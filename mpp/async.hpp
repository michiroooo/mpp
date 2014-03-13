//
//  async.hpp
//  mpp
//
//  Created by Michiro Hirai on 2/26/14.
//  Copyright (c) 2014 michiroooo. All rights reserved.
//

#ifndef mpp_async_hpp
#define mpp_async_hpp

#include <iostream>
#include <future>
#include <chrono>
#include <functional>

namespace mpp { namespace async {

    class thread_worker
    {
        std::future<size_t> future_;
    public:
        static size_t asyncFunc( const std::string & message )
        {
            for( auto s : message ){
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cerr << s << " ";
            }
            std::cerr << std::flush;

            return message.size();
        }

        void perform(){

            future_ = std::async( std::launch::async, std::ref(asyncFunc), std::string("async-func") );

            std::cerr << "performEnd" << std::endl;
        }

        bool isWorking() const
        {
            auto status = future_.wait_for(std::chrono::milliseconds(0));
            return status != std::future_status::ready;
        }

        size_t result()
        {
            return future_.get();
        }
    };


} }


#endif
