static void
scsi_defragment_init(void)
{
fragment_table_init(&scsi_fragment_table);
reassembled_table_init(&scsi_reassembled_table);
}
static void
log_parameter_2e_0001(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_rw, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0002(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_ww, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0003(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_he, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0004(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_media, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0005(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_rf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0006(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_wf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0007(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_ml, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0008(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_ndg, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0009(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_wp, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_000a(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_nr, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_000b(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_cm, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_000c(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_uf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_000d(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_rmcf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_000e(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_umcf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_000f(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_mcicf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0010(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_fe, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0011(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_rof, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0012(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_tdcol, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0013(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_nml, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0014(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_cn, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0015(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_cp, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0016(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_ecm, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0017(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_ict, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0018(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_rr, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0019(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_dpie, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_001a(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_cff, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_001b(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_psf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_001c(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_pc, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_001d(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_dm, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_001e(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_hwa, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_001f(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_hwb, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0020(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_if, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0021(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_em, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0022(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_dwf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0023(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_drhu, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0024(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_drtm, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0025(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_drvo, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0026(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_pefa, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0027(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_dire, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0032(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_lost, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0033(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_tduau, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0034(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_tsawf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0035(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_tsarf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0036(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_nsod, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0037(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_lofa, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0038(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_uuf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_0039(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_aif, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_003a(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_fwf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_003b(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_wmicf, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
log_parameter_2e_003c(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_log_ta_wmoa, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
dissect_scsi_evpd(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, guint tot_len _U_)
{
proto_tree *evpd_tree;
proto_item *ti;
guint pcode, plen, i, idlen;
guint8 codeset, flags;
if (tree) {
pcode = tvb_get_guint8(tvb, offset+1);
plen = tvb_get_guint8(tvb, offset+3);
ti = proto_tree_add_text(tree, tvb, offset, plen+4, "Page Code: %s",
val_to_str(pcode, scsi_evpd_pagecode_val,
"Unknown (0x%08x)"));
evpd_tree = proto_item_add_subtree(ti, ett_scsi_page);
proto_tree_add_item(evpd_tree, hf_scsi_inq_qualifier, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(evpd_tree, hf_scsi_inq_devtype, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_text(evpd_tree, tvb, offset+1, 1,
"Page Code: %s",
val_to_str(pcode, scsi_evpd_pagecode_val,
"Unknown (0x%02x)"));
proto_tree_add_text(evpd_tree, tvb, offset+3, 1,
"Page Length: %u", plen);
offset += 4;
switch (pcode) {
case SCSI_EVPD_SUPPPG:
for (i = 0; i < plen; i++) {
proto_tree_add_text(evpd_tree, tvb, offset+i, 1,
"Supported Page: %s",
val_to_str(tvb_get_guint8(tvb, offset+i),
scsi_evpd_pagecode_val,
"Unknown (0x%02x)"));
}
break;
case SCSI_EVPD_DEVID:
while (plen != 0) {
codeset = tvb_get_guint8(tvb, offset) & 0x0F;
proto_tree_add_text(evpd_tree, tvb, offset, 1,
"Code Set: %s",
val_to_str(codeset,
scsi_devid_codeset_val,
"Unknown (0x%02x)"));
plen -= 1;
offset += 1;
if (plen < 1) {
proto_tree_add_text(evpd_tree, tvb, offset, 0,
"Product data goes past end of page");
break;
}
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_text(evpd_tree, tvb, offset, 1,
"Association: %s",
val_to_str((flags & 0x30) >> 4,
scsi_devid_assoc_val,
"Unknown (0x%02x)"));
proto_tree_add_text(evpd_tree, tvb, offset, 1,
"Identifier Type: %s",
val_to_str((flags & 0x0F),
scsi_devid_idtype_val,
"Unknown (0x%02x)"));
plen -= 1;
offset += 1;
if (plen < 1) {
proto_tree_add_text(evpd_tree, tvb, offset, 0,
"Product data goes past end of page");
break;
}
plen -= 1;
offset += 1;
if (plen < 1) {
proto_tree_add_text(evpd_tree, tvb, offset, 0,
"Product data goes past end of page");
break;
}
idlen = tvb_get_guint8(tvb, offset);
proto_tree_add_text(evpd_tree, tvb, offset, 1,
"Identifier Length: %u", idlen);
plen -= 1;
offset += 1;
if (idlen != 0) {
if (plen < idlen) {
proto_tree_add_text(evpd_tree, tvb, offset, 0,
"Product data goes past end of page");
break;
}
if (codeset == CODESET_ASCII) {
proto_tree_add_text(evpd_tree, tvb, offset, idlen,
"Identifier: %s",
tvb_format_text(tvb, offset,
idlen));
} else {
proto_tree_add_text(evpd_tree, tvb, offset, idlen,
"Identifier: %s",
tvb_bytes_to_str(tvb, offset,
idlen));
}
plen -= idlen;
offset += idlen;
}
}
break;
case SCSI_EVPD_DEVSERNUM:
if (plen > 0) {
proto_tree_add_text(evpd_tree, tvb, offset, plen,
"Product Serial Number: %s",
tvb_format_text(tvb, offset, plen));
}
break;
case SCSI_EVPD_BLKLIMITS:
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_wsnz, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_mcawl, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_otlg, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_mtl, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_otl, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_mpl, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_mulc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_mubdc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_oug, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_ugavalid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_uga, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(evpd_tree, hf_scsi_block_limits_mwsl, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
break;
case SCSI_EVPD_LBP:
proto_tree_add_item(evpd_tree, hf_scsi_sbc_treshold_exponent, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(evpd_tree, hf_scsi_sbc_lbpu, tvb, offset, 1, ENC_NA);
proto_tree_add_item(evpd_tree, hf_scsi_sbc_lbpws, tvb, offset, 1, ENC_NA);
proto_tree_add_item(evpd_tree, hf_scsi_sbc_lbpws10, tvb, offset, 1, ENC_NA);
proto_tree_add_item(evpd_tree, hf_scsi_sbc_lbprz, tvb, offset, 1, ENC_NA);
proto_tree_add_item(evpd_tree, hf_scsi_sbc_anc_sup, tvb, offset, 1, ENC_NA);
proto_tree_add_item(evpd_tree, hf_scsi_sbc_dp, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(evpd_tree, hf_scsi_sbc_ptype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
}
}
static void
dissect_scsi_cmddt(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, guint tot_len _U_)
{
proto_tree *cmdt_tree;
proto_item *ti;
guint plen;
if (tree) {
plen = tvb_get_guint8(tvb, offset+5);
ti = proto_tree_add_text(tree, tvb, offset, plen, "Command Data");
cmdt_tree = proto_item_add_subtree(ti, ett_scsi_page);
proto_tree_add_item(cmdt_tree, hf_scsi_inq_qualifier, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(cmdt_tree, hf_scsi_inq_devtype, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_text(cmdt_tree, tvb, offset+1, 1, "Support: %s",
val_to_str(tvb_get_guint8(tvb, offset+1) & 0x7,
scsi_cmdt_supp_val, "Unknown (%d)"));
proto_tree_add_text(cmdt_tree, tvb, offset+2, 1, "Version: %s",
val_to_str_ext(tvb_get_guint8(tvb, offset+2),
&scsi_verdesc_val_ext,
"Unknown (0x%02x)"));
proto_tree_add_text(cmdt_tree, tvb, offset+5, 1, "CDB Size: %u",
plen);
}
}
static int
dissect_spc_inq_sccsflags(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
guint8 flags;
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_scsi_inq_sccsflags, tvb, offset, 1, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_scsi_inq_sccsflags);
}
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_scsi_inq_sccs, tvb, offset, 1, flags);
if (flags&SCSI_INQ_SCCSFLAGS_SCCS) {
proto_item_append_text(item, " SCCS");
}
flags&=(~SCSI_INQ_SCCSFLAGS_SCCS);
proto_tree_add_boolean(tree, hf_scsi_inq_acc, tvb, offset, 1, flags);
if (flags&SCSI_INQ_SCCSFLAGS_ACC) {
proto_item_append_text(item, " ACC");
}
flags&=(~SCSI_INQ_SCCSFLAGS_ACC);
proto_tree_add_item(tree, hf_scsi_inq_tpgs, tvb, offset, 1, ENC_BIG_ENDIAN);
flags&=0xcf;
proto_tree_add_boolean(tree, hf_scsi_inq_tpc, tvb, offset, 1, flags);
if (flags&SCSI_INQ_SCCSFLAGS_TPC) {
proto_item_append_text(item, " 3PC");
}
flags&=(~SCSI_INQ_SCCSFLAGS_TPC);
proto_tree_add_boolean(tree, hf_scsi_inq_protect, tvb, offset, 1, flags);
if (flags&SCSI_INQ_SCCSFLAGS_PROTECT) {
proto_item_append_text(item, " PROTECT");
}
flags&=(~SCSI_INQ_SCCSFLAGS_PROTECT);
offset+=1;
return offset;
}
static int
dissect_spc_inq_bqueflags(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
guint8 flags;
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_scsi_inq_bqueflags, tvb, offset, 1, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_scsi_inq_bqueflags);
}
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_scsi_inq_bque, tvb, offset, 1, flags);
if (flags&SCSI_INQ_BQUEFLAGS_BQUE) {
proto_item_append_text(item, " BQue");
}
flags&=(~SCSI_INQ_BQUEFLAGS_BQUE);
proto_tree_add_boolean(tree, hf_scsi_inq_encserv, tvb, offset, 1, flags);
if (flags&SCSI_INQ_BQUEFLAGS_ENCSERV) {
proto_item_append_text(item, " EncServ");
}
flags&=(~SCSI_INQ_BQUEFLAGS_ENCSERV);
proto_tree_add_boolean(tree, hf_scsi_inq_multip, tvb, offset, 1, flags);
if (flags&SCSI_INQ_BQUEFLAGS_MULTIP) {
proto_item_append_text(item, " MultiP");
}
flags&=(~SCSI_INQ_BQUEFLAGS_MULTIP);
proto_tree_add_boolean(tree, hf_scsi_inq_mchngr, tvb, offset, 1, flags);
if (flags&SCSI_INQ_BQUEFLAGS_MCHNGR) {
proto_item_append_text(item, " MChngr");
}
flags&=(~SCSI_INQ_BQUEFLAGS_MCHNGR);
offset+=1;
return offset;
}
static int
dissect_spc_inq_reladrflags(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
guint8 flags;
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_scsi_inq_reladrflags, tvb, offset, 1, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_scsi_inq_reladrflags);
}
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_scsi_inq_reladr, tvb, offset, 1, flags);
if (flags&SCSI_INQ_RELADRFLAGS_RELADR) {
proto_item_append_text(item, " RelAdr");
}
flags&=(~SCSI_INQ_RELADRFLAGS_RELADR);
proto_tree_add_boolean(tree, hf_scsi_inq_sync, tvb, offset, 1, flags);
if (flags&SCSI_INQ_RELADRFLAGS_SYNC) {
proto_item_append_text(item, " Sync");
}
flags&=(~SCSI_INQ_RELADRFLAGS_SYNC);
proto_tree_add_boolean(tree, hf_scsi_inq_linked, tvb, offset, 1, flags);
if (flags&SCSI_INQ_RELADRFLAGS_LINKED) {
proto_item_append_text(item, " Linked");
}
flags&=(~SCSI_INQ_RELADRFLAGS_LINKED);
proto_tree_add_boolean(tree, hf_scsi_inq_cmdque, tvb, offset, 1, flags);
if (flags&SCSI_INQ_RELADRFLAGS_CMDQUE) {
proto_item_append_text(item, " CmdQue");
}
flags&=(~SCSI_INQ_RELADRFLAGS_CMDQUE);
offset+=1;
return offset;
}
void
dissect_spc_inquiry(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb, guint32 payload_len,
scsi_task_data_t *cdata)
{
guint8 flags, i;
tvbuff_t *volatile tvb_v = tvb;
volatile guint offset_v = offset;
static const int *inq_control_fields[] = {
&hf_scsi_inq_control_vendor_specific,
&hf_scsi_inq_control_reserved,
&hf_scsi_inq_control_naca,
&hf_scsi_inq_control_obs1,
&hf_scsi_inq_control_obs2,
NULL
};
static const int *peripheral_fields[] = {
&hf_scsi_inq_qualifier,
&hf_scsi_inq_devtype,
NULL
};
static const int *aca_fields[] = {
&hf_scsi_inq_aerc,
&hf_scsi_inq_trmtsk,
&hf_scsi_inq_normaca,
&hf_scsi_inq_hisup,
&hf_scsi_inq_rdf,
NULL
};
static const int *rmb_fields[] = {
&hf_scsi_inq_rmb,
NULL
};
if (!isreq && ((cdata == NULL) || !(cdata->itlq->flags & 0x3))
&& (tvb_length_remaining(tvb_v, offset_v) >= 1) ) {
if (cdata && cdata->itl) {
cdata->itl->cmdset = tvb_get_guint8(tvb_v, offset_v)&SCSI_DEV_BITS;
}
}
if (isreq && iscdb) {
flags = tvb_get_guint8(tvb_v, offset_v);
if (cdata) {
cdata->itlq->flags = flags;
}
proto_tree_add_uint_format(tree, hf_scsi_inquiry_flags, tvb_v, offset_v, 1,
flags, "CMDT = %u, EVPD = %u",
flags & 0x2, flags & 0x1);
if (flags & 0x1) {
proto_tree_add_item(tree, hf_scsi_inquiry_evpd_page, tvb_v, offset_v+1,
1, ENC_BIG_ENDIAN);
}
else if (flags & 0x2) {
proto_tree_add_item(tree, hf_scsi_inquiry_cmdt_page, tvb_v, offset_v+1,
1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree, hf_scsi_alloclen, tvb_v, offset_v+3, 1, ENC_BIG_ENDIAN);
if (cdata) {
cdata->itlq->alloc_len = tvb_get_guint8(tvb_v, offset_v+3);
}
proto_tree_add_bitmask(tree, tvb_v, offset_v+4, hf_scsi_inq_control,
ett_scsi_inq_control, inq_control_fields, ENC_BIG_ENDIAN);
} else if (!isreq) {
if (!cdata) {
return;
}
if (cdata->itlq->flags & 0x1) {
dissect_scsi_evpd(tvb_v, pinfo, tree, offset_v, payload_len);
return;
}
if (cdata->itlq->flags & 0x2) {
dissect_scsi_cmddt(tvb_v, pinfo, tree, offset_v, payload_len);
return;
}
TRY_SCSI_CDB_ALLOC_LEN(pinfo, tvb_v, offset_v, cdata->itlq->alloc_len);
proto_tree_add_bitmask(tree, tvb_v, offset_v, hf_scsi_inq_peripheral, ett_scsi_inq_peripheral, peripheral_fields, ENC_BIG_ENDIAN);
offset_v+=1;
proto_tree_add_bitmask(tree, tvb_v, offset_v, hf_scsi_inq_rmbflags, ett_scsi_inq_rmbflags, rmb_fields, ENC_BIG_ENDIAN);
offset_v+=1;
proto_tree_add_item(tree, hf_scsi_inq_version, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
offset_v+=1;
proto_tree_add_bitmask(tree, tvb_v, offset_v, hf_scsi_inq_acaflags, ett_scsi_inq_acaflags, aca_fields, ENC_BIG_ENDIAN);
offset_v+=1;
SET_SCSI_DATA_END(tvb_get_guint8(tvb_v, offset_v)+offset);
proto_tree_add_item(tree, hf_scsi_inq_add_len, tvb_v, offset_v, 1, ENC_BIG_ENDIAN);
offset_v+=1;
offset_v = dissect_spc_inq_sccsflags(tvb_v, offset_v, tree);
offset_v = dissect_spc_inq_bqueflags(tvb_v, offset_v, tree);
offset_v = dissect_spc_inq_reladrflags(tvb_v, offset_v, tree);
proto_tree_add_item(tree, hf_scsi_inq_vendor_id, tvb_v, offset_v, 8, ENC_ASCII|ENC_NA);
offset_v+=8;
proto_tree_add_item(tree, hf_scsi_inq_product_id, tvb_v, offset_v, 16, ENC_ASCII|ENC_NA);
offset_v+=16;
proto_tree_add_item(tree, hf_scsi_inq_product_rev, tvb_v, offset_v, 4, ENC_ASCII|ENC_NA);
offset_v+=4;
proto_tree_add_item(tree, hf_scsi_inq_vendor_specific, tvb_v, offset_v, 20, ENC_NA);
offset_v+=20;
proto_tree_add_item(tree, hf_scsi_inq_reserved, tvb_v, offset_v, 2, ENC_NA);
offset_v++;
offset_v++;
for(i = 0;i<8;i++) {
proto_tree_add_item(tree, hf_scsi_inq_version_desc, tvb_v, offset_v, 2, ENC_BIG_ENDIAN);
offset_v+=2;
}
END_TRY_SCSI_CDB_ALLOC_LEN;
}
}
void
dissect_spc_extcopy(tvbuff_t *tvb _U_, packet_info *pinfo _U_,
proto_tree *tree _U_, guint offset _U_,
gboolean isreq _U_, gboolean iscdb _U_,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
}
static int
dissect_scsi_log_page(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset)
{
static const int *pcflags_fields[] = {
&hf_scsi_log_pagecode,
NULL
};
static const int *paramflags_fields[] = {
&hf_scsi_log_pf_du,
&hf_scsi_log_pf_ds,
&hf_scsi_log_pf_tsd,
&hf_scsi_log_pf_etc,
&hf_scsi_log_pf_tmc,
&hf_scsi_log_pf_lbin,
&hf_scsi_log_pf_lp,
NULL
};
guint16 pagelen, pagecode;
guint8 paramlen;
proto_tree *log_tree = NULL;
proto_item *ti = NULL;
guint old_offset = offset;
const log_pages_t *log_page;
pagecode = tvb_get_guint8(tvb, offset) & 0x3f;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, -1,
"Log Page: %s", val_to_str(pagecode, scsi_log_page_val, "Unknown (0x%04x)"));
log_tree = proto_item_add_subtree(ti, ett_scsi_log);
}
proto_tree_add_bitmask(log_tree, tvb, offset, hf_scsi_log_pc_flags, ett_scsi_log_pc, pcflags_fields, ENC_BIG_ENDIAN);
offset+=1;
offset+=1;
pagelen = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(log_tree, hf_scsi_log_page_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
for(log_page = log_pages;log_page;log_page++) {
if (log_page->parameters == NULL) {
log_page = NULL;
break;
}
if (log_page->page == pagecode) {
break;
}
}
while( offset<(old_offset+4+pagelen) ) {
const log_page_parameters_t *log_parameter = NULL;
guint16 log_param;
log_param = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(log_tree, hf_scsi_log_parameter_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_bitmask(log_tree, tvb, offset, hf_scsi_log_param_flags, ett_scsi_log_param, paramflags_fields, ENC_BIG_ENDIAN);
offset+=1;
paramlen = tvb_get_guint8(tvb, offset);
proto_tree_add_item(log_tree, hf_scsi_log_param_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
if (log_page) {
for(log_parameter = log_page->parameters;log_parameter;log_parameter++) {
if (log_parameter->dissector == NULL) {
log_parameter = NULL;
break;
}
if (log_parameter->number == log_param) {
break;
}
}
}
if (paramlen) {
if (log_parameter && log_parameter->dissector) {
tvbuff_t *param_tvb;
param_tvb = tvb_new_subset(tvb, offset, MIN(tvb_length_remaining(tvb, offset),paramlen), paramlen);
log_parameter->dissector(param_tvb, pinfo, log_tree);
} else {
proto_tree_add_item(log_tree, hf_scsi_log_param_data, tvb, offset, paramlen, ENC_NA);
}
offset+=paramlen;
}
}
proto_item_set_len(ti, offset-old_offset);
return offset;
}
void
dissect_spc_logselect(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *ppcflags_fields[] = {
&hf_scsi_log_pcr,
&hf_scsi_log_sp,
NULL
};
static const int *pcflags_fields[] = {
&hf_scsi_log_pc,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_log_ppc_flags,
ett_scsi_log_ppc, ppcflags_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+1, hf_scsi_log_pc_flags, ett_scsi_log_pc, pcflags_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_paramlen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else {
}
}
void
dissect_spc_logsense(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *ppcflags_fields[] = {
&hf_scsi_log_ppc,
&hf_scsi_log_sp,
NULL
};
static const int *pcflags_fields[] = {
&hf_scsi_log_pc,
&hf_scsi_log_pagecode,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_log_ppc_flags,
ett_scsi_log_ppc, ppcflags_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+1, hf_scsi_log_pc_flags,
ett_scsi_log_pc, pcflags_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_log_parameter_ptr, tvb, offset+4,
2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
} else if (!isreq) {
if (!cdata) {
return;
}
dissect_scsi_log_page(tvb, pinfo, tree, offset);
}
}
static void
dissect_scsi_blockdescs(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *scsi_tree,
scsi_task_data_t *cdata, gboolean longlba)
{
int offset = 0;
if (!cdata)
return;
while (tvb_length_remaining(tvb, offset) > 0) {
if (longlba) {
if (tvb_length_remaining(tvb, offset)<8)
return;
proto_tree_add_text(scsi_tree, tvb, offset, 8, "No. of Blocks: %" G_GINT64_MODIFIER "u",
tvb_get_ntoh64(tvb, offset));
offset += 8;
if (tvb_length_remaining(tvb, offset)<1)
return;
proto_tree_add_text(scsi_tree, tvb, offset, 1, "Density Code: 0x%02x",
tvb_get_guint8(tvb, offset));
offset += 1;
offset += 3;
if (tvb_length_remaining(tvb, offset)<4)
return;
proto_tree_add_text(scsi_tree, tvb, offset, 4, "Block Length: %u",
tvb_get_ntohl(tvb, offset));
offset += 4;
} else {
if ((cdata->itl->cmdset&SCSI_CMDSET_MASK) == SCSI_DEV_SBC) {
if (tvb_length_remaining(tvb, offset)<4)
return;
proto_tree_add_text(scsi_tree, tvb, offset, 4, "No. of Blocks: %u",
tvb_get_ntohl(tvb, offset));
offset += 4;
offset++;
if (tvb_length_remaining(tvb, offset)<3)
return;
proto_tree_add_text(scsi_tree, tvb, offset, 3, "Block Length: %u",
tvb_get_ntoh24(tvb, offset));
offset += 3;
} else {
if (tvb_length_remaining(tvb, offset)<1)
return;
proto_tree_add_text(scsi_tree, tvb, offset, 1, "Density Code: 0x%02x",
tvb_get_guint8(tvb, offset));
offset += 1;
if (tvb_length_remaining(tvb, offset)<3)
return;
proto_tree_add_text(scsi_tree, tvb, offset, 3, "No. of Blocks: %u",
tvb_get_ntoh24(tvb, offset));
offset += 3;
offset++;
if (tvb_length_remaining(tvb, offset)<3)
return;
proto_tree_add_text(scsi_tree, tvb, offset, 3, "Block Length: %u",
tvb_get_ntoh24(tvb, offset));
offset += 3;
}
}
}
}
static gboolean
dissect_scsi_spc_modepage(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, guint8 pcode)
{
guint8 flags, proto;
switch (pcode) {
case SCSI_SPC_MODEPAGE_CTL:
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_item(tree, hf_scsi_modesns_tst, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, offset+2, 1,
"Global Logging Target Save Disable: %u, Report Log Exception Condition: %u",
(flags & 0x2) >> 1, (flags & 0x1));
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_item(tree, hf_scsi_modesns_qmod, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_modesns_qerr, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, offset+3, 1, "Disable Queuing: %u",
flags & 0x1);
flags = tvb_get_guint8(tvb, offset+4);
proto_tree_add_item(tree, hf_scsi_modesns_rac, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_modesns_tas, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, offset+4, 1,
"SWP: %u, RAERP: %u, UAAERP: %u, EAERP: %u",
(flags & 0x8) >> 3, (flags & 0x4) >> 2,
(flags & 0x2) >> 1, (flags & 0x1));
proto_tree_add_text(tree, tvb, offset+5, 1, "Autoload Mode: 0x%x",
tvb_get_guint8(tvb, offset+5) & 0x7);
proto_tree_add_text(tree, tvb, offset+6, 2,
"Ready AER Holdoff Period: %u ms",
tvb_get_ntohs(tvb, offset+6));
proto_tree_add_text(tree, tvb, offset+8, 2,
"Busy Timeout Period: %u ms",
tvb_get_ntohs(tvb, offset+8)*100);
proto_tree_add_text(tree, tvb, offset+10, 2,
"Extended Self-Test Completion Time: %u",
tvb_get_ntohs(tvb, offset+10));
break;
case SCSI_SPC_MODEPAGE_DISCON:
proto_tree_add_text(tree, tvb, offset+2, 1, "Buffer Full Ratio: %u",
tvb_get_guint8(tvb, offset+2));
proto_tree_add_text(tree, tvb, offset+3, 1, "Buffer Empty Ratio: %u",
tvb_get_guint8(tvb, offset+3));
proto_tree_add_text(tree, tvb, offset+4, 2, "Bus Inactivity Limit: %u",
tvb_get_ntohs(tvb, offset+4));
proto_tree_add_text(tree, tvb, offset+6, 2, "Disconnect Time Limit: %u",
tvb_get_ntohs(tvb, offset+6));
proto_tree_add_text(tree, tvb, offset+8, 2, "Connect Time Limit: %u",
tvb_get_ntohs(tvb, offset+8));
proto_tree_add_text(tree, tvb, offset+10, 2,
"Maximum Burst Size: %u bytes",
tvb_get_ntohs(tvb, offset+10)*512);
flags = tvb_get_guint8(tvb, offset+12);
proto_tree_add_text(tree, tvb, offset+12, 1,
"EMDP: %u, FAA: %u, FAB: %u, FAC: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & 0x20) >> 5, (flags & 0x10) >> 4);
proto_tree_add_text(tree, tvb, offset+14, 2,
"First Burst Size: %u bytes",
tvb_get_ntohs(tvb, offset+14)*512);
break;
case SCSI_SPC_MODEPAGE_INFOEXCP:
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset+2, 1,
"Perf: %u, EBF: %u, EWasc: %u, DExcpt: %u, Test: %u, LogErr: %u",
(flags & 0x80) >> 7, (flags & 0x20) >> 5,
(flags & 0x10) >> 4, (flags & 0x08) >> 3,
(flags & 0x04) >> 2, (flags & 0x01));
if (!((flags & 0x10) >> 4) && ((flags & 0x08) >> 3)) {
proto_item *hidden_item;
hidden_item = proto_tree_add_item(tree, hf_scsi_modesns_errrep, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
else {
proto_tree_add_item(tree, hf_scsi_modesns_errrep, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_text(tree, tvb, offset+4, 4, "Interval Timer: %u",
tvb_get_ntohl(tvb, offset+4));
proto_tree_add_text(tree, tvb, offset+8, 4, "Report Count: %u",
tvb_get_ntohl(tvb, offset+8));
break;
case SCSI_SPC_MODEPAGE_PWR:
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset+3, 1, "Idle: %u, Standby: %u",
(flags & 0x2) >> 1, (flags & 0x1));
proto_tree_add_text(tree, tvb, offset+4, 2,
"Idle Condition Timer: %u ms",
tvb_get_ntohs(tvb, offset+4) * 100);
proto_tree_add_text(tree, tvb, offset+6, 2,
"Standby Condition Timer: %u ms",
tvb_get_ntohs(tvb, offset+6) * 100);
break;
case SCSI_SPC_MODEPAGE_LUN:
return FALSE;
case SCSI_SPC_MODEPAGE_PORT:
proto = tvb_get_guint8(tvb, offset+2) & 0x0F;
proto_tree_add_item(tree, hf_scsi_protocol, tvb, offset+2, 1, ENC_BIG_ENDIAN);
if (proto == SCSI_PROTO_FCP) {
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset+3, 1,
"DTFD: %u, PLPB: %u, DDIS: %u, DLM: %u, RHA: %u, ALWI: %u, DTIPE: %u, DTOLI:%u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & 0x20) >> 5, (flags & 0x10) >> 4,
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x1));
proto_tree_add_text(tree, tvb, offset+6, 1, "RR_TOV Units: %s",
val_to_str(tvb_get_guint8(tvb, offset+6) & 0x7,
scsi_fcp_rrtov_val,
"Unknown (0x%02x)"));
proto_tree_add_text(tree, tvb, offset+7, 1, "RR_TOV: %u",
tvb_get_guint8(tvb, offset+7));
}
else if (proto == SCSI_PROTO_iSCSI) {
return FALSE;
}
else {
return FALSE;
}
break;
case SCSI_SCSI2_MODEPAGE_PERDEV:
return FALSE;
default:
return FALSE;
}
return TRUE;
}
static gboolean
dissect_scsi_sbc_modepage(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, guint8 pcode)
{
guint8 flags;
switch (pcode) {
case SCSI_SBC_MODEPAGE_FMTDEV:
proto_tree_add_text(tree, tvb, offset+2, 2, "Tracks Per Zone: %u",
tvb_get_ntohs(tvb, offset+2));
proto_tree_add_text(tree, tvb, offset+4, 2,
"Alternate Sectors Per Zone: %u",
tvb_get_ntohs(tvb, offset+4));
proto_tree_add_text(tree, tvb, offset+6, 2,
"Alternate Tracks Per Zone: %u",
tvb_get_ntohs(tvb, offset+6));
proto_tree_add_text(tree, tvb, offset+8, 2,
"Alternate Tracks Per LU: %u",
tvb_get_ntohs(tvb, offset+8));
proto_tree_add_text(tree, tvb, offset+10, 2, "Sectors Per Track: %u",
tvb_get_ntohs(tvb, offset+10));
proto_tree_add_text(tree, tvb, offset+12, 2,
"Data Bytes Per Physical Sector: %u",
tvb_get_ntohs(tvb, offset+12));
proto_tree_add_text(tree, tvb, offset+14, 2, "Interleave: %u",
tvb_get_ntohs(tvb, offset+14));
proto_tree_add_text(tree, tvb, offset+16, 2, "Track Skew Factor: %u",
tvb_get_ntohs(tvb, offset+16));
proto_tree_add_text(tree, tvb, offset+18, 2,
"Cylinder Skew Factor: %u",
tvb_get_ntohs(tvb, offset+18));
flags = tvb_get_guint8(tvb, offset+20);
proto_tree_add_text(tree, tvb, offset+20, 1,
"SSEC: %u, HSEC: %u, RMB: %u, SURF: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & 0x20) >> 5, (flags & 0x10) >> 4);
break;
case SCSI_SBC_MODEPAGE_RDWRERR:
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset+2, 1,
"AWRE: %u, ARRE: %u, TB: %u, RC: %u, EER: %u, PER: %u, DTE: %u, DCR: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & 0x20) >> 5, (flags & 0x10) >> 4,
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
proto_tree_add_text(tree, tvb, offset+3, 1, "Read Retry Count: %u",
tvb_get_guint8(tvb, offset+3));
proto_tree_add_text(tree, tvb, offset+4, 1, "Correction Span: %u",
tvb_get_guint8(tvb, offset+4));
proto_tree_add_text(tree, tvb, offset+5, 1, "Head Offset Count: %u",
tvb_get_guint8(tvb, offset+5));
proto_tree_add_text(tree, tvb, offset+6, 1,
"Data Strobe Offset Count: %u",
tvb_get_guint8(tvb, offset+6));
proto_tree_add_text(tree, tvb, offset+8, 1, "Write Retry Count: %u",
tvb_get_guint8(tvb, offset+8));
proto_tree_add_text(tree, tvb, offset+10, 2,
"Recovery Time Limit: %u ms",
tvb_get_ntohs(tvb, offset+10));
break;
case SCSI_SBC_MODEPAGE_DISKGEOM:
proto_tree_add_text(tree, tvb, offset+2, 3, "Number of Cylinders: %u",
tvb_get_ntoh24(tvb, offset+2));
proto_tree_add_text(tree, tvb, offset+5, 1, "Number of Heads: %u",
tvb_get_guint8(tvb, offset+5));
proto_tree_add_text(tree, tvb, offset+6, 3,
"Starting Cyl Pre-compensation: %u",
tvb_get_ntoh24(tvb, offset+6));
proto_tree_add_text(tree, tvb, offset+9, 3,
"Starting Cyl-reduced Write Current: %u",
tvb_get_ntoh24(tvb, offset+9));
proto_tree_add_text(tree, tvb, offset+12, 2, "Device Step Rate: %u",
tvb_get_ntohs(tvb, offset+12));
proto_tree_add_text(tree, tvb, offset+14, 3, "Landing Zone Cyl: %u",
tvb_get_ntoh24(tvb, offset+14));
proto_tree_add_text(tree, tvb, offset+18, 1, "Rotational Offset: %u",
tvb_get_guint8(tvb, offset+18));
proto_tree_add_text(tree, tvb, offset+20, 2,
"Medium Rotation Rate: %u",
tvb_get_ntohs(tvb, offset+20));
break;
case SCSI_SBC_MODEPAGE_FLEXDISK:
return FALSE;
case SCSI_SBC_MODEPAGE_VERERR:
return FALSE;
case SCSI_SBC_MODEPAGE_CACHE:
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset+2, 1,
"IC: %u, ABPF: %u, CAP %u, Disc: %u, Size: %u, WCE: %u, MF: %u, RCD: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & 0x20) >> 5, (flags & 0x10) >> 4,
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset+3, 1,
"Demand Read Retention Priority: %u, Write Retention Priority: %u",
(flags & 0xF0) >> 4, (flags & 0x0F));
proto_tree_add_text(tree, tvb, offset+4, 2,
"Disable Pre-fetch Xfer Len: %u",
tvb_get_ntohs(tvb, offset+4));
proto_tree_add_text(tree, tvb, offset+6, 2, "Minimum Pre-Fetch: %u",
tvb_get_ntohs(tvb, offset+6));
proto_tree_add_text(tree, tvb, offset+8, 2, "Maximum Pre-Fetch: %u",
tvb_get_ntohs(tvb, offset+8));
proto_tree_add_text(tree, tvb, offset+10, 2,
"Maximum Pre-Fetch Ceiling: %u",
tvb_get_ntohs(tvb, offset+10));
flags = tvb_get_guint8(tvb, offset+12);
proto_tree_add_text(tree, tvb, offset+12, 1,
"FSW: %u, LBCSS: %u, DRA: %u, Vendor Specific: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & 0x20) >> 5, (flags & 0x1F) >> 4);
proto_tree_add_text(tree, tvb, offset+13, 1,
"Number of Cache Segments: %u",
tvb_get_guint8(tvb, offset+13));
proto_tree_add_text(tree, tvb, offset+14, 2, "Cache Segment Size: %u",
tvb_get_ntohs(tvb, offset+14));
proto_tree_add_text(tree, tvb, offset+17, 3,
"Non-Cache Segment Size: %u",
tvb_get_ntoh24(tvb, offset+17));
break;
case SCSI_SBC_MODEPAGE_MEDTYPE:
return FALSE;
case SCSI_SBC_MODEPAGE_NOTPART:
return FALSE;
case SCSI_SBC_MODEPAGE_XORCTL:
return FALSE;
default:
return FALSE;
}
return TRUE;
}
static gboolean
dissect_scsi_ssc2_modepage(tvbuff_t *tvb _U_, packet_info *pinfo _U_,
proto_tree *tree _U_, guint offset _U_,
guint8 pcode)
{
guint8 flags;
switch (pcode) {
case SCSI_SSC2_MODEPAGE_DATACOMP:
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset+2, 1,
"DCE: %u, DCC: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6);
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset+3, 1,
"DDE: %u, RED: %u",
(flags & 0x80) >> 7, (flags & 0x60) >> 5);
proto_tree_add_text(tree, tvb, offset+4, 4,
"Compression algorithm: %s",
val_to_str(tvb_get_ntohl(tvb, offset+4),
compression_algorithm_vals,
"Unknown (0x%08x)"));
proto_tree_add_text(tree, tvb, offset+8, 4,
"Decompression algorithm: %s",
val_to_str(tvb_get_ntohl(tvb, offset+4),
compression_algorithm_vals,
"Unknown (0x%08x)"));
break;
case SCSI_SSC2_MODEPAGE_DEVCONF:
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset+2, 1,
"CAF: %u, Active Format: %u",
(flags & 0x20) >> 5, (flags & 0x1f));
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset+3, 1,
"Active Partition: %u",
flags);
flags = tvb_get_guint8(tvb, offset+4);
proto_tree_add_text(tree, tvb, offset+4, 1,
"Write Object Buffer Full Ratio: %u",
flags);
flags = tvb_get_guint8(tvb, offset+5);
proto_tree_add_text(tree, tvb, offset+5, 1,
"Read Object Buffer Empty Ratio: %u",
flags);
proto_tree_add_text(tree, tvb, offset+6, 2,
"Write Delay time: %u 100ms",
tvb_get_ntohs(tvb, offset+6));
flags = tvb_get_guint8(tvb, offset+8);
proto_tree_add_text(tree, tvb, offset+8, 1,
"OBR: %u, LOIS: %u, RSMK: %u, AVC: %u, SOCF: %u, ROBO: %u, REW: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & 0x20) >> 5, (flags & 0x10) >> 4,
(flags & 0x0c) >> 2, (flags & 0x02) >> 1,
(flags & 0x01));
flags = tvb_get_guint8(tvb, offset+9);
proto_tree_add_text(tree, tvb, offset+9, 1,
"Gap Size: %u",
flags);
flags = tvb_get_guint8(tvb, offset+10);
proto_tree_add_text(tree, tvb, offset+10, 1,
"EOD Defined: %u, EEG: %u, SEW: %u, SWP: %u, BAML: %u, BAM: %u",
(flags & 0xe0) >> 5, (flags & 0x10) >> 4,
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
proto_tree_add_text(tree, tvb, offset+11, 3,
"Object Buffer Size At Early Warning: %u",
tvb_get_ntoh24(tvb, offset+11));
flags = tvb_get_guint8(tvb, offset+14);
proto_tree_add_text(tree, tvb, offset+14, 1,
"Select Data Compression Algorithm: %u",
flags);
flags = tvb_get_guint8(tvb, offset+15);
proto_tree_add_text(tree, tvb, offset+15, 1,
"OIR: %u, ReWind on Reset: %u, ASOCWP: %u, PERSWP: %u, PRMWP: %u",
(flags & 0x20) >> 5, (flags & 0x18) >> 3,
(flags & 0x04) >> 2, (flags & 0x02) >> 1,
(flags & 0x01));
break;
case SCSI_SSC2_MODEPAGE_MEDPAR1:
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset+2, 1,
"Maximum Additional Partitions: %u",
flags);
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset+3, 1,
"Additional Partitions Defined: %u",
flags);
flags = tvb_get_guint8(tvb, offset+4);
proto_tree_add_text(tree, tvb, offset+4, 1,
"FDP: %u, DSP: %u, IDP: %u, PSUM: %u, POFM: %u, CLEAR: %u, ADDP: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & 0x20) >> 5, (flags & 0x18) >> 3,
(flags & 0x04) >> 2, (flags & 0x02) >> 1,
(flags & 0x01));
flags = tvb_get_guint8(tvb, offset+5);
proto_tree_add_text(tree, tvb, offset+5, 1,
"Media Format Recognition: %u",
flags);
flags = tvb_get_guint8(tvb, offset+6);
proto_tree_add_text(tree, tvb, offset+6, 1,
"Partition Units: %u",
flags & 0x0f);
proto_tree_add_text(tree, tvb, offset+8, 2,
"Partition Size: %u",
tvb_get_ntohs(tvb, offset+8));
break;
case SCSI_SSC2_MODEPAGE_MEDPAR2:
return FALSE;
case SCSI_SSC2_MODEPAGE_MEDPAR3:
return FALSE;
case SCSI_SSC2_MODEPAGE_MEDPAR4:
return FALSE;
default:
return FALSE;
}
return TRUE;
}
static gboolean
dissect_scsi_mmc5_modepage(tvbuff_t *tvb _U_, packet_info *pinfo _U_,
proto_tree *tree _U_, guint offset _U_, guint8 pcode)
{
guint8 flags;
guint8 i;
guint16 n;
switch (pcode) {
case SCSI_MMC5_MODEPAGE_MRW:
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset+3, 1,
"LBA Space: %u",
(flags & 0x01));
break;
case SCSI_MMC5_MODEPAGE_WRPARAM:
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset+2, 1,
"BUFE: %u, LS_V: %u, Test Write: %u, Write Type: %u",
(flags & 0x40) >> 6, (flags & 0x20) >> 5, (flags & 0x10) >> 4, (flags & 0x0f));
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset+3, 1,
"Multi-session: %u, FP: %u, Copy: %u, Track Mode: %u",
(flags & 0xc0) >> 6, (flags & 0x20) >> 5, (flags & 0x10) >> 4, (flags & 0x0f));
flags = tvb_get_guint8(tvb, offset+4);
proto_tree_add_text(tree, tvb, offset+4, 1,
"Data Block Type: %u",
(flags & 0x0f));
flags = tvb_get_guint8(tvb, offset+5);
proto_tree_add_text(tree, tvb, offset+5, 1,
"Link Size: %u",
flags);
flags = tvb_get_guint8(tvb, offset+7);
proto_tree_add_text(tree, tvb, offset+7, 1,
"Initiator Application Code: %u",
(flags & 0x3f));
flags = tvb_get_guint8(tvb, offset+8);
proto_tree_add_text(tree, tvb, offset+8, 1,
"Session Format: %u",
flags);
proto_tree_add_text(tree, tvb, offset+10, 4,
"Packet Size: %u",
tvb_get_ntohl(tvb, offset+10));
proto_tree_add_text(tree, tvb, offset+14, 2,
"Audio Pause Length: %u",
tvb_get_ntohs(tvb, offset+14));
proto_tree_add_text(tree, tvb, offset+16, 16,
"Media Catalog Number: %s",
tvb_format_stringzpad(tvb, offset+16, 16));
proto_tree_add_text(tree, tvb, offset+32, 16,
"International Standard Recording Code: %s",
tvb_format_stringzpad(tvb, offset+32, 16));
for (i = 0; i < 4; i++) {
flags = tvb_get_guint8(tvb, offset+48+i);
proto_tree_add_text(tree, tvb, offset+48+i, 1,
"Sub-header Byte %u: %u",
i, flags);
}
if (0x36 == tvb_get_guint8(tvb, offset+1))
proto_tree_add_text(tree, tvb, offset+52, 4,
"Vendor Specific: %u",
tvb_get_ntohl(tvb, offset+52));
break;
case SCSI_MMC3_MODEPAGE_MMCAP:
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset+2, 1,
"DVD-RAM Read: %u, DVD-R Read: %u, DVD-ROM Read: %u,"
"Method 2: %u, CD-RW Read: %u, CD-R Read: %u",
(flags & 0x20) >> 5, (flags & 0x10) >> 4, (flags & 0x08) >> 3,
(flags & 0x04) >> 2, (flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset+3, 1,
"DVD-RAM Write: %u, DVD-R Write: %u, DVD-ROM Write: %u,"
"Test Write: %u, CD-RW Write: %u, CD-R Write: %u",
(flags & 0x20) >> 5, (flags & 0x10) >> 4, (flags & 0x08) >> 3,
(flags & 0x04) >> 2, (flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+4);
proto_tree_add_text(tree, tvb, offset+4, 1,
"BUF: %u, Multi Session: %u, Mode 2 Form 2: %u, Mode 2 Form 1: %u,"
"Digital Port (2): %u, Digital Port (1): %u, Composite: %u, Audio Play: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6, (flags & 0x20) >> 5, (flags & 0x10) >> 4,
(flags & 0x08) >> 3, (flags & 0x04) >> 2, (flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+5);
proto_tree_add_text(tree, tvb, offset+5, 1,
"Read Bar Code: %u, UPC: %u, ISRC: %u, C2 Pointers supported: %u,"
"R-W Deinterleaved & corrected: %u, R-W Supported: %u, CD-DA Stream is Accurate: %u, CD-DA Cmds Supported: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6, (flags & 0x20) >> 5, (flags & 0x10) >> 4,
(flags & 0x08) >> 3, (flags & 0x04) >> 2, (flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+6);
proto_tree_add_text(tree, tvb, offset+6, 1,
"Loading Mechanism Type: %u, Eject: %u, Prevent Jumper: %u,"
"Lock State: %u, Lock: %u",
(flags & 0xe0) >> 5, (flags & 0x08) >> 3,
(flags & 0x04) >> 2, (flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+7);
proto_tree_add_text(tree, tvb, offset+7, 1,
"R-W in Lead-in: %u, Side Change Capable: %u, S/W Slot Selection: %u,"
"Changer Supports Disc Present: %u, Separate Channel Mute: %u, Separate volume levels: %u",
(flags & 0x20) >> 5, (flags & 0x10) >> 4, (flags & 0x08) >> 3,
(flags & 0x04) >> 2, (flags & 0x02) >> 1, (flags & 0x01));
proto_tree_add_text(tree, tvb, offset+10, 2,
"Number of Volume Levels Supported: %u",
tvb_get_ntohs(tvb, offset+10));
proto_tree_add_text(tree, tvb, offset+12, 2,
"Buffer Size Supported: %u",
tvb_get_ntohs(tvb, offset+12));
flags = tvb_get_guint8(tvb, offset+17);
proto_tree_add_text(tree, tvb, offset+17, 1,
"Length: %u, LSBF: %u, RCK: %u, BCKF: %u",
(flags & 0x30) >> 4, (flags & 0x08) >> 3,
(flags & 0x04) >> 2, (flags & 0x02) >> 1);
proto_tree_add_text(tree, tvb, offset+22, 2,
"Copy Management Revision Support: %u",
tvb_get_ntohs(tvb, offset+22));
flags = tvb_get_guint8(tvb, offset+27);
proto_tree_add_text(tree, tvb, offset+27, 1,
"Rotation Control Selected: %u",
(flags & 0x03));
proto_tree_add_text(tree, tvb, offset+28, 2,
"Current Write Speed Selected: %u",
tvb_get_ntohs(tvb, offset+28));
n = tvb_get_ntohs(tvb, offset+30);
proto_tree_add_text(tree, tvb, offset+30, 2,
"Number of Logical Unit Write Speed Performance Descriptor Tables: %u",
n);
break;
default:
return FALSE;
}
return TRUE;
}
static gboolean
dissect_scsi_smc_modepage(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, guint8 pcode)
{
guint8 flags;
guint8 param_list_len;
switch (pcode) {
case SCSI_SMC_MODEPAGE_EAA:
param_list_len = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset+2, 1, "Parameter List Length: %u",
param_list_len);
if (param_list_len < 2)
break;
proto_tree_add_text(tree, tvb, offset+3, 2, "First Medium Transport Element Address: %u",
tvb_get_ntohs(tvb, offset+3));
param_list_len -= 2;
if (param_list_len < 2)
break;
proto_tree_add_text(tree, tvb, offset+5, 2, "Number of Medium Transport Elements: %u",
tvb_get_ntohs(tvb, offset+5));
param_list_len -= 2;
if (param_list_len < 2)
break;
proto_tree_add_text(tree, tvb, offset+7, 2, "First Storage Element Address: %u",
tvb_get_ntohs(tvb, offset+7));
param_list_len -= 2;
if (param_list_len < 2)
break;
proto_tree_add_text(tree, tvb, offset+9, 2, "Number of Storage Elements: %u",
tvb_get_ntohs(tvb, offset+9));
param_list_len -= 2;
if (param_list_len < 2)
break;
proto_tree_add_text(tree, tvb, offset+11, 2, "First Import/Export Element Address: %u",
tvb_get_ntohs(tvb, offset+11));
param_list_len -= 2;
if (param_list_len < 2)
break;
proto_tree_add_text(tree, tvb, offset+13, 2, "Number of Import/Export Elements: %u",
tvb_get_ntohs(tvb, offset+13));
param_list_len -= 2;
if (param_list_len < 2)
break;
proto_tree_add_text(tree, tvb, offset+15, 2, "First Data Transfer Element Address: %u",
tvb_get_ntohs(tvb, offset+15));
param_list_len -= 2;
if (param_list_len < 2)
break;
proto_tree_add_text(tree, tvb, offset+17, 2, "Number of Data Transfer Elements: %u",
tvb_get_ntohs(tvb, offset+17));
break;
case SCSI_SMC_MODEPAGE_TRANGEOM:
return FALSE;
case SCSI_SMC_MODEPAGE_DEVCAP:
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset+2, 1,
"STORDT: %u, STORI/E: %u, STORST: %u, STORMT: %u",
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+4);
proto_tree_add_text(tree, tvb, offset+4, 1,
"MT->DT: %u, MT->I/E: %u, MT->ST: %u, MT->MT: %u",
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+5);
proto_tree_add_text(tree, tvb, offset+5, 1,
"ST->DT: %u, ST->I/E: %u, ST->ST: %u, ST->MT: %u",
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+6);
proto_tree_add_text(tree, tvb, offset+6, 1,
"I/E->DT: %u, I/E->I/E: %u, I/E->ST: %u, I/E->MT: %u",
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+7);
proto_tree_add_text(tree, tvb, offset+7, 1,
"DT->DT: %u, DT->I/E: %u, DT->ST: %u, DT->MT: %u",
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+12);
proto_tree_add_text(tree, tvb, offset+12, 1,
"MT<>DT: %u, MT<>I/E: %u, MT<>ST: %u, MT<>MT: %u",
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+13);
proto_tree_add_text(tree, tvb, offset+13, 1,
"ST<>DT: %u, ST<>I/E: %u, ST<>ST: %u, ST<>MT: %u",
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+14);
proto_tree_add_text(tree, tvb, offset+14, 1,
"I/E<>DT: %u, I/E<>I/E: %u, I/E<>ST: %u, I/E<>MT: %u",
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
flags = tvb_get_guint8(tvb, offset+15);
proto_tree_add_text(tree, tvb, offset+15, 1,
"DT<>DT: %u, DT<>I/E: %u, DT<>ST: %u, DT<>MT: %u",
(flags & 0x08) >> 3, (flags & 0x04) >> 2,
(flags & 0x02) >> 1, (flags & 0x01));
break;
default:
return FALSE;
}
return TRUE;
}
static guint
dissect_scsi_modepage(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *scsi_tree, guint offset,
scsi_device_type devtype)
{
guint8 pcode, plen;
proto_tree *tree;
proto_item *ti;
const value_string *modepage_val;
int hf_pagecode;
gboolean (*dissect_modepage)(tvbuff_t *, packet_info *, proto_tree *,
guint, guint8);
pcode = tvb_get_guint8(tvb, offset);
plen = tvb_get_guint8(tvb, offset+1);
if (match_strval(pcode & SCSI_MS_PCODE_BITS,
scsi_spc_modepage_val) == NULL) {
switch (devtype) {
case SCSI_DEV_SBC:
modepage_val = scsi_sbc_modepage_val;
hf_pagecode = hf_scsi_sbcpagecode;
dissect_modepage = dissect_scsi_sbc_modepage;
break;
case SCSI_DEV_SSC:
modepage_val = scsi_ssc2_modepage_val;
hf_pagecode = hf_scsi_sscpagecode;
dissect_modepage = dissect_scsi_ssc2_modepage;
break;
case SCSI_DEV_SMC:
modepage_val = scsi_smc_modepage_val;
hf_pagecode = hf_scsi_smcpagecode;
dissect_modepage = dissect_scsi_smc_modepage;
break;
case SCSI_DEV_CDROM:
modepage_val = scsi_mmc5_modepage_val;
hf_pagecode = hf_scsi_mmcpagecode;
dissect_modepage = dissect_scsi_mmc5_modepage;
break;
default:
modepage_val = scsi_spc_modepage_val;
hf_pagecode = hf_scsi_spcpagecode;
dissect_modepage = dissect_scsi_spc_modepage;
break;
}
} else {
modepage_val = scsi_spc_modepage_val;
hf_pagecode = hf_scsi_spcpagecode;
dissect_modepage = dissect_scsi_spc_modepage;
}
ti = proto_tree_add_text(scsi_tree, tvb, offset, plen+2, "%s Mode Page",
val_to_str(pcode & SCSI_MS_PCODE_BITS,
modepage_val, "Unknown (0x%08x)"));
tree = proto_item_add_subtree(ti, ett_scsi_page);
proto_tree_add_text(tree, tvb, offset, 1, "PS: %u", (pcode & 0x80) >> 7);
proto_tree_add_item(tree, hf_pagecode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, offset+1, 1, "Page Length: %u",
plen);
if (!tvb_bytes_exist(tvb, offset, plen)) {
return (plen + 2);
}
if (!(*dissect_modepage)(tvb, pinfo, tree, offset,
(guint8) (pcode & SCSI_MS_PCODE_BITS))) {
proto_tree_add_text(tree, tvb, offset+2, plen,
"Unknown Page");
}
return (plen+2);
}
void
dissect_spc_modeselect6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len, scsi_task_data_t *cdata)
{
guint8 flags;
guint plen;
gint tot_len, desclen;
tvbuff_t *blockdesc_tvb;
if (!tree)
return;
if (isreq && iscdb) {
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_scsi_modesel_flags, tvb, offset, 1,
flags, "PF = %u, SP = %u", flags & 0x10,
flags & 0x1);
proto_tree_add_item(tree, hf_scsi_paramlen, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else {
if (payload_len < 1)
return;
tot_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Mode Data Length: %d",
tot_len);
offset += 1;
payload_len -= 1;
if (payload_len < 1)
return;
switch (cdata->itl->cmdset&SCSI_CMDSET_MASK) {
case SCSI_DEV_SBC:
proto_tree_add_text(tree, tvb, offset, 1, "Medium Type: %s",
val_to_str(tvb_get_guint8(tvb, offset),
scsi_modesense_medtype_sbc_val,
"Unknown (0x%02x)"));
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Medium Type: 0x%02x",
tvb_get_guint8(tvb, offset));
break;
}
offset += 1;
payload_len -= 1;
if (payload_len < 1)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"Device-Specific Parameter: 0x%02x",
tvb_get_guint8(tvb, offset));
offset += 1;
payload_len -= 1;
if (payload_len < 1)
return;
desclen = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Block Descriptor Length: %d", desclen);
offset += 1;
payload_len -= 1;
if (tvb_length_remaining(tvb, offset)>0) {
blockdesc_tvb = tvb_new_subset(tvb, offset, MIN(tvb_length_remaining(tvb, offset),desclen), desclen);
dissect_scsi_blockdescs(blockdesc_tvb, pinfo, tree, cdata, FALSE);
}
offset += desclen;
payload_len -= desclen;
while ((payload_len > 0) && tvb_bytes_exist(tvb, offset, 2)) {
plen = dissect_scsi_modepage(tvb, pinfo, tree, offset, cdata->itl->cmdset&SCSI_CMDSET_MASK);
offset += plen;
payload_len -= plen;
}
}
}
void
dissect_spc_modeselect10(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len, scsi_task_data_t *cdata)
{
guint8 flags;
gboolean longlba;
gint tot_len, desclen;
guint plen;
tvbuff_t *blockdesc_tvb;
if (!tree)
return;
if (isreq && iscdb) {
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_scsi_modesel_flags, tvb, offset, 1,
flags, "PF = %u, SP = %u", flags & 0x10,
flags & 0x1);
proto_tree_add_item(tree, hf_scsi_paramlen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else {
if (payload_len < 1)
return;
tot_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Mode Data Length: %u",
tot_len);
offset += 2;
payload_len -= 2;
if (payload_len < 1)
return;
if (!cdata->itl)
return;
switch (cdata->itl->cmdset&SCSI_CMDSET_MASK) {
case SCSI_DEV_SBC:
proto_tree_add_text(tree, tvb, offset, 1, "Medium Type: %s",
val_to_str(tvb_get_guint8(tvb, offset),
scsi_modesense_medtype_sbc_val,
"Unknown (0x%02x)"));
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Medium Type: 0x%02x",
tvb_get_guint8(tvb, offset));
break;
}
offset += 1;
payload_len -= 1;
if (payload_len < 1)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"Device-Specific Parameter: 0x%02x",
tvb_get_guint8(tvb, offset));
offset += 1;
payload_len -= 1;
if (payload_len < 1)
return;
longlba = tvb_get_guint8(tvb, offset) & 0x1;
proto_tree_add_text(tree, tvb, offset, 1, "LongLBA: %u", longlba);
offset += 2;
payload_len -= 2;
if (payload_len < 1)
return;
desclen = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2,
"Block Descriptor Length: %u", desclen);
offset += 2;
payload_len -= 2;
if (tvb_length_remaining(tvb, offset)>0) {
blockdesc_tvb = tvb_new_subset(tvb, offset, MIN(tvb_length_remaining(tvb, offset),desclen), desclen);
dissect_scsi_blockdescs(blockdesc_tvb, pinfo, tree, cdata, longlba);
}
offset += desclen;
payload_len -= desclen;
while ((payload_len > 0) && tvb_bytes_exist(tvb, offset, 2)) {
plen = dissect_scsi_modepage(tvb, pinfo, tree, offset, cdata->itl->cmdset&SCSI_CMDSET_MASK);
offset += plen;
payload_len -= plen;
}
}
}
static void
dissect_scsi_pagecode(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset,
scsi_task_data_t *cdata)
{
guint8 pcode;
int hf_pagecode;
if (!cdata)
return;
pcode = tvb_get_guint8(tvb, offset);
if (match_strval(pcode & SCSI_MS_PCODE_BITS,
scsi_spc_modepage_val) == NULL) {
switch (cdata->itl->cmdset&SCSI_CMDSET_MASK) {
case SCSI_DEV_SBC:
hf_pagecode = hf_scsi_sbcpagecode;
break;
case SCSI_DEV_SSC:
hf_pagecode = hf_scsi_sscpagecode;
break;
case SCSI_DEV_SMC:
hf_pagecode = hf_scsi_smcpagecode;
break;
case SCSI_DEV_CDROM:
hf_pagecode = hf_scsi_mmcpagecode;
break;
default:
hf_pagecode = hf_scsi_spcpagecode;
break;
}
} else {
hf_pagecode = hf_scsi_spcpagecode;
}
proto_tree_add_uint(tree, hf_pagecode, tvb, offset, 1, pcode);
}
void
dissect_spc_modesense6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len, scsi_task_data_t *cdata)
{
guint8 flags;
guint plen;
gint tot_len, desclen;
tvbuff_t *blockdesc_tvb;
if (!tree)
return;
if (isreq && iscdb) {
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_scsi_modesns_flags, tvb, offset, 1,
flags, "DBD = %u", flags & 0x8);
proto_tree_add_item(tree, hf_scsi_modesns_pc, tvb, offset+1, 1, ENC_BIG_ENDIAN);
dissect_scsi_pagecode(tvb, pinfo, tree, offset+1, cdata);
proto_tree_add_item(tree, hf_scsi_alloclen, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else {
tot_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Mode Data Length: %u",
tot_len);
offset += 1;
if (payload_len && (tot_len > (gint)payload_len))
tot_len = payload_len;
if (tot_len < 1)
return;
proto_tree_add_text(tree, tvb, offset, 1, "Medium Type: 0x%02x",
tvb_get_guint8(tvb, offset));
offset += 1;
tot_len -= 1;
if (tot_len < 1)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"Device-Specific Parameter: 0x%02x",
tvb_get_guint8(tvb, offset));
offset += 1;
tot_len -= 1;
if (tot_len < 1)
return;
desclen = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Block Descriptor Length: %d", desclen);
offset += 1;
tot_len -= 1;
if (tvb_length_remaining(tvb, offset)>0) {
blockdesc_tvb = tvb_new_subset(tvb, offset, MIN(tvb_length_remaining(tvb, offset),desclen), desclen);
dissect_scsi_blockdescs(blockdesc_tvb, pinfo, tree, cdata, FALSE);
}
offset += desclen;
tot_len -= desclen;
while ((tot_len > 0) && tvb_bytes_exist(tvb, offset, 2)) {
plen = dissect_scsi_modepage(tvb, pinfo, tree, offset, cdata->itl->cmdset&SCSI_CMDSET_MASK);
offset += plen;
tot_len -= plen;
}
}
}
void
dissect_spc_modesense10(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len, scsi_task_data_t *cdata)
{
guint8 flags;
gboolean longlba;
gint tot_len, desclen;
guint plen;
tvbuff_t *blockdesc_tvb;
if (!tree)
return;
if (isreq && iscdb) {
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_scsi_modesns_flags, tvb, offset, 1,
flags, "LLBAA = %u, DBD = %u", flags & 0x10,
flags & 0x8);
proto_tree_add_item(tree, hf_scsi_modesns_pc, tvb, offset+1, 1, ENC_BIG_ENDIAN);
dissect_scsi_pagecode(tvb, pinfo, tree, offset+1, cdata);
proto_tree_add_item(tree, hf_scsi_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else {
tot_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Mode Data Length: %u",
tot_len);
offset += 2;
if (payload_len && (tot_len > (gint)payload_len))
tot_len = payload_len;
if (tot_len < 1)
return;
proto_tree_add_text(tree, tvb, offset, 1, "Medium Type: 0x%02x",
tvb_get_guint8(tvb, offset));
offset += 1;
tot_len -= 1;
if (tot_len < 1)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"Device-Specific Parameter: 0x%02x",
tvb_get_guint8(tvb, offset));
offset += 1;
tot_len -= 1;
if (tot_len < 1)
return;
longlba = tvb_get_guint8(tvb, offset) & 0x1;
proto_tree_add_text(tree, tvb, offset, 1, "LongLBA: %u", longlba);
offset += 2;
tot_len -= 2;
if (tot_len < 1)
return;
desclen = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Block Descriptor Length: %u", desclen);
offset += 2;
tot_len -= 2;
if (tvb_length_remaining(tvb, offset)>0) {
blockdesc_tvb = tvb_new_subset(tvb, offset, MIN(tvb_length_remaining(tvb, offset),desclen), desclen);
dissect_scsi_blockdescs(blockdesc_tvb, pinfo, tree, cdata, longlba);
}
offset += desclen;
tot_len -= desclen;
while ((tot_len > 0) && tvb_bytes_exist(tvb, offset, 2)) {
plen = dissect_scsi_modepage(tvb, pinfo, tree, offset, cdata->itl->cmdset&SCSI_CMDSET_MASK);
offset += plen;
tot_len -= plen;
}
}
}
void
dissect_spc_preventallowmediaremoval(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 flags;
if (!tree)
return;
if (isreq && iscdb) {
flags = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset+3, 1,
"Persistent: %u, Prevent: %u",
flags & 0x02, flags & 0x01);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_spc_persistentreservein(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len, scsi_task_data_t *cdata)
{
guint16 flags;
int numrec, i;
guint len;
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item(tree, hf_scsi_persresvin_svcaction, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_alloclen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
cdata->itlq->flags = tvb_get_guint8(tvb, offset);
}
else {
if (cdata) {
flags = cdata->itlq->flags;
}
else {
flags = 0xFF;
}
proto_tree_add_text(tree, tvb, offset, 4, "Generation Number: 0x%08x",
tvb_get_ntohl(tvb, offset));
len = tvb_get_ntohl(tvb, offset+4);
proto_tree_add_text(tree, tvb, offset+4, 4, "Additional Length: %u",
len);
len = (payload_len > len) ? len : payload_len;
if ((flags & 0x1F) == SCSI_SPC_RESVIN_SVCA_RDKEYS) {
numrec = len / 8;
offset += 8;
for (i = 0; i < numrec; i++) {
proto_tree_add_item(tree, hf_scsi_persresv_key, tvb, offset,
8, ENC_NA);
offset += 8;
}
}
else if ((flags & 0x1F) == SCSI_SPC_RESVIN_SVCA_RDRESV) {
proto_tree_add_item(tree, hf_scsi_persresv_key, tvb, offset+8,
8, ENC_NA);
proto_tree_add_item(tree, hf_scsi_persresv_scopeaddr, tvb,
offset+8, 4, ENC_NA);
proto_tree_add_item(tree, hf_scsi_persresv_scope, tvb, offset+13,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_persresv_type, tvb, offset+13,
1, ENC_BIG_ENDIAN);
}
}
}
void
dissect_spc_persistentreserveout(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item(tree, hf_scsi_persresvout_svcaction, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_persresv_scope, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_persresv_type, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_paramlen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
cdata->itlq->flags = tvb_get_guint8(tvb, offset);
}
else if (isreq && !iscdb) {
proto_tree_add_item(tree, hf_scsi_persresvout_reskey, tvb, offset,
8, ENC_NA);
proto_tree_add_item(tree, hf_scsi_persresvout_sareskey, tvb,
offset +8, 8, ENC_NA);
if (cdata->itlq->flags == 0x07) {
const int *persresv_fields[] = {
&hf_scsi_persresv_control_rsvd,
&hf_scsi_persresv_control_unreg,
&hf_scsi_persresv_control_aptpl,
NULL
};
proto_tree_add_item(tree, hf_scsi_persresvout_obsolete, tvb,
offset+16, 1, ENC_NA);
proto_tree_add_bitmask(tree, tvb, offset+17,
hf_scsi_persresvout_control, ett_persresv_control,
persresv_fields, ENC_BIG_ENDIAN);
}
else {
const int *persresv_fields[] = {
&hf_scsi_persresv_control_rsvd1,
&hf_scsi_persresv_control_spec_i_pt,
&hf_scsi_persresv_control_all_tg_pt,
&hf_scsi_persresv_control_rsvd2,
&hf_scsi_persresv_control_aptpl,
NULL
};
proto_tree_add_item(tree, hf_scsi_persresvout_obsolete, tvb,
offset+16, 4, ENC_NA);
proto_tree_add_bitmask(tree, tvb, offset+20,
hf_scsi_persresvout_control, ett_persresv_control,
persresv_fields, ENC_BIG_ENDIAN);
}
}
else {
}
}
void
dissect_spc_release6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_spc_release10(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 flags;
if (!tree)
return;
if (isreq && iscdb) {
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_scsi_release_flags, tvb, offset, 1,
flags,
"Flags: 3rd Party ID = %u, LongID = %u",
flags & 0x10, flags & 0x2);
if ((flags & 0x12) == 0x10) {
proto_tree_add_item(tree, hf_scsi_release_thirdpartyid, tvb,
offset+2, 1, ENC_NA);
}
proto_tree_add_item(tree, hf_scsi_paramlen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_spc_reportdeviceidentifier(tvbuff_t *tvb _U_, packet_info *pinfo _U_,
proto_tree *tree _U_,
guint offset _U_, gboolean isreq _U_, gboolean iscdb _U_,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
}
void
dissect_spc_reportluns(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset,
gboolean isreq, gboolean iscdb, guint payload_len _U_,
scsi_task_data_t *cdata _U_)
{
gint listlen;
tvbuff_t *volatile tvb_v = tvb;
volatile guint offset_v = offset;
if (isreq && iscdb) {
proto_tree_add_item(tree, hf_scsi_select_report, tvb_v, offset_v+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_alloclen32, tvb_v, offset_v+5, 4, ENC_BIG_ENDIAN);
if (cdata) {
cdata->itlq->alloc_len = tvb_get_ntohl(tvb_v, offset_v+5);
}
proto_tree_add_bitmask(tree, tvb, offset_v+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
} else if (!isreq) {
if (!cdata) {
return;
}
TRY_SCSI_CDB_ALLOC_LEN(pinfo, tvb_v, offset_v, cdata->itlq->alloc_len);
listlen = tvb_get_ntohl(tvb_v, offset_v);
proto_tree_add_text(tree, tvb_v, offset_v, 4, "LUN List Length: %u",
listlen);
offset_v += 8;
while(listlen>0) {
if (!tvb_get_guint8(tvb_v, offset_v))
proto_tree_add_item(tree, hf_scsi_rluns_lun, tvb_v, offset_v+1, 1,
ENC_BIG_ENDIAN);
else
proto_tree_add_item(tree, hf_scsi_rluns_multilun, tvb_v, offset_v,
8, ENC_NA);
offset_v+=8;
listlen-=8;
}
END_TRY_SCSI_CDB_ALLOC_LEN;
}
}
static void
dissect_scsi_fix_snsinfo(tvbuff_t *tvb, proto_tree *sns_tree, guint offset)
{
proto_item *hidden_item;
guint8 flags;
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_text(sns_tree, tvb, offset, 1, "Valid: %u",
(flags & 0x80) >> 7);
proto_tree_add_item(sns_tree, hf_scsi_sns_errtype, tvb, offset, 1, ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(sns_tree, tvb, offset+2, 1,
"Filemark: %u, EOM: %u, ILI: %u",
(flags & 0x80) >> 7, (flags & 0x40) >> 6,
(flags & 0x20) >> 5);
proto_tree_add_item(sns_tree, hf_scsi_snskey, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sns_tree, hf_scsi_snsinfo, tvb, offset+3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sns_tree, hf_scsi_addlsnslen, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(sns_tree, tvb, offset+8, 4,
"Command-Specific Information: %s",
tvb_bytes_to_str(tvb, offset+8, 4));
proto_tree_add_item(sns_tree, hf_scsi_ascascq, tvb, offset+12, 2, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_item(sns_tree, hf_scsi_asc, tvb, offset+12, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(sns_tree, hf_scsi_ascq, tvb, offset+13, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(sns_tree, hf_scsi_fru, tvb, offset+14, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sns_tree, hf_scsi_sksv, tvb, offset+15, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(sns_tree, tvb, offset+15, 3,
"Sense Key Specific: %s",
tvb_bytes_to_str(tvb, offset+15, 3));
}
void
dissect_spc_requestsense(tvbuff_t * tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item(tree, hf_scsi_alloclen, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else if (!isreq)
dissect_scsi_fix_snsinfo(tvb, tree, offset);
}
void
dissect_spc_reserve6(tvbuff_t * tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_spc_reserve10(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint8 flags;
if (!tree)
return;
if (isreq && iscdb) {
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_scsi_release_flags, tvb, offset, 1,
flags,
"Flags: 3rd Party ID = %u, LongID = %u",
flags & 0x10, flags & 0x2);
if ((flags & 0x12) == 0x10) {
proto_tree_add_item(tree, hf_scsi_release_thirdpartyid, tvb,
offset+2, 1, ENC_NA);
}
proto_tree_add_item(tree, hf_scsi_paramlen16, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_spc_testunitready(tvbuff_t * tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_spc_senddiagnostic(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb _U_,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree && !isreq)
return;
proto_tree_add_uint(tree, hf_scsi_senddiag_st_code, tvb, offset, 1, 0);
proto_tree_add_boolean(tree, hf_scsi_senddiag_pf, tvb, offset, 1, 0);
proto_tree_add_boolean(tree, hf_scsi_senddiag_st, tvb, offset, 1, 0);
proto_tree_add_boolean(tree, hf_scsi_senddiag_devoff, tvb, offset, 1, 0);
proto_tree_add_boolean(tree, hf_scsi_senddiag_unitoff, tvb, offset, 1, 0);
proto_tree_add_uint(tree, hf_scsi_paramlen16, tvb, offset+2, 2, 0);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
void
dissect_spc_writebuffer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb _U_,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree && !isreq)
return;
proto_tree_add_uint(tree, hf_scsi_wb_mode, tvb, offset, 1, 0);
proto_tree_add_uint(tree, hf_scsi_wb_bufferid, tvb, offset+1, 1, 0);
proto_tree_add_uint(tree, hf_scsi_wb_bufoffset, tvb, offset+2, 3, 0);
proto_tree_add_uint(tree, hf_scsi_paramlen24, tvb, offset+5, 3, 0);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
static void
dissect_scsi_varlencdb(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item(tree, hf_scsi_control, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_add_cdblen, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_svcaction, tvb, offset+7, 2, ENC_BIG_ENDIAN);
}
}
void
dissect_scsi_rsp(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, itlq_nexus_t *itlq, itl_nexus_t *itl,
guint8 scsi_status)
{
proto_item *ti;
proto_tree *scsi_tree = NULL;
cmdset_t *csdata;
scsi_task_data_t *cdata;
cdata = ep_alloc(sizeof(scsi_task_data_t));
cdata->itl = itl;
cdata->itlq = itlq;
cdata->type = SCSI_PDU_TYPE_RSP;
tap_queue_packet(scsi_tap, pinfo, cdata);
csdata = get_cmdset_data(itlq, itl);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_scsi, tvb, 0,
0, "SCSI Response (%s)",
val_to_str(itlq->scsi_opcode,
csdata->cdb_vals,
"CDB:0x%02x"));
scsi_tree = proto_item_add_subtree(ti, ett_scsi);
}
ti = proto_tree_add_uint(scsi_tree, hf_scsi_lun, tvb, 0, 0, itlq->lun);
PROTO_ITEM_SET_GENERATED(ti);
if (itl) {
ti = proto_tree_add_uint_format(scsi_tree, hf_scsi_inq_devtype, tvb, 0, 0, itl->cmdset&SCSI_CMDSET_MASK, "Command Set:%s (0x%02x) %s", val_to_str(itl->cmdset&SCSI_CMDSET_MASK, scsi_devtype_val, "Unknown (%d)"), itl->cmdset&SCSI_CMDSET_MASK,itl->cmdset&SCSI_CMDSET_DEFAULT?"(Using default commandset)":"");
PROTO_ITEM_SET_GENERATED(ti);
if (itlq->scsi_opcode != 0xffff) {
ti = proto_tree_add_uint(scsi_tree, csdata->hf_opcode, tvb, 0, 0, itlq->scsi_opcode);
PROTO_ITEM_SET_GENERATED(ti);
}
}
if (itlq->first_exchange_frame) {
nstime_t delta_time;
ti = proto_tree_add_uint(scsi_tree, hf_scsi_request_frame, tvb, 0, 0, itlq->first_exchange_frame);
PROTO_ITEM_SET_GENERATED(ti);
nstime_delta(&delta_time, &pinfo->fd->abs_ts, &itlq->fc_time);
ti = proto_tree_add_time(scsi_tree, hf_scsi_time, tvb, 0, 0, &delta_time);
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_uint(scsi_tree, hf_scsi_status, tvb, 0, 0, scsi_status);
PROTO_ITEM_SET_GENERATED(ti);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "SCSI: Response LUN: 0x%02x (%s) (%s)", itlq->lun,
val_to_str(itlq->scsi_opcode, csdata->cdb_vals, "CDB:0x%02x"),
val_to_str(scsi_status, scsi_status_val, "Unknown (0x%08x)"));
col_set_fence(pinfo->cinfo, COL_INFO);
}
}
void
dissect_scsi_snsinfo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, guint snslen, itlq_nexus_t *itlq, itl_nexus_t *itl)
{
proto_item *ti;
proto_tree *sns_tree = NULL;
const char *old_proto;
scsi_task_data_t *cdata;
cdata = ep_alloc(sizeof(scsi_task_data_t));
cdata->itl = itl;
cdata->itlq = itlq;
cdata->type = SCSI_PDU_TYPE_SNS;
tap_queue_packet(scsi_tap, pinfo, cdata);
old_proto = pinfo->current_proto;
pinfo->current_proto="SCSI";
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_scsi, tvb, offset,
snslen, "SCSI: SNS Info");
sns_tree = proto_item_add_subtree(ti, ett_scsi);
}
ti = proto_tree_add_uint(sns_tree, hf_scsi_lun, tvb, 0, 0, itlq->lun);
PROTO_ITEM_SET_GENERATED(ti);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " LUN:0x%02x ", itlq->lun);
col_set_fence(pinfo->cinfo, COL_INFO);
}
dissect_scsi_fix_snsinfo(tvb, sns_tree, offset);
pinfo->current_proto = old_proto;
}
void
dissect_scsi_cdb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint devtype_arg _U_, itlq_nexus_t *itlq, itl_nexus_t *itl)
{
int offset = 0;
proto_item *ti;
proto_tree *scsi_tree = NULL;
guint8 opcode;
#if 0
scsi_device_type devtype;
#endif
const gchar *valstr;
scsi_task_data_t *cdata;
const char *old_proto;
cmdset_t *csdata;
old_proto = pinfo->current_proto;
pinfo->current_proto="SCSI";
if (!itlq) {
DISSECTOR_ASSERT_NOT_REACHED();
}
if (!itl) {
DISSECTOR_ASSERT_NOT_REACHED();
}
opcode = tvb_get_guint8(tvb, offset);
itlq->scsi_opcode = opcode;
csdata = get_cmdset_data(itlq, itl);
#if 0
if (devtype_arg != SCSI_DEV_UNKNOWN) {
devtype = devtype_arg;
} else {
if (itl) {
devtype = itl->cmdset;
} else {
devtype = (scsi_device_type)scsi_def_devtype;
}
}
#endif
if ((valstr = match_strval(opcode, scsi_spc_vals)) == NULL) {
valstr = match_strval(opcode, csdata->cdb_vals);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
if (valstr != NULL) {
col_add_fstr(pinfo->cinfo, COL_INFO, "SCSI: %s LUN: 0x%02x ", valstr, itlq->lun);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "SCSI Command: 0x%02x LUN:0x%02x ", opcode, itlq->lun);
}
col_set_fence(pinfo->cinfo, COL_INFO);
}
cdata = ep_alloc(sizeof(scsi_task_data_t));
cdata->itl = itl;
cdata->itlq = itlq;
cdata->type = SCSI_PDU_TYPE_CDB;
tap_queue_packet(scsi_tap, pinfo, cdata);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_scsi, tvb, 0,
-1, "SCSI CDB %s",
val_to_str(opcode,
csdata->cdb_vals,
"0x%02x")
);
scsi_tree = proto_item_add_subtree(ti, ett_scsi);
}
ti = proto_tree_add_uint(scsi_tree, hf_scsi_lun, tvb, 0, 0, itlq->lun);
PROTO_ITEM_SET_GENERATED(ti);
if (itl) {
ti = proto_tree_add_uint_format(scsi_tree, hf_scsi_inq_devtype, tvb, 0, 0, itl->cmdset&SCSI_CMDSET_MASK, "Command Set:%s (0x%02x) %s", val_to_str(itl->cmdset&SCSI_CMDSET_MASK, scsi_devtype_val, "Unknown (%d)"), itl->cmdset&SCSI_CMDSET_MASK,itl->cmdset&SCSI_CMDSET_DEFAULT?"(Using default commandset)":"");
PROTO_ITEM_SET_GENERATED(ti);
}
if (itlq->last_exchange_frame) {
ti = proto_tree_add_uint(scsi_tree, hf_scsi_response_frame, tvb, 0, 0, itlq->last_exchange_frame);
PROTO_ITEM_SET_GENERATED(ti);
}
if (valstr != NULL) {
proto_tree_add_uint_format(scsi_tree, csdata->hf_opcode, tvb,
offset, 1,
tvb_get_guint8(tvb, offset),
"Opcode: %s (0x%02x)", valstr,
opcode);
} else {
proto_tree_add_item(scsi_tree, hf_scsi_spcopcode, tvb, offset, 1, ENC_BIG_ENDIAN);
}
if (csdata->cdb_table[opcode].func) {
csdata->cdb_table[opcode].func(tvb, pinfo, scsi_tree, offset+1,
TRUE, TRUE, 0, cdata);
} else if (spc[opcode].func) {
spc[opcode].func(tvb, pinfo, scsi_tree, offset+1,
TRUE, TRUE, 0, cdata);
} else {
call_dissector(data_handle, tvb, pinfo, scsi_tree);
}
pinfo->current_proto = old_proto;
}
void
dissect_scsi_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean isreq, itlq_nexus_t *itlq, itl_nexus_t *itl,
guint32 relative_offset)
{
int offset = 0;
proto_item *ti;
proto_tree *scsi_tree = NULL;
guint8 opcode;
scsi_task_data_t *cdata;
int payload_len;
const char *old_proto;
cmdset_t *csdata;
guint32 expected_length;
fragment_data *ipfd_head;
tvbuff_t *next_tvb = tvb;
gboolean update_col_info = TRUE;
gboolean more_frags = FALSE;
if (!itlq || !itl) {
proto_tree_add_text(tree, tvb, offset, 0, "Unknown SCSI exchange, can not decode SCSI data");
return;
}
payload_len = tvb_length(tvb);
cdata = ep_alloc(sizeof(scsi_task_data_t));
cdata->itl = itl;
cdata->itlq = itlq;
cdata->type = SCSI_PDU_TYPE_CDB;
tap_queue_packet(scsi_tap, pinfo, cdata);
csdata = get_cmdset_data(itlq, itl);
old_proto = pinfo->current_proto;
pinfo->current_proto="SCSI";
opcode = (guint8) cdata->itlq->scsi_opcode;
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_scsi, tvb, offset,
payload_len,
"SCSI Payload (%s %s)",
val_to_str(opcode,
csdata->cdb_vals,
"CDB:0x%02x"),
isreq ? "Request Data" : "Response Data");
scsi_tree = proto_item_add_subtree(ti, ett_scsi);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"SCSI: Data %s LUN: 0x%02x (%s %s) ",
isreq ? "Out" : "In",
itlq->lun,
val_to_str(opcode, csdata->cdb_vals, "0x%02x"),
isreq ? "Request Data" : "Response Data");
col_set_fence(pinfo->cinfo, COL_INFO);
}
ti = proto_tree_add_uint(scsi_tree, hf_scsi_lun, tvb, 0, 0, itlq->lun);
PROTO_ITEM_SET_GENERATED(ti);
if (itl) {
ti = proto_tree_add_uint_format(scsi_tree, hf_scsi_inq_devtype, tvb, 0, 0, itl->cmdset&SCSI_CMDSET_MASK,
"Command Set:%s (0x%02x) %s",
val_to_str(itl->cmdset&SCSI_CMDSET_MASK, scsi_devtype_val, "Unknown (%d)"),
itl->cmdset&SCSI_CMDSET_MASK,
itl->cmdset&SCSI_CMDSET_DEFAULT ? "(Using default commandset)" : "");
PROTO_ITEM_SET_GENERATED(ti);
if (itlq && (itlq->scsi_opcode != 0xffff)) {
ti = proto_tree_add_uint(scsi_tree, csdata->hf_opcode, tvb, 0, 0, itlq->scsi_opcode);
PROTO_ITEM_SET_GENERATED(ti);
}
}
if (itlq->first_exchange_frame) {
ti = proto_tree_add_uint(scsi_tree, hf_scsi_request_frame, tvb, 0, 0, itlq->first_exchange_frame);
PROTO_ITEM_SET_GENERATED(ti);
}
if (itlq->last_exchange_frame) {
ti = proto_tree_add_uint(scsi_tree, hf_scsi_response_frame, tvb, 0, 0, itlq->last_exchange_frame);
PROTO_ITEM_SET_GENERATED(ti);
}
if ( !itlq->first_exchange_frame ) {
call_dissector(data_handle, tvb, pinfo, scsi_tree);
goto end_of_payload;
}
if (!scsi_defragment) {
if (relative_offset) {
call_dissector(data_handle, tvb, pinfo, scsi_tree);
goto end_of_payload;
} else {
goto dissect_the_payload;
}
}
if (tvb_length_remaining(tvb, offset) != tvb_reported_length_remaining(tvb, offset)) {
if (relative_offset) {
call_dissector(data_handle, tvb, pinfo, scsi_tree);
goto end_of_payload;
} else {
goto dissect_the_payload;
}
}
if ( (itlq->task_flags&(SCSI_DATA_READ|SCSI_DATA_WRITE)) == (SCSI_DATA_READ|SCSI_DATA_WRITE) ) {
if (isreq) {
expected_length = itlq->data_length;
} else {
expected_length = itlq->bidir_data_length;
}
} else {
expected_length = itlq->data_length;
}
if ( (!relative_offset) && ((guint32)tvb_length_remaining(tvb, offset) == expected_length) ) {
goto dissect_the_payload;
}
if (tvb_length_remaining(tvb, offset) < 0) {
goto end_of_payload;
}
if ((tvb_length_remaining(tvb,offset) + relative_offset) != expected_length) {
more_frags = TRUE;
}
ipfd_head = fragment_add_check(tvb, offset, pinfo,
itlq->first_exchange_frame,
scsi_fragment_table,
scsi_reassembled_table,
relative_offset,
tvb_length_remaining(tvb, offset),
more_frags);
next_tvb = process_reassembled_data(tvb, offset, pinfo, "Reassembled SCSI DATA", ipfd_head, &scsi_frag_items, &update_col_info, tree);
if ( ipfd_head && (ipfd_head->reassembled_in != pinfo->fd->num) ) {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_prepend_fstr(pinfo->cinfo, COL_INFO, "[Reassembled in #%u] ",
ipfd_head->reassembled_in);
}
}
dissect_the_payload:
if (!next_tvb) {
goto end_of_payload;
}
if (tree == NULL) {
if (opcode == SCSI_SPC_INQUIRY) {
dissect_spc_inquiry(next_tvb, pinfo, scsi_tree, offset, isreq,
FALSE, payload_len, cdata);
}
} else {
if (csdata->cdb_table && (csdata->cdb_table)[opcode].func) {
(csdata->cdb_table)[opcode].func(next_tvb, pinfo, scsi_tree, offset,
isreq, FALSE, payload_len, cdata);
} else if (spc[opcode].func) {
spc[opcode].func(next_tvb, pinfo, scsi_tree, offset,
isreq, FALSE, payload_len, cdata);
} else {
call_dissector(data_handle, next_tvb, pinfo, scsi_tree);
}
}
end_of_payload:
pinfo->current_proto = old_proto;
}
static cmdset_t *
get_cmdset_data(itlq_nexus_t *itlq, itl_nexus_t *itl)
{
cmdset_t *csdata;
guint8 cmdset;
if (!itlq) {
DISSECTOR_ASSERT_NOT_REACHED();
}
if (itl) {
if (itl->cmdset == 0xff) {
itl->cmdset = scsi_def_devtype|SCSI_CMDSET_DEFAULT;
}
cmdset = itl->cmdset;
} else {
cmdset = scsi_def_devtype;
}
csdata = ep_alloc(sizeof(cmdset_t));
switch(cmdset&SCSI_CMDSET_MASK) {
case SCSI_DEV_SBC:
csdata->hf_opcode = hf_scsi_sbc_opcode;
csdata->cdb_vals = scsi_sbc_vals;
csdata->cdb_table = scsi_sbc_table;
break;
case SCSI_DEV_CDROM:
csdata->hf_opcode = hf_scsi_mmc_opcode;
csdata->cdb_vals = scsi_mmc_vals;
csdata->cdb_table = scsi_mmc_table;
break;
case SCSI_DEV_SSC:
csdata->hf_opcode = hf_scsi_ssc_opcode;
csdata->cdb_vals = scsi_ssc_vals;
csdata->cdb_table = scsi_ssc_table;
break;
case SCSI_DEV_SMC:
csdata->hf_opcode = hf_scsi_smc_opcode;
csdata->cdb_vals = scsi_smc_vals;
csdata->cdb_table = scsi_smc_table;
break;
case SCSI_DEV_OSD:
csdata->hf_opcode = hf_scsi_osd_opcode;
csdata->cdb_vals = scsi_osd_vals;
csdata->cdb_table = scsi_osd_table;
break;
default:
csdata->hf_opcode = hf_scsi_spcopcode;
csdata->cdb_vals = scsi_spc_vals;
csdata->cdb_table = spc;
break;
}
return csdata;
}
void
proto_register_scsi(void)
{
static hf_register_info hf[] = {
{ &hf_scsi_lun,
{"LUN", "scsi.lun", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_status,
{ "Status", "scsi.status", FT_UINT8, BASE_HEX,
VALS(scsi_status_val), 0, "SCSI command status value", HFILL }},
{ &hf_scsi_spcopcode,
{"SPC-2 Opcode", "scsi.spc.opcode", FT_UINT8, BASE_HEX,
VALS(scsi_spc_vals), 0x0, NULL, HFILL}},
{ &hf_scsi_control,
{"Control", "scsi.cdb.control", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_control_vendor_specific,
{"Vendor specific", "scsi.cdb.control.vendorspecific", FT_UINT8,
BASE_HEX, NULL, 0xC0, NULL, HFILL}},
{ &hf_scsi_control_reserved,
{"Reserved", "scsi.cdb.control.reserved", FT_UINT8, BASE_HEX, NULL,
0x38, NULL, HFILL}},
{ &hf_scsi_control_naca,
{"NACA", "scsi.cdb.control.naca", FT_BOOLEAN, 8,
TFS(&scsi_naca_tfs), 0x04, NULL, HFILL}},
{ &hf_scsi_control_obs1,
{"Obsolete", "scsi.cdb.control.obs1", FT_UINT8, BASE_HEX,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_control_obs2,
{"Obsolete", "scsi.cdb.control.obs2", FT_UINT8, BASE_HEX,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_inq_control,
{"Control", "scsi.cdb.inq.control", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_inquiry_flags,
{"Inquiry Flags", "scsi.inquiry.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_inquiry_evpd_page,
{"EVPD Page Code", "scsi.inquiry.evpd.pagecode", FT_UINT8, BASE_HEX,
VALS(scsi_evpd_pagecode_val), 0x0, NULL, HFILL}},
{ &hf_scsi_inquiry_cmdt_page,
{"CMDT Page Code", "scsi.inquiry.cmdt.pagecode", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_alloclen,
{"Allocation Length", "scsi.cdb.alloclen", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_paramlen,
{"Parameter Length", "scsi.cdb.paramlen", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_log_pc,
{"Page Control", "scsi.log.pc", FT_UINT8, BASE_DEC,
VALS(scsi_log_pc_val), 0xC0, NULL, HFILL}},
{ &hf_scsi_log_pagecode,
{"Page Code", "scsi.log.pagecode", FT_UINT8, BASE_HEX,
VALS(scsi_log_page_val), 0x3F, NULL, HFILL}},
{ &hf_scsi_paramlen16,
{"Parameter Length", "scsi.cdb.paramlen16", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_modesel_flags,
{"Mode Sense/Select Flags", "scsi.cdb.mode.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_alloclen16,
{"Allocation Length", "scsi.cdb.alloclen16", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_modesns_pc,
{"Page Control", "scsi.mode.pc", FT_UINT8, BASE_DEC,
VALS(scsi_modesns_pc_val), 0xC0, NULL, HFILL}},
{ &hf_scsi_spcpagecode,
{"SPC-2 Page Code", "scsi.mode.spc.pagecode", FT_UINT8, BASE_HEX,
VALS(scsi_spc_modepage_val), 0x3F, NULL, HFILL}},
{ &hf_scsi_sbcpagecode,
{"SBC-2 Page Code", "scsi.mode.sbc.pagecode", FT_UINT8, BASE_HEX,
VALS(scsi_sbc_modepage_val), 0x3F, NULL, HFILL}},
{ &hf_scsi_sscpagecode,
{"SSC-2 Page Code", "scsi.mode.ssc.pagecode", FT_UINT8, BASE_HEX,
VALS(scsi_ssc2_modepage_val), 0x3F, NULL, HFILL}},
{ &hf_scsi_mmcpagecode,
{"MMC-5 Page Code", "scsi.mode.mmc.pagecode", FT_UINT8, BASE_HEX,
VALS(scsi_mmc5_modepage_val), 0x3F, NULL, HFILL}},
{ &hf_scsi_smcpagecode,
{"SMC-2 Page Code", "scsi.mode.smc.pagecode", FT_UINT8, BASE_HEX,
VALS(scsi_smc_modepage_val), 0x3F, NULL, HFILL}},
{ &hf_scsi_modesns_flags,
{"Mode Sense Flags", "scsi.mode.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_persresvin_svcaction,
{"Service Action", "scsi.persresvin.svcaction", FT_UINT8, BASE_HEX,
VALS(scsi_persresvin_svcaction_val), 0x0F, NULL, HFILL}},
{ &hf_scsi_persresvout_svcaction,
{"Service Action", "scsi.persresvout.svcaction", FT_UINT8, BASE_HEX,
VALS(scsi_persresvout_svcaction_val), 0x0F, NULL, HFILL}},
{ &hf_scsi_persresv_scope,
{"Reservation Scope", "scsi.persresv.scope", FT_UINT8, BASE_HEX,
VALS(scsi_persresv_scope_val), 0xF0, NULL, HFILL}},
{ &hf_scsi_persresv_type,
{"Reservation Type", "scsi.persresv.type", FT_UINT8, BASE_HEX,
VALS(scsi_persresv_type_val), 0x0F, NULL, HFILL}},
{ &hf_scsi_persresvout_reskey,
{"Reservation Key", "scsi.persresv.reskey", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_persresvout_sareskey,
{"Service Action Reservation Key", "scsi.persresv.sareskey", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_persresvout_obsolete,
{"Obsolete", "scsi.presresv.obs", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_persresvout_control,
{"Control", "scsi.presresv.control", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_persresv_control_rsvd,
{"Reserved", "scsi.persresv.control.reserved", FT_UINT8, BASE_HEX,
NULL, 0xFC, NULL, HFILL}},
{ &hf_scsi_persresv_control_rsvd1,
{"Reserved", "scsi.persresv.control.reserved1", FT_UINT8, BASE_HEX,
NULL, 0xF0, NULL, HFILL}},
{ &hf_scsi_persresv_control_rsvd2,
{"Reserved", "scsi.persresv.control.reserved2", FT_UINT8, BASE_HEX,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_persresv_control_spec_i_pt,
{"SPEC_I_PT", "scsi.persresv.control.spec_i_pt", FT_BOOLEAN, 8,
TFS(&scsi_spec_i_pt_tfs), 0x08, NULL, HFILL}},
{ &hf_scsi_persresv_control_all_tg_pt,
{"ALL_TG_PT", "scsi.persresv.control.all_tg_pt", FT_BOOLEAN, 8,
TFS(&scsi_all_tg_pt_tfs), 0x04, NULL, HFILL}},
{ &hf_scsi_persresv_control_aptpl,
{"aptpl", "scsi.persresv.control.aptpl", FT_BOOLEAN, 8,
TFS(&scsi_aptpl_tfs), 0x01, NULL, HFILL}},
{ &hf_scsi_release_flags,
{"Release Flags", "scsi.release.flags", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_release_thirdpartyid,
{"Third-Party ID", "scsi.release.thirdpartyid", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_alloclen32,
{"Allocation Length", "scsi.cdb.alloclen32", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_inq_add_len,
{"Additional Length", "scsi.inquiry.add_len", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_inq_qualifier,
{"Qualifier", "scsi.inquiry.qualifier", FT_UINT8, BASE_HEX,
VALS(scsi_qualifier_val), 0xE0, NULL, HFILL}},
{ &hf_scsi_inq_peripheral,
{"Peripheral", "scsi.inquiry.peripheral", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_inq_vendor_id,
{"Vendor Id", "scsi.inquiry.vendor_id", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_inq_product_id,
{"Product Id", "scsi.inquiry.product_id", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_inq_product_rev,
{"Product Revision Level", "scsi.inquiry.product_rev", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_inq_vendor_specific,
{"Vendor Specific", "scsi.inquiry.vendor_specific", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_inq_reserved,
{"Reserved", "scsi.inquiry.reserved", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_inq_version_desc,
{"Version Description", "scsi.inquiry.version_desc", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&scsi_verdesc_val_ext, 0, NULL, HFILL}},
{ &hf_scsi_inq_devtype,
{"Device Type", "scsi.inquiry.devtype", FT_UINT8, BASE_HEX,
VALS(scsi_devtype_val), SCSI_DEV_BITS, NULL, HFILL}},
{ &hf_scsi_inq_rmb,
{"Removable", "scsi.inquiry.removable", FT_BOOLEAN, 8,
TFS(&scsi_removable_val), 0x80, NULL, HFILL}},
{ & hf_scsi_inq_version,
{"Version", "scsi.inquiry.version", FT_UINT8, BASE_HEX,
VALS(scsi_inquiry_vers_val), 0x0, NULL, HFILL}},
{ &hf_scsi_inq_reladrflags,
{"Inquiry RelAdr Flags", "scsi.inquiry.reladrflags", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_inq_reladr,
{"RelAdr", "scsi.inquiry.reladr", FT_BOOLEAN, 8, TFS(&reladr_tfs), SCSI_INQ_RELADRFLAGS_RELADR,
NULL, HFILL}},
{ &hf_scsi_inq_sync,
{"Sync", "scsi.inquiry.sync", FT_BOOLEAN, 8, TFS(&sync_tfs), SCSI_INQ_RELADRFLAGS_SYNC,
NULL, HFILL}},
{ &hf_scsi_inq_linked,
{"Linked", "scsi.inquiry.linked", FT_BOOLEAN, 8, TFS(&linked_tfs), SCSI_INQ_RELADRFLAGS_LINKED,
NULL, HFILL}},
{ &hf_scsi_inq_cmdque,
{"CmdQue", "scsi.inquiry.cmdque", FT_BOOLEAN, 8, TFS(&cmdque_tfs), SCSI_INQ_RELADRFLAGS_CMDQUE,
NULL, HFILL}},
{ &hf_scsi_inq_bqueflags,
{"Inquiry BQue Flags", "scsi.inquiry.bqueflags", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_inq_bque,
{"BQue", "scsi.inquiry.bque", FT_BOOLEAN, 8, TFS(&bque_tfs), SCSI_INQ_BQUEFLAGS_BQUE,
NULL, HFILL}},
{ &hf_scsi_inq_encserv,
{"EncServ", "scsi.inquiry.encserv", FT_BOOLEAN, 8, TFS(&encserv_tfs), SCSI_INQ_BQUEFLAGS_ENCSERV,
NULL, HFILL}},
{ &hf_scsi_inq_multip,
{"MultiP", "scsi.inquiry.multip", FT_BOOLEAN, 8, TFS(&multip_tfs), SCSI_INQ_BQUEFLAGS_MULTIP,
NULL, HFILL}},
{ &hf_scsi_inq_mchngr,
{"MChngr", "scsi.inquiry.mchngr", FT_BOOLEAN, 8, TFS(&mchngr_tfs), SCSI_INQ_BQUEFLAGS_MCHNGR,
NULL, HFILL}},
{ &hf_scsi_inq_sccsflags,
{"Inquiry SCCS Flags", "scsi.inquiry.sccsflags", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_inq_sccs,
{"SCCS", "scsi.inquiry.sccs", FT_BOOLEAN, 8, TFS(&sccs_tfs), SCSI_INQ_SCCSFLAGS_SCCS,
NULL, HFILL}},
{ &hf_scsi_inq_acc,
{"ACC", "scsi.inquiry.acc", FT_BOOLEAN, 8, TFS(&acc_tfs), SCSI_INQ_SCCSFLAGS_ACC,
NULL, HFILL}},
{ &hf_scsi_inq_tpc,
{"3PC", "scsi.inquiry.tpc", FT_BOOLEAN, 8, TFS(&tpc_tfs), SCSI_INQ_SCCSFLAGS_TPC,
NULL, HFILL}},
{ &hf_scsi_inq_protect,
{"Protect", "scsi.inquiry.protect", FT_BOOLEAN, 8, TFS(&protect_tfs), SCSI_INQ_SCCSFLAGS_PROTECT,
NULL, HFILL}},
{ &hf_scsi_inq_tpgs,
{"TPGS", "scsi.inquiry.tpgs", FT_UINT8, BASE_DEC, VALS(inq_tpgs_vals), 0x30,
NULL, HFILL}},
{ &hf_scsi_inq_acaflags,
{"Inquiry ACA Flags", "scsi.inquiry.acaflags", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_inq_control_vendor_specific,
{"Vendor specific", "scsi.inquiry.control.vendorspecific", FT_UINT8,
BASE_HEX, NULL, 0xC0, NULL, HFILL}},
{ &hf_scsi_inq_control_reserved,
{"Reserved", "scsi.inquiry.control.reserved", FT_UINT8, BASE_HEX,
NULL, 0x38, NULL, HFILL}},
{ &hf_scsi_inq_control_naca,
{"NACA", "scsi.inquiry.control.naca", FT_BOOLEAN, 8,
TFS(&scsi_naca_tfs), 0x04, NULL, HFILL}},
{ &hf_scsi_inq_control_obs1,
{"Obsolete", "scsi.inquiry.control.obs1", FT_UINT8, BASE_HEX,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_inq_control_obs2,
{"Obsolete", "scsi.inquiry.control.obs2", FT_UINT8, BASE_HEX,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_inq_rmbflags,
{"Inquiry RMB Flags", "scsi.inquiry.rmbflags", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_inq_normaca,
{"NormACA", "scsi.inquiry.normaca", FT_BOOLEAN, 8, TFS(&normaca_tfs), SCSI_INQ_ACAFLAGS_NORMACA,
NULL, HFILL}},
{ &hf_scsi_inq_hisup,
{"HiSup", "scsi.inquiry.hisup", FT_BOOLEAN, 8, TFS(&hisup_tfs), SCSI_INQ_ACAFLAGS_HISUP,
NULL, HFILL}},
{ &hf_scsi_inq_aerc,
{"AERC", "scsi.inquiry.aerc", FT_BOOLEAN, 8, TFS(&aerc_tfs), SCSI_INQ_ACAFLAGS_AERC,
"AERC is obsolete from SPC-3 and forward", HFILL}},
{ &hf_scsi_inq_trmtsk,
{"TrmTsk", "scsi.inquiry.trmtsk", FT_BOOLEAN, 8, TFS(&trmtsk_tfs), SCSI_INQ_ACAFLAGS_TRMTSK,
"TRMTSK is obsolete from SPC-2 and forward", HFILL}},
{ &hf_scsi_inq_rdf,
{"Response Data Format", "scsi.inquiry.rdf", FT_UINT8, BASE_DEC, VALS(inq_rdf_vals), 0x0f,
NULL, HFILL}},
{ &hf_scsi_rluns_lun,
{"LUN", "scsi.reportluns.lun", FT_UINT8, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_rluns_multilun,
{"Multi-level LUN", "scsi.reportluns.mlun", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_modesns_errrep,
{"MRIE", "scsi.mode.mrie", FT_UINT8, BASE_HEX,
VALS(scsi_modesns_mrie_val), 0x0F, NULL, HFILL}},
{ &hf_scsi_modesns_tst,
{"Task Set Type", "scsi.mode.tst", FT_UINT8, BASE_DEC,
VALS(scsi_modesns_tst_val), 0xE0, NULL, HFILL}},
{ &hf_scsi_modesns_qmod,
{"Queue Algorithm Modifier", "scsi.mode.qmod", FT_UINT8, BASE_HEX,
VALS(scsi_modesns_qmod_val), 0xF0, NULL, HFILL}},
{ &hf_scsi_modesns_qerr,
{"Queue Error Management", "scsi.mode.qerr", FT_BOOLEAN, 8,
TFS(&scsi_modesns_qerr_val), 0x2, NULL, HFILL}},
{ &hf_scsi_modesns_tas,
{"Task Aborted Status", "scsi.mode.tac", FT_BOOLEAN, 8,
TFS(&scsi_modesns_tas_val), 0x80, NULL, HFILL}},
{ &hf_scsi_modesns_rac,
{"Report a Check", "scsi.mode.rac", FT_BOOLEAN, 8,
TFS(&scsi_modesns_rac_val), 0x40, NULL, HFILL}},
{ &hf_scsi_protocol,
{"Protocol", "scsi.proto", FT_UINT8, BASE_DEC, VALS(scsi_proto_val),
0x0F, NULL, HFILL}},
{ &hf_scsi_sns_errtype,
{"SNS Error Type", "scsi.sns.errtype", FT_UINT8, BASE_HEX,
VALS(scsi_sns_errtype_val), 0x7F, NULL, HFILL}},
{ &hf_scsi_snskey,
{"Sense Key", "scsi.sns.key", FT_UINT8, BASE_HEX,
VALS(scsi_sensekey_val), 0x0F, NULL, HFILL}},
{ &hf_scsi_snsinfo,
{"Sense Info", "scsi.sns.info", FT_UINT32, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_scsi_addlsnslen,
{"Additional Sense Length", "scsi.sns.addlen", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_asc,
{"Additional Sense Code", "scsi.sns.asc", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_ascq,
{"Additional Sense Code Qualifier", "scsi.sns.ascq", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_ascascq,
{"Additional Sense Code+Qualifier", "scsi.sns.ascascq", FT_UINT16,
BASE_HEX|BASE_EXT_STRING, &scsi_asc_val_ext, 0x0, NULL, HFILL}},
{ &hf_scsi_fru,
{"Field Replaceable Unit Code", "scsi.sns.fru", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_sksv,
{"SKSV", "scsi.sns.sksv", FT_BOOLEAN, 8, NULL, 0x80, NULL,
HFILL}},
{ &hf_scsi_persresv_key,
{"Reservation Key", "scsi.spc.resv.key", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_persresv_scopeaddr,
{"Scope Address", "scsi.spc.resv.scopeaddr", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_add_cdblen,
{"Additional CDB Length", "scsi.spc.addcdblen", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_svcaction,
{"Service Action", "scsi.spc.svcaction", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_wb_mode,
{"Mode", "scsi.spc.wb.mode", FT_UINT8, BASE_HEX,
VALS(scsi_wb_mode_val), 0xF, NULL, HFILL}},
{ &hf_scsi_wb_bufferid,
{"Buffer ID", "scsi.spc.sb.bufid", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_scsi_wb_bufoffset,
{"Buffer Offset", "scsi.spc.wb.bufoff", FT_UINT24, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_scsi_paramlen24,
{"Parameter List Length", "scsi.cdb.paramlen24", FT_UINT24, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_senddiag_st_code,
{"Self-Test Code", "scsi.spc.senddiag.code", FT_UINT8, BASE_HEX,
VALS(scsi_senddiag_st_code_val), 0xE0, NULL, HFILL}},
{ &hf_scsi_select_report,
{"Select Report", "scsi.spc.select_report", FT_UINT8, BASE_HEX,
VALS(scsi_select_report_val), 0x00, NULL, HFILL}},
{ &hf_scsi_senddiag_pf,
{"PF", "scsi.spc.senddiag.pf", FT_BOOLEAN, 8,
TFS(&scsi_senddiag_pf_val), 0x10, NULL, HFILL}},
{ &hf_scsi_senddiag_st,
{"Self Test", "scsi.spc.senddiag.st", FT_BOOLEAN, 8, NULL,
0x4, NULL, HFILL}},
{ &hf_scsi_senddiag_devoff,
{"Device Offline", "scsi.spc.senddiag.devoff", FT_BOOLEAN, 8,
NULL, 0x2, NULL, HFILL}},
{ &hf_scsi_senddiag_unitoff,
{"Unit Offline", "scsi.spc.senddiag.unitoff", FT_BOOLEAN, 8,
NULL, 0x1, NULL, HFILL}},
{ &hf_scsi_request_frame,
{ "Request in", "scsi.request_frame", FT_FRAMENUM, BASE_NONE, NULL, 0,
"The request to this transaction is in this frame", HFILL }},
{ &hf_scsi_time,
{ "Time from request", "scsi.time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0,
"Time between the Command and the Response", HFILL }},
{ &hf_scsi_response_frame,
{ "Response in", "scsi.response_frame", FT_FRAMENUM, BASE_NONE, NULL, 0,
"The response to this transaction is in this frame", HFILL }},
{ &hf_scsi_fragments,
{ "SCSI Fragments", "scsi.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_scsi_fragment_overlap,
{ "Fragment overlap", "scsi.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{ &hf_scsi_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "scsi.fragment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_scsi_fragment_multiple_tails,
{ "Multiple tail fragments found", "scsi.fragment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_scsi_fragment_too_long_fragment,
{ "Fragment too long", "scsi.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{ &hf_scsi_fragment_error,
{ "Defragmentation error", "scsi.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{ &hf_scsi_fragment_count,
{ "Fragment count", "scsi.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_scsi_fragment,
{ "SCSI DATA Fragment", "scsi.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_scsi_reassembled_in,
{ "Reassembled SCSI DATA in frame", "scsi.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This SCSI DATA packet is reassembled in this frame", HFILL }},
{ &hf_scsi_reassembled_length,
{ "Reassembled SCSI DATA length", "scsi.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{ &hf_scsi_log_ppc_flags,
{"PPC Flags", "scsi.log.ppc.flags", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_log_ppc,
{"PPC", "scsi.log.ppc", FT_BOOLEAN, 8,
TFS(&scsi_log_ppc_tfs), 0x02, NULL, HFILL}},
{ &hf_scsi_log_pcr,
{"PCR", "scsi.log.pcr", FT_BOOLEAN, 8,
TFS(&scsi_log_pcr_tfs), 0x02, NULL, HFILL}},
{ &hf_scsi_log_sp,
{"SP", "scsi.log.sp", FT_BOOLEAN, 8,
TFS(&scsi_log_sp_tfs), 0x01, NULL, HFILL}},
{ &hf_scsi_log_pc_flags,
{"PC Flags", "scsi.log.pc.flags", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_log_parameter_ptr,
{"Parameter Pointer", "scsi.log.param_ptr", FT_UINT8, BASE_HEX, NULL,
0, NULL, HFILL}},
{ &hf_scsi_log_page_length,
{"Page Length", "scsi.log.page_length", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_log_parameter_code,
{"Parameter Code", "scsi.log.parameter_code", FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_log_param_flags,
{"Param Flags", "scsi.log.param.flags", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_log_param_len,
{"Parameter Len", "scsi.log.param_len", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_log_param_data,
{"Parameter Data", "scsi.log.param_data", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_log_pf_du,
{"DU", "scsi.log.pf.du", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL}},
{ &hf_scsi_log_pf_ds,
{"DS", "scsi.log.pf.ds", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL}},
{ &hf_scsi_log_pf_tsd,
{"TSD", "scsi.log.pf.tsd", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL}},
{ &hf_scsi_log_pf_etc,
{"ETC", "scsi.log.pf.etc", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL}},
{ &hf_scsi_log_pf_tmc,
{"TMC", "scsi.log.pf.tmc", FT_UINT8, BASE_HEX, VALS(log_flags_tmc_vals), 0x0c,
NULL, HFILL}},
{ &hf_scsi_log_pf_lbin,
{"LBIN", "scsi.log.pf.lbin", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}},
{ &hf_scsi_log_pf_lp,
{"LP", "scsi.log.pf.lp", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_rw,
{"Read Warning", "scsi.log.ta.rw", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_ww,
{"write warning", "scsi.log.ta.ww", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_he,
{"hard error", "scsi.log.ta.he", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_media,
{"media", "scsi.log.ta.media", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_rf,
{"read failure", "scsi.log.ta.rf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_wf,
{"write failure", "scsi.log.ta.wf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_ml,
{"media life", "scsi.log.ta.ml", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_ndg,
{"not data grade", "scsi.log.ta.ndg", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_wp,
{"write protect", "scsi.log.ta.wp", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_nr,
{"no removal", "scsi.log.ta.nr", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_cm,
{"cleaning media", "scsi.log.ta.cm", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_uf,
{"unsupported format", "scsi.log.ta.uf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_rmcf,
{"removable mechanical cartridge failure", "scsi.log.ta.rmcf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_umcf,
{"unrecoverable mechanical cartridge failure", "scsi.log.ta.umcf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_mcicf,
{"memory chip in cartridge failure", "scsi.log.ta.mcicf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_fe,
{"forced eject", "scsi.log.ta.fe", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_rof,
{"read only format", "scsi.log.ta.rof", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_tdcol,
{"tape directory corrupted on load", "scsi.log.ta.tdcol", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_nml,
{"nearing media life", "scsi.log.ta.nml", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_cn,
{"clean now", "scsi.log.ta.cn", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_cp,
{"clean periodic", "scsi.log.ta.cp", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_ecm,
{"expired cleaning media", "scsi.log.ta.ecm", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_ict,
{"invalid cleaning tape", "scsi.log.ta.ict", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_rr,
{"retention requested", "scsi.log.ta.rr", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_dpie,
{"dual port interface error", "scsi.log.ta.dpie", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_cff,
{"cooling fan failure", "scsi.log.ta.cff", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_psf,
{"power supply failure", "scsi.log.ta.psf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_pc,
{"power consumption", "scsi.log.ta.pc", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_dm,
{"drive maintenance", "scsi.log.ta.dm", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_hwa,
{"hardware a", "scsi.log.ta.hwa", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_hwb,
{"hardware b", "scsi.log.ta.hwb", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_if,
{"interface", "scsi.log.ta.if", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_em,
{"eject media", "scsi.log.ta.em", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_dwf,
{"download failed", "scsi.log.ta.dwf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_drhu,
{"drive humidity", "scsi.log.ta.drhu", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_drtm,
{"drive temperature", "scsi.log.ta.drtm", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_drvo,
{"drive voltage", "scsi.log.ta.drvo", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_pefa,
{"periodic failure", "scsi.log.ta.pefa", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_dire,
{"diagnostics required", "scsi.log.ta.dire", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_lost,
{"lost statistics", "scsi.log.ta.lost", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_tduau,
{"tape directory invalid at unload", "scsi.log.ta.tduau", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_tsawf,
{"tape system area write failure", "scsi.log.ta.tsawf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_tsarf,
{"tape system area read failure", "scsi.log.ta.tsarf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_nsod,
{"no start of data", "scsi.log.ta.nsod", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_lofa,
{"loading failure", "scsi.log.ta.lofa", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_uuf,
{"unrecoverable unload failure", "scsi.log.ta.uuf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_aif,
{"automatic interface failure", "scsi.log.ta.aif", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_fwf,
{"firmware failure", "scsi.log.ta.fwf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_wmicf,
{"worm medium integrity check failed", "scsi.log.ta.wmicf", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_log_ta_wmoa,
{"worm medium overwrite attempted", "scsi.log.ta.wmoa", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_sbc_treshold_exponent,
{"Treshold Exponent", "scsi.sbc.treshold_exponent", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_sbc_lbpu,
{"LBPU", "scsi.sbc.lbpu", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL}},
{ &hf_scsi_sbc_lbpws,
{"LBPWS", "scsi.sbc.lbpws", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL}},
{ &hf_scsi_sbc_lbpws10,
{"LBPWS10", "scsi.sbc.lbpws10", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL}},
{ &hf_scsi_sbc_lbprz,
{"LBPRZ", "scsi.sbc.lbprz", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL}},
{ &hf_scsi_sbc_anc_sup,
{"ANC_SUP", "scsi.sbc.anc_sup", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}},
{ &hf_scsi_sbc_dp,
{"DP", "scsi.sbc.dp", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_sbc_ptype,
{"Provisioning Type", "scsi.sbc.ptype", FT_UINT8, BASE_DEC, VALS(provisioning_vals), 0x07,
NULL, HFILL}},
{ &hf_scsi_block_limits_wsnz,
{"WSNZ", "scsi.sbc.bl.wsnz", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_scsi_block_limits_mcawl,
{"Maximum Compare And Write Length", "scsi.sbc.bl.mcawl", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_block_limits_otlg,
{"Optimal Transfer Length Granularity", "scsi.sbc.bl.otlg", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_block_limits_mtl,
{"Maximum Transfer Length", "scsi.sbc.bl.mtl", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_block_limits_otl,
{"Optimal Transfer Length", "scsi.sbc.bl.otl", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_block_limits_mpl,
{"Optimal Prefetch/Xdread/Xdwrite Transfer Length", "scsi.sbc.bl.mpl", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_block_limits_mulc,
{"Maximum Unmap LBA Count", "scsi.sbc.bl.mulc", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_block_limits_mubdc,
{"Maximum Unmap Block Descriptor Count", "scsi.sbc.bl.mubdc", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_block_limits_oug,
{"Optimal Unmap Block Granularity", "scsi.sbc.bl.oug", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_scsi_block_limits_ugavalid,
{"UGAVALID", "scsi.sbc.bl.ugavalid", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL}},
{ &hf_scsi_block_limits_uga,
{"Unmap Granularity Alignment", "scsi.sbc.bl.uga", FT_UINT32, BASE_DEC, NULL, 0x7fffffff,
NULL, HFILL}},
{ &hf_scsi_block_limits_mwsl,
{"Maximum Write Same Length", "scsi.sbc.bl.mwsl", FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_scsi,
&ett_scsi_page,
&ett_scsi_control,
&ett_scsi_inq_control,
&ett_scsi_inq_peripheral,
&ett_scsi_inq_acaflags,
&ett_scsi_inq_rmbflags,
&ett_scsi_inq_sccsflags,
&ett_scsi_inq_bqueflags,
&ett_scsi_inq_reladrflags,
&ett_scsi_log,
&ett_scsi_log_ppc,
&ett_scsi_log_pc,
&ett_scsi_log_param,
&ett_scsi_fragments,
&ett_scsi_fragment,
&ett_persresv_control
};
module_t *scsi_module;
proto_scsi = proto_register_protocol("SCSI", "SCSI", "scsi");
proto_register_field_array(proto_scsi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
scsi_module = prefs_register_protocol(proto_scsi, NULL);
prefs_register_enum_preference(scsi_module, "decode_scsi_messages_as",
"Decode SCSI Messages As",
"When Target Cannot Be Identified, Decode SCSI Messages As",
&scsi_def_devtype,
scsi_devtype_options,
FALSE);
prefs_register_bool_preference(scsi_module, "defragment",
"Reassemble fragmented SCSI DATA IN/OUT transfers",
"Whether fragmented SCSI DATA IN/OUT transfers should be reassembled",
&scsi_defragment);
register_init_routine(scsi_defragment_init);
}
void
proto_reg_handoff_scsi(void)
{
scsi_tap = register_tap("scsi");
data_handle = find_dissector("data");
}
