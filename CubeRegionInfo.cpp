#include "CubeRegionInfo.h"

#include <iostream>

using namespace regioninfo;

void RegionInfoManager::addRegionInfo(std::string regionIdentifier, RegionInfo reginfo) {
	regInfos[regionIdentifier] = reginfo;
}

std::set<std::string> RegionInfoManager::getAllFilenames() {
	std::set<std::string> r;
	for (const auto &p : regInfos) {
		r.insert(p.second.filename);
	}
	return r;
}

void RegionInfoManager::printAll() {
	for (const auto &ri : regInfos) {
		std::cout << ri.first << " " << ri.second.filename << std::endl;
	}
}
