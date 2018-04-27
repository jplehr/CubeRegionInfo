#include "CubeReader.h"

using namespace regioninfo;

void CubeCallgraphBuilder::build(std::string filePath, regioninfo::RegionInfoManager &rim) {

	try {
		// Create cube instance
		cube::Cube cube;
		// Read our cube file
		cube.openCubeReport( filePath );
		// Get the cube nodes
		const std::vector<cube::Cnode*>& cnodes = cube.get_cnodev();
		unsigned long long overallNumberOfCalls = 0;
		double overallRuntime = 0.0;

		cube::Metric* timeMetric = cube.get_met("time");
		cube::Metric* visitsMetric = cube.get_met("visits");

		const std::vector<cube::Thread*> threads = cube.get_thrdv();

		for(auto cregion : cube.get_regv()) {
			RegionInfo ri { cregion->get_mod() };
			rim.addRegionInfo(cregion->get_name(), ri);
		}

	} catch (const cube::RuntimeError& e) {
		std::cout << "CubeReader failed: " << std::endl
				<< e.get_msg() << std::endl;
		exit(-1);
	}

}
