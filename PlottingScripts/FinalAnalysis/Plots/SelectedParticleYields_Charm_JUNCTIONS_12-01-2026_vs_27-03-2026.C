#ifdef __CLING__
#pragma cling optimize(0)
#endif
void SelectedParticleYields_Charm_JUNCTIONS_12-01-2026_vs_27-03-2026()
{
//=========Macro generated from canvas: cYield_Charm_JUNCTIONS/Charm JUNCTIONS yields
//=========  (Wed Apr  1 16:36:56 2026) by ROOT version 6.30/01
   TCanvas *cYield_Charm_JUNCTIONS = new TCanvas("cYield_Charm_JUNCTIONS", "Charm JUNCTIONS yields",0,0,1540,780);
   gStyle->SetOptStat(0);
   cYield_Charm_JUNCTIONS->Range(0,0,1,1);
   cYield_Charm_JUNCTIONS->SetFillColor(0);
   cYield_Charm_JUNCTIONS->SetBorderMode(0);
   cYield_Charm_JUNCTIONS->SetBorderSize(2);
   cYield_Charm_JUNCTIONS->SetLeftMargin(0.12);
   cYield_Charm_JUNCTIONS->SetRightMargin(0.18);
   cYield_Charm_JUNCTIONS->SetBottomMargin(0.18);
   cYield_Charm_JUNCTIONS->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pYield_Charm_JUNCTIONS
   TPad *pYield_Charm_JUNCTIONS__9 = new TPad("pYield_Charm_JUNCTIONS", "",0,0.1,0.39,0.9);
   pYield_Charm_JUNCTIONS__9->Draw();
   pYield_Charm_JUNCTIONS__9->cd();
   pYield_Charm_JUNCTIONS__9->Range(-0.09999998,-1.965363,3.65,0.249998);
   pYield_Charm_JUNCTIONS__9->SetFillColor(0);
   pYield_Charm_JUNCTIONS__9->SetBorderMode(0);
   pYield_Charm_JUNCTIONS__9->SetBorderSize(2);
   pYield_Charm_JUNCTIONS__9->SetLogy();
   pYield_Charm_JUNCTIONS__9->SetTickx(1);
   pYield_Charm_JUNCTIONS__9->SetTicky(1);
   pYield_Charm_JUNCTIONS__9->SetLeftMargin(0.16);
   pYield_Charm_JUNCTIONS__9->SetRightMargin(0.04);
   pYield_Charm_JUNCTIONS__9->SetTopMargin(0.07);
   pYield_Charm_JUNCTIONS__9->SetBottomMargin(0.22);
   pYield_Charm_JUNCTIONS__9->SetFrameBorderMode(0);
   pYield_Charm_JUNCTIONS__9->SetFrameBorderMode(0);
   
   TH1D *hFrame_Charm_JUNCTIONS__7 = new TH1D("hFrame_Charm_JUNCTIONS__7","",3,0.5,3.5);
   hFrame_Charm_JUNCTIONS__7->SetMinimum(0.03326719);
   hFrame_Charm_JUNCTIONS__7->SetMaximum(1.244293);
   hFrame_Charm_JUNCTIONS__7->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hFrame_Charm_JUNCTIONS__7->SetLineColor(ci);
   hFrame_Charm_JUNCTIONS__7->GetXaxis()->SetBinLabel(1,"D^{#pm}");
   hFrame_Charm_JUNCTIONS__7->GetXaxis()->SetBinLabel(2,"D^{0}/#bar{D}^{0}");
   hFrame_Charm_JUNCTIONS__7->GetXaxis()->SetBinLabel(3,"#Lambda_{c}^{+}/#bar{#Lambda}_{c}^{-}");
   hFrame_Charm_JUNCTIONS__7->GetXaxis()->SetBit(TAxis::kLabelsVert);
   hFrame_Charm_JUNCTIONS__7->GetXaxis()->SetLabelFont(42);
   hFrame_Charm_JUNCTIONS__7->GetXaxis()->SetLabelOffset(0.006);
   hFrame_Charm_JUNCTIONS__7->GetXaxis()->SetLabelSize(0.053);
   hFrame_Charm_JUNCTIONS__7->GetXaxis()->SetTitleSize(0.05);
   hFrame_Charm_JUNCTIONS__7->GetXaxis()->SetTitleOffset(1);
   hFrame_Charm_JUNCTIONS__7->GetXaxis()->SetTitleFont(42);
   hFrame_Charm_JUNCTIONS__7->GetYaxis()->SetTitle("Per-event yield");
   hFrame_Charm_JUNCTIONS__7->GetYaxis()->SetLabelFont(42);
   hFrame_Charm_JUNCTIONS__7->GetYaxis()->SetLabelSize(0.042);
   hFrame_Charm_JUNCTIONS__7->GetYaxis()->SetTitleSize(0.05);
   hFrame_Charm_JUNCTIONS__7->GetYaxis()->SetTitleOffset(1.25);
   hFrame_Charm_JUNCTIONS__7->GetYaxis()->SetTitleFont(42);
   hFrame_Charm_JUNCTIONS__7->GetZaxis()->SetLabelFont(42);
   hFrame_Charm_JUNCTIONS__7->GetZaxis()->SetTitleOffset(1);
   hFrame_Charm_JUNCTIONS__7->GetZaxis()->SetTitleFont(42);
   hFrame_Charm_JUNCTIONS__7->Draw("");
   
   Double_t gYield_12-01-2026_Charm_JUNCTIONS_fx1010[3] = { 1, 2, 3 };
   Double_t gYield_12-01-2026_Charm_JUNCTIONS_fy1010[3] = { 0.4814804, 0.9214143, 0.06653437 };
   Double_t gYield_12-01-2026_Charm_JUNCTIONS_fex1010[3] = { 0.5, 0.5, 0.5 };
   Double_t gYield_12-01-2026_Charm_JUNCTIONS_fey1010[3] = { 0.0001972381, 0.0002842829, 6.281112e-05 };
   TGraphErrors *gre = new TGraphErrors(3,gYield_12-01-2026_Charm_JUNCTIONS_fx1010,gYield_12-01-2026_Charm_JUNCTIONS_fy1010,gYield_12-01-2026_Charm_JUNCTIONS_fex1010,gYield_12-01-2026_Charm_JUNCTIONS_fey1010);
   gre->SetName("gYield_12-01-2026_Charm_JUNCTIONS");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0000cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0000cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010 = new TH1F("Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010","Graph",100,0.2,3.8);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->SetMinimum(0.05982441);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->SetMaximum(1.007221);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->SetDirectory(nullptr);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->SetLineColor(ci);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetXaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetXaxis()->SetLabelSize(0.042);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetXaxis()->SetTitleSize(0.05);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetXaxis()->SetTitleOffset(1);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetXaxis()->SetTitleFont(42);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetYaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetYaxis()->SetLabelSize(0.042);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetYaxis()->SetTitleSize(0.05);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetYaxis()->SetTitleFont(42);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetZaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetZaxis()->SetTitleOffset(1);
   Graph_gYield_12mI01mI2026_Charm_JUNCTIONS1010->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYield_12-01-2026_Charm_JUNCTIONS1010);
   
   gre->Draw("p ");
   
   Double_t gYield_27-03-2026_Charm_JUNCTIONS_fx1011[3] = { 1, 2, 3 };
   Double_t gYield_27-03-2026_Charm_JUNCTIONS_fy1011[3] = { 0.4585081, 0.8762303, 0.2253069 };
   Double_t gYield_27-03-2026_Charm_JUNCTIONS_fex1011[3] = { 0.5, 0.5, 0.5 };
   Double_t gYield_27-03-2026_Charm_JUNCTIONS_fey1011[3] = { 0.0002309429, 0.0002818932, 0.0002064705 };
   gre = new TGraphErrors(3,gYield_27-03-2026_Charm_JUNCTIONS_fx1011,gYield_27-03-2026_Charm_JUNCTIONS_fy1011,gYield_27-03-2026_Charm_JUNCTIONS_fex1011,gYield_27-03-2026_Charm_JUNCTIONS_fey1011);
   gre->SetName("gYield_27-03-2026_Charm_JUNCTIONS");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011 = new TH1F("Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011","Graph",100,0.2,3.8);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->SetMinimum(0.1599592);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->SetMaximum(0.9416534);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->SetDirectory(nullptr);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->SetLineColor(ci);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetXaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetXaxis()->SetLabelSize(0.042);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetXaxis()->SetTitleSize(0.05);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetXaxis()->SetTitleOffset(1);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetXaxis()->SetTitleFont(42);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetYaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetYaxis()->SetLabelSize(0.042);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetYaxis()->SetTitleSize(0.05);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetYaxis()->SetTitleFont(42);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetZaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetZaxis()->SetTitleOffset(1);
   Graph_gYield_27mI03mI2026_Charm_JUNCTIONS1011->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYield_27-03-2026_Charm_JUNCTIONS1011);
   
   gre->Draw("p ");
   pYield_Charm_JUNCTIONS__9->Modified();
   cYield_Charm_JUNCTIONS->cd();
   TLatex *   tex = new TLatex(0.385,0.948,"Charm JUNCTIONS Per-Event Yields");
   tex->SetNDC();
   tex->SetTextAlign(22);
   tex->SetTextSize(0.042);
   tex->SetLineWidth(2);
   tex->Draw();
  
