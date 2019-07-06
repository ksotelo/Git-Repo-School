// clientprogram.cpp
// Kat Sotelo

#include <iostream>
#include <fstream>
#include "two34tree.h"
#include "two34treenode.h"
#include "exception.h"
#include "key.h"
using namespace std;

// prints a number of newlines on the screen
// pre: numberOfLines is assigned a positive value_comp
// post: numberOfLines newlines has been printed on the screen
// usage: makeNewLines(3);
void newLines(fstream& output, int num);
//opens an output file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openOutputFile(output, filename);
void openOutputFile(fstream& output);
//closes an output file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is closed
//      with its file pointer at the end of the file 
//      else an error message is printed
//usage openOutputFile(output, filename);
void closeOutputFile(fstream& output);
//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(fstream& infile);
//closes an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is closed
//      with its file pointer at the end of the file 
//      else an error message is printed
//usage closeInputFile(infile, filename);
void closeInputFile(fstream& infile);
//
//
//
//
void testingCase1(fstream& output, fstream& infile);
//
//
//
//
void testingCase2(fstream& output, fstream& infile);
//
//
//
//
void testingCase3(fstream& output, fstream& infile);
//
//
//
//
void testingCase4(fstream& output, fstream& infile);
//
//
//
//
void testingCase5(fstream& output, fstream& infile);
// Creates an 234Tree with newKeys
// pre: 234Tree exists. infile has been opened with file pointer at beginning
//      items are arranged so that text is on one line
//		and comes in with integer num that decides the num keys read in
// post: 234Tree is now an 234 tree of keys num
// usage: create234Tree(infile, tree, num);
void create234Tree(fstream& infile, Two34Tree& tree, int num);
// displays tree in reader-friendly fashion without branches in the output file or inorder fashion
// post: the picture of the tree has been displayed on the screen or inorder list
// usage: display234Tree(output, avltree, which);
void display234Tree(fstream& output, Two34Tree& tree, char which);


int main()
{
	fstream infile, output;
	
	openInputFile(infile);
	openOutputFile(output);
	
	testingCase1(output, infile);
	testingCase2(output, infile);
	testingCase3(output, infile);
	testingCase4(output, infile);
	testingCase5(output, infile);	
		
	closeInputFile(infile);
	closeOutputFile(output);
	
	return 0;
}

//
//
//
//
void testingCase1(fstream& output, fstream& infile)
{
	Two34Tree tree1, tree2, tree3, tree4, tree5, tree6;
	
	output << "~~~~~<><><><><>~~~~~~~~~~~~~~~~~~~~  " << "TESTING: CASE 1" << "  ~~~~~~~~~~~~~~~~~~~~<><><><><>~~~~~" << endl << endl;
	
	output << "TEST 1: TREE IS EMPTY, ADD ONE KEY - ccc" << endl;
	display234Tree(output, tree1, 'p');
	create234Tree(infile, tree1, 1);
	display234Tree(output, tree1, 'p');
	
	output << "TEST 2: TREE HAS ONE KEY, ADD ONE KEY TO LEFT OF NODE - aaa" << endl;
	create234Tree(infile, tree2, 1);
	display234Tree(output, tree2, 'p');
	create234Tree(infile, tree2, 1);
	display234Tree(output, tree2, 'p');
	
	output << "TEST 3: TREE HAS ONE KEY, ADD ONE KEY TO RIGHT OF NODE - ddd" << endl;
	create234Tree(infile, tree3, 1);
	display234Tree(output, tree3, 'p');
	create234Tree(infile, tree3, 1);
	display234Tree(output, tree3, 'p');
	
	output << "TEST 4: TREE HAS TWO KEYS, ADD ONE KEY TO MIDDLE OF NODE - bbb" << endl;
	create234Tree(infile, tree4, 2);
	display234Tree(output, tree4, 'p');
	create234Tree(infile, tree4, 1);
	display234Tree(output, tree4, 'p');
	
	output << "TEST 5: TREE HAS TWO KEYS, ADD ONE KEY TO RIGHT OF NODE - ccc" << endl;
	create234Tree(infile, tree5, 2);
	display234Tree(output, tree5, 'p');
	create234Tree(infile, tree5, 1);
	display234Tree(output, tree5, 'p');
	
	output << "TEST 6: TREE HAS TWO KEYS, ADD ONE KEY TO LEFT OF NODE - aaa" << endl;
	create234Tree(infile, tree6, 2);
	display234Tree(output, tree6, 'p');
	create234Tree(infile, tree6, 1);	
	display234Tree(output, tree6, 'p');
}

