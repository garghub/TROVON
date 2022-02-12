static conversation_t *
find_or_create_conversation_noaddrb(packet_info *pinfo, gboolean request)
{
conversation_t *conv=NULL;
address *addr_a;
address *addr_b;
guint32 port_a;
guint32 port_b;
if (request) {
addr_a = &pinfo->src;
addr_b = &pinfo->dst;
port_a = pinfo->srcport;
port_b = pinfo->destport;
} else {
addr_a = &pinfo->dst;
addr_b = &pinfo->src;
port_a = pinfo->destport;
port_b = pinfo->srcport;
}
if((conv = find_conversation(pinfo->num, addr_a, addr_b,
pinfo->ptype, port_a,
port_b, NO_ADDR_B|NO_PORT_B)) != NULL) {
if (pinfo->num > conv->last_frame) {
conv->last_frame = pinfo->num;
}
} else {
conv = conversation_new(pinfo->num, &pinfo->src,
&pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, NO_ADDR_B|NO_PORT_B);
}
return conv;
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
expert_add_info_format(pinfo, subtree, &ei_coap_invalid_option_number,
"Invalid Option Number %u", opt_num);
return -1;
}
if (opt_length < coi[i].min || opt_length > coi[i].max) {
expert_add_info_format(pinfo, subtree, &ei_coap_invalid_option_range,
"Invalid Option Range: %d (%d < x < %d)", opt_length, coi[i].min, coi[i].max);
}
return 0;
}
static void
dissect_coap_opt_hex_string(tvbuff_t *tvb, proto_item *item, proto_tree *subtree, gint offset, gint opt_length, int hf)
{
const guint8 *str;
if (opt_length == 0)
str = nullstr;
else
str = tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, offset, opt_length, ' ');
proto_tree_add_item(subtree, hf, tvb, offset, opt_length, ENC_NA);
proto_item_append_text(item, ": %s", str);
}
static void
dissect_coap_opt_uint(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_length, int hf)
{
guint i = 0;
if (opt_length != 0) {
i = coap_get_opt_uint(tvb, offset, opt_length);
}
proto_tree_add_uint(subtree, hf, tvb, offset, opt_length, i);
proto_item_append_text(head_item, ": %u", i);
}
static void
dissect_coap_opt_uri_host(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_length, coap_info *coinfo)
{
const guint8 *str;
proto_tree_add_item_ret_string(subtree, hf_coap_opt_uri_host, tvb, offset, opt_length, ENC_ASCII, wmem_packet_scope(), &str);
proto_item_append_text(head_item, ": %s", str);
if (strchr(str, ':') == NULL) {
wmem_strbuf_append_printf(coinfo->uri_str_strbuf, "coap://%s", str);
} else {
wmem_strbuf_append_printf(coinfo->uri_str_strbuf, "coap://[%s]", str);
}
}
static void
dissect_coap_opt_uri_path(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_length, coap_info *coinfo)
{
const guint8 *str = NULL;
wmem_strbuf_append_c(coinfo->uri_str_strbuf, '/');
if (opt_length == 0) {
str = nullstr;
} else {
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, opt_length, ENC_ASCII);
wmem_strbuf_append(coinfo->uri_str_strbuf, str);
}
proto_tree_add_string(subtree, hf_coap_opt_uri_path, tvb, offset, opt_length, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_uri_query(tvbuff_t *tvb, proto_item *head_item,proto_tree *subtree, gint offset, gint opt_length, coap_info *coinfo)
{
const guint8 *str = NULL;
wmem_strbuf_append_c(coinfo->uri_query_strbuf,
(wmem_strbuf_get_len(coinfo->uri_query_strbuf) == 0) ? '?' : '&');
if (opt_length == 0) {
str = nullstr;
} else {
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, opt_length, ENC_ASCII);
wmem_strbuf_append(coinfo->uri_query_strbuf, str);
}
proto_tree_add_string(subtree, hf_coap_opt_uri_query, tvb, offset, opt_length, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_location_path(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_length)
{
const guint8 *str = NULL;
if (opt_length == 0) {
str = nullstr;
} else {
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, opt_length, ENC_ASCII);
}
proto_tree_add_string(subtree, hf_coap_opt_location_path, tvb, offset, opt_length, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_location_query(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_length)
{
const guint8 *str = NULL;
if (opt_length == 0) {
str = nullstr;
} else {
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, opt_length, ENC_ASCII);
}
proto_tree_add_string(subtree, hf_coap_opt_location_query, tvb, offset, opt_length, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_proxy_uri(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_length)
{
const guint8 *str = NULL;
if (opt_length == 0) {
str = nullstr;
} else {
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, opt_length, ENC_ASCII);
}
proto_tree_add_string(subtree, hf_coap_opt_proxy_uri, tvb, offset, opt_length, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_proxy_scheme(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_length)
{
const guint8 *str = NULL;
if (opt_length == 0) {
str = nullstr;
} else {
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, opt_length, ENC_ASCII);
}
proto_tree_add_string(subtree, hf_coap_opt_proxy_scheme, tvb, offset, opt_length, str);
proto_item_append_text(head_item, ": %s", str);
}
static void
dissect_coap_opt_ctype(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_length, int hf, coap_info *coinfo)
{
if (opt_length == 0) {
coinfo->ctype_value = 0;
} else {
coinfo->ctype_value = coap_get_opt_uint(tvb, offset, opt_length);
}
coinfo->ctype_str = val_to_str(coinfo->ctype_value, vals_ctype, "Unknown Type %u");
proto_tree_add_string(subtree, hf, tvb, offset, opt_length, coinfo->ctype_str);
proto_item_append_text(head_item, ": %s", coinfo->ctype_str);
}
static void
dissect_coap_opt_block(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_length, coap_info *coinfo)
{
guint8 val = 0;
guint encoded_block_size;
guint block_esize;
if (opt_length == 0) {
coinfo->block_number = 0;
val = 0;
} else {
coinfo->block_number = coap_get_opt_uint(tvb, offset, opt_length) >> 4;
val = tvb_get_guint8(tvb, offset + opt_length - 1) & 0x0f;
}
proto_tree_add_uint(subtree, hf_coap_opt_block_number,
tvb, offset, opt_length, coinfo->block_number);
coinfo->block_mflag = val & 0x08;
proto_tree_add_uint(subtree, hf_coap_opt_block_mflag,
tvb, offset + opt_length - 1, 1, coinfo->block_mflag);
encoded_block_size = val & 0x07;
block_esize = 1 << (encoded_block_size + 4);
proto_tree_add_uint_format(subtree, hf_coap_opt_block_size,
tvb, offset + opt_length - 1, 1, encoded_block_size, "Block Size: %u (%u encoded)", block_esize, encoded_block_size);
proto_item_append_text(head_item, ": NUM:%u, M:%u, SZX:%u",
coinfo->block_number, coinfo->block_mflag, block_esize);
}
static void
dissect_coap_opt_uri_port(tvbuff_t *tvb, proto_item *head_item, proto_tree *subtree, gint offset, gint opt_length, coap_info *coinfo)
{
guint port = 0;
if (opt_length != 0) {
port = coap_get_opt_uint(tvb, offset, opt_length);
}
proto_tree_add_uint(subtree, hf_coap_opt_uri_port, tvb, offset, opt_length, port);
proto_item_append_text(head_item, ": %u", port);
wmem_strbuf_append_printf(coinfo->uri_str_strbuf, ":%u", port);
}
static int
dissect_coap_options_main(tvbuff_t *tvb, packet_info *pinfo, proto_tree *coap_tree, gint offset, guint8 opt_count, guint *opt_num, gint coap_length, coap_info *coinfo)
{
guint8 opt_jump;
gint opt_length, opt_length_ext, opt_delta, opt_delta_ext;
gint opt_length_ext_off = 0;
gint8 opt_length_ext_len = 0;
gint opt_delta_ext_off = 0;
gint8 opt_delta_ext_len = 0;
gint orig_offset = offset;
proto_tree *subtree;
proto_item *item;
char strbuf[56];
opt_jump = tvb_get_guint8(tvb, offset);
if (0xff == opt_jump)
return offset;
offset += 1;
switch (opt_jump & 0xf0) {
case 0xd0:
opt_delta_ext = tvb_get_guint8(tvb, offset);
opt_delta_ext_off = offset;
opt_delta_ext_len = 1;
offset += 1;
opt_delta = 13;
opt_delta += opt_delta_ext;
break;
case 0xe0:
opt_delta_ext = coap_get_opt_uint(tvb, offset, 2);
opt_delta_ext_off = offset;
opt_delta_ext_len = 2;
offset += 2;
opt_delta = 269;
opt_delta += opt_delta_ext;
break;
case 0xf0:
expert_add_info_format(pinfo, coap_tree, &ei_coap_option_length_bad,
"end-of-options marker found, but option length isn't 15");
return -1;
default:
opt_delta = ((opt_jump & 0xf0) >> 4);
break;
}
*opt_num += opt_delta;
switch (opt_jump & 0x0f) {
case 0x0d:
opt_length_ext = tvb_get_guint8(tvb, offset);
opt_length_ext_off = offset;
opt_length_ext_len = 1;
offset += 1;
opt_length = 13;
opt_length += opt_length_ext;
break;
case 0x0e:
opt_length_ext = coap_get_opt_uint(tvb, offset, 2);
opt_length_ext_off = offset;
opt_length_ext_len = 2;
offset += 2;
opt_length = 269;
opt_length += opt_length_ext;
break;
case 0x0f:
expert_add_info_format(pinfo, coap_tree, &ei_coap_option_length_bad,
"end-of-options marker found, but option delta isn't 15");
return -1;
default:
opt_length = (opt_jump & 0x0f);
break;
}
if (offset + opt_length > coap_length) {
expert_add_info_format(pinfo, coap_tree, &ei_coap_option_length_bad,
"option longer than the package");
return -1;
}
coap_opt_check(pinfo, coap_tree, *opt_num, opt_length);
g_snprintf(strbuf, sizeof(strbuf),
"#%u: %s", opt_count, val_to_str_const(*opt_num, vals_opt_type,
*opt_num % 14 == 0 ? "No-Op" : "Unknown Option"));
item = proto_tree_add_string(coap_tree, hf_coap_opt_name,
tvb, orig_offset, offset - orig_offset + opt_length, strbuf);
subtree = proto_item_add_subtree(item, ett_coap_option);
g_snprintf(strbuf, sizeof(strbuf),
"Type %u, %s, %s%s", *opt_num,
(*opt_num & 1) ? "Critical" : "Elective",
(*opt_num & 2) ? "Unsafe" : "Safe",
((*opt_num & 0x1e) == 0x1c) ? ", NoCacheKey" : "");
proto_tree_add_string(subtree, hf_coap_opt_desc,
tvb, orig_offset, offset - orig_offset + opt_length, strbuf);
proto_tree_add_item(subtree, hf_coap_opt_delta, tvb, orig_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_coap_opt_length, tvb, orig_offset, 1, ENC_BIG_ENDIAN);
if (opt_delta_ext_off && opt_delta_ext_len)
proto_tree_add_item(subtree, hf_coap_opt_delta_ext, tvb, opt_delta_ext_off, opt_delta_ext_len, ENC_BIG_ENDIAN);
if (opt_length_ext_off && opt_length_ext_len)
proto_tree_add_item(subtree, hf_coap_opt_length_ext, tvb, opt_length_ext_off, opt_length_ext_len, ENC_BIG_ENDIAN);
switch (*opt_num) {
case COAP_OPT_CONTENT_TYPE:
dissect_coap_opt_ctype(tvb, item, subtree, offset,
opt_length, hf_coap_opt_ctype, coinfo);
break;
case COAP_OPT_MAX_AGE:
dissect_coap_opt_uint(tvb, item, subtree, offset,
opt_length, hf_coap_opt_max_age);
break;
case COAP_OPT_PROXY_URI:
dissect_coap_opt_proxy_uri(tvb, item, subtree, offset,
opt_length);
break;
case COAP_OPT_PROXY_SCHEME:
dissect_coap_opt_proxy_scheme(tvb, item, subtree, offset,
opt_length);
break;
case COAP_OPT_SIZE1:
dissect_coap_opt_uint(tvb, item, subtree, offset,
opt_length, hf_coap_opt_size1);
break;
case COAP_OPT_ETAG:
dissect_coap_opt_hex_string(tvb, item, subtree, offset,
opt_length, hf_coap_opt_etag);
break;
case COAP_OPT_URI_HOST:
dissect_coap_opt_uri_host(tvb, item, subtree, offset,
opt_length, coinfo);
break;
case COAP_OPT_LOCATION_PATH:
dissect_coap_opt_location_path(tvb, item, subtree, offset,
opt_length);
break;
case COAP_OPT_URI_PORT:
dissect_coap_opt_uri_port(tvb, item, subtree, offset,
opt_length, coinfo);
break;
case COAP_OPT_LOCATION_QUERY:
dissect_coap_opt_location_query(tvb, item, subtree, offset,
opt_length);
break;
case COAP_OPT_URI_PATH:
dissect_coap_opt_uri_path(tvb, item, subtree, offset,
opt_length, coinfo);
break;
case COAP_OPT_OBSERVE:
dissect_coap_opt_uint(tvb, item, subtree, offset,
opt_length, hf_coap_opt_observe);
break;
case COAP_OPT_ACCEPT:
dissect_coap_opt_ctype(tvb, item, subtree, offset,
opt_length, hf_coap_opt_accept, coinfo);
break;
case COAP_OPT_IF_MATCH:
dissect_coap_opt_hex_string(tvb, item, subtree, offset,
opt_length, hf_coap_opt_if_match);
break;
case COAP_OPT_URI_QUERY:
dissect_coap_opt_uri_query(tvb, item, subtree, offset,
opt_length, coinfo);
break;
case COAP_OPT_BLOCK2:
dissect_coap_opt_block(tvb, item, subtree, offset,
opt_length, coinfo);
break;
case COAP_OPT_BLOCK1:
dissect_coap_opt_block(tvb, item, subtree, offset,
opt_length, coinfo);
break;
case COAP_OPT_IF_NONE_MATCH:
break;
case COAP_OPT_BLOCK_SIZE:
dissect_coap_opt_uint(tvb, item, subtree, offset,
opt_length, hf_coap_opt_block_size);
break;
default:
dissect_coap_opt_hex_string(tvb, item, subtree, offset,
opt_length, hf_coap_opt_unknown);
break;
}
return offset + opt_length;
}
static int
dissect_coap_options(tvbuff_t *tvb, packet_info *pinfo, proto_tree *coap_tree, gint offset, gint coap_length, coap_info *coinfo)
{
guint opt_num = 0;
int i;
guint8 endmarker;
for (i = 1; offset < coap_length; i++) {
offset = dissect_coap_options_main(tvb, pinfo, coap_tree,
offset, i, &opt_num, coap_length, coinfo);
if (offset == -1)
return -1;
if (offset >= coap_length)
break;
endmarker = tvb_get_guint8(tvb, offset);
if (endmarker == 0xff) {
proto_tree_add_item(coap_tree, hf_coap_opt_end_marker, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
}
return offset;
}
static int
dissect_coap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
gint offset = 0;
proto_item *coap_root;
proto_item *pi;
proto_tree *coap_tree;
guint8 ttype;
guint8 token_len;
guint8 code;
guint8 code_class;
guint16 mid;
gint coap_length;
gchar *coap_token_str;
coap_info *coinfo;
conversation_t *conversation;
coap_conv_info *ccinfo;
coap_transaction *coap_trans = NULL;
if (!PINFO_FD_VISITED(pinfo)) {
coinfo = wmem_new0(wmem_file_scope(), coap_info);
p_add_proto_data(wmem_file_scope(), pinfo, proto_coap, 0, coinfo);
} else {
coinfo = (coap_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_coap, 0);
}
coap_length = tvb_reported_length(tvb);
coinfo->ctype_str = "";
coinfo->ctype_value = DEFAULT_COAP_CTYPE_VALUE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CoAP");
col_clear(pinfo->cinfo, COL_INFO);
coap_root = proto_tree_add_item(parent_tree, proto_coap, tvb, offset, -1, ENC_NA);
coap_tree = proto_item_add_subtree(coap_root, ett_coap);
proto_tree_add_item(coap_tree, hf_coap_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(coap_tree, hf_coap_ttype, tvb, offset, 1, ENC_BIG_ENDIAN);
ttype = (tvb_get_guint8(tvb, offset) & 0x30) >> 4;
proto_tree_add_item(coap_tree, hf_coap_token_len, tvb, offset, 1, ENC_BIG_ENDIAN);
token_len = tvb_get_guint8(tvb, offset) & 0x0f;
offset += 1;
proto_tree_add_item(coap_tree, hf_coap_code, tvb, offset, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, offset);
code_class = code >> 5;
offset += 1;
proto_tree_add_item(coap_tree, hf_coap_mid, tvb, offset, 2, ENC_BIG_ENDIAN);
mid = tvb_get_ntohs(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s, MID:%u, %s",
val_to_str(ttype, vals_ttype_short, "Unknown %u"),
mid,
val_to_str_ext(code, &vals_code_ext, "Unknown %u"));
proto_item_append_text(coap_root,
", %s, %s, MID:%u",
val_to_str(ttype, vals_ttype, "Unknown %u"),
val_to_str_ext(code, &vals_code_ext, "Unknown %u"),
mid);
offset += 2;
coinfo->block_number = DEFAULT_COAP_BLOCK_NUMBER;
coinfo->block_mflag = 0;
coinfo->uri_str_strbuf = wmem_strbuf_sized_new(wmem_packet_scope(), 0, 1024);
coinfo->uri_query_strbuf = wmem_strbuf_sized_new(wmem_packet_scope(), 0, 1024);
coap_token_str = NULL;
if (token_len > 0)
{
coap_token_str = tvb_bytes_to_str_punct(wmem_file_scope(), tvb, offset, token_len, ' ');
proto_tree_add_item(coap_tree, hf_coap_token,
tvb, offset, token_len, ENC_NA);
offset += token_len;
}
offset = dissect_coap_options(tvb, pinfo, coap_tree, offset, coap_length, coinfo);
if (offset == -1)
return tvb_captured_length(tvb);
conversation = find_or_create_conversation_noaddrb(pinfo, (code_class == 0));
ccinfo = (coap_conv_info *)conversation_get_proto_data(conversation, proto_coap);
if (!ccinfo) {
ccinfo = wmem_new(wmem_file_scope(), coap_conv_info);
ccinfo->messages = wmem_map_new(wmem_file_scope(), g_str_hash, g_str_equal);
conversation_add_proto_data(conversation, proto_coap, ccinfo);
}
if (coap_token_str != NULL) {
if (code != 0) {
coap_trans = (coap_transaction *)wmem_map_lookup(ccinfo->messages, coap_token_str);
if (!coap_trans) {
if ((!PINFO_FD_VISITED(pinfo)) && (code_class == 0)) {
coap_trans = wmem_new(wmem_file_scope(), coap_transaction);
coap_trans->req_frame = pinfo->num;
coap_trans->rsp_frame = 0;
coap_trans->req_time = pinfo->fd->abs_ts;
if (coinfo->uri_str_strbuf) {
coap_trans->uri_str_strbuf = wmem_strbuf_new(wmem_file_scope(), wmem_strbuf_get_str(coinfo->uri_str_strbuf));
}
wmem_map_insert(ccinfo->messages, coap_token_str, (void *)coap_trans);
}
} else {
if ((code_class >= 2) && (code_class <= 5)) {
if (!PINFO_FD_VISITED(pinfo)) {
coap_trans->rsp_frame = pinfo->num;
}
if (coap_trans->uri_str_strbuf) {
coinfo->uri_str_strbuf = wmem_strbuf_new(wmem_packet_scope(), wmem_strbuf_get_str(coap_trans->uri_str_strbuf));
}
}
}
}
}
if (coap_trans != NULL) {
if (code_class == 0) {
if (coap_trans->rsp_frame) {
proto_item *it;
it = proto_tree_add_uint(coap_tree, hf_coap_response_in,
tvb, 0, 0, coap_trans->rsp_frame);
PROTO_ITEM_SET_GENERATED(it);
}
} else if ((code_class >= 2) && (code_class <= 5)) {
if (coap_trans->req_frame) {
proto_item *it;
nstime_t ns;
it = proto_tree_add_uint(coap_tree, hf_coap_response_to,
tvb, 0, 0, coap_trans->req_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->fd->abs_ts, &coap_trans->req_time);
it = proto_tree_add_time(coap_tree, hf_coap_response_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
}
if (coap_token_str != NULL)
col_append_fstr(pinfo->cinfo, COL_INFO, ", TKN:%s", coap_token_str);
if (coinfo->block_number != DEFAULT_COAP_BLOCK_NUMBER)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %sBlock #%u",
coinfo->block_mflag ? "" : "End of ", coinfo->block_number);
if (wmem_strbuf_get_len(coinfo->uri_str_strbuf) > 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", wmem_strbuf_get_str(coinfo->uri_str_strbuf));
pi = proto_tree_add_string(coap_tree, hf_coap_opt_uri_path_recon, tvb, 0, 0, wmem_strbuf_get_str(coinfo->uri_str_strbuf));
PROTO_ITEM_SET_HIDDEN(pi);
}
if (wmem_strbuf_get_len(coinfo->uri_query_strbuf)> 0)
col_append_str(pinfo->cinfo, COL_INFO, wmem_strbuf_get_str(coinfo->uri_query_strbuf));
if (coap_length > offset) {
proto_tree *payload_tree;
proto_item *payload_item, *length_item;
tvbuff_t *payload_tvb;
guint payload_length = coap_length - offset;
const char *coap_ctype_str_dis;
char str_payload[80];
if (coinfo->ctype_value == DEFAULT_COAP_CTYPE_VALUE || coinfo->ctype_value == 0) {
if ((code_class >= 4) && (code_class <= 5)) {
coinfo->ctype_str = "text/plain; charset=utf-8";
coap_ctype_str_dis = "text/plain";
} else {
coinfo->ctype_str = "application/octet-stream";
coap_ctype_str_dis = coinfo->ctype_str;
}
} else {
coap_ctype_str_dis = coinfo->ctype_str;
}
g_snprintf(str_payload, sizeof(str_payload),
"Payload Content-Format: %s%s, Length: %u",
coinfo->ctype_str, coinfo->ctype_value == DEFAULT_COAP_CTYPE_VALUE ?
" (no Content-Format)" : "", payload_length);
payload_item = proto_tree_add_string(coap_tree, hf_coap_payload,
tvb, offset, payload_length,
str_payload);
payload_tree = proto_item_add_subtree(payload_item, ett_coap_payload);
proto_tree_add_string(payload_tree, hf_coap_payload_desc, tvb, offset, 0, coinfo->ctype_str);
length_item = proto_tree_add_uint(payload_tree, hf_coap_payload_length, tvb, offset, 0, payload_length);
PROTO_ITEM_SET_GENERATED(length_item);
payload_tvb = tvb_new_subset_length(tvb, offset, payload_length);
dissector_try_string(media_type_dissector_table, coap_ctype_str_dis,
payload_tvb, pinfo, parent_tree, NULL);
}
return tvb_captured_length(tvb);
}
void
proto_register_coap(void)
{
static hf_register_info hf[] = {
{ &hf_coap_version,
{ "Version", "coap.version",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_coap_ttype,
{ "Type", "coap.type",
FT_UINT8, BASE_DEC, VALS(vals_ttype), 0x30,
NULL, HFILL }
},
{ &hf_coap_token_len,
{ "Token Length", "coap.token_len",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_coap_token,
{ "Token", "coap.token",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_code,
{ "Code", "coap.code",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &vals_code_ext, 0x0,
NULL, HFILL }
},
{ &hf_coap_mid,
{ "Message ID", "coap.mid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_payload,
{ "Payload", "coap.payload",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_payload_desc,
{ "Payload Desc", "coap.payload_desc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_payload_length,
{ "Payload Length", "coap.payload_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_name,
{ "Opt Name", "coap.opt.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_desc,
{ "Opt Desc", "coap.opt.desc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_delta,
{ "Opt Delta", "coap.opt.delta",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_coap_opt_delta_ext,
{ "Opt Delta extended", "coap.opt.delta_ext",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_length,
{ "Opt Length", "coap.opt.length",
FT_UINT8, BASE_DEC, NULL, 0x0f,
"CoAP Option Length", HFILL }
},
{ &hf_coap_opt_length_ext,
{ "Opt Length extended", "coap.opt.length_ext",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_end_marker,
{ "End of options marker", "coap.opt.end_marker",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_coap_opt_ctype,
{ "Content-type", "coap.opt.ctype",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_max_age,
{ "Max-age", "coap.opt.max_age",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_proxy_uri,
{ "Proxy-Uri", "coap.opt.proxy_uri",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_proxy_scheme,
{ "Proxy-Scheme", "coap.opt.proxy_scheme",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_size1,
{ "Size1", "coap.opt.size1",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_etag,
{ "Etag", "coap.opt.etag",
FT_BYTES, BASE_NONE, NULL, 0x0,
"CoAP Option Etag", HFILL }
},
{ &hf_coap_opt_uri_host,
{ "Uri-Host", "coap.opt.uri_host",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_location_path,
{ "Location-Path", "coap.opt.location_path",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_uri_port,
{ "Uri-Port", "coap.opt.uri_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_location_query,
{ "Location-Query", "coap.opt.location_query",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_uri_path,
{ "Uri-Path", "coap.opt.uri_path",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_uri_path_recon,
{ "Uri-Path", "coap.opt.uri_path_recon",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_observe,
{ "Observe", "coap.opt.observe",
FT_UINT32, BASE_DEC, VALS(vals_observe_options), 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_accept,
{ "Accept", "coap.opt.accept",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_if_match,
{ "If-Match", "coap.opt.if_match",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_block_number,
{ "Block Number", "coap.opt.block_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_block_mflag,
{ "More Flag", "coap.opt.block_mflag",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_coap_opt_block_size,
{ "Encoded Block Size", "coap.opt.block_size",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_coap_opt_uri_query,
{ "Uri-Query", "coap.opt.uri_query",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_opt_unknown,
{ "Unknown", "coap.opt.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_coap_response_in,
{ "Response In", "coap.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this CoAP request is in this frame", HFILL }
},
{ &hf_coap_response_to,
{ "Request In", "coap.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the CoAP request in this frame", HFILL }
},
{ &hf_coap_response_time,
{ "Response Time", "coap.response_time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the Call and the Reply", HFILL }
},
};
static gint *ett[] = {
&ett_coap,
&ett_coap_option,
&ett_coap_payload,
};
static ei_register_info ei[] = {
{ &ei_coap_invalid_option_number,
{ "coap.invalid_option_number", PI_MALFORMED, PI_WARN, "Invalid Option Number", EXPFILL }},
{ &ei_coap_invalid_option_range,
{ "coap.invalid_option_range", PI_MALFORMED, PI_WARN, "Invalid Option Range", EXPFILL }},
{ &ei_coap_option_length_bad,
{ "coap.option_length_bad", PI_MALFORMED, PI_WARN, "Option length bad", EXPFILL }},
};
expert_module_t *expert_coap;
proto_coap = proto_register_protocol("Constrained Application Protocol", "CoAP", "coap");
proto_register_field_array(proto_coap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_coap = expert_register_protocol(proto_coap);
expert_register_field_array(expert_coap, ei, array_length(ei));
coap_handle = register_dissector("coap", dissect_coap, proto_coap);
}
void
proto_reg_handoff_coap(void)
{
media_type_dissector_table = find_dissector_table("media_type");
dissector_add_uint_with_preference("udp.port", DEFAULT_COAP_PORT, coap_handle);
dtls_dissector_add(DEFAULT_COAPS_PORT, coap_handle);
}