// ------------>Primitives in pad: pRatio_Charm_JUNCTIONS
   TPad *pRatio_Charm_JUNCTIONS__10 = new TPad("pRatio_Charm_JUNCTIONS", "",0.41,0.1,0.76,0.9);
   pRatio_Charm_JUNCTIONS__10->Draw();
   pRatio_Charm_JUNCTIONS__10->cd();
   pRatio_Charm_JUNCTIONS__10->Range(-0.2012987,-0.08213944,3.694805,1.363647);
   pRatio_Charm_JUNCTIONS__10->SetFillColor(0);
   pRatio_Charm_JUNCTIONS__10->SetBorderMode(0);
   pRatio_Charm_JUNCTIONS__10->SetBorderSize(2);
   pRatio_Charm_JUNCTIONS__10->SetTickx(1);
   pRatio_Charm_JUNCTIONS__10->SetTicky(1);
   pRatio_Charm_JUNCTIONS__10->SetLeftMargin(0.18);
   pRatio_Charm_JUNCTIONS__10->SetRightMargin(0.05);
   pRatio_Charm_JUNCTIONS__10->SetTopMargin(0.07);
   pRatio_Charm_JUNCTIONS__10->SetBottomMargin(0.22);
   pRatio_Charm_JUNCTIONS__10->SetFrameBorderMode(0);
   pRatio_Charm_JUNCTIONS__10->SetFrameBorderMode(0);
   
   TH1D *hRatioFrame_Charm_JUNCTIONS__8 = new TH1D("hRatioFrame_Charm_JUNCTIONS__8","",3,0.5,3.5);
   hRatioFrame_Charm_JUNCTIONS__8->SetMinimum(0.2359336);
   hRatioFrame_Charm_JUNCTIONS__8->SetMaximum(1.262442);
   hRatioFrame_Charm_JUNCTIONS__8->SetStats(0);

   ci = TColor::GetColor("#000099");
   hRatioFrame_Charm_JUNCTIONS__8->SetLineColor(ci);
   hRatioFrame_Charm_JUNCTIONS__8->GetXaxis()->SetBinLabel(1,"D^{#pm}");
   hRatioFrame_Charm_JUNCTIONS__8->GetXaxis()->SetBinLabel(2,"D^{0}/#bar{D}^{0}");
   hRatioFrame_Charm_JUNCTIONS__8->GetXaxis()->SetBinLabel(3,"#Lambda_{c}^{+}/#bar{#Lambda}_{c}^{-}");
   hRatioFrame_Charm_JUNCTIONS__8->GetXaxis()->SetLabelFont(42);
   hRatioFrame_Charm_JUNCTIONS__8->GetXaxis()->SetLabelOffset(0.006);
   hRatioFrame_Charm_JUNCTIONS__8->GetXaxis()->SetLabelSize(0.053);
   hRatioFrame_Charm_JUNCTIONS__8->GetXaxis()->SetTitleSize(0.05);
   hRatioFrame_Charm_JUNCTIONS__8->GetXaxis()->SetTitleOffset(1);
   hRatioFrame_Charm_JUNCTIONS__8->GetXaxis()->SetTitleFont(42);
   hRatioFrame_Charm_JUNCTIONS__8->GetYaxis()->SetTitle("Independent / Combined");
   hRatioFrame_Charm_JUNCTIONS__8->GetYaxis()->SetLabelFont(42);
   hRatioFrame_Charm_JUNCTIONS__8->GetYaxis()->SetLabelSize(0.048);
   hRatioFrame_Charm_JUNCTIONS__8->GetYaxis()->SetTitleSize(0.05);
   hRatioFrame_Charm_JUNCTIONS__8->GetYaxis()->SetTitleOffset(1.35);
   hRatioFrame_Charm_JUNCTIONS__8->GetYaxis()->SetTitleFont(42);
   hRatioFrame_Charm_JUNCTIONS__8->GetZaxis()->SetLabelFont(42);
   hRatioFrame_Charm_JUNCTIONS__8->GetZaxis()->SetTitleOffset(1);
   hRatioFrame_Charm_JUNCTIONS__8->GetZaxis()->SetTitleFont(42);
   hRatioFrame_Charm_JUNCTIONS__8->Draw("");
   TLine *line = new TLine(0.5,1,3.5,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   
   Double_t gYieldRatio_Charm_JUNCTIONS_12-01-2026_fx1012[3] = { 1, 2, 3 };
   Double_t gYieldRatio_Charm_JUNCTIONS_12-01-2026_fy1012[3] = { 1.050102, 1.051566, 0.2953055 };
   Double_t gYieldRatio_Charm_JUNCTIONS_12-01-2026_fex1012[3] = { 0.5, 0.5, 0.5 };
   Double_t gYieldRatio_Charm_JUNCTIONS_12-01-2026_fey1012[3] = { 0.000681766, 0.0004687301, 0.0003885254 };
   gre = new TGraphErrors(3,gYieldRatio_Charm_JUNCTIONS_12-01-2026_fx1012,gYieldRatio_Charm_JUNCTIONS_12-01-2026_fy1012,gYieldRatio_Charm_JUNCTIONS_12-01-2026_fex1012,gYieldRatio_Charm_JUNCTIONS_12-01-2026_fey1012);
   gre->SetName("gYieldRatio_Charm_JUNCTIONS_12-01-2026");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(24);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012 = new TH1F("Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012","Graph",100,0.2,3.8);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->SetMinimum(0.2192052);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->SetMaximum(1.127747);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->SetDirectory(nullptr);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->SetLineColor(ci);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetXaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetXaxis()->SetLabelSize(0.042);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetXaxis()->SetTitleSize(0.05);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetXaxis()->SetTitleOffset(1);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetXaxis()->SetTitleFont(42);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetYaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetYaxis()->SetLabelSize(0.042);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetYaxis()->SetTitleSize(0.05);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetYaxis()->SetTitleFont(42);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetZaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetZaxis()->SetTitleOffset(1);
   Graph_gYieldRatio_Charm_JUNCTIONS_12mI01mI20261012->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYieldRatio_Charm_JUNCTIONS_12-01-20261012);
   
   gre->Draw("p ");
   pRatio_Charm_JUNCTIONS__10->Modified();
   cYield_Charm_JUNCTIONS->cd();
  
