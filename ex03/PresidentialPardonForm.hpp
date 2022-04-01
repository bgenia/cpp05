#pragma once

#include <string>

#include <Form.hpp>

class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm(const std::string& target);

protected:
    virtual void executeImpl() const;

private:
    const std::string target;
};
