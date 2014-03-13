/*
 *  mpp.h
 *  mpp
 *
 *  Created by Michiro Hirai on 1/6/14.
 *  Copyright (c) 2014 michiroooo. All rights reserved.
 *
 */

#ifndef MPP_CHAIN_HPP
#define MPP_CHAIN_HPP

#include <iostream>
#include <functional>

namespace mpp { namespace func {

//    template<typename R>
//    auto chain(std::function<R()> func, std::function<R()> next) -> decltype(func() + next())
//    {
//        if (next)
//            return func() + next();
//        return func();
//    };
//
//    template<typename R, typename Arg>
//    R chain(std::function<R(Arg)> func, std::function<R(Arg)> next, Arg arg)
//    {
//        if (next)
//            return func(arg) + next(arg);
//        return func(arg);
//    };

    template<typename R, typename ...Args>
    auto chain(std::function<R(Args...)> func, std::function<R(Args...)> next, Args ... args) -> decltype(func(args...) + next(args...))
    {
        if (next) return func(args...) + next(args...);
        return func(args...);
    }

} }

#endif //MPP_CHAIN_HPP
