#ifndef NB_SIMULATION_DATA_GENERATOR
#define NB_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class NBAnalyzerSettings;

class NBSimulationDataGenerator
{
public:
	NBSimulationDataGenerator();
	~NBSimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, NBAnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	NBAnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
	std::string mSerialText;
	U32 mStringIndex;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //NB_SIMULATION_DATA_GENERATOR