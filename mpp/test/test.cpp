//=======================================================================================
/*!
 * \file test.cpp
 *
 * \defgroup mpp
 *
 * \brief 
 * Created by Michiro Hirai on 1/6/14.
 *
 */
//   Copyright (c) 2014 michiroooo. All rights reserved.:
//    (C) Copyright 2013 Sony. All rights reserved. Use of copyright notice is
//        precautionary and does imply publication.
//=======================================================================================


#include <memory>
#include <assert.h>

#include "async.hpp"
#include "chain.h"
#include "string.hpp"
#include "policy.hpp"

class math {

public:
    float ten(){ return 10.0f; }
    float squrare(float rhs){
        return rhs * rhs;
    }
    float prod(float rhs, float lhs){ return rhs * lhs; }
};


int main(int argc, char ** argv)
{
    mpp::async::thread_worker worker;
    worker.perform();

    while (worker.isWorking()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cerr << "."  << std::flush;
    }

    auto result = worker.result();

    typedef mpp::policy::operation<mpp::policy::HelloWorldOp> defaultOp;

    defaultOp op;

    op.exec();

    mpp::wstring utf8("がんばるとびうお");

    auto w = utf8.convert();

    std::cerr << utf8.get() << std::endl;
    std::wcerr << w << std::endl;

    assert( utf8.get().length() == w.length() );

}

/*
int main(int argc, char ** argv)
{
    using std::placeholders::_1;
    using std::placeholders::_2;
    using mpp::func::chain;

    std::function<float()> cf;
    std::function<float()> ten = std::bind(&math::ten, math());
    cf = std::bind(&chain<float>, ten, cf);

    auto result = cf(); // execute
    std::cerr << result << std::endl;

    std::function<float(float)> chained;
    std::function<float(float)> square = std::bind(&math::squrare, math(), _1);

    chained = std::bind(&chain<float, float>, square, chained, _1);
    chained = std::bind(&chain<float, float>, square, chained, _1);

    result = chained(0.1); // execute
    std::cerr << result << std::endl;


    std::function<float(float, float)> chained_func;
    std::function<float(float, float)> prod = std::bind(&math::prod, math(), _1, _2);

    chained_func = std::bind(&chain<float, float, float>, prod, chained_func, _1, _2);
    chained_func = std::bind(&chain<float, float, float>, prod, chained_func, _1, _2);

    result = chained_func(0.1, 0.2); // execute

    std::cerr << result << std::endl;

    return 0;
}
*/