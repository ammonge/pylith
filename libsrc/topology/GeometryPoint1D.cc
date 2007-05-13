// -*- C++ -*-
//
// ======================================================================
//
//                           Brad T. Aagaard
//                        U.S. Geological Survey
//
// {LicenseText}
//
// ======================================================================
//

#include <portinfo>

#include "GeometryPoint1D.hh" // implementation of class methods

#include "pylith/utils/array.hh" // USES double_array

#include <assert.h> // USES assert()

// ----------------------------------------------------------------------
// Default constructor.
pylith::topology::GeometryPoint1D::GeometryPoint1D(void) :
  CellGeometry(0, 1, 1)
{ // constructor
} // constructor

// ----------------------------------------------------------------------
// Default destructor.
pylith::topology::GeometryPoint1D::~GeometryPoint1D(void)
{ // destructor
} // destructor

// ----------------------------------------------------------------------
// Get cell geometry for lower dimension cell.
pylith::topology::CellGeometry*
pylith::topology::GeometryPoint1D::geometryLowerDim(void) const
{ // geometryLowerDim
  return 0;
} // geometryLowerDim

// ----------------------------------------------------------------------
// Compute Jacobian at location in cell.
void
pylith::topology::GeometryPoint1D::jacobian(double_array* jacobian,
					    const double_array& vertices,
					    const double_array& location) const
{ // jacobian
  assert(0 != jacobian);

  assert(1 == jacobian->size());
  
  (*jacobian)[0] = 1.0;
} // jacobian


// End of file
