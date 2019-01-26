//Includes
#include "template.h"

//Namespace
using namespace AGK;

app App;

void app::Begin()
{
	clock.SetAppSettings();
	clock.LoadResources();
}

int app::Loop()
{
	clock.CreateFrame();
	agk::Sync();

	return 0; //return 1 to close app
}


void app::End()
{
	agk::DeleteAllSprites();
	agk::DeleteAllImages();
}
