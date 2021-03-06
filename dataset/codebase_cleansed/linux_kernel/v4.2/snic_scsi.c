const char *
snic_state_to_str(unsigned int state)
{
if (state >= ARRAY_SIZE(snic_state_str) || !snic_state_str[state])
return "Unknown";
return snic_state_str[state];
}
static const char *
snic_io_status_to_str(unsigned int state)
{
if ((state >= ARRAY_SIZE(snic_io_status_str)) ||
(!snic_io_status_str[state]))
return "Unknown";
return snic_io_status_str[state];
}
static const char *
snic_ioreq_state_to_str(unsigned int state)
{
if (state >= ARRAY_SIZE(snic_req_state_str) ||
!snic_req_state_str[state])
return "Unknown";
return snic_req_state_str[state];
}
static inline spinlock_t *
snic_io_lock_hash(struct snic *snic, struct scsi_cmnd *sc)
{
u32 hash = snic_cmd_tag(sc) & (SNIC_IO_LOCKS - 1);
return &snic->io_req_lock[hash];
}
static inline spinlock_t *
snic_io_lock_tag(struct snic *snic, int tag)
{
return &snic->io_req_lock[tag & (SNIC_IO_LOCKS - 1)];
}
static void
snic_release_req_buf(struct snic *snic,
struct snic_req_info *rqi,
struct scsi_cmnd *sc)
{
struct snic_host_req *req = rqi_to_req(rqi);
SNIC_BUG_ON(!((CMD_STATE(sc) == SNIC_IOREQ_COMPLETE) ||
(CMD_STATE(sc) == SNIC_IOREQ_ABTS_COMPLETE) ||
(CMD_FLAGS(sc) & SNIC_DEV_RST_NOTSUP) ||
(CMD_FLAGS(sc) & SNIC_IO_INTERNAL_TERM_ISSUED) ||
(CMD_FLAGS(sc) & SNIC_DEV_RST_TERM_ISSUED) ||
(CMD_FLAGS(sc) & SNIC_SCSI_CLEANUP) ||
(CMD_STATE(sc) == SNIC_IOREQ_LR_COMPLETE)));
SNIC_SCSI_DBG(snic->shost,
"Rel_req:sc %p:tag %x:rqi %p:ioreq %p:abt %p:dr %p: state %s:flags 0x%llx\n",
sc, snic_cmd_tag(sc), rqi, rqi->req, rqi->abort_req,
rqi->dr_req, snic_ioreq_state_to_str(CMD_STATE(sc)),
CMD_FLAGS(sc));
if (req->u.icmnd.sense_addr)
pci_unmap_single(snic->pdev,
le64_to_cpu(req->u.icmnd.sense_addr),
SCSI_SENSE_BUFFERSIZE,
PCI_DMA_FROMDEVICE);
scsi_dma_unmap(sc);
snic_req_free(snic, rqi);
}
static int
snic_queue_icmnd_req(struct snic *snic,
struct snic_req_info *rqi,
struct scsi_cmnd *sc,
int sg_cnt)
{
struct scatterlist *sg;
struct snic_sg_desc *sgd;
dma_addr_t pa = 0;
struct scsi_lun lun;
u16 flags = 0;
int ret = 0;
unsigned int i;
if (sg_cnt) {
flags = SNIC_ICMND_ESGL;
sgd = (struct snic_sg_desc *) req_to_sgl(rqi->req);
for_each_sg(scsi_sglist(sc), sg, sg_cnt, i) {
sgd->addr = cpu_to_le64(sg_dma_address(sg));
sgd->len = cpu_to_le32(sg_dma_len(sg));
sgd->_resvd = 0;
sgd++;
}
}
pa = pci_map_single(snic->pdev,
sc->sense_buffer,
SCSI_SENSE_BUFFERSIZE,
PCI_DMA_FROMDEVICE);
if (pci_dma_mapping_error(snic->pdev, pa)) {
SNIC_HOST_ERR(snic->shost,
"QIcmnd:PCI Map Failed for sns buf %p tag %x\n",
sc->sense_buffer, snic_cmd_tag(sc));
ret = -ENOMEM;
return ret;
}
int_to_scsilun(sc->device->lun, &lun);
if (sc->sc_data_direction == DMA_FROM_DEVICE)
flags |= SNIC_ICMND_RD;
if (sc->sc_data_direction == DMA_TO_DEVICE)
flags |= SNIC_ICMND_WR;
snic_icmnd_init(rqi->req,
snic_cmd_tag(sc),
snic->config.hid,
(ulong) rqi,
flags,
rqi->tgt_id,
lun.scsi_lun,
sc->cmnd,
sc->cmd_len,
scsi_bufflen(sc),
sg_cnt,
(ulong) req_to_sgl(rqi->req),
pa,
SCSI_SENSE_BUFFERSIZE);
ret = snic_queue_wq_desc(snic, rqi->req, rqi->req_len);
if (ret)
SNIC_HOST_ERR(snic->shost,
"QIcmnd: Queuing Icmnd Failed. ret = %d\n",
ret);
return ret;
}
static int
snic_issue_scsi_req(struct snic *snic,
struct snic_tgt *tgt,
struct scsi_cmnd *sc)
{
struct snic_req_info *rqi = NULL;
int sg_cnt = 0;
int ret = 0;
u32 tag = snic_cmd_tag(sc);
u64 cmd_trc = 0, cmd_st_flags = 0;
spinlock_t *io_lock = NULL;
unsigned long flags;
CMD_STATE(sc) = SNIC_IOREQ_NOT_INITED;
CMD_FLAGS(sc) = SNIC_NO_FLAGS;
sg_cnt = scsi_dma_map(sc);
if (sg_cnt < 0) {
SNIC_TRC((u16)snic->shost->host_no, tag, (ulong) sc, 0,
sc->cmnd[0], sg_cnt, CMD_STATE(sc));
SNIC_HOST_ERR(snic->shost, "issue_sc:Failed to map SG List.\n");
ret = -ENOMEM;
goto issue_sc_end;
}
rqi = snic_req_init(snic, sg_cnt);
if (!rqi) {
scsi_dma_unmap(sc);
ret = -ENOMEM;
goto issue_sc_end;
}
rqi->tgt_id = tgt->id;
rqi->sc = sc;
CMD_STATE(sc) = SNIC_IOREQ_PENDING;
CMD_SP(sc) = (char *) rqi;
cmd_trc = SNIC_TRC_CMD(sc);
CMD_FLAGS(sc) |= (SNIC_IO_INITIALIZED | SNIC_IO_ISSUED);
cmd_st_flags = SNIC_TRC_CMD_STATE_FLAGS(sc);
io_lock = snic_io_lock_hash(snic, sc);
ret = snic_queue_icmnd_req(snic, rqi, sc, sg_cnt);
if (ret) {
SNIC_HOST_ERR(snic->shost,
"issue_sc: icmnd qing Failed for sc %p, err %d\n",
sc, ret);
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
CMD_SP(sc) = NULL;
CMD_STATE(sc) = SNIC_IOREQ_COMPLETE;
CMD_FLAGS(sc) &= ~SNIC_IO_ISSUED;
spin_unlock_irqrestore(io_lock, flags);
if (rqi)
snic_release_req_buf(snic, rqi, sc);
SNIC_TRC(snic->shost->host_no, tag, (ulong) sc, 0, 0, 0,
SNIC_TRC_CMD_STATE_FLAGS(sc));
} else {
u32 io_sz = scsi_bufflen(sc) >> 9;
u32 qtime = jiffies - rqi->start_time;
struct snic_io_stats *iostats = &snic->s_stats.io;
if (io_sz > atomic64_read(&iostats->max_io_sz))
atomic64_set(&iostats->max_io_sz, io_sz);
if (qtime > atomic64_read(&iostats->max_qtime))
atomic64_set(&iostats->max_qtime, qtime);
SNIC_SCSI_DBG(snic->shost,
"issue_sc:sc %p, tag %d queued to WQ.\n",
sc, tag);
SNIC_TRC(snic->shost->host_no, tag, (ulong) sc, (ulong) rqi,
sg_cnt, cmd_trc, cmd_st_flags);
}
issue_sc_end:
return ret;
}
int
snic_queuecommand(struct Scsi_Host *shost, struct scsi_cmnd *sc)
{
struct snic_tgt *tgt = NULL;
struct snic *snic = shost_priv(shost);
int ret;
tgt = starget_to_tgt(scsi_target(sc->device));
ret = snic_tgt_chkready(tgt);
if (ret) {
SNIC_HOST_ERR(shost, "Tgt %p id %d Not Ready.\n", tgt, tgt->id);
atomic64_inc(&snic->s_stats.misc.tgt_not_rdy);
sc->result = ret;
sc->scsi_done(sc);
return 0;
}
if (snic_get_state(snic) != SNIC_ONLINE) {
SNIC_HOST_ERR(shost, "snic state is %s\n",
snic_state_str[snic_get_state(snic)]);
return SCSI_MLQUEUE_HOST_BUSY;
}
atomic_inc(&snic->ios_inflight);
SNIC_SCSI_DBG(shost, "sc %p Tag %d (sc %0x) lun %lld in snic_qcmd\n",
sc, snic_cmd_tag(sc), sc->cmnd[0], sc->device->lun);
memset(scsi_cmd_priv(sc), 0, sizeof(struct snic_internal_io_state));
ret = snic_issue_scsi_req(snic, tgt, sc);
if (ret) {
SNIC_HOST_ERR(shost, "Failed to Q, Scsi Req w/ err %d.\n", ret);
ret = SCSI_MLQUEUE_HOST_BUSY;
} else
snic_stats_update_active_ios(&snic->s_stats);
atomic_dec(&snic->ios_inflight);
return ret;
}
static void
snic_proc_tmreq_pending_state(struct snic *snic,
struct scsi_cmnd *sc,
u8 cmpl_status)
{
int state = CMD_STATE(sc);
if (state == SNIC_IOREQ_ABTS_PENDING)
CMD_FLAGS(sc) |= SNIC_IO_ABTS_PENDING;
else if (state == SNIC_IOREQ_LR_PENDING)
CMD_FLAGS(sc) |= SNIC_DEV_RST_PENDING;
else
SNIC_BUG_ON(1);
switch (cmpl_status) {
case SNIC_STAT_IO_SUCCESS:
CMD_FLAGS(sc) |= SNIC_IO_DONE;
break;
case SNIC_STAT_ABORTED:
CMD_FLAGS(sc) |= SNIC_IO_ABORTED;
break;
default:
SNIC_BUG_ON(1);
}
}
static void
snic_process_io_failed_state(struct snic *snic,
struct snic_icmnd_cmpl *icmnd_cmpl,
struct scsi_cmnd *sc,
u8 cmpl_stat)
{
int res = 0;
switch (cmpl_stat) {
case SNIC_STAT_TIMEOUT:
atomic64_inc(&snic->s_stats.misc.io_tmo);
res = DID_TIME_OUT;
break;
case SNIC_STAT_ABORTED:
atomic64_inc(&snic->s_stats.misc.io_aborted);
res = DID_ABORT;
break;
case SNIC_STAT_DATA_CNT_MISMATCH:
atomic64_inc(&snic->s_stats.misc.data_cnt_mismat);
scsi_set_resid(sc, le32_to_cpu(icmnd_cmpl->resid));
res = DID_ERROR;
break;
case SNIC_STAT_OUT_OF_RES:
atomic64_inc(&snic->s_stats.fw.out_of_res);
res = DID_REQUEUE;
break;
case SNIC_STAT_IO_NOT_FOUND:
atomic64_inc(&snic->s_stats.io.io_not_found);
res = DID_ERROR;
break;
case SNIC_STAT_SGL_INVALID:
atomic64_inc(&snic->s_stats.misc.sgl_inval);
res = DID_ERROR;
break;
case SNIC_STAT_FW_ERR:
atomic64_inc(&snic->s_stats.fw.io_errs);
res = DID_ERROR;
break;
case SNIC_STAT_SCSI_ERR:
atomic64_inc(&snic->s_stats.fw.scsi_errs);
break;
case SNIC_STAT_NOT_READY:
case SNIC_STAT_DEV_OFFLINE:
res = DID_NO_CONNECT;
break;
case SNIC_STAT_INVALID_HDR:
case SNIC_STAT_INVALID_PARM:
case SNIC_STAT_REQ_NOT_SUP:
case SNIC_STAT_CMND_REJECT:
case SNIC_STAT_FATAL_ERROR:
default:
SNIC_SCSI_DBG(snic->shost,
"Invalid Hdr/Param or Req Not Supported or Cmnd Rejected or Device Offline. or Unknown\n");
res = DID_ERROR;
break;
}
SNIC_HOST_ERR(snic->shost, "fw returns failed status %s flags 0x%llx\n",
snic_io_status_to_str(cmpl_stat), CMD_FLAGS(sc));
sc->result = (res << 16) | icmnd_cmpl->scsi_status;
}
static int
snic_tmreq_pending(struct scsi_cmnd *sc)
{
int state = CMD_STATE(sc);
return ((state == SNIC_IOREQ_ABTS_PENDING) ||
(state == SNIC_IOREQ_LR_PENDING));
}
static int
snic_process_icmnd_cmpl_status(struct snic *snic,
struct snic_icmnd_cmpl *icmnd_cmpl,
u8 cmpl_stat,
struct scsi_cmnd *sc)
{
u8 scsi_stat = icmnd_cmpl->scsi_status;
u64 xfer_len = 0;
int ret = 0;
CMD_STATE(sc) = SNIC_IOREQ_COMPLETE;
if (likely(cmpl_stat == SNIC_STAT_IO_SUCCESS)) {
sc->result = (DID_OK << 16) | scsi_stat;
xfer_len = scsi_bufflen(sc);
scsi_set_resid(sc, le32_to_cpu(icmnd_cmpl->resid));
if (icmnd_cmpl->flags & SNIC_ICMND_CMPL_UNDR_RUN) {
xfer_len -= le32_to_cpu(icmnd_cmpl->resid);
atomic64_inc(&snic->s_stats.misc.io_under_run);
}
if (icmnd_cmpl->scsi_status == SAM_STAT_TASK_SET_FULL)
atomic64_inc(&snic->s_stats.misc.qfull);
ret = 0;
} else {
snic_process_io_failed_state(snic, icmnd_cmpl, sc, cmpl_stat);
atomic64_inc(&snic->s_stats.io.fail);
SNIC_HOST_ERR(snic->shost,
"icmnd_cmpl: IO Failed : Hdr Status %s flags 0x%llx\n",
snic_io_status_to_str(cmpl_stat), CMD_FLAGS(sc));
ret = 1;
}
return ret;
}
static void
snic_icmnd_cmpl_handler(struct snic *snic, struct snic_fw_req *fwreq)
{
u8 typ, hdr_stat;
u32 cmnd_id, hid;
ulong ctx;
struct scsi_cmnd *sc = NULL;
struct snic_icmnd_cmpl *icmnd_cmpl = NULL;
struct snic_host_req *req = NULL;
struct snic_req_info *rqi = NULL;
unsigned long flags, start_time;
spinlock_t *io_lock;
u8 sc_stat = 0;
snic_io_hdr_dec(&fwreq->hdr, &typ, &hdr_stat, &cmnd_id, &hid, &ctx);
icmnd_cmpl = &fwreq->u.icmnd_cmpl;
sc_stat = icmnd_cmpl->scsi_status;
SNIC_SCSI_DBG(snic->shost,
"Icmnd_cmpl: type = %x, hdr_stat = %x, cmnd_id = %x, hid = %x,i ctx = %lx\n",
typ, hdr_stat, cmnd_id, hid, ctx);
if (cmnd_id >= snic->max_tag_id) {
SNIC_HOST_ERR(snic->shost,
"Icmnd_cmpl:Tag Error:Out of Range Tag %d, hdr status = %s\n",
cmnd_id, snic_io_status_to_str(hdr_stat));
return;
}
sc = scsi_host_find_tag(snic->shost, cmnd_id);
WARN_ON_ONCE(!sc);
if (!sc) {
atomic64_inc(&snic->s_stats.io.sc_null);
SNIC_HOST_ERR(snic->shost,
"Icmnd_cmpl: Scsi Cmnd Not found, sc = NULL Hdr Status = %s tag = 0x%x fwreq = 0x%p\n",
snic_io_status_to_str(hdr_stat),
cmnd_id,
fwreq);
SNIC_TRC(snic->shost->host_no, cmnd_id, 0,
((u64)hdr_stat << 16 |
(u64)sc_stat << 8 | (u64)icmnd_cmpl->flags),
(ulong) fwreq, le32_to_cpu(icmnd_cmpl->resid), ctx);
return;
}
io_lock = snic_io_lock_hash(snic, sc);
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
SNIC_SCSI_DBG(snic->shost,
"Icmnd_cmpl:lun %lld sc %p cmd %xtag %d flags 0x%llx rqi %p\n",
sc->device->lun, sc, sc->cmnd[0], snic_cmd_tag(sc),
CMD_FLAGS(sc), rqi);
SNIC_BUG_ON(rqi != (struct snic_req_info *)ctx);
WARN_ON_ONCE(req);
if (!rqi) {
atomic64_inc(&snic->s_stats.io.req_null);
CMD_FLAGS(sc) |= SNIC_IO_REQ_NULL;
spin_unlock_irqrestore(io_lock, flags);
SNIC_HOST_ERR(snic->shost,
"Icmnd_cmpl:Host Req Not Found(null), Hdr Status %s, Tag 0x%x, sc 0x%p flags 0x%llx\n",
snic_io_status_to_str(hdr_stat),
cmnd_id, sc, CMD_FLAGS(sc));
return;
}
rqi = (struct snic_req_info *) ctx;
start_time = rqi->start_time;
rqi->io_cmpl = 1;
if (unlikely(snic_tmreq_pending(sc))) {
snic_proc_tmreq_pending_state(snic, sc, hdr_stat);
spin_unlock_irqrestore(io_lock, flags);
snic_stats_update_io_cmpl(&snic->s_stats);
if (likely(hdr_stat == SNIC_STAT_ABORTED))
return;
SNIC_SCSI_DBG(snic->shost,
"icmnd_cmpl:TM Req Pending(%s), Hdr Status %s sc 0x%p scsi status %x resid %d flags 0x%llx\n",
snic_ioreq_state_to_str(CMD_STATE(sc)),
snic_io_status_to_str(hdr_stat),
sc, sc_stat, le32_to_cpu(icmnd_cmpl->resid),
CMD_FLAGS(sc));
SNIC_TRC(snic->shost->host_no, cmnd_id, (ulong) sc,
jiffies_to_msecs(jiffies - start_time), (ulong) fwreq,
SNIC_TRC_CMD(sc), SNIC_TRC_CMD_STATE_FLAGS(sc));
return;
}
if (snic_process_icmnd_cmpl_status(snic, icmnd_cmpl, hdr_stat, sc)) {
scsi_print_command(sc);
SNIC_HOST_ERR(snic->shost,
"icmnd_cmpl:IO Failed, sc 0x%p Tag %d Cmd %x Hdr Status %s flags 0x%llx\n",
sc, sc->cmnd[0], cmnd_id,
snic_io_status_to_str(hdr_stat), CMD_FLAGS(sc));
}
CMD_SP(sc) = NULL;
CMD_FLAGS(sc) |= SNIC_IO_DONE;
spin_unlock_irqrestore(io_lock, flags);
snic_calc_io_process_time(snic, rqi);
snic_release_req_buf(snic, rqi, sc);
SNIC_TRC(snic->shost->host_no, cmnd_id, (ulong) sc,
jiffies_to_msecs(jiffies - start_time), (ulong) fwreq,
SNIC_TRC_CMD(sc), SNIC_TRC_CMD_STATE_FLAGS(sc));
if (sc->scsi_done)
sc->scsi_done(sc);
snic_stats_update_io_cmpl(&snic->s_stats);
}
static void
snic_proc_dr_cmpl_locked(struct snic *snic,
struct snic_fw_req *fwreq,
u8 cmpl_stat,
u32 cmnd_id,
struct scsi_cmnd *sc)
{
struct snic_req_info *rqi = (struct snic_req_info *) CMD_SP(sc);
u32 start_time = rqi->start_time;
CMD_LR_STATUS(sc) = cmpl_stat;
SNIC_SCSI_DBG(snic->shost, "itmf_cmpl: Cmd State = %s\n",
snic_ioreq_state_to_str(CMD_STATE(sc)));
if (CMD_STATE(sc) == SNIC_IOREQ_ABTS_PENDING) {
CMD_FLAGS(sc) |= SNIC_DEV_RST_ABTS_PENDING;
SNIC_TRC(snic->shost->host_no, cmnd_id, (ulong) sc,
jiffies_to_msecs(jiffies - start_time),
(ulong) fwreq, 0, SNIC_TRC_CMD_STATE_FLAGS(sc));
SNIC_SCSI_DBG(snic->shost,
"itmf_cmpl: Terminate Pending Dev Reset Cmpl Recvd.id %x, status %s flags 0x%llx\n",
(int)(cmnd_id & SNIC_TAG_MASK),
snic_io_status_to_str(cmpl_stat),
CMD_FLAGS(sc));
return;
}
if (CMD_FLAGS(sc) & SNIC_DEV_RST_TIMEDOUT) {
SNIC_TRC(snic->shost->host_no, cmnd_id, (ulong) sc,
jiffies_to_msecs(jiffies - start_time),
(ulong) fwreq, 0, SNIC_TRC_CMD_STATE_FLAGS(sc));
SNIC_SCSI_DBG(snic->shost,
"itmf_cmpl:Dev Reset Completion Received after timeout. id %d cmpl status %s flags 0x%llx\n",
(int)(cmnd_id & SNIC_TAG_MASK),
snic_io_status_to_str(cmpl_stat),
CMD_FLAGS(sc));
return;
}
CMD_STATE(sc) = SNIC_IOREQ_LR_COMPLETE;
CMD_FLAGS(sc) |= SNIC_DEV_RST_DONE;
SNIC_SCSI_DBG(snic->shost,
"itmf_cmpl:Dev Reset Cmpl Recvd id %d cmpl status %s flags 0x%llx\n",
(int)(cmnd_id & SNIC_TAG_MASK),
snic_io_status_to_str(cmpl_stat),
CMD_FLAGS(sc));
if (rqi->dr_done)
complete(rqi->dr_done);
}
static void
snic_update_abort_stats(struct snic *snic, u8 cmpl_stat)
{
struct snic_abort_stats *abt_stats = &snic->s_stats.abts;
SNIC_SCSI_DBG(snic->shost, "Updating Abort stats.\n");
switch (cmpl_stat) {
case SNIC_STAT_IO_SUCCESS:
break;
case SNIC_STAT_TIMEOUT:
atomic64_inc(&abt_stats->fw_tmo);
break;
case SNIC_STAT_IO_NOT_FOUND:
atomic64_inc(&abt_stats->io_not_found);
break;
default:
atomic64_inc(&abt_stats->fail);
break;
}
}
static int
snic_process_itmf_cmpl(struct snic *snic,
struct snic_fw_req *fwreq,
u32 cmnd_id,
u8 cmpl_stat,
struct scsi_cmnd *sc)
{
struct snic_req_info *rqi = NULL;
u32 tm_tags = 0;
spinlock_t *io_lock = NULL;
unsigned long flags;
u32 start_time = 0;
int ret = 0;
io_lock = snic_io_lock_hash(snic, sc);
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
WARN_ON_ONCE(!rqi);
if (!rqi) {
atomic64_inc(&snic->s_stats.io.req_null);
spin_unlock_irqrestore(io_lock, flags);
CMD_FLAGS(sc) |= SNIC_IO_ABTS_TERM_REQ_NULL;
SNIC_HOST_ERR(snic->shost,
"itmf_cmpl: rqi is null,Hdr stat = %s Tag = 0x%x sc = 0x%p flags 0x%llx\n",
snic_io_status_to_str(cmpl_stat), cmnd_id, sc,
CMD_FLAGS(sc));
return ret;
}
tm_tags = cmnd_id & ~(SNIC_TAG_MASK);
start_time = rqi->start_time;
cmnd_id &= (SNIC_TAG_MASK);
switch (tm_tags) {
case SNIC_TAG_ABORT:
snic_update_abort_stats(snic, cmpl_stat);
if (CMD_STATE(sc) != SNIC_IOREQ_ABTS_PENDING) {
ret = -1;
spin_unlock_irqrestore(io_lock, flags);
break;
}
CMD_STATE(sc) = SNIC_IOREQ_ABTS_COMPLETE;
CMD_ABTS_STATUS(sc) = cmpl_stat;
CMD_FLAGS(sc) |= SNIC_IO_ABTS_TERM_DONE;
SNIC_SCSI_DBG(snic->shost,
"itmf_cmpl:Abort Cmpl Recvd.Tag 0x%x Status %s flags 0x%llx\n",
cmnd_id,
snic_io_status_to_str(cmpl_stat),
CMD_FLAGS(sc));
if (rqi->abts_done) {
complete(rqi->abts_done);
spin_unlock_irqrestore(io_lock, flags);
break;
}
CMD_SP(sc) = NULL;
sc->result = (DID_ERROR << 16);
SNIC_SCSI_DBG(snic->shost,
"itmf_cmpl: Completing IO. sc %p flags 0x%llx\n",
sc, CMD_FLAGS(sc));
spin_unlock_irqrestore(io_lock, flags);
snic_release_req_buf(snic, rqi, sc);
if (sc->scsi_done) {
SNIC_TRC(snic->shost->host_no, cmnd_id, (ulong) sc,
jiffies_to_msecs(jiffies - start_time),
(ulong) fwreq, SNIC_TRC_CMD(sc),
SNIC_TRC_CMD_STATE_FLAGS(sc));
sc->scsi_done(sc);
}
break;
case SNIC_TAG_DEV_RST:
case SNIC_TAG_DEV_RST | SNIC_TAG_IOCTL_DEV_RST:
snic_proc_dr_cmpl_locked(snic, fwreq, cmpl_stat, cmnd_id, sc);
spin_unlock_irqrestore(io_lock, flags);
ret = 0;
break;
case SNIC_TAG_ABORT | SNIC_TAG_DEV_RST:
CMD_STATE(sc) = SNIC_IOREQ_ABTS_COMPLETE;
CMD_ABTS_STATUS(sc) = cmpl_stat;
CMD_FLAGS(sc) |= SNIC_DEV_RST_DONE;
SNIC_SCSI_DBG(snic->shost,
"itmf_cmpl:dev reset abts cmpl recvd. id %d status %s flags 0x%llx\n",
cmnd_id, snic_io_status_to_str(cmpl_stat),
CMD_FLAGS(sc));
if (rqi->abts_done)
complete(rqi->abts_done);
spin_unlock_irqrestore(io_lock, flags);
break;
default:
spin_unlock_irqrestore(io_lock, flags);
SNIC_HOST_ERR(snic->shost,
"itmf_cmpl: Unknown TM tag bit 0x%x\n", tm_tags);
SNIC_HOST_ERR(snic->shost,
"itmf_cmpl:Unexpected itmf io stat %s Tag = 0x%x flags 0x%llx\n",
snic_ioreq_state_to_str(CMD_STATE(sc)),
cmnd_id,
CMD_FLAGS(sc));
ret = -1;
SNIC_BUG_ON(1);
break;
}
return ret;
}
static void
snic_itmf_cmpl_handler(struct snic *snic, struct snic_fw_req *fwreq)
{
struct scsi_cmnd *sc = NULL;
struct snic_req_info *rqi = NULL;
struct snic_itmf_cmpl *itmf_cmpl = NULL;
ulong ctx;
u32 cmnd_id;
u32 hid;
u8 typ;
u8 hdr_stat;
snic_io_hdr_dec(&fwreq->hdr, &typ, &hdr_stat, &cmnd_id, &hid, &ctx);
SNIC_SCSI_DBG(snic->shost,
"Itmf_cmpl: %s: type = %x, hdr_stat = %x, cmnd_id = %x, hid = %x,ctx = %lx\n",
__func__, typ, hdr_stat, cmnd_id, hid, ctx);
itmf_cmpl = &fwreq->u.itmf_cmpl;
SNIC_SCSI_DBG(snic->shost,
"Itmf_cmpl: nterm %u , flags 0x%x\n",
le32_to_cpu(itmf_cmpl->nterminated), itmf_cmpl->flags);
if (cmnd_id & SNIC_TAG_IOCTL_DEV_RST) {
rqi = (struct snic_req_info *) ctx;
sc = rqi->sc;
goto ioctl_dev_rst;
}
if ((cmnd_id & SNIC_TAG_MASK) >= snic->max_tag_id) {
SNIC_HOST_ERR(snic->shost,
"Itmf_cmpl: Tag 0x%x out of Range,HdrStat %s\n",
cmnd_id, snic_io_status_to_str(hdr_stat));
SNIC_BUG_ON(1);
return;
}
sc = scsi_host_find_tag(snic->shost, cmnd_id & SNIC_TAG_MASK);
WARN_ON_ONCE(!sc);
ioctl_dev_rst:
if (!sc) {
atomic64_inc(&snic->s_stats.io.sc_null);
SNIC_HOST_ERR(snic->shost,
"Itmf_cmpl: sc is NULL - Hdr Stat %s Tag 0x%x\n",
snic_io_status_to_str(hdr_stat), cmnd_id);
return;
}
snic_process_itmf_cmpl(snic, fwreq, cmnd_id, hdr_stat, sc);
}
static void
snic_hba_reset_scsi_cleanup(struct snic *snic, struct scsi_cmnd *sc)
{
struct snic_stats *st = &snic->s_stats;
long act_ios = 0, act_fwreqs = 0;
SNIC_SCSI_DBG(snic->shost, "HBA Reset scsi cleanup.\n");
snic_scsi_cleanup(snic, snic_cmd_tag(sc));
act_ios = atomic64_read(&st->io.active);
atomic64_add(act_ios, &st->io.compl);
atomic64_sub(act_ios, &st->io.active);
act_fwreqs = atomic64_read(&st->fw.actv_reqs);
atomic64_sub(act_fwreqs, &st->fw.actv_reqs);
}
static int
snic_hba_reset_cmpl_handler(struct snic *snic, struct snic_fw_req *fwreq)
{
ulong ctx;
u32 cmnd_id;
u32 hid;
u8 typ;
u8 hdr_stat;
struct scsi_cmnd *sc = NULL;
struct snic_req_info *rqi = NULL;
spinlock_t *io_lock = NULL;
unsigned long flags, gflags;
int ret = 0;
SNIC_HOST_INFO(snic->shost,
"reset_cmpl:HBA Reset Completion received.\n");
snic_io_hdr_dec(&fwreq->hdr, &typ, &hdr_stat, &cmnd_id, &hid, &ctx);
SNIC_SCSI_DBG(snic->shost,
"reset_cmpl: type = %x, hdr_stat = %x, cmnd_id = %x, hid = %x, ctx = %lx\n",
typ, hdr_stat, cmnd_id, hid, ctx);
if (cmnd_id == SCSI_NO_TAG) {
rqi = (struct snic_req_info *) ctx;
sc = rqi->sc;
goto ioctl_hba_rst;
}
if (cmnd_id >= snic->max_tag_id) {
SNIC_HOST_ERR(snic->shost,
"reset_cmpl: Tag 0x%x out of Range,HdrStat %s\n",
cmnd_id, snic_io_status_to_str(hdr_stat));
SNIC_BUG_ON(1);
return 1;
}
sc = scsi_host_find_tag(snic->shost, cmnd_id);
ioctl_hba_rst:
if (!sc) {
atomic64_inc(&snic->s_stats.io.sc_null);
SNIC_HOST_ERR(snic->shost,
"reset_cmpl: sc is NULL - Hdr Stat %s Tag 0x%x\n",
snic_io_status_to_str(hdr_stat), cmnd_id);
ret = 1;
return ret;
}
io_lock = snic_io_lock_hash(snic, sc);
spin_lock_irqsave(io_lock, flags);
if (!snic->remove_wait) {
spin_unlock_irqrestore(io_lock, flags);
SNIC_HOST_ERR(snic->shost,
"reset_cmpl:host reset completed after timout\n");
ret = 1;
return ret;
}
rqi = (struct snic_req_info *) CMD_SP(sc);
WARN_ON_ONCE(!rqi);
if (!rqi) {
atomic64_inc(&snic->s_stats.io.req_null);
spin_unlock_irqrestore(io_lock, flags);
CMD_FLAGS(sc) |= SNIC_IO_ABTS_TERM_REQ_NULL;
SNIC_HOST_ERR(snic->shost,
"reset_cmpl: rqi is null,Hdr stat %s Tag 0x%x sc 0x%p flags 0x%llx\n",
snic_io_status_to_str(hdr_stat), cmnd_id, sc,
CMD_FLAGS(sc));
ret = 1;
return ret;
}
spin_unlock_irqrestore(io_lock, flags);
snic_hba_reset_scsi_cleanup(snic, sc);
SNIC_BUG_ON(snic_get_state(snic) != SNIC_OFFLINE &&
snic_get_state(snic) != SNIC_FWRESET);
spin_lock_irqsave(io_lock, flags);
spin_lock_irqsave(&snic->snic_lock, gflags);
if (snic_get_state(snic) == SNIC_FWRESET)
snic_set_state(snic, SNIC_ONLINE);
spin_unlock_irqrestore(&snic->snic_lock, gflags);
if (snic->remove_wait)
complete(snic->remove_wait);
spin_unlock_irqrestore(io_lock, flags);
atomic64_inc(&snic->s_stats.reset.hba_reset_cmpl);
ret = 0;
if (snic->config.xpt_type == SNIC_DAS)
return ret;
SNIC_SCSI_DBG(snic->shost, "reset_cmpl: Queuing discovery work.\n");
queue_work(snic_glob->event_q, &snic->disc_work);
return ret;
}
static void
snic_msg_ack_handler(struct snic *snic, struct snic_fw_req *fwreq)
{
SNIC_HOST_INFO(snic->shost, "Message Ack Received.\n");
SNIC_ASSERT_NOT_IMPL(1);
}
static void
snic_aen_handler(struct snic *snic, struct snic_fw_req *fwreq)
{
u8 typ, hdr_stat;
u32 cmnd_id, hid;
ulong ctx;
struct snic_async_evnotify *aen = &fwreq->u.async_ev;
u32 event_id = 0;
snic_io_hdr_dec(&fwreq->hdr, &typ, &hdr_stat, &cmnd_id, &hid, &ctx);
SNIC_SCSI_DBG(snic->shost,
"aen: type = %x, hdr_stat = %x, cmnd_id = %x, hid = %x, ctx = %lx\n",
typ, hdr_stat, cmnd_id, hid, ctx);
event_id = le32_to_cpu(aen->ev_id);
switch (event_id) {
case SNIC_EV_TGT_OFFLINE:
SNIC_HOST_INFO(snic->shost, "aen:TGT_OFFLINE Event Recvd.\n");
break;
case SNIC_EV_TGT_ONLINE:
SNIC_HOST_INFO(snic->shost, "aen:TGT_ONLINE Event Recvd.\n");
break;
case SNIC_EV_LUN_OFFLINE:
SNIC_HOST_INFO(snic->shost, "aen:LUN_OFFLINE Event Recvd.\n");
break;
case SNIC_EV_LUN_ONLINE:
SNIC_HOST_INFO(snic->shost, "aen:LUN_ONLINE Event Recvd.\n");
break;
case SNIC_EV_CONF_CHG:
SNIC_HOST_INFO(snic->shost, "aen:Config Change Event Recvd.\n");
break;
case SNIC_EV_TGT_ADDED:
SNIC_HOST_INFO(snic->shost, "aen:TGT_ADD Event Recvd.\n");
break;
case SNIC_EV_TGT_DELTD:
SNIC_HOST_INFO(snic->shost, "aen:TGT_DEL Event Recvd.\n");
break;
case SNIC_EV_LUN_ADDED:
SNIC_HOST_INFO(snic->shost, "aen:LUN_ADD Event Recvd.\n");
break;
case SNIC_EV_LUN_DELTD:
SNIC_HOST_INFO(snic->shost, "aen:LUN_DEL Event Recvd.\n");
break;
case SNIC_EV_DISC_CMPL:
SNIC_HOST_INFO(snic->shost, "aen:DISC_CMPL Event Recvd.\n");
break;
default:
SNIC_HOST_INFO(snic->shost, "aen:Unknown Event Recvd.\n");
SNIC_BUG_ON(1);
break;
}
SNIC_ASSERT_NOT_IMPL(1);
}
static int
snic_io_cmpl_handler(struct vnic_dev *vdev,
unsigned int cq_idx,
struct snic_fw_req *fwreq)
{
struct snic *snic = svnic_dev_priv(vdev);
u64 start = jiffies, cmpl_time;
snic_print_desc(__func__, (char *)fwreq, sizeof(*fwreq));
if ((fwreq->hdr.type >= SNIC_RSP_REPORT_TGTS_CMPL) &&
(fwreq->hdr.type <= SNIC_RSP_BOOT_LUNS_CMPL))
atomic64_dec(&snic->s_stats.fw.actv_reqs);
SNIC_BUG_ON((fwreq->hdr.type > SNIC_RSP_BOOT_LUNS_CMPL) &&
(fwreq->hdr.type < SNIC_MSG_ASYNC_EVNOTIFY));
switch (fwreq->hdr.status) {
case SNIC_STAT_NOT_READY:
SNIC_HOST_ERR(snic->shost,
"sNIC SubSystem is NOT Ready.\n");
break;
case SNIC_STAT_FATAL_ERROR:
SNIC_HOST_ERR(snic->shost,
"sNIC SubSystem in Unrecoverable State.\n");
break;
}
switch (fwreq->hdr.type) {
case SNIC_RSP_EXCH_VER_CMPL:
snic_io_exch_ver_cmpl_handler(snic, fwreq);
break;
case SNIC_RSP_REPORT_TGTS_CMPL:
snic_report_tgt_cmpl_handler(snic, fwreq);
break;
case SNIC_RSP_ICMND_CMPL:
snic_icmnd_cmpl_handler(snic, fwreq);
break;
case SNIC_RSP_ITMF_CMPL:
snic_itmf_cmpl_handler(snic, fwreq);
break;
case SNIC_RSP_HBA_RESET_CMPL:
snic_hba_reset_cmpl_handler(snic, fwreq);
break;
case SNIC_MSG_ACK:
snic_msg_ack_handler(snic, fwreq);
break;
case SNIC_MSG_ASYNC_EVNOTIFY:
snic_aen_handler(snic, fwreq);
break;
default:
SNIC_BUG_ON(1);
SNIC_SCSI_DBG(snic->shost,
"Unknown Firmwqre completion request type %d\n",
fwreq->hdr.type);
break;
}
cmpl_time = jiffies - start;
if (cmpl_time > atomic64_read(&snic->s_stats.io.max_cmpl_time))
atomic64_set(&snic->s_stats.io.max_cmpl_time, cmpl_time);
return 0;
}
int
snic_fwcq_cmpl_handler(struct snic *snic, int io_cmpl_work)
{
unsigned int num_ent = 0;
unsigned int cq_idx;
unsigned int nent_per_cq;
struct snic_misc_stats *misc_stats = &snic->s_stats.misc;
for (cq_idx = snic->wq_count; cq_idx < snic->cq_count; cq_idx++) {
nent_per_cq = vnic_cq_fw_service(&snic->cq[cq_idx],
snic_io_cmpl_handler,
io_cmpl_work);
num_ent += nent_per_cq;
if (nent_per_cq > atomic64_read(&misc_stats->max_cq_ents))
atomic64_set(&misc_stats->max_cq_ents, nent_per_cq);
}
return num_ent;
}
static int
snic_queue_itmf_req(struct snic *snic,
struct snic_host_req *tmreq,
struct scsi_cmnd *sc,
u32 tmf,
u32 req_id)
{
struct snic_req_info *rqi = req_to_rqi(tmreq);
struct scsi_lun lun;
int tm_tag = snic_cmd_tag(sc) | rqi->tm_tag;
int ret = 0;
SNIC_BUG_ON(!rqi);
SNIC_BUG_ON(!rqi->tm_tag);
int_to_scsilun(sc->device->lun, &lun);
snic_itmf_init(tmreq,
tm_tag,
snic->config.hid,
(ulong) rqi,
0 ,
req_id,
rqi->tgt_id,
lun.scsi_lun,
tmf);
ret = snic_queue_wq_desc(snic, tmreq, sizeof(*tmreq));
if (ret)
SNIC_HOST_ERR(snic->shost,
"qitmf:Queuing ITMF(%d) Req sc %p, rqi %p, req_id %d tag %d Failed, ret = %d\n",
tmf, sc, rqi, req_id, snic_cmd_tag(sc), ret);
else
SNIC_SCSI_DBG(snic->shost,
"qitmf:Queuing ITMF(%d) Req sc %p, rqi %p, req_id %d, tag %d (req_id)- Success.",
tmf, sc, rqi, req_id, snic_cmd_tag(sc));
return ret;
}
static int
snic_issue_tm_req(struct snic *snic,
struct snic_req_info *rqi,
struct scsi_cmnd *sc,
int tmf)
{
struct snic_host_req *tmreq = NULL;
int req_id = 0, tag = snic_cmd_tag(sc);
int ret = 0;
if (snic_get_state(snic) == SNIC_FWRESET)
return -EBUSY;
atomic_inc(&snic->ios_inflight);
SNIC_SCSI_DBG(snic->shost,
"issu_tmreq: Task mgmt req %d. rqi %p w/ tag %x\n",
tmf, rqi, tag);
if (tmf == SNIC_ITMF_LUN_RESET) {
tmreq = snic_dr_req_init(snic, rqi);
req_id = SCSI_NO_TAG;
} else {
tmreq = snic_abort_req_init(snic, rqi);
req_id = tag;
}
if (!tmreq) {
ret = -ENOMEM;
goto tmreq_err;
}
ret = snic_queue_itmf_req(snic, tmreq, sc, tmf, req_id);
if (ret)
goto tmreq_err;
ret = 0;
tmreq_err:
if (ret) {
SNIC_HOST_ERR(snic->shost,
"issu_tmreq: Queing ITMF(%d) Req, sc %p rqi %p req_id %d tag %x fails err = %d\n",
tmf, sc, rqi, req_id, tag, ret);
} else {
SNIC_SCSI_DBG(snic->shost,
"issu_tmreq: Queuing ITMF(%d) Req, sc %p, rqi %p, req_id %d tag %x - Success.\n",
tmf, sc, rqi, req_id, tag);
}
atomic_dec(&snic->ios_inflight);
return ret;
}
static int
snic_queue_abort_req(struct snic *snic,
struct snic_req_info *rqi,
struct scsi_cmnd *sc,
int tmf)
{
SNIC_SCSI_DBG(snic->shost, "q_abtreq: sc %p, rqi %p, tag %x, tmf %d\n",
sc, rqi, snic_cmd_tag(sc), tmf);
rqi->tm_tag |= SNIC_TAG_ABORT;
return snic_issue_tm_req(snic, rqi, sc, tmf);
}
static int
snic_abort_finish(struct snic *snic, struct scsi_cmnd *sc)
{
struct snic_req_info *rqi = NULL;
spinlock_t *io_lock = NULL;
unsigned long flags;
int ret = 0, tag = snic_cmd_tag(sc);
io_lock = snic_io_lock_hash(snic, sc);
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
if (!rqi) {
atomic64_inc(&snic->s_stats.io.req_null);
CMD_FLAGS(sc) |= SNIC_IO_ABTS_TERM_REQ_NULL;
SNIC_SCSI_DBG(snic->shost,
"abt_fini:req info is null tag 0x%x, sc 0x%p flags 0x%llx\n",
tag, sc, CMD_FLAGS(sc));
ret = FAILED;
goto abort_fail;
}
rqi->abts_done = NULL;
ret = FAILED;
switch (CMD_ABTS_STATUS(sc)) {
case SNIC_INVALID_CODE:
CMD_FLAGS(sc) |= SNIC_IO_ABTS_TIMEDOUT;
atomic64_inc(&snic->s_stats.abts.drv_tmo);
SNIC_SCSI_DBG(snic->shost,
"abt_fini:sc %p Tag %x Driver Timeout.flags 0x%llx\n",
sc, snic_cmd_tag(sc), CMD_FLAGS(sc));
rqi = NULL;
goto abort_fail;
case SNIC_STAT_IO_SUCCESS:
case SNIC_STAT_IO_NOT_FOUND:
ret = SUCCESS;
break;
default:
ret = FAILED;
break;
}
CMD_SP(sc) = NULL;
SNIC_HOST_INFO(snic->shost,
"abt_fini: Tag %x, Cmpl Status %s flags 0x%llx\n",
tag, snic_io_status_to_str(CMD_ABTS_STATUS(sc)),
CMD_FLAGS(sc));
abort_fail:
spin_unlock_irqrestore(io_lock, flags);
if (rqi)
snic_release_req_buf(snic, rqi, sc);
return ret;
}
static int
snic_send_abort_and_wait(struct snic *snic, struct scsi_cmnd *sc)
{
struct snic_req_info *rqi = NULL;
enum snic_ioreq_state sv_state;
struct snic_tgt *tgt = NULL;
spinlock_t *io_lock = NULL;
DECLARE_COMPLETION_ONSTACK(tm_done);
unsigned long flags;
int ret = 0, tmf = 0, tag = snic_cmd_tag(sc);
tgt = starget_to_tgt(scsi_target(sc->device));
if ((snic_tgt_chkready(tgt) != 0) && (tgt->tdata.typ == SNIC_TGT_SAN))
tmf = SNIC_ITMF_ABTS_TASK_TERM;
else
tmf = SNIC_ITMF_ABTS_TASK;
io_lock = snic_io_lock_hash(snic, sc);
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
if (!rqi) {
spin_unlock_irqrestore(io_lock, flags);
SNIC_HOST_ERR(snic->shost,
"abt_cmd: rqi is null. Tag %d flags 0x%llx\n",
tag, CMD_FLAGS(sc));
ret = SUCCESS;
goto send_abts_end;
}
rqi->abts_done = &tm_done;
if (CMD_STATE(sc) == SNIC_IOREQ_ABTS_PENDING) {
spin_unlock_irqrestore(io_lock, flags);
ret = 0;
goto abts_pending;
}
SNIC_BUG_ON(!rqi->abts_done);
sv_state = CMD_STATE(sc);
CMD_STATE(sc) = SNIC_IOREQ_ABTS_PENDING;
CMD_ABTS_STATUS(sc) = SNIC_INVALID_CODE;
SNIC_SCSI_DBG(snic->shost, "send_abt_cmd: TAG 0x%x\n", tag);
spin_unlock_irqrestore(io_lock, flags);
ret = snic_queue_abort_req(snic, rqi, sc, tmf);
if (ret) {
SNIC_HOST_ERR(snic->shost,
"send_abt_cmd: IO w/ Tag 0x%x fail w/ err %d flags 0x%llx\n",
tag, ret, CMD_FLAGS(sc));
spin_lock_irqsave(io_lock, flags);
CMD_STATE(sc) = sv_state;
rqi = (struct snic_req_info *) CMD_SP(sc);
if (rqi)
rqi->abts_done = NULL;
spin_unlock_irqrestore(io_lock, flags);
ret = FAILED;
goto send_abts_end;
}
spin_lock_irqsave(io_lock, flags);
if (tmf == SNIC_ITMF_ABTS_TASK) {
CMD_FLAGS(sc) |= SNIC_IO_ABTS_ISSUED;
atomic64_inc(&snic->s_stats.abts.num);
} else {
CMD_FLAGS(sc) |= SNIC_IO_TERM_ISSUED;
}
spin_unlock_irqrestore(io_lock, flags);
SNIC_SCSI_DBG(snic->shost,
"send_abt_cmd: sc %p Tag %x flags 0x%llx\n",
sc, tag, CMD_FLAGS(sc));
ret = 0;
abts_pending:
wait_for_completion_timeout(&tm_done, SNIC_ABTS_TIMEOUT);
send_abts_end:
return ret;
}
int
snic_abort_cmd(struct scsi_cmnd *sc)
{
struct snic *snic = shost_priv(sc->device->host);
int ret = SUCCESS, tag = snic_cmd_tag(sc);
u32 start_time = jiffies;
SNIC_SCSI_DBG(snic->shost, "abt_cmd:sc %p :0x%x :req = %p :tag = %d\n",
sc, sc->cmnd[0], sc->request, tag);
if (unlikely(snic_get_state(snic) != SNIC_ONLINE)) {
SNIC_HOST_ERR(snic->shost,
"abt_cmd: tag %x Parent Devs are not rdy\n",
tag);
ret = FAST_IO_FAIL;
goto abort_end;
}
ret = snic_send_abort_and_wait(snic, sc);
if (ret)
goto abort_end;
ret = snic_abort_finish(snic, sc);
abort_end:
SNIC_TRC(snic->shost->host_no, tag, (ulong) sc,
jiffies_to_msecs(jiffies - start_time), 0,
SNIC_TRC_CMD(sc), SNIC_TRC_CMD_STATE_FLAGS(sc));
SNIC_SCSI_DBG(snic->shost,
"abts: Abort Req Status = %s\n",
(ret == SUCCESS) ? "SUCCESS" :
((ret == FAST_IO_FAIL) ? "FAST_IO_FAIL" : "FAILED"));
return ret;
}
static int
snic_is_abts_pending(struct snic *snic, struct scsi_cmnd *lr_sc)
{
struct snic_req_info *rqi = NULL;
struct scsi_cmnd *sc = NULL;
struct scsi_device *lr_sdev = NULL;
spinlock_t *io_lock = NULL;
u32 tag;
unsigned long flags;
if (lr_sc)
lr_sdev = lr_sc->device;
for (tag = 0; tag < snic->max_tag_id; tag++) {
io_lock = snic_io_lock_tag(snic, tag);
spin_lock_irqsave(io_lock, flags);
sc = scsi_host_find_tag(snic->shost, tag);
if (!sc || (lr_sc && (sc->device != lr_sdev || sc == lr_sc))) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
rqi = (struct snic_req_info *) CMD_SP(sc);
if (!rqi) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
SNIC_SCSI_DBG(snic->shost, "Found IO in %s on LUN\n",
snic_ioreq_state_to_str(CMD_STATE(sc)));
if (CMD_STATE(sc) == SNIC_IOREQ_ABTS_PENDING) {
spin_unlock_irqrestore(io_lock, flags);
return 1;
}
spin_unlock_irqrestore(io_lock, flags);
}
return 0;
}
static int
snic_dr_clean_single_req(struct snic *snic,
u32 tag,
struct scsi_device *lr_sdev)
{
struct snic_req_info *rqi = NULL;
struct snic_tgt *tgt = NULL;
struct scsi_cmnd *sc = NULL;
spinlock_t *io_lock = NULL;
u32 sv_state = 0, tmf = 0;
DECLARE_COMPLETION_ONSTACK(tm_done);
unsigned long flags;
int ret = 0;
io_lock = snic_io_lock_tag(snic, tag);
spin_lock_irqsave(io_lock, flags);
sc = scsi_host_find_tag(snic->shost, tag);
if (!sc || sc->device != lr_sdev)
goto skip_clean;
rqi = (struct snic_req_info *) CMD_SP(sc);
if (!rqi)
goto skip_clean;
if (CMD_STATE(sc) == SNIC_IOREQ_ABTS_PENDING)
goto skip_clean;
if ((CMD_FLAGS(sc) & SNIC_DEVICE_RESET) &&
(!(CMD_FLAGS(sc) & SNIC_DEV_RST_ISSUED))) {
SNIC_SCSI_DBG(snic->shost,
"clean_single_req: devrst is not pending sc 0x%p\n",
sc);
goto skip_clean;
}
SNIC_SCSI_DBG(snic->shost,
"clean_single_req: Found IO in %s on lun\n",
snic_ioreq_state_to_str(CMD_STATE(sc)));
sv_state = CMD_STATE(sc);
CMD_STATE(sc) = SNIC_IOREQ_ABTS_PENDING;
SNIC_BUG_ON(rqi->abts_done);
if (CMD_FLAGS(sc) & SNIC_DEVICE_RESET) {
rqi->tm_tag = SNIC_TAG_DEV_RST;
SNIC_SCSI_DBG(snic->shost,
"clean_single_req:devrst sc 0x%p\n", sc);
}
CMD_ABTS_STATUS(sc) = SNIC_INVALID_CODE;
rqi->abts_done = &tm_done;
spin_unlock_irqrestore(io_lock, flags);
tgt = starget_to_tgt(scsi_target(sc->device));
if ((snic_tgt_chkready(tgt) != 0) && (tgt->tdata.typ == SNIC_TGT_SAN))
tmf = SNIC_ITMF_ABTS_TASK_TERM;
else
tmf = SNIC_ITMF_ABTS_TASK;
ret = snic_queue_abort_req(snic, rqi, sc, tmf);
if (ret) {
SNIC_HOST_ERR(snic->shost,
"clean_single_req_err:sc %p, tag %d abt failed. tm_tag %d flags 0x%llx\n",
sc, tag, rqi->tm_tag, CMD_FLAGS(sc));
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
if (rqi)
rqi->abts_done = NULL;
if (CMD_STATE(sc) == SNIC_IOREQ_ABTS_PENDING)
CMD_STATE(sc) = sv_state;
ret = 1;
goto skip_clean;
}
spin_lock_irqsave(io_lock, flags);
if (CMD_FLAGS(sc) & SNIC_DEVICE_RESET)
CMD_FLAGS(sc) |= SNIC_DEV_RST_TERM_ISSUED;
CMD_FLAGS(sc) |= SNIC_IO_INTERNAL_TERM_ISSUED;
spin_unlock_irqrestore(io_lock, flags);
wait_for_completion_timeout(&tm_done, SNIC_ABTS_TIMEOUT);
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
if (!rqi) {
CMD_FLAGS(sc) |= SNIC_IO_ABTS_TERM_REQ_NULL;
goto skip_clean;
}
rqi->abts_done = NULL;
if (CMD_ABTS_STATUS(sc) == SNIC_INVALID_CODE) {
SNIC_HOST_ERR(snic->shost,
"clean_single_req_err:sc %p tag %d abt still pending w/ fw, tm_tag %d flags 0x%llx\n",
sc, tag, rqi->tm_tag, CMD_FLAGS(sc));
CMD_FLAGS(sc) |= SNIC_IO_ABTS_TERM_DONE;
ret = 1;
goto skip_clean;
}
CMD_STATE(sc) = SNIC_IOREQ_ABTS_COMPLETE;
CMD_SP(sc) = NULL;
spin_unlock_irqrestore(io_lock, flags);
snic_release_req_buf(snic, rqi, sc);
ret = 0;
return ret;
skip_clean:
spin_unlock_irqrestore(io_lock, flags);
return ret;
}
static int
snic_dr_clean_pending_req(struct snic *snic, struct scsi_cmnd *lr_sc)
{
struct scsi_device *lr_sdev = lr_sc->device;
u32 tag = 0;
int ret = FAILED;
for (tag = 0; tag < snic->max_tag_id; tag++) {
if (tag == snic_cmd_tag(lr_sc))
continue;
ret = snic_dr_clean_single_req(snic, tag, lr_sdev);
if (ret) {
SNIC_HOST_ERR(snic->shost, "clean_err:tag = %d\n", tag);
goto clean_err;
}
}
schedule_timeout(msecs_to_jiffies(100));
if (snic_is_abts_pending(snic, lr_sc)) {
ret = FAILED;
goto clean_err;
}
ret = 0;
SNIC_SCSI_DBG(snic->shost, "clean_pending_req: Success.\n");
return ret;
clean_err:
ret = FAILED;
SNIC_HOST_ERR(snic->shost,
"Failed to Clean Pending IOs on %s device.\n",
dev_name(&lr_sdev->sdev_gendev));
return ret;
}
static int
snic_dr_finish(struct snic *snic, struct scsi_cmnd *sc)
{
struct snic_req_info *rqi = NULL;
spinlock_t *io_lock = NULL;
unsigned long flags;
int lr_res = 0;
int ret = FAILED;
io_lock = snic_io_lock_hash(snic, sc);
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
if (!rqi) {
spin_unlock_irqrestore(io_lock, flags);
SNIC_SCSI_DBG(snic->shost,
"dr_fini: rqi is null tag 0x%x sc 0x%p flags 0x%llx\n",
snic_cmd_tag(sc), sc, CMD_FLAGS(sc));
ret = FAILED;
goto dr_fini_end;
}
rqi->dr_done = NULL;
lr_res = CMD_LR_STATUS(sc);
switch (lr_res) {
case SNIC_INVALID_CODE:
SNIC_SCSI_DBG(snic->shost,
"dr_fini: Tag %x Dev Reset Timedout. flags 0x%llx\n",
snic_cmd_tag(sc), CMD_FLAGS(sc));
CMD_FLAGS(sc) |= SNIC_DEV_RST_TIMEDOUT;
ret = FAILED;
goto dr_failed;
case SNIC_STAT_IO_SUCCESS:
SNIC_SCSI_DBG(snic->shost,
"dr_fini: Tag %x Dev Reset cmpl\n",
snic_cmd_tag(sc));
ret = 0;
break;
default:
SNIC_HOST_ERR(snic->shost,
"dr_fini:Device Reset completed& failed.Tag = %x lr_status %s flags 0x%llx\n",
snic_cmd_tag(sc),
snic_io_status_to_str(lr_res), CMD_FLAGS(sc));
ret = FAILED;
goto dr_failed;
}
spin_unlock_irqrestore(io_lock, flags);
ret = snic_dr_clean_pending_req(snic, sc);
if (ret) {
spin_lock_irqsave(io_lock, flags);
SNIC_SCSI_DBG(snic->shost,
"dr_fini: Device Reset Failed since could not abort all IOs. Tag = %x.\n",
snic_cmd_tag(sc));
rqi = (struct snic_req_info *) CMD_SP(sc);
goto dr_failed;
} else {
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
if (rqi)
ret = SUCCESS;
else
ret = FAILED;
}
dr_failed:
SNIC_BUG_ON(!spin_is_locked(io_lock));
if (rqi)
CMD_SP(sc) = NULL;
spin_unlock_irqrestore(io_lock, flags);
if (rqi)
snic_release_req_buf(snic, rqi, sc);
dr_fini_end:
return ret;
}
static int
snic_queue_dr_req(struct snic *snic,
struct snic_req_info *rqi,
struct scsi_cmnd *sc)
{
rqi->tm_tag |= SNIC_TAG_DEV_RST;
return snic_issue_tm_req(snic, rqi, sc, SNIC_ITMF_LUN_RESET);
}
static int
snic_send_dr_and_wait(struct snic *snic, struct scsi_cmnd *sc)
{
struct snic_req_info *rqi = NULL;
enum snic_ioreq_state sv_state;
spinlock_t *io_lock = NULL;
unsigned long flags;
DECLARE_COMPLETION_ONSTACK(tm_done);
int ret = FAILED, tag = snic_cmd_tag(sc);
io_lock = snic_io_lock_hash(snic, sc);
spin_lock_irqsave(io_lock, flags);
CMD_FLAGS(sc) |= SNIC_DEVICE_RESET;
rqi = (struct snic_req_info *) CMD_SP(sc);
if (!rqi) {
SNIC_HOST_ERR(snic->shost,
"send_dr: rqi is null, Tag 0x%x flags 0x%llx\n",
tag, CMD_FLAGS(sc));
spin_unlock_irqrestore(io_lock, flags);
ret = FAILED;
goto send_dr_end;
}
sv_state = CMD_STATE(sc);
CMD_STATE(sc) = SNIC_IOREQ_LR_PENDING;
CMD_LR_STATUS(sc) = SNIC_INVALID_CODE;
SNIC_SCSI_DBG(snic->shost, "dr: TAG = %x\n", tag);
rqi->dr_done = &tm_done;
SNIC_BUG_ON(!rqi->dr_done);
spin_unlock_irqrestore(io_lock, flags);
ret = snic_queue_dr_req(snic, rqi, sc);
if (ret) {
SNIC_HOST_ERR(snic->shost,
"send_dr: IO w/ Tag 0x%x Failed err = %d. flags 0x%llx\n",
tag, ret, CMD_FLAGS(sc));
spin_lock_irqsave(io_lock, flags);
CMD_STATE(sc) = sv_state;
rqi = (struct snic_req_info *) CMD_SP(sc);
if (rqi)
rqi->dr_done = NULL;
spin_unlock_irqrestore(io_lock, flags);
ret = FAILED;
goto send_dr_end;
}
spin_lock_irqsave(io_lock, flags);
CMD_FLAGS(sc) |= SNIC_DEV_RST_ISSUED;
spin_unlock_irqrestore(io_lock, flags);
ret = 0;
wait_for_completion_timeout(&tm_done, SNIC_LUN_RESET_TIMEOUT);
send_dr_end:
return ret;
}
static int
snic_dev_reset_supported(struct scsi_device *sdev)
{
struct snic_tgt *tgt = starget_to_tgt(scsi_target(sdev));
if (tgt->tdata.typ == SNIC_TGT_DAS)
return 0;
return 1;
}
static void
snic_unlink_and_release_req(struct snic *snic, struct scsi_cmnd *sc, int flag)
{
struct snic_req_info *rqi = NULL;
spinlock_t *io_lock = NULL;
unsigned long flags;
u32 start_time = jiffies;
io_lock = snic_io_lock_hash(snic, sc);
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
if (rqi) {
start_time = rqi->start_time;
CMD_SP(sc) = NULL;
}
CMD_FLAGS(sc) |= flag;
spin_unlock_irqrestore(io_lock, flags);
if (rqi)
snic_release_req_buf(snic, rqi, sc);
SNIC_TRC(snic->shost->host_no, snic_cmd_tag(sc), (ulong) sc,
jiffies_to_msecs(jiffies - start_time), (ulong) rqi,
SNIC_TRC_CMD(sc), SNIC_TRC_CMD_STATE_FLAGS(sc));
}
int
snic_device_reset(struct scsi_cmnd *sc)
{
struct Scsi_Host *shost = sc->device->host;
struct snic *snic = shost_priv(shost);
struct snic_req_info *rqi = NULL;
int tag = snic_cmd_tag(sc);
int start_time = jiffies;
int ret = FAILED;
int dr_supp = 0;
SNIC_SCSI_DBG(shost, "dev_reset:sc %p :0x%x :req = %p :tag = %d\n",
sc, sc->cmnd[0], sc->request,
snic_cmd_tag(sc));
dr_supp = snic_dev_reset_supported(sc->device);
if (!dr_supp) {
SNIC_HOST_INFO(shost, "LUN Reset Op not supported.\n");
snic_unlink_and_release_req(snic, sc, SNIC_DEV_RST_NOTSUP);
goto dev_rst_end;
}
if (unlikely(snic_get_state(snic) != SNIC_ONLINE)) {
snic_unlink_and_release_req(snic, sc, 0);
SNIC_HOST_ERR(shost, "Devrst: Parent Devs are not online.\n");
goto dev_rst_end;
}
if (unlikely(tag <= SNIC_NO_TAG)) {
SNIC_HOST_INFO(snic->shost,
"Devrst: LUN Reset Recvd thru IOCTL.\n");
rqi = snic_req_init(snic, 0);
if (!rqi)
goto dev_rst_end;
memset(scsi_cmd_priv(sc), 0,
sizeof(struct snic_internal_io_state));
CMD_SP(sc) = (char *)rqi;
CMD_FLAGS(sc) = SNIC_NO_FLAGS;
rqi->tm_tag = SNIC_TAG_IOCTL_DEV_RST;
rqi->sc = sc;
}
ret = snic_send_dr_and_wait(snic, sc);
if (ret) {
SNIC_HOST_ERR(snic->shost,
"Devrst: IO w/ Tag %x Failed w/ err = %d\n",
tag, ret);
snic_unlink_and_release_req(snic, sc, 0);
goto dev_rst_end;
}
ret = snic_dr_finish(snic, sc);
dev_rst_end:
SNIC_TRC(snic->shost->host_no, tag, (ulong) sc,
jiffies_to_msecs(jiffies - start_time),
0, SNIC_TRC_CMD(sc), SNIC_TRC_CMD_STATE_FLAGS(sc));
SNIC_SCSI_DBG(snic->shost,
"Devrst: Returning from Device Reset : %s\n",
(ret == SUCCESS) ? "SUCCESS" : "FAILED");
return ret;
}
static int
snic_issue_hba_reset(struct snic *snic, struct scsi_cmnd *sc)
{
struct snic_req_info *rqi = NULL;
struct snic_host_req *req = NULL;
spinlock_t *io_lock = NULL;
DECLARE_COMPLETION_ONSTACK(wait);
unsigned long flags;
int ret = -ENOMEM;
rqi = snic_req_init(snic, 0);
if (!rqi) {
ret = -ENOMEM;
goto hba_rst_end;
}
if (snic_cmd_tag(sc) == SCSI_NO_TAG) {
memset(scsi_cmd_priv(sc), 0,
sizeof(struct snic_internal_io_state));
SNIC_HOST_INFO(snic->shost, "issu_hr:Host reset thru ioctl.\n");
rqi->sc = sc;
}
req = rqi_to_req(rqi);
io_lock = snic_io_lock_hash(snic, sc);
spin_lock_irqsave(io_lock, flags);
SNIC_BUG_ON(CMD_SP(sc) != NULL);
CMD_STATE(sc) = SNIC_IOREQ_PENDING;
CMD_SP(sc) = (char *) rqi;
CMD_FLAGS(sc) |= SNIC_IO_INITIALIZED;
snic->remove_wait = &wait;
spin_unlock_irqrestore(io_lock, flags);
snic_io_hdr_enc(&req->hdr, SNIC_REQ_HBA_RESET, 0, snic_cmd_tag(sc),
snic->config.hid, 0, (ulong) rqi);
req->u.reset.flags = 0;
ret = snic_queue_wq_desc(snic, req, sizeof(*req));
if (ret) {
SNIC_HOST_ERR(snic->shost,
"issu_hr:Queuing HBA Reset Failed. w err %d\n",
ret);
goto hba_rst_err;
}
spin_lock_irqsave(io_lock, flags);
CMD_FLAGS(sc) |= SNIC_HOST_RESET_ISSUED;
spin_unlock_irqrestore(io_lock, flags);
atomic64_inc(&snic->s_stats.reset.hba_resets);
SNIC_HOST_INFO(snic->shost, "Queued HBA Reset Successfully.\n");
wait_for_completion_timeout(snic->remove_wait,
SNIC_HOST_RESET_TIMEOUT);
if (snic_get_state(snic) == SNIC_FWRESET) {
SNIC_HOST_ERR(snic->shost, "reset_cmpl: Reset Timedout.\n");
ret = -ETIMEDOUT;
goto hba_rst_err;
}
spin_lock_irqsave(io_lock, flags);
snic->remove_wait = NULL;
rqi = (struct snic_req_info *) CMD_SP(sc);
CMD_SP(sc) = NULL;
spin_unlock_irqrestore(io_lock, flags);
if (rqi)
snic_req_free(snic, rqi);
ret = 0;
return ret;
hba_rst_err:
spin_lock_irqsave(io_lock, flags);
snic->remove_wait = NULL;
rqi = (struct snic_req_info *) CMD_SP(sc);
CMD_SP(sc) = NULL;
spin_unlock_irqrestore(io_lock, flags);
if (rqi)
snic_req_free(snic, rqi);
hba_rst_end:
SNIC_HOST_ERR(snic->shost,
"reset:HBA Reset Failed w/ err = %d.\n",
ret);
return ret;
}
int
snic_reset(struct Scsi_Host *shost, struct scsi_cmnd *sc)
{
struct snic *snic = shost_priv(shost);
enum snic_state sv_state;
unsigned long flags;
int ret = FAILED;
sv_state = snic_get_state(snic);
spin_lock_irqsave(&snic->snic_lock, flags);
if (snic_get_state(snic) == SNIC_FWRESET) {
spin_unlock_irqrestore(&snic->snic_lock, flags);
SNIC_HOST_INFO(shost, "reset:prev reset is in progres\n");
msleep(SNIC_HOST_RESET_TIMEOUT);
ret = SUCCESS;
goto reset_end;
}
snic_set_state(snic, SNIC_FWRESET);
spin_unlock_irqrestore(&snic->snic_lock, flags);
while (atomic_read(&snic->ios_inflight))
schedule_timeout(msecs_to_jiffies(1));
ret = snic_issue_hba_reset(snic, sc);
if (ret) {
SNIC_HOST_ERR(shost,
"reset:Host Reset Failed w/ err %d.\n",
ret);
spin_lock_irqsave(&snic->snic_lock, flags);
snic_set_state(snic, sv_state);
spin_unlock_irqrestore(&snic->snic_lock, flags);
atomic64_inc(&snic->s_stats.reset.hba_reset_fail);
ret = FAILED;
goto reset_end;
}
ret = SUCCESS;
reset_end:
return ret;
}
int
snic_host_reset(struct scsi_cmnd *sc)
{
struct Scsi_Host *shost = sc->device->host;
u32 start_time = jiffies;
int ret = FAILED;
SNIC_SCSI_DBG(shost,
"host reset:sc %p sc_cmd 0x%x req %p tag %d flags 0x%llx\n",
sc, sc->cmnd[0], sc->request,
snic_cmd_tag(sc), CMD_FLAGS(sc));
ret = snic_reset(shost, sc);
SNIC_TRC(shost->host_no, snic_cmd_tag(sc), (ulong) sc,
jiffies_to_msecs(jiffies - start_time),
0, SNIC_TRC_CMD(sc), SNIC_TRC_CMD_STATE_FLAGS(sc));
return ret;
}
static void
snic_cmpl_pending_tmreq(struct snic *snic, struct scsi_cmnd *sc)
{
struct snic_req_info *rqi = NULL;
SNIC_SCSI_DBG(snic->shost,
"Completing Pending TM Req sc %p, state %s flags 0x%llx\n",
sc, snic_io_status_to_str(CMD_STATE(sc)), CMD_FLAGS(sc));
rqi = (struct snic_req_info *) CMD_SP(sc);
if (!rqi)
return;
if (rqi->dr_done)
complete(rqi->dr_done);
else if (rqi->abts_done)
complete(rqi->abts_done);
}
static void
snic_scsi_cleanup(struct snic *snic, int ex_tag)
{
struct snic_req_info *rqi = NULL;
struct scsi_cmnd *sc = NULL;
spinlock_t *io_lock = NULL;
unsigned long flags;
int tag;
u64 st_time = 0;
SNIC_SCSI_DBG(snic->shost, "sc_clean: scsi cleanup.\n");
for (tag = 0; tag < snic->max_tag_id; tag++) {
if (tag == ex_tag)
continue;
io_lock = snic_io_lock_tag(snic, tag);
spin_lock_irqsave(io_lock, flags);
sc = scsi_host_find_tag(snic->shost, tag);
if (!sc) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
if (unlikely(snic_tmreq_pending(sc))) {
snic_cmpl_pending_tmreq(snic, sc);
spin_unlock_irqrestore(io_lock, flags);
continue;
}
rqi = (struct snic_req_info *) CMD_SP(sc);
if (!rqi) {
spin_unlock_irqrestore(io_lock, flags);
goto cleanup;
}
SNIC_SCSI_DBG(snic->shost,
"sc_clean: sc %p, rqi %p, tag %d flags 0x%llx\n",
sc, rqi, tag, CMD_FLAGS(sc));
CMD_SP(sc) = NULL;
CMD_FLAGS(sc) |= SNIC_SCSI_CLEANUP;
spin_unlock_irqrestore(io_lock, flags);
st_time = rqi->start_time;
SNIC_HOST_INFO(snic->shost,
"sc_clean: Releasing rqi %p : flags 0x%llx\n",
rqi, CMD_FLAGS(sc));
snic_release_req_buf(snic, rqi, sc);
cleanup:
sc->result = DID_TRANSPORT_DISRUPTED << 16;
SNIC_HOST_INFO(snic->shost,
"sc_clean: DID_TRANSPORT_DISRUPTED for sc %p. rqi %p duration %llu msecs\n",
sc, rqi, (jiffies - st_time));
snic_stats_update_io_cmpl(&snic->s_stats);
if (sc->scsi_done) {
SNIC_TRC(snic->shost->host_no, tag, (ulong) sc,
jiffies_to_msecs(jiffies - st_time), 0,
SNIC_TRC_CMD(sc),
SNIC_TRC_CMD_STATE_FLAGS(sc));
sc->scsi_done(sc);
}
}
}
void
snic_shutdown_scsi_cleanup(struct snic *snic)
{
SNIC_HOST_INFO(snic->shost, "Shutdown time SCSI Cleanup.\n");
snic_scsi_cleanup(snic, SCSI_NO_TAG);
}
static int
snic_internal_abort_io(struct snic *snic, struct scsi_cmnd *sc, int tmf)
{
struct snic_req_info *rqi = NULL;
spinlock_t *io_lock = NULL;
unsigned long flags;
u32 sv_state = 0;
int ret = 0;
io_lock = snic_io_lock_hash(snic, sc);
spin_lock_irqsave(io_lock, flags);
rqi = (struct snic_req_info *) CMD_SP(sc);
if (!rqi)
goto skip_internal_abts;
if (CMD_STATE(sc) == SNIC_IOREQ_ABTS_PENDING)
goto skip_internal_abts;
if ((CMD_FLAGS(sc) & SNIC_DEVICE_RESET) &&
(!(CMD_FLAGS(sc) & SNIC_DEV_RST_ISSUED))) {
SNIC_SCSI_DBG(snic->shost,
"internal_abts: dev rst not pending sc 0x%p\n",
sc);
goto skip_internal_abts;
}
if (!(CMD_FLAGS(sc) & SNIC_IO_ISSUED)) {
SNIC_SCSI_DBG(snic->shost,
"internal_abts: IO not yet issued sc 0x%p tag 0x%x flags 0x%llx state %d\n",
sc, snic_cmd_tag(sc), CMD_FLAGS(sc), CMD_STATE(sc));
goto skip_internal_abts;
}
sv_state = CMD_STATE(sc);
CMD_STATE(sc) = SNIC_IOREQ_ABTS_PENDING;
CMD_ABTS_STATUS(sc) = SNIC_INVALID_CODE;
CMD_FLAGS(sc) |= SNIC_IO_INTERNAL_TERM_PENDING;
if (CMD_FLAGS(sc) & SNIC_DEVICE_RESET) {
rqi->tm_tag = SNIC_TAG_DEV_RST;
SNIC_SCSI_DBG(snic->shost, "internal_abts:dev rst sc %p\n", sc);
}
SNIC_SCSI_DBG(snic->shost, "internal_abts: Issuing abts tag %x\n",
snic_cmd_tag(sc));
SNIC_BUG_ON(rqi->abts_done);
spin_unlock_irqrestore(io_lock, flags);
ret = snic_queue_abort_req(snic, rqi, sc, tmf);
if (ret) {
SNIC_HOST_ERR(snic->shost,
"internal_abts: Tag = %x , Failed w/ err = %d\n",
snic_cmd_tag(sc), ret);
spin_lock_irqsave(io_lock, flags);
if (CMD_STATE(sc) == SNIC_IOREQ_ABTS_PENDING)
CMD_STATE(sc) = sv_state;
goto skip_internal_abts;
}
spin_lock_irqsave(io_lock, flags);
if (CMD_FLAGS(sc) & SNIC_DEVICE_RESET)
CMD_FLAGS(sc) |= SNIC_DEV_RST_TERM_ISSUED;
else
CMD_FLAGS(sc) |= SNIC_IO_INTERNAL_TERM_ISSUED;
ret = SUCCESS;
skip_internal_abts:
SNIC_BUG_ON(!spin_is_locked(io_lock));
spin_unlock_irqrestore(io_lock, flags);
return ret;
}
int
snic_tgt_scsi_abort_io(struct snic_tgt *tgt)
{
struct snic *snic = NULL;
struct scsi_cmnd *sc = NULL;
struct snic_tgt *sc_tgt = NULL;
spinlock_t *io_lock = NULL;
unsigned long flags;
int ret = 0, tag, abt_cnt = 0, tmf = 0;
if (!tgt)
return -1;
snic = shost_priv(snic_tgt_to_shost(tgt));
SNIC_SCSI_DBG(snic->shost, "tgt_abt_io: Cleaning Pending IOs.\n");
if (tgt->tdata.typ == SNIC_TGT_DAS)
tmf = SNIC_ITMF_ABTS_TASK;
else
tmf = SNIC_ITMF_ABTS_TASK_TERM;
for (tag = 0; tag < snic->max_tag_id; tag++) {
io_lock = snic_io_lock_tag(snic, tag);
spin_lock_irqsave(io_lock, flags);
sc = scsi_host_find_tag(snic->shost, tag);
if (!sc) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
sc_tgt = starget_to_tgt(scsi_target(sc->device));
if (sc_tgt != tgt) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
spin_unlock_irqrestore(io_lock, flags);
ret = snic_internal_abort_io(snic, sc, tmf);
if (ret < 0) {
SNIC_HOST_ERR(snic->shost,
"tgt_abt_io: Tag %x, Failed w err = %d\n",
tag, ret);
continue;
}
if (ret == SUCCESS)
abt_cnt++;
}
SNIC_SCSI_DBG(snic->shost, "tgt_abt_io: abt_cnt = %d\n", abt_cnt);
return 0;
}
