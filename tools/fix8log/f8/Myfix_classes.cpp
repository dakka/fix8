//-------------------------------------------------------------------------------------------------
// *** f8c generated file: DO NOT EDIT! Created: 1969-12-31 19:06:28 ***
//-------------------------------------------------------------------------------------------------
/*

Fix8 is released under the GNU LESSER GENERAL PUBLIC LICENSE Version 3.

Fix8 Open Source FIX Engine.
Copyright (C) 2010-14 David L. Dight <fix@fix8.org>

Fix8 is free software: you can  redistribute it and / or modify  it under the  terms of the
GNU Lesser General  Public License as  published  by the Free  Software Foundation,  either
version 3 of the License, or (at your option) any later version.

Fix8 is distributed in the hope  that it will be useful, but WITHOUT ANY WARRANTY;  without
even the  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

You should  have received a copy of the GNU Lesser General Public  License along with Fix8.
If not, see <http://www.gnu.org/licenses/>.

*******************************************************************************************
*                Special note for Fix8 compiler generated source code                     *
*                                                                                         *
* Binary works  that are the results of compilation of code that is generated by the Fix8 *
* compiler  can be released  without releasing your  source code as  long as your  binary *
* links dynamically  against an  unmodified version of the Fix8 library.  You are however *
* required to leave the copyright text in the generated code.                             *
*                                                                                         *
*******************************************************************************************

BECAUSE THE PROGRAM IS  LICENSED FREE OF  CHARGE, THERE IS NO  WARRANTY FOR THE PROGRAM, TO
THE EXTENT  PERMITTED  BY  APPLICABLE  LAW.  EXCEPT WHEN  OTHERWISE  STATED IN  WRITING THE
COPYRIGHT HOLDERS AND/OR OTHER PARTIES  PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY OF ANY
KIND,  EITHER EXPRESSED   OR   IMPLIED,  INCLUDING,  BUT   NOT  LIMITED   TO,  THE  IMPLIED
WARRANTIES  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS TO
THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE,
YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

IN NO EVENT UNLESS REQUIRED  BY APPLICABLE LAW  OR AGREED TO IN  WRITING WILL ANY COPYRIGHT
HOLDER, OR  ANY OTHER PARTY  WHO MAY MODIFY  AND/OR REDISTRIBUTE  THE PROGRAM AS  PERMITTED
ABOVE,  BE  LIABLE  TO  YOU  FOR  DAMAGES,  INCLUDING  ANY  GENERAL, SPECIAL, INCIDENTAL OR
CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT
NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR
THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), EVEN IF SUCH
HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

*/

