#include <Intern.hpp>

#include <stdexcept>

Form* Intern::makeForm(const std::string& name, const std::string& target) const
{
    if (name == "ShrubberyCreationForm")
        return new ShrubberyCreationForm(target);
    if (name == "RobotomyRequestForm")
        return new RobotomyRequestForm(target);
    if (name == "PresidentialPardonForm")
        return new PresidentialPardonForm(target);
    throw std::invalid_argument("Invalid form name");
}
