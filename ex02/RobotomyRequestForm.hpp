#pragma once

#include <string>

#include <Form.hpp>

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm(const std::string& target);

protected:
    virtual void executeImpl() const;

private:
    const std::string target;
};
