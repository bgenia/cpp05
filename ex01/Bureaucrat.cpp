#include <Bureaucrat.hpp>

#include <iostream>

Bureaucrat::Bureaucrat()
    : name("Стас (клон)"), grade(MIN_GRADE) { }

Bureaucrat::Bureaucrat(const Bureaucrat& that)
    : name(that.name), grade(that.grade) { }

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade)
    : name(name), grade(grade)
{
    validateGrade();
}

Bureaucrat::~Bureaucrat() { }

void Bureaucrat::signForm(Form& form) const
{
    try
    {
        form.beSigned(*this);

        std::cout << name << " signed <" << form.getName() << ">" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << name << " couldn't sign <" << form.getName() << "> because <" << e.what() << ">" << std::endl;
    }
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

unsigned int Bureaucrat::getGrade() const
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
    : std::logic_error("grade too high") { }

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::logic_error("grade too low") { }

void Bureaucrat::validateGrade() const
{
    if (grade < MAX_GRADE)
        throw GradeTooHighException();
    if (grade > MIN_GRADE)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& value)
{
    ostream << value.getName() << ", bureaucrat grade " << value.getGrade();
    return ostream;
}
