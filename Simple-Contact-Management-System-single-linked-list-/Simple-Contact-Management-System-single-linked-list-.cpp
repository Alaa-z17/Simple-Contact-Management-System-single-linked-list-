#include <iostream>
#include"clsMainScreen.h"

int main()
{
	clsContactManager <clsContact>SystemManager;
    clsMainScreen::ShowMainLayout(SystemManager);
}
