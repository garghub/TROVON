static void
dissect_mmc4_getconfiguration (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset,
gboolean isreq, gboolean iscdb,
guint payload_len _U_,
scsi_task_data_t *cdata _U_)
{
gint32 len;
guint old_offset;
tvbuff_t *volatile tvb_v = tvb;
volatile guint offset_v = offset;
if (tree && isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_mmc_getconf_rt, tvb_v, offset_v+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_getconf_starting_feature, tvb_v, offset_v+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_alloclen16, tvb_v, offset_v+6, 2, ENC_BIG_ENDIAN);
if(cdata){
cdata->itlq->alloc_len=tvb_get_ntohs(tvb_v, offset_v+6);
}
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
if(!isreq) {
if(!cdata){
return;
}
TRY_SCSI_CDB_ALLOC_LEN(pinfo, tvb_v, offset_v, cdata->itlq->alloc_len);
len=tvb_get_ntohl(tvb_v, offset_v+0);
proto_tree_add_item (tree, hf_scsi_mmc_data_length, tvb_v, offset_v, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_getconf_current_profile, tvb_v, offset_v+6, 2, ENC_BIG_ENDIAN);
offset_v+=8;
len-=4;
while(len>0){
guint16 feature;
guint8 additional_length;
guint8 num_linksize;
feature=tvb_get_ntohs(tvb_v, offset_v);
proto_tree_add_item (tree, hf_scsi_mmc_feature, tvb_v, offset_v, 2, ENC_BIG_ENDIAN);
offset_v+=2;
proto_tree_add_item (tree, hf_scsi_mmc_feature_version, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_persistent, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_current, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
offset_v+=1;
additional_length=tvb_get_guint8(tvb_v, offset_v);
proto_tree_add_item (tree, hf_scsi_mmc_feature_additional_length, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
offset_v+=1;
old_offset=offset_v;
switch(feature){
case 0x0000:
while(offset_v<(old_offset+additional_length)){
proto_item *it=NULL;
proto_tree *tr=NULL;
guint16 profile;
guint8 cur_profile;
if(tree){
it=proto_tree_add_text(tree, tvb_v, offset_v, 4, "Profile:");
tr=proto_item_add_subtree(it, ett_scsi_mmc_profile);
}
profile=tvb_get_ntohs(tvb_v, offset_v);
proto_tree_add_item (tr, hf_scsi_mmc_feature_profile, tvb_v, offset_v, 2, ENC_BIG_ENDIAN);
proto_item_append_text(it, "%s", val_to_str(profile, scsi_getconf_current_profile_val, "Unknown 0x%04x"));
cur_profile=tvb_get_guint8(tvb_v, offset_v+2);
proto_tree_add_item (tr, hf_scsi_mmc_feature_profile_current, tvb_v, offset_v+2, 1, ENC_BIG_ENDIAN);
if(cur_profile&0x01){
proto_item_append_text(it, " [CURRENT PROFILE]");
}
offset_v+=4;
}
break;
case 0x001d:
case 0x001f:
break;
case 0x001e:
proto_tree_add_item (tree, hf_scsi_mmc_feature_cdread_dap, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_cdread_c2flag, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_cdread_cdtext, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
break;
case 0x0021:
proto_tree_add_item (tree, hf_scsi_mmc_feature_dts, tvb_v, offset_v, 2, ENC_BIG_ENDIAN);
offset_v+=2;
proto_tree_add_item (tree, hf_scsi_mmc_feature_isw_buf, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
offset_v+=1;
num_linksize=tvb_get_guint8(tvb_v, offset_v);
proto_tree_add_item (tree, hf_scsi_mmc_feature_isw_num_linksize, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
offset_v+=1;
while(num_linksize--){
proto_tree_add_item (tree, hf_scsi_mmc_feature_isw_linksize, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
offset_v+=1;
}
break;
case 0x002a:
proto_tree_add_item (tree, hf_scsi_mmc_feature_dvdrw_write, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_dvdrw_quickstart, tvb_v, offset_v, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_dvdrw_closeonly, tvb_v, offset_v, 2, ENC_BIG_ENDIAN);
break;
case 0x002b:
proto_tree_add_item (tree, hf_scsi_mmc_feature_dvdr_write, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
break;
case 0x002d:
proto_tree_add_item (tree, hf_scsi_mmc_feature_tao_buf, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_tao_rwraw, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_tao_rwpack, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_tao_testwrite, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_tao_cdrw, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_tao_rwsubcode, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_dts, tvb_v, offset_v+2, 2, ENC_BIG_ENDIAN);
break;
case 0x002e:
proto_tree_add_item (tree, hf_scsi_mmc_feature_sao_buf, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_sao_sao, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_sao_rawms, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_sao_raw, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_sao_testwrite, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_sao_cdrw, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_sao_rw, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_sao_mcsl, tvb_v, offset_v+1, 3, ENC_BIG_ENDIAN);
break;
case 0x002f:
proto_tree_add_item (tree, hf_scsi_mmc_feature_dvdr_buf, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_dvdr_testwrite, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_feature_dvdr_dvdrw, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
break;
case 0x0108:
proto_tree_add_item (tree, hf_scsi_mmc_feature_lun_sn, tvb_v, offset_v, additional_length, ENC_ASCII|ENC_NA);
break;
default:
proto_tree_add_text (tree, tvb_v, offset_v, additional_length,
"SCSI/MMC Unknown Feature data");
break;
}
offset_v=old_offset+additional_length;
len-=4+additional_length;
}
END_TRY_SCSI_CDB_ALLOC_LEN;
}
}
static void
dissect_mmc4_readtocpmaatip (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 format;
gint16 len;
if (tree && isreq && iscdb) {
format=tvb_get_guint8(tvb, offset+1)&0x0f;
cdata->itlq->flags=format;
switch(format){
case 0x00:
case 0x01:
proto_tree_add_item (tree, hf_scsi_mmc_readtoc_time, tvb, offset, 1, ENC_BIG_ENDIAN);
if(tvb_get_guint8(tvb, offset)&0x02){
cdata->itlq->flags|=0x0100;
}
break;
}
proto_tree_add_item (tree, hf_scsi_mmc_readtoc_format, tvb, offset+1, 1, ENC_BIG_ENDIAN);
switch(format){
case 0x00:
proto_tree_add_item (tree, hf_scsi_mmc_track, tvb, offset+5, 1, ENC_BIG_ENDIAN);
cdata->itlq->flags|=0x0200;
break;
case 0x02:
proto_tree_add_item (tree, hf_scsi_mmc_session, tvb, offset+5, 1, ENC_BIG_ENDIAN);
cdata->itlq->flags|=0x0400;
break;
}
proto_tree_add_item (tree, hf_scsi_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
if(tree && (!isreq)) {
len=tvb_get_ntohs(tvb, offset);
proto_tree_add_item (tree, hf_scsi_mmc_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cdata->itlq->flags&0x0200){
proto_tree_add_item (tree, hf_scsi_mmc_first_track, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_readtoc_last_track, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
if(cdata->itlq->flags&0x0400){
proto_tree_add_item (tree, hf_scsi_mmc_readtoc_first_session, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_readtoc_last_session, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
offset+=4;
len-=2;
switch(cdata->itlq->flags&0x000f){
case 0x0:
while(len>0){
proto_tree_add_item (tree, hf_scsi_mmc_q_subchannel_adr, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_q_subchannel_control, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_track, tvb, offset+2, 1, ENC_BIG_ENDIAN);
if(cdata->itlq->flags&0x0100){
proto_tree_add_item (tree, hf_scsi_mmc_track_start_time, tvb, offset+4, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item (tree, hf_scsi_mmc_track_start_address, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
offset+=8;
len-=8;
}
break;
default:
proto_tree_add_text (tree, tvb, offset, len,
"SCSI/MMC Unknown READ TOC Format:0x%04x",cdata->itlq->flags&0x000f);
break;
}
}
}
static void
dissect_mmc4_readdiscinformation (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (tree && isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
if(tree && (!isreq)) {
proto_tree_add_item (tree, hf_scsi_mmc_data_length, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_erasable, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_state_of_last_session, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_disk_status, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_first_track, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint (tree, hf_scsi_mmc_disc_info_number_of_sessions, tvb, 4, 1, (tvb_get_guint8(tvb, offset+9)<<8)|tvb_get_guint8(tvb, offset+4));
proto_tree_add_uint (tree, hf_scsi_mmc_disc_info_first_track_in_last_session, tvb, 5, 1, (tvb_get_guint8(tvb, offset+10)<<8)|tvb_get_guint8(tvb, offset+5));
proto_tree_add_uint (tree, hf_scsi_mmc_disc_info_last_track_in_last_session, tvb, 6, 1, (tvb_get_guint8(tvb, offset+11)<<8)|tvb_get_guint8(tvb, offset+6));
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_did_v, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_dbc_v, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_uru, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_dac_v, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_dbit, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_bgfs, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_disc_type, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_disc_identification, tvb, offset+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_last_session_lead_in_start_address, tvb, offset+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_last_possible_lead_out_start_address, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_info_disc_bar_code, tvb, offset+24, 8, ENC_BIG_ENDIAN);
}
}
static void
dissect_mmc4_readdiscstructure (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata)
{
guint8 flags;
if (tree && isreq && iscdb) {
proto_tree_add_text (tree, tvb, offset+1, 4,
"Address: %u",
tvb_get_ntohl (tvb, offset+1));
proto_tree_add_text (tree, tvb, offset+5, 1,
"Layer Number: %u",
tvb_get_guint8 (tvb, offset+5));
cdata->itlq->flags=tvb_get_guint8 (tvb, offset+6);
proto_tree_add_uint (tree, hf_scsi_mmc_read_dvd_format, tvb, offset+6, 1, cdata->itlq->flags);
proto_tree_add_item (tree, hf_scsi_alloclen16, tvb, offset+7, 2, ENC_BIG_ENDIAN);
flags = tvb_get_guint8 (tvb, offset+9);
proto_tree_add_text (tree, tvb, offset+9, 1,
"AGID: %u",
flags & 0xc0);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
if(tree && (!isreq)) {
proto_item *ti;
ti = proto_tree_add_uint (tree, hf_scsi_mmc_read_dvd_format, tvb, 0, 0, cdata->itlq->flags);
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item (tree, hf_scsi_mmc_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 4;
switch(cdata->itlq->flags) {
case 0x00:
case 0x11:
proto_tree_add_item (tree, hf_scsi_mmc_disc_book_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_book_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_size_size, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_size_rate, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_num_layers, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_track_path, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_structure_layer, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_density_length, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_density_pitch, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_first_physical, tvb, offset+5, 3, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_last_physical, tvb, offset+9, 3, ENC_BIG_ENDIAN);
if (cdata->itlq->flags == 0x00) {
proto_tree_add_item (tree, hf_scsi_mmc_disc_last_physical_layer0, tvb, offset+13, 3, ENC_BIG_ENDIAN);
}
proto_tree_add_item (tree, hf_scsi_mmc_disc_extended_format_info, tvb, offset+16, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_disc_application_code, tvb, offset+17, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_adip_eib5, tvb, offset+18, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_adip_eib4, tvb, offset+18, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_adip_eib3, tvb, offset+18, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_adip_eib2, tvb, offset+18, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_adip_eib1, tvb, offset+18, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_adip_eib0, tvb, offset+18, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_adip_device_manuf_id, tvb, offset+19, 8, ENC_ASCII|ENC_NA);
proto_tree_add_item (tree, hf_scsi_mmc_adip_media_type_id, tvb, offset+27, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item (tree, hf_scsi_mmc_adip_product_revision_number, tvb, offset+30, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_adip_number_of_physical_info, tvb, offset+31, 1, ENC_BIG_ENDIAN);
break;
default:
ti = proto_tree_add_text (tree, tvb, 0, 0,
"SCSI/MMC Unknown Read DVD Format:0x%02x",
cdata->itlq->flags);
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
static void
dissect_mmc4_getperformance (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 flags;
if (tree && isreq && iscdb) {
flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"Data Type: %u",
flags & 0x1f);
proto_tree_add_text (tree, tvb, offset+1, 4,
"Starting LBA: %u",
tvb_get_ntohl (tvb, offset+1));
proto_tree_add_text (tree, tvb, offset+7, 2,
"Maximum Number of Descriptors: %u",
tvb_get_ntohs (tvb, offset+7));
flags = tvb_get_guint8 (tvb, offset+9);
proto_tree_add_text (tree, tvb, offset+9, 1,
"Type: %u",
flags);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_mmc4_synchronizecache (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (tree && isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_mmc_synccache_immed, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_synccache_reladr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_num_blocks, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_mmc4_reportkey (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 agid, key_format, key_class;
proto_item *ti;
if (tree && isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_mmc_lba, tvb, offset+1,
4, ENC_BIG_ENDIAN);
key_class=tvb_get_guint8(tvb, offset+6);
proto_tree_add_item (tree, hf_scsi_mmc_key_class, tvb, offset+6,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_alloclen16, tvb, offset+7, 2, ENC_BIG_ENDIAN);
agid=tvb_get_guint8(tvb, offset+9)&0xc0;
key_format=tvb_get_guint8(tvb, offset+9)&0x3f;
switch(key_format){
case 0x01:
case 0x02:
case 0x04:
case 0x3f:
proto_tree_add_uint (tree, hf_scsi_mmc_agid, tvb, offset+9, 1, agid);
break;
}
proto_tree_add_uint (tree, hf_scsi_mmc_key_format, tvb, offset+9, 1, key_format);
cdata->itlq->flags=(key_format<<8)|key_class;
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
if(tree && (!isreq)) {
switch(cdata->itlq->flags){
case 0x0800:
proto_tree_add_item (tree, hf_scsi_mmc_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_report_key_type_code, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_report_key_vendor_resets, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_report_key_user_changes, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_report_key_region_mask, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_report_key_rpc_scheme, tvb, offset+6, 1, ENC_BIG_ENDIAN);
break;
default:
ti = proto_tree_add_text (tree, tvb, 0, 0,
"SCSI/MMC Unknown Format:0x%02x/Class:0x%02x combination",
cdata->itlq->flags>>8,cdata->itlq->flags&0xff);
PROTO_ITEM_SET_GENERATED(ti);
break;
}
}
}
static void
dissect_mmc4_readtrackinformation (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 addresstype;
if (tree && isreq && iscdb) {
addresstype=tvb_get_guint8(tvb, offset)&0x03;
proto_tree_add_item (tree, hf_scsi_mmc_rti_address_type, tvb, offset+0, 1, ENC_BIG_ENDIAN);
switch(addresstype){
case 0x00:
proto_tree_add_item (tree, hf_scsi_mmc_lba, tvb, offset+1,
4, ENC_BIG_ENDIAN);
break;
case 0x01:
proto_tree_add_item (tree, hf_scsi_mmc_track, tvb, offset+1,
4, ENC_BIG_ENDIAN);
break;
case 0x02:
proto_tree_add_item (tree, hf_scsi_mmc_session, tvb, offset+1,
4, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item (tree, hf_scsi_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
if(tree && (!isreq)) {
proto_tree_add_item (tree, hf_scsi_mmc_data_length, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint (tree, hf_scsi_mmc_track, tvb, 2, 1, (tvb_get_guint8(tvb, offset+32)<<8)|tvb_get_guint8(tvb, offset+2));
proto_tree_add_uint (tree, hf_scsi_mmc_session, tvb, 3, 1, (tvb_get_guint8(tvb, offset+33)<<8)|tvb_get_guint8(tvb, offset+3));
proto_tree_add_item (tree, hf_scsi_mmc_rti_damage, tvb, 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rti_copy, tvb, 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rti_track_mode, tvb, 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rti_rt, tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rti_blank, tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rti_packet, tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rti_fp, tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rti_data_mode, tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rti_lra_v, tvb, 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rti_nwa_v, tvb, 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_track_start_address, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_next_writable_address, tvb, offset+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_free_blocks, tvb, offset+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_fixed_packet_size, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_track_size, tvb, offset+24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_last_recorded_address, tvb, offset+28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_read_compatibility_lba, tvb, offset+36, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_mmc4_geteventstatusnotification (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 flags;
if (tree && isreq && iscdb) {
flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"Polled: %u",
flags & 0x01);
flags = tvb_get_guint8 (tvb, offset+3);
proto_tree_add_text (tree, tvb, offset+3, 1,
"Notification Class Request: %u",
flags);
proto_tree_add_item (tree, hf_scsi_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_mmc4_reservetrack (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (tree && isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_mmc_reservation_size, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_mmc4_close_track (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (tree && isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_mmc_closetrack_immed, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_scsi_mmc_closetrack_func, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset++;
proto_tree_add_item (tree, hf_scsi_mmc_track, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
offset+=3;
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_mmc4_readbuffercapacity (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (tree && isreq && iscdb) {
cdata->itlq->flags=0;
proto_tree_add_item (tree, hf_scsi_mmc_rbc_block, tvb, offset, 1, ENC_BIG_ENDIAN);
if(tvb_get_guint8(tvb, offset)&0x01){
cdata->itlq->flags=1;
}
proto_tree_add_item (tree, hf_scsi_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
if(tree && (!isreq)) {
proto_tree_add_item (tree, hf_scsi_mmc_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cdata->itlq->flags){
proto_tree_add_item (tree, hf_scsi_mmc_rbc_lob_blocks, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rbc_alob_blocks, tvb, offset+8, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item (tree, hf_scsi_mmc_rbc_lob_bytes, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_rbc_alob_bytes, tvb, offset+8, 4, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_mmc4_setcdspeed (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (tree && isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_mmc_setcdspeed_rc, tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_text (tree, tvb, offset+1, 2,
"Logical Unit Read Speed(bytes/sec): %u",
tvb_get_ntohs (tvb, offset+1));
proto_tree_add_text (tree, tvb, offset+3, 2,
"Logical Unit Write Speed(bytes/sec): %u",
tvb_get_ntohs (tvb, offset+3));
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_mmc4_setstreaming (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 type;
proto_item *ti;
if (tree && isreq && iscdb) {
type=tvb_get_guint8(tvb, offset+7);
cdata->itlq->flags=type;
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_type, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_param_len, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
if(tree && isreq && (!iscdb)) {
switch(cdata->itlq->flags){
case 0x00:
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_wrc, tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_rdd, tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_exact, tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_ra, tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_start_lba, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_end_lba, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_read_size, tvb, offset+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_read_time, tvb, offset+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_write_size, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_mmc_setstreaming_write_time, tvb, offset+24, 4, ENC_BIG_ENDIAN);
break;
default:
ti = proto_tree_add_text (tree, tvb, 0, 0,
"SCSI/MMC Unknown SetStreaming Type:0x%02x",cdata->itlq->flags);
PROTO_ITEM_SET_GENERATED(ti);
break;
}
}
}
void
proto_register_scsi_mmc(void)
{
static hf_register_info hf[] = {
{ &hf_scsi_mmc_opcode,
{"MMC Opcode", "scsi.mmc.opcode", FT_UINT8, BASE_HEX,
VALS (scsi_mmc_vals), 0x0, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_type,
{"Type", "scsi.mmc.setstreaming.type", FT_UINT8, BASE_DEC,
VALS(scsi_setstreaming_type_val), 0, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_param_len,
{"Parameter Length", "scsi.mmc.setstreaming.param_len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_wrc,
{"WRC", "scsi.mmc.setstreaming.wrc", FT_UINT8, BASE_HEX,
NULL, 0x18, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_rdd,
{"RDD", "scsi.mmc.setstreaming.rdd", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_exact,
{"Exact", "scsi.mmc.setstreaming.exact", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_ra,
{"RA", "scsi.mmc.setstreaming.ra", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_start_lba,
{"Start LBA", "scsi.mmc.setstreaming.start_lbs", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_end_lba,
{"End LBA", "scsi.mmc.setstreaming.end_lba", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_read_size,
{"Read Size", "scsi.mmc.setstreaming.read_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_read_time,
{"Read Time", "scsi.mmc.setstreaming.read_time", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_write_size,
{"Write Size", "scsi.mmc.setstreaming.write_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_setstreaming_write_time,
{"Write Time", "scsi.mmc.setstreaming.write_time", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_setcdspeed_rc,
{"Rotational Control", "scsi.mmc.setcdspeed.rc", FT_UINT8, BASE_HEX,
VALS(scsi_setcdspeed_rc_val), 0x03, NULL, HFILL}},
{ &hf_scsi_mmc_rbc_block,
{"BLOCK", "scsi.mmc.rbc.block", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_rbc_lob_blocks,
{"Buffer Len (blocks)", "scsi.mmc.rbc.lob_blocks", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_rbc_alob_blocks,
{"Available Buffer Len (blocks)", "scsi.mmc.rbc.alob_blocks", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_rbc_lob_bytes,
{"Buffer Len (bytes)", "scsi.mmc.rbc.lob_bytes", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_rbc_alob_bytes,
{"Available Buffer Len (bytes)", "scsi.mmc.rbc.alob_bytes", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_rti_address_type,
{"Address Type", "scsi.mmc.rti.address_type", FT_UINT8, BASE_HEX,
VALS(scsi_rti_address_type_val), 0x03, NULL, HFILL}},
{ &hf_scsi_mmc_rti_damage,
{"Damage", "scsi.mmc.rti.damage", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL}},
{ &hf_scsi_mmc_rti_copy,
{"Copy", "scsi.mmc.rti.copy", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{ &hf_scsi_mmc_rti_track_mode,
{"Track Mode", "scsi.mmc.rti.track_mode", FT_UINT8, BASE_HEX,
NULL, 0x0f, NULL, HFILL}},
{ &hf_scsi_mmc_rti_rt,
{"RT", "scsi.mmc.rti.rt", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{ &hf_scsi_mmc_rti_blank,
{"Blank", "scsi.mmc.rti.blank", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{ &hf_scsi_mmc_rti_packet,
{"Packet/Inc", "scsi.mmc.rti.packet", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL}},
{ &hf_scsi_mmc_rti_fp,
{"FP", "scsi.mmc.rti.fp", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{ &hf_scsi_mmc_rti_data_mode,
{"Data Mode", "scsi.mmc.rti.data_mode", FT_UINT8, BASE_HEX,
NULL, 0x0f, NULL, HFILL}},
{ &hf_scsi_mmc_rti_lra_v,
{"LRA_V", "scsi.mmc.rti.lra_v", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_rti_nwa_v,
{"NWA_V", "scsi.mmc.rti.nwa_v", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_report_key_type_code,
{"Type Code", "scsi.mmc.report_key.type_code", FT_UINT8, BASE_HEX,
VALS(scsi_report_key_type_code_val), 0xc0, NULL, HFILL}},
{ &hf_scsi_mmc_report_key_vendor_resets,
{"Vendor Resets", "scsi.mmc.report_key.vendor_resets", FT_UINT8, BASE_HEX,
NULL, 0x38, NULL, HFILL}},
{ &hf_scsi_mmc_report_key_user_changes,
{"User Changes", "scsi.mmc.report_key.user_changes", FT_UINT8, BASE_HEX,
NULL, 0x07, NULL, HFILL}},
{ &hf_scsi_mmc_report_key_region_mask,
{"Region Mask", "scsi.mmc.report_key.region_mask", FT_UINT8, BASE_HEX,
NULL, 0xff, NULL, HFILL}},
{ &hf_scsi_mmc_report_key_rpc_scheme,
{"RPC Scheme", "scsi.mmc.report_key.rpc_scheme", FT_UINT8, BASE_HEX,
VALS(scsi_report_key_rpc_scheme_val), 0, NULL, HFILL}},
{ &hf_scsi_mmc_key_class,
{"Key Class", "scsi.mmc.key_class", FT_UINT8, BASE_HEX,
VALS (scsi_key_class_val), 0x00, NULL, HFILL}},
{ &hf_scsi_mmc_key_format,
{"Key Format", "scsi.mmc.key_format", FT_UINT8, BASE_HEX,
VALS (scsi_key_format_val), 0x3f, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_erasable,
{"Erasable", "scsi.mmc.disc_info.erasable", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_state_of_last_session,
{"State Of Last Session", "scsi.mmc.disc_info.state_of_last_session", FT_UINT8, BASE_HEX,
VALS(scsi_disc_info_sols_val), 0x0c, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_disk_status,
{"Disk Status", "scsi.mmc.disc_info.disk_status", FT_UINT8, BASE_HEX,
VALS(scsi_disc_info_disc_status_val), 0x03, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_number_of_sessions,
{"Number Of Sessions", "scsi.mmc.disc_info.number_of_sessions", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_first_track_in_last_session,
{"First Track In Last Session", "scsi.mmc.disc_info.first_track_in_last_session", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_last_track_in_last_session,
{"Last Track In Last Session", "scsi.mmc.disc_info.last_track_in_last_session", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_did_v,
{"DID_V", "scsi.mmc.disc_info.did_v", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_dbc_v,
{"DBC_V", "scsi.mmc.disc_info.dbc_v", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_uru,
{"URU", "scsi.mmc.disc_info.uru", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_dac_v,
{"DAC_V", "scsi.mmc.disc_info.dac_v", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_dbit,
{"Dbit", "scsi.mmc.disc_info.dbit", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_bgfs,
{"BG Format Status", "scsi.mmc.disc_info.bgfs", FT_UINT8, BASE_HEX,
VALS(scsi_disc_info_bgfs_val), 0x03, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_disc_type,
{"Disc Type", "scsi.mmc.disc_info.disc_type", FT_UINT8, BASE_HEX,
VALS(scsi_disc_info_disc_type_val), 0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_disc_identification,
{"Disc Identification", "scsi.mmc.disc_info.disc_identification", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_last_session_lead_in_start_address,
{"Last Session Lead-In Start Address", "scsi.mmc.disc_info.last_session_lead_in_start_address", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_last_possible_lead_out_start_address,
{"Last Possible Lead-Out Start Address", "scsi.mmc.disc_info.last_possible_lead_out_start_address", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_info_disc_bar_code,
{"Disc Bar Code", "scsi.mmc.disc_info.disc_bar_code", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_readtoc_time,
{"Time", "scsi.mmc.readtoc.time", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_readtoc_format,
{"Format", "scsi.mmc.readtoc.format", FT_UINT8, BASE_HEX,
NULL, 0x0f, NULL, HFILL}},
{ &hf_scsi_mmc_readtoc_first_session,
{"First Session", "scsi.mmc.readtoc.first_session", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_readtoc_last_track,
{"Last Track", "scsi.mmc.readtoc.last_track", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_readtoc_last_session,
{"Last Session", "scsi.mmc.readtoc.last_session", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_q_subchannel_adr,
{"Q Subchannel ADR", "scsi.mmc.q.subchannel.adr", FT_UINT8, BASE_HEX,
VALS(scsi_q_subchannel_adr_val), 0xf0, NULL, HFILL}},
{ &hf_scsi_mmc_q_subchannel_control,
{"Q Subchannel Control", "scsi.mmc.q.subchannel.control", FT_UINT8, BASE_HEX,
VALS(scsi_q_subchannel_control_val), 0x0f, NULL, HFILL}},
{ &hf_scsi_mmc_agid,
{"AGID", "scsi.mmc.agid", FT_UINT8, BASE_HEX,
NULL, 0xc0, NULL, HFILL}},
{ &hf_scsi_mmc_track,
{"Track", "scsi.mmc.track", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_track_size,
{"Track Size", "scsi.mmc.track_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_track_start_address,
{"Track Start Address", "scsi.mmc.track_start_address", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_track_start_time,
{"Track Start Time", "scsi.mmc.track_start_time", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_lba,
{"Logical Block Address", "scsi.mmc.lba", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_mmc_session,
{"Session", "scsi.mmc.session", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_data_length,
{"Data Length", "scsi.mmc.data_length", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_mmc_getconf_rt,
{"RT", "scsi.mmc.getconf.rt", FT_UINT8, BASE_HEX,
VALS(scsi_getconf_rt_val), 0x03, NULL, HFILL}},
{ &hf_scsi_mmc_getconf_current_profile,
{"Current Profile", "scsi.mmc.getconf.current_profile", FT_UINT16, BASE_HEX,
VALS(scsi_getconf_current_profile_val), 0, NULL, HFILL}},
{ &hf_scsi_mmc_getconf_starting_feature,
{"Starting Feature", "scsi.mmc.getconf.starting_feature", FT_UINT16, BASE_HEX,
VALS(scsi_feature_val), 0, NULL, HFILL}},
{ &hf_scsi_mmc_feature,
{"Feature", "scsi.mmc.feature", FT_UINT16, BASE_HEX,
VALS(scsi_feature_val), 0, NULL, HFILL}},
{ &hf_scsi_mmc_feature_version,
{"Version", "scsi.mmc.feature.version", FT_UINT8, BASE_DEC,
NULL, 0x3c, NULL, HFILL}},
{ &hf_scsi_mmc_feature_persistent,
{"Persistent", "scsi.mmc.feature.persistent", FT_UINT8, BASE_HEX,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_feature_current,
{"Current", "scsi.mmc.feature.current", FT_UINT8, BASE_HEX,
NULL, 001, NULL, HFILL}},
{ &hf_scsi_mmc_feature_additional_length,
{"Additional Length", "scsi.mmc.feature.additional_length", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_feature_lun_sn,
{"LUN Serial Number", "scsi.mmc.feature.lun_sn", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_feature_cdread_dap,
{"DAP", "scsi.mmc.feature.cdread.dap", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{ &hf_scsi_mmc_feature_cdread_c2flag,
{"C2 Flag", "scsi.mmc.feature.cdread.c2flag", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_feature_cdread_cdtext,
{"CD-Text", "scsi.mmc.feature.cdread.cdtext", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_feature_dvdrw_write,
{"Write", "scsi.mmc.feature.dvdrw.write", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_feature_dvdrw_quickstart,
{"Quick Start", "scsi.mmc.feature.dvdrw.quickstart", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_feature_dvdrw_closeonly,
{"Close Only", "scsi.mmc.feature.dvdrw.closeonly", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_feature_dvdr_write,
{"Write", "scsi.mmc.feature.dvdr.write", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_feature_tao_buf,
{"BUF", "scsi.mmc.feature.tao.buf", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{ &hf_scsi_mmc_feature_tao_rwraw,
{"R-W Raw", "scsi.mmc.feature.tao.rwraw", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{ &hf_scsi_mmc_feature_tao_rwpack,
{"R-W Pack", "scsi.mmc.feature.tao.rwpack", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{ &hf_scsi_mmc_feature_tao_testwrite,
{"Test Write", "scsi.mmc.feature.tao.testwrite", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_mmc_feature_tao_cdrw,
{"CD-RW", "scsi.mmc.feature.tao.cdrw", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_feature_tao_rwsubcode,
{"R-W Subcode", "scsi.mmc.feature.tao.rwsubcode", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_feature_dts,
{"Data Type Supported", "scsi.mmc.feature.dts", FT_UINT16, BASE_HEX,
NULL, 0xffff, NULL, HFILL}},
{ &hf_scsi_mmc_feature_sao_buf,
{"BUF", "scsi.mmc.feature.sao.buf", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{ &hf_scsi_mmc_feature_sao_sao,
{"SAO", "scsi.mmc.feature.sao.sao", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL}},
{ &hf_scsi_mmc_feature_sao_rawms,
{"Raw MS", "scsi.mmc.feature.sao.rawms", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{ &hf_scsi_mmc_feature_sao_raw,
{"Raw", "scsi.mmc.feature.sao.raw", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{ &hf_scsi_mmc_feature_sao_testwrite,
{"Test Write", "scsi.mmc.feature.sao.testwrite", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_mmc_feature_sao_cdrw,
{"CD-RW", "scsi.mmc.feature.sao.cdrw", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_feature_sao_rw,
{"R-W", "scsi.mmc.feature.sao.rw", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_feature_sao_mcsl,
{"Maximum Cue Sheet Length", "scsi.mmc.feature.sao.mcsl", FT_UINT24, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_feature_dvdr_buf,
{"BUF", "scsi.mmc.feature.dvdr.buf", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{ &hf_scsi_mmc_feature_dvdr_testwrite,
{"Test Write", "scsi.mmc.feature.dvdr.testwrite", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_mmc_feature_dvdr_dvdrw,
{"DVD-RW", "scsi.mmc.feature.dvdr.dvdrw", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_feature_profile,
{"Profile", "scsi.mmc.feature.profile", FT_UINT16, BASE_HEX,
VALS(scsi_getconf_current_profile_val), 0, NULL, HFILL}},
{ &hf_scsi_mmc_feature_profile_current,
{"Current", "scsi.mmc.feature.profile.current", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_feature_isw_buf,
{"BUF", "scsi.mmc.feature.isw.buf", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_feature_isw_num_linksize,
{"Number of Link Sizes", "scsi.mmc.feature.isw.num_linksize", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_feature_isw_linksize,
{"Link Size", "scsi.mmc.feature.isw.linksize", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_read_compatibility_lba,
{"Read Compatibility LBA", "scsi.mmc.read_compatibility_lba", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_reservation_size,
{"Reservation Size", "scsi.mmc.reservation_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_last_recorded_address,
{"Last Recorded Address", "scsi.mmc.last_recorded_address", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_first_track,
{"First Track", "scsi.mmc.first_track", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_fixed_packet_size,
{"Fixed Packet Size", "scsi.mmc.fixed_packet_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_closetrack_immed,
{"IMMED", "scsi.mmc.closetrack.immed", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_closetrack_func,
{"Close Function", "scsi.mmc.closetrack.func", FT_UINT8, BASE_HEX,
VALS(scsi_closetrack_func_val), 0x07, NULL, HFILL}},
{ &hf_scsi_mmc_synccache_immed,
{"IMMED", "scsi.mmc.synccache.immed", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_synccache_reladr,
{"RelAdr", "scsi.mmc.synccache.reladr", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_num_blocks,
{"Number of Blocks", "scsi.mmc.num_blocks", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_mmc_next_writable_address,
{"Next Writable Address", "scsi.mmc.next_writable_address", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_free_blocks,
{"Free Blocks", "scsi.mmc.free_blocks", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_read_dvd_format,
{ "Format Code", "scsi.mmc.read_dvd.format", FT_UINT8, BASE_HEX,
VALS(scsi_read_dvd_formats), 0x0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_book_type,
{ "Type", "scsi.mmc.book.type", FT_UINT8, BASE_HEX,
VALS(scsi_disc_category_type), 0xf0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_book_version,
{ "Version", "scsi.mmc.book.version", FT_UINT8, BASE_HEX,
NULL, 0x0f, NULL, HFILL}},
{ &hf_scsi_mmc_disc_size_size,
{ "Size", "scsi.mmc.disc.size", FT_UINT8, BASE_HEX,
VALS(scsi_disc_size), 0xf0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_size_rate,
{ "Rate", "scsi.mmc.disc.rate", FT_UINT8, BASE_HEX,
VALS(scsi_disc_rate), 0x0f, NULL, HFILL}},
{ &hf_scsi_mmc_disc_structure_layer,
{ "Structure", "scsi.mmc.disc.structure", FT_UINT8, BASE_HEX,
VALS(scsi_disc_structure), 0x0f, NULL, HFILL}},
{ &hf_scsi_mmc_disc_density_length,
{ "Channel bith length", "scsi.mmc.density.channel_bit_length", FT_UINT8, BASE_HEX,
VALS(scsi_density_length), 0xf0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_density_pitch,
{ "Average Track Pitch", "scsi.mmc.density.average_track_pitch", FT_UINT8, BASE_HEX,
VALS(scsi_density_pitch), 0x0f, NULL, HFILL}},
{ &hf_scsi_mmc_disc_first_physical,
{ "First physical sector of data zone", "scsi.mmc.first_physical", FT_UINT24, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_last_physical,
{ "Last physical sector of data zone", "scsi.mmc.last_physical", FT_UINT24, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_last_physical_layer0,
{ "Last physical sector of layer 0", "scsi.mmc.last_physical_layer0", FT_UINT24, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_extended_format_info,
{ "Extended Format Info", "scsi.mmc.adip.extended_format_info", FT_BOOLEAN, 8,
TFS(&scsi_adip_extended_format_info), 0x40, NULL, HFILL}},
{ &hf_scsi_mmc_disc_application_code,
{ "Disk Application Code", "scsi.mmc.disk_application_code", FT_UINT8, BASE_HEX,
VALS(scsi_disk_application_code), 0x0, NULL, HFILL}},
{ &hf_scsi_mmc_adip_eib0,
{ "Extended Format Block 0", "scsi.mmc.adip.extended_format_block.0", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_mmc_adip_eib1,
{ "Extended Format Block 1", "scsi.mmc.adip.extended_format_block.1", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_mmc_adip_eib2,
{ "Extended Format Block 2", "scsi.mmc.adip.extended_format_block.2", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_mmc_adip_eib3,
{ "Extended Format Block 3", "scsi.mmc.adip.extended_format_block.3", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{ &hf_scsi_mmc_adip_eib4,
{ "Extended Format Block 4", "scsi.mmc.adip.extended_format_block.4", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{ &hf_scsi_mmc_adip_eib5,
{ "Extended Format Block 5", "scsi.mmc.adip.extended_format_block.5", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL}},
{ &hf_scsi_mmc_adip_device_manuf_id,
{ "Device Manufacturer Id", "scsi.mmc.adip.device_manufacturer_id", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_mmc_adip_media_type_id,
{ "Media Type Id", "scsi.mmc.adip.media_type_id", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_mmc_adip_product_revision_number,
{ "Product Revision Number", "scsi.mmc.adip.product_revision_number", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_mmc_adip_number_of_physical_info,
{ "Number of bytes of physical info", "scsi.mmc.adip.number_of_physical_info", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_mmc_disc_num_layers,
{ "Number of Layers", "scsi.mmc.disk.num_layers", FT_UINT8, BASE_DEC,
VALS(scsi_num_layers), 0x60, NULL, HFILL}},
{ &hf_scsi_mmc_disc_track_path,
{ "Track Path", "scsi.mmc.disk.track_path", FT_BOOLEAN, 8,
TFS(&scsi_track_path), 0x10, NULL, HFILL}},
};
static gint *ett[] = {
&ett_scsi_mmc_profile,
};
proto_scsi_mmc = proto_register_protocol("SCSI_MMC", "SCSI_MMC", "scsi_mmc");
proto_register_field_array(proto_scsi_mmc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
