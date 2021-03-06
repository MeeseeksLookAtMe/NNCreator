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
#ifndef _RUDROPDOWN
#define _RUDROPDOWN

#include "../GItems/RUComponent.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

class RULabel;
class RUImageComponent;
class RUListbox;

class RUDropdown : public RUComponent
{

protected:
	bool open;
	unsigned int prevSelectedIndex;
	unsigned int selectedIndex;
	std::string arrowLocation;

	RULabel* selectedLabel;
	RUListbox* lbItems;
	RUImageComponent* arrow;

	// events
	void (GPanel::*OptionChangedListener)(int);
	virtual void onMouseDown(GPanel*, int, int);
	virtual void onMouseWheel(GPanel*, int, int, int);

public:
	static const int DEFAULT_SIDE_WIDTH = 24;

	// constructors & destructor
	RUDropdown();
	~RUDropdown();

	// gets
	bool isOpen() const;
	unsigned int getOptionsShown() const;
	unsigned int getSelectedIndex();
	std::string getSelectedText() const;

	// sets
	void toggleOpen();
	void setWidth(int);
	void setHeight(int);
	void setOptionsShown(unsigned int);
	void setSelectedIndex(unsigned int);
	void addOption(std::string);
	void clearOptions();

	// events
	void setOptionChangedListener(void (GPanel::*)(int));

	// render
	virtual void updateBackground(SDL_Renderer*);
	virtual std::string getType() const;
};

#endif
