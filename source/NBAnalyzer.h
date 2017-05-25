#ifndef NB_ANALYZER_H
#define NB_ANALYZER_H

#include <Analyzer.h>
#include "NBAnalyzerResults.h"
#include "NBSimulationDataGenerator.h"

class NBAnalyzerSettings;
class ANALYZER_EXPORT NBAnalyzer : public Analyzer2
{
public:
	NBAnalyzer();
	virtual ~NBAnalyzer();

	virtual void SetupResults();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

protected: //vars
	std::auto_ptr< NBAnalyzerSettings > mSettings;
	std::auto_ptr< NBAnalyzerResults > mResults;
	AnalyzerChannelData* mSerial;

	NBSimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	//Serial analysis vars:
	U32 mSampleRateHz;
	U32 mStartOfStopBitOffset;
	U32 mEndOfStopBitOffset;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //NB_ANALYZER_H
