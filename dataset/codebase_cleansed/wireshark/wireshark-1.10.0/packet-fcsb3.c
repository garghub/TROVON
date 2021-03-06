static void
dissect_iui_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint16 flags)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item=proto_tree_add_uint(parent_tree, hf_sbccs_iui,
tvb, offset, 1, flags);
tree=proto_item_add_subtree(item, ett_sbccs_iui);
}
proto_tree_add_boolean(tree, hf_sbccs_iui_as, tvb, offset, 1, flags);
if (flags & 0x10) {
proto_item_append_text(item, " AS");
}
flags &= (~( 0x10 ));
proto_tree_add_boolean(tree, hf_sbccs_iui_es, tvb, offset, 1, flags);
if (flags & 0x08) {
proto_item_append_text(item, " ES");
}
flags &= (~( 0x08 ));
proto_tree_add_item (tree, hf_sbccs_iui_val, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s", val_to_str (flags & 0x7, fc_sbccs_iu_val, "0x%x"));
flags &= (~( 0x07 ));
}
static void
dissect_linkctlinfo (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint16 flags)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item=proto_tree_add_uint(parent_tree, hf_sbccs_dib_linkctlinfo,
tvb, offset, 2, flags);
tree=proto_item_add_subtree(item, ett_sbccs_dib_linkctlinfo);
}
proto_tree_add_boolean(tree, hf_sbccs_dib_linkctlinfo_ctcconn, tvb, offset, 2, flags);
if (flags & 0x80) {
proto_item_append_text(item, " CTC Conn");
}
flags &= (~( 0x80 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_linkctlinfo_ecrcg, tvb, offset, 2, flags);
if (flags & 0x01) {
proto_item_append_text(item, " Enhanced CRC Gen");
}
flags &= (~( 0x01 ));
}
static void
dissect_dh_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint16 flags)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item=proto_tree_add_uint(parent_tree, hf_sbccs_dhflags,
tvb, offset, 1, flags);
tree=proto_item_add_subtree(item, ett_sbccs_dhflags);
}
proto_tree_add_boolean(tree, hf_sbccs_dhflags_end, tvb, offset, 1, flags);
if (flags & 0x80) {
proto_item_append_text(item, " End");
}
flags &= (~( 0x80 ));
proto_tree_add_boolean(tree, hf_sbccs_dhflags_chaining, tvb, offset, 1, flags);
if (flags & 0x10) {
proto_item_append_text(item, " Chaining");
}
flags &= (~( 0x10 ));
proto_tree_add_boolean(tree, hf_sbccs_dhflags_earlyend, tvb, offset, 1, flags);
if (flags & 0x08) {
proto_item_append_text(item, " Early End");
}
flags &= (~( 0x08 ));
proto_tree_add_boolean(tree, hf_sbccs_dhflags_nocrc, tvb, offset, 1, flags);
if (flags & 0x04) {
proto_item_append_text(item, " No CRC");
}
flags &= (~( 0x04 ));
}
static void
dissect_ccw_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint8 flags)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item=proto_tree_add_uint(parent_tree, hf_sbccs_dib_ccw_flags,
tvb, offset, 1, flags);
tree=proto_item_add_subtree(item, ett_sbccs_dib_ccw_flags);
}
proto_tree_add_boolean(tree, hf_sbccs_dib_ccw_flags_cd, tvb, offset, 1, flags);
if (flags & 0x80) {
proto_item_append_text(item, " CD");
}
flags &= (~( 0x80 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_ccw_flags_cc, tvb, offset, 1, flags);
if (flags & 0x40) {
proto_item_append_text(item, " CC");
}
flags &= (~( 0x40 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_ccw_flags_sli, tvb, offset, 1, flags);
if (flags & 0x20) {
proto_item_append_text(item, " SLI");
}
flags &= (~( 0x20 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_ccw_flags_crr, tvb, offset, 1, flags);
if (flags & 0x08) {
proto_item_append_text(item, " CRR");
}
flags &= (~( 0x08 ));
}
static void
dissect_cmd_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint8 flags)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item=proto_tree_add_uint(parent_tree, hf_sbccs_dib_cmdflags,
tvb, offset, 1, flags);
tree=proto_item_add_subtree(item, ett_sbccs_dib_cmdflags);
}
proto_tree_add_boolean(tree, hf_sbccs_dib_cmdflags_du, tvb, offset, 1, flags);
if (flags & 0x10) {
proto_item_append_text(item, " DU");
}
flags &= (~( 0x10 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_cmdflags_coc, tvb, offset, 1, flags);
if (flags & 0x08) {
proto_item_append_text(item, " COC");
}
flags &= (~( 0x08 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_cmdflags_syr, tvb, offset, 1, flags);
if (flags & 0x04) {
proto_item_append_text(item, " SYR");
}
flags &= (~( 0x04 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_cmdflags_rex, tvb, offset, 1, flags);
if (flags & 0x02) {
proto_item_append_text(item, " REX");
}
flags &= (~( 0x02 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_cmdflags_sss, tvb, offset, 1, flags);
if (flags & 0x01) {
proto_item_append_text(item, " SSS");
}
flags &= (~( 0x01 ));
}
static void
dissect_status_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint8 flags)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item=proto_tree_add_uint(parent_tree, hf_sbccs_dib_statusflags,
tvb, offset, 1, flags);
tree=proto_item_add_subtree(item, ett_sbccs_dib_statusflags);
}
proto_tree_add_item (tree, hf_sbccs_dib_statusflags_ffc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s", val_to_str ((flags>>5) & 0x07, status_ffc_val, "Reserved:0x%x"));
flags &= (~( 0xE0 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_statusflags_ci, tvb, offset, 1, flags);
if (flags & 0x10) {
proto_item_append_text(item, " CI");
}
flags &= (~( 0x10 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_statusflags_cr, tvb, offset, 1, flags);
if (flags & 0x04) {
proto_item_append_text(item, " CR");
}
flags &= (~( 0x04 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_statusflags_lri, tvb, offset, 1, flags);
if (flags & 0x02) {
proto_item_append_text(item, " LRI");
}
flags &= (~( 0x02 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_statusflags_rv, tvb, offset, 1, flags);
if (flags & 0x01) {
proto_item_append_text(item, " RV");
}
flags &= (~( 0x01 ));
}
static void
dissect_status (packet_info *pinfo, proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint8 flags)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item=proto_tree_add_uint(parent_tree, hf_sbccs_dib_status,
tvb, offset, 1, flags);
tree=proto_item_add_subtree(item, ett_sbccs_dib_status);
}
proto_tree_add_boolean(tree, hf_sbccs_dib_status_attention, tvb, offset, 1, flags);
if (flags & 0x80) {
proto_item_append_text(item, " Attention");
col_append_str(pinfo->cinfo, COL_INFO, " Attention");
}
flags &= (~( 0x80 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_status_modifier, tvb, offset, 1, flags);
if (flags & 0x40) {
proto_item_append_text(item, " Status Modifier");
col_append_str(pinfo->cinfo, COL_INFO, " Status Modifier");
}
flags &= (~( 0x40 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_status_cue, tvb, offset, 1, flags);
if (flags & 0x20) {
proto_item_append_text(item, " Control-Unit End");
col_append_str(pinfo->cinfo, COL_INFO, " Control-Unit End");
}
flags &= (~( 0x20 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_status_busy, tvb, offset, 1, flags);
if (flags & 0x10) {
proto_item_append_text(item, " Busy");
col_append_str(pinfo->cinfo, COL_INFO, " Busy");
}
flags &= (~( 0x10 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_status_channelend, tvb, offset, 1, flags);
if (flags & 0x08) {
proto_item_append_text(item, " Channel End");
col_append_str(pinfo->cinfo, COL_INFO, " Channel End");
}
flags &= (~( 0x08 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_status_deviceend, tvb, offset, 1, flags);
if (flags & 0x04) {
proto_item_append_text(item, " Device End");
col_append_str(pinfo->cinfo, COL_INFO, " Device End");
}
flags &= (~( 0x04 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_status_unit_check, tvb, offset, 1, flags);
if (flags & 0x02) {
proto_item_append_text(item, " Unit Check");
col_append_str(pinfo->cinfo, COL_INFO, " Unit Check");
}
flags &= (~( 0x02 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_status_unit_exception, tvb, offset, 1, flags);
if (flags & 0x01) {
proto_item_append_text(item, " Unit Exception");
col_append_str(pinfo->cinfo, COL_INFO, " Unit Exception");
}
flags &= (~( 0x01 ));
}
static void
dissect_sel_rst_param (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint32 flags)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item=proto_tree_add_uint(parent_tree, hf_sbccs_dib_ctlparam,
tvb, offset, 3, flags);
tree=proto_item_add_subtree(item, ett_sbccs_dib_ctlparam);
}
proto_tree_add_boolean(tree, hf_sbccs_dib_ctlparam_rc, tvb, offset, 3, flags);
if (flags & 0x80) {
proto_item_append_text(item, " RC");
}
flags &= (~( 0x80 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_ctlparam_ru, tvb, offset, 3, flags);
if (flags & 0x10) {
proto_item_append_text(item, " RU");
}
flags &= (~( 0x10 ));
proto_tree_add_boolean(tree, hf_sbccs_dib_ctlparam_ro, tvb, offset, 3, flags);
if (flags & 0x08) {
proto_item_append_text(item, " RO");
}
flags &= (~( 0x08 ));
}
static void get_fc_sbccs_conv_data (tvbuff_t *tvb, guint offset,
guint16 *ch_cu_id, guint16 *dev_addr,
guint16 *ccw)
{
*ch_cu_id = *dev_addr = *ccw = 0;
*ch_cu_id = (tvb_get_guint8 (tvb, offset+1)) << 8;
*ch_cu_id |= tvb_get_guint8 (tvb, offset+3);
*dev_addr = tvb_get_ntohs (tvb, offset+4);
*ccw = tvb_get_ntohs (tvb, offset+10);
}
static void
dissect_fc_sbccs_sb3_iu_hdr (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset)
{
proto_item *subti;
proto_tree *sb3hdr_tree;
proto_tree *iuhdr_tree;
guint8 iui, dhflags;
guint type;
type = get_fc_sbccs_iu_type (tvb, offset);
if (check_col (pinfo->cinfo, COL_INFO)) {
col_add_str (pinfo->cinfo, COL_INFO, val_to_str (type, fc_sbccs_iu_val,
"0x%x"));
}
if (tree) {
subti = proto_tree_add_text (tree, tvb, offset, FC_SBCCS_SB3_HDR_SIZE,
"SB-3 Header");
sb3hdr_tree = proto_item_add_subtree (subti, ett_fc_sbccs);
proto_tree_add_item (sb3hdr_tree, hf_sbccs_chid, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (sb3hdr_tree, hf_sbccs_cuid, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (sb3hdr_tree, hf_sbccs_devaddr, tvb, offset+4, 2, ENC_BIG_ENDIAN);
subti = proto_tree_add_text (tree, tvb, offset + FC_SBCCS_SB3_HDR_SIZE,
FC_SBCCS_IU_HDR_SIZE, "IU Header");
iuhdr_tree = proto_item_add_subtree (subti, ett_fc_sbccs);
offset += FC_SBCCS_SB3_HDR_SIZE;
iui = tvb_get_guint8 (tvb, offset);
dissect_iui_flags(iuhdr_tree, tvb, offset, iui);
dhflags = tvb_get_guint8 (tvb, offset+1);
dissect_dh_flags(iuhdr_tree, tvb, offset+1, dhflags);
proto_tree_add_item (iuhdr_tree, hf_sbccs_ccw, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (iuhdr_tree, hf_sbccs_token, tvb, offset+5, 3, ENC_BIG_ENDIAN);
}
}
static void dissect_fc_sbccs_dib_data_hdr (tvbuff_t *tvb,
packet_info *pinfo _U_,
proto_tree *tree, guint offset)
{
if (tree) {
proto_tree_add_item (tree, hf_sbccs_dib_iucnt, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_dib_datacnt, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_lrc, tvb, offset+12, 4, ENC_BIG_ENDIAN);
}
}
static void dissect_fc_sbccs_dib_cmd_hdr (tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint offset)
{
guint8 flags;
if (check_col (pinfo->cinfo, COL_INFO)) {
col_append_fstr (pinfo->cinfo, COL_INFO,
": %s", val_to_str (tvb_get_guint8 (tvb, offset),
fc_sbccs_dib_cmd_val,
"0x%x"));
}
if (tree) {
proto_tree_add_item (tree, hf_sbccs_dib_ccw_cmd, tvb, offset, 1, ENC_BIG_ENDIAN);
flags = tvb_get_guint8 (tvb, offset+1);
dissect_ccw_flags(tree, tvb, offset+1, flags);
proto_tree_add_item (tree, hf_sbccs_dib_ccw_cnt, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_dib_ioprio, tvb, offset+5, 1, ENC_BIG_ENDIAN);
flags = tvb_get_guint8 (tvb, offset+7);
dissect_cmd_flags(tree, tvb, offset+7, flags);
proto_tree_add_item (tree, hf_sbccs_dib_iucnt, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_dib_datacnt, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_lrc, tvb, offset+12, 4, ENC_BIG_ENDIAN);
}
}
static void dissect_fc_sbccs_dib_status_hdr (tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint offset)
{
guint8 flags;
gboolean rv_valid, qparam_valid;
tvbuff_t *next_tvb;
guint16 supp_status_cnt = 0;
if (tree) {
flags = tvb_get_guint8 (tvb, offset);
rv_valid = flags & 0x1;
qparam_valid = (((flags & 0xE0) >> 5) == 0x1);
dissect_status_flags(tree, tvb, offset, flags);
flags = tvb_get_guint8 (tvb, offset+1);
dissect_status(pinfo, tree, tvb, offset+1, flags);
if (rv_valid) {
proto_tree_add_item (tree, hf_sbccs_dib_residualcnt, tvb, offset+2,
2, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item (tree, hf_sbccs_dib_iupacing, tvb, offset+3,
1, ENC_BIG_ENDIAN);
}
if (qparam_valid) {
proto_tree_add_item (tree, hf_sbccs_dib_qtuf, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_dib_qtu, tvb, offset+4, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item (tree, hf_sbccs_dib_dtuf, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_dib_dtu, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_dib_iucnt, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_dib_datacnt, tvb, offset+10, 2, ENC_BIG_ENDIAN);
supp_status_cnt = tvb_get_ntohs (tvb, offset+10);
proto_tree_add_item (tree, hf_sbccs_lrc, tvb, offset+12, 4, ENC_BIG_ENDIAN);
if (supp_status_cnt) {
next_tvb = tvb_new_subset_remaining (tvb, offset+FC_SBCCS_DIB_LRC_HDR_SIZE);
call_dissector (data_handle, next_tvb, pinfo, tree);
}
}
}
static void dissect_fc_sbccs_dib_ctl_hdr (tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint offset)
{
guint8 ctlfn;
ctlfn = tvb_get_guint8 (tvb, offset);
if (check_col (pinfo->cinfo, COL_INFO)) {
col_append_fstr (pinfo->cinfo, COL_INFO,
": %s",
val_to_str (ctlfn,
fc_sbccs_dib_ctl_fn_val,
"0x%x"));
}
if (tree) {
proto_tree_add_item (tree, hf_sbccs_dib_ctlfn, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (ctlfn) {
case FC_SBCCS_CTL_FN_SEL_RST:
dissect_sel_rst_param(tree, tvb, offset+1, tvb_get_ntoh24 (tvb, offset+1));
break;
case FC_SBCCS_CTL_FN_DEV_XCP:
proto_tree_add_item (tree, hf_sbccs_dev_xcp_code, tvb, offset+1,
1, ENC_BIG_ENDIAN);
break;
case FC_SBCCS_CTL_FN_PRG_PTH:
proto_tree_add_item (tree, hf_sbccs_prg_pth_errcode, tvb, offset+1,
1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item (tree, hf_sbccs_dib_ctlparam, tvb, offset+1,
3, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item (tree, hf_sbccs_dib_iucnt, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_dib_datacnt, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_lrc, tvb, offset+12, 4, ENC_BIG_ENDIAN);
if (ctlfn == FC_SBCCS_CTL_FN_PRG_RSP) {
proto_tree_add_item (tree, hf_sbccs_prg_rsp_errcode, tvb, offset+60,
1, ENC_BIG_ENDIAN);
}
}
}
static void dissect_fc_sbccs_dib_link_hdr (tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint offset)
{
guint8 link_ctl;
guint16 ctl_info;
guint link_payload_len, i;
if (check_col (pinfo->cinfo, COL_INFO)) {
col_append_fstr (pinfo->cinfo, COL_INFO,
": %s",
val_to_str (tvb_get_guint8 (tvb, offset+1),
fc_sbccs_dib_link_ctl_fn_val,
"0x%x"));
}
if (tree) {
link_ctl = tvb_get_guint8 (tvb, offset+1);
proto_tree_add_item (tree, hf_sbccs_dib_linkctlfn, tvb, offset+1, 1, ENC_BIG_ENDIAN);
ctl_info = tvb_get_ntohs (tvb, offset+2);
switch (link_ctl) {
case FC_SBCCS_LINK_CTL_FN_ELP:
case FC_SBCCS_LINK_CTL_FN_LPE:
dissect_linkctlinfo(tree, tvb, offset+2, ctl_info);
break;
case FC_SBCCS_LINK_CTL_FN_LPR:
proto_tree_add_item (tree, hf_sbccs_dib_lprcode, tvb, offset+2, 1,
ENC_BIG_ENDIAN);
break;
case FC_SBCCS_LINK_CTL_FN_TIN:
proto_tree_add_item (tree, hf_sbccs_dib_tin_imgid_cnt, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
break;
case FC_SBCCS_LINK_CTL_FN_TIR:
proto_tree_add_item (tree, hf_sbccs_dib_tin_imgid_cnt, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
break;
case FC_SBCCS_LINK_CTL_FN_LRJ:
proto_tree_add_item (tree, hf_sbccs_dib_lrjcode, tvb, offset+2,
1, ENC_BIG_ENDIAN);
break;
default:
break;
}
proto_tree_add_item (tree, hf_sbccs_dib_ctccntr, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_dib_iucnt, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_dib_datacnt, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_sbccs_lrc, tvb, offset+12, 4, ENC_BIG_ENDIAN);
if (link_ctl == FC_SBCCS_LINK_CTL_FN_TIR) {
link_payload_len = tvb_get_ntohs (tvb, offset+10);
i = 0;
offset += 16;
while (i < link_payload_len) {
proto_tree_add_text (tree, tvb, offset, 4,
"Logical Paths %d-%d: %s",
i*8, ((i+4)*8) - 1,
tvb_bytes_to_str_punct (tvb, offset, 4, ':'));
i += 4;
offset += 4;
}
}
}
}
static void dissect_fc_sbccs (tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
guint8 type;
guint16 ch_cu_id, dev_addr, ccw;
guint offset = 0;
proto_item *ti;
proto_tree *sb3_tree = NULL;
proto_tree *dib_tree = NULL;
tvbuff_t *next_tvb;
conversation_t *conversation;
sb3_task_id_t task_key;
void *pd_save;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FC-SB3");
type = get_fc_sbccs_iu_type (tvb, offset);
get_fc_sbccs_conv_data (tvb, offset, &ch_cu_id, &dev_addr, &ccw);
if (check_col (pinfo->cinfo, COL_INFO)) {
col_add_str (pinfo->cinfo, COL_INFO, val_to_str (type, fc_sbccs_iu_val,
"0x%x"));
}
conversation = find_conversation (pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_SBCCS, ch_cu_id, dev_addr, 0);
pd_save = pinfo->private_data;
if (conversation) {
task_key.conv_id = conversation->index;
task_key.task_id = ccw;
pinfo->private_data = (void *)&task_key;
}
else if ((type == FC_SBCCS_IU_CMD_HDR) ||
(type != FC_SBCCS_IU_CMD_DATA)) {
conversation = conversation_new (pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_SBCCS, ch_cu_id, dev_addr, 0);
task_key.conv_id = conversation->index;
task_key.task_id = ccw;
pinfo->private_data = (void *)&task_key;
}
else {
pinfo->private_data = NULL;
}
if (tree) {
ti = proto_tree_add_protocol_format (tree, proto_fc_sbccs, tvb, 0, -1,
"FC-SB3");
sb3_tree = proto_item_add_subtree (ti, ett_fc_sbccs);
dissect_fc_sbccs_sb3_iu_hdr (tvb, pinfo, sb3_tree, offset);
offset += (FC_SBCCS_SB3_HDR_SIZE + FC_SBCCS_IU_HDR_SIZE);
ti = proto_tree_add_text (sb3_tree, tvb, offset,
FC_SBCCS_DIB_LRC_HDR_SIZE, "DIB Header");
dib_tree = proto_item_add_subtree (ti, ett_fc_sbccs);
}
else {
offset += (FC_SBCCS_SB3_HDR_SIZE + FC_SBCCS_IU_HDR_SIZE);
}
switch (type) {
case FC_SBCCS_IU_DATA:
dissect_fc_sbccs_dib_data_hdr (tvb, pinfo, dib_tree, offset);
break;
case FC_SBCCS_IU_CMD_HDR:
case FC_SBCCS_IU_CMD_DATA:
dissect_fc_sbccs_dib_cmd_hdr (tvb, pinfo, dib_tree, offset);
break;
case FC_SBCCS_IU_STATUS:
dissect_fc_sbccs_dib_status_hdr (tvb, pinfo, dib_tree, offset);
break;
case FC_SBCCS_IU_CTL:
dissect_fc_sbccs_dib_ctl_hdr (tvb, pinfo, dib_tree, offset);
break;
case FC_SBCCS_IU_CMD_LINK_CTL:
dissect_fc_sbccs_dib_link_hdr (tvb, pinfo, dib_tree, offset);
break;
default:
next_tvb = tvb_new_subset_remaining (tvb, offset);
call_dissector (data_handle, next_tvb, pinfo, dib_tree);
break;
}
if ((get_fc_sbccs_iu_type (tvb, 0) != FC_SBCCS_IU_CTL) &&
(get_fc_sbccs_iu_type (tvb, 0) != FC_SBCCS_IU_CMD_LINK_CTL)) {
next_tvb = tvb_new_subset_remaining (tvb, offset+FC_SBCCS_DIB_LRC_HDR_SIZE);
call_dissector (data_handle, next_tvb, pinfo, tree);
}
pinfo->private_data = pd_save;
}
void
proto_register_fcsbccs (void)
{
static hf_register_info hf[] = {
{ &hf_sbccs_chid,
{ "Channel Image ID", "fcsb3.chid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_cuid,
{ "Control Unit Image ID", "fcsb3.cuid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_devaddr,
{ "Device Address", "fcsb3.devaddr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_iui,
{ "Information Unit Identifier", "fcsb3.iui",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dhflags,
{ "DH Flags", "fcsb3.dhflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_ccw,
{ "CCW Number", "fcsb3.ccw",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_token,
{ "Token", "fcsb3.token",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_iucnt,
{ "DIB IU Count", "fcsb3.iucnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_datacnt,
{ "DIB Data Byte Count", "fcsb3.databytecnt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_ccw_cmd,
{ "CCW Command", "fcsb3.ccwcmd",
FT_UINT8, BASE_HEX, VALS (fc_sbccs_dib_cmd_val), 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_ccw_cnt,
{ "CCW Count", "fcsb3.ccwcnt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_ioprio,
{ "I/O Priority", "fcsb3.ioprio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_status,
{ "Status", "fcsb3.status",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_residualcnt,
{ "Residual Count", "fcsb3.residualcnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_iupacing,
{ "IU Pacing", "fcsb3.iupacing",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_qtuf,
{ "Queue-Time Unit Factor", "fcsb3.qtuf",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL}},
{ &hf_sbccs_dib_qtu,
{ "Queue-Time Unit", "fcsb3.qtu",
FT_UINT16, BASE_DEC, NULL, 0xFFF,
NULL, HFILL}},
{ &hf_sbccs_dib_dtuf,
{ "Defer-Time Unit Function", "fcsb3.dtuf",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL}},
{ &hf_sbccs_dib_dtu,
{ "Defer-Time Unit", "fcsb3.dtu",
FT_UINT16, BASE_DEC, NULL, 0xFFF,
NULL, HFILL}},
{ &hf_sbccs_dib_ctlfn,
{ "Control Function", "fcsb3.ctlfn",
FT_UINT8, BASE_HEX, VALS (fc_sbccs_dib_ctl_fn_val), 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_linkctlfn,
{ "Link Control Function", "fcsb3.linkctlfn",
FT_UINT8, BASE_HEX, VALS (fc_sbccs_dib_link_ctl_fn_val), 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_ctccntr,
{ "CTC Counter", "fcsb3.ctccntr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_lrc,
{ "LRC", "fcsb3.lrc",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dev_xcp_code,
{ "Device Level Exception Code", "fcsb3.dip.xcpcode",
FT_UINT8, BASE_DEC, VALS (fc_sbccs_dib_dev_xcpcode_val), 0x0,
NULL, HFILL}},
{ &hf_sbccs_prg_pth_errcode,
{ "Purge Path Error Code", "fcsb3.purgepathcode",
FT_UINT8, BASE_DEC, VALS (fc_sbccs_dib_purge_path_err_val), 0x0,
NULL, HFILL}},
{ &hf_sbccs_prg_rsp_errcode,
{ "Purge Path Response Error Code", "fcsb3.purgepathrspcode",
FT_UINT8, BASE_DEC, VALS (fc_sbccs_dib_purge_path_rsp_err_val), 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_lprcode,
{ "LPR Reason Code", "fcsb3.lprcode",
FT_UINT8, BASE_DEC, VALS (fc_sbccs_dib_lpr_errcode_val), 0xF,
NULL, HFILL}},
{ &hf_sbccs_dib_tin_imgid_cnt,
{ "TIN Image ID", "fcsb3.tinimageidcnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_lrjcode,
{ "LRJ Reaspn Code", "fcsb3.lrjcode",
FT_UINT8, BASE_HEX, VALS (fc_sbccs_dib_lrj_errcode_val), 0x7F,
NULL, HFILL}},
{ &hf_sbccs_iui_as,
{ "AS", "fcsb3.iui.as",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_iui_as), 0x10,
NULL, HFILL}},
{ &hf_sbccs_iui_es,
{ "ES", "fcsb3.iui.es",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_iui_es), 0x08,
NULL, HFILL}},
{ &hf_sbccs_iui_val,
{ "Val", "fcsb3.iui.val",
FT_UINT8, BASE_HEX, VALS(fc_sbccs_iu_val), 0x07,
NULL, HFILL}},
{ &hf_sbccs_dhflags_end,
{ "End", "fcsb3.dhflags.end",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_dhflags_end), 0x80,
NULL, HFILL}},
{ &hf_sbccs_dhflags_chaining,
{ "Chaining", "fcsb3.dhflags.chaining",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_dhflags_chaining), 0x10,
NULL, HFILL}},
{ &hf_sbccs_dhflags_earlyend,
{ "Early End", "fcsb3.dhflags.earlyend",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_dhflags_earlyend), 0x08,
NULL, HFILL}},
{ &hf_sbccs_dhflags_nocrc,
{ "No CRC", "fcsb3.dhflags.nocrc",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_dhflags_nocrc), 0x04,
NULL, HFILL}},
{ &hf_sbccs_dib_ccw_flags,
{ "CCW Control Flags", "fcsb3.ccwflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_ccw_flags_cd,
{ "CD", "fcsb3.ccwflags.cd",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_ccwflags_cd), 0x80,
NULL, HFILL}},
{ &hf_sbccs_dib_ccw_flags_cc,
{ "CC", "fcsb3.ccwflags.cc",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_ccwflags_cc), 0x40,
NULL, HFILL}},
{ &hf_sbccs_dib_ccw_flags_sli,
{ "SLI", "fcsb3.ccwflags.sli",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_ccwflags_sli), 0x20,
NULL, HFILL}},
{ &hf_sbccs_dib_ccw_flags_crr,
{ "CRR", "fcsb3.ccwflags.crr",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_ccwflags_crr), 0x08,
NULL, HFILL}},
{ &hf_sbccs_dib_cmdflags,
{ "Command Flags", "fcsb3.cmdflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_cmdflags_du,
{ "DU", "fcsb3.cmdflags.du",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_cmdflags_du), 0x10,
NULL, HFILL}},
{ &hf_sbccs_dib_cmdflags_coc,
{ "COC", "fcsb3.cmdflags.coc",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_cmdflags_coc), 0x08,
NULL, HFILL}},
{ &hf_sbccs_dib_cmdflags_syr,
{ "SYR", "fcsb3.cmdflags.syr",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_cmdflags_syr), 0x04,
NULL, HFILL}},
{ &hf_sbccs_dib_cmdflags_rex,
{ "REX", "fcsb3.cmdflags.rex",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_cmdflags_rex), 0x02,
NULL, HFILL}},
{ &hf_sbccs_dib_cmdflags_sss,
{ "SSS", "fcsb3.cmdflags.sss",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_cmdflags_sss), 0x01,
NULL, HFILL}},
{ &hf_sbccs_dib_statusflags,
{ "Status Flags", "fcsb3.statusflags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_sbccs_dib_statusflags_ffc,
{ "FFC", "fcsb3.statusflags.ffc",
FT_UINT8, BASE_HEX, VALS(status_ffc_val), 0xE0,
NULL, HFILL}},
{ &hf_sbccs_dib_statusflags_ci,
{ "CI", "fcsb3.statusflags.ci",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_statusflags_ci), 0x10,
NULL, HFILL}},
{ &hf_sbccs_dib_statusflags_cr,
{ "CR", "fcsb3.statusflags.cr",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_statusflags_cr), 0x04,
NULL, HFILL}},
{ &hf_sbccs_dib_statusflags_lri,
{ "LRI", "fcsb3.statusflags.lri",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_statusflags_lri), 0x02,
NULL, HFILL}},
{ &hf_sbccs_dib_statusflags_rv,
{ "RV", "fcsb3.statusflags.rv",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_statusflags_rv), 0x01,
NULL, HFILL}},
{ &hf_sbccs_dib_status_attention,
{ "Attention", "fcsb3.status.attention",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_status_attention), 0x80,
NULL, HFILL}},
{ &hf_sbccs_dib_status_modifier,
{ "Status Modifier", "fcsb3.status.modifier",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_status_modifier), 0x40,
NULL, HFILL}},
{ &hf_sbccs_dib_status_cue,
{ "Control-Unit End", "fcsb3.status.cue",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_status_cue), 0x20,
NULL, HFILL}},
{ &hf_sbccs_dib_status_busy,
{ "Busy", "fcsb3.status.busy",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_status_busy), 0x10,
NULL, HFILL}},
{ &hf_sbccs_dib_status_channelend,
{ "Channel End", "fcsb3.status.channel_end",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_status_channelend), 0x08,
NULL, HFILL}},
{ &hf_sbccs_dib_status_deviceend,
{ "Device End", "fcsb3.status.device_end",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_status_deviceend), 0x04,
NULL, HFILL}},
{ &hf_sbccs_dib_status_unit_check,
{ "Unit Check", "fcsb3.status.unit_check",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_status_unitcheck), 0x02,
NULL, HFILL}},
{ &hf_sbccs_dib_status_unit_exception,
{ "Unit Exception", "fcsb3.status.unitexception",
FT_BOOLEAN, 8, TFS(&tfs_sbccs_status_unitexception), 0x01,
NULL, HFILL}},
{ &hf_sbccs_dib_ctlparam,
{ "Control Parameters", "fcsb3.ctlparam",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_ctlparam_rc,
{ "RC", "fcsb3.ctlparam.rc",
FT_BOOLEAN, 24, TFS(&tfs_sbccs_ctlparam_rc), 0x80,
NULL, HFILL}},
{ &hf_sbccs_dib_ctlparam_ru,
{ "RU", "fcsb3.ctlparam.ru",
FT_BOOLEAN, 24, TFS(&tfs_sbccs_ctlparam_ru), 0x10,
NULL, HFILL}},
{ &hf_sbccs_dib_ctlparam_ro,
{ "RO", "fcsb3.ctlparam.ro",
FT_BOOLEAN, 24, TFS(&tfs_sbccs_ctlparam_ro), 0x08,
NULL, HFILL}},
{ &hf_sbccs_dib_linkctlinfo,
{ "Link Control Information", "fcsb3.linkctlinfo",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_sbccs_dib_linkctlinfo_ctcconn,
{ "CTC Conn", "fcsb3.linkctlinfo.ctc_conn",
FT_BOOLEAN, 16, TFS(&tfs_sbccs_linkctlinfo_ctcconn), 0x80,
NULL, HFILL}},
{ &hf_sbccs_dib_linkctlinfo_ecrcg,
{ "Enhanced CRC Generation", "fcsb3.linkctlinfo.ecrcg",
FT_BOOLEAN, 16, TFS(&tfs_sbccs_linkctlinfo_ecrcg), 0x01,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_fc_sbccs,
&ett_sbccs_iui,
&ett_sbccs_dhflags,
&ett_sbccs_dib_ccw_flags,
&ett_sbccs_dib_cmdflags,
&ett_sbccs_dib_statusflags,
&ett_sbccs_dib_status,
&ett_sbccs_dib_ctlparam,
&ett_sbccs_dib_linkctlinfo,
};
proto_fc_sbccs = proto_register_protocol ("Fibre Channel Single Byte Command",
"FC-SB3", "fcsb3");
proto_register_field_array(proto_fc_sbccs, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_fcsbccs (void)
{
dissector_handle_t fc_sbccs_handle;
fc_sbccs_handle = create_dissector_handle (dissect_fc_sbccs,
proto_fc_sbccs);
dissector_add_uint("fc.ftype", FC_FTYPE_SBCCS, fc_sbccs_handle);
data_handle = find_dissector ("data");
}
