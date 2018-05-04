
#ifndef CUBEREGIONINFO_H
#define CUBEREGIONINFO_H


#include <string>
#include <map>
#include <set>

namespace regioninfo {

struct RegionInfo {
  std::string regionName;
  std::string filename;
  double runtimeInSeconds;
  unsigned long long numberOfCalls;
};

class RegionInfoManager {
public:
  void addRegionInfo(std::string regionIdentifier, RegionInfo reginfo);
  std::set<std::string> getAllFilenames() const;
  std::set<std::string> getAllFunctionNames() const;
  void addNumberOfCalls(std::string fName, unsigned long long numberOfCalls);
  void addRuntimeData(std::string fName, double timeInSeconds);

  void printAll() const;

private:
  std::map<std::string, RegionInfo> regInfos;
};

} // namespace 
#endif // CUBEREGIONINFO_H
