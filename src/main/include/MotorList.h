/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <vector>

#include <frc/Talon.h>
#include <frc/PWMTalonSRX.h>
#include <frc/Jaguar.h>
#include <frc/Victor.h>
#include <frc/VictorSP.h>
#include <frc/Spark.h>

#include <ctre/Phoenix.h>

#include "Motor.h"

enum motorType{
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
  std::vector<Motor<frc::Talon>> TalonList;                                   // list number: 0
  std::vector<Motor<frc::PWMTalonSRX>> PWMTalonSRXList;                       // list number: 1
  std::vector<Motor<frc::Jaguar>> JaguarList;                                 // list number: 2
  std::vector<Motor<frc::Victor>> VictorList;                                 // list number: 3
  std::vector<Motor<frc::VictorSP>> VictorSPList;                             // list number: 4
  std::vector<Motor<frc::Spark>> SparkList;                                   // list number: 5
  std::vector<Motor<ctre::phoenix::motorcontrol::can::TalonSRX>> TalonSRXList;// list number: 6
  
  std::vector<std::array<int, 2>> motorList;//stores the paths to find motors
 public:
  MotorList();

  void addMotor(int motorType, int portNumber);
};
