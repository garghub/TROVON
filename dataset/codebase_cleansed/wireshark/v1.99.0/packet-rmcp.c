static int
dissect_rmcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *rmcp_tree = NULL, *field_tree;
proto_item *ti;
tvbuff_t *next_tvb;
guint8 rmcp_class;
const gchar *class_str;
guint8 type;
guint len;
if (!tvb_bytes_exist(tvb, 3, 1))
return 0;
rmcp_class = tvb_get_guint8(tvb, 3);
type = (rmcp_class & RMCP_TYPE_MASK) >> 7;
rmcp_class &= RMCP_CLASS_MASK;
class_str = try_val_to_str(rmcp_class, rmcp_class_vals);
if (class_str == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RMCP");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s, Class: %s",
val_to_str(type, rmcp_type_vals, "Unknown (0x%02x)"),
class_str);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_rmcp, tvb, 0, 4,
"Remote Management Control Protocol, Class: %s",
class_str);
rmcp_tree = proto_item_add_subtree(ti, ett_rmcp);
proto_tree_add_item(rmcp_tree, hf_rmcp_version, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rmcp_tree, hf_rmcp_sequence, tvb, 2, 1, ENC_LITTLE_ENDIAN);
field_tree = proto_tree_add_subtree_format(rmcp_tree, tvb, 3, 1,
ett_rmcp_typeclass, NULL, "Type: %s, Class: %s",
val_to_str(type, rmcp_type_vals, "Unknown (0x%02x)"),
class_str);
proto_tree_add_item(field_tree, hf_rmcp_class, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(field_tree, hf_rmcp_type, tvb, 3, 1, ENC_LITTLE_ENDIAN);
}
if (!type){
next_tvb = tvb_new_subset_remaining(tvb, 4);
if (!dissector_try_uint(rmcp_dissector_table, rmcp_class, next_tvb, pinfo,
tree)) {
len = call_dissector(data_handle, next_tvb, pinfo, tree);
if (len < tvb_length(next_tvb)) {
proto_tree_add_item(tree, hf_rmcp_trailer, tvb, 4 + len, -1, ENC_NA);
}
}
}
return tvb_length(tvb);
}
static int
dissect_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *rsp_tree = NULL;
proto_item *ti;
tvbuff_t *next_tvb;
int offset = 0;
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_rsp, tvb, offset, 8,
"RMCP Security-extension Protocol");
rsp_tree = proto_item_add_subtree(ti, ett_rsp);
proto_tree_add_item(rsp_tree, hf_rsp_session_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rsp_tree, hf_rsp_sequence, tvb, offset, 4, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(tvb, 8);
dissect_rmcp(next_tvb, pinfo, tree, NULL);
return tvb_length(tvb);
}
void
proto_register_rmcp(void)
{
static hf_register_info hf[] = {
{ &hf_rmcp_version, {
"Version", "rmcp.version",
FT_UINT8, BASE_HEX, NULL, 0,
"RMCP Version", HFILL }},
{ &hf_rmcp_sequence, {
"Sequence", "rmcp.sequence",
FT_UINT8, BASE_HEX, NULL, 0,
"RMCP Sequence", HFILL }},
{ &hf_rmcp_class, {
"Class", "rmcp.class",
FT_UINT8, BASE_HEX,
VALS(rmcp_class_vals), RMCP_CLASS_MASK,
"RMCP Class", HFILL }},
{ &hf_rmcp_type, {
"Message Type", "rmcp.type",
FT_UINT8, BASE_HEX,
VALS(rmcp_type_vals), RMCP_TYPE_MASK,
"RMCP Message Type", HFILL }},
{ &hf_rmcp_trailer, {
"RSP Trailer", "rmcp.trailer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_rmcp,
&ett_rmcp_typeclass
};
proto_rmcp = proto_register_protocol(
"Remote Management Control Protocol", "RMCP", "rmcp");
proto_register_field_array(proto_rmcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
rmcp_dissector_table = register_dissector_table(
"rmcp.class", "RMCP Class", FT_UINT8, BASE_HEX);
}
void
proto_register_rsp(void)
{
static hf_register_info hf[] = {
{ &hf_rsp_session_id, {
"Session ID", "rsp.session_id",
FT_UINT32, BASE_HEX, NULL, 0,
"RSP session ID", HFILL }},
{ &hf_rsp_sequence, {
"Sequence", "rsp.sequence",
FT_UINT32, BASE_HEX, NULL, 0,
"RSP sequence", HFILL }},
};
static gint *ett[] = {
&ett_rsp
};
proto_rsp = proto_register_protocol(
"RMCP Security-extensions Protocol", "RSP", "rsp");
proto_register_field_array(proto_rsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_rmcp(void)
{
dissector_handle_t rmcp_handle;
data_handle = find_dissector("data");
rmcp_handle = new_create_dissector_handle(dissect_rmcp, proto_rmcp);
dissector_add_uint("udp.port", UDP_PORT_RMCP, rmcp_handle);
}
void
proto_reg_handoff_rsp(void)
{
dissector_handle_t rsp_handle;
rsp_handle = new_create_dissector_handle(dissect_rsp, proto_rsp);
dissector_add_uint("udp.port", UDP_PORT_RMCP_SECURE, rsp_handle);
}
