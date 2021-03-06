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
#ifndef _RUNNCREATORPANEL
#define _RUNNCREATORPANEL

#include "Backend/Machine Learning/glades.h"
#include "Frontend/GItems/GPanel.h"
#include <map>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>

class Point2;
class RUImageComponent;
class RULabel;
class RUTextbox;
class RUCheckbox;
class RUButton;
class RUDropdown;
class RUGraph;
class RUTable;
class RUProgressBar;
class RUTabContainer;
class PlotType;

namespace shmea {
class GTable;
class GList;
};

namespace glades {
class NNInfo;
};

class NNCreatorPanel : public GPanel
{
protected:
	virtual void onStart();

	glades::NNInfo* formInfo;
	int currentHiddenLayerIndex;

	int64_t parsePct(const std::string&);

public:
	RUGraph* lcGraph;
	RUGraph* dartboardGraph;
	RUGraph* rocCurveGraph;
	RUTable* cMatrixTable;

	RULabel* lblSettings;

	RULabel* lblNeuralNet;
	RUDropdown* ddNeuralNet;

	RULabel* lblNetName;
	RUTextbox* tbNetName;

	RUButton* btnSave;
	RUButton* btnDelete;

	RULabel* lblLayerSize;

	RULabel* lblHiddenLayerCount;
	RUTextbox* tbHiddenLayerCount;

	RULabel* lblEditHiddenLayer;
	// RULabel* lblIndexToEdit;
	RUDropdown* ddIndexToEdit;

	RULabel* lblHiddenLayerSize;
	RUTextbox* tbHiddenLayerSize;

	RULabel* lblLearningRate;
	RUTextbox* tbLearningRate;

	RULabel* lblWeightDecay;
	RUTextbox* tbWeightDecay;

	RULabel* lblMomentumFactor;
	RUTextbox* tbMomentumFactor;

	RULabel* lblPHidden;
	RUTextbox* tbPHidden;

	RULabel* lblActivationFunctions;
	RUDropdown* ddActivationFunctions;

	RULabel* lblActivationParam;
	RUTextbox* tbActivationParam;

	RULabel* lblEditInputLayer;

	RULabel* lblPInput;
	RUTextbox* tbPInput;

	RUTextbox* tbBatchSize;

	RULabel* lblEditOutputLayer;

	RULabel* lblOutputType;
	RUDropdown* ddOutputType;

	RULabel* lblOutputLayerSize;
	RUTextbox* tbOutputLayerSize;

	RUTextbox* tbCopyDestination;

	RUDropdown* ddTestDataSourceType;
	RUButton* sendButton;

	RUTextbox* tbTestDataSourcePath;

	RUCheckbox* chkCrossVal;
	RULabel* lblttv;
	RUTextbox* tbTrainPct;
	RUTextbox* tbTestPct;
	RUTextbox* tbValidationPct;

	NNCreatorPanel(const std::string&, int, int);
	void loadDDNN();
	void populateIndexToEdit(int = 0);
	void populateHLayerForm();
	void syncFormVar();
	void loadNNet(glades::NNInfo*);
	// void PlotLearningRate(const std::vector<Point2*>&);
	// void PlotLearningRate(PlotType*);
	// void PlotCoordinates(const std::vector<shmea::GTable*>&);
	void PlotLearningCurve(const shmea::GList&);
	void PlotROCCurve(const std::vector<Point2*>&);
	void PlotScatter(const shmea::GTable&);
	void updateConfMatrixTable(const shmea::GTable&);

	virtual void GuiCommander1(const std::string&, int, int);
	virtual void GuiCommander2(const std::string&, int, int);
	virtual void GuiCommander3(const std::string&, int, int);
	virtual void GuiCommander4(const std::string&, int, int);
	virtual void GuiCommander5(const std::string&, int, int);
	virtual void GuiCommander6(const std::string&, int, int);
	virtual void GuiCommander7(const std::string&, int, int);
	virtual void GuiCommander8(const std::string&, int, int);
	virtual void GuiCommander9();
	virtual void GuiCommander10(const std::string&, int, int);
	virtual void GuiCommander11(char);
	virtual void GuiCommander12(const std::string&, int, int);
	virtual void GuiCommander13(const std::string&, int, int);
	virtual void GuiCommander14(const std::string&, int, int);
	virtual void GuiCommander15(int);
};

#endif