//
//
//
//
void testingCase2(fstream& output, fstream& infile)
{
	Two34Tree tree1, tree2, tree3, tree4;
	
	output << "~~~~~<><><><><>~~~~~~~~~~~~~~~~~~~~  " << "TESTING: CASE 2" << "  ~~~~~~~~~~~~~~~~~~~~<><><><><>~~~~~" << endl << endl;	
	
	output << "TEST 1: TREE HAS FULL ROOT NODE, ADD ONE SMALLER KEY TO LEFT KID - ccc" << endl;
	create234Tree(infile, tree1, 3);
	display234Tree(output, tree1, 'p');
	create234Tree(infile, tree1, 1);
	display234Tree(output, tree1, 'p');
	
	output << "TEST 2: TREE HAS FULL ROOT NODE, ADD ONE LARGER KEY TO LEFT KID- hhh" << endl;
	create234Tree(infile, tree2, 3);
	display234Tree(output, tree2, 'p');
	create234Tree(infile, tree2, 1);
	display234Tree(output, tree2, 'p');
	
	output << "TEST 3: TREE HAS FULL ROOT NODE, ADD ONE SMALLER KEY TO RIGHT KID - ooo" << endl;
	create234Tree(infile, tree3, 3);
	display234Tree(output, tree3, 'p');
	create234Tree(infile, tree3, 1);
	display234Tree(output, tree3, 'p');
	
	output << "TEST 4: TREE HAS FULL ROOT NODE, ADD ONE LARGER KEY TO RIGHT KID - yyy" << endl;
	create234Tree(infile, tree4, 3);
	display234Tree(output, tree4, 'p');
	create234Tree(infile, tree4, 1);
	display234Tree(output, tree4, 'p');	
}

