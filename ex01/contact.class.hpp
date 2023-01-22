#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <string>
# include <locale>
# include <iomanip>	
# include <sstream> 


class contact
{
	private	:
		std::string	index;
		std::string	phone;
		std::string	name;
		std::string	nickname;
		std::string	favorite_colour;

	public	:
		void	add_contact(void);
		void	show_contact(void);

};

#endif