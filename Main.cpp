//Main.cpp
//the main program that will control the Cheaters program
//Based on the program that finds and opens a file directory

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files){
   DIR *dp;
   struct dirent *dirp;
   if((dp =opendir(dir.c_str())) == NULL) {
      cout << "Error(" << errno << ") opening " << dir << endl;
      return errno;
   }

   while ((dirp = readdir(dp)) != NULL){
      files.push_back(string(dirp->d_name));
   }
   closedir(dp);
   return(0);
}

int main(int argc, char *argv[]) {
   string dir = string("argv[2]");
   vector<string> files = vector<string>();

   getdir(dir,files);

   for (unsigned int i = 0; i < files.size(); i++){
      cout << i << files[i] << endl;
      ifstream infile;
      infile.open(files[i]);
      if(infile.is_open()){
         for(int c = 0; c + (argc[3] -1)  != eof(); c++){
            string output;
            int temp = c;
            while (output.length < argc[3]){
               output << infile[temp];
               temp++;
            }
            cout << output << endl;
         }
      }
      else{
         cout << "could not open file" << endl;
      }
   }
   return 0;
}
