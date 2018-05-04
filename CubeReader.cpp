#include "CubeReader.h"

using namespace regioninfo;

void cube_reader::build(std::string filePath, regioninfo::RegionInfoManager &rim) {

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
			RegionInfo ri { cregion->get_name(), cregion->get_mod(), .0, 0 };
			rim.addRegionInfo(cregion->get_name(), ri);
		}

	} catch (const cube::RuntimeError& e) {
		std::cout << "CubeReader failed: " << std::endl
				<< e.get_msg() << std::endl;
		exit(-1);
	}

}

void cube_reader::attachRuntimeInfo(std::string filePath, regioninfo::RegionInfoManager &rim) {

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

		for(auto cnode : cnodes){
			// I assume these are static initializers and ctors
			if(cnode->get_parent() == nullptr) {
				continue;
			}

			// Put the parent/child pair into our call graph
			auto parentNode = cnode->get_parent()->get_callee();	// RN: don't trust no one. It IS the parent node
			auto childnode = cnode->get_callee();

			for(unsigned int i = 0; i < threads.size(); i++) {
				unsigned long long numberOfCalls = (unsigned long long) cube.get_sev(visitsMetric, cnode, threads.at(i));
				double timeInSeconds = cube.get_sev(timeMetric, cnode, threads.at(i));

				rim.addNumberOfCalls(childnode->get_name(), numberOfCalls);
				rim.addRuntimeData(childnode->get_name(), timeInSeconds);

				overallNumberOfCalls += numberOfCalls;
				overallRuntime += timeInSeconds;
			}
		}

		std::cout << "Finished construction .." << std::endl
				<< "    " << "numberOfCalls: " << overallNumberOfCalls
				<< "    " << "runtime: "  << overallRuntime << " seconds" << std::endl;

	} catch (const cube::RuntimeError& e) {
		std::cout << "CubeReader failed: " << std::endl
				<< e.get_msg() << std::endl;
		exit(-1);
	}

}
