Split
====

Split algorithms are an extension to the find iterator for one common usage scenario. These algorithms use a find iterator and store all matches into the provided container. This container must be able to hold copies (e.g. std::string) or references (e.g. iterator_range) of the extracted substrings.

Two algorithms are provided. find_all() finds all copies of a string in the input. split() splits the input into parts.

    string str1("hello abc-*-ABC-*-aBc goodbye");

    typedef vector< iterator_range<string::iterator> > find_vector_type;
    
    find_vector_type FindVec; // #1: Search for separators
    ifind_all( FindVec, str1, "abc" ); // FindVec == { [abc],[ABC],[aBc] }

    typedef vector< string > split_vector_type;
    
    split_vector_type SplitVec; // #2: Search for tokens
    split( SplitVec, str1, is_any_of("-*"), token_compress_on ); // SplitVec == { "hello abc","ABC","aBc goodbye" }
        

[hello] designates an iterator_range delimiting this substring.

First example show how to construct a container to hold references to all extracted substrings. Algorithm ifind_all() puts into FindVec references to all substrings that are in case-insensitive manner equal to "abc".

Second example uses split() to split string str1 into parts separated by characters '-' or '*'. These parts are then put into the SplitVec. It is possible to specify if adjacent separators are concatenated or not.

More information can be found in the reference: *boost/algorithm/string/split.hpp*.