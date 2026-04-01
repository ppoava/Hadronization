#ifdef __CLING__
#pragma cling optimize(0)
#endif
void SelectedParticleYields_Beauty_JUNCTIONS_12-01-2026_vs_27-03-2026()
{
//=========Macro generated from canvas: cYield_Beauty_JUNCTIONS/Beauty JUNCTIONS yields
//=========  (Wed Apr  1 16:36:55 2026) by ROOT version 6.30/01
   TCanvas *cYield_Beauty_JUNCTIONS = new TCanvas("cYield_Beauty_JUNCTIONS", "Beauty JUNCTIONS yields",0,0,1540,780);
   gStyle->SetOptStat(0);
   cYield_Beauty_JUNCTIONS->Range(0,0,1,1);
   cYield_Beauty_JUNCTIONS->SetFillColor(0);
   cYield_Beauty_JUNCTIONS->SetBorderMode(0);
   cYield_Beauty_JUNCTIONS->SetBorderSize(2);
   cYield_Beauty_JUNCTIONS->SetLeftMargin(0.12);
   cYield_Beauty_JUNCTIONS->SetRightMargin(0.18);
   cYield_Beauty_JUNCTIONS->SetBottomMargin(0.18);
   cYield_Beauty_JUNCTIONS->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pYield_Beauty_JUNCTIONS
   TPad *pYield_Beauty_JUNCTIONS__3 = new TPad("pYield_Beauty_JUNCTIONS", "",0,0.1,0.39,0.9);
   pYield_Beauty_JUNCTIONS__3->Draw();
   pYield_Beauty_JUNCTIONS__3->cd();
   pYield_Beauty_JUNCTIONS__3->Range(-0.09999998,-1.495973,3.65,-0.03568496);
   pYield_Beauty_JUNCTIONS__3->SetFillColor(0);
   pYield_Beauty_JUNCTIONS__3->SetBorderMode(0);
   pYield_Beauty_JUNCTIONS__3->SetBorderSize(2);
   pYield_Beauty_JUNCTIONS__3->SetLogy();
   pYield_Beauty_JUNCTIONS__3->SetTickx(1);
   pYield_Beauty_JUNCTIONS__3->SetTicky(1);
   pYield_Beauty_JUNCTIONS__3->SetLeftMargin(0.16);
   pYield_Beauty_JUNCTIONS__3->SetRightMargin(0.04);
   pYield_Beauty_JUNCTIONS__3->SetTopMargin(0.07);
   pYield_Beauty_JUNCTIONS__3->SetBottomMargin(0.22);
   pYield_Beauty_JUNCTIONS__3->SetFrameBorderMode(0);
   pYield_Beauty_JUNCTIONS__3->SetFrameBorderMode(0);
   
   TH1D *hFrame_Beauty_JUNCTIONS__3 = new TH1D("hFrame_Beauty_JUNCTIONS__3","",3,0.5,3.5);
   hFrame_Beauty_JUNCTIONS__3->SetMinimum(0.06687906);
   hFrame_Beauty_JUNCTIONS__3->SetMaximum(0.7279388);
   hFrame_Beauty_JUNCTIONS__3->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hFrame_Beauty_JUNCTIONS__3->SetLineColor(ci);
   hFrame_Beauty_JUNCTIONS__3->GetXaxis()->SetBinLabel(1,"B^{#pm}");
   hFrame_Beauty_JUNCTIONS__3->GetXaxis()->SetBinLabel(2,"B^{0}/#bar{B}^{0}");
   hFrame_Beauty_JUNCTIONS__3->GetXaxis()->SetBinLabel(3,"#Lambda_{b}^{0}/#bar{#Lambda}_{b}^{0}");
   hFrame_Beauty_JUNCTIONS__3->GetXaxis()->SetBit(TAxis::kLabelsVert);
   hFrame_Beauty_JUNCTIONS__3->GetXaxis()->SetLabelFont(42);
   hFrame_Beauty_JUNCTIONS__3->GetXaxis()->SetLabelOffset(0.006);
   hFrame_Beauty_JUNCTIONS__3->GetXaxis()->SetLabelSize(0.053);
   hFrame_Beauty_JUNCTIONS__3->GetXaxis()->SetTitleSize(0.05);
   hFrame_Beauty_JUNCTIONS__3->GetXaxis()->SetTitleOffset(1);
   hFrame_Beauty_JUNCTIONS__3->GetXaxis()->SetTitleFont(42);
   hFrame_Beauty_JUNCTIONS__3->GetYaxis()->SetTitle("Per-event yield");
   hFrame_Beauty_JUNCTIONS__3->GetYaxis()->SetLabelFont(42);
   hFrame_Beauty_JUNCTIONS__3->GetYaxis()->SetLabelSize(0.042);
   hFrame_Beauty_JUNCTIONS__3->GetYaxis()->SetTitleSize(0.05);
   hFrame_Beauty_JUNCTIONS__3->GetYaxis()->SetTitleOffset(1.25);
   hFrame_Beauty_JUNCTIONS__3->GetYaxis()->SetTitleFont(42);
   hFrame_Beauty_JUNCTIONS__3->GetZaxis()->SetLabelFont(42);
   hFrame_Beauty_JUNCTIONS__3->GetZaxis()->SetTitleOffset(1);
   hFrame_Beauty_JUNCTIONS__3->GetZaxis()->SetTitleFont(42);
   hFrame_Beauty_JUNCTIONS__3->Draw("");
   
   Double_t gYield_12-01-2026_Beauty_JUNCTIONS_fx1004[3] = { 1, 2, 3 };
   Double_t gYield_12-01-2026_Beauty_JUNCTIONS_fy1004[3] = { 0.5389993, 0.5390066, 0.1337581 };
   Double_t gYield_12-01-2026_Beauty_JUNCTIONS_fex1004[3] = { 0.5, 0.5, 0.5 };
   Double_t gYield_12-01-2026_Beauty_JUNCTIONS_fey1004[3] = { 0.0002145907, 0.0001883894, 0.0001806815 };
   TGraphErrors *gre = new TGraphErrors(3,gYield_12-01-2026_Beauty_JUNCTIONS_fx1004,gYield_12-01-2026_Beauty_JUNCTIONS_fy1004,gYield_12-01-2026_Beauty_JUNCTIONS_fex1004,gYield_12-01-2026_Beauty_JUNCTIONS_fey1004);
   gre->SetName("gYield_12-01-2026_Beauty_JUNCTIONS");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0000cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0000cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004 = new TH1F("Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004","Graph",100,0.2,3.8);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->SetMinimum(0.09301379);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->SetMaximum(0.5797776);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->SetDirectory(nullptr);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->SetLineColor(ci);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetXaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetXaxis()->SetLabelSize(0.042);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetXaxis()->SetTitleSize(0.05);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetXaxis()->SetTitleOffset(1);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetXaxis()->SetTitleFont(42);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetYaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetYaxis()->SetLabelSize(0.042);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetYaxis()->SetTitleSize(0.05);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetYaxis()->SetTitleFont(42);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetZaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetZaxis()->SetTitleOffset(1);
   Graph_gYield_12mI01mI2026_Beauty_JUNCTIONS1004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYield_12-01-2026_Beauty_JUNCTIONS1004);
   
   gre->Draw("p ");
   
   Double_t gYield_27-03-2026_Beauty_JUNCTIONS_fx1005[3] = { 1, 2, 3 };
   Double_t gYield_27-03-2026_Beauty_JUNCTIONS_fy1005[3] = { 0.5382517, 0.5377616, 0.1342051 };
   Double_t gYield_27-03-2026_Beauty_JUNCTIONS_fex1005[3] = { 0.5, 0.5, 0.5 };
   Double_t gYield_27-03-2026_Beauty_JUNCTIONS_fey1005[3] = { 0.000914781, 0.001034438, 0.0003597698 };
   gre = new TGraphErrors(3,gYield_27-03-2026_Beauty_JUNCTIONS_fx1005,gYield_27-03-2026_Beauty_JUNCTIONS_fy1005,gYield_27-03-2026_Beauty_JUNCTIONS_fex1005,gYield_27-03-2026_Beauty_JUNCTIONS_fey1005);
   gre->SetName("gYield_27-03-2026_Beauty_JUNCTIONS");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005 = new TH1F("Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005","Graph",100,0.2,3.8);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->SetMinimum(0.09331324);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->SetMaximum(0.5796986);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->SetDirectory(nullptr);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->SetLineColor(ci);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetXaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetXaxis()->SetLabelSize(0.042);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetXaxis()->SetTitleSize(0.05);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetXaxis()->SetTitleOffset(1);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetXaxis()->SetTitleFont(42);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetYaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetYaxis()->SetLabelSize(0.042);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetYaxis()->SetTitleSize(0.05);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetYaxis()->SetTitleFont(42);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetZaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetZaxis()->SetTitleOffset(1);
   Graph_gYield_27mI03mI2026_Beauty_JUNCTIONS1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYield_27-03-2026_Beauty_JUNCTIONS1005);
   
   gre->Draw("p ");
   pYield_Beauty_JUNCTIONS__3->Modified();
   cYield_Beauty_JUNCTIONS->cd();
   TLatex *   tex = new TLatex(0.385,0.948,"Beauty JUNCTIONS Per-Event Yields");
   tex->SetNDC();
   tex->SetTextAlign(22);
   tex->SetTextSize(0.042);
   tex->SetLineWidth(2);
   tex->Draw();
  
