#include <Intern.hpp>

#include <stdexcept>

const std::string Intern::FORM_TYPES[] = {
    [FORM_SHRUBBERY_CREATION] = "ShrubberyCreationForm",
    [FORM_ROBOTOMY_REQUEST] = "RobotomyRequestForm",
    [FORM_PRESIDENTIAL_PARDON] = "PresidentialPardonForm"
};

Form* Intern::makeForm(const std::string& name, const std::string& target) const
{
    int formType = 0;

    for (; formType < FORM_UNDEFINED; formType++)
        if (name == FORM_TYPES[formType])
            break;

    switch (formType)
    {
    case FORM_SHRUBBERY_CREATION:
        return new ShrubberyCreationForm(target);
    case FORM_ROBOTOMY_REQUEST:
        return new RobotomyRequestForm(target);
    case FORM_PRESIDENTIAL_PARDON:
        return new PresidentialPardonForm(target);
    default:
        throw std::invalid_argument("invalid form name");
    }
}
