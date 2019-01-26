#pragma once

#include "agk.h"

#define WIN_TITLE "Nixie Tube Clock"
#define WIN_WIDTH 940
#define WIN_HEIGHT 209

#define OFFSET_TO_GET_IMAGE_ID 10
#define PANEL_WIDTH 100.0
#define DIGIT_WIDTH 12.75

struct SpriteID
{
	int major_h, minor_h;
	int major_m, minor_m;
	int major_s, minor_s;
	int colon, panel, bg;
};

class NixieTubeClock
{
private:
	int major_h, minor_h;
	int major_m, minor_m;
	int major_s, minor_s;
	int prev_minor_s;
	SpriteID spriteID;
	bool colon;
	float margin_V, margin_H;

	void TakeApartStringTime();

public:
	NixieTubeClock() {};

	void SetAppSettings();
	void LoadResources();
	int GetMajorHour();
	int GetMinorHour();
	int GetMajorMinute();
	int GetMinorMinute();
	int GetMajorSecond();
	int GetMinorSecond();
	bool GetColonBlink();
	void CreateFrame();
};
