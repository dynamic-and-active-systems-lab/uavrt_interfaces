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
	// Detected pulse value
	CommandIDPulse = 3,
	// Radio system commands
	CommandIDRSC = 4,
	// Radio system state
	CommandIDRSS = 5
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

};

enum class RSCIndex
{
	// The command that will be executed
	RSCIndexCommand = 0,
	// The radio system or which process the command will be executed on
	RSCIndexWho = 1,
	// If a Detector is specified for ‘who’, this value will correspond to
	// that Detector’s ID. Otherwise, this value will be ‘0’.
	RSCIndexDetectorID = 2
};

enum class RSSIndex
{

};

}  // namespace uavrt_interfaces

#endif  // UAVRT_INTERFACES_INCLUDE_UAVRT_INTERFACES_QGC_ENUM_CLASS_DEFINITIONS_HPP_
