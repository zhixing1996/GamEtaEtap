// -*- C++ -*- //
//
// Description: ee -> DD(2420) -> DDPIPI
//
// Original Author:  Maoqiang JING <jingmq@ihep.ac.cn>
//         Created:  [2019-08-08 Thu 15:09] 
//         Inspired by Suyu XIAO's code 
// 
//

#include "GamEtaEtapAlg.h"

const double PI = 3.1415927;
const double M_Pi0 = 0.1349766;
const double M_D0 = 1.86483;
const double M_Dplus = 1.86965;
const double M_Dst = 2.01026;
const double mass[5] = {
    0.000511, 0.105658, 0.139570, 0.493677, 0.938272 // e, mu, pi, K, p
};
int Ncut0, Ncut1, Ncut2, Ncut3, Ncut4, Ncut5, Ncut6, Ncut7, Ncut8, Ncut9, Ncut10, Ncut11, Ncut12, Ncut13, Ncut14, Ncut15, Ncut16, Ncut17, Ncut18, Ncut19, Ncut20;

// 
// module declare
//

VertexFit * vtxfit = VertexFit::instance();
KinematicFit * kmfit = KinematicFit::instance();

DECLARE_ALGORITHM_FACTORY( GamEtaEtap )
DECLARE_FACTORY_ENTRIES( GamEtaEtapAlg ) {
    DECLARE_ALGORITHM( GamEtaEtap );
}

LOAD_FACTORY_ENTRIES( GamEtaEtapAlg )

GamEtaEtap::GamEtaEtap(const std::string& name, ISvcLocator* pSvcLocator) :
	Algorithm(name, pSvcLocator) {
        m_DModes.push_back(200);
        declareProperty("DMode", m_DModes);
        declareProperty("IsMonteCarlo", m_isMonteCarlo = true);
        declareProperty("UsePID", m_pid = true);
        declareProperty("Debug", m_debug = false);
        declareProperty("Ecms", m_Ecms = 4.600);
}

StatusCode GamEtaEtap::initialize() {
    MsgStream log(msgSvc(), name());
    log << MSG::INFO << ">>>>>>> in initialize()" << endmsg;

    StatusCode status;

    NTuplePtr nt1(ntupleSvc(), "FILE1/STD");
    if (nt1) m_tuple1 = nt1;
    else {
        m_tuple1 = ntupleSvc()->book("FILE1/STD", CLID_ColumnWiseTuple, "Single tag D decay");
        if (m_tuple1) {
            status = m_tuple1->addItem("runNo", m_runNo);
            status = m_tuple1->addItem("evtNo", m_evtNo);
        }
        else {
            log << MSG::ERROR << "Cannot book N-tuple:" << long(m_tuple1) << endmsg;
            return StatusCode::FAILURE;
        }
    }

    log << MSG::INFO << "successfully return from initialize()" << endmsg;
    return StatusCode::SUCCESS;
}

StatusCode GamEtaEtap::execute() {
    MsgStream log(msgSvc(), name());
    log << MSG::INFO << "in execute()" << endreq;

    // grt common info
    SmartDataPtr<Event::EventHeader> eventHeader(eventSvc(),"/Event/EventHeader");
    if (!eventHeader) return StatusCode::FAILURE;
    runNo = eventHeader->runNumber();
    evtNo = eventHeader->eventNumber();

    if (m_debug) {
        std::cout << "**************************************" << std::endl;
        std::cout << "run = "  <<  runNo  <<  ", event = " << evtNo << std::endl;
        std::cout << "**************************************" << std::endl;
    }

    m_tuple1->write();
    return StatusCode::SUCCESS;
}

StatusCode GamEtaEtap::finalize() {
    std::cout << "Ncut0: " << Ncut0 << std::endl;
    std::cout << "Ncut1: " << Ncut1 << std::endl;
    std::cout << "Ncut2: " << Ncut2 << std::endl;
    std::cout << "Ncut3: " << Ncut3 << std::endl;
    std::cout << "Ncut4: " << Ncut4 << std::endl;
    std::cout << "Ncut5: " << Ncut5 << std::endl;
    std::cout << "Ncut6: " << Ncut6 << std::endl;
    MsgStream log(msgSvc(), name());
    log << MSG::INFO << ">>>>>>> in finalize()" << endmsg;

    return StatusCode::SUCCESS;
}
