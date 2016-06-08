/************************************************/
/* An overlay of 1D root histograms with Legend */
/************************************************/
#ifndef __OXSX_ROOTMULTIPLOT__
#define __OXSX_ROOTMULTIPLOT__
#include <TLegend.h>
#include <TCanvas.h>
#include <TH1D.h>
#include <THStack.h>
#include <string>
#include <vector>

class BinnedPdf;
class ROOTMultiPlot{
 public:
 ROOTMultiPlot() : fLegend(TLegend(0.7, 0.7, 0.9, 0.9)), fConstructed(false), fDrawLegend(true), fStacked(false){}

  void AddPdf(const BinnedPdf& pdf_, const std::string& name_);
  void AddPdf(const TH1D& pdf_, const std::string& name_);
  
  void SaveAs(const std::string& filename_);
  TCanvas& GetCanvas();

  void SetStacked(bool b_ = true);
  void SetDrawLegend(bool b_);
 private:
  bool    fConstructed;
  bool    fDrawLegend;
  bool    fStacked;

  void    Construct();
  void    ConstructOverlay();
  void    ConstructStacked();

  TCanvas fCanvas;
  TLegend fLegend;
  THStack fStack;
  std::vector<std::string> fNames;
  std::vector<TH1D>        fHists;

  static const int fColorScheme[];
  static const unsigned fNcolors;
};

#endif