//
//
//
//
void testingCase3(fstream& output, fstream& infile)
{
	Two34Tree tree1, tree2, tree3, tree4, tree5, tree6, tree7, tree8, tree9, tree10;
	
	output << "~~~~~<><><><><>~~~~~~~~~~~~~~~~~~~~  " << "TESTING: CASE 3" << "  ~~~~~~~~~~~~~~~~~~~~<><><><><>~~~~~" << endl << endl;

	output << "TEST 1: ROOT NODE HAS ONE ITEM, ADD ONE KEY TO THE MIDDLE OF THE LEFT KID -ddd" <<endl;
	create234Tree(infile, tree1, 4);
	display234Tree(output, tree1, 'p');
	create234Tree(infile, tree1, 1);
	display234Tree(output, tree1, 'p');

	output << "TEST 2: ROOT NODE HAS ONE ITEM, ADD ONE SMALLER KEY TO LEFT KID -aaa" << endl;
	create234Tree(infile, tree2, 4);
	display234Tree(output, tree2, 'p');
	create234Tree(infile, tree2, 1);
	display234Tree(output, tree2, 'p');
	
	output << "TEST 3: ROOT NODE HAS ONE ITEM, ADD ONE LARGER KEY TO LEFT KID - hhh" << endl;
	create234Tree(infile, tree3, 4);
	display234Tree(output, tree3, 'p');
	create234Tree(infile, tree3, 1);
	display234Tree(output, tree3, 'p');
	
	output << "TEST 4: ROOT NODE HAS ONE ITEM, ADD ONE SMALLER KEY TO RIGHT KID - nnn" << endl;
	create234Tree(infile, tree4, 4);
	display234Tree(output, tree4, 'p');
	create234Tree(infile, tree4, 1);
	display234Tree(output, tree4, 'p');

	output << "TEST 5: ROOT NODE HAS ONE ITEM, ADD ONE LARGER KEY TO RIGHT KID - zzz" << endl;
	create234Tree(infile, tree5, 4);
	display234Tree(output, tree5, 'p');
	create234Tree(infile, tree5, 1);
	display234Tree(output, tree5, 'p');
	
	output << "TEST 6: ROOT NODE HAS ONE ITEM, ADD ONE MIDDLE KEY TO RIGHT KID - xxx" << endl;
	create234Tree(infile, tree6, 4);
	display234Tree(output, tree6, 'p');
	create234Tree(infile, tree6, 1);
	display234Tree(output, tree6, 'p');

	output << "TEST 7: ROOT NODE HAS ONE ITEM, ADD ONE SMALLER KEY TO RIGHT KID - uuu" << endl;
	create234Tree(infile, tree7, 4);
	display234Tree(output, tree7, 'p');
	create234Tree(infile, tree7, 1);
	display234Tree(output, tree7, 'p');
	
	output << "TEST 8: ROOT NODE HAS ONE ITEM, ADD ONE LARGER KEY TO RIGHT KID - zzz" << endl;
	create234Tree(infile, tree8, 4);
	display234Tree(output, tree8, 'p');
	create234Tree(infile, tree8, 1);
	display234Tree(output, tree8, 'p');

	output << "TEST 9: ROOT NODE HAS ONE ITEM, ADD ONE SMALLER KEY TO LEFT KID - ddd" << endl;
	create234Tree(infile, tree9, 4);
	display234Tree(output, tree9, 'p');
	create234Tree(infile, tree9, 1);
	display234Tree(output, tree9, 'p');
	
	output << "TEST 10: ROOT NODE HAS ONE ITEM, ADD ONE LARGER KEY TO LEFT KID - iii" << endl;
	create234Tree(infile, tree10, 4);
	display234Tree(output, tree10, 'p');
	create234Tree(infile, tree10, 1);
	display234Tree(output, tree10, 'p');	
}

//
//
//
//
void testingCase4(fstream& output, fstream& infile)
{
	
}

//
//
//
//
void testingCase5(fstream& output, fstream& infile)
{
	
}

// Creates an 234Tree with newKeys
// pre: 234Tree exists. infile has been opened with file pointer at beginning
//      items are arranged so that text is on one line
//		and comes in with integer num that decides the num keys read in
// post: 234Tree is now an 234 tree of keys num
// usage: create234Tree(infile, tree, num);
void create234Tree(fstream& infile, Two34Tree& tree, int num)
{
	Key newKey;
	
	for (int i = 0; i < num; i++)
	{
		infile >> newKey;
		tree.addNewEntry(newKey);
	}
}

// displays tree in reader-friendly fashion without branches in the output file or inorder fashion
// post: the picture of the tree has been displayed on the screen or inorder list
// usage: display234Tree(output,avltree);
void display234Tree(fstream& output, Two34Tree& tree, char which)
{
	newLines(output, 2);
	tree.display(output, which);
	newLines(output, 2);
}


// prints a number of newlines on the screen
// pre: numberOfLines is assigned a positive value_comp
// post: numberOfLines newlines has been printed on the screen
// usage: makeNewLines(3);
void newLines(fstream& output, int num)
{
	for (int i = 0; i < num; i++)
		output << endl;
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(fstream& infile)
{
	infile.open("two.dat");
	if (infile.fail())
    {
      cout << "Input file failed to open!!!" << endl;
      exit(1);
    }
}

//closes an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is closed
//      with its file pointer at the end of the file 
//      else an error message is printed
//usage closeInputFile(infile, filename);
void closeInputFile(fstream& infile)
{
	infile.close();
}

//opens an output file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openOutputFile(output, filename);
void openOutputFile(fstream& output)
{
	output.open("out.dat");
	if (output.fail())
    {
      cout << "Output file failed to open!!!" << endl;
      exit(1);
    }
}

//closes an output file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is closed
//      with its file pointer at the end of the file 
//      else an error message is printed
//usage openOutputFile(output, filename);
void closeOutputFile(fstream& output)
{
	output.close();
}
