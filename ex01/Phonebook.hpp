#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.hpp"

class Phonebook
{
	private	:
		Contact	phonebook[8];
	public	:
		Phonebook(void);
		~Phonebook(void);
		void	add_contacts(void);
		void	search(void);
};

#endif