// ------------>Primitives in pad: pLegend_Charm_JUNCTIONS
   TPad *pLegend_Charm_JUNCTIONS__11 = new TPad("pLegend_Charm_JUNCTIONS", "",0.77,0.1,1,0.9);
   pLegend_Charm_JUNCTIONS__11->Draw();
   pLegend_Charm_JUNCTIONS__11->cd();
   pLegend_Charm_JUNCTIONS__11->Range(0,0,1,1);
   pLegend_Charm_JUNCTIONS__11->SetFillColor(0);
   pLegend_Charm_JUNCTIONS__11->SetFillStyle(4000);
   pLegend_Charm_JUNCTIONS__11->SetBorderMode(0);
   pLegend_Charm_JUNCTIONS__11->SetBorderSize(2);
   pLegend_Charm_JUNCTIONS__11->SetLeftMargin(0.04);
   pLegend_Charm_JUNCTIONS__11->SetRightMargin(0.04);
   pLegend_Charm_JUNCTIONS__11->SetTopMargin(0.07);
   pLegend_Charm_JUNCTIONS__11->SetFrameFillStyle(0);
   pLegend_Charm_JUNCTIONS__11->SetFrameLineColor(0);
   pLegend_Charm_JUNCTIONS__11->SetFrameBorderMode(0);
   
   TLegend *leg = new TLegend(0.03,0.64,0.99,0.87,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.062);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gYield_12-01-2026_Charm_JUNCTIONS","Independent Sample","pe");

   ci = TColor::GetColor("#0000cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("gYield_27-03-2026_Charm_JUNCTIONS","Combined Sample","pe");

   ci = TColor::GetColor("#cc0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("gYieldRatio_Charm_JUNCTIONS_12-01-2026","Independent / Combined","pe");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(24);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   leg->Draw();
   pLegend_Charm_JUNCTIONS__11->Modified();
   cYield_Charm_JUNCTIONS->cd();
      tex = new TLatex(0.385,0.06,"Particle species");
   tex->SetNDC();
   tex->SetTextAlign(22);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
   cYield_Charm_JUNCTIONS->Modified();
   cYield_Charm_JUNCTIONS->SetSelected(cYield_Charm_JUNCTIONS);
}
