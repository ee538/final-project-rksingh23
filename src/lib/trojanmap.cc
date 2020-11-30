#include "trojanmap.h"

#include <cmath>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip> 
#include <cfloat>
#include <chrono>
#include <bits/stdc++.h> 

#include <algorithm>
#include <fstream>
#include <locale>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <functional>
#include <queue>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

//-----------------------------------------------------
// TODO (Students): You do not and should not change the following functions:
//-----------------------------------------------------

/**
 * PrintMenu: Create the menu
 * 
 */
void TrojanMap::PrintMenu() {

  std::cout << std::endl;
  std::string menu =
      "\t*****************************************************************************************************************************************************\n"
      "\t** Select the function you want to execute.                                                                                                        **\n"
      "\t** 1. Autocomplete                - STARTS WITH IMPLEMENTATION     : Searches and returns Nodes that * STARTS WITH * the input string              **\n"
      "\t** 2. Autocomplete                - STRING ANYWHERE IMPLEMENTATION : Searches and returns Nodes that have the input string present * ANYWHERE *    **\n"
      "\t** 3. Find the position                                                                                                                            **\n"
      "\t** 4. CalculateShortestPath       - BELLMAN - FORD ALGORITHM       : for incorporating -ve edges, WARNING ---> BAD RUNTIME                         **\n"
      "\t** 5. CalculateShortestPath       - DIJKSTRA ALGORITHM             : for quicker runtime                                                           **\n"
      "\t** 6. Travelling salesman problem - Brute Force IMPLEMENTATION                                                                                     **\n"
      "\t** 7. Travelling salesman problem - 2 OPT Heuristic IMPLEMENTATION :                                                                               **\n"
      "\t** 8. Exit                                                                                                                                         **\n"
      "\t*****************************************************************************************************************************************************\n";
  std::cout << menu << std::endl;
  std::string input;
  getline(std::cin, input);
  char number = input[0];
  switch (number)
  {

  case '1':
  {
    menu =
        "**************************************************************\n"
        "* 1. Autocomplete  * STARTS WITH *                            \n"
        "**************************************************************\n";
    std::cout << menu << std::endl;
    menu = "Please input a partial location:";
    std::cout << menu;
    getline(std::cin, input);
    auto results = Autocomplete(input);
    menu = "*************************Results******************************\n";
    std::cout << menu;
    if (results.size() != 0) {
      for (auto x : results) std::cout << x << std::endl;
    } else {
      std::cout << "No locations starts with the input string provided - Please Try Again." << std::endl;
    }
    menu = "**************************************************************\n";
    std::cout << menu << std::endl;
    PrintMenu();
    break;
  }

  case '2':
  {
    menu =
        "**************************************************************\n"
        "* 2. Autocomplete   * ANYWHERE *                              \n"
        "**************************************************************\n";
    std::cout << menu << std::endl;
    menu = "Please input a partial location:";
    std::cout << menu;
    getline(std::cin, input);
    auto results = Autocomplete_Anywhere(input);
    menu = "*************************Results******************************\n";
    std::cout << menu;
    if (results.size() != 0) {
      for (auto x : results) std::cout << x << std::endl;
    } else {
      std::cout << "Input string does not match any locations.- Please Try Again" << std::endl;
    }
    menu = "**************************************************************\n";
    std::cout << menu << std::endl;
    PrintMenu();
    break;
  }

  case '3':
  {
    menu =
        "**************************************************************\n"
        "* 3. Find the position                                        \n"
        "**************************************************************\n";
    std::cout << menu << std::endl;
    menu = "Please input a location:";
    std::cout << menu;
    getline(std::cin, input);
    auto results = GetPosition(input);
    menu = "*************************Results******************************\n";
    std::cout << menu;
    if (results.first != -1) {
      std::cout << "Latitude: " << std::setprecision(10)<< results.first
                << " Longitude: " << std::setprecision(10)<< results.second << std::endl;
      PlotPoint(results.first, results.second);
    } else {
      std::cout << "No matched locations. - Please Try Again" << std::endl;
    }
    menu = "**************************************************************\n";
    std::cout << menu << std::endl;
    PrintMenu();
    break;
  }

  case '4':
  {
    menu =
        "********************************************************************\n"
        "* 4. CalculateShortestPath BELLMAN - FORD                           \n"
        " WARNING: please be patient - MAX. WAIT TIME is approx 3 minutes    \n"
        "********************************************************************\n";
    std::cout << menu << std::endl;
    menu = "Please input the start location:";
    std::cout << menu;
    std::string input1;
    getline(std::cin, input1);
    menu = "Please input the destination:";
    std::cout << menu;
    std::string input2;
    getline(std::cin, input2);
    auto results = CalculateShortestPath_Bellman(input1, input2);
    menu = "*************************Results******************************\n";
    std::cout << menu;
    if (results.size() != 0) {
      for (auto x : results) std::cout << x << std::endl;
      PlotPath(results);
    } else {
      std::cout << "No route from the start point to the destination."
                << std::endl;
    }
    menu = "**************************************************************\n";
    std::cout << menu << std::endl;
    PrintMenu();
    break;
  }

  case '5':
  {
    menu =
        "**************************************************************\n"
        "* 5. CalculateShortestPath DIJKSTRA                             "
        "      \n"
        "**************************************************************\n";
    std::cout << menu << std::endl;
    menu = "Please input the start location:";
    std::cout << menu;
    std::string input1;
    getline(std::cin, input1);
    menu = "Please input the destination:";
    std::cout << menu;
    std::string input2;
    getline(std::cin, input2);
    auto results = CalculateShortestPath(input1, input2);
    menu = "*************************Results******************************\n";
    std::cout << menu;
    if (results.size() != 0) {
      for (auto x : results) std::cout << x << std::endl;
      PlotPath(results);
    } else {
      std::cout << "No route from the start point to the destination."
                << std::endl;
    }
    menu = "**************************************************************\n";
    std::cout << menu << std::endl;
    PrintMenu();
    break;
  }

  case '6':
  {
    menu =
        "**************************************************************\n"
        "* 6. Travelling salesman problem - BRUTE FORCE                \n"
        "**************************************************************\n";
    std::cout << menu << std::endl;
    menu = "In this task, we will select N random points on the map and you need to find the path to travel these points and back to the start point.";
    std::cout << menu << std::endl << std::endl;
    menu = "Please input valid integer number for the number of the places to be traversed:";
    std::cout << menu;
    getline(std::cin, input);
    int num = std::stoi(input);
    /*
    while(!isdigit(num))
    {
      menu = "Please input valid integer number for the number of the places to be traversed:";
      std::cout << menu;
      getline(std::cin, input);
      num = std::stoi(input);
    }*/

    std::vector<std::string> keys;
    for (auto x : data) {
      keys.push_back(x.first);
    }
    std::vector<std::string> locations;
    srand(time(NULL));
    for (int i = 0; i < num; i++)
      locations.push_back(keys[rand() % keys.size()]);
    PlotPoints(locations);
    std::cout << "Calculating ..." << std::endl;
    auto results = TravellingTrojan(locations);
    menu = "*************************Results******************************\n";
    std::cout << menu;
    CreateAnimation(results.second);
    if (results.second.size() != 0) {
      for (auto x : results.second[results.second.size()-1]) std::cout << x << std::endl;
      menu = "**************************************************************\n";
      std::cout << menu;
      std::cout << "The distance of the path is:" << results.first << std::endl;
      PlotPath(results.second[results.second.size()-1]);
    } else {
      std::cout << "The size of the path is 0" << std::endl;
    }
    menu = "**************************************************************\n"
           "You could find your animation at src/lib/output.avi.          \n";
    std::cout << menu << std::endl;
    PrintMenu();
    break;
  }

  case '7':
  {
    menu =
        "**************************************************************\n"
        "* 7. Travelling salesman problem - 2 OPT Heuristic            \n"
        "**************************************************************\n";
    std::cout << menu << std::endl;
    menu = "In this task, we will select N random points on the map and you need to find the path to travel these points and back to the start point.";
    std::cout << menu << std::endl << std::endl;
    menu = "Please input the number of the places:";
    std::cout << menu;
    getline(std::cin, input);
    int num = std::stoi(input);
    std::vector<std::string> keys;
    for (auto x : data) {
      keys.push_back(x.first);
    }
    std::vector<std::string> locations;
    srand(time(NULL));
    for (int i = 0; i < num; i++)
      locations.push_back(keys[rand() % keys.size()]);
    PlotPoints(locations);
    std::cout << "Calculating ..." << std::endl;
    auto results = TravellingTrojan_2opt(locations);
    menu = "*************************Results******************************\n";
    std::cout << menu;
    CreateAnimation(results.second);
    if (results.second.size() != 0) {
      for (auto x : results.second[results.second.size()-1]) std::cout << x << std::endl;
      menu = "**************************************************************\n";
      std::cout << menu;
      std::cout << "The distance of the path is:" << results.first << std::endl;
      PlotPath(results.second[results.second.size()-1]);
    } else {
      std::cout << "The size of the path is 0" << std::endl;
    }
    menu = "**************************************************************\n"
           "You could find your animation at src/lib/output.avi.          \n";
    std::cout << menu << std::endl;
    PrintMenu();
    break;
  }
  case '8':
    break;
  default:
    std::cout << "Please select 1 - 8." << std::endl;
    PrintMenu();
    break;
  }
}


