#include <iostream>
#include <fstream>
#include <cmath>
#include <memory>

#include <ReflexxesAPI.h>
#include <RMLPositionFlags.h>
#include <RMLPositionInputParameters.h>
#include <RMLPositionOutputParameters.h>


constexpr double CYCLE_TIME_IN_SECONDS {0.001};
constexpr int NUMBER_OF_DOFS {1};


int main() {
  int ResultValue = 0;
  auto RML = std::make_shared<ReflexxesAPI>(NUMBER_OF_DOFS, CYCLE_TIME_IN_SECONDS);
  auto IP = std::make_shared<RMLPositionInputParameters>(NUMBER_OF_DOFS);
  auto OP = std::make_shared<RMLPositionOutputParameters>(NUMBER_OF_DOFS);
  RMLPositionFlags Flags;



  IP->CurrentPositionVector->VecData      [0] = 0.0;
  IP->CurrentVelocityVector->VecData      [0] = 0.0;
  IP->CurrentAccelerationVector->VecData  [0] = 0.0;

  IP->MaxVelocityVector->VecData          [0] = 100.0;
  IP->MaxAccelerationVector->VecData      [0] = 300.0;

  IP->TargetPositionVector->VecData       [0] = 49.0;
  IP->TargetVelocityVector->VecData       [0] =  0.0;

  IP->SelectionVector->VecData            [0] = true;



  std::ofstream outputFile("output.txt");

  while (ResultValue != ReflexxesAPI::RML_FINAL_STATE_REACHED) {
    ResultValue = RML->RMLPosition(*IP, OP.get(), Flags);

    outputFile << IP->CurrentPositionVector->VecData[0] << "," << IP->CurrentVelocityVector->VecData[0] << "," << IP->CurrentAccelerationVector->VecData[0] << std::endl;

    if (ResultValue < 0) {
      printf("An error occurred (%d).\n", ResultValue );
      break;
    }

    *IP->CurrentPositionVector = *OP->NewPositionVector;
    *IP->CurrentVelocityVector  = *OP->NewVelocityVector;
    *IP->CurrentAccelerationVector = *OP->NewAccelerationVector;
  }

  exit(EXIT_SUCCESS)  ;
}
