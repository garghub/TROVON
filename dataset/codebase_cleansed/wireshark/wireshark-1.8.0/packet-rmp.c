static void
dissect_rmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *rmp_tree = NULL;
proto_item *ti = NULL;
guint8 type, len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RMP");
col_clear(pinfo->cinfo, COL_INFO);
type = tvb_get_guint8(tvb, 0);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(type, rmp_type_vals, "Unknown Type"));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_rmp, tvb, 0, -1, ENC_NA);
rmp_tree = proto_item_add_subtree(ti, ett_rmp);
proto_tree_add_uint(rmp_tree, hf_rmp_type, tvb, 0, 1, type);
switch (type) {
case RMP_BOOT_REQ:
proto_tree_add_item(rmp_tree,
hf_rmp_retcode, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_seqnum, tvb, 2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_sessionid, tvb, 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_version, tvb, 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_machtype, tvb, 10, 20, ENC_ASCII|ENC_NA);
if(!tvb_offset_exists(tvb, 30))
return;
len = tvb_get_guint8(tvb, 30);
proto_tree_add_item(rmp_tree,
hf_rmp_filename, tvb, 30, 1, ENC_ASCII|ENC_NA);
if(tvb_offset_exists(tvb, len+31))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, len+31),
pinfo, tree);
break;
case RMP_BOOT_REPL:
proto_tree_add_item(rmp_tree,
hf_rmp_retcode, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_seqnum, tvb, 2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_sessionid, tvb, 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_version, tvb, 8, 2, ENC_BIG_ENDIAN);
len = tvb_get_guint8(tvb, 10);
proto_tree_add_item(rmp_tree,
hf_rmp_filename, tvb, 10, 1, ENC_ASCII|ENC_NA);
if(tvb_offset_exists(tvb, len+11))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, len+11),
pinfo, tree);
break;
case RMP_READ_REQ:
proto_tree_add_item(rmp_tree,
hf_rmp_retcode, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_offset, tvb, 2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_sessionid, tvb, 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_size, tvb, 8, 2, ENC_BIG_ENDIAN);
if(tvb_offset_exists(tvb, 10))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, 10),
pinfo, tree);
break;
case RMP_READ_REPL:
proto_tree_add_item(rmp_tree,
hf_rmp_retcode, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_offset, tvb, 2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rmp_tree,
hf_rmp_sessionid, tvb, 6, 2, ENC_BIG_ENDIAN);
call_dissector(data_handle, tvb_new_subset_remaining(tvb,
8), pinfo, rmp_tree);
break;
case RMP_BOOT_DONE:
proto_tree_add_item(rmp_tree,
hf_rmp_retcode, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(rmp_tree,
tvb, 2, 4, "Reserved");
proto_tree_add_item(rmp_tree,
hf_rmp_sessionid, tvb, 6, 2, ENC_BIG_ENDIAN);
if(tvb_offset_exists(tvb, 8))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, 6),
pinfo, tree);
break;
default:
call_dissector(data_handle, tvb_new_subset_remaining(tvb,
1), pinfo, tree);
}
}
}
void
proto_register_rmp(void)
{
static hf_register_info hf[] = {
{ &hf_rmp_type,
{ "Type", "rmp.type", FT_UINT8, BASE_HEX,
VALS(rmp_type_vals), 0x0, NULL, HFILL }},
{ &hf_rmp_retcode,
{ "Returncode", "rmp.retcode", FT_UINT8, BASE_HEX,
VALS(rmp_error_vals), 0x0, NULL, HFILL }},
{ &hf_rmp_seqnum,
{ "Sequence Number", "rmp.seqnum", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_rmp_sessionid,
{ "Session ID", "rmp.sessionid", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_rmp_version,
{ "Version", "rmp.version", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_rmp_machtype,
{ "Machine Type", "rmp.machtype", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_rmp_filename,
{ "Filename", "rmp.filename", FT_UINT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_rmp_offset,
{ "Offset", "rmp.offset", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_rmp_size,
{ "Size", "rmp.size", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_rmp,
};
proto_rmp = proto_register_protocol(
"HP Remote Maintenance Protocol", "RMP", "rmp");
proto_register_field_array(proto_rmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rmp", dissect_rmp, proto_rmp);
}
void
proto_reg_handoff_rmp(void)
{
dissector_handle_t rmp_handle;
data_handle = find_dissector("data");
rmp_handle = find_dissector("rmp");
dissector_add_uint("hpext.dxsap", HPEXT_DXSAP, rmp_handle);
dissector_add_uint("hpext.dxsap", HPEXT_SXSAP, rmp_handle);
}
