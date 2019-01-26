#include "NixieTubeClock.h"

void NixieTubeClock::TakeApartStringTime()
{
	char *s_time = agk::GetCurrentTime();

	char s_major_h[2];
	s_major_h[0] = *s_time++;
	s_major_h[1] = '\0';
	NixieTubeClock::major_h = atoi(s_major_h);

	char s_minor_h[2];
	s_minor_h[0] = *s_time++;
	s_minor_h[1] = '\0';
	NixieTubeClock::minor_h = atoi(s_minor_h);

	*s_time++;

	char s_major_m[2];
	s_major_m[0] = *s_time++;
	s_major_m[1] = '\0';
	NixieTubeClock::major_m = atoi(s_major_m);

	char s_minor_m[2];
	s_minor_m[0] = *s_time++;
	s_minor_m[1] = '\0';
	NixieTubeClock::minor_m = atoi(s_minor_m);

	*s_time++;

	char s_major_s[2];
	s_major_s[0] = *s_time++;
	s_major_s[1] = '\0';
	NixieTubeClock::major_s = atoi(s_major_s);

	char s_minor_s[2];
	s_minor_s[0] = *s_time++;
	s_minor_s[1] = '\0';
	NixieTubeClock::minor_s = atoi(s_minor_s);
}

void NixieTubeClock::SetAppSettings()
{
	agk::SetWindowTitle(WIN_TITLE);
	agk::SetWindowSize(WIN_WIDTH, WIN_HEIGHT, false);
	agk::SetWindowPosition((agk::GetMaxDeviceWidth() - WIN_WIDTH) / 2, (agk::GetMaxDeviceHeight() - WIN_HEIGHT) / 2);
	agk::SetWindowAllowResize(false);
	agk::SetDisplayAspect(static_cast<float>(WIN_WIDTH) / WIN_HEIGHT);
	agk::SetSyncRate(60, 0);
}

void NixieTubeClock::LoadResources()
{
	agk::LoadImage(1, "media\\panel.png", true);
	agk::LoadImage(2, "media\\background.png", false);
	agk::LoadImage(3, "media\\colon.png", false);
	agk::LoadImage(4, "media\\blank.png", false);
	agk::LoadImage(10, "media\\0.png", false);
	agk::LoadImage(11, "media\\1.png", false);
	agk::LoadImage(12, "media\\2.png", false);
	agk::LoadImage(13, "media\\3.png", false);
	agk::LoadImage(14, "media\\4.png", false);
	agk::LoadImage(15, "media\\5.png", false);
	agk::LoadImage(16, "media\\6.png", false);
	agk::LoadImage(17, "media\\7.png", false);
	agk::LoadImage(18, "media\\8.png", false);
	agk::LoadImage(19, "media\\9.png", false);

	NixieTubeClock::spriteID.panel   = agk::CreateSprite(1);
	NixieTubeClock::spriteID.bg      = agk::CreateSprite(2);
	NixieTubeClock::spriteID.colon   = agk::CreateSprite(3);
	NixieTubeClock::spriteID.major_h = agk::CreateSprite(10);
	NixieTubeClock::spriteID.minor_h = agk::CreateSprite(10);
	NixieTubeClock::spriteID.major_m = agk::CreateSprite(10);
	NixieTubeClock::spriteID.minor_m = agk::CreateSprite(10);
	NixieTubeClock::spriteID.major_s = agk::CreateSprite(10);
	NixieTubeClock::spriteID.minor_s = agk::CreateSprite(10);

	agk::SetSpriteSize(NixieTubeClock::spriteID.panel,   PANEL_WIDTH, -1);
	agk::SetSpriteSize(NixieTubeClock::spriteID.bg,      PANEL_WIDTH, -1);
	agk::SetSpriteSize(NixieTubeClock::spriteID.colon,   DIGIT_WIDTH, -1);
	agk::SetSpriteSize(NixieTubeClock::spriteID.major_h, DIGIT_WIDTH, -1);
	agk::SetSpriteSize(NixieTubeClock::spriteID.minor_h, DIGIT_WIDTH, -1);
	agk::SetSpriteSize(NixieTubeClock::spriteID.major_m, DIGIT_WIDTH, -1);
	agk::SetSpriteSize(NixieTubeClock::spriteID.minor_m, DIGIT_WIDTH, -1);
	agk::SetSpriteSize(NixieTubeClock::spriteID.major_s, DIGIT_WIDTH, -1);
	agk::SetSpriteSize(NixieTubeClock::spriteID.minor_s, DIGIT_WIDTH, -1);

	NixieTubeClock::margin_H = (agk::GetSpriteWidth(NixieTubeClock::spriteID.panel) - agk::GetSpriteWidth(NixieTubeClock::spriteID.colon) * 7) / 4;
	NixieTubeClock::margin_V = (agk::GetSpriteHeight(NixieTubeClock::spriteID.panel) - agk::GetSpriteHeight(NixieTubeClock::spriteID.colon)) / 2;

	agk::SetSpritePosition(NixieTubeClock::spriteID.panel, 0, 0);
	agk::SetSpritePosition(NixieTubeClock::spriteID.bg, 0, 0);
	agk::SetSpritePosition(NixieTubeClock::spriteID.major_h, NixieTubeClock::margin_H,                       NixieTubeClock::margin_V);
	agk::SetSpritePosition(NixieTubeClock::spriteID.minor_h, NixieTubeClock::margin_H     + DIGIT_WIDTH,     NixieTubeClock::margin_V);
	agk::SetSpritePosition(NixieTubeClock::spriteID.colon,   NixieTubeClock::margin_H     + DIGIT_WIDTH * 2, NixieTubeClock::margin_V);
	agk::SetSpritePosition(NixieTubeClock::spriteID.major_m, NixieTubeClock::margin_H     + DIGIT_WIDTH * 3, NixieTubeClock::margin_V);
	agk::SetSpritePosition(NixieTubeClock::spriteID.minor_m, NixieTubeClock::margin_H     + DIGIT_WIDTH * 4, NixieTubeClock::margin_V);
	agk::SetSpritePosition(NixieTubeClock::spriteID.major_s, NixieTubeClock::margin_H * 3 + DIGIT_WIDTH * 5, NixieTubeClock::margin_V);
	agk::SetSpritePosition(NixieTubeClock::spriteID.minor_s, NixieTubeClock::margin_H * 3 + DIGIT_WIDTH * 6, NixieTubeClock::margin_V);

	agk::SetSpriteDepth(NixieTubeClock::spriteID.panel,   10);
	agk::SetSpriteDepth(NixieTubeClock::spriteID.bg,      12);
	agk::SetSpriteDepth(NixieTubeClock::spriteID.colon,   11);
	agk::SetSpriteDepth(NixieTubeClock::spriteID.major_h, 11);
	agk::SetSpriteDepth(NixieTubeClock::spriteID.minor_h, 11);
	agk::SetSpriteDepth(NixieTubeClock::spriteID.major_m, 11);
	agk::SetSpriteDepth(NixieTubeClock::spriteID.minor_m, 11);
	agk::SetSpriteDepth(NixieTubeClock::spriteID.major_s, 11);
	agk::SetSpriteDepth(NixieTubeClock::spriteID.minor_s, 11);
}

