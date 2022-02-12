static int
radiusstat_packet(void *prs, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pri)
{
rtd_data_t *rtd_data = (rtd_data_t *)prs;
rtd_stat_table *rs = &rtd_data->stat_table;
const radius_info_t *ri = (const radius_info_t *)pri;
nstime_t delta;
radius_category radius_cat = RADIUS_CAT_OTHERS;
int ret = 0;
switch (ri->code) {
case RADIUS_PKT_TYPE_ACCESS_REQUEST:
case RADIUS_PKT_TYPE_ACCESS_ACCEPT:
case RADIUS_PKT_TYPE_ACCESS_REJECT:
radius_cat = RADIUS_CAT_ACCESS;
break;
case RADIUS_PKT_TYPE_ACCOUNTING_REQUEST:
case RADIUS_PKT_TYPE_ACCOUNTING_RESPONSE:
radius_cat = RADIUS_CAT_ACCOUNTING;
break;
case RADIUS_PKT_TYPE_PASSWORD_REQUEST:
case RADIUS_PKT_TYPE_PASSWORD_ACK:
case RADIUS_PKT_TYPE_PASSWORD_REJECT:
radius_cat = RADIUS_CAT_PASSWORD;
break;
case RADIUS_PKT_TYPE_RESOURCE_FREE_REQUEST:
case RADIUS_PKT_TYPE_RESOURCE_FREE_RESPONSE:
radius_cat = RADIUS_CAT_RESOURCE_FREE;
break;
case RADIUS_PKT_TYPE_RESOURCE_QUERY_REQUEST:
case RADIUS_PKT_TYPE_RESOURCE_QUERY_RESPONSE:
radius_cat = RADIUS_CAT_RESOURCE_QUERY;
break;
case RADIUS_PKT_TYPE_NAS_REBOOT_REQUEST:
case RADIUS_PKT_TYPE_NAS_REBOOT_RESPONSE:
radius_cat = RADIUS_CAT_NAS_REBOOT;
break;
case RADIUS_PKT_TYPE_EVENT_REQUEST:
case RADIUS_PKT_TYPE_EVENT_RESPONSE:
radius_cat = RADIUS_CAT_EVENT;
break;
case RADIUS_PKT_TYPE_DISCONNECT_REQUEST:
case RADIUS_PKT_TYPE_DISCONNECT_ACK:
case RADIUS_PKT_TYPE_DISCONNECT_NAK:
radius_cat = RADIUS_CAT_DISCONNECT;
break;
case RADIUS_PKT_TYPE_COA_REQUEST:
case RADIUS_PKT_TYPE_COA_ACK:
case RADIUS_PKT_TYPE_COA_NAK:
radius_cat = RADIUS_CAT_COA;
break;
}
switch (ri->code) {
case RADIUS_PKT_TYPE_ACCESS_REQUEST:
case RADIUS_PKT_TYPE_ACCOUNTING_REQUEST:
case RADIUS_PKT_TYPE_PASSWORD_REQUEST:
case RADIUS_PKT_TYPE_EVENT_REQUEST:
case RADIUS_PKT_TYPE_DISCONNECT_REQUEST:
case RADIUS_PKT_TYPE_COA_REQUEST:
if (ri->is_duplicate) {
rs->time_stats[RADIUS_CAT_OVERALL].req_dup_num++;
rs->time_stats[radius_cat].req_dup_num++;
} else {
rs->time_stats[RADIUS_CAT_OVERALL].open_req_num++;
rs->time_stats[radius_cat].open_req_num++;
}
break;
case RADIUS_PKT_TYPE_ACCESS_ACCEPT:
case RADIUS_PKT_TYPE_ACCESS_REJECT:
case RADIUS_PKT_TYPE_ACCOUNTING_RESPONSE:
case RADIUS_PKT_TYPE_PASSWORD_ACK:
case RADIUS_PKT_TYPE_PASSWORD_REJECT:
case RADIUS_PKT_TYPE_EVENT_RESPONSE:
case RADIUS_PKT_TYPE_DISCONNECT_ACK:
case RADIUS_PKT_TYPE_DISCONNECT_NAK:
case RADIUS_PKT_TYPE_COA_ACK:
case RADIUS_PKT_TYPE_COA_NAK:
if (ri->is_duplicate) {
rs->time_stats[RADIUS_CAT_OVERALL].rsp_dup_num++;
rs->time_stats[radius_cat].rsp_dup_num++;
} else if (!ri->request_available) {
rs->time_stats[RADIUS_CAT_OVERALL].disc_rsp_num++;
rs->time_stats[radius_cat].disc_rsp_num++;
} else {
rs->time_stats[RADIUS_CAT_OVERALL].open_req_num--;
rs->time_stats[radius_cat].open_req_num--;
nstime_delta(&delta, &pinfo->abs_ts, &ri->req_time);
time_stat_update(&(rs->time_stats[RADIUS_CAT_OVERALL].rtd[0]),&delta, pinfo);
time_stat_update(&(rs->time_stats[radius_cat].rtd[0]),&delta, pinfo);
ret = 1;
}
break;
default:
break;
}
return ret;
}
static gint
radius_vsa_equal(gconstpointer k1, gconstpointer k2)
{
const radius_vsa_buffer_key *key1 = (const radius_vsa_buffer_key *) k1;
const radius_vsa_buffer_key *key2 = (const radius_vsa_buffer_key *) k2;
return (((key1->vendor_id == key2->vendor_id) &&
(key1->vsa_type == key2->vsa_type)
) ? TRUE : FALSE);
}
static guint
radius_vsa_hash(gconstpointer k)
{
const radius_vsa_buffer_key *key = (const radius_vsa_buffer_key *) k;
return key->vendor_id + key->vsa_type;
}
static gboolean
radius_call_equal(gconstpointer k1, gconstpointer k2)
{
const radius_call_info_key *key1 = (const radius_call_info_key *) k1;
const radius_call_info_key *key2 = (const radius_call_info_key *) k2;
if (key1->ident == key2->ident && key1->conversation == key2->conversation) {
if (key1->code == key2->code)
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_ACCESS_REQUEST) &&
((key2->code == RADIUS_PKT_TYPE_ACCESS_ACCEPT) ||
(key2->code == RADIUS_PKT_TYPE_ACCESS_REJECT) ||
(key2->code == RADIUS_PKT_TYPE_ACCESS_CHALLENGE)))
return TRUE;
if ((key2->code == RADIUS_PKT_TYPE_ACCESS_REQUEST) &&
((key1->code == RADIUS_PKT_TYPE_ACCESS_ACCEPT) ||
(key1->code == RADIUS_PKT_TYPE_ACCESS_REJECT) ||
(key1->code == RADIUS_PKT_TYPE_ACCESS_CHALLENGE)))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_ACCOUNTING_REQUEST) &&
(key2->code == RADIUS_PKT_TYPE_ACCOUNTING_RESPONSE))
return TRUE;
if ((key2->code == RADIUS_PKT_TYPE_ACCOUNTING_REQUEST) &&
(key1->code == RADIUS_PKT_TYPE_ACCOUNTING_RESPONSE))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_PASSWORD_REQUEST) &&
((key2->code == RADIUS_PKT_TYPE_PASSWORD_ACK) ||
(key2->code == RADIUS_PKT_TYPE_PASSWORD_REJECT)))
return TRUE;
if ((key2->code == RADIUS_PKT_TYPE_PASSWORD_REQUEST) &&
((key1->code == RADIUS_PKT_TYPE_PASSWORD_ACK) ||
(key1->code == RADIUS_PKT_TYPE_PASSWORD_REJECT)))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_RESOURCE_FREE_REQUEST) &&
(key2->code == RADIUS_PKT_TYPE_RESOURCE_FREE_RESPONSE))
return TRUE;
if ((key2->code == RADIUS_PKT_TYPE_RESOURCE_FREE_REQUEST) &&
(key1->code == RADIUS_PKT_TYPE_RESOURCE_FREE_RESPONSE))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_RESOURCE_QUERY_REQUEST) &&
(key2->code == RADIUS_PKT_TYPE_RESOURCE_QUERY_RESPONSE))
return TRUE;
if ((key2->code == RADIUS_PKT_TYPE_RESOURCE_QUERY_REQUEST) &&
(key1->code == RADIUS_PKT_TYPE_RESOURCE_QUERY_RESPONSE))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_NAS_REBOOT_REQUEST) &&
(key2->code == RADIUS_PKT_TYPE_NAS_REBOOT_RESPONSE))
return TRUE;
if ((key2->code == RADIUS_PKT_TYPE_NAS_REBOOT_REQUEST) &&
(key1->code == RADIUS_PKT_TYPE_NAS_REBOOT_RESPONSE))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_EVENT_REQUEST) &&
(key2->code == RADIUS_PKT_TYPE_EVENT_RESPONSE))
return TRUE;
if ((key2->code == RADIUS_PKT_TYPE_EVENT_REQUEST) &&
(key1->code == RADIUS_PKT_TYPE_EVENT_RESPONSE))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_DISCONNECT_REQUEST) &&
((key2->code == RADIUS_PKT_TYPE_DISCONNECT_ACK) ||
(key2->code == RADIUS_PKT_TYPE_DISCONNECT_NAK)))
return TRUE;
if ((key2->code == RADIUS_PKT_TYPE_DISCONNECT_REQUEST) &&
((key1->code == RADIUS_PKT_TYPE_DISCONNECT_ACK) ||
(key1->code == RADIUS_PKT_TYPE_DISCONNECT_NAK)))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_COA_REQUEST) &&
((key2->code == RADIUS_PKT_TYPE_COA_ACK) ||
(key2->code == RADIUS_PKT_TYPE_COA_NAK)))
return TRUE;
if ((key2->code == RADIUS_PKT_TYPE_COA_REQUEST) &&
((key1->code == RADIUS_PKT_TYPE_COA_ACK) ||
(key1->code == RADIUS_PKT_TYPE_COA_NAK)))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_ALU_STATE_REQUEST) &&
((key2->code == RADIUS_PKT_TYPE_ALU_STATE_ACCEPT) ||
(key2->code == RADIUS_PKT_TYPE_ALU_STATE_REJECT) ||
(key2->code == RADIUS_PKT_TYPE_ALU_STATE_ERROR)))
return TRUE;
if ((key2->code == RADIUS_PKT_TYPE_ALU_STATE_REQUEST) &&
((key1->code == RADIUS_PKT_TYPE_ALU_STATE_ACCEPT) ||
(key1->code == RADIUS_PKT_TYPE_ALU_STATE_REJECT) ||
(key1->code == RADIUS_PKT_TYPE_ALU_STATE_ERROR)))
return TRUE;
}
return FALSE;
}
static guint
radius_call_hash(gconstpointer k)
{
const radius_call_info_key *key = (const radius_call_info_key *) k;
return key->ident + key->conversation->conv_index;
}
static const gchar *
dissect_chap_password(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int len;
proto_item *ti;
proto_tree *chap_tree;
len = tvb_reported_length(tvb);
if (len != 17)
return "[wrong length for CHAP-Password]";
ti = proto_tree_add_item(tree, hf_radius_chap_password, tvb, 0, len, ENC_NA);
chap_tree = proto_item_add_subtree(ti, ett_chap);
proto_tree_add_item(chap_tree, hf_radius_chap_ident, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(chap_tree, hf_radius_chap_string, tvb, 1, 16, ENC_NA);
return (tvb_bytes_to_str(wmem_packet_scope(), tvb, 0, len));
}
static const gchar *
dissect_framed_ip_address(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int len;
guint32 ip;
guint32 ip_h;
const gchar *str;
len = tvb_reported_length(tvb);
if (len != 4)
return "[wrong length for IP address]";
ip = tvb_get_ipv4(tvb, 0);
ip_h = g_ntohl(ip);
if (ip_h == 0xFFFFFFFF) {
str = "Negotiated";
proto_tree_add_ipv4_format_value(tree, hf_radius_framed_ip_address,
tvb, 0, len, ip, "%s", str);
} else if (ip_h == 0xFFFFFFFE) {
str = "Assigned";
proto_tree_add_ipv4_format_value(tree, hf_radius_framed_ip_address,
tvb, 0, len, ip, "%s", str);
} else {
str = tvb_ip_to_str(tvb, 0);
proto_tree_add_item(tree, hf_radius_framed_ip_address,
tvb, 0, len, ENC_BIG_ENDIAN);
}
return str;
}
static const gchar *
dissect_login_ip_host(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int len;
guint32 ip;
guint32 ip_h;
const gchar *str;
len = tvb_reported_length(tvb);
if (len != 4)
return "[wrong length for IP address]";
ip = tvb_get_ipv4(tvb, 0);
ip_h = g_ntohl(ip);
if (ip_h == 0xFFFFFFFF) {
str = "User-selected";
proto_tree_add_ipv4_format_value(tree, hf_radius_login_ip_host,
tvb, 0, len, ip, "%s", str);
} else if (ip_h == 0) {
str = "NAS-selected";
proto_tree_add_ipv4_format_value(tree, hf_radius_login_ip_host,
tvb, 0, len, ip, "%s", str);
} else {
str = tvb_ip_to_str(tvb, 0);
proto_tree_add_item(tree, hf_radius_login_ip_host,
tvb, 0, len, ENC_BIG_ENDIAN);
}
return str;
}
static const gchar *
dissect_ascend_data_filter(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
wmem_strbuf_t *filterstr;
proto_item *ti;
proto_tree *ascend_tree;
int len;
guint8 type, proto, srclen, dstlen;
address srcip, dstip;
guint16 srcport, dstport;
guint8 srcportq, dstportq;
guint8 iplen = 4;
guint offset = 0;
len=tvb_reported_length(tvb);
if (len != 24 && len != 48) {
return wmem_strdup_printf(wmem_packet_scope(), "Wrong attribute length %d", len);
}
filterstr = wmem_strbuf_sized_new(wmem_packet_scope(), 128, 128);
ti = proto_tree_add_item(tree, hf_radius_ascend_data_filter, tvb, 0, -1, ENC_NA);
ascend_tree = proto_item_add_subtree(ti, ett_radius_ascend);
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_type, tvb, offset, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, 0);
offset += 1;
if (type == 3) {
iplen = 16;
}
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_filteror, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_inout, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_spare, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (type == 3) {
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_src_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_dst_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_src_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_dst_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_src_ip_prefix, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_dst_ip_prefix, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_established, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_src_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_dst_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_src_port_qualifier, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_dst_port_qualifier, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ascend_tree, hf_radius_ascend_data_filter_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
wmem_strbuf_append_printf(filterstr, "%s %s %s",
val_to_str(type, ascenddf_filtertype, "%u"),
val_to_str(tvb_get_guint8(tvb, 2), ascenddf_inout, "%u"),
val_to_str(tvb_get_guint8(tvb, 1), ascenddf_filteror, "%u"));
proto = tvb_get_guint8(tvb, 6+iplen*2);
if (proto) {
wmem_strbuf_append_printf(filterstr, " %s",
val_to_str(proto, ascenddf_proto, "%u"));
}
if (type == 3) {
set_address_tvb(&srcip, AT_IPv6, 16, tvb, 4);
} else {
set_address_tvb(&srcip, AT_IPv4, 4, tvb, 4);
}
srclen = tvb_get_guint8(tvb, 4+iplen*2);
srcport = tvb_get_ntohs(tvb, 9+iplen*2);
srcportq = tvb_get_guint8(tvb, 12+iplen*2);
if (srclen || srcportq) {
wmem_strbuf_append_printf(filterstr, " srcip %s/%d", address_to_display(wmem_packet_scope(), &srcip), srclen);
if (srcportq)
wmem_strbuf_append_printf(filterstr, " srcport %s %d",
val_to_str(srcportq, ascenddf_portq, "%u"), srcport);
}
if (type == 3) {
set_address_tvb(&dstip, AT_IPv6, 16, tvb, 4+iplen);
} else {
set_address_tvb(&dstip, AT_IPv4, 4, tvb, 4+iplen);
}
dstlen = tvb_get_guint8(tvb, 5+iplen*2);
dstport = tvb_get_ntohs(tvb, 10+iplen*2);
dstportq = tvb_get_guint8(tvb, 13+iplen*2);
if (dstlen || dstportq) {
wmem_strbuf_append_printf(filterstr, " dstip %s/%d", address_to_display(wmem_packet_scope(), &dstip), dstlen);
if (dstportq)
wmem_strbuf_append_printf(filterstr, " dstport %s %d",
val_to_str(dstportq, ascenddf_portq, "%u"), dstport);
}
return wmem_strbuf_get_str(filterstr);
}
static const gchar *
dissect_framed_ipx_network(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int len;
guint32 net;
const gchar *str;
len = tvb_reported_length(tvb);
if (len != 4)
return "[wrong length for IPX network]";
net = tvb_get_ntohl(tvb, 0);
if (net == 0xFFFFFFFE)
str = "NAS-selected";
else
str = wmem_strdup_printf(wmem_packet_scope(), "0x%08X", net);
proto_tree_add_ipxnet_format_value(tree, hf_radius_framed_ipx_network, tvb, 0,
len, net, "Framed-IPX-Network: %s", str);
return str;
}
static const gchar *
dissect_cosine_vpvc(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
guint vpi, vci;
if (tvb_reported_length(tvb) != 4)
return "[Wrong Length for VP/VC AVP]";
vpi = tvb_get_ntohs(tvb, 0);
vci = tvb_get_ntohs(tvb, 2);
proto_tree_add_uint(tree, hf_radius_cosine_vpi, tvb, 0, 2, vpi);
proto_tree_add_uint(tree, hf_radius_cosine_vci, tvb, 2, 2, vci);
return wmem_strdup_printf(wmem_packet_scope(), "%u/%u", vpi, vci);
}
static const gchar *
dissect_radius_3gpp_ms_tmime_zone(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int offset = 0;
guint8 oct, daylight_saving_time;
char sign;
oct = tvb_get_guint8(tvb, offset);
sign = (oct & 0x08) ? '-' : '+';
oct = (oct >> 4) + (oct & 0x07) * 10;
daylight_saving_time = tvb_get_guint8(tvb, offset+1) & 0x3;
proto_tree_add_bytes_format_value(tree, hf_radius_3gpp_ms_tmime_zone, tvb, offset, 2, NULL,
"GMT %c%d hours %d minutes %s", sign, oct / 4, oct % 4 * 15,
val_to_str_const(daylight_saving_time, daylight_saving_time_vals, "Unknown"));
return wmem_strdup_printf(wmem_packet_scope(), "Timezone: GMT %c%d hours %d minutes %s ",
sign, oct / 4, oct % 4 * 15, val_to_str_const(daylight_saving_time, daylight_saving_time_vals, "Unknown"));
}
static const gchar *
dissect_rfc4675_egress_vlanid(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int len;
guint32 vlanid;
len = tvb_reported_length(tvb);
if (len != 4)
return "[wrong length for Egress-VLANID ]";
proto_tree_add_item(tree, hf_radius_egress_vlanid_tag, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_radius_egress_vlanid_pad, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_radius_egress_vlanid, tvb, 0, 4, ENC_BIG_ENDIAN);
vlanid = tvb_get_ntohl(tvb, 0);
return wmem_strdup_printf(wmem_packet_scope(), "%s, Vlan ID: %u",
val_to_str_const(((vlanid&0xFF000000)>>24), egress_vlan_tag_vals, "Unknown"), vlanid&0xFFF);
}
static const gchar *
dissect_rfc4675_egress_vlan_name(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int len;
guint8 tag;
const guint8 *name;
len = tvb_reported_length(tvb);
if (len < 2)
return "[wrong length for Egress-VLAN-Name ]";
proto_tree_add_item(tree, hf_radius_egress_vlan_name_tag, tvb, 0, 1, ENC_BIG_ENDIAN);
tag = tvb_get_guint8(tvb, 0);
len -= 1;
proto_tree_add_item_ret_string(tree, hf_radius_egress_vlan_name, tvb, 1, len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &name);
return wmem_strdup_printf(wmem_packet_scope(), "%s, Vlan Name: %s",
val_to_str_const(tag, egress_vlan_tag_vals, "Unknown"), name);
}
static void
radius_decrypt_avp(gchar *dest, int dest_len, tvbuff_t *tvb, int offset, int length)
{
gcry_md_hd_t md5_handle, old_md5_handle;
guint8 digest[HASH_MD5_LENGTH];
int i, j;
gint totlen = 0, returned_length, padded_length;
guint8 *pd;
guchar c;
DISSECTOR_ASSERT(dest_len > 0);
dest[0] = '\0';
if (length <= 0)
return;
if (length > 128)
length = 128;
if (gcry_md_open(&md5_handle, GCRY_MD_MD5, 0)) {
return;
}
gcry_md_write(md5_handle, (const guint8 *)shared_secret, (int)strlen(shared_secret));
if (gcry_md_copy(&old_md5_handle, md5_handle)) {
gcry_md_close(md5_handle);
return;
}
gcry_md_write(md5_handle, authenticator, AUTHENTICATOR_LENGTH);
memcpy(digest, gcry_md_read(md5_handle, 0), HASH_MD5_LENGTH);
gcry_md_close(md5_handle);
padded_length = length + ((length % AUTHENTICATOR_LENGTH) ?
(AUTHENTICATOR_LENGTH - (length % AUTHENTICATOR_LENGTH)) : 0);
pd = (guint8 *)wmem_alloc0(wmem_packet_scope(), padded_length);
tvb_memcpy(tvb, pd, offset, length);
for (i = 0; i < padded_length; i += AUTHENTICATOR_LENGTH) {
for (j = 0; j < AUTHENTICATOR_LENGTH; j++) {
c = pd[i + j] ^ digest[j];
if (g_ascii_isprint(c)) {
returned_length = g_snprintf(&dest[totlen], dest_len - totlen,
"%c", c);
totlen += MIN(returned_length, dest_len - totlen - 1);
}
else if (c) {
returned_length = g_snprintf(&dest[totlen], dest_len - totlen,
"\\%03o", c);
totlen += MIN(returned_length, dest_len - totlen - 1);
}
}
if (gcry_md_copy(&md5_handle, old_md5_handle)) {
gcry_md_close(old_md5_handle);
return;
}
gcry_md_write(md5_handle, &pd[i], AUTHENTICATOR_LENGTH);
memcpy(digest, gcry_md_read(md5_handle, 0), HASH_MD5_LENGTH);
gcry_md_close(md5_handle);
}
gcry_md_close(old_md5_handle);
}
void
radius_integer(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
guint32 uintv;
switch (len) {
case 1:
uintv = tvb_get_guint8(tvb, offset);
break;
case 2:
uintv = tvb_get_ntohs(tvb, offset);
break;
case 3:
uintv = tvb_get_ntoh24(tvb, offset);
break;
case 4:
uintv = tvb_get_ntohl(tvb, offset);
break;
case 8: {
guint64 uintv64 = tvb_get_ntoh64(tvb, offset);
proto_tree_add_uint64(tree, a->hf_alt, tvb, offset, len, uintv64);
proto_item_append_text(avp_item, "%" G_GINT64_MODIFIER "u", uintv64);
return;
}
default:
proto_item_append_text(avp_item, "[unhandled integer length(%u)]", len);
return;
}
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_BIG_ENDIAN);
if (a->vs) {
proto_item_append_text(avp_item, "%s(%u)", val_to_str_const(uintv, a->vs, "Unknown"), uintv);
} else {
proto_item_append_text(avp_item, "%u", uintv);
}
}
void
radius_signed(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
guint32 uintv;
switch (len) {
case 1:
uintv = tvb_get_guint8(tvb, offset);
break;
case 2:
uintv = tvb_get_ntohs(tvb, offset);
break;
case 3:
uintv = tvb_get_ntoh24(tvb, offset);
break;
case 4:
uintv = tvb_get_ntohl(tvb, offset);
break;
case 8: {
guint64 uintv64 = tvb_get_ntoh64(tvb, offset);
proto_tree_add_int64(tree, a->hf_alt, tvb, offset, len, uintv64);
proto_item_append_text(avp_item, "%" G_GINT64_MODIFIER "u", uintv64);
return;
}
default:
proto_item_append_text(avp_item, "[unhandled signed integer length(%u)]", len);
return;
}
proto_tree_add_int(tree, a->hf, tvb, offset, len, uintv);
if (a->vs) {
proto_item_append_text(avp_item, "%s(%d)", val_to_str_const(uintv, a->vs, "Unknown"), uintv);
} else {
proto_item_append_text(avp_item, "%d", uintv);
}
}
void
radius_string(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
switch (a->encrypt) {
case 0:
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_UTF_8|ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_format_text(tvb, offset, len));
break;
case 1:
if (*shared_secret == '\0') {
proto_item_append_text(avp_item, "Encrypted");
proto_tree_add_item(tree, a->hf_alt, tvb, offset, len, ENC_NA);
} else {
gchar *buffer;
buffer = (gchar *)wmem_alloc(wmem_packet_scope(), 1024);
radius_decrypt_avp(buffer, 1024, tvb, offset, len);
proto_item_append_text(avp_item, "Decrypted: %s", buffer);
proto_tree_add_string(tree, a->hf, tvb, offset, len, buffer);
}
break;
case 2:
proto_item_append_text(avp_item, "Encrypted");
proto_tree_add_item(tree, a->hf_alt, tvb, offset, len, ENC_NA);
break;
case 3:
proto_item_append_text(avp_item, "Encrypted");
proto_tree_add_item(tree, a->hf_alt, tvb, offset, len, ENC_NA);
break;
}
}
void
radius_octets(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, len));
}
void
radius_ipaddr(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
if (len != 4) {
proto_item_append_text(avp_item, "[wrong length for IP address]");
return;
}
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_BIG_ENDIAN);
proto_item_append_text(avp_item, "%s", tvb_ip_to_str(tvb, offset));
}
void
radius_ipv6addr(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
if (len != 16) {
proto_item_append_text(avp_item, "[wrong length for IPv6 address]");
return;
}
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_ip6_to_str(tvb, offset));
}
void
radius_ipv6prefix(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
struct e_in6_addr ipv6_buff;
gchar txtbuf[256];
guint8 n;
if ((len < 2) || (len > 18)) {
proto_item_append_text(avp_item, "[wrong length for IPv6 prefix]");
return;
}
if (tvb_get_guint8(tvb, offset)) {
proto_item_append_text(avp_item, "[invalid reserved byte for IPv6 prefix]");
return;
}
n = tvb_get_guint8(tvb, offset + 1);
if (n > 128) {
proto_item_append_text(avp_item, "[invalid IPv6 prefix length]");
return;
}
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
memset(&ipv6_buff, 0, sizeof ipv6_buff);
tvb_memcpy(tvb, &ipv6_buff, offset + 2, len - 2);
ip6_to_str_buf(&ipv6_buff, txtbuf, sizeof(txtbuf));
proto_item_append_text(avp_item, "%s/%u", txtbuf, n);
}
void
radius_combo_ip(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
if (len == 4) {
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_BIG_ENDIAN);
proto_item_append_text(avp_item, "%s", tvb_ip_to_str(tvb, offset));
} else if (len == 16) {
proto_tree_add_item(tree, a->hf_alt, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_ip6_to_str(tvb, offset));
} else {
proto_item_append_text(avp_item, "[wrong length for both of IPv4 and IPv6 address]");
return;
}
}
void
radius_ipxnet(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
guint32 net;
if (len != 4) {
proto_item_append_text(avp_item, "[wrong length for IPX network]");
return;
}
net = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "0x%08X", net);
}
void
radius_date(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
nstime_t time_ptr;
if (len != 4) {
proto_item_append_text(avp_item, "[wrong length for timestamp]");
return;
}
time_ptr.secs = tvb_get_ntohl(tvb, offset);
time_ptr.nsecs = 0;
proto_tree_add_time(tree, a->hf, tvb, offset, len, &time_ptr);
proto_item_append_text(avp_item, "%s", abs_time_to_str(wmem_packet_scope(), &time_ptr, ABSOLUTE_TIME_LOCAL, TRUE));
}
void
radius_abinary(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, len));
}
void
radius_ether(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
if (len != 6) {
proto_item_append_text(avp_item, "[wrong length for ethernet address]");
return;
}
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_ether_to_str(tvb, offset));
}
void
radius_ifid(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, len));
}
static void
add_tlv_to_tree(proto_tree *tlv_tree, proto_item *tlv_item, packet_info *pinfo, tvbuff_t *tvb, radius_attr_info_t *dictionary_entry, guint32 tlv_length, guint32 offset)
{
proto_item_append_text(tlv_item, ": ");
dictionary_entry->type(dictionary_entry, tlv_tree, pinfo, tvb, offset, tlv_length, tlv_item);
}
void
radius_tlv(radius_attr_info_t *a, proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int len, proto_item *avp_item)
{
gint tlv_num = 0;
while (len > 0) {
radius_attr_info_t *dictionary_entry = NULL;
guint32 tlv_type;
guint32 tlv_length;
proto_item *tlv_item;
proto_item *tlv_len_item;
proto_tree *tlv_tree;
if (len < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_radius_invalid_length, tvb, offset, 0,
"Not enough room in packet for TLV header");
return;
}
tlv_type = tvb_get_guint8(tvb, offset);
tlv_length = tvb_get_guint8(tvb, offset+1);
if (tlv_length < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_radius_invalid_length, tvb, offset, 0,
"TLV too short: length %u < 2", tlv_length);
return;
}
if (len < (gint)tlv_length) {
proto_tree_add_expert_format(tree, pinfo, &ei_radius_invalid_length, tvb, offset, 0,
"Not enough room in packet for TLV");
return;
}
len -= tlv_length;
dictionary_entry = (radius_attr_info_t *)g_hash_table_lookup(a->tlvs_by_id, GUINT_TO_POINTER(tlv_type));
if (!dictionary_entry) {
dictionary_entry = &no_dictionary_entry;
}
tlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, tlv_length,
dictionary_entry->ett, &tlv_item, "TLV: l=%u t=%s(%u)", tlv_length,
dictionary_entry->name, tlv_type);
tlv_length -= 2;
offset += 2;
if (show_length) {
tlv_len_item = proto_tree_add_uint(tlv_tree,
dictionary_entry->hf_len,
tvb, 0, 0, tlv_length);
PROTO_ITEM_SET_GENERATED(tlv_len_item);
}
add_tlv_to_tree(tlv_tree, tlv_item, pinfo, tvb, dictionary_entry,
tlv_length, offset);
offset += tlv_length;
tlv_num++;
}
proto_item_append_text(avp_item, "%d TLV(s) inside", tlv_num);
}
static void
add_avp_to_tree(proto_tree *avp_tree, proto_item *avp_item, packet_info *pinfo, tvbuff_t *tvb, radius_attr_info_t *dictionary_entry, guint32 avp_length, guint32 offset)
{
if (dictionary_entry->tagged) {
guint tag;
if (avp_length == 0) {
proto_tree_add_expert_format(avp_tree, pinfo, &ei_radius_invalid_length, tvb, offset,
0, "AVP too short for tag");
return;
}
tag = tvb_get_guint8(tvb, offset);
if (tag <= 0x1f) {
proto_tree_add_uint(avp_tree,
dictionary_entry->hf_tag,
tvb, offset, 1, tag);
proto_item_append_text(avp_item,
" Tag=0x%.2x", tag);
offset++;
avp_length--;
}
}
if (dictionary_entry->dissector) {
tvbuff_t *tvb_value;
const gchar *str;
tvb_value = tvb_new_subset_length(tvb, offset, avp_length);
str = dictionary_entry->dissector(avp_tree, tvb_value, pinfo);
proto_item_append_text(avp_item, ": %s", str);
} else {
proto_item_append_text(avp_item, ": ");
dictionary_entry->type(dictionary_entry, avp_tree, pinfo, tvb, offset, avp_length, avp_item);
}
}
static gboolean
vsa_buffer_destroy(gpointer k _U_, gpointer v, gpointer p _U_)
{
radius_vsa_buffer *vsa_buffer = (radius_vsa_buffer *)v;
g_free((gpointer)vsa_buffer->data);
g_free(v);
return TRUE;
}
static void
vsa_buffer_table_destroy(void *table)
{
if (table) {
g_hash_table_foreach_remove((GHashTable *)table, vsa_buffer_destroy, NULL);
g_hash_table_destroy((GHashTable *)table);
}
}
void
dissect_attribute_value_pairs(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset, guint length)
{
gboolean last_eap = FALSE;
guint8 *eap_buffer = NULL;
guint eap_seg_num = 0;
guint eap_tot_len_captured = 0;
guint eap_tot_len = 0;
proto_tree *eap_tree = NULL;
tvbuff_t *eap_tvb = NULL;
GHashTable *vsa_buffer_table = NULL;
if (hf_radius_code == -1)
proto_registrar_get_byname("radius.code");
CLEANUP_PUSH_PFX(la, g_free, eap_buffer);
CLEANUP_PUSH_PFX(lb, vsa_buffer_table_destroy, (void *)vsa_buffer_table);
while (length > 0) {
radius_attr_info_t *dictionary_entry = NULL;
guint32 avp_type0 = 0, avp_type1 = 0;
radius_attr_type_t avp_type;
guint32 avp_length;
guint32 vendor_id;
gboolean avp_is_extended = FALSE;
int avp_offset_start = offset;
proto_item *avp_item;
proto_item *avp_len_item;
proto_tree *avp_tree;
if (length < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_radius_invalid_length, tvb, offset, 0,
"Not enough room in packet for AVP header");
break;
}
avp_type0 = tvb_get_guint8(tvb, offset);
avp_length = tvb_get_guint8(tvb, offset+1);
avp_is_extended = RADIUS_ATTR_TYPE_IS_EXTENDED(avp_type0);
if (avp_is_extended) {
avp_type1 = tvb_get_guint8(tvb, offset+2);
}
memset(&avp_type, 0, sizeof(avp_type));
avp_type.u8_code[0] = avp_type0;
avp_type.u8_code[1] = avp_type1;
if (avp_length < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_radius_invalid_length, tvb, offset, 0,
"AVP too short: length %u < 2", avp_length);
break;
}
if (avp_is_extended && avp_length < 3) {
proto_tree_add_expert_format(tree, pinfo, &ei_radius_invalid_length, tvb, offset, 0,
"Extended AVP too short: length %u < 3", avp_length);
break;
}
if (length < avp_length) {
proto_tree_add_expert_format(tree, pinfo, &ei_radius_invalid_length, tvb, offset, 0,
"Not enough room in packet for AVP");
break;
}
length -= avp_length;
dictionary_entry = (radius_attr_info_t *)g_hash_table_lookup(dict->attrs_by_id, GUINT_TO_POINTER(avp_type.value));
if (!dictionary_entry) {
dictionary_entry = &no_dictionary_entry;
}
avp_item = proto_tree_add_bytes_format_value(tree, hf_radius_avp, tvb, offset, avp_length,
NULL, "l=%u t=%s", avp_length,
dictionary_entry->name);
if (avp_is_extended)
proto_item_append_text(avp_item, "(%u.%u)", avp_type0, avp_type1);
else
proto_item_append_text(avp_item, "(%u)", avp_type0);
avp_length -= 2;
offset += 2;
if (avp_is_extended) {
avp_length -= 1;
offset += 1;
}
if (RADIUS_ATTR_TYPE_IS_EXTENDED_LONG(avp_type0)) {
avp_length -= 1;
offset += 1;
}
if (avp_type0 == RADIUS_ATTR_TYPE_VENDOR_SPECIFIC || (avp_is_extended && avp_type1 == RADIUS_ATTR_TYPE_VENDOR_SPECIFIC)) {
radius_vendor_info_t *vendor;
proto_tree *vendor_tree;
gint max_offset = offset + avp_length;
const gchar *vendor_str;
int vendor_offset;
if (avp_length < 4) {
expert_add_info_format(pinfo, avp_item, &ei_radius_invalid_length, "AVP too short; no room for vendor ID");
offset += avp_length;
continue;
}
vendor_id = tvb_get_ntohl(tvb, offset);
avp_length -= 4;
offset += 4;
vendor = (radius_vendor_info_t *)g_hash_table_lookup(dict->vendors_by_id, GUINT_TO_POINTER(vendor_id));
vendor_str = val_to_str_ext_const(vendor_id, &sminmpec_values_ext, "Unknown");
if (!vendor) {
vendor = &no_vendor;
}
proto_item_append_text(avp_item, " v=%s(%u)", vendor_str,
vendor_id);
vendor_tree = proto_item_add_subtree(avp_item, vendor->ett);
vendor_offset = avp_offset_start;
proto_tree_add_item(vendor_tree, hf_radius_avp_type, tvb, vendor_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(vendor_tree, hf_radius_avp_length, tvb, vendor_offset+1, 1, ENC_BIG_ENDIAN);
vendor_offset += 2;
if (avp_is_extended) {
proto_tree_add_item(vendor_tree, hf_radius_avp_extended_type, tvb, vendor_offset, 1, ENC_BIG_ENDIAN);
vendor_offset += 1;
}
if (RADIUS_ATTR_TYPE_IS_EXTENDED_LONG(avp_type0)) {
proto_tree_add_item(vendor_tree, hf_radius_avp_extended_more, tvb, vendor_offset, 1, ENC_BIG_ENDIAN);
vendor_offset += 1;
}
proto_tree_add_uint_format_value(vendor_tree, hf_radius_avp_vendor_id, tvb, vendor_offset, 4, vendor_id, "%s (%u)", vendor_str, vendor_id);
vendor_offset += 4;
while (offset < max_offset) {
guint32 avp_vsa_type;
guint32 avp_vsa_len;
guint8 avp_vsa_flags = 0;
guint32 avp_vsa_header_len;
switch (vendor->type_octets) {
case 1:
avp_vsa_type = tvb_get_guint8(tvb, offset++);
break;
case 2:
avp_vsa_type = tvb_get_ntohs(tvb, offset);
offset += 2;
break;
case 4:
avp_vsa_type = tvb_get_ntohl(tvb, offset);
offset += 4;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
if (!avp_is_extended) {
switch (vendor->length_octets) {
case 1:
avp_vsa_len = tvb_get_guint8(tvb, offset++);
break;
case 0:
avp_vsa_len = avp_length;
break;
case 2:
avp_vsa_len = tvb_get_ntohs(tvb, offset);
offset += 2;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
avp_vsa_header_len = vendor->type_octets + vendor->length_octets + (vendor->has_flags ? 1 : 0);
} else {
avp_vsa_len = avp_length;
avp_vsa_header_len = vendor->type_octets + (vendor->has_flags ? 1 : 0);
}
if (vendor->has_flags) {
avp_vsa_flags = tvb_get_guint8(tvb, offset++);
}
if (avp_vsa_len < avp_vsa_header_len) {
proto_tree_add_expert_format(tree, pinfo, &ei_radius_invalid_length, tvb, offset+1, 1,
"VSA too short");
break;
}
avp_vsa_len -= avp_vsa_header_len;
if (vendor->attrs_by_id && !avp_is_extended) {
dictionary_entry = (radius_attr_info_t *)g_hash_table_lookup(vendor->attrs_by_id, GUINT_TO_POINTER(avp_vsa_type));
} else {
dictionary_entry = NULL;
}
if (!dictionary_entry) {
dictionary_entry = &no_dictionary_entry;
}
if (vendor->has_flags) {
avp_tree = proto_tree_add_subtree_format(vendor_tree, tvb, offset-avp_vsa_header_len, avp_vsa_len+avp_vsa_header_len,
dictionary_entry->ett, &avp_item, "VSA: l=%u t=%s(%u) C=0x%02x",
avp_vsa_len+avp_vsa_header_len, dictionary_entry->name, avp_vsa_type, avp_vsa_flags);
} else {
avp_tree = proto_tree_add_subtree_format(vendor_tree, tvb, offset-avp_vsa_header_len, avp_vsa_len+avp_vsa_header_len,
dictionary_entry->ett, &avp_item, "VSA: l=%u t=%s(%u)",
avp_vsa_len+avp_vsa_header_len, dictionary_entry->name, avp_vsa_type);
}
proto_tree_add_item(avp_tree, hf_radius_avp_vendor_type, tvb, vendor_offset, vendor->type_octets, ENC_BIG_ENDIAN);
vendor_offset += vendor->type_octets;
if (!avp_is_extended && vendor->length_octets) {
proto_tree_add_item(avp_tree, hf_radius_avp_vendor_len, tvb, vendor_offset, vendor->length_octets, ENC_BIG_ENDIAN);
}
if (show_length) {
avp_len_item = proto_tree_add_uint(avp_tree,
dictionary_entry->hf_len,
tvb, 0, 0, avp_length);
PROTO_ITEM_SET_GENERATED(avp_len_item);
}
if (vendor->has_flags) {
radius_vsa_buffer_key key;
radius_vsa_buffer *vsa_buffer = NULL;
key.vendor_id = vendor_id;
key.vsa_type = avp_vsa_type;
if (!vsa_buffer_table) {
vsa_buffer_table = g_hash_table_new(radius_vsa_hash, radius_vsa_equal);
}
vsa_buffer = (radius_vsa_buffer *)g_hash_table_lookup(vsa_buffer_table, &key);
if (vsa_buffer) {
vsa_buffer->data = (guint8 *)g_realloc(vsa_buffer->data, vsa_buffer->len + avp_vsa_len);
tvb_memcpy(tvb, vsa_buffer->data + vsa_buffer->len, offset, avp_vsa_len);
vsa_buffer->len += avp_vsa_len;
vsa_buffer->seg_num++;
}
if (avp_vsa_flags & 0x80) {
if (!vsa_buffer) {
vsa_buffer = (radius_vsa_buffer *)g_malloc(sizeof(radius_vsa_buffer));
vsa_buffer->key.vendor_id = vendor_id;
vsa_buffer->key.vsa_type = avp_vsa_type;
vsa_buffer->len = avp_vsa_len;
vsa_buffer->seg_num = 1;
vsa_buffer->data = (guint8 *)g_malloc(avp_vsa_len);
tvb_memcpy(tvb, vsa_buffer->data, offset, avp_vsa_len);
g_hash_table_insert(vsa_buffer_table, &(vsa_buffer->key), vsa_buffer);
}
proto_tree_add_item(avp_tree, hf_radius_vsa_fragment, tvb, offset, avp_vsa_len, ENC_NA);
proto_item_append_text(avp_item, ": VSA fragment[%u]", vsa_buffer->seg_num);
} else {
if (vsa_buffer) {
tvbuff_t *vsa_tvb = NULL;
proto_tree_add_item(avp_tree, hf_radius_vsa_fragment, tvb, offset, avp_vsa_len, ENC_NA);
proto_item_append_text(avp_item, ": Last VSA fragment[%u]", vsa_buffer->seg_num);
vsa_tvb = tvb_new_child_real_data(tvb, vsa_buffer->data, vsa_buffer->len, vsa_buffer->len);
tvb_set_free_cb(vsa_tvb, g_free);
add_new_data_source(pinfo, vsa_tvb, "Reassembled VSA");
add_avp_to_tree(avp_tree, avp_item, pinfo, vsa_tvb, dictionary_entry, vsa_buffer->len, 0);
g_hash_table_remove(vsa_buffer_table, &(vsa_buffer->key));
g_free(vsa_buffer);
} else {
add_avp_to_tree(avp_tree, avp_item, pinfo, tvb, dictionary_entry, avp_vsa_len, offset);
}
}
} else {
add_avp_to_tree(avp_tree, avp_item, pinfo, tvb, dictionary_entry, avp_vsa_len, offset);
}
offset += avp_vsa_len;
}
continue;
}
avp_tree = proto_item_add_subtree(avp_item, dictionary_entry->ett);
proto_tree_add_item(avp_tree, hf_radius_avp_type, tvb, avp_offset_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(avp_tree, hf_radius_avp_length, tvb, avp_offset_start+1, 1, ENC_BIG_ENDIAN);
if (show_length) {
avp_len_item = proto_tree_add_uint(avp_tree,
dictionary_entry->hf_len,
tvb, 0, 0, avp_length);
PROTO_ITEM_SET_GENERATED(avp_len_item);
}
if (avp_is_extended) {
proto_tree_add_item(avp_tree, hf_radius_avp_extended_type, tvb, avp_offset_start+2, 1, ENC_BIG_ENDIAN);
}
if (RADIUS_ATTR_TYPE_IS_EXTENDED_LONG(avp_type0)) {
proto_tree_add_item(avp_tree, hf_radius_avp_extended_more, tvb, avp_offset_start+3, 1, ENC_BIG_ENDIAN);
}
if (avp_type0 == RADIUS_ATTR_TYPE_EAP_MESSAGE) {
gint tvb_len;
eap_seg_num++;
tvb_len = tvb_captured_length_remaining(tvb, offset);
if ((gint)avp_length < tvb_len)
tvb_len = avp_length;
proto_tree_add_item(avp_tree, hf_radius_eap_fragment, tvb, offset, tvb_len, ENC_NA);
if (eap_tvb != NULL) {
proto_item_append_text(avp_item, " (non-consecutive)");
} else {
if (eap_buffer == NULL)
eap_buffer = (guint8 *)g_malloc(eap_tot_len_captured + tvb_len);
else
eap_buffer = (guint8 *)g_realloc(eap_buffer,
eap_tot_len_captured + tvb_len);
tvb_memcpy(tvb, eap_buffer + eap_tot_len_captured, offset,
tvb_len);
eap_tot_len_captured += tvb_len;
eap_tot_len += avp_length;
if (tvb_bytes_exist(tvb, offset + avp_length + 1, 1)) {
guint8 next_type = tvb_get_guint8(tvb, offset + avp_length);
if (next_type != RADIUS_ATTR_TYPE_EAP_MESSAGE) {
last_eap = TRUE;
}
} else {
last_eap = TRUE;
}
if (last_eap && eap_buffer) {
gboolean save_writable;
proto_item_append_text(avp_item, " Last Segment[%u]",
eap_seg_num);
eap_tree = proto_item_add_subtree(avp_item, ett_eap);
eap_tvb = tvb_new_child_real_data(tvb, eap_buffer,
eap_tot_len_captured,
eap_tot_len);
tvb_set_free_cb(eap_tvb, g_free);
add_new_data_source(pinfo, eap_tvb, "Reassembled EAP");
eap_buffer = NULL;
save_writable = col_get_writable(pinfo->cinfo, -1);
col_set_writable(pinfo->cinfo, -1, FALSE);
call_dissector(eap_handle, eap_tvb, pinfo, eap_tree);
col_set_writable(pinfo->cinfo, -1, save_writable);
} else {
proto_item_append_text(avp_item, " Segment[%u]",
eap_seg_num);
}
}
offset += avp_length;
continue;
}
add_avp_to_tree(avp_tree, avp_item, pinfo, tvb, dictionary_entry,
avp_length, offset);
offset += avp_length;
}
CLEANUP_CALL_AND_POP_PFX(lb);
CLEANUP_CALL_AND_POP_PFX(la);
}
static gboolean
is_radius(tvbuff_t *tvb)
{
guint8 code;
guint16 length;
code = tvb_get_guint8(tvb, 0);
if (try_val_to_str_ext(code, &radius_pkt_type_codes_ext) == NULL) {
return FALSE;
}
length = tvb_get_ntohs(tvb, 2);
if ((length < 20) || (length > 4096)) {
return FALSE;
}
return TRUE;
}
static gboolean
valid_authenticator(tvbuff_t *tvb, guint8 request_authenticator[])
{
gcry_md_hd_t md5_handle;
guint8 *digest;
gboolean result;
guint tvb_length;
guint8 *payload;
tvb_length = tvb_captured_length(tvb);
payload = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, 0, tvb_length);
memcpy(payload+4, request_authenticator, AUTHENTICATOR_LENGTH);
if (gcry_md_open(&md5_handle, GCRY_MD_MD5, 0)) {
return FALSE;
}
gcry_md_write(md5_handle, payload, tvb_length);
gcry_md_write(md5_handle, shared_secret, strlen(shared_secret));
digest = gcry_md_read(md5_handle, 0);
result = !memcmp(digest, authenticator, AUTHENTICATOR_LENGTH);
gcry_md_close(md5_handle);
return result;
}
static int
dissect_radius(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *radius_tree = NULL;
proto_tree *avptree = NULL;
proto_item *ti, *hidden_item, *authenticator_item = NULL;
guint avplength;
e_radiushdr rh;
radius_info_t *rad_info;
conversation_t *conversation;
radius_call_info_key radius_call_key;
radius_call_info_key *new_radius_call_key;
wmem_tree_t *radius_call_tree;
radius_call_t *radius_call = NULL;
static address null_address = ADDRESS_INIT_NONE;
if (!is_radius(tvb)) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RADIUS");
col_clear(pinfo->cinfo, COL_INFO);
rh.rh_code = tvb_get_guint8(tvb, 0);
rh.rh_ident = tvb_get_guint8(tvb, 1);
rh.rh_pktlength = tvb_get_ntohs(tvb, 2);
rad_info = wmem_new(wmem_packet_scope(), radius_info_t);
rad_info->code = 0;
rad_info->ident = 0;
rad_info->req_time.secs = 0;
rad_info->req_time.nsecs = 0;
rad_info->is_duplicate = FALSE;
rad_info->request_available = FALSE;
rad_info->req_num = 0;
rad_info->rspcode = 0;
rad_info->code = rh.rh_code;
rad_info->ident = rh.rh_ident;
tap_queue_packet(radius_tap, pinfo, rad_info);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s(%d) (id=%d, l=%d)",
val_to_str_ext_const(rh.rh_code, &radius_pkt_type_codes_ext, "Unknown Packet"),
rh.rh_code, rh.rh_ident, rh.rh_pktlength);
if (hf_radius_code == -1)
proto_registrar_get_byname("radius.code");
ti = proto_tree_add_item(tree, proto_radius, tvb, 0, rh.rh_pktlength, ENC_NA);
radius_tree = proto_item_add_subtree(ti, ett_radius);
proto_tree_add_uint(radius_tree, hf_radius_code, tvb, 0, 1, rh.rh_code);
proto_tree_add_uint_format(radius_tree, hf_radius_id, tvb, 1, 1, rh.rh_ident,
"Packet identifier: 0x%01x (%d)", rh.rh_ident, rh.rh_ident);
if (rh.rh_pktlength < HDR_LENGTH) {
proto_tree_add_uint_format_value(radius_tree, hf_radius_length,
tvb, 2, 2, rh.rh_pktlength, "%u (bogus, < %u)",
rh.rh_pktlength, HDR_LENGTH);
return tvb_captured_length(tvb);
}
avplength = rh.rh_pktlength - HDR_LENGTH;
proto_tree_add_uint(radius_tree, hf_radius_length, tvb, 2, 2, rh.rh_pktlength);
authenticator_item = proto_tree_add_item(radius_tree, hf_radius_authenticator, tvb, 4, AUTHENTICATOR_LENGTH, ENC_NA);
tvb_memcpy(tvb, authenticator, 4, AUTHENTICATOR_LENGTH);
switch (rh.rh_code)
{
case RADIUS_PKT_TYPE_ACCESS_REQUEST:
case RADIUS_PKT_TYPE_ACCOUNTING_REQUEST:
case RADIUS_PKT_TYPE_PASSWORD_REQUEST:
case RADIUS_PKT_TYPE_RESOURCE_FREE_REQUEST:
case RADIUS_PKT_TYPE_RESOURCE_QUERY_REQUEST:
case RADIUS_PKT_TYPE_NAS_REBOOT_REQUEST:
case RADIUS_PKT_TYPE_EVENT_REQUEST:
case RADIUS_PKT_TYPE_DISCONNECT_REQUEST:
case RADIUS_PKT_TYPE_COA_REQUEST:
case RADIUS_PKT_TYPE_ALU_STATE_REQUEST:
if (pinfo->flags.in_error_pkt)
break;
hidden_item = proto_tree_add_boolean(radius_tree, hf_radius_req, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
conversation = find_conversation(pinfo->num, &pinfo->src,
&null_address, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation == NULL)
{
conversation = conversation_new(pinfo->num, &pinfo->src,
&null_address, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
}
radius_call_key.code = rh.rh_code;
radius_call_key.ident = rh.rh_ident;
radius_call_key.conversation = conversation;
radius_call_key.req_time = pinfo->abs_ts;
radius_call_tree = (wmem_tree_t *)wmem_map_lookup(radius_calls, &radius_call_key);
if (!radius_call_tree) {
radius_call_tree = wmem_tree_new(wmem_file_scope());
new_radius_call_key = wmem_new(wmem_file_scope(), radius_call_info_key);
*new_radius_call_key = radius_call_key;
wmem_map_insert(radius_calls, new_radius_call_key, radius_call_tree);
}
radius_call = (radius_call_t *)wmem_tree_lookup32_le(radius_call_tree, pinfo->num);
if (radius_call != NULL) {
if (pinfo->num != radius_call->req_num &&
!memcmp(radius_call->req_authenticator, authenticator, AUTHENTICATOR_LENGTH)) {
rad_info->is_duplicate = TRUE;
rad_info->req_num = radius_call->req_num;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Duplicate Request");
if (tree) {
proto_item *item;
hidden_item = proto_tree_add_uint(radius_tree, hf_radius_dup, tvb, 0, 0, rh.rh_ident);
PROTO_ITEM_SET_HIDDEN(hidden_item);
item = proto_tree_add_uint(radius_tree, hf_radius_req_dup, tvb, 0, 0, radius_call->req_num);
PROTO_ITEM_SET_GENERATED(item);
}
}
}
if (!PINFO_FD_VISITED(pinfo) && (radius_call == NULL || !rad_info->is_duplicate)) {
radius_call = wmem_new(wmem_file_scope(), radius_call_t);
radius_call->req_num = pinfo->num;
radius_call->rsp_num = 0;
radius_call->ident = rh.rh_ident;
radius_call->code = rh.rh_code;
memcpy(radius_call->req_authenticator, authenticator, AUTHENTICATOR_LENGTH);
radius_call->responded = FALSE;
radius_call->req_time = pinfo->abs_ts;
radius_call->rspcode = 0;
wmem_tree_insert32(radius_call_tree, pinfo->num, radius_call);
}
if (radius_call && radius_call->rsp_num) {
proto_item *item;
item = proto_tree_add_uint_format(radius_tree,
hf_radius_rsp_frame, tvb, 0, 0, radius_call->rsp_num,
"The response to this request is in frame %u",
radius_call->rsp_num);
PROTO_ITEM_SET_GENERATED(item);
}
break;
case RADIUS_PKT_TYPE_ACCESS_ACCEPT:
case RADIUS_PKT_TYPE_ACCESS_REJECT:
case RADIUS_PKT_TYPE_ACCOUNTING_RESPONSE:
case RADIUS_PKT_TYPE_PASSWORD_ACK:
case RADIUS_PKT_TYPE_PASSWORD_REJECT:
case RADIUS_PKT_TYPE_RESOURCE_FREE_RESPONSE:
case RADIUS_PKT_TYPE_RESOURCE_QUERY_RESPONSE:
case RADIUS_PKT_TYPE_NAS_REBOOT_RESPONSE:
case RADIUS_PKT_TYPE_EVENT_RESPONSE:
case RADIUS_PKT_TYPE_DISCONNECT_ACK:
case RADIUS_PKT_TYPE_DISCONNECT_NAK:
case RADIUS_PKT_TYPE_COA_ACK:
case RADIUS_PKT_TYPE_COA_NAK:
case RADIUS_PKT_TYPE_ACCESS_CHALLENGE:
case RADIUS_PKT_TYPE_ALU_STATE_ACCEPT:
case RADIUS_PKT_TYPE_ALU_STATE_REJECT:
case RADIUS_PKT_TYPE_ALU_STATE_ERROR:
if (pinfo->flags.in_error_pkt)
break;
hidden_item = proto_tree_add_boolean(radius_tree, hf_radius_rsp, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
conversation = find_conversation(pinfo->num, &null_address,
&pinfo->dst, pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if (conversation == NULL) {
break;
}
radius_call_key.code = rh.rh_code;
radius_call_key.ident = rh.rh_ident;
radius_call_key.conversation = conversation;
radius_call_key.req_time = pinfo->abs_ts;
radius_call_tree = (wmem_tree_t *)wmem_map_lookup(radius_calls, &radius_call_key);
if (radius_call_tree == NULL) {
break;
}
radius_call = (radius_call_t *)wmem_tree_lookup32_le(radius_call_tree, pinfo->num);
if (radius_call == NULL) {
break;
}
if (radius_call->req_num) {
nstime_t delta;
proto_item *item;
rad_info->request_available = TRUE;
rad_info->req_num = radius_call->req_num;
radius_call->responded = TRUE;
item = proto_tree_add_uint_format(radius_tree,
hf_radius_req_frame, tvb, 0, 0,
radius_call->req_num,
"This is a response to a request in frame %u",
radius_call->req_num);
PROTO_ITEM_SET_GENERATED(item);
nstime_delta(&delta, &pinfo->abs_ts, &radius_call->req_time);
item = proto_tree_add_time(radius_tree, hf_radius_time, tvb, 0, 0, &delta);
PROTO_ITEM_SET_GENERATED(item);
if (validate_authenticator && *shared_secret != '\0') {
proto_item *authenticator_tree;
int valid;
valid = valid_authenticator(tvb, radius_call->req_authenticator);
proto_item_append_text(authenticator_item, " [%s]", valid? "correct" : "incorrect");
authenticator_tree = proto_item_add_subtree(authenticator_item, ett_radius_authenticator);
item = proto_tree_add_boolean(authenticator_tree, hf_radius_authenticator_valid, tvb, 4, AUTHENTICATOR_LENGTH, valid ? TRUE : FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(authenticator_tree, hf_radius_authenticator_invalid, tvb, 4, AUTHENTICATOR_LENGTH, valid ? FALSE : TRUE);
PROTO_ITEM_SET_GENERATED(item);
if (!valid) {
col_append_fstr(pinfo->cinfo, COL_INFO, " [incorrect authenticator]");
}
}
}
if (radius_call->rsp_num == 0) {
radius_call->rsp_num = pinfo->num;
} else {
if ((radius_call->rsp_num != pinfo->num) && (radius_call->rspcode == rh.rh_code)) {
rad_info->is_duplicate = TRUE;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Duplicate Response");
if (tree) {
proto_item *item;
hidden_item = proto_tree_add_uint(radius_tree,
hf_radius_dup, tvb, 0, 0, rh.rh_ident);
PROTO_ITEM_SET_HIDDEN(hidden_item);
item = proto_tree_add_uint(radius_tree,
hf_radius_rsp_dup, tvb, 0, 0, radius_call->rsp_num);
PROTO_ITEM_SET_GENERATED(item);
}
}
}
radius_call->rspcode = rh.rh_code;
rad_info->rspcode = rh.rh_code;
break;
default:
break;
}
if (radius_call) {
rad_info->req_time = radius_call->req_time;
}
if (avplength > 0) {
avptree = proto_tree_add_subtree(radius_tree, tvb, HDR_LENGTH,
avplength, ett_radius_avp, NULL, "Attribute Value Pairs");
dissect_attribute_value_pairs(avptree, pinfo, tvb, HDR_LENGTH,
avplength);
}
return tvb_captured_length(tvb);
}
void
free_radius_attr_info(gpointer data)
{
radius_attr_info_t* attr = (radius_attr_info_t*)data;
value_string *vs = (value_string *)attr->vs;
g_free(attr->name);
if (attr->tlvs_by_id) {
g_hash_table_destroy(attr->tlvs_by_id);
}
if (vs) {
for (; vs->strptr; vs++) {
g_free((gpointer)vs->strptr);
}
g_free((gpointer)attr->vs);
}
g_free(attr);
}
static void
free_radius_vendor_info(gpointer data)
{
radius_vendor_info_t* vendor = (radius_vendor_info_t*)data;
g_free(vendor->name);
if (vendor->attrs_by_id)
g_hash_table_destroy(vendor->attrs_by_id);
g_free(vendor);
}
static void
register_attrs(gpointer k _U_, gpointer v, gpointer p)
{
radius_attr_info_t *a = (radius_attr_info_t *)v;
int i;
gint *ett = &(a->ett);
gchar *abbrev = wmem_strdup_printf(wmem_epan_scope(), "radius.%s", a->name);
hf_register_info hfri[] = {
{ NULL, { NULL, NULL, FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ NULL, { NULL, NULL, FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ NULL, { NULL, NULL, FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ NULL, { NULL, NULL, FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
guint len_hf = 2;
hfett_t *ri = (hfett_t *)p;
for(i=0; abbrev[i]; i++) {
if (abbrev[i] == '-') abbrev[i] = '_';
if (abbrev[i] == '/') abbrev[i] = '_';
}
hfri[0].p_id = &(a->hf);
hfri[1].p_id = &(a->hf_len);
hfri[0].hfinfo.name = a->name;
hfri[0].hfinfo.abbrev = abbrev;
hfri[1].hfinfo.name = "Length";
hfri[1].hfinfo.abbrev = wmem_strdup_printf(wmem_epan_scope(), "%s.len", abbrev);
hfri[1].hfinfo.blurb = wmem_strdup_printf(wmem_epan_scope(), "%s Length", a->name);
if (a->type == radius_integer) {
hfri[0].hfinfo.type = FT_UINT32;
hfri[0].hfinfo.display = BASE_DEC;
hfri[2].p_id = &(a->hf_alt);
hfri[2].hfinfo.name = wmem_strdup(wmem_epan_scope(), a->name);
hfri[2].hfinfo.abbrev = abbrev;
hfri[2].hfinfo.type = FT_UINT64;
hfri[2].hfinfo.display = BASE_DEC;
if (a->vs) {
hfri[0].hfinfo.strings = VALS(a->vs);
}
len_hf++;
} else if (a->type == radius_signed) {
hfri[0].hfinfo.type = FT_INT32;
hfri[0].hfinfo.display = BASE_DEC;
hfri[2].p_id = &(a->hf_alt);
hfri[2].hfinfo.name = wmem_strdup(wmem_epan_scope(), a->name);
hfri[2].hfinfo.abbrev = abbrev;
hfri[2].hfinfo.type = FT_INT64;
hfri[2].hfinfo.display = BASE_DEC;
if (a->vs) {
hfri[0].hfinfo.strings = VALS(a->vs);
}
len_hf++;
} else if (a->type == radius_string) {
hfri[0].hfinfo.type = FT_STRING;
hfri[0].hfinfo.display = BASE_NONE;
if (a->encrypt != 0) {
hfri[2].p_id = &(a->hf_alt);
hfri[2].hfinfo.name = wmem_strdup_printf(wmem_epan_scope(), "%s (encrypted)", a->name);
hfri[2].hfinfo.abbrev = wmem_strdup_printf(wmem_epan_scope(), "%s_encrypted", abbrev);
hfri[2].hfinfo.type = FT_BYTES;
hfri[2].hfinfo.display = BASE_NONE;
len_hf++;
}
} else if (a->type == radius_octets) {
hfri[0].hfinfo.type = FT_BYTES;
hfri[0].hfinfo.display = BASE_NONE;
} else if (a->type == radius_ipaddr) {
hfri[0].hfinfo.type = FT_IPv4;
hfri[0].hfinfo.display = BASE_NONE;
} else if (a->type == radius_ipv6addr) {
hfri[0].hfinfo.type = FT_IPv6;
hfri[0].hfinfo.display = BASE_NONE;
} else if (a->type == radius_ipv6prefix) {
hfri[0].hfinfo.type = FT_BYTES;
hfri[0].hfinfo.display = BASE_NONE;
} else if (a->type == radius_ipxnet) {
hfri[0].hfinfo.type = FT_IPXNET;
hfri[0].hfinfo.display = BASE_NONE;
} else if (a->type == radius_date) {
hfri[0].hfinfo.type = FT_ABSOLUTE_TIME;
hfri[0].hfinfo.display = ABSOLUTE_TIME_LOCAL;
} else if (a->type == radius_abinary) {
hfri[0].hfinfo.type = FT_BYTES;
hfri[0].hfinfo.display = BASE_NONE;
} else if (a->type == radius_ifid) {
hfri[0].hfinfo.type = FT_BYTES;
hfri[0].hfinfo.display = BASE_NONE;
} else if (a->type == radius_combo_ip) {
hfri[0].hfinfo.type = FT_IPv4;
hfri[0].hfinfo.display = BASE_NONE;
hfri[2].p_id = &(a->hf_alt);
hfri[2].hfinfo.name = wmem_strdup(wmem_epan_scope(), a->name);
hfri[2].hfinfo.abbrev = wmem_strdup(wmem_epan_scope(), abbrev);
hfri[2].hfinfo.type = FT_IPv6;
hfri[2].hfinfo.display = BASE_NONE;
len_hf++;
#if 0
} else if (a->type == radius_tlv) {
hfri[0].hfinfo.type = FT_BYTES;
hfri[0].hfinfo.display = BASE_NONE;
#endif
} else {
hfri[0].hfinfo.type = FT_BYTES;
hfri[0].hfinfo.display = BASE_NONE;
}
if (a->tagged) {
hfri[len_hf].p_id = &(a->hf_tag);
hfri[len_hf].hfinfo.name = "Tag";
hfri[len_hf].hfinfo.abbrev = wmem_strdup_printf(wmem_epan_scope(), "%s.tag", abbrev);
hfri[len_hf].hfinfo.blurb = wmem_strdup_printf(wmem_epan_scope(), "%s Tag", a->name);
hfri[len_hf].hfinfo.type = FT_UINT8;
hfri[len_hf].hfinfo.display = BASE_HEX;
len_hf++;
}
wmem_array_append(ri->hf, hfri, len_hf);
wmem_array_append_one(ri->ett, ett);
if (a->tlvs_by_id) {
g_hash_table_foreach(a->tlvs_by_id, register_attrs, ri);
}
}
static void
register_vendors(gpointer k _U_, gpointer v, gpointer p)
{
radius_vendor_info_t *vnd = (radius_vendor_info_t *)v;
hfett_t *ri = (hfett_t *)p;
value_string vnd_vs;
gint *ett_p = &(vnd->ett);
vnd_vs.value = vnd->code;
vnd_vs.strptr = vnd->name;
wmem_array_append_one(ri->vend_vs, vnd_vs);
wmem_array_append_one(ri->ett, ett_p);
g_hash_table_foreach(vnd->attrs_by_id, register_attrs, ri);
}
extern void
radius_register_avp_dissector(guint32 vendor_id, guint32 _attribute_id, radius_avp_dissector_t radius_avp_dissector)
{
radius_vendor_info_t *vendor;
radius_attr_info_t *dictionary_entry;
GHashTable *by_id;
radius_attr_type_t attribute_id;
DISSECTOR_ASSERT(radius_avp_dissector != NULL);
memset(&attribute_id, 0, sizeof(attribute_id));
attribute_id.u8_code[0] = _attribute_id;
if (vendor_id) {
vendor = (radius_vendor_info_t *)g_hash_table_lookup(dict->vendors_by_id, GUINT_TO_POINTER(vendor_id));
if (!vendor) {
vendor = (radius_vendor_info_t *)g_malloc(sizeof(radius_vendor_info_t));
vendor->name = g_strdup_printf("%s-%u",
val_to_str_ext_const(vendor_id, &sminmpec_values_ext, "Unknown"),
vendor_id);
vendor->code = vendor_id;
vendor->attrs_by_id = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, free_radius_attr_info);
vendor->ett = no_vendor.ett;
vendor->type_octets = 1;
vendor->length_octets = 1;
vendor->has_flags = FALSE;
g_hash_table_insert(dict->vendors_by_id, GUINT_TO_POINTER(vendor->code), vendor);
g_hash_table_insert(dict->vendors_by_name, (gpointer)(vendor->name), vendor);
}
dictionary_entry = (radius_attr_info_t *)g_hash_table_lookup(vendor->attrs_by_id, GUINT_TO_POINTER(attribute_id.value));
by_id = vendor->attrs_by_id;
} else {
dictionary_entry = (radius_attr_info_t *)g_hash_table_lookup(dict->attrs_by_id, GUINT_TO_POINTER(attribute_id.value));
by_id = dict->attrs_by_id;
}
if (!dictionary_entry) {
dictionary_entry = (radius_attr_info_t *)g_malloc(sizeof(radius_attr_info_t));
dictionary_entry->name = g_strdup_printf("Unknown-Attribute-%u", attribute_id.value);
dictionary_entry->code = attribute_id;
dictionary_entry->encrypt = 0;
dictionary_entry->type = NULL;
dictionary_entry->vs = NULL;
dictionary_entry->hf = no_dictionary_entry.hf;
dictionary_entry->tagged = 0;
dictionary_entry->hf_tag = -1;
dictionary_entry->hf_len = no_dictionary_entry.hf_len;
dictionary_entry->ett = no_dictionary_entry.ett;
dictionary_entry->tlvs_by_id = NULL;
g_hash_table_insert(by_id, GUINT_TO_POINTER(dictionary_entry->code.value), dictionary_entry);
}
dictionary_entry->dissector = radius_avp_dissector;
}
static void
radius_init_protocol(void)
{
module_t *radius_module = prefs_find_module("radius");
pref_t *alternate_port;
if (radius_module) {
alternate_port = prefs_find_preference(radius_module, "alternate_port");
if (! prefs_get_preference_obsolete(alternate_port))
prefs_set_preference_obsolete(alternate_port);
}
}
static void
radius_shutdown(void)
{
if (dict != NULL) {
g_hash_table_destroy(dict->attrs_by_id);
g_hash_table_destroy(dict->attrs_by_name);
g_hash_table_destroy(dict->vendors_by_id);
g_hash_table_destroy(dict->vendors_by_name);
g_hash_table_destroy(dict->tlvs_by_name);
g_free(dict);
}
}
static void
register_radius_fields(const char *unused _U_)
{
hf_register_info base_hf[] = {
{ &hf_radius_req,
{ "Request", "radius.req", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if RADIUS request", HFILL }},
{ &hf_radius_rsp,
{ "Response", "radius.rsp", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if RADIUS response", HFILL }},
{ &hf_radius_req_frame,
{ "Request Frame", "radius.reqframe", FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_REQUEST), 0,
NULL, HFILL }},
{ &hf_radius_rsp_frame,
{ "Response Frame", "radius.rspframe", FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_RESPONSE), 0,
NULL, HFILL }},
{ &hf_radius_time,
{ "Time from request", "radius.time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0,
"Timedelta between Request and Response", HFILL }},
{ &hf_radius_code,
{ "Code", "radius.code", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &radius_pkt_type_codes_ext, 0x0,
NULL, HFILL }},
{ &hf_radius_id,
{ "Identifier", "radius.id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_authenticator,
{ "Authenticator", "radius.authenticator", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_authenticator_valid,
{ "Valid Authenticator", "radius.authenticator.valid", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if Authenticator is valid", HFILL }},
{ &hf_radius_authenticator_invalid,
{ "Invalid Authenticator", "radius.authenticator.invalid", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if Authenticator is invalid", HFILL }},
{ &hf_radius_length,
{ "Length", "radius.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &(no_dictionary_entry.hf),
{ "Unknown-Attribute", "radius.Unknown_Attribute", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &(no_dictionary_entry.hf_len),
{ "Unknown-Attribute Length", "radius.Unknown_Attribute.length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_chap_password,
{ "CHAP-Password", "radius.CHAP_Password", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_chap_ident,
{ "CHAP Ident", "radius.CHAP_Ident", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_chap_string,
{ "CHAP String", "radius.CHAP_String", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_framed_ip_address,
{ "Framed-IP-Address", "radius.Framed-IP-Address", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_login_ip_host,
{ "Login-IP-Host", "radius.Login-IP-Host", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_framed_ipx_network,
{ "Framed-IPX-Network", "radius.Framed-IPX-Network", FT_IPXNET, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_cosine_vpi,
{ "Cosine-VPI", "radius.Cosine-Vpi", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_cosine_vci,
{ "Cosine-VCI", "radius.Cosine-Vci", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_dup,
{ "Duplicate Message ID", "radius.dup", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_req_dup,
{ "Duplicate Request Frame Number", "radius.req.dup", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_rsp_dup,
{ "Duplicate Response Frame Number", "radius.rsp.dup", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter,
{ "Ascend Data Filter", "radius.ascenddatafilter", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_type,
{ "Type", "radius.ascenddatafilter.type", FT_UINT8, BASE_DEC, VALS(ascenddf_filtertype), 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_filteror,
{ "Filter or forward", "radius.ascenddatafilter.filteror", FT_UINT8, BASE_DEC, VALS(ascenddf_filteror), 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_inout,
{ "Indirection", "radius.ascenddatafilter.inout", FT_UINT8, BASE_DEC, VALS(ascenddf_inout), 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_spare,
{ "Spare", "radius.ascenddatafilter.spare", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_src_ipv4,
{ "Source IPv4 address", "radius.ascenddatafilter.src_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_dst_ipv4,
{ "Destination IPv4 address", "radius.ascenddatafilter.dst_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_src_ipv6,
{ "Source IPv6 address", "radius.ascenddatafilter.src_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_dst_ipv6,
{ "Destination IPv6 address", "radius.ascenddatafilter.dst_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_src_ip_prefix,
{ "Source IP prefix", "radius.ascenddatafilter.src_prefix_ip", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_dst_ip_prefix,
{ "Destination IP prefix", "radius.ascenddatafilter.dst_prefix_ip", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_protocol,
{ "Protocol", "radius.ascenddatafilter.protocol", FT_UINT8, BASE_DEC, VALS(ascenddf_proto), 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_established,
{ "Established", "radius.ascenddatafilter.established", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_src_port,
{ "Source Port", "radius.ascenddatafilter.src_port", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_dst_port,
{ "Destination Port", "radius.ascenddatafilter.dst_port", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_src_port_qualifier,
{ "Source Port Qualifier", "radius.ascenddatafilter.src_port_qualifier", FT_UINT8, BASE_DEC, VALS(ascenddf_portq), 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_dst_port_qualifier,
{ "Destination Port Qualifier", "radius.ascenddatafilter.dst_port_qualifier", FT_UINT8, BASE_DEC, VALS(ascenddf_portq), 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter_reserved,
{ "Reserved", "radius.ascenddatafilter.reserved", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_vsa_fragment,
{ "VSA fragment", "radius.vsa_fragment", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_eap_fragment,
{ "EAP fragment", "radius.eap_fragment", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_avp,
{ "AVP", "radius.avp", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_avp_length,
{ "AVP Length", "radius.avp.length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_avp_type,
{ "AVP Type", "radius.avp.type", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_avp_vendor_id,
{ "AVP Vendor ID", "radius.avp.vendor_id", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_avp_vendor_type,
{ "VSA Type", "radius.avp.vendor_type", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_avp_vendor_len,
{ "VSA Length", "radius.avp.vendor_len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_avp_extended_type,
{ "AVP Extended Type", "radius.avp.extended_type", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_avp_extended_more,
{ "AVP Extended More", "radius.avp.extended_more", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x80,
NULL, HFILL }},
{ &hf_radius_egress_vlanid_tag,
{ "Tag", "radius.egress_vlanid_tag", FT_UINT32, BASE_HEX, VALS(egress_vlan_tag_vals), 0xFF000000,
NULL, HFILL }},
{ &hf_radius_egress_vlanid_pad,
{ "Pad", "radius.egress_vlanid_pad", FT_UINT32, BASE_HEX, NULL, 0x00FFF000,
NULL, HFILL }},
{ &hf_radius_egress_vlanid,
{ "Vlan ID", "radius.egress_vlanid", FT_UINT32, BASE_DEC, NULL, 0x00000FFF,
NULL, HFILL }},
{ &hf_radius_egress_vlan_name_tag,
{ "Tag", "radius.egress_vlan_name_tag", FT_UINT8, BASE_HEX, VALS(egress_vlan_tag_vals), 0x0,
NULL, HFILL }},
{ &hf_radius_egress_vlan_name,
{ "Vlan Name", "radius.egress_vlan_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_3gpp_ms_tmime_zone,
{ "Timezone", "radius.3gpp_ms_tmime_zone", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
gint *base_ett[] = {
&ett_radius,
&ett_radius_avp,
&ett_radius_authenticator,
&ett_radius_ascend,
&ett_eap,
&ett_chap,
&(no_dictionary_entry.ett),
&(no_vendor.ett),
};
static ei_register_info ei[] = {
{
&ei_radius_invalid_length, { "radius.invalid_length", PI_MALFORMED, PI_ERROR, "Invalid length", EXPFILL }},
};
expert_module_t *expert_radius;
hfett_t ri;
char *dir = NULL;
gchar *dict_err_str = NULL;
ri.hf = wmem_array_new(wmem_epan_scope(), sizeof(hf_register_info));
ri.ett = wmem_array_new(wmem_epan_scope(), sizeof(gint *));
ri.vend_vs = wmem_array_new(wmem_epan_scope(), sizeof(value_string));
wmem_array_append(ri.hf, base_hf, array_length(base_hf));
wmem_array_append(ri.ett, base_ett, array_length(base_ett));
dir = get_persconffile_path("radius", FALSE);
if (test_for_directory(dir) != EISDIR) {
g_free(dir);
dir = get_datafile_path("radius");
if (test_for_directory(dir) != EISDIR) {
g_free(dir);
dir = NULL;
}
}
if (dir) {
radius_load_dictionary(dict, dir, "dictionary", &dict_err_str);
if (dict_err_str) {
report_failure("radius: %s", dict_err_str);
g_free(dict_err_str);
}
g_hash_table_foreach(dict->attrs_by_id, register_attrs, &ri);
g_hash_table_foreach(dict->vendors_by_id, register_vendors, &ri);
}
g_free(dir);
proto_register_field_array(proto_radius, (hf_register_info *)wmem_array_get_raw(ri.hf), wmem_array_get_count(ri.hf));
proto_register_subtree_array((gint **)wmem_array_get_raw(ri.ett), wmem_array_get_count(ri.ett));
expert_radius = expert_register_protocol(proto_radius);
expert_register_field_array(expert_radius, ei, array_length(ei));
radius_register_avp_dissector(0, 3, dissect_chap_password);
radius_register_avp_dissector(0, 8, dissect_framed_ip_address);
radius_register_avp_dissector(0, 14, dissect_login_ip_host);
radius_register_avp_dissector(0, 23, dissect_framed_ipx_network);
radius_register_avp_dissector(0, 56, dissect_rfc4675_egress_vlanid);
radius_register_avp_dissector(0, 58, dissect_rfc4675_egress_vlan_name);
radius_register_avp_dissector(VENDOR_COSINE, 5, dissect_cosine_vpvc);
radius_register_avp_dissector(VENDOR_ASCEND, 242, dissect_ascend_data_filter);
radius_register_avp_dissector(VENDOR_REDBACK, 242, dissect_ascend_data_filter);
radius_register_avp_dissector(0, 242, dissect_ascend_data_filter);
radius_register_avp_dissector(VENDOR_THE3GPP, 23, dissect_radius_3gpp_ms_tmime_zone);
}
void
proto_register_radius(void)
{
module_t *radius_module;
proto_radius = proto_register_protocol("RADIUS Protocol", "RADIUS", "radius");
radius_handle = register_dissector("radius", dissect_radius, proto_radius);
register_init_routine(&radius_init_protocol);
register_shutdown_routine(radius_shutdown);
radius_module = prefs_register_protocol(proto_radius, NULL);
prefs_register_string_preference(radius_module, "shared_secret", "Shared Secret",
"Shared secret used to decode User Passwords and validate Response Authenticators",
&shared_secret);
prefs_register_bool_preference(radius_module, "validate_authenticator", "Validate Response Authenticator",
"Whether to check or not if Response Authenticator is correct. You need to define shared secret for this to work.",
&validate_authenticator);
prefs_register_bool_preference(radius_module, "show_length", "Show AVP Lengths",
"Whether to add or not to the tree the AVP's payload length",
&show_length);
prefs_register_obsolete_preference(radius_module, "request_ttl");
radius_tap = register_tap("radius");
proto_register_prefix("radius", register_radius_fields);
dict = (radius_dictionary_t *)g_malloc(sizeof(radius_dictionary_t));
dict->attrs_by_id = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, free_radius_attr_info);
dict->attrs_by_name = g_hash_table_new(g_str_hash, g_str_equal);
dict->vendors_by_id = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, free_radius_vendor_info);
dict->vendors_by_name = g_hash_table_new(g_str_hash, g_str_equal);
dict->tlvs_by_name = g_hash_table_new(g_str_hash, g_str_equal);
radius_calls = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), radius_call_hash, radius_call_equal);
register_rtd_table(proto_radius, NULL, RADIUS_CAT_NUM_TIMESTATS, 1, radius_message_code, radiusstat_packet, NULL);
}
void
proto_reg_handoff_radius(void)
{
eap_handle = find_dissector_add_dependency("eap", proto_radius);
dissector_add_uint_range_with_preference("udp.port", DEFAULT_RADIUS_PORT_RANGE, radius_handle);
}
