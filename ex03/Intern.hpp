#pragma once

#include <string>

#include <Form.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

class Intern
{
public:
    Form* makeForm(const std::string& name, const std::string& target) const;
};
