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
	// Frequency - 6 digits shifted by three decimals, NNNNNN means NNN.NNN000 Mhz (uint 32)
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
	// Tag ID (string)
	// The tag ID that was used for detection priori info. Useful for tractability.
	uint32_t 	tag_id;
	// Frequency (float64/double)
	// Frequency at which pulse was detected.
	uint32_t 	frequency_hz;
	// Time start (builtin_interfaces/Time (double))
	// System time at rising edge of pulse time bin.
	double 		start_time_seconds;
	// Time end (builtin_interfaces/Time (double))
	// System time at falling edge of pulse time bin.
	// double 		end_time_seconds;
	// Expected next pulse time - start (builtin_interfaces/Time (double))
	// This is the time that the next pulse is expected to occur based on
	// the current pulse time and the priori pulse interval information.
	// double 		predict_next_start_seconds;
	// Expected next pulse time - end (builtin_interfaces/Time (double))
	// double 		predict_next_end_seconds;
	// Pulse SNR (float64/double)
	// Estimated pulse SNR in dB. This is the SNR during the time of pulse
	// transmission. Additionally, this is the ratio of the pulses peak
	// power point to the estimated noise power at that same frequency.
	// See ’Noise PSD’ parameter for how noise power is estimated.
	// SNR = 10 log10[(PSDS+N- PSDN )/PSDN].
	// Note: This value is currently being used as the signal strength metric.
	double 		snr;
	// Pulse per sample SNR (float64/double)
	// TBD
	// double 		snr_per_sample;
	// Signal + Noise Power Spectral Density (float64/double)
	// PSD value calculated from the STFT matrix including both signal and
	// noise during the time of pulse transmission.
	// double 		psd_sn;
	// Noise Power Spectral Density (float64/double)
	// PSD value of noise only. This is calculated based on the average power
	// in the pulses’ frequency bin but outside the location in time where
	// the pulse was located.
	// double 		psd_n;
	// DFT Coefficient Real (float64/double)
	// This is the real part of the result of the DFT of the time-frequency bin
	// in which the pulse is located.
	// double 		dft_real;
	// DFT Coefficient Imaginary (float64/double)
	// This is the imaginary part of the result of the DFT of the time-frequency
	// bin in which the pulse is located.
	// double 		dft_imag;
	// Pulse group index (uint16_t)
	// If more than one pulse is used for incoherent summing, the pulse group
	// will have up to K pulses. This property indicates where this pulse exists
	// in that pulse group. This property and the start time property can be
	// used to recollect pulse groups if needed.
	uint32_t 	group_ind;
	// Pulse group SNR (float64/double)
	// TBD
	double 		group_snr;
	// Detection status (bool)
	// This property indicates if the pulse is a subthreshold pulse (0),
	// superthreshold pulse (1), or confirmed pulse (2). All confirmed pulses
	// are superthreshold pulses. Confirmed status mean that pulses in near
	// this frequency were previously detected and this pulse aligns in time
	// with predictions based on the prior pulse and the tag priori.
	uint32_t 	detection_status;
	// Confirmation status (bool)
	// This property indicates if the pulse has been confirmed (1), or is of yet
	// unconfirmed (0). Confirmed pulses had a preceding pulse that was detected
	// and projected a next pulse that aligned with this pulse.
	uint32_t 	confirmed_status;
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
} CondensedPulseInfo_t;

#define TunnelProtocolValidateSizes \
	((sizeof(TunnelProtocol::AckInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::TagInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::StartTagsInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::EndTagsInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::StartDetectionInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::StopDetectionInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN && \
	sizeof(TunnelProtocol::CondensedPulseInfo_t) <= MAVLINK_MSG_TUNNEL_FIELD_PAYLOAD_LEN))

}
