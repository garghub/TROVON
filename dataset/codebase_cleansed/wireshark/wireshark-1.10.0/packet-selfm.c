static tvbuff_t *
clean_telnet_iac(packet_info *pinfo, tvbuff_t *tvb, int offset, int len)
{
tvbuff_t *telnet_tvb;
guint8 *buf;
const guint8 *spos;
guint8 *dpos;
int skip, l;
spos=tvb_get_ptr(tvb, offset, len);
buf=(guint8 *)g_malloc(len);
dpos=buf;
skip=0;
l=len;
while(l>0){
if((spos[0]==0xff) && (spos[1]==0xff)){
skip++;
l-=2;
*(dpos++)=0xff;
spos+=2;
continue;
}
*(dpos++)=*(spos++);
l--;
}
telnet_tvb = tvb_new_child_real_data(tvb, buf, len-skip, len-skip);
tvb_set_free_cb(telnet_tvb, g_free);
add_new_data_source(pinfo, telnet_tvb, "Processed Telnet Data");
return telnet_tvb;
}
static fm_config_frame* fmconfig_frame_fast(tvbuff_t *tvb)
{
guint count, offset = 0;
fm_config_frame *frame;
frame = (fm_config_frame *)wmem_alloc(wmem_file_scope(), sizeof(fm_config_frame));
frame->cfg_cmd = tvb_get_ntohs(tvb, offset);
frame->num_flags = tvb_get_guint8(tvb, offset+3);
frame->num_ai = tvb_get_guint8(tvb, offset+6);
frame->num_ai_samples = tvb_get_guint8(tvb, offset+7);
frame->num_dig = tvb_get_guint8(tvb, offset+8);
frame->num_calc = tvb_get_guint8(tvb, offset+9);
offset += 10;
frame->offset_ai = tvb_get_ntohs(tvb, offset);
frame->offset_ts = tvb_get_ntohs(tvb, offset+2);
frame->offset_dig = tvb_get_ntohs(tvb, offset+4);
offset += 6;
frame->analogs = (fm_analog_info *)wmem_alloc(wmem_file_scope(), frame->num_ai * sizeof(fm_analog_info));
for (count = 0; count < frame->num_ai; count++) {
fm_analog_info *analog = &(frame->analogs[count]);
tvb_memcpy(tvb, analog->name, offset, FM_CONFIG_ANA_CHNAME_LEN);
analog->name[FM_CONFIG_ANA_CHNAME_LEN] = '\0';
analog->type = tvb_get_guint8(tvb, offset+6);
analog->sf_type = tvb_get_guint8(tvb, offset+7);
analog->sf_offset = tvb_get_ntohs(tvb, offset+8);
offset += 10;
}
return frame;
}
static int
dissect_relaydef_frame(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *relaydef_item, *relaydef_fm_item, *relaydef_flags_item, *relaydef_proto_item;
proto_tree *relaydef_tree, *relaydef_fm_tree, *relaydef_flags_tree, *relaydef_proto_tree;
guint8 len, num_proto, num_fm, num_flags;
int count;
len = tvb_get_guint8(tvb, offset);
num_proto = tvb_get_guint8(tvb, offset+1);
num_fm = tvb_get_guint8(tvb, offset+2);
num_flags = tvb_get_guint8(tvb, offset+3);
relaydef_item = proto_tree_add_text(tree, tvb, offset, len-2, "Relay Definition Block Details");
relaydef_tree = proto_item_add_subtree(relaydef_item, ett_selfm_relaydef);
proto_tree_add_item(relaydef_tree, hf_selfm_relaydef_len, tvb, offset, 1, ENC_BIG_ENDIAN);
relaydef_proto_item = proto_tree_add_item(relaydef_tree, hf_selfm_relaydef_numproto, tvb, offset+1, 1, ENC_BIG_ENDIAN);
relaydef_proto_tree = proto_item_add_subtree(relaydef_proto_item, ett_selfm_relaydef_proto);
relaydef_fm_item = proto_tree_add_item(relaydef_tree, hf_selfm_relaydef_numfm, tvb, offset+2, 1, ENC_BIG_ENDIAN);
relaydef_fm_tree = proto_item_add_subtree(relaydef_fm_item, ett_selfm_relaydef_fm);
relaydef_flags_item = proto_tree_add_item(relaydef_tree, hf_selfm_relaydef_numflags, tvb, offset+3, 1, ENC_BIG_ENDIAN);
relaydef_flags_tree = proto_item_add_subtree(relaydef_flags_item, ett_selfm_relaydef_flags);
offset += 4;
for (count = 1; count <= num_fm; count++) {
proto_tree_add_item(relaydef_fm_tree, hf_selfm_relaydef_fmcfg_cmd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(relaydef_fm_tree, hf_selfm_relaydef_fmdata_cmd, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
}
for (count = 1; count <= num_flags; count++) {
proto_tree_add_item(relaydef_flags_tree, hf_selfm_relaydef_statbit, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(relaydef_flags_tree, hf_selfm_relaydef_statbit_cmd, tvb, offset+2, 6, ENC_NA);
offset += 8;
}
for (count = 1; count <= num_proto; count++) {
proto_tree_add_item(relaydef_proto_tree, hf_selfm_relaydef_proto, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
return tvb_length(tvb);
}
static int
dissect_fmconfig_frame(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *fmconfig_item, *fmconfig_ai_item=NULL;
proto_tree *fmconfig_tree, *fmconfig_ai_tree=NULL;
guint count;
guint8 len, num_ai;
gchar ai_name[FM_CONFIG_ANA_CHNAME_LEN+1];
len = tvb_get_guint8(tvb, offset);
num_ai = tvb_get_guint8(tvb, offset+4);
fmconfig_item = proto_tree_add_text(tree, tvb, offset, len, "Fast Meter Configuration Details");
fmconfig_tree = proto_item_add_subtree(fmconfig_item, ett_selfm_fmconfig);
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_len, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_numflags, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_loc_sf, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_num_sf, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_num_ai, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_num_samp, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_num_dig, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_num_calc, tvb, offset+7, 1, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_ofs_ai, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_ofs_ts, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_ofs_dig, tvb, offset+4, 2, ENC_BIG_ENDIAN);
offset += 6;
for (count = 0; count < num_ai; count++) {
tvb_memcpy(tvb, &ai_name, offset, 6);
ai_name[FM_CONFIG_ANA_CHNAME_LEN] = '\0';
fmconfig_ai_item = proto_tree_add_text(fmconfig_tree, tvb, offset, 10, "Analog Channel: %s", ai_name);
fmconfig_ai_tree = proto_item_add_subtree(fmconfig_ai_item, ett_selfm_fmconfig_ai);
proto_tree_add_text(fmconfig_ai_tree, tvb, offset, 6, "Analog Channel Name: %s", ai_name);
proto_tree_add_item(fmconfig_ai_tree, hf_selfm_fmconfig_ai_type, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_ai_tree, hf_selfm_fmconfig_ai_sf_type, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_ai_tree, hf_selfm_fmconfig_ai_sf_ofs, tvb, offset+8, 2, ENC_BIG_ENDIAN);
offset += 10;
}
return tvb_length(tvb);
}
static int
dissect_fmdata_frame(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, guint16 config_cmd_match)
{
proto_item *fmdata_item, *fmdata_ai_item=NULL, *fmdata_dig_item=NULL, *fmdata_ai_ch_item=NULL, *fmdata_dig_ch_item=NULL;
proto_tree *fmdata_tree, *fmdata_ai_tree=NULL, *fmdata_dig_tree=NULL, *fmdata_ai_ch_tree=NULL, *fmdata_dig_ch_tree=NULL;
guint8 len, i=0, j=0, ts_mon, ts_day, ts_year, ts_hour, ts_min, ts_sec;
guint16 config_cmd, ts_msec, ai_int16val;
gfloat ai_fpval, ai_sf_fp;
gdouble ai_fpd_val;
gboolean config_found = FALSE;
fm_conversation *conv;
fm_config_frame *cfg_data;
gint cnt = 0, ch_size=0;
len = tvb_get_guint8(tvb, offset);
fmdata_item = proto_tree_add_text(tree, tvb, offset, len-2, "Fast Meter Data Details");
fmdata_tree = proto_item_add_subtree(fmdata_item, ett_selfm_fmdata);
proto_tree_add_item(fmdata_tree, hf_selfm_fmdata_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
{
conv = (fm_conversation *)p_get_proto_data(pinfo->fd, proto_selfm, 0);
if (conv) {
wmem_slist_frame_t *frame = wmem_slist_front(conv->fm_config_frames);
while (frame && !config_found) {
cfg_data = (fm_config_frame *)wmem_slist_frame_data(frame);
config_cmd = cfg_data->cfg_cmd;
if (config_cmd == config_cmd_match) {
proto_item_append_text(fmdata_item, ", using frame number %"G_GUINT32_FORMAT" as Configuration Frame",
cfg_data->fnum);
config_found = TRUE;
}
frame = wmem_slist_frame_next(frame);
}
if (config_found) {
if (cfg_data->num_flags == 1){
proto_tree_add_item(fmdata_tree, hf_selfm_fmdata_flagbyte, tvb, offset, 1, ENC_BIG_ENDIAN);
}
cnt = cfg_data->num_ai;
offset = cfg_data->offset_ai;
if (cnt > 0) {
for (j=0; j < cfg_data->num_ai_samples; j++) {
if (cfg_data->num_ai_samples == 1) {
fmdata_ai_item = proto_tree_add_text(fmdata_tree, tvb, offset, ((cfg_data->offset_ts - cfg_data->offset_ai)/cfg_data->num_ai_samples),
"Analog Channels (%d), Sample: %d (%s)",
cfg_data->num_ai, j+1, val_to_str_const(j+1, selfm_fmconfig_numsamples1_vals, "Unknown"));
fmdata_ai_tree = proto_item_add_subtree(fmdata_ai_item, ett_selfm_fmdata_ai);
}
else if (cfg_data->num_ai_samples == 2) {
fmdata_ai_item = proto_tree_add_text(fmdata_tree, tvb, offset, ((cfg_data->offset_ts - cfg_data->offset_ai)/cfg_data->num_ai_samples),
"Analog Channels (%d), Sample: %d (%s)",
cfg_data->num_ai, j+1, val_to_str_const(j+1, selfm_fmconfig_numsamples2_vals, "Unknown"));
fmdata_ai_tree = proto_item_add_subtree(fmdata_ai_item, ett_selfm_fmdata_ai);
}
else if (cfg_data->num_ai_samples == 4) {
fmdata_ai_item = proto_tree_add_text(fmdata_tree, tvb, offset, ((cfg_data->offset_ts - cfg_data->offset_ai)/cfg_data->num_ai_samples),
"Analog Channels (%d), Sample: %d (%s)",
cfg_data->num_ai, j+1, val_to_str_const(j+1, selfm_fmconfig_numsamples4_vals, "Unknown"));
fmdata_ai_tree = proto_item_add_subtree(fmdata_ai_item, ett_selfm_fmdata_ai);
}
for (i = 0; i < cnt; i++) {
fm_analog_info *ai = &(cfg_data->analogs[i]);
switch (ai->type) {
case FM_CONFIG_ANA_CHTYPE_INT16:
ch_size = FM_CONFIG_ANA_CHTYPE_INT16_LEN;
break;
case FM_CONFIG_ANA_CHTYPE_FP:
ch_size = FM_CONFIG_ANA_CHTYPE_FP_LEN;
break;
case FM_CONFIG_ANA_CHTYPE_FPD:
ch_size = FM_CONFIG_ANA_CHTYPE_FPD_LEN;
break;
default:
break;
}
fmdata_ai_ch_item = proto_tree_add_text(fmdata_ai_tree, tvb, offset, ch_size, "Analog Channel %d: %s", i+1, ai->name);
fmdata_ai_ch_tree = proto_item_add_subtree(fmdata_ai_ch_item, ett_selfm_fmdata_ai_ch);
switch (ai->type) {
case FM_CONFIG_ANA_CHTYPE_INT16:
ai_int16val = tvb_get_ntohs(tvb, offset);
if ((ai->sf_offset != 0) && (ai->sf_type == FM_CONFIG_ANA_SFTYPE_FP)){
ai_sf_fp = tvb_get_ntohieee_float(tvb, ai->sf_offset);
proto_tree_add_float(fmdata_ai_ch_tree, hf_selfm_fmdata_ai_sf_fp, tvb, ai->sf_offset, 4, ai_sf_fp);
}
else {
ai_sf_fp = 1;
}
proto_tree_add_text(fmdata_ai_ch_tree, tvb, offset, ch_size, "Value (Raw): %d", ai_int16val);
proto_tree_add_text(fmdata_ai_ch_tree, tvb, offset, ch_size, "Value (w/ Scale Factor): %f", ((gfloat)ai_int16val*ai_sf_fp));
offset += ch_size;
break;
case FM_CONFIG_ANA_CHTYPE_FP:
ai_fpval = tvb_get_ntohieee_float(tvb, offset);
proto_tree_add_text(fmdata_ai_ch_tree, tvb, offset, ch_size, "Value: %f", ai_fpval);
offset += ch_size;
break;
case FM_CONFIG_ANA_CHTYPE_FPD:
ai_fpd_val = tvb_get_ntohieee_double(tvb, offset);
proto_tree_add_text(fmdata_ai_ch_tree, tvb, offset, ch_size, "Value: %f", ai_fpd_val);
offset += ch_size;
break;
}
}
}
}
if (cfg_data->offset_ts != 0xFFFF) {
ts_mon = tvb_get_guint8(tvb, offset);
ts_day = tvb_get_guint8(tvb, offset+1);
ts_year = tvb_get_guint8(tvb, offset+2);
ts_hour = tvb_get_guint8(tvb, offset+3);
ts_min = tvb_get_guint8(tvb, offset+4);
ts_sec = tvb_get_guint8(tvb, offset+5);
ts_msec = tvb_get_ntohs(tvb, offset+6);
proto_tree_add_text(fmdata_tree, tvb, offset, 8, "Timestamp: %.2d/%.2d/%.2d %.2d:%.2d:%.2d.%.3d", ts_mon, ts_day, ts_year, ts_hour, ts_min, ts_sec, ts_msec);
offset += 8;
}
if (cfg_data->num_dig > 0) {
fmdata_dig_item = proto_tree_add_text(fmdata_tree, tvb, offset, cfg_data->num_dig, "Digital Channels (%d)", cfg_data->num_dig);
fmdata_dig_tree = proto_item_add_subtree(fmdata_dig_item, ett_selfm_fmdata_dig);
for (i=0; i < cfg_data->num_dig; i++) {
fmdata_dig_ch_item = proto_tree_add_text(fmdata_dig_tree, tvb, offset, 1, "Digital Word Bit Row: %d", i+1);
fmdata_dig_ch_tree = proto_item_add_subtree(fmdata_dig_ch_item, ett_selfm_fmdata_dig_ch);
proto_tree_add_item(fmdata_dig_ch_tree, hf_selfm_fmdata_dig_b0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_ch_tree, hf_selfm_fmdata_dig_b1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_ch_tree, hf_selfm_fmdata_dig_b2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_ch_tree, hf_selfm_fmdata_dig_b3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_ch_tree, hf_selfm_fmdata_dig_b4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_ch_tree, hf_selfm_fmdata_dig_b5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_ch_tree, hf_selfm_fmdata_dig_b6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_ch_tree, hf_selfm_fmdata_dig_b7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
}
}
if (!config_found) {
proto_item_append_text(fmdata_item, ", No Fast Meter Configuration frame found");
return 0;
}
}
return tvb_length(tvb);
}
static int
dissect_foconfig_frame(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *foconfig_item, *foconfig_brkr_item, *foconfig_rb_item;
proto_tree *foconfig_tree, *foconfig_brkr_tree=NULL, *foconfig_rb_tree=NULL;
guint count;
guint8 len, num_brkr, prb_supp;
guint16 num_rb;
len = tvb_get_guint8(tvb, offset);
num_brkr = tvb_get_guint8(tvb, offset+1);
num_rb = tvb_get_ntohs(tvb, offset+2);
prb_supp = tvb_get_guint8(tvb, offset+4);
foconfig_item = proto_tree_add_text(tree, tvb, offset, len-2, "Fast Operate Configuration Details");
foconfig_tree = proto_item_add_subtree(foconfig_item, ett_selfm_foconfig);
proto_tree_add_item(foconfig_tree, hf_selfm_foconfig_len, tvb, offset, 1, ENC_BIG_ENDIAN);
foconfig_brkr_item = proto_tree_add_item(foconfig_tree, hf_selfm_foconfig_num_brkr, tvb, offset+1, 1, ENC_BIG_ENDIAN);
foconfig_rb_item = proto_tree_add_item(foconfig_tree, hf_selfm_foconfig_num_rb, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_tree, hf_selfm_foconfig_prb_supp, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_tree, hf_selfm_foconfig_reserved, tvb, offset+5, 1, ENC_BIG_ENDIAN);
offset += 6;
for (count = 1; count <= num_brkr; count++) {
foconfig_brkr_tree = proto_item_add_subtree(foconfig_brkr_item, ett_selfm_foconfig_brkr);
proto_tree_add_item(foconfig_brkr_tree, hf_selfm_foconfig_brkr_open, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_brkr_tree, hf_selfm_foconfig_brkr_close, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
}
for (count = 1; count <= num_rb; count++) {
foconfig_rb_tree = proto_item_add_subtree(foconfig_rb_item, ett_selfm_foconfig_rb);
proto_tree_add_item(foconfig_rb_tree, hf_selfm_foconfig_rb_cmd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_rb_tree, hf_selfm_foconfig_rb_cmd, tvb, offset+1, 1, ENC_BIG_ENDIAN);
if (prb_supp) {
proto_tree_add_item(foconfig_rb_tree, hf_selfm_foconfig_rb_cmd, tvb, offset+2, 1, ENC_BIG_ENDIAN);
offset += 3;
}
else{
offset += 2;
}
}
return tvb_length(tvb);
}
static int
dissect_fastop_frame(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_item *fastop_item;
proto_tree *fastop_tree;
guint8 len, opcode;
guint16 msg_type;
msg_type = tvb_get_ntohs(tvb, offset-2);
len = tvb_get_guint8(tvb, offset);
fastop_item = proto_tree_add_text(tree, tvb, offset, len-2, "Fast Operate Details");
fastop_tree = proto_item_add_subtree(fastop_item, ett_selfm_fastop);
proto_tree_add_item(fastop_tree, hf_selfm_fastop_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
opcode = tvb_get_guint8(tvb, offset);
if (msg_type == CMD_FASTOP_RB_CTRL) {
proto_tree_add_item(fastop_tree, hf_selfm_fastop_rb_code, tvb, offset, 1, ENC_BIG_ENDIAN);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", val_to_str_const(opcode, selfm_fo_rb_vals, "Unknown Control Code"));
}
}
else if (msg_type == CMD_FASTOP_BR_CTRL) {
proto_tree_add_item(fastop_tree, hf_selfm_fastop_br_code, tvb, offset, 1, ENC_BIG_ENDIAN);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", val_to_str_const(opcode, selfm_fo_br_vals, "Unknown Control Code"));
}
}
offset += 1;
proto_tree_add_item(fastop_tree, hf_selfm_fastop_valid, tvb, offset, 1, ENC_BIG_ENDIAN);
return tvb_length(tvb);
}
static int
dissect_fastser_frame(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_item *fastser_item, *fastser_def_fc_item=NULL, *fastser_seq_item=NULL, *fastser_elementlist_item=NULL;
proto_item *fastser_element_item=NULL, *fastser_datareg_item=NULL, *fastser_tag_item=NULL;
proto_tree *fastser_tree, *fastser_def_fc_tree=NULL, *fastser_seq_tree=NULL, *fastser_elementlist_tree=NULL;
proto_tree *fastser_element_tree=NULL, *fastser_datareg_tree=NULL, *fastser_tag_tree=NULL;
gint cnt, num_elements, elmt_status32_ofs=0, elmt_status;
guint8 len, funccode, seq, rx_num_fc, tx_num_fc;
guint8 seq_cnt, seq_fir, seq_fin, elmt_idx, fc_enable;
guint8 *fid_str_ptr, *rid_str_ptr, *region_name_ptr, *tag_name_ptr;
guint16 base_addr, num_addr, num_reg, addr1, addr2;
guint32 tod_ms, elmt_status32, elmt_ts_offset;
len = tvb_get_guint8(tvb, offset);
fastser_item = proto_tree_add_text(tree, tvb, offset, len-2, "Fast SER Message Details");
fastser_tree = proto_item_add_subtree(fastser_item, ett_selfm_fastser);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_len, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_routing_addr, tvb, offset+1, 5, ENC_NA);
offset += 6;
proto_tree_add_item(fastser_tree, hf_selfm_fastser_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
funccode = tvb_get_guint8(tvb, offset);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_funccode, tvb, offset, 1, ENC_BIG_ENDIAN);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", val_to_str_const(funccode, selfm_fastser_func_code_vals, "Unknown Function Code"));
}
offset += 1;
seq = tvb_get_guint8(tvb, offset);
seq_cnt = seq & FAST_SER_SEQ_CNT;
seq_fir = seq & FAST_SER_SEQ_FIR;
seq_fin = seq & FAST_SER_SEQ_FIN;
fastser_seq_item = proto_tree_add_uint_format(fastser_tree, hf_selfm_fastser_seq, tvb, offset, 1, seq, "Sequence Byte: 0x%02x (", seq);
if (seq_fir) proto_item_append_text(fastser_seq_item, "FIR, ");
if (seq_fin) proto_item_append_text(fastser_seq_item, "FIN, ");
proto_item_append_text(fastser_seq_item, "Count %u)", seq_cnt);
fastser_seq_tree = proto_item_add_subtree(fastser_seq_item, ett_selfm_fastser_seq);
proto_tree_add_boolean(fastser_seq_tree, hf_selfm_fastser_seq_fir, tvb, offset, 1, seq);
proto_tree_add_boolean(fastser_seq_tree, hf_selfm_fastser_seq_fin, tvb, offset, 1, seq);
proto_tree_add_item(fastser_seq_tree, hf_selfm_fastser_seq_cnt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(fastser_tree, hf_selfm_fastser_resp_num, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (funccode) {
case FAST_SER_MESSAGE_DEF_ACK:
proto_tree_add_item(fastser_tree, hf_selfm_fastser_def_route_sup, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(fastser_tree, hf_selfm_fastser_def_rx_stat, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_def_tx_stat, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(fastser_tree, hf_selfm_fastser_def_rx_maxfr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_def_tx_maxfr, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
offset += 6;
rx_num_fc = tvb_get_guint8(tvb, offset);
fastser_def_fc_item = proto_tree_add_item(fastser_tree, hf_selfm_fastser_def_rx_num_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
fastser_def_fc_tree = proto_item_add_subtree(fastser_def_fc_item, ett_selfm_fastser_def_fc);
offset += 1;
for (cnt=0; cnt<rx_num_fc; cnt++) {
proto_tree_add_item(fastser_def_fc_tree, hf_selfm_fastser_def_rx_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
}
tx_num_fc = tvb_get_guint8(tvb, offset);
fastser_def_fc_item = proto_tree_add_item(fastser_tree, hf_selfm_fastser_def_tx_num_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
fastser_def_fc_tree = proto_item_add_subtree(fastser_def_fc_item, ett_selfm_fastser_def_fc);
offset += 1;
for (cnt=0; cnt<tx_num_fc; cnt++) {
proto_tree_add_item(fastser_def_fc_tree, hf_selfm_fastser_def_tx_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case FAST_SER_EN_UNS_DATA:
fc_enable = tvb_get_guint8(tvb, offset);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_uns_en_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Function to Enable (%#x)", fc_enable);
}
proto_tree_add_item(fastser_tree, hf_selfm_fastser_uns_en_fc_data, tvb, offset+1, 3, ENC_NA);
offset += 4;
break;
case FAST_SER_DIS_UNS_DATA:
fc_enable = tvb_get_guint8(tvb, offset);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_uns_dis_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Function to Disable (%#x)", fc_enable);
}
proto_tree_add_item(fastser_tree, hf_selfm_fastser_uns_dis_fc_data, tvb, offset+1, 1, ENC_NA);
offset += 2;
break;
case FAST_SER_READ_REQ:
offset += 2;
base_addr = tvb_get_ntohs(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x", base_addr);
}
proto_tree_add_item(fastser_tree, hf_selfm_fastser_read_baseaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_read_numaddr, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
break;
case FAST_SER_READ_RESP:
offset += 2;
base_addr = tvb_get_ntohs(tvb, offset);
num_addr = tvb_get_ntohs(tvb, offset+2);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x", base_addr);
}
proto_tree_add_item(fastser_tree, hf_selfm_fastser_read_baseaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_read_numaddr, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
offset += num_addr*2;
break;
case FAST_SER_UNS_RESP:
proto_tree_add_item(fastser_tree, hf_selfm_fastser_unsresp_orig, tvb, offset, 4, ENC_NA);
offset += 4;
tod_ms = tvb_get_ntohl(tvb, offset+4);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_unsresp_doy, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_unsresp_year, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_unsresp_todms, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_text(fastser_tree, tvb, offset+4, 4, "Time of Day (decoded): %s", time_msecs_to_str(tod_ms));
offset += 8;
num_elements = (len-34) / 4;
fastser_elementlist_item = proto_tree_add_uint(fastser_tree, hf_selfm_fastser_unsresp_num_elmt, tvb, offset, (4*num_elements), num_elements);
fastser_elementlist_tree = proto_item_add_subtree(fastser_elementlist_item, ett_selfm_fastser_element_list);
for (cnt = offset; cnt < len; cnt++) {
if (tvb_memeql(tvb, cnt, "\xFF\xFF\xFF\xFE", 4) == 0) {
elmt_status32_ofs = cnt+4;
}
}
elmt_status32 = tvb_get_ntohl(tvb, elmt_status32_ofs );
for (cnt=0; cnt<num_elements; cnt++) {
elmt_idx = tvb_get_guint8(tvb, offset);
elmt_ts_offset = (guint32)((tvb_get_guint8(tvb, offset+1) << 16) | (tvb_get_guint8(tvb, offset+2) << 8) | (tvb_get_guint8(tvb, offset+3)));
elmt_status = ((elmt_status32 >> cnt) & 0x01);
fastser_element_item = proto_tree_add_text(fastser_elementlist_tree, tvb, offset, 4,
"Reported Event %d (Index: %d, New State: %s)", cnt+1, elmt_idx, val_to_str_const(elmt_status, selfm_ser_status_vals, "Unknown"));
fastser_element_tree = proto_item_add_subtree(fastser_element_item, ett_selfm_fastser_element);
proto_tree_add_item(fastser_element_tree, hf_selfm_fastser_unsresp_elmt_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_element_tree, hf_selfm_fastser_unsresp_elmt_ts_ofs, tvb, offset+1, 3, ENC_NA);
proto_tree_add_text(fastser_element_tree, tvb, offset+1, 3,
"SER Element Timestamp Offset (decoded): %s", time_msecs_to_str(tod_ms + (elmt_ts_offset/1000)));
proto_tree_add_uint(fastser_element_tree, hf_selfm_fastser_unsresp_elmt_status, tvb, elmt_status32_ofs, 4, elmt_status);
offset += 4;
}
proto_tree_add_item(fastser_tree, hf_selfm_fastser_unsresp_eor, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(fastser_tree, hf_selfm_fastser_unsresp_elmt_statword, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case FAST_SER_UNS_WRITE:
addr1 = tvb_get_ntohs(tvb, offset);
addr2 = tvb_get_ntohs(tvb, offset+2);
num_reg = tvb_get_ntohs(tvb, offset+4);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x, %#x", addr1, addr2);
}
proto_tree_add_item(fastser_tree, hf_selfm_fastser_unswrite_addr1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_unswrite_addr2, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_unswrite_num_reg, tvb, offset+4, 2, ENC_BIG_ENDIAN);
offset += 6;
for (cnt=0; cnt < num_reg; cnt++) {
proto_tree_add_item(fastser_tree, hf_selfm_fastser_unswrite_reg_val, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case FAST_SER_DEVDESC_RESP:
fid_str_ptr = tvb_get_ephemeral_string(tvb, offset, 50);
rid_str_ptr = tvb_get_ephemeral_string(tvb, offset+50, 40);
proto_tree_add_text(fastser_tree, tvb, offset, 50, "FID: %s", fid_str_ptr);
proto_tree_add_text(fastser_tree, tvb, offset+50, 40, "RID: %s", rid_str_ptr);
offset += 90;
num_reg = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_devdesc_num_reg, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += 2;
for (cnt=0; cnt<num_reg; cnt++) {
fastser_datareg_item = proto_tree_add_text(fastser_tree, tvb, offset, 18, "Fast SER Data Region #%d", cnt+1);
fastser_datareg_tree = proto_item_add_subtree(fastser_datareg_item, ett_selfm_fastser_datareg);
region_name_ptr = tvb_get_ephemeral_string(tvb, offset, 12);
proto_tree_add_text(fastser_datareg_tree, tvb, offset, 12, "Data Region Name: %s", region_name_ptr);
offset += 12;
proto_tree_add_item(fastser_datareg_tree, hf_selfm_fastser_read_baseaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(fastser_datareg_tree, hf_selfm_fastser_read_numaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += 2;
}
break;
case FAST_SER_DATAFMT_REQ:
offset += 2;
base_addr = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_read_baseaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x", base_addr);
}
break;
case FAST_SER_DATAFMT_RESP:
offset += 2;
base_addr = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_read_baseaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x", base_addr);
}
proto_tree_add_item(fastser_tree, hf_selfm_fastser_datafmt_resp_num_tag, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while ((tvb_reported_length_remaining(tvb, offset)) > 2) {
tag_name_ptr = tvb_get_ephemeral_string(tvb, offset, 11);
fastser_tag_item = proto_tree_add_text(fastser_tree, tvb, offset, 14, "Tag Name: %s", tag_name_ptr);
fastser_tag_tree = proto_item_add_subtree(fastser_tag_item, ett_selfm_fastser_tag);
proto_tree_add_item(fastser_tag_tree, hf_selfm_fastser_datafmt_resp_tag_qty, tvb, offset+11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastser_tag_tree, hf_selfm_fastser_datafmt_resp_tag_type, tvb, offset+13, 1, ENC_BIG_ENDIAN);
offset += 14;
}
break;
case FAST_SER_BITLABEL_REQ:
offset += 2;
base_addr = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(fastser_tree, hf_selfm_fastser_read_baseaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x", base_addr);
}
break;
case FAST_SER_BITLABEL_RESP:
proto_tree_add_text(fastser_tree, tvb, offset, (tvb_reported_length_remaining(tvb, offset)-2), "Bit Label Data %s",
tvb_format_text(tvb, offset, (tvb_reported_length_remaining(tvb, offset)-2)));
offset += (tvb_reported_length_remaining(tvb, offset)-2);
default:
break;
}
proto_tree_add_item(fastser_tree, hf_selfm_fastser_crc16, tvb, offset, 2, ENC_BIG_ENDIAN);
return tvb_length(tvb);
}
static void
dissect_selfm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *selfm_item=NULL;
proto_tree *selfm_tree=NULL;
int offset=0;
guint16 msg_type, len;
tvbuff_t *selfm_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SEL Fast Msg");
col_clear(pinfo->cinfo, COL_INFO);
len = tvb_length(tvb);
if ((pinfo->srcport) && selfm_telnet_clean) {
selfm_tvb=clean_telnet_iac(pinfo, tvb, offset, len);
}
else {
selfm_tvb = tvb_new_subset( tvb, offset, len, len);
}
msg_type = tvb_get_ntohs(selfm_tvb, offset);
if (!pinfo->fd->flags.visited) {
conversation_t *conversation;
fm_conversation *conv_data;
conversation = find_or_create_conversation(pinfo);
conv_data = (fm_conversation *)conversation_get_proto_data(conversation, proto_selfm);
if (conv_data == NULL) {
conv_data = (fm_conversation *)wmem_alloc(wmem_file_scope(), sizeof(fm_conversation));
conv_data->fm_config_frames = wmem_slist_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_selfm, (void *)conv_data);
}
p_add_proto_data(pinfo->fd, proto_selfm, 0, conv_data);
if ((CMD_FM_CONFIG == msg_type) || (CMD_DFM_CONFIG == msg_type) || (CMD_PDFM_CONFIG == msg_type)) {
fm_config_frame *frame_ptr = fmconfig_frame_fast(selfm_tvb);
frame_ptr->fnum = pinfo->fd->num;
wmem_slist_prepend(conv_data->fm_config_frames, frame_ptr);
}
}
if (tree) {
selfm_item = proto_tree_add_protocol_format(tree, proto_selfm, selfm_tvb, 0, len, "SEL Fast Message");
selfm_tree = proto_item_add_subtree(selfm_item, ett_selfm);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_clear(pinfo->cinfo, COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_const(msg_type, selfm_msgtype_vals, "Unknown Message Type"));
}
proto_tree_add_item(selfm_tree, hf_selfm_msgtype, selfm_tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (tvb_reported_length_remaining(selfm_tvb, offset) > 0) {
switch (msg_type) {
case CMD_RELAY_DEF:
dissect_relaydef_frame(selfm_tvb, selfm_tree, offset);
break;
case CMD_FM_CONFIG:
case CMD_DFM_CONFIG:
case CMD_PDFM_CONFIG:
dissect_fmconfig_frame(selfm_tvb, selfm_tree, offset);
break;
case CMD_FM_DATA:
dissect_fmdata_frame(selfm_tvb, selfm_tree, pinfo, offset, CMD_FM_CONFIG);
break;
case CMD_DFM_DATA:
dissect_fmdata_frame(selfm_tvb, selfm_tree, pinfo, offset, CMD_DFM_CONFIG);
break;
case CMD_PDFM_DATA:
dissect_fmdata_frame(selfm_tvb, selfm_tree, pinfo, offset, CMD_PDFM_CONFIG);
break;
case CMD_FASTOP_CONFIG:
dissect_foconfig_frame(selfm_tvb, selfm_tree, offset);
break;
case CMD_FAST_SER:
dissect_fastser_frame(selfm_tvb, selfm_tree, pinfo, offset);
break;
case CMD_FASTOP_RB_CTRL:
case CMD_FASTOP_BR_CTRL:
dissect_fastop_frame(selfm_tvb, selfm_tree, pinfo, offset);
break;
default:
break;
}
}
}
}
static guint
get_selfm_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset _U_)
{
guint message_len=0;
guint16 msg_type;
if (tvb_length(tvb) > 2) {
msg_type = tvb_get_ntohs(tvb, 0);
switch (msg_type) {
case CMD_FM_CONFIG:
if (tvb_length(tvb) > 10) {
if (tvb_get_guint8(tvb, 5) != 0) {
message_len = ((tvb_get_guint8(tvb, 6) * 10) + (tvb_get_guint8(tvb, 9) * 20) + 18);
}
else {
message_len = ((tvb_get_guint8(tvb, 6) * 11) + (tvb_get_guint8(tvb, 9) * 20) + 18);
}
}
else {
message_len = tvb_get_guint8(tvb, 2);
}
if (message_len < tvb_length(tvb)) {
message_len = tvb_length(tvb);
}
break;
case CMD_DFM_CONFIG:
case CMD_PDFM_CONFIG:
if (tvb_length(tvb) > 7) {
message_len = ((tvb_get_guint8(tvb, 6) * 11) + 20);
}
else {
message_len = tvb_get_guint8(tvb, 2);
}
if (message_len < tvb_length(tvb)) {
message_len = tvb_length(tvb);
}
break;
case CMD_RELAY_DEF:
case CMD_FM_DATA:
case CMD_DFM_DATA:
case CMD_PDFM_DATA:
case CMD_FAST_SER:
message_len = tvb_get_guint8(tvb, 2);
if (message_len < tvb_length(tvb)) {
message_len = tvb_length(tvb);
}
break;
default:
if (tvb_get_guint8(tvb, 2) > tvb_length(tvb)) {
message_len = tvb_get_guint8(tvb, 2);
}
else {
message_len = tvb_length(tvb);
}
break;
}
}
else if (tvb_length(tvb) == 2) {
message_len = 2;
}
return message_len;
}
static gboolean
dissect_selfm_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint length = tvb_length(tvb);
if(length < 2 || tvb_get_guint8(tvb, 0) != 0xA5) {
return FALSE;
}
tcp_dissect_pdus(tvb, pinfo, tree, selfm_desegment, 2,
get_selfm_len, dissect_selfm);
return TRUE;
}
static gboolean
dissect_selfm_simple(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint length = tvb_length(tvb);
if(length < 2 || tvb_get_guint8(tvb, 0) != 0xA5) {
return FALSE;
}
dissect_selfm(tvb, pinfo, tree);
return TRUE;
}
void
proto_register_selfm(void)
{
static hf_register_info selfm_hf[] = {
{ &hf_selfm_msgtype,
{ "Message Type", "selfm.msgtype", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &selfm_msgtype_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_relaydef_len,
{ "Length", "selfm.relaydef.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_relaydef_numproto,
{ "Number of Protocols", "selfm.relaydef.numproto", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_relaydef_numfm,
{ "Number of Fast Meter Messages", "selfm.relaydef.numfm", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_relaydef_numflags,
{ "Number of Status Flags", "selfm.relaydef.numflags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_relaydef_fmcfg_cmd,
{ "Fast Meter Config Command", "selfm.relaydef.fmcfg_cmd", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_relaydef_fmdata_cmd,
{ "Fast Meter Data Command", "selfm.relaydef.fmdata_cmd", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_relaydef_statbit,
{ "Status Flag Bit", "selfm.relaydef.status_bit", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_relaydef_statbit_cmd,
{ "Status Flag Bit Response Command", "selfm.relaydef.status_bit_cmd", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_relaydef_proto,
{ "Supported Protocol", "selfm.relaydef.proto", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &selfm_relaydef_proto_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_len,
{ "Length", "selfm.fmconfig.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_numflags,
{ "Number of Status Flags", "selfm.fmconfig.numflags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_loc_sf,
{ "Location of Scale Factor", "selfm.fmconfig.loc_sf", FT_UINT8, BASE_DEC, VALS(selfm_fmconfig_sfloc_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_num_sf,
{ "Number of Scale Factors", "selfm.fmconfig.num_sf", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_num_ai,
{ "Number of Analog Input Channels", "selfm.fmconfig.num_ai", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_num_samp,
{ "Number of Samples per AI Channel", "selfm.fmconfig.num_samp", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_num_dig,
{ "Number of Digital Banks", "selfm.fmconfig.num_dig", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_num_calc,
{ "Number of Calculation Blocks", "selfm.fmconfig.num_calc", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_ofs_ai,
{ "First Analog Channel Offset", "selfm.fmconfig.ofs_ai", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_ofs_ts,
{ "Timestamp Offset", "selfm.fmconfig.ofs_ts", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_ofs_dig,
{ "First Digital Bank Offset", "selfm.fmconfig.ofs_dig", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_ai_type,
{ "Analog Channel Type", "selfm.fmconfig.ai_type", FT_UINT8, BASE_DEC, VALS(selfm_fmconfig_ai_chtype_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_ai_sf_type,
{ "Analog Channel Scale Factor Type", "selfm.fmconfig.ai_sf_type", FT_UINT8, BASE_DEC, VALS(selfm_fmconfig_ai_sftype_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_ai_sf_ofs,
{ "Analog Channel Scale Factor Offset", "selfm.fmconfig.ai_sf_ofs", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_len,
{ "Length", "selfm.fmdata.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_flagbyte,
{ "Status Flags Byte", "selfm.fmdata.flagbyte", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_ai_sf_fp,
{ "Using IEEE FP Format Scale Factor", "selfm.fmdata.ai.sf_fp",FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_dig_b0,
{ "Bit 0", "selfm.fmdata.dig_b0", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_selfm_fmdata_dig_b1,
{ "Bit 1", "selfm.fmdata.dig_b1", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_selfm_fmdata_dig_b2,
{ "Bit 2", "selfm.fmdata.dig_b2", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_selfm_fmdata_dig_b3,
{ "Bit 3", "selfm.fmdata.dig_b3", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_selfm_fmdata_dig_b4,
{ "Bit 4", "selfm.fmdata.dig_b4", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_selfm_fmdata_dig_b5,
{ "Bit 5", "selfm.fmdata.dig_b5", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_selfm_fmdata_dig_b6,
{ "Bit 6", "selfm.fmdata.dig_b6", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_selfm_fmdata_dig_b7,
{ "Bit 7", "selfm.fmdata.dig_b7", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_selfm_foconfig_len,
{ "Length", "selfm.foconfig.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_foconfig_num_brkr,
{ "Number of Breaker Bits", "selfm.foconfig.num_brkr", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_foconfig_num_rb,
{ "Number of Remote Bits", "selfm.foconfig.num_rb", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_foconfig_prb_supp,
{ "Remote Bit Pulse Supported", "selfm.foconfig.prb_supp", FT_UINT8, BASE_DEC, VALS(selfm_foconfig_prb_supp_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_foconfig_reserved,
{ "Reserved Bit (Future)", "selfm.foconfig.reserved", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_foconfig_brkr_open,
{ "Breaker Bit Open Command", "selfm.foconfig.brkr_open", FT_UINT8, BASE_HEX, VALS(selfm_fo_br_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_foconfig_brkr_close,
{ "Breaker Bit Close Command", "selfm.foconfig.brkr_close", FT_UINT8, BASE_HEX, VALS(selfm_fo_br_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_foconfig_rb_cmd,
{ "Remote Bit Command", "selfm.foconfig.rb_cmd", FT_UINT8, BASE_HEX, VALS(selfm_fo_rb_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastop_len,
{ "Length", "selfm.fastop.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastop_rb_code,
{ "Remote Bit Operate Code", "selfm.fastop.rb_code", FT_UINT8, BASE_HEX, VALS(selfm_fo_rb_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastop_br_code,
{ "Breaker Bit Operate Code", "selfm.fastop.br_code", FT_UINT8, BASE_HEX, VALS(selfm_fo_br_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastop_valid,
{ "Operate Code Validation", "selfm.fastop.valid", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_len,
{ "Length", "selfm.fastser.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_routing_addr,
{ "Routing Address (future)", "selfm.fastser.routing_addr", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_status,
{ "Status Byte", "selfm.fastser.status", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_funccode,
{ "Function Code", "selfm.fastser.funccode", FT_UINT8, BASE_HEX, VALS(selfm_fastser_func_code_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_seq,
{ "Sequence Byte", "selfm.fastser.seq", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_seq_fir,
{ "FIR", "selfm.fastser.seq_fir", FT_BOOLEAN, 8, NULL, FAST_SER_SEQ_FIR, NULL, HFILL }},
{ &hf_selfm_fastser_seq_fin,
{ "FIN", "selfm.fastser.seq_fin", FT_BOOLEAN, 8, NULL, FAST_SER_SEQ_FIN, NULL, HFILL }},
{ &hf_selfm_fastser_seq_cnt,
{ "Count", "selfm.fastser.seq_cnt", FT_UINT8, BASE_DEC, NULL, FAST_SER_SEQ_CNT, "Frame Count Number", HFILL }},
{ &hf_selfm_fastser_resp_num,
{ "Response Number", "selfm.fastser.resp_num", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_crc16,
{ "CRC-16", "selfm.fastser.crc16", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_def_route_sup,
{ "Routing Support", "selfm.fastser.def_route_sup", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_def_rx_stat,
{ "Status RX", "selfm.fastser.def_rx_stat", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_def_tx_stat,
{ "Status TX", "selfm.fastser.def_tx_stat", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_def_rx_maxfr,
{ "Max Frames RX", "selfm.fastser.def_rx_maxfr", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_def_tx_maxfr,
{ "Max Frames TX", "selfm.fastser.def_tx_maxfr", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_def_rx_num_fc,
{ "Number of Supported RX Function Codes", "selfm.fastser.def_rx_num_fc", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_def_rx_fc,
{ "Receive Function Code", "selfm.fastser.def_rx_fc", FT_UINT8, BASE_HEX, VALS(selfm_fastser_func_code_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_def_tx_num_fc,
{ "Number of Supported TX Function Codes", "selfm.fastser.def_tx_num_fc", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_def_tx_fc,
{ "Transmit Function Code", "selfm.fastser.def_tx_fc", FT_UINT8, BASE_HEX, VALS(selfm_fastser_func_code_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_uns_en_fc,
{ "Function Code to Enable", "selfm.fastser.uns_en_fc", FT_UINT8, BASE_HEX, VALS(selfm_fastser_func_code_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_uns_en_fc_data,
{ "Function Code Data", "selfm.fastser.uns_en_fc_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_uns_dis_fc,
{ "Function Code to Disable", "selfm.fastser.uns_dis_fc", FT_UINT8, BASE_HEX, VALS(selfm_fastser_func_code_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_uns_dis_fc_data,
{ "Function Code Data", "selfm.fastser.uns_dis_fc_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unsresp_orig,
{ "Origination path", "selfm.fastser.unsresp_orig", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unsresp_doy,
{ "Day of Year", "selfm.fastser.unsresp_doy", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unsresp_year,
{ "Year", "selfm.fastser.unsresp_year", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unsresp_todms,
{ "Time of Day (in ms)", "selfm.fastser.unsresp_todms", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unsresp_num_elmt,
{ "Number of SER Elements", "selfm.fastser.unsresp_num_elmt", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unsresp_elmt_idx,
{ "SER Element Index", "selfm.fastser.unsresp_elmt_idx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unsresp_elmt_ts_ofs,
{ "SER Element Timestamp Offset (us)", "selfm.fastser.unsresp_elmt_ts_ofs", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unsresp_elmt_status,
{ "SER Element Status", "selfm.fastser.unsresp_elmt_status", FT_UINT8, BASE_DEC, VALS(selfm_ser_status_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unsresp_eor,
{ "End of Record Indicator", "selfm.fastser.unsresp_eor", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unsresp_elmt_statword,
{ "SER Element Status Word", "selfm.fastser.unsresp_elmt_statword", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unswrite_addr1,
{ "Write Address Region #1", "selfm.fastser.unswrite_addr1", FT_UINT16, BASE_HEX, VALS(selfm_fastser_unswrite_com_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unswrite_addr2,
{ "Write Address Region #2", "selfm.fastser.unswrite_addr2", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unswrite_num_reg,
{ "Number of Registers", "selfm.fastser.unswrite_num_reg", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_unswrite_reg_val,
{ "Register Value", "selfm.fastser.unswrite_reg_val", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_read_baseaddr,
{ "Base Address", "selfm.fastser.read_baseaddr", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_read_numaddr,
{ "Number of Addresses", "selfm.fastser.read_numaddr", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_datafmt_resp_num_tag,
{ "Number of Tags", "selfm.fastser.datafmt_resp_numtag", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_datafmt_resp_tag_qty,
{ "Quantity of Values within Tag", "selfm.fastser.datafmt_resp_tagqty", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_datafmt_resp_tag_type,
{ "Tag Data Type", "selfm.fastser.datafmt_resp_tagtype", FT_UINT8, BASE_HEX, VALS(selfm_fastser_tagtype_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastser_devdesc_num_reg,
{ "Number of Data Regions", "selfm.fastser.devdesc_num_reg", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_selfm,
&ett_selfm_relaydef,
&ett_selfm_relaydef_fm,
&ett_selfm_relaydef_proto,
&ett_selfm_relaydef_flags,
&ett_selfm_fmconfig,
&ett_selfm_fmconfig_ai,
&ett_selfm_foconfig,
&ett_selfm_foconfig_brkr,
&ett_selfm_foconfig_rb,
&ett_selfm_fastop,
&ett_selfm_fmdata,
&ett_selfm_fmdata_ai,
&ett_selfm_fmdata_dig,
&ett_selfm_fmdata_ai_ch,
&ett_selfm_fmdata_dig_ch,
&ett_selfm_fastser,
&ett_selfm_fastser_seq,
&ett_selfm_fastser_def_fc,
&ett_selfm_fastser_tag,
&ett_selfm_fastser_element_list,
&ett_selfm_fastser_element,
&ett_selfm_fastser_datareg,
};
module_t *selfm_module;
proto_selfm = proto_register_protocol("SEL Fast Message", "SEL Fast Message", "selfm");
new_register_dissector("selfm", dissect_selfm_simple, proto_selfm);
proto_register_field_array(proto_selfm, selfm_hf, array_length(selfm_hf));
proto_register_subtree_array(ett, array_length(ett));
selfm_module = prefs_register_protocol(proto_selfm, proto_reg_handoff_selfm);
prefs_register_bool_preference(selfm_module, "desegment",
"Desegment all SEL Fast Message Protocol packets spanning multiple TCP segments",
"Whether the SEL Protocol dissector should desegment all messages spanning multiple TCP segments",
&selfm_desegment);
prefs_register_bool_preference(selfm_module, "telnetclean",
"Enable Automatic pre-processing of Telnet-encapsulated data to remove extra 0xFF (IAC) bytes",
"Whether the SEL Protocol dissector should automatically pre-process Telnet data to remove IAC bytes",
&selfm_telnet_clean);
prefs_register_uint_preference(selfm_module, "tcp.port", "SEL Protocol Port",
"Set the TCP port for SEL FM Protocol packets (if other"
" than the default of 0)",
10, &global_selfm_tcp_port);
}
void
proto_reg_handoff_selfm(void)
{
static int selfm_prefs_initialized = FALSE;
static dissector_handle_t selfm_handle;
static unsigned int selfm_port;
if (! selfm_prefs_initialized) {
selfm_handle = new_create_dissector_handle(dissect_selfm_tcp, proto_selfm);
selfm_prefs_initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port", selfm_port, selfm_handle);
}
selfm_port = global_selfm_tcp_port;
dissector_add_uint("tcp.port", selfm_port, selfm_handle);
}
