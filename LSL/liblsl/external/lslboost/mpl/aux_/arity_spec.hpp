
#ifndef BOOST_MPL_AUX_ARITY_SPEC_HPP_INCLUDED
#define BOOST_MPL_AUX_ARITY_SPEC_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.lslboost.org/LICENSE_1_0.txt)
//
// See http://www.lslboost.org/libs/mpl for documentation.

// $Id: arity_spec.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <lslboost/mpl/int.hpp>
#include <lslboost/mpl/limits/arity.hpp>
#include <lslboost/mpl/aux_/config/dtp.hpp>
#include <lslboost/mpl/aux_/preprocessor/params.hpp>
#include <lslboost/mpl/aux_/arity.hpp>
#include <lslboost/mpl/aux_/template_arity_fwd.hpp>
#include <lslboost/mpl/aux_/config/ttp.hpp>
#include <lslboost/mpl/aux_/config/lambda.hpp>
#include <lslboost/mpl/aux_/config/static_constant.hpp>

#if defined(BOOST_MPL_CFG_BROKEN_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#   define BOOST_MPL_AUX_NONTYPE_ARITY_SPEC(i,type,name) \
namespace aux { \
template< BOOST_MPL_AUX_NTTP_DECL(int, N), BOOST_MPL_PP_PARAMS(i,type T) > \
struct arity< \
      name< BOOST_MPL_PP_PARAMS(i,T) > \
    , N \
    > \
{ \
    BOOST_STATIC_CONSTANT(int \
        , value = BOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        ); \
}; \
} \
/**/
#else
#   define BOOST_MPL_AUX_NONTYPE_ARITY_SPEC(i,type,name) /**/
#endif

#   define BOOST_MPL_AUX_ARITY_SPEC(i,name) \
    BOOST_MPL_AUX_NONTYPE_ARITY_SPEC(i,typename,name) \
/**/


#if defined(BOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING) \
    && !defined(BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)
#   define BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(i, name) \
namespace aux { \
template< BOOST_MPL_PP_PARAMS(i,typename T) > \
struct template_arity< name<BOOST_MPL_PP_PARAMS(i,T)> > \
    : int_<i> \
{ \
}; \
} \
/**/
#else
#   define BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(i, name) /**/
#endif


#endif // BOOST_MPL_AUX_ARITY_SPEC_HPP_INCLUDED
