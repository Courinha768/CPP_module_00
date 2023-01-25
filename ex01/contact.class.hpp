#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <string>
# include <locale>
# include <iomanip>	
# include <sstream> 

# define TRUE 1
# define FALSE 0

# define NULL_STR ""

enum	INFO {INDEX, NAME, NICKNAME, LAST_NAME};

void	print_str_s10(std::string str);

class contact
{
	private	:
		std::string	index;
		std::string	phone;
		std::string	name;
		std::string	nickname;
		std::string last_name;

	public	:
		contact(void);
		~contact(void);
		void	add_contact(void);
		void	show_contact(void);
		bool	has_value(void);
		void	print_value(int msg);
};

#endif