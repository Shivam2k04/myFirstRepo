/*
* FILE : f8.cpp
* PROJECT : Focused 8
* PROGRAMMER : Sivam Maisuria
* FIRST VERSION : 2024-03-29
* DESCRIPTION :  A program that reads command line arguments to create a text file with specific strings.
* The functions in this file reads command line arguments like strings, number of times strings is written in text file,
  specified directory name where file is created and lastly file name.
*/

// standard input output header file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Disables fopen function warning
#pragma warning(disable: 4996)

// function definition of struct that contains command line arguements
struct MyData
{
	int howMany;
	char theText[21];
	char directoryPath[21];
	char filename[21];
};

int main(int argc, char* argv[])
{
	// variable to store the number of times a string will be written in text file.
	int num;

	// if statement to check if theres only 4 arguments
	if (argc != 5)
	{
		// error message 
		printf("Error: Must be only 4 arguments\n");
		// end program
		return 1;
	}
	// if statement to check if the first argument is converted to an integer
	if (sscanf_s(argv[1], "%d", &num) != 1)
	{
		// error message to display if no integer has bbeen entered
		printf("Error: Missing integer\n");
		// end program
		return 2;
	}

	// for loop to check each argument
	for (int i = 1; i < argc; i++)
	{
		// if statement to check if number is positive or not
		if (num <= 0)
		{
			// error message to display if integer is negative
			printf("Error: interger must be positive\n");
			// end program
			return 3;
		}
		// else if statement to check if the lenght of the string is not more than 20 characters
		else if (strlen(argv[i]) > 20)
		{
			// error message to dsiplay if lenght of string os more than 20 characters
			printf("Error: String lenght must be less than or equal 20 characters\n");
			// end program
			return 4;
		}

	}
	// file created successful message
	printf("File created successfully");

	// struct to hold command line arguments
	struct MyData myArgs;
	// number of repetitions from first argument and storing it in myArgs.howMany
	myArgs.howMany = atoi(argv[1]);
	// copying string from second argument into myArgs.theText
	strcpy(myArgs.theText, argv[2]);
	// copying directory path from third argument into myArgs.directoryPath
	strcpy(myArgs.directoryPath, argv[3]);
	// copying file name from fourth argument  into myArgs.filename
	strcpy(myArgs.filename, argv[4]);

	// array to hold file location path myArgs.directoryPath to fileLocation
	char fileLocation[100];
	// copying directory path to file location
	strcpy(fileLocation, myArgs.directoryPath);
	// apending backslash to directory path
	strcat(fileLocation, "\\");
	//  Appending the specified file name from myArgs.filename to complete the file location path
	strcat(fileLocation, myArgs.filename);

	// File pointer for text file
	FILE* fp;
	// opening text file in write mode
	fp = fopen(fileLocation, "w");

	// if statement if file created successful
	if (fp == NULL)
	{
		// error message
		printf("Error: failed to create text file\n");
		// end program
		return 5;
	}
	// for loop to iterate strings according to the specified number
	for (int i = 0; i < myArgs.howMany; i++)
	{
		// if statement to check if file pointer is valid
		if (fp)
		{
			// writing string in text file
			fprintf(fp, "%s\n", myArgs.theText);
		}

	}

	// Function to close file
	fclose(fp);
	//exit program
	return 0;
}