#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::string crypt(std::string message)
{
	char key[3] = { 'K', 'E', 'Y' };
	std::string output = message;
	for (int i = 0; i < message.size(); i++)
		output[i] = message[i] ^ key[i % (sizeof(key) / sizeof(char))];
	return output;
}

int main()
{
	system("chcp 1251");
	system("cls");

	int choose = 0;
	std::string message;

	do {
		system("cls");
		std::cout << "1. encrypt message\n"
			<< "2. decrypt message\n"
			<< "0. exit\n";
		std::cin >> choose;

		switch (choose)
		{
		case 1:
			std::cout << "1. enter keyboard\n"
				<< "2. read message.txt" << std::endl;
			std::cin >> choose;
			switch (choose)
			{
			case 1:
				std::cout << "enter message: " << std::endl;
				std::cin.ignore(1024, '\n');
				std::getline(std::cin, message);
				crypt(message);
				message = crypt(message);
				std::cout << "encrypt: " << message << std::endl;
				system("pause");
				break;
			case 2:
				std::ifstream in("d:\\message.txt");
				std::getline(in, message, '\0');
				in.close();
				crypt(message);
				message = crypt(message);
				std::cout << "1. output cmd\n"
					<< "2. write message.txt" << std::endl;
				std::cin >> choose;
				switch (choose)
				{
				case 1:
					std::cout << "encrypt: " << message << std::endl;
					system("pause");
					break;
				case 2:
					std::ofstream out("d:\\message.txt");
					out << message;
					out.close();
					break;
				}
				break;
			}
			break;
		case 2:
			std::cout << "1. enter keyboard\n"
				<< "2. read message.txt" << std::endl;
			std::cin >> choose;
			switch (choose)
			{
			case 1:
				std::cout << "enter message: " << std::endl;
				std::cin.ignore(1024, '\n');
				std::getline(std::cin, message);
				crypt(message);
				message = crypt(message);
				std::cout << "decrypt: " << message << std::endl;
				system("pause");
				break;
			case 2:
				std::ifstream in("d:\\message.txt");
				std::getline(in, message, '\0');
				in.close();
				crypt(message);
				message = crypt(message);
				std::cout << "1. output cmd\n"
					<< "2. write message.txt" << std::endl;
				std::cin >> choose;
				switch (choose)
				{
				case 1:
					std::cout << "decrypt: " << message << std::endl;
					system("pause");
					break;
				case 2:
					std::ofstream out("d:\\message.txt");
					out << message;
					out.close();
					break;
				}
				break;
			}
		}
	} while (choose != 0);
	return 0;
}