/**
 * CreateGraphFromCSVFile: Read the map data from the csv file
 * 
 */
void TrojanMap::CreateGraphFromCSVFile() {
  std::fstream fin;
  fin.open("src/lib/map.csv", std::ios::in);
  std::string line, word;

  getline(fin, line);
  while (getline(fin, line)) {
    std::stringstream s(line);

    Node n;
    int count = 0;
    while (getline(s, word, ',')) {
      word.erase(std::remove(word.begin(), word.end(), '\''), word.end());
      word.erase(std::remove(word.begin(), word.end(), '"'), word.end());
      word.erase(std::remove(word.begin(), word.end(), '['), word.end());
      word.erase(std::remove(word.begin(), word.end(), ']'), word.end());
      if (count == 0)      //collumn 0
      {
        n.id = word;
        nodes.push_back(word);
      }
      else if (count == 1) //collumn 1
        n.lat = stod(word);
      else if (count == 2) //column 2
        n.lon = stod(word);
      else if (count == 3) //collumn 3
        {
          n.name = word;
          if(!word.empty())    
          {
            nameVector.push_back(word);
            std::pair<double,double> pair1=std::make_pair(n.lat,n.lon);
            location_map.insert (std::pair<std::string, std::pair<double, double>> (word,pair1));  
          }
        }
      else                //collumn 4
      word.erase(std::remove(word.begin(), word.end(), ' '), word.end());
        n.neighbors.push_back(word);
      count++;
    }
    data[n.id] = n;
  }
  fin.close();
}

