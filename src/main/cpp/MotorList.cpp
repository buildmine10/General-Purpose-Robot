/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MotorList.h"

MotorList::MotorList() {}

void MotorList::addMotor(int motorType, int portNumber){
    this->motorList.push_back(Motor(portNumber, motorType));
}

void MotorList::setSpeed(int motorId, float speed){
    this->motorList.at(motorId).set(speed);
}

void* MotorList::getMotorController(int motorId){
    this->motorList.at(motorId).motorController;
}

int MotorList::getControllerType(int motorId){
    return this->motorList.at(motorId).type;
}

//TalonSRX exclusive
int MotorList::getSensorPosition(int motorId){
    try
    {
        if(this->motorList.at(motorId).type != 6)//only allows TalonSRXs to run the remainder of the function
            throw "Only TalonSRX motor controllers can have feedback sensors attached to them.";
        else
            return  this->motorList.at(motorId).GetSensorPosition();
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }
}

void MotorList::configFeedbackSensor(int motorId, ctre::phoenix::motorcontrol::FeedbackDevice feedbackDevice, int pidIdx, int timeoutMs){
    try
    {
        if(this->motorList.at(motorId).type != 6)//only allows TalonSRXs to run the remainder of the function
            throw "Only TalonSRX motor controllers can have feedback sensors attached to them.";
        else
            this->motorList.at(motorId).configFeedbackSensor(feedbackDevice, pidIdx, timeoutMs);
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }
}

void MotorList::configFeedbackSensor(int motorId, ctre::phoenix::motorcontrol::RemoteFeedbackDevice feedbackDevice, int pidIdx, int timeoutMs){
    try
    {
        if(this->motorList.at(motorId).type != 6)//only allows TalonSRXs to run the remainder of the function
            throw "Only TalonSRX motor controllers can have feedback sensors attached to them.";
        else
            this->motorList.at(motorId).configFeedbackSensor(feedbackDevice, pidIdx, timeoutMs);
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }
}