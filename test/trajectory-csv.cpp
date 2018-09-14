#include <iostream>
#include <fstream>
#include <cmath>
#include <memory>

#include <ReflexxesAPI.h>
#include <RMLPositionFlags.h>
#include <RMLPositionInputParameters.h>
#include <RMLPositionOutputParameters.h>


constexpr double CYCLE_TIME_IN_SECONDS {0.001};
constexpr int NUMBER_OF_DOFS {2};


int main() {
  int ResultValue = 0;
  auto RML = std::make_shared<ReflexxesAPI>(NUMBER_OF_DOFS, CYCLE_TIME_IN_SECONDS);
  auto IP = std::make_shared<RMLPositionInputParameters>(NUMBER_OF_DOFS);
  auto OP = std::make_shared<RMLPositionOutputParameters>(NUMBER_OF_DOFS);
  RMLPositionFlags Flags;



  IP->CurrentPositionVector->VecData      [0] = 0.0;
  IP->CurrentPositionVector->VecData      [1] = 0.0;
  IP->CurrentVelocityVector->VecData      [0] = 0.0;
  IP->CurrentVelocityVector->VecData      [1] = 0.0;

  IP->MaxVelocityVector->VecData          [0] = 100.0;
  IP->MaxVelocityVector->VecData          [1] = 100.0;
  IP->MaxAccelerationVector->VecData      [0] = 300.0;
  IP->MaxAccelerationVector->VecData      [1] = 300.0;

  IP->TargetPositionVector->VecData       [0] = 40.0;
  IP->TargetPositionVector->VecData       [1] = 20.0;
  IP->TargetVelocityVector->VecData       [0] = 0.0;
  IP->TargetVelocityVector->VecData       [1] = 0.0;

  IP->SelectionVector->VecData            [0] = true;
  IP->SelectionVector->VecData            [1] = true;

  Flags.SynchronizationBehavior   =   RMLPositionFlags::ONLY_PHASE_SYNCHRONIZATION;



  std::ofstream outputFile("output.csv");

  double time = 0.0;
  while (ResultValue != ReflexxesAPI::RML_FINAL_STATE_REACHED) {
    ResultValue = RML->RMLPosition(*IP, OP.get(), Flags);

    outputFile << IP->CurrentPositionVector->VecData[0] << "," << IP->CurrentPositionVector->VecData[1] << ",";
    outputFile << IP->CurrentVelocityVector->VecData[0] << "," << IP->CurrentVelocityVector->VecData[1] << ",";
    outputFile << time << std::endl;

    if (ResultValue < 0) {
      printf("An error occurred (%d).\n", ResultValue );
      break;
    }

    *IP->CurrentPositionVector = *OP->NewPositionVector;
    *IP->CurrentVelocityVector  = *OP->NewVelocityVector;
    *IP->CurrentAccelerationVector = *OP->NewAccelerationVector;
    time += CYCLE_TIME_IN_SECONDS;
  }

  exit(EXIT_SUCCESS)  ;
}
