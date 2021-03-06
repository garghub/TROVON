static guint get_xot_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint16 plen;
int remain = tvb_length_remaining(tvb, offset);
if ( remain < XOT_HEADER_LENGTH){
return remain;
}
plen = tvb_get_ntohs(tvb, offset + 2);
return XOT_HEADER_LENGTH + plen;
}
static guint get_xot_pdu_len_mult(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int offset_before = offset;
int offset_next = offset + XOT_HEADER_LENGTH + X25_MIN_HEADER_LENGTH;
int tvb_len;
while (tvb_len = tvb_length_remaining(tvb, offset), tvb_len>0){
guint16 plen = 0;
int modulo;
guint16 bytes0_1;
guint8 pkt_type;
gboolean m_bit_set;
int offset_x25 = offset + XOT_HEADER_LENGTH;
offset_next = offset_x25 + X25_MIN_HEADER_LENGTH;
if (tvb_len < XOT_HEADER_LENGTH) {
return offset_next-offset_before;
}
plen = get_xot_pdu_len(pinfo, tvb, offset);
offset_next = offset + plen;
if (tvb_len < plen){
return offset_next-offset_before;
}
bytes0_1 = tvb_get_ntohs(tvb, offset_x25+0);
pkt_type = tvb_get_guint8(tvb, offset_x25+2);
if (offset == offset_before && !PACKET_IS_DATA(pkt_type)) {
return offset_next-offset_before;
}
if (PACKET_IS_DATA(pkt_type)){
modulo = ((bytes0_1 & 0x2000) ? 128 : 8);
if (modulo == 8) {
m_bit_set = pkt_type & X25_MBIT_MOD8;
} else {
m_bit_set = tvb_get_guint8(tvb, offset_x25+3) & X25_MBIT_MOD128;
}
if (!m_bit_set){
return offset_next-offset_before;
}
}
offset = offset_next;
offset_next += XOT_HEADER_LENGTH + X25_MIN_HEADER_LENGTH;
}
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return offset_next - offset_before;
}
static void dissect_xot_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint16 version;
guint16 plen;
guint8 pkt_type;
proto_item *ti = NULL;
proto_tree *xot_tree = NULL;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "XOT");
version = tvb_get_ntohs(tvb, offset + 0);
plen = tvb_get_ntohs(tvb, offset + 2);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "XOT Version = %u, size = %u",
version, plen);
if (check_col(pinfo->cinfo, COL_INFO) && offset == 0 &&
tvb_length_remaining(tvb, offset) > XOT_HEADER_LENGTH + plen )
col_append_fstr(pinfo->cinfo, COL_INFO, " TotX25: %d",
tvb_length_remaining(tvb, offset));
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_xot, tvb, offset, XOT_HEADER_LENGTH,
"X.25 over TCP");
xot_tree = proto_item_add_subtree(ti, ett_xot);
proto_tree_add_uint(xot_tree, hf_xot_version, tvb, offset, 2, version);
proto_tree_add_uint(xot_tree, hf_xot_length, tvb, offset + 2, 2, plen);
}
offset += XOT_HEADER_LENGTH;
if (plen >= X25_MIN_HEADER_LENGTH) {
pkt_type = tvb_get_guint8(tvb, offset + 2);
if (pkt_type == XOT_PVC_SETUP) {
guint init_itf_name_len, resp_itf_name_len, pkt_size;
gint hdr_offset = offset;
col_set_str(pinfo->cinfo, COL_INFO, "XOT PVC Setup");
proto_item_set_len(ti, XOT_HEADER_LENGTH + plen);
proto_tree_add_item(xot_tree, hf_x25_gfi, tvb, hdr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(xot_tree, hf_x25_lcn, tvb, hdr_offset, 2, ENC_BIG_ENDIAN);
hdr_offset += 2;
proto_tree_add_item(xot_tree, hf_x25_type, tvb, hdr_offset, 1, ENC_BIG_ENDIAN);
hdr_offset += 1;
proto_tree_add_item(xot_tree, hf_xot_pvc_version, tvb, hdr_offset, 1, ENC_BIG_ENDIAN);
hdr_offset += 1;
proto_tree_add_item(xot_tree, hf_xot_pvc_status, tvb, hdr_offset, 1, ENC_BIG_ENDIAN);
hdr_offset += 1;
proto_tree_add_item(xot_tree, hf_xot_pvc_init_itf_name_len, tvb, hdr_offset, 1, ENC_BIG_ENDIAN);
init_itf_name_len = tvb_get_guint8(tvb, hdr_offset);
hdr_offset += 1;
proto_tree_add_item(xot_tree, hf_xot_pvc_init_lcn, tvb, hdr_offset, 2, ENC_BIG_ENDIAN);
hdr_offset += 2;
proto_tree_add_item(xot_tree, hf_xot_pvc_resp_itf_name_len, tvb, hdr_offset, 1, ENC_BIG_ENDIAN);
resp_itf_name_len = tvb_get_guint8(tvb, hdr_offset);
hdr_offset += 1;
proto_tree_add_item(xot_tree, hf_xot_pvc_resp_lcn, tvb, hdr_offset, 2, ENC_BIG_ENDIAN);
hdr_offset += 2;
proto_tree_add_item(xot_tree, hf_xot_pvc_send_inc_window, tvb, hdr_offset, 1, ENC_BIG_ENDIAN);
hdr_offset += 1;
proto_tree_add_item(xot_tree, hf_xot_pvc_send_out_window, tvb, hdr_offset, 1, ENC_BIG_ENDIAN);
hdr_offset += 1;
pkt_size = 1 << tvb_get_guint8(tvb, hdr_offset);
proto_tree_add_uint(xot_tree, hf_xot_pvc_send_inc_pkt_size, tvb, hdr_offset, 1, pkt_size);
hdr_offset += 1;
pkt_size = 1 << tvb_get_guint8(tvb, hdr_offset);
proto_tree_add_uint(xot_tree, hf_xot_pvc_send_out_pkt_size, tvb, hdr_offset, 1, pkt_size);
hdr_offset += 1;
proto_tree_add_item(xot_tree, hf_xot_pvc_init_itf_name, tvb, hdr_offset, init_itf_name_len, ENC_ASCII|ENC_NA);
hdr_offset += init_itf_name_len;
proto_tree_add_item(xot_tree, hf_xot_pvc_resp_itf_name, tvb, hdr_offset, resp_itf_name_len, ENC_ASCII|ENC_NA);
} else {
next_tvb = tvb_new_subset(tvb, offset,
MIN(plen, tvb_length_remaining(tvb, offset)), plen);
call_dissector(x25_handle, next_tvb, pinfo, tree);
}
}
}
static void dissect_xot_mult(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
int len = get_xot_pdu_len_mult(pinfo, tvb, offset);
tvbuff_t *next_tvb;
int offset_max = offset+MIN(len,tvb_length_remaining(tvb, offset));
proto_item *ti;
proto_tree *xot_tree;
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_xot, tvb, offset, offset_max-offset,
"X.25 over TCP - X.25 Sequence");
xot_tree = proto_item_add_subtree(ti, ett_xot);
proto_tree_add_uint(xot_tree, hf_xot_length, tvb, offset, offset_max, len);
}
while (offset <= offset_max - XOT_HEADER_LENGTH){
int plen = get_xot_pdu_len(pinfo, tvb, offset);
next_tvb = tvb_new_subset(tvb, offset,plen, plen);
dissect_xot_pdu(next_tvb, pinfo, tree);
offset += plen;
}
}
static int dissect_xot_tcp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int tvb_len = tvb_length(tvb);
int len = 0;
if (tvb_len >= 2 && tvb_get_ntohs(tvb,0) != XOT_VERSION) {
return 0;
}
if (!x25_desegment || !xot_desegment){
tcp_dissect_pdus(tvb, pinfo, tree, xot_desegment,
XOT_HEADER_LENGTH,
get_xot_pdu_len,
dissect_xot_pdu);
len=get_xot_pdu_len(pinfo, tvb, 0);
} else {
tcp_dissect_pdus(tvb, pinfo, tree, xot_desegment,
XOT_HEADER_LENGTH,
get_xot_pdu_len_mult,
dissect_xot_mult);
len=get_xot_pdu_len_mult(pinfo, tvb, 0);
}
if (len < XOT_HEADER_LENGTH) {
len = 0;
} else if (tvb_len < XOT_HEADER_LENGTH) {
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
len=tvb_len - XOT_HEADER_LENGTH;
} else if (tvb_len < len) {
if (x25_desegment){
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
} else {
pinfo->desegment_len = len - tvb_len;
}
len=tvb_len - len;
}
return len;
}
void
proto_register_xot(void)
{
static hf_register_info hf[] = {
{ &hf_xot_version,
{ "Version", "xot.version", FT_UINT16, BASE_DEC,
NULL, 0, "Version of X.25 over TCP protocol", HFILL }},
{ &hf_xot_length,
{ "Length", "xot.length", FT_UINT16, BASE_DEC,
NULL, 0, "Length of X.25 over TCP packet", HFILL }},
{ &hf_x25_gfi,
{ "GFI", "x.25.gfi", FT_UINT16, BASE_DEC,
NULL, 0xF000, "General Format Identifier", HFILL }},
{ &hf_x25_lcn,
{ "Logical Channel", "x.25.lcn", FT_UINT16, BASE_DEC,
NULL, 0x0FFF, "Logical Channel Number", HFILL }},
{ &hf_x25_type,
{ "Packet Type", "x.25.type", FT_UINT8, BASE_HEX,
VALS(vals_x25_type), 0x0, NULL, HFILL }},
{ &hf_xot_pvc_version,
{ "Version", "xot.pvc.version", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_xot_pvc_status,
{ "Status", "xot.pvc.status", FT_UINT8, BASE_HEX,
VALS(xot_pvc_status_vals), 0, NULL, HFILL }},
{ &hf_xot_pvc_init_itf_name_len,
{ "Initiator interface name length", "xot.pvc.init_itf_name_len", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_xot_pvc_init_lcn,
{ "Initiator LCN", "xot.pvc.init_lcn", FT_UINT8, BASE_DEC,
NULL, 0, "Initiator Logical Channel Number", HFILL }},
{ &hf_xot_pvc_resp_itf_name_len,
{ "Responder interface name length", "xot.pvc.resp_itf_name_len", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_xot_pvc_resp_lcn,
{ "Responder LCN", "xot.pvc.resp_lcn", FT_UINT16, BASE_DEC,
NULL, 0, "Responder Logical Channel Number", HFILL }},
{ &hf_xot_pvc_send_inc_window,
{ "Sender incoming window", "xot.pvc.send_inc_window", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_xot_pvc_send_out_window,
{ "Sender outgoing window", "xot.pvc.send_out_window", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_xot_pvc_send_inc_pkt_size,
{ "Sender incoming packet size", "xot.pvc.send_inc_pkt_size", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_xot_pvc_send_out_pkt_size,
{ "Sender outgoing packet size", "xot.pvc.send_out_pkt_size", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_xot_pvc_init_itf_name,
{ "Initiator interface name", "xot.pvc.init_itf_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_xot_pvc_resp_itf_name,
{ "Responder interface name", "xot.pvc.resp_itf_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_xot
};
module_t *xot_module;
proto_xot = proto_register_protocol("X.25 over TCP", "XOT", "xot");
proto_register_field_array(proto_xot, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("xot", dissect_xot_tcp_heur, proto_xot);
xot_module = prefs_register_protocol(proto_xot, NULL);
prefs_register_bool_preference(xot_module, "desegment",
"Reassemble X.25-over-TCP messages spanning multiple TCP segments",
"Whether the X.25-over-TCP dissector should reassemble messages spanning multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings",
&xot_desegment);
prefs_register_bool_preference(xot_module, "x25_desegment",
"Reassemble X.25 packets with More flag to enable safe X.25 reassembly",
"Whether the X.25-over-TCP dissector should reassemble all X.25 packets before calling the X25 dissector. "
"If the TCP packets arrive out-of-order, the X.25 reassembly can otherwise fail. "
"To use this option, you should also enable \"Reassemble X.25-over-TCP messages spanning multiple TCP segments\", \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings and \"Reassemble fragmented X.25 packets\" in the X.25 protocol settings.",
&x25_desegment);
}
void
proto_reg_handoff_xot(void)
{
dissector_handle_t xot_handle;
xot_handle = find_dissector("xot");
dissector_add_uint("tcp.port", TCP_PORT_XOT, xot_handle);
x25_handle = find_dissector("x.25");
}
