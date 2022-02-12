static tvbuff_t *
clean_telnet_iac(packet_info *pinfo, tvbuff_t *tvb, int offset, int len)
{
tvbuff_t *telnet_tvb;
guint8 *buf;
const guint8 *spos;
guint8 *dpos;
int skip_byte, len_remaining;
spos=tvb_get_ptr(tvb, offset, len);
buf=(guint8 *)g_malloc(len);
dpos=buf;
skip_byte = 0;
len_remaining = len;
while(len_remaining > 0){
if (len_remaining > 1) {
if((spos[0]==0xff) && (spos[1]==0xff)){
skip_byte++;
len_remaining -= 2;
*(dpos++)=0xff;
spos+=2;
continue;
}
}
*(dpos++)=*(spos++);
len_remaining--;
}
telnet_tvb = tvb_new_child_real_data(tvb, buf, len-skip_byte, len-skip_byte);
tvb_set_free_cb(telnet_tvb, g_free);
add_new_data_source(pinfo, telnet_tvb, "Processed Telnet Data");
return telnet_tvb;
}
static fm_config_frame* fmconfig_frame_fast(tvbuff_t *tvb)
{
guint count, offset = 0;
fm_config_frame *frame;
frame = wmem_new(wmem_file_scope(), fm_config_frame);
frame->cfg_cmd = tvb_get_ntohs(tvb, offset);
frame->num_flags = tvb_get_guint8(tvb, offset+3);
frame->sf_loc = tvb_get_guint8(tvb, offset+4);
frame->sf_num = tvb_get_guint8(tvb, offset+5);
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
if (frame->sf_loc == FM_CONFIG_SF_LOC_CFG) {
analog->sf_fp = tvb_get_ntohieee_float(tvb, analog->sf_offset);
}
else {
analog->sf_fp = 1;
}
offset += 10;
}
return frame;
}
static fastmsg_dataitem* fastmsg_dataitem_save(tvbuff_t *tvb, int offset)
{
fastmsg_dataitem *dataitem;
dataitem = wmem_new(wmem_file_scope(), fastmsg_dataitem);
tvb_memcpy(tvb, dataitem->name, offset, 10);
dataitem->name[10] = '\0';
dataitem->quantity = tvb_get_ntohs(tvb, offset+10);
dataitem->data_type = tvb_get_ntohs(tvb, offset+12);
return dataitem;
}
static fastmsg_dataregion* fastmsg_dataregion_save(tvbuff_t *tvb, int offset)
{
fastmsg_dataregion *dataregion;
dataregion = wmem_new(wmem_file_scope(), fastmsg_dataregion);
tvb_memcpy(tvb, dataregion->name, offset, 10);
dataregion->name[10] = '\0';
return dataregion;
}
static const gchar*
region_lookup(packet_info *pinfo, guint32 base_addr)
{
fm_conversation *conv;
fastmsg_dataregion *dataregion = NULL;
conv = (fm_conversation *)p_get_proto_data(wmem_file_scope(), pinfo, proto_selfm, 0);
if (conv) {
dataregion = (fastmsg_dataregion*)wmem_tree_lookup32(conv->fastmsg_dataregions, base_addr);
}
if (dataregion) {
return dataregion->name;
}
return "Unknown Region";
}
static fastser_uns_wordbit* fastser_uns_wordbit_save(guint8 idx, const char *name)
{
fastser_uns_wordbit *wordbit_item;
wordbit_item = wmem_new(wmem_file_scope(), fastser_uns_wordbit);
if (idx <= 253) {
wordbit_item->name = wmem_strdup(wmem_file_scope(), name);
}
if (idx == 254) {
wordbit_item->name = wmem_strdup(wmem_file_scope(), "POWER_UP");
}
if (idx == 255) {
wordbit_item->name = wmem_strdup(wmem_file_scope(), "SET_CHNG");
}
return wordbit_item;
}
static const gchar*
fastser_uns_wordbit_lookup(packet_info *pinfo, guint8 idx)
{
fm_conversation *conv;
fastser_uns_wordbit *wordbit = NULL;
conv = (fm_conversation *)p_get_proto_data(wmem_file_scope(), pinfo, proto_selfm, 0);
if (conv) {
wordbit = (fastser_uns_wordbit*)wmem_tree_lookup32(conv->fastser_uns_wordbits, idx);
}
if (wordbit) {
return wordbit->name;
}
return "Unknown";
}
static int
dissect_relaydef_frame(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *relaydef_fm_item, *relaydef_flags_item, *relaydef_proto_item;
proto_tree *relaydef_tree, *relaydef_fm_tree, *relaydef_flags_tree, *relaydef_proto_tree;
guint8 len, num_proto, num_fm, num_flags;
int count;
len = tvb_get_guint8(tvb, offset);
num_proto = tvb_get_guint8(tvb, offset+1);
num_fm = tvb_get_guint8(tvb, offset+2);
num_flags = tvb_get_guint8(tvb, offset+3);
relaydef_tree = proto_tree_add_subtree(tree, tvb, offset, len-2, ett_selfm_relaydef, NULL, "Relay Definition Block Details");
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
if (tvb_reported_length_remaining(tvb, offset) > 1) {
proto_tree_add_item(relaydef_tree, hf_selfm_padbyte, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
proto_tree_add_item(relaydef_tree, hf_selfm_checksum, tvb, offset, 1, ENC_BIG_ENDIAN);
return tvb_reported_length(tvb);
}
static int
dissect_fmconfig_frame(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree *fmconfig_tree, *fmconfig_ai_tree=NULL, *fmconfig_calc_tree=NULL;
guint count;
guint8 len, sf_loc, num_sf, num_ai, num_calc;
gchar* ai_name;
len = tvb_get_guint8(tvb, offset);
sf_loc = tvb_get_guint8(tvb, offset+2);
num_sf = tvb_get_guint8(tvb, offset+3);
num_ai = tvb_get_guint8(tvb, offset+4);
num_calc = tvb_get_guint8(tvb, offset+7);
fmconfig_tree = proto_tree_add_subtree(tree, tvb, offset, len, ett_selfm_fmconfig, NULL, "Fast Meter Configuration Details");
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
ai_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 6, ENC_ASCII);
fmconfig_ai_tree = proto_tree_add_subtree_format(fmconfig_tree, tvb, offset, 10,
ett_selfm_fmconfig_ai, NULL, "Analog Channel: %s", ai_name);
proto_tree_add_item(fmconfig_ai_tree, hf_selfm_fmconfig_ai_channel, tvb, offset, 6, ENC_ASCII|ENC_NA);
proto_tree_add_item(fmconfig_ai_tree, hf_selfm_fmconfig_ai_type, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_ai_tree, hf_selfm_fmconfig_ai_sf_type, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_ai_tree, hf_selfm_fmconfig_ai_sf_ofs, tvb, offset+8, 2, ENC_BIG_ENDIAN);
offset += 10;
}
for (count = 0; count < num_calc; count++) {
fmconfig_calc_tree = proto_tree_add_subtree_format(fmconfig_tree, tvb, offset, 14,
ett_selfm_fmconfig_calc, NULL, "Calculation Block: %d", count+1);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_rot, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_vconn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_iconn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_ctype, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_deskew_ofs, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_rs_ofs, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_xs_ofs, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_ia_idx, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_ib_idx, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_ic_idx, tvb, offset+10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_va_idx, tvb, offset+11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_vb_idx, tvb, offset+12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmconfig_calc_tree, hf_selfm_fmconfig_cblk_vc_idx, tvb, offset+13, 1, ENC_BIG_ENDIAN);
offset += 14;
}
if ((num_sf != 0) && (sf_loc == FM_CONFIG_SF_LOC_CFG)) {
for (count = 0; count < num_sf; count++) {
proto_tree_add_item(fmconfig_tree, hf_selfm_fmconfig_ai_sf_float, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
if (tvb_reported_length_remaining(tvb, offset) > 1) {
proto_tree_add_item(fmconfig_tree, hf_selfm_padbyte, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
proto_tree_add_item(fmconfig_tree, hf_selfm_checksum, tvb, offset, 1, ENC_BIG_ENDIAN);
return tvb_reported_length(tvb);
}
static int
dissect_fmdata_frame(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, guint16 config_cmd_match)
{
proto_item *fmdata_item, *fmdata_dig_ch_item;
proto_item *fmdata_ai_sf_item;
proto_tree *fmdata_tree, *fmdata_ai_tree=NULL, *fmdata_dig_tree=NULL, *fmdata_ai_ch_tree=NULL, *fmdata_dig_ch_tree=NULL;
guint8 len, idx=0, j=0, ts_mon, ts_day, ts_year, ts_hour, ts_min, ts_sec;
guint16 config_cmd, ts_msec;
gint16 ai_int16val;
gint cnt = 0, ch_size=0;
gfloat ai_sf_fp;
gboolean config_found = FALSE;
fm_conversation *conv;
fm_config_frame *cfg_data;
len = tvb_get_guint8(tvb, offset);
fmdata_tree = proto_tree_add_subtree_format(tree, tvb, offset, len-2, ett_selfm_fmdata, &fmdata_item, "Fast Meter Data Details");
proto_tree_add_item(fmdata_tree, hf_selfm_fmdata_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
{
conv = (fm_conversation *)p_get_proto_data(wmem_file_scope(), pinfo, proto_selfm, 0);
if (conv) {
wmem_list_frame_t *frame = wmem_list_head(conv->fm_config_frames);
while (frame && !config_found) {
cfg_data = (fm_config_frame *)wmem_list_frame_data(frame);
config_cmd = cfg_data->cfg_cmd;
if (config_cmd == config_cmd_match) {
proto_item_append_text(fmdata_item, ", using frame number %"G_GUINT32_FORMAT" as Configuration Frame",
cfg_data->fnum);
config_found = TRUE;
}
frame = wmem_list_frame_next(frame);
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
fmdata_ai_tree = proto_tree_add_subtree_format(fmdata_tree, tvb, offset, ((cfg_data->offset_ts - cfg_data->offset_ai)/cfg_data->num_ai_samples),
ett_selfm_fmdata_ai, NULL, "Analog Channels (%d), Sample: %d (%s)",
cfg_data->num_ai, j+1, val_to_str_const(j+1, selfm_fmconfig_numsamples1_vals, "Unknown"));
}
else if (cfg_data->num_ai_samples == 2) {
fmdata_ai_tree = proto_tree_add_subtree_format(fmdata_tree, tvb, offset, ((cfg_data->offset_ts - cfg_data->offset_ai)/cfg_data->num_ai_samples),
ett_selfm_fmdata_ai, NULL, "Analog Channels (%d), Sample: %d (%s)",
cfg_data->num_ai, j+1, val_to_str_const(j+1, selfm_fmconfig_numsamples2_vals, "Unknown"));
}
else if (cfg_data->num_ai_samples == 4) {
fmdata_ai_tree = proto_tree_add_subtree_format(fmdata_tree, tvb, offset, ((cfg_data->offset_ts - cfg_data->offset_ai)/cfg_data->num_ai_samples),
ett_selfm_fmdata_ai, NULL, "Analog Channels (%d), Sample: %d (%s)",
cfg_data->num_ai, j+1, val_to_str_const(j+1, selfm_fmconfig_numsamples4_vals, "Unknown"));
}
for (idx = 0; idx < cnt; idx++) {
fm_analog_info *ai = &(cfg_data->analogs[idx]);
switch (ai->type) {
case FM_CONFIG_ANA_CHTYPE_INT16:
ch_size = 2;
break;
case FM_CONFIG_ANA_CHTYPE_FP:
ch_size = 4;
break;
case FM_CONFIG_ANA_CHTYPE_FPD:
ch_size = 8;
break;
default:
break;
}
fmdata_ai_ch_tree = proto_tree_add_subtree_format(fmdata_ai_tree, tvb, offset, ch_size,
ett_selfm_fmdata_ai_ch, NULL, "Analog Channel %d: %s", idx+1, ai->name);
switch (ai->type) {
case FM_CONFIG_ANA_CHTYPE_INT16:
ai_int16val = tvb_get_ntohs(tvb, offset);
if ((ai->sf_offset != 0) && (ai->sf_type == FM_CONFIG_ANA_SFTYPE_FP) && (cfg_data->sf_loc == FM_CONFIG_SF_LOC_FM)) {
ai_sf_fp = tvb_get_ntohieee_float(tvb, ai->sf_offset);
proto_tree_add_float(fmdata_ai_ch_tree, hf_selfm_fmdata_ai_sf_fp, tvb, ai->sf_offset, 4, ai_sf_fp);
}
else if (cfg_data->sf_loc == FM_CONFIG_SF_LOC_CFG) {
ai_sf_fp = ai->sf_fp;
fmdata_ai_sf_item = proto_tree_add_float(fmdata_ai_ch_tree, hf_selfm_fmdata_ai_sf_fp, tvb, offset, ch_size, ai_sf_fp);
PROTO_ITEM_SET_GENERATED(fmdata_ai_sf_item);
}
else {
ai_sf_fp = 1;
}
proto_tree_add_uint(fmdata_ai_ch_tree, hf_selfm_fmdata_ai_value16, tvb, offset, ch_size, ai_int16val);
proto_tree_add_float(fmdata_ai_ch_tree, hf_selfm_fmdata_ai_scale_factor, tvb, offset, ch_size, ((gfloat)ai_int16val*ai_sf_fp));
offset += ch_size;
break;
case FM_CONFIG_ANA_CHTYPE_FP:
proto_tree_add_item(fmdata_ai_ch_tree, hf_selfm_fmdata_ai_value_float, tvb, offset, ch_size, ENC_BIG_ENDIAN);
offset += ch_size;
break;
case FM_CONFIG_ANA_CHTYPE_FPD:
proto_tree_add_item(fmdata_ai_ch_tree, hf_selfm_fmdata_ai_value_double, tvb, offset, ch_size, ENC_BIG_ENDIAN);
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
proto_tree_add_bytes_format_value(fmdata_tree, hf_selfm_fmdata_timestamp, tvb, offset, 8, NULL,
"%.2d/%.2d/%.2d %.2d:%.2d:%.2d.%.3d", ts_mon, ts_day, ts_year, ts_hour, ts_min, ts_sec, ts_msec);
offset += 8;
}
if (cfg_data->num_dig > 0) {
fmdata_dig_tree = proto_tree_add_subtree_format(fmdata_tree, tvb, offset, cfg_data->num_dig,
ett_selfm_fmdata_dig, NULL, "Digital Channels (%d)", cfg_data->num_dig);
for (idx=0; idx < cfg_data->num_dig; idx++) {
fmdata_dig_ch_tree = proto_tree_add_subtree_format(fmdata_dig_tree, tvb, offset, 1, ett_selfm_fmdata_dig_ch, &fmdata_dig_ch_item, "Digital Word Bit Row: %2d", idx+1);
proto_item_append_text(fmdata_dig_ch_item, " [ %d %d %d %d %d %d %d %d ]",
((tvb_get_guint8(tvb, offset) & 0x80) >> 7), ((tvb_get_guint8(tvb, offset) & 0x40) >> 6),
((tvb_get_guint8(tvb, offset) & 0x20) >> 5), ((tvb_get_guint8(tvb, offset) & 0x10) >> 4),
((tvb_get_guint8(tvb, offset) & 0x08) >> 3), ((tvb_get_guint8(tvb, offset) & 0x04) >> 2),
((tvb_get_guint8(tvb, offset) & 0x02) >> 1), (tvb_get_guint8(tvb, offset) & 0x01));
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
if (tvb_reported_length_remaining(tvb, offset) > 1) {
proto_tree_add_item(fmdata_tree, hf_selfm_padbyte, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
proto_tree_add_item(fmdata_tree, hf_selfm_checksum, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
if (!config_found) {
proto_item_append_text(fmdata_item, ", No Fast Meter Configuration frame found");
return 0;
}
}
return tvb_reported_length(tvb);
}
static int
dissect_foconfig_frame(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *foconfig_brkr_item, *foconfig_rb_item;
proto_tree *foconfig_tree, *foconfig_brkr_tree=NULL, *foconfig_rb_tree=NULL;
guint count;
guint8 len, num_brkr, prb_supp;
guint16 num_rb;
len = tvb_get_guint8(tvb, offset);
num_brkr = tvb_get_guint8(tvb, offset+1);
num_rb = tvb_get_ntohs(tvb, offset+2);
prb_supp = tvb_get_guint8(tvb, offset+4);
foconfig_tree = proto_tree_add_subtree(tree, tvb, offset, len-2, ett_selfm_foconfig, NULL, "Fast Operate Configuration Details");
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
if (tvb_reported_length_remaining(tvb, offset) > 1) {
proto_tree_add_item(foconfig_tree, hf_selfm_padbyte, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
proto_tree_add_item(foconfig_tree, hf_selfm_checksum, tvb, offset, 1, ENC_BIG_ENDIAN);
return tvb_reported_length(tvb);
}
static int
dissect_alt_fastop_config_frame(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree *foconfig_tree;
guint8 len;
len = tvb_get_guint8(tvb, offset);
foconfig_tree = proto_tree_add_subtree(tree, tvb, offset, len-2,
ett_selfm_foconfig, NULL, "Alternate Fast Operate Configuration Details");
proto_tree_add_item(foconfig_tree, hf_selfm_alt_foconfig_len, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_tree, hf_selfm_alt_foconfig_num_ports, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_tree, hf_selfm_alt_foconfig_num_brkr, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_tree, hf_selfm_alt_foconfig_num_rb, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_tree, hf_selfm_alt_foconfig_funccode, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_tree, hf_selfm_alt_foconfig_funccode, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_tree, hf_selfm_alt_foconfig_funccode, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_tree, hf_selfm_alt_foconfig_funccode, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(foconfig_tree, hf_selfm_alt_foconfig_funccode, tvb, offset+8, 1, ENC_BIG_ENDIAN);
return tvb_reported_length(tvb);
}
static int
dissect_fastop_frame(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_tree *fastop_tree;
guint8 len, opcode;
guint16 msg_type;
msg_type = tvb_get_ntohs(tvb, offset-2);
len = tvb_get_guint8(tvb, offset);
fastop_tree = proto_tree_add_subtree(tree, tvb, offset, len-2, ett_selfm_fastop, NULL, "Fast Operate Details");
proto_tree_add_item(fastop_tree, hf_selfm_fastop_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
opcode = tvb_get_guint8(tvb, offset);
if (msg_type == CMD_FASTOP_RB_CTRL) {
proto_tree_add_item(fastop_tree, hf_selfm_fastop_rb_code, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", val_to_str_ext_const(opcode, &selfm_fo_rb_vals_ext, "Unknown Control Code"));
}
else if (msg_type == CMD_FASTOP_BR_CTRL) {
proto_tree_add_item(fastop_tree, hf_selfm_fastop_br_code, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", val_to_str_ext_const(opcode, &selfm_fo_br_vals_ext, "Unknown Control Code"));
}
offset += 1;
proto_tree_add_item(fastop_tree, hf_selfm_fastop_valid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(fastop_tree, hf_selfm_checksum, tvb, offset, 1, ENC_BIG_ENDIAN);
return tvb_reported_length(tvb);
}
static int
dissect_alt_fastop_frame(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_tree *fastop_tree;
guint8 len;
guint16 opcode;
len = tvb_get_guint8(tvb, offset);
fastop_tree = proto_tree_add_subtree(tree, tvb, offset, len-2, ett_selfm_fastop, NULL, "Alternate Fast Operate Details");
proto_tree_add_item(fastop_tree, hf_selfm_alt_fastop_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
opcode = tvb_get_ntohs(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x", opcode);
proto_tree_add_item(fastop_tree, hf_selfm_alt_fastop_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(fastop_tree, hf_selfm_alt_fastop_valid, tvb, offset, 2, ENC_BIG_ENDIAN);
return tvb_reported_length(tvb);
}
static int
dissect_fastmsg_readresp_frame(tvbuff_t *tvb, proto_tree *fastmsg_tree, packet_info *pinfo, int offset, guint8 seq_byte)
{
proto_item *fastmsg_tag_value_item=NULL, *fmdata_dig_item=NULL;
proto_item *pi_baseaddr=NULL, *pi_fnum=NULL, *pi_type=NULL, *pi_qty=NULL;
proto_tree *fastmsg_tag_tree=NULL, *fmdata_dig_tree=NULL;
guint32 base_addr;
guint16 data_size, num_addr, cnt;
guint8 seq_cnt;
gboolean seq_fir, seq_fin, save_fragmented;
int payload_offset=0;
fm_conversation *conv;
fastmsg_dataitem *dataitem;
tvbuff_t *data_tvb, *payload_tvb;
seq_cnt = seq_byte & FAST_MSG_SEQ_CNT;
seq_fir = ((seq_byte & FAST_MSG_SEQ_FIR) >> 7);
seq_fin = ((seq_byte & FAST_MSG_SEQ_FIN) >> 6);
base_addr = tvb_get_ntohl(tvb, offset);
num_addr = tvb_get_ntohs(tvb, offset+4);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x [%s]", base_addr, region_lookup(pinfo, base_addr));
pi_baseaddr = proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_baseaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(pi_baseaddr, " [%s]", region_lookup(pinfo, base_addr));
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_numwords, tvb, offset+4, 2, ENC_BIG_ENDIAN);
offset += 6;
data_tvb = tvb_new_subset( tvb, offset, (tvb_reported_length_remaining(tvb, offset)-2), (tvb_reported_length_remaining(tvb, offset)-2));
save_fragmented = pinfo->fragmented;
if (! (seq_fir && seq_fin)) {
fragment_head *frag_msg;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_next(&selfm_reassembly_table,
data_tvb, 0, pinfo, 0, NULL,
tvb_reported_length(data_tvb),
!seq_fin);
payload_tvb = process_reassembled_data(data_tvb, 0, pinfo,
"Reassembled Data Response Payload", frag_msg, &selfm_frag_items,
NULL, fastmsg_tree);
if (payload_tvb) {
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Reassembled Data Response");
}
else
{
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Response Data Fragment %u" , seq_cnt);
}
}
else {
payload_tvb = data_tvb;
add_new_data_source(pinfo, payload_tvb, "Data Response Payload");
}
pinfo->fragmented = save_fragmented;
if (payload_tvb) {
conv = (fm_conversation *)p_get_proto_data(wmem_file_scope(), pinfo, proto_selfm, 0);
if (conv) {
wmem_list_frame_t *frame = wmem_list_head(conv->fastmsg_dataitems);
while (frame) {
dataitem = (fastmsg_dataitem *)wmem_list_frame_data(frame);
if (dataitem->base_address == base_addr) {
switch (dataitem->data_type) {
case FAST_MSG_TAGTYPE_CHAR8:
case FAST_MSG_TAGTYPE_DIGWORD8_BL:
case FAST_MSG_TAGTYPE_DIGWORD8:
data_size = 1 * dataitem->quantity;
break;
case FAST_MSG_TAGTYPE_CHAR16:
case FAST_MSG_TAGTYPE_DIGWORD16_BL:
case FAST_MSG_TAGTYPE_DIGWORD16:
case FAST_MSG_TAGTYPE_INT16:
case FAST_MSG_TAGTYPE_UINT16:
data_size = 2 * dataitem->quantity;
break;
case FAST_MSG_TAGTYPE_INT32:
case FAST_MSG_TAGTYPE_UINT32:
case FAST_MSG_TAGTYPE_FLOAT:
data_size = 4 * dataitem->quantity;
break;
default:
data_size = 0;
break;
}
fastmsg_tag_tree = proto_tree_add_subtree_format(fastmsg_tree, payload_tvb, payload_offset, data_size,
ett_selfm_fastmsg_tag, NULL, "Data Item Name: %s", dataitem->name);
pi_fnum = proto_tree_add_uint_format(fastmsg_tag_tree, hf_selfm_fmdata_frame_data_format_reference, payload_tvb, payload_offset, data_size,
dataitem->fnum, "Using frame number %d (Index Pos: %d) as Data Format Reference",dataitem->fnum, dataitem->index_pos );
pi_type = proto_tree_add_uint(fastmsg_tag_tree, hf_selfm_fmdata_data_type, payload_tvb, payload_offset, 0, dataitem->data_type);
pi_qty = proto_tree_add_uint(fastmsg_tag_tree, hf_selfm_fmdata_quantity, payload_tvb, payload_offset, 0, dataitem->quantity );
PROTO_ITEM_SET_GENERATED(pi_fnum);
PROTO_ITEM_SET_GENERATED(pi_type);
proto_item_set_len(pi_type, data_size);
PROTO_ITEM_SET_GENERATED(pi_qty);
proto_item_set_len(pi_qty, data_size);
switch (dataitem->data_type) {
case FAST_MSG_TAGTYPE_DIGWORD8_BL:
case FAST_MSG_TAGTYPE_DIGWORD8:
for (cnt=1; cnt <= dataitem->quantity; cnt++) {
fmdata_dig_tree = proto_tree_add_subtree_format(fastmsg_tag_tree, payload_tvb, payload_offset, 1,
ett_selfm_fmdata_dig, &fmdata_dig_item, "8-bit Binary Items (Row: %2d)", cnt);
proto_item_append_text(fmdata_dig_item, " [ %d %d %d %d %d %d %d %d ]",
((tvb_get_guint8(payload_tvb, payload_offset) & 0x80) >> 7), ((tvb_get_guint8(payload_tvb, payload_offset) & 0x40) >> 6),
((tvb_get_guint8(payload_tvb, payload_offset) & 0x20) >> 5), ((tvb_get_guint8(payload_tvb, payload_offset) & 0x10) >> 4),
((tvb_get_guint8(payload_tvb, payload_offset) & 0x08) >> 3), ((tvb_get_guint8(payload_tvb, payload_offset) & 0x04) >> 2),
((tvb_get_guint8(payload_tvb, payload_offset) & 0x02) >> 1), (tvb_get_guint8(payload_tvb, payload_offset) & 0x01));
proto_tree_add_item(fmdata_dig_tree, hf_selfm_fmdata_dig_b0, payload_tvb, payload_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_tree, hf_selfm_fmdata_dig_b1, payload_tvb, payload_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_tree, hf_selfm_fmdata_dig_b2, payload_tvb, payload_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_tree, hf_selfm_fmdata_dig_b3, payload_tvb, payload_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_tree, hf_selfm_fmdata_dig_b4, payload_tvb, payload_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_tree, hf_selfm_fmdata_dig_b5, payload_tvb, payload_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_tree, hf_selfm_fmdata_dig_b6, payload_tvb, payload_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmdata_dig_tree, hf_selfm_fmdata_dig_b7, payload_tvb, payload_offset, 1, ENC_BIG_ENDIAN);
payload_offset += 1;
}
break;
case FAST_MSG_TAGTYPE_CHAR8:
case FAST_MSG_TAGTYPE_CHAR16:
proto_tree_add_item(fastmsg_tag_tree, hf_selfm_fmdata_ai_value_string, payload_tvb, payload_offset, data_size, ENC_ASCII|ENC_NA);
payload_offset += data_size;
break;
case FAST_MSG_TAGTYPE_INT16:
for (cnt=1; cnt <= dataitem->quantity; cnt++) {
fastmsg_tag_value_item = proto_tree_add_item(fastmsg_tag_tree, hf_selfm_fastmsg_dataitem_int16, payload_tvb, payload_offset, data_size/dataitem->quantity, ENC_BIG_ENDIAN);
proto_item_prepend_text(fastmsg_tag_value_item, "Value %d ", cnt);
payload_offset += data_size/dataitem->quantity;
}
break;
case FAST_MSG_TAGTYPE_UINT16:
for (cnt=1; cnt <= dataitem->quantity; cnt++) {
fastmsg_tag_value_item = proto_tree_add_item(fastmsg_tag_tree, hf_selfm_fastmsg_dataitem_uint16, payload_tvb, payload_offset, data_size/dataitem->quantity, ENC_BIG_ENDIAN);
proto_item_prepend_text(fastmsg_tag_value_item, "Value %d ", cnt);
payload_offset += data_size/dataitem->quantity;
}
break;
case FAST_MSG_TAGTYPE_INT32:
for (cnt=1; cnt <= dataitem->quantity; cnt++) {
fastmsg_tag_value_item = proto_tree_add_item(fastmsg_tag_tree, hf_selfm_fastmsg_dataitem_int32, payload_tvb, payload_offset, data_size/dataitem->quantity, ENC_BIG_ENDIAN);
proto_item_prepend_text(fastmsg_tag_value_item, "Value %d ", cnt);
payload_offset += data_size/dataitem->quantity;
}
break;
case FAST_MSG_TAGTYPE_UINT32:
for (cnt=1; cnt <= dataitem->quantity; cnt++) {
fastmsg_tag_value_item = proto_tree_add_item(fastmsg_tag_tree, hf_selfm_fastmsg_dataitem_uint32, payload_tvb, payload_offset, data_size/dataitem->quantity, ENC_BIG_ENDIAN);
proto_item_prepend_text(fastmsg_tag_value_item, "Value %d ", cnt);
payload_offset += data_size/dataitem->quantity;
}
break;
case FAST_MSG_TAGTYPE_FLOAT:
for (cnt=1; cnt <= dataitem->quantity; cnt++) {
fastmsg_tag_value_item = proto_tree_add_item(fastmsg_tag_tree, hf_selfm_fastmsg_dataitem_float, payload_tvb, payload_offset, data_size/dataitem->quantity, ENC_BIG_ENDIAN);
proto_item_prepend_text(fastmsg_tag_value_item, "Value %d ", cnt);
payload_offset += data_size/dataitem->quantity;
}
break;
default:
break;
}
}
frame = wmem_list_frame_next(frame);
}
}
}
offset += num_addr*2;
return offset;
}
static int
dissect_fastmsg_frame(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_item *fastmsg_def_fc_item, *fastmsg_elementlist_item;
proto_item *pi_baseaddr, *fastmsg_crc16_item;
proto_tree *fastmsg_tree, *fastmsg_def_fc_tree=NULL, *fastmsg_elementlist_tree=NULL;
proto_tree *fastmsg_element_tree=NULL, *fastmsg_datareg_tree=NULL, *fastmsg_tag_tree=NULL;
gint cnt, num_elements, elmt_status32_ofs=0, elmt_status, null_offset;
guint8 len, funccode, seq, rx_num_fc, tx_num_fc;
guint8 seq_cnt, elmt_idx, fc_enable;
guint8 *tag_name_ptr;
guint16 base_addr, num_addr, num_reg, addr1, addr2, crc16, crc16_calc;
guint32 tod_ms, elmt_status32, elmt_ts_offset;
static const int * seq_fields[] = {
&hf_selfm_fastmsg_seq_fir,
&hf_selfm_fastmsg_seq_fin,
&hf_selfm_fastmsg_seq_cnt,
NULL
};
len = tvb_get_guint8(tvb, offset);
fastmsg_tree = proto_tree_add_subtree(tree, tvb, offset, len-2, ett_selfm_fastmsg, NULL, "Fast Message Details");
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_len, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_routing_addr, tvb, offset+1, 5, ENC_NA);
offset += 6;
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
funccode = tvb_get_guint8(tvb, offset);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_funccode, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", val_to_str_ext_const(funccode, &selfm_fastmsg_func_code_vals_ext, "Unknown Function Code"));
offset += 1;
seq = tvb_get_guint8(tvb, offset);
seq_cnt = seq & FAST_MSG_SEQ_CNT;
proto_tree_add_bitmask_with_flags(fastmsg_tree, tvb, offset, hf_selfm_fastmsg_seq, ett_selfm_fastmsg_seq,
seq_fields, ENC_NA, BMT_NO_APPEND);
offset += 1;
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_resp_num, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (funccode) {
case FAST_MSG_EN_UNS_DATA:
fc_enable = tvb_get_guint8(tvb, offset);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_uns_en_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Function to Enable (%#x)", fc_enable);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_uns_en_fc_data, tvb, offset+1, 3, ENC_NA);
offset += 4;
break;
case FAST_MSG_DIS_UNS_DATA:
fc_enable = tvb_get_guint8(tvb, offset);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_uns_dis_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Function to Disable (%#x)", fc_enable);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_uns_dis_fc_data, tvb, offset+1, 1, ENC_NA);
offset += 2;
break;
case FAST_MSG_READ_REQ:
base_addr = tvb_get_ntohl(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x [%s]", base_addr, region_lookup(pinfo, base_addr));
pi_baseaddr = proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_baseaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(pi_baseaddr, " [%s]", region_lookup(pinfo, base_addr));
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_numwords, tvb, offset+4, 2, ENC_BIG_ENDIAN);
offset += 6;
break;
case FAST_MSG_GEN_UNS_DATA:
num_addr = len - 14;
num_reg = num_addr / 2;
for (cnt=0; cnt < num_reg; cnt++) {
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_unswrite_reg_val, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case FAST_MSG_SOE_STATE_REQ:
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_soe_req_orig, tvb, offset, 4, ENC_NA);
offset += 4;
break;
case FAST_MSG_UNS_RESP:
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_unsresp_orig, tvb, offset, 4, ENC_NA);
offset += 4;
tod_ms = tvb_get_ntohl(tvb, offset+4);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_unsresp_doy, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_unsresp_year, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(fastmsg_tree, hf_selfm_fastmsg_unsresp_todms, tvb, offset+4, 4,
tod_ms, "%s", time_msecs_to_str(wmem_packet_scope(), tod_ms));
offset += 8;
num_elements = (len-34) / 4;
fastmsg_elementlist_item = proto_tree_add_uint(fastmsg_tree, hf_selfm_fastmsg_unsresp_num_elmt, tvb, offset, (4*num_elements), num_elements);
fastmsg_elementlist_tree = proto_item_add_subtree(fastmsg_elementlist_item, ett_selfm_fastmsg_element_list);
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
fastmsg_element_tree = proto_tree_add_subtree_format(fastmsg_elementlist_tree, tvb, offset, 4, ett_selfm_fastmsg_element, NULL,
"Reported Event %d (Index: %d [%s], New State: %s)", cnt+1, elmt_idx, fastser_uns_wordbit_lookup(pinfo, elmt_idx),
val_to_str_const(elmt_status, selfm_ser_status_vals, "Unknown"));
proto_tree_add_item(fastmsg_element_tree, hf_selfm_fastmsg_unsresp_elmt_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_element_tree, hf_selfm_fastmsg_unsresp_elmt_ts_ofs, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(fastmsg_element_tree, hf_selfm_fastmsg_unsresp_elmt_ts_ofs_decoded, tvb, offset+1, 3,
tod_ms + (elmt_ts_offset/1000), "%s", time_msecs_to_str(wmem_packet_scope(), tod_ms + (elmt_ts_offset/1000)));
proto_tree_add_uint(fastmsg_element_tree, hf_selfm_fastmsg_unsresp_elmt_status, tvb, elmt_status32_ofs, 4, elmt_status);
offset += 4;
}
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_unsresp_eor, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_unsresp_elmt_statword, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case FAST_MSG_UNS_WRITE:
addr1 = tvb_get_ntohs(tvb, offset);
addr2 = tvb_get_ntohs(tvb, offset+2);
num_reg = tvb_get_ntohs(tvb, offset+4);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x, %#x", addr1, addr2);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_unswrite_addr1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_unswrite_addr2, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_unswrite_num_reg, tvb, offset+4, 2, ENC_BIG_ENDIAN);
offset += 6;
for (cnt=0; cnt < num_reg; cnt++) {
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_unswrite_reg_val, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case FAST_MSG_DATAFMT_REQ:
base_addr = tvb_get_ntohl(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x [%s]", base_addr, region_lookup(pinfo, base_addr));
pi_baseaddr = proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_baseaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(pi_baseaddr, " [%s]", region_lookup(pinfo, base_addr));
offset += 4;
break;
case FAST_MSG_BITLABEL_REQ:
base_addr = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_baseaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x", base_addr);
break;
case FAST_MSG_CFG_BLOCK_RESP:
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_def_route_sup, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_def_rx_stat, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_def_tx_stat, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_def_rx_maxfr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_def_tx_maxfr, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
offset += 6;
rx_num_fc = tvb_get_guint8(tvb, offset);
fastmsg_def_fc_item = proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_def_rx_num_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
fastmsg_def_fc_tree = proto_item_add_subtree(fastmsg_def_fc_item, ett_selfm_fastmsg_def_fc);
offset += 1;
for (cnt=0; cnt<rx_num_fc; cnt++) {
proto_tree_add_item(fastmsg_def_fc_tree, hf_selfm_fastmsg_def_rx_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
}
tx_num_fc = tvb_get_guint8(tvb, offset);
fastmsg_def_fc_item = proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_def_tx_num_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
fastmsg_def_fc_tree = proto_item_add_subtree(fastmsg_def_fc_item, ett_selfm_fastmsg_def_fc);
offset += 1;
for (cnt=0; cnt<tx_num_fc; cnt++) {
proto_tree_add_item(fastmsg_def_fc_tree, hf_selfm_fastmsg_def_tx_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case FAST_MSG_READ_RESP:
offset = dissect_fastmsg_readresp_frame( tvb, fastmsg_tree, pinfo, offset, seq);
break;
case FAST_MSG_SOE_STATE_RESP:
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_soe_resp_numblks, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_soe_resp_orig, tvb, offset, 4, ENC_NA);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_soe_resp_numbits, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_soe_resp_pad, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_soe_resp_doy, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_soe_resp_year, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_soe_resp_tod, tvb, offset+10, 4, ENC_BIG_ENDIAN);
offset += 14;
break;
case FAST_MSG_DEVDESC_RESP:
proto_tree_add_item(fastmsg_tree, hf_selfm_fid, tvb, offset, 50, ENC_ASCII|ENC_NA);
proto_tree_add_item(fastmsg_tree, hf_selfm_rid, tvb, offset+50, 40, ENC_ASCII|ENC_NA);
offset += 90;
num_reg = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_devdesc_num_region, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if ((num_reg >= 8) && (seq_cnt == 0)) {
num_reg = 7;
}
else{
num_reg = num_reg - (seq_cnt * 7);
}
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_devdesc_num_ctrl, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for (cnt=0; cnt<num_reg; cnt++) {
fastmsg_datareg_tree = proto_tree_add_subtree_format(fastmsg_tree, tvb, offset, 18,
ett_selfm_fastmsg_datareg, NULL, "Fast Message Data Region #%d", cnt+1);
proto_tree_add_item(fastmsg_datareg_tree, hf_selfm_fastmsg_data_region_name, tvb, offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
proto_tree_add_item(fastmsg_datareg_tree, hf_selfm_fastmsg_baseaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fastmsg_datareg_tree, hf_selfm_fastmsg_numwords, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(fastmsg_datareg_tree, hf_selfm_fastmsg_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
for (cnt = offset; cnt < len; cnt++) {
if (tvb_memeql(tvb, cnt, "\x00\x00\x00\x00\x00\x00\x00\x00", 8) == 0) {
offset = cnt+8;
}
}
break;
case FAST_MSG_DATAFMT_RESP:
base_addr = tvb_get_ntohl(tvb, offset);
pi_baseaddr = proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_baseaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(pi_baseaddr, " [%s]", region_lookup(pinfo, base_addr));
offset += 4;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%#x [%s]", base_addr, region_lookup(pinfo, base_addr));
proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_datafmt_resp_numitem, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while ((tvb_reported_length_remaining(tvb, offset)) > 2) {
tag_name_ptr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 10, ENC_ASCII);
fastmsg_tag_tree = proto_tree_add_subtree_format(fastmsg_tree, tvb, offset, 14, ett_selfm_fastmsg_tag, NULL, "Data Item Record Name: %s", tag_name_ptr);
proto_tree_add_item(fastmsg_tag_tree, hf_selfm_fastmsg_dataitem_qty, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fastmsg_tag_tree, hf_selfm_fastmsg_dataitem_type, tvb, offset+12, 2, ENC_BIG_ENDIAN);
offset += 14;
}
break;
case FAST_MSG_BITLABEL_RESP:
cnt=1;
for (null_offset = offset; null_offset < len; null_offset++) {
if ((tvb_memeql(tvb, null_offset, "\x00", 1) == 0) && (tvb_reported_length_remaining(tvb, offset) > 2)) {
gchar* str = tvb_format_text(tvb, offset, (null_offset-offset));
proto_tree_add_string_format(fastmsg_tree, hf_selfm_fastmsg_bit_label_name, tvb, offset, (null_offset-offset), str,
"Bit Label #%d Name: %s", cnt, str);
offset = null_offset+1;
cnt++;
}
}
break;
default:
break;
}
fastmsg_crc16_item = proto_tree_add_item(fastmsg_tree, hf_selfm_fastmsg_crc16, tvb, offset, 2, ENC_BIG_ENDIAN);
crc16 = tvb_get_ntohs(tvb, offset);
if (selfm_crc16) {
crc16_calc = crc16_plain_tvb_offset_seed(tvb, 0, len-2, 0xFFFF);
if (crc16_calc != crc16) {
expert_add_info_format(pinfo, fastmsg_crc16_item, &ei_selfm_crc16_incorrect, "Incorrect CRC - should be 0x%04x", crc16_calc);
}
else {
proto_item_append_text(fastmsg_crc16_item, " [OK]");
}
}
return tvb_reported_length(tvb);
}
static int
dissect_selfm(tvbuff_t *selfm_tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *selfm_item=NULL;
proto_tree *selfm_tree=NULL;
int offset=0, cnt=0;
guint32 base_addr;
guint16 msg_type, len, num_items;
guint8 seq, seq_cnt;
gchar **uns_ser_split_str;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SEL Protocol");
col_clear(pinfo->cinfo, COL_INFO);
len = tvb_reported_length(selfm_tvb);
msg_type = tvb_get_ntohs(selfm_tvb, offset);
if (!pinfo->fd->flags.visited) {
conversation_t *conversation;
fm_conversation *fm_conv_data;
conversation = find_or_create_conversation(pinfo);
fm_conv_data = (fm_conversation *)conversation_get_proto_data(conversation, proto_selfm);
if (fm_conv_data == NULL) {
fm_conv_data = wmem_new(wmem_file_scope(), fm_conversation);
fm_conv_data->fm_config_frames = wmem_list_new(wmem_file_scope());
fm_conv_data->fastmsg_dataitems = wmem_list_new(wmem_file_scope());
fm_conv_data->fastmsg_dataregions = wmem_tree_new(wmem_file_scope());
fm_conv_data->fastser_uns_wordbits = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_selfm, (void *)fm_conv_data);
uns_ser_split_str = wmem_strsplit(wmem_packet_scope(), selfm_ser_list, ",", -1);
for (cnt = 0; (uns_ser_split_str[cnt] != NULL); cnt++) {
fastser_uns_wordbit *wordbit_ptr = fastser_uns_wordbit_save(cnt, uns_ser_split_str[cnt]);
wmem_tree_insert32(fm_conv_data->fastser_uns_wordbits, cnt, wordbit_ptr);
}
for (cnt = 254; (cnt <= 255); cnt++) {
fastser_uns_wordbit *wordbit_ptr = fastser_uns_wordbit_save(cnt, "unused");
wmem_tree_insert32(fm_conv_data->fastser_uns_wordbits, cnt, wordbit_ptr);
}
}
p_add_proto_data(wmem_file_scope(), pinfo, proto_selfm, 0, fm_conv_data);
if ((CMD_FM_CONFIG == msg_type) || (CMD_DFM_CONFIG == msg_type) || (CMD_PDFM_CONFIG == msg_type)) {
fm_config_frame *frame_ptr = fmconfig_frame_fast(selfm_tvb);
frame_ptr->fnum = pinfo->fd->num;
wmem_list_prepend(fm_conv_data->fm_config_frames, frame_ptr);
}
if ((CMD_FAST_MSG == msg_type) && (tvb_get_guint8(selfm_tvb, offset+9) == FAST_MSG_DATAFMT_RESP)) {
seq = tvb_get_guint8(selfm_tvb, offset+10);
seq_cnt = seq & FAST_MSG_SEQ_CNT;
base_addr = tvb_get_ntohl(selfm_tvb, offset+12);
num_items = tvb_get_ntohs(selfm_tvb, offset+16);
if ((num_items > 16) && (seq_cnt == 0)) {
num_items = 16;
}
else {
num_items = num_items - (seq_cnt * 16);
}
offset = 18;
for (cnt = 1; (cnt <= num_items); cnt++) {
fastmsg_dataitem *dataitem_ptr = fastmsg_dataitem_save(selfm_tvb, offset);
dataitem_ptr->fnum = pinfo->fd->num;
dataitem_ptr->base_address = base_addr;
dataitem_ptr->index_pos = cnt;
wmem_list_append(fm_conv_data->fastmsg_dataitems, dataitem_ptr);
offset += 14;
}
}
if ((CMD_FAST_MSG == msg_type) && (tvb_get_guint8(selfm_tvb, offset+9) == FAST_MSG_READ_RESP)) {
seq = tvb_get_guint8(selfm_tvb, offset+10);
offset = 12;
offset = dissect_fastmsg_readresp_frame( selfm_tvb, tree, pinfo, offset, seq);
}
if ((CMD_FAST_MSG == msg_type) && (tvb_get_guint8(selfm_tvb, offset+9) == FAST_MSG_DEVDESC_RESP)) {
seq = tvb_get_guint8(selfm_tvb, offset+10);
seq_cnt = seq & FAST_MSG_SEQ_CNT;
num_items = tvb_get_ntohs(selfm_tvb, offset+102);
if ((num_items >= 8) && (seq_cnt == 0)) {
num_items = 7;
}
else{
num_items = num_items - (seq_cnt * 7);
}
offset = 106;
for (cnt = 1; (cnt <= num_items); cnt++) {
guint32 base_address = tvb_get_ntohl(selfm_tvb, offset+10);
fastmsg_dataregion *dataregion_ptr = fastmsg_dataregion_save(selfm_tvb, offset);
wmem_tree_insert32(fm_conv_data->fastmsg_dataregions, base_address, dataregion_ptr);
offset += 18;
}
}
}
if (tree) {
selfm_item = proto_tree_add_protocol_format(tree, proto_selfm, selfm_tvb, 0, len, "SEL Protocol");
selfm_tree = proto_item_add_subtree(selfm_item, ett_selfm);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext_const(msg_type, &selfm_msgtype_vals_ext, "Unknown Message Type"));
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
case CMD_FAST_MSG:
dissect_fastmsg_frame(selfm_tvb, selfm_tree, pinfo, offset);
break;
case CMD_FASTOP_RB_CTRL:
case CMD_FASTOP_BR_CTRL:
dissect_fastop_frame(selfm_tvb, selfm_tree, pinfo, offset);
break;
case CMD_ALT_FASTOP_CONFIG:
dissect_alt_fastop_config_frame(selfm_tvb, selfm_tree, offset);
break;
case CMD_ALT_FASTOP_OPEN:
case CMD_ALT_FASTOP_CLOSE:
case CMD_ALT_FASTOP_SET:
case CMD_ALT_FASTOP_CLEAR:
case CMD_ALT_FASTOP_PULSE:
dissect_alt_fastop_frame(selfm_tvb, selfm_tree, pinfo, offset);
break;
default:
break;
}
}
}
return tvb_reported_length(selfm_tvb);
}
static guint
get_selfm_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset _U_, void *data _U_)
{
guint message_len=0;
if (tvb_reported_length(tvb) > 2) {
message_len = tvb_get_guint8(tvb, 2);
}
else if (tvb_reported_length(tvb) == 2) {
message_len = 2;
}
return message_len;
}
static int
dissect_selfm_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tvbuff_t *selfm_tvb;
gint length = tvb_reported_length(tvb);
if(length < 2 || tvb_get_guint8(tvb, 0) != 0xA5) {
return 0;
}
if ((pinfo->srcport) && selfm_telnet_clean) {
selfm_tvb = clean_telnet_iac(pinfo, tvb, 0, length);
}
else {
selfm_tvb = tvb_new_subset_length( tvb, 0, length);
}
tcp_dissect_pdus(selfm_tvb, pinfo, tree, selfm_desegment, 2,
get_selfm_len, dissect_selfm, data);
return length;
}
static int
dissect_selfm_simple(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint length = tvb_reported_length(tvb);
if(length < 2 || tvb_get_guint8(tvb, 0) != 0xA5) {
return 0;
}
dissect_selfm(tvb, pinfo, tree, data);
return length;
}
static void
selfm_init(void)
{
reassembly_table_init(&selfm_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
selfm_cleanup(void)
{
reassembly_table_destroy(&selfm_reassembly_table);
}
void
proto_register_selfm(void)
{
static hf_register_info selfm_hf[] = {
{ &hf_selfm_msgtype,
{ "Message Type", "selfm.msgtype", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &selfm_msgtype_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_padbyte,
{ "Pad Byte", "selfm.padbyte", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_checksum,
{ "Checksum", "selfm.checksum", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
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
{ &hf_selfm_fmconfig_cblk_rot,
{ "Rotation", "selfm.fmconfig.cblk_rot", FT_UINT8, BASE_HEX, VALS(selfm_fmconfig_cblk_rot_vals), 0x01, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_vconn,
{ "Voltage Connection", "selfm.fmconfig.cblk_vconn", FT_UINT8, BASE_HEX, VALS(selfm_fmconfig_cblk_vconn_vals), 0x06, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_iconn,
{ "Current Connection", "selfm.fmconfig.cblk_iconn", FT_UINT8, BASE_HEX, VALS(selfm_fmconfig_cblk_iconn_vals), 0x18, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_ctype,
{ "Calculation Type", "selfm.fmconfig.cblk_ctype", FT_UINT8, BASE_DEC, VALS(selfm_fmconfig_cblk_ctype_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_deskew_ofs,
{ "Skew Correction Offset", "selfm.fmconfig.cblk_deskew_ofs", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_rs_ofs,
{ "Rs Offset", "selfm.fmconfig.cblk_rs_ofs", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_xs_ofs,
{ "Xs Offset", "selfm.fmconfig.cblk_xs_ofs", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_ia_idx,
{ "Analog Record Ia Index Position", "selfm.fmconfig.cblk_ia_idx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_ib_idx,
{ "Analog Record Ib Index Position", "selfm.fmconfig.cblk_ib_idx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_ic_idx,
{ "Analog Record Ic Index Position", "selfm.fmconfig.cblk_ic_idx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_va_idx,
{ "Analog Record Va/Vab Index Position", "selfm.fmconfig.cblk_va_idx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_vb_idx,
{ "Analog Record Vb/Vbc Index Position", "selfm.fmconfig.cblk_vb_idx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_cblk_vc_idx,
{ "Analog Record Vc/Vca Index Position", "selfm.fmconfig.cblk_vc_idx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmconfig_ai_sf_float,
{ "AI Scale Factor (float)", "selfm.fmconfig.ai_sf_float", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
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
{ "Breaker Bit Open Command", "selfm.foconfig.brkr_open", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &selfm_fo_br_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_foconfig_brkr_close,
{ "Breaker Bit Close Command", "selfm.foconfig.brkr_close", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &selfm_fo_br_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_foconfig_rb_cmd,
{ "Remote Bit Command", "selfm.foconfig.rb_cmd", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &selfm_fo_rb_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_alt_foconfig_len,
{ "Length", "selfm.alt_foconfig.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_alt_foconfig_num_ports,
{ "Number of Ports Available", "selfm.alt_foconfig.num_ports", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_alt_foconfig_num_brkr,
{ "Number of Breaker Bits per Port", "selfm.alt_foconfig.num_brkr", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_alt_foconfig_num_rb,
{ "Number of Remote Bits per Port", "selfm.alt_foconfig.num_rb", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_alt_foconfig_funccode,
{ "Supported Function Code", "selfm.alt_foconfig.funccode", FT_UINT8, BASE_HEX, VALS(selfm_foconfig_alt_funccode_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastop_len,
{ "Length", "selfm.fastop.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastop_rb_code,
{ "Remote Bit Operate Code", "selfm.fastop.rb_code", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &selfm_fo_rb_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_fastop_br_code,
{ "Breaker Bit Operate Code", "selfm.fastop.br_code", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &selfm_fo_br_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_fastop_valid,
{ "Operate Code Validation", "selfm.fastop.valid", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_alt_fastop_len,
{ "Length", "selfm.alt_fastop.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_alt_fastop_code,
{ "Operate Code", "selfm.alt_fastop.code", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_alt_fastop_valid,
{ "Operate Code Validation", "selfm.alt_fastop.valid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_len,
{ "Length", "selfm.fastmsg.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_routing_addr,
{ "Routing Address (future)", "selfm.fastmsg.routing_addr", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_status,
{ "Status Byte", "selfm.fastmsg.status", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_funccode,
{ "Function Code", "selfm.fastmsg.funccode", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &selfm_fastmsg_func_code_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_seq,
{ "Sequence Byte", "selfm.fastmsg.seq", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_seq_fir,
{ "FIR", "selfm.fastmsg.seq_fir", FT_BOOLEAN, 8, NULL, FAST_MSG_SEQ_FIR, NULL, HFILL }},
{ &hf_selfm_fastmsg_seq_fin,
{ "FIN", "selfm.fastmsg.seq_fin", FT_BOOLEAN, 8, NULL, FAST_MSG_SEQ_FIN, NULL, HFILL }},
{ &hf_selfm_fastmsg_seq_cnt,
{ "Count", "selfm.fastmsg.seq_cnt", FT_UINT8, BASE_DEC, NULL, FAST_MSG_SEQ_CNT, "Frame Count Number", HFILL }},
{ &hf_selfm_fastmsg_resp_num,
{ "Response Number", "selfm.fastmsg.resp_num", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_crc16,
{ "CRC-16", "selfm.fastmsg.crc16", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_def_route_sup,
{ "Routing Support", "selfm.fastmsg.def_route_sup", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_def_rx_stat,
{ "Status RX", "selfm.fastmsg.def_rx_stat", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_def_tx_stat,
{ "Status TX", "selfm.fastmsg.def_tx_stat", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_def_rx_maxfr,
{ "Max Frames RX", "selfm.fastmsg.def_rx_maxfr", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_def_tx_maxfr,
{ "Max Frames TX", "selfm.fastmsg.def_tx_maxfr", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_def_rx_num_fc,
{ "Number of Supported RX Function Codes", "selfm.fastmsg.def_rx_num_fc", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_def_rx_fc,
{ "Receive Function Code", "selfm.fastmsg.def_rx_fc", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &selfm_fastmsg_func_code_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_def_tx_num_fc,
{ "Number of Supported TX Function Codes", "selfm.fastmsg.def_tx_num_fc", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_def_tx_fc,
{ "Transmit Function Code", "selfm.fastmsg.def_tx_fc", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &selfm_fastmsg_func_code_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_uns_en_fc,
{ "Function Code to Enable", "selfm.fastmsg.uns_en_fc", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &selfm_fastmsg_func_code_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_uns_en_fc_data,
{ "Function Code Data", "selfm.fastmsg.uns_en_fc_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_uns_dis_fc,
{ "Function Code to Disable", "selfm.fastmsg.uns_dis_fc", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &selfm_fastmsg_func_code_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_uns_dis_fc_data,
{ "Function Code Data", "selfm.fastmsg.uns_dis_fc_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_orig,
{ "Origination path", "selfm.fastmsg.unsresp_orig", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_doy,
{ "Day of Year", "selfm.fastmsg.unsresp_doy", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_year,
{ "Year", "selfm.fastmsg.unsresp_year", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_todms,
{ "Time of Day (in ms)", "selfm.fastmsg.unsresp_todms", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_num_elmt,
{ "Number of SER Elements", "selfm.fastmsg.unsresp_num_elmt", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_elmt_idx,
{ "SER Element Index", "selfm.fastmsg.unsresp_elmt_idx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_elmt_ts_ofs,
{ "SER Element Timestamp Offset (us)", "selfm.fastmsg.unsresp_elmt_ts_ofs", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_elmt_status,
{ "SER Element Status", "selfm.fastmsg.unsresp_elmt_status", FT_UINT8, BASE_DEC, VALS(selfm_ser_status_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_eor,
{ "End of Record Indicator", "selfm.fastmsg.unsresp_eor", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_elmt_statword,
{ "SER Element Status Word", "selfm.fastmsg.unsresp_elmt_statword", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unswrite_addr1,
{ "Write Address Region #1", "selfm.fastmsg.unswrite_addr1", FT_UINT16, BASE_HEX | BASE_EXT_STRING, &selfm_fastmsg_unswrite_com_vals_ext, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unswrite_addr2,
{ "Write Address Region #2", "selfm.fastmsg.unswrite_addr2", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unswrite_num_reg,
{ "Number of Registers", "selfm.fastmsg.unswrite_num_reg", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unswrite_reg_val,
{ "Register Value", "selfm.fastmsg.unswrite_reg_val", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_baseaddr,
{ "Base Address", "selfm.fastmsg.baseaddr", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_numwords,
{ "Number of 16-bit Words", "selfm.fastmsg.numwords", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_flags,
{ "Flag Word", "selfm.fastmsg.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_datafmt_resp_numitem,
{ "Number of Data Items Records", "selfm.fastmsg.datafmt_resp_numitem", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_dataitem_qty,
{ "Data Item Quantity", "selfm.fastmsg.dataitem_qty", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_dataitem_type,
{ "Data Item Type", "selfm.fastmsg.dataitem_type", FT_UINT16, BASE_HEX, VALS(selfm_fastmsg_tagtype_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_dataitem_uint16,
{ "(uint16)", "selfm.fastmsg.dataitem_uint16", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_dataitem_int16,
{ "(int16)", "selfm.fastmsg.dataitem_int16", FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_dataitem_uint32,
{ "(uint32)", "selfm.fastmsg.dataitem_uint32", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_dataitem_int32,
{ "(int32)", "selfm.fastmsg.dataitem_int32", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_dataitem_float,
{ "(float)", "selfm.fastmsg.dataitem_float", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_devdesc_num_region,
{ "Number of Data Regions", "selfm.fastmsg.devdesc_num_region", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_devdesc_num_ctrl,
{ "Number of Control Regions", "selfm.fastmsg.devdesc_num_ctrl", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_soe_req_orig,
{ "Origination path", "selfm.fastmsg.soe_req_orig", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_soe_resp_numblks,
{ "Number of Blocks", "selfm.fastmsg.soe_resp_numblks", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_soe_resp_orig,
{ "Origination path", "selfm.fastmsg.soe_resp_orig", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_soe_resp_numbits,
{ "Number of Bits", "selfm.fastmsg.soe_resp_numbits", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_soe_resp_pad,
{ "Pad Byte", "selfm.fastmsg.soe_resp_pad", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_soe_resp_doy,
{ "Day of Year", "selfm.fastmsg.soe_resp_doy", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_soe_resp_year,
{ "Year", "selfm.fastmsg.soe_resp_year", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_soe_resp_tod,
{ "Time of Day (ms)", "selfm.fastmsg.soe_resp_tod", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fragment,
{ "SEL Fast Msg Response Data Fragment", "selfm.respdata.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0, "SEL Fast Message Response Data Fragment", HFILL }},
{ &hf_selfm_fragments,
{ "SEL Fast Msg Response Data Fragments", "selfm.respdata.fragments", FT_NONE, BASE_NONE, NULL, 0x0, "SEL Fast Message Response Data Fragments", HFILL }},
{ &hf_selfm_fragment_overlap,
{ "Fragment overlap", "selfm.respdata.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0, "Fragment overlaps with other fragments", HFILL }},
{ &hf_selfm_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "selfm.respdata.fragment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0, "Overlapping fragments contained conflicting data", HFILL }},
{ &hf_selfm_fragment_multiple_tails,
{ "Multiple tail fragments found", "selfm.respdata.fragment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0, "Several tails were found when defragmenting the packet", HFILL }},
{ &hf_selfm_fragment_too_long_fragment,
{ "Fragment too long", "selfm.respdata.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0, "Fragment contained data past end of packet", HFILL }},
{ &hf_selfm_fragment_error,
{ "Defragmentation error", "selfm.respdata.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0, "Defragmentation error due to illegal fragments", HFILL }},
{ &hf_selfm_fragment_count,
{ "Fragment count", "selfm.respdata.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fragment_reassembled_in,
{ "Reassembled PDU In Frame", "selfm.respdata.fragment.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0, "This PDU is reassembled in this frame", HFILL }},
{ &hf_selfm_fragment_reassembled_length,
{ "Reassembled SEL Fast Msg length", "selfm.respdata.fragment.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0, "The total length of the reassembled payload", HFILL }},
{ &hf_selfm_fmconfig_ai_channel, { "Analog Channel Name", "selfm.fmconfig.ai_channel", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_ai_value16, { "Value (Raw)", "selfm.fmdata.ai.value16", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_ai_scale_factor, { "Value (w/ Scale Factor)", "selfm.fmdata.ai.value_scale_factor", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_ai_value_float, { "Value", "selfm.fmdata.ai.value_float", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_ai_value_double, { "Value", "selfm.fmdata.ai.value_double", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_data_type, { "Data_Type", "selfm.fmdata.data_type", FT_UINT32, BASE_DEC, VALS(selfm_fastmsg_tagtype_vals), 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_quantity, { "Quantity", "selfm.fmdata.quantity", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_ai_value_string, { "Value", "selfm.fmdata.ai.value_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_unsresp_elmt_ts_ofs_decoded, { "SER Element Timestamp Offset (decoded)", "selfm.fastmsg.unsresp_elmt_ts_ofs.decoded", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fid, { "FID", "selfm.fid", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_rid, { "RID", "selfm.rid", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_data_region_name, { "Data Region Name", "selfm.fastmsg.data_region_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_timestamp, { "Timestamp", "selfm.fmdata.timestamp", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fmdata_frame_data_format_reference, { "Frame Data Format Reference", "selfm.fmdata.frame_data_format_reference", FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_selfm_fastmsg_bit_label_name, { "Bit Label Name", "selfm.fastmsg.bit_label_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static ei_register_info selfm_ei[] = {
{ &ei_selfm_crc16_incorrect, { "selfm.crc16.incorrect", PI_CHECKSUM, PI_WARN, "Incorrect CRC", EXPFILL }}
};
static gint *ett[] = {
&ett_selfm,
&ett_selfm_relaydef,
&ett_selfm_relaydef_fm,
&ett_selfm_relaydef_proto,
&ett_selfm_relaydef_flags,
&ett_selfm_fmconfig,
&ett_selfm_fmconfig_ai,
&ett_selfm_fmconfig_calc,
&ett_selfm_foconfig,
&ett_selfm_foconfig_brkr,
&ett_selfm_foconfig_rb,
&ett_selfm_fastop,
&ett_selfm_fmdata,
&ett_selfm_fmdata_ai,
&ett_selfm_fmdata_dig,
&ett_selfm_fmdata_ai_ch,
&ett_selfm_fmdata_dig_ch,
&ett_selfm_fastmsg,
&ett_selfm_fastmsg_seq,
&ett_selfm_fastmsg_def_fc,
&ett_selfm_fastmsg_tag,
&ett_selfm_fastmsg_element_list,
&ett_selfm_fastmsg_element,
&ett_selfm_fastmsg_datareg,
&ett_selfm_fragment,
&ett_selfm_fragments
};
module_t *selfm_module;
expert_module_t* expert_selfm;
register_init_routine(&selfm_init);
register_cleanup_routine(&selfm_cleanup);
proto_selfm = proto_register_protocol("SEL Protocol", "SEL Protocol", "selfm");
new_register_dissector("selfm", dissect_selfm_simple, proto_selfm);
proto_register_field_array(proto_selfm, selfm_hf, array_length(selfm_hf));
proto_register_subtree_array(ett, array_length(ett));
expert_selfm = expert_register_protocol(proto_selfm);
expert_register_field_array(expert_selfm, selfm_ei, array_length(selfm_ei));
selfm_module = prefs_register_protocol(proto_selfm, proto_reg_handoff_selfm);
prefs_register_bool_preference(selfm_module, "desegment",
"Desegment packets spanning multiple TCP segments",
"Whether the SEL Protocol dissector should desegment all messages spanning multiple TCP segments",
&selfm_desegment);
prefs_register_bool_preference(selfm_module, "telnetclean",
"Remove extra 0xFF (Telnet IAC) bytes",
"Whether the SEL Protocol dissector should automatically pre-process Telnet data to remove duplicate 0xFF IAC bytes",
&selfm_telnet_clean);
prefs_register_uint_preference(selfm_module, "tcp.port", "SEL Protocol Port",
"Set the TCP port for SEL FM Protocol packets (if other than the default of 0)",
10, &global_selfm_tcp_port);
prefs_register_bool_preference(selfm_module, "crc_verification", "Validate Fast Message CRC16",
"Perform CRC16 validation on Fast Messages",
&selfm_crc16);
prefs_register_string_preference(selfm_module, "ser_list",
"SER Index List", "List of word bits contained in SER equations (Comma-separated, no Quotes or Checksums)", &selfm_ser_list);
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
dissector_add_for_decode_as("rtacser.data", selfm_handle);
}
