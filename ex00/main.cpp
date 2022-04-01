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
}
