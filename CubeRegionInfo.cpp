#include "CubeRegionInfo.h"

#include <iostream>

using namespace regioninfo;

void RegionInfoManager::addRegionInfo(std::string regionIdentifier,
                                      RegionInfo reginfo) {
  regInfos[regionIdentifier] = reginfo;
}

std::set<std::string> RegionInfoManager::getAllFilenames() const {
  std::set<std::string> r;
  for (const auto &p : regInfos) {
    r.insert(p.second.filename);
  }
  return r;
}

std::set<std::string> RegionInfoManager::getAllFunctionNames() const {
  std::set<std::string> r;
  for (const auto &p : regInfos) {
    r.insert(p.second.regionName);
  }
  return r;
}

void RegionInfoManager::addNumberOfCalls(std::string fName,
                                         unsigned long long numberOfCalls) {
  regInfos[fName].numberOfCalls += numberOfCalls;
}

void RegionInfoManager::addRuntimeData(std::string fName,
                                       double timeInSeconds) {
  regInfos[fName].runtimeInSeconds += timeInSeconds;
}

void RegionInfoManager::printAll() const {
	for (const auto &ri : regInfos) {
		std::cout << ri.first << " " << ri.second.filename << std::endl;
	}
}
