static void
dissect_cups(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *cups_tree = NULL;
proto_tree *ptype_subtree = NULL;
proto_item *ti = NULL;
gint offset = 0;
gint next_offset;
guint len;
const guint8 *str;
cups_ptype_t ptype;
unsigned int state;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_CUPS);
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_cups, tvb, offset, -1, ENC_NA);
cups_tree = proto_item_add_subtree(ti, ett_cups);
ptype = get_hex_uint(tvb, offset, &next_offset);
len = next_offset - offset;
if (len != 0) {
ti = proto_tree_add_uint(cups_tree, hf_cups_ptype, tvb, offset, len, ptype);
ptype_subtree = proto_item_add_subtree(ti, ett_cups_ptype);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_default, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_implicit, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_variable, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_large, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_medium, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_small, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_sort, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_bind, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_cover, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_punch, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_collate, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_copies, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_staple, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_duplex, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_color, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_bw, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_remote, tvb, offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ptype_subtree, hf_cups_ptype_class, tvb, offset, len, ENC_BIG_ENDIAN);
}
offset = next_offset;
if (!skip_space(tvb, offset, &next_offset))
return;
offset = next_offset;
state = get_hex_uint(tvb, offset, &next_offset);
len = next_offset - offset;
if (len != 0) {
proto_tree_add_uint(cups_tree, hf_cups_state, tvb, offset, len, state);
}
offset = next_offset;
if (!skip_space(tvb, offset, &next_offset))
return;
offset = next_offset;
str = get_unquoted_string(tvb, offset, &next_offset, &len);
if (str == NULL)
return;
proto_tree_add_text(cups_tree, tvb, offset, len,
"URI: %.*s", (guint16) len, str);
col_add_fstr(pinfo->cinfo, COL_INFO, "%.*s (%s)",
(guint16) len, str, val_to_str(state, cups_state_values, "0x%x"));
offset = next_offset;
if (!cups_tree)
return;
if (!skip_space(tvb, offset, &next_offset))
return;
offset = next_offset;
str = get_quoted_string(tvb, offset, &next_offset, &len);
if (str == NULL)
return;
proto_tree_add_text(cups_tree, tvb, offset+1, len,
"Location: \"%.*s\"", (guint16) len, str);
offset = next_offset;
if (!skip_space(tvb, offset, &next_offset))
return;
offset = next_offset;
str = get_quoted_string(tvb, offset, &next_offset, &len);
if (str == NULL)
return;
proto_tree_add_text(cups_tree, tvb, offset+1, len,
"Information: \"%.*s\"", (guint16) len, str);
offset = next_offset;
if (!skip_space(tvb, offset, &next_offset))
return;
offset = next_offset;
str = get_quoted_string(tvb, offset, &next_offset, &len);
if (str == NULL)
return;
proto_tree_add_text(cups_tree, tvb, offset+1, len,
"Make and model: \"%.*s\"", (guint16) len, str);
}
static guint
get_hex_uint(tvbuff_t *tvb, gint offset, gint *next_offset)
{
int c;
guint u = 0;
while (isxdigit(c = tvb_get_guint8(tvb, offset))) {
if (isdigit(c))
c -= '0';
else if (isupper(c))
c -= 'A' - 10;
else if (islower(c))
c -= 'a' - 10;
else
c = 0;
u = 16*u + c;
offset++;
}
*next_offset = offset;
return u;
}
static gboolean
skip_space(tvbuff_t *tvb, gint offset, gint *next_offset)
{
int c;
while ((c = tvb_get_guint8(tvb, offset)) == ' ')
offset++;
if (c == '\r' || c == '\n')
return FALSE;
*next_offset = offset;
return TRUE;
}
static const guint8*
get_quoted_string(tvbuff_t *tvb, gint offset, gint *next_offset, guint *len)
{
int c;
const guint8* s = NULL;
guint l = 0;
gint o;
c = tvb_get_guint8(tvb, offset);
if (c == '"') {
o = tvb_find_guint8(tvb, offset+1, -1, '"');
if (o != -1) {
offset++;
l = o - offset;
s = tvb_get_ptr(tvb, offset, l);
offset = o + 1;
}
}
*next_offset = offset;
*len = l;
return s;
}
static const guint8*
get_unquoted_string(tvbuff_t *tvb, gint offset, gint *next_offset, guint *len)
{
const guint8* s = NULL;
guint l = 0;
gint o;
o = tvb_pbrk_guint8(tvb, offset, -1, " \t\r\n", NULL);
if (o != -1) {
l = o - offset;
s = tvb_get_ptr(tvb, offset, l);
offset = o;
}
*next_offset = offset;
*len = l;
return s;
}
void
proto_register_cups(void)
{
static hf_register_info hf[] = {
{ &hf_cups_ptype,
{ "Type", "cups.ptype", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_cups_ptype_default,
{ "Default printer on network", "cups.ptype.default", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_DEFAULT, NULL, HFILL }},
{ &hf_cups_ptype_implicit,
{ "Class", "cups.ptype.implicit", FT_BOOLEAN, 32,
TFS(&tfs_implicit_explicit), CUPS_PRINTER_IMPLICIT, NULL, HFILL }},
{ &hf_cups_ptype_variable,
{ "Can print variable sizes", "cups.ptype.variable", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_VARIABLE, NULL, HFILL }},
{ &hf_cups_ptype_large,
{ "Can print up to 36x48 inches", "cups.ptype.large", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_LARGE, NULL, HFILL }},
{ &hf_cups_ptype_medium,
{ "Can print up to 18x24 inches", "cups.ptype.medium", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_MEDIUM, NULL, HFILL }},
{ &hf_cups_ptype_small,
{ "Can print up to 9x14 inches", "cups.ptype.small", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_SMALL, NULL, HFILL }},
{ &hf_cups_ptype_sort,
{ "Can sort", "cups.ptype.sort", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_SORT, NULL, HFILL }},
{ &hf_cups_ptype_bind,
{ "Can bind", "cups.ptype.bind", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_BIND, NULL, HFILL }},
{ &hf_cups_ptype_cover,
{ "Can cover", "cups.ptype.cover", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_COVER, NULL, HFILL }},
{ &hf_cups_ptype_punch,
{ "Can punch holes", "cups.ptype.punch", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_PUNCH, NULL, HFILL }},
{ &hf_cups_ptype_collate,
{ "Can do fast collating", "cups.ptype.collate", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_COLLATE, NULL, HFILL }},
{ &hf_cups_ptype_copies,
{ "Can do fast copies", "cups.ptype.copies", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_COPIES, NULL, HFILL }},
{ &hf_cups_ptype_staple,
{ "Can staple", "cups.ptype.staple", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_STAPLE, NULL, HFILL }},
{ &hf_cups_ptype_duplex,
{ "Can duplex", "cups.ptype.duplex", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_DUPLEX, NULL, HFILL }},
{ &hf_cups_ptype_color,
{ "Can print color", "cups.ptype.color", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_COLOR, NULL, HFILL }},
{ &hf_cups_ptype_bw,
{ "Can print black", "cups.ptype.bw", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_BW, NULL, HFILL }},
{ &hf_cups_ptype_remote,
{ "Remote", "cups.ptype.remote", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), CUPS_PRINTER_REMOTE, NULL, HFILL }},
{ &hf_cups_ptype_class,
{ "Class", "cups.ptype.class", FT_BOOLEAN, 32,
TFS(&tfs_printer_class), CUPS_PRINTER_CLASS, NULL, HFILL }},
{ &hf_cups_state,
{ "State", "cups.state", FT_UINT8, BASE_HEX,
VALS(cups_state_values), 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_cups,
&ett_cups_ptype
};
proto_cups = proto_register_protocol(
"Common Unix Printing System (CUPS) Browsing Protocol",
"CUPS", "cups");
proto_register_field_array(proto_cups, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_cups(void)
{
dissector_handle_t cups_handle;
cups_handle = create_dissector_handle(dissect_cups, proto_cups);
dissector_add_uint("udp.port", UDP_PORT_CUPS, cups_handle);
}
