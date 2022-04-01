#include <RobotomyRequestForm.hpp>

#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("RobotomyRequestForm", 72, 45), target(target) { }

void RobotomyRequestForm::executeImpl() const
{
    std::cout << "* Drilling noises *" << std::endl;

    if (rand() % 2 == 0)
    {
        std::cout << "Robotomy failed :(" << std::endl;

        return;
    }

    std::cout << target << " has beed robotomized" << std::endl;
}
