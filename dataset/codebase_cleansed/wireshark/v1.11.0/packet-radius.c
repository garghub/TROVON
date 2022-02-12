static gint radius_vsa_equal(gconstpointer k1, gconstpointer k2)
{
const radius_vsa_buffer_key* key1 = (const radius_vsa_buffer_key*) k1;
const radius_vsa_buffer_key* key2 = (const radius_vsa_buffer_key*) k2;
return (((key1->vendor_id == key2->vendor_id) &&
(key1->vsa_type == key2->vsa_type)
) ? TRUE : FALSE);
}
static guint radius_vsa_hash(gconstpointer k)
{
const radius_vsa_buffer_key* key = (const radius_vsa_buffer_key*) k;
return key->vendor_id + key->vsa_type;
}
static gboolean radius_call_equal(gconstpointer k1, gconstpointer k2)
{
const radius_call_info_key* key1 = (const radius_call_info_key*) k1;
const radius_call_info_key* key2 = (const radius_call_info_key*) k2;
if (key1->ident == key2->ident && key1->conversation == key2->conversation) {
nstime_t delta;
nstime_delta(&delta, &key1->req_time, &key2->req_time);
if (abs( (int) nstime_to_sec(&delta)) > (double) request_ttl) return 0;
if (key1->code == key2->code)
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_ACCESS_REQUEST) &&
((key2->code == RADIUS_PKT_TYPE_ACCESS_ACCEPT) ||
(key2->code == RADIUS_PKT_TYPE_ACCESS_REJECT) ||
(key2->code == RADIUS_PKT_TYPE_ACCESS_CHALLENGE)))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_ACCOUNTING_REQUEST) &&
(key2->code == RADIUS_PKT_TYPE_ACCOUNTING_RESPONSE))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_PASSWORD_REQUEST) &&
((key2->code == RADIUS_PKT_TYPE_PASSWORD_ACK) || (key2->code == RADIUS_PKT_TYPE_PASSWORD_REJECT)))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_RESOURCE_FREE_REQUEST) &&
(key2->code == RADIUS_PKT_TYPE_RESOURCE_FREE_RESPONSE))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_RESOURCE_QUERY_REQUEST) &&
(key2->code == RADIUS_PKT_TYPE_RESOURCE_QUERY_RESPONSE))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_NAS_REBOOT_REQUEST) &&
(key2->code == RADIUS_PKT_TYPE_NAS_REBOOT_RESPONSE))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_EVENT_REQUEST) &&
(key2->code == RADIUS_PKT_TYPE_EVENT_RESPONSE))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_DISCONNECT_REQUEST) &&
((key2->code == RADIUS_PKT_TYPE_DISCONNECT_ACK) || (key2->code == RADIUS_PKT_TYPE_DISCONNECT_NAK)))
return TRUE;
if ((key1->code == RADIUS_PKT_TYPE_COA_REQUEST) &&
((key2->code == RADIUS_PKT_TYPE_COA_ACK) || (key2->code == RADIUS_PKT_TYPE_COA_NAK)))
return TRUE;
}
return FALSE;
}
static guint radius_call_hash(gconstpointer k)
{
const radius_call_info_key* key = (const radius_call_info_key*) k;
return key->ident + key->conversation->index;
}
static const gchar *dissect_chap_password(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo _U_) {
int len;
proto_item *ti;
proto_tree *chap_tree;
len = tvb_length(tvb);
if (len != 17)
return "[wrong length for CHAP-Password]";
ti = proto_tree_add_item(tree, hf_radius_chap_password, tvb, 0, len, ENC_NA);
chap_tree = proto_item_add_subtree(ti, ett_chap);
proto_tree_add_item(chap_tree, hf_radius_chap_ident, tvb, 0, 1, ENC_NA);
proto_tree_add_item(chap_tree, hf_radius_chap_string, tvb, 1, 16, ENC_NA);
return (tvb_bytes_to_str(tvb, 0, len));
}
static const gchar *dissect_framed_ip_address(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo _U_) {
int len;
guint32 ip;
guint32 ip_h;
const gchar *str;
len = tvb_length(tvb);
if (len != 4)
return "[wrong length for IP address]";
ip=tvb_get_ipv4(tvb,0);
ip_h=g_ntohl(ip);
if (ip_h == 0xFFFFFFFF) {
str = "Negotiated";
proto_tree_add_ipv4_format_value(tree, hf_radius_framed_ip_address,
tvb, 0, len, ip, "%s", str);
} else if (ip_h == 0xFFFFFFFE) {
str = "Assigned";
proto_tree_add_ipv4_format_value(tree, hf_radius_framed_ip_address,
tvb, 0, len, ip, "%s", str);
} else {
str = ip_to_str((guint8 *)&ip);
proto_tree_add_ipv4_format_value(tree, hf_radius_framed_ip_address,
tvb, 0, len, ip, "%s (%s)",
get_hostname(ip), str);
}
return str;
}
static const gchar *dissect_login_ip_host(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo _U_) {
int len;
guint32 ip;
guint32 ip_h;
const gchar *str;
len = tvb_length(tvb);
if (len != 4)
return "[wrong length for IP address]";
ip=tvb_get_ipv4(tvb,0);
ip_h=g_ntohl(ip);
if (ip_h == 0xFFFFFFFF) {
str = "User-selected";
proto_tree_add_ipv4_format_value(tree, hf_radius_login_ip_host,
tvb, 0, len, ip, "%s", str);
} else if (ip_h == 0) {
str = "NAS-selected";
proto_tree_add_ipv4_format_value(tree, hf_radius_login_ip_host,
tvb, 0, len, ip, "%s", str);
} else {
str = ip_to_str((guint8 *)&ip);
proto_tree_add_ipv4_format_value(tree, hf_radius_login_ip_host,
tvb, 0, len, ip, "%s (%s)",
get_hostname(ip), str);
}
return str;
}
static const gchar *dissect_ascend_data_filter(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo _U_) {
wmem_strbuf_t *filterstr;
int len;
guint8 proto, srclen, dstlen;
guint32 srcip, dstip;
guint16 srcport, dstport;
guint8 srcportq, dstportq;
len=tvb_length(tvb);
if (len != 24) {
return wmem_strdup_printf(wmem_packet_scope(), "Wrong attribute length %d", len);
}
filterstr=wmem_strbuf_sized_new(wmem_packet_scope(), 64, 64);
proto_tree_add_item(tree, hf_radius_ascend_data_filter, tvb, 0, -1, ENC_NA);
wmem_strbuf_append_printf(filterstr, "%s %s %s",
val_to_str(tvb_get_guint8(tvb, 0), ascenddf_filtertype, "%u"),
val_to_str(tvb_get_guint8(tvb, 2), ascenddf_inout, "%u"),
val_to_str(tvb_get_guint8(tvb, 1), ascenddf_filteror, "%u"));
proto=tvb_get_guint8(tvb, 14);
if (proto) {
wmem_strbuf_append_printf(filterstr, " %s",
val_to_str(proto, ascenddf_proto, "%u"));
}
srcip=tvb_get_ipv4(tvb, 4);
srclen=tvb_get_guint8(tvb, 12);
srcport=tvb_get_ntohs(tvb, 16);
srcportq=tvb_get_guint8(tvb, 20);
if (srcip || srclen || srcportq) {
wmem_strbuf_append_printf(filterstr, " srcip %s/%d", ip_to_str((guint8 *) &srcip), srclen);
if (srcportq)
wmem_strbuf_append_printf(filterstr, " srcport %s %d",
val_to_str(srcportq, ascenddf_portq, "%u"), srcport);
}
dstip=tvb_get_ipv4(tvb, 8);
dstlen=tvb_get_guint8(tvb, 13);
dstport=tvb_get_ntohs(tvb, 18);
dstportq=tvb_get_guint8(tvb, 21);
if (dstip || dstlen || dstportq) {
wmem_strbuf_append_printf(filterstr, " dstip %s/%d", ip_to_str((guint8 *) &dstip), dstlen);
if (dstportq)
wmem_strbuf_append_printf(filterstr, " dstport %s %d",
val_to_str(dstportq, ascenddf_portq, "%u"), dstport);
}
return wmem_strbuf_get_str(filterstr);
}
static const gchar *dissect_framed_ipx_network(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo _U_) {
int len;
guint32 net;
const gchar *str;
len = tvb_length(tvb);
if (len != 4)
return "[wrong length for IPX network]";
net=tvb_get_ntohl(tvb,0);
if (net == 0xFFFFFFFE)
str = "NAS-selected";
else
str = wmem_strdup_printf(wmem_packet_scope(), "0x%08X", net);
proto_tree_add_ipxnet_format_value(tree, hf_radius_framed_ipx_network, tvb, 0,
len, net, "Framed-IPX-Network: %s", str);
return str;
}
static const gchar* dissect_cosine_vpvc(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo _U_) {
guint vpi, vci;
if ( tvb_length(tvb) != 4 )
return "[Wrong Length for VP/VC AVP]";
vpi = tvb_get_ntohs(tvb,0);
vci = tvb_get_ntohs(tvb,2);
proto_tree_add_uint(tree,hf_radius_cosine_vpi,tvb,0,2,vpi);
proto_tree_add_uint(tree,hf_radius_cosine_vci,tvb,2,2,vci);
return wmem_strdup_printf(wmem_packet_scope(), "%u/%u",vpi,vci);
}
static const gchar*
dissect_radius_3gpp_ms_tmime_zone(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo _U_) {
int offset = 0;
guint8 oct, daylight_saving_time;
char sign;
oct = tvb_get_guint8(tvb, offset);
sign = (oct & 0x08) ? '-' : '+';
oct = (oct >> 4) + (oct & 0x07) * 10;
proto_tree_add_text(tree, tvb, offset, 1, "Timezone: GMT %c%d hours %d minutes", sign, oct / 4, oct % 4 * 15);
offset++;
daylight_saving_time = tvb_get_guint8(tvb, offset) & 0x3;
proto_tree_add_text(tree, tvb, offset, 1, "%s", val_to_str_const(daylight_saving_time, daylight_saving_time_vals, "Unknown"));
return wmem_strdup_printf(wmem_packet_scope(), "Timezone: GMT %c%d hours %d minutes %s ",
sign, oct / 4, oct % 4 * 15, val_to_str_const(daylight_saving_time, daylight_saving_time_vals, "Unknown"));
}
static void
radius_decrypt_avp(gchar *dest,int dest_len,tvbuff_t *tvb,int offset,int length)
{
md5_state_t md_ctx, old_md_ctx;
md5_byte_t digest[AUTHENTICATOR_LENGTH];
int i, j;
gint totlen = 0, returned_length, padded_length;
guint8 *pd;
guchar c;
DISSECTOR_ASSERT(dest_len > 0);
dest[0] = '\0';
if ( length <= 0 )
return;
if ( length > 128 )
length = 128;
md5_init(&md_ctx);
md5_append(&md_ctx, (const guint8*)shared_secret, (int)strlen(shared_secret));
old_md_ctx = md_ctx;
md5_append(&md_ctx, authenticator, AUTHENTICATOR_LENGTH);
md5_finish(&md_ctx, digest);
padded_length = length + ((length % AUTHENTICATOR_LENGTH) ?
(AUTHENTICATOR_LENGTH - (length % AUTHENTICATOR_LENGTH)) : 0);
pd = (guint8 *)wmem_alloc0(wmem_packet_scope(), padded_length);
tvb_memcpy(tvb, pd, offset, length);
for ( i = 0; i < padded_length; i += AUTHENTICATOR_LENGTH ) {
for ( j = 0; j < AUTHENTICATOR_LENGTH; j++ ) {
c = pd[i + j] ^ digest[j];
if ( isprint(c) ) {
returned_length = g_snprintf(&dest[totlen], dest_len - totlen,
"%c", c);
totlen += MIN(returned_length, dest_len - totlen - 1);
}
else if ( c ) {
returned_length = g_snprintf(&dest[totlen], dest_len - totlen,
"\\%03o", c);
totlen += MIN(returned_length, dest_len - totlen - 1);
}
}
md_ctx = old_md_ctx;
md5_append(&md_ctx, &pd[i], AUTHENTICATOR_LENGTH);
md5_finish(&md_ctx, digest);
}
}
void radius_integer(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
guint32 uintv;
switch (len) {
case 1:
uintv = tvb_get_guint8(tvb,offset);
break;
case 2:
uintv = tvb_get_ntohs(tvb,offset);
break;
case 3:
uintv = tvb_get_ntoh24(tvb,offset);
break;
case 4:
uintv = tvb_get_ntohl(tvb,offset);
break;
case 8: {
guint64 uintv64 = tvb_get_ntoh64(tvb,offset);
proto_tree_add_uint64(tree,a->hf_alt,tvb,offset,len,uintv64);
proto_item_append_text(avp_item, "%" G_GINT64_MODIFIER "u", uintv64);
return;
}
default:
proto_item_append_text(avp_item, "[unhandled integer length(%u)]", len);
return;
}
proto_tree_add_item(tree,a->hf,tvb, offset, len, ENC_BIG_ENDIAN);
if (a->vs) {
proto_item_append_text(avp_item, "%s(%u)", val_to_str_const(uintv, a->vs, "Unknown"),uintv);
} else {
proto_item_append_text(avp_item, "%u", uintv);
}
}
void radius_signed(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
guint32 uintv;
switch (len) {
case 1:
uintv = tvb_get_guint8(tvb,offset);
break;
case 2:
uintv = tvb_get_ntohs(tvb,offset);
break;
case 3:
uintv = tvb_get_ntoh24(tvb,offset);
break;
case 4:
uintv = tvb_get_ntohl(tvb,offset);
break;
case 8: {
guint64 uintv64 = tvb_get_ntoh64(tvb,offset);
proto_tree_add_int64(tree,a->hf_alt,tvb,offset,len,uintv64);
proto_item_append_text(avp_item, "%" G_GINT64_MODIFIER "u", uintv64);
return;
}
default:
proto_item_append_text(avp_item, "[unhandled signed integer length(%u)]", len);
return;
}
proto_tree_add_int(tree,a->hf,tvb,offset,len,uintv);
if (a->vs) {
proto_item_append_text(avp_item, "%s(%d)", val_to_str_const(uintv, a->vs, "Unknown"),uintv);
} else {
proto_item_append_text(avp_item, "%d", uintv);
}
}
void radius_string(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
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
buffer=(gchar *)wmem_alloc(wmem_packet_scope(), 1024);
radius_decrypt_avp(buffer,1024,tvb,offset,len);
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
void radius_octets(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_bytes_to_str(tvb, offset, len));
}
void radius_ipaddr(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
guint32 ip;
gchar buf[MAX_IP_STR_LEN];
if (len != 4) {
proto_item_append_text(avp_item, "[wrong length for IP address]");
return;
}
ip=tvb_get_ipv4(tvb,offset);
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_BIG_ENDIAN);
ip_to_str_buf((guint8 *)&ip, buf, MAX_IP_STR_LEN);
proto_item_append_text(avp_item, "%s", buf);
}
void radius_ipv6addr(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
struct e_in6_addr ipv6_buff;
gchar txtbuf[256];
if (len != 16) {
proto_item_append_text(avp_item, "[wrong length for IPv6 address]");
return;
}
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
tvb_get_ipv6(tvb, offset, &ipv6_buff);
ip6_to_str_buf(&ipv6_buff, txtbuf);
proto_item_append_text(avp_item, "%s", txtbuf);
}
void radius_ipv6prefix(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
struct e_in6_addr ipv6_buff;
gchar txtbuf[256];
guint8 n;
if ((len < 2) || (len > 18) ) {
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
ip6_to_str_buf(&ipv6_buff, txtbuf);
proto_item_append_text(avp_item, "%s/%u", txtbuf, n);
}
void radius_combo_ip(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
guint32 ip;
struct e_in6_addr ipv6_buff;
gchar buf[256];
if (len == 4){
ip=tvb_get_ipv4(tvb,offset);
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_BIG_ENDIAN);
ip_to_str_buf((guint8 *)&ip, buf, MAX_IP_STR_LEN);
proto_item_append_text(avp_item, "%s", buf);
} else if (len == 16) {
proto_tree_add_item(tree, a->hf_alt, tvb, offset, len, ENC_NA);
tvb_get_ipv6(tvb, offset, &ipv6_buff);
ip6_to_str_buf(&ipv6_buff, buf);
proto_item_append_text(avp_item, "%s", buf);
} else {
proto_item_append_text(avp_item, "[wrong length for both of IPv4 and IPv6 address]");
return;
}
}
void radius_ipxnet(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
guint32 net;
if (len != 4) {
proto_item_append_text(avp_item, "[wrong length for IPX network]");
return;
}
net=tvb_get_ntohl(tvb,offset);
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "0x%08X", net);
}
void radius_date(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
nstime_t time_ptr;
if (len != 4) {
proto_item_append_text(avp_item, "[wrong length for timestamp]");
return;
}
time_ptr.secs = tvb_get_ntohl(tvb,offset);
time_ptr.nsecs = 0;
proto_tree_add_time(tree, a->hf, tvb, offset, len, &time_ptr);
proto_item_append_text(avp_item, "%s", abs_time_to_str(&time_ptr, ABSOLUTE_TIME_LOCAL, TRUE));
}
void radius_abinary(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_bytes_to_str(tvb, offset, len));
}
void radius_ether(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
if (len != 6) {
proto_item_append_text(avp_item, "[wrong length for ethernet address]");
return;
}
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_ether_to_str(tvb, offset));
}
void radius_ifid(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
proto_tree_add_item(tree, a->hf, tvb, offset, len, ENC_NA);
proto_item_append_text(avp_item, "%s", tvb_bytes_to_str(tvb, offset, len));
}
static void add_tlv_to_tree(proto_tree* tlv_tree, proto_item* tlv_item, packet_info* pinfo, tvbuff_t* tvb, radius_attr_info_t* dictionary_entry, guint32 tlv_length, guint32 offset) {
proto_item_append_text(tlv_item, ": ");
dictionary_entry->type(dictionary_entry,tlv_tree,pinfo,tvb,offset,tlv_length,tlv_item);
}
void radius_tlv(radius_attr_info_t* a, proto_tree* tree, packet_info *pinfo _U_, tvbuff_t* tvb, int offset, int len, proto_item* avp_item) {
proto_item* item;
gint tlv_num = 0;
while (len > 0) {
radius_attr_info_t* dictionary_entry = NULL;
guint32 tlv_type;
guint32 tlv_length;
proto_item* tlv_item;
proto_item* tlv_len_item;
proto_tree* tlv_tree;
if (len < 2) {
item = proto_tree_add_text(tree, tvb, offset, 0,
"Not enough room in packet for TLV header");
PROTO_ITEM_SET_GENERATED(item);
return;
}
tlv_type = tvb_get_guint8(tvb,offset);
tlv_length = tvb_get_guint8(tvb,offset+1);
if (tlv_length < 2) {
item = proto_tree_add_text(tree, tvb, offset, 0,
"TLV too short: length %u < 2", tlv_length);
PROTO_ITEM_SET_GENERATED(item);
return;
}
if (len < (gint)tlv_length) {
item = proto_tree_add_text(tree, tvb, offset, 0,
"Not enough room in packet for TLV");
PROTO_ITEM_SET_GENERATED(item);
return;
}
len -= tlv_length;
dictionary_entry = (radius_attr_info_t *)g_hash_table_lookup(a->tlvs_by_id,GUINT_TO_POINTER(tlv_type));
if (! dictionary_entry ) {
dictionary_entry = &no_dictionary_entry;
}
tlv_item = proto_tree_add_text(tree, tvb, offset, tlv_length,
"TLV: l=%u t=%s(%u)", tlv_length,
dictionary_entry->name, tlv_type);
tlv_length -= 2;
offset += 2;
tlv_tree = proto_item_add_subtree(tlv_item,dictionary_entry->ett);
if (show_length) {
tlv_len_item = proto_tree_add_uint(tlv_tree,
dictionary_entry->hf_len,
tvb,0,0,tlv_length);
PROTO_ITEM_SET_GENERATED(tlv_len_item);
}
add_tlv_to_tree(tlv_tree, tlv_item, pinfo, tvb, dictionary_entry,
tlv_length, offset);
offset += tlv_length;
tlv_num++;
}
proto_item_append_text(avp_item, "%d TLV(s) inside", tlv_num);
}
static void add_avp_to_tree(proto_tree* avp_tree, proto_item* avp_item, packet_info* pinfo, tvbuff_t* tvb, radius_attr_info_t* dictionary_entry, guint32 avp_length, guint32 offset) {
proto_item* pi;
if (dictionary_entry->tagged) {
guint tag;
if (avp_length == 0) {
pi = proto_tree_add_text(avp_tree, tvb, offset,
0, "AVP too short for tag");
PROTO_ITEM_SET_GENERATED(pi);
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
if ( dictionary_entry->dissector ) {
tvbuff_t* tvb_value;
const gchar* str;
tvb_value = tvb_new_subset(tvb, offset, avp_length, (gint) avp_length);
str = dictionary_entry->dissector(avp_tree,tvb_value,pinfo);
proto_item_append_text(avp_item, ": %s",str);
} else {
proto_item_append_text(avp_item, ": ");
dictionary_entry->type(dictionary_entry,avp_tree,pinfo,tvb,offset,avp_length,avp_item);
}
}
static gboolean vsa_buffer_destroy(gpointer k _U_, gpointer v, gpointer p _U_) {
radius_vsa_buffer* vsa_buffer = (radius_vsa_buffer*)v;
g_free((gpointer)vsa_buffer->data);
g_free(v);
return TRUE;
}
static void vsa_buffer_table_destroy(void *table) {
if (table) {
g_hash_table_foreach_remove((GHashTable *)table, vsa_buffer_destroy, NULL);
g_hash_table_destroy((GHashTable *)table);
}
}
void dissect_attribute_value_pairs(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset, guint length) {
proto_item* item;
gboolean last_eap = FALSE;
guint8* eap_buffer = NULL;
guint eap_seg_num = 0;
guint eap_tot_len_captured = 0;
guint eap_tot_len = 0;
proto_tree* eap_tree = NULL;
tvbuff_t* eap_tvb = NULL;
GHashTable* vsa_buffer_table = NULL;
DISSECTOR_ASSERT(proto_registrar_get_byname("radius.code"));
CLEANUP_PUSH_PFX(la, g_free, eap_buffer);
CLEANUP_PUSH_PFX(lb, vsa_buffer_table_destroy, (void *)vsa_buffer_table);
while (length > 0) {
radius_attr_info_t* dictionary_entry = NULL;
gint tvb_len;
guint32 avp_type;
guint32 avp_length;
guint32 vendor_id;
proto_item* avp_item;
proto_item* avp_len_item;
proto_tree* avp_tree;
if (length < 2) {
item = proto_tree_add_text(tree, tvb, offset, 0,
"Not enough room in packet for AVP header");
PROTO_ITEM_SET_GENERATED(item);
break;
}
avp_type = tvb_get_guint8(tvb,offset);
avp_length = tvb_get_guint8(tvb,offset+1);
if (avp_length < 2) {
item = proto_tree_add_text(tree, tvb, offset, 0,
"AVP too short: length %u < 2", avp_length);
PROTO_ITEM_SET_GENERATED(item);
break;
}
if (length < avp_length) {
item = proto_tree_add_text(tree, tvb, offset, 0,
"Not enough room in packet for AVP");
PROTO_ITEM_SET_GENERATED(item);
break;
}
length -= avp_length;
dictionary_entry = (radius_attr_info_t *)g_hash_table_lookup(dict->attrs_by_id, GUINT_TO_POINTER(avp_type));
if (! dictionary_entry ) {
dictionary_entry = &no_dictionary_entry;
}
avp_item = proto_tree_add_text(tree, tvb, offset, avp_length,
"AVP: l=%u t=%s(%u)", avp_length,
dictionary_entry->name, avp_type);
avp_length -= 2;
offset += 2;
if (avp_type == RADIUS_ATTR_TYPE_VENDOR_SPECIFIC) {
radius_vendor_info_t* vendor;
proto_tree* vendor_tree;
gint max_offset = offset + avp_length;
const gchar* vendor_str;
if (avp_length < 4) {
proto_item_append_text(avp_item, " [AVP too short; no room for vendor ID]");
offset += avp_length;
continue;
}
vendor_id = tvb_get_ntohl(tvb,offset);
avp_length -= 4;
offset += 4;
vendor = (radius_vendor_info_t *)g_hash_table_lookup(dict->vendors_by_id,GUINT_TO_POINTER(vendor_id));
vendor_str = val_to_str_ext_const(vendor_id, &sminmpec_values_ext, "Unknown");
if (!vendor) {
vendor = &no_vendor;
}
proto_item_append_text(avp_item, " v=%s(%u)", vendor_str,
vendor_id);
vendor_tree = proto_item_add_subtree(avp_item,vendor->ett);
while (offset < max_offset) {
guint32 avp_vsa_type;
guint32 avp_vsa_len;
guint8 avp_vsa_flags = 0;
guint32 avp_vsa_header_len = vendor->type_octets + vendor->length_octets + (vendor->has_flags ? 1 : 0);
switch (vendor->type_octets) {
case 1:
avp_vsa_type = tvb_get_guint8(tvb,offset++);
break;
case 2:
avp_vsa_type = tvb_get_ntohs(tvb,offset);
offset += 2;
break;
case 4:
avp_vsa_type = tvb_get_ntohl(tvb,offset);
offset += 4;
break;
default:
avp_vsa_type = tvb_get_guint8(tvb,offset++);
}
switch (vendor->length_octets) {
case 1:
avp_vsa_len = tvb_get_guint8(tvb,offset++);
break;
case 0:
avp_vsa_len = avp_length;
break;
case 2:
avp_vsa_len = tvb_get_ntohs(tvb,offset);
offset += 2;
break;
default:
avp_vsa_len = tvb_get_guint8(tvb,offset++);
}
if (vendor->has_flags) {
avp_vsa_flags = tvb_get_guint8(tvb,offset++);
}
if (avp_vsa_len < avp_vsa_header_len) {
proto_tree_add_text(tree, tvb, offset+1, 1,
"[VSA too short]");
break;
}
avp_vsa_len -= avp_vsa_header_len;
dictionary_entry = (radius_attr_info_t *)g_hash_table_lookup(vendor->attrs_by_id,GUINT_TO_POINTER(avp_vsa_type));
if ( !dictionary_entry ) {
dictionary_entry = &no_dictionary_entry;
}
if (vendor->has_flags){
avp_item = proto_tree_add_text(vendor_tree,tvb,offset-avp_vsa_header_len,avp_vsa_len+avp_vsa_header_len,
"VSA: l=%u t=%s(%u) C=0x%02x",
avp_vsa_len+avp_vsa_header_len, dictionary_entry->name, avp_vsa_type, avp_vsa_flags);
} else {
avp_item = proto_tree_add_text(vendor_tree,tvb,offset-avp_vsa_header_len,avp_vsa_len+avp_vsa_header_len,
"VSA: l=%u t=%s(%u)",
avp_vsa_len+avp_vsa_header_len, dictionary_entry->name, avp_vsa_type);
}
avp_tree = proto_item_add_subtree(avp_item,dictionary_entry->ett);
if (show_length) {
avp_len_item = proto_tree_add_uint(avp_tree,
dictionary_entry->hf_len,
tvb,0,0,avp_length);
PROTO_ITEM_SET_GENERATED(avp_len_item);
}
if (vendor->has_flags) {
radius_vsa_buffer_key key;
radius_vsa_buffer* vsa_buffer = NULL;
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
proto_tree_add_text(avp_tree, tvb, offset, avp_vsa_len, "VSA fragment");
proto_item_append_text(avp_item, ": VSA fragment[%u]", vsa_buffer->seg_num);
} else {
if (vsa_buffer) {
tvbuff_t* vsa_tvb = NULL;
proto_tree_add_text(avp_tree, tvb, offset, avp_vsa_len, "VSA fragment");
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
};
continue;
}
avp_tree = proto_item_add_subtree(avp_item,dictionary_entry->ett);
if (show_length) {
avp_len_item = proto_tree_add_uint(avp_tree,
dictionary_entry->hf_len,
tvb,0,0,avp_length);
PROTO_ITEM_SET_GENERATED(avp_len_item);
}
tvb_len = tvb_length_remaining(tvb, offset);
if ((gint)avp_length < tvb_len)
tvb_len = avp_length;
if (avp_type == RADIUS_ATTR_TYPE_EAP_MESSAGE) {
eap_seg_num++;
if (tree)
proto_tree_add_text(avp_tree, tvb, offset, tvb_len,
"EAP fragment");
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
if ( tvb_bytes_exist(tvb, offset + avp_length + 1, 1) ) {
guint8 next_type = tvb_get_guint8(tvb, offset + avp_length);
if ( next_type != RADIUS_ATTR_TYPE_EAP_MESSAGE ) {
last_eap = TRUE;
}
} else {
last_eap = TRUE;
}
if (last_eap && eap_buffer) {
gboolean save_writable;
proto_item_append_text(avp_item, " Last Segment[%u]",
eap_seg_num);
eap_tree = proto_item_add_subtree(avp_item,ett_eap);
eap_tvb = tvb_new_child_real_data(tvb, eap_buffer,
eap_tot_len_captured,
eap_tot_len);
tvb_set_free_cb(eap_tvb, g_free);
add_new_data_source(pinfo, eap_tvb, "Reassembled EAP");
eap_buffer = NULL;
save_writable = col_get_writable(pinfo->cinfo);
col_set_writable(pinfo->cinfo, FALSE);
call_dissector(eap_handle, eap_tvb, pinfo, eap_tree);
col_set_writable(pinfo->cinfo, save_writable);
} else {
proto_item_append_text(avp_item, " Segment[%u]",
eap_seg_num);
}
}
offset += avp_length;
} else {
add_avp_to_tree(avp_tree, avp_item, pinfo, tvb, dictionary_entry,
avp_length, offset);
offset += avp_length;
}
}
CLEANUP_CALL_AND_POP_PFX(lb);
CLEANUP_CALL_AND_POP_PFX(la);
}
static gboolean
is_radius(tvbuff_t *tvb)
{
guint8 code;
guint16 length;
code=tvb_get_guint8(tvb, 0);
if (try_val_to_str_ext(code, &radius_pkt_type_codes_ext) == NULL) {
return FALSE;
}
length=tvb_get_ntohs(tvb, 2);
if ( (length<20) || (length>4096) ) {
return FALSE;
}
return TRUE;
}
static int
dissect_radius(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *radius_tree = NULL;
proto_tree *avptree = NULL;
proto_item *ti, *hidden_item;
proto_item *avptf;
guint avplength;
e_radiushdr rh;
radius_info_t *rad_info;
conversation_t* conversation;
radius_call_info_key radius_call_key;
radius_call_info_key *new_radius_call_key;
radius_call_t *radius_call = NULL;
static address null_address = { AT_NONE, -1, 0, NULL };
if(!is_radius(tvb)){
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RADIUS");
col_clear(pinfo->cinfo, COL_INFO);
rh.rh_code=tvb_get_guint8(tvb,0);
rh.rh_ident=tvb_get_guint8(tvb,1);
rh.rh_pktlength=tvb_get_ntohs(tvb,2);
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
col_add_fstr(pinfo->cinfo,COL_INFO,"%s(%d) (id=%d, l=%d)",
val_to_str_ext_const(rh.rh_code, &radius_pkt_type_codes_ext, "Unknown Packet"),
rh.rh_code, rh.rh_ident, rh.rh_pktlength);
if (tree)
{
DISSECTOR_ASSERT(proto_registrar_get_byname("radius.code"));
ti = proto_tree_add_item(tree,proto_radius, tvb, 0, rh.rh_pktlength, ENC_NA);
radius_tree = proto_item_add_subtree(ti, ett_radius);
proto_tree_add_uint(radius_tree,hf_radius_code, tvb, 0, 1, rh.rh_code);
proto_tree_add_uint_format(radius_tree,hf_radius_id, tvb, 1, 1, rh.rh_ident,
"Packet identifier: 0x%01x (%d)", rh.rh_ident, rh.rh_ident);
}
if (rh.rh_pktlength < HDR_LENGTH)
{
if (tree)
{
proto_tree_add_uint_format_value(radius_tree, hf_radius_length,
tvb, 2, 2, rh.rh_pktlength, "%u (bogus, < %u)",
rh.rh_pktlength, HDR_LENGTH);
}
return tvb_length(tvb);
}
avplength = rh.rh_pktlength - HDR_LENGTH;
if (tree)
{
proto_tree_add_uint(radius_tree, hf_radius_length, tvb, 2, 2, rh.rh_pktlength);
proto_tree_add_item(radius_tree, hf_radius_authenticator, tvb, 4, AUTHENTICATOR_LENGTH,ENC_NA);
}
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
if (pinfo->flags.in_error_pkt)
break;
if (tree)
{
hidden_item = proto_tree_add_boolean(radius_tree, hf_radius_req, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
conversation = find_conversation(pinfo->fd->num, &pinfo->src,
&null_address, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation == NULL)
{
conversation = conversation_new(pinfo->fd->num, &pinfo->src,
&null_address, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
}
radius_call_key.code = rh.rh_code;
radius_call_key.ident = rh.rh_ident;
radius_call_key.conversation = conversation;
radius_call_key.req_time = pinfo->fd->abs_ts;
radius_call = (radius_call_t *)g_hash_table_lookup(radius_calls, &radius_call_key);
if (radius_call != NULL)
{
if (pinfo->fd->num != radius_call->req_num)
{
rad_info->is_duplicate = TRUE;
rad_info->req_num = radius_call->req_num;
col_append_fstr(pinfo->cinfo, COL_INFO,
", Duplicate Request ID:%u", rh.rh_ident);
if (tree)
{
proto_item* item;
hidden_item = proto_tree_add_uint(radius_tree, hf_radius_dup, tvb, 0,0, rh.rh_ident);
PROTO_ITEM_SET_HIDDEN(hidden_item);
item = proto_tree_add_uint(radius_tree, hf_radius_req_dup, tvb, 0,0, rh.rh_ident);
PROTO_ITEM_SET_GENERATED(item);
}
}
}
else
{
new_radius_call_key = wmem_new(wmem_file_scope(), radius_call_info_key);
*new_radius_call_key = radius_call_key;
radius_call = wmem_new(wmem_file_scope(), radius_call_t);
radius_call->req_num = pinfo->fd->num;
radius_call->rsp_num = 0;
radius_call->ident = rh.rh_ident;
radius_call->code = rh.rh_code;
radius_call->responded = FALSE;
radius_call->req_time = pinfo->fd->abs_ts;
radius_call->rspcode = 0;
g_hash_table_insert(radius_calls, new_radius_call_key, radius_call);
}
if (tree && radius_call->rsp_num)
{
proto_item* item;
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
if (pinfo->flags.in_error_pkt)
break;
if (tree)
{
hidden_item = proto_tree_add_boolean(radius_tree, hf_radius_rsp, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
conversation = find_conversation(pinfo->fd->num, &null_address,
&pinfo->dst, pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if (conversation != NULL)
{
radius_call_key.code = rh.rh_code;
radius_call_key.ident = rh.rh_ident;
radius_call_key.conversation = conversation;
radius_call_key.req_time = pinfo->fd->abs_ts;
radius_call = (radius_call_t *)g_hash_table_lookup(radius_calls, &radius_call_key);
if (radius_call)
{
if (radius_call->req_num)
{
rad_info->request_available = TRUE;
rad_info->req_num = radius_call->req_num;
radius_call->responded = TRUE;
if (tree)
{
nstime_t delta;
proto_item* item;
item = proto_tree_add_uint_format(radius_tree,
hf_radius_req_frame, tvb, 0, 0,
radius_call->req_num,
"This is a response to a request in frame %u",
radius_call->req_num);
PROTO_ITEM_SET_GENERATED(item);
nstime_delta(&delta, &pinfo->fd->abs_ts, &radius_call->req_time);
item = proto_tree_add_time(radius_tree, hf_radius_time, tvb, 0, 0, &delta);
PROTO_ITEM_SET_GENERATED(item);
}
}
if (radius_call->rsp_num == 0)
{
radius_call->rsp_num = pinfo->fd->num;
}
else
{
if ( (radius_call->rsp_num != pinfo->fd->num) && (radius_call->rspcode == rh.rh_code) )
{
rad_info->is_duplicate = TRUE;
col_append_fstr(pinfo->cinfo, COL_INFO,
", Duplicate Response ID:%u", rh.rh_ident);
if (tree)
{
proto_item* item;
hidden_item = proto_tree_add_uint(radius_tree,
hf_radius_dup, tvb, 0,0, rh.rh_ident);
PROTO_ITEM_SET_HIDDEN(hidden_item);
item = proto_tree_add_uint(radius_tree,
hf_radius_rsp_dup, tvb, 0, 0, rh.rh_ident);
PROTO_ITEM_SET_GENERATED(item);
}
}
}
radius_call->rspcode = rh.rh_code;
rad_info->rspcode = rh.rh_code;
}
}
break;
default:
break;
}
if (radius_call)
{
rad_info->req_time.secs = radius_call->req_time.secs;
rad_info->req_time.nsecs = radius_call->req_time.nsecs;
}
if (avplength > 0)
{
avptf = proto_tree_add_text(radius_tree, tvb, HDR_LENGTH,
avplength, "Attribute Value Pairs");
avptree = proto_item_add_subtree(avptf, ett_radius_avp);
dissect_attribute_value_pairs(avptree, pinfo, tvb, HDR_LENGTH,
avplength);
}
return tvb_length(tvb);
}
static void register_attrs(gpointer k _U_, gpointer v, gpointer p) {
radius_attr_info_t* a = (radius_attr_info_t *)v;
int i;
gint* ett = &(a->ett);
gchar* abbrev = g_strconcat("radius.",a->name,NULL);
hf_register_info hfri[] = {
{ NULL, { NULL,NULL, FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ NULL, { NULL,NULL, FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ NULL, { NULL,NULL, FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ NULL, { NULL,NULL, FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
guint len_hf = 2;
hfett_t* ri = (hfett_t *)p;
for(i=0; abbrev[i]; i++) {
if(abbrev[i] == '-') abbrev[i] = '_';
if(abbrev[i] == '/') abbrev[i] = '_';
}
hfri[0].p_id = &(a->hf);
hfri[1].p_id = &(a->hf_len);
hfri[0].hfinfo.name = a->name;
hfri[0].hfinfo.abbrev = abbrev;
hfri[1].hfinfo.name = "Length";
hfri[1].hfinfo.abbrev = g_strconcat(abbrev,".len",NULL);
hfri[1].hfinfo.blurb = g_strconcat(a->name," Length",NULL);
if (a->type == radius_integer) {
hfri[0].hfinfo.type = FT_UINT32;
hfri[0].hfinfo.display = BASE_DEC;
hfri[2].p_id = &(a->hf_alt);
hfri[2].hfinfo.name = g_strdup(a->name);
hfri[2].hfinfo.abbrev = abbrev;
hfri[2].hfinfo.type = FT_UINT64;
hfri[2].hfinfo.display = BASE_DEC;
if (a->vs) {
hfri[0].hfinfo.strings = VALS(a->vs);
}
len_hf++;
}else if (a->type == radius_signed) {
hfri[0].hfinfo.type = FT_INT32;
hfri[0].hfinfo.display = BASE_DEC;
hfri[2].p_id = &(a->hf_alt);
hfri[2].hfinfo.name = g_strdup(a->name);
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
hfri[2].hfinfo.name = g_strdup_printf("%s (encrypted)", a->name);
hfri[2].hfinfo.abbrev = g_strdup_printf("%s_encrypted", abbrev);
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
hfri[2].hfinfo.name = g_strdup(a->name);
hfri[2].hfinfo.abbrev = g_strdup(abbrev);
hfri[2].hfinfo.type = FT_IPv6;
hfri[2].hfinfo.display = BASE_NONE;
len_hf++;
} else if (a->type == radius_tlv) {
hfri[0].hfinfo.type = FT_BYTES;
hfri[0].hfinfo.display = BASE_NONE;
} else {
hfri[0].hfinfo.type = FT_BYTES;
hfri[0].hfinfo.display = BASE_NONE;
}
if (a->tagged) {
hfri[len_hf].p_id = &(a->hf_tag);
hfri[len_hf].hfinfo.name = "Tag";
hfri[len_hf].hfinfo.abbrev = g_strconcat(abbrev,".tag",NULL);
hfri[len_hf].hfinfo.blurb = g_strconcat(a->name," Tag",NULL);
hfri[len_hf].hfinfo.type = FT_UINT8;
hfri[len_hf].hfinfo.display = BASE_HEX;
len_hf++;
}
g_array_append_vals(ri->hf,hfri,len_hf);
g_array_append_val(ri->ett,ett);
if (a->tlvs_by_id) {
g_hash_table_foreach(a->tlvs_by_id,register_attrs,ri);
}
}
static void register_vendors(gpointer k _U_, gpointer v, gpointer p) {
radius_vendor_info_t* vnd = (radius_vendor_info_t *)v;
hfett_t* ri = (hfett_t *)p;
value_string vnd_vs;
gint* ett_p = &(vnd->ett);
vnd_vs.value = vnd->code;
vnd_vs.strptr = vnd->name;
g_array_append_val(ri->vend_vs,vnd_vs);
g_array_append_val(ri->ett,ett_p);
g_hash_table_foreach(vnd->attrs_by_id,register_attrs,ri);
}
extern void radius_register_avp_dissector(guint32 vendor_id, guint32 attribute_id, radius_avp_dissector_t radius_avp_dissector) {
radius_vendor_info_t* vendor;
radius_attr_info_t* dictionary_entry;
GHashTable* by_id;
DISSECTOR_ASSERT(radius_avp_dissector != NULL);
if (vendor_id) {
vendor = (radius_vendor_info_t *)g_hash_table_lookup(dict->vendors_by_id,GUINT_TO_POINTER(vendor_id));
if ( ! vendor ) {
vendor = (radius_vendor_info_t *)g_malloc(sizeof(radius_vendor_info_t));
vendor->name = g_strdup_printf("%s-%u",
val_to_str_ext_const(vendor_id, &sminmpec_values_ext, "Unknown"),
vendor_id);
vendor->code = vendor_id;
vendor->attrs_by_id = g_hash_table_new(g_direct_hash,g_direct_equal);
vendor->ett = no_vendor.ett;
vendor->type_octets = 1;
vendor->length_octets = 1;
vendor->has_flags = FALSE;
g_hash_table_insert(dict->vendors_by_id,GUINT_TO_POINTER(vendor->code),vendor);
g_hash_table_insert(dict->vendors_by_name,(gpointer)(vendor->name),vendor);
}
dictionary_entry = (radius_attr_info_t *)g_hash_table_lookup(vendor->attrs_by_id,GUINT_TO_POINTER(attribute_id));
by_id = vendor->attrs_by_id;
} else {
dictionary_entry = (radius_attr_info_t *)g_hash_table_lookup(dict->attrs_by_id,GUINT_TO_POINTER(attribute_id));
by_id = dict->attrs_by_id;
}
if (!dictionary_entry) {
dictionary_entry = (radius_attr_info_t *)g_malloc(sizeof(radius_attr_info_t));
dictionary_entry->name = g_strdup_printf("Unknown-Attribute-%u",attribute_id);
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
g_hash_table_insert(by_id,GUINT_TO_POINTER(dictionary_entry->code),dictionary_entry);
}
dictionary_entry->dissector = radius_avp_dissector;
}
static void
radius_init_protocol(void)
{
if (radius_calls != NULL)
{
g_hash_table_destroy(radius_calls);
radius_calls = NULL;
}
radius_calls = g_hash_table_new(radius_call_hash, radius_call_equal);
}
static void register_radius_fields(const char* unused _U_) {
hf_register_info base_hf[] = {
{ &hf_radius_req,
{ "Request", "radius.req", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if RADIUS request", HFILL }},
{ &hf_radius_rsp,
{ "Response", "radius.rsp", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if RADIUS response", HFILL }},
{ &hf_radius_req_frame,
{ "Request Frame", "radius.reqframe", FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_radius_rsp_frame,
{ "Response Frame", "radius.rspframe", FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_radius_time,
{ "Time from request", "radius.time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0,
"Timedelta between Request and Response", HFILL }},
{ &hf_radius_code,
{ "Code","radius.code", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &radius_pkt_type_codes_ext, 0x0,
NULL, HFILL }},
{ &hf_radius_id,
{ "Identifier", "radius.id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_authenticator,
{ "Authenticator", "radius.authenticator", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_length,
{ "Length","radius.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &(no_dictionary_entry.hf),
{ "Unknown-Attribute","radius.Unknown_Attribute", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &(no_dictionary_entry.hf_len),
{ "Unknown-Attribute Length","radius.Unknown_Attribute.length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_chap_password,
{ "CHAP-Password","radius.CHAP_Password", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_chap_ident,
{ "CHAP Ident","radius.CHAP_Ident", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_chap_string,
{ "CHAP String","radius.CHAP_String", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_framed_ip_address,
{ "Framed-IP-Address","radius.Framed-IP-Address", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_login_ip_host,
{ "Login-IP-Host","radius.Login-IP-Host", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_framed_ipx_network,
{ "Framed-IPX-Network","radius.Framed-IPX-Network", FT_IPXNET, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_cosine_vpi,
{ "Cosine-VPI","radius.Cosine-Vpi", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_cosine_vci,
{ "Cosine-VCI","radius.Cosine-Vci", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_dup,
{ "Duplicate Message", "radius.dup", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_req_dup,
{ "Duplicate Request", "radius.req.dup", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_rsp_dup,
{ "Duplicate Response", "radius.rsp.dup", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_radius_ascend_data_filter,
{ "Ascend Data Filter", "radius.ascenddatafilter", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }}
};
gint *base_ett[] = {
&ett_radius,
&ett_radius_avp,
&ett_eap,
&ett_chap,
&(no_dictionary_entry.ett),
&(no_vendor.ett),
};
hfett_t ri;
char* dir = NULL;
gchar* dict_err_str = NULL;
ri.hf = g_array_new(FALSE,TRUE,sizeof(hf_register_info));
ri.ett = g_array_new(FALSE,TRUE,sizeof(gint *));
ri.vend_vs = g_array_new(TRUE,TRUE,sizeof(value_string));
g_array_append_vals(ri.hf, base_hf, array_length(base_hf));
g_array_append_vals(ri.ett, base_ett, array_length(base_ett));
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
radius_load_dictionary(dict,dir,"dictionary",&dict_err_str);
if (dict_err_str) {
report_failure("radius: %s",dict_err_str);
g_free(dict_err_str);
}
g_hash_table_foreach(dict->attrs_by_id,register_attrs,&ri);
g_hash_table_foreach(dict->vendors_by_id,register_vendors,&ri);
}
g_free(dir);
proto_register_field_array(proto_radius,(hf_register_info*)g_array_data(ri.hf),ri.hf->len);
proto_register_subtree_array((gint**)g_array_data(ri.ett), ri.ett->len);
g_array_free(ri.hf,FALSE);
g_array_free(ri.ett,FALSE);
g_array_free(ri.vend_vs,FALSE);
no_vendor.attrs_by_id = g_hash_table_new(g_direct_hash,g_direct_equal);
radius_register_avp_dissector(0,3,dissect_chap_password);
radius_register_avp_dissector(0,8,dissect_framed_ip_address);
radius_register_avp_dissector(0,14,dissect_login_ip_host);
radius_register_avp_dissector(0,23,dissect_framed_ipx_network);
radius_register_avp_dissector(VENDOR_COSINE,5,dissect_cosine_vpvc);
radius_register_avp_dissector(VENDOR_ASCEND,242,dissect_ascend_data_filter);
radius_register_avp_dissector(VENDOR_REDBACK,242,dissect_ascend_data_filter);
radius_register_avp_dissector(0,242,dissect_ascend_data_filter);
radius_register_avp_dissector(VENDOR_THE3GPP,23,dissect_radius_3gpp_ms_tmime_zone);
}
void
proto_register_radius(void)
{
module_t *radius_module;
proto_radius = proto_register_protocol("Radius Protocol", "RADIUS", "radius");
new_register_dissector("radius", dissect_radius, proto_radius);
register_init_routine(&radius_init_protocol);
radius_module = prefs_register_protocol(proto_radius, proto_reg_handoff_radius);
prefs_register_string_preference(radius_module,"shared_secret","Shared Secret",
"Shared secret used to decode User Passwords",
&shared_secret);
prefs_register_bool_preference(radius_module,"show_length","Show AVP Lengths",
"Whether to add or not to the tree the AVP's payload length",
&show_length);
prefs_register_uint_preference(radius_module, "alternate_port","Alternate Port",
"An alternate UDP port to decode as RADIUS", 10, &alt_port_pref);
prefs_register_uint_preference(radius_module, "request_ttl", "Request TimeToLive",
"Time to live for a radius request used for matching it with a response", 10, &request_ttl);
radius_tap = register_tap("radius");
proto_register_prefix("radius",register_radius_fields);
dict = (radius_dictionary_t *)g_malloc(sizeof(radius_dictionary_t));
dict->attrs_by_id = g_hash_table_new(g_direct_hash,g_direct_equal);
dict->attrs_by_name = g_hash_table_new(g_str_hash,g_str_equal);
dict->vendors_by_id = g_hash_table_new(g_direct_hash,g_direct_equal);
dict->vendors_by_name = g_hash_table_new(g_str_hash,g_str_equal);
dict->tlvs_by_name = g_hash_table_new(g_str_hash,g_str_equal);
}
void
proto_reg_handoff_radius(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t radius_handle;
static guint alt_port;
if (!initialized) {
radius_handle = find_dissector("radius");
dissector_add_uint("udp.port", UDP_PORT_RADIUS, radius_handle);
dissector_add_uint("udp.port", UDP_PORT_RADIUS_NEW, radius_handle);
dissector_add_uint("udp.port", UDP_PORT_RADACCT, radius_handle);
dissector_add_uint("udp.port", UDP_PORT_RADACCT_NEW, radius_handle);
dissector_add_uint("udp.port", UDP_PORT_DAE_OLD, radius_handle);
dissector_add_uint("udp.port", UDP_PORT_DAE, radius_handle);
eap_handle = find_dissector("eap");
initialized = TRUE;
} else {
if (alt_port != 0)
dissector_delete_uint("udp.port", alt_port, radius_handle);
}
if (alt_port_pref != 0)
dissector_add_uint("udp.port", alt_port_pref, radius_handle);
alt_port = alt_port_pref;
}
