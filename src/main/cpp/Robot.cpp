// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
using namespace ctre::phoenix6;
#include <frc2/command/CommandScheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <wpi/print.h>

Robot::Robot() {

     // start with factory-default configs
   configs::MotorOutputConfigs currentConfigs{};

   // The left motor is CCW+
   currentConfigs.Inverted = signals::InvertedValue::CounterClockwise_Positive;
   m_leftLeader.GetConfigurator().Apply(currentConfigs);

   // The right motor is CW+
   currentConfigs.Inverted = signals::InvertedValue::Clockwise_Positive;
   m_rightLeader.GetConfigurator().Apply(currentConfigs);

   // Ensure the followers are following their respective leader
   m_leftFollower.SetControl(controls::Follower{m_leftLeader.GetDeviceID(), false});
   m_rightFollower.SetControl(controls::Follower{m_rightLeader.GetDeviceID(), false});
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand) {
    frc2::CommandScheduler::GetInstance().Schedule(m_autonomousCommand.value());
  }
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand) {
    m_autonomousCommand->Cancel();
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
       // retrieve joystick inputs
   auto fwd = -m_driverController.GetLeftY();
   auto rot = m_driverController.GetRightX();

   // modify control requests
   m_leftOut.Output = fwd + rot;
   m_rightOut.Output = fwd - rot;

   // send control requests
   m_leftLeader.SetControl(m_leftOut);
   m_rightLeader.SetControl(m_rightOut);
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

/**
 * This function is called once when the robot is first started up.
 */
void Robot::SimulationInit() {}

/**
 * This function is called periodically whilst in simulation.
 */
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
/*

                      _.._                       
                   .-'\  /'-.                    
                  / : :  : : \                   
                 :'. :'  ': .':                  
                 :/ (o)..(o) \:                  
                  \ .\\''//. /                   
                   :/ \\// \:                    
                    .-'  '-.                     
                   :        :                    
                   i        i                    
                  :.________.:                   
                    "'"'"'"'   
*/