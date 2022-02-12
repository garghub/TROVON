static int
dissect_charging_ase_ChargingControlIndicators(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
ChargingControlIndicators_bits, hf_index, ett_charging_ase_ChargingControlIndicators,
NULL);
return offset;
}
static int
dissect_charging_ase_CurrencyFactor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_charging_ase_CurrencyScale(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_charging_ase_CurrencyFactorScale(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CurrencyFactorScale_sequence, hf_index, ett_charging_ase_CurrencyFactorScale);
return offset;
}
static int
dissect_charging_ase_TariffDuration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_charging_ase_SubTariffControl(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
SubTariffControl_bits, hf_index, ett_charging_ase_SubTariffControl,
NULL);
return offset;
}
static int
dissect_charging_ase_CommunicationChargeCurrency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CommunicationChargeCurrency_sequence, hf_index, ett_charging_ase_CommunicationChargeCurrency);
return offset;
}
static int
dissect_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency_sequence_of, hf_index, ett_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency);
return offset;
}
static int
dissect_charging_ase_T_tariffControlIndicators(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_tariffControlIndicators_bits, hf_index, ett_charging_ase_T_tariffControlIndicators,
NULL);
return offset;
}
static int
dissect_charging_ase_TariffCurrencyFormat(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TariffCurrencyFormat_sequence, hf_index, ett_charging_ase_TariffCurrencyFormat);
return offset;
}
static int
dissect_charging_ase_TariffSwitchoverTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_charging_ase_TariffSwitchCurrency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TariffSwitchCurrency_sequence, hf_index, ett_charging_ase_TariffSwitchCurrency);
return offset;
}
static int
dissect_charging_ase_TariffCurrency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TariffCurrency_sequence, hf_index, ett_charging_ase_TariffCurrency);
return offset;
}
static int
dissect_charging_ase_PulseUnits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_charging_ase_ChargeUnitTimeInterval(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_charging_ase_CommunicationChargePulse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CommunicationChargePulse_sequence, hf_index, ett_charging_ase_CommunicationChargePulse);
return offset;
}
static int
dissect_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse_sequence_of, hf_index, ett_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse);
return offset;
}
static int
dissect_charging_ase_T_tariffControlIndicators_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_tariffControlIndicators_01_bits, hf_index, ett_charging_ase_T_tariffControlIndicators_01,
NULL);
return offset;
}
static int
dissect_charging_ase_TariffPulseFormat(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TariffPulseFormat_sequence, hf_index, ett_charging_ase_TariffPulseFormat);
return offset;
}
static int
dissect_charging_ase_TariffSwitchPulse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TariffSwitchPulse_sequence, hf_index, ett_charging_ase_TariffSwitchPulse);
return offset;
}
static int
dissect_charging_ase_TariffPulse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TariffPulse_sequence, hf_index, ett_charging_ase_TariffPulse);
return offset;
}
static int
dissect_charging_ase_T_chargingTariff(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_chargingTariff_choice, hf_index, ett_charging_ase_T_chargingTariff,
NULL);
return offset;
}
static int
dissect_charging_ase_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_charging_ase_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_charging_ase_Code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Code_choice, hf_index, ett_charging_ase_Code,
NULL);
return offset;
}
static int
dissect_charging_ase_CriticalityType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_charging_ase_T_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 13 "./asn1/charging_ase/charging_ase.cnf"
proto_tree_add_expert(tree, actx->pinfo, &ei_charging_ase_extensions_not_dissected, tvb, offset, -1);
return tvb_reported_length(tvb);
return offset;
}
static int
dissect_charging_ase_ExtensionField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExtensionField_sequence, hf_index, ett_charging_ase_ExtensionField);
return offset;
}
static int
dissect_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField_sequence_of, hf_index, ett_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField);
return offset;
}
static int
dissect_charging_ase_NetworkIdentification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_charging_ase_ReferenceID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_charging_ase_ChargingReferenceIdentification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChargingReferenceIdentification_sequence, hf_index, ett_charging_ase_ChargingReferenceIdentification);
return offset;
}
static int
dissect_charging_ase_Currency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_charging_ase_ChargingTariffInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChargingTariffInformation_sequence, hf_index, ett_charging_ase_ChargingTariffInformation);
return offset;
}
static int
dissect_charging_ase_T_addOncharge(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_addOncharge_choice, hf_index, ett_charging_ase_T_addOncharge,
NULL);
return offset;
}
static int
dissect_charging_ase_AddOnChargingInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AddOnChargingInformation_sequence, hf_index, ett_charging_ase_AddOnChargingInformation);
return offset;
}
static int
dissect_charging_ase_T_acknowledgementIndicators(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_acknowledgementIndicators_bits, hf_index, ett_charging_ase_T_acknowledgementIndicators,
NULL);
return offset;
}
static int
dissect_charging_ase_ChargingAcknowledgementInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChargingAcknowledgementInformation_sequence, hf_index, ett_charging_ase_ChargingAcknowledgementInformation);
return offset;
}
static int
dissect_charging_ase_SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification_sequence_of, hf_index, ett_charging_ase_SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification);
return offset;
}
static int
dissect_charging_ase_StartCharging(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
StartCharging_sequence, hf_index, ett_charging_ase_StartCharging);
return offset;
}
static int
dissect_charging_ase_T_stopIndicators(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_stopIndicators_bits, hf_index, ett_charging_ase_T_stopIndicators,
NULL);
return offset;
}
static int
dissect_charging_ase_StopCharging(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
StopCharging_sequence, hf_index, ett_charging_ase_StopCharging);
return offset;
}
int
dissect_charging_ase_ChargingMessageType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChargingMessageType_choice, hf_index, ett_charging_ase_ChargingMessageType,
NULL);
return offset;
}
int dissect_charging_ase_ChargingMessageType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_charging_ase_ChargingMessageType(FALSE, tvb, offset, &asn1_ctx, tree, hf_charging_ase_charging_ase_ChargingMessageType_PDU);
return offset;
}
static int
dissect_charging_ase(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *it;
proto_tree *tr;
it=proto_tree_add_protocol_format(tree, proto_charging_ase, tvb, 0, -1, "Charging ASE");
tr=proto_item_add_subtree(it, ett_charging_ase);
if(tvb_reported_length(tvb)>0)
{
dissect_charging_ase_ChargingMessageType_PDU(tvb , pinfo, tr, NULL);
}
return tvb_captured_length(tvb);
}
void
proto_register_charging_ase(void)
{
static hf_register_info hf[] = {
#line 1 "./asn1/charging_ase/packet-charging_ase-hfarr.c"
{ &hf_charging_ase_charging_ase_ChargingMessageType_PDU,
{ "ChargingMessageType", "charging_ase.ChargingMessageType",
FT_UINT32, BASE_DEC, VALS(charging_ase_ChargingMessageType_vals), 0,
NULL, HFILL }},
{ &hf_charging_ase_crgt,
{ "crgt", "charging_ase.crgt_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChargingTariffInformation", HFILL }},
{ &hf_charging_ase_aocrg,
{ "aocrg", "charging_ase.aocrg_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddOnChargingInformation", HFILL }},
{ &hf_charging_ase_crga,
{ "crga", "charging_ase.crga_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChargingAcknowledgementInformation", HFILL }},
{ &hf_charging_ase_start,
{ "start", "charging_ase.start_element",
FT_NONE, BASE_NONE, NULL, 0,
"StartCharging", HFILL }},
{ &hf_charging_ase_stop,
{ "stop", "charging_ase.stop_element",
FT_NONE, BASE_NONE, NULL, 0,
"StopCharging", HFILL }},
{ &hf_charging_ase_acknowledgementIndicators,
{ "acknowledgementIndicators", "charging_ase.acknowledgementIndicators",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_extensions,
{ "extensions", "charging_ase.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField", HFILL }},
{ &hf_charging_ase_extensions_item,
{ "ExtensionField", "charging_ase.ExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_originationIdentification,
{ "originationIdentification", "charging_ase.originationIdentification_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChargingReferenceIdentification", HFILL }},
{ &hf_charging_ase_destinationIdentification,
{ "destinationIdentification", "charging_ase.destinationIdentification_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChargingReferenceIdentification", HFILL }},
{ &hf_charging_ase_chargingControlIndicators,
{ "chargingControlIndicators", "charging_ase.chargingControlIndicators",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_addOncharge,
{ "addOncharge", "charging_ase.addOncharge",
FT_UINT32, BASE_DEC, VALS(charging_ase_T_addOncharge_vals), 0,
NULL, HFILL }},
{ &hf_charging_ase_addOnChargeCurrency,
{ "addOnChargeCurrency", "charging_ase.addOnChargeCurrency_element",
FT_NONE, BASE_NONE, NULL, 0,
"CurrencyFactorScale", HFILL }},
{ &hf_charging_ase_addOnChargePulse,
{ "addOnChargePulse", "charging_ase.addOnChargePulse",
FT_BYTES, BASE_NONE, NULL, 0,
"PulseUnits", HFILL }},
{ &hf_charging_ase_currency,
{ "currency", "charging_ase.currency",
FT_UINT32, BASE_DEC, VALS(charging_ase_Currency_vals), 0,
NULL, HFILL }},
{ &hf_charging_ase_chargingTariff,
{ "chargingTariff", "charging_ase.chargingTariff",
FT_UINT32, BASE_DEC, VALS(charging_ase_T_chargingTariff_vals), 0,
NULL, HFILL }},
{ &hf_charging_ase_tariffCurrency,
{ "tariffCurrency", "charging_ase.tariffCurrency_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_tariffPulse,
{ "tariffPulse", "charging_ase.tariffPulse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_local,
{ "local", "charging_ase.local",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_charging_ase_global,
{ "global", "charging_ase.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_charging_ase_currencyFactorScale,
{ "currencyFactorScale", "charging_ase.currencyFactorScale_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_tariffDuration,
{ "tariffDuration", "charging_ase.tariffDuration",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_subTariffControl,
{ "subTariffControl", "charging_ase.subTariffControl",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_pulseUnits,
{ "pulseUnits", "charging_ase.pulseUnits",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_chargeUnitTimeInterval,
{ "chargeUnitTimeInterval", "charging_ase.chargeUnitTimeInterval",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_currencyFactor,
{ "currencyFactor", "charging_ase.currencyFactor",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_currencyScale,
{ "currencyScale", "charging_ase.currencyScale",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_type,
{ "type", "charging_ase.type",
FT_UINT32, BASE_DEC, VALS(charging_ase_Code_vals), 0,
"Code", HFILL }},
{ &hf_charging_ase_criticality,
{ "criticality", "charging_ase.criticality",
FT_UINT32, BASE_DEC, VALS(charging_ase_CriticalityType_vals), 0,
"CriticalityType", HFILL }},
{ &hf_charging_ase_value,
{ "value", "charging_ase.value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_networkOperators,
{ "networkOperators", "charging_ase.networkOperators",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification", HFILL }},
{ &hf_charging_ase_networkOperators_item,
{ "NetworkIdentification", "charging_ase.NetworkIdentification",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_stopIndicators,
{ "stopIndicators", "charging_ase.stopIndicators",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_currentTariffCurrency,
{ "currentTariffCurrency", "charging_ase.currentTariffCurrency_element",
FT_NONE, BASE_NONE, NULL, 0,
"TariffCurrencyFormat", HFILL }},
{ &hf_charging_ase_tariffSwitchCurrency,
{ "tariffSwitchCurrency", "charging_ase.tariffSwitchCurrency_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_nextTariffCurrency,
{ "nextTariffCurrency", "charging_ase.nextTariffCurrency_element",
FT_NONE, BASE_NONE, NULL, 0,
"TariffCurrencyFormat", HFILL }},
{ &hf_charging_ase_tariffSwitchoverTime,
{ "tariffSwitchoverTime", "charging_ase.tariffSwitchoverTime",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_communicationChargeSequenceCurrency,
{ "communicationChargeSequenceCurrency", "charging_ase.communicationChargeSequenceCurrency",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency", HFILL }},
{ &hf_charging_ase_communicationChargeSequenceCurrency_item,
{ "CommunicationChargeCurrency", "charging_ase.CommunicationChargeCurrency_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_tariffControlIndicators,
{ "tariffControlIndicators", "charging_ase.tariffControlIndicators",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_callAttemptChargeCurrency,
{ "callAttemptChargeCurrency", "charging_ase.callAttemptChargeCurrency_element",
FT_NONE, BASE_NONE, NULL, 0,
"CurrencyFactorScale", HFILL }},
{ &hf_charging_ase_callSetupChargeCurrency,
{ "callSetupChargeCurrency", "charging_ase.callSetupChargeCurrency_element",
FT_NONE, BASE_NONE, NULL, 0,
"CurrencyFactorScale", HFILL }},
{ &hf_charging_ase_currentTariffPulse,
{ "currentTariffPulse", "charging_ase.currentTariffPulse_element",
FT_NONE, BASE_NONE, NULL, 0,
"TariffPulseFormat", HFILL }},
{ &hf_charging_ase_tariffSwitchPulse,
{ "tariffSwitchPulse", "charging_ase.tariffSwitchPulse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_nextTariffPulse,
{ "nextTariffPulse", "charging_ase.nextTariffPulse_element",
FT_NONE, BASE_NONE, NULL, 0,
"TariffPulseFormat", HFILL }},
{ &hf_charging_ase_communicationChargeSequencePulse,
{ "communicationChargeSequencePulse", "charging_ase.communicationChargeSequencePulse",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse", HFILL }},
{ &hf_charging_ase_communicationChargeSequencePulse_item,
{ "CommunicationChargePulse", "charging_ase.CommunicationChargePulse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_tariffControlIndicators_01,
{ "tariffControlIndicators", "charging_ase.tariffControlIndicators",
FT_BYTES, BASE_NONE, NULL, 0,
"T_tariffControlIndicators_01", HFILL }},
{ &hf_charging_ase_callAttemptChargePulse,
{ "callAttemptChargePulse", "charging_ase.callAttemptChargePulse",
FT_BYTES, BASE_NONE, NULL, 0,
"PulseUnits", HFILL }},
{ &hf_charging_ase_callSetupChargePulse,
{ "callSetupChargePulse", "charging_ase.callSetupChargePulse",
FT_BYTES, BASE_NONE, NULL, 0,
"PulseUnits", HFILL }},
{ &hf_charging_ase_networkIdentification,
{ "networkIdentification", "charging_ase.networkIdentification",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_referenceID,
{ "referenceID", "charging_ase.referenceID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_charging_ase_T_acknowledgementIndicators_accepted,
{ "accepted", "charging_ase.accepted",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_charging_ase_ChargingControlIndicators_subscriberCharge,
{ "subscriberCharge", "charging_ase.subscriberCharge",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_charging_ase_ChargingControlIndicators_immediateChangeOfActuallyAppliedTariff,
{ "immediateChangeOfActuallyAppliedTariff", "charging_ase.immediateChangeOfActuallyAppliedTariff",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_charging_ase_ChargingControlIndicators_delayUntilStart,
{ "delayUntilStart", "charging_ase.delayUntilStart",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_charging_ase_T_stopIndicators_callAttemptChargesApplicable,
{ "callAttemptChargesApplicable", "charging_ase.callAttemptChargesApplicable",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_charging_ase_SubTariffControl_oneTimeCharge,
{ "oneTimeCharge", "charging_ase.oneTimeCharge",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_charging_ase_T_tariffControlIndicators_non_cyclicTariff,
{ "non-cyclicTariff", "charging_ase.non-cyclicTariff",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_charging_ase_T_tariffControlIndicators_01_non_cyclicTariff,
{ "non-cyclicTariff", "charging_ase.non-cyclicTariff",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
#line 77 "./asn1/charging_ase/packet-charging_ase-template.c"
};
static gint *ett[] = {
&ett_charging_ase,
#line 1 "./asn1/charging_ase/packet-charging_ase-ettarr.c"
&ett_charging_ase_ChargingMessageType,
&ett_charging_ase_ChargingAcknowledgementInformation,
&ett_charging_ase_T_acknowledgementIndicators,
&ett_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField,
&ett_charging_ase_ChargingControlIndicators,
&ett_charging_ase_AddOnChargingInformation,
&ett_charging_ase_T_addOncharge,
&ett_charging_ase_ChargingTariffInformation,
&ett_charging_ase_T_chargingTariff,
&ett_charging_ase_Code,
&ett_charging_ase_CommunicationChargeCurrency,
&ett_charging_ase_CommunicationChargePulse,
&ett_charging_ase_CurrencyFactorScale,
&ett_charging_ase_ExtensionField,
&ett_charging_ase_StartCharging,
&ett_charging_ase_SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification,
&ett_charging_ase_StopCharging,
&ett_charging_ase_T_stopIndicators,
&ett_charging_ase_SubTariffControl,
&ett_charging_ase_TariffCurrency,
&ett_charging_ase_TariffSwitchCurrency,
&ett_charging_ase_TariffCurrencyFormat,
&ett_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency,
&ett_charging_ase_T_tariffControlIndicators,
&ett_charging_ase_TariffPulse,
&ett_charging_ase_TariffSwitchPulse,
&ett_charging_ase_TariffPulseFormat,
&ett_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse,
&ett_charging_ase_T_tariffControlIndicators_01,
&ett_charging_ase_ChargingReferenceIdentification,
#line 83 "./asn1/charging_ase/packet-charging_ase-template.c"
};
static ei_register_info ei[] = {
{ &ei_charging_ase_extensions_not_dissected, { "charging_ase.extensions_not_dissected", PI_UNDECODED, PI_WARN, "Extensions not dissected", EXPFILL }},
};
expert_module_t* expert_charging_ase;
proto_charging_ase = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_charging_ase, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_charging_ase = expert_register_protocol(proto_charging_ase);
expert_register_field_array(expert_charging_ase, ei, array_length(ei));
}
void
proto_reg_handoff_charging_ase(void)
{
charging_ase_handle = create_dissector_handle(dissect_charging_ase, proto_charging_ase);
}
