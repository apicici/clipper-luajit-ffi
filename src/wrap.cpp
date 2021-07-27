#include "clipper.hpp"

#if defined _WIN32 || defined __CYGWIN__
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((__visibility__("default")))
#endif

#define PREFIX(type, funcname) ClipperLib_ ## type ## _ ## funcname

#define WRAP_VECTOR(type, argtype) \
    EXPORT type* PREFIX(type, _new_default)() {return new type();}\
    EXPORT type* PREFIX(type, _new_fill)(size_t n, argtype& value) {return new type(n, value);}\
    EXPORT type* PREFIX(type, _new_fill_default)(size_t n) {return new type(n);}\
    EXPORT type* PREFIX(type, _new_copy)(const type& x) {return new type(x);}\
    EXPORT void PREFIX(type, _destroy)(type* p) {delete p;}\
    \
    EXPORT size_t PREFIX(type, size)(type* p) {return p->size();}\
    EXPORT size_t PREFIX(type, max_size)(type* p) {return p->max_size();}\
    EXPORT void PREFIX(type, resize)(type* p, size_t n, argtype& value) {p->resize(n, value);}\
    EXPORT void PREFIX(type, resize__default)(type* p, size_t n) {p->resize(n);}\
    EXPORT size_t PREFIX(type, capacity)(type* p) {return p->capacity();}\
    EXPORT bool PREFIX(type, empty)(type* p) {return p->empty();}\
    EXPORT void PREFIX(type, reserve)(type* p, size_t n) {p->reserve(n);}\
    \
    EXPORT argtype& PREFIX(type, at)(type* p, size_t n) {return p->at(n);}\
    EXPORT void PREFIX(type, _setitem)(type* p, size_t n, argtype v) {p->at(n) = v;}\
    EXPORT void PREFIX(type, _setitem_frompointer)(type* p, size_t n, argtype* v) {p->at(n) = *v;}\
    EXPORT argtype& PREFIX(type, front)(type* p) {return p->front();}\
    EXPORT argtype& PREFIX(type, back)(type* p) {return p->back();}\
    \
    EXPORT void PREFIX(type, assign)(type* p, size_t n, argtype& value) {p->assign(n, value);}\
    EXPORT void PREFIX(type, push_back)(type* p, argtype& value) {p->push_back(value);}\
    EXPORT void PREFIX(type, pop_back)(type* p) {p->pop_back();}\
    EXPORT void PREFIX(type, swap)(type* p, type& q) {p->swap(q);}\
    EXPORT void PREFIX(type, clear)(type* p) {p->clear();}\

using namespace ClipperLib;

