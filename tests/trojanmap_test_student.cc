#include "src/lib/trojanmap.h"

#include <map>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

TEST(TrojanMapTest, Test1) {
  EXPECT_EQ(true, true);
}

//Rohit's Test Cases

TEST(TrojanMapTest, GetNeighborsID_rohit){
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::string empty;
  auto Neighbor = m.GetNeighborIDs(empty);         //Unique id: Student Union STU
  std::vector<std::string> empty_expected;
  EXPECT_EQ(Neighbor, empty_expected);

  empty="Rohit";
  Neighbor = m.GetNeighborIDs(empty);         //Unique id: Student Union STU
  EXPECT_EQ(Neighbor, empty_expected);
}

TEST(TrojanMapTest, GetName_rohit){
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::string empty;
  auto name = m.GetName(empty);         //Unique id: Student Union STU
  std::string empty_expected;
  EXPECT_EQ(name, empty_expected);

  empty="Rohit";
  name = m.GetName(empty);         //Unique id: Student Union STU
  EXPECT_EQ(name, empty_expected);

  std::string id="5229911615";
  name = m.GetName(id);         //Unique id: Student Union STU
  std::string expected ="Student Union STU";
  EXPECT_EQ(name, expected);
}



TEST(TrojanMap, GetLat_rohit) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  double Lat = m.GetLat("Rohit");  
  EXPECT_EQ(Lat, 0);

  std::string empty;
  Lat = m.GetLat(empty);  
  EXPECT_EQ(Lat, 0);
}

TEST(TrojanMap, GetPathLength_rohit) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> empty;
  double len = m.CalculatePathLength(empty);  
  EXPECT_EQ(len, 0);
}


TEST(TrojanMap, GetLon_rohit) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  double Lon = m.GetLon("Rohit");  
  EXPECT_EQ(Lon, 0);

  std::string empty;
  Lon = m.GetLon(empty);  
  EXPECT_EQ(Lon, 0);
}



TEST(TrojanMapTest, Autocomplete_corner_case_rohit1) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  // Test the simple case
  auto actual = m.Autocomplete("Rohit");
  std::vector<std::string> expected; // groundtruth for "Ch"
  EXPECT_EQ(actual, expected);
  // Test the lower case
  std::string empty;
  actual = m.Autocomplete(empty);
  EXPECT_EQ(actual, expected);
}

TEST(TrojanMapTest, GetID_corner_case_rohit1) {
  TrojanMap m;
  std::string empty;
  m.CreateGraphFromCSVFile();
  // Test the simple case
  auto actual = m.GetId("Rohit");
  EXPECT_EQ(actual, empty);
  // Test the lower case
  
  actual = m.GetId(empty);
  EXPECT_EQ(actual, empty);
}

TEST(TrojanMapTest, Autocomplete_corner_case_rohit2) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  // Test the simple case
  auto actual = m.Autocomplete_Anywhere("Rohit");
  std::vector<std::string> expected; // groundtruth for "Ch"
  EXPECT_EQ(actual, expected);
  // Test the lower case
  std::string empty;
  actual = m.Autocomplete_Anywhere(empty);
  EXPECT_EQ(actual, expected);
}

TEST(TrojanMapTest, Find_position_corner_case_rohit1) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  // Test ChickfilA
  auto actual = m.GetPosition("Rohit");
  std::pair<double, double> expected; // groundtruth for "ChickfilA"
  EXPECT_EQ(actual, expected);
  // Test Ralphs
  std::string empty;
  actual = m.GetPosition(empty);
  EXPECT_EQ(actual, expected);
}

TEST(TrojanMapTest, CalculateShortestPath_corner_case_rohit1) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::string empty1;
  std::string empty2;

  // Test from Ralphs to ChickfilA
  auto actual = m.CalculateShortestPath(empty1,empty2);
  std::vector<std::string> empty;
  // Print the path lengths
  EXPECT_EQ(actual, empty);
}


TEST(TrojanMapTest, CalculateShortestPath_corner_case_rohit2) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> empty;
  
  // Reverse the input from Ralphs to ChickfilA
  auto actual = m.CalculateShortestPath("ChickA", "Ralphs");
  EXPECT_EQ(actual, empty);
}

TEST(TrojanMapTest, CalculateShortestPath_corner_case_rohit3) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> empty;
  auto actual = m.CalculateShortestPath("ChickA", "Home");
  EXPECT_EQ(actual, empty); 
}


