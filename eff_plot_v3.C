#define eff_plot_cxx
#include "eff_plot.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TLatex.h>
#include <TLegend.h>
#include <TGraphAsymmErrors.h>

void eff_plot::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   //int nbins = 12; float x1 = -1.5; float x2 = 1.5;
   //int nbins = 24; float x1 = -3.0; float x2 = 3.0;
   int nbins = 60; float x1 = -3.0; float x2 = 3.0;

   TH1F* hEG_denom = new TH1F("hEG_denom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   TH1F* hEG_nom = new TH1F("hEG_nom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   hEG_nom->Sumw2();
   hEG_denom->Sumw2();

   TH1F* hPix_denom = new TH1F("hPix_denom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   TH1F* hPix_nom = new TH1F("hPix_nom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   hPix_nom->Sumw2();
   hPix_denom->Sumw2();

   TH1F* hPix4_denom = new TH1F("hPix4_denom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   TH1F* hPix4_nom = new TH1F("hPix4_nom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   hPix4_nom->Sumw2();
   hPix4_denom->Sumw2();

   TH1F* hTrk_denom = new TH1F("hTrk_denom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   TH1F* hTrk_nom = new TH1F("hTrk_nom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   hTrk_nom->Sumw2();
   hTrk_denom->Sumw2();

   TH1F* hPix123_denom = new TH1F("hPix123_denom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   TH1F* hPix123_nom = new TH1F("hPix123_nom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   hPix123_nom->Sumw2();
   hPix123_denom->Sumw2();

   TH1F* hPix124_denom = new TH1F("hPix124_denom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   TH1F* hPix124_nom = new TH1F("hPix124_nom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   hPix124_nom->Sumw2();
   hPix124_denom->Sumw2();

   TH1F* hPix134_denom = new TH1F("hPix134_denom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   TH1F* hPix134_nom = new TH1F("hPix134_nom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   hPix134_nom->Sumw2();
   hPix134_denom->Sumw2();

   TH1F* hPix234_denom = new TH1F("hPix234_denom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   TH1F* hPix234_nom = new TH1F("hPix234_nom",";#eta of generated electron; Efficiency",nbins,x1,x2);
   hPix234_nom->Sumw2();
   hPix234_denom->Sumw2();

   int nbins_pt = 46; float x1_pt = 8.; float x2_pt = 100.;   
//   int nbins_pt = 20; float x1_pt = 10.; float x2_pt = 50.;   
   TH1F* hEG_pt = new TH1F("hEG_pt",";P_{T} of generated electron; Efficiency",nbins_pt,x1_pt,x2_pt);
   TH1F* hPix_pt = new TH1F("hPix_pt",";P_{T} of generated electron [GeV]; Efficiency",nbins_pt,x1_pt,x2_pt);

   int width_bit[27] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000, 0x10000, 0x20000, 0x40000, 0x80000,
                        0x100000, 0x200000, 0x400000, 0x800000, 0x1000000, 0x2000000, 0x4000000};

   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<100;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if(nt_genPt < 20.) continue;
      if( fabs(nt_genEta) > 3.0 ) continue;
      //if( fabs(nt_genEta) > 1.479 ) continue;

      int eg_size = ntEgEt->size();
      int gen_matched_eg = -1;
      float dr = 999.;


      // find the closest L1 egamma to gen electron
      for(int i = 0; i < eg_size; i++){
         float temp_dr = sqrt(pow(nt_genPhi-ntEgPhi->at(i),2)+pow(nt_genEta-ntEgEta->at(i),2));
         if( temp_dr < dr){
           dr = temp_dr;
           gen_matched_eg = i;
         }
      }// eg loop
     
      float pt_err = 0.; 
      if(gen_matched_eg != -1) {pt_err = fabs(nt_genPt-ntEgEt->at(gen_matched_eg))/nt_genPt; }
      if( gen_matched_eg != -1 && pt_err < 0.5){
      //if( gen_matched_eg != -1){
        //if((trigger_bit_width->at(gen_matched_eg)&width_bit[17])==width_bit[17]) hPix_nom->Fill(nt_genEta, 1.);
        if((trigger_bit_width->at(gen_matched_eg)&width_bit[0])==width_bit[0]) hPix_nom->Fill(nt_genEta, 1.);
        //if(PiXTRKbit_4Hits->at(gen_matched_eg) ) hPix4_nom->Fill(nt_genEta, 1.);
        //if((pix_comb->at(gen_matched_eg)&0x2)==0x2) hPix123_nom->Fill(nt_genEta, 1.); 
        //if((pix_comb->at(gen_matched_eg)&0x4)==0x4) hPix124_nom->Fill(nt_genEta, 1.); 
        //if((pix_comb->at(gen_matched_eg)&0x8)==0x8) hPix134_nom->Fill(nt_genEta, 1.); 
        //if((pix_comb->at(gen_matched_eg)&0x10)==0x10) hPix234_nom->Fill(nt_genEta, 1.); 

        //if(isTrack_match->at(gen_matched_eg) && chi2->at(gen_matched_eg) < 100. && track_dr->at(gen_matched_eg) < 0.3) hTrk_nom->Fill(nt_genEta, 1.);
        //if(isTrack_match->at(gen_matched_eg) && chi2->at(gen_matched_eg) < 100.) hTrk_nom->Fill(nt_genEta, 1.);
        hEG_nom->Fill(nt_genEta, 1.);
      }

      hEG_denom->Fill(nt_genEta, 1.);
      hPix_denom->Fill(nt_genEta, 1.);
      //hPix4_denom->Fill(nt_genEta, 1.);
      //hTrk_denom->Fill(nt_genEta, 1.);
      //hPix123_denom->Fill(nt_genEta, 1.);
      //hPix124_denom->Fill(nt_genEta, 1.);
      //hPix134_denom->Fill(nt_genEta, 1.);
      //hPix234_denom->Fill(nt_genEta, 1.);

   }// events loop

   //hPix->Divide(hPix_nom,hPix_denom,1,1,"B");
   // divide the two histograms to plot efficiency 
   TGraphAsymmErrors* hEG = new TGraphAsymmErrors(hEG_nom, hEG_denom,"B");
   TGraphAsymmErrors* hPix = new TGraphAsymmErrors(hPix_nom, hPix_denom,"B");
   //TGraphAsymmErrors* hPix4 = new TGraphAsymmErrors(hPix4_nom, hPix4_denom,"B");
   //TGraphAsymmErrors* hPix123 = new TGraphAsymmErrors(hPix123_nom, hPix123_denom,"B");
   //TGraphAsymmErrors* hPix124 = new TGraphAsymmErrors(hPix124_nom, hPix124_denom,"B");
   //TGraphAsymmErrors* hPix134 = new TGraphAsymmErrors(hPix134_nom, hPix134_denom,"B");
   //TGraphAsymmErrors* hPix234 = new TGraphAsymmErrors(hPix234_nom, hPix234_denom,"B");
   //TGraphAsymmErrors* hTrk = new TGraphAsymmErrors(hTrk_nom, hTrk_denom,"B");

   //for(int pointNr=0;pointNr<hPix4->GetN();pointNr++){
   //  hPix4->SetPointEXhigh(pointNr,0);
   //  hPix4->SetPointEXlow(pointNr,0);

   //  hPix4->SetPointEYhigh(pointNr,0);
   //  hPix4->SetPointEYlow(pointNr,0);
   //}

   //for(int pointNr=0;pointNr<hEG->GetN();pointNr++){
   //  hEG->SetPointEXhigh(pointNr,0);
   //  hEG->SetPointEXlow(pointNr,0);
   //}

   //for(int pointNr=0;pointNr<hPix->GetN();pointNr++){
   //  hPix->SetPointEXhigh(pointNr,0);
   //  hPix->SetPointEXlow(pointNr,0);
   //}

   //for(int pointNr=0;pointNr<hTrk->GetN();pointNr++){
   //  hTrk->SetPointEXhigh(pointNr,0);
   //  hTrk->SetPointEXlow(pointNr,0);
   //}

   //for(int pointNr=0;pointNr<hPix123->GetN();pointNr++){
   //  hPix123->SetPointEXhigh(pointNr,0);
   //  hPix123->SetPointEXlow(pointNr,0);

   //  hPix123->SetPointEYhigh(pointNr,0);
   //  hPix123->SetPointEYlow(pointNr,0);
   //}

   //for(int pointNr=0;pointNr<hPix124->GetN();pointNr++){
   //  hPix124->SetPointEXhigh(pointNr,0);
   //  hPix124->SetPointEXlow(pointNr,0);

   //  hPix124->SetPointEYhigh(pointNr,0);
   //  hPix124->SetPointEYlow(pointNr,0);
   //} 

   //for(int pointNr=0;pointNr<hPix134->GetN();pointNr++){
   //  hPix134->SetPointEXhigh(pointNr,0);
   //  hPix134->SetPointEXlow(pointNr,0);

   //  hPix134->SetPointEYhigh(pointNr,0);
   //  hPix134->SetPointEYlow(pointNr,0);
   //} 

   //for(int pointNr=0;pointNr<hPix234->GetN();pointNr++){
   //  hPix234->SetPointEXhigh(pointNr,0);
   //  hPix234->SetPointEXlow(pointNr,0);

   //  hPix234->SetPointEYhigh(pointNr,0);
   //  hPix234->SetPointEYlow(pointNr,0);
   //}

   TCanvas *c1 = new TCanvas("c1","c1",1200,800);
   gStyle->SetOptStat(0);
   gStyle->SetLineWidth(1); // axis width, default is 1
   c1->SetTopMargin(0.05);
   c1->SetBottomMargin(0.12);
   c1->SetRightMargin(0.03);
   c1->SetLeftMargin(0.15);
   c1->SetGrid();
   c1->SetTicky(1);
   c1->SetTickx(1);
   c1->cd();

   //hPix->SetTitle("CMSSW_10_1_0_pre3, Phase 2, <PU>=0");
   hPix->GetXaxis()->SetTitle("#eta_{gen} ");
   hPix->GetXaxis()->SetTitleOffset(1.);
   hPix->GetXaxis()->SetTitleSize(0.055);
   hPix->GetXaxis()->SetNdivisions(510);
   hPix->GetYaxis()->SetNdivisions(506);
   hPix->GetXaxis()->SetLabelSize(0.05);
   hPix->GetYaxis()->SetLabelSize(0.05);
   //hPix->GetXaxis()->SetRangeUser(-1.7, 1.7);
   hPix->GetXaxis()->SetRangeUser(-3.0, 3.0);
   hPix->GetYaxis()->SetRangeUser(0.5, 1.1);
   hPix->GetYaxis()->SetTitle("Efficiency");
   hPix->GetYaxis()->SetTitleOffset(1.2);
   hPix->GetYaxis()->SetTitleSize(0.055);

   hPix->SetMarkerColor(4);
   hPix->SetLineColor(4);
   hPix->SetLineWidth(1);
   hPix->SetMarkerStyle(29);
   hPix->SetMarkerSize(1.8);
   hPix->Draw("ape");

   //hPix4->SetLineColor(4);
   //hPix4->SetLineWidth(1);
   //hPix4->SetMarkerStyle(30);
   //hPix4->Draw("l same");

   //hPix123->SetLineColor(6);
   //hPix123->SetLineWidth(1);
   //hPix123->SetLineStyle(7);
   //hPix123->Draw("l same");

   //hPix124->SetLineColor(7);
   //hPix124->SetLineWidth(1);
   //hPix124->SetLineStyle(7);
   //hPix124->Draw("l same");

   //hPix134->SetLineColor(3);
   //hPix134->SetLineWidth(1);
   //hPix134->SetLineStyle(7);
   //hPix134->Draw("l same");

   //hPix234->SetLineColor(1);
   //hPix234->SetLineWidth(1);
   //hPix234->SetLineStyle(7);
   //hPix234->Draw("l same");

   //hTrk->SetMarkerColor(1);
   //hTrk->SetLineColor(1);
   //hTrk->SetLineWidth(1);
   //hTrk->SetMarkerStyle(20);
   //hTrk->SetMarkerSize(1.);
   //hTrk->Draw("pe same");

   hEG->SetMarkerColor(2);
   hEG->SetLineColor(2);
   hEG->SetLineWidth(1);
   hEG->SetMarkerStyle(20);
   hEG->SetMarkerSize(1.);
   hEG->Draw("pe same");

   TLegend *Lgd = new TLegend(0.25, 0.9, 0.95, 0.95);

   Lgd-> SetNColumns(4);
   Lgd->SetFillColor(0);
   Lgd->SetTextFont(42);
   Lgd->SetTextSize(0.035);
   Lgd->SetBorderSize(0);
   Lgd->SetFillStyle(0);
   //Lgd->AddEntry(hEG,"Phase-2 L1 EG(barrel ECAL/ HGCAL)","lp");
   Lgd->AddEntry(hEG,"Phase-2 L1 EG","lp");
   Lgd->AddEntry(hPix,"Pixel matching","lp");
   //Lgd->AddEntry(hTrk,"L1 track matching","lp");
   //Lgd->AddEntry(hPix4,"Pixel matching(4 hits)","lp");
   //Lgd->AddEntry(hPix123,"L123 SW","lp");
   //Lgd->AddEntry(hPix124,"L124 SW","lp");
   //Lgd->AddEntry(hPix134,"L134 SW","lp");
   //Lgd->AddEntry(hPix234,"L234 SW","lp");
   Lgd->Draw();

   //TLatex t(0.1,1.28,"CMSSW_10_1_0_pre3, Phase 2, <PU>=200");
   TLatex t(0.,1.11,"CMSSW_10_1_0_pre3, Phase 2, <PU>=0");
   t.SetTextSize(0.035);
   t.Draw();

   TLatex pt_cut(2.,0.2,"p_{T}^{gen} > 20 GeV");
   pt_cut.SetTextSize(0.035);
   pt_cut.Draw();

   c1->Print("Eff.png");
}
