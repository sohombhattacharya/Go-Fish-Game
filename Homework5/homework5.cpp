#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
// Sohom Bhattacharya
// CMPSC 121
// Date Completed: 11/15

void makeDeck(int deck[], int& size)
{
	deck[size];
	
	for (int i = 0; i < size; i++)
	{			
		deck[i] = 2 + (i % 8);

	}


}

void shuffle(int deck[], int& size)
{

	int i;
	int k;
	int temp;
	for ( i = 0; i < size; i++ )
	{
		k = 1 + (rand() % 32);
		temp = deck[i];
		deck[i] = deck[k];
		deck[k] = temp;
	}

}

void createHand(int hand[], int deck[], int& deck_size, int& hand_size)
{

	int temp; 
	int counter = deck_size - 1; 
	for (int i = 0; i < hand_size; i++)
	{
		temp = deck[counter];
		hand[i] = temp; 
	
		counter--;
	
	}

	deck_size = counter; 

}
void addCard(int hand[], int& hand_size, int card)
{

	hand[hand_size] = card; 

	hand_size= hand_size + 1;

}

void drawCard(int deck[], int hand[], int& hand_size, int& deck_size, int& drawn)
{
	drawn = deck[deck_size - 1];

	addCard(hand,hand_size,drawn);

	deck_size = deck_size - 1;


}

void sortHand(int hand[], int hand_size)
{
	for (int i = 0; i < hand_size; i++)
	{
		for (int j = i + 1; j < hand_size; j++)
		{
			if (hand[i] > hand[j])
			{
			
			swap(hand[i],hand[j]);
			
			}
		}
	}
}



void searchHand(int hand[], int& hand_size, int card, int& counter)
{
	for (int i = 0; i < hand_size; i++)
	{
		if (hand[i] == card)
		{
		
		counter++;
		
		
		}
	
	}


}

void deleteCard(int hand[], int& hand_size, int card)
{

	for (int i = 0; i < hand_size; i++)
	{
		if (hand[i] == card)
		{
			for (int j = i + 1; j < hand_size; j++)
			{
			
			int temp = hand[j];
			hand[i] = temp; 
			i++;
			
			}
		
		
		}
	
	
	
	}
				hand_size--;




}

void computerTurn(int deck[], int computerHand[], int userHand[],int& deckSize, int& computerHandSize, int& userHandSize, int& computer_score, int& user_score)
{
	

		int times = 1;
		
		
		while (times >  0)
			{
				times = 0; 
			
				int guess = rand()%7 + 2;
				int counter = 0; 
				cout << "I ask: Do you have any ... " << guess << "'s?" << endl;
		
			searchHand(userHand, userHandSize, guess, times);
				
				if (times > 0)
				{
				
				cout << "You have " << times<< endl; 
			
			for (int k = 0; k < times; k++)
			{
					addCard(computerHand, computerHandSize, guess);
					deleteCard(userHand, userHandSize, guess);		
			}

			sortHand(userHand, userHandSize);

			cout << "You have: ";
			for (int i = 0; i < userHandSize; i++)
				cout << userHand[i] << " ";
			cout << '\n';
			
			for (int j = 0; j < computerHandSize; j++)
			{
				if (computerHand[j] == guess)
					counter++; 
			
			}
			
			if (counter == 4)
			{
			cout << "I completed a set!" << endl; 
			
			for (int i = 0; i < 4; i++)
			{deleteCard(computerHand, computerHandSize, guess);}
			
			computer_score++;
			}
		
			}

			if (times == 0)
			{
			int card; 
			cout << "You don't have any!" << endl;
			drawCard(deck, computerHand, computerHandSize, deckSize, card);
			cout << "I draw a card"<< endl;
			counter = 0;

			for (int j = 0; j < computerHandSize; j++)
			{
				if (computerHand[j] == card)
					counter++; 
			
			}
			
			if (counter == 4)
			{
			cout << "I completed a set!" << endl; 
			
			for (int i = 0; i < 4; i++)
			{deleteCard(computerHand, computerHandSize, card);}
			
			computer_score++;
			}

			cout << "Your turn!" << endl;
			
			}
		}


}

