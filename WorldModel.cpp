// **********************************************************************
//
// Copyright (c) 2003-2011 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.4.2
//
// <auto-generated>
//
// Generated from file `WorldModel.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <WorldModel.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 304
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 2
#       error Ice patch level mismatch!
#   endif
#endif

void
RoboCompWorldModel::__writeStringDictionary(::IceInternal::BasicStream* __os, const ::RoboCompWorldModel::StringDictionary& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::RoboCompWorldModel::StringDictionary::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        __os->write(p->second);
    }
}

void
RoboCompWorldModel::__readStringDictionary(::IceInternal::BasicStream* __is, ::RoboCompWorldModel::StringDictionary& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::std::string, ::std::string> pair;
        __is->read(const_cast< ::std::string&>(pair.first));
        ::RoboCompWorldModel::StringDictionary::iterator __i = v.insert(v.end(), pair);
        __is->read(__i->second);
    }
}

void
RoboCompWorldModel::__write(::IceInternal::BasicStream* __os, ::RoboCompWorldModel::BehaviorResultType v)
{
    __os->write(static_cast< ::Ice::Byte>(v), 7);
}

void
RoboCompWorldModel::__read(::IceInternal::BasicStream* __is, ::RoboCompWorldModel::BehaviorResultType& v)
{
    ::Ice::Byte val;
    __is->read(val, 7);
    v = static_cast< ::RoboCompWorldModel::BehaviorResultType>(val);
}

void
RoboCompWorldModel::GualzruWorldNode::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(nodeType);
    __os->write(nodeIdentifier);
    ::RoboCompWorldModel::__writeStringDictionary(__os, attributes);
}

void
RoboCompWorldModel::GualzruWorldNode::__read(::IceInternal::BasicStream* __is)
{
    __is->read(nodeType);
    __is->read(nodeIdentifier);
    ::RoboCompWorldModel::__readStringDictionary(__is, attributes);
}

void
RoboCompWorldModel::__writeNodeSequence(::IceInternal::BasicStream* __os, const ::RoboCompWorldModel::GualzruWorldNode* begin, const ::RoboCompWorldModel::GualzruWorldNode* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
RoboCompWorldModel::__readNodeSequence(::IceInternal::BasicStream* __is, ::RoboCompWorldModel::NodeSequence& v)
{
    ::Ice::Int sz;
    __is->readAndCheckSeqSize(6, sz);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
    }
}

void
RoboCompWorldModel::GualzruWorldEdge::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(a);
    __os->write(b);
    __os->write(edgeType);
}

void
RoboCompWorldModel::GualzruWorldEdge::__read(::IceInternal::BasicStream* __is)
{
    __is->read(a);
    __is->read(b);
    __is->read(edgeType);
}

void
RoboCompWorldModel::__writeEdgeSequence(::IceInternal::BasicStream* __os, const ::RoboCompWorldModel::GualzruWorldEdge* begin, const ::RoboCompWorldModel::GualzruWorldEdge* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
RoboCompWorldModel::__readEdgeSequence(::IceInternal::BasicStream* __is, ::RoboCompWorldModel::EdgeSequence& v)
{
    ::Ice::Int sz;
    __is->readAndCheckSeqSize(9, sz);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
    }
}

void
RoboCompWorldModel::GualzruWorld::__write(::IceInternal::BasicStream* __os) const
{
    if(nodes.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        ::RoboCompWorldModel::__writeNodeSequence(__os, &nodes[0], &nodes[0] + nodes.size());
    }
    if(edges.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        ::RoboCompWorldModel::__writeEdgeSequence(__os, &edges[0], &edges[0] + edges.size());
    }
}

void
RoboCompWorldModel::GualzruWorld::__read(::IceInternal::BasicStream* __is)
{
    ::RoboCompWorldModel::__readNodeSequence(__is, nodes);
    ::RoboCompWorldModel::__readEdgeSequence(__is, edges);
}

void
RoboCompWorldModel::ModelEvent::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(sender);
    ::RoboCompWorldModel::__write(__os, why);
    backModel.__write(__os);
    newModel.__write(__os);
}

void
RoboCompWorldModel::ModelEvent::__read(::IceInternal::BasicStream* __is)
{
    __is->read(sender);
    ::RoboCompWorldModel::__read(__is, why);
    backModel.__read(__is);
    newModel.__read(__is);
}
