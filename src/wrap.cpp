#include "clipper.hpp"

#define PREFIX(type, funcname) ClipperLib_ ## type ## _ ## funcname

#define WRAP_VECTOR(type, argtype) \
    type* PREFIX(type, _new_default)() {return new type();}\
    type* PREFIX(type, _new_fill)(size_t n, argtype& value) {return new type(n, value);}\
    type* PREFIX(type, _new_fill_default)(size_t n) {return new type(n);}\
    type* PREFIX(type, _new_copy)(const type& x) {return new type(x);}\
    void PREFIX(type, _destroy)(type* p) {delete p;}\
    \
    size_t PREFIX(type, size)(type* p) {return p->size();}\
    size_t PREFIX(type, max_size)(type* p) {return p->max_size();}\
    void PREFIX(type, resize)(type* p, size_t n, argtype& value) {p->resize(n, value);}\
    void PREFIX(type, resize__default)(type* p, size_t n) {p->resize(n);}\
    size_t PREFIX(type, capacity)(type* p) {return p->capacity();}\
    bool PREFIX(type, empty)(type* p) {return p->empty();}\
    void PREFIX(type, reserve)(type* p, size_t n) {p->reserve(n);}\
    \
    argtype& PREFIX(type, at)(type* p, size_t n) {return p->at(n);}\
    void PREFIX(type, _setitem)(type* p, size_t n, argtype v) {p->at(n) = v;}\
    void PREFIX(type, _setitem_frompointer)(type* p, size_t n, argtype* v) {p->at(n) = *v;}\
    argtype& PREFIX(type, front)(type* p) {return p->front();}\
    argtype& PREFIX(type, back)(type* p) {return p->back();}\
    \
    void PREFIX(type, assign)(type* p, size_t n, argtype& value) {p->assign(n, value);}\
    void PREFIX(type, push_back)(type* p, argtype& value) {p->push_back(value);}\
    void PREFIX(type, pop_back)(type* p) {p->pop_back();}\
    void PREFIX(type, swap)(type* p, type& q) {p->swap(q);}\
    void PREFIX(type, clear)(type* p) {p->clear();}\

using namespace ClipperLib;

