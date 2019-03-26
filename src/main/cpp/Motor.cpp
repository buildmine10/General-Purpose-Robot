/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Motor.h"

Motor::Motor(int type) {
    this->type = type;
    switch(type){
        case 0:
            this->motorController = new frc::Talon(0);
            break;
        case 1:
            this->motorController = new frc::PWMTalonSRX(0);
            break;
        case 2:
            this->motorController = new frc::Jaguar(0);
            break;
        case 3:
            this->motorController = new frc::Victor(0);
            break;
        case 4:
            this->motorController = new frc::VictorSP(0);
            break;
        case 5:
            this->motorController = new frc::Spark(0);
            break;
        case 6:
            this->motorController = new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(0);
            break;
    } 
}

Motor::Motor(int id, int type) {
    this->type = type;
    switch(type){
        case 0:
            this->motorController = new frc::Talon(id);
            break;
        case 1:
            this->motorController = new frc::PWMTalonSRX(id);
            break;
        case 2:
            this->motorController = new frc::Jaguar(id);
            break;
        case 3:
            this->motorController = new frc::Victor(id);
            break;
        case 4:
            this->motorController = new frc::VictorSP(id);
            break;
        case 5:
            this->motorController = new frc::Spark(id);
            break;
        case 6:
            this->motorController = new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(id);
            break;
    } 
}


void Motor::set(float speed){
    try
    {
        switch(this->type){
            case 0:
                reinterpret_cast<frc::Talon*>(this->motorController)->Set(speed);//the set function of the actual motor controller
                break;
            case 1:
                reinterpret_cast<frc::PWMTalonSRX*>(this->motorController)->Set(speed);//the set function of the actual motor controller
                break;
            case 2:
                reinterpret_cast<frc::Jaguar*>(this->motorController)->Set(speed);//the set function of the actual motor controller
                break;
            case 3:
                reinterpret_cast<frc::Victor*>(this->motorController)->Set(speed);//the set function of the actual motor controller
                break;
            case 4:
                reinterpret_cast<frc::VictorSP*>(this->motorController)->Set(speed);//the set function of the actual motor controller
                break;
            case 5:
                reinterpret_cast<frc::Spark*>(this->motorController)->Set(speed);//the set function of the actual motor controller
                break;
            case 6:
                reinterpret_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX*>(this->motorController)->Set(speed);//the set function of the actual motor controller
                break;
        } 
        
        if(abs(speed) > 1.f)//checks to make sure a speed between -1 and 1 is being supplied
            throw "speed must be between -1 and 1";
    }
    catch(std::string e)
    {
      std::cout << e << std::endl;
    }
}

float Motor::get(){
    switch(this->type){
        case 0:
            return (float)reinterpret_cast<frc::Talon*>(this->motorController)->Get();
            break;
        case 1:
            return (float)reinterpret_cast<frc::PWMTalonSRX*>(this->motorController)->Get();
            break;
        case 2:
            return (float)reinterpret_cast<frc::Jaguar*>(this->motorController)->Get();
            break;
        case 3:
            return (float)reinterpret_cast<frc::Victor*>(this->motorController)->Get();
            break;
        case 4:
            return (float)reinterpret_cast<frc::VictorSP*>(this->motorController)->Get();
            break;
        case 5:
            return (float)reinterpret_cast<frc::Spark*>(this->motorController)->Get();
            break;
        case 6:
            return (float)reinterpret_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX*>(this->motorController)->Get();
            break;
    } 
  return 2;
}


//TalonSRX exclusive
int Motor::GetSensorPosition(){
  return reinterpret_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX*>(this->motorController)->GetSelectedSensorPosition();
}

void Motor::configFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice feedbackDevice, int pidIdx, int timeoutMs){
  reinterpret_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX*>(this->motorController)->ConfigSelectedFeedbackSensor(feedbackDevice, pidIdx, timeoutMs);
}

void Motor::configFeedbackSensor(ctre::phoenix::motorcontrol::RemoteFeedbackDevice feedbackDevice, int pidIdx, int timeoutMs){
  reinterpret_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX*>(this->motorController)->ConfigSelectedFeedbackSensor(feedbackDevice, pidIdx, timeoutMs);
}
