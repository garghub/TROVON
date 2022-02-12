static void
dissect_msnlb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *msnlb_tree;
guint16 offset = 0;
guint8 type = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MS NLB");
col_set_str(pinfo->cinfo, COL_INFO, "MS NLB heartbeat");
if (tree) {
ti = proto_tree_add_item(tree, proto_msnlb, tvb, 0, -1, ENC_NA);
msnlb_tree = proto_item_add_subtree(ti, ett_msnlb);
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_hpn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_cls_virt_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_host_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
switch (type) {
case 0xc0:
display_unicode_string(tvb, msnlb_tree, offset, hf_msnlb_host_name, NULL);
break;
case 0xbf:
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, 4, ENC_NA);
break;
default:
proto_tree_add_item(msnlb_tree, hf_msnlb_unknown, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
}
}
}
void
proto_register_msnlb(void)
{
static hf_register_info hf[] = {
{ &hf_msnlb_unknown,
{ "Unknown", "msnlb.unknown",
FT_BYTES, BASE_NONE,
NULL, 0,
NULL, HFILL }
},
{ &hf_msnlb_hpn,
{ "Host Priority Number", "msnlb.hpn",
FT_UINT32, BASE_DEC,
NULL, 0,
NULL, HFILL }
},
{ &hf_msnlb_host_ip,
{ "Host IP", "msnlb.host_ip",
FT_IPv4, BASE_NONE,
NULL, 0,
"Host IP address", HFILL }
},
{ &hf_msnlb_cls_virt_ip,
{ "Cluster Virtual IP", "msnlb.cluster_virtual_ip",
FT_IPv4, BASE_NONE,
NULL, 0,
"Cluster Virtual IP address", HFILL }
},
{ &hf_msnlb_count,
{ "Count", "msnlb.count",
FT_UINT32, BASE_HEX,
NULL, 0,
NULL, HFILL }
},
{ &hf_msnlb_host_name,
{ "Host name", "msnlb.host_name",
FT_STRING, BASE_NONE,
NULL, 0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_msnlb
};
proto_msnlb = proto_register_protocol("MS Network Load Balancing", "MS NLB", "msnlb");
proto_register_field_array(proto_msnlb, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_msnlb(void)
{
dissector_handle_t msnlb_handle;
msnlb_handle = create_dissector_handle(dissect_msnlb, proto_msnlb);
dissector_add_uint("ethertype", ETHERTYPE_MS_NLB_HEARTBEAT, msnlb_handle);
}
