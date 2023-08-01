//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//class MyException :public exception
//{
//	string _message;
//	string _file;
//	string _date;
//	string _time;
//	int _line;
//public:
//
//	MyException(string message, string file, string date, string time, int line)
//		:exception(message.c_str())
//	{
//		_file = file;
//		_date = date;
//		_time = time;
//		_line = line;
//
//
//		_message = "Message: " + string(exception::what())
//			+ "\nFile: " + _file
//			+ "\nDate: " + _date
//			+ "\nTime: " + _time
//			+ "\nLine: " + to_string(_line);
//	}
//
//	char const* what() const override
//	{
//		return _message.c_str();
//	}
//
//
//};
//
//
//class User
//{
//
//	int _id;
//	static int static_id;
//	string _username;
//	string _password;
//	string _name;
//	string _surname;
//
//public:
//
//	User() : _id(++static_id), _username(), _password(), _name(), _surname() {}
//
//	User(string username, string password, string name, string surname)
//	{
//		try
//		{
//			setUsername(username);
//			setPassword(password);
//			setName(name);
//			setSurname(surname);
//		}
//
//		catch (const MyException& ex) { cout << ex.what() << endl; }
//	}
//
//	int getId() { return _id; }
//	string getUsername() { return _username; }
//	string getPassword() { return _password; }
//	string getName() { return _name; }
//	string getSurname() { return _surname; }
//
//	void setUsername(string username)
//	{
//		try
//		{
//			if (username.size() < 6)
//				throw MyException("Username minimum 6 simvol olmalidir !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//			if (username[0] >= 97 && username[0] <= 122)
//				throw MyException("Istifadeci adinin ilk herfi boyuk olmalidir !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//			else
//				_username = username;
//		}
//		catch (MyException& ex) { cout << ex.what() << endl; }
//	}
//
//	void setPassword(string password)
//	{
//		try
//		{
//			if (password.size() < 6)
//				throw MyException("Password minimum 6 simvol olmalidir !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//			else
//				_password = password;
//		}
//		catch (MyException& ex) { cout << ex.what() << endl; }
//	}
//
//	void setName(string name)
//	{
//		try
//		{
//			if (name.size() < 3) throw MyException("Name minimum 3 simvol olmalidir !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//			else _name = name;
//		}
//		catch (MyException& ex) { cout << ex.what() << endl; }
//	}
//
//	void setSurname(string surname)
//	{
//		try
//		{
//			if (surname.size() < 4)
//				throw MyException("Surname minimum 4 simvol olmalidir !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//			else
//				_surname = surname;
//		}
//		catch (MyException& ex) { cout << ex.what() << endl; }
//	}
//
//	void Show() const
//	{
//		cout << "ID: " << _id << endl;
//		cout << "Username: " << _username << endl;
//		cout << "Password: " << _password << endl;
//		cout << "Name: " << _name << endl;
//		cout << "Surname: " << _surname << endl << endl;
//	}
//	friend class Database;
//};
//int User::static_id = 0;
//
//class Database
//{
//	vector<User*> _users;
//
//public:
//	void addUser(User& user)
//	{
//		_users.push_back(&user);
//
//	}
//
//	User* getUserByUsername(string username)
//	{
//		try
//		{
//			for (int i = 0; i < _users.size(); i++)
//			{
//				if (_users[i]->_username == username) return _users[i];
//			}
//			throw MyException("Bu Username yoxdur !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//		}
//		catch (MyException& ex) { cout << ex.what() << endl; }
//		return nullptr;
//	}
//
//	void updateUser(User& olduser, User& newuser)
//	{
//		olduser._name = newuser._name;
//		olduser._surname = newuser._surname;
//		olduser._password = newuser._password;
//		olduser._username = newuser._surname;
//	}
//
//};
//
//class Registration
//{
//	Database _database;
//public:
//	Registration(Database& database)
//	{
//		_database = database;
//	}
//
//	void sign_in(string username, string password)
//	{
//
//		try
//		{
//			User* user = _database.getUserByUsername(username);
//			if (user->getPassword() == password)
//			{
//				cout << "Sign in" << endl;
//				return;
//			}
//			throw MyException("Password sehvdir !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//		}
//		catch (MyException ex)
//		{
//			cout << (ex.what()) << endl;
//		}
//	}
//
//	void sign_up(string username, string password, string name, string surname)
//	{
//		bool isCheck = true;
//
//		try
//		{
//			if (!(username.size() >= 6))
//				throw MyException("Username minimum 6 simvol olmalidir !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//		}
//		catch (MyException ex)
//		{
//			isCheck = false;
//			cout << ex.what() << endl;
//
//		}
//
//		try
//		{
//			if (!(password.size() >= 6))
//				throw MyException("Password minimum 6 simvol olmalidir !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//		}
//		catch (MyException ex)
//		{
//			isCheck = false;
//			cout << ex.what() << endl;
//
//		}
//
//		try
//		{
//			if (!(name.size() >= 3))
//				throw MyException("Name minimum 3 simvol olmalidir !!! ", __FILE__, __DATE__, __TIME__, __LINE__);
//		}
//		catch (MyException ex)
//		{
//			isCheck = false;
//			cout << ex.what() << endl;
//		}
//
//		try
//		{
//			if (!(surname.size() >= 4))
//				throw MyException("Surname minimum 4 simvol olmalidir !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//		}
//		catch (MyException ex)
//		{
//			isCheck = false;
//			cout << ex.what() << endl;
//		}
//
//		if (isCheck)
//		{
//			try
//			{
//				User& user = _database.getUserByUsername(username);
//				throw MyException("Database-de bu Username artiq movcuddur.Zehmet olmasa basqa Username daxil edin !!!", __FILE__, __DATE__, __TIME__, __LINE__);
//			}
//			catch (MyException ex)
//			{
//
//				User new_user(username, password, name, surname);
//				_database.addUser(new_user);
//				cout << "Sign up" << endl;
//			}
//		}
//	}
//
//};
//
//class StartUp
//{
//public:
//	static void Start()
//	{
//		Database database;
//		User user("Hsyn2005", "huseyn2005", "Huseyn", "Orucov");
//
//
//		database.addUser(user);
//
//		user.Show();
//
//		Registration registration(database);
//
//		registration.sign_up("Cavid2000", "cavid1234", "Cavid", "Atamoghlanov");
//	}
//};
//
//int main()
//{
//	StartUp::Start();
//}
//
