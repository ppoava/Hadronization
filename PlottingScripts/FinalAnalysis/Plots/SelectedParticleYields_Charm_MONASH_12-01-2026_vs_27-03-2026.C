#ifdef __CLING__
#pragma cling optimize(0)
#endif
void SelectedParticleYields_Charm_MONASH_12-01-2026_vs_27-03-2026()
{
//=========Macro generated from canvas: cYield_Charm_MONASH/Charm MONASH yields
//=========  (Wed Apr  1 16:36:55 2026) by ROOT version 6.30/01
   TCanvas *cYield_Charm_MONASH = new TCanvas("cYield_Charm_MONASH", "Charm MONASH yields",0,0,1540,780);
   gStyle->SetOptStat(0);
   cYield_Charm_MONASH->Range(0,0,1,1);
   cYield_Charm_MONASH->SetFillColor(0);
   cYield_Charm_MONASH->SetBorderMode(0);
   cYield_Charm_MONASH->SetBorderSize(2);
   cYield_Charm_MONASH->SetLeftMargin(0.12);
   cYield_Charm_MONASH->SetRightMargin(0.18);
   cYield_Charm_MONASH->SetBottomMargin(0.18);
   cYield_Charm_MONASH->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pYield_Charm_MONASH
   TPad *pYield_Charm_MONASH__6 = new TPad("pYield_Charm_MONASH", "",0,0.1,0.39,0.9);
   pYield_Charm_MONASH__6->Draw();
   pYield_Charm_MONASH__6->cd();
   pYield_Charm_MONASH__6->Range(-0.09999998,-2.080221,3.65,0.2891841);
   pYield_Charm_MONASH__6->SetFillColor(0);
   pYield_Charm_MONASH__6->SetBorderMode(0);
   pYield_Charm_MONASH__6->SetBorderSize(2);
   pYield_Charm_MONASH__6->SetLogy();
   pYield_Charm_MONASH__6->SetTickx(1);
   pYield_Charm_MONASH__6->SetTicky(1);
   pYield_Charm_MONASH__6->SetLeftMargin(0.16);
   pYield_Charm_MONASH__6->SetRightMargin(0.04);
   pYield_Charm_MONASH__6->SetTopMargin(0.07);
   pYield_Charm_MONASH__6->SetBottomMargin(0.22);
   pYield_Charm_MONASH__6->SetFrameBorderMode(0);
   pYield_Charm_MONASH__6->SetFrameBorderMode(0);
   
   TH1D *hFrame_Charm_MONASH__5 = new TH1D("hFrame_Charm_MONASH__5","",3,0.5,3.5);
   hFrame_Charm_MONASH__5->SetMinimum(0.02760883);
   hFrame_Charm_MONASH__5->SetMaximum(1.32839);
   hFrame_Charm_MONASH__5->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hFrame_Charm_MONASH__5->SetLineColor(ci);
   hFrame_Charm_MONASH__5->GetXaxis()->SetBinLabel(1,"D^{#pm}");
   hFrame_Charm_MONASH__5->GetXaxis()->SetBinLabel(2,"D^{0}/#bar{D}^{0}");
   hFrame_Charm_MONASH__5->GetXaxis()->SetBinLabel(3,"#Lambda_{c}^{+}/#bar{#Lambda}_{c}^{-}");
   hFrame_Charm_MONASH__5->GetXaxis()->SetBit(TAxis::kLabelsVert);
   hFrame_Charm_MONASH__5->GetXaxis()->SetLabelFont(42);
   hFrame_Charm_MONASH__5->GetXaxis()->SetLabelOffset(0.006);
   hFrame_Charm_MONASH__5->GetXaxis()->SetLabelSize(0.053);
   hFrame_Charm_MONASH__5->GetXaxis()->SetTitleSize(0.05);
   hFrame_Charm_MONASH__5->GetXaxis()->SetTitleOffset(1);
   hFrame_Charm_MONASH__5->GetXaxis()->SetTitleFont(42);
   hFrame_Charm_MONASH__5->GetYaxis()->SetTitle("Per-event yield");
   hFrame_Charm_MONASH__5->GetYaxis()->SetLabelFont(42);
   hFrame_Charm_MONASH__5->GetYaxis()->SetLabelSize(0.042);
   hFrame_Charm_MONASH__5->GetYaxis()->SetTitleSize(0.05);
   hFrame_Charm_MONASH__5->GetYaxis()->SetTitleOffset(1.25);
   hFrame_Charm_MONASH__5->GetYaxis()->SetTitleFont(42);
   hFrame_Charm_MONASH__5->GetZaxis()->SetLabelFont(42);
   hFrame_Charm_MONASH__5->GetZaxis()->SetTitleOffset(1);
   hFrame_Charm_MONASH__5->GetZaxis()->SetTitleFont(42);
   hFrame_Charm_MONASH__5->Draw("");
   
   Double_t gYield_12-01-2026_Charm_MONASH_fx1007[3] = { 1, 2, 3 };
   Double_t gYield_12-01-2026_Charm_MONASH_fy1007[3] = { 0.5096067, 0.9798575, 0.05521766 };
   Double_t gYield_12-01-2026_Charm_MONASH_fex1007[3] = { 0.5, 0.5, 0.5 };
   Double_t gYield_12-01-2026_Charm_MONASH_fey1007[3] = { 0.0001637737, 0.0003563522, 8.37484e-05 };
   TGraphErrors *gre = new TGraphErrors(3,gYield_12-01-2026_Charm_MONASH_fx1007,gYield_12-01-2026_Charm_MONASH_fy1007,gYield_12-01-2026_Charm_MONASH_fex1007,gYield_12-01-2026_Charm_MONASH_fey1007);
   gre->SetName("gYield_12-01-2026_Charm_MONASH");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0000cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0000cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYield_12mI01mI2026_Charm_MONASH1007 = new TH1F("Graph_gYield_12mI01mI2026_Charm_MONASH1007","Graph",100,0.2,3.8);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->SetMinimum(0.04962052);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->SetMaximum(1.072722);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->SetDirectory(nullptr);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->SetLineColor(ci);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetXaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetXaxis()->SetLabelSize(0.042);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetXaxis()->SetTitleSize(0.05);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetXaxis()->SetTitleOffset(1);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetXaxis()->SetTitleFont(42);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetYaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetYaxis()->SetLabelSize(0.042);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetYaxis()->SetTitleSize(0.05);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetYaxis()->SetTitleFont(42);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetZaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetZaxis()->SetTitleOffset(1);
   Graph_gYield_12mI01mI2026_Charm_MONASH1007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYield_12-01-2026_Charm_MONASH1007);
   
   gre->Draw("p ");
   
   Double_t gYield_27-03-2026_Charm_MONASH_fx1008[3] = { 1, 2, 3 };
   Double_t gYield_27-03-2026_Charm_MONASH_fy1008[3] = { 0.5122102, 0.9837071, 0.06351357 };
   Double_t gYield_27-03-2026_Charm_MONASH_fex1008[3] = { 0.5, 0.5, 0.5 };
   Double_t gYield_27-03-2026_Charm_MONASH_fey1008[3] = { 0.00020403, 0.0002857223, 0.000129926 };
   gre = new TGraphErrors(3,gYield_27-03-2026_Charm_MONASH_fx1008,gYield_27-03-2026_Charm_MONASH_fy1008,gYield_27-03-2026_Charm_MONASH_fex1008,gYield_27-03-2026_Charm_MONASH_fey1008);
   gre->SetName("gYield_27-03-2026_Charm_MONASH");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYield_27mI03mI2026_Charm_MONASH1008 = new TH1F("Graph_gYield_27mI03mI2026_Charm_MONASH1008","Graph",100,0.2,3.8);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->SetMinimum(0.05704528);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->SetMaximum(1.076054);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->SetDirectory(nullptr);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->SetLineColor(ci);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetXaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetXaxis()->SetLabelSize(0.042);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetXaxis()->SetTitleSize(0.05);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetXaxis()->SetTitleOffset(1);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetXaxis()->SetTitleFont(42);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetYaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetYaxis()->SetLabelSize(0.042);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetYaxis()->SetTitleSize(0.05);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetYaxis()->SetTitleFont(42);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetZaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetZaxis()->SetTitleOffset(1);
   Graph_gYield_27mI03mI2026_Charm_MONASH1008->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYield_27-03-2026_Charm_MONASH1008);
   
   gre->Draw("p ");
   pYield_Charm_MONASH__6->Modified();
   cYield_Charm_MONASH->cd();
   TLatex *   tex = new TLatex(0.385,0.948,"Charm MONASH Per-Event Yields");
   tex->SetNDC();
   tex->SetTextAlign(22);
   tex->SetTextSize(0.042);
   tex->SetLineWidth(2);
   tex->Draw();
  