#ifdef __cplusplus
extern "C" {
#endif

// vectors
WRAP_VECTOR(Path, IntPoint)
WRAP_VECTOR(Paths, Path)
WRAP_VECTOR(PolyNodes, PolyNode*)

//classes
PolyNode* PREFIX(PolyNode, _new)() {return new PolyNode();}
void PREFIX(PolyNode, _destroy)(PolyNode* p) {delete p;}
Path* PREFIX(PolyNode, Contour__get)(PolyNode* p) {return &(p->Contour);}
PolyNodes* PREFIX(PolyNode, Childs__get)(PolyNode* p) {return &(p->Childs);}
PolyNode* PREFIX(PolyNode, Parent__get)(PolyNode* p) {return p->Parent;}
PolyNode* PREFIX(PolyNode, GetNext)(PolyNode* p) {return p->GetNext();}
bool PREFIX(PolyNode, IsHole)(PolyNode* p) {return p->IsHole();}
bool PREFIX(PolyNode, IsOpen)(PolyNode* p) {return p->IsOpen();}
int PREFIX(PolyNode, ChildCount)(PolyNode* p) {return p->ChildCount();}

PolyTree* PREFIX(PolyTree, _new)() {return new PolyTree();}
void PREFIX(PolyTree, _destroy)(PolyTree* p) {delete p;}
Path* PREFIX(PolyTree, Contour__get)(PolyTree* p) {return &(p->Contour);}
PolyNodes* PREFIX(PolyTree, Childs__get)(PolyTree* p) {return &(p->Childs);}
PolyNode* PREFIX(PolyTree, Parent__get)(PolyTree* p) {return p->Parent;}
PolyNode* PREFIX(PolyTree, GetNext)(PolyTree* p) {return p->GetNext();}
bool PREFIX(PolyTree, IsHole)(PolyTree* p) {return p->IsHole();}
bool PREFIX(PolyTree, IsOpen)(PolyTree* p) {return p->IsOpen();}
int PREFIX(PolyTree, ChildCount)(PolyTree* p) {return p->ChildCount();}
PolyNode* PREFIX(PolyTree, GetFirst)(PolyTree* p) {return p->GetFirst();}
void PREFIX(PolyTree, Clear)(PolyTree* p) {return p->Clear();}
int PREFIX(PolyTree, Total)(PolyTree* p) {return p->Total();}

Clipper* PREFIX(Clipper, _new)(int initOptions) {return new Clipper(initOptions);}
Clipper* PREFIX(Clipper, _new_default)() {return new Clipper();}
void PREFIX(Clipper, _destroy)(Clipper* p) {delete p;}
bool PREFIX(Clipper, AddPath)(Clipper* p, const Path &pg, PolyType PolyTyp, bool Closed) {
    return p->AddPath(pg, PolyTyp, Closed);
}
bool PREFIX(Clipper, AddPaths)(Clipper* p, const Paths &ppg, PolyType PolyTyp, bool Closed) {
    return p->AddPaths(ppg, PolyTyp, Closed);
}
void PREFIX(Clipper, Clear)(Clipper* p) {p->Clear();}
IntRect PREFIX(Clipper, GetBounds)(Clipper* p) {return p->GetBounds();}
bool PREFIX(Clipper, PreserveCollinear__get)(Clipper* p) {return p->PreserveCollinear();}
void PREFIX(Clipper, PreserveCollinear__set)(Clipper* p, bool v) {p->PreserveCollinear(v);}
bool PREFIX(Clipper, Execute__Paths)(Clipper* p,
                                       ClipType clipType,
                                       Paths& solution,
                                       PolyFillType subjFillType,
                                       PolyFillType clipFillType) {
    return p->Execute(clipType, solution, subjFillType, clipFillType);
}
bool PREFIX(Clipper, Execute__PolyTree)(Clipper* p,
                                          ClipType clipType,
                                          PolyTree& solution,
                                          PolyFillType subjFillType,
                                          PolyFillType clipFillType) {
    return p->Execute(clipType, solution, subjFillType, clipFillType);
}
bool PREFIX(Clipper, ReverseSolution__get)(Clipper* p) {return p->ReverseSolution();}
void PREFIX(Clipper, ReverseSolution__set)(Clipper* p, bool v) {p->ReverseSolution(v);}
bool PREFIX(Clipper, StrictlySimple__get)(Clipper* p) {return p->StrictlySimple();}
void PREFIX(Clipper, StrictlySimple__set)(Clipper* p, bool v) {p->StrictlySimple(v);}

ClipperOffset* PREFIX(ClipperOffset, _new)(double miterLimit, double roundPrecision) {
    return new ClipperOffset(miterLimit, roundPrecision);
}
void PREFIX(ClipperOffset, _destroy)(ClipperOffset* p) {delete p;}
void PREFIX(ClipperOffset, AddPath)(ClipperOffset* p, const Path& path, JoinType joinType, EndType endType) {
    p->AddPath(path, joinType, endType);
}
void PREFIX(ClipperOffset, AddPaths)(ClipperOffset* p, const Paths& paths, JoinType joinType, EndType endType) {
    p->AddPaths(paths, joinType, endType);
}
void PREFIX(ClipperOffset, Execute__Paths)(ClipperOffset* p, Paths& solution, double delta) {
    return p->Execute(solution, delta);
}
void PREFIX(ClipperOffset, Execute__PolyTree)(ClipperOffset* p, PolyTree& solution, double delta) {
    return p->Execute(solution, delta);
}
void PREFIX(ClipperOffset, Clear)(ClipperOffset* p) {return p->Clear();}
double PREFIX(ClipperOffset, MiterLimit__get)(ClipperOffset* p) {return p->MiterLimit;}
void PREFIX(ClipperOffset, MiterLimit__set)(ClipperOffset* p, double v) {p->MiterLimit = v;}
double PREFIX(ClipperOffset, ArcTolerance__get)(ClipperOffset* p) {return p->ArcTolerance;}
void PREFIX(ClipperOffset, ArcTolerance__set)(ClipperOffset* p, double v) {p->ArcTolerance = v;}

// functions
bool ClipperLib_Orientation(const Path& poly) {return Orientation(poly);}
double ClipperLib_Area(const Path& poly) {return Area(poly);}
int ClipperLib_PointInPolygon(const IntPoint& pt, const Path& path) {return PointInPolygon(pt, path);}
void ClipperLib_SimplifyPolygon(const Path& in_poly, Paths& out_polys, PolyFillType fillType) {
    SimplifyPolygon(in_poly, out_polys, fillType);
}
void ClipperLib_SimplifyPolygons__inout(const Paths& in_polys, Paths& out_polys, PolyFillType fillType) {
    SimplifyPolygons(in_polys, out_polys, fillType);
}
void ClipperLib_SimplifyPolygons__single(Paths& polys, PolyFillType fillType) {
    SimplifyPolygons(polys, fillType);
}
void ClipperLib_CleanPolygon__inout(const Path& in_poly, Path& out_poly, double distance) {
    CleanPolygon(in_poly, out_poly, distance);
}
void ClipperLib_CleanPolygon__single(Path& poly, double distance) {
    CleanPolygon(poly, distance);
}
void ClipperLib_CleanPolygons__inout(const Paths& in_polys, Paths& out_polys, double distance) {
    CleanPolygons(in_polys, out_polys, distance);
}
void ClipperLib_CleanPolygons__single(Paths& polys, double distance) {
    CleanPolygons(polys, distance);
}
void ClipperLib_MinkowskiSum__Path(const Path& pattern, const Paths& path, Paths& solution, bool pathIsClosed) {
    MinkowskiSum(pattern, path, solution, pathIsClosed);
}
void ClipperLib_MinkowskiSum__Paths(const Path& pattern, const Path& paths, Paths& solution, bool pathIsClosed) {
    MinkowskiSum(pattern, paths, solution, pathIsClosed);
}
void ClipperLib_MinkowskiDiff(const Path& poly1, const Path& poly2, Paths& solution) {
    MinkowskiDiff(poly1, poly2, solution);
}
void ClipperLib_PolyTreeToPaths(const PolyTree& polytree, Paths& paths) {
    PolyTreeToPaths(polytree, paths);
}
void ClipperLib_ClosedPathsFromPolyTree(const PolyTree& polytree, Paths& paths) {
    ClosedPathsFromPolyTree(polytree, paths);
}
void ClipperLib_OpenPathsFromPolyTree(PolyTree& polytree, Paths& paths) {
    OpenPathsFromPolyTree(polytree, paths);
}
void ClipperLib_ReversePath(Path& p) {
    ReversePath(p);
}
void ClipperLib_ReversePaths(Paths& p) {
    ReversePaths(p);
}

#ifdef __cplusplus
}
#endif