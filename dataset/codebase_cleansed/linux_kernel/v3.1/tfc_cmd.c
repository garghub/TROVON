void ft_dump_cmd(struct ft_cmd *cmd, const char *caller)
{
struct fc_exch *ep;
struct fc_seq *sp;
struct se_cmd *se_cmd;
struct scatterlist *sg;
int count;
se_cmd = &cmd->se_cmd;
pr_debug("%s: cmd %p sess %p seq %p se_cmd %p\n",
caller, cmd, cmd->sess, cmd->seq, se_cmd);
pr_debug("%s: cmd %p cdb %p\n",
caller, cmd, cmd->cdb);
pr_debug("%s: cmd %p lun %d\n", caller, cmd, cmd->lun);
pr_debug("%s: cmd %p data_nents %u len %u se_cmd_flags <0x%x>\n",
caller, cmd, se_cmd->t_data_nents,
se_cmd->data_length, se_cmd->se_cmd_flags);
for_each_sg(se_cmd->t_data_sg, sg, se_cmd->t_data_nents, count)
pr_debug("%s: cmd %p sg %p page %p "
"len 0x%x off 0x%x\n",
caller, cmd, sg,
sg_page(sg), sg->length, sg->offset);
sp = cmd->seq;
if (sp) {
ep = fc_seq_exch(sp);
pr_debug("%s: cmd %p sid %x did %x "
"ox_id %x rx_id %x seq_id %x e_stat %x\n",
caller, cmd, ep->sid, ep->did, ep->oxid, ep->rxid,
sp->id, ep->esb_stat);
}
print_hex_dump(KERN_INFO, "ft_dump_cmd ", DUMP_PREFIX_NONE,
16, 4, cmd->cdb, MAX_COMMAND_SIZE, 0);
}
static void ft_free_cmd(struct ft_cmd *cmd)
{
struct fc_frame *fp;
struct fc_lport *lport;
if (!cmd)
return;
fp = cmd->req_frame;
lport = fr_dev(fp);
if (fr_seq(fp))
lport->tt.seq_release(fr_seq(fp));
fc_frame_free(fp);
ft_sess_put(cmd->sess);
kfree(cmd);
}
void ft_release_cmd(struct se_cmd *se_cmd)
{
struct ft_cmd *cmd = container_of(se_cmd, struct ft_cmd, se_cmd);
ft_free_cmd(cmd);
}
void ft_check_stop_free(struct se_cmd *se_cmd)
{
transport_generic_free_cmd(se_cmd, 0, 0);
}
int ft_queue_status(struct se_cmd *se_cmd)
{
struct ft_cmd *cmd = container_of(se_cmd, struct ft_cmd, se_cmd);
struct fc_frame *fp;
struct fcp_resp_with_ext *fcp;
struct fc_lport *lport;
struct fc_exch *ep;
size_t len;
ft_dump_cmd(cmd, __func__);
ep = fc_seq_exch(cmd->seq);
lport = ep->lp;
len = sizeof(*fcp) + se_cmd->scsi_sense_length;
fp = fc_frame_alloc(lport, len);
if (!fp) {
return 0;
}
fcp = fc_frame_payload_get(fp, len);
memset(fcp, 0, len);
fcp->resp.fr_status = se_cmd->scsi_status;
len = se_cmd->scsi_sense_length;
if (len) {
fcp->resp.fr_flags |= FCP_SNS_LEN_VAL;
fcp->ext.fr_sns_len = htonl(len);
memcpy((fcp + 1), se_cmd->sense_buffer, len);
}
if (se_cmd->se_cmd_flags & (SCF_OVERFLOW_BIT | SCF_UNDERFLOW_BIT)) {
if (se_cmd->se_cmd_flags & SCF_OVERFLOW_BIT)
fcp->resp.fr_flags |= FCP_RESID_OVER;
else
fcp->resp.fr_flags |= FCP_RESID_UNDER;
fcp->ext.fr_resid = cpu_to_be32(se_cmd->residual_count);
}
cmd->seq = lport->tt.seq_start_next(cmd->seq);
fc_fill_fc_hdr(fp, FC_RCTL_DD_CMD_STATUS, ep->did, ep->sid, FC_TYPE_FCP,
FC_FC_EX_CTX | FC_FC_LAST_SEQ | FC_FC_END_SEQ, 0);
lport->tt.seq_send(lport, cmd->seq, fp);
lport->tt.exch_done(cmd->seq);
return 0;
}
int ft_write_pending_status(struct se_cmd *se_cmd)
{
struct ft_cmd *cmd = container_of(se_cmd, struct ft_cmd, se_cmd);
return cmd->write_data_len != se_cmd->data_length;
}
int ft_write_pending(struct se_cmd *se_cmd)
{
struct ft_cmd *cmd = container_of(se_cmd, struct ft_cmd, se_cmd);
struct fc_frame *fp;
struct fcp_txrdy *txrdy;
struct fc_lport *lport;
struct fc_exch *ep;
struct fc_frame_header *fh;
u32 f_ctl;
ft_dump_cmd(cmd, __func__);
ep = fc_seq_exch(cmd->seq);
lport = ep->lp;
fp = fc_frame_alloc(lport, sizeof(*txrdy));
if (!fp)
return PYX_TRANSPORT_OUT_OF_MEMORY_RESOURCES;
txrdy = fc_frame_payload_get(fp, sizeof(*txrdy));
memset(txrdy, 0, sizeof(*txrdy));
txrdy->ft_burst_len = htonl(se_cmd->data_length);
cmd->seq = lport->tt.seq_start_next(cmd->seq);
fc_fill_fc_hdr(fp, FC_RCTL_DD_DATA_DESC, ep->did, ep->sid, FC_TYPE_FCP,
FC_FC_EX_CTX | FC_FC_END_SEQ | FC_FC_SEQ_INIT, 0);
fh = fc_frame_header_get(fp);
f_ctl = ntoh24(fh->fh_f_ctl);
if (f_ctl & FC_FC_EX_CTX) {
if ((ep->xid <= lport->lro_xid) &&
(fh->fh_r_ctl == FC_RCTL_DD_DATA_DESC)) {
if (se_cmd->se_cmd_flags & SCF_SCSI_DATA_SG_IO_CDB) {
transport_do_task_sg_chain(se_cmd);
cmd->sg = se_cmd->t_tasks_sg_chained;
cmd->sg_cnt =
se_cmd->t_tasks_sg_chained_no;
}
if (cmd->sg && lport->tt.ddp_target(lport, ep->xid,
cmd->sg,
cmd->sg_cnt))
cmd->was_ddp_setup = 1;
}
}
lport->tt.seq_send(lport, cmd->seq, fp);
return 0;
}
u32 ft_get_task_tag(struct se_cmd *se_cmd)
{
struct ft_cmd *cmd = container_of(se_cmd, struct ft_cmd, se_cmd);
return fc_seq_exch(cmd->seq)->rxid;
}
int ft_get_cmd_state(struct se_cmd *se_cmd)
{
return 0;
}
int ft_is_state_remove(struct se_cmd *se_cmd)
{
return 0;
}
static void ft_recv_seq(struct fc_seq *sp, struct fc_frame *fp, void *arg)
{
struct ft_cmd *cmd = arg;
struct fc_frame_header *fh;
if (IS_ERR(fp)) {
cmd->se_cmd.t_state = TRANSPORT_REMOVE;
cmd->seq = NULL;
transport_generic_free_cmd(&cmd->se_cmd, 0, 0);
return;
}
fh = fc_frame_header_get(fp);
switch (fh->fh_r_ctl) {
case FC_RCTL_DD_SOL_DATA:
ft_recv_write_data(cmd, fp);
break;
case FC_RCTL_DD_UNSOL_CTL:
case FC_RCTL_DD_SOL_CTL:
case FC_RCTL_DD_DATA_DESC:
default:
pr_debug("%s: unhandled frame r_ctl %x\n",
__func__, fh->fh_r_ctl);
ft_invl_hw_context(cmd);
fc_frame_free(fp);
transport_generic_free_cmd(&cmd->se_cmd, 0, 0);
break;
}
}
static void ft_send_resp_status(struct fc_lport *lport,
const struct fc_frame *rx_fp,
u32 status, enum fcp_resp_rsp_codes code)
{
struct fc_frame *fp;
struct fc_seq *sp;
const struct fc_frame_header *fh;
size_t len;
struct fcp_resp_with_ext *fcp;
struct fcp_resp_rsp_info *info;
fh = fc_frame_header_get(rx_fp);
pr_debug("FCP error response: did %x oxid %x status %x code %x\n",
ntoh24(fh->fh_s_id), ntohs(fh->fh_ox_id), status, code);
len = sizeof(*fcp);
if (status == SAM_STAT_GOOD)
len += sizeof(*info);
fp = fc_frame_alloc(lport, len);
if (!fp)
return;
fcp = fc_frame_payload_get(fp, len);
memset(fcp, 0, len);
fcp->resp.fr_status = status;
if (status == SAM_STAT_GOOD) {
fcp->ext.fr_rsp_len = htonl(sizeof(*info));
fcp->resp.fr_flags |= FCP_RSP_LEN_VAL;
info = (struct fcp_resp_rsp_info *)(fcp + 1);
info->rsp_code = code;
}
fc_fill_reply_hdr(fp, rx_fp, FC_RCTL_DD_CMD_STATUS, 0);
sp = fr_seq(fp);
if (sp)
lport->tt.seq_send(lport, sp, fp);
else
lport->tt.frame_send(lport, fp);
}
static void ft_send_resp_code(struct ft_cmd *cmd,
enum fcp_resp_rsp_codes code)
{
ft_send_resp_status(cmd->sess->tport->lport,
cmd->req_frame, SAM_STAT_GOOD, code);
}
static void ft_send_resp_code_and_free(struct ft_cmd *cmd,
enum fcp_resp_rsp_codes code)
{
ft_send_resp_code(cmd, code);
ft_free_cmd(cmd);
}
static void ft_send_tm(struct ft_cmd *cmd)
{
struct se_tmr_req *tmr;
struct fcp_cmnd *fcp;
struct ft_sess *sess;
u8 tm_func;
fcp = fc_frame_payload_get(cmd->req_frame, sizeof(*fcp));
switch (fcp->fc_tm_flags) {
case FCP_TMF_LUN_RESET:
tm_func = TMR_LUN_RESET;
break;
case FCP_TMF_TGT_RESET:
tm_func = TMR_TARGET_WARM_RESET;
break;
case FCP_TMF_CLR_TASK_SET:
tm_func = TMR_CLEAR_TASK_SET;
break;
case FCP_TMF_ABT_TASK_SET:
tm_func = TMR_ABORT_TASK_SET;
break;
case FCP_TMF_CLR_ACA:
tm_func = TMR_CLEAR_ACA;
break;
default:
pr_debug("invalid FCP tm_flags %x\n", fcp->fc_tm_flags);
ft_send_resp_code_and_free(cmd, FCP_CMND_FIELDS_INVALID);
return;
}
pr_debug("alloc tm cmd fn %d\n", tm_func);
tmr = core_tmr_alloc_req(&cmd->se_cmd, cmd, tm_func);
if (!tmr) {
pr_debug("alloc failed\n");
ft_send_resp_code_and_free(cmd, FCP_TMF_FAILED);
return;
}
cmd->se_cmd.se_tmr_req = tmr;
switch (fcp->fc_tm_flags) {
case FCP_TMF_LUN_RESET:
cmd->lun = scsilun_to_int((struct scsi_lun *)fcp->fc_lun);
if (transport_lookup_tmr_lun(&cmd->se_cmd, cmd->lun) < 0) {
pr_debug("Failed to get LUN for TMR func %d, "
"se_cmd %p, unpacked_lun %d\n",
tm_func, &cmd->se_cmd, cmd->lun);
ft_dump_cmd(cmd, __func__);
sess = cmd->sess;
transport_send_check_condition_and_sense(&cmd->se_cmd,
cmd->se_cmd.scsi_sense_reason, 0);
transport_generic_free_cmd(&cmd->se_cmd, 0, 0);
ft_sess_put(sess);
return;
}
break;
case FCP_TMF_TGT_RESET:
case FCP_TMF_CLR_TASK_SET:
case FCP_TMF_ABT_TASK_SET:
case FCP_TMF_CLR_ACA:
break;
default:
return;
}
transport_generic_handle_tmr(&cmd->se_cmd);
}
int ft_queue_tm_resp(struct se_cmd *se_cmd)
{
struct ft_cmd *cmd = container_of(se_cmd, struct ft_cmd, se_cmd);
struct se_tmr_req *tmr = se_cmd->se_tmr_req;
enum fcp_resp_rsp_codes code;
switch (tmr->response) {
case TMR_FUNCTION_COMPLETE:
code = FCP_TMF_CMPL;
break;
case TMR_LUN_DOES_NOT_EXIST:
code = FCP_TMF_INVALID_LUN;
break;
case TMR_FUNCTION_REJECTED:
code = FCP_TMF_REJECTED;
break;
case TMR_TASK_DOES_NOT_EXIST:
case TMR_TASK_STILL_ALLEGIANT:
case TMR_TASK_FAILOVER_NOT_SUPPORTED:
case TMR_TASK_MGMT_FUNCTION_NOT_SUPPORTED:
case TMR_FUNCTION_AUTHORIZATION_FAILED:
default:
code = FCP_TMF_FAILED;
break;
}
pr_debug("tmr fn %d resp %d fcp code %d\n",
tmr->function, tmr->response, code);
ft_send_resp_code(cmd, code);
return 0;
}
static void ft_recv_cmd(struct ft_sess *sess, struct fc_frame *fp)
{
struct ft_cmd *cmd;
struct fc_lport *lport = sess->tport->lport;
cmd = kzalloc(sizeof(*cmd), GFP_ATOMIC);
if (!cmd)
goto busy;
cmd->sess = sess;
cmd->seq = lport->tt.seq_assign(lport, fp);
if (!cmd->seq) {
kfree(cmd);
goto busy;
}
cmd->req_frame = fp;
INIT_WORK(&cmd->work, ft_send_work);
queue_work(sess->tport->tpg->workqueue, &cmd->work);
return;
busy:
pr_debug("cmd or seq allocation failure - sending BUSY\n");
ft_send_resp_status(lport, fp, SAM_STAT_BUSY, 0);
fc_frame_free(fp);
ft_sess_put(sess);
}
void ft_recv_req(struct ft_sess *sess, struct fc_frame *fp)
{
struct fc_frame_header *fh = fc_frame_header_get(fp);
switch (fh->fh_r_ctl) {
case FC_RCTL_DD_UNSOL_CMD:
ft_recv_cmd(sess, fp);
break;
case FC_RCTL_DD_SOL_DATA:
case FC_RCTL_DD_UNSOL_CTL:
case FC_RCTL_DD_SOL_CTL:
case FC_RCTL_DD_DATA_DESC:
case FC_RCTL_ELS4_REQ:
default:
pr_debug("%s: unhandled frame r_ctl %x\n",
__func__, fh->fh_r_ctl);
fc_frame_free(fp);
ft_sess_put(sess);
break;
}
}
static void ft_send_work(struct work_struct *work)
{
struct ft_cmd *cmd = container_of(work, struct ft_cmd, work);
struct fc_frame_header *fh = fc_frame_header_get(cmd->req_frame);
struct se_cmd *se_cmd;
struct fcp_cmnd *fcp;
int data_dir = 0;
u32 data_len;
int task_attr;
int ret;
fcp = fc_frame_payload_get(cmd->req_frame, sizeof(*fcp));
if (!fcp)
goto err;
if (fcp->fc_flags & FCP_CFL_LEN_MASK)
goto err;
if (fcp->fc_tm_flags) {
task_attr = FCP_PTA_SIMPLE;
data_dir = DMA_NONE;
data_len = 0;
} else {
switch (fcp->fc_flags & (FCP_CFL_RDDATA | FCP_CFL_WRDATA)) {
case 0:
data_dir = DMA_NONE;
break;
case FCP_CFL_RDDATA:
data_dir = DMA_FROM_DEVICE;
break;
case FCP_CFL_WRDATA:
data_dir = DMA_TO_DEVICE;
break;
case FCP_CFL_WRDATA | FCP_CFL_RDDATA:
goto err;
}
switch (fcp->fc_pri_ta & FCP_PTA_MASK) {
case FCP_PTA_HEADQ:
task_attr = MSG_HEAD_TAG;
break;
case FCP_PTA_ORDERED:
task_attr = MSG_ORDERED_TAG;
break;
case FCP_PTA_ACA:
task_attr = MSG_ACA_TAG;
break;
case FCP_PTA_SIMPLE:
default:
task_attr = MSG_SIMPLE_TAG;
}
task_attr = fcp->fc_pri_ta & FCP_PTA_MASK;
data_len = ntohl(fcp->fc_dl);
cmd->cdb = fcp->fc_cdb;
}
se_cmd = &cmd->se_cmd;
transport_init_se_cmd(se_cmd, &ft_configfs->tf_ops, cmd->sess->se_sess,
data_len, data_dir, task_attr,
&cmd->ft_sense_buffer[0]);
if (fcp->fc_tm_flags) {
ft_send_tm(cmd);
return;
}
fc_seq_exch(cmd->seq)->lp->tt.seq_set_resp(cmd->seq, ft_recv_seq, cmd);
cmd->lun = scsilun_to_int((struct scsi_lun *)fcp->fc_lun);
ret = transport_lookup_cmd_lun(&cmd->se_cmd, cmd->lun);
if (ret < 0) {
ft_dump_cmd(cmd, __func__);
transport_send_check_condition_and_sense(&cmd->se_cmd,
cmd->se_cmd.scsi_sense_reason, 0);
return;
}
ret = transport_generic_allocate_tasks(se_cmd, cmd->cdb);
pr_debug("r_ctl %x alloc task ret %d\n", fh->fh_r_ctl, ret);
ft_dump_cmd(cmd, __func__);
if (ret == -ENOMEM) {
transport_send_check_condition_and_sense(se_cmd,
TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE, 0);
transport_generic_free_cmd(se_cmd, 0, 0);
return;
}
if (ret == -EINVAL) {
if (se_cmd->se_cmd_flags & SCF_SCSI_RESERVATION_CONFLICT)
ft_queue_status(se_cmd);
else
transport_send_check_condition_and_sense(se_cmd,
se_cmd->scsi_sense_reason, 0);
transport_generic_free_cmd(se_cmd, 0, 0);
return;
}
transport_generic_handle_cdb(se_cmd);
return;
err:
ft_send_resp_code_and_free(cmd, FCP_CMND_FIELDS_INVALID);
}
