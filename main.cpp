#include <iostream>
#include <fstream>
int StringCompare(char* first, char* second) {
 int i = 0;
 while(first[i] != '\0' && second[i] != '\0'){
 if(first[i] != second[i])
 return first[i] < second[i] ? -1 : 1;
 i++;
 }
 return first[i] == second[i] ? 0 : first[i] < second[i] ? -1 : 1;
}

struct arguments
{
	char* word;
	char* file;
};
char* ofile {"--file"};
char* oword {"--word"};
arguments cl_parser(int argc, char** argv)
{
	arguments ar;
	for(int i=1; i<argc; ++i)
	{
		if(StringCompare(argv[i], ofile)==0) ar.file=argv[i+1];
		if(StringCompare(argv[i], oword)==0) ar.word=argv[i+1];
	}
	return ar;
}
bool contain(char* check, char* word)
{
	int i=0;
	int j=0;
	bool b=true;
	while(word[i]!='\0')
	{
		j=0;
		while(check[j]!='\0' && check[j]!=word[i]) ++j;
		if(check[j]!=word[i]) return false;
		i++;
	}
	return true;
}

int main(int argc, char** argv) {
	arguments ar=cl_parser(argc, argv);
	std::ifstream fin;
	fin.open(ar.file);
	char c[1000];
	int ans=0;
	while(fin.getline(c, 10000, ' ')) 
	{
		ans+=contain(c, ar.word);
	}
	std::cout << ans;
	return 0;
}
