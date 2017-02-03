#include "../interface/Jet.h"

void
panda::Jet::datastore::allocate(UInt_t _nmax)
{
  MicroJet::datastore::allocate(_nmax);

  rawPt = new Float_t[nmax_];
  ptCorrUp = new Float_t[nmax_];
  ptCorrDown = new Float_t[nmax_];
  ptSmear = new Float_t[nmax_];
  ptSmearUp = new Float_t[nmax_];
  ptSmearDown = new Float_t[nmax_];
  nhf = new Float_t[nmax_];
  chf = new Float_t[nmax_];
  puid = new Float_t[nmax_];
  loose = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  monojet = new Bool_t[nmax_];
  matchedGenJet_ = new Int_t[nmax_];
  constituents_ = new std::vector<std::vector<Int_t>>(nmax_);
}

void
panda::Jet::datastore::deallocate()
{
  MicroJet::datastore::deallocate();

  delete [] rawPt;
  rawPt = 0;
  delete [] ptCorrUp;
  ptCorrUp = 0;
  delete [] ptCorrDown;
  ptCorrDown = 0;
  delete [] ptSmear;
  ptSmear = 0;
  delete [] ptSmearUp;
  ptSmearUp = 0;
  delete [] ptSmearDown;
  ptSmearDown = 0;
  delete [] nhf;
  nhf = 0;
  delete [] chf;
  chf = 0;
  delete [] puid;
  puid = 0;
  delete [] loose;
  loose = 0;
  delete [] tight;
  tight = 0;
  delete [] monojet;
  monojet = 0;
  delete [] matchedGenJet_;
  matchedGenJet_ = 0;
  delete constituents_;
  constituents_ = 0;
}

void
panda::Jet::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  MicroJet::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "rawPt", _branches);
  utils::setStatus(_tree, _name, "ptCorrUp", _branches);
  utils::setStatus(_tree, _name, "ptCorrDown", _branches);
  utils::setStatus(_tree, _name, "ptSmear", _branches);
  utils::setStatus(_tree, _name, "ptSmearUp", _branches);
  utils::setStatus(_tree, _name, "ptSmearDown", _branches);
  utils::setStatus(_tree, _name, "nhf", _branches);
  utils::setStatus(_tree, _name, "chf", _branches);
  utils::setStatus(_tree, _name, "puid", _branches);
  utils::setStatus(_tree, _name, "loose", _branches);
  utils::setStatus(_tree, _name, "tight", _branches);
  utils::setStatus(_tree, _name, "monojet", _branches);
  utils::setStatus(_tree, _name, "matchedGenJet_", _branches);
  utils::setStatus(_tree, _name, "constituents_", _branches);
}

void
panda::Jet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  MicroJet::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "rawPt", rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptCorrUp", ptCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptCorrDown", ptCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmear", ptSmear, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmearUp", ptSmearUp, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmearDown", ptSmearDown, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhf", nhf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chf", chf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puid", puid, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "monojet", monojet, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGenJet_", matchedGenJet_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "constituents_", &constituents_, _branches, _setStatus);
}

void
panda::Jet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  MicroJet::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "rawPt", size, 'F', rawPt, _branches);
  utils::book(_tree, _name, "ptCorrUp", size, 'F', ptCorrUp, _branches);
  utils::book(_tree, _name, "ptCorrDown", size, 'F', ptCorrDown, _branches);
  utils::book(_tree, _name, "ptSmear", size, 'F', ptSmear, _branches);
  utils::book(_tree, _name, "ptSmearUp", size, 'F', ptSmearUp, _branches);
  utils::book(_tree, _name, "ptSmearDown", size, 'F', ptSmearDown, _branches);
  utils::book(_tree, _name, "nhf", size, 'F', nhf, _branches);
  utils::book(_tree, _name, "chf", size, 'F', chf, _branches);
  utils::book(_tree, _name, "puid", size, 'F', puid, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "monojet", size, 'O', monojet, _branches);
  utils::book(_tree, _name, "matchedGenJet_", size, 'I', matchedGenJet_, _branches);
  utils::book(_tree, _name, "constituents_", "std::vector<std::vector<Int_t>>", &constituents_, _branches);
}

