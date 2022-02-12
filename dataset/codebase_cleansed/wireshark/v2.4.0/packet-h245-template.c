void h245_set_h223_set_mc_handle( h223_set_mc_handle_t handle )
{
h223_set_mc_handle = handle;
}
static void h223_lc_init( void )
{
h223_lc_params_temp = NULL;
h245_lc_dissector = NULL;
h223_fw_lc_num = 0;
}
void h245_set_h223_add_lc_handle( h223_add_lc_handle_t handle )
{
h223_add_lc_handle = handle;
}
static const gchar *gen_olc_key(guint16 lc_num, address *dst_addr, address *src_addr)
{
return wmem_strdup_printf(wmem_packet_scope(), "%s/%s/%u",
address_to_str(wmem_packet_scope(), dst_addr),
address_to_str(wmem_packet_scope(), src_addr),
lc_num);
}
static void update_unicast_addr(unicast_addr_t *req_addr, unicast_addr_t *ack_addr)
{
if (ack_addr->addr.type!=AT_NONE && ack_addr->port!=0) {
memcpy(req_addr->addr_buf, ack_addr->addr_buf, sizeof(req_addr->addr_buf));
set_address(&req_addr->addr, ack_addr->addr.type, ack_addr->addr.len, req_addr->addr_buf);
req_addr->port = ack_addr->port;
}
}
static void h245_setup_channels(packet_info *pinfo, channel_info_t *upcoming_channel_lcl)
{
rtp_dyn_payload_t *rtp_dyn_payload = NULL;
struct srtp_info *dummy_srtp_info = NULL;
if (!upcoming_channel_lcl) return;
if (!strcmp(upcoming_channel_lcl->data_type_str, "t38fax")) {
if (upcoming_channel_lcl->media_addr.addr.type!=AT_NONE && upcoming_channel_lcl->media_addr.port!=0) {
t38_add_address(pinfo, &upcoming_channel_lcl->media_addr.addr,
upcoming_channel_lcl->media_addr.port, 0,
"H245", pinfo->num);
}
return;
}
if (upcoming_channel_lcl->rfc2198 > 0) {
rtp_dyn_payload = rtp_dyn_payload_new();
rtp_dyn_payload_insert(rtp_dyn_payload, upcoming_channel_lcl->rfc2198, "red", 8000);
}
if (upcoming_channel_lcl->srtp_flag) {
dummy_srtp_info = wmem_new0(wmem_file_scope(), struct srtp_info);
}
if (upcoming_channel_lcl->media_addr.addr.type!=AT_NONE && upcoming_channel_lcl->media_addr.port!=0) {
srtp_add_address(pinfo, PT_UDP, &upcoming_channel_lcl->media_addr.addr,
upcoming_channel_lcl->media_addr.port, 0,
"H245", pinfo->num, upcoming_channel_lcl->is_video , rtp_dyn_payload, dummy_srtp_info);
}
if (upcoming_channel_lcl->media_control_addr.addr.type!=AT_NONE && upcoming_channel_lcl->media_control_addr.port!=0 && rtcp_handle) {
srtcp_add_address(pinfo, &upcoming_channel_lcl->media_control_addr.addr,
upcoming_channel_lcl->media_control_addr.port, 0,
"H245", pinfo->num, dummy_srtp_info);
}
}
static void print_info_column(column_info *cinfo, const gint32 *value,
const value_string *msg_vals, const value_string *short_msg_vals)
{
const value_string *vals;
if (h245_shorttypes == FALSE || short_msg_vals == NULL) {
vals = msg_vals;
} else {
vals = short_msg_vals;
}
if (info_col_fmt_prepend == FALSE) {
col_append_fstr(cinfo, COL_INFO, "%s ", val_to_str(*value, vals, "<unknown>"));
} else {
col_prepend_fstr(cinfo, COL_INFO, "%s ", val_to_str(*value, vals, "<unknown>"));
}
}
static void reset_h245_pi(void *dummy _U_)
{
h245_pi = NULL;
}
static int
dissect_h245(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
dissect_tpkt_encap(tvb, pinfo, parent_tree, h245_reassembly, MultimediaSystemControlMessage_handle);
return tvb_captured_length(tvb);
}
static int
dissect_h245_h245(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_item *it;
proto_tree *tr;
guint32 offset=0;
asn1_ctx_t asn1_ctx;
fast_start = FALSE;
upcoming_olc = NULL;
upcoming_channel = NULL;
codec_type = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
it=proto_tree_add_protocol_format(parent_tree, proto_h245, tvb, 0, -1, PSNAME);
tr=proto_item_add_subtree(it, ett_h245);
while ( tvb_reported_length_remaining( tvb, offset>>3 )>0 ){
CLEANUP_PUSH(reset_h245_pi, NULL);
h245_pi=wmem_new(wmem_packet_scope(), h245_packet_info);
init_h245_packet_info(h245_pi);
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h245_MultimediaSystemControlMessage(tvb, offset, &asn1_ctx, tr, hf_h245_pdu_type);
tap_queue_packet(h245dg_tap, pinfo, h245_pi);
offset = (offset+0x07) & 0xfffffff8;
CLEANUP_CALL_AND_POP;
}
return tvb_captured_length(tvb);
}
void
dissect_h245_FastStart_OLC(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, char *codec_str) {
fast_start = TRUE;
upcoming_olc = NULL;
upcoming_channel = NULL;
codec_type = NULL;
dissect_OpenLogicalChannel_PDU(tvb, pinfo, tree, NULL);
if (h245_pi != NULL)
h245_pi->msg_type = H245_OpenLogChn;
if (codec_str && codec_type){
g_strlcpy(codec_str, codec_type, 50);
}
}
void proto_register_h245(void) {
static hf_register_info hf[] = {
{ &hf_h245_pdu_type,
{ "PDU Type", "h245.pdu_type", FT_UINT32, BASE_DEC,
VALS(h245_MultimediaSystemControlMessage_vals), 0, "Type of H.245 PDU", HFILL }},
{ &hf_h245Manufacturer,
{ "H.245 Manufacturer", "h245.Manufacturer", FT_UINT32, BASE_HEX,
VALS(H221ManufacturerCode_vals), 0, "h245.H.221 Manufacturer", HFILL }},
{ &hf_h245_subMessageIdentifier_standard,
{ "subMessageIdentifier", "h245.subMessageIdentifier.standard",
FT_UINT32, BASE_DEC, VALS(h245_h239subMessageIdentifier_vals), 0,
NULL, HFILL }},
{ &hf_h245_debug_dissector_try_string,
{ "*** DEBUG dissector_try_string", "h245.debug.dissector_try_string", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
#include "packet-h245-hfarr.c"
};
static gint *ett[] = {
&ett_h245,
&ett_h245_returnedFunction,
#include "packet-h245-ettarr.c"
};
module_t *h245_module;
proto_h245 = proto_register_protocol(PNAME, PSNAME, PFNAME);
h223_pending_olc_reqs[P2P_DIR_SENT] = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), g_direct_hash, g_direct_equal );
h223_pending_olc_reqs[P2P_DIR_RECV] = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), g_direct_hash, g_direct_equal );
h245_pending_olc_reqs = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), wmem_str_hash, g_str_equal);
register_init_routine(h223_lc_init);
proto_register_field_array(proto_h245, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
h245_module = prefs_register_protocol(proto_h245, NULL);
prefs_register_bool_preference(h245_module, "reassembly",
"Reassemble H.245 messages spanning multiple TCP segments",
"Whether the H.245 dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&h245_reassembly);
prefs_register_bool_preference(h245_module, "shorttypes",
"Show short message types",
"Whether the dissector should show short names or the long names from the standard",
&h245_shorttypes);
prefs_register_bool_preference(h245_module, "prepand",
"Show h245 info in reversed order",
"Whether the dissector should print items of h245 Info column in reversed order",
&info_col_fmt_prepend);
MultimediaSystemControlMessage_handle = register_dissector("h245dg", dissect_h245_h245, proto_h245);
h245_handle = register_dissector("h245", dissect_h245, proto_h245);
nsp_object_dissector_table = register_dissector_table("h245.nsp.object", "H.245 NonStandardParameter (object)", proto_h245, FT_STRING, BASE_NONE);
nsp_h221_dissector_table = register_dissector_table("h245.nsp.h221", "H.245 NonStandardParameter (h221)", proto_h245, FT_UINT32, BASE_HEX);
gef_name_dissector_table = register_dissector_table("h245.gef.name", "H.245 Generic Extensible Framework Name", proto_h245, FT_STRING, BASE_NONE);
gef_content_dissector_table = register_dissector_table("h245.gef.content", "H.245 Generic Extensible Framework Content", proto_h245, FT_STRING, BASE_NONE);
h245_tap = register_tap("h245");
h245dg_tap = register_tap("h245dg");
oid_add_from_string("h239ControlCapability","0.0.8.239.1.1");
oid_add_from_string("h239ExtendedVideoCapability","0.0.8.239.1.2");
oid_add_from_string("generic-message","0.0.8.239.2");
oid_add_from_string("h245 version 3","0.0.8.245.0.3");
oid_add_from_string("h245 version 4","0.0.8.245.0.4");
oid_add_from_string("h245 version 5","0.0.8.245.0.5");
oid_add_from_string("h245 version 6","0.0.8.245.0.6");
oid_add_from_string("h245 version 7","0.0.8.245.0.7");
oid_add_from_string("h245 version 8","0.0.8.245.0.8");
oid_add_from_string("h245 version 9","0.0.8.245.0.9");
oid_add_from_string("h245 version 10","0.0.8.245.0.10");
oid_add_from_string("h245 version 11","0.0.8.245.0.11");
oid_add_from_string("h245 version 12","0.0.8.245.0.12");
oid_add_from_string("h245 version 13","0.0.8.245.0.13");
oid_add_from_string("ISO/IEC 14496-2 MPEG-4 video","0.0.8.245.1.0.0");
oid_add_from_string("ISO/IEC 14496-3 MPEG-4 audio","0.0.8.245.1.1.0");
oid_add_from_string("AMR","0.0.8.245.1.1.1");
oid_add_from_string("acelp","0.0.8.245.1.1.2");
oid_add_from_string("us1","0.0.8.245.1.1.3");
oid_add_from_string("is127evrc","0.0.8.245.1.1.4");
oid_add_from_string("ISO/IEC 13818-7","0.0.8.245.1.1.5");
oid_add_from_string("rfc3389","0.0.8.245.1.1.6");
oid_add_from_string("L-16","0.0.8.245.1.1.7");
oid_add_from_string("bounded-audio-stream","0.0.8.245.1.1.8");
oid_add_from_string("AMR-NB","0.0.8.245.1.1.9");
oid_add_from_string("AMR-WB","0.0.8.245.1.1.10");
oid_add_from_string("ilbc","0.0.8.245.1.1.11");
oid_add_from_string("ISO/IEC 14496-1","0.0.8.245.1.2.0");
oid_add_from_string("Nx64","0.0.8.245.1.2.1");
oid_add_from_string("logical-channel-bit-ratemanagement","0.0.8.245.1.3.0");
oid_add_from_string("h264 generic-capabilities","0.0.8.241.0.0.1");
oid_add_from_string("iPpacketization_h241AnnexA(single NAL unit mode)","0.0.8.241.0.0.0.0");
oid_add_from_string("iPpacketization_RFC3984NonInterleaved","0.0.8.241.0.0.0.1");
oid_add_from_string("iPpacketization_RFC3984Interleaved","0.0.8.241.0.0.0.2");
}
void proto_reg_handoff_h245(void) {
rtcp_handle = find_dissector("rtcp");
data_handle = find_dissector("data");
h263_handle = find_dissector("h263data");
amr_handle = find_dissector("amr_if2_nb");
dissector_add_for_decode_as_with_preference("tcp.port", h245_handle);
dissector_add_for_decode_as_with_preference("udp.port", MultimediaSystemControlMessage_handle);
}
static void init_h245_packet_info(h245_packet_info *pi)
{
if(pi == NULL) {
return;
}
pi->msg_type = H245_OTHER;
pi->frame_label[0] = '\0';
g_snprintf(pi->comment, sizeof(pi->comment), "H245 ");
}
