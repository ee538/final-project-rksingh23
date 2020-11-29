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