// ------------>Primitives in pad: pRatio_Charm_MONASH
   TPad *pRatio_Charm_MONASH__7 = new TPad("pRatio_Charm_MONASH", "",0.41,0.1,0.76,0.9);
   pRatio_Charm_MONASH__7->Draw();
   pRatio_Charm_MONASH__7->cd();
   pRatio_Charm_MONASH__7->Range(-0.2012987,0.5381479,3.694805,1.245366);
   pRatio_Charm_MONASH__7->SetFillColor(0);
   pRatio_Charm_MONASH__7->SetBorderMode(0);
   pRatio_Charm_MONASH__7->SetBorderSize(2);
   pRatio_Charm_MONASH__7->SetTickx(1);
   pRatio_Charm_MONASH__7->SetTicky(1);
   pRatio_Charm_MONASH__7->SetLeftMargin(0.18);
   pRatio_Charm_MONASH__7->SetRightMargin(0.05);
   pRatio_Charm_MONASH__7->SetTopMargin(0.07);
   pRatio_Charm_MONASH__7->SetBottomMargin(0.22);
   pRatio_Charm_MONASH__7->SetFrameBorderMode(0);
   pRatio_Charm_MONASH__7->SetFrameBorderMode(0);
   
   TH1D *hRatioFrame_Charm_MONASH__6 = new TH1D("hRatioFrame_Charm_MONASH__6","",3,0.5,3.5);
   hRatioFrame_Charm_MONASH__6->SetMinimum(0.6937358);
   hRatioFrame_Charm_MONASH__6->SetMaximum(1.19586);
   hRatioFrame_Charm_MONASH__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   hRatioFrame_Charm_MONASH__6->SetLineColor(ci);
   hRatioFrame_Charm_MONASH__6->GetXaxis()->SetBinLabel(1,"D^{#pm}");
   hRatioFrame_Charm_MONASH__6->GetXaxis()->SetBinLabel(2,"D^{0}/#bar{D}^{0}");
   hRatioFrame_Charm_MONASH__6->GetXaxis()->SetBinLabel(3,"#Lambda_{c}^{+}/#bar{#Lambda}_{c}^{-}");
   hRatioFrame_Charm_MONASH__6->GetXaxis()->SetLabelFont(42);
   hRatioFrame_Charm_MONASH__6->GetXaxis()->SetLabelOffset(0.006);
   hRatioFrame_Charm_MONASH__6->GetXaxis()->SetLabelSize(0.053);
   hRatioFrame_Charm_MONASH__6->GetXaxis()->SetTitleSize(0.05);
   hRatioFrame_Charm_MONASH__6->GetXaxis()->SetTitleOffset(1);
   hRatioFrame_Charm_MONASH__6->GetXaxis()->SetTitleFont(42);
   hRatioFrame_Charm_MONASH__6->GetYaxis()->SetTitle("Independent / Combined");
   hRatioFrame_Charm_MONASH__6->GetYaxis()->SetLabelFont(42);
   hRatioFrame_Charm_MONASH__6->GetYaxis()->SetLabelSize(0.048);
   hRatioFrame_Charm_MONASH__6->GetYaxis()->SetTitleSize(0.05);
   hRatioFrame_Charm_MONASH__6->GetYaxis()->SetTitleOffset(1.35);
   hRatioFrame_Charm_MONASH__6->GetYaxis()->SetTitleFont(42);
   hRatioFrame_Charm_MONASH__6->GetZaxis()->SetLabelFont(42);
   hRatioFrame_Charm_MONASH__6->GetZaxis()->SetTitleOffset(1);
   hRatioFrame_Charm_MONASH__6->GetZaxis()->SetTitleFont(42);
   hRatioFrame_Charm_MONASH__6->Draw("");
   TLine *line = new TLine(0.5,1,3.5,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   
   Double_t gYieldRatio_Charm_MONASH_12-01-2026_fx1009[3] = { 1, 2, 3 };
   Double_t gYieldRatio_Charm_MONASH_12-01-2026_fy1009[3] = { 0.9949171, 0.9960867, 0.8693837 };
   Double_t gYieldRatio_Charm_MONASH_12-01-2026_fex1009[3] = { 0.5, 0.5, 0.5 };
   Double_t gYieldRatio_Charm_MONASH_12-01-2026_fey1009[3] = { 0.0005092082, 0.0004636088, 0.002213946 };
   gre = new TGraphErrors(3,gYieldRatio_Charm_MONASH_12-01-2026_fx1009,gYieldRatio_Charm_MONASH_12-01-2026_fy1009,gYieldRatio_Charm_MONASH_12-01-2026_fex1009,gYieldRatio_Charm_MONASH_12-01-2026_fey1009);
   gre->SetName("gYieldRatio_Charm_MONASH_12-01-2026");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(24);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009 = new TH1F("Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009","Graph",100,0.2,3.8);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->SetMinimum(0.8542317);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->SetMaximum(1.009488);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->SetDirectory(nullptr);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->SetLineColor(ci);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetXaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetXaxis()->SetLabelSize(0.042);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetXaxis()->SetTitleSize(0.05);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetXaxis()->SetTitleOffset(1);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetXaxis()->SetTitleFont(42);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetYaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetYaxis()->SetLabelSize(0.042);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetYaxis()->SetTitleSize(0.05);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetYaxis()->SetTitleFont(42);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetZaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetZaxis()->SetTitleOffset(1);
   Graph_gYieldRatio_Charm_MONASH_12mI01mI20261009->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYieldRatio_Charm_MONASH_12-01-20261009);
   
   gre->Draw("p ");
   pRatio_Charm_MONASH__7->Modified();
   cYield_Charm_MONASH->cd();
  
