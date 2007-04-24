// -*- C++ -*-
//
// ----------------------------------------------------------------------
//
//                           Brad T. Aagaard
//                        U.S. Geological Survey
//
// {LicenseText}
//
// ----------------------------------------------------------------------
//

#include <portinfo>

#include "EqKinSrc.hh" // implementation of object methods

#include "SlipTimeFn.hh" // USES SlipTimeFn

#include <assert.h> // USES assert()

// ----------------------------------------------------------------------
// Default constructor.
pylith::faults::EqKinSrc::EqKinSrc(void) :
  _slipfn(0)
{ // constructor
} // constructor

// ----------------------------------------------------------------------
// Destructor.
pylith::faults::EqKinSrc::~EqKinSrc(void)
{ // destructor
  delete _slipfn; _slipfn = 0;
} // destructor

// ----------------------------------------------------------------------
// Copy constructor.
pylith::faults::EqKinSrc::EqKinSrc(const EqKinSrc& s) :
  _slipfn(0)
{ // copy constructor
  if (0 != s._slipfn)
    _slipfn = s._slipfn->clone();
} // copy constructor

// ----------------------------------------------------------------------
// Set slip time function.
void
pylith::faults::EqKinSrc::slipfn(SlipTimeFn* slipfn)
{ // slipfn
  delete _slipfn; _slipfn = (0 != slipfn) ? slipfn->clone() : 0;
} // slipfn

// ----------------------------------------------------------------------
// Initialize slip time function.
void
pylith::faults::EqKinSrc::initialize(const ALE::Obj<Mesh>& mesh,
				   const spatialdata::geocoords::CoordSys* cs,
				   const std::set<Mesh::point_type>& vertices)
{ // initialize
  assert(0 != _slipfn);
  _slipfn->initialize(mesh, cs, vertices);
} // initialize

// ----------------------------------------------------------------------
// Get slip on fault surface at time t.
const ALE::Obj<pylith::real_section_type>&
pylith::faults::EqKinSrc::slip(const double t,
			       const std::set<Mesh::point_type>& vertices)
{ // slip
  assert(0 != _slipfn);
  return _slipfn->slip(t, vertices);
} // slip


// End of file 
