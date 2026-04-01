#ifdef __CLING__
#pragma cling optimize(0)
#endif
void SelectedParticleYields_Beauty_MONASH_12-01-2026_vs_27-03-2026()
{
//=========Macro generated from canvas: cYield_Beauty_MONASH/Beauty MONASH yields
//=========  (Wed Apr  1 13:39:33 2026) by ROOT version 6.30/01
   TCanvas *cYield_Beauty_MONASH = new TCanvas("cYield_Beauty_MONASH", "Beauty MONASH yields",0,0,1540,780);
   gStyle->SetOptStat(0);
   cYield_Beauty_MONASH->Range(0,0,1,1);
   cYield_Beauty_MONASH->SetFillColor(0);
   cYield_Beauty_MONASH->SetBorderMode(0);
   cYield_Beauty_MONASH->SetBorderSize(2);
   cYield_Beauty_MONASH->SetLeftMargin(0.12);
   cYield_Beauty_MONASH->SetRightMargin(0.18);
   cYield_Beauty_MONASH->SetBottomMargin(0.18);
   cYield_Beauty_MONASH->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pYield_Beauty_MONASH
   TPad *pYield_Beauty_MONASH__0 = new TPad("pYield_Beauty_MONASH", "",0,0.1,0.39,0.9);
   pYield_Beauty_MONASH__0->Draw();
   pYield_Beauty_MONASH__0->cd();
   pYield_Beauty_MONASH__0->Range(-0.09999998,-3.478136,3.65,0.2141737);
   pYield_Beauty_MONASH__0->SetFillColor(0);
   pYield_Beauty_MONASH__0->SetBorderMode(0);
   pYield_Beauty_MONASH__0->SetBorderSize(2);
   pYield_Beauty_MONASH__0->SetLogy();
   pYield_Beauty_MONASH__0->SetTickx(1);
   pYield_Beauty_MONASH__0->SetTicky(1);
   pYield_Beauty_MONASH__0->SetLeftMargin(0.16);
   pYield_Beauty_MONASH__0->SetRightMargin(0.04);
   pYield_Beauty_MONASH__0->SetTopMargin(0.07);
   pYield_Beauty_MONASH__0->SetBottomMargin(0.22);
   pYield_Beauty_MONASH__0->SetFrameBorderMode(0);
   pYield_Beauty_MONASH__0->SetFrameBorderMode(0);
   
   TH1D *hFrame_Beauty_MONASH__1 = new TH1D("hFrame_Beauty_MONASH__1","",3,0.5,3.5);
   hFrame_Beauty_MONASH__1->SetMinimum(0.0021586);
   hFrame_Beauty_MONASH__1->SetMaximum(0.9030505);
   hFrame_Beauty_MONASH__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hFrame_Beauty_MONASH__1->SetLineColor(ci);
   hFrame_Beauty_MONASH__1->GetXaxis()->SetBinLabel(1,"B^{#pm}");
   hFrame_Beauty_MONASH__1->GetXaxis()->SetBinLabel(2,"B^{0}/#bar{B}^{0}");
   hFrame_Beauty_MONASH__1->GetXaxis()->SetBinLabel(3,"#Lambda_{b}^{0}/#bar{#Lambda}_{b}^{0}");
   hFrame_Beauty_MONASH__1->GetXaxis()->SetBit(TAxis::kLabelsVert);
   hFrame_Beauty_MONASH__1->GetXaxis()->SetLabelFont(42);
   hFrame_Beauty_MONASH__1->GetXaxis()->SetLabelOffset(0.006);
   hFrame_Beauty_MONASH__1->GetXaxis()->SetLabelSize(0.053);
   hFrame_Beauty_MONASH__1->GetXaxis()->SetTitleSize(0.05);
   hFrame_Beauty_MONASH__1->GetXaxis()->SetTitleOffset(1);
   hFrame_Beauty_MONASH__1->GetXaxis()->SetTitleFont(42);
   hFrame_Beauty_MONASH__1->GetYaxis()->SetTitle("Per-event yield");
   hFrame_Beauty_MONASH__1->GetYaxis()->SetLabelFont(42);
   hFrame_Beauty_MONASH__1->GetYaxis()->SetLabelSize(0.042);
   hFrame_Beauty_MONASH__1->GetYaxis()->SetTitleSize(0.05);
   hFrame_Beauty_MONASH__1->GetYaxis()->SetTitleOffset(1.25);
   hFrame_Beauty_MONASH__1->GetYaxis()->SetTitleFont(42);
   hFrame_Beauty_MONASH__1->GetZaxis()->SetLabelFont(42);
   hFrame_Beauty_MONASH__1->GetZaxis()->SetTitleOffset(1);
   hFrame_Beauty_MONASH__1->GetZaxis()->SetTitleFont(42);
   hFrame_Beauty_MONASH__1->Draw("");
   
   Double_t gYield_12-01-2026_Beauty_MONASH_fx1001[3] = { 1, 2, 3 };
   Double_t gYield_12-01-2026_Beauty_MONASH_fy1001[3] = { 0.6682562, 0.6686649, 0.05101853 };
   Double_t gYield_12-01-2026_Beauty_MONASH_fex1001[3] = { 0.5, 0.5, 0.5 };
   Double_t gYield_12-01-2026_Beauty_MONASH_fey1001[3] = { 0.0002554481, 0.0002614051, 8.569629e-05 };
   TGraphErrors *gre = new TGraphErrors(3,gYield_12-01-2026_Beauty_MONASH_fx1001,gYield_12-01-2026_Beauty_MONASH_fy1001,gYield_12-01-2026_Beauty_MONASH_fex1001,gYield_12-01-2026_Beauty_MONASH_fey1001);
   gre->SetName("gYield_12-01-2026_Beauty_MONASH");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0000cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0000cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYield_12mI01mI2026_Beauty_MONASH1001 = new TH1F("Graph_gYield_12mI01mI2026_Beauty_MONASH1001","Graph",100,0.2,3.8);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->SetMinimum(0.04583955);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->SetMaximum(0.7307256);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->SetDirectory(nullptr);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->SetLineColor(ci);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetXaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetXaxis()->SetLabelSize(0.042);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetXaxis()->SetTitleSize(0.05);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetXaxis()->SetTitleOffset(1);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetXaxis()->SetTitleFont(42);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetYaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetYaxis()->SetLabelSize(0.042);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetYaxis()->SetTitleSize(0.05);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetYaxis()->SetTitleFont(42);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetZaxis()->SetLabelFont(42);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetZaxis()->SetTitleOffset(1);
   Graph_gYield_12mI01mI2026_Beauty_MONASH1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYield_12-01-2026_Beauty_MONASH1001);
   
   gre->Draw("p ");
   
   Double_t gYield_27-03-2026_Beauty_MONASH_fx1002[3] = { 1, 2, 3 };
   Double_t gYield_27-03-2026_Beauty_MONASH_fy1002[3] = { 0.05681453, 0.05687126, 0.004317199 };
   Double_t gYield_27-03-2026_Beauty_MONASH_fex1002[3] = { 0.5, 0.5, 0.5 };
   Double_t gYield_27-03-2026_Beauty_MONASH_fey1002[3] = { 7.909341e-05, 8.437867e-05, 1.418328e-05 };
   gre = new TGraphErrors(3,gYield_27-03-2026_Beauty_MONASH_fx1002,gYield_27-03-2026_Beauty_MONASH_fy1002,gYield_27-03-2026_Beauty_MONASH_fex1002,gYield_27-03-2026_Beauty_MONASH_fey1002);
   gre->SetName("gYield_27-03-2026_Beauty_MONASH");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYield_27mI03mI2026_Beauty_MONASH1002 = new TH1F("Graph_gYield_27mI03mI2026_Beauty_MONASH1002","Graph",100,0.2,3.8);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->SetMinimum(0.003872715);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->SetMaximum(0.0622209);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->SetDirectory(nullptr);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->SetLineColor(ci);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetXaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetXaxis()->SetLabelSize(0.042);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetXaxis()->SetTitleSize(0.05);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetXaxis()->SetTitleOffset(1);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetXaxis()->SetTitleFont(42);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetYaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetYaxis()->SetLabelSize(0.042);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetYaxis()->SetTitleSize(0.05);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetYaxis()->SetTitleFont(42);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetZaxis()->SetLabelFont(42);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetZaxis()->SetTitleOffset(1);
   Graph_gYield_27mI03mI2026_Beauty_MONASH1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYield_27-03-2026_Beauty_MONASH1002);
   
   gre->Draw("p ");
   pYield_Beauty_MONASH__0->Modified();
   cYield_Beauty_MONASH->cd();
   TLatex *   tex = new TLatex(0.385,0.948,"Beauty MONASH Per-Event Yields");
   tex->SetNDC();
   tex->SetTextAlign(22);
   tex->SetTextSize(0.042);
   tex->SetLineWidth(2);
   tex->Draw();
  
