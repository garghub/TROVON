static int
dissect_mrdisc_mra(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset)
{
guint16 num;
proto_tree_add_item(parent_tree, hf_advint, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
igmp_checksum(parent_tree, tvb, hf_checksum, hf_checksum_bad, pinfo, 0);
offset += 2;
offset += 2;
num = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(parent_tree, hf_numopts, tvb,
offset, 2, num);
offset += 2;
while (num--) {
proto_tree *tree;
proto_item *item;
guint8 type,len;
int old_offset = offset;
item = proto_tree_add_item(parent_tree, hf_options,
tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_options);
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_option, tvb, offset, 1, type);
offset += 1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_option_len, tvb, offset, 1, len);
offset += 1;
switch (type) {
case MRDISC_QI:
if (item) {
proto_item_set_text(item,"Option: %s == %d",
val_to_str(type, mrdisc_options, "unknown %x"),
tvb_get_ntohs(tvb, offset));
}
if (len != 2)
THROW(ReportedBoundsError);
proto_tree_add_item(tree, hf_qi, tvb, offset, len,
ENC_BIG_ENDIAN);
offset += len;
break;
case MRDISC_RV:
if (item) {
proto_item_set_text(item,"Option: %s == %d",
val_to_str(type, mrdisc_options, "unknown %x"),
tvb_get_ntohs(tvb, offset));
}
if (len != 2)
THROW(ReportedBoundsError);
proto_tree_add_item(tree, hf_rv, tvb, offset, len,
ENC_BIG_ENDIAN);
offset += len;
break;
default:
if (item) {
proto_item_set_text(item,"Option: unknown");
}
proto_tree_add_item(tree, hf_option_bytes,
tvb, offset, len, ENC_NA);
offset += len;
}
if (item) {
proto_item_set_len(item, offset-old_offset);
}
}
return offset;
}
static int
dissect_mrdisc_mrst(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset)
{
offset += 1;
igmp_checksum(parent_tree, tvb, hf_checksum, hf_checksum_bad, pinfo, 0);
offset += 2;
return offset;
}
static int
dissect_mrdisc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_tree *tree;
proto_item *item;
guint8 type;
int offset = 0;
guint32 dst = g_htonl(MC_ALL_ROUTERS);
if (memcmp(pinfo->dst.data, &dst, 4))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MRDISC");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(parent_tree, proto_mrdisc, tvb, offset, 0, ENC_NA);
tree = proto_item_add_subtree(item, ett_mrdisc);
type = tvb_get_guint8(tvb, offset);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(type, mrdisc_types,
"Unknown Type:0x%02x"));
proto_tree_add_uint(tree, hf_type, tvb, offset, 1, type);
offset += 1;
switch (type) {
case MRDISC_MRA:
offset = dissect_mrdisc_mra(tvb, pinfo, tree, offset);
break;
case MRDISC_MRS:
case MRDISC_MRT:
offset = dissect_mrdisc_mrst(tvb, pinfo, tree, offset);
break;
}
return offset;
}
void
proto_register_mrdisc(void)
{
static hf_register_info hf[] = {
{ &hf_type,
{ "Type", "mrdisc.type", FT_UINT8, BASE_HEX,
VALS(mrdisc_types), 0, "MRDISC Packet Type", HFILL }},
{ &hf_checksum,
{ "Checksum", "mrdisc.checksum", FT_UINT16, BASE_HEX,
NULL, 0, "MRDISC Checksum", HFILL }},
{ &hf_checksum_bad,
{ "Bad Checksum", "mrdisc.checksum_bad", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Bad MRDISC Checksum", HFILL }},
{ &hf_advint,
{ "Advertising Interval", "mrdisc.adv_int", FT_UINT8, BASE_DEC,
NULL, 0, "MRDISC Advertising Interval in seconds", HFILL }},
{ &hf_numopts,
{ "Number Of Options", "mrdisc.num_opts", FT_UINT16, BASE_DEC,
NULL, 0, "MRDISC Number Of Options", HFILL }},
{ &hf_options,
{ "Options", "mrdisc.options", FT_NONE, BASE_NONE,
NULL, 0, "MRDISC Options", HFILL }},
{ &hf_option,
{ "Option", "mrdisc.option", FT_UINT8, BASE_DEC,
VALS(mrdisc_options), 0, "MRDISC Option Type", HFILL }},
{ &hf_option_len,
{ "Length", "mrdisc.opt_len", FT_UINT8, BASE_DEC,
NULL, 0, "MRDISC Option Length", HFILL }},
{ &hf_qi,
{ "Query Interval", "mrdisc.query_int", FT_UINT16, BASE_DEC,
NULL, 0, "MRDISC Query Interval", HFILL }},
{ &hf_rv,
{ "Robustness Variable", "mrdisc.rob_var", FT_UINT16, BASE_DEC,
NULL, 0, "MRDISC Robustness Variable", HFILL }},
{ &hf_option_bytes,
{ "Data", "mrdisc.option_data", FT_BYTES, BASE_NONE,
NULL, 0, "MRDISC Unknown Option Data", HFILL }},
};
static gint *ett[] = {
&ett_mrdisc,
&ett_options,
};
proto_mrdisc = proto_register_protocol("Multicast Router DISCovery protocol", "MRDISC", "mrdisc");
proto_register_field_array(proto_mrdisc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mrdisc(void)
{
dissector_handle_t mrdisc_handle;
mrdisc_handle = new_create_dissector_handle(dissect_mrdisc, proto_mrdisc);
dissector_add_uint("igmp.type", IGMP_TYPE_0x24, mrdisc_handle);
dissector_add_uint("igmp.type", IGMP_TYPE_0x25, mrdisc_handle);
dissector_add_uint("igmp.type", IGMP_TYPE_0x26, mrdisc_handle);
}
