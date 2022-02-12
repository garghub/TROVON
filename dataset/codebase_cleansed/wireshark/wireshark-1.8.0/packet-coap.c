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
static void
dissect_coap_opt_string(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *subtree, gint offset, gint opt_length, int hfindex, int opt_code)
{
guint8 *hoststr = NULL;
proto_tree_add_item(subtree, hfindex, tvb, offset, opt_length, ENC_UTF_8|ENC_NA);
switch (opt_code) {
case COAP_OPT_URI_HOST:
g_strlcat(uri_string, "coap://", sizeof(uri_string));
hoststr = tvb_get_ephemeral_string(tvb, offset, opt_length);
if (coap_is_str_ipv6addr(hoststr)) {
g_strlcat(uri_string, "[", sizeof(uri_string));
g_strlcat(uri_string, hoststr, sizeof(uri_string));
g_strlcat(uri_string, "]", sizeof(uri_string));
} else
g_strlcat(uri_string, hoststr, sizeof(uri_string));
break;
case COAP_OPT_URI_PATH:
g_strlcat(uri_string, "/", sizeof(uri_string));
g_strlcat(uri_string, tvb_get_ephemeral_string(tvb, offset, opt_length), sizeof(uri_string));
break;
case COAP_OPT_URI_QUERY:
g_strlcat(uri_string, "/?", sizeof(uri_string));
g_strlcat(uri_string, tvb_get_ephemeral_string(tvb, offset, opt_length), sizeof(uri_string));
break;
}
}
static void
dissect_coap_opt_ctype(tvbuff_t *tvb, packet_info *pinfo, proto_tree *subtree, gint offset, gint opt_length, int hfindex)
{
guint32 opt_ctype = 0;
if (opt_length != 1) {
expert_add_info_format(pinfo, subtree, PI_MALFORMED, PI_WARN, "Invalid Option Length: %d", opt_length);
return;
}
opt_ctype = tvb_get_guint8(tvb, offset);
coap_content_type_value = (gint)opt_ctype;
coap_content_type = val_to_str(opt_ctype, vals_ctype, "Unknown %d");
proto_tree_add_item(subtree, hfindex, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_coap_opt_time(tvbuff_t *tvb, packet_info *pinfo, proto_tree *subtree, gint offset, gint opt_length, int hfindex)
{
proto_item *item = NULL;
if (opt_length <= 0 || opt_length > 4) {
expert_add_info_format(pinfo, subtree, PI_MALFORMED, PI_WARN, "Invalid Option Length: %d", opt_length);
return;
}
item = proto_tree_add_item(subtree, hfindex, tvb, offset, opt_length, ENC_BIG_ENDIAN);
proto_item_append_text(item, " (s)");
return;
}
static void
dissect_coap_opt_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *subtree, gint offset, gint opt_length, int hfindex)
{
guint8 val = 0;
guint encoded_block_size = 0;
guint block_size;
proto_item *item = NULL;
switch (opt_length) {
case 1:
block_number = (guint)(tvb_get_guint8(tvb, offset) >> 4);
break;
case 2:
block_number = (guint)(tvb_get_ntohs(tvb, offset) >> 4);
break;
case 3:
block_number = (guint)(tvb_get_ntoh24(tvb, offset) >> 4);
break;
default:
expert_add_info_format(pinfo, subtree, PI_MALFORMED, PI_WARN, "Invalid Option Length: %d", opt_length);
return;
}
val = tvb_get_guint8(tvb, offset + opt_length - 1) & 0x0f;
encoded_block_size = val & 0x07;
block_mflag = val & 0x08;
proto_tree_add_int(subtree, hf_coap_opt_block_number, tvb, offset, opt_length, block_number);
proto_tree_add_item(subtree, hfindex, tvb, offset + opt_length - 1, 1, ENC_BIG_ENDIAN);
block_size = 1 << (encoded_block_size + 4);
item = proto_tree_add_item(subtree, hf_coap_opt_block_size, tvb, offset + opt_length - 1, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, ", Result: %d", block_size);
}
static void
dissect_coap_opt_port(tvbuff_t *tvb, packet_info *pinfo, proto_tree *subtree, gint offset, gint opt_length, int hfindex)
{
proto_item *item = NULL;
char portstr[6];
memset(portstr, '\0', sizeof(portstr));
switch (opt_length) {
case 0:
item = proto_tree_add_uint(subtree, hfindex, tvb, offset, opt_length, pinfo->destport);
proto_item_append_text(item, " (default)");
return;
case 1:
g_snprintf(portstr, sizeof(portstr), "%u", tvb_get_guint8(tvb, offset));
break;
case 2:
g_snprintf(portstr, sizeof(portstr), "%u", tvb_get_ntohs(tvb, offset));
break;
default:
expert_add_info_format(pinfo, subtree, PI_MALFORMED, PI_WARN, "Invalid Option Length: %d", opt_length);
return;
}
(void)proto_tree_add_item(subtree, hfindex, tvb, offset, opt_length, ENC_BIG_ENDIAN);
if (uri_string[0] == '\0')
g_strlcat(uri_string, ep_address_to_str(&pinfo->net_dst), sizeof(uri_string));
g_strlcat(uri_string, ":", sizeof(uri_string));
g_strlcat(uri_string, portstr, sizeof(uri_string));
return;
}
static int
dissect_coap_options(tvbuff_t *tvb, packet_info *pinfo, proto_tree *coap_tree, gint offset, guint8 opt_count, guint8 *opt_code)
{
guint8 opt_delta;
gint opt_length;
proto_tree *subtree = NULL;
proto_item *item = NULL;
gint opt_hlen = 0;
tvbuff_t *tvb_lenbuf = NULL;
opt_delta = (tvb_get_guint8(tvb, offset) & 0xf0) >> 4;
*opt_code += opt_delta;
opt_length = (tvb_get_guint8(tvb, offset) & 0x0f);
opt_hlen = 1;
if (opt_length == 0x0f) {
opt_length += tvb_get_guint8(tvb, offset + 1);
opt_hlen = 2;
}
item = proto_tree_add_text(coap_tree, tvb, offset, opt_hlen + opt_length,
"Option #%u: %s (Type: %u)",
opt_count, val_to_str(*opt_code, vals_opt_type, *opt_code % 14 == 0 ? "No-Op" : "Unknown Option"), *opt_code);
subtree = proto_item_add_subtree(item, ett_coap_option);
proto_tree_add_item(subtree, hf_coap_opt_delta, tvb, offset, 1, ENC_BIG_ENDIAN);
tvb_lenbuf = tvb_new_subset(tvb, offset, opt_hlen, opt_hlen);
proto_tree_add_uint_bits_format_value(subtree, hf_coap_opt_length, tvb_lenbuf, 4, opt_hlen == 1 ? 4 : 12, opt_length, "%d", opt_length);
offset += opt_hlen;
switch (*opt_code) {
case COAP_OPT_CONTENT_TYPE:
dissect_coap_opt_ctype(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_ctype);
break;
case COAP_OPT_MAX_AGE:
dissect_coap_opt_time(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_max_age);
break;
case COAP_OPT_PROXY_URI:
dissect_coap_opt_string(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_proxy_uri, COAP_OPT_PROXY_URI);
break;
case COAP_OPT_ETAG:
dissect_coap_opt_string(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_etag, COAP_OPT_ETAG);
break;
case COAP_OPT_URI_HOST:
dissect_coap_opt_string(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_uri_host, COAP_OPT_URI_HOST);
break;
case COAP_OPT_LOCATION_PATH:
dissect_coap_opt_string(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_location_path, COAP_OPT_LOCATION_PATH);
break;
case COAP_OPT_URI_PORT:
dissect_coap_opt_port(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_uri_port);
break;
case COAP_OPT_LOCATION_QUERY:
dissect_coap_opt_string(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_location_query, COAP_OPT_LOCATION_QUERY);
break;
case COAP_OPT_URI_PATH:
dissect_coap_opt_string(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_uri_path, COAP_OPT_URI_PATH);
break;
case COAP_OPT_OBSERVE:
dissect_coap_opt_time(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_observe);
break;
case COAP_OPT_TOKEN:
dissect_coap_opt_string(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_token, COAP_OPT_TOKEN);
break;
case COAP_OPT_ACCEPT:
dissect_coap_opt_ctype(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_accept);
break;
case COAP_OPT_IF_MATCH:
dissect_coap_opt_string(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_if_match, COAP_OPT_IF_MATCH);
break;
case COAP_OPT_URI_QUERY:
dissect_coap_opt_string(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_uri_query, COAP_OPT_URI_QUERY);
break;
case COAP_OPT_BLOCK2:
dissect_coap_opt_block(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_block_mflag);
break;
case COAP_OPT_BLOCK1:
dissect_coap_opt_block(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_block_mflag);
break;
case COAP_OPT_IF_NONE_MATCH:
dissect_coap_opt_string(tvb, pinfo, subtree, offset, opt_length, hf_coap_opt_if_none_match, COAP_OPT_IF_NONE_MATCH);
break;
default:
break;
}
return offset + opt_length;
}
static void
dissect_coap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
guint offset = 0;
proto_item *coap_root = NULL;
proto_tree *coap_tree = NULL;
guint8 ttype = 0;
guint8 opt_count = 0;
guint8 code = 0;
guint16 tid = 0;
guint coap_length = 0;
guint8 opt_code = 0;
int i;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "COAP");
col_clear(pinfo->cinfo, COL_INFO);
if (!parent_tree)
return;
coap_length = tvb_reported_length(tvb);
coap_content_type = NULL;
coap_content_type_value = ~0;
coap_root = proto_tree_add_item(parent_tree, proto_coap, tvb, offset, -1, ENC_NA);
coap_tree = proto_item_add_subtree(coap_root, ett_coap);
proto_tree_add_item(coap_tree, hf_coap_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(coap_tree, hf_coap_ttype, tvb, offset, 1, ENC_BIG_ENDIAN);
ttype = (tvb_get_guint8(tvb, offset) & 0x30) >> 4;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(ttype, vals_ttype, "Unknown %d"));
proto_tree_add_item(coap_tree, hf_coap_opt_count, tvb, offset, 1, ENC_BIG_ENDIAN);
opt_count = tvb_get_guint8(tvb, offset) & 0x0f;
offset += 1;
proto_tree_add_item(coap_tree, hf_coap_code, tvb, offset, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str(code, vals_code, "Unknown %d"));
offset += 1;
proto_tree_add_item(coap_tree, hf_coap_tid, tvb, offset, 2, ENC_BIG_ENDIAN);
tid = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_item_append_text(coap_tree, ", TID: %u, Length: %u", tid, coap_length);
block_number = ~0;
block_mflag = 0;
uri_string[0] = 0;
for (i = 1; i <= opt_count; i++) {
offset = dissect_coap_options(tvb, pinfo, coap_tree, offset, i, &opt_code);
if (coap_length < offset) {
proto_tree_add_text(coap_tree, tvb, 0, 0, "Invalid length: coap_length(%d) < offset(%d)", coap_length, offset);
return;
}
}
if (block_number != ~0) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %sBlock #%d", block_mflag ? "" : "End of ", block_number);
}
if (uri_string[0] != '\0') {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", uri_string);
}
if (coap_length > offset) {
proto_tree *payload_tree = NULL;
proto_item *payload_item = NULL;
tvbuff_t *payload_tvb;
guint payload_length = coap_length - offset;
const char *ctype_str_default = "";
if (coap_content_type_value == ~0) {
coap_content_type = "text/plain";
ctype_str_default = " (default)";
}
payload_item = proto_tree_add_text(coap_tree, tvb, offset, -1, "Payload Content-Type: %s%s, Length: %u, offset: %u",
coap_content_type, ctype_str_default, payload_length, offset);
payload_tree = proto_item_add_subtree(payload_item, ett_coap_payload);
payload_tvb = tvb_new_subset(tvb, offset, payload_length, payload_length);
dissector_try_string(media_type_dissector_table, coap_content_type, payload_tvb, pinfo, payload_tree);
}
}
void
proto_register_coap(void)
{
static hf_register_info hf[] = {
{ &hf_coap_version, { "Version", "coap.version", FT_UINT8, BASE_DEC, NULL, 0xc0, "COAP Version", HFILL }},
{ &hf_coap_ttype, { "Type", "coap.type", FT_UINT8, BASE_DEC, VALS(vals_ttype), 0x30, "COAP Transaction Type", HFILL }},
{ &hf_coap_opt_count, { "Option Count", "coap.optcount", FT_UINT8, BASE_DEC, NULL, 0x0f, "COAP Option Count", HFILL }},
{ &hf_coap_code, { "Code", "coap.code", FT_UINT8, BASE_DEC, VALS(vals_code), 0x0, "COAP Method or Response Code", HFILL }},
{ &hf_coap_tid, { "Transaction ID", "coap.tid", FT_UINT16, BASE_DEC, NULL, 0x0, "COAP Transaction ID", HFILL }},
{ &hf_coap_opt_delta, { "Delta", "coap.opt.delta", FT_UINT8, BASE_DEC, NULL, 0xf0, "COAP Option Delta", HFILL }},
{ &hf_coap_opt_length, { "Length", "coap.opt.length", FT_UINT16, BASE_DEC, NULL, 0x0, "COAP Option Length", HFILL }},
{ &hf_coap_opt_ctype, { "Content-type", "coap.opt.ctype", FT_UINT8, BASE_DEC, VALS(vals_ctype), 0x0, "COAP Content Type", HFILL }},
{ &hf_coap_opt_max_age, { "Max-age", "coap.opt.max_age", FT_UINT32, BASE_DEC, NULL, 0x0, "COAP Max-age", HFILL }},
{ &hf_coap_opt_proxy_uri, { "Proxy-Uri", "coap.opt.proxy_uri", FT_STRING, BASE_NONE, NULL, 0x0, "COAP Proxy-Uri", HFILL }},
{ &hf_coap_opt_etag, { "Etag", "coap.opt.etag", FT_BYTES, BASE_NONE, NULL, 0x0, "COAP Etag", HFILL }},
{ &hf_coap_opt_uri_host, { "Uri-Host", "coap.opt.uri_host", FT_STRING, BASE_NONE, NULL, 0x0, "COAP Uri-Host", HFILL }},
{ &hf_coap_opt_location_path, { "Location-Path", "coap.opt.location_path", FT_STRING, BASE_NONE, NULL, 0x0, "COAP URI Path", HFILL }},
{ &hf_coap_opt_uri_port, { "Uri-Port", "coap.opt.uri_port", FT_UINT16, BASE_DEC, NULL, 0x0, "COAP Uri-Port", HFILL }},
{ &hf_coap_opt_location_query, { "Location-Query", "coap.opt.location_query", FT_STRING, BASE_NONE, NULL, 0x0, "COAP URI Query", HFILL }},
{ &hf_coap_opt_uri_path, { "Uri-Path", "coap.opt.uri_path", FT_STRING, BASE_NONE, NULL, 0x0, "COAP Uri-Path", HFILL }},
{ &hf_coap_opt_observe, { "Lifetime", "coap.opt.subscr_lifetime", FT_INT32, BASE_DEC, NULL, 0x0, "COAP Observe", HFILL }},
{ &hf_coap_opt_token, { "Token", "coap.opt.token", FT_BYTES, BASE_NONE, NULL, 0x0, "COAP Token", HFILL }},
{ &hf_coap_opt_accept, { "Accept", "coap.opt.accept", FT_UINT8, BASE_DEC, VALS(vals_ctype), 0x0, "COAP Acceptable Content Type", HFILL }},
{ &hf_coap_opt_if_match, { "If-Match", "coap.opt.if_match", FT_BYTES, BASE_NONE, NULL, 0x0, "COAP If-Match", HFILL }},
{ &hf_coap_opt_block_number, { "Block Number", "coap.opt.block_number", FT_INT32, BASE_DEC, NULL, 0x0, "COAP Block Number", HFILL }},
{ &hf_coap_opt_block_mflag, { "More Flag", "coap.opt.block_mflag", FT_UINT8, BASE_DEC, NULL, 0x08, "COAP Block More Size", HFILL }},
{ &hf_coap_opt_block_size, { "Encoded Block Size", "coap.opt.block_size", FT_UINT8, BASE_DEC, NULL, 0x07, "COAP Encoded Block Size", HFILL }},
{ &hf_coap_opt_uri_query, { "Uri-Query", "coap.opt.uri_query", FT_STRING, BASE_NONE, NULL, 0x0, "COAP Uri-Query", HFILL }},
{ &hf_coap_opt_if_none_match, { "If-None-Match", "coap.opt.if_none_match", FT_BYTES, BASE_NONE, NULL, 0x0, "COAP If-None-Match", HFILL }},
};
static gint *ett[] = {
&ett_coap,
&ett_coap_option,
&ett_coap_payload,
};
module_t *coap_module;
proto_coap = proto_register_protocol("Constrained Application Protocol", "COAP", "coap");
proto_register_field_array(proto_coap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("coap", dissect_coap, proto_coap);
coap_module = prefs_register_protocol (proto_coap, proto_reg_handoff_coap);
prefs_register_uint_preference (coap_module, "udp_port",
"COAP port number",
"Port number used for COAP traffic",
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
