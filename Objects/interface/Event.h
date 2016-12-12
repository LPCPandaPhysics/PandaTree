#ifndef PandaTree_Objects_Event_h
#define PandaTree_Objects_Event_h
#include "../../Framework/interface/TreeEntry.h"
#include "Constants.h"
#include "PFCand.h"
#include "SuperCluster.h"
#include "Electron.h"
#include "Muon.h"
#include "Tau.h"
#include "Photon.h"
#include "Jet.h"
#include "FatJet.h"
#include "MicroJet.h"
#include "GenJet.h"
#include "GenParticle.h"
#include "RecoMET.h"
#include "MET.h"
#include "METFilters.h"
#include "HLTBits.h"

namespace panda {

  class Event : public TreeEntry {
  public:
    Event();
    Event(Event const&);
    ~Event() {}
    Event& operator=(Event const&);

    void init() override;

    double reweight(UInt_t i) const { return 1. + reweightDW[i]; }

    PFCandCollection pfCandidates = PFCandCollection("pfCandidates", 256);
    SuperClusterCollection superClusters = SuperClusterCollection("superClusters", 64);
    ElectronCollection electrons = ElectronCollection("electrons", 32);
    MuonCollection muons = MuonCollection("muons", 32);
    TauCollection taus = TauCollection("taus", 64);
    PhotonCollection photons = PhotonCollection("photons", 32);
    JetCollection chsAK4Jets = JetCollection("chsAK4Jets", 64);
    JetCollection puppiAK4Jets = JetCollection("puppiAK4Jets", 64);
    FatJetCollection chsAK8Jets = FatJetCollection("chsAK8Jets", 8);
    FatJetCollection chsCA15Jets = FatJetCollection("chsCA15Jets", 8);
    FatJetCollection puppiAK8Jets = FatJetCollection("puppiAK8Jets", 8);
    FatJetCollection puppiCA15Jets = FatJetCollection("puppiCA15Jets", 8);
    MicroJetCollection subjets = MicroJetCollection("subjets", 64);
    GenJetCollection genJets = GenJetCollection("genJets", 64);
    GenParticleCollection genParticles = GenParticleCollection("genParticles", 128);
    RecoMET met = RecoMET("met");
    MET rawMet = MET("rawMet");
    MET caloMet = MET("caloMet");
    MET noMuMet = MET("noMuMet");
    MET noHFMet = MET("noHFMet");
    MET trkMet = MET("trkMet");
    MET neutralMet = MET("neutralMet");
    MET photonMet = MET("photonMet");
    MET hfMet = MET("hfMet");
    MET genMet = MET("genMet");
    METFilters metFilters = METFilters("metFilters");
    HLTBits triggers = HLTBits("triggers");

    UInt_t runNumber{};
    UInt_t lumiNumber{};
    UInt_t eventNumber{};
    Bool_t isData{};
    UShort_t npv{};
    UShort_t npvTrue{};
    Float_t rho{};
    Float_t rhoCentralCalo{};
    Float_t weight{};
    Float_t reweightDW[512]{};

  protected:
    void doSetStatus_(TTree&, Bool_t, utils::BranchList const&) override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doReleaseTree_(TTree&) override;
    void adjustCollectionSizes_() override;

  public:
    /* BEGIN CUSTOM Event.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM Event.h.global */
  /* END CUSTOM */

}

#endif
