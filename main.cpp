

#include "CubeRegionInfo.h"
#include "CubeReader.h"

#include <iostream>
#include <fstream>
#include <algorithm>

struct IDFilter {
  bool operator()(const std::string &s) { return true; }
};

struct IsDirectory {
  bool operator()(const std::string &s) { return s[0] == '/'; }
};

template <typename T, typename U>
void toOStream(T cont, std::ostream &o, U filter) {
  for (const auto &e : cont) {
    if (filter(e)) {
      o << e << "\n";
    }
  }
}

int main(int argc, char **argv) {

  if (argc != 2) {
    std::cout << "Need parameter .cubex file!" << std::endl;
    return -1;
  }

  std::string cubeFileName = std::string(argv[1]);

  regioninfo::RegionInfoManager rim;

  std::cout << "Reading cube file" << std::endl;
  cube_reader::build(cubeFileName, rim);
	cube_reader::attachRuntimeInfo(cubeFileName, rim);

  rim.printAll();

  {
    auto filenames = rim.getAllFilenames();
    toOStream(filenames, std::cout, IDFilter());
    std::ofstream out("filenames");
    toOStream(filenames, out, IsDirectory());
  }

  {
    auto funcNames = rim.getAllFunctionNames();
    std::ofstream out("functionNames");
    toOStream(funcNames, out, IDFilter());
	}

	return 0;
}
