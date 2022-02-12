static int
dissect_icap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *icap_tree = NULL;
proto_item *ti = NULL;
proto_item *hidden_item;
tvbuff_t *new_tvb;
gint offset = 0;
const guchar *line;
gint next_offset;
const guchar *linep, *lineend;
int linelen;
guchar c;
icap_type_t icap_type;
int datalen;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICAP");
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
icap_type = ICAP_OTHER;
if (is_icap_message(line, linelen, &icap_type))
col_add_str(pinfo->cinfo, COL_INFO,
format_text(line, linelen));
else
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
if (tree) {
ti = proto_tree_add_item(tree, proto_icap, tvb, offset, -1,
ENC_NA);
icap_tree = proto_item_add_subtree(ti, ett_icap);
}
icap_type = ICAP_OTHER;
while (tvb_offset_exists(tvb, offset)) {
gboolean is_icap = FALSE;
gboolean loop_done = FALSE;
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset,
FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
lineend = line + linelen;
if (is_icap_message(line, linelen, &icap_type)) {
goto is_icap_header;
}
if (linelen == 0) {
goto is_icap_header;
}
linep = line;
loop_done = FALSE;
while (linep < lineend && (!loop_done)) {
c = *linep++;
if (!g_ascii_isprint(c)) {
is_icap = FALSE;
break;
}
switch (c) {
case '(':
case ')':
case '<':
case '>':
case '@':
case ',':
case ';':
case '\\':
case '"':
case '/':
case '[':
case ']':
case '?':
case '=':
case '{':
case '}':
is_icap = FALSE;
loop_done = TRUE;
break;
case ':':
goto is_icap_header;
}
}
if (!is_icap)
break;
is_icap_header:
proto_tree_add_format_text(icap_tree, tvb, offset, next_offset - offset);
offset = next_offset;
}
if (tree) {
switch (icap_type) {
case ICAP_OPTIONS:
hidden_item = proto_tree_add_boolean(icap_tree,
hf_icap_options, tvb, 0, 0, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
case ICAP_REQMOD:
hidden_item = proto_tree_add_boolean(icap_tree,
hf_icap_reqmod, tvb, 0, 0, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
case ICAP_RESPMOD:
hidden_item = proto_tree_add_boolean(icap_tree,
hf_icap_respmod, tvb, 0, 0, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
case ICAP_RESPONSE:
hidden_item = proto_tree_add_boolean(icap_tree,
hf_icap_response, tvb, 0, 0, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
case ICAP_OTHER:
default:
break;
}
}
datalen = tvb_reported_length_remaining(tvb, offset);
if (datalen > 0) {
if(http_handle){
new_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(http_handle, new_tvb, pinfo, icap_tree);
}
}
return tvb_captured_length(tvb);
}
static int
is_icap_message(const guchar *data, int linelen, icap_type_t *type)
{
#define ICAP_COMPARE(string, length, msgtype) { \
if (strncmp(data, string, length) == 0) { \
if (*type == ICAP_OTHER) \
*type = msgtype; \
return TRUE; \
} \
}
if (linelen >= 5) {
ICAP_COMPARE("ICAP/", 5, ICAP_RESPONSE);
}
if (linelen >= 7) {
ICAP_COMPARE("REQMOD ", 7, ICAP_REQMOD);
}
if (linelen >= 8) {
ICAP_COMPARE("OPTIONS ", 8, ICAP_OPTIONS);
ICAP_COMPARE("RESPMOD ", 8, ICAP_RESPMOD);
}
return FALSE;
#undef ICAP_COMPARE
}
void
proto_register_icap(void)
{
static hf_register_info hf[] = {
{ &hf_icap_response,
{ "Response", "icap.response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if ICAP response", HFILL }},
{ &hf_icap_reqmod,
{ "Reqmod", "icap.reqmod",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if ICAP reqmod", HFILL }},
{ &hf_icap_respmod,
{ "Respmod", "icap.respmod",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if ICAP respmod", HFILL }},
{ &hf_icap_options,
{ "Options", "icap.options",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if ICAP options", HFILL }},
#if 0
{ &hf_icap_other,
{ "Other", "icap.other",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if ICAP other", HFILL }},
#endif
};
static gint *ett[] = {
&ett_icap,
};
proto_icap = proto_register_protocol(
"Internet Content Adaptation Protocol",
"ICAP", "icap");
proto_register_field_array(proto_icap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_icap(void)
{
dissector_handle_t icap_handle;
http_handle = find_dissector_add_dependency("http", proto_icap);
icap_handle = create_dissector_handle(dissect_icap, proto_icap);
dissector_add_uint("tcp.port", TCP_PORT_ICAP, icap_handle);
}
