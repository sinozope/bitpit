/*---------------------------------------------------------------------------*\
 *
 *  bitpit
 *
 *  Copyright (C) 2015-2016 OPTIMAD engineering Srl
 *
 *  -------------------------------------------------------------------------
 *  License
 *  This file is part of bitbit.
 *
 *  bitpit is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU Lesser General Public License v3 (LGPL)
 *  as published by the Free Software Foundation.
 *
 *  bitpit is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 *  License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with bitpit. If not, see <http://www.gnu.org/licenses/>.
 *
\*---------------------------------------------------------------------------*/

// ========================================================================== //
//           ** BitPit mesh ** Test 005 for class SurfUnstructured **         //
//                                                                            //
// Test multi-solid ASCI STL import ruotines                                  //
// ========================================================================== //

// ========================================================================== //
// INCLUDES                                                                   //
// ========================================================================== //

// Standard Template Library
# include <array>
# include <vector>
# include <iostream>

// BitPit
# include "bitpit_common.hpp"
# include "bitpit_operators.hpp"
# include "bitpit_surfunstructured.hpp"

// ========================================================================== //
// NAMESPACES                                                                 //
// ========================================================================== //
using namespace std;
using namespace bitpit;

// ========================================================================== //
// SUBTEST #001 Test multi-solid ASCI STL import ruotines                     //
// ========================================================================== //
int subtest_001(
    void
) {

// ========================================================================== //
// int subtest_001(                                                           //
//     void)                                                                  //
//                                                                            //
// Test multi-solid ASCI STL import ruotines.                                 //
// ========================================================================== //
// INPUT                                                                      //
// ========================================================================== //
// - none                                                                     //
// ========================================================================== //
// OUTPUT                                                                     //
// ========================================================================== //
// - err       : int, error flag:                                             //
//               err = 0  --> no error(s)                                     //
//               err = 1  --> error at step #1 (import STL)                   //
//               err = 2  --> error at step #2 (export STL)                   //
//               err = 3  --> error at step #3 (export VTK)                   //
// ========================================================================== //

// ========================================================================== //
// VARIABLES DECLARATION                                                      //
// ========================================================================== //

// Local variables
string                          in_name_ASCII = "./data/ahmed.stl";
string                          out_name_VTU = "ahmed";
SurfUnstructured                mesh(0);

// Counters
// none

// ========================================================================== //
// OUTPUT MESSAGE                                                             //
// ========================================================================== //
{
    // Scope variables
    // none

    // Output message
    cout << "** ================================================================= **" << endl;
    cout << "** Test #00005 - sub-test #001 - I/O functions for STL format        **" << endl;
    cout << "** ================================================================= **" << endl;
    cout << endl;
}

// ========================================================================== //
// STEP #1 (IMPORT MESH FROM ASCII STL)                                       //
// ========================================================================== //
{
    // Scope variables ------------------------------------------------------ //
    long                                nExpected = 45978;

    // Import mesh from stl format ------------------------------------------ //
    cout << "** Appending mesh from (ASCII): \"" << in_name_ASCII << "\"" << endl;
    if (mesh.importSTL(in_name_ASCII, false) > 0) return 1;
    if (mesh.getVertexCount() != 3*nExpected) return 1;
    if (mesh.getInternalCount() != nExpected) return 1;

    // Import mesh ---------------------------------------------------------- //
    mesh.write(out_name_VTU);

}

// ========================================================================== //
// OUTPUT MESSAGE                                                             //
// ========================================================================== //
{
    // Scope variables
    // none

    // Output message
    cout << "** ================================================================= **" << endl;
    cout << "** Test #00005 - sub-test #001 - completed!                          **" << endl;
    cout << "** ================================================================= **" << endl;
    cout << endl;
}

return 0; }

// ========================================================================== //
// MAIN FOR TEST #00005                                                       //
// ========================================================================== //
int main(
    void
) {

// ========================================================================== //
// VARIABLES DECLARATION                                                      //
// ========================================================================== //

// Local variabels
int                             err = 0;

// ========================================================================== //
// RUN SUB-TEST #001                                                          //
// ========================================================================== //
err = subtest_001();
if (err > 0) return(10 + err);

return err;

}