// ------------>Primitives in pad: pRatio_Beauty_MONASH
   TPad *pRatio_Beauty_MONASH__1 = new TPad("pRatio_Beauty_MONASH", "",0.41,0.1,0.76,0.9);
   pRatio_Beauty_MONASH__1->Draw();
   pRatio_Beauty_MONASH__1->cd();
   pRatio_Beauty_MONASH__1->Range(-0.2012987,-3.126667,3.694805,15.54);
   pRatio_Beauty_MONASH__1->SetFillColor(0);
   pRatio_Beauty_MONASH__1->SetBorderMode(0);
   pRatio_Beauty_MONASH__1->SetBorderSize(2);
   pRatio_Beauty_MONASH__1->SetTickx(1);
   pRatio_Beauty_MONASH__1->SetTicky(1);
   pRatio_Beauty_MONASH__1->SetLeftMargin(0.18);
   pRatio_Beauty_MONASH__1->SetRightMargin(0.05);
   pRatio_Beauty_MONASH__1->SetTopMargin(0.07);
   pRatio_Beauty_MONASH__1->SetBottomMargin(0.22);
   pRatio_Beauty_MONASH__1->SetFrameBorderMode(0);
   pRatio_Beauty_MONASH__1->SetFrameBorderMode(0);
   
   TH1D *hRatioFrame_Beauty_MONASH__2 = new TH1D("hRatioFrame_Beauty_MONASH__2","",3,0.5,3.5);
   hRatioFrame_Beauty_MONASH__2->SetMinimum(0.98);
   hRatioFrame_Beauty_MONASH__2->SetMaximum(14.23333);
   hRatioFrame_Beauty_MONASH__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   hRatioFrame_Beauty_MONASH__2->SetLineColor(ci);
   hRatioFrame_Beauty_MONASH__2->GetXaxis()->SetBinLabel(1,"B^{#pm}");
   hRatioFrame_Beauty_MONASH__2->GetXaxis()->SetBinLabel(2,"B^{0}/#bar{B}^{0}");
   hRatioFrame_Beauty_MONASH__2->GetXaxis()->SetBinLabel(3,"#Lambda_{b}^{0}/#bar{#Lambda}_{b}^{0}");
   hRatioFrame_Beauty_MONASH__2->GetXaxis()->SetLabelFont(42);
   hRatioFrame_Beauty_MONASH__2->GetXaxis()->SetLabelOffset(0.006);
   hRatioFrame_Beauty_MONASH__2->GetXaxis()->SetLabelSize(0.053);
   hRatioFrame_Beauty_MONASH__2->GetXaxis()->SetTitleSize(0.05);
   hRatioFrame_Beauty_MONASH__2->GetXaxis()->SetTitleOffset(1);
   hRatioFrame_Beauty_MONASH__2->GetXaxis()->SetTitleFont(42);
   hRatioFrame_Beauty_MONASH__2->GetYaxis()->SetTitle("Independent / Combined");
   hRatioFrame_Beauty_MONASH__2->GetYaxis()->SetLabelFont(42);
   hRatioFrame_Beauty_MONASH__2->GetYaxis()->SetLabelSize(0.048);
   hRatioFrame_Beauty_MONASH__2->GetYaxis()->SetTitleSize(0.05);
   hRatioFrame_Beauty_MONASH__2->GetYaxis()->SetTitleOffset(1.35);
   hRatioFrame_Beauty_MONASH__2->GetYaxis()->SetTitleFont(42);
   hRatioFrame_Beauty_MONASH__2->GetZaxis()->SetLabelFont(42);
   hRatioFrame_Beauty_MONASH__2->GetZaxis()->SetTitleOffset(1);
   hRatioFrame_Beauty_MONASH__2->GetZaxis()->SetTitleFont(42);
   hRatioFrame_Beauty_MONASH__2->Draw("");
   TLine *line = new TLine(0.5,1,3.5,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   
   Double_t gYieldRatio_Beauty_MONASH_12-01-2026_fx1003[3] = { 1, 2, 3 };
   Double_t gYieldRatio_Beauty_MONASH_12-01-2026_fy1003[3] = { 11.76206, 11.75752, 11.81751 };
   Double_t gYieldRatio_Beauty_MONASH_12-01-2026_fex1003[3] = { 0.5, 0.5, 0.5 };
   Double_t gYieldRatio_Beauty_MONASH_12-01-2026_fey1003[3] = { 0.01698044, 0.01803978, 0.0436042 };
   gre = new TGraphErrors(3,gYieldRatio_Beauty_MONASH_12-01-2026_fx1003,gYieldRatio_Beauty_MONASH_12-01-2026_fy1003,gYieldRatio_Beauty_MONASH_12-01-2026_fex1003,gYieldRatio_Beauty_MONASH_12-01-2026_fey1003);
   gre->SetName("gYieldRatio_Beauty_MONASH_12-01-2026");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(24);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003 = new TH1F("Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003","Graph",100,0.2,3.8);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->SetMinimum(11.72732);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->SetMaximum(11.87327);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->SetDirectory(nullptr);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->SetLineColor(ci);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetXaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetXaxis()->SetLabelSize(0.042);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetXaxis()->SetTitleSize(0.05);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetXaxis()->SetTitleOffset(1);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetXaxis()->SetTitleFont(42);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetYaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetYaxis()->SetLabelSize(0.042);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetYaxis()->SetTitleSize(0.05);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetYaxis()->SetTitleFont(42);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetZaxis()->SetLabelFont(42);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetZaxis()->SetTitleOffset(1);
   Graph_gYieldRatio_Beauty_MONASH_12mI01mI20261003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_gYieldRatio_Beauty_MONASH_12-01-20261003);
   
   gre->Draw("p ");
   pRatio_Beauty_MONASH__1->Modified();
   cYield_Beauty_MONASH->cd();
  
