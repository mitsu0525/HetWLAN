/*
 * STAapp.h
 *
 *  Created on: 2017/10/27
 *      Author: mitsuyasu
 */

#ifndef TEST_STAAPP_H_
#define TEST_STAAPP_H_

#include "inet/common/INETDefs.h"

#include "inet/linklayer/common/MACAddress.h"
#include "inet/common/lifecycle/NodeStatus.h"
#include "inet/common/lifecycle/ILifecycle.h"

namespace inet {

/**
 * Simple traffic generator for the Ethernet model.
 */
class INET_API STAapp : public cSimpleModule, public ILifecycle
{
  protected:
    enum Kinds { START = 100, NEXT };

    // send parameters
    long seqNum = 0;
    cPar *reqLength = nullptr;
    cPar *respLength = nullptr;
    cPar *sendInterval = nullptr;

    int localSAP = -1;
    int remoteSAP = -1;
    MACAddress destMACAddress;
    NodeStatus *nodeStatus = nullptr;

    // self messages
    cMessage *timerMsg = nullptr;
    simtime_t startTime;
    simtime_t stopTime;

    // receive statistics
    long packetsSent = 0;
    long packetsReceived = 0;
    static simsignal_t sentPkSignal;
    static simsignal_t rcvdPkSignal;
    static simsignal_t endToEndDelaySignal;

  protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;

    virtual bool isNodeUp();
    virtual bool isGenerator();
    virtual void scheduleNextPacket(bool start);
    virtual void cancelNextPacket();

    virtual MACAddress resolveDestMACAddress();

    virtual void sendPacket();
    virtual void receivePacket(cPacket *msg);
    virtual void registerDSAP(int dsap);
    virtual bool handleOperationStage(LifecycleOperation *operation, int stage, IDoneCallback *doneCallback) override;

    public:
        STAapp() {}
        virtual ~STAapp();
};

} // namespace inet



#endif /* TEST_STAAPP_H_ */
