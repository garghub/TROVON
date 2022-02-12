static void
dissect_hpteam(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HP NIC Team");
col_add_fstr(pinfo->cinfo, COL_INFO, "HP NIC Teaming Heartbeat; Port MAC = %s",
ep_address_to_str(&pinfo->dl_src));
if (tree) {
proto_item *hpteam_item;
proto_tree *hpteam_tree;
hpteam_item = proto_tree_add_item(tree, proto_hpteam, tvb, 0, -1, ENC_NA);
hpteam_tree = proto_item_add_subtree(hpteam_item, ett_hpteam);
proto_tree_add_item(hpteam_tree, hf_hpteam, tvb, 0, -1, ENC_NA);
}
}
void proto_register_hpteam(void)
{
static hf_register_info hf_pid = {
&hf_llc_hpteam_pid,
{ "PID", "llc.hpteam_pid",
FT_UINT16, BASE_HEX, VALS(hpteam_pid_vals),
0x0, NULL, HFILL }
};
static hf_register_info hf_data[] = {
{&hf_hpteam,
{ "Proprietary Data", "hpteam.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_hpteam
};
proto_hpteam = proto_register_protocol ("HP NIC Teaming Heartbeat", "HPTEAM", "hpteam");
llc_add_oui(OUI_HP_2, "llc.hpteam_pid", "LLC Hewlett Packard OUI PID", &hf_pid);
proto_register_field_array(proto_hpteam, hf_data, array_length(hf_data));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("hpteam", dissect_hpteam, proto_hpteam);
}
void proto_reg_handoff_hpteam(void)
{
dissector_handle_t hpteam_handle;
data_handle = find_dissector("data");
hpteam_handle = find_dissector("hpteam");
dissector_add_uint("llc.hpteam_pid", 0x0002, hpteam_handle);
}
