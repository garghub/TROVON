static void free_encoding_name_str (void *ptr)
{
encoding_name_and_rate_t *encoding_name_and_rate = (encoding_name_and_rate_t *)ptr;
if (encoding_name_and_rate->encoding_name) {
g_free(encoding_name_and_rate->encoding_name);
}
}
static void
dissect_sdp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *sdp_tree;
proto_item *ti, *sub_ti;
gint offset = 0;
gint next_offset;
int linelen;
gboolean in_media_description;
guchar type;
guchar delim;
int datalen;
int tokenoffset;
int hf = -1;
char *string;
address src_addr;
transport_info_t transport_info;
guint32 port = 0;
gboolean is_rtp = FALSE;
gboolean is_srtp = FALSE;
gboolean is_t38 = FALSE;
gboolean is_msrp = FALSE;
gboolean set_rtp = FALSE;
gboolean is_ipv4_addr = FALSE;
gboolean is_ipv6_addr = FALSE;
gboolean is_video = FALSE;
guint32 ipaddr[4];
gint n, i;
sdp_packet_info *sdp_pi;
gchar *unknown_encoding = ep_strdup("Unknown");
struct srtp_info *srtp_info = NULL;
sdp_pi = ep_alloc(sizeof (sdp_packet_info));
sdp_pi->summary_str[0] = '\0';
transport_info.connection_address = NULL;
transport_info.connection_type = NULL;
transport_info.media_type = NULL;
transport_info.encryption_algorithm = SRTP_ENC_ALG_NOT_SET;
transport_info.auth_algorithm = SRTP_AUTH_ALG_NONE;
transport_info.mki_len = 0;
transport_info.auth_tag_len = 0;
for (n = 0; n < SDP_NO_OF_PT; n++) {
transport_info.encoding_name[n] = unknown_encoding;
transport_info.sample_rate[n] = 0;
}
for (n = 0; n < SDP_MAX_RTP_CHANNELS; n++)
{
transport_info.media_port[n] = NULL;
transport_info.media_proto[n] = NULL;
transport_info.media[n].pt_count = 0;
transport_info.media[n].rtp_dyn_payload =
g_hash_table_new_full(g_int_hash, g_int_equal, g_free, free_encoding_name_str);
}
transport_info.media_count = 0;
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/SDP");
col_append_str(pinfo->cinfo, COL_INFO, ", with session description");
ti = proto_tree_add_item(tree, proto_sdp, tvb, offset, -1, ENC_NA);
sdp_tree = proto_item_add_subtree(ti, ett_sdp);
in_media_description = FALSE;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
linelen = tvb_find_line_end_unquoted(tvb, offset, -1, &next_offset);
if (linelen < 2)
break;
type = tvb_get_guint8(tvb, offset);
delim = tvb_get_guint8(tvb, offset + 1);
if (delim != '=') {
proto_item *ti2 = proto_tree_add_item(sdp_tree, hf_invalid, tvb, offset, linelen, ENC_ASCII|ENC_NA);
expert_add_info_format(pinfo, ti2, PI_MALFORMED, PI_NOTE,
"Invalid SDP line (no '=' delimiter)");
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
string = (char*)tvb_get_ephemeral_string(tvb, offset + tokenoffset,
linelen - tokenoffset);
sub_ti = proto_tree_add_string(sdp_tree, hf, tvb, offset, linelen,
string);
call_sdp_subdissector(tvb_new_subset(tvb, offset + tokenoffset,
linelen - tokenoffset,
linelen - tokenoffset),
pinfo,
hf, sub_ti, linelen-tokenoffset,&transport_info),
offset = next_offset;
}
for (n = 0; n < transport_info.media_count; n++)
{
if (transport_info.media_port[n] != NULL) {
port = atol(transport_info.media_port[n]);
}
if (transport_info.media_proto[n] != NULL) {
if (global_sdp_establish_conversation) {
is_rtp = (strcmp(transport_info.media_proto[n],"RTP/AVP") == 0);
is_srtp = (strcmp(transport_info.media_proto[n],"RTP/SAVP") == 0);
is_t38 = ((strcmp(transport_info.media_proto[n],"UDPTL") == 0) ||
(strcmp(transport_info.media_proto[n],"udptl") == 0));
is_msrp = (strcmp(transport_info.media_proto[n],"msrp/tcp") == 0);
}
}
if (transport_info.connection_address != NULL) {
if (transport_info.connection_type != NULL) {
if (strcmp(transport_info.connection_type, "IP4") == 0) {
if (inet_pton(AF_INET, transport_info.connection_address, &ipaddr) == 1) {
is_ipv4_addr = TRUE;
src_addr.type = AT_IPv4;
src_addr.len = 4;
}
} else if (strcmp(transport_info.connection_type, "IP6") == 0) {
if (inet_pton(AF_INET6, transport_info.connection_address, &ipaddr) == 1) {
is_ipv6_addr = TRUE;
src_addr.type = AT_IPv6;
src_addr.len = 16;
}
}
}
}
if (strcmp(transport_info.media_type,"video") == 0) {
is_video = TRUE;
}
set_rtp = FALSE;
if ((!pinfo->fd->flags.visited) && port != 0 && (is_rtp || is_srtp) && (is_ipv4_addr || is_ipv6_addr)) {
src_addr.data = (guint8*)&ipaddr;
if (rtp_handle) {
if (is_srtp) {
srtp_info = se_alloc0(sizeof (struct srtp_info));
if (transport_info.encryption_algorithm != SRTP_ENC_ALG_NOT_SET) {
srtp_info->encryption_algorithm = transport_info.encryption_algorithm;
srtp_info->auth_algorithm = transport_info.auth_algorithm;
srtp_info->mki_len = transport_info.mki_len;
srtp_info->auth_tag_len = transport_info.auth_tag_len;
}
srtp_add_address(pinfo, &src_addr, port, 0, "SDP", pinfo->fd->num, is_video,
transport_info.media[n].rtp_dyn_payload, srtp_info);
} else {
rtp_add_address(pinfo, &src_addr, port, 0, "SDP", pinfo->fd->num, is_video,
transport_info.media[n].rtp_dyn_payload);
}
set_rtp = TRUE;
}
if (rtcp_handle) {
port++;
if (is_srtp) {
srtcp_add_address(pinfo, &src_addr, port, 0, "SDP", pinfo->fd->num, srtp_info);
} else {
rtcp_add_address(pinfo, &src_addr, port, 0, "SDP", pinfo->fd->num);
}
}
}
if ((!pinfo->fd->flags.visited) && (port != 0) && !set_rtp && is_t38 && is_ipv4_addr) {
src_addr.data = (guint8*)&ipaddr;
if (t38_handle) {
t38_add_address(pinfo, &src_addr, port, 0, "SDP", pinfo->fd->num);
}
}
if (is_msrp) {
if ((!pinfo->fd->flags.visited) && msrp_transport_address_set) {
if (msrp_handle) {
src_addr.type = AT_IPv4;
src_addr.len = 4;
src_addr.data = (guint8*)&msrp_ipaddr;
msrp_add_address(pinfo, &src_addr, msrp_port_number, "SDP", pinfo->fd->num);
}
}
}
if (port != 0) {
for (i = 0; i < transport_info.media[n].pt_count; i++)
{
if ((transport_info.media[n].pt[i] >= 96) && (transport_info.media[n].pt[i] <= 127)) {
encoding_name_and_rate_t *encoding_name_and_rate_pt =
g_hash_table_lookup(transport_info.media[n].rtp_dyn_payload, &transport_info.media[n].pt[i]);
if (encoding_name_and_rate_pt) {
if (strlen(sdp_pi->summary_str)) g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str, encoding_name_and_rate_pt->encoding_name, 50);
} else {
char num_pt[10];
g_snprintf(num_pt, 10, "%u", transport_info.media[n].pt[i]);
if (strlen(sdp_pi->summary_str)) g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str, num_pt, 50);
}
} else
if (strlen(sdp_pi->summary_str)) g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str,
val_to_str_ext(transport_info.media[n].pt[i], &rtp_payload_type_short_vals_ext, "%u"),
50);
}
}
if (set_rtp == FALSE)
rtp_free_hash_dyn_payload(transport_info.media[n].rtp_dyn_payload);
if ((port != 0) && is_t38) {
if (strlen(sdp_pi->summary_str)) g_strlcat(sdp_pi->summary_str, " ", 50);
g_strlcat(sdp_pi->summary_str, "t38", 50);
}
}
for (n = transport_info.media_count; n < SDP_MAX_RTP_CHANNELS; n++)
{
rtp_free_hash_dyn_payload(transport_info.media[n].rtp_dyn_payload);
}
datalen = tvb_length_remaining(tvb, offset);
if (datalen > 0) {
proto_tree_add_text(sdp_tree, tvb, offset, datalen, "Data (%d bytes)", datalen);
}
tap_queue_packet(sdp_tap, pinfo, sdp_pi);
}
static void
call_sdp_subdissector(tvbuff_t *tvb, packet_info *pinfo, int hf, proto_tree* ti, int length, transport_info_t *transport_info) {
if (hf == hf_owner) {
dissect_sdp_owner(tvb, ti);
} else if (hf == hf_connection_info) {
dissect_sdp_connection_info(tvb, ti, transport_info);
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
dissect_sdp_media(tvb, ti, transport_info);
} else if (hf == hf_media_attribute) {
dissect_sdp_media_attribute(tvb, pinfo, ti, length, transport_info);
}
}
static void
dissect_sdp_owner(tvbuff_t *tvb, proto_item *ti) {
proto_tree *sdp_owner_tree;
gint offset, next_offset, tokenlen;
offset = 0;
sdp_owner_tree = proto_item_add_subtree(ti, ett_sdp_owner);
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_owner_tree, hf_owner_username, tvb, offset, tokenlen,
ENC_ASCII|ENC_NA);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_owner_tree, hf_owner_sessionid, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_owner_tree, hf_owner_version, tvb, offset, tokenlen,
ENC_ASCII|ENC_NA);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_owner_tree, hf_owner_network_type, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_owner_tree, hf_owner_address_type, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
proto_tree_add_item(sdp_owner_tree, hf_owner_address, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
static void
dissect_sdp_connection_info(tvbuff_t *tvb, proto_item* ti,
transport_info_t *transport_info) {
proto_tree *sdp_connection_info_tree;
gint offset, next_offset, tokenlen;
offset = 0;
sdp_connection_info_tree = proto_item_add_subtree(ti,
ett_sdp_connection_info);
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_connection_info_tree,
hf_connection_info_network_type, tvb, offset, tokenlen,
ENC_ASCII|ENC_NA);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
transport_info->connection_type = (char*)tvb_get_ephemeral_string(tvb, offset, tokenlen);
proto_tree_add_item(sdp_connection_info_tree,
hf_connection_info_address_type, tvb, offset, tokenlen,
ENC_ASCII|ENC_NA);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, '/');
if (next_offset == -1) {
tokenlen = -1;
transport_info->connection_address =
(char*)tvb_get_ephemeral_string(tvb, offset, tvb_length_remaining(tvb, offset));
} else {
tokenlen = next_offset - offset;
transport_info->connection_address = (char*)tvb_get_ephemeral_string(tvb, offset, tokenlen);
}
proto_tree_add_item(sdp_connection_info_tree,
hf_connection_info_connection_address, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
if (next_offset != -1) {
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, '/');
if (next_offset == -1) {
tokenlen = -1;
} else {
tokenlen = next_offset - offset;
}
proto_tree_add_item(sdp_connection_info_tree,
hf_connection_info_ttl, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
if (next_offset != -1) {
offset = next_offset + 1;
proto_tree_add_item(sdp_connection_info_tree,
hf_connection_info_num_addr, tvb, offset, -1, ENC_ASCII|ENC_NA);
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
tokenlen, ENC_ASCII|ENC_NA);
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
ENC_ASCII|ENC_NA);
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
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_time_tree, hf_time_start, tvb, offset, tokenlen,
ENC_ASCII|ENC_NA);
offset = next_offset + 1;
proto_tree_add_item(sdp_time_tree, hf_time_stop, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
static void dissect_sdp_repeat_time(tvbuff_t *tvb, proto_item* ti) {
proto_tree *sdp_repeat_time_tree;
gint offset, next_offset, tokenlen;
offset = 0;
sdp_repeat_time_tree = proto_item_add_subtree(ti, ett_sdp_time);
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_repeat_time_tree, hf_repeat_time_interval, tvb,
offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_repeat_time_tree, hf_repeat_time_duration, tvb,
offset, tokenlen, ENC_ASCII|ENC_NA);
do{
offset = next_offset +1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset != -1) {
tokenlen = next_offset - offset;
} else {
tokenlen = -1;
}
proto_tree_add_item(sdp_repeat_time_tree, hf_repeat_time_offset,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
} while (next_offset != -1);
}
static void
dissect_sdp_timezone(tvbuff_t *tvb, proto_item* ti) {
proto_tree* sdp_timezone_tree;
gint offset, next_offset, tokenlen;
offset = 0;
sdp_timezone_tree = proto_item_add_subtree(ti, ett_sdp_timezone);
do{
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
break;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_timezone_tree, hf_timezone_time, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset != -1) {
tokenlen = next_offset - offset;
} else {
tokenlen = -1;
}
proto_tree_add_item(sdp_timezone_tree, hf_timezone_offset, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
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
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
proto_tree_add_item(sdp_encryption_key_tree, hf_encryption_key_data,
tvb, offset, -1, ENC_ASCII|ENC_NA);
}
static void dissect_key_mgmt(tvbuff_t *tvb, packet_info * pinfo, proto_item * ti) {
gchar *data_p = NULL;
gchar *prtcl_id = NULL;
gint len;
tvbuff_t *keymgmt_tvb;
gboolean found_match = FALSE;
proto_tree *key_tree;
gint next_offset;
gint offset = 0;
gint tokenlen;
key_tree = proto_item_add_subtree(ti, ett_sdp_key_mgmt);
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
prtcl_id = tvb_get_ephemeral_string(tvb, offset, tokenlen);
proto_tree_add_item(key_tree, hf_key_mgmt_prtcl_id, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
len = tvb_length_remaining(tvb, offset);
if (len < 0)
return;
data_p = tvb_get_ephemeral_string(tvb, offset, len);
keymgmt_tvb = base64_to_tvb(tvb, data_p);
add_new_data_source(pinfo, keymgmt_tvb, "Key Management Data");
if ((prtcl_id != NULL) && (key_mgmt_dissector_table != NULL)) {
found_match = dissector_try_string(key_mgmt_dissector_table,
prtcl_id,
keymgmt_tvb, pinfo,
key_tree);
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
guint8 *field_name;
offset = 0;
sdp_session_attribute_tree = proto_item_add_subtree(ti,
ett_sdp_session_attribute);
next_offset = tvb_find_guint8(tvb, offset, -1, ':');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_session_attribute_tree, hf_session_attribute_field,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
field_name = tvb_get_ephemeral_string(tvb, offset, tokenlen);
offset = next_offset + 1;
if (strcmp((char*)field_name, "ipbcp") == 0) {
offset = tvb_pbrk_guint8(tvb, offset, -1,"0123456789", NULL);
if (offset == -1)
return;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_session_attribute_tree, hf_ipbcp_version, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = tvb_pbrk_guint8(tvb, offset, -1,"ABCDEFGHIJKLMNOPQRSTUVWXYZ", NULL);
if (offset == -1)
return;
tokenlen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (tokenlen == -1)
return;
proto_tree_add_item(sdp_session_attribute_tree, hf_ipbcp_type, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
} else if (strcmp((char*)field_name, "key-mgmt") == 0) {
tvbuff_t *key_tvb;
proto_item *key_ti;
key_tvb = tvb_new_subset_remaining(tvb, offset);
key_ti = proto_tree_add_item(sdp_session_attribute_tree, hf_key_mgmt_att_value, key_tvb, 0, -1, ENC_ASCII|ENC_NA);
dissect_key_mgmt(key_tvb, pinfo, key_ti);
} else {
proto_tree_add_item(sdp_session_attribute_tree, hf_session_attribute_value,
tvb, offset, -1, ENC_ASCII|ENC_NA);
}
}
static void
dissect_sdp_media(tvbuff_t *tvb, proto_item *ti,
transport_info_t *transport_info) {
proto_tree *sdp_media_tree;
gint offset, next_offset, tokenlen, idx;
guint8 *media_format;
offset = 0;
msrp_transport_address_set = FALSE;
sdp_media_tree = proto_item_add_subtree(ti, ett_sdp_media);
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_media_tree, hf_media_media, tvb, offset, tokenlen,
ENC_ASCII|ENC_NA);
transport_info->media_type = (char*)tvb_get_ephemeral_string(tvb, offset, tokenlen);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
next_offset = tvb_find_guint8(tvb, offset, tokenlen, '/');
if (next_offset != -1) {
tokenlen = next_offset - offset;
transport_info->media_port[transport_info->media_count] = (char*)tvb_get_ephemeral_string(tvb, offset, tokenlen);
proto_tree_add_uint(sdp_media_tree, hf_media_port, tvb, offset, tokenlen,
atoi((char*)tvb_get_ephemeral_string(tvb, offset, tokenlen)));
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_media_tree, hf_media_portcount, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
} else {
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
transport_info->media_port[transport_info->media_count] = (char*)tvb_get_ephemeral_string(tvb, offset, tokenlen);
proto_tree_add_uint(sdp_media_tree, hf_media_port, tvb, offset, tokenlen,
atoi((char*)tvb_get_ephemeral_string(tvb, offset, tokenlen)));
offset = next_offset + 1;
}
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if ( next_offset == -1)
return;
tokenlen = next_offset - offset;
transport_info->media_proto[transport_info->media_count] = (char*)tvb_get_ephemeral_string(tvb, offset, tokenlen);
proto_tree_add_item(sdp_media_tree, hf_media_proto, tvb, offset, tokenlen,
ENC_ASCII|ENC_NA);
do {
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1) {
tokenlen = tvb_length_remaining(tvb, offset);
if (tokenlen == 0)
break;
} else {
tokenlen = next_offset - offset;
}
if (strcmp(transport_info->media_proto[transport_info->media_count],
"RTP/AVP") == 0) {
media_format = tvb_get_ephemeral_string(tvb, offset, tokenlen);
proto_tree_add_string(sdp_media_tree, hf_media_format, tvb, offset,
tokenlen, val_to_str_ext(atol((char*)media_format), &rtp_payload_type_vals_ext, "%u"));
idx = transport_info->media[transport_info->media_count].pt_count;
transport_info->media[transport_info->media_count].pt[idx] = atol((char*)media_format);
if (idx < (SDP_MAX_RTP_PAYLOAD_TYPES-1))
transport_info->media[transport_info->media_count].pt_count++;
} else {
proto_tree_add_item(sdp_media_tree, hf_media_format, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
}
} while (next_offset != -1);
if (transport_info->media_count < (SDP_MAX_RTP_CHANNELS-1)) {
transport_info->media_count++;
}
}
static tvbuff_t *
ascii_bytes_to_tvb(tvbuff_t *tvb, packet_info *pinfo, gint len, gchar *msg)
{
guint8 *buf = g_malloc(10240);
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
tvb_set_free_cb(bytes_tvb, g_free);
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
proto_tree_add_text(tree, tvb, offset, tokenlen, "Debug; Analysed string: '%s'",
tvb_get_ephemeral_string(tvb, offset, tokenlen));
#endif
next_offset = tvb_find_guint8(tvb, offset, -1, '=');
if (next_offset == -1)
{
return;
}
tokenlen = next_offset - offset;
field_name = tvb_get_ephemeral_string(tvb, offset, tokenlen);
#if 0
proto_tree_add_text(tree, tvb, offset, tokenlen, "Debug; MIMEtype '%s'Parameter name: '%s'", mime_type, field_name); */
#endif
offset = next_offset;
if ((mime_type != NULL) && (g_ascii_strcasecmp(mime_type, "MP4V-ES") == 0)) {
if (strcmp((char*)field_name, "profile-level-id") == 0) {
offset++;
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_ephemeral_string(tvb, offset, tokenlen);
item = proto_tree_add_uint(tree, hf_sdp_fmtp_mpeg4_profile_level_id, tvb, offset, tokenlen,
atol((char*)format_specific_parameter));
PROTO_ITEM_SET_GENERATED(item);
} else if (strcmp((char*)field_name, "config") == 0) {
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_ephemeral_string(tvb, offset, tokenlen);
data_tvb = ascii_bytes_to_tvb(tvb, pinfo, tokenlen, format_specific_parameter);
if (mp4ves_handle && data_tvb) {
dissect_mp4ves_config(data_tvb, pinfo, tree);
}
}
}
if (((mime_type != NULL) && (g_ascii_strcasecmp(mime_type, "H263-2000") == 0)) ||
((mime_type != NULL) && (g_ascii_strcasecmp(mime_type, "H263-1998") == 0))) {
if (strcmp((char*)field_name, "profile") == 0) {
offset++;
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_ephemeral_string(tvb, offset, tokenlen);
item = proto_tree_add_uint(tree, hf_sdp_fmtp_h263_profile, tvb, offset, tokenlen,
atol((char*)format_specific_parameter));
PROTO_ITEM_SET_GENERATED(item);
} else if (strcmp((char*)field_name, "level") == 0) {
offset++;
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_ephemeral_string(tvb, offset, tokenlen);
item = proto_tree_add_uint(tree, hf_sdp_fmtp_h263_level, tvb, offset, tokenlen,
atol((char*)format_specific_parameter));
PROTO_ITEM_SET_GENERATED(item);
}
}
if ((mime_type != NULL) && (g_ascii_strcasecmp(mime_type, "H264") == 0)) {
if (strcmp(field_name, "profile-level-id") == 0) {
int length = 0;
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_ephemeral_string(tvb, offset, tokenlen);
data_tvb = ascii_bytes_to_tvb(tvb, pinfo, tokenlen, format_specific_parameter);
if (!data_tvb) {
proto_tree_add_text(tree, tvb, offset, tokenlen, "Could not convert '%s' to 3 bytes", format_specific_parameter);
return;
}
length = tvb_length(data_tvb);
if (length == 3) {
if (h264_handle && data_tvb) {
dissect_h264_profile(data_tvb, pinfo, tree);
}
} else {
item = proto_tree_add_text(tree, tvb, offset, tokenlen, "Incorrectly coded, must be three bytes");
PROTO_ITEM_SET_GENERATED(item);
}
} else if (strcmp(field_name, "packetization-mode") == 0) {
offset++;
tokenlen = end_offset - offset;
format_specific_parameter = tvb_get_ephemeral_string(tvb, offset, tokenlen);
item = proto_tree_add_uint(tree, hf_sdp_h264_packetization_mode, tvb, offset, tokenlen,
atol((char*)format_specific_parameter));
PROTO_ITEM_SET_GENERATED(item);
} else if (strcmp(field_name, "sprop-parameter-sets") == 0) {
gchar *data_p = NULL;
gint comma_offset;
offset++;
comma_offset = tvb_find_guint8(tvb, offset, -1, ',');
if (comma_offset != -1) {
tokenlen = comma_offset - offset;
} else {
tokenlen = end_offset - offset;
}
data_p = tvb_get_ephemeral_string(tvb, offset, tokenlen);
proto_tree_add_text(tree, tvb, offset, tokenlen, "NAL unit 1 string: %s", data_p);
data_tvb = base64_to_tvb(tvb, data_p);
add_new_data_source(pinfo, data_tvb, "h264 prop-parameter-sets");
if (h264_handle && data_tvb) {
TRY {
dissect_h264_nal_unit(data_tvb, pinfo, tree);
}
CATCH(BoundsError) {
RETHROW;
}
CATCH(ReportedBoundsError) {
show_reported_bounds_error(tvb, pinfo, tree);
}
ENDTRY;
if (comma_offset != -1) {
offset = comma_offset +1;
tokenlen = end_offset - offset;
data_p = tvb_get_ephemeral_string(tvb, offset, tokenlen);
proto_tree_add_text(tree, tvb, offset, tokenlen, "NAL unit 2 string: %s", data_p);
data_tvb = base64_to_tvb(tvb, data_p);
add_new_data_source(pinfo, data_tvb, "h264 prop-parameter-sets 2");
dissect_h264_nal_unit(data_tvb, pinfo, tree);
}
}
}
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
static void dissect_sdp_media_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_item * ti, int length, transport_info_t *transport_info) {
proto_tree *sdp_media_attribute_tree, *parameter_item;
proto_item *fmtp_item, *media_format_item, *parameter_tree;
proto_tree *fmtp_tree;
gint offset, next_offset, tokenlen, n, colon_offset;
guint8 *payload_type;
guint8 *attribute_value;
gint *key;
guint8 pt;
gint sdp_media_attrbute_code;
const char *msrp_res = "msrp://";
const char *h324ext_h223lcparm = "h324ext/h223lcparm";
gboolean has_more_pars = TRUE;
tvbuff_t *h245_tvb;
guint8 master_key_length = 0, master_salt_length = 0;
encoding_name_and_rate_t *encoding_name_and_rate;
offset = 0;
sdp_media_attribute_tree = proto_item_add_subtree(ti,
ett_sdp_media_attribute);
colon_offset = tvb_find_guint8(tvb, offset, -1, ':');
if (colon_offset == -1)
return;
tokenlen = colon_offset - offset;
proto_tree_add_item(sdp_media_attribute_tree,
hf_media_attribute_field,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
sdp_media_attrbute_code = find_sdp_media_attribute_names(tvb, offset, tokenlen);
offset = colon_offset + 1;
offset = tvb_skip_wsp(tvb, offset, tvb_length_remaining(tvb, offset));
attribute_value = tvb_get_ephemeral_string(tvb, offset, tvb_length_remaining(tvb, offset));
switch (sdp_media_attrbute_code) {
case SDP_RTPMAP:
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_media_attribute_tree, hf_media_format, tvb,
offset, tokenlen, ENC_ASCII|ENC_NA);
payload_type = tvb_get_ephemeral_string(tvb, offset, tokenlen);
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, '/');
if (next_offset == -1) {
return;
}
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_media_attribute_tree, hf_media_encoding_name, tvb,
offset, tokenlen, ENC_ASCII|ENC_NA);
pt = atoi((char*)payload_type);
if (pt >= SDP_NO_OF_PT) {
return;
}
key = g_malloc(sizeof (gint));
*key = atol((char*)payload_type);
transport_info->encoding_name[pt] = (char*)tvb_get_ephemeral_string(tvb, offset, tokenlen);
next_offset = next_offset + 1;
offset = next_offset;
while (length-1 >= next_offset) {
if (!isdigit(tvb_get_guint8(tvb, next_offset)))
break;
next_offset++;
}
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_media_attribute_tree, hf_media_sample_rate, tvb,
offset, tokenlen, ENC_ASCII|ENC_NA);
transport_info->sample_rate[pt] = atoi(tvb_get_ephemeral_string(tvb, offset, tokenlen));
if (transport_info->media_count == 0) {
for (n = 0; n < SDP_MAX_RTP_CHANNELS; n++) {
encoding_name_and_rate = g_malloc(sizeof (encoding_name_and_rate_t));
encoding_name_and_rate->encoding_name = g_strdup(transport_info->encoding_name[pt]);
encoding_name_and_rate->sample_rate = transport_info->sample_rate[pt];
if (n == 0) {
g_hash_table_insert(transport_info->media[n].rtp_dyn_payload,
key, encoding_name_and_rate);
} else {
gint *key2;
key2 = g_malloc(sizeof (gint));
*key2 = atol((char*)payload_type);
g_hash_table_insert(transport_info->media[n].rtp_dyn_payload,
key2, encoding_name_and_rate);
}
}
return;
} else
encoding_name_and_rate = g_malloc(sizeof (encoding_name_and_rate_t));
encoding_name_and_rate->encoding_name = g_strdup(transport_info->encoding_name[pt]);
encoding_name_and_rate->sample_rate = transport_info->sample_rate[pt];
if (transport_info->media_count == SDP_MAX_RTP_CHANNELS-1)
g_hash_table_insert(transport_info->media[ transport_info->media_count ].rtp_dyn_payload,
key, encoding_name_and_rate);
else
g_hash_table_insert(transport_info->media[ transport_info->media_count-1 ].rtp_dyn_payload,
key, encoding_name_and_rate);
break;
case SDP_FMTP:
if (sdp_media_attribute_tree) {
guint8 media_format;
offset = tvb_skip_wsp(tvb, offset, tvb_length_remaining(tvb, offset));
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (next_offset == -1)
return;
tokenlen = next_offset - offset;
media_format_item = proto_tree_add_item(sdp_media_attribute_tree,
hf_media_format, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
media_format = atoi((char*)tvb_get_ephemeral_string(tvb, offset, tokenlen));
if (media_format >= SDP_NO_OF_PT) {
return;
}
proto_item_append_text(media_format_item, " [%s]",
transport_info->encoding_name[media_format]);
#if 0
payload_type = tvb_get_ephemeral_string(tvb, offset, tokenlen);
#endif
offset = next_offset + 1;
while (has_more_pars == TRUE) {
next_offset = tvb_find_guint8(tvb, offset, -1, ';');
offset = tvb_skip_wsp(tvb, offset, tvb_length_remaining(tvb, offset));
if (next_offset == -1) {
has_more_pars = FALSE;
next_offset= tvb_length(tvb);
}
tokenlen = next_offset - offset;
fmtp_item = proto_tree_add_item(sdp_media_attribute_tree,
hf_media_format_specific_parameter, tvb,
offset, tokenlen, ENC_ASCII|ENC_NA);
fmtp_tree = proto_item_add_subtree(fmtp_item, ett_sdp_fmtp);
decode_sdp_fmtp(fmtp_tree, tvb, pinfo, offset, tokenlen,
transport_info->encoding_name[media_format]);
offset = next_offset + 1;
}
}
break;
case SDP_PATH:
if (strncmp((char*)attribute_value, msrp_res, strlen(msrp_res)) == 0) {
int address_offset, port_offset, port_end_offset;
address_offset = offset + (int)strlen(msrp_res);
port_offset = tvb_find_guint8(tvb, address_offset, -1, ':');
if (port_offset!= -1) {
port_end_offset = tvb_find_guint8(tvb, port_offset, -1, '/');
if (inet_pton(AF_INET,
(char*)tvb_get_ephemeral_string(tvb, address_offset, port_offset-address_offset),
&msrp_ipaddr) > 0) {
msrp_port_number = atoi((char*)tvb_get_ephemeral_string(tvb, port_offset + 1, port_end_offset - port_offset - 1));
msrp_transport_address_set = TRUE;
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
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
tokenlen = next_offset - offset;
proto_tree_add_uint(sdp_media_attribute_tree, hf_sdp_crypto_tag, tvb, offset, tokenlen,
atoi((char*)tvb_get_ephemeral_string(tvb, offset, tokenlen)));
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, ' ');
tokenlen = next_offset - offset;
proto_tree_add_item(sdp_media_attribute_tree, hf_sdp_crypto_crypto_suite,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
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
param_end_offset = tvb_length(tvb);
}
parameter_item = proto_tree_add_text(sdp_media_attribute_tree,
tvb, offset, param_end_offset-offset, "Key parameters");
parameter_tree = proto_item_add_subtree(parameter_item, ett_sdp_crypto_key_parameters);
next_offset = tvb_find_guint8(tvb, offset, -1, ':');
if (next_offset == -1) {
expert_add_info_format(pinfo, parameter_item, PI_MALFORMED, PI_NOTE,
"Invalid key-param (no ':' delimiter)");
break;
}
if (tvb_strncaseeql(tvb, offset, "inline", next_offset-offset) == 0) {
offset = next_offset +1;
next_offset = tvb_find_guint8(tvb, offset, -1, '|');
if (next_offset == -1) {
tokenlen = param_end_offset - offset;
} else {
tokenlen = next_offset - offset;
}
data_p = tvb_get_ephemeral_string(tvb, offset, tokenlen);
key_salt_tvb = base64_to_tvb(tvb, data_p);
add_new_data_source(pinfo, key_salt_tvb, "Key_Salt_tvb");
if (master_key_length != 0) {
proto_tree_add_text(parameter_tree, tvb, offset, tokenlen, "Key and Salt");
proto_tree_add_item(parameter_tree, hf_sdp_crypto_master_key,
key_salt_tvb, 0, master_key_length, ENC_ASCII|ENC_NA);
proto_tree_add_item(parameter_tree, hf_sdp_crypto_master_salt,
key_salt_tvb, master_key_length, master_salt_length, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_text(parameter_tree, key_salt_tvb, 0, -1, "Key and Salt");
}
if (next_offset != -1) {
offset = next_offset + 1;
next_offset = tvb_find_guint8(tvb, offset, -1, '|');
if (next_offset != -1) {
tokenlen = next_offset - offset;
proto_tree_add_item(parameter_tree, hf_sdp_crypto_lifetime,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
}
next_offset = tvb_find_guint8(tvb, offset, -1, ':');
tokenlen = next_offset - offset;
proto_tree_add_item(parameter_tree, hf_sdp_crypto_mki, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset + 1;
next_offset = param_end_offset;
tokenlen = next_offset - offset;
transport_info->mki_len = atoi((char*)tvb_get_ephemeral_string(tvb, offset, tokenlen));
proto_tree_add_item(parameter_tree, hf_sdp_crypto_mki_length,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
}
offset = param_end_offset;
} else {
tokenlen = param_end_offset - next_offset + 1;
proto_tree_add_text(parameter_tree, tvb, next_offset + 1, tokenlen,
"%s", tvb_get_ephemeral_string(tvb, next_offset + 1, tokenlen));
offset = param_end_offset;
}
}
break;
default:
proto_tree_add_item(sdp_media_attribute_tree, hf_media_attribute_value,
tvb, offset, -1, ENC_ASCII|ENC_NA);
break;
}
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
{ "IPBCP Protocol Version", "ipbcp.version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipbcp_type,
{ "IPBCP Command Type", "ipbcp.command",
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
{ "Mater salt", "sdp.crypto.master_salt",
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
module_t *sdp_module;
proto_sdp = proto_register_protocol("Session Description Protocol",
"SDP", "sdp");
proto_register_field_array(proto_sdp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
key_mgmt_dissector_table = register_dissector_table("key_mgmt",
"Key Management", FT_STRING, BASE_NONE);
sdp_module = prefs_register_protocol(proto_sdp, NULL);
prefs_register_bool_preference(sdp_module, "establish_conversation",
"Establish Media Conversation",
"Specifies that RTP/RTCP/T.38/MSRP/etc streams are decoded based "
"upon port numbers found in SDP payload",
&global_sdp_establish_conversation);
register_dissector("sdp", dissect_sdp, proto_sdp);
sdp_tap = register_tap("sdp");
}
void
proto_reg_handoff_sdp(void)
{
dissector_handle_t sdp_handle;
rtp_handle = find_dissector("rtp");
rtcp_handle = find_dissector("rtcp");
msrp_handle = find_dissector("msrp");
t38_handle = find_dissector("t38");
h264_handle = find_dissector("h264");
mp4ves_handle = find_dissector("mp4ves");
sdp_handle = find_dissector("sdp");
dissector_add_string("media_type", "application/sdp", sdp_handle);
dissector_add_uint("bctp.tpi", 0x20, sdp_handle);
}
