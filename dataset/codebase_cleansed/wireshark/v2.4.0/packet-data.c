static int
dissect_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint bytes;
if (tree) {
bytes = tvb_captured_length(tvb);
if (bytes > 0) {
tvbuff_t *data_tvb;
proto_item *ti;
proto_tree *data_tree;
if (new_pane) {
guint8 *real_data = (guint8 *)tvb_memdup(pinfo->pool, tvb, 0, bytes);
data_tvb = tvb_new_child_real_data(tvb,real_data,bytes,bytes);
add_new_data_source(pinfo, data_tvb, "Not dissected data bytes");
} else {
data_tvb = tvb;
}
ti = proto_tree_add_protocol_format(tree, proto_data, tvb,
0,
bytes, "Data (%d byte%s)", bytes,
plurality(bytes, "", "s"));
data_tree = proto_item_add_subtree(ti, ett_data);
proto_tree_add_item(data_tree, &hfi_data_data, data_tvb, 0, bytes, ENC_NA);
if (show_as_text) {
proto_tree_add_item(data_tree, &hfi_data_text, data_tvb, 0, bytes, ENC_ASCII|ENC_NA);
}
if(generate_md5_hash) {
const guint8 *cp;
guint8 digest[HASH_MD5_LENGTH];
const gchar *digest_string;
cp = tvb_get_ptr(tvb, 0, bytes);
gcry_md_hash_buffer(GCRY_MD_MD5, digest, cp, bytes);
digest_string = bytestring_to_str(wmem_packet_scope(), digest, HASH_MD5_LENGTH, '\0');
ti = proto_tree_add_string(data_tree, &hfi_data_md5_hash, tvb, 0, 0, digest_string);
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_int(data_tree, &hfi_data_len, data_tvb, 0, 0, bytes);
PROTO_ITEM_SET_GENERATED (ti);
}
}
return tvb_captured_length(tvb);
}
void
proto_register_data(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_data_data,
&hfi_data_text,
&hfi_data_md5_hash,
&hfi_data_len,
};
#endif
static gint *ett[] = {
&ett_data
};
module_t *module_data;
proto_data = proto_register_protocol (
"Data",
"Data",
"data"
);
register_dissector("data", dissect_data, proto_data);
proto_register_fields(proto_data, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
module_data = prefs_register_protocol( proto_data, NULL);
prefs_register_bool_preference(module_data,
"datapref.newpane",
"Show not dissected data on new Packet Bytes pane",
"Show not dissected data on new Packet Bytes pane",
&new_pane);
prefs_register_bool_preference(module_data,
"show_as_text",
"Show data as text",
"Show data as text in the Packet Details pane",
&show_as_text);
prefs_register_bool_preference(module_data,
"md5_hash",
"Generate MD5 hash",
"Whether or not MD5 hashes should be generated and shown for each payload.",
&generate_md5_hash);
proto_set_cant_toggle(proto_data);
}
