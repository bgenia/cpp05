#include <PresidentialPardonForm.hpp>

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Form("PresidentialPardonForm", 25, 5), target(target) { }

void PresidentialPardonForm::executeImpl() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
