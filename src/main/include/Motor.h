/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>

#include "ctre/Phoenix.h"

#include <frc/Talon.h>
#include <frc/Jaguar.h>
#include <frc/Victor.h>
#include <frc/PWMTalonSRX.h>
#include <frc/Spark.h>
#include <frc/VictorSP.h>

template <class motorType>
class Motor {
 private:
  motorType* motorController;
 public:
  Motor();//the id is set to zero
  Motor(int id);//the id is set manually

  void set(float speed);//sets the speed of the motor
  int GetSensorPosition();//gets the position reading of the sensor on a TalonSRX. (Will only run on a TalonSRX, because of a check in the MotorList class)
  void configFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice feedbackDevice, int pidIdx, int timeoutMs);//configures the feedback sensor on a TalonSRX. (Will only run on a TalonSRX, because of a check in the MotorList class)
  void configFeedbackSensor(ctre::phoenix::motorcontrol::RemoteFeedbackDevice feedbackDevice, int pidIdx, int timeoutMs);//configures the feedback sensor on a TalonSRX. (Will only run on a TalonSRX, because of a check in the MotorList class)
};


//start of function definitions
//
//
template <class T>
Motor<T>::Motor() {
  this->motorController = new T(0);
}

template <class T>
Motor<T>::Motor(int id) {
  this->motorController = new T(id);
}


template <class T>
void Motor<T>::set(float speed){
  try
  {
    this->motorController->Set(speed);//the set function of the actual motor controller
    if(abs(speed) > 1.f)//checks to make sure a speed between -1 and 1 is being supplied
        throw "speed must be between -1 and 1";
  }
  catch(std::string e)
  {
    std::cout << e << std::endl;
  }
}

template <class T>
int Motor<T>::GetSensorPosition(){
  return this->motorController->GetSelectedSensorPosition();
}

template <class T>
void Motor<T>::configFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice feedbackDevice, int pidIdx, int timeoutMs){
  this->motorController->ConfigSelectedFeedbackSensor(feedbackDevice, pidIdx, timeoutMs);
}

template <class T>
void Motor<T>::configFeedbackSensor(ctre::phoenix::motorcontrol::RemoteFeedbackDevice feedbackDevice, int pidIdx, int timeoutMs){
  this->motorController->ConfigSelectedFeedbackSensor(feedbackDevice, pidIdx, timeoutMs);
}