#include "std_lib_facilities.h"

	struct Person{
		private:
			string first_name;
			string last_name;
			int age;
		public:
			Person(){};
			Person(string f_name, string l_name, int a){
				const vector<char> err_char = {
					';','?',':','[',']','*','&','^',
				    '%','$','#','@','!','.','"','\''
				};
				if(a < 0 || a > 150) 
					error("Age is not valid!");

				if(f_name == "" || l_name == "") 
					error("Name can't be empty");

				for(int i=0; i<err_char.size(); i++)
					if(f_name.find(err_char[i]) != string::npos ||
					   l_name.find(err_char[i]) != string::npos)
					    	error("Invalid character spotted!");
			
			constructor(f_name, l_name, a);
			}

		void constructor(string f_name, string l_name, int a){
			first_name = f_name;
			last_name = l_name;
			age = a;
		}

		string get_f() const {return first_name;}
		string get_l() const {return last_name;}
		int get_a() const {return age;}
	};

ostream& operator<< (ostream& os, Person& p){
		return os << p.get_f() << ' ' << p.get_l()
		<< ", aged " << p.get_a() << endl;
	}

istream& operator>> (istream& is, Person& p)
{
	string f_name, l_name; int a;

	cout<<"Enter First name: ";
	is>>f_name;

	cout<<"Enter Last name: ";
	is>>l_name;

	cout<<"Enter age: ";
	is>>a;

	p=Person{f_name, l_name, a};

	return is;
}

int main(){

	try{
		Person G{"Goofy", "Goofy", 63};
		cout << G;

		Person p1;
		cin >> p1;
		cout << p1;

		cout << "Enter names and ages. Terminate " <<
		"with \"stop\" - \"stop\" - 1." << endl;
		vector<Person> persons;
		
		for (Person p2; cin >> p2;){
			if (p2.get_f() == "stop") break;
			persons.push_back(p2);
		}
		
		cout << "=========== List ===========" << endl;

		for (Person p:persons)
			cout << p << endl;

	}
	catch(exception& e){
		cerr << "Error: " << e.what() << endl;
		return 2; 
	}
	catch(...){
		cerr << "Unknown exception!" << endl; 
		return 2;
	}
	return 0;
}