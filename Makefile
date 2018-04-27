
LDFLAGS = -L$(CUPATH)/lib -lcube4
CXXFLAGS = -std=c++14 -I. -I$(CUPATH)/include/cube


SOURCES=\
				main.cpp \
				CubeReader.cpp \
				CubeRegionInfo.cpp

CXX := g++

default: all


all: fileprinter


fileprinter: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o cube_fileprinter $(LDFLAGS)
