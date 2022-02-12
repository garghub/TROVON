const gchar *
tvb_arphrdaddr_to_str(tvbuff_t *tvb, gint offset, int ad_len, guint16 type)
{
if (ad_len == 0)
return "<No address>";
if (ARP_HW_IS_ETHER(type, ad_len)) {
return tvb_ether_to_str(tvb, offset);
}
return tvb_bytes_to_ep_str(tvb, offset, ad_len);
}
static const gchar *
arpproaddr_to_str(const guint8 *ad, int ad_len, guint16 type)
{
if (ad_len == 0)
return "<No address>";
if (ARP_PRO_IS_IPv4(type, ad_len)) {
return ip_to_str(ad);
}
if (ARP_HW_IS_AX25(type, ad_len)) {
return get_ax25_name(ad);
}
return bytes_to_ep_str(ad, ad_len);
}
static const gchar *
atmarpnum_to_str(const guint8 *ad, int ad_tl)
{
int ad_len = ad_tl & ATMARP_LEN_MASK;
gchar *cur;
if (ad_len == 0)
return "<No address>";
if (ad_tl & ATMARP_IS_E164) {
cur = (gchar *)wmem_alloc(wmem_packet_scope(), MAX_E164_STR_LEN+3+1);
if (ad_len > MAX_E164_STR_LEN) {
memcpy(cur, ad, MAX_E164_STR_LEN);
g_snprintf(&cur[MAX_E164_STR_LEN], 3+1, "...");
} else {
memcpy(cur, ad, ad_len);
cur[ad_len + 1] = '\0';
}
return cur;
} else {
return bytes_to_ep_str(ad, ad_len);
}
}
static const gchar *
atmarpsubaddr_to_str(const guint8 *ad, int ad_tl)
{
int ad_len = ad_tl & ATMARP_LEN_MASK;
if (ad_len == 0)
return "<No address>";
return bytes_to_ep_str(ad, ad_len);
}
static void
dissect_atm_number(tvbuff_t *tvb, int offset, int tl, int hf_e164,
int hf_nsap, proto_tree *tree)
{
int len = tl & ATMARP_LEN_MASK;
proto_item *ti;
proto_tree *nsap_tree;
if (tl & ATMARP_IS_E164)
proto_tree_add_item(tree, hf_e164, tvb, offset, len, ENC_BIG_ENDIAN);
else {
ti = proto_tree_add_item(tree, hf_nsap, tvb, offset, len, ENC_BIG_ENDIAN);
if (len >= 20) {
nsap_tree = proto_item_add_subtree(ti, ett_atmarp_nsap);
dissect_atm_nsap(tvb, offset, len, nsap_tree);
}
}
}
void
dissect_atm_nsap(tvbuff_t *tvb, int offset, int len, proto_tree *tree)
{
guint8 afi;
afi = tvb_get_guint8(tvb, offset);
switch (afi) {
case 0x39:
case 0xBD:
proto_tree_add_text(tree, tvb, offset + 0, 3,
"Data Country Code%s: 0x%04X",
(afi == 0xBD) ? " (group)" : "",
tvb_get_ntohs(tvb, offset + 1));
proto_tree_add_text(tree, tvb, offset + 3, 10,
"High Order DSP: %s",
tvb_bytes_to_ep_str(tvb, offset + 3, 10));
proto_tree_add_text(tree, tvb, offset + 13, 6,
"End System Identifier: %s",
tvb_bytes_to_ep_str(tvb, offset + 13, 6));
proto_tree_add_text(tree, tvb, offset + 19, 1,
"Selector: 0x%02X", tvb_get_guint8(tvb, offset + 19));
break;
case 0x47:
case 0xC5:
proto_tree_add_text(tree, tvb, offset + 0, 3,
"International Code Designator%s: 0x%04X",
(afi == 0xC5) ? " (group)" : "",
tvb_get_ntohs(tvb, offset + 1));
proto_tree_add_text(tree, tvb, offset + 3, 10,
"High Order DSP: %s",
tvb_bytes_to_ep_str(tvb, offset + 3, 10));
proto_tree_add_text(tree, tvb, offset + 13, 6,
"End System Identifier: %s",
tvb_bytes_to_ep_str(tvb, offset + 13, 6));
proto_tree_add_text(tree, tvb, offset + 19, 1,
"Selector: 0x%02X", tvb_get_guint8(tvb, offset + 19));
break;
case 0x45:
case 0xC3:
proto_tree_add_text(tree, tvb, offset + 0, 9,
"E.164 ISDN%s: %s",
(afi == 0xC3) ? " (group)" : "",
tvb_bytes_to_ep_str(tvb, offset + 1, 8));
proto_tree_add_text(tree, tvb, offset + 9, 4,
"High Order DSP: %s",
tvb_bytes_to_ep_str(tvb, offset + 3, 10));
proto_tree_add_text(tree, tvb, offset + 13, 6,
"End System Identifier: %s",
tvb_bytes_to_ep_str(tvb, offset + 13, 6));
proto_tree_add_text(tree, tvb, offset + 19, 1,
"Selector: 0x%02X", tvb_get_guint8(tvb, offset + 19));
break;
default:
proto_tree_add_text(tree, tvb, offset, 1,
"Unknown AFI: 0x%02X", afi);
proto_tree_add_text(tree, tvb, offset + 1, len - 1,
"Rest of address: %s",
tvb_bytes_to_ep_str(tvb, offset + 1, len - 1));
break;
}
}
static guint
address_hash_func(gconstpointer v)
{
return GPOINTER_TO_UINT(v);
}
static gint
address_equal_func(gconstpointer v, gconstpointer v2)
{
return v == v2;
}
static guint
duplicate_result_hash_func(gconstpointer v)
{
const duplicate_result_key *key = (const duplicate_result_key*)v;
return (key->frame_number + key->ip_address);
}
static gint
duplicate_result_equal_func(gconstpointer v, gconstpointer v2)
{
const duplicate_result_key *key1 = (const duplicate_result_key*)v;
const duplicate_result_key *key2 = (const duplicate_result_key*)v2;
return (memcmp(key1, key2, sizeof(duplicate_result_key)) == 0);
}
static gboolean
check_for_duplicate_addresses(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb,
const guint8 *mac, guint32 ip,
guint32 *duplicate_ip)
{
address_hash_value *value;
address_hash_value *result = NULL;
duplicate_result_key result_key = {pinfo->fd->num, ip};
if (pinfo->fd->flags.visited) {
result = (address_hash_value *)g_hash_table_lookup(duplicate_result_hash_table,
&result_key);
}
else {
value = (address_hash_value *)g_hash_table_lookup(address_hash_table, GUINT_TO_POINTER(ip));
if (value != NULL)
{
if (pinfo->fd->num > value->frame_num)
{
if ((memcmp(value->mac, mac, 6) == 0))
{
value->frame_num = pinfo->fd->num;
value->time_of_entry = pinfo->fd->abs_ts.secs;
}
else
{
duplicate_result_key *persistent_key = wmem_new(wmem_file_scope(), duplicate_result_key);
memcpy(persistent_key, &result_key, sizeof(duplicate_result_key));
result = wmem_new(wmem_file_scope(), address_hash_value);
memcpy(result, value, sizeof(address_hash_value));
g_hash_table_insert(duplicate_result_hash_table, persistent_key, result);
}
}
}
else
{
value = wmem_new(wmem_file_scope(), struct address_hash_value);
memcpy(value->mac, mac, 6);
value->frame_num = pinfo->fd->num;
value->time_of_entry = pinfo->fd->abs_ts.secs;
g_hash_table_insert(address_hash_table, GUINT_TO_POINTER(ip), value);
}
}
if (result != NULL) {
proto_tree *duplicate_tree;
proto_item *ti = proto_tree_add_text(tree, tvb, 0, 0,
"Duplicate IP address detected for %s (%s) - also in use by %s (frame %u)",
arpproaddr_to_str((guint8*)&ip, 4, ETHERTYPE_IP),
ether_to_str(mac),
ether_to_str(result->mac),
result->frame_num);
PROTO_ITEM_SET_GENERATED(ti);
duplicate_tree = proto_item_add_subtree(ti, ett_arp_duplicate_address);
ti = proto_tree_add_uint(duplicate_tree, hf_arp_duplicate_ip_address_earlier_frame,
tvb, 0, 0, result->frame_num);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti,
&ei_seq_arp_dup_ip,
"Duplicate IP address configured (%s)",
arpproaddr_to_str((guint8*)&ip, 4, ETHERTYPE_IP));
ti = proto_tree_add_uint(duplicate_tree,
hf_arp_duplicate_ip_address_seconds_since_earlier_frame,
tvb, 0, 0,
(guint32)(pinfo->fd->abs_ts.secs - result->time_of_entry));
PROTO_ITEM_SET_GENERATED(ti);
*duplicate_ip = ip;
}
return (result != NULL);
}
static void
arp_init_protocol(void)
{
if (address_hash_table) {
g_hash_table_destroy(address_hash_table);
}
if (duplicate_result_hash_table) {
g_hash_table_destroy(duplicate_result_hash_table);
}
address_hash_table = g_hash_table_new(address_hash_func, address_equal_func);
duplicate_result_hash_table = g_hash_table_new(duplicate_result_hash_func,
duplicate_result_equal_func);
}
static void
request_seen(packet_info *pinfo)
{
if (p_get_proto_data(wmem_file_scope(), pinfo, proto_arp, 0) == 0)
{
arp_request_count++;
}
}
static void
check_for_storm_count(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gboolean report_storm = FALSE;
if (p_get_proto_data(wmem_file_scope(), pinfo, proto_arp, 0) != 0)
{
report_storm = (p_get_proto_data(wmem_file_scope(), pinfo, proto_arp, 0) == (void*)STORM);
}
else
{
gint seconds_delta = (gint) (pinfo->fd->abs_ts.secs - time_at_start_of_count.secs);
gint nseconds_delta = pinfo->fd->abs_ts.nsecs - time_at_start_of_count.nsecs;
gint gap = (seconds_delta*1000) + (nseconds_delta / 1000000);
if ((gap > (gint)global_arp_detect_request_storm_period) ||
(gap < 0))
{
arp_request_count = 1;
time_at_start_of_count = pinfo->fd->abs_ts;
p_add_proto_data(wmem_file_scope(), pinfo, proto_arp, 0, (void*)NO_STORM);
return;
}
else
if (arp_request_count > global_arp_detect_request_storm_packets)
{
report_storm = TRUE;
p_add_proto_data(wmem_file_scope(), pinfo, proto_arp, 0, (void*)STORM);
time_at_start_of_count = pinfo->fd->abs_ts;
}
else
{
p_add_proto_data(wmem_file_scope(), pinfo, proto_arp, 0, (void*)NO_STORM);
}
}
if (report_storm)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, 0,
"Packet storm detected (%u packets in < %u ms)",
global_arp_detect_request_storm_packets,
global_arp_detect_request_storm_period);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti,
&ei_seq_arp_storm,
"ARP packet storm detected (%u packets in < %u ms)",
global_arp_detect_request_storm_packets,
global_arp_detect_request_storm_period);
arp_request_count = 0;
}
}
static void
dissect_atmarp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 ar_hrd;
guint16 ar_pro;
guint8 ar_shtl;
guint8 ar_shl;
guint8 ar_sstl;
guint8 ar_ssl;
guint16 ar_op;
guint8 ar_spln;
guint8 ar_thtl;
guint8 ar_thl;
guint8 ar_tstl;
guint8 ar_tsl;
guint8 ar_tpln;
int tot_len;
proto_tree *arp_tree;
proto_item *ti;
const gchar *op_str;
int sha_offset, ssa_offset, spa_offset;
int tha_offset, tsa_offset, tpa_offset;
const guint8 *sha_val, *ssa_val, *spa_val;
const guint8 *tha_val, *tsa_val, *tpa_val;
const gchar *sha_str, *ssa_str, *spa_str;
const gchar *tha_str, *tsa_str, *tpa_str;
proto_tree *tl_tree;
proto_item *tl;
pinfo->current_proto = "ATMARP";
ar_hrd = tvb_get_ntohs(tvb, ATM_AR_HRD);
ar_pro = tvb_get_ntohs(tvb, ATM_AR_PRO);
ar_shtl = tvb_get_guint8(tvb, ATM_AR_SHTL);
ar_shl = ar_shtl & ATMARP_LEN_MASK;
ar_sstl = tvb_get_guint8(tvb, ATM_AR_SSTL);
ar_ssl = ar_sstl & ATMARP_LEN_MASK;
ar_op = tvb_get_ntohs(tvb, AR_OP);
ar_spln = tvb_get_guint8(tvb, ATM_AR_SPLN);
ar_thtl = tvb_get_guint8(tvb, ATM_AR_THTL);
ar_thl = ar_thtl & ATMARP_LEN_MASK;
ar_tstl = tvb_get_guint8(tvb, ATM_AR_TSTL);
ar_tsl = ar_tstl & ATMARP_LEN_MASK;
ar_tpln = tvb_get_guint8(tvb, ATM_AR_TPLN);
tot_len = MIN_ATMARP_HEADER_SIZE + ar_shl + ar_ssl + ar_spln +
ar_thl + ar_tsl + ar_tpln;
tvb_set_reported_length(tvb, tot_len);
sha_offset = MIN_ATMARP_HEADER_SIZE;
if (ar_shl != 0) {
sha_val = tvb_get_ptr(tvb, sha_offset, ar_shl);
sha_str = atmarpnum_to_str(sha_val, ar_shtl);
} else {
sha_val = NULL;
sha_str = "<No address>";
}
ssa_offset = sha_offset + ar_shl;
if (ar_ssl != 0) {
ssa_val = tvb_get_ptr(tvb, ssa_offset, ar_ssl);
ssa_str = atmarpsubaddr_to_str(ssa_val, ar_sstl);
} else {
ssa_val = NULL;
ssa_str = NULL;
}
spa_offset = ssa_offset + ar_ssl;
spa_val = tvb_get_ptr(tvb, spa_offset, ar_spln);
spa_str = arpproaddr_to_str(spa_val, ar_spln, ar_pro);
tha_offset = spa_offset + ar_spln;
if (ar_thl != 0) {
tha_val = tvb_get_ptr(tvb, tha_offset, ar_thl);
tha_str = atmarpnum_to_str(tha_val, ar_thtl);
} else {
tha_val = NULL;
tha_str = "<No address>";
}
tsa_offset = tha_offset + ar_thl;
if (ar_tsl != 0) {
tsa_val = tvb_get_ptr(tvb, tsa_offset, ar_tsl);
tsa_str = atmarpsubaddr_to_str(tsa_val, ar_tstl);
} else {
tsa_val = NULL;
tsa_str = NULL;
}
tpa_offset = tsa_offset + ar_tsl;
tpa_val = tvb_get_ptr(tvb, tpa_offset, ar_tpln);
tpa_str = arpproaddr_to_str(tpa_val, ar_tpln, ar_pro);
switch (ar_op) {
case ARPOP_REQUEST:
case ARPOP_REPLY:
case ATMARPOP_NAK:
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ATMARP");
break;
case ARPOP_RREQUEST:
case ARPOP_RREPLY:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ATMRARP");
break;
case ARPOP_IREQUEST:
case ARPOP_IREPLY:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Inverse ATMARP");
break;
case ARPOP_MARS_REQUEST:
case ARPOP_MARS_MULTI:
case ARPOP_MARS_MSERV:
case ARPOP_MARS_JOIN:
case ARPOP_MARS_LEAVE:
case ARPOP_MARS_NAK:
case ARPOP_MARS_UNSERV:
case ARPOP_MARS_SJOIN:
case ARPOP_MARS_SLEAVE:
case ARPOP_MARS_GROUPLIST_REQUEST:
case ARPOP_MARS_GROUPLIST_REPLY:
case ARPOP_MARS_REDIRECT_MAP:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MARS");
break;
case ARPOP_MAPOS_UNARP:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MAPOS");
break;
}
switch (ar_op) {
case ARPOP_REQUEST:
col_add_fstr(pinfo->cinfo, COL_INFO, "Who has %s? Tell %s",
tpa_str, spa_str);
break;
case ARPOP_REPLY:
col_add_fstr(pinfo->cinfo, COL_INFO, "%s is at %s%s%s", spa_str, sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""));
break;
case ARPOP_IREQUEST:
col_add_fstr(pinfo->cinfo, COL_INFO, "Who is %s%s%s? Tell %s%s%s",
tha_str,
((tsa_str != NULL) ? "," : ""),
((tsa_str != NULL) ? tsa_str : ""),
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""));
break;
case ARPOP_IREPLY:
col_add_fstr(pinfo->cinfo, COL_INFO, "%s%s%s is at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ATMARPOP_NAK:
col_add_fstr(pinfo->cinfo, COL_INFO, "I don't know where %s is", spa_str);
break;
case ARPOP_MARS_REQUEST:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS request from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_MULTI:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS MULTI request from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_MSERV:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS MSERV request from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_JOIN:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS JOIN request from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_LEAVE:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS LEAVE from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_NAK:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS NAK from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_UNSERV:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS UNSERV request from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_SJOIN:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS SJOIN request from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_SLEAVE:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS SLEAVE from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_GROUPLIST_REQUEST:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS grouplist request from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_GROUPLIST_REPLY:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS grouplist reply from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MARS_REDIRECT_MAP:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS redirect map from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_MAPOS_UNARP:
col_add_fstr(pinfo->cinfo, COL_INFO, "MAPOS UNARP request from %s%s%s at %s",
sha_str,
((ssa_str != NULL) ? "," : ""),
((ssa_str != NULL) ? ssa_str : ""),
spa_str);
break;
case ARPOP_EXP1:
col_add_fstr(pinfo->cinfo, COL_INFO, "Experimental 1 ( opcode %d )", ar_op);
break;
case ARPOP_EXP2:
col_add_fstr(pinfo->cinfo, COL_INFO, "Experimental 2 ( opcode %d )", ar_op);
break;
case 0:
case 65535:
col_add_fstr(pinfo->cinfo, COL_INFO, "Reserved opcode %d", ar_op);
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown ATMARP opcode 0x%04x", ar_op);
break;
}
if (tree) {
if ((op_str = try_val_to_str(ar_op, atmop_vals)))
ti = proto_tree_add_protocol_format(tree, proto_arp, tvb, 0, tot_len,
"ATM Address Resolution Protocol (%s)",
op_str);
else
ti = proto_tree_add_protocol_format(tree, proto_arp, tvb, 0, tot_len,
"ATM Address Resolution Protocol (opcode 0x%04x)", ar_op);
arp_tree = proto_item_add_subtree(ti, ett_arp);
proto_tree_add_uint(arp_tree, hf_arp_hard_type, tvb, ATM_AR_HRD, 2, ar_hrd);
proto_tree_add_uint(arp_tree, hf_arp_proto_type, tvb, ATM_AR_PRO, 2,ar_pro);
tl = proto_tree_add_text(arp_tree, tvb, ATM_AR_SHTL, 1,
"Sender ATM number type/length: %s/%u",
(ar_shtl & ATMARP_IS_E164 ?
"E.164" :
"ATM Forum NSAPA"),
ar_shl);
tl_tree = proto_item_add_subtree(tl, ett_atmarp_tl);
proto_tree_add_boolean(tl_tree, hf_atmarp_sht, tvb, ATM_AR_SHTL, 1, ar_shtl);
proto_tree_add_uint(tl_tree, hf_atmarp_shl, tvb, ATM_AR_SHTL, 1, ar_shtl);
tl = proto_tree_add_text(arp_tree, tvb, ATM_AR_SSTL, 1,
"Sender ATM subaddress type/length: %s/%u",
(ar_sstl & ATMARP_IS_E164 ?
"E.164" :
"ATM Forum NSAPA"),
ar_ssl);
tl_tree = proto_item_add_subtree(tl, ett_atmarp_tl);
proto_tree_add_boolean(tl_tree, hf_atmarp_sst, tvb, ATM_AR_SSTL, 1, ar_sstl);
proto_tree_add_uint(tl_tree, hf_atmarp_ssl, tvb, ATM_AR_SSTL, 1, ar_sstl);
proto_tree_add_uint(arp_tree, hf_arp_opcode, tvb, AR_OP, 2, ar_op);
proto_tree_add_uint(arp_tree, hf_atmarp_spln, tvb, ATM_AR_SPLN, 1, ar_spln);
tl = proto_tree_add_text(arp_tree, tvb, ATM_AR_THTL, 1,
"Target ATM number type/length: %s/%u",
(ar_thtl & ATMARP_IS_E164 ?
"E.164" :
"ATM Forum NSAPA"),
ar_thl);
tl_tree = proto_item_add_subtree(tl, ett_atmarp_tl);
proto_tree_add_boolean(tl_tree, hf_atmarp_tht, tvb, ATM_AR_THTL, 1, ar_thtl);
proto_tree_add_uint(tl_tree, hf_atmarp_thl, tvb, ATM_AR_THTL, 1, ar_thtl);
tl = proto_tree_add_text(arp_tree, tvb, ATM_AR_TSTL, 1,
"Target ATM subaddress type/length: %s/%u",
(ar_tstl & ATMARP_IS_E164 ?
"E.164" :
"ATM Forum NSAPA"),
ar_tsl);
tl_tree = proto_item_add_subtree(tl, ett_atmarp_tl);
proto_tree_add_boolean(tl_tree, hf_atmarp_tst, tvb, ATM_AR_TSTL, 1, ar_tstl);
proto_tree_add_uint(tl_tree, hf_atmarp_tsl, tvb, ATM_AR_TSTL, 1, ar_tstl);
proto_tree_add_uint(arp_tree, hf_atmarp_tpln, tvb, ATM_AR_TPLN, 1, ar_tpln);
if (ar_shl != 0)
dissect_atm_number(tvb, sha_offset, ar_shtl, hf_atmarp_src_atm_num_e164,
hf_atmarp_src_atm_num_nsap, arp_tree);
if (ar_ssl != 0)
proto_tree_add_bytes_format_value(arp_tree, hf_atmarp_src_atm_subaddr, tvb, ssa_offset,
ar_ssl,
ssa_val,
"%s", ssa_str);
if (ar_spln != 0) {
proto_tree_add_item(arp_tree,
ARP_PRO_IS_IPv4(ar_pro, ar_spln) ? hf_arp_src_proto_ipv4
: hf_arp_src_proto,
tvb, spa_offset, ar_spln, ENC_BIG_ENDIAN);
}
if (ar_thl != 0)
dissect_atm_number(tvb, tha_offset, ar_thtl, hf_atmarp_dst_atm_num_e164,
hf_atmarp_dst_atm_num_nsap, arp_tree);
if (ar_tsl != 0)
proto_tree_add_bytes_format_value(arp_tree, hf_atmarp_dst_atm_subaddr, tvb, tsa_offset,
ar_tsl,
tsa_val,
"%s", tsa_str);
if (ar_tpln != 0) {
proto_tree_add_item(arp_tree,
ARP_PRO_IS_IPv4(ar_pro, ar_tpln) ? hf_arp_dst_proto_ipv4
: hf_arp_dst_proto,
tvb, tpa_offset, ar_tpln, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_ax25arp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
#define ARP_AX25 204
guint16 ar_hrd;
guint16 ar_pro;
guint8 ar_hln;
guint8 ar_pln;
guint16 ar_op;
int tot_len;
proto_tree *arp_tree = NULL;
proto_item *ti;
const gchar *op_str;
int sha_offset, spa_offset, tha_offset, tpa_offset;
const guint8 *spa_val, *tpa_val;
gboolean is_gratuitous;
ar_hrd = tvb_get_ntohs(tvb, AR_HRD);
ar_pro = tvb_get_ntohs(tvb, AR_PRO);
ar_hln = tvb_get_guint8(tvb, AR_HLN);
ar_pln = tvb_get_guint8(tvb, AR_PLN);
ar_op = tvb_get_ntohs(tvb, AR_OP);
tot_len = MIN_ARP_HEADER_SIZE + ar_hln*2 + ar_pln*2;
tvb_set_reported_length(tvb, tot_len);
switch (ar_op) {
case ARPOP_REQUEST:
if (global_arp_detect_request_storm)
request_seen(pinfo);
case ARPOP_REPLY:
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ARP");
break;
case ARPOP_RREQUEST:
case ARPOP_RREPLY:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RARP");
break;
case ARPOP_IREQUEST:
case ARPOP_IREPLY:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Inverse ARP");
break;
}
sha_offset = MIN_ARP_HEADER_SIZE;
spa_offset = sha_offset + ar_hln;
tha_offset = spa_offset + ar_pln;
tpa_offset = tha_offset + ar_hln;
spa_val = tvb_get_ptr(tvb, spa_offset, ar_pln);
tpa_val = tvb_get_ptr(tvb, tpa_offset, ar_pln);
if (((ar_op == ARPOP_REQUEST) || (ar_op == ARPOP_REPLY)) && (memcmp(spa_val, tpa_val, ar_pln) == 0))
is_gratuitous = TRUE;
else
is_gratuitous = FALSE;
switch (ar_op) {
case ARPOP_REQUEST:
if (is_gratuitous)
col_add_fstr(pinfo->cinfo, COL_INFO, "Gratuitous ARP for %s (Request)",
arpproaddr_to_str(tpa_val, ar_pln, ar_pro));
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Who has %s? Tell %s",
arpproaddr_to_str(tpa_val, ar_pln, ar_pro),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_REPLY:
if (is_gratuitous)
col_add_fstr(pinfo->cinfo, COL_INFO, "Gratuitous ARP for %s (Reply)",
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%s is at %s",
arpproaddr_to_str(spa_val, ar_pln, ar_pro),
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd));
break;
case ARPOP_RREQUEST:
case ARPOP_IREQUEST:
col_add_fstr(pinfo->cinfo, COL_INFO, "Who is %s? Tell %s",
tvb_arphrdaddr_to_str(tvb, tha_offset, ar_hln, ar_hrd),
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd));
break;
case ARPOP_RREPLY:
col_add_fstr(pinfo->cinfo, COL_INFO, "%s is at %s",
tvb_arphrdaddr_to_str(tvb, tha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(tpa_val, ar_pln, ar_pro));
break;
case ARPOP_IREPLY:
col_add_fstr(pinfo->cinfo, COL_INFO, "%s is at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown ARP opcode 0x%04x", ar_op);
break;
}
if (tree) {
if ((op_str = try_val_to_str(ar_op, op_vals))) {
if (is_gratuitous && (ar_op == ARPOP_REQUEST))
op_str = "request/gratuitous ARP";
if (is_gratuitous && (ar_op == ARPOP_REPLY))
op_str = "reply/gratuitous ARP";
ti = proto_tree_add_protocol_format(tree, proto_arp, tvb, 0, tot_len,
"Address Resolution Protocol (%s)", op_str);
} else
ti = proto_tree_add_protocol_format(tree, proto_arp, tvb, 0, tot_len,
"Address Resolution Protocol (opcode 0x%04x)", ar_op);
arp_tree = proto_item_add_subtree(ti, ett_arp);
proto_tree_add_uint(arp_tree, hf_arp_hard_type, tvb, AR_HRD, 2, ar_hrd);
proto_tree_add_uint(arp_tree, hf_arp_proto_type, tvb, AR_PRO, 2, ar_pro);
proto_tree_add_uint(arp_tree, hf_arp_hard_size, tvb, AR_HLN, 1, ar_hln);
proto_tree_add_uint(arp_tree, hf_arp_proto_size, tvb, AR_PLN, 1, ar_pln);
proto_tree_add_uint(arp_tree, hf_arp_opcode, tvb, AR_OP, 2, ar_op);
if (ar_hln != 0) {
proto_tree_add_item(arp_tree,
ARP_HW_IS_AX25(ar_hrd, ar_hln) ? hf_arp_src_hw_ax25 : hf_arp_src_hw,
tvb, sha_offset, ar_hln, FALSE);
}
if (ar_pln != 0) {
proto_tree_add_item(arp_tree,
ARP_PRO_IS_IPv4(ar_pro, ar_pln) ? hf_arp_src_proto_ipv4
: hf_arp_src_proto,
tvb, spa_offset, ar_pln, FALSE);
}
if (ar_hln != 0) {
proto_tree_add_item(arp_tree,
ARP_HW_IS_AX25(ar_hrd, ar_hln) ? hf_arp_dst_hw_ax25 : hf_arp_dst_hw,
tvb, tha_offset, ar_hln, FALSE);
}
if (ar_pln != 0) {
proto_tree_add_item(arp_tree,
ARP_PRO_IS_IPv4(ar_pro, ar_pln) ? hf_arp_dst_proto_ipv4
: hf_arp_dst_proto,
tvb, tpa_offset, ar_pln, FALSE);
}
}
if (global_arp_detect_request_storm)
{
check_for_storm_count(tvb, pinfo, arp_tree);
}
}
static void
dissect_arp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 ar_hrd;
guint16 ar_pro;
guint8 ar_hln;
guint8 ar_pln;
guint16 ar_op;
int tot_len;
proto_tree *arp_tree = NULL;
proto_item *ti, *item;
const gchar *op_str;
int sha_offset, spa_offset, tha_offset, tpa_offset;
const guint8 *spa_val, *tpa_val;
gboolean is_gratuitous;
gboolean duplicate_detected = FALSE;
guint32 duplicate_ip = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ARP");
col_clear(pinfo->cinfo, COL_INFO);
ar_hrd = tvb_get_ntohs(tvb, AR_HRD);
if (ar_hrd == ARPHRD_ATM2225) {
call_dissector(atmarp_handle, tvb, pinfo, tree);
return;
}
if (ar_hrd == ARPHRD_AX25) {
call_dissector(ax25arp_handle, tvb, pinfo, tree);
return;
}
ar_pro = tvb_get_ntohs(tvb, AR_PRO);
ar_hln = tvb_get_guint8(tvb, AR_HLN);
ar_pln = tvb_get_guint8(tvb, AR_PLN);
ar_op = tvb_get_ntohs(tvb, AR_OP);
tot_len = MIN_ARP_HEADER_SIZE + ar_hln*2 + ar_pln*2;
tvb_set_reported_length(tvb, tot_len);
switch (ar_op) {
case ARPOP_REQUEST:
if (global_arp_detect_request_storm)
{
request_seen(pinfo);
}
case ARPOP_REPLY:
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ARP");
break;
case ARPOP_RREQUEST:
case ARPOP_RREPLY:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RARP");
break;
case ARPOP_DRARPREQUEST:
case ARPOP_DRARPREPLY:
case ARPOP_DRARPERROR:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DRARP");
break;
case ARPOP_IREQUEST:
case ARPOP_IREPLY:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Inverse ARP");
break;
case ARPOP_MARS_REQUEST:
case ARPOP_MARS_MULTI:
case ARPOP_MARS_MSERV:
case ARPOP_MARS_JOIN:
case ARPOP_MARS_LEAVE:
case ARPOP_MARS_NAK:
case ARPOP_MARS_UNSERV:
case ARPOP_MARS_SJOIN:
case ARPOP_MARS_SLEAVE:
case ARPOP_MARS_GROUPLIST_REQUEST:
case ARPOP_MARS_GROUPLIST_REPLY:
case ARPOP_MARS_REDIRECT_MAP:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MARS");
break;
case ARPOP_MAPOS_UNARP:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MAPOS");
break;
}
sha_offset = MIN_ARP_HEADER_SIZE;
spa_offset = sha_offset + ar_hln;
tha_offset = spa_offset + ar_pln;
tpa_offset = tha_offset + ar_hln;
if ((ar_op == ARPOP_REPLY || ar_op == ARPOP_REQUEST) &&
ARP_HW_IS_ETHER(ar_hrd, ar_hln) &&
ARP_PRO_IS_IPv4(ar_pro, ar_pln)) {
guint32 ip;
const guint8 *mac;
ip = tvb_get_ipv4(tvb, spa_offset);
mac = tvb_get_ptr(tvb, sha_offset, 6);
if ((mac[0] & 0x01) == 0 && memcmp(mac, mac_allzero, 6) != 0 && ip != 0)
{
add_ether_byip(ip, mac);
if (global_arp_detect_duplicate_ip_addresses)
{
duplicate_detected =
check_for_duplicate_addresses(pinfo, tree, tvb, mac, ip,
&duplicate_ip);
}
}
ip = tvb_get_ipv4(tvb, tpa_offset);
mac = tvb_get_ptr(tvb, tha_offset, 6);
if ((mac[0] & 0x01) == 0 && memcmp(mac, mac_allzero, 6) != 0 && ip != 0
&& ar_op != ARPOP_REQUEST)
{
add_ether_byip(ip, mac);
if (global_arp_detect_duplicate_ip_addresses && (duplicate_ip!=ip))
{
duplicate_detected =
check_for_duplicate_addresses(pinfo, tree, tvb, mac, ip,
&duplicate_ip);
}
}
}
spa_val = tvb_get_ptr(tvb, spa_offset, ar_pln);
tpa_val = tvb_get_ptr(tvb, tpa_offset, ar_pln);
if (((ar_op == ARPOP_REQUEST) || (ar_op == ARPOP_REPLY)) && (memcmp(spa_val, tpa_val, ar_pln) == 0))
is_gratuitous = TRUE;
else
is_gratuitous = FALSE;
switch (ar_op) {
case ARPOP_REQUEST:
if (is_gratuitous)
col_add_fstr(pinfo->cinfo, COL_INFO, "Gratuitous ARP for %s (Request)",
arpproaddr_to_str(tpa_val, ar_pln, ar_pro));
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Who has %s? Tell %s",
arpproaddr_to_str(tpa_val, ar_pln, ar_pro),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_REPLY:
if (is_gratuitous)
col_add_fstr(pinfo->cinfo, COL_INFO, "Gratuitous ARP for %s (Reply)",
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%s is at %s",
arpproaddr_to_str(spa_val, ar_pln, ar_pro),
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd));
break;
case ARPOP_RREQUEST:
case ARPOP_IREQUEST:
case ARPOP_DRARPREQUEST:
col_add_fstr(pinfo->cinfo, COL_INFO, "Who is %s? Tell %s",
tvb_arphrdaddr_to_str(tvb, tha_offset, ar_hln, ar_hrd),
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd));
break;
case ARPOP_RREPLY:
case ARPOP_DRARPREPLY:
col_add_fstr(pinfo->cinfo, COL_INFO, "%s is at %s",
tvb_arphrdaddr_to_str(tvb, tha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(tpa_val, ar_pln, ar_pro));
break;
case ARPOP_DRARPERROR:
col_add_fstr(pinfo->cinfo, COL_INFO, "DRARP Error");
break;
case ARPOP_IREPLY:
col_add_fstr(pinfo->cinfo, COL_INFO, "%s is at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ATMARPOP_NAK:
col_add_fstr(pinfo->cinfo, COL_INFO, "ARP NAK");
break;
case ARPOP_MARS_REQUEST:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS request from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_MULTI:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS MULTI request from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_MSERV:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS MSERV request from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_JOIN:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS JOIN request from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_LEAVE:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS LEAVE from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_NAK:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS NAK from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_UNSERV:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS UNSERV request from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_SJOIN:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS SJOIN request from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_SLEAVE:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS SLEAVE from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_GROUPLIST_REQUEST:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS grouplist request from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_GROUPLIST_REPLY:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS grouplist reply from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MARS_REDIRECT_MAP:
col_add_fstr(pinfo->cinfo, COL_INFO, "MARS redirect map from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_MAPOS_UNARP:
col_add_fstr(pinfo->cinfo, COL_INFO, "MAPOS UNARP request from %s at %s",
tvb_arphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd),
arpproaddr_to_str(spa_val, ar_pln, ar_pro));
break;
case ARPOP_EXP1:
col_add_fstr(pinfo->cinfo, COL_INFO, "Experimental 1 ( opcode %d )", ar_op);
break;
case ARPOP_EXP2:
col_add_fstr(pinfo->cinfo, COL_INFO, "Experimental 2 ( opcode %d )", ar_op);
break;
case 0:
case 65535:
col_add_fstr(pinfo->cinfo, COL_INFO, "Reserved opcode %d", ar_op);
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown ARP opcode 0x%04x", ar_op);
break;
}
if (tree) {
if ((op_str = try_val_to_str(ar_op, op_vals))) {
if (is_gratuitous && (ar_op == ARPOP_REQUEST))
op_str = "request/gratuitous ARP";
if (is_gratuitous && (ar_op == ARPOP_REPLY))
op_str = "reply/gratuitous ARP";
ti = proto_tree_add_protocol_format(tree, proto_arp, tvb, 0, tot_len,
"Address Resolution Protocol (%s)", op_str);
} else
ti = proto_tree_add_protocol_format(tree, proto_arp, tvb, 0, tot_len,
"Address Resolution Protocol (opcode 0x%04x)", ar_op);
arp_tree = proto_item_add_subtree(ti, ett_arp);
proto_tree_add_uint(arp_tree, hf_arp_hard_type, tvb, AR_HRD, 2, ar_hrd);
proto_tree_add_uint(arp_tree, hf_arp_proto_type, tvb, AR_PRO, 2, ar_pro);
proto_tree_add_uint(arp_tree, hf_arp_hard_size, tvb, AR_HLN, 1, ar_hln);
proto_tree_add_uint(arp_tree, hf_arp_proto_size, tvb, AR_PLN, 1, ar_pln);
proto_tree_add_uint(arp_tree, hf_arp_opcode, tvb, AR_OP, 2, ar_op);
if (is_gratuitous)
{
item = proto_tree_add_boolean(arp_tree, hf_arp_isgratuitous, tvb, 0, 0, is_gratuitous);
PROTO_ITEM_SET_GENERATED(item);
}
if (ar_hln != 0) {
proto_tree_add_item(arp_tree,
ARP_HW_IS_ETHER(ar_hrd, ar_hln) ?
hf_arp_src_hw_mac :
hf_arp_src_hw,
tvb, sha_offset, ar_hln, ENC_BIG_ENDIAN);
}
if (ar_pln != 0) {
proto_tree_add_item(arp_tree,
ARP_PRO_IS_IPv4(ar_pro, ar_pln) ?
hf_arp_src_proto_ipv4 :
hf_arp_src_proto,
tvb, spa_offset, ar_pln, ENC_BIG_ENDIAN);
}
if (ar_hln != 0) {
proto_tree_add_item(arp_tree,
ARP_HW_IS_ETHER(ar_hrd, ar_hln) ?
hf_arp_dst_hw_mac :
hf_arp_dst_hw,
tvb, tha_offset, ar_hln, ENC_BIG_ENDIAN);
}
if (ar_pln != 0 && ar_op != ARPOP_DRARPERROR) {
proto_tree_add_item(arp_tree,
ARP_PRO_IS_IPv4(ar_pro, ar_pln) ?
hf_arp_dst_proto_ipv4 :
hf_arp_dst_proto,
tvb, tpa_offset, ar_pln, ENC_BIG_ENDIAN);
}
else if (ar_pln != 0 && ar_op == ARPOP_DRARPERROR) {
proto_tree_add_item(arp_tree, hf_drarp_error_status, tvb, tpa_offset, 1, ENC_BIG_ENDIAN);
}
}
if (global_arp_detect_request_storm)
{
check_for_storm_count(tvb, pinfo, arp_tree);
}
if (duplicate_detected)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " (duplicate use of %s detected!)",
arpproaddr_to_str((guint8*)&duplicate_ip, 4, ETHERTYPE_IP));
}
}
void
proto_register_arp(void)
{
static struct true_false_string tfs_type_bit = { "E.164", "ATM Forum NSAPA" };
static hf_register_info hf[] = {
{ &hf_arp_hard_type,
{ "Hardware type", "arp.hw.type",
FT_UINT16, BASE_DEC, VALS(arp_hrd_vals), 0x0,
NULL, HFILL }},
{ &hf_arp_proto_type,
{ "Protocol type", "arp.proto.type",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }},
{ &hf_arp_hard_size,
{ "Hardware size", "arp.hw.size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atmarp_sht,
{ "Sender ATM number type", "arp.src.htype",
FT_BOOLEAN, 8, TFS(&tfs_type_bit), ATMARP_IS_E164,
NULL, HFILL }},
{ &hf_atmarp_shl,
{ "Sender ATM number length", "arp.src.hlen",
FT_UINT8, BASE_DEC, NULL, ATMARP_LEN_MASK,
NULL, HFILL }},
{ &hf_atmarp_sst,
{ "Sender ATM subaddress type", "arp.src.stype",
FT_BOOLEAN, 8, TFS(&tfs_type_bit), ATMARP_IS_E164,
NULL, HFILL }},
{ &hf_atmarp_ssl,
{ "Sender ATM subaddress length", "arp.src.slen",
FT_UINT8, BASE_DEC, NULL, ATMARP_LEN_MASK,
NULL, HFILL }},
{ &hf_arp_proto_size,
{ "Protocol size", "arp.proto.size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_opcode,
{ "Opcode", "arp.opcode",
FT_UINT16, BASE_DEC, VALS(op_vals), 0x0,
NULL, HFILL }},
{ &hf_arp_isgratuitous,
{ "Is gratuitous", "arp.isgratuitous",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_true_false), 0x0,
NULL, HFILL }},
{ &hf_atmarp_spln,
{ "Sender protocol size", "arp.src.pln",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atmarp_tht,
{ "Target ATM number type", "arp.dst.htype",
FT_BOOLEAN, 8, TFS(&tfs_type_bit), ATMARP_IS_E164,
NULL, HFILL }},
{ &hf_atmarp_thl,
{ "Target ATM number length", "arp.dst.hlen",
FT_UINT8, BASE_DEC, NULL, ATMARP_LEN_MASK,
NULL, HFILL }},
{ &hf_atmarp_tst,
{ "Target ATM subaddress type", "arp.dst.stype",
FT_BOOLEAN, 8, TFS(&tfs_type_bit), ATMARP_IS_E164,
NULL, HFILL }},
{ &hf_atmarp_tsl,
{ "Target ATM subaddress length", "arp.dst.slen",
FT_UINT8, BASE_DEC, NULL, ATMARP_LEN_MASK,
NULL, HFILL }},
{ &hf_atmarp_tpln,
{ "Target protocol size", "arp.dst.pln",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_src_hw,
{ "Sender hardware address", "arp.src.hw",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_src_hw_mac,
{ "Sender MAC address", "arp.src.hw_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_src_hw_ax25,
{ "Sender AX.25 address", "arp.src.hw_ax25",
FT_AX25, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atmarp_src_atm_num_e164,
{ "Sender ATM number (E.164)", "arp.src.atm_num_e164",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atmarp_src_atm_num_nsap,
{ "Sender ATM number (NSAP)", "arp.src.atm_num_nsap",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atmarp_src_atm_subaddr,
{ "Sender ATM subaddress", "arp.src.atm_subaddr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_src_proto,
{ "Sender protocol address", "arp.src.proto",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_src_proto_ipv4,
{ "Sender IP address", "arp.src.proto_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_dst_hw,
{ "Target hardware address", "arp.dst.hw",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_dst_hw_mac,
{ "Target MAC address", "arp.dst.hw_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_dst_hw_ax25,
{ "Target AX.25 address", "arp.dst.hw_ax25",
FT_AX25, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atmarp_dst_atm_num_e164,
{ "Target ATM number (E.164)", "arp.dst.atm_num_e164",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atmarp_dst_atm_num_nsap,
{ "Target ATM number (NSAP)", "arp.dst.atm_num_nsap",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atmarp_dst_atm_subaddr,
{ "Target ATM subaddress", "arp.dst.atm_subaddr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_dst_proto,
{ "Target protocol address", "arp.dst.proto",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_dst_proto_ipv4,
{ "Target IP address", "arp.dst.proto_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_drarp_error_status,
{ "DRARP error status", "arp.dst.drarp_error_status",
FT_UINT16, BASE_DEC, VALS(drarp_status), 0x0,
NULL, HFILL }},
{ &hf_arp_duplicate_ip_address_earlier_frame,
{ "Frame showing earlier use of IP address", "arp.duplicate-address-frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_arp_duplicate_ip_address_seconds_since_earlier_frame,
{ "Seconds since earlier frame seen", "arp.seconds-since-duplicate-address-frame",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_arp,
&ett_atmarp_nsap,
&ett_atmarp_tl,
&ett_arp_duplicate_address
};
static ei_register_info ei[] = {
{ &ei_seq_arp_dup_ip, { "arp.duplicate-address-detected", PI_SEQUENCE, PI_WARN, "Duplicate IP address configured", EXPFILL }},
{ &ei_seq_arp_storm, { "arp.packet-storm-detected", PI_SEQUENCE, PI_NOTE, "ARP packet storm detected", EXPFILL }},
};
module_t *arp_module;
expert_module_t* expert_arp;
proto_arp = proto_register_protocol("Address Resolution Protocol",
"ARP/RARP", "arp");
proto_register_field_array(proto_arp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_arp = expert_register_protocol(proto_arp);
expert_register_field_array(expert_arp, ei, array_length(ei));
atmarp_handle = create_dissector_handle(dissect_atmarp, proto_arp);
ax25arp_handle = create_dissector_handle(dissect_ax25arp, proto_arp);
arp_handle = register_dissector( "arp" , dissect_arp, proto_arp );
arp_module = prefs_register_protocol(proto_arp, NULL);
prefs_register_bool_preference(arp_module, "detect_request_storms",
"Detect ARP request storms",
"Attempt to detect excessive rate of ARP requests",
&global_arp_detect_request_storm);
prefs_register_uint_preference(arp_module, "detect_storm_number_of_packets",
"Number of requests to detect during period",
"Number of requests needed within period to indicate a storm",
10, &global_arp_detect_request_storm_packets);
prefs_register_uint_preference(arp_module, "detect_storm_period",
"Detection period (in ms)",
"Period in milliseconds during which a packet storm may be detected",
10, &global_arp_detect_request_storm_period);
prefs_register_bool_preference(arp_module, "detect_duplicate_ips",
"Detect duplicate IP address configuration",
"Attempt to detect duplicate use of IP addresses",
&global_arp_detect_duplicate_ip_addresses);
register_init_routine(&arp_init_protocol);
}
void
proto_reg_handoff_arp(void)
{
dissector_add_uint("ethertype", ETHERTYPE_ARP, arp_handle);
dissector_add_uint("ethertype", ETHERTYPE_REVARP, arp_handle);
dissector_add_uint("arcnet.protocol_id", ARCNET_PROTO_ARP_1051, arp_handle);
dissector_add_uint("arcnet.protocol_id", ARCNET_PROTO_ARP_1201, arp_handle);
dissector_add_uint("arcnet.protocol_id", ARCNET_PROTO_RARP_1201, arp_handle);
dissector_add_uint("ax25.pid", AX25_P_ARP, arp_handle);
}
