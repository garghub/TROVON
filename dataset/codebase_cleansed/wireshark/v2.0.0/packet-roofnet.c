static void dissect_roofnet_header(proto_tree *tree, tvbuff_t *tvb, guint *offset)
{
ptvcursor_t *cursor = ptvcursor_new(tree, tvb, *offset);
ptvcursor_add(cursor, hf_roofnet_version, 1, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_type, 1, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_nlinks, 1, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_next, 1, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_ttl, 2, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_cksum, 2, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_flags, 2, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_data_length, 2, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_query_dst, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_seq, 4, ENC_BIG_ENDIAN);
*offset = ptvcursor_current_offset(cursor);
ptvcursor_free(cursor);
}
static void dissect_roofnet_link(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint link)
{
proto_tree *subtree= NULL;
ptvcursor_t *cursor= NULL;
guint32 addr_src= 0;
guint32 addr_dst= 0;
addr_src= tvb_get_ipv4(tvb, *offset + ROOFNET_LINK_OFFSET_SRC);
addr_dst= tvb_get_ipv4(tvb, *offset + ROOFNET_LINK_OFFSET_DST);
subtree = proto_tree_add_subtree_format(tree, tvb, *offset, ROOFNET_LINK_LEN,
ett_roofnet_link, NULL, "link: %u, src: %s, dst: %s",
link,
get_hostname(addr_src),
get_hostname(addr_dst));
proto_tree_add_ipv4(subtree, hf_roofnet_link_src, tvb, *offset, 4, addr_src);
*offset += 4;
cursor = ptvcursor_new(subtree, tvb, *offset);
ptvcursor_add(cursor, hf_roofnet_link_forward, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_link_rev, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_link_seq, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_roofnet_link_age, 4, ENC_BIG_ENDIAN);
*offset = ptvcursor_current_offset(cursor);
ptvcursor_free(cursor);
proto_tree_add_ipv4(subtree, hf_roofnet_link_dst, tvb, *offset, 4, addr_dst);
}
static void dissect_roofnet_data(proto_tree *tree, tvbuff_t *tvb, packet_info * pinfo, gint offset)
{
guint16 roofnet_datalen= 0;
guint16 remaining_datalen= 0;
roofnet_datalen = tvb_get_ntohs(tvb, ROOFNET_OFFSET_DATA_LENGTH);
remaining_datalen= tvb_reported_length_remaining(tvb, offset);
if (roofnet_datalen < remaining_datalen)
proto_tree_add_expert_format(tree, pinfo, &ei_roofnet_too_much_data, tvb, offset, roofnet_datalen,
"[More payload data (%u) than told by Roofnet (%u)]",
remaining_datalen, roofnet_datalen);
if (roofnet_datalen == 0)
return;
call_dissector(ip_handle, tvb_new_subset_remaining(tvb, offset), pinfo, tree);
}
static void dissect_roofnet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item * it;
proto_tree * roofnet_tree;
guint offset= 0;
guint8 roofnet_msg_type= 0;
guint8 roofnet_nlinks= 0;
guint8 nlink= 1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Roofnet");
roofnet_msg_type = tvb_get_guint8(tvb, ROOFNET_OFFSET_TYPE);
col_add_fstr(pinfo->cinfo, COL_INFO, "Message Type: %s",
val_to_str(roofnet_msg_type, roofnet_pt_vals, "Unknown (%d)"));
it = proto_tree_add_item(tree, proto_roofnet, tvb, offset, -1, ENC_NA);
roofnet_tree = proto_item_add_subtree(it, ett_roofnet);
dissect_roofnet_header(roofnet_tree, tvb, &offset);
roofnet_nlinks= tvb_get_guint8(tvb, ROOFNET_OFFSET_NLINKS);
if ((roofnet_nlinks*6*4)+ROOFNET_HEADER_LENGTH > ROOFNET_MAX_LENGTH) {
expert_add_info_format(pinfo, it, &ei_roofnet_too_many_links, "Too many links (%u)", roofnet_nlinks);
return;
}
for (; roofnet_nlinks > 0; roofnet_nlinks--) {
if (tvb_reported_length_remaining(tvb, offset) < ROOFNET_LINK_DESCRIPTION_LENGTH)
return;
dissect_roofnet_link(roofnet_tree, tvb, &offset, nlink++);
}
dissect_roofnet_data(tree, tvb, pinfo, offset+4);
}
void proto_register_roofnet(void)
{
static hf_register_info hf[] = {
{ &hf_roofnet_version,
{ "Version", "roofnet.version",
FT_UINT8, BASE_DEC, NULL, 0x0, "Roofnet Version", HFILL }
},
{ &hf_roofnet_type,
{ "Type", "roofnet.type",
FT_UINT8, BASE_DEC, VALS(roofnet_pt_vals), 0x0, "Roofnet Message Type", HFILL }
},
{ &hf_roofnet_nlinks,
{ "Number of Links", "roofnet.nlinks",
FT_UINT8, BASE_DEC, NULL, 0x0, "Roofnet Number of Links", HFILL }
},
{ &hf_roofnet_next,
{ "Next Link", "roofnet.next",
FT_UINT8, BASE_DEC, NULL, 0x0, "Roofnet Next Link to Use", HFILL }
},
{ &hf_roofnet_ttl,
{ "Time To Live", "roofnet.ttl",
FT_UINT16, BASE_DEC, NULL, 0x0, "Roofnet Time to Live", HFILL }
},
{ &hf_roofnet_cksum,
{ "Checksum", "roofnet.cksum",
FT_UINT16, BASE_DEC, NULL, 0x0, "Roofnet Header Checksum", HFILL }
},
{ &hf_roofnet_flags,
{ "Flags", "roofnet.flags",
FT_UINT16, BASE_DEC, VALS(roofnet_flags_vals), 0x0, "Roofnet Flags", HFILL }
},
{ &hf_roofnet_data_length,
{ "Data Length", "roofnet.datalength",
FT_UINT16, BASE_DEC, NULL, 0x0, "Data Payload Length", HFILL }
},
{ &hf_roofnet_query_dst,
{ "Query Dst", "roofnet.querydst",
FT_IPv4, BASE_NONE, NULL, 0x0, "Roofnet Query Destination", HFILL }
},
{ &hf_roofnet_seq,
{ "Seq", "roofnet.seq",
FT_UINT32, BASE_DEC, NULL, 0x0, "Roofnet Sequential Number", HFILL }
},
#if 0
{ &hf_roofnet_links,
{ "Links", "roofnet.links",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_roofnet_link_src,
{ "Source IP", "roofnet.link.src",
FT_IPv4, BASE_NONE, NULL, 0x0, "Roofnet Message Source", HFILL }
},
{ &hf_roofnet_link_forward,
{ "Forward", "roofnet.link.forward",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_roofnet_link_rev,
{ "Rev", "roofnet.link.rev",
FT_UINT32, BASE_DEC, NULL, 0x0, "Revision Number", HFILL }
},
{ &hf_roofnet_link_seq,
{ "Seq", "roofnet.link.seq",
FT_UINT32, BASE_DEC, NULL, 0x0, "Link Sequential Number", HFILL }
},
{ &hf_roofnet_link_age,
{ "Age", "roofnet.link.age",
FT_UINT32, BASE_DEC, NULL, 0x0, "Information Age", HFILL }
},
{ &hf_roofnet_link_dst,
{ "Dst IP", "roofnet.link.dst",
FT_IPv4, BASE_NONE, NULL, 0x0, "Roofnet Message Destination", HFILL }
}
};
static gint *ett[] = {
&ett_roofnet,
&ett_roofnet_link
};
static ei_register_info ei[] = {
{ &ei_roofnet_too_many_links, { "roofnet.too_many_links", PI_MALFORMED, PI_ERROR, "Too many links", EXPFILL }},
{ &ei_roofnet_too_much_data, { "roofnet.too_much_data", PI_MALFORMED, PI_ERROR, "More payload data than told by Roofnet", EXPFILL }},
};
expert_module_t* expert_roofnet;
proto_roofnet = proto_register_protocol(
"Roofnet Protocol",
"Roofnet",
"roofnet"
);
proto_register_field_array(proto_roofnet, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_roofnet = expert_register_protocol(proto_roofnet);
expert_register_field_array(expert_roofnet, ei, array_length(ei));
}
void proto_reg_handoff_roofnet(void)
{
dissector_handle_t roofnet_handle;
ip_handle = find_dissector("ip");
roofnet_handle = create_dissector_handle(dissect_roofnet, proto_roofnet);
dissector_add_uint("ethertype", 0x0641, roofnet_handle);
dissector_add_uint("ethertype", 0x0643, roofnet_handle);
dissector_add_uint("ethertype", 0x0644, roofnet_handle);
dissector_add_uint("ethertype", 0x0645, roofnet_handle);
}
