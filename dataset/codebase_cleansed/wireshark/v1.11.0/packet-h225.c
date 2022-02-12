static int
dissect_h225_ProtocolIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h225_T_h245Ip(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 323 "../../asn1/h225/h225.cnf"
tvbuff_t *value_tvb;
ipv4_address = 0;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, &value_tvb);
if (value_tvb)
ipv4_address = tvb_get_ipv4(value_tvb, 0);
return offset;
}
static int
dissect_h225_T_h245IpPort(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ipv4_port, FALSE);
return offset;
}
static int
dissect_h225_T_h245IpAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_h245IpAddress, T_h245IpAddress_sequence);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_h225_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h225_T_h245Route(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_h245Route, T_h245Route_sequence_of);
return offset;
}
static int
dissect_h225_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h225_T_h245Routing(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_T_h245Routing, T_h245Routing_choice,
NULL);
return offset;
}
static int
dissect_h225_T_h245IpSourceRoute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_h245IpSourceRoute, T_h245IpSourceRoute_sequence);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_6(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
6, 6, FALSE, NULL);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_h225_T_h245IpxAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_h245IpxAddress, T_h245IpxAddress_sequence);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_h225_T_h245Ip6Address(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_h245Ip6Address, T_h245Ip6Address_sequence);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_1_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 20, FALSE, NULL);
return offset;
}
static int
dissect_h225_T_nsiOID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier_str(tvb, offset, actx, tree, hf_index, &nsiOID);
return offset;
}
static int
dissect_h225_T_t35CountryCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &t35CountryCode, FALSE);
return offset;
}
static int
dissect_h225_T_t35Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &t35Extension, FALSE);
return offset;
}
static int
dissect_h225_T_manufacturerCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &manufacturerCode, FALSE);
return offset;
}
static int
dissect_h225_H221NonStandard(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 611 "../../asn1/h225/h225.cnf"
t35CountryCode = 0;
t35Extension = 0;
manufacturerCode = 0;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_H221NonStandard, H221NonStandard_sequence);
#line 615 "../../asn1/h225/h225.cnf"
h221NonStandard = ((t35CountryCode * 256) + t35Extension) * 65536 + manufacturerCode;
proto_tree_add_uint(tree, hf_h221Manufacturer, tvb, (offset>>3)-4, 4, h221NonStandard);
return offset;
}
static int
dissect_h225_NonStandardIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 592 "../../asn1/h225/h225.cnf"
gint32 value;
nsiOID = "";
h221NonStandard = 0;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_NonStandardIdentifier, NonStandardIdentifier_choice,
&value);
switch (value) {
case 0 :
nsp_handle = dissector_get_string_handle(nsp_object_dissector_table, nsiOID);
break;
case 1 :
nsp_handle = dissector_get_uint_handle(nsp_h221_dissector_table, h221NonStandard);
break;
default :
nsp_handle = NULL;
}
return offset;
}
static int
dissect_h225_T_nsp_data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 626 "../../asn1/h225/h225.cnf"
tvbuff_t *next_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &next_tvb);
if (next_tvb && tvb_length(next_tvb)) {
call_dissector((nsp_handle)?nsp_handle:data_handle, next_tvb, actx->pinfo, tree);
}
return offset;
}
int
dissect_h225_NonStandardParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 624 "../../asn1/h225/h225.cnf"
nsp_handle = NULL;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_NonStandardParameter, NonStandardParameter_sequence);
return offset;
}
static int
dissect_h225_H245TransportAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 433 "../../asn1/h225/h225.cnf"
ipv4_address=0;
ipv4_port=0;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_H245TransportAddress, H245TransportAddress_choice,
NULL);
#line 439 "../../asn1/h225/h225.cnf"
h225_pi->is_h245 = TRUE;
h225_pi->h245_address = ipv4_address;
h225_pi->h245_port = ipv4_port;
if((!actx->pinfo->fd->flags.visited) && ipv4_address!=0 && ipv4_port!=0 && h245_handle){
address src_addr;
conversation_t *conv=NULL;
SET_ADDRESS(&src_addr, AT_IPv4, 4, &ipv4_address);
conv=find_conversation(actx->pinfo->fd->num, &src_addr, &src_addr, PT_TCP, ipv4_port, ipv4_port, NO_ADDR_B|NO_PORT_B);
if(!conv){
conv=conversation_new(actx->pinfo->fd->num, &src_addr, &src_addr, PT_TCP, ipv4_port, ipv4_port, NO_ADDR2|NO_PORT2);
conversation_set_dissector(conv, h245_handle);
}
}
return offset;
}
static int
dissect_h225_DialedDigits(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 305 "../../asn1/h225/h225.cnf"
tvbuff_t *value_tvb = NULL;
guint len = 0;
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 128, FALSE, "0123456789#*,", 13,
&value_tvb);
if (h225_pi && h225_pi->is_destinationInfo == TRUE) {
if (value_tvb) {
len = tvb_length(value_tvb);
if (len > sizeof h225_pi->dialedDigits - 1)
len = sizeof h225_pi->dialedDigits - 1;
tvb_memcpy(value_tvb, (guint8*)h225_pi->dialedDigits, 0, len);
}
h225_pi->dialedDigits[len] = '\0';
h225_pi->is_destinationInfo = FALSE;
}
return offset;
}
static int
dissect_h225_BMPString_SIZE_1_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
1, 256, FALSE);
return offset;
}
static int
dissect_h225_IA5String_SIZE_1_512(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
1, 512, FALSE);
return offset;
}
static int
dissect_h225_IpV4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_h225_T_ipAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_ipAddress, T_ipAddress_sequence);
return offset;
}
static int
dissect_h225_T_route(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_route, T_route_sequence_of);
return offset;
}
static int
dissect_h225_T_routing(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_T_routing, T_routing_choice,
NULL);
return offset;
}
static int
dissect_h225_T_ipSourceRoute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_ipSourceRoute, T_ipSourceRoute_sequence);
return offset;
}
static int
dissect_h225_T_ipxAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_ipxAddress, T_ipxAddress_sequence);
return offset;
}
static int
dissect_h225_T_ip6Address(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_ip6Address, T_ip6Address_sequence);
return offset;
}
int
dissect_h225_TransportAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_TransportAddress, TransportAddress_choice,
NULL);
return offset;
}
int
dissect_h225_PublicTypeOfNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_PublicTypeOfNumber, PublicTypeOfNumber_choice,
NULL);
return offset;
}
static int
dissect_h225_NumberDigits(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 128, FALSE, "0123456789#*,", 13,
NULL);
return offset;
}
static int
dissect_h225_PublicPartyNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_PublicPartyNumber, PublicPartyNumber_sequence);
return offset;
}
int
dissect_h225_PrivateTypeOfNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_PrivateTypeOfNumber, PrivateTypeOfNumber_choice,
NULL);
return offset;
}
static int
dissect_h225_PrivatePartyNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_PrivatePartyNumber, PrivatePartyNumber_sequence);
return offset;
}
int
dissect_h225_PartyNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_PartyNumber, PartyNumber_choice,
NULL);
return offset;
}
static int
dissect_h225_TBCD_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 719 "../../asn1/h225/h225.cnf"
int min_len, max_len;
gboolean has_extension;
get_size_constraint_from_stack(actx, "TBCD_STRING", &min_len, &max_len, &has_extension);
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
min_len, max_len, has_extension, "0123456789#*abc", 15,
NULL);
return offset;
}
static int
dissect_h225_TBCD_STRING_SIZE_3_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_size_constrained_type(tvb, offset, actx, tree, hf_index, dissect_h225_TBCD_STRING,
"TBCD_STRING", 3, 16, FALSE);
return offset;
}
static int
dissect_h225_TBCD_STRING_SIZE_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_size_constrained_type(tvb, offset, actx, tree, hf_index, dissect_h225_TBCD_STRING,
"TBCD_STRING", 16, 16, FALSE);
return offset;
}
static int
dissect_h225_TBCD_STRING_SIZE_1_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_size_constrained_type(tvb, offset, actx, tree, hf_index, dissect_h225_TBCD_STRING,
"TBCD_STRING", 1, 4, FALSE);
return offset;
}
static int
dissect_h225_T_system_id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_T_system_id, T_system_id_choice,
NULL);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_h225_ANSI_41_UIM(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_ANSI_41_UIM, ANSI_41_UIM_sequence);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_1_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 4, FALSE, NULL);
return offset;
}
static int
dissect_h225_TBCD_STRING_SIZE_15_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_size_constrained_type(tvb, offset, actx, tree, hf_index, dissect_h225_TBCD_STRING,
"TBCD_STRING", 15, 16, FALSE);
return offset;
}
static int
dissect_h225_GSM_UIM(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_GSM_UIM, GSM_UIM_sequence);
return offset;
}
static int
dissect_h225_MobileUIM(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_MobileUIM, MobileUIM_choice,
NULL);
return offset;
}
static int
dissect_h225_NatureOfAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_NatureOfAddress, NatureOfAddress_choice,
NULL);
return offset;
}
static int
dissect_h225_IsupDigits(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 128, FALSE, "0123456789ABCDE", 15,
NULL);
return offset;
}
static int
dissect_h225_IsupPublicPartyNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_IsupPublicPartyNumber, IsupPublicPartyNumber_sequence);
return offset;
}
static int
dissect_h225_IsupPrivatePartyNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_IsupPrivatePartyNumber, IsupPrivatePartyNumber_sequence);
return offset;
}
static int
dissect_h225_IsupNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_IsupNumber, IsupNumber_choice,
NULL);
return offset;
}
int
dissect_h225_AliasAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_AliasAddress, AliasAddress_choice,
NULL);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_AliasAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_AliasAddress, SEQUENCE_OF_AliasAddress_sequence_of);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_1_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 256, FALSE, NULL);
return offset;
}
static int
dissect_h225_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h225_VendorIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_VendorIdentifier, VendorIdentifier_sequence);
return offset;
}
static int
dissect_h225_GatekeeperInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_GatekeeperInfo, GatekeeperInfo_sequence);
return offset;
}
int
dissect_h225_BandWidth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h225_INTEGER_1_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_h225_DataRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_DataRate, DataRate_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_DataRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_DataRate, SEQUENCE_OF_DataRate_sequence_of);
return offset;
}
static int
dissect_h225_SupportedPrefix(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_SupportedPrefix, SupportedPrefix_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_SupportedPrefix(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_SupportedPrefix, SEQUENCE_OF_SupportedPrefix_sequence_of);
return offset;
}
static int
dissect_h225_H310Caps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_H310Caps, H310Caps_sequence);
return offset;
}
static int
dissect_h225_H320Caps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_H320Caps, H320Caps_sequence);
return offset;
}
static int
dissect_h225_H321Caps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_H321Caps, H321Caps_sequence);
return offset;
}
static int
dissect_h225_H322Caps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_H322Caps, H322Caps_sequence);
return offset;
}
static int
dissect_h225_H323Caps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_H323Caps, H323Caps_sequence);
return offset;
}
static int
dissect_h225_H324Caps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_H324Caps, H324Caps_sequence);
return offset;
}
static int
dissect_h225_VoiceCaps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_VoiceCaps, VoiceCaps_sequence);
return offset;
}
static int
dissect_h225_T120OnlyCaps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T120OnlyCaps, T120OnlyCaps_sequence);
return offset;
}
static int
dissect_h225_NonStandardProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_NonStandardProtocol, NonStandardProtocol_sequence);
return offset;
}
static int
dissect_h225_T38FaxAnnexbOnlyCaps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T38FaxAnnexbOnlyCaps, T38FaxAnnexbOnlyCaps_sequence);
return offset;
}
static int
dissect_h225_SIPCaps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_SIPCaps, SIPCaps_sequence);
return offset;
}
int
dissect_h225_SupportedProtocols(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_SupportedProtocols, SupportedProtocols_choice,
NULL);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_SupportedProtocols(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_SupportedProtocols, SEQUENCE_OF_SupportedProtocols_sequence_of);
return offset;
}
static int
dissect_h225_GatewayInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_GatewayInfo, GatewayInfo_sequence);
return offset;
}
static int
dissect_h225_McuInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_McuInfo, McuInfo_sequence);
return offset;
}
static int
dissect_h225_TerminalInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_TerminalInfo, TerminalInfo_sequence);
return offset;
}
static int
dissect_h225_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h225_BIT_STRING_SIZE_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL);
return offset;
}
static int
dissect_h225_T_tunnelledProtocolObjectID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier_str(tvb, offset, actx, tree, hf_index, &tpOID);
return offset;
}
static int
dissect_h225_IA5String_SIZE_1_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
1, 64, FALSE);
return offset;
}
static int
dissect_h225_TunnelledProtocolAlternateIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_TunnelledProtocolAlternateIdentifier, TunnelledProtocolAlternateIdentifier_sequence);
return offset;
}
static int
dissect_h225_TunnelledProtocol_id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_TunnelledProtocol_id, TunnelledProtocol_id_choice,
NULL);
return offset;
}
int
dissect_h225_TunnelledProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 569 "../../asn1/h225/h225.cnf"
tpOID = "";
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_TunnelledProtocol, TunnelledProtocol_sequence);
#line 571 "../../asn1/h225/h225.cnf"
tp_handle = dissector_get_string_handle(tp_dissector_table, tpOID);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_TunnelledProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_TunnelledProtocol, SEQUENCE_OF_TunnelledProtocol_sequence_of);
return offset;
}
int
dissect_h225_EndpointType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_EndpointType, EndpointType_sequence);
return offset;
}
int
dissect_h225_CallReferenceValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_CallReferenceValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_CallReferenceValue, SEQUENCE_OF_CallReferenceValue_sequence_of);
return offset;
}
int
dissect_h225_GloballyUniqueID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, (tvbuff_t **)actx->value_ptr);
return offset;
}
int
dissect_h225_ConferenceIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_h225_GloballyUniqueID(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h225_T_conferenceGoal(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_T_conferenceGoal, T_conferenceGoal_choice,
NULL);
return offset;
}
static int
dissect_h225_Q954Details(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_Q954Details, Q954Details_sequence);
return offset;
}
static int
dissect_h225_QseriesOptions(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_QseriesOptions, QseriesOptions_sequence);
return offset;
}
static int
dissect_h225_CallType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_CallType, CallType_choice,
NULL);
return offset;
}
static int
dissect_h225_T_guid(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 543 "../../asn1/h225/h225.cnf"
tvbuff_t *guid_tvb = NULL;
actx->value_ptr = &guid_tvb;
offset = dissect_h225_GloballyUniqueID(tvb, offset, actx, tree, hf_index);
if (guid_tvb)
tvb_get_ntohguid(guid_tvb, 0, call_id_guid = wmem_new(wmem_packet_scope(), e_guid_t));
actx->value_ptr = NULL;
return offset;
}
int
dissect_h225_CallIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CallIdentifier, CallIdentifier_sequence);
return offset;
}
static int
dissect_h225_SecurityServiceMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_SecurityServiceMode, SecurityServiceMode_choice,
NULL);
return offset;
}
static int
dissect_h225_SecurityCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_SecurityCapabilities, SecurityCapabilities_sequence);
return offset;
}
static int
dissect_h225_H245Security(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_H245Security, H245Security_choice,
NULL);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_H245Security(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_H245Security, SEQUENCE_OF_H245Security_sequence_of);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_ClearToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_ClearToken, SEQUENCE_OF_ClearToken_sequence_of);
return offset;
}
static int
dissect_h225_T_cryptoEPPwdHash(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_cryptoEPPwdHash, T_cryptoEPPwdHash_sequence);
return offset;
}
int
dissect_h225_GatekeeperIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
1, 128, FALSE);
return offset;
}
static int
dissect_h225_T_cryptoGKPwdHash(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_cryptoGKPwdHash, T_cryptoGKPwdHash_sequence);
return offset;
}
int
dissect_h225_CryptoH323Token(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_CryptoH323Token, CryptoH323Token_choice,
NULL);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_CryptoH323Token(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_CryptoH323Token, SEQUENCE_OF_CryptoH323Token_sequence_of);
return offset;
}
static int
dissect_h225_FastStart_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 269 "../../asn1/h225/h225.cnf"
tvbuff_t *value_tvb = NULL;
char codec_str[50];
codec_str[0] = '\0';
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &value_tvb);
if (value_tvb && tvb_length(value_tvb)) {
dissect_h245_FastStart_OLC(value_tvb, actx->pinfo, tree, codec_str);
}
g_snprintf(h225_pi->frame_label, 50, "%s %s", h225_pi->frame_label, codec_str);
contains_faststart = TRUE;
h225_pi->is_faststart = TRUE;
return offset;
}
static int
dissect_h225_FastStart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_FastStart, FastStart_sequence_of);
return offset;
}
static int
dissect_h225_EndpointIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
1, 128, FALSE);
return offset;
}
static int
dissect_h225_ScnConnectionType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_ScnConnectionType, ScnConnectionType_choice,
NULL);
return offset;
}
static int
dissect_h225_ScnConnectionAggregation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_ScnConnectionAggregation, ScnConnectionAggregation_choice,
NULL);
return offset;
}
static int
dissect_h225_T_connectionParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_connectionParameters, T_connectionParameters_sequence);
return offset;
}
static int
dissect_h225_IA5String_SIZE_1_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
1, 32, FALSE);
return offset;
}
static int
dissect_h225_Language(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_Language, Language_sequence_of);
return offset;
}
int
dissect_h225_PresentationIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_PresentationIndicator, PresentationIndicator_choice,
NULL);
return offset;
}
int
dissect_h225_ScreeningIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_h225_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h225_IA5String_SIZE_0_512(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
0, 512, FALSE);
return offset;
}
static int
dissect_h225_H248SignalsDescriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h225_BMPString_SIZE_1_512(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
1, 512, FALSE);
return offset;
}
static int
dissect_h225_T_billingMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_T_billingMode, T_billingMode_choice,
NULL);
return offset;
}
static int
dissect_h225_INTEGER_1_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h225_CallCreditServiceControl_callStartingPoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_CallCreditServiceControl_callStartingPoint, CallCreditServiceControl_callStartingPoint_choice,
NULL);
return offset;
}
static int
dissect_h225_CallCreditServiceControl(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CallCreditServiceControl, CallCreditServiceControl_sequence);
return offset;
}
static int
dissect_h225_ServiceControlDescriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_ServiceControlDescriptor, ServiceControlDescriptor_choice,
NULL);
return offset;
}
static int
dissect_h225_ServiceControlSession_reason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_ServiceControlSession_reason, ServiceControlSession_reason_choice,
NULL);
return offset;
}
int
dissect_h225_ServiceControlSession(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_ServiceControlSession, ServiceControlSession_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_ServiceControlSession(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_ServiceControlSession, SEQUENCE_OF_ServiceControlSession_sequence_of);
return offset;
}
static int
dissect_h225_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h225_IA5String_SIZE_1_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
1, 128, FALSE);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_3_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 4, FALSE, NULL);
return offset;
}
static int
dissect_h225_CarrierInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CarrierInfo, CarrierInfo_sequence);
return offset;
}
static int
dissect_h225_CallsAvailable(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CallsAvailable, CallsAvailable_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_CallsAvailable(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_CallsAvailable, SEQUENCE_OF_CallsAvailable_sequence_of);
return offset;
}
static int
dissect_h225_CallCapacityInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CallCapacityInfo, CallCapacityInfo_sequence);
return offset;
}
static int
dissect_h225_CallCapacity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CallCapacity, CallCapacity_sequence);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_2_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 4, FALSE, NULL);
return offset;
}
static int
dissect_h225_T_cic_2_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_cic_2_4, T_cic_2_4_sequence_of);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_2_5(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 5, FALSE, NULL);
return offset;
}
static int
dissect_h225_CicInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CicInfo, CicInfo_sequence);
return offset;
}
static int
dissect_h225_T_member(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_member, T_member_sequence_of);
return offset;
}
static int
dissect_h225_GroupID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_GroupID, GroupID_sequence);
return offset;
}
int
dissect_h225_CircuitIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CircuitIdentifier, CircuitIdentifier_sequence);
return offset;
}
static int
dissect_h225_T_standard(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 683 "../../asn1/h225/h225.cnf"
guint32 value_int = (guint32)-1;
gef_ctx_t *gefx;
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, &value_int, TRUE);
gefx = gef_ctx_get(actx->private_data);
if (gefx) gefx->id = wmem_strdup_printf(wmem_packet_scope(), "%u", value_int);
return offset;
}
static int
dissect_h225_T_oid(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 692 "../../asn1/h225/h225.cnf"
const gchar *oid_str = NULL;
gef_ctx_t *gefx;
offset = dissect_per_object_identifier_str(tvb, offset, actx, tree, hf_index, &oid_str);
gefx = gef_ctx_get(actx->private_data);
if (gefx) gefx->id = oid_str;
return offset;
}
int
dissect_h225_GenericIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 669 "../../asn1/h225/h225.cnf"
gef_ctx_t *gefx;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_GenericIdentifier, GenericIdentifier_choice,
NULL);
#line 671 "../../asn1/h225/h225.cnf"
gef_ctx_update_key(gef_ctx_get(actx->private_data));
gefx = gef_ctx_get(actx->private_data);
if (gefx) {
actx->pinfo->private_data = actx;
dissector_try_string(gef_name_dissector_table, gefx->key, tvb_new_subset(tvb, offset>>3, 0, 0), actx->pinfo, tree);
}
actx->private_data = gefx;
return offset;
}
static int
dissect_h225_T_raw(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 702 "../../asn1/h225/h225.cnf"
tvbuff_t *value_tvb;
gef_ctx_t *gefx;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &value_tvb);
gefx = gef_ctx_get(actx->private_data);
if (gefx) {
dissector_try_string(gef_content_dissector_table, gefx->key, value_tvb, actx->pinfo, tree);
}
return offset;
}
static int
dissect_h225_IA5String(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE);
return offset;
}
static int
dissect_h225_BMPString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE);
return offset;
}
static int
dissect_h225_SEQUENCE_SIZE_1_512_OF_EnumeratedParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_SIZE_1_512_OF_EnumeratedParameter, SEQUENCE_SIZE_1_512_OF_EnumeratedParameter_sequence_of,
1, 512, FALSE);
return offset;
}
static int
dissect_h225_SEQUENCE_SIZE_1_16_OF_GenericData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_SIZE_1_16_OF_GenericData, SEQUENCE_SIZE_1_16_OF_GenericData_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_h225_Content(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_Content, Content_choice,
NULL);
return offset;
}
static int
dissect_h225_EnumeratedParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_EnumeratedParameter, EnumeratedParameter_sequence);
return offset;
}
static int
dissect_h225_T_parameters_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 651 "../../asn1/h225/h225.cnf"
gef_ctx_t *parent_gefx;
parent_gefx = gef_ctx_get(actx->private_data);
actx->private_data = gef_ctx_alloc(parent_gefx, NULL);
offset = dissect_h225_EnumeratedParameter(tvb, offset, actx, tree, hf_index);
#line 656 "../../asn1/h225/h225.cnf"
actx->private_data = parent_gefx;
return offset;
}
static int
dissect_h225_T_parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_parameters, T_parameters_sequence_of,
1, 512, FALSE);
return offset;
}
int
dissect_h225_GenericData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 637 "../../asn1/h225/h225.cnf"
void *priv_data = actx->private_data;
gef_ctx_t *gefx;
gefx = gef_ctx_get(actx->private_data);
if (!gefx) {
gefx = gef_ctx_alloc(NULL, "GenericData");
actx->private_data = gefx;
}
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_GenericData, GenericData_sequence);
#line 647 "../../asn1/h225/h225.cnf"
actx->private_data = priv_data;
return offset;
}
static int
dissect_h225_SEQUENCE_OF_GenericData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_GenericData, SEQUENCE_OF_GenericData_sequence_of);
return offset;
}
int
dissect_h225_CircuitInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CircuitInfo, CircuitInfo_sequence);
return offset;
}
static int
dissect_h225_FeatureDescriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 661 "../../asn1/h225/h225.cnf"
void *priv_data = actx->private_data;
actx->private_data = gef_ctx_alloc(NULL, "FeatureDescriptor");
offset = dissect_h225_GenericData(tvb, offset, actx, tree, hf_index);
#line 664 "../../asn1/h225/h225.cnf"
actx->private_data = priv_data;
return offset;
}
static int
dissect_h225_SEQUENCE_OF_FeatureDescriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_FeatureDescriptor, SEQUENCE_OF_FeatureDescriptor_sequence_of);
return offset;
}
static int
dissect_h225_ParallelH245Control_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 334 "../../asn1/h225/h225.cnf"
tvbuff_t *h245_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &h245_tvb);
next_tvb_add_handle(&h245_list, h245_tvb, (h225_h245_in_tree)?tree:NULL, h245dg_handle);
return offset;
}
static int
dissect_h225_ParallelH245Control(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_ParallelH245Control, ParallelH245Control_sequence_of);
return offset;
}
static int
dissect_h225_ExtendedAliasAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_ExtendedAliasAddress, ExtendedAliasAddress_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_ExtendedAliasAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_ExtendedAliasAddress, SEQUENCE_OF_ExtendedAliasAddress_sequence_of);
return offset;
}
static int
dissect_h225_INTEGER_1_31(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_h225_BMPString_SIZE_1_80(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
1, 80, FALSE);
return offset;
}
static int
dissect_h225_DisplayName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_DisplayName, DisplayName_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_DisplayName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_DisplayName, SEQUENCE_OF_DisplayName_sequence_of);
return offset;
}
static int
dissect_h225_Setup_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 387 "../../asn1/h225/h225.cnf"
contains_faststart = FALSE;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_Setup_UUIE, Setup_UUIE_sequence);
#line 391 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_SETUP;
if (contains_faststart == TRUE )
g_snprintf(h225_pi->frame_label, 50, "%s OLC (%s)", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"), h225_pi->frame_label);
else
g_snprintf(h225_pi->frame_label, 50, "%s", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"));
return offset;
}
int
dissect_h225_FeatureSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_FeatureSet, FeatureSet_sequence);
return offset;
}
static int
dissect_h225_CallProceeding_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CallProceeding_UUIE, CallProceeding_UUIE_sequence);
#line 400 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_CALL_PROCEDING;
if (contains_faststart == TRUE )
g_snprintf(h225_pi->frame_label, 50, "%s OLC (%s)", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"), h225_pi->frame_label);
else
g_snprintf(h225_pi->frame_label, 50, "%s", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"));
return offset;
}
static int
dissect_h225_Connect_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_Connect_UUIE, Connect_UUIE_sequence);
#line 424 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_CONNECT;
if (contains_faststart == TRUE )
g_snprintf(h225_pi->frame_label, 50, "%s OLC (%s)", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"), h225_pi->frame_label);
else
g_snprintf(h225_pi->frame_label, 50, "%s", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"));
return offset;
}
static int
dissect_h225_Alerting_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_Alerting_UUIE, Alerting_UUIE_sequence);
#line 409 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_ALERTING;
if (contains_faststart == TRUE )
g_snprintf(h225_pi->frame_label, 50, "%s OLC (%s)", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"), h225_pi->frame_label);
else
g_snprintf(h225_pi->frame_label, 50, "%s", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"));
return offset;
}
static int
dissect_h225_Information_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_Information_UUIE, Information_UUIE_sequence);
#line 358 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_INFORMATION;
g_snprintf(h225_pi->frame_label, 50, "%s", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"));
return offset;
}
static int
dissect_h225_SecurityErrors(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_SecurityErrors, SecurityErrors_choice,
NULL);
return offset;
}
int
dissect_h225_ReleaseCompleteReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 536 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_ReleaseCompleteReason, ReleaseCompleteReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_ReleaseComplete_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_ReleaseComplete_UUIE, ReleaseComplete_UUIE_sequence);
#line 418 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_RELEASE_COMPLET;
g_snprintf(h225_pi->frame_label, 50, "%s", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"));
return offset;
}
static int
dissect_h225_FacilityReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 460 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_FacilityReason, FacilityReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_ConferenceList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_ConferenceList, ConferenceList_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_ConferenceList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_ConferenceList, SEQUENCE_OF_ConferenceList_sequence_of);
return offset;
}
static int
dissect_h225_Facility_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_Facility_UUIE, Facility_UUIE_sequence);
#line 379 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_FACILITY;
g_snprintf(h225_pi->frame_label, 50, "%s", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"));
return offset;
}
static int
dissect_h225_Progress_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_Progress_UUIE, Progress_UUIE_sequence);
#line 364 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_PROGRESS;
if (contains_faststart == TRUE )
g_snprintf(h225_pi->frame_label, 50, "%s OLC (%s)", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"), h225_pi->frame_label);
else
g_snprintf(h225_pi->frame_label, 50, "%s", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"));
return offset;
}
static int
dissect_h225_T_empty_flg(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
#line 348 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_EMPTY;
return offset;
}
static int
dissect_h225_Status_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_Status_UUIE, Status_UUIE_sequence);
#line 352 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_STATUS;
g_snprintf(h225_pi->frame_label, 50, "%s", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"));
return offset;
}
static int
dissect_h225_StatusInquiry_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_StatusInquiry_UUIE, StatusInquiry_UUIE_sequence);
return offset;
}
static int
dissect_h225_SetupAcknowledge_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_SetupAcknowledge_UUIE, SetupAcknowledge_UUIE_sequence);
#line 373 "../../asn1/h225/h225.cnf"
h225_pi->cs_type = H225_SETUP_ACK;
g_snprintf(h225_pi->frame_label, 50, "%s", val_to_str(h225_pi->cs_type, T_h323_message_body_vals, "<unknown>"));
return offset;
}
static int
dissect_h225_Notify_UUIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_Notify_UUIE, Notify_UUIE_sequence);
return offset;
}
static int
dissect_h225_T_h323_message_body(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 242 "../../asn1/h225/h225.cnf"
gint32 message_body_val;
contains_faststart = FALSE;
call_id_guid = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_T_h323_message_body, T_h323_message_body_choice,
&message_body_val);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "CS: %s ",
val_to_str(message_body_val, T_h323_message_body_vals, "<unknown>"));
if (h225_pi->msg_type == H225_CS) {
h225_pi->msg_tag = message_body_val;
}
if (call_id_guid) {
h225_pi->guid = *call_id_guid;
}
if (contains_faststart == TRUE )
{
col_append_str(actx->pinfo->cinfo, COL_INFO, "OpenLogicalChannel " );
}
col_set_fence(actx->pinfo->cinfo,COL_INFO);
return offset;
}
static int
dissect_h225_T_h4501SupplementaryService_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 557 "../../asn1/h225/h225.cnf"
tvbuff_t *h4501_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &h4501_tvb);
if (h4501_tvb && tvb_length(h4501_tvb)) {
call_dissector(h4501_handle, h4501_tvb, actx->pinfo, tree);
}
return offset;
}
static int
dissect_h225_T_h4501SupplementaryService(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_h4501SupplementaryService, T_h4501SupplementaryService_sequence_of);
return offset;
}
static int
dissect_h225_T_h245Tunnelling(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, &(h225_pi->is_h245Tunneling));
return offset;
}
static int
dissect_h225_H245Control_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 341 "../../asn1/h225/h225.cnf"
tvbuff_t *h245_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &h245_tvb);
next_tvb_add_handle(&h245_list, h245_tvb, (h225_h245_in_tree)?tree:NULL, h245dg_handle);
return offset;
}
static int
dissect_h225_H245Control(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_H245Control, H245Control_sequence_of);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_NonStandardParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_NonStandardParameter, SEQUENCE_OF_NonStandardParameter_sequence_of);
return offset;
}
static int
dissect_h225_CallLinkage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CallLinkage, CallLinkage_sequence);
return offset;
}
static int
dissect_h225_T_messageContent_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 579 "../../asn1/h225/h225.cnf"
tvbuff_t *next_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &next_tvb);
next_tvb_add_handle(&tp_list, next_tvb, (h225_tp_in_tree)?tree:NULL, tp_handle);
return offset;
}
static int
dissect_h225_T_messageContent(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_messageContent, T_messageContent_sequence_of);
return offset;
}
static int
dissect_h225_T_tunnelledSignallingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 577 "../../asn1/h225/h225.cnf"
tp_handle = NULL;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_tunnelledSignallingMessage, T_tunnelledSignallingMessage_sequence);
return offset;
}
static int
dissect_h225_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h225_StimulusControl(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_StimulusControl, StimulusControl_sequence);
return offset;
}
static int
dissect_h225_H323_UU_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_H323_UU_PDU, H323_UU_PDU_sequence);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_1_131(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 131, FALSE, NULL);
return offset;
}
static int
dissect_h225_T_user_data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_user_data, T_user_data_sequence);
return offset;
}
static int
dissect_h225_H323_UserInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_H323_UserInformation, H323_UserInformation_sequence);
return offset;
}
static int
dissect_h225_T_range(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_range, T_range_sequence);
return offset;
}
static int
dissect_h225_AddressPattern(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_AddressPattern, AddressPattern_choice,
NULL);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_TransportAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_TransportAddress, SEQUENCE_OF_TransportAddress_sequence_of);
return offset;
}
static int
dissect_h225_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
int
dissect_h225_AlternateTransportAddresses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_AlternateTransportAddresses, AlternateTransportAddresses_sequence);
return offset;
}
static int
dissect_h225_Endpoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_Endpoint, Endpoint_sequence);
return offset;
}
static int
dissect_h225_UseSpecifiedTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_UseSpecifiedTransport, UseSpecifiedTransport_choice,
NULL);
return offset;
}
static int
dissect_h225_AlternateGK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_AlternateGK, AlternateGK_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_AlternateGK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_AlternateGK, SEQUENCE_OF_AlternateGK_sequence_of);
return offset;
}
static int
dissect_h225_AltGKInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_AltGKInfo, AltGKInfo_sequence);
return offset;
}
static int
dissect_h225_SecurityErrors2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_SecurityErrors2, SecurityErrors2_choice,
NULL);
return offset;
}
static int
dissect_h225_RequestSeqNum(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 65535U, &(h225_pi->requestSeqNum), FALSE);
return offset;
}
int
dissect_h225_TimeToLive(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h225_H248PackagesDescriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h225_EncryptIntAlg(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_EncryptIntAlg, EncryptIntAlg_choice,
NULL);
return offset;
}
static int
dissect_h225_NonIsoIntegrityMechanism(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_NonIsoIntegrityMechanism, NonIsoIntegrityMechanism_choice,
NULL);
return offset;
}
int
dissect_h225_IntegrityMechanism(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_IntegrityMechanism, IntegrityMechanism_choice,
NULL);
return offset;
}
static int
dissect_h225_BIT_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
int
dissect_h225_ICV(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_ICV, ICV_sequence);
return offset;
}
static int
dissect_h225_CapacityReportingCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CapacityReportingCapability, CapacityReportingCapability_sequence);
return offset;
}
static int
dissect_h225_CapacityReportingSpecification_when(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CapacityReportingSpecification_when, CapacityReportingSpecification_when_sequence);
return offset;
}
static int
dissect_h225_CapacityReportingSpecification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CapacityReportingSpecification, CapacityReportingSpecification_sequence);
return offset;
}
static int
dissect_h225_RasUsageInfoTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_RasUsageInfoTypes, RasUsageInfoTypes_sequence);
return offset;
}
static int
dissect_h225_RasUsageSpecification_when(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_RasUsageSpecification_when, RasUsageSpecification_when_sequence);
return offset;
}
static int
dissect_h225_RasUsageSpecificationcallStartingPoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_RasUsageSpecificationcallStartingPoint, RasUsageSpecificationcallStartingPoint_sequence);
return offset;
}
static int
dissect_h225_RasUsageSpecification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_RasUsageSpecification, RasUsageSpecification_sequence);
return offset;
}
static int
dissect_h225_RasUsageInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_RasUsageInformation, RasUsageInformation_sequence);
return offset;
}
static int
dissect_h225_OCTET_STRING_SIZE_2_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 32, FALSE, NULL);
return offset;
}
static int
dissect_h225_CallTerminationCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_CallTerminationCause, CallTerminationCause_choice,
NULL);
return offset;
}
int
dissect_h225_TransportChannelInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_TransportChannelInfo, TransportChannelInfo_sequence);
return offset;
}
static int
dissect_h225_BandwidthDetails(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_BandwidthDetails, BandwidthDetails_sequence);
return offset;
}
static int
dissect_h225_CallCreditCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_CallCreditCapability, CallCreditCapability_sequence);
return offset;
}
static int
dissect_h225_PrintableString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_PrintableString(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE);
return offset;
}
static int
dissect_h225_INTEGER_1_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h225_T_associatedSessionIds(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_associatedSessionIds, T_associatedSessionIds_sequence_of);
return offset;
}
static int
dissect_h225_RTPSession(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_RTPSession, RTPSession_sequence);
return offset;
}
static int
dissect_h225_RehomingModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_RehomingModel, RehomingModel_choice,
NULL);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_Endpoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_Endpoint, SEQUENCE_OF_Endpoint_sequence_of);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_AuthenticationMechanism(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_AuthenticationMechanism, SEQUENCE_OF_AuthenticationMechanism_sequence_of);
return offset;
}
static int
dissect_h225_T_algorithmOIDs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_algorithmOIDs, T_algorithmOIDs_sequence_of);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_IntegrityMechanism(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_IntegrityMechanism, SEQUENCE_OF_IntegrityMechanism_sequence_of);
return offset;
}
static int
dissect_h225_GatekeeperRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_GatekeeperRequest, GatekeeperRequest_sequence);
return offset;
}
static int
dissect_h225_GatekeeperConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_GatekeeperConfirm, GatekeeperConfirm_sequence);
return offset;
}
static int
dissect_h225_GatekeeperRejectReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 467 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_GatekeeperRejectReason, GatekeeperRejectReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_GatekeeperReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_GatekeeperReject, GatekeeperReject_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_AddressPattern(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_AddressPattern, SEQUENCE_OF_AddressPattern_sequence_of);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_H248PackagesDescriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_H248PackagesDescriptor, SEQUENCE_OF_H248PackagesDescriptor_sequence_of);
return offset;
}
static int
dissect_h225_SEQUENCE_SIZE_1_256_OF_QOSCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_SIZE_1_256_OF_QOSCapability, SEQUENCE_SIZE_1_256_OF_QOSCapability_sequence_of,
1, 256, FALSE);
return offset;
}
int
dissect_h225_TransportQOS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_TransportQOS, TransportQOS_choice,
NULL);
return offset;
}
static int
dissect_h225_RegistrationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_RegistrationRequest, RegistrationRequest_sequence);
return offset;
}
static int
dissect_h225_INTEGER_1_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h225_T_preGrantedARQ(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_preGrantedARQ, T_preGrantedARQ_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_RasUsageSpecification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_RasUsageSpecification, SEQUENCE_OF_RasUsageSpecification_sequence_of);
return offset;
}
static int
dissect_h225_RegistrationConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_RegistrationConfirm, RegistrationConfirm_sequence);
return offset;
}
static int
dissect_h225_T_invalidTerminalAliases(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_invalidTerminalAliases, T_invalidTerminalAliases_sequence);
return offset;
}
static int
dissect_h225_RegistrationRejectReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 522 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_RegistrationRejectReason, RegistrationRejectReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_RegistrationReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_RegistrationReject, RegistrationReject_sequence);
return offset;
}
static int
dissect_h225_UnregRequestReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 474 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_UnregRequestReason, UnregRequestReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_UnregistrationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_UnregistrationRequest, UnregistrationRequest_sequence);
return offset;
}
static int
dissect_h225_UnregistrationConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_UnregistrationConfirm, UnregistrationConfirm_sequence);
return offset;
}
static int
dissect_h225_UnregRejectReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 481 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_UnregRejectReason, UnregRejectReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_UnregistrationReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_UnregistrationReject, UnregistrationReject_sequence);
return offset;
}
static int
dissect_h225_CallModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_CallModel, CallModel_choice,
NULL);
return offset;
}
static int
dissect_h225_DestinationInfo_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 300 "../../asn1/h225/h225.cnf"
h225_pi->is_destinationInfo = TRUE;
offset = dissect_h225_AliasAddress(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h225_DestinationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_DestinationInfo, DestinationInfo_sequence_of);
return offset;
}
static int
dissect_h225_AdmissionRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_AdmissionRequest, AdmissionRequest_sequence);
return offset;
}
static int
dissect_h225_UUIEsRequested(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_UUIEsRequested, UUIEsRequested_sequence);
return offset;
}
static int
dissect_h225_AdmissionConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_AdmissionConfirm, AdmissionConfirm_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_PartyNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_PartyNumber, SEQUENCE_OF_PartyNumber_sequence_of);
return offset;
}
static int
dissect_h225_AdmissionRejectReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 508 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_AdmissionRejectReason, AdmissionRejectReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_AdmissionReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_AdmissionReject, AdmissionReject_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_BandwidthDetails(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_BandwidthDetails, SEQUENCE_OF_BandwidthDetails_sequence_of);
return offset;
}
static int
dissect_h225_BandwidthRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_BandwidthRequest, BandwidthRequest_sequence);
return offset;
}
static int
dissect_h225_BandwidthConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_BandwidthConfirm, BandwidthConfirm_sequence);
return offset;
}
static int
dissect_h225_BandRejectReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 488 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_BandRejectReason, BandRejectReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_BandwidthReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_BandwidthReject, BandwidthReject_sequence);
return offset;
}
static int
dissect_h225_DisengageReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 495 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_DisengageReason, DisengageReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_DisengageRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_DisengageRequest, DisengageRequest_sequence);
return offset;
}
static int
dissect_h225_DisengageConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_DisengageConfirm, DisengageConfirm_sequence);
return offset;
}
static int
dissect_h225_DisengageRejectReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 501 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_DisengageRejectReason, DisengageRejectReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_DisengageReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_DisengageReject, DisengageReject_sequence);
return offset;
}
static int
dissect_h225_LocationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_LocationRequest, LocationRequest_sequence);
return offset;
}
static int
dissect_h225_LocationConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_LocationConfirm, LocationConfirm_sequence);
return offset;
}
static int
dissect_h225_LocationRejectReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 515 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_LocationRejectReason, LocationRejectReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_LocationReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_LocationReject, LocationReject_sequence);
return offset;
}
static int
dissect_h225_InfoRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_InfoRequest, InfoRequest_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_RTPSession(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_RTPSession, SEQUENCE_OF_RTPSession_sequence_of);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_TransportChannelInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_TransportChannelInfo, SEQUENCE_OF_TransportChannelInfo_sequence_of);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_ConferenceIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_ConferenceIdentifier, SEQUENCE_OF_ConferenceIdentifier_sequence_of);
return offset;
}
static int
dissect_h225_T_pdu_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_pdu_item, T_pdu_item_sequence);
return offset;
}
static int
dissect_h225_T_pdu(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_pdu, T_pdu_sequence_of);
return offset;
}
static int
dissect_h225_T_perCallInfo_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_perCallInfo_item, T_perCallInfo_item_sequence);
return offset;
}
static int
dissect_h225_T_perCallInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_T_perCallInfo, T_perCallInfo_sequence_of);
return offset;
}
static int
dissect_h225_InfoRequestResponseStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_InfoRequestResponseStatus, InfoRequestResponseStatus_choice,
NULL);
return offset;
}
static int
dissect_h225_InfoRequestResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_InfoRequestResponse, InfoRequestResponse_sequence);
return offset;
}
static int
dissect_h225_NonStandardMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_NonStandardMessage, NonStandardMessage_sequence);
return offset;
}
static int
dissect_h225_UnknownMessageResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_UnknownMessageResponse, UnknownMessageResponse_sequence);
return offset;
}
static int
dissect_h225_RequestInProgress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_RequestInProgress, RequestInProgress_sequence);
return offset;
}
static int
dissect_h225_ResourcesAvailableIndicate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_ResourcesAvailableIndicate, ResourcesAvailableIndicate_sequence);
return offset;
}
static int
dissect_h225_ResourcesAvailableConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_ResourcesAvailableConfirm, ResourcesAvailableConfirm_sequence);
return offset;
}
static int
dissect_h225_InfoRequestAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_InfoRequestAck, InfoRequestAck_sequence);
return offset;
}
static int
dissect_h225_InfoRequestNakReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 529 "../../asn1/h225/h225.cnf"
gint32 value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_InfoRequestNakReason, InfoRequestNakReason_choice,
&value);
h225_pi->reason = value;
return offset;
}
static int
dissect_h225_InfoRequestNak(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_InfoRequestNak, InfoRequestNak_sequence);
return offset;
}
static int
dissect_h225_T_callSpecific(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_T_callSpecific, T_callSpecific_sequence);
return offset;
}
static int
dissect_h225_ServiceControlIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_ServiceControlIndication, ServiceControlIndication_sequence);
return offset;
}
static int
dissect_h225_T_result(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_T_result, T_result_choice,
NULL);
return offset;
}
static int
dissect_h225_ServiceControlResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h225_ServiceControlResponse, ServiceControlResponse_sequence);
return offset;
}
static int
dissect_h225_SEQUENCE_OF_AdmissionConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h225_SEQUENCE_OF_AdmissionConfirm, SEQUENCE_OF_AdmissionConfirm_sequence_of);
return offset;
}
int
dissect_h225_RasMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 286 "../../asn1/h225/h225.cnf"
gint32 rasmessage_value;
call_id_guid = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h225_RasMessage, RasMessage_choice,
&rasmessage_value);
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "RAS: %s ",
val_to_str(rasmessage_value, h225_RasMessage_vals, "<unknown>"));
h225_pi->msg_tag = rasmessage_value;
if (call_id_guid) {
h225_pi->guid = *call_id_guid;
}
return offset;
}
static int dissect_H323_UserInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h225_H323_UserInformation(tvb, offset, &asn1_ctx, tree, hf_h225_H323_UserInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_h225_ExtendedAliasAddress_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h225_ExtendedAliasAddress(tvb, offset, &asn1_ctx, tree, hf_h225_h225_ExtendedAliasAddress_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RasMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h225_RasMessage(tvb, offset, &asn1_ctx, tree, hf_h225_RasMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h225_H323UserInformation(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *it;
proto_tree *tr;
int offset = 0;
pi_current++;
if(pi_current==5){
pi_current=0;
}
h225_pi=&pi_arr[pi_current];
reset_h225_packet_info(h225_pi);
h225_pi->msg_type = H225_CS;
next_tvb_init(&h245_list);
next_tvb_init(&tp_list);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear(pinfo->cinfo, COL_INFO);
it=proto_tree_add_protocol_format(tree, proto_h225, tvb, 0, tvb_length(tvb), PSNAME" CS");
tr=proto_item_add_subtree(it, ett_h225);
offset = dissect_H323_UserInformation_PDU(tvb, pinfo, tr, NULL);
if (h245_list.count){
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/");
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
}
next_tvb_call(&h245_list, pinfo, tree, h245dg_handle, data_handle);
next_tvb_call(&tp_list, pinfo, tree, NULL, data_handle);
tap_queue_packet(h225_tap, pinfo, h225_pi);
return offset;
}
static int
dissect_h225_h225_RasMessage(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_){
proto_item *it;
proto_tree *tr;
guint32 offset=0;
pi_current++;
if(pi_current==5){
pi_current=0;
}
h225_pi=&pi_arr[pi_current];
reset_h225_packet_info(h225_pi);
h225_pi->msg_type = H225_RAS;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
it=proto_tree_add_protocol_format(tree, proto_h225, tvb, offset, tvb_length(tvb), PSNAME" RAS");
tr=proto_item_add_subtree(it, ett_h225);
offset = dissect_RasMessage_PDU(tvb, pinfo, tr, NULL);
ras_call_matching(tvb, pinfo, tr, h225_pi);
tap_queue_packet(h225_tap, pinfo, h225_pi);
return offset;
}
void proto_register_h225(void) {
static hf_register_info hf[] = {
{ &hf_h221Manufacturer,
{ "H.221 Manufacturer", "h221.Manufacturer", FT_UINT32, BASE_HEX,
VALS(H221ManufacturerCode_vals), 0, NULL, HFILL }},
{ &hf_h225_ras_req_frame,
{ "RAS Request Frame", "h225.ras.reqframe", FT_FRAMENUM, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_h225_ras_rsp_frame,
{ "RAS Response Frame", "h225.ras.rspframe", FT_FRAMENUM, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_h225_ras_dup,
{ "Duplicate RAS Message", "h225.ras.dup", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_h225_ras_deltatime,
{ "RAS Service Response Time", "h225.ras.timedelta", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Timedelta between RAS-Request and RAS-Response", HFILL }},
#line 1 "../../asn1/h225/packet-h225-hfarr.c"
{ &hf_h225_H323_UserInformation_PDU,
{ "H323-UserInformation", "h225.H323_UserInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h225_ExtendedAliasAddress_PDU,
{ "ExtendedAliasAddress", "h225.ExtendedAliasAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_RasMessage_PDU,
{ "RasMessage", "h225.RasMessage",
FT_UINT32, BASE_DEC, VALS(h225_RasMessage_vals), 0,
NULL, HFILL }},
{ &hf_h225_h323_uu_pdu,
{ "h323-uu-pdu", "h225.h323_uu_pdu_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_user_data,
{ "user-data", "h225.user_data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_protocol_discriminator,
{ "protocol-discriminator", "h225.protocol_discriminator",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &q931_protocol_discriminator_vals_ext, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h225_user_information,
{ "user-information", "h225.user_information",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_131", HFILL }},
{ &hf_h225_h323_message_body,
{ "h323-message-body", "h225.h323_message_body",
FT_UINT32, BASE_DEC, VALS(T_h323_message_body_vals), 0,
NULL, HFILL }},
{ &hf_h225_setup,
{ "setup", "h225.setup_element",
FT_NONE, BASE_NONE, NULL, 0,
"Setup_UUIE", HFILL }},
{ &hf_h225_callProceeding,
{ "callProceeding", "h225.callProceeding_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallProceeding_UUIE", HFILL }},
{ &hf_h225_connect,
{ "connect", "h225.connect_element",
FT_NONE, BASE_NONE, NULL, 0,
"Connect_UUIE", HFILL }},
{ &hf_h225_alerting,
{ "alerting", "h225.alerting_element",
FT_NONE, BASE_NONE, NULL, 0,
"Alerting_UUIE", HFILL }},
{ &hf_h225_information,
{ "information", "h225.information_element",
FT_NONE, BASE_NONE, NULL, 0,
"Information_UUIE", HFILL }},
{ &hf_h225_releaseComplete,
{ "releaseComplete", "h225.releaseComplete_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReleaseComplete_UUIE", HFILL }},
{ &hf_h225_facility,
{ "facility", "h225.facility_element",
FT_NONE, BASE_NONE, NULL, 0,
"Facility_UUIE", HFILL }},
{ &hf_h225_progress,
{ "progress", "h225.progress_element",
FT_NONE, BASE_NONE, NULL, 0,
"Progress_UUIE", HFILL }},
{ &hf_h225_empty_flg,
{ "empty", "h225.empty_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_empty_flg", HFILL }},
{ &hf_h225_status,
{ "status", "h225.status_element",
FT_NONE, BASE_NONE, NULL, 0,
"Status_UUIE", HFILL }},
{ &hf_h225_statusInquiry,
{ "statusInquiry", "h225.statusInquiry_element",
FT_NONE, BASE_NONE, NULL, 0,
"StatusInquiry_UUIE", HFILL }},
{ &hf_h225_setupAcknowledge,
{ "setupAcknowledge", "h225.setupAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
"SetupAcknowledge_UUIE", HFILL }},
{ &hf_h225_notify,
{ "notify", "h225.notify_element",
FT_NONE, BASE_NONE, NULL, 0,
"Notify_UUIE", HFILL }},
{ &hf_h225_nonStandardData,
{ "nonStandardData", "h225.nonStandardData_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h225_h4501SupplementaryService,
{ "h4501SupplementaryService", "h225.h4501SupplementaryService",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h4501SupplementaryService_item,
{ "h4501SupplementaryService item", "h225.h4501SupplementaryService_item",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h245Tunnelling,
{ "h245Tunnelling", "h225.h245Tunnelling",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_H245Control_item,
{ "H245Control item", "h225.H245Control_item",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h245Control,
{ "h245Control", "h225.h245Control",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nonStandardControl,
{ "nonStandardControl", "h225.nonStandardControl",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_NonStandardParameter", HFILL }},
{ &hf_h225_nonStandardControl_item,
{ "NonStandardParameter", "h225.NonStandardParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callLinkage,
{ "callLinkage", "h225.callLinkage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_tunnelledSignallingMessage,
{ "tunnelledSignallingMessage", "h225.tunnelledSignallingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_tunnelledProtocolID,
{ "tunnelledProtocolID", "h225.tunnelledProtocolID_element",
FT_NONE, BASE_NONE, NULL, 0,
"TunnelledProtocol", HFILL }},
{ &hf_h225_messageContent,
{ "messageContent", "h225.messageContent",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_messageContent_item,
{ "messageContent item", "h225.messageContent_item",
FT_UINT32, BASE_DEC, NULL, 0,
"T_messageContent_item", HFILL }},
{ &hf_h225_tunnellingRequired,
{ "tunnellingRequired", "h225.tunnellingRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_provisionalRespToH245Tunnelling,
{ "provisionalRespToH245Tunnelling", "h225.provisionalRespToH245Tunnelling_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_stimulusControl,
{ "stimulusControl", "h225.stimulusControl_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_genericData,
{ "genericData", "h225.genericData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_GenericData", HFILL }},
{ &hf_h225_genericData_item,
{ "GenericData", "h225.GenericData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nonStandard,
{ "nonStandard", "h225.nonStandard_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h225_isText,
{ "isText", "h225.isText_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h248Message,
{ "h248Message", "h225.h248Message",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h225_protocolIdentifier,
{ "protocolIdentifier", "h225.protocolIdentifier",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_uUIE_destinationInfo,
{ "destinationInfo", "h225.destinationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"EndpointType", HFILL }},
{ &hf_h225_h245Address,
{ "h245Address", "h225.h245Address",
FT_UINT32, BASE_DEC, VALS(h225_H245TransportAddress_vals), 0,
"H245TransportAddress", HFILL }},
{ &hf_h225_callIdentifier,
{ "callIdentifier", "h225.callIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h245SecurityMode,
{ "h245SecurityMode", "h225.h245SecurityMode",
FT_UINT32, BASE_DEC, VALS(h225_H245Security_vals), 0,
"H245Security", HFILL }},
{ &hf_h225_tokens,
{ "tokens", "h225.tokens",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ClearToken", HFILL }},
{ &hf_h225_tokens_item,
{ "ClearToken", "h225.ClearToken_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_cryptoTokens,
{ "cryptoTokens", "h225.cryptoTokens",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CryptoH323Token", HFILL }},
{ &hf_h225_cryptoTokens_item,
{ "CryptoH323Token", "h225.CryptoH323Token",
FT_UINT32, BASE_DEC, VALS(h225_CryptoH323Token_vals), 0,
NULL, HFILL }},
{ &hf_h225_fastStart,
{ "fastStart", "h225.fastStart",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_multipleCalls,
{ "multipleCalls", "h225.multipleCalls",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_maintainConnection,
{ "maintainConnection", "h225.maintainConnection",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_alertingAddress,
{ "alertingAddress", "h225.alertingAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_alertingAddress_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_presentationIndicator,
{ "presentationIndicator", "h225.presentationIndicator",
FT_UINT32, BASE_DEC, VALS(h225_PresentationIndicator_vals), 0,
NULL, HFILL }},
{ &hf_h225_screeningIndicator,
{ "screeningIndicator", "h225.screeningIndicator",
FT_UINT32, BASE_DEC, VALS(h225_ScreeningIndicator_vals), 0,
NULL, HFILL }},
{ &hf_h225_fastConnectRefused,
{ "fastConnectRefused", "h225.fastConnectRefused_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_serviceControl,
{ "serviceControl", "h225.serviceControl",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ServiceControlSession", HFILL }},
{ &hf_h225_serviceControl_item,
{ "ServiceControlSession", "h225.ServiceControlSession_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_capacity,
{ "capacity", "h225.capacity_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallCapacity", HFILL }},
{ &hf_h225_featureSet,
{ "featureSet", "h225.featureSet_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_displayName,
{ "displayName", "h225.displayName",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_DisplayName", HFILL }},
{ &hf_h225_displayName_item,
{ "DisplayName", "h225.DisplayName_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_conferenceID,
{ "conferenceID", "h225.conferenceID",
FT_GUID, BASE_NONE, NULL, 0,
"ConferenceIdentifier", HFILL }},
{ &hf_h225_language,
{ "language", "h225.language",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_connectedAddress,
{ "connectedAddress", "h225.connectedAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_connectedAddress_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_circuitInfo,
{ "circuitInfo", "h225.circuitInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_releaseCompleteReason,
{ "reason", "h225.reason",
FT_UINT32, BASE_DEC, VALS(h225_ReleaseCompleteReason_vals), 0,
"ReleaseCompleteReason", HFILL }},
{ &hf_h225_busyAddress,
{ "busyAddress", "h225.busyAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_busyAddress_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_destinationInfo,
{ "destinationInfo", "h225.destinationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"EndpointType", HFILL }},
{ &hf_h225_noBandwidth,
{ "noBandwidth", "h225.noBandwidth_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatekeeperResources,
{ "gatekeeperResources", "h225.gatekeeperResources_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_unreachableDestination,
{ "unreachableDestination", "h225.unreachableDestination_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_destinationRejection,
{ "destinationRejection", "h225.destinationRejection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_invalidRevision,
{ "invalidRevision", "h225.invalidRevision_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_noPermission,
{ "noPermission", "h225.noPermission_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_unreachableGatekeeper,
{ "unreachableGatekeeper", "h225.unreachableGatekeeper_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatewayResources,
{ "gatewayResources", "h225.gatewayResources_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_badFormatAddress,
{ "badFormatAddress", "h225.badFormatAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_adaptiveBusy,
{ "adaptiveBusy", "h225.adaptiveBusy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_inConf,
{ "inConf", "h225.inConf_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_undefinedReason,
{ "undefinedReason", "h225.undefinedReason_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_facilityCallDeflection,
{ "facilityCallDeflection", "h225.facilityCallDeflection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityDenied,
{ "securityDenied", "h225.securityDenied_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_calledPartyNotRegistered,
{ "calledPartyNotRegistered", "h225.calledPartyNotRegistered_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callerNotRegistered,
{ "callerNotRegistered", "h225.callerNotRegistered_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_newConnectionNeeded,
{ "newConnectionNeeded", "h225.newConnectionNeeded_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nonStandardReason,
{ "nonStandardReason", "h225.nonStandardReason_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h225_replaceWithConferenceInvite,
{ "replaceWithConferenceInvite", "h225.replaceWithConferenceInvite",
FT_GUID, BASE_NONE, NULL, 0,
"ConferenceIdentifier", HFILL }},
{ &hf_h225_genericDataReason,
{ "genericDataReason", "h225.genericDataReason_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_neededFeatureNotSupported,
{ "neededFeatureNotSupported", "h225.neededFeatureNotSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_tunnelledSignallingRejected,
{ "tunnelledSignallingRejected", "h225.tunnelledSignallingRejected_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_invalidCID,
{ "invalidCID", "h225.invalidCID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_rLC_securityError,
{ "securityError", "h225.securityError",
FT_UINT32, BASE_DEC, VALS(h225_SecurityErrors_vals), 0,
"SecurityErrors", HFILL }},
{ &hf_h225_hopCountExceeded,
{ "hopCountExceeded", "h225.hopCountExceeded_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_sourceAddress,
{ "sourceAddress", "h225.sourceAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_sourceAddress_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_setup_UUIE_sourceInfo,
{ "sourceInfo", "h225.sourceInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"EndpointType", HFILL }},
{ &hf_h225_destinationAddress,
{ "destinationAddress", "h225.destinationAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_destinationAddress_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_destCallSignalAddress,
{ "destCallSignalAddress", "h225.destCallSignalAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_destExtraCallInfo,
{ "destExtraCallInfo", "h225.destExtraCallInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_destExtraCallInfo_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_destExtraCRV,
{ "destExtraCRV", "h225.destExtraCRV",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallReferenceValue", HFILL }},
{ &hf_h225_destExtraCRV_item,
{ "CallReferenceValue", "h225.CallReferenceValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_activeMC,
{ "activeMC", "h225.activeMC",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_conferenceGoal,
{ "conferenceGoal", "h225.conferenceGoal",
FT_UINT32, BASE_DEC, VALS(h225_T_conferenceGoal_vals), 0,
NULL, HFILL }},
{ &hf_h225_create,
{ "create", "h225.create_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_join,
{ "join", "h225.join_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_invite,
{ "invite", "h225.invite_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_capability_negotiation,
{ "capability-negotiation", "h225.capability_negotiation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callIndependentSupplementaryService,
{ "callIndependentSupplementaryService", "h225.callIndependentSupplementaryService_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callServices,
{ "callServices", "h225.callServices_element",
FT_NONE, BASE_NONE, NULL, 0,
"QseriesOptions", HFILL }},
{ &hf_h225_callType,
{ "callType", "h225.callType",
FT_UINT32, BASE_DEC, VALS(h225_CallType_vals), 0,
NULL, HFILL }},
{ &hf_h225_sourceCallSignalAddress,
{ "sourceCallSignalAddress", "h225.sourceCallSignalAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_uUIE_remoteExtensionAddress,
{ "remoteExtensionAddress", "h225.remoteExtensionAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h225_h245SecurityCapability,
{ "h245SecurityCapability", "h225.h245SecurityCapability",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_H245Security", HFILL }},
{ &hf_h225_h245SecurityCapability_item,
{ "H245Security", "h225.H245Security",
FT_UINT32, BASE_DEC, VALS(h225_H245Security_vals), 0,
NULL, HFILL }},
{ &hf_h225_FastStart_item,
{ "FastStart item", "h225.FastStart_item",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_mediaWaitForConnect,
{ "mediaWaitForConnect", "h225.mediaWaitForConnect",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_canOverlapSend,
{ "canOverlapSend", "h225.canOverlapSend",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_endpointIdentifier,
{ "endpointIdentifier", "h225.endpointIdentifier",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_connectionParameters,
{ "connectionParameters", "h225.connectionParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_connectionType,
{ "connectionType", "h225.connectionType",
FT_UINT32, BASE_DEC, VALS(h225_ScnConnectionType_vals), 0,
"ScnConnectionType", HFILL }},
{ &hf_h225_numberOfScnConnections,
{ "numberOfScnConnections", "h225.numberOfScnConnections",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h225_connectionAggregation,
{ "connectionAggregation", "h225.connectionAggregation",
FT_UINT32, BASE_DEC, VALS(h225_ScnConnectionAggregation_vals), 0,
"ScnConnectionAggregation", HFILL }},
{ &hf_h225_Language_item,
{ "Language item", "h225.Language_item",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_32", HFILL }},
{ &hf_h225_symmetricOperationRequired,
{ "symmetricOperationRequired", "h225.symmetricOperationRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_desiredProtocols,
{ "desiredProtocols", "h225.desiredProtocols",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SupportedProtocols", HFILL }},
{ &hf_h225_desiredProtocols_item,
{ "SupportedProtocols", "h225.SupportedProtocols",
FT_UINT32, BASE_DEC, VALS(h225_SupportedProtocols_vals), 0,
NULL, HFILL }},
{ &hf_h225_neededFeatures,
{ "neededFeatures", "h225.neededFeatures",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_FeatureDescriptor", HFILL }},
{ &hf_h225_neededFeatures_item,
{ "FeatureDescriptor", "h225.FeatureDescriptor_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_desiredFeatures,
{ "desiredFeatures", "h225.desiredFeatures",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_FeatureDescriptor", HFILL }},
{ &hf_h225_desiredFeatures_item,
{ "FeatureDescriptor", "h225.FeatureDescriptor_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_supportedFeatures,
{ "supportedFeatures", "h225.supportedFeatures",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_FeatureDescriptor", HFILL }},
{ &hf_h225_supportedFeatures_item,
{ "FeatureDescriptor", "h225.FeatureDescriptor_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_ParallelH245Control_item,
{ "ParallelH245Control item", "h225.ParallelH245Control_item",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_parallelH245Control,
{ "parallelH245Control", "h225.parallelH245Control",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_additionalSourceAddresses,
{ "additionalSourceAddresses", "h225.additionalSourceAddresses",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ExtendedAliasAddress", HFILL }},
{ &hf_h225_additionalSourceAddresses_item,
{ "ExtendedAliasAddress", "h225.ExtendedAliasAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_hopCount_1_31,
{ "hopCount", "h225.hopCount",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_31", HFILL }},
{ &hf_h225_unknown,
{ "unknown", "h225.unknown_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_bChannel,
{ "bChannel", "h225.bChannel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_hybrid2x64,
{ "hybrid2x64", "h225.hybrid2x64_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_hybrid384,
{ "hybrid384", "h225.hybrid384_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_hybrid1536,
{ "hybrid1536", "h225.hybrid1536_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_hybrid1920,
{ "hybrid1920", "h225.hybrid1920_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_multirate,
{ "multirate", "h225.multirate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_auto,
{ "auto", "h225.auto_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_none,
{ "none", "h225.none_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h221,
{ "h221", "h225.h221_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_bonded_mode1,
{ "bonded-mode1", "h225.bonded_mode1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_bonded_mode2,
{ "bonded-mode2", "h225.bonded_mode2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_bonded_mode3,
{ "bonded-mode3", "h225.bonded_mode3_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_presentationAllowed,
{ "presentationAllowed", "h225.presentationAllowed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_presentationRestricted,
{ "presentationRestricted", "h225.presentationRestricted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_addressNotAvailable,
{ "addressNotAvailable", "h225.addressNotAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_alternativeAddress,
{ "alternativeAddress", "h225.alternativeAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_alternativeAliasAddress,
{ "alternativeAliasAddress", "h225.alternativeAliasAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_alternativeAliasAddress_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_facilityReason,
{ "reason", "h225.reason",
FT_UINT32, BASE_DEC, VALS(FacilityReason_vals), 0,
"FacilityReason", HFILL }},
{ &hf_h225_conferences,
{ "conferences", "h225.conferences",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ConferenceList", HFILL }},
{ &hf_h225_conferences_item,
{ "ConferenceList", "h225.ConferenceList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_conferenceAlias,
{ "conferenceAlias", "h225.conferenceAlias",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h225_routeCallToGatekeeper,
{ "routeCallToGatekeeper", "h225.routeCallToGatekeeper_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callForwarded,
{ "callForwarded", "h225.callForwarded_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_routeCallToMC,
{ "routeCallToMC", "h225.routeCallToMC_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_conferenceListChoice,
{ "conferenceListChoice", "h225.conferenceListChoice_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_startH245,
{ "startH245", "h225.startH245_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_noH245,
{ "noH245", "h225.noH245_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_newTokens,
{ "newTokens", "h225.newTokens_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_featureSetUpdate,
{ "featureSetUpdate", "h225.featureSetUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_forwardedElements,
{ "forwardedElements", "h225.forwardedElements_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_transportedInformation,
{ "transportedInformation", "h225.transportedInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h245IpAddress,
{ "ipAddress", "h225.ipAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_h245IpAddress", HFILL }},
{ &hf_h225_h245Ip,
{ "ip", "h225.ip",
FT_IPv4, BASE_NONE, NULL, 0,
"T_h245Ip", HFILL }},
{ &hf_h225_h245IpPort,
{ "port", "h225.port",
FT_UINT32, BASE_DEC, NULL, 0,
"T_h245IpPort", HFILL }},
{ &hf_h225_h245IpSourceRoute,
{ "ipSourceRoute", "h225.ipSourceRoute_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_h245IpSourceRoute", HFILL }},
{ &hf_h225_ip,
{ "ip", "h225.ip",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_h225_port,
{ "port", "h225.port",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h225_h245Route,
{ "route", "h225.route",
FT_UINT32, BASE_DEC, NULL, 0,
"T_h245Route", HFILL }},
{ &hf_h225_h245Route_item,
{ "route item", "h225.route_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_h225_h245Routing,
{ "routing", "h225.routing",
FT_UINT32, BASE_DEC, VALS(h225_T_h245Routing_vals), 0,
"T_h245Routing", HFILL }},
{ &hf_h225_strict,
{ "strict", "h225.strict_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_loose,
{ "loose", "h225.loose_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h245IpxAddress,
{ "ipxAddress", "h225.ipxAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_h245IpxAddress", HFILL }},
{ &hf_h225_node,
{ "node", "h225.node",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_6", HFILL }},
{ &hf_h225_netnum,
{ "netnum", "h225.netnum",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_h225_h245IpxPort,
{ "port", "h225.port",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_h225_h245Ip6Address,
{ "ip6Address", "h225.ip6Address_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_h245Ip6Address", HFILL }},
{ &hf_h225_h245Ip6,
{ "ip", "h225.ip",
FT_IPv6, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_16", HFILL }},
{ &hf_h225_netBios,
{ "netBios", "h225.netBios",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_16", HFILL }},
{ &hf_h225_nsap,
{ "nsap", "h225.nsap",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_20", HFILL }},
{ &hf_h225_nonStandardAddress,
{ "nonStandardAddress", "h225.nonStandardAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h225_ipAddress,
{ "ipAddress", "h225.ipAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_ipV4,
{ "ip", "h225.ip",
FT_IPv4, BASE_NONE, NULL, 0,
"IpV4", HFILL }},
{ &hf_h225_ipV4_port,
{ "port", "h225.port",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h225_ipSourceRoute,
{ "ipSourceRoute", "h225.ipSourceRoute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_src_route_ipV4,
{ "ip", "h225.ip",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_h225_ipV4_src_port,
{ "port", "h225.port",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h225_route,
{ "route", "h225.route",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_route_item,
{ "route item", "h225.route_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_h225_routing,
{ "routing", "h225.routing",
FT_UINT32, BASE_DEC, VALS(h225_T_routing_vals), 0,
NULL, HFILL }},
{ &hf_h225_ipxAddress,
{ "ipxAddress", "h225.ipxAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_ipx_port,
{ "port", "h225.port",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_h225_ip6Address,
{ "ip6Address", "h225.ip6Address_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_ipV6,
{ "ip", "h225.ip",
FT_IPv6, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_16", HFILL }},
{ &hf_h225_ipV6_port,
{ "port", "h225.port",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h225_vendor,
{ "vendor", "h225.vendor_element",
FT_NONE, BASE_NONE, NULL, 0,
"VendorIdentifier", HFILL }},
{ &hf_h225_gatekeeper,
{ "gatekeeper", "h225.gatekeeper_element",
FT_NONE, BASE_NONE, NULL, 0,
"GatekeeperInfo", HFILL }},
{ &hf_h225_gateway,
{ "gateway", "h225.gateway_element",
FT_NONE, BASE_NONE, NULL, 0,
"GatewayInfo", HFILL }},
{ &hf_h225_mcu,
{ "mcu", "h225.mcu_element",
FT_NONE, BASE_NONE, NULL, 0,
"McuInfo", HFILL }},
{ &hf_h225_terminal,
{ "terminal", "h225.terminal_element",
FT_NONE, BASE_NONE, NULL, 0,
"TerminalInfo", HFILL }},
{ &hf_h225_mc,
{ "mc", "h225.mc",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_undefinedNode,
{ "undefinedNode", "h225.undefinedNode",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_set,
{ "set", "h225.set",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_32", HFILL }},
{ &hf_h225_supportedTunnelledProtocols,
{ "supportedTunnelledProtocols", "h225.supportedTunnelledProtocols",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TunnelledProtocol", HFILL }},
{ &hf_h225_supportedTunnelledProtocols_item,
{ "TunnelledProtocol", "h225.TunnelledProtocol_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_protocol,
{ "protocol", "h225.protocol",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SupportedProtocols", HFILL }},
{ &hf_h225_protocol_item,
{ "SupportedProtocols", "h225.SupportedProtocols",
FT_UINT32, BASE_DEC, VALS(h225_SupportedProtocols_vals), 0,
NULL, HFILL }},
{ &hf_h225_h310,
{ "h310", "h225.h310_element",
FT_NONE, BASE_NONE, NULL, 0,
"H310Caps", HFILL }},
{ &hf_h225_h320,
{ "h320", "h225.h320_element",
FT_NONE, BASE_NONE, NULL, 0,
"H320Caps", HFILL }},
{ &hf_h225_h321,
{ "h321", "h225.h321_element",
FT_NONE, BASE_NONE, NULL, 0,
"H321Caps", HFILL }},
{ &hf_h225_h322,
{ "h322", "h225.h322_element",
FT_NONE, BASE_NONE, NULL, 0,
"H322Caps", HFILL }},
{ &hf_h225_h323,
{ "h323", "h225.h323_element",
FT_NONE, BASE_NONE, NULL, 0,
"H323Caps", HFILL }},
{ &hf_h225_h324,
{ "h324", "h225.h324_element",
FT_NONE, BASE_NONE, NULL, 0,
"H324Caps", HFILL }},
{ &hf_h225_voice,
{ "voice", "h225.voice_element",
FT_NONE, BASE_NONE, NULL, 0,
"VoiceCaps", HFILL }},
{ &hf_h225_t120_only,
{ "t120-only", "h225.t120_only_element",
FT_NONE, BASE_NONE, NULL, 0,
"T120OnlyCaps", HFILL }},
{ &hf_h225_nonStandardProtocol,
{ "nonStandardProtocol", "h225.nonStandardProtocol_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_t38FaxAnnexbOnly,
{ "t38FaxAnnexbOnly", "h225.t38FaxAnnexbOnly_element",
FT_NONE, BASE_NONE, NULL, 0,
"T38FaxAnnexbOnlyCaps", HFILL }},
{ &hf_h225_sip,
{ "sip", "h225.sip_element",
FT_NONE, BASE_NONE, NULL, 0,
"SIPCaps", HFILL }},
{ &hf_h225_dataRatesSupported,
{ "dataRatesSupported", "h225.dataRatesSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_DataRate", HFILL }},
{ &hf_h225_dataRatesSupported_item,
{ "DataRate", "h225.DataRate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_supportedPrefixes,
{ "supportedPrefixes", "h225.supportedPrefixes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SupportedPrefix", HFILL }},
{ &hf_h225_supportedPrefixes_item,
{ "SupportedPrefix", "h225.SupportedPrefix_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_t38FaxProtocol,
{ "t38FaxProtocol", "h225.t38FaxProtocol",
FT_UINT32, BASE_DEC, VALS(DataProtocolCapability_vals), 0,
"DataProtocolCapability", HFILL }},
{ &hf_h225_t38FaxProfile,
{ "t38FaxProfile", "h225.t38FaxProfile_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_vendorIdentifier_vendor,
{ "vendor", "h225.vendor_element",
FT_NONE, BASE_NONE, NULL, 0,
"H221NonStandard", HFILL }},
{ &hf_h225_productId,
{ "productId", "h225.productId",
FT_STRING, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_h225_versionId,
{ "versionId", "h225.versionId",
FT_STRING, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_h225_enterpriseNumber,
{ "enterpriseNumber", "h225.enterpriseNumber",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h225_t35CountryCode,
{ "t35CountryCode", "h225.t35CountryCode",
FT_UINT32, BASE_DEC, VALS(T35CountryCode_vals), 0,
NULL, HFILL }},
{ &hf_h225_t35Extension,
{ "t35Extension", "h225.t35Extension",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_manufacturerCode,
{ "manufacturerCode", "h225.manufacturerCode",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_tunnelledProtocol_id,
{ "id", "h225.id",
FT_UINT32, BASE_DEC, VALS(h225_TunnelledProtocol_id_vals), 0,
"TunnelledProtocol_id", HFILL }},
{ &hf_h225_tunnelledProtocolObjectID,
{ "tunnelledProtocolObjectID", "h225.tunnelledProtocolObjectID",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_tunnelledProtocolAlternateID,
{ "tunnelledProtocolAlternateID", "h225.tunnelledProtocolAlternateID_element",
FT_NONE, BASE_NONE, NULL, 0,
"TunnelledProtocolAlternateIdentifier", HFILL }},
{ &hf_h225_subIdentifier,
{ "subIdentifier", "h225.subIdentifier",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_64", HFILL }},
{ &hf_h225_protocolType,
{ "protocolType", "h225.protocolType",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_64", HFILL }},
{ &hf_h225_protocolVariant,
{ "protocolVariant", "h225.protocolVariant",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_64", HFILL }},
{ &hf_h225_nonStandardIdentifier,
{ "nonStandardIdentifier", "h225.nonStandardIdentifier",
FT_UINT32, BASE_DEC, VALS(h225_NonStandardIdentifier_vals), 0,
NULL, HFILL }},
{ &hf_h225_nsp_data,
{ "data", "h225.data",
FT_UINT32, BASE_DEC, NULL, 0,
"T_nsp_data", HFILL }},
{ &hf_h225_nsiOID,
{ "object", "h225.object",
FT_OID, BASE_NONE, NULL, 0,
"T_nsiOID", HFILL }},
{ &hf_h225_h221NonStandard,
{ "h221NonStandard", "h225.h221NonStandard_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_dialledDigits,
{ "dialledDigits", "h225.dialledDigits",
FT_STRING, BASE_NONE, NULL, 0,
"DialedDigits", HFILL }},
{ &hf_h225_h323_ID,
{ "h323-ID", "h225.h323_ID",
FT_STRING, BASE_NONE, NULL, 0,
"BMPString_SIZE_1_256", HFILL }},
{ &hf_h225_url_ID,
{ "url-ID", "h225.url_ID",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_512", HFILL }},
{ &hf_h225_transportID,
{ "transportID", "h225.transportID",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_email_ID,
{ "email-ID", "h225.email_ID",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_512", HFILL }},
{ &hf_h225_partyNumber,
{ "partyNumber", "h225.partyNumber",
FT_UINT32, BASE_DEC, VALS(h225_PartyNumber_vals), 0,
NULL, HFILL }},
{ &hf_h225_mobileUIM,
{ "mobileUIM", "h225.mobileUIM",
FT_UINT32, BASE_DEC, VALS(h225_MobileUIM_vals), 0,
NULL, HFILL }},
{ &hf_h225_isupNumber,
{ "isupNumber", "h225.isupNumber",
FT_UINT32, BASE_DEC, VALS(h225_IsupNumber_vals), 0,
NULL, HFILL }},
{ &hf_h225_wildcard,
{ "wildcard", "h225.wildcard",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h225_range,
{ "range", "h225.range_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_startOfRange,
{ "startOfRange", "h225.startOfRange",
FT_UINT32, BASE_DEC, VALS(h225_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_h225_endOfRange,
{ "endOfRange", "h225.endOfRange",
FT_UINT32, BASE_DEC, VALS(h225_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_h225_e164Number,
{ "e164Number", "h225.e164Number_element",
FT_NONE, BASE_NONE, NULL, 0,
"PublicPartyNumber", HFILL }},
{ &hf_h225_dataPartyNumber,
{ "dataPartyNumber", "h225.dataPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_h225_telexPartyNumber,
{ "telexPartyNumber", "h225.telexPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_h225_privateNumber,
{ "privateNumber", "h225.privateNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrivatePartyNumber", HFILL }},
{ &hf_h225_nationalStandardPartyNumber,
{ "nationalStandardPartyNumber", "h225.nationalStandardPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_h225_publicTypeOfNumber,
{ "publicTypeOfNumber", "h225.publicTypeOfNumber",
FT_UINT32, BASE_DEC, VALS(h225_PublicTypeOfNumber_vals), 0,
NULL, HFILL }},
{ &hf_h225_publicNumberDigits,
{ "publicNumberDigits", "h225.publicNumberDigits",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_h225_privateTypeOfNumber,
{ "privateTypeOfNumber", "h225.privateTypeOfNumber",
FT_UINT32, BASE_DEC, VALS(h225_PrivateTypeOfNumber_vals), 0,
NULL, HFILL }},
{ &hf_h225_privateNumberDigits,
{ "privateNumberDigits", "h225.privateNumberDigits",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_h225_language_01,
{ "language", "h225.language",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_h225_name,
{ "name", "h225.name",
FT_STRING, BASE_NONE, NULL, 0,
"BMPString_SIZE_1_80", HFILL }},
{ &hf_h225_internationalNumber,
{ "internationalNumber", "h225.internationalNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nationalNumber,
{ "nationalNumber", "h225.nationalNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_networkSpecificNumber,
{ "networkSpecificNumber", "h225.networkSpecificNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_subscriberNumber,
{ "subscriberNumber", "h225.subscriberNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_abbreviatedNumber,
{ "abbreviatedNumber", "h225.abbreviatedNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_level2RegionalNumber,
{ "level2RegionalNumber", "h225.level2RegionalNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_level1RegionalNumber,
{ "level1RegionalNumber", "h225.level1RegionalNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_pISNSpecificNumber,
{ "pISNSpecificNumber", "h225.pISNSpecificNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_localNumber,
{ "localNumber", "h225.localNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_ansi_41_uim,
{ "ansi-41-uim", "h225.ansi_41_uim_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gsm_uim,
{ "gsm-uim", "h225.gsm_uim_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_imsi,
{ "imsi", "h225.imsi",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_3_16", HFILL }},
{ &hf_h225_min,
{ "min", "h225.min",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_3_16", HFILL }},
{ &hf_h225_mdn,
{ "mdn", "h225.mdn",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_3_16", HFILL }},
{ &hf_h225_msisdn,
{ "msisdn", "h225.msisdn",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_3_16", HFILL }},
{ &hf_h225_esn,
{ "esn", "h225.esn",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_16", HFILL }},
{ &hf_h225_mscid,
{ "mscid", "h225.mscid",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_3_16", HFILL }},
{ &hf_h225_system_id,
{ "system-id", "h225.system_id",
FT_UINT32, BASE_DEC, VALS(h225_T_system_id_vals), 0,
NULL, HFILL }},
{ &hf_h225_sid,
{ "sid", "h225.sid",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_1_4", HFILL }},
{ &hf_h225_mid,
{ "mid", "h225.mid",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_1_4", HFILL }},
{ &hf_h225_systemMyTypeCode,
{ "systemMyTypeCode", "h225.systemMyTypeCode",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_h225_systemAccessType,
{ "systemAccessType", "h225.systemAccessType",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_h225_qualificationInformationCode,
{ "qualificationInformationCode", "h225.qualificationInformationCode",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_h225_sesn,
{ "sesn", "h225.sesn",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_16", HFILL }},
{ &hf_h225_soc,
{ "soc", "h225.soc",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_3_16", HFILL }},
{ &hf_h225_tmsi,
{ "tmsi", "h225.tmsi",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_4", HFILL }},
{ &hf_h225_imei,
{ "imei", "h225.imei",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_15_16", HFILL }},
{ &hf_h225_hplmn,
{ "hplmn", "h225.hplmn",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_1_4", HFILL }},
{ &hf_h225_vplmn,
{ "vplmn", "h225.vplmn",
FT_STRING, BASE_NONE, NULL, 0,
"TBCD_STRING_SIZE_1_4", HFILL }},
{ &hf_h225_isupE164Number,
{ "e164Number", "h225.e164Number_element",
FT_NONE, BASE_NONE, NULL, 0,
"IsupPublicPartyNumber", HFILL }},
{ &hf_h225_isupDataPartyNumber,
{ "dataPartyNumber", "h225.dataPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"IsupDigits", HFILL }},
{ &hf_h225_isupTelexPartyNumber,
{ "telexPartyNumber", "h225.telexPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"IsupDigits", HFILL }},
{ &hf_h225_isupPrivateNumber,
{ "privateNumber", "h225.privateNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
"IsupPrivatePartyNumber", HFILL }},
{ &hf_h225_isupNationalStandardPartyNumber,
{ "nationalStandardPartyNumber", "h225.nationalStandardPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"IsupDigits", HFILL }},
{ &hf_h225_natureOfAddress,
{ "natureOfAddress", "h225.natureOfAddress",
FT_UINT32, BASE_DEC, VALS(h225_NatureOfAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_address,
{ "address", "h225.address",
FT_STRING, BASE_NONE, NULL, 0,
"IsupDigits", HFILL }},
{ &hf_h225_routingNumberNationalFormat,
{ "routingNumberNationalFormat", "h225.routingNumberNationalFormat_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_routingNumberNetworkSpecificFormat,
{ "routingNumberNetworkSpecificFormat", "h225.routingNumberNetworkSpecificFormat_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_routingNumberWithCalledDirectoryNumber,
{ "routingNumberWithCalledDirectoryNumber", "h225.routingNumberWithCalledDirectoryNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_extAliasAddress,
{ "address", "h225.address",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h225_aliasAddress,
{ "aliasAddress", "h225.aliasAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_aliasAddress_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_callSignalAddress,
{ "callSignalAddress", "h225.callSignalAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TransportAddress", HFILL }},
{ &hf_h225_callSignalAddress_item,
{ "TransportAddress", "h225.TransportAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_rasAddress,
{ "rasAddress", "h225.rasAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TransportAddress", HFILL }},
{ &hf_h225_rasAddress_item,
{ "TransportAddress", "h225.TransportAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_endpointType,
{ "endpointType", "h225.endpointType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_priority,
{ "priority", "h225.priority",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_h225_remoteExtensionAddress,
{ "remoteExtensionAddress", "h225.remoteExtensionAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_remoteExtensionAddress_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_alternateTransportAddresses,
{ "alternateTransportAddresses", "h225.alternateTransportAddresses_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_annexE,
{ "annexE", "h225.annexE",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TransportAddress", HFILL }},
{ &hf_h225_annexE_item,
{ "TransportAddress", "h225.TransportAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_sctp,
{ "sctp", "h225.sctp",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TransportAddress", HFILL }},
{ &hf_h225_sctp_item,
{ "TransportAddress", "h225.TransportAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_tcp,
{ "tcp", "h225.tcp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_annexE_flg,
{ "annexE", "h225.annexE_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_sctp_flg,
{ "sctp", "h225.sctp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_alternateGK_rasAddress,
{ "rasAddress", "h225.rasAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_gatekeeperIdentifier,
{ "gatekeeperIdentifier", "h225.gatekeeperIdentifier",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_needToRegister,
{ "needToRegister", "h225.needToRegister",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_alternateGatekeeper,
{ "alternateGatekeeper", "h225.alternateGatekeeper",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AlternateGK", HFILL }},
{ &hf_h225_alternateGatekeeper_item,
{ "AlternateGK", "h225.AlternateGK_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_altGKisPermanent,
{ "altGKisPermanent", "h225.altGKisPermanent",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_default,
{ "default", "h225.default_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_encryption,
{ "encryption", "h225.encryption",
FT_UINT32, BASE_DEC, VALS(h225_SecurityServiceMode_vals), 0,
"SecurityServiceMode", HFILL }},
{ &hf_h225_authenticaton,
{ "authenticaton", "h225.authenticaton",
FT_UINT32, BASE_DEC, VALS(h225_SecurityServiceMode_vals), 0,
"SecurityServiceMode", HFILL }},
{ &hf_h225_securityCapabilities_integrity,
{ "integrity", "h225.integrity",
FT_UINT32, BASE_DEC, VALS(h225_SecurityServiceMode_vals), 0,
"SecurityServiceMode", HFILL }},
{ &hf_h225_securityWrongSyncTime,
{ "securityWrongSyncTime", "h225.securityWrongSyncTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityReplay,
{ "securityReplay", "h225.securityReplay_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityWrongGeneralID,
{ "securityWrongGeneralID", "h225.securityWrongGeneralID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityWrongSendersID,
{ "securityWrongSendersID", "h225.securityWrongSendersID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityIntegrityFailed,
{ "securityIntegrityFailed", "h225.securityIntegrityFailed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityWrongOID,
{ "securityWrongOID", "h225.securityWrongOID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityDHmismatch,
{ "securityDHmismatch", "h225.securityDHmismatch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityCertificateExpired,
{ "securityCertificateExpired", "h225.securityCertificateExpired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityCertificateDateInvalid,
{ "securityCertificateDateInvalid", "h225.securityCertificateDateInvalid_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityCertificateRevoked,
{ "securityCertificateRevoked", "h225.securityCertificateRevoked_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityCertificateNotReadable,
{ "securityCertificateNotReadable", "h225.securityCertificateNotReadable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityCertificateSignatureInvalid,
{ "securityCertificateSignatureInvalid", "h225.securityCertificateSignatureInvalid_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityCertificateMissing,
{ "securityCertificateMissing", "h225.securityCertificateMissing_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityCertificateIncomplete,
{ "securityCertificateIncomplete", "h225.securityCertificateIncomplete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityUnsupportedCertificateAlgOID,
{ "securityUnsupportedCertificateAlgOID", "h225.securityUnsupportedCertificateAlgOID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityUnknownCA,
{ "securityUnknownCA", "h225.securityUnknownCA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_noSecurity,
{ "noSecurity", "h225.noSecurity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_tls,
{ "tls", "h225.tls_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityCapabilities", HFILL }},
{ &hf_h225_ipsec,
{ "ipsec", "h225.ipsec_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityCapabilities", HFILL }},
{ &hf_h225_q932Full,
{ "q932Full", "h225.q932Full",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_q951Full,
{ "q951Full", "h225.q951Full",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_q952Full,
{ "q952Full", "h225.q952Full",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_q953Full,
{ "q953Full", "h225.q953Full",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_q955Full,
{ "q955Full", "h225.q955Full",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_q956Full,
{ "q956Full", "h225.q956Full",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_q957Full,
{ "q957Full", "h225.q957Full",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_q954Info,
{ "q954Info", "h225.q954Info_element",
FT_NONE, BASE_NONE, NULL, 0,
"Q954Details", HFILL }},
{ &hf_h225_conferenceCalling,
{ "conferenceCalling", "h225.conferenceCalling",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_threePartyService,
{ "threePartyService", "h225.threePartyService",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_guid,
{ "guid", "h225.guid",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_isoAlgorithm,
{ "isoAlgorithm", "h225.isoAlgorithm",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h225_hMAC_MD5,
{ "hMAC-MD5", "h225.hMAC_MD5_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_hMAC_iso10118_2_s,
{ "hMAC-iso10118-2-s", "h225.hMAC_iso10118_2_s",
FT_UINT32, BASE_DEC, VALS(h225_EncryptIntAlg_vals), 0,
"EncryptIntAlg", HFILL }},
{ &hf_h225_hMAC_iso10118_2_l,
{ "hMAC-iso10118-2-l", "h225.hMAC_iso10118_2_l",
FT_UINT32, BASE_DEC, VALS(h225_EncryptIntAlg_vals), 0,
"EncryptIntAlg", HFILL }},
{ &hf_h225_hMAC_iso10118_3,
{ "hMAC-iso10118-3", "h225.hMAC_iso10118_3",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h225_digSig,
{ "digSig", "h225.digSig_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_iso9797,
{ "iso9797", "h225.iso9797",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h225_nonIsoIM,
{ "nonIsoIM", "h225.nonIsoIM",
FT_UINT32, BASE_DEC, VALS(h225_NonIsoIntegrityMechanism_vals), 0,
"NonIsoIntegrityMechanism", HFILL }},
{ &hf_h225_algorithmOID,
{ "algorithmOID", "h225.algorithmOID",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h225_icv,
{ "icv", "h225.icv",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_h225_cryptoEPPwdHash,
{ "cryptoEPPwdHash", "h225.cryptoEPPwdHash_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_alias,
{ "alias", "h225.alias",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h225_timeStamp,
{ "timeStamp", "h225.timeStamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
NULL, HFILL }},
{ &hf_h225_token,
{ "token", "h225.token_element",
FT_NONE, BASE_NONE, NULL, 0,
"HASHED", HFILL }},
{ &hf_h225_cryptoGKPwdHash,
{ "cryptoGKPwdHash", "h225.cryptoGKPwdHash_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatekeeperId,
{ "gatekeeperId", "h225.gatekeeperId",
FT_STRING, BASE_NONE, NULL, 0,
"GatekeeperIdentifier", HFILL }},
{ &hf_h225_cryptoEPPwdEncr,
{ "cryptoEPPwdEncr", "h225.cryptoEPPwdEncr_element",
FT_NONE, BASE_NONE, NULL, 0,
"ENCRYPTED", HFILL }},
{ &hf_h225_cryptoGKPwdEncr,
{ "cryptoGKPwdEncr", "h225.cryptoGKPwdEncr_element",
FT_NONE, BASE_NONE, NULL, 0,
"ENCRYPTED", HFILL }},
{ &hf_h225_cryptoEPCert,
{ "cryptoEPCert", "h225.cryptoEPCert_element",
FT_NONE, BASE_NONE, NULL, 0,
"SIGNED", HFILL }},
{ &hf_h225_cryptoGKCert,
{ "cryptoGKCert", "h225.cryptoGKCert_element",
FT_NONE, BASE_NONE, NULL, 0,
"SIGNED", HFILL }},
{ &hf_h225_cryptoFastStart,
{ "cryptoFastStart", "h225.cryptoFastStart_element",
FT_NONE, BASE_NONE, NULL, 0,
"SIGNED", HFILL }},
{ &hf_h225_nestedcryptoToken,
{ "nestedcryptoToken", "h225.nestedcryptoToken",
FT_UINT32, BASE_DEC, VALS(h235_CryptoToken_vals), 0,
"CryptoToken", HFILL }},
{ &hf_h225_channelRate,
{ "channelRate", "h225.channelRate",
FT_UINT32, BASE_DEC, NULL, 0,
"BandWidth", HFILL }},
{ &hf_h225_channelMultiplier,
{ "channelMultiplier", "h225.channelMultiplier",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_256", HFILL }},
{ &hf_h225_globalCallId,
{ "globalCallId", "h225.globalCallId",
FT_GUID, BASE_NONE, NULL, 0,
"GloballyUniqueID", HFILL }},
{ &hf_h225_threadId,
{ "threadId", "h225.threadId",
FT_GUID, BASE_NONE, NULL, 0,
"GloballyUniqueID", HFILL }},
{ &hf_h225_prefix,
{ "prefix", "h225.prefix",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h225_canReportCallCapacity,
{ "canReportCallCapacity", "h225.canReportCallCapacity",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_capacityReportingSpecification_when,
{ "when", "h225.when_element",
FT_NONE, BASE_NONE, NULL, 0,
"CapacityReportingSpecification_when", HFILL }},
{ &hf_h225_callStart,
{ "callStart", "h225.callStart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callEnd,
{ "callEnd", "h225.callEnd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_maximumCallCapacity,
{ "maximumCallCapacity", "h225.maximumCallCapacity_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallCapacityInfo", HFILL }},
{ &hf_h225_currentCallCapacity,
{ "currentCallCapacity", "h225.currentCallCapacity_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallCapacityInfo", HFILL }},
{ &hf_h225_voiceGwCallsAvailable,
{ "voiceGwCallsAvailable", "h225.voiceGwCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_voiceGwCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h310GwCallsAvailable,
{ "h310GwCallsAvailable", "h225.h310GwCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_h310GwCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h320GwCallsAvailable,
{ "h320GwCallsAvailable", "h225.h320GwCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_h320GwCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h321GwCallsAvailable,
{ "h321GwCallsAvailable", "h225.h321GwCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_h321GwCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h322GwCallsAvailable,
{ "h322GwCallsAvailable", "h225.h322GwCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_h322GwCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h323GwCallsAvailable,
{ "h323GwCallsAvailable", "h225.h323GwCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_h323GwCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h324GwCallsAvailable,
{ "h324GwCallsAvailable", "h225.h324GwCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_h324GwCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_t120OnlyGwCallsAvailable,
{ "t120OnlyGwCallsAvailable", "h225.t120OnlyGwCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_t120OnlyGwCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_t38FaxAnnexbOnlyGwCallsAvailable,
{ "t38FaxAnnexbOnlyGwCallsAvailable", "h225.t38FaxAnnexbOnlyGwCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_t38FaxAnnexbOnlyGwCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_terminalCallsAvailable,
{ "terminalCallsAvailable", "h225.terminalCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_terminalCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_mcuCallsAvailable,
{ "mcuCallsAvailable", "h225.mcuCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_mcuCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_sipGwCallsAvailable,
{ "sipGwCallsAvailable", "h225.sipGwCallsAvailable",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallsAvailable", HFILL }},
{ &hf_h225_sipGwCallsAvailable_item,
{ "CallsAvailable", "h225.CallsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_calls,
{ "calls", "h225.calls",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_h225_group_IA5String,
{ "group", "h225.group",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_128", HFILL }},
{ &hf_h225_carrier,
{ "carrier", "h225.carrier_element",
FT_NONE, BASE_NONE, NULL, 0,
"CarrierInfo", HFILL }},
{ &hf_h225_sourceCircuitID,
{ "sourceCircuitID", "h225.sourceCircuitID_element",
FT_NONE, BASE_NONE, NULL, 0,
"CircuitIdentifier", HFILL }},
{ &hf_h225_destinationCircuitID,
{ "destinationCircuitID", "h225.destinationCircuitID_element",
FT_NONE, BASE_NONE, NULL, 0,
"CircuitIdentifier", HFILL }},
{ &hf_h225_cic,
{ "cic", "h225.cic_element",
FT_NONE, BASE_NONE, NULL, 0,
"CicInfo", HFILL }},
{ &hf_h225_group,
{ "group", "h225.group_element",
FT_NONE, BASE_NONE, NULL, 0,
"GroupID", HFILL }},
{ &hf_h225_cic_2_4,
{ "cic", "h225.cic",
FT_UINT32, BASE_DEC, NULL, 0,
"T_cic_2_4", HFILL }},
{ &hf_h225_cic_2_4_item,
{ "cic item", "h225.cic_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2_4", HFILL }},
{ &hf_h225_pointCode,
{ "pointCode", "h225.pointCode",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2_5", HFILL }},
{ &hf_h225_member,
{ "member", "h225.member",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_member_item,
{ "member item", "h225.member_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h225_carrierIdentificationCode,
{ "carrierIdentificationCode", "h225.carrierIdentificationCode",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3_4", HFILL }},
{ &hf_h225_carrierName,
{ "carrierName", "h225.carrierName",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_128", HFILL }},
{ &hf_h225_url,
{ "url", "h225.url",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_0_512", HFILL }},
{ &hf_h225_signal,
{ "signal", "h225.signal",
FT_BYTES, BASE_NONE, NULL, 0,
"H248SignalsDescriptor", HFILL }},
{ &hf_h225_callCreditServiceControl,
{ "callCreditServiceControl", "h225.callCreditServiceControl_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_sessionId_0_255,
{ "sessionId", "h225.sessionId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h225_contents,
{ "contents", "h225.contents",
FT_UINT32, BASE_DEC, VALS(h225_ServiceControlDescriptor_vals), 0,
"ServiceControlDescriptor", HFILL }},
{ &hf_h225_reason,
{ "reason", "h225.reason",
FT_UINT32, BASE_DEC, VALS(h225_ServiceControlSession_reason_vals), 0,
"ServiceControlSession_reason", HFILL }},
{ &hf_h225_open,
{ "open", "h225.open_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_refresh,
{ "refresh", "h225.refresh_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_close,
{ "close", "h225.close_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nonStandardUsageTypes,
{ "nonStandardUsageTypes", "h225.nonStandardUsageTypes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_NonStandardParameter", HFILL }},
{ &hf_h225_nonStandardUsageTypes_item,
{ "NonStandardParameter", "h225.NonStandardParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_startTime,
{ "startTime", "h225.startTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_endTime_flg,
{ "endTime", "h225.endTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_terminationCause_flg,
{ "terminationCause", "h225.terminationCause_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_when,
{ "when", "h225.when_element",
FT_NONE, BASE_NONE, NULL, 0,
"RasUsageSpecification_when", HFILL }},
{ &hf_h225_start,
{ "start", "h225.start_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_end,
{ "end", "h225.end_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_inIrr,
{ "inIrr", "h225.inIrr_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_ras_callStartingPoint,
{ "callStartingPoint", "h225.callStartingPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"RasUsageSpecificationcallStartingPoint", HFILL }},
{ &hf_h225_alerting_flg,
{ "alerting", "h225.alerting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_connect_flg,
{ "connect", "h225.connect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_required,
{ "required", "h225.required_element",
FT_NONE, BASE_NONE, NULL, 0,
"RasUsageInfoTypes", HFILL }},
{ &hf_h225_nonStandardUsageFields,
{ "nonStandardUsageFields", "h225.nonStandardUsageFields",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_NonStandardParameter", HFILL }},
{ &hf_h225_nonStandardUsageFields_item,
{ "NonStandardParameter", "h225.NonStandardParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_alertingTime,
{ "alertingTime", "h225.alertingTime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_h225_connectTime,
{ "connectTime", "h225.connectTime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_h225_endTime,
{ "endTime", "h225.endTime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_h225_releaseCompleteCauseIE,
{ "releaseCompleteCauseIE", "h225.releaseCompleteCauseIE",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2_32", HFILL }},
{ &hf_h225_sender,
{ "sender", "h225.sender",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_multicast,
{ "multicast", "h225.multicast",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_bandwidth,
{ "bandwidth", "h225.bandwidth",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_rtcpAddresses,
{ "rtcpAddresses", "h225.rtcpAddresses_element",
FT_NONE, BASE_NONE, NULL, 0,
"TransportChannelInfo", HFILL }},
{ &hf_h225_canDisplayAmountString,
{ "canDisplayAmountString", "h225.canDisplayAmountString",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_canEnforceDurationLimit,
{ "canEnforceDurationLimit", "h225.canEnforceDurationLimit",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_amountString,
{ "amountString", "h225.amountString",
FT_STRING, BASE_NONE, NULL, 0,
"BMPString_SIZE_1_512", HFILL }},
{ &hf_h225_billingMode,
{ "billingMode", "h225.billingMode",
FT_UINT32, BASE_DEC, VALS(h225_T_billingMode_vals), 0,
NULL, HFILL }},
{ &hf_h225_credit,
{ "credit", "h225.credit_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_debit,
{ "debit", "h225.debit_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callDurationLimit,
{ "callDurationLimit", "h225.callDurationLimit",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_4294967295", HFILL }},
{ &hf_h225_enforceCallDurationLimit,
{ "enforceCallDurationLimit", "h225.enforceCallDurationLimit",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_callStartingPoint,
{ "callStartingPoint", "h225.callStartingPoint",
FT_UINT32, BASE_DEC, VALS(h225_CallCreditServiceControl_callStartingPoint_vals), 0,
"CallCreditServiceControl_callStartingPoint", HFILL }},
{ &hf_h225_id,
{ "id", "h225.id",
FT_UINT32, BASE_DEC, VALS(h225_GenericIdentifier_vals), 0,
"GenericIdentifier", HFILL }},
{ &hf_h225_parameters,
{ "parameters", "h225.parameters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_parameters_item,
{ "parameters item", "h225.parameters_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_standard,
{ "standard", "h225.standard",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_oid,
{ "oid", "h225.oid",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_genericIdentifier_nonStandard,
{ "nonStandard", "h225.nonStandard",
FT_GUID, BASE_NONE, NULL, 0,
"GloballyUniqueID", HFILL }},
{ &hf_h225_content,
{ "content", "h225.content",
FT_UINT32, BASE_DEC, VALS(h225_Content_vals), 0,
NULL, HFILL }},
{ &hf_h225_raw,
{ "raw", "h225.raw",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_text,
{ "text", "h225.text",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_h225_unicode,
{ "unicode", "h225.unicode",
FT_STRING, BASE_NONE, NULL, 0,
"BMPString", HFILL }},
{ &hf_h225_bool,
{ "bool", "h225.bool",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_number8,
{ "number8", "h225.number8",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h225_number16,
{ "number16", "h225.number16",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h225_number32,
{ "number32", "h225.number32",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_h225_transport,
{ "transport", "h225.transport",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_compound,
{ "compound", "h225.compound",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_512_OF_EnumeratedParameter", HFILL }},
{ &hf_h225_compound_item,
{ "EnumeratedParameter", "h225.EnumeratedParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nested,
{ "nested", "h225.nested",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_GenericData", HFILL }},
{ &hf_h225_nested_item,
{ "GenericData", "h225.GenericData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_replacementFeatureSet,
{ "replacementFeatureSet", "h225.replacementFeatureSet",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_sendAddress,
{ "sendAddress", "h225.sendAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_recvAddress,
{ "recvAddress", "h225.recvAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_rtpAddress,
{ "rtpAddress", "h225.rtpAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"TransportChannelInfo", HFILL }},
{ &hf_h225_rtcpAddress,
{ "rtcpAddress", "h225.rtcpAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"TransportChannelInfo", HFILL }},
{ &hf_h225_cname,
{ "cname", "h225.cname",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_h225_ssrc,
{ "ssrc", "h225.ssrc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_4294967295", HFILL }},
{ &hf_h225_sessionId,
{ "sessionId", "h225.sessionId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_255", HFILL }},
{ &hf_h225_associatedSessionIds,
{ "associatedSessionIds", "h225.associatedSessionIds",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_associatedSessionIds_item,
{ "associatedSessionIds item", "h225.associatedSessionIds_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_255", HFILL }},
{ &hf_h225_multicast_flg,
{ "multicast", "h225.multicast_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatekeeperBased,
{ "gatekeeperBased", "h225.gatekeeperBased_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_endpointBased,
{ "endpointBased", "h225.endpointBased_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatekeeperRequest,
{ "gatekeeperRequest", "h225.gatekeeperRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatekeeperConfirm,
{ "gatekeeperConfirm", "h225.gatekeeperConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatekeeperReject,
{ "gatekeeperReject", "h225.gatekeeperReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_registrationRequest,
{ "registrationRequest", "h225.registrationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_registrationConfirm,
{ "registrationConfirm", "h225.registrationConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_registrationReject,
{ "registrationReject", "h225.registrationReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_unregistrationRequest,
{ "unregistrationRequest", "h225.unregistrationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_unregistrationConfirm,
{ "unregistrationConfirm", "h225.unregistrationConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_unregistrationReject,
{ "unregistrationReject", "h225.unregistrationReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_admissionRequest,
{ "admissionRequest", "h225.admissionRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_admissionConfirm,
{ "admissionConfirm", "h225.admissionConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_admissionReject,
{ "admissionReject", "h225.admissionReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_bandwidthRequest,
{ "bandwidthRequest", "h225.bandwidthRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_bandwidthConfirm,
{ "bandwidthConfirm", "h225.bandwidthConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_bandwidthReject,
{ "bandwidthReject", "h225.bandwidthReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_disengageRequest,
{ "disengageRequest", "h225.disengageRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_disengageConfirm,
{ "disengageConfirm", "h225.disengageConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_disengageReject,
{ "disengageReject", "h225.disengageReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_locationRequest,
{ "locationRequest", "h225.locationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_locationConfirm,
{ "locationConfirm", "h225.locationConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_locationReject,
{ "locationReject", "h225.locationReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_infoRequest,
{ "infoRequest", "h225.infoRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_infoRequestResponse,
{ "infoRequestResponse", "h225.infoRequestResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nonStandardMessage,
{ "nonStandardMessage", "h225.nonStandardMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_unknownMessageResponse,
{ "unknownMessageResponse", "h225.unknownMessageResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_requestInProgress,
{ "requestInProgress", "h225.requestInProgress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_resourcesAvailableIndicate,
{ "resourcesAvailableIndicate", "h225.resourcesAvailableIndicate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_resourcesAvailableConfirm,
{ "resourcesAvailableConfirm", "h225.resourcesAvailableConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_infoRequestAck,
{ "infoRequestAck", "h225.infoRequestAck_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_infoRequestNak,
{ "infoRequestNak", "h225.infoRequestNak_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_serviceControlIndication,
{ "serviceControlIndication", "h225.serviceControlIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_serviceControlResponse,
{ "serviceControlResponse", "h225.serviceControlResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_admissionConfirmSequence,
{ "admissionConfirmSequence", "h225.admissionConfirmSequence",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AdmissionConfirm", HFILL }},
{ &hf_h225_admissionConfirmSequence_item,
{ "AdmissionConfirm", "h225.AdmissionConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_requestSeqNum,
{ "requestSeqNum", "h225.requestSeqNum",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatekeeperRequest_rasAddress,
{ "rasAddress", "h225.rasAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_endpointAlias,
{ "endpointAlias", "h225.endpointAlias",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_endpointAlias_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_alternateEndpoints,
{ "alternateEndpoints", "h225.alternateEndpoints",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Endpoint", HFILL }},
{ &hf_h225_alternateEndpoints_item,
{ "Endpoint", "h225.Endpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_authenticationCapability,
{ "authenticationCapability", "h225.authenticationCapability",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AuthenticationMechanism", HFILL }},
{ &hf_h225_authenticationCapability_item,
{ "AuthenticationMechanism", "h225.AuthenticationMechanism",
FT_UINT32, BASE_DEC, VALS(h235_AuthenticationMechanism_vals), 0,
NULL, HFILL }},
{ &hf_h225_algorithmOIDs,
{ "algorithmOIDs", "h225.algorithmOIDs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_algorithmOIDs_item,
{ "algorithmOIDs item", "h225.algorithmOIDs_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h225_integrity,
{ "integrity", "h225.integrity",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_IntegrityMechanism", HFILL }},
{ &hf_h225_integrity_item,
{ "IntegrityMechanism", "h225.IntegrityMechanism",
FT_UINT32, BASE_DEC, VALS(h225_IntegrityMechanism_vals), 0,
NULL, HFILL }},
{ &hf_h225_integrityCheckValue,
{ "integrityCheckValue", "h225.integrityCheckValue_element",
FT_NONE, BASE_NONE, NULL, 0,
"ICV", HFILL }},
{ &hf_h225_supportsAltGK,
{ "supportsAltGK", "h225.supportsAltGK_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_supportsAssignedGK,
{ "supportsAssignedGK", "h225.supportsAssignedGK",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_assignedGatekeeper,
{ "assignedGatekeeper", "h225.assignedGatekeeper_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlternateGK", HFILL }},
{ &hf_h225_gatekeeperConfirm_rasAddress,
{ "rasAddress", "h225.rasAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_authenticationMode,
{ "authenticationMode", "h225.authenticationMode",
FT_UINT32, BASE_DEC, VALS(h235_AuthenticationMechanism_vals), 0,
"AuthenticationMechanism", HFILL }},
{ &hf_h225_rehomingModel,
{ "rehomingModel", "h225.rehomingModel",
FT_UINT32, BASE_DEC, VALS(h225_RehomingModel_vals), 0,
NULL, HFILL }},
{ &hf_h225_gatekeeperRejectReason,
{ "rejectReason", "h225.rejectReason",
FT_UINT32, BASE_DEC, VALS(GatekeeperRejectReason_vals), 0,
"GatekeeperRejectReason", HFILL }},
{ &hf_h225_altGKInfo,
{ "altGKInfo", "h225.altGKInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_resourceUnavailable,
{ "resourceUnavailable", "h225.resourceUnavailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_terminalExcluded,
{ "terminalExcluded", "h225.terminalExcluded_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityDenial,
{ "securityDenial", "h225.securityDenial_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gkRej_securityError,
{ "securityError", "h225.securityError",
FT_UINT32, BASE_DEC, VALS(h225_SecurityErrors_vals), 0,
"SecurityErrors", HFILL }},
{ &hf_h225_discoveryComplete,
{ "discoveryComplete", "h225.discoveryComplete",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_terminalType,
{ "terminalType", "h225.terminalType_element",
FT_NONE, BASE_NONE, NULL, 0,
"EndpointType", HFILL }},
{ &hf_h225_terminalAlias,
{ "terminalAlias", "h225.terminalAlias",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_terminalAlias_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_endpointVendor,
{ "endpointVendor", "h225.endpointVendor_element",
FT_NONE, BASE_NONE, NULL, 0,
"VendorIdentifier", HFILL }},
{ &hf_h225_timeToLive,
{ "timeToLive", "h225.timeToLive",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_keepAlive,
{ "keepAlive", "h225.keepAlive",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_willSupplyUUIEs,
{ "willSupplyUUIEs", "h225.willSupplyUUIEs",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_additiveRegistration,
{ "additiveRegistration", "h225.additiveRegistration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_terminalAliasPattern,
{ "terminalAliasPattern", "h225.terminalAliasPattern",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AddressPattern", HFILL }},
{ &hf_h225_terminalAliasPattern_item,
{ "AddressPattern", "h225.AddressPattern",
FT_UINT32, BASE_DEC, VALS(h225_AddressPattern_vals), 0,
NULL, HFILL }},
{ &hf_h225_usageReportingCapability,
{ "usageReportingCapability", "h225.usageReportingCapability_element",
FT_NONE, BASE_NONE, NULL, 0,
"RasUsageInfoTypes", HFILL }},
{ &hf_h225_supportedH248Packages,
{ "supportedH248Packages", "h225.supportedH248Packages",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_H248PackagesDescriptor", HFILL }},
{ &hf_h225_supportedH248Packages_item,
{ "H248PackagesDescriptor", "h225.H248PackagesDescriptor",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callCreditCapability,
{ "callCreditCapability", "h225.callCreditCapability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_capacityReportingCapability,
{ "capacityReportingCapability", "h225.capacityReportingCapability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_restart,
{ "restart", "h225.restart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_supportsACFSequences,
{ "supportsACFSequences", "h225.supportsACFSequences_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_transportQOS,
{ "transportQOS", "h225.transportQOS",
FT_UINT32, BASE_DEC, VALS(h225_TransportQOS_vals), 0,
NULL, HFILL }},
{ &hf_h225_willRespondToIRR,
{ "willRespondToIRR", "h225.willRespondToIRR",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_preGrantedARQ,
{ "preGrantedARQ", "h225.preGrantedARQ_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_makeCall,
{ "makeCall", "h225.makeCall",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_useGKCallSignalAddressToMakeCall,
{ "useGKCallSignalAddressToMakeCall", "h225.useGKCallSignalAddressToMakeCall",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_answerCall,
{ "answerCall", "h225.answerCall",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_useGKCallSignalAddressToAnswer,
{ "useGKCallSignalAddressToAnswer", "h225.useGKCallSignalAddressToAnswer",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_irrFrequencyInCall,
{ "irrFrequencyInCall", "h225.irrFrequencyInCall",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_65535", HFILL }},
{ &hf_h225_totalBandwidthRestriction,
{ "totalBandwidthRestriction", "h225.totalBandwidthRestriction",
FT_UINT32, BASE_DEC, NULL, 0,
"BandWidth", HFILL }},
{ &hf_h225_useSpecifiedTransport,
{ "useSpecifiedTransport", "h225.useSpecifiedTransport",
FT_UINT32, BASE_DEC, VALS(h225_UseSpecifiedTransport_vals), 0,
NULL, HFILL }},
{ &hf_h225_supportsAdditiveRegistration,
{ "supportsAdditiveRegistration", "h225.supportsAdditiveRegistration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_usageSpec,
{ "usageSpec", "h225.usageSpec",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_RasUsageSpecification", HFILL }},
{ &hf_h225_usageSpec_item,
{ "RasUsageSpecification", "h225.RasUsageSpecification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_featureServerAlias,
{ "featureServerAlias", "h225.featureServerAlias",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h225_capacityReportingSpec,
{ "capacityReportingSpec", "h225.capacityReportingSpec_element",
FT_NONE, BASE_NONE, NULL, 0,
"CapacityReportingSpecification", HFILL }},
{ &hf_h225_registrationRejectReason,
{ "rejectReason", "h225.rejectReason",
FT_UINT32, BASE_DEC, VALS(RegistrationRejectReason_vals), 0,
"RegistrationRejectReason", HFILL }},
{ &hf_h225_discoveryRequired,
{ "discoveryRequired", "h225.discoveryRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_invalidCallSignalAddress,
{ "invalidCallSignalAddress", "h225.invalidCallSignalAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_invalidRASAddress,
{ "invalidRASAddress", "h225.invalidRASAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_duplicateAlias,
{ "duplicateAlias", "h225.duplicateAlias",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_duplicateAlias_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_invalidTerminalType,
{ "invalidTerminalType", "h225.invalidTerminalType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_transportNotSupported,
{ "transportNotSupported", "h225.transportNotSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_transportQOSNotSupported,
{ "transportQOSNotSupported", "h225.transportQOSNotSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_invalidAlias,
{ "invalidAlias", "h225.invalidAlias_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_fullRegistrationRequired,
{ "fullRegistrationRequired", "h225.fullRegistrationRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_additiveRegistrationNotSupported,
{ "additiveRegistrationNotSupported", "h225.additiveRegistrationNotSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_invalidTerminalAliases,
{ "invalidTerminalAliases", "h225.invalidTerminalAliases_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_reg_securityError,
{ "securityError", "h225.securityError",
FT_UINT32, BASE_DEC, VALS(h225_SecurityErrors_vals), 0,
"SecurityErrors", HFILL }},
{ &hf_h225_registerWithAssignedGK,
{ "registerWithAssignedGK", "h225.registerWithAssignedGK_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_unregRequestReason,
{ "reason", "h225.reason",
FT_UINT32, BASE_DEC, VALS(UnregRequestReason_vals), 0,
"UnregRequestReason", HFILL }},
{ &hf_h225_endpointAliasPattern,
{ "endpointAliasPattern", "h225.endpointAliasPattern",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AddressPattern", HFILL }},
{ &hf_h225_endpointAliasPattern_item,
{ "AddressPattern", "h225.AddressPattern",
FT_UINT32, BASE_DEC, VALS(h225_AddressPattern_vals), 0,
NULL, HFILL }},
{ &hf_h225_reregistrationRequired,
{ "reregistrationRequired", "h225.reregistrationRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_ttlExpired,
{ "ttlExpired", "h225.ttlExpired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_maintenance,
{ "maintenance", "h225.maintenance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_securityError,
{ "securityError", "h225.securityError",
FT_UINT32, BASE_DEC, VALS(h225_SecurityErrors2_vals), 0,
"SecurityErrors2", HFILL }},
{ &hf_h225_unregRejectReason,
{ "rejectReason", "h225.rejectReason",
FT_UINT32, BASE_DEC, VALS(UnregRejectReason_vals), 0,
"UnregRejectReason", HFILL }},
{ &hf_h225_notCurrentlyRegistered,
{ "notCurrentlyRegistered", "h225.notCurrentlyRegistered_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callInProgress,
{ "callInProgress", "h225.callInProgress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_permissionDenied,
{ "permissionDenied", "h225.permissionDenied_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callModel,
{ "callModel", "h225.callModel",
FT_UINT32, BASE_DEC, VALS(h225_CallModel_vals), 0,
NULL, HFILL }},
{ &hf_h225_DestinationInfo_item,
{ "DestinationInfo item", "h225.DestinationInfo_item",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_destinationInfo_01,
{ "destinationInfo", "h225.destinationInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_srcInfo,
{ "srcInfo", "h225.srcInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_srcInfo_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_srcCallSignalAddress,
{ "srcCallSignalAddress", "h225.srcCallSignalAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_bandWidth,
{ "bandWidth", "h225.bandWidth",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_callReferenceValue,
{ "callReferenceValue", "h225.callReferenceValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_canMapAlias,
{ "canMapAlias", "h225.canMapAlias",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_srcAlternatives,
{ "srcAlternatives", "h225.srcAlternatives",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Endpoint", HFILL }},
{ &hf_h225_srcAlternatives_item,
{ "Endpoint", "h225.Endpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_destAlternatives,
{ "destAlternatives", "h225.destAlternatives",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Endpoint", HFILL }},
{ &hf_h225_destAlternatives_item,
{ "Endpoint", "h225.Endpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatewayDataRate,
{ "gatewayDataRate", "h225.gatewayDataRate_element",
FT_NONE, BASE_NONE, NULL, 0,
"DataRate", HFILL }},
{ &hf_h225_desiredTunnelledProtocol,
{ "desiredTunnelledProtocol", "h225.desiredTunnelledProtocol_element",
FT_NONE, BASE_NONE, NULL, 0,
"TunnelledProtocol", HFILL }},
{ &hf_h225_canMapSrcAlias,
{ "canMapSrcAlias", "h225.canMapSrcAlias",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_pointToPoint,
{ "pointToPoint", "h225.pointToPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_oneToN,
{ "oneToN", "h225.oneToN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nToOne,
{ "nToOne", "h225.nToOne_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nToN,
{ "nToN", "h225.nToN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_direct,
{ "direct", "h225.direct_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatekeeperRouted,
{ "gatekeeperRouted", "h225.gatekeeperRouted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_endpointControlled,
{ "endpointControlled", "h225.endpointControlled_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_gatekeeperControlled,
{ "gatekeeperControlled", "h225.gatekeeperControlled_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_noControl,
{ "noControl", "h225.noControl_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_qOSCapabilities,
{ "qOSCapabilities", "h225.qOSCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_256_OF_QOSCapability", HFILL }},
{ &hf_h225_qOSCapabilities_item,
{ "QOSCapability", "h225.QOSCapability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_irrFrequency,
{ "irrFrequency", "h225.irrFrequency",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_65535", HFILL }},
{ &hf_h225_destinationType,
{ "destinationType", "h225.destinationType_element",
FT_NONE, BASE_NONE, NULL, 0,
"EndpointType", HFILL }},
{ &hf_h225_uuiesRequested,
{ "uuiesRequested", "h225.uuiesRequested_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_supportedProtocols,
{ "supportedProtocols", "h225.supportedProtocols",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SupportedProtocols", HFILL }},
{ &hf_h225_supportedProtocols_item,
{ "SupportedProtocols", "h225.SupportedProtocols",
FT_UINT32, BASE_DEC, VALS(h225_SupportedProtocols_vals), 0,
NULL, HFILL }},
{ &hf_h225_modifiedSrcInfo,
{ "modifiedSrcInfo", "h225.modifiedSrcInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_modifiedSrcInfo_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_setup_bool,
{ "setup", "h225.setup",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_callProceeding_flg,
{ "callProceeding", "h225.callProceeding",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_connect_bool,
{ "connect", "h225.connect",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_alerting_bool,
{ "alerting", "h225.alerting",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_information_bool,
{ "information", "h225.information",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_releaseComplete_bool,
{ "releaseComplete", "h225.releaseComplete",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_facility_bool,
{ "facility", "h225.facility",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_progress_bool,
{ "progress", "h225.progress",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_empty,
{ "empty", "h225.empty",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_status_bool,
{ "status", "h225.status",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_statusInquiry_bool,
{ "statusInquiry", "h225.statusInquiry",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_setupAcknowledge_bool,
{ "setupAcknowledge", "h225.setupAcknowledge",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_notify_bool,
{ "notify", "h225.notify",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_rejectReason,
{ "rejectReason", "h225.rejectReason",
FT_UINT32, BASE_DEC, VALS(AdmissionRejectReason_vals), 0,
"AdmissionRejectReason", HFILL }},
{ &hf_h225_invalidPermission,
{ "invalidPermission", "h225.invalidPermission_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_requestDenied,
{ "requestDenied", "h225.requestDenied_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_invalidEndpointIdentifier,
{ "invalidEndpointIdentifier", "h225.invalidEndpointIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_qosControlNotSupported,
{ "qosControlNotSupported", "h225.qosControlNotSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_incompleteAddress,
{ "incompleteAddress", "h225.incompleteAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_aliasesInconsistent,
{ "aliasesInconsistent", "h225.aliasesInconsistent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_routeCallToSCN,
{ "routeCallToSCN", "h225.routeCallToSCN",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PartyNumber", HFILL }},
{ &hf_h225_routeCallToSCN_item,
{ "PartyNumber", "h225.PartyNumber",
FT_UINT32, BASE_DEC, VALS(h225_PartyNumber_vals), 0,
NULL, HFILL }},
{ &hf_h225_exceedsCallCapacity,
{ "exceedsCallCapacity", "h225.exceedsCallCapacity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_collectDestination,
{ "collectDestination", "h225.collectDestination_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_collectPIN,
{ "collectPIN", "h225.collectPIN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_noRouteToDestination,
{ "noRouteToDestination", "h225.noRouteToDestination_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_unallocatedNumber,
{ "unallocatedNumber", "h225.unallocatedNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_answeredCall,
{ "answeredCall", "h225.answeredCall",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_usageInformation,
{ "usageInformation", "h225.usageInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"RasUsageInformation", HFILL }},
{ &hf_h225_bandwidthDetails,
{ "bandwidthDetails", "h225.bandwidthDetails",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_BandwidthDetails", HFILL }},
{ &hf_h225_bandwidthDetails_item,
{ "BandwidthDetails", "h225.BandwidthDetails_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_bandRejectReason,
{ "rejectReason", "h225.rejectReason",
FT_UINT32, BASE_DEC, VALS(BandRejectReason_vals), 0,
"BandRejectReason", HFILL }},
{ &hf_h225_allowedBandWidth,
{ "allowedBandWidth", "h225.allowedBandWidth",
FT_UINT32, BASE_DEC, NULL, 0,
"BandWidth", HFILL }},
{ &hf_h225_notBound,
{ "notBound", "h225.notBound_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_invalidConferenceID,
{ "invalidConferenceID", "h225.invalidConferenceID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_insufficientResources,
{ "insufficientResources", "h225.insufficientResources_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_replyAddress,
{ "replyAddress", "h225.replyAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_sourceInfo,
{ "sourceInfo", "h225.sourceInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_sourceInfo_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_hopCount,
{ "hopCount", "h225.hopCount",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_255", HFILL }},
{ &hf_h225_sourceEndpointInfo,
{ "sourceEndpointInfo", "h225.sourceEndpointInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h225_sourceEndpointInfo_item,
{ "AliasAddress", "h225.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h225_locationConfirm_callSignalAddress,
{ "callSignalAddress", "h225.callSignalAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_locationConfirm_rasAddress,
{ "rasAddress", "h225.rasAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_locationRejectReason,
{ "rejectReason", "h225.rejectReason",
FT_UINT32, BASE_DEC, VALS(LocationRejectReason_vals), 0,
"LocationRejectReason", HFILL }},
{ &hf_h225_notRegistered,
{ "notRegistered", "h225.notRegistered_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_routeCalltoSCN,
{ "routeCalltoSCN", "h225.routeCalltoSCN",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PartyNumber", HFILL }},
{ &hf_h225_routeCalltoSCN_item,
{ "PartyNumber", "h225.PartyNumber",
FT_UINT32, BASE_DEC, VALS(h225_PartyNumber_vals), 0,
NULL, HFILL }},
{ &hf_h225_disengageReason,
{ "disengageReason", "h225.disengageReason",
FT_UINT32, BASE_DEC, VALS(DisengageReason_vals), 0,
NULL, HFILL }},
{ &hf_h225_terminationCause,
{ "terminationCause", "h225.terminationCause",
FT_UINT32, BASE_DEC, VALS(h225_CallTerminationCause_vals), 0,
"CallTerminationCause", HFILL }},
{ &hf_h225_forcedDrop,
{ "forcedDrop", "h225.forcedDrop_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_normalDrop,
{ "normalDrop", "h225.normalDrop_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_disengageRejectReason,
{ "rejectReason", "h225.rejectReason",
FT_UINT32, BASE_DEC, VALS(DisengageRejectReason_vals), 0,
"DisengageRejectReason", HFILL }},
{ &hf_h225_requestToDropOther,
{ "requestToDropOther", "h225.requestToDropOther_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_usageInfoRequested,
{ "usageInfoRequested", "h225.usageInfoRequested_element",
FT_NONE, BASE_NONE, NULL, 0,
"RasUsageInfoTypes", HFILL }},
{ &hf_h225_segmentedResponseSupported,
{ "segmentedResponseSupported", "h225.segmentedResponseSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nextSegmentRequested,
{ "nextSegmentRequested", "h225.nextSegmentRequested",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h225_capacityInfoRequested,
{ "capacityInfoRequested", "h225.capacityInfoRequested_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_infoRequestResponse_rasAddress,
{ "rasAddress", "h225.rasAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h225_perCallInfo,
{ "perCallInfo", "h225.perCallInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_perCallInfo_item,
{ "perCallInfo item", "h225.perCallInfo_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_originator,
{ "originator", "h225.originator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_audio,
{ "audio", "h225.audio",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_RTPSession", HFILL }},
{ &hf_h225_audio_item,
{ "RTPSession", "h225.RTPSession_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_video,
{ "video", "h225.video",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_RTPSession", HFILL }},
{ &hf_h225_video_item,
{ "RTPSession", "h225.RTPSession_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_data,
{ "data", "h225.data",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TransportChannelInfo", HFILL }},
{ &hf_h225_data_item,
{ "TransportChannelInfo", "h225.TransportChannelInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h245,
{ "h245", "h225.h245_element",
FT_NONE, BASE_NONE, NULL, 0,
"TransportChannelInfo", HFILL }},
{ &hf_h225_callSignalling,
{ "callSignalling", "h225.callSignalling_element",
FT_NONE, BASE_NONE, NULL, 0,
"TransportChannelInfo", HFILL }},
{ &hf_h225_substituteConfIDs,
{ "substituteConfIDs", "h225.substituteConfIDs",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ConferenceIdentifier", HFILL }},
{ &hf_h225_substituteConfIDs_item,
{ "ConferenceIdentifier", "h225.ConferenceIdentifier",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_pdu,
{ "pdu", "h225.pdu",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h225_pdu_item,
{ "pdu item", "h225.pdu_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_h323pdu,
{ "h323pdu", "h225.h323pdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"H323_UU_PDU", HFILL }},
{ &hf_h225_sent,
{ "sent", "h225.sent",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_needResponse,
{ "needResponse", "h225.needResponse",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_irrStatus,
{ "irrStatus", "h225.irrStatus",
FT_UINT32, BASE_DEC, VALS(h225_InfoRequestResponseStatus_vals), 0,
"InfoRequestResponseStatus", HFILL }},
{ &hf_h225_unsolicited,
{ "unsolicited", "h225.unsolicited",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_complete,
{ "complete", "h225.complete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_incomplete,
{ "incomplete", "h225.incomplete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_segment,
{ "segment", "h225.segment",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h225_invalidCall,
{ "invalidCall", "h225.invalidCall_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_nakReason,
{ "nakReason", "h225.nakReason",
FT_UINT32, BASE_DEC, VALS(InfoRequestNakReason_vals), 0,
"InfoRequestNakReason", HFILL }},
{ &hf_h225_messageNotUnderstood,
{ "messageNotUnderstood", "h225.messageNotUnderstood",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h225_delay,
{ "delay", "h225.delay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_65535", HFILL }},
{ &hf_h225_protocols,
{ "protocols", "h225.protocols",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SupportedProtocols", HFILL }},
{ &hf_h225_protocols_item,
{ "SupportedProtocols", "h225.SupportedProtocols",
FT_UINT32, BASE_DEC, VALS(h225_SupportedProtocols_vals), 0,
NULL, HFILL }},
{ &hf_h225_almostOutOfResources,
{ "almostOutOfResources", "h225.almostOutOfResources",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h225_callSpecific,
{ "callSpecific", "h225.callSpecific_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_result,
{ "result", "h225.result",
FT_UINT32, BASE_DEC, VALS(h225_T_result_vals), 0,
NULL, HFILL }},
{ &hf_h225_started,
{ "started", "h225.started_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_failed,
{ "failed", "h225.failed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_stopped,
{ "stopped", "h225.stopped_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h225_notAvailable,
{ "notAvailable", "h225.notAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 232 "../../asn1/h225/packet-h225-template.c"
};
static gint *ett[] = {
&ett_h225,
#line 1 "../../asn1/h225/packet-h225-ettarr.c"
&ett_h225_H323_UserInformation,
&ett_h225_T_user_data,
&ett_h225_H323_UU_PDU,
&ett_h225_T_h323_message_body,
&ett_h225_T_h4501SupplementaryService,
&ett_h225_H245Control,
&ett_h225_SEQUENCE_OF_NonStandardParameter,
&ett_h225_T_tunnelledSignallingMessage,
&ett_h225_T_messageContent,
&ett_h225_SEQUENCE_OF_GenericData,
&ett_h225_StimulusControl,
&ett_h225_Alerting_UUIE,
&ett_h225_SEQUENCE_OF_ClearToken,
&ett_h225_SEQUENCE_OF_CryptoH323Token,
&ett_h225_SEQUENCE_OF_AliasAddress,
&ett_h225_SEQUENCE_OF_ServiceControlSession,
&ett_h225_SEQUENCE_OF_DisplayName,
&ett_h225_CallProceeding_UUIE,
&ett_h225_Connect_UUIE,
&ett_h225_Information_UUIE,
&ett_h225_ReleaseComplete_UUIE,
&ett_h225_ReleaseCompleteReason,
&ett_h225_Setup_UUIE,
&ett_h225_SEQUENCE_OF_CallReferenceValue,
&ett_h225_T_conferenceGoal,
&ett_h225_SEQUENCE_OF_H245Security,
&ett_h225_FastStart,
&ett_h225_T_connectionParameters,
&ett_h225_Language,
&ett_h225_SEQUENCE_OF_SupportedProtocols,
&ett_h225_SEQUENCE_OF_FeatureDescriptor,
&ett_h225_ParallelH245Control,
&ett_h225_SEQUENCE_OF_ExtendedAliasAddress,
&ett_h225_ScnConnectionType,
&ett_h225_ScnConnectionAggregation,
&ett_h225_PresentationIndicator,
&ett_h225_Facility_UUIE,
&ett_h225_SEQUENCE_OF_ConferenceList,
&ett_h225_ConferenceList,
&ett_h225_FacilityReason,
&ett_h225_Progress_UUIE,
&ett_h225_TransportAddress,
&ett_h225_H245TransportAddress,
&ett_h225_T_h245IpAddress,
&ett_h225_T_h245IpSourceRoute,
&ett_h225_T_h245Route,
&ett_h225_T_h245Routing,
&ett_h225_T_h245IpxAddress,
&ett_h225_T_h245Ip6Address,
&ett_h225_T_ipAddress,
&ett_h225_T_ipSourceRoute,
&ett_h225_T_route,
&ett_h225_T_routing,
&ett_h225_T_ipxAddress,
&ett_h225_T_ip6Address,
&ett_h225_Status_UUIE,
&ett_h225_StatusInquiry_UUIE,
&ett_h225_SetupAcknowledge_UUIE,
&ett_h225_Notify_UUIE,
&ett_h225_EndpointType,
&ett_h225_SEQUENCE_OF_TunnelledProtocol,
&ett_h225_GatewayInfo,
&ett_h225_SupportedProtocols,
&ett_h225_H310Caps,
&ett_h225_SEQUENCE_OF_DataRate,
&ett_h225_SEQUENCE_OF_SupportedPrefix,
&ett_h225_H320Caps,
&ett_h225_H321Caps,
&ett_h225_H322Caps,
&ett_h225_H323Caps,
&ett_h225_H324Caps,
&ett_h225_VoiceCaps,
&ett_h225_T120OnlyCaps,
&ett_h225_NonStandardProtocol,
&ett_h225_T38FaxAnnexbOnlyCaps,
&ett_h225_SIPCaps,
&ett_h225_McuInfo,
&ett_h225_TerminalInfo,
&ett_h225_GatekeeperInfo,
&ett_h225_VendorIdentifier,
&ett_h225_H221NonStandard,
&ett_h225_TunnelledProtocol,
&ett_h225_TunnelledProtocol_id,
&ett_h225_TunnelledProtocolAlternateIdentifier,
&ett_h225_NonStandardParameter,
&ett_h225_NonStandardIdentifier,
&ett_h225_AliasAddress,
&ett_h225_AddressPattern,
&ett_h225_T_range,
&ett_h225_PartyNumber,
&ett_h225_PublicPartyNumber,
&ett_h225_PrivatePartyNumber,
&ett_h225_DisplayName,
&ett_h225_PublicTypeOfNumber,
&ett_h225_PrivateTypeOfNumber,
&ett_h225_MobileUIM,
&ett_h225_ANSI_41_UIM,
&ett_h225_T_system_id,
&ett_h225_GSM_UIM,
&ett_h225_IsupNumber,
&ett_h225_IsupPublicPartyNumber,
&ett_h225_IsupPrivatePartyNumber,
&ett_h225_NatureOfAddress,
&ett_h225_ExtendedAliasAddress,
&ett_h225_Endpoint,
&ett_h225_SEQUENCE_OF_TransportAddress,
&ett_h225_AlternateTransportAddresses,
&ett_h225_UseSpecifiedTransport,
&ett_h225_AlternateGK,
&ett_h225_AltGKInfo,
&ett_h225_SEQUENCE_OF_AlternateGK,
&ett_h225_SecurityServiceMode,
&ett_h225_SecurityCapabilities,
&ett_h225_SecurityErrors,
&ett_h225_SecurityErrors2,
&ett_h225_H245Security,
&ett_h225_QseriesOptions,
&ett_h225_Q954Details,
&ett_h225_CallIdentifier,
&ett_h225_EncryptIntAlg,
&ett_h225_NonIsoIntegrityMechanism,
&ett_h225_IntegrityMechanism,
&ett_h225_ICV,
&ett_h225_CryptoH323Token,
&ett_h225_T_cryptoEPPwdHash,
&ett_h225_T_cryptoGKPwdHash,
&ett_h225_DataRate,
&ett_h225_CallLinkage,
&ett_h225_SupportedPrefix,
&ett_h225_CapacityReportingCapability,
&ett_h225_CapacityReportingSpecification,
&ett_h225_CapacityReportingSpecification_when,
&ett_h225_CallCapacity,
&ett_h225_CallCapacityInfo,
&ett_h225_SEQUENCE_OF_CallsAvailable,
&ett_h225_CallsAvailable,
&ett_h225_CircuitInfo,
&ett_h225_CircuitIdentifier,
&ett_h225_CicInfo,
&ett_h225_T_cic_2_4,
&ett_h225_GroupID,
&ett_h225_T_member,
&ett_h225_CarrierInfo,
&ett_h225_ServiceControlDescriptor,
&ett_h225_ServiceControlSession,
&ett_h225_ServiceControlSession_reason,
&ett_h225_RasUsageInfoTypes,
&ett_h225_RasUsageSpecification,
&ett_h225_RasUsageSpecification_when,
&ett_h225_RasUsageSpecificationcallStartingPoint,
&ett_h225_RasUsageInformation,
&ett_h225_CallTerminationCause,
&ett_h225_BandwidthDetails,
&ett_h225_CallCreditCapability,
&ett_h225_CallCreditServiceControl,
&ett_h225_T_billingMode,
&ett_h225_CallCreditServiceControl_callStartingPoint,
&ett_h225_GenericData,
&ett_h225_T_parameters,
&ett_h225_GenericIdentifier,
&ett_h225_EnumeratedParameter,
&ett_h225_Content,
&ett_h225_SEQUENCE_SIZE_1_512_OF_EnumeratedParameter,
&ett_h225_SEQUENCE_SIZE_1_16_OF_GenericData,
&ett_h225_FeatureSet,
&ett_h225_TransportChannelInfo,
&ett_h225_RTPSession,
&ett_h225_T_associatedSessionIds,
&ett_h225_RehomingModel,
&ett_h225_RasMessage,
&ett_h225_SEQUENCE_OF_AdmissionConfirm,
&ett_h225_GatekeeperRequest,
&ett_h225_SEQUENCE_OF_Endpoint,
&ett_h225_SEQUENCE_OF_AuthenticationMechanism,
&ett_h225_T_algorithmOIDs,
&ett_h225_SEQUENCE_OF_IntegrityMechanism,
&ett_h225_GatekeeperConfirm,
&ett_h225_GatekeeperReject,
&ett_h225_GatekeeperRejectReason,
&ett_h225_RegistrationRequest,
&ett_h225_SEQUENCE_OF_AddressPattern,
&ett_h225_SEQUENCE_OF_H248PackagesDescriptor,
&ett_h225_RegistrationConfirm,
&ett_h225_T_preGrantedARQ,
&ett_h225_SEQUENCE_OF_RasUsageSpecification,
&ett_h225_RegistrationReject,
&ett_h225_RegistrationRejectReason,
&ett_h225_T_invalidTerminalAliases,
&ett_h225_UnregistrationRequest,
&ett_h225_UnregRequestReason,
&ett_h225_UnregistrationConfirm,
&ett_h225_UnregistrationReject,
&ett_h225_UnregRejectReason,
&ett_h225_AdmissionRequest,
&ett_h225_DestinationInfo,
&ett_h225_CallType,
&ett_h225_CallModel,
&ett_h225_TransportQOS,
&ett_h225_SEQUENCE_SIZE_1_256_OF_QOSCapability,
&ett_h225_AdmissionConfirm,
&ett_h225_UUIEsRequested,
&ett_h225_AdmissionReject,
&ett_h225_AdmissionRejectReason,
&ett_h225_SEQUENCE_OF_PartyNumber,
&ett_h225_BandwidthRequest,
&ett_h225_SEQUENCE_OF_BandwidthDetails,
&ett_h225_BandwidthConfirm,
&ett_h225_BandwidthReject,
&ett_h225_BandRejectReason,
&ett_h225_LocationRequest,
&ett_h225_LocationConfirm,
&ett_h225_LocationReject,
&ett_h225_LocationRejectReason,
&ett_h225_DisengageRequest,
&ett_h225_DisengageReason,
&ett_h225_DisengageConfirm,
&ett_h225_DisengageReject,
&ett_h225_DisengageRejectReason,
&ett_h225_InfoRequest,
&ett_h225_InfoRequestResponse,
&ett_h225_T_perCallInfo,
&ett_h225_T_perCallInfo_item,
&ett_h225_SEQUENCE_OF_RTPSession,
&ett_h225_SEQUENCE_OF_TransportChannelInfo,
&ett_h225_SEQUENCE_OF_ConferenceIdentifier,
&ett_h225_T_pdu,
&ett_h225_T_pdu_item,
&ett_h225_InfoRequestResponseStatus,
&ett_h225_InfoRequestAck,
&ett_h225_InfoRequestNak,
&ett_h225_InfoRequestNakReason,
&ett_h225_NonStandardMessage,
&ett_h225_UnknownMessageResponse,
&ett_h225_RequestInProgress,
&ett_h225_ResourcesAvailableIndicate,
&ett_h225_ResourcesAvailableConfirm,
&ett_h225_ServiceControlIndication,
&ett_h225_T_callSpecific,
&ett_h225_ServiceControlResponse,
&ett_h225_T_result,
#line 238 "../../asn1/h225/packet-h225-template.c"
};
module_t *h225_module;
proto_h225 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h225, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
h225_module = prefs_register_protocol(proto_h225, proto_reg_handoff_h225);
prefs_register_uint_preference(h225_module, "tls.port",
"H.225 TLS Port",
"H.225 Server TLS Port",
10, &h225_tls_port);
prefs_register_bool_preference(h225_module, "reassembly",
"Reassemble H.225 messages spanning multiple TCP segments",
"Whether the H.225 dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&h225_reassembly);
prefs_register_bool_preference(h225_module, "h245_in_tree",
"Display tunnelled H.245 inside H.225.0 tree",
"ON - display tunnelled H.245 inside H.225.0 tree, OFF - display tunnelled H.245 in root tree after H.225.0",
&h225_h245_in_tree);
prefs_register_bool_preference(h225_module, "tp_in_tree",
"Display tunnelled protocols inside H.225.0 tree",
"ON - display tunnelled protocols inside H.225.0 tree, OFF - display tunnelled protocols in root tree after H.225.0",
&h225_tp_in_tree);
new_register_dissector("h225", dissect_h225_H323UserInformation, proto_h225);
new_register_dissector("h323ui",dissect_h225_H323UserInformation, proto_h225);
new_register_dissector("h225.ras", dissect_h225_h225_RasMessage, proto_h225);
nsp_object_dissector_table = register_dissector_table("h225.nsp.object", "H.225 NonStandardParameter (object)", FT_STRING, BASE_NONE);
nsp_h221_dissector_table = register_dissector_table("h225.nsp.h221", "H.225 NonStandardParameter (h221)", FT_UINT32, BASE_HEX);
tp_dissector_table = register_dissector_table("h225.tp", "H.225 TunnelledProtocol", FT_STRING, BASE_NONE);
gef_name_dissector_table = register_dissector_table("h225.gef.name", "H.225 Generic Extensible Framework (names)", FT_STRING, BASE_NONE);
gef_content_dissector_table = register_dissector_table("h225.gef.content", "H.225 Generic Extensible Framework", FT_STRING, BASE_NONE);
register_init_routine(&h225_init_routine);
h225_tap = register_tap("h225");
oid_add_from_string("Version 1","0.0.8.2250.0.1");
oid_add_from_string("Version 2","0.0.8.2250.0.2");
oid_add_from_string("Version 3","0.0.8.2250.0.3");
oid_add_from_string("Version 4","0.0.8.2250.0.4");
oid_add_from_string("Version 5","0.0.8.2250.0.5");
oid_add_from_string("Version 6","0.0.8.2250.0.6");
}
void
proto_reg_handoff_h225(void)
{
static gboolean h225_prefs_initialized = FALSE;
static dissector_handle_t h225ras_handle;
static guint saved_h225_tls_port;
if (!h225_prefs_initialized) {
h225ras_handle=find_dissector("h225.ras");
dissector_add_uint("udp.port", UDP_PORT_RAS1, h225ras_handle);
dissector_add_uint("udp.port", UDP_PORT_RAS2, h225ras_handle);
h245_handle = find_dissector("h245");
h245dg_handle = find_dissector("h245dg");
h4501_handle = find_dissector("h4501");
data_handle = find_dissector("data");
h225_prefs_initialized = TRUE;
} else {
ssl_dissector_delete(saved_h225_tls_port, "q931.tpkt", TRUE);
}
saved_h225_tls_port = h225_tls_port;
ssl_dissector_add(saved_h225_tls_port, "q931.tpkt", TRUE);
}
static void reset_h225_packet_info(h225_packet_info *pi)
{
if(pi == NULL) {
return;
}
pi->msg_type = H225_OTHERS;
pi->cs_type = H225_OTHER;
pi->msg_tag = -1;
pi->reason = -1;
pi->requestSeqNum = 0;
memset(&pi->guid,0,sizeof pi->guid);
pi->is_duplicate = FALSE;
pi->request_available = FALSE;
pi->is_faststart = FALSE;
pi->is_h245 = FALSE;
pi->is_h245Tunneling = FALSE;
pi->h245_address = 0;
pi->h245_port = 0;
pi->frame_label[0] = '\0';
pi->dialedDigits[0] = '\0';
pi->is_destinationInfo = FALSE;
}
static void ras_call_matching(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, h225_packet_info *pi)
{
proto_item *hidden_item;
conversation_t* conversation = NULL;
h225ras_call_info_key h225ras_call_key;
h225ras_call_t *h225ras_call = NULL;
nstime_t delta;
guint msg_category;
if(pi->msg_type == H225_RAS && pi->msg_tag < 21) {
msg_category = pi->msg_tag / 3;
if(pi->msg_tag % 3 == 0) {
conversation = find_or_create_conversation(pinfo);
h225ras_call_key.reqSeqNum = pi->requestSeqNum;
h225ras_call_key.conversation = conversation;
h225ras_call = find_h225ras_call(&h225ras_call_key ,msg_category);
if (h225ras_call != NULL) {
do {
if (pinfo->fd->num == h225ras_call->req_num) {
break;
}
if (h225ras_call->next_call == NULL) {
if ( (pinfo->fd->num > h225ras_call->rsp_num && h225ras_call->rsp_num != 0
&& pinfo->fd->abs_ts.secs > (h225ras_call->req_time.secs + THRESHOLD_REPEATED_RESPONDED_CALL) )
||(pinfo->fd->num > h225ras_call->req_num && h225ras_call->rsp_num == 0
&& pinfo->fd->abs_ts.secs > (h225ras_call->req_time.secs + THRESHOLD_REPEATED_NOT_RESPONDED_CALL) ) )
{
h225ras_call = append_h225ras_call(h225ras_call, pinfo, &pi->guid, msg_category);
} else {
pi->is_duplicate = TRUE;
hidden_item = proto_tree_add_uint(tree, hf_h225_ras_dup, tvb, 0,0, pi->requestSeqNum);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
break;
}
h225ras_call = h225ras_call->next_call;
} while (h225ras_call != NULL );
}
else {
h225ras_call = new_h225ras_call(&h225ras_call_key, pinfo, &pi->guid, msg_category);
}
if(h225ras_call && h225ras_call->rsp_num != 0){
proto_item *ti =
proto_tree_add_uint_format(tree, hf_h225_ras_rsp_frame, tvb, 0, 0, h225ras_call->rsp_num,
"The response to this request is in frame %u",
h225ras_call->rsp_num);
PROTO_ITEM_SET_GENERATED(ti);
}
}
else {
conversation = find_conversation(pinfo->fd->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation != NULL) {
h225ras_call_key.reqSeqNum = pi->requestSeqNum;
h225ras_call_key.conversation = conversation;
h225ras_call = find_h225ras_call(&h225ras_call_key ,msg_category);
if(h225ras_call) {
do {
if (pinfo->fd->num == h225ras_call->rsp_num) {
break;
}
if(h225ras_call->next_call == NULL) {
break;
}
h225ras_call = h225ras_call->next_call;
} while (h225ras_call != NULL) ;
if (!h225ras_call) {
return;
}
if (msg_category == 3 || msg_category == 5) {
pi->guid = h225ras_call->guid;
hidden_item = proto_tree_add_guid(tree, hf_h225_guid, tvb, 0, GUID_LEN, &pi->guid);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (h225ras_call->rsp_num == 0) {
h225ras_call->rsp_num = pinfo->fd->num;
}
else {
if (h225ras_call->rsp_num != pinfo->fd->num) {
pi->is_duplicate = TRUE;
hidden_item = proto_tree_add_uint(tree, hf_h225_ras_dup, tvb, 0,0, pi->requestSeqNum);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
if(h225ras_call->req_num != 0){
proto_item *ti;
h225ras_call->responded = TRUE;
pi->request_available = TRUE;
ti = proto_tree_add_uint_format(tree, hf_h225_ras_req_frame, tvb, 0, 0, h225ras_call->req_num,
"This is a response to a request in frame %u", h225ras_call->req_num);
PROTO_ITEM_SET_GENERATED(ti);
nstime_delta(&delta, &pinfo->fd->abs_ts, &h225ras_call->req_time);
pi->delta_time = delta;
ti = proto_tree_add_time(tree, hf_h225_ras_deltatime, tvb, 0, 0, &(pi->delta_time));
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
}
}
}
