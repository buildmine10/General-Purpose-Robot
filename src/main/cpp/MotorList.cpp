/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MotorList.h"

MotorList::MotorList() {}

void MotorList::addMotor(int motorType, int portNumber){
    int subListSize = 0;//used to store information about where the new motor goes for the motor list vector

    //each motor type has its own case because of the use of multiple vectors
    switch(motorType){
        case 0:
            subListSize = this->TalonList.size();
            this->TalonList.push_back(Motor<frc::Talon>(portNumber));//makes a new motor controller object
            break;
        case 1:
            subListSize = this->PWMTalonSRXList.size();
            this->PWMTalonSRXList.push_back(Motor<frc::PWMTalonSRX>(portNumber));//makes a new motor controller object
            break;
        case 2:
            subListSize = this->JaguarList.size();
            this->JaguarList.push_back(Motor<frc::Jaguar>(portNumber));//makes a new motor controller object
            break;
        case 3:
            subListSize = this->VictorList.size();
            this->VictorList.push_back(Motor<frc::Victor>(portNumber));//makes a new motor controller object
            break;
        case 4:
            subListSize = this->VictorSPList.size();
            this->VictorSPList.push_back(Motor<frc::VictorSP>(portNumber));//makes a new motor controller object
            break;
        case 5:
            subListSize = this->SparkList.size();
            this->SparkList.push_back(Motor<frc::Spark>(portNumber));//makes a new motor controller object
            break;
        case 6:
            subListSize = this->TalonSRXList.size();
            this->TalonSRXList.push_back(Motor<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(portNumber));//makes a new motor controller object
            break;
    }
    this->motorList.push_back({motorType, subListSize});//adds the motors location data to the motor list vector
}

void MotorList::setSpeed(int motorId, float speed){
    //extracts motor location info
    int motorType = this->motorList.at(motorId)[0];
    int subListPosition = this->motorList.at(motorId)[1];

    //each motor type has its own case because of the use of multiple vectors
    switch(motorType){
        case 0:
            this->TalonList.at(subListPosition).set(speed);//sets the speed of the motor
            break;
        case 1:
            this->PWMTalonSRXList.at(subListPosition).set(speed);//sets the speed of the motor
            break;
        case 2:
            this->JaguarList.at(subListPosition).set(speed);//sets the speed of the motor
            break;
        case 3:
            this->VictorList.at(subListPosition).set(speed);//sets the speed of the motor
            break;
        case 4:
            this->VictorSPList.at(subListPosition).set(speed);//sets the speed of the motor
            break;
        case 5:
            this->SparkList.at(subListPosition).set(speed);//sets the speed of the motor
            break;
        case 6:
            this->TalonSRXList.at(subListPosition).set(speed);//sets the speed of the motor
            break;
    }
}

int MotorList::getSensorPosition(int motorId){
    //extracts motor location info
    int motorType = this->motorList.at(motorId)[0];
    int subListPosition = this->motorList.at(motorId)[1];

    try
    {
        if(motorType != 6)//only allows TalonSRXs to run the remainder of the function
            throw "Only TalonSRX motor controllers can have feedback sensors attached to them.";
        else
            return this->TalonSRXList.at(subListPosition).GetSensorPosition();
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }
}

void MotorList::configFeedbackSensor(int motorId, ctre::phoenix::motorcontrol::FeedbackDevice feedbackDevice, int pidIdx, int timeoutMs){
    //extracts motor location info
    int motorType = this->motorList.at(motorId)[0];
    int subListPosition = this->motorList.at(motorId)[1];

    try
    {
        if(motorType != 6)//only allows TalonSRXs to run the remainder of the function
            throw "Only TalonSRX motor controllers can have feedback sensors attached to them.";
        else
            this->TalonSRXList.at(subListPosition).configFeedbackSensor(feedbackDevice, pidIdx, timeoutMs);
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }
}

void MotorList::configFeedbackSensor(int motorId, ctre::phoenix::motorcontrol::RemoteFeedbackDevice feedbackDevice, int pidIdx, int timeoutMs){
    //extracts motor location info
    int motorType = this->motorList.at(motorId)[0];
    int subListPosition = this->motorList.at(motorId)[1];

    try
    {
        if(motorType != 6)//only allows TalonSRXs to run the remainder of the function
            throw "Only TalonSRX motor controllers can have feedback sensors attached to them.";
        else
            this->TalonSRXList.at(subListPosition).configFeedbackSensor(feedbackDevice, pidIdx, timeoutMs);
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }
}