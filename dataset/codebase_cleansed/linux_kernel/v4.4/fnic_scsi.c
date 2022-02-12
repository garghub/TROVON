const char *fnic_state_to_str(unsigned int state)
{
if (state >= ARRAY_SIZE(fnic_state_str) || !fnic_state_str[state])
return "unknown";
return fnic_state_str[state];
}
static const char *fnic_ioreq_state_to_str(unsigned int state)
{
if (state >= ARRAY_SIZE(fnic_ioreq_state_str) ||
!fnic_ioreq_state_str[state])
return "unknown";
return fnic_ioreq_state_str[state];
}
static const char *fnic_fcpio_status_to_str(unsigned int status)
{
if (status >= ARRAY_SIZE(fcpio_status_str) || !fcpio_status_str[status])
return "unknown";
return fcpio_status_str[status];
}
static inline spinlock_t *fnic_io_lock_hash(struct fnic *fnic,
struct scsi_cmnd *sc)
{
u32 hash = sc->request->tag & (FNIC_IO_LOCKS - 1);
return &fnic->io_req_lock[hash];
}
static inline spinlock_t *fnic_io_lock_tag(struct fnic *fnic,
int tag)
{
return &fnic->io_req_lock[tag & (FNIC_IO_LOCKS - 1)];
}
static void fnic_release_ioreq_buf(struct fnic *fnic,
struct fnic_io_req *io_req,
struct scsi_cmnd *sc)
{
if (io_req->sgl_list_pa)
pci_unmap_single(fnic->pdev, io_req->sgl_list_pa,
sizeof(io_req->sgl_list[0]) * io_req->sgl_cnt,
PCI_DMA_TODEVICE);
scsi_dma_unmap(sc);
if (io_req->sgl_cnt)
mempool_free(io_req->sgl_list_alloc,
fnic->io_sgl_pool[io_req->sgl_type]);
if (io_req->sense_buf_pa)
pci_unmap_single(fnic->pdev, io_req->sense_buf_pa,
SCSI_SENSE_BUFFERSIZE, PCI_DMA_FROMDEVICE);
}
static int free_wq_copy_descs(struct fnic *fnic, struct vnic_wq_copy *wq)
{
if (!fnic->fw_ack_recd[0])
return 1;
if (wq->to_clean_index <= fnic->fw_ack_index[0])
wq->ring.desc_avail += (fnic->fw_ack_index[0]
- wq->to_clean_index + 1);
else
wq->ring.desc_avail += (wq->ring.desc_count
- wq->to_clean_index
+ fnic->fw_ack_index[0] + 1);
wq->to_clean_index =
(fnic->fw_ack_index[0] + 1) % wq->ring.desc_count;
fnic->fw_ack_recd[0] = 0;
return 0;
}
void
__fnic_set_state_flags(struct fnic *fnic, unsigned long st_flags,
unsigned long clearbits)
{
struct Scsi_Host *host = fnic->lport->host;
int sh_locked = spin_is_locked(host->host_lock);
unsigned long flags = 0;
if (!sh_locked)
spin_lock_irqsave(host->host_lock, flags);
if (clearbits)
fnic->state_flags &= ~st_flags;
else
fnic->state_flags |= st_flags;
if (!sh_locked)
spin_unlock_irqrestore(host->host_lock, flags);
return;
}
int fnic_fw_reset_handler(struct fnic *fnic)
{
struct vnic_wq_copy *wq = &fnic->wq_copy[0];
int ret = 0;
unsigned long flags;
fnic_set_state_flags(fnic, FNIC_FLAGS_FWRESET);
skb_queue_purge(&fnic->frame_queue);
skb_queue_purge(&fnic->tx_queue);
while (atomic_read(&fnic->in_flight))
schedule_timeout(msecs_to_jiffies(1));
spin_lock_irqsave(&fnic->wq_copy_lock[0], flags);
if (vnic_wq_copy_desc_avail(wq) <= fnic->wq_copy_desc_low[0])
free_wq_copy_descs(fnic, wq);
if (!vnic_wq_copy_desc_avail(wq))
ret = -EAGAIN;
else {
fnic_queue_wq_copy_desc_fw_reset(wq, SCSI_NO_TAG);
atomic64_inc(&fnic->fnic_stats.fw_stats.active_fw_reqs);
if (atomic64_read(&fnic->fnic_stats.fw_stats.active_fw_reqs) >
atomic64_read(&fnic->fnic_stats.fw_stats.max_fw_reqs))
atomic64_set(&fnic->fnic_stats.fw_stats.max_fw_reqs,
atomic64_read(
&fnic->fnic_stats.fw_stats.active_fw_reqs));
}
spin_unlock_irqrestore(&fnic->wq_copy_lock[0], flags);
if (!ret) {
atomic64_inc(&fnic->fnic_stats.reset_stats.fw_resets);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Issued fw reset\n");
} else {
fnic_clear_state_flags(fnic, FNIC_FLAGS_FWRESET);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Failed to issue fw reset\n");
}
return ret;
}
int fnic_flogi_reg_handler(struct fnic *fnic, u32 fc_id)
{
struct vnic_wq_copy *wq = &fnic->wq_copy[0];
enum fcpio_flogi_reg_format_type format;
struct fc_lport *lp = fnic->lport;
u8 gw_mac[ETH_ALEN];
int ret = 0;
unsigned long flags;
spin_lock_irqsave(&fnic->wq_copy_lock[0], flags);
if (vnic_wq_copy_desc_avail(wq) <= fnic->wq_copy_desc_low[0])
free_wq_copy_descs(fnic, wq);
if (!vnic_wq_copy_desc_avail(wq)) {
ret = -EAGAIN;
goto flogi_reg_ioreq_end;
}
if (fnic->ctlr.map_dest) {
memset(gw_mac, 0xff, ETH_ALEN);
format = FCPIO_FLOGI_REG_DEF_DEST;
} else {
memcpy(gw_mac, fnic->ctlr.dest_addr, ETH_ALEN);
format = FCPIO_FLOGI_REG_GW_DEST;
}
if ((fnic->config.flags & VFCF_FIP_CAPABLE) && !fnic->ctlr.map_dest) {
fnic_queue_wq_copy_desc_fip_reg(wq, SCSI_NO_TAG,
fc_id, gw_mac,
fnic->data_src_addr,
lp->r_a_tov, lp->e_d_tov);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"FLOGI FIP reg issued fcid %x src %pM dest %pM\n",
fc_id, fnic->data_src_addr, gw_mac);
} else {
fnic_queue_wq_copy_desc_flogi_reg(wq, SCSI_NO_TAG,
format, fc_id, gw_mac);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"FLOGI reg issued fcid %x map %d dest %pM\n",
fc_id, fnic->ctlr.map_dest, gw_mac);
}
atomic64_inc(&fnic->fnic_stats.fw_stats.active_fw_reqs);
if (atomic64_read(&fnic->fnic_stats.fw_stats.active_fw_reqs) >
atomic64_read(&fnic->fnic_stats.fw_stats.max_fw_reqs))
atomic64_set(&fnic->fnic_stats.fw_stats.max_fw_reqs,
atomic64_read(&fnic->fnic_stats.fw_stats.active_fw_reqs));
flogi_reg_ioreq_end:
spin_unlock_irqrestore(&fnic->wq_copy_lock[0], flags);
return ret;
}
static inline int fnic_queue_wq_copy_desc(struct fnic *fnic,
struct vnic_wq_copy *wq,
struct fnic_io_req *io_req,
struct scsi_cmnd *sc,
int sg_count)
{
struct scatterlist *sg;
struct fc_rport *rport = starget_to_rport(scsi_target(sc->device));
struct fc_rport_libfc_priv *rp = rport->dd_data;
struct host_sg_desc *desc;
struct misc_stats *misc_stats = &fnic->fnic_stats.misc_stats;
unsigned int i;
unsigned long intr_flags;
int flags;
u8 exch_flags;
struct scsi_lun fc_lun;
int r;
if (sg_count) {
desc = io_req->sgl_list;
for_each_sg(scsi_sglist(sc), sg, sg_count, i) {
desc->addr = cpu_to_le64(sg_dma_address(sg));
desc->len = cpu_to_le32(sg_dma_len(sg));
desc->_resvd = 0;
desc++;
}
io_req->sgl_list_pa = pci_map_single
(fnic->pdev,
io_req->sgl_list,
sizeof(io_req->sgl_list[0]) * sg_count,
PCI_DMA_TODEVICE);
r = pci_dma_mapping_error(fnic->pdev, io_req->sgl_list_pa);
if (r) {
printk(KERN_ERR "PCI mapping failed with error %d\n", r);
return SCSI_MLQUEUE_HOST_BUSY;
}
}
io_req->sense_buf_pa = pci_map_single(fnic->pdev,
sc->sense_buffer,
SCSI_SENSE_BUFFERSIZE,
PCI_DMA_FROMDEVICE);
r = pci_dma_mapping_error(fnic->pdev, io_req->sense_buf_pa);
if (r) {
pci_unmap_single(fnic->pdev, io_req->sgl_list_pa,
sizeof(io_req->sgl_list[0]) * sg_count,
PCI_DMA_TODEVICE);
printk(KERN_ERR "PCI mapping failed with error %d\n", r);
return SCSI_MLQUEUE_HOST_BUSY;
}
int_to_scsilun(sc->device->lun, &fc_lun);
spin_lock_irqsave(&fnic->wq_copy_lock[0], intr_flags);
if (vnic_wq_copy_desc_avail(wq) <= fnic->wq_copy_desc_low[0])
free_wq_copy_descs(fnic, wq);
if (unlikely(!vnic_wq_copy_desc_avail(wq))) {
spin_unlock_irqrestore(&fnic->wq_copy_lock[0], intr_flags);
FNIC_SCSI_DBG(KERN_INFO, fnic->lport->host,
"fnic_queue_wq_copy_desc failure - no descriptors\n");
atomic64_inc(&misc_stats->io_cpwq_alloc_failures);
return SCSI_MLQUEUE_HOST_BUSY;
}
flags = 0;
if (sc->sc_data_direction == DMA_FROM_DEVICE)
flags = FCPIO_ICMND_RDDATA;
else if (sc->sc_data_direction == DMA_TO_DEVICE)
flags = FCPIO_ICMND_WRDATA;
exch_flags = 0;
if ((fnic->config.flags & VFCF_FCP_SEQ_LVL_ERR) &&
(rp->flags & FC_RP_FLAGS_RETRY))
exch_flags |= FCPIO_ICMND_SRFLAG_RETRY;
fnic_queue_wq_copy_desc_icmnd_16(wq, sc->request->tag,
0, exch_flags, io_req->sgl_cnt,
SCSI_SENSE_BUFFERSIZE,
io_req->sgl_list_pa,
io_req->sense_buf_pa,
0,
FCPIO_ICMND_PTA_SIMPLE,
flags,
sc->cmnd, sc->cmd_len,
scsi_bufflen(sc),
fc_lun.scsi_lun, io_req->port_id,
rport->maxframe_size, rp->r_a_tov,
rp->e_d_tov);
atomic64_inc(&fnic->fnic_stats.fw_stats.active_fw_reqs);
if (atomic64_read(&fnic->fnic_stats.fw_stats.active_fw_reqs) >
atomic64_read(&fnic->fnic_stats.fw_stats.max_fw_reqs))
atomic64_set(&fnic->fnic_stats.fw_stats.max_fw_reqs,
atomic64_read(&fnic->fnic_stats.fw_stats.active_fw_reqs));
spin_unlock_irqrestore(&fnic->wq_copy_lock[0], intr_flags);
return 0;
}
static int fnic_queuecommand_lck(struct scsi_cmnd *sc, void (*done)(struct scsi_cmnd *))
{
struct fc_lport *lp = shost_priv(sc->device->host);
struct fc_rport *rport;
struct fnic_io_req *io_req = NULL;
struct fnic *fnic = lport_priv(lp);
struct fnic_stats *fnic_stats = &fnic->fnic_stats;
struct vnic_wq_copy *wq;
int ret;
u64 cmd_trace;
int sg_count = 0;
unsigned long flags = 0;
unsigned long ptr;
struct fc_rport_priv *rdata;
spinlock_t *io_lock = NULL;
int io_lock_acquired = 0;
if (unlikely(fnic_chk_state_flags_locked(fnic, FNIC_FLAGS_IO_BLOCKED)))
return SCSI_MLQUEUE_HOST_BUSY;
rport = starget_to_rport(scsi_target(sc->device));
ret = fc_remote_port_chkready(rport);
if (ret) {
atomic64_inc(&fnic_stats->misc_stats.rport_not_ready);
sc->result = ret;
done(sc);
return 0;
}
rdata = lp->tt.rport_lookup(lp, rport->port_id);
if (!rdata || (rdata->rp_state == RPORT_ST_DELETE)) {
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"returning IO as rport is removed\n");
atomic64_inc(&fnic_stats->misc_stats.rport_not_ready);
sc->result = DID_NO_CONNECT;
done(sc);
return 0;
}
if (lp->state != LPORT_ST_READY || !(lp->link_up))
return SCSI_MLQUEUE_HOST_BUSY;
atomic_inc(&fnic->in_flight);
spin_unlock(lp->host->host_lock);
CMD_STATE(sc) = FNIC_IOREQ_NOT_INITED;
CMD_FLAGS(sc) = FNIC_NO_FLAGS;
io_req = mempool_alloc(fnic->io_req_pool, GFP_ATOMIC);
if (!io_req) {
atomic64_inc(&fnic_stats->io_stats.alloc_failures);
ret = SCSI_MLQUEUE_HOST_BUSY;
goto out;
}
memset(io_req, 0, sizeof(*io_req));
sg_count = scsi_dma_map(sc);
if (sg_count < 0) {
FNIC_TRACE(fnic_queuecommand, sc->device->host->host_no,
sc->request->tag, sc, 0, sc->cmnd[0],
sg_count, CMD_STATE(sc));
mempool_free(io_req, fnic->io_req_pool);
goto out;
}
io_req->sgl_cnt = sg_count;
io_req->sgl_type = FNIC_SGL_CACHE_DFLT;
if (sg_count > FNIC_DFLT_SG_DESC_CNT)
io_req->sgl_type = FNIC_SGL_CACHE_MAX;
if (sg_count) {
io_req->sgl_list =
mempool_alloc(fnic->io_sgl_pool[io_req->sgl_type],
GFP_ATOMIC);
if (!io_req->sgl_list) {
atomic64_inc(&fnic_stats->io_stats.alloc_failures);
ret = SCSI_MLQUEUE_HOST_BUSY;
scsi_dma_unmap(sc);
mempool_free(io_req, fnic->io_req_pool);
goto out;
}
io_req->sgl_list_alloc = io_req->sgl_list;
ptr = (unsigned long) io_req->sgl_list;
if (ptr % FNIC_SG_DESC_ALIGN) {
io_req->sgl_list = (struct host_sg_desc *)
(((unsigned long) ptr
+ FNIC_SG_DESC_ALIGN - 1)
& ~(FNIC_SG_DESC_ALIGN - 1));
}
}
io_lock = fnic_io_lock_hash(fnic, sc);
spin_lock_irqsave(io_lock, flags);
io_lock_acquired = 1;
io_req->port_id = rport->port_id;
io_req->start_time = jiffies;
CMD_STATE(sc) = FNIC_IOREQ_CMD_PENDING;
CMD_SP(sc) = (char *)io_req;
CMD_FLAGS(sc) |= FNIC_IO_INITIALIZED;
sc->scsi_done = done;
wq = &fnic->wq_copy[0];
ret = fnic_queue_wq_copy_desc(fnic, wq, io_req, sc, sg_count);
if (ret) {
FNIC_TRACE(fnic_queuecommand, sc->device->host->host_no,
sc->request->tag, sc, 0, 0, 0,
(((u64)CMD_FLAGS(sc) << 32) | CMD_STATE(sc)));
io_req = (struct fnic_io_req *)CMD_SP(sc);
CMD_SP(sc) = NULL;
CMD_STATE(sc) = FNIC_IOREQ_CMD_COMPLETE;
spin_unlock_irqrestore(io_lock, flags);
if (io_req) {
fnic_release_ioreq_buf(fnic, io_req, sc);
mempool_free(io_req, fnic->io_req_pool);
}
atomic_dec(&fnic->in_flight);
spin_lock(lp->host->host_lock);
return ret;
} else {
atomic64_inc(&fnic_stats->io_stats.active_ios);
atomic64_inc(&fnic_stats->io_stats.num_ios);
if (atomic64_read(&fnic_stats->io_stats.active_ios) >
atomic64_read(&fnic_stats->io_stats.max_active_ios))
atomic64_set(&fnic_stats->io_stats.max_active_ios,
atomic64_read(&fnic_stats->io_stats.active_ios));
CMD_FLAGS(sc) |= FNIC_IO_ISSUED;
}
out:
cmd_trace = ((u64)sc->cmnd[0] << 56 | (u64)sc->cmnd[7] << 40 |
(u64)sc->cmnd[8] << 32 | (u64)sc->cmnd[2] << 24 |
(u64)sc->cmnd[3] << 16 | (u64)sc->cmnd[4] << 8 |
sc->cmnd[5]);
FNIC_TRACE(fnic_queuecommand, sc->device->host->host_no,
sc->request->tag, sc, io_req,
sg_count, cmd_trace,
(((u64)CMD_FLAGS(sc) >> 32) | CMD_STATE(sc)));
if (io_lock_acquired)
spin_unlock_irqrestore(io_lock, flags);
atomic_dec(&fnic->in_flight);
spin_lock(lp->host->host_lock);
return ret;
}
static int fnic_fcpio_fw_reset_cmpl_handler(struct fnic *fnic,
struct fcpio_fw_req *desc)
{
u8 type;
u8 hdr_status;
struct fcpio_tag tag;
int ret = 0;
unsigned long flags;
struct reset_stats *reset_stats = &fnic->fnic_stats.reset_stats;
fcpio_header_dec(&desc->hdr, &type, &hdr_status, &tag);
atomic64_inc(&reset_stats->fw_reset_completions);
fnic_cleanup_io(fnic, SCSI_NO_TAG);
atomic64_set(&fnic->fnic_stats.fw_stats.active_fw_reqs, 0);
atomic64_set(&fnic->fnic_stats.io_stats.active_ios, 0);
spin_lock_irqsave(&fnic->fnic_lock, flags);
if (fnic->state == FNIC_IN_FC_TRANS_ETH_MODE) {
if (!hdr_status) {
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"reset cmpl success\n");
fnic->state = FNIC_IN_ETH_MODE;
} else {
FNIC_SCSI_DBG(KERN_DEBUG,
fnic->lport->host,
"fnic fw_reset : failed %s\n",
fnic_fcpio_status_to_str(hdr_status));
fnic->state = FNIC_IN_FC_MODE;
atomic64_inc(&reset_stats->fw_reset_failures);
ret = -1;
}
} else {
FNIC_SCSI_DBG(KERN_DEBUG,
fnic->lport->host,
"Unexpected state %s while processing"
" reset cmpl\n", fnic_state_to_str(fnic->state));
atomic64_inc(&reset_stats->fw_reset_failures);
ret = -1;
}
if (fnic->remove_wait)
complete(fnic->remove_wait);
if (fnic->remove_wait || ret) {
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
skb_queue_purge(&fnic->tx_queue);
goto reset_cmpl_handler_end;
}
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
fnic_flush_tx(fnic);
reset_cmpl_handler_end:
fnic_clear_state_flags(fnic, FNIC_FLAGS_FWRESET);
return ret;
}
static int fnic_fcpio_flogi_reg_cmpl_handler(struct fnic *fnic,
struct fcpio_fw_req *desc)
{
u8 type;
u8 hdr_status;
struct fcpio_tag tag;
int ret = 0;
unsigned long flags;
fcpio_header_dec(&desc->hdr, &type, &hdr_status, &tag);
spin_lock_irqsave(&fnic->fnic_lock, flags);
if (fnic->state == FNIC_IN_ETH_TRANS_FC_MODE) {
if (!hdr_status) {
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"flog reg succeeded\n");
fnic->state = FNIC_IN_FC_MODE;
} else {
FNIC_SCSI_DBG(KERN_DEBUG,
fnic->lport->host,
"fnic flogi reg :failed %s\n",
fnic_fcpio_status_to_str(hdr_status));
fnic->state = FNIC_IN_ETH_MODE;
ret = -1;
}
} else {
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Unexpected fnic state %s while"
" processing flogi reg completion\n",
fnic_state_to_str(fnic->state));
ret = -1;
}
if (!ret) {
if (fnic->stop_rx_link_events) {
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
goto reg_cmpl_handler_end;
}
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
fnic_flush_tx(fnic);
queue_work(fnic_event_queue, &fnic->frame_work);
} else {
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
}
reg_cmpl_handler_end:
return ret;
}
static inline int is_ack_index_in_range(struct vnic_wq_copy *wq,
u16 request_out)
{
if (wq->to_clean_index <= wq->to_use_index) {
if (request_out < wq->to_clean_index ||
request_out >= wq->to_use_index)
return 0;
} else {
if (request_out < wq->to_clean_index &&
request_out >= wq->to_use_index)
return 0;
}
return 1;
}
static inline void fnic_fcpio_ack_handler(struct fnic *fnic,
unsigned int cq_index,
struct fcpio_fw_req *desc)
{
struct vnic_wq_copy *wq;
u16 request_out = desc->u.ack.request_out;
unsigned long flags;
u64 *ox_id_tag = (u64 *)(void *)desc;
wq = &fnic->wq_copy[cq_index - fnic->raw_wq_count - fnic->rq_count];
spin_lock_irqsave(&fnic->wq_copy_lock[0], flags);
fnic->fnic_stats.misc_stats.last_ack_time = jiffies;
if (is_ack_index_in_range(wq, request_out)) {
fnic->fw_ack_index[0] = request_out;
fnic->fw_ack_recd[0] = 1;
} else
atomic64_inc(
&fnic->fnic_stats.misc_stats.ack_index_out_of_range);
spin_unlock_irqrestore(&fnic->wq_copy_lock[0], flags);
FNIC_TRACE(fnic_fcpio_ack_handler,
fnic->lport->host->host_no, 0, 0, ox_id_tag[2], ox_id_tag[3],
ox_id_tag[4], ox_id_tag[5]);
}
static void fnic_fcpio_icmnd_cmpl_handler(struct fnic *fnic,
struct fcpio_fw_req *desc)
{
u8 type;
u8 hdr_status;
struct fcpio_tag tag;
u32 id;
u64 xfer_len = 0;
struct fcpio_icmnd_cmpl *icmnd_cmpl;
struct fnic_io_req *io_req;
struct scsi_cmnd *sc;
struct fnic_stats *fnic_stats = &fnic->fnic_stats;
unsigned long flags;
spinlock_t *io_lock;
u64 cmd_trace;
unsigned long start_time;
fcpio_header_dec(&desc->hdr, &type, &hdr_status, &tag);
fcpio_tag_id_dec(&tag, &id);
icmnd_cmpl = &desc->u.icmnd_cmpl;
if (id >= fnic->fnic_max_tag_id) {
shost_printk(KERN_ERR, fnic->lport->host,
"Tag out of range tag %x hdr status = %s\n",
id, fnic_fcpio_status_to_str(hdr_status));
return;
}
sc = scsi_host_find_tag(fnic->lport->host, id);
WARN_ON_ONCE(!sc);
if (!sc) {
atomic64_inc(&fnic_stats->io_stats.sc_null);
shost_printk(KERN_ERR, fnic->lport->host,
"icmnd_cmpl sc is null - "
"hdr status = %s tag = 0x%x desc = 0x%p\n",
fnic_fcpio_status_to_str(hdr_status), id, desc);
FNIC_TRACE(fnic_fcpio_icmnd_cmpl_handler,
fnic->lport->host->host_no, id,
((u64)icmnd_cmpl->_resvd0[1] << 16 |
(u64)icmnd_cmpl->_resvd0[0]),
((u64)hdr_status << 16 |
(u64)icmnd_cmpl->scsi_status << 8 |
(u64)icmnd_cmpl->flags), desc,
(u64)icmnd_cmpl->residual, 0);
return;
}
io_lock = fnic_io_lock_hash(fnic, sc);
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
WARN_ON_ONCE(!io_req);
if (!io_req) {
atomic64_inc(&fnic_stats->io_stats.ioreq_null);
CMD_FLAGS(sc) |= FNIC_IO_REQ_NULL;
spin_unlock_irqrestore(io_lock, flags);
shost_printk(KERN_ERR, fnic->lport->host,
"icmnd_cmpl io_req is null - "
"hdr status = %s tag = 0x%x sc 0x%p\n",
fnic_fcpio_status_to_str(hdr_status), id, sc);
return;
}
start_time = io_req->start_time;
io_req->io_completed = 1;
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING) {
spin_unlock_irqrestore(io_lock, flags);
CMD_FLAGS(sc) |= FNIC_IO_ABTS_PENDING;
switch (hdr_status) {
case FCPIO_SUCCESS:
CMD_FLAGS(sc) |= FNIC_IO_DONE;
FNIC_SCSI_DBG(KERN_INFO, fnic->lport->host,
"icmnd_cmpl ABTS pending hdr status = %s "
"sc 0x%p scsi_status %x residual %d\n",
fnic_fcpio_status_to_str(hdr_status), sc,
icmnd_cmpl->scsi_status,
icmnd_cmpl->residual);
break;
case FCPIO_ABORTED:
CMD_FLAGS(sc) |= FNIC_IO_ABORTED;
break;
default:
FNIC_SCSI_DBG(KERN_INFO, fnic->lport->host,
"icmnd_cmpl abts pending "
"hdr status = %s tag = 0x%x sc = 0x%p\n",
fnic_fcpio_status_to_str(hdr_status),
id, sc);
break;
}
return;
}
CMD_STATE(sc) = FNIC_IOREQ_CMD_COMPLETE;
icmnd_cmpl = &desc->u.icmnd_cmpl;
switch (hdr_status) {
case FCPIO_SUCCESS:
sc->result = (DID_OK << 16) | icmnd_cmpl->scsi_status;
xfer_len = scsi_bufflen(sc);
scsi_set_resid(sc, icmnd_cmpl->residual);
if (icmnd_cmpl->flags & FCPIO_ICMND_CMPL_RESID_UNDER)
xfer_len -= icmnd_cmpl->residual;
if (icmnd_cmpl->scsi_status == SAM_STAT_TASK_SET_FULL)
atomic64_inc(&fnic_stats->misc_stats.queue_fulls);
break;
case FCPIO_TIMEOUT:
atomic64_inc(&fnic_stats->misc_stats.fcpio_timeout);
sc->result = (DID_TIME_OUT << 16) | icmnd_cmpl->scsi_status;
break;
case FCPIO_ABORTED:
atomic64_inc(&fnic_stats->misc_stats.fcpio_aborted);
sc->result = (DID_ERROR << 16) | icmnd_cmpl->scsi_status;
break;
case FCPIO_DATA_CNT_MISMATCH:
atomic64_inc(&fnic_stats->misc_stats.data_count_mismatch);
scsi_set_resid(sc, icmnd_cmpl->residual);
sc->result = (DID_ERROR << 16) | icmnd_cmpl->scsi_status;
break;
case FCPIO_OUT_OF_RESOURCE:
atomic64_inc(&fnic_stats->fw_stats.fw_out_of_resources);
sc->result = (DID_REQUEUE << 16) | icmnd_cmpl->scsi_status;
break;
case FCPIO_IO_NOT_FOUND:
atomic64_inc(&fnic_stats->io_stats.io_not_found);
sc->result = (DID_ERROR << 16) | icmnd_cmpl->scsi_status;
break;
case FCPIO_SGL_INVALID:
atomic64_inc(&fnic_stats->misc_stats.sgl_invalid);
sc->result = (DID_ERROR << 16) | icmnd_cmpl->scsi_status;
break;
case FCPIO_FW_ERR:
atomic64_inc(&fnic_stats->fw_stats.io_fw_errs);
sc->result = (DID_ERROR << 16) | icmnd_cmpl->scsi_status;
break;
case FCPIO_MSS_INVALID:
atomic64_inc(&fnic_stats->misc_stats.mss_invalid);
sc->result = (DID_ERROR << 16) | icmnd_cmpl->scsi_status;
break;
case FCPIO_INVALID_HEADER:
case FCPIO_INVALID_PARAM:
case FCPIO_REQ_NOT_SUPPORTED:
default:
shost_printk(KERN_ERR, fnic->lport->host, "hdr status = %s\n",
fnic_fcpio_status_to_str(hdr_status));
sc->result = (DID_ERROR << 16) | icmnd_cmpl->scsi_status;
break;
}
if (hdr_status != FCPIO_SUCCESS) {
atomic64_inc(&fnic_stats->io_stats.io_failures);
shost_printk(KERN_ERR, fnic->lport->host, "hdr status = %s\n",
fnic_fcpio_status_to_str(hdr_status));
}
CMD_SP(sc) = NULL;
CMD_FLAGS(sc) |= FNIC_IO_DONE;
spin_unlock_irqrestore(io_lock, flags);
fnic_release_ioreq_buf(fnic, io_req, sc);
mempool_free(io_req, fnic->io_req_pool);
cmd_trace = ((u64)hdr_status << 56) |
(u64)icmnd_cmpl->scsi_status << 48 |
(u64)icmnd_cmpl->flags << 40 | (u64)sc->cmnd[0] << 32 |
(u64)sc->cmnd[2] << 24 | (u64)sc->cmnd[3] << 16 |
(u64)sc->cmnd[4] << 8 | sc->cmnd[5];
FNIC_TRACE(fnic_fcpio_icmnd_cmpl_handler,
sc->device->host->host_no, id, sc,
((u64)icmnd_cmpl->_resvd0[1] << 56 |
(u64)icmnd_cmpl->_resvd0[0] << 48 |
jiffies_to_msecs(jiffies - start_time)),
desc, cmd_trace,
(((u64)CMD_FLAGS(sc) << 32) | CMD_STATE(sc)));
if (sc->sc_data_direction == DMA_FROM_DEVICE) {
fnic->lport->host_stats.fcp_input_requests++;
fnic->fcp_input_bytes += xfer_len;
} else if (sc->sc_data_direction == DMA_TO_DEVICE) {
fnic->lport->host_stats.fcp_output_requests++;
fnic->fcp_output_bytes += xfer_len;
} else
fnic->lport->host_stats.fcp_control_requests++;
atomic64_dec(&fnic_stats->io_stats.active_ios);
if (atomic64_read(&fnic->io_cmpl_skip))
atomic64_dec(&fnic->io_cmpl_skip);
else
atomic64_inc(&fnic_stats->io_stats.io_completions);
if (sc->scsi_done)
sc->scsi_done(sc);
}
static void fnic_fcpio_itmf_cmpl_handler(struct fnic *fnic,
struct fcpio_fw_req *desc)
{
u8 type;
u8 hdr_status;
struct fcpio_tag tag;
u32 id;
struct scsi_cmnd *sc;
struct fnic_io_req *io_req;
struct fnic_stats *fnic_stats = &fnic->fnic_stats;
struct abort_stats *abts_stats = &fnic->fnic_stats.abts_stats;
struct terminate_stats *term_stats = &fnic->fnic_stats.term_stats;
struct misc_stats *misc_stats = &fnic->fnic_stats.misc_stats;
unsigned long flags;
spinlock_t *io_lock;
unsigned long start_time;
fcpio_header_dec(&desc->hdr, &type, &hdr_status, &tag);
fcpio_tag_id_dec(&tag, &id);
if ((id & FNIC_TAG_MASK) >= fnic->fnic_max_tag_id) {
shost_printk(KERN_ERR, fnic->lport->host,
"Tag out of range tag %x hdr status = %s\n",
id, fnic_fcpio_status_to_str(hdr_status));
return;
}
sc = scsi_host_find_tag(fnic->lport->host, id & FNIC_TAG_MASK);
WARN_ON_ONCE(!sc);
if (!sc) {
atomic64_inc(&fnic_stats->io_stats.sc_null);
shost_printk(KERN_ERR, fnic->lport->host,
"itmf_cmpl sc is null - hdr status = %s tag = 0x%x\n",
fnic_fcpio_status_to_str(hdr_status), id);
return;
}
io_lock = fnic_io_lock_hash(fnic, sc);
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
WARN_ON_ONCE(!io_req);
if (!io_req) {
atomic64_inc(&fnic_stats->io_stats.ioreq_null);
spin_unlock_irqrestore(io_lock, flags);
CMD_FLAGS(sc) |= FNIC_IO_ABT_TERM_REQ_NULL;
shost_printk(KERN_ERR, fnic->lport->host,
"itmf_cmpl io_req is null - "
"hdr status = %s tag = 0x%x sc 0x%p\n",
fnic_fcpio_status_to_str(hdr_status), id, sc);
return;
}
start_time = io_req->start_time;
if ((id & FNIC_TAG_ABORT) && (id & FNIC_TAG_DEV_RST)) {
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"dev reset abts cmpl recd. id %x status %s\n",
id, fnic_fcpio_status_to_str(hdr_status));
CMD_STATE(sc) = FNIC_IOREQ_ABTS_COMPLETE;
CMD_ABTS_STATUS(sc) = hdr_status;
CMD_FLAGS(sc) |= FNIC_DEV_RST_DONE;
if (io_req->abts_done)
complete(io_req->abts_done);
spin_unlock_irqrestore(io_lock, flags);
} else if (id & FNIC_TAG_ABORT) {
switch (hdr_status) {
case FCPIO_SUCCESS:
break;
case FCPIO_TIMEOUT:
if (CMD_FLAGS(sc) & FNIC_IO_ABTS_ISSUED)
atomic64_inc(&abts_stats->abort_fw_timeouts);
else
atomic64_inc(
&term_stats->terminate_fw_timeouts);
break;
case FCPIO_IO_NOT_FOUND:
if (CMD_FLAGS(sc) & FNIC_IO_ABTS_ISSUED)
atomic64_inc(&abts_stats->abort_io_not_found);
else
atomic64_inc(
&term_stats->terminate_io_not_found);
break;
default:
if (CMD_FLAGS(sc) & FNIC_IO_ABTS_ISSUED)
atomic64_inc(&abts_stats->abort_failures);
else
atomic64_inc(
&term_stats->terminate_failures);
break;
}
if (CMD_STATE(sc) != FNIC_IOREQ_ABTS_PENDING) {
spin_unlock_irqrestore(io_lock, flags);
return;
}
CMD_ABTS_STATUS(sc) = hdr_status;
CMD_FLAGS(sc) |= FNIC_IO_ABT_TERM_DONE;
atomic64_dec(&fnic_stats->io_stats.active_ios);
if (atomic64_read(&fnic->io_cmpl_skip))
atomic64_dec(&fnic->io_cmpl_skip);
else
atomic64_inc(&fnic_stats->io_stats.io_completions);
if (!(CMD_FLAGS(sc) & (FNIC_IO_ABORTED | FNIC_IO_DONE)))
atomic64_inc(&misc_stats->no_icmnd_itmf_cmpls);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"abts cmpl recd. id %d status %s\n",
(int)(id & FNIC_TAG_MASK),
fnic_fcpio_status_to_str(hdr_status));
if (io_req->abts_done) {
complete(io_req->abts_done);
spin_unlock_irqrestore(io_lock, flags);
} else {
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"abts cmpl, completing IO\n");
CMD_SP(sc) = NULL;
sc->result = (DID_ERROR << 16);
spin_unlock_irqrestore(io_lock, flags);
fnic_release_ioreq_buf(fnic, io_req, sc);
mempool_free(io_req, fnic->io_req_pool);
if (sc->scsi_done) {
FNIC_TRACE(fnic_fcpio_itmf_cmpl_handler,
sc->device->host->host_no, id,
sc,
jiffies_to_msecs(jiffies - start_time),
desc,
(((u64)hdr_status << 40) |
(u64)sc->cmnd[0] << 32 |
(u64)sc->cmnd[2] << 24 |
(u64)sc->cmnd[3] << 16 |
(u64)sc->cmnd[4] << 8 | sc->cmnd[5]),
(((u64)CMD_FLAGS(sc) << 32) |
CMD_STATE(sc)));
sc->scsi_done(sc);
}
}
} else if (id & FNIC_TAG_DEV_RST) {
CMD_LR_STATUS(sc) = hdr_status;
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING) {
spin_unlock_irqrestore(io_lock, flags);
CMD_FLAGS(sc) |= FNIC_DEV_RST_ABTS_PENDING;
FNIC_TRACE(fnic_fcpio_itmf_cmpl_handler,
sc->device->host->host_no, id, sc,
jiffies_to_msecs(jiffies - start_time),
desc, 0,
(((u64)CMD_FLAGS(sc) << 32) | CMD_STATE(sc)));
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Terminate pending "
"dev reset cmpl recd. id %d status %s\n",
(int)(id & FNIC_TAG_MASK),
fnic_fcpio_status_to_str(hdr_status));
return;
}
if (CMD_FLAGS(sc) & FNIC_DEV_RST_TIMED_OUT) {
spin_unlock_irqrestore(io_lock, flags);
FNIC_TRACE(fnic_fcpio_itmf_cmpl_handler,
sc->device->host->host_no, id, sc,
jiffies_to_msecs(jiffies - start_time),
desc, 0,
(((u64)CMD_FLAGS(sc) << 32) | CMD_STATE(sc)));
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"dev reset cmpl recd after time out. "
"id %d status %s\n",
(int)(id & FNIC_TAG_MASK),
fnic_fcpio_status_to_str(hdr_status));
return;
}
CMD_STATE(sc) = FNIC_IOREQ_CMD_COMPLETE;
CMD_FLAGS(sc) |= FNIC_DEV_RST_DONE;
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"dev reset cmpl recd. id %d status %s\n",
(int)(id & FNIC_TAG_MASK),
fnic_fcpio_status_to_str(hdr_status));
if (io_req->dr_done)
complete(io_req->dr_done);
spin_unlock_irqrestore(io_lock, flags);
} else {
shost_printk(KERN_ERR, fnic->lport->host,
"Unexpected itmf io state %s tag %x\n",
fnic_ioreq_state_to_str(CMD_STATE(sc)), id);
spin_unlock_irqrestore(io_lock, flags);
}
}
static int fnic_fcpio_cmpl_handler(struct vnic_dev *vdev,
unsigned int cq_index,
struct fcpio_fw_req *desc)
{
struct fnic *fnic = vnic_dev_priv(vdev);
switch (desc->hdr.type) {
case FCPIO_ICMND_CMPL:
case FCPIO_ITMF_CMPL:
case FCPIO_FLOGI_REG_CMPL:
case FCPIO_FLOGI_FIP_REG_CMPL:
case FCPIO_RESET_CMPL:
atomic64_dec(&fnic->fnic_stats.fw_stats.active_fw_reqs);
break;
default:
break;
}
switch (desc->hdr.type) {
case FCPIO_ACK:
fnic_fcpio_ack_handler(fnic, cq_index, desc);
break;
case FCPIO_ICMND_CMPL:
fnic_fcpio_icmnd_cmpl_handler(fnic, desc);
break;
case FCPIO_ITMF_CMPL:
fnic_fcpio_itmf_cmpl_handler(fnic, desc);
break;
case FCPIO_FLOGI_REG_CMPL:
case FCPIO_FLOGI_FIP_REG_CMPL:
fnic_fcpio_flogi_reg_cmpl_handler(fnic, desc);
break;
case FCPIO_RESET_CMPL:
fnic_fcpio_fw_reset_cmpl_handler(fnic, desc);
break;
default:
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"firmware completion type %d\n",
desc->hdr.type);
break;
}
return 0;
}
int fnic_wq_copy_cmpl_handler(struct fnic *fnic, int copy_work_to_do)
{
unsigned int wq_work_done = 0;
unsigned int i, cq_index;
unsigned int cur_work_done;
for (i = 0; i < fnic->wq_copy_count; i++) {
cq_index = i + fnic->raw_wq_count + fnic->rq_count;
cur_work_done = vnic_cq_copy_service(&fnic->cq[cq_index],
fnic_fcpio_cmpl_handler,
copy_work_to_do);
wq_work_done += cur_work_done;
}
return wq_work_done;
}
static void fnic_cleanup_io(struct fnic *fnic, int exclude_id)
{
int i;
struct fnic_io_req *io_req;
unsigned long flags = 0;
struct scsi_cmnd *sc;
spinlock_t *io_lock;
unsigned long start_time = 0;
struct fnic_stats *fnic_stats = &fnic->fnic_stats;
for (i = 0; i < fnic->fnic_max_tag_id; i++) {
if (i == exclude_id)
continue;
io_lock = fnic_io_lock_tag(fnic, i);
spin_lock_irqsave(io_lock, flags);
sc = scsi_host_find_tag(fnic->lport->host, i);
if (!sc) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
io_req = (struct fnic_io_req *)CMD_SP(sc);
if ((CMD_FLAGS(sc) & FNIC_DEVICE_RESET) &&
!(CMD_FLAGS(sc) & FNIC_DEV_RST_DONE)) {
CMD_FLAGS(sc) |= FNIC_DEV_RST_DONE;
if (io_req && io_req->dr_done)
complete(io_req->dr_done);
else if (io_req && io_req->abts_done)
complete(io_req->abts_done);
spin_unlock_irqrestore(io_lock, flags);
continue;
} else if (CMD_FLAGS(sc) & FNIC_DEVICE_RESET) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
if (!io_req) {
spin_unlock_irqrestore(io_lock, flags);
goto cleanup_scsi_cmd;
}
CMD_SP(sc) = NULL;
spin_unlock_irqrestore(io_lock, flags);
start_time = io_req->start_time;
fnic_release_ioreq_buf(fnic, io_req, sc);
mempool_free(io_req, fnic->io_req_pool);
cleanup_scsi_cmd:
sc->result = DID_TRANSPORT_DISRUPTED << 16;
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"%s: sc duration = %lu DID_TRANSPORT_DISRUPTED\n",
__func__, (jiffies - start_time));
if (atomic64_read(&fnic->io_cmpl_skip))
atomic64_dec(&fnic->io_cmpl_skip);
else
atomic64_inc(&fnic_stats->io_stats.io_completions);
if (sc->scsi_done) {
FNIC_TRACE(fnic_cleanup_io,
sc->device->host->host_no, i, sc,
jiffies_to_msecs(jiffies - start_time),
0, ((u64)sc->cmnd[0] << 32 |
(u64)sc->cmnd[2] << 24 |
(u64)sc->cmnd[3] << 16 |
(u64)sc->cmnd[4] << 8 | sc->cmnd[5]),
(((u64)CMD_FLAGS(sc) << 32) | CMD_STATE(sc)));
sc->scsi_done(sc);
}
}
}
void fnic_wq_copy_cleanup_handler(struct vnic_wq_copy *wq,
struct fcpio_host_req *desc)
{
u32 id;
struct fnic *fnic = vnic_dev_priv(wq->vdev);
struct fnic_io_req *io_req;
struct scsi_cmnd *sc;
unsigned long flags;
spinlock_t *io_lock;
unsigned long start_time = 0;
fcpio_tag_id_dec(&desc->hdr.tag, &id);
id &= FNIC_TAG_MASK;
if (id >= fnic->fnic_max_tag_id)
return;
sc = scsi_host_find_tag(fnic->lport->host, id);
if (!sc)
return;
io_lock = fnic_io_lock_hash(fnic, sc);
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (!io_req) {
spin_unlock_irqrestore(io_lock, flags);
goto wq_copy_cleanup_scsi_cmd;
}
CMD_SP(sc) = NULL;
spin_unlock_irqrestore(io_lock, flags);
start_time = io_req->start_time;
fnic_release_ioreq_buf(fnic, io_req, sc);
mempool_free(io_req, fnic->io_req_pool);
wq_copy_cleanup_scsi_cmd:
sc->result = DID_NO_CONNECT << 16;
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host, "wq_copy_cleanup_handler:"
" DID_NO_CONNECT\n");
if (sc->scsi_done) {
FNIC_TRACE(fnic_wq_copy_cleanup_handler,
sc->device->host->host_no, id, sc,
jiffies_to_msecs(jiffies - start_time),
0, ((u64)sc->cmnd[0] << 32 |
(u64)sc->cmnd[2] << 24 | (u64)sc->cmnd[3] << 16 |
(u64)sc->cmnd[4] << 8 | sc->cmnd[5]),
(((u64)CMD_FLAGS(sc) << 32) | CMD_STATE(sc)));
sc->scsi_done(sc);
}
}
static inline int fnic_queue_abort_io_req(struct fnic *fnic, int tag,
u32 task_req, u8 *fc_lun,
struct fnic_io_req *io_req)
{
struct vnic_wq_copy *wq = &fnic->wq_copy[0];
struct Scsi_Host *host = fnic->lport->host;
struct misc_stats *misc_stats = &fnic->fnic_stats.misc_stats;
unsigned long flags;
spin_lock_irqsave(host->host_lock, flags);
if (unlikely(fnic_chk_state_flags_locked(fnic,
FNIC_FLAGS_IO_BLOCKED))) {
spin_unlock_irqrestore(host->host_lock, flags);
return 1;
} else
atomic_inc(&fnic->in_flight);
spin_unlock_irqrestore(host->host_lock, flags);
spin_lock_irqsave(&fnic->wq_copy_lock[0], flags);
if (vnic_wq_copy_desc_avail(wq) <= fnic->wq_copy_desc_low[0])
free_wq_copy_descs(fnic, wq);
if (!vnic_wq_copy_desc_avail(wq)) {
spin_unlock_irqrestore(&fnic->wq_copy_lock[0], flags);
atomic_dec(&fnic->in_flight);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"fnic_queue_abort_io_req: failure: no descriptors\n");
atomic64_inc(&misc_stats->abts_cpwq_alloc_failures);
return 1;
}
fnic_queue_wq_copy_desc_itmf(wq, tag | FNIC_TAG_ABORT,
0, task_req, tag, fc_lun, io_req->port_id,
fnic->config.ra_tov, fnic->config.ed_tov);
atomic64_inc(&fnic->fnic_stats.fw_stats.active_fw_reqs);
if (atomic64_read(&fnic->fnic_stats.fw_stats.active_fw_reqs) >
atomic64_read(&fnic->fnic_stats.fw_stats.max_fw_reqs))
atomic64_set(&fnic->fnic_stats.fw_stats.max_fw_reqs,
atomic64_read(&fnic->fnic_stats.fw_stats.active_fw_reqs));
spin_unlock_irqrestore(&fnic->wq_copy_lock[0], flags);
atomic_dec(&fnic->in_flight);
return 0;
}
static void fnic_rport_exch_reset(struct fnic *fnic, u32 port_id)
{
int tag;
int abt_tag;
int term_cnt = 0;
struct fnic_io_req *io_req;
spinlock_t *io_lock;
unsigned long flags;
struct scsi_cmnd *sc;
struct reset_stats *reset_stats = &fnic->fnic_stats.reset_stats;
struct terminate_stats *term_stats = &fnic->fnic_stats.term_stats;
struct scsi_lun fc_lun;
enum fnic_ioreq_state old_ioreq_state;
FNIC_SCSI_DBG(KERN_DEBUG,
fnic->lport->host,
"fnic_rport_exch_reset called portid 0x%06x\n",
port_id);
if (fnic->in_remove)
return;
for (tag = 0; tag < fnic->fnic_max_tag_id; tag++) {
abt_tag = tag;
io_lock = fnic_io_lock_tag(fnic, tag);
spin_lock_irqsave(io_lock, flags);
sc = scsi_host_find_tag(fnic->lport->host, tag);
if (!sc) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (!io_req || io_req->port_id != port_id) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
if ((CMD_FLAGS(sc) & FNIC_DEVICE_RESET) &&
(!(CMD_FLAGS(sc) & FNIC_DEV_RST_ISSUED))) {
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"fnic_rport_exch_reset dev rst not pending sc 0x%p\n",
sc);
spin_unlock_irqrestore(io_lock, flags);
continue;
}
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
if (io_req->abts_done) {
shost_printk(KERN_ERR, fnic->lport->host,
"fnic_rport_exch_reset: io_req->abts_done is set "
"state is %s\n",
fnic_ioreq_state_to_str(CMD_STATE(sc)));
}
if (!(CMD_FLAGS(sc) & FNIC_IO_ISSUED)) {
shost_printk(KERN_ERR, fnic->lport->host,
"rport_exch_reset "
"IO not yet issued %p tag 0x%x flags "
"%x state %d\n",
sc, tag, CMD_FLAGS(sc), CMD_STATE(sc));
}
old_ioreq_state = CMD_STATE(sc);
CMD_STATE(sc) = FNIC_IOREQ_ABTS_PENDING;
CMD_ABTS_STATUS(sc) = FCPIO_INVALID_CODE;
if (CMD_FLAGS(sc) & FNIC_DEVICE_RESET) {
atomic64_inc(&reset_stats->device_reset_terminates);
abt_tag = (tag | FNIC_TAG_DEV_RST);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"fnic_rport_exch_reset dev rst sc 0x%p\n",
sc);
}
BUG_ON(io_req->abts_done);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"fnic_rport_reset_exch: Issuing abts\n");
spin_unlock_irqrestore(io_lock, flags);
int_to_scsilun(sc->device->lun, &fc_lun);
if (fnic_queue_abort_io_req(fnic, abt_tag,
FCPIO_ITMF_ABT_TASK_TERM,
fc_lun.scsi_lun, io_req)) {
spin_lock_irqsave(io_lock, flags);
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING)
CMD_STATE(sc) = old_ioreq_state;
spin_unlock_irqrestore(io_lock, flags);
} else {
spin_lock_irqsave(io_lock, flags);
if (CMD_FLAGS(sc) & FNIC_DEVICE_RESET)
CMD_FLAGS(sc) |= FNIC_DEV_RST_TERM_ISSUED;
else
CMD_FLAGS(sc) |= FNIC_IO_INTERNAL_TERM_ISSUED;
spin_unlock_irqrestore(io_lock, flags);
atomic64_inc(&term_stats->terminates);
term_cnt++;
}
}
if (term_cnt > atomic64_read(&term_stats->max_terminates))
atomic64_set(&term_stats->max_terminates, term_cnt);
}
void fnic_terminate_rport_io(struct fc_rport *rport)
{
int tag;
int abt_tag;
int term_cnt = 0;
struct fnic_io_req *io_req;
spinlock_t *io_lock;
unsigned long flags;
struct scsi_cmnd *sc;
struct scsi_lun fc_lun;
struct fc_rport_libfc_priv *rdata;
struct fc_lport *lport;
struct fnic *fnic;
struct fc_rport *cmd_rport;
struct reset_stats *reset_stats;
struct terminate_stats *term_stats;
enum fnic_ioreq_state old_ioreq_state;
if (!rport) {
printk(KERN_ERR "fnic_terminate_rport_io: rport is NULL\n");
return;
}
rdata = rport->dd_data;
if (!rdata) {
printk(KERN_ERR "fnic_terminate_rport_io: rdata is NULL\n");
return;
}
lport = rdata->local_port;
if (!lport) {
printk(KERN_ERR "fnic_terminate_rport_io: lport is NULL\n");
return;
}
fnic = lport_priv(lport);
FNIC_SCSI_DBG(KERN_DEBUG,
fnic->lport->host, "fnic_terminate_rport_io called"
" wwpn 0x%llx, wwnn0x%llx, rport 0x%p, portid 0x%06x\n",
rport->port_name, rport->node_name, rport,
rport->port_id);
if (fnic->in_remove)
return;
reset_stats = &fnic->fnic_stats.reset_stats;
term_stats = &fnic->fnic_stats.term_stats;
for (tag = 0; tag < fnic->fnic_max_tag_id; tag++) {
abt_tag = tag;
io_lock = fnic_io_lock_tag(fnic, tag);
spin_lock_irqsave(io_lock, flags);
sc = scsi_host_find_tag(fnic->lport->host, tag);
if (!sc) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
cmd_rport = starget_to_rport(scsi_target(sc->device));
if (rport != cmd_rport) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (!io_req || rport != cmd_rport) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
if ((CMD_FLAGS(sc) & FNIC_DEVICE_RESET) &&
(!(CMD_FLAGS(sc) & FNIC_DEV_RST_ISSUED))) {
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"fnic_terminate_rport_io dev rst not pending sc 0x%p\n",
sc);
spin_unlock_irqrestore(io_lock, flags);
continue;
}
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
if (io_req->abts_done) {
shost_printk(KERN_ERR, fnic->lport->host,
"fnic_terminate_rport_io: io_req->abts_done is set "
"state is %s\n",
fnic_ioreq_state_to_str(CMD_STATE(sc)));
}
if (!(CMD_FLAGS(sc) & FNIC_IO_ISSUED)) {
FNIC_SCSI_DBG(KERN_INFO, fnic->lport->host,
"fnic_terminate_rport_io "
"IO not yet issued %p tag 0x%x flags "
"%x state %d\n",
sc, tag, CMD_FLAGS(sc), CMD_STATE(sc));
}
old_ioreq_state = CMD_STATE(sc);
CMD_STATE(sc) = FNIC_IOREQ_ABTS_PENDING;
CMD_ABTS_STATUS(sc) = FCPIO_INVALID_CODE;
if (CMD_FLAGS(sc) & FNIC_DEVICE_RESET) {
atomic64_inc(&reset_stats->device_reset_terminates);
abt_tag = (tag | FNIC_TAG_DEV_RST);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"fnic_terminate_rport_io dev rst sc 0x%p\n", sc);
}
BUG_ON(io_req->abts_done);
FNIC_SCSI_DBG(KERN_DEBUG,
fnic->lport->host,
"fnic_terminate_rport_io: Issuing abts\n");
spin_unlock_irqrestore(io_lock, flags);
int_to_scsilun(sc->device->lun, &fc_lun);
if (fnic_queue_abort_io_req(fnic, abt_tag,
FCPIO_ITMF_ABT_TASK_TERM,
fc_lun.scsi_lun, io_req)) {
spin_lock_irqsave(io_lock, flags);
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING)
CMD_STATE(sc) = old_ioreq_state;
spin_unlock_irqrestore(io_lock, flags);
} else {
spin_lock_irqsave(io_lock, flags);
if (CMD_FLAGS(sc) & FNIC_DEVICE_RESET)
CMD_FLAGS(sc) |= FNIC_DEV_RST_TERM_ISSUED;
else
CMD_FLAGS(sc) |= FNIC_IO_INTERNAL_TERM_ISSUED;
spin_unlock_irqrestore(io_lock, flags);
atomic64_inc(&term_stats->terminates);
term_cnt++;
}
}
if (term_cnt > atomic64_read(&term_stats->max_terminates))
atomic64_set(&term_stats->max_terminates, term_cnt);
}
int fnic_abort_cmd(struct scsi_cmnd *sc)
{
struct fc_lport *lp;
struct fnic *fnic;
struct fnic_io_req *io_req = NULL;
struct fc_rport *rport;
spinlock_t *io_lock;
unsigned long flags;
unsigned long start_time = 0;
int ret = SUCCESS;
u32 task_req = 0;
struct scsi_lun fc_lun;
struct fnic_stats *fnic_stats;
struct abort_stats *abts_stats;
struct terminate_stats *term_stats;
enum fnic_ioreq_state old_ioreq_state;
int tag;
DECLARE_COMPLETION_ONSTACK(tm_done);
fc_block_scsi_eh(sc);
lp = shost_priv(sc->device->host);
fnic = lport_priv(lp);
fnic_stats = &fnic->fnic_stats;
abts_stats = &fnic->fnic_stats.abts_stats;
term_stats = &fnic->fnic_stats.term_stats;
rport = starget_to_rport(scsi_target(sc->device));
tag = sc->request->tag;
FNIC_SCSI_DBG(KERN_DEBUG,
fnic->lport->host,
"Abort Cmd called FCID 0x%x, LUN 0x%llx TAG %x flags %x\n",
rport->port_id, sc->device->lun, tag, CMD_FLAGS(sc));
CMD_FLAGS(sc) = FNIC_NO_FLAGS;
if (lp->state != LPORT_ST_READY || !(lp->link_up)) {
ret = FAILED;
goto fnic_abort_cmd_end;
}
io_lock = fnic_io_lock_hash(fnic, sc);
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (!io_req) {
spin_unlock_irqrestore(io_lock, flags);
goto fnic_abort_cmd_end;
}
io_req->abts_done = &tm_done;
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING) {
spin_unlock_irqrestore(io_lock, flags);
goto wait_pending;
}
old_ioreq_state = CMD_STATE(sc);
CMD_STATE(sc) = FNIC_IOREQ_ABTS_PENDING;
CMD_ABTS_STATUS(sc) = FCPIO_INVALID_CODE;
spin_unlock_irqrestore(io_lock, flags);
if (fc_remote_port_chkready(rport) == 0)
task_req = FCPIO_ITMF_ABT_TASK;
else {
atomic64_inc(&fnic_stats->misc_stats.rport_not_ready);
task_req = FCPIO_ITMF_ABT_TASK_TERM;
}
int_to_scsilun(sc->device->lun, &fc_lun);
if (fnic_queue_abort_io_req(fnic, sc->request->tag, task_req,
fc_lun.scsi_lun, io_req)) {
spin_lock_irqsave(io_lock, flags);
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING)
CMD_STATE(sc) = old_ioreq_state;
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (io_req)
io_req->abts_done = NULL;
spin_unlock_irqrestore(io_lock, flags);
ret = FAILED;
goto fnic_abort_cmd_end;
}
if (task_req == FCPIO_ITMF_ABT_TASK) {
CMD_FLAGS(sc) |= FNIC_IO_ABTS_ISSUED;
atomic64_inc(&fnic_stats->abts_stats.aborts);
} else {
CMD_FLAGS(sc) |= FNIC_IO_TERM_ISSUED;
atomic64_inc(&fnic_stats->term_stats.terminates);
}
wait_pending:
wait_for_completion_timeout(&tm_done,
msecs_to_jiffies
(2 * fnic->config.ra_tov +
fnic->config.ed_tov));
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (!io_req) {
atomic64_inc(&fnic_stats->io_stats.ioreq_null);
spin_unlock_irqrestore(io_lock, flags);
CMD_FLAGS(sc) |= FNIC_IO_ABT_TERM_REQ_NULL;
ret = FAILED;
goto fnic_abort_cmd_end;
}
io_req->abts_done = NULL;
if (CMD_ABTS_STATUS(sc) == FCPIO_INVALID_CODE) {
spin_unlock_irqrestore(io_lock, flags);
if (task_req == FCPIO_ITMF_ABT_TASK) {
atomic64_inc(&abts_stats->abort_drv_timeouts);
} else {
atomic64_inc(&term_stats->terminate_drv_timeouts);
}
CMD_FLAGS(sc) |= FNIC_IO_ABT_TERM_TIMED_OUT;
ret = FAILED;
goto fnic_abort_cmd_end;
}
if (!(CMD_FLAGS(sc) & (FNIC_IO_ABORTED | FNIC_IO_DONE))) {
spin_unlock_irqrestore(io_lock, flags);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Issuing Host reset due to out of order IO\n");
if (fnic_host_reset(sc) == FAILED) {
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"fnic_host_reset failed.\n");
}
ret = FAILED;
goto fnic_abort_cmd_end;
}
CMD_STATE(sc) = FNIC_IOREQ_ABTS_COMPLETE;
if (CMD_ABTS_STATUS(sc) != FCPIO_SUCCESS)
ret = FAILED;
CMD_SP(sc) = NULL;
spin_unlock_irqrestore(io_lock, flags);
start_time = io_req->start_time;
fnic_release_ioreq_buf(fnic, io_req, sc);
mempool_free(io_req, fnic->io_req_pool);
fnic_abort_cmd_end:
FNIC_TRACE(fnic_abort_cmd, sc->device->host->host_no,
sc->request->tag, sc,
jiffies_to_msecs(jiffies - start_time),
0, ((u64)sc->cmnd[0] << 32 |
(u64)sc->cmnd[2] << 24 | (u64)sc->cmnd[3] << 16 |
(u64)sc->cmnd[4] << 8 | sc->cmnd[5]),
(((u64)CMD_FLAGS(sc) << 32) | CMD_STATE(sc)));
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Returning from abort cmd type %x %s\n", task_req,
(ret == SUCCESS) ?
"SUCCESS" : "FAILED");
return ret;
}
static inline int fnic_queue_dr_io_req(struct fnic *fnic,
struct scsi_cmnd *sc,
struct fnic_io_req *io_req)
{
struct vnic_wq_copy *wq = &fnic->wq_copy[0];
struct Scsi_Host *host = fnic->lport->host;
struct misc_stats *misc_stats = &fnic->fnic_stats.misc_stats;
struct scsi_lun fc_lun;
int ret = 0;
unsigned long intr_flags;
spin_lock_irqsave(host->host_lock, intr_flags);
if (unlikely(fnic_chk_state_flags_locked(fnic,
FNIC_FLAGS_IO_BLOCKED))) {
spin_unlock_irqrestore(host->host_lock, intr_flags);
return FAILED;
} else
atomic_inc(&fnic->in_flight);
spin_unlock_irqrestore(host->host_lock, intr_flags);
spin_lock_irqsave(&fnic->wq_copy_lock[0], intr_flags);
if (vnic_wq_copy_desc_avail(wq) <= fnic->wq_copy_desc_low[0])
free_wq_copy_descs(fnic, wq);
if (!vnic_wq_copy_desc_avail(wq)) {
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"queue_dr_io_req failure - no descriptors\n");
atomic64_inc(&misc_stats->devrst_cpwq_alloc_failures);
ret = -EAGAIN;
goto lr_io_req_end;
}
int_to_scsilun(sc->device->lun, &fc_lun);
fnic_queue_wq_copy_desc_itmf(wq, sc->request->tag | FNIC_TAG_DEV_RST,
0, FCPIO_ITMF_LUN_RESET, SCSI_NO_TAG,
fc_lun.scsi_lun, io_req->port_id,
fnic->config.ra_tov, fnic->config.ed_tov);
atomic64_inc(&fnic->fnic_stats.fw_stats.active_fw_reqs);
if (atomic64_read(&fnic->fnic_stats.fw_stats.active_fw_reqs) >
atomic64_read(&fnic->fnic_stats.fw_stats.max_fw_reqs))
atomic64_set(&fnic->fnic_stats.fw_stats.max_fw_reqs,
atomic64_read(&fnic->fnic_stats.fw_stats.active_fw_reqs));
lr_io_req_end:
spin_unlock_irqrestore(&fnic->wq_copy_lock[0], intr_flags);
atomic_dec(&fnic->in_flight);
return ret;
}
static int fnic_clean_pending_aborts(struct fnic *fnic,
struct scsi_cmnd *lr_sc)
{
int tag, abt_tag;
struct fnic_io_req *io_req;
spinlock_t *io_lock;
unsigned long flags;
int ret = 0;
struct scsi_cmnd *sc;
struct scsi_lun fc_lun;
struct scsi_device *lun_dev = lr_sc->device;
DECLARE_COMPLETION_ONSTACK(tm_done);
enum fnic_ioreq_state old_ioreq_state;
for (tag = 0; tag < fnic->fnic_max_tag_id; tag++) {
io_lock = fnic_io_lock_tag(fnic, tag);
spin_lock_irqsave(io_lock, flags);
sc = scsi_host_find_tag(fnic->lport->host, tag);
if (!sc || sc == lr_sc || sc->device != lun_dev) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (!io_req || sc->device != lun_dev) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Found IO in %s on lun\n",
fnic_ioreq_state_to_str(CMD_STATE(sc)));
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
if ((CMD_FLAGS(sc) & FNIC_DEVICE_RESET) &&
(!(CMD_FLAGS(sc) & FNIC_DEV_RST_ISSUED))) {
FNIC_SCSI_DBG(KERN_INFO, fnic->lport->host,
"%s dev rst not pending sc 0x%p\n", __func__,
sc);
spin_unlock_irqrestore(io_lock, flags);
continue;
}
if (io_req->abts_done)
shost_printk(KERN_ERR, fnic->lport->host,
"%s: io_req->abts_done is set state is %s\n",
__func__, fnic_ioreq_state_to_str(CMD_STATE(sc)));
old_ioreq_state = CMD_STATE(sc);
CMD_STATE(sc) = FNIC_IOREQ_ABTS_PENDING;
BUG_ON(io_req->abts_done);
abt_tag = tag;
if (CMD_FLAGS(sc) & FNIC_DEVICE_RESET) {
abt_tag |= FNIC_TAG_DEV_RST;
FNIC_SCSI_DBG(KERN_INFO, fnic->lport->host,
"%s: dev rst sc 0x%p\n", __func__, sc);
}
CMD_ABTS_STATUS(sc) = FCPIO_INVALID_CODE;
io_req->abts_done = &tm_done;
spin_unlock_irqrestore(io_lock, flags);
int_to_scsilun(sc->device->lun, &fc_lun);
if (fnic_queue_abort_io_req(fnic, abt_tag,
FCPIO_ITMF_ABT_TASK_TERM,
fc_lun.scsi_lun, io_req)) {
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (io_req)
io_req->abts_done = NULL;
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING)
CMD_STATE(sc) = old_ioreq_state;
spin_unlock_irqrestore(io_lock, flags);
ret = 1;
goto clean_pending_aborts_end;
} else {
spin_lock_irqsave(io_lock, flags);
if (CMD_FLAGS(sc) & FNIC_DEVICE_RESET)
CMD_FLAGS(sc) |= FNIC_DEV_RST_TERM_ISSUED;
spin_unlock_irqrestore(io_lock, flags);
}
CMD_FLAGS(sc) |= FNIC_IO_INTERNAL_TERM_ISSUED;
wait_for_completion_timeout(&tm_done,
msecs_to_jiffies
(fnic->config.ed_tov));
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (!io_req) {
spin_unlock_irqrestore(io_lock, flags);
CMD_FLAGS(sc) |= FNIC_IO_ABT_TERM_REQ_NULL;
continue;
}
io_req->abts_done = NULL;
if (CMD_ABTS_STATUS(sc) == FCPIO_INVALID_CODE) {
spin_unlock_irqrestore(io_lock, flags);
CMD_FLAGS(sc) |= FNIC_IO_ABT_TERM_DONE;
ret = 1;
goto clean_pending_aborts_end;
}
CMD_STATE(sc) = FNIC_IOREQ_ABTS_COMPLETE;
CMD_SP(sc) = NULL;
spin_unlock_irqrestore(io_lock, flags);
fnic_release_ioreq_buf(fnic, io_req, sc);
mempool_free(io_req, fnic->io_req_pool);
}
schedule_timeout(msecs_to_jiffies(2 * fnic->config.ed_tov));
if (fnic_is_abts_pending(fnic, lr_sc))
ret = FAILED;
clean_pending_aborts_end:
return ret;
}
static inline int
fnic_scsi_host_start_tag(struct fnic *fnic, struct scsi_cmnd *sc)
{
struct blk_queue_tag *bqt = fnic->lport->host->bqt;
int tag, ret = SCSI_NO_TAG;
BUG_ON(!bqt);
if (!bqt) {
pr_err("Tags are not supported\n");
goto end;
}
do {
tag = find_next_zero_bit(bqt->tag_map, bqt->max_depth, 1);
if (tag >= bqt->max_depth) {
pr_err("Tag allocation failure\n");
goto end;
}
} while (test_and_set_bit(tag, bqt->tag_map));
bqt->tag_index[tag] = sc->request;
sc->request->tag = tag;
sc->tag = tag;
if (!sc->request->special)
sc->request->special = sc;
ret = tag;
end:
return ret;
}
static inline void
fnic_scsi_host_end_tag(struct fnic *fnic, struct scsi_cmnd *sc)
{
struct blk_queue_tag *bqt = fnic->lport->host->bqt;
int tag = sc->request->tag;
if (tag == SCSI_NO_TAG)
return;
BUG_ON(!bqt || !bqt->tag_index[tag]);
if (!bqt)
return;
bqt->tag_index[tag] = NULL;
clear_bit(tag, bqt->tag_map);
return;
}
int fnic_device_reset(struct scsi_cmnd *sc)
{
struct fc_lport *lp;
struct fnic *fnic;
struct fnic_io_req *io_req = NULL;
struct fc_rport *rport;
int status;
int ret = FAILED;
spinlock_t *io_lock;
unsigned long flags;
unsigned long start_time = 0;
struct scsi_lun fc_lun;
struct fnic_stats *fnic_stats;
struct reset_stats *reset_stats;
int tag = 0;
DECLARE_COMPLETION_ONSTACK(tm_done);
int tag_gen_flag = 0;
fc_block_scsi_eh(sc);
lp = shost_priv(sc->device->host);
fnic = lport_priv(lp);
fnic_stats = &fnic->fnic_stats;
reset_stats = &fnic->fnic_stats.reset_stats;
atomic64_inc(&reset_stats->device_resets);
rport = starget_to_rport(scsi_target(sc->device));
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Device reset called FCID 0x%x, LUN 0x%llx sc 0x%p\n",
rport->port_id, sc->device->lun, sc);
if (lp->state != LPORT_ST_READY || !(lp->link_up))
goto fnic_device_reset_end;
if (fc_remote_port_chkready(rport)) {
atomic64_inc(&fnic_stats->misc_stats.rport_not_ready);
goto fnic_device_reset_end;
}
CMD_FLAGS(sc) = FNIC_DEVICE_RESET;
tag = sc->request->tag;
if (unlikely(tag < 0)) {
if (shost_use_blk_mq(sc->device->host))
goto fnic_device_reset_end;
tag = fnic_scsi_host_start_tag(fnic, sc);
if (unlikely(tag == SCSI_NO_TAG))
goto fnic_device_reset_end;
tag_gen_flag = 1;
}
io_lock = fnic_io_lock_hash(fnic, sc);
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (!io_req) {
io_req = mempool_alloc(fnic->io_req_pool, GFP_ATOMIC);
if (!io_req) {
spin_unlock_irqrestore(io_lock, flags);
goto fnic_device_reset_end;
}
memset(io_req, 0, sizeof(*io_req));
io_req->port_id = rport->port_id;
CMD_SP(sc) = (char *)io_req;
}
io_req->dr_done = &tm_done;
CMD_STATE(sc) = FNIC_IOREQ_CMD_PENDING;
CMD_LR_STATUS(sc) = FCPIO_INVALID_CODE;
spin_unlock_irqrestore(io_lock, flags);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host, "TAG %x\n", tag);
if (fnic_queue_dr_io_req(fnic, sc, io_req)) {
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (io_req)
io_req->dr_done = NULL;
goto fnic_device_reset_clean;
}
spin_lock_irqsave(io_lock, flags);
CMD_FLAGS(sc) |= FNIC_DEV_RST_ISSUED;
spin_unlock_irqrestore(io_lock, flags);
wait_for_completion_timeout(&tm_done,
msecs_to_jiffies(FNIC_LUN_RESET_TIMEOUT));
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (!io_req) {
spin_unlock_irqrestore(io_lock, flags);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"io_req is null tag 0x%x sc 0x%p\n", tag, sc);
goto fnic_device_reset_end;
}
io_req->dr_done = NULL;
status = CMD_LR_STATUS(sc);
if (status == FCPIO_INVALID_CODE) {
atomic64_inc(&reset_stats->device_reset_timeouts);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Device reset timed out\n");
CMD_FLAGS(sc) |= FNIC_DEV_RST_TIMED_OUT;
spin_unlock_irqrestore(io_lock, flags);
int_to_scsilun(sc->device->lun, &fc_lun);
while (1) {
spin_lock_irqsave(io_lock, flags);
if (CMD_FLAGS(sc) & FNIC_DEV_RST_TERM_ISSUED) {
spin_unlock_irqrestore(io_lock, flags);
break;
}
spin_unlock_irqrestore(io_lock, flags);
if (fnic_queue_abort_io_req(fnic,
tag | FNIC_TAG_DEV_RST,
FCPIO_ITMF_ABT_TASK_TERM,
fc_lun.scsi_lun, io_req)) {
wait_for_completion_timeout(&tm_done,
msecs_to_jiffies(FNIC_ABT_TERM_DELAY_TIMEOUT));
} else {
spin_lock_irqsave(io_lock, flags);
CMD_FLAGS(sc) |= FNIC_DEV_RST_TERM_ISSUED;
CMD_STATE(sc) = FNIC_IOREQ_ABTS_PENDING;
io_req->abts_done = &tm_done;
spin_unlock_irqrestore(io_lock, flags);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Abort and terminate issued on Device reset "
"tag 0x%x sc 0x%p\n", tag, sc);
break;
}
}
while (1) {
spin_lock_irqsave(io_lock, flags);
if (!(CMD_FLAGS(sc) & FNIC_DEV_RST_DONE)) {
spin_unlock_irqrestore(io_lock, flags);
wait_for_completion_timeout(&tm_done,
msecs_to_jiffies(FNIC_LUN_RESET_TIMEOUT));
break;
} else {
io_req = (struct fnic_io_req *)CMD_SP(sc);
io_req->abts_done = NULL;
goto fnic_device_reset_clean;
}
}
} else {
spin_unlock_irqrestore(io_lock, flags);
}
if (status != FCPIO_SUCCESS) {
spin_lock_irqsave(io_lock, flags);
FNIC_SCSI_DBG(KERN_DEBUG,
fnic->lport->host,
"Device reset completed - failed\n");
io_req = (struct fnic_io_req *)CMD_SP(sc);
goto fnic_device_reset_clean;
}
if (fnic_clean_pending_aborts(fnic, sc)) {
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Device reset failed"
" since could not abort all IOs\n");
goto fnic_device_reset_clean;
}
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (io_req)
ret = SUCCESS;
fnic_device_reset_clean:
if (io_req)
CMD_SP(sc) = NULL;
spin_unlock_irqrestore(io_lock, flags);
if (io_req) {
start_time = io_req->start_time;
fnic_release_ioreq_buf(fnic, io_req, sc);
mempool_free(io_req, fnic->io_req_pool);
}
fnic_device_reset_end:
FNIC_TRACE(fnic_device_reset, sc->device->host->host_no,
sc->request->tag, sc,
jiffies_to_msecs(jiffies - start_time),
0, ((u64)sc->cmnd[0] << 32 |
(u64)sc->cmnd[2] << 24 | (u64)sc->cmnd[3] << 16 |
(u64)sc->cmnd[4] << 8 | sc->cmnd[5]),
(((u64)CMD_FLAGS(sc) << 32) | CMD_STATE(sc)));
if (unlikely(tag_gen_flag))
fnic_scsi_host_end_tag(fnic, sc);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Returning from device reset %s\n",
(ret == SUCCESS) ?
"SUCCESS" : "FAILED");
if (ret == FAILED)
atomic64_inc(&reset_stats->device_reset_failures);
return ret;
}
int fnic_reset(struct Scsi_Host *shost)
{
struct fc_lport *lp;
struct fnic *fnic;
int ret = 0;
struct reset_stats *reset_stats;
lp = shost_priv(shost);
fnic = lport_priv(lp);
reset_stats = &fnic->fnic_stats.reset_stats;
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"fnic_reset called\n");
atomic64_inc(&reset_stats->fnic_resets);
ret = lp->tt.lport_reset(lp);
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"Returning from fnic reset %s\n",
(ret == 0) ?
"SUCCESS" : "FAILED");
if (ret == 0)
atomic64_inc(&reset_stats->fnic_reset_completions);
else
atomic64_inc(&reset_stats->fnic_reset_failures);
return ret;
}
int fnic_host_reset(struct scsi_cmnd *sc)
{
int ret;
unsigned long wait_host_tmo;
struct Scsi_Host *shost = sc->device->host;
struct fc_lport *lp = shost_priv(shost);
ret = (fnic_reset(shost) == 0) ? SUCCESS : FAILED;
if (ret == SUCCESS) {
wait_host_tmo = jiffies + FNIC_HOST_RESET_SETTLE_TIME * HZ;
ret = FAILED;
while (time_before(jiffies, wait_host_tmo)) {
if ((lp->state == LPORT_ST_READY) &&
(lp->link_up)) {
ret = SUCCESS;
break;
}
ssleep(1);
}
}
return ret;
}
void fnic_scsi_abort_io(struct fc_lport *lp)
{
int err = 0;
unsigned long flags;
enum fnic_state old_state;
struct fnic *fnic = lport_priv(lp);
DECLARE_COMPLETION_ONSTACK(remove_wait);
retry_fw_reset:
spin_lock_irqsave(&fnic->fnic_lock, flags);
if (unlikely(fnic->state == FNIC_IN_FC_TRANS_ETH_MODE)) {
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
schedule_timeout(msecs_to_jiffies(100));
goto retry_fw_reset;
}
fnic->remove_wait = &remove_wait;
old_state = fnic->state;
fnic->state = FNIC_IN_FC_TRANS_ETH_MODE;
fnic_update_mac_locked(fnic, fnic->ctlr.ctl_src_addr);
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
err = fnic_fw_reset_handler(fnic);
if (err) {
spin_lock_irqsave(&fnic->fnic_lock, flags);
if (fnic->state == FNIC_IN_FC_TRANS_ETH_MODE)
fnic->state = old_state;
fnic->remove_wait = NULL;
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
return;
}
wait_for_completion_timeout(&remove_wait,
msecs_to_jiffies(FNIC_RMDEVICE_TIMEOUT));
spin_lock_irqsave(&fnic->fnic_lock, flags);
fnic->remove_wait = NULL;
FNIC_SCSI_DBG(KERN_DEBUG, fnic->lport->host,
"fnic_scsi_abort_io %s\n",
(fnic->state == FNIC_IN_ETH_MODE) ?
"SUCCESS" : "FAILED");
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
}
void fnic_scsi_cleanup(struct fc_lport *lp)
{
unsigned long flags;
enum fnic_state old_state;
struct fnic *fnic = lport_priv(lp);
retry_fw_reset:
spin_lock_irqsave(&fnic->fnic_lock, flags);
if (unlikely(fnic->state == FNIC_IN_FC_TRANS_ETH_MODE)) {
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
schedule_timeout(msecs_to_jiffies(100));
goto retry_fw_reset;
}
old_state = fnic->state;
fnic->state = FNIC_IN_FC_TRANS_ETH_MODE;
fnic_update_mac_locked(fnic, fnic->ctlr.ctl_src_addr);
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
if (fnic_fw_reset_handler(fnic)) {
spin_lock_irqsave(&fnic->fnic_lock, flags);
if (fnic->state == FNIC_IN_FC_TRANS_ETH_MODE)
fnic->state = old_state;
spin_unlock_irqrestore(&fnic->fnic_lock, flags);
}
}
void fnic_empty_scsi_cleanup(struct fc_lport *lp)
{
}
void fnic_exch_mgr_reset(struct fc_lport *lp, u32 sid, u32 did)
{
struct fnic *fnic = lport_priv(lp);
if (sid)
goto call_fc_exch_mgr_reset;
if (did) {
fnic_rport_exch_reset(fnic, did);
goto call_fc_exch_mgr_reset;
}
if (!fnic->in_remove)
fnic_scsi_cleanup(lp);
else
fnic_scsi_abort_io(lp);
call_fc_exch_mgr_reset:
fc_exch_mgr_reset(lp, sid, did);
}
int fnic_is_abts_pending(struct fnic *fnic, struct scsi_cmnd *lr_sc)
{
int tag;
struct fnic_io_req *io_req;
spinlock_t *io_lock;
unsigned long flags;
int ret = 0;
struct scsi_cmnd *sc;
struct scsi_device *lun_dev = NULL;
if (lr_sc)
lun_dev = lr_sc->device;
for (tag = 0; tag < fnic->fnic_max_tag_id; tag++) {
sc = scsi_host_find_tag(fnic->lport->host, tag);
if (!sc || (lr_sc && (sc->device != lun_dev || sc == lr_sc)))
continue;
io_lock = fnic_io_lock_hash(fnic, sc);
spin_lock_irqsave(io_lock, flags);
io_req = (struct fnic_io_req *)CMD_SP(sc);
if (!io_req || sc->device != lun_dev) {
spin_unlock_irqrestore(io_lock, flags);
continue;
}
FNIC_SCSI_DBG(KERN_INFO, fnic->lport->host,
"Found IO in %s on lun\n",
fnic_ioreq_state_to_str(CMD_STATE(sc)));
if (CMD_STATE(sc) == FNIC_IOREQ_ABTS_PENDING)
ret = 1;
spin_unlock_irqrestore(io_lock, flags);
}
return ret;
}
