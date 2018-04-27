
#ifndef CUBEREGIONINFO_H
#define CUBEREGIONINFO_H


#include <string>
#include <map>
#include <set>

namespace regioninfo {

struct RegionInfo{
	std::string filename;
};

class RegionInfoManager {
	public:

		void addRegionInfo(std::string regionIdentifier, RegionInfo reginfo);
		std::set<std::string> getAllFilenames();

		void printAll();

	private:
		std::map<std::string, RegionInfo> regInfos;
};

} // namespace 
#endif // CUBEREGIONINFO_H
