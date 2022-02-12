static void
dissect_sbc_formatunit (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *fuflags_fields[] = {
&hf_scsi_sbc_fuflags_fmtpinfo,
&hf_scsi_sbc_fuflags_rto_req,
&hf_scsi_sbc_fuflags_longlist,
&hf_scsi_sbc_fuflags_fmtdata,
&hf_scsi_sbc_fuflags_cmplist,
&hf_scsi_sbc_defect_list_format,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_formatunit_flags,
ett_scsi_format_unit, fuflags_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_formatunit_vendor, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_formatunit_interleave, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_read6 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%06x, Len: %u)",
tvb_get_ntoh24 (tvb, offset),
tvb_get_guint8 (tvb, offset+3));
}
if (tree && isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_sbc_rdwr6_lba, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr6_xferlen, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_write6 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%06x, Len: %u)",
tvb_get_ntoh24 (tvb, offset),
tvb_get_guint8 (tvb, offset+3));
}
if (tree && isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_sbc_rdwr6_lba, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr6_xferlen, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_prefetch10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *prefetch_fields[] = {
&hf_scsi_sbc_prefetch_immed,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohs (tvb, offset+6));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_prefetch_flags,
ett_scsi_prefetch, prefetch_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_xferlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_synchronizecache10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *sync_fields[] = {
&hf_scsi_sbc_synccache_sync_nv,
&hf_scsi_sbc_synccache_immed,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohs (tvb, offset+6));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_synccache_flags,
ett_scsi_synccache, sync_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_xferlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_synchronizecache16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *sync_fields[] = {
&hf_scsi_sbc_synccache_sync_nv,
&hf_scsi_sbc_synccache_immed,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: %" G_GINT64_MODIFIER "u, Len: %u)",
tvb_get_ntoh64 (tvb, offset+1),
tvb_get_ntohl (tvb, offset+9));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_synccache_flags,
ett_scsi_synccache, sync_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr16_lba, tvb, offset+1, 8, ENC_NA);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr12_xferlen, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_prefetch16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *prefetch_fields[] = {
&hf_scsi_sbc_prefetch_immed,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: %" G_GINT64_MODIFIER "u, Len: %u)",
tvb_get_ntoh64 (tvb, offset+1),
tvb_get_ntohl (tvb, offset+9));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_prefetch_flags,
ett_scsi_prefetch, prefetch_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr16_lba, tvb, offset+1, 8, ENC_NA);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr12_xferlen, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_sbc_read10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rdwr10_fields[] = {
&hf_scsi_sbc_rdprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_fua_nv,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohs (tvb, offset+6));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_read_flags,
ett_scsi_rdwr, rdwr10_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_xferlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_xdread10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *xdread10_fields[] = {
&hf_scsi_sbc_xorpinfo,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohs (tvb, offset+6));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_xdread_flags,
ett_scsi_xdread, xdread10_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_xferlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_xdwrite10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *xdwrite10_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_disable_write,
&hf_scsi_sbc_fua_nv,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohs (tvb, offset+6));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_xdwrite_flags,
ett_scsi_xdwrite, xdwrite10_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_xferlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_xdwriteread10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *xdwriteread10_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_disable_write,
&hf_scsi_sbc_fua_nv,
&hf_scsi_sbc_xorpinfo,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohs (tvb, offset+6));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_xdwriteread_flags,
ett_scsi_xdwriteread, xdwriteread10_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_xferlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_xpwrite10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *xpwrite10_fields[] = {
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_fua_nv,
&hf_scsi_sbc_xorpinfo,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohs (tvb, offset+6));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_xpwrite_flags,
ett_scsi_xpwrite, xpwrite10_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_xferlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_sbc_write10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rdwr10_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_fua_nv,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohs (tvb, offset+6));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_read_flags,
ett_scsi_rdwr, rdwr10_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_xferlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_sbc_read12 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rdwr12_fields[] = {
&hf_scsi_sbc_rdprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_fua_nv,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohl (tvb, offset+5));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_read_flags,
ett_scsi_rdwr, rdwr12_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr12_xferlen, tvb, offset+5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_sbc_write12 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rdwr12_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_fua_nv,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohl (tvb, offset+5));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_read_flags,
ett_scsi_rdwr, rdwr12_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr12_xferlen, tvb, offset+5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_read16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rdwr16_fields[] = {
&hf_scsi_sbc_rdprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_fua_nv,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: %" G_GINT64_MODIFIER "u, Len: %u)",
tvb_get_ntoh64 (tvb, offset+1),
tvb_get_ntohl (tvb, offset+9));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_read_flags,
ett_scsi_rdwr, rdwr16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr16_lba, tvb, offset+1, 8, ENC_NA);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr12_xferlen, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_write16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rdwr16_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_fua_nv,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: %" G_GINT64_MODIFIER "u, Len: %u)",
tvb_get_ntoh64 (tvb, offset+1),
tvb_get_ntohl (tvb, offset+9));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_read_flags,
ett_scsi_rdwr, rdwr16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr16_lba, tvb, offset+1, 8, ENC_NA);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr12_xferlen, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_orwrite (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rdwr16_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_fua_nv,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: %" G_GINT64_MODIFIER "u, Len: %u)",
tvb_get_ntoh64 (tvb, offset+1),
tvb_get_ntohl (tvb, offset+9));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_read_flags,
ett_scsi_rdwr, rdwr16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr16_lba, tvb, offset+1, 8, ENC_NA);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr12_xferlen, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_comparenwrite (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *rdwr16_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_fua,
&hf_scsi_sbc_fua_nv,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: %" G_GINT64_MODIFIER "u, Len: %u)",
tvb_get_ntoh64 (tvb, offset+1),
tvb_get_ntohl (tvb, offset+9));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_read_flags,
ett_scsi_rdwr, rdwr16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr16_lba, tvb, offset+1, 8, ENC_NA);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr12_xferlen, tvb, offset+12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_sbc_startstopunit (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq _U_, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *ssu_fields[] = {
&hf_scsi_sbc_ssu_immed,
NULL
};
static const int *pwr_fields[] = {
&hf_scsi_sbc_ssu_pwr_cond,
&hf_scsi_sbc_ssu_loej,
&hf_scsi_sbc_ssu_start,
NULL
};
if (!tree || !iscdb)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_ssu_immed_flags,
ett_scsi_ssu_immed, ssu_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+3, hf_scsi_sbc_ssu_pwr_flags,
ett_scsi_ssu_pwr, pwr_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_verify10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *verify10_fields[] = {
&hf_scsi_sbc_vrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_bytchk,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohs (tvb, offset+6));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_verify_flags,
ett_scsi_verify, verify10_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_verify_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_verify_vlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_verify12 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *verify12_fields[] = {
&hf_scsi_sbc_vrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_bytchk,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohl (tvb, offset+5));
}
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_verify_flags,
ett_scsi_verify, verify12_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_verify_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_verify_vlen32, tvb, offset+5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_verify16 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *verify16_fields[] = {
&hf_scsi_sbc_vrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_bytchk,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: %" G_GINT64_MODIFIER "u, Len: %u)",
tvb_get_ntoh64 (tvb, offset+1),
tvb_get_ntohl (tvb, offset+9));
}
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_verify_flags,
ett_scsi_verify, verify16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_verify_lba64, tvb, offset+1, 8, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_verify_vlen32, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_wrverify10 (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb, guint payload_len _U_,
scsi_task_data_t *cdata _U_)
{
static const int *wrverify10_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_bytchk,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohs (tvb, offset+6));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_wrverify_flags,
ett_scsi_wrverify, wrverify10_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_wrverify_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_wrverify_xferlen, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_wrverify12 (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb, guint payload_len _U_,
scsi_task_data_t *cdata _U_)
{
static const int *wrverify12_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_bytchk,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: 0x%08x, Len: %u)",
tvb_get_ntohl (tvb, offset+1),
tvb_get_ntohl (tvb, offset+5));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_wrverify_flags,
ett_scsi_wrverify, wrverify12_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_wrverify_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_wrverify_xferlen32, tvb, offset+5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_wrverify16 (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb, guint payload_len _U_,
scsi_task_data_t *cdata _U_)
{
static const int *wrverify16_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_dpo,
&hf_scsi_sbc_bytchk,
NULL
};
if (isreq && iscdb) {
if (check_col (pinfo->cinfo, COL_INFO))
col_append_fstr (pinfo->cinfo, COL_INFO, "(LBA: %" G_GINT64_MODIFIER "u, Len: %u)",
tvb_get_ntoh64 (tvb, offset+1),
tvb_get_ntohl (tvb, offset+9));
}
if (tree && isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_wrverify_flags,
ett_scsi_wrverify, wrverify16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_wrverify_lba64, tvb, offset+1, 8, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_wrverify_xferlen32, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_sbc_readcapacity10 (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint32 len, block_len, tot_len;
const char *un;
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else if (!iscdb) {
len = tvb_get_ntohl (tvb, offset);
block_len = tvb_get_ntohl (tvb, offset+4);
tot_len=((len/1024)*block_len)/1024;
un="MB";
if(tot_len>20000){
tot_len/=1024;
un="GB";
}
proto_tree_add_uint_format (tree, hf_scsi_sbc_returned_lba, tvb, offset, 4, len, "LBA: %u (%u %s)", len, tot_len, un);
proto_tree_add_item (tree, hf_scsi_sbc_blocksize, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_readdefectdata10 (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *defect_fields[] = {
&hf_scsi_sbc_defect_list_format,
&hf_scsi_sbc_req_plist,
&hf_scsi_sbc_req_glist,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset+1, hf_scsi_sbc_readdefdata_flags,
ett_scsi_defectdata, defect_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_readlong10 (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *corrct_fields[] = {
&hf_scsi_sbc_corrct,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_corrct_flags,
ett_scsi_corrct, corrct_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_writelong10 (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_writesame10 (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *writesame10_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_anchor,
&hf_scsi_sbc_unmap,
&hf_scsi_sbc_pbdata,
&hf_scsi_sbc_lbdata,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_writesame_flags,
ett_scsi_writesame, writesame10_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr10_lba, tvb, offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_writesame16 (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *writesame16_fields[] = {
&hf_scsi_sbc_wrprotect,
&hf_scsi_sbc_anchor,
&hf_scsi_sbc_unmap,
&hf_scsi_sbc_pbdata,
&hf_scsi_sbc_lbdata,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_writesame_flags,
ett_scsi_writesame, writesame16_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr16_lba, tvb, offset+1, 8, ENC_NA);
proto_tree_add_item (tree, hf_scsi_sbc_rdwr12_xferlen, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+14, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_unmap (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *unmap_fields[] = {
&hf_scsi_sbc_unmap_anchor,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_unmap_flags,
ett_scsi_unmap, unmap_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_group, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
} else if (isreq) {
proto_tree_add_item (tree, hf_scsi_sbc_unmap_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_unmap_block_descriptor_data_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 8;
while (tvb_reported_length_remaining(tvb, offset) >=16) {
proto_tree *tr;
proto_item *it;
gint64 lba;
gint32 num_blocks;
it = proto_tree_add_text(tree, tvb, offset, 16, "UNMAP Block Descriptor: LBA ");
tr = proto_item_add_subtree(it, ett_scsi_unmap_block_descriptor);
proto_tree_add_item (tr, hf_scsi_sbc_unmap_lba, tvb, offset, 8, ENC_BIG_ENDIAN);
lba = tvb_get_ntoh64 (tvb, offset);
proto_tree_add_item (tr, hf_scsi_sbc_unmap_num_blocks, tvb, offset+8, 4, ENC_BIG_ENDIAN);
num_blocks = tvb_get_ntohl(tvb, offset+8);
if (num_blocks > 1) {
proto_item_append_text (it, "%" G_GINT64_MODIFIER "u-%" G_GINT64_MODIFIER "u ", lba, lba+num_blocks-1);
} else {
proto_item_append_text (it, "%" G_GINT64_MODIFIER "u ", lba);
}
offset += 16;
}
}
}
static void
dissect_sbc_readdefectdata12 (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *defect_fields[] = {
&hf_scsi_sbc_defect_list_format,
&hf_scsi_sbc_req_plist,
&hf_scsi_sbc_req_glist,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_readdefdata_flags,
ett_scsi_defectdata, defect_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_alloclen32, tvb, offset+5, 4, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_reassignblocks (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *reassign_fields[] = {
&hf_scsi_sbc_reassignblocks_longlba,
&hf_scsi_sbc_reassignblocks_longlist,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_sbc_reassignblks_flags,
ett_scsi_reassign_blocks, reassign_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_sbc_serviceactionin16 (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 service_action;
guint32 block_len;
guint64 len, tot_len;
const char *un;
if (!tree)
return;
if (isreq && iscdb) {
service_action = tvb_get_guint8 (tvb, offset) & 0x1F;
if(cdata && cdata->itlq){
cdata->itlq->flags=service_action;
}
switch(service_action){
case SERVICE_READ_CAPACITY16:
col_append_str(pinfo->cinfo, COL_INFO, " READCAPACITY16");
proto_tree_add_text (tree, tvb, offset, 1,
"Service Action: %s",
val_to_str (service_action,
service_action_vals,
"Unknown (0x%02x)"));
offset += 9;
proto_tree_add_item (tree, hf_scsi_sbc_alloclen32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
offset++;
break;
case SERVICE_READ_LONG16:
col_append_str(pinfo->cinfo, COL_INFO, " READ_LONG16");
proto_tree_add_text (tree, tvb, offset, 1,
"Service Action: %s",
val_to_str (service_action,
service_action_vals,
"Unknown (0x%02x)"));
offset++;
proto_tree_add_text (tree, tvb, offset, 8,
"Logical Block Address: %" G_GINT64_MODIFIER "u",
tvb_get_ntoh64 (tvb, offset));
offset+=8;
offset+=2;
proto_tree_add_item (tree, hf_scsi_sbc_alloclen16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
offset++;
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
offset++;
break;
case SERVICE_GET_LBA_STATUS:
col_append_str(pinfo->cinfo, COL_INFO, " GET_LBA_STATUS");
proto_tree_add_text (tree, tvb, offset, 1,
"Service Action: %s",
val_to_str (service_action,
service_action_vals,
"Unknown (0x%02x)"));
offset++;
proto_tree_add_item (tree, hf_scsi_sbc_get_lba_status_lba, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item (tree, hf_scsi_sbc_alloclen32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset++;
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
offset++;
break;
};
} else if (!iscdb) {
if(cdata && cdata->itlq){
switch(cdata->itlq->flags){
case SERVICE_READ_CAPACITY16:
len = tvb_get_ntoh64 (tvb, offset);
block_len = tvb_get_ntohl (tvb, offset+8);
tot_len=((len/1024)*block_len)/1024;
un="MB";
if(tot_len>20000){
tot_len/=1024;
un="GB";
}
proto_tree_add_text (tree, tvb, offset, 8, "LBA: %" G_GINT64_MODIFIER "u (%" G_GINT64_MODIFIER "u %s)",
len, tot_len, un);
proto_tree_add_item (tree, hf_scsi_sbc_blocksize, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_prot_en, tvb, offset+12, 1, ENC_BIG_ENDIAN);
if (tvb_get_guint8(tvb, offset+12) & 0x01) {
proto_tree_add_item (tree, hf_scsi_sbc_ptype, tvb, offset+12, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item (tree, hf_scsi_sbc_p_i_exponent, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_lbppbe, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_lbpme, tvb, offset+14, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_lbprz, tvb, offset+14, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_sbc_lalba, tvb, offset+14, 2, ENC_BIG_ENDIAN);
break;
case SERVICE_GET_LBA_STATUS:
proto_tree_add_item (tree, hf_scsi_sbc_get_lba_status_data_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset += 4;
while (tvb_length_remaining(tvb, offset) >= 16) {
proto_tree *tr;
proto_item *it;
guint64 lba;
guint32 num_blocks;
guint8 type;
it = proto_tree_add_text(tree, tvb, offset, 16, "LBA Status Descriptor: ");
tr = proto_item_add_subtree(it, ett_scsi_lba_status_descriptor);
proto_tree_add_item (tr, hf_scsi_sbc_get_lba_status_lba, tvb, offset, 8, ENC_BIG_ENDIAN);
lba = tvb_get_ntoh64(tvb, offset);
offset += 8;
proto_tree_add_item (tr, hf_scsi_sbc_get_lba_status_num_blocks, tvb, offset, 4, ENC_BIG_ENDIAN);
num_blocks = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item (tr, hf_scsi_sbc_get_lba_status_provisioning_status, tvb, offset, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, offset) & 0x07;
offset++;
offset += 3;
proto_item_append_text (it, "%" G_GINT64_MODIFIER "u-%" G_GINT64_MODIFIER "u %s",
lba,
lba + num_blocks - 1,
val_to_str(type, scsi_provisioning_type_val, "Unknown (0x%02x)")
);
}
break;
}
}
}
}
void
proto_register_scsi_sbc(void)
{
static hf_register_info hf[] = {
{ &hf_scsi_sbc_opcode,
{"SBC Opcode", "scsi_sbc.opcode", FT_UINT8, BASE_HEX,
VALS (scsi_sbc_vals), 0x0, NULL, HFILL}},
{ &hf_scsi_sbc_formatunit_flags,
{"Flags", "scsi_sbc.formatunit.flags", FT_UINT8, BASE_HEX, NULL, 0xF8,
NULL, HFILL}},
{ &hf_scsi_sbc_defect_list_format,
{"Defect List Format", "scsi_sbc.defect_list_format", FT_UINT8, BASE_DEC,
NULL, 0x7, NULL, HFILL}},
{ &hf_scsi_sbc_formatunit_vendor,
{"Vendor Unique", "scsi_sbc.formatunit.vendor", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_sbc_formatunit_interleave,
{"Interleave", "scsi_sbc.formatunit.interleave", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_sbc_rdwr6_lba,
{"Logical Block Address (LBA)", "scsi_sbc.rdwr6.lba", FT_UINT24, BASE_DEC,
NULL, 0x0FFFFF, NULL, HFILL}},
{ &hf_scsi_sbc_rdwr6_xferlen,
{"Transfer Length", "scsi_sbc.rdwr6.xferlen", FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_sbc_rdwr10_lba,
{"Logical Block Address (LBA)", "scsi_sbc.rdwr10.lba", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_sbc_rdwr10_xferlen,
{"Transfer Length", "scsi_sbc.rdwr10.xferlen", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_sbc_rdwr12_xferlen,
{"Transfer Length", "scsi_sbc.rdwr12.xferlen", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_sbc_rdwr16_lba,
{"Logical Block Address (LBA)", "scsi_sbc.rdwr16.lba", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_sbc_ssu_immed,
{"Immediate", "scsi_sbc.ssu.immediate", FT_BOOLEAN, 8, NULL,
0x01, NULL, HFILL}},
{ &hf_scsi_sbc_ssu_pwr_cond,
{"Power Conditions", "scsi_sbc.ssu.pwr", FT_UINT8, BASE_HEX,
VALS (scsi_ssu_pwrcnd_val), 0xF0, NULL, HFILL}},
{ &hf_scsi_sbc_ssu_loej,
{"LOEJ", "scsi_sbc.ssu.loej", FT_BOOLEAN, 8, NULL, 0x2, NULL,
HFILL}},
{ &hf_scsi_sbc_ssu_start,
{"Start", "scsi_sbc.ssu.start", FT_BOOLEAN, 8, NULL, 0x1,
NULL, HFILL}},
{ &hf_scsi_sbc_bytchk,
{"BYTCHK", "scsi_sbc.bytchk", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
#if 0
{ &hf_scsi_sbc_verify_reladdr,
{"RELADDR", "scsi_sbc.verify.reladdr", FT_BOOLEAN, 8, NULL,
0x1, NULL, HFILL}},
#endif
{ &hf_scsi_sbc_verify_lba,
{"LBA", "scsi_sbc.verify.lba", FT_UINT32, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_verify_lba64,
{"LBA", "scsi_sbc.verify.lba64", FT_UINT64, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_verify_vlen,
{"Verification Length", "scsi_sbc.verify.vlen", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_sbc_verify_vlen32,
{"Verification Length", "scsi_sbc.verify.vlen32", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_sbc_wrverify_lba,
{"LBA", "scsi_sbc.wrverify.lba", FT_UINT32, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_wrverify_xferlen,
{"Transfer Length", "scsi_sbc.wrverify.xferlen", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_sbc_wrverify_lba64,
{"LBA", "scsi_sbc.wrverify.lba64", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_sbc_wrverify_xferlen32,
{"Transfer Length", "scsi_sbc.wrverify.xferlen32", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
#if 0
{ &hf_scsi_sbc_readcapacity_flags,
{"Flags", "scsi_sbc.readcapacity.flags", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
#endif
{ &hf_scsi_sbc_readdefdata_flags,
{"Flags", "scsi_sbc.readdefdata.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_reassignblks_flags,
{"Flags", "scsi_sbc.reassignblks.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_read_flags,
{"Flags", "scsi_sbc.read.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_alloclen32,
{"Allocation Length", "scsi_sbc.alloclen32", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_sbc_alloclen16,
{"Allocation Length", "scsi_sbc.alloclen16", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_sbc_fuflags_fmtpinfo,
{"FMTPINFO", "scsi_sbc.format_unit.fmtpinfo", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{ &hf_scsi_sbc_fuflags_rto_req,
{"RTO_REQ", "scsi_sbc.format_unit.rto_req", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{ &hf_scsi_sbc_fuflags_longlist,
{"LONGLIST", "scsi_sbc.format_unit.longlist", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL}},
{ &hf_scsi_sbc_fuflags_fmtdata,
{"FMTDATA", "scsi_sbc.format_unit.fmtdata", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{ &hf_scsi_sbc_fuflags_cmplist,
{"CMPLIST", "scsi_sbc.format_unit.cmplist", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{ &hf_scsi_sbc_prefetch_flags,
{"Flags", "scsi_sbc.prefetch.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_prefetch_immed,
{"Immediate", "scsi_sbc.prefetch.immediate", FT_BOOLEAN, 8, NULL,
0x2, NULL, HFILL}},
{ &hf_scsi_sbc_group,
{"Group", "scsi_sbc.group", FT_UINT8, BASE_HEX, NULL,
0x1f, NULL, HFILL}},
{ &hf_scsi_sbc_rdprotect,
{"RDPROTECT", "scsi_sbc.rdprotect", FT_UINT8, BASE_HEX,
NULL, 0xe0, NULL, HFILL}},
{ &hf_scsi_sbc_dpo,
{"DPO", "scsi_sbc.dpo", FT_BOOLEAN, 8,
TFS(&dpo_tfs), 0x10, "DisablePageOut: Whether the device should cache the data or not", HFILL}},
{ &hf_scsi_sbc_fua,
{"FUA", "scsi_sbc.fua", FT_BOOLEAN, 8,
TFS(&fua_tfs), 0x08, "ForceUnitAccess: Whether to allow reading from the cache or not", HFILL}},
{ &hf_scsi_sbc_fua_nv,
{"FUA_NV", "scsi_sbc.fua_nv", FT_BOOLEAN, 8,
TFS(&fua_nv_tfs), 0x02, "ForceUnitAccess_NonVolatile: Whether to allow reading from non-volatile cache or not", HFILL}},
{ &hf_scsi_sbc_blocksize,
{"Block size in bytes", "scsi_sbc.blocksize", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_returned_lba,
{"Returned LBA", "scsi_sbc.returned_lba", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_req_plist,
{"REQ_PLIST", "scsi_sbc.req_plist", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{ &hf_scsi_sbc_req_glist,
{"REQ_GLIST", "scsi_sbc.req_glist", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{ &hf_scsi_sbc_corrct,
{"CORRCT", "scsi_sbc.corrct", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_sbc_corrct_flags,
{"Flags", "scsi_sbc.corrct_flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_reassignblocks_longlba,
{"LongLBA", "scsi_sbc.reassignblocks.longlba", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_sbc_reassignblocks_longlist,
{"LongList", "scsi_sbc.reassignblocks.longlist", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_sbc_ssu_immed_flags,
{"Immed flags", "scsi_sbc.ssu.immed_flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_ssu_pwr_flags,
{"Pwr flags", "scsi_sbc.ssu.pwr_flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_synccache_flags,
{"Flags", "scsi_sbc.synccache.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_synccache_immed,
{"Immediate", "scsi_sbc.synccache.immediate", FT_BOOLEAN, 8, NULL,
0x02, NULL, HFILL}},
{ &hf_scsi_sbc_synccache_sync_nv,
{"SYNC_NV", "scsi_sbc.synccache.sync_nv", FT_BOOLEAN, 8, NULL,
0x04, NULL, HFILL}},
{ &hf_scsi_sbc_vrprotect,
{"VRPROTECT", "scsi_sbc.vrprotect", FT_UINT8, BASE_HEX,
NULL, 0xe0, NULL, HFILL}},
{ &hf_scsi_sbc_verify_flags,
{"Flags", "scsi_sbc.verify_flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_wrprotect,
{"WRPROTECT", "scsi_sbc.wrprotect", FT_UINT8, BASE_HEX,
NULL, 0xe0, NULL, HFILL}},
{ &hf_scsi_sbc_wrverify_flags,
{"Flags", "scsi_sbc.wrverify_flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_writesame_flags,
{"Flags", "scsi_sbc.writesame_flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_anchor,
{"ANCHOR", "scsi_sbc.anchor", FT_BOOLEAN, 8, NULL,
0x10, NULL, HFILL}},
{ &hf_scsi_sbc_unmap,
{"UNMAP", "scsi_sbc.unmap", FT_BOOLEAN, 8, NULL,
0x08, NULL, HFILL}},
{ &hf_scsi_sbc_pbdata,
{"PBDATA", "scsi_sbc.pbdata", FT_BOOLEAN, 8, NULL,
0x04, NULL, HFILL}},
{ &hf_scsi_sbc_lbdata,
{"LBDATA", "scsi_sbc.lbdata", FT_BOOLEAN, 8, NULL,
0x02, NULL, HFILL}},
{ &hf_scsi_sbc_xdread_flags,
{"Flags", "scsi_sbc.xdread.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_xorpinfo,
{"XORPINFO", "scsi_sbc.xorpinfo", FT_BOOLEAN, 8, NULL,
0x01, NULL, HFILL}},
{ &hf_scsi_sbc_disable_write,
{"DISABLE_WRITE", "scsi_sbc.disable_write", FT_BOOLEAN, 8, NULL,
0x04, NULL, HFILL}},
{ &hf_scsi_sbc_xdwrite_flags,
{"Flags", "scsi_sbc.xdwrite.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_xdwriteread_flags,
{"Flags", "scsi_sbc.xdwriteread.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_xpwrite_flags,
{"Flags", "scsi_sbc.xpwrite.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_sbc_unmap_anchor,
{"ANCHOR", "scsi_sbc.unmap.anchor", FT_BOOLEAN, 8, NULL,
0x01, NULL, HFILL}},
{ &hf_scsi_sbc_unmap_flags,
{"Flags", "scsi_sbc.unmap_flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_unmap_data_length,
{"Data Length", "scsi_sbc.unmap.data_length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_unmap_block_descriptor_data_length,
{"Block Descriptor Data Length", "scsi_sbc.unmap.block_descriptor_data_length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_unmap_lba,
{"LBA", "scsi_sbc.unmap.lba", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_unmap_num_blocks,
{"Num Blocks", "scsi_sbc.unmap.num_blocks", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_ptype,
{"PTYPE", "scsi_sbc.ptype", FT_UINT8, BASE_DEC,
VALS(scsi_ptype_val), 0x0e, NULL, HFILL}},
{ &hf_scsi_sbc_prot_en,
{"PROT_EN", "scsi_sbc.prot_en", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_sbc_p_i_exponent,
{"P_I_EXPONENT", "scsi_sbc.p_i_exponent", FT_UINT8, BASE_DEC,
NULL, 0xf0, NULL, HFILL}},
{ &hf_scsi_sbc_lbppbe,
{"LOGICAL_BLOCKS_PER_PHYSICAL_BLOCK_EXPONENT", "scsi_sbc.lbppbe", FT_UINT8, BASE_DEC,
NULL, 0x0f, NULL, HFILL}},
{ &hf_scsi_sbc_lbpme,
{"LBPME", "scsi_sbc.lbpme", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{ &hf_scsi_sbc_lbprz,
{"LBPRZ", "scsi_sbc.lbprz", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{ &hf_scsi_sbc_lalba,
{"LOWEST_ALIGNED_LBA", "scsi_sbc.lalba", FT_UINT16, BASE_DEC,
NULL, 0x3fff, NULL, HFILL}},
{ &hf_scsi_sbc_get_lba_status_lba,
{"LBA", "scsi_sbc.get_lba_status.start_lba", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_get_lba_status_data_length,
{"Data Length", "scsi_sbc.get_lba_status.data_length", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_get_lba_status_num_blocks,
{"Num Blocks", "scsi_sbc.get_lba_status.num_blocks", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_sbc_get_lba_status_provisioning_status,
{"Provisioning Type", "scsi_sbc.get_lba_status.provisioning_type", FT_UINT8, BASE_DEC,
VALS(scsi_provisioning_type_val), 0x07, NULL, HFILL}},
};
static gint *ett[] = {
&ett_scsi_format_unit,
&ett_scsi_prefetch,
&ett_scsi_rdwr,
&ett_scsi_xdread,
&ett_scsi_xdwrite,
&ett_scsi_xdwriteread,
&ett_scsi_xpwrite,
&ett_scsi_defectdata,
&ett_scsi_corrct,
&ett_scsi_reassign_blocks,
&ett_scsi_ssu_immed,
&ett_scsi_ssu_pwr,
&ett_scsi_synccache,
&ett_scsi_verify,
&ett_scsi_wrverify,
&ett_scsi_writesame,
&ett_scsi_unmap,
&ett_scsi_unmap_block_descriptor,
&ett_scsi_lba_status_descriptor
};
proto_scsi_sbc = proto_register_protocol("SCSI_SBC", "SCSI_SBC", "scsi_sbc");
proto_register_field_array(proto_scsi_sbc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_scsi_sbc(void)
{
}
