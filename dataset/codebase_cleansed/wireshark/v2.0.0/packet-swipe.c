static int
dissect_swipe(tvbuff_t *tvb, packet_info * pinfo, proto_tree *tree, void* data _U_)
{
int header_len, offset = 0;
proto_tree *swipe_tree;
proto_item *ti;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "swIPe");
col_clear(pinfo->cinfo, COL_INFO);
header_len = tvb_get_guint8(tvb, offset + 1);
if (tree)
{
ti = proto_tree_add_item(tree, proto_swipe, tvb, offset, header_len, ENC_NA);
swipe_tree = proto_item_add_subtree(ti, ett_swipe);
proto_tree_add_item(swipe_tree, hf_swipe_packet_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(swipe_tree, hf_swipe_len, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(swipe_tree, hf_swipe_policy_id, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(swipe_tree, hf_swipe_packet_seq, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
if (header_len > 8)
proto_tree_add_item(swipe_tree, hf_swipe_authenticator, tvb, offset + 8, header_len - 8, ENC_NA);
}
next_tvb = tvb_new_subset_remaining(tvb, header_len);
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_swipe(void)
{
static hf_register_info hf[] = {
{ &hf_swipe_packet_type, { "Packet type", "swipe.packet_type", FT_UINT8, BASE_DEC, VALS(swipe_packet_type_vals), 0x0, NULL, HFILL } },
{ &hf_swipe_len, { "Header Length", "swipe.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_swipe_policy_id, { "Policy identifier", "swipe.policy_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_swipe_packet_seq, { "Packet sequence number", "swipe.packet_seq", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_swipe_authenticator, { "Authenticator", "swipe.authenticator", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_swipe
};
proto_swipe = proto_register_protocol("swIPe IP Security Protocol", "swIPe", "swipe");
proto_register_field_array(proto_swipe, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_swipe(void)
{
dissector_handle_t swipe_handle;
swipe_handle = new_create_dissector_handle(dissect_swipe, proto_swipe );
dissector_add_uint("ip.proto", IP_PROTO_SWIPE, swipe_handle);
ipv6_handle = find_dissector("ipv6");
}
