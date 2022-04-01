#include <Form.hpp>

Form::Form()
    : name("Создать Стаса (клона)"),
      signingGrade(Bureaucrat::MIN_GRADE),
      executionGrade(Bureaucrat::MIN_GRADE),
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
    if (bureaucrat.getGrade() > signingGrade)
        throw GradeTooLowException();
    _signed = true;
}

void Form::execute(const Bureaucrat& bureaucrat) const
{
    if (bureaucrat.getGrade() > executionGrade)
        throw GradeTooLowException();
    executeImpl();
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
    if (signingGrade < Bureaucrat::MAX_GRADE || executionGrade < Bureaucrat::MAX_GRADE)
        throw GradeTooHighException();
    if (signingGrade > Bureaucrat::MIN_GRADE || executionGrade > Bureaucrat::MIN_GRADE)
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