////////////////////////////////////// BELLAM FORD CORNER CASES ////////////////////////////

TEST(TrojanMapTest, CalculateShortestPath_corner_case_Bellman_rohit1) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::string empty1;
  std::string empty2;

  // Test from Ralphs to ChickfilA
  auto actual = m.CalculateShortestPath_Bellman(empty1,empty2);
  std::vector<std::string> empty;
  // Print the path lengths
  EXPECT_EQ(actual, empty);
}


TEST(TrojanMapTest, CalculateShortestPath_corner_case_Bellman_rohit2) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> empty;
  
  // Reverse the input from Ralphs to ChickfilA
  auto actual = m.CalculateShortestPath_Bellman("ChickA", "Ralphs");
  EXPECT_EQ(actual, empty);
}

TEST(TrojanMapTest, CalculateShortestPath_corner_case_Bellman_rohit3) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> empty;
  auto actual = m.CalculateShortestPath_Bellman("ChickA", "Home");
  EXPECT_EQ(actual, empty); 
}

TEST(TrojanMapTest, CalculateShortestPath_corner_case_Travelling_Trojan_brute_rohit1) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> empty;
  std::pair<double, std::vector<std::vector<std::string>>> expeced_empty;
  auto actual = m.TravellingTrojan(empty);
  EXPECT_EQ(actual, expeced_empty); 
}

TEST(TrojanMapTest, CalculateShortestPath_corner_case_Travelling_Trojan_2_opt_rohit1) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> empty;
  std::pair<double, std::vector<std::vector<std::string>>> expeced_empty;
  auto actual = m.TravellingTrojan_2opt(empty);
  EXPECT_EQ(actual, expeced_empty); 
}





////////////////////////////////////////////////////////// WARNiNG -RUN THIS GTEST INDIVIDUALLY - COMMENT OUT ALL OTHER TESTS ////////////////////////////////////////////

// GTEST WORKS FOR ONLY INE ROUTE

/*

TEST(TrojanMapTest, CalculateShortestPath_Bellman_rohit) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();

  // Test from Ralphs to ChickfilA
  auto path = m.CalculateShortestPath_Bellman("Ralphs", "ChickfilA");
  std::vector<std::string> gt{
      "2578244375", "5559640911", "6787470571", "6808093910", "6808093913", "6808093919", "6816831441",
      "6813405269", "6816193784", "6389467806", "6816193783", "123178876", "2613117895", "122719259",
      "2613117861", "6817230316", "3642819026", "6817230310", "7811699597", "5565967545", "123318572",
      "6813405206", "6813379482", "544672028", "21306059", "6813379476", "6818390140", "63068610", 
      "6818390143", "7434941012", "4015423966", "5690152766", "6813379440", "6813379466", "21306060",
      "6813379469", "6813379427", "123005255", "6807200376", "6807200380", "6813379451", "6813379463",
      "123327639", "6813379460", "4141790922", "4015423963", "1286136447", "1286136422", "4015423962",
      "6813379494", "63068643", "6813379496", "123241977", "4015372479", "4015372477", "1732243576",
      "6813379548", "4015372476", "4015372474", "4015372468", "4015372463", "6819179749", "1732243544",
      "6813405275", "348121996", "348121864", "6813405280", "1472141024", "6813411590", "216155217", 
      "6813411589", "1837212103", "1837212101", "6820935911", "4547476733"}; // Expected path
  // Print the path lengths

  std::cout << "My path length: "  << m.CalculatePathLength(path) << "miles" << std::endl;
  std::cout << "GT path length: " << m.CalculatePathLength(gt) << "miles" << std::endl;
  EXPECT_EQ(path, gt);

}

*/






//Kunal's Test Cases

//Test GetPosition Function
TEST(TrojanMapTest, FindPosition_kunal) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  // Test Case sensitivity
  auto position = m.GetPosition("CHICKFILA");
  std::pair<double, double> gt1; // groundtruth for "ChickfilA"
  EXPECT_EQ(position, gt1);
  // Test spacing bewteen the name
  position = m.GetPosition("R alphs");
  std::pair<double, double> gt2; // groundtruth for "Ralphs"
  EXPECT_EQ(position, gt2);
    // Test Target
  position = m.GetPosition("Target");
  std::pair<double, double> gt4(34.0257016, -118.2843512); // groundtruth for "Target"
  EXPECT_EQ(position, gt4);
}

