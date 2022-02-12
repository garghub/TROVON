static void
add_headers (proto_tree *tree, tvbuff_t *tvb, int hf, packet_info *pinfo)
{
guint8 hdr_id, val_id, codepage = 1;
gint32 tvb_len = tvb_length(tvb);
gint32 offset = 0;
gint32 hdr_len, hdr_start;
gint32 val_len, val_start;
gchar *hdr_str, *val_str;
proto_tree *wsp_headers;
proto_item *ti, *hidden_item;
guint8 ok;
guint32 val = 0;
if (! tree)
return;
if (offset >= tvb_len)
return;
ti = proto_tree_add_item(tree, hf,
tvb, offset, tvb_len, ENC_NA);
wsp_headers = proto_item_add_subtree(ti, ett_headers);
while (offset < tvb_len) {
hdr_start = offset;
hdr_id = tvb_get_guint8(tvb, offset);
if (hdr_id & 0x80) {
hdr_len = 1;
if (codepage == 1) {
DebugLog(("add_headers(code page 0): %s\n",
val_to_str_ext_const (hdr_id & 0x7f, &vals_field_names_ext, "Undefined")));
offset = WellKnownHeader[hdr_id & 0x7F](wsp_headers, tvb,
hdr_start, pinfo);
} else {
DebugLog(("add_headers(code page 0x%02x - assumed to be x-up-1): %s\n",
codepage, val_to_str_ext_const (hdr_id & 0x7f, &vals_openwave_field_names_ext, "Undefined")));
offset = WellKnownOpenwaveHeader[hdr_id & 0x7F](wsp_headers,
tvb, hdr_start, pinfo);
}
} else if (hdr_id == 0x7F) {
codepage = tvb_get_guint8(tvb, offset+1);
proto_tree_add_uint(wsp_headers, hf_wsp_header_shift_code,
tvb, offset, 2, codepage);
offset += 2;
} else if (hdr_id >= 0x20) {
hdr_str = (gchar *)tvb_get_stringz(wmem_packet_scope(), tvb, hdr_start, (gint *)&hdr_len);
val_start = hdr_start + hdr_len;
val_id = tvb_get_guint8(tvb, val_start);
if (val_id >= 0x20 && val_id <=0x7E) {
val_str = (gchar *)tvb_get_stringz(wmem_packet_scope(), tvb, val_start, (gint *)&val_len);
offset = val_start + val_len;
tvb_ensure_bytes_exist(tvb, hdr_start, offset-hdr_start);
proto_tree_add_text(wsp_headers,tvb,hdr_start,offset-hdr_start,
"%s: %s", hdr_str, val_str);
} else {
if (g_ascii_strcasecmp(hdr_str, "x-wap.tod") == 0) {
get_delta_seconds_value(val, tvb, val_start, val_len, ok);
if (ok) {
if (val == 0) {
ti = proto_tree_add_string (wsp_headers,
hf_hdr_x_wap_tod,
tvb, hdr_start, hdr_len + val_len,
"Requesting Time Of Day");
} else {
val_str = abs_time_secs_to_str(val, ABSOLUTE_TIME_LOCAL, TRUE);
ti = proto_tree_add_string (wsp_headers,
hf_hdr_x_wap_tod,
tvb, hdr_start, hdr_len + val_len, val_str);
}
proto_item_append_text(ti, " <Warning: "
"should be encoded as a textual value>");
} else {
proto_tree_add_string (wsp_headers, hf_hdr_x_wap_tod,
tvb, hdr_start, hdr_len + val_len,
InvalidValueForHeader("X-Wap-Tod"));
}
} else {
proto_tree_add_text (wsp_headers, tvb, hdr_start, hdr_len,
"<Error: Invalid value for the textual '%s' header"
" (should be a textual value)>",
hdr_str);
}
offset = tvb_len;
}
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
hidden_item = proto_tree_add_string(wsp_headers, hf_hdr_name,
tvb, hdr_start, offset - hdr_start, hdr_str);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else if (hdr_id > 0) {
codepage = hdr_id;
proto_tree_add_uint (wsp_headers, hf_wsp_header_shift_code,
tvb, offset, 1, codepage);
offset++;
} else {
proto_tree_add_text (wsp_headers, tvb, hdr_start, 1,
InvalidTextualHeader);
offset = tvb_len;
}
}
}
static guint32
wkh_default(proto_tree *tree, tvbuff_t *tvb,
guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
ok = TRUE;
wkh_1_WellKnownValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_text (tree, tvb, hdr_start, offset - hdr_start,
"%s: (Undecoded well-known value 0x%02x)",
val_to_str_ext (hdr_id, &vals_field_names_ext,
"<Unknown WSP header field 0x%02X>"), val_id & 0x7F);
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_text(tree, tvb, hdr_start, offset - hdr_start,
"%s: %s",
val_to_str_ext (hdr_id, &vals_field_names_ext,
"<Unknown WSP header field 0x%02X>"), val_str);
wkh_3_ValueWithLength;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_text (tree, tvb, hdr_start, offset - hdr_start,
"%s: (Undecoded value in general form with length indicator)",
val_to_str_ext (hdr_id, &vals_field_names_ext,
"<Unknown WSP header field 0x%02X>"));
wkh_4_End(HF_EMPTY);
}
guint32
add_content_type(proto_tree *tree, tvbuff_t *tvb, guint32 val_start,
guint32 *well_known_content, const char **textual_content)
{
guint32 hdr_start = val_start;
guint8 hdr_id = FN_CONTENT_TYPE;
guint8 val_id = tvb_get_guint8 (tvb, val_start);
guint32 offset = val_start;
guint32 val_len;
guint32 val_len_len;
gchar *val_str = NULL;
guint32 off, val = 0, len;
guint8 peek;
gboolean ok = FALSE;
proto_item *ti = NULL;
proto_item *hidden_item = NULL;
proto_tree *parameter_tree = NULL;
*textual_content = NULL;
*well_known_content = 0;
DebugLog(("add_content_type() - START\n"));
wkh_1_WellKnownValue;
DebugLog(("add_content_type() - Well-known - Start\n"));
*textual_content = val_to_str_ext(val_id & 0x7F, &vals_content_types_ext,
"<Unknown media type identifier 0x%X>");
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_type,
tvb, hdr_start, offset - hdr_start,
*textual_content);
*well_known_content = val_id & 0x7F;
ok = TRUE;
DebugLog(("add_content_type() - Well-known - End\n"));
wkh_2_TextualValue;
DebugLog(("add_content_type() - Textual - Start\n"));
if (*val_str) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_type,
tvb, hdr_start, offset - hdr_start,
val_str);
*textual_content = g_strdup(val_str);
*well_known_content = 0;
} else {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_type,
tvb, hdr_start, offset - hdr_start,
"<no media type has been specified>");
*textual_content = NULL;
*well_known_content = 0;
}
ok = TRUE;
DebugLog(("add_content_type() - Textual - End\n"));
wkh_3_ValueWithLength;
DebugLog(("add_content_type() - General form - Start\n"));
off = val_start + val_len_len;
peek = tvb_get_guint8(tvb, off);
if (is_text_string(peek)) {
DebugLog(("add_content_type() - General form - extension-media\n"));
get_extension_media(val_str, tvb, off, len, ok);
if (ok) {
off += len;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string (tree, hf_hdr_content_type,
tvb, hdr_start, offset - hdr_start, val_str);
}
*textual_content = g_strdup(val_str);
*well_known_content = 0;
} else if (is_integer_value(peek)) {
DebugLog(("add_content_type() - General form - integer_value\n"));
get_integer_value(val, tvb, off, len, ok);
if (ok) {
*textual_content = val_to_str_ext(val, &vals_content_types_ext,
"<Unknown media type identifier 0x%X>");
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_type,
tvb, hdr_start, offset - hdr_start,
*textual_content);
*well_known_content = val;
}
off += len;
}
if (ok && (off < offset)) {
DebugLog(("add_content_type() - General form - parameters\n"));
parameter_tree = proto_item_add_subtree (ti, ett_header);
while (off < offset) {
DebugLog(("add_content_type() - General form - parameter start "
"(off = %u)\n", off));
off = parameter (parameter_tree, ti, tvb, off, offset - off);
DebugLog(("add_content_type() - General form - parameter end "
"(off = %u)\n", off));
}
}
DebugLog(("add_content_type() - General form - End\n"));
wkh_4_End(hf_hdr_content_type);
}
static guint32
wkh_push_flag(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0a_Declarations;
proto_tree *subtree = NULL;
wkh_1_WellKnownValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_push_flag,
tvb, hdr_start, offset - hdr_start, "");
subtree = proto_item_add_subtree(ti, ett_header);
proto_tree_add_uint(subtree, hf_hdr_push_flag_auth,
tvb, val_start, 1, val_id);
proto_tree_add_uint(subtree, hf_hdr_push_flag_trust,
tvb, val_start, 1, val_id);
proto_tree_add_uint(subtree, hf_hdr_push_flag_last,
tvb, val_start, 1, val_id);
if (val_id & 0x01)
proto_item_append_string(ti, " (Initiator URI authenticated)");
if (val_id & 0x02)
proto_item_append_string(ti, " (Content trusted)");
if (val_id & 0x04)
proto_item_append_string(ti, " (Last push message)");
if (val_id & 0x78)
proto_item_append_text(ti, " <Warning: Reserved flags set>");
else
ok = TRUE;
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
wkh_4_End(hf_hdr_push_flag);
}
static guint32 wkh_profile_diff_wbxml (proto_tree *tree, tvbuff_t *tvb,
guint32 hdr_start, packet_info *pinfo)
{
wkh_0a_Declarations;
tvbuff_t *tmp_tvb;
proto_tree *subtree;
ok = TRUE;
wkh_1_WellKnownValue;
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_profile_diff, tvb, hdr_start, offset - hdr_start,
"(Profile-Diff value as WBXML)");
subtree = proto_item_add_subtree(ti, ett_header);
tmp_tvb = tvb_new_subset(tvb, val_start + val_len_len, val_len, val_len);
call_dissector(wbxml_uaprof_handle, tmp_tvb, pinfo, subtree);
ok = TRUE;
wkh_4_End(hf_hdr_profile_diff);
}
static guint32
wkh_allow(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *apinfo _U_)
{
wkh_0a_Declarations;
wkh_1_WellKnownValue;
val_id &= 0x7F;
if (val_id >= 0x40) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_allow,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val_id & 0x7F, &wsp_vals_pdu_type_ext,
"<Unknown WSP method 0x%02X>"));
ok = TRUE;
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
wkh_4_End(hf_hdr_allow);
}
static guint32
wkh_public(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *apinfo _U_)
{
wkh_0_Declarations;
wkh_1_WellKnownValue;
val_id &= 0x7F;
if (val_id >= 0x40) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_public,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val_id & 0x7F, &wsp_vals_pdu_type_ext,
"<Unknown WSP method 0x%02X>"));
ok = TRUE;
}
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_public,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End(hf_hdr_public);
}
static guint32
wkh_vary(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
wkh_1_WellKnownValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_vary,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val_id & 0x7F, &vals_field_names_ext,
"<Unknown WSP header field 0x%02X>"));
ok = TRUE;
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_vary,
tvb, hdr_start, offset - hdr_start,
val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End(hf_hdr_vary);
}
static guint32
wkh_x_wap_security(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0a_Declarations;
wkh_1_WellKnownValue;
if (val_id == 0x80) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_x_wap_security,
tvb, hdr_start, offset - hdr_start, "close-subordinate");
ok = TRUE;
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
wkh_4_End(hf_hdr_x_wap_security);
}
static guint32
wkh_connection(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *apinfo _U_)
{
wkh_0_Declarations;
wkh_1_WellKnownValue;
if (val_id == 0x80) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_connection,
tvb, hdr_start, offset - hdr_start, "close");
ok = TRUE;
}
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_connection,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End(hf_hdr_connection);
}
static guint32
wkh_transfer_encoding(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
wkh_1_WellKnownValue;
if (val_id == 0x80) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_transfer_encoding,
tvb, hdr_start, offset - hdr_start, "chunked");
ok = TRUE;
}
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_transfer_encoding,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End(hf_hdr_transfer_encoding);
}
static guint32
wkh_accept_ranges(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
wkh_1_WellKnownValue;
switch (val_id) {
case 0x80:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_ranges,
tvb, hdr_start, offset - hdr_start, "none");
ok = TRUE;
break;
case 0x81:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_ranges,
tvb, hdr_start, offset - hdr_start, "bytes");
ok = TRUE;
break;
}
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_ranges,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End(hf_hdr_accept_ranges);
}
static guint32
wkh_content_encoding(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
wkh_1_WellKnownValue;
switch (val_id) {
case 0x80:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_encoding,
tvb, hdr_start, offset - hdr_start, "gzip");
ok = TRUE;
break;
case 0x81:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_encoding,
tvb, hdr_start, offset - hdr_start, "compress");
ok = TRUE;
break;
case 0x82:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_encoding,
tvb, hdr_start, offset - hdr_start, "deflate");
ok = TRUE;
break;
}
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_encoding,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End(hf_hdr_content_encoding);
}
static guint32
wkh_accept_encoding(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 len, off;
guint8 peek;
gchar *str;
proto_tree *parameter_tree = NULL;
wkh_1_WellKnownValue;
switch (val_id) {
case 0x80:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "gzip");
ok = TRUE;
break;
case 0x81:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "compress");
ok = TRUE;
break;
case 0x82:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "deflate");
ok = TRUE;
break;
case 0x83:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "*");
ok = TRUE;
break;
}
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
peek = tvb_get_guint8(tvb, off);
if (is_short_integer(peek)) {
switch (peek) {
case 0x80:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "gzip");
ok = TRUE;
break;
case 0x81:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "compress");
ok = TRUE;
break;
case 0x82:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "deflate");
ok = TRUE;
break;
case 0x83:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "*");
ok = TRUE;
break;
}
off++;
} else {
get_token_text(str, tvb, off, len, ok);
if (ok) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, str);
}
off += len;
}
if (ok) {
if (off < offset) {
parameter_tree = proto_item_add_subtree(ti, ett_header);
parameter_value_q(parameter_tree, ti, tvb, off);
}
}
wkh_4_End(hf_hdr_accept_encoding);
}
static guint32
wkh_content_disposition(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0a_Declarations;
guint32 len, off;
guint8 peek;
gchar *str;
proto_tree *parameter_tree = NULL;
wkh_1_WellKnownValue;
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
peek = tvb_get_guint8(tvb, off);
if (is_short_integer(peek)) {
switch (peek) {
case 0x80:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_disposition,
tvb, hdr_start, offset - hdr_start, "form-data");
ok = TRUE;
break;
case 0x81:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_disposition,
tvb, hdr_start, offset - hdr_start, "attachment");
ok = TRUE;
break;
case 0x82:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_disposition,
tvb, hdr_start, offset - hdr_start, "inline");
ok = TRUE;
break;
}
off++;
} else {
get_token_text(str, tvb, off, len, ok);
if (ok) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_disposition,
tvb, hdr_start, offset - hdr_start, str);
}
off += len;
}
if ((ok) && (off < offset)) {
parameter_tree = proto_item_add_subtree(ti, ett_header);
while (off < offset) {
off = parameter(parameter_tree, ti, tvb, off, offset - off);
}
}
wkh_4_End(hf_hdr_content_disposition);
}
static guint32
wkh_age(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 val = 0, off = val_start, len;
wkh_1_WellKnownValue;
val = val_id & 0x7F;
val_str = wmem_strdup_printf(wmem_packet_scope(), "%u second%s", val, plurality(val, "", "s"));
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_age,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
if (val_id <= 4) {
get_long_integer(val, tvb, off, len, ok);
if (ok) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "%u second%s", val, plurality(val, "", "s"));
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_age,
tvb, hdr_start, offset - hdr_start, val_str);
}
}
wkh_4_End(hf_hdr_age);
}
static guint32
wkh_content_md5 (proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off;
wkh_1_WellKnownValue;
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
if (val_len == 16) {
val_str = wmem_strdup_printf(wmem_packet_scope(),
"%02x%02x%02x%02x%02x%02x%02x%02x"
"%02x%02x%02x%02x%02x%02x%02x%02x",
tvb_get_guint8(tvb, off),
tvb_get_guint8(tvb, off + 1),
tvb_get_guint8(tvb, off + 2),
tvb_get_guint8(tvb, off + 3),
tvb_get_guint8(tvb, off + 4),
tvb_get_guint8(tvb, off + 5),
tvb_get_guint8(tvb, off + 6),
tvb_get_guint8(tvb, off + 7),
tvb_get_guint8(tvb, off + 8),
tvb_get_guint8(tvb, off + 9),
tvb_get_guint8(tvb, off + 10),
tvb_get_guint8(tvb, off + 11),
tvb_get_guint8(tvb, off + 12),
tvb_get_guint8(tvb, off + 13),
tvb_get_guint8(tvb, off + 14),
tvb_get_guint8(tvb, off + 15)
);
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_md5,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
}
wkh_4_End(hf_hdr_content_md5);
}
static guint32
wkh_pragma(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0a_Declarations;
guint32 off;
wkh_1_WellKnownValue;
if (val_id == 0x80) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_pragma,
tvb, hdr_start, offset - hdr_start, "no-cache");
ok = TRUE;
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_pragma,
tvb, hdr_start, off - hdr_start, "");
parameter(NULL, ti, tvb, off, offset - off);
ok = TRUE;
wkh_4_End(hf_hdr_pragma);
}
static guint32
wkh_cache_control(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, len, val = 0;
guint8 peek, cache_control_directive;
gchar *str;
wkh_1_WellKnownValue;
val = val_id & 0x7F;
val_str = try_val_to_str_ext(val, &vals_cache_control_ext);
if (val_str) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_cache_control,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
}
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_cache_control,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
cache_control_directive = tvb_get_guint8(tvb, off++);
if (cache_control_directive & 0x80) {
switch (cache_control_directive & 0x7F) {
case CACHE_CONTROL_NO_CACHE:
case CACHE_CONTROL_PRIVATE:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_cache_control,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext (cache_control_directive & 0x7F, &vals_cache_control_ext,
"<Unknown cache control directive 0x%02X>"));
ok = TRUE;
while (ok && (off < offset)) {
peek = tvb_get_guint8(tvb, off);
if (peek & 0x80) {
proto_item_append_string(ti,
val_to_str (peek, vals_field_names,
"<Unknown WSP header field 0x%02X>"));
off++;
} else {
get_token_text(val_str, tvb, off, len, ok);
if (ok) {
proto_item_append_string(ti, val_str);
off += len;
}
}
}
break;
case CACHE_CONTROL_MAX_AGE:
case CACHE_CONTROL_MAX_STALE:
case CACHE_CONTROL_MIN_FRESH:
case CACHE_CONTROL_S_MAXAGE:
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_cache_control,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext (cache_control_directive & 0x7F, &vals_cache_control_ext,
"<Unknown cache control directive 0x%02X>"));
get_delta_seconds_value(val, tvb, off, len, ok);
if (ok) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "=%u second%s",
val, plurality(val, "", "s"));
proto_item_append_string(ti, val_str);
}
break;
default:
break;
}
} else if (is_token_text(cache_control_directive)) {
get_token_text(val_str, tvb, off, len, ok);
if (ok) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_cache_control,
tvb, hdr_start, offset - hdr_start, val_str);
get_integer_value(val, tvb, off, len, ok);
if (ok) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "=%u", val);
proto_item_append_string(ti, val_str);
} else {
get_text_string(val_str, tvb, off, len, ok);
if (ok) {
if (is_quoted_string(val_str[0])) {
if (is_quoted_string(val_str[len-2])) {
str = wmem_strdup_printf(wmem_packet_scope(), "%s" TrailingQuoteWarning,
val_str);
} else {
str = wmem_strdup_printf(wmem_packet_scope(), "%s\"", val_str);
}
proto_item_append_string(ti, str);
} else {
proto_item_append_string(ti, val_str);
}
}
}
}
}
wkh_4_End(hf_hdr_cache_control);
}
static guint32
wkh_warning(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, len, val;
guint8 warn_code;
gchar *str;
proto_tree *subtree;
wkh_1_WellKnownValue;
val = val_id & 0x7F;
val_str = try_val_to_str_ext(val, &vals_wsp_warning_code_ext);
if (val_str) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_warning,
tvb, hdr_start, offset - hdr_start, val_str);
subtree = proto_item_add_subtree(ti, ett_header);
proto_tree_add_uint(subtree, hf_hdr_warning_code,
tvb, val_start, 1, val);
ok = TRUE;
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
warn_code = tvb_get_guint8(tvb, off);
if (warn_code & 0x80) {
val = warn_code & 0x7f;
val_str = try_val_to_str_ext(val, &vals_wsp_warning_code_short_ext);
if (val_str) {
str = wmem_strdup_printf(wmem_packet_scope(), "code=%s", val_str);
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_warning,
tvb, hdr_start, offset - hdr_start, str);
subtree = proto_item_add_subtree(ti, ett_header);
proto_tree_add_uint(subtree, hf_hdr_warning_code,
tvb, off, 1, val);
off++;
get_text_string(str, tvb, off, len, ok);
if (ok) {
proto_tree_add_string(subtree, hf_hdr_warning_agent,
tvb, off, len, str);
val_str = wmem_strdup_printf(wmem_packet_scope(), "; agent=%s", str);
proto_item_append_string(ti, val_str);
off += len;
get_text_string(str, tvb, off, len, ok);
if (ok) {
proto_tree_add_string(subtree,
hf_hdr_warning_text,
tvb, off, len, str);
val_str = wmem_strdup_printf(wmem_packet_scope(), "; text=%s", str);
proto_item_append_string(ti, val_str);
}
}
}
}
wkh_4_End(hf_hdr_warning);
}
static guint32
wkh_profile_warning(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, len, val = 0;
guint8 warn_code;
gchar *str;
wkh_1_WellKnownValue;
val = val_id & 0x7F;
val_str = try_val_to_str_ext(val, &vals_wsp_profile_warning_code_ext);
if (val_str) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_profile_warning,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
warn_code = tvb_get_guint8(tvb, off++);
if (warn_code & 0x80) {
val_str = try_val_to_str_ext(val, &vals_wsp_profile_warning_code_ext);
if (val_str) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_profile_warning,
tvb, hdr_start, offset - hdr_start, val_str);
get_uri_value(str, tvb, off, len, ok);
if (ok) {
off += len;
str = wmem_strdup_printf(wmem_packet_scope(), "; target=%s", val_str);
proto_item_append_string(ti, str);
while (ok && (off < offset)) {
get_date_value(val, tvb, off, len, ok);
if (ok) {
off += len;
val_str = abs_time_secs_to_str(val, ABSOLUTE_TIME_LOCAL, TRUE);
str = wmem_strdup_printf(wmem_packet_scope(), "; date=%s", val_str);
proto_item_append_string(ti, str);
\
}
}
}
}
}
wkh_4_End(hf_hdr_profile_warning);
}
static guint32 wkh_encoding_version (proto_tree *tree, tvbuff_t *tvb,
guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, val, len;
gchar *str;
wkh_1_WellKnownValue;
val = val_id & 0x7F;
val_str = wmem_strdup_printf(wmem_packet_scope(), "%u.%u", val >> 4, val & 0x0F);
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
proto_tree_add_string(tree, hf_hdr_encoding_version,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
proto_tree_add_string(tree, hf_hdr_encoding_version,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
val = tvb_get_guint8(tvb, off);
if (val & 0x80) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "code-page=%u", val & 0x7F);
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_encoding_version,
tvb, hdr_start, offset - hdr_start, val_str);
off++;
ok = TRUE;
if (off < offset) {
get_version_value(val,val_str,tvb,off,len,ok);
if (ok) {
str = wmem_strdup_printf(wmem_packet_scope(), ": %s", val_str);
proto_item_append_string(ti, str);
}
}
}
wkh_4_End(hf_hdr_encoding_version);
}
static guint32
wkh_content_range(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, val, len;
proto_tree *subtree = NULL;
wkh_1_WellKnownValue;
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
get_uintvar_integer (val, tvb, off, len, ok);
if (ok) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "first-byte-pos=%u", val);
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_content_range,
tvb, hdr_start, offset - hdr_start, val_str);
subtree = proto_item_add_subtree(ti, ett_header);
proto_tree_add_uint(subtree, hf_hdr_content_range_first_byte_pos,
tvb, off, len, val);
off += len;
val = tvb_get_guint8(tvb, off);
if (val == 0x80) {
proto_item_append_string(ti, "; entity-length=unknown");
} else {
get_uintvar_integer (val, tvb, off, len, ok);
if (ok) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "; entity-length=%u", val);
proto_item_append_string(ti, val_str);
proto_tree_add_uint(subtree,
hf_hdr_content_range_entity_length,
tvb, off, len, val);
}
}
}
wkh_4_End(hf_hdr_content_range);
}
static guint32
wkh_range(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, val, len;
proto_tree *subtree = NULL;
wkh_1_WellKnownValue;
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
val = tvb_get_guint8(tvb, off);
if (val == 0x80) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_range,
tvb, hdr_start, offset - hdr_start, "byte-range");
subtree = proto_item_add_subtree(ti, ett_header);
get_uintvar_integer (val, tvb, off, len, ok);
if (ok) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "; first-byte-pos=%u", val);
proto_item_append_string(ti, val_str);
proto_tree_add_uint(subtree, hf_hdr_range_first_byte_pos,
tvb, off, len, val);
off += len;
if (off < offset) {
get_uintvar_integer (val, tvb, off, len, ok);
if (ok) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "; last-byte-pos=%u", val);
proto_item_append_string(ti, val_str);
proto_tree_add_uint(subtree,
hf_hdr_range_last_byte_pos,
tvb, off, len, val);
}
}
}
} else if (val == 0x81) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_range,
tvb, hdr_start, offset - hdr_start, "suffix-byte-range");
subtree = proto_item_add_subtree(ti, ett_header);
get_uintvar_integer (val, tvb, off, len, ok);
if (ok) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "; suffix-length=%u", val);
proto_item_append_string(ti, val_str);
proto_tree_add_uint(subtree, hf_hdr_range_suffix_length,
tvb, off, len, val);
}
}
wkh_4_End(hf_hdr_range);
}
static guint32 wkh_te (proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, val, len;
wkh_1_WellKnownValue;
if (val_id == 0x81) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
proto_tree_add_string(tree, hf_hdr_encoding_version,
tvb, hdr_start, offset - hdr_start, "trailers");
ok = TRUE;
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
val = tvb_get_guint8(tvb, off);
if (val & 0x80) {
val_str = try_val_to_str_ext((val & 0x7F), &vals_well_known_te_ext);
if (val_str) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_te,
tvb, hdr_start, off - hdr_start, val_str);
off++;
ok = TRUE;
}
} else {
get_token_text(val_str, tvb, off, len, ok);
if (ok) {
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_string(tree, hf_hdr_te,
tvb, hdr_start, off - hdr_start, val_str);
off += len;
}
}
if ((ok) && (off < offset)) {
}
wkh_4_End(hf_hdr_te);
}
static guint32
wkh_openwave_default(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
ok = TRUE;
wkh_1_WellKnownValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_text(tree, tvb, hdr_start, offset - hdr_start,
"%s: (Undecoded well-known value 0x%02x)",
val_to_str_ext (hdr_id, &vals_openwave_field_names_ext,
"<Unknown WSP header field 0x%02X>"), val_id & 0x7F);
wkh_2_TextualValue;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_text(tree,tvb,hdr_start, offset - hdr_start,
"%s: %s",
val_to_str_ext (hdr_id, &vals_openwave_field_names_ext,
"<Unknown WSP header field 0x%02X>"), val_str);
wkh_3_ValueWithLength;
tvb_ensure_bytes_exist(tvb, hdr_start, offset - hdr_start);
ti = proto_tree_add_text(tree, tvb, hdr_start, offset - hdr_start,
"%s: (Undecoded value in general form with length indicator)",
val_to_str_ext (hdr_id, &vals_openwave_field_names_ext,
"<Unknown WSP header field 0x%02X>"));
wkh_4_End(HF_EMPTY);
}
static int
parameter (proto_tree *tree, proto_item *ti, tvbuff_t *tvb, int start, int len)
{
int offset = start;
guint8 peek = tvb_get_guint8 (tvb,start);
guint32 val = 0, type = 0, type_len, val_len;
gchar *str = NULL;
const gchar *val_str = NULL;
gchar *s;
gboolean ok;
DebugLog(("parameter(start = %u, len = %u)\n", start, len));
if (is_token_text (peek)) {
DebugLog(("parameter() - Untyped - Start\n"));
get_token_text (str,tvb,start,val_len,ok);
if (ok) {
offset += val_len;
get_text_value(val_str, tvb, offset, val_len, ok);
if (ok) {
DebugLog(("Trying textual parameter value.\n"));
offset += val_len;
if (is_quoted_string(val_str[0])) {
if (is_quoted_string(val_str[val_len-2])) {
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"%s: %s" TrailingQuoteWarning, str, val_str);
s = wmem_strdup_printf(wmem_packet_scope(), "; %s=%s", str, val_str);
} else {
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"%s: %s\"", str, val_str);
s = wmem_strdup_printf(wmem_packet_scope(), "; %s=%s\"", str, val_str);
}
} else {
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"%s: %s", str, val_str);
s = wmem_strdup_printf(wmem_packet_scope(), "; %s=%s", str, val_str);
}
DebugLog(("parameter() - Untyped: %s\n", s));
proto_item_append_string(ti, s);
DebugLog(("Freeing s\n"));
DebugLog(("Done!\n"));
} else {
DebugLog(("Trying integer parameter value.\n"));
get_integer_value (val,tvb,offset,val_len,ok);
if (ok) {
offset += val_len;
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"%s: %u", str, val);
s = wmem_strdup_printf(wmem_packet_scope(), "; %s=%u", str, val);
proto_item_append_string(ti, s);
DebugLog(("parameter() - Untyped: %s\n", s));
} else {
DebugLog(("Invalid untyped parameter value!\n"));
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text (tree, tvb, start, offset - start,
"<Error: Invalid untyped parameter definition>");
offset = start + len;
}
}
}
DebugLog(("parameter() - Untyped - End\n"));
return offset;
}
DebugLog(("parameter() - Typed - Start\n"));
get_integer_value (type,tvb,start,type_len,ok);
if (!ok) {
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text (tree, tvb, start, offset - start,
"<Error: Invalid typed parameter definition>");
return (start + len);
}
offset += type_len;
DebugLog(("Typed parameter = 0x%02x\n", type));
switch (type) {
case 0x01:
get_integer_value(val, tvb, offset, val_len, ok);
if (ok) {
val_str = val_to_str_ext(val, &wap_mib_enum_vals_character_sets_ext,
"<Unknown character set Identifier 0x%X>");
proto_tree_add_string(tree, hf_parameter_charset,
tvb, start, type_len + val_len, val_str);
str = wmem_strdup_printf(wmem_packet_scope(), "; charset=%s", val_str);
proto_item_append_string(ti, str);
offset += val_len;
} else {
proto_tree_add_text (tree, tvb, start, offset,
InvalidParameterValue("Charset", "Integer-value"));
offset = start + len;
}
break;
case 0x03:
get_integer_value (val,tvb,offset,val_len,ok);
if (ok) {
proto_tree_add_uint (tree, hf_wsp_parameter_type,
tvb, start, type_len + val_len, val);
s = wmem_strdup_printf(wmem_packet_scope(), "; Type=%u", val);
proto_item_append_string (ti, s);
offset += val_len;
} else {
proto_tree_add_text (tree, tvb, start, offset,
InvalidParameterValue("Type", "Integer-value"));
offset = start + len;
}
break;
case 0x05:
parameter_text(hf_wsp_parameter_name, "name",
"Name (WSP 1.1 encoding)", "Text-string");
break;
case 0x17:
parameter_text_value(hf_wsp_parameter_name, "name",
"Name (WSP 1.4 encoding)", "Text-value");
break;
case 0x06:
parameter_text(hf_wsp_parameter_filename, "filename",
"Filename (WSP 1.1 encoding)", "Text-string");
break;
case 0x18:
parameter_text_value(hf_wsp_parameter_filename, "filename",
"Filename (WSP 1.4 encoding)", "Text-value");
break;
case 0x09:
get_extension_media(val_str,tvb,offset,val_len,ok);
if (ok) {
offset += val_len;
} else {
get_short_integer(val,tvb,offset,val_len,ok);
if (ok) {
offset += val_len;
val_str = val_to_str_ext(val, &vals_content_types_ext,
"(Unknown content type identifier 0x%X)");
}
}
if (ok) {
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_string (tree, hf_wsp_parameter_upart_type,
tvb, start, offset - start, val_str);
str = wmem_strdup_printf(wmem_packet_scope(), "; type=%s", val_str);
proto_item_append_string(ti, str);
} else {
proto_tree_add_text (tree, tvb, start, len,
InvalidParameterValue("Type",
"Constrained-encoding"));
offset = start + len;
}
break;
case 0x0A:
parameter_text(hf_wsp_parameter_start, "start",
"Start (WSP 1.2 encoding)", "Text-string");
break;
case 0x19:
parameter_text_value(hf_wsp_parameter_start, "start",
"Start (WSP 1.4 encoding)", "Text-value");
break;
case 0x0B:
parameter_text(hf_wsp_parameter_start_info, "start-info",
"Start-info (WSP 1.2 encoding)", "Text-string");
break;
case 0x1A:
parameter_text_value(hf_wsp_parameter_start_info, "start-info",
"Start-info (WSP 1.4 encoding)", "Text-value");
break;
case 0x0C:
parameter_text(hf_wsp_parameter_comment, "comment",
"Comment (WSP 1.3 encoding)", "Text-string");
break;
case 0x1B:
parameter_text_value(hf_wsp_parameter_comment, "comment",
"Comment (WSP 1.4 encoding)", "Text-value");
break;
case 0x0D:
parameter_text(hf_wsp_parameter_domain, "domain",
"Domain (WSP 1.3 encoding)", "Text-string");
break;
case 0x1C:
parameter_text_value(hf_wsp_parameter_domain, "domain",
"Domain (WSP 1.4 encoding)", "Text-value");
break;
case 0x0F:
parameter_text(hf_wsp_parameter_path, "path",
"Path (WSP 1.3 encoding)", "Text-string");
break;
case 0x1D:
parameter_text_value(hf_wsp_parameter_path, "path",
"Path (WSP 1.4 encoding)", "Text-value");
break;
case 0x11:
peek = tvb_get_guint8 (tvb, start+1);
if (peek & 0x80) {
peek &= 0x7F;
proto_tree_add_uint (tree, hf_wsp_parameter_sec,
tvb, start, 2, peek);
str = (gchar *) val_to_str_ext_const(peek, &vals_wsp_parameter_sec_ext, "Undefined");
s = wmem_strdup_printf(wmem_packet_scope(), "; SEC=%s", str);
proto_item_append_string (ti, s);
offset++;
} else {
proto_tree_add_text (tree, tvb, start, len,
InvalidParameterValue("SEC", "Short-integer"));
offset = start + len;
}
break;
case 0x12:
parameter_text_value(hf_wsp_parameter_mac, "MAC",
"MAC", "Text-value");
break;
case 0x02:
get_version_value(val,str,tvb,offset,val_len,ok);
if (ok) {
proto_tree_add_string (tree, hf_wsp_parameter_level,
tvb, start, type_len + val_len, str);
s = wmem_strdup_printf(wmem_packet_scope(), "; level=%s", str);
proto_item_append_string (ti, s);
offset += val_len;
} else {
proto_tree_add_text (tree, tvb, start, len,
InvalidParameterValue("Level", "Version-value"));
offset = start + len;
}
break;
case 0x00:
offset = parameter_value_q(tree, ti, tvb, offset);
break;
case 0x16:
get_integer_value (val,tvb,offset,val_len,ok);
if (ok) {
proto_tree_add_uint (tree, hf_wsp_parameter_size,
tvb, start, type_len + val_len, val);
s = wmem_strdup_printf(wmem_packet_scope(), "; Size=%u", val);
proto_item_append_string (ti, s);
offset += val_len;
} else {
proto_tree_add_text (tree, tvb, start, offset,
InvalidParameterValue("Size", "Integer-value"));
offset = start + len;
}
break;
case 0x07:
DebugLog(("Skipping remaining parameters from here\n"));
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"Undecoded parameter Differences - decoding stopped");
break;
case 0x08:
DebugLog(("Skipping remaining parameters from here\n"));
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"Undecoded parameter Padding - decoding stopped");
break;
case 0x0E:
DebugLog(("Skipping remaining parameters from here\n"));
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"Undecoded parameter Max-Age - decoding stopped");
break;
case 0x10:
DebugLog(("Skipping remaining parameters from here\n"));
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"Undecoded parameter Secure - decoding stopped");
break;
case 0x13:
DebugLog(("Skipping remaining parameters from here\n"));
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"Undecoded parameter Creation-Date - decoding stopped");
break;
case 0x14:
DebugLog(("Skipping remaining parameters from here\n"));
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"Undecoded parameter Modification-Date - decoding stopped");
break;
case 0x15:
DebugLog(("Skipping remaining parameters from here\n"));
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"Undecoded parameter Read-Date - decoding stopped");
break;
default:
DebugLog(("Skipping remaining parameters from here\n"));
tvb_ensure_bytes_exist(tvb, start, offset - start);
proto_tree_add_text(tree, tvb, start, offset - start,
"Undecoded parameter type 0x%02x - decoding stopped",
type);
offset = start + len;
break;
}
DebugLog(("parameter() - Typed - End\n"));
return offset;
}
static int
parameter_value_q (proto_tree *tree, proto_item *ti, tvbuff_t *tvb, int start)
{
int offset = start;
guint32 val = 0, val_len;
gchar *str = NULL, *s = NULL;
guint8 ok;
get_uintvar_integer (val, tvb, offset, val_len, ok);
if (ok && (val < 1100)) {
if (val <= 100) {
str = wmem_strdup_printf(wmem_packet_scope(), "0.%02u", val - 1);
} else {
str = wmem_strdup_printf(wmem_packet_scope(), "0.%03u", val - 100);
}
s = wmem_strdup_printf(wmem_packet_scope(), "; q=%s", str);
proto_item_append_string (ti, s);
proto_tree_add_string (tree, hf_parameter_q,
tvb, start, val_len, str);
offset += val_len;
} else {
proto_tree_add_text (tree, tvb, start, offset,
InvalidParameterValue("Q", "Q-value"));
offset += val_len;
}
return offset;
}
static void
dissect_redirect(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dissector_handle_t dissector_handle)
{
guint8 flags;
proto_item *ti;
proto_tree *addresses_tree = NULL;
proto_tree *addr_tree = NULL;
proto_tree *flags_tree;
guint8 bearer_type;
guint8 address_flags_len;
int address_len;
proto_tree *address_flags_tree;
guint16 port_num;
guint32 address_ipv4;
struct e_in6_addr address_ipv6;
address redir_address;
conversation_t *conv;
guint32 idx = 0;
guint32 address_record_len;
flags = tvb_get_guint8 (tvb, offset);
if (tree) {
ti = proto_tree_add_uint (tree, hf_wsp_redirect_flags,
tvb, offset, 1, flags);
flags_tree = proto_item_add_subtree (ti, ett_redirect_flags);
proto_tree_add_boolean (flags_tree, hf_wsp_redirect_permanent,
tvb, offset, 1, flags);
proto_tree_add_boolean (flags_tree, hf_wsp_redirect_reuse_security_session,
tvb, offset, 1, flags);
}
offset++;
if (tree) {
ti = proto_tree_add_item(tree, hf_redirect_addresses,
tvb, 0, -1, ENC_NA);
addresses_tree = proto_item_add_subtree(ti, ett_addresses);
}
while (tvb_reported_length_remaining (tvb, offset) > 0) {
idx++;
address_flags_len = tvb_get_guint8 (tvb, offset);
address_len = address_flags_len & ADDRESS_LEN;
address_record_len = address_len
+ (address_flags_len & BEARER_TYPE_INCLUDED ? 1 : 0)
+ (address_flags_len & PORT_NUMBER_INCLUDED ? 2 : 0)
;
if (tree) {
ti = proto_tree_add_uint(addresses_tree, hf_address_entry,
tvb, offset, 1 + address_record_len, idx);
addr_tree = proto_item_add_subtree(ti, ett_address);
ti = proto_tree_add_uint (addr_tree, hf_address_flags_length,
tvb, offset, 1, address_flags_len);
address_flags_tree = proto_item_add_subtree (ti, ett_address_flags);
proto_tree_add_boolean (address_flags_tree, hf_address_flags_length_bearer_type_included,
tvb, offset, 1, address_flags_len);
proto_tree_add_boolean (address_flags_tree, hf_address_flags_length_port_number_included,
tvb, offset, 1, address_flags_len);
proto_tree_add_uint (address_flags_tree, hf_address_flags_length_address_len,
tvb, offset, 1, address_flags_len);
}
offset++;
if (address_flags_len & BEARER_TYPE_INCLUDED) {
bearer_type = tvb_get_guint8 (tvb, offset);
if (tree) {
proto_tree_add_uint (addr_tree, hf_address_bearer_type,
tvb, offset, 1, bearer_type);
}
offset++;
} else {
bearer_type = 0x00;
}
if (address_flags_len & PORT_NUMBER_INCLUDED) {
port_num = tvb_get_ntohs (tvb, offset);
if (tree) {
proto_tree_add_uint (addr_tree, hf_address_port_num,
tvb, offset, 2, port_num);
}
offset += 2;
} else {
port_num = pinfo->srcport;
}
if (!(address_flags_len & BEARER_TYPE_INCLUDED)) {
goto unknown_address_type;
}
switch (bearer_type) {
case BT_IPv4:
case BT_IS_95_CSD:
case BT_IS_95_PACKET_DATA:
case BT_ANSI_136_CSD:
case BT_ANSI_136_PACKET_DATA:
case BT_GSM_CSD:
case BT_GSM_GPRS:
case BT_GSM_USSD_IPv4:
case BT_AMPS_CDPD:
case BT_PDC_CSD:
case BT_PDC_PACKET_DATA:
case BT_IDEN_CSD:
case BT_IDEN_PACKET_DATA:
case BT_PHS_CSD:
case BT_TETRA_PACKET_DATA:
if (address_len != 4) {
goto unknown_address_type;
}
address_ipv4 = tvb_get_ipv4(tvb, offset);
if (tree) {
proto_tree_add_ipv4 (addr_tree,
hf_address_ipv4_addr,
tvb, offset, 4, address_ipv4);
}
redir_address.type = AT_IPv4;
redir_address.len = 4;
redir_address.data = (const guint8 *)&address_ipv4;
conv = find_conversation(pinfo->fd->num, &redir_address, &pinfo->dst,
PT_UDP, port_num, 0, NO_PORT_B);
if (conv == NULL) {
conv = conversation_new(pinfo->fd->num, &redir_address,
&pinfo->dst, PT_UDP, port_num, 0, NO_PORT2);
}
conversation_set_dissector(conv, dissector_handle);
break;
case BT_IPv6:
if (address_len != 16) {
goto unknown_address_type;
}
tvb_get_ipv6(tvb, offset, &address_ipv6);
if (tree) {
proto_tree_add_ipv6 (addr_tree,
hf_address_ipv6_addr,
tvb, offset, 16, (guint8 *)&address_ipv6);
}
redir_address.type = AT_IPv6;
redir_address.len = 16;
redir_address.data = (const guint8 *)&address_ipv6;
conv = find_conversation(pinfo->fd->num, &redir_address, &pinfo->dst,
PT_UDP, port_num, 0, NO_PORT_B);
if (conv == NULL) {
conv = conversation_new(pinfo->fd->num, &redir_address,
&pinfo->dst, PT_UDP, port_num, 0, NO_PORT2);
}
conversation_set_dissector(conv, dissector_handle);
break;
unknown_address_type:
default:
if (address_len != 0) {
if (tree) {
proto_tree_add_item (addr_tree, hf_address_addr,
tvb, offset, address_len, ENC_NA);
}
}
break;
}
offset += address_len;
}
}
static void
add_addresses(proto_tree *tree, tvbuff_t *tvb, int hf)
{
proto_item *ti;
proto_tree *addresses_tree;
proto_tree *addr_tree;
guint8 bearer_type;
guint8 address_flags_len;
int address_len;
proto_tree *address_flags_tree;
guint32 tvb_len = tvb_length(tvb);
guint32 offset = 0;
guint32 idx = 0;
guint32 address_record_len;
if (! tree)
return;
if (offset >= tvb_len)
return;
ti = proto_tree_add_item(tree, hf, tvb, 0, -1, ENC_NA);
addresses_tree = proto_item_add_subtree(ti, ett_addresses);
while (offset < tvb_len) {
idx++;
address_flags_len = tvb_get_guint8 (tvb, offset);
address_len = address_flags_len & ADDRESS_LEN;
address_record_len = address_len
+ (address_flags_len & BEARER_TYPE_INCLUDED ? 1 : 0)
+ (address_flags_len & PORT_NUMBER_INCLUDED ? 2 : 0)
;
ti = proto_tree_add_uint(addresses_tree, hf_address_entry,
tvb, offset, 1 + address_record_len, idx);
addr_tree = proto_item_add_subtree(ti, ett_address);
ti = proto_tree_add_uint (addr_tree, hf_address_flags_length,
tvb, offset, 1, address_flags_len);
address_flags_tree = proto_item_add_subtree (ti, ett_address_flags);
proto_tree_add_boolean (address_flags_tree, hf_address_flags_length_bearer_type_included,
tvb, offset, 1, address_flags_len);
proto_tree_add_boolean (address_flags_tree, hf_address_flags_length_port_number_included,
tvb, offset, 1, address_flags_len);
proto_tree_add_uint (address_flags_tree, hf_address_flags_length_address_len,
tvb, offset, 1, address_flags_len);
offset++;
if (address_flags_len & BEARER_TYPE_INCLUDED) {
bearer_type = tvb_get_guint8 (tvb, offset);
proto_tree_add_uint (addr_tree, hf_address_bearer_type,
tvb, offset, 1, bearer_type);
offset++;
} else {
bearer_type = 0x00;
}
if (address_flags_len & PORT_NUMBER_INCLUDED) {
proto_tree_add_uint (addr_tree, hf_address_port_num,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (!(address_flags_len & BEARER_TYPE_INCLUDED)) {
goto unknown_address_type;
}
switch (bearer_type) {
case BT_IPv4:
case BT_IS_95_CSD:
case BT_IS_95_PACKET_DATA:
case BT_ANSI_136_CSD:
case BT_ANSI_136_PACKET_DATA:
case BT_GSM_CSD:
case BT_GSM_GPRS:
case BT_GSM_USSD_IPv4:
case BT_AMPS_CDPD:
case BT_PDC_CSD:
case BT_PDC_PACKET_DATA:
case BT_IDEN_CSD:
case BT_IDEN_PACKET_DATA:
case BT_PHS_CSD:
case BT_TETRA_PACKET_DATA:
if (address_len != 4) {
goto unknown_address_type;
}
proto_tree_add_ipv4 (addr_tree, hf_address_ipv4_addr,
tvb, offset, 4, ENC_NA);
break;
case BT_IPv6:
if (address_len != 16) {
goto unknown_address_type;
}
proto_tree_add_ipv6 (addr_tree, hf_address_ipv6_addr,
tvb, offset, 16, ENC_NA);
break;
unknown_address_type:
default:
if (address_len != 0) {
proto_tree_add_item (addr_tree, hf_address_addr,
tvb, offset, address_len, ENC_NA);
}
break;
}
offset += address_len;
}
}
static void
dissect_sir(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 version;
guint32 val_len;
guint32 val_len_save;
guint32 len;
guint32 offset = 0;
guint32 i;
tvbuff_t *tmp_tvb;
proto_tree *subtree;
proto_item *ti;
col_append_str(pinfo->cinfo, COL_INFO,
": WAP Session Initiation Request");
if (! tree)
return;
ti = proto_tree_add_item(tree, hf_sir_section,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_sir);
version = tvb_get_guint8(tvb, 0);
proto_tree_add_uint(subtree, hf_sir_version,
tvb, 0, 1, version);
val_len = tvb_get_guintvar(tvb, 1, &len);
proto_tree_add_uint(subtree, hf_sir_app_id_list_len,
tvb, 1, len, val_len);
offset = 1 + len;
tmp_tvb = tvb_new_subset(tvb, offset, val_len, val_len);
add_headers (subtree, tmp_tvb, hf_sir_app_id_list, pinfo);
offset += val_len;
val_len = tvb_get_guintvar(tvb, offset, &len);
proto_tree_add_uint(subtree, hf_sir_wsp_contact_points_len,
tvb, offset, len, val_len);
offset += len;
tmp_tvb = tvb_new_subset (tvb, offset, val_len, val_len);
add_addresses(subtree, tmp_tvb, hf_sir_wsp_contact_points);
if (version == 0)
return;
offset += val_len;
val_len = tvb_get_guintvar(tvb, offset, &len);
proto_tree_add_uint(subtree, hf_sir_contact_points_len,
tvb, offset, len, val_len);
offset += len;
tmp_tvb = tvb_new_subset (tvb, offset, val_len, val_len);
add_addresses(subtree, tmp_tvb, hf_sir_contact_points);
offset += val_len;
val_len = tvb_get_guintvar(tvb, offset, &len);
proto_tree_add_uint(subtree, hf_sir_protocol_options_len,
tvb, offset, len, val_len);
offset += len;
val_len_save = val_len;
for (i = 0; i < val_len_save; i++) {
val_len = tvb_get_guintvar(tvb, offset, &len);
proto_tree_add_uint(subtree, hf_sir_protocol_options,
tvb, offset, len, val_len);
offset += len;
}
val_len = tvb_get_guintvar(tvb, offset, &len);
proto_tree_add_uint(subtree, hf_sir_prov_url_len,
tvb, offset, len, val_len);
offset += len;
tvb_ensure_bytes_exist(tvb, offset, val_len);
proto_tree_add_item (tree, hf_sir_prov_url,
tvb, offset, val_len, ENC_ASCII|ENC_NA);
offset += val_len;
val_len = tvb_get_guintvar(tvb, offset, &len);
proto_tree_add_uint(subtree, hf_sir_cpi_tag_len,
tvb, offset, len, val_len);
offset += len;
for (i = 0; i < val_len; i++) {
proto_tree_add_item(subtree, hf_sir_cpi_tag,
tvb, offset, 4, ENC_NA);
offset += 4;
}
}
static void
dissect_wsp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
dissector_handle_t dissector_handle, gboolean is_connectionless)
{
int offset = 0;
guint8 pdut;
guint count = 0;
guint value = 0;
guint uriLength = 0;
guint uriStart = 0;
guint capabilityLength = 0;
guint headersLength = 0;
guint headerLength = 0;
guint headerStart = 0;
guint nextOffset = 0;
guint contentTypeStart = 0;
guint contentType = 0;
const char *contentTypeStr;
tvbuff_t *tmp_tvb;
gboolean found_match;
proto_item *proto_ti = NULL;
proto_tree *wsp_tree = NULL;
wsp_info_value_t *stat_info;
stat_info = (wsp_info_value_t *)wmem_alloc(wmem_packet_scope(), sizeof(wsp_info_value_t));
stat_info->status_code = 0;
if (is_connectionless)
{
offset++;
};
pdut = tvb_get_guint8 (tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "WSP %s (0x%02x)",
val_to_str_ext (pdut, &wsp_vals_pdu_type_ext, "Unknown PDU type (0x%02x)"),
pdut);
if (tree) {
proto_tree_set_visible(tree, TRUE);
proto_ti = proto_tree_add_item(tree, proto_wsp,
tvb, 0, -1, ENC_NA);
wsp_tree = proto_item_add_subtree(proto_ti, ett_wsp);
proto_item_append_text(proto_ti, ", Method: %s (0x%02x)",
val_to_str_ext (pdut, &wsp_vals_pdu_type_ext, "Unknown (0x%02x)"),
pdut);
if (is_connectionless)
{
proto_tree_add_item (wsp_tree, hf_wsp_header_tid,
tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item( wsp_tree, hf_wsp_header_pdu_type,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset++;
if ((pdut >= 0x50) && (pdut <= 0x5F))
pdut = WSP_PDU_GET;
else if ((pdut >= 0x70) && (pdut <= 0x7F))
pdut = WSP_PDU_POST;
switch (pdut)
{
case WSP_PDU_CONNECT:
case WSP_PDU_CONNECTREPLY:
case WSP_PDU_RESUME:
if (tree) {
if (pdut == WSP_PDU_CONNECT)
{
proto_tree_add_item (wsp_tree, hf_wsp_version_major,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (wsp_tree, hf_wsp_version_minor,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
{
guint8 ver = tvb_get_guint8(tvb, offset);
proto_item_append_text(proto_ti, ", Version: %u.%u",
ver >> 4, ver & 0x0F);
}
offset++;
} else {
count = 0;
value = tvb_get_guintvar (tvb, offset, &count);
proto_tree_add_uint (wsp_tree,
hf_wsp_server_session_id,
tvb, offset, count, value);
proto_item_append_text(proto_ti, ", Session ID: %u", value);
offset += count;
}
count = 0;
capabilityLength = tvb_get_guintvar (tvb, offset, &count);
proto_tree_add_uint (wsp_tree, hf_capabilities_length,
tvb, offset, count, capabilityLength);
offset += count;
if (pdut != WSP_PDU_RESUME)
{
count = 0;
headerLength = tvb_get_guintvar (tvb, offset, &count);
proto_tree_add_uint (wsp_tree, hf_wsp_header_length,
tvb, offset, count, headerLength);
offset += count;
} else {
headerStart = offset + capabilityLength;
headerLength = tvb_reported_length_remaining (tvb,
headerStart);
}
if (capabilityLength > 0)
{
tmp_tvb = tvb_new_subset (tvb, offset,
capabilityLength, capabilityLength);
add_capabilities (wsp_tree, tmp_tvb, pdut);
offset += capabilityLength;
}
if (headerLength > 0)
{
tmp_tvb = tvb_new_subset (tvb, offset,
headerLength, headerLength);
add_headers (wsp_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
}
break;
case WSP_PDU_REDIRECT:
dissect_redirect(tvb, offset, pinfo, wsp_tree, dissector_handle);
break;
case WSP_PDU_DISCONNECT:
case WSP_PDU_SUSPEND:
if (tree) {
count = 0;
value = tvb_get_guintvar (tvb, offset, &count);
proto_tree_add_uint (wsp_tree,
hf_wsp_server_session_id,
tvb, offset, count, value);
proto_item_append_text(proto_ti, ", Session ID: %u", value);
}
break;
case WSP_PDU_GET:
case WSP_PDU_OPTIONS:
case WSP_PDU_HEAD:
case WSP_PDU_DELETE:
case WSP_PDU_TRACE:
count = 0;
value = tvb_get_guintvar (tvb, offset, &count);
nextOffset = offset + count;
add_uri (wsp_tree, pinfo, tvb, offset, nextOffset, proto_ti);
if (tree) {
offset += value + count;
tmp_tvb = tvb_new_subset_remaining (tvb, offset);
add_headers (wsp_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
break;
case WSP_PDU_POST:
case WSP_PDU_PUT:
uriStart = offset;
count = 0;
uriLength = tvb_get_guintvar (tvb, offset, &count);
headerStart = uriStart+count;
count = 0;
headersLength = tvb_get_guintvar (tvb, headerStart, &count);
offset = headerStart + count;
add_uri (wsp_tree, pinfo, tvb, uriStart, offset, proto_ti);
offset += uriLength;
if (tree)
proto_tree_add_uint (wsp_tree, hf_wsp_header_length,
tvb, headerStart, count, headersLength);
if (headersLength == 0)
break;
contentTypeStart = offset;
nextOffset = add_content_type (wsp_tree,
tvb, offset, &contentType, &contentTypeStr);
if (tree) {
if (contentTypeStr) {
proto_item_append_text(proto_ti, ", Content-Type: %s",
contentTypeStr);
} else {
proto_item_append_text(proto_ti, ", Content-Type: 0x%X",
contentType);
}
headerLength = headersLength - (nextOffset - contentTypeStart);
if (headerLength > 0)
{
tmp_tvb = tvb_new_subset (tvb, nextOffset,
headerLength, headerLength);
add_headers (wsp_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
}
if (tvb_reported_length_remaining(tvb,
headerStart + count + uriLength + headersLength) > 0)
{
tmp_tvb = tvb_new_subset_remaining (tvb,
headerStart + count + uriLength + headersLength);
found_match = FALSE;
if (contentTypeStr) {
found_match = dissector_try_string(media_type_table,
contentTypeStr, tmp_tvb, pinfo, tree);
}
if (! found_match) {
if (! dissector_try_heuristic(heur_subdissector_list,
tmp_tvb, pinfo, tree, NULL)) {
guint8* save_private_data = (guint8 *)pinfo->private_data;
pinfo->match_string = contentTypeStr;
pinfo->private_data = NULL;
call_dissector(media_handle, tmp_tvb, pinfo, tree);
pinfo->private_data = save_private_data;
#if 0
if (tree)
add_post_data (wsp_tree, tmp_tvb,
contentType, contentTypeStr, pinfo);
#endif
}
}
}
break;
case WSP_PDU_REPLY:
count = 0;
headersLength = tvb_get_guintvar (tvb, offset+1, &count);
headerStart = offset + count + 1;
{
guint8 reply_status = tvb_get_guint8(tvb, offset);
const char *reply_status_str;
reply_status_str = val_to_str_ext_const (reply_status, &wsp_vals_status_ext, "(Unknown response status)");
if (tree) {
proto_tree_add_item (wsp_tree, hf_wsp_header_status,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(proto_ti, ", Status: %s (0x%02x)",
reply_status_str, reply_status);
}
stat_info->status_code = (gint) reply_status;
col_append_fstr(pinfo->cinfo, COL_INFO,
": %s (0x%02x)",
reply_status_str, reply_status);
}
nextOffset = offset + 1 + count;
if (tree)
proto_tree_add_uint (wsp_tree, hf_wsp_header_length,
tvb, offset + 1, count, headersLength);
if (headersLength == 0)
break;
contentTypeStart = nextOffset;
nextOffset = add_content_type (wsp_tree, tvb,
nextOffset, &contentType, &contentTypeStr);
if (tree) {
if (contentTypeStr) {
proto_item_append_text(proto_ti, ", Content-Type: %s",
contentTypeStr);
} else {
proto_item_append_text(proto_ti, ", Content-Type: 0x%X",
contentType);
}
headerLength = headersLength - (nextOffset - contentTypeStart);
if (headerLength > 0)
{
tmp_tvb = tvb_new_subset (tvb, nextOffset,
headerLength, headerLength);
add_headers (wsp_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
}
if (tvb_reported_length_remaining(tvb, headerStart + headersLength)
> 0)
{
tmp_tvb = tvb_new_subset_remaining (tvb, headerStart + headersLength);
found_match = FALSE;
if (contentTypeStr) {
found_match = dissector_try_string(media_type_table,
contentTypeStr, tmp_tvb, pinfo, tree);
}
if (! found_match) {
if (! dissector_try_heuristic(heur_subdissector_list,
tmp_tvb, pinfo, tree, NULL)) {
guint8* save_private_data = (guint8 *)pinfo->private_data;
pinfo->match_string = contentTypeStr;
pinfo->private_data = NULL;
call_dissector(media_handle, tmp_tvb, pinfo, tree);
pinfo->private_data = save_private_data;
#if 0
if (tree) / * Only display if needed * /
proto_tree_add_item (wsp_tree,
hf_wsp_reply_data,
tmp_tvb, 0, -1, ENC_NA);
#endif
}
}
}
break;
case WSP_PDU_PUSH:
case WSP_PDU_CONFIRMEDPUSH:
count = 0;
headersLength = tvb_get_guintvar (tvb, offset, &count);
headerStart = offset + count;
if (tree)
proto_tree_add_uint (wsp_tree, hf_wsp_header_length,
tvb, offset, count, headersLength);
if (headersLength == 0)
break;
offset += count;
contentTypeStart = offset;
nextOffset = add_content_type (wsp_tree,
tvb, offset, &contentType, &contentTypeStr);
if (tree) {
if (contentTypeStr) {
proto_item_append_text(proto_ti, ", Content-Type: %s",
contentTypeStr);
} else {
proto_item_append_text(proto_ti, ", Content-Type: 0x%X",
contentType);
}
headerLength = headersLength-(nextOffset-contentTypeStart);
if (headerLength > 0)
{
tmp_tvb = tvb_new_subset (tvb, nextOffset,
headerLength, headerLength);
add_headers (wsp_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
}
if (tvb_reported_length_remaining(tvb, headerStart + headersLength)
> 0)
{
tmp_tvb = tvb_new_subset_remaining (tvb, headerStart + headersLength);
found_match = FALSE;
if (contentTypeStr) {
found_match = dissector_try_string(media_type_table,
contentTypeStr, tmp_tvb, pinfo, tree);
}
if (! found_match) {
if (! dissector_try_heuristic(heur_subdissector_list,
tmp_tvb, pinfo, tree, NULL)) {
guint8* save_private_data = (guint8 *)pinfo->private_data;
pinfo->match_string = contentTypeStr;
pinfo->private_data = NULL;
call_dissector(media_handle, tmp_tvb, pinfo, tree);
pinfo->private_data = save_private_data;
#if 0
if (tree)
proto_tree_add_item (wsp_tree,
hf_wsp_push_data,
tmp_tvb, 0, -1, ENC_NA);
#endif
}
}
}
break;
}
stat_info->pdut = pdut;
tap_queue_packet (wsp_tap, pinfo, stat_info);
}
static void
dissect_wsp_fromudp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WSP");
col_clear(pinfo->cinfo, COL_INFO);
dissect_wsp_common(tvb, pinfo, tree, wsp_fromudp_handle, TRUE);
}
static void
dissect_wsp_fromwap_co(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_wsp_common(tvb, pinfo, tree, wtp_fromudp_handle, FALSE);
}
static void
dissect_wsp_fromwap_cl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_clear(pinfo->cinfo, COL_INFO);
dissect_wsp_common(tvb, pinfo, tree, wtp_fromudp_handle, TRUE);
}
static void
add_uri (proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
guint URILenOffset, guint URIOffset, proto_item *proto_ti)
{
guint count = 0;
guint uriLen = tvb_get_guintvar (tvb, URILenOffset, &count);
gchar *str;
proto_tree_add_uint (tree, hf_wsp_header_uri_len,
tvb, URILenOffset, count, uriLen);
tvb_ensure_bytes_exist(tvb, URIOffset, uriLen);
proto_tree_add_item (tree, hf_wsp_header_uri,
tvb, URIOffset, uriLen, ENC_ASCII|ENC_NA);
str = tvb_format_text (tvb, URIOffset, uriLen);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", str);
if (proto_ti)
proto_item_append_text(proto_ti, ", URI: %s", str);
}
static void
add_capabilities (proto_tree *tree, tvbuff_t *tvb, guint8 pdu_type)
{
proto_tree *wsp_capabilities;
proto_tree *capa_subtree;
proto_item *ti;
char *capaName, *str, *valStr;
guint32 offset = 0;
guint32 len = 0;
guint32 capaStart = 0;
guint32 capaLen = 0;
guint32 capaValueLen = 0;
guint32 tvb_len = tvb_reported_length(tvb);
gboolean ok = FALSE;
guint8 peek;
guint32 value;
if (tvb_len == 0) {
DebugLog(("add_capabilities(): Capabilities = 0\n"));
return;
}
DebugLog(("add_capabilities(): capabilities to process\n"));
ti = proto_tree_add_item(tree, hf_capabilities_section,
tvb, 0, tvb_len, ENC_NA);
wsp_capabilities = proto_item_add_subtree(ti, ett_capabilities);
while (offset < tvb_len) {
capaStart = offset;
capaValueLen = tvb_get_guintvar(tvb, offset, &len);
capaLen = capaValueLen + len;
tvb_ensure_bytes_exist(tvb, offset, capaLen);
offset += len;
peek = tvb_get_guint8(tvb, offset);
if (is_token_text(peek)) {
get_token_text(capaName, tvb, offset, len, ok);
if (! ok) {
DebugLog(("add_capabilities(): expecting capability name as token_text "
"at offset %u (1st char = 0x%02x)\n", offset, peek));
return;
}
if (g_ascii_strcasecmp(capaName, "client-sdu-size") == 0) {
peek = WSP_CAPA_CLIENT_SDU_SIZE;
} else if (g_ascii_strcasecmp(capaName, "server-sdu-size") == 0) {
peek = WSP_CAPA_SERVER_SDU_SIZE;
} else if (g_ascii_strcasecmp(capaName, "protocol options") == 0) {
peek = WSP_CAPA_PROTOCOL_OPTIONS;
} else if (g_ascii_strcasecmp(capaName, "method-mor") == 0) {
peek = WSP_CAPA_METHOD_MOR;
} else if (g_ascii_strcasecmp(capaName, "push-mor") == 0) {
peek = WSP_CAPA_PUSH_MOR;
} else if (g_ascii_strcasecmp(capaName, "extended methods") == 0) {
peek = WSP_CAPA_EXTENDED_METHODS;
} else if (g_ascii_strcasecmp(capaName, "header code pages") == 0) {
peek = WSP_CAPA_HEADER_CODE_PAGES;
} else if (g_ascii_strcasecmp(capaName, "aliases") == 0) {
peek = WSP_CAPA_ALIASES;
} else if (g_ascii_strcasecmp(capaName, "client-message-size") == 0) {
peek = WSP_CAPA_CLIENT_MESSAGE_SIZE;
} else if (g_ascii_strcasecmp(capaName, "server-message-size") == 0) {
peek = WSP_CAPA_SERVER_MESSAGE_SIZE;
} else {
DebugLog(("add_capabilities(): unknown capability '%s' at offset %u\n",
capaName, offset));
proto_tree_add_text(wsp_capabilities, tvb, capaStart, capaLen,
"Unknown or invalid textual capability: %s", capaName);
offset = capaStart + capaLen;
continue;
}
offset += len;
} else if (peek < 0x80) {
DebugLog(("add_capabilities(): invalid capability type identifier 0x%02X at offset %u.",
peek, offset - 1));
proto_tree_add_text(wsp_capabilities, tvb, capaStart, capaLen,
"Invalid well-known capability: 0x%02X", peek);
return;
}
if (peek & 0x80) {
peek &= 0x7F;
len = 1;
offset++;
}
switch (peek) {
case WSP_CAPA_CLIENT_SDU_SIZE:
value = tvb_get_guintvar(tvb, offset, &len);
DebugLog(("add_capabilities(client-sdu-size): "
"guintvar = %u (0x%X) at offset %u (1st byte = 0x%02X) (len = %u)\n",
value, value, offset, tvb_get_guint8(tvb, offset), len));
proto_tree_add_uint(wsp_capabilities, hf_capa_client_sdu_size,
tvb, capaStart, capaLen, value);
break;
case WSP_CAPA_SERVER_SDU_SIZE:
value = tvb_get_guintvar(tvb, offset, &len);
DebugLog(("add_capabilities(server-sdu-size): "
"guintvar = %u (0x%X) at offset %u (1st byte = 0x%02X) (len = %u)\n",
value, value, offset, tvb_get_guint8(tvb, offset), len));
proto_tree_add_uint(wsp_capabilities, hf_capa_server_sdu_size,
tvb, capaStart, capaLen, value);
break;
case WSP_CAPA_PROTOCOL_OPTIONS:
ti = proto_tree_add_string(wsp_capabilities, hf_capa_protocol_options,
tvb, capaStart, capaLen, "");
capa_subtree = proto_item_add_subtree(ti, ett_capability);
switch (capaValueLen - len) {
case 1:
value = tvb_get_guint8(tvb, offset);
len = 1;
break;
default:
DebugLog(("add_capabilities(protocol options): "
"bit field too large (%u bytes)\n",
capaValueLen));
proto_item_append_text(ti,
" <warning: bit field too large>");
offset = capaStart + capaLen;
continue;
}
DebugLog(("add_capabilities(protocol options): "
"guintvar = %u (0x%X) at offset %u (1st byte = 0x%02X) (len = %u)\n",
value, value, offset, tvb_get_guint8(tvb, offset), len));
if (value & 0x80)
proto_item_append_string(ti, " (confirmed push facility)");
if (value & 0x40)
proto_item_append_string(ti, " (push facility)");
if (value & 0x20)
proto_item_append_string(ti, " (session resume facility)");
if (value & 0x10)
proto_item_append_string(ti, " (acknowledgement headers)");
if (value & 0x08)
proto_item_append_string(ti, " (large data transfer)");
if (value & 0xFFFFFF07)
proto_item_append_text(ti, " <warning: reserved bits have been set>");
proto_tree_add_boolean(capa_subtree,
hf_capa_protocol_option_confirmed_push,
tvb, offset, len, value);
proto_tree_add_boolean(capa_subtree,
hf_capa_protocol_option_push,
tvb, offset, len, value);
proto_tree_add_boolean(capa_subtree,
hf_capa_protocol_option_session_resume,
tvb, offset, len, value);
proto_tree_add_boolean(capa_subtree,
hf_capa_protocol_option_ack_headers,
tvb, offset, len, value);
proto_tree_add_boolean(capa_subtree,
hf_capa_protocol_option_large_data_transfer,
tvb, offset, len, value);
break;
case WSP_CAPA_METHOD_MOR:
value = tvb_get_guint8(tvb, offset);
proto_tree_add_uint (wsp_capabilities,
hf_capa_method_mor,
tvb, capaStart, capaLen, value);
break;
case WSP_CAPA_PUSH_MOR:
value = tvb_get_guint8(tvb, offset);
proto_tree_add_uint (wsp_capabilities,
hf_capa_push_mor,
tvb, capaStart, capaLen, value);
break;
case WSP_CAPA_EXTENDED_METHODS:
ti = proto_tree_add_string(wsp_capabilities,
hf_capa_extended_methods,
tvb, capaStart, capaLen, "");
if (pdu_type == WSP_PDU_CONNECT) {
while (offset < capaStart + capaLen) {
peek = tvb_get_guint8(tvb, offset++);
get_text_string(str, tvb, offset, len, ok);
if (! ok) {
proto_item_append_text(ti, " <error: invalid capability encoding>");
DebugLog(("add_capability(extended methods): "
"invalid method name at offset %u "
"(octet = 0x%02X)\n",
offset, tvb_get_guint8(tvb, offset)));
return;
}
valStr = wmem_strdup_printf(wmem_packet_scope(), " (0x%02x = %s)", peek, str);
DebugLog(("add_capabilities(extended methods):%s\n",
valStr));
proto_item_append_string(ti, valStr);
offset += len;
}
} else {
while (offset < capaStart + capaLen) {
peek = tvb_get_guint8(tvb, offset++);
valStr = wmem_strdup_printf(wmem_packet_scope(), " (0x%02x)", peek);
DebugLog(("add_capabilities(extended methods):%s\n",
valStr));
proto_item_append_string(ti, valStr);
}
}
break;
case WSP_CAPA_HEADER_CODE_PAGES:
ti = proto_tree_add_string(wsp_capabilities,
hf_capa_header_code_pages,
tvb, capaStart, capaLen, "");
if (pdu_type == WSP_PDU_CONNECT) {
while (offset < capaStart + capaLen) {
peek = tvb_get_guint8(tvb, offset++);
get_text_string(str, tvb, offset, len, ok);
if (! ok) {
proto_item_append_text(ti,
" <error: invalid capability encoding>");
DebugLog(("add_capability(header code pages): "
"invalid header code page name at offset %u "
"(octet = 0x%02X)\n",
offset, tvb_get_guint8(tvb, offset)));
return;
}
valStr = wmem_strdup_printf(wmem_packet_scope(), " (0x%02x = %s)", peek, str);
DebugLog(("add_capabilities(header code pages):%s\n",
valStr));
proto_item_append_string(ti, valStr);
offset += len;
}
} else {
while (offset < capaStart + capaLen) {
peek = tvb_get_guint8(tvb, offset++);
valStr = wmem_strdup_printf(wmem_packet_scope(), " (0x%02x)", peek);
DebugLog(("add_capabilities(header code pages):%s\n",
valStr));
proto_item_append_string(ti, valStr);
}
}
break;
case WSP_CAPA_ALIASES:
proto_tree_add_item(wsp_capabilities, hf_capa_aliases,
tvb, capaStart, capaLen, ENC_NA);
break;
case WSP_CAPA_CLIENT_MESSAGE_SIZE:
value = tvb_get_guintvar(tvb, offset, &len);
DebugLog(("add_capabilities(client-message-size): "
"guintvar = %u (0x%X) at offset %u (1st byte = 0x%02X) (len = %u)\n",
value, value, offset, tvb_get_guint8(tvb, offset), len));
proto_tree_add_uint(wsp_capabilities, hf_capa_client_message_size,
tvb, capaStart, capaLen, value);
break;
case WSP_CAPA_SERVER_MESSAGE_SIZE:
value = tvb_get_guintvar(tvb, offset, &len);
DebugLog(("add_capabilities(server-message-size): "
"guintvar = %u (0x%X) at offset %u (1st byte = 0x%02X) (len = %u)\n",
value, value, offset, tvb_get_guint8(tvb, offset), len));
proto_tree_add_uint(wsp_capabilities, hf_capa_server_message_size,
tvb, capaStart, capaLen, value);
break;
default:
proto_tree_add_text(wsp_capabilities, tvb, capaStart, capaLen,
"Unknown well-known capability: 0x%02X", peek);
break;
}
offset = capaStart + capaLen;
}
}
void
add_post_data (proto_tree *tree, tvbuff_t *tvb, guint contentType,
const char *contentTypeStr, packet_info *pinfo)
{
guint offset = 0;
guint variableStart = 0;
guint variableEnd = 0;
guint valueStart = 0;
guint8 peek = 0;
proto_item *ti;
proto_tree *sub_tree = NULL;
DebugLog(("add_post_data() - START\n"));
if (tree) {
ti = proto_tree_add_item (tree, hf_wsp_post_data,
tvb, offset, -1, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_post);
}
if ( (contentTypeStr == NULL && contentType == 0x12)
|| (contentTypeStr && (g_ascii_strcasecmp(contentTypeStr,
"application/x-www-form-urlencoded") == 0)) )
{
if (tree) {
for (offset = 0; offset < tvb_reported_length (tvb); offset++)
{
peek = tvb_get_guint8 (tvb, offset);
if (peek == '=')
{
variableEnd = offset;
valueStart = offset+1;
}
else if (peek == '&')
{
if (variableEnd > 0)
{
add_post_variable (sub_tree, tvb, variableStart, variableEnd, valueStart, offset);
}
variableStart = offset+1;
variableEnd = 0;
valueStart = 0;
}
}
if (variableEnd > 0)
{
add_post_variable (sub_tree, tvb, variableStart, variableEnd, valueStart, offset);
}
}
}
else if ((contentType == 0x22) || (contentType == 0x23) || (contentType == 0x24) ||
(contentType == 0x25) || (contentType == 0x26) || (contentType == 0x33))
{
add_multipart_data(sub_tree, tvb, pinfo);
}
DebugLog(("add_post_data() - END\n"));
}
static void
add_post_variable (proto_tree *tree, tvbuff_t *tvb, guint variableStart, guint variableEnd, guint valueStart, guint valueEnd)
{
int variableLength = variableEnd-variableStart;
int valueLength = 0;
char *variableBuffer;
char *valueBuffer;
variableBuffer = tvb_get_string(wmem_packet_scope(), tvb, variableStart, variableLength);
if (valueEnd < valueStart)
{
valueBuffer = (char *)wmem_alloc(wmem_packet_scope(), 1);
valueBuffer[0] = 0;
valueEnd = valueStart;
}
else
{
valueLength = valueEnd-valueStart;
valueBuffer = tvb_get_string(wmem_packet_scope(), tvb, valueStart, valueLength);
}
if (valueStart >= tvb_reported_length (tvb))
{
valueStart = tvb_reported_length (tvb);
valueEnd = valueStart;
}
valueLength = valueEnd-valueStart;
proto_tree_add_text (tree, tvb, variableStart, valueLength, "%s: %s", variableBuffer, valueBuffer);
}
static void
add_multipart_data (proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo)
{
int offset = 0;
guint nextOffset;
guint nEntries = 0;
guint count;
guint HeadersLen;
guint DataLen;
guint contentType = 0;
const char *contentTypeStr;
tvbuff_t *tmp_tvb;
int partnr = 1;
int part_start;
gboolean found_match = FALSE;
proto_item *sub_tree = NULL;
proto_item *ti = NULL;
proto_tree *mpart_tree = NULL;
DebugLog(("add_multipart_data(): offset = %u, byte = 0x%02x: ",
offset, tvb_get_guint8(tvb,offset)));
nEntries = tvb_get_guintvar (tvb, offset, &count);
DebugLog(("parts = %u\n", nEntries));
offset += count;
if (nEntries)
{
ti = proto_tree_add_text(tree, tvb, offset - count, 0,
"Multipart body");
sub_tree = proto_item_add_subtree(ti, ett_mpartlist);
}
while (nEntries--)
{
DebugLog(("add_multipart_data(): Parts to do after this: %u"
" (offset = %u, 0x%02x): ",
nEntries, offset, tvb_get_guint8(tvb,offset)));
part_start = offset;
HeadersLen = tvb_get_guintvar (tvb, offset, &count);
offset += count;
DataLen = tvb_get_guintvar (tvb, offset, &count);
offset += count;
if (tree) {
tvb_ensure_bytes_exist(tvb, part_start, HeadersLen + DataLen + (offset - part_start));
ti = proto_tree_add_uint(sub_tree, hf_wsp_mpart, tvb, part_start,
HeadersLen + DataLen + (offset - part_start), partnr);
mpart_tree = proto_item_add_subtree(ti, ett_multiparts);
}
nextOffset = add_content_type (mpart_tree, tvb, offset,
&contentType, &contentTypeStr);
if (tree) {
if (contentTypeStr) {
proto_item_append_text(ti, ", content-type: %s",
contentTypeStr);
} else {
proto_item_append_text(ti, ", content-type: 0x%X",
contentType);
}
}
HeadersLen -= (nextOffset - offset);
if (HeadersLen > 0)
{
tmp_tvb = tvb_new_subset (tvb, nextOffset, HeadersLen, HeadersLen);
add_headers (mpart_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
offset = nextOffset + HeadersLen;
tmp_tvb = tvb_new_subset(tvb, offset, DataLen, DataLen);
found_match = FALSE;
if (contentTypeStr) {
found_match = dissector_try_string(media_type_table,
contentTypeStr, tmp_tvb, pinfo, mpart_tree);
}
if (! found_match) {
if (! dissector_try_heuristic(heur_subdissector_list,
tmp_tvb, pinfo, mpart_tree, NULL)) {
guint8* save_private_data = (guint8 *)pinfo->private_data;
pinfo->match_string = contentTypeStr;
pinfo->private_data = NULL;
call_dissector(media_handle, tmp_tvb, pinfo, mpart_tree);
pinfo->private_data = save_private_data;
#if 0
if (tree)
proto_tree_add_item (mpart_tree, hf_wsp_multipart_data,
tvb, offset, DataLen, ENC_NA);
#endif
}
}
offset += DataLen;
partnr++;
}
}
void
proto_register_wsp(void)
{
static hf_register_info hf[] = {
{ &hf_wsp_header_tid,
{ "Transaction ID",
"wsp.TID",
FT_UINT8, BASE_HEX, NULL, 0x00,
"WSP Transaction ID (for connectionless WSP)", HFILL
}
},
{ &hf_wsp_header_pdu_type,
{ "PDU Type",
"wsp.pdu_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &wsp_vals_pdu_type_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_version_major,
{ "Version (Major)",
"wsp.version.major",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL
}
},
{ &hf_wsp_version_minor,
{ "Version (Minor)",
"wsp.version.minor",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL
}
},
{ &hf_capabilities_length,
{ "Capabilities Length",
"wsp.capabilities.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Length of Capabilities field (bytes)", HFILL
}
},
{ &hf_wsp_header_length,
{ "Headers Length",
"wsp.headers_length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Length of Headers field (bytes)", HFILL
}
},
{ &hf_capabilities_section,
{ "Capabilities",
"wsp.capabilities",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_headers_section,
{ "Headers",
"wsp.headers",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_header_uri_len,
{ "URI Length",
"wsp.uri_length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Length of URI field", HFILL
}
},
{ &hf_wsp_header_uri,
{ "URI",
"wsp.uri",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_server_session_id,
{ "Server Session ID",
"wsp.server.session_id",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_header_status,
{ "Status",
"wsp.reply.status",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &wsp_vals_status_ext, 0x00,
"Reply Status", HFILL
}
},
{ &hf_wsp_parameter_type,
{ "Type",
"wsp.parameter.type",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Type parameter", HFILL
}
},
{ &hf_wsp_parameter_name,
{ "Name",
"wsp.parameter.name",
FT_STRING, BASE_NONE, NULL, 0x00,
"Name parameter", HFILL
}
},
{ &hf_wsp_parameter_filename,
{ "Filename",
"wsp.parameter.filename",
FT_STRING, BASE_NONE, NULL, 0x00,
"Filename parameter", HFILL
}
},
{ &hf_wsp_parameter_start,
{ "Start",
"wsp.parameter.start",
FT_STRING, BASE_NONE, NULL, 0x00,
"Start parameter", HFILL
}
},
{ &hf_wsp_parameter_start_info,
{ "Start-info",
"wsp.parameter.start_info",
FT_STRING, BASE_NONE, NULL, 0x00,
"Start-info parameter", HFILL
}
},
{ &hf_wsp_parameter_comment,
{ "Comment",
"wsp.parameter.comment",
FT_STRING, BASE_NONE, NULL, 0x00,
"Comment parameter", HFILL
}
},
{ &hf_wsp_parameter_domain,
{ "Domain",
"wsp.parameter.domain",
FT_STRING, BASE_NONE, NULL, 0x00,
"Domain parameter", HFILL
}
},
{ &hf_wsp_parameter_path,
{ "Path",
"wsp.parameter.path",
FT_STRING, BASE_NONE, NULL, 0x00,
"Path parameter", HFILL
}
},
{ &hf_wsp_parameter_sec,
{ "SEC",
"wsp.parameter.sec",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &vals_wsp_parameter_sec_ext, 0x00,
"SEC parameter (Content-Type: application/vnd.wap.connectivity-wbxml)", HFILL
}
},
{ &hf_wsp_parameter_mac,
{ "MAC",
"wsp.parameter.mac",
FT_STRING, BASE_NONE, NULL, 0x00,
"MAC parameter (Content-Type: application/vnd.wap.connectivity-wbxml)", HFILL
}
},
{ &hf_wsp_parameter_upart_type,
{ "Type",
"wsp.parameter.upart.type",
FT_STRING, BASE_NONE, NULL, 0x00,
"Multipart type parameter", HFILL
}
},
{ &hf_wsp_parameter_level,
{ "Level",
"wsp.parameter.level",
FT_STRING, BASE_NONE, NULL, 0x00,
"Level parameter", HFILL
}
},
{ &hf_wsp_parameter_size,
{ "Size",
"wsp.parameter.size",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Size parameter", HFILL
}
},
#if 0
{ &hf_wsp_reply_data,
{ "Data",
"wsp.reply.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
#endif
{ &hf_wsp_header_shift_code,
{ "Switching to WSP header code-page",
"wsp.code_page",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Header code-page shift code", HFILL
}
},
{ &hf_capa_client_sdu_size,
{ "Client SDU Size",
"wsp.capability.client_sdu_size",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Client Service Data Unit size (bytes)", HFILL
}
},
{ &hf_capa_server_sdu_size,
{ "Server SDU Size",
"wsp.capability.server_sdu_size",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Server Service Data Unit size (bytes)", HFILL
}
},
{ &hf_capa_protocol_options,
{ "Protocol Options",
"wsp.capability.protocol_opt",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_capa_protocol_option_confirmed_push,
{ "Confirmed Push facility",
"wsp.capability.protocol_option.confirmed_push",
FT_BOOLEAN, 8, NULL, 0x80,
"If set, this CO-WSP session supports the Confirmed Push facility", HFILL
}
},
{ &hf_capa_protocol_option_push,
{ "Push facility",
"wsp.capability.protocol_option.push",
FT_BOOLEAN, 8, NULL, 0x40,
"If set, this CO-WSP session supports the Push facility", HFILL
}
},
{ &hf_capa_protocol_option_session_resume,
{ "Session Resume facility",
"wsp.capability.protocol_option.session_resume",
FT_BOOLEAN, 8, NULL, 0x20,
"If set, this CO-WSP session supports the Session Resume facility", HFILL
}
},
{ &hf_capa_protocol_option_ack_headers,
{ "Acknowledgement headers",
"wsp.capability.protocol_option.ack_headers",
FT_BOOLEAN, 8, NULL, 0x10,
"If set, this CO-WSP session supports Acknowledgement headers", HFILL
}
},
{ &hf_capa_protocol_option_large_data_transfer,
{ "Large data transfer",
"wsp.capability.protocol_option.large_data_transfer",
FT_BOOLEAN, 8, NULL, 0x08,
"If set, this CO-WSP session supports Large data transfer", HFILL
}
},
{ &hf_capa_method_mor,
{ "Method MOR",
"wsp.capability.method_mor",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_capa_push_mor,
{ "Push MOR",
"wsp.capability.push_mor",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_capa_extended_methods,
{ "Extended Methods",
"wsp.capability.extended_methods",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_capa_header_code_pages,
{ "Header Code Pages",
"wsp.capability.code_pages",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_capa_aliases,
{ "Aliases",
"wsp.capability.aliases",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_capa_client_message_size,
{ "Client Message Size",
"wsp.capability.client_message_size",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Client Message size (bytes)", HFILL
}
},
{ &hf_capa_server_message_size,
{ "Server Message Size",
"wsp.capability.server_message_size",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Server Message size (bytes)", HFILL
}
},
{ &hf_wsp_post_data,
{ "Data (Post)",
"wsp.post.data",
FT_NONE, BASE_NONE, NULL, 0x00,
"Post Data", HFILL
}
},
#if 0
{ &hf_wsp_push_data,
{ "Push Data",
"wsp.push.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_multipart_data,
{ "Data in this part",
"wsp.multipart.data",
FT_NONE, BASE_NONE, NULL, 0x00,
"The data of 1 MIME-multipart part.", HFILL
}
},
#endif
{ &hf_wsp_mpart,
{ "Part",
"wsp.multipart",
FT_UINT32, BASE_DEC, NULL, 0x00,
"MIME part of multipart data.", HFILL
}
},
{ &hf_wsp_redirect_flags,
{ "Flags",
"wsp.redirect.flags",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Redirect Flags", HFILL
}
},
{ &hf_wsp_redirect_permanent,
{ "Permanent Redirect",
"wsp.redirect.flags.permanent",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PERMANENT_REDIRECT,
NULL, HFILL
}
},
{ &hf_wsp_redirect_reuse_security_session,
{ "Reuse Security Session",
"wsp.redirect.flags.reuse_security_session",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), REUSE_SECURITY_SESSION,
"If set, the existing Security Session may be reused", HFILL
}
},
{ &hf_redirect_addresses,
{ "Redirect Addresses",
"wsp.redirect.addresses",
FT_NONE, BASE_NONE, NULL, 0x00,
"List of Redirect Addresses", HFILL
}
},
{ &hf_address_entry,
{ "Address Record",
"wsp.address",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_address_flags_length,
{ "Flags/Length",
"wsp.address.flags",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Address Flags/Length", HFILL
}
},
{ &hf_address_flags_length_bearer_type_included,
{ "Bearer Type Included",
"wsp.address.flags.bearer_type_included",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), BEARER_TYPE_INCLUDED,
"Address bearer type included", HFILL
}
},
{ &hf_address_flags_length_port_number_included,
{ "Port Number Included",
"wsp.address.flags.port_number_included",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PORT_NUMBER_INCLUDED,
"Address port number included", HFILL
}
},
{ &hf_address_flags_length_address_len,
{ "Address Length",
"wsp.address.flags.length",
FT_UINT8, BASE_DEC, NULL, ADDRESS_LEN,
NULL, HFILL
}
},
{ &hf_address_bearer_type,
{ "Bearer Type",
"wsp.address.bearer_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &vals_bearer_types_ext, 0x0,
NULL, HFILL
}
},
{ &hf_address_port_num,
{ "Port Number",
"wsp.address.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_address_ipv4_addr,
{ "IPv4 Address",
"wsp.address.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Address (IPv4)", HFILL
}
},
{ &hf_address_ipv6_addr,
{ "IPv6 Address",
"wsp.address.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Address (IPv6)", HFILL
}
},
{ &hf_address_addr,
{ "Address",
"wsp.address.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Address (unknown)", HFILL
}
},
{ &hf_hdr_name,
{ "Header name",
"wsp.header.name",
FT_STRING, BASE_NONE, NULL, 0x00,
"Name of the WSP header", HFILL
}
},
{ &hf_hdr_accept,
{ "Accept",
"wsp.header.accept",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Accept", HFILL
}
},
{ &hf_hdr_accept_charset,
{ "Accept-Charset",
"wsp.header.accept_charset",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Accept-Charset", HFILL
}
},
{ &hf_hdr_accept_encoding,
{ "Accept-Encoding",
"wsp.header.accept_encoding",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Accept-Encoding", HFILL
}
},
{ &hf_hdr_accept_language,
{ "Accept-Language",
"wsp.header.accept_language",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Accept-Language", HFILL
}
},
{ &hf_hdr_accept_ranges,
{ "Accept-Ranges",
"wsp.header.accept_ranges",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Accept-Ranges", HFILL
}
},
{ &hf_hdr_age,
{ "Age",
"wsp.header.age",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Age", HFILL
}
},
{ &hf_hdr_allow,
{ "Allow",
"wsp.header.allow",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Allow", HFILL
}
},
{ &hf_hdr_authorization,
{ "Authorization",
"wsp.header.authorization",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Authorization", HFILL
}
},
{ &hf_hdr_authorization_scheme,
{ "Authorization Scheme",
"wsp.header.authorization.scheme",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Authorization: used scheme", HFILL
}
},
{ &hf_hdr_authorization_user_id,
{ "User-id",
"wsp.header.authorization.user_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Authorization: user ID for basic authorization", HFILL
}
},
{ &hf_hdr_authorization_password,
{ "Password",
"wsp.header.authorization.password",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Authorization: password for basic authorization", HFILL
}
},
{ &hf_hdr_cache_control,
{ "Cache-Control",
"wsp.header.cache_control",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Cache-Control", HFILL
}
},
{ &hf_hdr_connection,
{ "Connection",
"wsp.header.connection",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Connection", HFILL
}
},
{ &hf_hdr_content_base,
{ "Content-Base",
"wsp.header.content_base",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Base", HFILL
}
},
{ &hf_hdr_content_encoding,
{ "Content-Encoding",
"wsp.header.content_encoding",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Encoding", HFILL
}
},
{ &hf_hdr_content_language,
{ "Content-Language",
"wsp.header.content_language",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Language", HFILL
}
},
{ &hf_hdr_content_length,
{ "Content-Length",
"wsp.header.content_length",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Length", HFILL
}
},
{ &hf_hdr_content_location,
{ "Content-Location",
"wsp.header.content_location",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Location", HFILL
}
},
{ &hf_hdr_content_md5,
{ "Content-Md5",
"wsp.header.content_md5",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Md5", HFILL
}
},
{ &hf_hdr_content_range,
{ "Content-Range",
"wsp.header.content_range",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Range", HFILL
}
},
{ &hf_hdr_content_range_first_byte_pos,
{ "First-byte-position",
"wsp.header.content_range.first_byte_pos",
FT_UINT32, BASE_DEC, NULL, 0x00,
"WSP header Content-Range: position of first byte", HFILL
}
},
{ &hf_hdr_content_range_entity_length,
{ "Entity-length",
"wsp.header.content_range.entity_length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"WSP header Content-Range: length of the entity", HFILL
}
},
{ &hf_hdr_content_type,
{ "Content-Type",
"wsp.header.content_type",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Type", HFILL
}
},
{ &hf_hdr_date,
{ "Date",
"wsp.header.date",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Date", HFILL
}
},
{ &hf_hdr_etag,
{ "ETag",
"wsp.header.etag",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header ETag", HFILL
}
},
{ &hf_hdr_expires,
{ "Expires",
"wsp.header.expires",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Expires", HFILL
}
},
{ &hf_hdr_from,
{ "From",
"wsp.header.from",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header From", HFILL
}
},
{ &hf_hdr_host,
{ "Host",
"wsp.header.host",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Host", HFILL
}
},
{ &hf_hdr_if_modified_since,
{ "If-Modified-Since",
"wsp.header.if_modified_since",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header If-Modified-Since", HFILL
}
},
{ &hf_hdr_if_match,
{ "If-Match",
"wsp.header.if_match",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header If-Match", HFILL
}
},
{ &hf_hdr_if_none_match,
{ "If-None-Match",
"wsp.header.if_none_match",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header If-None-Match", HFILL
}
},
{ &hf_hdr_if_range,
{ "If-Range",
"wsp.header.if_range",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header If-Range", HFILL
}
},
{ &hf_hdr_if_unmodified_since,
{ "If-Unmodified-Since",
"wsp.header.if_unmodified_since",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header If-Unmodified-Since", HFILL
}
},
{ &hf_hdr_last_modified,
{ "Last-Modified",
"wsp.header.last_modified",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Last-Modified", HFILL
}
},
{ &hf_hdr_location,
{ "Location",
"wsp.header.location",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Location", HFILL
}
},
{ &hf_hdr_max_forwards,
{ "Max-Forwards",
"wsp.header.max_forwards",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Max-Forwards", HFILL
}
},
{ &hf_hdr_pragma,
{ "Pragma",
"wsp.header.pragma",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Pragma", HFILL
}
},
{ &hf_hdr_proxy_authenticate,
{ "Proxy-Authenticate",
"wsp.header.proxy_authenticate",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Proxy-Authenticate", HFILL
}
},
{ &hf_hdr_proxy_authenticate_scheme,
{ "Authentication Scheme",
"wsp.header.proxy_authenticate.scheme",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Proxy-Authenticate: used scheme", HFILL
}
},
{ &hf_hdr_proxy_authenticate_realm,
{ "Authentication Realm",
"wsp.header.proxy_authenticate.realm",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Proxy-Authenticate: used realm", HFILL
}
},
{ &hf_hdr_proxy_authorization,
{ "Proxy-Authorization",
"wsp.header.proxy_authorization",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Proxy-Authorization", HFILL
}
},
{ &hf_hdr_proxy_authorization_scheme,
{ "Authorization Scheme",
"wsp.header.proxy_authorization.scheme",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Proxy-Authorization: used scheme", HFILL
}
},
{ &hf_hdr_proxy_authorization_user_id,
{ "User-id",
"wsp.header.proxy_authorization.user_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Proxy-Authorization: user ID for basic authorization", HFILL
}
},
{ &hf_hdr_proxy_authorization_password,
{ "Password",
"wsp.header.proxy_authorization.password",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Proxy-Authorization: password for basic authorization", HFILL
}
},
{ &hf_hdr_public,
{ "Public",
"wsp.header.public",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Public", HFILL
}
},
{ &hf_hdr_range,
{ "Range",
"wsp.header.range",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Range", HFILL
}
},
{ &hf_hdr_range_first_byte_pos,
{ "First-byte-position",
"wsp.header.range.first_byte_pos",
FT_UINT32, BASE_DEC, NULL, 0x00,
"WSP header Range: position of first byte", HFILL
}
},
{ &hf_hdr_range_last_byte_pos,
{ "Last-byte-position",
"wsp.header.range.last_byte_pos",
FT_UINT32, BASE_DEC, NULL, 0x00,
"WSP header Range: position of last byte", HFILL
}
},
{ &hf_hdr_range_suffix_length,
{ "Suffix-length",
"wsp.header.range.suffix_length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"WSP header Range: length of the suffix", HFILL
}
},
{ &hf_hdr_referer,
{ "Referer",
"wsp.header.referer",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Referer", HFILL
}
},
{ &hf_hdr_retry_after,
{ "Retry-After",
"wsp.header.retry_after",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Retry-After", HFILL
}
},
{ &hf_hdr_server,
{ "Server",
"wsp.header.server",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Server", HFILL
}
},
{ &hf_hdr_transfer_encoding,
{ "Transfer-Encoding",
"wsp.header.transfer_encoding",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Transfer-Encoding", HFILL
}
},
{ &hf_hdr_upgrade,
{ "Upgrade",
"wsp.header.upgrade",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Upgrade", HFILL
}
},
{ &hf_hdr_user_agent,
{ "User-Agent",
"wsp.header.user_agent",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header User-Agent", HFILL
}
},
{ &hf_hdr_vary,
{ "Vary",
"wsp.header.vary",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Vary", HFILL
}
},
{ &hf_hdr_via,
{ "Via",
"wsp.header.via",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Via", HFILL
}
},
{ &hf_hdr_warning,
{ "Warning",
"wsp.header.warning",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Warning", HFILL
}
},
{ &hf_hdr_warning_code,
{ "Warning code",
"wsp.header.warning.code",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &vals_wsp_warning_code_ext, 0x00,
"WSP header Warning code", HFILL
}
},
{ &hf_hdr_warning_agent,
{ "Warning agent",
"wsp.header.warning.agent",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Warning agent", HFILL
}
},
{ &hf_hdr_warning_text,
{ "Warning text",
"wsp.header.warning.text",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Warning text", HFILL
}
},
{ &hf_hdr_www_authenticate,
{ "Www-Authenticate",
"wsp.header.www_authenticate",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Www-Authenticate", HFILL
}
},
{ &hf_hdr_www_authenticate_scheme,
{ "Authentication Scheme",
"wsp.header.www_authenticate.scheme",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header WWW-Authenticate: used scheme", HFILL
}
},
{ &hf_hdr_www_authenticate_realm,
{ "Authentication Realm",
"wsp.header.www_authenticate.realm",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header WWW-Authenticate: used realm", HFILL
}
},
{ &hf_hdr_content_disposition,
{ "Content-Disposition",
"wsp.header.content_disposition",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Disposition", HFILL
}
},
{ &hf_hdr_application_id,
{ "Application-Id",
"wsp.header.application_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Application-Id", HFILL
}
},
{ &hf_hdr_content_uri,
{ "Content-Uri",
"wsp.header.content_uri",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Uri", HFILL
}
},
{ &hf_hdr_initiator_uri,
{ "Initiator-Uri",
"wsp.header.initiator_uri",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Initiator-Uri", HFILL
}
},
{ &hf_hdr_bearer_indication,
{ "Bearer-Indication",
"wsp.header.bearer_indication",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Bearer-Indication", HFILL
}
},
{ &hf_hdr_push_flag,
{ "Push-Flag",
"wsp.header.push_flag",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Push-Flag", HFILL
}
},
{ &hf_hdr_push_flag_auth,
{ "Initiator URI is authenticated",
"wsp.header.push_flag.authenticated",
FT_UINT8, BASE_DEC, VALS(vals_false_true), 0x01,
"The X-Wap-Initiator-URI has been authenticated.", HFILL
}
},
{ &hf_hdr_push_flag_trust,
{ "Content is trusted",
"wsp.header.push_flag.trusted",
FT_UINT8, BASE_DEC, VALS(vals_false_true), 0x02,
"The push content is trusted.", HFILL
}
},
{ &hf_hdr_push_flag_last,
{ "Last push message",
"wsp.header.push_flag.last",
FT_UINT8, BASE_DEC, VALS(vals_false_true), 0x04,
"Indicates whether this is the last push message.", HFILL
}
},
{ &hf_hdr_profile,
{ "Profile",
"wsp.header.profile",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Profile", HFILL
}
},
{ &hf_hdr_profile_diff,
{ "Profile-Diff",
"wsp.header.profile_diff",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Profile-Diff", HFILL
}
},
{ &hf_hdr_profile_warning,
{ "Profile-Warning",
"wsp.header.profile_warning",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Profile-Warning", HFILL
}
},
{ &hf_hdr_expect,
{ "Expect",
"wsp.header.expect",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Expect", HFILL
}
},
{ &hf_hdr_te,
{ "Te",
"wsp.header.te",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Te", HFILL
}
},
{ &hf_hdr_trailer,
{ "Trailer",
"wsp.header.trailer",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Trailer", HFILL
}
},
{ &hf_hdr_x_wap_tod,
{ "X-Wap-Tod",
"wsp.header.x_wap_tod",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header X-Wap-Tod", HFILL
}
},
{ &hf_hdr_content_id,
{ "Content-Id",
"wsp.header.content_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Content-Id", HFILL
}
},
{ &hf_hdr_set_cookie,
{ "Set-Cookie",
"wsp.header.set_cookie",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Set-Cookie", HFILL
}
},
{ &hf_hdr_cookie,
{ "Cookie",
"wsp.header.cookie",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Cookie", HFILL
}
},
{ &hf_hdr_encoding_version,
{ "Encoding-Version",
"wsp.header.encoding_version",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Encoding-Version", HFILL
}
},
{ &hf_hdr_x_wap_security,
{ "X-Wap-Security",
"wsp.header.x_wap_security",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header X-Wap-Security", HFILL
}
},
{ &hf_hdr_x_wap_application_id,
{ "X-Wap-Application-Id",
"wsp.header.x_wap_application_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header X-Wap-Application-Id", HFILL
}
},
{ &hf_hdr_accept_application,
{ "Accept-Application",
"wsp.header.accept_application",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP header Accept-Application", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_operator_domain,
{ "x-up-proxy-operator-domain",
"wsp.header.x_up_1.x_up_proxy_operator_domain",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-operator-domain", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_home_page,
{ "x-up-proxy-home-page",
"wsp.header.x_up_1.x_up_proxy_home_page",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-home-page", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_uplink_version,
{ "x-up-proxy-uplink-version",
"wsp.header.x_up_1.x_up_proxy_uplink_version",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-uplink-version", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_ba_realm,
{ "x-up-proxy-ba-realm",
"wsp.header.x_up_1.x_up_proxy_ba_realm",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-ba-realm", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_request_uri,
{ "x-up-proxy-request-uri",
"wsp.header.x_up_1.x_up_proxy_request_uri",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-request-uri", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_bookmark,
{ "x-up-proxy-bookmark",
"wsp.header.x_up_1.x_up_proxy_bookmark",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-bookmark", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_push_seq,
{ "x-up-proxy-push-seq",
"wsp.header.x_up_1.x_up_proxy_push_seq",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-push-seq", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_notify,
{ "x-up-proxy-notify",
"wsp.header.x_up_1.x_up_proxy_notify",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-notify", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_net_ask,
{ "x-up-proxy-net-ask",
"wsp.header.x_up_1.x_up_proxy_net_ask",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-net-ask", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_tod,
{ "x-up-proxy-tod",
"wsp.header.x_up_1.x_up_proxy_tod",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-tod", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_ba_enable,
{ "x-up-proxy-ba-enable",
"wsp.header.x_up_1.x_up_proxy_ba_enable",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-ba-enable", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_redirect_enable,
{ "x-up-proxy-redirect-enable",
"wsp.header.x_up_1.x_up_proxy_redirect_enable",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-redirect-enable", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_redirect_status,
{ "x-up-proxy-redirect-status",
"wsp.header.x_up_1.x_up_proxy_redirect_status",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-redirect-status", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_linger,
{ "x-up-proxy-linger",
"wsp.header.x_up_1.x_up_proxy_linger",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-linger", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_enable_trust,
{ "x-up-proxy-enable-trust",
"wsp.header.x_up_1.x_up_proxy_enable_trust",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-enable-trust", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_trust,
{ "x-up-proxy-trust",
"wsp.header.x_up_1.x_up_proxy_trust",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-trust", HFILL
}
},
{ &hf_hdr_openwave_x_up_devcap_has_color,
{ "x-up-devcap-has-color",
"wsp.header.x_up_1.x_up_devcap_has_color",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-devcap-has-color", HFILL
}
},
{ &hf_hdr_openwave_x_up_devcap_num_softkeys,
{ "x-up-devcap-num-softkeys",
"wsp.header.x_up_1.x_up_devcap_num_softkeys",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-devcap-num-softkeys", HFILL
}
},
{ &hf_hdr_openwave_x_up_devcap_softkey_size,
{ "x-up-devcap-softkey-size",
"wsp.header.x_up_1.x_up_devcap_softkey_size",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-devcap-softkey-size", HFILL
}
},
{ &hf_hdr_openwave_x_up_devcap_screen_chars,
{ "x-up-devcap-screen-chars",
"wsp.header.x_up_1.x_up_devcap_screen_chars",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-devcap-screen-chars", HFILL
}
},
{ &hf_hdr_openwave_x_up_devcap_screen_pixels,
{ "x-up-devcap-screen-pixels",
"wsp.header.x_up_1.x_up_devcap_screen_pixels",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-devcap-screen-pixels", HFILL
}
},
{ &hf_hdr_openwave_x_up_devcap_em_size,
{ "x-up-devcap-em-size",
"wsp.header.x_up_1.x_up_devcap_em_size",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-devcap-em-size", HFILL
}
},
{ &hf_hdr_openwave_x_up_devcap_screen_depth,
{ "x-up-devcap-screen-depth",
"wsp.header.x_up_1.x_up_devcap_screen_depth",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-devcap-screen-depth", HFILL
}
},
{ &hf_hdr_openwave_x_up_devcap_immed_alert,
{ "x-up-devcap-immed-alert",
"wsp.header.x_up_1.x_up_devcap_immed_alert",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-devcap-immed-alert", HFILL
}
},
{ &hf_hdr_openwave_x_up_devcap_gui,
{ "x-up-devcap-gui",
"wsp.header.x_up_1.x_up_devcap_gui",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-devcap-gui", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_trans_charset,
{ "x-up-proxy-trans-charset",
"wsp.header.x_up_1.x_up_proxy_trans_charset",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-trans-charset", HFILL
}
},
{ &hf_hdr_openwave_x_up_proxy_push_accept,
{ "x-up-proxy-push-accept",
"wsp.header.x_up_1.x_up_proxy_push_accept",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-push-accept", HFILL
}
},
#if 0
{ &hf_hdr_openwave_x_up_proxy_client_id,
{ "x-up-proxy-client-id",
"wsp.header.x_up_1.x_up_proxy_client_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"WSP Openwave header x-up-proxy-client-id", HFILL
}
},
#endif
{ &hf_parameter_q,
{ "Q",
"wsp.parameter.q",
FT_STRING, BASE_NONE, NULL, 0x00,
"Q parameter", HFILL
}
},
{ &hf_parameter_charset,
{ "Charset",
"wsp.parameter.charset",
FT_STRING, BASE_NONE, NULL, 0x00,
"Charset parameter", HFILL
}
}
};
static gint *ett[] = {
&ett_wsp,
&ett_header,
&ett_headers,
&ett_capabilities,
&ett_capability,
&ett_post,
&ett_redirect_flags,
&ett_address_flags,
&ett_multiparts,
&ett_mpartlist,
&ett_addresses,
&ett_address
};
proto_wsp = proto_register_protocol(
"Wireless Session Protocol",
"WSP",
"wsp"
);
wsp_tap = register_tap("wsp");
proto_register_field_array(proto_wsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("wsp-co", dissect_wsp_fromwap_co, proto_wsp);
register_dissector("wsp-cl", dissect_wsp_fromwap_cl, proto_wsp);
register_heur_dissector_list("wsp", &heur_subdissector_list);
wsp_fromudp_handle = create_dissector_handle(dissect_wsp_fromudp,
proto_wsp);
}
void
proto_reg_handoff_wsp(void)
{
wtp_fromudp_handle = find_dissector("wtp-udp");
media_handle = find_dissector("media");
wbxml_uaprof_handle = find_dissector("wbxml-uaprof");
dissector_add_uint("udp.port", UDP_PORT_WSP, wsp_fromudp_handle);
dissector_add_uint("udp.port", UDP_PORT_WSP_PUSH, wsp_fromudp_handle);
dissector_add_uint("gsm_sms_ud.udh.port", UDP_PORT_WSP, wsp_fromudp_handle);
dissector_add_uint("gsm_sms_ud.udh.port", UDP_PORT_WSP_PUSH, wsp_fromudp_handle);
dissector_add_uint("gsm_sms.udh.port", UDP_PORT_WSP, wsp_fromudp_handle);
dissector_add_uint("gsm_sms.udh.port", UDP_PORT_WSP_PUSH, wsp_fromudp_handle);
media_type_table = find_dissector_table("media_type");
}
void
proto_register_sir(void)
{
static hf_register_info hf[] = {
{ &hf_sir_section,
{ "Session Initiation Request",
"wap.sir",
FT_NONE, BASE_NONE, NULL, 0x00,
"Session Initiation Request content", HFILL
}
},
{ &hf_sir_version,
{ "Version",
"wap.sir.version",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Version of the Session Initiation Request document", HFILL
}
},
{ &hf_sir_app_id_list_len,
{ "Application-ID List Length",
"wap.sir.app_id_list.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Length of the Application-ID list (bytes)", HFILL
}
},
{ &hf_sir_app_id_list,
{ "Application-ID List",
"wap.sir.app_id_list",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_sir_wsp_contact_points_len,
{ "WSP Contact Points Length",
"wap.sir.wsp_contact_points.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Length of the WSP Contact Points list (bytes)", HFILL
}
},
{ &hf_sir_wsp_contact_points,
{ "WSP Contact Points",
"wap.sir.wsp_contact_points",
FT_NONE, BASE_NONE, NULL, 0x00,
"WSP Contact Points list", HFILL
}
},
{ &hf_sir_contact_points_len,
{ "Non-WSP Contact Points Length",
"wap.sir.contact_points.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Length of the Non-WSP Contact Points list (bytes)", HFILL
}
},
{ &hf_sir_contact_points,
{ "Non-WSP Contact Points",
"wap.sir.contact_points",
FT_NONE, BASE_NONE, NULL, 0x00,
"Non-WSP Contact Points list", HFILL
}
},
{ &hf_sir_protocol_options_len,
{ "Protocol Options List Entries",
"wap.sir.protocol_options.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Number of entries in the Protocol Options list", HFILL
}
},
{ &hf_sir_protocol_options,
{ "Protocol Options",
"wap.sir.protocol_options",
FT_UINT16, BASE_DEC, VALS(vals_sir_protocol_options), 0x00,
"Protocol Options list", HFILL
}
},
{ &hf_sir_prov_url_len,
{ "X-Wap-ProvURL Length",
"wap.sir.prov_url.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Length of the X-Wap-ProvURL (Identifies the WAP Client Provisioning Context)", HFILL
}
},
{ &hf_sir_prov_url,
{ "X-Wap-ProvURL",
"wap.sir.prov_url",
FT_STRING, BASE_NONE, NULL, 0x00,
"X-Wap-ProvURL (Identifies the WAP Client Provisioning Context)", HFILL
}
},
{ &hf_sir_cpi_tag_len,
{ "CPITag List Entries",
"wap.sir.cpi_tag.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Number of entries in the CPITag list", HFILL
}
},
{ &hf_sir_cpi_tag,
{ "CPITag",
"wap.sir.cpi_tag",
FT_BYTES, BASE_NONE, NULL, 0x00,
"CPITag (OTA-HTTP)", HFILL
}
}
};
static gint *ett[] = {
&ett_sir
};
proto_sir = proto_register_protocol(
"WAP Session Initiation Request",
"WAP SIR",
"wap-sir"
);
proto_register_field_array(proto_sir, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_sir(void)
{
dissector_handle_t sir_handle;
sir_handle = create_dissector_handle(dissect_sir, proto_sir);
dissector_add_string("media_type", "application/vnd.wap.sia", sir_handle);
}
