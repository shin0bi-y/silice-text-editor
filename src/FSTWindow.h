#include "FSTReader.h"
#include <vector>
#include <string>
#include "./ImGuiColorTextEdit/TextEditor.h"
#include "../libs/implot/implot.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#ifndef SILICE_TEXT_EDITOR_FSTWINDOW_H
#define SILICE_TEXT_EDITOR_FSTWINDOW_H

enum ConvertType {
    BINARY = 0,
    DECIMALS = 1,
    HEXADECIMAL = 2,
    CUSTOM = 3,
};

typedef struct {
    std::vector<int> x_data;
    std::vector<int> y_data;
    std::string name;
    fstHandle signalId;
    ConvertType type;
    std::string customtype_string;
    ImVec4 color;
} Plot;

class FSTWindow {
public:
    std::string fstFilePath;
    FSTWindow() = default;
    void load(std::string file, TextEditor& editor);
    void load(json data, TextEditor &editors);
    void render();
    json save();
private:
    std::vector<Plot> g_Plots;
    FSTReader *g_Reader = nullptr;
    ImPlotRange range = ImPlotRange(-1, -1);
    ImPlotRange *plotXLimits = nullptr;
    fstHandle hover = 0;
    fstHandle hoveredSignal = 0;
    fstHandle qindex = 0;
    std::vector<std::pair<int, int>> qindexValues;
    double markerX = 0;
    char filterBuffer[256] = {};
    char customFilterBuffer[256] = {};
    TextEditor* editor;
    void clean();
    void addPlot(fstHandle signal);
    void removePlot(fstHandle signal);
    bool isDisplayed(fstHandle signal);
    void showPlots();
    void showPlotMenu();
    std::string parseCustomExp(std::string expression, int value);
    int binaryToDecimal(std::string n);
};


#endif //SILICE_TEXT_EDITOR_FSTWINDOW_H
