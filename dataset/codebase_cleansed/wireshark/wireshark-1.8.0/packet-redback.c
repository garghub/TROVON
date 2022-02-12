static void
dissect_redback(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 l3off, dataoff, proto;
proto_item *ti;
proto_tree *rbtree = NULL;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo,COL_PROTOCOL,"RBN");
dataoff = tvb_get_ntohs(tvb, 20);
l3off = tvb_get_ntohs(tvb, 22);
if (tree) {
ti = proto_tree_add_item(tree, proto_redback, tvb, 0, -1, ENC_NA);
rbtree = proto_item_add_subtree(ti, ett_redback);
proto_tree_add_item(rbtree, hf_redback_context, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, hf_redback_flags, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, hf_redback_circuit, tvb, 8, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, hf_redback_length, tvb, 16, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, hf_redback_protocol, tvb, 18, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, hf_redback_dataoffset, tvb, 20, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, hf_redback_l3offset, tvb, 22, 2, ENC_BIG_ENDIAN);
if (dataoff > 24) {
proto_tree_add_item(rbtree, hf_redback_padding, tvb, 24, dataoff-24, ENC_NA);
}
}
proto = tvb_get_ntohs(tvb, 18);
switch(proto) {
case 0x01:
next_tvb = tvb_new_subset_remaining(tvb, dataoff);
if (dataoff == l3off)
call_dissector(ipv4_handle, next_tvb, pinfo, tree);
else if (dataoff+2 == l3off)
call_dissector(ppp_handle, next_tvb, pinfo, tree);
else if (dataoff+4 == l3off)
call_dissector(ppphdlc_handle, next_tvb, pinfo, tree);
else
call_dissector(ethnofcs_handle, next_tvb, pinfo, tree);
break;
case 0x02:
next_tvb = tvb_new_subset_remaining(tvb, dataoff);
if (l3off > dataoff) {
call_dissector(ethnofcs_handle, next_tvb, pinfo, tree);
} else {
guint8 nlpid = tvb_get_guint8(tvb, dataoff);
if(dissector_try_uint(osinl_subdissector_table, nlpid, next_tvb, pinfo, tree))
break;
next_tvb = tvb_new_subset_remaining(tvb, dataoff+1);
if(dissector_try_uint(osinl_excl_subdissector_table, nlpid, next_tvb, pinfo, tree))
break;
next_tvb = tvb_new_subset_remaining(tvb, dataoff);
call_dissector(data_handle, next_tvb, pinfo, tree);
}
break;
case 0x06: {
guint32 flags;
flags = tvb_get_ntohl(tvb, 4);
if (flags & 0x00400000) {
next_tvb = tvb_new_subset_remaining(tvb, dataoff);
} else {
if (tree)
proto_tree_add_item(rbtree, hf_redback_unknown, tvb, dataoff, 4, ENC_NA);
next_tvb = tvb_new_subset_remaining(tvb, dataoff+4);
}
if (l3off == dataoff) {
call_dissector(ppp_handle, next_tvb, pinfo, tree);
} else {
call_dissector(ethnofcs_handle, next_tvb, pinfo, tree);
}
break;
}
case 0x03:
case 0x04:
case 0x08:
next_tvb = tvb_new_subset_remaining(tvb, dataoff);
call_dissector(ethnofcs_handle, next_tvb, pinfo, tree);
break;
default:
if (tree)
proto_tree_add_text (rbtree, tvb, 24, -1, "Unknown Protocol Data %u", proto);
break;
}
return;
}
void
proto_register_redback(void)
{
static hf_register_info hf[] = {
{ &hf_redback_context,
{ "Context", "redback.context", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_redback_flags,
{ "Flags", "redback.flags", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_redback_circuit,
{ "Circuit", "redback.circuit", FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_redback_length,
{ "Length", "redback.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_redback_protocol,
{ "Protocol", "redback.protocol", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_redback_l3offset,
{ "Layer 3 Offset", "redback.l3offset", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_redback_dataoffset,
{ "Data Offset", "redback.dataoffset", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_redback_padding,
{ "Padding", "redback.padding", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_redback_unknown,
{ "Unknown", "redback.unknown", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_redback
};
proto_redback = proto_register_protocol("Redback", "Redback", "redback");
proto_register_field_array(proto_redback, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_redback(void)
{
dissector_handle_t redback_handle;
osinl_subdissector_table = find_dissector_table("osinl");
osinl_excl_subdissector_table = find_dissector_table("osinl.excl");
ipv4_handle = find_dissector("ip");
data_handle = find_dissector("data");
ethnofcs_handle = find_dissector("eth_withoutfcs");
clnp_handle = find_dissector("clnp");
arp_handle = find_dissector("arp");
ppp_handle = find_dissector("ppp");
ppphdlc_handle = find_dissector("ppp_hdlc");
redback_handle = create_dissector_handle(dissect_redback, proto_redback);
dissector_add_uint("wtap_encap", WTAP_ENCAP_REDBACK, redback_handle);
}