// ------------>Primitives in pad: pRatio_Beauty_JUNCTIONS
   TPad *pRatio_Beauty_JUNCTIONS__4 = new TPad("pRatio_Beauty_JUNCTIONS", "",0.41,0.1,0.76,0.9);
   pRatio_Beauty_JUNCTIONS__4->Draw();
   pRatio_Beauty_JUNCTIONS__4->cd();
   pRatio_Beauty_JUNCTIONS__4->Range(-0.2012987,0.6678415,3.694805,1.245571);
   pRatio_Beauty_JUNCTIONS__4->SetFillColor(0);
   pRatio_Beauty_JUNCTIONS__4->SetBorderMode(0);
   pRatio_Beauty_JUNCTIONS__4->SetBorderSize(2);
   pRatio_Beauty_JUNCTIONS__4->SetTickx(1);
   pRatio_Beauty_JUNCTIONS__4->SetTicky(1);
   pRatio_Beauty_JUNCTIONS__4->SetLeftMargin(0.18);
   pRatio_Beauty_JUNCTIONS__4->SetRightMargin(0.05);
   pRatio_Beauty_JUNCTIONS__4->SetTopMargin(0.07);
   pRatio_Beauty_JUNCTIONS__4->SetBottomMargin(0.22);
   pRatio_Beauty_JUNCTIONS__4->SetFrameBorderMode(0);
   pRatio_Beauty_JUNCTIONS__4->SetFrameBorderMode(0);
   
   TH1D *hRatioFrame_Beauty_JUNCTIONS__4 = new TH1D("hRatioFrame_Beauty_JUNCTIONS__4","",3,0.5,3.5);
   hRatioFrame_Beauty_JUNCTIONS__4->SetMinimum(0.794942);
   hRatioFrame_Beauty_JUNCTIONS__4->SetMaximum(1.20513);
   hRatioFrame_Beauty_JUNCTIONS__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   hRatioFrame_Beauty_JUNCTIONS__4->SetLineColor(ci);
   hRatioFrame_Beauty_JUNCTIONS__4->GetXaxis()->SetBinLabel(1,"B^{#pm}");
   hRatioFrame_Beauty_JUNCTIONS__4->GetXaxis()->SetBinLabel(2,"B^{0}/#bar{B}^{0}");
   hRatioFrame_Beauty_JUNCTIONS__4->GetXaxis()->SetBinLabel(3,"#Lambda_{b}^{0}/#bar{#Lambda}_{b}^{0}");
   hRatioFrame_Beauty_JUNCTIONS__4->GetXaxis()->SetLabelFont(42);
   hRatioFrame_Beauty_JUNCTIONS__4->GetXaxis()->SetLabelOffset(0.006);
   hRatioFrame_Beauty_JUNCTIONS__4->GetXaxis()->SetLabelSize(0.053);
   hRatioFrame_Beauty_JUNCTIONS__4->GetXaxis()->SetTitleSize(0.05);
   hRatioFrame_Beauty_JUNCTIONS__4->GetXaxis()->SetTitleOffset(1);
   hRatioFrame_Beauty_JUNCTIONS__4->GetXaxis()->SetTitleFont(42);
   hRatioFrame_Beauty_JUNCTIONS__4->GetYaxis()->SetTitle("Independent / Combined");
   hRatioFrame_Beauty_JUNCTIONS__4->GetYaxis()->SetLabelFont(42);
   hRatioFrame_Beauty_JUNCTIONS__4->GetYaxis()->SetLabelSize(0.048);
   hRatioFrame_Beauty_JUNCTIONS__4->GetYaxis()->SetTitleSize(0.05);
   hRatioFrame_Beauty_JUNCTIONS__4->GetYaxis()->SetTitleOffset(1.35);
   hRatioFrame_Beauty_JUNCTIONS__4->GetYaxis()->SetTitleFont(42);
   hRatioFrame_Beauty_JUNCTIONS__4->GetZaxis()->SetLabelFont(42);
   hRatioFrame_Beauty_JUNCTIONS__4->GetZaxis()->SetTitleOffset(1);
   hRatioFrame_Beauty_JUNCTIONS__4->GetZaxis()->SetTitleFont(42);
   hRatioFrame_Beauty_JUNCTIONS__4->Draw("");
   TLine *line = new TLine(0.5,1,3.5,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   
   Double_t gYieldRatio_Beauty_JUNCTIONS_12-01-2026_fx1006[3] = { 1, 2, 3 };
   Double_t gYieldRatio_Beauty_JUNCTIONS_12-01-2026_fy1006[3] = { 1.001389, 1.002315, 0.9966693 };
   Double_t gYieldRatio_Beauty_JUNCTIONS_12-01-2026_fex1006[3] = { 0.5, 0.5, 0.5 };
   Double_t gYieldRatio_Beauty_JUNCTIONS_12-01-2026_fey1006[3] = { 0.001747975, 0.00195962, 0.002991847 };
   gre = new TGraphErrors(3,gYieldRatio_Beauty_JUNCTIONS_12-01-2026_fx1006,gYieldRatio_Beauty_JUNCTIONS_12-01-2026_fy1006,gYieldRatio_Beauty_JUNCTIONS_12-01-2026_fex1006,gYieldRatio_Beauty_JUNCTIONS_12-01-2026_fey1006);
   gre->SetName("gYieldRatio_Beauty_JUNCTIONS_12-01-2026");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(24);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006 = new TH1F("Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006","Graph",100,0.2,3.8);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->SetMinimum(0.9926177);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->SetMaximum(1.005334);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->SetDirectory(nullptr);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->SetLineColor(ci);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetXaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetXaxis()->SetLabelSize(0.042);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetXaxis()->SetTitleSize(0.05);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetXaxis()->SetTitleOffset(1);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetXaxis()->SetTitleFont(42);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetYaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetYaxis()->SetLabelSize(0.042);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetYaxis()->SetTitleSize(0.05);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetYaxis()->SetTitleFont(42);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetZaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetZaxis()->SetTitleOffset(1);
   Graph_gYieldRatio_Beauty_JUNCTIONS_12mI01mI20261006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYieldRatio_Beauty_JUNCTIONS_12-01-20261006);
   
   gre->Draw("p ");
   pRatio_Beauty_JUNCTIONS__4->Modified();
   cYield_Beauty_JUNCTIONS->cd();
  
