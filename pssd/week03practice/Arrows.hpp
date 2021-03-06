/*
 * =====================================================================================
 *
 *       Filename:  Arrows.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/2017 02:28:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

class Arrows{

    public:
        int longestArrow(string s){
            int res = 0;
            int itr = 0;
            int tempM = 0;
            char check;
			bool test = false;
            for(int i=0;i<s.length();i++){
                itr = i;
                if(s[i]=='<'){
                    int temp = 0;
                    check = s[i+1];
					test = true;
                    if(check!=s[i]&&check!='>'){
                        temp++;
                        itr++;
                        while(s[itr]==check&&itr<s.length()){
                            temp++;
                            itr++;
                        }
                    }
                    if(temp>tempM)
                        tempM = temp;
                }
                if(s[i]=='>'){
                    int temp = 0;
                    check = s[i-1];
					test = true;
                    if(check!=s[i]&&check!='<'){
                        temp++;
                        itr--;
                        while(s[itr]==check&&itr>=0){
                            temp++;
                            itr--;
                        }
                    }
                    if(temp>tempM)
                        tempM = temp;
                }
            }
			if(test==true&&tempM==0)
				return 1;
            if(tempM==0)
                return -1;

            return tempM;
        }


};