// ------------>Primitives in pad: pLegend_Beauty_MONASH
   TPad *pLegend_Beauty_MONASH__2 = new TPad("pLegend_Beauty_MONASH", "",0.77,0.1,1,0.9);
   pLegend_Beauty_MONASH__2->Draw();
   pLegend_Beauty_MONASH__2->cd();
   pLegend_Beauty_MONASH__2->Range(0,0,1,1);
   pLegend_Beauty_MONASH__2->SetFillColor(0);
   pLegend_Beauty_MONASH__2->SetFillStyle(4000);
   pLegend_Beauty_MONASH__2->SetBorderMode(0);
   pLegend_Beauty_MONASH__2->SetBorderSize(2);
   pLegend_Beauty_MONASH__2->SetLeftMargin(0.04);
   pLegend_Beauty_MONASH__2->SetRightMargin(0.04);
   pLegend_Beauty_MONASH__2->SetTopMargin(0.07);
   pLegend_Beauty_MONASH__2->SetFrameFillStyle(0);
   pLegend_Beauty_MONASH__2->SetFrameLineColor(0);
   pLegend_Beauty_MONASH__2->SetFrameBorderMode(0);
   
   TLegend *leg = new TLegend(0.03,0.64,0.99,0.87,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.062);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gYield_12-01-2026_Beauty_MONASH","Independent Sample","pe");

   ci = TColor::GetColor("#0000cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("gYield_27-03-2026_Beauty_MONASH","Combined Sample","pe");

   ci = TColor::GetColor("#cc0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("gYieldRatio_Beauty_MONASH_12-01-2026","Independent / Combined","pe");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(24);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   leg->Draw();
   pLegend_Beauty_MONASH__2->Modified();
   cYield_Beauty_MONASH->cd();
      tex = new TLatex(0.385,0.06,"Particle species");
   tex->SetNDC();
   tex->SetTextAlign(22);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
   cYield_Beauty_MONASH->Modified();
   cYield_Beauty_MONASH->SetSelected(cYield_Beauty_MONASH);
}
