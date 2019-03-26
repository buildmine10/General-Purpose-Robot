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
#include <memory>

#include "ctre/Phoenix.h"

#include <frc/Talon.h>
#include <frc/Jaguar.h>
#include <frc/Victor.h>
#include <frc/PWMTalonSRX.h>
#include <frc/Spark.h>
#include <frc/VictorSP.h>

class Motor {
 public:
 //try and use SFINAE
  void* motorController;
  int type;

  Motor(int type);//the id is set to zero
  Motor(int id, int type);//the id is set manually

  void set(float speed);//sets the speed of the motor
  float get();

  //TalonSRX exclusive
  int GetSensorPosition();//gets the position reading of the sensor on a TalonSRX. (Will only run on a TalonSRX, because of a check in the MotorList class)
  void configFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice feedbackDevice, int pidIdx, int timeoutMs);//configures the feedback sensor on a TalonSRX. (Will only run on a TalonSRX, because of a check in the MotorList class)
  void configFeedbackSensor(ctre::phoenix::motorcontrol::RemoteFeedbackDevice feedbackDevice, int pidIdx, int timeoutMs);//configures the feedback sensor on a TalonSRX. (Will only run on a TalonSRX, because of a check in the MotorList class)
};