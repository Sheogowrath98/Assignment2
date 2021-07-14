/* Student Name: Mishaal Fadhl
 * Student Number: 991454815
 * filename: deck.c
 */

#include <stdio.h> /* for printf */
#include <stdlib.h> /* for malloc and free */
#include <string.h> /* for strcpy */
#include <time.h> /* for time */

/* Use these constants */
#define SUITS 4
#define RANKS 13
#define DECK_SIZE 52

typedef struct {
char *rank;
char *suit;
char *colour;
}Card;

Card *create_deck (); // deck of cards created
void print_to_screen (Card *); // print the deck of card
void shuffle_deck (Card *); // creating a file for shuffled deck of cards
void print_to_file (char *, Card *); // creating a file for deck of cards

int main (int argc, char *argv[]) {
Card *deck = create_deck(); // deck of cards created

printf(" *************** Original Deck ***************\n");
  print_to_screen (deck); /* display original deck */
  if (argc ==3){ // creating 3 arguments for files
  print_to_file (argv[1], deck); /*print to a filename argument from commandline */
   } 

printf("\n\n *************** Shuffled Deck ***************\n");
shuffle_deck (deck);
print_to_screen (deck); /* display shuffled deck */
if (argc == 3) { // creating 3 arguments for files
print_to_file(argv[2], deck); /*print to a filename argument from commandline */

}

free(deck); // Being used to free up space in the deck.

return 0;
}

Card* create_deck() { //deck of cards created
 /* Use these arrays to point rank and suit to, or to strcpy from.*/
char *ranks[] = {"King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2", "Ace"}; // creating a numeric / symbol deck
char *suits[] = {"Spades", "Clubs", "Hearts", "Diamonds"}; // creating a symbol deck

/* allocate space for 52 cards on the heap */
Card *deck = malloc(52 * sizeof(Card)); // Search memory for the size fo deck of cards

/* Place cards into the space */
for (int i = 0; i < 52; i++) { // creating a deck of cards of 52
Card card = *(deck + i);
}

/* Set the ranks,suits and colours of the cards */

for (int i = 0; i < 52; i++) { // creating a deck of cards of 52

deck[i].rank = ranks[i % 13]; // Creating a set of ranks from King - Ace 4 times 
deck[i].suit = suits[i / 13]; // Creating a set of suits 13 times

// Checks the suit and sets the colour accordingly

if (strcmp(deck[i].suit, "Spades") == 0
|| strcmp (deck[i].suit, "Clubs") == 0) 

{

deck[i].colour = "Black of"; // the colour of the deck of cards

} else {

deck[i].colour = "Red of";  

}

}

return deck;
}

/* Display the deck on screen (see sample output on assignment sheet). */
void print_to_screen(Card *deck) {

for (int i = 0; i < 52; i++) {

printf("%s %s %s\n", deck[i].colour, deck[i].suit, deck[i].rank); // printing out the original and shuffled deck of cards

}

}

/* 
 * Algorithm to be implemented in shuffle_deck: 
 *  Traverse the deck, swapping the current card with a randomly chosen card.
 */

void shuffle_deck (Card *deck) {

srand(time(NULL)); // Generating a set of random numbers

// Iterates 52 times to switch each card

for (int i = 0; i < 52; i++) {

Card temp = *(deck + i); // Card selected will be replaced with random generated card
int randomCard = rand() % 52; // Selecting a random card from the 52 card deck
*(deck + i) = deck[randomCard]; // replace current card with random generated card
deck[randomCard] = temp; // Replaces random car with current card

}

}

/* print the deck to a file */
void print_to_file(char *fileName, Card *deck) {

FILE *outputFile;

outputFile = fopen(fileName, "m"); // File is opened.

// All card printed to file
for (int i = 0; i < 52; i++) {

fprintf(outputFile, "%s %s %s\n", deck[i].colour, deck[i].suit, deck[i].rank);

}

fclose(outputFile); // File is closed

}