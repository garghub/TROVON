static gboolean get_next_item(tvbuff_t *tvb, gint offset, gint maxlen, guint8 *str, gint *next_offset, guint *len)
{
guint idx = 0;
guint8 ch;
while (maxlen > 1) {
ch = tvb_get_guint8(tvb, offset+idx);
if (ch == ';' || ch == '\r' || ch == '\n')
break;
if (idx==MAXLEN) {
*next_offset = offset + idx;
*len = idx;
return FALSE;
}
str[idx++] = ch;
maxlen--;
}
str[idx] = '\0';
*next_offset = offset + idx;
*len = idx;
return TRUE;
}
static void dissect_xcsl_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
guint offset = 0;
gint length_remaining;
guint8 idx;
gboolean request;
guint8 par;
guint8 str[MAXLEN];
guint8 result;
const gchar *code;
guint len;
gint next_offset;
proto_tree *xcsl_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Xcsl");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
proto_item *xcsl_item;
xcsl_item = proto_tree_add_item(tree, hfi_xcsl, tvb, offset, -1, ENC_NA);
xcsl_tree = proto_item_add_subtree(xcsl_item, ett_xcsl);
}
idx = 0;
par = 0;
request = FALSE;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
length_remaining = tvb_ensure_length_remaining(tvb, offset);
if ( length_remaining == -1 ) {
return;
}
if (!(get_next_item(tvb, offset, length_remaining, str, &next_offset, &len))) {
return;
}
if ( strlen(str) == 0 ) {
offset = next_offset + 1;
continue;
}
switch (idx) {
case 0:
proto_tree_add_item(xcsl_tree, &hfi_xcsl_protocol_version, tvb, offset, len, ENC_ASCII|ENC_NA);
break;
case 1:
if ( isdigit(str[0]) ) {
proto_tree_add_item(xcsl_tree, &hfi_xcsl_transaction_id, tvb, offset, len, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_item(xcsl_tree, &hfi_xcsl_information, tvb, offset, len, ENC_ASCII|ENC_NA);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",str);
break;
case 2:
if ( isdigit(str[0]) ) {
proto_item *xcsl_item;
request = FALSE;
result = atoi(str);
if ( result >= XCSL_NONE ) {
result = XCSL_UNDEFINED;
}
code = val_to_str(result, xcsl_action_vals, "Unknown: %d");
xcsl_item = proto_tree_add_item(xcsl_tree, &hfi_xcsl_result, tvb, offset, len, ENC_ASCII|ENC_NA);
proto_item_append_text(xcsl_item, " (%s)", code);
if (result != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s] ", code);
} else {
request = TRUE;
proto_tree_add_item(xcsl_tree, &hfi_xcsl_command, tvb, offset, len, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", str);
}
break;
default:
proto_tree_add_item(xcsl_tree, &hfi_xcsl_parameter, tvb, offset, len, ENC_ASCII|ENC_NA);
if ( request == TRUE ) {
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s ",str);
} else {
if (par == 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, "reply: %s ",str);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s ",str);
}
}
par++;
break;
}
offset = next_offset + 1;
idx++;
}
return;
}
static gboolean dissect_xcsl_tcp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
gint offset = 0;
guint8 *protocol;
if (tvb_length_remaining (tvb, offset) >= 5) {
protocol = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 5, ENC_ASCII);
if (strncmp(protocol,"xcsl",4) == 0 && (protocol[4] == ';' || protocol[4] == '-')) {
dissect_xcsl_tcp(tvb, pinfo, tree);
return TRUE;
}
}
return FALSE;
}
void proto_register_xcsl(void) {
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_xcsl_protocol_version,
&hfi_xcsl_transaction_id,
&hfi_xcsl_command,
&hfi_xcsl_result,
&hfi_xcsl_parameter,
&hfi_xcsl_information,
};
#endif
static gint *ett[] = {
&ett_xcsl
};
int proto_xcsl;
proto_xcsl = proto_register_protocol("Call Specification Language (Xcsl)", "XCSL", "xcsl");
hfi_xcsl = proto_registrar_get_nth(proto_xcsl);
proto_register_fields(proto_xcsl, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_xcsl(void) {
heur_dissector_add("tcp", dissect_xcsl_tcp_heur, hfi_xcsl->id);
}