/**
 * PlotPoint: Given a location id, plot the point on the map
 * 
 * @param  {std::string} id : location id
 */
void TrojanMap::PlotPoint(std::string id) {
  std::string image_path = cv::samples::findFile("src/lib/input.jpg");
  cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
  auto result = GetPlotLocation(data[id].lat, data[id].lon);
  cv::circle(img, cv::Point(result.first, result.second), DOT_SIZE,
             cv::Scalar(0, 0, 255), cv::FILLED);
  cv::imshow("TrojanMap", img);
  cv::waitKey(1);
}
/**
 * PlotPoint: Given a lat and a lon, plot the point on the map
 * 
 * @param  {double} lat : latitude
 * @param  {double} lon : longitude
 */
void TrojanMap::PlotPoint(double lat, double lon) {
  std::string image_path = cv::samples::findFile("src/lib/input.jpg");
  cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
  auto result = GetPlotLocation(lat, lon);
  cv::circle(img, cv::Point(int(result.first), int(result.second)), DOT_SIZE,
             cv::Scalar(0, 0, 255), cv::FILLED);
  cv::startWindowThread();
  cv::imshow("TrojanMap", img);
  cv::waitKey(1);
}

/**
 * PlotPath: Given a vector of location ids draws the path (connects the points)
 * 
 * @param  {std::vector<std::string>} location_ids : path
 */
