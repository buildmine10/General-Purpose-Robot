/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Motor.h"

template <class T>
Motor<T>::Motor() {
    this->motorController = new T(id);
}


template <class T>
Motor<T>::Motor(int id) {
    this->motorController = new T(id);
}

template <class T>
void Motor<T>::set(float speed){
    try
    {
        this->motorController->Set(speed);
        if(abs(speed) > 1.f)
            throw "speed must be between -1 and 1";
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }
}

template <>
void Motor<TalonSRX>::set(float speed){
    try
    {
        this->motorController->Set(ControlMode::PercentOutput, speed);
        if(abs(speed) > 1.f)
            throw "speed must be between -1 and 1";
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }
}