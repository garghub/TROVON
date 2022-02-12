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
ti = proto_tree_add_item(tree, hfi_redback, tvb, 0, -1, ENC_NA);
rbtree = proto_item_add_subtree(ti, ett_redback);
proto_tree_add_item(rbtree, &hfi_redback_context, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, &hfi_redback_flags, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, &hfi_redback_circuit, tvb, 8, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, &hfi_redback_length, tvb, 16, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, &hfi_redback_protocol, tvb, 18, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, &hfi_redback_dataoffset, tvb, 20, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rbtree, &hfi_redback_l3offset, tvb, 22, 2, ENC_BIG_ENDIAN);
if (dataoff > 24) {
proto_tree_add_item(rbtree, &hfi_redback_padding, tvb, 24, dataoff-24, ENC_NA);
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
if(dissector_try_uint(osinl_incl_subdissector_table, nlpid, next_tvb, pinfo, tree))
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
proto_tree_add_item(rbtree, &hfi_redback_unknown, tvb, dataoff, 4, ENC_NA);
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
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_redback_context,
&hfi_redback_flags,
&hfi_redback_circuit,
&hfi_redback_length,
&hfi_redback_protocol,
&hfi_redback_l3offset,
&hfi_redback_dataoffset,
&hfi_redback_padding,
&hfi_redback_unknown,
};
#endif
static gint *ett[] = {
&ett_redback
};
int proto_redback;
proto_redback = proto_register_protocol("Redback", "Redback", "redback");
hfi_redback = proto_registrar_get_nth(proto_redback);
proto_register_fields(proto_redback, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
redback_handle = create_dissector_handle(dissect_redback, proto_redback);
}
void
proto_reg_handoff_redback(void)
{
osinl_incl_subdissector_table = find_dissector_table("osinl.incl");
osinl_excl_subdissector_table = find_dissector_table("osinl.excl");
ipv4_handle = find_dissector("ip");
data_handle = find_dissector("data");
ethnofcs_handle = find_dissector("eth_withoutfcs");
clnp_handle = find_dissector("clnp");
arp_handle = find_dissector("arp");
ppp_handle = find_dissector("ppp");
ppphdlc_handle = find_dissector("ppp_hdlc");
dissector_add_uint("wtap_encap", WTAP_ENCAP_REDBACK, redback_handle);
}
