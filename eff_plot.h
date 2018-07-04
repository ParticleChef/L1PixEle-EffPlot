//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jul 18 01:34:29 2016 by ROOT version 6.04/08
// from TTree t/t
// found on file: Result_all.root
//////////////////////////////////////////////////////////

#ifndef eff_plot_h
#define eff_plot_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

class eff_plot {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           totalEvent;
   Float_t         totalEgN;
   Int_t           ntnEg2;
   Int_t           event_with_selection_passed;
   Int_t           event_with_trigger_passed;
   vector<float>   *ntEgEt;
   vector<float>   *ntEgEta;
   vector<float>   *ntEgPhi;
   vector<float>   *ntL1TkEleEt;
   vector<float>   *ntL1TkEleEta;
   vector<float>   *ntL1TkElePhi;
   vector<float>   *ntL1TkEleIsoEt;
   vector<float>   *ntL1TkEleIsoEta;
   vector<float>   *ntL1TkEleIsoPhi;
   vector<bool>    *ntCl_match;
   vector<bool>    *isTrack_match;
   vector<float>   *chi2;
   vector<float>   *track_dr;
   vector<bool>    *ntCl_match_wo4thPix;
   vector<bool>    *ntCl_match_wo3thPix;
   vector<bool>    *ntCl_match_wo2thPix;
   vector<bool>    *ntCl_match_wo1thPix;
   vector<bool>    *withoutEM_match;
   vector<bool>    *withEM_match;
   vector<int>     *Npass_woEM_Ele_wo4thPix;
   vector<int>     *Npass_woEM_Ele_wo3thPix;
   vector<int>     *Npass_woEM_Ele_wo2thPix;
   vector<int>     *Npass_woEM_Ele_wo1thPix;
   vector<int>     *Npass_wEM_Ele_wo4thPix;
   vector<int>     *Npass_wEM_Ele_wo3thPix;
   vector<int>     *Npass_wEM_Ele_wo2thPix;
   vector<int>     *Npass_wEM_Ele_wo1thPix;
   vector<int>     *ntfirstPix;
   vector<int>     *ntsecondPix;
   vector<int>     *ntthirdPix;
   vector<int>     *ntfourthPix;
   Float_t         nt_genPhi;
   Float_t         nt_genEta;
   Float_t         nt_genPt;
   Float_t         nt_genVz;
   Float_t         nt_lastSimtkpt;
   Float_t         nt_initialSimtkpt;
   vector<int>     *trigger_bit_width;
   vector<bool>     *PiXTRKbit_4Hits;
   vector<int>     *pix_comb;
   vector<int>     *PiXTRKbit;

   // List of branches
   TBranch        *b_count_Entry;   //!
   TBranch        *b_EgN;   //!
   TBranch        *b_ntnEg2;   //!
   TBranch        *b_event_denominator;   //!
   TBranch        *b_event_nominator;   //!
   TBranch        *b_ntEgEt;   //!
   TBranch        *b_ntEgEta;   //!
   TBranch        *b_ntEgPhi;   //!
   TBranch        *b_ntL1TkEleEt;   //!
   TBranch        *b_ntL1TkEleEta;   //!
   TBranch        *b_ntL1TkElePhi;   //!
   TBranch        *b_ntL1TkEleIsoEt;   //!
   TBranch        *b_ntL1TkEleIsoEta;   //!
   TBranch        *b_ntL1TkEleIsoPhi;   //!
   TBranch        *b_ntCl_match;   //!
   TBranch        *b_isTrack_match;   //!
   TBranch        *b_chi2;   //!
   TBranch        *b_track_dr;   //!
   TBranch        *b_ntCl_match_wo4thPix;   //!
   TBranch        *b_ntCl_match_wo3thPix;   //!
   TBranch        *b_ntCl_match_wo2thPix;   //!
   TBranch        *b_ntCl_match_wo1thPix;   //!
   TBranch        *b_withoutEM_match;   //!
   TBranch        *b_withEM_match;   //!
   TBranch        *b_Npass_woEM_Ele_wo4thPix;   //!
   TBranch        *b_Npass_woEM_Ele_wo3thPix;   //!
   TBranch        *b_Npass_woEM_Ele_wo2thPix;   //!
   TBranch        *b_Npass_woEM_Ele_wo1thPix;   //!
   TBranch        *b_Npass_wEM_Ele_wo4thPix;   //!
   TBranch        *b_Npass_wEM_Ele_wo3thPix;   //!
   TBranch        *b_Npass_wEM_Ele_wo2thPix;   //!
   TBranch        *b_Npass_wEM_Ele_wo1thPix;   //!
   TBranch        *b_ntfirstPix;   //!
   TBranch        *b_ntsecondPix;   //!
   TBranch        *b_ntthirdPix;   //!
   TBranch        *b_ntfourthPix;   //!
   TBranch        *b_nt_genPhi;   //!
   TBranch        *b_nt_genEta;   //!
   TBranch        *b_nt_genPt;   //!
   TBranch        *b_nt_genVz;   //!
   TBranch        *b_nt_lastSimtkpt;   //!
   TBranch        *b_nt_initialSimtkpt;   //!
   TBranch        *b_trigger_bit_width;   //!
   TBranch        *b_PiXTRKbit_4Hits;   //!
   TBranch        *b_pix_comb;   //!
   TBranch        *b_PiXTRKbit;

