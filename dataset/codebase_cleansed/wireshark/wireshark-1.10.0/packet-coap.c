static int
coap_is_str_ipv6addr(guint8 *str)
{
size_t len = strlen(str);
int colon = 0;
while (len--) {
if (*str++ == ':')
colon++;
}
return colon > 1 ? 1 : 0;
}
static gint
coap_get_opt_uint(tvbuff_t *tvb, gint offset, gint length)
{
switch (length) {
case 0:
return 0;
case 1:
return (guint)tvb_get_guint8(tvb, offset);
case 2:
return (guint)tvb_get_ntohs(tvb, offset);
case 3:
return (guint)tvb_get_ntoh24(tvb, offset);
case 4:
return (guint)tvb_get_ntohl(tvb, offset);
default:
return -1;
}
}
static gint
coap_opt_check(packet_info *pinfo, proto_tree *subtree, guint opt_num, gint opt_length)
{
int i;
for (i = 0; i < (int)(array_length(coi)); i++) {
if (coi[i].type == opt_num)
break;
}
if (i == (int)(array_length(coi))) {
expert_add_info_format(pinfo, subtree, PI_MALFORMED, PI_WARN,
"Invalid Option Number %d", opt_num);
return -1;
}
if (opt_length < coi[i].min || opt_length > coi[i].max) {
expert_add_info_format(pinfo, subtree, PI_MALFORMED,
PI_WARN, "Invalid Option Range: %d (%d < x < %d)",
opt_length, coi[i].min, coi[i].max);
}
return 0;
}
static void
dissect_coap_opt_hex_string(tvbuff_t *tvb, proto_item *item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length, int hf)
{
const guint8 *str;
gint dp = offset + opt_hlen;
if (opt_length == 0)
str = nullstr;
else
str = tvb_bytes_to_str_punct(tvb, dp, opt_length, ' ');
proto_tree_add_string(subtree, hf, tvb, dp, opt_length, str);
proto_item_append_text(item, ": %s", str);
}
static void
dissect_coap_opt_uint(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length, int hf)
{
guint i = 0;
gint dp, len;
if (opt_length == 0) {
dp = offset;
len = opt_hlen;
i = 0;
} else {
dp = offset + opt_hlen;
len = opt_length;
i = coap_get_opt_uint(tvb, dp, len);
}
proto_tree_add_uint(subtree, hf, tvb, dp, len, i);
proto_item_append_text(head_item, ": %d", i);
}
static void
dissect_coap_opt_uri_host(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length)
{
guint8 *str = NULL;
gint dp = offset + opt_hlen;
str = tvb_get_ephemeral_string(tvb, dp, opt_length);
proto_tree_add_string(subtree, hf_coap_opt_uri_host, tvb, dp, opt_length, str);
proto_item_append_text(head_item, ": %s", str);
g_strlcat(coap_uri_str, "coap://", sizeof(coap_uri_str));
if (coap_is_str_ipv6addr(str)) {
g_strlcat(coap_uri_str, "[", sizeof(coap_uri_str));
g_strlcat(coap_uri_str, str, sizeof(coap_uri_str));
g_strlcat(coap_uri_str, "]", sizeof(coap_uri_str));
} else
g_strlcat(coap_uri_str, str, sizeof(coap_uri_str));
}
static void
dissect_coap_opt_uri_path(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length)
{
const guint8 *str = NULL;
gint dp, len;
g_strlcat(coap_uri_str, "/", sizeof(coap_uri_str));
if (opt_length == 0) {
dp = offset;
len = opt_hlen;
str = nullstr;
} else {
dp = offset + opt_hlen;
len = opt_length;
str = tvb_get_ephemeral_string(tvb, dp, len);
g_strlcat(coap_uri_str, str, sizeof(coap_uri_str));
}
proto_tree_add_string(subtree, hf_coap_opt_uri_path, tvb, dp, len, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_uri_query(tvbuff_t *tvb, proto_item *head_item,proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length)
{
const guint8 *str = NULL;
gint dp, len;
if (coap_uri_query[0] == '\0')
g_strlcat(coap_uri_query, "?", sizeof(coap_uri_str));
else
g_strlcat(coap_uri_query, "&", sizeof(coap_uri_str));
if (opt_length == 0) {
dp = offset;
len = opt_hlen;
str = nullstr;
} else {
dp = offset + opt_hlen;
len = opt_length;
str = tvb_get_ephemeral_string(tvb, dp, len);
g_strlcat(coap_uri_str, str, sizeof(coap_uri_str));
}
proto_tree_add_string(subtree, hf_coap_opt_uri_query, tvb, dp, len, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_location_path(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length)
{
const guint8 *str = NULL;
gint dp, len;
if (opt_length == 0) {
dp = offset;
len = opt_hlen;
str = nullstr;
} else {
dp = offset + opt_hlen;
len = opt_length;
str = tvb_get_ephemeral_string(tvb, dp, len);
}
proto_tree_add_string(subtree, hf_coap_opt_location_path, tvb, dp, len, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_location_query(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length)
{
const guint8 *str = NULL;
gint dp, len;
if (opt_length == 0) {
dp = offset;
len = opt_hlen;
str = nullstr;
} else {
dp = offset + opt_hlen;
len = opt_length;
str = tvb_get_ephemeral_string(tvb, dp, len);
}
proto_tree_add_string(subtree, hf_coap_opt_location_query, tvb, dp, len, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_proxy_uri(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length)
{
const guint8 *str = NULL;
gint dp, len;
if (opt_length == 0) {
dp = offset;
len = opt_hlen;
str = nullstr;
} else {
dp = offset + opt_hlen;
len = opt_length;
str = tvb_get_ephemeral_string(tvb, dp, len);
}
proto_tree_add_string(subtree, hf_coap_opt_proxy_uri, tvb, dp, len, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_token(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length)
{
gint dp = offset + opt_hlen;
g_strlcat(coap_token_str, tvb_bytes_to_str_punct(tvb, dp, opt_length, ' '), sizeof(coap_token_str));
proto_tree_add_string(subtree, hf_coap_opt_token, tvb, dp, opt_length, coap_token_str);
proto_item_append_text(head_item, ": %s", coap_token_str);
}
static void
dissect_coap_opt_ctype(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length, int hf)
{
gint dp, len;
if (opt_length == 0) {
dp = offset;
len = opt_hlen;
coap_ctype_value = 0;
} else {
dp = offset + opt_hlen;
len = opt_length;
coap_ctype_value = coap_get_opt_uint(tvb, dp, len);
}
coap_ctype_str = val_to_str(coap_ctype_value, vals_ctype, "Unknown Type %d");
proto_tree_add_string(subtree, hf, tvb, dp, len, coap_ctype_str);
proto_item_append_text(head_item, ": %s", coap_ctype_str);
}
static void
dissect_coap_opt_block(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length)
{
guint8 val = 0;
guint encoded_block_size = 0;
guint block_esize;
gint dp, len;
gint dp2;
if (opt_length == 0) {
dp = offset;
len = opt_hlen;
coap_block_number = 0;
val = 0;
dp2 = dp;
} else {
dp = offset + opt_hlen;
len = opt_length;
coap_block_number = coap_get_opt_uint(tvb, dp, len) >> 4;
val = tvb_get_guint8(tvb, offset + opt_length - 1) & 0x0f;
dp2 = dp + opt_length - 1;
}
proto_tree_add_uint(subtree, hf_coap_opt_block_number,
tvb, dp, len, coap_block_number);
coap_block_mflag = val & 0x08;
proto_tree_add_uint(subtree, hf_coap_opt_block_mflag,
tvb, dp2, 1, coap_block_mflag);
encoded_block_size = val & 0x07;
block_esize = 1 << (encoded_block_size + 4);
proto_tree_add_uint_format(subtree, hf_coap_opt_block_size,
tvb, dp2, 1, encoded_block_size, "Block Size: %d (%d encoded)", block_esize, encoded_block_size);
proto_item_append_text(head_item, ": NUM:%d, M:%d, SZX:%d",
coap_block_number, coap_block_mflag, block_esize);
}
static void
dissect_coap_opt_uri_port(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_hlen, gint opt_length)
{
guint port = 0;
char portstr[6];
gint dp, len;
memset(portstr, '\0', sizeof(portstr));
if (opt_length == 0) {
dp = offset;
len = opt_hlen;
port = 0;
} else {
dp = offset;
len = opt_hlen;
port = coap_get_opt_uint(tvb, dp, len);
}
proto_tree_add_uint(subtree, hf_coap_opt_uri_port, tvb, dp, len, port);
proto_item_append_text(head_item, ": %d", port);
g_snprintf(portstr, sizeof(portstr), "%u", port);
g_strlcat(coap_uri_str, ":", sizeof(coap_uri_str));
g_strlcat(coap_uri_str, portstr, sizeof(coap_uri_str));
}
static int
dissect_coap_options_main(tvbuff_t *tvb, packet_info *pinfo, proto_tree *coap_tree, gint offset, guint8 opt_count, guint *opt_num, gint coap_length)
{
guint8 opt_jump;
gint opt_length, tmp_length, jump_length;
proto_tree *subtree = NULL;
proto_item *item = NULL;
gint opt_hlen, max_hlen;
tvbuff_t *tvb_lenbuf = NULL;
char strbuf[56];
opt_jump = tvb_get_guint8(tvb, offset);
switch (opt_jump) {
case 0xf0:
if (opt_count != 15) {
expert_add_info_format(pinfo, subtree,
PI_MALFORMED, PI_WARN,
"end-of-options marker found, but OC isn't 15");
return -1;
}
proto_tree_add_string(coap_tree, hf_coap_opt_jump,
tvb, offset, 1, "end-of-options marker");
return ++offset;
case 0xf1:
jump_length = 15;
proto_tree_add_uint_format(coap_tree, hf_coap_opt_jump,
tvb, offset, 1, jump_length, "Option Jump (0xf1): %d", jump_length);
*opt_num += jump_length;
offset++;
opt_jump = tvb_get_guint8(tvb, offset);
break;
case 0xf2:
jump_length = (tvb_get_guint8(tvb, offset + 1) + 2) * 8;
proto_tree_add_uint_format(coap_tree, hf_coap_opt_jump,
tvb, offset, 2, jump_length, "Option Jump (0xf2): %d", jump_length);
*opt_num += jump_length;
offset += 2;
opt_jump = tvb_get_guint8(tvb, offset);
break;
case 0xf3:
jump_length = (tvb_get_ntohs(tvb, offset + 1) + 258) * 8;
proto_tree_add_uint_format(coap_tree, hf_coap_opt_jump,
tvb, offset, 3, jump_length, "Option Jump (0xf3): %d", jump_length);
*opt_num += jump_length;
offset += 3;
opt_jump = tvb_get_guint8(tvb, offset);
break;
}
max_hlen = 4;
opt_hlen = 1;
opt_length = opt_jump & 0x0f;
if (opt_length == 0x0f) {
do {
tmp_length = tvb_get_guint8(tvb, offset + opt_hlen);
opt_length += tmp_length;
opt_hlen++;
} while (!(opt_hlen == max_hlen || tmp_length != 0xff));
}
if (max_hlen < opt_hlen) {
expert_add_info_format(pinfo, subtree, PI_MALFORMED, PI_WARN,
"Invalid Option Length: all %d bits are set, which is not"
" allowed by the spec 12", max_hlen * 8 - 4);
return -1;
}
if (coap_length < offset) {
expert_add_info_format(pinfo, subtree, PI_MALFORMED, PI_WARN,
"Invalid length: coap payload length(%d) < offset(%d)",
coap_length, offset);
return -1;
}
*opt_num += ((opt_jump & 0xf0) >> 4);
coap_opt_check(pinfo, subtree, *opt_num, opt_length);
g_snprintf(strbuf, sizeof(strbuf),
"#%u: %s", opt_count, val_to_str_const(*opt_num, vals_opt_type,
*opt_num % 14 == 0 ? "No-Op" : "Unknown Option"));
item = proto_tree_add_string(coap_tree, hf_coap_opt_name,
tvb, offset, opt_hlen + opt_length, strbuf);
subtree = proto_item_add_subtree(item, ett_coap_option);
g_snprintf(strbuf, sizeof(strbuf),
"Type %u, %s, %s%s", *opt_num,
(*opt_num & 1) ? "Critical" : "Elective",
(*opt_num & 2) ? "Unsafe" : "Safe",
((*opt_num & 0x1e) == 0x1c) ? ", NoCacheKey" : "");
proto_tree_add_string(subtree, hf_coap_opt_desc,
tvb, offset, opt_hlen + opt_length, strbuf);
proto_tree_add_item(subtree, hf_coap_opt_delta, tvb, offset, 1,
ENC_BIG_ENDIAN);
tvb_lenbuf = tvb_new_subset(tvb, offset, opt_hlen, opt_hlen);
proto_tree_add_uint_bits_format_value(subtree, hf_coap_opt_length,
tvb_lenbuf, 4, 4 + ((opt_hlen - 1) * 8), opt_length, "%d",
opt_length);
switch (*opt_num) {
case COAP_OPT_CONTENT_TYPE:
dissect_coap_opt_ctype(tvb, item, subtree, offset,
opt_hlen, opt_length, hf_coap_opt_ctype);
break;
case COAP_OPT_MAX_AGE:
dissect_coap_opt_uint(tvb, item, subtree, offset,
opt_hlen, opt_length, hf_coap_opt_max_age);
break;
case COAP_OPT_PROXY_URI:
dissect_coap_opt_proxy_uri(tvb, item, subtree, offset,
opt_hlen, opt_length);
break;
case COAP_OPT_ETAG:
dissect_coap_opt_hex_string(tvb, item, subtree, offset,
opt_hlen, opt_length, hf_coap_opt_etag);
break;
case COAP_OPT_URI_HOST:
dissect_coap_opt_uri_host(tvb, item, subtree, offset,
opt_hlen, opt_length);
break;
case COAP_OPT_LOCATION_PATH:
dissect_coap_opt_location_path(tvb, item, subtree, offset,
opt_hlen, opt_length);
break;
case COAP_OPT_URI_PORT:
dissect_coap_opt_uri_port(tvb, item, subtree, offset,
opt_hlen, opt_length);
break;
case COAP_OPT_LOCATION_QUERY:
dissect_coap_opt_location_query(tvb, item, subtree, offset,
opt_hlen, opt_length);
break;
case COAP_OPT_URI_PATH:
dissect_coap_opt_uri_path(tvb, item, subtree, offset,
opt_hlen, opt_length);
break;
case COAP_OPT_OBSERVE:
dissect_coap_opt_uint(tvb, item, subtree, offset,
opt_hlen, opt_length, hf_coap_opt_observe);
break;
case COAP_OPT_TOKEN:
dissect_coap_opt_token(tvb, item, subtree, offset,
opt_hlen, opt_length);
break;
case COAP_OPT_ACCEPT:
dissect_coap_opt_ctype(tvb, item, subtree, offset,
opt_hlen, opt_length, hf_coap_opt_accept);
break;
case COAP_OPT_IF_MATCH:
dissect_coap_opt_hex_string(tvb, item, subtree, offset,
opt_hlen, opt_length, hf_coap_opt_if_match);
break;
case COAP_OPT_URI_QUERY:
dissect_coap_opt_uri_query(tvb, item, subtree, offset,
opt_hlen, opt_length);
break;
case COAP_OPT_BLOCK2:
dissect_coap_opt_block(tvb, item, subtree, offset,
opt_hlen, opt_length);
break;
case COAP_OPT_BLOCK1:
dissect_coap_opt_block(tvb, item, subtree, offset,
opt_hlen, opt_length);
break;
case COAP_OPT_IF_NONE_MATCH:
break;
case COAP_OPT_BLOCK_SIZE:
dissect_coap_opt_uint(tvb, item, subtree, offset,
opt_hlen, opt_length, hf_coap_opt_block_size);
break;
default:
dissect_coap_opt_hex_string(tvb, item, subtree, offset,
opt_hlen, opt_length, hf_coap_opt_unknown);
break;
}
return offset + opt_hlen + opt_length;
}
static int
dissect_coap_options(tvbuff_t *tvb, packet_info *pinfo, proto_tree *coap_tree, gint offset, gint coap_length, guint8 opt_count)
{
guint opt_num = 0;
int i;
for (i = 1; i <= opt_count; i++) {
offset = dissect_coap_options_main(tvb, pinfo, coap_tree,
offset, i, &opt_num, coap_length);
if (offset == -1)
return -1;
}
return offset;
}
static void
dissect_coap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
gint offset = 0;
proto_item *coap_root = NULL;
proto_tree *coap_tree = NULL;
guint8 ttype = 0;
guint8 opt_count = 0;
guint8 code = 0;
guint16 tid = 0;
gint coap_length = 0;
coap_length = tvb_reported_length(tvb);
coap_ctype_str = "";
coap_ctype_value = DEFAULT_COAP_CTYPE_VALUE;
coap_root = proto_tree_add_item(parent_tree, proto_coap, tvb, offset, -1, ENC_NA);
coap_tree = proto_item_add_subtree(coap_root, ett_coap);
proto_tree_add_item(coap_tree, hf_coap_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(coap_tree, hf_coap_ttype, tvb, offset, 1, ENC_BIG_ENDIAN);
ttype = (tvb_get_guint8(tvb, offset) & 0x30) >> 4;
proto_tree_add_item(coap_tree, hf_coap_opt_count, tvb, offset, 1, ENC_BIG_ENDIAN);
opt_count = tvb_get_guint8(tvb, offset) & 0x0f;
offset += 1;
proto_tree_add_item(coap_tree, hf_coap_code, tvb, offset, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(coap_tree, hf_coap_tid, tvb, offset, 2, ENC_BIG_ENDIAN);
tid = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_item_append_text(coap_tree, ", %s, %s, TID:%u", val_to_str(ttype, vals_ttype, "Unkown %d"), val_to_str(code, vals_code, "Unknown %d"), tid);
coap_block_number = DEFAULT_COAP_BLOCK_NUMBER;
coap_block_mflag = 0;
coap_uri_str[0] = '\0';
coap_uri_query[0] = '\0';
coap_token_str[0] = '\0';
offset = dissect_coap_options(tvb, pinfo, coap_tree, offset, coap_length, opt_count);
if (offset == -1)
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CoAP");
col_clear(pinfo->cinfo, COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(ttype, vals_ttype_short, "Unknown %d"));
col_append_fstr(pinfo->cinfo, COL_INFO, ", TID:%u", tid);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str(code, vals_code, "Unknown %d"));
if (coap_token_str[0] != '\0')
col_append_fstr(pinfo->cinfo, COL_INFO, ", TKN:%s", coap_token_str);
if (coap_block_number != DEFAULT_COAP_BLOCK_NUMBER)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %sBlock #%d", coap_block_mflag ? "" : "End of ", coap_block_number);
if (coap_uri_str[0] != '\0')
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", coap_uri_str);
if (coap_uri_query[0] != '\0')
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", coap_uri_query);
if (coap_length > offset) {
proto_tree *payload_tree = NULL;
proto_item *payload_item = NULL;
tvbuff_t *payload_tvb;
guint payload_length = coap_length - offset;
char str_payload[80];
if (coap_ctype_value == DEFAULT_COAP_CTYPE_VALUE)
coap_ctype_str = "text/plain; charset=utf-8";
g_snprintf(str_payload, sizeof(str_payload),
"Payload Content-Format: %s%s, Length: %u, offset: %u",
coap_ctype_str, coap_ctype_value == DEFAULT_COAP_CTYPE_VALUE ?
" (no Content-Format)" : "", payload_length, offset);
proto_tree_add_string(coap_tree, hf_coap_payload_desc,
tvb, offset, -1, coap_ctype_str);
payload_tree = proto_item_add_subtree(payload_item, ett_coap_payload);
payload_tvb = tvb_new_subset(tvb, offset, payload_length, payload_length);
dissector_try_string(media_type_dissector_table, coap_ctype_str, payload_tvb, pinfo, payload_tree);
}
}
void
proto_register_coap(void)
{
static hf_register_info hf[] = {
{ &hf_coap_version,
{ "Version", "coap.version",
FT_UINT8, BASE_DEC, NULL, 0xc0,
"CoAP Version", HFILL }
},
{ &hf_coap_ttype,
{ "Type", "coap.type",
FT_UINT8, BASE_DEC, VALS(vals_ttype), 0x30,
"CoAP Transaction Type", HFILL }
},
{ &hf_coap_opt_count,
{ "Opt Count", "coap.ocount",
FT_UINT8, BASE_DEC, NULL, 0x0f,
"CoAP Option Count", HFILL }
},
{ &hf_coap_code,
{ "Code", "coap.code",
FT_UINT8, BASE_DEC, VALS(vals_code), 0x0,
"CoAP Method or Response Code", HFILL }
},
{ &hf_coap_tid,
{ "Transaction ID", "coap.tid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"CoAP Transaction ID", HFILL }
},
{ &hf_coap_payload_desc,
{ "Payload Desc", "coap.opt.payload_desc",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Payload Description", HFILL }
},
{ &hf_coap_opt_name,
{ "Opt Name", "coap.opt.name",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Name", HFILL }
},
{ &hf_coap_opt_desc,
{ "Opt Desc", "coap.opt.desc",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Description", HFILL }
},
{ &hf_coap_opt_jump,
{ "Opt Jump", "coap.opt.jump",
FT_UINT8, BASE_DEC, NULL, 0xf0,
"CoAP Option Jump", HFILL }
},
{ &hf_coap_opt_delta,
{ "Opt Delta", "coap.opt.delta",
FT_UINT8, BASE_DEC, NULL, 0xf0,
"CoAP Option Delta", HFILL }
},
{ &hf_coap_opt_length,
{ "Opt Length", "coap.opt.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"CoAP Option Length", HFILL }
},
{ &hf_coap_opt_ctype,
{ "Content-type", "coap.opt.ctype",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Content Type", HFILL }
},
{ &hf_coap_opt_max_age,
{ "Max-age", "coap.opt.max_age",
FT_UINT32, BASE_DEC, NULL, 0x0,
"CoAP Option Max-age", HFILL }
},
{ &hf_coap_opt_proxy_uri,
{ "Proxy-Uri", "coap.opt.proxy_uri",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Proxy-Uri", HFILL }
},
{ &hf_coap_opt_etag,
{ "Etag", "coap.opt.etag",
FT_BYTES, BASE_NONE, NULL, 0x0,
"CoAP Option Etag", HFILL }
},
{ &hf_coap_opt_uri_host,
{ "Uri-Host", "coap.opt.uri_host",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Uri-Host", HFILL }
},
{ &hf_coap_opt_location_path,
{ "Location-Path", "coap.opt.location_path",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Uri-Path", HFILL }
},
{ &hf_coap_opt_uri_port,
{ "Uri-Port", "coap.opt.uri_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"CoAP Option Uri-Port", HFILL }
},
{ &hf_coap_opt_location_query,
{ "Location-Query", "coap.opt.location_query",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Uri-Query", HFILL }
},
{ &hf_coap_opt_uri_path,
{ "Uri-Path", "coap.opt.uri_path",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Uri-Path", HFILL }
},
{ &hf_coap_opt_observe,
{ "Lifetime", "coap.opt.subscr_lifetime",
FT_INT32, BASE_DEC, NULL, 0x0,
"CoAP Option Observe", HFILL }
},
{ &hf_coap_opt_token,
{ "Token", "coap.opt.token",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Token", HFILL }
},
{ &hf_coap_opt_accept,
{ "Accept", "coap.opt.accept",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Acceptable Content Type", HFILL }
},
{ &hf_coap_opt_if_match,
{ "If-Match", "coap.opt.if_match",
FT_BYTES, BASE_NONE, NULL, 0x0,
"CoAP Option If-Match", HFILL }
},
{ &hf_coap_opt_block_number,
{ "Block Number", "coap.opt.block_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
"CoAP Option Block Number", HFILL }
},
{ &hf_coap_opt_block_mflag,
{ "More Flag", "coap.opt.block_mflag",
FT_UINT8, BASE_DEC, NULL, 0x08,
"CoAP Option Block More Size", HFILL }
},
{ &hf_coap_opt_block_size,
{ "Encoded Block Size", "coap.opt.block_size",
FT_UINT8, BASE_DEC, NULL, 0x07,
"CoAP Option Encoded Block Size", HFILL }
},
{ &hf_coap_opt_uri_query,
{ "Uri-Query", "coap.opt.uri_query",
FT_STRING, BASE_NONE, NULL, 0x0,
"CoAP Option Uri-Query", HFILL }
},
{ &hf_coap_opt_unknown,
{ "Unknown", "coap.opt.unknown",
FT_STRING, BASE_NONE, NULL, 0x0,
"Coap Unknown Option", HFILL }
},
};
static gint *ett[] = {
&ett_coap,
&ett_coap_option,
&ett_coap_payload,
};
module_t *coap_module;
proto_coap = proto_register_protocol("Constrained Application Protocol", "CoAP", "coap");
proto_register_field_array(proto_coap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("coap", dissect_coap, proto_coap);
coap_module = prefs_register_protocol (proto_coap, proto_reg_handoff_coap);
prefs_register_uint_preference (coap_module, "udp_port",
"CoAP port number",
"Port number used for CoAP traffic",
10, &global_coap_port_number);
}
void
proto_reg_handoff_coap(void)
{
static gboolean coap_prefs_initialized = FALSE;
static dissector_handle_t coap_handle;
static guint coap_port_number;
if (!coap_prefs_initialized) {
coap_handle = find_dissector("coap");
media_type_dissector_table = find_dissector_table("media_type");
coap_prefs_initialized = TRUE;
} else {
dissector_delete_uint("udp.port", coap_port_number, coap_handle);
dissector_delete_uint("tcp.port", coap_port_number, coap_handle);
}
coap_port_number = global_coap_port_number;
dissector_add_uint("udp.port", coap_port_number, coap_handle);
dissector_add_uint("tcp.port", coap_port_number, coap_handle);
}
