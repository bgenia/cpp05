#include <iostream>

#include <Bureaucrat.hpp>

#include <termutils.hpp>

int main()
{
    {
        std::cout << TERM_F_CYAN << "[Стас]:" << TERM_RESET << std::endl;

        Bureaucrat stas = Bureaucrat("Стас", 120);

        std::cout << stas << std::endl;

        stas.incrementGrade();

        std::cout << stas << std::endl;
    }

    {
        std::cout << TERM_F_CYAN << "[Никита]:" << TERM_RESET << std::endl;

        try
        {
            Bureaucrat nikita = Bureaucrat("Никита", 1);

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
            Bureaucrat oleg = Bureaucrat("Олег", 150);

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
            Bureaucrat artyom = Bureaucrat("Артём", 157);
        }
        catch (std::exception& e)
        {
            std::cout << TERM_F_RED << e.what() << TERM_RESET << std::endl;
        }
    }

    {
        std::cout << TERM_F_CYAN << "[<Создать стаса (клона)>]:" << TERM_RESET << std::endl;

        Bureaucrat b;
        Form f;

        b.signForm(f);
    }

    {
        std::cout << TERM_F_CYAN << "[<Создать смысл жизни>]:" << TERM_RESET << std::endl;

        try
        {
            Form impossible = Form("Создать смысл жизни", 0, 0);
        }
        catch (std::exception& e)
        {
            std::cout << TERM_F_RED << e.what() << TERM_RESET << std::endl;
        }
    }

    {
        std::cout << TERM_F_CYAN << "[<Абоба>]:" << TERM_RESET << std::endl;

        Form aboba = Form("Абоба", 30, 30);

        Bureaucrat stas = Bureaucrat("Стас", 120);
        Bureaucrat nikita = Bureaucrat("Никита", 1);

        stas.signForm(aboba);
        nikita.signForm(aboba);
    }
}
