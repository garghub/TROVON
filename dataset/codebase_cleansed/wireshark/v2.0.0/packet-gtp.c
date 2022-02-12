static void
gtpstat_init(struct register_srt* srt _U_, GArray* srt_array, srt_gui_init_cb gui_callback, void* gui_data)
{
srt_stat_table *gtp_srt_table;
gtp_srt_table = init_srt_table("GTP Requests", NULL, srt_array, 4, NULL, NULL, gui_callback, gui_data, NULL);
init_srt_table_row(gtp_srt_table, 0, "Echo");
init_srt_table_row(gtp_srt_table, 1, "Create PDP context");
init_srt_table_row(gtp_srt_table, 2, "Update PDP context");
init_srt_table_row(gtp_srt_table, 3, "Delete PDP context");
}
static int
gtpstat_packet(void *pss, packet_info *pinfo, epan_dissect_t *edt _U_, const void *prv)
{
guint i = 0;
srt_stat_table *gtp_srt_table;
srt_data_t *data = (srt_data_t *)pss;
const gtp_msg_hash_t *gtp=(const gtp_msg_hash_t *)prv;
int idx=0;
if(gtp->is_request){
return 0;
}
if(!gtp->req_frame){
return 0;
}
switch(gtp->msgtype){
case GTP_MSG_ECHO_REQ: idx=0;
break;
case GTP_MSG_CREATE_PDP_REQ: idx=1;
break;
case GTP_MSG_UPDATE_PDP_REQ: idx=2;
break;
case GTP_MSG_DELETE_PDP_REQ: idx=3;
break;
default:
return 0;
}
gtp_srt_table = g_array_index(data->srt_array, srt_stat_table*, i);
add_srt_table_data(gtp_srt_table, idx, &gtp->req_time, pinfo);
return 1;
}
static gchar *
id_to_str(tvbuff_t *tvb, gint offset)
{
static gchar str[17] = " ";
guint8 bits8to5, bits4to1;
int i, j;
guint8 ad;
for (i = j = 0; i < 8; i++) {
ad = tvb_get_guint8(tvb, offset + i);
bits8to5 = hi_nibble(ad);
bits4to1 = lo_nibble(ad);
if (bits4to1 <= 9)
str[j++] = BCD2CHAR(bits4to1);
else
str[j++] = ' ';
if (bits8to5 <= 9)
str[j++] = BCD2CHAR(bits8to5);
else
str[j++] = ' ';
}
str[j] = '\0';
return str;
}
static guint
gtp_sn_hash(gconstpointer k)
{
const gtp_msg_hash_t *key = (const gtp_msg_hash_t *)k;
return key->seq_nr;
}
static gint
gtp_sn_equal_matched(gconstpointer k1, gconstpointer k2)
{
const gtp_msg_hash_t *key1 = (const gtp_msg_hash_t *)k1;
const gtp_msg_hash_t *key2 = (const gtp_msg_hash_t *)k2;
if ( key1->req_frame && key2->req_frame && (key1->req_frame != key2->req_frame) ) {
return 0;
}
if ( key1->rep_frame && key2->rep_frame && (key1->rep_frame != key2->rep_frame) ) {
return 0;
}
return key1->seq_nr == key2->seq_nr;
}
static gint
gtp_sn_equal_unmatched(gconstpointer k1, gconstpointer k2)
{
const gtp_msg_hash_t *key1 = (const gtp_msg_hash_t *)k1;
const gtp_msg_hash_t *key2 = (const gtp_msg_hash_t *)k2;
return key1->seq_nr == key2->seq_nr;
}
static gtp_msg_hash_t *
gtp_match_response(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, gint seq_nr, guint msgtype, gtp_conv_info_t *gtp_info)
{
gtp_msg_hash_t gcr, *gcrp = NULL;
gcr.seq_nr=seq_nr;
switch (msgtype) {
case GTP_MSG_ECHO_REQ:
case GTP_MSG_CREATE_PDP_REQ:
case GTP_MSG_UPDATE_PDP_REQ:
case GTP_MSG_DELETE_PDP_REQ:
gcr.is_request=TRUE;
gcr.req_frame=pinfo->fd->num;
gcr.rep_frame=0;
break;
case GTP_MSG_ECHO_RESP:
case GTP_MSG_CREATE_PDP_RESP:
case GTP_MSG_UPDATE_PDP_RESP:
case GTP_MSG_DELETE_PDP_RESP:
gcr.is_request=FALSE;
gcr.req_frame=0;
gcr.rep_frame=pinfo->fd->num;
break;
default:
gcr.is_request=FALSE;
gcr.req_frame=0;
gcr.rep_frame=0;
break;
}
gcrp = (gtp_msg_hash_t *)g_hash_table_lookup(gtp_info->matched, &gcr);
if (gcrp) {
gcrp->is_request=gcr.is_request;
} else {
switch (msgtype) {
case GTP_MSG_ECHO_REQ:
case GTP_MSG_CREATE_PDP_REQ:
case GTP_MSG_UPDATE_PDP_REQ:
case GTP_MSG_DELETE_PDP_REQ:
gcr.seq_nr=seq_nr;
gcrp=(gtp_msg_hash_t *)g_hash_table_lookup(gtp_info->unmatched, &gcr);
if (gcrp) {
g_hash_table_remove(gtp_info->unmatched, gcrp);
}
if (!gcrp) {
gcrp = wmem_new(wmem_file_scope(), gtp_msg_hash_t);
}
gcrp->seq_nr=seq_nr;
gcrp->req_frame = pinfo->fd->num;
gcrp->req_time = pinfo->fd->abs_ts;
gcrp->rep_frame = 0;
gcrp->msgtype = msgtype;
gcrp->is_request = TRUE;
g_hash_table_insert(gtp_info->unmatched, gcrp, gcrp);
return NULL;
break;
case GTP_MSG_ECHO_RESP:
case GTP_MSG_CREATE_PDP_RESP:
case GTP_MSG_UPDATE_PDP_RESP:
case GTP_MSG_DELETE_PDP_RESP:
gcr.seq_nr=seq_nr;
gcrp=(gtp_msg_hash_t *)g_hash_table_lookup(gtp_info->unmatched, &gcr);
if (gcrp) {
if (!gcrp->rep_frame) {
g_hash_table_remove(gtp_info->unmatched, gcrp);
gcrp->rep_frame=pinfo->fd->num;
gcrp->is_request=FALSE;
g_hash_table_insert(gtp_info->matched, gcrp, gcrp);
}
}
break;
default:
break;
}
}
if (gcrp) {
proto_item *it;
if (gcrp->is_request) {
it = proto_tree_add_uint(tree, hf_gtp_response_in, tvb, 0, 0, gcrp->rep_frame);
PROTO_ITEM_SET_GENERATED(it);
} else {
nstime_t ns;
it = proto_tree_add_uint(tree, hf_gtp_response_to, tvb, 0, 0, gcrp->req_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->fd->abs_ts, &gcrp->req_time);
it = proto_tree_add_time(tree, hf_gtp_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
return gcrp;
}
static int
check_field_presence(guint8 message, guint8 field, int *position)
{
guint i = 0;
_gtp_mess_items *mess_items;
switch (gtp_version) {
case 0:
mess_items = gprs_mess_items;
break;
case 1:
mess_items = umts_mess_items;
break;
default:
return -2;
}
while (mess_items[i].code) {
if (mess_items[i].code == message) {
while (mess_items[i].fields[*position].code) {
if (mess_items[i].fields[*position].code == field) {
(*position)++;
return 0;
} else {
if (mess_items[i].fields[*position].presence == GTP_MANDATORY) {
return mess_items[i].fields[(*position)++].code;
} else {
(*position)++;
}
}
}
return -1;
}
i++;
}
return -2;
}
static int
decode_gtp_cause(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 cause;
cause = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_cause, tvb, offset, 2, cause);
return 2;
}
static int
decode_gtp_imsi(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
dissect_e212_imsi(tvb, pinfo, tree, offset+1, 8, FALSE);
return 9;
}
static int
decode_gtp_rai(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree *ext_tree_rai;
ext_tree_rai = proto_tree_add_subtree(tree, tvb, offset, 1, ett_gtp_ies[GTP_EXT_RAI], NULL,
val_to_str_ext_const(GTP_EXT_RAI, &gtp_val_ext, "Unknown message"));
dissect_e212_mcc_mnc(tvb, pinfo, ext_tree_rai, offset+1, E212_RAI, TRUE);
proto_tree_add_item(ext_tree_rai, hf_gtp_rai_lac, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_rai, hf_gtp_rai_rac, tvb, offset + 6, 1, ENC_BIG_ENDIAN);
return 7;
}
static int
decode_gtp_tlli(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint32 tlli;
tlli = tvb_get_ntohl(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_tlli, tvb, offset, 5, tlli);
return 5;
}
static int
decode_gtp_ptmsi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint32 ptmsi;
ptmsi = tvb_get_ntohl(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_ptmsi, tvb, offset, 5, ptmsi);
return 5;
}
static int
decode_qos_gprs(tvbuff_t * tvb, int offset, proto_tree * tree, const gchar * qos_str, guint8 adjust)
{
guint8 spare1, delay, reliability, peak, spare2, precedence, spare3, mean;
proto_tree *ext_tree_qos;
spare1 = tvb_get_guint8(tvb, offset) & GTP_EXT_QOS_SPARE1_MASK;
delay = tvb_get_guint8(tvb, offset) & GTP_EXT_QOS_DELAY_MASK;
reliability = tvb_get_guint8(tvb, offset) & GTP_EXT_QOS_RELIABILITY_MASK;
peak = tvb_get_guint8(tvb, offset + 1) & GTP_EXT_QOS_PEAK_MASK;
spare2 = tvb_get_guint8(tvb, offset + 1) & GTP_EXT_QOS_SPARE2_MASK;
precedence = tvb_get_guint8(tvb, offset + 1) & GTP_EXT_QOS_PRECEDENCE_MASK;
spare3 = tvb_get_guint8(tvb, offset + 2) & GTP_EXT_QOS_SPARE3_MASK;
mean = tvb_get_guint8(tvb, offset + 2) & GTP_EXT_QOS_MEAN_MASK;
ext_tree_qos = proto_tree_add_subtree_format(tree, tvb, offset - adjust, 3 + adjust, ett_gtp_qos, NULL,
"%s: delay: %u, reliability: %u, peak: %u, precedence: %u, mean: %u",
qos_str, (delay >> 3) & 0x07, reliability, (peak >> 4) & 0x0F, precedence, mean);
if (adjust != 0) {
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_spare1, tvb, offset, 1, spare1);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_delay, tvb, offset, 1, delay);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_reliability, tvb, offset, 1, reliability);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_peak, tvb, offset + 1, 1, peak);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_spare2, tvb, offset + 1, 1, spare2);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_precedence, tvb, offset + 1, 1, precedence);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_spare3, tvb, offset + 2, 1, spare3);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_mean, tvb, offset + 2, 1, mean);
}
return 3;
}
static int
decode_gtp_qos_gprs(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
return (1 + decode_qos_gprs(tvb, offset + 1, tree, "Quality of Service", 1));
}
static int
decode_gtp_reorder(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 reorder;
reorder = tvb_get_guint8(tvb, offset + 1) & 0x01;
proto_tree_add_boolean(tree, hf_gtp_reorder, tvb, offset, 2, reorder);
return 2;
}
static int
decode_gtp_auth_tri(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree *ext_tree_auth_tri;
ext_tree_auth_tri = proto_tree_add_subtree(tree, tvb, offset, 29, ett_gtp_ies[GTP_EXT_AUTH_TRI], NULL,
val_to_str_ext_const(GTP_EXT_AUTH_TRI, &gtp_val_ext, "Unknown message"));
proto_tree_add_item(ext_tree_auth_tri, hf_gtp_rand, tvb, offset + 1, 16, ENC_NA);
proto_tree_add_item(ext_tree_auth_tri, hf_gtp_sres, tvb, offset + 17, 4, ENC_NA);
proto_tree_add_item(ext_tree_auth_tri, hf_gtp_kc, tvb, offset + 21, 8, ENC_NA);
return 1 + 16 + 4 + 8;
}
static int
decode_gtp_map_cause(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 map_cause;
map_cause = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_map_cause, tvb, offset, 2, map_cause);
return 2;
}
static int
decode_gtp_ptmsi_sig(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint32 ptmsi_sig;
ptmsi_sig = tvb_get_ntoh24(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_ptmsi_sig, tvb, offset, 4, ptmsi_sig);
return 4;
}
static int
decode_gtp_ms_valid(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 ms_valid;
ms_valid = tvb_get_guint8(tvb, offset + 1) & 0x01;
proto_tree_add_boolean(tree, hf_gtp_ms_valid, tvb, offset, 2, ms_valid);
return 2;
}
static int
decode_gtp_recovery(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 recovery;
recovery = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_recovery, tvb, offset, 2, recovery);
return 2;
}
static const gchar *
dissect_radius_selection_mode(proto_tree * tree, tvbuff_t * tvb, packet_info* pinfo _U_)
{
guint8 sel_mode;
sel_mode = tvb_get_guint8(tvb, 0) - 0x30;
proto_tree_add_uint(tree, hf_gtp_sel_mode, tvb, 0, 1, sel_mode);
return val_to_str_const(sel_mode, sel_mode_type, "Unknown");
}
static int
decode_gtp_sel_mode(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree_add_item(tree, hf_gtp_sel_mode, tvb, offset, 2, ENC_BIG_ENDIAN);
return 2;
}
static int
decode_gtp_16(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 ext_flow_label;
guint32 teid_data;
switch (gtp_version) {
case 0:
ext_flow_label = tvb_get_ntohs(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_ext_flow_label, tvb, offset, 3, ext_flow_label);
return 3;
case 1:
teid_data = tvb_get_ntohl(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_teid_data, tvb, offset+1, 4, teid_data);
return 5;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_gtp_field_not_support_in_version,
tvb, offset, 1, "Flow label/TEID Data I : GTP version not supported");
return 3;
}
}
static int
decode_gtp_17(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 flow_sig;
guint32 teid_cp;
switch (gtp_version) {
case 0:
flow_sig = tvb_get_ntohs(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_flow_sig, tvb, offset, 3, flow_sig);
return 3;
case 1:
teid_cp = tvb_get_ntohl(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_teid_cp, tvb, offset, 5, teid_cp);
return 5;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_gtp_field_not_support_in_version,
tvb, offset, 1, "Flow label signalling/TEID control plane : GTP version not supported");
return 3;
}
}
static int
decode_gtp_18(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 flow_ii;
guint32 teid_ii;
proto_tree *ext_tree_flow_ii;
switch (gtp_version) {
case 0:
ext_tree_flow_ii = proto_tree_add_subtree(tree, tvb, offset, 4, ett_gtp_ies[GTP_EXT_FLOW_II], NULL,
val_to_str_ext_const(GTP_EXT_FLOW_II, &gtp_val_ext, "Unknown message"));
proto_tree_add_item(ext_tree_flow_ii, hf_gtp_nsapi, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
flow_ii = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_uint(ext_tree_flow_ii, hf_gtp_flow_ii, tvb, offset + 2, 2, flow_ii);
return 4;
case 1:
ext_tree_flow_ii = proto_tree_add_subtree(tree, tvb, offset, 6, ett_gtp_flow_ii, NULL,
val_to_str_ext_const(GTP_EXT_TEID_II, &gtpv1_val_ext, "Unknown message"));
proto_tree_add_item(ext_tree_flow_ii, hf_gtp_nsapi, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
teid_ii = tvb_get_ntohl(tvb, offset + 2);
proto_tree_add_uint(ext_tree_flow_ii, hf_gtp_teid_ii, tvb, offset + 2, 4, teid_ii);
return 6;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_gtp_field_not_support_in_version,
tvb, offset, 1, "Flow data II/TEID Data II : GTP Version not supported");
return 4;
}
}
static int
decode_gtp_19(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint8 field19;
field19 = tvb_get_guint8(tvb, offset + 1);
switch (gtp_version) {
case 0:
proto_tree_add_uint(tree, hf_gtp_ms_reason, tvb, offset, 2, field19);
break;
case 1:
proto_tree_add_boolean(tree, hf_gtp_tear_ind, tvb, offset, 2, field19 & 0x01);
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_gtp_field_not_support_in_version,
tvb, offset, 1, "Information Element Type = 19 : GTP Version not supported");
break;
}
return 2;
}
static int
decode_gtp_nsapi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 nsapi;
proto_tree *ext_tree;
proto_item *te;
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 10, ett_gtp_ies[GTP_EXT_NSAPI], &te,
val_to_str_ext_const(GTP_EXT_NSAPI, &gtp_val_ext, "Unknown message"));
nsapi = tvb_get_guint8(tvb, offset + 1) & 0x0F;
proto_tree_add_item(ext_tree, hf_gtp_nsapi, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_item_append_text(te, ": %u",nsapi);
return 2;
}
static int
decode_gtp_ranap_cause(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 ranap;
ranap = tvb_get_guint8(tvb, offset + 1);
if ((ranap > 0) && (ranap <= 64))
proto_tree_add_uint_format(tree, hf_gtp_ranap_cause, tvb, offset, 2,
ranap, "%s (Radio Network Layer Cause) : %s (%u)",
val_to_str_ext_const(GTP_EXT_RANAP_CAUSE, &gtp_val_ext, "Unknown"),
val_to_str_ext_const(ranap, &ranap_cause_type_ext, "Unknown RANAP Cause"), ranap);
if ((ranap > 64) && (ranap <= 80))
proto_tree_add_uint_format(tree, hf_gtp_ranap_cause, tvb, offset, 2,
ranap, "%s (Transport Layer Cause) : %s (%u)",
val_to_str_ext_const(GTP_EXT_RANAP_CAUSE, &gtp_val_ext, "Unknown"),
val_to_str_ext_const(ranap, &ranap_cause_type_ext, "Unknown RANAP Cause"), ranap);
if ((ranap > 80) && (ranap <= 96))
proto_tree_add_uint_format(tree, hf_gtp_ranap_cause, tvb, offset, 2,
ranap, "%s (NAS Cause) : %s (%u)",
val_to_str_ext_const(GTP_EXT_RANAP_CAUSE, &gtp_val_ext, "Unknown"),
val_to_str_ext_const(ranap, &ranap_cause_type_ext, "Unknown RANAP Cause"), ranap);
if ((ranap > 96) && (ranap <= 112))
proto_tree_add_uint_format(tree, hf_gtp_ranap_cause, tvb, offset, 2, ranap,
"%s (Protocol Cause) : %s (%u)",
val_to_str_ext_const(GTP_EXT_RANAP_CAUSE, &gtp_val_ext, "Unknown"),
val_to_str_ext_const(ranap, &ranap_cause_type_ext, "Unknown RANAP Cause"), ranap);
if ((ranap > 112) && (ranap <= 128))
proto_tree_add_uint_format(tree, hf_gtp_ranap_cause, tvb, offset, 2, ranap,
"%s (Miscellaneous Cause) : %s (%u)",
val_to_str_ext_const(GTP_EXT_RANAP_CAUSE, &gtp_val_ext, "Unknown"),
val_to_str_ext_const(ranap, &ranap_cause_type_ext, "Unknown RANAP Cause"), ranap);
if ((ranap > 128) )
proto_tree_add_uint_format(tree, hf_gtp_ranap_cause, tvb, offset, 2, ranap,
"%s (Non-standard Cause) : %s (%u)",
val_to_str_ext_const(GTP_EXT_RANAP_CAUSE, &gtp_val_ext, "Unknown"),
val_to_str_ext_const(ranap, &ranap_cause_type_ext, "Unknown RANAP Cause"), ranap);
return 2;
}
static int
decode_gtp_rab_cntxt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree *ext_tree_rab_cntxt;
ext_tree_rab_cntxt = proto_tree_add_subtree(tree, tvb, offset, 10, ett_gtp_ies[GTP_EXT_RAB_CNTXT], NULL,
val_to_str_ext_const(GTP_EXT_RAB_CNTXT, &gtp_val_ext, "Unknown message"));
proto_tree_add_item(ext_tree_rab_cntxt, hf_gtp_nsapi, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_rab_cntxt, hf_gtp_rab_gtpu_dn, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_rab_cntxt, hf_gtp_rab_gtpu_up, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_rab_cntxt, hf_gtp_rab_pdu_dn, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_rab_cntxt, hf_gtp_rab_pdu_up, tvb, offset + 8, 2, ENC_BIG_ENDIAN);
return 10;
}
static int
decode_gtp_rp_sms(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 rp_sms;
rp_sms = tvb_get_guint8(tvb, offset + 1) & 0x07;
proto_tree_add_uint(tree, hf_gtp_rp_sms, tvb, offset, 2, rp_sms);
return 2;
}
static int
decode_gtp_rp(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree *ext_tree_rp;
proto_item *te;
guint8 nsapi, rp, spare;
nsapi = tvb_get_guint8(tvb, offset + 1) & 0xF0;
spare = tvb_get_guint8(tvb, offset + 1) & 0x08;
rp = tvb_get_guint8(tvb, offset + 1) & 0x07;
te = proto_tree_add_uint_format(tree, hf_gtp_rp, tvb, offset, 2, rp, "Radio Priority for NSAPI(%u) : %u", nsapi, rp);
ext_tree_rp = proto_item_add_subtree(te, ett_gtp_rp);
proto_tree_add_uint(ext_tree_rp, hf_gtp_rp_nsapi, tvb, offset + 1, 1, nsapi);
proto_tree_add_uint(ext_tree_rp, hf_gtp_rp_spare, tvb, offset + 1, 1, spare);
proto_tree_add_uint(ext_tree_rp, hf_gtp_rp, tvb, offset + 1, 1, rp);
return 2;
}
static int
decode_gtp_pkt_flow_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree *ext_tree_pkt_flow_id;
proto_item *te;
guint8 nsapi, pkt_flow_id;
nsapi = tvb_get_guint8(tvb, offset + 1) & 0x0F;
pkt_flow_id = tvb_get_guint8(tvb, offset + 2);
te = proto_tree_add_uint_format(tree, hf_gtp_pkt_flow_id, tvb, offset, 3, pkt_flow_id, "Packet Flow ID for NSAPI(%u) : %u", nsapi, pkt_flow_id);
ext_tree_pkt_flow_id = proto_item_add_subtree(te, ett_gtp_pkt_flow_id);
proto_tree_add_item(ext_tree_pkt_flow_id, hf_gtp_nsapi, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(ext_tree_pkt_flow_id, hf_gtp_pkt_flow_id, tvb,
offset + 2, 1, pkt_flow_id, "%s : %u", val_to_str_ext_const(GTP_EXT_PKT_FLOW_ID, &gtp_val_ext, "Unknown message"), pkt_flow_id);
return 3;
}
static int
decode_gtp_chrg_char(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 chrg_char;
proto_item *te;
proto_tree *ext_tree_chrg_char;
chrg_char = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_uint(tree, hf_gtp_chrg_char, tvb, offset, 3, chrg_char);
ext_tree_chrg_char = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_CHRG_CHAR]);
proto_tree_add_uint(ext_tree_chrg_char, hf_gtp_chrg_char_s, tvb, offset + 1, 2, chrg_char);
proto_tree_add_uint(ext_tree_chrg_char, hf_gtp_chrg_char_n, tvb, offset + 1, 2, chrg_char);
proto_tree_add_uint(ext_tree_chrg_char, hf_gtp_chrg_char_p, tvb, offset + 1, 2, chrg_char);
proto_tree_add_uint(ext_tree_chrg_char, hf_gtp_chrg_char_f, tvb, offset + 1, 2, chrg_char);
proto_tree_add_uint(ext_tree_chrg_char, hf_gtp_chrg_char_h, tvb, offset + 1, 2, chrg_char);
proto_tree_add_uint(ext_tree_chrg_char, hf_gtp_chrg_char_r, tvb, offset + 1, 2, chrg_char);
return 3;
}
static int
decode_gtp_trace_ref(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 trace_ref;
trace_ref = tvb_get_ntohs(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_trace_ref, tvb, offset, 3, trace_ref);
return 3;
}
static int
decode_gtp_trace_type(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 trace_type;
trace_type = tvb_get_ntohs(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_trace_type, tvb, offset, 3, trace_type);
return 3;
}
static int
decode_gtp_ms_reason(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 reason;
reason = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_ms_reason, tvb, offset, 2, reason);
return 2;
}
static int
decode_gtp_ra_prio_lcs(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree_format(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_RA_PRIO_LCS], NULL,
"%s : ", val_to_str_ext_const(GTP_EXT_RA_PRIO_LCS, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_ra_prio_lcs, tvb, offset, 1, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_tr_comm(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 tr_command;
tr_command = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_tr_comm, tvb, offset, 2, tr_command);
return 2;
}
static int
decode_gtp_chrg_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint32 chrg_id;
chrg_id = tvb_get_ntohl(tvb, offset + 1);
proto_tree_add_uint(tree, hf_gtp_chrg_id, tvb, offset, 5, chrg_id);
return 5;
}
static int
decode_gtp_user_addr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
guint8 pdp_typ, pdp_org;
proto_tree *ext_tree_user;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
pdp_org = tvb_get_guint8(tvb, offset + 3) & 0x0F;
pdp_typ = tvb_get_guint8(tvb, offset + 4);
ext_tree_user = proto_tree_add_subtree_format(tree, tvb, offset, 3 + length,
ett_gtp_ies[GTP_EXT_USER_ADDR], &te, "%s (%s/%s)",
val_to_str_ext_const(GTP_EXT_USER_ADDR, &gtp_val_ext, "Unknown message"),
val_to_str_const(pdp_org, pdp_org_type, "Unknown PDP Organization"),
val_to_str_const(pdp_typ, pdp_type, "Unknown PDP Type"));
proto_tree_add_item(ext_tree_user, hf_gtp_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(ext_tree_user, hf_gtp_user_addr_pdp_org, tvb, offset + 3, 1, pdp_org);
proto_tree_add_uint(ext_tree_user, hf_gtp_user_addr_pdp_type, tvb, offset + 4, 1, pdp_typ);
if (length == 2) {
if ((pdp_org == 0) && (pdp_typ == 1))
proto_item_append_text(te, " (Point to Point Protocol)");
else if (pdp_typ == 2)
proto_item_append_text(te, " (Octet Stream Protocol)");
} else if (length > 2) {
switch (pdp_typ) {
case 0x21:
proto_tree_add_item(ext_tree_user, hf_gtp_user_ipv4, tvb, offset + 5, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, " : %s", tvb_ip_to_str(tvb, offset + 5));
break;
case 0x57:
proto_tree_add_item(ext_tree_user, hf_gtp_user_ipv6, tvb, offset + 5, 16, ENC_NA);
proto_item_append_text(te, " : %s", tvb_ip6_to_str(tvb, offset + 5));
break;
case 0x8d:
proto_tree_add_item(ext_tree_user, hf_gtp_user_ipv4, tvb, offset + 5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_user, hf_gtp_user_ipv6, tvb, offset + 9, 16, ENC_NA);
proto_item_append_text(te, " : %s / %s", tvb_ip_to_str(tvb, offset + 5),
tvb_ip6_to_str(tvb, offset + 9));
break;
}
} else
proto_item_append_text(te, " : empty PDP Address");
return 3 + length;
}
static int
decode_triplet(tvbuff_t * tvb, int offset, proto_tree * tree, guint16 count)
{
proto_tree *ext_tree_trip;
guint16 i;
for (i = 0; i < count; i++) {
ext_tree_trip = proto_tree_add_subtree_format(tree, tvb, offset + i * 28, 28, ett_gtp_trip, NULL, "Triplet no%x", i);
proto_tree_add_item(ext_tree_trip, hf_gtp_rand, tvb, offset + i * 28, 16, ENC_NA);
proto_tree_add_item(ext_tree_trip, hf_gtp_sres, tvb, offset + i * 28 + 16, 4, ENC_NA);
proto_tree_add_item(ext_tree_trip, hf_gtp_kc, tvb, offset + i * 28 + 20, 8, ENC_NA);
}
return count * 28;
}
static int
decode_quintuplet(tvbuff_t * tvb, int offset, proto_tree * tree, guint16 count)
{
proto_tree *ext_tree_quint;
proto_item *te_quint;
guint16 q_offset, i;
guint8 xres_len, auth_len;
q_offset = 0;
for (i = 0; i < count; i++) {
ext_tree_quint = proto_tree_add_subtree_format(tree, tvb, offset, -1,
ett_gtp_quint, &te_quint, "Quintuplet #%x", i + 1);
proto_tree_add_item(ext_tree_quint, hf_gtp_rand, tvb, offset + q_offset, 16, ENC_NA);
q_offset = q_offset + 16;
xres_len = tvb_get_guint8(tvb, offset + q_offset);
proto_tree_add_item(ext_tree_quint, hf_gtp_xres_length, tvb, offset + q_offset, 1, ENC_BIG_ENDIAN);
q_offset++;
proto_tree_add_item(ext_tree_quint, hf_gtp_xres, tvb, offset + q_offset, xres_len, ENC_NA);
q_offset = q_offset + xres_len;
proto_tree_add_item(ext_tree_quint, hf_gtp_quintuplet_ciphering_key, tvb, offset + q_offset, 16, ENC_NA);
q_offset = q_offset + 16;
proto_tree_add_item(ext_tree_quint, hf_gtp_quintuplet_integrity_key, tvb, offset + q_offset, 16, ENC_NA);
q_offset = q_offset + 16;
auth_len = tvb_get_guint8(tvb, offset + q_offset);
proto_tree_add_item(ext_tree_quint, hf_gtp_authentication_length, tvb, offset + q_offset, 1, ENC_BIG_ENDIAN);
q_offset++;
proto_tree_add_item(ext_tree_quint, hf_gtp_auth, tvb, offset + q_offset, auth_len, ENC_NA);
q_offset = q_offset + auth_len;
proto_item_set_end(te_quint, tvb, offset + q_offset);
}
return q_offset;
}
static int
decode_gtp_mm_cntxt(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length, con_len;
guint8 count, sec_mode, len, iei;
proto_tree *ext_tree_mm;
proto_tree *tf_tree = NULL, *con_tree;
ext_tree_mm = proto_tree_add_subtree(tree, tvb, offset, 1, ett_gtp_ies[GTP_EXT_MM_CNTXT], NULL,
val_to_str_ext_const(GTP_EXT_MM_CNTXT, &gtp_val_ext, "Unknown message"));
length = tvb_get_ntohs(tvb, offset + 1);
if (length < 1)
return 3;
sec_mode = (tvb_get_guint8(tvb, offset + 4) >> 6) & 0x03;
count = (tvb_get_guint8(tvb, offset + 4) >> 3) & 0x07;
proto_tree_add_item(ext_tree_mm, hf_gtp_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
if (gtp_version == 0)
sec_mode = 1;
switch (sec_mode) {
case 0:
proto_tree_add_item(ext_tree_mm, hf_gtp_cksn_ksi, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_security_mode, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_no_of_vectors, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_cipher_algorithm, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_ciphering_key_ck, tvb, offset + 5, 16, ENC_NA);
proto_tree_add_item(ext_tree_mm, hf_gtp_integrity_key_ik, tvb, offset + 21, 16, ENC_NA);
proto_tree_add_item(ext_tree_mm, hf_gtp_quintuplets_length, tvb, offset + 37, 2, ENC_BIG_ENDIAN);
offset = offset + decode_quintuplet(tvb, offset + 39, ext_tree_mm, count) + 39;
break;
case 1:
proto_tree_add_item(ext_tree_mm, hf_gtp_cksn, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
if (gtp_version != 0)
proto_tree_add_item(ext_tree_mm, hf_gtp_security_mode, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_no_of_vectors, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_cipher_algorithm, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_ciphering_key_kc, tvb, offset + 5, 8, ENC_NA);
offset = offset + decode_triplet(tvb, offset + 13, ext_tree_mm, count) + 13;
break;
case 2:
proto_tree_add_item(ext_tree_mm, hf_gtp_ksi, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_security_mode, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_no_of_vectors, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_ciphering_key_ck, tvb, offset + 5, 16, ENC_NA);
proto_tree_add_item(ext_tree_mm, hf_gtp_integrity_key_ik, tvb, offset + 21, 16, ENC_NA);
proto_tree_add_item(ext_tree_mm, hf_gtp_quintuplets_length, tvb, offset + 37, 2, ENC_BIG_ENDIAN);
offset = offset + decode_quintuplet(tvb, offset + 39, ext_tree_mm, count) + 39;
break;
case 3:
proto_tree_add_item(ext_tree_mm, hf_gtp_cksn, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_security_mode, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_no_of_vectors, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_cipher_algorithm, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_ciphering_key_kc, tvb, offset + 5, 8, ENC_NA);
proto_tree_add_item(ext_tree_mm, hf_gtp_quintuplets_length, tvb, offset + 13, 2, ENC_BIG_ENDIAN);
offset = offset + decode_quintuplet(tvb, offset + 15, ext_tree_mm, count) + 15;
break;
default:
break;
}
tf_tree = proto_tree_add_subtree(ext_tree_mm, tvb, offset, 2, ett_gtp_drx, NULL, "DRX Parameter");
de_gmm_drx_param(tvb, tf_tree, pinfo, offset, 2, NULL, 0);
offset = offset + 2;
len = tvb_get_guint8(tvb, offset);
tf_tree = proto_tree_add_subtree(ext_tree_mm, tvb, offset, len + 1, ett_gtp_net_cap, NULL, "MS Network Capability");
proto_tree_add_uint(tf_tree, hf_gtp_ms_network_cap_content_len, tvb, offset, 1, len);
offset++;
de_gmm_ms_net_cap(tvb, tf_tree, pinfo, offset, len, NULL, 0);
offset = offset + len;
con_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ext_tree_mm, hf_gtp_container_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
if (con_len > 0) {
proto_item* ti;
con_tree = proto_tree_add_subtree(ext_tree_mm, tvb, offset, con_len, ett_gtp_mm_cntxt, NULL, "Container");
iei = tvb_get_guint8(tvb,offset);
ti = proto_tree_add_uint(con_tree, hf_gtp_iei, tvb, offset, 1, iei);
if (iei == 0x23) {
proto_item_append_text(ti, " (Mobile identity)");
offset++;
len = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(con_tree, hf_gtp_iei_mobile_id_len, tvb, offset, 1, len);
offset++;
de_mid(tvb, con_tree, pinfo, offset, len, NULL, 0);
} else {
expert_add_info(pinfo, ti, &ei_gtp_iei);
}
}
return 3 + length;
}
static guint8
hex2dec(guint8 x)
{
if ((x >= 'a') && (x <= 'f'))
x = x - 'a' + 10;
else if ((x >= 'A') && (x <= 'F'))
x = x - 'A' + 10;
else if ((x >= '0') && (x <= '9'))
x = x - '0';
else
x = 0;
return x;
}
static guint8
wrapped_tvb_get_guint8(tvbuff_t * tvb, int offset, int type)
{
if (type == 2)
return (hex2dec(tvb_get_guint8(tvb, offset)) << 4 | hex2dec(tvb_get_guint8(tvb, offset + 1)));
else
return tvb_get_guint8(tvb, offset);
}
static int
decode_qos_umts(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree, const gchar * qos_str, guint8 type)
{
guint length;
guint8 al_ret_priority;
guint8 delay, reliability, peak, precedence, mean, spare1, spare2, spare3;
guint8 traf_class, del_order, del_err_sdu;
guint8 max_sdu_size, max_ul, max_dl, max_ul_ext, max_dl_ext, max_ul_ext2 = 0, max_dl_ext2 = 0;
guint8 res_ber, sdu_err_ratio;
guint8 trans_delay, traf_handl_prio;
guint8 guar_ul, guar_dl, guar_ul_ext, guar_dl_ext, guar_ul_ext2 = 0, guar_dl_ext2 = 0;
guint8 src_stat_desc, sig_ind;
proto_tree *ext_tree_qos;
int mss, mu, md, gu, gd;
guint8 arp, qci;
guint32 apn_ambr;
guint64 br;
guint8 utf8_type = 1;
guint8 rel_ind = 0;
guint8 hyphen;
int retval = 0;
switch (type) {
case 1:
length = tvb_get_guint8(tvb, offset);
ext_tree_qos = proto_tree_add_subtree(tree, tvb, offset, length + 1, ett_gtp_qos, NULL, qos_str);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_umts_length, tvb, offset, 1, length);
offset++;
retval = length + 1;
break;
case 2:
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_qos = proto_tree_add_subtree(tree, tvb, offset, length + 3, ett_gtp_qos, NULL, qos_str);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_umts_length, tvb, offset + 1, 2, length);
offset += 3;
retval = length + 3;
break;
case 3:
utf8_type = 2;
length = tvb_reported_length(tvb);
ext_tree_qos = proto_tree_add_subtree(tree, tvb, offset, length, ett_gtp_qos, NULL, qos_str);
rel_ind = wrapped_tvb_get_guint8(tvb, offset, 2);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_version, tvb, offset, 2, rel_ind);
hyphen = tvb_get_guint8(tvb, offset + 2);
if (hyphen == ((guint8) '-')) {
proto_tree_add_item(ext_tree_qos, hf_gtp_hyphen_separator, tvb, offset + 2, 1, ENC_NA);
offset++;
}
offset++;
length -= offset;
length /= 2;
length = retval = length + 2;
break;
default:
length = 0;
retval = 0;
ext_tree_qos = NULL;
break;
}
if ((type == 3) && (rel_ind == 8)) {
static const int * arp_flags[] = {
&hf_gtp_qos_arp_pci,
&hf_gtp_qos_arp_pl,
&hf_gtp_qos_arp_pvi,
NULL
};
offset++;
arp = wrapped_tvb_get_guint8(tvb, offset, 2);
proto_tree_add_bitmask_value_with_flags(ext_tree_qos, tvb, offset, hf_gtp_qos_arp,
ett_gtp_qos_arp, arp_flags, arp, BMT_NO_APPEND);
offset += 2;
qci = wrapped_tvb_get_guint8(tvb, offset, 2);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_qci, tvb, offset, 2, qci);
offset += 2;
if (qci <= 4) {
br = ((guint64)wrapped_tvb_get_guint8(tvb, offset , 2) << 32) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+2, 2) << 24) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+4, 2) << 16) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+6, 2) << 8) |
(guint64)wrapped_tvb_get_guint8(tvb, offset+8, 2);
proto_tree_add_uint64(ext_tree_qos, hf_gtp_qos_ul_mbr, tvb, offset, 10, br);
offset += 10;
br = ((guint64)wrapped_tvb_get_guint8(tvb, offset , 2) << 32) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+2, 2) << 24) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+4, 2) << 16) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+6, 2) << 8) |
(guint64)wrapped_tvb_get_guint8(tvb, offset+8, 2);
proto_tree_add_uint64(ext_tree_qos, hf_gtp_qos_dl_mbr, tvb, offset, 10, br);
offset += 10;
br = ((guint64)wrapped_tvb_get_guint8(tvb, offset , 2) << 32) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+2, 2) << 24) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+4, 2) << 16) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+6, 2) << 8) |
(guint64)wrapped_tvb_get_guint8(tvb, offset+8, 2);
proto_tree_add_uint64(ext_tree_qos, hf_gtp_qos_ul_gbr, tvb, offset, 10, br);
offset += 10;
br = ((guint64)wrapped_tvb_get_guint8(tvb, offset , 2) << 32) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+2, 2) << 24) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+4, 2) << 16) |
((guint64)wrapped_tvb_get_guint8(tvb, offset+6, 2) << 8) |
(guint64)wrapped_tvb_get_guint8(tvb, offset+8, 2);
proto_tree_add_uint64(ext_tree_qos, hf_gtp_qos_dl_gbr, tvb, offset, 10, br);
} else {
apn_ambr = (wrapped_tvb_get_guint8(tvb, offset , 2) << 24) |
(wrapped_tvb_get_guint8(tvb, offset+2, 2) << 16) |
(wrapped_tvb_get_guint8(tvb, offset+4, 2) << 8) |
wrapped_tvb_get_guint8(tvb, offset+6, 2);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_ul_apn_ambr, tvb, offset, 8, apn_ambr);
offset += 8;
apn_ambr = (wrapped_tvb_get_guint8(tvb, offset , 2) << 24) |
(wrapped_tvb_get_guint8(tvb, offset+2, 2) << 16) |
(wrapped_tvb_get_guint8(tvb, offset+4, 2) << 8) |
wrapped_tvb_get_guint8(tvb, offset+6, 2);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_dl_apn_ambr, tvb, offset, 8, apn_ambr);
}
return retval;
}
al_ret_priority = tvb_get_guint8(tvb, offset);
spare1 = wrapped_tvb_get_guint8(tvb, offset + (1 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_SPARE1_MASK;
delay = wrapped_tvb_get_guint8(tvb, offset + (1 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_DELAY_MASK;
reliability = wrapped_tvb_get_guint8(tvb, offset + (1 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_RELIABILITY_MASK;
peak = wrapped_tvb_get_guint8(tvb, offset + (2 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_PEAK_MASK;
spare2 = wrapped_tvb_get_guint8(tvb, offset + (2 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_SPARE2_MASK;
precedence = wrapped_tvb_get_guint8(tvb, offset + (2 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_PRECEDENCE_MASK;
spare3 = wrapped_tvb_get_guint8(tvb, offset + (3 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_SPARE3_MASK;
mean = wrapped_tvb_get_guint8(tvb, offset + (3 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_MEAN_MASK;
if (type != 3)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_al_ret_priority, tvb, offset, 1, al_ret_priority);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_spare1, tvb, offset + (1 - 1) * utf8_type + 1, utf8_type, spare1);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_delay, tvb, offset + (1 - 1) * utf8_type + 1, utf8_type, delay);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_reliability, tvb, offset + (1 - 1) * utf8_type + 1, utf8_type, reliability);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_peak, tvb, offset + (2 - 1) * utf8_type + 1, utf8_type, peak);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_spare2, tvb, offset + (2 - 1) * utf8_type + 1, utf8_type, spare2);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_precedence, tvb, offset + (2 - 1) * utf8_type + 1, utf8_type, precedence);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_spare3, tvb, offset + (3 - 1) * utf8_type + 1, utf8_type, spare3);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_mean, tvb, offset + (3 - 1) * utf8_type + 1, utf8_type, mean);
if (length > 4) {
traf_class = wrapped_tvb_get_guint8(tvb, offset + (4 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_TRAF_CLASS_MASK;
del_order = wrapped_tvb_get_guint8(tvb, offset + (4 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_DEL_ORDER_MASK;
del_err_sdu = wrapped_tvb_get_guint8(tvb, offset + (4 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_DEL_ERR_SDU_MASK;
max_sdu_size = wrapped_tvb_get_guint8(tvb, offset + (5 - 1) * utf8_type + 1, utf8_type);
max_ul = wrapped_tvb_get_guint8(tvb, offset + (6 - 1) * utf8_type + 1, utf8_type);
max_dl = wrapped_tvb_get_guint8(tvb, offset + (7 - 1) * utf8_type + 1, utf8_type);
res_ber = wrapped_tvb_get_guint8(tvb, offset + (8 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_RES_BER_MASK;
sdu_err_ratio = wrapped_tvb_get_guint8(tvb, offset + (8 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_SDU_ERR_RATIO_MASK;
trans_delay = wrapped_tvb_get_guint8(tvb, offset + (9 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_TRANS_DELAY_MASK;
traf_handl_prio = wrapped_tvb_get_guint8(tvb, offset + (9 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_TRAF_HANDL_PRIORITY_MASK;
guar_ul = wrapped_tvb_get_guint8(tvb, offset + (10 - 1) * utf8_type + 1, utf8_type);
guar_dl = wrapped_tvb_get_guint8(tvb, offset + (11 - 1) * utf8_type + 1, utf8_type);
src_stat_desc = 0;
sig_ind = 0;
max_dl_ext = 0;
guar_dl_ext = 0;
max_ul_ext = 0;
guar_ul_ext = 0;
if (length > 13 ||((type == 2) && (length == 13))) {
src_stat_desc = wrapped_tvb_get_guint8(tvb, offset + (12 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_SRC_STAT_DESC_MASK;
sig_ind = wrapped_tvb_get_guint8(tvb, offset + (12 - 1) * utf8_type + 1, utf8_type) & GTP_EXT_QOS_SIG_IND_MASK;
}
if (length > 14) {
max_dl_ext = wrapped_tvb_get_guint8(tvb, offset + (13 - 1) * utf8_type + 1, utf8_type);
guar_dl_ext = wrapped_tvb_get_guint8(tvb, offset + (14 - 1) * utf8_type + 1, utf8_type);
}
if (length > 16) {
max_ul_ext = wrapped_tvb_get_guint8(tvb, offset + (15 - 1) * utf8_type + 1, utf8_type);
guar_ul_ext = wrapped_tvb_get_guint8(tvb, offset + (16 - 1) * utf8_type + 1, utf8_type);
}
if (length > 18) {
max_dl_ext2 = wrapped_tvb_get_guint8(tvb, offset + (17 - 1) * utf8_type + 1, utf8_type);
guar_dl_ext2 = wrapped_tvb_get_guint8(tvb, offset + (18 - 1) * utf8_type + 1, utf8_type);
}
if (length > 20) {
max_ul_ext2 = wrapped_tvb_get_guint8(tvb, offset + (19 - 1) * utf8_type + 1, utf8_type);
guar_ul_ext2 = wrapped_tvb_get_guint8(tvb, offset + (20 - 1) * utf8_type + 1, utf8_type);
}
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_traf_class, tvb, offset + (4 - 1) * utf8_type + 1, utf8_type, traf_class);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_del_order, tvb, offset + (4 - 1) * utf8_type + 1, utf8_type, del_order);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_del_err_sdu, tvb, offset + (4 - 1) * utf8_type + 1, utf8_type, del_err_sdu);
if (max_sdu_size == 0 || max_sdu_size > 150)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_max_sdu_size, tvb, offset + (5 - 1) * utf8_type + 1, utf8_type, max_sdu_size);
if ((max_sdu_size > 0) && (max_sdu_size <= 150)) {
mss = max_sdu_size * 10;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_max_sdu_size, tvb, offset + (5 - 1) * utf8_type + 1, utf8_type, mss,
"%u octets", mss);
}
if (max_ul == 0 || max_ul == 255)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (6 - 1) * utf8_type + 1, utf8_type, max_ul);
if ((max_ul > 0) && (max_ul <= 63))
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (6 - 1) * utf8_type + 1, utf8_type, max_ul,
"%u kbps", max_ul);
if ((max_ul > 63) && (max_ul <= 127)) {
mu = 64 + (max_ul - 64) * 8;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (6 - 1) * utf8_type + 1, utf8_type, mu,
"%u kbps", mu);
}
if ((max_ul > 127) && (max_ul <= 254)) {
mu = 576 + (max_ul - 128) * 64;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (6 - 1) * utf8_type + 1, utf8_type, mu,
"%u kbps", mu);
}
if (max_dl == 0 || max_dl == 255)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (7 - 1) * utf8_type + 1, utf8_type, max_dl);
if ((max_dl > 0) && (max_dl <= 63))
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (7 - 1) * utf8_type + 1, utf8_type, max_dl,
"%u kbps", max_dl);
if ((max_dl > 63) && (max_dl <= 127)) {
md = 64 + (max_dl - 64) * 8;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (7 - 1) * utf8_type + 1, utf8_type, md,
"%u kbps", md);
}
if ((max_dl > 127) && (max_dl <= 254)) {
md = 576 + (max_dl - 128) * 64;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (7 - 1) * utf8_type + 1, utf8_type, md,
"%u kbps", md);
}
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_res_ber, tvb, offset + (8 - 1) * utf8_type + 1, utf8_type, res_ber);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_sdu_err_ratio, tvb, offset + (8 - 1) * utf8_type + 1, utf8_type, sdu_err_ratio);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_trans_delay, tvb, offset + (9 - 1) * utf8_type + 1, utf8_type, trans_delay);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_traf_handl_prio, tvb, offset + (9 - 1) * utf8_type + 1, utf8_type, traf_handl_prio);
if (guar_ul == 0 || guar_ul == 255)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (10 - 1) * utf8_type + 1, utf8_type, guar_ul);
if ((guar_ul > 0) && (guar_ul <= 63))
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (10 - 1) * utf8_type + 1, utf8_type, guar_ul,
"%u kbps", guar_ul);
if ((guar_ul > 63) && (guar_ul <= 127)) {
gu = 64 + (guar_ul - 64) * 8;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (10 - 1) * utf8_type + 1, utf8_type, gu,
"%u kbps", gu);
}
if ((guar_ul > 127) && (guar_ul <= 254)) {
gu = 576 + (guar_ul - 128) * 64;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (10 - 1) * utf8_type + 1, utf8_type, gu,
"%u kbps", gu);
}
if (guar_dl == 0 || guar_dl == 255)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (11 - 1) * utf8_type + 1, utf8_type, guar_dl);
if ((guar_dl > 0) && (guar_dl <= 63))
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (11 - 1) * utf8_type + 1, utf8_type, guar_dl,
"%u kbps", guar_dl);
if ((guar_dl > 63) && (guar_dl <= 127)) {
gd = 64 + (guar_dl - 64) * 8;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (11 - 1) * utf8_type + 1, utf8_type, gd,
"%u kbps", gd);
}
if ((guar_dl > 127) && (guar_dl <= 254)) {
gd = 576 + (guar_dl - 128) * 64;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (11 - 1) * utf8_type + 1, utf8_type, gd,
"%u kbps", gd);
}
if(length > 13 ||((type == 2) && (length == 13))) {
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_src_stat_desc, tvb, offset + (12 - 1) * utf8_type + 1, utf8_type, src_stat_desc);
proto_tree_add_boolean(ext_tree_qos, hf_gtp_qos_sig_ind, tvb, offset + (12 - 1) * utf8_type + 1, utf8_type, sig_ind);
}
if(length > 14) {
if ((max_dl_ext > 0) && (max_dl_ext <= 0x4a)) {
md = 8600 + max_dl_ext * 100;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (13 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for downlink: %u kbps", md);
}
if ((max_dl_ext > 0x4a) && (max_dl_ext <= 0xba)) {
md = 16 + (max_dl_ext-0x4a);
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (13 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for downlink: %u Mbps", md);
}
if ((max_dl_ext > 0xba) && (max_dl_ext <= 0xfa)) {
md = 128 + (max_dl_ext-0xba)*2;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (13 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for downlink: %u Mbps", md);
}
if(guar_dl_ext == 0)
proto_tree_add_expert_format(ext_tree_qos, pinfo, &ei_gtp_guaranteed_bit_rate_value, tvb, offset + (14 - 1) * utf8_type + 1, utf8_type,
"Use the value indicated by the Guaranteed bit rate for downlink in octet 13");
if ((guar_dl_ext > 0) && (guar_dl_ext <= 0x4a)) {
gd = 8600 + guar_dl_ext * 100;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (14 - 1) * utf8_type + 1, utf8_type, gd,
"%u kbps", gd);
}
if ((guar_dl_ext > 0x4a) && (max_dl_ext <= 0xba)) {
gd = 16 + (guar_dl_ext-0x4a);
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (14 - 1) * utf8_type + 1, utf8_type, gd,
"%u Mbps", gd);
}
if ((guar_dl_ext > 0xba) && (max_dl_ext <= 0xfa)) {
gd = 128 + (guar_dl_ext-0xba)*2;
proto_tree_add_uint_format_value(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (14 - 1) * utf8_type + 1, utf8_type, gd,
"%u Mbps", gd);
}
}
if(length > 16) {
if ((max_ul_ext > 0) && (max_ul_ext <= 0x4a)) {
md = 8600 + max_ul_ext * 100;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (15 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for uplink: %u kbps", md);
}
if ((max_ul_ext > 0x4a) && (max_ul_ext <= 0xba)) {
md = 16 + (max_ul_ext-0x4a);
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (15 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for uplink: %u Mbps", md);
}
if ((max_ul_ext > 0xba) && (max_ul_ext <= 0xfa)) {
md = 128 + (max_ul_ext-0xba)*2;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (15 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for uplink: %u Mbps", md);
}
if (guar_ul_ext == 0)
proto_tree_add_expert_format(ext_tree_qos, pinfo, &ei_gtp_guaranteed_bit_rate_value, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type,
"Use the value indicated by the Guaranteed bit rate for uplink in octet 12");
if ((guar_ul_ext > 0) && (guar_ul_ext <= 0x4a)) {
gd = 8600 + guar_ul_ext * 100;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for uplink: %u kbps", gd);
}
if ((guar_ul_ext > 0x4a) && (guar_ul_ext <= 0xba)) {
gd = 16 + (guar_ul_ext-0x4a);
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for uplink: %u Mbps", gd);
}
if ((guar_ul_ext > 0xba) && (guar_ul_ext <= 0xfa)) {
gd = 128 + (guar_ul_ext-0xba)*2;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for uplink: %u Mbps", gd);
}
}
if(length > 18) {
if (guar_dl_ext2 == 0)
proto_tree_add_expert_format(ext_tree_qos, pinfo, &ei_gtp_max_bit_rate_value, tvb, offset + (17 - 1) * utf8_type + 1, utf8_type,
"Use the value indicated by the Maximum bit rate for downlink in octet 9 and octet 15.");
if ((max_dl_ext2 > 0) && (max_dl_ext2 <= 0x3d)) {
md = 256 + max_dl_ext2 * 4;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (15 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for downlink: %u Mbps", md);
}
if ((max_dl_ext2 > 0x3d) && (max_dl_ext2 <= 0xa1)) {
md = 500 + (max_dl_ext2-0x3d) * 10;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (15 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for downlink: %u Mbps", md);
}
if ((max_dl_ext2 > 0xa1) && (max_dl_ext2 <= 0xf6)) {
md = 1500 + (max_dl_ext2-0xa1)*10;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (15 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for downlink: %u Mbps", md);
}
if (max_dl_ext2 == 0)
proto_tree_add_expert_format(ext_tree_qos, pinfo, &ei_gtp_max_bit_rate_value, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type,
"Use the value indicated by the Maximum bit rate for downlink in octet 13 and octet 16.");
if ((max_dl_ext2 > 0) && (max_dl_ext2 <= 0x3d)) {
gd = 256 + max_dl_ext2 * 4;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for downlink: %u Mbps", gd);
}
if ((max_dl_ext2 > 0x3d) && (max_dl_ext2 <= 0xa1)) {
gd = 500 + (max_dl_ext2-0x3d) * 10;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for downlink: %u Mbps", gd);
}
if ((max_dl_ext2 > 0xba) && (max_dl_ext2 <= 0xfa)) {
gd = 1500 + (max_dl_ext2-0xa1) * 10;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for uplink: %u Mbps", gd);
}
}
if(length > 20) {
if (guar_ul_ext2 == 0)
proto_tree_add_expert_format(ext_tree_qos, pinfo, &ei_gtp_max_bit_rate_value, tvb, offset + (17 - 1) * utf8_type + 1, utf8_type,
"Use the value indicated by the Maximum bit rate for uplink in octet 9 and octet 15.");
if ((max_ul_ext2 > 0) && (max_ul_ext2 <= 0x3d)) {
md = 256 + max_ul_ext2 * 4;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (15 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for uplink: %u Mbps", md);
}
if ((max_ul_ext2 > 0x3d) && (max_ul_ext2 <= 0xa1)) {
md = 500 + (max_ul_ext2-0x3d) * 10;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (15 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for uplink: %u Mbps", md);
}
if ((max_ul_ext2 > 0xa1) && (max_ul_ext2 <= 0xf6)) {
md = 1500 + (max_ul_ext2-0xa1)*10;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (15 - 1) * utf8_type + 1, utf8_type, md,
"Ext Maximum bit rate for uplink: %u Mbps", md);
}
if (max_ul_ext2 == 0)
proto_tree_add_expert_format(ext_tree_qos, pinfo, &ei_gtp_max_bit_rate_value, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type,
"Use the value indicated by the Maximum bit rate for uplink in octet 13 and octet 16.");
if ((max_ul_ext2 > 0) && (max_ul_ext2 <= 0x3d)) {
gd = 256 + max_ul_ext2 * 4;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for uplink: %u Mbps", gd);
}
if ((max_ul_ext2 > 0x3d) && (max_ul_ext2 <= 0xa1)) {
gd = 500 + (max_ul_ext2-0x3d) * 10;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for uplink: %u Mbps", gd);
}
if ((max_ul_ext2 > 0xba) && (max_ul_ext2 <= 0xfa)) {
gd = 1500 + (max_ul_ext2-0xa1) * 10;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for uplink: %u Mbps", gd);
}
}
}
return retval;
}
static int
dissect_diameter_3gpp_qosprofile(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
decode_qos_umts(tvb, 0, pinfo, tree, "UMTS GTP QoS Profile", 3);
return tvb_reported_length(tvb);
}
static const gchar *
dissect_radius_qos_umts(proto_tree * tree, tvbuff_t * tvb, packet_info* pinfo)
{
decode_qos_umts(tvb, 0, pinfo, tree, "UMTS GTP QoS Profile", 3);
return tvb_get_string_enc(wmem_packet_scope(), tvb, 0, tvb_reported_length(tvb), ENC_UTF_8|ENC_NA);
}
static void
decode_apn(tvbuff_t * tvb, int offset, guint16 length, proto_tree * tree, proto_item *item)
{
guint8 str[MAX_APN_LENGTH+1];
guint curr_len;
memset(str, 0, MAX_APN_LENGTH+1);
tvb_memcpy(tvb, str, offset, length<MAX_APN_LENGTH?length:MAX_APN_LENGTH);
curr_len = 0;
while ((curr_len < length) && (curr_len < MAX_APN_LENGTH))
{
guint step = str[curr_len];
str[curr_len] = '.';
curr_len += step+1;
}
proto_tree_add_string(tree, hf_gtp_apn, tvb, offset, length, str+1);
if(item){
proto_item_append_text(item, ": %s", str+1);
}
}
static void
decode_fqdn(tvbuff_t * tvb, int offset, guint16 length, proto_tree * tree)
{
guint8 *fqdn = NULL;
int name_len, tmp;
if (length > 0) {
name_len = tvb_get_guint8(tvb, offset);
if (name_len < 0x20) {
fqdn = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 1, length - 1, ENC_ASCII);
for (;;) {
if (name_len >= length - 1)
break;
tmp = name_len;
name_len = name_len + fqdn[tmp] + 1;
fqdn[tmp] = '.';
}
} else
fqdn = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_ASCII);
proto_tree_add_string(tree, hf_gtp_fqdn, tvb, offset, length, fqdn);
}
}
static int
decode_gtp_pdp_cntxt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 ggsn_addr_len, apn_len, trans_id, ea;
guint8 pdp_type_num, pdp_addr_len;
guint16 length;
proto_tree *ext_tree_pdp;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_pdp = proto_tree_add_subtree(tree, tvb, offset, length + 3, ett_gtp_ies[GTP_EXT_PDP_CNTXT], NULL,
val_to_str_ext_const(GTP_EXT_PDP_CNTXT, &gtp_val_ext, "Unknown message"));
ea = (tvb_get_guint8(tvb, offset + 3) >> 7) & 0x01;
proto_tree_add_item(ext_tree_pdp, hf_gtp_extended_end_user_address, tvb, offset + 3, 1, ENC_NA);
proto_tree_add_item(ext_tree_pdp, hf_gtp_vplmn_address_allowed, tvb, offset + 3, 1, ENC_NA);
proto_tree_add_item(ext_tree_pdp, hf_gtp_activity_status_indicator, tvb, offset + 3, 1, ENC_NA);
proto_tree_add_item(ext_tree_pdp, hf_gtp_reordering_required, tvb, offset + 3, 1, ENC_NA);
proto_tree_add_item(ext_tree_pdp, hf_gtp_nsapi, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_cntxt_sapi, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
switch (gtp_version) {
case 0:
decode_qos_gprs(tvb, offset + 5, ext_tree_pdp, "QoS subscribed", 0);
decode_qos_gprs(tvb, offset + 8, ext_tree_pdp, "QoS requested", 0);
decode_qos_gprs(tvb, offset + 11, ext_tree_pdp, "QoS negotiated", 0);
offset = offset + 14;
break;
case 1:
offset = offset + 5;
offset = offset + decode_qos_umts(tvb, offset, pinfo, ext_tree_pdp, "QoS subscribed", 1);
offset = offset + decode_qos_umts(tvb, offset, pinfo, ext_tree_pdp, "QoS requested", 1);
offset = offset + decode_qos_umts(tvb, offset, pinfo, ext_tree_pdp, "QoS negotiated", 1);
break;
default:
break;
}
proto_tree_add_item(ext_tree_pdp, hf_gtp_sequence_number_down, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_pdp, hf_gtp_sequence_number_up, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_pdp, hf_gtp_send_n_pdu_number, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_pdp, hf_gtp_receive_n_pdu_number, tvb, offset + 5, 1, ENC_BIG_ENDIAN);
switch (gtp_version) {
case 0:
proto_tree_add_item(ext_tree_pdp, hf_gtp_uplink_flow_label_signalling, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
offset = offset + 8;
break;
case 1:
proto_tree_add_item(ext_tree_pdp, hf_gtp_ulink_teid_cp, tvb, offset + 6, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_pdp, hf_gtp_ulink_teid_data, tvb, offset + 10, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_context_identifier, tvb, offset + 14, 1, ENC_BIG_ENDIAN);
offset = offset + 15;
break;
default:
break;
}
pdp_type_num = tvb_get_guint8(tvb, offset + 1);
pdp_addr_len = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_organization, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_type, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_address_length, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
if (pdp_addr_len > 0) {
switch (pdp_type_num) {
case 0x21:
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_address_ipv4, tvb, offset + 3, 4, ENC_BIG_ENDIAN);
break;
case 0x57:
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_address_ipv6, tvb, offset + 3, 16, ENC_NA);
break;
default:
break;
}
}
offset = offset + 3 + pdp_addr_len;
ggsn_addr_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ext_tree_pdp, hf_gtp_ggsn_address_length, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (ggsn_addr_len) {
case 4:
proto_tree_add_item(ext_tree_pdp, hf_gtp_ggsn_address_for_control_plane, tvb, offset + 1, 4, ENC_BIG_ENDIAN);
break;
case 16:
proto_tree_add_item(ext_tree_pdp, hf_gtp_ggsn_address_for_user_traffic, tvb, offset + 1, 16, ENC_BIG_ENDIAN);
break;
default:
break;
}
offset = offset + 1 + ggsn_addr_len;
if (gtp_version == 1) {
ggsn_addr_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ext_tree_pdp, hf_gtp_ggsn_2_address_length, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (ggsn_addr_len) {
case 4:
proto_tree_add_item(ext_tree_pdp, hf_gtp_ggsn_2_address_ipv4, tvb, offset + 1, 4, ENC_BIG_ENDIAN);
break;
case 16:
proto_tree_add_item(ext_tree_pdp, hf_gtp_ggsn_2_address_ipv6, tvb, offset + 1, 16, ENC_NA);
break;
default:
break;
}
offset = offset + 1 + ggsn_addr_len;
}
apn_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ext_tree_pdp, hf_gtp_apn_length, tvb, offset, 1, ENC_BIG_ENDIAN);
decode_apn(tvb, offset + 1, apn_len, ext_tree_pdp, NULL);
offset = offset + 1 + apn_len;
trans_id = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ext_tree_pdp, hf_gtp_transaction_identifier, tvb, offset, 2, trans_id);
offset += 2;
if (ea) {
pdp_type_num = tvb_get_guint8(tvb, offset);
pdp_addr_len = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_address_length, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
if (pdp_addr_len > 0) {
switch (pdp_type_num) {
case 0x21:
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_address_ipv4, tvb, offset + 2, 4, ENC_NA);
break;
case 0x57:
proto_tree_add_item(ext_tree_pdp, hf_gtp_pdp_address_ipv6, tvb, offset + 2, 16, ENC_NA);
break;
default:
break;
}
}
}
return 3 + length;
}
static int
decode_gtp_apn(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree_apn;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_apn = proto_tree_add_subtree(tree, tvb, offset, length + 3, ett_gtp_ies[GTP_EXT_APN], &te,
val_to_str_ext_const(GTP_EXT_APN, &gtp_val_ext, "Unknown field"));
proto_tree_add_item(ext_tree_apn, hf_gtp_apn_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
decode_apn(tvb, offset + 3, length, ext_tree_apn, te);
return 3 + length;
}
int
decode_gtp_proto_conf(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
tvbuff_t *next_tvb;
proto_tree *ext_tree_proto;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_proto = proto_tree_add_subtree(tree, tvb, offset, length + 3,
ett_gtp_proto, NULL, val_to_str_ext_const(GTP_EXT_PROTO_CONF, &gtp_val_ext, "Unknown message"));
proto_tree_add_uint(ext_tree_proto, hf_gtp_length, tvb, offset + 1, 2, length);
if (length < 1)
return 3;
next_tvb = tvb_new_subset_length(tvb, offset + 3, length);
de_sm_pco(next_tvb, ext_tree_proto, pinfo, 0, length, NULL, 0);
return 3 + length;
}
static int
decode_gtp_gsn_addr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 addr_type, addr_len;
guint16 length;
proto_tree *ext_tree_gsn_addr;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_gsn_addr = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_gsn_addr, &te, "GSN address : ");
switch (length) {
case 4:
proto_tree_add_item(ext_tree_gsn_addr, hf_gtp_gsn_address_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_gsn_addr, hf_gtp_gsn_ipv4, tvb, offset + 3, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, "%s", tvb_ip_to_str(tvb, offset + 3));
break;
case 5:
proto_tree_add_item(ext_tree_gsn_addr, hf_gtp_gsn_address_information_element_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
addr_type = tvb_get_guint8(tvb, offset + 3) & 0xC0;
proto_tree_add_uint(ext_tree_gsn_addr, hf_gtp_gsn_addr_type, tvb, offset + 3, 1, addr_type);
addr_len = tvb_get_guint8(tvb, offset + 3) & 0x3F;
proto_tree_add_uint(ext_tree_gsn_addr, hf_gtp_gsn_addr_len, tvb, offset + 3, 1, addr_len);
proto_tree_add_item(ext_tree_gsn_addr, hf_gtp_gsn_ipv4, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, "%s", tvb_ip_to_str(tvb, offset + 4));
break;
case 16:
proto_tree_add_item(ext_tree_gsn_addr, hf_gtp_gsn_address_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_gsn_addr, hf_gtp_gsn_ipv6, tvb, offset + 3, 16, ENC_NA);
proto_item_append_text(te, "%s", tvb_ip6_to_str(tvb, offset + 3));
break;
case 17:
proto_tree_add_item(ext_tree_gsn_addr, hf_gtp_gsn_address_information_element_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
addr_type = tvb_get_guint8(tvb, offset + 3) & 0xC0;
proto_tree_add_uint(ext_tree_gsn_addr, hf_gtp_gsn_addr_type, tvb, offset + 3, 1, addr_type);
addr_len = tvb_get_guint8(tvb, offset + 3) & 0x3F;
proto_tree_add_uint(ext_tree_gsn_addr, hf_gtp_gsn_addr_len, tvb, offset + 3, 1, addr_len);
proto_item_append_text(te, "%s", tvb_ip6_to_str(tvb, offset + 4));
proto_tree_add_item(ext_tree_gsn_addr, hf_gtp_gsn_ipv6, tvb, offset + 4, 16, ENC_NA);
break;
default:
proto_item_append_text(te, "unknown type or wrong length");
break;
}
return 3 + length;
}
static int
decode_gtp_msisdn(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
tvbuff_t *next_tvb;
proto_tree *ext_tree_proto;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_proto = proto_tree_add_subtree(tree, tvb, offset, length + 3, ett_gtp_proto, NULL,
val_to_str_ext_const(GTP_EXT_MSISDN, &gtp_val_ext, "Unknown message"));
proto_tree_add_uint(ext_tree_proto, hf_gtp_length, tvb, offset + 1, 2, length);
length = tvb_get_ntohs(tvb, offset + 1);
if (length < 1)
return 3;
next_tvb = tvb_new_subset_length(tvb, offset+3, length);
dissect_gsm_map_msisdn(next_tvb, pinfo, ext_tree_proto);
return 3 + length;
}
static int
decode_gtp_qos_umts(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
return decode_qos_umts(tvb, offset, pinfo, tree, "Quality of Service", 2);
}
static int
decode_gtp_auth_qui(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree *ext_tree;
guint16 length;
guint8 xres_len, auth_len;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, length + 1, ett_gtp_quint, NULL, "Quintuplet");
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_rand, tvb, offset, 16, ENC_NA);
offset = offset + 16;
xres_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ext_tree, hf_gtp_xres_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_xres, tvb, offset, xres_len, ENC_NA);
offset = offset + xres_len;
proto_tree_add_item(ext_tree, hf_gtp_quintuplet_ciphering_key, tvb, offset, 16, ENC_NA);
offset = offset + 16;
proto_tree_add_item(ext_tree, hf_gtp_quintuplet_integrity_key, tvb, offset, 16, ENC_NA);
offset = offset + 16;
auth_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ext_tree, hf_gtp_authentication_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_auth, tvb, offset, auth_len, ENC_NA);
return (3 + length);
}
static int
decode_gtp_tft(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length, port1, port2, tos;
guint8 tft_flags, tft_code, no_packet_filters, i, pf_eval, pf_len, pf_content_id, proto;
guint pf_offset;
guint32 ipsec_id, label;
proto_tree *ext_tree_tft, *ext_tree_tft_pf, *ext_tree_tft_flags;
proto_item *tee, *pf_item;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_tft = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_tft, NULL, "Traffic flow template");
tft_flags = tvb_get_guint8(tvb, offset + 3);
tft_code = (tft_flags >> 5) & 0x07;
no_packet_filters = tft_flags & 0x0F;
proto_tree_add_item(ext_tree_tft, hf_gtp_tft_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
ext_tree_tft_flags = proto_tree_add_subtree(ext_tree_tft, tvb, offset + 3, 1, ett_gtp_tft_flags, NULL, "TFT flags");
proto_tree_add_uint(ext_tree_tft_flags, hf_gtp_tft_code, tvb, offset + 3, 1, tft_flags);
proto_tree_add_uint(ext_tree_tft_flags, hf_gtp_tft_spare, tvb, offset + 3, 1, tft_flags);
proto_tree_add_uint(ext_tree_tft_flags, hf_gtp_tft_number, tvb, offset + 3, 1, tft_flags);
offset = offset + 4;
for (i = 0; i < no_packet_filters; i++) {
tee = proto_tree_add_item(ext_tree_tft, hf_gtp_tft_packet_filter_id, tvb, offset, 1, ENC_BIG_ENDIAN);
ext_tree_tft_pf = proto_item_add_subtree(tee, ett_gtp_tft_pf);
offset++;
if (tft_code != 2) {
pf_eval = tvb_get_guint8(tvb, offset);
pf_len = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_uint(ext_tree_tft_pf, hf_gtp_tft_eval, tvb, offset, 1, pf_eval);
proto_tree_add_item(ext_tree_tft_pf, hf_gtp_tft_content_length, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
offset = offset + 2;
pf_offset = 0;
while (pf_offset < pf_len) {
pf_content_id = tvb_get_guint8(tvb, offset + pf_offset);
pf_item = proto_tree_add_item(ext_tree_tft_pf, hf_gtp_tft_content_id, tvb, offset + pf_offset, 1, ENC_BIG_ENDIAN);
switch (pf_content_id) {
case 0x10:
proto_item_set_text(pf_item, "ID 0x10: IPv4/mask: %s/%s", tvb_ip_to_str(tvb, offset + pf_offset + 1),
tvb_ip_to_str(tvb, offset + pf_offset + 5));
proto_item_set_len(pf_item, 9);
pf_offset += 9;
break;
case 0x20:
proto_item_set_text(pf_item, "ID 0x20: IPv6/mask: %s/%s",
tvb_ip6_to_str(tvb, offset + pf_offset + 1), tvb_ip6_to_str(tvb, offset + pf_offset + 17));
proto_item_set_len(pf_item, 33);
pf_offset += 33;
break;
case 0x30:
proto = tvb_get_guint8(tvb, offset + pf_offset + 1);
proto_item_set_text(pf_item, "ID 0x30: IPv4 protocol identifier/IPv6 next header: %u (%x)",
proto, proto);
proto_item_set_len(pf_item, 2);
pf_offset += 2;
break;
case 0x40:
port1 = tvb_get_ntohs(tvb, offset + pf_offset + 1);
proto_item_set_text(pf_item, "ID 0x40: destination port: %u", port1);
proto_item_set_len(pf_item, 3);
pf_offset += 3;
break;
case 0x41:
port1 = tvb_get_ntohs(tvb, offset + pf_offset + 1);
port2 = tvb_get_ntohs(tvb, offset + pf_offset + 3);
proto_item_set_text(pf_item, "ID 0x41: destination port range: %u - %u", port1, port2);
proto_item_set_len(pf_item, 5);
pf_offset += 5;
break;
case 0x50:
port1 = tvb_get_ntohs(tvb, offset + pf_offset + 1);
proto_item_set_text(pf_item, "ID 0x50: source port: %u", port1);
proto_item_set_len(pf_item, 3);
pf_offset += 3;
break;
case 0x51:
port1 = tvb_get_ntohs(tvb, offset + pf_offset + 1);
port2 = tvb_get_ntohs(tvb, offset + pf_offset + 3);
proto_item_set_text(pf_item, "ID 0x51: source port range: %u - %u", port1, port2);
proto_item_set_len(pf_item, 5);
pf_offset += 5;
break;
case 0x60:
ipsec_id = tvb_get_ntohl(tvb, offset + pf_offset + 1);
proto_item_set_text(pf_item, "ID 0x60: security parameter index: %x", ipsec_id);
proto_item_set_len(pf_item, 5);
pf_offset += 5;
break;
case 0x70:
tos = tvb_get_ntohs(tvb, offset + pf_offset + 1);
proto_item_set_text(pf_item, "ID 0x70: Type of Service/Traffic Class: %u (%x)", tos, tos);
proto_item_set_len(pf_item, 3);
pf_offset += 3;
break;
case 0x80:
label = tvb_get_ntoh24(tvb, offset + pf_offset + 1) & 0x0FFFFF;
proto_item_set_text(pf_item, "ID 0x80: Flow Label: %u (%x)", label, label);
proto_item_set_len(pf_item, 4);
pf_offset += 4;
break;
default:
proto_item_set_text(pf_item, "Unknown value: %x ", pf_content_id);
pf_offset++;
break;
}
}
offset = offset + pf_offset;
}
}
return 3 + length;
}
static int
decode_gtp_target_id(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_TARGET_ID], NULL, "Target Identification");
offset = offset + 1;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
if (length == 0){
return 3 + length;
}
dissect_e212_mcc_mnc(tvb, pinfo, ext_tree, offset, E212_NONE, TRUE);
offset+=3;
proto_tree_add_item(ext_tree, hf_gtp_rai_lac, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(ext_tree, hf_gtp_rai_rac, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_target_rnc_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if(length == 10){
proto_tree_add_item(ext_tree, hf_gtp_target_ext_rnc_id, tvb, offset, 2, ENC_BIG_ENDIAN);
}
return 3 + length;
}
static int
decode_gtp_utran_cont(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_UTRAN_CONT], NULL, "UTRAN transparent Container");
offset = offset + 1;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_utran_field, tvb, offset, length, ENC_NA);
return 3 + length;
}
static int
decode_gtp_rab_setup(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint32 teid;
guint16 length;
proto_tree *ext_tree_rab_setup;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_rab_setup = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_rab_setup, NULL, "Radio Access Bearer Setup Information");
proto_tree_add_item(ext_tree_rab_setup, hf_gtp_rab_setup_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_rab_setup, hf_gtp_nsapi, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
if (length > 1) {
teid = tvb_get_ntohl(tvb, offset + 4);
proto_tree_add_uint(ext_tree_rab_setup, hf_gtp_teid_data, tvb, offset + 4, 4, teid);
switch (length) {
case 9:
proto_tree_add_item(ext_tree_rab_setup, hf_gtp_rnc_ipv4, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
break;
case 21:
proto_tree_add_item(ext_tree_rab_setup, hf_gtp_rnc_ipv6, tvb, offset + 8, 16, ENC_NA);
break;
default:
break;
}
}
return 3 + length;
}
static int
decode_gtp_hdr_list(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
int i;
guint8 length, hdr;
proto_tree *ext_tree_hdr_list;
length = tvb_get_guint8(tvb, offset + 1);
ext_tree_hdr_list = proto_tree_add_subtree(tree, tvb, offset, 2 + length, ett_gtp_hdr_list, NULL,
val_to_str_ext_const(GTP_EXT_HDR_LIST, &gtp_val_ext, "Unknown"));
proto_tree_add_item(ext_tree_hdr_list, hf_gtp_num_ext_hdr_types, tvb, offset + 1, 1, ENC_NA);
for (i = 0; i < length; i++) {
hdr = tvb_get_guint8(tvb, offset + 2 + i);
proto_tree_add_uint_format(ext_tree_hdr_list, hf_gtp_ext_hdr_type, tvb, offset + 2 + i, 1, hdr, "No. %u --> Extension Header Type value : %s (0x%02x)", i + 1,
val_to_str_const(hdr, next_extension_header_fieldvals, "Unknown Extension Header Type"), hdr);
}
return 2 + length;
}
static int
decode_gtp_trigger_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_item* ti;
length = tvb_get_ntohs(tvb, offset + 1);
ti = proto_tree_add_uint_format(tree, hf_gtp_ext_length, tvb, offset, 2, length, "%s length : %u",
val_to_str_ext_const(GTP_EXT_TRIGGER_ID, &gtp_val_ext, "Unknown"), length);
proto_item_set_len(ti, 3 + length);
return 3 + length;
}
static int
decode_gtp_omc_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_item* ti;
length = tvb_get_ntohs(tvb, offset + 1);
ti = proto_tree_add_uint_format(tree, hf_gtp_ext_length, tvb, offset, 2, length, "%s length : %u",
val_to_str_ext_const(GTP_EXT_OMC_ID, &gtp_val_ext, "Unknown"), length);
proto_item_set_len(ti, 3 + length);
return 3 + length;
}
static int
decode_gtp_chrg_addr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree_chrg_addr;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_chrg_addr = proto_tree_add_subtree_format(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_CHRG_ADDR], &te,
"%s : ", val_to_str_ext_const(GTP_EXT_CHRG_ADDR, &gtp_val_ext, "Unknown"));
proto_tree_add_uint_format(ext_tree_chrg_addr, hf_gtp_ext_length, tvb, offset + 1, 2, length,
"%s length : %u", val_to_str_ext_const(GTP_EXT_CHRG_ADDR, &gtp_val_ext, "Unknown"), length);
switch (length) {
case 4:
proto_tree_add_item(ext_tree_chrg_addr, hf_gtp_chrg_ipv4, tvb, offset + 3, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, "%s", tvb_ip_to_str(tvb, offset + 3));
break;
case 16:
proto_tree_add_item(ext_tree_chrg_addr, hf_gtp_chrg_ipv6, tvb, offset + 3, 16, ENC_NA);
proto_item_append_text(te, "%s", tvb_ip6_to_str(tvb, offset + 3));
break;
default:
proto_item_append_text(te, "unknown type or wrong length");
break;
}
return 3 + length;
}
static int
decode_gtp_ran_tr_cont(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
tvbuff_t *next_tvb;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree_format(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_RAN_TR_CONT], NULL,
"%s : ", val_to_str_ext_const(GTP_EXT_RAN_TR_CONT, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
next_tvb = tvb_new_subset_length(tvb, offset, length);
if (bssgp_handle) {
#if 0
col_set_fence(pinfo->cinfo, COL_INFO);
#endif
call_dissector(bssgp_handle, next_tvb, pinfo, ext_tree);
}
return 3 + length;
}
static int
decode_gtp_pdp_cont_prio(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree_format(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_PDP_CONT_PRIO], NULL,
"%s : ", val_to_str_ext_const(GTP_EXT_PDP_CONT_PRIO, &gtp_val_ext, "Unknown"));
if (length == 0) {
return 3;
}
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_add_rab_setup_inf(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree_format(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_ADD_RAB_SETUP_INF], NULL,
"%s : ", val_to_str_ext_const(GTP_EXT_ADD_RAB_SETUP_INF, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_ssgn_no(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree_format(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_SSGN_NO], NULL,
"%s : ", val_to_str_ext_const(GTP_EXT_SSGN_NO, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_common_flgs(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree_format(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_COMMON_FLGS], NULL,
"%s : ", val_to_str_ext_const(GTP_EXT_COMMON_FLGS, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_cmn_flg_dual_addr_bearer_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_cmn_flg_upgrd_qos_sup, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_cmn_flg_nrsn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_cmn_flg_no_qos_neg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_cmn_flg_mbs_cnt_inf, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_cmn_flg_mbs_ran_pcd_rdy, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_cmn_flg_mbs_srv_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_cmn_flg_ppc, tvb, offset, 1, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_apn_res(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree_apn_res;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_apn_res = proto_tree_add_subtree_format(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_APN_RES], NULL,
"%s : ", val_to_str_ext_const(GTP_EXT_APN_RES, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree_apn_res, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_gtp_ext_length_mal, tvb, 0, length, "Wrong length indicated. Expected 1, got %u", length);
return 3 + length;
}
proto_tree_add_item(ext_tree_apn_res, hf_gtp_ext_apn_res, tvb, offset, length, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_rat_type(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree_rat_type;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_rat_type = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_RAT_TYPE], &te,
val_to_str_ext_const(GTP_EXT_RAT_TYPE, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree_rat_type, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_gtp_ext_length_mal, tvb, 0, length, "Wrong length indicated. Expected 1, got %u", length);
return 3 + length;
}
proto_tree_add_item(ext_tree_rat_type, hf_gtp_ext_rat_type, tvb, offset, length, ENC_BIG_ENDIAN);
proto_item_append_text(te, ": %s", val_to_str_const(tvb_get_guint8(tvb,offset), gtp_ext_rat_type_vals, "Unknown"));
return 3 + length;
}
static const
gchar *dissect_radius_user_loc(proto_tree * tree, tvbuff_t * tvb, packet_info* pinfo)
{
int offset = 0;
guint8 geo_loc_type;
guint16 length = tvb_reported_length(tvb);
proto_item* ti;
ti = proto_tree_add_item(tree, hf_gtp_ext_geo_loc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
geo_loc_type = tvb_get_guint8(tvb, offset);
offset++;
switch(geo_loc_type) {
case 0:
be_cell_id_aux(tvb, tree, pinfo, offset, length - 1, NULL, 0, 0);
break;
case 1:
be_cell_id_aux(tvb, tree, pinfo, offset, length - 1, NULL, 0, 4);
offset = offset + 5;
proto_tree_add_item(tree, hf_gtp_ext_sac, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 2:
dissect_e212_mcc_mnc(tvb, pinfo, tree, offset, E212_RAI, TRUE);
offset+=3;
proto_tree_add_item(tree, hf_gtp_rai_lac, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_gtp_rai_rac, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 128:
dissect_e212_mcc_mnc(tvb, pinfo, tree, offset, E212_NONE, TRUE);
offset+=3;
proto_tree_add_item(tree, hf_gtp_tac, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 129:
dissect_e212_mcc_mnc(tvb, pinfo, tree, offset, E212_NONE, TRUE);
offset+=3;
proto_tree_add_item(tree, hf_gtp_eci, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 130:
dissect_e212_mcc_mnc(tvb, pinfo, tree, offset, E212_NONE, TRUE);
offset+=3;
proto_tree_add_item(tree, hf_gtp_tac, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dissect_e212_mcc_mnc(tvb, pinfo, tree, offset, E212_NONE, TRUE);
offset+=3;
proto_tree_add_item(tree, hf_gtp_eci, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
expert_add_info(pinfo, ti, &ei_gtp_ext_geo_loc_type);
break;
}
return tvb_bytes_to_str(wmem_packet_scope(), tvb, 0, length);
}
static int
decode_gtp_usr_loc_inf(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree, *rai_tree;
guint8 geo_loc_type;
proto_item* ti;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_USR_LOC_INF], NULL,
val_to_str_ext_const(GTP_EXT_USR_LOC_INF, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
ti = proto_tree_add_item(ext_tree, hf_gtp_ext_geo_loc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
geo_loc_type = tvb_get_guint8(tvb, offset);
offset++;
switch(geo_loc_type) {
case 0:
be_cell_id_aux(tvb, ext_tree, pinfo, offset, length - 1, NULL, 0, 0);
break;
case 1:
be_cell_id_aux(tvb, ext_tree, pinfo, offset, length - 1, NULL, 0, 4);
offset = offset + 5;
proto_tree_add_item(ext_tree, hf_gtp_ext_sac, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 2:
rai_tree = proto_tree_add_subtree(ext_tree, tvb, offset + 1, 7, ett_gtp_uli_rai, NULL, "Routeing Area Identity (RAI)");
dissect_e212_mcc_mnc(tvb, pinfo, rai_tree, offset, E212_RAI, TRUE);
offset+=3;
proto_tree_add_item(rai_tree, hf_gtp_rai_lac, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(rai_tree, hf_gtp_rai_rac, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
expert_add_info(pinfo, ti, &ei_gtp_ext_geo_loc_type);
break;
}
return 3 + length;
}
static int
decode_gtp_ms_time_zone(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
guint8 data;
char sign;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree_format(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MS_TIME_ZONE], &te,
"%s: ", val_to_str_ext_const(GTP_EXT_MS_TIME_ZONE, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
data = tvb_get_guint8(tvb, offset);
sign = (data & 0x08) ? '-' : '+';
data = (data >> 4) + (data & 0x07) * 10;
proto_tree_add_uint_format_value(ext_tree, hf_gtp_timezone, tvb, offset, 1, data, "GMT %c %d hours %d minutes", sign, data / 4, data % 4 * 15);
proto_item_append_text(te, "GMT %c %d hours %d minutes", sign, data / 4, data % 4 * 15);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_timezone_dst, tvb, offset, 1, ENC_NA);
return 3 + length;
}
static int
decode_gtp_imeisv(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_imeisv;
proto_item *te;
tvbuff_t *next_tvb;
const char *digit_str;
length = tvb_get_ntohs(tvb, offset + 1);
ext_imeisv = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_IMEISV], &te,
val_to_str_ext_const(GTP_EXT_IMEISV, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_imeisv, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
next_tvb = tvb_new_subset_length(tvb, offset, length);
digit_str = tvb_bcd_dig_to_wmem_packet_str(next_tvb, 0, -1, NULL, FALSE);
proto_tree_add_string(ext_imeisv, hf_gtp_ext_imeisv, next_tvb, 0, -1, digit_str);
proto_item_append_text(te, ": %s", digit_str);
return 3 + length;
}
static int
decode_gtp_camel_chg_inf_con(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_CAMEL_CHG_INF_CON], NULL,
val_to_str_ext_const(GTP_EXT_CAMEL_CHG_INF_CON, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_mbms_ue_ctx(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_UE_CTX], NULL,
val_to_str_ext_const(GTP_EXT_MBMS_UE_CTX, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_tmgi(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree, *tmgi_tree;
proto_item *ti;
tvbuff_t *next_tvb;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_TMGI], NULL,
val_to_str_ext_const(GTP_EXT_TMGI, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
ti = proto_tree_add_item(ext_tree, hf_gtp_tmgi, tvb, offset, length, ENC_NA);
tmgi_tree = proto_item_add_subtree(ti, ett_gtp_tmgi);
next_tvb = tvb_new_subset_length(tvb, offset, length);
de_mid(next_tvb, tmgi_tree, pinfo, 0, length, NULL, 0);
return 3 + length;
}
static int
decode_gtp_rim_ra(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_RIM_RA], NULL,
val_to_str_ext_const(GTP_EXT_RIM_RA, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_rim_routing_addr, tvb, offset, length, ENC_NA);
return 3 + length;
}
static int
decode_gtp_mbms_prot_conf_opt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_PROT_CONF_OPT], NULL,
val_to_str_ext_const(GTP_EXT_MBMS_PROT_CONF_OPT, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
dissect_gtp_mbms_ses_dur(tvbuff_t * tvb, packet_info * pinfo _U_, proto_tree * tree, void *data _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtp_mbms_ses_dur_days, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtp_mbms_ses_dur_s, tvb, offset, 3, ENC_BIG_ENDIAN);
return 3;
}
static int
decode_gtp_mbms_ses_dur(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_SES_DUR], NULL,
val_to_str_ext_const(GTP_EXT_MBMS_SES_DUR, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_mbms_ses_dur_days, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_mbms_ses_dur_s, tvb, offset, 3, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
dissect_gtp_3gpp_mbms_service_area(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
int offset = 0;
guint8 no_of_mbms_sa_codes;
int i;
no_of_mbms_sa_codes = tvb_get_guint8(tvb, offset) + 1;
proto_tree_add_uint(tree, hf_gtp_no_of_mbms_sa_codes, tvb, offset, 1, no_of_mbms_sa_codes);
offset++;
for (i = 0; i < no_of_mbms_sa_codes; i++) {
proto_tree_add_item(tree, hf_gtp_mbms_sa_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
}
return offset;
}
static int
decode_gtp_mbms_sa(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
tvbuff_t *next_tvb;
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_SA], NULL,
val_to_str_ext_const(GTP_EXT_MBMS_SA, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
next_tvb = tvb_new_subset_length(tvb, offset, length-3);
dissect_gtp_3gpp_mbms_service_area(next_tvb, pinfo, ext_tree, NULL);
return 3 + length;
}
static int
decode_gtp_src_rnc_pdp_ctx_inf(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_SRC_RNC_PDP_CTX_INF], NULL,
val_to_str_ext_const(GTP_EXT_SRC_RNC_PDP_CTX_INF, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_add_trs_inf(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_ADD_TRS_INF], NULL,
val_to_str_ext_const(GTP_EXT_ADD_TRS_INF, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_hop_count(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_HOP_COUNT], NULL,
val_to_str_ext_const(GTP_EXT_HOP_COUNT, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_sel_plmn_id(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_SES_ID], NULL,
val_to_str_ext_const(GTP_EXT_SEL_PLMN_ID, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
dissect_e212_mcc_mnc(tvb, pinfo, ext_tree, offset, E212_NONE, FALSE);
return 3 + length;
}
static int
decode_gtp_mbms_ses_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_SES_ID], NULL, val_to_str_ext_const(GTP_EXT_MBMS_SES_ID, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_mbms_2g_3g_ind(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_2G_3G_IND], NULL,
val_to_str_ext_const(GTP_EXT_MBMS_2G_3G_IND, &gtp_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_mbs_2g_3g_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_enh_nsapi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_ENH_NSAPI], NULL, val_to_str_ext_const(GTP_EXT_ENH_NSAPI, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_add_mbms_trs_inf(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_ADD_MBMS_TRS_INF], NULL,
val_to_str_ext_const(GTP_EXT_ADD_MBMS_TRS_INF, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_mbms_ses_id_rep_no(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_SES_ID_REP_NO], NULL,
val_to_str_ext_const(GTP_EXT_MBMS_SES_ID_REP_NO, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
dissect_gtp_mbms_time_to_data_tr(tvbuff_t * tvb, packet_info * pinfo _U_, proto_tree * tree, void *data _U_)
{
int offset = 0;
guint8 time_2_dta_tr;
time_2_dta_tr = tvb_get_guint8(tvb, offset) + 1;
proto_tree_add_uint(tree, hf_gtp_time_2_dta_tr, tvb, offset, 1, time_2_dta_tr);
return 3;
}
static int
decode_gtp_mbms_time_to_data_tr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
guint8 time_2_dta_tr;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_TIME_TO_DATA_TR], NULL,
val_to_str_ext_const(GTP_EXT_MBMS_TIME_TO_DATA_TR, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
time_2_dta_tr = tvb_get_guint8(tvb, offset) + 1;
proto_tree_add_uint(ext_tree, hf_gtp_time_2_dta_tr, tvb, offset, 1, time_2_dta_tr);
return 3 + length;
}
static int
decode_gtp_ps_ho_req_ctx(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_PS_HO_REQ_CTX], NULL,
val_to_str_ext_const(GTP_EXT_PS_HO_REQ_CTX, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_bss_cont(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_BSS_CONT], NULL,
val_to_str_ext_const(GTP_EXT_BSS_CONT, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_cell_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_CELL_ID], NULL,
val_to_str_ext_const(GTP_EXT_CELL_ID, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_pdu_no(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_PDU_NO], NULL,
val_to_str_ext_const(GTP_EXT_PDU_NO, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_bssgp_cause(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_BSSGP_CAUSE], NULL,
val_to_str_ext_const(GTP_EXT_BSSGP_CAUSE, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_bssgp_cause, tvb, offset, 2, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_mbms_bearer_cap(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_REQ_MBMS_BEARER_CAP], NULL,
val_to_str_ext_const(GTP_EXT_REQ_MBMS_BEARER_CAP, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
#if 0
offset = offset + 2;
#endif
return 3 + length;
}
static int
decode_gtp_rim_ra_disc(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_RIM_ROUTING_ADDR_DISC], NULL,
val_to_str_ext_const(GTP_EXT_RIM_ROUTING_ADDR_DISC, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_bssgp_ra_discriminator, tvb, offset, 1, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_lst_set_up_pfc(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_LIST_OF_SETUP_PFCS], NULL,
val_to_str_ext_const(GTP_EXT_LIST_OF_SETUP_PFCS, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_ps_handover_xid(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
tvbuff_t *next_tvb;
guint8 sapi;
guint8 xid_par_len;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_PS_HANDOVER_XIP_PAR], NULL,
val_to_str_ext_const(GTP_EXT_PS_HANDOVER_XIP_PAR, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
sapi = tvb_get_guint8(tvb, offset) & 0x0F;
proto_tree_add_uint(ext_tree, hf_gtp_sapi, tvb, offset, 1, sapi);
offset++;
xid_par_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ext_tree, hf_gtp_xid_par_len, tvb, offset, 1, xid_par_len);
offset++;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (sndcpxid_handle)
call_dissector(sndcpxid_handle, next_tvb, pinfo, tree);
else
call_dissector(data_handle, next_tvb, pinfo, tree);
return 4 + length;
}
static int
decode_gtp_ms_inf_chg_rep_act(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MS_INF_CHG_REP_ACT], NULL,
val_to_str_ext_const(GTP_EXT_MS_INF_CHG_REP_ACT, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_direct_tnl_flg(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_DIRECT_TUNNEL_FLGS], NULL,
val_to_str_ext_const(GTP_EXT_DIRECT_TUNNEL_FLGS, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ext_tree, hf_gtp_ext_ei, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_ext_gcsi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_ext_dti, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (length == 1) {
return 3 + length;
}
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_corrl_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_CORRELATION_ID], NULL,
val_to_str_ext_const(GTP_EXT_CORRELATION_ID, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_bearer_cntrl_mod(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_BEARER_CONTROL_MODE], NULL,
val_to_str_ext_const(GTP_EXT_BEARER_CONTROL_MODE, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_bcm, tvb, offset, 1, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_mbms_flow_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_FLOW_ID], NULL,
val_to_str_ext_const(GTP_EXT_MBMS_FLOW_ID, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_mbms_flow_id, tvb, offset, length, ENC_NA);
return 3 + length;
}
static int
decode_gtp_mbms_ip_mcast_dist(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_IP_MCAST_DIST], NULL,
val_to_str_ext_const(GTP_EXT_MBMS_IP_MCAST_DIST, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_mbms_dist_ack(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MBMS_DIST_ACK], NULL,
val_to_str_ext_const(GTP_EXT_MBMS_DIST_ACK, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_mbms_dist_indic, tvb, offset, 1, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_reliable_irat_ho_inf(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_RELIABLE_IRAT_HO_INF], NULL,
val_to_str_ext_const(GTP_EXT_RELIABLE_IRAT_HO_INF, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_rfsp_index(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length, rfsp;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_RFSP_INDEX], NULL,
val_to_str_ext_const(GTP_EXT_RFSP_INDEX, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
rfsp = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(ext_tree, hf_gtp_rfsp_index, tvb, offset, length, rfsp+1);
return 3 + length;
}
static int
decode_gtp_fqdn(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, length + 3, ett_gtp_ies[GTP_EXT_FQDN], NULL,
val_to_str_ext_const(GTP_EXT_FQDN, &gtp_val_ext, "Unknown field"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_fqdn_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
decode_fqdn(tvb, offset + 3, length, ext_tree);
return 3 + length;
}
static int
decode_gtp_evolved_allc_rtn_p1(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_EVO_ALLO_RETE_P1], NULL,
val_to_str_ext_const(GTP_EXT_EVO_ALLO_RETE_P1, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ext_tree, hf_gtp_earp_pvi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_earp_pl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_earp_pci, tvb, offset, 1, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_evolved_allc_rtn_p2(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_EVO_ALLO_RETE_P2], NULL,
val_to_str_ext_const(GTP_EXT_EVO_ALLO_RETE_P2, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_nsapi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_earp_pvi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_earp_pl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_earp_pci, tvb, offset, 1, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_extended_common_flgs(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_EXTENDED_COMMON_FLGS], NULL,
val_to_str_ext_const(GTP_EXT_EXTENDED_COMMON_FLGS, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_uci(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_UCI], NULL,
val_to_str_ext_const(GTP_EXT_UCI, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_csg_inf_rep_act(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_CSG_INF_REP_ACT], NULL,
val_to_str_ext_const(GTP_EXT_CSG_INF_REP_ACT, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_csg_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_CSG_ID], NULL,
val_to_str_ext_const(GTP_EXT_CSG_ID, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_cmi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_CMI], NULL,
val_to_str_ext_const(GTP_EXT_CMI, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_apn_ambr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_RELIABLE_IRAT_HO_INF], NULL,
val_to_str_ext_const(GTP_EXT_AMBR, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
te = proto_tree_add_item(ext_tree, hf_gtp_ext_apn_ambr_ul, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, " kbps");
offset+=4;
te = proto_tree_add_item(ext_tree, hf_gtp_ext_apn_ambr_dl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, " kbps");
return 3 + length;
}
static int
decode_gtp_ue_network_cap(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_UE_NETWORK_CAP], NULL,
val_to_str_ext_const(GTP_EXT_UE_NETWORK_CAP, &gtpv1_val_ext, "Unknown"));
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
de_emm_ue_net_cap(tvb, ext_tree, pinfo, offset, length, NULL, 0);
return 3 + length;
}
static int
decode_gtp_ue_ambr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_APN_AMBR_WITH_NSAPI], NULL,
val_to_str_ext_const(GTP_EXT_APN_AMBR_WITH_NSAPI, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
te = proto_tree_add_item(ext_tree, hf_gtp_ext_sub_ue_ambr_ul, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, " kbps");
offset+=4;
te = proto_tree_add_item(ext_tree, hf_gtp_ext_sub_ue_ambr_dl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, " kbps");
offset+=4;
if(offset >= length)
return 3 + length;
te = proto_tree_add_item(ext_tree, hf_gtp_ext_auth_ue_ambr_ul, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, " kbps");
offset+=4;
te = proto_tree_add_item(ext_tree, hf_gtp_ext_auth_ue_ambr_dl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, " kbps");
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_apn_ambr_with_nsapi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_UE_AMBR], NULL,
val_to_str_ext_const(GTP_EXT_UE_AMBR, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_nsapi, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
offset++;
te = proto_tree_add_item(ext_tree, hf_gtp_ext_auth_apn_ambr_ul, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, " kbps");
offset+=4;
te = proto_tree_add_item(ext_tree, hf_gtp_ext_auth_apn_ambr_dl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, " kbps");
return 3 + length;
}
static int
decode_gtp_ggsn_back_off_time(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_GGSN_BACK_OFF_TIME], NULL,
val_to_str_ext_const(GTP_EXT_GGSN_BACK_OFF_TIME, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ext_tree, hf_gtp_ext_ggsn_back_off_time_units, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_ext_ggsn_back_off_timer, tvb, offset, 2, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_sig_pri_ind(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_SIG_PRI_IND], NULL,
val_to_str_ext_const(GTP_EXT_SIG_PRI_IND, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_sig_pri_ind_w_nsapi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_SIG_PRI_IND_W_NSAPI], NULL,
val_to_str_ext_const(GTP_EXT_SIG_PRI_IND_W_NSAPI, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_higher_br_16mb_flg(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_HIGHER_BR_16MB_FLG], NULL,
val_to_str_ext_const(GTP_EXT_HIGHER_BR_16MB_FLG, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ext_tree, hf_gtp_higher_br_16mb_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_max_mbr_apn_ambr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
guint32 max_ul;
guint32 max_dl;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_MAX_MBR_APN_AMBR], NULL,
val_to_str_ext_const(GTP_EXT_MAX_MBR_APN_AMBR, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
max_ul = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(ext_tree, hf_gtp_max_mbr_apn_ambr_ul, tvb, offset, 4, max_ul, "%u %s",
(max_ul) > 1000 ? max_ul/1000 : max_ul,
(max_ul) > 1000 ? "Mbps" : "kbps");
offset += 4;
max_dl = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(ext_tree, hf_gtp_max_mbr_apn_ambr_dl, tvb, offset, 4, max_dl, "%u %s",
(max_dl) > 1000 ? max_dl/1000 : max_dl,
(max_dl) > 1000 ? "Mbps" : "kbps");
return 3 + length;
}
static int
decode_gtp_add_mm_ctx_srvcc(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_ADD_MM_CTX_SRVCC], NULL,
val_to_str_ext_const(GTP_EXT_ADD_MM_CTX_SRVCC, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_add_flgs_srvcc(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_ADD_FLGS_SRVCC], NULL,
val_to_str_ext_const(GTP_EXT_ADD_FLGS_SRVCC, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_stn_sr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_STN_SR], NULL,
val_to_str_ext_const(GTP_EXT_STN_SR, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_c_msisdn(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_C_MSISDN], NULL,
val_to_str_ext_const(GTP_EXT_C_MSISDN, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_ext_ranap_cause(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_EXT_RANAP_CAUSE], NULL,
val_to_str_ext_const(GTP_EXT_EXT_RANAP_CAUSE, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_ext_enodeb_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
guint32 enb_type;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_ENODEB_ID], NULL,
val_to_str_ext_const(GTP_EXT_ENODEB_ID, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item_ret_uint(ext_tree, hf_gtp_ext_enb_type, tvb, offset, 1, ENC_BIG_ENDIAN, &enb_type);
offset++;
dissect_e212_mcc_mnc(tvb, pinfo, ext_tree, offset, E212_NONE, TRUE);
offset += 3;
switch (enb_type){
case 0:
proto_tree_add_item(ext_tree, hf_gtp_macro_enodeb_id, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(ext_tree, hf_gtp_tac, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 1:
proto_tree_add_item(ext_tree, hf_gtp_home_enodeb_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ext_tree, hf_gtp_tac, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length - 4);
break;
}
return 3 + length;
}
static int
decode_gtp_ext_sel_mode_w_nsapi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_SEL_MODE_W_NSAPI], NULL,
val_to_str_ext_const(GTP_EXT_SEL_MODE_W_NSAPI, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_ext_uli_timestamp(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_ULI_TIMESTAMP], NULL,
val_to_str_ext_const(GTP_EXT_ULI_TIMESTAMP, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_ext_lhn_id_w_sapi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_LHN_ID_W_SAPI], NULL,
val_to_str_ext_const(GTP_EXT_LHN_ID_W_SAPI, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_ext_cn_op_sel_entity(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_ies[GTP_EXT_CN_OP_SEL_ENTITY], NULL,
val_to_str_ext_const(GTP_EXT_CN_OP_SEL_ENTITY, &gtpv1_val_ext, "Unknown"));
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_expert(ext_tree, pinfo, &ei_gtp_undecoded, tvb, offset, length);
return 3 + length;
}
static int
decode_gtp_rel_pack(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length, n, number;
proto_tree *ext_tree_rel_pack;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_rel_pack = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_rel_pack, NULL,
"Sequence numbers of released packets IE");
n = 0;
while (n < length) {
number = tvb_get_ntohs(tvb, offset + 3 + n);
proto_tree_add_uint_format(ext_tree_rel_pack, hf_gtp_seq_num_released, tvb, offset + 3 + n, 2, number, "%u", number);
n = n + 2;
}
return 3 + length;
}
static int
decode_gtp_can_pack(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length, n, number;
proto_tree *ext_tree_can_pack;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_can_pack = proto_tree_add_subtree(tree, tvb, offset, 3 + length, ett_gtp_can_pack, NULL,
"Sequence numbers of cancelled packets IE");
n = 0;
while (n < length) {
number = tvb_get_ntohs(tvb, offset + 3 + n);
proto_tree_add_uint_format(ext_tree_can_pack, hf_gtp_seq_num_canceled, tvb, offset + 3 + n, 2, number, "%u", number);
n += 2;
}
return 3 + length;
}
static int
decode_gtp_data_req(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length, cdr_length;
guint8 no, format, app_id, rel_id, ver_id, i;
proto_tree *ext_tree, *ver_tree, *cdr_dr_tree;
proto_item *fmt_item;
tvbuff_t *next_tvb;
ext_tree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_gtp_ext, NULL,
val_to_str_ext_const(GTP_EXT_DATA_REQ, &gtp_val_ext, "Unknown message"));
offset++;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(ext_tree, hf_gtp_length, tvb, offset, 2, length);
offset+=2;
if (length == 0) {
return 3;
}
no = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ext_tree, hf_gtp_number_of_data_records, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
format = tvb_get_guint8(tvb, offset);
fmt_item = proto_tree_add_item(ext_tree, hf_gtp_data_record_format, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(format < 4) {
proto_item_append_text(fmt_item, " %s", val_to_str_const(format, gtp_cdr_fmt_vals, "Unknown"));
app_id = tvb_get_guint8(tvb,offset);
rel_id = app_id & 0x0f;
app_id = app_id >>4;
ver_id =tvb_get_guint8(tvb,offset+1);
if(ver_id < 0x65)
ver_id = ver_id -1;
ver_tree = proto_tree_add_subtree_format(ext_tree, tvb, offset, 2, ett_gtp_cdr_ver, NULL,
"Data record format version: AppId %u Rel %u.%u.0", app_id,rel_id,ver_id);
proto_tree_add_item(ver_tree, hf_gtp_cdr_app, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ver_tree, hf_gtp_cdr_rel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ver_tree, hf_gtp_cdr_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for(i = 0; i < no; ++i) {
cdr_length = tvb_get_ntohs(tvb, offset);
cdr_dr_tree = proto_tree_add_subtree_format(ext_tree, tvb, offset, cdr_length+2,
ett_gtp_cdr_dr, NULL, "Data record %d", i + 1);
proto_tree_add_uint(cdr_dr_tree, hf_gtp_cdr_length, tvb, offset, 2, cdr_length);
offset+=2;
proto_tree_add_item(cdr_dr_tree, hf_gtp_cdr_context, tvb, offset, cdr_length, ENC_NA);
next_tvb = tvb_new_subset_remaining(tvb, offset);
if(format==1) {
if(rel_id <= 6){
dissect_gprscdr_GPRSCallEventRecord_PDU(next_tvb, pinfo, cdr_dr_tree, NULL);
}else if(rel_id >6){
dissect_gprscdr_GPRSRecord_PDU(next_tvb, pinfo, cdr_dr_tree, NULL);
}
} else {
dissector_try_uint(gtp_cdr_fmt_dissector_table, format, next_tvb, pinfo, cdr_dr_tree);
}
offset = offset + cdr_length;
}
} else {
proto_item_append_text(fmt_item, " Proprietary or un documented format");
}
if (gtpcdr_handle) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(gtpcdr_handle, next_tvb, pinfo, tree);
}
return 3 + length;
}
static int
decode_gtp_data_resp(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length, n, number;
proto_tree *ext_tree_data_resp;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_data_resp = proto_tree_add_subtree(tree, tvb, offset, 3 + length,
ett_gtp_data_resp, NULL, "Requests responded");
n = 0;
while (n < length) {
number = tvb_get_ntohs(tvb, offset + 3 + n);
proto_tree_add_uint_format(ext_tree_data_resp, hf_gtp_requests_responded, tvb, offset + 3 + n, 2, number, "%u", number);
n = n + 2;
}
return 3 + length;
}
static int
decode_gtp_node_addr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree_node_addr;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
ext_tree_node_addr = proto_tree_add_subtree(tree, tvb, offset, 3 + length,
ett_gtp_node_addr, &te, "Node address: ");
proto_tree_add_item(ext_tree_node_addr, hf_gtp_node_address_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
switch (length) {
case 4:
proto_tree_add_item(ext_tree_node_addr, hf_gtp_node_ipv4, tvb, offset + 3, 4, ENC_BIG_ENDIAN);
proto_item_append_text(te, "%s", tvb_ip_to_str(tvb, offset + 3));
break;
case 16:
proto_tree_add_item(ext_tree_node_addr, hf_gtp_node_ipv6, tvb, offset + 3, 16, ENC_NA);
proto_item_append_text(te, "%s", tvb_ip6_to_str(tvb, offset + 3));
break;
default:
proto_item_append_text(te, "unknown type or wrong length");
break;
}
return 3 + length;
}
static int
decode_gtp_priv_ext(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length, ext_id;
proto_tree *ext_tree_priv_ext;
proto_item *te;
tvbuff_t *next_tvb;
ext_tree_priv_ext = proto_tree_add_subtree_format(tree, tvb, offset, 1, ett_gtp_ext, &te,
"%s : ", val_to_str_ext_const(GTP_EXT_PRIV_EXT, &gtp_val_ext, "Unknown message"));
offset++;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ext_tree_priv_ext, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (length >= 2) {
ext_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(ext_tree_priv_ext, hf_gtp_ext_id, tvb, offset, 2, ext_id);
proto_item_append_text(te, "%s (%u)", val_to_str_ext_const(ext_id, &sminmpec_values_ext, "Unknown"), ext_id);
offset = offset + 2;
if (length > 2) {
next_tvb = tvb_new_subset_length(tvb, offset, length-2);
if(!dissector_try_uint(gtp_priv_ext_dissector_table, ext_id, next_tvb, pinfo, ext_tree_priv_ext)){
proto_tree_add_item(ext_tree_priv_ext, hf_gtp_ext_val, tvb, offset, length - 2, ENC_NA);
}
}
}
return 3 + length;
}
static int
decode_gtp_unknown(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
proto_tree_add_expert(tree, pinfo, &ei_gtp_unknown_extention_header, tvb, offset, 1);
return tvb_reported_length_remaining(tvb, offset);
}
static int
dissect_gtp_common(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint8 octet;
gtp_hdr_t *gtp_hdr = NULL;
proto_tree *gtp_tree = NULL, *ext_tree;
proto_item *ti = NULL, *tf, *ext_hdr_len_item, *message_item;
int i, offset = 0, checked_field, mandatory;
gboolean gtp_prime, has_SN;
int seq_no = 0;
int flow_label = 0;
guint8 pdu_no, next_hdr = 0;
guint8 ext_hdr_val;
guint ext_hdr_length;
guint16 ext_hdr_pdcpsn;
gchar *tid_str;
tvbuff_t *next_tvb;
guint8 sub_proto;
guint8 acfield_len = 0;
guint8 control_field;
gtp_msg_hash_t *gcrp = NULL;
conversation_t *conversation;
gtp_conv_info_t *gtp_info;
if (!tvb_bytes_exist(tvb, 0, 2)) {
return 0;
}
octet = tvb_get_guint8(tvb, 0);
if (((octet >> 5) & 0x07) > 2) {
return 0;
}
octet = tvb_get_guint8(tvb, 1);
if (octet == GTP_MSG_UNKNOWN || try_val_to_str(octet, gtp_message_type) == NULL) {
return 0;
}
gtp_hdr = wmem_new0(wmem_packet_scope(), gtp_hdr_t);
gtp_hdr->teid = -1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GTP");
col_clear(pinfo->cinfo, COL_INFO);
conversation = find_or_create_conversation(pinfo);
gtp_info = (gtp_conv_info_t *)conversation_get_proto_data(conversation, proto_gtp);
if (gtp_info == NULL) {
gtp_info = (gtp_conv_info_t *)g_malloc(sizeof(gtp_conv_info_t));
gtp_info->matched = g_hash_table_new(gtp_sn_hash, gtp_sn_equal_matched);
gtp_info->unmatched = g_hash_table_new(gtp_sn_hash, gtp_sn_equal_unmatched);
conversation_add_proto_data(conversation, proto_gtp, gtp_info);
gtp_info->next = gtp_info_items;
gtp_info_items = gtp_info;
}
gtp_hdr->flags = tvb_get_guint8(tvb, offset);
if (!(gtp_hdr->flags & 0x10)){
gtp_prime = TRUE;
}else{
gtp_prime = FALSE;
}
switch ((gtp_hdr->flags >> 5) & 0x07) {
case 0:
gtp_version = 0;
break;
case 1:
gtp_version = 1;
break;
default:
gtp_version = 1;
break;
}
if (tree) {
ti = proto_tree_add_item(tree, proto_gtp, tvb, 0, -1, ENC_NA);
gtp_tree = proto_item_add_subtree(ti, ett_gtp);
if(gtp_prime) {
const int * gtp_prime_flags[] = {
&hf_gtp_prime_flags_ver,
&hf_gtp_flags_pt,
&hf_gtp_flags_spare1,
NULL
};
const int * gtp_prime_v0_flags[] = {
&hf_gtp_prime_flags_ver,
&hf_gtp_flags_pt,
&hf_gtp_flags_spare1,
&hf_gtp_flags_hdr_length,
NULL
};
if(gtp_version == 0) {
proto_tree_add_bitmask_value_with_flags(gtp_tree, tvb, offset, hf_gtp_flags,
ett_gtp_flags, gtp_prime_v0_flags, gtp_hdr->flags, BMT_NO_APPEND);
} else {
proto_tree_add_bitmask_value_with_flags(gtp_tree, tvb, offset, hf_gtp_flags,
ett_gtp_flags, gtp_prime_flags, gtp_hdr->flags, BMT_NO_APPEND);
}
} else {
const int * gtp_flags[] = {
&hf_gtp_flags_ver,
&hf_gtp_flags_pt,
&hf_gtp_flags_spare2,
&hf_gtp_flags_e,
&hf_gtp_flags_s,
&hf_gtp_flags_pn,
NULL
};
const int * gtp_v0_flags[] = {
&hf_gtp_flags_ver,
&hf_gtp_flags_pt,
&hf_gtp_flags_spare1,
&hf_gtp_flags_snn,
NULL
};
if(gtp_version == 0) {
proto_tree_add_bitmask_value_with_flags(gtp_tree, tvb, offset, hf_gtp_flags,
ett_gtp_flags, gtp_v0_flags, gtp_hdr->flags, BMT_NO_APPEND);
} else {
proto_tree_add_bitmask_value_with_flags(gtp_tree, tvb, offset, hf_gtp_flags,
ett_gtp_flags, gtp_flags, gtp_hdr->flags, BMT_NO_APPEND);
}
}
}
offset++;
gtp_hdr->message = tvb_get_guint8(tvb, offset);
switch(gtp_hdr->message){
case GTP_MSG_DELETE_PDP_REQ:
case GTP_MSG_UPDATE_PDP_REQ:
case GTP_MSG_CREATE_PDP_REQ:
case GTP_MSG_INIT_PDP_CONTEXT_ACT_REQ:
case GTP_MSG_PDU_NOTIFY_REQ:
case GTP_MSG_PDU_NOTIFY_REJ_REQ:
pinfo->link_dir = P2P_DIR_UL;
break;
case GTP_MSG_DELETE_PDP_RESP:
case GTP_MSG_UPDATE_PDP_RESP:
case GTP_MSG_CREATE_PDP_RESP:
case GTP_MSG_INIT_PDP_CONTEXT_ACT_RESP:
pinfo->link_dir = P2P_DIR_DL;
break;
default:
break;
}
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_ext_const(gtp_hdr->message, &gtp_message_type_ext, "Unknown"));
message_item = proto_tree_add_uint(gtp_tree, hf_gtp_message_type, tvb, offset, 1, gtp_hdr->message);
offset++;
gtp_hdr->length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_length, tvb, 2, 2, gtp_hdr->length);
offset += 2;
has_SN = FALSE;
if (gtp_prime) {
seq_no = tvb_get_ntohs(tvb, offset);
has_SN = TRUE;
proto_tree_add_uint(gtp_tree, hf_gtp_seq_number, tvb, offset, 2, seq_no);
offset += 2;
if( (gtp_version == 0) && ((gtp_hdr->flags & 0x01) == 0) ) {
flow_label = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_flow_label, tvb, offset, 2, flow_label);
offset += 2;
pdu_no = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_sndcp_number, tvb, offset, 1, pdu_no);
offset += 4;
tid_str = id_to_str(tvb, offset);
proto_tree_add_string(gtp_tree, hf_gtp_tid, tvb, offset, 8, tid_str);
offset += 8;
}
set_actual_length(tvb, offset + gtp_hdr->length);
} else {
switch (gtp_version) {
case 0:
seq_no = tvb_get_ntohs(tvb, offset);
has_SN = TRUE;
proto_tree_add_uint(gtp_tree, hf_gtp_seq_number, tvb, offset, 2, seq_no);
offset += 2;
flow_label = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_flow_label, tvb, offset, 2, flow_label);
offset += 2;
pdu_no = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_sndcp_number, tvb, offset, 1, pdu_no);
offset += 4;
tid_str = id_to_str(tvb, offset);
proto_tree_add_string(gtp_tree, hf_gtp_tid, tvb, offset, 8, tid_str);
offset += 8;
set_actual_length(tvb, offset + gtp_hdr->length);
break;
case 1:
gtp_hdr->teid = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(gtp_tree, hf_gtp_teid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
set_actual_length(tvb, offset + gtp_hdr->length);
if (gtp_hdr->flags & (GTP_E_MASK|GTP_S_MASK|GTP_PN_MASK)) {
if (gtp_hdr->flags & GTP_S_MASK) {
seq_no = tvb_get_ntohs(tvb, offset);
has_SN = TRUE;
proto_tree_add_uint(gtp_tree, hf_gtp_seq_number, tvb, offset, 2, seq_no);
}
offset += 2;
if (gtp_hdr->flags & GTP_PN_MASK) {
pdu_no = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_npdu_number, tvb, offset, 1, pdu_no);
}
offset++;
if (gtp_hdr->flags & GTP_E_MASK) {
next_hdr = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_ext_hdr_next, tvb, offset, 1, next_hdr);
offset++;
while (next_hdr != 0) {
ext_hdr_length = tvb_get_guint8(tvb, offset);
tf = proto_tree_add_item(gtp_tree, hf_gtp_ext_hdr, tvb, offset, ext_hdr_length*4, ENC_NA);
ext_tree = proto_item_add_subtree(tf, ett_gtp_ext_hdr);
ext_hdr_len_item = proto_tree_add_item(ext_tree, hf_gtp_ext_hdr_length, tvb, offset,1, ENC_BIG_ENDIAN);
if (ext_hdr_length == 0) {
expert_add_info_format(pinfo, ext_hdr_len_item, &ei_gtp_ext_length_mal,
"Extension header length is zero");
return tvb_reported_length(tvb);
}
offset++;
switch (next_hdr) {
case GTP_EXT_HDR_PDCP_SN:
if (ext_hdr_length == 1) {
proto_item* ext_item;
ext_hdr_pdcpsn = tvb_get_ntohs(tvb, offset);
ext_item = proto_tree_add_item(ext_tree, hf_gtp_ext_hdr_pdcpsn, tvb, offset, 2, ENC_BIG_ENDIAN);
if (ext_hdr_pdcpsn & 0x700) {
expert_add_info(pinfo, ext_item, &ei_gtp_ext_hdr_pdcpsn);
}
} else {
expert_add_info_format(pinfo, ext_tree, &ei_gtp_ext_length_warn, "The length field for the PDCP SN Extension header should be 1.");
}
break;
case GTP_EXT_HDR_UDP_PORT:
if (ext_hdr_length == 1) {
proto_tree_add_item(ext_tree, hf_gtp_ext_hdr_udp_port, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
expert_add_info_format(pinfo, ext_tree, &ei_gtp_ext_length_warn, "The length field for the UDP Port Extension header should be 1.");
}
break;
case GTP_EXT_HDR_SUSPEND_REQ:
break;
case GTP_EXT_HDR_SUSPEND_RESP:
break;
default:
break;
}
offset += ext_hdr_length*4 - 2;
next_hdr = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ext_tree, hf_gtp_ext_hdr_next, tvb, offset, 1, next_hdr);
offset++;
}
} else
offset++;
}
break;
default:
break;
}
}
if (gtp_hdr->message != GTP_MSG_TPDU) {
mandatory = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
ext_hdr_val = tvb_get_guint8(tvb, offset);
if (g_gtp_etsi_order) {
checked_field = check_field_presence(gtp_hdr->message, ext_hdr_val, &mandatory);
switch (checked_field) {
case -2:
expert_add_info(pinfo, message_item, &ei_gtp_message_not_found);
break;
case -1:
expert_add_info(pinfo, message_item, &ei_gtp_field_not_present);
break;
case 0:
break;
default:
expert_add_info_format(pinfo, message_item, &ei_gtp_wrong_next_field, "[WARNING] wrong next field, should be: %s",
val_to_str_ext_const(checked_field, &gtp_val_ext, "Unknown extension field"));
break;
}
}
i = -1;
while (gtpopt[++i].optcode)
if (gtpopt[i].optcode == ext_hdr_val)
break;
offset = offset + (*gtpopt[i].decode) (tvb, offset, pinfo, gtp_tree);
}
if (has_SN) {
gcrp = gtp_match_response(tvb, pinfo, gtp_tree, seq_no, gtp_hdr->message, gtp_info);
if (gcrp) {
tap_queue_packet(gtp_tap,pinfo,gcrp);
}
}
}
proto_item_set_end (ti, tvb, offset);
if ((gtp_hdr->message == GTP_MSG_TPDU) && dissect_tpdu_as == GTP_TPDU_AS_TPDU) {
if(tvb_reported_length_remaining(tvb, offset) > 0){
proto_tree_add_item(gtp_tree, hf_gtp_tpdu_data, tvb, offset, -1, ENC_NA);
sub_proto = tvb_get_guint8(tvb, offset);
if ((sub_proto >= 0x45) && (sub_proto <= 0x4e)) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(ip_handle, next_tvb, pinfo, tree);
} else if ((sub_proto & 0xf0) == 0x60) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
} else {
if (sub_proto == 0xff) {
control_field = tvb_get_guint8(tvb, offset + 1);
if (control_field == 0x03)
acfield_len = 2;
}
next_tvb = tvb_new_subset_remaining(tvb, offset + acfield_len);
call_dissector(ppp_handle, next_tvb, pinfo, tree);
}
}
col_prepend_fstr(pinfo->cinfo, COL_PROTOCOL, "GTP <");
col_append_str(pinfo->cinfo, COL_PROTOCOL, ">");
}
else if ((gtp_hdr->message == GTP_MSG_TPDU) && dissect_tpdu_as == GTP_TPDU_AS_SYNC) {
next_tvb = tvb_new_subset_remaining(tvb, offset + acfield_len);
call_dissector(sync_handle, next_tvb, pinfo, tree);
col_prepend_fstr(pinfo->cinfo, COL_PROTOCOL, "GTP <");
col_append_str(pinfo->cinfo, COL_PROTOCOL, ">");
}
tap_queue_packet(gtpv1_tap,pinfo, gtp_hdr);
return tvb_reported_length(tvb);
}
static int
dissect_gtpprime(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
void *private_data _U_)
{
return dissect_gtp_common(tvb, pinfo, tree);
}
static int
dissect_gtp(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
void *private_data _U_)
{
guint8 version;
if (!tvb_bytes_exist(tvb, 0, 1)) {
return 0;
}
version = tvb_get_guint8(tvb,0)>>5;
if (version > 2) {
return 0;
}
if (version == 2) {
if (gtpv2_handle) {
call_dissector(gtpv2_handle, tvb, pinfo, tree);
return tvb_reported_length(tvb);
}
}
return dissect_gtp_common(tvb, pinfo, tree);
}
static void
gtp_cleanup(void)
{
gtp_conv_info_t *gtp_info;
for (gtp_info = gtp_info_items; gtp_info != NULL; ) {
gtp_conv_info_t *next;
g_hash_table_destroy(gtp_info->matched);
gtp_info->matched=NULL;
g_hash_table_destroy(gtp_info->unmatched);
gtp_info->unmatched=NULL;
next = gtp_info->next;
g_free(gtp_info);
gtp_info = next;
}
gtp_info_items = NULL;
}
void
proto_register_gtp(void)
{
module_t *gtp_module;
expert_module_t* expert_gtp;
guint i;
guint last_offset;
static hf_register_info hf_gtp[] = {
{&hf_gtp_ie_id,
{ "IE Id", "gtp.ie_id",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtp_val_ext, 0x0,
NULL, HFILL}
},
{&hf_gtp_response_in,
{ "Response In", "gtp.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this GTP request is in this frame", HFILL}
},
{&hf_gtp_response_to,
{ "Response To", "gtp.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the GTP request in this frame", HFILL}
},
{&hf_gtp_time,
{ "Time", "gtp.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the Request and the Response", HFILL}
},
{&hf_gtp_apn,
{ "APN", "gtp.apn",
FT_STRING, BASE_NONE, NULL, 0,
"Access Point Name", HFILL}
},
{&hf_gtp_cause,
{ "Cause", "gtp.cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &cause_type_ext, 0,
"Cause of operation", HFILL}
},
{&hf_gtp_chrg_char,
{ "Charging characteristics", "gtp.chrg_char",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_chrg_char_s,
{ "Spare", "gtp.chrg_char_s",
FT_UINT16, BASE_DEC, NULL, GTP_MASK_CHRG_CHAR_S,
NULL, HFILL}
},
{&hf_gtp_chrg_char_n,
{ "Normal charging", "gtp.chrg_char_n",
FT_UINT16, BASE_DEC, NULL, GTP_MASK_CHRG_CHAR_N,
NULL, HFILL}
},
{&hf_gtp_chrg_char_p,
{ "Prepaid charging", "gtp.chrg_char_p",
FT_UINT16, BASE_DEC, NULL, GTP_MASK_CHRG_CHAR_P,
NULL, HFILL}
},
{&hf_gtp_chrg_char_f,
{ "Flat rate charging", "gtp.chrg_char_f",
FT_UINT16, BASE_DEC, NULL, GTP_MASK_CHRG_CHAR_F,
NULL, HFILL}
},
{&hf_gtp_chrg_char_h,
{ "Hot billing charging", "gtp.chrg_char_h",
FT_UINT16, BASE_DEC, NULL, GTP_MASK_CHRG_CHAR_H,
NULL, HFILL}
},
{&hf_gtp_chrg_char_r,
{ "Reserved", "gtp.chrg_char_r",
FT_UINT16, BASE_DEC, NULL, GTP_MASK_CHRG_CHAR_R,
NULL, HFILL}
},
{&hf_gtp_chrg_id,
{ "Charging ID", "gtp.chrg_id",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_chrg_ipv4,
{ "CG address IPv4", "gtp.chrg_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
"Charging Gateway address IPv4", HFILL}
},
{&hf_gtp_chrg_ipv6,
{ "CG address IPv6", "gtp.chrg_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
"Charging Gateway address IPv6", HFILL}
},
{&hf_gtp_ext_flow_label,
{ "Flow Label Data I", "gtp.ext_flow_label",
FT_UINT16, BASE_HEX, NULL, 0,
"Flow label data", HFILL}
},
{&hf_gtp_ext_id,
{ "Extension identifier", "gtp.ext_id",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0,
"Private Enterprise number", HFILL}
},
{&hf_gtp_ext_val,
{ "Extension value", "gtp.ext_val",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_flags,
{ "Flags", "gtp.flags",
FT_UINT8, BASE_HEX, NULL, 0,
"Ver/PT/Spare...", HFILL}
},
{&hf_gtp_ext_hdr,
{ "Extension header", "gtp.ext_hdr",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_ext_hdr_next,
{ "Next extension header type", "gtp.ext_hdr.next",
FT_UINT8, BASE_HEX, VALS(next_extension_header_fieldvals), 0,
NULL, HFILL}
},
{&hf_gtp_ext_hdr_pdcpsn,
{ "PDCP Sequence Number", "gtp.ext_hdr.pdcp_sn",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_ext_hdr_udp_port,
{ "UDP Port", "gtp.ext_hdr.udp_port",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_ext_hdr_length,
{ "Extension Header Length", "gtp.ext_hdr.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_flags_ver,
{ "Version", "gtp.flags.version",
FT_UINT8, BASE_DEC, VALS(ver_types), GTP_VER_MASK,
"GTP Version", HFILL}
},
{&hf_gtp_prime_flags_ver,
{ "Version", "gtp.prim.flags.version",
FT_UINT8, BASE_DEC,NULL, GTP_VER_MASK,
"GTP' Version", HFILL}
},
{&hf_gtp_flags_pt,
{ "Protocol type", "gtp.flags.payload",
FT_UINT8, BASE_DEC, VALS(pt_types), GTP_PT_MASK,
NULL, HFILL}
},
{&hf_gtp_flags_spare1,
{ "Reserved", "gtp.flags.reserved",
FT_UINT8, BASE_DEC, NULL, GTP_SPARE1_MASK,
"Reserved (shall be sent as '111' )", HFILL}
},
{&hf_gtp_flags_hdr_length,
{ "Header length", "gtp.flags.hdr_length",
FT_BOOLEAN, 8, TFS(&gtp_hdr_length_vals), 0x01,
NULL, HFILL}
},
{&hf_gtp_flags_snn,
{ "Is SNDCP N-PDU included?", "gtp.flags.snn",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), GTP_SNN_MASK,
"Is SNDCP N-PDU LLC Number included? (1 = yes, 0 = no)", HFILL}
},
{&hf_gtp_flags_spare2,
{ "Reserved", "gtp.flags.reserved",
FT_UINT8, BASE_DEC, NULL, GTP_SPARE2_MASK,
"Reserved (shall be sent as '1' )", HFILL}
},
{&hf_gtp_flags_e,
{ "Is Next Extension Header present?", "gtp.flags.e",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), GTP_E_MASK,
"Is Next Extension Header present? (1 = yes, 0 = no)", HFILL}
},
{&hf_gtp_flags_s,
{ "Is Sequence Number present?", "gtp.flags.s",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), GTP_S_MASK,
"Is Sequence Number present? (1 = yes, 0 = no)", HFILL}
},
{&hf_gtp_flags_pn,
{ "Is N-PDU number present?", "gtp.flags.pn",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), GTP_PN_MASK,
"Is N-PDU number present? (1 = yes, 0 = no)", HFILL}
},
{&hf_gtp_flow_ii,
{ "Flow Label Data II", "gtp.flow_ii",
FT_UINT16, BASE_DEC, NULL, 0,
"Downlink flow label data", HFILL}
},
{&hf_gtp_flow_label,
{ "Flow label", "gtp.flow_label",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_flow_sig,
{ "Flow label Signalling", "gtp.flow_sig",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_gsn_addr_len,
{ "GSN Address Length", "gtp.gsn_addr_len",
FT_UINT8, BASE_DEC, NULL, GTP_EXT_GSN_ADDR_LEN_MASK,
NULL, HFILL}
},
{&hf_gtp_gsn_addr_type,
{ "GSN Address Type", "gtp.gsn_addr_type",
FT_UINT8, BASE_DEC, VALS(gsn_addr_type), GTP_EXT_GSN_ADDR_TYPE_MASK,
NULL, HFILL}
},
{&hf_gtp_gsn_ipv4,
{ "GSN address IPv4", "gtp.gsn_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_gsn_ipv6,
{ "GSN address IPv6", "gtp.gsn_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_length,
{ "Length", "gtp.length",
FT_UINT16, BASE_DEC, NULL, 0,
"Length (i.e. number of octets after TID or TEID)", HFILL}
},
{&hf_gtp_map_cause,
{ "MAP cause", "gtp.map_cause",
FT_UINT8, BASE_DEC, VALS(gsm_old_GSMMAPLocalErrorcode_vals), 0,
NULL, HFILL}
},
{&hf_gtp_message_type,
{ "Message Type", "gtp.message",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &gtp_message_type_ext, 0x0,
"GTP Message Type", HFILL}
},
{&hf_gtp_ms_reason,
{ "MS not reachable reason", "gtp.ms_reason",
FT_UINT8, BASE_DEC, VALS(ms_not_reachable_type), 0,
NULL, HFILL}
},
{&hf_gtp_ms_valid,
{ "MS validated", "gtp.ms_valid",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_node_ipv4,
{ "Node address IPv4", "gtp.node_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
"Recommended node address IPv4", HFILL}
},
{&hf_gtp_node_ipv6,
{ "Node address IPv6", "gtp.node_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
"Recommended node address IPv6", HFILL}
},
{&hf_gtp_npdu_number,
{ "N-PDU Number", "gtp.npdu_number",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_nsapi,
{ "NSAPI", "gtp.nsapi",
FT_UINT8, BASE_DEC, NULL, 0x0f,
"Network layer Service Access Point Identifier", HFILL}
},
{&hf_gtp_qos_version,
{ "Version", "gtp.qos_version",
FT_UINT8, BASE_HEX, NULL, 0,
"Version of the QoS Profile", HFILL}
},
{&hf_gtp_qos_spare1,
{ "Spare", "gtp.qos_spare1",
FT_UINT8, BASE_DEC, NULL, GTP_EXT_QOS_SPARE1_MASK,
"Spare (shall be sent as '00' )", HFILL}
},
{&hf_gtp_qos_delay,
{ "QoS delay", "gtp.qos_delay",
FT_UINT8, BASE_DEC, VALS(qos_delay_type), GTP_EXT_QOS_DELAY_MASK,
"Quality of Service Delay Class", HFILL}
},
{&hf_gtp_qos_reliability,
{ "QoS reliability", "gtp.qos_reliability",
FT_UINT8, BASE_DEC, VALS(qos_reliability_type), GTP_EXT_QOS_RELIABILITY_MASK,
"Quality of Service Reliability Class", HFILL}
},
{&hf_gtp_qos_peak,
{ "QoS peak", "gtp.qos_peak",
FT_UINT8, BASE_DEC, VALS(qos_peak_type), GTP_EXT_QOS_PEAK_MASK,
"Quality of Service Peak Throughput", HFILL}
},
{&hf_gtp_qos_spare2,
{ "Spare", "gtp.qos_spare2",
FT_UINT8, BASE_DEC, NULL, GTP_EXT_QOS_SPARE2_MASK,
"Spare (shall be sent as 0)", HFILL}
},
{&hf_gtp_qos_precedence,
{ "QoS precedence", "gtp.qos_precedence",
FT_UINT8, BASE_DEC, VALS(qos_precedence_type), GTP_EXT_QOS_PRECEDENCE_MASK,
"Quality of Service Precedence Class", HFILL}
},
{&hf_gtp_qos_spare3,
{ "Spare", "gtp.qos_spare3",
FT_UINT8, BASE_DEC, NULL, GTP_EXT_QOS_SPARE3_MASK,
"Spare (shall be sent as '000' )", HFILL}
},
{&hf_gtp_qos_mean,
{ "QoS mean", "gtp.qos_mean",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &qos_mean_type_ext, GTP_EXT_QOS_MEAN_MASK,
"Quality of Service Mean Throughput", HFILL}
},
{&hf_gtp_qos_al_ret_priority,
{ "Allocation/Retention priority", "gtp.qos_al_ret_priority",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_qos_traf_class,
{ "Traffic class", "gtp.qos_traf_class",
FT_UINT8, BASE_DEC, VALS(qos_traf_class), GTP_EXT_QOS_TRAF_CLASS_MASK,
NULL, HFILL}
},
{&hf_gtp_qos_del_order,
{ "Delivery order", "gtp.qos_del_order",
FT_UINT8, BASE_DEC, VALS(qos_del_order), GTP_EXT_QOS_DEL_ORDER_MASK,
NULL, HFILL}
},
{&hf_gtp_qos_del_err_sdu,
{ "Delivery of erroneous SDU", "gtp.qos_del_err_sdu",
FT_UINT8, BASE_DEC, VALS(qos_del_err_sdu), GTP_EXT_QOS_DEL_ERR_SDU_MASK,
NULL, HFILL}
},
{&hf_gtp_qos_max_sdu_size,
{ "Maximum SDU size", "gtp.qos_max_sdu_size",
FT_UINT8, BASE_DEC, VALS(qos_max_sdu_size), 0,
NULL, HFILL}
},
{&hf_gtp_qos_max_ul,
{ "Maximum bit rate for uplink", "gtp.qos_max_ul",
FT_UINT8, BASE_DEC, VALS(qos_max_ul), 0,
NULL, HFILL}
},
{&hf_gtp_qos_max_dl,
{ "Maximum bit rate for downlink", "gtp.qos_max_dl",
FT_UINT8, BASE_DEC, VALS(qos_max_dl), 0,
NULL, HFILL}
},
{&hf_gtp_qos_res_ber,
{ "Residual BER", "gtp.qos_res_ber",
FT_UINT8, BASE_DEC, VALS(qos_res_ber), GTP_EXT_QOS_RES_BER_MASK,
"Residual Bit Error Rate", HFILL}
},
{&hf_gtp_qos_sdu_err_ratio,
{ "SDU Error ratio", "gtp.qos_sdu_err_ratio",
FT_UINT8, BASE_DEC, VALS(qos_sdu_err_ratio), GTP_EXT_QOS_SDU_ERR_RATIO_MASK,
NULL,
HFILL}
},
{&hf_gtp_qos_trans_delay,
{ "Transfer delay", "gtp.qos_trans_delay",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &qos_trans_delay_ext, GTP_EXT_QOS_TRANS_DELAY_MASK,
NULL, HFILL}
},
{&hf_gtp_qos_traf_handl_prio,
{ "Traffic handling priority", "gtp.qos_traf_handl_prio",
FT_UINT8, BASE_DEC, VALS(qos_traf_handl_prio), GTP_EXT_QOS_TRAF_HANDL_PRIORITY_MASK,
NULL, HFILL}
},
{&hf_gtp_qos_guar_ul,
{ "Guaranteed bit rate for uplink", "gtp.qos_guar_ul",
FT_UINT8, BASE_DEC, VALS(qos_guar_ul), 0,
NULL, HFILL}
},
{&hf_gtp_qos_guar_dl,
{ "Guaranteed bit rate for downlink", "gtp.qos_guar_dl",
FT_UINT8, BASE_DEC, VALS(qos_guar_dl), 0,
NULL, HFILL}
},
{&hf_gtp_qos_src_stat_desc,
{ "Source Statistics Descriptor", "gtp.src_stat_desc",
FT_UINT8, BASE_DEC, VALS(src_stat_desc_vals), GTP_EXT_QOS_SRC_STAT_DESC_MASK,
NULL, HFILL}
},
{&hf_gtp_qos_sig_ind,
{ "Signalling Indication", "gtp.sig_ind",
FT_BOOLEAN, 8, TFS(&gtp_sig_ind), GTP_EXT_QOS_SIG_IND_MASK,
NULL, HFILL}
},
{ &hf_gtp_qos_arp,
{"Allocation/Retention Priority", "gtp.qos_arp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_qos_arp_pci,
{"Pre-emption Capability (PCI)", "gtp.qos_arp_pci",
FT_BOOLEAN, 16, TFS(&tfs_disabled_enabled), 0x40,
NULL, HFILL}
},
{ &hf_gtp_qos_arp_pl,
{"Priority Level", "gtp.qos_arp_pl",
FT_UINT16, BASE_DEC, NULL, 0x3c,
NULL, HFILL}
},
{ &hf_gtp_qos_arp_pvi,
{"Pre-emption Vulnerability (PVI)", "gtp.qos_arp_pvi",
FT_BOOLEAN, 16, TFS(&tfs_disabled_enabled), 0x01,
NULL, HFILL}
},
{&hf_gtp_qos_qci,
{"QCI", "gtp.qos_qci",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_qos_ul_mbr,
{"Uplink Maximum Bit Rate", "gtp.qos_ul_mbr",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_qos_dl_mbr,
{"Downlink Maximum Bit Rate", "gtp.qos_dl_mbr",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_qos_ul_gbr,
{"Uplink Guaranteed Bit Rate", "gtp.qos_ul_gbr",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_qos_dl_gbr,
{"Downlink Guaranteed Bit Rate", "gtp.qos_dl_gbr",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_qos_ul_apn_ambr,
{"Uplink APN Aggregate Maximum Bit Rate", "gtp.qos_ul_apn_ambr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_qos_dl_apn_ambr,
{"Downlink APN Aggregate Maximum Bit Rate", "gtp.qos_dl_apn_ambr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_pkt_flow_id,
{ "Packet Flow ID", "gtp.pkt_flow_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_ptmsi,
{ "P-TMSI", "gtp.ptmsi",
FT_UINT32, BASE_HEX, NULL, 0,
"Packet-Temporary Mobile Subscriber Identity", HFILL}
},
{&hf_gtp_ptmsi_sig,
{ "P-TMSI Signature", "gtp.ptmsi_sig",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_rab_gtpu_dn,
{ "Downlink GTP-U seq number", "gtp.rab_gtp_dn",
FT_UINT16, BASE_DEC, NULL, 0,
"Downlink GTP-U sequence number", HFILL}
},
{&hf_gtp_rab_gtpu_up,
{ "Uplink GTP-U seq number", "gtp.rab_gtp_up",
FT_UINT16, BASE_DEC, NULL, 0,
"Uplink GTP-U sequence number", HFILL}
},
{&hf_gtp_rab_pdu_dn,
{ "Downlink next PDCP-PDU seq number", "gtp.rab_pdu_dn",
FT_UINT16, BASE_DEC, NULL, 0,
"Downlink next PDCP-PDU sequence number", HFILL}
},
{&hf_gtp_rab_pdu_up,
{ "Uplink next PDCP-PDU seq number", "gtp.rab_pdu_up",
FT_UINT16, BASE_DEC, NULL, 0,
"Uplink next PDCP-PDU sequence number", HFILL}
},
{&hf_gtp_rai_rac,
{ "RAC", "gtp.rac",
FT_UINT8, BASE_DEC, NULL, 0,
"Routing Area Code", HFILL}
},
{&hf_gtp_rai_lac,
{ "LAC", "gtp.lac",
FT_UINT16, BASE_DEC, NULL, 0,
"Location Area Code", HFILL}
},
{ &hf_gtp_tac,
{"TAC", "gtp.tac",
FT_UINT16, BASE_DEC, NULL, 0,
"Tracking Area Code", HFILL}
},
{ &hf_gtp_eci,
{"ECI", "gtp.eci",
FT_UINT32, BASE_DEC, NULL, 0x0FFFFFFF,
"E-UTRAN Cell Identifier", HFILL}
},
{&hf_gtp_ranap_cause,
{ "RANAP cause", "gtp.ranap_cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &ranap_cause_type_ext, 0,
NULL, HFILL}
},
{&hf_gtp_recovery,
{ "Recovery", "gtp.recovery",
FT_UINT8, BASE_DEC, NULL, 0,
"Restart counter", HFILL}
},
{&hf_gtp_reorder,
{ "Reordering required", "gtp.reorder",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_rnc_ipv4,
{ "RNC address IPv4", "gtp.rnc_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
"Radio Network Controller address IPv4", HFILL}
},
{&hf_gtp_rnc_ipv6,
{ "RNC address IPv6", "gtp.rnc_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
"Radio Network Controller address IPv6", HFILL}
},
{&hf_gtp_rp,
{ "Radio Priority", "gtp.rp",
FT_UINT8, BASE_DEC, NULL, GTPv1_EXT_RP_MASK,
"Radio Priority for uplink tx", HFILL}
},
{&hf_gtp_rp_nsapi,
{ "NSAPI in Radio Priority", "gtp.rp_nsapi",
FT_UINT8, BASE_DEC, NULL, GTPv1_EXT_RP_NSAPI_MASK,
"Network layer Service Access Point Identifier in Radio Priority", HFILL}
},
{&hf_gtp_rp_sms,
{ "Radio Priority SMS", "gtp.rp_sms",
FT_UINT8, BASE_DEC, NULL, 0,
"Radio Priority for MO SMS", HFILL}
},
{&hf_gtp_rp_spare,
{ "Reserved", "gtp.rp_spare",
FT_UINT8, BASE_DEC, NULL, GTPv1_EXT_RP_SPARE_MASK,
"Spare bit", HFILL}
},
{&hf_gtp_sel_mode,
{ "Selection mode", "gtp.sel_mode",
FT_UINT8, BASE_DEC, VALS(sel_mode_type), 0x03,
NULL, HFILL}
},
{&hf_gtp_seq_number,
{ "Sequence number", "gtp.seq_number",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_sndcp_number,
{ "SNDCP N-PDU LLC Number", "gtp.sndcp_number",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_tear_ind,
{ "Teardown Indicator", "gtp.tear_ind",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_teid,
{ "TEID", "gtp.teid",
FT_UINT32, BASE_HEX, NULL, 0,
"Tunnel Endpoint Identifier", HFILL}
},
{&hf_gtp_teid_cp,
{ "TEID Control Plane", "gtp.teid_cp",
FT_UINT32, BASE_HEX, NULL, 0,
"Tunnel Endpoint Identifier Control Plane", HFILL}
},
{&hf_gtp_ulink_teid_cp,
{ "Uplink TEID Control Plane", "gtp.ulink_teid_cp",
FT_UINT32, BASE_HEX, NULL, 0,
"Uplink Tunnel Endpoint Identifier Control Plane", HFILL}
},
{&hf_gtp_teid_data,
{ "TEID Data I", "gtp.teid_data",
FT_UINT32, BASE_HEX, NULL, 0,
"Tunnel Endpoint Identifier Data I", HFILL}
},
{&hf_gtp_ulink_teid_data,
{ "Uplink TEID Data I", "gtp.ulink_teid_data",
FT_UINT32, BASE_HEX, NULL, 0,
"UplinkTunnel Endpoint Identifier Data I", HFILL}
},
{&hf_gtp_teid_ii,
{ "TEID Data II", "gtp.teid_ii",
FT_UINT32, BASE_HEX, NULL, 0,
"Tunnel Endpoint Identifier Data II", HFILL}
},
{&hf_gtp_tft_code,
{ "TFT operation code", "gtp.tft_code",
FT_UINT8, BASE_DEC, VALS(tft_code_type), GTPv1_TFT_CODE_MASK,
NULL, HFILL}
},
{&hf_gtp_tft_spare,
{ "TFT spare bit", "gtp.tft_spare",
FT_UINT8, BASE_DEC, NULL, GTPv1_TFT_SPARE_MASK,
NULL, HFILL}
},
{&hf_gtp_tft_number,
{ "Number of packet filters", "gtp.tft_number",
FT_UINT8, BASE_DEC, NULL, GTPv1_TFT_NUMBER_MASK,
NULL, HFILL}
},
{&hf_gtp_tft_eval,
{ "Evaluation precedence", "gtp.tft_eval",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_tft_content_id,
{ "Content ID", "gtp.tft_content_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_tid,
{ "TID", "gtp.tid",
FT_STRING, BASE_NONE, NULL, 0,
"Tunnel Identifier", HFILL}
},
{&hf_gtp_tlli,
{ "TLLI", "gtp.tlli",
FT_UINT32, BASE_HEX, NULL, 0,
"Temporary Logical Link Identity", HFILL}
},
{&hf_gtp_tr_comm,
{ "Packet transfer command", "gtp.tr_comm",
FT_UINT8, BASE_DEC, VALS(tr_comm_type), 0,
NULL, HFILL}
},
{&hf_gtp_trace_ref,
{ "Trace reference", "gtp.trace_ref",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_trace_type,
{ "Trace type", "gtp.trace_type",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_user_addr_pdp_org,
{ "PDP type organization", "gtp.user_addr_pdp_org",
FT_UINT8, BASE_DEC, VALS(pdp_org_type), 0,
NULL, HFILL}
},
{&hf_gtp_user_addr_pdp_type,
{ "PDP type number", "gtp.user_addr_pdp_type",
FT_UINT8, BASE_HEX, VALS(pdp_type), 0,
NULL, HFILL}
},
{&hf_gtp_user_ipv4,
{ "End user address IPv4", "gtp.user_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_user_ipv6,
{ "End user address IPv6", "gtp.user_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_gtp_security_mode,
{ "Security Mode", "gtp.security_mode",
FT_UINT8, BASE_DEC, VALS(mm_sec_modep), 0xc0,
NULL, HFILL}
},
{&hf_gtp_no_of_vectors,
{ "No of Vectors", "gtp.no_of_vectors",
FT_UINT8, BASE_DEC, NULL, 0x38,
NULL, HFILL}
},
{&hf_gtp_cipher_algorithm,
{ "Cipher Algorithm", "gtp.cipher_algorithm",
FT_UINT8, BASE_DEC, VALS(gtp_cipher_algorithm), 0x07,
NULL, HFILL}
},
{&hf_gtp_cksn_ksi,
{ "Ciphering Key Sequence Number (CKSN)/Key Set Identifier (KSI)", "gtp.cksn_ksi",
FT_UINT8, BASE_DEC, NULL, 0x07,
"CKSN/KSI", HFILL}
},
{&hf_gtp_cksn,
{ "Ciphering Key Sequence Number (CKSN)", "gtp.cksn",
FT_UINT8, BASE_DEC, NULL, 0x07,
"CKSN", HFILL}
},
{&hf_gtp_ksi,
{ "Key Set Identifier (KSI)", "gtp.ksi",
FT_UINT8, BASE_DEC, NULL, 0x07,
"KSI", HFILL}
},
{&hf_gtp_ext_length,
{ "Length", "gtp.ext_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"IE Length", HFILL}
},
{&hf_gtp_utran_field,
{ "UTRAN Transparent Field", "gtp.utran_field",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_ext_apn_res,
{ "Restriction Type", "gtp.ext_apn_res",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_ext_rat_type,
{ "RAT Type", "gtp.ext_rat_type",
FT_UINT8, BASE_DEC, VALS(gtp_ext_rat_type_vals), 0x0,
NULL, HFILL}
},
{&hf_gtp_ext_geo_loc_type,
{ "Geographic Location Type", "gtp.ext_geo_loc_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_ext_sac,
{ "SAC", "gtp.ext_sac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_ext_imeisv,
{ "IMEI(SV)", "gtp.ext_imeisv",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_target_rnc_id,
{ "targetRNC-ID", "gtp.targetRNC_ID",
FT_UINT16, BASE_HEX, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_gtp_target_ext_rnc_id,
{ "Extended RNC-ID", "gtp.target_ext_RNC_ID",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_gtp_bssgp_cause,
{ "BSSGP Cause", "gtp.bssgp_cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &bssgp_cause_vals_ext, 0,
NULL, HFILL}
},
{ &hf_gtp_bssgp_ra_discriminator,
{ "Routing Address Discriminator", "gtp.bssgp.rad",
FT_UINT8, BASE_DEC, VALS(gtp_bssgp_ra_discriminator_vals), 0x0f,
NULL, HFILL }
},
{&hf_gtp_sapi,
{ "PS Handover XID SAPI", "gtp.ps_handover_xid_sapi",
FT_UINT8, BASE_DEC, NULL, 0x0F,
"SAPI", HFILL}
},
{&hf_gtp_xid_par_len,
{ "PS Handover XID parameter length", "gtp.ps_handover_xid_par_len",
FT_UINT8, BASE_DEC, NULL, 0xFF,
"XID parameter length", HFILL}
},
{&hf_gtp_earp_pvi,
{ "PVI Pre-emption Vulnerability", "gtp.EARP_pre_emption_par_vulnerability",
FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled), 0x01,
NULL, HFILL}
},
{&hf_gtp_earp_pl,
{ "PL Priority Level", "gtp.EARP_priority_level",
FT_UINT8, BASE_DEC, NULL, 0x3C,
NULL, HFILL}
},
{&hf_gtp_earp_pci,
{ "PCI Pre-emption Capability", "gtp.EARP_pre_emption_Capability",
FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled), 0x40,
NULL, HFILL}
},
{&hf_gtp_cdr_app,
{ "Application Identifier", "gtp.cdr_app",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL}
},
{ &hf_gtp_cdr_rel,
{ "Release Identifier", "gtp.cdr_rel",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL}
},
{ &hf_gtp_cdr_ver,
{ "Version Identifier", "gtp.cdr_ver",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_cdr_length,
{ "Length", "gtp.cdr_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_cdr_context,
{ "Context", "gtp.cdr_context",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_cmn_flg_ppc,
{ "Prohibit Payload Compression", "gtp.cmn_flg.ppc",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{&hf_gtp_cmn_flg_mbs_srv_type,
{ "MBMS Service Type", "gtp.cmn_flg.mbs_srv_type",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{&hf_gtp_cmn_flg_mbs_ran_pcd_rdy,
{ "RAN Procedures Ready", "gtp.cmn_flg.mbs_ran_pcd_rdy",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL}
},
{&hf_gtp_cmn_flg_mbs_cnt_inf,
{ "MBMS Counting Information", "gtp.cmn_flg.mbs_cnt_inf",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL}
},
{&hf_gtp_cmn_flg_no_qos_neg,
{ "No QoS negotiation", "gtp.cmn_flg.no_qos_neg",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL}
},
{&hf_gtp_cmn_flg_nrsn,
{ "NRSN bit field", "gtp.cmn_flg.nrsn",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL}
},
{&hf_gtp_cmn_flg_upgrd_qos_sup,
{ "Upgrade QoS Supported", "gtp.cmn_flg.upgrd_qos_sup",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL}
},
{&hf_gtp_cmn_flg_dual_addr_bearer_flg,
{ "Dual Address Bearer Flag", "gtp.cmn_flg.dual_addr_bearer_flg",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL}
},
{&hf_gtp_tmgi,
{ "Temporary Mobile Group Identity (TMGI)", "gtp.tmgi",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_no_of_mbms_sa_codes,
{ "Number of MBMS service area codes", "gtp.no_of_mbms_sa_codes",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number N of MBMS service area codes", HFILL}
},
{&hf_gtp_mbms_ses_dur_days,
{ "Estimated session duration days", "gtp.mbms_ses_dur_days",
FT_UINT24, BASE_DEC, NULL, 0x00007F,
NULL, HFILL}
},
{&hf_gtp_mbms_ses_dur_s,
{ "Estimated session duration seconds", "gtp.mbms_ses_dur_s",
FT_UINT24, BASE_DEC, NULL, 0xFFFF80,
NULL, HFILL}
},
{&hf_gtp_mbms_sa_code,
{ "MBMS service area code", "gtp.mbms_sa_code",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_mbs_2g_3g_ind,
{ "MBMS 2G/3G Indicator", "gtp.mbs_2g_3g_ind",
FT_UINT8, BASE_DEC, VALS(gtp_mbs_2g_3g_ind_vals), 0x0,
NULL, HFILL}
},
{&hf_gtp_time_2_dta_tr,
{ "Time to MBMS Data Transfer", "gtp.time_2_dta_tr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_ext_ei,
{ "Error Indication (EI)", "gtp.ei",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL}
},
{&hf_gtp_ext_gcsi,
{ "GPRS-CSI (GCSI)", "gtp.gcsi",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL}
},
{ &hf_gtp_ext_dti,
{ "Direct Tunnel Indicator (DTI)", "gtp.dti",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL}
},
{ &hf_gtp_ra_prio_lcs,
{ "Radio Priority LCS", "gtp.raplcs",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL}
},
{ &hf_gtp_bcm,
{ "Bearer Control Mode", "gtp.bcm",
FT_UINT8, BASE_DEC, VALS(gtp_pdp_bcm_type_vals), 0,
NULL, HFILL}
},
{ &hf_gtp_fqdn,
{ "FQDN", "gtp.fqdn",
FT_STRING, BASE_NONE, NULL, 0,
"Fully Qualified Domain Name", HFILL}
},
{ &hf_gtp_rim_routing_addr,
{ "RIM Routing Address value", "gtp.rim_routing_addr_val",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_gtp_mbms_flow_id,
{ "MBMS Flow Identifier", "gtp.mbms_flow_id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_gtp_mbms_dist_indic,
{ "Distribution Indication", "gtp.mbms_dist_indic",
FT_UINT8, BASE_DEC, VALS(gtp_mbms_dist_indic_vals), 0x03,
NULL, HFILL}
},
{ &hf_gtp_ext_apn_ambr_ul,
{ "APN-AMBR for Uplink", "gtp.apn_ambr_ul",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_ext_apn_ambr_dl,
{ "APN-AMBR for Downlink", "gtp.apn_ambr_dl",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_ext_sub_ue_ambr_ul,
{ "Subscribed UE-AMBR for Uplink", "gtp.sub_ue_ambr_ul",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_ext_sub_ue_ambr_dl,
{ "Subscribed UE-AMBR for Downlink", "gtp.sub_ue_ambr_dl",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_ext_auth_ue_ambr_ul,
{ "Authorized UE-AMBR for Uplink", "gtp.auth_ue_ambr_ul",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_ext_auth_ue_ambr_dl,
{ "Authorized UE-AMBR for Downlink", "gtp.auth_ue_ambr_dl",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_ext_auth_apn_ambr_ul,
{ "Authorized APN-AMBR for Uplink", "gtp.auth_apn_ambr_ul",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_ext_auth_apn_ambr_dl,
{ "Authorized APN-AMBR for Downlink", "gtp.auth_apn_ambr_dl",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_ext_ggsn_back_off_time_units,
{ "Timer unit", "gtp.ggsn_back_off_time_units",
FT_UINT8, BASE_DEC, VALS(gtp_ggsn_back_off_time_units_vals), 0xe0,
NULL, HFILL}
},
{ &hf_gtp_ext_ggsn_back_off_timer,
{ "Timer value", "gtp.ggsn_back_off_timer",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL}
},
{ &hf_gtp_higher_br_16mb_flg,
{ "Higher bitrates than 16 Mbps flag", "gtp.higher_br_16mb_flg",
FT_UINT8, BASE_DEC, VALS(gtp_higher_br_16mb_flg_vals), 0x0,
NULL, HFILL}
},
{ &hf_gtp_max_mbr_apn_ambr_ul,
{ "Max MBR/APN-AMBR for uplink", "gtp.max_mbr_apn_ambr_ul",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_max_mbr_apn_ambr_dl,
{ "Max MBR/APN-AMBR for downlink", "gtp.max_mbr_apn_ambr_dl",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_rand, { "RAND", "gtp.rand", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_sres, { "SRES", "gtp.sres", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_kc, { "Kc", "gtp.kc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_xres_length, { "XRES length", "gtp.xres_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_xres, { "XRES", "gtp.xres", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_quintuplet_ciphering_key, { "Quintuplet Ciphering Key", "gtp.quintuplet_ciphering_key", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_quintuplet_integrity_key, { "Quintuplet Integrity Key", "gtp.quintuplet_integrity_key", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_authentication_length, { "Authentication length", "gtp.authentication_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_auth, { "AUTH", "gtp.auth", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_ciphering_key_ck, { "Ciphering key CK", "gtp.ciphering_key_ck", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_integrity_key_ik, { "Integrity key IK", "gtp.integrity_key_ik", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_quintuplets_length, { "Quintuplets length", "gtp.quintuplets_length", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_ciphering_key_kc, { "Ciphering key Kc", "gtp.ciphering_key_kc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_container_length, { "Container length", "gtp.container_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_extended_end_user_address, { "Extended End User Address", "gtp.extended_end_user_address", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80, NULL, HFILL }},
{ &hf_gtp_vplmn_address_allowed, { "VPLMN address allowed", "gtp.vplmn_address_allowed", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40, NULL, HFILL }},
{ &hf_gtp_activity_status_indicator, { "Activity Status Indicator", "gtp.activity_status_indicator", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20, NULL, HFILL }},
{ &hf_gtp_reordering_required, { "Reordering required", "gtp.reordering_required", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10, NULL, HFILL }},
{ &hf_gtp_pdp_cntxt_sapi, { "SAPI", "gtp.pdp_cntxt.sapi", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{ &hf_gtp_sequence_number_down, { "Sequence number down", "gtp.sequence_number_down", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_sequence_number_up, { "Sequence number up", "gtp.sequence_number_up", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_send_n_pdu_number, { "Send N-PDU number", "gtp.send_n_pdu_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_receive_n_pdu_number, { "Receive N-PDU number", "gtp.receive_n_pdu_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_uplink_flow_label_signalling, { "Uplink flow label signalling", "gtp.uplink_flow_label_signalling", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_pdp_context_identifier, { "PDP context identifier", "gtp.pdp_context_identifier", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_pdp_organization, { "PDP organization", "gtp.pdp_organization", FT_UINT8, BASE_DEC, VALS(pdp_type), 0x0F, NULL, HFILL }},
{ &hf_gtp_pdp_type, { "PDP type", "gtp.pdp_type", FT_UINT8, BASE_DEC, VALS(pdp_type), 0x0, NULL, HFILL }},
{ &hf_gtp_pdp_address_length, { "PDP address length", "gtp.pdp_address_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_pdp_address_ipv4, { "PDP address", "gtp.pdp_address.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_pdp_address_ipv6, { "PDP address", "gtp.pdp_address.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_ggsn_address_length, { "GGSN address length", "gtp.ggsn_address_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_ggsn_address_for_control_plane, { "GGSN Address for control plane", "gtp.ggsn_address_for_control_plane", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_ggsn_address_for_user_traffic, { "GGSN Address for User Traffic", "gtp.ggsn_address_for_user_traffic", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_ggsn_2_address_length, { "GGSN 2 address length", "gtp.ggsn_2_address_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_ggsn_2_address_ipv4, { "GGSN 2 address", "gtp.ggsn_2_address.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_ggsn_2_address_ipv6, { "GGSN 2 address", "gtp.ggsn_2_address.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_apn_length, { "APN length", "gtp.apn_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_transaction_identifier, { "Transaction identifier", "gtp.transaction_identifier", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_gsn_address_length, { "GSN address length", "gtp.gsn_address_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_gsn_address_information_element_length, { "GSN address Information Element length", "gtp.gsn_address_information_element_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_tft_length, { "TFT length", "gtp.tft_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_tft_packet_filter_id, { "Packet filter id", "gtp.tft_packet_filter_id", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_tft_content_length, { "Content length", "gtp.tft_content_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_rab_setup_length, { "RAB setup length", "gtp.rab_setup_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_timezone, { "Timezone", "gtp.timezone", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_timezone_dst, { "DST", "gtp.timezone_dst", FT_UINT8, BASE_DEC, VALS(daylight_saving_time_vals), 0x03, NULL, HFILL }},
{ &hf_gtp_rfsp_index, { "RFSP Index", "gtp.rfsp_index", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_fqdn_length, { "FQDN length", "gtp.fqdn_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_number_of_data_records, { "Number of data records", "gtp.number_of_data_records", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_data_record_format, { "Data record format", "gtp.data_record_format", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_node_address_length, { "Node address length", "gtp.node_address_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_seq_num_released, { "Sequence number released", "gtp.seq_num_released", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_seq_num_canceled, { "Sequence number cancelled", "gtp.seq_num_canceled", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_requests_responded, { "Requests responded", "gtp.requests_responded", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_hyphen_separator, { "Hyphen separator: -", "gtp.hyphen_separator", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_ms_network_cap_content_len, { "Length of MS network capability contents", "gtp.ms_network_cap_content_len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_iei, { "IEI", "gtp.iei", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_iei_mobile_id_len, { "Length", "gtp.iei.mobile_id_len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_qos_umts_length, { "Length", "gtp.qos_umts_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_num_ext_hdr_types, { "Number of Extension Header Types in list (i.e., length)", "gtp.num_ext_hdr_types", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtp_ext_hdr_type, { "Extension Header Type", "gtp.ext_hdr_type", FT_UINT8, BASE_DEC, VALS(next_extension_header_fieldvals), 0x0, NULL, HFILL }},
{ &hf_gtp_tpdu_data, { "T-PDU Data", "gtp.tpdu_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_gtp_ext_enb_type, { "enb_type", "gtp.enb_type", FT_UINT8, BASE_DEC, VALS(gtp_enb_type_vals), 0x0, NULL, HFILL } },
{ &hf_gtp_macro_enodeb_id,
{ "Macro eNodeB ID", "gtp.macro_enodeb_id",
FT_UINT24, BASE_HEX, NULL, 0x0fffff,
NULL, HFILL }
},
{ &hf_gtp_home_enodeb_id,
{ "Home eNodeB ID", "gtp.home_enodeb_id",
FT_UINT32, BASE_HEX, NULL, 0x0fffffff,
NULL, HFILL }
},
};
static ei_register_info ei[] = {
{ &ei_gtp_ext_length_mal, { "gtp.ext_length.invalid", PI_MALFORMED, PI_ERROR, "Malformed length", EXPFILL }},
{ &ei_gtp_ext_hdr_pdcpsn, { "gtp.ext_hdr.pdcp_sn.non_zero", PI_PROTOCOL, PI_NOTE, "3GPP TS 29.281 v9.0.0: When used between two eNBs at the X2 interface in E-UTRAN, bits 5-8 of octet 2 are spare. The meaning of the spare bits shall be set to zero.", EXPFILL }},
{ &ei_gtp_ext_length_warn, { "gtp.ext_length.invalid", PI_PROTOCOL, PI_WARN, "Length warning", EXPFILL }},
{ &ei_gtp_undecoded, { "gtp.undecoded", PI_UNDECODED, PI_WARN, "Data not decoded yet", EXPFILL }},
{ &ei_gtp_message_not_found, { "gtp.message_not_found", PI_PROTOCOL, PI_WARN, "Message not found", EXPFILL }},
{ &ei_gtp_field_not_present, { "gtp.field_not_present", PI_PROTOCOL, PI_WARN, "Field not present", EXPFILL }},
{ &ei_gtp_wrong_next_field, { "gtp.wrong_next_field", PI_PROTOCOL, PI_WARN, "Wrong next field", EXPFILL }},
{ &ei_gtp_field_not_support_in_version, { "gtp.field_not_support_in_version", PI_PROTOCOL, PI_WARN, "GTP version not supported for field", EXPFILL }},
{ &ei_gtp_guaranteed_bit_rate_value, { "gtp.guaranteed_bit_rate_value", PI_PROTOCOL, PI_NOTE, "Use the value indicated by the Guaranteed bit rate", EXPFILL }},
{ &ei_gtp_max_bit_rate_value, { "gtp.max_bit_rate_value", PI_PROTOCOL, PI_NOTE, "Use the value indicated by the Maximum bit rate", EXPFILL }},
{ &ei_gtp_ext_geo_loc_type, { "gtp.ext_geo_loc_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown Location type data", EXPFILL }},
{ &ei_gtp_iei, { "gtp.iei.unknown", PI_PROTOCOL, PI_WARN, "Unknown IEI - Later spec than TS 29.060 9.4.0 used?", EXPFILL }},
{ &ei_gtp_unknown_extention_header, { "gtp.unknown_extention_header", PI_PROTOCOL, PI_WARN, "Unknown extension header", EXPFILL }},
};
#define GTP_NUM_INDIVIDUAL_ELEMS 29
static gint *ett_gtp_array[GTP_NUM_INDIVIDUAL_ELEMS + NUM_GTP_IES];
ett_gtp_array[0] = &ett_gtp;
ett_gtp_array[1] = &ett_gtp_flags;
ett_gtp_array[2] = &ett_gtp_ext;
ett_gtp_array[3] = &ett_gtp_cdr_dr;
ett_gtp_array[4] = &ett_gtp_qos;
ett_gtp_array[5] = &ett_gtp_qos_arp;
ett_gtp_array[6] = &ett_gtp_uli_rai;
ett_gtp_array[7] = &ett_gtp_flow_ii;
ett_gtp_array[8] = &ett_gtp_ext_hdr;
ett_gtp_array[9] = &ett_gtp_rp;
ett_gtp_array[10] = &ett_gtp_pkt_flow_id;
ett_gtp_array[11] = &ett_gtp_data_resp;
ett_gtp_array[12] = &ett_gtp_cdr_ver;
ett_gtp_array[13] = &ett_gtp_tmgi;
ett_gtp_array[14] = &ett_gtp_trip;
ett_gtp_array[15] = &ett_gtp_quint;
ett_gtp_array[16] = &ett_gtp_drx;
ett_gtp_array[17] = &ett_gtp_net_cap;
ett_gtp_array[18] = &ett_gtp_can_pack;
ett_gtp_array[19] = &ett_gtp_proto;
ett_gtp_array[20] = &ett_gtp_gsn_addr;
ett_gtp_array[21] = &ett_gtp_tft;
ett_gtp_array[22] = &ett_gtp_tft_pf;
ett_gtp_array[23] = &ett_gtp_tft_flags;
ett_gtp_array[24] = &ett_gtp_rab_setup;
ett_gtp_array[25] = &ett_gtp_hdr_list;
ett_gtp_array[26] = &ett_gtp_rel_pack;
ett_gtp_array[27] = &ett_gtp_node_addr;
ett_gtp_array[28] = &ett_gtp_mm_cntxt;
last_offset = GTP_NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_GTP_IES; i++, last_offset++)
{
ett_gtp_ies[i] = -1;
ett_gtp_array[last_offset] = &ett_gtp_ies[i];
}
proto_gtp = proto_register_protocol("GPRS Tunneling Protocol", "GTP", "gtp");
proto_gtpprime = proto_register_protocol("GPRS Tunneling Protocol Prime", "GTP (Prime)", "gtpprime");
proto_register_field_array(proto_gtp, hf_gtp, array_length(hf_gtp));
proto_register_subtree_array(ett_gtp_array, array_length(ett_gtp_array));
expert_gtp = expert_register_protocol(proto_gtp);
expert_register_field_array(expert_gtp, ei, array_length(ei));
gtp_module = prefs_register_protocol(proto_gtp, proto_reg_handoff_gtp);
prefs_register_uint_preference(gtp_module, "v0_port", "GTPv0 and GTP' port", "GTPv0 and GTP' port (default 3386)", 10, &g_gtpv0_port);
prefs_register_uint_preference(gtp_module, "v1c_port", "GTPv1 or GTPv2 control plane (GTP-C, GTPv2-C) port", "GTPv1 and GTPv2 control plane port (default 2123)", 10,
&g_gtpv1c_port);
prefs_register_uint_preference(gtp_module, "v1u_port", "GTPv1 user plane (GTP-U) port", "GTPv1 user plane port (default 2152)", 10,
&g_gtpv1u_port);
prefs_register_enum_preference(gtp_module, "dissect_tpdu_as",
"Dissect T-PDU as",
"Dissect T-PDU as",
&dissect_tpdu_as,
gtp_decode_tpdu_as,
FALSE);
prefs_register_obsolete_preference(gtp_module, "v0_dissect_cdr_as");
prefs_register_obsolete_preference(gtp_module, "v0_check_etsi");
prefs_register_obsolete_preference(gtp_module, "v1_check_etsi");
prefs_register_bool_preference(gtp_module, "check_etsi", "Compare GTP order with ETSI", "GTP ETSI order", &g_gtp_etsi_order);
prefs_register_obsolete_preference(gtp_module, "ppp_reorder");
prefs_register_obsolete_preference(gtp_module, "dissect_tpdu");
prefs_register_bool_preference(gtp_module, "dissect_gtp_over_tcp", "Dissect GTP over TCP", "Dissect GTP over TCP", &g_gtp_over_tcp);
new_register_dissector("gtp", dissect_gtp, proto_gtp);
new_register_dissector("gtpprime", dissect_gtpprime, proto_gtpprime);
gtp_priv_ext_dissector_table = register_dissector_table("gtp.priv_ext", "GTP PRIVATE EXT", FT_UINT16, BASE_DEC);
gtp_cdr_fmt_dissector_table = register_dissector_table("gtp.cdr_fmt", "GTP DATA RECORD TYPE", FT_UINT16, BASE_DEC);
register_cleanup_routine(gtp_cleanup);
gtp_tap = register_tap("gtp");
gtpv1_tap = register_tap("gtpv1");
register_srt_table(proto_gtp, NULL, 1, gtpstat_packet, gtpstat_init, NULL);
}
void
proto_reg_handoff_gtp(void)
{
static gboolean Initialized = FALSE;
static dissector_handle_t gtp_handle, gtp_prime_handle;
static gboolean gtp_over_tcp;
static guint gtpv0_port;
static guint gtpv1c_port;
static guint gtpv1u_port;
if (!Initialized) {
gtp_handle = find_dissector("gtp");
gtp_prime_handle = find_dissector("gtpprime");
ppp_subdissector_table = find_dissector_table("ppp.protocol");
radius_register_avp_dissector(VENDOR_THE3GPP, 5, dissect_radius_qos_umts);
radius_register_avp_dissector(VENDOR_THE3GPP, 12, dissect_radius_selection_mode);
radius_register_avp_dissector(VENDOR_THE3GPP, 22, dissect_radius_user_loc);
ip_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
ppp_handle = find_dissector("ppp");
sync_handle = find_dissector("sync");
gtpcdr_handle = find_dissector("gtpcdr");
sndcpxid_handle = find_dissector("sndcpxid");
data_handle = find_dissector("data");
gtpv2_handle = find_dissector("gtpv2");
bssgp_handle = find_dissector("bssgp");
bssap_pdu_type_table = find_dissector_table("bssap.pdu_type");
dissector_add_uint("diameter.3gpp", 5, new_create_dissector_handle(dissect_diameter_3gpp_qosprofile, proto_gtp));
dissector_add_uint("diameter.3gpp", 903, new_create_dissector_handle(dissect_gtp_3gpp_mbms_service_area, proto_gtp));
dissector_add_uint("diameter.3gpp", 904, new_create_dissector_handle(dissect_gtp_mbms_ses_dur, proto_gtp));
dissector_add_uint("diameter.3gpp", 911, new_create_dissector_handle(dissect_gtp_mbms_time_to_data_tr, proto_gtp));
Initialized = TRUE;
} else {
dissector_delete_uint("udp.port", gtpv0_port, gtp_prime_handle);
dissector_delete_uint("udp.port", gtpv1c_port, gtp_handle);
dissector_delete_uint("udp.port", gtpv1u_port, gtp_handle);
if (gtp_over_tcp) {
dissector_delete_uint("tcp.port", gtpv0_port, gtp_prime_handle);
dissector_delete_uint("tcp.port", gtpv1c_port, gtp_handle);
dissector_delete_uint("tcp.port", gtpv1u_port, gtp_handle);
}
}
gtp_over_tcp = g_gtp_over_tcp;
gtpv0_port = g_gtpv0_port;
gtpv1c_port = g_gtpv1c_port;
gtpv1u_port = g_gtpv1u_port;
dissector_add_uint("udp.port", g_gtpv0_port, gtp_prime_handle);
dissector_add_uint("udp.port", g_gtpv1c_port, gtp_handle);
dissector_add_uint("udp.port", g_gtpv1u_port, gtp_handle);
if (g_gtp_over_tcp) {
dissector_add_uint("tcp.port", g_gtpv0_port, gtp_prime_handle);
dissector_add_uint("tcp.port", g_gtpv1c_port, gtp_handle);
dissector_add_uint("tcp.port", g_gtpv1u_port, gtp_handle);
}
}
