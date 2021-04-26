#include "FSTReader.h"
#include <vector>
#include <string>
#include "./ImGuiColorTextEdit/TextEditor.h"

#ifndef SILICE_TEXT_EDITOR_FSTWINDOW_H
#define SILICE_TEXT_EDITOR_FSTWINDOW_H

enum ConvertType {
    BINARY = 0,
    DECIMALS = 1,
    HEXADECIMAL = 2
};

typedef struct {
    std::vector<int> x_data;
    std::vector<int> y_data;
    std::string name;
    fstHandle signalId;
    ConvertType type;
    ImVec4 color;
} Plot;

class FSTWindow {
public:
    FSTWindow(std::string file, TextEditor& editor);
    void render();
private:
    void addPlot(fstHandle signal);
    void removePlot(fstHandle signal);
    bool isDisplayed(fstHandle signal);
    void showPlots();
    void showPlotMenu();
};


#endif //SILICE_TEXT_EDITOR_FSTWINDOW_H
