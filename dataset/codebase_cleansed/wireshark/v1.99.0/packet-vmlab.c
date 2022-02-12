static void
dissect_vmlab(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree* volatile vmlab_tree;
proto_item* ti;
guint32 offset=0;
const guint8* src_addr;
const guint8* dst_addr;
guint8 attributes;
guint8 portgroup;
ethertype_data_t ethertype_data;
volatile guint16 encap_proto;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VMLAB");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_vmlab, tvb, 0, 24, ENC_NA);
vmlab_tree = proto_item_add_subtree(ti, ett_vmlab);
attributes = tvb_get_guint8(tvb, offset);
proto_tree_add_item(vmlab_tree, hf_vmlab_flags_part1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(vmlab_tree, hf_vmlab_flags_fragment, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(vmlab_tree, hf_vmlab_flags_part2, tvb, offset, 1, ENC_BIG_ENDIAN);
if (attributes & 0x04) {
proto_item_append_text(ti, ", Fragment");
}
offset += 1;
portgroup = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(vmlab_tree, hf_vmlab_portgroup, tvb, offset, 1, portgroup);
proto_item_append_text(ti, ", Portgroup: %d", portgroup);
offset += 1;
offset += 2;
proto_tree_add_item(vmlab_tree, hf_vmlab_eth_addr, tvb, offset, 6, ENC_NA);
offset += 6;
dst_addr=tvb_get_ptr(tvb, offset, 6);
proto_tree_add_item(vmlab_tree, hf_vmlab_eth_dst, tvb, offset, 6, ENC_NA);
offset += 6;
src_addr=tvb_get_ptr(tvb, offset, 6);
proto_tree_add_item(vmlab_tree, hf_vmlab_eth_src, tvb, offset, 6, ENC_NA);
offset += 6;
proto_item_append_text(ti, ", Src: %s (%s), Dst: %s (%s)",
get_ether_name(src_addr), ether_to_str(src_addr), get_ether_name(dst_addr), ether_to_str(dst_addr));
encap_proto = tvb_get_ntohs(tvb, offset);
offset += 2;
ethertype_data.etype = encap_proto;
ethertype_data.offset_after_ethertype = offset;
ethertype_data.fh_tree = vmlab_tree;
ethertype_data.etype_id = hf_vmlab_etype;
ethertype_data.trailer_id = hf_vmlab_trailer;
ethertype_data.fcs_len = 0;
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
}
void
proto_register_vmlab(void)
{
static hf_register_info hf[] = {
{ &hf_vmlab_flags_part1, { "Unknown", "vmlab.unknown1",
FT_UINT8, BASE_HEX, NULL, 0xF8, NULL, HFILL }},
{ &hf_vmlab_flags_fragment, { "More Fragments", "vmlab.fragment",
FT_UINT8, BASE_DEC, VALS(fragment_vals), 0x04, NULL, HFILL }},
{ &hf_vmlab_flags_part2, { "Unknown", "vmlab.unknown2",
FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL }},
{ &hf_vmlab_portgroup, { "Portgroup", "vmlab.pgrp",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_vmlab_eth_src, { "Source", "vmlab.src",
FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_vmlab_eth_dst, { "Destination", "vmlab.dst",
FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_vmlab_eth_addr, { "Address", "vmlab.addr",
FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_vmlab_etype, { "Encapsulated Type", "vmlab.subtype",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0, NULL, HFILL }},
{ &hf_vmlab_trailer, { "Trailer", "vmlab.trailer",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_vmlab
};
proto_vmlab = proto_register_protocol("VMware Lab Manager", "VMLAB", "vmlab");
proto_register_field_array(proto_vmlab, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_vmlab(void)
{
dissector_handle_t vmlab_handle;
vmlab_handle = create_dissector_handle(dissect_vmlab, proto_vmlab);
dissector_add_uint("ethertype", ETHERTYPE_VMLAB, vmlab_handle);
ethertype_handle = find_dissector("ethertype");
}
