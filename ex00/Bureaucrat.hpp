#pragma once

#include <string>
#include <stdexcept>

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& that);

    Bureaucrat(const std::string& name, unsigned int grade);

    virtual ~Bureaucrat();

    const std::string& getName() const;

    int getGrade() const;

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
