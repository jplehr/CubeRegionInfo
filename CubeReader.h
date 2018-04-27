
#include "CubeRegionInfo.h"

#include <Cube.h>
#include <CubeMetric.h>

#include <string>

#ifndef CUBEREADER_H_
#define CUBEREADER_H_

/**
 * \author roman
 * \author JPL
 */
namespace CubeCallgraphBuilder {

	void build(std::string filePath, regioninfo::RegionInfoManager &rim);

};



#endif
