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
	CommandIDRSC = 3,
	// System stop command
	CommandIDRSS = 4,
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
	PulseIndexGroupIndex = 2
};

enum class PulseDetectionStatus
{
	PulseDetectionStatusSuperThreshold = 1,
	PulseDetectionStatusConfirm = 2
};

}  // namespace uavrt_interfaces

#endif  // UAVRT_INTERFACES_INCLUDE_UAVRT_INTERFACES_QGC_ENUM_CLASS_DEFINITIONS_HPP_
