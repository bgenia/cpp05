#include <iostream>
#include <ctime>
#include <cstdlib>

#include <Bureaucrat.hpp>

#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

#include <termutils.hpp>

int main()
{
    srand(time(NULL));


    {
        std::cout << TERM_F_CYAN << "[Стас]:" << TERM_RESET << std::endl;

        Bureaucrat stas("Стас", 120);

        std::cout << stas << std::endl;

        stas.incrementGrade();

        std::cout << stas << std::endl;
    }

    {
        std::cout << TERM_F_CYAN << "[Никита]:" << TERM_RESET << std::endl;

        try
        {
            Bureaucrat nikita("Никита", 1);

            std::cout << nikita << std::endl;

            nikita.incrementGrade();

            std::cout << nikita << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << TERM_F_RED << e.what() << TERM_RESET << std::endl;
        }
    }

    {
        std::cout << TERM_F_CYAN << "[Олег]:" << TERM_RESET << std::endl;

        try
        {
            Bureaucrat oleg("Олег", 150);

            std::cout << oleg << std::endl;

            oleg.decrementGrade();

            std::cout << oleg << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << TERM_F_RED << e.what() << TERM_RESET << std::endl;
        }
    }

    {
        std::cout << TERM_F_CYAN << "[Артём]:" << TERM_RESET << std::endl;

        try
        {
            Bureaucrat artyom("Артём", 157);
        }
        catch (std::exception& e)
        {
            std::cout << TERM_F_RED << e.what() << TERM_RESET << std::endl;
        }
    }

    {
        std::cout << TERM_F_CYAN << "[<ShrubberyCreationForm>]:" << TERM_RESET << std::endl;

        Bureaucrat b("Игорь", 70);

        ShrubberyCreationForm form("куст");

        b.signForm(form);
        form.execute(b);
    }

    {
        std::cout << TERM_F_CYAN << "[<RobotomyRequestForm>]:" << TERM_RESET << std::endl;

        Bureaucrat stas("Стас", 120);
        Bureaucrat nikita("Никита", 1);

        RobotomyRequestForm form("Стас (киборг)");

        try
        {
            stas.signForm(form);
            nikita.signForm(form);

            form.execute(nikita);
            form.execute(nikita);
            form.execute(nikita);
            form.execute(nikita);
            form.execute(stas);
        }
        catch (std::exception& e)
        {
            std::cout << TERM_F_RED << e.what() << TERM_RESET << std::endl;
        }
    }

    {
        std::cout << TERM_F_CYAN << "[<PresedentialPardonForm>]:" << TERM_RESET << std::endl;

        PresidentialPardonForm form("Абобус");

        Bureaucrat stas("Стас", 120);
        Bureaucrat nikita("Никита", 1);

        stas.signForm(form);
        nikita.signForm(form);

        try
        {
            form.execute(nikita);
            form.execute(stas);
        }
        catch (std::exception& e)
        {
            std::cout << TERM_F_RED << e.what() << TERM_RESET << std::endl;
        }
    }
}
