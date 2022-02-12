static int
dissect_atn_cm_AircraftFlightIdentification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
2, 8, FALSE);
return offset;
}
static int
dissect_atn_cm_OCTET_STRING_SIZE_5(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
5, 5, FALSE, NULL);
return offset;
}
static int
dissect_atn_cm_OCTET_STRING_SIZE_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_atn_cm_OCTET_STRING_SIZE_10_11(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
10, 11, FALSE, NULL);
return offset;
}
static int
dissect_atn_cm_ShortTsap(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cm_ShortTsap, ShortTsap_sequence);
return offset;
}
static int
dissect_atn_cm_LongTsap(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cm_LongTsap, LongTsap_sequence);
return offset;
}
static int
dissect_atn_cm_AEQualifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cm_VersionNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cm_APAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cm_APAddress, APAddress_choice,
NULL);
return offset;
}
static int
dissect_atn_cm_AEQualifierVersionAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cm_AEQualifierVersionAddress, AEQualifierVersionAddress_sequence);
return offset;
}
static int
dissect_atn_cm_SEQUENCE_SIZE_1_256_OF_AEQualifierVersionAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cm_SEQUENCE_SIZE_1_256_OF_AEQualifierVersionAddress, SEQUENCE_SIZE_1_256_OF_AEQualifierVersionAddress_sequence_of,
1, 256, FALSE);
return offset;
}
static int
dissect_atn_cm_AEQualifierVersion(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cm_AEQualifierVersion, AEQualifierVersion_sequence);
return offset;
}
static int
dissect_atn_cm_SEQUENCE_SIZE_1_256_OF_AEQualifierVersion(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cm_SEQUENCE_SIZE_1_256_OF_AEQualifierVersion, SEQUENCE_SIZE_1_256_OF_AEQualifierVersion_sequence_of,
1, 256, FALSE);
return offset;
}
static int
dissect_atn_cm_FacilityDesignation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
4, 8, FALSE);
return offset;
}
static int
dissect_atn_cm_Airport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
4, 4, FALSE);
return offset;
}
static int
dissect_atn_cm_Year(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1996U, 2095U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cm_Month(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 12U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cm_Day(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cm_Date(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cm_Date, Date_sequence);
return offset;
}
static int
dissect_atn_cm_Timehours(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 23U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cm_Timeminutes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 59U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cm_Time(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cm_Time, Time_sequence);
return offset;
}
static int
dissect_atn_cm_DateTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cm_DateTime, DateTime_sequence);
return offset;
}
static int
dissect_atn_cm_CMLogonRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cm_CMLogonRequest, CMLogonRequest_sequence);
return offset;
}
static int
dissect_atn_cm_Response(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cm_CMContactResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_atn_cm_Response(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_atn_cm_CMAbortReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
10, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cm_CMAircraftMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cm_CMAircraftMessage, CMAircraftMessage_choice,
NULL);
return offset;
}
static int
dissect_atn_cm_CMLogonResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cm_CMLogonResponse, CMLogonResponse_sequence);
return offset;
}
static int
dissect_atn_cm_CMUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_atn_cm_CMLogonResponse(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_atn_cm_CMContactRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cm_CMContactRequest, CMContactRequest_sequence);
return offset;
}
static int
dissect_atn_cm_CMForwardRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_atn_cm_CMLogonRequest(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_atn_cm_CMForwardResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cm_CMGroundMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cm_CMGroundMessage, CMGroundMessage_choice,
NULL);
return offset;
}
static void dissect_CMAircraftMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_atn_cm_CMAircraftMessage(tvb, 0, &asn1_ctx, tree, hf_atn_cm_CMAircraftMessage_PDU);
}
static void dissect_CMGroundMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_atn_cm_CMGroundMessage(tvb, 0, &asn1_ctx, tree, hf_atn_cm_CMGroundMessage_PDU);
}
static int
dissect_atn_cm(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
int type;
proto_tree *sub_tree;
sub_tree = proto_tree_add_subtree(
tree, tvb, 0, -1, ett_atn_cm, NULL, ATN_CM_PROTO);
type = check_heur_msg_type(pinfo);
switch(type){
case um:
dissect_CMGroundMessage_PDU(
tvb,
pinfo,
sub_tree);
break;
case dm:
dissect_CMAircraftMessage_PDU(
tvb,
pinfo,
sub_tree);
break;
default:
break;
}
return tvb_reported_length_remaining(tvb, 0);
}
static gboolean
dissect_atn_cm_heur(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
atn_conversation_t *atn_cv = NULL;
volatile gboolean is_atn_cm = FALSE;
int type;
type = check_heur_msg_type(pinfo);
switch(type){
case um:
TRY {
dissect_CMGroundMessage_PDU(
tvb,
pinfo,
NULL);
is_atn_cm = TRUE; }
CATCH_ALL {
is_atn_cm = FALSE; }
ENDTRY;
break;
case dm:
TRY {
dissect_CMAircraftMessage_PDU(
tvb,
pinfo,
NULL);
is_atn_cm = TRUE;}
CATCH_ALL {
is_atn_cm = FALSE; }
ENDTRY;
break;
default:
break;
}
if (is_atn_cm == TRUE) {
if((pinfo->clnp_dstref) &&
(!pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src );
}
if((!pinfo->clnp_dstref) &&
(pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if((pinfo->clnp_dstref) &&
(pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if(atn_cv){
atn_cv->ae_qualifier = cma;
}
dissect_atn_cm(
tvb,
pinfo,
tree,
NULL);
}
return is_atn_cm;
}
void proto_register_atn_cm (void)
{
static hf_register_info hf_atn_cm[] = {
#line 1 "../../asn1/atn-cm/packet-atn-cm-hfarr.c"
{ &hf_atn_cm_CMAircraftMessage_PDU,
{ "CMAircraftMessage", "atn-cm.CMAircraftMessage",
FT_UINT32, BASE_DEC, VALS(atn_cm_CMAircraftMessage_vals), 0,
NULL, HFILL }},
{ &hf_atn_cm_CMGroundMessage_PDU,
{ "CMGroundMessage", "atn-cm.CMGroundMessage",
FT_UINT32, BASE_DEC, VALS(atn_cm_CMGroundMessage_vals), 0,
NULL, HFILL }},
{ &hf_atn_cm_cmLogonRequest,
{ "cmLogonRequest", "atn-cm.cmLogonRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_cmContactResponse,
{ "cmContactResponse", "atn-cm.cmContactResponse",
FT_UINT32, BASE_DEC, VALS(atn_cm_Response_vals), 0,
NULL, HFILL }},
{ &hf_atn_cm_cmAbortReason,
{ "cmAbortReason", "atn-cm.cmAbortReason",
FT_UINT32, BASE_DEC, VALS(atn_cm_CMAbortReason_vals), 0,
NULL, HFILL }},
{ &hf_atn_cm_cmLogonResponse,
{ "cmLogonResponse", "atn-cm.cmLogonResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_cmUpdate,
{ "cmUpdate", "atn-cm.cmUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_cmContactRequest,
{ "cmContactRequest", "atn-cm.cmContactRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_cmForwardRequest,
{ "cmForwardRequest", "atn-cm.cmForwardRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_cmForwardResponse,
{ "cmForwardResponse", "atn-cm.cmForwardResponse",
FT_UINT32, BASE_DEC, VALS(atn_cm_CMForwardResponse_vals), 0,
NULL, HFILL }},
{ &hf_atn_cm_longTsap,
{ "longTsap", "atn-cm.longTsap_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_shortTsap,
{ "shortTsap", "atn-cm.shortTsap_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_aeQualifier,
{ "aeQualifier", "atn-cm.aeQualifier",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_apVersion,
{ "apVersion", "atn-cm.apVersion",
FT_UINT32, BASE_DEC, NULL, 0,
"VersionNumber", HFILL }},
{ &hf_atn_cm_apAddress,
{ "apAddress", "atn-cm.apAddress",
FT_UINT32, BASE_DEC, VALS(atn_cm_APAddress_vals), 0,
NULL, HFILL }},
{ &hf_atn_cm_facilityDesignation,
{ "facilityDesignation", "atn-cm.facilityDesignation",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_address,
{ "address", "atn-cm.address_element",
FT_NONE, BASE_NONE, NULL, 0,
"LongTsap", HFILL }},
{ &hf_atn_cm_aircraftFlightIdentification,
{ "aircraftFlightIdentification", "atn-cm.aircraftFlightIdentification",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_cMLongTSAP,
{ "cMLongTSAP", "atn-cm.cMLongTSAP_element",
FT_NONE, BASE_NONE, NULL, 0,
"LongTsap", HFILL }},
{ &hf_atn_cm_groundInitiatedApplications,
{ "groundInitiatedApplications", "atn-cm.groundInitiatedApplications",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_256_OF_AEQualifierVersionAddress", HFILL }},
{ &hf_atn_cm_groundInitiatedApplications_item,
{ "AEQualifierVersionAddress", "atn-cm.AEQualifierVersionAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_airOnlyInitiatedApplications,
{ "airOnlyInitiatedApplications", "atn-cm.airOnlyInitiatedApplications",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_256_OF_AEQualifierVersion", HFILL }},
{ &hf_atn_cm_airOnlyInitiatedApplications_item,
{ "AEQualifierVersion", "atn-cm.AEQualifierVersion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_airportDeparture,
{ "airportDeparture", "atn-cm.airportDeparture",
FT_STRING, BASE_NONE, NULL, 0,
"Airport", HFILL }},
{ &hf_atn_cm_airportDestination,
{ "airportDestination", "atn-cm.airportDestination",
FT_STRING, BASE_NONE, NULL, 0,
"Airport", HFILL }},
{ &hf_atn_cm_dateTimeDepartureETD,
{ "dateTimeDepartureETD", "atn-cm.dateTimeDepartureETD_element",
FT_NONE, BASE_NONE, NULL, 0,
"DateTime", HFILL }},
{ &hf_atn_cm_airInitiatedApplications,
{ "airInitiatedApplications", "atn-cm.airInitiatedApplications",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_256_OF_AEQualifierVersionAddress", HFILL }},
{ &hf_atn_cm_airInitiatedApplications_item,
{ "AEQualifierVersionAddress", "atn-cm.AEQualifierVersionAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_groundOnlyInitiatedApplications,
{ "groundOnlyInitiatedApplications", "atn-cm.groundOnlyInitiatedApplications",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_256_OF_AEQualifierVersion", HFILL }},
{ &hf_atn_cm_groundOnlyInitiatedApplications_item,
{ "AEQualifierVersion", "atn-cm.AEQualifierVersion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_year,
{ "year", "atn-cm.year",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_month,
{ "month", "atn-cm.month",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_day,
{ "day", "atn-cm.day",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_date,
{ "date", "atn-cm.date_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_time,
{ "time", "atn-cm.time_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cm_rDP,
{ "rDP", "atn-cm.rDP",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_5", HFILL }},
{ &hf_atn_cm_aRS,
{ "aRS", "atn-cm.aRS",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_atn_cm_locSysNselTsel,
{ "locSysNselTsel", "atn-cm.locSysNselTsel",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_10_11", HFILL }},
{ &hf_atn_cm_hours,
{ "hours", "atn-cm.hours",
FT_UINT32, BASE_DEC, NULL, 0,
"Timehours", HFILL }},
{ &hf_atn_cm_minutes,
{ "minutes", "atn-cm.minutes",
FT_UINT32, BASE_DEC, NULL, 0,
"Timeminutes", HFILL }},
#line 203 "../../asn1/atn-cm/packet-atn-cm-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/atn-cm/packet-atn-cm-ettarr.c"
&ett_atn_cm_CMAircraftMessage,
&ett_atn_cm_CMGroundMessage,
&ett_atn_cm_APAddress,
&ett_atn_cm_AEQualifierVersion,
&ett_atn_cm_AEQualifierVersionAddress,
&ett_atn_cm_CMContactRequest,
&ett_atn_cm_CMLogonRequest,
&ett_atn_cm_SEQUENCE_SIZE_1_256_OF_AEQualifierVersionAddress,
&ett_atn_cm_SEQUENCE_SIZE_1_256_OF_AEQualifierVersion,
&ett_atn_cm_CMLogonResponse,
&ett_atn_cm_Date,
&ett_atn_cm_DateTime,
&ett_atn_cm_LongTsap,
&ett_atn_cm_ShortTsap,
&ett_atn_cm_Time,
#line 206 "../../asn1/atn-cm/packet-atn-cm-template.c"
&ett_atn_cm
};
proto_atn_cm = proto_register_protocol(
ATN_CM_PROTO ,
"ATN-CM",
"atn-cm");
proto_register_field_array(
proto_atn_cm,
hf_atn_cm,
array_length(hf_atn_cm));
proto_register_subtree_array(
ett,
array_length(ett));
new_register_dissector(
"atn-cm",
dissect_atn_cm,
proto_atn_cm);
}
void proto_reg_handoff_atn_cm(void)
{
heur_dissector_add(
"atn-ulcs",
dissect_atn_cm_heur,
proto_atn_cm);
}
