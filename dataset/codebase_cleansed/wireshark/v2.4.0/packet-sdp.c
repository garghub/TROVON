static void sdp_dump_transport_media(const transport_media_pt_t* media) {
int i;
int count;
DPRINT2(("transport_media contents:"));
DINDENT();
if (!media) {
DPRINT2(("null transport_media_pt_t*"));
DENDENT();
return;
}
count = (int)media->pt_count;
DPRINT2(("pt_count=%d",count));
DINDENT();
for (i=0; i < count; i++) {
DPRINT2(("pt=%d", media->pt[i]));
}
DENDENT();
DPRINT2(("rtp_dyn_payload hashtable=%s", media->rtp_dyn_payload ? "YES" : "NO"));
if (media->rtp_dyn_payload) {
rtp_dump_dyn_payload(media->rtp_dyn_payload);
}
DPRINT2(("set_rtp=%s", media->set_rtp ? "TRUE" : "FALSE"));
DENDENT();
}
static void sdp_dump_transport_info(const transport_info_t* info) {
int i;
int count;
DPRINT2(("transport_info contents:"));
DINDENT();
if (!info) {
DPRINT2(("null transport_info_t*"));
DENDENT();
return;
}
DPRINT2(("sdp_status=%s",
val_to_str(info->sdp_status, sdp_exchange_type_vs, "SDP_EXCHANGE_UNKNOWN")));
DPRINT2(("payload type contents:"));
DINDENT();
for (i=0; i < SDP_NO_OF_PT; i++) {
if (info->encoding_name[i] &&
strcmp(UNKNOWN_ENCODING,info->encoding_name[i]) != 0) {
DPRINT2(("payload type #%d:",i));
DINDENT();
DPRINT2(("encoding_name=%s", info->encoding_name[i]));
DPRINT2(("sample_rate=%d", info->sample_rate[i]));
DENDENT();
}
}
DENDENT();
count = wmem_array_get_count(info->media_descriptions);
DPRINT2(("media_count=%d", count));
DPRINT2(("rtp channels:"));
DINDENT();
for (i=0; i < count; i++) {
media_description_t *media_desc = (media_description_t *)wmem_array_index(info->media_descriptions, i);
DPRINT2(("channel #%d:",i));
DINDENT();
DPRINT2(("conn_addr=%s",
address_to_str(wmem_packet_scope(), &(media_desc->conn_addr))));
DPRINT2(("media_port=%d", media_desc->media_port));
DPRINT2(("proto=%d", media_desc->proto));
sdp_dump_transport_media(&(media_desc->media));
DENDENT();
}
DENDENT();
DPRINT2(("encryption_algorithm=%u", info->encryption_algorithm));
DPRINT2(("auth_algorithm=%u", info->auth_algorithm));
if (info->encryption_algorithm || info->auth_algorithm) {
DPRINT2(("mki_len=%u", info->mki_len));
if (info->auth_algorithm) {
DPRINT2(("auth_tag_len=%u", info->auth_tag_len));
}
}
DENDENT();
}
static inline gint
find_next_optional_token_in_line(tvbuff_t *tvb, proto_tree *tree,
gint *offset, gint *next_offset,
const gboolean optional)
{
gint tokenlen = 0;
gint next_off = -1;
gint off = *offset;
if (tvb_offset_exists(tvb, off)) {
while (tokenlen == 0) {
next_off = tvb_find_guint8(tvb, off, -1, ' ');
if (next_off == -1) {
tokenlen = tvb_captured_length_remaining(tvb, off);
break;
}
tokenlen = next_off - off;
if (tokenlen == 0) {
proto_tree_add_expert(tree, NULL, &ei_sdp_invalid_line_space, tvb, off-1, 2);
off = next_off + 1;
}
}
}
if (!optional && tokenlen == 0) {
proto_tree_add_expert(tree, NULL, &ei_sdp_invalid_line_fields, tvb, 0, -1);
}
*next_offset = next_off;
*offset = off;
return tokenlen;
}
static inline gint
find_next_token_in_line(tvbuff_t *tvb, proto_tree *tree, gint *offset, gint *next_offset)
{
return find_next_optional_token_in_line(tvb, tree, offset, next_offset, FALSE);
}
static transport_proto_t
parse_sdp_media_protocol(const char *media_proto)
{
const struct {
const char *proto_name;
transport_proto_t proto;
} protocols[] = {
{ "RTP/AVP", SDP_PROTO_RTP },
{ "udptl", SDP_PROTO_T38 },
{ "UDPTL", SDP_PROTO_T38 },
{ "RTP/AVPF", SDP_PROTO_RTP },
{ "RTP/SAVP", SDP_PROTO_SRTP },
{ "RTP/SAVPF", SDP_PROTO_SRTP },
{ "UDP/TLS/RTP/SAVP", SDP_PROTO_SRTP },
{ "UDP/TLS/RTP/SAVPF", SDP_PROTO_SRTP },
{ "msrp/tcp", SDP_PROTO_MSRP },
{ "UDPSPRT", SDP_PROTO_SPRT },
{ "udpsprt", SDP_PROTO_SPRT },
};
for (guint i = 0; i < G_N_ELEMENTS(protocols); i++) {
if (!strcmp(protocols[i].proto_name, media_proto)) {
return protocols[i].proto;
}
}
return SDP_PROTO_UNKNOWN;
}
static void
parse_sdp_connection_address(const char *connection_type, const char *connection_address,
wmem_allocator_t *allocator, address *conn_addr)
{
if (strcmp(connection_type, "IP4") == 0) {
guint32 ip4_addr;
if (str_to_ip(connection_address, &ip4_addr)) {
alloc_address_wmem(allocator, conn_addr, AT_IPv4, 4, &ip4_addr);
}
} else if (strcmp(connection_type, "IP6") == 0) {
struct e_in6_addr ip6_addr;
if (str_to_ip6(connection_address, &ip6_addr)) {
alloc_address_wmem(allocator, conn_addr, AT_IPv6, 16, &ip6_addr);
}
}
}
static media_description_t *
sdp_new_media_description(wmem_array_t *media_descriptions, session_info_t *session_info)
{
media_description_t empty_desc;
media_description_t *media_desc;
if (wmem_array_get_count(media_descriptions) >= SDP_MAX_RTP_CHANNELS) {
DPRINT(("Too many media descriptions (more than %d), returning NULL!",
wmem_array_get_count(media_descriptions)));
return NULL;
}
memset(&empty_desc, 0, sizeof(media_description_t));
wmem_array_append_one(media_descriptions, empty_desc);
media_desc = (media_description_t *) wmem_array_index(media_descriptions,
wmem_array_get_count(media_descriptions) - 1);
if (session_info->conn_addr.type != AT_NONE) {
copy_address_wmem(wmem_file_scope(), &media_desc->conn_addr, &session_info->conn_addr);
}
media_desc->media.rtp_dyn_payload =
rtp_dyn_payload_dup(session_info->rtp_dyn_payload);
return media_desc;
}
static void
clean_unused_media_descriptions(wmem_array_t *descs)
{
for (guint i = 0; i < wmem_array_get_count(descs); i++) {
media_description_t *media_desc = (media_description_t *)wmem_array_index(descs, i);
if (!media_desc->media.set_rtp) {
rtp_dyn_payload_free(media_desc->media.rtp_dyn_payload);
media_desc->media.rtp_dyn_payload = NULL;
}
}
}
static void
dissect_sdp_owner(tvbuff_t *tvb, proto_item *ti) {
proto_tree *sdp_owner_tree;
gint offset, next_offset, tokenlen;
offset = 0;
sdp_owner_tree = proto_item_add_subtree(ti, ett_sdp_owner);
tokenlen = find_next_token_in_line(tvb, sdp_owner_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_owner_tree, hf_owner_username, tvb, offset, tokenlen,
ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, sdp_owner_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_owner_tree, hf_owner_sessionid, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, sdp_owner_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_owner_tree, hf_owner_version, tvb, offset, tokenlen,
ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, sdp_owner_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_owner_tree, hf_owner_network_type, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, sdp_owner_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_owner_tree, hf_owner_address_type, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
proto_tree_add_item(sdp_owner_tree, hf_owner_address, tvb, offset, -1, ENC_UTF_8|ENC_NA);
}
static void
dissect_sdp_connection_info(tvbuff_t *tvb, proto_item* ti, session_info_t *session_info, media_description_t *media_desc)
{
proto_tree *sdp_connection_info_tree;
gint offset, next_offset, tokenlen;
const guint8 *connection_type, *connection_address;
offset = 0;
sdp_connection_info_tree = proto_item_add_subtree(ti,
ett_sdp_connection_info);
tokenlen = find_next_token_in_line(tvb, sdp_connection_info_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_connection_info_tree,
hf_connection_info_network_type, tvb, offset, tokenlen,
ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, sdp_connection_info_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item_ret_string(sdp_connection_info_tree,
hf_connection_info_address_type, tvb, offset, tokenlen,
ENC_UTF_8|ENC_NA, wmem_packet_scope(), &connection_type);
DPRINT(("parsed connection line type=%s", connection_type));
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, '/');
if (next_offset == -1) {
tokenlen = -1;
connection_address =
(char*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tvb_captured_length_remaining(tvb, offset), ENC_UTF_8|ENC_NA);
} else {
tokenlen = next_offset - offset;
connection_address = (char*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
}
DPRINT(("parsed connection line address=%s", connection_address));
if (session_info) {
parse_sdp_connection_address(connection_type, connection_address,
wmem_packet_scope(),
&session_info->conn_addr);
} else if (media_desc) {
free_address_wmem(wmem_file_scope(), &media_desc->conn_addr);
parse_sdp_connection_address(connection_type, connection_address,
wmem_file_scope(),
&media_desc->conn_addr);
}
proto_tree_add_item(sdp_connection_info_tree,
hf_connection_info_connection_address, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
if (next_offset != -1) {
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, '/');
if (next_offset == -1) {
tokenlen = -1;
} else {
tokenlen = next_offset - offset;
}
proto_tree_add_item(sdp_connection_info_tree,
hf_connection_info_ttl, tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
if (next_offset != -1) {
offset = next_offset + 1;
proto_tree_add_item(sdp_connection_info_tree,
hf_connection_info_num_addr, tvb, offset, -1, ENC_UTF_8|ENC_NA);
}
}
}
static void
dissect_sdp_bandwidth(tvbuff_t *tvb, proto_item *ti) {
proto_tree *sdp_bandwidth_tree;
gint offset, next_offset, tokenlen;
proto_item *item;
gboolean unit_is_kbs = FALSE;
gboolean unit_is_bps = FALSE;
offset = 0;
sdp_bandwidth_tree = proto_item_add_subtree(ti, ett_sdp_bandwidth);
next_offset = tvb_find_guint8(tvb, offset, -1, ':');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
item = proto_tree_add_item(sdp_bandwidth_tree, hf_bandwidth_modifier, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
if (tvb_strneql(tvb, offset, "CT", 2) == 0) {
proto_item_append_text(item, " [Conference Total(total bandwidth of all RTP sessions)]");
unit_is_kbs = TRUE;
} else if (tvb_strneql(tvb, offset, "AS", 2) == 0) {
proto_item_append_text(item, " [Application Specific (RTP session bandwidth)]");
unit_is_kbs = TRUE;
} else if (tvb_strneql(tvb, offset, "TIAS", 4) == 0) {
proto_item_append_text(item, " [Transport Independent Application Specific maximum]");
unit_is_bps = TRUE;
}
offset = next_offset + 1;
item = proto_tree_add_item(sdp_bandwidth_tree, hf_bandwidth_value, tvb, offset, -1,
ENC_UTF_8|ENC_NA);
if (unit_is_kbs == TRUE)
proto_item_append_text(item, " kb/s");
if (unit_is_bps == TRUE)
proto_item_append_text(item, " b/s");
}
static void dissect_sdp_time(tvbuff_t *tvb, proto_item* ti) {
proto_tree *sdp_time_tree;
gint offset, next_offset, tokenlen;
offset = 0;
sdp_time_tree = proto_item_add_subtree(ti, ett_sdp_time);
tokenlen = find_next_token_in_line(tvb, sdp_time_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_time_tree, hf_time_start, tvb, offset, tokenlen,
ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
proto_tree_add_item(sdp_time_tree, hf_time_stop, tvb, offset, -1, ENC_UTF_8|ENC_NA);
}
static void dissect_sdp_repeat_time(tvbuff_t *tvb, proto_item* ti) {
proto_tree *sdp_repeat_time_tree;
gint offset, next_offset, tokenlen;
gboolean optional = FALSE;
offset = 0;
sdp_repeat_time_tree = proto_item_add_subtree(ti, ett_sdp_time);
tokenlen = find_next_token_in_line(tvb, sdp_repeat_time_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_repeat_time_tree, hf_repeat_time_interval, tvb,
offset, tokenlen, ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, sdp_repeat_time_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_repeat_time_tree, hf_repeat_time_duration, tvb,
offset, tokenlen, ENC_UTF_8|ENC_NA);
do {
offset = next_offset +1;
tokenlen = find_next_optional_token_in_line(tvb, sdp_repeat_time_tree,
&offset, &next_offset, optional);
if (tokenlen == 0)
break;
proto_tree_add_item(sdp_repeat_time_tree, hf_repeat_time_offset,
tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
optional = TRUE;
} while (next_offset != -1);
}
static void
dissect_sdp_timezone(tvbuff_t *tvb, proto_item* ti) {
proto_tree* sdp_timezone_tree;
gint offset, next_offset, tokenlen;
gboolean optional = FALSE;
offset = 0;
sdp_timezone_tree = proto_item_add_subtree(ti, ett_sdp_timezone);
do {
tokenlen = find_next_optional_token_in_line(tvb, sdp_timezone_tree,
&offset, &next_offset, optional);
if (tokenlen == 0)
break;
proto_tree_add_item(sdp_timezone_tree, hf_timezone_time, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_optional_token_in_line(tvb, sdp_timezone_tree,
&offset, &next_offset, optional);
if (tokenlen == 0)
break;
proto_tree_add_item(sdp_timezone_tree, hf_timezone_offset, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
optional = TRUE;
} while (next_offset != -1);
}
static void dissect_sdp_encryption_key(tvbuff_t *tvb, proto_item * ti) {
proto_tree *sdp_encryption_key_tree;
gint offset, next_offset, tokenlen;
offset = 0;
sdp_encryption_key_tree = proto_item_add_subtree(ti, ett_sdp_encryption_key);
next_offset = tvb_find_guint8(tvb, offset, -1, ':');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_encryption_key_tree, hf_encryption_key_type,
tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
proto_tree_add_item(sdp_encryption_key_tree, hf_encryption_key_data,
tvb, offset, -1, ENC_UTF_8|ENC_NA);
}
static void dissect_key_mgmt(tvbuff_t *tvb, packet_info * pinfo, proto_item * ti) {
gchar *data_p = NULL;
const guint8 *prtcl_id = NULL;
gint len;
tvbuff_t *keymgmt_tvb;
int found_match = 0;
proto_tree *key_tree;
gint next_offset;
gint offset = 0;
gint tokenlen;
key_tree = proto_item_add_subtree(ti, ett_sdp_key_mgmt);
tokenlen = find_next_token_in_line(tvb, key_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item_ret_string(key_tree, hf_key_mgmt_prtcl_id, tvb, offset, tokenlen, ENC_UTF_8|ENC_NA, wmem_packet_scope(), &prtcl_id);
offset = next_offset + 1;
len = tvb_captured_length_remaining(tvb, offset);
if (len < 0)
return;
data_p = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_UTF_8|ENC_NA);
keymgmt_tvb = base64_to_tvb(tvb, data_p);
add_new_data_source(pinfo, keymgmt_tvb, "Key Management Data");
if ((prtcl_id != NULL) && (key_mgmt_dissector_table != NULL)) {
found_match = dissector_try_string(key_mgmt_dissector_table,
prtcl_id,
keymgmt_tvb, pinfo,
key_tree, NULL);
}
if (found_match) {
proto_item *ti2 = proto_tree_add_item(key_tree, hf_key_mgmt_data,
keymgmt_tvb, 0, -1, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti2);
} else {
proto_tree_add_item(key_tree, hf_key_mgmt_data,
keymgmt_tvb, 0, -1, ENC_NA);
}
}
static void dissect_sdp_session_attribute(tvbuff_t *tvb, packet_info * pinfo, proto_item * ti) {
proto_tree *sdp_session_attribute_tree;
gint offset, next_offset, tokenlen;
const guint8 *field_name;
offset = 0;
sdp_session_attribute_tree = proto_item_add_subtree(ti,
ett_sdp_session_attribute);
next_offset = tvb_find_guint8(tvb, offset, -1, ':');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item_ret_string(sdp_session_attribute_tree, hf_session_attribute_field,
tvb, offset, tokenlen, ENC_UTF_8|ENC_NA, wmem_packet_scope(), &field_name);
offset = next_offset + 1;
if (strcmp((const char *)field_name, "ipbcp") == 0) {
offset = tvb_ws_mempbrk_pattern_guint8(tvb, offset, -1,&pbrk_digits, NULL);
if (offset == -1)
return;
tokenlen = find_next_token_in_line(tvb, sdp_session_attribute_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_session_attribute_tree, hf_ipbcp_version, tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
offset = tvb_ws_mempbrk_pattern_guint8(tvb, offset, -1,&pbrk_alpha, NULL);
if (offset == -1)
return;
tokenlen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (tokenlen == -1)
return;
proto_tree_add_item(sdp_session_attribute_tree, hf_ipbcp_type, tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
} else if (strcmp((const char *)field_name, "key-mgmt") == 0) {
tvbuff_t *key_tvb;
proto_item *key_ti;
key_tvb = tvb_new_subset_remaining(tvb, offset);
key_ti = proto_tree_add_item(sdp_session_attribute_tree, hf_key_mgmt_att_value, key_tvb, 0, -1, ENC_UTF_8|ENC_NA);
dissect_key_mgmt(key_tvb, pinfo, key_ti);
} else {
proto_tree_add_item(sdp_session_attribute_tree, hf_session_attribute_value,
tvb, offset, -1, ENC_UTF_8|ENC_NA);
}
}
static void
dissect_sdp_media(tvbuff_t *tvb, packet_info* pinfo, proto_item *ti,
media_description_t *media_desc) {
proto_tree *sdp_media_tree;
gint offset, next_offset, tokenlen, idx;
guint8 *media_format;
gboolean optional = FALSE;
proto_item *it;
const guint8 *media_type_str;
const guint8 *media_port_str;
const guint8 *media_proto_str;
transport_proto_t transport_proto;
guint16 media_port;
gboolean media_port_valid;
proto_item *pi;
offset = 0;
sdp_media_tree = proto_item_add_subtree(ti, ett_sdp_media);
tokenlen = find_next_token_in_line(tvb, sdp_media_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item_ret_string(sdp_media_tree, hf_media_media, tvb, offset, tokenlen,
ENC_UTF_8|ENC_NA, wmem_packet_scope(), &media_type_str);
if (media_desc) {
media_desc->is_video = strcmp(media_type_str, "video") == 0;
}
DPRINT(("parsed media_type=%s", media_type_str));
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, sdp_media_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
next_offset = tvb_find_guint8(tvb, offset, tokenlen, '/');
if (next_offset != -1) {
tokenlen = next_offset - offset;
it = proto_tree_add_item_ret_string(sdp_media_tree, hf_media_port_string, tvb, offset, tokenlen,
ENC_UTF_8|ENC_NA, wmem_packet_scope(), &media_port_str);
DPRINT(("parsed media_port=%s", media_port_str));
if (g_ascii_isdigit(media_port_str[0])) {
PROTO_ITEM_SET_HIDDEN(it);
media_port_valid = ws_strtou16(media_port_str, NULL, &media_port);
pi = proto_tree_add_uint(sdp_media_tree, hf_media_port, tvb, offset, tokenlen,
media_port);
if (!media_port_valid)
expert_add_info(pinfo, pi, &ei_sdp_invalid_media_port);
if (media_desc) {
media_desc->media_port = media_port;
}
}
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, sdp_media_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(sdp_media_tree, hf_media_portcount, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
} else {
tokenlen = find_next_token_in_line(tvb, sdp_media_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
it = proto_tree_add_item_ret_string(sdp_media_tree, hf_media_port_string, tvb, offset, tokenlen,
ENC_UTF_8|ENC_NA, wmem_packet_scope(), &media_port_str);
DPRINT(("parsed media_port=%s", media_port_str));
if (g_ascii_isdigit(media_port_str[0])) {
PROTO_ITEM_SET_HIDDEN(it);
media_port_valid = ws_strtou16(media_port_str, NULL, &media_port);
pi = proto_tree_add_uint(sdp_media_tree, hf_media_port, tvb, offset, tokenlen,
media_port);
if (!media_port_valid)
expert_add_info(pinfo, pi, &ei_sdp_invalid_media_port);
if (media_desc) {
media_desc->media_port = media_port;
}
}
offset = next_offset + 1;
}
tokenlen = find_next_token_in_line(tvb, sdp_media_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item_ret_string(sdp_media_tree, hf_media_proto, tvb, offset, tokenlen,
ENC_UTF_8|ENC_NA, wmem_packet_scope(), &media_proto_str);
DPRINT(("parsed media_proto=%s", media_proto_str));
transport_proto = parse_sdp_media_protocol(media_proto_str);
if (media_desc) {
media_desc->proto = transport_proto;
}
do {
offset = next_offset + 1;
tokenlen = find_next_optional_token_in_line(tvb, sdp_media_tree,
&offset, &next_offset, optional);
if (tokenlen == 0)
break;
if (transport_proto == SDP_PROTO_RTP || transport_proto == SDP_PROTO_SRTP) {
media_format = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
if (g_ascii_isdigit(media_format[0])) {
proto_tree_add_string(sdp_media_tree, hf_media_format, tvb, offset,
tokenlen, val_to_str_ext((guint32)strtoul((char*)media_format, NULL, 10), &rtp_payload_type_vals_ext, "%u"));
if (media_desc) {
idx = media_desc->media.pt_count;
media_desc->media.pt[idx] = (gint32)strtol((char*)media_format, NULL, 10);
DPRINT(("parsed media codec pt=%d", media_desc->media.pt[idx]));
if (idx < (SDP_MAX_RTP_PAYLOAD_TYPES-1))
media_desc->media.pt_count++;
}
} else {
proto_tree_add_item(sdp_media_tree, hf_media_format, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
}
} else {
proto_tree_add_item(sdp_media_tree, hf_media_format, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
}
optional = TRUE;
} while (next_offset != -1);
}
static tvbuff_t *
ascii_bytes_to_tvb(tvbuff_t *tvb, packet_info *pinfo, gint len, gchar *msg)
{
guint8 *buf = (guint8 *)wmem_alloc(pinfo->pool, 10240);
if (len < 20480) {
int i;
tvbuff_t *bytes_tvb;
while (1) {
if ((*msg == 0) || (*msg == '\n')) {
return NULL;
}
if (*msg == '=') {
msg++;
break;
}
msg++;
}
while (1) {
if ((*msg == 0) || (*msg == '\n')) {
return NULL;
}
if ( ((*msg >= '0') && (*msg <= '9'))
|| ((*msg >= 'a') && (*msg <= 'f'))
|| ((*msg >= 'A') && (*msg <= 'F'))) {
break;
}
msg++;
}
i = 0;
while (((*msg >= '0') && (*msg <= '9'))
|| ((*msg >= 'a') && (*msg <= 'f'))
|| ((*msg >= 'A') && (*msg <= 'F'))) {
int val;
if ((*msg >= '0') && (*msg <= '9')) {
val = (*msg)-'0';
} else if ((*msg >= 'a') && (*msg <= 'f')) {
val = (*msg)-'a'+10;
} else if ((*msg >= 'A') && (*msg <= 'F')) {
val = (*msg)-'A'+10;
} else {
return NULL;
}
val <<= 4;
msg++;
if ((*msg >= '0') && (*msg <= '9')) {
val |= (*msg)-'0';
} else if ((*msg >= 'a') && (*msg <= 'f')) {
val |= (*msg)-'a'+10;
} else if ((*msg >= 'A') && (*msg <= 'F')) {
val |= (*msg)-'A'+10;
} else {
return NULL;
}
msg++;
buf[i] = (guint8)val;
i++;
}
if (i == 0) {
return NULL;
}
bytes_tvb = tvb_new_child_real_data(tvb, buf, i, i);
add_new_data_source(pinfo, bytes_tvb, "ASCII bytes to tvb");
return bytes_tvb;
}
return NULL;
}
static void
decode_sdp_fmtp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, gint tokenlen, char *mime_type) {
gint next_offset;
gint end_offset;
guint8 *field_name;
gchar *format_specific_parameter;
proto_item *item;
tvbuff_t * volatile data_tvb;
end_offset = offset + tokenlen;
#if 0
proto_tree_add_debug(tree, tvb, offset, tokenlen, "Debug; Analysed string: '%s'",
tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_ASCII));
#endif
next_offset = tvb_find_guint8(tvb, offset, -1, '=');
if (next_offset == -1)
{
return;
}
tokenlen = next_offset - offset;
field_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
#if 0
proto_tree_add_debug(tree, tvb, offset, tokenlen, "Debug; MIMEtype '%s'Parameter name: '%s'", mime_type, field_name); */
#endif
offset = next_offset;
if ((mime_type != NULL) && (g_ascii_strcasecmp(mime_type, "MP4V-ES") == 0)) {
if (strcmp((char*)field_name, "profile-level-id") == 0) {
offset++;
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
item = proto_tree_add_uint(tree, hf_sdp_fmtp_mpeg4_profile_level_id, tvb, offset, tokenlen,
(guint32)strtol((char*)format_specific_parameter, NULL, 10));
PROTO_ITEM_SET_GENERATED(item);
} else if (strcmp((char*)field_name, "config") == 0) {
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
data_tvb = ascii_bytes_to_tvb(tvb, pinfo, tokenlen, format_specific_parameter);
if (mp4ves_config_handle && data_tvb) {
call_dissector(mp4ves_config_handle, data_tvb, pinfo, tree);
}
}
}
if (((mime_type != NULL) && (g_ascii_strcasecmp(mime_type, "H263-2000") == 0)) ||
((mime_type != NULL) && (g_ascii_strcasecmp(mime_type, "H263-1998") == 0))) {
if (strcmp((char*)field_name, "profile") == 0) {
offset++;
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
item = proto_tree_add_uint(tree, hf_sdp_fmtp_h263_profile, tvb, offset, tokenlen,
(guint32)strtol((char*)format_specific_parameter, NULL, 10));
PROTO_ITEM_SET_GENERATED(item);
} else if (strcmp((char*)field_name, "level") == 0) {
offset++;
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
item = proto_tree_add_uint(tree, hf_sdp_fmtp_h263_level, tvb, offset, tokenlen,
(guint32)strtol((char*)format_specific_parameter, NULL, 10));
PROTO_ITEM_SET_GENERATED(item);
}
}
if ((mime_type != NULL) && ((g_ascii_strcasecmp(mime_type, "H264") == 0) || (g_ascii_strcasecmp(mime_type, "H264-SVC") == 0))) {
if (strcmp(field_name, "profile-level-id") == 0) {
int length = 0;
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
data_tvb = ascii_bytes_to_tvb(tvb, pinfo, tokenlen, format_specific_parameter);
if (!data_tvb) {
proto_tree_add_expert_format(tree, pinfo, &ei_sdp_invalid_conversion, tvb, offset, tokenlen, "Could not convert '%s' to 3 bytes", format_specific_parameter);
return;
}
length = tvb_reported_length(data_tvb);
if (length == 3) {
if (h264_handle && data_tvb) {
dissect_h264_profile(data_tvb, pinfo, tree);
}
} else {
item = proto_tree_add_expert_format(tree, pinfo, &ei_sdp_invalid_conversion, tvb, offset, tokenlen, "Incorrectly coded, must be three bytes");
PROTO_ITEM_SET_GENERATED(item);
}
} else if (strcmp(field_name, "packetization-mode") == 0) {
offset++;
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
item = proto_tree_add_uint(tree, hf_sdp_h264_packetization_mode, tvb, offset, tokenlen,
(guint32)strtol((char*)format_specific_parameter, NULL, 10));
PROTO_ITEM_SET_GENERATED(item);
} else if (strcmp(field_name, "sprop-parameter-sets") == 0) {
const guint8 *data_p = NULL;
gint comma_offset;
offset++;
comma_offset = tvb_find_guint8(tvb, offset, -1, ',');
if (comma_offset != -1) {
tokenlen = comma_offset - offset;
} else {
tokenlen = end_offset - offset;
}
proto_tree_add_item_ret_string(tree, hf_sdp_nal_unit_1_string, tvb, offset, tokenlen, ENC_UTF_8|ENC_NA, wmem_packet_scope(), &data_p);
data_tvb = base64_to_tvb(tvb, data_p);
add_new_data_source(pinfo, data_tvb, "h264 prop-parameter-sets");
if (h264_handle && data_tvb) {
TRY {
dissect_h264_nal_unit(data_tvb, pinfo, tree);
}
CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
if (comma_offset != -1) {
offset = comma_offset +1;
tokenlen = end_offset - offset;
proto_tree_add_item_ret_string(tree, hf_sdp_nal_unit_2_string, tvb, offset, tokenlen, ENC_UTF_8|ENC_NA, wmem_packet_scope(), &data_p);
data_tvb = base64_to_tvb(tvb, data_p);
add_new_data_source(pinfo, data_tvb, "h264 prop-parameter-sets 2");
dissect_h264_nal_unit(data_tvb, pinfo, tree);
}
}
}
}
}
static void
dissect_sdp_media_attribute_candidate(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *pi;
gint next_offset, tokenlen;
const guint8 *candidate_type;
tokenlen = find_next_token_in_line(tvb, tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(tree, hf_ice_candidate_foundation,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(tree, hf_ice_candidate_componentid,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(tree, hf_ice_candidate_transport,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(tree, hf_ice_candidate_priority,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(tree, hf_ice_candidate_address,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, tree, &offset, &next_offset);
if (tokenlen == 0)
return;
proto_tree_add_item(tree, hf_ice_candidate_port,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
if (tvb_strneql(tvb, offset, "typ ", 4))
return;
offset += 4;
tokenlen = find_next_token_in_line(tvb, tree, &offset, &next_offset);
if (tokenlen == 0)
return;
pi = proto_tree_add_item_ret_string(tree, hf_ice_candidate_type,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA,
wmem_packet_scope(), &candidate_type);
if ((candidate_type = try_str_to_str(candidate_type, ice_candidate_types))) {
proto_item_append_text(pi, " (%s)", candidate_type);
}
}
static gint find_sdp_media_attribute_names(tvbuff_t *tvb, int offset, guint len)
{
guint i;
for (i = 1; i < array_length(sdp_media_attribute_names); i++) {
if ((len == strlen(sdp_media_attribute_names[i].name)) &&
(tvb_strncaseeql(tvb, offset, sdp_media_attribute_names[i].name, len) == 0))
return i;
}
return -1;
}
static void dissect_sdp_media_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_item * ti, int length,
transport_info_t *transport_info,
session_info_t *session_info,
media_description_t *media_desc,
sdp_data_t *sdp_data)
{
proto_tree *sdp_media_attribute_tree, *parameter_item;
proto_item *fmtp_item, *media_format_item, *parameter_tree;
proto_tree *fmtp_tree;
proto_item *pi;
gint offset, next_offset, tokenlen, colon_offset;
const guint8 *payload_type;
guint8 *attribute_value;
guint8 pt;
gint sdp_media_attrbute_code;
const char *msrp_res = "msrp://";
const char *h324ext_h223lcparm = "h324ext/h223lcparm";
gboolean has_more_pars = TRUE;
tvbuff_t *h245_tvb;
guint8 master_key_length = 0, master_salt_length = 0;
guint32 crypto_tag;
gboolean crypto_tag_valid;
gboolean mki_len_valid;
offset = 0;
sdp_media_attribute_tree = proto_item_add_subtree(ti,
ett_sdp_media_attribute);
colon_offset = tvb_find_guint8(tvb, offset, -1, ':');
if (colon_offset == -1)
return;
tokenlen = colon_offset - offset;
pi = proto_tree_add_item(sdp_media_attribute_tree,
hf_media_attribute_field,
tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
sdp_media_attrbute_code = find_sdp_media_attribute_names(tvb, offset, tokenlen);
offset = colon_offset + 1;
offset = tvb_skip_wsp(tvb, offset, tvb_captured_length_remaining(tvb, offset));
if (tvb_captured_length_remaining(tvb, offset) > 0)
attribute_value = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tvb_captured_length_remaining(tvb, offset), ENC_UTF_8|ENC_NA);
else
{
expert_add_info(pinfo, pi, &ei_sdp_invalid_line_fields);
return;
}
switch (sdp_media_attrbute_code) {
case SDP_RTPMAP:
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item_ret_string(sdp_media_attribute_tree, hf_media_format, tvb,
offset, tokenlen, ENC_UTF_8|ENC_NA, wmem_packet_scope(), &payload_type);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, '/');
if (next_offset == -1) {
return;
}
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_media_attribute_tree, hf_media_encoding_name, tvb,
offset, tokenlen, ENC_UTF_8|ENC_NA);
if (!ws_strtou8(payload_type, NULL, &pt) || pt >= SDP_NO_OF_PT) {
return;
}
transport_info->encoding_name[pt] = (char*)tvb_get_string_enc(wmem_file_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
next_offset = next_offset + 1;
offset = next_offset;
while (length-1 >= next_offset) {
if (!g_ascii_isdigit(tvb_get_guint8(tvb, next_offset)))
break;
next_offset++;
}
tokenlen = next_offset - offset;
pi = proto_tree_add_item(sdp_media_attribute_tree, hf_media_sample_rate, tvb,
offset, tokenlen, ENC_UTF_8|ENC_NA);
transport_info->sample_rate[pt] = 0;
if (!ws_strtou32(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA),
NULL, &transport_info->sample_rate[pt]))
expert_add_info(pinfo, pi, &ei_sdp_invalid_sample_rate);
if (session_info) {
rtp_dyn_payload_insert(session_info->rtp_dyn_payload,
pt,
transport_info->encoding_name[pt],
transport_info->sample_rate[pt]);
} else if (media_desc) {
rtp_dyn_payload_insert(media_desc->media.rtp_dyn_payload,
pt,
transport_info->encoding_name[pt],
transport_info->sample_rate[pt]);
}
break;
case SDP_FMTP:
if (sdp_media_attribute_tree) {
guint8 media_format;
offset = tvb_skip_wsp(tvb, offset, tvb_captured_length_remaining(tvb, offset));
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
media_format_item = proto_tree_add_item(sdp_media_attribute_tree,
hf_media_format, tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA);
if (!ws_strtou8(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA),
NULL, &media_format) || media_format >= SDP_NO_OF_PT) {
expert_add_info(pinfo, media_format_item, &ei_sdp_invalid_media_format);
return;
}
proto_item_append_text(media_format_item, " [%s]",
transport_info->encoding_name[media_format]);
#if 0
payload_type = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_ASCII);
#endif
offset = next_offset + 1;
while (has_more_pars == TRUE) {
next_offset = tvb_find_guint8(tvb, offset, -1, ';');
offset = tvb_skip_wsp(tvb, offset, tvb_captured_length_remaining(tvb, offset));
if (next_offset == -1) {
has_more_pars = FALSE;
next_offset= tvb_captured_length(tvb);
}
tokenlen = next_offset - offset;
fmtp_item = proto_tree_add_item(sdp_media_attribute_tree,
hf_media_format_specific_parameter, tvb,
offset, tokenlen, ENC_UTF_8|ENC_NA);
fmtp_tree = proto_item_add_subtree(fmtp_item, ett_sdp_fmtp);
decode_sdp_fmtp(fmtp_tree, tvb, pinfo, offset, tokenlen,
transport_info->encoding_name[media_format]);
offset = next_offset + 1;
}
}
break;
case SDP_PATH:
if (strncmp((char*)attribute_value, msrp_res, strlen(msrp_res)) == 0 && msrp_handle &&
media_desc && media_desc->proto == SDP_PROTO_MSRP) {
int address_offset, port_offset, port_end_offset;
address_offset = offset + (int)strlen(msrp_res);
port_offset = tvb_find_guint8(tvb, address_offset, -1, ':');
if (port_offset!= -1) {
port_end_offset = tvb_find_guint8(tvb, port_offset, -1, '/');
if (port_end_offset == -1) {
port_end_offset = tvb_find_guint8(tvb, port_offset, -1, ';');
}
guint32 msrp_ipaddr;
guint16 msrp_port_number;
if (str_to_ip((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, address_offset, port_offset-address_offset, ENC_UTF_8|ENC_NA),
&msrp_ipaddr)) {
if (ws_strtou16(tvb_get_string_enc(wmem_packet_scope(), tvb, port_offset + 1,
port_end_offset - port_offset - 1, ENC_UTF_8|ENC_NA), NULL, &msrp_port_number)) {
alloc_address_wmem(wmem_file_scope(), &media_desc->media_attr.msrp.ipaddr, AT_IPv4, 4, &msrp_ipaddr);
media_desc->media_attr.msrp.port_number = msrp_port_number;
}
}
}
}
break;
case SDP_H248_ITEM:
if (strncmp((char*)attribute_value, h324ext_h223lcparm, strlen(msrp_res)) == 0) {
gint len;
asn1_ctx_t actx;
len = (gint)strlen(attribute_value);
h245_tvb = ascii_bytes_to_tvb(tvb, pinfo, len, attribute_value);
if (h245_tvb) {
asn1_ctx_init(&actx, ASN1_ENC_PER, TRUE, pinfo);
dissect_h245_H223LogicalChannelParameters(h245_tvb, 0, &actx,
sdp_media_attribute_tree,
hf_SDPh223LogicalChannelParameters);
}
}
break;
case SDP_CRYPTO:
tokenlen = find_next_token_in_line(tvb, sdp_media_attribute_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
crypto_tag_valid = ws_strtou32(tvb_get_string_enc(wmem_packet_scope(), tvb, offset,
tokenlen, ENC_UTF_8|ENC_NA), NULL, &crypto_tag);
pi = proto_tree_add_uint(sdp_media_attribute_tree, hf_sdp_crypto_tag, tvb, offset, tokenlen,
crypto_tag);
if (!crypto_tag_valid)
expert_add_info(pinfo, pi, &ei_sdp_invalid_crypto_tag);
offset = next_offset + 1;
tokenlen = find_next_token_in_line(tvb, sdp_media_attribute_tree, &offset, &next_offset);
if (tokenlen == 0)
return;
parameter_item = proto_tree_add_item(sdp_media_attribute_tree, hf_sdp_crypto_crypto_suite,
tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
if (tvb_strncaseeql(tvb, offset, "AES_CM_128_HMAC_SHA1_80", tokenlen) == 0) {
if (transport_info->encryption_algorithm == SRTP_ENC_ALG_NOT_SET) {
transport_info->encryption_algorithm = SRTP_ENC_ALG_AES_CM;
transport_info->auth_algorithm = SRTP_AUTH_ALG_HMAC_SHA1;
transport_info->auth_tag_len = 10;
}
master_key_length = 16;
master_salt_length = 14;
} else if (tvb_strncaseeql(tvb, offset, "AES_CM_128_HMAC_SHA1_32", tokenlen) == 0) {
if (transport_info->encryption_algorithm == SRTP_ENC_ALG_NOT_SET) {
transport_info->encryption_algorithm = SRTP_ENC_ALG_AES_CM;
transport_info->auth_algorithm = SRTP_AUTH_ALG_HMAC_SHA1;
transport_info->auth_tag_len = 4;
}
master_key_length = 16;
master_salt_length = 14;
} else if (tvb_strncaseeql(tvb, offset, "F8_128_HMAC_SHA1_80", tokenlen) == 0) {
if (transport_info->encryption_algorithm == SRTP_ENC_ALG_NOT_SET) {
transport_info->encryption_algorithm = SRTP_ENC_ALG_AES_F8;
transport_info->auth_algorithm = SRTP_AUTH_ALG_HMAC_SHA1;
transport_info->auth_tag_len = 10;
}
master_key_length = 16;
master_salt_length = 14;
}
offset = next_offset + 1;
while (has_more_pars == TRUE) {
int param_end_offset;
tvbuff_t *key_salt_tvb;
gchar *data_p = NULL;
param_end_offset = tvb_find_guint8(tvb, offset, -1, ';');
if (param_end_offset == -1) {
has_more_pars = FALSE;
param_end_offset = tvb_captured_length(tvb);
}
next_offset = tvb_find_guint8(tvb, offset, -1, ':');
if (next_offset == -1) {
expert_add_info(pinfo, parameter_item, &ei_sdp_invalid_key_param);
break;
}
if (tvb_strncaseeql(tvb, offset, "inline", next_offset-offset) == 0) {
parameter_tree = proto_tree_add_subtree(sdp_media_attribute_tree, tvb, offset,
param_end_offset-offset, ett_sdp_crypto_key_parameters, NULL, "Key parameters");
offset = next_offset +1;
next_offset = tvb_find_guint8(tvb, offset, -1, '|');
if (next_offset == -1) {
tokenlen = param_end_offset - offset;
} else {
tokenlen = next_offset - offset;
}
data_p = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
key_salt_tvb = base64_to_tvb(tvb, data_p);
add_new_data_source(pinfo, key_salt_tvb, "Key_Salt_tvb");
if (master_key_length != 0) {
proto_tree_add_item(parameter_tree, hf_sdp_key_and_salt, tvb, offset, tokenlen, ENC_NA);
proto_tree_add_item(parameter_tree, hf_sdp_crypto_master_key,
key_salt_tvb, 0, master_key_length, ENC_NA);
proto_tree_add_item(parameter_tree, hf_sdp_crypto_master_salt,
key_salt_tvb, master_key_length, master_salt_length, ENC_NA);
} else {
proto_tree_add_item(parameter_tree, hf_sdp_key_and_salt, key_salt_tvb, 0, -1, ENC_NA);
}
if (next_offset != -1) {
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, '|');
if (next_offset == -1) {
if (next_offset < param_end_offset){
next_offset = param_end_offset;
}
}
if (next_offset != -1) {
tokenlen = next_offset - offset;
proto_tree_add_item(parameter_tree, hf_sdp_crypto_lifetime,
tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
}
if (offset>param_end_offset) {
next_offset = -1;
} else {
next_offset = tvb_find_guint8(tvb, offset, -1, ':');
}
if (next_offset != -1) {
tokenlen = next_offset - offset;
proto_tree_add_item(parameter_tree, hf_sdp_crypto_mki, tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
offset = next_offset + 1;
next_offset = param_end_offset;
tokenlen = next_offset - offset;
mki_len_valid = ws_strtou32(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen,
ENC_UTF_8|ENC_NA), NULL, &transport_info->mki_len);
pi = proto_tree_add_item(parameter_tree, hf_sdp_crypto_mki_length,
tvb, offset, tokenlen, ENC_UTF_8|ENC_NA);
if (!mki_len_valid)
expert_add_info(pinfo, pi, &ei_sdp_invalid_crypto_mki_length);
}
}
offset = param_end_offset;
} else {
break;
}
}
break;
case SDP_CANDIDATE:
dissect_sdp_media_attribute_candidate(sdp_media_attribute_tree, tvb, offset);
break;
case SDP_ED137_TYPE:
sdp_data->ed137_type = attribute_value;
proto_tree_add_item(sdp_media_attribute_tree, hf_media_attribute_value,
tvb, offset, -1, ENC_UTF_8|ENC_NA);
break;
case SDP_ED137_TXRXMODE:
sdp_data->ed137_txrxmode = attribute_value;
proto_tree_add_item(sdp_media_attribute_tree, hf_media_attribute_value,
tvb, offset, -1, ENC_UTF_8|ENC_NA);
break;
case SDP_ED137_FID:
sdp_data->ed137_fid = attribute_value;
proto_tree_add_item(sdp_media_attribute_tree, hf_media_attribute_value,
tvb, offset, -1, ENC_UTF_8|ENC_NA);
break;
default:
proto_tree_add_item(sdp_media_attribute_tree, hf_media_attribute_value,
tvb, offset, -1, ENC_UTF_8|ENC_NA);
break;
}
}
static void
call_sdp_subdissector(tvbuff_t *tvb, packet_info *pinfo, int hf, proto_tree* ti, int length,
transport_info_t *transport_info,
session_info_t *session_info,
media_description_t *media_desc,
sdp_data_t *sdp_data)
{
if (hf == hf_owner) {
dissect_sdp_owner(tvb, ti);
} else if (hf == hf_connection_info) {
dissect_sdp_connection_info(tvb, ti, session_info, media_desc);
} else if (hf == hf_bandwidth) {
dissect_sdp_bandwidth(tvb, ti);
} else if (hf == hf_time) {
dissect_sdp_time(tvb, ti);
} else if (hf == hf_repeat_time) {
dissect_sdp_repeat_time(tvb, ti);
} else if (hf == hf_timezone) {
dissect_sdp_timezone(tvb, ti);
} else if (hf == hf_encryption_key) {
dissect_sdp_encryption_key(tvb, ti);
} else if (hf == hf_session_attribute) {
dissect_sdp_session_attribute(tvb, pinfo, ti);
} else if (hf == hf_media) {
dissect_sdp_media(tvb, pinfo, ti, media_desc);
} else if (hf == hf_media_attribute) {
dissect_sdp_media_attribute(tvb, pinfo, ti, length, transport_info, session_info, media_desc, sdp_data);
}
}
static void
complete_descriptions(transport_info_t *transport_info, guint answer_offset)
{
guint media_count = wmem_array_get_count(transport_info->media_descriptions);
media_description_t *media_descs = (media_description_t *)wmem_array_get_raw(transport_info->media_descriptions);
DPRINT(("complete_descriptions called with answer_offset=%d media_count=%d",
answer_offset, media_count));
for (guint i = answer_offset; i < media_count; i++) {
media_description_t *media_desc = &media_descs[i];
if (answer_offset > 0) {
if (media_desc->media_port == 0) {
DPRINT(("disabling media_port=%d, for index=%d",
media_descs[i - answer_offset].media_port,
i - answer_offset));
media_descs[i - answer_offset].media_port = 0;
}
}
if (media_desc->proto == SDP_PROTO_MSRP && msrp_handle &&
media_desc->media_attr.msrp.ipaddr.type != AT_NONE) {
free_address_wmem(wmem_file_scope(), &media_desc->conn_addr);
copy_address_shallow(&media_desc->conn_addr,
&media_desc->media_attr.msrp.ipaddr);
media_desc->media_port = media_desc->media_attr.msrp.port_number;
}
}
}
static void
apply_sdp_transport(packet_info *pinfo, transport_info_t *transport_info, int request_frame)
{
int establish_frame = 0;
struct srtp_info *srtp_info = NULL;
if (!global_sdp_establish_conversation) {
return;
}
if (request_frame == 0) {
establish_frame = pinfo->num;
} else {
establish_frame = request_frame;
}
for (guint i = 0; i < wmem_array_get_count(transport_info->media_descriptions); i++) {
media_description_t *media_desc =
(media_description_t *)wmem_array_index(transport_info->media_descriptions, i);
guint32 current_rtp_port = 0;
if ((media_desc->media_port != 0) &&
(media_desc->proto == SDP_PROTO_RTP ||
media_desc->proto == SDP_PROTO_SRTP) &&
(media_desc->conn_addr.type == AT_IPv4 ||
media_desc->conn_addr.type == AT_IPv6)) {
if (media_desc->proto == SDP_PROTO_SRTP) {
srtp_info = wmem_new0(wmem_file_scope(), struct srtp_info);
if (transport_info->encryption_algorithm != SRTP_ENC_ALG_NOT_SET) {
srtp_info->encryption_algorithm = transport_info->encryption_algorithm;
srtp_info->auth_algorithm = transport_info->auth_algorithm;
srtp_info->mki_len = transport_info->mki_len;
srtp_info->auth_tag_len = transport_info->auth_tag_len;
}
DPRINT(("calling srtp_add_address, channel=%d, media_port=%d",
i, media_desc->media_port));
DINDENT();
srtp_add_address(pinfo, PT_UDP, &media_desc->conn_addr, media_desc->media_port, 0, "SDP", establish_frame,
media_desc->is_video,
media_desc->media.rtp_dyn_payload, srtp_info);
DENDENT();
} else {
DPRINT(("calling rtp_add_address, channel=%d, media_port=%d",
i, media_desc->media_port));
DINDENT();
rtp_add_address(pinfo, PT_UDP, &media_desc->conn_addr, media_desc->media_port, 0, "SDP", establish_frame,
media_desc->is_video,
media_desc->media.rtp_dyn_payload);
DENDENT();
}
media_desc->media.set_rtp = TRUE;
current_rtp_port = media_desc->media_port;
if (rtcp_handle) {
if (media_desc->proto == SDP_PROTO_SRTP) {
DPRINT(("calling rtcp_add_address, channel=%d, media_port=%d",
i, media_desc->media_port+1));
DINDENT();
srtcp_add_address(pinfo, &media_desc->conn_addr, media_desc->media_port+1, 0, "SDP", establish_frame, srtp_info);
DENDENT();
} else {
DPRINT(("calling rtcp_add_address, channel=%d, media_port=%d",
i, media_desc->media_port+1));
DINDENT();
rtcp_add_address(pinfo, &media_desc->conn_addr, media_desc->media_port+1, 0, "SDP", establish_frame);
DENDENT();
}
}
}
if (media_desc->proto == SDP_PROTO_SPRT &&
(media_desc->conn_addr.type == AT_IPv4 ||
media_desc->conn_addr.type == AT_IPv6) &&
(sprt_handle)) {
if (media_desc->media_port == 0 && current_rtp_port) {
sprt_add_address(pinfo, &media_desc->conn_addr, current_rtp_port,
0, "SDP", pinfo->num);
} else {
sprt_add_address(pinfo, &media_desc->conn_addr, media_desc->media_port, 0, "SDP", pinfo->num);
}
}
if ((media_desc->media_port != 0) &&
!media_desc->media.set_rtp &&
media_desc->proto == SDP_PROTO_T38 &&
media_desc->conn_addr.type == AT_IPv4) {
t38_add_address(pinfo, &media_desc->conn_addr, media_desc->media_port, 0, "SDP", pinfo->num);
}
if (media_desc->proto == SDP_PROTO_MSRP && msrp_handle) {
msrp_add_address(pinfo, &media_desc->conn_addr, media_desc->media_port, "SDP", pinfo->num);
}
}
}
void
setup_sdp_transport(tvbuff_t *tvb, packet_info *pinfo, enum sdp_exchange_type exchange_type,
int request_frame, const gboolean delay)
{
gint offset = 0, next_offset, n;
int linelen;
gboolean in_media_description = FALSE;
guchar type, delim;
const int tokenoffset = 2;
int hf = -1;
gint start_transport_info_count = 0;
transport_info_t* transport_info = NULL;
media_description_t *media_desc = NULL;
session_info_t session_info;
sdp_data_t sdp_data;
DPRINT2(("-------------------- setup_sdp_transport -------------------"));
if (pinfo->fd->flags.visited) {
DPRINT(("already visited"));
return;
}
memset(&sdp_data, 0, sizeof(sdp_data));
if (request_frame != 0)
transport_info = (transport_info_t*)wmem_tree_lookup32( sdp_transport_reqs, request_frame );
if (transport_info == NULL) {
transport_info = wmem_new0(wmem_file_scope(), transport_info_t);
transport_info->media_descriptions = wmem_array_new(wmem_file_scope(), sizeof(media_description_t));
for (n = 0; n < SDP_NO_OF_PT; n++) {
transport_info->encoding_name[n] = wmem_strdup(wmem_file_scope(), UNKNOWN_ENCODING);
}
if (request_frame != 0)
wmem_tree_insert32(sdp_transport_reqs, request_frame, (void *)transport_info);
}
#ifdef DEBUG_CONVERSATION
else {
DPRINT(("found previous transport_info:"));
sdp_dump_transport_info(transport_info);
}
#endif
if (exchange_type != SDP_EXCHANGE_OFFER)
wmem_tree_insert32(sdp_transport_rsps, pinfo->num, (void *)transport_info);
if ((transport_info->sdp_status == SDP_EXCHANGE_ANSWER_REJECT) ||
(transport_info->sdp_status == SDP_EXCHANGE_ANSWER_ACCEPT))
return;
memset(&session_info, 0, sizeof(session_info_t));
session_info.rtp_dyn_payload = rtp_dyn_payload_new();
start_transport_info_count = wmem_array_get_count(transport_info->media_descriptions);
DPRINT(("start_transport_info_count=%d", start_transport_info_count));
while (tvb_offset_exists(tvb, offset)) {
linelen = tvb_find_line_end_unquoted(tvb, offset, -1, &next_offset);
if (linelen < 2)
break;
type = tvb_get_guint8(tvb, offset);
delim = tvb_get_guint8(tvb, offset + 1);
if (delim != '=') {
offset = next_offset;
continue;
}
switch (type) {
case 'c':
hf = hf_connection_info;
break;
case 'm':
hf = hf_media;
media_desc = sdp_new_media_description(transport_info->media_descriptions, &session_info);
in_media_description = TRUE;
DPRINT(("in media description, media descriptions count=%d",
wmem_array_get_count(transport_info->media_descriptions)));
break;
case 'a':
if (in_media_description) {
hf = hf_media_attribute;
} else {
hf = hf_session_attribute;
}
break;
default:
hf = hf_unknown;
break;
}
if (hf != hf_unknown)
{
DINDENT();
call_sdp_subdissector(tvb_new_subset_length(tvb, offset + tokenoffset,
linelen - tokenoffset),
pinfo,
hf, NULL, linelen-tokenoffset,
transport_info,
in_media_description ? NULL : &session_info,
media_desc,
&sdp_data);
DENDENT();
}
offset = next_offset;
}
rtp_dyn_payload_free(session_info.rtp_dyn_payload);
session_info.rtp_dyn_payload = NULL;
complete_descriptions(transport_info, start_transport_info_count);
#ifdef DEBUG_CONVERSATION
sdp_dump_transport_info(transport_info);
#endif
if (!delay || ((exchange_type == SDP_EXCHANGE_ANSWER_ACCEPT) &&
(transport_info->sdp_status == SDP_EXCHANGE_OFFER))) {
apply_sdp_transport(pinfo, transport_info, request_frame);
clean_unused_media_descriptions(transport_info->media_descriptions);
transport_info->sdp_status = exchange_type;
} else if ((exchange_type == SDP_EXCHANGE_ANSWER_REJECT) &&
(transport_info->sdp_status != SDP_EXCHANGE_ANSWER_REJECT)) {
clean_unused_media_descriptions(transport_info->media_descriptions);
transport_info->sdp_status = SDP_EXCHANGE_ANSWER_REJECT;
}
}
void setup_sdp_transport_resend(int current_frame, int request_frame)
{
transport_info_t* transport_info = NULL;
if (request_frame != 0) {
transport_info = (transport_info_t*)wmem_tree_lookup32( sdp_transport_reqs, request_frame );
if (transport_info != NULL) {
wmem_tree_insert32(sdp_transport_reqs, current_frame, (void *)transport_info);
}
}
}
static int
dissect_sdp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *sdp_tree;
proto_item *ti, *sub_ti;
gint offset = 0, next_offset, n;
int linelen;
gboolean in_media_description;
guchar type, delim;
int datalen, tokenoffset, hf = -1;
char *string;
sdp_data_t sdp_data;
transport_info_t local_transport_info;
transport_info_t* transport_info = NULL;
media_description_t *media_desc = NULL;
session_info_t session_info;
sdp_packet_info *sdp_pi;
DPRINT2(("----------------------- dissect_sdp ------------------------"));
sdp_pi = wmem_new(wmem_packet_scope(), sdp_packet_info);
sdp_pi->summary_str[0] = '\0';
memset(&sdp_data, 0, sizeof(sdp_data));
if (!pinfo->fd->flags.visited) {
transport_info = (transport_info_t*)wmem_tree_lookup32( sdp_transport_reqs, pinfo->num );
if (transport_info == NULL) {
transport_info = (transport_info_t*)wmem_tree_lookup32( sdp_transport_rsps, pinfo->num );
}
}
if (transport_info == NULL) {
transport_info = &local_transport_info;
}
#ifdef DEBUG_CONVERSATION
else {
DPRINT(("found previous transport_info:"));
sdp_dump_transport_info(transport_info);
}
#endif
memset(&local_transport_info, 0, sizeof(local_transport_info));
local_transport_info.media_descriptions = wmem_array_new(wmem_packet_scope(), sizeof(media_description_t));
for (n = 0; n < SDP_NO_OF_PT; n++) {
local_transport_info.encoding_name[n] = wmem_strdup(wmem_packet_scope(), UNKNOWN_ENCODING);
}
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/SDP");
ti = proto_tree_add_item(tree, proto_sdp, tvb, offset, -1, ENC_NA);
sdp_tree = proto_item_add_subtree(ti, ett_sdp);
in_media_description = FALSE;
memset(&session_info, 0, sizeof(session_info_t));
session_info.rtp_dyn_payload = rtp_dyn_payload_new();
while (tvb_offset_exists(tvb, offset)) {
linelen = tvb_find_line_end_unquoted(tvb, offset, -1, &next_offset);
if (linelen < 2)
break;
type = tvb_get_guint8(tvb, offset);
delim = tvb_get_guint8(tvb, offset + 1);
if (delim != '=') {
proto_item *ti2 = proto_tree_add_item(sdp_tree, hf_invalid, tvb, offset, linelen, ENC_UTF_8|ENC_NA);
expert_add_info(pinfo, ti2, &ei_sdp_invalid_line_equal);
offset = next_offset;
continue;
}
switch (type) {
case 'v':
hf = hf_protocol_version;
break;
case 'o':
hf = hf_owner;
break;
case 's':
hf = hf_session_name;
break;
case 'i':
if (in_media_description) {
hf = hf_media_title;
} else {
hf = hf_session_info;
}
break;
case 'u':
hf = hf_uri;
break;
case 'e':
hf = hf_email;
break;
case 'p':
hf = hf_phone;
break;
case 'c':
hf = hf_connection_info;
break;
case 'b':
hf = hf_bandwidth;
break;
case 't':
hf = hf_time;
break;
case 'r':
hf = hf_repeat_time;
break;
case 'm':
hf = hf_media;
media_desc = sdp_new_media_description(local_transport_info.media_descriptions, &session_info);
in_media_description = TRUE;
break;
case 'k':
hf = hf_encryption_key;
break;
case 'a':
if (in_media_description) {
hf = hf_media_attribute;
} else {
hf = hf_session_attribute;
}
break;
case 'z':
hf = hf_timezone;
break;
default:
hf = hf_unknown;
break;
}
tokenoffset = 2;
if (hf == hf_unknown)
tokenoffset = 0;
string = (char*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset + tokenoffset,
linelen - tokenoffset, ENC_ASCII);
sub_ti = proto_tree_add_string(sdp_tree, hf, tvb, offset, linelen,
string);
call_sdp_subdissector(tvb_new_subset_length(tvb, offset + tokenoffset,
linelen - tokenoffset),
pinfo,
hf, sub_ti, linelen-tokenoffset,
&local_transport_info,
in_media_description ? NULL : &session_info,
in_media_description ? media_desc : NULL,
&sdp_data);
offset = next_offset;
}
if (NULL != sdp_data.ed137_fid) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", sdp_data.ed137_fid);
if (strlen(sdp_pi->summary_str))
g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str, sdp_data.ed137_fid, 50);
}
if (NULL != sdp_data.ed137_txrxmode) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", sdp_data.ed137_txrxmode);
if (strlen(sdp_pi->summary_str))
g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str, sdp_data.ed137_txrxmode, 50);
}
if (NULL != sdp_data.ed137_type) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", sdp_data.ed137_type);
if (strlen(sdp_pi->summary_str))
g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str, sdp_data.ed137_type, 50);
}
rtp_dyn_payload_free(session_info.rtp_dyn_payload);
session_info.rtp_dyn_payload = NULL;
if (transport_info == &local_transport_info) {
DPRINT(("no previous transport_info saved, calling complete_descriptions()"));
DINDENT();
complete_descriptions(transport_info, 0);
DENDENT();
#ifdef DEBUG_CONVERSATION
sdp_dump_transport_info(transport_info);
#endif
}
#ifdef DEBUG_CONVERSATION
else {
DPRINT(("not overwriting previous transport_info, local_transport_info contents:"));
sdp_dump_transport_info(&local_transport_info);
}
#endif
if ((!pinfo->fd->flags.visited) && (transport_info == &local_transport_info)) {
apply_sdp_transport(pinfo, transport_info, 0);
}
for (guint i = 0; i < wmem_array_get_count(local_transport_info.media_descriptions); i++)
{
media_desc = (media_description_t *)wmem_array_index(local_transport_info.media_descriptions, i);
if (media_desc->media_port != 0) {
for (int j = 0; j < media_desc->media.pt_count; j++)
{
DPRINT(("in for-loop for voip call analysis setting for media #%d, pt=%d",
j, media_desc->media. pt[j]));
if ((media_desc->media.pt[j] >= 96) && (media_desc->media.pt[j] <= 127)) {
const gchar *payload_type_str = rtp_dyn_payload_get_name(
media_desc->media.rtp_dyn_payload,
media_desc->media.pt[j]);
if (payload_type_str) {
if (strlen(sdp_pi->summary_str))
g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str, payload_type_str, 50);
} else {
char num_pt[10];
g_snprintf(num_pt, 10, "%u", media_desc->media.pt[j]);
if (strlen(sdp_pi->summary_str))
g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str, num_pt, 50);
}
} else {
if (strlen(sdp_pi->summary_str))
g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str,
val_to_str_ext(media_desc->media.pt[j], &rtp_payload_type_short_vals_ext, "%u"),
50);
}
}
}
if ((media_desc->media_port != 0) && media_desc->proto == SDP_PROTO_T38) {
if (strlen(sdp_pi->summary_str))
g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str, "t38", 50);
}
}
if (transport_info == &local_transport_info) {
clean_unused_media_descriptions(transport_info->media_descriptions);
}
datalen = tvb_captured_length_remaining(tvb, offset);
if (datalen > 0) {
proto_tree_add_item(sdp_tree, hf_sdp_data, tvb, offset, datalen, ENC_NA);
}
tap_queue_packet(sdp_tap, pinfo, sdp_pi);
return tvb_captured_length(tvb);
}
void
proto_register_sdp(void)
{
static hf_register_info hf[] = {
{ &hf_protocol_version,
{ "Session Description Protocol Version (v)", "sdp.version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_owner,
{ "Owner/Creator, Session Id (o)",
"sdp.owner", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL}
},
{ &hf_session_name,
{ "Session Name (s)", "sdp.session_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_session_info,
{ "Session Information (i)", "sdp.session_info",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uri,
{ "URI of Description (u)", "sdp.uri",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_email,
{ "E-mail Address (e)", "sdp.email",
FT_STRING, BASE_NONE, NULL, 0x0,
"E-mail Address", HFILL }
},
{ &hf_phone,
{ "Phone Number (p)", "sdp.phone",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_connection_info,
{ "Connection Information (c)", "sdp.connection_info",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bandwidth,
{ "Bandwidth Information (b)", "sdp.bandwidth",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_timezone,
{ "Time Zone Adjustments (z)", "sdp.timezone",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_encryption_key,
{ "Encryption Key (k)", "sdp.encryption_key",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_session_attribute,
{ "Session Attribute (a)", "sdp.session_attr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_attribute,
{ "Media Attribute (a)", "sdp.media_attr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_time,
{ "Time Description, active time (t)",
"sdp.time", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }
},
{ &hf_repeat_time,
{ "Repeat Time (r)", "sdp.repeat_time",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media,
{ "Media Description, name and address (m)",
"sdp.media", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }
},
{ &hf_media_title,
{ "Media Title (i)", "sdp.media_title",
FT_STRING, BASE_NONE, NULL, 0x0,
"Media Title", HFILL }
},
{ &hf_unknown,
{ "Unknown", "sdp.unknown",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_invalid,
{ "Invalid line", "sdp.invalid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_owner_username,
{ "Owner Username", "sdp.owner.username",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_owner_sessionid,
{ "Session ID", "sdp.owner.sessionid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_owner_version,
{ "Session Version", "sdp.owner.version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_owner_network_type,
{ "Owner Network Type", "sdp.owner.network_type",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_owner_address_type,
{ "Owner Address Type", "sdp.owner.address_type",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_owner_address,
{ "Owner Address", "sdp.owner.address",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_connection_info_network_type,
{ "Connection Network Type", "sdp.connection_info.network_type",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_connection_info_address_type,
{ "Connection Address Type", "sdp.connection_info.address_type",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_connection_info_connection_address,
{ "Connection Address", "sdp.connection_info.address",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_connection_info_ttl,
{ "Connection TTL", "sdp.connection_info.ttl",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_connection_info_num_addr,
{ "Connection Number of Addresses", "sdp.connection_info.num_addr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bandwidth_modifier,
{ "Bandwidth Modifier", "sdp.bandwidth.modifier",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bandwidth_value,
{ "Bandwidth Value", "sdp.bandwidth.value",
FT_STRING, BASE_NONE, NULL, 0x0,
"Bandwidth Value (in kbits/s)", HFILL }
},
{ &hf_time_start,
{ "Session Start Time", "sdp.time.start",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_time_stop,
{ "Session Stop Time", "sdp.time.stop",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_repeat_time_interval,
{ "Repeat Interval", "sdp.repeat_time.interval",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_repeat_time_duration,
{ "Repeat Duration", "sdp.repeat_time.duration",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_repeat_time_offset,
{ "Repeat Offset", "sdp.repeat_time.offset",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_timezone_time,
{ "Timezone Time", "sdp.timezone.time",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_timezone_offset,
{ "Timezone Offset", "sdp.timezone.offset",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_encryption_key_type,
{ "Key Type", "sdp.encryption_key.type",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_encryption_key_data,
{ "Key Data", "sdp.encryption_key.data",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_session_attribute_field,
{ "Session Attribute Fieldname", "sdp.session_attr.field",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_session_attribute_value,
{ "Session Attribute Value", "sdp.session_attr.value",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_media,
{ "Media Type", "sdp.media.media",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_port,
{ "Media Port", "sdp.media.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_port_string,
{ "Media Port", "sdp.media.port_string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_portcount,
{ "Media Port Count", "sdp.media.portcount",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_proto,
{ "Media Protocol", "sdp.media.proto",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_format,
{ "Media Format", "sdp.media.format",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_attribute_field,
{ "Media Attribute Fieldname", "sdp.media_attribute.field",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_attribute_value,
{ "Media Attribute Value", "sdp.media_attribute.value",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_encoding_name,
{ "MIME Type", "sdp.mime.type",
FT_STRING, BASE_NONE, NULL, 0x0,
"SDP MIME Type", HFILL }
},
{ &hf_media_sample_rate,
{ "Sample Rate", "sdp.sample_rate",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_media_format_specific_parameter,
{ "Media format specific parameters", "sdp.fmtp.parameter",
FT_STRING, BASE_NONE, NULL, 0x0,
"Format specific parameter(fmtp)", HFILL }
},
{ &hf_ipbcp_version,
{ "IPBCP Protocol Version", "sdp.ipbcp.version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipbcp_type,
{ "IPBCP Command Type", "sdp.ipbcp.command",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_sdp_fmtp_mpeg4_profile_level_id,
{ "Level Code", "sdp.fmtp.profile_level_id",
FT_UINT32, BASE_DEC, VALS(mp4ves_level_indication_vals), 0x0,
NULL, HFILL }
},
{ &hf_sdp_fmtp_h263_profile,
{ "Profile", "sdp.fmtp.h263profile",
FT_UINT32, BASE_DEC, VALS(h263_profile_vals), 0x0,
NULL, HFILL }
},
{ &hf_sdp_fmtp_h263_level,
{ "Level", "sdp.fmtp.h263level",
FT_UINT32, BASE_DEC, VALS(h263_level_vals), 0x0,
NULL, HFILL }
},
{ &hf_sdp_h264_packetization_mode,
{ "Packetization mode", "sdp.fmtp.h264_packetization_mode",
FT_UINT32, BASE_DEC, VALS(h264_packetization_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_SDPh223LogicalChannelParameters,
{ "h223LogicalChannelParameters", "sdp.h223LogicalChannelParameters",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_key_mgmt_att_value,
{ "Key Management", "sdp.key_mgmt",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_key_mgmt_prtcl_id,
{ "Key Management Protocol (kmpid)", "sdp.key_mgmt.kmpid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_key_mgmt_data,
{ "Key Management Data", "sdp.key_mgmt.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sdp_crypto_tag,
{ "tag", "sdp.crypto.tag",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sdp_crypto_crypto_suite,
{ "Crypto suite", "sdp.crypto.crypto_suite",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sdp_crypto_master_key,
{ "Master Key", "sdp.crypto.master_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sdp_crypto_master_salt,
{ "Master salt", "sdp.crypto.master_salt",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sdp_crypto_lifetime,
{ "Lifetime", "sdp.crypto.lifetime",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sdp_crypto_mki,
{ "mki-value", "sdp.crypto.mki-valu",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sdp_crypto_mki_length,
{ "mki_length", "sdp.crypto.mki_length",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ice_candidate_foundation,
{ "Foundation", "sdp.ice_candidate.foundation",
FT_STRING, BASE_NONE, NULL, 0x0,
"Identifier, same for two candidates with same type, base address, protocol and STUN server", HFILL }
},
{ &hf_ice_candidate_componentid,
{ "Component ID", "sdp.ice_candidate.componentid",
FT_STRING, BASE_NONE, NULL, 0x0,
"Media component identifier (For RTP media, 1 is RTP, 2 is RTCP)", HFILL }
},
{ &hf_ice_candidate_transport,
{ "Transport", "sdp.ice_candidate.transport",
FT_STRING, BASE_NONE, NULL, 0x0,
"Transport protocol", HFILL }
},
{ &hf_ice_candidate_priority,
{ "Priority", "sdp.ice_candidate.priority",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ice_candidate_address,
{ "Connection Address", "sdp.ice_candidate.address",
FT_STRING, BASE_NONE, NULL, 0x0,
"IP address or FQDN of the candidate", HFILL }
},
{ &hf_ice_candidate_port,
{ "Candidate Port", "sdp.ice_candidate.port",
FT_STRING, BASE_NONE, NULL, 0x0,
"Port of the candidate", HFILL }
},
{ &hf_ice_candidate_type,
{ "Candidate Type", "sdp.ice_candidate.type",
FT_STRING, BASE_NONE, NULL, 0x0,
"The origin of the address and port, i.e. where it was learned", HFILL }
},
{ &hf_sdp_nal_unit_1_string, { "NAL unit 1 string", "sdp.nal_unit_1_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sdp_nal_unit_2_string, { "NAL unit 2 string", "sdp.nal_unit_2_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sdp_key_and_salt, { "Key and Salt", "sdp.key_and_salt", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sdp_data, { "Data", "sdp.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_sdp,
&ett_sdp_owner,
&ett_sdp_connection_info,
&ett_sdp_bandwidth,
&ett_sdp_time,
&ett_sdp_repeat_time,
&ett_sdp_timezone,
&ett_sdp_encryption_key,
&ett_sdp_session_attribute,
&ett_sdp_media,
&ett_sdp_media_attribute,
&ett_sdp_fmtp,
&ett_sdp_key_mgmt,
&ett_sdp_crypto_key_parameters,
};
static ei_register_info ei[] = {
{ &ei_sdp_invalid_key_param,
{ "sdp.invalid_key_param",
PI_MALFORMED, PI_NOTE,
"Invalid key-param (no ':' delimiter)",
EXPFILL
}
},
{ &ei_sdp_invalid_line_equal,
{ "sdp.invalid_line.no_equal",
PI_MALFORMED, PI_NOTE,
"Invalid SDP line (no '=' delimiter)",
EXPFILL
}
},
{ &ei_sdp_invalid_line_fields,
{ "sdp.invalid_line.missing_fields",
PI_MALFORMED, PI_ERROR,
"Invalid SDP line (missing required fields)",
EXPFILL
}
},
{ &ei_sdp_invalid_line_space,
{ "sdp.invalid_line.extra_space",
PI_MALFORMED, PI_ERROR,
"Invalid SDP whitespace (extra space character)",
EXPFILL
}
},
{ &ei_sdp_invalid_conversion,
{ "sdp.invalid_conversion",
PI_PROTOCOL, PI_WARN,
"Invalid conversion",
EXPFILL
}
},
{ &ei_sdp_invalid_media_port,
{ "sdp.invalid_media_port",
PI_MALFORMED, PI_ERROR,
"Invalid media port",
EXPFILL
}
},
{ &ei_sdp_invalid_sample_rate,
{ "sdp.invalid_sample_rate",
PI_MALFORMED, PI_ERROR,
"Invalid sample rate",
EXPFILL
}
},
{ &ei_sdp_invalid_media_format,
{ "sdp.invalid_media_format",
PI_MALFORMED, PI_ERROR,
"Invalid media format",
EXPFILL
}
},
{ &ei_sdp_invalid_crypto_tag,
{ "sdp.invalid_crypto_tag",
PI_MALFORMED, PI_ERROR,
"Invalid crypto tag",
EXPFILL
}
},
{ &ei_sdp_invalid_crypto_mki_length,
{ "sdp.invalid_crypto_mki_length",
PI_MALFORMED, PI_ERROR,
"Invalid crypto mki length",
EXPFILL
}
}
};
module_t *sdp_module;
expert_module_t* expert_sdp;
proto_sdp = proto_register_protocol("Session Description Protocol",
"SDP", "sdp");
proto_register_field_array(proto_sdp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_sdp = expert_register_protocol(proto_sdp);
expert_register_field_array(expert_sdp, ei, array_length(ei));
key_mgmt_dissector_table = register_dissector_table("key_mgmt",
"Key Management", proto_sdp, FT_STRING, BASE_NONE);
sdp_module = prefs_register_protocol(proto_sdp, NULL);
prefs_register_bool_preference(sdp_module, "establish_conversation",
"Establish Media Conversation",
"Specifies that RTP/RTCP/T.38/MSRP/etc streams are decoded based "
"upon port numbers found in SDP payload",
&global_sdp_establish_conversation);
sdp_transport_reqs = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
sdp_transport_rsps = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
sdp_handle = register_dissector("sdp", dissect_sdp, proto_sdp);
sdp_tap = register_tap("sdp");
ws_mempbrk_compile(&pbrk_digits, "0123456789");
ws_mempbrk_compile(&pbrk_alpha, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}
void
proto_reg_handoff_sdp(void)
{
rtcp_handle = find_dissector_add_dependency("rtcp", proto_sdp);
msrp_handle = find_dissector_add_dependency("msrp", proto_sdp);
sprt_handle = find_dissector_add_dependency("sprt", proto_sdp);
h264_handle = find_dissector_add_dependency("h264", proto_sdp);
mp4ves_config_handle = find_dissector_add_dependency("mp4ves_config", proto_sdp);
proto_sprt = dissector_handle_get_protocol_index(find_dissector("sprt"));
dissector_add_string("media_type", "application/sdp", sdp_handle);
dissector_add_uint("bctp.tpi", 0x20, sdp_handle);
}
