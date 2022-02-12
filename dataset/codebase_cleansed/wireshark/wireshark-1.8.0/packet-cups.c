static void
dissect_cups(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *cups_tree = 0;
proto_tree *ptype_subtree = 0;
proto_item *ti = 0;
gint offset = 0;
gint next_offset;
guint len;
unsigned int u;
const guint8 *str;
cups_ptype_t ptype;
unsigned int state;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_CUPS);
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_cups, tvb, offset, -1,
ENC_NA);
cups_tree = proto_item_add_subtree(ti, ett_cups);
}
ptype = get_hex_uint(tvb, offset, &next_offset);
len = next_offset - offset;
if (len != 0) {
if (cups_tree) {
ti = proto_tree_add_uint(cups_tree, hf_cups_ptype,
tvb, offset, len, ptype);
ptype_subtree = proto_item_add_subtree(ti,
ett_cups_ptype);
for (u = 0; u < N_CUPS_PTYPE_BITS; u++) {
proto_tree_add_text(ptype_subtree, tvb,
offset, len, "%s",
decode_boolean_bitfield(ptype,
cups_ptype_bits[u].bit, sizeof (ptype)*8,
cups_ptype_bits[u].on_string,
cups_ptype_bits[u].off_string));
}
}
}
offset = next_offset;
if (!skip_space(tvb, offset, &next_offset))
return;
offset = next_offset;
state = get_hex_uint(tvb, offset, &next_offset);
len = next_offset - offset;
if (len != 0) {
if (cups_tree)
proto_tree_add_uint(cups_tree, hf_cups_state,
tvb, offset, len, state);
}
offset = next_offset;
if (!skip_space(tvb, offset, &next_offset))
return;
offset = next_offset;
str = get_unquoted_string(tvb, offset, &next_offset, &len);
if (str == NULL)
return;
if (cups_tree)
proto_tree_add_text(cups_tree, tvb, offset, len,
"URI: %.*s",
(guint16) len, str);
col_add_fstr(pinfo->cinfo, COL_INFO,
"%.*s (%s)",
(guint16) len, str,
val_to_str(state, cups_state_values, "0x%x"));
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
"Location: \"%.*s\"",
(guint16) len, str);
offset = next_offset;
if (!skip_space(tvb, offset, &next_offset))
return;
offset = next_offset;
str = get_quoted_string(tvb, offset, &next_offset, &len);
if (str == NULL)
return;
proto_tree_add_text(cups_tree, tvb, offset+1, len,
"Information: \"%.*s\"",
(guint16) len, str);
offset = next_offset;
if (!skip_space(tvb, offset, &next_offset))
return;
offset = next_offset;
str = get_quoted_string(tvb, offset, &next_offset, &len);
if (str == NULL)
return;
proto_tree_add_text(cups_tree, tvb, offset+1, len,
"Make and model: \"%.*s\"",
(guint16) len, str);
offset = next_offset;
return;
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
