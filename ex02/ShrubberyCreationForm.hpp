#pragma once

#include <string>

#include <Form.hpp>

class ShrubberyCreationForm : public Form
{
public:
    ShrubberyCreationForm(const std::string& target);

protected:
    virtual void executeImpl() const;

private:
    const std::string target;
};
