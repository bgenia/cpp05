#include <ShrubberyCreationForm.hpp>

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form("ShrubberyCreationForm", 145, 137), target(target) { }

void ShrubberyCreationForm::executeImpl() const
{
    std::ofstream ofstream((target + "_shrubbery").c_str());

    if (!ofstream.is_open())
        return;

    ofstream <<
        "              &&& &&  & &\n"
        "      && &\\/&\\|& ()|/ @, &&\n"
        "      &\\/(/&/&||/& /_/)_&/_&\n"
        "   &() &\\/&|()|/&\\/ '%\" & ()\n"
        "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
        "&&   && & &| &| /& & % ()& /&&\n"
        " ()&_---()&\\&\\|&&-&&--%---()~\n"
        "     &&     \\|||\n"
        "             |||\n"
        "             |||\n"
        "             |||\n"
        "       , -=-~  .-^- _\\n"
        << std::endl;

    ofstream.close();
}
