#include <SFML/Graphics.hpp>
#include <windows.h>
#include <bits/stdc++.h>
#include <string>

#define screen_weight 800
#define screen_height 640
#define elements 100

int dataset[elements]={96, 79, 77, 59, 32, 48, 9, 60, 68, 52, 86, 31, 46, 55, 91, 57, 56, 3, 11, 98, 95, 75, 6, 92, 100, 89, 1, 
19, 47, 2, 35, 85, 44, 54, 72, 93, 97, 78, 67, 29, 81, 39, 17, 94, 51, 80, 14, 49, 21, 53, 18, 73, 16, 84, 90, 20, 41, 36, 66, 
40, 63, 28, 37, 30, 61, 71, 8, 45, 88, 74, 5, 15, 22, 25, 26, 87, 10, 50, 13, 99, 70, 76, 65, 64, 12, 34, 38, 4, 42, 27, 43, 69, 82, 62, 58, 24, 83, 23, 7, 33};

bool swaped[elements];
int swap_counter=0;
int comparisons=0;

// Audio or sound effect didnt added cuz of no information about music theory

//int dataset[elements]={100,200,300};

/*
void sort(int arr[]){
	while(1){
		int s;
		bool chk=0;
		for(int i=0;i<elements-1;i++){
			if(arr[i]>arr[i+1]){
				chk=1;
				s=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=s;
			}

		}
		if(chk==0){
			break;
		}
	}

}*/

int main(){

	memset(swaped, 0,elements);
	
	sf::Font font;
	if (!font.loadFromFile("Prototype.ttf")){
		// error...
	}



    sf::RenderWindow window(sf::VideoMode(screen_weight,screen_height),"",sf::Style::Close);
	


	sf::Text compt;
	compt.setFont(font); 
	compt.setString(std::to_string(comparisons));
	compt.setCharacterSize(14);
	compt.setFillColor(sf::Color::White);
	compt.setPosition(0,25);
	sf::Text swapt;
	swapt.setFont(font); 
	swapt.setString(std::to_string(swap_counter));
	swapt.setCharacterSize(14);
	swapt.setFillColor(sf::Color::White);

	while(window.isOpen()){
		sf::Event evnt;
		while(window.pollEvent(evnt)){
			if(evnt.type == evnt.Closed){
				window.close();
			}

		}


		window.clear();
		for(int i=0;i<elements;i++){
			sf::RectangleShape bar(sf::Vector2f(static_cast<int>(screen_weight/elements)-2,dataset[i]*4));
			swaped[i]==1?bar.setFillColor(sf::Color::Blue):bar.setFillColor(sf::Color::White);
			bar.setPosition( static_cast<int>(screen_weight/elements)*i+2,screen_height-dataset[i]*4);
			//std::cout<<"x: "<<static_cast<float>(screen_height-dataset[i],static_cast<int>(screen_weight/elements)*i + 2) << "y: " << static_cast<float>(static_cast<int>(screen_weight/elements)) <<std::endl;
			window.draw(bar);
			
		}
		compt.setString("Comparisons: " + std::to_string(comparisons));
		swapt.setString("Swapped: " + std::to_string(swap_counter));
		window.draw(compt);
		window.draw(swapt);
		window.display();

		int s;
		bool chk=0;
		memset(swaped, 0,elements);
		for(int i=0;i<elements-1;i++){
			comparisons++;
			if(dataset[i]>dataset[i+1]){
				chk=1;
				s=dataset[i];
				dataset[i]=dataset[i+1];
				dataset[i+1]=s;

				swap_counter++;
				swaped[i]=1;
				swaped[i+1]=1;
				break;
			}

		}
		if(chk==0){
			Sleep(10000);
			window.close();
		}

		Sleep(30);

	}


    return 0;
}