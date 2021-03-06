// Written by Michael Zeilfelder, please check licenseHCraft.txt for the zlib-style license text.

#ifndef GUI_MENU_RIVALS_H
#define GUI_MENU_RIVALS_H

#include "../gui_dialog.h"
#include "../globals.h"
#include "../level_manager.h"

// the mode is by now called rivals in the game.


enum NumRacesSelected
{
    NRS_SINGLE,
    NRS_THREE,
    NRS_FIVE,
    NRS_SEVEN,
};

class GuiMenuRivals : public GuiDialog
{
public:
    GuiMenuRivals(const Config& config);

    virtual bool Load(const char* filename_, bool reloadLast_=false);
    virtual void Show();

protected:
    LevelDifficulty GetLevelDifficulty() const;
    bool OnSliderLevelDifficulty(const irr::SEvent &event_);
    bool OnSliderNumRaces(const irr::SEvent &event_);
    bool OnSliderPlayer(const irr::SEvent &event_);
    bool OnButtonStart(const irr::SEvent &event_);
    bool OnButtonMain(const irr::SEvent &event_);
    unsigned int GetNumRacesSelected();
    bool CheckCanStart();

private:
    irr::gui::IGUIButton* mButtonStart;
    irr::gui::IGUIButton* mButtonBack;
    IGUITextSlider* mSliderTrackDifficulty;
    IGUITextSlider* mSliderNumRaces;
    IGUITextSlider* mSliderTracks;
    IGUITextSlider* mSliderPlayer[MAX_RIVALS];
};


#endif // GUI_MENU_RIVALS_H
