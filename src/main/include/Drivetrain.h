/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <vector>

#include "frc/drive/DifferentialDrive.h"
#include "frc/drive/MecanumDrive.h"
#include "frc/drive/KilloughDrive.h"

class Drivetrain {
 private:
  bool isUsingCanBus = false;
  frc::DifferentialDrive* difDrive;
  frc::MecanumDrive* mecDrive;
  frc::KilloughDrive* kilDrive;
  short int mode;//0: differential, 1: mecanum, 2: killough
 public:

  Drivetrain(int leftId, int rightId);
  Drivetrain(int frontId, int backLeftId, int backRightId);
  Drivetrain(int frontLeftId, int frontRightId, int backLeftId, int backRightId, bool isMecanum);
};
