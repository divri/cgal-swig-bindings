#ifndef SWIG_CGAL_MESH_2_CRITERIA_H
#define SWIG_CGAL_MESH_2_CRITERIA_H

enum Face_badness { NOT_BAD, BAD, IMPERATIVELY_BAD };

template <class Cpp>
class Criteria_wrapper{
  Cpp data;
public:
  #ifndef SWIG
  typedef Cpp cpp_base;
  const cpp_base& get_data() const {return data;}
        cpp_base& get_data_ref()   {return data;}
  Criteria_wrapper(const cpp_base& base):data(base){}
  #endif
  Criteria_wrapper( double b , double S ):data(b,S){}
  Criteria_wrapper( double b ):data(b){}
  Criteria_wrapper(){}
};

#ifdef SWIGJAVA

template <class FT>
class Quality_simple{
  FT data;
public:
  #ifndef SWIG
  typedef FT cpp_base;
  const cpp_base& get_data() const {return data;}
        cpp_base& get_data_ref()   {return data;}
  #endif
  Quality_simple(FT v):data(v){}
};

template <class FT>
class Quality_pair{
  std::pair<FT,FT> data;
public:
  #ifndef SWIG
  typedef FT cpp_base;
  const cpp_base& get_data() const {return data;}
        cpp_base& get_data_ref()   {return data;}
  #endif
  Quality_pair(std::pair<FT,FT> p):data(p){}
};

template <class Caller,class Face_handle_,class Quality_>
class Java_Is_bad_wrapper
{
  Caller caller;
public:
  typedef typename Face_handle_::cpp_base  Face_handle;
  typedef typename Quality_::cpp_base      Quality;

  Java_Is_bad_wrapper(Caller& call):caller(call){}
  Java_Is_bad_wrapper(){}
    
  CGAL::Mesh_2::Face_badness operator()(const Face_handle& f,Quality& q) const {return CGAL::Mesh_2::NOT_BAD;}
  CGAL::Mesh_2::Face_badness operator()(const Quality& q) const {return CGAL::Mesh_2::NOT_BAD;}
};

template <class Is_bad_wrapper,class Caller>
class Java_criteria_wrapper{
  Is_bad_wrapper is_bad;
public:
  typedef typename Is_bad_wrapper::Quality      Quality;
  typedef typename Is_bad_wrapper::Face_handle  Face_handle;
  typedef Is_bad_wrapper                        Is_bad;  

  #ifndef SWIG
  typedef Java_criteria_wrapper<Is_bad_wrapper,Caller> cpp_base;
  const cpp_base& get_data() const {return *this;}
        cpp_base& get_data_ref()   {return *this;}
  const Is_bad& is_bad_object() const {return is_bad;}
  #endif
  
  Java_criteria_wrapper(){}
  Java_criteria_wrapper(Caller& call):is_bad(call){}
};

#endif

#endif //SWIG_CGAL_MESH_2_CRITERIA_H
