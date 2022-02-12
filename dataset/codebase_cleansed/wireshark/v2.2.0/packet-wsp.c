static guint32
wkh_default(proto_tree *tree, tvbuff_t *tvb,
guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint8 hdr_id = tvb_get_guint8 (tvb, hdr_start) & 0x7F;
ok = TRUE;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_default, "default");
proto_tree_add_uint_format(tree, hf_wsp_default_int, tvb, hdr_start, offset - hdr_start,
val_id & 0x7F, "%s: (Undecoded well-known value 0x%02x)",
val_to_str_ext (hdr_id, &vals_field_names_ext,
"<Unknown WSP header field 0x%02X>"), val_id & 0x7F);
wkh_2_TextualValue;
proto_tree_add_string_format(tree, hf_wsp_default_string, tvb, hdr_start, offset - hdr_start,
"%s: %s",
val_to_str_ext (hdr_id, &vals_field_names_ext,
"<Unknown WSP header field 0x%02X>"), val_str);
wkh_3_ValueWithLength;
proto_tree_add_uint_format(tree, hf_wsp_default_val_len, tvb, hdr_start, offset - hdr_start,
val_len, "%s: (Undecoded value in general form with length indicator)",
val_to_str_ext (hdr_id, &vals_field_names_ext,
"<Unknown WSP header field 0x%02X>"));
wkh_4_End();
}
static guint32
wkh_content_type_header(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo, int hf, const char* name)
{
wkh_0_Declarations;
guint32 off, val = 0, len;
guint8 peek;
proto_item *ti = NULL;
proto_tree *parameter_tree = NULL;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Content type: %s", name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_content_type_header, header_name);
proto_tree_add_string(header_tree, hf, tvb, val_start, 1,
val_to_str_ext(val_id & 0x7F, &vals_content_types_ext,
"(Unknown content type identifier 0x%X)"));
proto_item_set_len(header_item, 2);
ok = TRUE;
wkh_2_TextualValue;
if (*val_str) {
proto_tree_add_string(header_tree, hf, tvb, val_start, val_len, val_str);
proto_item_set_len(header_item, val_len+1);
} else {
proto_tree_add_string(header_tree, hf, tvb, val_start, 0,
"<no content type has been specified>");
proto_item_set_len(header_item, 2);
}
ok = TRUE;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
peek = tvb_get_guint8(tvb, off);
if (is_text_string(peek)) {
val_str = (gchar *)tvb_get_stringz_enc(wmem_packet_scope(), tvb, off, (gint*)&len, ENC_ASCII);
off += len;
ti = proto_tree_add_string (header_tree, hf, tvb, hdr_start, offset - hdr_start, val_str);
} else if (is_integer_value(peek)) {
get_integer_value(val, tvb, off, len, ok);
if (ok) {
ti = proto_tree_add_string(header_tree, hf,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val, &vals_content_types_ext,
"(Unknown content type identifier 0x%X)"));
}
off += len;
} else {
ok = FALSE;
}
if (ok && (off < offset)) {
parameter_tree = proto_item_add_subtree (ti, ett_header);
while (off < offset) {
off = parameter (parameter_tree, pinfo, ti, tvb, off, offset - off);
}
}
wkh_4_End();
}
static guint32
wkh_accept(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo)
{
return wkh_content_type_header(tree, tvb, hdr_start, pinfo, hf_hdr_accept, "Accept");
}
static guint32
wkh_content_type(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo)
{
return wkh_content_type_header(tree, tvb, hdr_start, pinfo, hf_hdr_content_type, "Content-Type");
}
guint32
add_content_type(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, guint32 val_start,
guint32 *well_known_content, const char **textual_content)
{
guint32 hdr_start = val_start;
guint8 val_id = tvb_get_guint8 (tvb, val_start);
guint32 offset = val_start;
guint32 val_len;
guint32 val_len_len;
gchar *val_str = NULL;
guint32 off, val = 0, len;
guint8 peek;
gboolean ok = FALSE;
proto_item *ti = NULL;
proto_tree *parameter_tree = NULL;
proto_tree *header_tree;
proto_item *header_item;
*textual_content = NULL;
*well_known_content = 0;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_add_content_type, "Content-Type");
*textual_content = val_to_str_ext(val_id & 0x7F, &vals_content_types_ext,
"<Unknown media type identifier 0x%X>");
proto_tree_add_string(tree, hf_hdr_content_type,
tvb, hdr_start, offset - hdr_start,
*textual_content);
*well_known_content = val_id & 0x7F;
ok = TRUE;
wkh_2_TextualValue;
if (*val_str) {
proto_tree_add_string(tree, hf_hdr_content_type,
tvb, hdr_start, offset - hdr_start,
val_str);
*textual_content = g_strdup(val_str);
*well_known_content = 0;
} else {
proto_tree_add_string(tree, hf_hdr_content_type,
tvb, hdr_start, offset - hdr_start,
"<no media type has been specified>");
*textual_content = NULL;
*well_known_content = 0;
}
ok = TRUE;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
peek = tvb_get_guint8(tvb, off);
if (is_text_string(peek)) {
get_extension_media(val_str, tvb, off, len, ok);
if (ok) {
off += len;
ti = proto_tree_add_string (tree, hf_hdr_content_type,
tvb, hdr_start, offset - hdr_start, val_str);
}
*textual_content = g_strdup(val_str);
*well_known_content = 0;
} else if (is_integer_value(peek)) {
get_integer_value(val, tvb, off, len, ok);
if (ok) {
*textual_content = val_to_str_ext(val, &vals_content_types_ext,
"<Unknown media type identifier 0x%X>");
ti = proto_tree_add_string(tree, hf_hdr_content_type,
tvb, hdr_start, offset - hdr_start,
*textual_content);
*well_known_content = val;
}
off += len;
}
if (ok && (off < offset)) {
parameter_tree = proto_item_add_subtree (ti, ett_header);
while (off < offset) {
off = parameter (parameter_tree, pinfo, ti, tvb, off, offset - off);
}
}
wkh_4_End();
}
static guint32
wkh_accept_x_q_header_func(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo,
int hf, const char* name, value_string_ext *valueStringExtAddr, const char* value_format)
{
wkh_0_Declarations;
guint32 off, val = 0, len;
guint8 peek;
proto_item *ti = NULL;
proto_tree *parameter_tree = NULL;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Accept X: %s", name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_accept_x_q_header, header_name);
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val_id & 0x7F, valueStringExtAddr, value_format));
ok = TRUE;
wkh_2_TextualValue;
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
peek = tvb_get_guint8(tvb, off);
if (is_text_string(peek)) {
get_token_text(val_str, tvb, off, len, ok);
if (ok) {
off += len;
ti = proto_tree_add_string (tree, hf,
tvb, hdr_start, offset - hdr_start, val_str);
}
} else if (is_integer_value(peek)) {
get_integer_value(val, tvb, off, len, ok);
if (ok) {
ti = proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val, valueStringExtAddr, value_format));
}
off += len;
}
if (ok && (off < offset)) {
parameter_tree = proto_item_add_subtree (ti, ett_header);
parameter_value_q (parameter_tree, pinfo, ti, tvb, off);
}
wkh_4_End();
}
static guint32
wkh_push_flag(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0a_Declarations;
proto_item *ti = NULL;
proto_tree *subtree = NULL;
wmem_strbuf_t *push_flag_str = wmem_strbuf_new(wmem_packet_scope(), "");
wkh_1_WellKnownValue(hf_hdr_name_value, ett_push_flag, "Push Flag");
if (val_id & 0x01)
wmem_strbuf_append(push_flag_str, " (Initiator URI authenticated)");
if (val_id & 0x02)
wmem_strbuf_append(push_flag_str, " (Content trusted)");
if (val_id & 0x04)
wmem_strbuf_append(push_flag_str, " (Last push message)");
if (val_id & 0x78)
wmem_strbuf_append(push_flag_str, " <Warning: Reserved flags set>");
else
ok = TRUE;
ti = proto_tree_add_string(tree, hf_hdr_push_flag,
tvb, hdr_start, offset - hdr_start, wmem_strbuf_get_str(push_flag_str));
subtree = proto_item_add_subtree(ti, ett_header);
proto_tree_add_uint(subtree, hf_hdr_push_flag_auth,
tvb, val_start, 1, val_id);
proto_tree_add_uint(subtree, hf_hdr_push_flag_trust,
tvb, val_start, 1, val_id);
proto_tree_add_uint(subtree, hf_hdr_push_flag_last,
tvb, val_start, 1, val_id);
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32 wkh_profile_diff_wbxml (proto_tree *tree, tvbuff_t *tvb,
guint32 hdr_start, packet_info *pinfo)
{
wkh_0a_Declarations;
tvbuff_t *tmp_tvb;
proto_item *ti = NULL;
proto_tree *subtree;
ok = TRUE;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_profile_diff_wbxml, "Profile-Diff (with WBXML)");
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
ti = proto_tree_add_string(tree, hf_hdr_profile_diff, tvb, hdr_start, offset - hdr_start,
"(Profile-Diff value as WBXML)");
subtree = proto_item_add_subtree(ti, ett_header);
tmp_tvb = tvb_new_subset_length(tvb, val_start + val_len_len, val_len);
call_dissector(wbxml_uaprof_handle, tmp_tvb, pinfo, subtree);
ok = TRUE;
wkh_4_End();
}
static guint32
wkh_allow(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo)
{
wkh_0a_Declarations;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_allow, "Allow");
val_id &= 0x7F;
if (val_id >= 0x40) {
proto_tree_add_string(tree, hf_hdr_allow,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val_id & 0x7F, &wsp_vals_pdu_type_ext,
"<Unknown WSP method 0x%02X>"));
ok = TRUE;
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32
wkh_public(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo)
{
wkh_0_Declarations;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_public, "Public");
val_id &= 0x7F;
if (val_id >= 0x40) {
proto_tree_add_string(tree, hf_hdr_public,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val_id & 0x7F, &wsp_vals_pdu_type_ext,
"<Unknown WSP method 0x%02X>"));
ok = TRUE;
}
wkh_2_TextualValue;
proto_tree_add_string(tree, hf_hdr_public,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32
wkh_vary(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_vary, "Vary");
proto_tree_add_string(tree, hf_hdr_vary,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val_id & 0x7F, &vals_field_names_ext,
"<Unknown WSP header field 0x%02X>"));
ok = TRUE;
wkh_2_TextualValue;
proto_tree_add_string(tree, hf_hdr_vary,
tvb, hdr_start, offset - hdr_start,
val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32
wkh_x_wap_security(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0a_Declarations;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_x_wap_security, "X-wap-security-value");
if (val_id == 0x80) {
proto_tree_add_string(tree, hf_hdr_x_wap_security,
tvb, hdr_start, offset - hdr_start, "close-subordinate");
ok = TRUE;
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32
wkh_connection(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo)
{
wkh_0_Declarations;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_connection, "Connection");
if (val_id == 0x80) {
proto_tree_add_string(tree, hf_hdr_connection,
tvb, hdr_start, offset - hdr_start, "close");
ok = TRUE;
}
wkh_2_TextualValue;
proto_tree_add_string(tree, hf_hdr_connection,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32
wkh_transfer_encoding(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_transfer_encoding, "Transfer encoding");
if (val_id == 0x80) {
proto_tree_add_string(tree, hf_hdr_transfer_encoding,
tvb, hdr_start, offset - hdr_start, "chunked");
ok = TRUE;
}
wkh_2_TextualValue;
proto_tree_add_string(tree, hf_hdr_transfer_encoding,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32
wkh_accept_ranges(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_accept_ranges, "Accept Ranges");
switch (val_id) {
case 0x80:
proto_tree_add_string(tree, hf_hdr_accept_ranges,
tvb, hdr_start, offset - hdr_start, "none");
ok = TRUE;
break;
case 0x81:
proto_tree_add_string(tree, hf_hdr_accept_ranges,
tvb, hdr_start, offset - hdr_start, "bytes");
ok = TRUE;
break;
}
wkh_2_TextualValue;
proto_tree_add_string(tree, hf_hdr_accept_ranges,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32
wkh_content_encoding(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_content_encoding, "Content Encoding");
switch (val_id) {
case 0x80:
proto_tree_add_string(tree, hf_hdr_content_encoding,
tvb, hdr_start, offset - hdr_start, "gzip");
ok = TRUE;
break;
case 0x81:
proto_tree_add_string(tree, hf_hdr_content_encoding,
tvb, hdr_start, offset - hdr_start, "compress");
ok = TRUE;
break;
case 0x82:
proto_tree_add_string(tree, hf_hdr_content_encoding,
tvb, hdr_start, offset - hdr_start, "deflate");
ok = TRUE;
break;
}
wkh_2_TextualValue;
proto_tree_add_string(tree, hf_hdr_content_encoding,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32
wkh_accept_encoding(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo)
{
wkh_0_Declarations;
guint32 len, off;
guint8 peek;
gchar *str;
proto_item *ti = NULL;
proto_tree *parameter_tree = NULL;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_accept_encoding, "Accept Encoding");
switch (val_id) {
case 0x80:
proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "gzip");
ok = TRUE;
break;
case 0x81:
proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "compress");
ok = TRUE;
break;
case 0x82:
proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "deflate");
ok = TRUE;
break;
case 0x83:
proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "*");
ok = TRUE;
break;
}
wkh_2_TextualValue;
proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
peek = tvb_get_guint8(tvb, off);
if (is_short_integer(peek)) {
switch (peek) {
case 0x80:
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "gzip");
ok = TRUE;
break;
case 0x81:
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "compress");
ok = TRUE;
break;
case 0x82:
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "deflate");
ok = TRUE;
break;
case 0x83:
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, "*");
ok = TRUE;
break;
}
off++;
} else {
get_token_text(str, tvb, off, len, ok);
if (ok) {
ti = proto_tree_add_string(tree, hf_hdr_accept_encoding,
tvb, hdr_start, offset - hdr_start, str);
}
off += len;
}
if (ok) {
if (off < offset) {
parameter_tree = proto_item_add_subtree(ti, ett_header);
parameter_value_q(parameter_tree, pinfo, ti, tvb, off);
}
}
wkh_4_End();
}
static guint32
wkh_content_disposition(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo)
{
wkh_0a_Declarations;
guint32 len, off;
guint8 peek;
gchar *str;
proto_item *ti = NULL;
proto_tree *parameter_tree = NULL;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_content_disposition, "Content Disposition");
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
peek = tvb_get_guint8(tvb, off);
if (is_short_integer(peek)) {
switch (peek) {
case 0x80:
ti = proto_tree_add_string(tree, hf_hdr_content_disposition,
tvb, hdr_start, offset - hdr_start, "form-data");
ok = TRUE;
break;
case 0x81:
ti = proto_tree_add_string(tree, hf_hdr_content_disposition,
tvb, hdr_start, offset - hdr_start, "attachment");
ok = TRUE;
break;
case 0x82:
ti = proto_tree_add_string(tree, hf_hdr_content_disposition,
tvb, hdr_start, offset - hdr_start, "inline");
ok = TRUE;
break;
}
off++;
} else {
get_token_text(str, tvb, off, len, ok);
if (ok) {
ti = proto_tree_add_string(tree, hf_hdr_content_disposition,
tvb, hdr_start, offset - hdr_start, str);
}
off += len;
}
if ((ok) && (off < offset)) {
parameter_tree = proto_item_add_subtree(ti, ett_header);
while (off < offset) {
off = parameter(parameter_tree, pinfo, ti, tvb, off, offset - off);
}
}
wkh_4_End();
}
static guint32
wkh_text_header_func(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo, int hf, const char* name)
{
wkh_0_Declarations;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Header: %s", name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_text_header, header_name);
wkh_2_TextualValue;
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32
wkh_content_id(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo)
{
wkh_0_Declarations;
gchar *str;
proto_item *ti = NULL;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_content_id, "Content ID");
wkh_2_TextualValue;
if (is_quoted_string(val_str[0])) {
if (is_quoted_string(val_str[val_len-2])) {
ti = proto_tree_add_string(tree, hf_hdr_content_id,
tvb, hdr_start, offset - hdr_start, val_str);
expert_add_info(pinfo, ti, &ei_wsp_trailing_quote);
} else {
str = wmem_strdup_printf(wmem_packet_scope(), "%s\"", val_str);
proto_tree_add_string(tree, hf_hdr_content_id,
tvb, hdr_start, offset - hdr_start, str);
}
} else {
ti = proto_tree_add_string(tree, hf_hdr_content_id,
tvb, hdr_start, offset - hdr_start, val_str);
expert_add_info(pinfo, ti, &ei_wsp_trailing_quote);
}
ok = TRUE;
wkh_3_ValueWithLength;
wkh_4_End();
}
static guint32
wkh_text_or_date_value_header_func(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo, int hf, const char* name)
{
wkh_0_Declarations;
guint32 val = 0, off = val_start, len;
gchar *str;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Text or Date: %s", name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_text_or_date_value, header_name);
wkh_2_TextualValue;
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
if (val_id <= 4) {
get_date_value(val, tvb, off, len, ok);
if (ok) {
str = abs_time_secs_to_str(wmem_packet_scope(), val, ABSOLUTE_TIME_LOCAL, TRUE);
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, str);
}
}
wkh_4_End();
}
static guint32
wkh_date_value_header_func(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo, int hf, const char* name)
{
wkh_0a_Declarations;
guint32 val = 0, off = val_start, len;
gchar *str;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Date: %s", name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_date_value, header_name);
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
if (val_id <= 4) {
get_date_value(val, tvb, off, len, ok);
if (ok) {
str = abs_time_secs_to_str(wmem_packet_scope(), val, ABSOLUTE_TIME_LOCAL, TRUE);
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, str);
}
}
wkh_4_End();
}
static guint32
wkh_tod_value_header_func(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo, int hf, const char* name)
{
wkh_0a_Declarations;
guint32 val = 0, off = val_start, len;
gchar *str;
proto_item *ti = NULL;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Time of Day: %s", name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_tod_value, header_name);
if (val_id == 0x80) {
ti = proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start,
"Requesting Time Of Day");
proto_item_append_text(ti,
" <Warning: should be encoded as long-integer>");
ok = TRUE;
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
if (val_id <= 4) {
get_date_value(val, tvb, off, len, ok);
if (ok) {
if (val == 0) {
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start,
"Requesting Time Of Day");
} else {
str = abs_time_secs_to_str(wmem_packet_scope(), val, ABSOLUTE_TIME_LOCAL, TRUE);
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, str);
}
}
}
wkh_4_End();
}
static guint32
wkh_age(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 val = 0, off = val_start, len;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_age, "Age");
val = val_id & 0x7F;
val_str = wmem_strdup_printf(wmem_packet_scope(), "%u second%s", val, plurality(val, "", "s"));
proto_tree_add_string(tree, hf_hdr_age,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
if (val_id <= 4) {
get_long_integer(val, tvb, off, len, ok);
if (ok) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "%u second%s", val, plurality(val, "", "s"));
proto_tree_add_string(tree, hf_hdr_age,
tvb, hdr_start, offset - hdr_start, val_str);
}
}
wkh_4_End();
}
static guint32
wkh_integer_lookup_or_text_value_func(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo,
int hf, const char* name, value_string_ext *valueStringExtAddr, const char* value_format)
{
wkh_0_Declarations;
guint32 off = val_start, len;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Integer lookup: %s", name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_integer_lookup, header_name);
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val_id & 0x7F, valueStringExtAddr, value_format));
ok = TRUE;
wkh_2_TextualValue;
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
if (val_id <= 4) {
len = tvb_get_guint8(tvb,off);
ok = (len >= 1 && len <= 4);
if (ok) {
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext(val_id & 0x7F, valueStringExtAddr, value_format));
}
}
wkh_4_End();
}
static guint32
wkh_challenge_value_header_func(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo,
int hf, int hf_scheme, int hf_realm, const char* name)
{
wkh_0a_Declarations;
guint8 peek;
guint32 off, len;
proto_tree *subtree;
gchar *str;
proto_item *ti = NULL;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Challenge: %s", name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_challenge, header_name);
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
peek = tvb_get_guint8(tvb, off);
if (peek == 0x80) {
ti = proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, "basic");
subtree = proto_item_add_subtree(ti, ett_header);
proto_tree_add_string(subtree, hf_scheme,
tvb, off, 1, "basic");
off++;
get_text_string(str,tvb,off,len,ok);
if (ok) {
proto_tree_add_string(subtree,
hf_realm,
tvb, off, len, str);
proto_item_append_text(ti, "; realm=%s", str);
}
} else {
get_token_text(str, tvb, off, len, ok);
if (ok) {
ti = proto_tree_add_string(tree, hf,
tvb, hdr_start, off - hdr_start, str);
subtree = proto_item_add_subtree(ti, ett_header);
proto_tree_add_string(subtree,
hf_scheme,
tvb, hdr_start, off - hdr_start, str);
off += len;
get_text_string(str,tvb,off,len,ok);
if (ok) {
proto_tree_add_string(subtree,
hf_realm,
tvb, off, len, str);
proto_item_append_text(ti, "; realm=%s", str);
off += len;
while (off < offset)
off = parameter(subtree, pinfo, ti, tvb, off, offset - off);
}
}
}
wkh_4_End();
}
static guint32
wkh_credentials_value_header_func(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo,
int hf, int hf_scheme, int hf_userid, int hf_password, const char* name)
{
wkh_0a_Declarations;
guint8 peek;
guint32 off, len;
proto_tree *subtree;
gchar *str;
proto_item *ti = NULL;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Credentials: %s", name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_credentials_value, header_name);
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
peek = tvb_get_guint8(tvb, off);
if (peek == 0x80) {
ti = proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, "basic");
subtree = proto_item_add_subtree(ti, ett_header);
proto_tree_add_string(subtree, hf_scheme,
tvb, off, 1, "basic");
off++;
get_text_string(str,tvb,off,len,ok);
if (ok) {
proto_tree_add_string(subtree,
hf_userid,
tvb, off, len, str);
proto_item_append_text(ti, "; user-id=%s", str);
off += len;
get_text_string(str,tvb,off,len,ok);
if (ok) {
proto_tree_add_string(subtree,
hf_password,
tvb, off, len, str);
proto_item_append_text(ti, "; password=%s", str);
}
}
} else {
get_token_text(str, tvb, off, len, ok);
if (ok) {
ti = proto_tree_add_string(tree, hf,
tvb, hdr_start, off - hdr_start, str);
subtree = proto_item_add_subtree(ti, ett_header);
proto_tree_add_string(subtree,
hf_scheme,
tvb, hdr_start, off - hdr_start, str);
off += len;
while (off < offset)
off = parameter(subtree, pinfo, ti, tvb, off, offset - off);
}
}
wkh_4_End();
}
static guint32
wkh_content_md5 (proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0a_Declarations;
guint32 off;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_content_md5, "Content-md5");
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
if (val_len == 16) {
proto_tree_add_item(tree, hf_hdr_content_md5,
tvb, off, val_len, ENC_NA);
ok = TRUE;
}
wkh_4_End();
}
static guint32
wkh_pragma(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo)
{
wkh_0a_Declarations;
guint32 off;
proto_item *ti = NULL;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_pragma, "Pragma");
if (val_id == 0x80) {
proto_tree_add_string(tree, hf_hdr_pragma,
tvb, hdr_start, offset - hdr_start, "no-cache");
ok = TRUE;
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
ti = proto_tree_add_string(tree, hf_hdr_pragma,
tvb, hdr_start, off - hdr_start, "");
parameter(NULL, pinfo, ti, tvb, off, offset - off);
ok = TRUE;
wkh_4_End();
}
static guint32
wkh_integer_value_header_func(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo, int hf, const char* name)
{
wkh_0a_Declarations;
guint32 val = 0, off = val_start, len;
gchar *str;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Integer-value: %s", name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_integer_value, header_name);
str = wmem_strdup_printf(wmem_packet_scope(), "%u", val_id & 0x7F);
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, str);
ok = TRUE;
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
if (val_id <= 4) {
get_long_integer(val, tvb, off, len, ok);
if (ok) {
str = wmem_strdup_printf(wmem_packet_scope(), "%u", val);
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, str);
}
}
wkh_4_End();
}
static guint32
wkh_integer_lookup_value_header_func(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo,
int hf, const char* name, value_string_ext *valueStringExtAddr, const char* value_name)
{
wkh_0_Declarations;
guint32 off = val_start, len;
gchar* header_name = wmem_strdup_printf(wmem_packet_scope(), "Integer lookup: %s", name);
gchar* value_name_str = wmem_strdup_printf(wmem_packet_scope(), "<Unknown %s>", value_name);
wkh_1_WellKnownValue(hf_hdr_name_value, ett_integer_lookup_value, header_name);
val_str = try_val_to_str_ext(val_id & 0x7F, valueStringExtAddr);
if (val_str) {
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
} else {
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start,
value_name_str);
}
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
if (val_id <= 4) {
len = tvb_get_guint8(tvb,off);
ok = (len >= 1 && len <= 4);
if (ok) {
val_str = try_val_to_str_ext(val_id & 0x7F, valueStringExtAddr);
if (val_str) {
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
} else {
proto_tree_add_string(tree, hf,
tvb, hdr_start, offset - hdr_start,
value_name_str);
}
}
}
wkh_4_End();
}
static guint32
wkh_cache_control(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, len, val = 0;
guint8 peek, cache_control_directive;
proto_item *ti = NULL;
wmem_strbuf_t *cache_str;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_cache_control, "Cache-control");
val = val_id & 0x7F;
val_str = try_val_to_str_ext(val, &vals_cache_control_ext);
if (val_str) {
proto_tree_add_string(tree, hf_hdr_cache_control,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
}
wkh_2_TextualValue;
proto_tree_add_string(tree, hf_hdr_cache_control,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
cache_control_directive = tvb_get_guint8(tvb, off++);
if (cache_control_directive & 0x80) {
switch (cache_control_directive & 0x7F) {
case CACHE_CONTROL_NO_CACHE:
case CACHE_CONTROL_PRIVATE:
cache_str = wmem_strbuf_new(wmem_packet_scope(), val_to_str_ext (cache_control_directive & 0x7F, &vals_cache_control_ext,
"<Unknown cache control directive 0x%02X>"));
ok = TRUE;
while (ok && (off < offset)) {
peek = tvb_get_guint8(tvb, off);
if (peek & 0x80) {
wmem_strbuf_append(cache_str,
val_to_str (peek, vals_field_names,
"<Unknown WSP header field 0x%02X>"));
off++;
} else {
get_token_text(val_str, tvb, off, len, ok);
if (ok) {
wmem_strbuf_append(cache_str, val_str);
off += len;
}
}
}
proto_tree_add_string(tree, hf_hdr_cache_control,
tvb, hdr_start, offset - hdr_start,
wmem_strbuf_get_str(cache_str));
break;
case CACHE_CONTROL_MAX_AGE:
case CACHE_CONTROL_MAX_STALE:
case CACHE_CONTROL_MIN_FRESH:
case CACHE_CONTROL_S_MAXAGE:
ti = proto_tree_add_string(tree, hf_hdr_cache_control,
tvb, hdr_start, offset - hdr_start,
val_to_str_ext (cache_control_directive & 0x7F, &vals_cache_control_ext,
"<Unknown cache control directive 0x%02X>"));
get_delta_seconds_value(val, tvb, off, len, ok);
if (ok) {
proto_item_append_text(ti, "=%u second%s", val, plurality(val, "", "s"));
}
break;
default:
break;
}
} else if (is_token_text(cache_control_directive)) {
get_token_text(val_str, tvb, off, len, ok);
if (ok) {
ti = proto_tree_add_string(tree, hf_hdr_cache_control,
tvb, hdr_start, offset - hdr_start, val_str);
get_integer_value(val, tvb, off, len, ok);
if (ok) {
proto_item_append_text(ti, "=%u", val);
} else {
get_text_string(val_str, tvb, off, len, ok);
if (ok) {
if (is_quoted_string(val_str[0])) {
if (is_quoted_string(val_str[len-2])) {
expert_add_info(pinfo, ti, &ei_wsp_trailing_quote);
} else {
proto_item_append_text(ti, "%s\"", val_str);
}
} else {
proto_item_append_text(ti, "%s", val_str);
}
}
}
}
}
wkh_4_End();
}
static guint32
wkh_warning(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, len, val;
guint8 warn_code;
gchar *str;
proto_item *ti = NULL;
proto_tree *subtree;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_warning, "Warning");
val = val_id & 0x7F;
val_str = try_val_to_str_ext(val, &vals_wsp_warning_code_ext);
if (val_str) {
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
proto_item_append_text(ti, "; agent=%s", str);
off += len;
get_text_string(str, tvb, off, len, ok);
if (ok) {
proto_tree_add_string(subtree,
hf_hdr_warning_text,
tvb, off, len, str);
proto_item_append_text(ti, "; text=%s", str);
}
}
}
}
wkh_4_End();
}
static guint32
wkh_profile_warning(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, len, val = 0;
guint8 warn_code;
proto_item *ti = NULL;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_profile_warning, "Profile-warning");
val = val_id & 0x7F;
val_str = try_val_to_str_ext(val, &vals_wsp_profile_warning_code_ext);
if (val_str) {
proto_tree_add_string(tree, hf_hdr_profile_warning,
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
ti = proto_tree_add_string(tree, hf_hdr_profile_warning,
tvb, hdr_start, offset - hdr_start, val_str);
get_uri_value(val_str, tvb, off, len, ok);
if (ok) {
off += len;
proto_item_append_text(ti, "; target=%s", val_str);
while (ok && (off < offset)) {
get_date_value(val, tvb, off, len, ok);
if (ok) {
off += len;
proto_item_append_text(ti, "; date=%s", abs_time_secs_to_str(wmem_packet_scope(), val, ABSOLUTE_TIME_LOCAL, TRUE));
}
}
}
}
}
wkh_4_End();
}
static guint32 wkh_encoding_version (proto_tree *tree, tvbuff_t *tvb,
guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
proto_item *ti = NULL;
guint32 off, val, len;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_encoding_version, "Encoding-version");
val = val_id & 0x7F;
val_str = wmem_strdup_printf(wmem_packet_scope(), "%u.%u", val >> 4, val & 0x0F);
proto_tree_add_string(tree, hf_hdr_encoding_version,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_2_TextualValue;
proto_tree_add_string(tree, hf_hdr_encoding_version,
tvb, hdr_start, offset - hdr_start, val_str);
ok = TRUE;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
val = tvb_get_guint8(tvb, off);
if (val & 0x80) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "code-page=%u", val & 0x7F);
ti = proto_tree_add_string(tree, hf_hdr_encoding_version,
tvb, hdr_start, offset - hdr_start, val_str);
off++;
ok = TRUE;
if (off < offset) {
get_version_value(val,val_str,tvb,off,len,ok);
if (ok) {
proto_item_append_text(ti, ": %s", val_str);
}
}
}
wkh_4_End();
}
static guint32
wkh_content_range(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, val, len;
proto_item *ti = NULL;
proto_tree *subtree = NULL;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_content_range, "Content range");
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
get_uintvar_integer (val, tvb, off, len, ok);
if (ok) {
val_str = wmem_strdup_printf(wmem_packet_scope(), "first-byte-pos=%u", val);
ti = proto_tree_add_string(tree, hf_hdr_content_range,
tvb, hdr_start, offset - hdr_start, val_str);
subtree = proto_item_add_subtree(ti, ett_header);
proto_tree_add_uint(subtree, hf_hdr_content_range_first_byte_pos,
tvb, off, len, val);
off += len;
val = tvb_get_guint8(tvb, off);
if (val == 0x80) {
proto_item_append_text(ti, "%s", "; entity-length=unknown");
} else {
get_uintvar_integer (val, tvb, off, len, ok);
if (ok) {
proto_item_append_text(ti, "; entity-length=%u", val);
proto_tree_add_uint(subtree,
hf_hdr_content_range_entity_length,
tvb, off, len, val);
}
}
}
wkh_4_End();
}
static guint32
wkh_range(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0a_Declarations;
guint32 off, val, len;
proto_item *ti = NULL;
proto_tree *subtree = NULL;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_range, "Range");
wkh_2_TextualValueInv;
wkh_3_ValueWithLength;
off = val_start + val_len_len;
val = tvb_get_guint8(tvb, off);
if (val == 0x80) {
ti = proto_tree_add_string(tree, hf_hdr_range,
tvb, hdr_start, offset - hdr_start, "byte-range");
subtree = proto_item_add_subtree(ti, ett_header);
get_uintvar_integer (val, tvb, off, len, ok);
if (ok) {
proto_item_append_text(ti, "; first-byte-pos=%u", val);
proto_tree_add_uint(subtree, hf_hdr_range_first_byte_pos,
tvb, off, len, val);
off += len;
if (off < offset) {
get_uintvar_integer (val, tvb, off, len, ok);
if (ok) {
proto_item_append_text(ti, "; last-byte-pos=%u", val);
proto_tree_add_uint(subtree,
hf_hdr_range_last_byte_pos,
tvb, off, len, val);
}
}
}
} else if (val == 0x81) {
ti = proto_tree_add_string(tree, hf_hdr_range,
tvb, hdr_start, offset - hdr_start, "suffix-byte-range");
subtree = proto_item_add_subtree(ti, ett_header);
get_uintvar_integer (val, tvb, off, len, ok);
if (ok) {
proto_item_append_text(ti, "; suffix-length=%u", val);
proto_tree_add_uint(subtree, hf_hdr_range_suffix_length,
tvb, off, len, val);
}
}
wkh_4_End();
}
static guint32 wkh_te (proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint32 off, val, len;
wkh_1_WellKnownValue(hf_hdr_name_value, ett_te_value, "TE-value");
if (val_id == 0x81) {
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
proto_tree_add_string(tree, hf_hdr_te,
tvb, hdr_start, off - hdr_start, val_str);
off++;
ok = TRUE;
}
} else {
get_token_text(val_str, tvb, off, len, ok);
if (ok) {
proto_tree_add_string(tree, hf_hdr_te,
tvb, hdr_start, off - hdr_start, val_str);
off += len;
}
}
if ((ok) && (off < offset)) {
}
wkh_4_End();
}
static guint32
wkh_openwave_default(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo _U_)
{
wkh_0_Declarations;
guint8 hdr_id = tvb_get_guint8 (tvb, hdr_start) & 0x7F;
ok = TRUE;
wkh_1_WellKnownValue(hf_hdr_openwave_name_value, ett_openwave_default, "Default");
proto_tree_add_uint_format(tree, hf_hdr_openwave_default_int, tvb, hdr_start, offset - hdr_start,
val_id & 0x7F, "%s: (Undecoded well-known value 0x%02x)",
val_to_str_ext (hdr_id, &vals_openwave_field_names_ext,
"<Unknown WSP header field 0x%02X>"), val_id & 0x7F);
wkh_2_TextualValue;
proto_tree_add_string_format(tree, hf_hdr_openwave_default_string, tvb, hdr_start, offset - hdr_start,
"%s: %s",
val_to_str_ext (hdr_id, &vals_openwave_field_names_ext,
"<Unknown WSP header field 0x%02X>"), val_str);
wkh_3_ValueWithLength;
proto_tree_add_uint_format(tree, hf_hdr_openwave_default_val_len, tvb, hdr_start, offset - hdr_start,
val_len, "%s: (Undecoded value in general form with length indicator)",
val_to_str_ext (hdr_id, &vals_openwave_field_names_ext,
"<Unknown WSP header field 0x%02X>"));
wkh_4_End();
}
static guint32
wkh_openwave_x_up_proxy_push_accept(proto_tree *tree, tvbuff_t *tvb, guint32 hdr_start, packet_info *pinfo)
{
return wkh_content_type_header(tree, tvb, hdr_start, pinfo, hf_hdr_openwave_x_up_proxy_push_accept, "x-up-proxy-push-accept");
}
static gboolean parameter_text(proto_tree *tree, tvbuff_t *tvb, int *offset, proto_item *ti, int hf)
{
gchar *val_str;
gboolean ok;
guint32 val_len;
get_text_string(val_str, tvb, (*offset), val_len, ok);
if (ok) {
proto_tree_add_string(tree, hf, tvb, *offset, val_len, val_str);
proto_item_append_text(ti, "; %s=%s", proto_registrar_get_name(hf), val_str);
(*offset) += val_len;
}
return ok;
}
static gboolean parameter_text_value(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int *offset, proto_item *ti, int hf)
{
gchar *val_str, *str;
gboolean ok;
guint32 val_len;
proto_item* ti2;
get_text_string(val_str, tvb, (*offset), val_len, ok);
if (ok) {
if (is_quoted_string(val_str[0])) {
if (is_quoted_string(val_str[val_len-2])) {
ti2 = proto_tree_add_string(tree, hf,
tvb, *offset, val_len, val_str);
expert_add_info(pinfo, ti2, &ei_wsp_trailing_quote);
} else {
str = wmem_strdup_printf(wmem_packet_scope(), "%s\"", val_str);
proto_tree_add_string(tree, hf,
tvb, *offset, val_len, str);
}
} else {
proto_tree_add_string(tree, hf,
tvb, *offset, val_len, val_str);
}
proto_item_append_text(ti, "; %s=%s", proto_registrar_get_name(hf), val_str);
(*offset) += val_len;
}
return ok;
}
static int
parameter (proto_tree *tree, packet_info *pinfo, proto_item *ti, tvbuff_t *tvb, int start, int len)
{
int offset = start;
guint8 peek = tvb_get_guint8 (tvb,start);
guint32 val = 0, type = 0, type_len, val_len;
const gchar *str = NULL;
const gchar *val_str = NULL;
gboolean ok;
proto_item* ti2;
if (is_token_text (peek)) {
get_token_text (str,tvb,start,val_len,ok);
if (ok) {
offset += val_len;
get_text_value(val_str, tvb, offset, val_len, ok);
if (ok) {
offset += val_len;
if (is_quoted_string(val_str[0])) {
if (is_quoted_string(val_str[val_len-2])) {
ti2 = proto_tree_add_string_format(tree, hf_wsp_parameter_untype_quote_text,
tvb, start, offset - start, val_str,
"%s: %s", str, val_str);
expert_add_info(pinfo, ti2, &ei_wsp_trailing_quote);
proto_item_append_text(ti, "; %s=%s", str, val_str);
} else {
proto_tree_add_string_format(tree, hf_wsp_parameter_untype_quote_text,
tvb, start, offset - start, val_str,
"%s: %s\"", str, val_str);
proto_item_append_text(ti, "; %s=%s\"", str, val_str);
}
} else {
proto_tree_add_string_format(tree, hf_wsp_parameter_untype_text,
tvb, start, offset - start, val_str,
"%s: %s", str, val_str);
proto_item_append_text(ti, "; %s=%s", str, val_str);
}
} else {
get_integer_value (val,tvb,offset,val_len,ok);
if (ok) {
offset += val_len;
proto_tree_add_uint_format(tree, hf_wsp_parameter_untype_int, tvb, start, offset - start,
val, "%s: %u", str, val);
proto_item_append_text(ti, "; %s=%u", str, val);
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, offset - start,
"Invalid untyped parameter definition");
offset = start + len;
}
}
}
return offset;
}
get_integer_value (type,tvb,start,type_len,ok);
if (!ok) {
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, offset - start,
"Invalid typed parameter definition");
return (start + len);
}
offset += type_len;
proto_tree_add_uint(tree, hf_wsp_parameter_type, tvb, start, type_len, type);
switch (type) {
case 0x01:
get_integer_value(val, tvb, offset, val_len, ok);
if (ok) {
val_str = val_to_str_ext(val, &mibenum_vals_character_sets_ext,
"<Unknown character set Identifier %u>");
proto_tree_add_string(tree, hf_parameter_charset,
tvb, offset, val_len, val_str);
proto_item_append_text(ti, "; charset=%s", val_str);
offset += val_len;
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Charset parameter value: invalid Integer-value");
offset = start + len;
}
break;
case 0x03:
get_integer_value (val,tvb,offset,val_len,ok);
if (ok) {
proto_tree_add_uint (tree, hf_wsp_parameter_int_type,
tvb, offset, val_len, val);
proto_item_append_text(ti, "; Type=%u", val);
offset += val_len;
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Type parameter value: invalid Integer-value");
offset = start + len;
}
break;
case 0x05:
if (!parameter_text(tree, tvb, &offset, ti, hf_wsp_parameter_name))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Name (WSP 1.1 encoding) parameter value: invalid Text-string");
offset = start + len;
}
break;
case 0x17:
if (!parameter_text_value(tree, pinfo, tvb, &offset, ti, hf_wsp_parameter_name))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Name (WSP 1.4 encoding) parameter value: invalid Text-value");
offset = start + len;
}
break;
case 0x06:
if (!parameter_text(tree, tvb, &offset, ti, hf_wsp_parameter_filename))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Filename (WSP 1.1 encoding) parameter value: invalid Text-string");
offset = start + len;
}
break;
case 0x18:
if (!parameter_text_value(tree, pinfo, tvb, &offset, ti, hf_wsp_parameter_filename))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Filename (WSP 1.4 encoding) parameter value: invalid Text-value");
offset = start + len;
}
break;
case 0x09:
get_extension_media(val_str,tvb,offset,val_len,ok);
if (ok) {
proto_tree_add_string (tree, hf_wsp_parameter_upart_type,
tvb, offset, val_len, val_str);
proto_item_append_text(ti, "; type=%s", val_str);
offset += val_len;
} else {
get_short_integer(val,tvb,offset,val_len,ok);
if (ok) {
proto_tree_add_string (tree, hf_wsp_parameter_upart_type,
tvb, offset, val_len, val_to_str_ext(val, &vals_content_types_ext,
"(Unknown content type identifier 0x%X)"));
offset += val_len;
}
}
if (!ok) {
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Type parameter value: invalid Constrained-encoding");
offset = start + len;
}
break;
case 0x0A:
if (!parameter_text(tree, tvb, &offset, ti, hf_wsp_parameter_start))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Start (WSP 1.2 encoding) parameter value: invalid Text-string");
offset = start + len;
}
break;
case 0x19:
if (!parameter_text_value(tree, pinfo, tvb, &offset, ti, hf_wsp_parameter_start))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Start (with multipart/related) parameter value: invalid Text-value");
offset = start + len;
}
break;
case 0x0B:
if (!parameter_text(tree, tvb, &offset, ti, hf_wsp_parameter_start_info))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Start-info (WSP 1.2 encoding) parameter value: invalid Text-string");
offset = start + len;
}
break;
case 0x1A:
if (!parameter_text_value(tree, pinfo, tvb, &offset, ti, hf_wsp_parameter_start_info))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Start-info (WSP 1.4 encoding) parameter value: invalid Text-value");
offset = start + len;
}
break;
case 0x0C:
if (!parameter_text(tree, tvb, &offset, ti, hf_wsp_parameter_comment))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Comment (WSP 1.3 encoding) parameter value: invalid Text-string");
offset = start + len;
}
break;
case 0x1B:
if (!parameter_text_value(tree, pinfo, tvb, &offset, ti, hf_wsp_parameter_comment))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Comment (WSP 1.4 encoding) parameter value: invalid Text-value");
offset = start + len;
}
break;
case 0x0D:
if (!parameter_text(tree, tvb, &offset, ti, hf_wsp_parameter_domain))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Domain (WSP 1.3 encoding) parameter value: invalid Text-string");
offset = start + len;
}
break;
case 0x1C:
if (!parameter_text_value(tree, pinfo, tvb, &offset, ti, hf_wsp_parameter_domain))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Domain (WSP 1.4 encoding) parameter value: invalid Text-value");
offset = start + len;
}
break;
case 0x0F:
if (!parameter_text(tree, tvb, &offset, ti, hf_wsp_parameter_path))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Path (WSP 1.3 encoding) parameter value: invalid Text-string");
offset = start + len;
}
break;
case 0x1D:
if (!parameter_text_value(tree, pinfo, tvb, &offset, ti, hf_wsp_parameter_path))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Path (WSP 1.4 encoding) parameter value: invalid Text-value");
offset = start + len;
}
break;
case 0x11:
peek = tvb_get_guint8 (tvb, start+1);
if (peek & 0x80) {
peek &= 0x7F;
proto_tree_add_uint (tree, hf_wsp_parameter_sec,
tvb, offset, 1, peek);
proto_item_append_text(ti, "; SEC=%s", val_to_str_ext_const(peek, &vals_wsp_parameter_sec_ext, "Undefined"));
offset++;
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid SEC parameter value: invalid Short-integer-value");
offset = start + len;
}
break;
case 0x12:
if (!parameter_text_value(tree, pinfo, tvb, &offset, ti, hf_wsp_parameter_mac))
{
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid MAC (WSP 1.4 encoding) parameter value: invalid Text-value");
offset = start + len;
}
break;
case 0x02:
get_version_value(val,str,tvb,offset,val_len,ok);
if (ok) {
proto_tree_add_string (tree, hf_wsp_parameter_level,
tvb, offset, val_len, str);
proto_item_append_text(ti, "; level=%s", str);
offset += val_len;
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Level parameter value: invalid Version-value");
offset = start + len;
}
break;
case 0x00:
offset = parameter_value_q(tree, pinfo, ti, tvb, offset);
break;
case 0x16:
get_integer_value (val,tvb,offset,val_len,ok);
if (ok) {
proto_tree_add_uint (tree, hf_wsp_parameter_size,
tvb, offset, val_len, val);
proto_item_append_text(ti, "; Size=%u", val);
offset += val_len;
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, len,
"Invalid Size parameter value: invalid Integer-value");
offset = start + len;
}
break;
case 0x07:
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_undecoded_parameter, tvb, start, offset - start,
"Undecoded parameter Differences");
offset = start + len;
break;
case 0x08:
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_undecoded_parameter, tvb, start, offset - start,
"Undecoded parameter Padding");
offset = start + len;
break;
case 0x0E:
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_undecoded_parameter, tvb, start, offset - start,
"Undecoded parameter Max-Age");
offset = start + len;
break;
case 0x10:
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_undecoded_parameter, tvb, start, offset - start,
"Undecoded parameter Secure");
offset = start + len;
break;
case 0x13:
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_undecoded_parameter, tvb, start, offset - start,
"Undecoded parameter Creation-Date");
offset = start + len;
break;
case 0x14:
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_undecoded_parameter, tvb, start, offset - start,
"Undecoded parameter Modification-Date");
offset = start + len;
break;
case 0x15:
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_undecoded_parameter, tvb, start, offset - start,
"Undecoded parameter Read-Date");
offset = start + len;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_undecoded_parameter, tvb, start, offset - start,
"Undecoded parameter type 0x%02x", type);
offset = start + len;
break;
}
return offset;
}
static int
parameter_value_q (proto_tree *tree, packet_info *pinfo, proto_item *ti, tvbuff_t *tvb, int start)
{
int offset = start;
guint32 val = 0, val_len;
gchar *str = NULL;
guint8 ok;
get_uintvar_integer (val, tvb, offset, val_len, ok);
if (ok && (val < 1100)) {
if (val <= 100) {
str = wmem_strdup_printf(wmem_packet_scope(), "0.%02u", val - 1);
} else {
str = wmem_strdup_printf(wmem_packet_scope(), "0.%03u", val - 100);
}
proto_item_append_text(ti, "; q=%s", str);
proto_tree_add_string (tree, hf_parameter_q,
tvb, start, val_len, str);
offset += val_len;
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_wsp_invalid_parameter_value, tvb, start, offset,
"Invalid Q parameter value: invalid Q-value");
offset += val_len;
}
return offset;
}
static void
dissect_redirect(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dissector_handle_t dissector_handle)
{
proto_item *ti;
proto_tree *addresses_tree = NULL;
proto_tree *addr_tree = NULL;
guint8 bearer_type;
guint8 address_flags_len;
int address_len;
guint16 port_num;
guint32 address_ipv4;
struct e_in6_addr address_ipv6;
address redir_address;
conversation_t *conv;
guint32 idx = 0;
guint32 address_record_len;
static const int * flags[] = {
&hf_wsp_redirect_permanent,
&hf_wsp_redirect_reuse_security_session,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_wsp_redirect_flags, ett_redirect_flags, flags, ENC_NA);
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
ti = proto_tree_add_uint(addresses_tree, hf_address_entry,
tvb, offset, 1 + address_record_len, idx);
addr_tree = proto_item_add_subtree(ti, ett_address);
proto_tree_add_bitmask(addr_tree, tvb, offset, hf_address_flags_length, ett_address_flags, address_length_flags, ENC_NA);
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
port_num = tvb_get_ntohs (tvb, offset);
proto_tree_add_uint (addr_tree, hf_address_port_num,
tvb, offset, 2, port_num);
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
conv = find_conversation(pinfo->num, &redir_address, &pinfo->dst,
PT_UDP, port_num, 0, NO_PORT_B);
if (conv == NULL) {
conv = conversation_new(pinfo->num, &redir_address,
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
tvb, offset, 16, &address_ipv6);
}
redir_address.type = AT_IPv6;
redir_address.len = 16;
redir_address.data = (const guint8 *)&address_ipv6;
conv = find_conversation(pinfo->num, &redir_address, &pinfo->dst,
PT_UDP, port_num, 0, NO_PORT_B);
if (conv == NULL) {
conv = conversation_new(pinfo->num, &redir_address,
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
guint32 tvb_len = tvb_reported_length(tvb);
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
proto_tree_add_bitmask(addr_tree, tvb, offset, hf_address_flags_length, ett_address_flags, address_length_flags, ENC_NA);
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
proto_tree_add_item (addr_tree, hf_address_ipv4_addr,
tvb, offset, 4, ENC_NA);
break;
case BT_IPv6:
if (address_len != 16) {
goto unknown_address_type;
}
proto_tree_add_item (addr_tree, hf_address_ipv6_addr,
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
add_headers (proto_tree *tree, tvbuff_t *tvb, int hf, packet_info *pinfo)
{
guint8 hdr_id, val_id, codepage = 1;
gint32 tvb_len = tvb_reported_length(tvb);
gint32 offset = 0;
gint32 save_offset;
gint32 hdr_len, hdr_start;
gint32 val_len, val_start;
gchar *hdr_str, *val_str;
proto_tree *wsp_headers;
proto_item *ti, *hidden_item;
guint8 ok;
guint32 val = 0;
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
save_offset = offset;
offset = WellKnownHeader[hdr_id & 0x7F](wsp_headers, tvb,
hdr_start, pinfo);
if (save_offset <= offset) {
expert_add_info(pinfo, ti, &ei_wsp_header_invalid);
break;
}
} else {
save_offset = offset;
offset = WellKnownOpenwaveHeader[hdr_id & 0x7F](wsp_headers,
tvb, hdr_start, pinfo);
if (save_offset <= offset) {
expert_add_info(pinfo, ti, &ei_wsp_header_invalid);
break;
}
}
} else if (hdr_id == 0x7F) {
codepage = tvb_get_guint8(tvb, offset+1);
proto_tree_add_uint(wsp_headers, hf_wsp_header_shift_code,
tvb, offset, 2, codepage);
offset += 2;
} else if (hdr_id >= 0x20) {
hdr_str = (gchar *)tvb_get_stringz_enc(wmem_packet_scope(), tvb, hdr_start, (gint *)&hdr_len, ENC_ASCII);
val_start = hdr_start + hdr_len;
val_id = tvb_get_guint8(tvb, val_start);
if (val_id >= 0x20 && val_id <=0x7E) {
val_str = (gchar *)tvb_get_stringz_enc(wmem_packet_scope(), tvb, val_start, (gint *)&val_len, ENC_ASCII);
offset = val_start + val_len;
proto_tree_add_string_format(wsp_headers, hf_wsp_header_text_value, tvb, hdr_start, offset-hdr_start,
val_str, "%s: %s", hdr_str, val_str);
} else {
if (g_ascii_strcasecmp(hdr_str, "x-wap.tod") == 0) {
get_delta_seconds_value(val, tvb, val_start, val_len, ok);
if (ok) {
nstime_t t;
t.secs = (time_t)val;
t.nsecs = 0;
if (val == 0) {
ti = proto_tree_add_time_format_value(wsp_headers, hf_hdr_x_wap_tod,
tvb, hdr_start, hdr_len + val_len, &t,
"Requesting Time Of Day");
} else {
ti = proto_tree_add_time(wsp_headers, hf_hdr_x_wap_tod,
tvb, hdr_start, hdr_len + val_len, &t);
}
expert_add_info(pinfo, ti, &ei_hdr_x_wap_tod);
} else {
proto_tree_add_expert_format(wsp_headers, pinfo, &ei_wsp_text_field_invalid,
tvb, hdr_start, hdr_len + val_len,
"Invalid value for the 'X-Wap-Tod' header");
}
} else {
proto_tree_add_expert_format(wsp_headers, pinfo, &ei_wsp_text_field_invalid, tvb, hdr_start, hdr_len,
"Invalid value for the textual '%s' header (should be a textual value)",
hdr_str);
}
offset = tvb_len;
}
hidden_item = proto_tree_add_string(wsp_headers, hf_hdr_name_string,
tvb, hdr_start, offset - hdr_start, hdr_str);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else if (hdr_id > 0) {
codepage = hdr_id;
proto_tree_add_uint (wsp_headers, hf_wsp_header_shift_code,
tvb, offset, 1, codepage);
offset++;
} else {
proto_tree_add_expert_format (wsp_headers, pinfo, &ei_wsp_text_field_invalid, tvb, hdr_start, 1,
"Invalid zero-length textual header");
offset = tvb_len;
}
}
}
static int
dissect_sir(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
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
col_append_str(pinfo->cinfo, COL_INFO, ": WAP Session Initiation Request");
ti = proto_tree_add_item(tree, hf_sir_section,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_sir);
version = tvb_get_guint8(tvb, 0);
proto_tree_add_uint(subtree, hf_sir_version,
tvb, 0, 1, version);
val_len = tvb_get_guintvar(tvb, 1, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(subtree, hf_sir_app_id_list_len,
tvb, 1, len, val_len);
offset = 1 + len;
tmp_tvb = tvb_new_subset_length(tvb, offset, val_len);
add_headers (subtree, tmp_tvb, hf_sir_app_id_list, pinfo);
offset += val_len;
val_len = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(subtree, hf_sir_wsp_contact_points_len,
tvb, offset, len, val_len);
offset += len;
tmp_tvb = tvb_new_subset_length (tvb, offset, val_len);
add_addresses(subtree, tmp_tvb, hf_sir_wsp_contact_points);
if (version == 0)
return offset;
offset += val_len;
val_len = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(subtree, hf_sir_contact_points_len,
tvb, offset, len, val_len);
offset += len;
tmp_tvb = tvb_new_subset_length(tvb, offset, val_len);
add_addresses(subtree, tmp_tvb, hf_sir_contact_points);
offset += val_len;
val_len = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(subtree, hf_sir_protocol_options_len,
tvb, offset, len, val_len);
offset += len;
val_len_save = val_len;
for (i = 0; i < val_len_save; i++) {
val_len = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(subtree, hf_sir_protocol_options,
tvb, offset, len, val_len);
offset += len;
}
val_len = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(subtree, hf_sir_prov_url_len,
tvb, offset, len, val_len);
offset += len;
proto_tree_add_item (tree, hf_sir_prov_url,
tvb, offset, val_len, ENC_ASCII|ENC_NA);
offset += val_len;
val_len = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(subtree, hf_sir_cpi_tag_len,
tvb, offset, len, val_len);
offset += len;
for (i = 0; i < val_len; i++) {
proto_tree_add_item(subtree, hf_sir_cpi_tag,
tvb, offset, 4, ENC_NA);
offset += 4;
}
return tvb_captured_length(tvb);
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
int found_match;
heur_dtbl_entry_t *hdtbl_entry;
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
value = tvb_get_guintvar (tvb, offset, &count, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint (wsp_tree,
hf_wsp_server_session_id,
tvb, offset, count, value);
proto_item_append_text(proto_ti, ", Session ID: %u", value);
offset += count;
}
count = 0;
capabilityLength = tvb_get_guintvar (tvb, offset, &count, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint (wsp_tree, hf_capabilities_length,
tvb, offset, count, capabilityLength);
offset += count;
if (pdut != WSP_PDU_RESUME)
{
count = 0;
headerLength = tvb_get_guintvar (tvb, offset, &count, pinfo, &ei_wsp_oversized_uintvar);
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
tmp_tvb = tvb_new_subset_length (tvb, offset,
capabilityLength);
add_capabilities (wsp_tree, pinfo, tmp_tvb, pdut);
offset += capabilityLength;
}
if (headerLength > 0)
{
tmp_tvb = tvb_new_subset_length (tvb, offset,
headerLength);
add_headers (wsp_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
break;
case WSP_PDU_REDIRECT:
dissect_redirect(tvb, offset, pinfo, wsp_tree, dissector_handle);
break;
case WSP_PDU_DISCONNECT:
case WSP_PDU_SUSPEND:
if (tree) {
count = 0;
value = tvb_get_guintvar (tvb, offset, &count, pinfo, &ei_wsp_oversized_uintvar);
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
value = tvb_get_guintvar (tvb, offset, &count, pinfo, &ei_wsp_oversized_uintvar);
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
uriLength = tvb_get_guintvar (tvb, offset, &count, pinfo, &ei_wsp_oversized_uintvar);
headerStart = uriStart+count;
count = 0;
headersLength = tvb_get_guintvar (tvb, headerStart, &count, pinfo, &ei_wsp_oversized_uintvar);
offset = headerStart + count;
add_uri (wsp_tree, pinfo, tvb, uriStart, offset, proto_ti);
offset += uriLength;
if (tree)
proto_tree_add_uint (wsp_tree, hf_wsp_header_length,
tvb, headerStart, count, headersLength);
if (headersLength == 0)
break;
contentTypeStart = offset;
nextOffset = add_content_type (wsp_tree, pinfo,
tvb, offset, &contentType, &contentTypeStr);
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
tmp_tvb = tvb_new_subset_length (tvb, nextOffset,
headerLength);
add_headers (wsp_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
if (tvb_reported_length_remaining(tvb,
headerStart + count + uriLength + headersLength) > 0)
{
tmp_tvb = tvb_new_subset_remaining (tvb,
headerStart + count + uriLength + headersLength);
found_match = 0;
if (contentTypeStr) {
found_match = dissector_try_string(media_type_table,
contentTypeStr, tmp_tvb, pinfo, tree, NULL);
}
if (! found_match) {
if (! dissector_try_heuristic(heur_subdissector_list,
tmp_tvb, pinfo, tree, &hdtbl_entry, NULL)) {
pinfo->match_string = contentTypeStr;
call_dissector_with_data(media_handle, tmp_tvb, pinfo, tree, NULL );
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
headersLength = tvb_get_guintvar (tvb, offset+1, &count, pinfo, &ei_wsp_oversized_uintvar);
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
nextOffset = add_content_type (wsp_tree, pinfo, tvb,
nextOffset, &contentType, &contentTypeStr);
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
tmp_tvb = tvb_new_subset_length (tvb, nextOffset,
headerLength);
add_headers (wsp_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
if (tvb_reported_length_remaining(tvb, headerStart + headersLength)
> 0)
{
tmp_tvb = tvb_new_subset_remaining (tvb, headerStart + headersLength);
found_match = 0;
if (contentTypeStr) {
found_match = dissector_try_string(media_type_table,
contentTypeStr, tmp_tvb, pinfo, tree, NULL);
}
if (! found_match) {
if (! dissector_try_heuristic(heur_subdissector_list,
tmp_tvb, pinfo, tree, &hdtbl_entry, NULL)) {
pinfo->match_string = contentTypeStr;
call_dissector_with_data(media_handle, tmp_tvb, pinfo, tree, NULL );
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
headersLength = tvb_get_guintvar (tvb, offset, &count, pinfo, &ei_wsp_oversized_uintvar);
headerStart = offset + count;
proto_tree_add_uint (wsp_tree, hf_wsp_header_length,
tvb, offset, count, headersLength);
if (headersLength == 0)
break;
offset += count;
contentTypeStart = offset;
nextOffset = add_content_type (wsp_tree, pinfo,
tvb, offset, &contentType, &contentTypeStr);
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
tmp_tvb = tvb_new_subset_length (tvb, nextOffset,
headerLength);
add_headers (wsp_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
if (tvb_reported_length_remaining(tvb, headerStart + headersLength)
> 0)
{
tmp_tvb = tvb_new_subset_remaining (tvb, headerStart + headersLength);
found_match = 0;
if (contentTypeStr) {
found_match = dissector_try_string(media_type_table,
contentTypeStr, tmp_tvb, pinfo, tree, NULL);
}
if (! found_match) {
if (! dissector_try_heuristic(heur_subdissector_list,
tmp_tvb, pinfo, tree, &hdtbl_entry, NULL)) {
pinfo->match_string = contentTypeStr;
call_dissector_with_data(media_handle, tmp_tvb, pinfo, tree, NULL );
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
static int
dissect_wsp_fromudp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WSP");
col_clear(pinfo->cinfo, COL_INFO);
dissect_wsp_common(tvb, pinfo, tree, wsp_fromudp_handle, TRUE);
return tvb_captured_length(tvb);
}
static int
dissect_wsp_fromwap_co(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_wsp_common(tvb, pinfo, tree, wtp_fromudp_handle, FALSE);
return tvb_captured_length(tvb);
}
static int
dissect_wsp_fromwap_cl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_clear(pinfo->cinfo, COL_INFO);
dissect_wsp_common(tvb, pinfo, tree, wtp_fromudp_handle, TRUE);
return tvb_captured_length(tvb);
}
static void
add_uri (proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
guint URILenOffset, guint URIOffset, proto_item *proto_ti)
{
guint count = 0;
guint uriLen = tvb_get_guintvar (tvb, URILenOffset, &count, pinfo, &ei_wsp_oversized_uintvar);
gchar *str;
proto_tree_add_uint (tree, hf_wsp_header_uri_len,
tvb, URILenOffset, count, uriLen);
proto_tree_add_item (tree, hf_wsp_header_uri,
tvb, URIOffset, uriLen, ENC_ASCII|ENC_NA);
str = tvb_format_text (tvb, URIOffset, uriLen);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", str);
if (proto_ti)
proto_item_append_text(proto_ti, ", URI: %s", str);
}
static void
add_capabilities (proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, guint8 pdu_type)
{
proto_tree *wsp_capabilities, *cap_subtree, *cap_subtree2;
proto_item *ti, *cap_item, *cap_item2;
char *capaName, *str;
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
return;
}
ti = proto_tree_add_item(tree, hf_capabilities_section,
tvb, 0, tvb_len, ENC_NA);
wsp_capabilities = proto_item_add_subtree(ti, ett_capabilities);
while (offset < tvb_len) {
capaStart = offset;
capaValueLen = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
capaLen = capaValueLen + len;
cap_subtree = proto_tree_add_subtree(wsp_capabilities, tvb, offset, capaLen, ett_capabilities_entry, &cap_item, "Capability");
offset += len;
peek = tvb_get_guint8(tvb, offset);
if (is_token_text(peek)) {
capaName = (gchar *)tvb_get_stringz_enc(wmem_packet_scope(), tvb, capaStart, (gint *)&len, ENC_ASCII);
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
expert_add_info_format(pinfo, cap_item, &ei_wsp_capability_invalid,
"Unknown or invalid textual capability: %s", capaName);
offset = capaStart + capaLen;
continue;
}
offset += len;
} else if (peek < 0x80) {
expert_add_info_format(pinfo, cap_item, &ei_wsp_capability_invalid,
"Invalid well-known capability: 0x%02X", peek);
return;
}
if (peek & 0x80) {
peek &= 0x7F;
len = 1;
offset++;
}
proto_item_append_text(cap_item, ": %s", val_to_str_const(peek, wsp_capability_vals, "Invalid capabiliity"));
switch (peek) {
case WSP_CAPA_CLIENT_SDU_SIZE:
value = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(cap_subtree, hf_capa_client_sdu_size,
tvb, offset, len, value);
break;
case WSP_CAPA_SERVER_SDU_SIZE:
value = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(cap_subtree, hf_capa_server_sdu_size,
tvb, offset, len, value);
break;
case WSP_CAPA_PROTOCOL_OPTIONS:
if (capaValueLen - len == 1) {
static const int * capabilities[] = {
&hf_capa_protocol_option_confirmed_push,
&hf_capa_protocol_option_push,
&hf_capa_protocol_option_session_resume,
&hf_capa_protocol_option_ack_headers,
&hf_capa_protocol_option_large_data_transfer,
NULL
};
proto_tree_add_bitmask_with_flags(cap_subtree, tvb, offset, hf_capa_protocol_options,
ett_proto_option_capability, capabilities, ENC_NA, BMT_NO_FALSE);
}
else
{
proto_item_append_text(cap_item,
" <warning: bit field too large>");
offset = capaStart + capaLen;
continue;
}
break;
case WSP_CAPA_METHOD_MOR:
proto_tree_add_item(cap_subtree, hf_capa_method_mor, tvb, offset, len, ENC_NA);
break;
case WSP_CAPA_PUSH_MOR:
proto_tree_add_item(cap_subtree, hf_capa_push_mor, tvb, offset, len, ENC_NA);
break;
case WSP_CAPA_EXTENDED_METHODS:
cap_subtree2 = proto_tree_add_subtree(cap_subtree, tvb, capaStart, capaLen, ett_capabilities_extended_methods, &cap_item2, "Extended Methods");
if (pdu_type == WSP_PDU_CONNECT) {
while (offset < capaStart + capaLen) {
ti = proto_tree_add_item(cap_subtree2, hf_capa_extended_method, tvb, offset, 1, ENC_NA);
offset++;
get_text_string(str, tvb, offset, len, ok);
if (! ok) {
expert_add_info(pinfo, ti, &ei_wsp_capability_encoding_invalid);
return;
}
proto_item_append_text(ti, " = %s", str);
proto_item_set_len(ti, len+1);
offset += len;
}
} else {
while (offset < capaStart + capaLen) {
proto_tree_add_item(cap_subtree2, hf_capa_extended_method, tvb, offset, 1, ENC_NA);
offset++;
}
}
break;
case WSP_CAPA_HEADER_CODE_PAGES:
cap_subtree2 = proto_tree_add_subtree(cap_subtree, tvb, capaStart, capaLen, ett_capabilities_header_code_pages, &cap_item2, "Header Code Pages");
if (pdu_type == WSP_PDU_CONNECT) {
while (offset < capaStart + capaLen) {
ti = proto_tree_add_item(cap_subtree2, hf_capa_header_code_page, tvb, offset, 1, ENC_NA);
offset++;
get_text_string(str, tvb, offset, len, ok);
if (! ok) {
expert_add_info(pinfo, ti, &ei_wsp_capability_encoding_invalid);
return;
}
proto_item_append_text(ti, " = %s", str);
proto_item_set_len(ti, len+1);
offset += len;
}
} else {
while (offset < capaStart + capaLen) {
proto_tree_add_item(cap_subtree2, hf_capa_header_code_page, tvb, offset, 1, ENC_NA);
offset++;
}
}
break;
case WSP_CAPA_ALIASES:
proto_tree_add_item(cap_subtree, hf_capa_aliases,
tvb, capaStart, capaLen, ENC_NA);
break;
case WSP_CAPA_CLIENT_MESSAGE_SIZE:
value = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(cap_subtree, hf_capa_client_message_size,
tvb, offset, len, value);
break;
case WSP_CAPA_SERVER_MESSAGE_SIZE:
value = tvb_get_guintvar(tvb, offset, &len, pinfo, &ei_wsp_oversized_uintvar);
proto_tree_add_uint(cap_subtree, hf_capa_server_message_size,
tvb, offset, len, value);
break;
default:
expert_add_info_format(pinfo, cap_item, &ei_wsp_capability_invalid,
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
}
static void
add_post_variable (proto_tree *tree, tvbuff_t *tvb, guint variableStart, guint variableEnd, guint valueStart, guint valueEnd)
{
int variableLength = variableEnd-variableStart;
int valueLength = 0;
char *variableBuffer;
char *valueBuffer;
variableBuffer = tvb_get_string_enc(wmem_packet_scope(), tvb, variableStart, variableLength, ENC_ASCII);
if (valueEnd < valueStart)
{
valueBuffer = (char *)wmem_alloc(wmem_packet_scope(), 1);
valueBuffer[0] = 0;
valueEnd = valueStart;
}
else
{
valueLength = valueEnd-valueStart;
valueBuffer = tvb_get_string_enc(wmem_packet_scope(), tvb, valueStart, valueLength, ENC_ASCII);
}
if (valueStart >= tvb_reported_length (tvb))
{
valueStart = tvb_reported_length (tvb);
valueEnd = valueStart;
}
valueLength = valueEnd-valueStart;
proto_tree_add_string_format(tree, hf_wsp_variable_value, tvb, variableStart, valueLength, valueBuffer, "%s: %s", variableBuffer, valueBuffer);
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
int found_match = 0;
proto_item *sub_tree = NULL;
proto_item *ti = NULL;
proto_tree *mpart_tree = NULL;
heur_dtbl_entry_t *hdtbl_entry;
nEntries = tvb_get_guintvar (tvb, offset, &count, pinfo, &ei_wsp_oversized_uintvar);
offset += count;
if (nEntries)
{
sub_tree = proto_tree_add_subtree(tree, tvb, offset - count, 0,
ett_mpartlist, NULL, "Multipart body");
}
while (nEntries--)
{
part_start = offset;
HeadersLen = tvb_get_guintvar (tvb, offset, &count, pinfo, &ei_wsp_oversized_uintvar);
offset += count;
DataLen = tvb_get_guintvar (tvb, offset, &count, pinfo, &ei_wsp_oversized_uintvar);
offset += count;
ti = proto_tree_add_uint(sub_tree, hf_wsp_mpart, tvb, part_start,
HeadersLen + DataLen + (offset - part_start), partnr);
mpart_tree = proto_item_add_subtree(ti, ett_multiparts);
nextOffset = add_content_type (mpart_tree, pinfo, tvb, offset,
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
tmp_tvb = tvb_new_subset_length (tvb, nextOffset, HeadersLen);
add_headers (mpart_tree, tmp_tvb, hf_wsp_headers_section, pinfo);
}
offset = nextOffset + HeadersLen;
tmp_tvb = tvb_new_subset_length(tvb, offset, DataLen);
found_match = 0;
if (contentTypeStr) {
found_match = dissector_try_string(media_type_table,
contentTypeStr, tmp_tvb, pinfo, mpart_tree, NULL);
}
if (! found_match) {
if (! dissector_try_heuristic(heur_subdissector_list,
tmp_tvb, pinfo, mpart_tree, &hdtbl_entry, NULL)) {
pinfo->match_string = contentTypeStr;
call_dissector_with_data(media_handle, tmp_tvb, pinfo, mpart_tree, NULL );
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
static void wsp_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
int num_fields = sizeof(wsp_stat_fields)/sizeof(stat_tap_table_item);
stat_tap_table* pt_table = new_stat_tap_init_table("PDU Types", num_fields, 0, NULL, gui_callback, gui_data);
stat_tap_table_item_type pt_items[sizeof(wsp_stat_fields)/sizeof(stat_tap_table_item)];
stat_tap_table* sc_table = new_stat_tap_init_table("Status Codes", num_fields, 0, NULL, gui_callback, gui_data);
stat_tap_table_item_type sc_items[sizeof(wsp_stat_fields)/sizeof(stat_tap_table_item)];
int table_idx;
new_stat_tap_add_table(new_stat, pt_table);
new_stat_tap_add_table(new_stat, sc_table);
table_idx = 0;
memset(pt_items, 0, sizeof(pt_items));
pt_items[MESSAGE_TYPE_COLUMN].type = TABLE_ITEM_STRING;
pt_items[PACKET_COLUMN].type = TABLE_ITEM_UINT;
while (wsp_vals_pdu_type[table_idx].strptr)
{
pt_items[MESSAGE_TYPE_COLUMN].value.string_value = g_strdup(wsp_vals_pdu_type[table_idx].strptr);
pt_items[MESSAGE_TYPE_COLUMN].user_data.uint_value = wsp_vals_pdu_type[table_idx].value;
new_stat_tap_init_table_row(pt_table, table_idx, num_fields, pt_items);
table_idx++;
}
pt_items[MESSAGE_TYPE_COLUMN].value.string_value = g_strdup("Unknown PDU type");
pt_items[MESSAGE_TYPE_COLUMN].user_data.uint_value = 0;
new_stat_tap_init_table_row(pt_table, table_idx, num_fields, pt_items);
unknown_pt_idx = table_idx;
table_idx = 0;
memset(sc_items, 0, sizeof(sc_items));
sc_items[MESSAGE_TYPE_COLUMN].type = TABLE_ITEM_STRING;
sc_items[PACKET_COLUMN].type = TABLE_ITEM_UINT;
while (wsp_vals_status[table_idx].strptr)
{
sc_items[MESSAGE_TYPE_COLUMN].value.string_value = g_strdup(wsp_vals_status[table_idx].strptr);
sc_items[MESSAGE_TYPE_COLUMN].user_data.uint_value = wsp_vals_status[table_idx].value;
new_stat_tap_init_table_row(sc_table, table_idx, num_fields, sc_items);
table_idx++;
}
sc_items[MESSAGE_TYPE_COLUMN].value.string_value = g_strdup("Unknown status code");
sc_items[MESSAGE_TYPE_COLUMN].user_data.uint_value = 0;
new_stat_tap_init_table_row(sc_table, table_idx, num_fields, sc_items);
unknown_sc_idx = table_idx;
}
static gboolean
wsp_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *wiv_ptr)
{
new_stat_data_t* stat_data = (new_stat_data_t*)tapdata;
const wsp_info_value_t *value = (const wsp_info_value_t *)wiv_ptr;
stat_tap_table *pt_table, *sc_table;
guint element;
stat_tap_table_item_type* item_data;
gboolean found;
pt_table = g_array_index(stat_data->stat_tap_data->tables, stat_tap_table*, 0);
sc_table = g_array_index(stat_data->stat_tap_data->tables, stat_tap_table*, 1);
found = FALSE;
for (element = 0; element < pt_table->num_elements; element++) {
item_data = new_stat_tap_get_field_data(pt_table, element, MESSAGE_TYPE_COLUMN);
if (value->pdut == item_data->user_data.uint_value) {
found = TRUE;
break;
}
}
if (!found) {
element = unknown_pt_idx;
}
item_data = new_stat_tap_get_field_data(pt_table, element, PACKET_COLUMN);
item_data->value.uint_value++;
new_stat_tap_set_field_data(pt_table, element, PACKET_COLUMN, item_data);
if (value->status_code != 0) {
found = FALSE;
for (element = 0; element < sc_table->num_elements; element++) {
item_data = new_stat_tap_get_field_data(sc_table, element, MESSAGE_TYPE_COLUMN);
if (value->status_code == (int) item_data->user_data.uint_value) {
found = TRUE;
break;
}
}
if (!found) {
element = unknown_sc_idx;
}
item_data = new_stat_tap_get_field_data(sc_table, element, PACKET_COLUMN);
item_data->value.uint_value++;
new_stat_tap_set_field_data(sc_table, element, PACKET_COLUMN, item_data);
}
return TRUE;
}
static void
wsp_stat_reset(stat_tap_table* table)
{
guint element;
stat_tap_table_item_type* item_data;
for (element = 0; element < table->num_elements; element++)
{
item_data = new_stat_tap_get_field_data(table, element, PACKET_COLUMN);
item_data->value.uint_value = 0;
new_stat_tap_set_field_data(table, element, PACKET_COLUMN, item_data);
}
}
static void
wsp_stat_free_table_item(stat_tap_table* table _U_, guint row _U_, guint column, stat_tap_table_item_type* field_data)
{
if (column != MESSAGE_TYPE_COLUMN) return;
g_free((char*)field_data->value.string_value);
field_data->value.string_value = NULL;
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
{ &hf_wsp_parameter_untype_quote_text,
{ "Untyped quoted text",
"wsp.untype.quote_text",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_parameter_untype_text,
{ "Untyped text",
"wsp.untype.text",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_parameter_untype_int,
{ "Untyped integer",
"wsp.untype.int",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_parameter_type,
{ "Parameter Type",
"wsp.parameter.type",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &parameter_type_vals_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_parameter_int_type,
{ "Integer Type",
"wsp.parameter.int_type",
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
FT_UINT8, BASE_HEX, NULL, 0x00,
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
{ &hf_capa_extended_method,
{ "Extended Method",
"wsp.capability.extended_method",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_capa_header_code_page,
{ "Header Code Page",
"wsp.capability.code_page",
FT_UINT8, BASE_HEX, NULL, 0x00,
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
{ &hf_wsp_header_text_value,
{ "Header textual value",
"wsp.header_text_value",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_variable_value,
{ "Variable value",
"wsp.variable_value",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_default_int,
{ "Default integer",
"wsp.default_int",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_default_string,
{ "Default string value",
"wsp.default_string",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wsp_default_val_len,
{ "Default value len",
"wsp.default_val_len",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL
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
{ &hf_hdr_name_value,
{ "Header name",
"wsp.header.name_value",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &vals_field_names_ext, 0x7F,
"Name of the WSP header as numeric value", HFILL
}
},
{ &hf_hdr_name_string,
{ "Header name",
"wsp.header.name_string",
FT_STRING, BASE_NONE, NULL, 0x0,
"Name of the WSP header as string", HFILL
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
FT_BYTES, BASE_NONE, NULL, 0x00,
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
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
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
{ &hf_hdr_openwave_default_int,
{ "Default integer",
"wsp.default_int",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_hdr_openwave_default_string,
{ "Default string value",
"wsp.default_string",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_hdr_openwave_default_val_len,
{ "Default value len",
"wsp.default_val_len",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_hdr_openwave_name_value,
{ "Header name",
"wsp.header.name_value",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &vals_openwave_field_names_ext, 0x7F,
"WSP Openwave header as numeric value", HFILL
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
&ett_content_type_header,
&ett_wsp_parameter_type,
&ett_capabilities,
&ett_capabilities_entry,
&ett_proto_option_capability,
&ett_capabilities_extended_methods,
&ett_capabilities_header_code_pages,
&ett_post,
&ett_redirect_flags,
&ett_address_flags,
&ett_multiparts,
&ett_mpartlist,
&ett_addresses,
&ett_address,
&ett_default,
&ett_add_content_type,
&ett_accept_x_q_header,
&ett_push_flag,
&ett_profile_diff_wbxml,
&ett_allow,
&ett_public,
&ett_vary,
&ett_x_wap_security,
&ett_connection,
&ett_transfer_encoding,
&ett_accept_ranges,
&ett_content_encoding,
&ett_accept_encoding,
&ett_content_disposition,
&ett_text_header,
&ett_content_id,
&ett_text_or_date_value,
&ett_date_value,
&ett_tod_value,
&ett_age,
&ett_integer_lookup,
&ett_challenge,
&ett_credentials_value,
&ett_content_md5,
&ett_pragma,
&ett_integer_value,
&ett_integer_lookup_value,
&ett_cache_control,
&ett_warning,
&ett_profile_warning,
&ett_encoding_version,
&ett_content_range,
&ett_range,
&ett_te_value,
&ett_openwave_default,
};
static ei_register_info ei[] = {
{ &ei_wsp_capability_invalid, { "wsp.capability.invalid", PI_PROTOCOL, PI_WARN, "Invalid capability", EXPFILL }},
{ &ei_wsp_capability_encoding_invalid, { "wsp.capability_encoding.invalid", PI_PROTOCOL, PI_WARN, "Invalid capability encoding", EXPFILL }},
{ &ei_wsp_text_field_invalid, { "wsp.text_field_invalid", PI_PROTOCOL, PI_WARN, "Text field invalid", EXPFILL }},
{ &ei_wsp_invalid_parameter_value, { "wsp.invalid_parameter_value", PI_PROTOCOL, PI_WARN, "Invalid parameter value", EXPFILL }},
{ &ei_wsp_header_invalid_value, { "wsp.header_invalid_value", PI_PROTOCOL, PI_WARN, "Invalid header value", EXPFILL }},
{ &ei_hdr_x_wap_tod, { "wsp.header.x_wap_tod.not_text", PI_PROTOCOL, PI_WARN, "Should be encoded as a textual value", EXPFILL }},
{ &ei_wsp_undecoded_parameter, { "wsp.undecoded_parameter", PI_UNDECODED, PI_WARN, "Invalid parameter value", EXPFILL }},
{ &ei_wsp_trailing_quote, { "wsp.trailing_quote", PI_PROTOCOL, PI_WARN, "Quoted-string value has been encoded with a trailing quote", EXPFILL }},
{ &ei_wsp_header_invalid, { "wsp.header_invalid", PI_MALFORMED, PI_ERROR, "Malformed header", EXPFILL }},
{ &ei_wsp_oversized_uintvar, { "wsp.oversized_uintvar", PI_MALFORMED, PI_ERROR, "Uintvar is oversized", EXPFILL }}
};
expert_module_t* expert_wsp;
proto_wsp = proto_register_protocol(
"Wireless Session Protocol",
"WSP",
"wsp"
);
wsp_tap = register_tap("wsp");
proto_register_field_array(proto_wsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_wsp = expert_register_protocol(proto_wsp);
expert_register_field_array(expert_wsp, ei, array_length(ei));
register_dissector("wsp-co", dissect_wsp_fromwap_co, proto_wsp);
register_dissector("wsp-cl", dissect_wsp_fromwap_cl, proto_wsp);
heur_subdissector_list = register_heur_dissector_list("wsp", proto_wsp);
wsp_fromudp_handle = create_dissector_handle(dissect_wsp_fromudp,
proto_wsp);
}
void
proto_reg_handoff_wsp(void)
{
wtp_fromudp_handle = find_dissector_add_dependency("wtp-udp", proto_wsp);
media_handle = find_dissector_add_dependency("media", proto_wsp);
wbxml_uaprof_handle = find_dissector_add_dependency("wbxml-uaprof", proto_wsp);
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
static tap_param wsp_stat_params[] = {
{ PARAM_FILTER, "filter", "Filter", NULL, TRUE }
};
static stat_tap_table_ui wsp_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY,
"WAP-WSP Packet Counter",
"wsp",
"wsp,stat",
wsp_stat_init,
wsp_stat_packet,
wsp_stat_reset,
wsp_stat_free_table_item,
NULL,
sizeof(wsp_stat_fields)/sizeof(stat_tap_table_item), wsp_stat_fields,
sizeof(wsp_stat_params)/sizeof(tap_param), wsp_stat_params,
NULL,
0
};
proto_sir = proto_register_protocol(
"WAP Session Initiation Request",
"WAP SIR",
"wap-sir"
);
proto_register_field_array(proto_sir, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_stat_tap_table_ui(&wsp_stat_table);
}
void
proto_reg_handoff_sir(void)
{
dissector_handle_t sir_handle;
sir_handle = create_dissector_handle(dissect_sir, proto_sir);
dissector_add_string("media_type", "application/vnd.wap.sia", sir_handle);
}
