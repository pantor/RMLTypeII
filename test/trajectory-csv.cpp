#include <iostream>
#include <fstream>
#include <cmath>

#include <ReflexxesAPI.h>
#include <RMLPositionFlags.h>
#include <RMLPositionInputParameters.h>
#include <RMLPositionOutputParameters.h>


#define CYCLE_TIME_IN_SECONDS                   0.001
#define NUMBER_OF_DOFS                          1


int main() {
  int                         ResultValue                 =   0       ;
  ReflexxesAPI                *RML                        =   NULL    ;
  RMLPositionInputParameters  *IP                         =   NULL    ;
  RMLPositionOutputParameters *OP                         =   NULL    ;
  RMLPositionFlags            Flags                                   ;

  // ********************************************************************
  // Creating all relevant objects of the Type II Reflexxes Motion Library

  RML =   new ReflexxesAPI(NUMBER_OF_DOFS,   CYCLE_TIME_IN_SECONDS   );
  IP  =   new RMLPositionInputParameters(     NUMBER_OF_DOFS          );
  OP  =   new RMLPositionOutputParameters(    NUMBER_OF_DOFS          );


  IP->CurrentPositionVector->VecData      [0] =    0.0      ;
//  IP->CurrentPositionVector->VecData      [1] =      0.0      ;
//  IP->CurrentPositionVector->VecData      [2] =     50.0      ;

  IP->CurrentVelocityVector->VecData      [0] =    100.0      ;
//  IP->CurrentVelocityVector->VecData      [1] =   -220.0      ;
//  IP->CurrentVelocityVector->VecData      [2] =    -50.0      ;

  IP->CurrentAccelerationVector->VecData  [0] =   0.0      ;
//  IP->CurrentAccelerationVector->VecData  [1] =    250.0      ;
//  IP->CurrentAccelerationVector->VecData  [2] =    -50.0      ;

  IP->MaxVelocityVector->VecData          [0] =    100.0      ;
//  IP->MaxVelocityVector->VecData          [1] =    100.0      ;
//  IP->MaxVelocityVector->VecData          [2] =    300.0      ;

  IP->MaxAccelerationVector->VecData      [0] =    300.0      ;
//  IP->MaxAccelerationVector->VecData      [1] =    200.0      ;
//  IP->MaxAccelerationVector->VecData      [2] =    100.0      ;

//  IP->MaxJerkVector->VecData              [0] =    400.0      ;
//  IP->MaxJerkVector->VecData              [1] =    300.0      ;
//  IP->MaxJerkVector->VecData              [2] =    200.0      ;

  IP->TargetPositionVector->VecData       [0] =   30.0      ;
//  IP->TargetPositionVector->VecData       [1] =   -200.0      ;
//  IP->TargetPositionVector->VecData       [2] =   -350.0      ;

  IP->TargetVelocityVector->VecData       [0] =    0.0       ;
//  IP->TargetVelocityVector->VecData       [1] =   -50.0       ;
//  IP->TargetVelocityVector->VecData       [2] =  -200.0       ;

  IP->SelectionVector->VecData            [0] =   true        ;
//  IP->SelectionVector->VecData            [1] =   true        ;
//  IP->SelectionVector->VecData            [2] =   true        ;

  // ********************************************************************
  // Starting the control loop

  std::ofstream outputFile("output.txt");

  while (ResultValue != ReflexxesAPI::RML_FINAL_STATE_REACHED) {
    ResultValue =   RML->RMLPosition(*IP,   OP,   Flags       );

    if (ResultValue < 0) {
      printf("An error occurred (%d).\n", ResultValue );
      break;
    }

    *IP->CurrentPositionVector      =   *OP->NewPositionVector      ;
    *IP->CurrentVelocityVector      =   *OP->NewVelocityVector      ;
    *IP->CurrentAccelerationVector  =   *OP->NewAccelerationVector  ;

    outputFile << IP->CurrentPositionVector->VecData[0] << "," << IP->CurrentVelocityVector->VecData[0] << "," << IP->CurrentAccelerationVector->VecData[0] << std::endl;
  }


  delete  RML         ;
  delete  IP          ;
  delete  OP          ;

  exit(EXIT_SUCCESS)  ;
}
