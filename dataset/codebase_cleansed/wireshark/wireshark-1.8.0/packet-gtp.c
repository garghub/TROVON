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
gtp_match_response(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, gint seq_nr, guint msgtype)
{
gtp_msg_hash_t gcr, *gcrp = NULL;
gtp_conv_info_t *gtp_info = (gtp_conv_info_t *)pinfo->private_data;
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
gcrp = se_new(gtp_msg_hash_t);
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
decode_gtp_imsi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
const gchar *imsi_str;
imsi_str = tvb_bcd_dig_to_ep_str( tvb, offset+1, 8, NULL, FALSE);
proto_tree_add_string(tree, hf_gtp_imsi, tvb, offset+1, 8, imsi_str);
return 9;
}
static int
decode_gtp_rai(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree *ext_tree_rai;
proto_item *te;
te = proto_tree_add_text(tree, tvb, offset, 1, "%s", val_to_str_ext_const(GTP_EXT_RAI, &gtp_val_ext, "Unknown message"));
ext_tree_rai = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_RAI]);
dissect_e212_mcc_mnc(tvb, pinfo, ext_tree_rai, offset+1, TRUE);
proto_tree_add_uint(ext_tree_rai, hf_gtp_rai_lac, tvb, offset + 4, 2, tvb_get_ntohs(tvb, offset + 4));
proto_tree_add_uint(ext_tree_rai, hf_gtp_rai_rac, tvb, offset + 6, 1, tvb_get_guint8(tvb, offset + 6));
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
proto_item *te;
spare1 = tvb_get_guint8(tvb, offset) & GTP_EXT_QOS_SPARE1_MASK;
delay = tvb_get_guint8(tvb, offset) & GTP_EXT_QOS_DELAY_MASK;
reliability = tvb_get_guint8(tvb, offset) & GTP_EXT_QOS_RELIABILITY_MASK;
peak = tvb_get_guint8(tvb, offset + 1) & GTP_EXT_QOS_PEAK_MASK;
spare2 = tvb_get_guint8(tvb, offset + 1) & GTP_EXT_QOS_SPARE2_MASK;
precedence = tvb_get_guint8(tvb, offset + 1) & GTP_EXT_QOS_PRECEDENCE_MASK;
spare3 = tvb_get_guint8(tvb, offset + 2) & GTP_EXT_QOS_SPARE3_MASK;
mean = tvb_get_guint8(tvb, offset + 2) & GTP_EXT_QOS_MEAN_MASK;
te = proto_tree_add_text(tree, tvb, offset - adjust, 3 + adjust, "%s: delay: %u, reliability: %u, peak: %u, precedence: %u, mean: %u",
qos_str, (delay >> 3) & 0x07, reliability, (peak >> 4) & 0x0F, precedence, mean);
ext_tree_qos = proto_item_add_subtree(te, ett_gtp_qos);
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
proto_item *te;
te = proto_tree_add_text(tree, tvb, offset, 29, "%s", val_to_str_ext_const(GTP_EXT_AUTH_TRI, &gtp_val_ext, "Unknown message"));
ext_tree_auth_tri = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_AUTH_TRI]);
proto_tree_add_text(ext_tree_auth_tri, tvb, offset + 1, 16, "RAND: %s", tvb_bytes_to_str(tvb, offset + 1, 16));
proto_tree_add_text(ext_tree_auth_tri, tvb, offset + 17, 4, "SRES: %s", tvb_bytes_to_str(tvb, offset + 17, 4));
proto_tree_add_text(ext_tree_auth_tri, tvb, offset + 21, 8, "Kc: %s", tvb_bytes_to_str(tvb, offset + 21, 8));
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
decode_gtp_16(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
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
proto_tree_add_uint(tree, hf_gtp_teid_data, tvb, offset, 5, teid_data);
return 5;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Flow label/TEID Data I : GTP version not supported");
return 3;
}
}
static int
decode_gtp_17(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
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
proto_tree_add_text(tree, tvb, offset, 1, "Flow label signalling/TEID control plane : GTP version not supported");
return 3;
}
}
static int
decode_gtp_18(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 flow_ii;
guint32 teid_ii;
proto_tree *ext_tree_flow_ii;
proto_item *te;
switch (gtp_version) {
case 0:
te = proto_tree_add_text(tree, tvb, offset, 4, "%s", val_to_str_ext_const(GTP_EXT_FLOW_II, &gtp_val_ext, "Unknown message"));
ext_tree_flow_ii = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_FLOW_II]);
proto_tree_add_item(ext_tree_flow_ii, hf_gtp_nsapi, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
flow_ii = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_uint(ext_tree_flow_ii, hf_gtp_flow_ii, tvb, offset + 2, 2, flow_ii);
return 4;
case 1:
te = proto_tree_add_text(tree, tvb, offset, 6, "%s", val_to_str_ext_const(GTP_EXT_TEID_II, &gtpv1_val_ext, "Unknown message"));
ext_tree_flow_ii = proto_item_add_subtree(te, ett_gtp_flow_ii);
proto_tree_add_item(ext_tree_flow_ii, hf_gtp_nsapi, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
teid_ii = tvb_get_ntohl(tvb, offset + 2);
proto_tree_add_uint(ext_tree_flow_ii, hf_gtp_teid_ii, tvb, offset + 2, 4, teid_ii);
return 6;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Flow data II/TEID Data II : GTP Version not supported");
return 4;
}
}
static int
decode_gtp_19(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
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
proto_tree_add_text(tree, tvb, offset, 1, "Information Element Type = 19 : GTP Version not supported");
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
te = proto_tree_add_text(tree, tvb, offset, 10, "%s", val_to_str_ext_const(GTP_EXT_NSAPI, &gtp_val_ext, "Unknown message"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_NSAPI]);
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
proto_item *te;
te = proto_tree_add_text(tree, tvb, offset, 10, "%s", val_to_str_ext_const(GTP_EXT_RAB_CNTXT, &gtp_val_ext, "Unknown message"));
ext_tree_rab_cntxt = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_RAB_CNTXT]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s : ", val_to_str_ext_const(GTP_EXT_RA_PRIO_LCS, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_RA_PRIO_LCS]);
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
guint32 addr_ipv4;
struct e_in6_addr addr_ipv6;
proto_tree *ext_tree_user;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
pdp_org = tvb_get_guint8(tvb, offset + 3) & 0x0F;
pdp_typ = tvb_get_guint8(tvb, offset + 4);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s (%s/%s)",
val_to_str_ext_const(GTP_EXT_USER_ADDR, &gtp_val_ext, "Unknown message"),
val_to_str_const(pdp_org, pdp_org_type, "Unknown PDP Organization"),
val_to_str_const(pdp_typ, pdp_type, "Unknown PDP Type"));
ext_tree_user = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_USER_ADDR]);
proto_tree_add_text(ext_tree_user, tvb, offset + 1, 2, "Length : %u", length);
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
addr_ipv4 = tvb_get_ipv4(tvb, offset + 5);
proto_tree_add_ipv4(ext_tree_user, hf_gtp_user_ipv4, tvb, offset + 5, 4, addr_ipv4);
proto_item_append_text(te, " : %s", ip_to_str((guint8 *) & addr_ipv4));
break;
case 0x57:
tvb_get_ipv6(tvb, offset + 5, &addr_ipv6);
proto_tree_add_ipv6(ext_tree_user, hf_gtp_user_ipv6, tvb, offset + 5, 16, (guint8 *) & addr_ipv6);
proto_item_append_text(te, " : %s", ip6_to_str((struct e_in6_addr *) &addr_ipv6));
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
proto_item *te_trip;
guint16 i;
for (i = 0; i < count; i++) {
te_trip = proto_tree_add_text(tree, tvb, offset + i * 28, 28, "Triplet no%x", i);
ext_tree_trip = proto_item_add_subtree(te_trip, ett_gtp_trip);
proto_tree_add_text(ext_tree_trip, tvb, offset + i * 28, 16, "RAND: %s", tvb_bytes_to_str(tvb, offset + i * 28, 16));
proto_tree_add_text(ext_tree_trip, tvb, offset + i * 28 + 16, 4, "SRES: %s", tvb_bytes_to_str(tvb, offset + i * 28 + 16, 4));
proto_tree_add_text(ext_tree_trip, tvb, offset + i * 28 + 20, 8, "Kc: %s", tvb_bytes_to_str(tvb, offset + i * 28 + 20, 8));
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
te_quint = proto_tree_add_text(tree, tvb, offset, -1, "Quintuplet #%x", i + 1);
ext_tree_quint = proto_item_add_subtree(te_quint, ett_gtp_quint);
proto_tree_add_text(ext_tree_quint, tvb, offset + q_offset, 16, "RAND: %s", tvb_bytes_to_str(tvb, offset, 16));
q_offset = q_offset + 16;
xres_len = tvb_get_guint8(tvb, offset + q_offset);
proto_tree_add_text(ext_tree_quint, tvb, offset + q_offset, 1, "XRES length: %u", xres_len);
q_offset++;
proto_tree_add_text(ext_tree_quint, tvb, offset + q_offset, xres_len, "XRES: %s", tvb_bytes_to_str(tvb, offset + q_offset, xres_len));
q_offset = q_offset + xres_len;
proto_tree_add_text(ext_tree_quint, tvb, offset + q_offset, 16, "Quintuplet Ciphering Key: %s", tvb_bytes_to_str(tvb, offset + q_offset, 16));
q_offset = q_offset + 16;
proto_tree_add_text(ext_tree_quint, tvb, offset + q_offset, 16, "Quintuplet Integrity Key: %s", tvb_bytes_to_str(tvb, offset + q_offset, 16));
q_offset = q_offset + 16;
auth_len = tvb_get_guint8(tvb, offset + q_offset);
proto_tree_add_text(ext_tree_quint, tvb, offset + q_offset, 1, "Authentication length: %u", auth_len);
q_offset++;
proto_tree_add_text(ext_tree_quint, tvb, offset + q_offset, auth_len, "AUTH: %s", tvb_bytes_to_str(tvb, offset + q_offset, auth_len));
q_offset = q_offset + auth_len;
proto_item_set_end(te_quint, tvb, offset + q_offset);
}
return q_offset;
}
static int
decode_gtp_mm_cntxt(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length, quint_len, con_len;
guint8 count, sec_mode, len, iei;
proto_tree *ext_tree_mm;
proto_item *te;
proto_item *tf = NULL;
proto_tree *tf_tree = NULL;
te = proto_tree_add_text(tree, tvb, offset, 1, "%s", val_to_str_ext_const(GTP_EXT_MM_CNTXT, &gtp_val_ext, "Unknown message"));
ext_tree_mm = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MM_CNTXT]);
length = tvb_get_ntohs(tvb, offset + 1);
if (length < 1)
return 3;
sec_mode = (tvb_get_guint8(tvb, offset + 4) >> 6) & 0x03;
count = (tvb_get_guint8(tvb, offset + 4) >> 3) & 0x07;
proto_tree_add_text(ext_tree_mm, tvb, offset + 1, 2, "Length: %x", length);
if (gtp_version == 0)
sec_mode = 1;
switch (sec_mode) {
case 0:
proto_tree_add_item(ext_tree_mm, hf_gtp_cksn_ksi, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_security_mode, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_no_of_vectors, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_cipher_algorithm, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(ext_tree_mm, tvb, offset + 5, 16, "Ciphering key CK: %s", tvb_bytes_to_str(tvb, offset + 5, 16));
proto_tree_add_text(ext_tree_mm, tvb, offset + 21, 16, "Integrity key IK: %s", tvb_bytes_to_str(tvb, offset + 21, 16));
quint_len = tvb_get_ntohs(tvb, offset + 37);
proto_tree_add_text(ext_tree_mm, tvb, offset + 37, 2, "Quintuplets length: 0x%x (%u)", quint_len, quint_len);
offset = offset + decode_quintuplet(tvb, offset + 39, ext_tree_mm, count) + 39;
break;
case 1:
proto_tree_add_item(ext_tree_mm, hf_gtp_cksn, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
if (gtp_version != 0)
proto_tree_add_item(ext_tree_mm, hf_gtp_security_mode, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_no_of_vectors, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_cipher_algorithm, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(ext_tree_mm, tvb, offset + 5, 8, "Ciphering key Kc: %s", tvb_bytes_to_str(tvb, offset + 5, 8));
offset = offset + decode_triplet(tvb, offset + 13, ext_tree_mm, count) + 13;
break;
case 2:
proto_tree_add_item(ext_tree_mm, hf_gtp_ksi, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_security_mode, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_no_of_vectors, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(ext_tree_mm, tvb, offset + 5, 16, "Ciphering key CK: %s", tvb_bytes_to_str(tvb, offset + 5, 16));
proto_tree_add_text(ext_tree_mm, tvb, offset + 21, 16, "Integrity key IK: %s", tvb_bytes_to_str(tvb, offset + 21, 16));
quint_len = tvb_get_ntohs(tvb, offset + 37);
proto_tree_add_text(ext_tree_mm, tvb, offset + 37, 2, "Quintuplets length: 0x%x (%u)", quint_len, quint_len);
offset = offset + decode_quintuplet(tvb, offset + 39, ext_tree_mm, count) + 39;
break;
case 3:
proto_tree_add_item(ext_tree_mm, hf_gtp_cksn, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_security_mode, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_no_of_vectors, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_mm, hf_gtp_cipher_algorithm, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(ext_tree_mm, tvb, offset + 5, 8, "Ciphering key Kc: %s", tvb_bytes_to_str(tvb, offset + 5, 8));
quint_len = tvb_get_ntohs(tvb, offset + 13);
proto_tree_add_text(ext_tree_mm, tvb, offset + 13, 2, "Quintuplets length: 0x%x (%u)", quint_len, quint_len);
offset = offset + decode_quintuplet(tvb, offset + 15, ext_tree_mm, count) + 15;
break;
default:
break;
}
de_gmm_drx_param(tvb, ext_tree_mm, pinfo, offset, 2, NULL, 0);
offset = offset + 2;
len = tvb_get_guint8(tvb, offset);
tf = proto_tree_add_text(ext_tree_mm, tvb, offset, len + 1, "MS Network Capability");
tf_tree = proto_item_add_subtree(tf, ett_gtp_net_cap);
proto_tree_add_text(tf_tree, tvb, offset, 1, "Length of MS network capability contents: %u", len);
offset++;
de_gmm_ms_net_cap(tvb, tf_tree, pinfo, offset, len, NULL, 0);
offset = offset + len;
con_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(ext_tree_mm, tvb, offset, 2, "Container length: %u", con_len);
offset = offset + 2;
if (con_len > 0) {
proto_tree_add_text(ext_tree_mm, tvb, offset, con_len, "Container");
iei = tvb_get_guint8(tvb,offset);
if (iei == 0x23) {
proto_tree_add_text(ext_tree_mm, tvb, offset, 1, "Mobile identity IEI %u",iei);
offset++;
len = tvb_get_guint8(tvb,offset);
proto_tree_add_text(ext_tree_mm, tvb, offset, 1, "Length %u",len);
offset++;
de_mid(tvb, ext_tree_mm, pinfo, offset, len, NULL, 0);
} else {
proto_tree_add_text(ext_tree_mm, tvb, offset, 1, "Unknown IEI %u - Later spec than TS 29.060 9.4.0 used?",iei);
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
decode_qos_umts(tvbuff_t * tvb, int offset, proto_tree * tree, const gchar * qos_str, guint8 type)
{
guint length;
guint8 al_ret_priority;
guint8 delay, reliability, peak, precedence, mean, spare1, spare2, spare3;
guint8 traf_class, del_order, del_err_sdu;
guint8 max_sdu_size, max_ul, max_dl, max_ul_ext, max_dl_ext;
guint8 res_ber, sdu_err_ratio;
guint8 trans_delay, traf_handl_prio;
guint8 guar_ul, guar_dl, guar_ul_ext, guar_dl_ext;
guint8 src_stat_desc, sig_ind;
proto_tree *ext_tree_qos, *ext_tree_qos_arp;
proto_item *te;
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
te = proto_tree_add_text(tree, tvb, offset, length + 1, "%s", qos_str);
ext_tree_qos = proto_item_add_subtree(te, ett_gtp_qos);
proto_tree_add_text(ext_tree_qos, tvb, offset, 1, "Length: %u", length);
offset++;
retval = length + 1;
break;
case 2:
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, length + 3, "%s", qos_str);
ext_tree_qos = proto_item_add_subtree(te, ett_gtp_qos);
proto_tree_add_text(ext_tree_qos, tvb, offset + 1, 2, "Length: %u", length);
offset += 3;
retval = length + 3;
break;
case 3:
utf8_type = 2;
length = tvb_length(tvb);
te = proto_tree_add_text(tree, tvb, offset, length, "%s", qos_str);
ext_tree_qos = proto_item_add_subtree(te, ett_gtp_qos);
rel_ind = wrapped_tvb_get_guint8(tvb, offset, 2);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_version, tvb, offset, 2, rel_ind);
hyphen = tvb_get_guint8(tvb, offset + 2);
if (hyphen == ((guint8) '-')) {
proto_tree_add_text(ext_tree_qos, tvb, offset + 2, 1, "Hyphen separator: -");
offset++;
}
offset++;
length -= offset;
length /= 2;
retval = length + 2;
break;
default:
length = 0;
retval = 0;
ext_tree_qos = NULL;
break;
}
if ((type == 3) && (rel_ind >= 8)) {
offset++;
arp = wrapped_tvb_get_guint8(tvb, offset, 2);
te = proto_tree_add_text(ext_tree_qos, tvb, offset, 2, "Allocation/Retention Priority");
ext_tree_qos_arp = proto_item_add_subtree(te, ett_gtp_qos_arp);
proto_tree_add_boolean(ext_tree_qos_arp, hf_gtp_qos_arp_pci, tvb, offset, 2, arp);
proto_tree_add_uint(ext_tree_qos_arp, hf_gtp_qos_arp_pl, tvb, offset, 2, arp);
proto_tree_add_boolean(ext_tree_qos_arp, hf_gtp_qos_arp_pvi, tvb, offset, 2, arp);
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
guar_ul_ext =0;
if (length > 13) {
src_stat_desc = wrapped_tvb_get_guint8(tvb, offset + (12 - 1) * utf8_type + 1, utf8_type)& GTP_EXT_QOS_SRC_STAT_DESC_MASK;
sig_ind = wrapped_tvb_get_guint8(tvb, offset + (12 - 1) * utf8_type + 1, utf8_type)& GTP_EXT_QOS_SIG_IND_MASK;
}
if (length > 14) {
max_dl_ext = wrapped_tvb_get_guint8(tvb, offset + (13 - 1) * utf8_type + 1, utf8_type);
guar_dl_ext = wrapped_tvb_get_guint8(tvb, offset + (14 - 1) * utf8_type + 1, utf8_type);
}
if (length > 16) {
max_ul_ext = wrapped_tvb_get_guint8(tvb, offset + (15 - 1) * utf8_type + 1, utf8_type);
guar_ul_ext = wrapped_tvb_get_guint8(tvb, offset + (16 - 1) * utf8_type + 1, utf8_type);
}
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_traf_class, tvb, offset + (4 - 1) * utf8_type + 1, utf8_type, traf_class);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_del_order, tvb, offset + (4 - 1) * utf8_type + 1, utf8_type, del_order);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_del_err_sdu, tvb, offset + (4 - 1) * utf8_type + 1, utf8_type, del_err_sdu);
if (max_sdu_size == 0 || max_sdu_size > 150)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_max_sdu_size, tvb, offset + (5 - 1) * utf8_type + 1, utf8_type, max_sdu_size);
if ((max_sdu_size > 0) && (max_sdu_size <= 150)) {
mss = max_sdu_size * 10;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_sdu_size, tvb, offset + (5 - 1) * utf8_type + 1, utf8_type, mss,
"Maximum SDU size: %u octets", mss);
}
if (max_ul == 0 || max_ul == 255)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (6 - 1) * utf8_type + 1, utf8_type, max_ul);
if ((max_ul > 0) && (max_ul <= 63))
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (6 - 1) * utf8_type + 1, utf8_type, max_ul,
"Maximum bit rate for uplink: %u kbps", max_ul);
if ((max_ul > 63) && (max_ul <= 127)) {
mu = 64 + (max_ul - 64) * 8;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (6 - 1) * utf8_type + 1, utf8_type, mu,
"Maximum bit rate for uplink: %u kbps", mu);
}
if ((max_ul > 127) && (max_ul <= 254)) {
mu = 576 + (max_ul - 128) * 64;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_ul, tvb, offset + (6 - 1) * utf8_type + 1, utf8_type, mu,
"Maximum bit rate for uplink: %u kbps", mu);
}
if (max_dl == 0 || max_dl == 255)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (7 - 1) * utf8_type + 1, utf8_type, max_dl);
if ((max_dl > 0) && (max_dl <= 63))
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (7 - 1) * utf8_type + 1, utf8_type, max_dl,
"Maximum bit rate for downlink: %u kbps", max_dl);
if ((max_dl > 63) && (max_dl <= 127)) {
md = 64 + (max_dl - 64) * 8;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (7 - 1) * utf8_type + 1, utf8_type, md,
"Maximum bit rate for downlink: %u kbps", md);
}
if ((max_dl > 127) && (max_dl <= 254)) {
md = 576 + (max_dl - 128) * 64;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_max_dl, tvb, offset + (7 - 1) * utf8_type + 1, utf8_type, md,
"Maximum bit rate for downlink: %u kbps", md);
}
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_res_ber, tvb, offset + (8 - 1) * utf8_type + 1, utf8_type, res_ber);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_sdu_err_ratio, tvb, offset + (8 - 1) * utf8_type + 1, utf8_type, sdu_err_ratio);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_trans_delay, tvb, offset + (9 - 1) * utf8_type + 1, utf8_type, trans_delay);
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_traf_handl_prio, tvb, offset + (9 - 1) * utf8_type + 1, utf8_type, traf_handl_prio);
if (guar_ul == 0 || guar_ul == 255)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (10 - 1) * utf8_type + 1, utf8_type, guar_ul);
if ((guar_ul > 0) && (guar_ul <= 63))
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (10 - 1) * utf8_type + 1, utf8_type, guar_ul,
"Guaranteed bit rate for uplink: %u kbps", guar_ul);
if ((guar_ul > 63) && (guar_ul <= 127)) {
gu = 64 + (guar_ul - 64) * 8;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (10 - 1) * utf8_type + 1, utf8_type, gu,
"Guaranteed bit rate for uplink: %u kbps", gu);
}
if ((guar_ul > 127) && (guar_ul <= 254)) {
gu = 576 + (guar_ul - 128) * 64;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (10 - 1) * utf8_type + 1, utf8_type, gu,
"Guaranteed bit rate for uplink: %u kbps", gu);
}
if (guar_dl == 0 || guar_dl == 255)
proto_tree_add_uint(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (11 - 1) * utf8_type + 1, utf8_type, guar_dl);
if ((guar_dl > 0) && (guar_dl <= 63))
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (11 - 1) * utf8_type + 1, utf8_type, guar_dl,
"Guaranteed bit rate for downlink: %u kbps", guar_dl);
if ((guar_dl > 63) && (guar_dl <= 127)) {
gd = 64 + (guar_dl - 64) * 8;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (11 - 1) * utf8_type + 1, utf8_type, gd,
"Guaranteed bit rate for downlink: %u kbps", gd);
}
if ((guar_dl > 127) && (guar_dl <= 254)) {
gd = 576 + (guar_dl - 128) * 64;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (11 - 1) * utf8_type + 1, utf8_type, gd,
"Guaranteed bit rate for downlink: %u kbps", gd);
}
if(length > 13) {
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
proto_tree_add_text(ext_tree_qos, tvb, offset + (14 - 1) * utf8_type + 1, utf8_type, "Use the value indicated by the Guaranteed bit rate for downlink in octet 13");
if ((guar_dl_ext > 0) && (guar_dl_ext <= 0x4a)) {
gd = 8600 + guar_dl_ext * 100;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (14 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for downlink: %u kbps", gd);
}
if ((guar_dl_ext > 0x4a) && (max_dl_ext <= 0xba)) {
gd = 16 + (guar_dl_ext-0x4a);
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (14 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for downlink: %u Mbps", gd);
}
if ((guar_dl_ext > 0xba) && (max_dl_ext <= 0xfa)) {
gd = 128 + (guar_dl_ext-0xba)*2;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_dl, tvb, offset + (14 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for downlink: %u Mbps", gd);
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
proto_tree_add_text(ext_tree_qos, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, "Use the value indicated by the Guaranteed bit rate for uplink in octet 12");
if ((guar_ul_ext > 0) && (guar_ul_ext <= 0x4a)) {
gd = 8600 + guar_ul_ext * 100;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for uplink: %u kbps", gd);
}
if ((guar_ul_ext > 0x4a) && (max_ul_ext <= 0xba)) {
gd = 16 + (guar_ul_ext-0x4a);
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for uplink: %u Mbps", gd);
}
if ((guar_ul_ext > 0xba) && (max_ul_ext <= 0xfa)) {
gd = 128 + (guar_ul_ext-0xba)*2;
proto_tree_add_uint_format(ext_tree_qos, hf_gtp_qos_guar_ul, tvb, offset + (16 - 1) * utf8_type + 1, utf8_type, gd,
"Ext Guaranteed bit rate for uplink: %u Mbps", gd);
}
}
}
return retval;
}
static int
dissect_diameter_3gpp_qosprofile(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
decode_qos_umts(tvb, 0, tree, "UMTS GTP QoS Profile", 3);
return tvb_length(tvb);
}
static const gchar *
dissect_radius_qos_umts(proto_tree * tree, tvbuff_t * tvb, packet_info* pinfo _U_)
{
decode_qos_umts(tvb, 0, tree, "UMTS GTP QoS Profile", 3);
return tvb_get_ephemeral_string(tvb, 0, tvb_length(tvb));
}
static void
decode_apn(tvbuff_t * tvb, int offset, guint16 length, proto_tree * tree)
{
guint8 *apn = NULL;
int name_len, tmp;
if (length > 0) {
name_len = tvb_get_guint8(tvb, offset);
if (name_len < 0x20) {
apn = tvb_get_ephemeral_string(tvb, offset + 1, length - 1);
for (;;) {
if (name_len >= length - 1)
break;
tmp = name_len;
name_len = name_len + apn[tmp] + 1;
apn[tmp] = '.';
}
} else
apn = tvb_get_ephemeral_string(tvb, offset, length);
proto_tree_add_string(tree, hf_gtp_apn, tvb, offset, length, apn);
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
fqdn = tvb_get_ephemeral_string(tvb, offset + 1, length - 1);
for (;;) {
if (name_len >= length - 1)
break;
tmp = name_len;
name_len = name_len + fqdn[tmp] + 1;
fqdn[tmp] = '.';
}
} else
fqdn = tvb_get_ephemeral_string(tvb, offset, length);
proto_tree_add_string(tree, hf_gtp_fqdn, tvb, offset, length, fqdn);
}
}
static int
decode_gtp_pdp_cntxt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 ggsn_addr_len, apn_len, trans_id, vaa, asi, order;
guint8 nsapi, sapi, pdu_send_no, pdu_rec_no;
guint8 pdp_cntxt_id, pdp_type_org, pdp_type_num, pdp_addr_len;
guint16 length, sn_down, sn_up, up_flow;
guint32 addr_ipv4;
struct e_in6_addr addr_ipv6;
proto_tree *ext_tree_pdp;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, length + 3, "%s", val_to_str_ext_const(GTP_EXT_PDP_CNTXT, &gtp_val_ext, "Unknown message"));
ext_tree_pdp = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_PDP_CNTXT]);
vaa = (tvb_get_guint8(tvb, offset + 3) >> 6) & 0x01;
asi = (tvb_get_guint8(tvb, offset + 3) >> 5) & 0x01;
order = (tvb_get_guint8(tvb, offset + 3) >> 4) & 0x01;
nsapi = tvb_get_guint8(tvb, offset + 3) & 0x0F;
sapi = tvb_get_guint8(tvb, offset + 4) & 0x0F;
proto_tree_add_text(ext_tree_pdp, tvb, offset + 3, 1, "VPLMN address allowed: %s", yesno[vaa]);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 3, 1, "Activity Status Indicator: %s", yesno[asi]);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 3, 1, "Reordering required: %s", yesno[order]);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 3, 1, "NSAPI: %u", nsapi);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 4, 1, "SAPI: %u", sapi);
switch (gtp_version) {
case 0:
decode_qos_gprs(tvb, offset + 5, ext_tree_pdp, "QoS subscribed", 0);
decode_qos_gprs(tvb, offset + 8, ext_tree_pdp, "QoS requested", 0);
decode_qos_gprs(tvb, offset + 11, ext_tree_pdp, "QoS negotiated", 0);
offset = offset + 14;
break;
case 1:
offset = offset + 5;
offset = offset + decode_qos_umts(tvb, offset, ext_tree_pdp, "QoS subscribed", 1);
offset = offset + decode_qos_umts(tvb, offset, ext_tree_pdp, "QoS requested", 1);
offset = offset + decode_qos_umts(tvb, offset, ext_tree_pdp, "QoS negotiated", 1);
break;
default:
break;
}
sn_down = tvb_get_ntohs(tvb, offset);
sn_up = tvb_get_ntohs(tvb, offset + 2);
pdu_send_no = tvb_get_guint8(tvb, offset + 4);
pdu_rec_no = tvb_get_guint8(tvb, offset + 5);
proto_tree_add_text(ext_tree_pdp, tvb, offset, 2, "Sequence number down: %u", sn_down);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 2, 2, "Sequence number up: %u", sn_up);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 4, 1, "Send N-PDU number: %u", pdu_send_no);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 5, 1, "Receive N-PDU number: %u", pdu_rec_no);
switch (gtp_version) {
case 0:
up_flow = tvb_get_ntohs(tvb, offset + 6);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 6, 2, "Uplink flow label signalling: %u", up_flow);
offset = offset + 8;
break;
case 1:
pdp_cntxt_id = tvb_get_guint8(tvb, offset + 14);
proto_tree_add_item(ext_tree_pdp, hf_gtp_ulink_teid_cp, tvb, offset + 6, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree_pdp, hf_gtp_ulink_teid_data, tvb, offset + 10, 4, ENC_BIG_ENDIAN);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 14, 1, "PDP context identifier: %u", pdp_cntxt_id);
offset = offset + 15;
break;
default:
break;
}
pdp_type_org = tvb_get_guint8(tvb, offset) & 0x0F;
pdp_type_num = tvb_get_guint8(tvb, offset + 1);
pdp_addr_len = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_text(ext_tree_pdp, tvb, offset, 1, "PDP organization: %s", val_to_str_const(pdp_type_org, pdp_type, "Unknown PDP org"));
proto_tree_add_text(ext_tree_pdp, tvb, offset + 1, 1, "PDP type: %s", val_to_str_const(pdp_type_num, pdp_type, "Unknown PDP type"));
proto_tree_add_text(ext_tree_pdp, tvb, offset + 2, 1, "PDP address length: %u", pdp_addr_len);
if (pdp_addr_len > 0) {
switch (pdp_type_num) {
case 0x21:
addr_ipv4 = tvb_get_ipv4(tvb, offset + 3);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 3, 4, "PDP address: %s", ip_to_str((guint8 *) & addr_ipv4));
break;
case 0x57:
tvb_get_ipv6(tvb, offset + 3, &addr_ipv6);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 3, 16, "PDP address: %s", ip6_to_str((struct e_in6_addr *) &addr_ipv6));
break;
default:
break;
}
}
offset = offset + 3 + pdp_addr_len;
ggsn_addr_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ext_tree_pdp, tvb, offset, 1, "GGSN address length: %u", ggsn_addr_len);
switch (ggsn_addr_len) {
case 4:
addr_ipv4 = tvb_get_ipv4(tvb, offset + 1);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 1, 4, "GGSN Address for control plane: %s", ip_to_str((guint8 *) & addr_ipv4));
break;
case 16:
tvb_get_ipv6(tvb, offset + 1, &addr_ipv6);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 1, 16, "GGSN Address for User Traffic: %s", ip6_to_str((struct e_in6_addr *) &addr_ipv6));
break;
default:
break;
}
offset = offset + 1 + ggsn_addr_len;
if (gtp_version == 1) {
ggsn_addr_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ext_tree_pdp, tvb, offset, 1, "GGSN 2 address length: %u", ggsn_addr_len);
switch (ggsn_addr_len) {
case 4:
addr_ipv4 = tvb_get_ipv4(tvb, offset + 1);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 1, 4, "GGSN 2 address: %s", ip_to_str((guint8 *) & addr_ipv4));
break;
case 16:
tvb_get_ipv6(tvb, offset + 1, &addr_ipv6);
proto_tree_add_text(ext_tree_pdp, tvb, offset + 1, 16, "GGSN 2 address: %s", ip6_to_str((struct e_in6_addr *) &addr_ipv6));
break;
default:
break;
}
offset = offset + 1 + ggsn_addr_len;
}
apn_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ext_tree_pdp, tvb, offset, 1, "APN length: %u", apn_len);
decode_apn(tvb, offset + 1, apn_len, ext_tree_pdp);
offset = offset + 1 + apn_len;
trans_id = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ext_tree_pdp, tvb, offset, 2, "Transaction identifier: %u", trans_id);
return 3 + length;
}
static int
decode_gtp_apn(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree_apn;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, length + 3, "%s", val_to_str_ext_const(GTP_EXT_APN, &gtp_val_ext, "Unknown field"));
ext_tree_apn = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_APN]);
proto_tree_add_text(ext_tree_apn, tvb, offset + 1, 2, "APN length : %u", length);
decode_apn(tvb, offset + 3, length, ext_tree_apn);
return 3 + length;
}
int
decode_gtp_proto_conf(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
tvbuff_t *next_tvb;
proto_tree *ext_tree_proto;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, length + 3, "%s", val_to_str_ext_const(GTP_EXT_PROTO_CONF, &gtp_val_ext, "Unknown message"));
ext_tree_proto = proto_item_add_subtree(te, ett_gtp_proto);
proto_tree_add_text(ext_tree_proto, tvb, offset + 1, 2, "Length: %u", length);
if (length < 1)
return 3;
next_tvb = tvb_new_subset(tvb, offset + 3, length, length);
pinfo->link_dir = P2P_DIR_UL;
de_sm_pco(next_tvb, ext_tree_proto, pinfo, 0, length, NULL, 0);
return 3 + length;
}
static int
decode_gtp_gsn_addr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint8 addr_type, addr_len;
guint16 length;
guint32 addr_ipv4;
struct e_in6_addr addr_ipv6;
proto_tree *ext_tree_gsn_addr;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "GSN address : ");
ext_tree_gsn_addr = proto_item_add_subtree(te, ett_gtp_gsn_addr);
switch (length) {
case 4:
proto_tree_add_text(ext_tree_gsn_addr, tvb, offset + 1, 2, "GSN address length : %u", length);
addr_ipv4 = tvb_get_ipv4(tvb, offset + 3);
proto_item_append_text(te, "%s", ip_to_str((guint8 *) & addr_ipv4));
proto_tree_add_ipv4(ext_tree_gsn_addr, hf_gtp_gsn_ipv4, tvb, offset + 3, 4, addr_ipv4);
break;
case 5:
proto_tree_add_text(ext_tree_gsn_addr, tvb, offset + 1, 2, "GSN address Information Element length : %u", length);
addr_type = tvb_get_guint8(tvb, offset + 3) & 0xC0;
proto_tree_add_uint(ext_tree_gsn_addr, hf_gtp_gsn_addr_type, tvb, offset + 3, 1, addr_type);
addr_len = tvb_get_guint8(tvb, offset + 3) & 0x3F;
proto_tree_add_uint(ext_tree_gsn_addr, hf_gtp_gsn_addr_len, tvb, offset + 3, 1, addr_len);
addr_ipv4 = tvb_get_ipv4(tvb, offset + 4);
proto_item_append_text(te, "%s", ip_to_str((guint8 *) & addr_ipv4));
proto_tree_add_ipv4(ext_tree_gsn_addr, hf_gtp_gsn_ipv4, tvb, offset + 4, 4, addr_ipv4);
break;
case 16:
proto_tree_add_text(ext_tree_gsn_addr, tvb, offset + 1, 2, "GSN address length : %u", length);
tvb_get_ipv6(tvb, offset + 3, &addr_ipv6);
proto_item_append_text(te, "%s", ip6_to_str((struct e_in6_addr *) &addr_ipv6));
proto_tree_add_ipv6(ext_tree_gsn_addr, hf_gtp_gsn_ipv6, tvb, offset + 3, 16, (guint8 *) & addr_ipv6);
break;
case 17:
proto_tree_add_text(ext_tree_gsn_addr, tvb, offset + 1, 2, "GSN address Information Element length : %u", length);
addr_type = tvb_get_guint8(tvb, offset + 3) & 0xC0;
proto_tree_add_uint(ext_tree_gsn_addr, hf_gtp_gsn_addr_type, tvb, offset + 3, 1, addr_type);
addr_len = tvb_get_guint8(tvb, offset + 3) & 0x3F;
proto_tree_add_uint(ext_tree_gsn_addr, hf_gtp_gsn_addr_len, tvb, offset + 3, 1, addr_len);
tvb_get_ipv6(tvb, offset + 4, &addr_ipv6);
proto_item_append_text(te, "%s", ip6_to_str((struct e_in6_addr *) &addr_ipv6));
proto_tree_add_ipv6(ext_tree_gsn_addr, hf_gtp_gsn_ipv6, tvb, offset + 4, 16, (guint8 *) & addr_ipv6);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, length + 3, "%s", val_to_str_ext_const(GTP_EXT_MSISDN, &gtp_val_ext, "Unknown message"));
ext_tree_proto = proto_item_add_subtree(te, ett_gtp_proto);
proto_tree_add_text(ext_tree_proto, tvb, offset + 1, 2, "Length: %u", length);
length = tvb_get_ntohs(tvb, offset + 1);
if (length < 1)
return 3;
next_tvb = tvb_new_subset(tvb, offset+3, length, length);
dissect_gsm_map_msisdn(next_tvb, pinfo, ext_tree_proto);
return 3 + length;
}
static int
decode_gtp_qos_umts(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
return decode_qos_umts(tvb, offset, tree, "Quality of Service", 2);
}
static int
decode_gtp_auth_qui(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree *ext_tree;
proto_item *te_quint;
guint16 length;
guint8 xres_len, auth_len;
length = tvb_get_ntohs(tvb, offset + 1);
te_quint = proto_tree_add_text(tree, tvb, offset, length + 1, "Quintuplet");
ext_tree = proto_item_add_subtree(te_quint, ett_gtp_quint);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, 16, "RAND: %s", tvb_bytes_to_str(tvb, offset, 16));
offset = offset + 16;
xres_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ext_tree, tvb, offset, 1, "XRES length: %u", xres_len);
offset++;
proto_tree_add_text(ext_tree, tvb, offset, xres_len, "XRES: %s", tvb_bytes_to_str(tvb, offset, xres_len));
offset = offset + xres_len;
proto_tree_add_text(ext_tree, tvb, offset, 16, "Quintuplet Ciphering Key: %s", tvb_bytes_to_str(tvb, offset, 16));
offset = offset + 16;
proto_tree_add_text(ext_tree, tvb, offset, 16, "Quintuplet Integrity Key: %s", tvb_bytes_to_str(tvb, offset, 16));
offset = offset + 16;
auth_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ext_tree, tvb, offset, 1, "Authentication length: %u", auth_len);
offset++;
proto_tree_add_text(ext_tree, tvb, offset, auth_len, "AUTH: %s", tvb_bytes_to_str(tvb, offset, auth_len));
return (3 + length);
}
static int
decode_gtp_tft(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length, port1, port2, tos;
guint8 tft_flags, tft_code, no_packet_filters, i, pf_id, pf_eval, pf_len, pf_content_id, proto;
guint pf_offset;
guint32 mask_ipv4, addr_ipv4, ipsec_id, label;
struct e_in6_addr addr_ipv6, mask_ipv6;
proto_tree *ext_tree_tft, *ext_tree_tft_pf, *ext_tree_tft_flags;
proto_item *te, *tee, *tef;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "Traffic flow template");
ext_tree_tft = proto_item_add_subtree(te, ett_gtp_tft);
tft_flags = tvb_get_guint8(tvb, offset + 3);
tft_code = (tft_flags >> 5) & 0x07;
no_packet_filters = tft_flags & 0x0F;
proto_tree_add_text(ext_tree_tft, tvb, offset + 1, 2, "TFT length: %u", length);
tef = proto_tree_add_text(ext_tree_tft, tvb, offset + 3, 1, "TFT flags");
ext_tree_tft_flags = proto_item_add_subtree(tef, ett_gtp_tft_flags);
proto_tree_add_uint(ext_tree_tft_flags, hf_gtp_tft_code, tvb, offset + 3, 1, tft_flags);
proto_tree_add_uint(ext_tree_tft_flags, hf_gtp_tft_spare, tvb, offset + 3, 1, tft_flags);
proto_tree_add_uint(ext_tree_tft_flags, hf_gtp_tft_number, tvb, offset + 3, 1, tft_flags);
offset = offset + 4;
for (i = 0; i < no_packet_filters; i++) {
pf_id = tvb_get_guint8(tvb, offset);
tee = proto_tree_add_text(ext_tree_tft, tvb, offset, 1, "Packet filter id: %u", pf_id);
ext_tree_tft_pf = proto_item_add_subtree(tee, ett_gtp_tft_pf);
offset++;
if (tft_code != 2) {
pf_eval = tvb_get_guint8(tvb, offset);
pf_len = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_uint(ext_tree_tft_pf, hf_gtp_tft_eval, tvb, offset, 1, pf_eval);
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + 1, 1, "Content length: %u", pf_len);
offset = offset + 2;
pf_offset = 0;
while (pf_offset < pf_len) {
pf_content_id = tvb_get_guint8(tvb, offset + pf_offset);
switch (pf_content_id) {
case 0x10:
addr_ipv4 = tvb_get_ipv4(tvb, offset + pf_offset + 1);
mask_ipv4 = tvb_get_ipv4(tvb, offset + pf_offset + 5);
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 9, "ID 0x10: IPv4/mask: %s/%s", ip_to_str((guint8 *) & addr_ipv4),
ip_to_str((guint8 *) & mask_ipv4));
pf_offset = pf_offset + 9;
break;
case 0x20:
tvb_get_ipv6(tvb, offset + pf_offset + 1, &addr_ipv6);
tvb_get_ipv6(tvb, offset + pf_offset + 17, &mask_ipv6);
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 33, "ID 0x20: IPv6/mask: %s/%s",
ip6_to_str((struct e_in6_addr *) &addr_ipv6), ip6_to_str((struct e_in6_addr *) &mask_ipv6));
pf_offset = pf_offset + 33;
break;
case 0x30:
proto = tvb_get_guint8(tvb, offset + pf_offset + 1);
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 2, "ID 0x30: IPv4 protocol identifier/IPv6 next header: %u (%x)",
proto, proto);
pf_offset = pf_offset + 2;
break;
case 0x40:
port1 = tvb_get_ntohs(tvb, offset + pf_offset + 1);
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 3, "ID 0x40: destination port: %u", port1);
pf_offset = pf_offset + 3;
break;
case 0x41:
port1 = tvb_get_ntohs(tvb, offset + pf_offset + 1);
port2 = tvb_get_ntohs(tvb, offset + pf_offset + 3);
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 5, "ID 0x41: destination port range: %u - %u", port1, port2);
pf_offset = pf_offset + 5;
break;
case 0x50:
port1 = tvb_get_ntohs(tvb, offset + pf_offset + 1);
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 3, "ID 0x50: source port: %u", port1);
pf_offset = pf_offset + 3;
break;
case 0x51:
port1 = tvb_get_ntohs(tvb, offset + pf_offset + 1);
port2 = tvb_get_ntohs(tvb, offset + pf_offset + 3);
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 5, "ID 0x51: source port range: %u - %u", port1, port2);
pf_offset = pf_offset + 5;
break;
case 0x60:
ipsec_id = tvb_get_ntohl(tvb, offset + pf_offset + 1);
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 5, "ID 0x60: security parameter index: %x", ipsec_id);
pf_offset = pf_offset + 5;
break;
case 0x70:
tos = tvb_get_ntohs(tvb, offset + pf_offset + 1);
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 2, "ID 0x70: Type of Service/Traffic Class: %u (%x)", tos, tos);
pf_offset = pf_offset + 3;
break;
case 0x80:
label = tvb_get_ntoh24(tvb, offset + pf_offset + 1) & 0x0FFFFF;
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 4, "ID 0x80: Flow Label: %u (%x)", label, label);
pf_offset = pf_offset + 4;
break;
default:
proto_tree_add_text(ext_tree_tft_pf, tvb, offset + pf_offset, 1, "Unknown value: %x ", pf_content_id);
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
decode_gtp_target_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_item *te;
proto_tree *ext_tree;
tvbuff_t *next_tvb;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "Target Identification");
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_TARGET_ID]);
offset = offset + 1;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
next_tvb = tvb_new_subset(tvb, offset, length, length);
dissect_ranap_TargetRNC_ID(next_tvb, 0, &asn1_ctx, ext_tree, hf_gtp_targetRNC_ID);
return 3 + length;
}
static int
decode_gtp_utran_cont(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_item *te;
proto_tree *ext_tree;
tvbuff_t *next_tvb;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "UTRAN transparent field");
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_UTRAN_CONT]);
offset = offset + 1;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
next_tvb = tvb_new_subset(tvb, offset, length, length);
if (data_handle)
call_dissector(data_handle, next_tvb, pinfo, ext_tree);
return 3 + length;
}
static int
decode_gtp_rab_setup(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint32 teid, addr_ipv4;
guint16 length;
struct e_in6_addr addr_ipv6;
proto_tree *ext_tree_rab_setup;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "Radio Access Bearer Setup Information");
ext_tree_rab_setup = proto_item_add_subtree(te, ett_gtp_rab_setup);
proto_tree_add_text(ext_tree_rab_setup, tvb, offset + 1, 2, "RAB setup length : %u", length);
proto_tree_add_item(ext_tree_rab_setup, hf_gtp_nsapi, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
if (length > 1) {
teid = tvb_get_ntohl(tvb, offset + 4);
proto_tree_add_uint(ext_tree_rab_setup, hf_gtp_teid_data, tvb, offset + 4, 4, teid);
switch (length) {
case 12:
addr_ipv4 = tvb_get_ipv4(tvb, offset + 8);
proto_tree_add_ipv4(ext_tree_rab_setup, hf_gtp_rnc_ipv4, tvb, offset + 8, 4, addr_ipv4);
break;
case 24:
tvb_get_ipv6(tvb, offset + 8, &addr_ipv6);
proto_tree_add_ipv6(ext_tree_rab_setup, hf_gtp_rnc_ipv6, tvb, offset + 8, 16, (guint8 *) & addr_ipv6);
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
proto_item *te;
length = tvb_get_guint8(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 2 + length, "%s", val_to_str_ext_const(GTP_EXT_HDR_LIST, &gtp_val_ext, "Unknown"));
ext_tree_hdr_list = proto_item_add_subtree(te, ett_gtp_hdr_list);
proto_tree_add_text(ext_tree_hdr_list, tvb, offset + 1, 1, "Number of Extension Header Types in list (i.e., length) : %u", length);
for (i = 0; i < length; i++) {
hdr = tvb_get_guint8(tvb, offset + 2 + i);
proto_tree_add_text(ext_tree_hdr_list, tvb, offset + 2 + i, 1, "No. %u --> Extension Header Type value : %s (%u)", i + 1,
val_to_str_ext_const(hdr, &gtp_val_ext, "Unknown Extension Header Type"), hdr);
}
return 2 + length;
}
static int
decode_gtp_trigger_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
length = tvb_get_ntohs(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 3 + length, "%s length : %u", val_to_str_ext_const(GTP_EXT_TRIGGER_ID, &gtp_val_ext, "Unknown"), length);
return 3 + length;
}
static int
decode_gtp_omc_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
length = tvb_get_ntohs(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 3 + length, "%s length : %u", val_to_str_ext_const(GTP_EXT_OMC_ID, &gtp_val_ext, "Unknown"), length);
return 3 + length;
}
static int
decode_gtp_chrg_addr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
guint32 addr_ipv4;
struct e_in6_addr addr_ipv6;
proto_tree *ext_tree_chrg_addr;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s : ", val_to_str_ext_const(GTP_EXT_CHRG_ADDR, &gtp_val_ext, "Unknown"));
ext_tree_chrg_addr = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_CHRG_ADDR]);
proto_tree_add_text(ext_tree_chrg_addr, tvb, offset + 1, 2, "%s length : %u", val_to_str_ext_const(GTP_EXT_CHRG_ADDR, &gtp_val_ext, "Unknown"), length);
switch (length) {
case 4:
addr_ipv4 = tvb_get_ipv4(tvb, offset + 3);
proto_item_append_text(te, "%s", ip_to_str((guint8 *) & addr_ipv4));
proto_tree_add_ipv4(ext_tree_chrg_addr, hf_gtp_chrg_ipv4, tvb, offset + 3, 4, addr_ipv4);
break;
case 16:
tvb_get_ipv6(tvb, offset + 3, &addr_ipv6);
proto_item_append_text(te, "%s", ip6_to_str((struct e_in6_addr *) &addr_ipv6));
proto_tree_add_ipv6(ext_tree_chrg_addr, hf_gtp_chrg_ipv6, tvb, offset + 3, 16, (guint8 *) & addr_ipv6);
break;
default:
proto_item_append_text(te, "unknown type or wrong length");
break;
}
return 3 + length;
}
static int
decode_gtp_ran_tr_cont(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
tvbuff_t *next_tvb;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s : ", val_to_str_ext_const(GTP_EXT_RAN_TR_CONT, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_RAN_TR_CONT]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
next_tvb = tvb_new_subset(tvb, offset, length, length);
if (bssgp_handle) {
col_set_fence(pinfo->cinfo, COL_INFO);
call_dissector(bssgp_handle, next_tvb, pinfo, ext_tree);
}
return 3 + length;
}
static int
decode_gtp_pdp_cont_prio(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s : ", val_to_str_ext_const(GTP_EXT_PDP_CONT_PRIO, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_PDP_CONT_PRIO]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_add_rab_setup_inf(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s : ", val_to_str_ext_const(GTP_EXT_ADD_RAB_SETUP_INF, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_ADD_RAB_SETUP_INF]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_ssgn_no(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s : ", val_to_str_ext_const(GTP_EXT_SSGN_NO, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_SSGN_NO]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_common_flgs(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s : ", val_to_str_ext_const(GTP_EXT_COMMON_FLGS, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_COMMON_FLGS]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
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
decode_gtp_apn_res(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree_apn_res;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s : ", val_to_str_ext_const(GTP_EXT_APN_RES, &gtp_val_ext, "Unknown"));
ext_tree_apn_res = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_APN_RES]);
offset++;
proto_tree_add_item(ext_tree_apn_res, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
if (length != 1) {
proto_item *expert_item;
expert_item = proto_tree_add_text(tree, tvb, 0, length, "Wrong length indicated. Expected 1, got %u", length);
expert_add_info_format(pinfo, expert_item, PI_MALFORMED, PI_ERROR, "Wrong length indicated. Expected 1, got %u", length);
PROTO_ITEM_SET_GENERATED(expert_item);
return 3 + length;
}
proto_tree_add_item(ext_tree_apn_res, hf_gtp_ext_apn_res, tvb, offset, length, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_rat_type(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree_rat_type;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_RAT_TYPE, &gtp_val_ext, "Unknown"));
ext_tree_rat_type = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_RAT_TYPE]);
offset++;
proto_tree_add_item(ext_tree_rat_type, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
if (length != 1) {
proto_item *expert_item;
expert_item = proto_tree_add_text(tree, tvb, 0, length, "Wrong length indicated. Expected 1, got %u", length);
expert_add_info_format(pinfo, expert_item, PI_MALFORMED, PI_ERROR, "Wrong length indicated. Expected 1, got %u", length);
PROTO_ITEM_SET_GENERATED(expert_item);
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
guint16 length = tvb_length(tvb);
proto_tree_add_item(tree, hf_gtp_ext_geo_loc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
geo_loc_type = tvb_get_guint8(tvb, offset);
offset++;
if (geo_loc_type == 0)
be_cell_id_aux(tvb, tree, pinfo, offset, length - 1, NULL, 0, 0);
if (geo_loc_type == 1) {
be_cell_id_aux(tvb, tree, pinfo, offset, length - 1, NULL, 0, 4);
offset = offset + 5;
proto_tree_add_item(tree, hf_gtp_ext_sac, tvb, offset, 2, ENC_BIG_ENDIAN);
}
return tvb_bytes_to_str(tvb, 0, length);
}
static int
decode_gtp_usr_loc_inf(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree, *rai_tree;
proto_item *te, *fi;
guint8 geo_loc_type;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_USR_LOC_INF, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_USR_LOC_INF]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_ext_geo_loc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
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
fi = proto_tree_add_text(ext_tree, tvb, offset + 1, 7, "Routeing Area Identity (RAI)");
rai_tree = proto_item_add_subtree(fi, ett_gtp_uli_rai);
dissect_e212_mcc_mnc(tvb, pinfo, rai_tree, offset, TRUE);
offset+=3;
proto_tree_add_item(rai_tree, hf_gtp_rai_lac, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rai_tree, hf_gtp_rai_rac, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_text(tree, tvb, offset, length - 1, "Unknown Location type data");
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
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s: ", val_to_str_ext_const(GTP_EXT_MS_TIME_ZONE, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MS_TIME_ZONE]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
data = tvb_get_guint8(tvb, offset);
sign = (data & 0x08) ? '-' : '+';
data = (data >> 4) + (data & 0x07) * 10;
proto_tree_add_text(ext_tree, tvb, offset, 1, "Timezone: GMT %c %d hours %d minutes", sign, data / 4, data % 4 * 15);
proto_item_append_text(te, "GMT %c %d hours %d minutes", sign, data / 4, data % 4 * 15);
offset++;
data = tvb_get_guint8(tvb, offset) & 0x3;
proto_tree_add_text(ext_tree, tvb, offset, 1, "%s", val_to_str_const(data, daylight_saving_time_vals, "Unknown"));
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
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_IMEISV, &gtp_val_ext, "Unknown"));
ext_imeisv = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_IMEISV]);
offset++;
proto_tree_add_item(ext_imeisv, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
next_tvb = tvb_new_subset(tvb, offset, length, length);
digit_str = unpack_digits(next_tvb, 0);
proto_tree_add_string(ext_imeisv, hf_gtp_ext_imeisv, next_tvb, 0, -1, digit_str);
proto_item_append_text(te, ": %s", digit_str);
return 3 + length;
}
static int
decode_gtp_camel_chg_inf_con(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_CAMEL_CHG_INF_CON, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_CAMEL_CHG_INF_CON]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_mbms_ue_ctx(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_UE_CTX, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_UE_CTX]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_tmgi(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree, *tmgi_tree;
proto_item *te, *ti;
tvbuff_t *next_tvb;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_TMGI, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_TMGI]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
ti = proto_tree_add_item(ext_tree, hf_gtp_tmgi, tvb, offset, length, ENC_NA);
tmgi_tree = proto_item_add_subtree(ti, ett_gtp_tmgi);
next_tvb = tvb_new_subset(tvb, offset, length, length);
de_mid(next_tvb, tmgi_tree, pinfo, 0, length, NULL, 0);
return 3 + length;
}
static int
decode_gtp_rim_ra(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_RIM_RA, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_RIM_RA]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_PROT_CONF_OPT, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_PROT_CONF_OPT]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
dissect_gtp_mbms_ses_dur(tvbuff_t * tvb _U_, packet_info * pinfo _U_, proto_tree * tree _U_)
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_SES_DUR, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_SES_DUR]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_mbms_ses_dur_days, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_mbms_ses_dur_s, tvb, offset, 3, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
dissect_gtp_3gpp_mbms_service_area(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
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
decode_gtp_mbms_sa(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
tvbuff_t *next_tvb;
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_SA, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_SA]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
next_tvb = tvb_new_subset(tvb, offset, length-3, length-3);
dissect_gtp_3gpp_mbms_service_area(next_tvb, pinfo,ext_tree);
return 3 + length;
}
static int
decode_gtp_src_rnc_pdp_ctx_inf(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_SRC_RNC_PDP_CTX_INF, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_SRC_RNC_PDP_CTX_INF]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_add_trs_inf(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_ADD_TRS_INF, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_ADD_TRS_INF]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_hop_count(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_HOP_COUNT, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_HOP_COUNT]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_sel_plmn_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_SEL_PLMN_ID, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_SES_ID]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_mbms_ses_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_SES_ID, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_SES_ID]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_mbms_2g_3g_ind(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_2G_3G_IND, &gtp_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_2G_3G_IND]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_ENH_NSAPI, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_ENH_NSAPI]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_add_mbms_trs_inf(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_ADD_MBMS_TRS_INF, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_ADD_MBMS_TRS_INF]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_mbms_ses_id_rep_no(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_SES_ID_REP_NO, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_SES_ID_REP_NO]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
dissect_gtp_mbms_time_to_data_tr(tvbuff_t * tvb _U_, packet_info * pinfo _U_, proto_tree * tree _U_)
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
proto_item *te;
guint8 time_2_dta_tr;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_TIME_TO_DATA_TR, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_TIME_TO_DATA_TR]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_PS_HO_REQ_CTX, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_PS_HO_REQ_CTX]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_bss_cont(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_BSS_CONT, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_BSS_CONT]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_cell_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_CELL_ID, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_CELL_ID]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_pdu_no(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_PDU_NO, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_PDU_NO]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_bssgp_cause(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_BSSGP_CAUSE, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_BSSGP_CAUSE]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_REQ_MBMS_BEARER_CAP, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_REQ_MBMS_BEARER_CAP]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_RIM_ROUTING_ADDR_DISC, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_RIM_ROUTING_ADDR_DISC]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_LIST_OF_SETUP_PFCS, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_LIST_OF_SETUP_PFCS]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_ps_handover_xid(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
tvbuff_t *next_tvb;
guint8 sapi;
guint8 xid_par_len;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_PS_HANDOVER_XIP_PAR, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_PS_HANDOVER_XIP_PAR]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
sapi = tvb_get_guint8(tvb, offset) & 0x0F;
proto_tree_add_uint(ext_tree, hf_gtp_sapi, tvb, offset, 1, sapi);
offset++;
xid_par_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ext_tree, hf_gtp_xid_par_len, tvb, offset, 1, xid_par_len);
offset++;
if (sndcpxid_handle) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(sndcpxid_handle, next_tvb, pinfo, tree);
} else
proto_tree_add_text(tree, tvb, offset, 0, "Data");
return 4 + length;
}
static int
decode_gtp_ms_inf_chg_rep_act(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MS_INF_CHG_REP_ACT, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MS_INF_CHG_REP_ACT]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_direct_tnl_flg(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_DIRECT_TUNNEL_FLGS, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_DIRECT_TUNNEL_FLGS]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
proto_tree_add_item(ext_tree, hf_gtp_ext_ei, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_ext_gcsi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_ext_dti, tvb, offset, 1, ENC_BIG_ENDIAN);
#if 0
offset++;
#endif
return 3 + length;
}
static int
decode_gtp_corrl_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_CORRELATION_ID, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_CORRELATION_ID]);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "Data not decoded yet");
return 3 + length;
}
static int
decode_gtp_bearer_cntrl_mod(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_BEARER_CONTROL_MODE, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_BEARER_CONTROL_MODE]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_FLOW_ID, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_FLOW_ID]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_IP_MCAST_DIST, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_IP_MCAST_DIST]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_mbms_dist_ack(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MBMS_DIST_ACK, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MBMS_DIST_ACK]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_RELIABLE_IRAT_HO_INF, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_RELIABLE_IRAT_HO_INF]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_rfsp_index(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_RFSP_INDEX, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_RFSP_INDEX]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_fqdn(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, length + 3, "%s", val_to_str_ext_const(GTP_EXT_FQDN, &gtp_val_ext, "Unknown field"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_FQDN]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(ext_tree, tvb, offset + 1, 2, "FQDN length : %u", length);
decode_fqdn(tvb, offset + 3, length, ext_tree);
return 3 + length;
}
static int
decode_gtp_evolved_allc_rtn_p1(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_EVO_ALLO_RETE_P1, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_EVO_ALLO_RETE_P1]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_EVO_ALLO_RETE_P2, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_EVO_ALLO_RETE_P2]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_EXTENDED_COMMON_FLGS, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_EXTENDED_COMMON_FLGS]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_uci(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_UCI, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_UCI]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_csg_inf_rep_act(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_CSG_INF_REP_ACT, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_CSG_INF_REP_ACT]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_csg_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_CSG_ID, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_CSG_ID]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_cmi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_CMI, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_CMI]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_apn_ambr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_AMBR, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_RELIABLE_IRAT_HO_INF]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_UE_NETWORK_CAP, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_UE_NETWORK_CAP]);
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
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_APN_AMBR_WITH_NSAPI, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_APN_AMBR_WITH_NSAPI]);
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
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_apn_ambr_with_nsapi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_UE_AMBR, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_UE_AMBR]);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_GGSN_BACK_OFF_TIME, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_GGSN_BACK_OFF_TIME]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_ext_ggsn_back_off_time_units, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_gtp_ext_ggsn_back_off_timer, tvb, offset, 2, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_sig_pri_ind(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_SIG_PRI_IND, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_SIG_PRI_IND]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_sig_pri_ind_w_nsapi(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_SIG_PRI_IND_W_NSAPI, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_SIG_PRI_IND_W_NSAPI]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_higher_br_16mb_flg(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_HIGHER_BR_16MB_FLG, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_HIGHER_BR_16MB_FLG]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(ext_tree, hf_gtp_higher_br_16mb_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
return 3 + length;
}
static int
decode_gtp_max_mbr_apn_ambr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
guint32 max_ul;
guint32 max_dl;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_MAX_MBR_APN_AMBR, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_MAX_MBR_APN_AMBR]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
max_ul = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(ext_tree, hf_gtp_max_mbr_apn_ambr_ul, tvb, offset, 4, max_ul, "Max MBR/APN-AMBR for uplink : %u %s",
(max_ul) > 1000 ? max_ul/1000 : max_ul,
(max_ul) > 1000 ? "Mbps" : "kbps");
offset += 4;
max_dl = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(ext_tree, hf_gtp_max_mbr_apn_ambr_dl, tvb, offset, 4, max_dl, "Max MBR/APN-AMBR for downlink : %u %s",
(max_dl) > 1000 ? max_dl/1000 : max_dl,
(max_dl) > 1000 ? "Mbps" : "kbps");
return 3 + length;
}
static int
decode_gtp_add_mm_ctx_srvcc(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_ADD_MM_CTX_SRVCC, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_ADD_MM_CTX_SRVCC]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_add_flgs_srvcc(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_ADD_FLGS_SRVCC, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_ADD_FLGS_SRVCC]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_stn_sr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_STN_SR, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_STN_SR]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_c_msisdn(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_C_MSISDN, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_C_MSISDN]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_ext_ranap_cause(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
proto_tree *ext_tree;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "%s", val_to_str_ext_const(GTP_EXT_EXT_RANAP_CAUSE, &gtpv1_val_ext, "Unknown"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ies[GTP_EXT_EXT_RANAP_CAUSE]);
proto_tree_add_item(ext_tree, hf_gtp_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_text(ext_tree, tvb, offset, length, "The rest of the data is not dissected yet");
return 3 + length;
}
static int
decode_gtp_rel_pack(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length, n, number;
proto_tree *ext_tree_rel_pack;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "Sequence numbers of released packets IE");
ext_tree_rel_pack = proto_item_add_subtree(te, ett_gtp_rel_pack);
n = 0;
while (n < length) {
number = tvb_get_ntohs(tvb, offset + 3 + n);
proto_tree_add_text(ext_tree_rel_pack, tvb, offset + 3 + n, 2, "%u", number);
n = n + 2;
}
return 3 + length;
}
static int
decode_gtp_can_pack(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length, n, number;
proto_tree *ext_tree_can_pack;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "Sequence numbers of cancelled packets IE");
ext_tree_can_pack = proto_item_add_subtree(te, ett_gtp_can_pack);
n = 0;
while (n < length) {
number = tvb_get_ntohs(tvb, offset + 3 + n);
proto_tree_add_text(ext_tree_can_pack, tvb, offset + 3 + n, 2, "%u", number);
n = n + 2;
}
return 3 + length;
}
static int
decode_gtp_data_req(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length, cdr_length;
guint8 no, format, app_id, rel_id, ver_id, i;
proto_tree *ext_tree, *ver_tree, *cdr_dr_tree;
proto_item *te, *fmt_item, *ver_item;
tvbuff_t *next_tvb;
te = proto_tree_add_text(tree, tvb, offset, 1, "%s", val_to_str_ext_const(GTP_EXT_DATA_REQ, &gtp_val_ext, "Unknown message"));
ext_tree = proto_item_add_subtree(te, ett_gtp_ext);
offset++;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(ext_tree, tvb, offset, 2, "Length: %u", length);
offset+=2;
no = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ext_tree, tvb, offset, 1, "Number of data records: %u", no);
offset++;
format = tvb_get_guint8(tvb, offset);
fmt_item = proto_tree_add_text(ext_tree, tvb, offset, 1, "Data record format: %u", format);
offset++;
if(format < 4) {
proto_item_append_text(fmt_item, " %s", val_to_str_const(format, gtp_cdr_fmt_vals, "Unknown"));
app_id = tvb_get_guint8(tvb,offset);
rel_id = app_id & 0x0f;
app_id = app_id >>4;
ver_id =tvb_get_guint8(tvb,offset+1);
if(ver_id < 0x65)
ver_id = ver_id -1;
ver_item = proto_tree_add_text(ext_tree, tvb, offset, 2, "Data record format version: AppId %u Rel %u.%u.0", app_id,rel_id,ver_id);
ver_tree = proto_item_add_subtree(ver_item, ett_gtp_cdr_ver);
proto_tree_add_item(ver_tree, hf_gtp_cdr_app, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ver_tree, hf_gtp_cdr_rel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ver_tree, hf_gtp_cdr_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for(i = 0; i < no; ++i) {
cdr_length = tvb_get_ntohs(tvb, offset);
te = proto_tree_add_text(ext_tree, tvb, offset, cdr_length+2, "Data record %d", i + 1);
cdr_dr_tree = proto_item_add_subtree(te, ett_gtp_cdr_dr);
proto_tree_add_text(cdr_dr_tree, tvb, offset, 2, "Length: %u", cdr_length);
offset+=2;
proto_tree_add_text(cdr_dr_tree, tvb, offset, cdr_length, "Content");
next_tvb = tvb_new_subset_remaining(tvb, offset);
if(format==1) {
dissect_gprscdr_GPRSCallEventRecord_PDU(next_tvb, pinfo, cdr_dr_tree);
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
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "Requests responded");
ext_tree_data_resp = proto_item_add_subtree(te, ett_gtp_data_resp);
n = 0;
while (n < length) {
number = tvb_get_ntohs(tvb, offset + 3 + n);
proto_tree_add_text(ext_tree_data_resp, tvb, offset + 3 + n, 2, "%u", number);
n = n + 2;
}
return 3 + length;
}
static int
decode_gtp_node_addr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length;
guint32 addr_ipv4;
struct e_in6_addr addr_ipv6;
proto_tree *ext_tree_node_addr;
proto_item *te;
length = tvb_get_ntohs(tvb, offset + 1);
te = proto_tree_add_text(tree, tvb, offset, 3 + length, "Node address: ");
ext_tree_node_addr = proto_item_add_subtree(te, ett_gtp_node_addr);
proto_tree_add_text(ext_tree_node_addr, tvb, offset + 1, 2, "Node address length: %u", length);
switch (length) {
case 4:
addr_ipv4 = tvb_get_ipv4(tvb, offset + 3);
proto_item_append_text(te, "%s", ip_to_str((guint8 *) & addr_ipv4));
proto_tree_add_ipv4(ext_tree_node_addr, hf_gtp_node_ipv4, tvb, offset + 3, 4, addr_ipv4);
break;
case 16:
tvb_get_ipv6(tvb, offset + 3, &addr_ipv6);
proto_item_append_text(te, "%s", ip6_to_str((struct e_in6_addr *) &addr_ipv6));
proto_tree_add_ipv6(ext_tree_node_addr, hf_gtp_node_ipv6, tvb, offset + 3, 16, (guint8 *) & addr_ipv6);
break;
default:
proto_item_append_text(te, "unknown type or wrong length");
break;
}
return 3 + length;
}
static int
decode_gtp_priv_ext(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 length, ext_id;
proto_tree *ext_tree_priv_ext;
proto_item *te;
tvbuff_t *next_tvb;
te = proto_tree_add_text(tree, tvb, offset, 1, "%s", val_to_str_ext_const(GTP_EXT_PRIV_EXT, &gtp_val_ext, "Unknown message"));
ext_tree_priv_ext = proto_item_add_subtree(te, ett_gtp_ext);
offset++;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ext_tree_priv_ext, hf_gtp_ext_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
if (length >= 2) {
ext_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(ext_tree_priv_ext, hf_gtp_ext_id, tvb, offset, 2, ext_id);
offset = offset + 2;
if (length > 2) {
proto_tree_add_item(ext_tree_priv_ext, hf_gtp_ext_val, tvb, offset, length - 2, ENC_NA);
next_tvb = tvb_new_subset_remaining(tvb, offset);
dissector_try_uint(gtp_priv_ext_dissector_table, ext_id, next_tvb, pinfo, ext_tree_priv_ext);
}
}
return 3 + length;
}
static int
decode_gtp_unknown(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree_add_text(tree, tvb, offset, 1, "Unknown extension header");
return tvb_length_remaining(tvb, offset);
}
static void
dissect_gtp_common(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
struct _gtp_hdr gtp_hdr;
proto_tree *gtp_tree, *flags_tree, *ext_tree;
proto_item *ti, *tf, *item;
int i, offset, length, gtp_prime, checked_field, mandatory;
int seq_no = 0;
int flow_label = 0;
guint8 pdu_no, next_hdr = 0;
guint8 ext_hdr_val;
guint8 noOfExtHdrs = 0;
guint8 ext_hdr_length;
gchar *tid_str;
guint32 teid = 0;
tvbuff_t *next_tvb;
guint8 sub_proto;
guint8 acfield_len = 0;
guint8 control_field;
gtp_msg_hash_t *gcrp = NULL;
conversation_t *conversation = NULL;
gtp_conv_info_t *gtp_info;
void* pd_save;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GTP");
col_clear(pinfo->cinfo, COL_INFO);
conversation = find_or_create_conversation(pinfo);
gtp_info = conversation_get_proto_data(conversation, proto_gtp);
if (gtp_info == NULL) {
gtp_info = g_malloc(sizeof(gtp_conv_info_t));
gtp_info->matched = g_hash_table_new(gtp_sn_hash, gtp_sn_equal_matched);
gtp_info->unmatched = g_hash_table_new(gtp_sn_hash, gtp_sn_equal_unmatched);
conversation_add_proto_data(conversation, proto_gtp, gtp_info);
gtp_info->next = gtp_info_items;
gtp_info_items = gtp_info;
}
pd_save = pinfo->private_data;
pinfo->private_data = gtp_info;
tvb_memcpy(tvb, (guint8 *) & gtp_hdr, 0, 4);
if (!(gtp_hdr.flags & 0x10))
gtp_prime = 1;
else
gtp_prime = 0;
switch ((gtp_hdr.flags >> 5) & 0x07) {
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
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_ext_const(gtp_hdr.message, &gtp_message_type_ext, "Unknown"));
if (tree) {
ti = proto_tree_add_item(tree, proto_gtp, tvb, 0, -1, ENC_NA);
gtp_tree = proto_item_add_subtree(ti, ett_gtp);
tf = proto_tree_add_uint(gtp_tree, hf_gtp_flags, tvb, 0, 1, gtp_hdr.flags);
flags_tree = proto_item_add_subtree(tf, ett_gtp_flags);
if(gtp_prime == 1) {
proto_tree_add_uint(flags_tree, hf_gtp_prime_flags_ver, tvb, 0, 1, gtp_hdr.flags);
proto_tree_add_uint(flags_tree, hf_gtp_flags_pt, tvb, 0, 1, gtp_hdr.flags);
proto_tree_add_uint(flags_tree, hf_gtp_flags_spare1, tvb, 0, 1, gtp_hdr.flags);
if(gtp_version == 0) {
proto_tree_add_item(flags_tree, hf_gtp_flags_hdr_length, tvb, 0, 1, ENC_BIG_ENDIAN);
}
} else {
proto_tree_add_uint(flags_tree, hf_gtp_flags_ver, tvb, 0, 1, gtp_hdr.flags);
proto_tree_add_uint(flags_tree, hf_gtp_flags_pt, tvb, 0, 1, gtp_hdr.flags);
if(gtp_version == 0) {
proto_tree_add_uint(flags_tree, hf_gtp_flags_spare1, tvb, 0, 1, gtp_hdr.flags);
proto_tree_add_boolean(flags_tree, hf_gtp_flags_snn, tvb, 0, 1, gtp_hdr.flags);
} else {
proto_tree_add_uint(flags_tree, hf_gtp_flags_spare2, tvb, 0, 1, gtp_hdr.flags);
proto_tree_add_boolean(flags_tree, hf_gtp_flags_e, tvb, 0, 1, gtp_hdr.flags);
proto_tree_add_boolean(flags_tree, hf_gtp_flags_s, tvb, 0, 1, gtp_hdr.flags);
proto_tree_add_boolean(flags_tree, hf_gtp_flags_pn, tvb, 0, 1, gtp_hdr.flags);
}
}
proto_tree_add_uint(gtp_tree, hf_gtp_message_type, tvb, 1, 1, gtp_hdr.message);
gtp_hdr.length = g_ntohs(gtp_hdr.length);
proto_tree_add_uint(gtp_tree, hf_gtp_length, tvb, 2, 2, gtp_hdr.length);
offset = 4;
if (gtp_prime) {
seq_no = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_seq_number, tvb, offset, 2, seq_no);
offset += 2;
if( (gtp_version == 0) && ((gtp_hdr.flags & 0x01) == 0) ) {
offset = GTPv0_HDR_LENGTH;
}
} else {
switch (gtp_version) {
case 0:
seq_no = tvb_get_ntohs(tvb, offset);
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
break;
case 1:
teid = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_teid, tvb, offset, 4, teid);
offset += 4;
if (gtp_hdr.flags & 0x07) {
seq_no = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_seq_number, tvb, offset, 2, seq_no);
offset += 2;
pdu_no = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_npdu_number, tvb, offset, 1, pdu_no);
offset++;
next_hdr = tvb_get_guint8(tvb, offset);
offset++;
if (next_hdr) {
noOfExtHdrs++;
tf = proto_tree_add_uint(gtp_tree, hf_gtp_ext_hdr, tvb, offset, 4, next_hdr);
ext_tree = proto_item_add_subtree(tf, ett_gtp_ext_hdr);
if (next_hdr == GTP_EXT_HDR_PDCP_SN) {
ext_hdr_length = tvb_get_guint8(tvb, offset);
if (ext_hdr_length != 1) {
expert_add_info_format(pinfo, ext_tree, PI_PROTOCOL, PI_WARN, "The length field for the PDCP SN Extension header should be 1.");
}
proto_tree_add_item(ext_tree, hf_gtp_ext_hdr_length, tvb, offset,1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ext_tree, hf_gtp_ext_hdr_pdcpsn, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
next_hdr = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(ext_tree, hf_gtp_ext_hdr_next, tvb, offset, 1, ENC_BIG_ENDIAN);
if (next_hdr) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "Can't decode more than one extension header.");
}
offset++;
}
}
}
break;
default:
break;
}
}
if (gtp_hdr.message != GTP_MSG_TPDU) {
if (next_hdr) {
switch (next_hdr) {
case 1:
proto_tree_add_text(gtp_tree, tvb, offset, 4, "[--- MBMS support indication header ---]");
offset += 3;
break;
case 2:
proto_tree_add_text(gtp_tree, tvb, offset, 4, "[--- MS Info Change Reporting support indication header ---]");
offset += 3;
break;
case 0xc0:
proto_tree_add_text(gtp_tree, tvb, offset, 4, "[--- PDCP PDU number header ---]");
offset += 3;
break;
case 0xc1:
proto_tree_add_text(gtp_tree, tvb, offset, 4, "[--- Suspend Request header ---]");
offset += 3;
break;
case 0xc2:
proto_tree_add_text(gtp_tree, tvb, offset, 4, "[--- Suspend Response header ---]");
offset += 3;
break;
default:
proto_tree_add_text(gtp_tree, tvb, offset, 4, "[--- Unknown extension header ---]");
offset += 3;
break;
}
next_hdr = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(gtp_tree, hf_gtp_next, tvb, offset, 1, next_hdr);
offset++;
}
length = tvb_length(tvb);
mandatory = 0;
for (;;) {
if (offset >= length)
break;
if (next_hdr) {
ext_hdr_val = next_hdr;
next_hdr = 0;
} else
ext_hdr_val = tvb_get_guint8(tvb, offset);
if (g_gtp_etsi_order) {
checked_field = check_field_presence(gtp_hdr.message, ext_hdr_val, (int *) &mandatory);
switch (checked_field) {
case -2:
proto_tree_add_text(gtp_tree, tvb, 0, 0, "[WARNING] message not found");
break;
case -1:
proto_tree_add_text(gtp_tree, tvb, 0, 0, "[WARNING] field not present");
break;
case 0:
break;
default:
proto_tree_add_text(gtp_tree, tvb, offset, 1, "[WARNING] wrong next field, should be: %s",
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
if (seq_no) {
gcrp = gtp_match_response(tvb, pinfo, gtp_tree, seq_no, gtp_hdr.message);
if (gcrp) {
tap_queue_packet(gtp_tap,pinfo,gcrp);
}
}
}
proto_item_set_len (ti, offset);
}
if ((gtp_hdr.message == GTP_MSG_TPDU) && g_gtp_tpdu) {
if (gtp_prime)
offset = 6;
else if (gtp_version == 1) {
if (gtp_hdr.flags & 0x07) {
offset = 11;
if (tvb_get_guint8(tvb, offset) == 0)
offset++;
} else
offset = 8;
} else
offset = 20;
if(gtp_hdr.length > offset){
proto_tree_add_text(tree, tvb, offset, gtp_hdr.length, "T-PDU Data %u bytes", gtp_hdr.length);
}
if (noOfExtHdrs != 0) offset+= 1 + noOfExtHdrs*4;
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
col_prepend_fstr(pinfo->cinfo, COL_PROTOCOL, "GTP <");
col_append_str(pinfo->cinfo, COL_PROTOCOL, ">");
}
#if 0
else {
if (gtp_prime)
offset = 6;
else if (gtp_version == 1) {
if (gtp_hdr.flags & 0x07) {
offset = 11;
if (tvb_get_guint8(tvb, offset) == 0)
offset++;
} else
offset = 8;
} else
offset = 20;
}
#endif
pinfo->private_data = pd_save;
}
static void
dissect_gtpprim(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
dissect_gtp_common(tvb, pinfo, tree);
}
static void
dissect_gtp(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint8 version;
version = tvb_get_guint8(tvb,0)>>5;
if (version == 2) {
if (gtpv2_handle) {
call_dissector(gtpv2_handle, tvb, pinfo, tree);
return;
}
}
if(version > 2) {
proto_tree_add_text(tree, tvb, 0, -1, "No WS dissector for GTP version %u %s", version,
val_to_str_const(version, ver_types, "Unknown"));
return;
}
dissect_gtp_common(tvb, pinfo, tree);
}
static void
gtp_reinit(void)
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
NULL, HFILL}
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
FT_UINT8, BASE_HEX, VALS(next_extension_header_fieldvals), 0,
NULL, HFILL}
},
{&hf_gtp_ext_hdr_next,
{ "Next extension header", "gtp.ext_hdr.next",
FT_UINT8, BASE_HEX, VALS(next_extension_header_fieldvals), 0,
NULL, HFILL}
},
{&hf_gtp_ext_hdr_pdcpsn,
{ "PDCP Sequence Number", "gtp.ext_hdr.pdcp_sn",
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
{ "Header length", "gtp.flags._hdr_length",
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
{&hf_gtp_imsi,
{ "IMSI", "gtp.imsi",
FT_STRING, BASE_NONE, NULL, 0,
"International Mobile Subscriber Identity number", HFILL}
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
{&hf_gtp_next,
{ "Next extension header type", "gtp.next",
FT_UINT8, BASE_HEX, VALS(next_extension_header_fieldvals), 0,
NULL,
HFILL}
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
FT_UINT8, BASE_DEC, NULL, 0,
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
{ &hf_gtp_qos_arp_pci,
{"Pre-emption Capability (PCI)", "gtp.qos_arp_pci",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x40,
NULL, HFILL}
},
{ &hf_gtp_qos_arp_pl,
{"Priority Level", "gtp.qos_arp_pl",
FT_UINT8, BASE_DEC, NULL, 0x3c,
NULL, HFILL}
},
{ &hf_gtp_qos_arp_pvi,
{"Pre-emption Vulnerability (PVI)", "gtp.qos_arp_pvi",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01,
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
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtp_ext_imeisv,
{ "IMEI(SV)", "gtp.ext_imeisv",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtp_targetRNC_ID,
{ "targetRNC-ID", "gtp.targetRNC_ID",
FT_NONE, BASE_NONE, NULL, 0,
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
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL}
},
{&hf_gtp_earp_pl,
{ "PL Priority Level", "gtp.EARP_priority_level",
FT_UINT8, BASE_DEC, NULL, 0x3C,
NULL, HFILL}
},
{&hf_gtp_earp_pci,
{ "PCI Pre-emption Capability", "gtp.EARP_pre_emption_Capability",
FT_UINT8, BASE_DEC, NULL, 0x40,
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
};
#define GTP_NUM_INDIVIDUAL_ELEMS 27
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
ett_gtp_array[16] = &ett_gtp_net_cap;
ett_gtp_array[17] = &ett_gtp_can_pack;
ett_gtp_array[18] = &ett_gtp_proto;
ett_gtp_array[19] = &ett_gtp_gsn_addr;
ett_gtp_array[20] = &ett_gtp_tft;
ett_gtp_array[21] = &ett_gtp_tft_pf;
ett_gtp_array[22] = &ett_gtp_tft_flags;
ett_gtp_array[23] = &ett_gtp_rab_setup;
ett_gtp_array[24] = &ett_gtp_hdr_list;
ett_gtp_array[25] = &ett_gtp_rel_pack;
ett_gtp_array[26] = &ett_gtp_node_addr;
last_offset = GTP_NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_GTP_IES; i++, last_offset++)
{
ett_gtp_ies[i] = -1;
ett_gtp_array[last_offset] = &ett_gtp_ies[i];
}
proto_gtp = proto_register_protocol("GPRS Tunneling Protocol", "GTP", "gtp");
proto_register_field_array(proto_gtp, hf_gtp, array_length(hf_gtp));
proto_register_subtree_array(ett_gtp_array, array_length(ett_gtp_array));
gtp_module = prefs_register_protocol(proto_gtp, proto_reg_handoff_gtp);
prefs_register_uint_preference(gtp_module, "v0_port", "GTPv0 and GTP' port", "GTPv0 and GTP' port (default 3386)", 10, &g_gtpv0_port);
prefs_register_uint_preference(gtp_module, "v1c_port", "GTPv1 or GTPv2 control plane (GTP-C, GTPv2-C) port", "GTPv1 and GTPv2 control plane port (default 2123)", 10,
&g_gtpv1c_port);
prefs_register_uint_preference(gtp_module, "v1u_port", "GTPv1 user plane (GTP-U) port", "GTPv1 user plane port (default 2152)", 10,
&g_gtpv1u_port);
prefs_register_bool_preference(gtp_module, "dissect_tpdu", "Dissect T-PDU", "Dissect T-PDU", &g_gtp_tpdu);
prefs_register_obsolete_preference(gtp_module, "v0_dissect_cdr_as");
prefs_register_obsolete_preference(gtp_module, "v0_check_etsi");
prefs_register_obsolete_preference(gtp_module, "v1_check_etsi");
prefs_register_bool_preference(gtp_module, "check_etsi", "Compare GTP order with ETSI", "GTP ETSI order", &g_gtp_etsi_order);
prefs_register_obsolete_preference(gtp_module, "ppp_reorder");
prefs_register_bool_preference(gtp_module, "dissect_gtp_over_tcp", "Dissect GTP over TCP", "Dissect GTP over TCP", &g_gtp_over_tcp);
register_dissector("gtp", dissect_gtp, proto_gtp);
register_dissector("gtpprim", dissect_gtpprim, proto_gtp);
gtp_priv_ext_dissector_table = register_dissector_table("gtp.priv_ext", "GTP PRIVATE EXT", FT_UINT16, BASE_DEC);
gtp_cdr_fmt_dissector_table = register_dissector_table("gtp.cdr_fmt", "GTP DATA RECORD TYPE", FT_UINT16, BASE_DEC);
register_init_routine(gtp_reinit);
gtp_tap=register_tap("gtp");
}
void
proto_reg_handoff_gtp(void)
{
static gboolean Initialized = FALSE;
static dissector_handle_t gtp_handle, gtp_prim_handle;
static gboolean gtp_over_tcp;
static guint gtpv0_port;
static guint gtpv1c_port;
static guint gtpv1u_port;
if (!Initialized) {
gtp_handle = find_dissector("gtp");
gtp_prim_handle = find_dissector("gtpprim");
ppp_subdissector_table = find_dissector_table("ppp.protocol");
radius_register_avp_dissector(VENDOR_THE3GPP, 5, dissect_radius_qos_umts);
radius_register_avp_dissector(VENDOR_THE3GPP, 12, dissect_radius_selection_mode);
radius_register_avp_dissector(VENDOR_THE3GPP, 22, dissect_radius_user_loc);
ip_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
ppp_handle = find_dissector("ppp");
data_handle = find_dissector("data");
gtpcdr_handle = find_dissector("gtpcdr");
sndcpxid_handle = find_dissector("sndcpxid");
gtpv2_handle = find_dissector("gtpv2");
bssgp_handle = find_dissector("bssgp");
bssap_pdu_type_table = find_dissector_table("bssap.pdu_type");
dissector_add_uint("diameter.3gpp", 5, new_create_dissector_handle(dissect_diameter_3gpp_qosprofile, proto_gtp));
dissector_add_uint("diameter.3gpp", 903, new_create_dissector_handle(dissect_gtp_3gpp_mbms_service_area, proto_gtp));
dissector_add_uint("diameter.3gpp", 904, new_create_dissector_handle(dissect_gtp_mbms_ses_dur, proto_gtp));
dissector_add_uint("diameter.3gpp", 911, new_create_dissector_handle(dissect_gtp_mbms_time_to_data_tr, proto_gtp));
Initialized = TRUE;
} else {
dissector_delete_uint("udp.port", gtpv0_port, gtp_prim_handle);
dissector_delete_uint("udp.port", gtpv1c_port, gtp_handle);
dissector_delete_uint("udp.port", gtpv1u_port, gtp_handle);
if (gtp_over_tcp) {
dissector_delete_uint("tcp.port", gtpv0_port, gtp_prim_handle);
dissector_delete_uint("tcp.port", gtpv1c_port, gtp_handle);
dissector_delete_uint("tcp.port", gtpv1u_port, gtp_handle);
}
}
gtp_over_tcp = g_gtp_over_tcp;
gtpv0_port = g_gtpv0_port;
gtpv1c_port = g_gtpv1c_port;
gtpv1u_port = g_gtpv1u_port;
dissector_add_uint("udp.port", g_gtpv0_port, gtp_prim_handle);
dissector_add_uint("udp.port", g_gtpv1c_port, gtp_handle);
dissector_add_uint("udp.port", g_gtpv1u_port, gtp_handle);
if (g_gtp_over_tcp) {
dissector_add_uint("tcp.port", g_gtpv0_port, gtp_prim_handle);
dissector_add_uint("tcp.port", g_gtpv1c_port, gtp_handle);
dissector_add_uint("tcp.port", g_gtpv1u_port, gtp_handle);
}
}
