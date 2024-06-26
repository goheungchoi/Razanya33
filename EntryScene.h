#pragma once
#include "SceneGraph.h"
#include "Wall.h"

template<class T>
class SingleSpriteRenderable;
class Container;
class Button;
class ButtonEventHandler;


class EntryScene: public IScene
{
	ButtonEventHandler* _buttonEventHandler;

	struct SunFlares { int sentinel; };
	struct Sun { int sentinel; };
	struct Temple { int sentinel; };
	class Container* _mainMenuContainer;
	struct MainMenuComponents
	{
		Container* backgroundContainers;
		Container* backgroundSunrays;
		Container* backgroundCorona;
		
		SingleSpriteRenderable<SunFlares>* SunFlares;
		SingleSpriteRenderable<Sun>* Sun;
		SingleSpriteRenderable<Temple>* temple;
		SingleSpriteRenderable<MainMenuComponents>* background;

		Container* lazanya;
		Container* title;
		Container* highScoreTag;
		Container* highScore;
		Container* highScoreName;

		Container* age;

		Button* playbutton;
		Button* decoratorButton;
		Button* developerButton;
		Button* artWorkButton;
		Button* blockButton;
		Button* descriptionButton;

	}_mainComs;

public:
	EntryScene();
	~EntryScene() {};
	void Update(double deltaTime)override;
	void Draw()override;
	void InitScene()override;
	void EndScene()override;
	
	bool playBGM = false;
private:
	std::wstring _WStringAgeIndex(int age) {
		wchar_t buffer[30];
		swprintf_s(buffer, L"%2d", age);
		return std::wstring(buffer);
	}

	std::wstring __WStringifyLetterText() {
		std::wstring a = L" : ";
		std::wstring b = GetGameDataHub().GetMaxScoreUser().userName;
		std::wstring c = std::to_wstring(GetGameDataHub().GetMaxScoreUser().score);
		std::wstring d = L" ����";
		std::wstring newName = b + a+c+d;
		return newName;
	}
};

