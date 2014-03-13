//
//  string.hpp
//  mpp
//
//  Created by Michiro Hirai on 1/21/14.
//  Copyright (c) 2014 michiroooo. All rights reserved.
//

#ifndef MPP_STRING_HPP
#define MPP_STRING_HPP

#include <codecvt>

namespace mpp {

template<class Facet>
struct deletable_facet : Facet
{
    template<class ...Args>
    deletable_facet(Args&& ...args) : Facet(std::forward<Args>(args)...) {}
    ~deletable_facet() {}
};


template<typename CharT>
class string {
    const std::string str_;

public:
    string( const char * rhs)
    : str_(rhs)
    {}

    string( const std::string & rhs)
    : str_(rhs)
    {}

    std::basic_string<CharT> convert() const
    {
        std::wstring_convert<
        deletable_facet<std::codecvt<CharT, char, std::mbstate_t>>, CharT> conv;
        return conv.from_bytes(str_);
    }

    std::string get() const { return str_; }

};

typedef string<wchar_t> wstring;
typedef string<char16_t> u16string;
typedef string<char32_t> u32string;

}



#endif