//-------------------------------------------------------------------------------------------------
#include <fix8/f8config.h>
#if defined MAGIC_NUM && MAGIC_NUM > 16777216L
#error Myfix_classes.cpp version 1.0.0 is out of date. Please regenerate with f8c.
#endif
//-------------------------------------------------------------------------------------------------
// Myfix_classes.cpp
//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
#include <cerrno>
#include <string.h>
// f8 includes
#include <fix8/f8includes.hpp>
#include "Myfix_types.hpp"
#include "Myfix_router.hpp"
#include "Myfix_classes.hpp"
//-------------------------------------------------------------------------------------------------
namespace FIX8 {
namespace TEX {

namespace {

//-------------------------------------------------------------------------------------------------

const char *cn[] // Component names
{
   "",
   "AffectedOrdGrp", // 1
   "AllocAckGrp", // 2
   "AllocGrp", // 3
   "AltPtysSubGrp", // 4
   "ApplIDReportGrp", // 5
   "ApplIDRequestAckGrp", // 6
   "ApplIDRequestGrp", // 7
   "ApplicationSequenceControl", // 8
   "AttrbGrp", // 9
   "BaseTradingRules", // 10
   "BidCompReqGrp", // 11
   "BidCompRspGrp", // 12
   "BidDescReqGrp", // 13
   "ClrInstGrp", // 14
   "CollInqQualGrp", // 15
   "CommissionData", // 16
   "CompIDReqGrp", // 17
   "CompIDStatGrp", // 18
   "ComplexEventDates", // 19
   "ComplexEventTimes", // 20
   "ComplexEvents", // 21
   "ContAmtGrp", // 22
   "ContextParties", // 23
   "ContextPtysSubGrp", // 24
   "ContraGrp", // 25
   "CpctyConfGrp", // 26
   "DerivativeEventsGrp", // 27
   "DerivativeInstrument", // 28
   "DerivativeInstrumentAttribute", // 29
   "DerivativeInstrumentParties", // 30
   "DerivativeInstrumentPartySubIDsGrp", // 31
   "DerivativeSecurityAltIDGrp", // 32
   "DerivativeSecurityDefinition", // 33
   "DerivativeSecurityXML", // 34
   "DiscretionInstructions", // 35
   "DisplayInstruction", // 36
   "DlvyInstGrp", // 37
   "EvntGrp", // 38
   "ExecAllocGrp", // 39
   "ExecCollGrp", // 40
   "ExecInstRules", // 41
   "ExpirationQty", // 42
   "FillsGrp", // 43
   "FinancingDetails", // 44
   "HopGrp", // 45
   "IOIQualGrp", // 46
   "InstrmtGrp", // 47
   "InstrmtLegExecGrp", // 48
   "InstrmtLegGrp", // 49
   "InstrmtLegIOIGrp", // 50
   "InstrmtLegSecListGrp", // 51
   "InstrmtMDReqGrp", // 52
   "InstrmtStrkPxGrp", // 53
   "Instrument", // 54
   "InstrumentExtension", // 55
   "InstrumentLeg", // 56
   "InstrumentParties", // 57
   "InstrumentPtysSubGrp", // 58
   "LegBenchmarkCurveData", // 59
   "LegOrdGrp", // 60
   "LegPreAllocGrp", // 61
   "LegQuotGrp", // 62
   "LegQuotStatGrp", // 63
   "LegSecAltIDGrp", // 64
   "LegStipulations", // 65
   "LinesOfTextGrp", // 66
   "ListOrdGrp", // 67
   "LotTypeRules", // 68
   "MDFullGrp", // 69
   "MDIncGrp", // 70
   "MDReqGrp", // 71
   "MDRjctGrp", // 72
   "MarketDataFeedTypes", // 73
   "MarketSegmentGrp", // 74
   "MatchRules", // 75
   "MaturityRules", // 76
   "MiscFeesGrp", // 77
   "MsgTypeGrp", // 78
   "NestedInstrumentAttribute", // 79
   "NestedParties", // 80
   "NestedParties2", // 81
   "NestedParties3", // 82
   "NestedParties4", // 83
   "NewsRefGrp", // 84
   "NotAffectedOrdersGrp", // 85
   "NstdPtys2SubGrp", // 86
   "NstdPtys3SubGrp", // 87
   "NstdPtys4SubGrp", // 88
   "NstdPtysSubGrp", // 89
   "OrdAllocGrp", // 90
   "OrdListStatGrp", // 91
   "OrdTypeRules", // 92
   "OrderQtyData", // 93
   "Parties", // 94
   "PartyAltIDs", // 95
   "PartyDetail", // 96
   "PartyListGrp", // 97
   "PartyListResponseTypeGrp", // 98
   "PartyRelationships", // 99
   "PegInstructions", // 100
   "PosUndInstrmtGrp", // 101
   "PositionAmountData", // 102
   "PositionQty", // 103
   "PreAllocGrp", // 104
   "PreAllocMlegGrp", // 105
   "PriceLimits", // 106
   "PtysSubGrp", // 107
   "QuotCxlEntriesGrp", // 108
   "QuotEntryAckGrp", // 109
   "QuotEntryGrp", // 110
   "QuotQualGrp", // 111
   "QuotReqGrp", // 112
   "QuotReqLegsGrp", // 113
   "QuotReqRjctGrp", // 114
   "QuotSetAckGrp", // 115
   "QuotSetGrp", // 116
   "RFQReqGrp", // 117
   "RateSource", // 118
   "RelSymDerivSecGrp", // 119
   "RelSymDerivSecUpdGrp", // 120
   "RelatedAltPtysSubGrp", // 121
   "RelatedContextParties", // 122
   "RelatedContextPtysSubGrp", // 123
   "RelatedPartyAltIDs", // 124
   "RelatedPartyDetail", // 125
   "RelatedPartyGrp", // 126
   "RelatedPtysSubGrp", // 127
   "RelationshipRiskInstrumentScope", // 128
   "RelationshipRiskLimits", // 129
   "RelationshipRiskSecAltIDGrp", // 130
   "RelationshipRiskWarningLevels", // 131
   "RequestedPartyRoleGrp", // 132
   "RgstDistInstGrp", // 133
   "RgstDtlsGrp", // 134
   "RiskInstrumentScope", // 135
   "RiskLimits", // 136
   "RiskSecAltIDGrp", // 137
   "RiskWarningLevels", // 138
   "RootParties", // 139
   "RootSubParties", // 140
   "RoutingGrp", // 141
   "SecAltIDGrp", // 142
   "SecListGrp", // 143
   "SecLstUpdRelSymGrp", // 144
   "SecLstUpdRelSymsLegGrp", // 145
   "SecSizesGrp", // 146
   "SecTypesGrp", // 147
   "SecondaryPriceLimits", // 148
   "SecurityTradingRules", // 149
   "SecurityXML", // 150
   "SettlDetails", // 151
   "SettlInstGrp", // 152
   "SettlInstructionsData", // 153
   "SettlObligationInstructions", // 154
   "SettlParties", // 155
   "SettlPtysSubGrp", // 156
   "SideCrossOrdCxlGrp", // 157
   "SideCrossOrdModGrp", // 158
   "SideTrdRegTS", // 159
   "SpreadOrBenchmarkCurveData", // 160
   "StatsIndGrp", // 161
   "Stipulations", // 162
   "StrategyParametersGrp", // 163
   "StrikeRules", // 164
   "StrmAsgnReqGrp", // 165
   "StrmAsgnReqInstrmtGrp", // 166
   "StrmAsgnRptGrp", // 167
   "StrmAsgnRptInstrmtGrp", // 168
   "TargetParties", // 169
   "TickRules", // 170
   "TimeInForceRules", // 171
   "TradeCapLegUnderlyingsGrp", // 172
   "TradeReportOrderDetail", // 173
   "TradingSessionRules", // 174
   "TradingSessionRulesGrp", // 175
   "TrdAllocGrp", // 176
   "TrdCapDtGrp", // 177
   "TrdCapRptAckSideGrp", // 178
   "TrdCapRptSideGrp", // 179
   "TrdCollGrp", // 180
   "TrdInstrmtLegGrp", // 181
   "TrdRegTimestamps", // 182
   "TrdRepIndicatorsGrp", // 183
   "TrdSessLstGrp", // 184
   "TrdgSesGrp", // 185
   "TriggeringInstruction", // 186
   "UndInstrmtCollGrp", // 187
   "UndInstrmtGrp", // 188
   "UndSecAltIDGrp", // 189
   "UnderlyingAmount", // 190
   "UnderlyingInstrument", // 191
   "UnderlyingLegInstrument", // 192
   "UnderlyingLegSecurityAltIDGrp", // 193
   "UnderlyingStipulations", // 194
   "UndlyInstrumentParties", // 195
   "UndlyInstrumentPtysSubGrp", // 196
   "UsernameGrp", // 197
   "YieldData", // 198
};

} // namespace

//-------------------------------------------------------------------------------------------------
const TEX::Myfix_BaseMsgEntry::Pair msgpairs[] 
{
   { "0", { Type2Type<TEX::Heartbeat>(), "Heartbeat" } },
   { "1", { Type2Type<TEX::TestRequest>(), "TestRequest" } },
   { "2", { Type2Type<TEX::ResendRequest>(), "ResendRequest" } },
   { "3", { Type2Type<TEX::Reject>(), "Reject" } },
   { "4", { Type2Type<TEX::SequenceReset>(), "SequenceReset" } },
   { "5", { Type2Type<TEX::Logout>(), "Logout" } },
   { "6", { Type2Type<TEX::IOI>(), "IOI" } },
   { "7", { Type2Type<TEX::Advertisement>(), "Advertisement" } },
   { "8", { Type2Type<TEX::ExecutionReport>(), "ExecutionReport" } },
   { "9", { Type2Type<TEX::OrderCancelReject>(), "OrderCancelReject" } },
   { "A", { Type2Type<TEX::Logon>(), "Logon" } },
   { "AA", { Type2Type<TEX::DerivativeSecurityList>(), "DerivativeSecurityList" } },
   { "AB", { Type2Type<TEX::NewOrderMultileg>(), "NewOrderMultileg" } },
   { "AC", { Type2Type<TEX::MultilegOrderCancelReplace>(), "MultilegOrderCancelReplace" } },
   { "AD", { Type2Type<TEX::TradeCaptureReportRequest>(), "TradeCaptureReportRequest" } },
   { "AE", { Type2Type<TEX::TradeCaptureReport>(), "TradeCaptureReport" } },
   { "AF", { Type2Type<TEX::OrderMassStatusRequest>(), "OrderMassStatusRequest" } },
   { "AG", { Type2Type<TEX::QuoteRequestReject>(), "QuoteRequestReject" } },
   { "AH", { Type2Type<TEX::RFQRequest>(), "RFQRequest" } },
   { "AI", { Type2Type<TEX::QuoteStatusReport>(), "QuoteStatusReport" } },
   { "AJ", { Type2Type<TEX::QuoteResponse>(), "QuoteResponse" } },
   { "AK", { Type2Type<TEX::Confirmation>(), "Confirmation" } },
   { "AL", { Type2Type<TEX::PositionMaintenanceRequest>(), "PositionMaintenanceRequest" } },
   { "AM", { Type2Type<TEX::PositionMaintenanceReport>(), "PositionMaintenanceReport" } },
   { "AN", { Type2Type<TEX::RequestForPositions>(), "RequestForPositions" } },
   { "AO", { Type2Type<TEX::RequestForPositionsAck>(), "RequestForPositionsAck" } },
   { "AP", { Type2Type<TEX::PositionReport>(), "PositionReport" } },
   { "AQ", { Type2Type<TEX::TradeCaptureReportRequestAck>(), "TradeCaptureReportRequestAck" } },
   { "AR", { Type2Type<TEX::TradeCaptureReportAck>(), "TradeCaptureReportAck" } },
   { "AS", { Type2Type<TEX::AllocationReport>(), "AllocationReport" } },
   { "AT", { Type2Type<TEX::AllocationReportAck>(), "AllocationReportAck" } },
   { "AU", { Type2Type<TEX::ConfirmationAck>(), "ConfirmationAck" } },
   { "AV", { Type2Type<TEX::SettlementInstructionRequest>(), "SettlementInstructionRequest" } },
   { "AW", { Type2Type<TEX::AssignmentReport>(), "AssignmentReport" } },
   { "AX", { Type2Type<TEX::CollateralRequest>(), "CollateralRequest" } },
   { "AY", { Type2Type<TEX::CollateralAssignment>(), "CollateralAssignment" } },
   { "AZ", { Type2Type<TEX::CollateralResponse>(), "CollateralResponse" } },
   { "B", { Type2Type<TEX::News>(), "News" } },
   { "BA", { Type2Type<TEX::CollateralReport>(), "CollateralReport" } },
   { "BB", { Type2Type<TEX::CollateralInquiry>(), "CollateralInquiry" } },
   { "BC", { Type2Type<TEX::NetworkCounterpartySystemStatusRequest>(), "NetworkCounterpartySystemStatusRequest" } },
   { "BD", { Type2Type<TEX::NetworkCounterpartySystemStatusResponse>(), "NetworkCounterpartySystemStatusResponse" } },
   { "BE", { Type2Type<TEX::UserRequest>(), "UserRequest" } },
   { "BF", { Type2Type<TEX::UserResponse>(), "UserResponse" } },
   { "BG", { Type2Type<TEX::CollateralInquiryAck>(), "CollateralInquiryAck" } },
   { "BH", { Type2Type<TEX::ConfirmationRequest>(), "ConfirmationRequest" } },
   { "BI", { Type2Type<TEX::TradingSessionListRequest>(), "TradingSessionListRequest" } },
   { "BJ", { Type2Type<TEX::TradingSessionList>(), "TradingSessionList" } },
   { "BK", { Type2Type<TEX::SecurityListUpdateReport>(), "SecurityListUpdateReport" } },
   { "BL", { Type2Type<TEX::AdjustedPositionReport>(), "AdjustedPositionReport" } },
   { "BM", { Type2Type<TEX::AllocationInstructionAlert>(), "AllocationInstructionAlert" } },
   { "BN", { Type2Type<TEX::ExecutionAcknowledgement>(), "ExecutionAcknowledgement" } },
   { "BO", { Type2Type<TEX::ContraryIntentionReport>(), "ContraryIntentionReport" } },
   { "BP", { Type2Type<TEX::SecurityDefinitionUpdateReport>(), "SecurityDefinitionUpdateReport" } },
   { "BQ", { Type2Type<TEX::SettlementObligationReport>(), "SettlementObligationReport" } },
   { "BR", { Type2Type<TEX::DerivativeSecurityListUpdateReport>(), "DerivativeSecurityListUpdateReport" } },
   { "BS", { Type2Type<TEX::TradingSessionListUpdateReport>(), "TradingSessionListUpdateReport" } },
   { "BT", { Type2Type<TEX::MarketDefinitionRequest>(), "MarketDefinitionRequest" } },
   { "BU", { Type2Type<TEX::MarketDefinition>(), "MarketDefinition" } },
   { "BV", { Type2Type<TEX::MarketDefinitionUpdateReport>(), "MarketDefinitionUpdateReport" } },
   { "BW", { Type2Type<TEX::ApplicationMessageRequest>(), "ApplicationMessageRequest" } },
   { "BX", { Type2Type<TEX::ApplicationMessageRequestAck>(), "ApplicationMessageRequestAck" } },
   { "BY", { Type2Type<TEX::ApplicationMessageReport>(), "ApplicationMessageReport" } },
   { "BZ", { Type2Type<TEX::OrderMassActionReport>(), "OrderMassActionReport" } },
   { "C", { Type2Type<TEX::Email>(), "Email" } },
   { "CA", { Type2Type<TEX::OrderMassActionRequest>(), "OrderMassActionRequest" } },
   { "CB", { Type2Type<TEX::UserNotification>(), "UserNotification" } },
   { "CC", { Type2Type<TEX::StreamAssignmentRequest>(), "StreamAssignmentRequest" } },
   { "CD", { Type2Type<TEX::StreamAssignmentReport>(), "StreamAssignmentReport" } },
   { "CE", { Type2Type<TEX::StreamAssignmentReportACK>(), "StreamAssignmentReportACK" } },
   { "CF", { Type2Type<TEX::PartyDetailsListRequest>(), "PartyDetailsListRequest" } },
   { "CG", { Type2Type<TEX::PartyDetailsListReport>(), "PartyDetailsListReport" } },
   { "D", { Type2Type<TEX::NewOrderSingle>(), "NewOrderSingle" } },
   { "E", { Type2Type<TEX::NewOrderList>(), "NewOrderList" } },
   { "F", { Type2Type<TEX::OrderCancelRequest>(), "OrderCancelRequest" } },
   { "G", { Type2Type<TEX::OrderCancelReplaceRequest>(), "OrderCancelReplaceRequest" } },
   { "H", { Type2Type<TEX::OrderStatusRequest>(), "OrderStatusRequest" } },
   { "J", { Type2Type<TEX::AllocationInstruction>(), "AllocationInstruction" } },
   { "K", { Type2Type<TEX::ListCancelRequest>(), "ListCancelRequest" } },
   { "L", { Type2Type<TEX::ListExecute>(), "ListExecute" } },
   { "M", { Type2Type<TEX::ListStatusRequest>(), "ListStatusRequest" } },
   { "N", { Type2Type<TEX::ListStatus>(), "ListStatus" } },
   { "P", { Type2Type<TEX::AllocationInstructionAck>(), "AllocationInstructionAck" } },
   { "Q", { Type2Type<TEX::DontKnowTrade>(), "DontKnowTrade" } },
   { "R", { Type2Type<TEX::QuoteRequest>(), "QuoteRequest" } },
   { "S", { Type2Type<TEX::Quote>(), "Quote" } },
   { "T", { Type2Type<TEX::SettlementInstructions>(), "SettlementInstructions" } },
   { "V", { Type2Type<TEX::MarketDataRequest>(), "MarketDataRequest" } },
   { "W", { Type2Type<TEX::MarketDataSnapshotFullRefresh>(), "MarketDataSnapshotFullRefresh" } },
   { "X", { Type2Type<TEX::MarketDataIncrementalRefresh>(), "MarketDataIncrementalRefresh" } },
   { "Y", { Type2Type<TEX::MarketDataRequestReject>(), "MarketDataRequestReject" } },
   { "Z", { Type2Type<TEX::QuoteCancel>(), "QuoteCancel" } },
   { "a", { Type2Type<TEX::QuoteStatusRequest>(), "QuoteStatusRequest" } },
   { "b", { Type2Type<TEX::MassQuoteAcknowledgement>(), "MassQuoteAcknowledgement" } },
   { "c", { Type2Type<TEX::SecurityDefinitionRequest>(), "SecurityDefinitionRequest" } },
   { "d", { Type2Type<TEX::SecurityDefinition>(), "SecurityDefinition" } },
   { "e", { Type2Type<TEX::SecurityStatusRequest>(), "SecurityStatusRequest" } },
   { "f", { Type2Type<TEX::SecurityStatus>(), "SecurityStatus" } },
   { "g", { Type2Type<TEX::TradingSessionStatusRequest>(), "TradingSessionStatusRequest" } },
   { "h", { Type2Type<TEX::TradingSessionStatus>(), "TradingSessionStatus" } },
   { "header", { Type2Types<TEX::header, bool>(), "header" } },
   { "i", { Type2Type<TEX::MassQuote>(), "MassQuote" } },
   { "j", { Type2Type<TEX::BusinessMessageReject>(), "BusinessMessageReject" } },
   { "k", { Type2Type<TEX::BidRequest>(), "BidRequest" } },
   { "l", { Type2Type<TEX::BidResponse>(), "BidResponse" } },
   { "m", { Type2Type<TEX::ListStrikePrice>(), "ListStrikePrice" } },
   { "o", { Type2Type<TEX::RegistrationInstructions>(), "RegistrationInstructions" } },
   { "p", { Type2Type<TEX::RegistrationInstructionsResponse>(), "RegistrationInstructionsResponse" } },
   { "q", { Type2Type<TEX::OrderMassCancelRequest>(), "OrderMassCancelRequest" } },
   { "r", { Type2Type<TEX::OrderMassCancelReport>(), "OrderMassCancelReport" } },
   { "s", { Type2Type<TEX::NewOrderCross>(), "NewOrderCross" } },
   { "t", { Type2Type<TEX::CrossOrderCancelReplaceRequest>(), "CrossOrderCancelReplaceRequest" } },
   { "trailer", { Type2Types<TEX::trailer, bool>(), "trailer" } },
   { "u", { Type2Type<TEX::CrossOrderCancelRequest>(), "CrossOrderCancelRequest" } },
   { "v", { Type2Type<TEX::SecurityTypeRequest>(), "SecurityTypeRequest" } },
   { "w", { Type2Type<TEX::SecurityTypes>(), "SecurityTypes" } },
   { "x", { Type2Type<TEX::SecurityListRequest>(), "SecurityListRequest" } },
   { "y", { Type2Type<TEX::SecurityList>(), "SecurityList" } },
   { "z", { Type2Type<TEX::DerivativeSecurityListRequest>(), "DerivativeSecurityListRequest" } }
}; // 119

extern const Myfix_BaseEntry::Pair fldpairs[];

/// Compiler generated metadata object, accessed through this function
const F8MetaCntx& ctx() // avoid SIOF
{
   static const Myfix_BaseMsgEntry bme(msgpairs, 119);
   static const Myfix_BaseEntry be(fldpairs, 1562);
   static const F8MetaCntx _ctx(1100, bme, be, cn, "FIXT.1.1");
   return _ctx;
}

} // namespace TEX
} // namespace FIX8

