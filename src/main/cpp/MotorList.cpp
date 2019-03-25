/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MotorList.h"

MotorList::MotorList() {}

void MotorList::addMotor(int motorType, int portNumber){
    int subListSize = 0;

    Motor<frc::Talon> test();

    switch(motorType){
        case 0:
            subListSize = this->TalonList.size();
            //this->TalonList.push_back(Motor<frc::Talon>(portNumber));
            break;
        case 1:
            subListSize = this->PWMTalonSRXList.size();
            //this->PWMTalonSRXList.push_back(Motor<frc::PWMTalonSRX>(portNumber));
            break;
        case 2:
            subListSize = this->JaguarList.size();
            //this->JaguarList.push_back(Motor<frc::Jaguar>(portNumber));
            break;
        case 3:
            subListSize = this->VictorList.size();
            //this->VictorList.push_back(Motor<frc::Victor>(portNumber));
            break;
        case 4:
            subListSize = this->VictorSPList.size();
            //this->VictorSPList.push_back(Motor<frc::VictorSP>(portNumber));
            break;
        case 5:
            subListSize = this->SparkList.size();
            //this->SparkList.push_back(Motor<frc::Spark>(portNumber));
            break;
        case 6:
            subListSize = this->TalonSRXList.size();
            //this->TalonSRXList.push_back(Motor<ctre::phoenix::motorcontrol::can::TalonSRX>(portNumber));
            break;
    }
    this->motorList.push_back({motorType, subListSize});
}