   eff_plot(TTree *tree=0);
   virtual ~eff_plot();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef eff_plot_cxx
eff_plot::eff_plot(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/Volumes/Samsung_T3/Pixel_plots/CMSSW_9_3_2/PiXTRK_withoutBS/test_.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/Volumes/Samsung_T3/Pixel_plots/CMSSW_9_3_2/PiXTRK_withoutBS/test_.root");
      }
      f->GetObject("t",tree);

   }
   Init(tree);
}

eff_plot::~eff_plot()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t eff_plot::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t eff_plot::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void eff_plot::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   ntEgEt = 0;
   ntEgEta = 0;
   ntEgPhi = 0;
   ntL1TkEleEt = 0;
   ntL1TkEleEta = 0;
   ntL1TkElePhi = 0;
   ntL1TkEleIsoEt = 0;
   ntL1TkEleIsoEta = 0;
   ntL1TkEleIsoPhi = 0;
   ntCl_match = 0;
   isTrack_match = 0;
   chi2 = 0;
   track_dr = 0;
   ntCl_match_wo4thPix = 0;
   ntCl_match_wo3thPix = 0;
   ntCl_match_wo2thPix = 0;
   ntCl_match_wo1thPix = 0;
   withoutEM_match = 0;
   withEM_match = 0;
   Npass_woEM_Ele_wo4thPix = 0;
   Npass_woEM_Ele_wo3thPix = 0;
   Npass_woEM_Ele_wo2thPix = 0;
   Npass_woEM_Ele_wo1thPix = 0;
   Npass_wEM_Ele_wo4thPix = 0;
   Npass_wEM_Ele_wo3thPix = 0;
   Npass_wEM_Ele_wo2thPix = 0;
   Npass_wEM_Ele_wo1thPix = 0;
   ntfirstPix = 0;
   ntsecondPix = 0;
   ntthirdPix = 0;
   ntfourthPix = 0;
   trigger_bit_width = 0;
   PiXTRKbit_4Hits = 0;
   pix_comb = 0;
   PiXTRKbit = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("totalEvent", &totalEvent, &b_count_Entry);
   fChain->SetBranchAddress("totalEgN", &totalEgN, &b_EgN);
   fChain->SetBranchAddress("ntnEg2", &ntnEg2, &b_ntnEg2);
   fChain->SetBranchAddress("event_with_selection_passed", &event_with_selection_passed, &b_event_denominator);
   fChain->SetBranchAddress("event_with_trigger_passed", &event_with_trigger_passed, &b_event_nominator);
   fChain->SetBranchAddress("ntEgEt", &ntEgEt, &b_ntEgEt);
   fChain->SetBranchAddress("ntEgEta", &ntEgEta, &b_ntEgEta);
   fChain->SetBranchAddress("ntEgPhi", &ntEgPhi, &b_ntEgPhi);
   fChain->SetBranchAddress("ntL1TkEleEt", &ntL1TkEleEt, &b_ntL1TkEleEt);
   fChain->SetBranchAddress("ntL1TkEleEta", &ntL1TkEleEta, &b_ntL1TkEleEta);
   fChain->SetBranchAddress("ntL1TkElePhi", &ntL1TkElePhi, &b_ntL1TkElePhi);
   fChain->SetBranchAddress("ntL1TkEleIsoEt", &ntL1TkEleIsoEt, &b_ntL1TkEleIsoEt);
   fChain->SetBranchAddress("ntL1TkEleIsoEta", &ntL1TkEleIsoEta, &b_ntL1TkEleIsoEta);
   fChain->SetBranchAddress("ntL1TkEleIsoPhi", &ntL1TkEleIsoPhi, &b_ntL1TkEleIsoPhi);
   fChain->SetBranchAddress("ntCl_match", &ntCl_match, &b_ntCl_match);
   fChain->SetBranchAddress("isTrack_match", &isTrack_match, &b_isTrack_match);
   fChain->SetBranchAddress("chi2", &chi2, &b_chi2);
   fChain->SetBranchAddress("track_dr", &track_dr, &b_track_dr);
   fChain->SetBranchAddress("ntCl_match_wo4thPix", &ntCl_match_wo4thPix, &b_ntCl_match_wo4thPix);
   fChain->SetBranchAddress("ntCl_match_wo3thPix", &ntCl_match_wo3thPix, &b_ntCl_match_wo3thPix);
   fChain->SetBranchAddress("ntCl_match_wo2thPix", &ntCl_match_wo2thPix, &b_ntCl_match_wo2thPix);
   fChain->SetBranchAddress("ntCl_match_wo1thPix", &ntCl_match_wo1thPix, &b_ntCl_match_wo1thPix);
   fChain->SetBranchAddress("withoutEM_match", &withoutEM_match, &b_withoutEM_match);
   fChain->SetBranchAddress("withEM_match", &withEM_match, &b_withEM_match);
   fChain->SetBranchAddress("Npass_woEM_Ele_wo4thPix", &Npass_woEM_Ele_wo4thPix, &b_Npass_woEM_Ele_wo4thPix);
   fChain->SetBranchAddress("Npass_woEM_Ele_wo3thPix", &Npass_woEM_Ele_wo3thPix, &b_Npass_woEM_Ele_wo3thPix);
   fChain->SetBranchAddress("Npass_woEM_Ele_wo2thPix", &Npass_woEM_Ele_wo2thPix, &b_Npass_woEM_Ele_wo2thPix);
   fChain->SetBranchAddress("Npass_woEM_Ele_wo1thPix", &Npass_woEM_Ele_wo1thPix, &b_Npass_woEM_Ele_wo1thPix);
   fChain->SetBranchAddress("Npass_wEM_Ele_wo4thPix", &Npass_wEM_Ele_wo4thPix, &b_Npass_wEM_Ele_wo4thPix);
   fChain->SetBranchAddress("Npass_wEM_Ele_wo3thPix", &Npass_wEM_Ele_wo3thPix, &b_Npass_wEM_Ele_wo3thPix);
   fChain->SetBranchAddress("Npass_wEM_Ele_wo2thPix", &Npass_wEM_Ele_wo2thPix, &b_Npass_wEM_Ele_wo2thPix);
   fChain->SetBranchAddress("Npass_wEM_Ele_wo1thPix", &Npass_wEM_Ele_wo1thPix, &b_Npass_wEM_Ele_wo1thPix);
   fChain->SetBranchAddress("ntfirstPix", &ntfirstPix, &b_ntfirstPix);
   fChain->SetBranchAddress("ntsecondPix", &ntsecondPix, &b_ntsecondPix);
   fChain->SetBranchAddress("ntthirdPix", &ntthirdPix, &b_ntthirdPix);
   fChain->SetBranchAddress("ntfourthPix", &ntfourthPix, &b_ntfourthPix);
   fChain->SetBranchAddress("nt_genPhi", &nt_genPhi, &b_nt_genPhi);
   fChain->SetBranchAddress("nt_genEta", &nt_genEta, &b_nt_genEta);
   fChain->SetBranchAddress("nt_genPt", &nt_genPt, &b_nt_genPt);
   fChain->SetBranchAddress("nt_genVz", &nt_genVz, &b_nt_genVz);
   fChain->SetBranchAddress("nt_lastSimtkpt", &nt_lastSimtkpt, &b_nt_lastSimtkpt);
   fChain->SetBranchAddress("nt_initialSimtkpt", &nt_initialSimtkpt, &b_nt_initialSimtkpt);
   fChain->SetBranchAddress("trigger_bit_width", &trigger_bit_width, &b_trigger_bit_width);
   fChain->SetBranchAddress("PiXTRKbit_4Hits", &PiXTRKbit_4Hits, &b_PiXTRKbit_4Hits);
   fChain->SetBranchAddress("pix_comb", &pix_comb, &b_pix_comb);
   fChain->SetBranchAddress("PiXTRKbit", &PiXTRKbit, &b_PiXTRKbit);
   Notify();
}

Bool_t eff_plot::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void eff_plot::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t eff_plot::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef eff_plot_cxx
