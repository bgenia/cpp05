#include <Bureaucrat.hpp>

#include <iostream>

Bureaucrat::Bureaucrat()
    : name("Стас (клон)"), grade(150) { }

Bureaucrat::Bureaucrat(const Bureaucrat& that)
    : name(that.name), grade(that.grade) { }

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade)
    : name(name), grade(grade)
{
    validateGrade();
}

Bureaucrat::~Bureaucrat() { }

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    grade--;
    validateGrade();
}

void Bureaucrat::decrementGrade()
{
    grade++;
    validateGrade();
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::logic_error("Grade too high") { }

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::logic_error("Grade too low") { }

void Bureaucrat::validateGrade() const
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& value)
{
    ostream << value.getName() << ", bureaucrat grade " << value.getGrade();
    return ostream;
}
