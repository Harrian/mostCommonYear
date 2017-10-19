#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

bool readInFirstNameLastNameBeginYearEndYear(std::string & firstName,std::string & lastName,int & beginYear,int & endYear){
  //try to read in a first name if it fails something is wrong or end of input
  if(!(std::cin>>firstName))
    return false;
  //try to read in a last name if it fails something is wrong
  if(!(std::cin>>lastName))
    return false;
  //try to read in a last name if it fails something is wrong
  if(!(std::cin>>beginYear))
    return false;
  //try to read in a last name if it fails something is wrong
  if(!(std::cin>>endYear))
    return false;
  //if everything was successfully read in return true
  return true;
}
void increaseValuesInYearsAlive(std::unordered_map<int,int> & years, int beginYear, int endYear){
  //if the year exists already increment by one otherwise add that year
  for(int i=beginYear;i<=endYear;i++)
    if(years.find(i)==years.end())
      years[i]=1;
    else
      years[i]++;
}
//if there is a tie between multiple years for the most number of people alive return all of them
std::vector<int> getYearsWithMostAlive(std::unordered_map<int,int> & years){
  int max=-1;
  //find max
  for(auto x:years)
    max=std::max(max,x.second);

  std::vector<int> yearsWithMostALive;
  //get all years that have the max number of people alive
  for(auto x:years)
    if(x.second==max)
      yearsWithMostALive.push_back(x.first);
      
  return yearsWithMostALive;
}
int main(void){
  std::string curFirstName,curLastName;
  int curBeginYear=0,curEndYear=0;
  std::unordered_map<int,int> years;
  //while can read in a person's information
  while(readInFirstNameLastNameBeginYearEndYear(curFirstName,curLastName,curBeginYear,curEndYear)){
    //increment years this person was alive by one
    increaseValuesInYearsAlive(years,curBeginYear,curEndYear);
  }
  //if no one was read in then we're done
  if(years.size()==0){
    std::cout<<"Empty input"<<std::endl;
  }else{
    //get the years with most alive
    std::vector<int> yearsWithMostALive(getYearsWithMostAlive(years));
    //sort it to display in correct order
    std::sort(yearsWithMostALive.begin(),yearsWithMostALive.end());
    //display
    std::cout<<"Year(s) with the most people alive: "<<std::endl;
    for(auto x:yearsWithMostALive)
      std::cout<<x<<std::endl;
  }
  return 0;
}