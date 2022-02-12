static void
dissect_task_mgmt_flags(packet_info *pinfo, proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
proto_item *item;
static const int * mgmt_flags[] = {
&hf_fcp_mgmt_flags_obsolete,
&hf_fcp_mgmt_flags_clear_aca,
&hf_fcp_mgmt_flags_target_reset,
&hf_fcp_mgmt_flags_lu_reset,
&hf_fcp_mgmt_flags_rsvd,
&hf_fcp_mgmt_flags_clear_task_set,
&hf_fcp_mgmt_flags_abort_task_set,
NULL
};
guint8 flags;
flags = tvb_get_guint8(tvb, offset);
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_fcp_taskmgmt,
ett_fcp_taskmgmt, mgmt_flags, ENC_NA, BMT_NO_FALSE|BMT_NO_TFS);
if (!flags)
proto_item_append_text(item, " (No values set)");
if (flags & 0x80) {
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP OBSOLETE] ");
}
if (flags & 0x40) {
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP CLEAR_ACA] ");
}
if (flags & 0x20) {
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP TARGET_RESET] ");
}
if (flags & 0x10) {
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP LU_RESET] ");
}
if (flags & 0x08) {
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP RSVD] ");
}
if (flags & 0x04) {
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP CLEAR_TASK_SET] ");
}
if (flags & 0x02) {
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[FCP ABORT_TASK_SET] ");
}
}
static void
dissect_rsp_flags(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
proto_item *item;
guint8 flags;
static const int * resid_present_flags[] = {
&hf_fcp_rsp_flags_bidi,
&hf_fcp_rsp_flags_bidi_rru,
&hf_fcp_rsp_flags_bidi_rro,
&hf_fcp_rsp_flags_conf_req,
&hf_fcp_rsp_flags_resid_under,
&hf_fcp_rsp_flags_resid_over,
&hf_fcp_rsp_flags_sns_vld,
&hf_fcp_rsp_flags_res_vld,
NULL
};
static const int * no_resid_flags[] = {
&hf_fcp_rsp_flags_bidi,
&hf_fcp_rsp_flags_conf_req,
&hf_fcp_rsp_flags_resid_under,
&hf_fcp_rsp_flags_resid_over,
&hf_fcp_rsp_flags_sns_vld,
&hf_fcp_rsp_flags_res_vld,
NULL
};
flags = tvb_get_guint8(tvb, offset);
if (flags & 0x80) {
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_fcp_rspflags,
ett_fcp_rsp_flags, resid_present_flags, ENC_NA, BMT_NO_FALSE|BMT_NO_TFS);
} else {
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_fcp_rspflags,
ett_fcp_rsp_flags, no_resid_flags, ENC_NA, BMT_NO_FALSE|BMT_NO_TFS);
}
if (!flags)
proto_item_append_text(item, " (No values set)");
}
static void
dissect_fcp_cmnd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, proto_tree *tree, conversation_t *conversation, fc_hdr *fchdr, fcp_conv_data_t *fcp_conv_data)
{
int offset = 0;
int add_len = 0;
guint8 flags, rwflags, lun0;
guint16 lun = 0xffff;
tvbuff_t *cdb_tvb;
int tvb_len;
fcp_request_data_t *request_data = NULL;
itl_nexus_t itl;
fcp_proto_data_t *proto_data;
flags = tvb_get_guint8(tvb, offset+10);
if (flags) {
add_len = tvb_get_guint8(tvb, offset+11) & 0x7C;
add_len = add_len >> 2;
}
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
if (!pinfo->fd->flags.visited) {
proto_data = wmem_new(wmem_file_scope(), fcp_proto_data_t);
proto_data->lun = lun;
p_add_proto_data(wmem_file_scope(), pinfo, proto_fcp, 0, proto_data);
}
request_data = (fcp_request_data_t*)wmem_map_lookup(fcp_conv_data->luns, GUINT_TO_POINTER((guint)lun));
if (!request_data) {
request_data = wmem_new(wmem_file_scope(), fcp_request_data_t);
request_data->request_frame = pinfo->num;
request_data->response_frame = 0;
request_data->request_time = pinfo->abs_ts;
request_data->itlq = wmem_new(wmem_file_scope(), itlq_nexus_t);
request_data->itlq->first_exchange_frame=0;
request_data->itlq->last_exchange_frame=0;
request_data->itlq->lun=lun;
request_data->itlq->scsi_opcode=0xffff;
request_data->itlq->task_flags=0;
request_data->itlq->data_length=0;
request_data->itlq->bidir_data_length=0;
request_data->itlq->fc_time=pinfo->abs_ts;
request_data->itlq->flags=0;
request_data->itlq->alloc_len=0;
request_data->itlq->extra_data=NULL;
wmem_map_insert(fcp_conv_data->luns, GUINT_TO_POINTER((guint)lun), request_data);
}
if(!pinfo->fd->flags.visited){
if(fchdr->fctl&FC_FCTL_EXCHANGE_FIRST){
request_data->itlq->first_exchange_frame=pinfo->num;
request_data->itlq->fc_time = pinfo->abs_ts;
}
if(fchdr->fctl&FC_FCTL_EXCHANGE_LAST){
request_data->itlq->last_exchange_frame=pinfo->num;
}
}
if (request_data->itlq)
request_data->itlq->lun = lun;
fchdr->lun = lun;
proto_tree_add_item(tree, hf_fcp_crn, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_taskattr, tvb, offset+9, 1, ENC_BIG_ENDIAN);
dissect_task_mgmt_flags(pinfo, tree, tvb, offset+10);
proto_tree_add_item(tree, hf_fcp_addlcdblen, tvb, offset+11, 1, ENC_BIG_ENDIAN);
rwflags = tvb_get_guint8(tvb, offset+11);
if (request_data->itlq) {
if (rwflags & 0x02) {
request_data->itlq->task_flags |= SCSI_DATA_READ;
}
if (rwflags & 0x01) {
request_data->itlq->task_flags |= SCSI_DATA_WRITE;
}
}
proto_tree_add_item(tree, hf_fcp_rddata, tvb, offset+11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_wrdata, tvb, offset+11, 1, ENC_BIG_ENDIAN);
tvb_len = tvb_captured_length_remaining(tvb, offset+12);
if (tvb_len > (16 + add_len))
tvb_len = 16 + add_len;
itl.cmdset = 0xff;
itl.conversation = conversation;
cdb_tvb = tvb_new_subset_length(tvb, offset+12, tvb_len);
dissect_scsi_cdb(cdb_tvb, pinfo, parent_tree, SCSI_DEV_UNKNOWN, request_data->itlq, &itl);
proto_tree_add_item(tree, hf_fcp_dl, tvb, offset+12+16+add_len,
4, ENC_BIG_ENDIAN);
if (request_data->itlq) {
request_data->itlq->data_length = tvb_get_ntohl(tvb, offset+12+16+add_len);
}
if ( ((rwflags & 0x03) == 0x03)
&& tvb_reported_length_remaining(tvb, offset+12+16+add_len+4) >= 4) {
proto_tree_add_item(tree, hf_fcp_bidir_dl, tvb, offset+12+16+add_len+4,
4, ENC_BIG_ENDIAN);
if (request_data->itlq) {
request_data->itlq->bidir_data_length = tvb_get_ntohl(tvb, offset+12+16+add_len+4);
}
}
}
static void
dissect_fcp_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, conversation_t *conversation, itlq_nexus_t *itlq, guint32 relative_offset)
{
itl_nexus_t itl;
itlq_nexus_t empty_itlq;
itl.cmdset = 0xff;
itl.conversation = conversation;
if (itlq == NULL)
{
memset(&empty_itlq, 0, sizeof(empty_itlq));
empty_itlq.lun=0xffff;
empty_itlq.scsi_opcode=0xffff;
itlq = &empty_itlq;
}
dissect_scsi_payload(tvb, pinfo, parent_tree, FALSE, itlq, &itl, relative_offset);
}
static int
dissect_fcp_rspinfo(tvbuff_t *tvb, proto_tree *tree, int offset)
{
offset += 3;
proto_tree_add_item(tree, hf_fcp_rspcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 4;
return offset;
}
static void
dissect_fcp_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, proto_tree *tree, conversation_t *conversation, fc_hdr *fchdr, fcp_request_data_t *request_data)
{
guint32 offset = 0;
gint32 snslen = 0;
gint32 rsplen = 0;
guint8 flags;
guint8 status;
itl_nexus_t itl;
itlq_nexus_t empty_itlq;
status = tvb_get_guint8(tvb, offset+11);
col_append_fstr(pinfo->cinfo, COL_INFO, ":%s",
val_to_str(status, scsi_status_val, "0x%x"));
if (request_data != NULL) {
request_data->response_frame = pinfo->num;
if(!pinfo->fd->flags.visited){
if(fchdr->fctl&FC_FCTL_EXCHANGE_FIRST){
request_data->itlq->first_exchange_frame=pinfo->num;
request_data->itlq->fc_time = pinfo->abs_ts;
}
if(fchdr->fctl&FC_FCTL_EXCHANGE_LAST){
request_data->itlq->last_exchange_frame=pinfo->num;
}
}
} else {
memset(&empty_itlq, 0, sizeof(empty_itlq));
empty_itlq.lun=0xffff;
empty_itlq.scsi_opcode=0xffff;
}
offset += 8;
proto_tree_add_item(tree, hf_fcp_retry_delay_timer, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
flags = tvb_get_guint8(tvb, offset);
dissect_rsp_flags(tree, tvb, offset);
offset += 1;
itl.cmdset = 0xff;
itl.conversation = conversation;
proto_tree_add_item(tree, hf_fcp_scsistatus, tvb, offset, 1, ENC_BIG_ENDIAN);
dissect_scsi_rsp(tvb, pinfo, parent_tree, (request_data != NULL) ? request_data->itlq : &empty_itlq, &itl, tvb_get_guint8(tvb, offset));
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
rspinfo_tvb = tvb_new_subset_length_caplen(tvb, offset, MIN(rsplen, tvb_captured_length_remaining(tvb, offset)), rsplen);
dissect_fcp_rspinfo(rspinfo_tvb, tree, 0);
offset += rsplen;
}
if (snslen) {
tvbuff_t *sns_tvb;
sns_tvb = tvb_new_subset_length_caplen(tvb, offset, MIN(snslen, tvb_captured_length_remaining(tvb, offset)), snslen);
dissect_scsi_snsinfo(sns_tvb, pinfo, parent_tree, 0,
snslen,
(request_data != NULL) ? request_data->itlq : &empty_itlq, &itl);
offset += snslen;
}
if (flags & 0x80) {
if (flags & 0x60) {
proto_tree_add_item(tree, hf_fcp_bidir_resid, tvb, offset, 4, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_fcp_xfer_rdy(tvbuff_t *tvb, proto_tree *tree)
{
int offset = 0;
proto_tree_add_item(tree, hf_fcp_data_ro, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_burstlen, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
static void
dissect_fcp_srr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, fc_hdr *fchdr)
{
guint8 r_ctl;
r_ctl = fchdr->r_ctl & 0xf;
if (r_ctl == FCP_IU_UNSOL_CTL) {
proto_tree_add_item(tree, hf_fcp_srr_ox_id, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_srr_rx_id, tvb, 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_data_ro, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcp_r_ctl, tvb, 12, 1, ENC_NA);
}
}
static void
dissect_fcp_els(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, fc_hdr *fchdr)
{
guint8 op;
op = tvb_get_guint8(tvb, 0);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_ext(op, &fc_els_proto_val_ext, "0x%x"));
proto_tree_add_item(tree, hf_fcp_els_op, tvb, 0, 1, ENC_NA);
switch (op) {
case FC_ELS_SRR:
dissect_fcp_srr(tvb, pinfo, tree, fchdr);
break;
default:
call_data_dissector(tvb, pinfo, tree);
break;
}
}
static int
dissect_fcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *ti = NULL;
proto_tree *fcp_tree = NULL;
fc_hdr *fchdr;
guint8 r_ctl;
conversation_t *fc_conv;
fcp_conv_data_t *fcp_conv_data = NULL;
fcp_request_data_t *request_data = NULL;
gboolean els;
fcp_proto_data_t *proto_data;
if (data == NULL)
return 0;
fchdr = (fc_hdr *)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FCP");
r_ctl = fchdr->r_ctl;
els = (r_ctl & 0xf0) == FC_RCTL_LINK_DATA;
r_ctl &= 0xF;
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(r_ctl, els ? fcp_els_iu_val : fcp_iu_val,
"0x%x"));
ti = proto_tree_add_protocol_format(tree, proto_fcp, tvb, 0, -1,
"FCP: %s",
val_to_str(r_ctl,
els ? fcp_els_iu_val :
fcp_iu_val, "Unknown 0x%02x"));
fcp_tree = proto_item_add_subtree(ti, ett_fcp);
fc_conv = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (fc_conv != NULL) {
fcp_conv_data = (fcp_conv_data_t *)conversation_get_proto_data(fc_conv, proto_fcp);
}
if (!fcp_conv_data) {
fcp_conv_data = wmem_new(wmem_file_scope(), fcp_conv_data_t);
fcp_conv_data->luns = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
conversation_add_proto_data(fc_conv, proto_fcp, fcp_conv_data);
}
if (!pinfo->fd->flags.visited) {
proto_data = wmem_new(wmem_file_scope(), fcp_proto_data_t);
proto_data->lun = fchdr->lun;
p_add_proto_data(wmem_file_scope(), pinfo, proto_fcp, 0, proto_data);
} else {
proto_data = (fcp_proto_data_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_fcp, 0);
}
if ((r_ctl != FCP_IU_CMD) && (r_ctl != FCP_IU_UNSOL_CTL)) {
request_data = (fcp_request_data_t *)wmem_map_lookup(fcp_conv_data->luns, GUINT_TO_POINTER((guint)(proto_data->lun)));
}
if ((r_ctl != FCP_IU_CMD) && (r_ctl != FCP_IU_UNSOL_CTL) &&
(request_data != NULL) && (request_data->itlq->first_exchange_frame)) {
proto_item *it;
it = proto_tree_add_uint(fcp_tree, hf_fcp_singlelun, tvb, 0, 0, proto_data->lun);
PROTO_ITEM_SET_GENERATED(it);
if (request_data != NULL) {
it = proto_tree_add_uint(fcp_tree, hf_fcp_request_in, tvb, 0, 0, request_data->request_frame);
PROTO_ITEM_SET_GENERATED(it);
if (r_ctl == FCP_IU_RSP) {
nstime_t delta_ts;
nstime_delta(&delta_ts, &pinfo->abs_ts, &request_data->request_time);
it = proto_tree_add_time(ti, hf_fcp_time, tvb, 0, 0, &delta_ts);
PROTO_ITEM_SET_GENERATED(it);
}
}
}
if ((r_ctl != FCP_IU_RSP) && (r_ctl != FCP_IU_SOL_CTL) &&
(request_data != NULL) && (request_data->response_frame)) {
proto_item *it;
it = proto_tree_add_uint(fcp_tree, hf_fcp_response_in, tvb, 0, 0, request_data->response_frame);
PROTO_ITEM_SET_GENERATED(it);
}
if (els) {
dissect_fcp_els(tvb, pinfo, fcp_tree, fchdr);
return tvb_captured_length(tvb);
}
switch (r_ctl) {
case FCP_IU_DATA:
dissect_fcp_data(tvb, pinfo, tree, fc_conv, (request_data != NULL) ? request_data->itlq : NULL, fchdr->relative_offset);
break;
case FCP_IU_CONFIRM:
break;
case FCP_IU_XFER_RDY:
dissect_fcp_xfer_rdy(tvb, fcp_tree);
break;
case FCP_IU_CMD:
dissect_fcp_cmnd(tvb, pinfo, tree, fcp_tree, fc_conv, fchdr, fcp_conv_data);
break;
case FCP_IU_RSP:
dissect_fcp_rsp(tvb, pinfo, tree, fcp_tree, fc_conv, fchdr, request_data);
break;
default:
call_data_dissector(tvb, pinfo, tree);
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_fcp(void)
{
static hf_register_info hf[] = {
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
FT_UINT32, BASE_DEC, VALS(fcp_iu_val), 0x0,
NULL, HFILL}},
{ &hf_fcp_r_ctl,
{"R_CTL", "fcp.r_ctl",
FT_UINT8, BASE_HEX, NULL, 0x0,
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
{ &hf_fcp_els_op,
{"Opcode", "fcp.els.op",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &fc_els_proto_val_ext, 0x0,
NULL, HFILL}},
{ &hf_fcp_srr_ox_id,
{"OX_ID", "fcp.els.srr.ox_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcp_srr_rx_id,
{"RX_ID", "fcp.els.srr.rx_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
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
}
void
proto_reg_handoff_fcp(void)
{
dissector_handle_t fcp_handle;
fcp_handle = create_dissector_handle(dissect_fcp, proto_fcp);
dissector_add_uint("fc.ftype", FC_FTYPE_SCSI, fcp_handle);
}
