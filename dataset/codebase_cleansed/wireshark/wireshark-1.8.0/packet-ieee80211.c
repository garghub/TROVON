static void* uat_wep_key_record_copy_cb(void* n, const void* o, size_t siz _U_) {
uat_wep_key_record_t* new_key = (uat_wep_key_record_t *)n;
const uat_wep_key_record_t* old_key = (const uat_wep_key_record_t *)o;
if (old_key->string) {
new_key->string = g_strdup(old_key->string);
} else {
new_key->string = NULL;
}
return new_key;
}
static void uat_wep_key_record_update_cb(void* r, const char** err) {
uat_wep_key_record_t* rec = (uat_wep_key_record_t *)r;
decryption_key_t* dk;
if (rec->string == NULL) {
*err = ep_strdup_printf("Key can't be blank");
} else {
g_strstrip(rec->string);
dk = parse_key_string(rec->string, rec->key);
if(dk != NULL) {
switch(dk->type) {
case AIRPDCAP_KEY_TYPE_WEP:
case AIRPDCAP_KEY_TYPE_WEP_40:
case AIRPDCAP_KEY_TYPE_WEP_104:
if (rec->key != AIRPDCAP_KEY_TYPE_WEP) {
*err = ep_strdup_printf("Invalid key format");
}
break;
case AIRPDCAP_KEY_TYPE_WPA_PWD:
if (rec->key != AIRPDCAP_KEY_TYPE_WPA_PWD) {
*err = ep_strdup_printf("Invalid key format");
}
break;
case AIRPDCAP_KEY_TYPE_WPA_PSK:
if (rec->key != AIRPDCAP_KEY_TYPE_WPA_PSK) {
*err = ep_strdup_printf("Invalid key format");
}
break;
default:
*err = ep_strdup_printf("Invalid key format");
break;
}
} else {
*err = ep_strdup_printf("Invalid key format");
}
}
}
static void uat_wep_key_record_free_cb(void*r) {
uat_wep_key_record_t* key = (uat_wep_key_record_t *)r;
if (key->string) g_free(key->string);
}
static void
beacon_interval_base_custom(gchar *result, guint32 beacon_interval)
{
double temp_double;
temp_double = (double)beacon_interval;
g_snprintf(result, ITEM_LABEL_LENGTH, "%f [Seconds]", (temp_double * 1024 / 1000000) );
}
static int
find_header_length (guint16 fcf, guint16 ctrl_fcf, gboolean is_ht)
{
int len;
guint16 cw_fcf;
switch (FCF_FRAME_TYPE (fcf)) {
case MGT_FRAME:
if (is_ht && IS_STRICTLY_ORDERED(FCF_FLAGS(fcf)))
return MGT_FRAME_HDR_LEN + 4;
return MGT_FRAME_HDR_LEN;
case CONTROL_FRAME:
if (COMPOSE_FRAME_TYPE(fcf) == CTRL_CONTROL_WRAPPER) {
len = 6;
cw_fcf = ctrl_fcf;
} else {
len = 0;
cw_fcf = fcf;
}
switch (COMPOSE_FRAME_TYPE (cw_fcf)) {
case CTRL_CTS:
case CTRL_ACKNOWLEDGEMENT:
return len + 10;
case CTRL_RTS:
case CTRL_PS_POLL:
case CTRL_CFP_END:
case CTRL_CFP_ENDACK:
case CTRL_BLOCK_ACK_REQ:
case CTRL_BLOCK_ACK:
return len + 16;
}
return len + 4;
case DATA_FRAME:
len = (FCF_ADDR_SELECTOR(fcf) ==
DATA_ADDR_T4) ? DATA_LONG_HDR_LEN : DATA_SHORT_HDR_LEN;
if (DATA_FRAME_IS_QOS(COMPOSE_FRAME_TYPE(fcf))) {
len += 2;
if (is_ht && IS_STRICTLY_ORDERED(FCF_FLAGS(fcf))) {
len += 4;
}
}
return len;
default:
return 4;
}
}
static int
has_mesh_control(guint16 fcf, guint16 qos_ctl, guint8 mesh_flags)
{
return ((FCF_ADDR_SELECTOR(fcf) == DATA_ADDR_T4 || FCF_ADDR_SELECTOR(fcf) == DATA_ADDR_T2) &&
(QOS_MESH_CONTROL_PRESENT(qos_ctl)) &&
(mesh_flags & ~MESH_FLAGS_ADDRESS_EXTENSION) == 0 &&
(mesh_flags & MESH_FLAGS_ADDRESS_EXTENSION) != MESH_FLAGS_ADDRESS_EXTENSION);
}
static int
find_mesh_control_length(guint8 mesh_flags)
{
return 6 + 6*(mesh_flags & MESH_FLAGS_ADDRESS_EXTENSION);
}
mimo_control_t get_mimo_control (tvbuff_t *tvb, int offset)
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
int get_mimo_na (guint8 nr, guint8 nc)
{
if (nr == 2 && nc == 1){
return 2;
}else if (nr == 2 && nc == 2){
return 2;
}else if (nr == 3 && nc == 1){
return 4;
}else if (nr == 3 && nc == 2){
return 6;
}else if (nr == 3 && nc == 3){
return 6;
}else if (nr == 4 && nc == 1){
return 6;
}else if (nr == 4 && nc == 2){
return 10;
}else if (nr == 4 && nc == 3){
return 12;
}else if (nr == 4 && nc == 4){
return 12;
}else{
return 0;
}
}
int get_mimo_ns (gboolean chan_width, guint8 output_grouping)
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
int add_mimo_csi_matrices_report (proto_tree *tree, tvbuff_t *tvb, int offset, mimo_control_t mimo_cntrl)
{
proto_item *snr_item;
proto_tree *snr_tree;
int csi_matrix_size, start_offset;
int ns, i;
start_offset = offset;
snr_item = proto_tree_add_text(tree, tvb, offset, mimo_cntrl.nc, "Signal to Noise Ratio");
snr_tree = proto_item_add_subtree (snr_item, ett_mimo_report);
for (i = 1; i <= mimo_cntrl.nr; i++)
{
guint8 snr;
snr = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(snr_tree, hf_ieee80211_ff_mimo_csi_snr, tvb, offset, 1, snr, "Channel %d - Signal to Noise Ratio: 0x%02X", i, snr);
offset++;
}
ns = get_mimo_ns(mimo_cntrl.chan_width, mimo_cntrl.grouping);
csi_matrix_size = ns*(3+(2*mimo_cntrl.nc*mimo_cntrl.nr*mimo_cntrl.coefficient_size));
csi_matrix_size = roundup2(csi_matrix_size, 8) / 8;
proto_tree_add_text(tree, tvb, offset, csi_matrix_size, "CSI Matrices");
offset += csi_matrix_size;
return offset - start_offset;
}
int add_mimo_beamforming_feedback_report (proto_tree *tree, tvbuff_t *tvb, int offset, mimo_control_t mimo_cntrl)
{
proto_item *snr_item;
proto_tree *snr_tree;
int csi_matrix_size, start_offset;
int ns, i;
start_offset = offset;
snr_item = proto_tree_add_text(tree, tvb, offset, mimo_cntrl.nc, "Signal to Noise Ratio");
snr_tree = proto_item_add_subtree (snr_item, ett_mimo_report);
for (i = 1; i <= mimo_cntrl.nc; i++)
{
guint8 snr;
snr = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(snr_tree, hf_ieee80211_ff_mimo_csi_snr, tvb, offset, 1, snr, "Stream %d - Signal to Noise Ratio: 0x%02X", i, snr);
offset++;
}
ns = get_mimo_ns(mimo_cntrl.chan_width, mimo_cntrl.grouping);
csi_matrix_size = ns*(2*mimo_cntrl.nc*mimo_cntrl.nr*mimo_cntrl.coefficient_size);
csi_matrix_size = roundup2(csi_matrix_size, 8) / 8;
proto_tree_add_text(tree, tvb, offset, csi_matrix_size, "Beamforming Feedback Matrices");
offset += csi_matrix_size;
return offset - start_offset;
}
int add_mimo_compressed_beamforming_feedback_report (proto_tree *tree, tvbuff_t *tvb, int offset, mimo_control_t mimo_cntrl)
{
proto_item *snr_item;
proto_tree *snr_tree;
int csi_matrix_size, start_offset;
int ns, na, i;
start_offset = offset;
snr_item = proto_tree_add_text(tree, tvb, offset, mimo_cntrl.nc, "Signal to Noise Ratio");
snr_tree = proto_item_add_subtree (snr_item, ett_mimo_report);
for (i = 1; i <= mimo_cntrl.nc; i++)
{
guint8 snr;
snr = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(snr_tree, hf_ieee80211_ff_mimo_csi_snr, tvb, offset, 1, snr, "Stream %d - Signal to Noise Ratio: 0x%02X", i, snr);
offset++;
}
na = get_mimo_na(mimo_cntrl.nr, mimo_cntrl.nc);
ns = get_mimo_ns(mimo_cntrl.chan_width, mimo_cntrl.grouping);
csi_matrix_size = ns*(na*((mimo_cntrl.codebook_info+1)*2 + 2)/2);
csi_matrix_size = roundup2(csi_matrix_size, 8) / 8;
proto_tree_add_text(tree, tvb, offset, csi_matrix_size, "Compressed Beamforming Feedback Matrices");
offset += csi_matrix_size;
return offset - start_offset;
}
static void
capture_ieee80211_common (const guchar * pd, int offset, int len,
packet_counts * ld, gboolean fixed_length_header,
gboolean datapad, gboolean is_ht)
{
guint16 fcf, hdr_length;
if (!BYTES_ARE_IN_FRAME(offset, len, 2)) {
ld->other++;
return;
}
fcf = pletohs (&pd[offset]);
if (IS_PROTECTED(FCF_FLAGS(fcf)) && wlan_ignore_wep == WLAN_IGNORE_WEP_NO) {
ld->other++;
return;
}
switch (COMPOSE_FRAME_TYPE (fcf)) {
case DATA:
case DATA_CF_ACK:
case DATA_CF_POLL:
case DATA_CF_ACK_POLL:
case DATA_QOS_DATA:
{
if (fixed_length_header) {
hdr_length = DATA_LONG_HDR_LEN;
} else {
hdr_length = find_header_length (fcf, 0, is_ht);
if (FCF_FRAME_TYPE(fcf) == DATA_FRAME &&
DATA_FRAME_IS_QOS(COMPOSE_FRAME_TYPE(fcf))) {
guint8 mesh_flags = pd[hdr_length];
guint16 qosoff = hdr_length - 2;
qosoff -= is_ht ? 4 : 0;
if (has_mesh_control(fcf, pletohs(&pd[qosoff]), mesh_flags)) {
hdr_length += find_mesh_control_length(mesh_flags);
}
}
if (datapad)
hdr_length = roundup2(hdr_length, 4);
}
if (!BYTES_ARE_IN_FRAME(offset+hdr_length, len, 2)) {
ld->other++;
return;
}
if (pd[offset+hdr_length] != 0xaa && pd[offset+hdr_length+1] != 0xaa) {
#if 0
if (BYTES_ARE_IN_FRAME(offset+hdr_length, len, 12) {
if (memcmp(&pd[offset+hdr_length+6], pinfo->dl_src.data, 6) == 0 ||
memcmp(&pd[offset+hdr_length+6], pinfo->dl_dst.data, 6) == 0) {
capture_eth (pd, offset + hdr_length, len, ld);
return;
}
}
#endif
if (pd[offset+hdr_length] == 0xff && pd[offset+hdr_length+1] == 0xff)
capture_ipx (ld);
else if (pd[offset+hdr_length] == 0x00 && pd[offset+hdr_length+1] == 0x00)
capture_llc (pd, offset + hdr_length + 2, len, ld);
}
else {
capture_llc (pd, offset + hdr_length, len, ld);
}
break;
}
default:
ld->other++;
break;
}
}
void
capture_ieee80211 (const guchar * pd, int offset, int len, packet_counts * ld)
{
capture_ieee80211_common (pd, offset, len, ld, FALSE, FALSE, FALSE);
}
void
capture_ieee80211_datapad (const guchar * pd, int offset, int len,
packet_counts * ld)
{
capture_ieee80211_common (pd, offset, len, ld, FALSE, TRUE, FALSE);
}
void
capture_ieee80211_fixed (const guchar * pd, int offset, int len, packet_counts * ld)
{
capture_ieee80211_common (pd, offset, len, ld, TRUE, FALSE, FALSE);
}
void
capture_ieee80211_ht (const guchar * pd, int offset, int len, packet_counts * ld)
{
capture_ieee80211_common (pd, offset, len, ld, FALSE, FALSE, TRUE);
}
static proto_tree *
get_fixed_parameter_tree (proto_tree * tree, tvbuff_t *tvb, int start, int size)
{
proto_item *fixed_fields;
fixed_fields =
proto_tree_add_uint_format (tree, hf_ieee80211_fixed_parameters, tvb, start,
size, size, "Fixed parameters (%d bytes)",
size);
return proto_item_add_subtree (fixed_fields, ett_fixed_parameters);
}
static proto_tree *
get_tagged_parameter_tree (proto_tree * tree, tvbuff_t *tvb, int start, int size)
{
proto_item *tagged_fields;
tagged_fields = proto_tree_add_uint_format (tree, hf_ieee80211_tagged_parameters,
tvb,
start,
2,
size,
"Tagged parameters (%d bytes)",
size);
proto_item_set_len(tagged_fields, size);
return proto_item_add_subtree (tagged_fields, ett_tagged_parameters);
}
static int
dissect_vendor_action_marvell(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 octet;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_action_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
switch (octet)
{
case MRVL_ACTION_MESH_MANAGEMENT:
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_action_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
switch (octet)
{
case MRVL_MESH_MGMT_ACTION_RREQ:
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_hopcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_ttl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_rreqid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_sa, tvb, offset, 6, ENC_NA);
offset+= 6;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_ssn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_lifetime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_metric, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_dstcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_da, tvb, offset, 6, ENC_NA);
offset+= 6;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_dsn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
break;
case MRVL_MESH_MGMT_ACTION_RREP:
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_hopcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_ttl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_da, tvb, offset, 6, ENC_NA);
offset+= 6;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_dsn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_lifetime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_metric, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_sa, tvb, offset, 6, ENC_NA);
offset+= 6;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_ssn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
break;
case MRVL_MESH_MGMT_ACTION_RERR:
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_dstcount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_da, tvb, offset, 6, ENC_NA);
offset+= 6;
proto_tree_add_item (tree, hf_ieee80211_ff_marvell_mesh_mgt_dsn, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
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
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Unexpected IE %d (expected Advertisement "
"Protocol)", tag_no);
return 2 + tag_len;
}
if (anqp)
item = proto_tree_add_uint(tree, hf_ieee80211_tag_length, tvb, offset + 1, 1, tag_len);
if (tag_len < 2) {
if (!anqp)
item = proto_tree_add_uint(tree, hf_ieee80211_tag_length, tvb, offset + 1, 1, tag_len);
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Advertisement Protocol: IE must be at least 2 "
"octets long");
return 2 + tag_len;
}
left = tag_len;
offset += 2;
adv_item = proto_tree_add_text(tree, tvb, offset, left,
"Advertisement Protocol element");
adv_tree = proto_item_add_subtree(adv_item, ett_adv_proto);
while (left >= 2) {
guint8 id;
id = tvb_get_guint8(tvb, offset + 1);
if (id == 0)
proto_item_append_text(adv_item, ": ANQP");
item = proto_tree_add_text(adv_tree, tvb, offset, 2,
"Advertisement Protocol Tuple: %s",
val_to_str(id, adv_proto_id_vals,
"Unknown (%d)"));
adv_tuple_tree = proto_item_add_subtree(item, ett_adv_proto_tuple);
proto_tree_add_item(adv_tuple_tree,
hf_ieee80211_tag_adv_proto_resp_len_limit, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tuple_tree,
hf_ieee80211_tag_adv_proto_pame_bi, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
left--;
proto_tree_add_item(adv_tuple_tree, hf_ieee80211_tag_adv_proto_id, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
left--;
if (id == 0 && anqp)
*anqp = TRUE;
if (id == 221) {
guint8 len = tvb_get_guint8(tvb, offset);
offset++;
left--;
if (len > left) {
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Vendor specific info length error");
return 2 + tag_len;
}
proto_tree_add_text(adv_tuple_tree, tvb, offset, len,
"Vendor Specific Advertisement Protocol info");
offset += len;
left -= len;
}
}
if (left) {
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Unexpected extra data in the end");
}
return 2 + tag_len;
}
static void
dissect_anqp_query_list(proto_tree *tree, tvbuff_t *tvb, int offset, int end)
{
while (offset + 2 <= end) {
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_query_id,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if (offset != end) {
expert_add_info_format(g_pinfo, tree, PI_MALFORMED, PI_ERROR,
"Unexpected ANQP Query list format");
}
}
static void
dissect_anqp_capab_list(proto_tree *tree, tvbuff_t *tvb, int offset, int end)
{
guint16 id, len;
proto_item *item;
proto_tree *vtree;
guint32 oui;
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
if (len < 3 || offset + len > end) {
expert_add_info_format(g_pinfo, tree, PI_MALFORMED, PI_ERROR,
"Invalid vendor-specific ANQP capability");
return;
}
oui = tvb_get_ntoh24(tvb, offset);
proto_tree_add_item(vtree, hf_ieee80211_tag_oui, tvb, offset, 3, ENC_NA);
offset += 3;
len -= 3;
switch (oui) {
default:
proto_tree_add_item(vtree, hf_ieee80211_ff_anqp_capability_vendor,
tvb, offset, len, ENC_NA);
break;
}
offset += len;
}
}
if (offset != end) {
expert_add_info_format(g_pinfo, tree, PI_MALFORMED, PI_ERROR,
"Unexpected ANQP Capability list format");
}
}
static void dissect_venue_info(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_venue_info_group,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_ff_venue_info_type,
tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
static void
dissect_venue_name_info(proto_tree *tree, tvbuff_t *tvb, int offset, int end)
{
proto_item *item;
dissect_venue_info(tree, tvb, offset);
offset += 2;
while (offset + 4 <= end) {
guint8 vlen = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree, hf_ieee80211_ff_anqp_venue_length,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (vlen > end - offset || vlen < 3) {
expert_add_info_format(g_pinfo, item, PI_MALFORMED, PI_ERROR,
"Invalid Venue Name Duple length");
break;
}
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_venue_language,
tvb, offset, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_venue_name,
tvb, offset + 3, vlen - 3, ENC_ASCII|ENC_NA);
offset += vlen;
}
}
static void
dissect_network_auth_type(proto_tree *tree, tvbuff_t *tvb, int offset, int end)
{
while (offset + 3 <= end) {
guint16 len;
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_nw_auth_type_indicator,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
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
static void add_manuf(proto_item *item, tvbuff_t *tvb, int offset)
{
const gchar *manuf_name;
manuf_name = tvb_get_manuf_name_if_known(tvb, offset);
if (manuf_name == NULL)
return;
proto_item_append_text(item, " - %s", manuf_name);
}
static void
dissect_roaming_consortium_list(proto_tree *tree, tvbuff_t *tvb, int offset,
int end)
{
proto_item *item;
guint8 len;
while (offset < end) {
len = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree,
hf_ieee80211_ff_anqp_roaming_consortium_oi_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (len > end - offset || len < 3) {
expert_add_info_format(g_pinfo, item, PI_MALFORMED, PI_ERROR,
"Invalid Roaming Consortium OI");
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
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_ip_addr_avail_ipv4,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_nai_realm_list(proto_tree *tree, tvbuff_t *tvb, int offset, int end)
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
r_item = proto_tree_add_text(tree, tvb, offset, 2 + len, "NAI Realm Data");
realm_tree = proto_item_add_subtree(r_item, ett_nai_realm);
item = proto_tree_add_item(realm_tree, hf_ieee80211_ff_anqp_nai_field_len,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (offset + len > end) {
expert_add_info_format(g_pinfo, item, PI_MALFORMED, PI_ERROR,
"Invalid NAI Realm List");
break;
}
f_end = offset + len;
proto_tree_add_item(realm_tree, hf_ieee80211_ff_anqp_nai_realm_encoding,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
nai_len = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(realm_tree,
hf_ieee80211_ff_anqp_nai_realm_length,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (offset + nai_len > f_end) {
expert_add_info_format(g_pinfo, item, PI_MALFORMED, PI_ERROR,
"Invalid NAI Realm Data");
break;
}
proto_tree_add_item(realm_tree, hf_ieee80211_ff_anqp_nai_realm,
tvb, offset, nai_len, ENC_ASCII|ENC_NA);
realm = tvb_get_string(tvb, offset, nai_len);
if (realm) {
proto_item_append_text(r_item, " (%s)", realm);
g_free(realm);
}
offset += nai_len;
eap_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(realm_tree, hf_ieee80211_ff_anqp_nai_realm_eap_count,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
while (eap_count > 0) {
eap_len = tvb_get_guint8(tvb, offset);
eap_end = offset + 1 + eap_len;
item = proto_tree_add_text(realm_tree, tvb, offset, 1 + eap_len,
"EAP Method");
eap_tree = proto_item_add_subtree(item, ett_nai_realm_eap);
item = proto_tree_add_item(eap_tree,
hf_ieee80211_ff_anqp_nai_realm_eap_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (offset + eap_len > f_end) {
expert_add_info_format(g_pinfo, item, PI_MALFORMED, PI_ERROR,
"Invalid EAP Method subfield");
break;
}
proto_item_append_text(eap_tree, ": %s",
val_to_str(tvb_get_guint8(tvb, offset),
eap_type_vals, "Unknown (%d)"));
proto_tree_add_item(eap_tree, hf_ieee80211_ff_anqp_nai_realm_eap_method,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
auth_param_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eap_tree,
hf_ieee80211_ff_anqp_nai_realm_auth_param_count,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
while (auth_param_count > 0) {
auth_param_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eap_tree,
hf_ieee80211_ff_anqp_nai_realm_auth_param_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
auth_param_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eap_tree,
hf_ieee80211_ff_anqp_nai_realm_auth_param_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
item = proto_tree_add_item(
eap_tree, hf_ieee80211_ff_anqp_nai_realm_auth_param_value,
tvb, offset, auth_param_len, ENC_NA);
if (auth_param_id == 3 && auth_param_len == 1) {
guint8 inner_method = tvb_get_guint8(tvb, offset);
const char *str;
str = val_to_str(inner_method, eap_type_vals, "Unknown (%d)");
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
dissect_3gpp_cellular_network_info(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 iei, num;
proto_item *item;
proto_tree_add_item(tree, hf_ieee80211_3gpp_gc_gud, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_3gpp_gc_udhl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
iei = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree, hf_ieee80211_3gpp_gc_iei, tvb, offset, 1, ENC_BIG_ENDIAN);
if (iei == 0)
proto_item_append_text(item, " (PLMN List)");
else
return;
offset++;
proto_tree_add_item(tree, hf_ieee80211_3gpp_gc_plmn_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
num = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_3gpp_gc_num_plmns, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while (num > 0) {
guint8 o1, o2, o3;
if (tvb_reported_length_remaining(tvb, offset) < 3)
break;
num--;
o1 = tvb_get_guint8(tvb, offset);
o2 = tvb_get_guint8(tvb, offset + 1);
o3 = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_string_format_value(tree, hf_ieee80211_3gpp_gc_plmn, tvb, offset, 3,
"", "MCC %d%d%d MNC %d%d%c",
o1 & 0x0f, (o1 & 0xf0) >> 4, o2 & 0x0f,
o3 & 0x0f, (o3 & 0xf0) >> 4,
((o2 & 0xf0) == 0xf0) ? ' ' :
('0' + ((o2 & 0xf0) >> 4)));
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
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_domain_name,
tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
}
}
static int
dissect_anqp_info(proto_tree *tree, tvbuff_t *tvb, int offset,
gboolean request, int idx)
{
guint16 id, len;
guint32 oui;
guint8 subtype;
proto_item *item;
item = proto_tree_add_item(tree, hf_ieee80211_ff_anqp_info_id,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
id = tvb_get_letohs(tvb, offset);
if (id != ANQP_INFO_ANQP_VENDOR_SPECIFIC_LIST) {
if (idx == 0) {
proto_item_append_text(tree, " - %s",
val_to_str(id, anqp_info_id_vals,
"Unknown (%u)"));
col_append_fstr(g_pinfo->cinfo, COL_INFO, " %s",
val_to_str(id, anqp_info_id_vals, "Unknown (%u)"));
} else if (idx == 1) {
proto_item_append_text(tree, ", ..");
col_append_fstr(g_pinfo->cinfo, COL_INFO, ", ..");
}
}
tree = proto_item_add_subtree(item, ett_gas_anqp);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_ff_anqp_info_length,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
len = tvb_get_letohs(tvb, offset);
offset += 2;
if (tvb_reported_length_remaining(tvb, offset) < len) {
expert_add_info_format(g_pinfo, tree, PI_MALFORMED, PI_ERROR,
"Invalid ANQP Info length");
return 4 + len;
}
switch (id)
{
case ANQP_INFO_ANQP_QUERY_LIST:
dissect_anqp_query_list(tree, tvb, offset, offset + len);
break;
case ANQP_INFO_ANQP_CAPAB_LIST:
dissect_anqp_capab_list(tree, tvb, offset, offset + len);
break;
case ANQP_INFO_VENUE_NAME_INFO:
dissect_venue_name_info(tree, tvb, offset, offset + len);
break;
case ANQP_INFO_NETWORK_AUTH_TYPE_INFO:
dissect_network_auth_type(tree, tvb, offset, offset + len);
break;
case ANQP_INFO_ROAMING_CONSORTIUM_LIST:
dissect_roaming_consortium_list(tree, tvb, offset, offset + len);
break;
case ANQP_INFO_IP_ADDR_TYPE_AVAILABILITY_INFO:
dissect_ip_addr_type_availability_info(tree, tvb, offset);
break;
case ANQP_INFO_NAI_REALM_LIST:
dissect_nai_realm_list(tree, tvb, offset, offset + len);
break;
case ANQP_INFO_3GPP_CELLULAR_NETWORK_INFO:
dissect_3gpp_cellular_network_info(tree, tvb, offset);
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
subtype = tvb_get_guint8(tvb, offset);
if (subtype == WFA_SUBTYPE_P2P) {
proto_tree_add_text(tree, tvb, offset, 1, "Subtype %u: P2P ANQP",
subtype);
dissect_wifi_p2p_anqp(g_pinfo, tree, tvb, offset + 1, request);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "Subtype %u", subtype);
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
dissect_anqp(proto_tree *tree, tvbuff_t *tvb, int offset, gboolean request)
{
int idx = 0;
proto_item_append_text(tree, ": ANQP ");
proto_item_append_text(tree, request ? "Request" : "Response");
if (tvb_reported_length_remaining(tvb, offset) < 4) {
expert_add_info_format(g_pinfo, tree, PI_MALFORMED, PI_ERROR,
"Not enough room for ANQP header");
return;
}
col_append_fstr(g_pinfo->cinfo, COL_INFO, ", ANQP %s",
request ? "Req" : "Resp");
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset += dissect_anqp_info(tree, tvb, offset, request, idx);
idx++;
}
}
static guint
dissect_gas_initial_request(proto_tree *tree, tvbuff_t *tvb, int offset,
gboolean anqp)
{
guint16 req_len;
int start = offset;
proto_item *item;
proto_tree *query;
req_len = tvb_get_letohs(tvb, offset);
item = proto_tree_add_text(tree, tvb, offset, 2 + req_len, "Query Request");
if (tvb_reported_length_remaining(tvb, offset) < 2 + req_len) {
expert_add_info_format(g_pinfo, tree, PI_MALFORMED, PI_ERROR,
"Invalid Query Request Length");
return tvb_reported_length_remaining(tvb, offset);
}
query = proto_item_add_subtree(item, ett_gas_query);
proto_tree_add_item(query, hf_ieee80211_ff_query_request_length,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (anqp)
dissect_anqp(query, tvb, offset, TRUE);
else
proto_tree_add_item(query, hf_ieee80211_ff_query_request,
tvb, offset, req_len, ENC_NA);
offset += req_len;
return offset - start;
}
static guint
dissect_gas_initial_response(proto_tree *tree, tvbuff_t *tvb, int offset,
gboolean anqp)
{
guint16 resp_len;
int start = offset;
proto_item *item;
proto_tree *query;
resp_len = tvb_get_letohs(tvb, offset);
item = proto_tree_add_text(tree, tvb, offset, 2 + resp_len,
"Query Response");
if (tvb_reported_length_remaining(tvb, offset) < 2 + resp_len) {
expert_add_info_format(g_pinfo, tree, PI_MALFORMED, PI_ERROR,
"Invalid Query Response Length");
return tvb_reported_length_remaining(tvb, offset);
}
query = proto_item_add_subtree(item, ett_gas_query);
proto_tree_add_item(query, hf_ieee80211_ff_query_response_length,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (resp_len) {
if (anqp)
dissect_anqp(query, tvb, offset, FALSE);
else
proto_tree_add_item(query, hf_ieee80211_ff_query_response,
tvb, offset, resp_len, ENC_NA);
offset += resp_len;
}
return offset - start;
}
static void ieee80211_gas_reassembly_init(void)
{
fragment_table_init(&gas_fragment_table);
reassembled_table_init(&gas_reassembled_table);
}
static guint
dissect_gas_comeback_response(proto_tree *tree, tvbuff_t *tvb, int offset,
gboolean anqp, guint8 frag, gboolean more,
guint8 dialog_token)
{
guint16 resp_len;
int start = offset;
proto_item *item;
proto_tree *query;
resp_len = tvb_get_letohs(tvb, offset);
item = proto_tree_add_text(tree, tvb, offset, 2 + resp_len,
"Query Response");
if (tvb_reported_length_remaining(tvb, offset) < 2 + resp_len) {
expert_add_info_format(g_pinfo, tree, PI_MALFORMED, PI_ERROR,
"Invalid Query Response Length");
return tvb_reported_length_remaining(tvb, offset);
}
query = proto_item_add_subtree(item, ett_gas_query);
proto_tree_add_item(query, hf_ieee80211_ff_query_response_length,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (resp_len) {
if (anqp && frag == 0 && !more)
dissect_anqp(query, tvb, offset, FALSE);
else {
fragment_data *frag_msg;
gboolean save_fragmented;
tvbuff_t *new_tvb;
save_fragmented = g_pinfo->fragmented;
g_pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(tvb, offset, g_pinfo, dialog_token,
gas_fragment_table,
gas_reassembled_table, frag, resp_len,
more);
new_tvb = process_reassembled_data(tvb, offset, g_pinfo,
"Reassembled GAS Query Response",
frag_msg, &gas_resp_frag_items,
NULL, tree);
if (new_tvb) {
if (anqp)
dissect_anqp(query, new_tvb, 0, FALSE);
else
proto_tree_add_item(query, hf_ieee80211_ff_query_response,
new_tvb, 0,
tvb_reported_length_remaining(new_tvb, 0),
ENC_NA);
}
ieee80211_tvb_invalid = TRUE;
g_pinfo->fragmented = save_fragmented;
}
offset += resp_len;
}
return offset - start;
}
static guint
add_ff_timestamp(proto_tree *tree, tvbuff_t *tvb, int offset)
{
last_timestamp = tvb_get_letoh64(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_ff_timestamp, tvb, offset, 8,
ENC_LITTLE_ENDIAN);
return 8;
}
static guint
add_ff_beacon_interval(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_beacon_interval, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
col_append_fstr(g_pinfo->cinfo, COL_INFO, ", BI=%d",
tvb_get_letohs(tvb, offset));
return 2;
}
static guint
add_ff_cap_info(proto_tree *tree, tvbuff_t *tvb, int offset)
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
proto_tree_add_item(cap_tree, hf_ieee80211_ff_dsss_ofdm, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_del_blk_ack, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ff_cf_imm_blk_ack, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_auth_alg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_auth_alg, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_auth_trans_seq(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_auth_seq, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_current_ap_addr(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_current_ap, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_listen_ival(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_listen_ival, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_reason_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_reason, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_assoc_id(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_assoc_id, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_status_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_status_code, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_category_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_category_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_dialog_token(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_dialog_token, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_wme_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_wme_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_wme_status_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_wme_status_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_qos_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_qos_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_block_ack_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_ba_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_block_ack_param(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_block_ack_params,
ett_ff_ba_param_tree,
ieee80211_ff_block_ack_params_fields,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_block_ack_timeout(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_block_ack_timeout, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_block_ack_ssc(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_block_ack_ssc,
ett_ff_ba_ssc_tree, ieee80211_ff_block_ack_ssc_fields,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_qos_ts_info(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_tsinfo,
ett_tsinfo_tree, ieee80211_tsinfo_fields,
ENC_LITTLE_ENDIAN);
return 3;
}
static guint
add_ff_mesh_action(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_mesh_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_multihop_action(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_multihop_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_mesh_control(proto_tree *tree, tvbuff_t *tvb, int offset)
{
int start = offset;
guint8 flags;
proto_tree_add_item(tree, hf_ieee80211_ff_mesh_flags, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
flags = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_ieee80211_ff_mesh_ttl, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset++;
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
proto_item_append_text(tree, "Unknown Address Extension Mode");
break;
default:
break;
}
return offset - start;
}
static guint
add_ff_selfprot_action(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_selfprot_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_dls_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_dls_action_code, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_dst_mac_addr(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_dst_mac_addr, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_src_mac_addr(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_src_mac_addr, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_dls_timeout(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_dls_timeout, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_delba_param_set(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_delba_param,
ett_ff_ba_param_tree, ieee80211_ff_delba_param_fields,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_max_reg_pwr(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_max_reg_pwr, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_measurement_pilot_int(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_measurement_pilot_int, tvb, offset,
2, ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_country_str(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_string(tree, hf_ieee80211_ff_country_str, tvb, offset, 3,
ENC_BIG_ENDIAN);
return 3;
}
static guint
add_ff_max_tx_pwr(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_max_tx_pwr, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_tx_pwr_used(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_tx_pwr_used, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_transceiver_noise_floor(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_transceiver_noise_floor, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_channel_width(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_channel_width, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_qos_info_ap(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_qos_info_ap,
ett_ff_qos_info, ieee80211_ff_qos_info_ap_fields,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_qos_info_sta(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_qos_info_sta,
ett_ff_qos_info, ieee80211_ff_qos_info_sta_fields,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_sm_pwr_cntrl(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_sm_pwr_save,
ett_ff_sm_pwr_save, ieee80211_ff_sw_pwr_save_fields,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_pco_phase_cntrl(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_pco_phase_cntrl, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_psmp_param_set(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_psmp_param_set,
ett_ff_psmp_param_set,
ieee80211_ff_psmp_param_set_fields,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_mimo_cntrl(proto_tree *tree, tvbuff_t *tvb, int offset)
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
add_ff_ant_selection(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_ant_selection,
ett_ff_ant_sel, ieee80211_ff_ant_selection_fields,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_extended_channel_switch_announcement(proto_tree *tree, tvbuff_t *tvb,
int offset)
{
proto_tree_add_bitmask(tree, tvb, offset,
hf_ieee80211_ff_ext_channel_switch_announcement,
ett_ff_chan_switch_announce,
ieee80211_ff_ext_channel_switch_announcement_fields,
ENC_LITTLE_ENDIAN);
return 4;
}
static guint
add_ff_ht_information(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_ieee80211_ff_ht_info,
ett_ff_ht_info, ieee80211_ff_ht_info_fields,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_ht_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_ht_action, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
return 1;
}
static guint
add_ff_psmp_sta_info(proto_tree *tree, tvbuff_t *tvb, int offset)
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
G_GINT64_CONSTANT(0xFFFFFFFFFFE00000)) >> 21);
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
G_GINT64_CONSTANT(0xFFFFFFFFFFE00000)) >> 21);
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
add_ff_schedule_info(proto_tree *tree, tvbuff_t *tvb, int offset)
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
add_ff_pa_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_public_action, tvb, offset, 1,
ENC_BIG_ENDIAN);
return 1;
}
static guint
add_ff_action_spectrum_mgmt(proto_tree *tree, tvbuff_t *tvb, int offset)
{
switch (tvb_get_guint8(tvb, offset + 1)) {
case SM_ACTION_MEASUREMENT_REQUEST:
case SM_ACTION_MEASUREMENT_REPORT:
case SM_ACTION_TPC_REQUEST:
case SM_ACTION_TPC_REPORT:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, offset + 1, FIELD_ACTION_CODE);
add_fixed_field(tree, tvb, offset + 2, FIELD_DIALOG_TOKEN);
return 3;
case SM_ACTION_CHAN_SWITCH_ANNC:
case SM_ACTION_EXT_CHAN_SWITCH_ANNC:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, offset + 1, FIELD_ACTION_CODE);
return 2;
default:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, offset + 1, FIELD_ACTION_CODE);
return 2;
}
}
static guint
add_ff_action_qos(proto_tree *tree, tvbuff_t *tvb, int offset)
{
switch (tvb_get_guint8(tvb, offset + 1)) {
case SM_ACTION_ADDTS_REQUEST:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, offset + 1, FIELD_QOS_ACTION_CODE);
add_fixed_field(tree, tvb, offset + 2, FIELD_DIALOG_TOKEN);
return 3;
case SM_ACTION_ADDTS_RESPONSE:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, offset + 1, FIELD_QOS_ACTION_CODE);
add_fixed_field(tree, tvb, offset + 2, FIELD_DIALOG_TOKEN);
add_fixed_field(tree, tvb, offset + 3, FIELD_STATUS_CODE);
return 5;
case SM_ACTION_DELTS:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, offset + 1, FIELD_QOS_ACTION_CODE);
add_fixed_field(tree, tvb, offset + 2, FIELD_QOS_TS_INFO);
add_fixed_field(tree, tvb, offset + 5, FIELD_REASON_CODE);
return 7;
case SM_ACTION_QOS_SCHEDULE:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, offset + 1, FIELD_QOS_ACTION_CODE);
return 2;
default:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
return 2;
}
}
static guint
add_ff_action_dls(proto_tree *tree, tvbuff_t *tvb, int offset)
{
switch (tvb_get_guint8(tvb, offset + 1)) {
case SM_ACTION_DLS_REQUEST:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, offset + 1, FIELD_DLS_ACTION_CODE);
add_fixed_field(tree, tvb, offset + 2, FIELD_DST_MAC_ADDR);
add_fixed_field(tree, tvb, offset + 8, FIELD_SRC_MAC_ADDR);
add_fixed_field(tree, tvb, offset + 14, FIELD_CAP_INFO);
add_fixed_field(tree, tvb, offset + 16, FIELD_DLS_TIMEOUT);
return 18;
case SM_ACTION_DLS_RESPONSE:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, offset + 1, FIELD_DLS_ACTION_CODE);
add_fixed_field(tree, tvb, offset + 2, FIELD_STATUS_CODE);
add_fixed_field(tree, tvb, offset + 4, FIELD_DST_MAC_ADDR);
add_fixed_field(tree, tvb, offset + 10, FIELD_SRC_MAC_ADDR);
if (!hf_ieee80211_ff_status_code) {
add_fixed_field(tree, tvb, offset + 16, FIELD_CAP_INFO);
}
return 16;
case SM_ACTION_DLS_TEARDOWN:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
add_fixed_field(tree, tvb, offset + 1, FIELD_DLS_ACTION_CODE);
add_fixed_field(tree, tvb, offset + 2, FIELD_DST_MAC_ADDR);
add_fixed_field(tree, tvb, offset + 8, FIELD_SRC_MAC_ADDR);
add_fixed_field(tree, tvb, offset + 14, FIELD_REASON_CODE);
return 16;
default:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
return 2;
}
}
static guint
add_ff_action_block_ack(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint start = offset;
switch (tvb_get_guint8(tvb, offset + 1)) {
case BA_ADD_BLOCK_ACK_REQUEST:
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_BLOCK_ACK_ACTION_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, offset, FIELD_BLOCK_ACK_PARAM);
offset += add_fixed_field(tree, tvb, offset, FIELD_BLOCK_ACK_TIMEOUT);
offset += add_fixed_field(tree, tvb, offset, FIELD_BLOCK_ACK_SSC);
break;
case BA_ADD_BLOCK_ACK_RESPONSE:
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_BLOCK_ACK_ACTION_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, offset, FIELD_STATUS_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_BLOCK_ACK_PARAM);
offset += add_fixed_field(tree, tvb, offset, FIELD_BLOCK_ACK_TIMEOUT);
break;
case BA_DELETE_BLOCK_ACK:
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_BLOCK_ACK_ACTION_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_DELBA_PARAM_SET);
offset += add_fixed_field(tree, tvb, offset, FIELD_REASON_CODE);
break;
}
return offset - start;
}
static guint
add_ff_action_public(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint start = offset;
guint32 oui;
guint8 code;
guint8 subtype;
gboolean anqp;
guint8 dialog_token;
guint8 frag;
gboolean more;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_PA_ACTION_CODE);
switch (code) {
case PA_VENDOR_SPECIFIC:
oui = tvb_get_ntoh24(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_oui, tvb, offset, 3, ENC_NA);
offset += 3;
switch (oui) {
case OUI_WFA:
subtype = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Subtype %u", subtype);
offset++;
if (subtype == WFA_SUBTYPE_P2P) {
offset = dissect_wifi_p2p_public_action(g_pinfo, tree, tvb, offset);
}
break;
default:
break;
}
break;
case PA_GAS_INITIAL_REQUEST:
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
offset += dissect_advertisement_protocol(g_pinfo, tree, tvb, offset,
&anqp);
offset += dissect_gas_initial_request(tree, tvb, offset, anqp);
break;
case PA_GAS_INITIAL_RESPONSE:
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, offset, FIELD_STATUS_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_GAS_COMEBACK_DELAY);
offset += dissect_advertisement_protocol(g_pinfo, tree, tvb, offset,
&anqp);
offset += dissect_gas_initial_response(tree, tvb, offset, anqp);
break;
case PA_GAS_COMEBACK_REQUEST:
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
break;
case PA_GAS_COMEBACK_RESPONSE:
dialog_token = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, offset, FIELD_STATUS_CODE);
frag = tvb_get_guint8(tvb, offset) & 0x7f;
more = (tvb_get_guint8(tvb, offset) & 0x80) != 0;
offset += add_fixed_field(tree, tvb, offset, FIELD_GAS_FRAGMENT_ID);
offset += add_fixed_field(tree, tvb, offset, FIELD_GAS_COMEBACK_DELAY);
offset += dissect_advertisement_protocol(g_pinfo, tree, tvb, offset,
&anqp);
offset += dissect_gas_comeback_response(tree, tvb, offset, anqp, frag,
more, dialog_token);
break;
case PA_TDLS_DISCOVERY_RESPONSE:
col_set_str(g_pinfo->cinfo, COL_PROTOCOL, "TDLS");
col_set_str(g_pinfo->cinfo, COL_INFO, "TDLS Discovery Response");
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, offset, FIELD_CAP_INFO);
break;
}
return offset - start;
}
static guint
add_ff_action_fast_bss_transition(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint start = offset;
guint8 code;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_FT_ACTION_CODE);
switch (code) {
case FT_ACTION_REQUEST:
offset += add_fixed_field(tree, tvb, offset, FIELD_STA_ADDRESS);
offset += add_fixed_field(tree, tvb, offset, FIELD_TARGET_AP_ADDRESS);
break;
case FT_ACTION_RESPONSE:
offset += add_fixed_field(tree, tvb, offset, FIELD_STA_ADDRESS);
offset += add_fixed_field(tree, tvb, offset, FIELD_TARGET_AP_ADDRESS);
offset += add_fixed_field(tree, tvb, offset, FIELD_STATUS_CODE);
break;
case FT_ACTION_CONFIRM:
offset += add_fixed_field(tree, tvb, offset, FIELD_STA_ADDRESS);
offset += add_fixed_field(tree, tvb, offset, FIELD_TARGET_AP_ADDRESS);
break;
case FT_ACTION_ACK:
offset += add_fixed_field(tree, tvb, offset, FIELD_STA_ADDRESS);
offset += add_fixed_field(tree, tvb, offset, FIELD_TARGET_AP_ADDRESS);
offset += add_fixed_field(tree, tvb, offset, FIELD_STATUS_CODE);
break;
}
return offset - start;
}
static guint
add_ff_action_sa_query(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint start = offset;
guint8 code;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_SA_QUERY_ACTION_CODE);
switch (code) {
case SA_QUERY_REQUEST:
offset += add_fixed_field(tree, tvb, offset, FIELD_TRANSACTION_ID);
break;
case SA_QUERY_RESPONSE:
offset += add_fixed_field(tree, tvb, offset, FIELD_TRANSACTION_ID);
break;
}
return offset - start;
}
static guint
add_ff_action_mesh(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint length;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_MESH_ACTION);
length = 2;
if (tvb_get_guint8(tvb, 1) == MESH_ACTION_TBTT_ADJ_RESPONSE) {
length += add_fixed_field(tree, tvb, offset, FIELD_STATUS_CODE);
}
return length;
}
static guint
add_ff_action_multihop(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint start = offset;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_MULTIHOP_ACTION);
offset += add_fixed_field(tree, tvb, offset, FIELD_MESH_CONTROL);
return offset - start;
}
static guint
add_ff_action_self_protected(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint start = offset;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_SELFPROT_ACTION);
switch (tvb_get_guint8(tvb, start + 1)) {
case SELFPROT_ACTION_MESH_PEERING_OPEN:
offset += add_fixed_field(tree, tvb, offset, FIELD_CAP_INFO);
break;
case SELFPROT_ACTION_MESH_PEERING_CONFIRM:
offset += add_fixed_field(tree, tvb, offset, FIELD_CAP_INFO);
offset += add_fixed_field(tree, tvb, offset, FIELD_ASSOC_ID);
break;
}
return offset - start;
}
static guint
wnm_bss_trans_mgmt_req(proto_tree *tree, tvbuff_t *tvb, int offset)
{
int start = offset;
guint8 mode;
gint left;
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
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
offset++;
proto_tree_add_item(tree, hf_ieee80211_ff_disassoc_timer, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_ff_validity_interval, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset++;
if (mode & 0x08) {
proto_tree_add_text(tree, tvb, offset, 8, "BSS Termination Duration");
offset += 8;
}
if (mode & 0x10) {
guint8 url_len;
url_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_ff_url_len, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_ff_url, tvb, offset, url_len,
ENC_ASCII|ENC_NA);
offset += url_len;
}
left = tvb_reported_length_remaining(tvb, offset);
if (left > 0) {
proto_tree_add_text(tree, tvb, offset, left,
"BSS Transition Candidate List Entries");
offset += left;
}
return offset - start;
}
static guint
add_ff_action_wnm(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 code;
guint start = offset;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_WNM_ACTION_CODE);
switch (code) {
case WNM_BSS_TRANS_MGMT_REQ:
offset += wnm_bss_trans_mgmt_req(tree, tvb, offset);
break;
}
return offset - start;
}
static guint
add_ff_action_tdls(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 code;
guint16 status;
guint start = offset;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
code = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_TDLS_ACTION_CODE);
switch (code) {
case TDLS_SETUP_REQUEST:
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, offset, FIELD_CAP_INFO);
break;
case TDLS_SETUP_RESPONSE:
status = tvb_get_letohs(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_STATUS_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
if (tvb_reported_length_remaining(tvb, offset) < 2) {
if (status == 0) {
expert_add_info_format(g_pinfo, tree, PI_MALFORMED, PI_ERROR,
"TDLS Setup Response (success) does not "
"include mandatory fields");
}
break;
}
offset += add_fixed_field(tree, tvb, offset, FIELD_CAP_INFO);
break;
case TDLS_SETUP_CONFIRM:
status = tvb_get_letohs(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_STATUS_CODE);
if (tvb_reported_length_remaining(tvb, offset) < 1) {
if (status == 0) {
expert_add_info_format(g_pinfo, tree, PI_MALFORMED, PI_ERROR,
"TDLS Setup Confirm (success) does not include "
"mandatory fields");
}
break;
}
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
break;
case TDLS_TEARDOWN:
offset += add_fixed_field(tree, tvb, offset, FIELD_REASON_CODE);
break;
case TDLS_PEER_TRAFFIC_INDICATION:
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
break;
case TDLS_CHANNEL_SWITCH_REQUEST:
offset += add_fixed_field(tree, tvb, offset, FIELD_TARGET_CHANNEL);
offset += add_fixed_field(tree, tvb, offset, FIELD_REGULATORY_CLASS);
break;
case TDLS_CHANNEL_SWITCH_RESPONSE:
offset += add_fixed_field(tree, tvb, offset, FIELD_STATUS_CODE);
break;
case TDLS_PEER_PSM_REQUEST:
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
break;
case TDLS_PEER_PSM_RESPONSE:
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, offset, FIELD_STATUS_CODE);
break;
case TDLS_PEER_TRAFFIC_RESPONSE:
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
break;
case TDLS_DISCOVERY_REQUEST:
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
break;
}
return offset - start;
}
static guint
add_ff_action_mgmt_notification(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint start = offset;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_WME_ACTION_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_DIALOG_TOKEN);
offset += add_fixed_field(tree, tvb, offset, FIELD_WME_STATUS_CODE);
return offset - start;
}
static guint
add_ff_action_vendor_specific(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint start = offset;
guint32 oui;
guint8 subtype;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
oui = tvb_get_ntoh24(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_oui, tvb, offset, 3, ENC_NA);
offset +=3;
switch (oui) {
case OUI_MARVELL:
offset = dissect_vendor_action_marvell(tree, tvb, offset);
break;
case OUI_WFA:
subtype = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Subtype %u", subtype);
offset++;
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
add_ff_action_ht(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint start = offset;
guint8 n_sta, i;
mimo_control_t mimo_cntrl;
offset += add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
offset += add_fixed_field(tree, tvb, offset, FIELD_HT_ACTION_CODE);
switch (tvb_get_guint8(tvb, offset - 1)) {
case HT_ACTION_NOTIFY_CHAN_WIDTH:
offset += add_fixed_field(tree, tvb, offset, FIELD_CHANNEL_WIDTH);
break;
case HT_ACTION_SM_PWR_SAVE:
offset += add_fixed_field(tree, tvb, offset, FIELD_SM_PWR_CNTRL);
break;
case HT_ACTION_PSMP_ACTION:
n_sta = tvb_get_guint8(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_PSMP_PARAM_SET);
for (i = 0; i < (n_sta & 0x0F); i++) {
offset += add_fixed_field(tree, tvb, offset, FIELD_PSMP_STA_INFO);
}
break;
case HT_ACTION_SET_PCO_PHASE:
offset += add_fixed_field(tree, tvb, offset, FIELD_PCO_PHASE_CNTRL);
break;
case HT_ACTION_MIMO_CSI:
mimo_cntrl = get_mimo_control(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_MIMO_CNTRL);
offset += add_mimo_csi_matrices_report(tree, tvb, offset, mimo_cntrl);
break;
case HT_ACTION_MIMO_BEAMFORMING:
mimo_cntrl = get_mimo_control(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_MIMO_CNTRL);
offset += add_mimo_beamforming_feedback_report(tree, tvb, offset,
mimo_cntrl);
break;
case HT_ACTION_MIMO_COMPRESSED_BEAMFORMING:
mimo_cntrl = get_mimo_control(tvb, offset);
offset += add_fixed_field(tree, tvb, offset, FIELD_MIMO_CNTRL);
offset += add_mimo_compressed_beamforming_feedback_report(tree, tvb,
offset,
mimo_cntrl);
break;
case HT_ACTION_ANT_SEL_FEEDBACK:
offset += add_fixed_field(tree, tvb, offset, FIELD_ANT_SELECTION);
break;
case HT_ACTION_HT_INFO_EXCHANGE:
offset += add_fixed_field(tree, tvb, offset, FIELD_HT_INFORMATION);
break;
}
return offset - start;
}
static guint
add_ff_action(proto_tree *tree, tvbuff_t *tvb, int offset)
{
switch (tvb_get_guint8(tvb, offset) & 0x7f) {
case CAT_SPECTRUM_MGMT:
return add_ff_action_spectrum_mgmt(tree, tvb, offset);
case CAT_QOS:
return add_ff_action_qos(tree, tvb, offset);
case CAT_DLS:
return add_ff_action_dls(tree, tvb, offset);
case CAT_BLOCK_ACK:
return add_ff_action_block_ack(tree, tvb, offset);
case CAT_PUBLIC:
return add_ff_action_public(tree, tvb, offset);
case CAT_FAST_BSS_TRANSITION:
return add_ff_action_fast_bss_transition(tree, tvb, offset);
case CAT_SA_QUERY:
return add_ff_action_sa_query(tree, tvb, offset);
case CAT_MESH:
return add_ff_action_mesh(tree, tvb, offset);
case CAT_MULTIHOP:
return add_ff_action_multihop(tree, tvb, offset);
case CAT_SELF_PROTECTED:
return add_ff_action_self_protected(tree, tvb, offset);
case CAT_WNM:
return add_ff_action_wnm(tree, tvb, offset);
case CAT_TDLS:
return add_ff_action_tdls(tree, tvb, offset);
case CAT_MGMT_NOTIFICATION:
return add_ff_action_mgmt_notification(tree, tvb, offset);
case CAT_VENDOR_SPECIFIC:
return add_ff_action_vendor_specific(tree, tvb, offset);
case CAT_HT:
return add_ff_action_ht(tree, tvb, offset);
default:
add_fixed_field(tree, tvb, offset, FIELD_CATEGORY_CODE);
return 1;
}
}
static guint
add_ff_ft_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_ft_action_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
return 1;
}
static guint
add_ff_sta_address(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_sta_address, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_target_ap_address(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_target_ap_address, tvb, offset, 6,
ENC_NA);
return 6;
}
static guint
add_ff_gas_comeback_delay(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_gas_comeback_delay, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_gas_fragment_id(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_gas_fragment_id, tvb, offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_ff_more_gas_fragments, tvb, offset, 1,
ENC_BIG_ENDIAN);
return 1;
}
static guint
add_ff_sa_query_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_sa_query_action_code, tvb, offset,
1, ENC_BIG_ENDIAN);
return 1;
}
static guint
add_ff_transaction_id(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_transaction_id, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
return 2;
}
static guint
add_ff_tdls_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 code;
code = tvb_get_guint8(tvb, offset);
col_set_str(g_pinfo->cinfo, COL_INFO,
val_to_str_const(code, tdls_action_codes,
"Unknown TDLS Action"));
proto_tree_add_item(tree, hf_ieee80211_ff_tdls_action_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
return 1;
}
static guint
add_ff_target_channel(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_target_channel, tvb, offset, 1,
ENC_BIG_ENDIAN);
return 1;
}
static guint
add_ff_regulatory_class(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_ieee80211_ff_regulatory_class, tvb, offset, 1,
ENC_BIG_ENDIAN);
return 1;
}
static guint
add_ff_wnm_action_code(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 code;
code = tvb_get_guint8(tvb, offset);
col_set_str(g_pinfo->cinfo, COL_INFO,
val_to_str_const(code, wnm_action_codes,
"Unknown WNM Action"));
proto_tree_add_item(tree, hf_ieee80211_ff_wnm_action_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
return 1;
}
static guint
add_fixed_field(proto_tree *tree, tvbuff_t *tvb, int offset,
enum fixed_field lfcode)
{
int i;
for (i = 0; ff_dissectors[i].dissector; i++) {
if (ff_dissectors[i].lfcode == lfcode) {
return ff_dissectors[i].dissector(tree, tvb, offset);
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
g_snprintf(result, ITEM_LABEL_LENGTH, "%.2x-%.2x-%.2x", p_oui[0], p_oui[1], p_oui[2] );
}
else {
g_snprintf(result, ITEM_LABEL_LENGTH, "%.2x-%.2x-%.2x (%s)", p_oui[0], p_oui[1], p_oui[2], manuf_name );
}
}
static void
rsn_gcs_base_custom(gchar *result, guint32 gcs)
{
gchar *oui_result=NULL;
oui_result = ep_alloc(SHORT_STR);
oui_result[0] = '\0';
oui_base_custom(oui_result, gcs >> 8);
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, val_to_str( gcs & 0xFF, ieee80211_rsn_cipher_vals, "Unknown %d") );
}
static void
rsn_pcs_base_custom(gchar *result, guint32 pcs)
{
gchar *oui_result=NULL;
oui_result = ep_alloc(SHORT_STR);
oui_result[0] = '\0';
oui_base_custom(oui_result, pcs >> 8);
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, val_to_str( pcs & 0xFF, ieee80211_rsn_cipher_vals, "Unknown %d") );
}
static void
rsn_akms_base_custom(gchar *result, guint32 akms)
{
gchar *oui_result=NULL;
oui_result = ep_alloc(SHORT_STR);
oui_result[0] = '\0';
oui_base_custom(oui_result, akms >> 8);
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, val_to_str( akms & 0xFF, ieee80211_rsn_keymgmt_vals, "Unknown %d") );
}
static gchar *
rsn_pcs_return(guint32 pcs)
{
gchar *result=NULL;
result = ep_alloc(SHORT_STR);
result[0] = '\0';
rsn_pcs_base_custom(result, pcs);
return result;
}
static gchar *
rsn_akms_return(guint32 akms)
{
gchar *result=NULL;
result = ep_alloc(SHORT_STR);
result[0] = '\0';
rsn_akms_base_custom(result, akms);
return result;
}
static void
rsn_gmcs_base_custom(gchar *result, guint32 gmcs)
{
gchar *oui_result=NULL;
oui_result = ep_alloc(SHORT_STR);
oui_result[0] = '\0';
oui_base_custom(oui_result, gmcs >> 8);
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, val_to_str( gmcs & 0xFF, ieee80211_rsn_cipher_vals, "Unknown %d") );
}
static void
wpa_mcs_base_custom(gchar *result, guint32 mcs)
{
gchar *oui_result=NULL;
oui_result = ep_alloc(SHORT_STR);
oui_result[0] = '\0';
oui_base_custom(oui_result, mcs >> 8);
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, val_to_str( mcs & 0xFF, ieee80211_wfa_ie_wpa_cipher_vals, "Unknown %d") );
}
static void
wpa_ucs_base_custom(gchar *result, guint32 ucs)
{
gchar *oui_result=NULL;
oui_result = ep_alloc(SHORT_STR);
oui_result[0] = '\0';
oui_base_custom(oui_result, ucs >> 8);
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, val_to_str( ucs & 0xFF, ieee80211_wfa_ie_wpa_cipher_vals, "Unknown %d") );
}
static void
wpa_akms_base_custom(gchar *result, guint32 akms)
{
gchar *oui_result=NULL;
oui_result = ep_alloc(SHORT_STR);
oui_result[0] = '\0';
oui_base_custom(oui_result, akms >> 8);
g_snprintf(result, ITEM_LABEL_LENGTH, "%s %s", oui_result, val_to_str( akms & 0xFF, ieee80211_wfa_ie_wpa_keymgmt_vals, "Unknown %d") );
}
static gchar *
wpa_ucs_return(guint32 ucs)
{
gchar *result=NULL;
result = ep_alloc(SHORT_STR);
result[0] = '\0';
wpa_ucs_base_custom(result, ucs);
return result;
}
static gchar *
wpa_akms_return(guint32 akms)
{
gchar *result=NULL;
result = ep_alloc(SHORT_STR);
result[0] = '\0';
wpa_akms_base_custom(result, akms);
return result;
}
static int dissect_qos_info(proto_tree * tree, tvbuff_t *tvb, int offset, int ftype)
{
proto_tree *qos_info_tree;
proto_item *qos_info_item;
qos_info_item = proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_qos_info, tvb, offset, 1, ENC_NA);
qos_info_tree = proto_item_add_subtree(qos_info_item, ett_wme_qos_info);
switch(ftype){
case MGT_ASSOC_REQ:
case MGT_PROBE_REQ:
case MGT_REASSOC_REQ:
{
proto_tree_add_item(qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_max_sp_length, tvb, offset, 1, ENC_NA);
proto_tree_add_item(qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_be, tvb, offset, 1, ENC_NA);
proto_tree_add_item(qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_bk, tvb, offset, 1, ENC_NA);
proto_tree_add_item(qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_vi, tvb, offset, 1, ENC_NA);
proto_tree_add_item(qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_vo, tvb, offset, 1, ENC_NA);
proto_tree_add_item(qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_sta_reserved, tvb, offset, 1, ENC_NA);
break;
}
case MGT_BEACON:
case MGT_PROBE_RESP:
case MGT_ASSOC_RESP:
case MGT_REASSOC_RESP:
{
proto_tree_add_item(qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_ap_u_apsd, tvb, offset, 1, ENC_NA);
proto_tree_add_item(qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_ap_parameter_set_count, tvb, offset, 1, ENC_NA);
proto_tree_add_item(qos_info_tree, hf_ieee80211_wfa_ie_wme_qos_info_ap_reserved, tvb, offset, 1, ENC_NA);
break;
}
default:
expert_add_info_format(g_pinfo, qos_info_item, PI_UNDECODED, PI_WARN, "Could not deduce direction to decode correctly, ftype %u", ftype);
break;
}
offset += 1;
return offset;
}
static int
dissect_vendor_ie_wpawme(proto_tree * tree, tvbuff_t * tvb, int offset, guint32 tag_len, int ftype)
{
guint8 type;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_type, tvb, offset, 1, ENC_NA);
type = tvb_get_guint8(tvb, offset);
proto_item_append_text(tree, ": %s", val_to_str(type, ieee802111_wfa_ie_type_vals, "Unknown %d" ));
offset += 1;
switch(type){
case 1:
{
proto_item *wpa_mcs_item, *wpa_ucs_item, *wpa_akms_item;
proto_item *wpa_sub_ucs_item, *wpa_sub_akms_item;
proto_tree *wpa_mcs_tree, *wpa_ucs_tree, *wpa_akms_tree;
proto_tree *wpa_sub_ucs_tree, *wpa_sub_akms_tree;
guint16 ucs_count, akms_count;
guint i;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
wpa_mcs_item = proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_mcs, tvb, offset, 4, ENC_BIG_ENDIAN);
wpa_mcs_tree = proto_item_add_subtree(wpa_mcs_item, ett_wpa_mcs_tree);
proto_tree_add_item(wpa_mcs_tree, hf_ieee80211_wfa_ie_wpa_mcs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if(tvb_get_ntoh24(tvb, offset) == 0x0050F2)
{
proto_tree_add_item(wpa_mcs_tree, hf_ieee80211_wfa_ie_wpa_mcs_wfa_type, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(wpa_mcs_tree, hf_ieee80211_wfa_ie_wpa_mcs_type, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
}
offset += 4;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_ucs_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ucs_count = tvb_get_letohs(tvb, offset);
offset += 2;
wpa_ucs_item = proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_ucs_list, tvb, offset, ucs_count * 4, ENC_NA);
wpa_ucs_tree = proto_item_add_subtree(wpa_ucs_item, ett_wpa_ucs_tree);
for(i = 1; i <= ucs_count; i++)
{
wpa_sub_ucs_item = proto_tree_add_item(wpa_ucs_tree, hf_ieee80211_wfa_ie_wpa_ucs, tvb, offset, 4, ENC_BIG_ENDIAN);
wpa_sub_ucs_tree = proto_item_add_subtree(wpa_sub_ucs_item, ett_wpa_sub_ucs_tree);
proto_tree_add_item(wpa_sub_ucs_tree, hf_ieee80211_wfa_ie_wpa_ucs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if(tvb_get_ntoh24(tvb, offset) == 0x0050F2)
{
proto_tree_add_item(wpa_sub_ucs_tree, hf_ieee80211_wfa_ie_wpa_ucs_wfa_type, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(wpa_ucs_item, " %s", wpa_ucs_return(tvb_get_ntohl(tvb, offset)));
} else {
proto_tree_add_item(wpa_sub_ucs_tree, hf_ieee80211_wfa_ie_wpa_ucs_type, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
offset += 4;
}
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_akms_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
akms_count = tvb_get_letohs(tvb, offset);
offset += 2;
wpa_akms_item = proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wpa_akms_list, tvb, offset, akms_count * 4, ENC_NA);
wpa_akms_tree = proto_item_add_subtree(wpa_akms_item, ett_wpa_akms_tree);
for(i = 1; i <= akms_count; i++)
{
wpa_sub_akms_item = proto_tree_add_item(wpa_akms_tree, hf_ieee80211_wfa_ie_wpa_akms, tvb, offset, 4, ENC_BIG_ENDIAN);
wpa_sub_akms_tree = proto_item_add_subtree(wpa_sub_akms_item, ett_wpa_sub_akms_tree);
proto_tree_add_item(wpa_sub_akms_tree, hf_ieee80211_wfa_ie_wpa_akms_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if(tvb_get_ntoh24(tvb, offset) == 0x0050F2)
{
proto_tree_add_item(wpa_sub_akms_tree, hf_ieee80211_wfa_ie_wpa_akms_wfa_type, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(wpa_akms_item, " %s", wpa_akms_return(tvb_get_ntohl(tvb, offset)));
} else {
proto_tree_add_item(wpa_sub_akms_tree, hf_ieee80211_wfa_ie_wpa_akms_type, tvb, offset+3, 1, ENC_BIG_ENDIAN);
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
proto_item_append_text(tree, ": %s", val_to_str(subtype, ieee802111_wfa_ie_wme_type, "Unknown %d" ));
offset += 1;
switch(subtype){
case 0:
{
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_version, tvb, offset, 1, ENC_NA);
offset += 1;
offset = dissect_qos_info(tree, tvb, offset, ftype);
break;
}
case 1:
{
int i;
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_version, tvb, offset, 1, ENC_NA);
offset += 1;
offset = dissect_qos_info(tree, tvb, offset, ftype);
proto_tree_add_item(tree, hf_ieee80211_wfa_ie_wme_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
for(i = 0; i < 4; i++)
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
(aci_aifsn & 0x60) >> 5, match_strval((aci_aifsn & 0x60) >> 5, ieee80211_wfa_ie_wme_acs_vals),
(aci_aifsn & 0x10) ? "yes" : "no ", aci_aifsn & 0x0f);
offset += 1;
ecw_item = proto_tree_add_item(ac_tree, hf_ieee80211_wfa_ie_wme_acp_ecw, tvb, offset, 1, ENC_NA);
ecw_tree = proto_item_add_subtree(ecw_item, ett_wme_ecw);
proto_tree_add_item(ecw_tree, hf_ieee80211_wfa_ie_wme_acp_ecw_max, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ecw_tree, hf_ieee80211_wfa_ie_wme_acp_ecw_min, tvb, offset, 1, ENC_NA);
ecw = tvb_get_guint8(tvb, offset);
proto_item_append_text(ac_item, ", ECWmin %u ,ECWmax %u", ecw & 0x0f, (ecw & 0xf0) >> 4 );
offset += 1;
proto_tree_add_item(ac_tree, hf_ieee80211_wfa_ie_wme_acp_txop_limit, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(ac_item, ", TXOP %u", tvb_get_letohs(tvb, offset));
offset += 2;
}
break;
}
case 3:
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
dissect_wps_tlvs(tree, tvb, offset, tag_len-4, NULL);
}
break;
default:
break;
}
return offset;
}
static void
dissect_vendor_ie_wfa(packet_info *pinfo, proto_item *item, tvbuff_t *tag_tvb)
{
gint tag_len = tvb_length(tag_tvb);
if (tag_len < 4)
return;
switch (tvb_get_guint8(tag_tvb, 3)) {
case WFA_SUBTYPE_P2P:
dissect_wifi_p2p_ie(pinfo, item, tag_tvb, 4, tag_len - 4);
proto_item_append_text(item, ": P2P");
break;
}
}
static void
dissect_vendor_ie_rsn(proto_item * item, proto_tree * tree, tvbuff_t * tag_tvb)
{
guint tag_off = 0;
guint tag_len = tvb_length(tag_tvb);
guint pmkid_len = tag_len - 4;
char out_buff[SHORT_STR], valid_str[SHORT_STR] = "";
if (tag_len >= 4 && !tvb_memeql(tag_tvb, tag_off, RSN_OUI"\x04", 4)) {
if (pmkid_len != PMKID_LEN) {
g_snprintf(valid_str, SHORT_STR,
"(invalid PMKID len=%d, expected 16) ", pmkid_len);
}
g_snprintf(out_buff, SHORT_STR, "RSN PMKID: %s%s", valid_str,
tvb_bytes_to_str(tag_tvb, 4, pmkid_len));
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tag_tvb, 0,
tag_len, out_buff);
}
proto_item_append_text(item, ": RSN");
}
static void
dissect_vendor_ie_marvell(proto_item * item _U_, proto_tree * ietree,
tvbuff_t * tvb, int offset, guint32 tag_len)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (type) {
case MARVELL_IE_MESH:
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_mesh_subtype, tvb,
offset++, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_mesh_version, tvb,
offset++, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_mesh_active_proto_id, tvb,
offset++, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_mesh_active_metric_id, tvb,
offset++, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item (ietree, hf_ieee80211_marvell_ie_mesh_cap, tvb,
offset++, 1, ENC_LITTLE_ENDIAN );
break;
default:
proto_tree_add_item(ietree, hf_ieee80211_marvell_ie_data, tvb, offset,
tag_len - 1, ENC_NA);
break;
}
}
static void
dissect_vendor_ie_atheros_cap(proto_item * item _U_, tvbuff_t *tvb, int offset)
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
dissect_vendor_ie_atheros(proto_item * item _U_, proto_tree * ietree,
tvbuff_t * tvb, int offset, guint tag_len,
packet_info * pinfo, proto_item *ti_len)
{
guint8 type;
guint8 subtype;
guint8 version;
proto_item *cap_item;
proto_item *ti;
if (tag_len <= 3) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag length %u too short, must be >= 6", tag_len+3);
return;
}
proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_type, tvb, offset, 1, ENC_NA);
type = tvb_get_guint8(tvb, offset);
proto_item_append_text(item, ": %s", val_to_str(type, atheros_ie_type_vals, "Unknown"));
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
if(version == 0)
{
switch(type){
case ATHEROS_IE_ADVCAP:
{
switch(subtype){
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
switch(subtype){
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
if(tag_len > 0 ){
ti = proto_tree_add_item(ietree, hf_ieee80211_atheros_ie_data, tvb, offset, tag_len, ENC_NA);
expert_add_info_format(pinfo, ti, PI_UNDECODED, PI_WARN, "Unknown Data (not interpreted)");
}
}
static void
dissect_vendor_ie_aironet(proto_item * aironet_item, proto_tree * ietree,
tvbuff_t * tvb, int offset, guint32 tag_len)
{
guint8 type;
int i;
gboolean dont_change = FALSE;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item (ietree, hf_ieee80211_aironet_ie_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (type) {
case AIRONET_IE_VERSION:
proto_tree_add_item (ietree, hf_ieee80211_aironet_ie_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(aironet_item, ": Aironet CCX version = %d",
tvb_get_guint8(tvb, offset));
dont_change = TRUE;
break;
case AIRONET_IE_QOS:
proto_tree_add_item (ietree, hf_ieee80211_aironet_ie_qos_unk1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
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
"CCX QoS Parameters??: ACI %u (%s), Admission Control %sMandatory, AIFSN %u, ECWmin %u, ECWmax %u, TXOP %u",
(byte1 & 0x60) >> 5, val_to_str((byte1 & 0x60) >> 5, wme_acs, "(Unknown: %d)"),
(byte1 & 0x10) ? "" : "not ", byte1 & 0x0f,
byte2 & 0x0f, (byte2 & 0xf0) >> 4,
txop);
offset += 4;
}
break;
case AIRONET_IE_QBSS_V2:
proto_tree_add_item (ietree, hf_ieee80211_qbss2_scount, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ietree, hf_ieee80211_qbss2_cu, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (ietree, hf_ieee80211_qbss2_cal, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (ietree, hf_ieee80211_qbss2_gl, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(ietree, hf_ieee80211_aironet_ie_data, tvb, offset,
tag_len - 1, ENC_NA);
break;
}
if (!dont_change) {
proto_item_append_text(aironet_item, ": Aironet %s",
val_to_str(type, aironet_ie_type_vals, "Unknown"));
}
}
static int dissect_qos_capability(proto_tree * tree, tvbuff_t * tvb, int offset, int ftype)
{
proto_item *cap_info_item;
proto_tree *cap_info_tree;
cap_info_item = proto_tree_add_item(tree, hf_ieee80211_tag_qos_cap_qos_info, tvb, offset, 1, ENC_NA);
cap_info_tree = proto_item_add_subtree(cap_info_item, ett_qos_info_field_tree);
switch(ftype){
case MGT_ASSOC_REQ:
case MGT_PROBE_REQ:
case MGT_REASSOC_REQ:
{
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_vo_uapsd, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_vi_uapsd, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_bk_uapsd, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_be_uapsd, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_qack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_max_sp_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_more_data_ack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
}
case MGT_BEACON:
case MGT_PROBE_RESP:
case MGT_ASSOC_RESP:
case MGT_REASSOC_RESP:
{
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_edca_upd_cnt, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_qack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_queue_req, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_txop_req, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_info_tree, hf_ieee80211_qos_info_field_reserved, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
}
default:
expert_add_info_format(g_pinfo, cap_info_item, PI_UNDECODED, PI_WARN, "Could not deduce direction to decode correctly, ftype %u", ftype);
break;
}
return offset + 1;
}
static int
dissect_rsn_ie(packet_info * pinfo, proto_tree * tree, tvbuff_t * tvb,
int offset, guint32 tag_len)
{
proto_item *rsn_gcs_item, *rsn_pcs_item, *rsn_akms_item, *rsn_cap_item, *rsn_pmkid_item, *rsn_gmcs_item;
proto_item *rsn_sub_pcs_item, *rsn_sub_akms_item;
proto_item *rsn_pcs_count, *rsn_akms_count, *rsn_pmkid_count;
proto_tree *rsn_gcs_tree, *rsn_pcs_tree, *rsn_akms_tree, *rsn_cap_tree, *rsn_pmkid_tree, *rsn_gmcs_tree;
proto_tree *rsn_sub_pcs_tree, *rsn_sub_akms_tree;
guint16 pcs_count, akms_count, pmkid_count;
guint i;
int tag_end = offset + tag_len;
proto_tree_add_item(tree, hf_ieee80211_rsn_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
rsn_gcs_item = proto_tree_add_item(tree, hf_ieee80211_rsn_gcs, tvb, offset, 4, ENC_BIG_ENDIAN);
rsn_gcs_tree = proto_item_add_subtree(rsn_gcs_item, ett_rsn_gcs_tree);
proto_tree_add_item(rsn_gcs_tree, hf_ieee80211_rsn_gcs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if(tvb_get_ntoh24(tvb, offset) == 0x000FAC)
{
proto_tree_add_item(rsn_gcs_tree, hf_ieee80211_rsn_gcs_80211_type, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(rsn_gcs_tree, hf_ieee80211_rsn_gcs_type, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
}
offset += 4;
rsn_pcs_count = proto_tree_add_item(tree, hf_ieee80211_rsn_pcs_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
pcs_count = tvb_get_letohs(tvb, offset);
offset += 2;
if (offset + (pcs_count * 4) > tag_end)
{
expert_add_info_format(pinfo, rsn_pcs_count, PI_MALFORMED, PI_ERROR,
"Pairwise Cipher Suite Count too large, 4*%u > %d", pcs_count, tag_end - offset);
pcs_count = (tag_end - offset) / 4;
}
rsn_pcs_item = proto_tree_add_item(tree, hf_ieee80211_rsn_pcs_list, tvb, offset, pcs_count * 4, ENC_NA);
rsn_pcs_tree = proto_item_add_subtree(rsn_pcs_item, ett_rsn_pcs_tree);
for(i = 1; i <= pcs_count; i++)
{
rsn_sub_pcs_item = proto_tree_add_item(rsn_pcs_tree, hf_ieee80211_rsn_pcs, tvb, offset, 4, ENC_BIG_ENDIAN);
rsn_sub_pcs_tree = proto_item_add_subtree(rsn_sub_pcs_item, ett_rsn_sub_pcs_tree);
proto_tree_add_item(rsn_sub_pcs_tree, hf_ieee80211_rsn_pcs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if(tvb_get_ntoh24(tvb, offset) == 0x000FAC)
{
proto_tree_add_item(rsn_sub_pcs_tree, hf_ieee80211_rsn_pcs_80211_type, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(rsn_pcs_item, " %s", rsn_pcs_return(tvb_get_ntohl(tvb, offset)));
} else {
proto_tree_add_item(rsn_sub_pcs_tree, hf_ieee80211_rsn_pcs_type, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
offset += 4;
}
if(offset >= tag_end)
{
return offset;
}
rsn_akms_count = proto_tree_add_item(tree, hf_ieee80211_rsn_akms_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
akms_count = tvb_get_letohs(tvb, offset);
offset += 2;
if (offset + (akms_count * 4) > tag_end)
{
expert_add_info_format(pinfo, rsn_akms_count, PI_MALFORMED, PI_ERROR,
"Auth Key Management (AKM) Suite Count too large, 4*%u > %d", akms_count, tag_end - offset);
akms_count = (tag_end - offset) / 4;
}
rsn_akms_item = proto_tree_add_item(tree, hf_ieee80211_rsn_akms_list, tvb, offset, akms_count * 4, ENC_NA);
rsn_akms_tree = proto_item_add_subtree(rsn_akms_item, ett_rsn_akms_tree);
for(i = 1; i <= akms_count; i++)
{
rsn_sub_akms_item = proto_tree_add_item(rsn_akms_tree, hf_ieee80211_rsn_akms, tvb, offset, 4, ENC_BIG_ENDIAN);
rsn_sub_akms_tree = proto_item_add_subtree(rsn_sub_akms_item, ett_rsn_sub_akms_tree);
proto_tree_add_item(rsn_sub_akms_tree, hf_ieee80211_rsn_akms_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if(tvb_get_ntoh24(tvb, offset) == 0x000FAC)
{
proto_tree_add_item(rsn_sub_akms_tree, hf_ieee80211_rsn_akms_80211_type, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(rsn_akms_item, " %s", rsn_akms_return(tvb_get_ntohl(tvb, offset)));
} else {
proto_tree_add_item(rsn_sub_akms_tree, hf_ieee80211_rsn_akms_type, tvb, offset+3, 1, ENC_BIG_ENDIAN);
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
proto_tree_add_item(rsn_cap_tree, hf_ieee80211_rsn_cap_peerkey, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if(offset >= tag_end)
{
return offset;
}
rsn_pmkid_count = proto_tree_add_item(tree, hf_ieee80211_rsn_pmkid_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
pmkid_count = tvb_get_letohs(tvb, offset);
offset += 2;
if (offset + (pmkid_count * 16) > tag_end)
{
expert_add_info_format(pinfo, rsn_pmkid_count, PI_MALFORMED, PI_ERROR,
"PMKID Count too large, 16*%u > %d", pmkid_count, tag_end - offset);
pmkid_count = (tag_end - offset) / 16;
}
rsn_pmkid_item = proto_tree_add_item(tree, hf_ieee80211_rsn_pmkid_list, tvb, offset, pmkid_count * 16, ENC_NA);
rsn_pmkid_tree = proto_item_add_subtree(rsn_pmkid_item, ett_rsn_pmkid_tree);
for(i = 1; i <= pmkid_count; i++)
{
proto_tree_add_item(rsn_pmkid_tree, hf_ieee80211_rsn_pmkid, tvb, offset, 16, ENC_NA);
offset +=16;
}
if(offset >= tag_end)
{
return offset;
}
rsn_gmcs_item = proto_tree_add_item(tree, hf_ieee80211_rsn_gmcs, tvb, offset, 4, ENC_BIG_ENDIAN);
rsn_gmcs_tree = proto_item_add_subtree(rsn_gmcs_item, ett_rsn_gmcs_tree);
proto_tree_add_item(rsn_gmcs_tree, hf_ieee80211_rsn_gmcs_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
if(tvb_get_ntoh24(tvb, offset) == 0x000FAC)
{
proto_tree_add_item(rsn_gmcs_tree, hf_ieee80211_rsn_gmcs_80211_type, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(rsn_gmcs_tree, hf_ieee80211_rsn_gmcs_type, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
}
offset += 4;
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
tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_mobility_domain_ft_capab_ft_over_ds,
tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_mobility_domain_ft_capab_resource_req,
tvb, offset + 2, 1, ENC_BIG_ENDIAN);
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
tvb, offset, 1, ENC_BIG_ENDIAN);
id = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_ft_subelem_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
len = tvb_get_guint8(tvb, offset);
offset++;
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
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
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
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
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
offset, 1, ENC_BIG_ENDIAN);
offset++;
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
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pu_buffer_status_ac_be, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pu_buffer_status_ac_vi, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_pu_buffer_status_ac_vo, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_timeout_interval(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
proto_item *pi;
pi = proto_tree_add_item(tree, hf_ieee80211_tag_timeout_int_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (tag_len < 5) {
expert_add_info_format(g_pinfo, pi, PI_MALFORMED, PI_ERROR,
"Timeout Interval content length must be at least "
"5 bytes");
return;
}
proto_tree_add_item(tree, hf_ieee80211_tag_timeout_int_value, tvb,
offset + 1, 4, ENC_LITTLE_ENDIAN);
}
static int
dissect_mcs_set(proto_tree *tree, tvbuff_t *tvb, int offset, gboolean basic, gboolean vs) {
proto_item *ti;
proto_tree *mcs_tree, *bit_tree;
if(vs)
{
ti = proto_tree_add_string(tree, hf_ieee80211_mcsset_vs, tvb, offset, 16,
basic ? "Basic MCS Set" : "MCS Set");
}else
{
ti = proto_tree_add_string(tree, hf_ieee80211_mcsset, tvb, offset, 16,
basic ? "Basic MCS Set" : "MCS Set");
}
mcs_tree = proto_item_add_subtree(ti, ett_mcsset_tree);
ti = proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_rx_bitmask, tvb, offset, 10, ENC_NA);
bit_tree = proto_item_add_subtree(ti, ett_mcsbit_tree);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_0to7, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_8to15, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_16to23, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_24to31, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_32, tvb, offset , 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_33to38, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_39to52, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(bit_tree, hf_ieee80211_mcsset_rx_bitmask_53to76, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_highest_data_rate, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_tx_mcs_set_defined, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_tx_rx_mcs_set_not_equal, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcs_tree, hf_ieee80211_mcsset_tx_max_spatial_streams, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
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
static int dissect_time_adv(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 capab;
proto_item *item;
proto_tree *subtree;
struct tm tm, *now;
time_t t;
capab = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_tag_time_adv_timing_capab,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
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
offset++;
tm.tm_mday = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_day,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
tm.tm_hour = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_hours,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
tm.tm_min = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_minutes,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
tm.tm_sec = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_seconds,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree,
hf_ieee80211_tag_time_adv_time_value_milliseconds,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_ieee80211_tag_time_adv_time_value_reserved,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
tm.tm_isdst = -1;
t = mktime(&tm);
if (t != -1) {
t += last_timestamp / 1000000;
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
offset++;
break;
}
return offset;
}
static int dissect_time_zone(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 tag_len)
{
proto_tree_add_item(tree, hf_ieee80211_tag_time_zone, tvb, offset, tag_len,
ENC_ASCII|ENC_NA);
return offset + tag_len;
}
static int
dissect_ap_channel_report(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len, int tag_end, proto_item *ti)
{
if (tag_len < 1) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"AP Channel Report length %u wrong, must be > 1", tag_len);
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_ap_channel_report_regulatory_class, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": Regulatory Class %u, Channel List :", tvb_get_guint8(tvb, offset) );
offset += 1;
while(offset < tag_end)
{
proto_tree_add_item(tree, hf_ieee80211_tag_ap_channel_report_channel_list, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti, " %u,", tvb_get_guint8(tvb, offset) );
offset += 1;
}
return offset;
}
static int
dissect_secondary_channel_offset_ie(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint32 tag_len, proto_item *ti_len)
{
if (tag_len != 1) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"Secondary Channel Offset length %u wrong, must be = 1", tag_len);
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_secondary_channel_offset, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_ht_capability_ie(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
guint32 tag_len, proto_item *ti_len, gboolean vs )
{
proto_item *cap_item, *ti;
proto_tree *cap_tree;
if (tag_len != 26) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"HT Capability IE length %u wrong, must be = 26", tag_len);
return offset;
}
if (wlan_ignore_draft_ht && vs)
return offset;
if(vs)
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_ht_vs_cap, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
else
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_ht_cap, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
cap_tree = proto_item_add_subtree(cap_item, ett_ht_cap_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_ldpc_coding, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_chan_width, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_sm_pwsave, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_green, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_short20, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_short40, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_tx_stbc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(cap_tree, hf_ieee80211_ht_rx_stbc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_delayed_block_ack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_max_amsdu, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_dss_cck_40, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_psmp, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_40_mhz_intolerant, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ht_l_sig, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if(vs)
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_ampduparam_vs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}else
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_ampduparam, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
cap_tree = proto_item_add_subtree(cap_item, ett_ampduparam_tree);
ti = proto_tree_add_item(cap_tree, hf_ieee80211_ampduparam_mpdu, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%04.0f[Bytes])",pow(2,13+(tvb_get_guint8(tvb, offset) & 0x3))-1);
proto_tree_add_item(cap_tree, hf_ieee80211_ampduparam_mpdu_start_spacing, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_ampduparam_reserved, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset = dissect_mcs_set(tree, tvb, offset, FALSE, vs);
if(vs)
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_htex_vs_cap, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
cap_item = proto_tree_add_item(tree, hf_ieee80211_htex_cap, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
cap_tree = proto_item_add_subtree(cap_item, ett_htex_cap_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_htex_pco, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_htex_transtime, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(cap_tree, hf_ieee80211_htex_mcs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_htex_htc_support, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_htex_rd_responder, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if(vs)
{
cap_item = proto_tree_add_item(tree, hf_ieee80211_txbf_vs, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
cap_item = proto_tree_add_item(tree, hf_ieee80211_txbf, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
cap_tree = proto_item_add_subtree(cap_item, ett_txbf_tree);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_cap, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_rcv_ssc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_tx_ssc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_rcv_ndp, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_tx_ndp, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_impl_txbf, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_calib, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset +=1;
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_csi, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_uncomp_fm, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_comp_fm, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_bf_csi, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_uncomp_fm_feed, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_expl_comp_fm_feed, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=1;
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_min_group, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_csi_num_bf_ant, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_uncomp_sm_bf_ant, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_comp_sm_bf_ant, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_csi_max_rows_bf, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_chan_est, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_ieee80211_txbf_resrv, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if(vs)
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
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
proto_tree_add_boolean(cap_tree, hf_ieee80211_hta_pco_phase, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_mcs_set(tree, tvb, offset, FALSE, TRUE);
return offset;
}
static void
dissect_ht_control(proto_tree *tree, tvbuff_t * tvb, int offset)
{
proto_item *ti;
proto_tree *htc_tree, *lac_subtree;
guint16 htc;
htc = tvb_get_letohs(tvb, offset);
ti = proto_tree_add_item(tree, hf_ieee80211_htc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
htc_tree = proto_item_add_subtree(ti, ett_htc_tree);
ti = proto_tree_add_item(htc_tree, hf_ieee80211_htc_lac, tvb, offset, 2, ENC_LITTLE_ENDIAN);
lac_subtree = proto_item_add_subtree(ti, ett_htc_tree);
proto_tree_add_boolean(lac_subtree, hf_ieee80211_htc_lac_reserved, tvb, offset, 1, htc);
proto_tree_add_boolean(lac_subtree, hf_ieee80211_htc_lac_trq, tvb, offset, 1, htc);
if (HTC_IS_ASELI(htc)) {
proto_tree_add_uint(lac_subtree, hf_ieee80211_htc_lac_mai_aseli, tvb, offset, 1, htc);
} else {
proto_tree_add_boolean(lac_subtree, hf_ieee80211_htc_lac_mai_mrq, tvb, offset, 1, htc);
if (HTC_LAC_MAI_MRQ(htc)){
proto_tree_add_uint(lac_subtree, hf_ieee80211_htc_lac_mai_msi, tvb, offset, 1, htc);
} else {
proto_tree_add_uint(lac_subtree, hf_ieee80211_htc_lac_mai_reserved, tvb, offset, 1, htc);
}
}
proto_tree_add_uint(lac_subtree, hf_ieee80211_htc_lac_mfsi, tvb, offset, 2, htc);
offset++;
if (HTC_IS_ASELI(htc)) {
proto_tree_add_uint(lac_subtree, hf_ieee80211_htc_lac_asel_command, tvb, offset, 1, htc);
proto_tree_add_uint(lac_subtree, hf_ieee80211_htc_lac_asel_data, tvb, offset, 1, htc);
} else {
proto_tree_add_uint(lac_subtree, hf_ieee80211_htc_lac_mfb, tvb, offset, 1, htc);
}
offset++;
htc = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(htc_tree, hf_ieee80211_htc_cal_pos, tvb, offset, 1, htc);
proto_tree_add_uint(htc_tree, hf_ieee80211_htc_cal_seq, tvb, offset, 1, htc);
proto_tree_add_uint(htc_tree, hf_ieee80211_htc_reserved1, tvb, offset, 1, htc);
proto_tree_add_uint(htc_tree, hf_ieee80211_htc_csi_steering, tvb, offset, 1, htc);
offset++;
proto_tree_add_boolean(htc_tree, hf_ieee80211_htc_ndp_announcement, tvb, offset, 1, htc);
proto_tree_add_uint(htc_tree, hf_ieee80211_htc_reserved2, tvb, offset, 1, htc);
proto_tree_add_boolean(htc_tree, hf_ieee80211_htc_ac_constraint, tvb, offset, 1, htc);
proto_tree_add_boolean(htc_tree, hf_ieee80211_htc_rdg_more_ppdu, tvb, offset, 1, htc);
}
static void
dissect_frame_control(proto_tree * tree, tvbuff_t * tvb, gboolean wlan_broken_fc,
guint32 offset)
{
guint16 fcf, flags, frame_type_subtype;
proto_tree *fc_tree, *flag_tree;
proto_item *fc_item, *flag_item, *hidden_item;
fcf = FETCH_FCF(offset);
flags = FCF_FLAGS(fcf);
frame_type_subtype = COMPOSE_FRAME_TYPE(fcf);
proto_tree_add_uint (tree, hf_ieee80211_fc_frame_type_subtype,
tvb, wlan_broken_fc?offset+1:offset, 1,
frame_type_subtype);
fc_item = proto_tree_add_uint_format (tree, hf_ieee80211_fc_field, tvb,
offset, 2, fcf, "Frame Control: 0x%04X (%s)",
fcf, wlan_broken_fc?"Swapped":"Normal");
fc_tree = proto_item_add_subtree (fc_item, ett_fc_tree);
proto_tree_add_uint (fc_tree, hf_ieee80211_fc_proto_version, tvb, wlan_broken_fc?offset+1:offset, 1,
FCF_PROT_VERSION (fcf));
proto_tree_add_uint (fc_tree, hf_ieee80211_fc_frame_type, tvb, wlan_broken_fc?offset+1:offset, 1,
FCF_FRAME_TYPE (fcf));
proto_tree_add_uint (fc_tree, hf_ieee80211_fc_frame_subtype, tvb, wlan_broken_fc?offset+1:offset, 1,
FCF_FRAME_SUBTYPE (fcf));
flag_item = proto_tree_add_uint_format (fc_tree, hf_ieee80211_fc_flags, tvb,
wlan_broken_fc?offset:offset+1, 1,
flags, "Flags: 0x%X", flags);
flag_tree = proto_item_add_subtree (flag_item, ett_proto_flags);
proto_tree_add_uint (flag_tree, hf_ieee80211_fc_data_ds, tvb, wlan_broken_fc?offset:offset+1, 1,
FLAGS_DS_STATUS (flags));
hidden_item = proto_tree_add_boolean (flag_tree, hf_ieee80211_fc_to_ds, tvb, offset+1, 1, flags);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_boolean (flag_tree, hf_ieee80211_fc_from_ds, tvb, offset+1, 1, flags);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_boolean (flag_tree, hf_ieee80211_fc_more_frag, tvb, wlan_broken_fc?offset:offset+1, 1,
flags);
proto_tree_add_boolean (flag_tree, hf_ieee80211_fc_retry, tvb, wlan_broken_fc?offset:offset+1, 1,
flags);
proto_tree_add_boolean (flag_tree, hf_ieee80211_fc_pwr_mgt, tvb, wlan_broken_fc?offset:offset+1, 1,
flags);
proto_tree_add_boolean (flag_tree, hf_ieee80211_fc_more_data, tvb, wlan_broken_fc?offset:offset+1, 1,
flags);
proto_tree_add_boolean (flag_tree, hf_ieee80211_fc_protected, tvb, wlan_broken_fc?offset:offset+1, 1,
flags);
proto_tree_add_boolean (flag_tree, hf_ieee80211_fc_order, tvb, wlan_broken_fc?offset:offset+1, 1,
flags);
}
static void
dissect_vendor_ie_ht(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, proto_item *item, proto_item *ti_len, gint tag_len)
{
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, offset, 3, "802.11n (Pre) OUI");
if (4 <= tag_len && !tvb_memeql(tvb, offset, PRE_11N_OUI"\x33", 4)) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, 3, 1,"802.11n (Pre) HT information" );
dissect_ht_capability_ie(tvb, pinfo, tree, offset+4, tag_len - 4, ti_len, TRUE);
proto_item_append_text(item, ": HT Capabilities (802.11n D1.10)");
}
else {
if (4 <= tag_len && !tvb_memeql(tvb, offset, PRE_11N_OUI"\x34", 4)) {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, 3, 1, "HT additional information (802.11n D1.00)");
dissect_ht_info_ie_1_0(tvb, pinfo, tree, offset+4, tag_len - 4, ti_len);
proto_item_append_text(item, ": HT Additional Capabilities (802.11n D1.00)");
}
else {
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, 3, 1, "Unknown type");
proto_item_append_text(item, ": 802.11n (pre) Unknown type");
proto_tree_add_string(tree, hf_ieee80211_tag_interpretation, tvb, 4,
tag_len - 4, "Not interpreted");
}
}
}
static guint
dissect_interworking(packet_info *pinfo, proto_tree *tree, proto_item *item,
tvbuff_t *tvb, int offset)
{
guint8 len;
offset++;
len = tvb_get_guint8(tvb, offset);
offset++;
if (tvb_reported_length_remaining(tvb, offset) < len || len == 0) {
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Truncated Interworking element");
return offset;
}
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_access_network_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_internet,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_asra,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_esr,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_uesa,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (len == 1 + 2 || len == 1 + 2 + 6) {
dissect_venue_info(tree, tvb, offset);
offset += 2;
}
if (len == 1 + 6 || len == 1 + 2 + 6) {
proto_tree_add_item(tree, hf_ieee80211_tag_interworking_hessid,
tvb, offset, 6, ENC_NA);
offset += 6;
}
if (len != 1 && len != 1 + 2 && len != 1 + 6 && len != 1 + 2 + 6) {
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Invalid Interworking element length");
}
return offset;
}
static guint
dissect_roaming_consortium(packet_info *pinfo, proto_tree *tree,
proto_item *item, tvbuff_t *tvb, int offset)
{
guint8 len, oi_lens, oi1_len, oi2_len;
int end;
offset++;
len = tvb_get_guint8(tvb, offset);
offset++;
end = offset + len;
if (tvb_reported_length_remaining(tvb, offset) < len || len < 2) {
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Truncated Roaming Consortium element");
return 2 + len;
}
proto_tree_add_item(tree, hf_ieee80211_tag_roaming_consortium_num_anqp_oi,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
oi_lens = tvb_get_guint8(tvb, offset);
oi1_len = oi_lens & 0x0f;
oi2_len = (oi_lens & 0xf0) >> 4;
proto_tree_add_item(tree, hf_ieee80211_tag_roaming_consortium_oi1_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_tag_roaming_consortium_oi2_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (offset + oi1_len > end) {
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Truncated Roaming Consortium element");
return 2 + len;
}
item = proto_tree_add_item(tree, hf_ieee80211_tag_roaming_consortium_oi1,
tvb, offset, oi1_len, ENC_NA);
add_manuf(item, tvb, offset);
offset += oi1_len;
if (offset + oi2_len > end) {
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
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
static int ieee80211_tag_ssid(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb, int offset)
{
guint8 *ssid;
if (beacon_padding != 0)
return offset;
if(tag_len > MAX_SSID_LEN) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"SSID length (%u) greater than maximum (%u)",
tag_len, MAX_SSID_LEN);
}
ssid = tvb_get_ephemeral_string(tvb, offset + 2, tag_len);
AirPDcapSetLastSSID(&airpdcap_ctx, (CHAR *) ssid, tag_len);
proto_tree_add_item(tree, hf_ieee80211_tag_ssid, tvb, offset + 2, tag_len,
ENC_ASCII|ENC_NA);
if (tag_len > 0) {
proto_item_append_text(ti, ": %s", ssid);
col_append_fstr(pinfo->cinfo, COL_INFO, ", SSID=%s", ssid);
memcpy(wlan_stats.ssid, ssid, MIN(tag_len, MAX_SSID_LEN));
wlan_stats.ssid_len = tag_len;
} else {
proto_item_append_text(ti, ": Broadcast");
col_append_str(pinfo->cinfo, COL_INFO, ", SSID=Broadcast");
}
beacon_padding++;
return offset + 2 + tag_len;
}
static int ieee80211_tag_supp_rates(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset, int tag_end)
{
if (tag_len < 1) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"Tag length %u too short, must be greater than 0",
tag_len);
return offset;
}
offset += 2;
while (offset < tag_end) {
proto_tree_add_item(tree, hf_ieee80211_tag_supp_rates, tvb, offset, 1,
ENC_BIG_ENDIAN);
proto_item_append_text(ti, " %s,",
val_to_str(tvb_get_guint8(tvb, offset),
ieee80211_supported_rates_vals,
"Unknown Rate") );
offset++;
}
proto_item_append_text(ti, " [Mbit/sec]");
return offset;
}
static int ieee80211_tag_fh_parameter(packet_info *pinfo, proto_tree *tree,
proto_item *ti_len, guint32 tag_len,
tvbuff_t *tvb, int offset)
{
if (tag_len < 5) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"Tag length %u too short, must be >= 5", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_dwell_time,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hop_set,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hop_pattern,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hop_index,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int ieee80211_tag_ds_parameter(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset)
{
if (tag_len != 1) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"Tag length %u wrong, must be = 1", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_ds_param_channel,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": Current Channel: %u",
tvb_get_guint8(tvb, offset));
wlan_stats.channel = tvb_get_guint8(tvb, offset);
offset++;
return offset;
}
static int ieee80211_tag_cf_parameter(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset)
{
if (tag_len != 6) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"Tag length %u wrong, must be = 6", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_cfp_count,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": CFP count %u", tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_cfp_period,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": CFP Period %u", tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_cfp_max_duration,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": CFP Max Duration %u",
tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_cfp_dur_remaining,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": CFP Dur Remaining %u",
tvb_get_letohs(tvb, offset));
offset++;
return offset;
}
static int ieee80211_tag_tim(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb, int offset)
{
proto_tree *bmapctl_tree;
proto_item *bmapctl_item;
if (tag_len < 4) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"Tag length %u too short, must be >= 4", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tim_dtim_count,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": DTIM %u of", tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_item(tree, hf_ieee80211_tim_dtim_period,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " %u bitmap", tvb_get_guint8(tvb, offset + 1));
offset++;
bmapctl_item = proto_tree_add_item(tree, hf_ieee80211_tim_bmapctl,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
bmapctl_tree = proto_item_add_subtree(bmapctl_item, ett_tag_bmapctl_tree);
proto_tree_add_item(bmapctl_tree, hf_ieee80211_tim_bmapctl_mcast,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bmapctl_tree, hf_ieee80211_tim_bmapctl_offset,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tim_partial_virtual_bitmap,
tvb, offset, tag_len - 3, ENC_NA);
offset += tag_len - 3;
return offset;
}
static int ieee80211_tag_ibss_parameter(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset)
{
if (tag_len != 2) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
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
static int ieee80211_tag_country_info(packet_info *pinfo, proto_tree *tree,
proto_item *ti, proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset, int tag_end)
{
proto_tree *sub_tree;
proto_item *sub_item;
if (tag_len < 6) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"Tag length %u too short, must be >= 6", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_country_info_code,
tvb, offset, 2, ENC_ASCII|ENC_NA);
proto_item_append_text(ti, ": Country Code %s",
tvb_get_ephemeral_string(tvb, offset, 2));
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_country_info_env,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", Environment %s",
val_to_str(tvb_get_guint8(tvb, offset),
environment_vals,"Unknown (0x%02x)"));
offset++;
while (offset < tag_end) {
if ((tag_end - offset) < 3) {
proto_tree_add_item(tree, hf_ieee80211_tag_country_info_pad,
tvb, offset, 1, ENC_NA);
offset++;
continue;
}
if (tvb_get_guint8(tvb, offset) <= 200) {
sub_item = proto_tree_add_item(tree, hf_ieee80211_tag_country_info_fnm,
tvb, offset, 3, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_tag_country_fnm_tree);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_fnm_fcn,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(sub_item, ": First Channel Number: %d",
tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_fnm_nc,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(sub_item, ", Number of Channels: %d",
tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_fnm_mtpl,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(sub_item,
", Maximum Transmit Power Level: %d dBm",
tvb_get_guint8(tvb, offset));
offset++;
} else {
sub_item = proto_tree_add_item(tree, hf_ieee80211_tag_country_info_rrc,
tvb, offset, 3, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_tag_country_rcc_tree);
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_rrc_rei,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(sub_item,
": Regulatory Extension Identifier: %d",
tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_rrc_rc,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(sub_item, ", Regulatory Class: %d",
tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_country_info_rrc_cc,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(sub_item, ", Coverage Class: %d",
tvb_get_guint8(tvb, offset));
offset++;
}
}
return offset;
}
static int ieee80211_tag_fh_hopping_parameter(packet_info *pinfo,
proto_tree *tree,
proto_item *ti,
proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset)
{
if (tag_len < 2) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"Tag length %u too short, must be >= 2", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_parameter_prime_radix,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": Prime Radix: %u", tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_parameter_nb_channels,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", Number of Channels: %u",
tvb_get_guint8(tvb, offset));
offset++;
return offset;
}
static int ieee80211_tag_fh_hopping_table(packet_info *pinfo, proto_tree *tree,
proto_item *ti_len,
guint32 tag_len, tvbuff_t *tvb,
int offset, int tag_end)
{
if (tag_len < 4) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR,
"Tag length %u too short, must be >= 4", tag_len);
return offset;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_table_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_table_number_of_sets,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_table_modulus,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_table_offset,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while (offset < tag_end) {
proto_tree_add_item(tree, hf_ieee80211_tag_fh_hopping_random_table,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
return offset;
}
static int
add_tagged_field(packet_info * pinfo, proto_tree * tree, tvbuff_t * tvb, int offset, int ftype)
{
guint32 oui;
tvbuff_t *tag_tvb;
const guint8 *tag_data_ptr;
guint32 tag_no, tag_len;
int n, ret;
char print_buff[SHORT_STR];
proto_tree * orig_tree=tree;
proto_item *ti = NULL, *ti_len = NULL;
int tag_end;
tag_no = tvb_get_guint8(tvb, offset);
tag_len = tvb_get_guint8(tvb, offset + 1);
tag_end = offset + 2 + tag_len;
if (tree) {
ti = proto_tree_add_item(orig_tree, hf_ieee80211_tag, tvb, offset, 2 + tag_len , ENC_NA);
proto_item_append_text(ti, ": %s", val_to_str(tag_no, tag_num_vals, "Reserved (%d)"));
tree = proto_item_add_subtree(ti, ett_80211_mgt_ie);
proto_tree_add_item(tree, hf_ieee80211_tag_number, tvb, offset, 1, ENC_BIG_ENDIAN);
}
ti_len = proto_tree_add_uint(tree, hf_ieee80211_tag_length, tvb, offset + 1, 1, tag_len);
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
while(offset < tag_end )
{
proto_tree_add_item(tree, hf_ieee80211_tag_request, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case TAG_QBSS_LOAD:
if (tag_len < 4 || tag_len >5)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 4 or 5", tag_len);
break;
}
if (tag_len == 4)
{
proto_item_append_text(ti, " Cisco QBSS Version 1 - non CCA");
proto_tree_add_uint(tree, hf_ieee80211_qbss_version, tvb, offset + 2, tag_len, 1);
proto_tree_add_item(tree, hf_ieee80211_qbss_scount, tvb, offset + 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_qbss_cu, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_qbss_adc, tvb, offset + 5, 1, ENC_BIG_ENDIAN);
}
else if (tag_len == 5)
{
proto_item_append_text(ti, " 802.11e CCA Version");
proto_tree_add_uint(tree, hf_ieee80211_qbss_version, tvb, offset + 2, tag_len, 2);
proto_tree_add_item(tree, hf_ieee80211_qbss_scount, tvb, offset + 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_qbss_cu, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee80211_qbss_adc, tvb, offset + 5, 2, ENC_LITTLE_ENDIAN);
}
break;
case TAG_TSPEC:
if (tag_len != 55)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 55", tag_len);
break;
}
offset += 2;
add_fixed_field(tree, tvb, offset, FIELD_QOS_TS_INFO);
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
break;
case TAG_TCLAS:
if (tag_len < 6)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag length %u too short, must be >= 6", tag_len);
break;
}
{
guint8 type;
guint8 version;
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tclas_up, tvb, offset, 1, ENC_LITTLE_ENDIAN);
type = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tclas_class_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tclas_class_mask, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (type)
{
case 0:
proto_tree_add_item(tree, hf_ieee80211_tclas_src_mac_addr, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_ieee80211_tclas_dst_mac_addr, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_ieee80211_tclas_ether_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 1:
version = tvb_get_guint8(tvb, offset + 5);
proto_tree_add_item(tree, hf_ieee80211_tclas_version, tvb, offset + 5, 1, ENC_LITTLE_ENDIAN);
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
proto_tree_add_item(tree, hf_ieee80211_tclas_dscp, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tclas_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 14", tag_len);
break;
}
offset += 2;
add_fixed_field(tree, tvb, offset, FIELD_SCHEDULE_INFO);
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 1", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_power_constraint_local, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " :%d", tvb_get_guint8(tvb, offset));
offset += 1;
break;
}
case TAG_POWER_CAPABILITY:
{
if (tag_len != 2)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 2", tag_len);
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 0", tag_len);
break;
}
offset += 2;
break;
}
case TAG_TPC_REPORT:
{
if (tag_len != 2)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 2", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_tpc_report_trsmt_pow, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " Transmit Power :%d", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_ieee80211_tag_tpc_report_link_mrg, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ", Link Margin :%d", tvb_get_guint8(tvb, offset));
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag length %u must be even",tag_len);
break;
}
while(offset < tag_end)
{
chan_item = proto_tree_add_item(tree, hf_ieee80211_tag_supported_channels, tvb, offset, 2, ENC_NA);
proto_item_append_text(chan_item, " #%d", i);
i++;
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 3", tag_len);
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
}
case TAG_MEASURE_REQ:
if (tag_len < 3)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag length %u too short, must be >= 3", tag_len);
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
switch(request_type) {
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
case 4:
{
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_regulatory_class, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_channel_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_randomization_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
}
case 5:
{
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_regulatory_class, tvb, offset, 1, ENC_NA);
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
while(offset < tag_end)
{
guint8 sub_id, sub_length, sub_tag_end;
proto_item *ti;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_id, tvb, offset, 1, ENC_NA);
sub_id = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_subelement_length, tvb, offset, 1, ENC_NA);
sub_length = tvb_get_guint8(tvb, offset);
offset += 1;
sub_tag_end = offset + sub_length;
switch(sub_id){
case MEASURE_REQ_BEACON_SUB_SSID:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_ssid, tvb, offset, sub_length, ENC_ASCII|ENC_NA);
offset += sub_length;
break;
case MEASURE_REQ_BEACON_SUB_BRI:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_bri_reporting_condition, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_bri_threshold_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case MEASURE_REQ_BEACON_SUB_RD:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_reporting_detail, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case MEASURE_REQ_BEACON_SUB_REQUEST:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_sub_request, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case MEASURE_REQ_BEACON_SUB_APCP:
break;
default:
break;
}
if(offset < sub_tag_end)
{
ti = proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_beacon_unknown, tvb, offset, sub_tag_end - offset, ENC_NA);
expert_add_info_format(pinfo, ti, PI_UNDECODED, PI_WARN, " Unknown Data (not interpreted)");
offset = sub_tag_end;
}
}
break;
}
case 6:
{
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_request_regulatory_class, tvb, offset, 1, ENC_NA);
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
case 255:
default:
break;
}
}
break;
case TAG_MEASURE_REP:
if (tag_len < 3)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag length %u too short, must be >= 3", tag_len);
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
parent_item = proto_tree_add_uint(tree, hf_ieee80211_tag_measure_report_type, tvb, offset, 1, ENC_NA);
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
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_regulatory_class, tvb, offset, 1, ENC_NA);
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
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_regulatory_class, tvb, offset, 1, ENC_NA);
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
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_regulatory_class, tvb, offset, 1, ENC_NA);
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
break;
}
case 6:
proto_tree_add_item(sub_tree, hf_ieee80211_tag_measure_report_regulatory_class, tvb, offset, 1, ENC_NA);
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
default:
break;
}
}
case TAG_QUIET:
if (tag_len != 6)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 6", tag_len);
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be >= 7", tag_len);
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
while(offset < tag_end)
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 1", tag_len);
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 4", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_ts_delay, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " : %d", tvb_get_ntohl(tvb, offset) );
offset += 4;
break;
case TAG_TCLAS_PROCESS:
if (tag_len != 1)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 1", tag_len);
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
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be = 1", tag_len);
break;
}
{
offset += 2;
offset = dissect_qos_capability(tree, tvb, offset, ftype);
}
break;
case TAG_RSN_IE:
if (tag_len < 20)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be >= 20", tag_len);
break;
}
offset += 2;
offset = dissect_rsn_ie(pinfo, tree, tvb, offset, tag_len);
break;
case TAG_EXT_SUPP_RATES:
if(tag_len < 1)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag length %u too short, must be greater than 0", tag_len);
break;
}
offset += 2;
while(offset < tag_end)
{
proto_tree_add_item(tree, hf_ieee80211_tag_ext_supp_rates, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti, " %s,", val_to_str(tvb_get_guint8(tvb, offset), ieee80211_supported_rates_vals, "Unknown Rate") );
offset += 1;
}
proto_item_append_text(ti, " [Mbit/sec]");
break;
case TAG_EXTENDED_CAPABILITIES:
{
proto_item *ti_ex_cap;
proto_tree *ex_cap_tree;
if (tag_len < 1)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag length %u too short, must be greater than 0", tag_len);
break;
}
offset += 2;
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 0)");
ex_cap_tree = proto_item_add_subtree (ti_ex_cap, ett_tag_ex_cap);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b0, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b1, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b2, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b3, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b4, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b6, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
break;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 1)");
offset += 1;
if (offset >= tag_end) {
break;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 2)");
offset += 1;
if (offset >= tag_end) {
break;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 3)");
ex_cap_tree = proto_item_add_subtree(ti_ex_cap, ett_tag_ex_cap);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b27, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b28, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b29, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b30, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b31, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
break;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 4)");
ex_cap_tree = proto_item_add_subtree(ti_ex_cap, ett_tag_ex_cap);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b32, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b33, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b34, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b36, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b37, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b38, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b39, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset >= tag_end) {
break;
}
ti_ex_cap = proto_tree_add_item(tree, hf_ieee80211_tag_extended_capabilities, tvb, offset, 1, ENC_NA);
proto_item_append_text(ti_ex_cap, " (octet 5)");
ex_cap_tree = proto_item_add_subtree(ti_ex_cap, ett_tag_ex_cap);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_b40, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ex_cap_tree, hf_ieee80211_tag_extended_capabilities_serv_int_granularity, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case TAG_CISCO_CCX1_CKIP:
if (tag_len < 26)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u too short, must be >= 26", tag_len);
break;
}
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_tag_cisco_ccx1_unknown, tvb, offset, 10, ENC_NA);
offset += 10;
proto_tree_add_item(tree, hf_ieee80211_tag_cisco_ccx1_name, tvb, offset, 16, ENC_ASCII|ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_ieee80211_tag_cisco_ccx1_clients, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case TAG_VENDOR_SPECIFIC_IE:
if (tag_len < 3)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Tag Length %u wrong, must be >= 3", tag_len);
break;
}
{
offset += 2;
oui = tvb_get_ntoh24(tvb, offset);
tag_tvb = tvb_new_subset(tvb, offset, tag_len, tag_len);
proto_tree_add_item(tree, hf_ieee80211_tag_oui, tvb, offset, 3, ENC_NA);
proto_item_append_text(ti, ": %s", uint_get_manuf_name(oui));
if (tag_len > 3) {
proto_tree_add_item(ti, hf_ieee80211_tag_vendor_oui_type, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
}
switch (oui) {
# define WPAWME_OUI 0x0050F2
# define RSNOUI_VAL 0x000FAC
# define PRE11N_OUI 0x00904c
case WPAWME_OUI:
offset = dissect_vendor_ie_wpawme(tree, tvb, offset + 3, tag_len, ftype);
break;
case RSNOUI_VAL:
dissect_vendor_ie_rsn(ti, tree, tag_tvb);
break;
case PRE11N_OUI:
dissect_vendor_ie_ht(tvb, pinfo, tree, offset, ti, ti_len, tag_len);
break;
case OUI_WFA:
dissect_vendor_ie_wfa(pinfo, ti, tag_tvb);
break;
case OUI_CISCOWL:
dissect_vendor_ie_aironet(ti, tree, tvb, offset + 3, tag_len - 3);
break;
case OUI_MARVELL:
dissect_vendor_ie_marvell(ti, tree, tvb, offset + 3, tag_len - 3);
break;
case OUI_ATHEROS:
dissect_vendor_ie_atheros(ti, tree, tvb, offset + 3, tag_len - 3, pinfo, ti_len);
break;
default:
proto_tree_add_string (tree, hf_ieee80211_tag_interpretation, tvb, offset + 3,
tag_len - 3, "Not interpreted");
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
case TAG_TIME_ZONE:
dissect_time_zone(tree, tvb, offset + 2, tag_len);
break;
case TAG_TIMEOUT_INTERVAL:
dissect_timeout_interval(tree, tvb, offset + 2, tag_len);
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
case TAG_TIME_ADV:
dissect_time_adv(tree, tvb, offset + 2);
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
if (tag_len == 8 || tag_len == 24)
{
proto_tree_add_item (tree, hf_ieee80211_mesh_peering_peer_link_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
offset += add_fixed_field(tree, tvb, offset, FIELD_REASON_CODE);
break;
default:
proto_tree_add_text (tree, tvb, offset, tag_len, "Unexpected Self-protected action");
offset += tag_len;
break;
}
if (tag_len - (offset - start) == 16)
{
proto_tree_add_item(tree, hf_ieee80211_rsn_pmkid, tvb, offset, 16, ENC_NA);
offset +=16;
}
break;
}
case TAG_MESH_CONFIGURATION:
{
offset += 2;
proto_tree_add_item (tree, hf_ieee80211_mesh_config_path_sel_protocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_ieee80211_mesh_config_path_sel_metric, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_ieee80211_mesh_config_congestion_control, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_ieee80211_mesh_config_sync_method, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_ieee80211_mesh_config_auth_protocol, tvb, offset + 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_ieee80211_mesh_config_formation_info, tvb, offset + 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_ieee80211_mesh_config_capability, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
break;
}
case TAG_MESH_ID:
{
offset += 2;
proto_tree_add_item(tree, hf_ieee80211_mesh_id, tvb, offset, tag_len, ENC_ASCII|ENC_NA);
if (tag_len > 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", MESHID=%s", tvb_get_ephemeral_string(tvb, offset, tag_len));
proto_item_append_text(ti, ": %s", tvb_get_ephemeral_string(tvb, offset, tag_len));
}
break;
}
case TAG_MESH_PREQ:
{
guint8 flags = tvb_get_guint8(tvb, offset + 2);
guint8 targs, i;
proto_item *item;
proto_tree *subtree;
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
item = proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_hwmp_targ_flags_tree);
proto_tree_add_boolean(subtree, hf_ieee80211_ff_hwmp_targ_to_flags, tvb, offset, 1, flags);
proto_tree_add_boolean(subtree, hf_ieee80211_ff_hwmp_targ_usn_flags, tvb, offset, 1, flags);
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
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_targ_count, tvb, offset, 1, ENC_BIG_ENDIAN);
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
offset += add_fixed_field(tree, tvb, offset, FIELD_REASON_CODE);
}
break;
}
case TAG_RANN:
{
offset += 2;
proto_tree_add_item (tree, hf_ieee80211_rann_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_hopcount, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item (tree, hf_ieee80211_ff_hwmp_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
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
case TAG_ROAMING_CONSORTIUM:
dissect_roaming_consortium(pinfo, tree, ti, tvb, offset);
break;
case TAG_AP_CHANNEL_REPORT:
dissect_ap_channel_report(tvb, pinfo, tree, offset + 2, tag_len, ti_len, tag_end, ti);
break;
case TAG_NEIGHBOR_REPORT:
{
#define SUB_TAG_TSF_INFO 0x01
#define SUB_TAG_MEASUREMENT_PILOT_INFO 0x02
#define SUB_TAG_HT_CAPABILITIES 0x03
#define SUB_TAG_HT_INFO 0x04
#define SUB_TAG_SEC_CHANNEL_OFFSET 0x05
#define SUB_TAG_VENDOR_SPECIFIC 0xDD
guint tag_offset;
guint8 sub_tag_id;
guint32 bssid_info, info, sub_tag_length;
proto_item *parent_item;
proto_tree *bssid_info_subtree, *sub_tag_tree;
tvbuff_t *volatile sub_tag_tvb = NULL;
if (tag_len < 13)
{
proto_tree_add_text (tree, tvb, offset + 2, tag_len,
"Neighbor Report: Error: Tag length must be at least 13 bytes long");
break;
}
offset+=2;
tag_offset = offset;
proto_tree_add_item(tree, hf_ieee80211_tag_neighbor_report_bssid, tvb, offset, 6, ENC_NA);
offset+=6;
bssid_info = tvb_get_letohl (tvb, offset);
parent_item = proto_tree_add_uint_format(tree, hf_ieee80211_tag_neighbor_report_bssid_info, tvb, offset, 4, bssid_info, "BSSID Information: 0x%08X", bssid_info);
bssid_info_subtree = proto_item_add_subtree(parent_item, ett_tag_neighbor_report_bssid_info_tree);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_reachability, tvb, offset, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_security, tvb, offset, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_key_scope, tvb, offset, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_spec_mng, tvb, offset, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_qos, tvb, offset, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_apsd, tvb, offset, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_radio_msnt, tvb, offset, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_dback, tvb, offset+1, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_capability_iback, tvb, offset+1, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_mobility_domain, tvb, offset+1, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_high_throughput, tvb, offset+1, 1, bssid_info);
proto_tree_add_uint(bssid_info_subtree, hf_ieee80211_tag_neighbor_report_bssid_info_reserved, tvb, offset+1, 3, (bssid_info & 0xfffff000) >> 12);
offset+=4;
info = tvb_get_guint8 (tvb, offset);
proto_tree_add_uint_format(tree, hf_ieee80211_tag_neighbor_report_reg_class, tvb, offset, 1, info, "Regulatory Class: 0x%02X", info);
offset++;
info = tvb_get_guint8 (tvb, offset);
proto_tree_add_uint_format(tree, hf_ieee80211_tag_neighbor_report_channel_number, tvb, offset, 1, info, "Channel Number: 0x%02X", info);
offset++;
info = tvb_get_guint8 (tvb, offset);
proto_tree_add_uint_format(tree, hf_ieee80211_tag_neighbor_report_phy_type, tvb, offset, 1, info, "PHY Type: 0x%02X", info);
offset++;
sub_tag_id = tvb_get_guint8 (tvb, offset);
offset++;
sub_tag_length = tvb_get_guint8 (tvb, offset);
offset++;
sub_tag_tvb = tvb_new_subset(tvb, offset, sub_tag_length, -1);
switch (sub_tag_id) {
case SUB_TAG_TSF_INFO:
break;
case SUB_TAG_MEASUREMENT_PILOT_INFO:
break;
case SUB_TAG_HT_CAPABILITIES:
parent_item = proto_tree_add_text (tree, tvb, offset, sub_tag_length, "HT Capabilities");
sub_tag_tree = proto_item_add_subtree(parent_item, ett_tag_neighbor_report_sub_tag_tree);
dissect_ht_capability_ie(sub_tag_tvb, pinfo, sub_tag_tree, 0, sub_tag_length, ti_len, FALSE);
break;
case SUB_TAG_HT_INFO:
parent_item = proto_tree_add_text (tree, tvb, offset, sub_tag_length, "HT Information");
sub_tag_tree = proto_item_add_subtree(parent_item, ett_tag_neighbor_report_sub_tag_tree);
dissect_ht_info_ie_1_1(sub_tag_tvb, pinfo, sub_tag_tree, 0, sub_tag_length, ti_len);
break;
case SUB_TAG_SEC_CHANNEL_OFFSET:
parent_item = proto_tree_add_text (tree, tvb, offset, sub_tag_length, "Secondary Channel Offset");
sub_tag_tree = proto_item_add_subtree(parent_item, ett_tag_neighbor_report_sub_tag_tree);
dissect_secondary_channel_offset_ie(sub_tag_tvb, pinfo, sub_tag_tree, 0, sub_tag_length, ti_len);
break;
case SUB_TAG_VENDOR_SPECIFIC:
default:
break;
}
offset += sub_tag_length;
if (tag_len > (offset - tag_offset))
{
proto_tree_add_text (tree, tvb, offset, tag_len - (offset - tag_offset), "Unknown Data");
break;
}
break;
}
case TAG_EXTENDED_CHANNEL_SWITCH_ANNOUNCEMENT:
{
guint tag_offset;
if (tag_len != 4)
{
proto_tree_add_text (tree, tvb, offset + 2, tag_len,
"Extended Channel Switch Announcement: Error: Tag length must be exactly 4 bytes long");
break;
}
offset+=2;
tag_offset = offset;
offset+= add_fixed_field(tree, tvb, offset, FIELD_EXTENDED_CHANNEL_SWITCH_ANNOUNCEMENT);
if (tag_len > (offset - tag_offset))
{
proto_tree_add_text (tree, tvb, offset, tag_len - (offset - tag_offset), "Unknown Data");
break;
}
break;
}
case TAG_SUPPORTED_REGULATORY_CLASSES:
{
guint8 current_field;
guint i;
if (tag_len < 2) {
proto_tree_add_text (tree, tvb, offset + 2, tag_len,
"Supported Regulatory Classes: Error: Tag length must be at least 2 bytes long");
break;
} else if (tag_len > 32) {
proto_tree_add_text (tree, tvb, offset + 2, tag_len,
"Supported Regulatory Classes: Error: Tag length must be no more than 32 bytes long");
break;
}
offset+=2;
current_field = tvb_get_guint8 (tvb, offset);
proto_tree_add_uint(tree, hf_ieee80211_tag_supported_reg_classes_current, tvb, offset, 1, current_field);
offset++;
tag_data_ptr = tvb_get_ptr (tvb, offset, tag_len);
for (i = 0, n = 0; i < tag_len && n < SHORT_STR; i++) {
ret = g_snprintf (print_buff + n, SHORT_STR - n, (i == tag_len-1)?"%d":"%d, ", tag_data_ptr[i]);
if (ret >= SHORT_STR - n) {
break;
}
n += ret;
}
proto_tree_add_string (tree, hf_ieee80211_tag_supported_reg_classes_alternate, tvb, offset, tag_len, print_buff);
break;
}
default:
tvb_ensure_bytes_exist (tvb, offset + 2, tag_len);
proto_tree_add_string (tree, hf_ieee80211_tag_interpretation, tvb, offset + 1 + 1,
tag_len, "Not interpreted");
proto_item_append_text(ti, ": Tag %u Len %u", tag_no, tag_len);
break;
}
if(offset < tag_end){
}
return tag_len + 1 + 1;
}
void
ieee_80211_add_tagged_parameters (tvbuff_t * tvb, int offset, packet_info * pinfo,
proto_tree * tree, int tagged_parameters_len, int ftype)
{
int next_len;
beacon_padding = 0;
while (tagged_parameters_len > 0) {
if ((next_len=add_tagged_field (pinfo, tree, tvb, offset, ftype))==0)
break;
if (next_len > tagged_parameters_len) {
next_len = tagged_parameters_len;
}
offset += next_len;
tagged_parameters_len -= next_len;
}
}
static void
dissect_ieee80211_mgt (guint16 fcf, tvbuff_t * tvb, packet_info * pinfo,
proto_tree * tree)
{
proto_item *ti = NULL;
proto_tree *mgt_tree;
proto_tree *fixed_tree;
proto_tree *tagged_tree;
int offset = 0;
int tagged_parameter_tree_len;
g_pinfo = pinfo;
ieee80211_tvb_invalid = FALSE;
CHECK_DISPLAY_AS_X(data_handle,proto_wlan_mgt, tvb, pinfo, tree);
ti = proto_tree_add_item (tree, proto_wlan_mgt, tvb, 0, -1, ENC_NA);
mgt_tree = proto_item_add_subtree (ti, ett_80211_mgt);
switch (COMPOSE_FRAME_TYPE(fcf))
{
case MGT_ASSOC_REQ:
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 4);
add_fixed_field(fixed_tree, tvb, 0, FIELD_CAP_INFO);
add_fixed_field(fixed_tree, tvb, 2, FIELD_LISTEN_IVAL);
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
add_fixed_field(fixed_tree, tvb, 0, FIELD_CAP_INFO);
add_fixed_field(fixed_tree, tvb, 2, FIELD_STATUS_CODE);
add_fixed_field(fixed_tree, tvb, 4, FIELD_ASSOC_ID);
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
add_fixed_field(fixed_tree, tvb, 0, FIELD_CAP_INFO);
add_fixed_field(fixed_tree, tvb, 2, FIELD_LISTEN_IVAL);
add_fixed_field(fixed_tree, tvb, 4, FIELD_CURRENT_AP_ADDR);
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
add_fixed_field(fixed_tree, tvb, 0, FIELD_CAP_INFO);
add_fixed_field(fixed_tree, tvb, 2, FIELD_STATUS_CODE);
add_fixed_field(fixed_tree, tvb, 4, FIELD_ASSOC_ID);
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
add_fixed_field(fixed_tree, tvb, 0, FIELD_TIMESTAMP);
add_fixed_field(fixed_tree, tvb, 8, FIELD_BEACON_INTERVAL);
add_fixed_field(fixed_tree, tvb, 10, FIELD_CAP_INFO);
offset = 12;
tagged_parameter_tree_len = tvb_reported_length_remaining(tvb, offset);
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset, tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree, tagged_parameter_tree_len, MGT_PROBE_RESP);
break;
}
case MGT_MEASUREMENT_PILOT:
{
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 12);
offset += add_fixed_field(fixed_tree, tvb, offset, FIELD_TIMESTAMP);
offset += add_fixed_field(fixed_tree, tvb, offset, FIELD_MEASUREMENT_PILOT_INT);
offset += add_fixed_field(fixed_tree, tvb, offset, FIELD_BEACON_INTERVAL);
offset += add_fixed_field(fixed_tree, tvb, offset, FIELD_CAP_INFO);
offset += add_fixed_field(fixed_tree, tvb, offset, FIELD_COUNTRY_STR);
offset += add_fixed_field(fixed_tree, tvb, offset, FIELD_MAX_REG_PWR);
offset += add_fixed_field(fixed_tree, tvb, offset, FIELD_MAX_TX_PWR);
offset += add_fixed_field(fixed_tree, tvb, offset, FIELD_TX_PWR_USED);
offset += add_fixed_field(fixed_tree, tvb, offset, FIELD_TRANSCEIVER_NOISE_FLOOR);
tagged_parameter_tree_len = tvb_reported_length_remaining(tvb, offset);
tagged_tree = get_tagged_parameter_tree (mgt_tree, tvb, offset, tagged_parameter_tree_len);
ieee_80211_add_tagged_parameters (tvb, offset, pinfo, tagged_tree, tagged_parameter_tree_len, MGT_MEASUREMENT_PILOT);
break;
}
case MGT_BEACON:
fixed_tree = get_fixed_parameter_tree (mgt_tree, tvb, 0, 12);
add_fixed_field(fixed_tree, tvb, 0, FIELD_TIMESTAMP);
add_fixed_field(fixed_tree, tvb, 8, FIELD_BEACON_INTERVAL);
add_fixed_field(fixed_tree, tvb, 10, FIELD_CAP_INFO);
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
add_fixed_field(fixed_tree, tvb, 0, FIELD_REASON_CODE);
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
add_fixed_field(fixed_tree, tvb, 0, FIELD_AUTH_ALG);
add_fixed_field(fixed_tree, tvb, 2, FIELD_AUTH_TRANS_SEQ);
add_fixed_field(fixed_tree, tvb, 4, FIELD_STATUS_CODE);
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
add_fixed_field(fixed_tree, tvb, 0, FIELD_REASON_CODE);
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
lcl_fixed_hdr = proto_tree_add_text(mgt_tree, tvb, 0, 0, "Fixed parameters");
lcl_fixed_tree = proto_item_add_subtree (lcl_fixed_hdr, ett_fixed_parameters);
offset += add_fixed_field(lcl_fixed_tree, tvb, 0, FIELD_ACTION);
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
lcl_fixed_hdr = proto_tree_add_text(mgt_tree, tvb, 0, 0, "Fixed parameters");
lcl_fixed_tree = proto_item_add_subtree (lcl_fixed_hdr, ett_fixed_parameters);
offset += add_fixed_field(lcl_fixed_tree, tvb, 0, FIELD_ACTION);
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
proto_item *aruba_hdr;
proto_tree *aruba_tree;
guint16 type;
type = tvb_get_ntohs(tvb, offset);
aruba_hdr = proto_tree_add_text(mgt_tree, tvb, 0, 0, "Aruba Management");
aruba_tree = proto_item_add_subtree(aruba_hdr, ett_fixed_parameters);
proto_tree_add_item(aruba_tree, hf_ieee80211_aruba, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if ( type == 0x0005 )
{
proto_tree_add_item(aruba_tree, hf_ieee80211_aruba_hb_seq, tvb, offset, 8, ENC_BIG_ENDIAN);
}
if ( type == 0x0003 )
{
proto_tree_add_item(aruba_tree, hf_ieee80211_aruba_mtu, tvb, offset, 2, ENC_BIG_ENDIAN);
}
break;
}
}
}
static void
set_src_addr_cols(packet_info *pinfo, const guint8 *addr, const char *type)
{
col_add_fstr(pinfo->cinfo, COL_RES_DL_SRC, "%s (%s)",
get_ether_name(addr), type);
col_add_str(pinfo->cinfo, COL_UNRES_DL_SRC, ether_to_str(addr));
}
static void
set_dst_addr_cols(packet_info *pinfo, const guint8 *addr, const char *type)
{
col_add_fstr(pinfo->cinfo, COL_RES_DL_DST, "%s (%s)",
get_ether_name(addr), type);
col_add_str(pinfo->cinfo, COL_UNRES_DL_DST, ether_to_str(addr));
}
static guint32
crc32_802_tvb_padded(tvbuff_t *tvb, guint hdr_len, guint hdr_size, guint len)
{
guint32 c_crc;
c_crc = crc32_ccitt_tvb(tvb, hdr_len);
c_crc = crc32_ccitt_seed(tvb_get_ptr(tvb, hdr_size, len), len, ~c_crc);
c_crc = ((unsigned char)(c_crc>>0)<<24) |
((unsigned char)(c_crc>>8)<<16) |
((unsigned char)(c_crc>>16)<<8) |
((unsigned char)(c_crc>>24)<<0);
return ( c_crc );
}
static void
dissect_ieee80211_common (tvbuff_t * tvb, packet_info * pinfo,
proto_tree * tree, gboolean fixed_length_header, gint fcs_len,
gboolean wlan_broken_fc, gboolean datapad,
gboolean is_ht)
{
guint16 fcf, flags, frame_type_subtype, ctrl_fcf, ctrl_type_subtype;
guint16 seq_control;
guint32 seq_number, frag_number;
gboolean more_frags;
const guint8 *src = NULL;
const guint8 *dst = NULL;
const guint8 *bssid = NULL;
proto_item *ti = NULL;
proto_item *fcs_item = NULL;
proto_item *cw_item = NULL;
proto_item *hidden_item;
proto_tree *volatile hdr_tree = NULL;
proto_tree *fcs_tree = NULL;
proto_tree *cw_tree = NULL;
guint16 hdr_len, ohdr_len, htc_len = 0;
gboolean has_fcs, fcs_good, fcs_bad;
gint len, reported_len, ivlen;
gboolean is_amsdu = 0;
gboolean save_fragmented;
tvbuff_t *volatile next_tvb = NULL;
guint32 addr_type;
volatile encap_t encap_type;
guint8 octet1, octet2;
char out_buff[SHORT_STR];
gint is_iv_bad;
guchar iv_buff[4];
const char *addr1_str = NULL;
int addr1_hf = -1;
guint offset;
const gchar *fts_str;
gchar flag_str[] = "opmPRMFTC";
gint ii;
guint16 qosoff = 0, qos_control = 0;
gint meshctl_len = 0;
guint8 mesh_flags;
guint16 meshoff = 0;
wlan_hdr *volatile whdr;
static wlan_hdr whdrs[4];
gboolean retransmitted;
whdr= &whdrs[0];
col_set_str (pinfo->cinfo, COL_PROTOCOL, "802.11");
col_clear(pinfo->cinfo, COL_INFO);
fcf = FETCH_FCF(0);
frame_type_subtype = COMPOSE_FRAME_TYPE(fcf);
if (frame_type_subtype == CTRL_CONTROL_WRAPPER)
ctrl_fcf = FETCH_FCF(10);
else
ctrl_fcf = 0;
if (fixed_length_header)
hdr_len = DATA_LONG_HDR_LEN;
else
hdr_len = find_header_length (fcf, ctrl_fcf, is_ht);
fts_str = val_to_str_const(frame_type_subtype, frame_type_subtype_vals,
"Unrecognized (Reserved frame)");
col_set_str (pinfo->cinfo, COL_INFO, fts_str);
flags = FCF_FLAGS (fcf);
more_frags = HAVE_FRAGMENTS (flags);
for (ii = 0; ii < 8; ii++) {
if (! (flags & 0x80 >> ii)) {
flag_str[ii] = '.';
}
}
if (is_ht && IS_STRICTLY_ORDERED(flags) &&
((FCF_FRAME_TYPE(fcf) == MGT_FRAME) || (FCF_FRAME_TYPE(fcf) == DATA_FRAME &&
DATA_FRAME_IS_QOS(frame_type_subtype)))) {
htc_len = 4;
}
if (FCF_FRAME_TYPE(fcf) == DATA_FRAME &&
DATA_FRAME_IS_QOS(frame_type_subtype)) {
qosoff = hdr_len - htc_len - 2;
qos_control = tvb_get_letohs(tvb, qosoff);
if (tvb_length(tvb) > hdr_len) {
meshoff = hdr_len;
mesh_flags = tvb_get_guint8 (tvb, hdr_len);
if (has_mesh_control(fcf, qos_control, mesh_flags)) {
meshctl_len = find_mesh_control_length(mesh_flags);
hdr_len += meshctl_len;
}
}
}
ohdr_len = hdr_len;
if (datapad)
hdr_len = roundup2(hdr_len, 4);
if (tree)
{
ti = proto_tree_add_protocol_format (tree, proto_wlan, tvb, 0, hdr_len,
"IEEE 802.11 %s", fts_str);
hdr_tree = proto_item_add_subtree (ti, ett_80211);
dissect_frame_control(hdr_tree, tvb, wlan_broken_fc, 0);
if (frame_type_subtype == CTRL_PS_POLL)
proto_tree_add_uint(hdr_tree, hf_ieee80211_assoc_id, tvb, 2, 2, ENC_LITTLE_ENDIAN);
else
proto_tree_add_uint (hdr_tree, hf_ieee80211_did_duration, tvb, 2, 2,
tvb_get_letohs (tvb, 2));
}
seq_control = 0;
frag_number = 0;
seq_number = 0;
switch (FCF_FRAME_TYPE (fcf))
{
case MGT_FRAME:
src = tvb_get_ptr (tvb, 10, 6);
dst = tvb_get_ptr (tvb, 4, 6);
SET_ADDRESS(&pinfo->dl_src, AT_ETHER, 6, src);
SET_ADDRESS(&pinfo->src, AT_ETHER, 6, src);
SET_ADDRESS(&pinfo->dl_dst, AT_ETHER, 6, dst);
SET_ADDRESS(&pinfo->dst, AT_ETHER, 6, dst);
SET_ADDRESS(&whdr->bssid, AT_ETHER, 6, tvb_get_ptr(tvb, 16,6));
SET_ADDRESS(&whdr->src, AT_ETHER, 6, src);
SET_ADDRESS(&whdr->dst, AT_ETHER, 6, dst);
whdr->type = frame_type_subtype;
seq_control = tvb_get_letohs(tvb, 22);
frag_number = SEQCTL_FRAGMENT_NUMBER(seq_control);
seq_number = SEQCTL_SEQUENCE_NUMBER(seq_control);
col_append_fstr(pinfo->cinfo, COL_INFO,
", SN=%d", seq_number);
col_append_fstr(pinfo->cinfo, COL_INFO,
", FN=%d",frag_number);
if (tree)
{
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_da, tvb, 4, 6, dst);
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_sa, tvb, 10, 6, src);
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_bssid, tvb, 16, 6, ENC_NA);
hidden_item = proto_tree_add_ether (hdr_tree, hf_ieee80211_addr, tvb, 4, 6, dst);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether (hdr_tree, hf_ieee80211_addr, tvb, 10, 6, src);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 16, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint (hdr_tree, hf_ieee80211_frag_number, tvb, 22, 2,
frag_number);
proto_tree_add_uint (hdr_tree, hf_ieee80211_seq_number, tvb, 22, 2,
seq_number);
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
addr1_str = "BSSID";
addr1_hf = hf_ieee80211_addr_bssid;
break;
case CTRL_RTS:
case CTRL_CTS:
case CTRL_ACKNOWLEDGEMENT:
case CTRL_CFP_END:
case CTRL_CFP_ENDACK:
case CTRL_BLOCK_ACK_REQ:
case CTRL_BLOCK_ACK:
addr1_str = "RA";
addr1_hf = hf_ieee80211_addr_ra;
break;
default:
break;
}
if (!addr1_str)
break;
dst = tvb_get_ptr(tvb, 4, 6);
set_dst_addr_cols(pinfo, dst, addr1_str);
if (tree) {
proto_tree_add_item(hdr_tree, addr1_hf, tvb, 4, 6, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 4, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (frame_type_subtype == CTRL_CONTROL_WRAPPER && tree) {
cw_item = proto_tree_add_text(hdr_tree, tvb, offset, 2,
"Contained Frame Control");
cw_tree = proto_item_add_subtree (cw_item, ett_cntrl_wrapper_fc);
dissect_frame_control(cw_tree, tvb, FALSE, offset);
dissect_ht_control(hdr_tree, tvb, offset + 2);
offset+=6;
cw_item = proto_tree_add_text(hdr_tree, tvb, offset, 2,
"Carried Frame");
hdr_tree = proto_item_add_subtree (cw_item, ett_cntrl_wrapper_fc);
}
switch (ctrl_type_subtype)
{
case CTRL_PS_POLL:
case CTRL_CFP_END:
case CTRL_CFP_ENDACK:
{
src = tvb_get_ptr (tvb, offset, 6);
set_src_addr_cols(pinfo, src, "BSSID");
if (tree) {
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
break;
}
case CTRL_RTS:
{
src = tvb_get_ptr (tvb, offset, 6);
set_src_addr_cols(pinfo, src, "TA");
if (tree) {
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
break;
}
case CTRL_CONTROL_WRAPPER:
{
break;
}
case CTRL_BLOCK_ACK_REQ:
{
src = tvb_get_ptr (tvb, offset, 6);
set_src_addr_cols(pinfo, src, "TA");
if (tree)
{
guint16 bar_control;
guint8 block_ack_type;
proto_item *bar_parent_item;
proto_tree *bar_sub_tree;
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 6;
bar_control = tvb_get_letohs(tvb, offset);
block_ack_type = (bar_control & 0x0006) >> 1;
proto_tree_add_uint(hdr_tree, hf_ieee80211_block_ack_request_type, tvb,
offset, 1, block_ack_type);
bar_parent_item = proto_tree_add_uint_format(hdr_tree,
hf_ieee80211_block_ack_request_control, tvb, offset, 2, bar_control,
"Block Ack Request (BAR) Control: 0x%04X", bar_control);
bar_sub_tree = proto_item_add_subtree(bar_parent_item,
ett_block_ack);
proto_tree_add_boolean(bar_sub_tree,
hf_ieee80211_block_ack_control_ack_policy, tvb, offset, 1, bar_control);
proto_tree_add_boolean(bar_sub_tree, hf_ieee80211_block_ack_control_multi_tid,
tvb, offset, 1, bar_control);
proto_tree_add_boolean(bar_sub_tree,
hf_ieee80211_block_ack_control_compressed_bitmap, tvb, offset, 1,
bar_control);
proto_tree_add_uint(bar_sub_tree, hf_ieee80211_block_ack_control_reserved,
tvb, offset, 2, bar_control);
switch (block_ack_type)
{
case 0:
{
proto_tree_add_uint(bar_sub_tree,
hf_ieee80211_block_ack_control_basic_tid_info, tvb, offset+1, 1,
bar_control);
offset += 2;
add_fixed_field(hdr_tree, tvb, offset,
FIELD_BLOCK_ACK_SSC);
break;
}
case 2:
{
proto_tree_add_uint(bar_sub_tree,
hf_ieee80211_block_ack_control_compressed_tid_info, tvb, offset+1, 1,
bar_control);
offset += 2;
add_fixed_field(hdr_tree, tvb, offset,
FIELD_BLOCK_ACK_SSC);
break;
}
case 3:
{
guint8 tid_count;
guint i;
proto_tree *bar_mtid_tree, *bar_mtid_sub_tree;
tid_count = ((bar_control & 0xF000) >> 12) + 1;
proto_tree_add_uint_format(bar_sub_tree, hf_ieee80211_block_ack_control_multi_tid_info, tvb, offset+1, 1, bar_control,
decode_numeric_bitfield(bar_control, 0xF000, 16,"Number of TIDs Present: 0x%%X"), tid_count);
offset += 2;
bar_parent_item = proto_tree_add_text (hdr_tree, tvb, offset, tid_count*4, "Per TID Info");
bar_mtid_tree = proto_item_add_subtree(bar_parent_item, ett_block_ack);
for (i = 1; i <= tid_count; i++) {
bar_parent_item = proto_tree_add_uint(bar_mtid_tree, hf_ieee80211_block_ack_multi_tid_info, tvb, offset, 4, i);
bar_mtid_sub_tree = proto_item_add_subtree(bar_parent_item, ett_block_ack);
bar_control = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(bar_mtid_sub_tree, hf_ieee80211_block_ack_multi_tid_reserved, tvb, offset, 2, bar_control);
proto_tree_add_uint(bar_mtid_sub_tree, hf_ieee80211_block_ack_multi_tid_value, tvb, offset+1, 1, bar_control);
offset += 2;
offset += add_fixed_field(bar_mtid_sub_tree, tvb, offset, FIELD_BLOCK_ACK_SSC);
}
break;
}
}
}
break;
}
case CTRL_BLOCK_ACK:
{
src = tvb_get_ptr (tvb, offset, 6);
set_src_addr_cols(pinfo, src, "TA");
if (tree)
{
guint16 ba_control;
guint8 block_ack_type;
proto_item *ba_parent_item;
proto_tree *ba_sub_tree;
proto_tree_add_item(hdr_tree, hf_ieee80211_addr_ta, tvb, offset, 6, ENC_NA);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 6;
ba_control = tvb_get_letohs(tvb, offset);
block_ack_type = (ba_control & 0x0006) >> 1;
proto_tree_add_uint(hdr_tree, hf_ieee80211_block_ack_type, tvb, offset, 1, block_ack_type);
ba_parent_item = proto_tree_add_uint_format(hdr_tree,
hf_ieee80211_block_ack_control, tvb, offset, 2, ba_control,
"Block Ack (BA) Control: 0x%04X", ba_control);
ba_sub_tree = proto_item_add_subtree(ba_parent_item, ett_block_ack);
proto_tree_add_boolean(ba_sub_tree, hf_ieee80211_block_ack_control_ack_policy,
tvb, offset, 1, ba_control);
proto_tree_add_boolean(ba_sub_tree, hf_ieee80211_block_ack_control_multi_tid,
tvb, offset, 1, ba_control);
proto_tree_add_boolean(ba_sub_tree,
hf_ieee80211_block_ack_control_compressed_bitmap, tvb, offset, 1,
ba_control);
proto_tree_add_uint(ba_sub_tree, hf_ieee80211_block_ack_control_reserved, tvb,
offset, 2, ba_control);
switch (block_ack_type)
{
case 0:
{
proto_tree_add_uint(ba_sub_tree,
hf_ieee80211_block_ack_control_basic_tid_info, tvb, offset+1, 1,
ba_control);
offset += 2;
offset += add_fixed_field(hdr_tree, tvb, offset, FIELD_BLOCK_ACK_SSC);
proto_tree_add_item(hdr_tree, hf_ieee80211_block_ack_bitmap, tvb, offset, 128, ENC_NA);
break;
}
case 2:
{
guint16 ssn;
guint64 bmap;
int f;
proto_item *ba_bitmap_item;
proto_tree *ba_bitmap_tree;
proto_tree_add_uint(ba_sub_tree, hf_ieee80211_block_ack_control_basic_tid_info, tvb, offset+1, 1, ba_control);
offset += 2;
ssn = tvb_get_letohs(tvb, offset);
ssn >>= 4;
offset += add_fixed_field(hdr_tree, tvb, offset, FIELD_BLOCK_ACK_SSC);
bmap = tvb_get_letoh64(tvb, offset);
ba_bitmap_item = proto_tree_add_item(hdr_tree, hf_ieee80211_block_ack_bitmap, tvb, offset, 8, ENC_NA);
ba_bitmap_tree = proto_item_add_subtree(ba_bitmap_item, ett_block_ack_bitmap);
for (f = 0; f < 64; f++) {
if (bmap & (G_GINT64_CONSTANT(1) << f))
continue;
proto_tree_add_uint_format_value(ba_bitmap_tree, hf_ieee80211_block_ack_bitmap_missing_frame,
tvb, offset + (f/8), 1, ssn + f, "%u", ssn + f);
}
break;
}
case 3:
{
guint8 tid_count;
guint i;
proto_tree *ba_mtid_tree, *ba_mtid_sub_tree;
tid_count = ((ba_control & 0xF000) >> 12) + 1;
proto_tree_add_uint_format(ba_sub_tree,
hf_ieee80211_block_ack_control_compressed_tid_info, tvb, offset+1, 1,
ba_control, decode_numeric_bitfield(ba_control, 0xF000,
16,"Number of TIDs Present: 0x%%X"), tid_count);
offset += 2;
ba_parent_item = proto_tree_add_text (hdr_tree, tvb, offset, tid_count*4, "Per TID Info");
ba_mtid_tree = proto_item_add_subtree(ba_parent_item, ett_block_ack);
for (i = 1; i <= tid_count; i++) {
ba_parent_item = proto_tree_add_uint(ba_mtid_tree, hf_ieee80211_block_ack_multi_tid_info, tvb, offset, 4, i);
ba_mtid_sub_tree = proto_item_add_subtree(ba_parent_item, ett_block_ack);
ba_control = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(ba_mtid_sub_tree, hf_ieee80211_block_ack_multi_tid_reserved, tvb, offset, 2, ba_control);
proto_tree_add_uint(ba_mtid_sub_tree, hf_ieee80211_block_ack_multi_tid_value, tvb, offset+1, 1, ba_control);
offset += 2;
offset += add_fixed_field(ba_mtid_sub_tree, tvb, offset, FIELD_BLOCK_ACK_SSC);
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
break;
}
case DATA_FRAME:
addr_type = FCF_ADDR_SELECTOR (fcf);
switch (addr_type)
{
case DATA_ADDR_T1:
src = tvb_get_ptr (tvb, 10, 6);
dst = tvb_get_ptr (tvb, 4, 6);
bssid = tvb_get_ptr (tvb, 16, 6);
break;
case DATA_ADDR_T2:
src = tvb_get_ptr (tvb, 16, 6);
dst = tvb_get_ptr (tvb, 4, 6);
bssid = tvb_get_ptr (tvb, 10, 6);
break;
case DATA_ADDR_T3:
src = tvb_get_ptr (tvb, 10, 6);
dst = tvb_get_ptr (tvb, 16, 6);
bssid = tvb_get_ptr (tvb, 4, 6);
break;
case DATA_ADDR_T4:
src = tvb_get_ptr (tvb, 24, 6);
dst = tvb_get_ptr (tvb, 16, 6);
bssid = tvb_get_ptr (tvb, 16, 6);
break;
}
SET_ADDRESS(&pinfo->dl_src, AT_ETHER, 6, src);
SET_ADDRESS(&pinfo->src, AT_ETHER, 6, src);
SET_ADDRESS(&pinfo->dl_dst, AT_ETHER, 6, dst);
SET_ADDRESS(&pinfo->dst, AT_ETHER, 6, dst);
SET_ADDRESS(&whdr->bssid, AT_ETHER, 6, bssid);
SET_ADDRESS(&whdr->src, AT_ETHER, 6, src);
SET_ADDRESS(&whdr->dst, AT_ETHER, 6, dst);
whdr->type = frame_type_subtype;
seq_control = tvb_get_letohs(tvb, 22);
frag_number = SEQCTL_FRAGMENT_NUMBER(seq_control);
seq_number = SEQCTL_SEQUENCE_NUMBER(seq_control);
col_append_fstr(pinfo->cinfo, COL_INFO,
", SN=%d, FN=%d", seq_number,frag_number);
if (tree)
{
switch (addr_type)
{
case DATA_ADDR_T1:
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_da, tvb, 4, 6, dst);
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_sa, tvb, 10, 6, src);
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_bssid, tvb, 16, 6, bssid);
proto_tree_add_uint (hdr_tree, hf_ieee80211_frag_number, tvb, 22, 2,
frag_number);
proto_tree_add_uint (hdr_tree, hf_ieee80211_seq_number, tvb, 22, 2,
seq_number);
hidden_item = proto_tree_add_ether (hdr_tree, hf_ieee80211_addr, tvb, 4, 6, dst);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether (hdr_tree, hf_ieee80211_addr, tvb, 10, 6, src);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 16, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
case DATA_ADDR_T2:
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_da, tvb, 4, 6, dst);
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_bssid, tvb, 10, 6, bssid);
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_sa, tvb, 16, 6, src);
proto_tree_add_uint (hdr_tree, hf_ieee80211_frag_number, tvb, 22, 2,
frag_number);
proto_tree_add_uint (hdr_tree, hf_ieee80211_seq_number, tvb, 22, 2,
seq_number);
hidden_item = proto_tree_add_ether (hdr_tree, hf_ieee80211_addr, tvb, 4, 6, dst);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 10, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether (hdr_tree, hf_ieee80211_addr, tvb, 16, 6, src);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
case DATA_ADDR_T3:
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_bssid, tvb, 4, 6, bssid);
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_sa, tvb, 10, 6, src);
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_da, tvb, 16, 6, dst);
proto_tree_add_uint (hdr_tree, hf_ieee80211_frag_number, tvb, 22, 2,
frag_number);
proto_tree_add_uint (hdr_tree, hf_ieee80211_seq_number, tvb, 22, 2,
seq_number);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 4, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether (hdr_tree, hf_ieee80211_addr, tvb, 10, 6, src);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether (hdr_tree, hf_ieee80211_addr, tvb, 16, 6, dst);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
case DATA_ADDR_T4:
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_ra, tvb, 4, 6, ENC_NA);
proto_tree_add_item (hdr_tree, hf_ieee80211_addr_ta, tvb, 10, 6, ENC_NA);
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_da, tvb, 16, 6, dst);
proto_tree_add_uint (hdr_tree, hf_ieee80211_frag_number, tvb, 22, 2,
frag_number);
proto_tree_add_uint (hdr_tree, hf_ieee80211_seq_number, tvb, 22, 2,
seq_number);
proto_tree_add_ether (hdr_tree, hf_ieee80211_addr_sa, tvb, 24, 6, src);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 4, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item (hdr_tree, hf_ieee80211_addr, tvb, 10, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether (hdr_tree, hf_ieee80211_addr, tvb, 16, 6, dst);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether (hdr_tree, hf_ieee80211_addr, tvb, 24, 6, src);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
}
}
break;
}
len = tvb_length_remaining(tvb, hdr_len);
reported_len = tvb_reported_length_remaining(tvb, hdr_len);
switch (fcs_len)
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
has_fcs = TRUE;
break;
default:
has_fcs = wlan_check_fcs;
break;
}
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
if (datapad)
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
if(fcs_good) {
fcs_item = proto_tree_add_uint_format(hdr_tree, hf_ieee80211_fcs, tvb,
hdr_len + len, 4, sent_fcs,
"Frame check sequence: 0x%08x [correct]", sent_fcs);
} else {
fcs_item = proto_tree_add_uint_format(hdr_tree, hf_ieee80211_fcs, tvb,
hdr_len + len, 4, sent_fcs,
"Frame check sequence: 0x%08x [incorrect, should be 0x%08x]",
sent_fcs, fcs);
flag_str[8] = '.';
}
proto_tree_set_appendix(hdr_tree, tvb, hdr_len + len, 4);
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
} else {
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
proto_item *qos_fields;
proto_tree *qos_tree;
guint16 qos_tid;
guint16 qos_priority;
guint16 qos_ack_policy;
guint16 qos_amsdu_present;
guint16 qos_eosp;
guint16 qos_field_content;
qos_fields = proto_tree_add_text(hdr_tree, tvb, qosoff, 2,
"QoS Control");
qos_tree = proto_item_add_subtree (qos_fields, ett_qos_parameters);
qos_tid = QOS_TID(qos_control);
qos_priority = QOS_PRIORITY(qos_control);
qos_ack_policy = QOS_ACK_POLICY(qos_control);
qos_amsdu_present = QOS_AMSDU_PRESENT(qos_control);
qos_eosp = QOS_EOSP(qos_control);
qos_field_content = QOS_FIELD_CONTENT(qos_control);
proto_tree_add_uint (qos_tree, hf_ieee80211_qos_tid, tvb,
qosoff, 1, qos_tid);
proto_tree_add_uint_format (qos_tree, hf_ieee80211_qos_priority, tvb,
qosoff, 1, qos_priority,
"Priority: %d (%s) (%s)",
qos_priority, qos_tags[qos_priority], qos_acs[qos_priority]);
if (flags & FLAG_FROM_DS) {
proto_tree_add_boolean (qos_tree, hf_ieee80211_qos_eosp, tvb,
qosoff, 1, qos_control);
} else {
proto_tree_add_boolean (qos_tree, hf_ieee80211_qos_bit4, tvb,
qosoff, 1, qos_control);
}
proto_tree_add_uint (qos_tree, hf_ieee80211_qos_ack_policy, tvb, qosoff, 1,
qos_ack_policy);
if (flags & FLAG_FROM_DS) {
if (!DATA_FRAME_IS_NULL(frame_type_subtype)) {
proto_tree_add_boolean(qos_tree, hf_ieee80211_qos_amsdu_present, tvb,
qosoff, 1, qos_amsdu_present);
is_amsdu = qos_amsdu_present;
}
if (DATA_FRAME_IS_CF_POLL(frame_type_subtype)) {
if (qos_field_content == 0) {
proto_tree_add_uint_format_value (qos_tree, hf_ieee80211_qos_txop_limit, tvb,
qosoff + 1, 1, qos_field_content,
"transmit one frame immediately (0)");
} else {
proto_tree_add_uint (qos_tree, hf_ieee80211_qos_txop_limit, tvb,
qosoff + 1, 1, qos_field_content);
}
} else {
proto_item *qos_ps_buf_state_fields;
proto_tree *qos_ps_buf_state_tree;
guint8 qap_buf_load;
qos_ps_buf_state_fields = proto_tree_add_text(qos_tree, tvb, qosoff + 1, 1,
"QAP PS Buffer State: 0x%x", qos_field_content);
qos_ps_buf_state_tree = proto_item_add_subtree (qos_ps_buf_state_fields, ett_qos_ps_buf_state);
proto_tree_add_boolean (qos_ps_buf_state_tree, hf_ieee80211_qos_buf_state_indicated,
tvb, qosoff + 1, 1, qos_field_content);
if (QOS_PS_BUF_STATE_INDICATED(qos_field_content)) {
proto_tree_add_uint (qos_ps_buf_state_tree, hf_ieee80211_qos_highest_pri_buf_ac, tvb,
qosoff + 1, 1, qos_field_content);
qap_buf_load = QOS_PS_QAP_BUF_LOAD(qos_field_content);
switch (qap_buf_load) {
case 0:
proto_tree_add_uint_format_value (qos_ps_buf_state_tree, hf_ieee80211_qos_qap_buf_load, tvb,
qosoff + 1, 1, qos_field_content,
"no buffered traffic (0)");
break;
default:
proto_tree_add_uint_format_value (qos_ps_buf_state_tree, hf_ieee80211_qos_qap_buf_load, tvb,
qosoff + 1, 1, qos_field_content,
"%d octets (%d)", qap_buf_load*4096, qap_buf_load);
break;
case 15:
proto_tree_add_uint_format_value (qos_ps_buf_state_tree, hf_ieee80211_qos_qap_buf_load, tvb,
qosoff + 1, 1, qos_field_content,
"greater than 57344 octets (15)");
break;
}
}
}
} else {
if (!DATA_FRAME_IS_NULL(frame_type_subtype)) {
proto_tree_add_boolean(qos_tree, hf_ieee80211_qos_amsdu_present, tvb,
qosoff, 1, qos_amsdu_present);
is_amsdu = qos_amsdu_present;
}
if (qos_eosp) {
switch (qos_field_content) {
case 0:
proto_tree_add_uint_format_value (qos_tree, hf_ieee80211_qos_queue_size,
tvb, qosoff + 1, 1, qos_field_content,
"no buffered traffic in the queue (0)");
break;
default:
proto_tree_add_uint_format_value (qos_tree, hf_ieee80211_qos_queue_size,
tvb, qosoff + 1, 1, qos_field_content,
"%u bytes (%u)", qos_field_content*256, qos_field_content);
break;
case 254:
proto_tree_add_uint_format_value (qos_tree, hf_ieee80211_qos_queue_size,
tvb, qosoff + 1, 1, qos_field_content,
"more than 64768 octets (254)");
break;
case 255:
proto_tree_add_uint_format_value (qos_tree, hf_ieee80211_qos_queue_size,
tvb, qosoff + 1, 1, qos_field_content,
"unspecified or unknown (256)");
break;
}
} else {
if (qos_field_content == 0) {
proto_tree_add_uint_format_value (qos_tree, hf_ieee80211_qos_txop_dur_req,
tvb, qosoff + 1, 1, qos_field_content,
"no TXOP requested (0)");
} else {
proto_tree_add_uint (qos_tree, hf_ieee80211_qos_txop_dur_req,
tvb, qosoff + 1, 1, qos_field_content);
}
}
}
if (htc_len == 4) {
dissect_ht_control(hdr_tree, tvb, ohdr_len - 4);
}
if (meshctl_len != 0) {
proto_item *msh_fields;
proto_tree *msh_tree;
msh_fields = proto_tree_add_text(hdr_tree, tvb, meshoff, meshctl_len, "Mesh Control field");
msh_tree = proto_item_add_subtree (msh_fields, ett_msh_control);
add_fixed_field(msh_tree, tvb, meshoff, FIELD_MESH_CONTROL);
}
}
if (enable_decryption && !pinfo->fd->flags.visited) {
const guint8 *enc_data = tvb_get_ptr(tvb, 0, hdr_len+reported_len);
AirPDcapPacketProcess(&airpdcap_ctx, enc_data, hdr_len, hdr_len+reported_len, NULL, 0, NULL, TRUE, FALSE);
}
if (DATA_FRAME_IS_NULL(frame_type_subtype))
return;
if (!wlan_subdissector) {
guint fnum = 0;
retransmitted = FALSE;
if(!pinfo->fd->flags.visited){
retransmit_key key;
retransmit_key *result;
memcpy(key.bssid, bssid, 6);
memcpy(key.src, src, 6);
key.seq_control = 0;
result = (retransmit_key *)g_hash_table_lookup(fc_analyse_retransmit_table, &key);
if (result && result->seq_control == seq_control) {
fnum = result->fnum;
g_hash_table_insert(fc_first_frame_table, GINT_TO_POINTER( pinfo->fd->num),
GINT_TO_POINTER(fnum));
retransmitted = TRUE;
} else {
if (!result) {
result = se_alloc(sizeof(retransmit_key));
*result = key;
g_hash_table_insert(fc_analyse_retransmit_table, result, result);
}
result->seq_control = seq_control;
result->fnum = pinfo->fd->num;
}
}
else if ((fnum = GPOINTER_TO_UINT(g_hash_table_lookup(fc_first_frame_table, GINT_TO_POINTER( pinfo->fd->num))))) {
retransmitted = TRUE;
}
if (retransmitted) {
col_append_str(pinfo->cinfo, COL_INFO, " [retransmitted]");
if (tree) {
proto_item *item;
item=proto_tree_add_none_format(hdr_tree, hf_ieee80211_fc_analysis_retransmission, tvb, 0, 0, "Retransmitted frame");
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
return;
default:
return;
}
if (IS_PROTECTED(FCF_FLAGS(fcf)) && wlan_ignore_wep != WLAN_IGNORE_WEP_WO_IV) {
gboolean can_decrypt = FALSE;
proto_tree *wep_tree = NULL;
guint32 iv;
guint8 key, keybyte;
#define PROTECTION_ALG_WEP AIRPDCAP_KEY_TYPE_WEP
#define PROTECTION_ALG_TKIP AIRPDCAP_KEY_TYPE_TKIP
#define PROTECTION_ALG_CCMP AIRPDCAP_KEY_TYPE_CCMP
#define PROTECTION_ALG_RSNA PROTECTION_ALG_CCMP | PROTECTION_ALG_TKIP
guint8 algorithm=G_MAXUINT8;
#define IS_TKIP(tvb, hdr_len) (tvb_get_guint8(tvb, hdr_len + 1) & 0x20)
#define IS_CCMP(tvb, hdr_len) (tvb_get_guint8(tvb, hdr_len + 2) == 0)
guint32 sec_header=0;
guint32 sec_trailer=0;
next_tvb = try_decrypt(tvb, hdr_len, reported_len, &algorithm, &sec_header, &sec_trailer);
keybyte = tvb_get_guint8(tvb, hdr_len + 3);
key = KEY_OCTET_WEP_KEY(keybyte);
if ((keybyte & KEY_EXTIV) && (len >= EXTIV_LEN)) {
if (tree) {
proto_item *extiv_fields;
if (algorithm==PROTECTION_ALG_TKIP)
extiv_fields = proto_tree_add_text(hdr_tree, tvb, hdr_len, 8,
"TKIP parameters");
else if (algorithm==PROTECTION_ALG_CCMP)
extiv_fields = proto_tree_add_text(hdr_tree, tvb, hdr_len, 8,
"CCMP parameters");
else {
if (IS_TKIP(tvb, hdr_len)) {
algorithm=PROTECTION_ALG_TKIP;
extiv_fields = proto_tree_add_text(hdr_tree, tvb, hdr_len, 8,
"TKIP parameters");
} else if (IS_CCMP(tvb, hdr_len)) {
algorithm=PROTECTION_ALG_CCMP;
extiv_fields = proto_tree_add_text(hdr_tree, tvb, hdr_len, 8,
"CCMP parameters");
} else
extiv_fields = proto_tree_add_text(hdr_tree, tvb, hdr_len, 8,
"TKIP/CCMP parameters");
}
proto_item_set_len (ti, hdr_len + 8);
wep_tree = proto_item_add_subtree (extiv_fields, ett_wep_parameters);
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
}
}
} else {
iv = tvb_get_ntoh24(tvb, hdr_len);
if (tree) {
proto_item *wep_fields;
wep_fields = proto_tree_add_text(hdr_tree, tvb, hdr_len, 4,
"WEP parameters");
wep_tree = proto_item_add_subtree (wep_fields, ett_wep_parameters);
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
if (!can_decrypt || next_tvb == NULL) {
next_tvb = tvb_new_subset(tvb, hdr_len + ivlen, len, reported_len);
if (tree) {
if (algorithm==PROTECTION_ALG_WEP) {
if (can_decrypt)
proto_tree_add_uint_format (wep_tree, hf_ieee80211_wep_icv, tvb,
hdr_len + ivlen + len, 4,
tvb_get_ntohl(tvb, hdr_len + ivlen + len),
"WEP ICV: 0x%08x (not verified)",
tvb_get_ntohl(tvb, hdr_len + ivlen + len));
} else if (algorithm==PROTECTION_ALG_CCMP) {
} else if (algorithm==PROTECTION_ALG_TKIP) {
}
}
if (pinfo->ethertype != ETHERTYPE_CENTRINO_PROMISC && wlan_ignore_wep == WLAN_IGNORE_WEP_NO) {
call_dissector(data_handle, next_tvb, pinfo, tree);
goto end_of_wlan;
}
} else {
if (algorithm==PROTECTION_ALG_WEP) {
if (tree)
proto_tree_add_uint_format (wep_tree, hf_ieee80211_wep_icv, tvb,
hdr_len + ivlen + len, 4,
tvb_get_ntohl(tvb, hdr_len + ivlen + len),
"WEP ICV: 0x%08x (correct)",
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
if (wlan_defragment && (more_frags || frag_number != 0)) {
fragment_data *fd_head;
if (reported_len < 0)
THROW(ReportedBoundsError);
fd_head = fragment_add_seq_802_11(next_tvb, hdr_len, pinfo, seq_number,
wlan_fragment_table,
wlan_reassembled_table,
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
if (is_amsdu && tvb_reported_length_remaining(next_tvb, 0) > 4){
tvbuff_t *volatile msdu_tvb = NULL;
guint32 msdu_offset = 0;
guint i = 1;
const guint8 *lcl_src = NULL;
const guint8 *lcl_dst = NULL;
guint16 msdu_length;
proto_item *parent_item;
proto_tree *mpdu_tree;
proto_tree *subframe_tree;
parent_item = proto_tree_add_protocol_format(tree, proto_aggregate, next_tvb, 0,
tvb_reported_length_remaining(next_tvb, 0), "IEEE 802.11 Aggregate MSDU");
mpdu_tree = proto_item_add_subtree(parent_item, ett_msdu_aggregation_parent_tree);
do {
lcl_dst = tvb_get_ptr (next_tvb, msdu_offset, 6);
lcl_src = tvb_get_ptr (next_tvb, msdu_offset+6, 6);
msdu_length = tvb_get_ntohs (next_tvb, msdu_offset+12);
parent_item = proto_tree_add_uint_format(mpdu_tree, hf_ieee80211_amsdu_msdu_header_text, next_tvb,
msdu_offset, roundup2(msdu_offset+14+msdu_length, 4),
i, "A-MSDU Subframe #%u", i);
subframe_tree = proto_item_add_subtree(parent_item, ett_msdu_aggregation_subframe_tree);
i++;
proto_tree_add_ether(subframe_tree, hf_ieee80211_addr_da, next_tvb, msdu_offset, 6, lcl_dst);
proto_tree_add_ether(subframe_tree, hf_ieee80211_addr_sa, next_tvb, msdu_offset+6, 6, lcl_src);
proto_tree_add_uint_format(subframe_tree, hf_ieee80211_mcsset_highest_data_rate, next_tvb, msdu_offset+12, 2,
msdu_length, "MSDU length: 0x%04X", msdu_length);
msdu_offset += 14;
msdu_tvb = tvb_new_subset(next_tvb, msdu_offset, msdu_length, -1);
call_dissector(llc_handle, msdu_tvb, pinfo, subframe_tree);
msdu_offset = roundup2(msdu_offset+msdu_length, 4);
} while (tvb_reported_length_remaining(next_tvb, msdu_offset) > 14);
break;
}
encap_type = ENCAP_802_2;
TRY {
octet1 = tvb_get_guint8(next_tvb, 0);
octet2 = tvb_get_guint8(next_tvb, 1);
if (octet1 != 0xaa || octet2 != 0xaa) {
if (tvb_memeql(next_tvb, 6, pinfo->dl_src.data, 6) == 0 ||
tvb_memeql(next_tvb, 0, pinfo->dl_dst.data, 6) == 0)
encap_type = ENCAP_ETHERNET;
else if (octet1 == 0xff && octet2 == 0xff)
encap_type = ENCAP_IPX;
else if (octet1 == 0x00 && octet2 == 0x00) {
proto_tree_add_text(tree, next_tvb, 0, 2, "Mysterious OLPC stuff");
next_tvb = tvb_new_subset_remaining (next_tvb, 2);
}
}
}
CATCH2(BoundsError, ReportedBoundsError) {
;
}
ENDTRY;
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
}
pinfo->fragmented = save_fragmented;
end_of_wlan:
whdr->stats = wlan_stats;
tap_queue_packet(wlan_tap, pinfo, whdr);
memset (&wlan_stats, 0, sizeof wlan_stats);
}
static void
dissect_ieee80211 (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
dissect_ieee80211_common (tvb, pinfo, tree, FALSE,
pinfo->pseudo_header->ieee_802_11.fcs_len, FALSE, FALSE, FALSE);
}
static void
dissect_ieee80211_datapad (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
dissect_ieee80211_common (tvb, pinfo, tree, FALSE,
pinfo->pseudo_header->ieee_802_11.fcs_len, FALSE, TRUE, FALSE);
}
static void
dissect_ieee80211_bsfc (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
dissect_ieee80211_common (tvb, pinfo, tree, FALSE, 0, TRUE, FALSE, FALSE);
}
static void
dissect_ieee80211_fixed (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
dissect_ieee80211_common (tvb, pinfo, tree, TRUE, 0, FALSE, FALSE, FALSE);
}
static void
dissect_ieee80211_ht (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
dissect_ieee80211_common (tvb, pinfo, tree, FALSE,
pinfo->pseudo_header->ieee_802_11.fcs_len, FALSE, FALSE, TRUE);
}
static void
wlan_defragment_init(void)
{
fragment_table_init(&wlan_fragment_table);
reassembled_table_init(&wlan_reassembled_table);
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
return ( (!memcmp(key1->bssid, key2->bssid, 6) && !memcmp( key1->src, key2->src, 6))? TRUE:FALSE);
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
static void
wlan_retransmit_init(void)
{
if ( fc_analyse_retransmit_table ){
g_hash_table_destroy(fc_analyse_retransmit_table);
fc_analyse_retransmit_table = NULL;
}
if( fc_first_frame_table ){
g_hash_table_destroy(fc_first_frame_table);
fc_first_frame_table = NULL;
}
if (wlan_subdissector)
return;
fc_analyse_retransmit_table= g_hash_table_new(retransmit_hash, retransmit_equal);
fc_first_frame_table = g_hash_table_new( frame_hash, frame_equal);
}
void
proto_register_ieee80211 (void)
{
static const value_string frame_type[] = {
{MGT_FRAME, "Management frame"},
{CONTROL_FRAME, "Control frame"},
{DATA_FRAME, "Data frame"},
{0, NULL}
};
static const value_string tofrom_ds[] = {
{0, "Not leaving DS or network is operating "
"in AD-HOC mode (To DS: 0 From DS: 0)"},
{FLAG_TO_DS, "Frame from STA to DS via an AP (To DS: 1 "
"From DS: 0)"},
{FLAG_FROM_DS, "Frame from DS to a STA via AP(To DS: 0 "
"From DS: 1)"},
{FLAG_TO_DS|FLAG_FROM_DS, "WDS (AP to AP) or Mesh (MP to MP) Frame "
"(To DS: 1 From DS: 1)"},
{0, NULL}
};
static const true_false_string tods_flag = {
"Frame is entering DS",
"Frame is not entering DS"
};
static const true_false_string fromds_flag = {
"Frame is exiting DS",
"Frame is not exiting DS"
};
static const true_false_string more_frags = {
"More fragments follow",
"This is the last fragment"
};
static const true_false_string retry_flags = {
"Frame is being retransmitted",
"Frame is not being retransmitted"
};
static const true_false_string pm_flags = {
"STA will go to sleep",
"STA will stay up"
};
static const true_false_string md_flags = {
"Data is buffered for STA at AP",
"No data buffered"
};
static const true_false_string protected_flags = {
"Data is protected",
"Data is not protected"
};
static const true_false_string order_flags = {
"Strictly ordered",
"Not strictly ordered"
};
static const true_false_string cf_ess_flags = {
"Transmitter is an AP",
"Transmitter is a STA"
};
static const true_false_string cf_privacy_flags = {
"AP/STA can support WEP",
"AP/STA cannot support WEP"
};
static const true_false_string cf_preamble_flags = {
"Short preamble allowed",
"Short preamble not allowed"
};
static const true_false_string cf_pbcc_flags = {
"PBCC modulation allowed",
"PBCC modulation not allowed"
};
static const true_false_string cf_agility_flags = {
"Channel agility in use",
"Channel agility not in use"
};
static const true_false_string short_slot_time_flags = {
"Short slot time in use",
"Short slot time not in use"
};
static const true_false_string dsss_ofdm_flags = {
"DSSS-OFDM modulation allowed",
"DSSS-OFDM modulation not allowed"
};
static const true_false_string cf_spec_man_flags = {
"dot11SpectrumManagementRequired TRUE",
"dot11SpectrumManagementRequired FALSE"
};
static const true_false_string cf_apsd_flags = {
"apsd implemented",
"apsd not implemented"
};
static const true_false_string cf_del_blk_ack_flags = {
"delayed block ack implemented",
"delayed block ack not implemented"
};
static const true_false_string cf_imm_blk_ack_flags = {
"immediate block ack implemented",
"immediate block ack not implemented"
};
static const true_false_string cf_ibss_flags = {
"Transmitter belongs to an IBSS",
"Transmitter belongs to a BSS"
};
static const true_false_string eosp_flag = {
"End of service period",
"Service period"
};
static const true_false_string bit4_flag = {
"Bits 8-15 of QoS Control field are Queue Size",
"Bits 8-15 of QoS Control field are TXOP Duration Requested"
};
static const true_false_string ieee80211_qos_amsdu_present_flag = {
"A-MSDU",
"MSDU"
};
static const value_string sta_cf_pollable[] = {
{0x00, "Station is not CF-Pollable"},
{0x02, "Station is CF-Pollable, "
"not requesting to be placed on the CF-polling list"},
{0x01, "Station is CF-Pollable, "
"requesting to be placed on the CF-polling list"},
{0x03, "Station is CF-Pollable, requesting never to be polled"},
{0x0200, "QSTA requesting association in QBSS"},
{0, NULL}
};
static const value_string ap_cf_pollable[] = {
{0x00, "No point coordinator at AP"},
{0x02, "Point coordinator at AP for delivery only (no polling)"},
{0x01, "Point coordinator at AP for delivery and polling"},
{0x03, "Reserved"},
{0x0200, "QAP (HC) does not use CFP for delivery of unicast data type frames"},
{0x0202, "QAP (HC) uses CFP for delivery, but does not send CF-Polls to non-QoS STAs"},
{0x0201, "QAP (HC) uses CFP for delivery, and sends CF-Polls to non-QoS STAs"},
{0x0203, "Reserved"},
{0, NULL}
};
static const value_string auth_alg[] = {
{0x00, "Open System"},
{0x01, "Shared key"},
{0x02, "Fast BSS Transition"},
{0x80, "Network EAP"},
{0, NULL}
};
static const true_false_string ff_block_ack_params_amsdu_permitted_flag = {
"Permitted in QoS Data MPDUs",
"Not Permitted"
};
static const true_false_string ff_block_ack_params_policy_flag = {
"Immediate Block Ack",
"Delayed Block Ack"
};
static const value_string ff_channel_width_vals[] = {
{0x00, "20 MHz channel width only"},
{0x01, "Any channel width in the STA's Supported Channel Width Set"},
{0, NULL}
};
static const true_false_string ff_qos_info_ap_q_ack_flag = {
"Implemented",
"Not Implemented"
};
static const true_false_string ff_qos_info_ap_queue_req_flag = {
"Can process a nonzero Queue Size subfield in the QoS Control field in QoS data frames",
"Can NOT process a nonzero Queue Size subfield in the QoS Control field in QoS data frames"
};
static const true_false_string ff_qos_info_ap_txop_request_flag = {
"Can process a nonzero TXOP Duration Requested subfield in the QoS Control field in QoS data frames",
"Can NOT process a nonzero TXOP Duration Requested subfield in the QoS Control field in QoS data frames"
};
static const true_false_string ff_qos_info_sta_ac_flag = {
"Trigger-enabled and Delivery-enabled",
"Neither Trigger-enabled nor Delivery-enabled"
};
static const true_false_string ff_qos_info_sta_q_ack_flag = {
"Implemented",
"Not Implemented"
};
static const value_string ff_qos_info_sta_max_sp_len_flags[] = {
{0x00, "AP may deliver all buffered MSDUs, A-MSDUs and MMPDUs"},
{0x01, "AP may deliver a maximum of two MSDUs and MMPDUs per SP"},
{0x02, "AP may deliver a maximum of four MSDUs and MMPDUs per SP"},
{0x03, "AP may deliver a maximum of six MSDUs and MMPDUs per SP"},
{0, NULL}
};
static const true_false_string ff_qos_info_sta_more_data_ack_flag = {
"Can process ACK frames with the More Data bit in the Frame Control field set to 1",
"Can NOT process ACK frames with the More Data bit in the Frame Control field set to 1"
};
static const true_false_string ff_sm_pwr_save_sm_mode_flag = {
"Dynamic SM Power Save mode",
"Static SM Power Save mode"
};
static const true_false_string ff_pco_phase_cntrl_flag = {
"40 MHz Phase",
"20 MHz Phase"
};
static const true_false_string ff_psmp_param_set_more_psmp_flag = {
"More PSMP Sequences Follow",
"No PSMP Sequences Follow"
};
static const value_string ff_mimo_cntrl_nc_index_flags[] = {
{0x00, "1 Column"},
{0x01, "2 Columns"},
{0x02, "3 Columns"},
{0x03, "4 Columns"},
{0, NULL}
};
static const value_string ff_mimo_cntrl_nr_index_flags[] = {
{0x00, "1 Row"},
{0x01, "2 Rows"},
{0x02, "3 Rows"},
{0x03, "4 Rows"},
{0, NULL}
};
static const true_false_string ff_mimo_cntrl_channel_width_flag = {
"40 MHz",
"20 MHz"
};
static const true_false_string ff_ht_info_information_request_flag = {
"Requesting HT Information Exchange management action frame",
"Should not send an HT Information Exchange management action frame"
};
static const true_false_string ff_ht_info_40_mhz_intolerant_flag = {
"Transmitting station is intolerant of 40 MHz operation",
"Transmitting station permits 40 MHz operation"
};
static const true_false_string ff_ht_info_sta_chan_width_flag = {
"40 MHz",
"20 MHz"
};
static const value_string ff_ht_action_flags[] = {
{HT_ACTION_NOTIFY_CHAN_WIDTH, "Notify Channel Width"},
{HT_ACTION_SM_PWR_SAVE, "Spatial Multiplexing (SM) Power Save"},
{HT_ACTION_PSMP_ACTION, "Power Save Multi-Poll (PSMP) action frame"},
{HT_ACTION_SET_PCO_PHASE, "Set PCO Phase"},
{HT_ACTION_MIMO_CSI, "MIMO CSI Matrices"},
{HT_ACTION_MIMO_BEAMFORMING, "MIMO Non-compressed Beamforming"},
{HT_ACTION_MIMO_COMPRESSED_BEAMFORMING, "MIMO Compressed Beamforming"},
{HT_ACTION_ANT_SEL_FEEDBACK, "Antenna Selection Indices Feedback"},
{HT_ACTION_HT_INFO_EXCHANGE, "HT Information Exchange"},
{0x00, NULL}
};
static const value_string ff_mimo_cntrl_grouping_flags[] = {
{0x00, "No Grouping"},
{0x01, "Carrier Groups of 2"},
{0x02, "Carrier Groups of 4"},
{0x03, "Reserved"},
{0, NULL}
};
static const value_string ff_mimo_cntrl_coefficient_size_flags[] = {
{0x00, "4 Bits"},
{0x01, "5 Bits"},
{0x02, "6 Bits"},
{0x03, "8 Bits"},
{0, NULL}
};
static const value_string ff_mimo_cntrl_codebook_info_flags[] = {
{0x00, "1 bit for 'Capital Psi', 3 bits for 'Small Psi'"},
{0x01, "2 bit for 'Capital Psi', 4 bits for 'Small Psi'"},
{0x02, "3 bit for 'Capital Psi', 5 bits for 'Small Psi'"},
{0x03, "4 bit for 'Capital Psi', 6 bits for 'Small Psi'"},
{0, NULL}
};
static const value_string ff_pa_action_codes[] = {
{PA_DSE_ENABLEMENT, "DSE enablement"},
{PA_DSE_DEENABLEMENT, "DSE deenablement"},
{PA_DSE_REG_LOC_ANNOUNCEMENT, "DSE Registered Location Announcement"},
{PA_EXT_CHANNEL_SWITCH_ANNOUNCEMENT, "Extended Channel Switch Announcement"},
{PA_DSE_MEASUREMENT_REQUEST, "DSE measurement request"},
{PA_DSE_MEASUREMENT_REPORT, "DSE measurement report"},
{PA_MEASUREMENT_PILOT, "Measurement Pilot"},
{PA_DSE_POWER_CONSTRAINT, "DSE power constraint"},
{PA_VENDOR_SPECIFIC, "Vendor Specific"},
{PA_GAS_INITIAL_REQUEST, "GAS Initial Request"},
{PA_GAS_INITIAL_RESPONSE, "GAS Initial Response"},
{PA_GAS_COMEBACK_REQUEST, "GAS Comeback Request"},
{PA_GAS_COMEBACK_RESPONSE, "GAS Comeback Response"},
{PA_TDLS_DISCOVERY_RESPONSE, "TDLS Discovery Response"},
{0x00, NULL}
};
static const value_string category_codes[] = {
{CAT_SPECTRUM_MGMT, "Spectrum Management (SM)"},
{0x80 | CAT_SPECTRUM_MGMT, "Spectrum Management (SM) (error)"},
{CAT_QOS, "Quality of Service (QoS)"},
{0x80 | CAT_QOS, "Quality of Service (QoS (error))"},
{CAT_DLS, "Direct-Link Setup (DLS)"},
{0x80 | CAT_DLS, "Direct-Link Setup (DLS) (error)"},
{CAT_BLOCK_ACK, "Block Ack"},
{0x80 | CAT_BLOCK_ACK, "Block Ack (error)"},
{CAT_PUBLIC, "Public Action"},
{0x80 | CAT_PUBLIC, "Public Action (error)"},
{CAT_RADIO_MEASUREMENT, "Radio Measurement"},
{0x80 | CAT_RADIO_MEASUREMENT, "Radio Measurement (error)"},
{CAT_FAST_BSS_TRANSITION, "Fast BSS Transition"},
{0x80 | CAT_FAST_BSS_TRANSITION, "Fast BSS Transition (error)"},
{CAT_HT, "High Throughput"},
{0x80 | CAT_HT, "High Throughput (error)"},
{CAT_SA_QUERY, "SA Query"},
{0x80 | CAT_SA_QUERY, "SA Query (error)"},
{CAT_PUBLIC_PROTECTED, "Protected Dual of Public Action"},
{0x80 | CAT_PUBLIC_PROTECTED, "Protected Dual of Public Action (error)"},
{CAT_WNM, "WNM"},
{0x80 | CAT_WNM, "WNM (error)"},
{CAT_UNPROTECTED_WNM, "Unprotected WNM"},
{0x80 | CAT_UNPROTECTED_WNM, "Unprotected WNM (error)"},
{CAT_TDLS, "TDLS"},
{0x80 | CAT_TDLS, "TDLS (error)"},
{CAT_MESH, "MESH"},
{0x80 | CAT_MESH, "Mesh (error)"},
{CAT_MULTIHOP, "Multihop"},
{0x80 | CAT_MULTIHOP, "Multihop (error)"},
{CAT_SELF_PROTECTED, "Self-protected"},
{0x80 | CAT_SELF_PROTECTED, "Self-protected (error)"},
{CAT_MGMT_NOTIFICATION, "Management Notification"},
{0x80 | CAT_MGMT_NOTIFICATION, "Management Notification (error)"},
{CAT_VENDOR_SPECIFIC_PROTECTED, "Vendor-specific Protected"},
{0x80 | CAT_VENDOR_SPECIFIC_PROTECTED, "Vendor-specific Protected (error)"},
{CAT_VENDOR_SPECIFIC, "Vendor Specific"},
{0x80 | CAT_VENDOR_SPECIFIC, "Vendor Specific (error)"},
{0, NULL}
};
static const value_string action_codes[] ={
{SM_ACTION_MEASUREMENT_REQUEST, "Measurement Request"},
{SM_ACTION_MEASUREMENT_REPORT, "Measurement Report"},
{SM_ACTION_TPC_REQUEST, "TPC Request"},
{SM_ACTION_TPC_REPORT, "TPC Report"},
{SM_ACTION_CHAN_SWITCH_ANNC, "Channel Switch Announcement"},
{0, NULL}
};
static const value_string vendor_action_types_mrvl[] ={
{MRVL_ACTION_MESH_MANAGEMENT, "Mesh Management"},
{0, NULL}
};
static const value_string mesh_mgt_action_codes_mrvl[] ={
{MRVL_MESH_MGMT_ACTION_RREQ, "Route Request"},
{MRVL_MESH_MGMT_ACTION_RREP, "Route Response"},
{MRVL_MESH_MGMT_ACTION_RERR, "Route Error"},
{MRVL_MESH_MGMT_ACTION_PLDM, "Peer Link Down"},
{0, NULL}
};
static const value_string mesh_path_selection_codes[] ={
{0x0, "Hybrid Wireless Mesh Protocol"},
{0, NULL}
};
static const value_string mesh_metric_codes[] ={
{0x0, "Airtime Link Metric"},
{0, NULL}
};
static const value_string wme_action_codes[] = {
{0x00, "Setup request"},
{0x01, "Setup response"},
{0x02, "Teardown"},
{0x00, NULL}
};
static const value_string wme_status_codes[] = {
{0x00, "Admission accepted"},
{0x01, "Invalid parameters"},
{0x03, "Refused"},
{0x00, NULL}
};
static const value_string mesh_action[] ={
{MESH_ACTION_LINK_METRIC_REPORT, "Mesh Link Metric Report"},
{MESH_ACTION_HWMP, "HWMP Mesh Path Selection"},
{MESH_ACTION_GATE_ANNOUNCE, "Gate Announcement"},
{MESH_ACTION_CONGESTION_CTL, "Congestion Control Notification"},
{MESH_ACTION_MCCA_SETUP_REQUEST, "MCCA Setup Request"},
{MESH_ACTION_MCCA_SETUP_REPLY, "MCCA Setup Reply"},
{MESH_ACTION_MCCA_ADV_REQUEST, "MCCA Advertisement Request"},
{MESH_ACTION_MCCA_ADV, "MCCA Advertisement"},
{MESH_ACTION_MCCA_TEARDOWN, "MCCA Teardown"},
{MESH_ACTION_TBTT_ADJ_REQUEST, "TBTT Adjustment Request"},
{MESH_ACTION_TBTT_ADJ_RESPONSE, "TBTT Adjustment Response"},
{0, NULL}
};
static const value_string multihop_action[] ={
{MULTIHOP_ACTION_PROXY_UPDATE, "Proxy Update"},
{MULTIHOP_ACTION_PROXY_UPDATE_CONF, "Proxy Update Confirmation"},
{0, NULL}
};
static const value_string selfprot_action[] = {
{SELFPROT_ACTION_MESH_PEERING_OPEN, "Mesh Peering Open"},
{SELFPROT_ACTION_MESH_PEERING_CONFIRM, "Mesh Peering Confirm"},
{SELFPROT_ACTION_MESH_PEERING_CLOSE, "Mesh Peering Close"},
{SELFPROT_ACTION_MESH_GROUP_KEY_INFORM, "Mesh Group Key Inform"},
{SELFPROT_ACTION_MESH_GROUP_KEY_ACK, "Mesh Group Key Ack"},
{0, NULL}
};
static const value_string mesh_peering_proto_ids[] = {
{MESH_PEERING_PROTO_MGMT, "Mesh peering management protocol"},
{MESH_PEERING_PROTO_AMPE, "Authenticated mesh peering exchange protocol"},
{MESH_PEERING_PROTO_VENDOR, "Vendor specific"},
{0, NULL}
};
static const true_false_string hwmp_targ_usn_flags = {
"[USN = 1] Target Sequence Number Unknown at Originator",
"[USN = 0] Target Sequence Number Known at Originator"
};
static const true_false_string hwmp_targ_to_flags = {
"[TO = 1] Only Target Will Respond",
"[TO = 0] Intermediate Nodes May Respond"
};
static const value_string ack_policy[] = {
{0x00, "Normal Ack"},
{0x01, "No Ack"},
{0x02, "No explicit acknowledgment"},
{0x03, "Block Ack"},
{0x00, NULL}
};
static const value_string qos_action_codes[] = {
{SM_ACTION_ADDTS_REQUEST, "ADDTS Request"},
{SM_ACTION_ADDTS_RESPONSE, "ADDTS Response"},
{SM_ACTION_DELTS, "DELTS"},
{SM_ACTION_QOS_SCHEDULE, "Schedule"},
{0, NULL}
};
static const value_string ba_action_codes[] = {
{BA_ADD_BLOCK_ACK_REQUEST, "Add Block Ack Request"},
{BA_ADD_BLOCK_ACK_RESPONSE, "Add Block Ack Response"},
{BA_DELETE_BLOCK_ACK, "Delete Block Ack"},
{0x00, NULL}
};
static const value_string dls_action_codes[] = {
{SM_ACTION_DLS_REQUEST, "DLS Request"},
{SM_ACTION_DLS_RESPONSE, "DLS Response"},
{SM_ACTION_DLS_TEARDOWN, "DLS Teardown"},
{0, NULL}
};
static const value_string tsinfo_type[] = {
{0x0, "Aperiodic or unspecified Traffic"},
{0x1, "Periodic Traffic"},
{0, NULL}
};
static const value_string tsinfo_direction[] = {
{0x00, "Uplink"},
{0x01, "Downlink"},
{0x02, "Direct link"},
{0x03, "Bidirectional link"},
{0, NULL}
};
static const value_string tsinfo_access[] = {
{0x00, "Reserved"},
{0x01, "EDCA"},
{0x02, "HCCA"},
{0x03, "HEMM"},
{0, NULL}
};
static const value_string qos_up[] = {
{0x00, "Best Effort"},
{0x01, "Background"},
{0x02, "Spare"},
{0x03, "Excellent Effort"},
{0x04, "Controlled Load"},
{0x05, "Video"},
{0x06, "Voice"},
{0x07, "Network Control"},
{0, NULL}
};
static const value_string classifier_type[] = {
{0x00, "Ethernet parameters"},
{0x01, "TCP/UDP IP parameters"},
{0x02, "IEEE 802.1D/Q parameters"},
{0, NULL}
};
static const true_false_string ieee80211_block_ack_control_ack_policy_flag = {
"Immediate Acknowledgement Required",
"Sender Does Not Require Immediate Acknowledgement"
};
static const value_string ieee80211_block_ack_request_type_flags[] = {
{0x00, "Basic Block Ack Request"},
{0x01, "Reserved"},
{0x02, "Compressed Block Ack Request"},
{0x03, "Multi-TID Block Ack Request"},
{0x00, NULL}
};
static const value_string ieee80211_block_ack_type_flags[] = {
{0x00, "Basic Block Ack"},
{0x01, "Reserved"},
{0x02, "Compressed Block"},
{0x03, "Multi-TID Block"},
{0x00, NULL}
};
static const value_string ft_action_codes[] ={
{FT_ACTION_REQUEST, "FT Request"},
{FT_ACTION_RESPONSE, "FT Response"},
{FT_ACTION_CONFIRM, "FT Confirm"},
{FT_ACTION_ACK, "FT Ack"},
{0, NULL}
};
static const value_string sa_query_action_codes[] ={
{SA_QUERY_REQUEST, "SA Query Request"},
{SA_QUERY_RESPONSE, "SA Query Response"},
{0, NULL}
};
static const value_string ieee80211_data_encap_payload_types[] = {
{1, "Remote Request/Response"},
{2, "TDLS"},
{0, NULL}
};
static hf_register_info hf[] = {
{&hf_ieee80211_fc_field,
{"Frame Control Field", "wlan.fc", FT_UINT16, BASE_HEX, NULL, 0,
"MAC Frame control", HFILL }},
{&hf_ieee80211_fc_proto_version,
{"Version", "wlan.fc.version", FT_UINT8, BASE_DEC, NULL, 0,
"MAC Protocol version", HFILL }},
{&hf_ieee80211_fc_frame_type,
{"Type", "wlan.fc.type", FT_UINT8, BASE_DEC, VALS(frame_type), 0,
"Frame type", HFILL }},
{&hf_ieee80211_fc_frame_subtype,
{"Subtype", "wlan.fc.subtype", FT_UINT8, BASE_DEC, NULL, 0,
"Frame subtype", HFILL }},
{&hf_ieee80211_fc_frame_type_subtype,
{"Type/Subtype", "wlan.fc.type_subtype", FT_UINT8, BASE_HEX, VALS(frame_type_subtype_vals), 0,
"Type and subtype combined (first byte: type, second byte: subtype)", HFILL }},
{&hf_ieee80211_fc_flags,
{"Protocol Flags", "wlan.flags", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_fc_data_ds,
{"DS status", "wlan.fc.ds", FT_UINT8, BASE_HEX, VALS (&tofrom_ds), (FLAG_FROM_DS|FLAG_TO_DS),
"Data-frame DS-traversal status", HFILL }},
{&hf_ieee80211_fc_to_ds,
{"To DS", "wlan.fc.tods", FT_BOOLEAN, 8, TFS (&tods_flag), FLAG_TO_DS,
"To DS flag", HFILL }},
{&hf_ieee80211_fc_from_ds,
{"From DS", "wlan.fc.fromds", FT_BOOLEAN, 8, TFS (&fromds_flag), FLAG_FROM_DS,
"From DS flag", HFILL }},
{&hf_ieee80211_fc_more_frag,
{"More Fragments", "wlan.fc.frag", FT_BOOLEAN, 8, TFS (&more_frags), FLAG_MORE_FRAGMENTS,
"More Fragments flag", HFILL }},
{&hf_ieee80211_fc_retry,
{"Retry", "wlan.fc.retry", FT_BOOLEAN, 8, TFS (&retry_flags), FLAG_RETRY,
"Retransmission flag", HFILL }},
{ &hf_ieee80211_fc_analysis_retransmission,
{"Retransmission", "wlan.analysis.retransmission", FT_NONE, BASE_NONE,
NULL, 0x0, "This frame is a suspected wireless retransmission", HFILL }},
{ &hf_ieee80211_fc_analysis_retransmission_frame,
{"Retransmission of frame", "wlan.analysis.retransmission_frame", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "This is a retransmission of frame #", HFILL }},
{&hf_ieee80211_fc_pwr_mgt,
{"PWR MGT", "wlan.fc.pwrmgt", FT_BOOLEAN, 8, TFS (&pm_flags), FLAG_POWER_MGT,
"Power management status", HFILL }},
{&hf_ieee80211_fc_more_data,
{"More Data", "wlan.fc.moredata", FT_BOOLEAN, 8, TFS (&md_flags), FLAG_MORE_DATA,
"More data flag", HFILL }},
{&hf_ieee80211_fc_protected,
{"Protected flag", "wlan.fc.protected", FT_BOOLEAN, 8, TFS (&protected_flags), FLAG_PROTECTED,
NULL, HFILL }},
{&hf_ieee80211_fc_order,
{"Order flag", "wlan.fc.order", FT_BOOLEAN, 8, TFS (&order_flags), FLAG_ORDER,
"Strictly ordered flag", HFILL }},
{&hf_ieee80211_assoc_id,
{"Association ID","wlan.aid",FT_UINT16, BASE_DEC, NULL, 0x3FFF,
"Association-ID field", HFILL }},
{&hf_ieee80211_did_duration,
{"Duration", "wlan.duration", FT_UINT16, BASE_DEC, NULL, 0,
"Duration field", HFILL }},
{&hf_ieee80211_addr_da,
{"Destination address", "wlan.da", FT_ETHER, BASE_NONE, NULL, 0,
"Destination Hardware Address", HFILL }},
{&hf_ieee80211_addr_sa,
{"Source address", "wlan.sa", FT_ETHER, BASE_NONE, NULL, 0,
"Source Hardware Address", HFILL }},
{ &hf_ieee80211_addr,
{"Hardware address", "wlan.addr", FT_ETHER, BASE_NONE, NULL, 0,
"SA, DA, BSSID, RA or TA Hardware Address", HFILL }},
{&hf_ieee80211_addr_ra,
{"Receiver address", "wlan.ra", FT_ETHER, BASE_NONE, NULL, 0,
"Receiving Station Hardware Address", HFILL }},
{&hf_ieee80211_addr_ta,
{"Transmitter address", "wlan.ta", FT_ETHER, BASE_NONE, NULL, 0,
"Transmitting Station Hardware Address", HFILL }},
{&hf_ieee80211_addr_bssid,
{"BSS Id", "wlan.bssid", FT_ETHER, BASE_NONE, NULL, 0,
"Basic Service Set ID", HFILL }},
{&hf_ieee80211_frag_number,
{"Fragment number", "wlan.frag", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_seq_number,
{"Sequence number", "wlan.seq", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qos_tid,
{"TID", "wlan.qos.tid", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qos_priority,
{"Priority", "wlan.qos.priority", FT_UINT16, BASE_DEC, NULL, 0,
"802.1D Tag", HFILL }},
{&hf_ieee80211_qos_eosp,
{"EOSP", "wlan.qos.eosp", FT_BOOLEAN, 8, TFS (&eosp_flag), QOS_FLAG_EOSP,
"EOSP Field", HFILL }},
{&hf_ieee80211_qos_bit4,
{"QoS bit 4", "wlan.qos.bit4", FT_BOOLEAN, 8, TFS (&bit4_flag), QOS_FLAG_EOSP,
NULL, HFILL }},
{&hf_ieee80211_qos_ack_policy,
{"Ack Policy", "wlan.qos.ack", FT_UINT8, BASE_HEX, VALS (&ack_policy), 0,
NULL, HFILL }},
{&hf_ieee80211_qos_amsdu_present,
{"Payload Type", "wlan.qos.amsdupresent", FT_BOOLEAN, BASE_NONE,
TFS(&ieee80211_qos_amsdu_present_flag), 0x0, NULL, HFILL }},
{&hf_ieee80211_qos_txop_limit,
{"TXOP Limit", "wlan.qos.txop_limit", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qos_buf_state_indicated,
{"Buffer State Indicated", "wlan.qos.buf_state_indicated",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }},
{&hf_ieee80211_qos_highest_pri_buf_ac,
{"Highest-Priority Buffered AC", "wlan.qos.highest_pri_buf_ac",
FT_UINT8, BASE_DEC, VALS(wme_acs), 0x0C,
NULL, HFILL }},
{&hf_ieee80211_qos_qap_buf_load,
{"QAP Buffered Load", "wlan.qos.qap_buf_load",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }},
{&hf_ieee80211_qos_txop_dur_req,
{"TXOP Duration Requested", "wlan.qos.txop_dur_req", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_qos_queue_size,
{"Queue Size", "wlan.qos.queue_size", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_fcs,
{"Frame check sequence", "wlan.fcs", FT_UINT32, BASE_HEX,
NULL, 0, "Frame Check Sequence (FCS)", HFILL }},
{&hf_ieee80211_fcs_good,
{"Good", "wlan.fcs_good", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "True if the FCS is correct", HFILL }},
{&hf_ieee80211_fcs_bad,
{"Bad", "wlan.fcs_bad", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "True if the FCS is incorrect", HFILL }},
{&hf_ieee80211_fragment_overlap,
{"Fragment overlap", "wlan.fragment.overlap", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Fragment overlaps with other fragments", HFILL }},
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
{"Fragment count", "wlan.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_fragment,
{"802.11 Fragment", "wlan.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_fragments,
{"802.11 Fragments", "wlan.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_reassembled_in,
{"Reassembled 802.11 in frame", "wlan.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This 802.11 packet is reassembled in this frame", HFILL }},
{&hf_ieee80211_reassembled_length,
{"Reassembled 802.11 length", "wlan.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{&hf_ieee80211_wep_iv,
{"Initialization Vector", "wlan.wep.iv", FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wep_iv_weak,
{"Weak IV", "wlan.wep.weakiv", FT_BOOLEAN, BASE_NONE, NULL,0x0,
NULL,HFILL}},
{&hf_ieee80211_tkip_extiv,
{"TKIP Ext. Initialization Vector", "wlan.tkip.extiv", FT_STRING,
BASE_NONE, NULL, 0, "TKIP Extended Initialization Vector", HFILL }},
{&hf_ieee80211_ccmp_extiv,
{"CCMP Ext. Initialization Vector", "wlan.ccmp.extiv", FT_STRING,
BASE_NONE, NULL, 0, "CCMP Extended Initialization Vector", HFILL }},
{&hf_ieee80211_wep_key,
{"Key Index", "wlan.wep.key", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_wep_icv,
{"WEP ICV", "wlan.wep.icv", FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_block_ack_request_control,
{"Block Ack Request (BAR) Control", "wlan.bar.control",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_block_ack_control,
{"Block Ack Request Control", "wlan.ba.control",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_block_ack_control_ack_policy,
{"BAR Ack Policy", "wlan.ba.control.ackpolicy",
FT_BOOLEAN, 16, TFS (&ieee80211_block_ack_control_ack_policy_flag), 0x01, "Block Ack Request (BAR) Ack Policy", HFILL }},
{&hf_ieee80211_block_ack_control_multi_tid,
{"Multi-TID", "wlan.ba.control.multitid",
FT_BOOLEAN, 16, 0, 0x02, "Multi-Traffic Identifier (TID)", HFILL }},
{&hf_ieee80211_block_ack_control_compressed_bitmap,
{"Compressed Bitmap", "wlan.ba.control.cbitmap",
FT_BOOLEAN, 16, 0, 0x04, NULL, HFILL }},
{&hf_ieee80211_block_ack_control_reserved,
{"Reserved", "wlan.ba.control.cbitmap",
FT_UINT16, BASE_HEX, NULL, 0x0ff8, NULL, HFILL }},
{&hf_ieee80211_block_ack_control_basic_tid_info,
{"TID for which a Basic BlockAck frame is requested", "wlan.ba.basic.tidinfo",
FT_UINT16, BASE_HEX, NULL, 0xf000, "Traffic Identifier (TID) for which a Basic BlockAck frame is requested", HFILL }},
{&hf_ieee80211_block_ack_control_compressed_tid_info,
{"TID for which a BlockAck frame is requested", "wlan.bar.compressed.tidinfo",
FT_UINT16, BASE_HEX, NULL, 0xf000, "Traffic Identifier (TID) for which a BlockAck frame is requested", HFILL }},
{&hf_ieee80211_block_ack_control_multi_tid_info,
{"Number of TIDs Present", "wlan.ba.mtid.tidinfo",
FT_UINT16, BASE_HEX, NULL, 0xf000, "Number of Traffic Identifiers (TIDs) Present", HFILL }},
{&hf_ieee80211_block_ack_multi_tid_info,
{"Traffic Identifier (TID) Info", "wlan.ba.mtid.tid",
FT_UINT8, BASE_DEC, 0, 0, NULL, HFILL }},
{&hf_ieee80211_block_ack_multi_tid_reserved,
{"Reserved", "wlan.bar.mtid.tidinfo.reserved",
FT_UINT16, BASE_HEX, 0, 0x0fff, NULL, HFILL }},
{&hf_ieee80211_block_ack_multi_tid_value,
{"Multi-TID Value", "wlan.bar.mtid.tidinfo.value",
FT_UINT16, BASE_HEX, 0, 0xf000, NULL, HFILL }},
{&hf_ieee80211_block_ack_request_type,
{"Block Ack Request Type", "wlan.bar.type",
FT_UINT8, BASE_HEX, VALS(ieee80211_block_ack_request_type_flags), 0, "Block Ack Request (BAR) Type", HFILL }},
{&hf_ieee80211_block_ack_type,
{"Block Ack Type", "wlan.ba.type",
FT_UINT8, BASE_HEX, VALS(ieee80211_block_ack_type_flags), 0, NULL, HFILL }},
{&hf_ieee80211_block_ack_bitmap,
{"Block Ack Bitmap", "wlan.ba.bm",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_block_ack_bitmap_missing_frame,
{"Missing frame", "wlan.ba.bm.missing_frame",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_data_encap_payload_type,
{"Payload Type", "wlan.data_encap.payload_type",
FT_UINT8, BASE_DEC, VALS(ieee80211_data_encap_payload_types), 0, NULL,
HFILL }},
{&hf_ieee80211_ff_tdls_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_DEC, VALS(tdls_action_codes), 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_target_channel,
{"Target Channel", "wlan_mgt.fixed.target_channel",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_regulatory_class,
{"Regulatory Class", "wlan_mgt.fixed.regulatory_class",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_wnm_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_DEC, VALS(wnm_action_codes), 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_request_mode_pref_cand,
{"Preferred Candidate List Included",
"wlan_mgt.fixed.request_mode.pref_cand",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL }},
{&hf_ieee80211_ff_request_mode_abridged,
{"Abridged", "wlan_mgt.fixed.request_mode.abridged",
FT_UINT8, BASE_DEC, NULL, 0x02, NULL, HFILL }},
{&hf_ieee80211_ff_request_mode_disassoc_imminent,
{"Disassociation Imminent",
"wlan_mgt.fixed.request_mode.disassoc_imminent",
FT_UINT8, BASE_DEC, NULL, 0x04, NULL, HFILL }},
{&hf_ieee80211_ff_request_mode_bss_term_included,
{"BSS Termination Included",
"wlan_mgt.fixed.request_mode.bss_term_included",
FT_UINT8, BASE_DEC, NULL, 0x08, NULL, HFILL }},
{&hf_ieee80211_ff_request_mode_ess_disassoc_imminent,
{"ESS Disassociation Imminent",
"wlan_mgt.fixed.request_mode.ess_disassoc_imminent",
FT_UINT8, BASE_DEC, NULL, 0x10, NULL, HFILL }},
{&hf_ieee80211_ff_disassoc_timer,
{"Disassociation Timer", "wlan_mgt.fixed.disassoc_timer",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_validity_interval,
{"Validity Interval", "wlan_mgt.fixed.validity_interval",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_url_len,
{"Session Information URL Length",
"wlan_mgt.fixed.session_information.url_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_url,
{"Session Information URL", "wlan_mgt.fixed.session_information.url",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static const true_false_string qos_info_field_qack_flags = {
"STAs/APs MIB attribute dot11QAckOptionImplemented is true",
"STAs/APs MIB attribute dot11QAckOptionImplemented is false"
};
static const true_false_string qos_info_field_more_data_ack_flags = {
"STA can process Ack frames with More Data bit and will remain in the awake state.",
"STA cannot process Ack frames with More Data bit in Frame Controll field."
};
static const true_false_string qos_info_field_queue_req_flags = {
"AP can process a nonzero Queue Size subfield in the QoS Control field in QoS data frames",
"AP cannot process Queue Size subfield in QoS data frames."
};
static const value_string qos_info_field_max_sp_lenght_flags[] =
{
{ 0x0, "QAP may deliver all buffered MSDUs and MMPDUs." },
{ 0x2, "QAP may deliver a maximum of two MSDUs and MMPDUs per SP." },
{ 0x1, "QAP may deliver a maximum of four MSDUs and MMPDUs per SP." },
{ 0x3, "QAP may deliver a maximum of six MSDUs and MMPDUs per SP." },
{ 0, NULL}
};
static const true_false_string rsn_preauth_flags = {
"Transmitter supports pre-authentication",
"Transmitter does not support pre-authentication"
};
static const true_false_string rsn_no_pairwise_flags = {
"Transmitter cannot support WEP default key 0 simultaneously with "
"Pairwise key",
"Transmitter can support WEP default key 0 simultaneously with "
"Pairwise key"
};
static const value_string rsn_cap_replay_counter[] = {
{0x00, "1 replay counter per PTKSA/GTKSA/STAKeySA"},
{0x01, "2 replay counters per PTKSA/GTKSA/STAKeySA"},
{0x02, "4 replay counters per PTKSA/GTKSA/STAKeySA"},
{0x03, "16 replay counters per PTKSA/GTKSA/STAKeySA"},
{0, NULL}
};
static const true_false_string ht_ldpc_coding_flag = {
"Transmitter supports receiving LDPC coded packets",
"Transmitter does not support receiving LDPC coded packets"
};
static const true_false_string ht_chan_width_flag = {
"Transmitter supports 20MHz and 40MHz operation",
"Transmitter only supports 20MHz operation"
};
static const value_string ht_sm_pwsave_flag[] = {
{0x00, "Static SM Power Save mode"},
{0x01, "Dynamic SM Power Save mode"},
{0x02, "Reserved"},
{0x03, "SM Power Save disabled"},
{0x00, NULL}
};
static const true_false_string ht_green_flag = {
"Transmitter is able to receive PPDUs with Green Field (GF) preamble",
"Transmitter is not able to receive PPDUs with Green Field (GF) preamble"
};
static const value_string ht_rx_stbc_flag[] = {
{0x00, "No Rx STBC support"},
{0x01, "Rx support of one spatial stream"},
{0x02, "Rx support of one and two spatial streams"},
{0x03, "Rx support of one, two, and three spatial streams"},
{0x00, NULL}
};
static const true_false_string ht_delayed_block_ack_flag = {
"Transmitter supports HT-Delayed BlockAck",
"Transmitter does not support HT-Delayed BlockAck"
};
static const true_false_string ht_max_amsdu_flag = {
"7935 bytes",
"3839 bytes"
};
static const true_false_string ht_dss_cck_40_flag = {
"Will/Can use DSSS/CCK in 40 MHz",
"Won't/Can't use of DSSS/CCK in 40 MHz"
};
static const true_false_string ht_psmp_flag = {
"Will/Can support PSMP operation",
"Won't/Can't support PSMP operation"
};
static const true_false_string ht_40_mhz_intolerant_flag = {
"Use of 40 MHz transmissions restricted/disallowed",
"Use of 40 MHz transmissions unrestricted/allowed"
};
static const value_string ampduparam_mpdu_start_spacing_flags[] = {
{0x00, "no restriction"},
{0x01, "1/4 [usec]"},
{0x02, "1/2 [usec]"},
{0x03, "1 [usec]"},
{0x04, "2 [usec]"},
{0x05, "4 [usec]"},
{0x06, "8 [usec]"},
{0x07, "16 [usec]"},
{0x00, NULL}
};
static const true_false_string mcsset_tx_mcs_set_defined_flag = {
"Defined",
"Not Defined",
};
static const true_false_string mcsset_tx_rx_mcs_set_not_equal_flag = {
"Not Equal",
"Equal",
};
static const value_string mcsset_tx_max_spatial_streams_flags[] = {
{0x00, "1 spatial stream"},
{0x01, "2 spatial streams"},
{0x02, "3 spatial streams"},
{0x03, "4 spatial streams"},
{0x00, NULL}
};
static const value_string htex_transtime_flags[] = {
{0x00, "No Transition"},
{0x01, "400 usec"},
{0x02, "1.5 msec"},
{0x03, "5 msec"},
{0x00, NULL}
};
static const value_string htex_mcs_flags[] = {
{0x00, "STA does not provide MCS feedback"},
{0x01, "Reserved"},
{0x02, "STA provides only unsolicited MCS feedback"},
{0x03, "STA can provide MCS feedback in response to MRQ as well as unsolicited MCS feedback"},
{0x00, NULL}
};
static const value_string txbf_calib_flag[] = {
{0x00, "incapable"},
{0x01, "Limited involvement, cannot initiate"},
{0x02, "Limited involvement, can initiate"},
{0x03, "Fully capable"},
{0x00, NULL}
};
static const value_string txbf_feedback_flags[] = {
{0x00, "not supported"},
{0x01, "delayed feedback capable"},
{0x02, "immediate feedback capable"},
{0x03, "delayed and immediate feedback capable"},
{0x00, NULL}
};
static const value_string txbf_antenna_flags[] = {
{0x00, "1 TX antenna sounding"},
{0x01, "2 TX antenna sounding"},
{0x02, "3 TX antenna sounding"},
{0x03, "4 TX antenna sounding"},
{0x00, NULL}
};
static const value_string txbf_csi_max_rows_bf_flags[] = {
{0x00, "1 row of CSI"},
{0x01, "2 rows of CSI"},
{0x02, "3 rows of CSI"},
{0x03, "4 rows of CSI"},
{0x00, NULL}
};
static const value_string txbf_chan_est_flags[] = {
{0x00, "1 space time stream"},
{0x01, "2 space time streams"},
{0x02, "3 space time streams"},
{0x03, "4 space time streams"},
{0x00, NULL}
};
static const value_string txbf_min_group_flags[] = {
{0x00, "No grouping supported"},
{0x01, "Groups of 1,2 supported"},
{0x02, "Groups of 1,4 supported"},
{0x03, "Groups of 1,2,4 supported"},
{0x00, NULL}
};
static const value_string hta_ext_chan_offset_flag[] = {
{0x00, "No Extension Channel"},
{0x01, "Extension Channel above control channel"},
{0x02, "Undefined"},
{0x03, "Extension Channel below control channel"},
{0x00, NULL}
};
static const true_false_string hta_rec_tx_width_flag = {
"Any channel width enabled",
"Use 20MHz channel (control)"
};
static const true_false_string hta_rifs_mode_flag = {
"Use of RIFS permitted",
"Use of RIFS prohibited"
};
static const true_false_string hta_controlled_access_flag = {
"Not only PSMP",
"PSMP only"
};
static const value_string hta_service_interval_flag[] = {
{0x00, "5ms"},
{0x01, "10ms"},
{0x02, "15ms"},
{0x03, "20ms"},
{0x04, "25ms"},
{0x05, "30ms"},
{0x06, "35ms"},
{0x07, "40ms"},
{0x00, NULL}
};
static const value_string hta_operating_mode_flag[] = {
{0x00, "Pure HT, no protection"},
{0x01, "There may be non-HT devices (control & ext channel)"},
{0x02, "No non-HT is associated, but at least 1 20MHz is. protect on"},
{0x03, "Mixed: no non-HT is associated, protect on"},
{0x00, NULL}
};
static const true_false_string hta_non_gf_devices_flag = {
"All HT devices associated are GF capable",
"One or More HT devices are not GF capable"
};
static const true_false_string hta_dual_stbc_protection_flag = {
"Dual CTS protections is used",
"Regular use of RTS/CTS"
};
static const true_false_string hta_secondary_beacon_flag = {
"Secondary Beacon",
"Primary Beacon"
};
static const true_false_string hta_lsig_txop_protection_flag = {
"Full Support",
"Not full support"
};
static const true_false_string hta_pco_active_flag = {
"PCO is activated in the BSS",
"PCO is not activated in the BSS"
};
static const true_false_string hta_pco_phase_flag = {
"Switch to 20MHz phase/keep 20MHz",
"Switch to 40MHz phase/keep 40MHz"
};
static const value_string ht_info_secondary_channel_offset_flags[] = {
{0x00, "No secondary channel"},
{0x01, "Secondary channel is above the primary channel"},
{0x02, "Reserved"},
{0x03, "Secondary channel is below the primary channel"},
{0x00, NULL}
};
static const true_false_string ht_info_channel_width_flag = {
"Channel of any width supported",
"20 MHz channel width only"
};
static const true_false_string ht_info_rifs_mode_flag = {
"Permitted",
"Prohibited"
};
static const true_false_string ht_info_psmp_stas_only_flag = {
"Association requests are accepted from only PSMP capable STA",
"Association requests are accepted regardless of PSMP capability"
};
static const value_string ht_info_service_interval_granularity_flags[] = {
{0x00, "5 ms"},
{0x01, "10 ms"},
{0x02, "15 ms"},
{0x03, "20 ms"},
{0x04, "25 ms"},
{0x05, "30 ms"},
{0x06, "35 ms"},
{0x07, "40 ms"},
{0x00, NULL}
};
static const value_string ht_info_operating_mode_flags[] = {
{0x00, "All STAs are - 20/40 MHz HT or in a 20/40 MHz BSS or are 20 MHz HT in a 20 MHz BSS"},
{0x01, "HT non-member protection mode"},
{0x02, "Only HT STAs in the BSS, however, there exists at least one 20 MHz STA"},
{0x03, "HT mixed mode"},
{0x00, NULL}
};
static const true_false_string ht_info_non_greenfield_sta_present_flag = {
"One or more associated STAs are not greenfield capable",
"All associated STAs are greenfield capable"
};
static const true_false_string ht_info_transmit_burst_limit_flag = {
"2.4 GHz - 6.16 ms | All other bands - 3.08 ms",
"No limit"
};
static const true_false_string ht_info_obss_non_ht_stas_present_flag = {
"Use of protection for non-HT STAs by overlapping BSSs is needed",
"Use of protection for non-HT STAs by overlapping BSSs is not needed"
};
static const true_false_string ht_info_dual_beacon_flag = {
"AP transmits a secondary beacon",
"No second beacon is transmitted"
};
static const true_false_string ht_info_dual_cts_protection_flag = {
"Required",
"Not required"
};
static const true_false_string ht_info_secondary_beacon_flag = {
"Secondary beacon",
"Primary beacon"
};
static const true_false_string ht_info_lsig_txop_protection_full_support_flag = {
"All HT STAs in the BSS support L-SIG TXOP protection",
"One or more HT STAs in the BSS do not support L-SIG TXOP protection"
};
static const true_false_string ht_info_pco_phase_flag = {
"Switch to or continue 40 MHz phase",
"Switch to or continue 20 MHz phase"
};
static const true_false_string htc_lac_trq_flag = {
"Want sounding PPDU",
"Don't want sounding PPDU"
};
static const true_false_string htc_lac_mai_mrq_flag = {
"MCS feedback requested",
"No MCS feedback requested"
};
static const value_string ieee80211_htc_lac_asel_command_flags[] = {
{0x00, "Transmit Antenna Selection Sounding Indication (TXASSI)"},
{0x01, "Transmit Antenna Selection Sounding Request (TXASSR)"},
{0x02, "Receive Antenna Selection Sounding Indication (RXASSI)"},
{0x03, "Receive Antenna Selection Sounding Request (RXASSR)"},
{0x04, "Sounding Label"},
{0x05, "No feedback, ASEL training failure"},
{0x06, "Transmit Antenna Selection Sounding Indication (TXASSI) requesting feedback of explicit CSI"},
{0x07, "Reserved"},
{0x00, NULL}
};
static const value_string ieee80211_htc_cal_pos_flags[] = {
{0x00, "Not a calibration frame"},
{0x01, "Calibration Start"},
{0x02, "Sounding Response"},
{0x03, "Sounding Complete"},
{0x00, NULL}
};
static const true_false_string ieee80211_htc_ndp_announcement_flag = {
"NDP will follow",
"No NDP will follow"
};
static const value_string ieee80211_htc_csi_steering_flags[] = {
{0x00, "No feedback required"},
{0x01, "CSI"},
{0x02, "Non-compressed Beamforming Feedback Matrix"},
{0x03, "Compressed Beamforming Feedback Matrix"},
{0x00, NULL}
};
static const value_string ieee80211_tag_secondary_channel_offset_flags[] = {
{0x00, "No Secondary Channel"},
{0x01, "Above Primary Channel"},
{0x02, "Reserved"},
{0x03, "Below Primary Channel"},
{0x00, NULL}
};
static const value_string ieee80211_tag_ext_channel_switch_announcement_switch_mode_flags[] = {
{0x00, "Frames may be transmitted before the channel switch has been completed"},
{0x01, "No more frames are to be transmitted until the channel switch has been completed"},
{0x00, NULL}
};
static const value_string service_interval_granularity_vals[] = {
{ 0, "5 ms" },
{ 1, "10 ms" },
{ 2, "15 ms" },
{ 3, "20 ms" },
{ 4, "25 ms" },
{ 5, "30 ms" },
{ 6, "35 ms" },
{ 7, "40 ms" },
{ 0x00, NULL }
};
static const value_string wep_type_vals[] = {
{ AIRPDCAP_KEY_TYPE_WEP, STRING_KEY_TYPE_WEP },
{ AIRPDCAP_KEY_TYPE_WPA_PWD, STRING_KEY_TYPE_WPA_PWD },
{ AIRPDCAP_KEY_TYPE_WPA_PSK, STRING_KEY_TYPE_WPA_PSK },
{ 0x00, NULL }
};
static hf_register_info ff[] = {
{&hf_ieee80211_ff_timestamp,
{"Timestamp", "wlan_mgt.fixed.timestamp", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_auth_alg,
{"Authentication Algorithm", "wlan_mgt.fixed.auth.alg",
FT_UINT16, BASE_DEC, VALS (&auth_alg), 0, NULL, HFILL }},
{&hf_ieee80211_ff_beacon_interval,
{"Beacon Interval", "wlan_mgt.fixed.beacon", FT_UINT32, BASE_CUSTOM, beacon_interval_base_custom, 0,
NULL, HFILL }},
{&hf_ieee80211_fixed_parameters,
{"Fixed parameters", "wlan_mgt.fixed.all", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tagged_parameters,
{"Tagged parameters", "wlan_mgt.tagged.all", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ssid,
{"SSID", "wlan_mgt.ssid", FT_STRING, BASE_NONE, NULL, 0,
"Indicates the identity of an ESS or IBSS", HFILL }},
{&hf_ieee80211_tag_supp_rates,
{"Supported Rates", "wlan_mgt.supported_rates",
FT_UINT8, BASE_HEX, VALS(ieee80211_supported_rates_vals), 0x0,
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
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_params_amsdu_permitted,
{"A-MSDUs", "wlan_mgt.fixed.baparams.amsdu",
FT_BOOLEAN, 16, TFS (&ff_block_ack_params_amsdu_permitted_flag), 0x0001, "A-MSDU Permitted in QoS Data MPDUs", HFILL }},
{&hf_ieee80211_ff_block_ack_params_policy,
{"Block Ack Policy", "wlan_mgt.fixed.baparams.policy",
FT_BOOLEAN, 16, TFS (&ff_block_ack_params_policy_flag), 0x0002, NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_params_tid,
{"Traffic Identifier", "wlan_mgt.fixed.baparams.tid",
FT_UINT16, BASE_HEX, NULL, 0x003C, NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_params_buffer_size,
{"Number of Buffers (1 Buffer = 2304 Bytes)", "wlan_mgt.fixed.baparams.buffersize",
FT_UINT16, BASE_DEC, NULL, 0xFFC0, "Number of Buffers", HFILL }},
{&hf_ieee80211_ff_block_ack_timeout,
{"Block Ack Timeout", "wlan_mgt.fixed.batimeout",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_ssc,
{"Block Ack Starting Sequence Control (SSC)", "wlan_mgt.fixed.ssc",
FT_UINT16, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_ssc_fragment,
{"Fragment", "wlan_mgt.fixed.fragment",
FT_UINT16, BASE_DEC, 0, 0x000f, NULL, HFILL }},
{&hf_ieee80211_ff_block_ack_ssc_sequence,
{"Starting Sequence Number", "wlan_mgt.fixed.sequence",
FT_UINT16, BASE_DEC, 0, 0xfff0, NULL, HFILL }},
{&hf_ieee80211_ff_delba_param,
{"Delete Block Ack (DELBA) Parameter Set", "wlan_mgt.fixed.delba.param",
FT_UINT16, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_delba_param_reserved,
{"Reserved", "wlan_mgt.fixed.delba.param.reserved",
FT_UINT16, BASE_HEX, 0, 0x07ff, NULL, HFILL }},
{&hf_ieee80211_ff_delba_param_init,
{"Initiator", "wlan_mgt.fixed.delba.param.initiator",
FT_BOOLEAN, 16, 0, 0x0800, NULL, HFILL }},
{&hf_ieee80211_ff_delba_param_tid,
{"TID", "wlan_mgt.fixed.delba.param.tid",
FT_UINT16, BASE_HEX, 0, 0xf000, "Traffic Identifier (TID)", HFILL }},
{&hf_ieee80211_ff_max_reg_pwr,
{"Maximum Regulation Power", "wlan_mgt.fixed.maxregpwr",
FT_UINT16, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_measurement_pilot_int,
{"Measurement Pilot Interval", "wlan_mgt.fixed.msmtpilotint",
FT_UINT16, BASE_HEX, 0, 0, "Measurement Pilot Interval Fixed Field", HFILL }},
{&hf_ieee80211_ff_country_str,
{"Country String", "wlan_mgt.fixed.country",
FT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_max_tx_pwr,
{"Maximum Transmit Power", "wlan_mgt.fixed.maxtxpwr",
FT_UINT8, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_tx_pwr_used,
{"Transmit Power Used", "wlan_mgt.fixed.txpwr",
FT_UINT8, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_transceiver_noise_floor,
{"Transceiver Noise Floor", "wlan_mgt.fixed.tnoisefloor",
FT_UINT8, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_channel_width,
{"Supported Channel Width", "wlan_mgt.fixed.chanwidth",
FT_UINT8, BASE_HEX, VALS (ff_channel_width_vals), 0, NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_ap,
{"QoS Information (AP)", "wlan_mgt.fixed.qosinfo.ap",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_ap_edca_param_set_counter,
{"EDCA Parameter Set Update Count", "wlan_mgt.fixed.qosinfo.ap.edcaupdate",
FT_UINT8, BASE_HEX, NULL, 0x0F, "Enhanced Distributed Channel Access (EDCA) Parameter Set Update Count", HFILL }},
{&hf_ieee80211_ff_qos_info_ap_q_ack,
{"Q-Ack", "wlan_mgt.fixed.qosinfo.ap.qack",
FT_BOOLEAN, 8, TFS (&ff_qos_info_ap_q_ack_flag), 0x10, "QoS Ack", HFILL }},
{&hf_ieee80211_ff_qos_info_ap_queue_req,
{"Queue Request", "wlan_mgt.fixed.qosinfo.ap",
FT_BOOLEAN, 8, TFS (&ff_qos_info_ap_queue_req_flag), 0x20, NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_ap_txop_request,
{"TXOP Request", "wlan_mgt.fixed.qosinfo.ap.txopreq",
FT_BOOLEAN, 8, TFS (&ff_qos_info_ap_txop_request_flag), 0x40, "Transmit Opportunity (TXOP) Request", HFILL }},
{&hf_ieee80211_ff_qos_info_ap_reserved,
{"Reserved", "wlan_mgt.fixed.qosinfo.ap.reserved",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta,
{"QoS Information (STA)", "wlan_mgt.fixed.qosinfo.sta",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_ac_vo,
{"AC_VO", "wlan_mgt.fixed.qosinfo.sta.ac.vo",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_ac_flag), 0x01, NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_ac_vi,
{"AC_VI", "wlan_mgt.fixed.qosinfo.sta.ac.vi",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_ac_flag), 0x02, NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_ac_bk,
{"AC_BK", "wlan_mgt.fixed.qosinfo.sta.ac.bk",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_ac_flag), 0x04, NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_ac_be,
{"AC_BE", "wlan_mgt.fixed.qosinfo.sta.ac.be",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_ac_flag), 0x08, NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_q_ack,
{"Q-Ack", "wlan_mgt.fixed.qosinfo.sta.qack",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_q_ack_flag), 0x10, "QoS Ack", HFILL }},
{&hf_ieee80211_ff_qos_info_sta_max_sp_len,
{"Service Period (SP) Length", "wlan_mgt.fixed.qosinfo.sta.splen",
FT_UINT8, BASE_HEX, VALS (&ff_qos_info_sta_max_sp_len_flags) , 0x60, NULL, HFILL }},
{&hf_ieee80211_ff_qos_info_sta_more_data_ack,
{"More Data Ack", "wlan_mgt.fixed.qosinfo.sta.moredataack",
FT_BOOLEAN, 8, TFS (&ff_qos_info_sta_more_data_ack_flag), 0x80, NULL, HFILL }},
{&hf_ieee80211_ff_sm_pwr_save,
{"Spatial Multiplexing (SM) Power Control", "wlan_mgt.fixed.sm.powercontrol",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_sm_pwr_save_enabled,
{"SM Power Save", "wlan_mgt.fixed.sm.powercontrol.enabled",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x01, "Spatial Multiplexing (SM) Power Save", HFILL }},
{&hf_ieee80211_ff_sm_pwr_save_sm_mode,
{"SM Mode", "wlan_mgt.fixed.sm.powercontrol.mode",
FT_BOOLEAN, 8, TFS (&ff_sm_pwr_save_sm_mode_flag), 0x02, "Spatial Multiplexing (SM) Mode", HFILL }},
{&hf_ieee80211_ff_sm_pwr_save_reserved,
{"Reserved", "wlan_mgt.fixed.sm.powercontrol.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFC, NULL, HFILL }},
{&hf_ieee80211_ff_pco_phase_cntrl,
{"Phased Coexistence Operation (PCO) Phase Control", "wlan_mgt.fixed.pco.phasecntrl",
FT_BOOLEAN, BASE_NONE, TFS (&ff_pco_phase_cntrl_flag), 0x0, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_param_set,
{"Power Save Multi-Poll (PSMP) Parameter Set", "wlan_mgt.fixed.psmp.paramset",
FT_UINT16, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_param_set_n_sta,
{"Number of STA Info Fields Present", "wlan_mgt.fixed.psmp.paramset.nsta",
FT_UINT16, BASE_HEX, 0, 0x000F, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_param_set_more_psmp,
{"More PSMP", "wlan_mgt.fixed.psmp.paramset.more",
FT_BOOLEAN, 16, TFS(&ff_psmp_param_set_more_psmp_flag), 0x0010, "More Power Save Multi-Poll (PSMP)", HFILL }},
{&hf_ieee80211_ff_psmp_param_set_psmp_sequence_duration,
{"PSMP Sequence Duration [us]", "wlan_mgt.fixed.psmp.paramset.seqduration",
FT_UINT16, BASE_DEC, 0, 0xFFE0, "Power Save Multi-Poll (PSMP) Sequence Duration", HFILL }},
{&hf_ieee80211_ff_mimo_cntrl,
{"MIMO Control", "wlan_mgt.fixed.mimo.control.",
FT_BYTES, BASE_NONE, 0, 0x0, NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_nc_index,
{"Nc Index", "wlan_mgt.fixed.mimo.control.ncindex",
FT_UINT16, BASE_HEX, VALS(ff_mimo_cntrl_nc_index_flags), 0x0003, "Number of Columns Less One", HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_nr_index,
{"Nr Index", "wlan_mgt.fixed.mimo.control.nrindex",
FT_UINT16, BASE_HEX, VALS(ff_mimo_cntrl_nr_index_flags), 0x000C, "Number of Rows Less One", HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_channel_width,
{"Channel Width", "wlan_mgt.fixed.mimo.control.chanwidth",
FT_BOOLEAN, 16, TFS(&ff_mimo_cntrl_channel_width_flag), 0x0010, NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_grouping,
{"Grouping (Ng)", "wlan_mgt.fixed.mimo.control.grouping",
FT_UINT16, BASE_HEX, VALS(ff_mimo_cntrl_grouping_flags), 0x0060, NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_coefficient_size,
{"Coefficient Size (Nb)", "wlan_mgt.fixed.mimo.control.cosize",
FT_UINT16, BASE_HEX, VALS(ff_mimo_cntrl_coefficient_size_flags), 0x0180, NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_codebook_info,
{"Codebook Information", "wlan_mgt.fixed.mimo.control.codebookinfo",
FT_UINT16, BASE_HEX, VALS(ff_mimo_cntrl_codebook_info_flags), 0x0600, NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_remaining_matrix_segment,
{"Remaining Matrix Segment", "wlan_mgt.fixed.mimo.control.matrixseg",
FT_UINT16, BASE_HEX, 0, 0x3800, NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_reserved,
{"Reserved", "wlan_mgt.fixed.mimo.control.reserved",
FT_UINT16, BASE_HEX, 0, 0xC000, NULL, HFILL }},
{&hf_ieee80211_ff_mimo_cntrl_sounding_timestamp,
{"Sounding Timestamp", "wlan_mgt.fixed.mimo.control.soundingtime",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info,
{"Power Save Multi-Poll (PSMP) Station Information", "wlan_mgt.fixed.psmp.stainfo",
FT_UINT64, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_type,
{"Sta Info Type", "wlan_mgt.fixed.psmp.stainfo.type",
FT_UINT32, BASE_HEX, VALS(ff_psmp_sta_info_flags), PSMP_STA_INFO_FLAG_TYPE, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_dtt_start_offset,
{"DTT Start Offset", "wlan_mgt.fixed.psmp.stainfo.dttstart",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_DTT_START, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_dtt_duration,
{"DTT Duration", "wlan_mgt.fixed.psmp.stainfo.dttduration",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_DTT_DURATION, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_sta_id,
{"Target Station ID", "wlan_mgt.fixed.psmp.stainfo.staid",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_STA_ID, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_utt_start_offset,
{"UTT Start Offset", "wlan_mgt.fixed.psmp.stainfo.uttstart",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_UTT_START, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_utt_duration,
{"UTT Duration", "wlan_mgt.fixed.psmp.stainfo.uttduration",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_UTT_DURATION, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_reserved_small,
{"Reserved", "wlan_mgt.fixed.psmp.stainfo.reserved",
FT_UINT32, BASE_HEX, 0, PSMP_STA_INFO_FLAG_IA_RESERVED, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_reserved_large,
{"Reserved", "wlan_mgt.fixed.psmp.stainfo.reserved",
FT_UINT64, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_psmp_sta_info_psmp_multicast_id,
{"Power Save Multi-Poll (PSMP) Multicast ID", "wlan_mgt.fixed.psmp.stainfo.multicastid",
FT_UINT64, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection,
{"Antenna Selection", "wlan_mgt.fixed.antsel",
FT_UINT8, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_0,
{"Antenna 0", "wlan_mgt.fixed.antsel.ant0",
FT_UINT8, BASE_HEX, 0, 0x01, NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_1,
{"Antenna 1", "wlan_mgt.fixed.antsel.ant1",
FT_UINT8, BASE_HEX, 0, 0x02, NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_2,
{"Antenna 2", "wlan_mgt.fixed.antsel.ant2",
FT_UINT8, BASE_HEX, 0, 0x04, NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_3,
{"Antenna 3", "wlan_mgt.fixed.antsel.ant3",
FT_UINT8, BASE_HEX, 0, 0x08, NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_4,
{"Antenna 4", "wlan_mgt.fixed.antsel.ant4",
FT_UINT8, BASE_HEX, 0, 0x10, NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_5,
{"Antenna 5", "wlan_mgt.fixed.antsel.ant5",
FT_UINT8, BASE_HEX, 0, 0x20, NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_6,
{"Antenna 6", "wlan_mgt.fixed.antsel.ant6",
FT_UINT8, BASE_HEX, 0, 0x40, NULL, HFILL }},
{&hf_ieee80211_ff_ant_selection_7,
{"Antenna 7", "wlan_mgt.fixed.antsel.ant7",
FT_UINT8, BASE_HEX, 0, 0x80, NULL, HFILL }},
{&hf_ieee80211_ff_ext_channel_switch_announcement,
{"Extended Channel Switch Announcement", "wlan_mgt.fixed.extchansw",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{&hf_ieee80211_ff_ext_channel_switch_announcement_switch_mode,
{"Channel Switch Mode", "wlan_mgt.fixed.extchansw.switchmode",
FT_UINT32, BASE_HEX, VALS(ieee80211_tag_ext_channel_switch_announcement_switch_mode_flags), 0x000000FF, NULL, HFILL }},
{&hf_ieee80211_ff_ext_channel_switch_announcement_new_reg_class,
{"New Regulatory Class", "wlan_mgt.fixed.extchansw.new.regclass",
FT_UINT32, BASE_HEX, NULL, 0x0000FF00, NULL, HFILL }},
{&hf_ieee80211_ff_ext_channel_switch_announcement_new_chan_number,
{"New Channel Number", "wlan_mgt.fixed.extchansw.new.channumber",
FT_UINT32, BASE_HEX, NULL, 0x00FF0000, NULL, HFILL }},
{&hf_ieee80211_ff_ext_channel_switch_announcement_switch_count,
{"Channel Switch Count", "wlan_mgt.extchanswitch.switchcount",
FT_UINT32, BASE_HEX, NULL, 0xFF000000, NULL, HFILL }},
{&hf_ieee80211_ff_ht_info,
{"HT Information", "wlan_mgt.fixed.extchansw",
FT_UINT8, BASE_HEX, 0, 0, "HT Information Fixed Field", HFILL }},
{&hf_ieee80211_ff_ht_info_information_request,
{"Information Request", "wlan_mgt.fixed.mimo.control.chanwidth",
FT_BOOLEAN, 8, TFS(&ff_ht_info_information_request_flag), 0x01, NULL, HFILL }},
{&hf_ieee80211_ff_ht_info_40_mhz_intolerant,
{"40 MHz Intolerant", "wlan_mgt.fixed.mimo.control.chanwidth",
FT_BOOLEAN, 8, TFS(&ff_ht_info_40_mhz_intolerant_flag), 0x02, NULL, HFILL }},
{&hf_ieee80211_ff_ht_info_sta_chan_width,
{"Station Channel Width", "wlan_mgt.fixed.mimo.control.chanwidth",
FT_BOOLEAN, 8, TFS(&ff_ht_info_sta_chan_width_flag), 0x04, NULL, HFILL }},
{&hf_ieee80211_ff_ht_info_reserved,
{"Reserved", "wlan_mgt.fixed.extchansw",
FT_UINT8, BASE_HEX, 0, 0xF8, "Reserved Field", HFILL }},
{&hf_ieee80211_ff_ht_action,
{"HT Action", "wlan_mgt.fixed.htact",
FT_UINT8, BASE_HEX, VALS (&ff_ht_action_flags), 0, "HT Action Code", HFILL }},
{&hf_ieee80211_ff_mimo_csi_snr,
{"Signal to Noise Ratio (SNR)", "wlan_mgt.mimo.csimatrices.snr",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_public_action,
{"Public Action", "wlan_mgt.fixed.publicact",
FT_UINT8, BASE_HEX, VALS(ff_pa_action_codes), 0, "Public Action Code", HFILL }},
{&hf_ieee80211_ff_capture,
{"Capabilities Information", "wlan_mgt.fixed.capabilities", FT_UINT16, BASE_HEX, NULL, 0,
"Capability information", HFILL }},
{&hf_ieee80211_ff_cf_ess,
{"ESS capabilities", "wlan_mgt.fixed.capabilities.ess",
FT_BOOLEAN, 16, TFS (&cf_ess_flags), 0x0001, NULL, HFILL }},
{&hf_ieee80211_ff_cf_ibss,
{"IBSS status", "wlan_mgt.fixed.capabilities.ibss",
FT_BOOLEAN, 16, TFS (&cf_ibss_flags), 0x0002, "IBSS participation", HFILL }},
{&hf_ieee80211_ff_cf_sta_poll,
{"CFP participation capabilities", "wlan_mgt.fixed.capabilities.cfpoll.sta",
FT_UINT16, BASE_HEX, VALS (&sta_cf_pollable), 0x020C,
"CF-Poll capabilities for a STA", HFILL }},
{&hf_ieee80211_ff_cf_ap_poll,
{"CFP participation capabilities", "wlan_mgt.fixed.capabilities.cfpoll.ap",
FT_UINT16, BASE_HEX, VALS (&ap_cf_pollable), 0x020C,
"CF-Poll capabilities for an AP", HFILL }},
{&hf_ieee80211_ff_cf_privacy,
{"Privacy", "wlan_mgt.fixed.capabilities.privacy",
FT_BOOLEAN, 16, TFS (&cf_privacy_flags), 0x0010, "WEP support", HFILL }},
{&hf_ieee80211_ff_cf_preamble,
{"Short Preamble", "wlan_mgt.fixed.capabilities.preamble",
FT_BOOLEAN, 16, TFS (&cf_preamble_flags), 0x0020, NULL, HFILL }},
{&hf_ieee80211_ff_cf_pbcc,
{"PBCC", "wlan_mgt.fixed.capabilities.pbcc",
FT_BOOLEAN, 16, TFS (&cf_pbcc_flags), 0x0040, "PBCC Modulation", HFILL }},
{&hf_ieee80211_ff_cf_agility,
{"Channel Agility", "wlan_mgt.fixed.capabilities.agility",
FT_BOOLEAN, 16, TFS (&cf_agility_flags), 0x0080, NULL, HFILL }},
{&hf_ieee80211_ff_cf_spec_man,
{"Spectrum Management", "wlan_mgt.fixed.capabilities.spec_man",
FT_BOOLEAN, 16, TFS (&cf_spec_man_flags), 0x0100, NULL, HFILL }},
{&hf_ieee80211_ff_short_slot_time,
{"Short Slot Time", "wlan_mgt.fixed.capabilities.short_slot_time",
FT_BOOLEAN, 16, TFS (&short_slot_time_flags), 0x0400, NULL,
HFILL }},
{&hf_ieee80211_ff_cf_apsd,
{"Automatic Power Save Delivery", "wlan_mgt.fixed.capabilities.apsd",
FT_BOOLEAN, 16, TFS (&cf_apsd_flags), 0x0800, NULL, HFILL }},
{&hf_ieee80211_ff_dsss_ofdm,
{"DSSS-OFDM", "wlan_mgt.fixed.capabilities.dsss_ofdm",
FT_BOOLEAN, 16, TFS (&dsss_ofdm_flags), 0x2000, "DSSS-OFDM Modulation",
HFILL }},
{&hf_ieee80211_ff_cf_del_blk_ack,
{"Delayed Block Ack", "wlan_mgt.fixed.capabilities.del_blk_ack",
FT_BOOLEAN, 16, TFS (&cf_del_blk_ack_flags), 0x4000, NULL, HFILL }},
{&hf_ieee80211_ff_cf_imm_blk_ack,
{"Immediate Block Ack", "wlan_mgt.fixed.capabilities.imm_blk_ack",
FT_BOOLEAN, 16, TFS (&cf_imm_blk_ack_flags), 0x8000, NULL, HFILL }},
{&hf_ieee80211_ff_auth_seq,
{"Authentication SEQ", "wlan_mgt.fixed.auth_seq",
FT_UINT16, BASE_HEX, NULL, 0, "Authentication Sequence Number", HFILL }},
{&hf_ieee80211_ff_assoc_id,
{"Association ID", "wlan_mgt.fixed.aid",
FT_UINT16, BASE_HEX, NULL, 0x3FFF, NULL, HFILL }},
{&hf_ieee80211_ff_listen_ival,
{"Listen Interval", "wlan_mgt.fixed.listen_ival",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_current_ap,
{"Current AP", "wlan_mgt.fixed.current_ap",
FT_ETHER, BASE_NONE, NULL, 0, "MAC address of current AP", HFILL }},
{&hf_ieee80211_ff_reason,
{"Reason code", "wlan_mgt.fixed.reason_code",
FT_UINT16, BASE_HEX, VALS (&ieee80211_reason_code), 0,
"Reason for unsolicited notification", HFILL }},
{&hf_ieee80211_ff_status_code,
{"Status code", "wlan_mgt.fixed.status_code",
FT_UINT16, BASE_HEX, VALS (&ieee80211_status_code), 0,
"Status of requested event", HFILL }},
{&hf_ieee80211_ff_category_code,
{"Category code", "wlan_mgt.fixed.category_code",
FT_UINT16, BASE_DEC, VALS (&category_codes), 0,
"Management action category", HFILL }},
{&hf_ieee80211_ff_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT16, BASE_DEC, VALS (&action_codes), 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_dialog_token,
{"Dialog token", "wlan_mgt.fixed.dialog_token",
FT_UINT8, BASE_HEX, NULL, 0, "Management action dialog token", HFILL }},
{&hf_ieee80211_ff_marvell_action_type,
{"Marvell Action type", "wlan_mgt.fixed.mrvl_action_type",
FT_UINT8, BASE_DEC, VALS (&vendor_action_types_mrvl), 0,
"Vendor Specific Action Type (Marvell)", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_action_code,
{"Mesh action(Marvell)", "wlan_mgt.fixed.mrvl_mesh_action",
FT_UINT8, BASE_HEX, VALS (&mesh_mgt_action_codes_mrvl), 0,
"Mesh action code(Marvell)", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_length,
{"Message Length", "wlan_mgt.fixed.length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_mode,
{"Message Mode", "wlan_mgt.fixed.mode",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_ttl,
{"Message TTL", "wlan_mgt.fixed.ttl",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_dstcount,
{"Destination Count", "wlan_mgt.fixed.dstcount",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_hopcount,
{"Hop Count", "wlan_mgt.fixed.hopcount",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_rreqid,
{"RREQ ID", "wlan_mgt.fixed.rreqid",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_sa,
{"Source Address", "wlan_mgt.fixed.sa",
FT_ETHER, BASE_NONE, NULL, 0, "Source MAC address", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_ssn,
{"SSN", "wlan_mgt.fixed.ssn",
FT_UINT32, BASE_DEC, NULL, 0, "Source Sequence Number", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_metric,
{"Metric", "wlan_mgt.fixed.metric",
FT_UINT32, BASE_DEC, NULL, 0, "Route Metric", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_flags,
{"RREQ Flags", "wlan_mgt.fixed.hopcount",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_da,
{"Destination Address", "wlan_mgt.fixed.da",
FT_ETHER, BASE_NONE, NULL, 0, "Destination MAC address", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_dsn,
{"DSN", "wlan_mgt.fixed.dsn",
FT_UINT32, BASE_DEC, NULL, 0, "Destination Sequence Number", HFILL }},
{&hf_ieee80211_ff_marvell_mesh_mgt_lifetime,
{"Lifetime", "wlan_mgt.fixed.lifetime",
FT_UINT32, BASE_DEC, NULL, 0, "Route Lifetime", HFILL }},
{&hf_ieee80211_ff_wme_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT16, BASE_HEX, VALS (&wme_action_codes), 0,
"Management notification action code", HFILL }},
{&hf_ieee80211_ff_wme_status_code,
{"Status code", "wlan_mgt.fixed.status_code",
FT_UINT16, BASE_HEX, VALS (&wme_status_codes), 0,
"Management notification setup response status code", HFILL }},
{&hf_ieee80211_ff_mesh_action,
{"Mesh Action code", "wlan_mgt.fixed.mesh_action",
FT_UINT8, BASE_HEX, VALS (&mesh_action), 0,
NULL, HFILL }},
{&hf_ieee80211_ff_multihop_action,
{"Multihop Action code", "wlan_mgt.fixed.multihop_action",
FT_UINT8, BASE_HEX, VALS (&multihop_action), 0,
NULL, HFILL }},
{&hf_ieee80211_ff_mesh_flags,
{"Mesh Flags", "wlan_mgt.fixed.mesh_flags",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_mesh_ttl,
{"Mesh TTL", "wlan_mgt.fixed.mesh_ttl",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_mesh_sequence,
{"Sequence Number", "wlan_mgt.fixed.mesh_sequence",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_mesh_addr4,
{"Mesh Extended Address 4", "wlan_mgt.fixed.mesh_addr4",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_mesh_addr5,
{"Mesh Extended Address 5", "wlan_mgt.fixed.mesh_addr5",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_mesh_addr6,
{"Mesh Extended Address 6", "wlan_mgt.fixed.mesh_addr6",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_selfprot_action,
{"Self-protected Action code", "wlan_mgt.fixed.selfprot_action",
FT_UINT8, BASE_HEX, VALS (&selfprot_action), 0,
NULL, HFILL }},
{&hf_ieee80211_mesh_peering_proto,
{"Mesh Peering Protocol ID", "wlan.peering.proto",
FT_UINT16, BASE_HEX, VALS (&mesh_peering_proto_ids), 0,
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
{"HWMP Flags", "wlan.hwmp.flags", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_hopcount,
{"HWMP Hop Count", "wlan.hwmp.hopcount", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_ttl,
{"HWMP TTL", "wlan.hwmp.ttl", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_pdid,
{"HWMP Path Discovery ID", "wlan.hwmp.pdid", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_orig_sta,
{"Originator STA Address", "wlan.hwmp.orig_sta", FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_orig_sn,
{"HWMP Originator Sequence Number", "wlan.hwmp.orig_sn", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{&hf_ieee80211_ff_hwmp_orig_ext,
{"Originator External Address", "wlan.hwmp.orig_ext", FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_lifetime,
{"HWMP Lifetime", "wlan.hwmp.lifetime", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_metric,
{"HWMP Metric", "wlan.hwmp.metric", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_targ_count,
{"HWMP Target Count", "wlan.hwmp.targ_count", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_targ_flags,
{"HWMP Per-Target Flags", "wlan.hwmp.targ_flags", FT_UINT8, BASE_HEX, NULL, 0,
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
{"Target STA Address", "wlan.hwmp.targ_sta", FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_targ_ext,
{"Target External Address", "wlan.hwmp.targ_ext", FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_ff_hwmp_targ_sn,
{"Target HWMP Sequence Number", "wlan.hwmp.targ_sn",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
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
{&hf_ieee80211_mesh_config_capability,
{"Capability", "wlan.mesh.config.cap",
FT_UINT8, BASE_HEX, NULL, 0,
"Mesh Configuration Capability", HFILL }},
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
FT_UINT32, BASE_DEC, NULL, 0, "Root Mesh STA Sequence Number", HFILL }},
{&hf_ieee80211_rann_interval,
{"RANN Interval", "wlan.rann.interval", FT_UINT32, BASE_DEC, NULL, 0,
"Root Announcement Interval", HFILL }},
{&hf_ieee80211_ff_qos_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT16, BASE_HEX, VALS (&qos_action_codes), 0,
"QoS management action code", HFILL }},
{&hf_ieee80211_ff_ba_action,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_HEX, VALS (&ba_action_codes), 0,
"Block Ack action code", HFILL }},
{&hf_ieee80211_ff_dls_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT16, BASE_HEX, VALS (&dls_action_codes), 0,
"DLS management action code", HFILL }},
{&hf_ieee80211_ff_dst_mac_addr,
{"Destination address", "wlan_mgt.fixed.dst_mac_addr",
FT_ETHER, BASE_NONE, NULL, 0, "Destination MAC address", HFILL }},
{&hf_ieee80211_ff_src_mac_addr,
{"Source address", "wlan_mgt.fixed.src_mac_addr",
FT_ETHER, BASE_NONE, NULL, 0, "Source MAC address", HFILL }},
{&hf_ieee80211_ff_ft_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_DEC, VALS(ft_action_codes), 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_sta_address,
{"STA Address", "wlan_mgt.fixed.sta_address",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_target_ap_address,
{"Target AP Address", "wlan_mgt.fixed.target_ap_address",
FT_ETHER, BASE_NONE, NULL, 0, "Target AP MAC address", HFILL }},
{&hf_ieee80211_ff_gas_comeback_delay,
{"GAS Comeback Delay", "wlan_mgt.fixed.gas_comeback_delay",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_gas_fragment_id,
{"GAS Query Response Fragment ID", "wlan_mgt.fixed.gas_fragment_id",
FT_UINT8, BASE_DEC, NULL, 0x7f, NULL, HFILL
}},
{&hf_ieee80211_ff_more_gas_fragments,
{"More GAS Fragments", "wlan_mgt.fixed.more_gas_fragments",
FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL }},
{&hf_ieee80211_ff_query_request_length,
{"Query Request Length", "wlan_mgt.fixed.query_request_length",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_query_request,
{"Query Request", "wlan_mgt.fixed.query_request",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_query_response_length,
{"Query Response Length", "wlan_mgt.fixed.query_response_length",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_query_response,
{"Query Response", "wlan_mgt.fixed.query_response",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_gas_resp_fragments,
{"GAS Query Response fragments", "wlan_mgt.fixed.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment,
{"GAS Query Response fragment", "wlan_mgt.fixed.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_overlap,
{"GAS Query Response fragment overlap", "wlan_mgt.fixed.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_overlap_conflict,
{"GAS Query Response fragment overlapping with conflicting data",
"wlan_mgt.fixed.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_multiple_tails,
{"GAS Query Response has multiple tail fragments",
"wlan_mgt.fixed.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_too_long_fragment,
{"GAS Query Response fragment too long",
"wlan_mgt.fixed.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_error,
{"GAS Query Response reassembly error", "wlan_mgt.fixed.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ieee80211_gas_resp_fragment_count,
{"GAS Query Response fragment count", "wlan_mgt.fixed.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{&hf_ieee80211_gas_resp_reassembled_in,
{"Reassembled in", "wlan_mgt.fixed.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ieee80211_gas_resp_reassembled_length,
{"Reassembled length", "wlan_mgt.fixed.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{&hf_ieee80211_ff_anqp_info_id,
{"Info ID", "wlan_mgt.fixed.anqp.info_id",
FT_UINT16, BASE_DEC, VALS(anqp_info_id_vals), 0,
"Access Network Query Protocol Info ID", HFILL }},
{&hf_ieee80211_ff_anqp_info_length,
{"Length", "wlan_mgt.fixed.anqp.info_length",
FT_UINT16, BASE_DEC, NULL, 0, "Access Network Query Protocol Length",
HFILL }},
{&hf_ieee80211_ff_anqp_info,
{"Information", "wlan_mgt.fixed.anqp.info",
FT_BYTES, BASE_NONE, NULL, 0,
"Access Network Query Protocol Information", HFILL }},
{&hf_ieee80211_ff_anqp_query_id,
{"ANQP Query ID", "wlan_mgt.fixed.anqp.query_id",
FT_UINT16, BASE_DEC, VALS(anqp_info_id_vals), 0,
"Access Network Query Protocol Query ID", HFILL }},
{&hf_ieee80211_ff_anqp_capability,
{"ANQP Capability", "wlan_mgt.fixed.anqp.capability",
FT_UINT16, BASE_DEC, VALS(anqp_info_id_vals), 0,
"Access Network Query Protocol Query ID", HFILL }},
{&hf_ieee80211_ff_anqp_capability_vlen,
{"Vendor-specific Capability Length",
"wlan_mgt.fixed.anqp.capability_vlen",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_capability_vendor,
{"Vendor-specific Capability",
"wlan_mgt.fixed.anqp.capability_vendor",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_venue_info_group,
{"Venue Group", "wlan_mgt.fixed.venue_info.group",
FT_UINT8, BASE_DEC, VALS(venue_group_vals), 0, NULL, HFILL }},
{&hf_ieee80211_ff_venue_info_type,
{"Venue Type", "wlan_mgt.fixed.venue_info.type",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_venue_length,
{"Venue Name Duple Length", "wlan_mgt.fixed.anqp.venue.length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_venue_language,
{"Language Code", "wlan_mgt.fixed.anqp.venue.language",
FT_STRING, BASE_NONE, NULL, 0,
"Venue Name Language Code", HFILL }},
{&hf_ieee80211_ff_anqp_venue_name,
{"Venue Name", "wlan_mgt.fixed.anqp.venue.name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nw_auth_type_indicator,
{"Network Authentication Type Indicator",
"wlan_mgt.fixed.anqp.nw_auth_type.indicator",
FT_UINT8, BASE_DEC, VALS(nw_auth_type_vals), 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nw_auth_type_url_len,
{"Re-direct URL Length",
"wlan_mgt.fixed.anqp.nw_auth_type.url_len",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nw_auth_type_url,
{"Re-direct URL", "wlan_mgt.fixed.anqp.nw_auth_type_url",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_roaming_consortium_oi_len,
{"OI Length", "wlan_mgt.fixed.anqp.roaming_consortium.oi_len",
FT_UINT8, BASE_DEC, NULL, 0, "Roaming Consortium OI Length", HFILL }},
{&hf_ieee80211_ff_anqp_roaming_consortium_oi,
{"OI", "wlan_mgt.fixed.anqp.roaming_consortium.oi",
FT_BYTES, BASE_NONE, NULL, 0, "Roaming Consortium OI", HFILL }},
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
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_field_len,
{"NAI Realm Data Field Length",
"wlan_mgt.fixed.anqp.nai_realm_list.field_len",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_encoding,
{"NAI Realm Encoding",
"wlan_mgt.fixed.naqp_nai_realm_list.encoding",
FT_UINT8, BASE_DEC, VALS(nai_realm_encoding_vals), 0x01, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_length,
{"NAI Realm Length",
"wlan_mgt.fixed.naqp_nai_realm_list.realm_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm,
{"NAI Realm",
"wlan_mgt.fixed.naqp_nai_realm_list.realm",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_eap_count,
{"EAP Method Count",
"wlan_mgt.fixed.naqp_nai_realm_list.eap_method_count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_eap_len,
{"EAP Method subfield Length",
"wlan_mgt.fixed.naqp_nai_realm_list.eap_method_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_eap_method,
{"EAP Method",
"wlan_mgt.fixed.naqp_nai_realm_list.eap_method",
FT_UINT8, BASE_DEC, VALS(eap_type_vals), 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_auth_param_count,
{"Authentication Parameter Count",
"wlan_mgt.fixed.naqp_nai_realm_list.auth_param_count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_auth_param_id,
{"Authentication Parameter ID",
"wlan_mgt.fixed.naqp_nai_realm_list.auth_param_id",
FT_UINT8, BASE_DEC, VALS(nai_realm_auth_param_id_vals),
0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_auth_param_len,
{"Authentication Parameter Length",
"wlan_mgt.fixed.naqp_nai_realm_list.auth_param_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_nai_realm_auth_param_value,
{"Authentication Parameter Value",
"wlan_mgt.fixed.naqp_nai_realm_list.auth_param_value",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
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
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_3gpp_gc_plmn,
{"PLMN", "wlan_mgt.fixed.anqp.3gpp_cellular_info.plmn",
FT_STRING, BASE_NONE, NULL, 0,
"PLMN information", HFILL }},
{&hf_ieee80211_ff_anqp_domain_name_len,
{"Domain Name Length", "wlan_mgt.fixed.anqp.domain_name_list.len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_anqp_domain_name,
{"Domain Name", "wlan_mgt.fixed.anqp.domain_name_list.name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ff_dls_timeout,
{"DLS timeout", "wlan_mgt.fixed.dls_timeout",
FT_UINT16, BASE_HEX, NULL, 0, "DLS timeout value", HFILL }},
{&hf_ieee80211_ff_sa_query_action_code,
{"Action code", "wlan_mgt.fixed.action_code",
FT_UINT8, BASE_DEC, VALS(sa_query_action_codes), 0,
"Management action code", HFILL }},
{&hf_ieee80211_ff_transaction_id,
{"Transaction Id", "wlan_mgt.fixed.transaction_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag,
{"Tag", "wlan_mgt.tag",
FT_NONE, BASE_NONE, 0x0, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_number,
{"Tag Number", "wlan_mgt.tag.number",
FT_UINT8, BASE_DEC, VALS(tag_num_vals), 0,
"Element ID", HFILL }},
{&hf_ieee80211_tag_length,
{"Tag length", "wlan_mgt.tag.length",
FT_UINT32, BASE_DEC, NULL, 0, "Length of tag", HFILL }},
{&hf_ieee80211_tag_interpretation,
{"Tag interpretation", "wlan_mgt.tag.interpretation",
FT_STRING, BASE_NONE, NULL, 0, "Interpretation of tag", HFILL }},
{&hf_ieee80211_tag_oui,
{"OUI", "wlan_mgt.tag.oui",
FT_UINT24, BASE_CUSTOM, oui_base_custom, 0, "OUI of vendor specific IE", HFILL }},
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
{"Vendor Specific OUI Type", "wlan_mgt.tag.oui.type",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
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
{&hf_ieee80211_tag_country_info_rrc_rei,
{"Regulatory Extension Identifier", "wlan_mgt.country_info.rrc.rei",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ieee80211_tag_country_info_rrc_rc,
{"Regulatory Class", "wlan_mgt.country_info.rrc.rc",
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
FT_UINT8, BASE_DEC, VALS(tag_num_vals), 0,
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
{&hf_ieee80211_tclas_src_mac_addr,
{"Source address", "wlan_mgt.tclas.type",
FT_ETHER, BASE_NONE, NULL, 0,
"Classifier Parameters Ethernet Type", HFILL }},
{&hf_ieee80211_tclas_dst_mac_addr,
{"Destination address", "wlan_mgt.tclas.type",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tclas_ether_type,
{"Ethernet Type", "wlan_mgt.tclas.type",
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
FT_UINT8, BASE_HEX, NULL, 0, "IPv4 Protocol", HFILL }},
{&hf_ieee80211_tclas_ipv6_src,
{"IPv6 Src Addr", "wlan_mgt.tclas.ipv6_src",
FT_IPv6, BASE_NONE,
NULL, 0, NULL, HFILL }},
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
{"RSN Version", "wlan_mgt.rsn.version", FT_UINT16, BASE_DEC,
NULL, 0, "Indicates the version number of the RSNA protocol", HFILL }},
{&hf_ieee80211_rsn_gcs,
{"Group Cipher Suite", "wlan_mgt.rsn.gcs", FT_UINT32, BASE_CUSTOM,
rsn_gcs_base_custom, 0, "Contains the cipher suite selector used by the BSS to protect broadcast/multicast traffic", HFILL }},
{&hf_ieee80211_rsn_gcs_oui,
{"Group Cipher Suite OUI", "wlan_mgt.rsn.gcs.oui", FT_UINT24, BASE_CUSTOM,
oui_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_gcs_type,
{"Group Cipher Suite type", "wlan_mgt.rsn.gcs.type", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_gcs_80211_type,
{"Group Cipher Suite type", "wlan_mgt.rsn.gcs.type", FT_UINT8, BASE_DEC,
VALS(ieee80211_rsn_cipher_vals), 0, NULL, HFILL }},
{&hf_ieee80211_rsn_pcs_count,
{"Pairwise Cipher Suite Count", "wlan_mgt.rsn.pcs.count", FT_UINT16, BASE_DEC,
NULL, 0, "Indicates the number of pairwise cipher suite selectors that are contained in the Pairwise Cipher Suite List", HFILL }},
{&hf_ieee80211_rsn_pcs_list,
{"Pairwise Cipher Suite List", "wlan_mgt.rsn.pcs.list", FT_NONE, BASE_NONE,
NULL, 0, "Contains a series of cipher suite selectors that indicate the pairwisecipher suites", HFILL }},
{&hf_ieee80211_rsn_pcs,
{"Pairwise Cipher Suite", "wlan_mgt.rsn.pcs", FT_UINT32, BASE_CUSTOM,
rsn_pcs_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_pcs_oui,
{"Pairwise Cipher Suite OUI", "wlan_mgt.rsn.pcs.oui", FT_UINT24, BASE_CUSTOM,
oui_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_pcs_type,
{"Pairwise Cipher Suite type", "wlan_mgt.rsn.pcs.type", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_pcs_80211_type,
{"Pairwise Cipher Suite type", "wlan_mgt.rsn.pcs.type", FT_UINT8, BASE_DEC,
VALS(ieee80211_rsn_cipher_vals), 0, NULL, HFILL }},
{&hf_ieee80211_rsn_akms_count,
{"Auth Key Management (AKM) Suite Count", "wlan_mgt.rsn.akms.count", FT_UINT16, BASE_DEC,
NULL, 0, "Indicates the number of Auth Key Management suite selectors that are contained in the Auth Key Management Suite List", HFILL }},
{&hf_ieee80211_rsn_akms_list,
{"Auth Key Management (AKM) List", "wlan_mgt.rsn.akms.list", FT_NONE, BASE_NONE,
NULL, 0, "Contains a series of cipher suite selectors that indicate the AKM suites", HFILL }},
{&hf_ieee80211_rsn_akms,
{"Auth Key Management (AKM) Suite", "wlan_mgt.rsn.akms", FT_UINT32, BASE_CUSTOM,
rsn_akms_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_akms_oui,
{"Auth Key Management (AKM) OUI", "wlan_mgt.rsn.akms.oui", FT_UINT24, BASE_CUSTOM,
oui_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_akms_type,
{"Auth Key Management (AKM) type", "wlan_mgt.rsn.akms.type", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_akms_80211_type,
{"Auth Key Management (AKM) type", "wlan_mgt.rsn.akms.type", FT_UINT8, BASE_DEC,
VALS(ieee80211_rsn_keymgmt_vals), 0, NULL, HFILL }},
{&hf_ieee80211_rsn_cap,
{"RSN Capabilities", "wlan_mgt.rsn.capabilities", FT_UINT16, BASE_HEX,
NULL, 0, "RSN Capability information", HFILL }},
{&hf_ieee80211_rsn_cap_preauth,
{"RSN Pre-Auth capabilities", "wlan_mgt.rsn.capabilities.preauth",
FT_BOOLEAN, 16, TFS(&rsn_preauth_flags), 0x0001,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_no_pairwise,
{"RSN No Pairwise capabilities", "wlan_mgt.rsn.capabilities.no_pairwise",
FT_BOOLEAN, 16, TFS(&rsn_no_pairwise_flags), 0x0002,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_ptksa_replay_counter,
{"RSN PTKSA Replay Counter capabilities",
"wlan_mgt.rsn.capabilities.ptksa_replay_counter",
FT_UINT16, BASE_HEX, VALS(rsn_cap_replay_counter), 0x000C,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_gtksa_replay_counter,
{"RSN GTKSA Replay Counter capabilities",
"wlan_mgt.rsn.capabilities.gtksa_replay_counter",
FT_UINT16, BASE_HEX, VALS(rsn_cap_replay_counter), 0x0030,
NULL, HFILL }},
{&hf_ieee80211_rsn_cap_mfpr,
{"Management Frame Protection Required",
"wlan_mgt.rsn.capabilities.mfpr",
FT_BOOLEAN, 16, NULL, 0x0040, NULL, HFILL }},
{&hf_ieee80211_rsn_cap_mfpc,
{"Management Frame Protection Capable",
"wlan_mgt.rsn.capabilities.mfpc",
FT_BOOLEAN, 16, NULL, 0x0080, NULL, HFILL }},
{&hf_ieee80211_rsn_cap_peerkey,
{"PeerKey Enabled",
"wlan_mgt.rsn.capabilities.peerkey",
FT_BOOLEAN, 16, NULL, 0x0200, NULL, HFILL }},
{&hf_ieee80211_rsn_pmkid_count,
{"PMKID Count", "wlan_mgt.rsn.pmkid.count", FT_UINT16, BASE_DEC,
NULL, 0, "Indicates the number of PMKID selectors that are contained in the PMKID Suite List", HFILL }},
{&hf_ieee80211_rsn_pmkid_list,
{"PMKID List", "wlan_mgt.rsn.pmkid.list", FT_NONE, BASE_NONE,
NULL, 0, "Contains a series of cipher suite selectors that indicate the AKM suites", HFILL }},
{&hf_ieee80211_rsn_pmkid,
{"PMKID", "wlan_mgt.pmkid.akms", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_gmcs,
{"Group Managemement Cipher Suite", "wlan_mgt.rsn.gmcs", FT_UINT32, BASE_CUSTOM,
rsn_gmcs_base_custom, 0, "Contains the cipher suite selector used by the BSS to protect broadcast/multicast traffic", HFILL }},
{&hf_ieee80211_rsn_gmcs_oui,
{"Group Managemement Cipher Suite OUI", "wlan_mgt.rsn.gmcs.oui", FT_UINT24, BASE_CUSTOM,
oui_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_gmcs_type,
{"Group Managemement Cipher Suite type", "wlan_mgt.rsn.gmcs.type", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_rsn_gmcs_80211_type,
{"Group Managemement Cipher Suite type", "wlan_mgt.rsn.gmcs.type", FT_UINT8, BASE_DEC,
VALS(ieee80211_rsn_cipher_vals), 0, NULL, HFILL }},
{&hf_ieee80211_ht_cap,
{"HT Capabilities Info", "wlan_mgt.ht.capabilities", FT_UINT16, BASE_HEX,
NULL, 0, "HT Capability information", HFILL }},
{&hf_ieee80211_ht_vs_cap,
{"HT Capabilities Info (VS)", "wlan_mgt.vs.ht.capabilities", FT_UINT16, BASE_HEX,
NULL, 0, "Vendor Specific HT Capability information", HFILL }},
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
FT_UINT16, BASE_HEX, VALS (&ht_sm_pwsave_flag), 0x000c,
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
FT_UINT16, BASE_HEX, VALS (&ht_rx_stbc_flag), 0x0300,
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
{&hf_ieee80211_ampduparam,
{"A-MPDU Parameters", "wlan_mgt.ht.ampduparam", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ampduparam_vs,
{"A-MPDU Parameters (VS)", "wlan_mgt.vs.ht.ampduparam", FT_UINT16, BASE_HEX,
NULL, 0, "Vendor Specific A-MPDU Parameters", HFILL }},
{&hf_ieee80211_ampduparam_mpdu,
{"Maximum Rx A-MPDU Length", "wlan_mgt.ht.ampduparam.maxlength",
FT_UINT8, BASE_HEX, 0, 0x03,
NULL, HFILL }},
{&hf_ieee80211_ampduparam_mpdu_start_spacing,
{"MPDU Density", "wlan_mgt.ht.ampduparam.mpdudensity",
FT_UINT8, BASE_HEX, VALS(&ampduparam_mpdu_start_spacing_flags), 0x1c,
NULL, HFILL }},
{&hf_ieee80211_ampduparam_reserved,
{"Reserved", "wlan_mgt.ht.ampduparam.reserved",
FT_UINT8, BASE_HEX, NULL, 0xE0,
NULL, HFILL }},
{&hf_ieee80211_mcsset,
{"Rx Supported Modulation and Coding Scheme Set", "wlan_mgt.ht.mcsset",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_mcsset_vs,
{"Rx Supported Modulation and Coding Scheme Set (VS)", "wlan_mgt.vs.ht.mcsset",
FT_STRING, BASE_NONE, NULL, 0, "Vendor Specific Rx Supported Modulation and Coding Scheme Set", HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask,
{"Rx Modulation and Coding Scheme (One bit per modulation)", "wlan_mgt.ht.mcsset.rxbitmask",
FT_NONE, BASE_NONE, NULL, 0, "One bit per modulation", HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_0to7,
{"Rx Bitmask Bits 0-7", "wlan_mgt.ht.mcsset.rxbitmask.0to7",
FT_UINT32, BASE_HEX, 0, 0x000000ff, NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_8to15,
{"Rx Bitmask Bits 8-15", "wlan_mgt.ht.mcsset.rxbitmask.8to15",
FT_UINT32, BASE_HEX, 0, 0x0000ff00, NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_16to23,
{"Rx Bitmask Bits 16-23", "wlan_mgt.ht.mcsset.rxbitmask.16to23",
FT_UINT32, BASE_HEX, 0, 0x00ff0000, NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_24to31,
{"Rx Bitmask Bits 24-31", "wlan_mgt.ht.mcsset.rxbitmask.24to31",
FT_UINT32, BASE_HEX, 0, 0xff000000, NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_32,
{"Rx Bitmask Bit 32", "wlan_mgt.ht.mcsset.rxbitmask.32",
FT_UINT32, BASE_HEX, 0, 0x000001, NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_33to38,
{"Rx Bitmask Bits 33-38", "wlan_mgt.ht.mcsset.rxbitmask.33to38",
FT_UINT32, BASE_HEX, 0, 0x00007e, NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_39to52,
{"Rx Bitmask Bits 39-52", "wlan_mgt.ht.mcsset.rxbitmask.39to52",
FT_UINT32, BASE_HEX, 0, 0x1fff80, NULL, HFILL }},
{&hf_ieee80211_mcsset_rx_bitmask_53to76,
{"Rx Bitmask Bits 53-76", "wlan_mgt.ht.mcsset.rxbitmask.53to76",
FT_UINT32, BASE_HEX, 0, 0x1fffffe0, NULL, HFILL }},
{&hf_ieee80211_mcsset_highest_data_rate,
{"Highest Supported Data Rate", "wlan_mgt.ht.mcsset.highestdatarate",
FT_UINT16, BASE_HEX, 0, 0x03ff, NULL, HFILL }},
{&hf_ieee80211_mcsset_tx_mcs_set_defined,
{"Tx Supported MCS Set", "wlan_mgt.ht.mcsset.txsetdefined",
FT_BOOLEAN, 16, TFS (&mcsset_tx_mcs_set_defined_flag), 0x0001,
NULL, HFILL }},
{&hf_ieee80211_mcsset_tx_rx_mcs_set_not_equal,
{"Tx and Rx MCS Set", "wlan_mgt.ht.mcsset.txrxmcsnotequal",
FT_BOOLEAN, 16, TFS (&mcsset_tx_rx_mcs_set_not_equal_flag), 0x0002,
NULL, HFILL }},
{&hf_ieee80211_mcsset_tx_max_spatial_streams,
{"Tx Maximum Number of Spatial Streams Supported", "wlan_mgt.ht.mcsset.txmaxss",
FT_UINT16, BASE_HEX, VALS (&mcsset_tx_max_spatial_streams_flags) , 0x000c,
NULL, HFILL }},
{&hf_ieee80211_mcsset_tx_unequal_modulation,
{"Unequal Modulation", "wlan_mgt.ht.mcsset.txunequalmod",
FT_BOOLEAN, 16, TFS (&tfs_supported_not_supported), 0x0010,
NULL, HFILL }},
{&hf_ieee80211_htex_cap,
{"HT Extended Capabilities", "wlan_mgt.htex.capabilities", FT_UINT16, BASE_HEX,
NULL, 0, "HT Extended Capability information", HFILL }},
{&hf_ieee80211_htex_vs_cap,
{"HT Extended Capabilities (VS)", "wlan_mgt.vs.htex.capabilities", FT_UINT16, BASE_HEX,
NULL, 0, "Vendor Specific HT Extended Capability information", HFILL }},
{&hf_ieee80211_htex_pco,
{"Transmitter supports PCO", "wlan_mgt.htex.capabilities.pco",
FT_BOOLEAN, 16, TFS (&tfs_supported_not_supported), 0x0001,
NULL, HFILL }},
{&hf_ieee80211_htex_transtime,
{"Time needed to transition between 20MHz and 40MHz", "wlan_mgt.htex.capabilities.transtime",
FT_UINT16, BASE_HEX, VALS (&htex_transtime_flags), 0x0006,
NULL, HFILL }},
{&hf_ieee80211_htex_mcs,
{"MCS Feedback capability", "wlan_mgt.htex.capabilities.mcs",
FT_UINT16, BASE_HEX, VALS (&htex_mcs_flags), 0x0300,
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
{"Transmit Beam Forming (TxBF) Capabilities", "wlan_mgt.txbf", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_txbf_vs,
{"Transmit Beam Forming (TxBF) Capabilities (VS)", "wlan_mgt.vs.txbf", FT_UINT16, BASE_HEX,
NULL, 0, "Vendor Specific Transmit Beam Forming (TxBF) Capabilities", HFILL }},
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
FT_UINT32, BASE_HEX, VALS (&txbf_calib_flag), 0x000000c0,
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
FT_UINT32, BASE_HEX, VALS (&txbf_feedback_flags), 0x00001800,
NULL, HFILL }},
{&hf_ieee80211_txbf_expl_uncomp_fm_feed,
{"Receiver can return explicit uncompressed Beamforming Feedback Matrix", "wlan_mgt.txbf.fm.uncompressed.rbf",
FT_UINT32, BASE_HEX, VALS (&txbf_feedback_flags), 0x00006000,
NULL, HFILL }},
{&hf_ieee80211_txbf_expl_comp_fm_feed,
{"STA can compress and use compressed Beamforming Feedback Matrix", "wlan_mgt.txbf.fm.compressed.bf",
FT_UINT32, BASE_HEX, VALS (&txbf_feedback_flags), 0x00018000,
"Station can compress and use compressed Beamforming Feedback Matrix", HFILL }},
{&hf_ieee80211_txbf_min_group,
{"Minimal grouping used for explicit feedback reports", "wlan_mgt.txbf.mingroup",
FT_UINT32, BASE_HEX, VALS (&txbf_min_group_flags), 0x00060000,
NULL, HFILL }},
{&hf_ieee80211_txbf_csi_num_bf_ant,
{"Max antennae STA can support when CSI feedback required", "wlan_mgt.txbf.csinumant",
FT_UINT32, BASE_HEX, VALS (&txbf_antenna_flags), 0x00180000,
"Max antennae station can support when CSI feedback required", HFILL }},
{&hf_ieee80211_txbf_uncomp_sm_bf_ant,
{"Max antennae STA can support when uncompressed Beamforming feedback required", "wlan_mgt.txbf.fm.uncompressed.maxant",
FT_UINT32, BASE_HEX, VALS (&txbf_antenna_flags), 0x00600000,
"Max antennae station can support when uncompressed Beamforming feedback required", HFILL }},
{&hf_ieee80211_txbf_comp_sm_bf_ant,
{"Max antennae STA can support when compressed Beamforming feedback required", "wlan_mgt.txbf.fm.compressed.maxant",
FT_UINT32, BASE_HEX, VALS (&txbf_antenna_flags), 0x01800000,
"Max antennae station can support when compressed Beamforming feedback required", HFILL }},
{&hf_ieee80211_txbf_csi_max_rows_bf,
{"Maximum number of rows of CSI explicit feedback", "wlan_mgt.txbf.csi.maxrows",
FT_UINT32, BASE_HEX, VALS (&txbf_csi_max_rows_bf_flags), 0x06000000,
NULL, HFILL }},
{&hf_ieee80211_txbf_chan_est,
{"Maximum number of space time streams for which channel dimensions can be simultaneously estimated", "wlan_mgt.txbf.channelest",
FT_UINT32, BASE_HEX, VALS (&txbf_chan_est_flags), 0x18000000,
NULL, HFILL }},
{&hf_ieee80211_txbf_resrv,
{"Reserved", "wlan_mgt.txbf.reserved",
FT_UINT32, BASE_HEX, NULL, 0xe0000000,
NULL, HFILL }},
{&hf_ieee80211_hta_cc,
{"HT Control Channel", "wlan_mgt.hta.control_channel", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_hta_cap,
{"HT Additional Capabilities", "wlan_mgt.hta.capabilities", FT_UINT16, BASE_HEX,
NULL, 0, "HT Additional Capability information", HFILL }},
{&hf_ieee80211_hta_ext_chan_offset,
{"Extension Channel Offset", "wlan_mgt.hta.capabilities.extchan",
FT_UINT16, BASE_HEX, VALS (&hta_ext_chan_offset_flag), 0x0003,
NULL, HFILL }},
{&hf_ieee80211_hta_rec_tx_width,
{"Recommended Tx Channel Width", "wlan_mgt.hta.capabilities.rectxwidth",
FT_BOOLEAN, 16, TFS (&hta_rec_tx_width_flag), 0x0004,
"Recommended Transmit Channel Width", HFILL }},
{&hf_ieee80211_hta_rifs_mode,
{"Reduced Interframe Spacing (RIFS) Mode", "wlan_mgt.hta.capabilities.rifsmode",
FT_BOOLEAN, 16, TFS (&hta_rifs_mode_flag), 0x0008,
NULL, HFILL }},
{&hf_ieee80211_hta_controlled_access,
{"Controlled Access Only", "wlan_mgt.hta.capabilities.controlledaccess",
FT_BOOLEAN, 16, TFS (&hta_controlled_access_flag), 0x0010,
NULL, HFILL }},
{&hf_ieee80211_hta_service_interval,
{"Service Interval Granularity", "wlan_mgt.hta.capabilities.serviceinterval",
FT_UINT16, BASE_HEX, VALS (&hta_service_interval_flag), 0x00E0,
NULL, HFILL }},
{&hf_ieee80211_hta_operating_mode,
{"Operating Mode", "wlan_mgt.hta.capabilities.operatingmode",
FT_UINT16, BASE_HEX, VALS (&hta_operating_mode_flag), 0x0003,
NULL, HFILL }},
{&hf_ieee80211_hta_non_gf_devices,
{"Non Greenfield (GF) devices Present", "wlan_mgt.hta.capabilities.nongfdevices",
FT_BOOLEAN, 16, TFS (&hta_non_gf_devices_flag), 0x0004,
"on Greenfield (GF) devices Present", HFILL }},
{&hf_ieee80211_hta_basic_stbc_mcs,
{"Basic STB Modulation and Coding Scheme (MCS)", "wlan_mgt.hta.capabilities.",
FT_UINT16, BASE_HEX, NULL , 0x007f,
NULL, HFILL }},
{&hf_ieee80211_hta_dual_stbc_protection,
{"Dual Clear To Send (CTS) Protection", "wlan_mgt.hta.capabilities.",
FT_BOOLEAN, 16, TFS (&hta_dual_stbc_protection_flag), 0x0080,
NULL, HFILL }},
{&hf_ieee80211_hta_secondary_beacon,
{"Secondary Beacon", "wlan_mgt.hta.capabilities.",
FT_BOOLEAN, 16, TFS (&hta_secondary_beacon_flag), 0x0100,
NULL, HFILL }},
{&hf_ieee80211_hta_lsig_txop_protection,
{"L-SIG TXOP Protection Support", "wlan_mgt.hta.capabilities.",
FT_BOOLEAN, 16, TFS (&hta_lsig_txop_protection_flag), 0x0200,
NULL, HFILL }},
{&hf_ieee80211_hta_pco_active,
{"Phased Coexistence Operation (PCO) Active", "wlan_mgt.hta.capabilities.",
FT_BOOLEAN, 16, TFS (&hta_pco_active_flag), 0x0400,
NULL, HFILL }},
{&hf_ieee80211_hta_pco_phase,
{"Phased Coexistence Operation (PCO) Phase", "wlan_mgt.hta.capabilities.",
FT_BOOLEAN, 16, TFS (&hta_pco_phase_flag), 0x0800,
NULL, HFILL }},
{&hf_ieee80211_antsel,
{"Antenna Selection (ASEL) Capabilities", "wlan_mgt.asel",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_antsel_vs,
{"Antenna Selection (ASEL) Capabilities (VS)", "wlan_mgt.vs.asel",
FT_UINT8, BASE_HEX, NULL, 0, "Vendor Specific Antenna Selection (ASEL) Capabilities", HFILL }},
{&hf_ieee80211_antsel_b0,
{"Antenna Selection Capable", "wlan_mgt.asel.capable",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x01, NULL, HFILL }},
{&hf_ieee80211_antsel_b1,
{"Explicit CSI Feedback Based Tx ASEL", "wlan_mgt.asel.txcsi",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x02, NULL, HFILL }},
{&hf_ieee80211_antsel_b2,
{"Antenna Indices Feedback Based Tx ASEL", "wlan_mgt.asel.txif",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x04, NULL, HFILL }},
{&hf_ieee80211_antsel_b3,
{"Explicit CSI Feedback", "wlan_mgt.asel.csi",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x08, NULL, HFILL }},
{&hf_ieee80211_antsel_b4,
{"Antenna Indices Feedback", "wlan_mgt.asel.if",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x10, NULL, HFILL }},
{&hf_ieee80211_antsel_b5,
{"Rx ASEL", "wlan_mgt.asel.rx",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x20, NULL, HFILL }},
{&hf_ieee80211_antsel_b6,
{"Tx Sounding PPDUs", "wlan_mgt.asel.sppdu",
FT_BOOLEAN, 8, TFS (&tfs_supported_not_supported), 0x40, NULL, HFILL }},
{&hf_ieee80211_antsel_b7,
{"Reserved", "wlan_mgt.asel.reserved",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL }},
{&hf_ieee80211_ht_info_delimiter1,
{"HT Information Subset (1 of 3)", "wlan_mgt.ht.info.delim1",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ht_info_primary_channel,
{"Primary Channel", "wlan_mgt.ht.info.primarychannel",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ht_info_secondary_channel_offset,
{"Secondary channel offset", "wlan_mgt.ht.info.secchanoffset",
FT_UINT8, BASE_HEX, VALS (&ht_info_secondary_channel_offset_flags), 0x03, NULL, HFILL }},
{&hf_ieee80211_ht_info_channel_width,
{"Supported channel width", "wlan_mgt.ht.info.chanwidth",
FT_BOOLEAN, 8, TFS (&ht_info_channel_width_flag), 0x04, NULL, HFILL }},
{&hf_ieee80211_ht_info_rifs_mode,
{"Reduced Interframe Spacing (RIFS)", "wlan_mgt.ht.info.rifs",
FT_BOOLEAN, 8, TFS (&ht_info_rifs_mode_flag), 0x08, NULL, HFILL }},
{&hf_ieee80211_ht_info_psmp_stas_only,
{"Power Save Multi-Poll (PSMP) stations only", "wlan_mgt.ht.info.psmponly",
FT_BOOLEAN, 8, TFS (&ht_info_psmp_stas_only_flag), 0x10, NULL, HFILL }},
{&hf_ieee80211_ht_info_service_interval_granularity,
{"Shortest service interval", "wlan_mgt.ht.info.",
FT_UINT8, BASE_HEX, VALS (&ht_info_service_interval_granularity_flags), 0xe0, NULL, HFILL }},
{&hf_ieee80211_ht_info_delimiter2,
{"HT Information Subset (2 of 3)", "wlan_mgt.ht.info.delim2",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ht_info_operating_mode,
{"Operating mode of BSS", "wlan_mgt.ht.info.operatingmode",
FT_UINT16, BASE_HEX, VALS (&ht_info_operating_mode_flags), 0x0003, NULL, HFILL }},
{&hf_ieee80211_ht_info_non_greenfield_sta_present,
{"Non-greenfield STAs present", "wlan_mgt.ht.info.greenfield",
FT_BOOLEAN, 16, TFS (&ht_info_non_greenfield_sta_present_flag), 0x0004, NULL, HFILL }},
{&hf_ieee80211_ht_info_transmit_burst_limit,
{"Transmit burst limit", "wlan_mgt.ht.info.burstlim",
FT_BOOLEAN, 16, TFS (&ht_info_transmit_burst_limit_flag), 0x0008, NULL, HFILL }},
{&hf_ieee80211_ht_info_obss_non_ht_stas_present,
{"OBSS non-HT STAs present", "wlan_mgt.ht.info.obssnonht",
FT_BOOLEAN, 16, TFS (&ht_info_obss_non_ht_stas_present_flag), 0x0010, NULL, HFILL }},
{&hf_ieee80211_ht_info_reserved_1,
{"Reserved", "wlan_mgt.ht.info.reserved1",
FT_UINT16, BASE_HEX, NULL, 0xffe0, NULL, HFILL }},
{&hf_ieee80211_ht_info_delimiter3,
{"HT Information Subset (3 of 3)", "wlan_mgt.ht.info.delim3",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ht_info_reserved_2,
{"Reserved", "wlan_mgt.ht.info.reserved2",
FT_UINT16, BASE_HEX, NULL, 0x003f, NULL, HFILL }},
{&hf_ieee80211_ht_info_dual_beacon,
{"Dual beacon", "wlan_mgt.ht.info.dualbeacon",
FT_BOOLEAN, 16, TFS (&ht_info_dual_beacon_flag), 0x0040, NULL, HFILL }},
{&hf_ieee80211_ht_info_dual_cts_protection,
{"Dual Clear To Send (CTS) protection", "wlan_mgt.ht.info.dualcts",
FT_BOOLEAN, 16, TFS (&ht_info_dual_cts_protection_flag), 0x0080, NULL, HFILL }},
{&hf_ieee80211_ht_info_secondary_beacon,
{"Beacon ID", "wlan_mgt.ht.info.secondarybeacon",
FT_BOOLEAN, 16, TFS (&ht_info_secondary_beacon_flag), 0x0100, NULL, HFILL }},
{&hf_ieee80211_ht_info_lsig_txop_protection_full_support,
{"L-SIG TXOP Protection Full Support", "wlan_mgt.ht.info.lsigprotsupport",
FT_BOOLEAN, 16, TFS (&ht_info_lsig_txop_protection_full_support_flag), 0x0200, NULL, HFILL }},
{&hf_ieee80211_ht_info_pco_active,
{"Phased Coexistence Operation (PCO)", "wlan_mgt.ht.info.pco.active",
FT_BOOLEAN, 16, TFS (&tfs_active_inactive), 0x0400, NULL, HFILL }},
{&hf_ieee80211_ht_info_pco_phase,
{"Phased Coexistence Operation (PCO) Phase", "wlan_mgt.ht.info.pco.phase",
FT_BOOLEAN, 16, TFS (&ht_info_pco_phase_flag), 0x0800, NULL, HFILL }},
{&hf_ieee80211_ht_info_reserved_3,
{"Reserved", "wlan_mgt.ht.info.reserved3",
FT_UINT16, BASE_HEX, NULL, 0xf000, NULL, HFILL }},
{&hf_ieee80211_tag_ap_channel_report_regulatory_class,
{"Regulatory Class", "wlan_mgt.ap_channel_report.regulatory_class",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_ap_channel_report_channel_list,
{"Channel List", "wlan_mgt.ap_channel_report.channel_list",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_ieee80211_tag_secondary_channel_offset,
{"Secondary Channel Offset", "wlan_mgt.secchanoffset",
FT_UINT8, BASE_HEX, VALS (&ieee80211_tag_secondary_channel_offset_flags), 0,
NULL, HFILL }},
{&hf_ieee80211_tag_power_constraint_local,
{"Local Power Constraint", "wlan_mgt.powercon.local",
FT_UINT8, BASE_HEX, NULL, 0,
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
{"Channel Switch Count", "wlan_mgt.csa.channel_switch_count",
FT_UINT8, BASE_DEC, NULL, 0,
"Set to the number of TBTTs until the STA sending the Channel Switch Announcement element switches to the new channel or shall be set to 0", HFILL }},
{&hf_ieee80211_tag_measure_request_token,
{"Measurement Token", "wlan_mgt.measure.req.token",
FT_UINT8, BASE_HEX, NULL, 0xff, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode,
{"Measurement Request Mode", "wlan_mgt.measure.req.mode",
FT_UINT8, BASE_HEX, NULL, 0xff, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_parallel,
{"Parallel", "wlan_mgt.measure.req.reqmode.parallel",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_enable,
{"Measurement Request Mode Field", "wlan_mgt.measure.req.reqmode.enable",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_request,
{"Measurement Reports", "wlan_mgt.measure.req.reqmode.request",
FT_BOOLEAN, 8, TFS (&tfs_accepted_not_accepted), 0x04, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_report,
{"Autonomous Measurement Reports", "wlan_mgt.measure.req.reqmode.report",
FT_BOOLEAN, 8, TFS (&tfs_accepted_not_accepted), 0x08, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_duration_mandatory,
{"Duration Mandatory", "wlan_mgt.measure.req.reqmode.duration_mandatory",
FT_BOOLEAN, 8, TFS (&tfs_accepted_not_accepted), 0x10, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mode_reserved,
{"Reserved", "wlan_mgt.measure.req.reqmode.reserved",
FT_UINT8, BASE_HEX, NULL, 0xE0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_type,
{"Measurement Request Type", "wlan_mgt.measure.req.reqtype",
FT_UINT8, BASE_HEX, VALS (&ieee80211_tag_measure_request_type_flags), 0x00, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_channel_number,
{"Measurement Channel Number", "wlan_mgt.measure.req.channelnumber",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_start_time,
{"Measurement Start Time", "wlan_mgt.measure.req.starttime",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_duration,
{"Measurement Duration", "wlan_mgt.measure.req.channelnumber",
FT_UINT16, BASE_HEX, NULL, 0, "in TU (1 TU = 1024 us)", HFILL }},
{&hf_ieee80211_tag_measure_request_regulatory_class,
{"Measurement Channel Number", "wlan_mgt.measure.req.regclass",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_randomization_interval,
{"Randomization Interval", "wlan_mgt.measure.req.randint",
FT_UINT16, BASE_HEX, NULL, 0, "in TU (1 TU = 1024 us)", HFILL }},
{&hf_ieee80211_tag_measure_request_measurement_mode,
{"Measurement Mode", "wlan_mgt.measure.req.measurementmode",
FT_UINT8, BASE_HEX, VALS(ieee80211_tag_measure_request_measurement_mode_flags), 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_bssid,
{"BSSID", "wlan_mgt.measure.req.bssid",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_subelement_length,
{"Length", "wlan_mgt.measure.req.sub.length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_id,
{"SubElement ID", "wlan_mgt.measure.req.beacon.sub.id",
FT_UINT8, BASE_DEC, VALS(ieee80211_tag_measure_request_beacon_sub_id_flags), 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_ssid,
{"SSID", "wlan_mgt.measure.req.beacon.sub.ssid",
FT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_bri_reporting_condition,
{"Reporting Condition", "wlan_mgt.measure.req.beacon.sub.bri.repcond",
FT_UINT8, BASE_HEX, VALS(ieee80211_tag_measure_request_beacon_sub_bri_reporting_condition_flags), 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_bri_threshold_offset,
{"Threshold/Offset", "wlan_mgt.measure.req.beacon.sub.bri.threshold_offset",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_reporting_detail,
{"Reporting Detail", "wlan_mgt.measure.req.beacon.sub.bri.reporting_detail",
FT_UINT8, BASE_HEX, VALS(ieee80211_tag_measure_request_beacon_sub_reporting_detail_flags), 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_sub_request,
{"Request", "wlan_mgt.measure.req.beacon.sub.request",
FT_UINT8, BASE_DEC, 0, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_beacon_unknown,
{"Unknown Data", "wlan_mgt.measure.req.beacon.unknown",
FT_BYTES, BASE_NONE, NULL, 0, "(not interpreted)", HFILL }},
{&hf_ieee80211_tag_measure_request_frame_request_type,
{"Frame Request Type", "wlan_mgt.measure.req.frame_request_type",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_mac_address,
{"MAC Address", "wlan_mgt.measure.req.mac_address",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_peer_mac_address,
{"Peer MAC Address", "wlan_mgt.measure.req.peer_mac_address",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_request_group_id,
{"Group ID", "wlan_mgt.measure.req.groupid",
FT_UINT8, BASE_HEX, VALS(ieee80211_tag_measure_request_group_id_flags), 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_measurement_token,
{"Measurement Token", "wlan_mgt.measure.req.token",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_mode,
{"Measurement Report Mode", "wlan_mgt.measure.req.mode",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_mode_late,
{"Measurement Report Mode Field", "wlan_mgt.measure.rep.repmode.late",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_mode_incapable,
{"Measurement Reports", "wlan_mgt.measure.rep.repmode.incapable",
FT_BOOLEAN, 8, TFS (&tfs_accepted_not_accepted), 0x02, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_mode_refused,
{"Autonomous Measurement Reports", "wlan_mgt.measure.rep.repmode.refused",
FT_BOOLEAN, 8, TFS (&tfs_accepted_not_accepted), 0x04, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_mode_reserved,
{"Reserved", "wlan_mgt.measure.rep.repmode.reserved",
FT_UINT8, BASE_HEX, NULL, 0xf8, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_type,
{"Measurement Report Type", "wlan_mgt.measure.rep.reptype",
FT_UINT8, BASE_HEX, VALS (&ieee80211_tag_measure_report_type_flags), 0x00, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_channel_number,
{"Measurement Channel Number", "wlan_mgt.measure.rep.channelnumber",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_start_time,
{"Measurement Start Time", "wlan_mgt.measure.rep.starttime",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_duration,
{"Measurement Duration", "wlan_mgt.measure.rep.channelnumber",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_cca_busy_fraction,
{"CCA Busy Fraction", "wlan_mgt.measure.rep.ccabusy",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_basic_map_field,
{"Map Field", "wlan_mgt.measure.rep.mapfield",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_bss,
{"BSS", "wlan_mgt.measure.rep.repmode.mapfield.bss",
FT_BOOLEAN, 8, TFS (&ieee80211_tag_measure_map_field_bss_flag), 0x01, NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_odfm,
{"Orthogonal Frequency Division Multiplexing (ODFM) Preamble", "wlan_mgt.measure.rep.repmode.mapfield.bss",
FT_BOOLEAN, 8, TFS (&tfs_detected_not_detected), 0x02, NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_unident_signal,
{"Unidentified Signal", "wlan_mgt.measure.rep.repmode.mapfield.unidentsig",
FT_BOOLEAN, 8, TFS (&tfs_detected_not_detected), 0x04, NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_radar,
{"Radar", "wlan_mgt.measure.rep.repmode.mapfield.radar",
FT_BOOLEAN, 8, TFS (&tfs_detected_not_detected), 0x08, NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_unmeasured,
{"Unmeasured", "wlan_mgt.measure.rep.repmode.mapfield.unmeasured",
FT_BOOLEAN, 8, TFS (&tfs_true_false), 0x10, NULL, HFILL }},
{&hf_ieee80211_tag_measure_map_field_reserved,
{"Reserved", "wlan_mgt.measure.rep.repmode.mapfield.reserved",
FT_UINT8, BASE_HEX, NULL, 0xe0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report,
{"Receive Power Indicator (RPI) Histogram Report", "wlan_mgt.measure.rep.rpi.histogram_report",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_0,
{"RPI 0 Density", "wlan_mgt.measure.rep.rpi.rpi0density",
FT_UINT8, BASE_HEX, NULL, 0, "Receive Power Indicator (RPI) 0 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_1,
{"RPI 1 Density", "wlan_mgt.measure.rep.rpi.rpi1density",
FT_UINT8, BASE_HEX, NULL, 0, "Receive Power Indicator (RPI) 1 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_2,
{"RPI 2 Density", "wlan_mgt.measure.rep.rpi.rpi2density",
FT_UINT8, BASE_HEX, NULL, 0, "Receive Power Indicator (RPI) 2 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_3,
{"RPI 3 Density", "wlan_mgt.measure.rep.rpi.rpi3density",
FT_UINT8, BASE_HEX, NULL, 0, "Receive Power Indicator (RPI) 3 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_4,
{"RPI 4 Density", "wlan_mgt.measure.rep.rpi.rpi4density",
FT_UINT8, BASE_HEX, NULL, 0, "Receive Power Indicator (RPI) 4 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_5,
{"RPI 5 Density", "wlan_mgt.measure.rep.rpi.rpi5density",
FT_UINT8, BASE_HEX, NULL, 0, "Receive Power Indicator (RPI) 5 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_6,
{"RPI 6 Density", "wlan_mgt.measure.rep.rpi.rpi6density",
FT_UINT8, BASE_HEX, NULL, 0, "Receive Power Indicator (RPI) 6 Density", HFILL }},
{&hf_ieee80211_tag_measure_rpi_histogram_report_7,
{"RPI 7 Density", "wlan_mgt.measure.rep.rpi.rpi7density",
FT_UINT8, BASE_HEX, NULL, 0, "Receive Power Indicator (RPI) 7 Density", HFILL }},
{&hf_ieee80211_tag_measure_report_regulatory_class,
{"Regulatory Class", "wlan_mgt.measure.rep.regclass",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_channel_load,
{"Channel Load", "wlan_mgt.measure.rep.chanload",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_frame_info,
{"Reported Frame Information", "wlan_mgt.measure.rep.frameinfo",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_frame_info_phy_type,
{"Condensed PHY", "wlan_mgt.measure.rep.frameinfo.phytype",
FT_UINT8, BASE_HEX, NULL, 0x7F, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_frame_info_frame_type,
{"Reported Frame Type", "wlan_mgt.measure.rep.frameinfo.frametype",
FT_BOOLEAN, 8, TFS(&ieee80211_tag_measure_report_frame_info_frame_type_flag), 0x80, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_rcpi,
{"Received Channel Power Indicator (RCPI)", "wlan_mgt.measure.rep.rcpi",
FT_UINT8, BASE_HEX, NULL, 0, "in dBm", HFILL }},
{&hf_ieee80211_tag_measure_report_rsni,
{"Received Signal to Noise Indicator (RSNI)", "wlan_mgt.measure.rep.rsni",
FT_UINT8, BASE_HEX, NULL, 0, "in dB", HFILL }},
{&hf_ieee80211_tag_measure_report_bssid,
{"BSSID Being Reported", "wlan_mgt.measure.rep.bssid",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ant_id,
{"Antenna ID", "wlan_mgt.measure.rep.antid",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_anpi,
{"ANPI", "wlan_mgt.measure.rep.anpi",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_0,
{"IPI Density 0", "wlan_mgt.measure.rep.ipi_density0",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_1,
{"IPI Density 1", "wlan_mgt.measure.rep.ipi_density1",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_2,
{"IPI Density 2", "wlan_mgt.measure.rep.ipi_density2",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_3,
{"IPI Density 3", "wlan_mgt.measure.rep.ipi_density3",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_4,
{"IPI Density 4", "wlan_mgt.measure.rep.ipi_density4",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_5,
{"IPI Density 5", "wlan_mgt.measure.rep.ipi_density5",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_6,
{"IPI Density 6", "wlan_mgt.measure.rep.ipi_density6",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_7,
{"IPI Density 7", "wlan_mgt.measure.rep.ipi_density7",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_8,
{"IPI Density 8", "wlan_mgt.measure.rep.ipi_density8",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_9,
{"IPI Density 9", "wlan_mgt.measure.rep.ipi_density9",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_ipi_density_10,
{"IPI Density 10", "wlan_mgt.measure.rep.ipi_density10",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_measure_report_parent_tsf,
{"Parent Timing Synchronization Function (TSF)", "wlan_mgt.measure.rep.parenttsf",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_quiet_count,
{"Count", "wlan_mgt.quiet.count",
FT_UINT8, BASE_DEC, NULL, 0, "Set to the number of TBTTs until the beacon interval during which the next quiet interval shall start", HFILL }},
{&hf_ieee80211_tag_quiet_period,
{"Period", "wlan_mgt.quiet.period",
FT_UINT8, BASE_DEC, NULL, 0, "Set to the number of beacon intervals between the start of regularly scheduled quiet intervals", HFILL }},
{&hf_ieee80211_tag_quiet_duration,
{"Duration", "wlan_mgt.quiet.duration",
FT_UINT16, BASE_DEC, NULL, 0, "Set to the duration of the quiet interval", HFILL }},
{&hf_ieee80211_tag_quiet_offset,
{"Offset", "wlan_mgt.quiet.offset",
FT_UINT16, BASE_DEC, NULL, 0, "Set to the offset of the start of the quiet interval from the TBTT", HFILL }},
{&hf_ieee80211_tag_dfs_owner,
{"Owner", "wlan_mgt.dfs.owner",
FT_ETHER, BASE_NONE, NULL, 0, "Set to the individual IEEE MAC address of the STA that is the currently known DFS Owner in the IBSS", HFILL }},
{&hf_ieee80211_tag_dfs_recovery_interval,
{"Recovery Interval", "wlan_mgt.dfs.recovery_interval",
FT_UINT8, BASE_DEC, NULL, 0, "Indicates the time interval that shall be used for DFS owner recovery", HFILL }},
{&hf_ieee80211_tag_dfs_channel_map,
{"Channel Map", "wlan_mgt.dfs.channel_map",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_dfs_channel_number,
{"Channel Number", "wlan_mgt.dfs.channel_number",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_dfs_map,
{"Map", "wlan_mgt.dfs.map",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_erp_info,
{"ERP Information", "wlan_mgt.erp_info",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_erp_info_erp_present,
{"Non ERP Present", "wlan_mgt.erp_info.erp_present",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x01, NULL, HFILL }},
{&hf_ieee80211_tag_erp_info_use_protection,
{"Use Protection", "wlan_mgt.erp_info.use_protection",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{&hf_ieee80211_tag_erp_info_barker_preamble_mode,
{"Barker Preamble Mode", "wlan_mgt.erp_info.barker_preamble_mode",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{&hf_ieee80211_tag_erp_info_reserved,
{"Reserved", "wlan_mgt.erp_info.reserved",
FT_UINT8, BASE_HEX, NULL, 0xF8, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities,
{"Extended Capabilities", "wlan_mgt.extcap",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b0,
{"20/40 BSS Coexistence Management Support", "wlan_mgt.extcap.infoexchange.b0",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0001, "HT Information Exchange Support", HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b1,
{"On-demand beacon", "wlan_mgt.extcap.infoexchange.b1",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0002, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b2,
{"Extended Channel Switching", "wlan_mgt.extcap.infoexchange.b2",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0004, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b3,
{"WAVE indication", "wlan_mgt.extcap.infoexchange.b3",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0008, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b4,
{"PSMP Capability", "wlan_mgt.extcap.infoexchange.b4",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0010, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b6,
{"S-PSMP Support", "wlan_mgt.extcap.infoexchange.b6",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0040, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b27,
{"UTC TSF Offset", "wlan_mgt.extcap.infoexchange.b27",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0008, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b28,
{"Peer U-APSD Buffer STA Support", "wlan_mgt.extcap.infoexchange.b28",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0010, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b29,
{"TDLS Peer PSM Support", "wlan_mgt.extcap.infoexchange.b29",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0020, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b30,
{"TDLS channel switching", "wlan_mgt.extcap.infoexchange.b30",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0040, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b31,
{"Interworking", "wlan_mgt.extcap.infoexchange.b31",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0080, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b32,
{"QoS Map", "wlan_mgt.extcap.infoexchange.b32",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0001, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b33,
{"EBR", "wlan_mgt.extcap.infoexchange.b33",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0002, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b34,
{"SSPN Interface", "wlan_mgt.extcap.infoexchange.b34",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0004, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b36,
{"MSGCF Capability", "wlan_mgt.extcap.infoexchange.b36",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0010, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b37,
{"TDLS support", "wlan_mgt.extcap.infoexchange.b37",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0020, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b38,
{"TDLS Prohibited", "wlan_mgt.extcap.infoexchange.b38",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0040, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b39,
{"TDLS Channel Switching Prohibited", "wlan_mgt.extcap.infoexchange.b39",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0080, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_b40,
{"Reject Unadmitted Frame", "wlan_mgt.extcap.infoexchange.b40",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x0001, NULL, HFILL }},
{&hf_ieee80211_tag_extended_capabilities_serv_int_granularity,
{"Service Interval Granularity",
"wlan_mgt.extcap.infoexchange.serv_int_granularity",
FT_UINT8, BASE_DEC, VALS(service_interval_granularity_vals), 0x000e,
NULL, HFILL }},
{&hf_ieee80211_tag_cisco_ccx1_unknown,
{"Unknown", "wlan_mgt.cisco.ccx1.unknown",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_cisco_ccx1_name,
{"Name", "wlan_mgt.cisco.ccx1.name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_cisco_ccx1_clients,
{"Clients", "wlan_mgt.cisco.ccx1.clients",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid,
{"BSSID", "wlan_mgt.nreport.bssid",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info,
{"BSSID Information", "wlan_mgt.nreport.bssid.info",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_reachability,
{"AP Reachability", "wlan_mgt.nreport.bssid.info.reachability",
FT_UINT16, BASE_HEX, NULL, 0x0003, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_security,
{"Security", "wlan_mgt.nreport.bssid.info.security",
FT_UINT16, BASE_HEX, NULL, 0x0004, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_key_scope,
{"Key Scope", "wlan_mgt.nreport.bssid.info.keyscope",
FT_UINT16, BASE_HEX, NULL, 0x0008, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_spec_mng,
{"Capability: Spectrum Management", "wlan_mgt.nreport.bssid.info.capability.specmngt",
FT_UINT16, BASE_HEX, NULL, 0x0010, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_qos,
{"Capability: QoS", "wlan_mgt.nreport.bssid.info.capability.qos",
FT_UINT16, BASE_HEX, NULL, 0x0020, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_apsd,
{"Capability: APSD", "wlan_mgt.nreport.bssid.info.capability.apsd",
FT_UINT16, BASE_HEX, NULL, 0x0040, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_radio_msnt,
{"Capability: Radio Measurement", "wlan_mgt.nreport.bssid.info.capability.radiomsnt",
FT_UINT16, BASE_HEX, NULL, 0x0080, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_dback,
{"Capability: Delayed Block Ack", "wlan_mgt.nreport.bssid.info.capability.dback",
FT_UINT16, BASE_HEX, NULL, 0x0100, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_capability_iback,
{"Capability: Immediate Block Ack", "wlan_mgt.nreport.bssid.info.capability.iback",
FT_UINT16, BASE_HEX, NULL, 0x0200, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_mobility_domain,
{"Mobility Domain", "wlan_mgt.nreport.bssid.info.mobilitydomain",
FT_UINT16, BASE_HEX, NULL, 0x0400, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_high_throughput,
{"High Throughput", "wlan_mgt.nreport.bssid.info.hthoughput",
FT_UINT16, BASE_HEX, NULL, 0x0800, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_bssid_info_reserved,
{"Reserved", "wlan_mgt.nreport.bssid.info.reserved",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_reg_class,
{"Regulatory Class", "wlan_mgt.nreport.regclass",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_channel_number,
{"Channel Number", "wlan_mgt.nreport.channumber",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_neighbor_report_phy_type,
{"PHY Type", "wlan_mgt.nreport.phytype",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_supported_reg_classes_current,
{"Current Regulatory Class", "wlan_mgt.supregclass.current",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_supported_reg_classes_alternate,
{"Alternate Regulatory Classes", "wlan_mgt.supregclass.alt",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_type,
{"Type", "wlan_mgt.wfa.ie.type",
FT_UINT8, BASE_HEX, VALS(ieee802111_wfa_ie_type_vals), 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_version,
{"WPA Version", "wlan_mgt.wfa.ie.wpa.version",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_mcs,
{"Multicast Cipher Suite", "wlan_mgt.wfa.ie.wpa.mcs", FT_UINT32, BASE_CUSTOM,
wpa_mcs_base_custom, 0, "Contains the cipher suite selector used by the BSS to protect broadcast/multicast traffic", HFILL }},
{&hf_ieee80211_wfa_ie_wpa_mcs_oui,
{"Multicast Cipher Suite OUI", "wlan_mgt.wfa.ie.wpa.mcs.oui", FT_UINT24, BASE_CUSTOM,
oui_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_mcs_type,
{"Multicast Cipher Suite type", "wlan_mgt.wfa.ie.wpa.mcs.type", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_mcs_wfa_type,
{"Multicast Cipher Suite type", "wlan_mgt.wfa.ie.wpa.mcs.type", FT_UINT8, BASE_DEC,
VALS(ieee80211_wfa_ie_wpa_cipher_vals), 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs_count,
{"Unicast Cipher Suite Count", "wlan_mgt.wfa.ie.wpa.ucs.count", FT_UINT16, BASE_DEC,
NULL, 0, "Indicates the number of pairwise cipher suite selectors that are contained in the Unicast Cipher Suite List", HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs_list,
{"Unicast Cipher Suite List", "wlan_mgt.wfa.ie.wpa.ucs.list", FT_NONE, BASE_NONE,
NULL, 0, "Contains a series of cipher suite selectors that indicate the Unicast cipher suites", HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs,
{"Unicast Cipher Suite", "wlan_mgt.wfa.ie.wpa.ucs", FT_UINT32, BASE_CUSTOM,
wpa_ucs_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs_oui,
{"Unicast Cipher Suite OUI", "wlan_mgt.wfa.ie.wpau.cs.oui", FT_UINT24, BASE_CUSTOM,
oui_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs_type,
{"Unicast Cipher Suite type", "wlan_mgt.wfa.ie.wpa.ucs.type", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_ucs_wfa_type,
{"Unicast Cipher Suite type", "wlan_mgt.wfa.ie.wpa.ucs.type", FT_UINT8, BASE_DEC,
VALS(ieee80211_wfa_ie_wpa_cipher_vals), 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms_count,
{"Auth Key Management (AKM) Suite Count", "wlan_mgt.wfa.ie.wpa.akms.count", FT_UINT16, BASE_DEC,
NULL, 0, "Indicates the number of Auth Key Management suite selectors that are contained in the Auth Key Management Suite List", HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms_list,
{"Auth Key Management (AKM) List", "wlan_mgt.wfa.ie.wpa.akms.list", FT_NONE, BASE_NONE,
NULL, 0, "Contains a series of cipher suite selectors that indicate the AKM suites", HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms,
{"Auth Key Management (AKM) Suite", "wlan_mgt.wfa.ie.wpa.akms", FT_UINT32, BASE_CUSTOM,
wpa_akms_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms_oui,
{"Auth Key Management (AKM) OUI", "wlan_mgt.wfa.ie.wpa.akms.oui", FT_UINT24, BASE_CUSTOM,
oui_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms_type,
{"Auth Key Management (AKM) type", "wlan_mgt.wfa.ie.wpa.akms.type", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wpa_akms_wfa_type,
{"Auth Key Management (AKM) type", "wlan_mgt.wfa.ie.wpa.type", FT_UINT8, BASE_DEC,
VALS(ieee80211_wfa_ie_wpa_keymgmt_vals), 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_subtype,
{"WME Subtype", "wlan_mgt.wfa.ie.wme.subtype",
FT_UINT8, BASE_DEC, VALS(ieee802111_wfa_ie_wme_type), 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_version,
{"WME Version", "wlan_mgt.wfa.ie.wme.version",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info,
{"WME QoS Info", "wlan_mgt.wfa.ie.wme.qos_info",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_max_sp_length,
{"Max SP Length", "wlan_mgt.wfa.ie.wme.qos_info.sta.max_sp_length",
FT_UINT8, BASE_HEX, VALS(ieee802111_wfa_ie_wme_qos_info_sta_max_sp_length_vals), 0x60, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_be,
{"AC_BE", "wlan_mgt.wfa.ie.wme.qos_info.sta.ac_be",
FT_BOOLEAN, 8, TFS(&ieee802111_wfa_ie_wme_qos_info_sta_ac_tfs), 0x08, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_bk,
{"AC_BK", "wlan_mgt.wfa.ie.wme.qos_info.sta.ac_bk",
FT_BOOLEAN, 8, TFS(&ieee802111_wfa_ie_wme_qos_info_sta_ac_tfs), 0x04, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_vi,
{"AC_VI", "wlan_mgt.wfa.ie.wme.qos_info.sta.ac_vi",
FT_BOOLEAN, 8, TFS(&ieee802111_wfa_ie_wme_qos_info_sta_ac_tfs), 0x02, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_ac_vo,
{"AC_VO", "wlan_mgt.wfa.ie.wme.qos_info.sta.ac_vo",
FT_BOOLEAN, 8, TFS(&ieee802111_wfa_ie_wme_qos_info_sta_ac_tfs), 0x01, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_sta_reserved,
{"Reserved", "wlan_mgt.wfa.ie.wme.qos_info.sta.reserved",
FT_UINT8, BASE_HEX, NULL, 0x90, "Must Be Zero", HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_ap_u_apsd,
{"U-APSD", "wlan_mgt.wfa.ie.wme.qos_info.ap.u_apsd",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x80, "Indicates the WMM AP is currently supporting unscheduled automatic power save delivery", HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_ap_parameter_set_count,
{"Parameter Set Count", "wlan_mgt.wfa.ie.wme.qos_info.ap.parameter_set_count",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_qos_info_ap_reserved,
{"Reserved", "wlan_mgt.wfa.ie.wme.qos_info.ap.reserved",
FT_UINT8, BASE_HEX, NULL, 0x70, "Must Be Zero", HFILL }},
{&hf_ieee80211_wfa_ie_wme_reserved,
{"Reserved", "wlan_mgt.wfa.ie.wme.reserved",
FT_BYTES, BASE_NONE, NULL, 0, "Must Be Zero", HFILL }},
{&hf_ieee80211_wfa_ie_wme_ac_parameters,
{"Ac Parameters", "wlan_mgt.wfa.ie.wme.acp",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_aci_aifsn,
{"ACI / AIFSN Field", "wlan_mgt.wfa.ie.wme.acp.aci_aifsn",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_aci,
{"ACI", "wlan_mgt.wfa.ie.wme.acp.aci",
FT_UINT8, BASE_DEC, VALS(ieee80211_wfa_ie_wme_acs_vals), 0x60, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_acm,
{"Admission Control Mandatory", "wlan_mgt.wfa.ie.wme.acp.aci",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_aifsn,
{"AIFSN", "wlan_mgt.wfa.ie.wme.acp.aifsn",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_reserved,
{"Reserved", "wlan_mgt.wfa.ie.wme.acp.reserved",
FT_UINT8, BASE_DEC, NULL, 0x80, "Must be Zero", HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_ecw,
{"ECW", "wlan_mgt.wfa.ie.wme.acp.ecw",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_ecw_max,
{"ECW Max", "wlan_mgt.wfa.ie.wme.acp.ecw.max",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_ecw_min,
{"ECW Min", "wlan_mgt.wfa.ie.wme.acp.ecw.min",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_acp_txop_limit,
{"TXOP Limit", "wlan_mgt.wfa.ie.wme.acp.txop_limit",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo,
{"TS Info", "wlan_mgt.wfa.ie.wme.tspec.ts_info",
FT_UINT24, BASE_HEX, NULL, 0, "Traffic Stream (TS) Info", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo_tid,
{"TID", "wlan_mgt.wfa.ie.wme.tspec.ts_info.tid",
FT_UINT24, BASE_DEC, NULL, 0x00001E, "Traffic Stream Info ID (TID)", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo_direction,
{"Direction", "wlan_mgt.wfa.ie.wme.tspec.ts_info.dir", FT_UINT24, BASE_DEC,
VALS (&ieee80211_wfa_ie_wme_tspec_tsinfo_direction_vals), 0x000060, "Traffic Stream (TS) Info Direction", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo_psb,
{"PSB", "wlan_mgt.wfa.ie.wme.tspec.ts_info.psb", FT_UINT24, BASE_DEC,
VALS (&ieee80211_wfa_ie_wme_tspec_tsinfo_psb_vals), 0x000400, "Traffic Stream (TS) Info Power Save Behavior (PSB)", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo_up,
{"UP", "wlan_mgt.wfa.ie.wme.tspec.ts_info.up", FT_UINT24, BASE_DEC,
VALS (&ieee80211_wfa_ie_wme_tspec_tsinfo_up_vals), 0x003800, "Traffic Stream (TS) Info User Priority (UP)", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_tsinfo_reserved,
{"Reserved", "wlan_mgt.wfa.ie.wme.tspec.ts_info.reserved", FT_UINT24, BASE_HEX,
NULL, 0xFFC381, "Must be Zero", HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_nor_msdu,
{"Normal MSDU Size", "wlan_mgt.wfa.ie.wme.tspec.nor_msdu",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_max_msdu,
{"Maximum MSDU Size", "wlan_mgt.wfa.ie.wme.tspec.max_msdu",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_min_srv,
{"Minimum Service Interval", "wlan_mgt.wfa.ie.wme.tspec.min_srv",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_max_srv,
{"Maximum Service Interval", "wlan_mgt.wfa.ie.wme.tspec.max_srv",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_inact_int,
{"Inactivity Interval", "wlan_mgt.wfa.ie.wme.tspec.inact_int",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_susp_int,
{"Suspension Interval", "wlan_mgt.wfa.ie.wme.tspec.susp_int",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_srv_start,
{"Service Start Time", "wlan_mgt.wfa.ie.wme.tspec.srv_start",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_min_data,
{"Minimum Data Rate", "wlan_mgt.wfa.ie.wme.tspec.min_data",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_mean_data,
{"Mean Data Rate", "wlan_mgt.wfa.ie.wme.tspec.mean_data",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_peak_data,
{"Peak Data Rate", "wlan_mgt.wfa.ie.wme.tspec.peak_data",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_burst_size,
{"Burst Size", "wlan_mgt.wfa.ie.wme.tspec.burst_size",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_delay_bound,
{"Delay Bound", "wlan_mgt.wfa.ie.wme.tspec.delay_bound",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_min_phy,
{"Minimum PHY Rate", "wlan_mgt.wfa.ie.wme.tspec.min_phy",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_surplus,
{"Surplus Bandwidth Allowance", "wlan_mgt.wfa.ie.wme.tspec.surplus",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_wfa_ie_wme_tspec_medium,
{"Medium Time", "wlan_mgt.wfa.ie.wme.tspec.medium",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_marvell_ie_type,
{"Type", "wlan_mgt.marvell.ie.type",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_marvell_ie_mesh_subtype,
{"Subtype", "wlan_mgt.marvell.ie.subtype",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_marvell_ie_mesh_version,
{"Version", "wlan_mgt.marvell.ie.version",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_marvell_ie_mesh_active_proto_id,
{"Path Selection Protocol", "wlan_mgt.marvell.ie.proto_id",
FT_UINT8, BASE_HEX, VALS(mesh_path_selection_codes), 0, NULL, HFILL }},
{&hf_ieee80211_marvell_ie_mesh_active_metric_id,
{"Path Selection Metric", "wlan_mgt.marvell.ie.metric_id",
FT_UINT8, BASE_HEX, VALS(mesh_metric_codes), 0, NULL, HFILL }},
{&hf_ieee80211_marvell_ie_mesh_cap,
{"Mesh Capabilities", "wlan_mgt.marvell.ie.cap",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_marvell_ie_data,
{ "Marvell IE data", "wlan_mgt.marvell.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_type,
{"Type", "wlan_mgt.atheros.ie.type",
FT_UINT8, BASE_HEX, VALS(atheros_ie_type_vals), 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_subtype,
{"Subtype", "wlan_mgt.atheros.ie.subtype",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_version,
{"Version", "wlan_mgt.atheros.ie.version",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_turbop,
{"Turbo Prime", "wlan_mgt.ie.atheros.capabilities.turbop",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_TURBOP, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_comp,
{"Compression", "wlan_mgt.ie.atheros.capabilities.comp",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_COMP, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_ff,
{"Fast Frames", "wlan_mgt.ie.atheros.capabilities.ff",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_FF, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_xr,
{"eXtended Range", "wlan_mgt.ie.atheros.capabilities.xr",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_XR, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_ar,
{"Advanced Radar", "wlan_mgt.ie.atheros.capabilities.ar",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_AR, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_burst,
{"Burst", "wlan_mgt.ie.atheros.capabilities.burst",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_BURST, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_wme,
{"CWMin tuning", "wlan_mgt.ie.atheros.capabilities.wme",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_WME, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_cap_f_boost,
{"Boost", "wlan_mgt.ie.atheros.capabilities.boost",
FT_BOOLEAN, 8, NULL, ATHEROS_IE_CAP_BOOST, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_advcap_cap,
{"Capabilities", "wlan_mgt.atheros.ie.advcap.cap",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_advcap_defkey,
{"Default key index", "wlan_mgt.atheros.ie.advcap.defkey",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_info,
{"Info", "wlan_mgt.atheros.ie.xr.info",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_base_bssid,
{"Base BSS Id", "wlan_mgt.atheros.ie.xr.base_bssid",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_xr_bssid,
{"XR BSS Id", "wlan_mgt.atheros.ie.xr.xr_bssid",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_xr_beacon,
{"XR Beacon Interval", "wlan_mgt.atheros.ie.xr.xr_beacon",
FT_UINT32, BASE_CUSTOM, beacon_interval_base_custom, 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_base_cap,
{"Base capabilities", "wlan_mgt.atheros.ie.xr.base_cap",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_xr_xr_cap,
{"XR capabilities", "wlan_mgt.atheros.ie.xr.xr_cap",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_atheros_ie_data,
{"Atheros IE data", "wlan_mgt.atheros.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_aironet_ie_type,
{"Aironet IE type", "wlan_mgt.aironet.type",
FT_UINT8, BASE_DEC, VALS(aironet_ie_type_vals), 0, NULL, HFILL }},
{&hf_ieee80211_aironet_ie_version,
{"Aironet IE CCX version?", "wlan_mgt.aironet.version",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_aironet_ie_data,
{ "Aironet IE data", "wlan_mgt.aironet.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ieee80211_qbss_version,
{"QBSS Version", "wlan_mgt.qbss.version",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_qbss_scount,
{"Station Count", "wlan_mgt.qbss.scount",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_qbss_cu,
{"Channel Utilization", "wlan_mgt.qbss.cu",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_qbss_adc,
{"Available Admission Capabilities", "wlan_mgt.qbss.adc",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_qbss2_cu,
{"Channel Utilization", "wlan_mgt.qbss2.cu",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_qbss2_gl,
{"G.711 CU Quantum", "wlan_mgt.qbss2.glimit",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_qbss2_cal,
{"Call Admission Limit", "wlan_mgt.qbss2.cal",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_qbss2_scount,
{"Station Count", "wlan_mgt.qbss2.scount",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_aironet_ie_qos_unk1,
{"Aironet IE QoS unknown 1", "wlan_mgt.aironet.qos.unk1",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_aironet_ie_qos_paramset,
{"Aironet IE QoS paramset", "wlan_mgt.aironet.qos.paramset",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_aironet_ie_qos_val,
{"Aironet IE QoS valueset", "wlan_mgt.aironet.qos.val",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tsinfo,
{"Traffic Stream (TS) Info", "wlan_mgt.ts_info",
FT_UINT24, BASE_HEX, NULL, 0, "Traffic Stream (TS) Info field", HFILL }},
{&hf_ieee80211_tsinfo_type,
{"Traffic Type", "wlan_mgt.ts_info.type", FT_UINT24, BASE_DEC,
VALS (&tsinfo_type), 0x000001, "Traffic Stream (TS) Info Traffic Type", HFILL }},
{&hf_ieee80211_tsinfo_tsid,
{"Traffic Stream ID (TSID)", "wlan_mgt.ts_info.tsid",
FT_UINT24, BASE_DEC, NULL, 0x00001E, "Traffic Stream ID (TSID) Info TSID", HFILL }},
{&hf_ieee80211_tsinfo_dir,
{"Direction", "wlan_mgt.ts_info.dir", FT_UINT24, BASE_DEC,
VALS (&tsinfo_direction), 0x000060, "Traffic Stream (TS) Info Direction", HFILL }},
{&hf_ieee80211_tsinfo_access,
{"Access Policy", "wlan_mgt.ts_info.dir", FT_UINT24, BASE_DEC,
VALS (&tsinfo_access), 0x000180, "Traffic Stream (TS) Info Access Policy", HFILL }},
{&hf_ieee80211_tsinfo_agg,
{"Aggregation", "wlan_mgt.ts_info.agg", FT_UINT24, BASE_DEC,
NULL, 0x000200, "Traffic Stream (TS) Info Access Policy", HFILL }},
{&hf_ieee80211_tsinfo_apsd,
{"Automatic Power-Save Delivery (APSD)", "wlan_mgt.ts_info.apsd", FT_UINT24, BASE_DEC,
NULL, 0x000400, "Traffic Stream (TS) Info Automatic Power-Save Delivery (APSD)", HFILL }},
{&hf_ieee80211_tsinfo_up,
{"User Priority", "wlan_mgt.ts_info.up", FT_UINT24, BASE_DEC,
VALS (&qos_up), 0x003800, "Traffic Stream (TS) Info User Priority", HFILL }},
{&hf_ieee80211_tsinfo_ack,
{"Ack Policy", "wlan_mgt.ts_info.ack", FT_UINT24, BASE_DEC,
VALS (&ack_policy), 0x00C000, "Traffic Stream (TS) Info Ack Policy", HFILL }},
{&hf_ieee80211_tsinfo_sched,
{"Schedule", "wlan_mgt.ts_info.sched", FT_UINT24, BASE_DEC,
NULL, 0x010000, "Traffic Stream (TS) Info Schedule", HFILL }},
{&hf_ieee80211_tsinfo_rsv,
{"Reserved", "wlan_mgt.ts_info.rsv", FT_UINT24, BASE_HEX,
NULL, 0xFE0000, "Must be Zero", HFILL }},
{&hf_ieee80211_tspec_nor_msdu,
{"Normal MSDU Size", "wlan_mgt.tspec.nor_msdu",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_max_msdu,
{"Maximum MSDU Size", "wlan_mgt.tspec.max_msdu",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_min_srv,
{"Minimum Service Interval", "wlan_mgt.tspec.min_srv",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_max_srv,
{"Maximum Service Interval", "wlan_mgt.tspec.max_srv",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_inact_int,
{"Inactivity Interval", "wlan_mgt.tspec.inact_int",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_susp_int,
{"Suspension Interval", "wlan_mgt.tspec.susp_int",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_srv_start,
{"Service Start Time", "wlan_mgt.tspec.srv_start",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_min_data,
{"Minimum Data Rate", "wlan_mgt.tspec.min_data",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_mean_data,
{"Mean Data Rate", "wlan_mgt.tspec.mean_data",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_peak_data,
{"Peak Data Rate", "wlan_mgt.tspec.peak_data",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_burst_size,
{"Burst Size", "wlan_mgt.tspec.burst_size",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_delay_bound,
{"Delay Bound", "wlan_mgt.tspec.delay_bound",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_min_phy,
{"Minimum PHY Rate", "wlan_mgt.tspec.min_phy",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_surplus,
{"Surplus Bandwidth Allowance", "wlan_mgt.tspec.surplus",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tspec_medium,
{"Medium Time", "wlan_mgt.tspec.medium",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_ts_delay,
{"Traffic Stream (TS) Delay", "wlan_mgt.ts_delay",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tclas_process,
{"Processing", "wlan_mgt.tclas_proc.processing", FT_UINT8, BASE_DEC,
VALS(ieee80211_tclas_process_flag), 0, "TCLAS Processing", HFILL }},
{&hf_ieee80211_tag_qos_cap_qos_info,
{"QoS Info", "wlan_mgt.tag.qos_cap.qos_info", FT_UINT8, BASE_HEX,
NULL, 0, "TCLAS Processing", HFILL }},
{&hf_ieee80211_qos_info_field_vo_uapsd,
{"AC_VO U-APSD Flag", "wlan_mgt.tag.qos_cap.qos_info.vo_uapsd",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{&hf_ieee80211_qos_info_field_vi_uapsd,
{"AC_VI U-APSD Flag", "wlan_mgt.tag.qos_cap.qos_info.vi_uapsd",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{&hf_ieee80211_qos_info_field_bk_uapsd,
{"AC_BK U-APSD Flag", "wlan_mgt.tag.qos_cap.qos_info.bk_uapsd",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }},
{&hf_ieee80211_qos_info_field_be_uapsd,
{"AC_BE U-APSD Flag", "wlan_mgt.tag.qos_cap.qos_info.be_uapsd",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x08, NULL, HFILL }},
{&hf_ieee80211_qos_info_field_qack,
{"Q-ACK", "wlan_mgt.tag.qos_cap.qos_info.qack",
FT_BOOLEAN, 8, TFS(&qos_info_field_qack_flags), 0x10, NULL, HFILL }},
{&hf_ieee80211_qos_info_field_max_sp_length,
{"Max SP-Lenght", "wlan_mgt.tag.qos_cap.qos_info.max_sp_length",
FT_UINT8, BASE_HEX, VALS(qos_info_field_max_sp_lenght_flags),
0x60, NULL , HFILL }},
{&hf_ieee80211_qos_info_field_more_data_ack,
{"More Data Ack", "wlan_mgt.tag.qos_cap.qos_info.more_data_ack",
FT_BOOLEAN, 8, TFS(&qos_info_field_more_data_ack_flags) , 0x80, NULL, HFILL }},
{&hf_ieee80211_qos_info_field_edca_upd_cnt,
{"EDCA Parameter Set Update Count", "wlan_mgt.tag.qos_cap.qos_info.edca_upd_cnt",
FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL}},
{&hf_ieee80211_qos_info_field_queue_req,
{"Queue Request", "wlan_mgt.tag.qos_cap.qos_info.queue_req",
FT_BOOLEAN, 8, TFS(&qos_info_field_queue_req_flags), 0x07, NULL, HFILL}},
{&hf_ieee80211_qos_info_field_txop_req,
{"TXOP Request", "wlan_mgt.tag.qos_cap.qos_info.txop_req",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x40, NULL, HFILL}},
{&hf_ieee80211_qos_info_field_reserved,
{"Reserved", "wlan_mgt.tag.qos_cap.qos_info.reserved",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}},
{&hf_ieee80211_tag_ext_supp_rates,
{"Extented Supported Rates", "wlan_mgt.extented_supported_rates",
FT_UINT8, BASE_HEX, VALS(ieee80211_supported_rates_vals), 0x0,
"In Mbit/sec, (B) for Basic Rates", HFILL }},
{&hf_ieee80211_sched_info,
{"Schedule Info", "wlan_mgt.sched.sched_info",
FT_UINT16, BASE_HEX, NULL, 0, "Schedule Info field", HFILL }},
{&hf_ieee80211_sched_info_agg,
{"Schedule Aggregation", "wlan_mgt.sched_info.agg", FT_UINT16, BASE_DEC,
NULL, 0x0001, "Traffic Stream (TS) Info Access Policy", HFILL }},
{&hf_ieee80211_sched_info_tsid,
{"Schedule Traffic Stream ID (TSID)", "wlan_mgt.sched_info.tsid",
FT_UINT16, BASE_DEC, NULL, 0x001E, "Traffic Stream ID (TSID) Info TSID", HFILL }},
{&hf_ieee80211_sched_info_dir,
{"Schedule Direction", "wlan_mgt.sched_info.dir", FT_UINT16, BASE_DEC,
VALS (&tsinfo_direction), 0x0060, "Traffic Stream (TS) Info Direction", HFILL }},
{&hf_ieee80211_sched_srv_start,
{"Service Start Time", "wlan_mgt.sched.srv_start",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_sched_srv_int,
{"Service Interval", "wlan_mgt.sched.srv_int",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_sched_spec_int,
{"Specification Interval", "wlan_mgt.sched.spec_int",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_aruba,
{"Aruba Type", "wlan_mgt.aruba.type",
FT_UINT16, BASE_DEC, VALS(aruba_mgt_typevals), 0, "Aruba Management", HFILL }},
{&hf_ieee80211_aruba_hb_seq,
{"Aruba Heartbeat Sequence", "wlan_mgt.aruba.heartbeat_sequence",
FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_aruba_mtu,
{"Aruba MTU Size", "wlan_mgt.aruba.mtu_size",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_htc,
{"HT Control (+HTC)", "wlan_mgt.htc",
FT_UINT32, BASE_HEX, NULL, 0, "High Throughput Control (+HTC)", HFILL }},
{&hf_ieee80211_htc_lac,
{"Link Adaptation Control (LAC)", "wlan_mgt.htc.lac",
FT_UINT16, BASE_HEX, NULL, 0, "High Throughput Control Link Adaptation Control (LAC)", HFILL }},
{&hf_ieee80211_htc_lac_reserved,
{"Reserved", "wlan_mgt.htc.lac.reserved",
FT_BOOLEAN, 16, NULL, 0x0001, "High Throughput Control Link Adaptation Control Reserved", HFILL }},
{&hf_ieee80211_htc_lac_trq,
{"Training Request (TRQ)", "wlan_mgt.htc.lac.trq",
FT_BOOLEAN, 16, TFS(&htc_lac_trq_flag), 0x0002, "High Throughput Control Link Adaptation Control Training Request (TRQ)", HFILL }},
{&hf_ieee80211_htc_lac_mai_aseli,
{"Antenna Selection Indication (ASELI)", "wlan_mgt.htc.lac.mai.aseli",
FT_UINT16, BASE_HEX, NULL, 0x003C, "High Throughput Control Link Adaptation Control MAI Antenna Selection Indication", HFILL }},
{&hf_ieee80211_htc_lac_mai_mrq,
{"MCS Request (MRQ)", "wlan_mgt.htc.lac.mai.mrq",
FT_BOOLEAN, 16, TFS(&htc_lac_mai_mrq_flag), 0x0004, "High Throughput Control Link Adaptation Control MAI MCS Request", HFILL }},
{&hf_ieee80211_htc_lac_mai_msi,
{"MCS Request Sequence Identifier (MSI)", "wlan_mgt.htc.lac.mai.msi",
FT_UINT16, BASE_HEX, NULL, 0x0038, "High Throughput Control Link Adaptation Control MAI MCS Request Sequence Identifier", HFILL }},
{&hf_ieee80211_htc_lac_mai_reserved,
{"Reserved", "wlan_mgt.htc.lac.mai.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0038, "High Throughput Control Link Adaptation Control MAI Reserved", HFILL }},
{&hf_ieee80211_htc_lac_mfsi,
{"MCS Feedback Sequence Identifier (MFSI)", "wlan_mgt.htc.lac.mfsi",
FT_UINT16, BASE_DEC, NULL, 0x01C0, "High Throughput Control Link Adaptation Control MCS Feedback Sequence Identifier (MSI)", HFILL }},
{&hf_ieee80211_htc_lac_asel_command,
{"Antenna Selection (ASEL) Command", "wlan_mgt.htc.lac.asel.command",
FT_UINT16, BASE_HEX, VALS (&ieee80211_htc_lac_asel_command_flags), 0x0E00, "High Throughput Control Link Adaptation Control Antenna Selection (ASEL) Command", HFILL }},
{&hf_ieee80211_htc_lac_asel_data,
{"Antenna Selection (ASEL) Data", "wlan_mgt.htc.lac.asel.data",
FT_UINT16, BASE_HEX, NULL, 0xF000, "High Throughput Control Link Adaptation Control Antenna Selection (ASEL) Data", HFILL }},
{&hf_ieee80211_htc_lac_mfb,
{"MCS Feedback (MFB)", "wlan_mgt.htc.lac.mfb",
FT_UINT16, BASE_HEX, NULL, 0xFE00, "High Throughput Control Link Adaptation Control MCS Feedback", HFILL }},
{&hf_ieee80211_htc_cal_pos,
{"Calibration Position", "wlan_mgt.htc.cal.pos",
FT_UINT16, BASE_DEC, VALS (&ieee80211_htc_cal_pos_flags), 0x0003, "High Throughput Control Calibration Position", HFILL }},
{&hf_ieee80211_htc_cal_seq,
{"Calibration Sequence Identifier", "wlan_mgt.htc.cal.seq",
FT_UINT16, BASE_DEC, NULL, 0x000C, "High Throughput Control Calibration Sequence Identifier", HFILL }},
{&hf_ieee80211_htc_reserved1,
{"Reserved", "wlan_mgt.htc.reserved1",
FT_UINT16, BASE_DEC, NULL, 0x0030, "High Throughput Control Reserved", HFILL }},
{&hf_ieee80211_htc_csi_steering,
{"CSI/Steering", "wlan_mgt.htc.csi_steering",
FT_UINT16, BASE_DEC, VALS (&ieee80211_htc_csi_steering_flags), 0x00C0, "High Throughput Control CSI/Steering", HFILL }},
{&hf_ieee80211_htc_ndp_announcement,
{"NDP Announcement", "wlan_mgt.htc.ndp_announcement",
FT_BOOLEAN, 16, TFS(&ieee80211_htc_ndp_announcement_flag), 0x0100, "High Throughput Control NDP Announcement", HFILL }},
{&hf_ieee80211_htc_reserved2,
{"Reserved", "wlan_mgt.htc.reserved2",
FT_UINT16, BASE_HEX, NULL, 0x3E00, "High Throughput Control Reserved", HFILL }},
{&hf_ieee80211_htc_ac_constraint,
{"AC Constraint", "wlan_mgt.htc.ac_constraint",
FT_BOOLEAN, 16, NULL, 0x4000, "High Throughput Control AC Constraint", HFILL }},
{&hf_ieee80211_htc_rdg_more_ppdu,
{"RDG/More PPDU", "wlan_mgt.htc.rdg_more_ppdu",
FT_BOOLEAN, 16, NULL, 0x8000, "High Throughput Control RDG/More PPDU", HFILL }},
{&hf_ieee80211_tag_mobility_domain_mdid,
{"Mobility Domain Identifier", "wlan_mgt.mobility_domain.mdid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_mobility_domain_ft_capab,
{"FT Capability and Policy", "wlan_mgt.mobility_domain.ft_capab",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_mobility_domain_ft_capab_ft_over_ds,
{"Fast BSS Transition over DS",
"wlan_mgt.mobility_domain.ft_capab.ft_over_ds",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL }},
{&hf_ieee80211_tag_mobility_domain_ft_capab_resource_req,
{"Resource Request Protocol Capability",
"wlan_mgt.mobility_domain.ft_capab.resource_req",
FT_UINT8, BASE_HEX, NULL, 0x02, NULL, HFILL }},
{&hf_ieee80211_tag_ft_mic_control,
{"MIC Control", "wlan_mgt.ft.mic_control",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_element_count,
{"Element Count", "wlan_mgt.ft.element_count",
FT_UINT16, BASE_DEC, NULL, 0xff00, NULL, HFILL }},
{&hf_ieee80211_tag_ft_mic,
{"MIC", "wlan_mgt.ft.mic",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_anonce,
{"ANonce", "wlan_mgt.ft.anonce",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_snonce,
{"SNonce", "wlan_mgt.ft.snonce",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_id,
{"Subelement ID", "wlan_mgt.ft.subelem.id",
FT_UINT8, BASE_DEC, VALS(ft_subelem_id_vals), 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_len,
{"Length", "wlan_mgt.ft.subelem.len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_data,
{"Data", "wlan_mgt.ft.subelem.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_r1kh_id,
{"PMK-R1 key holder identifier (R1KH-ID)", "wlan_mgt.ft.subelem.r1kh_id",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_gtk_key_info,
{"Key Info", "wlan_mgt.ft.subelem.gtk.key_info",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_gtk_key_id,
{"Key ID", "wlan_mgt.ft.subelem.gtk.key_id",
FT_UINT16, BASE_DEC, NULL, 0x0003, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_gtk_key_length,
{"Key Length", "wlan_mgt.ft.subelem.gtk.key_length",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_gtk_rsc,
{"RSC", "wlan_mgt.ft.subelem.gtk.rsc",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_gtk_key,
{"GTK", "wlan_mgt.ft.subelem.gtk.key",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_r0kh_id,
{"PMK-R0 key holder identifier (R0KH-ID)", "wlan_mgt.ft.subelem.r0kh_id",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_igtk_key_id,
{"Key ID", "wlan_mgt.ft.subelem.igtk.key_id",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_igtk_ipn,
{"IPN", "wlan_mgt.ft.subelem.igtk.ipn",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_igtk_key_length,
{"Key Length", "wlan_mgt.ft.subelem.igtk.key_length",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_ft_subelem_igtk_key,
{"Wrapped Key (IGTK)", "wlan_mgt.ft.subelem.igtk.key",
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
{&hf_ieee80211_tag_time_adv_timing_capab,
{"Timing capabilities", "wlan_mgt.time_adv.timing_capab",
FT_UINT8, BASE_DEC, VALS(time_adv_timing_capab_vals), 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value,
{"Time Value", "wlan_mgt.time_adv.time_value",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_year,
{"Time Value: Year", "wlan_mgt.time_adv.time_value.year",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_month,
{"Time Value: Month", "wlan_mgt.time_adv.time_value.month",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_day,
{"Time Value: Day", "wlan_mgt.time_adv.time_value.month",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_hours,
{"Time Value: Hours", "wlan_mgt.time_adv.time_value.hours",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_minutes,
{"Time Value: Minutes", "wlan_mgt.time_adv.time_value.minutes",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_seconds,
{"Time Value: Seconds", "wlan_mgt.time_adv.time_value.seconds",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_milliseconds,
{"Time Value: Milliseconds", "wlan_mgt.time_adv.time_value.milliseconds",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_value_reserved,
{"Time Value: Reserved", "wlan_mgt.time_adv.time_value.reserved",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_error,
{"Time Error", "wlan_mgt.time_adv.time_error",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_adv_time_update_counter,
{"Time Update Counter", "wlan_mgt.time_adv.time_update_counter",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_time_zone,
{"Time Zone", "wlan_mgt.time_zone",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_interworking_access_network_type,
{"Access Network Type", "wlan_mgt.interworking.access_network_type",
FT_UINT8, BASE_DEC, VALS(access_network_type_vals), 0x0f, NULL, HFILL }},
{&hf_ieee80211_tag_interworking_internet,
{"Internet", "wlan_mgt.interworking.internet",
FT_UINT8, BASE_DEC, NULL, 0x10, NULL, HFILL }},
{&hf_ieee80211_tag_interworking_asra,
{"ASRA", "wlan_mgt.interworking.asra",
FT_UINT8, BASE_DEC, NULL, 0x20, "Additional Step Required for Access",
HFILL }},
{&hf_ieee80211_tag_interworking_esr,
{"ESR", "wlan_mgt.interworking.esr",
FT_UINT8, BASE_DEC, NULL, 0x40, "Emergency services reachable", HFILL }},
{&hf_ieee80211_tag_interworking_uesa,
{"UESA", "wlan_mgt.interworking.uesa",
FT_UINT8, BASE_DEC, NULL, 0x80,
"Unauthenticated emergency service accessible", HFILL }},
{&hf_ieee80211_tag_interworking_hessid,
{"HESSID", "wlan_mgt.interworking.hessid",
FT_ETHER, BASE_NONE, NULL, 0, "Homogeneous ESS identifier", HFILL }},
{&hf_ieee80211_tag_adv_proto_resp_len_limit,
{"Query Response Length Limit", "wlan_mgt.adv_proto.resp_len_limit",
FT_UINT8, BASE_DEC, NULL, 0x7f, NULL, HFILL }},
{&hf_ieee80211_tag_adv_proto_pame_bi,
{"PAME-BI", "wlan_mgt.adv_proto.pame_bi",
FT_UINT8, BASE_DEC, NULL, 0x80,
"Pre-Association Message Xchange BSSID Independent (PAME-BI)", HFILL }},
{&hf_ieee80211_tag_adv_proto_id,
{"Advertisement Protocol ID", "wlan_mgt.adv_proto.id",
FT_UINT8, BASE_DEC, VALS(adv_proto_id_vals), 0, NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_num_anqp_oi,
{"Number of ANQP OIs", "wlan_mgt.roaming_consortium.num_anqp_oi",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_oi1_len,
{"OI #1 Length", "wlan_mgt.roaming_consortium.oi1_len",
FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_oi2_len,
{"OI #2 Length", "wlan_mgt.roaming_consortium.oi2_len",
FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_oi1,
{"OI #1", "wlan_mgt.roaming_consortium.oi1",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_oi2,
{"OI #2", "wlan_mgt.roaming_consortium.oi2",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_roaming_consortium_oi3,
{"OI #3", "wlan_mgt.roaming_consortium.oi3",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_timeout_int_type,
{"Timeout Interval Type", "wlan_mgt.timeout_int.type",
FT_UINT8, BASE_DEC, VALS(timeout_int_types), 0, NULL, HFILL }},
{&hf_ieee80211_tag_timeout_int_value,
{"Timeout Interval Value", "wlan_mgt.timeout_int.value",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_link_id_bssid,
{"BSSID", "wlan_mgt.link_id.bssid",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_link_id_init_sta,
{"TDLS initiator STA Address", "wlan_mgt.link_id.init_sta",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_link_id_resp_sta,
{"TDLS responder STA Address", "wlan_mgt.link_id.resp_sta",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_wakeup_schedule_offset,
{"Offset", "wlan_mgt.wakeup_schedule.offset",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_wakeup_schedule_interval,
{"Interval", "wlan_mgt.wakeup_schedule.interval",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_wakeup_schedule_awake_window_slots,
{"Awake Window Slots", "wlan_mgt.wakeup_schedule.awake_window_slots",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_wakeup_schedule_max_awake_dur,
{"Maximum Awake Window Duration",
"wlan_mgt.wakeup_schedule.max_awake_dur",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_wakeup_schedule_idle_count,
{"Idle Count", "wlan_mgt.wakeup_schedule.idle_count",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_channel_switch_timing_switch_time,
{"Switch Time", "wlan_mgt.channel_switch_timing.switch_time",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_channel_switch_timing_switch_timeout,
{"Switch Timeout", "wlan_mgt.channel_switch_timing.switch_timeout",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_pti_control_tid,
{"TID", "wlan_mgt.pti_control.tid",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_pti_control_sequence_control,
{"Sequence Control", "wlan_mgt.pti_control.sequence_control",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{&hf_ieee80211_tag_pu_buffer_status_ac_bk,
{"AC_BK traffic available", "wlan_mgt.pu_buffer_status.ac_bk",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL }},
{&hf_ieee80211_tag_pu_buffer_status_ac_be,
{"AC_BE traffic available", "wlan_mgt.pu_buffer_status.ac_be",
FT_UINT8, BASE_DEC, NULL, 0x02, NULL, HFILL }},
{&hf_ieee80211_tag_pu_buffer_status_ac_vi,
{"AC_VI traffic available", "wlan_mgt.pu_buffer_status.ac_vi",
FT_UINT8, BASE_DEC, NULL, 0x04, NULL, HFILL }},
{&hf_ieee80211_tag_pu_buffer_status_ac_vo,
{"AC_VO traffic available", "wlan_mgt.pu_buffer_status.ac_vo",
FT_UINT8, BASE_DEC, NULL, 0x08, NULL, HFILL }}
};
static hf_register_info aggregate_fields[] = {
{&hf_ieee80211_amsdu_msdu_header_text,
{"MAC Service Data Unit (MSDU)", "wlan_aggregate.msduheader", FT_UINT16,
BASE_DEC, 0, 0x0000, NULL, HFILL }}
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
&ett_fc_tree,
&ett_proto_flags,
&ett_fragments,
&ett_fragment,
&ett_block_ack,
&ett_block_ack_bitmap,
&ett_80211_mgt,
&ett_fixed_parameters,
&ett_tagged_parameters,
&ett_tag_bmapctl_tree,
&ett_tag_country_fnm_tree,
&ett_tag_country_rcc_tree,
&ett_qos_parameters,
&ett_qos_ps_buf_state,
&ett_qos_info_field_tree,
&ett_wep_parameters,
&ett_msh_control,
&ett_hwmp_targ_flags_tree,
&ett_cap_tree,
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
&ett_ath_cap_tree,
&ett_ff_ba_param_tree,
&ett_ff_qos_info,
&ett_ff_sm_pwr_save,
&ett_ff_psmp_param_set,
&ett_ff_mimo_cntrl,
&ett_ff_ant_sel,
&ett_ff_chan_switch_announce,
&ett_ff_ht_info,
&ett_ff_psmp_sta_info,
&ett_ff_delba_param_tree,
&ett_ff_ba_ssc_tree,
&ett_mimo_report,
&ett_cntrl_wrapper_fc,
&ett_cntrl_wrapper_payload,
&ett_ht_info_delimiter1_tree,
&ett_ht_info_delimiter2_tree,
&ett_ht_info_delimiter3_tree,
&ett_msdu_aggregation_parent_tree,
&ett_msdu_aggregation_subframe_tree,
&ett_tag_measure_request_mode_tree,
&ett_tag_measure_request_type_tree,
&ett_tag_measure_report_mode_tree,
&ett_tag_measure_report_type_tree,
&ett_tag_measure_report_basic_map_tree,
&ett_tag_measure_report_rpi_tree,
&ett_tag_measure_report_frame_tree,
&ett_tag_dfs_map_tree,
&ett_tag_erp_info_tree,
&ett_tag_ex_cap,
&ett_tag_supported_channels,
&ett_tag_neighbor_report_bssid_info_tree,
&ett_tag_neighbor_report_bssid_info_capability_tree,
&ett_tag_neighbor_report_sub_tag_tree,
&ett_ampduparam_tree,
&ett_mcsset_tree,
&ett_mcsbit_tree,
&ett_htex_cap_tree,
&ett_txbf_tree,
&ett_hta_cap_tree,
&ett_hta_cap1_tree,
&ett_hta_cap2_tree,
&ett_htc_tree,
&ett_antsel_tree,
&ett_80211_mgt_ie,
&ett_tsinfo_tree,
&ett_sched_tree,
&ett_fcs,
&ett_tag_time_adv_tree,
&ett_adv_proto,
&ett_adv_proto_tuple,
&ett_gas_query,
&ett_gas_resp_fragment,
&ett_gas_resp_fragments,
&ett_gas_anqp,
&ett_nai_realm,
&ett_nai_realm_eap,
&ett_anqp_vendor_capab
};
module_t *wlan_module;
memset (&wlan_stats, 0, sizeof wlan_stats);
proto_aggregate = proto_register_protocol("IEEE 802.11 wireless LAN aggregate frame",
"IEEE 802.11 Aggregate Data", "wlan_aggregate");
proto_register_field_array(proto_aggregate, aggregate_fields, array_length(aggregate_fields));
proto_wlan = proto_register_protocol ("IEEE 802.11 wireless LAN",
"IEEE 802.11", "wlan");
proto_register_field_array (proto_wlan, hf, array_length (hf));
proto_wlan_mgt = proto_register_protocol ("IEEE 802.11 wireless LAN management frame",
"802.11 MGT", "wlan_mgt");
proto_register_field_array (proto_wlan_mgt, ff, array_length (ff));
proto_register_subtree_array (tree_array, array_length (tree_array));
register_dissector("wlan", dissect_ieee80211, proto_wlan);
register_dissector("wlan_fixed", dissect_ieee80211_fixed, proto_wlan);
register_dissector("wlan_bsfc", dissect_ieee80211_bsfc, proto_wlan);
register_dissector("wlan_datapad", dissect_ieee80211_datapad, proto_wlan);
register_dissector("wlan_ht", dissect_ieee80211_ht, proto_wlan);
register_init_routine(wlan_defragment_init);
register_init_routine(wlan_retransmit_init);
register_init_routine(ieee80211_gas_reassembly_init);
wlan_tap = register_tap("wlan");
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
(void*) &uat_wep_key_records,
&num_wepkeys_uat,
UAT_CAT_CRYPTO,
NULL,
uat_wep_key_record_copy_cb,
uat_wep_key_record_update_cb,
uat_wep_key_record_free_cb,
NULL,
wep_uat_flds);
prefs_register_uat_preference(wlan_module,
"wep_key_table",
"Decryption Keys",
"WEP and pre-shared WPA keys",
wep_uat);
}
static void
dissect_data_encap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 type;
int tagged_parameter_tree_len;
proto_tree *tagged_tree;
g_pinfo = pinfo;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee80211_data_encap_payload_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset++;
switch (type) {
case 1:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RRB");
break;
case 2:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TDLS");
col_clear(pinfo->cinfo, COL_INFO);
offset += add_fixed_field(tree, tvb, offset, FIELD_ACTION);
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
proto_reg_handoff_ieee80211(void)
{
dissector_handle_t data_encap_handle;
llc_handle = find_dissector("llc");
ipx_handle = find_dissector("ipx");
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
data_handle = find_dissector("data");
ieee80211_handle = find_dissector("wlan");
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11, ieee80211_handle);
dissector_add_uint("ethertype", ETHERTYPE_CENTRINO_PROMISC, ieee80211_handle);
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
}
static tvbuff_t *
try_decrypt(tvbuff_t *tvb, guint offset, guint len, guint8 *algorithm, guint32 *sec_header, guint32 *sec_trailer) {
const guint8 *enc_data;
guint8 *tmp = NULL;
tvbuff_t *decr_tvb = NULL;
guint32 dec_caplen;
guchar dec_data[AIRPDCAP_MAX_CAPLEN];
AIRPDCAP_KEY_ITEM used_key;
if (!enable_decryption)
return NULL;
enc_data = tvb_get_ptr(tvb, 0, len+offset);
if (AirPDcapPacketProcess(&airpdcap_ctx, enc_data, offset, offset+len, dec_data, &dec_caplen, &used_key, FALSE, TRUE)==AIRPDCAP_RET_SUCCESS)
{
*algorithm=used_key.KeyType;
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
tmp = g_memdup(dec_data+offset, dec_caplen-offset);
len=dec_caplen-offset;
decr_tvb = tvb_new_child_real_data(tvb, tmp, len, len);
tvb_set_free_cb(decr_tvb, g_free);
} else
g_free(tmp);
return decr_tvb;
}
static
void set_airpdcap_keys(void)
{
guint i = 0;
AIRPDCAP_KEY_ITEM key;
PAIRPDCAP_KEYS_COLLECTION keys;
decryption_key_t* dk = NULL;
GByteArray *bytes = NULL;
gboolean res;
keys=(PAIRPDCAP_KEYS_COLLECTION)g_malloc(sizeof(AIRPDCAP_KEYS_COLLECTION));
keys->nKeys = 0;
for(i = 0; (uat_wep_key_records != NULL) && (i < num_wepkeys_uat) && (i < MAX_ENCRYPTION_KEYS); i++)
{
dk = parse_key_string(uat_wep_key_records[i].string, uat_wep_key_records[i].key);
if(dk != NULL)
{
if(dk->type == AIRPDCAP_KEY_TYPE_WEP)
{
key.KeyType = AIRPDCAP_KEY_TYPE_WEP;
bytes = g_byte_array_new();
res = hex_str_to_bytes(dk->key->str, bytes, FALSE);
if (dk->key->str && res && bytes->len > 0 && bytes->len <= AIRPDCAP_WEP_KEY_MAXLEN)
{
memcpy(key.KeyData.Wep.WepKey, bytes->data, bytes->len);
key.KeyData.Wep.WepKeyLen = bytes->len;
keys->Keys[keys->nKeys] = key;
keys->nKeys++;
}
}
else if(dk->type == AIRPDCAP_KEY_TYPE_WPA_PWD)
{
key.KeyType = AIRPDCAP_KEY_TYPE_WPA_PWD;
g_strlcpy(key.UserPwd.Passphrase, dk->key->str, AIRPDCAP_WPA_PASSPHRASE_MAX_LEN+1);
key.UserPwd.SsidLen = 0;
if(dk->ssid != NULL && dk->ssid->len <= AIRPDCAP_WPA_SSID_MAX_LEN)
{
memcpy(key.UserPwd.Ssid, dk->ssid->data, dk->ssid->len);
key.UserPwd.SsidLen = dk->ssid->len;
}
keys->Keys[keys->nKeys] = key;
keys->nKeys++;
}
else if(dk->type == AIRPDCAP_KEY_TYPE_WPA_PMK)
{
key.KeyType = AIRPDCAP_KEY_TYPE_WPA_PMK;
bytes = g_byte_array_new();
hex_str_to_bytes(dk->key->str, bytes, FALSE);
if (bytes->len <= AIRPDCAP_WPA_PMK_LEN) {
memcpy(key.KeyData.Wpa.Pmk, bytes->data, bytes->len);
keys->Keys[keys->nKeys] = key;
keys->nKeys++;
}
}
}
}
AirPDcapSetKeys(&airpdcap_ctx,keys->Keys,keys->nKeys);
g_free(keys);
if (bytes)
g_byte_array_free(bytes, TRUE);
}
static void init_wepkeys(void) {
set_airpdcap_keys();
}
static int
weak_iv(guchar *iv)
{
guchar sum, k;
if (iv[1] == 255 && iv[0] > 2 && iv[0] < 16) {
return iv[0] -3;
}
sum = iv[0] + iv[1];
if (sum == 1) {
if (iv[2] <= 0x0a) {
return iv[2] +2;
}
else if (iv[2] == 0xff){
return 0;
}
}
k = 0xfe - iv[2];
if (sum == k && (iv[2] >= 0xf2 && iv[2] <= 0xfe && iv[2] != 0xfd)){
return k;
}
return -1;
}
