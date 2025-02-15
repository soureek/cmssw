#ifndef CastorSim_CastorSimParameters_h
#define CastorSim_CastorSimParameters_h

#include "SimCalorimetry/CaloSimAlgos/interface/CaloSimParameters.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "CalibFormats/CastorObjects/interface/CastorDbService.h"

class CastorSimParameters : public CaloSimParameters
{
public:

CastorSimParameters(double simHitToPhotoelectrons, double photoelectronsToAnalog, double samplingFactor, double timePhase, bool syncPhase);
CastorSimParameters(const edm::ParameterSet & p);

virtual ~CastorSimParameters() {}

void setDbService(const CastorDbService * service) {theDbService = service;}

double getNominalfCperPE() const;
bool doDynamicNoise() const; 

virtual double photoelectronsToAnalog(const DetId & detId) const;

double fCtoGeV(const DetId & detId) const;


private:
const CastorDbService * theDbService;
double theSamplingFactor;
double nominalfCperPE;
bool dynamicNoise;
};

#endif
  