int NixieTubeClock::GetMajorHour()
{
	NixieTubeClock::TakeApartStringTime();
	
	return NixieTubeClock::major_h;
}

int NixieTubeClock::GetMinorHour()
{
	NixieTubeClock::TakeApartStringTime();

	return NixieTubeClock::minor_h;
}

int NixieTubeClock::GetMajorMinute()
{
	NixieTubeClock::TakeApartStringTime();
	
	return NixieTubeClock::major_m;
}

int NixieTubeClock::GetMinorMinute()
{
	NixieTubeClock::TakeApartStringTime();

	return NixieTubeClock::minor_m;
}

int NixieTubeClock::GetMajorSecond()
{
	NixieTubeClock::TakeApartStringTime();

	return NixieTubeClock::major_s;
}

int NixieTubeClock::GetMinorSecond()
{
	NixieTubeClock::TakeApartStringTime();

	return NixieTubeClock::minor_s;
}

bool NixieTubeClock::GetColonBlink()
{
	if (NixieTubeClock::prev_minor_s != NixieTubeClock::minor_s)
	{
		NixieTubeClock::prev_minor_s = NixieTubeClock::minor_s;
		NixieTubeClock::colon = NixieTubeClock::colon ? false : true;
	}

	return NixieTubeClock::colon;
}

//AGK doesn't allow to use ID 0(null) and this is a reason to doing this shit with "+ OFFSET_TO_GET_IMAGE_ID" ;(
void NixieTubeClock::CreateFrame()
{
	agk::SetSpriteImage(NixieTubeClock::spriteID.major_h, NixieTubeClock::GetMajorHour()   + OFFSET_TO_GET_IMAGE_ID);
	agk::SetSpriteImage(NixieTubeClock::spriteID.minor_h, NixieTubeClock::GetMinorHour()   + OFFSET_TO_GET_IMAGE_ID);
	agk::SetSpriteImage(NixieTubeClock::spriteID.major_m, NixieTubeClock::GetMajorMinute() + OFFSET_TO_GET_IMAGE_ID);
	agk::SetSpriteImage(NixieTubeClock::spriteID.minor_m, NixieTubeClock::GetMinorMinute() + OFFSET_TO_GET_IMAGE_ID);
	agk::SetSpriteImage(NixieTubeClock::spriteID.major_s, NixieTubeClock::GetMajorSecond() + OFFSET_TO_GET_IMAGE_ID);
	agk::SetSpriteImage(NixieTubeClock::spriteID.minor_s, NixieTubeClock::GetMinorSecond() + OFFSET_TO_GET_IMAGE_ID);
	
	if (NixieTubeClock::GetColonBlink())
		agk::SetSpriteImage(NixieTubeClock::spriteID.colon, 3);
	else
		agk::SetSpriteImage(NixieTubeClock::spriteID.colon, 4);
}





