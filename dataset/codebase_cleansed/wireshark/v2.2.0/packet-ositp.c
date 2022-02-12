static void cotp_frame_end(void)
{
if (!cotp_last_fragment) {
cotp_dst_ref--;
}
cotp_frame_reset = TRUE;
}
static gboolean is_all_printable(const guchar *stringtocheck, int length)
{
gboolean allprintable;
int i;
allprintable=TRUE;
for (i=0;i<length;i++) {
if (!g_ascii_isprint(stringtocheck[i])) {
allprintable=FALSE;
break;
}
}
return allprintable;
}
static gchar *print_tsap(tvbuff_t *tvb, int offset, int length)
{
const guchar *tsap = tvb_get_ptr(tvb, offset, length);
gchar *cur;
gboolean allprintable;
gint idx = 0, returned_length;
cur=(gchar *)wmem_alloc(wmem_packet_scope(), MAX_TSAP_LEN * 2 + 3);
cur[0] = '\0';
if (length <= 0 || length > MAX_TSAP_LEN)
g_snprintf(cur, MAX_TSAP_LEN * 2 + 3, "<unsupported TSAP length>");
else {
allprintable = is_all_printable(tsap,length);
if (!allprintable) {
returned_length = g_snprintf(cur, MAX_TSAP_LEN * 2 + 3, "0x");
idx += MIN(returned_length, MAX_TSAP_LEN * 2 + 3 - 1);
}
while (length != 0) {
if (allprintable) {
returned_length = g_snprintf(&cur[idx], MAX_TSAP_LEN * 2 + 3 - idx,
"%c", *tsap ++);
idx += MIN(returned_length, MAX_TSAP_LEN * 2 + 3 - idx - 1);
} else {
returned_length = g_snprintf(&cur[idx], MAX_TSAP_LEN * 2 + 3 - idx,
"%02x", *tsap ++);
idx += MIN(returned_length, MAX_TSAP_LEN * 2 + 3 - idx - 1);
}
length --;
}
}
return cur;
}
static gboolean ositp_decode_var_part(tvbuff_t *tvb, int offset, int vp_length,
int class_option, int tpdu_len,
packet_info *pinfo, proto_tree *tree)
{
guint8 code, length;
guint8 c1;
guint16 s;
guint32 offset_iso8073_checksum = 0;
gint32 i = 0;
guint8 tmp_code = 0;
guint tmp_len = 0;
guint32 pref_max_tpdu_size;
proto_item *hidden_item;
while (vp_length != 0) {
code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_cotp_parameter_code, tvb, offset, 1, ENC_NA);
offset += 1;
vp_length -= 1;
if (vp_length == 0)
break;
length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_cotp_parameter_length, tvb, offset, 1, ENC_NA);
offset += 1;
vp_length -= 1;
switch (code) {
case VP_ATN_EC_16 :
if (cotp_decode_atn) {
guint16 sum;
if (!offset_iso8073_checksum) {
for (i = offset + length; i < vp_length;) {
tmp_code = tvb_get_guint8(tvb, i++);
tmp_len = tvb_get_guint8(tvb, i++);
if (tmp_code == VP_CHECKSUM) {
offset_iso8073_checksum = i;
break;
}
i += tmp_len;
}
}
sum = check_atn_ec_16(tvb, tpdu_len , offset,
offset_iso8073_checksum,
pinfo->dst.len, (const guint8 *)pinfo->dst.data,
pinfo->src.len, (const guint8 *)pinfo->src.data);
proto_tree_add_checksum(tree, tvb, offset, hf_cotp_atn_extended_checksum16, -1, NULL, pinfo, sum, ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY|PROTO_CHECKSUM_ZERO);
} else {
proto_tree_add_bytes_format_value(tree, hf_cotp_parameter_value, tvb, offset, length, NULL, "<not shown>");
}
offset += length;
vp_length -= length;
break;
case VP_ATN_EC_32 :
if (cotp_decode_atn) {
guint32 sum;
if (!offset_iso8073_checksum) {
for (i = offset + length; i < vp_length;) {
tmp_code = tvb_get_guint8(tvb, i++);
tmp_len = tvb_get_guint8(tvb, i++);
if (tmp_code == VP_CHECKSUM) {
offset_iso8073_checksum = i;
break;
}
i += tmp_len;
}
}
sum = check_atn_ec_32(tvb, tpdu_len , offset,
offset_iso8073_checksum,
pinfo->dst.len, (const guint8 *)pinfo->dst.data,
pinfo->src.len, (const guint8 *)pinfo->src.data);
proto_tree_add_checksum(tree, tvb, offset, hf_cotp_atn_extended_checksum32, -1, NULL, pinfo, sum, ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY|PROTO_CHECKSUM_ZERO);
} else {
proto_tree_add_bytes_format_value(tree, hf_cotp_parameter_value, tvb, offset, length, NULL, "<not shown>");
}
offset += length;
vp_length -= length;
break;
case VP_ACK_TIME:
proto_tree_add_item(tree, hf_cotp_ack_time, tvb, offset, length, ENC_BIG_ENDIAN);
offset += length;
vp_length -= length;
break;
case VP_RES_ERROR:
s = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_cotp_res_error_rate_target_value, tvb, offset, 1,
s, "Residual error rate, target value: 10^%u", s);
offset += 1;
vp_length -= 1;
s = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_cotp_res_error_rate_min_accept, tvb, offset, 1,
s, "Residual error rate, minimum acceptable: 10^%u", s);
offset += 1;
vp_length -= 1;
s = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree,hf_cotp_res_error_rate_tdsu, tvb, offset, 1, 1 << s);
offset += 1;
vp_length -= 1;
break;
case VP_PRIORITY:
proto_tree_add_item(tree, hf_cotp_vp_priority, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += length;
vp_length -= length;
break;
case VP_TRANSIT_DEL:
proto_tree_add_item(tree, hf_cotp_transit_delay_targ_calling_called, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
vp_length -= 2;
proto_tree_add_item(tree, hf_cotp_transit_delay_max_accept_calling_called, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
vp_length -= 2;
proto_tree_add_item(tree, hf_cotp_transit_delay_targ_called_calling, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
vp_length -= 2;
proto_tree_add_item(tree, hf_cotp_transit_delay_max_accept_called_calling, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
vp_length -= 2;
break;
case VP_THROUGHPUT:
proto_tree_add_item(tree, hf_cotp_max_throughput_targ_calling_called, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
length -= 3;
vp_length -= 3;
proto_tree_add_item(tree, hf_cotp_max_throughput_min_accept_calling_called, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
length -= 3;
vp_length -= 3;
proto_tree_add_item(tree, hf_cotp_max_throughput_targ_called_calling, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
length -= 3;
vp_length -= 3;
proto_tree_add_item(tree, hf_cotp_max_throughput_min_accept_called_calling, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
length -= 3;
vp_length -= 3;
if (length != 0) {
proto_tree_add_item(tree, hf_cotp_avg_throughput_targ_calling_called, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
vp_length -= 3;
proto_tree_add_item(tree, hf_cotp_avg_throughput_min_accept_calling_called, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
vp_length -= 3;
proto_tree_add_item(tree, hf_cotp_avg_throughput_targ_called_calling, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
vp_length -= 3;
proto_tree_add_item(tree, hf_cotp_avg_throughput_min_accept_called_calling, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
vp_length -= 3;
}
break;
case VP_SEQ_NR:
proto_tree_add_item(tree, hf_cotp_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += length;
vp_length -= length;
break;
case VP_REASSIGNMENT:
proto_tree_add_item(tree, hf_cotp_reassignment_time, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += length;
vp_length -= length;
break;
case VP_FLOW_CNTL:
proto_tree_add_item(tree, hf_cotp_lower_window_edge, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
vp_length -= 4;
proto_tree_add_item(tree, hf_cotp_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
vp_length -= 2;
proto_tree_add_item(tree, hf_cotp_credit, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
vp_length -= 2;
break;
case VP_TPDU_SIZE:
c1 = tvb_get_guint8(tvb, offset) & 0x0F;
proto_tree_add_uint(tree, hf_cotp_tpdu_size, tvb, offset, 1, 1 << c1);
offset += length;
vp_length -= length;
break;
case VP_SRC_TSAP:
if (tsap_display==TSAP_DISPLAY_STRING ||
(tsap_display==TSAP_DISPLAY_AUTO &&
is_all_printable(tvb_get_ptr(tvb, offset,length),length))) {
proto_tree_add_string(tree, hf_cotp_vp_src_tsap, tvb, offset, length,
print_tsap(tvb, offset, length));
hidden_item = proto_tree_add_item(tree, hf_cotp_vp_src_tsap_bytes, tvb,
offset, length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else {
hidden_item = proto_tree_add_string(tree, hf_cotp_vp_src_tsap, tvb,
offset, length,
print_tsap(tvb, offset, length));
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(tree, hf_cotp_vp_src_tsap_bytes, tvb, offset,
length, ENC_NA);
}
offset += length;
vp_length -= length;
break;
case VP_DST_TSAP:
if (tsap_display==TSAP_DISPLAY_STRING ||
(tsap_display==TSAP_DISPLAY_AUTO &&
is_all_printable(tvb_get_ptr(tvb,offset,length),length))) {
proto_tree_add_string(tree, hf_cotp_vp_dst_tsap, tvb, offset, length,
print_tsap(tvb, offset, length));
hidden_item = proto_tree_add_item(tree, hf_cotp_vp_dst_tsap_bytes, tvb,
offset, length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else {
hidden_item = proto_tree_add_string(tree, hf_cotp_vp_dst_tsap, tvb,
offset, length,
print_tsap(tvb, offset, length));
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(tree, hf_cotp_vp_dst_tsap_bytes, tvb, offset,
length, ENC_NA);
}
offset += length;
vp_length -= length;
break;
case VP_CHECKSUM:
offset_iso8073_checksum = offset;
if (tvb_get_ntohs(tvb, offset) == 0) {
proto_tree_add_checksum(tree, tvb, offset, hf_cotp_checksum, -1, NULL, pinfo, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NOT_PRESENT);
} else {
guint32 calc_c0 = 0, calc_c1 = 0;
if (osi_calc_checksum(tvb, 0, length, &calc_c0, &calc_c1)) {
proto_tree_add_checksum(tree, tvb, offset, hf_cotp_checksum, -1, NULL, pinfo, calc_c0 | calc_c1, ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY|PROTO_CHECKSUM_ZERO);
} else {
proto_tree_add_checksum(tree, tvb, offset, hf_cotp_checksum, -1, NULL, pinfo, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
}
}
offset += length;
vp_length -= length;
break;
case VP_VERSION_NR:
proto_tree_add_item(tree, hf_cotp_vp_version_nr, tvb, offset, 1, ENC_NA);
offset += length;
vp_length -= length;
break;
case VP_OPT_SEL:
switch (class_option) {
case 1:
proto_tree_add_item(tree, hf_cotp_network_expedited_data, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_cotp_vp_opt_sel_class1_use, tvb, offset, 1, ENC_NA);
break;
case 4:
proto_tree_add_item(tree, hf_cotp_use_16_bit_checksum, tvb, offset, 1, ENC_NA);
break;
}
proto_tree_add_item(tree, hf_cotp_transport_expedited_data_transfer, tvb, offset, 1, ENC_NA);
offset += length;
vp_length -= length;
break;
case VP_PREF_MAX_TPDU_SIZE:
switch (length) {
case 1:
pref_max_tpdu_size = tvb_get_guint8(tvb, offset);
break;
case 2:
pref_max_tpdu_size = tvb_get_ntohs(tvb, offset);
break;
case 3:
pref_max_tpdu_size = tvb_get_ntoh24(tvb, offset);
break;
case 4:
pref_max_tpdu_size = tvb_get_ntohl(tvb, offset);
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_cotp_preferred_maximum_tpdu_size, tvb, offset, length,
"Preferred maximum TPDU size: bogus length %u (not 1, 2, 3, or 4)", length);
return FALSE;
}
proto_tree_add_uint(tree, hf_cotp_preferred_maximum_tpdu_size, tvb, offset, length, pref_max_tpdu_size*128);
offset += length;
vp_length -= length;
break;
case VP_INACTIVITY_TIMER:
proto_tree_add_item(tree, hf_cotp_inactivity_timer, tvb, offset, length, ENC_BIG_ENDIAN);
offset += length;
vp_length -= length;
break;
case VP_PROTECTION:
case VP_PROTO_CLASS:
case VP_CLEARING_INFO:
default:
proto_tree_add_bytes_format_value(tree, hf_cotp_parameter_value, tvb, offset, length, NULL, "<not shown>");
offset += length;
vp_length -= length;
break;
}
}
return TRUE;
}
static int ositp_decode_DR(tvbuff_t *tvb, int offset, guint8 li, guint8 tpdu,
packet_info *pinfo, proto_tree *tree)
{
proto_tree *cotp_tree = NULL;
proto_item *ti = NULL;
guint16 dst_ref, src_ref;
guchar reason;
guint tpdu_len;
if (li < LI_MIN_DR)
return -1;
tpdu_len = tvb_reported_length_remaining(tvb, offset);
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
src_ref = tvb_get_ntohs(tvb, offset + P_SRC_REF);
reason = tvb_get_guint8(tvb, offset + P_REASON_IN_DR);
pinfo->clnp_dstref = dst_ref;
pinfo->clnp_srcref = src_ref;
if (try_val_to_str(reason, cotp_cause_vals) == NULL)
return -1;
col_append_fstr(pinfo->cinfo, COL_INFO,
"DR TPDU src-ref: 0x%04x dst-ref: 0x%04x", src_ref, dst_ref);
if (tree) {
ti = proto_tree_add_item(tree, proto_cotp, tvb, offset, li + 1, ENC_NA);
cotp_tree = proto_item_add_subtree(ti, ett_cotp);
proto_tree_add_uint(cotp_tree, hf_cotp_li, tvb, offset, 1,li);
proto_tree_add_uint(cotp_tree, hf_cotp_type, tvb, offset + 1, 1, tpdu);
proto_tree_add_uint(cotp_tree, hf_cotp_destref, tvb, offset + 2, 2,
dst_ref);
proto_tree_add_uint(cotp_tree, hf_cotp_srcref, tvb, offset + 4, 2,
src_ref);
proto_tree_add_item(cotp_tree, hf_cotp_cause, tvb, offset + 6, 1, ENC_NA);
}
offset += 7;
li -= 6;
if (tree)
ositp_decode_var_part(tvb, offset, li, 4, tpdu_len, pinfo, cotp_tree);
offset += li;
expert_add_info_format(pinfo, ti, &ei_cotp_disconnect_request, "Disconnect Request(DR): 0x%x -> 0x%x", src_ref, dst_ref);
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo, tree);
offset += tvb_captured_length_remaining(tvb, offset);
return offset;
}
static int ositp_decode_DT(tvbuff_t *tvb, int offset, guint8 li, guint8 tpdu,
packet_info *pinfo, proto_tree *tree,
gboolean uses_inactive_subset,
gboolean *subdissector_found)
{
proto_tree *cotp_tree = NULL;
proto_item *ti;
gboolean is_extended;
gboolean is_class_234;
guint32 dst_ref;
guint32 *prev_dst_ref;
guint tpdu_nr;
gboolean fragment = FALSE;
guint32 fragment_length = 0;
tvbuff_t *next_tvb;
fragment_head *fd_head;
conversation_t *conv;
guint tpdu_len;
heur_dtbl_entry_t *hdtbl_entry;
tpdu_len = tvb_reported_length_remaining(tvb, offset);
is_class_234 = (li > LI_NORMAL_DT_CLASS_01);
if (!cotp_decode_atn) {
switch (li) {
case LI_NORMAL_DT_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_CHECKSUM)
return -1;
case LI_NORMAL_DT_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80)
tpdu_nr = tpdu_nr & 0x7F;
else
fragment = TRUE;
is_extended = FALSE;
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
break;
case LI_EXTENDED_DT_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_CHECKSUM)
return -1;
case LI_EXTENDED_DT_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80000000)
tpdu_nr = tpdu_nr & 0x7FFFFFFF;
else
fragment = TRUE;
is_extended = TRUE;
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
break;
case LI_NORMAL_DT_CLASS_01 :
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_0_1);
if (tpdu_nr & 0x80)
tpdu_nr = tpdu_nr & 0x7F;
else
fragment = TRUE;
is_extended = FALSE;
prev_dst_ref = (guint32 *)p_get_proto_data(wmem_file_scope(), pinfo, proto_clnp, 0);
if (!prev_dst_ref) {
prev_dst_ref = wmem_new(wmem_file_scope(), guint32);
*prev_dst_ref = cotp_dst_ref;
p_add_proto_data(wmem_file_scope(), pinfo, proto_clnp, 0, prev_dst_ref);
} else if (cotp_frame_reset) {
cotp_dst_ref = *prev_dst_ref;
}
cotp_frame_reset = FALSE;
cotp_last_fragment = fragment;
dst_ref = cotp_dst_ref;
conv = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport,
0);
if (conv) {
dst_ref += (conv->conv_index << 16);
}
if (!fragment) {
cotp_dst_ref++;
register_frame_end_routine(pinfo, cotp_frame_end);
}
break;
default :
return -1;
}
} else {
switch (li) {
case LI_NORMAL_DT_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_CHECKSUM &&
tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_ATN_EC_16)
return -1;
case LI_NORMAL_DT_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80)
tpdu_nr = tpdu_nr & 0x7F;
else
fragment = TRUE;
is_extended = FALSE;
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
break;
case LI_EXTENDED_DT_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_CHECKSUM &&
tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_ATN_EC_16)
return -1;
case LI_EXTENDED_DT_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80000000)
tpdu_nr = tpdu_nr & 0x7FFFFFFF;
else
fragment = TRUE;
is_extended = TRUE;
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
break;
case LI_ATN_NORMAL_DT_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_ATN_EC_32)
return -1;
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80)
tpdu_nr = tpdu_nr & 0x7F;
else
fragment = TRUE;
is_extended = FALSE;
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
break;
case LI_ATN_EXTENDED_DT_WITH_CHECKSUM:
if (tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_ATN_EC_32)
return -1;
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80000000)
tpdu_nr = tpdu_nr & 0x7FFFFFFF;
else
fragment = TRUE;
is_extended = TRUE;
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
break;
default :
return -1;
}
}
pinfo->clnp_dstref = dst_ref;
pinfo->fragmented = fragment;
if (is_class_234) {
col_append_fstr(pinfo->cinfo, COL_INFO, "DT TPDU (%u) dst-ref: 0x%04x",
tpdu_nr, dst_ref);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "DT TPDU (%u)", tpdu_nr);
}
if (tree) {
ti = proto_tree_add_item(tree, proto_cotp, tvb, offset, li + 1, ENC_NA);
cotp_tree = proto_item_add_subtree(ti, ett_cotp);
proto_tree_add_uint(cotp_tree, hf_cotp_li, tvb, offset, 1,li);
}
offset += 1;
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_type, tvb, offset, 1, tpdu);
}
offset += 1;
li -= 1;
if (is_class_234) {
if (tree)
proto_tree_add_uint(cotp_tree, hf_cotp_destref, tvb, offset, 2, dst_ref);
offset += 2;
li -= 2;
} else if (tree) {
ti = proto_tree_add_uint (cotp_tree, hf_cotp_destref, tvb, offset, 0,
dst_ref);
PROTO_ITEM_SET_GENERATED (ti);
}
if (is_extended) {
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_tpdu_number_extended, tvb, offset,
4, tpdu_nr);
proto_tree_add_item(cotp_tree, hf_cotp_eot_extended, tvb, offset, 4,
ENC_BIG_ENDIAN);
}
offset += 4;
li -= 4;
} else {
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_tpdu_number, tvb, offset, 1,
tpdu_nr);
proto_tree_add_item(cotp_tree, hf_cotp_eot, tvb, offset, 1,
ENC_BIG_ENDIAN);
}
offset += 1;
li -= 1;
}
if (tree)
ositp_decode_var_part(tvb, offset, li, 4, tpdu_len, pinfo, cotp_tree);
offset += li;
next_tvb = tvb_new_subset_remaining(tvb, offset);
fragment_length = tvb_captured_length(next_tvb);
if (fragment) {
col_append_fstr(pinfo->cinfo, COL_INFO, " [COTP fragment, %u byte%s]",
fragment_length, plurality(fragment_length, "", "s"));
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " EOT");
}
if (cotp_reassemble) {
fd_head = fragment_add_seq_next(&cotp_reassembly_table, next_tvb, 0, pinfo,
dst_ref, NULL, fragment_length, fragment);
if (fd_head && fd_head->next) {
proto_tree_add_bytes_format(cotp_tree, hf_cotp_segment_data, tvb, offset, (fragment_length) ? -1 : 0,
NULL, "COTP segment data (%u byte%s)", fragment_length,
plurality(fragment_length, "", "s"));
if (!fragment) {
next_tvb = process_reassembled_data (next_tvb, offset, pinfo,
"Reassembled COTP", fd_head,
&cotp_frag_items, NULL, tree);
} else if (pinfo->num != fd_head->reassembled_in) {
proto_tree_add_uint(cotp_tree, *(cotp_frag_items.hf_reassembled_in),
next_tvb, 0, 0, fd_head->reassembled_in);
}
pinfo->fragmented = fragment;
}
}
if (uses_inactive_subset) {
if (dissector_try_heuristic(cotp_is_heur_subdissector_list, next_tvb,
pinfo, tree, &hdtbl_entry, NULL)) {
*subdissector_found = TRUE;
} else {
call_data_dissector(next_tvb, pinfo, tree);
}
} else {
if ((!cotp_reassemble) || ((cotp_reassemble) && (!fragment))) {
if (dissector_try_heuristic(cotp_heur_subdissector_list, next_tvb, pinfo,
tree, &hdtbl_entry, NULL)) {
*subdissector_found = TRUE;
} else {
call_data_dissector(next_tvb, pinfo, tree);
}
}
}
offset += tvb_captured_length_remaining(tvb, offset);
return offset;
}
static int ositp_decode_ED(tvbuff_t *tvb, int offset, guint8 li, guint8 tpdu,
packet_info *pinfo, proto_tree *tree)
{
proto_tree *cotp_tree = NULL;
proto_item *ti;
gboolean is_extended;
guint16 dst_ref;
guint tpdu_nr;
tvbuff_t *next_tvb;
guint tpdu_len;
tpdu_len = tvb_reported_length_remaining(tvb, offset);
if (!cotp_decode_atn) {
switch (li) {
case LI_NORMAL_DT_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_CHECKSUM)
return -1;
case LI_NORMAL_DT_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80)
tpdu_nr = tpdu_nr & 0x7F;
else
return -1;
is_extended = FALSE;
break;
case LI_EXTENDED_DT_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_CHECKSUM)
return -1;
case LI_EXTENDED_DT_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80000000)
tpdu_nr = tpdu_nr & 0x7FFFFFFF;
else
return -1;
is_extended = TRUE;
break;
default :
return -1;
}
} else {
switch (li) {
case LI_NORMAL_DT_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80)
tpdu_nr = tpdu_nr & 0x7F;
else
return -1;
is_extended = FALSE;
break;
case LI_NORMAL_DT_WITH_CHECKSUM :
if ((tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_CHECKSUM) &&
(tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_ATN_EC_16))
return -1;
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80)
tpdu_nr = tpdu_nr & 0x7F;
else
return -1;
is_extended = FALSE;
break;
case LI_ATN_NORMAL_DT_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_ATN_EC_32)
return -1;
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80)
tpdu_nr = tpdu_nr & 0x7F;
else
return -1;
is_extended = FALSE;
break;
case LI_EXTENDED_DT_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80000000)
tpdu_nr = tpdu_nr & 0x7FFFFFFF;
else
return -1;
is_extended = TRUE;
break;
case LI_EXTENDED_DT_WITH_CHECKSUM :
if ((tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_CHECKSUM) &&
(tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_ATN_EC_16))
return -1;
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80000000)
tpdu_nr = tpdu_nr & 0x7FFFFFFF;
else
return -1;
is_extended = TRUE;
break;
case LI_ATN_EXTENDED_DT_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_ATN_EC_32)
return -1;
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
if (tpdu_nr & 0x80000000)
tpdu_nr = tpdu_nr & 0x7FFFFFFF;
else
return -1;
is_extended = TRUE;
break;
default :
return -1;
}
}
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
pinfo->clnp_dstref = dst_ref;
col_append_fstr(pinfo->cinfo, COL_INFO, "ED TPDU (%u) dst-ref: 0x%04x",
tpdu_nr, dst_ref);
if (tree) {
ti = proto_tree_add_item(tree, proto_cotp, tvb, offset, li + 1, ENC_NA);
cotp_tree = proto_item_add_subtree(ti, ett_cotp);
proto_tree_add_uint(cotp_tree, hf_cotp_li, tvb, offset, 1,li);
}
offset += 1;
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_type, tvb, offset, 1, tpdu);
}
offset += 1;
li -= 1;
if (tree)
proto_tree_add_uint(cotp_tree, hf_cotp_destref, tvb, offset, 2, dst_ref);
offset += 2;
li -= 2;
if (is_extended) {
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_tpdu_number_extended, tvb, offset,
4, tpdu_nr);
}
offset += 4;
li -= 4;
} else {
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_tpdu_number, tvb, offset, 1,
tpdu_nr);
}
offset += 1;
li -= 1;
}
if (tree)
ositp_decode_var_part(tvb, offset, li, 4, tpdu_len, pinfo, cotp_tree);
offset += li;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(next_tvb, pinfo, tree);
offset += tvb_captured_length_remaining(tvb, offset);
return offset;
}
static int ositp_decode_RJ(tvbuff_t *tvb, int offset, guint8 li, guint8 tpdu,
guint8 cdt, packet_info *pinfo, proto_tree *tree)
{
proto_tree *cotp_tree;
proto_item *ti;
proto_item *item = NULL;
guint16 dst_ref;
guint tpdu_nr;
gushort credit = 0;
if (!cotp_decode_atn) {
switch(li) {
case LI_NORMAL_RJ :
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
break;
case LI_EXTENDED_RJ :
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
credit = tvb_get_ntohs(tvb, offset + P_CDT_IN_RJ);
break;
default :
return -1;
}
} else {
switch(li) {
case LI_NORMAL_RJ :
case LI_ATN_NORMAL_RJ :
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
break;
case LI_EXTENDED_RJ :
case LI_ATN_EXTENDED_RJ :
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
credit = tvb_get_ntohs(tvb, offset + P_CDT_IN_RJ);
break;
default :
return -1;
}
}
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
pinfo->clnp_dstref = dst_ref;
col_append_fstr(pinfo->cinfo, COL_INFO, "RJ TPDU (%u) dst-ref: 0x%04x",
tpdu_nr, dst_ref);
if (tree) {
ti = proto_tree_add_item(tree, proto_cotp, tvb, offset, li + 1, ENC_NA);
cotp_tree = proto_item_add_subtree(ti, ett_cotp);
proto_tree_add_uint(cotp_tree, hf_cotp_li, tvb, offset, 1,li);
item = proto_tree_add_uint(cotp_tree, hf_cotp_type, tvb, offset + 1, 1,
tpdu);
if (li == LI_NORMAL_RJ) {
proto_tree_add_uint(cotp_tree, hf_cotp_credit_cdt, tvb, offset + 1, 1, cdt);
}
proto_tree_add_uint(cotp_tree, hf_cotp_destref, tvb, offset + 2, 2,
dst_ref);
if (li == LI_NORMAL_RJ)
proto_tree_add_uint(cotp_tree, hf_cotp_next_tpdu_number, tvb, offset + 4,
1, tpdu_nr);
else {
proto_tree_add_uint(cotp_tree, hf_cotp_next_tpdu_number_extended, tvb,
offset + 4, 4, tpdu_nr);
proto_tree_add_uint(cotp_tree, hf_cotp_credit, tvb, offset + 8, 2, credit);
}
}
offset += li + 1;
expert_add_info_format(pinfo, item, &ei_cotp_reject, "Reject(RJ): -> 0x%x", dst_ref);
return offset;
}
static int ositp_decode_CR_CC(tvbuff_t *tvb, int offset, guint8 li, guint8 tpdu,
packet_info *pinfo, proto_tree *tree,
gboolean uses_inactive_subset,
gboolean *subdissector_found)
{
proto_tree *cotp_tree = NULL;
proto_item *ti;
proto_item *item = NULL;
guint16 dst_ref, src_ref;
guint8 class_option;
tvbuff_t *next_tvb;
guint tpdu_len;
heur_dtbl_entry_t *hdtbl_entry;
static const int * class_options[] = {
&hf_cotp_class,
&hf_cotp_opts_extended_formats,
&hf_cotp_opts_no_explicit_flow_control,
NULL,
};
src_ref = tvb_get_ntohs(tvb, offset + P_SRC_REF);
class_option = tvb_get_guint8(tvb, offset + P_CLASS_OPTION);
if (((class_option & 0xF0) >> 4) > 4)
return -1;
tpdu_len = tvb_reported_length_remaining(tvb, offset);
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
pinfo->clnp_srcref = src_ref;
pinfo->clnp_dstref = dst_ref;
col_append_fstr(pinfo->cinfo, COL_INFO,
"%s TPDU src-ref: 0x%04x dst-ref: 0x%04x",
(tpdu == CR_TPDU) ? "CR" : "CC", src_ref, dst_ref);
ti = proto_tree_add_item(tree, proto_cotp, tvb, offset, li + 1, ENC_NA);
cotp_tree = proto_item_add_subtree(ti, ett_cotp);
proto_tree_add_uint(cotp_tree, hf_cotp_li, tvb, offset, 1,li);
offset += 1;
item = proto_tree_add_uint(cotp_tree, hf_cotp_type, tvb, offset, 1, tpdu);
offset += 1;
li -= 1;
proto_tree_add_uint(cotp_tree, hf_cotp_destref, tvb, offset, 2, dst_ref);
offset += 2;
li -= 2;
proto_tree_add_uint(cotp_tree, hf_cotp_srcref, tvb, offset, 2, src_ref);
offset += 2;
li -= 2;
if (pinfo->destport == 0) {
expert_add_info_format(pinfo, item, &ei_cotp_connection, "Connection %s: 0x%x -> 0x%x", tpdu == CR_TPDU ? "Request(CR)" : "Confirm(CC)", src_ref, dst_ref);
}
proto_tree_add_bitmask_list(cotp_tree, tvb, offset, 1, class_options, ENC_NA);
offset += 1;
li -= 1;
if (li > 0) {
next_tvb = tvb_new_subset_length(tvb, offset, li);
if (dissector_try_heuristic((tpdu == CR_TPDU) ?
cotp_cr_heur_subdissector_list :
cotp_cc_heur_subdissector_list,
next_tvb, pinfo, tree, &hdtbl_entry, NULL)) {
*subdissector_found = TRUE;
} else {
ositp_decode_var_part(tvb, offset, li, class_option, tpdu_len, pinfo,
cotp_tree);
}
offset += li;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!uses_inactive_subset){
if (dissector_try_heuristic(cotp_heur_subdissector_list, next_tvb, pinfo,
tree, &hdtbl_entry, NULL)) {
*subdissector_found = TRUE;
} else {
call_data_dissector(next_tvb, pinfo, tree);
}
}
else
call_data_dissector( next_tvb, pinfo, tree);
offset += tvb_captured_length_remaining(tvb, offset);
return offset;
}
static int ositp_decode_DC(tvbuff_t *tvb, int offset, guint8 li, guint8 tpdu,
packet_info *pinfo, proto_tree *tree)
{
proto_tree *cotp_tree = NULL;
proto_item *ti;
proto_item *item = NULL;
guint16 dst_ref, src_ref;
guint tpdu_len;
if (!cotp_decode_atn) {
if (li > LI_MAX_DC)
return -1;
} else {
if (li > LI_ATN_MAX_DC)
return -1;
}
tpdu_len = li + 1;
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
src_ref = tvb_get_ntohs(tvb, offset + P_SRC_REF);
pinfo->clnp_dstref = dst_ref;
pinfo->clnp_srcref = src_ref;
col_append_fstr(pinfo->cinfo, COL_INFO,
"DC TPDU src-ref: 0x%04x dst-ref: 0x%04x", src_ref, dst_ref);
if (tree) {
ti = proto_tree_add_item(tree, proto_cotp, tvb, offset, li + 1, ENC_NA);
cotp_tree = proto_item_add_subtree(ti, ett_cotp);
proto_tree_add_uint(cotp_tree, hf_cotp_li, tvb, offset, 1,li);
}
offset += 1;
if (tree) {
item = proto_tree_add_uint(cotp_tree, hf_cotp_type, tvb, offset, 1, tpdu);
}
offset += 1;
li -= 1;
if (tree)
proto_tree_add_uint(cotp_tree, hf_cotp_destref, tvb, offset, 2, dst_ref);
offset += 2;
li -= 2;
if (tree)
proto_tree_add_uint(cotp_tree, hf_cotp_srcref, tvb, offset, 2, src_ref);
offset += 2;
li -= 2;
if (tree)
ositp_decode_var_part(tvb, offset, li, 4, tpdu_len, pinfo, cotp_tree);
offset += li;
expert_add_info_format(pinfo, item, &ei_cotp_disconnect_confirm, "Disconnect Confirm(DC): 0x%x -> 0x%x", src_ref, dst_ref);
return offset;
}
static int ositp_decode_AK(tvbuff_t *tvb, int offset, guint8 li, guint8 tpdu,
guint8 cdt, packet_info *pinfo, proto_tree *tree)
{
proto_tree *cotp_tree = NULL;
proto_item *ti;
guint16 dst_ref;
guint tpdu_nr;
gushort cdt_in_ak;
guint tpdu_len;
if (!cotp_decode_atn) {
if (li > LI_MAX_AK)
return -1;
} else {
if (li > LI_ATN_MAX_AK)
return -1;
}
tpdu_len = li + 1;
if (is_LI_NORMAL_AK(li)) {
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
pinfo->clnp_dstref = dst_ref;
col_append_fstr(pinfo->cinfo, COL_INFO, "AK TPDU (%u) dst-ref: 0x%04x",
tpdu_nr, dst_ref);
if (tree) {
ti = proto_tree_add_item(tree, proto_cotp, tvb, offset, li + 1, ENC_NA);
cotp_tree = proto_item_add_subtree(ti, ett_cotp);
proto_tree_add_uint(cotp_tree, hf_cotp_li, tvb, offset, 1,li);
}
offset += 1;
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_type, tvb, offset, 1, tpdu);
proto_tree_add_uint(cotp_tree, hf_cotp_credit_cdt, tvb, offset, 1, cdt);
}
offset += 1;
li -= 1;
if (tree)
proto_tree_add_uint(cotp_tree, hf_cotp_destref, tvb, offset, 2, dst_ref);
offset += 2;
li -= 2;
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_next_tpdu_number, tvb, offset, 1,
tpdu_nr);
}
offset += 1;
li -= 1;
if (tree)
ositp_decode_var_part(tvb, offset, li, 4, tpdu_len, pinfo, cotp_tree);
offset += li;
} else {
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
cdt_in_ak = tvb_get_ntohs(tvb, offset + P_CDT_IN_AK);
pinfo->clnp_dstref = dst_ref;
col_append_fstr(pinfo->cinfo, COL_INFO,
"AK TPDU (%u) dst-ref: 0x%04x Credit: %u",
tpdu_nr, dst_ref, cdt_in_ak);
if (tree) {
ti = proto_tree_add_item(tree, proto_cotp, tvb, offset, li + 1, ENC_NA);
cotp_tree = proto_item_add_subtree(ti, ett_cotp);
proto_tree_add_uint(cotp_tree, hf_cotp_li, tvb, offset, 1,li);
}
offset += 1;
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_type, tvb, offset, 1, tpdu);
}
offset += 1;
li -= 1;
if (tree)
proto_tree_add_uint(cotp_tree, hf_cotp_destref, tvb, offset, 2, dst_ref);
offset += 2;
li -= 2;
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_next_tpdu_number_extended, tvb,
offset, 4, tpdu_nr);
}
offset += 4;
li -= 4;
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_credit, tvb, offset, 2, cdt_in_ak);
}
offset += 2;
li -= 2;
if (tree)
ositp_decode_var_part(tvb, offset, li, 4, tpdu_len, pinfo, cotp_tree);
offset += li;
}
return offset;
}
static int ositp_decode_EA(tvbuff_t *tvb, int offset, guint8 li, guint8 tpdu,
packet_info *pinfo, proto_tree *tree)
{
proto_tree *cotp_tree = NULL;
proto_item *ti;
gboolean is_extended;
guint16 dst_ref;
guint tpdu_nr;
guint tpdu_len;
if (!cotp_decode_atn) {
if (li > LI_MAX_EA)
return -1;
switch (li) {
case LI_NORMAL_EA_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_CHECKSUM ||
tvb_get_guint8(tvb, offset + P_VAR_PART_NDT + 1) != 2)
return -1;
case LI_NORMAL_EA_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
is_extended = FALSE;
break;
case LI_EXTENDED_EA_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_CHECKSUM ||
tvb_get_guint8(tvb, offset + P_VAR_PART_EDT + 1) != 2)
return -1;
case LI_EXTENDED_EA_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
is_extended = TRUE;
break;
default :
return -1;
}
} else {
if (li > LI_ATN_MAX_EA)
return -1;
switch (li) {
case LI_NORMAL_EA_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
is_extended = FALSE;
break;
case LI_NORMAL_EA_WITH_CHECKSUM :
if ((tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_CHECKSUM) &&
(tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_ATN_EC_16))
return -1;
if (tvb_get_guint8(tvb, offset + P_VAR_PART_NDT + 1) != 2)
return -1;
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
is_extended = FALSE;
break;
case LI_ATN_NORMAL_EA_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_NDT) != VP_ATN_EC_32)
return -1;
if (tvb_get_guint8(tvb, offset + P_VAR_PART_NDT + 1) != 4)
return -1;
tpdu_nr = tvb_get_guint8(tvb, offset + P_TPDU_NR_234);
is_extended = FALSE;
break;
case LI_EXTENDED_EA_WITHOUT_CHECKSUM :
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
is_extended = TRUE;
break;
case LI_EXTENDED_EA_WITH_CHECKSUM :
if ((tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_CHECKSUM) &&
(tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_ATN_EC_16))
return -1;
if (tvb_get_guint8(tvb, offset + P_VAR_PART_EDT + 1) != 2)
return -1;
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
is_extended = TRUE;
break;
case LI_ATN_EXTENDED_EA_WITH_CHECKSUM :
if (tvb_get_guint8(tvb, offset + P_VAR_PART_EDT) != VP_ATN_EC_32)
return -1;
if (tvb_get_guint8(tvb, offset + P_VAR_PART_EDT + 1) != 2)
return -1;
tpdu_nr = tvb_get_ntohl(tvb, offset + P_TPDU_NR_234);
is_extended = TRUE;
break;
default :
return -1;
}
}
tpdu_len = li + 1;
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
pinfo->clnp_dstref = dst_ref;
col_append_fstr(pinfo->cinfo, COL_INFO, "EA TPDU (%u) dst-ref: 0x%04x",
tpdu_nr, dst_ref);
if (tree) {
ti = proto_tree_add_item(tree, proto_cotp, tvb, offset, li + 1, ENC_NA);
cotp_tree = proto_item_add_subtree(ti, ett_cotp);
proto_tree_add_uint(cotp_tree, hf_cotp_li, tvb, offset, 1,li);
}
offset += 1;
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_type, tvb, offset, 1, tpdu);
}
offset += 1;
li -= 1;
if (tree)
proto_tree_add_uint(cotp_tree, hf_cotp_destref, tvb, offset, 2, dst_ref);
offset += 2;
li -= 2;
if (is_extended) {
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_next_tpdu_number_extended, tvb,
offset, 4, tpdu_nr);
}
offset += 4;
li -= 4;
} else {
if (tree) {
proto_tree_add_uint(cotp_tree, hf_cotp_next_tpdu_number, tvb, offset, 1,
tpdu_nr);
}
offset += 1;
li -= 1;
}
if (tree)
ositp_decode_var_part(tvb, offset, li, 4, tpdu_len, pinfo, cotp_tree);
offset += li;
return offset;
}
static int ositp_decode_ER(tvbuff_t *tvb, int offset, guint8 li, guint8 tpdu,
packet_info *pinfo, proto_tree *tree)
{
proto_tree *cotp_tree = NULL;
proto_item *ti;
guint16 dst_ref;
guint8 tpdu_len;
if (!cotp_decode_atn) {
if (li > LI_MAX_ER)
return -1;
} else {
if (li > LI_ATN_MAX_ER)
return -1;
}
tpdu_len = li + 1;
if(try_val_to_str(tvb_get_guint8(tvb, offset + P_REJECT_ER), cotp_reject_vals) == NULL)
return -1;
dst_ref = tvb_get_ntohs(tvb, offset + P_DST_REF);
pinfo->clnp_dstref = dst_ref;
col_append_fstr(pinfo->cinfo, COL_INFO, "ER TPDU dst-ref: 0x%04x", dst_ref);
if (tree) {
ti = proto_tree_add_item(tree, proto_cotp, tvb, offset, li + 1, ENC_NA);
cotp_tree = proto_item_add_subtree(ti, ett_cotp);
proto_tree_add_uint(cotp_tree, hf_cotp_li, tvb, offset, 1,li);
proto_tree_add_uint(cotp_tree, hf_cotp_type, tvb, offset + 1, 1, tpdu);
proto_tree_add_uint(cotp_tree, hf_cotp_destref, tvb, offset + 2, 2,
dst_ref);
proto_tree_add_item(cotp_tree, hf_cotp_reject_cause, tvb, offset + 4, 1, ENC_NA);
}
offset += 5;
li -= 4;
if (tree)
ositp_decode_var_part(tvb, offset, li, 4, tpdu_len, pinfo, cotp_tree);
offset += li;
return offset;
}
static int ositp_decode_UD(tvbuff_t *tvb, int offset, guint8 li, guint8 tpdu,
packet_info *pinfo, proto_tree *tree,
gboolean *subdissector_found)
{
proto_item *ti;
proto_tree *cltp_tree = NULL;
tvbuff_t *next_tvb;
guint tpdu_len;
heur_dtbl_entry_t *hdtbl_entry;
tpdu_len = tvb_reported_length_remaining(tvb, offset);
col_append_str(pinfo->cinfo, COL_INFO, "UD TPDU");
if (tree) {
ti = proto_tree_add_item(tree, proto_cltp, tvb, offset, li + 1, ENC_NA);
cltp_tree = proto_item_add_subtree(ti, ett_cltp);
proto_tree_add_uint(cltp_tree, hf_cltp_li, tvb, offset, 1,li);
}
offset += 1;
if (tree) {
proto_tree_add_uint(cltp_tree, hf_cltp_type, tvb, offset, 1, tpdu);
}
offset += 1;
li -= 1;
if (tree)
ositp_decode_var_part(tvb, offset, li, 0, tpdu_len, pinfo, cltp_tree);
offset += li;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (dissector_try_heuristic(cltp_heur_subdissector_list, next_tvb,
pinfo, tree, &hdtbl_entry, NULL)) {
*subdissector_found = TRUE;
} else {
call_data_dissector(next_tvb, pinfo, tree);
}
offset += tvb_captured_length_remaining(tvb, offset);
return offset;
}
static gint dissect_ositp_internal(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree,
gboolean uses_inactive_subset)
{
int offset = 0;
guint8 li, tpdu, cdt;
gboolean first_tpdu = TRUE;
int new_offset;
gboolean found_ositp = FALSE;
gboolean is_cltp = FALSE;
gboolean subdissector_found = FALSE;
col_set_str(pinfo->cinfo, COL_INFO, "");
while (tvb_offset_exists(tvb, offset)) {
if (!first_tpdu) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
expert_add_info(pinfo, NULL, &ei_cotp_multiple_tpdus);
tvb = tvb_new_subset_remaining(tvb, offset);
offset = 0 ;
}
if ((li = tvb_get_guint8(tvb, offset + P_LI)) == 0) {
col_append_str(pinfo->cinfo, COL_INFO, "Length indicator is zero");
if (!first_tpdu)
call_data_dissector( tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
return found_ositp;
}
tpdu = (tvb_get_guint8(tvb, offset + P_TPDU) >> 4) & 0x0F;
if (tpdu == UD_TPDU)
pinfo->current_proto = "CLTP";
cdt = tvb_get_guint8(tvb, offset + P_CDT) & 0x0F;
switch (tpdu) {
case CC_TPDU :
case CR_TPDU :
new_offset = ositp_decode_CR_CC(tvb, offset, li, tpdu, pinfo, tree,
uses_inactive_subset, &subdissector_found);
break;
case DR_TPDU :
new_offset = ositp_decode_DR(tvb, offset, li, tpdu, pinfo, tree);
break;
case DT_TPDU :
new_offset = ositp_decode_DT(tvb, offset, li, tpdu, pinfo, tree,
uses_inactive_subset, &subdissector_found);
break;
case ED_TPDU :
new_offset = ositp_decode_ED(tvb, offset, li, tpdu, pinfo, tree);
break;
case RJ_TPDU :
new_offset = ositp_decode_RJ(tvb, offset, li, tpdu, cdt, pinfo, tree);
break;
case DC_TPDU :
new_offset = ositp_decode_DC(tvb, offset, li, tpdu, pinfo, tree);
break;
case AK_TPDU :
new_offset = ositp_decode_AK(tvb, offset, li, tpdu, cdt, pinfo, tree);
break;
case EA_TPDU :
new_offset = ositp_decode_EA(tvb, offset, li, tpdu, pinfo, tree);
break;
case ER_TPDU :
new_offset = ositp_decode_ER(tvb, offset, li, tpdu, pinfo, tree);
break;
case UD_TPDU :
new_offset = ositp_decode_UD(tvb, offset, li, tpdu, pinfo, tree,
&subdissector_found);
is_cltp = TRUE;
break;
default :
if (first_tpdu)
col_append_fstr(pinfo->cinfo, COL_INFO, "Unknown TPDU type (0x%x)",
tpdu);
new_offset = -1;
break;
}
if (new_offset == -1) {
if (!first_tpdu)
call_data_dissector( tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
break;
}
if (first_tpdu) {
if (!subdissector_found)
col_set_str(pinfo->cinfo, COL_PROTOCOL, is_cltp ? "CLTP" : "COTP");
found_ositp = TRUE;
}
offset = new_offset;
first_tpdu = FALSE;
}
return found_ositp ? offset : 0;
}
static gint dissect_ositp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
return dissect_ositp_internal(tvb, pinfo, tree, FALSE);
}
static gint dissect_ositp_inactive(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data _U_)
{
return dissect_ositp_internal(tvb, pinfo, tree, TRUE);
}
static void
cotp_reassemble_init(void)
{
reassembly_table_init(&cotp_reassembly_table,
&addresses_reassembly_table_functions);
cotp_dst_ref = 0;
}
static void
cotp_reassemble_cleanup(void)
{
reassembly_table_destroy(&cotp_reassembly_table);
}
void proto_register_cotp(void)
{
static hf_register_info hf[] = {
{ &hf_cotp_li,
{ "Length", "cotp.li", FT_UINT8, BASE_DEC,
NULL, 0x0, "Length Indicator, length of this header", HFILL}},
{ &hf_cotp_type,
{ "PDU Type", "cotp.type", FT_UINT8, BASE_HEX,
VALS(cotp_tpdu_type_abbrev_vals), 0x0,
"PDU Type - upper nibble of byte", HFILL}},
{ &hf_cotp_srcref,
{ "Source reference", "cotp.srcref", FT_UINT16, BASE_HEX,
NULL, 0x0, "Source address reference", HFILL}},
{ &hf_cotp_destref,
{ "Destination reference", "cotp.destref", FT_UINT16, BASE_HEX,
NULL, 0x0, "Destination address reference", HFILL}},
{ &hf_cotp_class,
{ "Class", "cotp.class", FT_UINT8, BASE_DEC, NULL,
0xF0, "Transport protocol class", HFILL}},
{ &hf_cotp_opts_extended_formats,
{ "Extended formats", "cotp.opts.extended_formats", FT_BOOLEAN, 8,
NULL, 0x02, "Use of extended formats in classes 2, 3, and 4", HFILL}},
{ &hf_cotp_opts_no_explicit_flow_control,
{ "No explicit flow control", "cotp.opts.no_explicit_flow_control",
FT_BOOLEAN, 8, NULL, 0x01, "No explicit flow control in class 2",
HFILL}},
{ &hf_cotp_tpdu_number,
{ "TPDU number", "cotp.tpdu-number", FT_UINT8, BASE_HEX,
NULL, 0x7f, NULL, HFILL}},
{ &hf_cotp_tpdu_number_extended,
{ "TPDU number", "cotp.tpdu-number", FT_UINT32, BASE_HEX,
NULL, 0x0 , NULL, HFILL}},
{ &hf_cotp_next_tpdu_number,
{ "Your TPDU number", "cotp.next-tpdu-number", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_cotp_next_tpdu_number_extended,
{ "Your TPDU number", "cotp.next-tpdu-number", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_cotp_eot,
{ "Last data unit", "cotp.eot", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x80,
"Is current TPDU the last data unit of a complete DT TPDU sequence "
"(End of TSDU)?", HFILL}},
{ &hf_cotp_eot_extended,
{ "Last data unit", "cotp.eot", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), 0x80000000,
"Is current TPDU the last data unit of a complete DT TPDU sequence "
"(End of TSDU)?", HFILL}},
{ &hf_cotp_segment_overlap,
{ "Segment overlap", "cotp.segment.overlap", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Segment overlaps with other segments", HFILL }},
{ &hf_cotp_segment_overlap_conflict,
{ "Conflicting data in segment overlap", "cotp.segment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping segments contained conflicting data", HFILL }},
{ &hf_cotp_segment_multiple_tails,
{ "Multiple tail segments found", "cotp.segment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when reassembling the packet", HFILL }},
{ &hf_cotp_segment_too_long_segment,
{ "Segment too long", "cotp.segment.toolongsegment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Segment contained data past end of packet", HFILL }},
{ &hf_cotp_segment_error,
{ "Reassembly error", "cotp.segment.error", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "Reassembly error due to illegal segments", HFILL }},
{ &hf_cotp_segment_count,
{ "Segment count", "cotp.segment.count", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_segment,
{ "COTP Segment", "cotp.segment", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_segments,
{ "COTP Segments", "cotp.segments", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_reassembled_in,
{ "Reassembled COTP in frame", "cotp.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This COTP packet is reassembled in this frame", HFILL }},
{ &hf_cotp_reassembled_length,
{ "Reassembled COTP length", "cotp.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{ &hf_cotp_vp_src_tsap,
{ "Source TSAP", "cotp.src-tsap", FT_STRING, BASE_NONE,
NULL, 0x0, "Calling TSAP", HFILL }},
{ &hf_cotp_vp_src_tsap_bytes,
{ "Source TSAP", "cotp.src-tsap-bytes", FT_BYTES, BASE_NONE,
NULL, 0x0, "Calling TSAP (bytes representation)", HFILL }},
{ &hf_cotp_vp_dst_tsap,
{ "Destination TSAP", "cotp.dst-tsap", FT_STRING, BASE_NONE,
NULL, 0x0, "Called TSAP", HFILL }},
{ &hf_cotp_vp_dst_tsap_bytes,
{ "Destination TSAP", "cotp.dst-tsap-bytes", FT_BYTES, BASE_NONE,
NULL, 0x0, "Called TSAP (bytes representation)", HFILL }},
{ &hf_cotp_parameter_code, { "Parameter code", "cotp.parameter_code", FT_UINT8, BASE_HEX, VALS(tp_vpart_type_vals), 0x0, NULL, HFILL }},
{ &hf_cotp_parameter_length, { "Parameter length", "cotp.parameter_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_parameter_value, { "Parameter value", "cotp.parameter_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_atn_extended_checksum16, { "ATN extended checksum", "cotp.atn_extended_checksum", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_atn_extended_checksum32, { "ATN extended checksum", "cotp.atn_extended_checksum", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_ack_time, { "Ack time (ms)", "cotp.ack_time", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_res_error_rate_target_value, { "Residual error rate, target value", "cotp.res_error_rate.target_value", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_res_error_rate_min_accept, { "Residual error rate, minimum acceptable", "cotp.res_error_rate.min_accept", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_res_error_rate_tdsu, { "Residual error rate, TSDU size of interest", "cotp.res_error_rate.tdsu", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_vp_priority, { "Priority", "cotp.vp_priority", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_transit_delay_targ_calling_called, { "Transit delay, target value, calling-called (ms)", "cotp.transit_delay.targ_calling_called", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_transit_delay_max_accept_calling_called, { "Transit delay, maximum acceptable, calling-called (ms)", "cotp.transit_delay.max_accept_calling_called", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_transit_delay_targ_called_calling, { "Transit delay, target value, called-calling (ms)", "cotp.transit_delay.targ_called_calling", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_transit_delay_max_accept_called_calling, { "Transit delay, maximum acceptable, called-calling (ms)", "cotp.transit_delay.max_accept_called_calling", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_max_throughput_targ_calling_called, { "Maximum throughput, target value, calling-called (o/s)", "cotp.max_throughput.targ_calling_called", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_max_throughput_min_accept_calling_called, { "Maximum throughput, minimum acceptable, calling-called (o/s)", "cotp.max_throughput.min_accept_calling_called", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_max_throughput_targ_called_calling, { "Maximum throughput, target value, called-calling (o/s)", "cotp.max_throughput.targ_called_calling", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_max_throughput_min_accept_called_calling, { "Maximum throughput, minimum acceptable, called-calling (o/s)", "cotp.max_throughput.min_accept_called_calling", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_avg_throughput_targ_calling_called, { "Average throughput, target value, calling-called (o/s)", "cotp.avg_throughput.targ_calling_called", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_avg_throughput_min_accept_calling_called, { "Average throughput, minimum acceptable, calling-called (o/s)", "cotp.avg_throughput.min_accept_calling_called", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_avg_throughput_targ_called_calling, { "Average throughput, target value, called-calling (o/s)", "cotp.avg_throughput.targ_called_calling", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_avg_throughput_min_accept_called_calling, { "Average throughput, minimum acceptable, called-calling (o/s)", "cotp.avg_throughput.min_accept_called_calling", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_sequence_number, { "Sequence number", "cotp.sequence_number", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_reassignment_time, { "Reassignment time (secs)", "cotp.reassignment_time", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_lower_window_edge, { "Lower window edge", "cotp.lower_window_edge", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_credit, { "Credit", "cotp.credit", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_tpdu_size, { "TPDU size", "cotp.tpdu_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_checksum, { "Checksum", "cotp.checksum", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_vp_version_nr, { "Version", "cotp.vp_version_nr", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_network_expedited_data, { "Use of network expedited data", "cotp.network_expedited_data", FT_BOOLEAN, 8, TFS(&tfs_used_notused), 0x08, NULL, HFILL }},
{ &hf_cotp_vp_opt_sel_class1_use, { "Use", "cotp.vp_opt_sel_class1_use", FT_BOOLEAN, 8, TFS(&tfs_vp_opt_sel_class1_use), 0x04, NULL, HFILL }},
{ &hf_cotp_use_16_bit_checksum, { "16 bit checksum", "cotp.use_16_bit_checksum", FT_BOOLEAN, 8, TFS(&tfs_used_notused), 0x02, NULL, HFILL }},
{ &hf_cotp_transport_expedited_data_transfer, { "Transport expedited data transfer", "cotp.transport_expedited_data_transfer", FT_BOOLEAN, 8, TFS(&tfs_used_notused), 0x01, NULL, HFILL }},
{ &hf_cotp_preferred_maximum_tpdu_size, { "Preferred maximum TPDU size", "cotp.preferred_maximum_tpdu_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_inactivity_timer, { "Inactivity timer (ms)", "cotp.inactivity_timer", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_cause, { "Cause", "cotp.cause", FT_UINT8, BASE_DEC, VALS(cotp_cause_vals), 0x0, NULL, HFILL }},
{ &hf_cotp_segment_data, { "COTP segment data", "cotp.segment_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_credit_cdt, { "Credit", "cotp.credit", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cotp_reject_cause, { "Reject cause", "cotp.reject_cause", FT_UINT8, BASE_DEC, VALS(cotp_reject_vals), 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_cotp,
&ett_cotp_segment,
&ett_cotp_segments
};
static ei_register_info ei[] = {
{ &ei_cotp_disconnect_request, { "cotp.disconnect_request", PI_SEQUENCE, PI_CHAT, "Disconnect Request(DR): 0x%x -> 0x%x", EXPFILL }},
{ &ei_cotp_reject, { "cotp.reject", PI_SEQUENCE, PI_NOTE, "Reject(RJ): -> 0x%x", EXPFILL }},
{ &ei_cotp_connection, { "cotp.connection", PI_SEQUENCE, PI_CHAT, "Connection %s: 0x%x -> 0x%x", EXPFILL }},
{ &ei_cotp_disconnect_confirm, { "cotp.disconnect_confirm", PI_SEQUENCE, PI_CHAT, "Disconnect Confirm(DC): 0x%x -> 0x%x", EXPFILL }},
{ &ei_cotp_multiple_tpdus, { "cotp.multiple_tpdus", PI_SEQUENCE, PI_NOTE, "Multiple TPDUs in one packet", EXPFILL }},
{ &ei_cotp_preferred_maximum_tpdu_size, { "cotp.preferred_maximum_tpdu_size.invalid", PI_PROTOCOL, PI_WARN, "Preferred maximum TPDU size: bogus length", EXPFILL }},
};
module_t *cotp_module;
expert_module_t* expert_cotp;
proto_cotp = proto_register_protocol(PROTO_STRING_COTP, "COTP", "cotp");
proto_register_field_array(proto_cotp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_cotp = expert_register_protocol(proto_cotp);
expert_register_field_array(expert_cotp, ei, array_length(ei));
cotp_module = prefs_register_protocol(proto_cotp, NULL);
prefs_register_bool_preference(cotp_module, "reassemble",
"Reassemble segmented COTP datagrams",
"Whether segmented COTP datagrams should be "
"reassembled. To use this option, you must "
"also enable \"Allow subdissectors to "
"reassemble TCP streams\" in the TCP "
"protocol settings.",
&cotp_reassemble);
prefs_register_enum_preference(cotp_module, "tsap_display",
"Display TSAPs as strings or bytes",
"How TSAPs should be displayed",
&tsap_display, tsap_display_options, FALSE);
prefs_register_bool_preference(cotp_module, "decode_atn", "Decode ATN TPDUs",
"Whether to decode OSI TPDUs with ATN "
"(Aereonautical Telecommunications Network) "
"extensions. To use this option, you must "
"also enable \"Always try to decode NSDU as "
"transport PDUs\" in the CLNP protocol "
"settings.", &cotp_decode_atn);
cotp_cr_heur_subdissector_list = register_heur_dissector_list("cotp_cr", proto_cotp);
cotp_cc_heur_subdissector_list = register_heur_dissector_list("cotp_cc", proto_cotp);
cotp_is_heur_subdissector_list = register_heur_dissector_list("cotp_is", proto_cotp);
cotp_heur_subdissector_list = register_heur_dissector_list("cotp", proto_cotp);
register_dissector("ositp", dissect_ositp, proto_cotp);
register_dissector("ositp_inactive", dissect_ositp_inactive, proto_cotp);
register_init_routine(cotp_reassemble_init);
register_cleanup_routine(cotp_reassemble_cleanup);
}
void proto_register_cltp(void)
{
static hf_register_info hf[] = {
{ &hf_cltp_li,
{ "Length", "cltp.li", FT_UINT8, BASE_DEC, NULL, 0x0,
"Length Indicator, length of this header", HFILL}},
{ &hf_cltp_type,
{ "PDU Type", "cltp.type", FT_UINT8, BASE_HEX,
VALS(cltp_tpdu_type_abbrev_vals), 0x0, NULL, HFILL}}
};
static gint *ett[] = {
&ett_cltp
};
proto_cltp = proto_register_protocol(PROTO_STRING_CLTP, "CLTP", "cltp");
proto_register_field_array(proto_cltp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
cltp_heur_subdissector_list = register_heur_dissector_list("cltp", proto_cltp);
}
void
proto_reg_handoff_cotp(void)
{
dissector_handle_t ositp_handle;
ositp_handle = find_dissector("ositp");
dissector_add_uint("ip.proto", IP_PROTO_TP, ositp_handle);
rdp_cr_handle = find_dissector("rdp_cr");
rdp_cc_handle = find_dissector("rdp_cc");
proto_clnp = proto_get_id_by_filter_name("clnp");
}
