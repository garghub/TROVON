static int
qla4xxx_space_in_req_ring(struct scsi_qla_host *ha, uint16_t req_cnt)
{
uint16_t cnt;
if ((req_cnt + 2) >= ha->req_q_count) {
cnt = (uint16_t) ha->isp_ops->rd_shdw_req_q_out(ha);
if (ha->request_in < cnt)
ha->req_q_count = cnt - ha->request_in;
else
ha->req_q_count = REQUEST_QUEUE_DEPTH -
(ha->request_in - cnt);
}
if ((req_cnt + 2) < ha->req_q_count)
return 1;
else
return 0;
}
static void qla4xxx_advance_req_ring_ptr(struct scsi_qla_host *ha)
{
if (ha->request_in == (REQUEST_QUEUE_DEPTH - 1)) {
ha->request_in = 0;
ha->request_ptr = ha->request_ring;
} else {
ha->request_in++;
ha->request_ptr++;
}
}
static int qla4xxx_get_req_pkt(struct scsi_qla_host *ha,
struct queue_entry **queue_entry)
{
uint16_t req_cnt = 1;
if (qla4xxx_space_in_req_ring(ha, req_cnt)) {
*queue_entry = ha->request_ptr;
memset(*queue_entry, 0, sizeof(**queue_entry));
qla4xxx_advance_req_ring_ptr(ha);
ha->req_q_count -= req_cnt;
return QLA_SUCCESS;
}
return QLA_ERROR;
}
int qla4xxx_send_marker_iocb(struct scsi_qla_host *ha,
struct ddb_entry *ddb_entry, int lun, uint16_t mrkr_mod)
{
struct qla4_marker_entry *marker_entry;
unsigned long flags = 0;
uint8_t status = QLA_SUCCESS;
spin_lock_irqsave(&ha->hardware_lock, flags);
if (qla4xxx_get_req_pkt(ha, (struct queue_entry **) &marker_entry) !=
QLA_SUCCESS) {
status = QLA_ERROR;
goto exit_send_marker;
}
marker_entry->hdr.entryType = ET_MARKER;
marker_entry->hdr.entryCount = 1;
marker_entry->target = cpu_to_le16(ddb_entry->fw_ddb_index);
marker_entry->modifier = cpu_to_le16(mrkr_mod);
int_to_scsilun(lun, &marker_entry->lun);
wmb();
ha->isp_ops->queue_iocb(ha);
exit_send_marker:
spin_unlock_irqrestore(&ha->hardware_lock, flags);
return status;
}
static struct continuation_t1_entry *
qla4xxx_alloc_cont_entry(struct scsi_qla_host *ha)
{
struct continuation_t1_entry *cont_entry;
cont_entry = (struct continuation_t1_entry *)ha->request_ptr;
qla4xxx_advance_req_ring_ptr(ha);
cont_entry->hdr.entryType = ET_CONTINUE;
cont_entry->hdr.entryCount = 1;
cont_entry->hdr.systemDefined = (uint8_t) cpu_to_le16(ha->request_in);
return cont_entry;
}
static uint16_t qla4xxx_calc_request_entries(uint16_t dsds)
{
uint16_t iocbs;
iocbs = 1;
if (dsds > COMMAND_SEG) {
iocbs += (dsds - COMMAND_SEG) / CONTINUE_SEG;
if ((dsds - COMMAND_SEG) % CONTINUE_SEG)
iocbs++;
}
return iocbs;
}
static void qla4xxx_build_scsi_iocbs(struct srb *srb,
struct command_t3_entry *cmd_entry,
uint16_t tot_dsds)
{
struct scsi_qla_host *ha;
uint16_t avail_dsds;
struct data_seg_a64 *cur_dsd;
struct scsi_cmnd *cmd;
struct scatterlist *sg;
int i;
cmd = srb->cmd;
ha = srb->ha;
if (!scsi_bufflen(cmd) || cmd->sc_data_direction == DMA_NONE) {
cmd_entry->ttlByteCnt = __constant_cpu_to_le32(0);
return;
}
avail_dsds = COMMAND_SEG;
cur_dsd = (struct data_seg_a64 *) & (cmd_entry->dataseg[0]);
scsi_for_each_sg(cmd, sg, tot_dsds, i) {
dma_addr_t sle_dma;
if (avail_dsds == 0) {
struct continuation_t1_entry *cont_entry;
cont_entry = qla4xxx_alloc_cont_entry(ha);
cur_dsd =
(struct data_seg_a64 *)
&cont_entry->dataseg[0];
avail_dsds = CONTINUE_SEG;
}
sle_dma = sg_dma_address(sg);
cur_dsd->base.addrLow = cpu_to_le32(LSDW(sle_dma));
cur_dsd->base.addrHigh = cpu_to_le32(MSDW(sle_dma));
cur_dsd->count = cpu_to_le32(sg_dma_len(sg));
avail_dsds--;
cur_dsd++;
}
}
void qla4_8xxx_queue_iocb(struct scsi_qla_host *ha)
{
uint32_t dbval = 0;
dbval = 0x14 | (ha->func_num << 5);
dbval = dbval | (0 << 8) | (ha->request_in << 16);
qla4_8xxx_wr_32(ha, ha->nx_db_wr_ptr, ha->request_in);
}
void qla4_8xxx_complete_iocb(struct scsi_qla_host *ha)
{
writel(ha->response_out, &ha->qla4_8xxx_reg->rsp_q_out);
readl(&ha->qla4_8xxx_reg->rsp_q_out);
}
void qla4xxx_queue_iocb(struct scsi_qla_host *ha)
{
writel(ha->request_in, &ha->reg->req_q_in);
readl(&ha->reg->req_q_in);
}
void qla4xxx_complete_iocb(struct scsi_qla_host *ha)
{
writel(ha->response_out, &ha->reg->rsp_q_out);
readl(&ha->reg->rsp_q_out);
}
int qla4xxx_send_command_to_isp(struct scsi_qla_host *ha, struct srb * srb)
{
struct scsi_cmnd *cmd = srb->cmd;
struct ddb_entry *ddb_entry;
struct command_t3_entry *cmd_entry;
int nseg;
uint16_t tot_dsds;
uint16_t req_cnt;
unsigned long flags;
uint32_t index;
char tag[2];
ddb_entry = srb->ddb;
tot_dsds = 0;
spin_lock_irqsave(&ha->hardware_lock, flags);
index = (uint32_t)cmd->request->tag;
if (!test_bit(AF_ONLINE, &ha->flags)) {
DEBUG2(printk("scsi%ld: %s: Adapter OFFLINE! "
"Do not issue command.\n",
ha->host_no, __func__));
goto queuing_error;
}
nseg = scsi_dma_map(cmd);
if (nseg < 0)
goto queuing_error;
tot_dsds = nseg;
req_cnt = qla4xxx_calc_request_entries(tot_dsds);
if (!qla4xxx_space_in_req_ring(ha, req_cnt))
goto queuing_error;
if ((ha->iocb_cnt + req_cnt) >= REQUEST_QUEUE_DEPTH)
goto queuing_error;
cmd_entry = (struct command_t3_entry *) ha->request_ptr;
memset(cmd_entry, 0, sizeof(struct command_t3_entry));
cmd_entry->hdr.entryType = ET_COMMAND;
cmd_entry->handle = cpu_to_le32(index);
cmd_entry->target = cpu_to_le16(ddb_entry->fw_ddb_index);
cmd_entry->connection_id = cpu_to_le16(ddb_entry->connection_id);
int_to_scsilun(cmd->device->lun, &cmd_entry->lun);
cmd_entry->cmdSeqNum = cpu_to_le32(ddb_entry->CmdSn);
cmd_entry->ttlByteCnt = cpu_to_le32(scsi_bufflen(cmd));
memcpy(cmd_entry->cdb, cmd->cmnd, cmd->cmd_len);
cmd_entry->dataSegCnt = cpu_to_le16(tot_dsds);
cmd_entry->hdr.entryCount = req_cnt;
cmd_entry->control_flags = CF_NO_DATA;
if (scsi_bufflen(cmd)) {
if (cmd->sc_data_direction == DMA_TO_DEVICE)
cmd_entry->control_flags = CF_WRITE;
else if (cmd->sc_data_direction == DMA_FROM_DEVICE)
cmd_entry->control_flags = CF_READ;
ha->bytes_xfered += scsi_bufflen(cmd);
if (ha->bytes_xfered & ~0xFFFFF){
ha->total_mbytes_xferred += ha->bytes_xfered >> 20;
ha->bytes_xfered &= 0xFFFFF;
}
}
cmd_entry->control_flags |= CF_SIMPLE_TAG;
if (scsi_populate_tag_msg(cmd, tag))
switch (tag[0]) {
case MSG_HEAD_TAG:
cmd_entry->control_flags |= CF_HEAD_TAG;
break;
case MSG_ORDERED_TAG:
cmd_entry->control_flags |= CF_ORDERED_TAG;
break;
}
qla4xxx_advance_req_ring_ptr(ha);
qla4xxx_build_scsi_iocbs(srb, cmd_entry, tot_dsds);
wmb();
srb->cmd->host_scribble = (unsigned char *)(unsigned long)index;
srb->state = SRB_ACTIVE_STATE;
srb->flags |= SRB_DMA_VALID;
ha->iocb_cnt += req_cnt;
srb->iocb_cnt = req_cnt;
ha->req_q_count -= req_cnt;
ha->isp_ops->queue_iocb(ha);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
return QLA_SUCCESS;
queuing_error:
if (tot_dsds)
scsi_dma_unmap(cmd);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
return QLA_ERROR;
}
