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

private:
    enum FormType
    {
        FORM_SHRUBBERY_CREATION,
        FORM_ROBOTOMY_REQUEST,
        FORM_PRESIDENTIAL_PARDON,
        FORM_UNDEFINED
    };

    const static std::string FORM_TYPES[];
};
