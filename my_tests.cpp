#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "helper.h"
#include "cFunctions.h"
#include <fstream>
#include <sstream>

TEST_CASE("Testing Rule of Five and Stud functionality", "[Stud]") {
    SECTION("Copy Constructor and Assignment") {
        Stud s1;
        s1.setVardas("Jonas");
        Stud s2(s1); // Copy constructor
        REQUIRE(s2 == s1);

        s1.setVardas("Tadas");
        REQUIRE(s2 != s1); // s2 should remain unchanged

        s2 = s1; // Copy assignment
        REQUIRE(s2 == s1);
    }

    SECTION("Move Constructor and Assignment") {
        Stud s1;
        s1.setVardas("Pranas");
        Stud s3 (std::move(s1)); // Move constructor
        REQUIRE(s1.getVardas() == ""); // s1 should be in a valid but unspecified state
        REQUIRE(s3.getVardas() == "Pranas");

        Stud s2;
        s2.setVardas("Tadas");
        s3 = std::move(s2); // Move assignment
        REQUIRE(s2.getVardas() == ""); // s2 should be in a valid but unspecified state
        REQUIRE(s3.getVardas() == "Tadas");
    }

    SECTION("File Input and Output") {
        Stud s4;
        s4.setVardas("John");
        s4.setPavarde("Doe");

        // Write to file
        std::ofstream ofile("test.txt");
        ofile << s4;
        ofile.close();

        // Read from file
        std::ifstream ifile("test.txt");
        Stud s5;
        ifile >> s5;
        ifile.close();

        REQUIRE(s5.getVardas() == "John");
        REQUIRE(s5.getPavarde() == "Doe");
    }
}



/*
TEST_CASE("QuickTest processes files correctly", "[QuickTest]") {
    std::string filename1 = "test_file1.txt";
    std::string filename2 = "test_file2.txt";

    // Create mock data for testing
    std::ofstream file1(filename1);
    file1 << "Jonas Jonaitis 8 9 10\n";
    file1.close();

    std::ofstream file2(filename2);
    file2 << "Petras Petraitis 6 7 8\n";
    file2.close();

    SECTION("QuickTest processes files using DataProccess3") {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 5; i++) {
            DataProccess3<std::vector<Stud>>(filename1, "vidurkis", 1);
            DataProccess3<std::vector<Stud>>(filename2, "vidurkis", 1);
        }
        std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - start;

        REQUIRE(duration.count() > 0.0); // Ensure the function executes
        std::cout << "Bendrai vector uztruko " << (duration / 5).count() << " sekundes.\n" << std::endl;
    }

    // Clean up test files
    std::remove(filename1.c_str());
    std::remove(filename2.c_str());
}
*/

TEST_CASE("Testing Stud getters and setters", "[Stud]") {
    Stud student;

    SECTION("Testing setVardas and getVardas") {
        student.setVardas("Jonas");
        REQUIRE(student.getVardas() == "Jonas");
    }

    SECTION("Testing setPavarde and getPavarde") {
        student.setPavarde("Jonaitis");
        REQUIRE(student.getPavarde() == "Jonaitis");
    }

    SECTION("Testing setEgz and getEgz") {
        student.setEgz(9);
        REQUIRE(student.getEgz() == 9);
    }

    SECTION("Testing setNdVector and getNdVector") {
        std::vector<int> grades = {8, 9, 10};
        student.setNdVector(grades);
        REQUIRE(student.getNdVector() == grades);
    }

    SECTION("Testing setNd and getNd") {
        int grades[] = {7, 8, 9};
        student.setNd(grades, 3);
        int* retrievedGrades = student.getNd();
        REQUIRE(retrievedGrades[0] == 7);
        REQUIRE(retrievedGrades[1] == 8);
        REQUIRE(retrievedGrades[2] == 9);
        REQUIRE(student.getNdCount() == 3);
    }

    SECTION("Testing setGalutinisVid and getGalutinisVid") {
        student.setGalutinisVid(8.5f);
        REQUIRE(student.getGalutinisVid() == Approx(8.5f));
    }

    SECTION("Testing setGalutinisMed and getGalutinisMed") {
        student.setGalutinisMed(9.0f);
        REQUIRE(student.getGalutinisMed() == Approx(9.0f));
    }

    SECTION("Testing clearNdVector and addNd") {
        student.addNd(8);
        student.addNd(9);
        REQUIRE(student.getNdVector() == std::vector<int>{8, 9});
        student.clearNdVector();
        REQUIRE(student.getNdVector().empty());
    }
}