void TrojanMap::PlotPath(std::vector<std::string> &location_ids) {
  std::string image_path = cv::samples::findFile("src/lib/input.jpg");
  cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
  auto start = GetPlotLocation(data[location_ids[0]].lat, data[location_ids[0]].lon);
  cv::circle(img, cv::Point(int(start.first), int(start.second)), DOT_SIZE,
             cv::Scalar(0, 0, 255), cv::FILLED);
  for (unsigned int i = 1; i < location_ids.size(); i++) {
    auto start = GetPlotLocation(data[location_ids[i - 1]].lat, data[location_ids[i - 1]].lon);
    auto end = GetPlotLocation(data[location_ids[i]].lat, data[location_ids[i]].lon);
    cv::circle(img, cv::Point(int(end.first), int(end.second)), DOT_SIZE,
               cv::Scalar(0, 0, 255), cv::FILLED);
    cv::line(img, cv::Point(int(start.first), int(start.second)),
             cv::Point(int(end.first), int(end.second)), cv::Scalar(0, 255, 0),
             LINE_WIDTH);
  }
  cv::startWindowThread();
  cv::imshow("TrojanMap", img);
  cv::waitKey(1);
}

/**
 * PlotPoints: Given a vector of location ids draws the points on the map (no path).
 * 
 * @param  {std::vector<std::string>} location_ids : points
 */
void TrojanMap::PlotPoints(std::vector<std::string> &location_ids) {
  std::string image_path = cv::samples::findFile("src/lib/input.jpg");
  cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
  for (auto x : location_ids) {
    auto result = GetPlotLocation(data[x].lat, data[x].lon);
    cv::circle(img, cv::Point(result.first, result.second), DOT_SIZE,
               cv::Scalar(0, 0, 255), cv::FILLED);
  }
  cv::imshow("TrojanMap", img);
  cv::waitKey(1);
}


/**
 * CreateAnimation: Create the videos of the progress to get the path
 * 
 * @param  {std::vector<std::vector<std::string>>} path_progress : the progress to get the path
 */
void TrojanMap::CreateAnimation(std::vector<std::vector<std::string>> path_progress){
  cv::VideoWriter video("src/lib/output.avi", cv::VideoWriter::fourcc('M','J','P','G'), 10, cv::Size(1248,992));
  for(auto location_ids: path_progress) {
    std::string image_path = cv::samples::findFile("src/lib/input.jpg");
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    auto start = GetPlotLocation(data[location_ids[0]].lat, data[location_ids[0]].lon);
    cv::circle(img, cv::Point(int(start.first), int(start.second)), DOT_SIZE,
              cv::Scalar(0, 0, 255), cv::FILLED);
    for (unsigned int i = 1; i < location_ids.size(); i++) {
      auto start = GetPlotLocation(data[location_ids[i - 1]].lat, data[location_ids[i - 1]].lon);
      auto end = GetPlotLocation(data[location_ids[i]].lat, data[location_ids[i]].lon);
      cv::circle(img, cv::Point(int(end.first), int(end.second)), DOT_SIZE,
                cv::Scalar(0, 0, 255), cv::FILLED);
      cv::line(img, cv::Point(int(start.first), int(start.second)),
              cv::Point(int(end.first), int(end.second)), cv::Scalar(0, 255, 0),
              LINE_WIDTH);
    }
    video.write(img);
    cv::imshow("TrojanMap", img);
    cv::waitKey(1);
  }
	video.release();
}
/**
 * GetPlotLocation: Transform the location to the position on the map
 * 
 * @param  {double} lat         : latitude 
 * @param  {double} lon         : longitude
 * @return {std::pair<double, double>}  : position on the map
 */
std::pair<double, double> TrojanMap::GetPlotLocation(double lat, double lon) {
  std::pair<double, double> bottomLeft(34.01001, -118.30000);
  std::pair<double, double> upperRight(34.03302, -118.26502);
  double h = upperRight.first - bottomLeft.first;
  double w = upperRight.second - bottomLeft.second;
  std::pair<double, double> result((lon - bottomLeft.second) / w * 1248,
                                   (1 - (lat - bottomLeft.first) / h) * 992);
  return result;
}

//-----------------------------------------------------
// TODO: Student should implement the following:
//-----------------------------------------------------
/**
 * GetLat: Get the latitude of a Node given its id.
 * 
 * @param  {std::string} id : location id
 * @return {double}         : latitude
 */
double TrojanMap::GetLat(std::string id) { 
    Node temp = data[id];     //Extracting the value for the corresponding key i.e. id from data map
  return temp.lat; 
}

/**
 * GetLon: Get the longitude of a Node given its id. 
 * 
 * @param  {std::string} id : location id
 * @return {double}         : longitude
 */