TEST(TrojanMapTest, GetNeighborsID_kunal){
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  auto Neighbor = m.GetNeighborIDs("5229911615");         //Unique id: Student Union STU
  std::vector<std::string> gt1 = {"5229911604", "6814620863"};
  EXPECT_EQ(Neighbor, gt1);
}

TEST(TrojanMap, GetLon_kunal) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  double Lon = m.GetLon("5567718696");    //Unique ID for: DULCE
  double gt1 =  -118.2854176;
  EXPECT_EQ(Lon, gt1);
}


TEST(TrojanMap, GetName_kunal) {
   TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::string name = m.GetName("5567718696");    //Unique ID for: DULCE
  std::string gt1 =  "Dulce";
  EXPECT_EQ(name, gt1);
}


TEST(TrojanMap, GetLat_kunal) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  double Lat = m.GetLat("5567718696");    //Unique ID for: DULCE
  double gt1 =  34.0253528;
  EXPECT_EQ(Lat, gt1);
}


//Test for Travelling Trojan - Brute Force Function
TEST(TrojanMapTest, TSP1_kunal) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> input{"1849116058", "6816305553", "269633656"}; // Input location ids 
  auto result = m.TravellingTrojan(input);
  std::cout << "My path length: "  << result.first << "miles" << std::endl; // Print the result path lengths
  std::vector<std::string> gt{"1849116058", "6816305553", "269633656", "1849116058"}; // Expected order
  std::cout << "GT path length: "  << m.CalculatePathLength(gt) << "miles" << std::endl; // Print the gt path lengths
  bool flag = false;
  if (gt == result.second[result.second.size()-1]) // clockwise
    flag = true;
  std::reverse(gt.begin(),gt.end()); // Reverse the expected order because the counterclockwise result is also correct
  if (gt == result.second[result.second.size()-1]) 
    flag = true;
  
  EXPECT_EQ(flag, true);
}
//The below test will give result as false as we are delibrately changing the path in "gt"
TEST(TrojanMapTest, TSP2_kunal) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> input{"1849116058", "6816305553", "269633656"}; // Input location ids 
  auto result = m.TravellingTrojan(input);
  std::cout << "My path length: "  << result.first << "miles" << std::endl; // Print the result path lengths
  std::vector<std::string> gt{"1849116058", "6813416142", "6816305553", "1849116058"}; // It will fail as we are delibrately providing different path
  std::cout << "GT path length: "  << m.CalculatePathLength(gt) << "miles" << std::endl; // Print the gt path lengths
  bool flag = false;
  if (gt == result.second[result.second.size()-1]) // clockwise
    flag = true;
  std::reverse(gt.begin(),gt.end()); // Reverse the expected order because the counterclockwise result is also correct
  if (gt == result.second[result.second.size()-1]) 
    flag = true;
  
  EXPECT_EQ(flag, false);
}

TEST(TrojanMapTest, TSP3_kunal) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> input{"7071968735", "6807274422", "544348508", "1849116067", "6818390153", "6813416142", "6817275189", "7477898578", "1378231753", "6788057222"}; // Input location ids 
  auto result = m.TravellingTrojan(input);
  std::cout << "My path length: "  << result.first << "miles" << std::endl; // Print the result path lengths
  std::vector<std::string> gt{"7071968735", "544348508", "1378231753", "6788057222", "1849116067", "6813416142", "6818390153", "7477898578", "6807274422", "6817275189", "7071968735"}; // Expected order
  std::cout << "GT path length: "  << m.CalculatePathLength(gt) << "miles" << std::endl; // Print the gt path lengths
  bool flag = false;
  if (gt == result.second[result.second.size()-1]) // clockwise
    flag = true;
  std::reverse(gt.begin(),gt.end()); // Reverse the expected order because the counterclockwise result is also correct
  if (gt == result.second[result.second.size()-1]) 
    flag = true;
  
  EXPECT_EQ(flag, true);
}

TEST(TrojanMapTest, TSP4_kunal) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> input{"6815813018", "123182692", "4399914025", "6820972453", "2613117902", "5768963647"}; // Input location ids 
  auto result = m.TravellingTrojan(input);
  std::cout << "My path length: "  << result.first << "miles" << std::endl; // Print the result path lengths
  std::vector<std::string> gt{"6815813018", "4399914025", "2613117902", "123182692", "5768963647", "6820972453", "6815813018"}; // Expected order
  std::cout << "GT path length: "  << m.CalculatePathLength(gt) << "miles" << std::endl; // Print the gt path lengths
  bool flag = false;
  if (gt == result.second[result.second.size()-1]) // clockwise
    flag = true;
  std::reverse(gt.begin(),gt.end()); // Reverse the expected order because the counterclockwise result is also correct
  if (gt == result.second[result.second.size()-1]) 
    flag = true;
  
  EXPECT_EQ(flag, true);
}

