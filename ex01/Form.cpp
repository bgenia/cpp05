#include <Form.hpp>

Form::Form()
    : name("Создать Стаса (клона)"),
      signingGrade(150),
      executionGrade(150),
      _signed(false) { }

Form::Form(const Form& that)
    : name(that.name),
      signingGrade(that.signingGrade),
      executionGrade(that.executionGrade),
      _signed(that._signed) { }

Form::Form(const std::string& name, const unsigned int signingGrade, const unsigned int executionGrade)
    : name(name),
      signingGrade(signingGrade),
      executionGrade(executionGrade),
      _signed(false)
{
    validateGrades();
}

Form::~Form() { }

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= executionGrade)
        _signed = true;
    else
        throw GradeTooLowException();
}

const std::string& Form::getName() const
{
    return name;
}

unsigned int Form::getSigningGrade() const
{
    return signingGrade;
}

unsigned int Form::getExecutionGrade() const
{
    return executionGrade;
}

bool Form::isSigned() const
{
    return _signed;
}

Form::GradeTooHighException::GradeTooHighException()
    : std::logic_error("Grade too high") {}

Form::GradeTooLowException::GradeTooLowException()
    : std::logic_error("Grade too low") {}

void Form::validateGrades() const
{
    if (signingGrade < 1 || executionGrade < 1)
        throw GradeTooHighException();
    if (signingGrade > 150 || executionGrade > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& ostream, const Form& value)
{
    ostream
        << value.getName() << ": "
        << value.getSigningGrade() << "/" << value.getExecutionGrade()
        << " (" << (value.isSigned() ? "signed" : "unsigned") << ") ";
    return ostream;
}
