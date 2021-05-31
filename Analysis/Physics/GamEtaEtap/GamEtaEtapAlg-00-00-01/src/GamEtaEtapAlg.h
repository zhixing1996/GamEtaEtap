#ifndef Physics_Analysis_GamEtaEtap_H
#define Physics_Analysis_GamEtaEtap_H 

#include "GaudiKernel/Algorithm.h"
#include "GaudiKernel/DeclareFactoryEntries.h"
#include "GaudiKernel/LoadFactoryEntries.h"
#include "GaudiKernel/INTupleSvc.h"
#include "GaudiKernel/NTuple.h"
#include "GaudiKernel/ISvcLocator.h"
#include "GaudiKernel/PropertyMgr.h"
#include "GaudiKernel/SmartDataPtr.h"
#include "GaudiKernel/Service.h"
#include "GaudiKernel/MsgStream.h"
#include "GaudiKernel/PropertyMgr.h"
#include "DatabaseSvc/IDatabaseSvc.h"

// don't know their functions
#include "GaudiKernel/Bootstrap.h"
#include "GaudiKernel/IDataProviderSvc.h"
#include "GaudiKernel/IHistogramSvc.h"
#include "EventModel/Event.h"
/////////////////////////////

#include "EventModel/EventModel.h"
#include "EventModel/EventHeader.h"

#include "EvtRecEvent/EvtRecEvent.h"
#include "EvtRecEvent/EvtRecTrack.h"
#include "EvtRecEvent/EvtRecDTag.h"
#include "EvtRecEvent/EvtRecPi0.h"
#include "EvtRecEvent/EvtRecVeeVertex.h"
#include "MdcRecEvent/RecMdcKalTrack.h"
#include "DTagTool/DTagTool.h"

#include "VertexFit/KinematicFit.h"
#include "VertexFit/VertexFit.h"
#include "VertexFit/IVertexDbSvc.h"
#include "VertexFit/SecondVertexFit.h"
#include "VertexFit/Helix.h"
#include "VertexFit/WTrackParameter.h"
#include "ParticleID/ParticleID.h"

#include "McTruth/McParticle.h"

#include "TMath.h"
#include "TLorentzVector.h"
#include <vector>
#include <TTree.h>

#include "CLHEP/Vector/LorentzVector.h"
#include "CLHEP/Vector/ThreeVector.h"
using CLHEP::Hep3Vector;
using CLHEP::HepLorentzVector;
typedef std::vector<HepLorentzVector> Vp4;
typedef std::vector<int> Vint;
typedef std::vector<WTrackParameter> VWTrkPara;

class GamEtaEtap : public Algorithm {

    public:
        GamEtaEtap(const std::string& name, ISvcLocator* pSvcLocator);
        StatusCode initialize();
        StatusCode execute();
        StatusCode finalize();  

    private:
        std::vector<int> m_DModes;
        bool m_isMonteCarlo;
        bool m_pid;
        bool m_debug;
        double m_Ecms;

        // common info
        int runNo;
        int evtNo;

        // Ntuple1 info
        NTuple::Tuple* m_tuple1;
        NTuple::Item<int> m_runNo;
        NTuple::Item<int> m_evtNo;
};
#endif
