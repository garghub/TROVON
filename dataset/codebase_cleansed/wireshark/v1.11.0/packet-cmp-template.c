static int
dissect_cmp_pdu(tvbuff_t *tvb, proto_tree *tree, asn1_ctx_t *actx)
{
return dissect_cmp_PKIMessage(FALSE, tvb, 0, actx,tree, -1);
}
static int dissect_cmp_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
tvbuff_t *next_tvb;
guint32 pdu_len;
guint8 pdu_type;
nstime_t ts;
proto_item *item=NULL;
proto_item *ti=NULL;
proto_tree *tree=NULL;
proto_tree *tcptrans_tree=NULL;
asn1_ctx_t asn1_ctx;
int offset=0;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CMP");
col_set_str(pinfo->cinfo, COL_INFO, "PKIXCMP");
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_cmp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_cmp);
}
pdu_len=tvb_get_ntohl(tvb, 0);
pdu_type=tvb_get_guint8(tvb, 4);
if (pdu_type < 10) {
ti = proto_tree_add_item(tree, proto_cmp, tvb, offset, 5, ENC_NA);
tcptrans_tree = proto_item_add_subtree(ti, ett_cmp);
proto_tree_add_item(tree, hf_cmp_tcptrans_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cmp_tcptrans_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(tree, tvb, offset, 7, "TCP transport");
tcptrans_tree = proto_item_add_subtree(ti, ett_cmp);
pdu_type=tvb_get_guint8(tvb, 6);
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans10_version, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans10_flags, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
}
col_add_str (pinfo->cinfo, COL_INFO, val_to_str (pdu_type, cmp_pdu_types, "0x%x"));
switch(pdu_type){
case CMP_TYPE_PKIMSG:
next_tvb = tvb_new_subset(tvb, offset, tvb_length_remaining(tvb, offset), pdu_len);
dissect_cmp_pdu(next_tvb, tree, &asn1_ctx);
offset += tvb_length_remaining(tvb, offset);
break;
case CMP_TYPE_POLLREP:
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans_poll_ref, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ts.secs = tvb_get_ntohl(tvb, 4);
ts.nsecs = 0;
proto_tree_add_time(tcptrans_tree, hf_cmp_tcptrans_ttcb, tvb, offset, 4, &ts);
offset += 4;
break;
case CMP_TYPE_POLLREQ:
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans_poll_ref, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case CMP_TYPE_NEGPOLLREP:
break;
case CMP_TYPE_PARTIALMSGREP:
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans_next_poll_ref, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ts.secs = tvb_get_ntohl(tvb, 4);
ts.nsecs = 0;
proto_tree_add_time(tcptrans_tree, hf_cmp_tcptrans_ttcb, tvb, offset, 4, &ts);
offset += 4;
next_tvb = tvb_new_subset(tvb, offset, tvb_length_remaining(tvb, offset), pdu_len);
dissect_cmp_pdu(next_tvb, tree, &asn1_ctx);
offset += tvb_length_remaining(tvb, offset);
break;
case CMP_TYPE_FINALMSGREP:
next_tvb = tvb_new_subset(tvb, offset, tvb_length_remaining(tvb, offset), pdu_len);
dissect_cmp_pdu(next_tvb, tree, &asn1_ctx);
offset += tvb_length_remaining(tvb, offset);
break;
case CMP_TYPE_ERRORMSGREP:
break;
}
return offset;
}
static void dissect_cmp_tcp_pdu_no_return(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
dissect_cmp_tcp_pdu(tvb, pinfo, parent_tree, NULL);
}
static guint get_cmp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint32 plen;
plen = tvb_get_ntohl(tvb, offset);
return plen+4;
}
static int
dissect_cmp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
guint32 pdu_len;
guint8 pdu_type;
int offset=4;
if (!tvb_bytes_exist(tvb, 0, 5)) {
return 0;
}
pdu_len=tvb_get_ntohl(tvb, 0);
pdu_type=tvb_get_guint8(tvb, 4);
if(pdu_type == 10) {
pdu_type = tvb_get_guint8(tvb, 7);
offset = 7;
if((pdu_len<=2)||(pdu_len>10000)){
return 0;
}
} else {
if(pdu_type>6){
return 0;
}
if((pdu_len<=0)||(pdu_len>10000)){
return 0;
}
}
if((pdu_type==0)&&(pdu_len<3)){
return 0;
}
tcp_dissect_pdus(tvb, pinfo, parent_tree, cmp_desegment, offset, get_cmp_pdu_len,
dissect_cmp_tcp_pdu_no_return);
return tvb_length(tvb);
}
static int
dissect_cmp_http(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CMP");
col_set_str(pinfo->cinfo, COL_INFO, "PKIXCMP");
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_cmp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_cmp);
}
return dissect_cmp_pdu(tvb, tree, &asn1_ctx);
}
void proto_register_cmp(void) {
static hf_register_info hf[] = {
{ &hf_cmp_type_oid,
{ "InfoType", "cmp.type.oid",
FT_STRING, BASE_NONE, NULL, 0,
"Type of InfoTypeAndValue", HFILL }},
{ &hf_cmp_tcptrans_len,
{ "Length", "cmp.tcptrans.length",
FT_UINT32, BASE_DEC, NULL, 0,
"TCP transport Length of PDU in bytes", HFILL }},
{ &hf_cmp_tcptrans_type,
{ "Type", "cmp.tcptrans.type",
FT_UINT8, BASE_DEC, VALS(cmp_pdu_types), 0,
"TCP transport PDU Type", HFILL }},
{ &hf_cmp_tcptrans_poll_ref,
{ "Polling Reference", "cmp.tcptrans.poll_ref",
FT_UINT32, BASE_HEX, NULL, 0,
"TCP transport Polling Reference", HFILL }},
{ &hf_cmp_tcptrans_next_poll_ref,
{ "Next Polling Reference", "cmp.tcptrans.next_poll_ref",
FT_UINT32, BASE_HEX, NULL, 0,
"TCP transport Next Polling Reference", HFILL }},
{ &hf_cmp_tcptrans_ttcb,
{ "Time to check Back", "cmp.tcptrans.ttcb",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
"TCP transport Time to check Back", HFILL }},
{ &hf_cmp_tcptrans10_version,
{ "Version", "cmp.tcptrans10.version",
FT_UINT8, BASE_DEC, NULL, 0,
"TCP transport version", HFILL }},
{ &hf_cmp_tcptrans10_flags,
{ "Flags", "cmp.tcptrans10.flags",
FT_UINT8, BASE_DEC, NULL, 0,
"TCP transport flags", HFILL }},
#include "packet-cmp-hfarr.c"
};
static gint *ett[] = {
&ett_cmp,
#include "packet-cmp-ettarr.c"
};
module_t *cmp_module;
proto_cmp = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_cmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
cmp_module = prefs_register_protocol(proto_cmp, proto_reg_handoff_cmp);
prefs_register_bool_preference(cmp_module, "desegment",
"Reassemble CMP-over-TCP messages spanning multiple TCP segments",
"Whether the CMP-over-TCP dissector should reassemble messages spanning multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&cmp_desegment);
prefs_register_uint_preference(cmp_module, "tcp_alternate_port",
"Alternate TCP port",
"Decode this TCP port\'s traffic as CMP. Set to \"0\" to disable.",
10,
&cmp_alternate_tcp_port);
prefs_register_uint_preference(cmp_module, "http_alternate_port",
"Alternate HTTP port",
"Decode this TCP port\'s traffic as CMP-over-HTTP. Set to \"0\" to disable. "
"Use this if the Content-Type is not set correctly.",
10,
&cmp_alternate_http_port);
prefs_register_uint_preference(cmp_module, "tcp_style_http_alternate_port",
"Alternate TCP-style-HTTP port",
"Decode this TCP port\'s traffic as TCP-transport-style CMP-over-HTTP. Set to \"0\" to disable. "
"Use this if the Content-Type is not set correctly.",
10,
&cmp_alternate_tcp_style_http_port);
}
void proto_reg_handoff_cmp(void) {
static gboolean inited = FALSE;
static dissector_handle_t cmp_http_handle;
static dissector_handle_t cmp_tcp_style_http_handle;
static dissector_handle_t cmp_tcp_handle;
static guint cmp_alternate_tcp_port_prev = 0;
static guint cmp_alternate_http_port_prev = 0;
static guint cmp_alternate_tcp_style_http_port_prev = 0;
if (!inited) {
cmp_http_handle = new_create_dissector_handle(dissect_cmp_http, proto_cmp);
dissector_add_string("media_type", "application/pkixcmp", cmp_http_handle);
dissector_add_string("media_type", "application/x-pkixcmp", cmp_http_handle);
cmp_tcp_style_http_handle = new_create_dissector_handle(dissect_cmp_tcp_pdu, proto_cmp);
dissector_add_string("media_type", "application/pkixcmp-poll", cmp_tcp_style_http_handle);
dissector_add_string("media_type", "application/x-pkixcmp-poll", cmp_tcp_style_http_handle);
cmp_tcp_handle = new_create_dissector_handle(dissect_cmp_tcp, proto_cmp);
dissector_add_uint("tcp.port", TCP_PORT_CMP, cmp_tcp_handle);
oid_add_from_string("Cryptlib-presence-check","1.3.6.1.4.1.3029.3.1.1");
oid_add_from_string("Cryptlib-PKIBoot","1.3.6.1.4.1.3029.3.1.2");
oid_add_from_string("HMAC MD5","1.3.6.1.5.5.8.1.1");
oid_add_from_string("HMAC SHA-1","1.3.6.1.5.5.8.1.2");
oid_add_from_string("HMAC TIGER","1.3.6.1.5.5.8.1.3");
oid_add_from_string("HMAC RIPEMD-160","1.3.6.1.5.5.8.1.4");
oid_add_from_string("sha256WithRSAEncryption","1.2.840.113549.1.1.11");
#include "packet-cmp-dis-tab.c"
inited = TRUE;
}
if (cmp_alternate_tcp_port != cmp_alternate_tcp_port_prev) {
if (cmp_alternate_tcp_port_prev != 0)
dissector_delete_uint("tcp.port", cmp_alternate_tcp_port_prev, cmp_tcp_handle);
if (cmp_alternate_tcp_port != 0)
dissector_add_uint("tcp.port", cmp_alternate_tcp_port, cmp_tcp_handle);
cmp_alternate_tcp_port_prev = cmp_alternate_tcp_port;
}
if (cmp_alternate_http_port != cmp_alternate_http_port_prev) {
if (cmp_alternate_http_port_prev != 0) {
dissector_delete_uint("tcp.port", cmp_alternate_http_port_prev, NULL);
dissector_delete_uint("http.port", cmp_alternate_http_port_prev, NULL);
}
if (cmp_alternate_http_port != 0)
http_dissector_add( cmp_alternate_http_port, cmp_http_handle);
cmp_alternate_http_port_prev = cmp_alternate_http_port;
}
if (cmp_alternate_tcp_style_http_port != cmp_alternate_tcp_style_http_port_prev) {
if (cmp_alternate_tcp_style_http_port_prev != 0) {
dissector_delete_uint("tcp.port", cmp_alternate_tcp_style_http_port_prev, NULL);
dissector_delete_uint("http.port", cmp_alternate_tcp_style_http_port_prev, NULL);
}
if (cmp_alternate_tcp_style_http_port != 0)
http_dissector_add( cmp_alternate_tcp_style_http_port, cmp_tcp_style_http_handle);
cmp_alternate_tcp_style_http_port_prev = cmp_alternate_tcp_style_http_port;
}
}
