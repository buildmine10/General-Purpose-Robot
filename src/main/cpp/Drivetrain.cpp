/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Drivetrain.h"
#include "GlobalVariables.h"


Drivetrain::Drivetrain(int leftId, int rightId){
    int controllerType = motors->getControllerType(leftId);
    if(controllerType == 6){
        this->isUsingCanBus = true;
        this->mode = 0;
    }else{
        this->mode = 0;
        extern auto left;
        extern auto right;
        switch(this->type){
            case 0:
                auto left = reinterpret_cast<frc::Talon*>(motors->getMotorController(leftId));
                auto right = reinterpret_cast<frc::Talon*>(motors->getMotorController(rightId));
                break;
            case 1:
                auto left = reinterpret_cast<frc::PWMTalonSRX*>(motors->getMotorController(leftId));
                auto right = reinterpret_cast<frc::PWMTalonSRX*>(motors->getMotorController(rightId));
                break;
            case 2:
                auto left = reinterpret_cast<frc::Jaguar*>(motors->getMotorController(leftId));
                auto right = reinterpret_cast<frc::Jaguar*>(motors->getMotorController(rightId));
                break;
            case 3:
                auto left = reinterpret_cast<frc::Victor*>(motors->getMotorController(leftId));
                auto right = reinterpret_cast<frc::Victor*>(motors->getMotorController(rightId));
                break;
            case 4:
                auto left = reinterpret_cast<frc::VictorSP*>(motors->getMotorController(leftId));
                auto right = reinterpret_cast<frc::VictorSP*>(motors->getMotorController(rightId));
                break;
            case 5:
                auto left = reinterpret_cast<frc::Spark*>(motors->getMotorController(leftId));
                auto right = reinterpret_cast<frc::Spark*>(motors->getMotorController(rightId));
                break;
        } 

        this->driveController = new frc::DifferentialDrive(left, right);
    }
}

Drivetrain::Drivetrain(int frontId, int backLeftId, int backRightId){

}

Drivetrain::Drivetrain(int frontLeftId, int frontRightId, int backLeftId, int backRightId, bool isMecanum){

}