void userTurn(int deck[], int computerHand[], int userHand[],int& deckSize, int& computerHandSize, int& userHandSize, int& computer_score, int& user_score)
{

	sortHand(userHand, userHandSize);

	cout << "You have:";
	for (int i = 0; i < userHandSize; i++)
	cout << ' ' << userHand[i];
	cout << '\n';

		int times = 1;
		int guess; 
		
		
		while (times >  0 && (computerHandSize > 0))
			{
				times = 0;
			
				cout << "You ask if I have a .... " << endl;
		cin >> guess; 
		int counter = 0; 
		
		searchHand(computerHand, computerHandSize, guess, times);
				
				if (times > 0)
				{
				cout << "Yes I do. I have " << times<< endl; 
			
			for (int k = 0; k < times; k++)
			{
					addCard(userHand, userHandSize, guess);
					deleteCard(computerHand, computerHandSize, guess);		
			}
			
						sortHand(userHand, userHandSize);

			cout << "You have: ";
			for (int i = 0; i < userHandSize; i++)
				cout << userHand[i] << " ";
			cout << '\n';
			for (int j = 0; j < userHandSize; j++)
			{
				if (userHand[j] == guess)
					counter++; 
			
			}
			
			if (counter == 4)
			{
			cout << "You completed a set!" << endl; 
			
			for (int i = 0; i < 4; i++)
			{deleteCard(userHand, userHandSize, guess);}
			
			user_score++;
			}
		
			}

		}
	
		if (times == 0)
		{
			int drawn_card; 
			cout << "No I don't! Go Fish!" << endl;
			drawCard(deck, userHand, userHandSize, deckSize, drawn_card);
			cout << "You draw a " << drawn_card << endl;
			int counter = 0; 
			for (int j = 0; j < userHandSize; j++)
			{
				if (userHand[j] == drawn_card)
					counter++; 
			
			}
			
			if (counter == 4)
			{
			cout << "You completed a set!" << endl; 
			
			for (int i = 0; i < 4; i++)
			{deleteCard(userHand, userHandSize, drawn_card);}
			
			user_score++;
			}




			cout << "My Turn!" << endl;
		
		}

		if (computerHandSize == 0)
		cout << "Computer has no more cards!" << endl;


}



void play_GoFish()
{
	string play_again = "yes";
	while (play_again == "yes")
	{
	int deck[32];
	int deckSize = 32; 
	int userHand[32];
	int userHandSize = 5; 
	int computerHand[32];
	int computerHandSize = 5;
	int user_score = 0; 
	int computer_score = 0;


	makeDeck(deck, deckSize);
	shuffle(deck, deckSize);
	createHand(userHand, deck, deckSize, userHandSize); 
	createHand(computerHand, deck, deckSize, computerHandSize);
	sortHand(userHand, userHandSize);
	sortHand(computerHand, computerHandSize);

	cout << "Lets play a game of go fish" << endl;
	
	while (deckSize != 0 && computerHandSize != 0 && userHandSize != 0)
	{
		userTurn(deck, computerHand, userHand, deckSize,computerHandSize, userHandSize, computer_score, user_score);	
		if (computerHandSize == 0 || deckSize == 0)
		{
			if (computerHandSize == 0)
			cout << "Game Over! The Computer ran out of cards!" << endl;
			
			if (deckSize == 0)
			cout << "Game Over! The deck ran out of cards!" << endl;
		}
		else 
		computerTurn(deck, computerHand, userHand, deckSize, computerHandSize, userHandSize, computer_score, user_score);

		if (userHandSize == 0 || deckSize == 0)
		{
		
			if (userHandSize == 0)
			cout << "Game Over! You ran out of cards!" << endl;
		
			if (deckSize == 0)
			cout << "Game Over! The deck ran out of cards!" << endl;
		}
	}

		cout << "Final Score: Computer - " << computer_score << "  You - " << user_score << endl;
		cout << "Would you like to play again? Enter yes or no" << endl;
		cin >> play_again; 

	
	}

	



}


int main()
{
	

	play_GoFish();
	
	
	cout << '\n';

}
