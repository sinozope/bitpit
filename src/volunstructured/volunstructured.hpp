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

#ifndef __BITPIT_VOLUNSTRUCTURED_HPP__
#define __BITPIT_VOLUNSTRUCTURED_HPP__

#include <array>
#include <vector>

#include "bitpit_patchkernel.hpp"

namespace bitpit {

class VolUnstructured : public VolumeKernel {

public:
	using VolumeKernel::isPointInside;
	using PatchKernel::locatePoint;

	VolUnstructured(const int &id, const int &dimension);

	~VolUnstructured();

	void setExpert(bool expert);

	double evalCellVolume(const long &id);
	double evalCellSize(const long &id);

	double evalInterfaceArea(const long &id);
	std::array<double, 3> evalInterfaceNormal(const long &id);

	bool isPointInside(const std::array<double, 3> &point);
	bool isPointInside(const long &id, const std::array<double, 3> &point);
	long locatePoint(const std::array<double, 3> &point);

protected:
	const std::vector<adaption::Info> _updateAdaption(bool trackAdaption);
	bool _markCellForRefinement(const long &id);
	bool _markCellForCoarsening(const long &id);
	bool _enableCellBalancing(const long &id, bool enabled);

private:

};

}

#endif
