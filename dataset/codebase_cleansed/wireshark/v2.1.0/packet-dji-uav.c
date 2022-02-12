static void
request_response_handling(tvbuff_t *tvb, packet_info *pinfo, proto_tree *djiuav_tree,
guint32 offset)
{
conversation_t *conversation;
djiuav_conv_info_t *djiuav_info;
djiuav_transaction_t *djiuav_trans;
guint16 seq_no;
gboolean is_cmd;
guint8 packet_type;
is_cmd = (pinfo->match_uint == pinfo->destport);
seq_no = tvb_get_letohs(tvb, offset + 4);
packet_type = tvb_get_guint8(tvb, offset + 6);
conversation = find_or_create_conversation(pinfo);
djiuav_info = (djiuav_conv_info_t *)conversation_get_proto_data(conversation, proto_djiuav);
if (!djiuav_info) {
djiuav_info = wmem_new(wmem_file_scope(), djiuav_conv_info_t);
djiuav_info->pdus=wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
conversation_add_proto_data(conversation, proto_djiuav, djiuav_info);
}
if (!pinfo->fd->flags.visited) {
if (is_cmd) {
djiuav_trans=wmem_new(wmem_file_scope(), djiuav_transaction_t);
djiuav_trans->request_frame=pinfo->num;
djiuav_trans->reply_frame=0;
djiuav_trans->request_time=pinfo->abs_ts;
djiuav_trans->seqno=seq_no;
djiuav_trans->command=packet_type;
wmem_map_insert(djiuav_info->pdus, GUINT_TO_POINTER((guint)seq_no), (void *)djiuav_trans);
} else {
djiuav_trans=(djiuav_transaction_t *)wmem_map_lookup(djiuav_info->pdus, GUINT_TO_POINTER((guint)seq_no));
if (djiuav_trans) {
if (djiuav_trans->reply_frame == 0)
djiuav_trans->reply_frame=pinfo->num;
}
}
} else {
djiuav_trans=(djiuav_transaction_t *)wmem_map_lookup(djiuav_info->pdus, GUINT_TO_POINTER((guint)seq_no));
}
if (djiuav_tree && djiuav_trans) {
if (is_cmd) {
if (djiuav_trans->reply_frame) {
proto_item *it;
it = proto_tree_add_uint(djiuav_tree, hf_djiuav_response_in,
tvb, 0, 0, djiuav_trans->reply_frame);
PROTO_ITEM_SET_GENERATED(it);
}
} else {
if (djiuav_trans->request_frame) {
proto_item *it;
nstime_t ns;
it = proto_tree_add_uint(djiuav_tree, hf_djiuav_response_to,
tvb, 0, 0, djiuav_trans->request_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->abs_ts, &djiuav_trans->request_time);
it = proto_tree_add_time(djiuav_tree, hf_djiuav_response_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
}
}
static int
dissect_djiuav_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *djiuav_tree = NULL;
guint32 offset = 0;
guint32 pdu_length;
guint8 packet_type;
gboolean is_cmd;
is_cmd = (pinfo->match_uint == pinfo->destport);
packet_type = tvb_get_guint8(tvb, 6);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_add_str(pinfo->cinfo, COL_INFO, is_cmd?"C: ":"R: ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(packet_type,
djiuav_pdu_type, "Type 0x%02x"));
ti = proto_tree_add_item(tree, proto_djiuav, tvb, offset, -1, ENC_NA);
djiuav_tree = proto_item_add_subtree(ti, ett_djiuav);
request_response_handling(tvb, pinfo, djiuav_tree, offset);
if (tree) {
proto_tree_add_item(djiuav_tree, hf_djiuav_magic, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
pdu_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(djiuav_tree, hf_djiuav_length, tvb, offset, 1,
ENC_NA);
offset += 1;
proto_tree_add_item(djiuav_tree, hf_djiuav_flags, tvb, offset, 1,
ENC_NA);
offset += 1;
proto_tree_add_item(djiuav_tree, hf_djiuav_seqno, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(djiuav_tree, hf_djiuav_cmd, tvb, offset, 1,
ENC_NA);
offset += 1;
if (is_cmd) {
switch (packet_type) {
case 0x20:
proto_tree_add_item(djiuav_tree, hf_djiuav_cmd20_unknown, tvb, offset, 7,
ENC_NA);
offset += 7;
break;
default:
proto_tree_add_item(djiuav_tree, hf_djiuav_cmdunk, tvb, offset, pdu_length - 8,
ENC_NA);
offset += (pdu_length - 8);
break;
}
} else {
switch (packet_type) {
default:
proto_tree_add_item(djiuav_tree, hf_djiuav_respunk, tvb,
offset, pdu_length - 8, ENC_NA);
offset += (pdu_length - 8);
break;
}
}
if (offset < pdu_length - 1) {
proto_tree_add_item(djiuav_tree, hf_djiuav_extradata, tvb, offset,
pdu_length - 1 - offset, ENC_NA);
offset += pdu_length - 1 - offset;
}
proto_tree_add_item(djiuav_tree, hf_djiuav_checksum, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
}
return offset;
}
static gboolean
test_djiuav(tvbuff_t *tvb)
{
if ( tvb_captured_length(tvb) < 8
|| tvb_get_ntohs(tvb, 0) != 0x55BB
) {
return FALSE;
}
return TRUE;
}
static guint
get_djiuav_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_guint8(tvb, offset + 2);
}
static int
dissect_djiuav_static(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if ( !test_djiuav(tvb) ) {
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, djiuav_desegment, 8,
get_djiuav_pdu_len, dissect_djiuav_pdu, data);
return tvb_captured_length(tvb);
}
void
proto_register_djiuav(void)
{
static hf_register_info hf[] = {
{ &hf_djiuav_magic,
{ "Protocol Magic", "djiuav.magic", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_djiuav_length,
{ "PDU Length", "djiuav.length", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_djiuav_flags,
{ "Flags", "djiuav.flags", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_djiuav_seqno,
{ "Sequence No", "djiuav.seqno", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_djiuav_cmd,
{ "PDU Type", "djiuav.pdutype", FT_UINT8, BASE_HEX, VALS(djiuav_pdu_type),
0x0, NULL, HFILL }},
{ &hf_djiuav_checksum,
{ "Checksum", "djiuav.checksum", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
#if 0
{ &hf_djiuav_cmd04_unknown,
{ "C04 Unknown", "djiuav.cmd04.unknown", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_djiuav_resp04_unknown,
{ "R04 Unknown", "djiuav.resp04.unknown", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
#endif
{ &hf_djiuav_cmd20_unknown,
{ "Time in BCD", "djiuav.cmd04.bcdtime", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
#if 0
{ &hf_djiuav_resp20_unknown,
{ "R20 Unknown", "djiuav.resp04.unknown", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
#endif
{ &hf_djiuav_cmdunk,
{ "C Unknown", "djiuav.cmd.unknown", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_djiuav_respunk,
{ "R Unknown", "djiuav.resp.unknown", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_djiuav_extradata,
{ "Unexpected", "djiuav.unexpected", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_djiuav_response_in,
{ "Response In", "djiuav.response_in", FT_FRAMENUM, BASE_NONE, NULL,
0x0, "Matching response in frame", HFILL }},
{ &hf_djiuav_response_to,
{ "Request In", "djiuav.response_to",
FT_FRAMENUM, BASE_NONE, NULL,
0x0, "Matching command in frame", HFILL }},
{ &hf_djiuav_response_time,
{ "Response Time", "djiuav.response_time",
FT_RELATIVE_TIME, BASE_NONE, NULL,
0x0, "Time between Command and matching Response", HFILL }},
};
static gint *ett[] = {
&ett_djiuav,
};
module_t *djiuav_module;
proto_djiuav = proto_register_protocol(PROTO_LONG_NAME, PROTO_SHORT_NAME, "djiuav");
proto_register_field_array(proto_djiuav, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
djiuav_module = prefs_register_protocol(proto_djiuav, NULL);
prefs_register_bool_preference(djiuav_module, "desegment",
"Reassemble DJIUAV messages",
"Whether DJIUAV should reassemble messages spanning multiple"
" TCP segments (required to get useful results)",
&djiuav_desegment);
}
void
proto_reg_handoff_djiuav(void)
{
dissector_handle_t djiuav_handle;
djiuav_handle = create_dissector_handle(dissect_djiuav_static, proto_djiuav);
dissector_add_uint("tcp.port", PORT_DJIUAV, djiuav_handle);
}
