#pragma once

namespace TunnelProtocol {

// WIP for new TUNNEL mavlink protocol work

#define COMMAND_ID_ACK              1   // Ack response to command
#define COMMAND_ID_TAG              2   // Tag info
#define COMMAND_ID_START_DETECTION  3   // Start pulse detection
#define COMMAND_ID_STOP_DETECTION   4   // Stop pulse detection
#define COMMAND_ID_PULSE           	5   // Detected pulse value

#define COMMAND_RESULT_SUCCESS		1
#define COMMAND_RESULT_FAILURE		0

typedef struct {
	uint32_t command;
} HeaderInfo_t;

typedef struct {
	HeaderInfo_t 	header = { COMMAND_ID_ACK };

	uint32_t		command;
	uint32_t		result;
} AckInfo_t;

typedef struct {
	HeaderInfo_t	header = { COMMAND_ID_TAG };

	uint32_t		frequencyHz;
	uint32_t		pulseWidthMSecs;
	uint32_t		intraPulse1MSecs;
	uint32_t		intraPulse2MSecs;
	uint32_t		intraPulseUncertaintyMsecs;
	uint32_t		intraPulseJitterMSecs;
} TagInfo_t;

typedef struct {
    HeaderInfo_t	header = { COMMAND_ID_START_DETECTION };
} StartDetectionInfo_t;

typedef struct {
    HeaderInfo_t	header = { COMMAND_ID_STOP_DETECTION };
} StopDetectionInfo_t;

typedef struct {
    HeaderInfo_t	header = {COMMAND_ID_TAG};

    double 		startTimeMSecs;
	uint32_t	confirmedStatus;
	double		snr;
	uint32_t	groupIndex;
} PulseInfo_t;

}