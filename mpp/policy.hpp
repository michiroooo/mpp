//
//  policy.hpp
//  mpp
//
//  Created by Michiro Hirai on 2/19/14.
//  Copyright (c) 2014 michiroooo. All rights reserved.
//

#ifndef MPP_POLICY_HPP
#define MPP_POLICY_HPP

namespace mpp { namespace policy {

    class HelloWorldOp {
    public:
        void run()
        {
            std::cerr << " HELLO WORLD" << std::endl;
        }
    };

    class DefaultIO {
        void create(){
            std::cerr << " Create " << std::endl;
        }
    };

    class ErrorLogger {
    public:
        void handleError(const std::string & error)
        {
            std::cerr << error << std::endl;
        }

    };

    template<
        typename OperationPolicy,
//        typename SourcePolicy = DefaultIO,
//        typename TargetPolicy = DefaultIO,
        typename ErrorPolicy = ErrorLogger
    >
    class operation : private OperationPolicy, private ErrorPolicy
    {
        using OperationPolicy::run;
//        using SourcePolicy::create;
//        using TargetPolicy::create;
        using ErrorPolicy::handleError;

//        const ErrorPolicy m_error;
//        const OperationPolicy m_op;

    public:
        operation()
        : OperationPolicy()
        , ErrorPolicy()
        {

        }
//        void create(const OperationPolicy & o, const ErrorPolicy & e)
//        {
//            auto source = SourcePolicy::create( o, e );
//            auto target = TargetPolicy::create( o, e );
//        }

        void exec()
        {
            run();
            handleError("error was handled");
        }

    };

} }




#endif
