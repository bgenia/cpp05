#pragma once

#include <string>
#include <stdexcept>

#include <Form.hpp>

class Form;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& that);

    Bureaucrat(const std::string& name, unsigned int grade);

    virtual ~Bureaucrat();

    void signForm(Form& form) const;

    const std::string& getName() const;

    unsigned int getGrade() const;

    void incrementGrade();
    void decrementGrade();

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

    static const int MAX_GRADE = 1;
    static const int MIN_GRADE = 150;

private:
    const std::string name;

    unsigned int grade;

    Bureaucrat& operator=(Bureaucrat that);

    void validateGrade() const;
};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& value);
