#pragma once

namespace TunnelProtocol {

#define COMMAND_ID_ACK              1   // Ack response to command
#define COMMAND_ID_START_TAGS		2   // Previous tag set should be cleared, new tags are about to be uploaded
#define COMMAND_ID_END_TAGS			3   // All new tags have been uploaded
#define COMMAND_ID_TAG              4   // Tag info
#define COMMAND_ID_START_DETECTION  5   // Start pulse detection
#define COMMAND_ID_STOP_DETECTION   6   // Stop pulse detection
#define COMMAND_ID_PULSE           	7   // Detected pulse value
#define COMMAND_ID_AIRSPY_HF        8 	// Capture raw Airspy HF+ data
#define COMMAND_ID_AIRSPY_MINI      9   // Capture raw Airspy mini data

#define COMMAND_RESULT_SUCCESS		1
#define COMMAND_RESULT_FAILURE		0

typedef struct {
	uint32_t command;
} HeaderInfo_t;

typedef struct {
	HeaderInfo_t 	header;

	uint32_t		command;
	uint32_t		result;
} AckInfo_t;

typedef struct {
	HeaderInfo_t	header;

	uint32_t		id;
	uint32_t		frequency_hz;
	uint32_t		pulse_width_msecs;
	uint32_t		intra_pulse1_msecs;
	uint32_t		intra_pulse2_msecs;
	uint32_t		intra_pulse_uncertainty_msecs;
	uint32_t		intra_pulse_jitter_msecs;
} TagInfo_t;

typedef struct {
    HeaderInfo_t	header;
} StartDetectionInfo_t;

typedef struct {
    HeaderInfo_t	header;
} StopDetectionInfo_t;

typedef struct {
    HeaderInfo_t	header;
} StartTagsInfo_t;

typedef struct {
    HeaderInfo_t	header;
} EndTagsInfo_t;

typedef struct {
    HeaderInfo_t	header;

	uint32_t 	tag_id;
	uint32_t 	frequency_hz;
	double 		start_time_seconds;
	double 		end_time_seconds;
	double 		predict_next_start_seconds;
	double 		predict_next_end_seconds;
	double 		snr;
	double 		snr_per_sample;
	double 		psd_sn;
	double 		psd_n;
	double 		dft_real;
	double 		dft_imag;
	uint32_t 	group_ind;
	double 		group_snr;
	uint32_t 	detection_status;
	uint32_t 	confirmed_status;
} PulseInfo_t;

#define TunnelProtocolValidateSizes \
	((sizeof(TunnelProtocol::AckInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::TagInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::StartTagsInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::EndTagsInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::StartDetectionInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::StopDetectionInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::PulseInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN))

}