#include <iostream>
#include "tddFuncs.h"
#include "WordCount.h"

int main() {
    std::cout << "Running the tests on the WordCount file:" << std::endl;

    WordCount wc;

    ASSERT_EQUALS(0, wc.getTotalWords());
    ASSERT_EQUALS(0, wc.getNumUniqueWords());

    wc.incrWordCount("AaKaSH");
    wc.incrWordCount("aakash");

    ASSERT_EQUALS(2, wc.getTotalWords());
    ASSERT_EQUALS(1, wc.getNumUniqueWords());
    ASSERT_EQUALS(2, wc.getWordCount("AAKASH"));
    ASSERT_EQUALS(0, wc.incrWordCount(""));

    wc.incrWordCount("ramen-noodles");
    wc.incrWordCount("RAMEN-NOODLES");

    ASSERT_EQUALS(4, wc.getTotalWords());
    ASSERT_EQUALS(2, wc.getNumUniqueWords());
    ASSERT_EQUALS(2, wc.getWordCount("ramen-noodles"));

    wc.decrWordCount("aakash");

    ASSERT_EQUALS(3, wc.getTotalWords());
    ASSERT_EQUALS(2, wc.getNumUniqueWords());
    ASSERT_EQUALS(1, wc.getWordCount("aakash"));

    ASSERT_EQUALS(-1, wc.decrWordCount(""));
    ASSERT_EQUALS(-1, wc.decrWordCount("missing"));

    wc.decrWordCount("AaKaSH");

    ASSERT_EQUALS(0, wc.getWordCount("aakash"));

    ASSERT_EQUALS("monkeys", WordCount::makeValidWord("12mOnkEYs-$"));
    ASSERT_EQUALS("paive", WordCount::makeValidWord("Pa55ive"));
    ASSERT_EQUALS("don't", WordCount::makeValidWord("don't"));
    ASSERT_EQUALS("ramen-noodles", WordCount::makeValidWord("Ramen-noodles"));
    ASSERT_EQUALS("hay", WordCount::makeValidWord("hA99y"));
    ASSERT_EQUALS("potato-chip", WordCount::makeValidWord("$2p3O$TA2T4O-cH2Ip"));

    wc.incrWordCount("12mOnkEYs-$");
    wc.incrWordCount("monkeys");
    wc.incrWordCount("Pa55ive");
    wc.incrWordCount("paive");
    wc.incrWordCount("ramen-noodles");
    wc.incrWordCount("ramen-noodles");

    ASSERT_EQUALS(3, wc.getNumUniqueWords());
    ASSERT_EQUALS(2, wc.getWordCount("monkeys"));
    ASSERT_EQUALS(2, wc.getWordCount("paive"));
    ASSERT_EQUALS(4, wc.getWordCount("ramen-noodles"));

    ASSERT_EQUALS("", WordCount::makeValidWord(""));

    std::cout << "All tests done." << std::endl;
    return 0;
}