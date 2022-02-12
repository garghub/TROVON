static void
dissect_isdn(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *isdn_tree;
proto_item *ti;
static const guint8 v120_sabme[3] = { 0x08, 0x01, 0x7F };
static const guint8 ppp[2] = { 0xFF, 0x03 };
circuit_t *circuit;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISDN");
if (pinfo->pseudo_header->isdn.uton) {
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "Network");
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "User");
} else {
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "User");
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "Network");
}
pinfo->ctype = CT_ISDN;
pinfo->circuit_id = pinfo->pseudo_header->isdn.channel;
if (tree) {
ti = proto_tree_add_item(tree, proto_isdn, tvb, 0, 0, ENC_NA);
isdn_tree = proto_item_add_subtree(ti, ett_isdn);
proto_tree_add_uint(isdn_tree, hf_isdn_channel, tvb, 0, 0,
pinfo->pseudo_header->isdn.channel);
}
circuit = find_circuit(pinfo->ctype, pinfo->circuit_id, pinfo->fd->num);
if (circuit == NULL)
circuit = circuit_new(pinfo->ctype, pinfo->circuit_id,
pinfo->fd->num);
if (circuit_get_dissector(circuit) == NULL) {
switch (pinfo->pseudo_header->isdn.channel) {
case 0:
switch (dchannel_protocol) {
case DCHANNEL_LAPD:
circuit_set_dissector(circuit, lapd_handle);
break;
case DCHANNEL_DPNSS:
circuit_set_dissector(circuit,
dpnss_link_handle);
break;
}
break;
default:
if (tvb_memeql(tvb, 0, v120_sabme, 3) == 0) {
circuit_set_dissector(circuit, v120_handle);
} else if (tvb_memeql(tvb, 0, ppp, 2) == 0) {
circuit_set_dissector(circuit, ppp_hdlc_handle);
}
break;
}
}
if (!try_circuit_dissector(pinfo->ctype, pinfo->circuit_id,
pinfo->fd->num, tvb, pinfo, tree, NULL))
call_dissector(data_handle, tvb, pinfo, tree);
}
void
proto_register_isdn(void)
{
static hf_register_info hf[] = {
{ &hf_isdn_channel,
{ "Channel", "isdn.channel", FT_UINT8, BASE_DEC,
VALS(channel_vals), 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_isdn,
};
module_t *isdn_module;
proto_isdn = proto_register_protocol("ISDN", "ISDN", "isdn");
proto_register_field_array(proto_isdn, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
isdn_module = prefs_register_protocol(proto_isdn, NULL);
prefs_register_enum_preference(isdn_module, "dchannel_protocol",
"D-channel protocol",
"The protocol running on the D channel",
&dchannel_protocol, dchannel_protocol_options, FALSE);
}
void
proto_reg_handoff_isdn(void)
{
dissector_handle_t isdn_handle;
lapd_handle = find_dissector("lapd");
dpnss_link_handle = find_dissector("dpnss_link");
ppp_hdlc_handle = find_dissector("ppp_hdlc");
v120_handle = find_dissector("v120");
data_handle = find_dissector("data");
isdn_handle = create_dissector_handle(dissect_isdn, proto_isdn);
dissector_add_uint("wtap_encap", WTAP_ENCAP_ISDN, isdn_handle);
}
