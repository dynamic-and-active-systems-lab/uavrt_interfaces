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

	// Tag id (uint 32)
	uint32_t		id;
	// Frequency (uint 32)
	uint32_t		frequency_hz;
	// Pulse duration
	uint32_t		pulse_width_msecs;
	// Intra-pulse duration 1
	uint32_t		intra_pulse1_msecs;
	// Intra-pulse duration 2
	uint32_t		intra_pulse2_msecs;
	// Intra-pulse uncertainty
	uint32_t		intra_pulse_uncertainty_msecs;
	// Intra-pulse jitter
	uint32_t		intra_pulse_jitter_msecs;
	// Number of pulses to integrate by
	uint32_t		k;
	// Probability of a false alarm given that ??
	double			false_alarm_probability;
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

	// Descriptions and order are from the Interface Control Document
	// Tag ID (uint32_t)
	// The tag ID that was used for detection priori info. Useful for tractability.
	uint32_t 	tag_id;
	// Frequency (uint32_t)
	// Frequency at which pulse was detected.
	uint32_t 	frequency_hz;
	// Time start (builtin_interfaces/Time (double))
	// System time at rising edge of pulse time bin.
	double 		start_time_seconds;
	// Expected next pulse time - start (builtin_interfaces/Time (double))
	// This is the time that the next pulse is expected to occur based on
	// the current pulse time and the priori pulse interval information.
	double 		predict_next_start_seconds;
	// Pulse SNR (float64/double)
	// Estimated pulse SNR in dB. This is the SNR during the time of pulse
	// transmission. Additionally, this is the ratio of the pulses peak
	// power point to the estimated noise power at that same frequency.
	// See ’Noise PSD’ parameter for how noise power is estimated.
	// SNR = 10 log10[(PSDS+N- PSDN )/PSDN].
	// Note: This value is currently being used as the signal strength metric.
	double 		snr;
	// STFT Score (float64/double)
	// TBD
	double 		stft_score;
	// Pulse group index (uint16_t)
	// If more than one pulse is used for incoherent summing, the pulse group
	// will have up to K pulses. This property indicates where this pulse exists
	// in that pulse group. This property and the start time property can be
	// used to recollect pulse groups if needed.
	uint16_t 	group_ind;
	// Pulse group SNR (float64/double)
	// TBD
	double 		group_snr;
	// Detection status (bool converted to uint8_t)
	// This property indicates if the pulse is a subthreshold pulse (0),
	// superthreshold pulse (1), or confirmed pulse (2). All confirmed pulses
	// are superthreshold pulses. Confirmed status mean that pulses in near
	// this frequency were previously detected and this pulse aligns in time
	// with predictions based on the prior pulse and the tag priori.
	uint8_t 	detection_status;
	// Confirmation status (bool converted to uint8_t)
	// This property indicates if the pulse has been confirmed (1), or is of yet
	// unconfirmed (0). Confirmed pulses had a preceding pulse that was detected
	// and projected a next pulse that aligned with this pulse.
	uint8_t 	confirmed_status;
	// This is the longitude of the antenna when the pulse was received. 
	double 		position_x;
	// This is the latitude of the antenna when the pulse was received. 
	double 		position_y;
	// This is the altitude of the antenna when the pulse was received in meters
	// above the launch location.
	double 		position_z;
	// x element of the antenna orientation quaternion in free space.
	double 		orientation_x;
	// y element of the antenna orientation quaternion in free space.
	double 		orientation_y;
	// z element of the antenna orientation quaternion in free space.
	double 		orientation_z;
	// w element of the antenna orientation quaternion in free space.
	double 		orientation_w;
} PulseInfo_t;

typedef struct {
    HeaderInfo_t	header;

	// Confirmation as to whether detection can be started or not
	uint32_t		status;
} StatusConfirmationInfo_t;

#define TunnelProtocolValidateSizes \
	((sizeof(TunnelProtocol::AckInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::TagInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::StartTagsInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::EndTagsInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::StartDetectionInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::StopDetectionInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::PulseInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::StatusConfirmationInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN))

}
