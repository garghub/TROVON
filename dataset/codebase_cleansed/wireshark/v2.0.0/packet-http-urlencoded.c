static int
get_form_key_value(tvbuff_t *tvb, char **ptr, int offset, char stop)
{
const int orig_offset = offset;
char *tmp;
int len;
len = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
guint8 ch;
ch = tvb_get_guint8(tvb, offset);
if (!ch)
return -1;
if (ch == stop)
break;
if (ch == '%') {
offset++;
ch = tvb_get_guint8(tvb, offset);
if (ws_xton(ch) == -1)
return -1;
offset++;
ch = tvb_get_guint8(tvb, offset);
if (ws_xton(ch) == -1)
return -1;
}
len++;
offset++;
}
*ptr = tmp = (char*)wmem_alloc(wmem_packet_scope(), len + 1);
tmp[len] = '\0';
len = 0;
offset = orig_offset;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
guint8 ch;
ch = tvb_get_guint8(tvb, offset);
if (!ch)
return -1;
if (ch == stop)
break;
if (ch == '%') {
guint8 ch1, ch2;
offset++;
ch1 = tvb_get_guint8(tvb, offset);
offset++;
ch2 = tvb_get_guint8(tvb, offset);
tmp[len] = ws_xton(ch1) << 4 | ws_xton(ch2);
} else if (ch == '+')
tmp[len] = ' ';
else
tmp[len] = ch;
len++;
offset++;
}
return offset;
}
static int
dissect_form_urlencoded(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *url_tree;
proto_tree *sub;
proto_item *ti;
gint offset = 0, next_offset;
const char *data_name;
data_name = pinfo->match_string;
if (! (data_name && data_name[0])) {
data_name = (char *)data;
if (! (data_name && data_name[0])) {
data_name = NULL;
}
}
if (data_name)
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "(%s)", data_name);
ti = proto_tree_add_item(tree, hfi_urlencoded, tvb, 0, -1, ENC_NA);
if (data_name)
proto_item_append_text(ti, ": %s", data_name);
url_tree = proto_item_add_subtree(ti, ett_form_urlencoded);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
const int start_offset = offset;
char *key, *value;
ti = proto_tree_add_item(url_tree, &hfi_form_keyvalue, tvb, offset, 0, ENC_NA);
sub = proto_item_add_subtree(ti, ett_form_keyvalue);
next_offset = get_form_key_value(tvb, &key, offset, '=');
if (next_offset == -1)
break;
proto_tree_add_string(sub, &hfi_form_key, tvb, offset, next_offset - offset, key);
proto_item_append_text(sub, ": \"%s\"", key);
offset = next_offset+1;
next_offset = get_form_key_value(tvb, &value, offset, '&');
if (next_offset == -1)
break;
proto_tree_add_string(sub, &hfi_form_value, tvb, offset, next_offset - offset, value);
proto_item_append_text(sub, " = \"%s\"", value);
offset = next_offset+1;
proto_item_set_len(ti, offset - start_offset);
}
return tvb_captured_length(tvb);
}
void
proto_register_http_urlencoded(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_form_keyvalue,
&hfi_form_key,
&hfi_form_value,
};
#endif
static gint *ett[] = {
&ett_form_urlencoded,
&ett_form_keyvalue
};
int proto_urlencoded;
proto_urlencoded = proto_register_protocol("HTML Form URL Encoded", "URL Encoded Form Data", "urlencoded-form");
hfi_urlencoded = proto_registrar_get_nth(proto_urlencoded);
form_urlencoded_handle = new_register_dissector("urlencoded-form", dissect_form_urlencoded, proto_urlencoded);
proto_register_fields(proto_urlencoded, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_http_urlencoded(void)
{
dissector_add_string("media_type", "application/x-www-form-urlencoded", form_urlencoded_handle);
}
