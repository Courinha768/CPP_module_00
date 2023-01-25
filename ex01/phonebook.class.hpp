#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "contact.class.hpp"

class c_phonebook
{
	private	:
		contact	phonebook[8];
	public	:
		c_phonebook(void);
		~c_phonebook(void);
		void	add_contacts(void);
		void	search(void);
};

#endif