//Test for Travelling Trojan - Two_Opt Function
TEST(TrojanMapTest, TSP1_two_opt) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> input{"1849116058", "6816305553", "269633656"}; // Input location ids 
  auto result = m.TravellingTrojan_2opt(input);
  std::cout << "My path length: "  << result.first << "miles" << std::endl; // Print the result path lengths
  std::vector<std::string> gt{"1849116058", "6816305553", "269633656", "1849116058"}; // Expected order
  std::cout << "GT path length: "  << m.CalculatePathLength(gt) << "miles" << std::endl; // Print the gt path lengths
  bool flag = false;
  if (gt == result.second[result.second.size()-1]) // clockwise
    flag = true;
  std::reverse(gt.begin(),gt.end()); // Reverse the expected order because the counterclockwise result is also correct
  if (gt == result.second[result.second.size()-1]) 
    flag = true;
  
  EXPECT_EQ(flag, true);
}
//The below test will give result as false as we are delibrately changing the path in "gt"
TEST(TrojanMapTest, TSP2_two_opt) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> input{"1849116058", "6816305553", "269633656"}; // Input location ids 
  auto result = m.TravellingTrojan_2opt(input);
  std::cout << "My path length: "  << result.first << "miles" << std::endl; // Print the result path lengths
  std::vector<std::string> gt{"1849116058", "6813416142", "6816305553", "1849116058"}; // It will fail as we are delibrately providing different path
  std::cout << "GT path length: "  << m.CalculatePathLength(gt) << "miles" << std::endl; // Print the gt path lengths
  bool flag = false;
  if (gt == result.second[result.second.size()-1]) // clockwise
    flag = true;
  std::reverse(gt.begin(),gt.end()); // Reverse the expected order because the counterclockwise result is also correct
  if (gt == result.second[result.second.size()-1]) 
    flag = true;
  
  EXPECT_EQ(flag, false);
}

TEST(TrojanMapTest, TSP3_two_opt) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> input{"7071968735", "6807274422", "544348508", "1849116067", "6818390153", "6813416142", "6817275189", "7477898578", "1378231753", "6788057222"}; // Input location ids 
  auto result = m.TravellingTrojan_2opt(input);
  std::cout << "My path length: "  << result.first << "miles" << std::endl; // Print the result path lengths
  std::vector<std::string> gt{"7071968735", "544348508", "1378231753", "6788057222", "1849116067", "6813416142", "6818390153", "7477898578", "6807274422", "6817275189", "7071968735"}; // Expected order
  std::cout << "GT path length: "  << m.CalculatePathLength(gt) << "miles" << std::endl; // Print the gt path lengths
  bool flag = false;
  if (gt == result.second[result.second.size()-1]) // clockwise
    flag = true;
  std::reverse(gt.begin(),gt.end()); // Reverse the expected order because the counterclockwise result is also correct
  if (gt == result.second[result.second.size()-1]) 
    flag = true;
  
  EXPECT_EQ(flag, true);
}

TEST(TrojanMapTest, TSP4_two_opt) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  std::vector<std::string> input{"6815813018", "123182692", "4399914025", "6820972453", "2613117902", "5768963647"}; // Input location ids 
  auto result = m.TravellingTrojan_2opt(input);
  std::cout << "My path length: "  << result.first << "miles" << std::endl; // Print the result path lengths
  std::vector<std::string> gt{"6815813018", "4399914025", "2613117902", "123182692", "5768963647", "6820972453", "6815813018"}; // Expected order
  std::cout << "GT path length: "  << m.CalculatePathLength(gt) << "miles" << std::endl; // Print the gt path lengths
  bool flag = false;
  if (gt == result.second[result.second.size()-1]) // clockwise
    flag = true;
  std::reverse(gt.begin(),gt.end()); // Reverse the expected order because the counterclockwise result is also correct
  if (gt == result.second[result.second.size()-1]) 
    flag = true;
  
  EXPECT_EQ(flag, true);
}
