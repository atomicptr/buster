#pragma once

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

namespace buster {
    namespace internal {
        inline void print_pass(std::string file, int line) {
            std::cout << "\t\033[32mPASS\033[0m\t" << file << ":" << line << std::endl;
        }

        inline void print_fail(std::string file, int line, std::string reason) {
            std::cout << "\t\033[1;31mFAIL\033[0m\t" << file << ":" << line << "\t" << reason << std::endl;
            std::abort();
        }

        template<typename T>
        inline bool is_equal(T a, T b) {
            return a == b;
        }

        template<>
        inline bool is_equal(float a, float b) {
            return std::abs(a - b) < 0.000001f;
        }

        template<typename T>
        inline void test_equals(T expected, T actual, std::string file, int line) {
            if (is_equal(expected, actual)) {
                print_pass(file, line);
                return;
            }

            std::stringstream ss;
            ss << "Expected " << actual << " to be " << actual;
            print_fail(file, line, ss.str());
        }

        inline void test_true(bool value, std::string file, int line) {
            if (value) {
                print_pass(file, line);
                return;
            }

            std::stringstream ss;
            ss << "Expected value to be true";
            print_fail(file, line, ss.str());
        }

        inline void test_false(bool value, std::string file, int line) {
            if (!value) {
                print_pass(file, line);
                return;
            }
            
            std::stringstream ss;
            ss << "Expected value to be false";
            print_fail(file, line, ss.str());
        }
    }
}

#define expect_equals(expected, actual) buster::internal::test_equals((expected), (actual), __FILE__, __LINE__)

#define expect_true(value) buster::internal::test_true((value), __FILE__, __LINE__)

#define expect_false(value) buster::internal::test_false((value), __FILE__, __LINE__)