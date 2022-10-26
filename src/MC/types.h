#pragma once

//
// Created by Admin on 2022/10/25.
//

#ifndef GGXX_TYPES_H
#define GGXX_TYPES_H

#endif //GGXX_TYPES_H

class ClientBlockPipeline
{
public:
    template <typename T>
    class VolumeOf;

    struct BlockSchematic;
};

struct ISurfaceBuilder
{
    struct BuildParameters;
};

struct FeatureLoading
{
    template <typename T>
    struct ConcreteFeatureHolder;
    struct FeatureRootParseContext;
    template <typename T>
    struct ConcreteFeatureHolder;
};

template <typename T1, typename T2>
class OperationNode;

struct OperationNodeDetails
{
    template <typename T1, typename T2>
    class WorkingData;
};

struct PositionTrackingDB
{
    class TrackingRecord;
    class PositionTrackingDBServer;
    class PositionTrackingDBClient;
};


struct SubChunkBrightnessStorage
{
    struct LightPair;
};

struct BlockGeometry
{
    struct Model;

    class TessellatedModel;
};

struct CanyonFeatureUtils
{
    struct CanyonConfiguration;
};

class IInPackagePacks
{
public:
    struct MetaData;
};

struct GameEventConfig
{
    enum GameEvents;
};

struct OperationNodeValues
{
    enum Terrain;
};

struct SubChunkStorageUnit
{
    enum PruneType;
};

//Templates
template <typename T, typename T2, int unk>
class TypedServerNetId
{
public:
    T2 netId;
    inline operator T2()
    {
        return netId;
    }
};

template <typename T, typename T2, int unk>
class TypedClientNetId
{
public:
    T2 netId;
};

template <typename T, typename T2, int unk>
class TypedRuntimeId
{
public:
    T2 netId;
};

template <typename T, typename T2>
class AutomaticID;

template<typename T, typename T2>
class BidirectionalUnorderedMap {
public:
    std::unordered_map<T, T2> mMap1;
    std::unordered_map<T2, T> mMap2;
};

template <typename T>
class BlockDataFetchResult;

template <typename T>
class CommandSelectorResults;

template <typename... T>
class Factory;

template <typename T>
class InheritanceTree;

//enum class ItemStackRequestActionType : char;
//template <typename T, ItemStackRequestActionType actionType>
//class ItemStackRequestActionCraft;

template <typename T>
class ItemStateVariant;

template <typename T>
class LevelChunkGridAreaElement;

template <typename T>
class GridArea;

template <typename T>
class OwnerPtrT;

template <typename T>
class ServiceReference;

template <typename T>
class SharedPtr;

template <typename T>
class StackRefResultT;

template<typename T>
class WeakPtr {
    T** value;
public:
    inline T* get()
    {
        if (value)
            return *value;
        return nullptr;
    }
    inline T const* get() const
    {
        if (value)
            return *value;
        return nullptr;
    }
    inline T& operator*()
    {
        return *get();
    }
    inline T const& operator*() const
    {
        return *get();
    }
    inline operator bool() const
    {
        return get() != nullptr;
    }
};

template <typename T>
class WeakRefT;

template <typename T>
struct SharePtrRefTraits;

template <typename T>
class SubChunkStorage;

template <typename T, typename T2>
class TagRegistry;

template <typename T>
struct IDType;

template <typename T>
class ToFloatFunction;

template <typename T>
class TypedScreenCapabilities;

template <typename T, typename T2, typename T3, typename T4 = class UNK>
class ViewedEntityContextT;

template <typename T>
class FlagComponent;

template <typename T>
class WeightedChoices;

template <typename T>
class buffer_span;

template <typename T>
class buffer_span_mut;

template <typename T>
class optional_ref
{
    T** value;

public:
    inline T* get() const
    {
        if (value && *value)
            return *value;
        return nullptr;
    }
    //inline T* set(T const& val)
    //{
    //    *value = &val;
    //}
    inline T& operator*() const
    {
        return **value;
    }
    inline T* operator->() const
    {
        return *value;
    }
};

template <int a>
class DividedPos2d;

//template <typename T>
//struct GameplayHandlerResult;

template <typename T>
struct GameplayHandlerResult;

template <int T>
class ItemStackRequestActionDataless;

template <typename T>
class OperationGraphResult;

template <typename T1>
class SmallSet;

template <typename T1>
struct TaskStartInfoEx;

template <typename T1>
class WildcardCommandSelector;
