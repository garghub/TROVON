static void
dissect_ssc_read6 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *read6_fields[] = {
&hf_scsi_ssc_sili,
&hf_scsi_ssc_fixed,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, read6_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr6_xferlen, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_recoverbuffereddata (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *recover_fields[] = {
&hf_scsi_ssc_sili,
&hf_scsi_ssc_fixed,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, recover_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr6_xferlen, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_reportdensitysupport (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rd_fields[] = {
&hf_scsi_ssc_medium_type,
&hf_scsi_ssc_media,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if(!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, rd_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr6_xferlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
} else {
}
}
static void
dissect_ssc_readreverse6 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rr6_fields[] = {
&hf_scsi_ssc_bytord,
&hf_scsi_ssc_sili,
&hf_scsi_ssc_fixed,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, rr6_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr6_xferlen, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_read16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *read6_fields[] = {
&hf_scsi_ssc_sili,
&hf_scsi_ssc_fixed,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, read6_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_partition, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_locate16_loid, tvb, offset+3, 8, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr6_xferlen, tvb, offset+11, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_write16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *write16_fields[] = {
&hf_scsi_ssc_fcs,
&hf_scsi_ssc_lcs,
&hf_scsi_ssc_fixed,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, write16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_partition, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_locate16_loid, tvb, offset+3, 8, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr6_xferlen, tvb, offset+11, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_writefilemarks16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *wf16_fields[] = {
&hf_scsi_ssc_fcs,
&hf_scsi_ssc_lcs,
&hf_scsi_ssc_immed,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, wf16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_partition, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_locate16_loid, tvb, offset+3, 8, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr6_xferlen, tvb, offset+11, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_verify16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *verify16_fields[] = {
&hf_scsi_ssc_verify16_immed,
&hf_scsi_ssc_bytcmp,
&hf_scsi_ssc_fixed,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, verify16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_partition, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_locate16_loid, tvb, offset+3, 8, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_ver16_verlen, tvb, offset+11, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_verify6 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *verify6_fields[] = {
&hf_scsi_ssc_verify16_immed,
&hf_scsi_ssc_bytcmp,
&hf_scsi_ssc_fixed,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, verify6_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_ver16_verlen, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_readreverse16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rr16_fields[] = {
&hf_scsi_ssc_bytord,
&hf_scsi_ssc_sili,
&hf_scsi_ssc_fixed,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, rr16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_partition, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_locate16_loid, tvb, offset+3, 8, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr6_xferlen, tvb, offset+11, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_write6 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *write6_fields[] = {
&hf_scsi_ssc_immed,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, write6_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr6_xferlen, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_writefilemarks6 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *wf6_fields[] = {
&hf_scsi_ssc_immed,
NULL
};
if (isreq) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Len: %u)",
tvb_get_ntoh24 (tvb, offset+1));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, wf6_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr6_xferlen, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_loadunload (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *loadunload_immed_fields[] = {
&hf_scsi_ssc_immed,
NULL
};
static const int *loadunload_fields[] = {
&hf_scsi_ssc_hold,
&hf_scsi_ssc_eot,
&hf_scsi_ssc_reten,
&hf_scsi_ssc_load,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Immed: %u)",
tvb_get_guint8 (tvb, offset) & 0x01);
}
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_loadunload_immed_flags,
ett_scsi_loadunload_immed, loadunload_immed_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+3, hf_scsi_ssc_loadunload_flags,
ett_scsi_loadunload, loadunload_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_readblocklimits (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 granularity;
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else if (!iscdb) {
granularity = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1, "Granularity: %u (%u %s)",
granularity, 1 << granularity,
plurality(1 << granularity, "byte", "bytes"));
proto_tree_add_text (tree, tvb, offset+1, 3, "Maximum Block Length Limit: %u bytes",
tvb_get_ntoh24 (tvb, offset+1));
proto_tree_add_text (tree, tvb, offset+4, 2, "Minimum Block Length Limit: %u bytes",
tvb_get_ntohs (tvb, offset+4));
}
}
static void
dissect_ssc_rewind (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rewind_fields[] = {
&hf_scsi_ssc_immed,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(Immed: %u)",
tvb_get_guint8 (tvb, offset) & 0x01);
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags, ett_scsi_read6, rewind_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_setcapacity (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *sc_fields[] = {
&hf_scsi_ssc_immed,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_read6_flags,
ett_scsi_read6, sc_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_capacity_prop_value, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_locate10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *locate_fields[] = {
&hf_scsi_ssc_bt,
&hf_scsi_ssc_cp,
&hf_scsi_ssc_immed,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_locate_flags,
ett_scsi_locate, locate_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_locate10_loid, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_partition, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_locate16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *locate_fields[] = {
&hf_scsi_ssc_dest_type,
&hf_scsi_ssc_cp,
&hf_scsi_ssc_immed,
NULL
};
static const int *bam_fields[] = {
&hf_scsi_ssc_bam,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_locate_flags,
ett_scsi_locate, locate_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+1, hf_scsi_ssc_bam_flags,
ett_scsi_bam, bam_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_partition, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_locate16_loid, tvb, offset+3, 8, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_erase6 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 flags;
if (isreq && iscdb) {
if (!tree)
return;
flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"IMMED: %u, LONG: %u",
(flags & 0x02) >> 1,
flags & 0x01);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_erase16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *erase16_fields[] = {
&hf_scsi_ssc_fcs,
&hf_scsi_ssc_lcs,
&hf_scsi_ssc_erase_immed,
&hf_scsi_ssc_long,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_erase_flags,
ett_scsi_erase, erase16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_partition, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_lbi, tvb, offset+3, 8, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_space6 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_ssc_space6_code, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_space6_count, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_space16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_ssc_space6_code, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_space16_count, tvb, offset+3, 8, ENC_BIG_ENDIAN);
proto_tree_add_text (tree, tvb, offset+11, 2,
"Parameter Len: %u",
tvb_get_ntohs (tvb, offset+11));
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_formatmedium (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *formatmedium_fields[] = {
&hf_scsi_ssc_verify,
&hf_scsi_ssc_immed,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_ssc_formatmedium_flags,
ett_scsi_formatmedium, formatmedium_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_format, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_ssc_rdwr10_xferlen, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_ssc_readposition (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata)
{
gint service_action;
guint8 flags;
if (!tree)
return;
if (isreq && iscdb) {
service_action = tvb_get_guint8 (tvb, offset) & 0x1F;
proto_tree_add_text (tree, tvb, offset, 1,
"Service Action: %s",
val_to_str (service_action,
service_action_vals,
"Unknown (0x%02x)"));
if (cdata != NULL) {
cdata->itlq->flags = service_action;
}
proto_tree_add_text (tree, tvb, offset+6, 2,
"Parameter Len: %u",
tvb_get_ntohs (tvb, offset+6));
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else if (!isreq) {
if (cdata)
service_action = cdata->itlq->flags;
else
service_action = -1;
switch (service_action) {
case SHORT_FORM_BLOCK_ID:
case SHORT_FORM_VENDOR_SPECIFIC:
flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"BOP: %u, EOP: %u, BCU: %u, BYCU: %u, BPU: %u, PERR: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & BCU) >> 5, (flags & BYCU) >> 4,
(flags & BPU) >> 2, (flags & 0x02) >> 1);
offset += 1;
proto_tree_add_item (tree, hf_scsi_ssc_partition, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 2;
if (!(flags & BPU)) {
proto_tree_add_text (tree, tvb, offset, 4,
"First Block Location: %u",
tvb_get_ntohl (tvb, offset));
offset += 4;
proto_tree_add_text (tree, tvb, offset, 4,
"Last Block Location: %u",
tvb_get_ntohl (tvb, offset));
offset += 4;
} else
offset += 8;
offset += 1;
if (!(flags & BCU)) {
proto_tree_add_text (tree, tvb, offset, 3,
"Number of Blocks in Buffer: %u",
tvb_get_ntoh24 (tvb, offset));
}
offset += 3;
if (!(flags & BYCU)) {
proto_tree_add_text (tree, tvb, offset, 4,
"Number of Bytes in Buffer: %u",
tvb_get_ntohl (tvb, offset));
}
offset += 4;
break;
case LONG_FORM:
flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"BOP: %u, EOP: %u, MPU: %u, BPU: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & MPU) >> 3, (flags & BPU) >> 2);
offset += 1;
offset += 3;
if (!(flags & BPU)) {
proto_tree_add_text (tree, tvb, offset, 4,
"Partition Number: %u",
tvb_get_ntohl (tvb, offset));
offset += 4;
proto_tree_add_text (tree, tvb, offset, 8,
"Block Number: %" G_GINT64_MODIFIER "u",
tvb_get_ntoh64 (tvb, offset));
offset += 8;
} else
offset += 12;
if (!(flags & MPU)) {
proto_tree_add_text (tree, tvb, offset, 8,
"File Number: %" G_GINT64_MODIFIER "u",
tvb_get_ntoh64 (tvb, offset));
offset += 8;
proto_tree_add_text (tree, tvb, offset, 8,
"Set Number: %" G_GINT64_MODIFIER "u",
tvb_get_ntoh64 (tvb, offset));
offset += 8;
} else
offset += 16;
break;
case EXTENDED_FORM:
flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"BOP: %u, EOP: %u, BCU: %u, BYCU: %u, MPU: %u, BPU: %u, PERR: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & BCU) >> 5, (flags & BYCU) >> 4,
(flags & MPU) >> 3, (flags & BPU) >> 2,
(flags & 0x02) >> 1);
offset += 1;
proto_tree_add_item (tree, hf_scsi_ssc_partition, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_text (tree, tvb, offset, 2,
"Additional Length: %u",
tvb_get_ntohs (tvb, offset));
offset += 2;
offset += 1;
if (!(flags & BCU)) {
proto_tree_add_text (tree, tvb, offset, 3,
"Number of Blocks in Buffer: %u",
tvb_get_ntoh24 (tvb, offset));
}
offset += 3;
if (!(flags & BPU)) {
proto_tree_add_text (tree, tvb, offset, 8,
"First Block Location: %" G_GINT64_MODIFIER "u",
tvb_get_ntoh64 (tvb, offset));
offset += 8;
proto_tree_add_text (tree, tvb, offset, 8,
"Last Block Location: %" G_GINT64_MODIFIER "u",
tvb_get_ntoh64 (tvb, offset));
offset += 8;
} else
offset += 16;
offset += 1;
if (!(flags & BYCU)) {
proto_tree_add_text (tree, tvb, offset, 8,
"Number of Bytes in Buffer: %" G_GINT64_MODIFIER "u",
tvb_get_ntoh64 (tvb, offset));
}
offset += 8;
break;
default:
break;
}
}
}
void
proto_register_scsi_ssc(void)
{
static hf_register_info hf[] = {
{ &hf_scsi_ssc_opcode,
{"SSC Opcode", "scsi.ssc.opcode", FT_UINT8, BASE_HEX,
VALS (scsi_ssc_vals), 0x0, NULL, HFILL}},
{ &hf_scsi_ssc_rdwr6_xferlen,
{"Transfer Length", "scsi.ssc.rdwr6.xferlen", FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_ssc_ver16_verlen,
{"Verification Length", "scsi.ssc.verify16.verify_len", FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_ssc_locate10_loid,
{"Logical Object Identifier", "scsi.ssc.locate10.loid", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_ssc_locate16_loid,
{"Logical Identifier", "scsi.ssc.locate16.loid", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_ssc_space6_count,
{"Count", "scsi.ssc.space6.count", FT_INT24, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_ssc_space6_code,
{"Code", "scsi.ssc.space6.code", FT_UINT8, BASE_HEX,
VALS(space6_code_vals), 0x0f,
NULL, HFILL}},
{ &hf_scsi_ssc_space16_count,
{"Count", "scsi.ssc.space16.count", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_ssc_rdwr10_xferlen,
{"Transfer Length", "scsi.ssc.rdwr10.xferlen", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_ssc_erase_flags,
{"Flags", "scsi.ssc.erase_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_ssc_fcs,
{"FCS", "scsi.ssc.fcs", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{ &hf_scsi_ssc_lcs,
{"LCS", "scsi.ssc.lcs", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_ssc_erase_immed,
{"IMMED", "scsi.ssc.erase_immed", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_ssc_long,
{"LONG", "scsi.ssc.long", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_ssc_partition,
{"Partition", "scsi.ssc.partition", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_ssc_lbi,
{"Logical Block Identifier", "scsi.ssc.lbi", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_ssc_verify,
{"VERIFY", "scsi.ssc.verify", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_ssc_immed,
{"IMMED", "scsi.ssc.immed", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_ssc_formatmedium_flags,
{"Flags", "scsi.ssc.formatmedium_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_ssc_format,
{"Format", "scsi.ssc.format", FT_UINT8, BASE_HEX,
VALS(format_vals), 0x0f, NULL, HFILL}},
{ &hf_scsi_ssc_loadunload_immed_flags,
{"Immed", "scsi.ssc.loadunload_immed_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_ssc_loadunload_flags,
{"Flags", "scsi.ssc.loadunload_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_ssc_hold,
{"HOLD", "scsi.ssc.hold", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{ &hf_scsi_ssc_eot,
{"EOT", "scsi.ssc.eot", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_ssc_reten,
{"RETEN", "scsi.ssc.reten", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_ssc_load,
{"LOAD", "scsi.ssc.load", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_ssc_locate_flags,
{"Flags", "scsi.ssc.locate_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_ssc_bt,
{"BT", "scsi.ssc.bt", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_ssc_cp,
{"CP", "scsi.ssc.cp", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_ssc_dest_type,
{"Dest Type", "scsi.ssc.dest_type", FT_UINT8, BASE_HEX,
VALS(dest_type_vals), 0x18, NULL, HFILL}},
{ &hf_scsi_ssc_bam_flags,
{"Flags", "scsi.ssc.bam_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_ssc_bam,
{"BAM", "scsi.ssc.bam", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_ssc_read6_flags,
{"Flags", "scsi.ssc.read6_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_ssc_sili,
{"SILI", "scsi.ssc.sili", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_ssc_fixed,
{"FIXED", "scsi.ssc.fixed", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_ssc_bytord,
{"BYTORD", "scsi.ssc.bytord", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_ssc_bytcmp,
{"BYTCMP", "scsi.ssc.bytcmp", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_ssc_verify16_immed,
{"IMMED", "scsi.ssc.verify16_immed", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_scsi_ssc_medium_type,
{"Medium Type", "scsi.ssc.medium_type", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_ssc_media,
{"Media", "scsi.ssc.media", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_ssc_capacity_prop_value,
{"Capacity Proportion Value", "scsi.ssc.cpv", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_scsi_erase,
&ett_scsi_formatmedium,
&ett_scsi_loadunload_immed,
&ett_scsi_loadunload,
&ett_scsi_locate,
&ett_scsi_bam,
&ett_scsi_read6
};
proto_scsi_ssc = proto_register_protocol("SCSI_SSC", "SCSI_SSC", "scsi_ssc");
proto_register_field_array(proto_scsi_ssc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_scsi_ssc(void)
{
}
