
LDFLAGS = -L$(CUPATH)/lib -lcube4
CXXFLAGS = -std=c++14 -I. -I$(CUPATH)/include/cube


SOURCES=\
				CubeReader.cpp \
				CubeRegionInfo.cpp

MAIN_SOURCE=\
				main.cpp
CXX := g++

default: all


all: fileprinter


fileprinter: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) $(MAIN_SOURCE) -o cube_fileprinter $(LDFLAGS)


library: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -shared -fPIC -o libcube_reader.so $(LDFLAGS)