double TrojanMap::GetLon(std::string id) { 
  Node temp = data[id];  
  return temp.lon; 
}

/**
 * GetName: Get the name of a Node given its id.
 * 
 * @param  {std::string} id : location id
 * @return {std::string}    : name
 */
std::string TrojanMap::GetName(std::string id) { 
  Node temp = data[id];  
  return temp.name; 
}


std::string TrojanMap::GetId(std::string name) { 
  std::string null;
  if (name.empty()) return null;
  
  for(auto x=data.begin();x!=data.end();x++)
  {
    Node temp = x->second;
    if(temp.name == name)
    {
      return temp.id;
    }
  }
  return null;
}

/**
 * GetNeighborIDs: Get the neighbor ids of a Node.
 * 
 * @param  {std::string} id            : location id
 * @return {std::vector<std::string>}  : neighbor ids
 */
std::vector<std::string> TrojanMap::GetNeighborIDs(std::string id) {

    //Corner case
    std::vector<std::string> empty;

    auto it = std::find (nodes.begin(), nodes.end(), id);
    if (it == nodes.end())        
    {
      std::cout<<"No such place in the Map - Try again"<<std::endl;
      return empty;
    } 

    std::vector<std::string> result;
    Node temp = data[id];
    return temp.neighbors;
}


/**
 * CalculateDistance: Get the distance between 2 nodes. 
 * 
 * @param  {Node} a  : node a
 * @param  {Node} b  : node b
 * @return {double}  : distance in mile
 */
double TrojanMap::CalculateDistance(const Node &a, const Node &b) {
  // TODO: Use Haversine Formula:
 
  double dlat = (b.lat - a.lat) * M_PI / 180.0;
  double dlon = (b.lon - a.lon) * M_PI / 180.0;

  // convert to radians
  double aLat = (a.lat) * M_PI / 180.0; //a is constant!!
  double bLat = (b.lat) * M_PI / 180.0;

  double a_ = pow(sin(dlat / 2), 2) + pow(sin(dlon / 2), 2) * cos(aLat) * cos(bLat);  
  double c = 2 * asin(sqrt(a_));
  double distances = 3961 * c;
  return distances;
}

/**
 * CalculatePathLength: Calculates the total path length for the locations inside the vector.
 * 
 * @param  {std::vector<std::string>} path : path
 * @return {double}                        : path length
 */
double TrojanMap::CalculatePathLength(const std::vector<std::string> &path) {
  double sum = 0;

  if (path.empty()) return sum;

  int prev_index = 0;
  unsigned int cur_index = 1;
  while(cur_index<path.size())
  {
    Node cur = data[path[cur_index]];
    Node prev = data[path[prev_index]];
    sum += CalculateDistance(cur,prev);                                                              //Calculate total distance between nodes
    prev_index = cur_index;
    cur_index += 1; //cur goes to next index inside path vector
  }
  return sum;
}





/**
 * Autocomplete: Given a parital name return all the possible locations with
 * partial name as the prefix.
 *
 * @param  {std::string} name          : partial name
 * @return {std::vector<std::string>}  : a vector of full names
 */
std::vector<std::string> TrojanMap::Autocomplete(std::string name) {
  std::vector<std::string> results;
   std::string namecmp=name;
  std::string namesrc;

  //Corner Case
  std::vector<std::string> empty;
  if (name.empty())   return empty;                                                 //Corner Case : when name is given blank. 
  
  for(auto i:nameVector)
    {
        std::string namesrc=i.substr(0,name.length());
        //npos returns -1. If substring is not found, find will return -1.
        //if substring is found, condition fails and count is incremented 
        //namesrc=i;
        transform(namesrc.begin(),namesrc.end(),namesrc.begin(),::tolower);   // Converting to lower for comparison 
        transform(namecmp.begin(),namecmp.end(),namecmp.begin(),::tolower);   // Converting to lower for comparison 

      //  std::cout<<namesrc<<" | | "<<namecmp<<std::endl;
        if (namecmp.compare(namesrc) == 0)
            results.push_back(i);                                 // Pushing original deta into the result vector
    }

  std::sort(results.begin(),results.end());//sort the vector

  return results;
}


