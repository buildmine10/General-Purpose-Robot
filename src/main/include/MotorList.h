/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>
#include <iostream>
#include <vector>

#include <frc/Talon.h>
#include <frc/PWMTalonSRX.h>
#include <frc/Jaguar.h>
#include <frc/Victor.h>
#include <frc/VictorSP.h>
#include <frc/Spark.h>

#include <ctre/Phoenix.h>

#include "Motor.h"

enum MotorType{
  Talon,
  PWMTalonSRX,
  Jaguar,
  Victor,
  VictorSP,
  Spark,
  TalonSRX
};

class MotorList {
 private:
  std::vector<Motor> motorList;
 public:
  MotorList();

  void addMotor(int motorType, int portNumber);
  void setSpeed(int motorId, float speed);
  void* getMotorController(int motorId);
  int getControllerType(int motorId);

  //TalonSRX exclusive functions
  int getSensorPosition(int motorId);//gets the position reading of the sensor on a TalonSRX.
  void configFeedbackSensor(int motorId, ctre::phoenix::motorcontrol::FeedbackDevice feedbackDevice, int pidIdx, int timeoutMs);//configures the feedback sensor on a TalonSRX.
  void configFeedbackSensor(int motorId, ctre::phoenix::motorcontrol::RemoteFeedbackDevice feedbackDevice, int pidIdx, int timeoutMs);//configures the remote feedback sensor on a TalonSRX.
};
