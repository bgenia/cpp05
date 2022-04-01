#pragma once

#include <string>
#include <stdexcept>
#include <iostream>

#include <Bureaucrat.hpp>

class Bureaucrat;

class Form
{
public:
    Form();
    Form(const Form& that);

    Form(const std::string& name, const unsigned int signingGrade, const unsigned int executionGrade);

    virtual ~Form();

    void beSigned(const Bureaucrat& bureaucrat);

    const std::string& getName() const;
    unsigned int getSigningGrade() const;
    unsigned int getExecutionGrade() const;
    bool isSigned() const;

    class GradeTooHighException : public std::logic_error
    {
    public:
        GradeTooHighException();
    };

    class GradeTooLowException : public std::logic_error
    {
    public:
        GradeTooLowException();
    };

private:
    const std::string name;
    const unsigned int signingGrade;
    const unsigned int executionGrade;

    bool _signed;

    void validateGrades() const;

    Form& operator=(Form that);
};

std::ostream& operator<<(std::ostream& ostream, const Form& value);
