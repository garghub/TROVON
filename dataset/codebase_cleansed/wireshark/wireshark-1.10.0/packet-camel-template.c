static char camel_number_to_char(int number)
{
if (number < 10)
return (char) (number + 48 );
else
return (char) (number + 55 );
}
static guint8
dissect_RP_cause_ie(tvbuff_t *tvb, guint32 offset, _U_ guint len,
proto_tree *tree, int hf_cause_value, guint8 *cause_value)
{
guint8 oct;
guint32 curr_offset;
static char a_bigbuf[1024];
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
*cause_value = oct & 0x7f;
other_decode_bitfield_value(a_bigbuf, oct, 0x7f, 8);
proto_tree_add_uint_format(tree, hf_cause_value,
tvb, curr_offset, 1, *cause_value,
"%s : %s",
a_bigbuf,
val_to_str(*cause_value, camel_RP_Cause_values,
"Unknown Cause (%u), treated as (41) \"Temporary failure\" for MO-SMS or (111) \"Protocol error,unspecified\" for MT-SMS"));
curr_offset++;
if ((oct & 0x80)) {
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint_format(tree, hf_cause_value,
tvb, curr_offset, 1, oct,
"Diagnostic : %u", oct);
curr_offset++;
}
return(curr_offset - offset);
}
static int
dissect_camel_camelPDU(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_,proto_tree *tree, int hf_index) {
char *version_ptr;
struct tcap_private_t * p_private_tcap;
opcode = 0;
application_context_version = 0;
if (actx->pinfo->private_data != NULL){
p_private_tcap=(struct tcap_private_t *)actx->pinfo->private_data;
if (p_private_tcap->acv==TRUE ){
version_ptr = strrchr((char *)p_private_tcap->oid,'.');
if (version_ptr)
application_context_version = atoi(version_ptr+1);
}
gp_camelsrt_info->tcap_context=p_private_tcap->context;
if (p_private_tcap->context)
gp_camelsrt_info->tcap_session_id = ( (struct tcaphash_context_t *) (p_private_tcap->context))->session_id;
}
camel_pdu_type = tvb_get_guint8(tvb, offset)&0x0f;
camel_pdu_size = tvb_get_guint8(tvb, offset+1)+2;
col_add_str(actx->pinfo->cinfo, COL_INFO, val_to_str(camel_pdu_type, camel_Component_vals, "Unknown Camel (%u)"));
col_append_str(actx->pinfo->cinfo, COL_INFO, " ");
is_ExtensionField =FALSE;
offset = dissect_camel_ROS(TRUE, tvb, offset, actx, tree, hf_index);
return offset;
}
static void
dissect_camel_v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Camel-v1");
camel_ver = 1;
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_camel, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_camel);
}
gp_camelsrt_info=camelsrt_razinfo();
dissect_camel_camelPDU(FALSE, tvb, 0, &asn1_ctx , tree, -1);
if (gcamel_HandleSRT &&
gp_camelsrt_info->tcap_context ) {
if (gcamel_DisplaySRT && tree) {
stat_item = proto_tree_add_text(tree, tvb, 0, 0, "Stat");
stat_tree = proto_item_add_subtree(stat_item, ett_camel_stat);
}
camelsrt_call_matching(tvb, pinfo, stat_tree, gp_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, gp_camelsrt_info);
}
}
static void
dissect_camel_v2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Camel-v2");
camel_ver = 2;
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_camel, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_camel);
}
gp_camelsrt_info=camelsrt_razinfo();
dissect_camel_camelPDU(FALSE, tvb, 0, &asn1_ctx , tree, -1);
if (gcamel_HandleSRT &&
gp_camelsrt_info->tcap_context ) {
if (gcamel_DisplaySRT && tree) {
stat_item = proto_tree_add_text(tree, tvb, 0, 0, "Stat");
stat_tree = proto_item_add_subtree(stat_item, ett_camel_stat);
}
camelsrt_call_matching(tvb, pinfo, stat_tree, gp_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, gp_camelsrt_info);
}
}
static void
dissect_camel(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Camel");
camel_ver = 0;
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_camel, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_camel);
}
gp_camelsrt_info=camelsrt_razinfo();
dissect_camel_camelPDU(FALSE, tvb, 0, &asn1_ctx , tree, -1);
if (gcamel_HandleSRT &&
gp_camelsrt_info->tcap_context ) {
if (gcamel_DisplaySRT && tree) {
stat_item = proto_tree_add_text(tree, tvb, 0, 0, "Stat");
stat_tree = proto_item_add_subtree(stat_item, ett_camel_stat);
}
camelsrt_call_matching(tvb, pinfo, stat_tree, gp_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, gp_camelsrt_info);
}
}
static void range_delete_callback(guint32 ssn)
{
if (ssn) {
delete_itu_tcap_subdissector(ssn, camel_handle);
}
}
static void range_add_callback(guint32 ssn)
{
if (ssn) {
add_itu_tcap_subdissector(ssn, camel_handle);
}
}
void proto_reg_handoff_camel(void) {
static gboolean camel_prefs_initialized = FALSE;
static range_t *ssn_range;
if (!camel_prefs_initialized) {
camel_prefs_initialized = TRUE;
camel_handle = find_dissector("camel");
camel_v1_handle = find_dissector("camel-v1");
camel_v2_handle = find_dissector("camel-v2");
register_ber_oid_dissector_handle("0.4.0.0.1.0.50.0",camel_v1_handle, proto_camel, "CAP-v1-gsmSSF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.50.1",camel_v2_handle, proto_camel, "CAP-v2-gsmSSF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.51.1",camel_v2_handle, proto_camel, "CAP-v2-assist-gsmSSF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.52.1",camel_v2_handle, proto_camel, "CAP-v2-gsmSRF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.21.3.50",camel_handle, proto_camel, "cap3-gprssf-scfAC" );
register_ber_oid_dissector_handle("0.4.0.0.1.21.3.51",camel_handle, proto_camel, "cap3-gsmscf-gprsssfAC" );
register_ber_oid_dissector_handle("0.4.0.0.1.21.3.61",camel_handle, proto_camel, "cap3-sms-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.23.3.4",camel_handle, proto_camel, "capssf-scfGenericAC" );
register_ber_oid_dissector_handle("0.4.0.0.1.23.3.61",camel_handle, proto_camel, "cap4-sms-AC" );
#include "packet-camel-dis-tab.c"
} else {
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
ssn_range = range_copy(global_ssn_range);
range_foreach(ssn_range, range_add_callback);
}
void proto_register_camel(void) {
module_t *camel_module;
static hf_register_info hf[] = {
{ &hf_camel_extension_code_local,
{ "local", "camel.extension_code_local",
FT_INT32, BASE_DEC, NULL, 0,
"Extension local code", HFILL }},
{ &hf_camel_error_code_local,
{ "local", "camel.error_code_local",
FT_INT32, BASE_DEC, VALS(camel_err_code_string_vals), 0,
"ERROR code", HFILL }},
{ &hf_camel_cause_indicator,
{ "Cause indicator", "camel.cause_indicator",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &q850_cause_code_vals_ext, 0x7f,
NULL, HFILL }},
{ &hf_digit,
{ "Digit Value", "camel.digit_value",
FT_UINT8, BASE_DEC, VALS(digit_value), 0, NULL, HFILL }},
{ &hf_camel_PDPTypeNumber_etsi,
{ "ETSI defined PDP Type Value", "camel.PDPTypeNumber_etsi",
FT_UINT8, BASE_HEX, VALS(gsm_map_etsi_defined_pdp_vals), 0,
NULL, HFILL }},
{ &hf_camel_PDPTypeNumber_ietf,
{ "IETF defined PDP Type Value", "camel.PDPTypeNumber_ietf",
FT_UINT8, BASE_HEX, VALS(gsm_map_ietf_defined_pdp_vals), 0,
NULL, HFILL }},
{ &hf_camel_PDPAddress_IPv4,
{ "PDPAddress IPv4", "camel.PDPAddress_IPv4",
FT_IPv4, BASE_NONE, NULL, 0,
"IPAddress IPv4", HFILL }},
{ &hf_camel_PDPAddress_IPv6,
{ "PDPAddress IPv6", "camel.PDPAddress_IPv6",
FT_IPv6, BASE_NONE, NULL, 0,
"IPAddress IPv6", HFILL }},
{ &hf_camel_cellGlobalIdOrServiceAreaIdFixedLength,
{ "CellGlobalIdOrServiceAreaIdFixedLength", "camel.CellGlobalIdOrServiceAreaIdFixedLength",
FT_BYTES, BASE_NONE, NULL, 0,
"LocationInformationGPRS/CellGlobalIdOrServiceAreaIdOrLAI", HFILL }},
{ &hf_camel_RP_Cause,
{ "RP Cause", "camel.RP_Cause",
FT_UINT8, BASE_DEC, NULL, 0,
"RP Cause Value", HFILL }},
{ &hf_camel_CAMEL_AChBillingChargingCharacteristics,
{ "CAMEL-AChBillingChargingCharacteristics", "camel.CAMEL_AChBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_AChBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_FCIBillingChargingCharacteristics,
{ "CAMEL-FCIBillingChargingCharacteristics", "camel.CAMEL_FCIBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_FCIBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_FCIGPRSBillingChargingCharacteristics,
{ "CAMEL-FCIGPRSBillingChargingCharacteristics", "camel.CAMEL_FCIGPRSBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_FCISMSBillingChargingCharacteristics,
{ "CAMEL-FCISMSBillingChargingCharacteristics", "camel.CAMEL_FCISMSBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_FCISMSBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_SCIBillingChargingCharacteristics,
{ "CAMEL-SCIBillingChargingCharacteristics", "camel.CAMEL_SCIBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_SCIBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_SCIGPRSBillingChargingCharacteristics,
{ "CAMEL-SCIGPRSBillingChargingCharacteristics", "camel.CAMEL_SCIGPRSBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, NULL, 0,
"CAMEL-FSCIGPRSBillingChargingCharacteristics", HFILL }},
{ &hf_camel_CAMEL_CallResult,
{ "CAMEL-CAMEL_CallResult", "camel.CAMEL_CallResult",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_CallResult_vals), 0,
"CAMEL-CallResult", HFILL }},
{ &hf_camelsrt_SessionId,
{ "Session Id",
"camel.srt.session_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_camelsrt_RequestNumber,
{ "Request Number",
"camel.srt.request_number",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_camelsrt_Duplicate,
{ "Request Duplicate",
"camel.srt.duplicate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_camelsrt_RequestFrame,
{ "Requested Frame",
"camel.srt.reqframe",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Request Frame", HFILL }
},
{ &hf_camelsrt_ResponseFrame,
{ "Response Frame",
"camel.srt.rspframe",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Response Frame", HFILL }
},
{ &hf_camelsrt_DeltaTime,
{ "Service Response Time",
"camel.srt.deltatime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between Request and Response", HFILL }
},
{ &hf_camelsrt_SessionTime,
{ "Session duration",
"camel.srt.sessiontime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Duration of the TCAP session", HFILL }
},
{ &hf_camelsrt_DeltaTime31,
{ "Service Response Time",
"camel.srt.deltatime31",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between InitialDP and Continue", HFILL }
},
{ &hf_camelsrt_DeltaTime65,
{ "Service Response Time",
"camel.srt.deltatime65",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between InitialDPSMS and ContinueSMS", HFILL }
},
{ &hf_camelsrt_DeltaTime75,
{ "Service Response Time",
"camel.srt.deltatime75",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between InitialDPGPRS and ContinueGPRS", HFILL }
},
{ &hf_camelsrt_DeltaTime35,
{ "Service Response Time",
"camel.srt.deltatime35",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between ApplyCharginReport and ApplyCharging", HFILL }
},
{ &hf_camelsrt_DeltaTime22,
{ "Service Response Time",
"camel.srt.deltatime22",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between EventReport(Disconnect) and Release Call", HFILL }
},
{ &hf_camelsrt_DeltaTime80,
{ "Service Response Time",
"camel.srt.deltatime80",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between EventReportGPRS and ContinueGPRS", HFILL }
},
#ifdef REMOVED
#endif
#include "packet-camel-hfarr.c"
};
static gint *ett[] = {
&ett_camel,
&ett_camelisup_parameter,
&ett_camel_AccessPointName,
&ett_camel_pdptypenumber,
&ett_camel_cause,
&ett_camel_RPcause,
&ett_camel_stat,
&ett_camel_calledpartybcdnumber,
&ett_camel_callingpartynumber,
&ett_camel_locationnumber,
#include "packet-camel-ettarr.c"
};
proto_camel = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("camel", dissect_camel, proto_camel);
register_dissector("camel-v1", dissect_camel_v1, proto_camel);
register_dissector("camel-v2", dissect_camel_v2, proto_camel);
proto_register_field_array(proto_camel, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
rose_ctx_init(&camel_rose_ctx);
camel_rose_ctx.arg_local_dissector_table = register_dissector_table("camel.ros.local.arg",
"CAMEL Operation Argument (local opcode)",
FT_UINT32, BASE_HEX);
camel_rose_ctx.res_local_dissector_table = register_dissector_table("camel.ros.local.res",
"CAMEL Operation Result (local opcode)",
FT_UINT32, BASE_HEX);
camel_rose_ctx.err_local_dissector_table = register_dissector_table("camel.ros.local.err",
"CAMEL Error (local opcode)",
FT_UINT32, BASE_HEX);
range_convert_str(&global_ssn_range, "146", MAX_SSN);
camel_module = prefs_register_protocol(proto_camel, proto_reg_handoff_camel);
prefs_register_enum_preference(camel_module, "date.format", "Date Format",
"The date format: (DD/MM) or (MM/DD)",
&date_format, date_options, FALSE);
prefs_register_range_preference(camel_module, "tcap.ssn",
"TCAP SSNs",
"TCAP Subsystem numbers used for Camel",
&global_ssn_range, MAX_SSN);
prefs_register_bool_preference(camel_module, "srt",
"Service Response Time Analyse",
"Activate the analyse for Response Time",
&gcamel_HandleSRT);
prefs_register_bool_preference(camel_module, "persistentsrt",
"Persistent stats for SRT",
"Statistics for Response Time",
&gcamel_PersistentSRT);
register_init_routine(&camelsrt_init_routine);
camel_tap=register_tap(PSNAME);
}
