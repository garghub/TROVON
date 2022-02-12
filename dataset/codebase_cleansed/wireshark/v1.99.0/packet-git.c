static gboolean get_packet_length(tvbuff_t *tvb, int offset,
guint16 *length)
{
guint8 *lenstr;
lenstr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 4, ENC_ASCII);
return (sscanf(lenstr, "%hx", length) == 1);
}
static guint
get_git_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint16 plen;
if (!get_packet_length(tvb, offset, &plen))
return 0;
if (plen == 0) {
return 4;
}
return plen;
}
static int
dissect_git_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *git_tree;
proto_item *ti;
int offset = 0;
guint16 plen;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GIT");
col_set_str(pinfo->cinfo, COL_INFO, "Git Smart Protocol");
ti = proto_tree_add_item(tree, proto_git, tvb, offset, -1, ENC_NA);
git_tree = proto_item_add_subtree(ti, ett_git);
if (!get_packet_length(tvb, 0, &plen))
return 0;
if (plen == 0) {
proto_tree_add_uint(git_tree, hf_git_packet_terminator, tvb, offset,
4, plen);
return 4;
}
if (git_tree)
{
proto_tree_add_uint(git_tree, hf_git_packet_len, tvb, offset,
4, plen);
proto_tree_add_item(git_tree, hf_git_packet_data, tvb, offset+4,
plen-4, ENC_NA);
}
return tvb_length(tvb);
}
static int
dissect_git(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, git_desegment, 4, get_git_pdu_len,
dissect_git_pdu, data);
return tvb_length(tvb);
}
void
proto_register_git(void)
{
static hf_register_info hf[] = {
{ &hf_git_packet_len,
{ "Packet length", "git.length", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_git_packet_data,
{ "Packet data", "git.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_git_packet_terminator,
{ "Terminator packet", "git.terminator", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
};
static gint *ett[] = {
&ett_git,
};
module_t *git_module;
proto_git = proto_register_protocol("Git Smart Protocol", "GIT", "git");
proto_register_field_array(proto_git, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
git_handle = new_register_dissector("git", dissect_git, proto_git);
git_module = prefs_register_protocol(proto_git, NULL);
prefs_register_bool_preference(git_module, "desegment",
"Reassemble GIT messages spanning multiple TCP segments",
"Whether the GIT dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&git_desegment);
}
void
proto_reg_handoff_git(void)
{
dissector_add_uint("tcp.port", TCP_PORT_GIT, git_handle);
}
