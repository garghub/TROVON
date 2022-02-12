static int
dissect_q932_NumberDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_q932_PublicTypeOfNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_q932_PublicPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PublicPartyNumber_sequence, hf_index, ett_q932_PublicPartyNumber);
return offset;
}
static int
dissect_q932_NsapEncodedNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_q932_PrivateTypeOfNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_q932_PrivatePartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PrivatePartyNumber_sequence, hf_index, ett_q932_PrivatePartyNumber);
return offset;
}
int
dissect_q932_PartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PartyNumber_choice, hf_index, ett_q932_PartyNumber,
NULL);
return offset;
}
int
dissect_q932_ScreeningIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_q932_SubaddressInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_q932_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_q932_UserSpecifiedSubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UserSpecifiedSubaddress_sequence, hf_index, ett_q932_UserSpecifiedSubaddress);
return offset;
}
static int
dissect_q932_NSAPSubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_q932_PartySubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PartySubaddress_choice, hf_index, ett_q932_PartySubaddress,
NULL);
return offset;
}
static int
dissect_q932_AddressScreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AddressScreened_sequence, hf_index, ett_q932_AddressScreened);
return offset;
}
static int
dissect_q932_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
int
dissect_q932_PresentedAddressScreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PresentedAddressScreened_choice, hf_index, ett_q932_PresentedAddressScreened,
NULL);
return offset;
}
int
dissect_q932_Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Address_sequence, hf_index, ett_q932_Address);
return offset;
}
int
dissect_q932_PresentedAddressUnscreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PresentedAddressUnscreened_choice, hf_index, ett_q932_PresentedAddressUnscreened,
NULL);
return offset;
}
static int
dissect_q932_NumberScreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NumberScreened_sequence, hf_index, ett_q932_NumberScreened);
return offset;
}
int
dissect_q932_PresentedNumberScreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PresentedNumberScreened_choice, hf_index, ett_q932_PresentedNumberScreened,
NULL);
return offset;
}
int
dissect_q932_PresentedNumberUnscreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PresentedNumberUnscreened_choice, hf_index, ett_q932_PresentedNumberUnscreened,
NULL);
return offset;
}
int
dissect_q932_PresentationAllowedIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_q932_EntityType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_q932_AddressInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_q932_PartyNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_q932_NetworkFacilityExtension_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NetworkFacilityExtension_U_sequence, hf_index, ett_q932_NetworkFacilityExtension_U);
return offset;
}
static int
dissect_q932_NetworkFacilityExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 10, TRUE, dissect_q932_NetworkFacilityExtension_U);
return offset;
}
static int
dissect_q932_NetworkProtocolProfile_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_q932_NetworkProtocolProfile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 18, TRUE, dissect_q932_NetworkProtocolProfile_U);
return offset;
}
static int
dissect_q932_InterpretationComponent_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_q932_InterpretationComponent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 11, TRUE, dissect_q932_InterpretationComponent_U);
return offset;
}
static int dissect_NetworkFacilityExtension_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_q932_NetworkFacilityExtension(FALSE, tvb, offset, &asn1_ctx, tree, hf_q932_NetworkFacilityExtension_PDU);
return offset;
}
static int dissect_NetworkProtocolProfile_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_q932_NetworkProtocolProfile(FALSE, tvb, offset, &asn1_ctx, tree, hf_q932_NetworkProtocolProfile_PDU);
return offset;
}
static int dissect_InterpretationComponent_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_q932_InterpretationComponent(FALSE, tvb, offset, &asn1_ctx, tree, hf_q932_InterpretationComponent_PDU);
return offset;
}
static void
dissect_q932_facility_ie(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, int length) {
gint8 appclass;
gboolean pc;
gint32 tag;
guint32 len;
int hoffset, eoffset;
int ie_end;
tvbuff_t *next_tvb;
ie_end = offset + length;
proto_tree_add_item(tree, hf_q932_pp, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while (offset < ie_end) {
hoffset = offset;
offset = get_ber_identifier(tvb, offset, &appclass, &pc, &tag);
offset = get_ber_length(tvb, offset, &len, NULL);
eoffset = offset + len;
next_tvb = tvb_new_subset_length(tvb, hoffset, eoffset - hoffset);
switch (appclass) {
case BER_CLASS_CON:
switch (tag) {
case 10 :
dissect_NetworkFacilityExtension_PDU(next_tvb, pinfo, tree, NULL);
break;
case 18 :
dissect_NetworkProtocolProfile_PDU(next_tvb, pinfo, tree, NULL);
break;
case 11 :
dissect_InterpretationComponent_PDU(next_tvb, pinfo, tree, NULL);
break;
case 1 :
case 2 :
case 3 :
case 4 :
q932_rose_ctx.apdu_depth = 1;
call_dissector_with_data(q932_ros_handle, next_tvb, pinfo, tree, &q932_rose_ctx);
break;
case 12 :
case 14 :
case 15 :
case 17 :
offset = dissect_ber_identifier(pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
proto_tree_add_expert(tree, pinfo, &ei_q932_dse_not_supported, tvb, offset, len);
break;
default:
offset = dissect_ber_identifier(pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
proto_tree_add_expert(tree, pinfo, &ei_q932_unknown_component, tvb, offset, len);
}
break;
case BER_CLASS_APP:
switch (tag) {
case 0 :
case 1 :
case 2 :
case 3 :
case 4 :
offset = dissect_ber_identifier(pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
proto_tree_add_expert(tree, pinfo, &ei_q932_acse_not_supported, tvb, offset, len);
break;
default:
offset = dissect_ber_identifier(pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
proto_tree_add_expert(tree, pinfo, &ei_q932_unknown_component, tvb, offset, len);
}
break;
default:
offset = dissect_ber_identifier(pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
proto_tree_add_expert(tree, pinfo, &ei_q932_unknown_component, tvb, offset, len);
}
offset = eoffset;
}
}
static void
dissect_q932_ni_ie(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, int length) {
int remain = length;
guint8 octet = 0;
guint32 value = 0;
proto_item* ti;
while ((remain > 0) && !(octet & 0x80)) {
octet = tvb_get_guint8(tvb, offset++);
remain--;
value <<= 7;
value |= octet & 0x7F;
}
ti = proto_tree_add_uint(tree, hf_q932_nd, tvb, offset - (length - remain), length - remain, value);
if (remain > 0) {
expert_add_info(pinfo, ti, &ei_q932_asn1_encoded);
}
}
static int
dissect_q932_ie(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
gint offset;
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_type, ie_len;
offset = 0;
ti = proto_tree_add_item(tree, proto_q932, tvb, offset, -1, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
ie_type = tvb_get_guint8(tvb, offset);
ie_len = tvb_get_guint8(tvb, offset + 1);
ie_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_q932_ie, NULL,
val_to_str(ie_type, VALS(q932_str_ie_type), "unknown (0x%02X)"));
proto_tree_add_item(ie_tree, hf_q932_ie_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_q932_ie_len, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
offset += 2;
if (tvb_reported_length_remaining(tvb, offset) <= 0)
return offset;
switch (ie_type) {
case Q932_IE_FACILITY :
dissect_q932_facility_ie(tvb, offset, pinfo, ie_tree, ie_len);
break;
case Q932_IE_NOTIFICATION_INDICATOR :
dissect_q932_ni_ie(tvb, offset, pinfo, ie_tree, ie_len);
break;
default:
if (ie_len > 0) {
proto_tree_add_item(ie_tree, hf_q932_ie_data, tvb, offset, ie_len, ENC_NA);
}
}
return tvb_captured_length(tvb);
}
static int
dissect_q932_apdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
return call_dissector(q932_ros_handle, tvb, pinfo, tree);
}
void proto_register_q932(void) {
static hf_register_info hf[] = {
{ &hf_q932_ie_type, { "Type", "q932.ie.type",
FT_UINT8, BASE_HEX, VALS(q932_str_ie_type), 0x0,
"Information Element Type", HFILL }},
{ &hf_q932_ie_len, { "Length", "q932.ie.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Information Element Length", HFILL }},
{ &hf_q932_ie_data, { "Data", "q932.ie.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q932_pp, { "Protocol profile", "q932.pp",
FT_UINT8, BASE_HEX, VALS(str_pp), 0x1F,
NULL, HFILL }},
{ &hf_q932_nd, { "Notification description", "q932.nd",
FT_UINT8, BASE_HEX, VALS(str_nd), 0x0,
NULL, HFILL }},
#line 1 "./asn1/q932/packet-q932-hfarr.c"
{ &hf_q932_NetworkFacilityExtension_PDU,
{ "NetworkFacilityExtension", "q932.NetworkFacilityExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_q932_NetworkProtocolProfile_PDU,
{ "NetworkProtocolProfile", "q932.NetworkProtocolProfile",
FT_UINT32, BASE_DEC, VALS(q932_NetworkProtocolProfile_U_vals), 0,
NULL, HFILL }},
{ &hf_q932_InterpretationComponent_PDU,
{ "InterpretationComponent", "q932.InterpretationComponent",
FT_UINT32, BASE_DEC, VALS(q932_InterpretationComponent_U_vals), 0,
NULL, HFILL }},
{ &hf_q932_presentationAlIowedAddress,
{ "presentationAlIowedAddress", "q932.presentationAlIowedAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddressScreened", HFILL }},
{ &hf_q932_presentationRestricted,
{ "presentationRestricted", "q932.presentationRestricted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_q932_numberNotAvailableDueTolnterworking,
{ "numberNotAvailableDueTolnterworking", "q932.numberNotAvailableDueTolnterworking_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_q932_presentationRestrictedAddressScreened,
{ "presentationRestrictedAddress", "q932.presentationRestrictedAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddressScreened", HFILL }},
{ &hf_q932_presentationAllowedAddress,
{ "presentationAllowedAddress", "q932.presentationAllowedAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"Address", HFILL }},
{ &hf_q932_presentationRestrictedAddress,
{ "presentationRestrictedAddress", "q932.presentationRestrictedAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"Address", HFILL }},
{ &hf_q932_presentationAllowedNumberScreened,
{ "presentationAllowedNumber", "q932.presentationAllowedNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
"NumberScreened", HFILL }},
{ &hf_q932_numberNotAvailableDueToInterworking,
{ "numberNotAvailableDueToInterworking", "q932.numberNotAvailableDueToInterworking_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_q932_presentationRestrictedNumberScreened,
{ "presentationRestrictedNumber", "q932.presentationRestrictedNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
"NumberScreened", HFILL }},
{ &hf_q932_presentationAllowedNumber,
{ "presentationAllowedNumber", "q932.presentationAllowedNumber",
FT_UINT32, BASE_DEC, VALS(q932_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_q932_presentationRestrictedNumber,
{ "presentationRestrictedNumber", "q932.presentationRestrictedNumber",
FT_UINT32, BASE_DEC, VALS(q932_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_q932_partyNumber,
{ "partyNumber", "q932.partyNumber",
FT_UINT32, BASE_DEC, VALS(q932_PartyNumber_vals), 0,
NULL, HFILL }},
{ &hf_q932_screeninglndicator,
{ "screeninglndicator", "q932.screeninglndicator",
FT_UINT32, BASE_DEC, VALS(q932_ScreeningIndicator_vals), 0,
"ScreeningIndicator", HFILL }},
{ &hf_q932_partySubaddress,
{ "partySubaddress", "q932.partySubaddress",
FT_UINT32, BASE_DEC, VALS(q932_PartySubaddress_vals), 0,
NULL, HFILL }},
{ &hf_q932_screeningIndicator,
{ "screeningIndicator", "q932.screeningIndicator",
FT_UINT32, BASE_DEC, VALS(q932_ScreeningIndicator_vals), 0,
NULL, HFILL }},
{ &hf_q932_unknownPartyNumber,
{ "unknownPartyNumber", "q932.unknownPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_q932_publicPartyNumber,
{ "publicPartyNumber", "q932.publicPartyNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_q932_nsapEncodedNumber,
{ "nsapEncodedNumber", "q932.nsapEncodedNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_q932_dataPartyNumber,
{ "dataPartyNumber", "q932.dataPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_q932_telexPartyNumber,
{ "telexPartyNumber", "q932.telexPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_q932_privatePartyNumber,
{ "privatePartyNumber", "q932.privatePartyNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_q932_nationalStandardPartyNumber,
{ "nationalStandardPartyNumber", "q932.nationalStandardPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_q932_publicTypeOfNumber,
{ "publicTypeOfNumber", "q932.publicTypeOfNumber",
FT_UINT32, BASE_DEC, VALS(q932_PublicTypeOfNumber_vals), 0,
NULL, HFILL }},
{ &hf_q932_publicNumberDigits,
{ "publicNumberDigits", "q932.publicNumberDigits",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_q932_privateTypeOfNumber,
{ "privateTypeOfNumber", "q932.privateTypeOfNumber",
FT_UINT32, BASE_DEC, VALS(q932_PrivateTypeOfNumber_vals), 0,
NULL, HFILL }},
{ &hf_q932_privateNumberDigits,
{ "privateNumberDigits", "q932.privateNumberDigits",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_q932_userSpecifiedSubaddress,
{ "userSpecifiedSubaddress", "q932.userSpecifiedSubaddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_q932_nSAPSubaddress,
{ "nSAPSubaddress", "q932.nSAPSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_q932_subaddressInformation,
{ "subaddressInformation", "q932.subaddressInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_q932_oddCountIndicator,
{ "oddCountIndicator", "q932.oddCountIndicator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_q932_sourceEntity,
{ "sourceEntity", "q932.sourceEntity",
FT_UINT32, BASE_DEC, VALS(q932_EntityType_vals), 0,
"EntityType", HFILL }},
{ &hf_q932_sourceEntityAddress,
{ "sourceEntityAddress", "q932.sourceEntityAddress",
FT_UINT32, BASE_DEC, VALS(q932_PartyNumber_vals), 0,
"AddressInformation", HFILL }},
{ &hf_q932_destinationEntity,
{ "destinationEntity", "q932.destinationEntity",
FT_UINT32, BASE_DEC, VALS(q932_EntityType_vals), 0,
"EntityType", HFILL }},
{ &hf_q932_destinationEntityAddress,
{ "destinationEntityAddress", "q932.destinationEntityAddress",
FT_UINT32, BASE_DEC, VALS(q932_PartyNumber_vals), 0,
"AddressInformation", HFILL }},
#line 313 "./asn1/q932/packet-q932-template.c"
};
static gint *ett[] = {
&ett_q932,
&ett_q932_ie,
#line 1 "./asn1/q932/packet-q932-ettarr.c"
&ett_q932_PresentedAddressScreened,
&ett_q932_PresentedAddressUnscreened,
&ett_q932_PresentedNumberScreened,
&ett_q932_PresentedNumberUnscreened,
&ett_q932_AddressScreened,
&ett_q932_NumberScreened,
&ett_q932_Address,
&ett_q932_PartyNumber,
&ett_q932_PublicPartyNumber,
&ett_q932_PrivatePartyNumber,
&ett_q932_PartySubaddress,
&ett_q932_UserSpecifiedSubaddress,
&ett_q932_NetworkFacilityExtension_U,
#line 320 "./asn1/q932/packet-q932-template.c"
};
static ei_register_info ei[] = {
{ &ei_q932_dse_not_supported, { "q932.dse_not_supported", PI_UNDECODED, PI_WARN, "DSE APDU (not supported)", EXPFILL }},
{ &ei_q932_acse_not_supported, { "q932.acse_not_supported", PI_UNDECODED, PI_WARN, "ACSE APDU (not supported)", EXPFILL }},
{ &ei_q932_unknown_component, { "q932.unknown_component", PI_UNDECODED, PI_WARN, "Unknown Component", EXPFILL }},
{ &ei_q932_asn1_encoded, { "q932.asn1_encoded", PI_UNDECODED, PI_WARN, "ASN.1 Encoded Data Structure(NOT IMPLEMENTED)", EXPFILL }},
};
module_t *q932_module;
expert_module_t* expert_q932;
static const enum_val_t facility_encoding[] = {
{"Facility as QSIG", "Dissect facility as QSIG", FACILITY_QSIG},
{"Facility as ETSI", "Dissect facility as ETSI", FACILITY_ETSI},
{NULL, NULL, -1}
};
proto_q932 = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("q932.apdu", dissect_q932_apdu, proto_q932);
proto_register_field_array(proto_q932, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_q932 = expert_register_protocol(proto_q932);
expert_register_field_array(expert_q932, ei, array_length(ei));
rose_ctx_init(&q932_rose_ctx);
q932_rose_ctx.arg_global_dissector_table = register_dissector_table("q932.ros.global.arg", "Q.932 Operation Argument (global opcode)", proto_q932, FT_STRING, BASE_NONE);
q932_rose_ctx.res_global_dissector_table = register_dissector_table("q932.ros.global.res", "Q.932 Operation Result (global opcode)", proto_q932, FT_STRING, BASE_NONE);
q932_rose_ctx.err_global_dissector_table = register_dissector_table("q932.ros.global.err", "Q.932 Error (global opcode)", proto_q932, FT_STRING, BASE_NONE);
qsig_arg_local_dissector_table = register_dissector_table("q932.ros.local.arg", "Q.932 Operation Argument (local opcode)", proto_q932, FT_UINT32, BASE_HEX);
qsig_res_local_dissector_table = register_dissector_table("q932.ros.local.res", "Q.932 Operation Result (local opcode)", proto_q932, FT_UINT32, BASE_HEX);
qsig_err_local_dissector_table = register_dissector_table("q932.ros.local.err", "Q.932 Error (local opcode)", proto_q932, FT_UINT32, BASE_HEX);
etsi_arg_local_dissector_table = register_dissector_table("q932.ros.etsi.local.arg", "Q.932 ETSI Operation Argument (local opcode)", proto_q932, FT_UINT32, BASE_HEX);
etsi_res_local_dissector_table = register_dissector_table("q932.ros.etsi.local.res", "Q.932 ETSI Operation Result (local opcode)", proto_q932, FT_UINT32, BASE_HEX);
etsi_err_local_dissector_table = register_dissector_table("q932.ros.etsi.local.err", "Q.932 ETSI Error (local opcode)", proto_q932, FT_UINT32, BASE_HEX);
q932_module = prefs_register_protocol(proto_q932, proto_reg_handoff_q932);
prefs_register_enum_preference(q932_module, "facility_encoding",
"Type of Facility encoding",
"Type of Facility encoding",
&g_facility_encoding, facility_encoding, FALSE);
}
void proto_reg_handoff_q932(void) {
dissector_handle_t q932_ie_handle;
static gboolean q931_prefs_initialized = FALSE;
if (!q931_prefs_initialized) {
q932_ie_handle = create_dissector_handle(dissect_q932_ie, proto_q932);
dissector_add_uint("q931.ie", (0x00 << 8) | Q932_IE_FACILITY, q932_ie_handle);
dissector_add_uint("q931.ie", (0x00 << 8) | Q932_IE_NOTIFICATION_INDICATOR, q932_ie_handle);
q932_ros_handle = find_dissector_add_dependency("q932.ros", proto_q932);
}
if(g_facility_encoding == FACILITY_QSIG){
q932_rose_ctx.arg_local_dissector_table = qsig_arg_local_dissector_table;
q932_rose_ctx.res_local_dissector_table = qsig_res_local_dissector_table;
q932_rose_ctx.err_local_dissector_table = qsig_err_local_dissector_table;
}else{
q932_rose_ctx.arg_local_dissector_table = etsi_arg_local_dissector_table;
q932_rose_ctx.res_local_dissector_table = etsi_res_local_dissector_table;
q932_rose_ctx.err_local_dissector_table = etsi_err_local_dissector_table;
}
}
