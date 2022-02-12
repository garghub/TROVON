static int
classify_lg8979_packet(tvbuff_t *tvb)
{
guint8 func, len, data_len, flags;
len = tvb_reported_length(tvb);
if (len == 5) {
return LG8979_DIR_RTU_TO_MASTER;
}
if (len > 5) {
flags = tvb_get_guint8(tvb, 1);
if ( (flags & 0x04) && (flags & 0x08) ){
return LG8979_DIR_RTU_TO_MASTER;
}
else if ( (flags & 0x78) && !(flags & 0x80) ){
return LG8979_DIR_RTU_TO_MASTER;
}
func = tvb_get_guint8(tvb, 3) & 0x7F;
data_len = tvb_get_guint8(tvb, 4);
if (len > (data_len + 5 + 2)) {
return LG8979_DIR_RTU_TO_MASTER;
}
switch (func) {
case LG8979_FC_ANG_CHGRPT:
case LG8979_FC_ADC_FRCRPT:
case LG8979_FC_IND_CHGRPT:
case LG8979_FC_SOE_CHGRPT:
case LG8979_FC_ACC_CHGRPT:
case LG8979_FC_SOELOG_CHGRPT:
case LG8979_FC_REPEAT_MSG:
case LG8979_FC_RTU_CONFIG:
case LG8979_FC_FIRMWARE_CFG:
if (data_len == 0) {
return LG8979_DIR_MASTER_TO_RTU;
}
else {
return LG8979_DIR_RTU_TO_MASTER;
}
break;
case LG8979_FC_ANGGRP_CHGRPT:
case LG8979_FC_ANGGRP_FRCRPT:
if (data_len == 1) {
return LG8979_DIR_MASTER_TO_RTU;
}
else {
return LG8979_DIR_RTU_TO_MASTER;
}
break;
case LG8979_FC_DIG_FRCRPT:
case LG8979_FC_ACC_FRCRPT:
case LG8979_FC_TIME_BIAS:
if (data_len == 2) {
return LG8979_DIR_MASTER_TO_RTU;
}
else {
return LG8979_DIR_RTU_TO_MASTER;
}
break;
case LG8979_FC_ANG_FRCRPT:
case LG8979_FC_IND_FRCRPT:
case LG8979_FC_SOE_FRCRPT:
if (data_len == 4) {
return LG8979_DIR_MASTER_TO_RTU;
}
else {
return LG8979_DIR_RTU_TO_MASTER;
}
break;
case LG8979_FC_ANG_OUTPUT:
case LG8979_FC_SBO_SELECT:
case LG8979_FC_SBO_OPERATE:
case LG8979_FC_DIG_OUTPUT:
case LG8979_FC_ACC_FREEZE:
case LG8979_FC_PUL_OUTPUT:
case LG8979_FC_PULTR_OUTPUT:
case LG8979_FC_SBO_IMEXECUTE:
case LG8979_FC_TIME_SYNC:
case LG8979_FC_ANG_DEADBAND:
case LG8979_FC_ANGGRP_DEFINE:
case LG8979_FC_ACC_PRESET:
case LG8979_FC_CONT_REQUEST:
return LG8979_DIR_MASTER_TO_RTU;
break;
case LG8979_FC_EXP_RPT:
return LG8979_DIR_RTU_TO_MASTER;
break;
default:
return LG8979_DIR_INDETERMINATE;
break;
}
}
return LG8979_DIR_INDETERMINATE;
}
static int
dissect_lg8979(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *lg8979_item, *lg8979_point_item = NULL;
proto_item *lg8979_slot_item = NULL, *lg8979_ang_group_pts_item = NULL;
proto_tree *lg8979_tree, *lg8979_fc_tree = NULL;
proto_tree *lg8979_point_tree = NULL, *lg8979_ts_tree = NULL;
int offset = 0;
guint8 rtu_addr, func, packet_type, data_len, ptnum8, tripclose, rl, exp_code, num_chassis;
guint8 ts_mon, ts_day, ts_hr, ts_min, ts_sec;
guint16 ptnum, ptval, ana12_val;
guint16 ts_ms;
gint num_points = 0, cnt = 0, cnt1 = 0;
gboolean shr, new_status, change;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "L&G 8979");
col_clear(pinfo->cinfo, COL_INFO);
lg8979_item = proto_tree_add_item(tree, proto_lg8979, tvb, 0, -1, ENC_NA);
lg8979_tree = proto_item_add_subtree(lg8979_item, ett_lg8979);
proto_tree_add_item(lg8979_tree, hf_lg8979_header, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
packet_type = classify_lg8979_packet(tvb);
if (packet_type == LG8979_DIR_MASTER_TO_RTU) {
static const int * request_flags[] = {
&hf_lg8979_shr,
&hf_lg8979_mfc,
&hf_lg8979_ack,
NULL
};
col_add_str(pinfo->cinfo, COL_INFO, "Master -> RTU");
shr = tvb_get_guint8(tvb, offset) & 0x80;
proto_tree_add_bitmask(lg8979_tree, tvb, offset, hf_lg8979_flags, ett_lg8979_flags, request_flags, ENC_LITTLE_ENDIAN);
offset += 1;
rtu_addr = tvb_get_guint8(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Address: %d", rtu_addr);
proto_tree_add_item(lg8979_tree, hf_lg8979_address, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (!shr) {
func = tvb_get_guint8(tvb, offset) & 0x7f;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL,
val_to_str_const(func, lg8979_funccode_vals, "Unknown Function Code"));
lg8979_fc_tree = proto_tree_add_subtree_format(
lg8979_tree, tvb, offset, 1, ett_lg8979_funccode, NULL,
"Function Code: %s (%d)",
val_to_str_const(func, lg8979_funccode_vals, "Unknown Function Code"), func);
proto_tree_add_item(lg8979_fc_tree, hf_lg8979_lastblock, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_fc_tree, hf_lg8979_funccode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
data_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lg8979_tree, hf_lg8979_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (func) {
case LG8979_FC_ANG_FRCRPT:
case LG8979_FC_IND_FRCRPT:
case LG8979_FC_SOE_FRCRPT:
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_tree, hf_lg8979_stop_ptnum16, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case LG8979_FC_ANGGRP_CHGRPT:
proto_tree_add_item(lg8979_tree, hf_lg8979_ang_group, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case LG8979_FC_DIG_FRCRPT:
case LG8979_FC_ACC_FRCRPT:
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_tree, hf_lg8979_stop_ptnum8, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case LG8979_FC_ANG_OUTPUT:
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_tree, hf_lg8979_ang_output_val, tvb, offset+1, 2, ENC_LITTLE_ENDIAN);
offset += 3;
break;
case LG8979_FC_SBO_SELECT:
ptnum = tvb_get_guint8(tvb, offset);
tripclose = (tvb_get_guint8(tvb, offset+1) & 0x80) >> 7;
lg8979_point_tree = proto_tree_add_subtree_format(
lg8979_tree, tvb, offset, 2,
ett_lg8979_point, NULL,
"SBO Command, Pt.Num: %u, Code: %s",
ptnum,
val_to_str_const(tripclose, lg8979_sbo_tripclose_vals, "Unknown Control Code"));
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Output: %u, Code: %s",
ptnum, val_to_str_const(tripclose, lg8979_sbo_tripclose_vals, "Unknown Control Code"));
proto_tree_add_item(lg8979_point_tree, hf_lg8979_start_ptnum8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_sbo_tripclose, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_sbo_timercnt, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case LG8979_FC_SBO_OPERATE:
ptnum = tvb_get_guint8(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Output: %u", ptnum);
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case LG8979_FC_DIG_OUTPUT:
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_tree, hf_lg8979_digout_data, tvb, offset+1, 3, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case LG8979_FC_PUL_OUTPUT:
ptnum = tvb_get_guint8(tvb, offset);
rl = (tvb_get_guint8(tvb, offset+1) & 0x80) >> 7;
lg8979_point_tree = proto_tree_add_subtree_format(lg8979_tree, tvb, offset, 2,
ett_lg8979_point, NULL, "Pulse Output, Pt.Num: %u, Code: %s",
ptnum, val_to_str_const(rl, lg8979_pul_output_rl_vals, "Unknown Control Code"));
proto_tree_add_item(lg8979_point_tree, hf_lg8979_start_ptnum8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_pul_output_base, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_pul_output_dur, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_pul_output_rl, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case LG8979_FC_TIME_SYNC:
ts_mon = tvb_get_guint8(tvb, offset);
ts_day = tvb_get_guint8(tvb, offset+1);
ts_hr = tvb_get_guint8(tvb, offset+2);
ts_min = tvb_get_guint8(tvb, offset+3);
ts_sec = tvb_get_guint8(tvb, offset+4);
ts_ms = tvb_get_letohs(tvb, offset+5);
lg8979_ts_tree = proto_tree_add_subtree_format(lg8979_tree, tvb, offset, 7, ett_lg8979_ts, NULL,
"Time-Sync Value: %02d/%02d %02d:%02d:%02d.%03d",
ts_mon, ts_day, ts_hr, ts_min, ts_sec, ts_ms);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_timesync_mon, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_timesync_day, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_timesync_hour, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_timesync_min, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_timesync_sec, tvb, offset+4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_timesync_msec, tvb, offset+5, 2, ENC_LITTLE_ENDIAN);
offset += 7;
break;
case LG8979_FC_TIME_BIAS:
proto_tree_add_item(lg8979_tree, hf_lg8979_timebias_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case LG8979_FC_ANG_DEADBAND:
ptnum = tvb_get_letohs(tvb, offset);
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
num_points = (data_len-2);
for (cnt=0; cnt<num_points; cnt++) {
ptval = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(lg8979_tree, hf_lg8979_ang_deadband, tvb, offset, 1,
ptnum, "Point Number %u: New Deadband: %u", ptnum, ptval);
ptnum += 1;
offset += 1;
}
break;
case LG8979_FC_ANGGRP_DEFINE:
proto_tree_add_item(lg8979_tree, hf_lg8979_ang_group, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum16, tvb, offset+1, 2, ENC_LITTLE_ENDIAN);
offset += 3;
num_points = (data_len-3);
for (cnt=0; cnt<num_points; cnt++) {
lg8979_ang_group_pts_item = proto_tree_add_item(lg8979_tree, hf_lg8979_ang_group_pts, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(lg8979_ang_group_pts_item, " (%d - %d), ", (cnt*8), ((cnt*8)+7));
offset += 1;
}
break;
case LG8979_FC_ACC_PRESET:
num_points = ((data_len)/3);
for (cnt=0; cnt<num_points; cnt++) {
ptnum8 = tvb_get_guint8(tvb, offset);
ptval = tvb_get_letohs(tvb, offset+1);
proto_tree_add_uint_format(lg8979_tree, hf_lg8979_acc_preset, tvb, offset, 3,
ptnum8, "Acc Point Number %u: Preset: %u", ptnum8, ptval);
offset += 3;
}
break;
default:
break;
}
}
proto_tree_add_item(lg8979_tree, hf_lg8979_crc16, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else if (packet_type == LG8979_DIR_RTU_TO_MASTER) {
static const int * response_flags[] = {
&hf_lg8979_shr,
&hf_lg8979_con,
&hf_lg8979_frz,
&hf_lg8979_ind,
&hf_lg8979_sch,
&hf_lg8979_slg,
NULL
};
col_add_str(pinfo->cinfo, COL_INFO, "RTU -> Master");
shr = tvb_get_guint8(tvb, offset) & 0x80;
proto_tree_add_bitmask(lg8979_tree, tvb, offset, hf_lg8979_flags, ett_lg8979_flags, response_flags, ENC_LITTLE_ENDIAN);
offset += 1;
rtu_addr = tvb_get_guint8(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Address: %d", rtu_addr);
proto_tree_add_item(lg8979_tree, hf_lg8979_address, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
while ((!shr) && (tvb_reported_length_remaining(tvb, offset) > 2)){
func = tvb_get_guint8(tvb, offset) & 0x7f;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL,
val_to_str_const(func, lg8979_funccode_vals, "Unknown Function Code"));
lg8979_fc_tree = proto_tree_add_subtree_format(
lg8979_tree, tvb, offset, 1, ett_lg8979_funccode, NULL,
"Function Code: %s (%d)", val_to_str_const(func, lg8979_funccode_vals, "Unknown Function Code"), func);
proto_tree_add_item(lg8979_fc_tree, hf_lg8979_lastblock, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lg8979_fc_tree, hf_lg8979_funccode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
data_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lg8979_tree, hf_lg8979_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (func) {
case LG8979_FC_ANG_CHGRPT:
case LG8979_FC_ANGGRP_CHGRPT:
num_points = (data_len / 3);
for (cnt=0; cnt<num_points; cnt++) {
ptnum = ( tvb_get_guint8(tvb, offset) | ((tvb_get_guint8(tvb, offset+1) & 0x0F) << 8) );
ptval = ( ((tvb_get_guint8(tvb, offset+1) & 0xF0) >> 4) | (tvb_get_guint8(tvb, offset+2) << 4) );
proto_tree_add_uint_format(lg8979_tree, hf_lg8979_ang_point, tvb, offset, 3, ptnum,
"Point Number %u: %u", ptnum, ptval);
offset += 3;
}
break;
case LG8979_FC_ANG_FRCRPT:
ptnum = tvb_get_letohs(tvb, offset);
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (((data_len-2) % 3) == 0) {
num_points = (((data_len-2) / 3) * 2);
}
else {
num_points = ((((data_len-2) / 3) * 2) + 1);
}
for (cnt=0; cnt < num_points; cnt++) {
if (cnt%2 == 0) {
ana12_val = ( tvb_get_guint8(tvb, offset) | ((tvb_get_guint8(tvb, offset+1) & 0x0F) << 8) );
proto_tree_add_uint_format(lg8979_tree, hf_lg8979_ang_point, tvb, offset, 2, ptnum,
"Point Number %u: %u", ptnum, ana12_val);
offset += 1;
if (cnt == (num_points - 1)) {
offset += 1;
}
}
else {
ana12_val = ( ((tvb_get_guint8(tvb, offset) & 0xF0) >> 4) | (tvb_get_guint8(tvb, offset+1) << 4) );
proto_tree_add_uint_format(lg8979_tree, hf_lg8979_ang_point, tvb, offset, 2, ptnum,
"Point Number %u: %u", ptnum, ana12_val);
offset += 2;
}
ptnum += 1;
}
break;
case LG8979_FC_ADC_FRCRPT:
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
ana12_val = ( tvb_get_guint8(tvb, offset) | ((tvb_get_guint8(tvb, offset+1) & 0x0F) << 8) );
proto_tree_add_uint(lg8979_tree, hf_lg8979_adc_ref_zero, tvb, offset, 2, ana12_val);
ana12_val = ( ((tvb_get_guint8(tvb, offset+1) & 0xF0) >> 4) | (tvb_get_guint8(tvb, offset+2) << 4) );
proto_tree_add_uint(lg8979_tree, hf_lg8979_adc_ref_neg90, tvb, offset+1, 2, ana12_val);
offset += 3;
ana12_val = ( tvb_get_guint8(tvb, offset) | ((tvb_get_guint8(tvb, offset+1) & 0x0F) << 8) );
proto_tree_add_uint(lg8979_tree, hf_lg8979_adc_ref_pos90, tvb, offset, 2, ana12_val);
offset += 2;
break;
case LG8979_FC_IND_CHGRPT:
num_points = (data_len / 2);
for (cnt=0; cnt<num_points; cnt++) {
ptnum = tvb_get_letohs(tvb, offset) & 0xFFF;
new_status = (tvb_get_guint8(tvb, offset+1) & 0x80) >> 7;
change = (tvb_get_guint8(tvb, offset+1) & 0x40) >> 6;
lg8979_point_tree = proto_tree_add_subtree_format(lg8979_tree, tvb, offset, 2, ett_lg8979_point, NULL,
"Indication Change Report, Point Number: %u, Status: %u, Change %u", ptnum, new_status, change);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_chgrpt_ptnum, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_chgrpt_status, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_chgrpt_change, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
case LG8979_FC_IND_FRCRPT:
ptnum = tvb_get_letohs(tvb, offset);
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
num_points = ((data_len - 2) / 2);
for (cnt=0; cnt<num_points; cnt++) {
lg8979_point_tree = proto_tree_add_subtree_format(lg8979_tree, tvb, offset, 1,
ett_lg8979_point, NULL, "Indication Status, Base Point Num %d", ptnum);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_status_b0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_status_b1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_status_b2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_status_b3, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_status_b4, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_status_b5, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_status_b6, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_status_b7, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
lg8979_point_tree = proto_tree_add_subtree_format(lg8979_tree, tvb, offset, 1,
ett_lg8979_point, NULL, "Indication Change, Base Point Num %d", ptnum);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_change_b0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_change_b1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_change_b2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_change_b3, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_change_b4, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_change_b5, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_change_b6, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_ind_frcrpt_change_b7, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
ptnum += 8;
}
break;
case LG8979_FC_SOE_CHGRPT:
num_points = (data_len / 2);
for (cnt=0; cnt<num_points; cnt++) {
ptnum = tvb_get_letohs(tvb, offset) & 0xFFF;
new_status = (tvb_get_guint8(tvb, offset+1) & 0x80) >> 7;
change = (tvb_get_guint8(tvb, offset+1) & 0x40) >> 6;
lg8979_point_tree = proto_tree_add_subtree_format(lg8979_tree, tvb, offset, 2, ett_lg8979_point, NULL,
"SOE Change Report, Point Number: %u, Status: %u, Change %u", ptnum, new_status, change);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_chgrpt_ptnum, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_chgrpt_status, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_chgrpt_change, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
case LG8979_FC_SOE_FRCRPT:
ptnum = tvb_get_letohs(tvb, offset);
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
num_points = ((data_len - 2) / 2);
for (cnt=0; cnt<num_points; cnt++) {
lg8979_point_tree = proto_tree_add_subtree_format(lg8979_tree, tvb, offset, 1,
ett_lg8979_point, NULL, "SOE Status, Base Point Num %d", ptnum);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_status_b0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_status_b1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_status_b2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_status_b3, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_status_b4, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_status_b5, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_status_b6, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_status_b7, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
lg8979_point_tree = proto_tree_add_subtree_format(lg8979_tree, tvb, offset, 1,
ett_lg8979_point, NULL, "SOE Change, Base Point Num %d", ptnum);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_change_b0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_change_b1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_change_b2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_change_b3, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_change_b4, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_change_b5, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_change_b6, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_frcrpt_change_b7, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
ptnum += 8;
}
break;
case LG8979_FC_DIG_FRCRPT:
ptnum8 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
num_points = ((data_len-1)/2);
for (cnt=0; cnt<num_points; cnt++) {
lg8979_point_tree = proto_tree_add_subtree_format(lg8979_tree, tvb, offset, 2,
ett_lg8979_point, NULL, "Digital Input Block %d", ptnum8);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b0, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b2, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b4, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b6, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b7, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b8, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b9, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b10, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b11, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b12, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b13, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b14, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_digin_b15, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ptnum8 += 1;
offset += 2;
}
break;
case LG8979_FC_ACC_CHGRPT:
case LG8979_FC_ACC_FRCRPT:
ptnum8 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
num_points = ((data_len-1) / 2);
for (cnt=0; cnt<num_points; cnt++) {
lg8979_point_item = proto_tree_add_item(lg8979_tree, hf_lg8979_acc_point, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_prepend_text(lg8979_point_item, "Point Number %u, ", ptnum8);
offset += 2;
ptnum8 += 1;
}
break;
case LG8979_FC_SOELOG_CHGRPT:
num_points = (data_len / 9);
for (cnt=0; cnt<num_points; cnt++) {
ptnum = tvb_get_letohs(tvb, offset) & 0xFFF;
new_status = (tvb_get_guint8(tvb, offset+1) & 0x80) >> 7;
lg8979_point_tree = proto_tree_add_subtree_format(lg8979_tree, tvb, offset, 9, ett_lg8979_point, NULL,
"SOE Log Change Report, Point Number: %u, New Status: %u", ptnum, new_status);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_logchg_ptnum, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_soe_logchg_newstat, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
ts_mon = tvb_get_guint8(tvb, offset);
ts_day = tvb_get_guint8(tvb, offset+1);
ts_hr = tvb_get_guint8(tvb, offset+2);
ts_min = tvb_get_guint8(tvb, offset+3);
ts_sec = tvb_get_guint8(tvb, offset+4);
ts_ms = tvb_get_letohs(tvb, offset+5);
lg8979_ts_tree = proto_tree_add_subtree_format(lg8979_point_tree, tvb, offset, 7, ett_lg8979_ts, NULL,
"SOE Time Stamp: [%02d/%02d %02d:%02d:%02d.%03d]", ts_mon, ts_day, ts_hr, ts_min, ts_sec, ts_ms);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_soe_logchg_mon, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_soe_logchg_day, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_soe_logchg_hour, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_soe_logchg_min, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_soe_logchg_sec, tvb, offset+4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_ts_tree, hf_lg8979_soe_logchg_msec, tvb, offset+5, 2, ENC_LITTLE_ENDIAN);
offset += 7;
}
break;
case LG8979_FC_SBO_SELECT:
ptnum = tvb_get_guint8(tvb, offset);
tripclose = (tvb_get_guint8(tvb, offset+1) & 0x80) >> 7;
lg8979_point_tree = proto_tree_add_subtree_format(
lg8979_tree, tvb, offset, 2,
ett_lg8979_point, NULL,
"SBO Command, Pt.Num: %u, Code: %s",
ptnum,
val_to_str_const(tripclose, lg8979_sbo_tripclose_vals, "Unknown Control Code"));
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Output: %u, Code: %s",
ptnum, val_to_str_const(tripclose, lg8979_sbo_tripclose_vals, "Unknown Control Code"));
proto_tree_add_item(lg8979_point_tree, hf_lg8979_start_ptnum8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_sbo_tripclose, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_point_tree, hf_lg8979_sbo_timercnt, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case LG8979_FC_SBO_OPERATE:
ptnum = tvb_get_guint8(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Output: %u", ptnum);
proto_tree_add_item(lg8979_tree, hf_lg8979_start_ptnum8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case LG8979_FC_RTU_CONFIG:
num_chassis = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lg8979_tree, hf_lg8979_rtucfg_num_chassis, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
for (cnt=0; cnt<num_chassis; cnt++) {
proto_tree_add_item(lg8979_tree, hf_lg8979_rtucfg_chassis_num, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
for (cnt1=0; cnt1<16; cnt1++) {
lg8979_slot_item = proto_tree_add_item(lg8979_tree, hf_lg8979_rtucfg_card_slot, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_prepend_text(lg8979_slot_item, "Slot %d, ", cnt1);
offset += 1;
}
}
break;
case LG8979_FC_TIME_BIAS:
proto_tree_add_item(lg8979_tree, hf_lg8979_timebias_proctime, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case LG8979_FC_FIRMWARE_CFG:
proto_tree_add_item(lg8979_tree, hf_lg8979_firmware_ver, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case LG8979_FC_EXP_RPT:
exp_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lg8979_tree, hf_lg8979_exprpt_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lg8979_tree, hf_lg8979_exprpt_parm, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
if (exp_code == 14) {
proto_item *lg8979_dfc_item;
lg8979_dfc_item = proto_tree_add_item(lg8979_tree, hf_lg8979_disallowed_func, tvb, offset+1, 1, ENC_NA);
PROTO_ITEM_SET_GENERATED(lg8979_dfc_item);
}
offset += 2;
break;
default:
break;
}
}
if (shr) {
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Short Response");
}
proto_tree_add_item(lg8979_tree, hf_lg8979_crc16, tvb, offset, 2, ENC_BIG_ENDIAN);
}
return tvb_reported_length(tvb);
}
static guint
get_lg8979_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset _U_, void *data _U_)
{
guint len;
len = tvb_reported_length(tvb);
return len;
}
static int
dissect_lg8979_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint length = tvb_reported_length(tvb);
if(length < 2 || tvb_get_guint8(tvb, 0) != 0xFF) {
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, lg8979_desegment, 1,
get_lg8979_len, dissect_lg8979, data);
return length;
}
static int
dissect_lg8979_simple(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint length = tvb_reported_length(tvb);
if(length < 2 || tvb_get_guint8(tvb, 0) != 0xFF) {
return 0;
}
dissect_lg8979(tvb, pinfo, tree, data);
return length;
}
void
proto_register_lg8979(void)
{
static hf_register_info lg8979_hf[] = {
{ &hf_lg8979_header,
{ "Header", "lg8979.header", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_flags,
{ "Flags", "lg8979.flags", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_lg8979_shr,
{ "SHR", "lg8979.shr", FT_UINT8, BASE_DEC, NULL, 0x80, "Short Response Flag", HFILL }},
{ &hf_lg8979_mfc,
{ "MFC", "lg8979.mfc", FT_UINT8, BASE_DEC, NULL, 0x78, "Multi Function Code", HFILL }},
{ &hf_lg8979_ack,
{ "ACK", "lg8979.ack", FT_UINT8, BASE_DEC, NULL, 0x04, "Acknowledge Flag", HFILL }},
{ &hf_lg8979_con,
{ "CON", "lg8979.con", FT_UINT8, BASE_DEC, NULL, 0x40, "Continuation Flag", HFILL }},
{ &hf_lg8979_frz,
{ "FRZ", "lg8979.frz", FT_UINT8, BASE_DEC, NULL, 0x20, "Accumulator Freeze Flag", HFILL }},
{ &hf_lg8979_ind,
{ "IND", "lg8979.ind", FT_UINT8, BASE_DEC, NULL, 0x10, "Indication Change Flag", HFILL }},
{ &hf_lg8979_sch,
{ "SCH", "lg8979.sch", FT_UINT8, BASE_DEC, NULL, 0x08, "SOE Change Flag", HFILL }},
{ &hf_lg8979_slg,
{ "SLG", "lg8979.slg", FT_UINT8, BASE_DEC, NULL, 0x04, "SOE Log Flag", HFILL }},
{ &hf_lg8979_address,
{ "RTU Address", "lg8979.address", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_lastblock,
{ "Last Block Mark", "lg8979.lastblock", FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL }},
{ &hf_lg8979_funccode,
{ "Function Code", "lg8979.funccode", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &lg8979_funccode_vals_ext, 0x7F, NULL, HFILL }},
{ &hf_lg8979_length,
{ "Data Length", "lg8979.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_start_ptnum16,
{ "Start Point Number (16-bit)", "lg8979.start_ptnum16", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_start_ptnum8,
{ "Start Point Number (8-bit)", "lg8979.start_ptnum8", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_stop_ptnum16,
{ "Stop Point Number (16-bit)", "lg8979.stop_ptnum16", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_stop_ptnum8,
{ "Stop Point Number (8-bit)", "lg8979.stop_ptnum8", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_ang_point,
{ "Analog Point", "lg8979.ang_point", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_adc_ref_zero,
{ "ADC Reference (0%)", "lg8979.adc_ref_zero", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_adc_ref_neg90,
{ "ADC Reference (-90%)", "lg8979.adc_ref_neg90", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_adc_ref_pos90,
{ "ADC Reference (+90%)", "lg8979.adc_ref_pos90", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_ind_chgrpt_ptnum,
{ "Point Number (12-bit)", "lg8979.ind_chgrpt_ptnum", FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }},
{ &hf_lg8979_ind_chgrpt_status,
{ "Status Bit", "lg8979.ind_chgrpt_status", FT_UINT16, BASE_DEC, NULL, 0x8000, NULL, HFILL }},
{ &hf_lg8979_ind_chgrpt_change,
{ "Change Bit", "lg8979.ind_chgrpt_change", FT_UINT16, BASE_DEC, NULL, 0x4000, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_status_b0,
{ "Status Bit 0", "lg8979.ind.frcrpt.status_b0", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_status_b1,
{ "Status Bit 1", "lg8979.ind.frcrpt.status_b1", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_status_b2,
{ "Status Bit 2", "lg8979.ind.frcrpt.status_b2", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_status_b3,
{ "Status Bit 3", "lg8979.ind.frcrpt.status_b3", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_status_b4,
{ "Status Bit 4", "lg8979.ind.frcrpt.status_b4", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_status_b5,
{ "Status Bit 5", "lg8979.ind.frcrpt.status_b5", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_status_b6,
{ "Status Bit 6", "lg8979.ind.frcrpt.status_b6", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_status_b7,
{ "Status Bit 7", "lg8979.ind.frcrpt.status_b7", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_change_b0,
{ "Change Bit 0", "lg8979.ind.frcrpt.change_b0", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_change_b1,
{ "Change Bit 1", "lg8979.ind.frcrpt.change_b1", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_change_b2,
{ "Change Bit 2", "lg8979.ind.frcrpt.change_b2", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_change_b3,
{ "Change Bit 3", "lg8979.ind.frcrpt.change_b3", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_change_b4,
{ "Change Bit 4", "lg8979.ind.frcrpt.change_b4", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_change_b5,
{ "Change Bit 5", "lg8979.ind.frcrpt.change_b5", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_change_b6,
{ "Change Bit 6", "lg8979.ind.frcrpt.change_b6", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_lg8979_ind_frcrpt_change_b7,
{ "Change Bit 7", "lg8979.ind.frcrpt.change_b7", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_lg8979_soe_chgrpt_ptnum,
{ "Point Number (12-bit)", "lg8979.soe_chgrpt_ptnum", FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }},
{ &hf_lg8979_soe_chgrpt_status,
{ "Status Bit", "lg8979.soe_chgrpt_status", FT_UINT16, BASE_DEC, NULL, 0x8000, NULL, HFILL }},
{ &hf_lg8979_soe_chgrpt_change,
{ "Change Bit", "lg8979.soe_chgrpt_change", FT_UINT16, BASE_DEC, NULL, 0x4000, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_status_b0,
{ "Status Bit 0", "lg8979.soe.frcrpt.status_b0", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_status_b1,
{ "Status Bit 1", "lg8979.soe.frcrpt.status_b1", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_status_b2,
{ "Status Bit 2", "lg8979.soe.frcrpt.status_b2", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_status_b3,
{ "Status Bit 3", "lg8979.soe.frcrpt.status_b3", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_status_b4,
{ "Status Bit 4", "lg8979.soe.frcrpt.status_b4", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_status_b5,
{ "Status Bit 5", "lg8979.soe.frcrpt.status_b5", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_status_b6,
{ "Status Bit 6", "lg8979.soe.frcrpt.status_b6", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_status_b7,
{ "Status Bit 7", "lg8979.soe.frcrpt.status_b7", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_change_b0,
{ "Change Bit 0", "lg8979.soe.frcrpt.change_b0", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_change_b1,
{ "Change Bit 1", "lg8979.soe.frcrpt.change_b1", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_change_b2,
{ "Change Bit 2", "lg8979.soe.frcrpt.change_b2", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_change_b3,
{ "Change Bit 3", "lg8979.soe.frcrpt.change_b3", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_change_b4,
{ "Change Bit 4", "lg8979.soe.frcrpt.change_b4", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_change_b5,
{ "Change Bit 5", "lg8979.soe.frcrpt.change_b5", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_change_b6,
{ "Change Bit 6", "lg8979.soe.frcrpt.change_b6", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_lg8979_soe_frcrpt_change_b7,
{ "Change Bit 7", "lg8979.soe.frcrpt.change_b7", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_lg8979_digin_b0,
{ "Digital Input Bit 0", "lg8979.digin_b0", FT_BOOLEAN, 16, NULL, 0x0001, NULL, HFILL }},
{ &hf_lg8979_digin_b1,
{ "Digital Input Bit 1", "lg8979.digin_b1", FT_BOOLEAN, 16, NULL, 0x0002, NULL, HFILL }},
{ &hf_lg8979_digin_b2,
{ "Digital Input Bit 2", "lg8979.digin_b2", FT_BOOLEAN, 16, NULL, 0x0004, NULL, HFILL }},
{ &hf_lg8979_digin_b3,
{ "Digital Input Bit 3", "lg8979.digin_b3", FT_BOOLEAN, 16, NULL, 0x0008, NULL, HFILL }},
{ &hf_lg8979_digin_b4,
{ "Digital Input Bit 4", "lg8979.digin_b4", FT_BOOLEAN, 16, NULL, 0x0010, NULL, HFILL }},
{ &hf_lg8979_digin_b5,
{ "Digital Input Bit 5", "lg8979.digin_b5", FT_BOOLEAN, 16, NULL, 0x0020, NULL, HFILL }},
{ &hf_lg8979_digin_b6,
{ "Digital Input Bit 6", "lg8979.digin_b6", FT_BOOLEAN, 16, NULL, 0x0040, NULL, HFILL }},
{ &hf_lg8979_digin_b7,
{ "Digital Input Bit 7", "lg8979.digin_b7", FT_BOOLEAN, 16, NULL, 0x0080, NULL, HFILL }},
{ &hf_lg8979_digin_b8,
{ "Digital Input Bit 8", "lg8979.digin_b8", FT_BOOLEAN, 16, NULL, 0x0100, NULL, HFILL }},
{ &hf_lg8979_digin_b9,
{ "Digital Input Bit 9", "lg8979.digin_b9", FT_BOOLEAN, 16, NULL, 0x0200, NULL, HFILL }},
{ &hf_lg8979_digin_b10,
{ "Digital Input Bit 10", "lg8979.digin_b10", FT_BOOLEAN, 16, NULL, 0x0400, NULL, HFILL }},
{ &hf_lg8979_digin_b11,
{ "Digital Input Bit 11", "lg8979.digin_b11", FT_BOOLEAN, 16, NULL, 0x0800, NULL, HFILL }},
{ &hf_lg8979_digin_b12,
{ "Digital Input Bit 12", "lg8979.digin_b12", FT_BOOLEAN, 16, NULL, 0x1000, NULL, HFILL }},
{ &hf_lg8979_digin_b13,
{ "Digital Input Bit 13", "lg8979.digin_b13", FT_BOOLEAN, 16, NULL, 0x2000, NULL, HFILL }},
{ &hf_lg8979_digin_b14,
{ "Digital Input Bit 14", "lg8979.digin_b14", FT_BOOLEAN, 16, NULL, 0x4000, NULL, HFILL }},
{ &hf_lg8979_digin_b15,
{ "Digital Input Bit 15", "lg8979.digin_b15", FT_BOOLEAN, 16, NULL, 0x8000, NULL, HFILL }},
{ &hf_lg8979_acc_point,
{ "Value", "lg8979.acc_point", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_soe_logchg_ptnum,
{ "Point Number", "lg8979.soe_logchg_ptnum", FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }},
{ &hf_lg8979_soe_logchg_newstat,
{ "New Status", "lg8979.soe_logchg_newstat", FT_UINT16, BASE_DEC, NULL, 0x8000, NULL, HFILL }},
{ &hf_lg8979_soe_logchg_mon,
{ "Month", "lg8979.soe_logchg_mon", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_soe_logchg_day,
{ "Day", "lg8979.soe_logchg_day", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_soe_logchg_hour,
{ "Hours", "lg8979.soe_logchg_hour", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_soe_logchg_min,
{ "Minute", "lg8979.soe_logchg_min", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_soe_logchg_sec,
{ "Second", "lg8979.soe_logchg_sec", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_soe_logchg_msec,
{ "Milli-Second", "lg8979.soe_logchg_msec", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_ang_output_val,
{ "Point Value", "lg8979.ang_output_val", FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }},
{ &hf_lg8979_sbo_tripclose,
{ "Trip/Close Control Code", "lg8979.sbo_tripclose", FT_UINT8, BASE_DEC, VALS(lg8979_sbo_tripclose_vals), 0x80, NULL, HFILL }},
{ &hf_lg8979_sbo_timercnt,
{ "Timer Count", "lg8979.sbo_timercnt", FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL }},
{ &hf_lg8979_digout_data,
{ "Data", "lg8979.digout_data", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_pul_output_base,
{ "Base Time", "lg8979.pul_output_base", FT_UINT8, BASE_HEX, VALS(lg8979_pul_output_base_vals), 0x03, NULL, HFILL }},
{ &hf_lg8979_pul_output_dur,
{ "Duration", "lg8979.pul_output_dur", FT_UINT8, BASE_HEX, NULL, 0x7C, NULL, HFILL }},
{ &hf_lg8979_pul_output_rl,
{ "Raise/Lower", "lg8979.pul_output_rl", FT_UINT8, BASE_HEX, VALS(lg8979_pul_output_rl_vals), 0x80, NULL, HFILL }},
{ &hf_lg8979_ang_deadband,
{ "Deadband", "lg8979.ang_deadband", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_ang_group,
{ "Analog Group", "lg8979.ang_group", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_ang_group_pts,
{ "Analog Group Points Mask", "lg8979.ang_group_pts", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_acc_preset,
{ "Preset Value", "lg8979.acc_preset", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_rtucfg_num_chassis,
{ "Number of I/O Chassis in RTU", "lg8979.rtucfg_num_chassis", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_rtucfg_chassis_num,
{ "Chassis Number", "lg8979.rtucfg_chassis_num", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_rtucfg_card_slot,
{ "Card Code", "lg8979.rtucfg_card_slot", FT_UINT8, BASE_DEC, VALS(lg8979_cardcode_vals), 0x0, NULL, HFILL }},
{ &hf_lg8979_timesync_mon,
{ "Month", "lg8979.timesync_mon", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_timesync_day,
{ "Day", "lg8979.timesync_day", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_timesync_hour,
{ "Hours", "lg8979.timesync_hour", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_timesync_min,
{ "Minute", "lg8979.timesync_min", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_timesync_sec,
{ "Second", "lg8979.timesync_sec", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_timesync_msec,
{ "Milli-Second", "lg8979.timesync_msec", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_timebias_value,
{ "Time Bias Value", "lg8979.timebias_value", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_firmware_ver,
{ "Firmware Version", "lg8979.firmware_ver", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_timebias_proctime,
{ "Time Bias Processing Time (ms)", "lg8979.timebias_proctime", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lg8979_exprpt_code,
{ "Exception Report Code", "lg8979.exprpt_code", FT_UINT8, BASE_DEC, VALS(lg8979_exprpt_code_vals), 0x0, NULL, HFILL }},
{ &hf_lg8979_exprpt_parm,
{ "Value", "lg8979.exprpt_parm", FT_UINT8, BASE_DEC, VALS(lg8979_exprpt_parm_vals), 0x0, NULL, HFILL }},
{ &hf_lg8979_disallowed_func,
{ "Disallowed Function Code", "lg8979.disallowed_func", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &lg8979_funccode_vals_ext, 0x0, NULL, HFILL }},
{ &hf_lg8979_crc16,
{ "CRC-16", "lg8979.crc16", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_lg8979,
&ett_lg8979_flags,
&ett_lg8979_funccode,
&ett_lg8979_point,
&ett_lg8979_ts,
};
module_t *lg8979_module;
proto_lg8979 = proto_register_protocol("Landis & Gyr Telegyr 8979", "L&G 8979", "lg8979");
register_dissector("lg8979", dissect_lg8979_simple, proto_lg8979);
proto_register_field_array(proto_lg8979, lg8979_hf, array_length(lg8979_hf));
proto_register_subtree_array(ett, array_length(ett));
lg8979_module = prefs_register_protocol(proto_lg8979, NULL);
prefs_register_bool_preference(lg8979_module, "desegment",
"Desegment all L&G 8979 Protocol packets spanning multiple TCP segments",
"Whether the L&G 8979 dissector should desegment all messages spanning multiple TCP segments",
&lg8979_desegment);
}
void
proto_reg_handoff_lg8979(void)
{
dissector_handle_t lg8979_handle;
lg8979_handle = create_dissector_handle(dissect_lg8979_tcp, proto_lg8979);
dissector_add_for_decode_as_with_preference("tcp.port", lg8979_handle);
dissector_add_for_decode_as("rtacser.data", lg8979_handle);
}
