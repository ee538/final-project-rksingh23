#include "src/lib/trojanmap.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

TEST(TrojanMapTest, Test1) {
  EXPECT_EQ(true, true);
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





////////////////////////////////////////////////////////// WARNiNG -RUN THIS GTEST INDIVIDUALLY - COMMENT OUT ALL OTHER TESTS ////////////////////////////////////////////

// GTEST WORKS FOR ONLY INE ROUTE

/*

TEST(TrojanMapTest, CalculateShortestPath_Bellman) {
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