std::vector<std::string> TrojanMap::Autocomplete_Anywhere(std::string name) {
  std::vector<std::string> results;

  std::string namesrc;
  std::string namecmp=name;

  //Corner Case
  std::vector<std::string> empty;
  if (name.empty())   return empty;                                                 //Corner Case : when name is given blank. 
  
  for(auto i:nameVector)
    {
        //npos returns -1. If substring is not found, find will return -1.
        //if substring is found, condition fails and count is incremented 
        namesrc=i;
        transform(namesrc.begin(),namesrc.end(),namesrc.begin(),::tolower);   // Converting to lower for comparison 
        transform(name.begin()   ,name.end()   ,name.begin()   ,::tolower);   // Converting to lower for comparison 

        if (namesrc.find(namecmp) != std::string::npos)
            results.push_back(i);                                 // Pushing original deta into the result vector
    }
  std::sort(results.begin(),results.end());//sort the vector
  return results;
}


/**
 * GetPosition: Given a location name, return the position.
 *
 * @param  {std::string} name          : location name
 * @return {std::pair<double,double>}  : (lat, lon)
 */
std::pair<double, double> TrojanMap::GetPosition(std::string name) {
  std::pair<double, double> results;
  
  //CORNER CASE
  std::pair<double, double> empty;
  std::string null;
  std::string id_position = GetId(name);
  if (id_position==null)        
  {
    std::cout<<"No such place in the Map - Try again"<<std::endl;
    return empty;
  } 

  std::map<std::string, std::pair<double, double>>::iterator it = location_map.find(name);
  if (it != location_map.end())
    results=std::make_pair(it->second.first,it->second.second);                                 //Creating the result pair

  return results;
}



/**
 * CalculateShortestPath: Given 2 locations, return the shortest path which is a
 * list of id.
 *
 * @param  {std::string} location1_name     : start
 * @param  {std::string} location2_name     : goal
 * @return {std::vector<std::string>}       : path
 */


TrojanMap::~TrojanMap() { std::cout<<std::endl<<" Code Executed Succesfully - Destructor Activated \n"; }



      //DIJKSTRA ALGORITHM


std::vector<std::string> TrojanMap::CalculateShortestPath(std::string location1_name, std::string location2_name)
{
  auto time_stamp_start = std::chrono::steady_clock::now();
std::vector<std::string> x;
std::map<std::string, double> dist; //maps id with its respective distance from source


std::map<std::string, std::string> parent_path;
std::string start = GetId(location1_name);
std::string end = GetId(location2_name);
std::map<std::string,std::vector<std::string>> adj_list;


//CORNER CASES
  std::vector<std::string> empty;
  std::string null;
  
  //std::cout<<start<<"  "<<end<<std::endl;
  if ((location1_name.empty())||(location2_name.empty())) return empty;
  else if ((start==null)||(end==null))                    return empty;
  else
  {

  for (auto it: data){
          adj_list[it.second.id]= it.second.neighbors;
    }
    
  typedef std::pair<double,std::string> dist_info;
  std::priority_queue <dist_info, std::vector<dist_info>, std::greater<dist_info>> max_heap;

  for(auto it = data.begin(); it!=data.end();it++) {
    Node n = it->second;
    dist[n.id] = DBL_MAX;
  }

  max_heap.push(std::make_pair(0,GetId(location1_name)));

  parent_path[GetId(location1_name)]= "null"; // blank value for key source in previous map
  
  Node a = data[GetId(location1_name)]; // loc1 node
//  std::cout<<" loc1 id is: "<< GetId(location1_name)<<std::endl;

  std::string loc2_id= GetId(location2_name);
  //  std::cout<<" loc2 id is: "<< loc2_id<<std::endl;
  dist[a.id] = 0;
  double weight=0;

  std::string cur_node;

  while(!max_heap.empty())    //actually we should write while Max_heap->data != location2_name
  {
    cur_node = max_heap.top().second; // u is id of node on which we re currently present
    //x.push_back(u);
    max_heap.pop();

    //now we need an iterator to get the neighbours and their weights

  for(auto neighbor : adj_list[cur_node]) 
    {
        weight = CalculateDistance(data[cur_node],data[neighbor]);  //Shortest Distance between current node and neighbor 

    if(dist[neighbor] > (dist[cur_node] + weight)) //if distance of current node > distance of current node and it's neighbor
    {

    dist[neighbor] = (dist[cur_node] + weight); //Distance of source to current node + distance of current node to it's neighbor
    parent_path[neighbor] = cur_node; 
    max_heap.push(std::make_pair(dist[neighbor],neighbor));
    // x.push_back(cur_node);
    }
    }
  }
  

  result.clear();
  std::string parent = parent_path[end];
  result.push_back(end);
  while (parent !=start)
  {
    result.push_back(parent);
    parent=parent_path[parent];
  }
  result.push_back(start);
  std::reverse(result.begin(),result.end());

  x = result;
 
  
  auto time_stamp_stop = std::chrono::steady_clock::now(); 
  std::chrono::duration<double> duration_program = time_stamp_stop - time_stamp_start; 
  
  std::cout << "Time taken by function: "<< duration_program.count() << " seconds" << std::endl;
  parent_path.clear();

  return x;
  } //end of else
}





