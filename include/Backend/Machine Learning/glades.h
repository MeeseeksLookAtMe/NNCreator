// Copyright 2020 Robert Carneiro, Derek Meer, Matthew Tabak, Eric Lujan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#ifndef _GLADESML
#define _GLADESML

// The Truly Relative Database
#include <algorithm>
#include <map>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/signal.h>
#include <sys/stat.h>
#include <vector>

namespace shmea {
class GTable;
};

namespace glades {
class NNInfo;
class MetaNetwork;
class NNetwork;
class RNN;
class Layer;
class Terminator;

extern std::map<std::string, MetaNetwork*>* metaNets; // meta networks we loaded
extern std::map<std::string, NNetwork*>* neuralNets;  // neural networks we loaded
extern pthread_mutex_t* nnetworkMutex;

void init();
void cleanup();
pthread_mutex_t* getNNetworkMutex();
NNetwork* getNeuralNetwork(const std::string&);
RNN* getRNN(const std::string&);
bool saveNeuralNetwork(NNetwork*);
void addMetaNetwork(MetaNetwork*);
void removeMetaNetwork(const std::string&);

// Machine Learning Functions
MetaNetwork* train(NNInfo*, const shmea::GTable&, Terminator*);
MetaNetwork* train(NNetwork*, const shmea::GTable&, Terminator*);
MetaNetwork* train(MetaNetwork*, const shmea::GTable&, Terminator*);
MetaNetwork* test(NNInfo*, const shmea::GTable&);
MetaNetwork* test(NNetwork*, const shmea::GTable&);
MetaNetwork* test(MetaNetwork*, const shmea::GTable&);
MetaNetwork* crossValidate(NNInfo*, std::string, bool, int);
MetaNetwork* crossValidate(std::string, std::vector<std::string>, float, bool, int);

// Database Setup
bool doesDatabaseExist();
void createDatabase();
};

#endif