// ------------>Primitives in pad: pLegend_Beauty_JUNCTIONS
   TPad *pLegend_Beauty_JUNCTIONS__5 = new TPad("pLegend_Beauty_JUNCTIONS", "",0.77,0.1,1,0.9);
   pLegend_Beauty_JUNCTIONS__5->Draw();
   pLegend_Beauty_JUNCTIONS__5->cd();
   pLegend_Beauty_JUNCTIONS__5->Range(0,0,1,1);
   pLegend_Beauty_JUNCTIONS__5->SetFillColor(0);
   pLegend_Beauty_JUNCTIONS__5->SetFillStyle(4000);
   pLegend_Beauty_JUNCTIONS__5->SetBorderMode(0);
   pLegend_Beauty_JUNCTIONS__5->SetBorderSize(2);
   pLegend_Beauty_JUNCTIONS__5->SetLeftMargin(0.04);
   pLegend_Beauty_JUNCTIONS__5->SetRightMargin(0.04);
   pLegend_Beauty_JUNCTIONS__5->SetTopMargin(0.07);
   pLegend_Beauty_JUNCTIONS__5->SetFrameFillStyle(0);
   pLegend_Beauty_JUNCTIONS__5->SetFrameLineColor(0);
   pLegend_Beauty_JUNCTIONS__5->SetFrameBorderMode(0);
   
   TLegend *leg = new TLegend(0.03,0.64,0.99,0.87,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.062);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gYield_12-01-2026_Beauty_JUNCTIONS","Independent Sample","pe");

   ci = TColor::GetColor("#0000cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("gYield_27-03-2026_Beauty_JUNCTIONS","Combined Sample","pe");

   ci = TColor::GetColor("#cc0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("gYieldRatio_Beauty_JUNCTIONS_12-01-2026","Independent / Combined","pe");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(24);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   leg->Draw();
   pLegend_Beauty_JUNCTIONS__5->Modified();
   cYield_Beauty_JUNCTIONS->cd();
      tex = new TLatex(0.385,0.06,"Particle species");
   tex->SetNDC();
   tex->SetTextAlign(22);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
   cYield_Beauty_JUNCTIONS->Modified();
   cYield_Beauty_JUNCTIONS->SetSelected(cYield_Beauty_JUNCTIONS);
}