//***********************************************************************************
//BELLMAN FORD

  std::vector<std::string> TrojanMap::CalculateShortestPath_Bellman(std::string location1_name,
                                                 std::string location2_name)
{

auto time_stamp_start = std::chrono::steady_clock::now();
std::vector<std::string> x;
std::map<std::string, double> dist; //maps id with its respective distance from source

std::map<std::string, std::string> parent_path;
std::string start = GetId(location1_name);
std::string end = GetId(location2_name);
std::map<std::string,std::vector<std::string>> adj_list;

//CORNER CASES
  std::vector<std::string> empty;
  std::string null;
  
  //std::cout<<start<<"  "<<end<<std::endl;
  if ((location1_name.empty())||(location2_name.empty())) return empty;
  else if ((start==null)||(end==null))                    return empty;
  else
  {
  

  for (auto it: data){
          adj_list[it.second.id]= it.second.neighbors;
    }

  for(auto it = data.begin(); it!=data.end();it++) {
    Node n = it->second;
    dist[n.id] = DBL_MAX;
  }

  dist[start] = 0;
    std::string loc2_id= GetId(location2_name);


for(size_t i=0;i<nodes.size()-1;i++) //Total edges 
  {
  for(auto cur_node:nodes) 
  {
    for(auto neighbor : adj_list[cur_node]) 
    {
       auto  weight = CalculateDistance(data[cur_node],data[neighbor]);  //Shortest Distance between current node and neighbor 

    if(dist[neighbor] > (dist[cur_node] + weight)) //if distance of current node > distance from source to parent node and it's neighbor
      {
        dist[neighbor] = (dist[cur_node] + weight); //Distance of source to current node + distance of current node to it's neighbor
        parent_path[neighbor] = cur_node; 
      }
    }
  }
  }

  result.clear();
  std::string parent = parent_path[end];
  result.push_back(end);
  while (parent !=start)
  {
    result.push_back(parent);
    parent=parent_path[parent];
  }
  result.push_back(start);
  std::reverse(result.begin(),result.end());


   x = result;
   auto time_stamp_stop = std::chrono::steady_clock::now(); 
  std::chrono::duration<double> duration_program = time_stamp_stop - time_stamp_start; 
  
    std::cout << "Time taken by function: "<< duration_program.count() << " seconds" << std::endl;
  return x;
  }
}


//***********************************************************************************





/**
 * Travelling salesman problem: Given a list of locations, return the shortest
 * path which visit all the places and back to the start point.
 *
 * @param  {std::vector<std::string>} input : a list of locations needs to visit
 * @return {std::pair<double, std::vector<std::vector<std::string>>} : a pair of total distance and the all the progress to get final path
 */

std::vector<std::string> TrojanMap::two_optSwap(std::vector<std::string> route, int i, int j) {
   std::vector<std::string> temp;
      for(int x=0; x < i; x++){
          temp.push_back(route[x]);
      }
      for(int x=j; x>=i; x--){
          temp.push_back(route[x]);
      }
      unsigned int route_size = j+1;
      if(route_size<route.size())
       for(unsigned int x=j+1; x < route.size(); x++){
          temp.push_back(route[x]);
      }
      return temp;
 }