#ifdef __cplusplus
extern "C" {
#endif

// vectors
WRAP_VECTOR(Path, IntPoint)
WRAP_VECTOR(Paths, Path)
WRAP_VECTOR(PolyNodes, PolyNode*)

//classes
EXPORT PolyNode* PREFIX(PolyNode, _new)() {return new PolyNode();}
EXPORT void PREFIX(PolyNode, _destroy)(PolyNode* p) {delete p;}
EXPORT Path* PREFIX(PolyNode, Contour__get)(PolyNode* p) {return &(p->Contour);}
EXPORT PolyNodes* PREFIX(PolyNode, Childs__get)(PolyNode* p) {return &(p->Childs);}
EXPORT PolyNode* PREFIX(PolyNode, Parent__get)(PolyNode* p) {return p->Parent;}
EXPORT PolyNode* PREFIX(PolyNode, GetNext)(PolyNode* p) {return p->GetNext();}
EXPORT bool PREFIX(PolyNode, IsHole)(PolyNode* p) {return p->IsHole();}
EXPORT bool PREFIX(PolyNode, IsOpen)(PolyNode* p) {return p->IsOpen();}
EXPORT int PREFIX(PolyNode, ChildCount)(PolyNode* p) {return p->ChildCount();}

EXPORT PolyTree* PREFIX(PolyTree, _new)() {return new PolyTree();}
EXPORT void PREFIX(PolyTree, _destroy)(PolyTree* p) {delete p;}
EXPORT Path* PREFIX(PolyTree, Contour__get)(PolyTree* p) {return &(p->Contour);}
EXPORT PolyNodes* PREFIX(PolyTree, Childs__get)(PolyTree* p) {return &(p->Childs);}
EXPORT PolyNode* PREFIX(PolyTree, Parent__get)(PolyTree* p) {return p->Parent;}
EXPORT PolyNode* PREFIX(PolyTree, GetNext)(PolyTree* p) {return p->GetNext();}
EXPORT bool PREFIX(PolyTree, IsHole)(PolyTree* p) {return p->IsHole();}
EXPORT bool PREFIX(PolyTree, IsOpen)(PolyTree* p) {return p->IsOpen();}
EXPORT int PREFIX(PolyTree, ChildCount)(PolyTree* p) {return p->ChildCount();}
EXPORT PolyNode* PREFIX(PolyTree, GetFirst)(PolyTree* p) {return p->GetFirst();}
EXPORT void PREFIX(PolyTree, Clear)(PolyTree* p) {return p->Clear();}
EXPORT int PREFIX(PolyTree, Total)(PolyTree* p) {return p->Total();}

EXPORT Clipper* PREFIX(Clipper, _new)(int initOptions) {return new Clipper(initOptions);}
EXPORT Clipper* PREFIX(Clipper, _new_default)() {return new Clipper();}
EXPORT void PREFIX(Clipper, _destroy)(Clipper* p) {delete p;}
EXPORT bool PREFIX(Clipper, AddPath)(Clipper* p, const Path &pg, PolyType PolyTyp, bool Closed) {
    return p->AddPath(pg, PolyTyp, Closed);
}
EXPORT bool PREFIX(Clipper, AddPaths)(Clipper* p, const Paths &ppg, PolyType PolyTyp, bool Closed) {
    return p->AddPaths(ppg, PolyTyp, Closed);
}
EXPORT void PREFIX(Clipper, Clear)(Clipper* p) {p->Clear();}
EXPORT IntRect PREFIX(Clipper, GetBounds)(Clipper* p) {return p->GetBounds();}
EXPORT bool PREFIX(Clipper, PreserveCollinear__get)(Clipper* p) {return p->PreserveCollinear();}
EXPORT void PREFIX(Clipper, PreserveCollinear__set)(Clipper* p, bool v) {p->PreserveCollinear(v);}
EXPORT bool PREFIX(Clipper, Execute__Paths)(Clipper* p,
                                            ClipType clipType,
                                            Paths& solution,
                                            PolyFillType subjFillType,
                                            PolyFillType clipFillType) {
    return p->Execute(clipType, solution, subjFillType, clipFillType);
}
EXPORT bool PREFIX(Clipper, Execute__PolyTree)(Clipper* p,
                                               ClipType clipType,
                                               PolyTree& solution,
                                               PolyFillType subjFillType,
                                               PolyFillType clipFillType) {
    return p->Execute(clipType, solution, subjFillType, clipFillType);
}
EXPORT bool PREFIX(Clipper, ReverseSolution__get)(Clipper* p) {return p->ReverseSolution();}
EXPORT void PREFIX(Clipper, ReverseSolution__set)(Clipper* p, bool v) {p->ReverseSolution(v);}
EXPORT bool PREFIX(Clipper, StrictlySimple__get)(Clipper* p) {return p->StrictlySimple();}
EXPORT void PREFIX(Clipper, StrictlySimple__set)(Clipper* p, bool v) {p->StrictlySimple(v);}

EXPORT ClipperOffset* PREFIX(ClipperOffset, _new)(double miterLimit, double roundPrecision) {
    return new ClipperOffset(miterLimit, roundPrecision);
}
EXPORT void PREFIX(ClipperOffset, _destroy)(ClipperOffset* p) {delete p;}
EXPORT void PREFIX(ClipperOffset, AddPath)(ClipperOffset* p, const Path& path, JoinType joinType, EndType endType) {
    p->AddPath(path, joinType, endType);
}
EXPORT void PREFIX(ClipperOffset, AddPaths)(ClipperOffset* p, const Paths& paths, JoinType joinType, EndType endType) {
    p->AddPaths(paths, joinType, endType);
}
EXPORT void PREFIX(ClipperOffset, Execute__Paths)(ClipperOffset* p, Paths& solution, double delta) {
    return p->Execute(solution, delta);
}
EXPORT void PREFIX(ClipperOffset, Execute__PolyTree)(ClipperOffset* p, PolyTree& solution, double delta) {
    return p->Execute(solution, delta);
}
EXPORT void PREFIX(ClipperOffset, Clear)(ClipperOffset* p) {return p->Clear();}
EXPORT double PREFIX(ClipperOffset, MiterLimit__get)(ClipperOffset* p) {return p->MiterLimit;}
EXPORT void PREFIX(ClipperOffset, MiterLimit__set)(ClipperOffset* p, double v) {p->MiterLimit = v;}
EXPORT double PREFIX(ClipperOffset, ArcTolerance__get)(ClipperOffset* p) {return p->ArcTolerance;}
EXPORT void PREFIX(ClipperOffset, ArcTolerance__set)(ClipperOffset* p, double v) {p->ArcTolerance = v;}

// functions
EXPORT bool ClipperLib_Orientation(const Path& poly) {return Orientation(poly);}
EXPORT double ClipperLib_Area(const Path& poly) {return Area(poly);}
EXPORT int ClipperLib_PointInPolygon(const IntPoint& pt, const Path& path) {return PointInPolygon(pt, path);}
EXPORT void ClipperLib_SimplifyPolygon(const Path& in_poly, Paths& out_polys, PolyFillType fillType) {
    SimplifyPolygon(in_poly, out_polys, fillType);
}
EXPORT void ClipperLib_SimplifyPolygons__inout(const Paths& in_polys, Paths& out_polys, PolyFillType fillType) {
    SimplifyPolygons(in_polys, out_polys, fillType);
}
EXPORT void ClipperLib_SimplifyPolygons__single(Paths& polys, PolyFillType fillType) {
    SimplifyPolygons(polys, fillType);
}
EXPORT void ClipperLib_CleanPolygon__inout(const Path& in_poly, Path& out_poly, double distance) {
    CleanPolygon(in_poly, out_poly, distance);
}
EXPORT void ClipperLib_CleanPolygon__single(Path& poly, double distance) {
    CleanPolygon(poly, distance);
}
EXPORT void ClipperLib_CleanPolygons__inout(const Paths& in_polys, Paths& out_polys, double distance) {
    CleanPolygons(in_polys, out_polys, distance);
}
EXPORT void ClipperLib_CleanPolygons__single(Paths& polys, double distance) {
    CleanPolygons(polys, distance);
}
EXPORT void ClipperLib_MinkowskiSum__Path(const Path& pattern, const Paths& path, Paths& solution, bool pathIsClosed) {
    MinkowskiSum(pattern, path, solution, pathIsClosed);
}
EXPORT void ClipperLib_MinkowskiSum__Paths(const Path& pattern, const Path& paths, Paths& solution, bool pathIsClosed) {
    MinkowskiSum(pattern, paths, solution, pathIsClosed);
}
EXPORT void ClipperLib_MinkowskiDiff(const Path& poly1, const Path& poly2, Paths& solution) {
    MinkowskiDiff(poly1, poly2, solution);
}
EXPORT void ClipperLib_PolyTreeToPaths(const PolyTree& polytree, Paths& paths) {
    PolyTreeToPaths(polytree, paths);
}
EXPORT void ClipperLib_ClosedPathsFromPolyTree(const PolyTree& polytree, Paths& paths) {
    ClosedPathsFromPolyTree(polytree, paths);
}
EXPORT void ClipperLib_OpenPathsFromPolyTree(PolyTree& polytree, Paths& paths) {
    OpenPathsFromPolyTree(polytree, paths);
}
EXPORT void ClipperLib_ReversePath(Path& p) {
    ReversePath(p);
}
EXPORT void ClipperLib_ReversePaths(Paths& p) {
    ReversePaths(p);
}

#ifdef __cplusplus
}
#endif
