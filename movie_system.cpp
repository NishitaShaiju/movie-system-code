#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    int year;
public:
    Movie(string t="", int y = 0) : title(t), year(y) {}
	
    void display() {
        cout << "Title: " << title << ", Year: " << year << endl;}
};

class MovieSystem {
private:
    Movie* movies;
    int count;   
    int capacity; 
public:
    MovieSystem(int cap): count(0), capacity(cap) {
        movies = new Movie[capacity];
        cout << "Movie system created with capacity: " << capacity << endl;
    }

    ~MovieSystem() {
        delete[] movies;
        cout << "Movie system destroyed" << endl;
    }

    void addMovie(const Movie& movie) {
        if (count < capacity) {
            movies[count++] = movie;
        } else {
            cout << "Error: Movie list is full." << endl;
        }
    }
    
    Movie& operator[](int index) {
        if (index < 0 || index >= count) {
            cout << "Error: Index out of range." << endl;
        }
        return movies[index];
    }


    void display() const {
        for (int i = 0; i < count; ++i) {
            movies[i].display();
        }
    }
    

};

class movie {
    public:
    static string mov[5];
    static double rate[5];
    static void show() {
        for (int i=0;i<5;i++) {
            cout<<"\n Movie Name = "<<mov[i]<<endl;
            cout<<"\n Rating = "<<rate[i]<<endl;
        }
    }
movie(double r) {
        cout << "Rating: " << r << endl;
    }

    movie(string m) {
        cout << "Movie Name: " << m << endl;
    }

};

string movie::mov[5] = {"Inception", "The Matrix", "Interstellar", "The Godfather", "Pulp Fiction"};
double movie::rate[5] = {3.6, 4.7, 4.2, 3.0, 3.3};

class Movies {
public:
    string title;
    int year;
    Movies() {}

    Movies(string t, int y) : title(t), year(y) {}
    void show() {
        cout << "Title: " << title << ", Year: " << year << endl;
    }
};

class Genre : public Movies {
public:
    string genre;
    Genre() : Movies() {}
    Genre(string t, int y, string g) : Movies(t, y), genre(g) {}

    void showg() {
        show(); 
        cout << "Genre: " << genre << endl;
    }
};


class Rating : public Genre {
public:
    double rating;
    Rating() : Genre(), rating(0.0) {}
    Rating(string t, int y, string g, double r): Genre(t, y, g), rating(r) {}

    void showr() {
        showg();
        cout << "Rating: " << rating << endl;
    }
};

class tax {
    public :
     double price;
     double gst=0.05;
     double total;
    tax() 
    {
        cout<<"Enter ticket price = ";
        cin>>price;
        total=price*gst;
    }
    
    tax(tax& object1)
    {
        cout<<"Copy Constructor = \n";
        price=object1.price+1000;
        gst;
        total=object1.total;
    }
    void display() {
        cout<< "Price : "<<price<<endl;
        cout<<"GST : "<<price*gst<<endl;
        cout<<"Total : "<<(price*gst)+price<<endl;
        cout<<endl;
    }
};

class Ticket {
private:
    string event;
    double price;
public:
    Ticket(const string& event, double price)
        : event(event), price(price) {}

    static double avg(Ticket tickets[], int size) {
        double total = 0.0;
        for (int i = 0; i<5; ++i) {
            total += tickets[i].price;}
        return (size > 0) ? total / size : 0;}

    void display() {
        cout << "Event: " << event<< ", Price: " << price << " rupees"<< endl;}
};



int main() {
	int numbers;
	cout<<"Welcome! What would you like to do today?"<<
	"\n1.View available movies"<<
	"\n2.Enter a movie rating"<<
	"\n3.Create a movie list"<<
	"\n4.Check ticket price"<<
	"\n5.Check average ticket price"<<endl;
	cin>>numbers;
	
	if (numbers==1) {
		    MovieSystem* system = new MovieSystem(5);
    system->addMovie(Movie("Inception", 2010));
    system->addMovie(Movie("The Matrix", 1999));
    system->addMovie(Movie("Interstellar", 2014));
    system->addMovie(Movie("Minions", 2015));
    system->addMovie(Movie("Frozen", 2014));
    system->addMovie(Movie("Knives Out", 2017));
    system->addMovie(Movie("Glass Onion", 2022));

    cout << "\nAll Movies in the System:" << endl;
    system->display();
    
    cout << "\nAccessing a specific movie:" << endl;
    Movie& movie = (*system)[1];
    movie.display();
    
    cout << "\nAccessing movie out of range:" << endl;
    Movie& err = (*system)[8];
    err.display();
    
    delete system;
    return 0;
}

    if (numbers==2) {
    	    movie::show();
    double a;
    string b;
    cout<<"Enter movie name : "<<endl;
    cin>>b;
    cout<<"Enter rating : "<<endl;
    cin>>a;
    
    movie obj1(b);
    movie obj2(a);
    return 0;
	}
	
	 if (numbers==3) {
	 	Rating* movies= new Rating[10];
    int n;

    cout << "How many movies do you want to enter ? ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Invalid number" << endl;
        return 1;
    }


    for (int i = 0; i < n; ++i) {
        string title, genre;
        int year;
        double rating;

        cout << "Enter title of movie " << (i + 1) << ": ";
        cin>>title;
        
        cout << "Enter year of movie " << (i + 1) << ": ";
        cin >> year;

        cout << "Enter genre of movie " << (i + 1) << ": ";
        cin >> genre;

        cout << "Enter rating of movie " << (i + 1) << ": ";
        cin >> rating; 


        movies[i] = Rating(title, year, genre, rating);
}

	cout << "\nMovie List:\n";
            
    for (int i = 0; i < n; ++i) {
        movies[i].showr();
        cout << "---------------------\n";
    } 

    return 0;
	 	
	 }
	 
	if (numbers==4) {
	tax a;
    a.display();
    
    tax b(a);
    b.display();
    return 0;
		
	}
	
	if (numbers==5) {
		Ticket tickets[] = {
        Ticket("Minions", 10),
        Ticket("Frozen", 50),
        Ticket("James Bond", 75.0),
        Ticket("Fast&Furious", 30.0)
    };
    for (int i = 0; i < 4; i++) {
    tickets[i].display();}
    int size = sizeof(tickets) / sizeof(tickets[0]);
    double avg = Ticket::avg(tickets, size);
    cout << "Average Ticket Price: " << avg <<" rupees"<<endl;
    return 0;
		
	}
	
}


