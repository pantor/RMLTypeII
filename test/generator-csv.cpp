#include <iostream>
#include <fstream>
#include <cmath>
#include <memory>
#include <random>
#include <vector>

#include <ReflexxesAPI.h>
#include <RMLPositionFlags.h>
#include <RMLPositionInputParameters.h>
#include <RMLPositionOutputParameters.h>


constexpr double CYCLE_TIME_IN_SECONDS {0.001};
constexpr int NUMBER_OF_DOFS {1};


struct MotionData {
  double x;
  double v;
  double a;
  double a_max;
  double x_target;
  double v_target;

  double x_new;
  double v_new;
  double a_new;
};



std::vector<MotionData> generateMotion(double x_0, double v_0, double a_max, double x_target, double v_target) {
  std::vector<MotionData> result {};

  int ResultValue = 0;
  auto RML = std::make_shared<ReflexxesAPI>(NUMBER_OF_DOFS, CYCLE_TIME_IN_SECONDS);
  auto IP = std::make_shared<RMLPositionInputParameters>(NUMBER_OF_DOFS);
  auto OP = std::make_shared<RMLPositionOutputParameters>(NUMBER_OF_DOFS);
  RMLPositionFlags Flags;

  IP->CurrentPositionVector->VecData [0] = x_0;
  IP->CurrentVelocityVector->VecData [0] = v_0;
  IP->MaxVelocityVector->VecData     [0] = 100000.0;
  IP->MaxAccelerationVector->VecData [0] = a_max;
  IP->TargetPositionVector->VecData  [0] = x_target;
  IP->TargetVelocityVector->VecData  [0] = v_target;
  IP->SelectionVector->VecData       [0] = true;

  while (ResultValue != ReflexxesAPI::RML_FINAL_STATE_REACHED) {
    ResultValue = RML->RMLPosition(*IP, OP.get(), Flags);

    if (ResultValue < 0) {
      printf("An error occurred (%d).\n", ResultValue );
      break;
    }

    MotionData motion_data;
    motion_data.x = IP->CurrentPositionVector->VecData[0];
    motion_data.v = IP->CurrentVelocityVector->VecData[0];
    motion_data.a = IP->CurrentAccelerationVector->VecData[0];
    motion_data.a_max = a_max;
    motion_data.x_target = x_target;
    motion_data.v_target = v_target;
    motion_data.x_new = OP->NewPositionVector->VecData[0];
    motion_data.v_new = OP->NewVelocityVector->VecData[0];
    motion_data.a_new = OP->NewAccelerationVector->VecData[0];
    result.push_back(motion_data);

    *IP->CurrentPositionVector = *OP->NewPositionVector;
    *IP->CurrentVelocityVector  = *OP->NewVelocityVector;
    *IP->CurrentAccelerationVector = *OP->NewAccelerationVector;
  }

  return result;
}

void printMotionData(const std::string& filename, const std::vector<MotionData>& motion_data) {
  std::ofstream outputFile(filename);

  // outputFile << "x,v,a,a_max,x_target,v_target,x_new,v_new" << std::endl;
  for (auto d: motion_data) {
    outputFile
      << d.x << ","
      << d.v << ","
      << d.a << ","
      << d.a_max << ","
      << d.x_target << ","
      << d.v_target << ","
      << d.x_new << ","
      << d.v_new << ","
      << d.a_new << std::endl;
  }
}

int main() {
  const int train_count = 300;
  const int test_count = 60;
  const std::string file_id = "x1-v1-xt1-vt1-2";

  std::random_device rd;
  std::mt19937 gen(rd());

  std::normal_distribution<double> x_0_dist(0.0, 1.0);
  std::normal_distribution<double> v_0_dist(0.0, 1.0);
  std::gamma_distribution<double> a_max_dist(1.0, 1.0);
  std::normal_distribution<double> x_target_dist(0.0, 1.0);
  std::normal_distribution<double> v_target_dist(0.0, 1.0);

  std::vector<MotionData> train_result {};
  std::vector<MotionData> test_result {};

  // Train data
  for (int i = 0; i < train_count; i++) {
    auto motion_data = generateMotion(x_0_dist(gen), v_0_dist(gen), a_max_dist(gen), x_target_dist(gen), v_target_dist(gen));
    train_result.insert(train_result.end(), motion_data.begin(), motion_data.end());
  }
  printMotionData("train-" + file_id + ".csv", train_result);

  // Test data
  for (int i = 0; i < test_count; i++) {
    auto motion_data = generateMotion(x_0_dist(gen), v_0_dist(gen), a_max_dist(gen), x_target_dist(gen), v_target_dist(gen));
    test_result.insert(test_result.end(), motion_data.begin(), motion_data.end());
  }
  printMotionData("test-" + file_id + ".csv", test_result);
}
