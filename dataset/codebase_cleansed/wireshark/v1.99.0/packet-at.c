static gboolean allowed_chars(tvbuff_t *tvb)
{
gint offset, len;
guint8 val;
len = tvb_length(tvb);
for (offset = 0; offset < len; offset++) {
val = tvb_get_guint8(tvb, offset);
if (!(g_ascii_isprint(val) || (val == 0x0a) || (val == 0x0d)))
return (FALSE);
}
return (TRUE);
}
static gboolean heur_dissect_at(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
const gchar at_magic1[2] = {0x0d, 0x0a};
const gchar at_magic2[3] = {0x0d, 0x0d, 0x0a};
const gchar at_magic3[2] = {'A', 'T'};
if (((tvb_memeql(tvb, 0, at_magic1, sizeof(at_magic1)) == 0) ||
(tvb_memeql(tvb, 0, at_magic2, sizeof(at_magic2)) == 0) ||
(tvb_memeql(tvb, 0, at_magic3, sizeof(at_magic3)) == 0)) &&
allowed_chars(tvb)) {
dissect_at(tvb, pinfo, tree);
return (TRUE);
}
return (FALSE);
}
static void dissect_at(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *at_tree;
gint len;
len = tvb_reported_length(tvb);
col_append_sep_str(pinfo->cinfo, COL_PROTOCOL, "/", "AT");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "AT Command: %s",
tvb_format_text_wsp(tvb, 0, len));
if (tree) {
item = proto_tree_add_item(tree, proto_at, tvb, 0, -1, ENC_NA);
at_tree = proto_item_add_subtree(item, ett_at);
proto_tree_add_item(at_tree, hf_at_command, tvb, 0, len, ENC_ASCII|ENC_NA);
proto_item_append_text(item, ": %s", tvb_format_text_wsp(tvb, 0, len));
}
}
void
proto_register_at_command(void)
{
static hf_register_info hf[] = {
{ &hf_at_command,
{ "AT Command", "at.command", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_at
};
proto_at = proto_register_protocol("AT Command", "AT", "at");
proto_register_field_array(proto_at, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("at", dissect_at, proto_at);
}
void
proto_reg_handoff_at_command(void)
{
heur_dissector_add("usb.bulk", heur_dissect_at, proto_at);
heur_dissector_add("usb.control", heur_dissect_at, proto_at);
}
