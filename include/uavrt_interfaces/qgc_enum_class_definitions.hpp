// Codebase for the Interfaces package used within the UAV-RT architecture.
// Copyright (C) 2022 Dynamic and Active Systems Lab
//
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef UAVRT_INTERFACES_INCLUDE_UAVRT_INTERFACES_QGC_ENUM_CLASS_DEFINITIONS_HPP_
#define UAVRT_INTERFACES_INCLUDE_UAVRT_INTERFACES_QGC_ENUM_CLASS_DEFINITIONS_HPP_

namespace uavrt_interfaces
{

enum class CommandID
{
	// Ack response to command
	CommandIDAck = 1,
	// Tag info
	CommandIDTag = 2,
	// System start command
	CommandIDStart = 3,
	// System stop command
	CommandIDStop = 4,
	// Detected pulse value
	CommandIDPulse = 5,

};

enum class AckIndex
{
	// Command being acked
	AckIndexCommand = 0,
	// Command result - 1 success, 0 failure
	AckIndexResult = 1
};

enum class TagIndex
{
	// Tag id (uint 32)
	TagIndexID = 0,
	// Frequency - 6 digits shifted by three decimals, NNNNNN means NNN.NNN000 Mhz (uint 32)
	TagIndexFrequency = 1,
	// Pulse duration
	TagIndexDurationMSecs = 2,
	// Intra-pulse duration 1
	TagIndexIntraPulse1MSecs = 3,
	// Intra-pulse duration 2
	TagIndexIntraPulse2MSecs = 4,
	// Intra-pulse uncertainty
	TagIndexIntraPulseUncertainty = 5,
	// Intra-pulse jitter
	TagIndexIntraPulseJitter = 6,
	// Max pulse value
	TagIndexMaxPulse = 7
};

enum class PulseIndex
{
	// Detection status (uint 32)
	PulseIndexDetectionStatus = 0,
	// Pulse strength [0-100] (float)
	PulseIndexStrength = 1,
	// Group index 0/1/2 (uint 32)
	PulseIndexGroupIndex = 2,

/**
	// Refactored version
	// Descriptions are from the Interface Control Document
	// Tag ID (string)
	// The tag ID that was used for detection priori info. Useful for tractability.
	PulseIndexTagID = 0,
	// Frequency (float64/double)
	// Frequency at which pulse was detected.
	PulseIndexFrequency = 1,
	// Time start (builtin_interfaces/Time (double))
	// System time at rising edge of pulse time bin.
	PulseIndexStartTime = 2,
	// Time end (builtin_interfaces/Time (double))
	// System time at falling edge of pulse time bin.
	PulseIndexEndTime = 3,
	// Expected next pulse time - start (builtin_interfaces/Time (double))
	// This is the time that the next pulse is expected to occur based on
	// the current pulse time and the priori pulse interval information.
	PulseIndexPredictNextStartTime = 4,
	// Expected next pulse time - end (builtin_interfaces/Time (double))
	PulseIndexPredictNextEndTime = 5,
	// Pulse SNR (float64/double)
	// Estimated pulse SNR in dB. This is the SNR during the time of pulse
	// transmission. Additionally, this is the ratio of the pulses peak
	// power point to the estimated noise power at that same frequency.
	// See ’Noise PSD’ parameter for how noise power is estimated.
	// SNR = 10 log10[(PSDS+N- PSDN )/PSDN].
	// Note: This value is currently being used as the signal strength metric.
	PulseIndexSNR = 6,
	// Pulse per sample SNR (float64/double)
	// TBD
	PulseIndexSNRPerSample = 7,
	// Signal + Noise Power Spectral Density (float64/double)
	// PSD value calculated from the STFT matrix including both signal and
	// noise during the time of pulse transmission
	PulseIndexPSDSN = 8,
	// DFT Coefficient Real (float64/double)
	// This is the real part of the result of the DFT of the time-frequency bin
	// in which the pulse is located.
	PulseIndexDFTReal = 9,
	// DFT Coefficient Imaginary (float64/double)
	// This is the imaginary part of the result of the DFT of the time-frequency
	// bin in which the pulse is located.
	PulseIndexDFTImaginary = 10,
	// Pulse group index (uint16_t)
	// If more than one pulse is used for incoherent summing, the pulse group
	// will have up to K pulses. This property indicates where this pulse exists
	// in that pulse group. This property and the start time property can be
	// used to recollect pulse groups if needed.
	PulseIndexGroupIndex = 11,
	// Pulse group SNR (float64/double)
	// TBD
	PulseIndexGroupSNR = 12,
	// Detection status (bool)
	// This property indicates if the pulse is a subthreshold pulse (0),
	// superthreshold pulse (1), or confirmed pulse (2). All confirmed pulses
	// are superthreshold pulses. Confirmed status mean that pulses in near
	// this frequency were previously detected and this pulse aligns in time
	// with predictions based on the prior pulse and the tag priori.
	PulseIndexDetectionStatus = 13,
	// Confirmation status (bool)
	// This property indicates if the pulse has been confirmed (1), or is of yet
	// unconfirmed (0). Confirmed pulses had a preceding pulse that was detected
	// and projected a next pulse that aligned with this pulse.
	PulseIndexConfirmedStatus = 14
**/
};

enum class PulseDetectionStatus
{
	PulseDetectionStatusSuperThreshold = 1,
	PulseDetectionStatusConfirm = 2
};

}  // namespace uavrt_interfaces

#endif  // UAVRT_INTERFACES_INCLUDE_UAVRT_INTERFACES_QGC_ENUM_CLASS_DEFINITIONS_HPP_
