static int
dissect_turnchannel_message(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data _U_)
{
guint len;
guint16 channel_id;
guint16 data_len;
proto_item *ti;
proto_tree *turnchannel_tree;
heur_dtbl_entry_t *hdtbl_entry;
len = tvb_length(tvb);
if (len < TURNCHANNEL_HDR_LEN) {
return 0;
}
channel_id = tvb_get_ntohs(tvb, 0);
data_len = tvb_get_ntohs(tvb, 2);
if ((channel_id < 0x4000) || (channel_id > 0xFFFE)) {
return 0;
}
if (len != TURNCHANNEL_HDR_LEN + data_len) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TURN CHANNEL");
col_add_fstr(pinfo->cinfo, COL_INFO, "Channel Id 0x%x", channel_id);
ti = proto_tree_add_item(tree, proto_turnchannel, tvb, 0, -1, ENC_NA);
turnchannel_tree = proto_item_add_subtree(ti, ett_turnchannel);
proto_tree_add_uint(turnchannel_tree, hf_turnchannel_id, tvb, 0, 2, channel_id);
proto_tree_add_uint(turnchannel_tree, hf_turnchannel_len, tvb, 2, 2, data_len);
if (len > TURNCHANNEL_HDR_LEN) {
tvbuff_t *next_tvb;
guint reported_len, new_len;
new_len = tvb_length_remaining(tvb, TURNCHANNEL_HDR_LEN);
reported_len = tvb_reported_length_remaining(tvb,
TURNCHANNEL_HDR_LEN);
if (data_len < reported_len) {
reported_len = data_len;
}
next_tvb = tvb_new_subset(tvb, TURNCHANNEL_HDR_LEN, new_len,
reported_len);
if (!dissector_try_heuristic(heur_subdissector_list,
next_tvb, pinfo, tree, &hdtbl_entry, NULL)) {
call_dissector(data_handle,next_tvb, pinfo, tree);
}
}
return tvb_length(tvb);
}
static guint
get_turnchannel_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return (guint)tvb_get_ntohs(tvb, offset+2) + TURNCHANNEL_HDR_LEN;
}
static int
dissect_turnchannel_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, TURNCHANNEL_HDR_LEN,
get_turnchannel_message_len, dissect_turnchannel_message, data);
return tvb_length(tvb);
}
static gboolean
dissect_turnchannel_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint len;
guint16 channel_id;
guint16 data_len;
len = tvb_length(tvb);
if (len < TURNCHANNEL_HDR_LEN) {
return FALSE;
}
channel_id = tvb_get_ntohs(tvb, 0);
data_len = tvb_get_ntohs(tvb, 2);
if ((channel_id < 0x4000) || (channel_id > 0xFFFE)) {
return FALSE;
}
if (len != TURNCHANNEL_HDR_LEN + data_len) {
return FALSE;
}
return dissect_turnchannel_message(tvb, pinfo, tree, NULL);
}
void
proto_register_turnchannel(void)
{
static hf_register_info hf[] = {
{ &hf_turnchannel_id,
{ "TURN Channel ID", "turnchannel.id", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_turnchannel_len,
{ "Data Length", "turnchannel.length", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_turnchannel,
};
proto_turnchannel = proto_register_protocol("TURN Channel",
"TURNCHANNEL", "turnchannel");
new_register_dissector("turnchannel", dissect_turnchannel_message,
proto_turnchannel);
register_heur_dissector_list("turnchannel", &heur_subdissector_list);
proto_register_field_array(proto_turnchannel, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_turnchannel(void)
{
dissector_handle_t turnchannel_tcp_handle;
dissector_handle_t turnchannel_udp_handle;
turnchannel_tcp_handle = new_create_dissector_handle(dissect_turnchannel_tcp, proto_turnchannel);
turnchannel_udp_handle = find_dissector("turnchannel");
dissector_add_handle("tcp.port", turnchannel_tcp_handle);
dissector_add_handle("udp.port", turnchannel_udp_handle);
heur_dissector_add("stun", dissect_turnchannel_heur, proto_turnchannel);
data_handle = find_dissector("data");
}
