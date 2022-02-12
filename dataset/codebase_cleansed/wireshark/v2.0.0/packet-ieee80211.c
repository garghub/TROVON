static void *
uat_wep_key_record_copy_cb(void* n, const void* o, size_t siz _U_)
{
uat_wep_key_record_t* new_key = (uat_wep_key_record_t *)n;
const uat_wep_key_record_t* old_key = (const uat_wep_key_record_t *)o;
if (old_key->string) {
new_key->string = g_strdup(old_key->string);
} else {
new_key->string = NULL;
}
return new_key;
}
static gboolean
uat_wep_key_record_update_cb(void* r, char** err)
{
uat_wep_key_record_t* rec = (uat_wep_key_record_t *)r;
decryption_key_t* dk;
guint dk_type;
if (rec->string == NULL) {
*err = g_strdup("Key can't be blank");
return FALSE;
}
g_strstrip(rec->string);
dk = parse_key_string(rec->string, rec->key);
if (dk != NULL) {
dk_type = dk->type;
free_key_string(dk);
switch (dk_type) {
case AIRPDCAP_KEY_TYPE_WEP:
case AIRPDCAP_KEY_TYPE_WEP_40:
case AIRPDCAP_KEY_TYPE_WEP_104:
if (rec->key != AIRPDCAP_KEY_TYPE_WEP) {
*err = g_strdup("Invalid key format");
return FALSE;
}
break;
case AIRPDCAP_KEY_TYPE_WPA_PWD:
if (rec->key != AIRPDCAP_KEY_TYPE_WPA_PWD) {
*err = g_strdup("Invalid key format");
return FALSE;
}
break;
case AIRPDCAP_KEY_TYPE_WPA_PSK:
if (rec->key != AIRPDCAP_KEY_TYPE_WPA_PSK) {
*err = g_strdup("Invalid key format");
return FALSE;
}
break;
default:
*err = g_strdup("Invalid key format");
return FALSE;
break;
}
} else {
*err = g_strdup("Invalid key format");
return FALSE;
}
return TRUE;
}
static void
uat_wep_key_record_free_cb(void*r)
{
uat_wep_key_record_t* key = (uat_wep_key_record_t *)r;
if (key->string) g_free(key->string);
}
gboolean is_broadcast_bssid(const address *bssid) {
return addresses_equal(&bssid_broadcast, bssid);
}
static const char* wlan_conv_get_filter_type(conv_item_t* conv, conv_filter_type_e filter)
{
if ((filter == CONV_FT_SRC_ADDRESS) && ((conv->src_address.type == AT_ETHER) || (conv->src_address.type == wlan_address_type)))
return "wlan.sa";
if ((filter == CONV_FT_DST_ADDRESS) && ((conv->dst_address.type == AT_ETHER) || (conv->dst_address.type == wlan_address_type)))
return "wlan.da";
if ((filter == CONV_FT_ANY_ADDRESS) && ((conv->src_address.type == AT_ETHER) || (conv->src_address.type == wlan_address_type)))
return "wlan.addr";
return CONV_FILTER_INVALID;
}
static int
wlan_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pct;
const wlan_hdr_t *whdr=(const wlan_hdr_t *)vip;
add_conversation_table_data(hash, &whdr->src, &whdr->dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, &pinfo->fd->abs_ts, &wlan_ct_dissector_info, PT_NONE);
return 1;
}
static const char* wlan_host_get_filter_type(hostlist_talker_t* host, conv_filter_type_e filter)
{
if ((filter == CONV_FT_ANY_ADDRESS) && (host->myaddress.type == AT_ETHER))
return "wlan.addr";
return CONV_FILTER_INVALID;
}
static int
wlan_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pit;
const wlan_hdr_t *whdr=(const wlan_hdr_t *)vip;
add_hostlist_table_data(hash, &whdr->src, 0, TRUE, 1, pinfo->fd->pkt_len, &wlan_host_dissector_info, PT_NONE);
add_hostlist_table_data(hash, &whdr->dst, 0, FALSE, 1, pinfo->fd->pkt_len, &wlan_host_dissector_info, PT_NONE);
return 1;
}
static const char* wlan_col_filter_str(const address* addr _U_, gboolean is_src)
{
if (is_src)
return "wlan.sa";
return "wlan.da";
}
static const char* wlan_bssid_col_filter_str(const address* addr _U_, gboolean is_src _U_)
{
return "wlan.bssid";
}
static void
beacon_interval_base_custom(gchar *result, guint32 beacon_interval)
{
double temp_double;
temp_double = (double)beacon_interval;
g_snprintf(result, ITEM_LABEL_LENGTH, "%f [Seconds]", (temp_double * 1024 / 1000000));
}
static void
allocation_duration_base_custom(gchar *result, guint32 allocation_duration)
{
double temp_double;
temp_double = (double)allocation_duration;
g_snprintf(result, ITEM_LABEL_LENGTH, "%f [Seconds]", (temp_double / 1000000));
}
static void
extra_one_base_custom(gchar *result, guint32 value)
{
g_snprintf(result, ITEM_LABEL_LENGTH, "%d", value+1);
}
static void
extra_one_mul_two_base_custom(gchar *result, guint32 value)
{
g_snprintf(result, ITEM_LABEL_LENGTH, "%d", (value+1)*2);
}
static int
has_mesh_control(guint16 fcf, guint16 qos_ctl, guint8 mesh_flags)
{
return (((FCF_ADDR_SELECTOR(fcf) == DATA_ADDR_T4) || (FCF_ADDR_SELECTOR(fcf) == DATA_ADDR_T2)) &&
(QOS_MESH_CONTROL_PRESENT(qos_ctl)) &&
((mesh_flags & ~MESH_FLAGS_ADDRESS_EXTENSION) == 0) &&
((mesh_flags & MESH_FLAGS_ADDRESS_EXTENSION) != MESH_FLAGS_ADDRESS_EXTENSION));
}
static int
find_mesh_control_length(guint8 mesh_flags)
{
return 6 + 6*(mesh_flags & MESH_FLAGS_ADDRESS_EXTENSION);
}
static mimo_control_t
get_mimo_control (tvbuff_t *tvb, int offset)
{
guint16 mimo;
mimo_control_t output;
mimo = tvb_get_letohs (tvb, offset);
output.nc = (mimo & 0x0003) + 1;
output.nr = ((mimo & 0x000C) >> 2) + 1;
output.chan_width = (mimo & 0x0010) >> 4;
output.coefficient_size = 4;
switch ((mimo & 0x0060) >> 5)
{
case 0:
output.grouping = 1;
break;
case 1:
output.grouping = 2;
break;
case 2:
output.grouping = 4;
break;
default:
output.grouping = 1;
break;
}
switch ((mimo & 0x0180) >> 7)
{
case 0:
output.coefficient_size = 4;
break;
case 1:
output.coefficient_size = 5;
break;
case 2:
output.coefficient_size = 6;
break;
case 3:
output.coefficient_size = 8;
break;
}
output.codebook_info = (mimo & 0x0600) >> 9;
output.remaining_matrix_segment = (mimo & 0x3800) >> 11;
return output;
}
static int
get_mimo_na (guint8 nr, guint8 nc)
{
if ((nr == 2) && (nc == 1)) {
return 2;
} else if ((nr == 2) && (nc == 2)) {
return 2;
} else if ((nr == 3) && (nc == 1)) {
return 4;
} else if ((nr == 3) && (nc == 2)) {
return 6;
} else if ((nr == 3) && (nc == 3)) {
return 6;
} else if ((nr == 4) && (nc == 1)) {
return 6;
} else if ((nr == 4) && (nc == 2)) {
return 10;
} else if ((nr == 4) && (nc == 3)) {
return 12;
} else if ((nr == 4) && (nc == 4)) {
return 12;
} else{
return 0;
}
}
static int
get_mimo_ns (gboolean chan_width, guint8 output_grouping)
{
int ns = 0;
if (chan_width)
{
switch (output_grouping)
{
case 1:
ns = 114;
break;
case 2:
ns = 58;
break;
case 4:
ns = 30;
break;
default:
ns = 0;
}
} else {
switch (output_grouping)
{
case 1:
ns = 56;
break;
case 2:
ns = 30;
break;
case 4:
ns = 16;
break;
default:
ns = 0;
}
}
return ns;
}
static int
add_mimo_csi_matrices_report (proto_tree *tree, tvbuff_t *tvb, int offset, mimo_control_t mimo_cntrl)
{
proto_tree *snr_tree;
int csi_matrix_size, start_offset;
int ns, i;
start_offset = offset;
snr_tree = proto_tree_add_subtree(tree, tvb, offset, mimo_cntrl.nc,
ett_mimo_report, NULL, "Signal to Noise Ratio");
for (i = 1; i <= mimo_cntrl.nr; i++)
{
guint8 snr;
snr = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(snr_tree, hf_ieee80211_ff_mimo_csi_snr, tvb, offset, 1,
snr, "Channel %d - Signal to Noise Ratio: 0x%02X", i, snr);
offset += 1;
}
ns = get_mimo_ns(mimo_cntrl.chan_width, mimo_cntrl.grouping);
csi_matrix_size = ns*(3+(2*mimo_cntrl.nc*mimo_cntrl.nr*mimo_cntrl.coefficient_size));
csi_matrix_size = roundup2(csi_matrix_size, 8) / 8;
proto_tree_add_item(snr_tree, hf_ieee80211_ff_mimo_csi_matrices, tvb, offset, csi_matrix_size, ENC_NA);
offset += csi_matrix_size;
return offset - start_offset;
}
static int
add_mimo_beamforming_feedback_report (proto_tree *tree, tvbuff_t *tvb, int offset, mimo_control_t mimo_cntrl)
{
proto_tree *snr_tree;
int csi_matrix_size, start_offset;
int ns, i;
start_offset = offset;
snr_tree = proto_tree_add_subtree(tree, tvb, offset, mimo_cntrl.nc, ett_mimo_report, NULL, "Signal to Noise Ratio");
for (i = 1; i <= mimo_cntrl.nc; i++)
{
guint8 snr;
snr = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(snr_tree, hf_ieee80211_ff_mimo_csi_snr, tvb, offset, 1,
snr, "Stream %d - Signal to Noise Ratio: 0x%02X", i, snr);
offset += 1;
}
ns = get_mimo_ns(mimo_cntrl.chan_width, mimo_cntrl.grouping);
csi_matrix_size = ns*(2*mimo_cntrl.nc*mimo_cntrl.nr*mimo_cntrl.coefficient_size);
csi_matrix_size = roundup2(csi_matrix_size, 8) / 8;
proto_tree_add_item(snr_tree, hf_ieee80211_ff_mimo_csi_bf_matrices, tvb, offset, csi_matrix_size, ENC_NA);
offset += csi_matrix_size;
return offset - start_offset;
}
static int
add_mimo_compressed_beamforming_feedback_report (proto_tree *tree, tvbuff_t *tvb, int offset, mimo_control_t mimo_cntrl)
{
proto_tree *snr_tree;
int csi_matrix_size, start_offset;
int ns, na, i;
start_offset = offset;
snr_tree = proto_tree_add_subtree(tree, tvb, offset, mimo_cntrl.nc,
ett_mimo_report, NULL, "Signal to Noise Ratio");
for (i = 1; i <= mimo_cntrl.nc; i++)
{
guint8 snr;
snr = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(snr_tree, hf_ieee80211_ff_mimo_csi_snr, tvb, offset, 1,
snr, "Stream %d - Signal to Noise Ratio: 0x%02X", i, snr);
offset += 1;
}
na = get_mimo_na(mimo_cntrl.nr, mimo_cntrl.nc);
ns = get_mimo_ns(mimo_cntrl.chan_width, mimo_cntrl.grouping);
csi_matrix_size = ns*(na*((mimo_cntrl.codebook_info+1)*2 + 2)/2);
csi_matrix_size = roundup2(csi_matrix_size, 8) / 8;
proto_tree_add_item(snr_tree, hf_ieee80211_ff_mimo_csi_cbf_matrices, tvb, offset, csi_matrix_size, ENC_NA);
offset += csi_matrix_size;
return offset - start_offset;
}
static void
capture_ieee80211_common (const guchar * pd, int offset, int len,
packet_counts * ld, gboolean datapad)
{
guint16 fcf, hdr_length;
if (!BYTES_ARE_IN_FRAME(offset, len, 2)) {
ld->other += 1;
return;
}
fcf = pletoh16 (&pd[offset]);
if (IS_PROTECTED(FCF_FLAGS(fcf)) && (wlan_ignore_wep == WLAN_IGNORE_WEP_NO)) {
ld->other += 1;
return;
}
switch (COMPOSE_FRAME_TYPE (fcf)) {
case DATA:
case DATA_CF_ACK:
case DATA_CF_POLL:
case DATA_CF_ACK_POLL:
case DATA_QOS_DATA:
case DATA_QOS_DATA_CF_ACK:
case DATA_QOS_DATA_CF_POLL:
case DATA_QOS_DATA_CF_ACK_POLL:
{
hdr_length = (FCF_ADDR_SELECTOR(fcf) == DATA_ADDR_T4) ? DATA_LONG_HDR_LEN : DATA_SHORT_HDR_LEN;
if (DATA_FRAME_IS_QOS(COMPOSE_FRAME_TYPE(fcf))) {
guint16 qosoff;
guint8 mesh_flags;
qosoff = hdr_length;
hdr_length += 2;
if (HAS_HT_CONTROL(FCF_FLAGS(fcf))) {
hdr_length += 4;
}
if (!BYTES_ARE_IN_FRAME(offset, hdr_length, 1)) {
ld->other += 1;
return;
}
mesh_flags = pd[hdr_length];
if (has_mesh_control(fcf, pletoh16(&pd[qosoff]), mesh_flags)) {
hdr_length += find_mesh_control_length(mesh_flags);
}
if (datapad) {
hdr_length = roundup2(hdr_length, 4);
}
}
if (!BYTES_ARE_IN_FRAME(offset+hdr_length, len, 2)) {
ld->other += 1;
return;
}
if ((pd[offset+hdr_length] != 0xaa) && (pd[offset+hdr_length+1] != 0xaa)) {
#if 0
if (BYTES_ARE_IN_FRAME(offset+hdr_length, len, 12)) {
if ((memcmp(&pd[offset+hdr_length+6], pinfo->dl_src.data, 6) == 0) ||
(memcmp(&pd[offset+hdr_length+6], pinfo->dl_dst.data, 6) == 0)) {
capture_eth (pd, offset + hdr_length, len, ld);
return;
}
}
#endif
if ((pd[offset+hdr_length] == 0xff) && (pd[offset+hdr_length+1] == 0xff))
capture_ipx (ld);
else if ((pd[offset+hdr_length] == 0x00) && (pd[offset+hdr_length+1] == 0x00))
capture_llc (pd, offset + hdr_length + 2, len, ld);
}
else {
capture_llc (pd, offset + hdr_length, len, ld);
}
break;
}
default:
ld->other += 1;
break;
}
}
void
capture_ieee80211 (const guchar * pd, int offset, int len, packet_counts * ld)
{
capture_ieee80211_common (pd, offset, len, ld, FALSE);
}
void
capture_ieee80211_datapad (const guchar * pd, int offset, int len,
packet_counts * ld)
{
capture_ieee80211_common (pd, offset, len, ld, TRUE);
}
static proto_tree *
get_fixed_parameter_tree (proto_tree * tree, tvbuff_t *tvb, int start, int size)
{
proto_item *fixed_fields;
fixed_fields = proto_tree_add_item (tree, hf_ieee80211_fixed_parameters, tvb, start, size, ENC_NA);
proto_item_append_text(fixed_fields, " (%d bytes)",size);
return proto_item_add_subtree (fixed_fields, ett_fixed_parameters);
}
static proto_tree *
get_tagged_parameter_tree (proto_tree * tree, tvbuff_t *tvb, int start, int size)
{
proto_item *tagged_fields;
tagged_fields = proto_tree_add_item(tree, hf_ieee80211_tagged_parameters, tvb, start, -1, ENC_NA);
proto_item_append_text(tagged_fields, " (%d bytes)",size);
return proto_item_add_subtree (tagged_fields, ett_tagged_parameters);
}
static int
dissect_vendor_action_marvell(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 octet;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_action_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (octet)
{
case MRVL_ACTION_MESH_MANAGEMENT:
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_action_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (octet)
{
case MRVL_MESH_MGMT_ACTION_RREQ:
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_hopcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_ttl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_rreqid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_sa, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_ssn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_lifetime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_metric, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_dstcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_da, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_dsn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case MRVL_MESH_MGMT_ACTION_RREP:
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_hopcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_ttl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_da, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_dsn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_lifetime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_metric, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_sa, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_ssn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case MRVL_MESH_MGMT_ACTION_RERR:
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_dstcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_da, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_dsn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
default:
break;
}
break;
default:
break;
}
return offset;
}
static guint
dissect_advertisement_protocol(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, int offset, gboolean *anqp)
{
guint8 tag_no, tag_len, left;
proto_item *item = NULL, *adv_item;
proto_tree *adv_tree, *adv_tuple_tree;
if (anqp)
*anqp = FALSE;
tag_no = tvb_get_guint8(tvb, offset);
if (anqp)
item = proto_tree_add_item(tree, hf_ieee80211_tag_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
tag_len = tvb_get_guint8(tvb, offset + 1);
if (tag_no != TAG_ADVERTISEMENT_PROTOCOL) {
expert_add_info_format(pinfo, item, &ei_ieee80211_tag_number,
"Unexpected IE %d (expected Advertisement "
"Protocol)", tag_no);
return 2 + tag_len;
}
if (anqp)
item = proto_tree_add_uint(tree, hf_ieee80211_tag_length, tvb, offset + 1, 1, tag_len);
if (tag_len < 2) {
if (!anqp)
item = proto_tree_add_uint(tree, hf_ieee80211_tag_length, tvb, offset + 1, 1, tag_len);
expert_add_info_format(pinfo, item, &ei_ieee80211_tag_length,
"Advertisement Protocol: IE must be at least 2 "
"octets long");
return 2 + tag_len;
}
left = tag_len;
offset += 2;
adv_tree = proto_tree_add_subtree(tree, tvb, offset, left,
ett_adv_proto, &adv_item, "Advertisement Protocol element");
while (left >= 2) {
guint8 id;
id = tvb_get_guint8(tvb, offset + 1);
if (id == 0)
proto_item_append_text(adv_item, ": ANQP");
adv_tuple_tree = proto_tree_add_subtree_format(adv_tree, tvb, offset, 2, ett_adv_proto_tuple, &item,
"Advertisement Protocol Tuple: %s",
val_to_str(id, adv_proto_id_vals,
"Unknown (%d)"));
proto_tree_add_item(adv_tuple_tree,
hf_ieee80211_tag_adv_proto_resp_len_limit, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adv_tuple_tree,
hf_ieee80211_tag_adv_proto_pame_bi, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
left--;
proto_tree_add_item(adv_tuple_tree, hf_ieee80211_tag_adv_proto_id, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
left--;
if ((id == 0) && anqp)
*anqp = TRUE;
if (id == 221) {
guint8 len = tvb_get_guint8(tvb, offset);
offset += 1;
left -= 1;
if (len > left) {
expert_add_info_format(pinfo, item, &ei_ieee80211_tag_length,
"Vendor specific info length error");
return 2 + tag_len;
}
proto_tree_add_item(adv_tuple_tree, hf_ieee80211_tag_adv_proto_vs_info, tvb,
offset, len, ENC_NA);
offset += len;
left -= len;
}
}
if (left) {
expert_add_info_format(pinfo, item, &ei_ieee80211_extra_data,
"Unexpected extra data in the end");
}
return 2 + tag_len;
}
static void
dissect_anqp_query_list(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, int end)
{
while (offset + 2 <= end) {
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_query_id,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if (offset != end) {
expert_add_info_format(pinfo, tree, &ei_ieee80211_ff_anqp_info_length,
"Unexpected ANQP Query list format");
}
}
static void dissect_hs20_anqp_hs_capability_list(proto_tree *tree,
tvbuff_t *tvb,
int offset, int end)
{
while (offset < end) {
proto_tree_add_item(tree, hf_hs20_anqp_hs_capability_list,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
}
}
static void
dissect_anqp_capab_list(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, int end)
{
guint16 id, len;
proto_item *item;
proto_tree *vtree;
guint32 oui;
guint8 subtype;
while (offset + 2 <= end) {
id = tvb_get_letohs(tvb, offset);
item = proto_tree_add_item(tree, hf_ieee80211_ff_anqp_capability,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (id == ANQP_INFO_ANQP_VENDOR_SPECIFIC_LIST) {
vtree = proto_item_add_subtree(item, ett_anqp_vendor_capab);
len = tvb_get_letohs(tvb, offset);
proto_tree_add_item(vtree, hf_ieee80211_ff_anqp_capability_vlen,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if ((len < 3) || ((offset + len) > end)) {
expert_add_info(pinfo, tree, &ei_ieee80211_ff_anqp_capability);
return;
}
oui = tvb_get_ntoh24(tvb, offset);
proto_tree_add_item(vtree, hf_ieee80211_tag_oui, tvb, offset, 3, ENC_NA);
offset += 3;
len -= 3;
switch (oui) {
case OUI_WFA:
if (len == 0)
break;
subtype = tvb_get_guint8(tvb, offset);
proto_item_append_text(vtree, " - WFA - %s",
val_to_str(subtype, wfa_subtype_vals,
"Unknown (%u)"));
proto_tree_add_item(vtree, hf_ieee80211_anqp_wfa_subtype,
tvb, offset, 1, ENC_NA);
offset++;
len--;
switch (subtype) {
case WFA_SUBTYPE_HS20_ANQP:
dissect_hs20_anqp_hs_capability_list(vtree, tvb, offset, end);
break;
default:
proto_tree_add_item(vtree, hf_ieee80211_ff_anqp_capability_vendor,
tvb, offset, len, ENC_NA);
break;
}
break;
default:
proto_tree_add_item(vtree, hf_ieee80211_ff_anqp_capability_vendor,
tvb, offset, len, ENC_NA);
break;
}
offset += len;
}
}
if (offset != end) {
expert_add_info_format(pinfo, tree, &ei_ieee80211_ff_anqp_info_length,
"Unexpected ANQP Capability list format");
}
}
static void
dissect_venue_info(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_venue_info_group,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_ff_venue_info_type,
tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_venue_name_info(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, int end)
{
proto_item *item;
dissect_venue_info(tree, tvb, offset);
offset += 2;
while (offset + 4 <= end) {
guint8 vlen = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree, hf_ieee80211_ff_anqp_venue_length,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if ((vlen > (end - offset)) || (vlen < 3)) {
expert_add_info(pinfo, item, &ei_ieee80211_ff_anqp_venue_length);
break;
}
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_venue_language,
tvb, offset, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_venue_name,
tvb, offset + 3, vlen - 3, ENC_UTF_8|ENC_NA);
offset += vlen;
}
}
static void
dissect_network_auth_type(proto_tree *tree, tvbuff_t *tvb, int offset, int end)
{
while (offset + 3 <= end) {
guint16 len;
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_nw_auth_type_indicator,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
len = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_nw_auth_type_url_len,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (len)
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_nw_auth_type_url,
tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
}
}
static void
add_manuf(proto_item *item, tvbuff_t *tvb, int offset)
{
const gchar *manuf_name;
manuf_name = tvb_get_manuf_name_if_known(tvb, offset);
if (manuf_name == NULL)
return;
proto_item_append_text(item, " - %s", manuf_name);
}
static void
dissect_roaming_consortium_list(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
int end)
{
proto_item *item;
guint8 len;
while (offset < end) {
len = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree,
hf_ieee80211_ff_anqp_roaming_consortium_oi_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if ((len > (end - offset)) || (len < 3)) {
expert_add_info(pinfo, item, &ei_ieee80211_ff_anqp_roaming_consortium_oi_len);
break;
}
item = proto_tree_add_item(tree,
hf_ieee80211_ff_anqp_roaming_consortium_oi,
tvb, offset, len, ENC_NA);
add_manuf(item, tvb, offset);
offset += len;
}
}
static void
dissect_ip_addr_type_availability_info(proto_tree *tree, tvbuff_t *tvb,
int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_ip_addr_avail_ipv6,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_ip_addr_avail_ipv4,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_nai_realm_list(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, int end)
{
guint16 count, len;
proto_item *item, *r_item;
int f_end, eap_end;
guint8 nai_len, eap_count, eap_len, auth_param_count, auth_param_len;
guint8 auth_param_id;
proto_tree *realm_tree, *eap_tree;
guint8 *realm;
count = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_nai_realm_count,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
while (count > 0) {
len = tvb_get_letohs(tvb, offset);
realm_tree = proto_tree_add_subtree(tree, tvb, offset, 2 + len, ett_nai_realm, &r_item, "NAI Realm Data");
item = proto_tree_add_item(realm_tree, hf_ieee80211_ff_anqp_nai_field_len,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (offset + len > end) {
expert_add_info_format(pinfo, item, &ei_ieee80211_ff_anqp_nai_field_len,
"Invalid NAI Realm List");
break;
}
f_end = offset + len;
proto_tree_add_item(realm_tree, hf_ieee80211_ff_anqp_nai_realm_encoding,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
nai_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(realm_tree, hf_ieee80211_ff_anqp_nai_realm_length,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (offset + nai_len > f_end) {
expert_add_info_format(pinfo, r_item, &ei_ieee80211_ff_anqp_nai_field_len,
"Invalid NAI Realm Data");
break;
}
proto_tree_add_item(realm_tree, hf_ieee80211_ff_anqp_nai_realm,
tvb, offset, nai_len, ENC_ASCII|ENC_NA);
realm = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, nai_len, ENC_ASCII);
if (realm) {
proto_item_append_text(r_item, " (%s)", realm);
}
offset += nai_len;
eap_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(realm_tree, hf_ieee80211_ff_anqp_nai_realm_eap_count,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
while (eap_count > 0) {
eap_len = tvb_get_guint8(tvb, offset);
eap_end = offset + 1 + eap_len;
eap_tree = proto_tree_add_subtree(realm_tree, tvb, offset, 1 + eap_len,
ett_nai_realm_eap, NULL, "EAP Method");
item = proto_tree_add_item(eap_tree,
hf_ieee80211_ff_anqp_nai_realm_eap_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (offset + eap_len > f_end) {
expert_add_info(pinfo, item, &ei_ieee80211_ff_anqp_nai_realm_eap_len);
break;
}
proto_item_append_text(eap_tree, ": %s",
val_to_str_ext(tvb_get_guint8(tvb, offset),
&eap_type_vals_ext, "Unknown (%d)"));
proto_tree_add_item(eap_tree, hf_ieee80211_ff_anqp_nai_realm_eap_method,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
auth_param_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eap_tree,
hf_ieee80211_ff_anqp_nai_realm_auth_param_count,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
while (auth_param_count > 0) {
auth_param_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eap_tree,
hf_ieee80211_ff_anqp_nai_realm_auth_param_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
auth_param_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eap_tree,
hf_ieee80211_ff_anqp_nai_realm_auth_param_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
item = proto_tree_add_item(
eap_tree, hf_ieee80211_ff_anqp_nai_realm_auth_param_value,
tvb, offset, auth_param_len, ENC_NA);
if ((auth_param_id == 3) && (auth_param_len == 1)) {
guint8 inner_method = tvb_get_guint8(tvb, offset);
const char *str;
str = val_to_str_ext(inner_method, &eap_type_vals_ext, "Unknown (%d)");
proto_item_append_text(eap_tree, " / %s", str);
proto_item_append_text(item, " - %s", str);
}
offset += auth_param_len;
auth_param_count--;
}
offset = eap_end;
eap_count--;
}
offset = f_end;
count--;
}
}
static void
dissect_3gpp_cellular_network_info(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 iei, num;
proto_item *item;
proto_tree_add_item(tree, hf_ieee80211_3gpp_gc_gud, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_3gpp_gc_udhl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
iei = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree, hf_ieee80211_3gpp_gc_iei, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if (iei == 0)
proto_item_append_text(item, " (PLMN List)");
else
return;
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_3gpp_gc_plmn_len, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
num = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_3gpp_gc_num_plmns, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
while (num > 0) {
if (tvb_reported_length_remaining(tvb, offset) < 3)
break;
dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, offset, E212_NONE, FALSE);
num--;
offset += 3;
}
}
static void
dissect_domain_name_list(proto_tree *tree, tvbuff_t *tvb, int offset, int end)
{
guint8 len;
while (offset < end) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_domain_name_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_domain_name,
tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
}
}
static void dissect_hs20_anqp_hs_query_list(proto_tree *tree, tvbuff_t *tvb,
int offset, int end)
{
while (offset < end) {
proto_tree_add_item(tree, hf_hs20_anqp_hs_query_list,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
}
}
static void dissect_hs20_anqp_operator_friendly_name(proto_tree *tree,
tvbuff_t *tvb, packet_info *pinfo,
int offset, int end)
{
while (offset + 4 <= end) {
guint8 vlen = tvb_get_guint8(tvb, offset);
proto_item *item = proto_tree_add_item(tree, hf_hs20_anqp_ofn_length,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (vlen > end - offset || vlen < 3) {
expert_add_info(pinfo, item, &ei_hs20_anqp_ofn_length);
break;
}
proto_tree_add_item(tree, hf_hs20_anqp_ofn_language,
tvb, offset, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_hs20_anqp_ofn_name,
tvb, offset + 3, vlen - 3, ENC_UTF_8|ENC_NA);
offset += vlen;
}
}
static void dissect_hs20_anqp_wan_metrics(proto_tree *tree, tvbuff_t *tvb,
int offset, gboolean request)
{
if (request)
return;
proto_tree_add_item(tree, hf_hs20_anqp_wan_metrics_link_status,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_hs20_anqp_wan_metrics_symmetric_link,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_hs20_anqp_wan_metrics_at_capacity,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_hs20_anqp_wan_metrics_reserved,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_hs20_anqp_wan_metrics_downlink_speed,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_hs20_anqp_wan_metrics_uplink_speed,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_hs20_anqp_wan_metrics_downlink_load,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_hs20_anqp_wan_metrics_uplink_load,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_hs20_anqp_wan_metrics_lmd,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_hs20_anqp_connection_capability(proto_tree *tree, tvbuff_t *tvb,
int offset, int end)
{
proto_tree *tuple;
while (offset + 4 <= end) {
guint8 ip_proto, status;
guint16 port_num;
ip_proto = tvb_get_guint8(tvb, offset);
port_num = tvb_get_letohs(tvb, offset + 1);
status = tvb_get_guint8(tvb, offset + 3);
tuple = proto_tree_add_subtree_format(tree, tvb, offset, 4, ett_hs20_cc_proto_port_tuple, NULL,
"ProtoPort Tuple - ip_proto=%u port_num=%u status=%s",
ip_proto, port_num,
val_to_str(status, hs20_cc_status_vals,
"Unknown (%u)"));
proto_tree_add_item(tuple, hf_hs20_anqp_cc_proto_ip_proto,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tuple, hf_hs20_anqp_cc_proto_port_num,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tuple, hf_hs20_anqp_cc_proto_status,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
}
}
static void
dissect_hs20_anqp_nai_home_realm_query(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
int offset, int end)
{
guint8 len;
proto_item *item;
proto_tree_add_item(tree, hf_hs20_anqp_nai_hrq_count,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
while (offset + 2 <= end) {
proto_tree_add_item(tree, hf_hs20_anqp_nai_hrq_encoding_type,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
len = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree, hf_hs20_anqp_nai_hrq_length,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (offset + len > end) {
expert_add_info(pinfo, item, &ei_hs20_anqp_nai_hrq_length);
break;
}
proto_tree_add_item(tree, hf_hs20_anqp_nai_hrq_realm_name,
tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
}
}
static void dissect_hs20_anqp_oper_class_indic(proto_tree *tree, tvbuff_t *tvb,
int offset, int end)
{
while (offset < end) {
proto_tree_add_item(tree, hf_hs20_anqp_oper_class_indic,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
}
}
static void dissect_hs20_anqp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
int end, gboolean request, int idx)
{
guint8 subtype;
subtype = tvb_get_guint8(tvb, offset);
proto_item_append_text(tree, " - HS 2.0 %s",
val_to_str(subtype, hs20_anqp_subtype_vals,
"Unknown (%u)"));
if (idx == 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, " HS 2.0 %s",
val_to_str(subtype, hs20_anqp_subtype_vals,
"Unknown (%u)"));
} else if (idx == 1) {
col_append_str(pinfo->cinfo, COL_INFO, ", ..");
}
proto_tree_add_item(tree, hf_hs20_anqp_subtype, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_hs20_anqp_reserved, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset++;
switch (subtype) {
case HS20_ANQP_HS_QUERY_LIST:
dissect_hs20_anqp_hs_query_list(tree, tvb, offset, end);
break;
case HS20_ANQP_HS_CAPABILITY_LIST:
dissect_hs20_anqp_hs_capability_list(tree, tvb, offset, end);
break;
case HS20_ANQP_OPERATOR_FRIENDLY_NAME:
dissect_hs20_anqp_operator_friendly_name(tree, tvb, pinfo, offset, end);
break;
case HS20_ANQP_WAN_METRICS:
dissect_hs20_anqp_wan_metrics(tree, tvb, offset, request);
break;
case HS20_ANQP_CONNECTION_CAPABILITY:
dissect_hs20_anqp_connection_capability(tree, tvb, offset, end);
break;
case HS20_ANQP_NAI_HOME_REALM_QUERY:
dissect_hs20_anqp_nai_home_realm_query(tree, tvb, pinfo, offset, end);
break;
case HS20_ANQP_OPERATING_CLASS_INDICATION:
dissect_hs20_anqp_oper_class_indic(tree, tvb, offset, end);
break;
default:
if (offset == end)
break;
proto_tree_add_item(tree, hf_hs20_anqp_payload, tvb, offset,
end - offset, ENC_NA);
break;
}
}
static int
dissect_anqp_info(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
gboolean request, int idx)
{
guint16 id, len;
guint32 oui;
proto_item *item;
item = proto_tree_add_item(tree, hf_ieee80211_ff_anqp_info_id,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
id = tvb_get_letohs(tvb, offset);
if (id != ANQP_INFO_ANQP_VENDOR_SPECIFIC_LIST) {
if (idx == 0) {
proto_item_append_text(tree, " - %s",
val_to_str_ext(id, &anqp_info_id_vals_ext, "Unknown (%u)"));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext(id, &anqp_info_id_vals_ext, "Unknown (%u)"));
} else if (idx == 1) {
proto_item_append_text(tree, ", ..");
col_append_str(pinfo->cinfo, COL_INFO, ", ..");
}
}
tree = proto_item_add_subtree(item, ett_gas_anqp);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_info_length,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
len = tvb_get_letohs(tvb, offset);
offset += 2;
if (tvb_reported_length_remaining(tvb, offset) < len) {
expert_add_info(pinfo, tree, &ei_ieee80211_ff_anqp_info_length);
return 4 + len;
}
switch (id)
{
case ANQP_INFO_ANQP_QUERY_LIST:
dissect_anqp_query_list(tree, tvb, pinfo, offset, offset + len);
break;
case ANQP_INFO_ANQP_CAPAB_LIST:
dissect_anqp_capab_list(tree, tvb, pinfo, offset, offset + len);
break;
case ANQP_INFO_VENUE_NAME_INFO:
dissect_venue_name_info(tree, tvb, pinfo, offset, offset + len);
break;
case ANQP_INFO_NETWORK_AUTH_TYPE_INFO:
dissect_network_auth_type(tree, tvb, offset, offset + len);
break;
case ANQP_INFO_ROAMING_CONSORTIUM_LIST:
dissect_roaming_consortium_list(tree, tvb, pinfo, offset, offset + len);
break;
case ANQP_INFO_IP_ADDR_TYPE_AVAILABILITY_INFO:
dissect_ip_addr_type_availability_info(tree, tvb, offset);
break;
case ANQP_INFO_NAI_REALM_LIST:
dissect_nai_realm_list(tree, tvb, pinfo, offset, offset + len);
break;
case ANQP_INFO_3GPP_CELLULAR_NETWORK_INFO:
dissect_3gpp_cellular_network_info(tree, tvb, pinfo, offset);
break;
case ANQP_INFO_DOMAIN_NAME_LIST:
dissect_domain_name_list(tree, tvb, offset, offset + len);
break;
case ANQP_INFO_ANQP_VENDOR_SPECIFIC_LIST:
oui = tvb_get_ntoh24(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_oui, tvb, offset, 3, ENC_NA);
offset += 3;
switch (oui) {
case OUI_WFA:
proto_tree_add_item(tree, hf_ieee80211_anqp_wfa_subtype, tvb, offset, 1,
ENC_NA);
switch (tvb_get_guint8(tvb, offset)) {
case WFA_SUBTYPE_P2P:
dissect_wifi_p2p_anqp(pinfo, tree, tvb, offset + 1, request);
break;
case WFA_SUBTYPE_HS20_ANQP:
dissect_hs20_anqp(tree, tvb, pinfo, offset + 1, offset + len - 3, request,
idx);
break;
}
break;
default:
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_info,
tvb, offset, len, ENC_NA);
break;
}
break;
default:
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_info,
tvb, offset, len, ENC_NA);
break;
}
return 4 + len;
}
static void
dissect_anqp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, gboolean request)
{
int idx = 0;
proto_item_append_text(tree, ": ANQP ");
proto_item_append_text(tree, request ? "Request" : "Response");
if (tvb_reported_length_remaining(tvb, offset) < 4) {
expert_add_info_format(pinfo, tree, &ei_ieee80211_not_enough_room_for_anqp_header,
"Not enough room for ANQP header");
return;
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", ANQP %s",
request ? "Req" : "Resp");
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset += dissect_anqp_info(tree, tvb, pinfo, offset, request, idx);
idx += 1;
}
}
static guint
dissect_gas_initial_request(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
gboolean anqp)
{
guint16 req_len;
int start = offset;
proto_item *item;
proto_tree *query;
req_len = tvb_get_letohs(tvb, offset);
query = proto_tree_add_subtree(tree, tvb, offset, 2 + req_len, ett_gas_query, &item, "Query Request");
if (tvb_reported_length_remaining(tvb, offset) < 2 + req_len) {
expert_add_info(pinfo, item, &ei_ieee80211_ff_query_request_length);
return tvb_reported_length_remaining(tvb, offset);
}
proto_tree_add_item(query, hf_ieee80211_ff_query_request_length,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (anqp)
dissect_anqp(query, tvb, pinfo, offset, TRUE);
else
proto_tree_add_item(query, hf_ieee80211_ff_query_request,
tvb, offset, req_len, ENC_NA);
offset += req_len;
return offset - start;
}
static guint
dissect_gas_initial_response(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
gboolean anqp)
{
guint16 resp_len;
int start = offset;
proto_item *item;
proto_tree *query;
resp_len = tvb_get_letohs(tvb, offset);
query = proto_tree_add_subtree(tree, tvb, offset, 2 + resp_len,
ett_gas_query, &item, "Query Response");
if (tvb_reported_length_remaining(tvb, offset) < 2 + resp_len) {
expert_add_info(pinfo, item, &ei_ieee80211_ff_query_response_length);
return tvb_reported_length_remaining(tvb, offset);
}
proto_tree_add_item(query, hf_ieee80211_ff_query_response_length,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (resp_len) {
if (anqp)
dissect_anqp(query, tvb, pinfo, offset, FALSE);
else
proto_tree_add_item(query, hf_ieee80211_ff_query_response,
tvb, offset, resp_len, ENC_NA);
offset += resp_len;
}
return offset - start;
}
static void
ieee80211_gas_reassembly_init(void)
{
reassembly_table_init(&gas_reassembly_table,
&addresses_reassembly_table_functions);
}
static guint
dissect_gas_comeback_response(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
gboolean anqp, guint8 frag, gboolean more,
guint8 dialog_token)
{
guint16 resp_len;
int start = offset;
proto_item *item;
proto_tree *query;
resp_len = tvb_get_letohs(tvb, offset);
query = proto_tree_add_subtree(tree, tvb, offset, 2 + resp_len,
ett_gas_query, &item, "Query Response");
if (tvb_reported_length_remaining(tvb, offset) < 2 + resp_len) {
expert_add_info(pinfo, item, &ei_ieee80211_ff_query_response_length);
return tvb_reported_length_remaining(tvb, offset);
}
proto_tree_add_item(query, hf_ieee80211_ff_query_response_length,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (resp_len) {
if (anqp && (frag == 0) && !more)
dissect_anqp(query, tvb, pinfo, offset, FALSE);
else {
fragment_head *frag_msg;
gboolean save_fragmented;
tvbuff_t *new_tvb;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(&gas_reassembly_table, tvb, offset,
pinfo, dialog_token, NULL,
frag, resp_len, more);
new_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled GAS Query Response",
frag_msg, &gas_resp_frag_items,
NULL, tree);
if (new_tvb) {
if (anqp)
dissect_anqp(query, new_tvb, pinfo, 0, FALSE);
else
proto_tree_add_item(query, hf_ieee80211_ff_query_response,
new_tvb, 0,
tvb_reported_length_remaining(new_tvb, 0),
ENC_NA);
}
ieee80211_tvb_invalid = TRUE;
pinfo->fragmented = save_fragmented;
}
offset += resp_len;
}
return offset - start;
}
static guint
add_ff_timestamp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
last_timestamp = tvb_get_letoh64(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_ff_timestamp, tvb, offset, 8,
ENC_LITTLE_ENDIAN);
return 8;
}
static guint
add_ff_beacon_interval(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_beacon_interval, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", BI=%d",
tvb_get_letohs(tvb, offset));
return 2;
}
static guint
add_ff_cap_info(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *cap_item;
proto_tree *cap_tree;
cap_item = proto_tree_add_item(tree, hf_ieee80211_ff_capture, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
cap_tree = proto_item_add_subtree(cap_item, ett_cap_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_ess, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_ibss, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
if ((tvb_get_letohs(tvb, offset) & 0x0001) != 0) {
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_ap_poll, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_sta_poll, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_privacy, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_preamble, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_pbcc, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_agility, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_spec_man, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_short_slot_time, tvb, offset,
2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_apsd, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_radio_measurement, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_dsss_ofdm, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_del_blk_ack, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_imm_blk_ack, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_auth_alg(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_auth_alg, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_auth_trans_seq(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_auth_seq, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_current_ap_addr(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_current_ap, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_listen_ival(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_listen_ival, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_reason_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_reason, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_assoc_id(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_assoc_id, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_status_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_status_code, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_category_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_category_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_dialog_token(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_dialog_token, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_followup_dialog_token(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_followup_dialog_token, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_wme_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_wme_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_wme_status_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_wme_status_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_qos_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_qos_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_block_ack_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_ba_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_block_ack_param(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_block_ack_params,
ett_ff_ba_param_tree,
ieee80211_ff_block_ack_params_fields,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_block_ack_timeout(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_block_ack_timeout, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_block_ack_ssc(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_block_ack_ssc,
ett_ff_ba_ssc_tree, ieee80211_ff_block_ack_ssc_fields,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_qos_ts_info(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_tsinfo,
ett_tsinfo_tree, ieee80211_tsinfo_fields,
ENC_LITTLE_ENDIAN);
return 3;
}
static guint
add_ff_mesh_action(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_mesh_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_multihop_action(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_multihop_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_mesh_control(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
int start = offset;
guint8 flags;
proto_tree_add_item(tree, hf_ieee80211_ff_mesh_flags, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
flags = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_ff_mesh_ttl, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_ff_mesh_sequence, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
switch (flags & 0x03) {
case 1:
proto_tree_add_item(tree, hf_ieee80211_ff_mesh_addr4, tvb, offset, 6,
ENC_NA);
offset += 6;
break;
case 2:
proto_tree_add_item(tree, hf_ieee80211_ff_mesh_addr5, tvb, offset, 6,
ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_ieee80211_ff_mesh_addr6, tvb, offset, 6,
ENC_NA);
offset += 6;
break;
case 3:
proto_item_append_text(tree, " Unknown Address Extension Mode");
break;
default:
break;
}
return offset - start;
}
static guint
add_ff_selfprot_action(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_selfprot_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_dls_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_dls_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_dst_mac_addr(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_dst_mac_addr, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_src_mac_addr(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_src_mac_addr, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_req_ap_addr(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_req_ap_addr, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_res_ap_addr(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_res_ap_addr, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_check_beacon(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_check_beacon, tvb, offset, 1,
ENC_NA);
return 1;
}
static guint
add_ff_tod(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_tod, tvb, offset, 4,
ENC_NA);
return 4;
}
static guint
add_ff_toa(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_toa, tvb, offset, 4,
ENC_NA);
return 4;
}
static guint
add_ff_max_tod_err(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_max_tod_err, tvb, offset, 1,
ENC_NA);
return 1;
}
static guint
add_ff_max_toa_err(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_max_toa_err, tvb, offset, 1,
ENC_NA);
return 1;
}
static guint
add_ff_dls_timeout(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_dls_timeout, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_delba_param_set(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_delba_param,
ett_ff_ba_param_tree, ieee80211_ff_delba_param_fields,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_max_reg_pwr(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_max_reg_pwr, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_measurement_pilot_int(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_measurement_pilot_int, tvb, offset,
2, ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_country_str(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_country_str, tvb, offset, 3,
ENC_ASCII|ENC_NA);
return 3;
}
static guint
add_ff_max_tx_pwr(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_max_tx_pwr, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_tx_pwr_used(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_tx_pwr_used, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_transceiver_noise_floor(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_transceiver_noise_floor, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_channel_width(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_channel_width, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_qos_info_ap(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_ieee80211_ff_qos_info_ap,
ett_ff_qos_info, ieee80211_ff_qos_info_ap_fields,
ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
return 1;
}
static guint
add_ff_qos_info_sta(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_ieee80211_ff_qos_info_sta,
ett_ff_qos_info, ieee80211_ff_qos_info_sta_fields,
ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
return 1;
}
static guint
add_ff_sm_pwr_cntrl(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_sm_pwr_save,
ett_ff_sm_pwr_save, ieee80211_ff_sw_pwr_save_fields,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_pco_phase_cntrl(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_pco_phase_cntrl, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_psmp_param_set(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_psmp_param_set,
ett_ff_psmp_param_set,
ieee80211_ff_psmp_param_set_fields,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_mimo_cntrl(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *mimo_item;
proto_tree *mimo_tree;
mimo_item = proto_tree_add_item(tree, hf_ieee80211_ff_mimo_cntrl, tvb,
offset, 6, ENC_NA);
mimo_tree = proto_item_add_subtree(mimo_item, ett_ff_mimo_cntrl);
proto_tree_add_item(mimo_tree, hf_ieee80211_ff_mimo_cntrl_nc_index, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mimo_tree, hf_ieee80211_ff_mimo_cntrl_nr_index, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mimo_tree, hf_ieee80211_ff_mimo_cntrl_channel_width, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mimo_tree, hf_ieee80211_ff_mimo_cntrl_grouping, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mimo_tree, hf_ieee80211_ff_mimo_cntrl_coefficient_size,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mimo_tree, hf_ieee80211_ff_mimo_cntrl_codebook_info, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mimo_tree,
hf_ieee80211_ff_mimo_cntrl_remaining_matrix_segment, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mimo_tree, hf_ieee80211_ff_mimo_cntrl_reserved, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(mimo_tree, hf_ieee80211_ff_mimo_cntrl_sounding_timestamp,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
return 6;
}
static guint
add_ff_ant_selection(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_ant_selection,
ett_ff_ant_sel, ieee80211_ff_ant_selection_fields,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_extended_channel_switch_announcement(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset,
hf_ieee80211_ff_ext_channel_switch_announcement,
ett_ff_chan_switch_announce,
ieee80211_ff_ext_channel_switch_announcement_fields,
ENC_LITTLE_ENDIAN);
return 4;
}
static guint
add_ff_ht_information(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_ht_info,
ett_ff_ht_info, ieee80211_ff_ht_info_fields,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_ht_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_ht_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_dmg_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_dmg_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_dmg_pwr_mgmt(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_dmg_pwr_mgmt, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_psmp_sta_info(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *psmp_item;
proto_tree *psmp_tree;
psmp_item = proto_tree_add_item(tree, hf_ieee80211_ff_psmp_sta_info, tvb,
offset, 8, ENC_LITTLE_ENDIAN);
psmp_tree = proto_item_add_subtree(psmp_item, ett_ff_psmp_sta_info);
proto_tree_add_item(psmp_item, hf_ieee80211_ff_psmp_sta_info_type, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
switch (tvb_get_letohl(tvb, offset) & PSMP_STA_INFO_FLAG_TYPE) {
case PSMP_STA_INFO_BROADCAST:
proto_tree_add_item(psmp_tree,
hf_ieee80211_ff_psmp_sta_info_dtt_start_offset, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psmp_tree, hf_ieee80211_ff_psmp_sta_info_dtt_duration,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_uint64(psmp_tree,
hf_ieee80211_ff_psmp_sta_info_reserved_large,
tvb, offset, 8,
(tvb_get_letoh64(tvb, offset) &
G_GUINT64_CONSTANT(0xFFFFFFFFFFE00000)) >> 21);
break;
case PSMP_STA_INFO_MULTICAST:
proto_tree_add_item(psmp_tree,
hf_ieee80211_ff_psmp_sta_info_dtt_start_offset, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psmp_tree, hf_ieee80211_ff_psmp_sta_info_dtt_duration,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_uint64(psmp_tree,
hf_ieee80211_ff_psmp_sta_info_psmp_multicast_id,
tvb, offset, 6,
(tvb_get_letoh64(tvb, offset) &
G_GUINT64_CONSTANT(0xFFFFFFFFFFE00000)) >> 21);
break;
case PSMP_STA_INFO_INDIVIDUALLY_ADDRESSED:
proto_tree_add_item(psmp_tree,
hf_ieee80211_ff_psmp_sta_info_dtt_start_offset, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psmp_tree, hf_ieee80211_ff_psmp_sta_info_dtt_duration,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(psmp_tree, hf_ieee80211_ff_psmp_sta_info_sta_id, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(psmp_tree,
hf_ieee80211_ff_psmp_sta_info_utt_start_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psmp_tree, hf_ieee80211_ff_psmp_sta_info_utt_duration,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psmp_tree,
hf_ieee80211_ff_psmp_sta_info_reserved_small, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
break;
}
return 8;
}
static guint
add_ff_schedule_info(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *sched_item;
proto_tree *sched_tree;
sched_item = proto_tree_add_item(tree, hf_ieee80211_sched_info, tvb, offset,
2, ENC_LITTLE_ENDIAN);
sched_tree = proto_item_add_subtree(sched_item, ett_sched_tree);
proto_tree_add_item(sched_tree, hf_ieee80211_sched_info_agg, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
if (tvb_get_letohs(tvb, offset) & 0x0001) {
proto_tree_add_item(sched_tree, hf_ieee80211_sched_info_tsid, tvb, offset,
2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sched_tree, hf_ieee80211_sched_info_dir, tvb, offset,
2, ENC_LITTLE_ENDIAN);
}
return 2;
}
static guint
add_ff_pa_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_public_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_ppa_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_protected_public_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_action_spectrum_mgmt(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
switch (tvb_get_guint8(tvb, offset + 1)) {
case SM_ACTION_MEASUREMENT_REQUEST:
case SM_ACTION_MEASUREMENT_REPORT:
case SM_ACTION_TPC_REQUEST:
case SM_ACTION_TPC_REPORT:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_ACTION_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 2, FIELD_DIALOG_TOKEN);
return 3;
case SM_ACTION_CHAN_SWITCH_ANNC:
case SM_ACTION_EXT_CHAN_SWITCH_ANNC:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_ACTION_CODE);
return 2;
default:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_ACTION_CODE);
return 2;
}
}
static guint
add_ff_action_qos(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
switch (tvb_get_guint8(tvb, offset + 1)) {
case QOS_ACTION_ADDTS_REQUEST:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_QOS_ACTION_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 2, FIELD_DIALOG_TOKEN);
return 3;
case QOS_ACTION_ADDTS_RESPONSE:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_QOS_ACTION_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 2, FIELD_DIALOG_TOKEN);
add_fixed_field(tree, tvb, pinfo, offset + 3, FIELD_STATUS_CODE);
return 5;
case QOS_ACTION_DELTS:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_QOS_ACTION_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 2, FIELD_QOS_TS_INFO);
add_fixed_field(tree, tvb, pinfo, offset + 5, FIELD_REASON_CODE);
return 7;
case QOS_ACTION_SCHEDULE:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_QOS_ACTION_CODE);
return 2;
case QOS_ACTION_MAP_CONFIGURE:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_QOS_ACTION_CODE);
return 2;
default:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
return 2;
}
}
static guint
add_ff_action_dls(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
switch (tvb_get_guint8(tvb, offset + 1)) {
case DLS_ACTION_REQUEST:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_DLS_ACTION_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 2, FIELD_DST_MAC_ADDR);
add_fixed_field(tree, tvb, pinfo, offset + 8, FIELD_SRC_MAC_ADDR);
add_fixed_field(tree, tvb, pinfo, offset + 14, FIELD_CAP_INFO);
add_fixed_field(tree, tvb, pinfo, offset + 16, FIELD_DLS_TIMEOUT);
return 18;
case DLS_ACTION_RESPONSE:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_DLS_ACTION_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 2, FIELD_STATUS_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 4, FIELD_DST_MAC_ADDR);
add_fixed_field(tree, tvb, pinfo, offset + 10, FIELD_SRC_MAC_ADDR);
if (!hf_ieee80211_ff_status_code) {
add_fixed_field(tree, tvb, pinfo, offset + 16, FIELD_CAP_INFO);
}
return 16;
case DLS_ACTION_TEARDOWN:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 1, FIELD_DLS_ACTION_CODE);
add_fixed_field(tree, tvb, pinfo, offset + 2, FIELD_DST_MAC_ADDR);
add_fixed_field(tree, tvb, pinfo, offset + 8, FIELD_SRC_MAC_ADDR);
add_fixed_field(tree, tvb, pinfo, offset + 14, FIELD_REASON_CODE);
return 16;
default:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
return 2;
}
}
static guint
add_ff_action_block_ack(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint start = offset;
switch (tvb_get_guint8(tvb, offset + 1)) {
case BA_ADD_BLOCK_ACK_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_ACTION_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_PARAM);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_TIMEOUT);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_SSC);
break;
case BA_ADD_BLOCK_ACK_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_ACTION_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_PARAM);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_TIMEOUT);
break;
case BA_DELETE_BLOCK_ACK:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_ACTION_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DELBA_PARAM_SET);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_REASON_CODE);
break;
}
return offset - start;
}
static guint
add_ff_action_public_fields(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, guint8 code)
{
guint32 oui;
guint8 subtype;
gboolean anqp;
guint8 dialog_token;
guint8 frag;
gboolean more;
guint start = offset;
switch (code) {
case PA_EXT_CHANNEL_SWITCH_ANNOUNCEMENT:
offset += add_ff_extended_channel_switch_announcement(tree, tvb, pinfo, offset);
break;
case PA_VENDOR_SPECIFIC:
oui = tvb_get_ntoh24(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_oui, tvb, offset, 3, ENC_NA);
offset += 3;
switch (oui) {
case OUI_WFA:
subtype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_oui_wfa_subtype, tvb, offset, 1, ENC_NA);
offset += 1;
if (subtype == WFA_SUBTYPE_P2P) {
offset = dissect_wifi_p2p_public_action(pinfo, tree, tvb, offset);
}
break;
default:
break;
}
break;
case PA_GAS_INITIAL_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += dissect_advertisement_protocol(pinfo, tree, tvb, offset,
&anqp);
offset += dissect_gas_initial_request(tree, tvb, pinfo, offset, anqp);
break;
case PA_GAS_INITIAL_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_GAS_COMEBACK_DELAY);
offset += dissect_advertisement_protocol(pinfo, tree, tvb, offset,
&anqp);
offset += dissect_gas_initial_response(tree, tvb, pinfo, offset, anqp);
break;
case PA_GAS_COMEBACK_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
case PA_GAS_COMEBACK_RESPONSE:
dialog_token = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
frag = tvb_get_guint8(tvb, offset) & 0x7f;
more = (tvb_get_guint8(tvb, offset) & 0x80) != 0;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_GAS_FRAGMENT_ID);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_GAS_COMEBACK_DELAY);
offset += dissect_advertisement_protocol(pinfo, tree, tvb, offset,
&anqp);
offset += dissect_gas_comeback_response(tree, tvb, pinfo, offset, anqp, frag,
more, dialog_token);
break;
case PA_TDLS_DISCOVERY_RESPONSE:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TDLS");
col_set_str(pinfo->cinfo, COL_INFO, "TDLS Discovery Response");
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CAP_INFO);
break;
case PA_QAB_REQUEST:
case PA_QAB_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_REQ_AP_ADDR);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RES_AP_ADDR);
break;
}
return offset - start;
}
static guint
add_ff_action_public(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
guint start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_PA_ACTION_CODE);
offset += add_ff_action_public_fields(tree, tvb, pinfo, offset, code);
return offset - start;
}
static guint
add_ff_action_protected_public(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
guint start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_PPA_ACTION_CODE);
offset += add_ff_action_public_fields(tree, tvb, pinfo, offset, code);
return offset - start;
}
static guint
add_ff_action_radio_measurement(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint start = offset;
guint8 code;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_ACTION_CODE);
switch (code) {
case RM_ACTION_RADIO_MEASUREMENT_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_REPETITIONS);
break;
case RM_ACTION_RADIO_MEASUREMENT_REPORT:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_DIALOG_TOKEN);
break;
case RM_ACTION_LINK_MEASUREMENT_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_TX_POWER);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_MAX_TX_POWER);
break;
case RM_ACTION_LINK_MEASUREMENT_REPORT:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_TPC_REPORT);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_RX_ANTENNA_ID);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_TX_ANTENNA_ID);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_RCPI);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_RSNI);
break;
case RM_ACTION_NEIGHBOR_REPORT_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_DIALOG_TOKEN);
break;
case RM_ACTION_NEIGHBOR_REPORT_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RM_DIALOG_TOKEN);
break;
}
return offset - start;
}
static guint
add_ff_action_fast_bss_transition(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint start = offset;
guint8 code;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_FT_ACTION_CODE);
switch (code) {
case FT_ACTION_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STA_ADDRESS);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TARGET_AP_ADDRESS);
break;
case FT_ACTION_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STA_ADDRESS);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TARGET_AP_ADDRESS);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
break;
case FT_ACTION_CONFIRM:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STA_ADDRESS);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TARGET_AP_ADDRESS);
break;
case FT_ACTION_ACK:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STA_ADDRESS);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TARGET_AP_ADDRESS);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
break;
}
return offset - start;
}
static guint
add_ff_action_sa_query(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint start = offset;
guint8 code;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_SA_QUERY_ACTION_CODE);
switch (code) {
case SA_QUERY_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TRANSACTION_ID);
break;
case SA_QUERY_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TRANSACTION_ID);
break;
}
return offset - start;
}
static guint
add_ff_action_mesh(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint length;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_MESH_ACTION);
length = 2;
if (tvb_get_guint8(tvb, 1) == MESH_ACTION_TBTT_ADJ_RESPONSE) {
length += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
}
return length;
}
static guint
add_ff_action_multihop(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_MULTIHOP_ACTION);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_MESH_CONTROL);
return offset - start;
}
static guint
add_ff_action_self_protected(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_SELFPROT_ACTION);
switch (tvb_get_guint8(tvb, start + 1)) {
case SELFPROT_ACTION_MESH_PEERING_OPEN:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CAP_INFO);
break;
case SELFPROT_ACTION_MESH_PEERING_CONFIRM:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CAP_INFO);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_ASSOC_ID);
break;
}
return offset - start;
}
static guint
add_ff_vht_action(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_vht_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
wnm_bss_trans_mgmt_req(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
int start = offset;
guint8 mode;
gint left;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
mode = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_ff_request_mode_pref_cand,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_ff_request_mode_abridged,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_ff_request_mode_disassoc_imminent,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_ff_request_mode_bss_term_included,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_ff_request_mode_ess_disassoc_imminent,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_ff_disassoc_timer, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_ff_validity_interval, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset += 1;
if (mode & 0x08) {
proto_tree_add_item(tree, hf_ieee80211_ff_bss_termination_duration,
tvb, offset, 8, ENC_NA);
offset += 8;
}
if (mode & 0x10) {
guint8 url_len;
url_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_ff_url_len, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_ff_url, tvb, offset, url_len,
ENC_ASCII|ENC_NA);
offset += url_len;
}
left = tvb_reported_length_remaining(tvb, offset);
if (left > 0) {
proto_tree_add_item(tree, hf_ieee80211_ff_bss_transition_candidate_list_entries,
tvb, offset, left, ENC_NA);
offset += left;
}
return offset - start;
}
static guint
wnm_sleep_mode_req(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
int start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
return offset - start;
}
static guint
wnm_sleep_mode_resp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
int start = offset;
guint16 key_data_len;
gint left;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
key_data_len = tvb_get_letohs(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_KEY_DATA_LENGTH);
left = tvb_reported_length_remaining(tvb, offset);
if (left < key_data_len) {
expert_add_info(pinfo, tree, &ei_ieee80211_tag_wnm_sleep_mode_no_key_data);
return offset - start;
}
proto_tree_add_item(tree, hf_ieee80211_ff_key_data, tvb, offset,
key_data_len, ENC_NA);
offset += key_data_len;
return offset - start;
}
static guint
wnm_tfs_req(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
int start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
return offset - start;
}
static guint
wnm_tfs_resp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
int start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
return offset - start;
}
static guint
wnm_notification_req(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
int start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_WNM_NOTIFICATION_TYPE);
return offset - start;
}
static guint
add_ff_action_wnm(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
guint start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_WNM_ACTION_CODE);
switch (code) {
case WNM_BSS_TRANS_MGMT_REQ:
offset += wnm_bss_trans_mgmt_req(tree, tvb, pinfo, offset);
break;
case WNM_TFS_REQ:
offset += wnm_tfs_req(tree, tvb, pinfo, offset);
break;
case WNM_TFS_RESP:
offset += wnm_tfs_resp(tree, tvb, pinfo, offset);
break;
case WNM_SLEEP_MODE_REQ:
offset += wnm_sleep_mode_req(tree, tvb, pinfo, offset);
break;
case WNM_SLEEP_MODE_RESP:
offset += wnm_sleep_mode_resp(tree, tvb, pinfo, offset);
break;
case WNM_NOTIFICATION_REQ:
offset += wnm_notification_req(tree, tvb, pinfo, offset);
break;
}
return offset - start;
}
static guint
add_ff_action_unprotected_wnm(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
guint start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_UNPROTECTED_WNM_ACTION_CODE);
switch (code) {
case UNPROTECTED_WNM_TIM:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CHECK_BEACON);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TIMESTAMP);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TOD);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TOA);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_MAX_TOD_ERR);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_MAX_TOA_ERR);
break;
case UNPROTECTED_WNM_TIMING_MEASUREMENT:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_FOLLOWUP_DIALOG_TOKEN);
break;
}
return offset - start;
}
static guint
add_ff_action_tdls(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
guint16 status;
guint start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TDLS_ACTION_CODE);
switch (code) {
case TDLS_SETUP_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CAP_INFO);
break;
case TDLS_SETUP_RESPONSE:
status = tvb_get_letohs(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
if (tvb_reported_length_remaining(tvb, offset) < 2) {
if (status == 0) {
expert_add_info(pinfo, tree, &ei_ieee80211_tdls_setup_response_malformed);
}
break;
}
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CAP_INFO);
break;
case TDLS_SETUP_CONFIRM:
status = tvb_get_letohs(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
if (tvb_reported_length_remaining(tvb, offset) < 1) {
if (status == 0) {
expert_add_info(pinfo, tree, &ei_ieee80211_tdls_setup_confirm_malformed);
}
break;
}
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
case TDLS_TEARDOWN:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_REASON_CODE);
break;
case TDLS_PEER_TRAFFIC_INDICATION:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
case TDLS_CHANNEL_SWITCH_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TARGET_CHANNEL);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_OPERATING_CLASS);
break;
case TDLS_CHANNEL_SWITCH_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
break;
case TDLS_PEER_PSM_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
case TDLS_PEER_PSM_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
break;
case TDLS_PEER_TRAFFIC_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
case TDLS_DISCOVERY_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
}
return offset - start;
}
static guint
add_ff_action_mgmt_notification(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_WME_ACTION_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_WME_STATUS_CODE);
return offset - start;
}
static guint
add_ff_action_vendor_specific(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint start = offset;
guint32 oui;
guint8 subtype;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
oui = tvb_get_ntoh24(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_oui, tvb, offset, 3, ENC_NA);
offset += 3;
switch (oui) {
case OUI_MARVELL:
offset = dissect_vendor_action_marvell(tree, tvb, offset);
break;
case OUI_WFA:
subtype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_oui_wfa_subtype, tvb, offset, 1, ENC_NA);
offset += 1;
if (subtype == WFA_SUBTYPE_P2P) {
offset = dissect_wifi_p2p_action(tree, tvb, offset);
}
break;
default:
break;
}
return offset - start;
}
static guint
add_ff_action_ht(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint start = offset;
guint8 n_sta, i;
mimo_control_t mimo_cntrl;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_HT_ACTION_CODE);
switch (tvb_get_guint8(tvb, offset - 1)) {
case HT_ACTION_NOTIFY_CHAN_WIDTH:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CHANNEL_WIDTH);
break;
case HT_ACTION_SM_PWR_SAVE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_SM_PWR_CNTRL);
break;
case HT_ACTION_PSMP_ACTION:
n_sta = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_PSMP_PARAM_SET);
for (i = 0; i < (n_sta & 0x0F); i++) {
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_PSMP_STA_INFO);
}
break;
case HT_ACTION_SET_PCO_PHASE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_PCO_PHASE_CNTRL);
break;
case HT_ACTION_MIMO_CSI:
mimo_cntrl = get_mimo_control(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_MIMO_CNTRL);
offset += add_mimo_csi_matrices_report(tree, tvb, offset, mimo_cntrl);
break;
case HT_ACTION_MIMO_BEAMFORMING:
mimo_cntrl = get_mimo_control(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_MIMO_CNTRL);
offset += add_mimo_beamforming_feedback_report(tree, tvb, offset,
mimo_cntrl);
break;
case HT_ACTION_MIMO_COMPRESSED_BEAMFORMING:
mimo_cntrl = get_mimo_control(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_MIMO_CNTRL);
offset += add_mimo_compressed_beamforming_feedback_report(tree, tvb,
offset,
mimo_cntrl);
break;
case HT_ACTION_ANT_SEL_FEEDBACK:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_ANT_SELECTION);
break;
case HT_ACTION_HT_INFO_EXCHANGE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_HT_INFORMATION);
break;
}
return offset - start;
}
static guint
add_ff_ft_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_ft_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_sta_address(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_sta_address, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_target_ap_address(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_target_ap_address, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_gas_comeback_delay(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_gas_comeback_delay, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_gas_fragment_id(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_gas_fragment_id, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_ff_more_gas_fragments, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_sa_query_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_sa_query_action_code, tvb, offset,
1, ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_transaction_id(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_transaction_id, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_tdls_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
code = tvb_get_guint8(tvb, offset);
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_ext_const(code, &tdls_action_codes_ext,
"Unknown TDLS Action"));
proto_tree_add_item(tree, hf_ieee80211_ff_tdls_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_target_channel(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_target_channel, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_operating_class(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_operating_class, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_wnm_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
code = tvb_get_guint8(tvb, offset);
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_ext_const(code, &wnm_action_codes_ext, "Unknown WNM Action"));
proto_tree_add_item(tree, hf_ieee80211_ff_wnm_action_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_unprotected_wnm_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
code = tvb_get_guint8(tvb, offset);
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_ext_const(code, &unprotected_wnm_action_codes_ext, "Unknown Unprotected WNM Action"));
proto_tree_add_item(tree, hf_ieee80211_ff_unprotected_wnm_action_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_unprotected_dmg_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_unprotected_dmg_action_code, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_key_data_length(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_key_data_length, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_wnm_notification_type(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_wnm_notification_type,
tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_rm_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_rm_action_code, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_rm_dialog_token(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_rm_dialog_token, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_rm_repetitions(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_rm_repetitions, tvb, offset, 2,
ENC_BIG_ENDIAN);
return 2;
}
static guint
add_ff_rm_tx_power(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_rm_tx_power, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_rm_max_tx_power(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_rm_max_tx_power, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_rm_tpc_report(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree *tpc_tree;
proto_item *tpc_item;
tpc_item = proto_tree_add_item(tree, hf_ieee80211_ff_tpc, tvb, offset, 4, ENC_NA);
tpc_tree = proto_item_add_subtree(tpc_item, ett_tpc);
proto_tree_add_item(tpc_tree, hf_ieee80211_ff_tpc_element_id, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tpc_tree, hf_ieee80211_ff_tpc_length, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tpc_tree, hf_ieee80211_ff_tpc_tx_power, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tpc_tree, hf_ieee80211_ff_tpc_link_margin, tvb, offset + 3, 1, ENC_NA);
return 4;
}
static guint
add_ff_rm_rx_antenna_id(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_rm_rx_antenna_id, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_rm_tx_antenna_id(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_rm_tx_antenna_id, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_rm_rcpi(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_rm_rcpi, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_rm_rsni(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_rm_rsni, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_beacon_interval_ctrl(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *bic_item = proto_tree_add_item(tree, hf_ieee80211_ff_bic, tvb, offset, 6, ENC_LITTLE_ENDIAN);
proto_tree *bic_tree = proto_item_add_subtree(bic_item, ett_bic_tree);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_cc_present, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_discovery_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_next_beacon, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_ati_present, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_abft_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_fss, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_is_resp, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_next_abft, tvb, offset+1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_frag_txss, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_txss_span, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_NBI_abft, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_abft_count, tvb, offset+3, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_nabft, tvb, offset+4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bic_tree, hf_ieee80211_ff_bic_pcp, tvb, offset+5, 1, ENC_LITTLE_ENDIAN);
return 6;
}
static guint
add_ff_beamforming_ctrl(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
gboolean isGrant = *((gboolean*)(p_get_proto_data(wmem_file_scope(), pinfo, proto_wlan, IS_CTRL_GRANT_OR_GRANT_ACK_KEY)));
proto_item *bf_item = proto_tree_add_item(tree, hf_ieee80211_ff_bf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree *bf_tree = proto_item_add_subtree(bf_item, ett_bf_tree);
guint16 bf_field = tvb_get_letohs(tvb, offset);
gboolean isInit = (bf_field & 0x2) >> 1;
gboolean isResp = (bf_field & 0x4) >> 2;
proto_tree_add_item(bf_tree, hf_ieee80211_ff_bf_train, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bf_tree, hf_ieee80211_ff_bf_is_init, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bf_tree, hf_ieee80211_ff_bf_is_resp, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if((isInit==TRUE) && (isResp==TRUE) && isGrant) {
proto_tree_add_item(bf_tree, hf_ieee80211_ff_bf_num_sectors, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bf_tree, hf_ieee80211_ff_bf_num_rx_dmg_ants, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(bf_tree, hf_ieee80211_ff_bf_rxss_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bf_tree, hf_ieee80211_ff_bf_rxss_rate, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
return 2;
}
static guint
add_ff_dynamic_allocation(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *dynamic_alloc_item = proto_tree_add_item(tree, hf_ieee80211_ff_dynamic_allocation, tvb, offset, 5, ENC_LITTLE_ENDIAN);
proto_tree *dynamic_alloc_tree = proto_item_add_subtree(dynamic_alloc_item, ett_dynamic_alloc_tree);
proto_tree_add_item(dynamic_alloc_tree, hf_ieee80211_ff_TID, tvb, offset, 1, ENC_NA);
proto_tree_add_item(dynamic_alloc_tree, hf_ieee80211_ff_alloc_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(dynamic_alloc_tree, hf_ieee80211_ff_src_aid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(dynamic_alloc_tree, hf_ieee80211_ff_dest_aid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(dynamic_alloc_tree, hf_ieee80211_ff_alloc_duration, tvb, offset, 1, ENC_NA);
return 5;
}
static guint
add_ff_beamformed_link(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *blm_item = proto_tree_add_item(tree, hf_ieee80211_ff_blm, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree *blm_tree = proto_item_add_subtree(blm_item, ett_blm_tree);
proto_tree_add_item(blm_tree, hf_ieee80211_ff_blm_unit_index, tvb, offset, 1, ENC_NA);
proto_tree_add_item(blm_tree, hf_ieee80211_ff_blm_maint_value, tvb, offset, 1, ENC_NA);
proto_tree_add_item(blm_tree, hf_ieee80211_ff_blm_is_master, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_BRP_request(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *brp_req_item = proto_tree_add_item(tree, hf_ieee80211_ff_brp, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree *brp_req_tree = proto_item_add_subtree(brp_req_item, ett_brp_tree);
proto_tree_add_item(brp_req_tree, hf_ieee80211_ff_brp_L_RX, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(brp_req_tree, hf_ieee80211_ff_brp_TX_TRN_REQ, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(brp_req_tree, hf_ieee80211_ff_brp_MID_REQ, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(brp_req_tree, hf_ieee80211_ff_brp_BC_REQ, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(brp_req_tree, hf_ieee80211_ff_brp_MID_GRANT, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(brp_req_tree, hf_ieee80211_ff_brp_BC_GRANT, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(brp_req_tree, hf_ieee80211_ff_brp_chan_FBCK_CAP, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(brp_req_tree, hf_ieee80211_ff_brp_tx_sector, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(brp_req_tree, hf_ieee80211_ff_brp_other_aid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(brp_req_tree, hf_ieee80211_ff_brp_tx_antenna, tvb, offset, 4, ENC_LITTLE_ENDIAN);
return 4;
}
static guint
add_ff_sector_sweep_feedback(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *sswf_item = proto_tree_add_item(tree, hf_ieee80211_ff_sswf, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree *sswf_tree = proto_item_add_subtree(sswf_item, ett_sswf_tree);
proto_tree_add_item(sswf_tree, hf_ieee80211_ff_sswf_total_sectors, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sswf_tree, hf_ieee80211_ff_sswf_num_rx_dmg_ants, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sswf_tree, hf_ieee80211_ff_sswf_poll_required, tvb, offset, 3, ENC_LITTLE_ENDIAN);
return 3;
}
static guint
add_ff_sector_sweep(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *ssw_item = proto_tree_add_item(tree, hf_ieee80211_ff_ssw, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree *ssw_tree = proto_item_add_subtree(ssw_item, ett_ssw_tree);
proto_tree_add_item(ssw_tree, hf_ieee80211_ff_ssw_direction, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ssw_tree, hf_ieee80211_ff_ssw_cdown, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ssw_tree, hf_ieee80211_ff_ssw_sector_id, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ssw_tree, hf_ieee80211_ff_ssw_dmg_ant_id, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ssw_tree, hf_ieee80211_ff_ssw_rxss_len, tvb, offset, 3, ENC_LITTLE_ENDIAN);
return 3;
}
static guint
add_ff_dmg_params(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *dmg_params_item = proto_tree_add_item(tree, hf_ieee80211_ff_dmg_params, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree *dmg_params_tree = proto_item_add_subtree(dmg_params_item, ett_dmg_params_tree);
proto_tree_add_item(dmg_params_tree, hf_ieee80211_ff_dmg_params_bss, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dmg_params_tree, hf_ieee80211_ff_dmg_params_cbap_only, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dmg_params_tree, hf_ieee80211_ff_dmg_params_cbap_src, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dmg_params_tree, hf_ieee80211_ff_dmg_params_privacy, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dmg_params_tree, hf_ieee80211_ff_dmg_params_policy, tvb, offset, 1, ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_cc_field(proto_tree *tree, tvbuff_t *tvb, int offset, gboolean dis)
{
proto_item *cc_item = proto_tree_add_item(tree, hf_ieee80211_ff_cc, tvb, offset, 8, ENC_LITTLE_ENDIAN);
proto_tree *cc_tree = proto_item_add_subtree(cc_item, ett_cc_tree);
guint64 cc_field;
if(dis) {
proto_tree_add_item(cc_tree, hf_ieee80211_ff_cc_abft_resp_addr, tvb, offset, 6, ENC_NA);
} else {
cc_field = tvb_get_letoh64(tvb, offset);
proto_tree_add_uint(cc_tree, hf_ieee80211_ff_cc_sp_duration, tvb, offset, 1, (guint32)(cc_field & 0xff));
proto_tree_add_uint64(cc_tree, hf_ieee80211_ff_cc_cluster_id, tvb, offset+1, 6, (guint64)((cc_field & G_GUINT64_CONSTANT(0x00ffffffffffff00)) >> 8));
proto_tree_add_uint(cc_tree, hf_ieee80211_ff_cc_role, tvb, offset+7, 1, (guint32)((cc_field & G_GUINT64_CONSTANT(0x0300000000000000)) >> 56));
proto_tree_add_uint(cc_tree, hf_ieee80211_ff_cc_max_mem, tvb, offset+7, 1, (guint32)((cc_field & G_GUINT64_CONSTANT(0x7c00000000000000)) >> 58));
}
return 8;
}
static guint
add_ff_band_id(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_band_id, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_subject_address(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_subject_address, tvb, offset, 6, ENC_NA);
return 6;
}
static guint
add_ff_handover_reason(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_handover_reason, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_handover_remaining_bi(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_handover_remaining_bi, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_handover_result(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_handover_result, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_handover_reject_reason(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_handover_reject_reason, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_destination_reds_aid(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_destination_reds_aid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_destination_aid(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_destination_aid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_realy_aid(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_realy_aid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_source_aid(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_source_aid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_timing_offset(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_timing_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_sampling_frequency_offset(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_sampling_frequency_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_relay_operation_type(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_relay_operation_type, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_fst_action_code(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_fst_action_code, tvb, offset, 1, ENC_NA);
return 1;
}
static guint
add_ff_llt(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_llt, tvb, offset, 4, ENC_LITTLE_ENDIAN);
return 4;
}
static guint
add_ff_fsts_id(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_fsts_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
return 4;
}
static guint
add_ff_oct_mmpdu(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
guint start = offset;
guint len = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_ff_mmpdu_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_ff_mmpdu_ctrl, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_ff_oct_mmpdu, tvb, offset, len, ENC_NA);
offset += len;
return offset - start;
}
static void
add_tag_relay_capabilities(packet_info *pinfo, proto_item *item, gint32 tag_len, proto_tree *tree, tvbuff_t *tvb, gint32 *offset) {
if (tag_len < 2) {
expert_add_info_format(pinfo, item, &ei_ieee80211_tag_length, "Tag length must be 2");
return;
}
*offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_relay_support, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_relay_use, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_relay_permission, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_AC_power, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_relay_prefer, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_duplex, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_cooperation, tvb, *offset, 1, ENC_NA);
*offset += 2;
return;
}
static guint
add_ff_relay_capable_sta_info(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
proto_item *rcsi_item = proto_tree_add_item(tree, hf_ieee80211_ff_rcsi, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree *rcsi_tree = proto_item_add_subtree(rcsi_item, ett_rcsi_tree);
proto_tree_add_item(rcsi_tree, hf_ieee80211_ff_rcsi_aid, tvb, offset, 1, ENC_NA);
offset += 1;
add_tag_relay_capabilities(pinfo, rcsi_item, 2, rcsi_tree, tvb, &offset);
return 3;
}
static void
dissect_ieee80211_extension(guint16 fcf, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *ext_tree;
proto_tree *fixed_tree;
proto_tree *tagged_tree;
int offset = 0;
int tagged_parameter_tree_len;
ti = proto_tree_add_item (tree, proto_wlan_ext, tvb, offset, -1, ENC_NA);
ext_tree = proto_item_add_subtree (ti, ett_80211_ext);
switch (COMPOSE_FRAME_TYPE(fcf))
{
case EXTENSION_DMG_BEACON:
{
gboolean cc, dis;
guint16 bic_field;
fixed_tree = get_fixed_parameter_tree (ext_tree, tvb, offset, 20);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_TIMESTAMP);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_SECTOR_SWEEP);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_BEACON_INTERVAL);
bic_field = tvb_get_letohs(tvb, offset);
cc = (bic_field & 0x1);
dis = (bic_field & 0x2) >> 1;
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_BEACON_INTERVAL_CTRL);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_DMG_PARAMETERS);
if(cc) {
offset += add_ff_cc_field(fixed_tree,tvb, offset, dis);
}
tagged_parameter_tree_len = tvb_reported_length_remaining(tvb, offset);
if (tagged_parameter_tree_len) {
tagged_tree = get_tagged_parameter_tree (ext_tree, tvb, offset, tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters(tvb, offset, pinfo, tagged_tree, tagged_parameter_tree_len, EXTENSION_DMG_BEACON);
}
break;
}
}
}
static guint
add_ff_action_unprotected_dmg(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
guint start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_UNPROTECTED_DMG_ACTION_CODE);
switch (code) {
case UNPROTECTED_DMG_ANNOUNCE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TIMESTAMP);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_BEACON_INTERVAL);
break;
case UNPROTECTED_DMG_BRP:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_BRP_REQ);
break;
}
return offset - start;
}
static inline int vht_compressed_skip_scidx(guint8 nchan_width, guint8 ng, int scidx)
{
switch(nchan_width) {
case 0:
if (ng == 0)
switch (scidx) {
case -21: case -7: case 7: case 21:
case 0:
scidx++;
default:
break;
}
break;
case 1:
if (ng == 0)
switch (scidx) {
case -53: case -25: case -11: case 11: case 25: case 53:
scidx++;
break;
case -1: case 0: case 1:
scidx = 2;
default:
break;
}
break;
case 2:
if (ng == 0)
switch (scidx) {
case -103: case -75: case -39: case -11: case 11: case 39: case 75: case 103:
scidx++;
break;
case -1:
scidx = 2;
default:
break;
}
break;
case 3:
switch (ng) {
case 0:
if (scidx == -5) {
scidx = 6;
break;
}
switch (scidx) {
case -231: case -203: case -167: case -139: case -117: case -89: case -53: case -25:
case 25: case 53: case 89: case 117: case 139: case 167: case 203: case 231:
scidx++;
break;
case -129:
scidx = -126;
break;
case 127:
scidx = 130;
break;
default:
break;
}
break;
case 1:
switch (scidx) {
case -128: case -4: case -2: case 0: case 2: case 4: case 128:
scidx++;
default:
break;
}
break;
case 2:
if (scidx == -2 || scidx == 2)
scidx++;
break;
}
break;
default:
break;
}
return scidx;
}
static guint
add_ff_vht_compressed_beamforming_report(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset)
{
guint32 vht_mimo;
guint8 nc;
guint8 nr;
guint8 chan_width;
guint8 grouping;
gboolean codebook_info;
gboolean feedback_type;
proto_item *vht_beam_item;
proto_tree *vht_beam_tree, *subtree;
int i, matrix_size, len, pos, ns, scidx = 0;
guint8 phi, psi, carry;
static const guint8 na_arr[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
{ 2, 2, 0, 0, 0, 0, 0, 0 },
{ 4, 6, 6, 0, 0, 0, 0, 0 },
{ 6, 10, 12, 12, 0, 0, 0, 0 },
{ 8, 14, 18, 20, 20, 0, 0, 0 },
{ 10, 18, 24, 28, 30, 30, 0, 0 },
{ 12, 22, 30, 36, 40, 42, 42, 0 },
{ 14, 26, 36, 44, 50, 54, 56, 56 }
};
static const int ns_arr[4][3] = { { 52, 30, 16 },
{ 108, 58, 30 },
{ 234, 122, 62 },
{ 468, 244, 124 }
};
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_vht_mimo_cntrl,
ett_ff_vhtmimo_cntrl, hf_ieee80211_ff_vht_mimo_cntrl_fields, ENC_LITTLE_ENDIAN);
offset += 3;
vht_mimo = tvb_get_letoh24(tvb, offset);
nc = (vht_mimo & 0x7) + 1;
nr = ((vht_mimo & 0x38) >> 3) + 1;
chan_width = (vht_mimo & 0xC0) >> 6;
grouping = ((vht_mimo & 0x300) >> 8);
codebook_info = (vht_mimo & 0x400) >> 10;
feedback_type = (vht_mimo & 0x800) >> 11;
vht_beam_item = proto_tree_add_item(tree, hf_ieee80211_vht_compressed_beamforming_report, tvb,
offset, -1, ENC_NA);
vht_beam_tree = proto_item_add_subtree(vht_beam_item, ett_ff_vhtmimo_beamforming_report);
subtree = proto_tree_add_subtree(vht_beam_tree, tvb, offset, nc,
ett_ff_vhtmimo_beamforming_report_snr, NULL, "Average Signal to Noise Ratio");
for (i = 1; i <= nc; i++)
{
guint8 snr;
snr = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(subtree, hf_ieee80211_vht_compressed_beamforming_report_snr, tvb, offset, 1,
snr, "Stream %d - Signal to Noise Ratio: 0x%02X", i, snr);
offset += 1;
}
subtree = proto_tree_add_subtree(vht_beam_tree, tvb, offset, -1,
ett_ff_vhtmimo_beamforming_report_feedback_matrices, NULL, "Beamforming Feedback Matrics");
if (feedback_type) {
if (codebook_info) {
psi = 7; phi = 9;
} else {
psi = 5; phi = 7;
}
} else {
if (codebook_info) {
psi = 4; phi = 6;
} else {
psi = 2; phi = 4;
}
}
ns = ns_arr[chan_width][grouping];
switch(chan_width) {
case 0:
scidx = -28;
break;
case 1:
scidx = -58;
break;
case 2:
scidx = -122;
break;
case 3:
scidx = -250;
break;
}
matrix_size = na_arr[nr - 1][nc -1] * (psi + phi)/2;
pos = 0;
for (i = 0; i < ns; i++) {
if (pos % 8)
carry = 1;
else
carry = 0;
len = roundup2((pos + matrix_size), 8)/8 - roundup2(pos, 8)/8;
scidx = vht_compressed_skip_scidx(chan_width, grouping, scidx);
proto_tree_add_none_format(subtree, hf_ieee80211_vht_compressed_beamforming_feedback_matrix, tvb,
offset - carry, len + carry, "Compressed Beamforming Feedback Matrix for subcarrier %d", scidx++);
offset += len;
pos += matrix_size;
}
return offset;
}
static guint
add_ff_action_vht(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint start = offset;
guint8 vht_action;
proto_item *ti;
proto_tree *ti_tree;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
vht_action = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_VHT_ACTION);
switch(vht_action){
case VHT_ACT_VHT_COMPRESSED_BEAMFORMING:{
offset = add_ff_vht_compressed_beamforming_report(tree, tvb, pinfo, offset);
offset += tvb_reported_length_remaining(tvb, offset);
}
break;
case VHT_ACT_GROUP_ID_MANAGEMENT:{
ti = proto_tree_add_item(tree, hf_ieee80211_vht_group_id_management, tvb,
offset, -1, ENC_NA);
ti_tree = proto_item_add_subtree(ti, ett_vht_grpidmgmt);
proto_tree_add_item(ti_tree, hf_ieee80211_vht_membership_status_array, tvb,
offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(ti_tree, hf_ieee80211_vht_user_position_array, tvb,
offset, 16, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
}
break;
case VHT_ACT_OPERATION_MODE_NOTIFICATION:{
ti = proto_tree_add_item(tree, hf_ieee80211_vht_operation_mode_notification, tvb,
offset, -1, ENC_NA);
expert_add_info(pinfo, ti, &ei_ieee80211_vht_action);
offset += tvb_reported_length_remaining(tvb, offset);
}
break;
default:
break;
}
return offset - start;
}
static guint
add_ff_action_fst(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
guint start = offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_FST_ACTION_CODE);
switch (code) {
case FST_SETUP_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_LLT);
break;
case FST_SETUP_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
break;
case FST_TEAR_DOWN:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_FSTS_ID);
break;
case FST_ACK_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_FSTS_ID);
break;
case FST_ACK_RESPONSE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_FSTS_ID);
break;
case FST_ON_CHANNEL_TUNNEL_REQUEST:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_OCT_MMPDU);
break;
}
return offset - start;
}
static guint
add_ff_action_dmg(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
guint8 code;
guint start = offset;
int left_offset;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DMG_ACTION_CODE);
switch (code) {
case DMG_ACTION_PWR_SAVE_CONFIG_REQ:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DMG_PWR_MGMT);
break;
case DMG_ACTION_PWR_SAVE_CONFIG_RES:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
break;
case DMG_ACTION_INFO_REQ:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_SUBJECT_ADDRESS);
break;
case DMG_ACTION_INFO_RES:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_SUBJECT_ADDRESS);
break;
case DMG_ACTION_HANDOVER_REQ:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_HANDOVER_REASON);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_HANDOVER_REMAINING_BI);
break;
case DMG_ACTION_HANDOVER_RES:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_HANDOVER_RESULT);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_HANDOVER_REJECT_REASON);
break;
case DMG_ACTION_DTP_REQ:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
case DMG_ACTION_DTP_RES:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
case DMG_ACTION_RELAY_SEARCH_REQ:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DESTINATION_REDS_AID);
break;
case DMG_ACTION_RELAY_SEARCH_RES:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
break;
case DMG_ACTION_MUL_RELAY_CHANNEL_MEASURE_REQ:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
case DMG_ACTION_MUL_RELAY_CHANNEL_MEASURE_RES:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
left_offset =
tvb_reported_length_remaining(tvb, offset);
while(left_offset > 0) {
proto_tree_add_item(tree, hf_ieee80211_ff_peer_sta_aid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_ff_snr, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_ff_internal_angle, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_ff_recommend, tvb, offset+2, 1, ENC_NA);
offset += 4;
left_offset -= 4;
}
break;
case DMG_ACTION_RLS_REQ:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DESTINATION_AID);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_REALY_AID);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_SOURCE_AID);
break;
case DMG_ACTION_RLS_RES:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
case DMG_ACTION_RLS_ANNOUNCE:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DESTINATION_AID);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_REALY_AID);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_SOURCE_AID);
break;
case DMG_ACTION_RLS_TEARDOWN:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DESTINATION_AID);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_REALY_AID);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_SOURCE_AID);
break;
case DMG_ACTION_RELAY_ACK_REQ:
case DMG_ACTION_RELAY_ACK_RES:
break;
case DMG_ACTION_TPA_REQ:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_TIMING_OFFSET);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_SAMPLING_FREQUENCY_OFFSET);
break;
case DMG_ACTION_TPA_RES:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
break;
case DMG_ACTION_TPA_REP:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
break;
case DMG_ACTION_ROC_REQ:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_RELAY_OPERATION_TYPE);
break;
case DMG_ACTION_ROC_RES:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_STATUS_CODE);
break;
}
return offset - start;
}
static guint
add_ff_action(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
switch (tvb_get_guint8(tvb, offset) & 0x7f) {
case CAT_SPECTRUM_MGMT:
return add_ff_action_spectrum_mgmt(tree, tvb, pinfo, offset);
case CAT_QOS:
return add_ff_action_qos(tree, tvb, pinfo, offset);
case CAT_DLS:
return add_ff_action_dls(tree, tvb, pinfo, offset);
case CAT_BLOCK_ACK:
return add_ff_action_block_ack(tree, tvb, pinfo, offset);
case CAT_PUBLIC:
return add_ff_action_public(tree, tvb, pinfo, offset);
case CAT_RADIO_MEASUREMENT:
return add_ff_action_radio_measurement(tree, tvb, pinfo, offset);
case CAT_FAST_BSS_TRANSITION:
return add_ff_action_fast_bss_transition(tree, tvb, pinfo, offset);
case CAT_HT:
return add_ff_action_ht(tree, tvb, pinfo, offset);
case CAT_SA_QUERY:
return add_ff_action_sa_query(tree, tvb, pinfo, offset);
case CAT_PUBLIC_PROTECTED:
return add_ff_action_protected_public(tree, tvb, pinfo, offset);
case CAT_WNM:
return add_ff_action_wnm(tree, tvb, pinfo, offset);
case CAT_UNPROTECTED_WNM:
return add_ff_action_unprotected_wnm(tree, tvb, pinfo, offset);
case CAT_TDLS:
return add_ff_action_tdls(tree, tvb, pinfo, offset);
case CAT_MESH:
return add_ff_action_mesh(tree, tvb, pinfo, offset);
case CAT_MULTIHOP:
return add_ff_action_multihop(tree, tvb, pinfo, offset);
case CAT_SELF_PROTECTED:
return add_ff_action_self_protected(tree, tvb, pinfo, offset);
case CAT_DMG:
return add_ff_action_dmg(tree, tvb, pinfo, offset);
case CAT_MGMT_NOTIFICATION:
return add_ff_action_mgmt_notification(tree, tvb, pinfo, offset);
case CAT_FAST_SESSION_TRANSFER:
return add_ff_action_fst(tree, tvb, pinfo, offset);
case CAT_UNPROTECTED_DMG:
return add_ff_action_unprotected_dmg(tree, tvb, pinfo, offset);
case CAT_VHT:
return add_ff_action_vht(tree, tvb, pinfo, offset);
case CAT_VENDOR_SPECIFIC:
return add_ff_action_vendor_specific(tree, tvb, pinfo, offset);
default:
add_fixed_field(tree, tvb, pinfo, offset, FIELD_CATEGORY_CODE);
return 1;
}
}
static guint
add_fixed_field(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
enum fixed_field lfcode)
{
int i;
for (i = 0; ff_dissectors[i].dissector; i++) {
if (ff_dissectors[i].lfcode == lfcode) {
return ff_dissectors[i].dissector(tree, tvb, pinfo, offset);
}
}
return 0;
}
static void
oui_base_custom(gchar *result, guint32 oui)
{
guint8 p_oui[3];
const gchar *manuf_name;
p_oui[0] = oui >> 16 & 0xFF;
p_oui[1] = oui >> 8 & 0xFF;
p_oui[2] = oui & 0xFF;
manuf_name = get_manuf_name_if_known(p_oui);
if (manuf_name == NULL) {
g_snprintf(result, ITEM_LABEL_LENGTH, "%.2x-%.2x-%.2x", p_oui[0], p_oui[1], p_oui[2]);
}
else {
g_snprintf(result, ITEM_LABEL_LENGTH, "%.2x-%.2x-%.2x (%s)", p_oui[0], p_oui[1], p_oui[2], manuf_name);
}
}
static void
rsn_gcs_base_custom(gchar *result, guint32 gcs)
{
gchar oui_result[SHORT_STR];
gchar *tmp_str;
oui_result[0] = '\0';
oui_base_custom(oui_result, gcs >> 8);
tmp_str = val_to_str_wmem(NULL, gcs & 0xFF, ieee80211_rsn_cipher_vals, "Unknown %d");
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, tmp_str);
wmem_free(NULL, tmp_str);
}
static void
rsn_pcs_base_custom(gchar *result, guint32 pcs)
{
gchar oui_result[SHORT_STR];
gchar *tmp_str;
oui_result[0] = '\0';
oui_base_custom(oui_result, pcs >> 8);
tmp_str = val_to_str_wmem(NULL, pcs & 0xFF, ieee80211_rsn_cipher_vals, "Unknown %d");
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, tmp_str);
wmem_free(NULL, tmp_str);
}
static void
rsn_akms_base_custom(gchar *result, guint32 akms)
{
gchar oui_result[SHORT_STR];
gchar *tmp_str;
oui_result[0] = '\0';
oui_base_custom(oui_result, akms >> 8);
tmp_str = val_to_str_wmem(NULL, akms & 0xFF, ieee80211_rsn_keymgmt_vals, "Unknown %d");
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, tmp_str);
wmem_free(NULL, tmp_str);
}
static gchar *
rsn_pcs_return(guint32 pcs)
{
gchar *result;
result = (gchar *)wmem_alloc(wmem_packet_scope(), SHORT_STR);
result[0] = '\0';
rsn_pcs_base_custom(result, pcs);
return result;
}
static gchar *
rsn_akms_return(guint32 akms)
{
gchar *result;
result = (gchar *)wmem_alloc(wmem_packet_scope(), SHORT_STR);
result[0] = '\0';
rsn_akms_base_custom(result, akms);
return result;
}
static void
rsn_gmcs_base_custom(gchar *result, guint32 gmcs)
{
gchar oui_result[SHORT_STR];
gchar *tmp_str;
oui_result[0] = '\0';
oui_base_custom(oui_result, gmcs >> 8);
tmp_str = val_to_str_wmem(NULL, gmcs & 0xFF, ieee80211_rsn_cipher_vals, "Unknown %d");
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, tmp_str);
wmem_free(NULL, tmp_str);
}
static void
rsni_base_custom(gchar *result, guint32 rsni)
{
double temp_double;
temp_double = (double)rsni;
g_snprintf(result, ITEM_LABEL_LENGTH, "%f dB", (temp_double / 2));
}
static void
vht_tpe_custom(gchar *result, guint8 txpwr)
{
gint8 txpwr_db;
txpwr_db = (gint8)(txpwr);
g_snprintf(result, ITEM_LABEL_LENGTH, "%3.1f dBm", (txpwr_db/2.0));
}
static void
channel_number_custom(gchar *result, guint8 channel_number)
{
switch(channel_number){
case 0:
g_snprintf(result, ITEM_LABEL_LENGTH, "%u (iterative measurements on all supported channels in the specified Operating Class)", channel_number);
break;
case 255:
g_snprintf(result, ITEM_LABEL_LENGTH, "%u (iterative measurements on all supported channels listed in the AP Channel Report)", channel_number);
break;
default :
g_snprintf(result, ITEM_LABEL_LENGTH, "%u (iterative measurements on that Channel Number)", channel_number);
break;
}
}
static void
wpa_mcs_base_custom(gchar *result, guint32 mcs)
{
gchar oui_result[SHORT_STR];
gchar *tmp_str;
oui_result[0] = '\0';
oui_base_custom(oui_result, mcs >> 8);
tmp_str = val_to_str_wmem(NULL, mcs & 0xFF, ieee80211_wfa_ie_wpa_cipher_vals, "Unknown %d");
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, tmp_str);
wmem_free(NULL, tmp_str);
}
static void
wpa_ucs_base_custom(gchar *result, guint32 ucs)
{
gchar oui_result[SHORT_STR];
gchar *tmp_str;
oui_result[0] = '\0';
oui_base_custom(oui_result, ucs >> 8);
tmp_str = val_to_str_wmem(NULL, ucs & 0xFF, ieee80211_wfa_ie_wpa_cipher_vals, "Unknown %d");
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, tmp_str);
wmem_free(NULL, tmp_str);
}
static void
wpa_akms_base_custom(gchar *result, guint32 akms)
{
gchar oui_result[SHORT_STR];
gchar *tmp_str;
oui_result[0] = '\0';
oui_base_custom(oui_result, akms >> 8);
tmp_str = val_to_str_wmem(NULL, akms & 0xFF, ieee80211_wfa_ie_wpa_keymgmt_vals, "Unknown %d");
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, tmp_str);
wmem_free(NULL, tmp_str);
}
static gchar *
wpa_ucs_return(guint32 ucs)
{
gchar *result;
result = (gchar *)wmem_alloc(wmem_packet_scope(), SHORT_STR);
result[0] = '\0';
wpa_ucs_base_custom(result, ucs);
return result;
}
static gchar *
wpa_akms_return(guint32 akms)
{
gchar *result;
result = (gchar *)wmem_alloc(wmem_packet_scope(), SHORT_STR);
result[0] = '\0';
wpa_akms_base_custom(result, akms);
return result;
}
static int
dissect_wme_qos_info(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, int ftype)
{
proto_tree *wme_qos_info_tree;
proto_item *wme_qos_info_item;
wme_qos_info_item = proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_qos_info, tvb, offset, 1, ENC_NA);
wme_qos_info_tree = proto_item_add_subtree(wme_qos_info_item, ett_wme_qos_info);
switch (ftype) {
case MGT_ASSOC_REQ:
case MGT_PROBE_REQ:
case MGT_REASSOC_REQ:
{
proto_tree_add_item(wme_qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_max_sp_length, tvb, offset, 1, ENC_NA);
proto_tree_add_item(wme_qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_be, tvb, offset, 1, ENC_NA);
proto_tree_add_item(wme_qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_bk, tvb, offset, 1, ENC_NA);
proto_tree_add_item(wme_qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_vi, tvb, offset, 1, ENC_NA);
proto_tree_add_item(wme_qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_vo, tvb, offset, 1, ENC_NA);
proto_tree_add_item(wme_qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_reserved, tvb, offset, 1, ENC_NA);
break;
}
case MGT_BEACON:
case MGT_PROBE_RESP:
case MGT_ASSOC_RESP:
case MGT_REASSOC_RESP:
{
proto_tree_add_item(wme_qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_ap_u_apsd, tvb, offset, 1, ENC_NA);
proto_tree_add_item(wme_qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_ap_parameter_set_count, tvb, offset, 1, ENC_NA);
proto_tree_add_item(wme_qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_ap_reserved, tvb, offset, 1, ENC_NA);
break;
}
default:
expert_add_info_format(pinfo, wme_qos_info_item, &ei_ieee80211_wfa_ie_wme_qos_info_bad_ftype, "Could not deduce direction to decode correctly, ftype %u", ftype);
break;
}
offset += 1;
return offset;
}
static int
dissect_vendor_ie_wpawme(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, guint32 tag_len, int ftype)
{
guint8 type;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_type, tvb, offset, 1, ENC_NA);
type = tvb_get_guint8(tvb, offset);
proto_item_append_text(tree, ": %s", val_to_str(type, ieee802111_wfa_ie_type_vals, "Unknown %d"));
offset += 1;
switch (type) {
case 1:
{
proto_item *wpa_mcs_item, *wpa_ucs_item, *wpa_akms_item;
proto_item *wpa_sub_ucs_item, *wpa_sub_akms_item;
proto_tree *wpa_mcs_tree, *wpa_ucs_tree, *wpa_akms_tree;
proto_tree *wpa_sub_ucs_tree, *wpa_sub_akms_tree;
guint16 ucs_count, akms_count;
guint ii;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
wpa_mcs_item = proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_mcs, tvb, offset, 4, ENC_BIG_ENDIAN);
wpa_mcs_tree = proto_item_add_subtree(wpa_mcs_item, ett_wpa_mcs_tree);
proto_tree_add_item(wpa_mcs_tree, hf_ieee80211_wfa_ie_wpa_mcs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if (tvb_get_ntoh24(tvb, offset) == OUI_WPAWME)
{
proto_tree_add_item(wpa_mcs_tree, hf_ieee80211_wfa_ie_wpa_mcs_wfa_type, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(wpa_mcs_tree, hf_ieee80211_wfa_ie_wpa_mcs_type, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
}
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_ucs_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ucs_count = tvb_get_letohs(tvb, offset);
offset += 2;
wpa_ucs_item = proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_ucs_list, tvb, offset, ucs_count * 4, ENC_NA);
wpa_ucs_tree = proto_item_add_subtree(wpa_ucs_item, ett_wpa_ucs_tree);
for (ii = 0; ii < ucs_count; ii++)
{
wpa_sub_ucs_item = proto_tree_add_item(wpa_ucs_tree, hf_ieee80211_wfa_ie_wpa_ucs, tvb, offset, 4, ENC_BIG_ENDIAN);
wpa_sub_ucs_tree = proto_item_add_subtree(wpa_sub_ucs_item, ett_wpa_sub_ucs_tree);
proto_tree_add_item(wpa_sub_ucs_tree, hf_ieee80211_wfa_ie_wpa_ucs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if (tvb_get_ntoh24(tvb, offset) == OUI_WPAWME)
{
proto_tree_add_item(wpa_sub_ucs_tree, hf_ieee80211_wfa_ie_wpa_ucs_wfa_type, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(wpa_ucs_item, " %s", wpa_ucs_return(tvb_get_ntohl(tvb, offset)));
} else {
proto_tree_add_item(wpa_sub_ucs_tree, hf_ieee80211_wfa_ie_wpa_ucs_type, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
}
offset += 4;
}
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_akms_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
akms_count = tvb_get_letohs(tvb, offset);
offset += 2;
wpa_akms_item = proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_akms_list, tvb, offset, akms_count * 4, ENC_NA);
wpa_akms_tree = proto_item_add_subtree(wpa_akms_item, ett_wpa_akms_tree);
for (ii = 0; ii < akms_count; ii++)
{
wpa_sub_akms_item = proto_tree_add_item(wpa_akms_tree, hf_ieee80211_wfa_ie_wpa_akms, tvb, offset, 4, ENC_BIG_ENDIAN);
wpa_sub_akms_tree = proto_item_add_subtree(wpa_sub_akms_item, ett_wpa_sub_akms_tree);
proto_tree_add_item(wpa_sub_akms_tree, hf_ieee80211_wfa_ie_wpa_akms_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if (tvb_get_ntoh24(tvb, offset) == OUI_WPAWME)
{
proto_tree_add_item(wpa_sub_akms_tree, hf_ieee80211_wfa_ie_wpa_akms_wfa_type, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(wpa_akms_item, " %s", wpa_akms_return(tvb_get_ntohl(tvb, offset)));
} else {
proto_tree_add_item(wpa_sub_akms_tree, hf_ieee80211_wfa_ie_wpa_akms_type, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
}
offset += 4;
}
break;
}
case 2:
{
guint8 subtype;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_subtype, tvb, offset, 1, ENC_NA);
subtype = tvb_get_guint8(tvb, offset);
proto_item_append_text(tree, ": %s", val_to_str(subtype, ieee802111_wfa_ie_wme_type, "Unknown %d"));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_version, tvb, offset, 1, ENC_NA);
offset += 1;
switch (subtype) {
case 0:
{
offset = dissect_wme_qos_info(tree, tvb, pinfo, offset, ftype);
break;
}
case 1:
{
int i;
offset = dissect_wme_qos_info(tree, tvb, pinfo, offset, ftype);
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
for (i = 0; i < 4; i++)
{
proto_item *ac_item, *aci_aifsn_item, *ecw_item;
proto_tree *ac_tree, *aci_aifsn_tree, *ecw_tree;
guint8 aci_aifsn, ecw;
ac_item = proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_ac_parameters, tvb, offset, 4, ENC_NA);
ac_tree = proto_item_add_subtree(ac_item, ett_wme_ac);
aci_aifsn_item = proto_tree_add_item(ac_tree, hf_ieee80211_wfa_ie_wme_acp_aci_aifsn, tvb, offset, 1, ENC_NA);
aci_aifsn_tree = proto_item_add_subtree(aci_aifsn_item, ett_wme_aci_aifsn);
proto_tree_add_item(aci_aifsn_tree, hf_ieee80211_wfa_ie_wme_acp_aci, tvb, offset, 1, ENC_NA);
proto_tree_add_item(aci_aifsn_tree, hf_ieee80211_wfa_ie_wme_acp_acm, tvb, offset, 1, ENC_NA);
proto_tree_add_item(aci_aifsn_tree, hf_ieee80211_wfa_ie_wme_acp_aifsn, tvb, offset, 1, ENC_NA);
proto_tree_add_item(aci_aifsn_tree, hf_ieee80211_wfa_ie_wme_acp_reserved, tvb, offset, 1, ENC_NA);
aci_aifsn = tvb_get_guint8(tvb, offset);
proto_item_append_text(ac_item, " ACI %u (%s), ACM %s, AIFSN %u",
(aci_aifsn & 0x60) >> 5, try_val_to_str((aci_aifsn & 0x60) >> 5, ieee80211_wfa_ie_wme_acs_vals),
(aci_aifsn & 0x10) ? "yes" : "no", aci_aifsn & 0x0f);
offset += 1;
ecw_item = proto_tree_add_item(ac_tree, hf_ieee80211_wfa_ie_wme_acp_ecw, tvb, offset, 1, ENC_NA);
ecw_tree = proto_item_add_subtree(ecw_item, ett_wme_ecw);
proto_tree_add_item(ecw_tree, hf_ieee80211_wfa_ie_wme_acp_ecw_max, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ecw_tree, hf_ieee80211_wfa_ie_wme_acp_ecw_min, tvb, offset, 1, ENC_NA);
ecw = tvb_get_guint8(tvb, offset);
proto_item_append_text(ac_item, ", ECWmin %u, ECWmax %u", ecw & 0x0f, (ecw & 0xf0) >> 4);
offset += 1;
proto_tree_add_item(ac_tree, hf_ieee80211_wfa_ie_wme_acp_txop_limit, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(ac_item, ", TXOP %u", tvb_get_letohs(tvb, offset));
offset += 2;
}
break;
}
case 2:
{
proto_item *tsinfo_item;
proto_tree *tsinfo_tree;
tsinfo_item = proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_tsinfo, tvb, offset, 3, ENC_LITTLE_ENDIAN);
tsinfo_tree = proto_item_add_subtree(tsinfo_item, ett_tsinfo_tree);
proto_tree_add_item(tsinfo_tree, hf_ieee80211_wfa_ie_wme_tspec_tsinfo_tid, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tsinfo_tree, hf_ieee80211_wfa_ie_wme_tspec_tsinfo_direction, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tsinfo_tree, hf_ieee80211_wfa_ie_wme_tspec_tsinfo_psb, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tsinfo_tree, hf_ieee80211_wfa_ie_wme_tspec_tsinfo_up, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tsinfo_tree, hf_ieee80211_wfa_ie_wme_tspec_tsinfo_reserved, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_nor_msdu, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_max_msdu, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_min_srv, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_max_srv, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_inact_int, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_susp_int, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_srv_start, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_min_data, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_mean_data, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_peak_data, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_burst_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_delay_bound, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_min_phy, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_surplus, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_tspec_medium, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
}
default:
break;
}
break;
}
case 4:
{
dissect_wps_tlvs(tree, tvb, offset, tag_len-1, NULL);
}
break;
default:
break;
}
return offset;
}
static void dissect_hs20_indication(proto_tree *tree, tvbuff_t *tvb,
int offset)
{
proto_tree_add_item(tree, hf_hs20_indication_dgaf_disabled, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
}
static void
dissect_vendor_ie_wfa(packet_info *pinfo, proto_item *item, tvbuff_t *tag_tvb)
{
gint tag_len = tvb_reported_length(tag_tvb);
if (tag_len < 4)
return;
switch (tvb_get_guint8(tag_tvb, 3)) {
case WFA_SUBTYPE_P2P:
dissect_wifi_p2p_ie(pinfo, item, tag_tvb, 4, tag_len - 4);
proto_item_append_text(item, ": P2P");
break;
case WFA_SUBTYPE_WIFI_DISPLAY:
dissect_wifi_display_ie(pinfo, item, tag_tvb, 4, tag_len - 4);
proto_item_append_text(item, ": Wi-Fi Display");
break;
case WFA_SUBTYPE_HS20_INDICATION:
dissect_hs20_indication(item, tag_tvb, 4);
proto_item_append_text(item, ": Hotspot 2.0 Indication");
break;
}
}
static void
dissect_vendor_ie_rsn(proto_item * item, proto_tree * tree, tvbuff_t * tvb, int offset, guint32 tag_len)
{
switch(tvb_get_guint8(tvb, offset)){
case 4:
{
proto_tree_add_item(tree, hf_ieee80211_rsn_ie_pmkid, tvb, offset, 16, ENC_NA);
}
break;
default:
proto_tree_add_item(tree, hf_ieee80211_rsn_ie_unknown, tvb, offset, tag_len, ENC_NA);
break;
}
proto_item_append_text(item, ": RSN");
}
static void
dissect_vendor_ie_marvell(proto_item *item _U_, proto_tree *ietree,
tvbuff_t *tvb, int offset, guint32 tag_len)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (type) {
case MARVELL_IE_MESH:
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_mesh_subtype, tvb,
offset++, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_mesh_version, tvb,
offset++, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_mesh_active_proto_id, tvb,
offset++, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_mesh_active_metric_id, tvb,
offset++, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_mesh_cap, tvb,
offset++, 1, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(ietree, hf_ieee80211_marvell_ie_data, tvb, offset,
tag_len - 1, ENC_NA);
break;
}
}
static void
dissect_vendor_ie_atheros_cap(proto_item *item _U_, tvbuff_t *tvb, int offset)
{
proto_tree *cap_tree;
cap_tree = proto_item_add_subtree(item, ett_ath_cap_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_atheros_ie_cap_f_turbop, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_ieee80211_atheros_ie_cap_f_comp, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_ieee80211_atheros_ie_cap_f_ff, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_ieee80211_atheros_ie_cap_f_xr, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_ieee80211_atheros_ie_cap_f_ar, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_ieee80211_atheros_ie_cap_f_burst, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_ieee80211_atheros_ie_cap_f_wme, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_ieee80211_atheros_ie_cap_f_boost, tvb, offset, 1, ENC_NA);
}
static void
dissect_vendor_ie_atheros(proto_item *item _U_, proto_tree *ietree,
tvbuff_t *tvb, int offset, guint tag_len,
packet_info *pinfo, proto_item *ti_len)
{
guint8 type;
guint8 subtype;
guint8 version;
proto_item *cap_item;
if (tag_len <= 3) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag length %u too short, must be >= 6", tag_len+3);
return;
}
proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_type, tvb, offset, 1, ENC_NA);
type = tvb_get_guint8(tvb, offset);
proto_item_append_text(item, ": %s", val_to_str_const(type, atheros_ie_type_vals, "Unknown"));
offset += 1;
tag_len -= 1;
proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_subtype, tvb, offset, 1, ENC_NA);
subtype = tvb_get_guint8(tvb, offset);
offset += 1;
tag_len -= 1;
proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_version, tvb, offset, 1, ENC_NA);
version = tvb_get_guint8(tvb, offset);
offset += 1;
tag_len -= 1;
if (version == 0)
{
switch (type) {
case ATHEROS_IE_ADVCAP:
{
switch (subtype) {
case ATHEROS_IE_ADVCAP_S:
{
cap_item = proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_advcap_cap, tvb, offset, 1, ENC_NA);
dissect_vendor_ie_atheros_cap(cap_item, tvb, offset);
offset += 1;
tag_len -= 1;
proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_advcap_defkey, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
tag_len -= 2;
break;
}
default:
break;
}
break;
}
case ATHEROS_IE_XR:
{
switch (subtype) {
case ATHEROS_IE_XR_S:
{
proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_xr_info, tvb, offset, 1, ENC_NA);
offset += 1;
tag_len -= 1;
proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_xr_base_bssid, tvb, offset, 6, ENC_NA);
offset += 6;
tag_len -= 6;
proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_xr_xr_bssid, tvb, offset, 6, ENC_NA);
offset += 6;
tag_len -= 6;
proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_xr_xr_beacon, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
tag_len -= 2;
cap_item = proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_xr_base_cap, tvb, offset, 1, ENC_NA);
dissect_vendor_ie_atheros_cap(cap_item, tvb, offset);
offset += 1;
tag_len -= 1;
cap_item = proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_xr_xr_cap, tvb, offset, 1, ENC_NA);
dissect_vendor_ie_atheros_cap(cap_item, tvb, offset);
offset += 1;
tag_len -= 1;
break;
}
default:
break;
}
break;
default:
break;
}
}
}
if (tag_len > 0) {
proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_data, tvb, offset, tag_len, ENC_NA);
}
}
static void
dissect_vendor_ie_aironet(proto_item *aironet_item, proto_tree *ietree,
tvbuff_t *tvb, int offset, guint32 tag_len)
{
guint8 type;
int i;
gboolean dont_change = FALSE;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item (ietree, hf_ieee80211_aironet_ie_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (type) {
case AIRONET_IE_DTPC:
proto_tree_add_item (ietree, hf_ieee80211_aironet_ie_dtpc, tvb, offset, 2, ENC_NA);
proto_item_append_text(aironet_item, ": Aironet DTPC Powerlevel 0x%02X", tvb_get_guint8(tvb, offset));
dont_change = TRUE;
break;
case AIRONET_IE_VERSION:
proto_tree_add_item (ietree, hf_ieee80211_aironet_ie_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(aironet_item, ": Aironet CCX version = %d", tvb_get_guint8(tvb, offset));
dont_change = TRUE;
break;
case AIRONET_IE_QOS:
proto_tree_add_item (ietree, hf_ieee80211_aironet_ie_qos_reserved, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (ietree, hf_ieee80211_aironet_ie_qos_paramset, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
for (i = 0; i < 4; i++) {
guint8 byte1, byte2;
guint16 txop;
byte1 = tvb_get_guint8(tvb, offset);
byte2 = tvb_get_guint8(tvb, offset + 1);
txop = tvb_get_letohs(tvb, offset + 2);
proto_tree_add_bytes_format(ietree, hf_ieee80211_aironet_ie_qos_val, tvb, offset, 4, NULL,
"CCX QoS Parameters: ACI %u (%s), Admission Control %sMandatory, AIFSN %u, ECWmin %u, ECWmax %u, TXOP %u",
(byte1 & 0x60) >> 5, val_to_str((byte1 & 0x60) >> 5, wme_acs, "(Unknown: %d)"),
(byte1 & 0x10) ? "" : "not ", byte1 & 0x0f,
byte2 & 0x0f, (byte2 & 0xf0) >> 4,
txop);
offset += 4;
}
break;
case AIRONET_IE_QBSS_V2:
proto_tree_add_item (ietree, hf_ieee80211_qbss2_scount, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ietree, hf_ieee80211_qbss2_cu, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ietree, hf_ieee80211_qbss2_cal, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ietree, hf_ieee80211_qbss2_gl, tvb, offset + 4, 1, ENC_LITTLE_ENDIAN);
break;
case AIRONET_IE_CLIENT_MFP:
proto_tree_add_item (ietree, hf_ieee80211_aironet_ie_clientmfp, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(aironet_item, ": Aironet Client MFP %s",
val_to_str_const(1 & tvb_get_guint8(tvb, offset), aironet_mfp_vals, "Unknown"));
dont_change = TRUE;
break;
default:
proto_tree_add_item(ietree, hf_ieee80211_aironet_ie_data, tvb, offset,
tag_len - 1, ENC_NA);
break;
}
if (!dont_change) {
proto_item_append_text(aironet_item, ": Aironet %s (%d)",
val_to_str_const(type, aironet_ie_type_vals, "Unknown"), type);
}
}
static void
dissect_vendor_ie_aruba(proto_item *item, proto_tree *ietree,
tvbuff_t *tvb, int offset, guint32 tag_len)
{
guint8 type;
offset += 1;
tag_len -= 1;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item (ietree, hf_ieee80211_vs_aruba_subtype, tvb, offset, 1, ENC_NA);
proto_item_append_text(item, ": %s", val_to_str_const(type, ieee80211_vs_aruba_subtype_vals, "Unknown"));
offset += 1;
tag_len -= 1;
switch (type) {
case ARUBA_APNAME:
offset += 1;
tag_len -= 1;
proto_tree_add_item (ietree, hf_ieee80211_vs_aruba_apname, tvb,
offset, tag_len, ENC_ASCII|ENC_NA);
proto_item_append_text(item, " (%s)", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tag_len, ENC_ASCII));
break;
default:
proto_tree_add_item(ietree, hf_ieee80211_vs_aruba_data, tvb, offset,
tag_len, ENC_NA);
proto_item_append_text(item, " (Data: %s)", tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, tag_len));
break;
}
}
static proto_tree*
dissect_vendor_ie_nintendo_tlv(const int hfindex, proto_tree *ietree,
tvbuff_t *tvb, int offset, guint32 sublen)
{
proto_item *nintendo_item;
proto_tree *nintendo_tree;
nintendo_item = proto_tree_add_item(ietree, hfindex, tvb, offset, sublen, ENC_NA);
nintendo_tree = proto_item_add_subtree(nintendo_item, ett_nintendo);
proto_tree_add_item(nintendo_tree, hf_ieee80211_vs_nintendo_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(nintendo_tree, hf_ieee80211_vs_nintendo_length, tvb, offset + 1, 1, ENC_NA);
return nintendo_tree;
}
static void
dissect_vendor_ie_nintendo(proto_item *item _U_, proto_tree *ietree,
tvbuff_t *tvb, int offset, guint32 tag_len)
{
proto_tree *nintendo_tree;
guint8 subtype;
guint8 sublength;
guint32 length = tag_len;
offset += 1;
length -= 1;
while(length > 0 && length < 256) {
subtype = tvb_get_guint8(tvb, offset);
sublength = tvb_get_guint8(tvb, offset + 1);
switch(subtype) {
case NINTENDO_SERVICES:
nintendo_tree = dissect_vendor_ie_nintendo_tlv(hf_ieee80211_vs_nintendo_servicelist, ietree, tvb, offset, sublength + 2);
offset += 2;
length -= 2;
while (sublength > 4) {
proto_tree_add_item(nintendo_tree, hf_ieee80211_vs_nintendo_service, tvb, offset, 5, ENC_NA);
offset += 5;
length -= 5;
sublength -= 5;
}
break;
case NINTENDO_CONSOLEID:
nintendo_tree = dissect_vendor_ie_nintendo_tlv(hf_ieee80211_vs_nintendo_consoleid, ietree, tvb, offset, sublength + 2);
offset += + 2;
length -= + 2;
proto_tree_add_item(nintendo_tree, hf_ieee80211_vs_nintendo_consoleid, tvb, offset, sublength, ENC_NA);
offset += sublength;
length -= sublength;
break;
default:
nintendo_tree = dissect_vendor_ie_nintendo_tlv(hf_ieee80211_vs_nintendo_unknown, ietree, tvb, offset, sublength + 2);
offset += + 2;
length -= + 2;
proto_tree_add_item(nintendo_tree, hf_ieee80211_vs_nintendo_unknown, tvb, offset, sublength, ENC_NA);
offset += sublength;
length -= sublength;
break;
}
}
}
static int
dissect_qos_capability(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, int ftype)
{
switch (ftype) {
case MGT_ASSOC_REQ:
case MGT_PROBE_REQ:
case MGT_REASSOC_REQ:
{
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_QOS_INFO_STA);
break;
}
case MGT_BEACON:
case MGT_PROBE_RESP:
case MGT_ASSOC_RESP:
case MGT_REASSOC_RESP:
{
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_QOS_INFO_AP);
break;
}
default:
expert_add_info_format(pinfo, proto_tree_get_parent(tree), &ei_ieee80211_qos_info_bad_ftype,
"Could not deduce direction to decode correctly, ftype %u", ftype);
break;
}
return offset;
}
static int
dissect_rsn_ie(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb,
int offset, guint32 tag_len)
{
proto_item *rsn_gcs_item, *rsn_pcs_item, *rsn_akms_item, *rsn_cap_item, *rsn_pmkid_item, *rsn_gmcs_item;
proto_item *rsn_sub_pcs_item, *rsn_sub_akms_item;
proto_item *rsn_pcs_count, *rsn_akms_count, *rsn_pmkid_count;
proto_tree *rsn_gcs_tree, *rsn_pcs_tree, *rsn_akms_tree, *rsn_cap_tree, *rsn_pmkid_tree, *rsn_gmcs_tree;
proto_tree *rsn_sub_pcs_tree, *rsn_sub_akms_tree;
guint16 pcs_count, akms_count, pmkid_count;
guint ii;
int tag_end = offset + tag_len;
proto_tree_add_item(tree, hf_ieee80211_rsn_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
rsn_gcs_item = proto_tree_add_item(tree, hf_ieee80211_rsn_gcs, tvb, offset, 4, ENC_BIG_ENDIAN);
rsn_gcs_tree = proto_item_add_subtree(rsn_gcs_item, ett_rsn_gcs_tree);
proto_tree_add_item(rsn_gcs_tree, hf_ieee80211_rsn_gcs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if (tvb_get_ntoh24(tvb, offset) == OUI_RSN)
{
proto_tree_add_item(rsn_gcs_tree, hf_ieee80211_rsn_gcs_80211_type, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(rsn_gcs_tree, hf_ieee80211_rsn_gcs_type, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
}
offset += 4;
rsn_pcs_count = proto_tree_add_item(tree, hf_ieee80211_rsn_pcs_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
pcs_count = tvb_get_letohs(tvb, offset);
offset += 2;
if (offset + (pcs_count * 4) > tag_end)
{
expert_add_info_format(pinfo, rsn_pcs_count, &ei_ieee80211_rsn_pcs_count,
"Pairwise Cipher Suite Count too large, 4*%u > %d", pcs_count, tag_end - offset);
pcs_count = (tag_end - offset) / 4;
}
rsn_pcs_item = proto_tree_add_item(tree, hf_ieee80211_rsn_pcs_list, tvb, offset, pcs_count * 4, ENC_NA);
rsn_pcs_tree = proto_item_add_subtree(rsn_pcs_item, ett_rsn_pcs_tree);
for (ii = 0; ii < pcs_count; ii++)
{
rsn_sub_pcs_item = proto_tree_add_item(rsn_pcs_tree, hf_ieee80211_rsn_pcs, tvb, offset, 4, ENC_BIG_ENDIAN);
rsn_sub_pcs_tree = proto_item_add_subtree(rsn_sub_pcs_item, ett_rsn_sub_pcs_tree);
proto_tree_add_item(rsn_sub_pcs_tree, hf_ieee80211_rsn_pcs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if (tvb_get_ntoh24(tvb, offset) == OUI_RSN)
{
proto_tree_add_item(rsn_sub_pcs_tree, hf_ieee80211_rsn_pcs_80211_type, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(rsn_pcs_item, " %s", rsn_pcs_return(tvb_get_ntohl(tvb, offset)));
} else {
proto_tree_add_item(rsn_sub_pcs_tree, hf_ieee80211_rsn_pcs_type, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
}
offset += 4;
}
if (offset >= tag_end)
{
return offset;
}
rsn_akms_count = proto_tree_add_item(tree, hf_ieee80211_rsn_akms_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
akms_count = tvb_get_letohs(tvb, offset);
offset += 2;
if (offset + (akms_count * 4) > tag_end)
{
expert_add_info_format(pinfo, rsn_akms_count, &ei_ieee80211_rsn_pmkid_count,
"Auth Key Management (AKM) Suite Count too large, 4*%u > %d", akms_count, tag_end - offset);
akms_count = (tag_end - offset) / 4;
}
rsn_akms_item = proto_tree_add_item(tree, hf_ieee80211_rsn_akms_list, tvb, offset, akms_count * 4, ENC_NA);
rsn_akms_tree = proto_item_add_subtree(rsn_akms_item, ett_rsn_akms_tree);
for (ii = 0; ii < akms_count; ii++)
{
rsn_sub_akms_item = proto_tree_add_item(rsn_akms_tree, hf_ieee80211_rsn_akms, tvb, offset, 4, ENC_BIG_ENDIAN);
rsn_sub_akms_tree = proto_item_add_subtree(rsn_sub_akms_item, ett_rsn_sub_akms_tree);
proto_tree_add_item(rsn_sub_akms_tree, hf_ieee80211_rsn_akms_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if (tvb_get_ntoh24(tvb, offset) == OUI_RSN)
{
proto_tree_add_item(rsn_sub_akms_tree, hf_ieee80211_rsn_akms_80211_type, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(rsn_akms_item, " %s", rsn_akms_return(tvb_get_ntohl(tvb, offset)));
} else {
proto_tree_add_item(rsn_sub_akms_tree, hf_ieee80211_rsn_akms_type, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
}
offset += 4;
}
rsn_cap_item = proto_tree_add_item(tree, hf_ieee80211_rsn_cap, tvb, offset, 2, ENC_LITTLE_ENDIAN);
rsn_cap_tree = proto_item_add_subtree(rsn_cap_item, ett_rsn_cap_tree);
proto_tree_add_item(rsn_cap_tree, hf_ieee80211_rsn_cap_preauth, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rsn_cap_tree, hf_ieee80211_rsn_cap_no_pairwise, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rsn_cap_tree, hf_ieee80211_rsn_cap_ptksa_replay_counter, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rsn_cap_tree, hf_ieee80211_rsn_cap_gtksa_replay_counter, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rsn_cap_tree, hf_ieee80211_rsn_cap_mfpr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rsn_cap_tree, hf_ieee80211_rsn_cap_mfpc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rsn_cap_tree, hf_ieee80211_rsn_cap_jmr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rsn_cap_tree, hf_ieee80211_rsn_cap_peerkey, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (offset >= tag_end)
{
return offset;
}
rsn_pmkid_count = proto_tree_add_item(tree, hf_ieee80211_rsn_pmkid_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
pmkid_count = tvb_get_letohs(tvb, offset);
offset += 2;
if (offset + (pmkid_count * 16) > tag_end)
{
expert_add_info_format(pinfo, rsn_pmkid_count, &ei_ieee80211_pmkid_count_too_large,
"PMKID Count too large, 16*%u > %d", pmkid_count, tag_end - offset);
pmkid_count = (tag_end - offset) / 16;
}
rsn_pmkid_item = proto_tree_add_item(tree, hf_ieee80211_rsn_pmkid_list, tvb, offset, pmkid_count * 16, ENC_NA);
rsn_pmkid_tree = proto_item_add_subtree(rsn_pmkid_item, ett_rsn_pmkid_tree);
for (ii = 0; ii < pmkid_count; ii++)
{
proto_tree_add_item(rsn_pmkid_tree, hf_ieee80211_rsn_pmkid, tvb, offset, 16, ENC_NA);
offset += 16;
}
if (offset >= tag_end)
{
return offset;
}
rsn_gmcs_item = proto_tree_add_item(tree, hf_ieee80211_rsn_gmcs, tvb, offset, 4, ENC_BIG_ENDIAN);
rsn_gmcs_tree = proto_item_add_subtree(rsn_gmcs_item, ett_rsn_gmcs_tree);
proto_tree_add_item(rsn_gmcs_tree, hf_ieee80211_rsn_gmcs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if (tvb_get_ntoh24(tvb, offset) == OUI_RSN)
{
proto_tree_add_item(rsn_gmcs_tree, hf_ieee80211_rsn_gmcs_80211_type, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(rsn_gmcs_tree, hf_ieee80211_rsn_gmcs_type, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
}
offset += 4;
return offset;
}
static int
dissect_extended_capabilities_ie(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset, int tag_end)
{
proto_item *ti_ex_cap;
proto_tree *ex_cap_tree;
if (tag_len < 1)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag length %u too short, must be greater than 0", tag_len);
return offset;
}
proto_item_append_text(ti, " (%u octet%s)", tag_len, plurality(tag_len, "", "s"));
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 1)");
ex_cap_tree = proto_item_add_subtree (ti_ex_cap, ett_tag_ex_cap1);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b0, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b1, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b2, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b3, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b4, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b5, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b6, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b7, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
return offset;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 2)");
ex_cap_tree = proto_item_add_subtree (ti_ex_cap, ett_tag_ex_cap2);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b8, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b9, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b10, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b11, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b12, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b13, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b14, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b15, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
return offset;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 3)");
ex_cap_tree = proto_item_add_subtree (ti_ex_cap, ett_tag_ex_cap3);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b16, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b17, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b18, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b19, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b20, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b21, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b22, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b23, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
return offset;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 4)");
ex_cap_tree = proto_item_add_subtree(ti_ex_cap, ett_tag_ex_cap4);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b24, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b25, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b26, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b27, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b28, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b29, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b30, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b31, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
return offset;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 5)");
ex_cap_tree = proto_item_add_subtree(ti_ex_cap, ett_tag_ex_cap5);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b32, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b33, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b34, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b35, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b36, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b37, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b38, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b39, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
return offset;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 6)");
ex_cap_tree = proto_item_add_subtree(ti_ex_cap, ett_tag_ex_cap6);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b40, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_serv_int_granularity, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b44, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b45, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b46, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b47, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
return offset;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 7)");
ex_cap_tree = proto_item_add_subtree(ti_ex_cap, ett_tag_ex_cap7);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b48, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_o7, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
return offset;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 8)");
ex_cap_tree = proto_item_add_subtree(ti_ex_cap, ett_tag_ex_cap8);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b61, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b62, tvb, offset, 1, ENC_NA);
ti_ex_cap = proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b63, tvb, offset, 1, ENC_NA);
if (offset+1 < tag_end) {
proto_item_append_text(ti_ex_cap, " (b63-64 Max Number of MSDUs in AMSDU: %s)",
val_to_str((tvb_get_guint8(tvb,offset) & 0x80) + ((tvb_get_guint8(tvb,offset+1) & 0x1) << 1),
vht_max_mpdu_in_amsdu,"Unknown:%d"));
}
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_o8, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
return offset;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 9)");
ex_cap_tree = proto_item_add_subtree(ti_ex_cap, ett_tag_ex_cap9);
ti_ex_cap = proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b64, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (b63-64 Max Number of MSDUs in AMSDU)");
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_o9, tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
static int
dissect_vht_mcs_set(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *ti;
proto_tree *mcs_tree, *rx_mcs_tree, *tx_mcs_tree;
ti = proto_tree_add_item(tree, hf_ieee80211_vht_mcsset, tvb, offset, 8, ENC_NA);
mcs_tree = proto_item_add_subtree(ti, ett_vht_mcsset_tree);
ti = proto_tree_add_item(mcs_tree, hf_ieee80211_vht_mcsset_rx_mcs_map, tvb, offset, 2, ENC_LITTLE_ENDIAN);
rx_mcs_tree = proto_item_add_subtree(ti, ett_vht_rx_mcsbit_tree);
proto_tree_add_item(rx_mcs_tree, hf_ieee80211_vht_mcsset_rx_max_mcs_for_1_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rx_mcs_tree, hf_ieee80211_vht_mcsset_rx_max_mcs_for_2_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rx_mcs_tree, hf_ieee80211_vht_mcsset_rx_max_mcs_for_3_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rx_mcs_tree, hf_ieee80211_vht_mcsset_rx_max_mcs_for_4_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rx_mcs_tree, hf_ieee80211_vht_mcsset_rx_max_mcs_for_5_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rx_mcs_tree, hf_ieee80211_vht_mcsset_rx_max_mcs_for_6_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rx_mcs_tree, hf_ieee80211_vht_mcsset_rx_max_mcs_for_7_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rx_mcs_tree, hf_ieee80211_vht_mcsset_rx_max_mcs_for_8_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(mcs_tree, hf_ieee80211_vht_mcsset_rx_highest_long_gi, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
ti = proto_tree_add_item(mcs_tree, hf_ieee80211_vht_mcsset_tx_mcs_map, tvb, offset, 2, ENC_LITTLE_ENDIAN);
tx_mcs_tree = proto_item_add_subtree(ti, ett_vht_tx_mcsbit_tree);
proto_tree_add_item(tx_mcs_tree, hf_ieee80211_vht_mcsset_tx_max_mcs_for_1_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tx_mcs_tree, hf_ieee80211_vht_mcsset_tx_max_mcs_for_2_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tx_mcs_tree, hf_ieee80211_vht_mcsset_tx_max_mcs_for_3_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tx_mcs_tree, hf_ieee80211_vht_mcsset_tx_max_mcs_for_4_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tx_mcs_tree, hf_ieee80211_vht_mcsset_tx_max_mcs_for_5_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tx_mcs_tree, hf_ieee80211_vht_mcsset_tx_max_mcs_for_6_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tx_mcs_tree, hf_ieee80211_vht_mcsset_tx_max_mcs_for_7_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tx_mcs_tree, hf_ieee80211_vht_mcsset_tx_max_mcs_for_8_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(mcs_tree, hf_ieee80211_vht_mcsset_tx_highest_long_gi, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_vht_capability_ie(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
guint32 tag_len, proto_item *ti_len)
{
proto_item *cap_item;
proto_tree *cap_tree;
if (tag_len != 12) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"VHT Capabilities IE length %u wrong, must be = 12", tag_len);
return offset;
}
cap_item = proto_tree_add_item(tree, hf_ieee80211_vht_cap, tvb, offset, 4, ENC_LITTLE_ENDIAN);
cap_tree = proto_item_add_subtree(cap_item, ett_vht_cap_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_max_mpdu_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_supported_chan_width_set, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_rx_ldpc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_short_gi_for_80, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_short_gi_for_160, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_tx_stbc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_rx_stbc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_su_beamformer_cap, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_su_beamformee_cap, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_beamformer_antennas, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_sounding_dimensions, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_mu_beamformer_cap, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_mu_beamformee_cap, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_txop_ps, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_var_htc_field, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_max_ampdu, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_link_adaptation_cap, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_rx_pattern, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_tx_pattern, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_vht_reserv, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_vht_mcs_set(tree, tvb, offset);
return offset;
}
static int
dissect_vht_operation_ie(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
guint32 tag_len, proto_item *ti_len)
{
proto_item *op_item, *ti;
proto_tree *op_tree, *basic_mcs_tree;
if (tag_len != 5) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"VHT Operation IE length %u wrong, must be = 5", tag_len);
return offset;
}
op_item = proto_tree_add_item(tree, hf_ieee80211_vht_op, tvb, offset, 3, ENC_NA);
op_tree = proto_item_add_subtree(op_item, ett_vht_op_tree);
proto_tree_add_item(op_tree, hf_ieee80211_vht_op_channel_width, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(op_tree, hf_ieee80211_vht_op_channel_center0, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(op_tree, hf_ieee80211_vht_op_channel_center1, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
offset += 3;
ti = proto_tree_add_item(tree, hf_ieee80211_vht_op_basic_mcs_map, tvb, offset, 2, ENC_LITTLE_ENDIAN);
basic_mcs_tree = proto_item_add_subtree(ti, ett_vht_basic_mcsbit_tree);
proto_tree_add_item(basic_mcs_tree, hf_ieee80211_vht_op_max_basic_mcs_for_1_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(basic_mcs_tree, hf_ieee80211_vht_op_max_basic_mcs_for_2_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(basic_mcs_tree, hf_ieee80211_vht_op_max_basic_mcs_for_3_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(basic_mcs_tree, hf_ieee80211_vht_op_max_basic_mcs_for_4_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(basic_mcs_tree, hf_ieee80211_vht_op_max_basic_mcs_for_5_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(basic_mcs_tree, hf_ieee80211_vht_op_max_basic_mcs_for_6_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(basic_mcs_tree, hf_ieee80211_vht_op_max_basic_mcs_for_7_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(basic_mcs_tree, hf_ieee80211_vht_op_max_basic_mcs_for_8_ss, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_vht_tx_pwr_envelope(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
guint32 tag_len, proto_item *ti_len)
{
proto_item *tx_pwr_item, *ti;
proto_tree *tx_pwr_info_tree;
guint8 opt_ie_cnt=0;
guint8 i;
if (tag_len < 2 || tag_len > 5) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"VHT TX PWR Envelope IE length %u wrong, must be >= 2 and <= 5", tag_len);
return offset;
}
tx_pwr_item = proto_tree_add_item(tree, hf_ieee80211_vht_tpe_pwr_info, tvb, offset, 1, ENC_NA);
tx_pwr_info_tree = proto_item_add_subtree(tx_pwr_item, ett_vht_tpe_info_tree);
ti = proto_tree_add_item(tx_pwr_info_tree, hf_ieee80211_vht_tpe_pwr_info_count, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tx_pwr_info_tree, hf_ieee80211_vht_tpe_pwr_info_unit, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tx_pwr_info_tree, hf_ieee80211_vht_tpe_pwr_info_reserved, tvb, offset, 1, ENC_LITTLE_ENDIAN);
opt_ie_cnt = tvb_get_guint8(tvb, offset) & 0x07;
offset += 1;
for (i = 0; i <= opt_ie_cnt; i++) {
switch(i) {
case 0:
proto_tree_add_item(tree, hf_ieee80211_vht_tpe_pwr_constr_20, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 1:
proto_tree_add_item(tree, hf_ieee80211_vht_tpe_pwr_constr_40, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 2:
proto_tree_add_item(tree, hf_ieee80211_vht_tpe_pwr_constr_80, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 3:
proto_tree_add_item(tree, hf_ieee80211_vht_tpe_pwr_constr_160, tvb, offset, 1, ENC_NA);
offset += 1;
break;
default:
expert_add_info(pinfo, ti, &ei_ieee80211_vht_tpe_pwr_info_count);
offset += 1;
break;
}
}
return offset;
}
static void
dissect_mobility_domain(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
if (tag_len < 3) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, offset, tag_len,
"MDIE content length must be at least 3 bytes");
return;
}
proto_tree_add_item(tree, hf_ieee80211_tag_mobility_domain_mdid,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_mobility_domain_ft_capab,
tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_mobility_domain_ft_capab_ft_over_ds,
tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_mobility_domain_ft_capab_resource_req,
tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_fast_bss_transition(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
int end = offset + tag_len;
if (tag_len < 82) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, offset, tag_len,
"FTIE content length must be at least 82 bytes");
return;
}
proto_tree_add_item(tree, hf_ieee80211_tag_ft_mic_control,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_ft_element_count,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_mic,
tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_anonce,
tvb, offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_snonce,
tvb, offset, 32, ENC_NA);
offset += 32;
while (offset + 2 <= end) {
guint8 id, len;
int s_end;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
id = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
len = tvb_get_guint8(tvb, offset);
offset += 1;
if (offset + len > end) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, offset,
end - offset, "Invalid FTIE subelement");
return;
}
s_end = offset + len;
switch (id) {
case 1:
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_r1kh_id,
tvb, offset, len, ENC_NA);
break;
case 2:
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_gtk_key_info,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_gtk_key_id,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (offset > s_end)
break;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_gtk_key_length,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (offset > s_end)
break;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_gtk_rsc,
tvb, offset, 8, ENC_NA);
offset += 8;
if (offset > s_end)
break;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_gtk_key,
tvb, offset, s_end - offset, ENC_NA);
break;
case 3:
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_r0kh_id,
tvb, offset, len, ENC_ASCII|ENC_NA);
break;
case 4:
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_igtk_key_id,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (offset > s_end)
break;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_igtk_ipn,
tvb, offset, 6, ENC_NA);
offset += 6;
if (offset > s_end)
break;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_igtk_key_length,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (offset > s_end)
break;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_igtk_key,
tvb, offset, 24, ENC_NA);
break;
default:
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_data,
tvb, offset, len, ENC_NA);
break;
}
offset = s_end;
}
}
static void
dissect_mmie(proto_tree *tree, tvbuff_t *tvb, int offset, guint32 tag_len)
{
if (tag_len < 16) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, offset, tag_len,
"MMIE content length must be at least 16 bytes");
return;
}
proto_tree_add_item(tree, hf_ieee80211_tag_mmie_keyid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_mmie_ipn, tvb, offset + 2, 6,
ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_mmie_mic, tvb, offset + 8, 8,
ENC_NA);
}
static void
dissect_ssid_list(proto_tree *tree, tvbuff_t *tvb, int offset, guint32 tag_len)
{
int end = offset + tag_len;
proto_tree *entry;
gboolean first = TRUE;
while (offset + 1 <= end) {
guint8 len = tvb_get_guint8(tvb, offset + 1);
guint8 *str;
if (offset + 2 + len > end)
break;
str = format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 2, len, ENC_ASCII), len);
proto_item_append_text(tree, "%c %s", (first ? ':' : ','), str);
first = FALSE;
entry = proto_tree_add_subtree_format(tree, tvb, offset, 2 + len, ett_ssid_list, NULL, "SSID: %s", str);
proto_tree_add_item(entry, hf_ieee80211_tag_number, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_uint(entry, hf_ieee80211_tag_length, tvb, offset, 1, len);
offset++;
proto_tree_add_item(entry, hf_ieee80211_tag_ssid, tvb, offset, len,
ENC_ASCII|ENC_NA);
offset += len;
}
}
static void
dissect_link_identifier(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
if (tag_len < 18) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, offset, tag_len,
"Link Identifier content length must be at least "
"18 bytes");
return;
}
proto_tree_add_item(tree, hf_ieee80211_tag_link_id_bssid, tvb,
offset, 6, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_link_id_init_sta, tvb,
offset + 6, 6, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_link_id_resp_sta, tvb,
offset + 12, 6, ENC_NA);
}
static void
dissect_wakeup_schedule(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
if (tag_len < 18) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, offset, tag_len,
"Wakeup Schedule content length must be at least "
"18 bytes");
return;
}
proto_tree_add_item(tree, hf_ieee80211_tag_wakeup_schedule_offset, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tag_wakeup_schedule_interval, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_ieee80211_tag_wakeup_schedule_awake_window_slots, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tag_wakeup_schedule_max_awake_dur,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tag_wakeup_schedule_idle_count, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_channel_switch_timing(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
if (tag_len < 4) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, offset, tag_len,
"Channel Switch Timing content length must be at "
"least 4 bytes");
return;
}
proto_tree_add_item(tree, hf_ieee80211_tag_channel_switch_timing_switch_time,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree,
hf_ieee80211_tag_channel_switch_timing_switch_timeout,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_pti_control(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
if (tag_len < 3) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, offset, tag_len,
"PTI Control content length must be at least "
"3 bytes");
return;
}
proto_tree_add_item(tree, hf_ieee80211_tag_pti_control_tid, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_pti_control_sequence_control, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_pu_buffer_status(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
if (tag_len < 1) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, offset, tag_len,
"PU Buffer Status content length must be at least "
"1 byte");
return;
}
proto_tree_add_item(tree, hf_ieee80211_tag_pu_buffer_status_ac_bk, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pu_buffer_status_ac_be, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pu_buffer_status_ac_vi, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pu_buffer_status_ac_vo, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_timeout_interval(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
guint32 tag_len)
{
proto_item *pi;
pi = proto_tree_add_item(tree, hf_ieee80211_tag_timeout_int_type, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
if (tag_len < 5) {
expert_add_info_format(pinfo, pi, &ei_ieee80211_tag_length,
"Timeout Interval content length must be at least "
"5 bytes");
return;
}
proto_tree_add_item(tree, hf_ieee80211_tag_timeout_int_value, tvb,
offset + 1, 4, ENC_LITTLE_ENDIAN);
}
static int
dissect_ric_data(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len, proto_item *ti, proto_item *ti_len, int ftype)
{
proto_tree *sub_tree;
guint8 desc_cnt = 0;
guint32 next_ie;
int offset_r = 0;
if (tag_len != 4) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"RIC Data Length must be 4 bytes");
return 0;
}
proto_tree_add_item(tree, hf_ieee80211_tag_ric_data_id, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
desc_cnt = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_ieee80211_tag_ric_data_desc_cnt, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_ric_data_status_code, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
sub_tree = proto_item_add_subtree(tree, ett_tag_ric_data_desc_ie);
proto_item_append_text(ti, " :Resource Descriptor List");
if (desc_cnt == 0) {
proto_item_append_text(ti, " :0 (Weird?)");
}
while ( desc_cnt !=0 ) {
next_ie = tvb_get_guint8(tvb,offset);
proto_item_append_text(ti, " :(%d:%s)", desc_cnt,val_to_str_ext(next_ie, &tag_num_vals_ext, "Reserved (%d)"));
offset_r = add_tagged_field(pinfo, sub_tree, tvb, offset, ftype);
if (offset_r == 0 )
break;
tag_len += offset_r;
desc_cnt--;
}
return tag_len;
}
static int
dissect_ric_descriptor(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len, proto_item *ti, proto_item *ti_len)
{
guint8 rsrc_type = 0;
if (tag_len < 1) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"RIC Data Length must be at least 1 byte");
return 0;
}
rsrc_type = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_ieee80211_tag_ric_desc_rsrc_type, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (rsrc_type == 1) {
proto_item_append_text(ti, " : Block ACK Params");
proto_tree_add_item(tree, hf_ieee80211_tag_ric_desc_var_params, tvb,
offset, tag_len-1, ENC_NA);
offset += tag_len -1;
}else {
proto_item_append_text(ti, " :Reserved (type != 1)");
}
return offset;
}
static int
dissect_ext_bss_load(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ext_bss_mu_mimo_capable_sta_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_ext_bss_ss_underutilization, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_ext_bss_observable_sec_20mhz_utilization, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_ext_bss_observable_sec_40mhz_utilization, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_ext_bss_observable_sec_80mhz_utilization, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_wide_bw_channel_switch(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_wide_bw_new_channel_width, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_wide_bw_new_channel_center_freq_segment0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_wide_bw_new_channel_center_freq_segment1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_channel_switch_wrapper(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
int tmp_sublen;
while (tag_len > 0){
tmp_sublen = tvb_get_guint8(tvb, offset + 1);
if(add_tagged_field(pinfo, tree, tvb, offset, 0) == 0){
break;
}
tag_len -= (tmp_sublen + 2);
offset += (tmp_sublen + 2);
}
return offset;
}
static int
dissect_operating_mode_notification(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *ti;
proto_tree *bit_tree;
ti = proto_tree_add_item(tree, hf_ieee80211_operat_notification_mode, tvb, offset, 1, ENC_NA);
bit_tree = proto_item_add_subtree(ti, ett_mcsbit_tree);
proto_tree_add_item(bit_tree, hf_ieee80211_operat_mode_field_channel_width, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_operat_mode_field_reserved, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_operat_mode_field_rxnss, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_operat_mode_field_rxnsstype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_mcs_set(proto_tree *tree, tvbuff_t *tvb, int offset, gboolean basic, gboolean vendorspecific)
{
proto_item *ti;
proto_tree *mcs_tree, *bit_tree;
guint8 rx_nss, tx_nss;
guint32 value_mcs_0_31, value_mcs_32_52, value_mcs_53_76;
guint16 tx_mcs_set;
rx_nss = tx_nss = 8;
if (vendorspecific)
{
ti = proto_tree_add_string(tree, hf_ieee80211_mcsset_vs, tvb, offset, 16,
basic ? "Basic MCS Set" : "MCS Set");
} else
{
ti = proto_tree_add_string(tree, hf_ieee80211_mcsset, tvb, offset, 16,
basic ? "Basic MCS Set" : "MCS Set");
}
mcs_tree = proto_item_add_subtree(ti, ett_mcsset_tree);
ti = proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_rx_bitmask, tvb, offset, 10, ENC_NA);
bit_tree = proto_item_add_subtree(ti, ett_mcsbit_tree);
value_mcs_0_31 = tvb_get_letohl(tvb, offset);
if (value_mcs_0_31 != 0x0)
{
if (!(value_mcs_0_31 & (0xffffff00))) {
rx_nss = 0;
} else if (!(value_mcs_0_31 & (0xffff0000))) {
rx_nss = 1;
} else if (!(value_mcs_0_31 & (0xff000000))) {
rx_nss = 2;
} else {
rx_nss = 3;
}
}
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_0to7, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_8to15, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_16to23, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_24to31, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
value_mcs_32_52 = tvb_get_letohl(tvb, offset);
if (!(value_mcs_32_52 & (0x1ffffe))) {
;
} else if (!(value_mcs_32_52 & (0x1fff80))) {
rx_nss = MAX(1,rx_nss);
} else {
rx_nss = MAX(2,rx_nss);
}
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_33to38, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_39to52, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 2;
value_mcs_53_76 = tvb_get_letohl(tvb, offset);
if ((value_mcs_53_76 & (0x1fffffe0))) {
rx_nss = MAX(3,rx_nss);
}
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_53to76, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_highest_data_rate, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
tx_mcs_set = tvb_get_letohs(tvb,offset);
if (!(tx_mcs_set & 0x0001) && !(tx_mcs_set & 0x0002))
{
tx_nss = 4;
}
if ((tx_mcs_set & 0x0001) && !(tx_mcs_set & 0x0002))
{
tx_nss = rx_nss;
}
proto_item_append_text(ti, ": %s",val_to_str(rx_nss,mcsset_tx_max_spatial_streams_flags,"Reserved:%d" ) );
proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_tx_mcs_set_defined, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_tx_rx_mcs_set_not_equal, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
ti = proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_tx_max_spatial_streams, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ", %s",val_to_str(tx_nss,mcsset_tx_max_spatial_streams_flags,"Reserved:%d" ) );
proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_tx_unequal_modulation, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset += 1;
offset += 3;
return offset;
}
static int
dissect_ht_info_ie_1_1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
guint32 tag_len, proto_item *ti_len)
{
proto_item *cap_item;
proto_tree *cap_tree;
cap_tree = tree;
if (tag_len < 22) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"HT Information IE content length %u wrong, must be at least 22 bytes", tag_len);
return offset;
}
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_primary_channel, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
cap_item = proto_tree_add_item(tree, hf_ieee80211_ht_info_delimiter1, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
cap_tree = proto_item_add_subtree(cap_item, ett_ht_info_delimiter1_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_secondary_channel_offset, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_channel_width, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_rifs_mode, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_psmp_stas_only, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_service_interval_granularity, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
cap_item = proto_tree_add_item(tree, hf_ieee80211_ht_info_delimiter2, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
cap_tree = proto_item_add_subtree(cap_item, ett_ht_info_delimiter2_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_operating_mode, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_non_greenfield_sta_present, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_transmit_burst_limit, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_obss_non_ht_stas_present, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_reserved_1, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
cap_item = proto_tree_add_item(tree, hf_ieee80211_ht_info_delimiter3, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
cap_tree = proto_item_add_subtree(cap_item, ett_ht_info_delimiter3_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_reserved_2, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_dual_beacon, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_dual_cts_protection, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_secondary_beacon, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_lsig_txop_protection_full_support, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_pco_active, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_pco_phase, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_info_reserved_3, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset = dissect_mcs_set(tree, tvb, offset, TRUE, FALSE);
return offset;
}
static int
dissect_wapi_param_set(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len,
proto_item *ti, int ftype)
{
proto_item *item;
proto_tree *subtree;
guint16 loop_cnt, version, akm_cnt = 1, ucast_cnt = 1, bkid_cnt = 1;
guint8 akm_suite_type = 0, ucast_cipher_type = 0, mcast_cipher_type = 0;
version = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_wapi_param_set_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (tag_len < 20) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"tag_len is %d, it's neither WAPI not BSS-AC-Access-Delay", tag_len);
return offset;
}
if (version != 1) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Version of WAPI protocol is %d, must be = 1", version);
return offset;
}
akm_cnt = tvb_get_letohs(tvb, offset);
item = proto_tree_add_item(tree, hf_ieee80211_tag_wapi_param_set_akm_suite_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (akm_cnt != 0) {
proto_item_append_text(ti, " : AKM Suite List:");
for (loop_cnt = 0; loop_cnt < akm_cnt; loop_cnt++) {
subtree = proto_item_add_subtree(item, ett_tag_wapi_param_set_akm_tree);
proto_tree_add_item(subtree, hf_ieee80211_tag_wapi_param_set_akm_suite_oui, tvb, offset, 3, ENC_NA);
offset += 3;
akm_suite_type = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subtree, hf_ieee80211_tag_wapi_param_set_akm_suite_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_item_append_text(ti, " (%d,%s)", loop_cnt+1,val_to_str(akm_suite_type,
ieee80211_wapi_suite_type_short,"Reserved: %d"));
}
proto_item_append_text(ti, " /");
} else {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Number of AKM suites is 0, must be min 1");
return offset;
}
ucast_cnt = tvb_get_letohs(tvb, offset);
item = proto_tree_add_item(tree, hf_ieee80211_tag_wapi_param_set_ucast_cipher_suite_count,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (ucast_cnt != 0) {
proto_item_append_text(ti, " Unicast Cipher List:");
for (loop_cnt = 0; loop_cnt < ucast_cnt; loop_cnt++) {
subtree = proto_item_add_subtree(item, ett_tag_wapi_param_set_ucast_tree);
proto_tree_add_item(subtree, hf_ieee80211_tag_wapi_param_set_ucast_cipher_suite_oui, tvb, offset, 3, ENC_NA);
offset += 3;
ucast_cipher_type = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subtree, hf_ieee80211_tag_wapi_param_set_ucast_cipher_suite_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_item_append_text(ti, " (%d,%s)", loop_cnt+1, val_to_str(ucast_cipher_type,ieee80211_wapi_cipher_type,"Reserved: %d"));
}
proto_item_append_text(ti, " /");
} else {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Number of Unicast Cipher suites is 0, must be min 1");
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_wapi_param_set_mcast_cipher_suite_oui, tvb, offset, 3, ENC_NA);
offset += 3;
mcast_cipher_type = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_ieee80211_tag_wapi_param_set_mcast_cipher_suite_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_item_append_text(ti, " Multicast Cipher: %s", val_to_str(mcast_cipher_type,ieee80211_wapi_cipher_type,"Reserved: %d"));
item = proto_tree_add_item(tree, hf_ieee80211_tag_wapi_param_set_capab, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_tag_wapi_param_set_preauth_tree);
proto_tree_add_item(subtree, hf_ieee80211_tag_wapi_param_set_capab_preauth, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_ieee80211_tag_wapi_param_set_capab_rsvd, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (ftype == MGT_ASSOC_REQ || ftype == MGT_REASSOC_REQ ) {
bkid_cnt = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_wapi_param_set_bkid_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (bkid_cnt != 0) {
for (loop_cnt = 0; loop_cnt < bkid_cnt; loop_cnt++) {
proto_tree_add_item(tree, hf_ieee80211_tag_wapi_param_set_bkid_list, tvb, offset, 16, ENC_NA);
offset += 16;
}
}
}
return offset;
}
static int dissect_bss_max_idle_period(proto_tree *tree, tvbuff_t *tvb,
int offset)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_max_idle_period,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_bss_max_idle_options_protected,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int dissect_tfs_request(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, int offset, guint32 tag_len,
int ftype)
{
int end = offset + tag_len;
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_request_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_request_ac_delete_after_match,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_request_ac_notify,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (offset + 1 >= end) {
expert_add_info_format(pinfo, tree, &ei_ieee80211_missing_data,
"No TFS Request subelements in TFS Request");
return end;
}
while (offset + 1 < end) {
guint8 id, len;
int s_offset, s_end;
id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_request_subelem_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_request_subelem_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (offset + len > end) {
expert_add_info_format(pinfo, tree, &ei_ieee80211_tag_length,
"Not enough data for TFS Request subelement");
return end;
}
switch (id) {
case TFS_REQ_SUBELEM_TFS:
s_offset = offset;
s_end = offset + len;
while (s_offset < s_end) {
int tlen = add_tagged_field(pinfo, tree, tvb, s_offset, ftype);
if (tlen==0)
break;
s_offset += tlen;
}
break;
default:
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_request_subelem,
tvb, offset, len, ENC_NA);
break;
}
offset += len;
}
if (offset < end) {
proto_tree_add_expert_format(tree, pinfo, &ei_ieee80211_extra_data,
tvb, offset, end - offset, "Extra data after TFS Subelements");
}
return end;
}
static int dissect_tfs_response(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, int offset, guint32 tag_len,
int ftype)
{
int end = offset + tag_len;
while (offset + 3 <= end) {
guint8 id, len;
int s_offset, s_end;
id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_response_subelem_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_response_subelem_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (offset + len > end) {
expert_add_info_format(pinfo, tree, &ei_ieee80211_tag_length,
"Not enough data for TFS Request subelement");
return end;
}
switch (id) {
case TFS_RESP_SUBELEM_TFS_STATUS:
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_response_status,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_response_id,
tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
break;
case TFS_RESP_SUBELEM_TFS:
s_offset = offset;
s_end = offset + len;
while (s_offset < s_end) {
int tlen = add_tagged_field(pinfo, tree, tvb, s_offset, ftype);
if (tlen==0)
break;
s_offset += tlen;
}
break;
default:
proto_tree_add_item(tree, hf_ieee80211_tag_tfs_response_subelem,
tvb, offset, len, ENC_NA);
break;
}
offset += len;
}
if (offset < end) {
proto_tree_add_expert_format(tree, pinfo, &ei_ieee80211_extra_data,
tvb, offset, end - offset, "Extra data after TFS Subelements");
}
return end;
}
static int dissect_wnm_sleep_mode(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_tag_wnm_sleep_mode_action_type,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_wnm_sleep_mode_response_status,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_wnm_sleep_mode_interval,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_time_adv(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 capab;
proto_item *item;
proto_tree *subtree;
struct tm tm, *now;
time_t t;
capab = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_time_adv_timing_capab,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (capab) {
case 1:
proto_tree_add_item(tree, hf_ieee80211_tag_time_adv_time_value,
tvb, offset, 10, ENC_NA);
offset += 10;
proto_tree_add_item(tree, hf_ieee80211_tag_time_adv_time_error,
tvb, offset, 5, ENC_NA);
offset += 5;
break;
case 2:
item = proto_tree_add_item(tree, hf_ieee80211_tag_time_adv_time_value,
tvb, offset, 10, ENC_NA);
subtree = proto_item_add_subtree(item, ett_tag_time_adv_tree);
memset(&tm, 0, sizeof(tm));
tm.tm_year = tvb_get_letohs(tvb, offset) - 1900;
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_year,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
tm.tm_mon = tvb_get_guint8(tvb, offset) - 1;
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_month,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
tm.tm_mday = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_day,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
tm.tm_hour = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_hours,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
tm.tm_min = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_minutes,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
tm.tm_sec = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_seconds,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(subtree,
hf_ieee80211_tag_time_adv_time_value_milliseconds,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_reserved,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
tm.tm_isdst = -1;
t = mktime(&tm);
if (t != -1) {
t += (time_t)(last_timestamp / 1000000);
now = localtime(&t);
if (now)
proto_item_append_text(item,
": current time=%u-%02u-%02u %02u:%02u:%02u",
now->tm_year + 1900, now->tm_mon + 1,
now->tm_mday, now->tm_hour, now->tm_min,
now->tm_sec);
}
proto_tree_add_item(tree, hf_ieee80211_tag_time_adv_time_error,
tvb, offset, 5, ENC_NA);
offset += 5;
proto_tree_add_item(tree, hf_ieee80211_tag_time_adv_time_update_counter,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
}
return offset;
}
static int
dissect_time_zone(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
proto_tree_add_item(tree, hf_ieee80211_tag_time_zone, tvb, offset, tag_len,
ENC_ASCII|ENC_NA);
return offset + tag_len;
}
static int
dissect_ap_channel_report(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len,
int tag_end, proto_item *ti)
{
if (tag_len < 1) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"AP Channel Report length %u wrong, must be > 1", tag_len);
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_ap_channel_report_operating_class, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": Operating Class %u, Channel List :", tvb_get_guint8(tvb, offset));
offset += 1;
while (offset < tag_end)
{
proto_tree_add_item(tree, hf_ieee80211_tag_ap_channel_report_channel_list, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti, " %u,", tvb_get_guint8(tvb, offset));
offset += 1;
}
return offset;
}
static int
dissect_secondary_channel_offset_ie(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len)
{
if (tag_len != 1) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Secondary Channel Offset length %u wrong, must be = 1", tag_len);
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_secondary_channel_offset, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bss_avg_access_delay_ie(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len)
{
if (tag_len != 1) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"BSS Average Access Delay length %u wrong, must be = 1", tag_len);
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_bss_ap_avg_access_delay, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_antenna_ie(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len)
{
if (tag_len != 1) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Antenna length %u wrong, must be = 1", tag_len);
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_antenna_id, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_rsni_ie(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len)
{
if (tag_len != 1) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"RSNI length %u wrong, must be = 1", tag_len);
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_rsni, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bss_available_admission_capacity_ie(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len)
{
proto_item *ti;
proto_tree *btree;
guint16 bitmask;
if (tag_len < 2) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"BSS Available Admission Capacity length %u wrong, must > = 2", tag_len);
return offset;
}
ti = proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
btree = proto_item_add_subtree(ti, ett_tag_bss_bitmask_tree);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up0, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up2, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up4, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up6, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up7, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_ac0, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_ac1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_ac2, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_ac3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btree, hf_ieee80211_tag_bss_avb_adm_cap_bitmask_rsv, tvb, offset, 2, ENC_LITTLE_ENDIAN);
bitmask = tvb_get_letohs(tvb, offset);
offset += 2;
if(bitmask & BSS_BITMASK_UP0)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_up0, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_UP1)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_up1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_UP2)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_up2, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_UP3)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_up3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_UP4)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_up4, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_UP5)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_up5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_UP6)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_up6, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_UP7)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_up7, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_AC0)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_ac0, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_AC1)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_ac1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_AC2)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_ac2, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if(bitmask & BSS_BITMASK_AC3)
{
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avb_adm_cap_ac3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
return offset;
}
static int
dissect_bss_ac_access_delay_ie(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len)
{
if (tag_len == 4) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"BSS AC Access Delay length %u wrong, must = 4", tag_len);
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avg_ac_access_delay_be, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avg_ac_access_delay_bk, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avg_ac_access_delay_vi, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_bss_avg_ac_access_delay_vo, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_rm_enabled_capabilities_ie(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset, int tag_end _U_)
{
proto_item *ti_ex_cap;
proto_tree *ex_cap_tree;
if (tag_len != 5)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "RM Enabled Capabilities length %u wrong, must = 4", tag_len);
return offset;
}
proto_item_append_text(ti, " (%d octets)", tag_len);
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_rm_enabled_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 1)");
ex_cap_tree = proto_item_add_subtree (ti_ex_cap, ett_tag_rm_cap1);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b0, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b1, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b2, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b3, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b4, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b5, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b6, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b7, tvb, offset, 1, ENC_NA);
offset += 1;
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_rm_enabled_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 2)");
ex_cap_tree = proto_item_add_subtree (ti_ex_cap, ett_tag_rm_cap2);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b8, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b9, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b10, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b11, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b12, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b13, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b14, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b15, tvb, offset, 1, ENC_NA);
offset += 1;
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_rm_enabled_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 3)");
ex_cap_tree = proto_item_add_subtree (ti_ex_cap, ett_tag_rm_cap3);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b16, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b17, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b18to20, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b21to23, tvb, offset, 1, ENC_NA);
offset += 1;
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_rm_enabled_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 4)");
ex_cap_tree = proto_item_add_subtree (ti_ex_cap, ett_tag_rm_cap4);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b24to26, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b27, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b28, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b29, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b30, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b31, tvb, offset, 1, ENC_NA);
offset += 1;
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_rm_enabled_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 5)");
ex_cap_tree = proto_item_add_subtree (ti_ex_cap, ett_tag_rm_cap5);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b32, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_b33, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_rm_enabled_capabilities_o5, tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
static int
dissect_ht_capability_ie(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
guint32 tag_len, proto_item *ti_len, gboolean vendorspecific)
{
proto_item *cap_item, *ti;
proto_tree *cap_tree;
if (tag_len != 26) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"HT Capabilities IE length %u wrong, must be = 26", tag_len);
return offset;
}
if (wlan_ignore_draft_ht && vendorspecific)
return offset;
if (vendorspecific)
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_ht_vs_cap, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
else
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_ht_cap, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
cap_tree = proto_item_add_subtree(cap_item, ett_ht_cap_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_ldpc_coding, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_chan_width, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_sm_pwsave, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_green, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_short20, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_short40, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_tx_stbc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_rx_stbc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_delayed_block_ack, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_max_amsdu, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_dss_cck_40, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_psmp, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_40_mhz_intolerant, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_l_sig, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (vendorspecific)
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_ampduparam_vs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
} else
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_ampduparam, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
cap_tree = proto_item_add_subtree(cap_item, ett_ampduparam_tree);
ti = proto_tree_add_item(cap_tree, hf_ieee80211_ampduparam_mpdu, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%04.0f[Bytes])",pow(2,13+(tvb_get_guint8(tvb, offset) & 0x3))-1);
proto_tree_add_item(cap_tree, hf_ieee80211_ampduparam_mpdu_start_spacing, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ampduparam_reserved, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset = dissect_mcs_set(tree, tvb, offset, FALSE, vendorspecific);
if (vendorspecific)
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_htex_vs_cap, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
cap_item = proto_tree_add_item(tree, hf_ieee80211_htex_cap, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
cap_tree = proto_item_add_subtree(cap_item, ett_htex_cap_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_htex_pco, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_htex_transtime, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_htex_mcs, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_htex_htc_support, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_htex_rd_responder, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (vendorspecific)
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_txbf_vs, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
cap_item = proto_tree_add_item(tree, hf_ieee80211_txbf, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
cap_tree = proto_item_add_subtree(cap_item, ett_txbf_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_cap, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_rcv_ssc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_tx_ssc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_rcv_ndp, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_tx_ndp, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_impl_txbf, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_calib, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_csi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_uncomp_fm, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_comp_fm, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_bf_csi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_uncomp_fm_feed, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_comp_fm_feed, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_min_group, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_csi_num_bf_ant, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_uncomp_sm_bf_ant, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_comp_sm_bf_ant, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_csi_max_rows_bf, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_chan_est, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_resrv, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (vendorspecific)
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_antsel_vs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
else
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_antsel, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
cap_tree = proto_item_add_subtree(cap_item, ett_antsel_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_antsel_b0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_antsel_b1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_antsel_b2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_antsel_b3, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_antsel_b4, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_antsel_b5, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_antsel_b6, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_antsel_b7, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_ht_info_ie_1_0(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
guint32 tag_len, proto_item *ti_len)
{
proto_item *cap_item;
proto_tree *cap_tree;
if (tag_len != 22) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag length %u wrong, must be = 22", tag_len);
return offset;
}
if (wlan_ignore_draft_ht)
return offset;
proto_tree_add_item(tree, hf_ieee80211_hta_cc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
cap_item = proto_tree_add_item(tree, hf_ieee80211_hta_cap, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
cap_tree = proto_item_add_subtree(cap_item, ett_hta_cap_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_ext_chan_offset, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_rec_tx_width, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_rifs_mode, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_controlled_access, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_service_interval, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset += 1;
cap_item = proto_tree_add_item(tree, hf_ieee80211_hta_cap, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
cap_tree = proto_item_add_subtree(cap_item, ett_hta_cap1_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_operating_mode, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_non_gf_devices, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
cap_item = proto_tree_add_item(tree, hf_ieee80211_hta_cap, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
cap_tree = proto_item_add_subtree(cap_item, ett_hta_cap2_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_basic_stbc_mcs, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_dual_stbc_protection, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_secondary_beacon, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_lsig_txop_protection, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_pco_active, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_hta_pco_phase, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_mcs_set(tree, tvb, offset, FALSE, TRUE);
return offset;
}
static void
dissect_ht_control(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *ti;
proto_tree *htc_tree, *lac_subtree, *mfb_subtree;
guint32 htc;
htc = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(tree, hf_ieee80211_htc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
htc_tree = proto_item_add_subtree(ti, ett_htc_tree);
proto_tree_add_item(htc_tree, hf_ieee80211_htc_vht, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (htc & HTC_VHT) {
proto_tree_add_item(htc_tree, hf_ieee80211_htc_mrq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (!(htc & HTC_UNSOLICITED_MFB)) {
if (htc & HTC_MRQ) {
proto_tree_add_item(htc_tree, hf_ieee80211_htc_msi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(htc_tree, hf_ieee80211_htc_msi_stbc_reserved, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(htc_tree, hf_ieee80211_htc_mfsi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
if (!HTC_NO_FEEDBACK_PRESENT(HTC_MFB(htc))) {
proto_tree_add_item(htc_tree, hf_ieee80211_htc_compressed_msi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(htc_tree, hf_ieee80211_htc_ppdu_stbc_encoded, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(htc_tree, hf_ieee80211_htc_msi_stbc_reserved, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(htc_tree, hf_ieee80211_htc_gid_l, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
ti = proto_tree_add_item(htc_tree, hf_ieee80211_htc_mfb, tvb, offset, 4, ENC_LITTLE_ENDIAN);
mfb_subtree = proto_item_add_subtree(ti, ett_mfb_subtree);
proto_tree_add_item(mfb_subtree, hf_ieee80211_htc_num_sts, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mfb_subtree, hf_ieee80211_htc_vht_mcs, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mfb_subtree, hf_ieee80211_htc_bw, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mfb_subtree, hf_ieee80211_htc_snr, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (!HTC_NO_FEEDBACK_PRESENT(HTC_MFB(htc))) {
proto_tree_add_item(htc_tree, hf_ieee80211_htc_gid_h, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(htc_tree, hf_ieee80211_htc_coding_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(htc_tree, hf_ieee80211_htc_fb_tx_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(htc_tree, hf_ieee80211_htc_reserved3, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(htc_tree, hf_ieee80211_htc_unsolicited_mfb, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
ti = proto_tree_add_item(htc_tree, hf_ieee80211_htc_lac, tvb, offset, 4, ENC_LITTLE_ENDIAN);
lac_subtree = proto_item_add_subtree(ti, ett_lac_subtree);
proto_tree_add_item(lac_subtree, hf_ieee80211_htc_lac_trq, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (HTC_IS_ASELI(htc)) {
proto_tree_add_item(lac_subtree, hf_ieee80211_htc_lac_mai_aseli, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(lac_subtree, hf_ieee80211_htc_lac_mai_mrq, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (HTC_LAC_MAI_MRQ(htc)) {
proto_tree_add_item(lac_subtree, hf_ieee80211_htc_lac_mai_msi, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(lac_subtree, hf_ieee80211_htc_lac_mai_reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
}
proto_tree_add_item(lac_subtree, hf_ieee80211_htc_lac_mfsi, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (HTC_IS_ASELI(htc)) {
proto_tree_add_item(lac_subtree, hf_ieee80211_htc_lac_asel_command, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lac_subtree, hf_ieee80211_htc_lac_asel_data, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(lac_subtree, hf_ieee80211_htc_lac_mfb, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(htc_tree, hf_ieee80211_htc_cal_pos, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(htc_tree, hf_ieee80211_htc_cal_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(htc_tree, hf_ieee80211_htc_reserved1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(htc_tree, hf_ieee80211_htc_csi_steering, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(htc_tree, hf_ieee80211_htc_ndp_announcement, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(htc_tree, hf_ieee80211_htc_reserved2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(htc_tree, hf_ieee80211_htc_ac_constraint, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(htc_tree, hf_ieee80211_htc_rdg_more_ppdu, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
dissect_frame_control(proto_tree *tree, tvbuff_t *tvb, gboolean wlan_broken_fc,
guint32 offset, packet_info *pinfo)
{
guint16 fcf, flags, frame_type_subtype;
proto_tree *fc_tree, *flag_tree;
proto_item *fc_item, *flag_item, *hidden_item, *ti;
fcf = FETCH_FCF(offset);
flags = FCF_FLAGS(fcf);
frame_type_subtype = COMPOSE_FRAME_TYPE(fcf);
if(wlan_broken_fc)
{
offset += 1;
}
proto_tree_add_uint(tree, hf_ieee80211_fc_frame_type_subtype, tvb, offset, 1, frame_type_subtype);
fc_item = proto_tree_add_item(tree, hf_ieee80211_fc_field, tvb, offset, 2, ENC_BIG_ENDIAN);
fc_tree = proto_item_add_subtree(fc_item, ett_fc_tree);
proto_tree_add_item(fc_tree, hf_ieee80211_fc_proto_version, tvb, offset, 1, ENC_NA);
proto_tree_add_item(fc_tree, hf_ieee80211_fc_frame_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(fc_tree, hf_ieee80211_fc_frame_subtype, tvb, offset, 1, ENC_NA);
if(IS_FRAME_EXTENSION(fcf) == 1) {
proto_tree_add_uint (fc_tree, hf_ieee80211_fc_frame_extension, tvb, offset, 1, FCF_FRAME_EXTENSION (fcf));
}
offset += 1;
if(wlan_broken_fc)
{
offset -= 1;
proto_item_append_text(fc_item, "(Swapped)");
}
flag_item = proto_tree_add_item(fc_tree, hf_ieee80211_fc_flags, tvb, offset, 1, ENC_NA);
flag_tree = proto_item_add_subtree (flag_item, ett_proto_flags);
if(IS_FRAME_EXTENSION(fcf) == 0) {
proto_tree_add_item (flag_tree, hf_ieee80211_fc_data_ds, tvb, offset, 1, ENC_NA);
hidden_item = proto_tree_add_item(flag_tree, hf_ieee80211_fc_to_ds, tvb, offset, 1, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(flag_tree, hf_ieee80211_fc_from_ds, tvb, offset, 1, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(flag_tree, hf_ieee80211_fc_more_frag, tvb, offset, 1,ENC_NA);
ti = proto_tree_add_item(flag_tree, hf_ieee80211_fc_retry, tvb, offset, 1, ENC_NA);
if( IS_RETRY(flags) )
{
expert_add_info(pinfo, ti, &ei_ieee80211_fc_retry);
}
}
proto_tree_add_item(flag_tree, hf_ieee80211_fc_pwr_mgt, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flag_tree, hf_ieee80211_fc_more_data, tvb, offset, 1, ENC_NA);
if(IS_FRAME_EXTENSION(fcf) == 0) {
proto_tree_add_item(flag_tree, hf_ieee80211_fc_protected, tvb, offset, 1,ENC_NA);
}
proto_tree_add_item(flag_tree, hf_ieee80211_fc_order, tvb, offset, 1, ENC_NA);
}
static void
dissect_durid(proto_tree *hdr_tree, tvbuff_t *tvb, guint16 fts, gint offset)
{
guint16 durid = tvb_get_letohs(tvb, offset);
if (durid < 0x8000) {
proto_tree_add_uint_format_value(hdr_tree, hf_ieee80211_did_duration, tvb,
offset, 2, durid, "%u microseconds", durid);
} else if (((durid & 0xC000) == 0xC000) &&
((durid & 0x3FFF) > 0) && ((durid & 0x3FFF) <= 2007) &&
(fts == CTRL_PS_POLL)) {
proto_tree_add_item(hdr_tree, hf_ieee80211_assoc_id, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
} else if (durid == 0x8000) {
proto_tree_add_uint_format(hdr_tree, hf_ieee80211_did_duration, tvb,
offset, 2, durid, "Duration/ID: %u", durid);
} else {
proto_tree_add_uint_format(hdr_tree, hf_ieee80211_did_duration, tvb,
offset, 2, durid, "Duration/ID: %u (reserved)", durid & 0x3FFF);
}
}
static void
dissect_vendor_ie_ht(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, proto_item *item, proto_item *ti_len, gint tag_len)
{
guint8 type;
proto_tree_add_item(tree, hf_ieee80211_ht_pren_type, tvb, offset, 1, ENC_NA);
type = tvb_get_guint8(tvb, offset);
offset += 1;
tag_len -= 1;
switch(type){
case 51:
dissect_ht_capability_ie(tvb, pinfo, tree, offset, tag_len, ti_len, TRUE);
proto_item_append_text(item, ": HT Capabilities (802.11n D1.10)");
break;
case 52:
dissect_ht_info_ie_1_0(tvb, pinfo, tree, offset, tag_len, ti_len);
proto_item_append_text(item, ": HT Additional Capabilities (802.11n D1.00)");
break;
default:
proto_tree_add_item(tree, hf_ieee80211_ht_pren_unknown, tvb, offset, tag_len, ENC_NA);
break;
}
}
static guint
dissect_interworking(packet_info *pinfo, proto_tree *tree, proto_item *item,
tvbuff_t *tvb, int offset)
{
guint8 len;
offset += 1;
len = tvb_get_guint8(tvb, offset);
offset += 1;
if ((tvb_reported_length_remaining(tvb, offset) < len) || (len == 0)) {
expert_add_info_format(pinfo, item, &ei_ieee80211_tag_length,
"Truncated Interworking element");
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_access_network_type,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_internet,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_asra,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_esr,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_uesa,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if ((len == (1 + 2)) || (len == (1 + 2 + 6))) {
dissect_venue_info(tree, tvb, offset);
offset += 2;
}
if ((len == (1 + 6)) || (len == (1 + 2 + 6))) {
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_hessid,
tvb, offset, 6, ENC_NA);
offset += 6;
}
if ((len != 1) && (len != (1 + 2)) && (len != (1 + 6)) && (len != (1 + 2 + 6))) {
expert_add_info_format(pinfo, item, &ei_ieee80211_tag_length,
"Invalid Interworking element length");
}
return offset;
}
static guint
dissect_qos_map_set(packet_info *pinfo, proto_tree *tree, proto_item *item,
tvbuff_t *tvb, int offset)
{
guint8 len, left;
guint8 val, val2;
int i;
proto_item *dscp_item;
proto_tree *dscp_tree;
offset++;
len = tvb_get_guint8(tvb, offset);
offset++;
if (tvb_reported_length_remaining(tvb, offset) < len || len < 16 || len & 1) {
expert_add_info_format(pinfo, item, &ei_ieee80211_bad_length,
"Truncated QoS Map Set element");
return 2 + len;
}
left = len - 16;
while (left >= 2) {
dscp_item = proto_tree_add_item(tree, hf_ieee80211_tag_qos_map_set_dscp_exc,
tvb, offset, 2, ENC_NA);
dscp_tree = proto_item_add_subtree(dscp_item, ett_qos_map_set_exception);
item = proto_tree_add_item(dscp_tree,
hf_ieee80211_tag_qos_map_set_dscp_exc_val,
tvb, offset, 1, ENC_NA);
val = tvb_get_guint8(tvb, offset);
if (val > 63 && val != 255) {
expert_add_info_format(pinfo, item, &ei_ieee80211_inv_val,
"Invalid DSCP Value");
}
offset++;
item = proto_tree_add_item(dscp_tree,
hf_ieee80211_tag_qos_map_set_dscp_exc_up,
tvb, offset, 1, ENC_NA);
val2 = tvb_get_guint8(tvb, offset);
if (val2 > 7) {
expert_add_info_format(pinfo, item, &ei_ieee80211_inv_val,
"Invalid User Priority");
}
offset++;
proto_item_append_text(dscp_item, " (0x%02x: UP %u)", val, val2);
left -= 2;
}
for (i = 0; i < 8; i++) {
dscp_item = proto_tree_add_item(tree, hf_ieee80211_tag_qos_map_set_range,
tvb, offset, 2, ENC_NA);
dscp_tree = proto_item_add_subtree(dscp_item, ett_qos_map_set_exception);
item = proto_tree_add_item(dscp_tree, hf_ieee80211_tag_qos_map_set_low,
tvb, offset, 1, ENC_NA);
val = tvb_get_guint8(tvb, offset);
if (val > 63 && val != 255) {
expert_add_info_format(pinfo, item, &ei_ieee80211_inv_val,
"Invalid DSCP Value");
}
offset++;
item = proto_tree_add_item(dscp_tree, hf_ieee80211_tag_qos_map_set_high,
tvb, offset, 1, ENC_NA);
val2 = tvb_get_guint8(tvb, offset);
if ((val2 > 63 && val2 != 255) || val2 < val ||
(val == 255 && val2 != 255) || (val != 255 && val2 == 255)) {
expert_add_info_format(pinfo, item, &ei_ieee80211_inv_val,
"Invalid DSCP Value");
}
offset++;
if (val == 255 && val2 == 255) {
proto_item_append_text(dscp_item, " (UP %u not in use)", i);
} else {
proto_item_append_text(dscp_item, " (0x%02x-0x%02x: UP %u)",
val, val2, i);
}
}
return 2 + len;
}
static guint
dissect_roaming_consortium(packet_info *pinfo, proto_tree *tree,
proto_item *item, tvbuff_t *tvb, int offset)
{
guint8 len, oi_lens, oi1_len, oi2_len;
int end;
offset += 1;
len = tvb_get_guint8(tvb, offset);
offset += 1;
end = offset + len;
if ((tvb_reported_length_remaining(tvb, offset) < len) || (len < 2)) {
expert_add_info_format(pinfo, item, &ei_ieee80211_tag_length,
"Truncated Roaming Consortium element");
return 2 + len;
}
proto_tree_add_item(tree, hf_ieee80211_tag_roaming_consortium_num_anqp_oi,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
oi_lens = tvb_get_guint8(tvb, offset);
oi1_len = oi_lens & 0x0f;
oi2_len = (oi_lens & 0xf0) >> 4;
proto_tree_add_item(tree, hf_ieee80211_tag_roaming_consortium_oi1_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_roaming_consortium_oi2_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (offset + oi1_len > end) {
expert_add_info_format(pinfo, item, &ei_ieee80211_tag_length,
"Truncated Roaming Consortium element");
return 2 + len;
}
item = proto_tree_add_item(tree, hf_ieee80211_tag_roaming_consortium_oi1,
tvb, offset, oi1_len, ENC_NA);
add_manuf(item, tvb, offset);
offset += oi1_len;
if (offset + oi2_len > end) {
expert_add_info_format(pinfo, item, &ei_ieee80211_tag_length,
"Truncated Roaming Consortium element");
return 2 + len;
}
if (oi2_len > 0) {
proto_tree_add_item(tree, hf_ieee80211_tag_roaming_consortium_oi2,
tvb, offset, oi2_len, ENC_NA);
offset += oi2_len;
}
if (end > offset) {
proto_tree_add_item(tree, hf_ieee80211_tag_roaming_consortium_oi3,
tvb, offset, end - offset, ENC_NA);
}
return 2 + len;
}
static int
ieee80211_tag_ssid(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb, int offset)
{
gchar *ssid;
gint ssid_len = tag_len;
if (beacon_padding != 0)
return offset;
if (ssid_len > MAX_SSID_LEN) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"SSID length (%u) greater than maximum (%u)",
ssid_len, MAX_SSID_LEN);
ssid_len = MAX_SSID_LEN;
}
ssid = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 2, ssid_len, ENC_ASCII);
if (ssid_len == (gint)tag_len) {
AirPDcapSetLastSSID(&airpdcap_ctx, (CHAR *) ssid, ssid_len);
}
proto_tree_add_item(tree, hf_ieee80211_tag_ssid, tvb, offset + 2, tag_len,
ENC_ASCII|ENC_NA);
if (ssid_len > 0) {
proto_item_append_text(ti, ": %s", format_text(ssid, ssid_len));
col_append_fstr(pinfo->cinfo, COL_INFO, ", SSID=%s", format_text(ssid, ssid_len));
memcpy(wlan_stats.ssid, ssid, MIN(ssid_len, MAX_SSID_LEN));
wlan_stats.ssid_len = ssid_len;
} else {
proto_item_append_text(ti, ": Broadcast");
col_append_str(pinfo->cinfo, COL_INFO, ", SSID=Broadcast");
}
beacon_padding += 1;
return offset + 2 + tag_len;
}
static int
dissect_neighbor_report(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len,
int tag_end, proto_item *ti _U_)
{
guint8 sub_tag_id;
guint32 sub_tag_length;
proto_item *parent_item;
proto_tree *bssid_info_subtree, *bssid_info_cap_subtree, *sub_tag_tree;
tvbuff_t *volatile sub_tag_tvb = NULL;
if (tag_len < 13) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Neighbor Report length %u wrong, must be > 13", tag_len);
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_neighbor_report_bssid, tvb, offset, 6, ENC_NA);
offset += 6;
parent_item = proto_tree_add_item(tree, hf_ieee80211_tag_neighbor_report_bssid_info, tvb, offset, 4, ENC_LITTLE_ENDIAN);
bssid_info_subtree = proto_item_add_subtree(parent_item, ett_tag_neighbor_report_bssid_info_tree);
proto_tree_add_item(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_reachability, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_security, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_key_scope, tvb, offset, 4, ENC_LITTLE_ENDIAN);
parent_item = proto_tree_add_item(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability, tvb, offset, 4, ENC_LITTLE_ENDIAN);
bssid_info_cap_subtree = proto_item_add_subtree(parent_item, ett_tag_neighbor_report_bssid_info_capability_tree);
proto_tree_add_item(bssid_info_cap_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_spec_mng, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bssid_info_cap_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_qos, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bssid_info_cap_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_apsd, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bssid_info_cap_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_radio_msnt, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bssid_info_cap_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_dback, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bssid_info_cap_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_iback, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_mobility_domain, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_high_throughput, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_reserved, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tag_neighbor_report_ope_class, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_neighbor_report_channel_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_neighbor_report_phy_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (tag_len == 13){
return offset;
}
while (offset < tag_end)
{
sub_tag_id = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_neighbor_report_subelement_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
sub_tag_length = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_neighbor_report_subelement_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
sub_tag_tvb = tvb_new_subset_length(tvb, offset, sub_tag_length);
switch (sub_tag_id) {
case NR_SUB_ID_TSF_INFO:
break;
case NR_SUB_ID_MEASUREMENT_PILOT_INFO:
break;
case NR_SUB_ID_HT_CAPABILITIES:
sub_tag_tree = proto_tree_add_subtree(tree, tvb, offset, sub_tag_length,
ett_tag_neighbor_report_sub_tag_tree, NULL, "HT Capabilities");
dissect_ht_capability_ie(sub_tag_tvb, pinfo, sub_tag_tree, 0, sub_tag_length, ti_len, FALSE);
break;
case NR_SUB_ID_HT_OPERATION:
sub_tag_tree = proto_tree_add_subtree(tree, tvb, offset, sub_tag_length,
ett_tag_neighbor_report_sub_tag_tree, NULL, "HT Information");
dissect_ht_info_ie_1_1(sub_tag_tvb, pinfo, sub_tag_tree, 0, sub_tag_length, ti_len);
break;
case NR_SUB_ID_SEC_CHANNEL_OFFSET:
sub_tag_tree = proto_tree_add_subtree(tree, tvb, offset, sub_tag_length,
ett_tag_neighbor_report_sub_tag_tree, NULL, "Secondary Channel Offset");
dissect_secondary_channel_offset_ie(sub_tag_tvb, pinfo, sub_tag_tree, 0, sub_tag_length, ti_len);
break;
case NR_SUB_ID_VENDOR_SPECIFIC:
default:
break;
}
offset += sub_tag_length;
}
return offset;
}
static int
ieee80211_tag_supp_rates(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset, int tag_end)
{
if (tag_len < 1) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag length %u too short, must be greater than 0",
tag_len);
return offset;
}
offset += 2;
while (offset < tag_end) {
proto_tree_add_item(tree, hf_ieee80211_tag_supp_rates, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " %s,",
val_to_str_ext_const(tvb_get_guint8(tvb, offset),
&ieee80211_supported_rates_vals_ext,
"Unknown Rate"));
offset += 1;
}
proto_item_append_text(ti, " [Mbit/sec]");
return offset;
}
static int
ieee80211_tag_fh_parameter(packet_info *pinfo, proto_tree *tree,
proto_item *ti_len, guint32 tag_len,
tvbuff_t *tvb, int offset)
{
if (tag_len < 5) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag length %u too short, must be >= 5", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_dwell_time,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hop_set,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hop_pattern,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hop_index,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
ieee80211_tag_ds_parameter(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset)
{
if (tag_len != 1) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag length %u wrong, must be = 1", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_ds_param_channel,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": Current Channel: %u",
tvb_get_guint8(tvb, offset));
wlan_stats.channel = tvb_get_guint8(tvb, offset);
offset += 1;
return offset;
}
static int
ieee80211_tag_cf_parameter(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset)
{
if (tag_len != 6) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag length %u wrong, must be = 6", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_cfp_count,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": CFP count %u", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_cfp_period,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": CFP Period %u", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_cfp_max_duration,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": CFP Max Duration %u",
tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_cfp_dur_remaining,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": CFP Dur Remaining %u",
tvb_get_letohs(tvb, offset));
offset += 1;
return offset;
}
static int
ieee80211_tag_tim(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb, int offset)
{
proto_tree *bmapctl_tree;
proto_item *bmapctl_item;
if (tag_len < 4) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag length %u too short, must be >= 4", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tim_dtim_count,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": DTIM %u of", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tim_dtim_period,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " %u bitmap", tvb_get_guint8(tvb, offset + 1));
offset += 1;
bmapctl_item = proto_tree_add_item(tree, hf_ieee80211_tim_bmapctl,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
bmapctl_tree = proto_item_add_subtree(bmapctl_item, ett_tag_bmapctl_tree);
proto_tree_add_item(bmapctl_tree, hf_ieee80211_tim_bmapctl_mcast,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bmapctl_tree, hf_ieee80211_tim_bmapctl_offset,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tim_partial_virtual_bitmap,
tvb, offset, tag_len - 3, ENC_NA);
offset += tag_len - 3;
return offset;
}
static int
ieee80211_tag_ibss_parameter(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset)
{
if (tag_len != 2) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag length %u wrong, must be = 2", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_ibss_atim_window,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": ATIM window 0x%x",
tvb_get_letohs(tvb, offset));
offset += 2;
return offset;
}
static int
ieee80211_tag_country_info(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset, int tag_end)
{
proto_tree *sub_tree;
proto_item *sub_item;
if (tag_len < 6) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag length %u too short, must be >= 6", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_country_info_code,
tvb, offset, 2, ENC_ASCII|ENC_NA);
proto_item_append_text(ti, ": Country Code %s",
tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 2, ENC_ASCII));
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_country_info_env,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ", Environment %s",
val_to_str(tvb_get_guint8(tvb, offset),
environment_vals,"Unknown (0x%02x)"));
offset += 1;
while (offset < tag_end) {
if ((tag_end - offset) < 3) {
proto_tree_add_item(tree, hf_ieee80211_tag_country_info_pad,
tvb, offset, 1, ENC_NA);
offset += 1;
continue;
}
if (tvb_get_guint8(tvb, offset) <= 200) {
sub_item = proto_tree_add_item(tree, hf_ieee80211_tag_country_info_fnm,
tvb, offset, 3, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_tag_country_fnm_tree);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_fnm_fcn,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(sub_item, ": First Channel Number: %d",
tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_fnm_nc,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(sub_item, ", Number of Channels: %d",
tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_fnm_mtpl,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(sub_item,
", Maximum Transmit Power Level: %d dBm",
tvb_get_guint8(tvb, offset));
offset += 1;
} else {
sub_item = proto_tree_add_item(tree, hf_ieee80211_tag_country_info_rrc,
tvb, offset, 3, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_tag_country_rcc_tree);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_rrc_oei,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(sub_item,
": Operating Extension Identifier: %d",
tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_rrc_oc,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(sub_item, ", Operating Class: %d",
tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_rrc_cc,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(sub_item, ", Coverage Class: %d",
tvb_get_guint8(tvb, offset));
offset += 1;
}
}
return offset;
}
static int
ieee80211_tag_fh_hopping_parameter(packet_info *pinfo,
proto_tree *tree,
proto_item *ti,
proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset)
{
if (tag_len < 2) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag length %u too short, must be >= 2", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_parameter_prime_radix,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": Prime Radix: %u", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_parameter_nb_channels,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ", Number of Channels: %u",
tvb_get_guint8(tvb, offset));
offset += 1;
return offset;
}
static int
ieee80211_tag_fh_hopping_table(packet_info *pinfo, proto_tree *tree,
proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset, int tag_end)
{
if (tag_len < 4) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag length %u too short, must be >= 4", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_table_flag,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_table_number_of_sets,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_table_modulus,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_table_offset,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
while (offset < tag_end) {
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_random_table,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
return offset;
}
int
add_tagged_field(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, int ftype)
{
guint32 oui;
tvbuff_t *tag_tvb;
const guint8 *tag_data_ptr;
guint32 tag_no, tag_len;
int n, ret;
char print_buff[SHORT_STR];
proto_tree *orig_tree = tree;
proto_item *ti = NULL;
proto_item *ti_len, *ti_tag;
int tag_end;
gboolean isDMG;
gboolean *p_isDMG = ((gboolean*)(p_get_proto_data(wmem_file_scope(), pinfo, proto_wlan, IS_DMG_KEY)));
isDMG = p_isDMG ? *p_isDMG : FALSE;
tag_no = tvb_get_guint8(tvb, offset);
tag_len = tvb_get_guint8(tvb, offset + 1);
tag_end = offset + 2 + tag_len;
if (tree) {
ti = proto_tree_add_item(orig_tree, hf_ieee80211_tag, tvb, offset, 2 + tag_len , ENC_NA);
proto_item_append_text(ti, ": %s", val_to_str_ext(tag_no, &tag_num_vals_ext, "Reserved (%d)"));
tree = proto_item_add_subtree(ti, ett_80211_mgt_ie);
}
ti_tag = proto_tree_add_item(tree, hf_ieee80211_tag_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
ti_len = proto_tree_add_uint(tree, hf_ieee80211_tag_length, tvb, offset + 1, 1, tag_len);
if (tag_len > (guint)tvb_reported_length_remaining(tvb, offset)) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length,
"Tag Length is longer than remaining payload");
}
switch (tag_no) {
case TAG_SSID:
offset += ieee80211_tag_ssid(pinfo, tree, ti, ti_len, tag_len, tvb,
offset);
break;
case TAG_SUPP_RATES:
offset += ieee80211_tag_supp_rates(pinfo, tree, ti, ti_len, tag_len, tvb,
offset, tag_end);
break;
case TAG_FH_PARAMETER:
offset += ieee80211_tag_fh_parameter(pinfo, tree, ti_len, tag_len, tvb,
offset);
break;
case TAG_DS_PARAMETER:
offset += ieee80211_tag_ds_parameter(pinfo, tree, ti, ti_len, tag_len, tvb,
offset);
break;
case TAG_CF_PARAMETER:
offset += ieee80211_tag_cf_parameter(pinfo, tree, ti, ti_len, tag_len, tvb,
offset);
break;
case TAG_TIM:
offset += ieee80211_tag_tim(pinfo, tree, ti, ti_len, tag_len, tvb, offset);
break;
case TAG_IBSS_PARAMETER:
offset += ieee80211_tag_ibss_parameter(pinfo, tree, ti, ti_len, tag_len,
tvb, offset);
break;
case TAG_COUNTRY_INFO:
offset += ieee80211_tag_country_info(pinfo, tree, ti, ti_len, tag_len, tvb,
offset, tag_end);
break;
case TAG_FH_HOPPING_PARAMETER:
offset += ieee80211_tag_fh_hopping_parameter(pinfo, tree, ti, ti_len,
tag_len, tvb, offset);
break;
case TAG_FH_HOPPING_TABLE:
offset += ieee80211_tag_fh_hopping_table(pinfo, tree, ti_len, tag_len,
tvb, offset, tag_end);
break;
case TAG_REQUEST:
while (offset < tag_end)
{
proto_tree_add_item(tree, hf_ieee80211_tag_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
break;
case TAG_QBSS_LOAD:
if ((tag_len < 4) || (tag_len > 5))
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 4 or 5", tag_len);
break;
}
if (tag_len == 4)
{
proto_item_append_text(ti, " Cisco QBSS Version 1 - non CCA");
proto_tree_add_uint(tree, hf_ieee80211_qbss_version, tvb, offset + 2, tag_len, 1);
proto_tree_add_item(tree, hf_ieee80211_qbss_scount, tvb, offset + 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_qbss_cu, tvb, offset + 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_qbss_adc, tvb, offset + 5, 1, ENC_LITTLE_ENDIAN);
}
else if (tag_len == 5)
{
proto_item *base_item;
proto_item_append_text(ti, " 802.11e CCA Version");
proto_tree_add_uint(tree, hf_ieee80211_qbss_version, tvb, offset + 2, tag_len, 2);
proto_tree_add_item(tree, hf_ieee80211_qbss_scount, tvb, offset + 2, 2, ENC_LITTLE_ENDIAN);
base_item = proto_tree_add_item(tree, hf_ieee80211_qbss_cu, tvb, offset + 4, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(base_item, " (%d%%)", 100*tvb_get_guint8(tvb, offset + 4)/255);
base_item = proto_tree_add_item(tree, hf_ieee80211_qbss_adc, tvb, offset + 5, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(base_item, " (%d us/s)", tvb_get_letohs(tvb, offset + 5)*32);
}
break;
#if 0
case TAG_EDCA_PARAM_SET:
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_QOS_INFO_AP);
offset += 1;
offset += 4;
offset += 4;
offset += 4;
offset += 4;
break;
#endif
case TAG_TSPEC:
if (isDMG == FALSE && tag_len != 55)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 55", tag_len);
break;
}
if (isDMG == TRUE && tag_len != 57)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 57", tag_len);
break;
}
offset += 2;
add_fixed_field(tree, tvb, pinfo, offset, FIELD_QOS_TS_INFO);
offset += 3;
proto_tree_add_item(tree, hf_ieee80211_tspec_nor_msdu, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tspec_max_msdu, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tspec_min_srv, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_max_srv, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_inact_int, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_susp_int, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_srv_start, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_min_data, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_mean_data, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_peak_data, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_burst_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_delay_bound, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_min_phy, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tspec_surplus, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tspec_medium, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if(isDMG == TRUE) {
proto_tree_add_item(tree, hf_ieee80211_tspec_dmg, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
}
break;
case TAG_TCLAS:
if (tag_len < 6)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag length %u too short, must be >= 6", tag_len);
break;
}
{
guint8 type;
guint8 version;
proto_item *class_mask;
proto_tree *mask_tree;
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tclas_up, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tclas_class_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
class_mask = proto_tree_add_item(tree, hf_ieee80211_tclas_class_mask,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (type)
{
case 0:
offset--;
mask_tree = proto_item_add_subtree(class_mask,
ett_tag_tclas_mask_tree);
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask0_src_addr,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask0_dst_addr,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask0_type,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tclas_src_mac_addr, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_ieee80211_tclas_dst_mac_addr, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_ieee80211_tclas_ether_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 1:
version = tvb_get_guint8(tvb, offset);
offset--;
mask_tree = proto_item_add_subtree(class_mask,
ett_tag_tclas_mask_tree);
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask1_ver,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask1_src_ip,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask1_dst_ip,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask1_src_port,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask1_dst_port,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
if (version == 4) {
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask1_ipv4_dscp,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask1_ipv4_proto,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask1_ipv6_flow,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tclas_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (version == 4)
{
proto_tree_add_item(tree, hf_ieee80211_tclas_ipv4_src, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tclas_ipv4_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tclas_src_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tclas_dst_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tclas_dscp, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tclas_protocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
else if (version == 6)
{
proto_tree_add_item(tree, hf_ieee80211_tclas_ipv6_src, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_ieee80211_tclas_ipv6_dst, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_ieee80211_tclas_src_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tclas_dst_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tclas_flow, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
}
break;
case 2:
offset--;
mask_tree = proto_item_add_subtree(class_mask,
ett_tag_tclas_mask_tree);
proto_tree_add_item(mask_tree,
hf_ieee80211_tclas_class_mask2_tci,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tclas_tag_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
default:
break;
}
}
break;
case TAG_SCHEDULE:
if (tag_len != 14)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 14", tag_len);
break;
}
offset += 2;
add_fixed_field(tree, tvb, pinfo, offset, FIELD_SCHEDULE_INFO);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_sched_srv_start, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_sched_srv_int, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_sched_spec_int, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case TAG_CHALLENGE_TEXT:
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_challenge_text, tvb, offset, tag_len, ENC_NA);
break;
case TAG_POWER_CONSTRAINT:
{
if (tag_len != 1)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 1", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_power_constraint_local, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": %d", tvb_get_guint8(tvb, offset));
offset += 1;
break;
}
case TAG_POWER_CAPABILITY:
{
if (tag_len != 2)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 2", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_power_capability_min, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " Min: %d", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_power_capability_max, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ", Max :%d", tvb_get_guint8(tvb, offset));
offset += 1;
break;
}
case TAG_TPC_REQUEST:
{
if (tag_len != 0)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 0", tag_len);
break;
}
offset += 2;
break;
}
case TAG_TPC_REPORT:
{
if (tag_len != 2)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 2", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_tpc_report_trsmt_pow, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " Transmit Power: %d", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_tpc_report_link_mrg, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ", Link Margin: %d", tvb_get_guint8(tvb, offset));
offset += 1;
break;
}
case TAG_SUPPORTED_CHANNELS:
{
proto_item *chan_item;
proto_tree *chan_tree;
guint i = 1;
offset += 2;
if (tag_len % 2 == 1) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag length %u must be even", tag_len);
break;
}
while (offset < tag_end)
{
chan_item = proto_tree_add_item(tree, hf_ieee80211_tag_supported_channels, tvb, offset, 2, ENC_NA);
proto_item_append_text(chan_item, " #%d", i);
i += 1;
chan_tree = proto_item_add_subtree(chan_item , ett_tag_supported_channels);
proto_tree_add_item(chan_tree, hf_ieee80211_tag_supported_channels_first, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(chan_item, " First: %d", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(chan_tree, hf_ieee80211_tag_supported_channels_range, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(chan_item, ", Range: %d ", tvb_get_guint8(tvb, offset));
offset += 1;
}
break;
}
case TAG_CHANNEL_SWITCH_ANN:
{
if (tag_len != 3)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 3", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_csa_channel_switch_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " Mode: %d", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_csa_new_channel_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ", Number: %d ", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_csa_channel_switch_count, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ", Count: %d ", tvb_get_guint8(tvb, offset));
offset += 1;
break;
}
case TAG_MEASURE_REQ:
if (tag_len < 3)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag length %u too short, must be >= 3", tag_len);
break;
}
{
guint8 request_type;
proto_item *parent_item;
proto_tree *sub_tree;
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_measure_request_token, tvb, offset, 1, ENC_NA);
offset += 1;
parent_item = proto_tree_add_item(tree, hf_ieee80211_tag_measure_request_mode, tvb, offset, 1, ENC_NA);
sub_tree = proto_item_add_subtree(parent_item, ett_tag_measure_request_mode_tree);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_mode_parallel, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_mode_enable, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_mode_request, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_mode_report, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_mode_duration_mandatory, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_mode_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
parent_item = proto_tree_add_item(tree, hf_ieee80211_tag_measure_request_type, tvb, offset, 1, ENC_NA);
sub_tree = proto_item_add_subtree(parent_item, ett_tag_measure_request_type_tree);
request_type = tvb_get_guint8 (tvb, offset);
offset += 1;
switch (request_type) {
case 0:
case 1:
case 2:
{
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_start_time, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
}
case 3:
{
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_operating_class, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_randomization_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
while (offset < tag_end)
{
guint8 sub_id;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_channel_load_sub_id, tvb, offset, 1, ENC_NA);
sub_id = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_subelement_length, tvb, offset, 1, ENC_NA);
offset += 1;
switch (sub_id) {
case MEASURE_REQ_CHANNEL_LOAD_SUB_REPORTING_INFO:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_channel_load_sub_reporting_condition, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_channel_load_sub_reporting_ref, tvb, offset, 1, ENC_NA);
offset += 1;
break;
default:
break;
}
}
break;
}
case 4:
{
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_operating_class, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_randomization_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
while (offset < tag_end)
{
guint8 sub_id;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_noise_histogram_sub_id, tvb, offset, 1, ENC_NA);
sub_id = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_subelement_length, tvb, offset, 1, ENC_NA);
offset += 1;
switch (sub_id) {
case MEASURE_REQ_NOISE_HISTOGRAM_SUB_REPORTING_INFO:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_noise_histogram_sub_reporting_condition, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_noise_histogram_sub_reporting_anpi_ref, tvb, offset, 1, ENC_NA);
offset += 1;
break;
default:
break;
}
}
break;
}
case 5:
{
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_operating_class, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_randomization_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_measurement_mode, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_bssid, tvb, offset, 6, ENC_NA);
offset += 6;
while (offset < tag_end)
{
guint8 sub_id, sub_length, sub_tag_end;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_id, tvb, offset, 1, ENC_NA);
sub_id = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_subelement_length, tvb, offset, 1, ENC_NA);
sub_length = tvb_get_guint8(tvb, offset);
offset += 1;
sub_tag_end = offset + sub_length;
switch (sub_id) {
case MEASURE_REQ_BEACON_SUB_SSID:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_ssid, tvb, offset, sub_length, ENC_ASCII|ENC_NA);
offset += sub_length;
break;
case MEASURE_REQ_BEACON_SUB_BRI:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_bri_reporting_condition, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_bri_threshold_offset, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case MEASURE_REQ_BEACON_SUB_RD:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_reporting_detail, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case MEASURE_REQ_BEACON_SUB_REQUEST:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case MEASURE_REQ_BEACON_SUB_APCP:
break;
default:
break;
}
if (offset < sub_tag_end)
{
proto_item *tix;
tix = proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_unknown, tvb, offset, sub_tag_end - offset, ENC_NA);
expert_add_info(pinfo, tix, &ei_ieee80211_tag_measure_request_beacon_unknown);
offset = sub_tag_end;
}
}
break;
}
case 6:
{
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_operating_class, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_randomization_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_frame_request_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_mac_address, tvb, offset, 6, ENC_NA);
offset += 6;
break;
}
case 7:
{
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_peer_mac_address, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_randomization_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_group_id, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
case 8:
case 9:
case 10:
case 11:
case 12:
case 13:
case 14:
case 15:
case 255:
default:
break;
}
if (offset < tag_end)
{
proto_item *tix;
tix = proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_unknown, tvb, offset, tag_end - offset, ENC_NA);
expert_add_info(pinfo, tix, &ei_ieee80211_tag_measure_request_unknown);
}
}
break;
case TAG_MEASURE_REP:
if (tag_len < 3)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag length %u too short, must be >= 3", tag_len);
break;
}
{
proto_item *parent_item;
proto_tree *sub_tree;
guint8 report_type;
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_measure_report_measurement_token, tvb, offset, 1, ENC_NA);
offset += 1;
parent_item = proto_tree_add_item(tree, hf_ieee80211_tag_measure_report_mode, tvb, offset, 1, ENC_NA);
sub_tree = proto_item_add_subtree(parent_item, ett_tag_measure_report_mode_tree);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_mode_late, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_mode_incapable, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_mode_refused, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_mode_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
report_type = tvb_get_guint8(tvb, offset);
parent_item = proto_tree_add_item(tree, hf_ieee80211_tag_measure_report_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
sub_tree = proto_item_add_subtree(parent_item, ett_tag_measure_report_type_tree);
offset += 1;
if (tag_len == 3)
break;
switch (report_type) {
case 0:
{
proto_tree *sub_tree_map_field;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_start_time, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
parent_item = proto_tree_add_item(tree, hf_ieee80211_tag_measure_basic_map_field, tvb, offset, 1, ENC_NA);
sub_tree_map_field = proto_item_add_subtree(parent_item, ett_tag_measure_report_basic_map_tree);
proto_tree_add_item(sub_tree_map_field, hf_ieee80211_tag_measure_map_field_bss, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree_map_field, hf_ieee80211_tag_measure_map_field_odfm, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree_map_field, hf_ieee80211_tag_measure_map_field_unident_signal, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree_map_field, hf_ieee80211_tag_measure_map_field_radar, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree_map_field, hf_ieee80211_tag_measure_map_field_unmeasured, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree_map_field, hf_ieee80211_tag_measure_map_field_reserved, tvb, offset, 1, ENC_NA);
break;
}
case 1:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_start_time, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_cca_busy_fraction, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 2:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_start_time, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
parent_item = proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_rpi_histogram_report, tvb, offset, 8, ENC_NA);
sub_tree = proto_item_add_subtree(parent_item, ett_tag_measure_report_rpi_tree);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_rpi_histogram_report_0, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_rpi_histogram_report_1, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_rpi_histogram_report_2, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_rpi_histogram_report_3, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_rpi_histogram_report_4, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_rpi_histogram_report_5, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_rpi_histogram_report_6, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_rpi_histogram_report_7, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 3:
{
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_operating_class, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_start_time, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_channel_load, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
case 4:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_operating_class, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_start_time, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ant_id, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_anpi, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_0, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_1, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_2, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_3, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_4, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_5, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_6, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_7, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_8, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_9, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ipi_density_10, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 5:
{
proto_tree *sub_tree_frame_info;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_operating_class, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_start_time, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
parent_item = proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_frame_info, tvb, offset, 1, ENC_NA);
sub_tree_frame_info = proto_item_add_subtree(parent_item, ett_tag_measure_report_frame_tree);
proto_tree_add_item(sub_tree_frame_info, hf_ieee80211_tag_measure_report_frame_info_phy_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree_frame_info, hf_ieee80211_tag_measure_report_frame_info_frame_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_rcpi, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_rsni, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_bssid, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_ant_id, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_parent_tsf, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
while (offset < tag_end)
{
guint8 sub_id, sub_length;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_beacon_sub_id, tvb, offset, 1, ENC_NA);
sub_id = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_subelement_length, tvb, offset, 1, ENC_NA);
sub_length = tvb_get_guint8(tvb, offset);
offset += 1;
switch (sub_id) {
case MEASURE_REP_REPORTED_FRAME_BODY:
{
proto_tree *rep_tree;
rep_tree = proto_tree_add_subtree(sub_tree, tvb, offset, sub_length, ett_tag_measure_reported_frame_tree, NULL, "Reported Frame Body");
add_fixed_field(rep_tree, tvb, pinfo, 0, FIELD_TIMESTAMP);
add_fixed_field(rep_tree, tvb, pinfo, 8, FIELD_BEACON_INTERVAL);
add_fixed_field(rep_tree, tvb, pinfo, 10, FIELD_CAP_INFO);
offset += 12;
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, rep_tree, sub_length - 12, MGT_PROBE_RESP);
offset += (sub_length - 12);
}
break;
default:
break;
}
}
break;
}
case 6:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_operating_class, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_start_time, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 7:
case 8:
case 9:
case 10:
case 11:
case 12:
case 13:
case 14:
case 15:
default:
break;
}
if (offset < tag_end)
{
proto_item *tix;
tix = proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_unknown, tvb, offset, tag_end - offset, ENC_NA);
expert_add_info(pinfo, tix, &ei_ieee80211_tag_measure_report_unknown);
}
}
break;
case TAG_QUIET:
if (tag_len != 6)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 6", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_quiet_count, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti, " Count: %d", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_quiet_period, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti, " Period: %d", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_quiet_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " Duration: %d", tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_quiet_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " Offset: %d", tvb_get_letohs(tvb, offset));
offset += 2;
break;
case TAG_IBSS_DFS:
if (tag_len < 7)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be >= 7", tag_len);
break;
}
{
proto_item *ti_sup_map;
proto_tree *sub_map_tree;
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_dfs_owner, tvb, offset, 6, ENC_NA);
proto_item_append_text(ti, " Owner: %s", tvb_ether_to_str(tvb, offset));
offset += 6;
proto_tree_add_item(tree, hf_ieee80211_tag_dfs_recovery_interval, tvb, offset, 1, ENC_NA);
offset += 1;
while (offset < tag_end)
{
ti_sup_map = proto_tree_add_item(tree, hf_ieee80211_tag_dfs_channel_map, tvb, offset, 2, ENC_NA);
sub_map_tree = proto_item_add_subtree(ti_sup_map, ett_tag_dfs_map_tree);
proto_tree_add_item(sub_map_tree, hf_ieee80211_tag_dfs_channel_number, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_map_tree, hf_ieee80211_tag_dfs_map, tvb, offset, 1, ENC_NA);
offset += 2;
}
break;
}
case TAG_ERP_INFO:
case TAG_ERP_INFO_OLD:
if (tag_len != 1)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 1", tag_len);
break;
}
{
proto_item *ti_erp;
proto_tree *erp_tree;
offset += 2;
ti_erp = proto_tree_add_item(tree, hf_ieee80211_tag_erp_info, tvb, offset, 1, ENC_NA);
erp_tree = proto_item_add_subtree(ti_erp, ett_tag_erp_info_tree);
proto_tree_add_item(erp_tree, hf_ieee80211_tag_erp_info_erp_present, tvb, offset, 1, ENC_NA);
proto_tree_add_item(erp_tree, hf_ieee80211_tag_erp_info_use_protection, tvb, offset, 1, ENC_NA);
proto_tree_add_item(erp_tree, hf_ieee80211_tag_erp_info_barker_preamble_mode, tvb, offset, 1, ENC_NA);
proto_tree_add_item(erp_tree, hf_ieee80211_tag_erp_info_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
case TAG_TS_DELAY:
if (tag_len != 4)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 4", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_ts_delay, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " : %d", tvb_get_ntohl(tvb, offset));
offset += 4;
break;
case TAG_TCLAS_PROCESS:
if (tag_len != 1)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 1", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tclas_process, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " : %s", val_to_str(tvb_get_guint8(tvb, offset), ieee80211_tclas_process_flag, "Unknown %d"));
offset += 1;
break;
case TAG_QOS_CAPABILITY:
if (tag_len != 1)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 1", tag_len);
break;
}
{
offset += 2;
offset = dissect_qos_capability(tree, tvb, pinfo, offset, ftype);
}
break;
case TAG_RSN_IE:
if (tag_len < 18)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be >= 18", tag_len);
break;
}
offset += 2;
offset = dissect_rsn_ie(pinfo, tree, tvb, offset, tag_len);
break;
case TAG_EXT_SUPP_RATES:
if (tag_len < 1)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag length %u too short, must be greater than 0", tag_len);
break;
}
offset += 2;
while (offset < tag_end)
{
proto_tree_add_item(tree, hf_ieee80211_tag_ext_supp_rates, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti, " %s,", val_to_str_ext_const(tvb_get_guint8(tvb, offset), &ieee80211_supported_rates_vals_ext, "Unknown Rate"));
offset += 1;
}
proto_item_append_text(ti, " [Mbit/sec]");
break;
case TAG_EXTENDED_CAPABILITIES:
dissect_extended_capabilities_ie(pinfo, tree, ti, ti_len, tag_len, tvb, offset+2, tag_end);
break;
case TAG_CISCO_CCX1_CKIP:
if (tag_len < 26)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u too short, must be >= 26", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_cisco_ccx1_unknown, tvb, offset, 10, ENC_NA);
offset += 10;
proto_tree_add_item(tree, hf_ieee80211_tag_cisco_ccx1_name, tvb, offset, 16, ENC_ASCII|ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_ieee80211_tag_cisco_ccx1_clients, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_cisco_ccx1_unknown2, tvb, offset, 3, ENC_NA);
offset += 3;
break;
case TAG_VHT_CAPABILITY:
dissect_vht_capability_ie(tvb, pinfo, tree, offset+2, tag_len, ti_len);
break;
case TAG_VHT_OPERATION:
dissect_vht_operation_ie(tvb, pinfo, tree, offset+2, tag_len, ti_len);
break;
case TAG_EXT_BSS_LOAD:
dissect_ext_bss_load(tree, tvb, offset+2);
break;
case TAG_WIDE_BW_CHANNEL_SWITCH:
dissect_wide_bw_channel_switch(tree, tvb, offset+2);
break;
case TAG_VHT_TX_PWR_ENVELOPE:
dissect_vht_tx_pwr_envelope(tvb, pinfo, tree, offset+2, tag_len, ti_len);
break;
case TAG_CHANNEL_SWITCH_WRAPPER:
dissect_channel_switch_wrapper(pinfo, tree, tvb, offset + 2, tag_len);
break;
case TAG_OPERATING_MODE_NOTIFICATION:
dissect_operating_mode_notification(tree, tvb, offset + 2);
break;
case TAG_VENDOR_SPECIFIC_IE:
case TAG_CISCO_VENDOR_SPECIFIC:
case TAG_SYMBOL_PROPRIETARY:
if (tag_len < 3)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be >= 3", tag_len);
break;
}
{
guint32 tag_vs_len = tag_len;
offset += 2;
oui = tvb_get_ntoh24(tvb, offset);
tag_tvb = tvb_new_subset_length(tvb, offset, tag_len);
proto_tree_add_item(tree, hf_ieee80211_tag_oui, tvb, offset, 3, ENC_NA);
proto_item_append_text(ti, ": %s", uint_get_manuf_name(oui));
offset += 3;
tag_vs_len -= 3;
if (tag_len > 0) {
proto_tree_add_item(ti, hf_ieee80211_tag_vendor_oui_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
switch (oui) {
case OUI_WPAWME:
offset = dissect_vendor_ie_wpawme(tree, tvb, pinfo, offset, tag_vs_len, ftype);
break;
case OUI_RSN:
dissect_vendor_ie_rsn(ti, tree, tvb, offset, tag_vs_len);
break;
case OUI_PRE11N:
dissect_vendor_ie_ht(tvb, pinfo, tree, offset, ti, ti_len, tag_vs_len);
break;
case OUI_WFA:
dissect_vendor_ie_wfa(pinfo, ti, tag_tvb);
break;
case OUI_CISCOWL:
dissect_vendor_ie_aironet(ti, tree, tvb, offset, tag_vs_len);
break;
case OUI_MARVELL:
dissect_vendor_ie_marvell(ti, tree, tvb, offset, tag_vs_len);
break;
case OUI_ATHEROS:
dissect_vendor_ie_atheros(ti, tree, tvb, offset, tag_vs_len, pinfo, ti_len);
break;
case OUI_ARUBA:
dissect_vendor_ie_aruba(ti, tree, tvb, offset, tag_vs_len);
break;
case OUI_NINTENDO:
dissect_vendor_ie_nintendo(ti, tree, tvb, offset, tag_vs_len);
break;
default:
proto_tree_add_item(tree, hf_ieee80211_tag_vendor_data, tvb, offset, tag_vs_len, ENC_NA);
break;
}
}
break;
case TAG_MOBILITY_DOMAIN:
dissect_mobility_domain(tree, tvb, offset + 2, tag_len);
break;
case TAG_FAST_BSS_TRANSITION:
dissect_fast_bss_transition(tree, tvb, offset + 2, tag_len);
break;
case TAG_MMIE:
dissect_mmie(tree, tvb, offset + 2, tag_len);
break;
case TAG_SSID_LIST:
dissect_ssid_list(tree, tvb, offset + 2, tag_len);
break;
case TAG_TIME_ZONE:
dissect_time_zone(tree, tvb, offset + 2, tag_len);
break;
case TAG_TIMEOUT_INTERVAL:
dissect_timeout_interval(tree, tvb, pinfo, offset + 2, tag_len);
break;
case TAG_RIC_DATA:
tag_len = dissect_ric_data(pinfo, tree, tvb, offset + 2, tag_len, ti, ti_len, ftype);
break;
case TAG_LINK_IDENTIFIER:
dissect_link_identifier(tree, tvb, offset + 2, tag_len);
break;
case TAG_WAKEUP_SCHEDULE:
dissect_wakeup_schedule(tree, tvb, offset + 2, tag_len);
break;
case TAG_CHANNEL_SWITCH_TIMING:
dissect_channel_switch_timing(tree, tvb, offset + 2, tag_len);
break;
case TAG_PTI_CONTROL:
dissect_pti_control(tree, tvb, offset + 2, tag_len);
break;
case TAG_PU_BUFFER_STATUS:
dissect_pu_buffer_status(tree, tvb, offset + 2, tag_len);
break;
case TAG_HT_CAPABILITY:
dissect_ht_capability_ie(tvb, pinfo, tree, offset+2, tag_len, ti_len, FALSE);
break;
case TAG_HT_INFO:
dissect_ht_info_ie_1_1(tvb, pinfo, tree, offset + 2, tag_len, ti_len);
break;
case TAG_SECONDARY_CHANNEL_OFFSET:
dissect_secondary_channel_offset_ie(tvb, pinfo, tree, offset + 2, tag_len, ti_len);
break;
case TAG_BSS_AVG_ACCESS_DELAY:
dissect_bss_avg_access_delay_ie(tvb, pinfo, tree, offset + 2, tag_len, ti_len);
break;
case TAG_ANTENNA:
dissect_antenna_ie(tvb, pinfo, tree, offset + 2, tag_len, ti_len);
break;
case TAG_RSNI:
dissect_rsni_ie(tvb, pinfo, tree, offset + 2, tag_len, ti_len);
break;
case TAG_BSS_AVB_ADM_CAPACITY:
dissect_bss_available_admission_capacity_ie(tvb, pinfo, tree, offset + 2, tag_len, ti_len);
break;
case TAG_IE_68_CONFLICT:
if (tag_len >= 20) {
dissect_wapi_param_set(tvb, pinfo, tree, offset + 2,tag_len, ti_len, ti, ftype);
}
else {
dissect_bss_ac_access_delay_ie(tvb, pinfo, tree, offset + 2, tag_len, ti_len);
}
break;
case TAG_BSS_MAX_IDLE_PERIOD:
dissect_bss_max_idle_period(tree, tvb, offset + 2);
break;
case TAG_TFS_REQUEST:
dissect_tfs_request(pinfo, tree, tvb, offset + 2, tag_len, ftype);
break;
case TAG_TFS_RESPONSE:
dissect_tfs_response(pinfo, tree, tvb, offset + 2, tag_len, ftype);
break;
case TAG_WNM_SLEEP_MODE:
dissect_wnm_sleep_mode(tree, tvb, offset + 2);
break;
case TAG_TIME_ADV:
dissect_time_adv(tree, tvb, offset + 2);
break;
case TAG_RM_ENABLED_CAPABILITY:
dissect_rm_enabled_capabilities_ie(pinfo, tree, ti, ti_len, tag_len, tvb, offset+2, tag_end);
break;
case TAG_RIC_DESCRIPTOR:
dissect_ric_descriptor(pinfo, tree, tvb, offset + 2, tag_len, ti, ti_len);
break;
case TAG_MESH_PEERING_MGMT:
{
guint start = offset + 2;
offset += 2;
proto_tree_add_item (tree, hf_ieee80211_mesh_peering_proto, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item (tree, hf_ieee80211_mesh_peering_local_link_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
switch (tvb_get_guint8(tvb, 1))
{
case SELFPROT_ACTION_MESH_PEERING_OPEN:
break;
case SELFPROT_ACTION_MESH_PEERING_CONFIRM:
proto_tree_add_item (tree, hf_ieee80211_mesh_peering_peer_link_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case SELFPROT_ACTION_MESH_PEERING_CLOSE:
if ((tag_len == 8) || (tag_len == 24))
{
proto_tree_add_item (tree, hf_ieee80211_mesh_peering_peer_link_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_REASON_CODE);
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_ieee80211_mesh_peering_unexpected , tvb, offset, tag_len);
offset += tag_len;
break;
}
if (tag_len - (offset - start) == 16)
{
proto_tree_add_item(tree, hf_ieee80211_rsn_pmkid, tvb, offset, 16, ENC_NA);
offset += 16;
}
break;
}
case TAG_MESH_CONFIGURATION:
{
proto_item *item;
proto_tree *subtree;
offset += 2;
proto_tree_add_item (tree, hf_ieee80211_mesh_config_path_sel_protocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_ieee80211_mesh_config_path_sel_metric, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_ieee80211_mesh_config_congestion_control, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_ieee80211_mesh_config_sync_method, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_ieee80211_mesh_config_auth_protocol, tvb, offset + 4, 1, ENC_LITTLE_ENDIAN);
item = proto_tree_add_item (tree, hf_ieee80211_mesh_config_formation_info, tvb, offset + 5, 1, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_mesh_formation_info_tree);
proto_tree_add_item (subtree, hf_ieee80211_mesh_form_info_num_of_peerings, tvb, offset + 5, 1, ENC_LITTLE_ENDIAN);
item = proto_tree_add_item (tree, hf_ieee80211_mesh_config_capability, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_mesh_config_cap_tree);
proto_tree_add_item (subtree, hf_ieee80211_mesh_config_cap_accepting, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (subtree, hf_ieee80211_mesh_config_cap_mcca_support, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (subtree, hf_ieee80211_mesh_config_cap_mcca_enabled, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (subtree, hf_ieee80211_mesh_config_cap_forwarding, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (subtree, hf_ieee80211_mesh_config_cap_mbca_enabled, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (subtree, hf_ieee80211_mesh_config_cap_tbtt_adjusting, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (subtree, hf_ieee80211_mesh_config_cap_power_save_level, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
break;
}
case TAG_MESH_ID:
{
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_mesh_id, tvb, offset, tag_len, ENC_ASCII|ENC_NA);
if (tag_len > 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", MESHID=%s", format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tag_len, ENC_ASCII), tag_len));
proto_item_append_text(ti, ": %s", format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tag_len, ENC_ASCII), tag_len));
}
break;
}
case TAG_MESH_PREQ:
{
guint8 flags = tvb_get_guint8(tvb, offset + 2);
guint8 targs, i;
offset += 2;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_hopcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_ttl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_pdid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_orig_sta, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_orig_sn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (flags & (1<<6)) {
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_orig_ext, tvb, offset, 6, ENC_NA);
offset += 6;
}
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_lifetime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_metric, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_count, tvb, offset, 1, ENC_LITTLE_ENDIAN);
targs = tvb_get_guint8 (tvb, offset);
offset += 1;
for (i = 0; i < targs; i++) {
const int * targ_flags[] = {
&hf_ieee80211_ff_hwmp_targ_to_flags,
&hf_ieee80211_ff_hwmp_targ_usn_flags,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_ieee80211_ff_hwmp_targ_flags,
ett_hwmp_targ_flags_tree, targ_flags, ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_sta, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_sn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
break;
}
case TAG_MESH_PREP:
{
guint8 flags = tvb_get_guint8(tvb, offset + 2);
offset += 2;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_hopcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_ttl, tvb, offset , 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_sta, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_sn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (flags & (1<<6)) {
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_ext, tvb, offset, 6, ENC_NA);
offset += 6;
}
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_lifetime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_metric, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_orig_sta, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_orig_sn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
}
case TAG_MESH_PERR:
{
guint8 targs, i;
offset += 2;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_ttl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_count, tvb, offset, 1, ENC_LITTLE_ENDIAN);
targs = tvb_get_guint8 (tvb, offset);
offset += 1;
for (i = 0; i < targs; i++) {
guint8 flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_sta, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_sn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (flags & (1<<6)) {
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_ext, tvb, offset, 6, ENC_NA);
offset += 6;
}
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_REASON_CODE);
}
break;
}
case TAG_RANN:
{
offset += 2;
proto_tree_add_item (tree, hf_ieee80211_rann_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_hopcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_ttl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_rann_root_sta, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item (tree, hf_ieee80211_rann_sn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_rann_interval, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_metric, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
}
case TAG_MESH_CHANNEL_SWITCH:
{
proto_item *item;
proto_tree *subtree;
if (tag_len != 6)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 6", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_mesh_channel_switch_ttl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " TTL: %d", tvb_get_guint8(tvb, offset));
offset += 1;
item = proto_tree_add_item(tree, hf_ieee80211_mesh_channel_switch_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_mesh_chswitch_flag_tree);
proto_tree_add_item(subtree, hf_ieee80211_mesh_chswitch_flag_initiator, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_ieee80211_mesh_chswitch_flag_txrestrict, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_mesh_channel_switch_reason_code, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_mesh_channel_switch_precedence_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
}
case TAG_INTERWORKING:
dissect_interworking(pinfo, tree, ti, tvb, offset);
break;
case TAG_ADVERTISEMENT_PROTOCOL:
{
dissect_advertisement_protocol(pinfo, tree, tvb, offset, NULL);
break;
}
case TAG_QOS_MAP_SET:
dissect_qos_map_set(pinfo, tree, ti, tvb, offset);
break;
case TAG_ROAMING_CONSORTIUM:
dissect_roaming_consortium(pinfo, tree, ti, tvb, offset);
break;
case TAG_AP_CHANNEL_REPORT:
dissect_ap_channel_report(tvb, pinfo, tree, offset + 2, tag_len, ti_len, tag_end, ti);
break;
case TAG_NEIGHBOR_REPORT:
dissect_neighbor_report(tvb, pinfo, tree, offset + 2, tag_len, ti_len, tag_end, ti);
break;
case TAG_EXTENDED_CHANNEL_SWITCH_ANNOUNCEMENT:
{
if (tag_len != 4)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 4", tag_len);
break;
}
offset += 2;
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_EXTENDED_CHANNEL_SWITCH_ANNOUNCEMENT);
break;
}
case TAG_SUPPORTED_OPERATING_CLASSES:
{
guint i;
if (tag_len < 2) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be >= 3", tag_len);
break;
} else if (tag_len > 32) {
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be < 32", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_supported_ope_classes_current, tvb, offset, 1, ENC_NA);
offset += 1;
tag_data_ptr = tvb_get_ptr (tvb, offset, tag_len);
for (i = 0, n = 0; (i < tag_len) && (n < SHORT_STR); i++) {
ret = g_snprintf (print_buff + n, SHORT_STR - n, (i == tag_len-1)?"%d":"%d, ", tag_data_ptr[i]);
if (ret >= SHORT_STR - n) {
break;
}
n += ret;
}
proto_tree_add_string (tree, hf_ieee80211_tag_supported_ope_classes_alternate, tvb, offset, tag_len, print_buff);
break;
}
case TAG_RELAY_CAPABILITIES:
{
add_tag_relay_capabilities(pinfo, ti_len, tag_len, tree, tvb, &offset);
break;
}
case TAG_DMG_BSS_PRAMTER_CHANGE:
{
gboolean size;
if (tag_len != 7)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 7", tag_len);
break;
}
offset += 2;
size = (tvb_get_guint8(tvb, offset) & 0x02) >> 1;
proto_tree_add_item(tree, hf_ieee80211_tag_move, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_size, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_tbtt_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if(size == TRUE) {
proto_tree_add_item(tree, hf_ieee80211_tag_bi_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
break;
}
case TAG_DMG_CAPABILITIES:
{
if (tag_len != 17)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 17", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_dmg_capa_sta_addr, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_ieee80211_tag_dmg_capa_aid, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_reverse_direction, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_hlts, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tpc, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_spsh, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_rx_antenna, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_fast_link, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_num_sectors, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_rxss_length, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_reciprocity, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_max_ampdu_exp, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_ieee80211_tag_min_mpdu_sapcing, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_ba_flow_control, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_max_sc_rx_mcs, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_max_ofdm_rx_mcs, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_max_sc_tx_mcs, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_max_ofdm_tx_mcs, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_ieee80211_tag_low_power_supported, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_code_rate, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_dtp, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_appdu_supp, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_heartbeat, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_other_aid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pattern_recip, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_heartbeat_elapsed, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_grant_ack_supp, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_RXSSTxRate_supp, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_tddti, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_PSA, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_handover, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_max_assoc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_power_src, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_decenter, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_forwarding, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_center, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
}
case TAG_DMG_OPERATION:
{
if (tag_len != 10)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 10", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_tddti, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_PSA, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_pcp_handover, tvb, offset, 1, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_PSRSI, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_min_BHI_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_brdct_sta_info_dur, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_assoc_resp_confirm_time, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_min_pp_duration, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_SP_idle_timeout, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_max_lost_beacons, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
case TAG_ANTENNA_SECTOR_ID:
{
if (tag_len != 4)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 4", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tap1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_state1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tap2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_state2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
}
case TAG_EXTENDED_SCHEDULE:
{
guint32 i = 0;
gboolean isGrant;
proto_tree * alloc_tree;
if ((tag_len%15) != 0)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be N*15 where 0<=N<=17", tag_len);
break;
}
offset += 2;
isGrant = ((ftype==CTRL_GRANT)||(ftype==CTRL_GRANT_ACK));
p_add_proto_data(wmem_file_scope(), pinfo, proto_wlan, IS_CTRL_GRANT_OR_GRANT_ACK_KEY, &isGrant);
for(i=0; i < tag_len; i+=15) {
alloc_tree = proto_tree_add_subtree_format(tree, tvb, offset, 15, ett_allocation_tree, NULL, "Allocation %d", i/15);
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_allocation_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_allocation_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_pseudo_static, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_truncatable, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_extendable, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_pcp_active, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_lp_sc_used, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset += add_fixed_field(alloc_tree, tvb, pinfo, offset, FIELD_BEAMFORMING_CTRL);
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_src_aid, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_dest_aid, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_alloc_start, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_alloc_block_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_num_blocks, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(alloc_tree, hf_ieee80211_tag_alloc_block_period, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
}
case TAG_STA_AVAILABILITY:
{
guint32 i = 0;
proto_tree * sta_info_tree;
if ((tag_len%2) != 0)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be N*2 where N>=0", tag_len);
break;
}
offset += 2;
for(i=0; i < tag_len; i+=2) {
sta_info_tree = proto_tree_add_subtree_format(tree, tvb, offset, 2, ett_sta_info, NULL, "STA Info %d", i/2);
proto_tree_add_item(sta_info_tree, hf_ieee80211_tag_aid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sta_info_tree, hf_ieee80211_tag_cbap, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sta_info_tree, hf_ieee80211_tag_pp_avail, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
}
case TAG_NEXT_DMG_ATI:
{
if (tag_len != 6)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be = 6", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_next_ati_start_time, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tag_next_ati_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
}
case TAG_NEXTPCP_LIST:
{
guint32 i = 0;
if (tag_len < 1)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be at least 1", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_nextpcp_token, tvb, offset, 1, ENC_NA);
offset += 1;
for(i=0; i < tag_len-1; i+=1) {
proto_tree_add_item(tree, hf_ieee80211_tag_nextpcp_list, tvb, offset, 1, ENC_NA);
offset += 1;
}
break;
}
case TAG_PCP_HANDOVER:
{
if (tag_len != 13)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be 13", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_old_bssid, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_ieee80211_tag_new_pcp_addr, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_ieee80211_tag_reamaining_BI, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
case TAG_BEAMLINK_MAINTAINCE:
{
if (tag_len != 1)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be 1", tag_len);
break;
}
offset += 2;
offset += add_ff_beamformed_link(tree, tvb, pinfo, offset);
break;
}
case TAG_QUIET_PERIOD_RES:
{
if (tag_len != 10)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be 10", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_request_token, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_bssid, tvb, offset, 6, ENC_NA);
offset += 6;
offset += add_ff_sta_address(tree, tvb, pinfo, offset);
break;
}
case TAG_RELAY_TRANSFER_PARAM:
{
if (tag_len != 8)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be 8", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_duplex_relay, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_cooperation_relay, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_tx_mode, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_link_change_interval, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_data_sensing_time, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_first_period, tvb, offset+3, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_second_period, tvb, offset+5, 2, ENC_LITTLE_ENDIAN);
offset += 8;
break;
}
case TAG_DMG_BEAM_REFINEMENT:
{
if (tag_len != 5)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be 5", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_initiator, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tx_train_res, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_rx_train_res, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tx_trn_ok, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_txss_fbck_req, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_bs_fbck, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_bs_fbck_antenna_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_snr_requested, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_channel_measurement_requested, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_number_of_taps_requested, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_sector_id_order_req, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_snr_present, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_channel_measurement_present, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tap_delay_present, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_number_of_taps_present, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_number_of_measurement, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_sector_id_order_present, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_number_of_beams, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_mid_extension, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_capability_request, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
}
case TAG_WAKEUP_SCHEDULE_AD:
{
if (tag_len != 8)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be 8", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_bi_start_time, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tag_sleep_cycle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_num_awake_bis, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
}
case TAG_DMG_TSPEC:
{
gboolean isGrant;
int num_constraints;
if (tag_len < 14)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be at least 14", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_allocation_id, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_allocation_type, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_allocation_format, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_pseudo_static, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_truncatable, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_extendable, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_lp_sc_used, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_up, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_dest_aid, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
isGrant = ((ftype==CTRL_GRANT)||(ftype==CTRL_GRANT_ACK));
p_add_proto_data(wmem_file_scope(), pinfo, proto_wlan, IS_CTRL_GRANT_OR_GRANT_ACK_KEY, &isGrant);
offset += add_fixed_field(tree, tvb, pinfo, 2, FIELD_BEAMFORMING_CTRL);
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_allocation_period, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_min_allocation, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_max_allocation, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_min_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
num_constraints = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_num_of_constraints, tvb, offset, 1, ENC_NA);
offset += 1;
while(num_constraints > 0) {
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_tsconst_start_time, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_tsconst_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_tsconst_period, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_tspec_tsconst_interferer_mac, tvb, offset, 2, ENC_NA);
offset += 6;
num_constraints--;
}
break;
}
case TAG_CHANNEL_MEASURMENT_FB:
{
int num_measurement;
if (tag_len%5 != 0)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be multiple of 5", tag_len);
break;
}
num_measurement = tvb_get_guint8(tvb, offset+1);
offset += 2;
while(num_measurement > 0) {
proto_tree_add_item(tree, hf_ieee80211_ff_snr, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_channel_measurement_feedback_realtive_I, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_channel_measurement_feedback_realtive_Q, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_channel_measurement_feedback_tap_delay, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_channel_measurement_feedback_sector_id, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_channel_measurement_feedback_antenna_id, tvb, offset, 1, ENC_NA);
offset += 1;
num_measurement--;
}
break;
}
case TAG_AWAKE_WINDOW:
{
if (tag_len != 2)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be 2", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_awake_window, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
}
case TAG_ADDBA_EXT:
{
if (tag_len != 1)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be 1", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_addba_ext_no_frag, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
case TAG_MULTI_BAND:
{
gboolean chiper_present, addr_present;
if (tag_len < 22)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be at least 22", tag_len);
break;
}
offset += 2;
chiper_present = (tvb_get_letohs(tvb, offset) & 0x08) >> 3;
addr_present = (tvb_get_letohs(tvb, offset) & 0x10) >> 4;
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_ctrl_sta_role, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_ctrl_addr_present, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_ctrl_cipher_present, tvb, offset, 1, ENC_NA);
offset += 1;
offset += add_fixed_field(tree, tvb, pinfo, 1, FIELD_BAND_ID);
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_oper_class, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_bssid, tvb, offset, 6, ENC_NA);
offset += 6;
offset += add_fixed_field(tree, tvb, pinfo, 2, FIELD_BEACON_INTERVAL);
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_tsf_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_conn_ap, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_conn_pcp, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_conn_dls, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_conn_tdls, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_conn_ibss, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_fst_timeout, tvb, offset, 1, ENC_NA);
offset += 1;
if(addr_present)
{
proto_tree_add_item(tree, hf_ieee80211_tag_multi_band_sta_mac, tvb, offset, 6, ENC_NA);
offset += 6;
}
if(chiper_present)
{
proto_item *rsn_pcs_count, *rsn_pcs_item, *rsn_sub_pcs_item;
proto_tree *rsn_pcs_tree, *rsn_sub_pcs_tree;
gint ii;
guint16 pcs_count;
rsn_pcs_count = proto_tree_add_item(tree, hf_ieee80211_rsn_pcs_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
pcs_count = tvb_get_letohs(tvb, offset);
offset += 2;
if (offset + (pcs_count * 4) > tag_end)
{
expert_add_info_format(pinfo, rsn_pcs_count, &ei_ieee80211_rsn_pcs_count,
"Pairwise Cipher Suite Count too large, 4*%u > %d", pcs_count, tag_end - offset);
pcs_count = (tag_end - offset) / 4;
}
rsn_pcs_item = proto_tree_add_item(tree, hf_ieee80211_rsn_pcs_list, tvb, offset, pcs_count * 4, ENC_NA);
rsn_pcs_tree = proto_item_add_subtree(rsn_pcs_item, ett_rsn_pcs_tree);
for (ii = 0; ii < pcs_count; ii++)
{
rsn_sub_pcs_item = proto_tree_add_item(rsn_pcs_tree, hf_ieee80211_rsn_pcs, tvb, offset, 4, ENC_BIG_ENDIAN);
rsn_sub_pcs_tree = proto_item_add_subtree(rsn_sub_pcs_item, ett_rsn_sub_pcs_tree);
proto_tree_add_item(rsn_sub_pcs_tree, hf_ieee80211_rsn_pcs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if (tvb_get_ntoh24(tvb, offset) == OUI_RSN)
{
proto_tree_add_item(rsn_sub_pcs_tree, hf_ieee80211_rsn_pcs_80211_type, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(rsn_pcs_item, " %s", rsn_pcs_return(tvb_get_ntohl(tvb, offset)));
} else {
proto_tree_add_item(rsn_sub_pcs_tree, hf_ieee80211_rsn_pcs_type, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
}
offset += 4;
}
}
break;
}
case TAG_DMG_LINK_MARGIN:
{
if (tag_len != 8)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be 8", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_activity, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_dmg_link_adapt_mcs, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_dmg_link_adapt_link_margin, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_ff_snr, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_ref_timestamp, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 4;
break;
}
case TAG_DMG_LINK_ADAPTION_ACK:
{
if (tag_len != 5)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be 5", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_activity, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_ref_timestamp, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 4;
break;
}
case TAG_SWITCHING_STREAM:
{
int param_num;
if (tag_len < 4)
{
expert_add_info_format(pinfo, ti_len, &ei_ieee80211_tag_length, "Tag Length %u wrong, must be at least 4", tag_len);
break;
}
offset += 2;
offset += add_fixed_field(tree, tvb, pinfo, 1, FIELD_BAND_ID);
offset += add_fixed_field(tree, tvb, pinfo, 1, FIELD_BAND_ID);
proto_tree_add_item(tree, hf_ieee80211_tag_switching_stream_non_qos, tvb, offset, 1, ENC_NA);
offset += 1;
param_num = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_switching_stream_param_num, tvb, offset, 1, ENC_NA);
offset += 1;
while(param_num > 0)
{
proto_tree_add_item(tree, hf_ieee80211_tag_switching_stream_old_tid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_switching_stream_old_direction, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_switching_stream_new_tid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_switching_stream_new_direction, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_switching_stream_new_valid_id, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_tag_switching_stream_llt_type, tvb, offset, 1, ENC_NA);
param_num--;
offset += 2;
}
break;
}
default:
proto_tree_add_item(tree, hf_ieee80211_tag_data, tvb, offset + 1 + 1, tag_len, ENC_NA);
expert_add_info_format(pinfo, ti_tag, &ei_ieee80211_tag_data,
"Dissector for 802.11 IE Tag"
" (%s) code not implemented, Contact"
" Wireshark developers if you want this supported", val_to_str_ext(tag_no,
&tag_num_vals_ext, "(%d)"));
proto_item_append_text(ti, ": Undecoded");
break;
}
if (offset < tag_end) {
}
return tag_len + 1 + 1;
}
static void
ieee_80211_add_tagged_parameters (tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, int tagged_parameters_len, int ftype)
{
int next_len;
beacon_padding = 0;
while (tagged_parameters_len > 0) {
if ((next_len=add_tagged_field (pinfo, tree, tvb, offset, ftype)) == 0)
break;
if (next_len > tagged_parameters_len) {
next_len = tagged_parameters_len;
}
offset += next_len;
tagged_parameters_len -= next_len;
}
}
static void
dissect_ieee80211_mgt (guint16 fcf, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *mgt_tree;
proto_tree *fixed_tree;
proto_tree *tagged_tree;
int offset = 0;
int tagged_parameter_tree_len;
ieee80211_tvb_invalid = FALSE;
if (!proto_is_protocol_enabled(find_protocol_by_id(proto_wlan_mgt))) {
call_dissector(data_handle,tvb, pinfo, tree);
return;
}
ti = proto_tree_add_item (tree, proto_wlan_mgt, tvb, 0, -1, ENC_NA);
mgt_tree = proto_item_add_subtree (ti, ett_80211_mgt);
switch (COMPOSE_FRAME_TYPE(fcf))
{
case MGT_ASSOC_REQ:
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 4);
add_fixed_field(fixed_tree, tvb, pinfo, 0, FIELD_CAP_INFO);
add_fixed_field(fixed_tree, tvb, pinfo, 2, FIELD_LISTEN_IVAL);
offset = 4;
tagged_parameter_tree_len =
tvb_reported_length_remaining(tvb, offset);
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_ASSOC_REQ);
break;
case MGT_ASSOC_RESP:
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 6);
add_fixed_field(fixed_tree, tvb, pinfo, 0, FIELD_CAP_INFO);
add_fixed_field(fixed_tree, tvb, pinfo, 2, FIELD_STATUS_CODE);
add_fixed_field(fixed_tree, tvb, pinfo, 4, FIELD_ASSOC_ID);
offset = 6;
tagged_parameter_tree_len =
tvb_reported_length_remaining(tvb, offset);
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_ASSOC_RESP);
break;
case MGT_REASSOC_REQ:
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 10);
add_fixed_field(fixed_tree, tvb, pinfo, 0, FIELD_CAP_INFO);
add_fixed_field(fixed_tree, tvb, pinfo, 2, FIELD_LISTEN_IVAL);
add_fixed_field(fixed_tree, tvb, pinfo, 4, FIELD_CURRENT_AP_ADDR);
offset = 10;
tagged_parameter_tree_len =
tvb_reported_length_remaining(tvb, offset);
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_REASSOC_REQ);
break;
case MGT_REASSOC_RESP:
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 6);
add_fixed_field(fixed_tree, tvb, pinfo, 0, FIELD_CAP_INFO);
add_fixed_field(fixed_tree, tvb, pinfo, 2, FIELD_STATUS_CODE);
add_fixed_field(fixed_tree, tvb, pinfo, 4, FIELD_ASSOC_ID);
offset = 6;
tagged_parameter_tree_len =
tvb_reported_length_remaining(tvb, offset);
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_REASSOC_RESP);
break;
case MGT_PROBE_REQ:
offset = 0;
tagged_parameter_tree_len =
tvb_reported_length_remaining(tvb, offset);
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_PROBE_REQ);
break;
case MGT_PROBE_RESP:
{
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 12);
add_fixed_field(fixed_tree, tvb, pinfo, 0, FIELD_TIMESTAMP);
add_fixed_field(fixed_tree, tvb, pinfo, 8, FIELD_BEACON_INTERVAL);
add_fixed_field(fixed_tree, tvb, pinfo, 10, FIELD_CAP_INFO);
offset = 12;
tagged_parameter_tree_len = tvb_reported_length_remaining(tvb, offset);
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset, tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree, tagged_parameter_tree_len, MGT_PROBE_RESP);
break;
}
case MGT_MEASUREMENT_PILOT:
{
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 12);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_TIMESTAMP);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_MEASUREMENT_PILOT_INT);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_BEACON_INTERVAL);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_CAP_INFO);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_COUNTRY_STR);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_MAX_REG_PWR);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_MAX_TX_PWR);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_TX_PWR_USED);
offset += add_fixed_field(fixed_tree, tvb, pinfo, offset, FIELD_TRANSCEIVER_NOISE_FLOOR);
tagged_parameter_tree_len = tvb_reported_length_remaining(tvb, offset);
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset, tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree, tagged_parameter_tree_len, MGT_MEASUREMENT_PILOT);
break;
}
case MGT_BEACON:
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 12);
add_fixed_field(fixed_tree, tvb, pinfo, 0, FIELD_TIMESTAMP);
add_fixed_field(fixed_tree, tvb, pinfo, 8, FIELD_BEACON_INTERVAL);
add_fixed_field(fixed_tree, tvb, pinfo, 10, FIELD_CAP_INFO);
offset = 12;
tagged_parameter_tree_len =
tvb_reported_length_remaining(tvb, offset);
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_BEACON);
break;
case MGT_ATIM:
break;
case MGT_DISASS:
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 2);
add_fixed_field(fixed_tree, tvb, pinfo, 0, FIELD_REASON_CODE);
offset = 2;
tagged_parameter_tree_len = tvb_reported_length_remaining(tvb, offset);
if (tagged_parameter_tree_len > 0) {
tagged_tree = get_tagged_parameter_tree(mgt_tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters(tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_DISASS);
}
break;
case MGT_AUTHENTICATION:
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 6);
add_fixed_field(fixed_tree, tvb, pinfo, 0, FIELD_AUTH_ALG);
add_fixed_field(fixed_tree, tvb, pinfo, 2, FIELD_AUTH_TRANS_SEQ);
add_fixed_field(fixed_tree, tvb, pinfo, 4, FIELD_STATUS_CODE);
offset = 6;
tagged_parameter_tree_len =
tvb_reported_length_remaining(tvb, offset);
if (tagged_parameter_tree_len > 0)
{
tagged_tree = get_tagged_parameter_tree (mgt_tree,
tvb,
offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_AUTHENTICATION);
}
break;
case MGT_DEAUTHENTICATION:
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 2);
add_fixed_field(fixed_tree, tvb, pinfo, 0, FIELD_REASON_CODE);
offset = 2;
tagged_parameter_tree_len = tvb_reported_length_remaining(tvb, offset);
if (tagged_parameter_tree_len > 0) {
tagged_tree = get_tagged_parameter_tree(mgt_tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters(tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_DEAUTHENTICATION);
}
break;
case MGT_ACTION:
{
proto_item *lcl_fixed_hdr;
proto_tree *lcl_fixed_tree;
lcl_fixed_tree = proto_tree_add_subtree(mgt_tree, tvb, 0, 0, ett_fixed_parameters, &lcl_fixed_hdr, "Fixed parameters");
offset += add_fixed_field(lcl_fixed_tree, tvb, pinfo, 0, FIELD_ACTION);
proto_item_set_len(lcl_fixed_hdr, offset);
if (ieee80211_tvb_invalid)
break;
tagged_parameter_tree_len = tvb_reported_length_remaining(tvb, offset);
if (tagged_parameter_tree_len > 0)
{
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_ACTION);
}
break;
}
case MGT_ACTION_NO_ACK:
{
proto_item *lcl_fixed_hdr;
proto_tree *lcl_fixed_tree;
lcl_fixed_tree = proto_tree_add_subtree(mgt_tree, tvb, 0, 0, ett_fixed_parameters, &lcl_fixed_hdr, "Fixed parameters");
offset += add_fixed_field(lcl_fixed_tree, tvb, pinfo, 0, FIELD_ACTION);
proto_item_set_len(lcl_fixed_hdr, offset);
if (ieee80211_tvb_invalid)
break;
tagged_parameter_tree_len = tvb_reported_length_remaining(tvb, offset);
if (tagged_parameter_tree_len > 0)
{
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, MGT_ACTION_NO_ACK);
}
break;
}
case MGT_ARUBA_WLAN:
{
proto_tree *aruba_tree;
guint16 type;
type = tvb_get_ntohs(tvb, offset);
aruba_tree = proto_tree_add_subtree(mgt_tree, tvb, 0, 0, ett_fixed_parameters, NULL, "Aruba Management");
proto_tree_add_item(aruba_tree, hf_ieee80211_aruba, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch(type){
case 0x0003:
proto_tree_add_item(aruba_tree, hf_ieee80211_aruba_mtu, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x0005:
proto_tree_add_item(aruba_tree, hf_ieee80211_aruba_hb_seq, tvb, offset, 8, ENC_BIG_ENDIAN);
break;
}
break;
}
}
}
static void
set_src_addr_cols(packet_info *pinfo, tvbuff_t *tvb, int offset, const char *type)
{
address ether_addr;
TVB_SET_ADDRESS(&ether_addr, AT_ETHER, tvb, offset, 6);
col_add_fstr(pinfo->cinfo, COL_RES_DL_SRC, "%s (%s)",
address_with_resolution_to_str(wmem_packet_scope(), &ether_addr), type);
}
static void
set_dst_addr_cols(packet_info *pinfo, tvbuff_t *tvb, int offset, const char *type)
{
address ether_addr;
TVB_SET_ADDRESS(&ether_addr, AT_ETHER, tvb, offset, 6);
col_add_fstr(pinfo->cinfo, COL_RES_DL_DST, "%s (%s)",
address_with_resolution_to_str(wmem_packet_scope(), &ether_addr), type);
}
static guint32
crc32_802_tvb_padded(tvbuff_t *tvb, guint hdr_len, guint hdr_size, guint len)
{
guint32 c_crc;
c_crc = crc32_ccitt_tvb(tvb, hdr_len);
c_crc = crc32_ccitt_tvb_offset_seed(tvb, hdr_size, len, ~c_crc);
c_crc = ((unsigned char)(c_crc>>0)<<24) |
((unsigned char)(c_crc>>8)<<16) |
((unsigned char)(c_crc>>16)<<8) |
((unsigned char)(c_crc>>24)<<0);
return (c_crc);
}
static int
dissect_ieee80211_common (tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gboolean wlan_broken_fc,
gboolean is_centrino,
struct ieee_802_11_phdr *phdr)
{
guint16 fcf, flags, frame_type_subtype, ctrl_fcf, ctrl_type_subtype;
guint16 cw_fcf;
guint16 seq_control;
guint32 seq_number, frag_number;
gboolean more_frags;
proto_item *ti = NULL;
proto_item *fcs_item = NULL;
proto_item *cw_item = NULL;
proto_item *hidden_item;
proto_tree *fcs_tree = NULL;
proto_tree *cw_tree = NULL;
guint16 hdr_len, ohdr_len;
guint16 htc_len = 0;
gboolean has_fcs, fcs_good, fcs_bad;
gint len, reported_len, ivlen;
gint sta_addr_offset = 0;
gchar *station_name;
gboolean is_amsdu = 0;
gboolean save_fragmented;
guint32 addr_type;
guint8 octet1, octet2;
char out_buff[SHORT_STR];
gint is_iv_bad;
guchar iv_buff[4];
const char *addr1_str = NULL;
int addr1_hf = -1, addr1_hf_resolved = -1;
guint offset;
const gchar *fts_str;
gchar flag_str[] = "opmPRMFTC";
gint ii;
guint16 qosoff = 0;
guint16 qos_control = 0;
gint meshctl_len = 0;
guint8 mesh_flags;
guint16 meshoff = 0;
static wlan_hdr_t whdrs[4];
gboolean retransmitted;
gboolean isDMG = (phdr->presence_flags & PHDR_802_11_HAS_FREQUENCY ?
IS_80211AD(phdr->frequency) :
FALSE);
volatile encap_t encap_type;
proto_tree *volatile hdr_tree = NULL;
tvbuff_t *volatile next_tvb = NULL;
wlan_hdr_t *volatile whdr;
AIRPDCAP_KEY_ITEM used_key;
p_add_proto_data(wmem_file_scope(), pinfo, proto_wlan, IS_DMG_KEY, &isDMG);
whdr= &whdrs[0];
col_set_str (pinfo->cinfo, COL_PROTOCOL, "802.11");
col_clear(pinfo->cinfo, COL_INFO);
fcf = FETCH_FCF(0);
frame_type_subtype = COMPOSE_FRAME_TYPE(fcf);
whdr->type = frame_type_subtype;
if (frame_type_subtype == CTRL_CONTROL_WRAPPER)
ctrl_fcf = FETCH_FCF(10);
else
ctrl_fcf = 0;
fts_str = val_to_str_ext_const(frame_type_subtype, &frame_type_subtype_vals_ext,
"Unrecognized (Reserved frame)");
col_set_str (pinfo->cinfo, COL_INFO, fts_str);
# define FROM_TO_DS 3
flags = FCF_FLAGS (fcf);
more_frags = HAVE_FRAGMENTS (flags);
for (ii = 0; ii < 8; ii++) {
if (! (flags & 0x80 >> ii)) {
flag_str[ii] = '.';
}
}
switch (FCF_FRAME_TYPE (fcf)) {
case MGT_FRAME:
hdr_len = MGT_FRAME_HDR_LEN;
if (HAS_HT_CONTROL(FCF_FLAGS(fcf))) {
hdr_len += 4;
htc_len = 4;
}
break;
case CONTROL_FRAME:
if (frame_type_subtype == CTRL_CONTROL_WRAPPER) {
hdr_len = 6;
cw_fcf = ctrl_fcf;
} else {
hdr_len = 0;
cw_fcf = fcf;
}
switch (COMPOSE_FRAME_TYPE (cw_fcf)) {
case CTRL_BEAMFORM_RPT_POLL:
hdr_len += 17;
break;
case CTRL_VHT_NDP_ANNC:
hdr_len += 17;
hdr_len += 2;
break;
case CTRL_CTS:
case CTRL_ACKNOWLEDGEMENT:
hdr_len += 10;
break;
case CTRL_POLL:
hdr_len += 18;
break;
case CTRL_SPR:
case CTRL_GRANT:
case CTRL_GRANT_ACK:
hdr_len += 23;
break;
case CTRL_DMG_CTS:
hdr_len += 16;
break;
case CTRL_DMG_DTS:
case CTRL_SSW:
hdr_len += 22;
break;
case CTRL_SSW_FEEDBACK:
case CTRL_SSW_ACK:
hdr_len += 24;
break;
case CTRL_RTS:
case CTRL_PS_POLL:
case CTRL_CFP_END:
case CTRL_CFP_ENDACK:
case CTRL_BLOCK_ACK_REQ:
case CTRL_BLOCK_ACK:
hdr_len += 16;
break;
default:
hdr_len += 4;
break;
}
break;
case DATA_FRAME:
hdr_len = (FCF_ADDR_SELECTOR(fcf) == DATA_ADDR_T4) ? DATA_LONG_HDR_LEN : DATA_SHORT_HDR_LEN;
if (DATA_FRAME_IS_QOS(frame_type_subtype)) {
qosoff = hdr_len;
hdr_len += 2;
if (HAS_HT_CONTROL(FCF_FLAGS(fcf))) {
hdr_len += 4;
htc_len = 4;
}
qos_control = tvb_get_letohs(tvb, qosoff);
if (tvb_bytes_exist(tvb, hdr_len, 1)) {
meshoff = hdr_len;
mesh_flags = tvb_get_guint8 (tvb, meshoff);
if (has_mesh_control(fcf, qos_control, mesh_flags)) {
meshctl_len = find_mesh_control_length(mesh_flags);
hdr_len += meshctl_len;
}
}
}
break;
case EXTENSION_FRAME:
hdr_len = 10;
break;
default:
hdr_len = 4;
break;
}
ohdr_len = hdr_len;
if (phdr->datapad) {
hdr_len = roundup2(hdr_len, 4);
}
ti = proto_tree_add_protocol_format (tree, proto_wlan, tvb, 0, hdr_len,
"IEEE 802.11 %s", fts_str);
hdr_tree = proto_item_add_subtree (ti, ett_80211);
dissect_frame_control(hdr_tree, tvb, wlan_broken_fc, 0, pinfo);
dissect_durid(hdr_tree, tvb, frame_type_subtype, 2);
switch (phdr->fcs_len)
{
case 0:
has_fcs = FALSE;
break;
case 4:
has_fcs = TRUE;
break;
case -2:
if (FCF_FRAME_TYPE (fcf) == DATA_FRAME)
has_fcs = FALSE;
else
has_fcs = wlan_check_fcs;
break;
default:
has_fcs = wlan_check_fcs;
break;
}
seq_control = 0;
frag_number = 0;
seq_number = 0;
switch (FCF_FRAME_TYPE (fcf))
{
case MGT_FRAME:
TVB_SET_ADDRESS(&pinfo->dl_src, wlan_address_type, tvb, 10, 6);
COPY_ADDRESS_SHALLOW(&pinfo->src, &pinfo->dl_src);
TVB_SET_ADDRESS(&pinfo->dl_dst, wlan_address_type, tvb, 4, 6);
COPY_ADDRESS_SHALLOW(&pinfo->dst, &pinfo->dl_dst);
TVB_SET_ADDRESS(&whdr->bssid, wlan_bssid_address_type, tvb, 16, 6);
COPY_ADDRESS_SHALLOW(&whdr->src, &pinfo->dl_src);
COPY_ADDRESS_SHALLOW(&whdr->dst, &pinfo->dl_dst);
seq_control = tvb_get_letohs(tvb, 22);
frag_number = SEQCTL_FRAGMENT_NUMBER(seq_control);
seq_number = SEQCTL_SEQUENCE_NUMBER(seq_control);
col_append_fstr(pinfo->cinfo, COL_INFO,
", SN=%d", seq_number);
col_append_fstr(pinfo->cinfo, COL_INFO,
", FN=%d",frag_number);
if (tree)
{
gchar *ra_da_name, *ta_sa_name, *bssid_name;
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_ra, tvb, 4, 6, ENC_NA);
ra_da_name = tvb_get_ether_name(tvb, 4);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_ra_resolved, tvb, 4, 6, ra_da_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_da, tvb, 4, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_da_resolved, tvb, 4, 6, ra_da_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_ta, tvb, 10, 6, ENC_NA);
ta_sa_name = tvb_get_ether_name(tvb, 10);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_ta_resolved, tvb, 10, 6, ta_sa_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_sa, tvb, 10, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_sa_resolved, tvb, 10, 6, ta_sa_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_bssid, tvb, 16, 6, ENC_NA);
bssid_name = tvb_get_ether_name(tvb, 16);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_bssid_resolved, tvb, 16, 6, bssid_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if ((flags & FROM_TO_DS) == FLAG_FROM_DS) {
sta_addr_offset = 4;
} else if ((flags & FROM_TO_DS) == FLAG_TO_DS) {
sta_addr_offset = 10;
}
if (sta_addr_offset > 0) {
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_staa, tvb, sta_addr_offset, 6, ENC_NA);
station_name = tvb_get_ether_name(tvb, sta_addr_offset);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_staa_resolved, tvb, sta_addr_offset, 6, station_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 4, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, 4, 6, ra_da_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 10, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, 10, 6, ta_sa_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 16, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, 16, 6, bssid_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item (hdr_tree, hf_ieee80211_frag_number, tvb, 22, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (hdr_tree, hf_ieee80211_seq_number, tvb, 22, 2, ENC_LITTLE_ENDIAN);
}
break;
case CONTROL_FRAME:
{
if (frame_type_subtype == CTRL_CONTROL_WRAPPER) {
offset = 10;
ctrl_fcf = FETCH_FCF(10);
ctrl_type_subtype = COMPOSE_FRAME_TYPE(ctrl_fcf);
} else {
offset = 10;
ctrl_type_subtype = frame_type_subtype;
}
switch (ctrl_type_subtype)
{
case CTRL_PS_POLL:
case CTRL_CTS:
case CTRL_CFP_ENDACK:
if(isDMG == TRUE) {
expert_add_info_format(pinfo, hdr_tree, &ei_ieee80211_dmg_subtype,
"DMG STA shouldn't transmit control frame of type contention-free period end+ack");
}
break;
default:
break;
}
switch (ctrl_type_subtype)
{
case CTRL_PS_POLL:
addr1_str = "BSSID";
addr1_hf = hf_ieee80211_addr_bssid;
addr1_hf_resolved = hf_ieee80211_addr_bssid_resolved;
break;
case CTRL_BEAMFORM_RPT_POLL:
case CTRL_VHT_NDP_ANNC:
case CTRL_RTS:
case CTRL_POLL:
case CTRL_SPR:
case CTRL_GRANT:
case CTRL_DMG_CTS:
case CTRL_DMG_DTS:
case CTRL_GRANT_ACK:
case CTRL_SSW:
case CTRL_SSW_FEEDBACK:
case CTRL_SSW_ACK:
case CTRL_CTS:
case CTRL_ACKNOWLEDGEMENT:
case CTRL_CFP_END:
case CTRL_CFP_ENDACK:
case CTRL_BLOCK_ACK_REQ:
case CTRL_BLOCK_ACK:
addr1_str = "RA";
addr1_hf = hf_ieee80211_addr_ra;
addr1_hf_resolved = hf_ieee80211_addr_ra_resolved;
break;
default:
break;
}
if (!addr1_str)
break;
set_dst_addr_cols(pinfo, tvb, 4, addr1_str);
if (tree) {
gchar* ether_name = tvb_get_ether_name(tvb, 4);
proto_tree_add_item(hdr_tree, addr1_hf, tvb, 4, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, addr1_hf_resolved, tvb, 4, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 4, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, 4, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if ((frame_type_subtype == CTRL_CONTROL_WRAPPER) && tree) {
cw_tree = proto_tree_add_subtree(hdr_tree, tvb, offset, 2,
ett_cntrl_wrapper_fc, NULL, "Contained Frame Control");
dissect_frame_control(cw_tree, tvb, FALSE, offset, pinfo);
dissect_ht_control(hdr_tree, tvb, offset + 2);
offset += 6;
hdr_tree = proto_tree_add_subtree(hdr_tree, tvb, offset, 2,
ett_cntrl_wrapper_fc, &cw_item, "Carried Frame");
if(isDMG == TRUE) {
expert_add_info_format(pinfo, cw_item, &ei_ieee80211_dmg_subtype,
"DMG STA shouldn't transmit Control Wrapper frame");
}
}
if ((frame_type_subtype == CTRL_CFP_END) && tree) {
if(isDMG == TRUE)
set_src_addr_cols(pinfo, tvb, offset, "TA");
else
set_src_addr_cols(pinfo, tvb, offset, "BSSID");
if (tree) {
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
offset += 6;
}
switch (ctrl_type_subtype)
{
case CTRL_PS_POLL:
case CTRL_CFP_END:
case CTRL_CFP_ENDACK:
{
set_src_addr_cols(pinfo, tvb, offset, "BSSID");
if (tree) {
gchar* ether_name = tvb_get_ether_name(tvb, offset);
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_ta_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 6;
}
break;
}
case CTRL_BEAMFORM_RPT_POLL:
{
set_src_addr_cols(pinfo, tvb, offset, "TA");
if (tree) {
gchar *ether_name = tvb_get_ether_name(tvb, offset);
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_ta_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 6;
proto_tree_add_item(hdr_tree, hf_ieee80211_beamform_feedback_seg_retrans_bitmap, tvb, offset, 1, ENC_NA);
}
break;
}
case CTRL_VHT_NDP_ANNC:
{
set_src_addr_cols(pinfo, tvb, offset, "TA");
if (tree) {
guint16 sta_info;
guint8 len_fcs = 0;
proto_tree *dialog_token_tree;
proto_item *dialog_token_item;
proto_tree *sta_info_tree;
proto_item *sta_info_item;
gchar* ether_name = tvb_get_ether_name(tvb, offset);
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_ta_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 6;
dialog_token_item = proto_tree_add_item(hdr_tree, hf_ieee80211_vht_ndp_annc_token,
tvb, offset, 1, ENC_NA);
dialog_token_tree = proto_item_add_subtree(dialog_token_item, ett_vht_ndp_annc_token_tree);
proto_tree_add_item(dialog_token_tree, hf_ieee80211_vht_ndp_annc_token_number,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(dialog_token_tree, hf_ieee80211_vht_ndp_annc_token_reserved,
tvb, offset, 1, ENC_NA);
offset++;
if(has_fcs){
len_fcs = 4;
}
while (tvb_reported_length_remaining(tvb, offset) > len_fcs) {
sta_info_item = proto_tree_add_item(hdr_tree, hf_ieee80211_vht_ndp_annc_sta_info,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
sta_info_tree = proto_item_add_subtree(sta_info_item, ett_vht_ndp_annc_sta_info_tree);
proto_tree_add_item(sta_info_tree, hf_ieee80211_vht_ndp_annc_sta_info_aid12,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sta_info_tree, hf_ieee80211_vht_ndp_annc_sta_info_feedback_type,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
sta_info = tvb_get_letohs(tvb, offset);
if (sta_info & 0x0010)
proto_tree_add_uint(sta_info_tree,
hf_ieee80211_vht_ndp_annc_sta_info_nc_index,
tvb, offset, 2, sta_info);
else
proto_tree_add_item(sta_info_tree, hf_ieee80211_vht_ndp_annc_sta_info_reserved,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
}
break;
}
case CTRL_GRANT_ACK:
case CTRL_SSW:
case CTRL_SSW_FEEDBACK:
case CTRL_SSW_ACK:
case CTRL_DMG_CTS:
case CTRL_GRANT:
case CTRL_SPR:
case CTRL_POLL:
case CTRL_RTS:
{
set_src_addr_cols(pinfo, tvb, offset, "TA");
if (tree) {
gchar* ether_name = tvb_get_ether_name(tvb, offset);
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_ta_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 6;
}
break;
}
case CTRL_CONTROL_WRAPPER:
{
break;
}
case CTRL_BLOCK_ACK_REQ:
{
set_src_addr_cols(pinfo, tvb, offset, "TA");
{
guint16 bar_control;
guint8 block_ack_type;
proto_item *bar_parent_item;
proto_tree *bar_sub_tree;
gchar* ether_name = tvb_get_ether_name(tvb, offset);
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_ta_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 6;
bar_control = tvb_get_letohs(tvb, offset);
block_ack_type = (bar_control & 0x0006) >> 1;
proto_tree_add_item(hdr_tree, hf_ieee80211_block_ack_request_type, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
bar_parent_item = proto_tree_add_item(hdr_tree,
hf_ieee80211_block_ack_request_control, tvb, offset, 2, ENC_LITTLE_ENDIAN);
bar_sub_tree = proto_item_add_subtree(bar_parent_item,
ett_block_ack);
proto_tree_add_item(bar_sub_tree,
hf_ieee80211_block_ack_control_ack_policy, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bar_sub_tree, hf_ieee80211_block_ack_control_multi_tid,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bar_sub_tree,
hf_ieee80211_block_ack_control_compressed_bitmap, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(bar_sub_tree, hf_ieee80211_block_ack_control_reserved,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
switch (block_ack_type)
{
case 0:
{
if(isDMG == TRUE) {
expert_add_info_format(pinfo, bar_sub_tree, &ei_ieee80211_dmg_subtype,
"DMG STA shouldn't transmit BlockAckReq frame with Basic BlockAckReq");
break;
}
proto_tree_add_item(bar_sub_tree,
hf_ieee80211_block_ack_control_basic_tid_info, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
add_fixed_field(hdr_tree, tvb, pinfo, offset,
FIELD_BLOCK_ACK_SSC);
break;
}
case 1:
if(isDMG == FALSE) {
expert_add_info_format(pinfo, bar_sub_tree, &ei_ieee80211_dmg_subtype,
"Non-DMG STA shouldn't transmit BlockAckReq frame with Extended Compressed BlockAckReq");
break;
}
case 2:
{
proto_tree_add_item(bar_sub_tree,
hf_ieee80211_block_ack_control_compressed_tid_info, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
add_fixed_field(hdr_tree, tvb, pinfo, offset,
FIELD_BLOCK_ACK_SSC);
break;
}
case 3:
{
guint8 tid_count;
guint iii;
proto_tree *bar_mtid_tree, *bar_mtid_sub_tree;
if(isDMG == TRUE) {
expert_add_info_format(pinfo, bar_sub_tree, &ei_ieee80211_dmg_subtype,
"DMG STA shouldn't transmit BlockAckReq frame with Basic BlockAckReq");
break;
}
tid_count = ((bar_control & 0xF000) >> 12) + 1;
proto_tree_add_uint(bar_sub_tree, hf_ieee80211_block_ack_control_multi_tid_info, tvb, offset, 2, tid_count);
offset += 2;
bar_mtid_tree = proto_tree_add_subtree(hdr_tree, tvb, offset, tid_count*4, ett_block_ack, NULL, "Per TID Info");
for (iii = 0; iii < tid_count; iii++) {
bar_parent_item = proto_tree_add_uint(bar_mtid_tree, hf_ieee80211_block_ack_multi_tid_info, tvb, offset, 4, iii);
bar_mtid_sub_tree = proto_item_add_subtree(bar_parent_item, ett_block_ack);
proto_tree_add_item(bar_mtid_sub_tree, hf_ieee80211_block_ack_multi_tid_reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bar_mtid_sub_tree, hf_ieee80211_block_ack_multi_tid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset += add_fixed_field(bar_mtid_sub_tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_SSC);
}
break;
}
}
}
break;
}
case CTRL_BLOCK_ACK:
{
set_src_addr_cols(pinfo, tvb, offset, "TA");
{
guint16 ba_control;
guint8 block_ack_type;
proto_item *ba_parent_item;
proto_tree *ba_sub_tree;
gchar* ether_name = tvb_get_ether_name(tvb, offset);
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_ta_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, offset, 6, ether_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 6;
ba_control = tvb_get_letohs(tvb, offset);
block_ack_type = (ba_control & 0x0006) >> 1;
proto_tree_add_item(hdr_tree, hf_ieee80211_block_ack_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ba_parent_item = proto_tree_add_item(hdr_tree,
hf_ieee80211_block_ack_control, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ba_sub_tree = proto_item_add_subtree(ba_parent_item, ett_block_ack);
proto_tree_add_item(ba_sub_tree, hf_ieee80211_block_ack_control_ack_policy,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ba_sub_tree, hf_ieee80211_block_ack_control_multi_tid,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ba_sub_tree,
hf_ieee80211_block_ack_control_compressed_bitmap, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(ba_sub_tree, hf_ieee80211_block_ack_control_reserved, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
switch (block_ack_type)
{
case 0:
{
proto_tree_add_item(ba_sub_tree,
hf_ieee80211_block_ack_control_basic_tid_info, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset += add_fixed_field(hdr_tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_SSC);
proto_tree_add_item(hdr_tree, hf_ieee80211_block_ack_bitmap, tvb, offset, 128, ENC_NA);
break;
}
case 1:
{
guint16 ssn;
guint64 bmap;
int f;
proto_item *ba_bitmap_item;
proto_tree *ba_bitmap_tree;
if(isDMG == FALSE) {
expert_add_info_format(pinfo, ba_sub_tree, &ei_ieee80211_dmg_subtype,
"Non-DMG STA shouldn't transmit BlockAck frame with Extended Compressed BlockAck");
break;
}
proto_tree_add_item(ba_sub_tree, hf_ieee80211_block_ack_control_basic_tid_info, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
ssn = tvb_get_letohs(tvb, offset);
ssn >>= 4;
offset += add_fixed_field(hdr_tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_SSC);
bmap = tvb_get_letoh64(tvb, offset);
ba_bitmap_item = proto_tree_add_item(hdr_tree, hf_ieee80211_block_ack_bitmap, tvb, offset, 8, ENC_NA);
ba_bitmap_tree = proto_item_add_subtree(ba_bitmap_item, ett_block_ack_bitmap);
for (f = 0; f < 64; f++) {
if (bmap & (G_GUINT64_CONSTANT(1) << f))
continue;
proto_tree_add_uint_format_value(ba_bitmap_tree, hf_ieee80211_block_ack_bitmap_missing_frame,
tvb, offset + (f/8), 1, ssn + f, "%u", ssn + f);
}
offset += 8;
proto_tree_add_item(ba_sub_tree, hf_ieee80211_block_ack_RBUFCAP, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
}
case 2:
{
guint16 ssn;
guint64 bmap;
int f;
proto_item *ba_bitmap_item;
proto_tree *ba_bitmap_tree;
proto_tree_add_item(ba_sub_tree, hf_ieee80211_block_ack_control_basic_tid_info, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
ssn = tvb_get_letohs(tvb, offset);
ssn >>= 4;
offset += add_fixed_field(hdr_tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_SSC);
bmap = tvb_get_letoh64(tvb, offset);
ba_bitmap_item = proto_tree_add_item(hdr_tree, hf_ieee80211_block_ack_bitmap, tvb, offset, 8, ENC_NA);
ba_bitmap_tree = proto_item_add_subtree(ba_bitmap_item, ett_block_ack_bitmap);
for (f = 0; f < 64; f++) {
if (bmap & (G_GUINT64_CONSTANT(1) << f))
continue;
proto_tree_add_uint_format_value(ba_bitmap_tree, hf_ieee80211_block_ack_bitmap_missing_frame,
tvb, offset + (f/8), 1, ssn + f, "%u", (ssn + f) & 0x0fff);
}
break;
}
case 3:
{
guint8 tid_count;
guint iii;
proto_tree *ba_mtid_tree, *ba_mtid_sub_tree;
tid_count = ((ba_control & 0xF000) >> 12) + 1;
proto_tree_add_uint(ba_sub_tree,
hf_ieee80211_block_ack_control_compressed_tid_info, tvb, offset, 2, tid_count);
offset += 2;
ba_mtid_tree = proto_tree_add_subtree(hdr_tree, tvb, offset, tid_count*4, ett_block_ack, NULL, "Per TID Info");
for (iii = 0; iii < tid_count; iii++) {
ba_parent_item = proto_tree_add_uint(ba_mtid_tree, hf_ieee80211_block_ack_multi_tid_info, tvb, offset, 4, iii);
ba_mtid_sub_tree = proto_item_add_subtree(ba_parent_item, ett_block_ack);
proto_tree_add_item(ba_mtid_sub_tree, hf_ieee80211_block_ack_multi_tid_reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ba_mtid_sub_tree, hf_ieee80211_block_ack_multi_tid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset += add_fixed_field(ba_mtid_sub_tree, tvb, pinfo, offset, FIELD_BLOCK_ACK_SSC);
proto_tree_add_item(ba_mtid_sub_tree, hf_ieee80211_block_ack_bitmap, tvb, offset, 8, ENC_NA);
offset += 8;
}
break;
}
}
}
break;
}
}
switch (ctrl_type_subtype) {
case CTRL_POLL: {
proto_tree_add_item(hdr_tree, hf_ieee80211_cf_response_offset,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
}
case CTRL_GRANT:
case CTRL_GRANT_ACK:
case CTRL_SPR: {
gboolean isGrant;
if(ctrl_type_subtype != CTRL_GRANT_ACK) {
offset += add_fixed_field(hdr_tree, tvb, pinfo, offset, FIELD_DYNAMIC_ALLOCATION);
} else {
offset += 5;
}
isGrant = ((ctrl_type_subtype==CTRL_GRANT)||(ctrl_type_subtype==CTRL_GRANT_ACK));
p_add_proto_data(wmem_file_scope(), pinfo, proto_wlan, IS_CTRL_GRANT_OR_GRANT_ACK_KEY, &isGrant);
add_fixed_field(hdr_tree, tvb, pinfo, offset, FIELD_BEAMFORMING_CTRL);
break;
}
case CTRL_SSW: {
offset += add_fixed_field(hdr_tree, tvb, pinfo, offset, FIELD_SECTOR_SWEEP);
add_fixed_field(hdr_tree, tvb, pinfo, offset, FIELD_SECTOR_SWEEP_FB);
break;
}
case CTRL_SSW_ACK:
case CTRL_SSW_FEEDBACK: {
offset += add_fixed_field(hdr_tree, tvb, pinfo, offset, FIELD_SECTOR_SWEEP_FB);
offset += add_fixed_field(hdr_tree, tvb, pinfo, offset, FIELD_BRP_REQ);
add_fixed_field(hdr_tree, tvb, pinfo, offset, FIELD_BEAMFORMED_LINK_MAINTAINCE);
break;
}
case CTRL_DMG_DTS: {
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_nav_sa, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_nav_da, tvb, offset, 6, ENC_NA);
break;
}
default:
break;
}
break;
}
case DATA_FRAME:
{
guint32 ra_offset, da_offset, sa_offset, ta_offset, bssid_offset;
addr_type = FCF_ADDR_SELECTOR (fcf);
switch (addr_type)
{
case DATA_ADDR_T1:
ra_offset = 4;
da_offset = 4;
sa_offset = 10;
ta_offset = 10;
bssid_offset = 16;
break;
case DATA_ADDR_T2:
ra_offset = 4;
da_offset = 4;
sa_offset = 16;
ta_offset = 10;
bssid_offset = 10;
break;
case DATA_ADDR_T3:
ra_offset = 4;
da_offset = 16;
sa_offset = 10;
ta_offset = 10;
bssid_offset = 4;
break;
case DATA_ADDR_T4:
ra_offset = 4;
da_offset = 16;
sa_offset = 24;
ta_offset = 10;
bssid_offset = 10;
break;
default:
ra_offset = 0;
da_offset = 0;
sa_offset = 0;
ta_offset = 0;
bssid_offset = 0;
break;
}
TVB_SET_ADDRESS(&pinfo->dl_src, wlan_address_type, tvb, sa_offset, 6);
COPY_ADDRESS_SHALLOW(&pinfo->src, &pinfo->dl_src);
TVB_SET_ADDRESS(&pinfo->dl_dst, wlan_address_type, tvb, da_offset, 6);
COPY_ADDRESS_SHALLOW(&pinfo->dst, &pinfo->dl_dst);
TVB_SET_ADDRESS(&whdr->bssid, wlan_bssid_address_type, tvb, bssid_offset, 6);
COPY_ADDRESS_SHALLOW(&whdr->src, &pinfo->dl_src);
COPY_ADDRESS_SHALLOW(&whdr->dst, &pinfo->dl_dst);
seq_control = tvb_get_letohs(tvb, 22);
frag_number = SEQCTL_FRAGMENT_NUMBER(seq_control);
seq_number = SEQCTL_SEQUENCE_NUMBER(seq_control);
col_append_fstr(pinfo->cinfo, COL_INFO,
", SN=%d, FN=%d", seq_number,frag_number);
if (tree)
{
gchar *ra_name, *ta_name, *sa_name, *da_name, *bssid_name = NULL;
switch (addr_type)
{
case DATA_ADDR_T1:
case DATA_ADDR_T2:
case DATA_ADDR_T3:
case DATA_ADDR_T4:
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_ra, tvb, ra_offset, 6, ENC_NA);
ra_name = tvb_get_ether_name(tvb, ra_offset);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_ra_resolved, tvb, ra_offset, 6, ra_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_da, tvb, da_offset, 6, ENC_NA);
da_name = tvb_get_ether_name(tvb, da_offset);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_da_resolved, tvb, da_offset, 6, da_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_ta, tvb, ta_offset, 6, ENC_NA);
ta_name = tvb_get_ether_name(tvb, ta_offset);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_ta_resolved, tvb, ta_offset, 6, ta_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_sa, tvb, sa_offset, 6, ENC_NA);
sa_name = tvb_get_ether_name(tvb, sa_offset);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_sa_resolved, tvb, sa_offset, 6, sa_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_bssid, tvb, bssid_offset, 6, ENC_NA);
bssid_name = tvb_get_ether_name(tvb, bssid_offset);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_bssid_resolved, tvb, bssid_offset, 6, bssid_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if ((flags & FROM_TO_DS) == FLAG_FROM_DS) {
sta_addr_offset = ra_offset;
} else if ((flags & FROM_TO_DS) == FLAG_TO_DS) {
sta_addr_offset = ta_offset;
}
if (sta_addr_offset > 0) {
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_staa, tvb, sta_addr_offset, 6, ENC_NA);
station_name = tvb_get_ether_name(tvb, sta_addr_offset);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_staa_resolved, tvb, sta_addr_offset, 6, station_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
proto_tree_add_item (hdr_tree, hf_ieee80211_frag_number, tvb, 22, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (hdr_tree, hf_ieee80211_seq_number, tvb, 22, 2, ENC_LITTLE_ENDIAN);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, ra_offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, ra_offset, 6, ra_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, ta_offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, ta_offset, 6, ta_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, sa_offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, sa_offset, 6, sa_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, da_offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, da_offset, 6, da_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, bssid_offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_resolved, tvb, bssid_offset, 6, bssid_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
}
}
break;
}
case EXTENSION_FRAME: {
switch (frame_type_subtype) {
case EXTENSION_DMG_BEACON: {
set_dst_addr_cols(pinfo, tvb, 4, "BSSID");
if (tree) {
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_bssid, tvb, 4, 6, ENC_NA);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 4, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
break;
}
}
}
}
len = tvb_captured_length_remaining(tvb, hdr_len);
reported_len = tvb_reported_length_remaining(tvb, hdr_len);
if (has_fcs)
{
if (reported_len < 4)
{
;
}
else if (len < reported_len)
{
reported_len -= 4;
if (len > reported_len)
len = reported_len;
}
else
{
len -= 4;
reported_len -= 4;
if (tree)
{
guint32 sent_fcs = tvb_get_ntohl(tvb, hdr_len + len);
guint32 fcs;
if (phdr->datapad)
fcs = crc32_802_tvb_padded(tvb, ohdr_len, hdr_len, len);
else
fcs = crc32_802_tvb(tvb, hdr_len + len);
if (fcs == sent_fcs) {
fcs_good = TRUE;
fcs_bad = FALSE;
} else {
fcs_good = FALSE;
fcs_bad = TRUE;
}
fcs_item = proto_tree_add_item(hdr_tree, hf_ieee80211_fcs, tvb,
hdr_len + len, 4, ENC_LITTLE_ENDIAN);
if (fcs_good) {
proto_item_append_text(fcs_item, " [correct]");
} else {
proto_item_append_text(fcs_item, " [incorrect, should be 0x%08x]", fcs);
flag_str[8] = '.';
}
proto_tree_set_appendix(hdr_tree, tvb, hdr_len + len, 4);
if(wlan_check_checksum) {
fcs_tree = proto_item_add_subtree(fcs_item, ett_fcs);
fcs_item = proto_tree_add_boolean(fcs_tree,
hf_ieee80211_fcs_good, tvb,
hdr_len + len, 4,
fcs_good);
PROTO_ITEM_SET_GENERATED(fcs_item);
fcs_item = proto_tree_add_boolean(fcs_tree,
hf_ieee80211_fcs_bad, tvb,
hdr_len + len, 4,
fcs_bad);
PROTO_ITEM_SET_GENERATED(fcs_item);
}
}
}
}
else
{
flag_str[8] = '\0';
}
proto_item_append_text(ti, ", Flags: %s", flag_str);
col_append_fstr (pinfo->cinfo, COL_INFO, ", Flags=%s", flag_str);
switch (FCF_FRAME_TYPE (fcf))
{
case MGT_FRAME:
if (htc_len == 4) {
dissect_ht_control(hdr_tree, tvb, ohdr_len - 4);
}
break;
case DATA_FRAME:
if (tree && DATA_FRAME_IS_QOS(frame_type_subtype))
{
proto_item *qos_fields, *qos_ti;
proto_tree *qos_tree;
guint16 qos_eosp;
guint16 qos_field_content;
qos_fields = proto_tree_add_item(hdr_tree, hf_ieee80211_qos, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
qos_tree = proto_item_add_subtree (qos_fields, ett_qos_parameters);
qos_eosp = QOS_EOSP(qos_control);
qos_field_content = QOS_FIELD_CONTENT(qos_control);
proto_tree_add_item(qos_tree, hf_ieee80211_qos_tid, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
qos_ti = proto_tree_add_item(qos_tree, hf_ieee80211_qos_priority, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_GENERATED(qos_ti);
if (flags & FLAG_TO_DS) {
proto_tree_add_item(qos_tree, hf_ieee80211_qos_bit4, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(qos_tree, hf_ieee80211_qos_eosp, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(qos_tree, hf_ieee80211_qos_ack_policy, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
if (flags & FLAG_FROM_DS) {
if (!DATA_FRAME_IS_NULL(frame_type_subtype)) {
proto_tree_add_item(qos_tree, hf_ieee80211_qos_amsdu_present, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
is_amsdu = QOS_AMSDU_PRESENT(qos_control);
}
if (DATA_FRAME_IS_CF_POLL(frame_type_subtype)) {
qos_ti = proto_tree_add_item(qos_tree, hf_ieee80211_qos_txop_limit, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
if (qos_field_content == 0) {
proto_item_append_text(qos_ti, " (transmit one frame immediately)");
}
} else {
proto_item *qos_ps_buf_state_fields;
proto_tree *qos_ps_buf_state_tree;
qos_ps_buf_state_fields = proto_tree_add_item(qos_tree, hf_ieee80211_qos_ps_buf_state, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
qos_ps_buf_state_tree = proto_item_add_subtree (qos_ps_buf_state_fields, ett_qos_ps_buf_state);
proto_tree_add_item(qos_ps_buf_state_tree, hf_ieee80211_qos_buf_state_indicated, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
if (QOS_PS_BUF_STATE_INDICATED(qos_field_content)) {
proto_tree_add_item(qos_ps_buf_state_tree, hf_ieee80211_qos_highest_pri_buf_ac, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
qos_ti = proto_tree_add_item(qos_ps_buf_state_tree, hf_ieee80211_qos_qap_buf_load, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
switch (QOS_PS_QAP_BUF_LOAD(qos_field_content)) {
case 0:
proto_item_append_text(qos_ti, " (no buffered traffic)");
break;
default:
proto_item_append_text(qos_ti, " (%d octets)", QOS_PS_QAP_BUF_LOAD(qos_field_content)*4096);
break;
case 15:
proto_item_append_text(qos_ti, " (greater than 57344 octets)");
break;
}
}
}
} else {
if (!DATA_FRAME_IS_NULL(frame_type_subtype)) {
proto_tree_add_item(qos_tree, hf_ieee80211_qos_amsdu_present, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
is_amsdu = QOS_AMSDU_PRESENT(qos_control);
}
if (qos_eosp) {
qos_ti = proto_tree_add_item(qos_tree, hf_ieee80211_qos_queue_size, tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
switch (qos_field_content) {
case 0:
proto_item_append_text(qos_ti, " (no buffered traffic in the queue)");
break;
default:
proto_item_append_text(qos_ti, " (%u bytes)", qos_field_content*256);
break;
case 254:
proto_item_append_text(qos_ti, " (more than 64768 octets)");
break;
case 255:
proto_item_append_text(qos_ti, " (unspecified or unknown)");
break;
}
} else {
qos_ti = proto_tree_add_item(qos_tree, hf_ieee80211_qos_txop_dur_req,
tvb, qosoff, 2, ENC_LITTLE_ENDIAN);
if (qos_field_content == 0) {
proto_item_append_text(qos_ti, " (no TXOP requested)");
}
}
}
if (htc_len == 4) {
dissect_ht_control(hdr_tree, tvb, ohdr_len - 4);
}
if (meshctl_len != 0) {
proto_item *msh_fields;
proto_tree *msh_tree;
msh_fields = proto_tree_add_item(hdr_tree, hf_ieee80211_mesh_control_field, tvb, meshoff, meshctl_len, ENC_NA);
msh_tree = proto_item_add_subtree (msh_fields, ett_msh_control);
add_fixed_field(msh_tree, tvb, pinfo, meshoff, FIELD_MESH_CONTROL);
}
}
if (enable_decryption && !pinfo->fd->flags.visited) {
const guint8 *enc_data = tvb_get_ptr(tvb, 0, hdr_len+reported_len);
AirPDcapPacketProcess(&airpdcap_ctx, enc_data, hdr_len, hdr_len+reported_len, NULL, 0, NULL, TRUE, FALSE);
}
if (DATA_FRAME_IS_NULL(frame_type_subtype))
goto end_of_wlan;
if (!wlan_subdissector) {
guint fnum = 0;
retransmitted = FALSE;
if (!pinfo->fd->flags.visited) {
retransmit_key key;
retransmit_key *result;
memcpy(key.bssid, whdr->bssid.data, 6);
memcpy(key.src, whdr->src.data, 6);
key.seq_control = 0;
result = (retransmit_key *)g_hash_table_lookup(fc_analyse_retransmit_table, &key);
if (result && (result->seq_control == seq_control)) {
fnum = result->fnum;
g_hash_table_insert(fc_first_frame_table, GINT_TO_POINTER(pinfo->fd->num),
GINT_TO_POINTER(fnum));
retransmitted = TRUE;
} else {
if (!result) {
result = wmem_new(wmem_file_scope(), retransmit_key);
*result = key;
g_hash_table_insert(fc_analyse_retransmit_table, result, result);
}
result->seq_control = seq_control;
result->fnum = pinfo->fd->num;
}
}
else if ((fnum = GPOINTER_TO_UINT(g_hash_table_lookup(fc_first_frame_table, GINT_TO_POINTER(pinfo->fd->num))))) {
retransmitted = TRUE;
}
if (retransmitted) {
col_append_str(pinfo->cinfo, COL_INFO, " [retransmitted]");
if (tree) {
proto_item *item;
item=proto_tree_add_none_format(hdr_tree, hf_ieee80211_fc_analysis_retransmission, tvb, 0, 0,
"Retransmitted frame");
PROTO_ITEM_SET_GENERATED(item);
item=proto_tree_add_uint(hdr_tree, hf_ieee80211_fc_analysis_retransmission_frame,tvb, 0, 0, fnum);
PROTO_ITEM_SET_GENERATED(item);
}
next_tvb = tvb_new_subset (tvb, hdr_len, len, reported_len);
call_dissector(data_handle, next_tvb, pinfo, tree);
goto end_of_wlan;
}
}
break;
case CONTROL_FRAME:
goto end_of_wlan;
case EXTENSION_FRAME:
break;
default:
goto end_of_wlan;
}
if (IS_PROTECTED(FCF_FLAGS(fcf))
&& !phdr->decrypted
&& (wlan_ignore_wep != WLAN_IGNORE_WEP_WO_IV)) {
gboolean can_decrypt = FALSE;
proto_tree *wep_tree = NULL;
guint32 iv;
guint8 key, keybyte;
#define PROTECTION_ALG_WEP AIRPDCAP_KEY_TYPE_WEP
#define PROTECTION_ALG_TKIP AIRPDCAP_KEY_TYPE_TKIP
#define PROTECTION_ALG_CCMP AIRPDCAP_KEY_TYPE_CCMP
#define PROTECTION_ALG_RSNA PROTECTION_ALG_CCMP | PROTECTION_ALG_TKIP
guint8 algorithm=G_MAXUINT8;
#define IS_TKIP(tvb, hdr_len) (tvb_get_guint8(tvb, hdr_len + 1) == \
((tvb_get_guint8(tvb, hdr_len) | 0x20) & 0x7f))
#define IS_CCMP(tvb, hdr_len) (tvb_get_guint8(tvb, hdr_len + 2) == 0)
guint32 sec_header=0;
guint32 sec_trailer=0;
next_tvb = try_decrypt(tvb, hdr_len, reported_len, &algorithm, &sec_header, &sec_trailer, &used_key);
keybyte = tvb_get_guint8(tvb, hdr_len + 3);
key = KEY_OCTET_WEP_KEY(keybyte);
if ((keybyte & KEY_EXTIV) && (len >= EXTIV_LEN)) {
if (tree) {
if (algorithm==PROTECTION_ALG_TKIP)
wep_tree = proto_tree_add_subtree(hdr_tree, tvb, hdr_len, 8,
ett_wep_parameters, NULL, "TKIP parameters");
else if (algorithm==PROTECTION_ALG_CCMP)
wep_tree = proto_tree_add_subtree(hdr_tree, tvb, hdr_len, 8,
ett_wep_parameters, NULL, "CCMP parameters");
else {
if (IS_TKIP(tvb, hdr_len)) {
algorithm=PROTECTION_ALG_TKIP;
wep_tree = proto_tree_add_subtree(hdr_tree, tvb, hdr_len, 8,
ett_wep_parameters, NULL, "TKIP parameters");
} else if (IS_CCMP(tvb, hdr_len)) {
algorithm=PROTECTION_ALG_CCMP;
wep_tree = proto_tree_add_subtree(hdr_tree, tvb, hdr_len, 8,
ett_wep_parameters, NULL, "CCMP parameters");
} else
wep_tree = proto_tree_add_subtree(hdr_tree, tvb, hdr_len, 8,
ett_wep_parameters, NULL, "TKIP/CCMP parameters");
}
proto_item_set_len (ti, hdr_len + 8);
if (algorithm==PROTECTION_ALG_TKIP) {
g_snprintf(out_buff, SHORT_STR, "0x%08X%02X%02X",
tvb_get_letohl(tvb, hdr_len + 4),
tvb_get_guint8(tvb, hdr_len),
tvb_get_guint8(tvb, hdr_len + 2));
proto_tree_add_string(wep_tree, hf_ieee80211_tkip_extiv, tvb, hdr_len,
EXTIV_LEN, out_buff);
} else if (algorithm==PROTECTION_ALG_CCMP) {
g_snprintf(out_buff, SHORT_STR, "0x%08X%02X%02X",
tvb_get_letohl(tvb, hdr_len + 4),
tvb_get_guint8(tvb, hdr_len + 1),
tvb_get_guint8(tvb, hdr_len));
proto_tree_add_string(wep_tree, hf_ieee80211_ccmp_extiv, tvb, hdr_len,
EXTIV_LEN, out_buff);
}
proto_tree_add_uint(wep_tree, hf_ieee80211_wep_key, tvb, hdr_len + 3, 1, key);
}
len -= EXTIV_LEN;
reported_len -= EXTIV_LEN;
ivlen = EXTIV_LEN;
if (next_tvb!=NULL) {
if (reported_len < (gint) sec_trailer) {
;
} else if (len < reported_len) {
reported_len -= sec_trailer;
if (len > reported_len)
len = reported_len;
} else {
len -= sec_trailer;
reported_len -= sec_trailer;
can_decrypt = TRUE;
bytes_to_hexstr(out_buff, used_key.KeyData.Wpa.Ptk+32, AIRPDCAP_TK_LEN);
out_buff[2*AIRPDCAP_TK_LEN] = '\0';
if (key == 0) {
ti = proto_tree_add_string(wep_tree, hf_ieee80211_fc_analysis_tk, tvb, 0, 0, out_buff);
PROTO_ITEM_SET_GENERATED(ti);
bytes_to_hexstr(out_buff, used_key.KeyData.Wpa.Psk, AIRPDCAP_WPA_PSK_LEN);
out_buff[2*AIRPDCAP_WPA_PSK_LEN] = '\0';
ti = proto_tree_add_string(wep_tree, hf_ieee80211_fc_analysis_pmk, tvb, 0, 0, out_buff);
PROTO_ITEM_SET_GENERATED(ti);
} else {
ti = proto_tree_add_string(wep_tree, hf_ieee80211_fc_analysis_gtk, tvb, 0, 0, out_buff);
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
} else {
iv = tvb_get_ntoh24(tvb, hdr_len);
if (tree) {
wep_tree = proto_tree_add_subtree(hdr_tree, tvb, hdr_len, 4,
ett_wep_parameters, NULL, "WEP parameters");
proto_tree_add_uint (wep_tree, hf_ieee80211_wep_iv, tvb, hdr_len, 3, iv);
tvb_memcpy(tvb, iv_buff, hdr_len, 3);
is_iv_bad = weak_iv(iv_buff);
if (is_iv_bad != -1) {
proto_tree_add_boolean_format (wep_tree, hf_ieee80211_wep_iv_weak,
tvb, 0, 0, TRUE,
"Weak IV for key byte %d",
is_iv_bad);
}
}
if (tree)
proto_tree_add_uint (wep_tree, hf_ieee80211_wep_key, tvb, hdr_len + 3, 1, key);
len -= 4;
reported_len -= 4;
ivlen = 4;
algorithm=PROTECTION_ALG_WEP;
if (reported_len < 4) {
;
} else if (len < reported_len) {
reported_len -= 4;
if (len > reported_len)
len = reported_len;
} else {
len -= 4;
reported_len -= 4;
can_decrypt = TRUE;
}
}
if (algorithm == PROTECTION_ALG_WEP) {
g_strlcpy (wlan_stats.protection, "WEP", MAX_PROTECT_LEN);
} else if (algorithm == PROTECTION_ALG_TKIP) {
g_strlcpy (wlan_stats.protection, "TKIP", MAX_PROTECT_LEN);
} else if (algorithm == PROTECTION_ALG_CCMP) {
g_strlcpy (wlan_stats.protection, "CCMP", MAX_PROTECT_LEN);
} else {
g_strlcpy (wlan_stats.protection, "Unknown", MAX_PROTECT_LEN);
}
if (!can_decrypt || (next_tvb == NULL)) {
next_tvb = tvb_new_subset(tvb, hdr_len + ivlen, len, reported_len);
if (tree) {
if (algorithm == PROTECTION_ALG_WEP) {
if (can_decrypt)
proto_tree_add_uint_format_value(wep_tree, hf_ieee80211_wep_icv, tvb,
hdr_len + ivlen + len, 4,
tvb_get_ntohl(tvb, hdr_len + ivlen + len),
"0x%08x (not verified)",
tvb_get_ntohl(tvb, hdr_len + ivlen + len));
} else if (algorithm == PROTECTION_ALG_CCMP) {
} else if (algorithm == PROTECTION_ALG_TKIP) {
}
}
if ((!is_centrino) && (wlan_ignore_wep == WLAN_IGNORE_WEP_NO)) {
call_dissector(data_handle, next_tvb, pinfo, tree);
goto end_of_wlan;
}
} else {
if (algorithm == PROTECTION_ALG_WEP) {
if (tree)
proto_tree_add_uint_format_value(wep_tree, hf_ieee80211_wep_icv, tvb,
hdr_len + ivlen + len, 4,
tvb_get_ntohl(tvb, hdr_len + ivlen + len),
"0x%08x (correct)",
tvb_get_ntohl(tvb, hdr_len + ivlen + len));
add_new_data_source(pinfo, next_tvb, "Decrypted WEP data");
} else if (algorithm==PROTECTION_ALG_CCMP) {
add_new_data_source(pinfo, next_tvb, "Decrypted CCMP data");
} else if (algorithm==PROTECTION_ALG_TKIP) {
add_new_data_source(pinfo, next_tvb, "Decrypted TKIP data");
}
#undef IS_TKIP
#undef IS_CCMP
#undef PROTECTION_ALG_CCMP
#undef PROTECTION_ALG_TKIP
#undef PROTECTION_ALG_WEP
}
hdr_len = 0;
} else {
next_tvb = tvb;
}
save_fragmented = pinfo->fragmented;
if (wlan_defragment && (more_frags || (frag_number != 0))) {
fragment_head *fd_head;
if (reported_len < 0)
THROW(ReportedBoundsError);
fd_head = fragment_add_seq_802_11(&wlan_reassembly_table,
next_tvb, hdr_len, pinfo, seq_number, NULL,
frag_number,
reported_len,
more_frags);
next_tvb = process_reassembled_data(tvb, hdr_len, pinfo,
"Reassembled 802.11", fd_head,
&frag_items, NULL, hdr_tree);
} else {
if (frag_number != 0) {
next_tvb = NULL;
} else {
next_tvb = tvb_new_subset (next_tvb, hdr_len, len, reported_len);
if (more_frags)
pinfo->fragmented = TRUE;
else
pinfo->fragmented = FALSE;
}
}
if (next_tvb == NULL) {
col_set_str(pinfo->cinfo, COL_INFO, "Fragmented IEEE 802.11 frame");
next_tvb = tvb_new_subset (tvb, hdr_len, len, reported_len);
call_dissector(data_handle, next_tvb, pinfo, tree);
pinfo->fragmented = save_fragmented;
goto end_of_wlan;
}
switch (FCF_FRAME_TYPE (fcf))
{
case MGT_FRAME:
dissect_ieee80211_mgt (fcf, next_tvb, pinfo, tree);
break;
case DATA_FRAME:
if (is_amsdu && (tvb_reported_length_remaining(next_tvb, 0) > 4)) {
proto_item *parent_item;
proto_tree *mpdu_tree;
guint32 msdu_offset = 0;
guint i = 1;
parent_item = proto_tree_add_protocol_format(tree, proto_aggregate, next_tvb, 0,
tvb_reported_length_remaining(next_tvb, 0), "IEEE 802.11 Aggregate MSDU");
mpdu_tree = proto_item_add_subtree(parent_item, ett_msdu_aggregation_parent_tree);
do {
tvbuff_t *volatile msdu_tvb;
guint16 msdu_length;
proto_tree *subframe_tree;
msdu_length = tvb_get_ntohs (next_tvb, msdu_offset+12);
parent_item = proto_tree_add_item(mpdu_tree, hf_ieee80211_amsdu_subframe, next_tvb,
msdu_offset, roundup2(msdu_offset+14+msdu_length, 4), ENC_NA);
proto_item_append_text(parent_item, " #%u", i);
subframe_tree = proto_item_add_subtree(parent_item, ett_msdu_aggregation_subframe_tree);
i += 1;
proto_tree_add_item(subframe_tree, hf_ieee80211_addr_da, next_tvb, msdu_offset, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_da_resolved, tvb, msdu_offset, 6,
tvb_get_ether_name(tvb, msdu_offset));
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(subframe_tree, hf_ieee80211_addr_sa, next_tvb, msdu_offset+6, 6, ENC_NA);
hidden_item = proto_tree_add_string (hdr_tree, hf_ieee80211_addr_sa_resolved, tvb, msdu_offset+6, 6,
tvb_get_ether_name(tvb, msdu_offset+6));
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(subframe_tree, hf_ieee80211_amsdu_length, next_tvb, msdu_offset+12, 2, ENC_BIG_ENDIAN);
msdu_offset += 14;
msdu_tvb = tvb_new_subset_length(next_tvb, msdu_offset, msdu_length);
call_dissector(llc_handle, msdu_tvb, pinfo, subframe_tree);
msdu_offset = roundup2(msdu_offset+msdu_length, 4);
} while (tvb_reported_length_remaining(next_tvb, msdu_offset) > 14);
break;
}
encap_type = ENCAP_802_2;
if (tvb_bytes_exist(next_tvb, 0, 2)) {
octet1 = tvb_get_guint8(next_tvb, 0);
octet2 = tvb_get_guint8(next_tvb, 1);
if ((octet1 != 0xaa) || (octet2 != 0xaa)) {
if ((tvb_memeql(next_tvb, 6, (const guint8 *)pinfo->dl_src.data, 6) == 0) ||
(tvb_memeql(next_tvb, 0, (const guint8 *)pinfo->dl_dst.data, 6) == 0))
encap_type = ENCAP_ETHERNET;
else if ((octet1 == 0xff) && (octet2 == 0xff))
encap_type = ENCAP_IPX;
else if ((octet1 == 0x00) && (octet2 == 0x00)) {
proto_tree_add_item(tree, hf_ieee80211_mysterious_olpc_stuff, next_tvb, 0, 2, ENC_NA);
next_tvb = tvb_new_subset_remaining (next_tvb, 2);
}
}
}
switch (encap_type) {
case ENCAP_802_2:
call_dissector(llc_handle, next_tvb, pinfo, tree);
break;
case ENCAP_ETHERNET:
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
break;
case ENCAP_IPX:
call_dissector(ipx_handle, next_tvb, pinfo, tree);
break;
}
break;
case EXTENSION_FRAME:
{
dissect_ieee80211_extension(fcf, next_tvb, pinfo, tree);
break;
}
}
pinfo->fragmented = save_fragmented;
end_of_wlan:
whdr->stats = wlan_stats;
tap_queue_packet(wlan_tap, pinfo, whdr);
memset (&wlan_stats, 0, sizeof wlan_stats);
return tvb_captured_length(tvb);
}
static int
dissect_ieee80211 (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct ieee_802_11_phdr *phdr = (struct ieee_802_11_phdr *)data;
struct ieee_802_11_phdr ourphdr;
if (phdr == NULL) {
ourphdr.fcs_len = -1;
ourphdr.decrypted = FALSE;
ourphdr.datapad = FALSE;
ourphdr.phy = PHDR_802_11_PHY_UNKNOWN;
ourphdr.presence_flags = 0;
phdr = &ourphdr;
}
return dissect_ieee80211_common (tvb, pinfo, tree, FALSE, FALSE, phdr);
}
static void
dissect_ieee80211_withfcs (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
struct ieee_802_11_phdr phdr;
phdr.fcs_len = 4;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
phdr.presence_flags = 0;
dissect_ieee80211_common (tvb, pinfo, tree, FALSE, FALSE, &phdr);
}
static void
dissect_ieee80211_withoutfcs (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
struct ieee_802_11_phdr phdr;
phdr.fcs_len = 0;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
phdr.presence_flags = 0;
dissect_ieee80211_common (tvb, pinfo, tree, FALSE, FALSE, &phdr);
}
static void
dissect_ieee80211_centrino(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
struct ieee_802_11_phdr phdr;
phdr.fcs_len = 0;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
phdr.presence_flags = 0;
dissect_ieee80211_common (tvb, pinfo, tree, FALSE, TRUE, &phdr);
}
static void
dissect_ieee80211_bsfc (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
struct ieee_802_11_phdr phdr;
phdr.fcs_len = 0;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
phdr.presence_flags = 0;
dissect_ieee80211_common (tvb, pinfo, tree, TRUE, FALSE, &phdr);
}
static void
wlan_defragment_init(void)
{
reassembly_table_init(&wlan_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
wlan_defragment_cleanup(void)
{
reassembly_table_destroy(&wlan_reassembly_table);
}
static guint
retransmit_hash(gconstpointer k)
{
const retransmit_key *key = (const retransmit_key *)k;
guint hash_val;
int i;
hash_val = 0;
for (i = 0; i < 6; i++)
hash_val += key->bssid[i];
for (i = 0; i < 6; i++)
hash_val += key->src[i];
return hash_val;
}
static gint
retransmit_equal(gconstpointer k1, gconstpointer k2)
{
const retransmit_key *key1 = (const retransmit_key *)k1;
const retransmit_key *key2 = (const retransmit_key *)k2;
return ((!memcmp(key1->bssid, key2->bssid, 6) && !memcmp(key1->src, key2->src, 6)) ? TRUE:FALSE);
}
static guint
frame_hash(gconstpointer k)
{
guint32 frame = GPOINTER_TO_UINT(k);
return frame;
}
static gint
frame_equal(gconstpointer k1, gconstpointer k2)
{
guint32 frame1 = GPOINTER_TO_UINT(k1);
guint32 frame2 = GPOINTER_TO_UINT(k2);
return frame1==frame2;
}
static int
dissect_wlan_rsna_eapol_wpa_or_rsn_key(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean is_rsn)
{
int offset = 0;
guint16 keyinfo;
guint16 eapol_data_len;
proto_tree *keyinfo_item = NULL;
proto_tree *keyinfo_tree = NULL;
proto_tree *keydes_tree;
proto_tree *ti = NULL;
guint32 start_nonce;
keyinfo = tvb_get_ntohs(tvb, offset);
if (keyinfo & KEY_INFO_REQUEST_MASK) {
col_set_str(pinfo->cinfo, COL_INFO, "Key (Request)");
if (keyinfo & KEY_INFO_ERROR_MASK)
col_set_str(pinfo->cinfo, COL_INFO, "Key (Request, Error)");
} else if (keyinfo & KEY_INFO_KEY_TYPE_MASK) {
guint16 masked;
masked = keyinfo &
(KEY_INFO_INSTALL_MASK | KEY_INFO_KEY_ACK_MASK |
KEY_INFO_KEY_MIC_MASK | KEY_INFO_SECURE_MASK);
if (!is_rsn) {
switch (masked) {
case KEY_INFO_KEY_ACK_MASK:
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 1 of 4)");
break;
case KEY_INFO_KEY_MIC_MASK:
start_nonce = tvb_get_ntohl(tvb, offset+12);
if (start_nonce)
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 2 of 4)");
else
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 4 of 4)");
break;
case (KEY_INFO_INSTALL_MASK | KEY_INFO_KEY_ACK_MASK | KEY_INFO_KEY_MIC_MASK):
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 3 of 4)");
break;
}
} else {
switch (masked) {
case KEY_INFO_KEY_ACK_MASK:
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 1 of 4)");
break;
case KEY_INFO_KEY_MIC_MASK:
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 2 of 4)");
break;
case (KEY_INFO_INSTALL_MASK | KEY_INFO_KEY_ACK_MASK | KEY_INFO_KEY_MIC_MASK | KEY_INFO_SECURE_MASK):
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 3 of 4)");
break;
case (KEY_INFO_KEY_MIC_MASK | KEY_INFO_SECURE_MASK):
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 4 of 4)");
break;
}
}
} else {
if (keyinfo & KEY_INFO_KEY_ACK_MASK)
col_set_str(pinfo->cinfo, COL_INFO, "Key (Group Message 1 of 2)");
else
col_set_str(pinfo->cinfo, COL_INFO, "Key (Group Message 2 of 2)");
}
keyinfo_item =
proto_tree_add_item(tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo, tvb,
offset, 2, ENC_BIG_ENDIAN);
keyinfo_tree = proto_item_add_subtree(keyinfo_item, ett_keyinfo);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_keydes_version, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_key_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_key_index, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_install, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_key_ack, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_key_mic, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_secure, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_error, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_request, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_encrypted_key_data, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_wlan_rsna_eapol_wpa_keydes_keyinfo_smk_message, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_wlan_rsna_eapol_keydes_key_len, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_wlan_rsna_eapol_keydes_replay_counter, tvb,
offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_wlan_rsna_eapol_wpa_keydes_nonce, tvb, offset,
32, ENC_NA);
offset += 32;
proto_tree_add_item(tree, hf_wlan_rsna_eapol_keydes_key_iv, tvb,
offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_wlan_rsna_eapol_wpa_keydes_rsc, tvb, offset,
8, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_wlan_rsna_eapol_wpa_keydes_id, tvb, offset, 8,
ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_wlan_rsna_eapol_wpa_keydes_mic, tvb, offset,
16, ENC_NA);
offset += 16;
eapol_data_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_wlan_rsna_eapol_wpa_keydes_data_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (eapol_data_len != 0) {
ti = proto_tree_add_item(tree, hf_wlan_rsna_eapol_wpa_keydes_data,
tvb, offset, eapol_data_len, ENC_NA);
if ((keyinfo & KEY_INFO_ENCRYPTED_KEY_DATA_MASK) ||
!(keyinfo & KEY_INFO_KEY_TYPE_MASK)) {
} else {
keydes_tree = proto_item_add_subtree(ti, ett_wlan_rsna_eapol_keydes_data);
ieee_80211_add_tagged_parameters(tvb, offset, pinfo, keydes_tree,
tvb_reported_length_remaining(tvb, offset),
-1);
}
}
return tvb_captured_length(tvb);
}
static int
dissect_wlan_rsna_eapol_wpa_key(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_wlan_rsna_eapol_wpa_or_rsn_key(tvb, pinfo, tree, FALSE);
}
static int
dissect_wlan_rsna_eapol_rsn_key(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_wlan_rsna_eapol_wpa_or_rsn_key(tvb, pinfo, tree, TRUE);
}
static tvbuff_t *
try_decrypt(tvbuff_t *tvb, guint offset, guint len, guint8 *algorithm, guint32 *sec_header, guint32 *sec_trailer, PAIRPDCAP_KEY_ITEM used_key)
{
const guint8 *enc_data;
tvbuff_t *decr_tvb = NULL;
guint32 dec_caplen;
guchar dec_data[AIRPDCAP_MAX_CAPLEN];
if (!enable_decryption)
return NULL;
enc_data = tvb_get_ptr(tvb, 0, len+offset);
if (AirPDcapPacketProcess(&airpdcap_ctx, enc_data, offset, offset+len, dec_data, &dec_caplen,
used_key, FALSE, TRUE)==AIRPDCAP_RET_SUCCESS)
{
guint8 *tmp;
*algorithm=used_key->KeyType;
switch (*algorithm) {
case AIRPDCAP_KEY_TYPE_WEP:
*sec_header=AIRPDCAP_WEP_HEADER;
*sec_trailer=AIRPDCAP_WEP_TRAILER;
break;
case AIRPDCAP_KEY_TYPE_CCMP:
*sec_header=AIRPDCAP_RSNA_HEADER;
*sec_trailer=AIRPDCAP_CCMP_TRAILER;
break;
case AIRPDCAP_KEY_TYPE_TKIP:
*sec_header=AIRPDCAP_RSNA_HEADER;
*sec_trailer=AIRPDCAP_TKIP_TRAILER;
break;
default:
return NULL;
}
tmp = (guint8 *)g_memdup(dec_data+offset, dec_caplen-offset);
len = dec_caplen-offset;
decr_tvb = tvb_new_child_real_data(tvb, tmp, len, len);
tvb_set_free_cb(decr_tvb, g_free);
}
return decr_tvb;
}
static void
set_airpdcap_keys(void)
{
AIRPDCAP_KEYS_COLLECTION keys;
GByteArray *bytes = NULL;
guint i;
keys.nKeys = 0;
for (i = 0; (uat_wep_key_records != NULL) && (i < num_wepkeys_uat) && (i < MAX_ENCRYPTION_KEYS); i++)
{
decryption_key_t *dk;
dk = parse_key_string(uat_wep_key_records[i].string, uat_wep_key_records[i].key);
if (dk != NULL)
{
AIRPDCAP_KEY_ITEM key;
if (dk->type == AIRPDCAP_KEY_TYPE_WEP)
{
gboolean res;
key.KeyType = AIRPDCAP_KEY_TYPE_WEP;
bytes = g_byte_array_new();
res = hex_str_to_bytes(dk->key->str, bytes, FALSE);
if (dk->key->str && res && (bytes->len > 0) && (bytes->len <= AIRPDCAP_WEP_KEY_MAXLEN))
{
memcpy(key.KeyData.Wep.WepKey, bytes->data, bytes->len);
key.KeyData.Wep.WepKeyLen = bytes->len;
keys.Keys[keys.nKeys] = key;
keys.nKeys += 1;
}
}
else if (dk->type == AIRPDCAP_KEY_TYPE_WPA_PWD)
{
key.KeyType = AIRPDCAP_KEY_TYPE_WPA_PWD;
g_strlcpy(key.UserPwd.Passphrase, dk->key->str, AIRPDCAP_WPA_PASSPHRASE_MAX_LEN+1);
key.UserPwd.SsidLen = 0;
if ((dk->ssid != NULL) && (dk->ssid->len <= AIRPDCAP_WPA_SSID_MAX_LEN))
{
memcpy(key.UserPwd.Ssid, dk->ssid->data, dk->ssid->len);
key.UserPwd.SsidLen = dk->ssid->len;
}
keys.Keys[keys.nKeys] = key;
keys.nKeys += 1;
}
else if (dk->type == AIRPDCAP_KEY_TYPE_WPA_PSK)
{
key.KeyType = AIRPDCAP_KEY_TYPE_WPA_PSK;
bytes = g_byte_array_new();
hex_str_to_bytes(dk->key->str, bytes, FALSE);
if (bytes->len <= AIRPDCAP_WPA_PSK_LEN) {
memcpy(key.KeyData.Wpa.Psk, bytes->data, bytes->len);
keys.Keys[keys.nKeys] = key;
keys.nKeys += 1;
}
}
free_key_string(dk);
if (bytes) {
g_byte_array_free(bytes, TRUE);
bytes = NULL;
}
}
}
AirPDcapSetKeys(&airpdcap_ctx, keys.Keys, keys.nKeys);
}
static void
init_wepkeys(void)
{
set_airpdcap_keys();
}
static int
weak_iv(guchar *iv)
{
guchar sum, k;
if ((iv[1] == 255) && (iv[0] > 2) && (iv[0] < 16)) {
return iv[0] -3;
}
sum = iv[0] + iv[1];
if (sum == 1) {
if (iv[2] <= 0x0a) {
return iv[2] +2;
}
else if (iv[2] == 0xff) {
return 0;
}
}
k = 0xfe - iv[2];
if ((sum == k) && ((iv[2] >= 0xf2) && (iv[2] <= 0xfe) && (iv[2] != 0xfd))) {
return k;
}
return -1;
}
static void
wlan_retransmit_init(void)
{
if (fc_analyse_retransmit_table) {
g_hash_table_destroy(fc_analyse_retransmit_table);
fc_analyse_retransmit_table = NULL;
}
if (fc_first_frame_table) {
g_hash_table_destroy(fc_first_frame_table);
fc_first_frame_table = NULL;
}
if (wlan_subdissector)
return;
fc_analyse_retransmit_table= g_hash_table_new(retransmit_hash, retransmit_equal);
fc_first_frame_table = g_hash_table_new(frame_hash, frame_equal);
}
static void
dissect_data_encap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 type;
int tagged_parameter_tree_len;
proto_tree *tagged_tree;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_data_encap_payload_type, tvb, offset,
1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (type) {
case 1:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RRB");
break;
case 2:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TDLS");
col_clear(pinfo->cinfo, COL_INFO);
offset += add_fixed_field(tree, tvb, pinfo, offset, FIELD_ACTION);
tagged_parameter_tree_len = tvb_reported_length_remaining(tvb, offset);
if (tagged_parameter_tree_len > 0) {
tagged_tree = get_tagged_parameter_tree(tree, tvb, offset,
tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters(tvb, offset, pinfo, tagged_tree,
tagged_parameter_tree_len, -1);
}
break;
}
}
void
proto_register_ieee80211 (void)
{
static hf_register_info hf[] = {
{&hf_ieee80211_fc_field,
{"Frame Control Field", "wlan.fc",
FT_UINT16, BASE_HEX, NULL, 0,
"MAC Frame control", HFILL }},
{&hf_ieee80211_fc_proto_version,
{"Version", "wlan.fc.version",
FT_UINT8, BASE_DEC, NULL, 0x03,
"MAC Protocol version", HFILL }},
{&hf_ieee80211_fc_frame_type,
{"Type", "wlan.fc.type",
FT_UINT8, BASE_DEC, VALS(frame_type), 0x0C,
"Frame type", HFILL }},
{&hf_ieee80211_fc_frame_subtype,
{"Subtype", "wlan.fc.subtype",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Frame subtype", HFILL }},
{&hf_ieee80211_fc_frame_type_subtype,
{"Type/Subtype", "wlan.fc.type_subtype",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &frame_type_subtype_vals_ext, 0x0,
"Type and subtype combined (first byte: type, second byte: subtype)", HFILL }},
{&hf_ieee80211_fc_frame_extension,
{"Control Frame Extension", "wlan.fc.extension",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_fc_flags,
{"Flags", "wlan.flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_fc_data_ds,
{"DS status", "wlan.fc.ds",
FT_UINT8, BASE_HEX, VALS(tofrom_ds), (FLAG_FROM_DS|FLAG_TO_DS),
"Data-frame DS-traversal status", HFILL }},
{&hf_ieee80211_fc_to_ds,
{"To DS", "wlan.fc.tods",
FT_BOOLEAN, 8, TFS (&tods_flag), FLAG_TO_DS,
"To DS flag", HFILL }},
{&hf_ieee80211_fc_from_ds,
{"From DS", "wlan.fc.fromds",
FT_BOOLEAN, 8, TFS (&fromds_flag), FLAG_FROM_DS,
"From DS flag", HFILL }},
{&hf_ieee80211_fc_more_frag,
{"More Fragments", "wlan.fc.frag",
FT_BOOLEAN, 8, TFS (&more_fragments), FLAG_MORE_FRAGMENTS,
"More Fragments flag", HFILL }},
{&hf_ieee80211_fc_retry,
{"Retry", "wlan.fc.retry",
FT_BOOLEAN, 8, TFS (&retry_flags), FLAG_RETRY,
"Retransmission flag", HFILL }},
{ &hf_ieee80211_fc_analysis_retransmission,
{"Retransmission", "wlan.analysis.retransmission",
FT_NONE, BASE_NONE, NULL, 0x0,
"This frame is a suspected wireless retransmission", HFILL }},
{ &hf_ieee80211_fc_analysis_retransmission_frame,
{"Retransmission of frame", "wlan.analysis.retransmission_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a retransmission of frame #", HFILL }},
{&hf_ieee80211_fc_pwr_mgt,
{"PWR MGT", "wlan.fc.pwrmgt",
FT_BOOLEAN, 8, TFS (&pm_flags), FLAG_POWER_MGT,
"Power management status", HFILL }},
{&hf_ieee80211_fc_more_data,
{"More Data", "wlan.fc.moredata",
FT_BOOLEAN, 8, TFS (&md_flags), FLAG_MORE_DATA,
"More data flag", HFILL }},
{&hf_ieee80211_fc_protected,
{"Protected flag", "wlan.fc.protected",
FT_BOOLEAN, 8, TFS (&protected_flags), FLAG_PROTECTED,
NULL, HFILL }},
{&hf_ieee80211_fc_order,
{"Order flag", "wlan.fc.order",
FT_BOOLEAN, 8, TFS (&order_flags), FLAG_ORDER,
"Strictly ordered flag", HFILL }},
{&hf_ieee80211_assoc_id,
{"Association ID","wlan.aid"
,FT_UINT16, BASE_DEC, NULL, 0x3FFF,
"Association-ID field", HFILL }},
{&hf_ieee80211_did_duration,
{"Duration", "wlan.duration",
FT_UINT16, BASE_DEC, NULL, 0x7FFF,
"Duration field", HFILL }},
{&hf_ieee80211_addr_da,
{"Destination address", "wlan.da",
FT_ETHER, BASE_NONE, NULL, 0,
"Destination Hardware Address", HFILL }},
{ &hf_ieee80211_addr_da_resolved,
{"Destination address (resolved)", "wlan.da_resolved", FT_STRING,
BASE_NONE, NULL, 0x0, "Destination Hardware Address (resolved)",
HFILL }},
{&hf_ieee80211_addr_sa,
{"Source address", "wlan.sa",
FT_ETHER, BASE_NONE, NULL, 0,
"Source Hardware Address", HFILL }},
{ &hf_ieee80211_addr_sa_resolved,
{"Source address (resolved)", "wlan.sa_resolved", FT_STRING, BASE_NONE,
NULL, 0x0, "Source Hardware Address (resolved)", HFILL }},
{ &hf_ieee80211_addr,
{"Hardware address", "wlan.addr",
FT_ETHER, BASE_NONE, NULL, 0,
"SA, DA, BSSID, RA or TA Hardware Address", HFILL }},
{ &hf_ieee80211_addr_resolved,
{ "Hardware address (resolved)", "wlan.addr_resolved", FT_STRING,
BASE_NONE, NULL, 0x0,
"SA, DA, BSSID, RA or TA Hardware Address (resolved)", HFILL }},
{&hf_ieee80211_addr_ra,
{"Receiver address", "wlan.ra",
FT_ETHER, BASE_NONE, NULL, 0,
"Receiving Station Hardware Address", HFILL }},
{ &hf_ieee80211_addr_ra_resolved,
{"Receiver address (resolved)", "wlan.ra_resolved", FT_STRING, BASE_NONE,
NULL, 0x0, "Receiving Station Hardware Address (resolved)", HFILL }},
{&hf_ieee80211_addr_ta,
{"Transmitter address", "wlan.ta",
FT_ETHER, BASE_NONE, NULL, 0,
"Transmitting Station Hardware Address", HFILL }},
{ &hf_ieee80211_addr_ta_resolved,
{"Transmitter address (resolved)", "wlan.ta_resolved", FT_STRING,
BASE_NONE, NULL, 0x0,
"Transmitting Station Hardware Address (resolved)", HFILL }},
{&hf_ieee80211_addr_bssid,
{"BSS Id", "wlan.bssid",
FT_ETHER, BASE_NONE, NULL, 0,
"Basic Service Set ID", HFILL }},
{ &hf_ieee80211_addr_bssid_resolved,
{"BSS Id (resolved)", "wlan.bssid_resolved", FT_STRING, BASE_NONE, NULL,
0x0, "Basic Service Set ID (resolved)", HFILL }},
{&hf_ieee80211_addr_staa,
{"STA address", "wlan.staa",
FT_ETHER, BASE_NONE, NULL, 0,
"Station Hardware Address", HFILL }},
{ &hf_ieee80211_addr_staa_resolved,
{"STA address (resolved)", "wlan.staa_resolved", FT_STRING, BASE_NONE, NULL,
0x0, "Station Hardware Address (resolved)", HFILL }},
{&hf_ieee80211_frag_number,
{"Fragment number", "wlan.frag",
FT_UINT16, BASE_DEC, NULL, 0x000F,
NULL, HFILL }},
{&hf_ieee80211_seq_number,
{"Sequence number", "wlan.seq",
FT_UINT16, BASE_DEC, NULL, 0xFFF0,
NULL, HFILL }},
{&hf_ieee80211_mesh_control_field,
{"Mesh Control Field", "wlan.mesh.control_field",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qos,
{"Qos Control", "wlan.qos",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qos_tid,
{"TID", "wlan.qos.tid",
FT_UINT16, BASE_DEC, NULL, 0x000F,
NULL, HFILL }},
{&hf_ieee80211_qos_priority,
{"Priority", "wlan.qos.priority",
FT_UINT16, BASE_DEC, VALS(ieee80211_qos_tags_acs), 0x0007,
"802.1D Tag", HFILL }},
{&hf_ieee80211_qos_eosp,
{"EOSP", "wlan.qos.eosp",
FT_BOOLEAN, 16, TFS (&eosp_flag), QOS_FLAG_EOSP,
"EOSP Field", HFILL }},
{&hf_ieee80211_qos_bit4,
{"QoS bit 4", "wlan.qos.bit4",
FT_BOOLEAN, 16, TFS (&bit4_flag), QOS_FLAG_EOSP,
NULL, HFILL }},
{&hf_ieee80211_qos_ack_policy,
{"Ack Policy", "wlan.qos.ack",
FT_UINT16, BASE_HEX, VALS(ack_policy), 0x0060,
NULL, HFILL }},
{&hf_ieee80211_qos_amsdu_present,
{"Payload Type", "wlan.qos.amsdupresent",
FT_BOOLEAN, 16,
TFS(&ieee80211_qos_amsdu_present_flag), 0x0080, NULL, HFILL }},
{&hf_ieee80211_qos_txop_limit,
{"TXOP Limit", "wlan.qos.txop_limit",
FT_UINT16, BASE_DEC, NULL, 0xFF00,
NULL, HFILL }},
{&hf_ieee80211_qos_ps_buf_state,
{"QAP PS Buffer State", "wlan.qos.ps_buf_state",
FT_UINT16, BASE_HEX, NULL, 0xFF00,
NULL, HFILL }},
{&hf_ieee80211_qos_buf_state_indicated,
{"Buffer State Indicated", "wlan.qos.buf_state_indicated",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0200,
NULL, HFILL }},
{&hf_ieee80211_qos_highest_pri_buf_ac,
{"Highest-Priority Buffered AC", "wlan.qos.highest_pri_buf_ac",
FT_UINT16, BASE_DEC, VALS(wme_acs), 0x0C00,
NULL, HFILL }},
{&hf_ieee80211_qos_qap_buf_load,
{"QAP Buffered Load", "wlan.qos.qap_buf_load",
FT_UINT16, BASE_DEC, NULL, 0xF000,
NULL, HFILL }},
{&hf_ieee80211_qos_txop_dur_req,
{"TXOP Duration Requested", "wlan.qos.txop_dur_req",
FT_UINT16, BASE_DEC, NULL, 0xFF00,
NULL, HFILL }},
{&hf_ieee80211_qos_queue_size,
{"Queue Size", "wlan.qos.queue_size",
FT_UINT16, BASE_DEC, NULL, 0xFF00,
NULL, HFILL }},
{&hf_ieee80211_fcs,
{"Frame check sequence", "wlan.fcs",
FT_UINT32, BASE_HEX, NULL, 0,
"Frame Check Sequence (FCS)", HFILL }},
{&hf_ieee80211_fcs_good,
{"Good", "wlan.fcs_good",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True if the FCS is correct", HFILL }},
{&hf_ieee80211_fcs_bad,
{"Bad", "wlan.fcs_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True if the FCS is incorrect", HFILL }},
{&hf_ieee80211_fragment_overlap,
{"Fragment overlap", "wlan.fragment.overlap",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{&hf_ieee80211_fragment_overlap_conflict,
{"Conflicting data in fragment overlap", "wlan.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{&hf_ieee80211_fragment_multiple_tails,
{"Multiple tail fragments found", "wlan.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{&hf_ieee80211_fragment_too_long_fragment,
{"Fragment too long", "wlan.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{&hf_ieee80211_fragment_error,
{"Defragmentation error", "wlan.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{&hf_ieee80211_fragment_count,
{"Fragment count", "wlan.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_fragment,
{"802.11 Fragment", "wlan.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_fragments,
{"802.11 Fragments", "wlan.fragments",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_reassembled_in,
{"Reassembled 802.11 in frame", "wlan.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This 802.11 packet is reassembled in this frame", HFILL }},
{&hf_ieee80211_reassembled_length,
{"Reassembled 802.11 length", "wlan.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{&hf_ieee80211_wep_iv,
{"Initialization Vector", "wlan.wep.iv",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wep_iv_weak,
{"Weak IV", "wlan.wep.weakiv",
FT_BOOLEAN, BASE_NONE, NULL,0x0,
NULL,HFILL}},
{&hf_ieee80211_tkip_extiv,
{"TKIP Ext. Initialization Vector", "wlan.tkip.extiv",
FT_STRING, BASE_NONE, NULL, 0,
"TKIP Extended Initialization Vector", HFILL }},
{&hf_ieee80211_ccmp_extiv,
{"CCMP Ext. Initialization Vector", "wlan.ccmp.extiv",
FT_STRING, BASE_NONE, NULL, 0,
"CCMP Extended Initialization Vector", HFILL }},
{&hf_ieee80211_wep_key,
{"Key Index", "wlan.wep.key",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wep_icv,
{"WEP ICV", "wlan.wep.icv",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_fc_analysis_pmk,
{"PMK", "wlan.analysis.pmk",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_fc_analysis_tk,
{"TK", "wlan.analysis.tk",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_fc_analysis_gtk,
{"GTK", "wlan.analysis.gtk",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_block_ack_request_control,
{"Block Ack Request (BAR) Control", "wlan.bar.control",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_block_ack_control,
{"Block Ack Request Control", "wlan.ba.control",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_block_ack_control_ack_policy,
{"BAR Ack Policy", "wlan.ba.control.ackpolicy",
FT_BOOLEAN, 16, TFS (&ieee80211_block_ack_control_ack_policy_flag), 0x01,
"Block Ack Request (BAR) Ack Policy", HFILL }},
{&hf_ieee80211_block_ack_control_multi_tid,
{"Multi-TID", "wlan.ba.control.multitid",
FT_BOOLEAN, 16, 0, 0x02,
"Multi-Traffic Identifier (TID)", HFILL }},
{&hf_ieee80211_block_ack_control_compressed_bitmap,
{"Compressed Bitmap", "wlan.ba.control.cbitmap",
FT_BOOLEAN, 16, 0, 0x04,
NULL, HFILL }},
{&hf_ieee80211_block_ack_control_reserved,
{"Reserved", "wlan.ba.control.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0ff8,
NULL, HFILL }},
{&hf_ieee80211_block_ack_control_basic_tid_info,
{"TID for which a Basic BlockAck frame is requested", "wlan.ba.basic.tidinfo",
FT_UINT16, BASE_HEX, NULL, 0xf000,
"Traffic Identifier (TID) for which a Basic BlockAck frame is requested", HFILL }},
{&hf_ieee80211_block_ack_control_compressed_tid_info,
{"TID for which a BlockAck frame is requested", "wlan.bar.compressed.tidinfo",
FT_UINT16, BASE_HEX, NULL, 0xf000,
"Traffic Identifier (TID) for which a BlockAck frame is requested", HFILL }},
{&hf_ieee80211_block_ack_control_multi_tid_info,
{"Number of TIDs Present", "wlan.ba.mtid.tidinfo",
FT_UINT16, BASE_HEX, NULL, 0xf000,
"Number of Traffic Identifiers (TIDs) Present", HFILL }},
{&hf_ieee80211_block_ack_multi_tid_info,
{"Traffic Identifier (TID) Info", "wlan.ba.mtid.tid",
FT_UINT8, BASE_DEC, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_block_ack_multi_tid_reserved,
{"Reserved", "wlan.bar.mtid.tidinfo.reserved",
FT_UINT16, BASE_HEX, 0, 0x0fff,
NULL, HFILL }},
{&hf_ieee80211_block_ack_multi_tid_value,
{"Multi-TID Value", "wlan.bar.mtid.tidinfo.value",
FT_UINT16, BASE_HEX, 0, 0xf000,
NULL, HFILL }},
{&hf_ieee80211_block_ack_request_type,
{"Block Ack Request Type", "wlan.bar.type",
FT_UINT8, BASE_HEX, VALS(ieee80211_block_ack_request_type_flags), 0x06,
"Block Ack Request (BAR) Type", HFILL }},
{&hf_ieee80211_block_ack_type,
{"Block Ack Type", "wlan.ba.type",
FT_UINT8, BASE_HEX, VALS(ieee80211_block_ack_type_flags), 0x06,
NULL, HFILL }},
{&hf_ieee80211_block_ack_bitmap,
{"Block Ack Bitmap", "wlan.ba.bm",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_block_ack_RBUFCAP,
{"Block Ack RBUFCAP", "wlan.ba.RBUFCAP",
FT_BOOLEAN, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_block_ack_bitmap_missing_frame,
{"Missing frame", "wlan.ba.bm.missing_frame",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_beamform_feedback_seg_retrans_bitmap,
{"Feedback segment Retansmission Bitmap", "wlan.beamform.feedback_seg_retrans_bitmap",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_ndp_annc_token,
{"Sounding Dialog Token", "wlan.vht_ndp.token",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_ndp_annc_token_number,
{"Sounding Dialog Token Number", "wlan.vht_ndp.token.number",
FT_UINT8, BASE_DEC, NULL, 0xFC,
NULL, HFILL }},
{&hf_ieee80211_vht_ndp_annc_token_reserved,
{"Reserved", "wlan.vht_ndp.token.reserved",
FT_UINT8, BASE_HEX, NULL, 0x03,
NULL, HFILL }},
{&hf_ieee80211_vht_ndp_annc_sta_info,
{"STA Info", "wlan.vht_ndp.sta_info",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_ndp_annc_sta_info_aid12,
{"AID12", "wlan.vht_ndp.sta_info.aid12",
FT_UINT16, BASE_HEX, NULL, 0x0FFF,
"12 least significant bits of the AID of the target STA", HFILL }},
{&hf_ieee80211_vht_ndp_annc_sta_info_feedback_type,
{"Feedback Type", "wlan.vht_ndp.sta_info.feedback_type",
FT_BOOLEAN, 16, TFS(&vht_ndp_annc_sta_info_feedback_type), 0x1000,
NULL, HFILL }},
{&hf_ieee80211_vht_ndp_annc_sta_info_nc_index,
{"Nc Index", "wlan.vht_ndp.sta_info.nc_index",
FT_UINT16, BASE_DEC, VALS(num_plus_one_3bit_flag), 0xE000,
NULL, HFILL }},
{&hf_ieee80211_vht_ndp_annc_sta_info_reserved,
{"Reserved", "wlan.vht_ndp.sta_info.reserved",
FT_UINT16, BASE_HEX, NULL, 0xE000,
NULL, HFILL }},
{&hf_ieee80211_data_encap_payload_type,
{"Payload Type", "wlan.data_encap.payload_type",
FT_UINT8, BASE_DEC, VALS(ieee80211_data_encap_payload_types), 0,
NULL, HFILL }},
{&hf_ieee80211_ff_tdls_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &tdls_action_codes_ext, 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_target_channel,
{"Target Channel", "wlan_mgt.fixed.target_channel",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_operating_class,
{"Operating Class", "wlan_mgt.fixed.operating_class",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_wnm_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wnm_action_codes_ext, 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_unprotected_wnm_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &unprotected_wnm_action_codes_ext, 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_key_data,
{"Key Data", "wlan_mgt.fixed.key_data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_key_data_length,
{"Key Data Length", "wlan_mgt.fixed.key_data_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_wnm_notification_type,
{"WNM-Notification type", "wlan_mgt.fixed.wnm_notification_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wnm_notification_types_ext, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_rm_action_code,
{"Action code", "wlan_mgt.rm.action_code",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &rm_action_codes_ext, 0,
"Radio Measurement Action", HFILL }},
{&hf_ieee80211_ff_rm_dialog_token,
{"Dialog token", "wlan_mgt.rm.dialog_token",
FT_UINT8, BASE_DEC, NULL, 0,
"Non-zero Dialog Token identifies request/report transaction", HFILL }},
{&hf_ieee80211_ff_rm_repetitions,
{"Repetitions", "wlan_mgt.rm.repetitions",
FT_UINT16, BASE_DEC, NULL, 0,
"Numer of Repetitions, 65535 indicates repeat until cancellation", HFILL }},
{&hf_ieee80211_ff_rm_tx_power,
{"Transmit Power Used", "wlan_mgt.rm.tx_power",
FT_INT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_rm_max_tx_power,
{"Max Transmit Power", "wlan_mgt.rm.max_tx_power",
FT_INT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_tpc,
{"TPC Report", "wlan_mgt.rm.tpc",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_tpc_element_id,
{"TPC Element ID", "wlan_mgt.rm.tpc.element_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_tpc_length,
{"TPC Length", "wlan_mgt.rm.tpc.length",
FT_UINT8, BASE_DEC, NULL, 0,
"Length of TPC Report element (always 2)", HFILL }},
{&hf_ieee80211_ff_tpc_tx_power,
{"TPC Transmit Power", "wlan_mgt.rm.tpc.tx_power",
FT_INT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_tpc_link_margin,
{"TPC Link Margin", "wlan_mgt.rm.tpc.link_margin",
FT_INT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_rm_rx_antenna_id,
{"Receive Antenna ID", "wlan_mgt.rm.rx_antenna_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_rm_tx_antenna_id,
{"Transmit Antenna ID", "wlan_mgt.rm.tx_antenna_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_rm_rcpi,
{"Received Channel Power", "wlan_mgt.rm.rcpi",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_rm_rsni,
{"Received Signal to noise indication", "wlan_mgt.rm.rsni",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_request_mode_pref_cand,
{"Preferred Candidate List Included","wlan_mgt.fixed.request_mode.pref_cand",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_request_mode_abridged,
{"Abridged", "wlan_mgt.fixed.request_mode.abridged",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL }},
{&hf_ieee80211_ff_request_mode_disassoc_imminent,
{"Disassociation Imminent", "wlan_mgt.fixed.request_mode.disassoc_imminent",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }},
{&hf_ieee80211_ff_request_mode_bss_term_included,
{"BSS Termination Included", "wlan_mgt.fixed.request_mode.bss_term_included",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }},
{&hf_ieee80211_ff_request_mode_ess_disassoc_imminent,
{"ESS Disassociation Imminent", "wlan_mgt.fixed.request_mode.ess_disassoc_imminent",
FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL }},
{&hf_ieee80211_ff_disassoc_timer,
{"Disassociation Timer", "wlan_mgt.fixed.disassoc_timer",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_validity_interval,
{"Validity Interval", "wlan_mgt.fixed.validity_interval",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_bss_termination_duration,
{"BSS Termination Duration", "wlan_mgt.fixed.bss_termination_duration",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_url_len,
{"Session Information URL Length",
"wlan_mgt.fixed.session_information.url_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_url,
{"Session Information URL", "wlan_mgt.fixed.session_information.url",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_bss_transition_candidate_list_entries,
{"BSS Transition Candidate List Entries", "wlan_mgt.fixed.bss_transition_candidate_list_entries",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_cf_response_offset,
{"Response Offset", "wlan.res_offset",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_dynamic_allocation,
{"Response Offset", "wlan.dynamic_allocation",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_TID,
{"Response Offset", "wlan.dynamic_allocation.TID",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }},
{&hf_ieee80211_ff_alloc_type,
{"Response Offset", "wlan.dynamic_allocation.alloc_type",
FT_UINT8, BASE_DEC, NULL, 0x70,
NULL, HFILL }},
{&hf_ieee80211_ff_src_aid,
{"Response Offset", "wlan.dynamic_allocation.src_aid",
FT_UINT16, BASE_DEC, NULL, 0x7f80,
NULL, HFILL }},
{&hf_ieee80211_ff_dest_aid,
{"Response Offset", "wlan.dynamic_allocation.dest_aid",
FT_UINT16, BASE_DEC, NULL, 0x7f80,
NULL, HFILL }},
{&hf_ieee80211_ff_alloc_duration,
{"Response Offset", "wlan.dynamic_allocation.alloc_duration",
FT_UINT32, BASE_CUSTOM, CF_FUNC(allocation_duration_base_custom), 0x7fff80,
NULL, HFILL }},
{&hf_ieee80211_ff_ssw,
{"Sector Sweep", "wlan.ssw",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_ssw_direction,
{"Sector Sweep Direction", "wlan.ssw.direction",
FT_BOOLEAN, 24, TFS(&ieee80211_cf_ssw_direction), 0x000001,
NULL, HFILL}},
{&hf_ieee80211_ff_ssw_cdown,
{"Sector Sweep CDOWN", "wlan.ssw.cdown",
FT_UINT24, BASE_DEC, NULL, 0x0003fe,
NULL, HFILL }},
{&hf_ieee80211_ff_ssw_sector_id,
{"Sector Sweep Sector ID", "wlan.ssw.sector_id",
FT_UINT24, BASE_DEC, NULL, 0x00fc00,
NULL, HFILL }},
{&hf_ieee80211_ff_ssw_dmg_ant_id,
{"Sector Sweep DMG Antenna ID", "wlan.ssw.dmg_ant_id",
FT_UINT24, BASE_DEC, NULL, 0x030000,
NULL, HFILL }},
{&hf_ieee80211_ff_ssw_rxss_len,
{"Sector Sweep RXSS Length", "wlan.ssw.rxss_len",
FT_UINT24, BASE_DEC, NULL, 0xfc0000,
NULL, HFILL }},
{&hf_ieee80211_ff_bf,
{"Beam Forming", "wlan.bf",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_bf_train,
{"Beam Forming Training", "wlan.bf.train",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_bf_is_init,
{"Beam Forming Is InitiatorTXSS", "wlan.bf.isInit",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{&hf_ieee80211_ff_bf_is_resp,
{"Beam Forming Is ResponderTXSS", "wlan.bf.isResp",
FT_BOOLEAN, 8, NULL, 0x4,
NULL, HFILL }},
{&hf_ieee80211_ff_bf_rxss_len,
{"Beam Forming RXSS Length", "wlan.bf.rxss_len",
FT_UINT16, BASE_DEC, NULL, 0x1f8,
NULL, HFILL }},
{&hf_ieee80211_ff_bf_rxss_rate,
{"Beam Forming RXSS Rate", "wlan.bf.rxss_rate",
FT_BOOLEAN, 16, NULL, 0x200,
NULL, HFILL }},
{&hf_ieee80211_ff_bf_num_sectors,
{"Beam Forming Total Number of Sectors", "wlan.bf.num_sectors",
FT_UINT16, BASE_DEC, NULL, 0x3f8,
NULL, HFILL }},
{&hf_ieee80211_ff_bf_num_rx_dmg_ants,
{"Beam Forming Number of DMG Antennas", "wlan.bf.num_dmg_ants",
FT_UINT16, BASE_DEC, NULL, 0xc00,
NULL, HFILL }},
{&hf_ieee80211_addr_nav_da,
{"Destination address of STA that caused NAV update", "wlan.nav_da",
FT_ETHER, BASE_NONE, NULL, 0,
"DMG Destination Hardware Address", HFILL }},
{&hf_ieee80211_addr_nav_sa,
{"Source address of STA that caused NAV update", "wlan.nav_sa",
FT_ETHER, BASE_NONE, NULL, 0,
"DMG Source Hardware Address", HFILL }},
{&hf_ieee80211_ff_sswf,
{"Sector Sweep Feedback", "wlan.sswf",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_sswf_total_sectors,
{"Sector Sweep Feedback total number of sectors", "wlan.sswf.num_sectors",
FT_UINT24, BASE_DEC, NULL, 0x0001ff,
NULL, HFILL }},
{&hf_ieee80211_ff_sswf_num_rx_dmg_ants,
{"Sector Sweep Feedback Number of receive DMG Antennas", "wlan.sswf.num_dmg_ants",
FT_UINT24, BASE_DEC, NULL, 0x000600,
NULL, HFILL }},
{&hf_ieee80211_ff_sswf_poll_required,
{"Sector Sweep Feedback Poll required", "wlan.sswf.poll",
FT_BOOLEAN, 24, NULL, 0x010000,
NULL, HFILL }},
{&hf_ieee80211_ff_brp,
{"BRP Request", "wlan.brp",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_brp_L_RX,
{"BRP Request L-RX", "wlan.brp.l_rx",
FT_UINT32, BASE_DEC, NULL, 0x0000001f,
NULL, HFILL }},
{&hf_ieee80211_ff_brp_TX_TRN_REQ,
{"BRP Request TX-TRN-REQ", "wlan.brp.tx_trn_req",
FT_BOOLEAN, 32, NULL, 0x00000020,
NULL, HFILL }},
{&hf_ieee80211_ff_brp_MID_REQ,
{"BRP Request MID-REQ", "wlan.brp.mid_req",
FT_BOOLEAN, 32, NULL, 0x00000040,
NULL, HFILL }},
{&hf_ieee80211_ff_brp_BC_REQ,
{"BRP Request BC-REQ", "wlan.brp.bc_req",
FT_BOOLEAN, 32, NULL, 0x00000080,
NULL, HFILL }},
{&hf_ieee80211_ff_brp_MID_GRANT,
{"BRP Request MID-GRANT", "wlan.brp.mid_grant",
FT_BOOLEAN, 32, NULL, 0x00000100,
NULL, HFILL }},
{&hf_ieee80211_ff_brp_BC_GRANT,
{"BRP Request BC-GRANT", "wlan.brp.bc_grant",
FT_BOOLEAN, 32, NULL, 0x00000200,
NULL, HFILL }},
{&hf_ieee80211_ff_brp_chan_FBCK_CAP,
{"BRP Request Chan FBCK-CAP", "wlan.brp.chan_fbck_cap",
FT_BOOLEAN, 32, NULL, 0x00000400,
NULL, HFILL }},
{&hf_ieee80211_ff_brp_tx_sector,
{"BRP Request TX Sector ID", "wlan.brp.tx_sector_id",
FT_UINT32, BASE_DEC, NULL, 0x0001f800,
NULL, HFILL }},
{&hf_ieee80211_ff_brp_other_aid,
{"BRP Request Other AID", "wlan.brp.other_aid",
FT_UINT32, BASE_DEC, NULL, 0x01fe0000,
NULL, HFILL }},
{&hf_ieee80211_ff_brp_tx_antenna,
{"BRP Request TX Antenna ID", "wlan.brp.tx_antenna_id",
FT_UINT32, BASE_DEC, NULL, 0x0600000,
NULL, HFILL }},
{&hf_ieee80211_ff_blm,
{"Beamformed Link Maintenance", "wlan.blm",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_blm_unit_index,
{"BeamLink Maintenance Uint Index", "wlan.blm.uint_index",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_blm_maint_value,
{"BeamLink Maintenance Value", "wlan.blm.value",
FT_UINT8, BASE_DEC, NULL, 0x7e,
NULL, HFILL }},
{&hf_ieee80211_ff_blm_is_master,
{"BeamLink Is Master", "wlan.blm.is_master",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{&hf_ieee80211_ff_bic,
{"Beacon Interval Control", "wlan.bic",
FT_UINT48, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_cc_present,
{"Clustering Control Present", "wlan.bic.cc",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_discovery_mode,
{"Discovery Mode", "wlan.bic.discovery_mode",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_next_beacon,
{"Next Beacon", "wlan.bic.next_beacon",
FT_UINT8, BASE_DEC, NULL, 0x3c,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_ati_present,
{"ATI Present", "wlan.bic.ati",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_abft_len,
{"A-BFT length", "wlan.bic.abft_len",
FT_UINT16, BASE_DEC, NULL, 0x0380,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_fss,
{"FSS", "wlan.bic.fss",
FT_UINT8, BASE_DEC, NULL, 0x3c,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_is_resp,
{"Is TXSS Responder", "wlan.bic.is_responder",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_next_abft,
{"Next A-BFT", "wlan.bic.next_abft",
FT_UINT16, BASE_DEC, NULL, 0x0780,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_frag_txss,
{"Fragmented TXSS", "wlan.bic.frag_txss",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_txss_span,
{"TXSS span", "wlan.bic.txss_span",
FT_UINT16, BASE_DEC, NULL, 0x07f0,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_NBI_abft,
{"Number of Beacon Intervals that are needed to allocate A-BFT", "wlan.bic.NBI_abft",
FT_UINT8, BASE_DEC, NULL, 0x78,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_abft_count,
{"A-BFT Count", "wlan.bic.abft_count",
FT_UINT16, BASE_DEC, NULL, 0x1f80,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_nabft,
{"Number of A-BFT's received from each Antenna", "wlan.bic.nabft",
FT_UINT16, BASE_DEC, NULL, 0x07e0,
NULL, HFILL }},
{&hf_ieee80211_ff_bic_pcp,
{"PCP Association Ready", "wlan.bic.pcp",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{&hf_ieee80211_ff_dmg_params,
{"DMG Parameters", "wlan.dmg_params",
FT_UINT8, BASE_HEX , NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_dmg_params_bss,
{"BSS Type", "wlan.dmg_params.bss",
FT_UINT8, BASE_DEC, VALS(bss_type), 0x03,
NULL, HFILL }},
{&hf_ieee80211_ff_dmg_params_cbap_only,
{"CBAP Only", "wlan.dmp_params.cbap_only",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{&hf_ieee80211_ff_dmg_params_cbap_src,
{"CBAP Source", "wlan.dmp_params.cbap_src",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{&hf_ieee80211_ff_dmg_params_privacy,
{"DMG Privacy", "wlan.dmp_params.privacy",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{&hf_ieee80211_ff_dmg_params_policy,
{"ECPAC Policy Enforced", "wlan.dmp_params.policy",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{&hf_ieee80211_ff_cc,
{"Clustering Control", "wlan.cc",
FT_UINT64, BASE_HEX , NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_cc_abft_resp_addr,
{"A-BFT Responder Address", "wlan.cc.abft_resp_addr",
FT_ETHER, BASE_NONE , NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_cc_sp_duration,
{"Beacon SP Duration", "wlan.cc.sp_duration",
FT_UINT8, BASE_DEC , NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_cc_cluster_id,
{"Cluster ID", "wlan.cc.cluster_id",
FT_UINT64, BASE_DEC , NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_cc_role,
{"Cluster Member Role", "wlan.cc.rold",
FT_UINT8, BASE_DEC , NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_cc_max_mem,
{"Cluster MaxMem", "wlan.cc.max_mem",
FT_UINT8, BASE_DEC , NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_relay_support,
{"Relay Supportability", "wlan.relay_capabilities.relay_support",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_relay_use,
{"Relay Usability", "wlan.relay_capabilities.relay_use",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_relay_permission,
{"Relay Permission", "wlan.relay_capabilities.relay_permission",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_AC_power,
{"A/C Power", "wlan.relay_capabilities.AC_power",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_relay_prefer,
{"Relay Preference", "wlan.relay_capabilities.relay_prefer",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_duplex,
{"Duplex", "wlan.relay_capabilities.duplex",
FT_UINT8, BASE_DEC, NULL, 0x60,
NULL, HFILL }},
{&hf_ieee80211_tag_cooperation,
{"Cooperation", "wlan.relay_capabilities.cooperation",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{&hf_ieee80211_ff_rcsi,
{"Relay Capable STA Info", "wlan.rcsi",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_rcsi_aid,
{"AID", "wlan.rcsi.aid",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }},
{&hf_ieee80211_ff_band_id,
{"Band ID", "wlan.band_id",
FT_UINT8, BASE_DEC, VALS(band_id), 0xff,
NULL, HFILL }},
{&hf_ieee80211_tag_move,
{"Move", "wlan.dmg_bss_param_change.move",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_size,
{"Size", "wlan.dmg_bss_param_change.size",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_tbtt_offset,
{"TBTT Offset", "wlan.dmg_bss_param_change.tbtt_offset",
FT_UINT32, BASE_CUSTOM, CF_FUNC(allocation_duration_base_custom), 0xffffffff,
NULL, HFILL }},
{&hf_ieee80211_tag_bi_duration,
{"BI Duration", "wlan.dmg_bss_param_change.bi_duration",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }},
{&hf_ieee80211_tag_dmg_capa_sta_addr,
{"STA Address", "wlan.dmg_capa.sta_addr",
FT_ETHER, BASE_NONE, NULL, 0,
"STA_Address", HFILL }},
{&hf_ieee80211_tag_dmg_capa_aid,
{"AID", "wlan.dmg_capa.aid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_reverse_direction,
{"Reverse Direction", "wlan.dmg_capa.reverse_direction",
FT_BOOLEAN, 24, NULL, GENMASK(0, 0),
NULL, HFILL }},
{&hf_ieee80211_tag_hlts,
{"Higher Layer Timer Synchronization", "wlan.dmg_capa.htls",
FT_BOOLEAN, 24, NULL, GENMASK(1, 1),
NULL, HFILL }},
{&hf_ieee80211_tag_tpc,
{"TPC", "wlan.dmg_capa.tpc",
FT_BOOLEAN, 24, NULL, GENMASK(2, 2),
NULL, HFILL }},
{&hf_ieee80211_tag_spsh,
{"SPSH and Interference Mitigation", "wlan.dmg_capa.spsh",
FT_BOOLEAN, 24, NULL, GENMASK(3, 3),
NULL, HFILL }},
{&hf_ieee80211_tag_rx_antenna,
{"Number of RX DMG Antennas", "wlan.dmg_capa.num_rx",
FT_UINT24, BASE_CUSTOM, CF_FUNC(extra_one_base_custom), GENMASK(5, 4),
NULL, HFILL }},
{&hf_ieee80211_tag_fast_link,
{"Fast Link Adaptation", "wlan.dmg_capa.fast_link",
FT_BOOLEAN, 24, NULL, GENMASK(6, 6),
NULL, HFILL }},
{&hf_ieee80211_tag_num_sectors,
{"Total Number of Sectors", "wlan.dmg_capa.num_sectors",
FT_UINT24, BASE_CUSTOM, CF_FUNC(extra_one_base_custom), GENMASK(13, 7),
NULL, HFILL }},
{&hf_ieee80211_tag_rxss_length,
{"RXSS Length", "wlan.dmg_capa.rxss_len",
FT_UINT24, BASE_CUSTOM, CF_FUNC(extra_one_mul_two_base_custom), GENMASK(19, 14),
NULL, HFILL }},
{&hf_ieee80211_tag_reciprocity,
{"DMG Antenna Reciprocity", "wlan.dmg_capa.reciprocity",
FT_BOOLEAN, 24, NULL, GENMASK(20, 20),
NULL, HFILL }},
{&hf_ieee80211_tag_max_ampdu_exp,
{"Maximum A-MPDU Length Exponent", "wlan.dmg_capa.max_ampdu_exp",
FT_UINT24, BASE_DEC, NULL, GENMASK(23, 21),
NULL, HFILL }},
{&hf_ieee80211_tag_min_mpdu_sapcing,
{"Minimum MPDU Start Spacing", "wlan.dmg_capa.min_mpdu_spacing",
FT_UINT24, BASE_DEC, NULL, GENMASK(26-24, 24-24),
NULL, HFILL }},
{&hf_ieee80211_tag_ba_flow_control ,
{"BA with Flow Control", "wlan.dmg_capa.bs_flow_ctrl",
FT_BOOLEAN, 24, NULL, GENMASK(27-24, 27-24),
NULL, HFILL }},
{&hf_ieee80211_tag_max_sc_rx_mcs,
{"Maximum SC Rx MCS", "wlan.dmg_capa.max_sc_rx_mcs",
FT_UINT24, BASE_DEC, NULL, GENMASK(32-24, 28-24),
NULL, HFILL }},
{&hf_ieee80211_tag_max_ofdm_rx_mcs,
{"Maximum OFDM Rx MCS", "wlan.dmg_capa.max_ofdm_rx_mcs",
FT_UINT24, BASE_DEC, NULL, GENMASK(37-24, 33-24),
NULL, HFILL }},
{&hf_ieee80211_tag_max_sc_tx_mcs,
{"Maximum SC Tx MCS", "wlan.dmg_capa.max_sc_tx_mcs",
FT_UINT24, BASE_DEC, NULL, GENMASK(42-24, 38-24),
NULL, HFILL }},
{&hf_ieee80211_tag_max_ofdm_tx_mcs,
{"Maximum OFDM Tx MCS", "wlan.dmg_capa.max_ofdm_tx_mcs",
FT_UINT24, BASE_DEC, NULL, GENMASK(47-24, 43-24),
NULL, HFILL }},
{&hf_ieee80211_tag_low_power_supported,
{"Low Power SC PHY Supported", "wlan.dmg_capa.low_power_suuported",
FT_BOOLEAN, 16, NULL, GENMASK(48-48, 48-48),
NULL, HFILL }},
{&hf_ieee80211_tag_code_rate,
{"Code Rate 13/16", "wlan.dmg_capa.code_rate",
FT_BOOLEAN, 16, NULL, GENMASK(49-48, 49-48),
NULL, HFILL }},
{&hf_ieee80211_tag_dtp,
{"DTP Supported", "wlan.dmg_capa.dtp",
FT_BOOLEAN, 16, NULL, GENMASK(52-48, 52-48),
NULL, HFILL }},
{&hf_ieee80211_tag_appdu_supp,
{"A-PPDU Supported", "wlan.dmg_capa.appdu_supp",
FT_BOOLEAN, 16, NULL, GENMASK(53-48, 53-48),
NULL, HFILL }},
{&hf_ieee80211_tag_heartbeat,
{"HeartBeat", "wlan.dmg_capa.heartbeat",
FT_BOOLEAN, 16, NULL, GENMASK(54-48, 54-48),
NULL, HFILL }},
{&hf_ieee80211_tag_other_aid,
{"Supports Other_AID", "wlan.dmg_capa.other_aid",
FT_BOOLEAN, 16, NULL, GENMASK(55-48, 55-48),
NULL, HFILL }},
{&hf_ieee80211_tag_pattern_recip,
{"Antenna Pattern Reciprocity", "wlan.dmg_capa.pattern_recip",
FT_BOOLEAN, 16, NULL, GENMASK(56-48, 56-48),
NULL, HFILL }},
{&hf_ieee80211_tag_heartbeat_elapsed,
{"Heartbeat Elapsed Indication", "wlan.dmg_capa.heartbeat_elapsed",
FT_UINT16, BASE_DEC, NULL, GENMASK(59-48, 57-48),
NULL, HFILL }},
{&hf_ieee80211_tag_grant_ack_supp,
{"Grant ACK Supported", "wlan.dmg_capa.grant_ack_supp",
FT_BOOLEAN, 16, NULL, GENMASK(60-48, 60-48),
NULL, HFILL }},
{&hf_ieee80211_tag_RXSSTxRate_supp,
{"RXSSTxRate Supported", "wlan.dmg_capa.RXSSTxRate",
FT_BOOLEAN, 16, NULL, GENMASK(61-48, 61-48),
NULL, HFILL }},
{&hf_ieee80211_tag_pcp_tddti,
{"TDDTI", "wlan.dmg_capa.pcp_tdtti",
FT_BOOLEAN, 16, NULL, GENMASK(0, 0),
NULL, HFILL }},
{&hf_ieee80211_tag_pcp_PSA,
{"Pseudo-static Allocations", "wlan.dmg_capa.pcp_psa",
FT_BOOLEAN, 16, NULL, GENMASK(1, 1),
NULL, HFILL }},
{&hf_ieee80211_tag_pcp_handover,
{"PDP Handover", "wlan.dmg_capa.pcp_handover",
FT_BOOLEAN, 16, NULL, GENMASK(2, 2),
NULL, HFILL }},
{&hf_ieee80211_tag_pcp_max_assoc,
{"Max Associated STA Number", "wlan.dmg_capa.pcp_max_assoc",
FT_UINT16, BASE_DEC, NULL, GENMASK(10, 3),
NULL, HFILL }},
{&hf_ieee80211_tag_pcp_power_src,
{"Power Source", "wlan.dmg_capa.pcp_power_src",
FT_BOOLEAN, 16, NULL, GENMASK(11, 11),
NULL, HFILL }},
{&hf_ieee80211_tag_pcp_decenter,
{"Decentralized PCP/AP Clustering", "wlan.dmg_capa.pcp_decenter",
FT_BOOLEAN, 16, NULL, GENMASK(12, 12),
NULL, HFILL }},
{&hf_ieee80211_tag_pcp_forwarding,
{"PCP Forwarding", "wlan.dmg_capa.pcp_forwarding",
FT_BOOLEAN, 16, NULL, GENMASK(13, 13),
NULL, HFILL }},
{&hf_ieee80211_tag_pcp_center,
{"Centralized PCP/AP Clustering", "wlan.dmg_capa.pcp_center",
FT_BOOLEAN, 16, NULL, GENMASK(14, 14),
NULL, HFILL }},
{&hf_ieee80211_tag_PSRSI,
{"PS Request Suspension Interval", "wlan.dmg_oper.psrsi",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_min_BHI_duration,
{"Min BHI Duration", "wlan.dmg_oper.min_BHI_duration",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_brdct_sta_info_dur,
{"Broadcast STA Info Duration", "wlan.dmg_oper.brdcst_sta_info_dur",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_assoc_resp_confirm_time,
{"Associated Response Confirm Time", "wlan.dmg_oper.assoc_resp_confirm_time",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_min_pp_duration,
{"Min PP Duration", "wlan.dmg_oper.min_pp_duration",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_SP_idle_timeout,
{"SP Idle Timeout", "wlan.dmg_oper.SP_idle_timeout",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_max_lost_beacons,
{"Max Lost Beacons", "wlan.dmg_oper.max_lost_beacons",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_type,
{"Type", "wlan.sctor_id.type",
FT_UINT32, BASE_HEX, NULL, 0x0000000f,
NULL, HFILL }},
{&hf_ieee80211_tag_tap1,
{"Tap 1", "wlan.sctor_id.tap1",
FT_UINT32, BASE_HEX, NULL, 0x000003f0,
NULL, HFILL }},
{&hf_ieee80211_tag_state1,
{"State 1", "wlan.sctor_id.state1",
FT_UINT32, BASE_HEX, NULL, 0x0000fc00,
NULL, HFILL }},
{&hf_ieee80211_tag_tap2,
{"Tap 2", "wlan.sctor_id.tap2",
FT_UINT32, BASE_HEX, NULL, 0x00ff0000,
NULL, HFILL }},
{&hf_ieee80211_tag_state2,
{"State 2", "wlan.sctor_id.state2",
FT_UINT32, BASE_HEX, NULL, 0xff000000,
NULL, HFILL }},
{&hf_ieee80211_tag_allocation_id,
{"Allocation ID", "wlan.ext_sched.alloc_id",
FT_UINT16, BASE_DEC, NULL, 0x000f,
NULL, HFILL }},
{&hf_ieee80211_tag_allocation_type,
{"Allocation Type", "wlan.ext_sched.alloc_type",
FT_UINT16, BASE_DEC, VALS(allocation_type), 0x0070,
NULL, HFILL }},
{&hf_ieee80211_tag_pseudo_static,
{"Pseudo-static", "wlan.ext_sched.p_static",
FT_BOOLEAN, 16, NULL, 0x0080,
NULL, HFILL }},
{&hf_ieee80211_tag_truncatable,
{"Truncatable", "wlan.ext_sched.truncatable",
FT_BOOLEAN, 16, NULL, 0x0100,
NULL, HFILL }},
{&hf_ieee80211_tag_extendable,
{"Extenedable", "wlan.ext_sched.extendable",
FT_BOOLEAN, 16, NULL, 0x0200,
NULL, HFILL }},
{&hf_ieee80211_tag_pcp_active,
{"PCP Active", "wlan.ext_sched.pcp_active",
FT_BOOLEAN, 16, NULL, 0x0400,
NULL, HFILL }},
{&hf_ieee80211_tag_lp_sc_used,
{"LP SC Used", "wlan.ext_sched.lp_sc_used",
FT_BOOLEAN, 16, NULL, 0x0800,
NULL, HFILL }},
{&hf_ieee80211_tag_src_aid,
{"Source AID", "wlan.ext_sched.src_id",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }},
{&hf_ieee80211_tag_dest_aid,
{"Destination AID", "wlan.ext_sched.dest_id",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }},
{&hf_ieee80211_tag_alloc_start,
{"Allocation Start", "wlan.ext_sched.alloc_start",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_alloc_block_duration,
{"Allocation Block Duration", "wlan.ext_sched.block_duration",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }},
{&hf_ieee80211_tag_num_blocks,
{"Number of Blocks", "wlan.ext_sched.num_blocks",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }},
{&hf_ieee80211_tag_alloc_block_period,
{"Allocation Block Period", "wlan.ext_sched.alloc_block_period",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }},
{&hf_ieee80211_tag_aid,
{"AID", "wlan.sta_avail.aid",
FT_UINT16, BASE_DEC, NULL, 0x00ff,
NULL, HFILL }},
{&hf_ieee80211_tag_cbap,
{"CBAP", "wlan.sta_avail.cbap",
FT_BOOLEAN, 16, NULL, 0x0100,
NULL, HFILL }},
{&hf_ieee80211_tag_pp_avail,
{"PP Available", "wlan.sta_avail.pp_avail",
FT_BOOLEAN, 16, NULL, 0x0200,
NULL, HFILL }},
{&hf_ieee80211_tag_next_ati_start_time,
{"Start Time", "wlan.next_ati.start_time",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_next_ati_duration,
{"ATI Duration", "wlan.next_ati.duration",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }},
{&hf_ieee80211_tag_old_bssid,
{"Old BSSID", "wlan.pcp_handover.old_bssid",
FT_ETHER, BASE_NONE, NULL, 0,
"OLD_BSSID", HFILL }},
{&hf_ieee80211_tag_new_pcp_addr,
{"New PCP Address", "wlan.pcp_handover.new_pcp_addr",
FT_ETHER, BASE_NONE, NULL, 0,
"New_PCP_Address", HFILL }},
{&hf_ieee80211_tag_bssid,
{"BSSID", "wlan.quiet_res.bssid",
FT_ETHER, BASE_NONE, NULL, 0,
"BSS-ID", HFILL }},
{&hf_ieee80211_tag_duplex_relay,
{"Duplex", "wlan.relay_capabilities.duplex",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_cooperation_relay,
{"Cooperation", "wlan.relay_capabilities.cooperation",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_tx_mode,
{"TX-Mode", "wlan.realy_trans_param.tx_mode",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_link_change_interval,
{"Link Change Interval", "wlan.realy_trans_param.link_change_interval",
FT_UINT8, BASE_CUSTOM, CF_FUNC(allocation_duration_base_custom), 0xff,
NULL, HFILL }},
{&hf_ieee80211_tag_data_sensing_time,
{"Data Sensing Time", "wlan.realy_trans_param.data_sensing_time",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }},
{&hf_ieee80211_tag_first_period,
{"First Period", "wlan.realy_trans_param.first_period",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }},
{&hf_ieee80211_tag_second_period,
{"Second Period", "wlan.realy_trans_param.second_period",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }},
{&hf_ieee80211_tag_initiator,
{"Initiator", "wlan.beam_refine.initiator",
FT_BOOLEAN, 16, NULL, 0x0001,
NULL, HFILL }},
{&hf_ieee80211_tag_tx_train_res,
{"TX-train-response", "wlan.beam_refine.tx_train_res",
FT_BOOLEAN, 16, NULL, 0x0002,
NULL, HFILL }},
{&hf_ieee80211_tag_rx_train_res,
{"RX-train-response", "wlan.beam_refine.rx_train_res",
FT_BOOLEAN, 16, NULL, 0x0004,
NULL, HFILL }},
{&hf_ieee80211_tag_tx_trn_ok,
{"TX-TRN-OK", "wlan.beam_refine.tx_trn_ok",
FT_BOOLEAN, 16, NULL, 0x0008,
NULL, HFILL }},
{&hf_ieee80211_tag_txss_fbck_req,
{"TXSS-FBCK-REQ", "wlan.beam_refine.txss_fbck_req",
FT_BOOLEAN, 16, NULL, 0x0010,
NULL, HFILL }},
{&hf_ieee80211_tag_bs_fbck,
{"BS-FBCK", "wlan.beam_refine.bs_fbck",
FT_UINT16, BASE_DEC, NULL, 0x07e0,
NULL, HFILL }},
{&hf_ieee80211_tag_bs_fbck_antenna_id,
{"BS-FBCK Anetenna ID", "wlan.beam_refine.bs_fbck_antenna_id",
FT_UINT16, BASE_DEC, NULL, 0x1800,
NULL, HFILL }},
{&hf_ieee80211_tag_snr_requested,
{"SNR Requested", "wlan.beam_refine.snr_req",
FT_BOOLEAN, 16, NULL, 0x2000,
NULL, HFILL }},
{&hf_ieee80211_tag_channel_measurement_requested,
{"Channel Measurement Requested", "wlan.beam_refine.ch_measure_req",
FT_BOOLEAN, 16, NULL, 0x4000,
NULL, HFILL }},
{&hf_ieee80211_tag_number_of_taps_requested,
{"Number of Taps Requested", "wlan.beam_refine.taps_req",
FT_UINT32, BASE_DEC, VALS(number_of_taps_values), 0x00000180,
NULL, HFILL }},
{&hf_ieee80211_tag_sector_id_order_req,
{"Sector ID Order Requested", "wlan.beam_refine.sector_id_req",
FT_BOOLEAN, 32, NULL, 0x00000200,
NULL, HFILL }},
{&hf_ieee80211_tag_snr_present,
{"SNR Present", "wlan.beam_refine.snr_present",
FT_BOOLEAN, 32, NULL, 0x00000400,
NULL, HFILL }},
{&hf_ieee80211_tag_channel_measurement_present,
{"Channel Measurement Present", "wlan.beam_refine.ch_measure_present",
FT_BOOLEAN, 32, NULL, 0x00000800,
NULL, HFILL }},
{&hf_ieee80211_tag_tap_delay_present,
{"Tap Delay Present", "wlan.beam_refine.tap_delay_present",
FT_BOOLEAN, 32, NULL, 0x00001000,
NULL, HFILL }},
{&hf_ieee80211_tag_number_of_taps_present,
{"Number of Taps Present", "wlan.beam_refine.taps_present",
FT_UINT32, BASE_DEC, VALS(number_of_taps_values), 0x00006000,
NULL, HFILL }},
{&hf_ieee80211_tag_number_of_measurement,
{"Number of Measurements", "wlan.beam_refine.num_measurement",
FT_UINT32, BASE_DEC, NULL, 0x003f8000,
NULL, HFILL }},
{&hf_ieee80211_tag_sector_id_order_present,
{"Sector ID Order Present", "wlan.beam_refine.sector_id_present",
FT_BOOLEAN, 32, NULL, 0x00400000,
NULL, HFILL }},
{&hf_ieee80211_tag_number_of_beams,
{"Number of Beams", "wlan.beam_refine.num_beams",
FT_UINT32, BASE_DEC, NULL, 0x0f800000,
NULL, HFILL }},
{&hf_ieee80211_tag_mid_extension,
{"MID Extension", "wlan.beam_refine.mid_ext",
FT_BOOLEAN, 32, NULL, 0x10000000,
NULL, HFILL }},
{&hf_ieee80211_tag_capability_request,
{"Capability Request", "wlan.beam_refine.cap_req",
FT_BOOLEAN, 32, NULL, 0x20000000,
NULL, HFILL }},
{&hf_ieee80211_tag_nextpcp_list,
{"AID of NextPCP", "wlan.next_pcp.list",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_nextpcp_token,
{"NextPCP List Token", "wlan.next_pcp.token",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_reamaining_BI,
{"Remaining BI's", "wlan.pcp_handover.remaining_BIs",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_request_token,
{"Request Token", "wlan.request_token",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_bi_start_time,
{"BI Start Time", "wlan.bi_start_time",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_sleep_cycle,
{"Sleep Cycle", "wlan.sleep_cycle",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_num_awake_bis,
{"Number of Awake/Doze BIs", "wlan.num_awake_bis",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_dmg_action_code,
{"DMG Action", "wlan_mgt.fixed.dmg_act",
FT_UINT8, BASE_HEX, VALS(ff_dmg_action_flags), 0,
"Action Code", HFILL }},
{&hf_ieee80211_ff_unprotected_dmg_action_code,
{"Unprotected DMG Action", "wlan_mgt.fixed.unprotected_dmg_act",
FT_UINT8, BASE_HEX, VALS(ff_unprotected_dmg_action_flags), 0,
"Action Code", HFILL }},
{&hf_ieee80211_ff_dmg_pwr_mgmt,
{"DMG Power Management", "wlan.dmg.pwr_mgmt",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_subject_address,
{"Subject Address","wlan.dmg.subject_addr",
FT_ETHER, BASE_NONE, NULL, 0,
"MAC address of requested STA", HFILL }},
{&hf_ieee80211_ff_handover_reason,
{"Handover Reason","wlan.dmg.handover_reason",
FT_UINT8, BASE_DEC, NULL, 0x03,
NULL, HFILL }},
{&hf_ieee80211_ff_handover_remaining_bi,
{"Handover Remaining BI","wlan.dmg.handover_remaining_bi",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_handover_result,
{"Handover Result","wlan.dmg.handover_result",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_handover_reject_reason,
{"Handover Reject Reason","wlan.dmg.handover_reject_reason",
FT_UINT8, BASE_DEC, NULL, 0x03,
NULL, HFILL }},
{&hf_ieee80211_ff_destination_reds_aid,
{"Destination REDS AID","wlan.dmg.destination_reds_aid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_destination_aid,
{"Destination AID","wlan.dmg.destination_aid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_realy_aid,
{"Relay AID","wlan.dmg.realy_aid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_source_aid,
{"Source AID","wlan.dmg.source_aid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_timing_offset,
{"Timing Offset","wlan.dmg.timing_offset",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_sampling_frequency_offset,
{"Sampling Frequency Offset","wlan.dmg.sampling_frequency_offset",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_relay_operation_type,
{"Relay Operation Type","wlan.dmg.relay_operation_type",
FT_UINT8, BASE_DEC, NULL, 0x03,
NULL, HFILL }},
{&hf_ieee80211_ff_peer_sta_aid,
{"Peer STA AID","wlan.dmg.peer_sta_aid",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_snr,
{"SNR","wlan.dmg.snr",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_internal_angle,
{"Internal Angle","wlan.dmg.internal_angle",
FT_UINT8, BASE_DEC, NULL, 0xfe,
NULL, HFILL }},
{&hf_ieee80211_ff_recommend,
{"Recommend","wlan.dmg.recommend",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_fst_action_code,
{"FST Action Code","wlan.fst.action_code",
FT_UINT8, BASE_HEX, VALS(ff_fst_action_flags), 0,
"Action Code", HFILL }},
{&hf_ieee80211_ff_llt,
{"Link Loss Timeout","wlan.fst.llt",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_fsts_id,
{"FSTS ID","wlan.session_trans.fsts_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mmpdu_len,
{"MMPDU Length","wlan.fst.mmpdu_length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mmpdu_ctrl,
{"MMPDU Control","wlan.fst.mmpdu_ctrl",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_oct_mmpdu,
{"OCT MMPDU","wlan.fst.oct_mmpdu",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl,
{"VHT MIMO Control", "wlan.vht.mimo_control.control",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl_nc_index,
{"Nc Index", "wlan.vht.mimo_control.ncindex",
FT_UINT24, BASE_HEX, VALS(ff_vht_mimo_cntrl_nc_index_vals), 0x000007,
"Number of Columns Less One", HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl_nr_index,
{"Nr Index", "wlan.vht.mimo_control.nrindex",
FT_UINT24, BASE_HEX, VALS(ff_vht_mimo_cntrl_nr_index_vals), 0x000038,
"Number of Rows Less One", HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl_channel_width,
{"Channel Width", "wlan.vht.mimo_control.chanwidth",
FT_UINT24, BASE_HEX, VALS(ff_vht_mimo_cntrl_channel_width_vals), 0x0000C0,
NULL, HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl_grouping,
{"Grouping (Ng)", "wlan.vht.mimo_control.grouping",
FT_UINT24, BASE_HEX, VALS(ff_vht_mimo_cntrl_grouping_vals), 0x000300,
NULL, HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl_codebook_info,
{"Codebook Information", "wlan.vht.mimo_control.codebookinfo",
FT_UINT24, BASE_HEX, NULL, 0x000400,
NULL, HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl_feedback_type,
{"Feedback Type", "wlan.vht.mimo_control.feedbacktype",
FT_UINT24, BASE_HEX, VALS(ff_vht_mimo_cntrl_feedback_vals), 0x000800,
NULL, HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl_remaining_feedback_seg,
{"Remaining Feedback Segments", "wlan.vht.mimo_control.remainingfeedbackseg",
FT_UINT24, BASE_HEX, NULL, 0x007000,
NULL, HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl_first_feedback_seg,
{"First Feedback Segments", "wlan.vht.mimo_control.firstfeedbackseg",
FT_UINT24, BASE_HEX, NULL, 0x008000,
NULL, HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl_reserved,
{"Reserved", "wlan.vht.mimo_control.reserved",
FT_UINT24, BASE_HEX, NULL, 0x030000,
NULL, HFILL }},
{&hf_ieee80211_ff_vht_mimo_cntrl_sounding_dialog_token_number,
{"Sounding Dialog Toker Number", "wlan.vht.mimo_control.soundingdialogtocketnbr",
FT_UINT24, BASE_HEX, NULL, 0xFC0000,
NULL, HFILL }},
{&hf_ieee80211_ff_vht_action,
{"VHT Action","wlan.vht.action",
FT_UINT8, BASE_DEC, VALS(vht_action_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_vht_compressed_beamforming_report,
{"VHT Compressed Beamforming Report","wlan.vht.compressed_beamforming_report",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_compressed_beamforming_report_snr,
{"Signal to Noise Ratio (SNR)", "wlan.vht.compressed_beamforming_report.snr",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_compressed_beamforming_feedback_matrix,
{"Compressed Beamforming Feedback Matrix", "wlan.vht.compressed_beamforming_report.feedback_matrix",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_group_id_management,
{"Group ID Management","wlan.vht.group_id_management",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_membership_status_array,
{"Membership Status Array","wlan.vht.membership_status_array",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_user_position_array,
{"User Position Array","wlan.vht.user_position_array",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_operation_mode_notification,
{"Operation Mode Notification","wlan.vht.operation_mode_notification",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_allocation_id,
{"Allocation ID","wlan.dmg_tspec.allocation_id",
FT_UINT24, BASE_DEC, NULL, 0x00000f,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_allocation_type,
{"Allocation Type","wlan.dmg_tspec.allocation_type",
FT_UINT24, BASE_DEC, NULL, 0x000070,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_allocation_format,
{"Allocation Format","wlan.dmg_tspec.allocation_format",
FT_BOOLEAN, 24, NULL, 0x000080,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_pseudo_static,
{"Pseudo Static","wlan.dmg_tspec.pseudo_static",
FT_BOOLEAN, 24, NULL, 0x000100,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_truncatable,
{"Truncatable","wlan.dmg_tspec.truncatable",
FT_BOOLEAN, 24, NULL, 0x000200,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_extendable,
{"Extendable","wlan.dmg_tspec.extendable",
FT_BOOLEAN, 24, NULL, 0x000400,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_lp_sc_used,
{"LP SC Usec","wlan.dmg_tspec.lp_sc_used",
FT_BOOLEAN, 24, NULL, 0x000800,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_up,
{"UP","wlan.dmg_tspec.up",
FT_UINT24, BASE_HEX, NULL, 0x007000,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_dest_aid,
{"Destination AID","wlan.dmg_tspec.dest_aid",
FT_UINT24, BASE_HEX, NULL, 0x7f8000,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_allocation_period,
{"Allocation Period","wlan.dmg_tspec.allocation_period",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_min_allocation,
{"Minimal Allocation","wlan.dmg_tspec.min_allocation",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_max_allocation,
{"Maximal Allocation","wlan.dmg_tspec.max_allocation",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_min_duration,
{"Minimal Duration","wlan.dmg_tspec.min_duration",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_num_of_constraints,
{"Number Of Constraints","wlan.dmg_tspec.num_of_constraints",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_tsconst_start_time,
{"TS Constraint Start Time","wlan.dmg_tspec.tsconst.start_time",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_tsconst_duration,
{"TS Constraint Duration","wlan.dmg_tspec.tsconst.duration",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_tsconst_period,
{"TS Constraint Period","wlan.dmg_tspec.tsconst.period",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_tspec_tsconst_interferer_mac,
{"TS Constraint Interferer MAC Address","wlan.dmg_tspec.tsconst.interferer_mac",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_channel_measurement_feedback_realtive_I,
{"Channel Measurement Feedback Relative I","wlan.ch_meas_fb.realtive_I",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_channel_measurement_feedback_realtive_Q,
{"Channel Measurement Feedback Relative Q","wlan.ch_meas_fb.realtive_Q",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_channel_measurement_feedback_tap_delay,
{"Channel Measurement Feedback Tap Delay","wlan.ch_meas_fb.tap_delay",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_channel_measurement_feedback_sector_id,
{"Channel Measurement Feedback Secotr ID","wlan.ch_meas_fb.sector_id",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL }},
{&hf_ieee80211_tag_channel_measurement_feedback_antenna_id,
{"Channel Measurement Feedback Antenna ID","wlan.ch_meas_fb.antenna_id",
FT_UINT8, BASE_DEC, NULL, 0x03,
NULL, HFILL }},
{&hf_ieee80211_tag_awake_window,
{"Awake Window","wlan.awake_window",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_addba_ext_no_frag,
{"ADDBA No Fragmentation","wlan.addba.no_frag",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_ctrl_sta_role,
{"STA Rold","wlan.multi_band.ctrl_sta_role",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_ctrl_addr_present,
{"STA MAC Address Present","wlan.multi_band.ctrl_addr_present",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_ctrl_cipher_present,
{"PCS Present","wlan.multi_band.ctrl_cipher_present",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_oper_class,
{"Operating Class","wlan.multi_band.oper_class",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_channel_number,
{"Channel Number","wlan.multi_band.channel_number",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_tsf_offset,
{"TSF Offset","wlan.multi_band.tsf_offset",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_conn_ap,
{"Connection Capability AP","wlan.multi_band.conn_ap",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_conn_pcp,
{"Connection Capability PCP","wlan.multi_band.conn_pcp",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_conn_dls,
{"Connection Capability DLS","wlan.multi_band.conn_dls",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_conn_tdls,
{"Connection Capability TDLS","wlan.multi_band.conn_tdls",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_conn_ibss,
{"Connection Capability IBSS","wlan.multi_band.conn_ibss",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_fst_timeout,
{"FST Session Timeout","wlan.multi_band.fst_timeout",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_multi_band_sta_mac,
{"Transmitting STA MAC Address","wlan.multi_band.sta_mac",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_activity,
{"Activity","wlan.activity",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_dmg_link_adapt_mcs,
{"MCS","wlan.dmg_link_adapt.mcs",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_dmg_link_adapt_link_margin,
{"Link Margin","wlan.dmg_link_adapt.link_margin",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ref_timestamp,
{"Reference Timestamp","wlan.ref_timestamp",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_switching_stream_non_qos,
{"Non-Qos Data Frames","wlan.switching_stream.non_qos",
FT_BOOLEAN, 8, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_switching_stream_param_num,
{"Number Of Switching Stream Elements","wlan.switching_stream.param_num",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_switching_stream_old_tid,
{"Old Band TID","wlan.switching_stream.old_tid",
FT_UINT16, BASE_DEC, NULL, 0xf000,
NULL, HFILL }},
{&hf_ieee80211_tag_switching_stream_old_direction,
{"Old Band Direction","wlan.switching_stream.old_direction",
FT_BOOLEAN, 16, NULL, 0x0800,
NULL, HFILL }},
{&hf_ieee80211_tag_switching_stream_new_tid,
{"New Band TID","wlan.switching_stream.new_tid",
FT_UINT16, BASE_DEC, NULL, 0x0780,
NULL, HFILL }},
{&hf_ieee80211_tag_switching_stream_new_direction,
{"New Band Direction","wlan.switching_stream.new_direction",
FT_BOOLEAN, 16, NULL, 0x0040,
NULL, HFILL }},
{&hf_ieee80211_tag_switching_stream_new_valid_id,
{"Stream ID in New Band Valid","wlan.switching_stream.new_valid_id",
FT_BOOLEAN, 16, NULL, 0x0020,
NULL, HFILL }},
{&hf_ieee80211_tag_switching_stream_llt_type,
{"LLT Type","wlan.switching_stream.llt_type",
FT_BOOLEAN, 16, NULL, 0x0010,
NULL, HFILL }},
};
static hf_register_info ff[] = {
{&hf_ieee80211_ff_timestamp,
{"Timestamp", "wlan_mgt.fixed.timestamp",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_auth_alg,
{"Authentication Algorithm", "wlan_mgt.fixed.auth.alg",
FT_UINT16, BASE_DEC, VALS(auth_alg), 0,
NULL, HFILL }},
{&hf_ieee80211_ff_beacon_interval,
{"Beacon Interval", "wlan_mgt.fixed.beacon",
FT_UINT32, BASE_CUSTOM, CF_FUNC(beacon_interval_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_fixed_parameters,
{"Fixed parameters", "wlan_mgt.fixed.all",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tagged_parameters,
{"Tagged parameters", "wlan_mgt.tagged.all",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ssid,
{"SSID", "wlan_mgt.ssid",
FT_STRING, BASE_NONE, NULL, 0,
"Indicates the identity of an ESS or IBSS", HFILL }},
{&hf_ieee80211_tag_supp_rates,
{"Supported Rates", "wlan_mgt.supported_rates",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ieee80211_supported_rates_vals_ext, 0x0,
"In Mbit/sec, (B) for Basic Rates", HFILL }},
{&hf_ieee80211_tag_fh_dwell_time,
{"Dwell Time", "wlan_mgt.fh.dwell_time",
FT_UINT16, BASE_HEX, NULL, 0x0,
"In Time Unit (TU)", HFILL }},
{&hf_ieee80211_tag_fh_hop_set,
{"Hop Set", "wlan_mgt.fh.hop_set",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_fh_hop_pattern,
{"Hop Pattern", "wlan_mgt.fh.hop_pattern",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_fh_hop_index,
{"Hop Index", "wlan_mgt.fh.hop_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_params,
{"Block Ack Parameters", "wlan_mgt.fixed.baparams",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_params_amsdu_permitted,
{"A-MSDUs", "wlan_mgt.fixed.baparams.amsdu",
FT_BOOLEAN, 16, TFS (&ff_block_ack_params_amsdu_permitted_flag), 0x0001,
"A-MSDU Permitted in QoS Data MPDUs", HFILL }},
{&hf_ieee80211_ff_block_ack_params_policy,
{"Block Ack Policy", "wlan_mgt.fixed.baparams.policy",
FT_BOOLEAN, 16, TFS (&ff_block_ack_params_policy_flag), 0x0002,
NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_params_tid,
{"Traffic Identifier", "wlan_mgt.fixed.baparams.tid",
FT_UINT16, BASE_HEX, NULL, 0x003C,
NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_params_buffer_size,
{"Number of Buffers (1 Buffer = 2304 Bytes)", "wlan_mgt.fixed.baparams.buffersize",
FT_UINT16, BASE_DEC, NULL, 0xFFC0,
"Number of Buffers", HFILL }},
{&hf_ieee80211_ff_block_ack_timeout,
{"Block Ack Timeout", "wlan_mgt.fixed.batimeout",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_ssc,
{"Block Ack Starting Sequence Control (SSC)", "wlan_mgt.fixed.ssc",
FT_UINT16, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_ssc_fragment,
{"Fragment", "wlan_mgt.fixed.ssc.fragment",
FT_UINT16, BASE_DEC, 0, 0x000f,
NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_ssc_sequence,
{"Starting Sequence Number", "wlan_mgt.fixed.ssc.sequence",
FT_UINT16, BASE_DEC, 0, 0xfff0,
NULL, HFILL }},
{&hf_ieee80211_ff_delba_param,
{"Delete Block Ack (DELBA) Parameter Set", "wlan_mgt.fixed.delba.param",
FT_UINT16, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_delba_param_reserved,
{"Reserved", "wlan_mgt.fixed.delba.param.reserved",
FT_UINT16, BASE_HEX, 0, 0x07ff,
NULL, HFILL }},
{&hf_ieee80211_ff_delba_param_init,
{"Initiator", "wlan_mgt.fixed.delba.param.initiator",
FT_BOOLEAN, 16, 0, 0x0800,
NULL, HFILL }},
{&hf_ieee80211_ff_delba_param_tid,
{"TID", "wlan_mgt.fixed.delba.param.tid",
FT_UINT16, BASE_HEX, 0, 0xf000,
"Traffic Identifier (TID)", HFILL }},
{&hf_ieee80211_ff_max_reg_pwr,
{"Maximum Regulation Power", "wlan_mgt.fixed.maxregpwr",
FT_UINT16, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_measurement_pilot_int,
{"Measurement Pilot Interval", "wlan_mgt.fixed.msmtpilotint",
FT_UINT16, BASE_HEX, 0, 0,
"Measurement Pilot Interval Fixed Field", HFILL }},
{&hf_ieee80211_ff_country_str,
{"Country String", "wlan_mgt.fixed.country",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_max_tx_pwr,
{"Maximum Transmit Power", "wlan_mgt.fixed.maxtxpwr",
FT_UINT8, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_tx_pwr_used,
{"Transmit Power Used", "wlan_mgt.fixed.txpwr",
FT_UINT8, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_transceiver_noise_floor,
{"Transceiver Noise Floor", "wlan_mgt.fixed.tnoisefloor",
FT_UINT8, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_channel_width,
{"Supported Channel Width", "wlan_mgt.fixed.chanwidth",
FT_UINT8, BASE_HEX, VALS(ff_channel_width_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_ap,
{"QoS Information (AP)", "wlan_mgt.fixed.qosinfo.ap",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_ap_edca_param_set_counter,
{"EDCA Parameter Set Update Count", "wlan_mgt.fixed.qosinfo.ap.edcaupdate",
FT_UINT8, BASE_HEX, NULL, 0x0F,
"Enhanced Distributed Channel Access (EDCA) Parameter Set Update Count", HFILL }},
{&hf_ieee80211_ff_qos_info_ap_q_ack,
{"Q-Ack", "wlan_mgt.fixed.qosinfo.ap.qack",
FT_BOOLEAN, 8, TFS (&ff_qos_info_ap_q_ack_flag), 0x10,
"QoS Ack", HFILL }},
{&hf_ieee80211_ff_qos_info_ap_queue_req,
{"Queue Request", "wlan_mgt.fixed.qosinfo.ap.queue_req",
FT_BOOLEAN, 8, TFS (&ff_qos_info_ap_queue_req_flag), 0x20,
NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_ap_txop_request,
{"TXOP Request", "wlan_mgt.fixed.qosinfo.ap.txopreq",
FT_BOOLEAN, 8, TFS (&ff_qos_info_ap_txop_request_flag), 0x40,
"Transmit Opportunity (TXOP) Request", HFILL }},
{&hf_ieee80211_ff_qos_info_ap_reserved,
{"Reserved", "wlan_mgt.fixed.qosinfo.ap.reserved",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta,
{"QoS Information (STA)", "wlan_mgt.fixed.qosinfo.sta",
FT_UINT8, BASE_HEX, NULL, 0,
"TCLAS Processing", HFILL }},
{&hf_ieee80211_ff_qos_info_sta_ac_vo,
{"AC_VO U-APSD Flag", "wlan_mgt.fixed.qosinfo.sta.ac_vo",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_ac_flag), 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_ac_vi,
{"AC_VI U-APSD Flag", "wlan_mgt.fixed.qosinfo.sta.ac_vi",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_ac_flag), 0x02,
NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_ac_bk,
{"AC_BK U-APSD Flag", "wlan_mgt.fixed.qosinfo.sta.ac_bk",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_ac_flag), 0x04,
NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_ac_be,
{"AC_BE U-APSD Flag", "wlan_mgt.fixed.qosinfo.sta.ac_be",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_ac_flag), 0x08,
NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_q_ack,
{"Q-Ack", "wlan_mgt.fixed.qosinfo.sta.qack",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_q_ack_flag), 0x10,
"QoS Ack", HFILL }},
{&hf_ieee80211_ff_qos_info_sta_max_sp_length,
{"Max SP Length", "wlan_mgt.fixed.qosinfo.sta.max_sp_length",
FT_UINT8, BASE_HEX, VALS(ff_qos_info_sta_max_sp_len_flags) , 0x60,
NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_more_data_ack,
{"More Data Ack", "wlan_mgt.fixed.qosinfo.sta.more_data_ack",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_more_data_ack_flag), 0x80,
NULL, HFILL }},
{&hf_ieee80211_ff_sm_pwr_save,
{"Spatial Multiplexing (SM) Power Control", "wlan_mgt.fixed.sm.powercontrol",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_sm_pwr_save_enabled,
{"SM Power Save", "wlan_mgt.fixed.sm.powercontrol.enabled",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x01,
"Spatial Multiplexing (SM) Power Save", HFILL }},
{&hf_ieee80211_ff_sm_pwr_save_sm_mode,
{"SM Mode", "wlan_mgt.fixed.sm.powercontrol.mode",
FT_BOOLEAN, 8, TFS (&ff_sm_pwr_save_sm_mode_flag), 0x02,
"Spatial Multiplexing (SM) Mode", HFILL }},
{&hf_ieee80211_ff_sm_pwr_save_reserved,
{"Reserved", "wlan_mgt.fixed.sm.powercontrol.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFC,
NULL, HFILL }},
{&hf_ieee80211_ff_pco_phase_cntrl,
{"Phased Coexistence Operation (PCO) Phase Control", "wlan_mgt.fixed.pco.phasecntrl",
FT_BOOLEAN, BASE_NONE, TFS (&ff_pco_phase_cntrl_flag), 0x0,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_param_set,
{"Power Save Multi-Poll (PSMP) Parameter Set", "wlan_mgt.fixed.psmp.paramset",
FT_UINT16, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_param_set_n_sta,
{"Number of STA Info Fields Present", "wlan_mgt.fixed.psmp.paramset.nsta",
FT_UINT16, BASE_HEX, 0, 0x000F,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_param_set_more_psmp,
{"More PSMP", "wlan_mgt.fixed.psmp.paramset.more",
FT_BOOLEAN, 16, TFS(&ff_psmp_param_set_more_psmp_flag), 0x0010,
"More Power Save Multi-Poll (PSMP)", HFILL }},
{&hf_ieee80211_ff_psmp_param_set_psmp_sequence_duration,
{"PSMP Sequence Duration [us]", "wlan_mgt.fixed.psmp.paramset.seqduration",
FT_UINT16, BASE_DEC, 0, 0xFFE0,
"Power Save Multi-Poll (PSMP) Sequence Duration", HFILL }},
{&hf_ieee80211_ff_mimo_cntrl,
{"MIMO Control", "wlan_mgt.fixed.mimo.control",
FT_BYTES, BASE_NONE, 0, 0x0,
NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_nc_index,
{"Nc Index", "wlan_mgt.fixed.mimo.control.ncindex",
FT_UINT16, BASE_HEX, VALS(ff_mimo_cntrl_nc_index_flags), 0x0003,
"Number of Columns Less One", HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_nr_index,
{"Nr Index", "wlan_mgt.fixed.mimo.control.nrindex",
FT_UINT16, BASE_HEX, VALS(ff_mimo_cntrl_nr_index_flags), 0x000C,
"Number of Rows Less One", HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_channel_width,
{"Channel Width", "wlan_mgt.fixed.mimo.control.chanwidth",
FT_BOOLEAN, 16, TFS(&ff_mimo_cntrl_channel_width_flag), 0x0010,
NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_grouping,
{"Grouping (Ng)", "wlan_mgt.fixed.mimo.control.grouping",
FT_UINT16, BASE_HEX, VALS(ff_mimo_cntrl_grouping_flags), 0x0060,
NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_coefficient_size,
{"Coefficient Size (Nb)", "wlan_mgt.fixed.mimo.control.cosize",
FT_UINT16, BASE_HEX, VALS(ff_mimo_cntrl_coefficient_size_flags), 0x0180,
NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_codebook_info,
{"Codebook Information", "wlan_mgt.fixed.mimo.control.codebookinfo",
FT_UINT16, BASE_HEX, VALS(ff_mimo_cntrl_codebook_info_flags), 0x0600,
NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_remaining_matrix_segment,
{"Remaining Matrix Segment", "wlan_mgt.fixed.mimo.control.matrixseg",
FT_UINT16, BASE_HEX, 0, 0x3800,
NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_reserved,
{"Reserved", "wlan_mgt.fixed.mimo.control.reserved",
FT_UINT16, BASE_HEX, 0, 0xC000,
NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_sounding_timestamp,
{"Sounding Timestamp", "wlan_mgt.fixed.mimo.control.soundingtime",
FT_UINT32, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info,
{"Power Save Multi-Poll (PSMP) Station Information", "wlan_mgt.fixed.psmp.stainfo",
FT_UINT64, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_type,
{"Sta Info Type", "wlan_mgt.fixed.psmp.stainfo.type",
FT_UINT32, BASE_HEX, VALS(ff_psmp_sta_info_flags), PSMP_STA_INFO_FLAG_TYPE,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_dtt_start_offset,
{"DTT Start Offset", "wlan_mgt.fixed.psmp.stainfo.dttstart",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_DTT_START,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_dtt_duration,
{"DTT Duration", "wlan_mgt.fixed.psmp.stainfo.dttduration",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_DTT_DURATION,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_sta_id,
{"Target Station ID", "wlan_mgt.fixed.psmp.stainfo.staid",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_STA_ID,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_utt_start_offset,
{"UTT Start Offset", "wlan_mgt.fixed.psmp.stainfo.uttstart",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_UTT_START,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_utt_duration,
{"UTT Duration", "wlan_mgt.fixed.psmp.stainfo.uttduration",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_UTT_DURATION,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_reserved_small,
{"Reserved", "wlan_mgt.fixed.psmp.stainfo.reserved",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_IA_RESERVED,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_reserved_large,
{"Reserved", "wlan_mgt.fixed.psmp.stainfo.reserved",
FT_UINT64, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_psmp_multicast_id,
{"Power Save Multi-Poll (PSMP) Multicast ID", "wlan_mgt.fixed.psmp.stainfo.multicastid",
FT_UINT64, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection,
{"Antenna Selection", "wlan_mgt.fixed.antsel",
FT_UINT8, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_0,
{"Antenna 0", "wlan_mgt.fixed.antsel.ant0",
FT_UINT8, BASE_HEX, 0, 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_1,
{"Antenna 1", "wlan_mgt.fixed.antsel.ant1",
FT_UINT8, BASE_HEX, 0, 0x02,
NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_2,
{"Antenna 2", "wlan_mgt.fixed.antsel.ant2",
FT_UINT8, BASE_HEX, 0, 0x04,
NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_3,
{"Antenna 3", "wlan_mgt.fixed.antsel.ant3",
FT_UINT8, BASE_HEX, 0, 0x08,
NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_4,
{"Antenna 4", "wlan_mgt.fixed.antsel.ant4",
FT_UINT8, BASE_HEX, 0, 0x10,
NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_5,
{"Antenna 5", "wlan_mgt.fixed.antsel.ant5",
FT_UINT8, BASE_HEX, 0, 0x20,
NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_6,
{"Antenna 6", "wlan_mgt.fixed.antsel.ant6",
FT_UINT8, BASE_HEX, 0, 0x40,
NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_7,
{"Antenna 7", "wlan_mgt.fixed.antsel.ant7",
FT_UINT8, BASE_HEX, 0, 0x80,
NULL, HFILL }},
{&hf_ieee80211_ff_ext_channel_switch_announcement,
{"Extended Channel Switch Announcement", "wlan_mgt.fixed.extchansw",
FT_UINT32, BASE_HEX, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_ext_channel_switch_announcement_switch_mode,
{"Channel Switch Mode", "wlan_mgt.fixed.extchansw.switchmode",
FT_UINT32, BASE_HEX, VALS(ieee80211_tag_ext_channel_switch_announcement_switch_mode_flags), 0x000000FF,
NULL, HFILL }},
{&hf_ieee80211_ff_ext_channel_switch_announcement_new_ope_class,
{"New Operating Class", "wlan_mgt.fixed.extchansw.new.opeclass",
FT_UINT32, BASE_HEX, NULL, 0x0000FF00,
NULL, HFILL }},
{&hf_ieee80211_ff_ext_channel_switch_announcement_new_chan_number,
{"New Channel Number", "wlan_mgt.fixed.extchansw.new.channumber",
FT_UINT32, BASE_HEX, NULL, 0x00FF0000,
NULL, HFILL }},
{&hf_ieee80211_ff_ext_channel_switch_announcement_switch_count,
{"Channel Switch Count", "wlan_mgt.extchanswitch.switchcount",
FT_UINT32, BASE_HEX, NULL, 0xFF000000,
NULL, HFILL }},
{&hf_ieee80211_ff_ht_info,
{"HT Information", "wlan_mgt.fixed.extchansw",
FT_UINT8, BASE_HEX, 0, 0,
"HT Information Fixed Field", HFILL }},
{&hf_ieee80211_ff_ht_info_information_request,
{"Information Request", "wlan_mgt.fixed.mimo.control.chanwidth",
FT_BOOLEAN, 8, TFS(&ff_ht_info_information_request_flag), 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_ht_info_40_mhz_intolerant,
{"40 MHz Intolerant", "wlan_mgt.fixed.mimo.control.chanwidth",
FT_BOOLEAN, 8, TFS(&ff_ht_info_40_mhz_intolerant_flag), 0x02,
NULL, HFILL }},
{&hf_ieee80211_ff_ht_info_sta_chan_width,
{"Station Channel Width", "wlan_mgt.fixed.mimo.control.chanwidth",
FT_BOOLEAN, 8, TFS(&ff_ht_info_sta_chan_width_flag), 0x04,
NULL, HFILL }},
{&hf_ieee80211_ff_ht_info_reserved,
{"Reserved", "wlan_mgt.fixed.extchansw",
FT_UINT8, BASE_HEX, 0, 0xF8,
"Reserved Field", HFILL }},
{&hf_ieee80211_ff_ht_action,
{"HT Action", "wlan_mgt.fixed.htact",
FT_UINT8, BASE_HEX, VALS(ff_ht_action_flags), 0,
"HT Action Code", HFILL }},
{&hf_ieee80211_ff_mimo_csi_snr,
{"Signal to Noise Ratio (SNR)", "wlan_mgt.mimo.csimatrices.snr",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mimo_csi_matrices,
{"CSI Matrices", "wlan_mgt.mimo.csimatrices",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mimo_csi_bf_matrices,
{"Beamforming Feedback Matrices", "wlan_mgt.mimo.csimatrices.bf",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mimo_csi_cbf_matrices,
{"Compressed Beamforming Feedback Matrices", "wlan_mgt.mimo.csimatrices.cbf",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_public_action,
{"Public Action", "wlan_mgt.fixed.publicact",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ff_pa_action_codes_ext, 0,
"Public Action Code", HFILL }},
{&hf_ieee80211_ff_protected_public_action,
{"Protected Public Action", "wlan_mgt.fixed.publicact",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ff_ppa_action_codes_ext, 0,
"Protected Public Action Code", HFILL }},
{&hf_ieee80211_ff_capture,
{"Capabilities Information", "wlan_mgt.fixed.capabilities",
FT_UINT16, BASE_HEX, NULL, 0,
"Capability information", HFILL }},
{&hf_ieee80211_ff_cf_ess,
{"ESS capabilities", "wlan_mgt.fixed.capabilities.ess",
FT_BOOLEAN, 16, TFS (&cf_ess_flags), 0x0001,
NULL, HFILL }},
{&hf_ieee80211_ff_cf_ibss,
{"IBSS status", "wlan_mgt.fixed.capabilities.ibss",
FT_BOOLEAN, 16, TFS(&cf_ibss_flags), 0x0002,
"IBSS participation", HFILL }},
{&hf_ieee80211_ff_cf_sta_poll,
{"CFP participation capabilities", "wlan_mgt.fixed.capabilities.cfpoll.sta",
FT_UINT16, BASE_HEX, VALS(sta_cf_pollable), 0x020C,
"CF-Poll capabilities for a STA", HFILL }},
{&hf_ieee80211_ff_cf_ap_poll,
{"CFP participation capabilities", "wlan_mgt.fixed.capabilities.cfpoll.ap",
FT_UINT16, BASE_HEX, VALS(ap_cf_pollable), 0x020C,
"CF-Poll capabilities for an AP", HFILL }},
{&hf_ieee80211_ff_cf_privacy,
{"Privacy", "wlan_mgt.fixed.capabilities.privacy",
FT_BOOLEAN, 16, TFS(&cf_privacy_flags), 0x0010,
"WEP support", HFILL }},
{&hf_ieee80211_ff_cf_preamble,
{"Short Preamble", "wlan_mgt.fixed.capabilities.preamble",
FT_BOOLEAN, 16, TFS(&tfs_allowed_not_allowed), 0x0020,
NULL, HFILL }},
{&hf_ieee80211_ff_cf_pbcc,
{"PBCC", "wlan_mgt.fixed.capabilities.pbcc",
FT_BOOLEAN, 16, TFS(&tfs_allowed_not_allowed), 0x0040,
"PBCC Modulation", HFILL }},
{&hf_ieee80211_ff_cf_agility,
{"Channel Agility", "wlan_mgt.fixed.capabilities.agility",
FT_BOOLEAN, 16, TFS(&tfs_inuse_not_inuse), 0x0080,
NULL, HFILL }},
{&hf_ieee80211_ff_cf_spec_man,
{"Spectrum Management", "wlan_mgt.fixed.capabilities.spec_man",
FT_BOOLEAN, 16, TFS(&tfs_implemented_not_implemented), 0x0100,
NULL, HFILL }},
{&hf_ieee80211_ff_short_slot_time,
{"Short Slot Time", "wlan_mgt.fixed.capabilities.short_slot_time",
FT_BOOLEAN, 16, TFS(&tfs_inuse_not_inuse), 0x0400,
NULL, HFILL }},
{&hf_ieee80211_ff_cf_apsd,
{"Automatic Power Save Delivery", "wlan_mgt.fixed.capabilities.apsd",
FT_BOOLEAN, 16, TFS(&tfs_implemented_not_implemented), 0x0800,
NULL, HFILL }},
{&hf_ieee80211_ff_radio_measurement,
{"Radio Measurement", "wlan_mgt.fixed.capabilities.radio_measurement",
FT_BOOLEAN, 16, TFS(&tfs_implemented_not_implemented), 0x1000,
NULL, HFILL }},
{&hf_ieee80211_ff_dsss_ofdm,
{"DSSS-OFDM", "wlan_mgt.fixed.capabilities.dsss_ofdm",
FT_BOOLEAN, 16, TFS(&tfs_allowed_not_allowed), 0x2000,
"DSSS-OFDM Modulation", HFILL }},
{&hf_ieee80211_ff_cf_del_blk_ack,
{"Delayed Block Ack", "wlan_mgt.fixed.capabilities.del_blk_ack",
FT_BOOLEAN, 16, TFS(&tfs_implemented_not_implemented), 0x4000,
NULL, HFILL }},
{&hf_ieee80211_ff_cf_imm_blk_ack,
{"Immediate Block Ack", "wlan_mgt.fixed.capabilities.imm_blk_ack",
FT_BOOLEAN, 16, TFS(&tfs_implemented_not_implemented), 0x8000,
NULL, HFILL }},
{&hf_ieee80211_ff_auth_seq,
{"Authentication SEQ", "wlan_mgt.fixed.auth_seq",
FT_UINT16, BASE_HEX, NULL, 0,
"Authentication Sequence Number", HFILL }},
{&hf_ieee80211_ff_assoc_id,
{"Association ID", "wlan_mgt.fixed.aid",
FT_UINT16, BASE_HEX, NULL, 0x3FFF,
NULL, HFILL }},
{&hf_ieee80211_ff_listen_ival,
{"Listen Interval", "wlan_mgt.fixed.listen_ival",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_current_ap,
{"Current AP", "wlan_mgt.fixed.current_ap",
FT_ETHER, BASE_NONE, NULL, 0,
"MAC address of current AP", HFILL }},
{&hf_ieee80211_ff_reason,
{"Reason code", "wlan_mgt.fixed.reason_code",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &ieee80211_reason_code_ext, 0,
"Reason for unsolicited notification", HFILL }},
{&hf_ieee80211_ff_status_code,
{"Status code", "wlan_mgt.fixed.status_code",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &ieee80211_status_code_ext, 0,
"Status of requested event", HFILL }},
{&hf_ieee80211_ff_category_code,
{"Category code", "wlan_mgt.fixed.category_code",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &category_codes_ext, 0,
"Management action category", HFILL }},
{&hf_ieee80211_ff_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT16, BASE_DEC, VALS(action_codes), 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_dialog_token,
{"Dialog token", "wlan_mgt.fixed.dialog_token",
FT_UINT8, BASE_HEX, NULL, 0,
"Management action dialog token", HFILL }},
{&hf_ieee80211_ff_followup_dialog_token,
{"Followup Dialog token", "wlan_mgt.fixed.followup_dialog_token",
FT_UINT8, BASE_HEX, NULL, 0,
"Management action followup dialog token", HFILL }},
{&hf_ieee80211_ff_marvell_action_type,
{"Marvell Action type", "wlan_mgt.fixed.mrvl_action_type",
FT_UINT8, BASE_DEC, VALS(vendor_action_types_mrvl), 0,
"Vendor Specific Action Type (Marvell)", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_action_code,
{"Mesh action(Marvell)", "wlan_mgt.fixed.mrvl_mesh_action",
FT_UINT8, BASE_HEX, VALS(mesh_mgt_action_codes_mrvl), 0,
"Mesh action code(Marvell)", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_length,
{"Message Length", "wlan_mgt.fixed.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_mode,
{"Message Mode", "wlan_mgt.fixed.mode",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_ttl,
{"Message TTL", "wlan_mgt.fixed.ttl",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_dstcount,
{"Destination Count", "wlan_mgt.fixed.dstcount",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_hopcount,
{"Hop Count", "wlan_mgt.fixed.hopcount",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_rreqid,
{"RREQ ID", "wlan_mgt.fixed.rreqid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_sa,
{"Source Address", "wlan_mgt.fixed.sa",
FT_ETHER, BASE_NONE, NULL, 0,
"Source MAC address", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_ssn,
{"SSN", "wlan_mgt.fixed.ssn",
FT_UINT32, BASE_DEC, NULL, 0,
"Source Sequence Number", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_metric,
{"Metric", "wlan_mgt.fixed.metric",
FT_UINT32, BASE_DEC, NULL, 0,
"Route Metric", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_flags,
{"RREQ Flags", "wlan_mgt.fixed.hopcount",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_da,
{"Destination Address", "wlan_mgt.fixed.da",
FT_ETHER, BASE_NONE, NULL, 0,
"Destination MAC address", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_dsn,
{"DSN", "wlan_mgt.fixed.dsn",
FT_UINT32, BASE_DEC, NULL, 0,
"Destination Sequence Number", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_lifetime,
{"Lifetime", "wlan_mgt.fixed.lifetime",
FT_UINT32, BASE_DEC, NULL, 0,
"Route Lifetime", HFILL }},
{&hf_ieee80211_ff_wme_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT16, BASE_HEX, VALS(wme_action_codes), 0,
"Management notification action code", HFILL }},
{&hf_ieee80211_ff_wme_status_code,
{"Status code", "wlan_mgt.fixed.status_code",
FT_UINT16, BASE_HEX, VALS(wme_status_codes), 0,
"Management notification setup response status code", HFILL }},
{&hf_ieee80211_ff_mesh_action,
{"Mesh Action code", "wlan_mgt.fixed.mesh_action",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &mesh_action_ext, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_multihop_action,
{"Multihop Action code", "wlan_mgt.fixed.multihop_action",
FT_UINT8, BASE_HEX, VALS(multihop_action), 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mesh_flags,
{"Mesh Flags", "wlan_mgt.fixed.mesh_flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mesh_ttl,
{"Mesh TTL", "wlan_mgt.fixed.mesh_ttl",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mesh_sequence,
{"Sequence Number", "wlan_mgt.fixed.mesh_sequence",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mesh_addr4,
{"Mesh Extended Address 4", "wlan_mgt.fixed.mesh_addr4",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mesh_addr5,
{"Mesh Extended Address 5", "wlan_mgt.fixed.mesh_addr5",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mesh_addr6,
{"Mesh Extended Address 6", "wlan_mgt.fixed.mesh_addr6",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_selfprot_action,
{"Self-protected Action code", "wlan_mgt.fixed.selfprot_action",
FT_UINT8, BASE_HEX, VALS(selfprot_action), 0,
NULL, HFILL }},
{&hf_ieee80211_mesh_peering_proto,
{"Mesh Peering Protocol ID", "wlan.peering.proto",
FT_UINT16, BASE_HEX, VALS(mesh_peering_proto_ids), 0,
NULL, HFILL }},
{&hf_ieee80211_mesh_peering_local_link_id,
{"Local Link ID", "wlan.peering.local_id",
FT_UINT16, BASE_HEX, NULL, 0,
"Mesh Peering Management Local Link ID", HFILL }},
{&hf_ieee80211_mesh_peering_peer_link_id,
{"Peer Link ID", "wlan.peering.peer_id",
FT_UINT16, BASE_HEX, NULL, 0,
"Mesh Peering Management Peer Link ID", HFILL }},
{&hf_ieee80211_ff_hwmp_flags,
{"HWMP Flags", "wlan.hwmp.flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_hopcount,
{"HWMP Hop Count", "wlan.hwmp.hopcount",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_ttl,
{"HWMP TTL", "wlan.hwmp.ttl",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_pdid,
{"HWMP Path Discovery ID", "wlan.hwmp.pdid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_orig_sta,
{"Originator STA Address", "wlan.hwmp.orig_sta",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_orig_sn,
{"HWMP Originator Sequence Number", "wlan.hwmp.orig_sn",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{&hf_ieee80211_ff_hwmp_orig_ext,
{"Originator External Address", "wlan.hwmp.orig_ext",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_lifetime,
{"HWMP Lifetime", "wlan.hwmp.lifetime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_metric,
{"HWMP Metric", "wlan.hwmp.metric",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_targ_count,
{"HWMP Target Count", "wlan.hwmp.targ_count",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_targ_flags,
{"HWMP Per-Target Flags", "wlan.hwmp.targ_flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_targ_to_flags,
{"TO Flag", "wlan.hwmp.to_flag",
FT_BOOLEAN, 8, TFS (&hwmp_targ_to_flags), 0x01,
"Target Only Flag", HFILL }},
{&hf_ieee80211_ff_hwmp_targ_usn_flags,
{"USN Flag", "wlan.hwmp.usn_flag",
FT_BOOLEAN, 8, TFS (&hwmp_targ_usn_flags), 0x04,
"Unknown Target HWMP Sequence Number Flag", HFILL }},
{&hf_ieee80211_ff_hwmp_targ_sta,
{"Target STA Address", "wlan.hwmp.targ_sta",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_targ_ext,
{"Target External Address", "wlan.hwmp.targ_ext",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_targ_sn,
{"Target HWMP Sequence Number", "wlan.hwmp.targ_sn",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_mesh_config_path_sel_protocol,
{"Path Selection Protocol", "wlan.mesh.config.ps_protocol",
FT_UINT8, BASE_HEX, NULL, 0,
"Mesh Configuration Path Selection Protocol", HFILL }},
{&hf_ieee80211_mesh_config_path_sel_metric,
{"Path Selection Metric", "wlan.mesh.config.ps_metric",
FT_UINT8, BASE_HEX, NULL, 0,
"Mesh Configuration Path Selection Metric", HFILL }},
{&hf_ieee80211_mesh_config_congestion_control,
{"Congestion Control", "wlan.mesh.config.cong_ctl",
FT_UINT8, BASE_HEX, NULL, 0,
"Mesh Configuration Congestion Control", HFILL }},
{&hf_ieee80211_mesh_config_sync_method,
{"Synchronization Method", "wlan.mesh.config.sync_method",
FT_UINT8, BASE_HEX, NULL, 0,
"Mesh Configuration Synchronization Method", HFILL }},
{&hf_ieee80211_mesh_config_auth_protocol,
{"Authentication Protocol", "wlan.mesh.config.auth_protocol",
FT_UINT8, BASE_HEX, NULL, 0,
"Mesh Configuration Authentication Protocol", HFILL }},
{&hf_ieee80211_mesh_config_formation_info,
{"Formation Info", "wlan.mesh.config.formation_info",
FT_UINT8, BASE_HEX, NULL, 0,
"Mesh Configuration Formation Info", HFILL }},
{&hf_ieee80211_mesh_form_info_num_of_peerings,
{"Number of Peerings", "wlan.mesh.config.formation_info.num_peers",
FT_UINT8, BASE_DEC, NULL, 0x7E,
NULL, HFILL }},
{&hf_ieee80211_mesh_config_capability,
{"Capability", "wlan.mesh.config.cap",
FT_UINT8, BASE_HEX, NULL, 0,
"Mesh Configuration Capability", HFILL }},
{&hf_ieee80211_mesh_config_cap_accepting,
{"Accepting Additional Mesh Peerings", "wlan.mesh.config.cap.accept",
FT_BOOLEAN, 8, TFS (&tfs_yes_no), 0x01,
NULL, HFILL }},
{&hf_ieee80211_mesh_config_cap_mcca_support,
{"MCCA Support", "wlan.mesh.config.cap.mcca_support",
FT_BOOLEAN, 8, TFS (&tfs_yes_no), 0x02,
NULL, HFILL }},
{&hf_ieee80211_mesh_config_cap_mcca_enabled,
{"MCCA Enabled", "wlan.mesh.config.cap.mcca_enabled",
FT_BOOLEAN, 8, TFS (&tfs_yes_no), 0x04,
NULL, HFILL }},
{&hf_ieee80211_mesh_config_cap_forwarding,
{"Mesh Forwarding", "wlan.mesh.config.cap.forwarding",
FT_BOOLEAN, 8, TFS (&tfs_yes_no), 0x08,
NULL, HFILL }},
{&hf_ieee80211_mesh_config_cap_mbca_enabled,
{"MBCA Enabled", "wlan.mesh.config.cap.mbca_enabled",
FT_BOOLEAN, 8, TFS (&tfs_yes_no), 0x10,
NULL, HFILL }},
{&hf_ieee80211_mesh_config_cap_tbtt_adjusting,
{"TBTT Adjustment", "wlan.mesh.config.cap.tbtt_adjusting",
FT_BOOLEAN, 8, TFS (&tfs_yes_no), 0x20,
NULL, HFILL }},
{&hf_ieee80211_mesh_config_cap_power_save_level,
{"Power Save", "wlan.mesh.config.cap.power_save_level",
FT_BOOLEAN, 8, TFS (&mesh_config_cap_power_save_level_flags), 0x40,
NULL, HFILL }},
{&hf_ieee80211_mesh_id,
{"Mesh ID", "wlan.mesh.id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_rann_flags,
{"RANN Flags", "wlan.rann.flags",
FT_UINT8, BASE_HEX, NULL, 0,
"Root Announcement Flags", HFILL }},
{&hf_ieee80211_rann_root_sta,
{"Root STA Address", "wlan.rann.root_sta", FT_ETHER, BASE_NONE, NULL, 0,
"Root Mesh STA Address", HFILL }},
{&hf_ieee80211_rann_sn,
{"Root STA Sequence Number", "wlan.rann.rann_sn",
FT_UINT32, BASE_DEC, NULL, 0,
"Root Mesh STA Sequence Number", HFILL }},
{&hf_ieee80211_rann_interval,
{"RANN Interval", "wlan.rann.interval",
FT_UINT32, BASE_DEC, NULL, 0,
"Root Announcement Interval", HFILL }},
{&hf_ieee80211_ff_qos_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT16, BASE_HEX, VALS(qos_action_codes), 0,
"QoS management action code", HFILL }},
{&hf_ieee80211_ff_ba_action,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_HEX, VALS(ba_action_codes), 0,
"Block Ack action code", HFILL }},
{&hf_ieee80211_ff_check_beacon,
{"Check Beacon", "wlan_mgt.fixed.check_beacon",
FT_UINT8, BASE_DEC, NULL, 0,
"Unprotected WNM Check Beacon", HFILL }},
{&hf_ieee80211_ff_tod,
{"TOD", "wlan_mgt.fixed.tod",
FT_UINT32, BASE_DEC, NULL, 0,
"Previous TS of transmit antenna port", HFILL }},
{&hf_ieee80211_ff_toa,
{"TOA", "wlan_mgt.fixed.toa",
FT_UINT32, BASE_DEC, NULL, 0,
"Previous TS of receive antenna port", HFILL }},
{&hf_ieee80211_ff_max_tod_err,
{"MAX TOD ERROR", "wlan_mgt.fixed.max_tod_err",
FT_UINT8, BASE_DEC, NULL, 0,
"Maximal Error at Previous TS of transmit antenna port", HFILL }},
{&hf_ieee80211_ff_max_toa_err,
{"MAX TOA ERROR", "wlan_mgt.fixed.max_toa_err",
FT_UINT8, BASE_DEC, NULL, 0,
"Maximal Error at Previous TS of receive antenna port", HFILL }},
{&hf_ieee80211_ff_dls_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT16, BASE_HEX, VALS(dls_action_codes), 0,
"DLS management action code", HFILL }},
{&hf_ieee80211_ff_dst_mac_addr,
{"Destination address", "wlan_mgt.fixed.dst_mac_addr",
FT_ETHER, BASE_NONE, NULL, 0,
"Destination MAC address", HFILL }},
{&hf_ieee80211_ff_src_mac_addr,
{"Source address", "wlan_mgt.fixed.src_mac_addr",
FT_ETHER, BASE_NONE, NULL, 0,
"Source MAC address", HFILL }},
{&hf_ieee80211_ff_req_ap_addr,
{"RequesterAP address", "wlan_mgt.fixed.req_ap_addr",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_res_ap_addr,
{"ResponderAP address", "wlan_mgt.fixed.res_ap_addr",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_ft_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_DEC, VALS(ft_action_codes), 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_sta_address,
{"STA Address", "wlan_mgt.fixed.sta_address",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_target_ap_address,
{"Target AP Address", "wlan_mgt.fixed.target_ap_address",
FT_ETHER, BASE_NONE, NULL, 0,
"Target AP MAC address", HFILL }},
{&hf_ieee80211_ff_gas_comeback_delay,
{"GAS Comeback Delay", "wlan_mgt.fixed.gas_comeback_delay",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_gas_fragment_id,
{"GAS Query Response Fragment ID", "wlan_mgt.fixed.gas_fragment_id",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }},
{&hf_ieee80211_ff_more_gas_fragments,
{"More GAS Fragments", "wlan_mgt.fixed.more_gas_fragments",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }},
{&hf_ieee80211_ff_query_request_length,
{"Query Request Length", "wlan_mgt.fixed.query_request_length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_query_request,
{"Query Request", "wlan_mgt.fixed.query_request",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_query_response_length,
{"Query Response Length", "wlan_mgt.fixed.query_response_length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_query_response,
{"Query Response", "wlan_mgt.fixed.query_response",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_gas_resp_fragments,
{"GAS Query Response fragments", "wlan_mgt.fixed.fragments",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment,
{"GAS Query Response fragment", "wlan_mgt.fixed.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_overlap,
{"GAS Query Response fragment overlap", "wlan_mgt.fixed.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00,
NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_overlap_conflict,
{"GAS Query Response fragment overlapping with conflicting data", "wlan_mgt.fixed.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00,
NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_multiple_tails,
{"GAS Query Response has multiple tail fragments", "wlan_mgt.fixed.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00,
NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_too_long_fragment,
{"GAS Query Response fragment too long", "wlan_mgt.fixed.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00,
NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_error,
{"GAS Query Response reassembly error", "wlan_mgt.fixed.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_count,
{"GAS Query Response fragment count", "wlan_mgt.fixed.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL } },
{&hf_ieee80211_gas_resp_reassembled_in,
{"Reassembled in", "wlan_mgt.fixed.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL } },
{&hf_ieee80211_gas_resp_reassembled_length,
{"Reassembled length", "wlan_mgt.fixed.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL } },
{&hf_ieee80211_ff_anqp_info_id,
{"Info ID", "wlan_mgt.fixed.anqp.info_id",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &anqp_info_id_vals_ext, 0,
"Access Network Query Protocol Info ID", HFILL }},
{&hf_ieee80211_ff_anqp_info_length,
{"Length", "wlan_mgt.fixed.anqp.info_length",
FT_UINT16, BASE_DEC, NULL, 0,
"Access Network Query Protocol Length", HFILL }},
{&hf_ieee80211_ff_anqp_info,
{"Information", "wlan_mgt.fixed.anqp.info",
FT_BYTES, BASE_NONE, NULL, 0,
"Access Network Query Protocol Information", HFILL }},
{&hf_ieee80211_ff_anqp_query_id,
{"ANQP Query ID", "wlan_mgt.fixed.anqp.query_id",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &anqp_info_id_vals_ext, 0,
"Access Network Query Protocol Query ID", HFILL }},
{&hf_ieee80211_ff_anqp_capability,
{"ANQP Capability", "wlan_mgt.fixed.anqp.capability",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &anqp_info_id_vals_ext, 0,
"Access Network Query Protocol Query ID", HFILL }},
{&hf_ieee80211_ff_anqp_capability_vlen,
{"Vendor-specific Capability Length", "wlan_mgt.fixed.anqp.capability_vlen",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_capability_vendor,
{"Vendor-specific Capability", "wlan_mgt.fixed.anqp.capability_vendor",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_venue_info_group,
{"Venue Group", "wlan_mgt.fixed.venue_info.group",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &venue_group_vals_ext, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_venue_info_type,
{"Venue Type", "wlan_mgt.fixed.venue_info.type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_venue_length,
{"Venue Name Duple Length", "wlan_mgt.fixed.anqp.venue.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_venue_language,
{"Language Code", "wlan_mgt.fixed.anqp.venue.language",
FT_STRING, BASE_NONE, NULL, 0,
"Venue Name Language Code", HFILL }},
{&hf_ieee80211_ff_anqp_venue_name,
{"Venue Name", "wlan_mgt.fixed.anqp.venue.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nw_auth_type_indicator,
{"Network Authentication Type Indicator", "wlan_mgt.fixed.anqp.nw_auth_type.indicator",
FT_UINT8, BASE_DEC, VALS(nw_auth_type_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nw_auth_type_url_len,
{"Re-direct URL Length", "wlan_mgt.fixed.anqp.nw_auth_type.url_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nw_auth_type_url,
{"Re-direct URL", "wlan_mgt.fixed.anqp.nw_auth_type_url",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_roaming_consortium_oi_len,
{"OI Length", "wlan_mgt.fixed.anqp.roaming_consortium.oi_len",
FT_UINT8, BASE_DEC, NULL, 0,
"Roaming Consortium OI Length", HFILL }},
{&hf_ieee80211_ff_anqp_roaming_consortium_oi,
{"OI", "wlan_mgt.fixed.anqp.roaming_consortium.oi",
FT_BYTES, BASE_NONE, NULL, 0,
"Roaming Consortium OI", HFILL }},
{&hf_ieee80211_ff_anqp_ip_addr_avail_ipv6,
{"IPv6 Address", "wlan_mgt.fixed.anqp.ip_addr_availability.ipv6",
FT_UINT8, BASE_DEC, VALS(ip_addr_avail_ipv6_vals), 0x03,
"IP Address Type Availability information for IPv6", HFILL }},
{&hf_ieee80211_ff_anqp_ip_addr_avail_ipv4,
{"IPv4 Address", "wlan_mgt.fixed.anqp.ip_addr_availability.ipv4",
FT_UINT8, BASE_DEC, VALS(ip_addr_avail_ipv4_vals), 0xfc,
"IP Address Type Availability information for IPv4", HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_count,
{"NAI Realm Count", "wlan_mgt.fixed.anqp.nai_realm_list.count",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_field_len,
{"NAI Realm Data Field Length", "wlan_mgt.fixed.anqp.nai_realm_list.field_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_encoding,
{"NAI Realm Encoding", "wlan_mgt.fixed.naqp_nai_realm_list.encoding",
FT_UINT8, BASE_DEC, VALS(nai_realm_encoding_vals), 0x01,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_length,
{"NAI Realm Length", "wlan_mgt.fixed.naqp_nai_realm_list.realm_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm,
{"NAI Realm", "wlan_mgt.fixed.naqp_nai_realm_list.realm",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_eap_count,
{"EAP Method Count", "wlan_mgt.fixed.naqp_nai_realm_list.eap_method_count",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_eap_len,
{"EAP Method subfield Length", "wlan_mgt.fixed.naqp_nai_realm_list.eap_method_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_eap_method,
{"EAP Method", "wlan_mgt.fixed.naqp_nai_realm_list.eap_method",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &eap_type_vals_ext, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_auth_param_count,
{"Authentication Parameter Count", "wlan_mgt.fixed.naqp_nai_realm_list.auth_param_count",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_auth_param_id,
{"Authentication Parameter ID", "wlan_mgt.fixed.naqp_nai_realm_list.auth_param_id",
FT_UINT8, BASE_DEC, VALS(nai_realm_auth_param_id_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_auth_param_len,
{"Authentication Parameter Length", "wlan_mgt.fixed.naqp_nai_realm_list.auth_param_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_auth_param_value,
{"Authentication Parameter Value", "wlan_mgt.fixed.naqp_nai_realm_list.auth_param_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_3gpp_gc_gud,
{"GUD", "wlan_mgt.fixed.anqp.3gpp_cellular_info.gud",
FT_UINT8, BASE_DEC, NULL, 0,
"Generic container User Data", HFILL }},
{&hf_ieee80211_3gpp_gc_udhl,
{"UDHL", "wlan_mgt.fixed.anqp.3gpp_cellular_info.udhl",
FT_UINT8, BASE_DEC, NULL, 0,
"User Data Header Length", HFILL }},
{&hf_ieee80211_3gpp_gc_iei,
{"IEI", "wlan_mgt.fixed.anqp.3gpp_cellular_info.iei",
FT_UINT8, BASE_DEC, NULL, 0,
"Information Element Identity", HFILL }},
{&hf_ieee80211_3gpp_gc_plmn_len,
{"PLMN Length", "wlan_mgt.fixed.anqp.3gpp_cellular_info.plmn_len",
FT_UINT8, BASE_DEC, NULL, 0,
"Length of PLMN List value contents", HFILL }},
{&hf_ieee80211_3gpp_gc_num_plmns,
{"Number of PLMNs", "wlan_mgt.fixed.anqp.3gpp_cellular_info.num_plmns",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_domain_name_len,
{"Domain Name Length", "wlan_mgt.fixed.anqp.domain_name_list.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_anqp_domain_name,
{"Domain Name", "wlan_mgt.fixed.anqp.domain_name_list.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_dls_timeout,
{"DLS timeout", "wlan_mgt.fixed.dls_timeout",
FT_UINT16, BASE_HEX, NULL, 0,
"DLS timeout value", HFILL }},
{&hf_ieee80211_ff_sa_query_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_DEC, VALS(sa_query_action_codes), 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_transaction_id,
{"Transaction Id", "wlan_mgt.fixed.transaction_id",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_anqp_wfa_subtype,
{"ANQP WFA Subtype", "wlan_mgt.anqp.wfa.subtype",
FT_UINT8, BASE_DEC, VALS(wfa_subtype_vals), 0, NULL, HFILL }},
{&hf_hs20_indication_dgaf_disabled,
{"DGAF Disabled", "wlan_mgt.hs20.indication.dgaf_disabled",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL }},
{&hf_hs20_anqp_subtype,
{"Subtype", "wlan_mgt.hs20.anqp.subtype",
FT_UINT8, BASE_DEC, VALS(hs20_anqp_subtype_vals), 0,
"Hotspot 2.0 ANQP Subtype", HFILL }},
{&hf_hs20_anqp_reserved,
{"Reserved", "wlan_mgt.hs20.anqp.reserved",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_hs20_anqp_payload,
{"Payload", "wlan_mgt.hs20.anqp.payload",
FT_BYTES, BASE_NONE, NULL, 0,
"Hotspot 2.0 ANQP Payload", HFILL }},
{&hf_hs20_anqp_hs_query_list,
{"Queried Subtype", "wlan_mgt.hs20.anqp.hs_query_list",
FT_UINT8, BASE_DEC, VALS(hs20_anqp_subtype_vals), 0,
"Queried HS 2.0 Element Subtype", HFILL }},
{&hf_hs20_anqp_hs_capability_list,
{"Capability", "wlan_mgt.hs20.anqp.hs_capability_list",
FT_UINT8, BASE_DEC, VALS(hs20_anqp_subtype_vals), 0,
"Hotspot 2.0 ANQP Subtype Capability", HFILL }},
{&hf_hs20_anqp_ofn_length,
{"Length", "wlan_mgt.hs20.anqp.ofn.length",
FT_UINT8, BASE_DEC, NULL, 0,
"Operator Friendly Name Length", HFILL }},
{&hf_hs20_anqp_ofn_language,
{"Language Code", "wlan_mgt.hs20.anqp.ofn.language",
FT_STRING, BASE_NONE, NULL, 0,
"Operator Friendly Name Language Code", HFILL }},
{&hf_hs20_anqp_ofn_name,
{"Operator Friendly Name", "wlan_mgt.hs20.anqp.ofn.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_hs20_anqp_wan_metrics_link_status,
{"Link Status", "wlan_mgt.hs20.anqp.wan_metrics.link_status",
FT_UINT8, BASE_DEC, VALS(hs20_wm_link_status_vals), 0x03, NULL, HFILL }},
{&hf_hs20_anqp_wan_metrics_symmetric_link,
{"Symmetric Link", "wlan_mgt.hs20.anqp.wan_metrics.symmetric_link",
FT_UINT8, BASE_DEC, NULL, 0x04, NULL, HFILL }},
{&hf_hs20_anqp_wan_metrics_at_capacity,
{"At Capacity", "wlan_mgt.hs20.anqp.wan_metrics.at_capacity",
FT_UINT8, BASE_DEC, NULL, 0x08, NULL, HFILL }},
{&hf_hs20_anqp_wan_metrics_reserved,
{"Reserved", "wlan_mgt.hs20.anqp.wan_metrics.reserved",
FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{&hf_hs20_anqp_wan_metrics_downlink_speed,
{"Downlink Speed", "wlan_mgt.hs20.anqp.wan_metrics.downlink_speed",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_hs20_anqp_wan_metrics_uplink_speed,
{"Uplink Speed", "wlan_mgt.hs20.anqp.wan_metrics.uplink_speed",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_hs20_anqp_wan_metrics_downlink_load,
{"Downlink Load", "wlan_mgt.hs20.anqp.wan_metrics.downlink_load",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_hs20_anqp_wan_metrics_uplink_load,
{"Uplink Load", "wlan_mgt.hs20.anqp.wan_metrics.uplink_load",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_hs20_anqp_wan_metrics_lmd,
{"LMD", "wlan_mgt.hs20.anqp.wan_metrics.lmd",
FT_UINT16, BASE_DEC, NULL, 0, "Load Measurement Duration", HFILL }},
{&hf_hs20_anqp_cc_proto_ip_proto,
{"IP Protocol", "wlan_mgt.hs20.anqp.cc.ip_proto",
FT_UINT8, BASE_DEC, NULL, 0,
"ProtoPort Tuple - IP Protocol", HFILL }},
{&hf_hs20_anqp_cc_proto_port_num,
{"Port Number", "wlan_mgt.hs20.anqp.cc.port_num",
FT_UINT16, BASE_DEC, NULL, 0,
"ProtoPort Tuple - Port Number", HFILL }},
{&hf_hs20_anqp_cc_proto_status,
{"Status", "wlan_mgt.hs20.anqp.cc.status",
FT_UINT8, BASE_DEC, VALS(hs20_cc_status_vals), 0,
"ProtoPort Tuple - Status", HFILL }},
{&hf_hs20_anqp_nai_hrq_count,
{"NAI Home Realm Count", "wlan_mgt.hs20.anqp.nai_hrq.count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_hs20_anqp_nai_hrq_encoding_type,
{"NAI Home Realm Encoding Type",
"wlan_mgt.hs20.anqp.nai_hrq.encoding_type",
FT_UINT8, BASE_DEC, VALS(nai_realm_encoding_vals),
0x01, NULL, HFILL }},
{&hf_hs20_anqp_nai_hrq_length,
{"NAI Home Realm Name Length", "wlan_mgt.hs20.anqp.nai_hrq.length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_hs20_anqp_nai_hrq_realm_name,
{"NAI Home Realm Name", "wlan_mgt.hs20.anqp.nai_hrq.name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_hs20_anqp_oper_class_indic,
{"Operating Class", "wlan_mgt.hs20.anqp.oper_class_indic.oper_class",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag,
{"Tag", "wlan_mgt.tag",
FT_NONE, BASE_NONE, 0x0, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_number,
{"Tag Number", "wlan_mgt.tag.number",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &tag_num_vals_ext, 0,
"Element ID", HFILL }},
{&hf_ieee80211_tag_length,
{"Tag length", "wlan_mgt.tag.length",
FT_UINT32, BASE_DEC, NULL, 0,
"Length of tag", HFILL }},
{&hf_ieee80211_tag_interpretation,
{"Tag interpretation", "wlan_mgt.tag.interpretation",
FT_STRING, BASE_NONE, NULL, 0,
"Interpretation of tag", HFILL }},
{&hf_ieee80211_tag_data,
{"Tag Data", "wlan_mgt.tag.data",
FT_BYTES, BASE_NONE, NULL, 0,
"Data Interpretation of tag", HFILL }},
{&hf_ieee80211_tag_oui,
{"OUI", "wlan_mgt.tag.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
"OUI of vendor specific IE", HFILL }},
{&hf_ieee80211_tag_oui_wfa_subtype,
{"WFA Subtype", "wlan_mgt.tag.oui.wfa_subtype",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ds_param_channel,
{"Current Channel", "wlan_mgt.ds.current_channel",
FT_UINT8, BASE_DEC, NULL, 0,
"DS Parameter Set - Current Channel", HFILL }},
{&hf_ieee80211_tag_cfp_count,
{"CFP Count", "wlan_mgt.cfp.count",
FT_UINT8, BASE_DEC, NULL, 0,
"Indicates how many delivery traffic indication messages (DTIMs)", HFILL }},
{&hf_ieee80211_tag_cfp_period,
{"CFP Period", "wlan_mgt.cfp.period",
FT_UINT8, BASE_DEC, NULL, 0,
"Indicates the number of DTIM intervals between the start of CFPs", HFILL }},
{&hf_ieee80211_tag_cfp_max_duration,
{"CFP Max Duration", "wlan_mgt.cfp.max_duration",
FT_UINT16, BASE_DEC, NULL, 0,
"Indicates the maximum duration (in TU) of the CFP that may be generated by this PCF", HFILL }},
{&hf_ieee80211_tag_cfp_dur_remaining,
{"CFP Dur Remaining", "wlan_mgt.cfp.dur_remaining",
FT_UINT16, BASE_DEC, NULL, 0,
"Indicates the maximum time (in TU) remaining in the present CFP", HFILL }},
{&hf_ieee80211_tag_vendor_oui_type,
{"Vendor Specific OUI Type", "wlan_mgt.tag.vendor.oui.type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_vendor_data,
{"Vendor Specific Data", "wlan_mgt.tag.vendor.data",
FT_BYTES, BASE_NONE, NULL, 0,
"Unknown/undecoded Vendor Specific Data", HFILL }},
{&hf_ieee80211_tim_dtim_count,
{"DTIM count", "wlan_mgt.tim.dtim_count",
FT_UINT8, BASE_DEC, NULL, 0,
"Indicates how many Beacon frames (including the current frame) appear before the next DTIM", HFILL }},
{&hf_ieee80211_tim_dtim_period,
{"DTIM period", "wlan_mgt.tim.dtim_period",
FT_UINT8, BASE_DEC, NULL, 0,
"Indicates the number of beacon intervals between successive DTIMs", HFILL }},
{&hf_ieee80211_tim_bmapctl,
{"Bitmap control", "wlan_mgt.tim.bmapctl",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tim_bmapctl_mcast,
{"Multicast", "wlan_mgt.tim.bmapctl.multicast",
FT_BOOLEAN, 8, NULL, 0x1,
"Contains the Traffic Indicator bit associated with Association ID 0", HFILL }},
{&hf_ieee80211_tim_bmapctl_offset,
{"Bitmap Offset", "wlan_mgt.tim.bmapctl.offset",
FT_UINT8, BASE_HEX, NULL, 0xFE,
NULL, HFILL }},
{&hf_ieee80211_tim_partial_virtual_bitmap,
{"Partial Virtual Bitmap", "wlan_mgt.tim.partial_virtual_bitmap",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_ibss_atim_window,
{"Atim Windows", "wlan_mgt.ibss.atim_windows",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Contains the ATIM Window length in TU", HFILL }},
{&hf_ieee80211_tag_country_info_code,
{"Code", "wlan_mgt.country_info.code",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_env,
{"Environment", "wlan_mgt.country_info.environment",
FT_UINT8, BASE_HEX, VALS(environment_vals), 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_pad,
{"Padding", "wlan_mgt.country_info.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_fnm,
{"Country Info", "wlan_mgt.country_info.fnm",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_fnm_fcn,
{"First Channel Number", "wlan_mgt.country_info.fnm.fcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_fnm_nc,
{"Number of Channels", "wlan_mgt.country_info.fnm.nc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_fnm_mtpl,
{"Maximum Transmit Power Level (in dBm)", "wlan_mgt.country_info.fnm.mtpl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_rrc,
{"Country Info", "wlan_mgt.country_info.rrc",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_rrc_oei,
{"Operating Extension Identifier", "wlan_mgt.country_info.rrc.oei",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_rrc_oc,
{"Operating Class", "wlan_mgt.country_info.rrc.oc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_rrc_cc,
{"Coverage Class", "wlan_mgt.country_info.rrc.cc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_fh_hopping_parameter_prime_radix,
{"Prime Radix", "wlan_mgt.fh_hopping.parameter.prime_radix",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_fh_hopping_parameter_nb_channels,
{"Number of Channels", "wlan_mgt.fh_hopping.parameter.nb_channels",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_fh_hopping_table_flag,
{"Flag", "wlan_mgt.fh_hopping.table.flag",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Indicates that a Random Table is present when the value is 1", HFILL }},
{&hf_ieee80211_tag_fh_hopping_table_number_of_sets,
{"Number of Sets", "wlan_mgt.fh_hopping.table.number_of_sets",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the total number of sets within the hopping patterns", HFILL }},
{&hf_ieee80211_tag_fh_hopping_table_modulus,
{"Modulus", "wlan_mgt.fh_hopping.table.modulus",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Indicate the values to be used in the equations to create a hopping sequence from the Random Table information", HFILL }},
{&hf_ieee80211_tag_fh_hopping_table_offset,
{"Offset", "wlan_mgt.fh_hopping.table.offset",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Indicate the values to be used in the equations to create a hopping sequence from the Random Table information", HFILL }},
{&hf_ieee80211_tag_fh_hopping_random_table,
{"Random Table", "wlan_mgt.fh_hopping.table.random_table",
FT_UINT16, BASE_HEX, NULL, 0x0,
"It is a vector of single octet values that indicate the random sequence to be followed during a hopping sequence", HFILL }},
{&hf_ieee80211_tag_request,
{"Requested Element ID", "wlan_mgt.tag.request",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &tag_num_vals_ext, 0,
"The list of elements that are to be included in the responding STA Probe Response frame", HFILL }},
{&hf_ieee80211_tclas_up,
{"User Priority", "wlan_mgt.tclas.user_priority",
FT_UINT8, BASE_DEC, NULL, 0,
"Contains the value of the UP of the associated MSDUs", HFILL }},
{&hf_ieee80211_tclas_class_type,
{"Classifier Type", "wlan_mgt.tclas.class_type",
FT_UINT8, BASE_DEC, VALS (classifier_type), 0,
"Specifies the type of classifier parameters", HFILL }},
{&hf_ieee80211_tclas_class_mask,
{"Classifier Mask", "wlan_mgt.tclas.class_mask",
FT_UINT8, BASE_HEX, NULL, 0,
"Specifies a bitmap where bits that are set to 1 identify a subset of the classifier parameters", HFILL }},
{&hf_ieee80211_tclas_class_mask0_src_addr,
{"Source Address", "wlan_mgt.tclas.class_mask.src_addr",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask0_dst_addr,
{"Destination Address", "wlan_mgt.tclas.class_mask.dst_addr",
FT_UINT8, BASE_HEX, NULL, 0x02, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask0_type,
{"Type", "wlan_mgt.tclas.class_mask.type",
FT_UINT8, BASE_HEX, NULL, 0x04, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask1_ver,
{"Version", "wlan_mgt.tclas.class_mask.version",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask1_src_ip,
{"Source IP Address", "wlan_mgt.tclas.class_mask.src_ip",
FT_UINT8, BASE_HEX, NULL, 0x02, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask1_dst_ip,
{"Destination IP Address", "wlan_mgt.tclas.class_mask.dst_ip",
FT_UINT8, BASE_HEX, NULL, 0x04, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask1_src_port,
{"Source Port", "wlan_mgt.tclas.class_mask.src_port",
FT_UINT8, BASE_HEX, NULL, 0x08, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask1_dst_port,
{"Destination Port", "wlan_mgt.tclas.class_mask.dst_port",
FT_UINT8, BASE_HEX, NULL, 0x10, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask1_ipv4_dscp,
{"DSCP", "wlan_mgt.tclas.class_mask.dscp",
FT_UINT8, BASE_HEX, NULL, 0x20, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask1_ipv4_proto,
{"Protocol", "wlan_mgt.tclas.class_mask.proto",
FT_UINT8, BASE_HEX, NULL, 0x40, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask1_ipv6_flow,
{"Flow Label", "wlan_mgt.tclas.class_mask.flow_label",
FT_UINT8, BASE_HEX, NULL, 0x20, NULL, HFILL }},
{&hf_ieee80211_tclas_class_mask2_tci,
{"802.1Q CLAN TCI", "wlan_mgt.tclas.class_mask.tci",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL }},
{&hf_ieee80211_tclas_src_mac_addr,
{"Source address", "wlan_mgt.tclas.src_mac_addr",
FT_ETHER, BASE_NONE, NULL, 0,
"Classifier Parameters Ethernet Type", HFILL }},
{&hf_ieee80211_tclas_dst_mac_addr,
{"Destination address", "wlan_mgt.tclas.dat_mac_addr",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_ether_type,
{"Ethernet Type", "wlan_mgt.tclas.ether_type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_version,
{"IP Version", "wlan_mgt.tclas.version",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_ipv4_src,
{"IPv4 Src Addr", "wlan_mgt.tclas.ipv4_src",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_ipv4_dst,
{"IPv4 Dst Addr", "wlan_mgt.tclas.ipv4_dst",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_src_port,
{"Source Port", "wlan_mgt.tclas.src_port",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_dst_port,
{"Destination Port", "wlan_mgt.tclas.dst_port",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_dscp,
{"IPv4 DSCP", "wlan_mgt.tclas.dscp",
FT_UINT8, BASE_HEX, NULL, 0,
"IPv4 Differentiated Services Code Point (DSCP) Field", HFILL }},
{&hf_ieee80211_tclas_protocol,
{"Protocol", "wlan_mgt.tclas.protocol",
FT_UINT8, BASE_HEX, NULL, 0,
"IPv4 Protocol", HFILL }},
{&hf_ieee80211_tclas_ipv6_src,
{"IPv6 Src Addr", "wlan_mgt.tclas.ipv6_src",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_ipv6_dst,
{"IPv6 Dst Addr", "wlan_mgt.tclas.ipv6_dst",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_flow,
{"Flow Label", "wlan_mgt.tclas.flow",
FT_UINT24, BASE_HEX, NULL, 0,
"IPv6 Flow Label", HFILL }},
{&hf_ieee80211_tclas_tag_type,
{"802.1Q Tag Type", "wlan_mgt.tclas.tag_type",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_challenge_text,
{"Challenge Text", "wlan_mgt.tag.challenge_text",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_version,
{"RSN Version", "wlan_mgt.rsn.version",
FT_UINT16, BASE_DEC, NULL, 0,
"Indicates the version number of the RSNA protocol", HFILL }},
{&hf_ieee80211_rsn_gcs,
{"Group Cipher Suite", "wlan_mgt.rsn.gcs",
FT_UINT32, BASE_CUSTOM, CF_FUNC(rsn_gcs_base_custom), 0,
"Contains the cipher suite selector used by the BSS to protect broadcast/multicast traffic", HFILL }},
{&hf_ieee80211_rsn_gcs_oui,
{"Group Cipher Suite OUI", "wlan_mgt.rsn.gcs.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_gcs_type,
{"Group Cipher Suite type", "wlan_mgt.rsn.gcs.type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_gcs_80211_type,
{"Group Cipher Suite type", "wlan_mgt.rsn.gcs.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_rsn_cipher_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_pcs_count,
{"Pairwise Cipher Suite Count", "wlan_mgt.rsn.pcs.count",
FT_UINT16, BASE_DEC, NULL, 0,
"Indicates the number of pairwise cipher suite selectors that are contained in the Pairwise Cipher Suite List", HFILL }},
{&hf_ieee80211_rsn_pcs_list,
{"Pairwise Cipher Suite List", "wlan_mgt.rsn.pcs.list",
FT_NONE, BASE_NONE, NULL, 0,
"Contains a series of cipher suite selectors that indicate the pairwisecipher suites", HFILL }},
{&hf_ieee80211_rsn_pcs,
{"Pairwise Cipher Suite", "wlan_mgt.rsn.pcs",
FT_UINT32, BASE_CUSTOM, CF_FUNC(rsn_pcs_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_pcs_oui,
{"Pairwise Cipher Suite OUI", "wlan_mgt.rsn.pcs.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_pcs_type,
{"Pairwise Cipher Suite type", "wlan_mgt.rsn.pcs.type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_pcs_80211_type,
{"Pairwise Cipher Suite type", "wlan_mgt.rsn.pcs.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_rsn_cipher_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_akms_count,
{"Auth Key Management (AKM) Suite Count", "wlan_mgt.rsn.akms.count",
FT_UINT16, BASE_DEC, NULL, 0,
"Indicates the number of Auth Key Management suite selectors that are contained in the Auth Key Management Suite List", HFILL }},
{&hf_ieee80211_rsn_akms_list,
{"Auth Key Management (AKM) List", "wlan_mgt.rsn.akms.list",
FT_NONE, BASE_NONE, NULL, 0,
"Contains a series of cipher suite selectors that indicate the AKM suites", HFILL }},
{&hf_ieee80211_rsn_akms,
{"Auth Key Management (AKM) Suite", "wlan_mgt.rsn.akms",
FT_UINT32, BASE_CUSTOM, CF_FUNC(rsn_akms_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_akms_oui,
{"Auth Key Management (AKM) OUI", "wlan_mgt.rsn.akms.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_akms_type,
{"Auth Key Management (AKM) type", "wlan_mgt.rsn.akms.type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_akms_80211_type,
{"Auth Key Management (AKM) type", "wlan_mgt.rsn.akms.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_rsn_keymgmt_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap,
{"RSN Capabilities", "wlan_mgt.rsn.capabilities",
FT_UINT16, BASE_HEX, NULL, 0,
"RSN Capability information", HFILL }},
{&hf_ieee80211_rsn_cap_preauth,
{"RSN Pre-Auth capabilities", "wlan_mgt.rsn.capabilities.preauth",
FT_BOOLEAN, 16, TFS(&rsn_preauth_flags), 0x0001,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_no_pairwise,
{"RSN No Pairwise capabilities", "wlan_mgt.rsn.capabilities.no_pairwise",
FT_BOOLEAN, 16, TFS(&rsn_no_pairwise_flags), 0x0002,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_ptksa_replay_counter,
{"RSN PTKSA Replay Counter capabilities", "wlan_mgt.rsn.capabilities.ptksa_replay_counter",
FT_UINT16, BASE_HEX, VALS(rsn_cap_replay_counter), 0x000C,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_gtksa_replay_counter,
{"RSN GTKSA Replay Counter capabilities", "wlan_mgt.rsn.capabilities.gtksa_replay_counter",
FT_UINT16, BASE_HEX, VALS(rsn_cap_replay_counter), 0x0030,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_mfpr,
{"Management Frame Protection Required", "wlan_mgt.rsn.capabilities.mfpr",
FT_BOOLEAN, 16, NULL, 0x0040,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_mfpc,
{"Management Frame Protection Capable", "wlan_mgt.rsn.capabilities.mfpc",
FT_BOOLEAN, 16, NULL, 0x0080,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_jmr,
{"Joint Multi-band RSNA", "wlan_mgt.rsn.capabilities.jmr",
FT_BOOLEAN, 16, NULL, 0x0100,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_peerkey,
{"PeerKey Enabled", "wlan_mgt.rsn.capabilities.peerkey",
FT_BOOLEAN, 16, NULL, 0x0200,
NULL, HFILL }},
{&hf_ieee80211_rsn_pmkid_count,
{"PMKID Count", "wlan_mgt.rsn.pmkid.count",
FT_UINT16, BASE_DEC, NULL, 0,
"Indicates the number of PMKID selectors that are contained in the PMKID Suite List", HFILL }},
{&hf_ieee80211_rsn_pmkid_list,
{"PMKID List", "wlan_mgt.rsn.pmkid.list",
FT_NONE, BASE_NONE, NULL, 0,
"Contains a series of cipher suite selectors that indicate the AKM suites", HFILL }},
{&hf_ieee80211_rsn_pmkid,
{"PMKID", "wlan_mgt.pmkid.akms",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_gmcs,
{"Group Management Cipher Suite", "wlan_mgt.rsn.gmcs",
FT_UINT32, BASE_CUSTOM, CF_FUNC(rsn_gmcs_base_custom), 0,
"Contains the cipher suite selector used by the BSS to protect broadcast/multicast traffic", HFILL }},
{&hf_ieee80211_rsn_gmcs_oui,
{"Group Management Cipher Suite OUI", "wlan_mgt.rsn.gmcs.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_gmcs_type,
{"Group Management Cipher Suite type", "wlan_mgt.rsn.gmcs.type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_gmcs_80211_type,
{"Group Management Cipher Suite type", "wlan_mgt.rsn.gmcs.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_rsn_cipher_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_ht_pren_type,
{"802.11n (Pre) Type", "wlan_mgt.vs.pren.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_ht_pren_type_vals), 0,
"Vendor Specific HT Type", HFILL }},
{&hf_ieee80211_ht_pren_unknown,
{"802.11n (Pre) Unknown Data", "wlan_mgt.vs.pren.unknown_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ht_cap,
{"HT Capabilities Info", "wlan_mgt.ht.capabilities",
FT_UINT16, BASE_HEX, NULL, 0,
"HT Capabilities information", HFILL }},
{&hf_ieee80211_ht_vs_cap,
{"HT Capabilities Info (VS)", "wlan_mgt.vs.ht.capabilities",
FT_UINT16, BASE_HEX, NULL, 0,
"Vendor Specific HT Capabilities information", HFILL }},
{&hf_ieee80211_ht_ldpc_coding,
{"HT LDPC coding capability", "wlan_mgt.ht.capabilities.ldpccoding",
FT_BOOLEAN, 16, TFS (&ht_ldpc_coding_flag), 0x0001,
NULL, HFILL }},
{&hf_ieee80211_ht_chan_width,
{"HT Support channel width", "wlan_mgt.ht.capabilities.width",
FT_BOOLEAN, 16, TFS (&ht_chan_width_flag), 0x0002,
NULL, HFILL }},
{&hf_ieee80211_ht_sm_pwsave,
{"HT SM Power Save", "wlan_mgt.ht.capabilities.sm",
FT_UINT16, BASE_HEX, VALS(ht_sm_pwsave_flag), 0x000c,
NULL, HFILL }},
{&hf_ieee80211_ht_green,
{"HT Green Field", "wlan_mgt.ht.capabilities.green",
FT_BOOLEAN, 16, TFS (&ht_green_flag), 0x0010,
NULL, HFILL }},
{&hf_ieee80211_ht_short20,
{"HT Short GI for 20MHz", "wlan_mgt.ht.capabilities.short20",
FT_BOOLEAN, 16, TFS (&tfs_supported_not_supported), 0x0020,
NULL, HFILL }},
{&hf_ieee80211_ht_short40,
{"HT Short GI for 40MHz", "wlan_mgt.ht.capabilities.short40",
FT_BOOLEAN, 16, TFS (&tfs_supported_not_supported), 0x0040,
NULL, HFILL }},
{&hf_ieee80211_ht_tx_stbc,
{"HT Tx STBC", "wlan_mgt.ht.capabilities.txstbc",
FT_BOOLEAN, 16, TFS (&tfs_supported_not_supported), 0x0080,
NULL, HFILL }},
{&hf_ieee80211_ht_rx_stbc,
{"HT Rx STBC", "wlan_mgt.ht.capabilities.rxstbc",
FT_UINT16, BASE_HEX, VALS(ht_rx_stbc_flag), 0x0300,
"HT Tx STBC", HFILL }},
{&hf_ieee80211_ht_delayed_block_ack,
{"HT Delayed Block ACK", "wlan_mgt.ht.capabilities.delayedblockack",
FT_BOOLEAN, 16, TFS (&ht_delayed_block_ack_flag), 0x0400,
NULL, HFILL }},
{&hf_ieee80211_ht_max_amsdu,
{"HT Max A-MSDU length", "wlan_mgt.ht.capabilities.amsdu",
FT_BOOLEAN, 16, TFS (&ht_max_amsdu_flag), 0x0800,
NULL, HFILL }},
{&hf_ieee80211_ht_dss_cck_40,
{"HT DSSS/CCK mode in 40MHz", "wlan_mgt.ht.capabilities.dsscck",
FT_BOOLEAN, 16, TFS (&ht_dss_cck_40_flag), 0x1000,
"HT DSS/CCK mode in 40MHz", HFILL }},
{&hf_ieee80211_ht_psmp,
{"HT PSMP Support", "wlan_mgt.ht.capabilities.psmp",
FT_BOOLEAN, 16, TFS (&ht_psmp_flag), 0x2000,
NULL, HFILL }},
{&hf_ieee80211_ht_40_mhz_intolerant,
{"HT Forty MHz Intolerant", "wlan_mgt.ht.capabilities.40mhzintolerant",
FT_BOOLEAN, 16, TFS (&ht_40_mhz_intolerant_flag), 0x4000,
NULL, HFILL }},
{&hf_ieee80211_ht_l_sig,
{"HT L-SIG TXOP Protection support", "wlan_mgt.ht.capabilities.lsig",
FT_BOOLEAN, 16, TFS (&tfs_supported_not_supported), 0x8000,
NULL, HFILL }},
{&hf_ieee80211_ext_bss_mu_mimo_capable_sta_count,
{"MU-MIMO Capable STA Count", "wlan_mgt.ext_bss.mu_mimo_capable_sta_count",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ext_bss_ss_underutilization,
{"Spatial Stream Underutilization", "wlan_mgt.ext_bss.ss_underutilization",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ext_bss_observable_sec_20mhz_utilization,
{"Observable Secondary 20MHz Utilization", "wlan_mgt.ext_bss.observable_sec_20mhz_utilization",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ext_bss_observable_sec_40mhz_utilization,
{"Observable Secondary 40MHz Utilization", "wlan_mgt.ext_bss.observable_sec_40mhz_utilization",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ext_bss_observable_sec_80mhz_utilization,
{"Observable Secondary 80MHz Utilization", "wlan_mgt.ext_bss.observable_sec_80mhz_utilization",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wide_bw_new_channel_width,
{"New Channel Width", "wlan_mgt.wide_bw.new_channel_width",
FT_UINT8, BASE_HEX, VALS(vht_operation_info_channel_width), 0x0,
NULL, HFILL }},
{&hf_ieee80211_wide_bw_new_channel_center_freq_segment0,
{"New Channel Center Frequency Segment 0", "wlan_mgt.wide_bw.new_channel_center_freq_segment0",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_wide_bw_new_channel_center_freq_segment1,
{"New Channel Center Frequency Segment 1", "wlan_mgt.wide_bw.new_channel_center_freq_segment1",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_operat_notification_mode,
{"Operating Mode Notification", "wlan_mgt.operat_notification_mode",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_operat_mode_field_channel_width,
{"Channel Width", "wlan_mgt.operat_mode_field.channelwidth",
FT_UINT8, BASE_HEX, VALS (&operating_mode_field_channel_width), 0x03,
NULL, HFILL }},
{&hf_ieee80211_operat_mode_field_reserved,
{"Reserved", "wlan_mgt.operat_mode_field.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0C,
NULL, HFILL }},
{&hf_ieee80211_operat_mode_field_rxnss,
{"Rx NSS", "wlan_mgt.operat_mode_field.rxnss",
FT_UINT8, BASE_HEX, VALS (&operat_mode_field_rxnss), 0x70,
NULL, HFILL }},
{&hf_ieee80211_operat_mode_field_rxnsstype,
{"Rx NSS Type", "wlan_mgt.operat_mode_field.rxnsstype",
FT_UINT8, BASE_HEX, NULL, 0x80,
"Indicate that the Rx NSS subfield carries the maximum number of spatial streams that the STA can receive", HFILL }},
{&hf_ieee80211_ampduparam,
{"A-MPDU Parameters", "wlan_mgt.ht.ampduparam",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ampduparam_vs,
{"A-MPDU Parameters (VS)", "wlan_mgt.vs.ht.ampduparam",
FT_UINT8, BASE_HEX, NULL, 0,
"Vendor Specific A-MPDU Parameters", HFILL }},
{&hf_ieee80211_ampduparam_mpdu,
{"Maximum Rx A-MPDU Length", "wlan_mgt.ht.ampduparam.maxlength",
FT_UINT8, BASE_HEX, 0, 0x03,
NULL, HFILL }},
{&hf_ieee80211_ampduparam_mpdu_start_spacing,
{"MPDU Density", "wlan_mgt.ht.ampduparam.mpdudensity",
FT_UINT8, BASE_HEX, VALS(ampduparam_mpdu_start_spacing_flags), 0x1c,
NULL, HFILL }},
{&hf_ieee80211_ampduparam_reserved,
{"Reserved", "wlan_mgt.ht.ampduparam.reserved",
FT_UINT8, BASE_HEX, NULL, 0xE0,
NULL, HFILL }},
{&hf_ieee80211_mcsset,
{"Rx Supported Modulation and Coding Scheme Set", "wlan_mgt.ht.mcsset",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_mcsset_vs,
{"Rx Supported Modulation and Coding Scheme Set (VS)", "wlan_mgt.vs.ht.mcsset",
FT_STRING, BASE_NONE, NULL, 0,
"Vendor Specific Rx Supported Modulation and Coding Scheme Set", HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask,
{"Rx Modulation and Coding Scheme (One bit per modulation)", "wlan_mgt.ht.mcsset.rxbitmask",
FT_NONE, BASE_NONE, NULL, 0,
"One bit per modulation", HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_0to7,
{"Rx Bitmask Bits 0-7", "wlan_mgt.ht.mcsset.rxbitmask.0to7",
FT_UINT32, BASE_HEX, 0, 0x000000ff,
NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_8to15,
{"Rx Bitmask Bits 8-15", "wlan_mgt.ht.mcsset.rxbitmask.8to15",
FT_UINT32, BASE_HEX, 0, 0x0000ff00,
NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_16to23,
{"Rx Bitmask Bits 16-23", "wlan_mgt.ht.mcsset.rxbitmask.16to23",
FT_UINT32, BASE_HEX, 0, 0x00ff0000,
NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_24to31,
{"Rx Bitmask Bits 24-31", "wlan_mgt.ht.mcsset.rxbitmask.24to31",
FT_UINT32, BASE_HEX, 0, 0xff000000,
NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_32,
{"Rx Bitmask Bit 32", "wlan_mgt.ht.mcsset.rxbitmask.32",
FT_UINT32, BASE_HEX, 0, 0x000001,
NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_33to38,
{"Rx Bitmask Bits 33-38", "wlan_mgt.ht.mcsset.rxbitmask.33to38",
FT_UINT32, BASE_HEX, 0, 0x00007e,
NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_39to52,
{"Rx Bitmask Bits 39-52", "wlan_mgt.ht.mcsset.rxbitmask.39to52",
FT_UINT32, BASE_HEX, 0, 0x1fff80,
NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_53to76,
{"Rx Bitmask Bits 53-76", "wlan_mgt.ht.mcsset.rxbitmask.53to76",
FT_UINT32, BASE_HEX, 0, 0x1fffffe0,
NULL, HFILL }},
{&hf_ieee80211_mcsset_highest_data_rate,
{"Highest Supported Data Rate", "wlan_mgt.ht.mcsset.highestdatarate",
FT_UINT16, BASE_HEX, 0, 0x03ff,
NULL, HFILL }},
{&hf_ieee80211_mcsset_tx_mcs_set_defined,
{"Tx Supported MCS Set", "wlan_mgt.ht.mcsset.txsetdefined",
FT_BOOLEAN, 16, TFS (&tfs_defined_not_defined), 0x0001,
NULL, HFILL }},
{&hf_ieee80211_mcsset_tx_rx_mcs_set_not_equal,
{"Tx and Rx MCS Set", "wlan_mgt.ht.mcsset.txrxmcsnotequal",
FT_BOOLEAN, 16, TFS (&mcsset_tx_rx_mcs_set_not_equal_flag), 0x0002,
NULL, HFILL }},
{&hf_ieee80211_mcsset_tx_max_spatial_streams,
{"Maximum Number of Tx Spatial Streams Supported", "wlan_mgt.ht.mcsset.txmaxss",
FT_UINT16, BASE_HEX, 0 , 0x000c,
NULL, HFILL }},
{&hf_ieee80211_mcsset_tx_unequal_modulation,
{"Unequal Modulation", "wlan_mgt.ht.mcsset.txunequalmod",
FT_BOOLEAN, 16, TFS (&tfs_supported_not_supported), 0x0010,
NULL, HFILL }},
{&hf_ieee80211_htex_cap,
{"HT Extended Capabilities", "wlan_mgt.htex.capabilities",
FT_UINT16, BASE_HEX, NULL, 0,
"HT Extended Capability information", HFILL }},
{&hf_ieee80211_htex_vs_cap,
{"HT Extended Capabilities (VS)", "wlan_mgt.vs.htex.capabilities",
FT_UINT16, BASE_HEX, NULL, 0,
"Vendor Specific HT Extended Capability information", HFILL }},
{&hf_ieee80211_htex_pco,
{"Transmitter supports PCO", "wlan_mgt.htex.capabilities.pco",
FT_BOOLEAN, 16, TFS (&tfs_supported_not_supported), 0x0001,
NULL, HFILL }},
{&hf_ieee80211_htex_transtime,
{"Time needed to transition between 20MHz and 40MHz", "wlan_mgt.htex.capabilities.transtime",
FT_UINT16, BASE_HEX, VALS(htex_transtime_flags), 0x0006,
NULL, HFILL }},
{&hf_ieee80211_htex_mcs,
{"MCS Feedback capability", "wlan_mgt.htex.capabilities.mcs",
FT_UINT16, BASE_HEX, VALS(htex_mcs_flags), 0x0300,
NULL, HFILL }},
{&hf_ieee80211_htex_htc_support,
{"High Throughput", "wlan_mgt.htex.capabilities.htc",
FT_BOOLEAN, 16, TFS (&tfs_supported_not_supported), 0x0400,
NULL, HFILL }},
{&hf_ieee80211_htex_rd_responder,
{"Reverse Direction Responder", "wlan_mgt.htex.capabilities.rdresponder",
FT_BOOLEAN, 16, TFS (&tfs_supported_not_supported), 0x0800,
NULL, HFILL }},
{&hf_ieee80211_txbf,
{"Transmit Beam Forming (TxBF) Capabilities", "wlan_mgt.txbf",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_txbf_vs,
{"Transmit Beam Forming (TxBF) Capabilities (VS)", "wlan_mgt.vs.txbf",
FT_UINT32, BASE_HEX, NULL, 0,
"Vendor Specific Transmit Beam Forming (TxBF) Capabilities", HFILL }},
{&hf_ieee80211_txbf_cap,
{"Transmit Beamforming", "wlan_mgt.txbf.txbf",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }},
{&hf_ieee80211_txbf_rcv_ssc,
{"Receive Staggered Sounding", "wlan_mgt.txbf.rxss",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }},
{&hf_ieee80211_txbf_tx_ssc,
{"Transmit Staggered Sounding", "wlan_mgt.txbf.txss",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000004,
NULL, HFILL }},
{&hf_ieee80211_txbf_rcv_ndp,
{"Receive Null Data packet (NDP)", "wlan_mgt.txbf.rxndp",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000008,
NULL, HFILL }},
{&hf_ieee80211_txbf_tx_ndp,
{"Transmit Null Data packet (NDP)", "wlan_mgt.txbf.txndp",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000010,
NULL, HFILL }},
{&hf_ieee80211_txbf_impl_txbf,
{"Implicit TxBF capable", "wlan_mgt.txbf.impltxbf",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000020,
"Implicit Transmit Beamforming (TxBF) capable", HFILL }},
{&hf_ieee80211_txbf_calib,
{"Calibration", "wlan_mgt.txbf.calibration",
FT_UINT32, BASE_HEX, VALS(txbf_calib_flag), 0x000000c0,
NULL, HFILL }},
{&hf_ieee80211_txbf_expl_csi,
{"STA can apply TxBF using CSI explicit feedback", "wlan_mgt.txbf.csi",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000100,
"Station can apply TxBF using CSI explicit feedback", HFILL }},
{&hf_ieee80211_txbf_expl_uncomp_fm,
{"STA can apply TxBF using uncompressed beamforming feedback matrix", "wlan_mgt.txbf.fm.uncompressed.tbf",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000200,
"Station can apply TxBF using uncompressed beamforming feedback matrix", HFILL }},
{&hf_ieee80211_txbf_expl_comp_fm,
{"STA can apply TxBF using compressed beamforming feedback matrix", "wlan_mgt.txbf.fm.compressed.tbf",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000400,
"Station can apply TxBF using compressed beamforming feedback matrix", HFILL }},
{&hf_ieee80211_txbf_expl_bf_csi,
{"Receiver can return explicit CSI feedback", "wlan_mgt.txbf.rcsi",
FT_UINT32, BASE_HEX, VALS(txbf_feedback_flags), 0x00001800,
NULL, HFILL }},
{&hf_ieee80211_txbf_expl_uncomp_fm_feed,
{"Receiver can return explicit uncompressed Beamforming Feedback Matrix", "wlan_mgt.txbf.fm.uncompressed.rbf",
FT_UINT32, BASE_HEX, VALS(txbf_feedback_flags), 0x00006000,
NULL, HFILL }},
{&hf_ieee80211_txbf_expl_comp_fm_feed,
{"STA can compress and use compressed Beamforming Feedback Matrix", "wlan_mgt.txbf.fm.compressed.bf",
FT_UINT32, BASE_HEX, VALS(txbf_feedback_flags), 0x00018000,
"Station can compress and use compressed Beamforming Feedback Matrix", HFILL }},
{&hf_ieee80211_txbf_min_group,
{"Minimal grouping used for explicit feedback reports", "wlan_mgt.txbf.mingroup",
FT_UINT32, BASE_HEX, VALS(txbf_min_group_flags), 0x00060000,
NULL, HFILL }},
{&hf_ieee80211_vht_cap,
{"VHT Capabilities Info", "wlan_mgt.vht.capabilities",
FT_UINT32, BASE_HEX, NULL, 0,
"VHT Capabilities information", HFILL }},
{&hf_ieee80211_vht_max_mpdu_length,
{"Maximum MPDU Length", "wlan_mgt.vht.capabilities.maxmpdulength",
FT_UINT32, BASE_HEX, VALS(vht_max_mpdu_length_flag), 0x00000003,
"In Octets unit", HFILL }},
{&hf_ieee80211_vht_supported_chan_width_set,
{"Supported Channel Width Set", "wlan_mgt.vht.capabilities.supportedchanwidthset",
FT_UINT32, BASE_HEX, VALS(vht_supported_chan_width_set_flag), 0x0000000c,
NULL, HFILL }},
{&hf_ieee80211_vht_rx_ldpc,
{"Rx LDPC", "wlan_mgt.vht.capabilities.rxldpc",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000010,
NULL, HFILL }},
{&hf_ieee80211_vht_short_gi_for_80,
{"Short GI for 80MHz", "wlan_mgt.vht.capabilities.short80",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000020,
NULL, HFILL }},
{&hf_ieee80211_vht_short_gi_for_160,
{"Short GI for 160MHz and 80+80MHz", "wlan_mgt.vht.capabilities.short160",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000040,
NULL, HFILL }},
{&hf_ieee80211_vht_tx_stbc,
{"Tx STBC", "wlan_mgt.vht.capabilities.txstbc",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000080,
NULL, HFILL }},
{&hf_ieee80211_vht_rx_stbc,
{"Rx STBC", "wlan_mgt.vht.capabilities.rxstbc",
FT_UINT32, BASE_HEX, VALS(vht_rx_stbc_flag), 0x00000700,
NULL, HFILL }},
{&hf_ieee80211_vht_su_beamformer_cap,
{"SU Beam-former Capable", "wlan_mgt.vht.capabilities.subeamformer",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00000800,
NULL, HFILL }},
{&hf_ieee80211_vht_su_beamformee_cap,
{"SU Beam-formee Capable", "wlan_mgt.vht.capabilities.subeamformee",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00001000,
NULL, HFILL }},
{&hf_ieee80211_vht_beamformer_antennas,
{"Compressed Steering Number of Beamformer Antennas Supported", "wlan_mgt.vht.capabilities.beamformerants",
FT_UINT32, BASE_HEX, VALS(num_plus_one_3bit_flag), 0x0000e000,
NULL, HFILL }},
{&hf_ieee80211_vht_sounding_dimensions,
{"Number of Sounding Dimensions", "wlan_mgt.vht.capabilities.soundingdimensions",
FT_UINT32, BASE_HEX, VALS(num_plus_one_3bit_flag), 0x00070000,
NULL, HFILL }},
{&hf_ieee80211_vht_mu_beamformer_cap,
{"MU Beam-former Capable", "wlan_mgt.vht.capabilities.mubeamformer",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00080000,
NULL, HFILL }},
{&hf_ieee80211_vht_mu_beamformee_cap,
{"MU Beam-formee Capable", "wlan_mgt.vht.capabilities.mubeamformee",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00100000,
NULL, HFILL }},
{&hf_ieee80211_vht_txop_ps,
{"VHT TXOP PS", "wlan_mgt.vht.capabilities.vhttxopps",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00200000,
NULL, HFILL }},
{&hf_ieee80211_vht_var_htc_field,
{"+HTC-VHT Capable (VHT variant HT Control field)", "wlan_mgt.vht.capabilities.vhthtc",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x00400000,
NULL, HFILL }},
{&hf_ieee80211_vht_max_ampdu,
{"Max A-MPDU Length", "wlan_mgt.vht.capabilities.maxampdu",
FT_UINT32, BASE_HEX, VALS(vht_max_ampdu_flag), 0x03800000,
"In Octets unit", HFILL }},
{&hf_ieee80211_vht_link_adaptation_cap,
{"VHT Link Adaptation", "wlan_mgt.vht.capabilities.linkadapt",
FT_UINT32, BASE_HEX, VALS(vht_link_adapt_flag), 0x0c000000,
NULL, HFILL }},
{&hf_ieee80211_vht_rx_pattern,
{"Rx Antenna Pattern Consistency", "wlan_mgt.vht.capabilities.rxpatconsist",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x10000000,
NULL, HFILL }},
{&hf_ieee80211_vht_tx_pattern,
{"Tx Antenna Pattern Consistency", "wlan_mgt.vht.capabilities.txpatconsist",
FT_BOOLEAN, 32, TFS (&tfs_supported_not_supported), 0x20000000,
NULL, HFILL }},
{&hf_ieee80211_vht_reserv,
{"Reserved", "wlan_mgt.vht.reserved",
FT_BOOLEAN, 32, NULL, 0xc0000000,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset,
{"VHT Supported MCS Set", "wlan_mgt.vht.mcsset",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_rx_mcs_map,
{"Rx MCS Map", "wlan_mgt.vht.mcsset.rxmcsmap",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_rx_max_mcs_for_1_ss,
{"Rx 1 SS", "wlan_mgt.vht.mcsset.rxmcsmap.ss1",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0003,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_rx_max_mcs_for_2_ss,
{"Rx 2 SS", "wlan_mgt.vht.mcsset.rxmcsmap.ss2",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x000c,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_rx_max_mcs_for_3_ss,
{"Rx 3 SS", "wlan_mgt.vht.mcsset.rxmcsmap.ss3",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0030,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_rx_max_mcs_for_4_ss,
{"Rx 4 SS", "wlan_mgt.vht.mcsset.rxmcsmap.ss4",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x00c0,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_rx_max_mcs_for_5_ss,
{"Rx 5 SS", "wlan_mgt.vht.mcsset.rxmcsmap.ss5",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0300,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_rx_max_mcs_for_6_ss,
{"Rx 6 SS", "wlan_mgt.vht.mcsset.rxmcsmap.ss6",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0c00,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_rx_max_mcs_for_7_ss,
{"Rx 7 SS", "wlan_mgt.vht.mcsset.rxmcsmap.ss7",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x3000,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_rx_max_mcs_for_8_ss,
{"Rx 8 SS", "wlan_mgt.vht.mcsset.rxmcsmap.ss8",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0xc000,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_rx_highest_long_gi,
{"Rx Highest Long GI Data Rate (in Mb/s, 0 = subfield not in use)", "wlan_mgt.vht.mcsset.rxhighestlonggirate",
FT_UINT16, BASE_HEX, NULL, 0x1fff,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_tx_mcs_map,
{"Tx MCS Map", "wlan_mgt.vht.mcsset.txmcsmap",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_tx_max_mcs_for_1_ss,
{"Tx 1 SS", "wlan_mgt.vht.mcsset.txmcsmap.ss1",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0003,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_tx_max_mcs_for_2_ss,
{"Tx 2 SS", "wlan_mgt.vht.mcsset.txmcsmap.ss2",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x000c,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_tx_max_mcs_for_3_ss,
{"Tx 3 SS", "wlan_mgt.vht.mcsset.txmcsmap.ss3",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0030,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_tx_max_mcs_for_4_ss,
{"Tx 4 SS", "wlan_mgt.vht.mcsset.txmcsmap.ss4",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x00c0,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_tx_max_mcs_for_5_ss,
{"Tx 5 SS", "wlan_mgt.vht.mcsset.txmcsmap.ss5",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0300,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_tx_max_mcs_for_6_ss,
{"Tx 6 SS", "wlan_mgt.vht.mcsset.txmcsmap.ss6",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0c00,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_tx_max_mcs_for_7_ss,
{"Tx 7 SS", "wlan_mgt.vht.mcsset.txmcsmap.ss7",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x3000,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_tx_max_mcs_for_8_ss,
{"Tx 8 SS", "wlan_mgt.vht.mcsset.txmcsmap.ss8",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0xc000,
NULL, HFILL }},
{&hf_ieee80211_vht_mcsset_tx_highest_long_gi,
{"Tx Highest Long GI Data Rate (in Mb/s, 0 = subfield not in use)", "wlan_mgt.vht.mcsset.txhighestlonggirate",
FT_UINT16, BASE_HEX, NULL, 0x1fff,
NULL, HFILL }},
{&hf_ieee80211_vht_op,
{"VHT Operation Info", "wlan_mgt.vht.op",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_op_channel_width,
{"Channel Width", "wlan_mgt.vht.op.channelwidth",
FT_UINT8, BASE_HEX, VALS(vht_op_channel_width_flag), 0,
NULL, HFILL }},
{&hf_ieee80211_vht_op_channel_center0,
{"Channel Center Segment 0", "wlan_mgt.vht.op.channelcenter0",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_op_channel_center1,
{"Channel Center Segment 1", "wlan_mgt.vht.op.channelcenter1",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_op_basic_mcs_map,
{"Basic MCS Map", "wlan_mgt.vht.op.basicmcsmap",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_op_max_basic_mcs_for_1_ss,
{"Basic 1 SS", "wlan_mgt.vht.op.basicmcsmap.ss1",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0003,
NULL, HFILL }},
{&hf_ieee80211_vht_op_max_basic_mcs_for_2_ss,
{"Basic 2 SS", "wlan_mgt.vht.op.basicmcsmap.ss2",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x000c,
NULL, HFILL }},
{&hf_ieee80211_vht_op_max_basic_mcs_for_3_ss,
{"Basic 3 SS", "wlan_mgt.vht.op.basicmcsmap.ss3",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0030,
NULL, HFILL }},
{&hf_ieee80211_vht_op_max_basic_mcs_for_4_ss,
{"Basic 4 SS", "wlan_mgt.vht.op.basicmcsmap.ss4",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x00c0,
NULL, HFILL }},
{&hf_ieee80211_vht_op_max_basic_mcs_for_5_ss,
{"Basic 5 SS", "wlan_mgt.vht.op.basicmcsmap.ss5",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0300,
NULL, HFILL }},
{&hf_ieee80211_vht_op_max_basic_mcs_for_6_ss,
{"Basic 6 SS", "wlan_mgt.vht.op.basicmcsmap.ss6",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x0c00,
NULL, HFILL }},
{&hf_ieee80211_vht_op_max_basic_mcs_for_7_ss,
{"Basic 7 SS", "wlan_mgt.vht.op.basicmcsmap.ss7",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0x3000,
NULL, HFILL }},
{&hf_ieee80211_vht_op_max_basic_mcs_for_8_ss,
{"Basic 8 SS", "wlan_mgt.vht.op.basicmcsmap.ss8",
FT_UINT16, BASE_HEX, VALS(vht_supported_mcs_flag), 0xc000,
NULL, HFILL }},
{&hf_ieee80211_vht_tpe_pwr_info,
{"Tx Pwr Info", "wlan_mgt.vht.tpe.pwr_info",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vht_tpe_pwr_info_count,
{"Max Tx Pwr Count", "wlan_mgt.vht.tpe.pwr_info.count",
FT_UINT8, BASE_DEC, NULL , 0x07,
NULL, HFILL }},
{&hf_ieee80211_vht_tpe_pwr_info_unit,
{"Max Tx Pwr Unit Interpretation", "wlan_mgt.vht.tpe.pwr_info.unit",
FT_UINT8, BASE_DEC, VALS(vht_tpe_pwr_units) , 0x38,
NULL, HFILL }},
{&hf_ieee80211_vht_tpe_pwr_info_reserved,
{"Reserved", "wlan_mgt.vht.tpe.pwr_info.reserved",
FT_UINT8, BASE_DEC, NULL , 0xC0,
NULL, HFILL }},
{&hf_ieee80211_vht_tpe_pwr_constr_20,
{"Local Max Tx Pwr Constraint 20MHz", "wlan_mgt.vht.tpe.pwr_constr_20",
FT_INT8, BASE_CUSTOM, CF_FUNC(vht_tpe_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_vht_tpe_pwr_constr_40,
{"Local Max Tx Pwr Constraint 40MHz", "wlan_mgt.vht.tpe.pwr_constr_40",
FT_INT8, BASE_CUSTOM, CF_FUNC(vht_tpe_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_vht_tpe_pwr_constr_80,
{"Local Max Tx Pwr Constraint 80MHz", "wlan_mgt.vht.tpe.pwr_constr_80",
FT_INT8, BASE_CUSTOM, CF_FUNC(vht_tpe_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_vht_tpe_pwr_constr_160,
{"Local Max Tx Pwr Constraint 160MHz/80+80 MHz", "wlan_mgt.vht.tpe.pwr_constr_160",
FT_INT8, BASE_CUSTOM, CF_FUNC(vht_tpe_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_txbf_csi_num_bf_ant,
{"Max antennae STA can support when CSI feedback required", "wlan_mgt.txbf.csinumant",
FT_UINT32, BASE_HEX, VALS(txbf_antenna_flags), 0x00180000,
"Max antennae station can support when CSI feedback required", HFILL }},
{&hf_ieee80211_txbf_uncomp_sm_bf_ant,
{"Max antennae STA can support when uncompressed Beamforming feedback required", "wlan_mgt.txbf.fm.uncompressed.maxant",
FT_UINT32, BASE_HEX, VALS(txbf_antenna_flags), 0x00600000,
"Max antennae station can support when uncompressed Beamforming feedback required", HFILL }},
{&hf_ieee80211_txbf_comp_sm_bf_ant,
{"Max antennae STA can support when compressed Beamforming feedback required", "wlan_mgt.txbf.fm.compressed.maxant",
FT_UINT32, BASE_HEX, VALS(txbf_antenna_flags), 0x01800000,
"Max antennae station can support when compressed Beamforming feedback required", HFILL }},
{&hf_ieee80211_txbf_csi_max_rows_bf,
{"Maximum number of rows of CSI explicit feedback", "wlan_mgt.txbf.csi.maxrows",
FT_UINT32, BASE_HEX, VALS(txbf_csi_max_rows_bf_flags), 0x06000000,
NULL, HFILL }},
{&hf_ieee80211_txbf_chan_est,
{"Maximum number of space time streams for which channel dimensions can be simultaneously estimated", "wlan_mgt.txbf.channelest",
FT_UINT32, BASE_HEX, VALS(txbf_chan_est_flags), 0x18000000,
NULL, HFILL }},
{&hf_ieee80211_txbf_resrv,
{"Reserved", "wlan_mgt.txbf.reserved",
FT_UINT32, BASE_HEX, NULL, 0xe0000000,
NULL, HFILL }},
{&hf_ieee80211_hta_cc,
{"HT Control Channel", "wlan_mgt.hta.control_channel",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_hta_cap,
{"HT Additional Capabilities", "wlan_mgt.hta.capabilities",
FT_UINT16, BASE_HEX, NULL, 0,
"HT Additional Capability information", HFILL }},
{&hf_ieee80211_hta_ext_chan_offset,
{"Extension Channel Offset", "wlan_mgt.hta.capabilities.ext_chan_offset",
FT_UINT16, BASE_HEX, VALS(hta_ext_chan_offset_flag), 0x0003,
NULL, HFILL }},
{&hf_ieee80211_hta_rec_tx_width,
{"Recommended Tx Channel Width", "wlan_mgt.hta.capabilities.rec_tx_width",
FT_BOOLEAN, 16, TFS (&hta_rec_tx_width_flag), 0x0004,
"Recommended Transmit Channel Width", HFILL }},
{&hf_ieee80211_hta_rifs_mode,
{"Reduced Interframe Spacing (RIFS) Mode", "wlan_mgt.hta.capabilities.rifs_mode",
FT_BOOLEAN, 16, TFS (&hta_rifs_mode_flag), 0x0008,
NULL, HFILL }},
{&hf_ieee80211_hta_controlled_access,
{"Controlled Access Only", "wlan_mgt.hta.capabilities.controlled_access",
FT_BOOLEAN, 16, TFS (&hta_controlled_access_flag), 0x0010,
NULL, HFILL }},
{&hf_ieee80211_hta_service_interval,
{"Service Interval Granularity", "wlan_mgt.hta.capabilities.service_interval",
FT_UINT16, BASE_HEX, VALS(hta_service_interval_flag), 0x00E0,
NULL, HFILL }},
{&hf_ieee80211_hta_operating_mode,
{"Operating Mode", "wlan_mgt.hta.capabilities.operating_mode",
FT_UINT16, BASE_HEX, VALS(hta_operating_mode_flag), 0x0003,
NULL, HFILL }},
{&hf_ieee80211_hta_non_gf_devices,
{"Non Greenfield (GF) devices Present", "wlan_mgt.hta.capabilities.non_gf_devices",
FT_BOOLEAN, 16, TFS (&hta_non_gf_devices_flag), 0x0004,
"on Greenfield (GF) devices Present", HFILL }},
{&hf_ieee80211_hta_basic_stbc_mcs,
{"Basic STB Modulation and Coding Scheme (MCS)", "wlan_mgt.hta.capabilities.basic_stbc_mcs",
FT_UINT16, BASE_HEX, NULL , 0x007f,
NULL, HFILL }},
{&hf_ieee80211_hta_dual_stbc_protection,
{"Dual Clear To Send (CTS) Protection", "wlan_mgt.hta.capabilities.dual_stbc_protection",
FT_BOOLEAN, 16, TFS (&hta_dual_stbc_protection_flag), 0x0080,
NULL, HFILL }},
{&hf_ieee80211_hta_secondary_beacon,
{"Secondary Beacon", "wlan_mgt.hta.capabilities.secondary_beacon",
FT_BOOLEAN, 16, TFS (&hta_secondary_beacon_flag), 0x0100,
NULL, HFILL }},
{&hf_ieee80211_hta_lsig_txop_protection,
{"L-SIG TXOP Protection Support", "wlan_mgt.hta.capabilities.lsig_txop_protection",
FT_BOOLEAN, 16, TFS (&hta_lsig_txop_protection_flag), 0x0200,
NULL, HFILL }},
{&hf_ieee80211_hta_pco_active,
{"Phased Coexistence Operation (PCO) Active", "wlan_mgt.hta.capabilities.pco_active",
FT_BOOLEAN, 16, TFS (&hta_pco_active_flag), 0x0400,
NULL, HFILL }},
{&hf_ieee80211_hta_pco_phase,
{"Phased Coexistence Operation (PCO) Phase", "wlan_mgt.hta.capabilities.pco_phase",
FT_BOOLEAN, 16, TFS (&hta_pco_phase_flag), 0x0800,
NULL, HFILL }},
{&hf_ieee80211_antsel,
{"Antenna Selection (ASEL) Capabilities", "wlan_mgt.asel",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_antsel_vs,
{"Antenna Selection (ASEL) Capabilities (VS)", "wlan_mgt.vs.asel",
FT_UINT8, BASE_HEX, NULL, 0,
"Vendor Specific Antenna Selection (ASEL) Capabilities", HFILL }},
{&hf_ieee80211_antsel_b0,
{"Antenna Selection Capable", "wlan_mgt.asel.capable",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x01,
NULL, HFILL }},
{&hf_ieee80211_antsel_b1,
{"Explicit CSI Feedback Based Tx ASEL", "wlan_mgt.asel.txcsi",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x02,
NULL, HFILL }},
{&hf_ieee80211_antsel_b2,
{"Antenna Indices Feedback Based Tx ASEL", "wlan_mgt.asel.txif",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x04,
NULL, HFILL }},
{&hf_ieee80211_antsel_b3,
{"Explicit CSI Feedback", "wlan_mgt.asel.csi",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x08,
NULL, HFILL }},
{&hf_ieee80211_antsel_b4,
{"Antenna Indices Feedback", "wlan_mgt.asel.if",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x10,
NULL, HFILL }},
{&hf_ieee80211_antsel_b5,
{"Rx ASEL", "wlan_mgt.asel.rx",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x20,
NULL, HFILL }},
{&hf_ieee80211_antsel_b6,
{"Tx Sounding PPDUs", "wlan_mgt.asel.sppdu",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_antsel_b7,
{"Reserved", "wlan_mgt.asel.reserved",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }},
{&hf_ieee80211_ht_info_delimiter1,
{"HT Information Subset (1 of 3)", "wlan_mgt.ht.info.delim1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ht_info_primary_channel,
{"Primary Channel", "wlan_mgt.ht.info.primarychannel",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ht_info_secondary_channel_offset,
{"Secondary channel offset", "wlan_mgt.ht.info.secchanoffset",
FT_UINT8, BASE_HEX, VALS(ht_info_secondary_channel_offset_flags), 0x03,
NULL, HFILL }},
{&hf_ieee80211_ht_info_channel_width,
{"Supported channel width", "wlan_mgt.ht.info.chanwidth",
FT_BOOLEAN, 8, TFS (&ht_info_channel_width_flag), 0x04,
NULL, HFILL }},
{&hf_ieee80211_ht_info_rifs_mode,
{"Reduced Interframe Spacing (RIFS)", "wlan_mgt.ht.info.rifs",
FT_BOOLEAN, 8, TFS (&ht_info_rifs_mode_flag), 0x08,
NULL, HFILL }},
{&hf_ieee80211_ht_info_psmp_stas_only,
{"Power Save Multi-Poll (PSMP) stations only", "wlan_mgt.ht.info.psmponly",
FT_BOOLEAN, 8, TFS (&ht_info_psmp_stas_only_flag), 0x10,
NULL, HFILL }},
{&hf_ieee80211_ht_info_service_interval_granularity,
{"Shortest service interval", "wlan_mgt.ht.info",
FT_UINT8, BASE_HEX, VALS(ht_info_service_interval_granularity_flags), 0xe0,
NULL, HFILL }},
{&hf_ieee80211_ht_info_delimiter2,
{"HT Information Subset (2 of 3)", "wlan_mgt.ht.info.delim2",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ht_info_operating_mode,
{"Operating mode of BSS", "wlan_mgt.ht.info.operatingmode",
FT_UINT16, BASE_HEX, VALS(ht_info_operating_mode_flags), 0x0003,
NULL, HFILL }},
{&hf_ieee80211_ht_info_non_greenfield_sta_present,
{"Non-greenfield STAs present", "wlan_mgt.ht.info.greenfield",
FT_BOOLEAN, 16, TFS (&ht_info_non_greenfield_sta_present_flag), 0x0004,
NULL, HFILL }},
{&hf_ieee80211_ht_info_transmit_burst_limit,
{"Transmit burst limit", "wlan_mgt.ht.info.burstlim",
FT_BOOLEAN, 16, TFS (&ht_info_transmit_burst_limit_flag), 0x0008,
NULL, HFILL }},
{&hf_ieee80211_ht_info_obss_non_ht_stas_present,
{"OBSS non-HT STAs present", "wlan_mgt.ht.info.obssnonht",
FT_BOOLEAN, 16, TFS (&ht_info_obss_non_ht_stas_present_flag), 0x0010,
NULL, HFILL }},
{&hf_ieee80211_ht_info_reserved_1,
{"Reserved", "wlan_mgt.ht.info.reserved1",
FT_UINT16, BASE_HEX, NULL, 0xffe0,
NULL, HFILL }},
{&hf_ieee80211_ht_info_delimiter3,
{"HT Information Subset (3 of 3)", "wlan_mgt.ht.info.delim3",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ht_info_reserved_2,
{"Reserved", "wlan_mgt.ht.info.reserved2",
FT_UINT16, BASE_HEX, NULL, 0x003f,
NULL, HFILL }},
{&hf_ieee80211_ht_info_dual_beacon,
{"Dual beacon", "wlan_mgt.ht.info.dualbeacon",
FT_BOOLEAN, 16, TFS (&ht_info_dual_beacon_flag), 0x0040,
NULL, HFILL }},
{&hf_ieee80211_ht_info_dual_cts_protection,
{"Dual Clear To Send (CTS) protection", "wlan_mgt.ht.info.dualcts",
FT_BOOLEAN, 16, TFS (&ht_info_dual_cts_protection_flag), 0x0080,
NULL, HFILL }},
{&hf_ieee80211_ht_info_secondary_beacon,
{"Beacon ID", "wlan_mgt.ht.info.secondarybeacon",
FT_BOOLEAN, 16, TFS (&ht_info_secondary_beacon_flag), 0x0100,
NULL, HFILL }},
{&hf_ieee80211_ht_info_lsig_txop_protection_full_support,
{"L-SIG TXOP Protection Full Support", "wlan_mgt.ht.info.lsigprotsupport",
FT_BOOLEAN, 16, TFS (&ht_info_lsig_txop_protection_full_support_flag), 0x0200,
NULL, HFILL }},
{&hf_ieee80211_ht_info_pco_active,
{"Phased Coexistence Operation (PCO)", "wlan_mgt.ht.info.pco.active",
FT_BOOLEAN, 16, TFS (&tfs_active_inactive), 0x0400,
NULL, HFILL }},
{&hf_ieee80211_ht_info_pco_phase,
{"Phased Coexistence Operation (PCO) Phase", "wlan_mgt.ht.info.pco.phase",
FT_BOOLEAN, 16, TFS (&ht_info_pco_phase_flag), 0x0800,
NULL, HFILL }},
{&hf_ieee80211_ht_info_reserved_3,
{"Reserved", "wlan_mgt.ht.info.reserved3",
FT_UINT16, BASE_HEX, NULL, 0xf000,
NULL, HFILL }},
{&hf_ieee80211_tag_ap_channel_report_operating_class,
{"Operating Class", "wlan_mgt.ap_channel_report.operating_class",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ap_channel_report_channel_list,
{"Channel List", "wlan_mgt.ap_channel_report.channel_list",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_secondary_channel_offset,
{"Secondary Channel Offset", "wlan_mgt.secchanoffset",
FT_UINT8, BASE_HEX, VALS(ieee80211_tag_secondary_channel_offset_flags), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_ap_avg_access_delay,
{"AP Average Access Delay", "wlan_mgt.bss_ap_avg_access_delay",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_antenna_id,
{"Antenna ID", "wlan_mgt.antenna.id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_rsni,
{"RSNI", "wlan_mgt.rsni",
FT_UINT8, BASE_CUSTOM, CF_FUNC(rsni_base_custom), 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask,
{"Available Admission Capacity Bitmask", "wlan_mgt.bss_avb_adm_cap.bitmask",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up0,
{"UP0 (bit0)", "wlan_mgt.bss_avb_adm_cap.bitmask.up0",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_UP0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up1,
{"UP1 (bit1)", "wlan_mgt.bss_avb_adm_cap.bitmask.up1",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_UP1,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up2,
{"UP2 (bit2)", "wlan_mgt.bss_avb_adm_cap.bitmask.up2",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_UP2,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up3,
{"UP3 (bit3)", "wlan_mgt.bss_avb_adm_cap.bitmask.up3",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_UP3,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up4,
{"UP4 (bit4)", "wlan_mgt.bss_avb_adm_cap.bitmask.up4",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_UP4,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up5,
{"UP5 (bit5)", "wlan_mgt.bss_avb_adm_cap.bitmask.up5",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_UP5,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up6,
{"UP0 (bit6)", "wlan_mgt.bss_avb_adm_cap.bitmask.up6",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_UP6,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_up7,
{"UP7 (bit7)", "wlan_mgt.bss_avb_adm_cap.bitmask.up7",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_UP7,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_ac0,
{"AC0 (bit8)", "wlan_mgt.bss_avb_adm_cap.bitmask.ac0",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_AC0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_ac1,
{"AC1 (bit9)", "wlan_mgt.bss_avb_adm_cap.bitmask.AC1",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_AC1,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_ac2,
{"AC2 (bit10)", "wlan_mgt.bss_avb_adm_cap.bitmask.ac2",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_AC2,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_ac3,
{"AC3 (bit11)", "wlan_mgt.bss_avb_adm_cap.bitmask.ac3",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), BSS_BITMASK_AC3,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_bitmask_rsv,
{"Reserved", "wlan_mgt.bss_avb_adm_cap.bitmask.rsv",
FT_UINT16, BASE_HEX, NULL, BSS_BITMASK_RSV,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_up0,
{"UP0", "wlan_mgt.bss_avb_adm_cap.up0",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_up1,
{"UP1", "wlan_mgt.bss_avb_adm_cap.up1",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_up2,
{"UP2", "wlan_mgt.bss_avb_adm_cap.up2",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_up3,
{"UP3", "wlan_mgt.bss_avb_adm_cap.up3",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_up4,
{"UP4", "wlan_mgt.bss_avb_adm_cap.up4",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_up5,
{"UP5", "wlan_mgt.bss_avb_adm_cap.up5",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_up6,
{"UP6", "wlan_mgt.bss_avb_adm_cap.up6",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_up7,
{"UP7", "wlan_mgt.bss_avb_adm_cap.up7",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_ac0,
{"AC0", "wlan_mgt.bss_avb_adm_cap.ac0",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_ac1,
{"AC1", "wlan_mgt.bss_avb_adm_cap.ac1",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_ac2,
{"AC2", "wlan_mgt.bss_avb_adm_cap.ac2",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avb_adm_cap_ac3,
{"AC3", "wlan_mgt.bss_avb_adm_cap.ac3",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avg_ac_access_delay_be,
{"AC Average Access Delay for Best Effort", "wlan_mgt.bss_avg_ac_access_delay.be",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avg_ac_access_delay_bk,
{"AC Average Access Delay for Best Background", "wlan_mgt.bss_avg_ac_access_delay.bk",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avg_ac_access_delay_vi,
{"AC Average Access Delay for Video", "wlan_mgt.bss_avg_ac_access_delay_vi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_avg_ac_access_delay_vo,
{"AC Average Access Delay for Voice", "wlan_mgt.bss_avg_ac_access_delay_vo",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities,
{"RM Capabilities", "wlan_mgt.rmcap",
FT_UINT8, BASE_HEX, NULL, 0,
"Signals support for radio measurements in a device", HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b0,
{"Link Measurement", "wlan_mgt.rmcap.b0",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b1,
{"Neighbor Report", "wlan_mgt.rmcap.b1",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b2,
{"Parallel Measurements", "wlan_mgt.rmcap.b2",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b3,
{"Repeated Measurements", "wlan_mgt.rmcap.b3",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b4,
{"Beacon Passive Measurement", "wlan_mgt.rmcap.b4",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b5,
{"Beacon Active Measurement", "wlan_mgt.rmcap.b5",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x20,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b6,
{"Beacon Table Measurement", "wlan_mgt.rmcap.b6",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b7,
{"Beacon Measurement Reporting Conditions", "wlan_mgt.rmcap.b7",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b8,
{"Frame Measurement", "wlan_mgt.rmcap.b8",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b9,
{"Channel Load Measurement", "wlan_mgt.rmcap.b9",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b10,
{"Noise Histogram Measurement", "wlan_mgt.rmcap.b10",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b11,
{"Statistics Measurement", "wlan_mgt.rmcap.b11",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b12,
{"LCI Measurement", "wlan_mgt.rmcap.b12",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b13,
{"LCI Azimuth capability", "wlan_mgt.rmcap.b13",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x20,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b14,
{"Transmit Stream/Category Measurement", "wlan_mgt.rmcap.b14",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b15,
{"Triggered Transmit Stream/Category Measurement", "wlan_mgt.rmcap.b15",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b16,
{"AP Channel Report capability", "wlan_mgt.rmcap.b16",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b17,
{"RM MIB capability", "wlan_mgt.rmcap.b17",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b18to20,
{"Operating Channel Max Measurement Duration", "wlan_mgt.rmcap.b18to20",
FT_UINT8, BASE_DEC, NULL, 0x1C,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b21to23,
{"Nonoperating Channel Max Measurement Duration", "wlan_mgt.rmcap.b21to23",
FT_UINT8, BASE_DEC, NULL, 0xE0,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b24to26,
{"Measurement Pilotcapability", "wlan_mgt.rmcap.b24to26",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b27,
{"Measurement Pilot Transmission Information", "wlan_mgt.rmcap.b27",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b28,
{"Neighbor Report TSF Offset", "wlan_mgt.rmcap.b28",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b29,
{"RCPI Measurement capability", "wlan_mgt.rmcap.b29",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x20,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b30,
{"RSNI Measurement capability", "wlan_mgt.rmcap.b30",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b31,
{"BSS Average Access Delay capability", "wlan_mgt.rmcap.b31",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b32,
{"BSS Available Admission Capacity capability", "wlan_mgt.rmcap.b32",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_b33,
{"Antenna capability", "wlan_mgt.rmcap.b33",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_rm_enabled_capabilities_o5,
{"Reserved", "wlan_mgt.rmcap.o5",
FT_UINT8, BASE_HEX, NULL, 0xFC,
"Must be zero", HFILL }},
{&hf_ieee80211_tag_power_constraint_local,
{"Local Power Constraint", "wlan_mgt.powercon.local",
FT_UINT8, BASE_DEC, NULL, 0,
"Value that allows the mitigation requirements to be satisfied in the current channel", HFILL }},
{&hf_ieee80211_tag_power_capability_min,
{"Minimum Transmit Power", "wlan_mgt.powercap.min",
FT_UINT8, BASE_HEX, NULL, 0,
"The nominal minimum transmit power with which the STA is capable of transmitting in the current channel", HFILL }},
{&hf_ieee80211_tag_power_capability_max,
{"Maximum Transmit Power", "wlan_mgt.powercap.max",
FT_UINT8, BASE_HEX, NULL, 0,
"The nominal maximum transmit power with which the STA is capable of transmitting in the current channel", HFILL }},
{&hf_ieee80211_tag_tpc_report_trsmt_pow,
{"Transmit Power", "wlan_mgt.tcprep.trsmt_pow",
FT_INT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_tpc_report_link_mrg,
{"Link Margin", "wlan_mgt.tcprep.link_mrg",
FT_INT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_supported_channels,
{"Supported Channels Set", "wlan_mgt.supchan",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_supported_channels_first,
{"First Supported Channel", "wlan_mgt.supchan.first",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_supported_channels_range,
{"Supported Channel Range", "wlan_mgt.supchan.range",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_csa_channel_switch_mode,
{"Channel Switch Mode", "wlan_mgt.csa.channel_switch_mode",
FT_UINT8, BASE_HEX, NULL, 0,
"Indicates any restrictions on transmission until a channel switch", HFILL }},
{&hf_ieee80211_csa_new_channel_number,
{"New Channel Number", "wlan_mgt.csa.new_channel_number",
FT_UINT8, BASE_HEX, NULL, 0,
"Set to the number of the channel to which the STA is moving", HFILL }},
{&hf_ieee80211_csa_channel_switch_count,
{"Channel Switch Count", "wlan_mgt.csa.channel_switch.count",
FT_UINT8, BASE_DEC, NULL, 0,
"Set to the number of TBTTs until the STA sending the Channel Switch Announcement element switches to the new channel or shall be set to 0", HFILL }},
{&hf_ieee80211_mesh_channel_switch_ttl,
{"Mesh Channel Switch TTL", "wlan_mgt.csa.mesh_channel_switch.ttl",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_mesh_channel_switch_flag,
{"Mesh Channel Switch Flag", "wlan_mgt.csa.mesh_channel_switch.flag",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_mesh_chswitch_flag_txrestrict,
{"CSA Tx Restrict", "wlan_mgt.csa.mesh_channel_switch.flag.txrestrict",
FT_BOOLEAN, 16, TFS (&csa_txrestrict_flags), 0x0001,
NULL, HFILL }},
{&hf_ieee80211_mesh_chswitch_flag_initiator,
{"CSA Initiator", "wlan_mgt.csa.mesh_channel_switch.flag.initiator",
FT_BOOLEAN, 16, TFS (&csa_initiator_flags), 0x0002,
NULL, HFILL }},
{&hf_ieee80211_mesh_channel_switch_reason_code,
{"Mesh Channel Switch Reason Code", "wlan_mgt.csa.mesh_channel_switch.reason_code",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &ieee80211_reason_code_ext, 0,
NULL, HFILL }},
{&hf_ieee80211_mesh_channel_switch_precedence_value,
{"Mesh Channel Switch Precedence Value", "wlan_mgt.csa.mesh_channel_switch.pre_value",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_token,
{"Measurement Token", "wlan_mgt.measure.req.token",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode,
{"Measurement Request Mode", "wlan_mgt.measure.req.mode",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_parallel,
{"Parallel", "wlan_mgt.measure.req.reqmode.parallel",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_enable,
{"Measurement Request Mode Field", "wlan_mgt.measure.req.reqmode.enable",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_request,
{"Measurement Reports", "wlan_mgt.measure.req.reqmode.request",
FT_BOOLEAN, 8, TFS (&tfs_accepted_not_accepted), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_report,
{"Autonomous Measurement Reports", "wlan_mgt.measure.req.reqmode.report",
FT_BOOLEAN, 8, TFS (&tfs_accepted_not_accepted), 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_duration_mandatory,
{"Duration Mandatory", "wlan_mgt.measure.req.reqmode.duration_mandatory",
FT_BOOLEAN, 8, TFS (&tfs_accepted_not_accepted), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_reserved,
{"Reserved", "wlan_mgt.measure.req.reqmode.reserved",
FT_UINT8, BASE_HEX, NULL, 0xE0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_type,
{"Measurement Request Type", "wlan_mgt.measure.req.reqtype",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ieee80211_tag_measure_request_type_flags_ext, 0x00,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_channel_number,
{"Measurement Channel Number", "wlan_mgt.measure.req.channelnumber",
FT_UINT8, BASE_CUSTOM, CF_FUNC(channel_number_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_start_time,
{"Measurement Start Time", "wlan_mgt.measure.req.starttime",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_duration,
{"Measurement Duration", "wlan_mgt.measure.req.channelnumber",
FT_UINT16, BASE_HEX, NULL, 0,
"in TU (1 TU = 1024 us)", HFILL }},
{&hf_ieee80211_tag_measure_request_operating_class,
{"Operating Class", "wlan_mgt.measure.req.operatingclass",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_randomization_interval,
{"Randomization Interval", "wlan_mgt.measure.req.randint",
FT_UINT16, BASE_HEX, NULL, 0,
"in TU (1 TU = 1024 us)", HFILL }},
{&hf_ieee80211_tag_measure_request_measurement_mode,
{"Measurement Mode", "wlan_mgt.measure.req.measurementmode",
FT_UINT8, BASE_HEX, VALS(ieee80211_tag_measure_request_measurement_mode_flags), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_bssid,
{"BSSID", "wlan_mgt.measure.req.bssid",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_subelement_length,
{"Length", "wlan_mgt.measure.req.sub.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_id,
{"SubElement ID", "wlan_mgt.measure.req.beacon.sub.id",
FT_UINT8, BASE_DEC, VALS(ieee80211_tag_measure_request_beacon_sub_id_flags), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_ssid,
{"SSID", "wlan_mgt.measure.req.beacon.sub.ssid",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_bri_reporting_condition,
{"Reporting Condition", "wlan_mgt.measure.req.beacon.sub.bri.repcond",
FT_UINT8, BASE_HEX, VALS(ieee80211_tag_measure_request_beacon_sub_bri_reporting_condition_flags), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_bri_threshold_offset,
{"Threshold/Offset", "wlan_mgt.measure.req.beacon.sub.bri.threshold_offset",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_reporting_detail,
{"Reporting Detail", "wlan_mgt.measure.req.beacon.sub.bri.reporting_detail",
FT_UINT8, BASE_HEX, VALS(ieee80211_tag_measure_request_beacon_sub_reporting_detail_flags), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_request,
{"Request", "wlan_mgt.measure.req.beacon.sub.request",
FT_UINT8, BASE_DEC, 0, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_unknown,
{"Unknown Data", "wlan_mgt.measure.req.beacon.unknown",
FT_BYTES, BASE_NONE, NULL, 0,
"(not interpreted)", HFILL }},
{&hf_ieee80211_tag_measure_request_channel_load_sub_id,
{"SubElement ID", "wlan_mgt.measure.req.channel_load.sub.id",
FT_UINT8, BASE_DEC, VALS(ieee80211_tag_measure_request_channel_load_sub_id_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_channel_load_sub_reporting_condition,
{"Reporting Condition", "wlan_mgt.measure.req.channel_load.sub.repcond",
FT_UINT8, BASE_HEX, VALS(ieee80211_tag_measure_request_channel_load_sub_reporting_condition_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_channel_load_sub_reporting_ref,
{"Reference Value", "wlan_mgt.measure.req.channel_load.sub.ref",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_noise_histogram_sub_id,
{"SubElement ID", "wlan_mgt.measure.req.noise_histogram.sub.id",
FT_UINT8, BASE_DEC, VALS(ieee80211_tag_measure_request_noise_histogram_sub_id_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_noise_histogram_sub_reporting_condition,
{"Reporting Condition", "wlan_mgt.measure.reqnoise_histogram.sub.repcond",
FT_UINT8, BASE_HEX, VALS(ieee80211_tag_measure_request_noise_histogram_sub_reporting_condition_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_noise_histogram_sub_reporting_anpi_ref,
{"ANPI Reference Value", "wlan_mgt.measure.req.noise_histogram.sub.anpiref",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_frame_request_type,
{"Frame Request Type", "wlan_mgt.measure.req.frame_request_type",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mac_address,
{"MAC Address", "wlan_mgt.measure.req.mac_address",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_peer_mac_address,
{"Peer MAC Address", "wlan_mgt.measure.req.peer_mac_address",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_group_id,
{"Group ID", "wlan_mgt.measure.req.groupid",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ieee80211_tag_measure_request_group_id_flags_ext, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_unknown,
{"Unknown Data", "wlan_mgt.measure.req.unknown",
FT_BYTES, BASE_NONE, NULL, 0,
"(not interpreted)", HFILL }},
{&hf_ieee80211_tag_measure_report_measurement_token,
{"Measurement Token", "wlan_mgt.measure.req.token",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_mode,
{"Measurement Report Mode", "wlan_mgt.measure.req.mode",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_mode_late,
{"Measurement Report Mode Field", "wlan_mgt.measure.rep.repmode.late",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_mode_incapable,
{"Measurement Reports", "wlan_mgt.measure.rep.repmode.incapable",
FT_BOOLEAN, 8, TFS (&tfs_accepted_not_accepted), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_mode_refused,
{"Autonomous Measurement Reports", "wlan_mgt.measure.rep.repmode.refused",
FT_BOOLEAN, 8, TFS (&tfs_accepted_not_accepted), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_mode_reserved,
{"Reserved", "wlan_mgt.measure.rep.repmode.reserved",
FT_UINT8, BASE_HEX, NULL, 0xf8,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_type,
{"Measurement Report Type", "wlan_mgt.measure.rep.reptype",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ieee80211_tag_measure_report_type_flags_ext, 0x00,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_channel_number,
{"Measurement Channel Number", "wlan_mgt.measure.rep.channelnumber",
FT_UINT8, BASE_CUSTOM, CF_FUNC(channel_number_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_start_time,
{"Measurement Start Time", "wlan_mgt.measure.rep.starttime",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_duration,
{"Measurement Duration", "wlan_mgt.measure.rep.channelnumber",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_cca_busy_fraction,
{"CCA Busy Fraction", "wlan_mgt.measure.rep.ccabusy",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_basic_map_field,
{"Map Field", "wlan_mgt.measure.rep.mapfield",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_bss,
{"BSS", "wlan_mgt.measure.rep.repmode.mapfield.bss",
FT_BOOLEAN, 8, TFS (&ieee80211_tag_measure_map_field_bss_flag), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_odfm,
{"Orthogonal Frequency Division Multiplexing (ODFM) Preamble", "wlan_mgt.measure.rep.repmode.mapfield.bss",
FT_BOOLEAN, 8, TFS (&tfs_detected_not_detected), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_unident_signal,
{"Unidentified Signal", "wlan_mgt.measure.rep.repmode.mapfield.unidentsig",
FT_BOOLEAN, 8, TFS (&tfs_detected_not_detected), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_radar,
{"Radar", "wlan_mgt.measure.rep.repmode.mapfield.radar",
FT_BOOLEAN, 8, TFS (&tfs_detected_not_detected), 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_unmeasured,
{"Unmeasured", "wlan_mgt.measure.rep.repmode.mapfield.unmeasured",
FT_BOOLEAN, 8, TFS (&tfs_true_false), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_reserved,
{"Reserved", "wlan_mgt.measure.rep.repmode.mapfield.reserved",
FT_UINT8, BASE_HEX, NULL, 0xe0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report,
{"Receive Power Indicator (RPI) Histogram Report", "wlan_mgt.measure.rep.rpi.histogram_report",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_0,
{"RPI 0 Density", "wlan_mgt.measure.rep.rpi.rpi0density",
FT_UINT8, BASE_HEX, NULL, 0,
"Receive Power Indicator (RPI) 0 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_1,
{"RPI 1 Density", "wlan_mgt.measure.rep.rpi.rpi1density",
FT_UINT8, BASE_HEX, NULL, 0,
"Receive Power Indicator (RPI) 1 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_2,
{"RPI 2 Density", "wlan_mgt.measure.rep.rpi.rpi2density",
FT_UINT8, BASE_HEX, NULL, 0,
"Receive Power Indicator (RPI) 2 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_3,
{"RPI 3 Density", "wlan_mgt.measure.rep.rpi.rpi3density",
FT_UINT8, BASE_HEX, NULL, 0,
"Receive Power Indicator (RPI) 3 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_4,
{"RPI 4 Density", "wlan_mgt.measure.rep.rpi.rpi4density",
FT_UINT8, BASE_HEX, NULL, 0,
"Receive Power Indicator (RPI) 4 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_5,
{"RPI 5 Density", "wlan_mgt.measure.rep.rpi.rpi5density",
FT_UINT8, BASE_HEX, NULL, 0,
"Receive Power Indicator (RPI) 5 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_6,
{"RPI 6 Density", "wlan_mgt.measure.rep.rpi.rpi6density",
FT_UINT8, BASE_HEX, NULL, 0,
"Receive Power Indicator (RPI) 6 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_7,
{"RPI 7 Density", "wlan_mgt.measure.rep.rpi.rpi7density",
FT_UINT8, BASE_HEX, NULL, 0,
"Receive Power Indicator (RPI) 7 Density", HFILL }},
{&hf_ieee80211_tag_measure_report_operating_class,
{"Operating Class", "wlan_mgt.measure.rep.operatingclass",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_channel_load,
{"Channel Load", "wlan_mgt.measure.rep.chanload",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_frame_info,
{"Reported Frame Information", "wlan_mgt.measure.rep.frameinfo",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_frame_info_phy_type,
{"Condensed PHY", "wlan_mgt.measure.rep.frameinfo.phytype",
FT_UINT8, BASE_HEX, NULL, 0x7F,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_frame_info_frame_type,
{"Reported Frame Type", "wlan_mgt.measure.rep.frameinfo.frametype",
FT_BOOLEAN, 8, TFS(&ieee80211_tag_measure_report_frame_info_frame_type_flag), 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_rcpi,
{"Received Channel Power Indicator (RCPI)", "wlan_mgt.measure.rep.rcpi",
FT_UINT8, BASE_HEX, NULL, 0,
"in dBm", HFILL }},
{&hf_ieee80211_tag_measure_report_rsni,
{"Received Signal to Noise Indicator (RSNI)", "wlan_mgt.measure.rep.rsni",
FT_UINT8, BASE_HEX, NULL, 0,
"in dB", HFILL }},
{&hf_ieee80211_tag_measure_report_bssid,
{"BSSID Being Reported", "wlan_mgt.measure.rep.bssid",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ant_id,
{"Antenna ID", "wlan_mgt.measure.rep.antid",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_anpi,
{"ANPI", "wlan_mgt.measure.rep.anpi",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_0,
{"IPI Density 0", "wlan_mgt.measure.rep.ipi_density0",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_1,
{"IPI Density 1", "wlan_mgt.measure.rep.ipi_density1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_2,
{"IPI Density 2", "wlan_mgt.measure.rep.ipi_density2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_3,
{"IPI Density 3", "wlan_mgt.measure.rep.ipi_density3",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_4,
{"IPI Density 4", "wlan_mgt.measure.rep.ipi_density4",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_5,
{"IPI Density 5", "wlan_mgt.measure.rep.ipi_density5",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_6,
{"IPI Density 6", "wlan_mgt.measure.rep.ipi_density6",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_7,
{"IPI Density 7", "wlan_mgt.measure.rep.ipi_density7",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_8,
{"IPI Density 8", "wlan_mgt.measure.rep.ipi_density8",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_9,
{"IPI Density 9", "wlan_mgt.measure.rep.ipi_density9",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_10,
{"IPI Density 10", "wlan_mgt.measure.rep.ipi_density10",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_parent_tsf,
{"Parent Timing Synchronization Function (TSF)", "wlan_mgt.measure.rep.parenttsf",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_subelement_length,
{"Length", "wlan_mgt.measure.req.sub.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_beacon_sub_id,
{"SubElement ID", "wlan_mgt.measure.req.beacon.sub.id",
FT_UINT8, BASE_DEC, VALS(ieee80211_tag_measure_report_beacon_sub_id_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_unknown,
{"Unknown Data", "wlan_mgt.measure.rep.unknown",
FT_BYTES, BASE_NONE, NULL, 0,
"(not interpreted)", HFILL }},
{&hf_ieee80211_tag_quiet_count,
{"Count", "wlan_mgt.quiet.count",
FT_UINT8, BASE_DEC, NULL, 0,
"Set to the number of TBTTs until the beacon interval during which the next quiet interval shall start", HFILL }},
{&hf_ieee80211_tag_quiet_period,
{"Period", "wlan_mgt.quiet.period",
FT_UINT8, BASE_DEC, NULL, 0,
"Set to the number of beacon intervals between the start of regularly scheduled quiet intervals", HFILL }},
{&hf_ieee80211_tag_quiet_duration,
{"Duration", "wlan_mgt.quiet.duration",
FT_UINT16, BASE_DEC, NULL, 0,
"Set to the duration of the quiet interval", HFILL }},
{&hf_ieee80211_tag_quiet_offset,
{"Offset", "wlan_mgt.quiet.offset",
FT_UINT16, BASE_DEC, NULL, 0,
"Set to the offset of the start of the quiet interval from the TBTT", HFILL }},
{&hf_ieee80211_tag_dfs_owner,
{"Owner", "wlan_mgt.dfs.owner",
FT_ETHER, BASE_NONE, NULL, 0,
"Set to the individual IEEE MAC address of the STA that is the currently known DFS Owner in the IBSS", HFILL }},
{&hf_ieee80211_tag_dfs_recovery_interval,
{"Recovery Interval", "wlan_mgt.dfs.recovery_interval",
FT_UINT8, BASE_DEC, NULL, 0,
"Indicates the time interval that shall be used for DFS owner recovery", HFILL }},
{&hf_ieee80211_tag_dfs_channel_map,
{"Channel Map", "wlan_mgt.dfs.channel_map",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_dfs_channel_number,
{"Channel Number", "wlan_mgt.dfs.channel_number",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_dfs_map,
{"Map", "wlan_mgt.dfs.map",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_erp_info,
{"ERP Information", "wlan_mgt.erp_info",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_erp_info_erp_present,
{"Non ERP Present", "wlan_mgt.erp_info.erp_present",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_erp_info_use_protection,
{"Use Protection", "wlan_mgt.erp_info.use_protection",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_erp_info_barker_preamble_mode,
{"Barker Preamble Mode", "wlan_mgt.erp_info.barker_preamble_mode",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_erp_info_reserved,
{"Reserved", "wlan_mgt.erp_info.reserved",
FT_UINT8, BASE_HEX, NULL, 0xF8,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities,
{"Extended Capabilities", "wlan_mgt.extcap",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b0,
{"20/40 BSS Coexistence Management Support", "wlan_mgt.extcap.b0",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
"HT Information Exchange Support", HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b1,
{"On-demand beacon", "wlan_mgt.extcap.b1",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b2,
{"Extended Channel Switching", "wlan_mgt.extcap.b2",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b3,
{"WAVE indication", "wlan_mgt.extcap.b3",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b4,
{"PSMP Capability", "wlan_mgt.extcap.b4",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b5,
{"Reserved", "wlan_mgt.extcap.b5",
FT_UINT8, BASE_HEX, NULL, 0x20,
"Must be zero", HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b6,
{"S-PSMP Support", "wlan_mgt.extcap.b6",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b7,
{"Event", "wlan_mgt.extcap.b7",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b8,
{"Diagnostics", "wlan_mgt.extcap.b8",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b9,
{"Multicast Diagnostics", "wlan_mgt.extcap.b9",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b10,
{"Location Tracking", "wlan_mgt.extcap.b10",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b11,
{"FMS", "wlan_mgt.extcap.b11",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b12,
{"Proxy ARP Service", "wlan_mgt.extcap.b12",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b13,
{"Collocated Interference Reporting", "wlan_mgt.extcap.b13",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b14,
{"Civic Location", "wlan_mgt.extcap.b14",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b15,
{"Geospatial Location", "wlan_mgt.extcap.b15",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b16,
{"TFS", "wlan_mgt.extcap.b16",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b17,
{"WNM-Sleep Mode", "wlan_mgt.extcap.b17",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b18,
{"TIM Broadcast", "wlan_mgt.extcap.b18",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b19,
{"BSS Transition", "wlan_mgt.extcap.b19",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b20,
{"QoS Traffic Capability", "wlan_mgt.extcap.b20",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b21,
{"AC Station Count", "wlan_mgt.extcap.b21",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b22,
{"Multiple BSSID", "wlan_mgt.extcap.b22",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b23,
{"Timing Measurement", "wlan_mgt.extcap.b23",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b24,
{"Channel Usage", "wlan_mgt.extcap.b24",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b25,
{"SSID List", "wlan_mgt.extcap.b25",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b26,
{"DMS", "wlan_mgt.extcap.b26",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b27,
{"UTC TSF Offset", "wlan_mgt.extcap.b27",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b28,
{"Peer U-APSD Buffer STA Support", "wlan_mgt.extcap.b28",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b29,
{"TDLS Peer PSM Support", "wlan_mgt.extcap.b29",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b30,
{"TDLS channel switching", "wlan_mgt.extcap.b30",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b31,
{"Interworking", "wlan_mgt.extcap.b31",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b32,
{"QoS Map", "wlan_mgt.extcap.b32",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b33,
{"EBR", "wlan_mgt.extcap.b33",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b34,
{"SSPN Interface", "wlan_mgt.extcap.b34",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b35,
{"Reserved", "wlan_mgt.extcap.b35",
FT_UINT8, BASE_HEX, NULL, 0x08,
"Must be zero", HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b36,
{"MSGCF Capability", "wlan_mgt.extcap.b36",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b37,
{"TDLS support", "wlan_mgt.extcap.b37",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b38,
{"TDLS Prohibited", "wlan_mgt.extcap.b38",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b39,
{"TDLS Channel Switching Prohibited", "wlan_mgt.extcap.b39",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b40,
{"Reject Unadmitted Frame", "wlan_mgt.extcap.b40",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_serv_int_granularity,
{"Service Interval Granularity",
"wlan_mgt.extcap.serv_int_granularity",
FT_UINT8, BASE_DEC, VALS(service_interval_granularity_vals), 0x0e,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b44,
{"Identifier Location", "wlan_mgt.extcap.b44",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b45,
{"U-APSD Coexistence", "wlan_mgt.extcap.b45",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b46,
{"WNM-Notification", "wlan_mgt.extcap.b46",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b47,
{"QAB Capability", "wlan_mgt.extcap.b47",
FT_UINT8, BASE_HEX, NULL, 0x80,
"AP supports QAB", HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b48,
{"UTF-8 SSID", "wlan_mgt.extcap.b48",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
"The SSID in this BSS is interpreted using UTF-8 encoding", HFILL }},
{&hf_ieee80211_tag_extended_capabilities_o7,
{"Reserved", "wlan_mgt.extcap.o7",
FT_UINT8, BASE_HEX, NULL, 0xfe,
"Must be zero", HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b61,
{"TDLS Wider Bandwidth", "wlan_mgt.extcap.b61",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b62,
{"Operating Mode Notification", "wlan_mgt.extcap.b62",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b63,
{"Max Number Of MSDUs In A-MSDU", "wlan_mgt.extcap.b63",
FT_UINT8, BASE_DEC, NULL, 0x80,
"Part 1 (bit63)", HFILL }},
{&hf_ieee80211_tag_extended_capabilities_o8,
{"Reserved", "wlan_mgt.extcap.o8",
FT_UINT8, BASE_HEX, NULL, 0x1f,
"Must be zero", HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b64,
{"Max Number Of MSDUs In A-MSDU64", "wlan_mgt.extcap.b64",
FT_UINT8, BASE_DEC, NULL, 0x01,
"Part 2 (bit64)", HFILL }},
{&hf_ieee80211_tag_extended_capabilities_o9,
{"Reserved", "wlan_mgt.extcap.o9",
FT_UINT8, BASE_HEX, NULL, 0xfe,
"Must be zero", HFILL }},
{&hf_ieee80211_tag_cisco_ccx1_unknown,
{"Unknown", "wlan_mgt.cisco.ccx1.unknown",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_cisco_ccx1_name,
{"Name", "wlan_mgt.cisco.ccx1.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_cisco_ccx1_clients,
{"Clients", "wlan_mgt.cisco.ccx1.clients",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_cisco_ccx1_unknown2,
{"Unknown2", "wlan_mgt.cisco.ccx1.unknown2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid,
{"BSSID", "wlan_mgt.nreport.bssid",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info,
{"BSSID Information", "wlan_mgt.nreport.bssid.info",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_reachability,
{"AP Reachability", "wlan_mgt.nreport.bssid.info.reachability",
FT_UINT32, BASE_HEX, VALS(ieee80211_neighbor_report_bssid_info_reachability_vals), 0x00000003,
"Indicates whether the AP identified by this BSSID is reachable by the STA that requested the neighbor report", HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_security,
{"Security", "wlan_mgt.nreport.bssid.info.security",
FT_BOOLEAN, 32, NULL, 0x00000004,
"Indicates that the AP identified by this BSSID supports the same security provisioning as used by the STA in its current association", HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_key_scope,
{"Key Scope", "wlan_mgt.nreport.bssid.info.keyscope",
FT_BOOLEAN, 32, NULL, 0x00000008,
"indicates the AP indicated by this BSSID has the same authenticator as the AP sending the report", HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability,
{"Capability", "wlan_mgt.nreport.bssid.info.capability",
FT_UINT32, BASE_HEX, NULL, 0x000003F0,
"Contains selected capability information for the AP indicated by this BSSID", HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_spec_mng,
{"Spectrum Management", "wlan_mgt.nreport.bssid.info.capability.specmngt",
FT_BOOLEAN, 32, NULL, 0x00000010,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_qos,
{"QoS", "wlan_mgt.nreport.bssid.info.capability.qos",
FT_BOOLEAN, 32, NULL, 0x00000020,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_apsd,
{"APSD", "wlan_mgt.nreport.bssid.info.capability.apsd",
FT_BOOLEAN, 32, NULL, 0x00000040,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_radio_msnt,
{"Radio Measurement", "wlan_mgt.nreport.bssid.info.capability.radiomsnt",
FT_BOOLEAN, 32, NULL, 0x00000080,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_dback,
{"Delayed Block Ack", "wlan_mgt.nreport.bssid.info.capability.dback",
FT_BOOLEAN, 32, NULL, 0x000000100,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_iback,
{"Immediate Block Ack", "wlan_mgt.nreport.bssid.info.capability.iback",
FT_BOOLEAN, 32, NULL, 0x00000200,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_mobility_domain,
{"Mobility Domain", "wlan_mgt.nreport.bssid.info.mobilitydomain",
FT_BOOLEAN, 32, NULL, 0x00000400,
"", HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_high_throughput,
{"High Throughput Control (+HTC)", "wlan_mgt.nreport.bssid.info.hthoughput",
FT_BOOLEAN, 32, NULL, 0x00000800,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_reserved,
{"Reserved", "wlan_mgt.nreport.bssid.info.reserved",
FT_UINT32, BASE_HEX, NULL, 0xFFFFF000,
"Must be zero", HFILL }},
{&hf_ieee80211_tag_neighbor_report_ope_class,
{"Operating Class", "wlan_mgt.nreport.opeclass",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_channel_number,
{"Channel Number", "wlan_mgt.nreport.channumber",
FT_UINT8, BASE_CUSTOM, CF_FUNC(channel_number_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_phy_type,
{"PHY Type", "wlan_mgt.nreport.phytype",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_subelement_id,
{"Subelement ID", "wlan_mgt.nreport.subelement_id",
FT_UINT8, BASE_HEX, VALS(ieee80211_neighbor_report_subelement_id_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_subelement_length,
{"Length", "wlan_mgt.nreport.phytype.subelement_length",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_supported_ope_classes_current,
{"Current Operating Class", "wlan_mgt.supopeclass.current",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_supported_ope_classes_alternate,
{"Alternate Operating Classes", "wlan_mgt.supopeclass.alt",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_type,
{"Type", "wlan_mgt.wfa.ie.type",
FT_UINT8, BASE_HEX, VALS(ieee802111_wfa_ie_type_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_version,
{"WPA Version", "wlan_mgt.wfa.ie.wpa.version",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_mcs,
{"Multicast Cipher Suite", "wlan_mgt.wfa.ie.wpa.mcs",
FT_UINT32, BASE_CUSTOM, CF_FUNC(wpa_mcs_base_custom), 0,
"Contains the cipher suite selector used by the BSS to protect broadcast/multicasttraffic", HFILL }},
{&hf_ieee80211_wfa_ie_wpa_mcs_oui,
{"Multicast Cipher Suite OUI", "wlan_mgt.wfa.ie.wpa.mcs.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_mcs_type,
{"Multicast Cipher Suite type", "wlan_mgt.wfa.ie.wpa.mcs.type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_mcs_wfa_type,
{"Multicast Cipher Suite type", "wlan_mgt.wfa.ie.wpa.mcs.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_wfa_ie_wpa_cipher_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs_count,
{"Unicast Cipher Suite Count", "wlan_mgt.wfa.ie.wpa.ucs.count",
FT_UINT16, BASE_DEC, NULL, 0,
"Indicates the number of pairwise cipher suite selectors that are contained in the Unicast Cipher Suite List", HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs_list,
{"Unicast Cipher Suite List", "wlan_mgt.wfa.ie.wpa.ucs.list",
FT_NONE, BASE_NONE, NULL, 0,
"Contains a series of cipher suite selectors that indicate the Unicast cipher suites", HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs,
{"Unicast Cipher Suite", "wlan_mgt.wfa.ie.wpa.ucs",
FT_UINT32, BASE_CUSTOM, CF_FUNC(wpa_ucs_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs_oui,
{"Unicast Cipher Suite OUI", "wlan_mgt.wfa.ie.wpau.cs.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs_type,
{"Unicast Cipher Suite type", "wlan_mgt.wfa.ie.wpa.ucs.type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs_wfa_type,
{"Unicast Cipher Suite type", "wlan_mgt.wfa.ie.wpa.ucs.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_wfa_ie_wpa_cipher_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms_count,
{"Auth Key Management (AKM) Suite Count", "wlan_mgt.wfa.ie.wpa.akms.count",
FT_UINT16, BASE_DEC, NULL, 0,
"Indicates the number of Auth Key Management suite selectors that are contained in the Auth Key Management Suite List", HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms_list,
{"Auth Key Management (AKM) List", "wlan_mgt.wfa.ie.wpa.akms.list",
FT_NONE, BASE_NONE, NULL, 0,
"Contains a series of cipher suite selectors that indicate the AKM suites", HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms,
{"Auth Key Management (AKM) Suite", "wlan_mgt.wfa.ie.wpa.akms",
FT_UINT32, BASE_CUSTOM, CF_FUNC(wpa_akms_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms_oui,
{"Auth Key Management (AKM) OUI", "wlan_mgt.wfa.ie.wpa.akms.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms_type,
{"Auth Key Management (AKM) type", "wlan_mgt.wfa.ie.wpa.akms.type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms_wfa_type,
{"Auth Key Management (AKM) type", "wlan_mgt.wfa.ie.wpa.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_wfa_ie_wpa_keymgmt_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_subtype,
{"WME Subtype", "wlan_mgt.wfa.ie.wme.subtype",
FT_UINT8, BASE_DEC, VALS(ieee802111_wfa_ie_wme_type), 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_version,
{"WME Version", "wlan_mgt.wfa.ie.wme.version",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info,
{"WME QoS Info", "wlan_mgt.wfa.ie.wme.qos_info",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_max_sp_length,
{"Max SP Length", "wlan_mgt.wfa.ie.wme.qos_info.sta.max_sp_length",
FT_UINT8, BASE_HEX, VALS(ieee802111_wfa_ie_wme_qos_info_sta_max_sp_length_vals), 0x60,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_be,
{"AC_BE", "wlan_mgt.wfa.ie.wme.qos_info.sta.ac_be",
FT_BOOLEAN, 8, TFS(&ieee802111_wfa_ie_wme_qos_info_sta_ac_tfs), 0x08,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_bk,
{"AC_BK", "wlan_mgt.wfa.ie.wme.qos_info.sta.ac_bk",
FT_BOOLEAN, 8, TFS(&ieee802111_wfa_ie_wme_qos_info_sta_ac_tfs), 0x04,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_vi,
{"AC_VI", "wlan_mgt.wfa.ie.wme.qos_info.sta.ac_vi",
FT_BOOLEAN, 8, TFS(&ieee802111_wfa_ie_wme_qos_info_sta_ac_tfs), 0x02,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_vo,
{"AC_VO", "wlan_mgt.wfa.ie.wme.qos_info.sta.ac_vo",
FT_BOOLEAN, 8, TFS(&ieee802111_wfa_ie_wme_qos_info_sta_ac_tfs), 0x01,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_reserved,
{"Reserved", "wlan_mgt.wfa.ie.wme.qos_info.sta.reserved",
FT_UINT8, BASE_HEX, NULL, 0x90,
"Must Be Zero", HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_ap_u_apsd,
{"U-APSD", "wlan_mgt.wfa.ie.wme.qos_info.ap.u_apsd",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x80,
"Indicates the WMM AP is currently supporting unscheduled automatic power save delivery", HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_ap_parameter_set_count,
{"Parameter Set Count", "wlan_mgt.wfa.ie.wme.qos_info.ap.parameter_set_count",
FT_UINT8, BASE_HEX, NULL, 0x0F,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_ap_reserved,
{"Reserved", "wlan_mgt.wfa.ie.wme.qos_info.ap.reserved",
FT_UINT8, BASE_HEX, NULL, 0x70,
"Must Be Zero", HFILL }},
{&hf_ieee80211_wfa_ie_wme_reserved,
{"Reserved", "wlan_mgt.wfa.ie.wme.reserved",
FT_BYTES, BASE_NONE, NULL, 0,
"Must Be Zero", HFILL }},
{&hf_ieee80211_wfa_ie_wme_ac_parameters,
{"Ac Parameters", "wlan_mgt.wfa.ie.wme.acp",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_aci_aifsn,
{"ACI / AIFSN Field", "wlan_mgt.wfa.ie.wme.acp.aci_aifsn",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_aci,
{"ACI", "wlan_mgt.wfa.ie.wme.acp.aci",
FT_UINT8, BASE_DEC, VALS(ieee80211_wfa_ie_wme_acs_vals), 0x60,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_acm,
{"Admission Control Mandatory", "wlan_mgt.wfa.ie.wme.acp.acm",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_aifsn,
{"AIFSN", "wlan_mgt.wfa.ie.wme.acp.aifsn",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_reserved,
{"Reserved", "wlan_mgt.wfa.ie.wme.acp.reserved",
FT_UINT8, BASE_DEC, NULL, 0x80,
"Must be Zero", HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_ecw,
{"ECW", "wlan_mgt.wfa.ie.wme.acp.ecw",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_ecw_max,
{"ECW Max", "wlan_mgt.wfa.ie.wme.acp.ecw.max",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_ecw_min,
{"ECW Min", "wlan_mgt.wfa.ie.wme.acp.ecw.min",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_txop_limit,
{"TXOP Limit", "wlan_mgt.wfa.ie.wme.acp.txop_limit",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo,
{"TS Info", "wlan_mgt.wfa.ie.wme.tspec.ts_info",
FT_UINT24, BASE_HEX, NULL, 0,
"Traffic Stream (TS) Info", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo_tid,
{"TID", "wlan_mgt.wfa.ie.wme.tspec.ts_info.tid",
FT_UINT24, BASE_DEC, NULL, 0x00001E,
"Traffic Stream Info ID (TID)", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo_direction,
{"Direction", "wlan_mgt.wfa.ie.wme.tspec.ts_info.dir",
FT_UINT24, BASE_DEC, VALS(ieee80211_wfa_ie_wme_tspec_tsinfo_direction_vals), 0x000060,
"Traffic Stream (TS) Info Direction", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo_psb,
{"PSB", "wlan_mgt.wfa.ie.wme.tspec.ts_info.psb",
FT_UINT24, BASE_DEC, VALS(ieee80211_wfa_ie_wme_tspec_tsinfo_psb_vals), 0x000400,
"Traffic Stream (TS) Info Power Save Behavior (PSB)", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo_up,
{"UP", "wlan_mgt.wfa.ie.wme.tspec.ts_info.up",
FT_UINT24, BASE_DEC, VALS(ieee80211_wfa_ie_wme_tspec_tsinfo_up_vals), 0x003800,
"Traffic Stream (TS) Info User Priority (UP)", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo_reserved,
{"Reserved", "wlan_mgt.wfa.ie.wme.tspec.ts_info.reserved",
FT_UINT24, BASE_HEX, NULL, 0xFFC381,
"Must be Zero", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_nor_msdu,
{"Normal MSDU Size", "wlan_mgt.wfa.ie.wme.tspec.nor_msdu",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_max_msdu,
{"Maximum MSDU Size", "wlan_mgt.wfa.ie.wme.tspec.max_msdu",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_min_srv,
{"Minimum Service Interval", "wlan_mgt.wfa.ie.wme.tspec.min_srv",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_max_srv,
{"Maximum Service Interval", "wlan_mgt.wfa.ie.wme.tspec.max_srv",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_inact_int,
{"Inactivity Interval", "wlan_mgt.wfa.ie.wme.tspec.inact_int",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_susp_int,
{"Suspension Interval", "wlan_mgt.wfa.ie.wme.tspec.susp_int",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_srv_start,
{"Service Start Time", "wlan_mgt.wfa.ie.wme.tspec.srv_start",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_min_data,
{"Minimum Data Rate", "wlan_mgt.wfa.ie.wme.tspec.min_data",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_mean_data,
{"Mean Data Rate", "wlan_mgt.wfa.ie.wme.tspec.mean_data",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_peak_data,
{"Peak Data Rate", "wlan_mgt.wfa.ie.wme.tspec.peak_data",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_burst_size,
{"Burst Size", "wlan_mgt.wfa.ie.wme.tspec.burst_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_delay_bound,
{"Delay Bound", "wlan_mgt.wfa.ie.wme.tspec.delay_bound",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_min_phy,
{"Minimum PHY Rate", "wlan_mgt.wfa.ie.wme.tspec.min_phy",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_surplus,
{"Surplus Bandwidth Allowance", "wlan_mgt.wfa.ie.wme.tspec.surplus",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_medium,
{"Medium Time", "wlan_mgt.wfa.ie.wme.tspec.medium",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_ie_pmkid,
{"RSN PMKID", "wlan_mgt.rsn.ie.pmkid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_rsn_ie_unknown,
{"RSN Unknown", "wlan_mgt.rsn.ie.unknown",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_marvell_ie_type,
{"Type", "wlan_mgt.marvell.ie.type",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_marvell_ie_mesh_subtype,
{"Subtype", "wlan_mgt.marvell.ie.subtype",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_marvell_ie_mesh_version,
{"Version", "wlan_mgt.marvell.ie.version",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_marvell_ie_mesh_active_proto_id,
{"Path Selection Protocol", "wlan_mgt.marvell.ie.proto_id",
FT_UINT8, BASE_HEX, VALS(mesh_path_selection_codes), 0,
NULL, HFILL }},
{&hf_ieee80211_marvell_ie_mesh_active_metric_id,
{"Path Selection Metric", "wlan_mgt.marvell.ie.metric_id",
FT_UINT8, BASE_HEX, VALS(mesh_metric_codes), 0,
NULL, HFILL }},
{&hf_ieee80211_marvell_ie_mesh_cap,
{"Mesh Capabilities", "wlan_mgt.marvell.ie.cap",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_marvell_ie_data,
{ "Marvell IE data", "wlan_mgt.marvell.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_type,
{"Type", "wlan_mgt.atheros.ie.type",
FT_UINT8, BASE_HEX, VALS(atheros_ie_type_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_subtype,
{"Subtype", "wlan_mgt.atheros.ie.subtype",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_version,
{"Version", "wlan_mgt.atheros.ie.version",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_turbop,
{"Turbo Prime", "wlan_mgt.ie.atheros.capabilities.turbop",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_TURBOP,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_comp,
{"Compression", "wlan_mgt.ie.atheros.capabilities.comp",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_COMP,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_ff,
{"Fast Frames", "wlan_mgt.ie.atheros.capabilities.ff",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_FF,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_xr,
{"eXtended Range", "wlan_mgt.ie.atheros.capabilities.xr",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_XR,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_ar,
{"Advanced Radar", "wlan_mgt.ie.atheros.capabilities.ar",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_AR,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_burst,
{"Burst", "wlan_mgt.ie.atheros.capabilities.burst",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_BURST,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_wme,
{"CWMin tuning", "wlan_mgt.ie.atheros.capabilities.wme",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_WME,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_boost,
{"Boost", "wlan_mgt.ie.atheros.capabilities.boost",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_BOOST,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_advcap_cap,
{"Capabilities", "wlan_mgt.atheros.ie.advcap.cap",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_advcap_defkey,
{"Default key index", "wlan_mgt.atheros.ie.advcap.defkey",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_info,
{"Info", "wlan_mgt.atheros.ie.xr.info",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_base_bssid,
{"Base BSS Id", "wlan_mgt.atheros.ie.xr.base_bssid",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_xr_bssid,
{"XR BSS Id", "wlan_mgt.atheros.ie.xr.xr_bssid",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_xr_beacon,
{"XR Beacon Interval", "wlan_mgt.atheros.ie.xr.xr_beacon",
FT_UINT32, BASE_CUSTOM, CF_FUNC(beacon_interval_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_base_cap,
{"Base capabilities", "wlan_mgt.atheros.ie.xr.base_cap",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_xr_cap,
{"XR capabilities", "wlan_mgt.atheros.ie.xr.xr_cap",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_atheros_ie_data,
{"Atheros IE data", "wlan_mgt.atheros.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_aironet_ie_type,
{"Aironet IE type", "wlan_mgt.aironet.type",
FT_UINT8, BASE_DEC, VALS(aironet_ie_type_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_aironet_ie_dtpc,
{"Aironet IE CCX DTCP", "wlan_mgt.aironet.dtpc",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_aironet_ie_version,
{"Aironet IE CCX version", "wlan_mgt.aironet.version",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_aironet_ie_data,
{ "Aironet IE data", "wlan_mgt.aironet.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_qbss_version,
{"QBSS Version", "wlan_mgt.qbss.version",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qbss_scount,
{"Station Count", "wlan_mgt.qbss.scount",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qbss_cu,
{"Channel Utilization", "wlan_mgt.qbss.cu",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qbss_adc,
{"Available Admission Capabilities", "wlan_mgt.qbss.adc",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qbss2_cu,
{"Channel Utilization", "wlan_mgt.qbss2.cu",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qbss2_gl,
{"G.711 CU Quantum", "wlan_mgt.qbss2.glimit",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qbss2_cal,
{"Call Admission Limit", "wlan_mgt.qbss2.cal",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qbss2_scount,
{"Station Count", "wlan_mgt.qbss2.scount",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_aironet_ie_qos_reserved,
{"Aironet IE QoS reserved", "wlan_mgt.aironet.qos.reserved",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_aironet_ie_qos_paramset,
{"Aironet IE QoS paramset", "wlan_mgt.aironet.qos.paramset",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_aironet_ie_qos_val,
{"Aironet IE QoS valueset", "wlan_mgt.aironet.qos.val",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_aironet_ie_clientmfp,
{"Aironet IE Client MFP", "wlan_mgt.aironet.clientmfp",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01,
NULL, HFILL }},
{&hf_ieee80211_vs_nintendo_type,
{"Type", "wlan_mgt.vs.nintendo.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_vs_nintendo_type_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_vs_nintendo_length,
{"Length", "wlan_mgt.vs.nintendo.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vs_nintendo_servicelist,
{"Servicelist", "wlan_mgt.vs.nintendo.servicelist",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vs_nintendo_service,
{"Service", "wlan_mgt.vs.nintendo.service",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vs_nintendo_consoleid,
{"Console ID", "wlan_mgt.vs.nintendo.consoleid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vs_nintendo_unknown,
{"Unknown", "wlan_mgt.vs.nintendo.unknown",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vs_aruba_subtype,
{"Subtype", "wlan_mgt.vs.aruba.subtype",
FT_UINT8, BASE_DEC, VALS(ieee80211_vs_aruba_subtype_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_vs_aruba_apname,
{"AP Name", "wlan_mgt.vs.aruba.ap_name",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_vs_aruba_data,
{"Data", "wlan_mgt.vs.aruba.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tsinfo,
{"Traffic Stream (TS) Info", "wlan_mgt.ts_info",
FT_UINT24, BASE_HEX, NULL, 0,
"Traffic Stream (TS) Info field", HFILL }},
{&hf_ieee80211_tsinfo_type,
{"Traffic Type", "wlan_mgt.ts_info.type",
FT_UINT24, BASE_DEC, VALS(tsinfo_type), 0x000001,
"Traffic Stream (TS) Info Traffic Type", HFILL }},
{&hf_ieee80211_tsinfo_tsid,
{"Traffic Stream ID (TSID)", "wlan_mgt.ts_info.tsid",
FT_UINT24, BASE_DEC, NULL, 0x00001E,
"Traffic Stream ID (TSID) Info TSID", HFILL }},
{&hf_ieee80211_tsinfo_dir,
{"Direction", "wlan_mgt.ts_info.dir",
FT_UINT24, BASE_DEC, VALS(tsinfo_direction), 0x000060,
"Traffic Stream (TS) Info Direction", HFILL }},
{&hf_ieee80211_tsinfo_access,
{"Access Policy", "wlan_mgt.ts_info.dir",
FT_UINT24, BASE_DEC, VALS(tsinfo_access), 0x000180,
"Traffic Stream (TS) Info Access Policy", HFILL }},
{&hf_ieee80211_tsinfo_agg,
{"Aggregation", "wlan_mgt.ts_info.agg",
FT_UINT24, BASE_DEC, NULL, 0x000200,
"Traffic Stream (TS) Info Access Policy", HFILL }},
{&hf_ieee80211_tsinfo_apsd,
{"Automatic Power-Save Delivery (APSD)", "wlan_mgt.ts_info.apsd",
FT_UINT24, BASE_DEC, NULL, 0x000400,
"Traffic Stream (TS) Info Automatic Power-Save Delivery (APSD)", HFILL }},
{&hf_ieee80211_tsinfo_up,
{"User Priority", "wlan_mgt.ts_info.up",
FT_UINT24, BASE_DEC, VALS(qos_up), 0x003800,
"Traffic Stream (TS) Info User Priority", HFILL }},
{&hf_ieee80211_tsinfo_ack,
{"Ack Policy", "wlan_mgt.ts_info.ack",
FT_UINT24, BASE_DEC, VALS(ack_policy), 0x00C000,
"Traffic Stream (TS) Info Ack Policy", HFILL }},
{&hf_ieee80211_tsinfo_sched,
{"Schedule", "wlan_mgt.ts_info.sched",
FT_UINT24, BASE_DEC, NULL, 0x010000,
"Traffic Stream (TS) Info Schedule", HFILL }},
{&hf_ieee80211_tsinfo_rsv,
{"Reserved", "wlan_mgt.ts_info.rsv",
FT_UINT24, BASE_HEX, NULL, 0xFE0000,
"Must be Zero", HFILL }},
{&hf_ieee80211_tspec_nor_msdu,
{"Normal MSDU Size", "wlan_mgt.tspec.nor_msdu",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_max_msdu,
{"Maximum MSDU Size", "wlan_mgt.tspec.max_msdu",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_min_srv,
{"Minimum Service Interval", "wlan_mgt.tspec.min_srv",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_max_srv,
{"Maximum Service Interval", "wlan_mgt.tspec.max_srv",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_inact_int,
{"Inactivity Interval", "wlan_mgt.tspec.inact_int",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_susp_int,
{"Suspension Interval", "wlan_mgt.tspec.susp_int",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_srv_start,
{"Service Start Time", "wlan_mgt.tspec.srv_start",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_min_data,
{"Minimum Data Rate", "wlan_mgt.tspec.min_data",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_mean_data,
{"Mean Data Rate", "wlan_mgt.tspec.mean_data",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_peak_data,
{"Peak Data Rate", "wlan_mgt.tspec.peak_data",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_burst_size,
{"Burst Size", "wlan_mgt.tspec.burst_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_delay_bound,
{"Delay Bound", "wlan_mgt.tspec.delay_bound",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_min_phy,
{"Minimum PHY Rate", "wlan_mgt.tspec.min_phy",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_surplus,
{"Surplus Bandwidth Allowance", "wlan_mgt.tspec.surplus",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_medium,
{"Medium Time", "wlan_mgt.tspec.medium",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tspec_dmg,
{"DMG attributes", "wlan_mgt.tspec.dmg",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ts_delay,
{"Traffic Stream (TS) Delay", "wlan_mgt.ts_delay",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_process,
{"Processing", "wlan_mgt.tclas_proc.processing",
FT_UINT8, BASE_DEC, VALS(ieee80211_tclas_process_flag), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ext_supp_rates,
{"Extended Supported Rates", "wlan_mgt.extended_supported_rates",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ieee80211_supported_rates_vals_ext, 0x0,
"In Mbit/sec, (B) for Basic Rates", HFILL }},
{&hf_ieee80211_sched_info,
{"Schedule Info", "wlan_mgt.sched.sched_info",
FT_UINT16, BASE_HEX, NULL, 0,
"Schedule Info field", HFILL }},
{&hf_ieee80211_sched_info_agg,
{"Schedule Aggregation", "wlan_mgt.sched_info.agg",
FT_UINT16, BASE_DEC, NULL, 0x0001,
"Traffic Stream (TS) Info Access Policy", HFILL }},
{&hf_ieee80211_sched_info_tsid,
{"Schedule Traffic Stream ID (TSID)", "wlan_mgt.sched_info.tsid",
FT_UINT16, BASE_DEC, NULL, 0x001E,
"Traffic Stream ID (TSID) Info TSID", HFILL }},
{&hf_ieee80211_sched_info_dir,
{"Schedule Direction", "wlan_mgt.sched_info.dir",
FT_UINT16, BASE_DEC, VALS(tsinfo_direction), 0x0060,
"Traffic Stream (TS) Info Direction", HFILL }},
{&hf_ieee80211_sched_srv_start,
{"Service Start Time", "wlan_mgt.sched.srv_start",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_sched_srv_int,
{"Service Interval", "wlan_mgt.sched.srv_int",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_sched_spec_int,
{"Specification Interval", "wlan_mgt.sched.spec_int",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_aruba,
{"Aruba Type", "wlan_mgt.aruba.type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &aruba_mgt_typevals_ext, 0,
"Aruba Management", HFILL }},
{&hf_ieee80211_aruba_hb_seq,
{"Aruba Heartbeat Sequence", "wlan_mgt.aruba.heartbeat_sequence",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_aruba_mtu,
{"Aruba MTU Size", "wlan_mgt.aruba.mtu_size",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_htc,
{"HT Control (+HTC)", "wlan_mgt.htc",
FT_UINT32, BASE_HEX, NULL, 0,
"High Throughput Control (+HTC)", HFILL }},
{&hf_ieee80211_htc_vht,
{"VHT", "wlan_mgt.htc.lac.vht",
FT_BOOLEAN, 32, NULL, HTC_VHT,
"High Throughput Control HT/VHT flag", HFILL }},
{&hf_ieee80211_htc_lac,
{"Link Adaptation Control (LAC)", "wlan_mgt.htc.lac",
FT_UINT32, BASE_HEX, NULL, 0x0000FFFE,
"High Throughput Control Link Adaptation Control (LAC)", HFILL }},
{&hf_ieee80211_htc_lac_trq,
{"Training Request (TRQ)", "wlan_mgt.htc.lac.trq",
FT_BOOLEAN, 16, TFS(&htc_lac_trq_flag), 0x0002,
"High Throughput Control Link Adaptation Control Training Request (TRQ)", HFILL }},
{&hf_ieee80211_htc_lac_mai_aseli,
{"Antenna Selection Indication (ASELI)", "wlan_mgt.htc.lac.mai.aseli",
FT_UINT16, BASE_HEX, NULL, 0x003C,
"High Throughput Control Link Adaptation Control MAI Antenna Selection Indication", HFILL }},
{&hf_ieee80211_htc_lac_mai_mrq,
{"MCS Request (MRQ)", "wlan_mgt.htc.lac.mai.mrq",
FT_BOOLEAN, 16, TFS(&htc_lac_mai_mrq_flag), 0x0004,
"High Throughput Control Link Adaptation Control MAI MCS Request", HFILL }},
{&hf_ieee80211_htc_lac_mai_msi,
{"MCS Request Sequence Identifier (MSI)", "wlan_mgt.htc.lac.mai.msi",
FT_UINT16, BASE_HEX, NULL, 0x0038,
"High Throughput Control Link Adaptation Control MAI MCS Request Sequence Identifier", HFILL }},
{&hf_ieee80211_htc_lac_mai_reserved,
{"Reserved", "wlan_mgt.htc.lac.mai.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0038,
"High Throughput Control Link Adaptation Control MAI Reserved", HFILL }},
{&hf_ieee80211_htc_lac_mfsi,
{"MCS Feedback Sequence Identifier (MFSI)", "wlan_mgt.htc.lac.mfsi",
FT_UINT16, BASE_DEC, NULL, 0x01C0,
"High Throughput Control Link Adaptation Control MCS Feedback Sequence Identifier (MSI)", HFILL }},
{&hf_ieee80211_htc_lac_asel_command,
{"Antenna Selection (ASEL) Command", "wlan_mgt.htc.lac.asel.command",
FT_UINT16, BASE_HEX, VALS(ieee80211_htc_lac_asel_command_flags), 0x0E00,
"High Throughput Control Link Adaptation Control Antenna Selection (ASEL) Command", HFILL }},
{&hf_ieee80211_htc_lac_asel_data,
{"Antenna Selection (ASEL) Data", "wlan_mgt.htc.lac.asel.data",
FT_UINT16, BASE_HEX, NULL, 0xF000,
"High Throughput Control Link Adaptation Control Antenna Selection (ASEL) Data", HFILL }},
{&hf_ieee80211_htc_lac_mfb,
{"MCS Feedback (MFB)", "wlan_mgt.htc.lac.mfb",
FT_UINT16, BASE_HEX, NULL, 0xFE00,
"High Throughput Control Link Adaptation Control MCS Feedback", HFILL }},
{&hf_ieee80211_htc_cal_pos,
{"Calibration Position", "wlan_mgt.htc.cal.pos",
FT_UINT32, BASE_DEC, VALS(ieee80211_htc_cal_pos_flags), 0x00030000,
"High Throughput Control Calibration Position", HFILL }},
{&hf_ieee80211_htc_cal_seq,
{"Calibration Sequence Identifier", "wlan_mgt.htc.cal.seq",
FT_UINT32, BASE_DEC, NULL, 0x000C0000,
"High Throughput Control Calibration Sequence Identifier", HFILL }},
{&hf_ieee80211_htc_reserved1,
{"Reserved", "wlan_mgt.htc.reserved1",
FT_UINT32, BASE_HEX, NULL, 0x00300000,
"High Throughput Control Reserved", HFILL }},
{&hf_ieee80211_htc_csi_steering,
{"CSI/Steering", "wlan_mgt.htc.csi_steering",
FT_UINT32, BASE_DEC, VALS(ieee80211_htc_csi_steering_flags), 0x00C00000,
"High Throughput Control CSI/Steering", HFILL }},
{&hf_ieee80211_htc_ndp_announcement,
{"NDP Announcement", "wlan_mgt.htc.ndp_announcement",
FT_BOOLEAN, 32, TFS(&ieee80211_htc_ndp_announcement_flag), 0x01000000,
"High Throughput Control NDP Announcement", HFILL }},
{&hf_ieee80211_htc_reserved2,
{"Reserved", "wlan_mgt.htc.reserved2",
FT_UINT32, BASE_HEX, NULL, 0x3E000000,
"High Throughput Control Reserved", HFILL }},
{&hf_ieee80211_htc_mrq,
{"MRQ", "wlan_mgt.htc.mrq",
FT_BOOLEAN, 32, NULL, HTC_MRQ,
"VHT-MCS feedback request", HFILL }},
{&hf_ieee80211_htc_msi,
{"MSI", "wlan_mgt.htc.msi",
FT_UINT32, BASE_DEC, NULL, 0x00000038,
"MRQ sequence number", HFILL }},
{&hf_ieee80211_htc_msi_stbc_reserved,
{"Reserved", "wlan_mgt.htc.msi_stbc_reserved",
FT_UINT32, BASE_HEX, NULL, 0x00000038,
NULL, HFILL }},
{&hf_ieee80211_htc_compressed_msi,
{"Compressed MSI", "wlan_mgt.htc.compressed_msi",
FT_UINT32, BASE_DEC, NULL, 0x00000018,
NULL, HFILL }},
{&hf_ieee80211_htc_ppdu_stbc_encoded,
{"PPDU was STBC encoded", "wlan_mgt.htc.ppdu_stbc_encoded",
FT_BOOLEAN, 32, NULL, 0x00000020,
NULL, HFILL }},
{&hf_ieee80211_htc_mfsi,
{"MFSI", "wlan_mgt.htc.mfsi",
FT_BOOLEAN, 32, NULL, 0x000001C0,
"MFB sequence identifier", HFILL }},
{&hf_ieee80211_htc_gid_l,
{"GID-L", "wlan_mgt.htc.gid_l",
FT_BOOLEAN, 32, NULL, 0x000001C0,
"LSBs of group ID", HFILL }},
{&hf_ieee80211_htc_mfb,
{"MFB", "wlan_mgt.htc.mfb",
FT_UINT32, BASE_HEX, NULL, 0x00FFFE00,
"Recommended MFB", HFILL }},
{&hf_ieee80211_htc_num_sts,
{"NUM_STS", "wlan_mgt.htc.num_sts",
FT_UINT32, BASE_DEC, NULL, 0x00000E00,
"Recommended NUM_STS", HFILL }},
{&hf_ieee80211_htc_vht_mcs,
{"VHT-MCS", "wlan_mgt.htc.vht_mcs",
FT_UINT32, BASE_DEC, NULL, 0x0000F000,
"Recommended VHT-MCS", HFILL }},
{&hf_ieee80211_htc_bw,
{"BW", "wlan_mgt.htc.bw",
FT_UINT32, BASE_DEC, VALS(ieee80211_htc_bw_recommended_vht_mcs_vals), 0x00030000,
"Bandwidth for recommended VHT-MCS", HFILL }},
{&hf_ieee80211_htc_snr,
{"SNR", "wlan_mgt.htc.snr",
FT_INT32, BASE_DEC, NULL, 0x00FC0000,
"Average SNR + 22", HFILL }},
{&hf_ieee80211_htc_reserved3,
{"Reserved", "wlan_mgt.htc.reserved3",
FT_UINT32, BASE_HEX, NULL, 0x1F000000,
NULL, HFILL }},
{&hf_ieee80211_htc_gid_h,
{"GID-H", "wlan_mgt.htc.gid_h",
FT_UINT32, BASE_DEC, NULL, 0x07000000,
NULL, HFILL }},
{&hf_ieee80211_htc_coding_type,
{"Coding type", "wlan_mgt.htc.coding_type",
FT_UINT32, BASE_DEC, VALS(ieee80211_htc_coding_type_vals), 0x08000000,
NULL, HFILL }},
{&hf_ieee80211_htc_fb_tx_type,
{"FB Tx type", "wlan_mgt.htc.fb_tx_type",
FT_UINT32, BASE_DEC, VALS(ieee80211_htc_fb_tx_type_vals), 0x10000000,
NULL, HFILL }},
{&hf_ieee80211_htc_unsolicited_mfb,
{"Unsolicited MFB", "wlan_mgt.htc.unsolicited_mfb",
FT_BOOLEAN, 32, NULL, HTC_UNSOLICITED_MFB,
"High Throughput Control Unsolicited MFB", HFILL }},
{&hf_ieee80211_htc_ac_constraint,
{"AC Constraint", "wlan_mgt.htc.ac_constraint",
FT_BOOLEAN, 32, NULL, 0x40000000,
"High Throughput Control AC Constraint", HFILL }},
{&hf_ieee80211_htc_rdg_more_ppdu,
{"RDG/More PPDU", "wlan_mgt.htc.rdg_more_ppdu",
FT_BOOLEAN, 32, NULL, 0x80000000,
"High Throughput Control RDG/More PPDU", HFILL }},
{&hf_ieee80211_tag_mobility_domain_mdid,
{"Mobility Domain Identifier", "wlan_mgt.mobility_domain.mdid",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_mobility_domain_ft_capab,
{"FT Capability and Policy", "wlan_mgt.mobility_domain.ft_capab",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_mobility_domain_ft_capab_ft_over_ds,
{"Fast BSS Transition over DS",
"wlan_mgt.mobility_domain.ft_capab.ft_over_ds",
FT_UINT8, BASE_HEX, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_mobility_domain_ft_capab_resource_req,
{"Resource Request Protocol Capability",
"wlan_mgt.mobility_domain.ft_capab.resource_req",
FT_UINT8, BASE_HEX, NULL, 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_mic_control,
{"MIC Control", "wlan_mgt.ft.mic_control",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_element_count,
{"Element Count", "wlan_mgt.ft.element_count",
FT_UINT16, BASE_DEC, NULL, 0xff00,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_mic,
{"MIC", "wlan_mgt.ft.mic",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_anonce,
{"ANonce", "wlan_mgt.ft.anonce",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_snonce,
{"SNonce", "wlan_mgt.ft.snonce",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_id,
{"Subelement ID", "wlan_mgt.ft.subelem.id",
FT_UINT8, BASE_DEC, VALS(ft_subelem_id_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_len,
{"Length", "wlan_mgt.ft.subelem.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_data,
{"Data", "wlan_mgt.ft.subelem.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_r1kh_id,
{"PMK-R1 key holder identifier (R1KH-ID)", "wlan_mgt.ft.subelem.r1kh_id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_gtk_key_info,
{"Key Info", "wlan_mgt.ft.subelem.gtk.key_info",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_gtk_key_id,
{"Key ID", "wlan_mgt.ft.subelem.gtk.key_id",
FT_UINT16, BASE_DEC, NULL, 0x0003,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_gtk_key_length,
{"Key Length", "wlan_mgt.ft.subelem.gtk.key_length",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_gtk_rsc,
{"RSC", "wlan_mgt.ft.subelem.gtk.rsc",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_gtk_key,
{"GTK", "wlan_mgt.ft.subelem.gtk.key",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_r0kh_id,
{"PMK-R0 key holder identifier (R0KH-ID)", "wlan_mgt.ft.subelem.r0kh_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_igtk_key_id,
{"Key ID", "wlan_mgt.ft.subelem.igtk.key_id",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_igtk_ipn,
{"IPN", "wlan_mgt.ft.subelem.igtk.ipn",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_igtk_key_length,
{"Key Length", "wlan_mgt.ft.subelem.igtk.key_length",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_igtk_key,
{"Wrapped Key (IGTK)", "wlan_mgt.ft.subelem.igtk.key",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ric_data_id,
{"Resource Handshake Identifier", "wlan_mgt.ric_data.id",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ric_data_desc_cnt,
{"Resource Descriptor Count", "wlan_mgt.ric_data.desc_cnt",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ric_data_status_code,
{"Status Code", "wlan_mgt.ric_data.status_code",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &ieee80211_status_code_ext, 0,
"Status of requested Resource", HFILL }},
{&hf_ieee80211_tag_ric_desc_rsrc_type,
{"Resource Type", "wlan_mgt.ric_desc.rsrc_type",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ric_desc_var_params,
{"Variable Params", "wlan_mgt.ric_desc.var_params",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_mmie_keyid,
{"KeyID", "wlan_mgt.mmie.keyid",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_mmie_ipn,
{"IPN", "wlan_mgt.mmie.ipn",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_mmie_mic,
{"MIC", "wlan_mgt.mmie.mic",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_version,
{"Version", "wlan_mgt.wapi.version",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_akm_suite_count,
{"AKM Suite Count", "wlan_mgt.wapi.akm_suite.count",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_akm_suite_oui,
{"AKM Suite OUI", "wlan_mgt.wapi.akm_suite.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_akm_suite_type,
{"AKM Suite Type", "wlan_mgt.wapi.akm_suite.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_wapi_suite_type) , 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_ucast_cipher_suite_count,
{"Unicast Cipher Suite Count", "wlan_mgt.wapi.unicast_cipher.suite.count",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_ucast_cipher_suite_oui,
{"Unicast Cipher Suite OUI", "wlan_mgt.wapi.unicast_cipher.suite.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_ucast_cipher_suite_type,
{"Unicast Cipher Suite Type", "wlan_mgt.wapi.unicast_cipher.suite.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_wapi_cipher_type) , 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_mcast_cipher_suite_oui,
{"Multicast Cipher Suite OUI", "wlan_mgt.wapi.multicast_cipher.suite.oui",
FT_UINT24, BASE_CUSTOM, CF_FUNC(oui_base_custom), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_mcast_cipher_suite_type,
{"Multicast Cipher Suite Type", "wlan_mgt.wapi.multicast_cipher.suite.type",
FT_UINT8, BASE_DEC, VALS(ieee80211_wapi_cipher_type) , 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_capab,
{"WAPI Capability Info", "wlan_mgt.wapi.capab",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_capab_preauth,
{"Supports Preauthentication?", "wlan_mgt.wapi.capab.preauth",
FT_BOOLEAN, 16 , NULL, 0x0001,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_capab_rsvd,
{"Reserved", "wlan_mgt.wapi.capab.rsvd",
FT_UINT16, BASE_DEC , NULL, 0xFFFE,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_bkid_count,
{"No of BKID's", "wlan_mgt.wapi.bkid.count",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wapi_param_set_bkid_list,
{"BKID", "wlan_mgt.wapi.bkid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_bss_max_idle_period,
{"BSS Max Idle Period (1000 TUs)", "wlan_mgt.bss_max_idle.period",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_bss_max_idle_options_protected,
{"BSS Max Idle Period Options: Protected Keep-Alive Required",
"wlan_mgt.bss_max_idle.options.protected",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL }},
{&hf_ieee80211_tag_tfs_request_id,
{"TFS ID", "wlan_mgt.tfs_request.id",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_tfs_request_ac_delete_after_match,
{"TFS Action Code - Delete after match",
"wlan_mgt.tfs_request.action_code.delete_after_match",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL }},
{&hf_ieee80211_tag_tfs_request_ac_notify,
{"TFS Action Code - Notify",
"wlan_mgt.tfs_request.action_code.notify",
FT_UINT8, BASE_DEC, NULL, 0x02, NULL, HFILL }},
{&hf_ieee80211_tag_tfs_request_subelem_id,
{"Subelement ID", "wlan_mgt.tfs_request.subelem.id",
FT_UINT8, BASE_DEC, VALS(tfs_request_subelem_ids), 0,
"TFS Request Subelement ID", HFILL }},
{&hf_ieee80211_tag_tfs_request_subelem_len,
{"Length", "wlan_mgt.tfs_request.subelem.len",
FT_UINT8, BASE_DEC, NULL, 0,
"TFS Request Subelement Length", HFILL }},
{&hf_ieee80211_tag_tfs_request_subelem,
{"Subelement Data", "wlan_mgt.tfs_request.subelem",
FT_BYTES, BASE_NONE, NULL, 0,
"TFS Request Subelement Data", HFILL }},
{&hf_ieee80211_tag_tfs_response_subelem_id,
{"Subelement ID", "wlan_mgt.tfs_response.subelem.id",
FT_UINT8, BASE_DEC, VALS(tfs_response_subelem_ids), 0,
"TFS Response Subelement ID", HFILL }},
{&hf_ieee80211_tag_tfs_response_subelem_len,
{"Length", "wlan_mgt.tfs_response.subelem.len",
FT_UINT8, BASE_DEC, NULL, 0,
"TFS Response Subelement Length", HFILL }},
{&hf_ieee80211_tag_tfs_response_subelem,
{"Subelement Data", "wlan_mgt.tfs_response.subelem",
FT_BYTES, BASE_NONE, NULL, 0,
"TFS Response Subelement Data", HFILL }},
{&hf_ieee80211_tag_tfs_response_status,
{"TFS Response Status", "wlan_mgt.tfs_response.status",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_tfs_response_id,
{"TFS ID", "wlan_mgt.tfs_response.tfs_id",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_wnm_sleep_mode_action_type,
{"Action Type", "wlan_mgt.wnm_sleep_mode.action_type",
FT_UINT8, BASE_DEC, VALS(wnm_sleep_mode_action_types), 0,
"WNM-Sleep Mode Action Type", HFILL }},
{&hf_ieee80211_tag_wnm_sleep_mode_response_status,
{"WNM-Sleep Mode Response Status",
"wlan_mgt.wnm_sleep_mode.response_status",
FT_UINT8, BASE_DEC, VALS(wnm_sleep_mode_response_status_vals), 0, NULL,
HFILL }},
{&hf_ieee80211_tag_wnm_sleep_mode_interval,
{"WNM-Sleep Interval", "wlan_mgt.wnm_sleep_mode.interval",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_timing_capab,
{"Timing capabilities", "wlan_mgt.time_adv.timing_capab",
FT_UINT8, BASE_DEC, VALS(time_adv_timing_capab_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value,
{"Time Value", "wlan_mgt.time_adv.time_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_year,
{"Time Value: Year", "wlan_mgt.time_adv.time_value.year",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_month,
{"Time Value: Month", "wlan_mgt.time_adv.time_value.month",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_day,
{"Time Value: Day", "wlan_mgt.time_adv.time_value.month",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_hours,
{"Time Value: Hours", "wlan_mgt.time_adv.time_value.hours",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_minutes,
{"Time Value: Minutes", "wlan_mgt.time_adv.time_value.minutes",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_seconds,
{"Time Value: Seconds", "wlan_mgt.time_adv.time_value.seconds",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_milliseconds,
{"Time Value: Milliseconds", "wlan_mgt.time_adv.time_value.milliseconds",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_reserved,
{"Time Value: Reserved", "wlan_mgt.time_adv.time_value.reserved",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_error,
{"Time Error", "wlan_mgt.time_adv.time_error",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_update_counter,
{"Time Update Counter", "wlan_mgt.time_adv.time_update_counter",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_time_zone,
{"Time Zone", "wlan_mgt.time_zone",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_interworking_access_network_type,
{"Access Network Type", "wlan_mgt.interworking.access_network_type",
FT_UINT8, BASE_DEC, VALS(access_network_type_vals), 0x0f,
NULL, HFILL }},
{&hf_ieee80211_tag_interworking_internet,
{"Internet", "wlan_mgt.interworking.internet",
FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL }},
{&hf_ieee80211_tag_interworking_asra,
{"ASRA", "wlan_mgt.interworking.asra",
FT_UINT8, BASE_DEC, NULL, 0x20,
"Additional Step Required for Access", HFILL }},
{&hf_ieee80211_tag_interworking_esr,
{"ESR", "wlan_mgt.interworking.esr",
FT_UINT8, BASE_DEC, NULL, 0x40,
"Emergency services reachable", HFILL }},
{&hf_ieee80211_tag_interworking_uesa,
{"UESA", "wlan_mgt.interworking.uesa",
FT_UINT8, BASE_DEC, NULL, 0x80,
"Unauthenticated emergency service accessible", HFILL }},
{&hf_ieee80211_tag_interworking_hessid,
{"HESSID", "wlan_mgt.interworking.hessid",
FT_ETHER, BASE_NONE, NULL, 0,
"Homogeneous ESS identifier", HFILL }},
{&hf_ieee80211_tag_qos_map_set_dscp_exc,
{"DSCP Exception", "wlan_mgt.qos_map_set.dscp_exception",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_qos_map_set_dscp_exc_val,
{"DSCP Value", "wlan_mgt.qos_map_set.dscp_value",
FT_UINT8, BASE_DEC, NULL, 0,
"DSCP Exception - DSCP Value", HFILL }},
{&hf_ieee80211_tag_qos_map_set_dscp_exc_up,
{"User Priority", "wlan_mgt.qos_map_set.up",
FT_UINT8, BASE_DEC, NULL, 0,
"DSCP Exception - User Priority", HFILL }},
{&hf_ieee80211_tag_qos_map_set_range,
{"DSCP Range description", "wlan_mgt.qos_map_set.range",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_qos_map_set_low,
{"DSCP Low Value", "wlan_mgt.qos_map_set.dscp_low_value",
FT_UINT8, BASE_DEC, NULL, 0,
"DSCP Range description - DSCP Low Value", HFILL }},
{&hf_ieee80211_tag_qos_map_set_high,
{"DSCP High Value", "wlan_mgt.qos_map_set.dscp_high_value",
FT_UINT8, BASE_DEC, NULL, 0,
"DSCP Range description - DSCP High Value", HFILL }},
{&hf_ieee80211_tag_adv_proto_resp_len_limit,
{"Query Response Length Limit", "wlan_mgt.adv_proto.resp_len_limit",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }},
{&hf_ieee80211_tag_adv_proto_pame_bi,
{"PAME-BI", "wlan_mgt.adv_proto.pame_bi",
FT_UINT8, BASE_DEC, NULL, 0x80,
"Pre-Association Message Xchange BSSID Independent (PAME-BI)", HFILL }},
{&hf_ieee80211_tag_adv_proto_id,
{"Advertisement Protocol ID", "wlan_mgt.adv_proto.id",
FT_UINT8, BASE_DEC, VALS(adv_proto_id_vals), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_adv_proto_vs_info,
{"Advertisement Protocol Vendor Specific info", "wlan_mgt.adv_proto.vs_info",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_num_anqp_oi,
{"Number of ANQP OIs", "wlan_mgt.roaming_consortium.num_anqp_oi",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_oi1_len,
{"OI #1 Length", "wlan_mgt.roaming_consortium.oi1_len",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_oi2_len,
{"OI #2 Length", "wlan_mgt.roaming_consortium.oi2_len",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_oi1,
{"OI #1", "wlan_mgt.roaming_consortium.oi1",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_oi2,
{"OI #2", "wlan_mgt.roaming_consortium.oi2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_oi3,
{"OI #3", "wlan_mgt.roaming_consortium.oi3",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_timeout_int_type,
{"Timeout Interval Type", "wlan_mgt.timeout_int.type",
FT_UINT8, BASE_DEC, VALS(timeout_int_types), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_timeout_int_value,
{"Timeout Interval Value", "wlan_mgt.timeout_int.value",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_link_id_bssid,
{"BSSID", "wlan_mgt.link_id.bssid",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_link_id_init_sta,
{"TDLS initiator STA Address", "wlan_mgt.link_id.init_sta",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_link_id_resp_sta,
{"TDLS responder STA Address", "wlan_mgt.link_id.resp_sta",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wakeup_schedule_offset,
{"Offset", "wlan_mgt.wakeup_schedule.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wakeup_schedule_interval,
{"Interval", "wlan_mgt.wakeup_schedule.interval",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wakeup_schedule_awake_window_slots,
{"Awake Window Slots", "wlan_mgt.wakeup_schedule.awake_window_slots",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wakeup_schedule_max_awake_dur,
{"Maximum Awake Window Duration", "wlan_mgt.wakeup_schedule.max_awake_dur",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_wakeup_schedule_idle_count,
{"Idle Count", "wlan_mgt.wakeup_schedule.idle_count",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_channel_switch_timing_switch_time,
{"Switch Time", "wlan_mgt.channel_switch_timing.switch_time",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_channel_switch_timing_switch_timeout,
{"Switch Timeout", "wlan_mgt.channel_switch_timing.switch_timeout",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_pti_control_tid,
{"TID", "wlan_mgt.pti_control.tid",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_pti_control_sequence_control,
{"Sequence Control", "wlan_mgt.pti_control.sequence_control",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_pu_buffer_status_ac_bk,
{"AC_BK traffic available", "wlan_mgt.pu_buffer_status.ac_bk",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }},
{&hf_ieee80211_tag_pu_buffer_status_ac_be,
{"AC_BE traffic available", "wlan_mgt.pu_buffer_status.ac_be",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL }},
{&hf_ieee80211_tag_pu_buffer_status_ac_vi,
{"AC_VI traffic available", "wlan_mgt.pu_buffer_status.ac_vi",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }},
{&hf_ieee80211_tag_pu_buffer_status_ac_vo,
{"AC_VO traffic available", "wlan_mgt.pu_buffer_status.ac_vo",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }},
{&hf_ieee80211_mysterious_olpc_stuff,
{"Mysterious OLPC stuff", "wlan_mgt.mysterious_olpc_stuff",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }}
};
static hf_register_info aggregate_fields[] = {
{&hf_ieee80211_amsdu_subframe,
{"A-MSDU Subframe", "wlan_aggregate.a_mdsu.subframe",
FT_NONE, BASE_NONE, NULL, 0x0,
"Aggregate MAC Service Data Unit (MSDU) Subframe", HFILL }},
{&hf_ieee80211_amsdu_length,
{"A-MSDU Length", "wlan_aggregate.a_mdsu.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }}
};
static uat_field_t wep_uat_flds[] = {
UAT_FLD_VS(uat_wep_key_records, key, "Key type", wep_type_vals,
"Decryption key type used"),
UAT_FLD_CSTRING(uat_wep_key_records, string, "Key",
"wep:<wep hexadecimal key>\n"
"wpa-pwd:<passphrase>[:<ssid>]\n"
"wpa-psk:<wpa hexadecimal key>"),
UAT_END_FIELDS
};
static gint *tree_array[] = {
&ett_80211,
&ett_proto_flags,
&ett_cap_tree,
&ett_fc_tree,
&ett_cntrl_wrapper_fc,
&ett_cntrl_wrapper_payload,
&ett_fragments,
&ett_fragment,
&ett_block_ack,
&ett_block_ack_bitmap,
&ett_ath_cap_tree,
&ett_80211_mgt,
&ett_fixed_parameters,
&ett_tagged_parameters,
&ett_tag_bmapctl_tree,
&ett_tag_country_fnm_tree,
&ett_tag_country_rcc_tree,
&ett_qos_parameters,
&ett_qos_ps_buf_state,
&ett_wep_parameters,
&ett_msh_control,
&ett_hwmp_targ_flags_tree,
&ett_mesh_chswitch_flag_tree,
&ett_mesh_config_cap_tree,
&ett_mesh_formation_info_tree,
&ett_rsn_gcs_tree,
&ett_rsn_pcs_tree,
&ett_rsn_sub_pcs_tree,
&ett_rsn_akms_tree,
&ett_rsn_sub_akms_tree,
&ett_rsn_cap_tree,
&ett_rsn_pmkid_tree,
&ett_rsn_gmcs_tree,
&ett_wpa_mcs_tree,
&ett_wpa_ucs_tree,
&ett_wpa_sub_ucs_tree,
&ett_wpa_akms_tree,
&ett_wpa_sub_akms_tree,
&ett_wme_ac,
&ett_wme_aci_aifsn,
&ett_wme_ecw,
&ett_wme_qos_info,
&ett_ht_cap_tree,
&ett_ampduparam_tree,
&ett_mcsset_tree,
&ett_mcsbit_tree,
&ett_htex_cap_tree,
&ett_txbf_tree,
&ett_antsel_tree,
&ett_hta_cap_tree,
&ett_hta_cap1_tree,
&ett_hta_cap2_tree,
&ett_htc_tree,
&ett_mfb_subtree,
&ett_lac_subtree,
&ett_vht_cap_tree,
&ett_vht_mcsset_tree,
&ett_vht_rx_mcsbit_tree,
&ett_vht_tx_mcsbit_tree,
&ett_vht_basic_mcsbit_tree,
&ett_vht_op_tree,
&ett_vht_tpe_info_tree,
&ett_vht_ndp_annc_token_tree,
&ett_vht_ndp_annc_sta_info_tree,
&ett_ff_vhtmimo_cntrl,
&ett_ff_vhtmimo_beamforming_report,
&ett_ff_vhtmimo_beamforming_report_snr,
&ett_ff_vhtmimo_beamforming_report_feedback_matrices,
&ett_vht_grpidmgmt,
&ett_ht_info_delimiter1_tree,
&ett_ht_info_delimiter2_tree,
&ett_ht_info_delimiter3_tree,
&ett_tag_measure_request_mode_tree,
&ett_tag_measure_request_type_tree,
&ett_tag_measure_report_mode_tree,
&ett_tag_measure_report_type_tree,
&ett_tag_measure_report_basic_map_tree,
&ett_tag_measure_report_rpi_tree,
&ett_tag_measure_report_frame_tree,
&ett_tag_measure_reported_frame_tree,
&ett_tag_bss_bitmask_tree,
&ett_tag_dfs_map_tree,
&ett_tag_erp_info_tree,
&ett_tag_ex_cap1,
&ett_tag_ex_cap2,
&ett_tag_ex_cap3,
&ett_tag_ex_cap4,
&ett_tag_ex_cap5,
&ett_tag_ex_cap6,
&ett_tag_ex_cap7,
&ett_tag_ex_cap8,
&ett_tag_ex_cap9,
&ett_tag_rm_cap1,
&ett_tag_rm_cap2,
&ett_tag_rm_cap3,
&ett_tag_rm_cap4,
&ett_tag_rm_cap5,
&ett_tag_tclas_mask_tree,
&ett_tag_supported_channels,
&ett_tag_neighbor_report_bssid_info_tree,
&ett_tag_neighbor_report_bssid_info_capability_tree,
&ett_tag_neighbor_report_sub_tag_tree,
&ett_tag_wapi_param_set_akm_tree,
&ett_tag_wapi_param_set_ucast_tree,
&ett_tag_wapi_param_set_mcast_tree,
&ett_tag_wapi_param_set_preauth_tree,
&ett_tag_time_adv_tree,
&ett_ff_ba_param_tree,
&ett_ff_ba_ssc_tree,
&ett_ff_delba_param_tree,
&ett_ff_qos_info,
&ett_ff_psmp_param_set,
&ett_ff_mimo_cntrl,
&ett_ff_ant_sel,
&ett_mimo_report,
&ett_ff_sm_pwr_save,
&ett_ff_chan_switch_announce,
&ett_ff_ht_info,
&ett_ff_psmp_sta_info,
&ett_tpc,
&ett_msdu_aggregation_parent_tree,
&ett_msdu_aggregation_subframe_tree,
&ett_80211_mgt_ie,
&ett_tsinfo_tree,
&ett_sched_tree,
&ett_fcs,
&ett_adv_proto,
&ett_adv_proto_tuple,
&ett_gas_query,
&ett_gas_anqp,
&ett_nai_realm,
&ett_nai_realm_eap,
&ett_tag_ric_data_desc_ie,
&ett_anqp_vendor_capab,
&ett_hs20_cc_proto_port_tuple,
&ett_ssid_list,
&ett_nintendo,
&ett_qos_map_set_exception,
&ett_qos_map_set_range,
&ett_dynamic_alloc_tree,
&ett_ssw_tree,
&ett_bf_tree,
&ett_sswf_tree,
&ett_brp_tree,
&ett_blm_tree,
&ett_bic_tree,
&ett_dmg_params_tree,
&ett_cc_tree,
&ett_rcsi_tree,
&ett_80211_ext,
&ett_allocation_tree,
&ett_sta_info,
&ett_gas_resp_fragment,
&ett_gas_resp_fragments
};
static ei_register_info ei[] = {
{ &ei_ieee80211_bad_length,
{ "ieee80211.bad_length", PI_MALFORMED, PI_ERROR,
"Wrong length indicated", EXPFILL }},
{ &ei_ieee80211_inv_val,
{ "ieee80211.invalid_value", PI_MALFORMED, PI_WARN,
"Invalid value", EXPFILL }},
{ &ei_ieee80211_tag_number, { "wlan_mgt.tag.number.unexpected_ie", PI_MALFORMED, PI_ERROR, "Unexpected IE (expected Advertisement Protocol)", EXPFILL }},
{ &ei_ieee80211_tag_length, { "wlan_mgt.tag.length.bad", PI_MALFORMED, PI_ERROR, "Bad tag length", EXPFILL }},
{ &ei_ieee80211_extra_data, { "ieee80211.extra_data", PI_MALFORMED, PI_WARN, "Unexpected extra data in the end", EXPFILL }},
{ &ei_ieee80211_ff_anqp_capability, { "wlan_mgt.fixed.anqp.capability.invalid", PI_MALFORMED, PI_ERROR, "Invalid vendor-specific ANQP capability", EXPFILL }},
{ &ei_ieee80211_ff_anqp_venue_length, { "wlan_mgt.fixed.anqp.venue.length.invalid", PI_MALFORMED, PI_ERROR, "Invalid Venue Name Duple length", EXPFILL }},
{ &ei_ieee80211_ff_anqp_roaming_consortium_oi_len, { "wlan_mgt.fixed.anqp.roaming_consortium.oi_len.invalid", PI_MALFORMED, PI_ERROR, "Invalid Roaming Consortium OI", EXPFILL }},
{ &ei_ieee80211_ff_anqp_nai_field_len, { "wlan_mgt.fixed.anqp.nai_realm_list.field_len.invalid", PI_MALFORMED, PI_ERROR, "Invalid NAI Realm List", EXPFILL }},
{ &ei_ieee80211_ff_anqp_nai_realm_eap_len, { "wlan_mgt.fixed.naqp_nai_realm_list.eap_method_len.invalid", PI_MALFORMED, PI_ERROR, "Invalid EAP Method subfield", EXPFILL }},
{ &ei_hs20_anqp_ofn_length, { "wlan_mgt.hs20.anqp.ofn.length.invalid", PI_MALFORMED, PI_ERROR, "Invalid Operator Friendly Name Duple length", EXPFILL }},
{ &ei_hs20_anqp_nai_hrq_length, { "wlan_mgt.hs20.anqp.nai_hrq.length.invalid", PI_MALFORMED, PI_ERROR, "Invalid NAI Home Realm Query length", EXPFILL }},
{ &ei_ieee80211_ff_anqp_info_length, { "wlan_mgt.fixed.anqp.info_length.invalid", PI_MALFORMED, PI_ERROR, "Invalid ANQP Info length", EXPFILL }},
{ &ei_ieee80211_not_enough_room_for_anqp_header, { "wlan_mgt.fixed.query_length_invalid", PI_MALFORMED, PI_ERROR, "Not enough room for ANQP header", EXPFILL }},
{ &ei_ieee80211_ff_query_request_length, { "wlan_mgt.fixed.query_request_length.invalid", PI_MALFORMED, PI_ERROR, "Invalid Query Request Length", EXPFILL }},
{ &ei_ieee80211_ff_query_response_length, { "wlan_mgt.fixed.query_response_length.invalid", PI_MALFORMED, PI_ERROR, "Invalid Query Response Length", EXPFILL }},
{ &ei_ieee80211_tag_wnm_sleep_mode_no_key_data, { "wlan_mgt.wnm_sleep_mode.no_key_data", PI_MALFORMED, PI_ERROR, "WNM-Sleep Mode Response is not long enough to include Key Data", EXPFILL }},
{ &ei_ieee80211_tdls_setup_response_malformed, { "wlan_mgt.tdls_setup_response_malformed", PI_MALFORMED, PI_ERROR, "TDLS Setup Response (success) does not include mandatory fields", EXPFILL }},
{ &ei_ieee80211_tdls_setup_confirm_malformed, { "wlan_mgt.tdls_setup_confirm_malformed", PI_MALFORMED, PI_ERROR, "TDLS Setup Confirm (success) does not include mandatory fields", EXPFILL }},
{ &ei_ieee80211_wfa_ie_wme_qos_info_bad_ftype, { "wlan_mgt.wfa.ie.wme.qos_info.bad_ftype", PI_UNDECODED, PI_WARN, "Could not deduce direction to decode correctly", EXPFILL }},
{ &ei_ieee80211_qos_info_bad_ftype, { "wlan_mgt.qos_info.bad_ftype", PI_UNDECODED, PI_WARN, "Could not deduce direction to decode correctly", EXPFILL }},
{ &ei_ieee80211_rsn_pcs_count, { "wlan_mgt.rsn.pcs.count.invalid", PI_MALFORMED, PI_ERROR, "Pairwise Cipher Suite Count too large", EXPFILL }},
{ &ei_ieee80211_rsn_pmkid_count, { "wlan_mgt.rsn.akms.count.invalid", PI_MALFORMED, PI_ERROR, "Auth Key Management (AKM) Suite Count too large", EXPFILL }},
{ &ei_ieee80211_pmkid_count_too_large, { "wlan_mgt.rsn.pmkid.count.invalid", PI_MALFORMED, PI_ERROR, "PMKID Count too large", EXPFILL }},
{ &ei_ieee80211_vht_tpe_pwr_info_count, { "wlan_mgt.vht.tpe.pwr_info.count.invalid", PI_MALFORMED, PI_ERROR, "Max Tx Pwr Count is Incorrect, should be 0-7", EXPFILL }},
{ &ei_ieee80211_missing_data, { "ieee80211.missing_data", PI_MALFORMED, PI_WARN, "No TFS Request subelements in TFS Request", EXPFILL }},
{ &ei_ieee80211_fc_retry, { "wlan.fc.retry.expert", PI_SEQUENCE, PI_NOTE, "Retransmission (retry)", EXPFILL }},
{ &ei_ieee80211_tag_measure_request_unknown, { "wlan_mgt.measure.req.unknown.expert", PI_UNDECODED, PI_WARN, "Undecoded Measurement Request type (or subtype), Contact Wireshark developers if you want this supported", EXPFILL }},
{ &ei_ieee80211_tag_measure_request_beacon_unknown, { "wlan_mgt.measure.req.beacon.unknown.expert", PI_UNDECODED, PI_WARN, "Unknown Data (not interpreted)", EXPFILL }},
{ &ei_ieee80211_tag_measure_report_unknown, { "wlan_mgt.measure.req.unknown.expert", PI_UNDECODED, PI_WARN, "Undecoded Measurement Report type (or subtype), Contact Wireshark developers if you want this supported", EXPFILL }},
{ &ei_ieee80211_tag_data, { "wlan_mgt.tag.data.undecoded", PI_UNDECODED, PI_NOTE, "Dissector for 802.11 IE Tag code not implemented, Contact Wireshark developers if you want this supported", EXPFILL }},
{ &ei_ieee80211_dmg_subtype, { "wlan.dmg_subtype.bad", PI_MALFORMED, PI_ERROR, "Bad DMG type/subtype", EXPFILL }},
{ &ei_ieee80211_vht_action, { "wlan_mgt.vht.action.undecoded", PI_UNDECODED, PI_NOTE, "All subtype of VHT Action is not yet supported by Wireshark", EXPFILL }},
{ &ei_ieee80211_mesh_peering_unexpected, { "wlan.peering.unexpected", PI_MALFORMED, PI_ERROR, "Unexpected Self-protected action", EXPFILL }},
};
expert_module_t *expert_ieee80211;
module_t *wlan_module;
const unsigned char bssid_broadcast_data[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
memset(&wlan_stats, 0, sizeof wlan_stats);
proto_aggregate = proto_register_protocol("IEEE 802.11 wireless LAN aggregate frame",
"IEEE 802.11 Aggregate Data", "wlan_aggregate");
proto_register_field_array(proto_aggregate, aggregate_fields, array_length(aggregate_fields));
proto_wlan = proto_register_protocol("IEEE 802.11 wireless LAN", "IEEE 802.11", "wlan");
proto_centrino = proto_register_protocol("IEEE 802.11 wireless LAN (Centrino)", "IEEE 802.11 (Centrino)", "wlan_centrino");
proto_register_field_array(proto_wlan, hf, array_length (hf));
proto_wlan_mgt = proto_register_protocol("IEEE 802.11 wireless LAN management frame",
"IEEE 802.11 MGT", "wlan_mgt");
proto_register_field_array (proto_wlan_mgt, ff, array_length (ff));
proto_wlan_ext = proto_register_protocol ("IEEE 802.11 wireless LAN extension frame",
"IEEE 802.11 EXT", "wlan_ext");
proto_register_subtree_array (tree_array, array_length (tree_array));
expert_ieee80211 = expert_register_protocol(proto_wlan);
expert_register_field_array(expert_ieee80211, ei, array_length(ei));
new_register_dissector("wlan", dissect_ieee80211, proto_wlan);
register_dissector("wlan_withfcs", dissect_ieee80211_withfcs, proto_wlan);
register_dissector("wlan_withoutfcs", dissect_ieee80211_withoutfcs, proto_wlan);
register_dissector("wlan_bsfc", dissect_ieee80211_bsfc, proto_wlan);
register_init_routine(wlan_defragment_init);
register_cleanup_routine(wlan_defragment_cleanup);
register_init_routine(wlan_retransmit_init);
register_init_routine(ieee80211_gas_reassembly_init);
wlan_tap = register_tap("wlan");
register_conversation_table(proto_wlan, TRUE, wlan_conversation_packet, wlan_hostlist_packet);
wlan_address_type = address_type_dissector_register("AT_ETHER_WLAN", "WLAN Address", ether_to_str, ether_str_len, wlan_col_filter_str,
ether_len, ether_name_resolution_str, ether_name_resolution_len);
wlan_bssid_address_type = address_type_dissector_register("AT_ETHER_BSSID", "WLAN BSSID Address", ether_to_str, ether_str_len, wlan_bssid_col_filter_str,
ether_len, ether_name_resolution_str, ether_name_resolution_len);
set_address(&bssid_broadcast, wlan_bssid_address_type, 6, bssid_broadcast_data);
wlan_module = prefs_register_protocol(proto_wlan, init_wepkeys);
prefs_register_bool_preference(wlan_module, "defragment",
"Reassemble fragmented 802.11 datagrams",
"Whether fragmented 802.11 datagrams should be reassembled",
&wlan_defragment);
prefs_register_bool_preference(wlan_module, "ignore_draft_ht",
"Ignore vendor-specific HT elements",
"Don't dissect 802.11n draft HT elements (which might contain duplicate information).",
&wlan_ignore_draft_ht);
prefs_register_bool_preference(wlan_module, "retransmitted",
"Call subdissector for retransmitted 802.11 frames",
"Whether retransmitted 802.11 frames should be subdissected",
&wlan_subdissector);
prefs_register_bool_preference(wlan_module, "check_fcs",
"Assume packets have FCS",
"Some 802.11 cards include the FCS at the end of a packet, others do not.",
&wlan_check_fcs);
prefs_register_bool_preference(wlan_module, "check_checksum",
"Validate the FCS checksum if possible",
"Whether to validate the FCS checksum or not.",
&wlan_check_checksum);
prefs_register_enum_preference(wlan_module, "ignore_wep",
"Ignore the Protection bit",
"Some 802.11 cards leave the Protection bit set even though the packet is decrypted, "
"and some also leave the IV (initialization vector).",
&wlan_ignore_wep, wlan_ignore_wep_options, TRUE);
prefs_register_obsolete_preference(wlan_module, "wep_keys");
prefs_register_bool_preference(wlan_module, "enable_decryption",
"Enable decryption", "Enable WEP and WPA/WPA2 decryption",
&enable_decryption);
prefs_register_static_text_preference(wlan_module, "info_decryption_key",
"Key examples: 01:02:03:04:05 (40/64-bit WEP),\n"
"010203040506070809101111213 (104/128-bit WEP),\n"
"MyPassword[:MyAP] (WPA + plaintext password [+ SSID]),\n"
"0102030405...6061626364 (WPA + 256-bit key). "
"Invalid keys will be ignored.",
"Valid key formats");
wep_uat = uat_new("WEP and WPA Decryption Keys",
sizeof(uat_wep_key_record_t),
"80211_keys",
TRUE,
&uat_wep_key_records,
&num_wepkeys_uat,
UAT_AFFECTS_DISSECTION,
NULL,
uat_wep_key_record_copy_cb,
uat_wep_key_record_update_cb,
uat_wep_key_record_free_cb,
init_wepkeys,
wep_uat_flds);
prefs_register_uat_preference(wlan_module,
"wep_key_table",
"Decryption Keys",
"WEP and pre-shared WPA keys",
wep_uat);
}
void
proto_register_wlan_rsna_eapol (void)
{
static hf_register_info hf[] = {
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo,
{"Key Information", "wlan_rsna_eapol.keydes.key_info",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_keydes_version,
{"Key Descriptor Version", "wlan_rsna_eapol.keydes.key_info.keydes_version",
FT_UINT16, BASE_DEC, VALS(keydes_version_vals), KEY_INFO_KEYDES_VERSION_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_key_type,
{"Key Type", "wlan_rsna_eapol.keydes.key_info.key_type",
FT_BOOLEAN, 16, TFS(&keyinfo_key_type_tfs), KEY_INFO_KEY_TYPE_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_key_index,
{"Key Index", "wlan_rsna_eapol.keydes.key_info.key_index",
FT_UINT16, BASE_DEC, NULL, KEY_INFO_KEY_INDEX_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_install,
{"Install", "wlan_rsna_eapol.keydes.key_info.install",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_INSTALL_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_key_ack,
{"Key ACK", "wlan_rsna_eapol.keydes.key_info.key_ack",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_KEY_ACK_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_key_mic,
{"Key MIC", "wlan_rsna_eapol.keydes.key_info.key_mic",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_KEY_MIC_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_secure,
{"Secure", "wlan_rsna_eapol.keydes.key_info.secure",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_SECURE_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_error,
{"Error", "wlan_rsna_eapol.keydes.key_info.error",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_ERROR_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_request,
{"Request", "wlan_rsna_eapol.keydes.key_info.request",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_REQUEST_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_encrypted_key_data,
{"Encrypted Key Data", "wlan_rsna_eapol.keydes.key_info.encrypted_key_data",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_ENCRYPTED_KEY_DATA_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_keyinfo_smk_message,
{"SMK Message", "wlan_rsna_eapol.keydes.key_info.smk_message",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_ENCRYPTED_KEY_DATA_MASK,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_keydes_key_len,
{"Key Length", "eapol.keydes.key_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_keydes_replay_counter,
{"Replay Counter", "eapol.keydes.replay_counter",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_keydes_key_iv,
{"Key IV", "eapol.keydes.key_iv",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_nonce,
{"WPA Key Nonce", "wlan_rsna_eapol.keydes.nonce",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_rsc,
{"WPA Key RSC", "wlan_rsna_eapol.keydes.rsc",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_id,
{"WPA Key ID", "wlan_rsna_eapol.keydes.id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_mic,
{"WPA Key MIC", "wlan_rsna_eapol.keydes.mic",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_data_len,
{"WPA Key Data Length", "wlan_rsna_eapol.keydes.data_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_wlan_rsna_eapol_wpa_keydes_data,
{"WPA Key Data", "wlan_rsna_eapol.keydes.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *tree_array[] = {
&ett_keyinfo,
&ett_wlan_rsna_eapol_keydes_data,
};
proto_wlan_rsna_eapol = proto_register_protocol("IEEE 802.11 RSNA EAPOL key",
"802.11 RSNA EAPOL", "wlan_rsna_eapol");
proto_register_field_array(proto_wlan_rsna_eapol, hf, array_length (hf));
proto_register_subtree_array (tree_array, array_length (tree_array));
}
void
proto_reg_handoff_ieee80211(void)
{
dissector_handle_t data_encap_handle, centrino_handle;
dissector_handle_t wlan_rsna_eapol_wpa_key_handle, wlan_rsna_eapol_rsn_key_handle, wlan_withoutfcs_handle;
llc_handle = find_dissector("llc");
ipx_handle = find_dissector("ipx");
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
data_handle = find_dissector("data");
ieee80211_handle = find_dissector("wlan");
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11, ieee80211_handle);
centrino_handle = create_dissector_handle( dissect_ieee80211_centrino, proto_centrino );
dissector_add_uint("ethertype", ETHERTYPE_CENTRINO_PROMISC, centrino_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8200, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8210, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8220, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8230, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8240, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8250, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8260, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8270, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8280, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8290, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_82A0, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_82B0, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_82C0, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_82D0, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_82E0, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_82F0, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8300, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8310, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8320, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8330, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8340, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8350, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8360, ieee80211_handle);
dissector_add_uint("gre.proto", GRE_ARUBA_8370, ieee80211_handle);
data_encap_handle = create_dissector_handle(dissect_data_encap, proto_wlan);
dissector_add_uint("ethertype", ETHERTYPE_IEEE80211_DATA_ENCAP,
data_encap_handle);
wlan_rsna_eapol_wpa_key_handle = new_create_dissector_handle(dissect_wlan_rsna_eapol_wpa_key,
proto_wlan_rsna_eapol);
dissector_add_uint("eapol.keydes.type", EAPOL_WPA_KEY, wlan_rsna_eapol_wpa_key_handle);
wlan_rsna_eapol_rsn_key_handle = new_create_dissector_handle(dissect_wlan_rsna_eapol_rsn_key,
proto_wlan_rsna_eapol);
dissector_add_uint("eapol.keydes.type", EAPOL_RSN_KEY, wlan_rsna_eapol_rsn_key_handle);
wlan_withoutfcs_handle = find_dissector("wlan_withoutfcs");
dissector_add_uint("sflow_245.header_protocol", SFLOW_5_HEADER_80211_MAC, wlan_withoutfcs_handle);
}
