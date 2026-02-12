#include <iostream>
#include "tddFuncs.h"
#include "WordCount.h"

int main() {
    std::cout << "run failed tests:" << std::endl;

    ASSERT_EQUALS("s", WordCount::makeValidWord("$-s'-#"));
    ASSERT_EQUALS("", WordCount::makeValidWord("$$*-'-!"));

    WordCount wc2;

    wc2.incrWordCount("foO");
    wc2.incrWordCount("foo");
    wc2.incrWordCount("bAr");
    wc2.incrWordCount("BaR");
    wc2.incrWordCount("foo#bar");
    wc2.incrWordCount("foo_bar-");
    wc2.incrWordCount("'foo-bar-");

    ASSERT_EQUALS(0, wc2.incrWordCount("--$$--"));
    ASSERT_EQUALS(7, wc2.getTotalWords());
    ASSERT_EQUALS(4, wc2.getNumUniqueWords());

    WordCount wc3;

    wc3.incrWordCount("foo");
    wc3.incrWordCount("oof");
    wc3.incrWordCount("ofo");
    wc3.incrWordCount("isn't");

    ASSERT_EQUALS(2, wc3.incrWordCount("$#'isn't--"));

    wc3.incrWordCount("n'ist");

    ASSERT_EQUALS(5, wc3.getNumUniqueWords());
    ASSERT_EQUALS(2, wc3.getWordCount("isn't"));

    std::cout << "all tests run" << std::endl;
    return 0;
}
