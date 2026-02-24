// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/Commands.h>
#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
RobotContainer::RobotContainer() {

  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {


// Run the intake when the right bumper is held
m_driverController.RightBumper().OnTrue(
  frc2::cmd::Run(
    [this] {
      m_intake.SetIntake(0.5);
    },
    {&m_intake}
  )
);
// Stop the intake when the right bumper is released
m_driverController.RightBumper().OnFalse(
  frc2::cmd::RunOnce(
    [this] { m_intake.Stop(); },
    {&m_intake}
  )
);


// Run the intake in reverse when the left bumper is held
m_driverController.LeftBumper().OnTrue(
  frc2::cmd::Run(
    [this] {  m_intake.SetIntake(-0.5); },
    {&m_intake}
  )
);
// Stop the intake when the left bumper is released
m_driverController.LeftBumper().OnFalse(
  frc2::cmd::RunOnce(
    [this] { m_intake.Stop();},
    {&m_intake}
  )
);


// Shoot the intake when the A button is held
m_driverController.A().OnTrue(
  frc2::cmd::Run(
    [this] { m_intake.Shooting(0.5); },
    {&m_intake}
  )
);
// Stop the intake when the A button is released
m_driverController.A().OnFalse(
  frc2::cmd::RunOnce(
    [this] { m_intake.Stop(); },
    {&m_intake}
  )
);


}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