std::pair<double, std::vector<std::vector<std::string>>> TrojanMap::TravellingTrojan(
                                    std::vector<std::string> &location_ids) {
  auto time_stamp_start = std::chrono::steady_clock::now();

  std::pair<double, std::vector<std::vector<std::string>>> empty;
  if (location_ids.empty()) return empty;
 
  std::pair<double, std::vector<std::vector<std::string>>> results;
  std::vector< std::pair<double,std::vector<std::string>>> paths;

//Brute Force
 std::vector<Node> location_data(location_ids.size());
  Node curr_, fuv_;
  int N = location_ids.size();
  std::vector<std::vector<double>> graph_build;
  for(unsigned int i=0;i<location_ids.size();i++)
  {
    location_data[i]=data[location_ids[i]];
  }
  for(int i = 0; i < N; i++) {
   std::vector<double> row_vector;
    for(int j = 0; j < N; j++)  row_vector.push_back( CalculateDistance(data[location_ids[i]], data[location_ids[j]]));
    graph_build.push_back(row_vector);
  }
  std::vector<int> vertices;
  for(int i = 1; i < N; i++) vertices.push_back(i);

  double min_path = DBL_MAX;
  std::vector<std::string> dfs_track(location_ids.size()+1);
  dfs_track[0] = location_data[0].id;
  do{
      double curr__pathwieght = 0.0;
      int k = 0;
      for(unsigned int i = 0; i < vertices.size();i++){
        curr__pathwieght = curr__pathwieght + graph_build[k][vertices[i]];
        k = vertices[i];
      }
      curr__pathwieght = curr__pathwieght + graph_build[k][0];
      min_path = std::min(min_path, curr__pathwieght);
      if(min_path == curr__pathwieght) {
          for(auto o:vertices)  dfs_track.push_back(location_data[o].id);
              dfs_track.push_back(location_data[0].id);
          results.second.push_back(dfs_track);
          dfs_track.erase(dfs_track.begin()+1, dfs_track.end());      
       }
    } while(std::next_permutation(vertices.begin(), vertices.end()));
    results.first = min_path;
    auto time_stamp_stop = std::chrono::steady_clock::now(); 
    std::chrono::duration<double> duration_program = time_stamp_stop - time_stamp_start; 
  
    std::cout << "Time taken by function: "<< duration_program.count() << " seconds" << std::endl;
    return results;

} 

std::pair<double, std::vector<std::vector<std::string>>> TrojanMap::TravellingTrojan_2opt(
                                    std::vector<std::string> &location_ids) {

std::pair<double, std::vector<std::vector<std::string>>> empty;
  if (location_ids.empty()) return empty;

         auto time_stamp_start = std::chrono::steady_clock::now();
         std::vector< std::pair<double,std::vector<std::string>>> paths; 
          std::pair<double, std::vector<std::vector<std::string>>> results;
         std::vector<std::string> exisiting_route  = location_ids;
              exisiting_route.push_back(location_ids[0]);
      double prev = DBL_MAX;
      bool improve = true;
      while(improve) {
      start_again:
      improve= false;
       double best_distance = CalculatePathLength(exisiting_route);
       if(paths.size()==0)
       {
          paths.push_back({best_distance,exisiting_route});
       }
       if(prev-best_distance <= 0) break;
       prev = best_distance;
        for(unsigned int i = 1; i <= location_ids.size()-2; i++) {
          for(unsigned int k = i+1; k <= location_ids.size()-1; k++) {
            std::vector<std::string> new_route = two_optSwap(exisiting_route, i,k);
            double new_distance = CalculatePathLength(new_route);
            //std::cout<<i<<" "<<k<<" "<<new_distance<<std::endl;
            if(new_distance < best_distance) {
              exisiting_route = new_route;
              best_distance = new_distance;
              paths.push_back({best_distance,new_route});
              improve = true;
              goto start_again;
            }
          }
        } 
      }
       std::vector<std::vector<std::string>> temp1;
  for(unsigned int i=0;i<=paths.size()-1;i++)
  {
    temp1.push_back(paths[i].second);
  }
  results = {paths[paths.size()-1].first,temp1};
    auto time_stamp_stop = std::chrono::steady_clock::now(); 
    std::chrono::duration<double> duration_program = time_stamp_stop - time_stamp_start; 
    std::cout << "Time taken by function: "<< duration_program.count() << " seconds" << std::endl;
    
    return results;
} 
