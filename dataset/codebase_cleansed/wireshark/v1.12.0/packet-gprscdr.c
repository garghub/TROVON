static int
dissect_gprscdr_BCDDirectoryNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_CallDuration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_CallEventRecordType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_CallingNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gprscdr_BCDDirectoryNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gprscdr_CellId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_CNIPMulticastDistribution(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gprscdr_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gprscdr_T_information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 53 "../../asn1/gprscdr/gprscdr.cnf"
proto_tree_add_text(tree, tvb, offset, -1, "Not dissected");
return offset;
}
static int
dissect_gprscdr_ManagementExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ManagementExtension_sequence, hf_index, ett_gprscdr_ManagementExtension);
return offset;
}
static int
dissect_gprscdr_Diagnostics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Diagnostics_choice, hf_index, ett_gprscdr_Diagnostics,
NULL);
return offset;
}
static int
dissect_gprscdr_DiameterIdentity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_IPBinV4Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_IPBinV6Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_PDPAddressPrefixLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_IPBinV6AddressWithPrefixLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IPBinV6AddressWithPrefixLength_sequence, hf_index, ett_gprscdr_IPBinV6AddressWithPrefixLength);
return offset;
}
static int
dissect_gprscdr_IPBinV6AddressWithOrWithoutPrefixLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IPBinV6AddressWithOrWithoutPrefixLength_choice, hf_index, ett_gprscdr_IPBinV6AddressWithOrWithoutPrefixLength,
NULL);
return offset;
}
static int
dissect_gprscdr_IPBinaryAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IPBinaryAddress_choice, hf_index, ett_gprscdr_IPBinaryAddress,
NULL);
return offset;
}
static int
dissect_gprscdr_IA5String_SIZE_7_15(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_IA5String_SIZE_15_45(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_IPTextRepresentedAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IPTextRepresentedAddress_choice, hf_index, ett_gprscdr_IPTextRepresentedAddress,
NULL);
return offset;
}
static int
dissect_gprscdr_IPAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IPAddress_choice, hf_index, ett_gprscdr_IPAddress,
NULL);
return offset;
}
static int
dissect_gprscdr_GSNAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gprscdr_IPAddress(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gprscdr_LevelOfCAMELService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
LevelOfCAMELService_bits, hf_index, ett_gprscdr_LevelOfCAMELService,
NULL);
return offset;
}
static int
dissect_gprscdr_LocalSequenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_LocationAreaCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_ManagementExtensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ManagementExtensions_set_of, hf_index, ett_gprscdr_ManagementExtensions);
return offset;
}
static int
dissect_gprscdr_MBMS2G3GIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_TMGI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_MBMSSessionIdentity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_MBMSServiceType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_MBMSUserServiceType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_RoutingAreaCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_MBMSServiceArea(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_RequiredMBMSBearerCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_MBMSInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MBMSInformation_set, hf_index, ett_gprscdr_MBMSInformation);
return offset;
}
static int
dissect_gprscdr_MessageReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_MSISDN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_ISDN_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gprscdr_MSTimeZone(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 96 "../../asn1/gprscdr/gprscdr.cnf"
tvbuff_t *parameter_tvb;
guint8 data, data2;
char sign;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
data = tvb_get_guint8(parameter_tvb, 0);
sign = (data & 0x08) ? '-' : '+';
data = (data >> 4) + (data & 0x07) * 10;
data2 = tvb_get_guint8(tvb, 1) & 0x3;
proto_item_append_text(actx->created_item, " (GMT %c %d hours %d minutes %s)",
sign,
data / 4,
data % 4 * 15,
val_to_str_const(data2, gprscdr_daylight_saving_time_vals, "Unknown")
);
return offset;
}
static int
dissect_gprscdr_RecordingEntity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gprscdr_RecordType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_GraphicString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_ServiceSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceSpecificInfo_sequence, hf_index, ett_gprscdr_ServiceSpecificInfo);
return offset;
}
static int
dissect_gprscdr_SMSResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gprscdr_Diagnostics(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gprscdr_SmsTpDestinationNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_SubscriptionIDType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_UTF8String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_SubscriptionID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SubscriptionID_set, hf_index, ett_gprscdr_SubscriptionID);
return offset;
}
static int
dissect_gprscdr_TimeStamp(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 57 "../../asn1/gprscdr/gprscdr.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
proto_item_append_text(actx->created_item, " (UTC %x-%x-%x %x:%x:%x %s%x:%x)",
tvb_get_guint8(parameter_tvb,0),
tvb_get_guint8(parameter_tvb,1),
tvb_get_guint8(parameter_tvb,2),
tvb_get_guint8(parameter_tvb,3),
tvb_get_guint8(parameter_tvb,4),
tvb_get_guint8(parameter_tvb,5),
tvb_get_string_enc(wmem_packet_scope(), parameter_tvb,6,1,ENC_ASCII|ENC_NA),
tvb_get_guint8(parameter_tvb,7),
tvb_get_guint8(parameter_tvb,8)
);
return offset;
}
static int
dissect_gprscdr_NetworkInitiatedPDPContext(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gprscdr_MSNetworkCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_ChargingID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_AccessPointNameNI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_PDPType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_PDPAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PDPAddress_choice, hf_index, ett_gprscdr_PDPAddress,
NULL);
return offset;
}
static int
dissect_gprscdr_QoSInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_DataVolumeGPRS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_ChangeConditionV651(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_ChangeOfCharConditionV651(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChangeOfCharConditionV651_sequence, hf_index, ett_gprscdr_ChangeOfCharConditionV651);
return offset;
}
static int
dissect_gprscdr_SEQUENCE_OF_ChangeOfCharConditionV651(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ChangeOfCharConditionV651_sequence_of, hf_index, ett_gprscdr_SEQUENCE_OF_ChangeOfCharConditionV651);
return offset;
}
static int
dissect_gprscdr_SGSNChange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gprscdr_CauseForRecClosingV651(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_NodeID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_APNSelectionMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_AccessPointNameOI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_ChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_RATType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_SCFAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gprscdr_CAMELAccessPointNameNI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gprscdr_AccessPointNameNI(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gprscdr_CAMELAccessPointNameOI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gprscdr_AccessPointNameOI(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gprscdr_NumberOfDPEncountered(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_FreeFormatData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_FFDAppendIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gprscdr_CAMELInformationPDP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CAMELInformationPDP_set, hf_index, ett_gprscdr_CAMELInformationPDP);
return offset;
}
static int
dissect_gprscdr_ChChSelectionMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_DynamicAddressFlag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gprscdr_SGSNPDPRecordV651(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SGSNPDPRecordV651_set, hf_index, ett_gprscdr_SGSNPDPRecordV651);
return offset;
}
static int
dissect_gprscdr_SEQUENCE_OF_GSNAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_GSNAddress_sequence_of, hf_index, ett_gprscdr_SEQUENCE_OF_GSNAddress);
return offset;
}
static int
dissect_gprscdr_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gprscdr_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_PLMN_Id(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 123 "../../asn1/gprscdr/gprscdr.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gprscdr_plmn_id);
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, subtree, 0, TRUE);
return offset;
}
static int
dissect_gprscdr_GGSNPDPRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
GGSNPDPRecord_set, hf_index, ett_gprscdr_GGSNPDPRecord);
return offset;
}
static int
dissect_gprscdr_ChangeLocation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChangeLocation_sequence, hf_index, ett_gprscdr_ChangeLocation);
return offset;
}
static int
dissect_gprscdr_SEQUENCE_OF_ChangeLocation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ChangeLocation_sequence_of, hf_index, ett_gprscdr_SEQUENCE_OF_ChangeLocation);
return offset;
}
static int
dissect_gprscdr_CauseForRecClosing(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_CAMELInformationMM(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CAMELInformationMM_set, hf_index, ett_gprscdr_CAMELInformationMM);
return offset;
}
static int
dissect_gprscdr_SGSNMMRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SGSNMMRecord_set, hf_index, ett_gprscdr_SGSNMMRecord);
return offset;
}
static int
dissect_gprscdr_CAMELInformationSMS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CAMELInformationSMS_set, hf_index, ett_gprscdr_CAMELInformationSMS);
return offset;
}
static int
dissect_gprscdr_SGSNSMORecordV651(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SGSNSMORecordV651_set, hf_index, ett_gprscdr_SGSNSMORecordV651);
return offset;
}
static int
dissect_gprscdr_SGSNSMTRecordV651(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SGSNSMTRecordV651_set, hf_index, ett_gprscdr_SGSNSMTRecordV651);
return offset;
}
static int
dissect_gprscdr_PSFurnishChargingInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PSFurnishChargingInformation_sequence, hf_index, ett_gprscdr_PSFurnishChargingInformation);
return offset;
}
static int
dissect_gprscdr_RatingGroupId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_ChargingRuleBaseName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_ResultCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_ServiceConditionChangeV651(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
ServiceConditionChangeV651_bits, hf_index, ett_gprscdr_ServiceConditionChangeV651,
NULL);
return offset;
}
static int
dissect_gprscdr_FailureHandlingContinue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gprscdr_ServiceIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_ChangeOfServiceConditionV651(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChangeOfServiceConditionV651_sequence, hf_index, ett_gprscdr_ChangeOfServiceConditionV651);
return offset;
}
static int
dissect_gprscdr_SEQUENCE_OF_ChangeOfServiceConditionV651(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ChangeOfServiceConditionV651_sequence_of, hf_index, ett_gprscdr_SEQUENCE_OF_ChangeOfServiceConditionV651);
return offset;
}
static int
dissect_gprscdr_EGSNPDPRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
EGSNPDPRecord_set, hf_index, ett_gprscdr_EGSNPDPRecord);
return offset;
}
int
dissect_gprscdr_GPRSCallEventRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GPRSCallEventRecord_choice, hf_index, ett_gprscdr_GPRSCallEventRecord,
NULL);
return offset;
}
static int
dissect_gprscdr_ChangeCondition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_EPCQoSInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EPCQoSInformation_sequence, hf_index, ett_gprscdr_EPCQoSInformation);
return offset;
}
static int
dissect_gprscdr_ChangeOfCharCondition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChangeOfCharCondition_sequence, hf_index, ett_gprscdr_ChangeOfCharCondition);
return offset;
}
static int
dissect_gprscdr_SEQUENCE_OF_ChangeOfCharCondition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ChangeOfCharCondition_sequence_of, hf_index, ett_gprscdr_SEQUENCE_OF_ChangeOfCharCondition);
return offset;
}
static int
dissect_gprscdr_CSGId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_CSGAccessMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_UserCSGInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UserCSGInformation_sequence, hf_index, ett_gprscdr_UserCSGInformation);
return offset;
}
static int
dissect_gprscdr_SGSNPDPRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SGSNPDPRecord_set, hf_index, ett_gprscdr_SGSNPDPRecord);
return offset;
}
static int
dissect_gprscdr_ServingNodeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_SGSNSMORecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SGSNSMORecord_set, hf_index, ett_gprscdr_SGSNSMORecord);
return offset;
}
static int
dissect_gprscdr_SGSNSMTRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SGSNSMTRecord_set, hf_index, ett_gprscdr_SGSNSMTRecord);
return offset;
}
static int
dissect_gprscdr_SGWChange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gprscdr_SEQUENCE_OF_ServingNodeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ServingNodeType_sequence_of, hf_index, ett_gprscdr_SEQUENCE_OF_ServingNodeType);
return offset;
}
static int
dissect_gprscdr_SGWRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SGWRecord_set, hf_index, ett_gprscdr_SGWRecord);
return offset;
}
static int
dissect_gprscdr_ServiceConditionChange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
ServiceConditionChange_bits, hf_index, ett_gprscdr_ServiceConditionChange,
NULL);
return offset;
}
static int
dissect_gprscdr_AFChargingIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_T_flowNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_flowNumber_sequence_of, hf_index, ett_gprscdr_T_flowNumber);
return offset;
}
static int
dissect_gprscdr_Flows(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Flows_sequence, hf_index, ett_gprscdr_Flows);
return offset;
}
static int
dissect_gprscdr_AFRecordInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AFRecordInformation_sequence, hf_index, ett_gprscdr_AFRecordInformation);
return offset;
}
static int
dissect_gprscdr_SEQUENCE_OF_AFRecordInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_AFRecordInformation_sequence_of, hf_index, ett_gprscdr_SEQUENCE_OF_AFRecordInformation);
return offset;
}
static int
dissect_gprscdr_SEQUENCE_OF_TimeStamp(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_TimeStamp_sequence_of, hf_index, ett_gprscdr_SEQUENCE_OF_TimeStamp);
return offset;
}
static int
dissect_gprscdr_EventBasedChargingInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventBasedChargingInformation_sequence, hf_index, ett_gprscdr_EventBasedChargingInformation);
return offset;
}
static int
dissect_gprscdr_TimeQuotaType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gprscdr_TimeQuotaMechanism(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TimeQuotaMechanism_sequence, hf_index, ett_gprscdr_TimeQuotaMechanism);
return offset;
}
static int
dissect_gprscdr_SEQUENCE_OF_ServiceSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ServiceSpecificInfo_sequence_of, hf_index, ett_gprscdr_SEQUENCE_OF_ServiceSpecificInfo);
return offset;
}
static int
dissect_gprscdr_ChangeOfServiceCondition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChangeOfServiceCondition_sequence, hf_index, ett_gprscdr_ChangeOfServiceCondition);
return offset;
}
static int
dissect_gprscdr_SEQUENCE_OF_ChangeOfServiceCondition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ChangeOfServiceCondition_sequence_of, hf_index, ett_gprscdr_SEQUENCE_OF_ChangeOfServiceCondition);
return offset;
}
static int
dissect_gprscdr_TWANUserLocationInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TWANUserLocationInfo_sequence, hf_index, ett_gprscdr_TWANUserLocationInfo);
return offset;
}
static int
dissect_gprscdr_PGWRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PGWRecord_set, hf_index, ett_gprscdr_PGWRecord);
return offset;
}
int
dissect_gprscdr_GPRSRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GPRSRecord_choice, hf_index, ett_gprscdr_GPRSRecord,
NULL);
return offset;
}
int dissect_gprscdr_GPRSCallEventRecord_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_gprscdr_GPRSCallEventRecord(FALSE, tvb, offset, &asn1_ctx, tree, hf_gprscdr_gprscdr_GPRSCallEventRecord_PDU);
return offset;
}
int dissect_gprscdr_GPRSRecord_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_gprscdr_GPRSRecord(FALSE, tvb, offset, &asn1_ctx, tree, hf_gprscdr_gprscdr_GPRSRecord_PDU);
return offset;
}
void
proto_register_gprscdr(void)
{
static hf_register_info hf[] = {
#line 1 "../../asn1/gprscdr/packet-gprscdr-hfarr.c"
{ &hf_gprscdr_gprscdr_GPRSCallEventRecord_PDU,
{ "GPRSCallEventRecord", "gprscdr.GPRSCallEventRecord",
FT_UINT32, BASE_DEC, VALS(gprscdr_GPRSCallEventRecord_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_gprscdr_GPRSRecord_PDU,
{ "GPRSRecord", "gprscdr.GPRSRecord",
FT_UINT32, BASE_DEC, VALS(gprscdr_GPRSRecord_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_gsm0408Cause,
{ "gsm0408Cause", "gprscdr.gsm0408Cause",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_gsm0902MapErrorValue,
{ "gsm0902MapErrorValue", "gprscdr.gsm0902MapErrorValue",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_itu_tQ767Cause,
{ "itu-tQ767Cause", "gprscdr.itu_tQ767Cause",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_networkSpecificCause,
{ "networkSpecificCause", "gprscdr.networkSpecificCause_element",
FT_NONE, BASE_NONE, NULL, 0,
"ManagementExtension", HFILL }},
{ &hf_gprscdr_manufacturerSpecificCause,
{ "manufacturerSpecificCause", "gprscdr.manufacturerSpecificCause_element",
FT_NONE, BASE_NONE, NULL, 0,
"ManagementExtension", HFILL }},
{ &hf_gprscdr_positionMethodFailureCause,
{ "positionMethodFailureCause", "gprscdr.positionMethodFailureCause",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_PositionMethodFailure_Diagnostic_vals), 0,
"PositionMethodFailure_Diagnostic", HFILL }},
{ &hf_gprscdr_unauthorizedLCSClientCause,
{ "unauthorizedLCSClientCause", "gprscdr.unauthorizedLCSClientCause",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_UnauthorizedLCSClient_Diagnostic_vals), 0,
"UnauthorizedLCSClient_Diagnostic", HFILL }},
{ &hf_gprscdr_diameterResultCodeAndExperimentalResult,
{ "diameterResultCodeAndExperimentalResult", "gprscdr.diameterResultCodeAndExperimentalResult",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_iPBinaryAddress,
{ "iPBinaryAddress", "gprscdr.iPBinaryAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPBinaryAddress_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_iPTextRepresentedAddress,
{ "iPTextRepresentedAddress", "gprscdr.iPTextRepresentedAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPTextRepresentedAddress_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_iPBinV4Address,
{ "iPBinV4Address", "gprscdr.iPBinV4Address",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_iPBinV6Address,
{ "iPBinV6Address", "gprscdr.iPBinV6Address",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPBinV6AddressWithOrWithoutPrefixLength_vals), 0,
"IPBinV6AddressWithOrWithoutPrefixLength", HFILL }},
{ &hf_gprscdr_iPBinV6Address_01,
{ "iPBinV6Address", "gprscdr.iPBinV6Address",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_iPBinV6AddressWithPrefix,
{ "iPBinV6AddressWithPrefix", "gprscdr.iPBinV6AddressWithPrefix_element",
FT_NONE, BASE_NONE, NULL, 0,
"IPBinV6AddressWithPrefixLength", HFILL }},
{ &hf_gprscdr_pDPAddressPrefixLength,
{ "pDPAddressPrefixLength", "gprscdr.pDPAddressPrefixLength",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_iPTextV4Address,
{ "iPTextV4Address", "gprscdr.iPTextV4Address",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_7_15", HFILL }},
{ &hf_gprscdr_iPTextV6Address,
{ "iPTextV6Address", "gprscdr.iPTextV6Address",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_15_45", HFILL }},
{ &hf_gprscdr_ManagementExtensions_item,
{ "ManagementExtension", "gprscdr.ManagementExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_tMGI,
{ "tMGI", "gprscdr.tMGI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_mBMSSessionIdentity,
{ "mBMSSessionIdentity", "gprscdr.mBMSSessionIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_mBMSServiceType,
{ "mBMSServiceType", "gprscdr.mBMSServiceType",
FT_UINT32, BASE_DEC, VALS(gprscdr_MBMSServiceType_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_mBMSUserServiceType,
{ "mBMSUserServiceType", "gprscdr.mBMSUserServiceType",
FT_UINT32, BASE_DEC, VALS(gprscdr_MBMSUserServiceType_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_mBMS2G3GIndicator,
{ "mBMS2G3GIndicator", "gprscdr.mBMS2G3GIndicator",
FT_UINT32, BASE_DEC, VALS(gprscdr_MBMS2G3GIndicator_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_fileRepairSupported,
{ "fileRepairSupported", "gprscdr.fileRepairSupported",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gprscdr_rAI,
{ "rAI", "gprscdr.rAI",
FT_BYTES, BASE_NONE, NULL, 0,
"RoutingAreaCode", HFILL }},
{ &hf_gprscdr_mBMSServiceArea,
{ "mBMSServiceArea", "gprscdr.mBMSServiceArea",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_requiredMBMSBearerCaps,
{ "requiredMBMSBearerCaps", "gprscdr.requiredMBMSBearerCaps",
FT_BYTES, BASE_NONE, NULL, 0,
"RequiredMBMSBearerCapabilities", HFILL }},
{ &hf_gprscdr_mBMSGWAddress,
{ "mBMSGWAddress", "gprscdr.mBMSGWAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_cNIPMulticastDistribution,
{ "cNIPMulticastDistribution", "gprscdr.cNIPMulticastDistribution",
FT_UINT32, BASE_DEC, VALS(gprscdr_CNIPMulticastDistribution_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_serviceSpecificData,
{ "serviceSpecificData", "gprscdr.serviceSpecificData",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_gprscdr_serviceSpecificType,
{ "serviceSpecificType", "gprscdr.serviceSpecificType",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_subscriptionIDType,
{ "subscriptionIDType", "gprscdr.subscriptionIDType",
FT_UINT32, BASE_DEC, VALS(gprscdr_SubscriptionIDType_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_subscriptionIDData,
{ "subscriptionIDData", "gprscdr.subscriptionIDData",
FT_STRING, BASE_NONE, NULL, 0,
"UTF8String", HFILL }},
{ &hf_gprscdr_identifier,
{ "identifier", "gprscdr.identifier",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_gprscdr_significance,
{ "significance", "gprscdr.significance",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gprscdr_information,
{ "information", "gprscdr.information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_sgsnPDPRecord,
{ "sgsnPDPRecord", "gprscdr.sgsnPDPRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
"SGSNPDPRecordV651", HFILL }},
{ &hf_gprscdr_ggsnPDPRecord,
{ "ggsnPDPRecord", "gprscdr.ggsnPDPRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_sgsnMMRecord,
{ "sgsnMMRecord", "gprscdr.sgsnMMRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_sgsnSMORecord,
{ "sgsnSMORecord", "gprscdr.sgsnSMORecord_element",
FT_NONE, BASE_NONE, NULL, 0,
"SGSNSMORecordV651", HFILL }},
{ &hf_gprscdr_sgsnSMTRecord,
{ "sgsnSMTRecord", "gprscdr.sgsnSMTRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
"SGSNSMTRecordV651", HFILL }},
{ &hf_gprscdr_egsnPDPRecord,
{ "egsnPDPRecord", "gprscdr.egsnPDPRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_recordType,
{ "recordType", "gprscdr.recordType",
FT_INT32, BASE_DEC, VALS(gprscdr_CallEventRecordType_vals), 0,
"CallEventRecordType", HFILL }},
{ &hf_gprscdr_networkInitiation,
{ "networkInitiation", "gprscdr.networkInitiation",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"NetworkInitiatedPDPContext", HFILL }},
{ &hf_gprscdr_servedIMSI,
{ "servedIMSI", "gprscdr.servedIMSI",
FT_BYTES, BASE_NONE, NULL, 0,
"IMSI", HFILL }},
{ &hf_gprscdr_ggsnAddress,
{ "ggsnAddress", "gprscdr.ggsnAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_chargingID,
{ "chargingID", "gprscdr.chargingID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_sgsnAddress,
{ "sgsnAddress", "gprscdr.sgsnAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_GSNAddress", HFILL }},
{ &hf_gprscdr_sgsnAddress_item,
{ "GSNAddress", "gprscdr.GSNAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_accessPointNameNI,
{ "accessPointNameNI", "gprscdr.accessPointNameNI",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_pdpType,
{ "pdpType", "gprscdr.pdpType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_servedPDPAddress,
{ "servedPDPAddress", "gprscdr.servedPDPAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_PDPAddress_vals), 0,
"PDPAddress", HFILL }},
{ &hf_gprscdr_dynamicAddressFlag,
{ "dynamicAddressFlag", "gprscdr.dynamicAddressFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_listOfTrafficVolumes,
{ "listOfTrafficVolumes", "gprscdr.listOfTrafficVolumes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ChangeOfCharConditionV651", HFILL }},
{ &hf_gprscdr_listOfTrafficVolumes_item,
{ "ChangeOfCharConditionV651", "gprscdr.ChangeOfCharConditionV651_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_recordOpeningTime,
{ "recordOpeningTime", "gprscdr.recordOpeningTime",
FT_BYTES, BASE_NONE, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_gprscdr_duration,
{ "duration", "gprscdr.duration",
FT_INT32, BASE_DEC, NULL, 0,
"CallDuration", HFILL }},
{ &hf_gprscdr_causeForRecClosing,
{ "causeForRecClosing", "gprscdr.causeForRecClosing",
FT_INT32, BASE_DEC, VALS(gprscdr_CauseForRecClosingV651_vals), 0,
"CauseForRecClosingV651", HFILL }},
{ &hf_gprscdr_diagnostics,
{ "diagnostics", "gprscdr.diagnostics",
FT_UINT32, BASE_DEC, VALS(gprscdr_Diagnostics_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_recordSequenceNumber,
{ "recordSequenceNumber", "gprscdr.recordSequenceNumber",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_nodeID,
{ "nodeID", "gprscdr.nodeID",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_recordExtensions,
{ "recordExtensions", "gprscdr.recordExtensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ManagementExtensions", HFILL }},
{ &hf_gprscdr_localSequenceNumber,
{ "localSequenceNumber", "gprscdr.localSequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_apnSelectionMode,
{ "apnSelectionMode", "gprscdr.apnSelectionMode",
FT_UINT32, BASE_DEC, VALS(gprscdr_APNSelectionMode_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_servedMSISDN,
{ "servedMSISDN", "gprscdr.servedMSISDN",
FT_BYTES, BASE_NONE, NULL, 0,
"MSISDN", HFILL }},
{ &hf_gprscdr_chargingCharacteristics,
{ "chargingCharacteristics", "gprscdr.chargingCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_chChSelectionMode,
{ "chChSelectionMode", "gprscdr.chChSelectionMode",
FT_UINT32, BASE_DEC, VALS(gprscdr_ChChSelectionMode_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_iMSsignalingContext,
{ "iMSsignalingContext", "gprscdr.iMSsignalingContext_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_externalChargingID,
{ "externalChargingID", "gprscdr.externalChargingID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_gprscdr_sgsnPLMNIdentifier,
{ "sgsnPLMNIdentifier", "gprscdr.sgsnPLMNIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Id", HFILL }},
{ &hf_gprscdr_servedIMEISV,
{ "servedIMEISV", "gprscdr.servedIMEISV",
FT_BYTES, BASE_NONE, NULL, 0,
"IMEI", HFILL }},
{ &hf_gprscdr_rATType,
{ "rATType", "gprscdr.rATType",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_mSTimeZone,
{ "mSTimeZone", "gprscdr.mSTimeZone",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_userLocationInformation,
{ "userLocationInformation", "gprscdr.userLocationInformation",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_gprscdr_cAMELChargingInformation,
{ "cAMELChargingInformation", "gprscdr.cAMELChargingInformation",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_gprscdr_pSFurnishChargingInformation,
{ "pSFurnishChargingInformation", "gprscdr.pSFurnishChargingInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_listOfServiceData,
{ "listOfServiceData", "gprscdr.listOfServiceData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ChangeOfServiceConditionV651", HFILL }},
{ &hf_gprscdr_listOfServiceData_item,
{ "ChangeOfServiceConditionV651", "gprscdr.ChangeOfServiceConditionV651_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_servedIMEI,
{ "servedIMEI", "gprscdr.servedIMEI",
FT_BYTES, BASE_NONE, NULL, 0,
"IMEI", HFILL }},
{ &hf_gprscdr_sgsnAddress_01,
{ "sgsnAddress", "gprscdr.sgsnAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_msNetworkCapability,
{ "msNetworkCapability", "gprscdr.msNetworkCapability",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_routingArea,
{ "routingArea", "gprscdr.routingArea",
FT_BYTES, BASE_NONE, NULL, 0,
"RoutingAreaCode", HFILL }},
{ &hf_gprscdr_locationAreaCode,
{ "locationAreaCode", "gprscdr.locationAreaCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_cellIdentifier,
{ "cellIdentifier", "gprscdr.cellIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"CellId", HFILL }},
{ &hf_gprscdr_ggsnAddressUsed,
{ "ggsnAddressUsed", "gprscdr.ggsnAddressUsed",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_sgsnChange,
{ "sgsnChange", "gprscdr.sgsnChange",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_accessPointNameOI,
{ "accessPointNameOI", "gprscdr.accessPointNameOI",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_cAMELInformationPDP,
{ "cAMELInformationPDP", "gprscdr.cAMELInformationPDP_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_rNCUnsentDownlinkVolume,
{ "rNCUnsentDownlinkVolume", "gprscdr.rNCUnsentDownlinkVolume",
FT_INT32, BASE_DEC, NULL, 0,
"DataVolumeGPRS", HFILL }},
{ &hf_gprscdr_serviceCentre,
{ "serviceCentre", "gprscdr.serviceCentre",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gprscdr_recordingEntity,
{ "recordingEntity", "gprscdr.recordingEntity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_locationArea,
{ "locationArea", "gprscdr.locationArea",
FT_BYTES, BASE_NONE, NULL, 0,
"LocationAreaCode", HFILL }},
{ &hf_gprscdr_messageReference,
{ "messageReference", "gprscdr.messageReference",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_eventTimeStamp,
{ "eventTimeStamp", "gprscdr.eventTimeStamp",
FT_BYTES, BASE_NONE, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_gprscdr_smsResult,
{ "smsResult", "gprscdr.smsResult",
FT_UINT32, BASE_DEC, VALS(gprscdr_Diagnostics_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_destinationNumber,
{ "destinationNumber", "gprscdr.destinationNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"SmsTpDestinationNumber", HFILL }},
{ &hf_gprscdr_cAMELInformationSMS,
{ "cAMELInformationSMS", "gprscdr.cAMELInformationSMS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_qosRequested,
{ "qosRequested", "gprscdr.qosRequested",
FT_BYTES, BASE_NONE, NULL, 0,
"QoSInformation", HFILL }},
{ &hf_gprscdr_qosNegotiated,
{ "qosNegotiated", "gprscdr.qosNegotiated",
FT_BYTES, BASE_NONE, NULL, 0,
"QoSInformation", HFILL }},
{ &hf_gprscdr_dataVolumeGPRSUplink,
{ "dataVolumeGPRSUplink", "gprscdr.dataVolumeGPRSUplink",
FT_INT32, BASE_DEC, NULL, 0,
"DataVolumeGPRS", HFILL }},
{ &hf_gprscdr_dataVolumeGPRSDownlink,
{ "dataVolumeGPRSDownlink", "gprscdr.dataVolumeGPRSDownlink",
FT_INT32, BASE_DEC, NULL, 0,
"DataVolumeGPRS", HFILL }},
{ &hf_gprscdr_changeCondition,
{ "changeCondition", "gprscdr.changeCondition",
FT_UINT32, BASE_DEC, VALS(gprscdr_ChangeConditionV651_vals), 0,
"ChangeConditionV651", HFILL }},
{ &hf_gprscdr_changeTime,
{ "changeTime", "gprscdr.changeTime",
FT_BYTES, BASE_NONE, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_gprscdr_ratingGroup,
{ "ratingGroup", "gprscdr.ratingGroup",
FT_INT32, BASE_DEC, NULL, 0,
"RatingGroupId", HFILL }},
{ &hf_gprscdr_chargingRuleBaseName,
{ "chargingRuleBaseName", "gprscdr.chargingRuleBaseName",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_resultCode,
{ "resultCode", "gprscdr.resultCode",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_timeOfFirstUsage,
{ "timeOfFirstUsage", "gprscdr.timeOfFirstUsage",
FT_BYTES, BASE_NONE, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_gprscdr_timeOfLastUsage,
{ "timeOfLastUsage", "gprscdr.timeOfLastUsage",
FT_BYTES, BASE_NONE, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_gprscdr_timeUsage,
{ "timeUsage", "gprscdr.timeUsage",
FT_INT32, BASE_DEC, NULL, 0,
"CallDuration", HFILL }},
{ &hf_gprscdr_serviceConditionChange,
{ "serviceConditionChange", "gprscdr.serviceConditionChange",
FT_BYTES, BASE_NONE, NULL, 0,
"ServiceConditionChangeV651", HFILL }},
{ &hf_gprscdr_qoSInformationNeg,
{ "qoSInformationNeg", "gprscdr.qoSInformationNeg",
FT_BYTES, BASE_NONE, NULL, 0,
"QoSInformation", HFILL }},
{ &hf_gprscdr_sgsn_Address,
{ "sgsn-Address", "gprscdr.sgsn_Address",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_sGSNPLMNIdentifier,
{ "sGSNPLMNIdentifier", "gprscdr.sGSNPLMNIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Id", HFILL }},
{ &hf_gprscdr_datavolumeFBCUplink,
{ "datavolumeFBCUplink", "gprscdr.datavolumeFBCUplink",
FT_INT32, BASE_DEC, NULL, 0,
"DataVolumeGPRS", HFILL }},
{ &hf_gprscdr_datavolumeFBCDownlink,
{ "datavolumeFBCDownlink", "gprscdr.datavolumeFBCDownlink",
FT_INT32, BASE_DEC, NULL, 0,
"DataVolumeGPRS", HFILL }},
{ &hf_gprscdr_timeOfReport,
{ "timeOfReport", "gprscdr.timeOfReport",
FT_BYTES, BASE_NONE, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_gprscdr_failureHandlingContinue,
{ "failureHandlingContinue", "gprscdr.failureHandlingContinue",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_serviceIdentifier,
{ "serviceIdentifier", "gprscdr.serviceIdentifier",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_sgsnPDPRecord_01,
{ "sgsnPDPRecord", "gprscdr.sgsnPDPRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_sgsnSMORecord_01,
{ "sgsnSMORecord", "gprscdr.sgsnSMORecord_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_sgsnSMTRecord_01,
{ "sgsnSMTRecord", "gprscdr.sgsnSMTRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_sGWRecord,
{ "sGWRecord", "gprscdr.sGWRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_pGWRecord,
{ "pGWRecord", "gprscdr.pGWRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_recordType_01,
{ "recordType", "gprscdr.recordType",
FT_INT32, BASE_DEC, VALS(gprscdr_RecordType_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_s_GWAddress,
{ "s-GWAddress", "gprscdr.s_GWAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_servingNodeAddress,
{ "servingNodeAddress", "gprscdr.servingNodeAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_GSNAddress", HFILL }},
{ &hf_gprscdr_servingNodeAddress_item,
{ "GSNAddress", "gprscdr.GSNAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_pdpPDNType,
{ "pdpPDNType", "gprscdr.pdpPDNType",
FT_BYTES, BASE_NONE, NULL, 0,
"PDPType", HFILL }},
{ &hf_gprscdr_servedPDPPDNAddress,
{ "servedPDPPDNAddress", "gprscdr.servedPDPPDNAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_PDPAddress_vals), 0,
"PDPAddress", HFILL }},
{ &hf_gprscdr_listOfTrafficVolumes_01,
{ "listOfTrafficVolumes", "gprscdr.listOfTrafficVolumes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ChangeOfCharCondition", HFILL }},
{ &hf_gprscdr_listOfTrafficVolumes_item_01,
{ "ChangeOfCharCondition", "gprscdr.ChangeOfCharCondition_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_causeForRecClosing_01,
{ "causeForRecClosing", "gprscdr.causeForRecClosing",
FT_INT32, BASE_DEC, VALS(gprscdr_CauseForRecClosing_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_servingNodePLMNIdentifier,
{ "servingNodePLMNIdentifier", "gprscdr.servingNodePLMNIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Id", HFILL }},
{ &hf_gprscdr_sGWChange,
{ "sGWChange", "gprscdr.sGWChange",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_servingNodeType,
{ "servingNodeType", "gprscdr.servingNodeType",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ServingNodeType", HFILL }},
{ &hf_gprscdr_servingNodeType_item,
{ "ServingNodeType", "gprscdr.ServingNodeType",
FT_UINT32, BASE_DEC, VALS(gprscdr_ServingNodeType_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_p_GWAddressUsed,
{ "p-GWAddressUsed", "gprscdr.p_GWAddressUsed",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_p_GWPLMNIdentifier,
{ "p-GWPLMNIdentifier", "gprscdr.p_GWPLMNIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Id", HFILL }},
{ &hf_gprscdr_startTime,
{ "startTime", "gprscdr.startTime",
FT_BYTES, BASE_NONE, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_gprscdr_stopTime,
{ "stopTime", "gprscdr.stopTime",
FT_BYTES, BASE_NONE, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_gprscdr_pDNConnectionChargingID,
{ "pDNConnectionChargingID", "gprscdr.pDNConnectionChargingID",
FT_UINT32, BASE_DEC, NULL, 0,
"ChargingID", HFILL }},
{ &hf_gprscdr_iMSIunauthenticatedFlag,
{ "iMSIunauthenticatedFlag", "gprscdr.iMSIunauthenticatedFlag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_userCSGInformation,
{ "userCSGInformation", "gprscdr.userCSGInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_servedPDPPDNAddressExt,
{ "servedPDPPDNAddressExt", "gprscdr.servedPDPPDNAddressExt",
FT_UINT32, BASE_DEC, VALS(gprscdr_PDPAddress_vals), 0,
"PDPAddress", HFILL }},
{ &hf_gprscdr_lowPriorityIndicator,
{ "lowPriorityIndicator", "gprscdr.lowPriorityIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_dynamicAddressFlagExt,
{ "dynamicAddressFlagExt", "gprscdr.dynamicAddressFlagExt",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"DynamicAddressFlag", HFILL }},
{ &hf_gprscdr_s_GWiPv6Address,
{ "s-GWiPv6Address", "gprscdr.s_GWiPv6Address",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_servingNodeiPv6Address,
{ "servingNodeiPv6Address", "gprscdr.servingNodeiPv6Address",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_GSNAddress", HFILL }},
{ &hf_gprscdr_servingNodeiPv6Address_item,
{ "GSNAddress", "gprscdr.GSNAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_p_GWiPv6AddressUsed,
{ "p-GWiPv6AddressUsed", "gprscdr.p_GWiPv6AddressUsed",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_p_GWAddress,
{ "p-GWAddress", "gprscdr.p_GWAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_servinggNodePLMNIdentifier,
{ "servinggNodePLMNIdentifier", "gprscdr.servinggNodePLMNIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Id", HFILL }},
{ &hf_gprscdr_listOfServiceData_01,
{ "listOfServiceData", "gprscdr.listOfServiceData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ChangeOfServiceCondition", HFILL }},
{ &hf_gprscdr_listOfServiceData_item_01,
{ "ChangeOfServiceCondition", "gprscdr.ChangeOfServiceCondition_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_servedMNNAI,
{ "servedMNNAI", "gprscdr.servedMNNAI_element",
FT_NONE, BASE_NONE, NULL, 0,
"SubscriptionID", HFILL }},
{ &hf_gprscdr_served3gpp2MEID,
{ "served3gpp2MEID", "gprscdr.served3gpp2MEID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_gprscdr_threeGPP2UserLocationInformation,
{ "threeGPP2UserLocationInformation", "gprscdr.threeGPP2UserLocationInformation",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_gprscdr_tWANUserLocationInformation,
{ "tWANUserLocationInformation", "gprscdr.tWANUserLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"TWANUserLocationInfo", HFILL }},
{ &hf_gprscdr_changeLocation,
{ "changeLocation", "gprscdr.changeLocation",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ChangeLocation", HFILL }},
{ &hf_gprscdr_changeLocation_item,
{ "ChangeLocation", "gprscdr.ChangeLocation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_cAMELInformationMM,
{ "cAMELInformationMM", "gprscdr.cAMELInformationMM_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_cellPLMNId,
{ "cellPLMNId", "gprscdr.cellPLMNId",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Id", HFILL }},
{ &hf_gprscdr_servingNodeType_01,
{ "servingNodeType", "gprscdr.servingNodeType",
FT_UINT32, BASE_DEC, VALS(gprscdr_ServingNodeType_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_servingNodeAddress_01,
{ "servingNodeAddress", "gprscdr.servingNodeAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_servingNodeiPv6Address_01,
{ "servingNodeiPv6Address", "gprscdr.servingNodeiPv6Address",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
"GSNAddress", HFILL }},
{ &hf_gprscdr_mMEName,
{ "mMEName", "gprscdr.mMEName",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gprscdr_mMERealm,
{ "mMERealm", "gprscdr.mMERealm",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gprscdr_originatingAddress,
{ "originatingAddress", "gprscdr.originatingAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gprscdr_aFChargingIdentifier,
{ "aFChargingIdentifier", "gprscdr.aFChargingIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_flows,
{ "flows", "gprscdr.flows_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_sCFAddress,
{ "sCFAddress", "gprscdr.sCFAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_serviceKey,
{ "serviceKey", "gprscdr.serviceKey",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_defaultTransactionHandling,
{ "defaultTransactionHandling", "gprscdr.defaultTransactionHandling",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_DefaultGPRS_Handling_vals), 0,
"DefaultGPRS_Handling", HFILL }},
{ &hf_gprscdr_numberOfDPEncountered,
{ "numberOfDPEncountered", "gprscdr.numberOfDPEncountered",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_levelOfCAMELService,
{ "levelOfCAMELService", "gprscdr.levelOfCAMELService",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_freeFormatData,
{ "freeFormatData", "gprscdr.freeFormatData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_fFDAppendIndicator,
{ "fFDAppendIndicator", "gprscdr.fFDAppendIndicator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_cAMELAccessPointNameNI,
{ "cAMELAccessPointNameNI", "gprscdr.cAMELAccessPointNameNI",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_cAMELAccessPointNameOI,
{ "cAMELAccessPointNameOI", "gprscdr.cAMELAccessPointNameOI",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_defaultSMSHandling,
{ "defaultSMSHandling", "gprscdr.defaultSMSHandling",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_DefaultSMS_Handling_vals), 0,
"DefaultSMS_Handling", HFILL }},
{ &hf_gprscdr_cAMELCallingPartyNumber,
{ "cAMELCallingPartyNumber", "gprscdr.cAMELCallingPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"CallingNumber", HFILL }},
{ &hf_gprscdr_cAMELDestinationSubscriberNumber,
{ "cAMELDestinationSubscriberNumber", "gprscdr.cAMELDestinationSubscriberNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"SmsTpDestinationNumber", HFILL }},
{ &hf_gprscdr_cAMELSMSCAddress,
{ "cAMELSMSCAddress", "gprscdr.cAMELSMSCAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gprscdr_smsReferenceNumber,
{ "smsReferenceNumber", "gprscdr.smsReferenceNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"CallReferenceNumber", HFILL }},
{ &hf_gprscdr_changeCondition_01,
{ "changeCondition", "gprscdr.changeCondition",
FT_UINT32, BASE_DEC, VALS(gprscdr_ChangeCondition_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_ePCQoSInformation,
{ "ePCQoSInformation", "gprscdr.ePCQoSInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_serviceConditionChange_01,
{ "serviceConditionChange", "gprscdr.serviceConditionChange",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_qoSInformationNeg_01,
{ "qoSInformationNeg", "gprscdr.qoSInformationNeg_element",
FT_NONE, BASE_NONE, NULL, 0,
"EPCQoSInformation", HFILL }},
{ &hf_gprscdr_aFRecordInformation,
{ "aFRecordInformation", "gprscdr.aFRecordInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AFRecordInformation", HFILL }},
{ &hf_gprscdr_aFRecordInformation_item,
{ "AFRecordInformation", "gprscdr.AFRecordInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_eventBasedChargingInformation,
{ "eventBasedChargingInformation", "gprscdr.eventBasedChargingInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_timeQuotaMechanism,
{ "timeQuotaMechanism", "gprscdr.timeQuotaMechanism_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_serviceSpecificInfo,
{ "serviceSpecificInfo", "gprscdr.serviceSpecificInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ServiceSpecificInfo", HFILL }},
{ &hf_gprscdr_serviceSpecificInfo_item,
{ "ServiceSpecificInfo", "gprscdr.ServiceSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_sponsorIdentity,
{ "sponsorIdentity", "gprscdr.sponsorIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_gprscdr_applicationServiceProviderIdentity,
{ "applicationServiceProviderIdentity", "gprscdr.applicationServiceProviderIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_gprscdr_routingAreaCode,
{ "routingAreaCode", "gprscdr.routingAreaCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_cellId,
{ "cellId", "gprscdr.cellId",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_mCC_MNC,
{ "mCC-MNC", "gprscdr.mCC_MNC",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Id", HFILL }},
{ &hf_gprscdr_qCI,
{ "qCI", "gprscdr.qCI",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_maxRequestedBandwithUL,
{ "maxRequestedBandwithUL", "gprscdr.maxRequestedBandwithUL",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_maxRequestedBandwithDL,
{ "maxRequestedBandwithDL", "gprscdr.maxRequestedBandwithDL",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_guaranteedBitrateUL,
{ "guaranteedBitrateUL", "gprscdr.guaranteedBitrateUL",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_guaranteedBitrateDL,
{ "guaranteedBitrateDL", "gprscdr.guaranteedBitrateDL",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_aRP,
{ "aRP", "gprscdr.aRP",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_aPNAggregateMaxBitrateUL,
{ "aPNAggregateMaxBitrateUL", "gprscdr.aPNAggregateMaxBitrateUL",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_aPNAggregateMaxBitrateDL,
{ "aPNAggregateMaxBitrateDL", "gprscdr.aPNAggregateMaxBitrateDL",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_numberOfEvents,
{ "numberOfEvents", "gprscdr.numberOfEvents",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_eventTimeStamps,
{ "eventTimeStamps", "gprscdr.eventTimeStamps",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TimeStamp", HFILL }},
{ &hf_gprscdr_eventTimeStamps_item,
{ "TimeStamp", "gprscdr.TimeStamp",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_mediaComponentNumber,
{ "mediaComponentNumber", "gprscdr.mediaComponentNumber",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_flowNumber,
{ "flowNumber", "gprscdr.flowNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_flowNumber_item,
{ "flowNumber item", "gprscdr.flowNumber_item",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_iPAddress,
{ "iPAddress", "gprscdr.iPAddress",
FT_UINT32, BASE_DEC, VALS(gprscdr_IPAddress_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_pSFreeFormatData,
{ "pSFreeFormatData", "gprscdr.pSFreeFormatData",
FT_BYTES, BASE_NONE, NULL, 0,
"FreeFormatData", HFILL }},
{ &hf_gprscdr_pSFFDAppendIndicator,
{ "pSFFDAppendIndicator", "gprscdr.pSFFDAppendIndicator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"FFDAppendIndicator", HFILL }},
{ &hf_gprscdr_timeQuotaType,
{ "timeQuotaType", "gprscdr.timeQuotaType",
FT_UINT32, BASE_DEC, VALS(gprscdr_TimeQuotaType_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_baseTimeInterval,
{ "baseTimeInterval", "gprscdr.baseTimeInterval",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gprscdr_sSID,
{ "sSID", "gprscdr.sSID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_gprscdr_bSSID,
{ "bSSID", "gprscdr.bSSID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_gprscdr_cSGId,
{ "cSGId", "gprscdr.cSGId",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_cSGAccessMode,
{ "cSGAccessMode", "gprscdr.cSGAccessMode",
FT_UINT32, BASE_DEC, VALS(gprscdr_CSGAccessMode_vals), 0,
NULL, HFILL }},
{ &hf_gprscdr_cSGMembershipIndication,
{ "cSGMembershipIndication", "gprscdr.cSGMembershipIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gprscdr_LevelOfCAMELService_basic,
{ "basic", "gprscdr.basic",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gprscdr_LevelOfCAMELService_callDurationSupervision,
{ "callDurationSupervision", "gprscdr.callDurationSupervision",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gprscdr_LevelOfCAMELService_onlineCharging,
{ "onlineCharging", "gprscdr.onlineCharging",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_qoSChange,
{ "qoSChange", "gprscdr.qoSChange",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_sGSNChange,
{ "sGSNChange", "gprscdr.sGSNChange",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_sGSNPLMNIDChange,
{ "sGSNPLMNIDChange", "gprscdr.sGSNPLMNIDChange",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_tariffTimeSwitch,
{ "tariffTimeSwitch", "gprscdr.tariffTimeSwitch",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_pDPContextRelease,
{ "pDPContextRelease", "gprscdr.pDPContextRelease",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_rATChange,
{ "rATChange", "gprscdr.rATChange",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_serviceIdledOut,
{ "serviceIdledOut", "gprscdr.serviceIdledOut",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_qCTExpiry,
{ "qCTExpiry", "gprscdr.qCTExpiry",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_configurationChange,
{ "configurationChange", "gprscdr.configurationChange",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_serviceStop,
{ "serviceStop", "gprscdr.serviceStop",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_timeThresholdReached,
{ "timeThresholdReached", "gprscdr.timeThresholdReached",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_volumeThresholdReached,
{ "volumeThresholdReached", "gprscdr.volumeThresholdReached",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_timeExhausted,
{ "timeExhausted", "gprscdr.timeExhausted",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_volumeExhausted,
{ "volumeExhausted", "gprscdr.volumeExhausted",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_timeout,
{ "timeout", "gprscdr.timeout",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_returnRequested,
{ "returnRequested", "gprscdr.returnRequested",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_reauthorisationRequest,
{ "reauthorisationRequest", "gprscdr.reauthorisationRequest",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_continueOngoingSession,
{ "continueOngoingSession", "gprscdr.continueOngoingSession",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_retryAndTerminateOngoingSession,
{ "retryAndTerminateOngoingSession", "gprscdr.retryAndTerminateOngoingSession",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChangeV651_terminateOngoingSession,
{ "terminateOngoingSession", "gprscdr.terminateOngoingSession",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_qoSChange,
{ "qoSChange", "gprscdr.qoSChange",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_sGSNChange,
{ "sGSNChange", "gprscdr.sGSNChange",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_sGSNPLMNIDChange,
{ "sGSNPLMNIDChange", "gprscdr.sGSNPLMNIDChange",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_tariffTimeSwitch,
{ "tariffTimeSwitch", "gprscdr.tariffTimeSwitch",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_pDPContextRelease,
{ "pDPContextRelease", "gprscdr.pDPContextRelease",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_rATChange,
{ "rATChange", "gprscdr.rATChange",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_serviceIdledOut,
{ "serviceIdledOut", "gprscdr.serviceIdledOut",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_reserved,
{ "reserved", "gprscdr.reserved",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_configurationChange,
{ "configurationChange", "gprscdr.configurationChange",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_serviceStop,
{ "serviceStop", "gprscdr.serviceStop",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCATimeThresholdReached,
{ "dCCATimeThresholdReached", "gprscdr.dCCATimeThresholdReached",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCAVolumeThresholdReached,
{ "dCCAVolumeThresholdReached", "gprscdr.dCCAVolumeThresholdReached",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCAServiceSpecificUnitThresholdReached,
{ "dCCAServiceSpecificUnitThresholdReached", "gprscdr.dCCAServiceSpecificUnitThresholdReached",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCATimeExhausted,
{ "dCCATimeExhausted", "gprscdr.dCCATimeExhausted",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCAVolumeExhausted,
{ "dCCAVolumeExhausted", "gprscdr.dCCAVolumeExhausted",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCAValidityTimeout,
{ "dCCAValidityTimeout", "gprscdr.dCCAValidityTimeout",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_reserved1,
{ "reserved1", "gprscdr.reserved1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCAReauthorisationRequest,
{ "dCCAReauthorisationRequest", "gprscdr.dCCAReauthorisationRequest",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCAContinueOngoingSession,
{ "dCCAContinueOngoingSession", "gprscdr.dCCAContinueOngoingSession",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCARetryAndTerminateOngoingSession,
{ "dCCARetryAndTerminateOngoingSession", "gprscdr.dCCARetryAndTerminateOngoingSession",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCATerminateOngoingSession,
{ "dCCATerminateOngoingSession", "gprscdr.dCCATerminateOngoingSession",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_cGI_SAIChange,
{ "cGI-SAIChange", "gprscdr.cGI-SAIChange",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_rAIChange,
{ "rAIChange", "gprscdr.rAIChange",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_dCCAServiceSpecificUnitExhausted,
{ "dCCAServiceSpecificUnitExhausted", "gprscdr.dCCAServiceSpecificUnitExhausted",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_recordClosure,
{ "recordClosure", "gprscdr.recordClosure",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_timeLimit,
{ "timeLimit", "gprscdr.timeLimit",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_volumeLimit,
{ "volumeLimit", "gprscdr.volumeLimit",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_serviceSpecificUnitLimit,
{ "serviceSpecificUnitLimit", "gprscdr.serviceSpecificUnitLimit",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_envelopeClosure,
{ "envelopeClosure", "gprscdr.envelopeClosure",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_eCGIChange,
{ "eCGIChange", "gprscdr.eCGIChange",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_tAIChange,
{ "tAIChange", "gprscdr.tAIChange",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gprscdr_ServiceConditionChange_userLocationChange,
{ "userLocationChange", "gprscdr.userLocationChange",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
#line 70 "../../asn1/gprscdr/packet-gprscdr-template.c"
};
static gint *ett[] = {
&ett_gprscdr,
&ett_gprscdr_timestamp,
&ett_gprscdr_plmn_id,
#line 1 "../../asn1/gprscdr/packet-gprscdr-ettarr.c"
&ett_gprscdr_Diagnostics,
&ett_gprscdr_IPAddress,
&ett_gprscdr_IPBinaryAddress,
&ett_gprscdr_IPBinV6AddressWithOrWithoutPrefixLength,
&ett_gprscdr_IPBinV6AddressWithPrefixLength,
&ett_gprscdr_IPTextRepresentedAddress,
&ett_gprscdr_LevelOfCAMELService,
&ett_gprscdr_ManagementExtensions,
&ett_gprscdr_MBMSInformation,
&ett_gprscdr_ServiceSpecificInfo,
&ett_gprscdr_SubscriptionID,
&ett_gprscdr_ManagementExtension,
&ett_gprscdr_GPRSCallEventRecord,
&ett_gprscdr_GGSNPDPRecord,
&ett_gprscdr_SEQUENCE_OF_GSNAddress,
&ett_gprscdr_SEQUENCE_OF_ChangeOfCharConditionV651,
&ett_gprscdr_EGSNPDPRecord,
&ett_gprscdr_SEQUENCE_OF_ChangeOfServiceConditionV651,
&ett_gprscdr_SGSNPDPRecordV651,
&ett_gprscdr_SGSNSMORecordV651,
&ett_gprscdr_SGSNSMTRecordV651,
&ett_gprscdr_ChangeOfCharConditionV651,
&ett_gprscdr_ChangeOfServiceConditionV651,
&ett_gprscdr_ServiceConditionChangeV651,
&ett_gprscdr_GPRSRecord,
&ett_gprscdr_SGWRecord,
&ett_gprscdr_SEQUENCE_OF_ChangeOfCharCondition,
&ett_gprscdr_SEQUENCE_OF_ServingNodeType,
&ett_gprscdr_PGWRecord,
&ett_gprscdr_SEQUENCE_OF_ChangeOfServiceCondition,
&ett_gprscdr_SGSNMMRecord,
&ett_gprscdr_SEQUENCE_OF_ChangeLocation,
&ett_gprscdr_SGSNPDPRecord,
&ett_gprscdr_SGSNSMORecord,
&ett_gprscdr_SGSNSMTRecord,
&ett_gprscdr_AFRecordInformation,
&ett_gprscdr_CAMELInformationMM,
&ett_gprscdr_CAMELInformationPDP,
&ett_gprscdr_CAMELInformationSMS,
&ett_gprscdr_ChangeOfCharCondition,
&ett_gprscdr_ChangeOfServiceCondition,
&ett_gprscdr_SEQUENCE_OF_AFRecordInformation,
&ett_gprscdr_SEQUENCE_OF_ServiceSpecificInfo,
&ett_gprscdr_ChangeLocation,
&ett_gprscdr_EPCQoSInformation,
&ett_gprscdr_EventBasedChargingInformation,
&ett_gprscdr_SEQUENCE_OF_TimeStamp,
&ett_gprscdr_Flows,
&ett_gprscdr_T_flowNumber,
&ett_gprscdr_PDPAddress,
&ett_gprscdr_PSFurnishChargingInformation,
&ett_gprscdr_ServiceConditionChange,
&ett_gprscdr_TimeQuotaMechanism,
&ett_gprscdr_TWANUserLocationInfo,
&ett_gprscdr_UserCSGInformation,
#line 78 "../../asn1/gprscdr/packet-gprscdr-template.c"
};
proto_gprscdr = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_gprscdr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
