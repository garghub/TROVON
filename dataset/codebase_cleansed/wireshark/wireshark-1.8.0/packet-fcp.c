static void
dissect_task_mgmt_flags(packet_info *pinfo, proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint8 flags;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_fcp_taskmgmt, tvb, offset, 1, ENC_LITTLE_ENDIAN);
tree = proto_item_add_subtree(item, ett_fcp_taskmgmt);
}
flags = tvb_get_guint8(tvb, offset);
if (!flags)
proto_item_append_text(item, " (No values set)");
proto_tree_add_boolean(tree, hf_fcp_mgmt_flags_obsolete, tvb, offset, 1, flags);
if (flags & 0x80) {
proto_item_append_text(item, " OBSOLETE");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP OBSOLETE] ");
}
flags &= (~( 0x80 ));
proto_tree_add_boolean(tree, hf_fcp_mgmt_flags_clear_aca, tvb, offset, 1, flags);
if (flags & 0x40) {
proto_item_append_text(item, " CLEAR ACA");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP CLEAR_ACA] ");
}
flags &= (~( 0x40 ));
proto_tree_add_boolean(tree, hf_fcp_mgmt_flags_target_reset, tvb, offset, 1, flags);
if (flags & 0x20) {
proto_item_append_text(item, " TARGET RESET");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP TARGET_RESET] ");
}
flags &= (~( 0x20 ));
proto_tree_add_boolean(tree, hf_fcp_mgmt_flags_lu_reset, tvb, offset, 1, flags);
if (flags & 0x10) {
proto_item_append_text(item, " LU RESET");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP LU_RESET] ");
}
flags &= (~( 0x10 ));
proto_tree_add_boolean(tree, hf_fcp_mgmt_flags_rsvd, tvb, offset, 1, flags);
if (flags & 0x08) {
proto_item_append_text(item, " RSVD");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP RSVD] ");
}
flags &= (~( 0x08 ));
proto_tree_add_boolean(tree, hf_fcp_mgmt_flags_clear_task_set, tvb, offset, 1, flags);
if (flags & 0x04) {
proto_item_append_text(item, " CLEAR TASK SET");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP CLEAR_TASK_SET] ");
}
flags &= (~( 0x04 ));
proto_tree_add_boolean(tree, hf_fcp_mgmt_flags_abort_task_set, tvb, offset, 1, flags);
if (flags & 0x02) {
proto_item_append_text(item, " ABORT TASK SET");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP ABORT_TASK_SET] ");
}
flags &= (~( 0x02 ));
if (flags) {
proto_item_append_text(item, " Unknown bitmap value 0x%x", flags);
}
}
static void
dissect_rsp_flags(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gboolean bidi_resid_present = FALSE;
guint8 flags;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_fcp_rspflags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
tree = proto_item_add_subtree(item, ett_fcp_rsp_flags);
}
flags = tvb_get_guint8(tvb, offset);
if (!flags)
proto_item_append_text(item, " (No values set)");
proto_tree_add_boolean(tree, hf_fcp_rsp_flags_bidi, tvb, offset, 1, flags);
if (flags & 0x80) {
bidi_resid_present = TRUE;
proto_item_append_text(item, " BIDI_RSP");
if (flags & (~( 0x80 )))
proto_item_append_text(item, ",");
}
flags &= (~( 0x80 ));
if (bidi_resid_present) {
proto_tree_add_boolean(tree, hf_fcp_rsp_flags_bidi_rru, tvb, offset, 1, flags);
if (flags & 0x40) {
proto_item_append_text(item, " BIDI_RRU");
if (flags & (~( 0x40 )))
proto_item_append_text(item, ",");
}
flags &= (~( 0x40 ));
proto_tree_add_boolean(tree, hf_fcp_rsp_flags_bidi_rro, tvb, offset, 1, flags);
if (flags & 0x20) {
proto_item_append_text(item, " BIDI_RRO");
if (flags & (~( 0x20 )))
proto_item_append_text(item, ",");
}
flags &= (~( 0x20 ));
}
proto_tree_add_boolean(tree, hf_fcp_rsp_flags_conf_req, tvb, offset, 1, flags);
if (flags & 0x10) {
proto_item_append_text(item, " CONF REQ");
if (flags & (~( 0x10 )))
proto_item_append_text(item, ",");
}
flags &= (~( 0x10 ));
proto_tree_add_boolean(tree, hf_fcp_rsp_flags_resid_under, tvb, offset, 1, flags);
if (flags & 0x08) {
proto_item_append_text(item, " RESID UNDER");
if (flags & (~( 0x08 )))
proto_item_append_text(item, ",");
}
flags &= (~( 0x08 ));
proto_tree_add_boolean(tree, hf_fcp_rsp_flags_resid_over, tvb, offset, 1, flags);
if (flags & 0x04) {
proto_item_append_text(item, " RESID OVER");
if (flags & (~( 0x04 )))
proto_item_append_text(item, ",");
}
flags &= (~( 0x04 ));
proto_tree_add_boolean(tree, hf_fcp_rsp_flags_sns_vld, tvb, offset, 1, flags);
if (flags & 0x02) {
proto_item_append_text(item, " SNS VLD");
if (flags & (~( 0x02 )))
proto_item_append_text(item, ",");
}
flags &= (~( 0x02 ));
proto_tree_add_boolean(tree, hf_fcp_rsp_flags_res_vld, tvb, offset, 1, flags);
if (flags & 0x01) {
proto_item_append_text(item, " RES VLD");
if (flags & (~( 0x01 )))
proto_item_append_text(item, ",");
}
flags &= (~( 0x01 ));
if (flags) {
proto_item_append_text(item, " Unknown bitmap value 0x%x", flags);
}
}
static void
dissect_fcp_cmnd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, proto_tree *tree, conversation_t *conversation, fc_hdr *fchdr, fcp_conv_data_t *fcp_conv_data)
{
int offset = 0;
int add_len = 0;
guint8 flags, rwflags, lun0;
guint16 lun = 0xffff;
tvbuff_t *cdb_tvb;
int tvb_len, tvb_rlen;
itl_nexus_t *itl = NULL;
proto_item *hidden_item;
flags = tvb_get_guint8(tvb, offset+10);
if (flags) {
add_len = tvb_get_guint8(tvb, offset+11) & 0x7C;
add_len = add_len >> 2;
}
hidden_item = proto_tree_add_uint(tree, hf_fcp_type, tvb, offset, 0, 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
lun0 = tvb_get_guint8(tvb, offset);
if (lun0) {
proto_tree_add_item(tree, hf_fcp_multilun, tvb, offset, 8, ENC_NA);
lun = tvb_get_guint8(tvb, offset) & 0x3f;
lun <<= 8;
lun |= tvb_get_guint8(tvb, offset+1);
} else {
proto_tree_add_item(tree, hf_fcp_singlelun, tvb, offset+1,
1, ENC_BIG_ENDIAN);
lun = tvb_get_guint8(tvb, offset+1);
}
if (fchdr->itlq)
fchdr->itlq->lun = lun;
itl = (itl_nexus_t *)se_tree_lookup32(fcp_conv_data->luns, lun);
if (!itl) {
itl = se_alloc(sizeof(itl_nexus_t));
itl->cmdset = 0xff;
itl->conversation = conversation;
se_tree_insert32(fcp_conv_data->luns, lun, itl);
}
proto_tree_add_item(tree, hf_fcp_crn, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_taskattr, tvb, offset+9, 1, ENC_BIG_ENDIAN);
dissect_task_mgmt_flags(pinfo, tree, tvb, offset+10);
proto_tree_add_item(tree, hf_fcp_addlcdblen, tvb, offset+11, 1, ENC_BIG_ENDIAN);
rwflags = tvb_get_guint8(tvb, offset+11);
if (fchdr->itlq) {
if (rwflags & 0x02) {
fchdr->itlq->task_flags |= SCSI_DATA_READ;
}
if (rwflags & 0x01) {
fchdr->itlq->task_flags |= SCSI_DATA_WRITE;
}
}
proto_tree_add_item(tree, hf_fcp_rddata, tvb, offset+11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_wrdata, tvb, offset+11, 1, ENC_BIG_ENDIAN);
tvb_len = tvb_length_remaining(tvb, offset+12);
if (tvb_len > (16 + add_len))
tvb_len = 16 + add_len;
tvb_rlen = tvb_reported_length_remaining(tvb, offset+12);
if (tvb_rlen > (16 + add_len))
tvb_rlen = 16 + add_len;
cdb_tvb = tvb_new_subset(tvb, offset+12, tvb_len, tvb_rlen);
dissect_scsi_cdb(cdb_tvb, pinfo, parent_tree, SCSI_DEV_UNKNOWN, fchdr->itlq, itl);
proto_tree_add_item(tree, hf_fcp_dl, tvb, offset+12+16+add_len,
4, ENC_BIG_ENDIAN);
if (fchdr->itlq) {
fchdr->itlq->data_length = tvb_get_ntohl(tvb, offset+12+16+add_len);
}
if ( ((rwflags & 0x03) == 0x03)
&& tvb_length_remaining(tvb, offset+12+16+add_len+4) >= 4) {
proto_tree_add_item(tree, hf_fcp_bidir_dl, tvb, offset+12+16+add_len+4,
4, ENC_BIG_ENDIAN);
if (fchdr->itlq) {
fchdr->itlq->bidir_data_length = tvb_get_ntohl(tvb, offset+12+16+add_len+4);
}
}
}
static void
dissect_fcp_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, conversation_t *conversation _U_, fc_hdr *fchdr, itl_nexus_t *itl)
{
dissect_scsi_payload(tvb, pinfo, parent_tree, FALSE, fchdr->itlq, itl, fchdr->relative_offset);
}
static void
dissect_fcp_rspinfo(tvbuff_t *tvb, proto_tree *tree, int offset)
{
offset += 3;
proto_tree_add_item(tree, hf_fcp_rspcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 4;
}
static void
dissect_fcp_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, proto_tree *tree, conversation_t *conversation _U_, fc_hdr *fchdr, itl_nexus_t *itl)
{
guint32 offset = 0;
gint32 snslen = 0;
gint32 rsplen = 0;
guint8 flags;
guint8 status;
proto_item *hidden_item;
status = tvb_get_guint8(tvb, offset+11);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ":%s",
val_to_str(status, scsi_status_val, "0x%x"));
}
hidden_item = proto_tree_add_uint(tree, hf_fcp_type, tvb, offset, 0, 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 8;
proto_tree_add_item(tree, hf_fcp_retry_delay_timer, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
flags = tvb_get_guint8(tvb, offset);
dissect_rsp_flags(tree, tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_fcp_scsistatus, tvb, offset, 1, ENC_BIG_ENDIAN);
dissect_scsi_rsp(tvb, pinfo, parent_tree, fchdr->itlq, itl, tvb_get_guint8(tvb, offset));
offset += 1;
if (flags & 0x0e) {
proto_tree_add_item(tree, hf_fcp_resid, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
if (flags & 0x2) {
snslen = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_fcp_snslen, tvb, offset, 4,
snslen);
}
offset += 4;
if (flags & 0x1) {
rsplen = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_fcp_rsplen, tvb, offset, 4,
rsplen);
}
offset += 4;
if (rsplen) {
tvbuff_t *rspinfo_tvb;
rspinfo_tvb = tvb_new_subset(tvb, offset, MIN(rsplen, tvb_length_remaining(tvb, offset)), rsplen);
dissect_fcp_rspinfo(rspinfo_tvb, tree, 0);
offset += rsplen;
}
if (snslen) {
tvbuff_t *sns_tvb;
sns_tvb = tvb_new_subset(tvb, offset, MIN(snslen, tvb_length_remaining(tvb, offset)), snslen);
dissect_scsi_snsinfo(sns_tvb, pinfo, parent_tree, 0,
snslen,
fchdr->itlq, itl);
offset += snslen;
}
if (flags & 0x80) {
if (flags & 0x60) {
proto_tree_add_item(tree, hf_fcp_bidir_resid, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
}
}
static void
dissect_fcp_xfer_rdy(tvbuff_t *tvb, proto_tree *tree)
{
int offset = 0;
proto_item *hidden_item;
hidden_item = proto_tree_add_uint(tree, hf_fcp_type, tvb, offset, 0, 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(tree, hf_fcp_data_ro, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_burstlen, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
static void
dissect_fcp_srr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 r_ctl;
r_ctl = pinfo->r_ctl & 0xf;
if (r_ctl == FCP_IU_UNSOL_CTL) {
proto_tree_add_item(tree, hf_fcp_srr_ox_id, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_srr_rx_id, tvb, 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_data_ro, tvb, 8, 4, ENC_BIG_ENDIAN);
r_ctl = tvb_get_guint8(tvb, 12);
proto_tree_add_text(tree, tvb, 12, 1, "R_CTL: %s",
val_to_str(r_ctl, fcp_iu_val, "0x%02x"));
}
}
static void
dissect_fcp_els(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 op;
op = tvb_get_guint8(tvb, 0);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(op, fc_els_proto_val, "0x%x"));
proto_tree_add_text(tree, tvb, 0, 1, "Opcode: %s",
val_to_str(op, fc_els_proto_val,
"ELS 0x%02x"));
switch (op) {
case FC_ELS_SRR:
dissect_fcp_srr(tvb, pinfo, tree);
break;
default:
call_dissector(data_handle, tvb, pinfo, tree);
break;
}
}
static void
dissect_fcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *fcp_tree = NULL;
fc_hdr *fchdr;
guint8 r_ctl;
fcp_conv_data_t *fcp_conv_data;
itl_nexus_t *itl = NULL;
gboolean els;
fchdr = (fc_hdr *)pinfo->private_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FCP");
r_ctl = pinfo->r_ctl;
els = (r_ctl & 0xf0) == FC_RCTL_LINK_DATA;
r_ctl &= 0xF;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(r_ctl, els ? fcp_els_iu_val : fcp_iu_val,
"0x%x"));
}
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_fcp, tvb, 0, -1,
"FCP: %s",
val_to_str(r_ctl,
els ? fcp_els_iu_val :
fcp_iu_val, "Unknown 0x%02x"));
fcp_tree = proto_item_add_subtree(ti, ett_fcp);
}
fcp_conv_data = conversation_get_proto_data(fchdr->conversation, proto_fcp);
if (!fcp_conv_data) {
fcp_conv_data = se_alloc(sizeof(fcp_conv_data_t));
fcp_conv_data->luns = se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "FCP Luns");
conversation_add_proto_data(fchdr->conversation, proto_fcp, fcp_conv_data);
}
if ((r_ctl != FCP_IU_CMD) && (r_ctl != FCP_IU_UNSOL_CTL)) {
itl = (itl_nexus_t *)se_tree_lookup32(fcp_conv_data->luns, fchdr->itlq->lun);
}
if ((r_ctl != FCP_IU_CMD) && (r_ctl != FCP_IU_UNSOL_CTL) &&
(fchdr->itlq->first_exchange_frame)) {
proto_item *it;
it = proto_tree_add_uint(fcp_tree, hf_fcp_singlelun, tvb, 0, 0, fchdr->itlq->lun);
PROTO_ITEM_SET_GENERATED(it);
it = proto_tree_add_uint(fcp_tree, hf_fcp_request_in, tvb, 0, 0, fchdr->itlq->first_exchange_frame);
PROTO_ITEM_SET_GENERATED(it);
if (r_ctl == FCP_IU_RSP) {
nstime_t delta_ts;
nstime_delta(&delta_ts, &pinfo->fd->abs_ts, &fchdr->itlq->fc_time);
it = proto_tree_add_time(ti, hf_fcp_time, tvb, 0, 0, &delta_ts);
PROTO_ITEM_SET_GENERATED(it);
}
}
if ((r_ctl != FCP_IU_RSP) && (r_ctl != FCP_IU_SOL_CTL) &&
(fchdr->itlq->last_exchange_frame)) {
proto_item *it;
it = proto_tree_add_uint(fcp_tree, hf_fcp_response_in, tvb, 0, 0, fchdr->itlq->last_exchange_frame);
PROTO_ITEM_SET_GENERATED(it);
}
if (els) {
dissect_fcp_els(tvb, pinfo, fcp_tree);
return;
}
switch (r_ctl) {
case FCP_IU_DATA:
dissect_fcp_data(tvb, pinfo, tree, fchdr->conversation, fchdr, itl);
break;
case FCP_IU_CONFIRM:
break;
case FCP_IU_XFER_RDY:
dissect_fcp_xfer_rdy(tvb, fcp_tree);
break;
case FCP_IU_CMD:
dissect_fcp_cmnd(tvb, pinfo, tree, fcp_tree, fchdr->conversation, fchdr, fcp_conv_data);
break;
case FCP_IU_RSP:
dissect_fcp_rsp(tvb, pinfo, tree, fcp_tree, fchdr->conversation, fchdr, itl);
break;
default:
call_dissector(data_handle, tvb, pinfo, tree);
break;
}
}
void
proto_register_fcp(void)
{
static hf_register_info hf[] = {
{ &hf_fcp_type,
{"Field to branch off to SCSI", "fcp.type",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_multilun,
{"Multi-Level LUN", "fcp.multilun",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_singlelun,
{"LUN", "fcp.lun",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_crn,
{"Command Ref Num", "fcp.crn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_taskattr,
{"Task Attribute", "fcp.taskattr",
FT_UINT8, BASE_HEX, VALS(fcp_task_attr_val), 0x7,
NULL, HFILL}},
{ &hf_fcp_taskmgmt,
{"Task Management Flags", "fcp.taskmgmt",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_addlcdblen,
{"Additional CDB Length", "fcp.addlcdblen",
FT_UINT8, BASE_DEC, NULL, 0xFC,
NULL, HFILL}},
{ &hf_fcp_rddata,
{"RDDATA", "fcp.rddata",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}},
{ &hf_fcp_wrdata,
{"WRDATA", "fcp.wrdata",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_fcp_dl,
{"FCP_DL", "fcp.dl",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_bidir_dl,
{"FCP_BIDIRECTIONAL_READ_DL", "fcp.bidir_dl",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_data_ro,
{"FCP_DATA_RO", "fcp.data_ro",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_burstlen,
{"Burst Length", "fcp.burstlen",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_retry_delay_timer,
{"Retry Delay Timer", "fcp.rsp.retry_delay_timer",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_rspflags,
{"FCP_RSP Flags", "fcp.rspflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_resid,
{"FCP_RESID", "fcp.resid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_bidir_resid,
{"Bidirectional Read Resid", "fcp.bidir_resid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_snslen,
{"FCP_SNS_LEN", "fcp.snslen",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_rsplen,
{"FCP_RSP_LEN", "fcp.rsplen",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_rspcode,
{"RSP_CODE", "fcp.rspcode",
FT_UINT8, BASE_HEX, VALS(fcp_rsp_code_val), 0x0,
NULL, HFILL}},
{ &hf_fcp_scsistatus,
{"SCSI Status", "fcp.status",
FT_UINT8, BASE_HEX, VALS(scsi_status_val), 0x0,
NULL, HFILL}},
{ &hf_fcp_mgmt_flags_obsolete,
{ "Obsolete", "fcp.mgmt.flags.obsolete",
FT_BOOLEAN, 8, TFS(&fcp_mgmt_flags_obsolete_tfs), 0x80,
NULL, HFILL }},
{ &hf_fcp_mgmt_flags_clear_aca,
{ "Clear ACA", "fcp.mgmt.flags.clear_aca",
FT_BOOLEAN, 8, TFS(&fcp_mgmt_flags_clear_aca_tfs), 0x40,
NULL, HFILL }},
{ &hf_fcp_mgmt_flags_target_reset,
{ "Target Reset", "fcp.mgmt.flags.target_reset",
FT_BOOLEAN, 8, TFS(&fcp_mgmt_flags_target_reset_tfs), 0x20,
NULL, HFILL }},
{ &hf_fcp_mgmt_flags_lu_reset,
{ "LU Reset", "fcp.mgmt.flags.lu_reset",
FT_BOOLEAN, 8, TFS(&fcp_mgmt_flags_lu_reset_tfs), 0x10,
NULL, HFILL }},
{ &hf_fcp_mgmt_flags_rsvd,
{ "Rsvd", "fcp.mgmt.flags.rsvd",
FT_BOOLEAN, 8, TFS(&fcp_mgmt_flags_rsvd_tfs), 0x08,
NULL, HFILL }},
{ &hf_fcp_mgmt_flags_clear_task_set,
{ "Clear Task Set", "fcp.mgmt.flags.clear_task_set",
FT_BOOLEAN, 8, TFS(&fcp_mgmt_flags_clear_task_set_tfs), 0x04,
NULL, HFILL }},
{ &hf_fcp_mgmt_flags_abort_task_set,
{ "Abort Task Set", "fcp.mgmt.flags.abort_task_set",
FT_BOOLEAN, 8, TFS(&fcp_mgmt_flags_abort_task_set_tfs), 0x02,
NULL, HFILL }},
{ &hf_fcp_rsp_flags_bidi,
{ "Bidi Rsp", "fcp.rsp.flags.bidi",
FT_BOOLEAN, 8, TFS(&fcp_rsp_flags_bidi_tfs), 0x80,
NULL, HFILL }},
{ &hf_fcp_rsp_flags_bidi_rru,
{ "Bidi Read Resid Under", "fcp.rsp.flags.bidi_rru",
FT_BOOLEAN, 8, TFS(&fcp_rsp_flags_bidi_rru_tfs), 0x40,
NULL, HFILL }},
{ &hf_fcp_rsp_flags_bidi_rro,
{ "Bidi Read Resid Over", "fcp.rsp.flags.bidi_rro",
FT_BOOLEAN, 8, TFS(&fcp_rsp_flags_bidi_rro_tfs), 0x20,
NULL, HFILL }},
{ &hf_fcp_rsp_flags_conf_req,
{ "Conf Req", "fcp.rsp.flags.conf_req",
FT_BOOLEAN, 8, TFS(&fcp_rsp_flags_conf_req_tfs), 0x10,
NULL, HFILL }},
{ &hf_fcp_rsp_flags_resid_under,
{ "Resid Under", "fcp.rsp.flags.resid_under",
FT_BOOLEAN, 8, TFS(&fcp_rsp_flags_resid_under_tfs), 0x08,
NULL, HFILL }},
{ &hf_fcp_rsp_flags_resid_over,
{ "Resid Over", "fcp.rsp.flags.resid_over",
FT_BOOLEAN, 8, TFS(&fcp_rsp_flags_resid_over_tfs), 0x04,
NULL, HFILL }},
{ &hf_fcp_rsp_flags_sns_vld,
{ "SNS Vld", "fcp.rsp.flags.sns_vld",
FT_BOOLEAN, 8, TFS(&fcp_rsp_flags_sns_vld_tfs), 0x02,
NULL, HFILL }},
{ &hf_fcp_rsp_flags_res_vld,
{ "RES Vld", "fcp.rsp.flags.res_vld",
FT_BOOLEAN, 8, TFS(&fcp_rsp_flags_res_vld_tfs), 0x01,
NULL, HFILL }},
{ &hf_fcp_request_in,
{ "Request In", "fcp.request_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The frame number for the request", HFILL }},
{ &hf_fcp_response_in,
{ "Response In", "fcp.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The frame number of the response", HFILL }},
{ &hf_fcp_time,
{ "Time from FCP_CMND", "fcp.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0,
"Time since the FCP_CMND frame", HFILL }},
{ &hf_fcp_srr_op,
{"Opcode", "fcp.els.op",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_srr_ox_id,
{"OX_ID", "fcp.els.srr.ox_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_srr_rx_id,
{"RX_ID", "fcp.els.srr.rx_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_srr_r_ctl,
{"R_CTL", "fcp.els.srr.r_ctl",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_fcp,
&ett_fcp_taskmgmt,
&ett_fcp_rsp_flags,
};
proto_fcp = proto_register_protocol("Fibre Channel Protocol for SCSI",
"FCP", "fcp");
proto_register_field_array(proto_fcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
fcp_dissector = register_dissector_table("fcp.type", "FCP Type", FT_UINT8,
BASE_HEX);
}
void
proto_reg_handoff_fcp(void)
{
dissector_handle_t fcp_handle;
fcp_handle = create_dissector_handle(dissect_fcp, proto_fcp);
dissector_add_uint("fc.ftype", FC_FTYPE_SCSI, fcp_handle);
data_handle = find_dissector("data");
}
