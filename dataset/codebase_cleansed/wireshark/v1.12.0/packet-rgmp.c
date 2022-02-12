int
dissect_rgmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset)
{
proto_tree *tree;
proto_item *item;
guint8 type;
if (!proto_is_protocol_enabled(find_protocol_by_id(proto_rgmp))) {
return offset + tvb_length_remaining(tvb, offset);
}
item = proto_tree_add_item(parent_tree, proto_rgmp, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_rgmp);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RGMP");
col_clear(pinfo->cinfo, COL_INFO);
type = tvb_get_guint8(tvb, offset);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(type, rgmp_types, "Unknown Type: 0x%02x"));
proto_tree_add_uint(tree, hf_type, tvb, offset, 1, type);
offset += 1;
offset += 1;
igmp_checksum(tree, tvb, hf_checksum, hf_checksum_bad, pinfo, 0);
offset += 2;
proto_tree_add_item(tree, hf_maddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
void
proto_register_rgmp(void)
{
static hf_register_info hf[] = {
{ &hf_type,
{ "Type", "rgmp.type", FT_UINT8, BASE_HEX,
VALS(rgmp_types), 0, "RGMP Packet Type", HFILL }
},
{ &hf_checksum,
{ "Checksum", "rgmp.checksum", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_checksum_bad,
{ "Bad Checksum", "rgmp.checksum_bad", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_maddr,
{ "Multicast group address", "rgmp.maddr", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_rgmp
};
proto_rgmp = proto_register_protocol
("Router-port Group Management Protocol", "RGMP", "rgmp");
proto_register_field_array(proto_rgmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
