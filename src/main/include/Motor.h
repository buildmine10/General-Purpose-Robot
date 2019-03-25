/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <iostream>
#include <cstring>

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
  Motor();//works
  Motor(int id);//doesn't work

  void set(float speed);
};
