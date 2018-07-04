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

   TH1F* hPix_denom2 = new TH1F("hPix_denom2",";#eta of generated electron; Efficiency",nbins,x1,x2);
   TH1F* hPix_nom2 = new TH1F("hPix_nom2",";#eta of generated electron; Efficiency",nbins,x1,x2);
   hPix_nom2->Sumw2();
   hPix_denom2->Sumw2();

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

        //if((pix_comb->at(gen_matched_eg)&0x10)==0x10) hPix234_nom->Fill(nt_genEta, 1.); 

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
        if((trigger_bit_width->at(gen_matched_eg)&width_bit[0])==width_bit[0]) hPix_nom2->Fill(nt_genEta, 1.);
        if( ((PiXTRKbit->at(0)&0x2)!=0 && (PiXTRKbit->at(0)&0x4)!=0 && (PiXTRKbit->at(0)&0x8)!=0 && (PiXTRKbit->at(0)&0x10)==0) || 
            ((PiXTRKbit->at(0)&0x2)!=0 && (PiXTRKbit->at(0)&0x4)!=0 && (PiXTRKbit->at(0)&0x8)==0 && (PiXTRKbit->at(0)&0x10)!=0) || 
            ((PiXTRKbit->at(0)&0x2)!=0 && (PiXTRKbit->at(0)&0x4)==0 && (PiXTRKbit->at(0)&0x8)!=0 && (PiXTRKbit->at(0)&0x10)!=0) || 
            ((PiXTRKbit->at(0)&0x2)==0 && (PiXTRKbit->at(0)&0x4)!=0 && (PiXTRKbit->at(0)&0x8)!=0 && (PiXTRKbit->at(0)&0x10)!=0) ||
            ((PiXTRKbit->at(0)&0x2)!=0 && (PiXTRKbit->at(0)&0x4)!=0 && (PiXTRKbit->at(0)&0x8)!=0 && (PiXTRKbit->at(0)&0x10)!=0) 
//((PiXTRKbit->at(0)&0x2)!=0 && (PiXTRKbit->at(0)&0x4)!=0 && (PiXTRKbit->at(0)&0x8)==0 && (PiXTRKbit->at(0)&0x10)==0) ||  
//((PiXTRKbit->at(0)&0x2)!=0 && (PiXTRKbit->at(0)&0x4)==0 && (PiXTRKbit->at(0)&0x8)!=0 && (PiXTRKbit->at(0)&0x10)==0) ||
//((PiXTRKbit->at(0)&0x2)!=0 && (PiXTRKbit->at(0)&0x4)==0 && (PiXTRKbit->at(0)&0x8)==0 && (PiXTRKbit->at(0)&0x10)!=0) ||
//((PiXTRKbit->at(0)&0x2)==0 && (PiXTRKbit->at(0)&0x4)!=0 && (PiXTRKbit->at(0)&0x8)!=0 && (PiXTRKbit->at(0)&0x10)==0) ||
//((PiXTRKbit->at(0)&0x2)==0 && (PiXTRKbit->at(0)&0x4)!=0 && (PiXTRKbit->at(0)&0x8)==0 && (PiXTRKbit->at(0)&0x10)!=0) ||
//((PiXTRKbit->at(0)&0x2)==0 && (PiXTRKbit->at(0)&0x4)!=0 && (PiXTRKbit->at(0)&0x8)!=0 && (PiXTRKbit->at(0)&0x10)!=0) 
             ) hPix_nom->Fill(nt_genEta, 1.);


        hEG_nom->Fill(nt_genEta, 1.);
      }

      hEG_denom->Fill(nt_genEta, 1.);
      hPix_denom->Fill(nt_genEta, 1.);
      hPix_denom2->Fill(nt_genEta, 1.);

   }// events loop

   TGraphAsymmErrors* hEG = new TGraphAsymmErrors(hEG_nom, hEG_denom,"B");
   TGraphAsymmErrors* hPix = new TGraphAsymmErrors(hPix_nom, hPix_denom,"B");
   TGraphAsymmErrors* hPix2 = new TGraphAsymmErrors(hPix_nom2, hPix_denom2,"B");

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
   hPix->SetMarkerStyle(24);
   hPix->SetMarkerSize(1.);
   hPix->Draw("ape");

   hEG->SetMarkerColor(2);
   hEG->SetLineColor(2);
   hEG->SetLineWidth(1);
   hEG->SetMarkerStyle(20);
   hEG->SetMarkerSize(1.);
   hEG->Draw("pe same");

   hPix2->SetMarkerColor(4);
   hPix2->SetLineColor(4);
   hPix2->SetLineWidth(1);
   hPix2->SetMarkerStyle(20);
   hPix2->SetMarkerSize(1.);
   hPix2->Draw("pe same");

   TLegend *Lgd = new TLegend(0.35, 0.82, 0.9, 0.94);

   Lgd-> SetNColumns(1);
   Lgd->SetFillColor(0);
   Lgd->SetTextFont(42);
   Lgd->SetTextSize(0.035);
   Lgd->SetBorderSize(0);
   Lgd->SetFillStyle(0);
   //Lgd->AddEntry(hEG,"Phase-2 L1 EG(barrel ECAL/ HGCAL)","lp");
   Lgd->AddEntry(hEG,"Phase-2 L1 EG (crystal barrel and HGCAL endcap)","lp");
   Lgd->AddEntry(hPix,"At least 3 pixels in ROI","lp");
   Lgd->AddEntry(hPix2,"Pixel matching","lp");
   Lgd->Draw();

   //TLatex t(0.1,1.11,"CMSSW_10_1_0_pre3, Phase 2, <PU>=200");
   TLatex t(0.,1.11,"CMSSW_10_1_0_pre3, Phase 2, <PU>=0");
   t.SetTextSize(0.035);
   t.Draw();

   TLatex pt_cut(2.,0.2,"p_{T}^{gen} > 20 GeV");
   pt_cut.SetTextSize(0.035);
   pt_cut.Draw();

   c1->Print("Eff_bit.png");
}
//   float nth_bin_left_pt, nth_bin_right_pt;
//   for(int i = 0; i < 46; i++){
//      nth_bin_left_pt = x1_pt + (2*i) * 1.0; 
//      nth_bin_right_pt = x1_pt + (2*i + 2) * 1.0; 
//
//      float denominator = 0.; 
//      float nominator = 0.; 
//      float nominator_Pix = 0.; 
//      float nominator_Eg = 0.;
//      float nominator_matching = 0.; 
//
//      for (Long64_t jentry=0; jentry<nentries;jentry++) {
//         Long64_t ientry = LoadTree(jentry);
//         if (ientry < 0) break;
//         nb = fChain->GetEntry(jentry);   nbytes += nb;
//         // if (Cut(ientry) < 0) continue;
//
//        //if(!ntnEg2) continue;
//        if(nt_genPt < nth_bin_left_pt || nt_genPt > nth_bin_right_pt ) continue;
//        if(fabs(nt_genEta) > 1.479) continue;
//
//
//        int eg_size = ntEgEt->size(); 
//        int gen_matched_eg = -1; 
//        float dr = 999.; 
//        for(int i = 0; i < eg_size; i++){
//            float temp_dr = sqrt(pow(nt_genPhi-ntEgPhi->at(i),2)+pow(nt_genEta-ntEgEta->at(i),2));
//            if( temp_dr < dr){
//              dr = temp_dr;
//              gen_matched_eg = i;
//            }
//         }// eg loop
//         //if(dr > 0.1) continue;
//
//         if( gen_matched_eg != -1){
//              //if( ntEgEt->at(gen_matched_eg) > 20 ){
//                 nominator_Eg++;
//                 if( ntCl_match->at(gen_matched_eg) ) nominator_Pix++;
//              //}
//         }
//
//         //if(EgEt < 20) continue;
//         denominator++;
//
//
//      }// event loop
//
//       float efficiency_Eg = nominator_Eg / denominator;
//       float efficiency_Pix = nominator_Pix / denominator;
//
//       if(denominator==0){
//
//       hPix_pt->SetBinContent(i+1, 0.);
//       hPix_pt->SetBinError(i+1, 0.);
//
//       hEG_pt->SetBinContent(i+1, 0.);
//       hEG_pt->SetBinError(i+1, 0.);
//       }
//       else{
//       hPix_pt->SetBinContent(i+1, efficiency_Pix);
//       hPix_pt->SetBinError(i+1, sqrt( efficiency_Pix * (1-efficiency_Pix) / denominator) );
//
//       hEG_pt->SetBinContent(i+1, efficiency_Eg);
//       hEG_pt->SetBinError(i+1, sqrt( efficiency_Eg * (1-efficiency_Eg) / denominator) );
//       }
//
//
//   }// pt loop
//
//   TCanvas *c2 = new TCanvas("c2","c2",800,700);
//   gStyle->SetOptStat(0);
//   gStyle->SetLineWidth(2); // axis width, default is 1
//   c2->SetTopMargin(0.05);
//   c2->SetBottomMargin(0.12);
//   c2->SetRightMargin(0.03);
//   c2->SetLeftMargin(0.2);
//   c2->SetGrid();
//   c2->SetTicky(1);
//   c2->SetTickx(1);
//  
//   c2->cd();
//
//   hPix_pt->SetTitle("");
//   hPix_pt->GetXaxis()->CenterTitle(true);
//   hPix_pt->GetXaxis()->SetTitleOffset(1.3);
//   hPix_pt->GetXaxis()->SetTitleSize(0.045);
//   hPix_pt->GetXaxis()->SetNdivisions(510);
//   hPix_pt->GetYaxis()->SetNdivisions(506);
//   hPix_pt->GetXaxis()->SetLabelSize(0.05);
//   hPix_pt->GetYaxis()->SetLabelSize(0.05);
//   //hPix_pt->GetXaxis()->SetRangeUser(x1_pt,x2_pt);
//   hPix_pt->GetXaxis()->SetRangeUser(8.,x2_pt);
//   hPix_pt->GetYaxis()->SetRangeUser(0., 1.3);
//   hPix_pt->GetYaxis()->SetTitleOffset(1.5);
//   hPix_pt->GetYaxis()->SetTitleSize(0.050);
//
//   hPix_pt->SetMarkerColor(4);
//   hPix_pt->SetLineColor(4);
//   hPix_pt->SetLineWidth(2);
//   hPix_pt->SetMarkerStyle(29);
//   hPix_pt->SetMarkerSize(1.8);
//   hPix_pt->Draw("HIST e");
//
//
//   hEG_pt->SetTitle("");
//   hEG_pt->GetXaxis()->CenterTitle(true);
//   hEG_pt->GetXaxis()->SetTitleOffset(1.3);
//   hEG_pt->GetXaxis()->SetTitleSize(0.045);
//   hEG_pt->GetXaxis()->SetNdivisions(515);
//   hEG_pt->GetYaxis()->SetNdivisions(506);
//   hEG_pt->GetXaxis()->SetLabelSize(0.05);
//   hEG_pt->GetYaxis()->SetLabelSize(0.05);
//   hEG_pt->GetXaxis()->SetRangeUser(5.,x2_pt);
//   hEG_pt->GetYaxis()->SetRangeUser(0., 1.3);
//   hEG_pt->GetYaxis()->SetTitleOffset(1.5);
//   hEG_pt->GetYaxis()->SetTitleSize(0.050);
//
//   hEG_pt->SetMarkerColor(kRed);
//   hEG_pt->SetLineColor(kRed);
//   hEG_pt->SetLineWidth(2);
//   hEG_pt->SetMarkerStyle(20);
//   hEG_pt->SetMarkerSize(1.2);
//   //hEG_pt->Draw("ple same");
//   hEG_pt->Draw("ple");
//
//   TLegend *Lgd1 = new TLegend(0.35, 0.5, 0.8, 0.6);
//   Lgd1->SetFillColor(0);
//   Lgd1->SetTextFont(42);
//   Lgd1->SetTextSize(0.04);
//   Lgd1->SetBorderSize(1);
//   Lgd1->AddEntry(hPix_pt,"L1 Pixel Detector","lp");
//   //Lgd1->Draw();
//
//   TLatex t1(25.,1.33,"CMS Preliminary Simulation, Phase 2, <PU>=200");
//   t1.SetTextSize(0.035);
//   t1.Draw();
//
//   TLatex eta_range(80,0.75,"#lbar#bf{#eta}#lbar < 1.479");
//   eta_range.SetTextSize(0.045);
//   eta_range.Draw();
//
//   c2->Print("Eff_pt.png");
//   file->Write();
//
//}