// ------------>Primitives in pad: pLegend_Charm_MONASH
   TPad *pLegend_Charm_MONASH__8 = new TPad("pLegend_Charm_MONASH", "",0.77,0.1,1,0.9);
   pLegend_Charm_MONASH__8->Draw();
   pLegend_Charm_MONASH__8->cd();
   pLegend_Charm_MONASH__8->Range(0,0,1,1);
   pLegend_Charm_MONASH__8->SetFillColor(0);
   pLegend_Charm_MONASH__8->SetFillStyle(4000);
   pLegend_Charm_MONASH__8->SetBorderMode(0);
   pLegend_Charm_MONASH__8->SetBorderSize(2);
   pLegend_Charm_MONASH__8->SetLeftMargin(0.04);
   pLegend_Charm_MONASH__8->SetRightMargin(0.04);
   pLegend_Charm_MONASH__8->SetTopMargin(0.07);
   pLegend_Charm_MONASH__8->SetFrameFillStyle(0);
   pLegend_Charm_MONASH__8->SetFrameLineColor(0);
   pLegend_Charm_MONASH__8->SetFrameBorderMode(0);
   
   TLegend *leg = new TLegend(0.03,0.64,0.99,0.87,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.062);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gYield_12-01-2026_Charm_MONASH","Independent Sample","pe");

   ci = TColor::GetColor("#0000cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("gYield_27-03-2026_Charm_MONASH","Combined Sample","pe");

   ci = TColor::GetColor("#cc0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("gYieldRatio_Charm_MONASH_12-01-2026","Independent / Combined","pe");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(24);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   leg->Draw();
   pLegend_Charm_MONASH__8->Modified();
   cYield_Charm_MONASH->cd();
      tex = new TLatex(0.385,0.06,"Particle species");
   tex->SetNDC();
   tex->SetTextAlign(22);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
   cYield_Charm_MONASH->Modified();
   cYield_Charm_MONASH->SetSelected(cYield_Charm_MONASH);
}