void
panda::Jet::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  MicroJet::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "rawPt");
  utils::resetAddress(_tree, _name, "ptCorrUp");
  utils::resetAddress(_tree, _name, "ptCorrDown");
  utils::resetAddress(_tree, _name, "ptSmear");
  utils::resetAddress(_tree, _name, "ptSmearUp");
  utils::resetAddress(_tree, _name, "ptSmearDown");
  utils::resetAddress(_tree, _name, "nhf");
  utils::resetAddress(_tree, _name, "chf");
  utils::resetAddress(_tree, _name, "puid");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "monojet");
  utils::resetAddress(_tree, _name, "matchedGenJet_");
  utils::resetAddress(_tree, _name, "constituents_");
}

void
panda::Jet::datastore::resizeVectors_(UInt_t _size)
{
  MicroJet::datastore::resizeVectors_(_size);

  constituents_->resize(_size);
}

panda::Jet::Jet(char const* _name/* = ""*/) :
  MicroJet(new JetArray(1, _name)),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptSmear(gStore.getData(this).ptSmear[0]),
  ptSmearUp(gStore.getData(this).ptSmearUp[0]),
  ptSmearDown(gStore.getData(this).ptSmearDown[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  puid(gStore.getData(this).puid[0]),
  loose(gStore.getData(this).loose[0]),
  tight(gStore.getData(this).tight[0]),
  monojet(gStore.getData(this).monojet[0]),
  matchedGenJet(gStore.getData(this).matchedGenJetContainer_, gStore.getData(this).matchedGenJet_[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
}

panda::Jet::Jet(datastore& _data, UInt_t _idx) :
  MicroJet(_data, _idx),
  rawPt(_data.rawPt[_idx]),
  ptCorrUp(_data.ptCorrUp[_idx]),
  ptCorrDown(_data.ptCorrDown[_idx]),
  ptSmear(_data.ptSmear[_idx]),
  ptSmearUp(_data.ptSmearUp[_idx]),
  ptSmearDown(_data.ptSmearDown[_idx]),
  nhf(_data.nhf[_idx]),
  chf(_data.chf[_idx]),
  puid(_data.puid[_idx]),
  loose(_data.loose[_idx]),
  tight(_data.tight[_idx]),
  monojet(_data.monojet[_idx]),
  matchedGenJet(_data.matchedGenJetContainer_, _data.matchedGenJet_[_idx]),
  constituents(_data.constituentsContainer_, (*_data.constituents_)[_idx])
{
}

panda::Jet::Jet(Jet const& _src) :
  MicroJet(new JetArray(1, gStore.getName(&_src))),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptSmear(gStore.getData(this).ptSmear[0]),
  ptSmearUp(gStore.getData(this).ptSmearUp[0]),
  ptSmearDown(gStore.getData(this).ptSmearDown[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  puid(gStore.getData(this).puid[0]),
  loose(gStore.getData(this).loose[0]),
  tight(gStore.getData(this).tight[0]),
  monojet(gStore.getData(this).monojet[0]),
  matchedGenJet(gStore.getData(this).matchedGenJetContainer_, gStore.getData(this).matchedGenJet_[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
  MicroJet::operator=(_src);

  rawPt = _src.rawPt;
  ptCorrUp = _src.ptCorrUp;
  ptCorrDown = _src.ptCorrDown;
  ptSmear = _src.ptSmear;
  ptSmearUp = _src.ptSmearUp;
  ptSmearDown = _src.ptSmearDown;
  nhf = _src.nhf;
  chf = _src.chf;
  puid = _src.puid;
  loose = _src.loose;
  tight = _src.tight;
  monojet = _src.monojet;
  matchedGenJet = _src.matchedGenJet;
  constituents = _src.constituents;
}

panda::Jet::Jet(ArrayBase* _array) :
  MicroJet(_array),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptSmear(gStore.getData(this).ptSmear[0]),
  ptSmearUp(gStore.getData(this).ptSmearUp[0]),
  ptSmearDown(gStore.getData(this).ptSmearDown[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  puid(gStore.getData(this).puid[0]),
  loose(gStore.getData(this).loose[0]),
  tight(gStore.getData(this).tight[0]),
  monojet(gStore.getData(this).monojet[0]),
  matchedGenJet(gStore.getData(this).matchedGenJetContainer_, gStore.getData(this).matchedGenJet_[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
}

panda::Jet::~Jet()
{
  destructor();
  gStore.free(this);
}

void
panda::Jet::destructor()
{
  /* BEGIN CUSTOM Jet.cc.destructor */
  /* END CUSTOM */

  MicroJet::destructor();
}

panda::Jet&
panda::Jet::operator=(Jet const& _src)
{
  MicroJet::operator=(_src);

  rawPt = _src.rawPt;
  ptCorrUp = _src.ptCorrUp;
  ptCorrDown = _src.ptCorrDown;
  ptSmear = _src.ptSmear;
  ptSmearUp = _src.ptSmearUp;
  ptSmearDown = _src.ptSmearDown;
  nhf = _src.nhf;
  chf = _src.chf;
  puid = _src.puid;
  loose = _src.loose;
  tight = _src.tight;
  monojet = _src.monojet;
  matchedGenJet = _src.matchedGenJet;
  constituents = _src.constituents;

  return *this;
}

void
panda::Jet::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  MicroJet::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "rawPt", _branches);
  utils::setStatus(_tree, _name, "ptCorrUp", _branches);
  utils::setStatus(_tree, _name, "ptCorrDown", _branches);
  utils::setStatus(_tree, _name, "ptSmear", _branches);
  utils::setStatus(_tree, _name, "ptSmearUp", _branches);
  utils::setStatus(_tree, _name, "ptSmearDown", _branches);
  utils::setStatus(_tree, _name, "nhf", _branches);
  utils::setStatus(_tree, _name, "chf", _branches);
  utils::setStatus(_tree, _name, "puid", _branches);
  utils::setStatus(_tree, _name, "loose", _branches);
  utils::setStatus(_tree, _name, "tight", _branches);
  utils::setStatus(_tree, _name, "monojet", _branches);
  utils::setStatus(_tree, _name, "matchedGenJet_", _branches);
  utils::setStatus(_tree, _name, "constituents_", _branches);
}

void
panda::Jet::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  MicroJet::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "rawPt", &rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptCorrUp", &ptCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptCorrDown", &ptCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmear", &ptSmear, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmearUp", &ptSmearUp, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmearDown", &ptSmearDown, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhf", &nhf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chf", &chf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puid", &puid, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", &loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", &tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "monojet", &monojet, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGenJet_", gStore.getData(this).matchedGenJet_, _branches, true);
  utils::setAddress(_tree, _name, "constituents_", &constituents.indices(), _branches, true);
}

void
panda::Jet::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  MicroJet::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "rawPt", "", 'F', &rawPt, _branches);
  utils::book(_tree, _name, "ptCorrUp", "", 'F', &ptCorrUp, _branches);
  utils::book(_tree, _name, "ptCorrDown", "", 'F', &ptCorrDown, _branches);
  utils::book(_tree, _name, "ptSmear", "", 'F', &ptSmear, _branches);
  utils::book(_tree, _name, "ptSmearUp", "", 'F', &ptSmearUp, _branches);
  utils::book(_tree, _name, "ptSmearDown", "", 'F', &ptSmearDown, _branches);
  utils::book(_tree, _name, "nhf", "", 'F', &nhf, _branches);
  utils::book(_tree, _name, "chf", "", 'F', &chf, _branches);
  utils::book(_tree, _name, "puid", "", 'F', &puid, _branches);
  utils::book(_tree, _name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, _name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, _name, "monojet", "", 'O', &monojet, _branches);
  utils::book(_tree, _name, "matchedGenJet_", "", 'I', gStore.getData(this).matchedGenJet_, _branches);
  utils::book(_tree, _name, "constituents_", "std::vector<Int_t>", &constituents.indices(), _branches);
}

void
panda::Jet::doReleaseTree_(TTree& _tree, TString const& _name)
{
  MicroJet::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "rawPt");
  utils::resetAddress(_tree, _name, "ptCorrUp");
  utils::resetAddress(_tree, _name, "ptCorrDown");
  utils::resetAddress(_tree, _name, "ptSmear");
  utils::resetAddress(_tree, _name, "ptSmearUp");
  utils::resetAddress(_tree, _name, "ptSmearDown");
  utils::resetAddress(_tree, _name, "nhf");
  utils::resetAddress(_tree, _name, "chf");
  utils::resetAddress(_tree, _name, "puid");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "monojet");
  utils::resetAddress(_tree, _name, "matchedGenJet_");
  utils::resetAddress(_tree, _name, "constituents_");
}

void
panda::Jet::doInit_()
{
  MicroJet::doInit_();

  rawPt = 0.;
  ptCorrUp = 0.;
  ptCorrDown = 0.;
  ptSmear = 0.;
  ptSmearUp = 0.;
  ptSmearDown = 0.;
  nhf = 0.;
  chf = 0.;
  puid = 0.;
  loose = false;
  tight = false;
  monojet = false;
  matchedGenJet.init();
  constituents.init();
}

/* BEGIN CUSTOM Jet.cc.global */
/* END CUSTOM */