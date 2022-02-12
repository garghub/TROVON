static void
lpfc_debug_save_data(struct lpfc_hba *phba, struct scsi_cmnd *cmnd)
{
void *src, *dst;
struct scatterlist *sgde = scsi_sglist(cmnd);
if (!_dump_buf_data) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9050 BLKGRD: ERROR %s _dump_buf_data is NULL\n",
__func__);
return;
}
if (!sgde) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9051 BLKGRD: ERROR: data scatterlist is null\n");
return;
}
dst = (void *) _dump_buf_data;
while (sgde) {
src = sg_virt(sgde);
memcpy(dst, src, sgde->length);
dst += sgde->length;
sgde = sg_next(sgde);
}
}
static void
lpfc_debug_save_dif(struct lpfc_hba *phba, struct scsi_cmnd *cmnd)
{
void *src, *dst;
struct scatterlist *sgde = scsi_prot_sglist(cmnd);
if (!_dump_buf_dif) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9052 BLKGRD: ERROR %s _dump_buf_data is NULL\n",
__func__);
return;
}
if (!sgde) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9053 BLKGRD: ERROR: prot scatterlist is null\n");
return;
}
dst = _dump_buf_dif;
while (sgde) {
src = sg_virt(sgde);
memcpy(dst, src, sgde->length);
dst += sgde->length;
sgde = sg_next(sgde);
}
}
static void
lpfc_sli4_set_rsp_sgl_last(struct lpfc_hba *phba,
struct lpfc_scsi_buf *lpfc_cmd)
{
struct sli4_sge *sgl = (struct sli4_sge *)lpfc_cmd->fcp_bpl;
if (sgl) {
sgl += 1;
sgl->word2 = le32_to_cpu(sgl->word2);
bf_set(lpfc_sli4_sge_last, sgl, 1);
sgl->word2 = cpu_to_le32(sgl->word2);
}
}
static void
lpfc_update_stats(struct lpfc_hba *phba, struct lpfc_scsi_buf *lpfc_cmd)
{
struct lpfc_rport_data *rdata = lpfc_cmd->rdata;
struct lpfc_nodelist *pnode = rdata->pnode;
struct scsi_cmnd *cmd = lpfc_cmd->pCmd;
unsigned long flags;
struct Scsi_Host *shost = cmd->device->host;
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
unsigned long latency;
int i;
if (cmd->result)
return;
latency = jiffies_to_msecs((long)jiffies - (long)lpfc_cmd->start_time);
spin_lock_irqsave(shost->host_lock, flags);
if (!vport->stat_data_enabled ||
vport->stat_data_blocked ||
!pnode ||
!pnode->lat_data ||
(phba->bucket_type == LPFC_NO_BUCKET)) {
spin_unlock_irqrestore(shost->host_lock, flags);
return;
}
if (phba->bucket_type == LPFC_LINEAR_BUCKET) {
i = (latency + phba->bucket_step - 1 - phba->bucket_base)/
phba->bucket_step;
if (i < 0)
i = 0;
else if (i >= LPFC_MAX_BUCKET_COUNT)
i = LPFC_MAX_BUCKET_COUNT - 1;
} else {
for (i = 0; i < LPFC_MAX_BUCKET_COUNT-1; i++)
if (latency <= (phba->bucket_base +
((1<<i)*phba->bucket_step)))
break;
}
pnode->lat_data[i].cmd_count++;
spin_unlock_irqrestore(shost->host_lock, flags);
}
static void
lpfc_send_sdev_queuedepth_change_event(struct lpfc_hba *phba,
struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
uint32_t lun,
uint32_t old_val,
uint32_t new_val)
{
struct lpfc_fast_path_event *fast_path_evt;
unsigned long flags;
fast_path_evt = lpfc_alloc_fast_evt(phba);
if (!fast_path_evt)
return;
fast_path_evt->un.queue_depth_evt.scsi_event.event_type =
FC_REG_SCSI_EVENT;
fast_path_evt->un.queue_depth_evt.scsi_event.subcategory =
LPFC_EVENT_VARQUEDEPTH;
fast_path_evt->un.queue_depth_evt.scsi_event.lun = lun;
if (ndlp && NLP_CHK_NODE_ACT(ndlp)) {
memcpy(&fast_path_evt->un.queue_depth_evt.scsi_event.wwpn,
&ndlp->nlp_portname, sizeof(struct lpfc_name));
memcpy(&fast_path_evt->un.queue_depth_evt.scsi_event.wwnn,
&ndlp->nlp_nodename, sizeof(struct lpfc_name));
}
fast_path_evt->un.queue_depth_evt.oldval = old_val;
fast_path_evt->un.queue_depth_evt.newval = new_val;
fast_path_evt->vport = vport;
fast_path_evt->work_evt.evt = LPFC_EVT_FASTPATH_MGMT_EVT;
spin_lock_irqsave(&phba->hbalock, flags);
list_add_tail(&fast_path_evt->work_evt.evt_listp, &phba->work_list);
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_worker_wake_up(phba);
return;
}
int
lpfc_change_queue_depth(struct scsi_device *sdev, int qdepth, int reason)
{
struct lpfc_vport *vport = (struct lpfc_vport *) sdev->host->hostdata;
struct lpfc_hba *phba = vport->phba;
struct lpfc_rport_data *rdata;
unsigned long new_queue_depth, old_queue_depth;
old_queue_depth = sdev->queue_depth;
scsi_adjust_queue_depth(sdev, scsi_get_tag_type(sdev), qdepth);
new_queue_depth = sdev->queue_depth;
rdata = sdev->hostdata;
if (rdata)
lpfc_send_sdev_queuedepth_change_event(phba, vport,
rdata->pnode, sdev->lun,
old_queue_depth,
new_queue_depth);
return sdev->queue_depth;
}
void
lpfc_rampdown_queue_depth(struct lpfc_hba *phba)
{
unsigned long flags;
uint32_t evt_posted;
spin_lock_irqsave(&phba->hbalock, flags);
atomic_inc(&phba->num_rsrc_err);
phba->last_rsrc_error_time = jiffies;
if ((phba->last_ramp_down_time + QUEUE_RAMP_DOWN_INTERVAL) > jiffies) {
spin_unlock_irqrestore(&phba->hbalock, flags);
return;
}
phba->last_ramp_down_time = jiffies;
spin_unlock_irqrestore(&phba->hbalock, flags);
spin_lock_irqsave(&phba->pport->work_port_lock, flags);
evt_posted = phba->pport->work_port_events & WORKER_RAMP_DOWN_QUEUE;
if (!evt_posted)
phba->pport->work_port_events |= WORKER_RAMP_DOWN_QUEUE;
spin_unlock_irqrestore(&phba->pport->work_port_lock, flags);
if (!evt_posted)
lpfc_worker_wake_up(phba);
return;
}
static inline void
lpfc_rampup_queue_depth(struct lpfc_vport *vport,
uint32_t queue_depth)
{
unsigned long flags;
struct lpfc_hba *phba = vport->phba;
uint32_t evt_posted;
atomic_inc(&phba->num_cmd_success);
if (vport->cfg_lun_queue_depth <= queue_depth)
return;
spin_lock_irqsave(&phba->hbalock, flags);
if (time_before(jiffies,
phba->last_ramp_up_time + QUEUE_RAMP_UP_INTERVAL) ||
time_before(jiffies,
phba->last_rsrc_error_time + QUEUE_RAMP_UP_INTERVAL)) {
spin_unlock_irqrestore(&phba->hbalock, flags);
return;
}
phba->last_ramp_up_time = jiffies;
spin_unlock_irqrestore(&phba->hbalock, flags);
spin_lock_irqsave(&phba->pport->work_port_lock, flags);
evt_posted = phba->pport->work_port_events & WORKER_RAMP_UP_QUEUE;
if (!evt_posted)
phba->pport->work_port_events |= WORKER_RAMP_UP_QUEUE;
spin_unlock_irqrestore(&phba->pport->work_port_lock, flags);
if (!evt_posted)
lpfc_worker_wake_up(phba);
return;
}
void
lpfc_ramp_down_queue_handler(struct lpfc_hba *phba)
{
struct lpfc_vport **vports;
struct Scsi_Host *shost;
struct scsi_device *sdev;
unsigned long new_queue_depth;
unsigned long num_rsrc_err, num_cmd_success;
int i;
num_rsrc_err = atomic_read(&phba->num_rsrc_err);
num_cmd_success = atomic_read(&phba->num_cmd_success);
vports = lpfc_create_vport_work_array(phba);
if (vports != NULL)
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
shost = lpfc_shost_from_vport(vports[i]);
shost_for_each_device(sdev, shost) {
new_queue_depth =
sdev->queue_depth * num_rsrc_err /
(num_rsrc_err + num_cmd_success);
if (!new_queue_depth)
new_queue_depth = sdev->queue_depth - 1;
else
new_queue_depth = sdev->queue_depth -
new_queue_depth;
lpfc_change_queue_depth(sdev, new_queue_depth,
SCSI_QDEPTH_DEFAULT);
}
}
lpfc_destroy_vport_work_array(phba, vports);
atomic_set(&phba->num_rsrc_err, 0);
atomic_set(&phba->num_cmd_success, 0);
}
void
lpfc_ramp_up_queue_handler(struct lpfc_hba *phba)
{
struct lpfc_vport **vports;
struct Scsi_Host *shost;
struct scsi_device *sdev;
int i;
vports = lpfc_create_vport_work_array(phba);
if (vports != NULL)
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
shost = lpfc_shost_from_vport(vports[i]);
shost_for_each_device(sdev, shost) {
if (vports[i]->cfg_lun_queue_depth <=
sdev->queue_depth)
continue;
lpfc_change_queue_depth(sdev,
sdev->queue_depth+1,
SCSI_QDEPTH_RAMP_UP);
}
}
lpfc_destroy_vport_work_array(phba, vports);
atomic_set(&phba->num_rsrc_err, 0);
atomic_set(&phba->num_cmd_success, 0);
}
void
lpfc_scsi_dev_block(struct lpfc_hba *phba)
{
struct lpfc_vport **vports;
struct Scsi_Host *shost;
struct scsi_device *sdev;
struct fc_rport *rport;
int i;
vports = lpfc_create_vport_work_array(phba);
if (vports != NULL)
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
shost = lpfc_shost_from_vport(vports[i]);
shost_for_each_device(sdev, shost) {
rport = starget_to_rport(scsi_target(sdev));
fc_remote_port_delete(rport);
}
}
lpfc_destroy_vport_work_array(phba, vports);
}
static int
lpfc_new_scsi_buf_s3(struct lpfc_vport *vport, int num_to_alloc)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_scsi_buf *psb;
struct ulp_bde64 *bpl;
IOCB_t *iocb;
dma_addr_t pdma_phys_fcp_cmd;
dma_addr_t pdma_phys_fcp_rsp;
dma_addr_t pdma_phys_bpl;
uint16_t iotag;
int bcnt;
for (bcnt = 0; bcnt < num_to_alloc; bcnt++) {
psb = kzalloc(sizeof(struct lpfc_scsi_buf), GFP_KERNEL);
if (!psb)
break;
psb->data = pci_pool_alloc(phba->lpfc_scsi_dma_buf_pool,
GFP_KERNEL, &psb->dma_handle);
if (!psb->data) {
kfree(psb);
break;
}
memset(psb->data, 0, phba->cfg_sg_dma_buf_size);
iotag = lpfc_sli_next_iotag(phba, &psb->cur_iocbq);
if (iotag == 0) {
pci_pool_free(phba->lpfc_scsi_dma_buf_pool,
psb->data, psb->dma_handle);
kfree(psb);
break;
}
psb->cur_iocbq.iocb_flag |= LPFC_IO_FCP;
psb->fcp_cmnd = psb->data;
psb->fcp_rsp = psb->data + sizeof(struct fcp_cmnd);
psb->fcp_bpl = psb->data + sizeof(struct fcp_cmnd) +
sizeof(struct fcp_rsp);
bpl = psb->fcp_bpl;
pdma_phys_fcp_cmd = psb->dma_handle;
pdma_phys_fcp_rsp = psb->dma_handle + sizeof(struct fcp_cmnd);
pdma_phys_bpl = psb->dma_handle + sizeof(struct fcp_cmnd) +
sizeof(struct fcp_rsp);
bpl[0].addrHigh = le32_to_cpu(putPaddrHigh(pdma_phys_fcp_cmd));
bpl[0].addrLow = le32_to_cpu(putPaddrLow(pdma_phys_fcp_cmd));
bpl[0].tus.f.bdeSize = sizeof(struct fcp_cmnd);
bpl[0].tus.f.bdeFlags = BUFF_TYPE_BDE_64;
bpl[0].tus.w = le32_to_cpu(bpl[0].tus.w);
bpl[1].addrHigh = le32_to_cpu(putPaddrHigh(pdma_phys_fcp_rsp));
bpl[1].addrLow = le32_to_cpu(putPaddrLow(pdma_phys_fcp_rsp));
bpl[1].tus.f.bdeSize = sizeof(struct fcp_rsp);
bpl[1].tus.f.bdeFlags = BUFF_TYPE_BDE_64;
bpl[1].tus.w = le32_to_cpu(bpl[1].tus.w);
iocb = &psb->cur_iocbq.iocb;
iocb->un.fcpi64.bdl.ulpIoTag32 = 0;
if ((phba->sli_rev == 3) &&
!(phba->sli3_options & LPFC_SLI3_BG_ENABLED)) {
iocb->un.fcpi64.bdl.bdeFlags = BUFF_TYPE_BDE_IMMED;
iocb->un.fcpi64.bdl.bdeSize = sizeof(struct fcp_cmnd);
iocb->un.fcpi64.bdl.addrLow = offsetof(IOCB_t,
unsli3.fcp_ext.icd);
iocb->un.fcpi64.bdl.addrHigh = 0;
iocb->ulpBdeCount = 0;
iocb->ulpLe = 0;
iocb->unsli3.fcp_ext.rbde.tus.f.bdeFlags =
BUFF_TYPE_BDE_64;
iocb->unsli3.fcp_ext.rbde.tus.f.bdeSize =
sizeof(struct fcp_rsp);
iocb->unsli3.fcp_ext.rbde.addrLow =
putPaddrLow(pdma_phys_fcp_rsp);
iocb->unsli3.fcp_ext.rbde.addrHigh =
putPaddrHigh(pdma_phys_fcp_rsp);
} else {
iocb->un.fcpi64.bdl.bdeFlags = BUFF_TYPE_BLP_64;
iocb->un.fcpi64.bdl.bdeSize =
(2 * sizeof(struct ulp_bde64));
iocb->un.fcpi64.bdl.addrLow =
putPaddrLow(pdma_phys_bpl);
iocb->un.fcpi64.bdl.addrHigh =
putPaddrHigh(pdma_phys_bpl);
iocb->ulpBdeCount = 1;
iocb->ulpLe = 1;
}
iocb->ulpClass = CLASS3;
psb->status = IOSTAT_SUCCESS;
psb->cur_iocbq.context1 = psb;
lpfc_release_scsi_buf_s3(phba, psb);
}
return bcnt;
}
void
lpfc_sli4_vport_delete_fcp_xri_aborted(struct lpfc_vport *vport)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_scsi_buf *psb, *next_psb;
unsigned long iflag = 0;
spin_lock_irqsave(&phba->hbalock, iflag);
spin_lock(&phba->sli4_hba.abts_scsi_buf_list_lock);
list_for_each_entry_safe(psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if (psb->rdata && psb->rdata->pnode
&& psb->rdata->pnode->vport == vport)
psb->rdata = NULL;
}
spin_unlock(&phba->sli4_hba.abts_scsi_buf_list_lock);
spin_unlock_irqrestore(&phba->hbalock, iflag);
}
void
lpfc_sli4_fcp_xri_aborted(struct lpfc_hba *phba,
struct sli4_wcqe_xri_aborted *axri)
{
uint16_t xri = bf_get(lpfc_wcqe_xa_xri, axri);
uint16_t rxid = bf_get(lpfc_wcqe_xa_remote_xid, axri);
struct lpfc_scsi_buf *psb, *next_psb;
unsigned long iflag = 0;
struct lpfc_iocbq *iocbq;
int i;
struct lpfc_nodelist *ndlp;
int rrq_empty = 0;
struct lpfc_sli_ring *pring = &phba->sli.ring[LPFC_ELS_RING];
spin_lock_irqsave(&phba->hbalock, iflag);
spin_lock(&phba->sli4_hba.abts_scsi_buf_list_lock);
list_for_each_entry_safe(psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if (psb->cur_iocbq.sli4_xritag == xri) {
list_del(&psb->list);
psb->exch_busy = 0;
psb->status = IOSTAT_SUCCESS;
spin_unlock(
&phba->sli4_hba.abts_scsi_buf_list_lock);
if (psb->rdata && psb->rdata->pnode)
ndlp = psb->rdata->pnode;
else
ndlp = NULL;
rrq_empty = list_empty(&phba->active_rrq_list);
spin_unlock_irqrestore(&phba->hbalock, iflag);
if (ndlp)
lpfc_set_rrq_active(phba, ndlp, xri, rxid, 1);
lpfc_release_scsi_buf_s4(phba, psb);
if (rrq_empty)
lpfc_worker_wake_up(phba);
return;
}
}
spin_unlock(&phba->sli4_hba.abts_scsi_buf_list_lock);
for (i = 1; i <= phba->sli.last_iotag; i++) {
iocbq = phba->sli.iocbq_lookup[i];
if (!(iocbq->iocb_flag & LPFC_IO_FCP) ||
(iocbq->iocb_flag & LPFC_IO_LIBDFC))
continue;
if (iocbq->sli4_xritag != xri)
continue;
psb = container_of(iocbq, struct lpfc_scsi_buf, cur_iocbq);
psb->exch_busy = 0;
spin_unlock_irqrestore(&phba->hbalock, iflag);
if (pring->txq_cnt)
lpfc_worker_wake_up(phba);
return;
}
spin_unlock_irqrestore(&phba->hbalock, iflag);
}
int
lpfc_sli4_repost_scsi_sgl_list(struct lpfc_hba *phba)
{
struct lpfc_scsi_buf *psb;
int index, status, bcnt = 0, rcnt = 0, rc = 0;
LIST_HEAD(sblist);
for (index = 0; index < phba->sli4_hba.scsi_xri_cnt; index++) {
psb = phba->sli4_hba.lpfc_scsi_psb_array[index];
if (psb) {
list_del(&psb->list);
list_add_tail(&psb->list, &sblist);
if (++rcnt == LPFC_NEMBED_MBOX_SGL_CNT) {
bcnt = rcnt;
rcnt = 0;
}
} else
bcnt = rcnt;
if (index == phba->sli4_hba.scsi_xri_cnt - 1)
bcnt = rcnt;
if (bcnt == 0)
continue;
if (!phba->sli4_hba.extents_in_use)
status = lpfc_sli4_post_scsi_sgl_block(phba,
&sblist,
bcnt);
else
status = lpfc_sli4_post_scsi_sgl_blk_ext(phba,
&sblist,
bcnt);
bcnt = 0;
while (!list_empty(&sblist)) {
list_remove_head(&sblist, psb, struct lpfc_scsi_buf,
list);
if (status) {
psb->exch_busy = 1;
rc++;
} else {
psb->exch_busy = 0;
psb->status = IOSTAT_SUCCESS;
}
lpfc_release_scsi_buf_s4(phba, psb);
}
}
return rc;
}
static int
lpfc_new_scsi_buf_s4(struct lpfc_vport *vport, int num_to_alloc)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_scsi_buf *psb;
struct sli4_sge *sgl;
IOCB_t *iocb;
dma_addr_t pdma_phys_fcp_cmd;
dma_addr_t pdma_phys_fcp_rsp;
dma_addr_t pdma_phys_bpl, pdma_phys_bpl1;
uint16_t iotag, last_xritag = NO_XRI, lxri = 0;
int status = 0, index;
int bcnt;
int non_sequential_xri = 0;
LIST_HEAD(sblist);
for (bcnt = 0; bcnt < num_to_alloc; bcnt++) {
psb = kzalloc(sizeof(struct lpfc_scsi_buf), GFP_KERNEL);
if (!psb)
break;
psb->data = pci_pool_alloc(phba->lpfc_scsi_dma_buf_pool,
GFP_KERNEL, &psb->dma_handle);
if (!psb->data) {
kfree(psb);
break;
}
memset(psb->data, 0, phba->cfg_sg_dma_buf_size);
iotag = lpfc_sli_next_iotag(phba, &psb->cur_iocbq);
if (iotag == 0) {
pci_pool_free(phba->lpfc_scsi_dma_buf_pool,
psb->data, psb->dma_handle);
kfree(psb);
break;
}
lxri = lpfc_sli4_next_xritag(phba);
if (lxri == NO_XRI) {
pci_pool_free(phba->lpfc_scsi_dma_buf_pool,
psb->data, psb->dma_handle);
kfree(psb);
break;
}
psb->cur_iocbq.sli4_lxritag = lxri;
psb->cur_iocbq.sli4_xritag = phba->sli4_hba.xri_ids[lxri];
if (last_xritag != NO_XRI
&& psb->cur_iocbq.sli4_xritag != (last_xritag+1)) {
non_sequential_xri = 1;
} else
list_add_tail(&psb->list, &sblist);
last_xritag = psb->cur_iocbq.sli4_xritag;
index = phba->sli4_hba.scsi_xri_cnt++;
psb->cur_iocbq.iocb_flag |= LPFC_IO_FCP;
psb->fcp_bpl = psb->data;
psb->fcp_cmnd = (psb->data + phba->cfg_sg_dma_buf_size)
- (sizeof(struct fcp_cmnd) + sizeof(struct fcp_rsp));
psb->fcp_rsp = (struct fcp_rsp *)((uint8_t *)psb->fcp_cmnd +
sizeof(struct fcp_cmnd));
sgl = (struct sli4_sge *)psb->fcp_bpl;
pdma_phys_bpl = psb->dma_handle;
pdma_phys_fcp_cmd =
(psb->dma_handle + phba->cfg_sg_dma_buf_size)
- (sizeof(struct fcp_cmnd) + sizeof(struct fcp_rsp));
pdma_phys_fcp_rsp = pdma_phys_fcp_cmd + sizeof(struct fcp_cmnd);
sgl->addr_hi = cpu_to_le32(putPaddrHigh(pdma_phys_fcp_cmd));
sgl->addr_lo = cpu_to_le32(putPaddrLow(pdma_phys_fcp_cmd));
sgl->word2 = le32_to_cpu(sgl->word2);
bf_set(lpfc_sli4_sge_last, sgl, 0);
sgl->word2 = cpu_to_le32(sgl->word2);
sgl->sge_len = cpu_to_le32(sizeof(struct fcp_cmnd));
sgl++;
sgl->addr_hi = cpu_to_le32(putPaddrHigh(pdma_phys_fcp_rsp));
sgl->addr_lo = cpu_to_le32(putPaddrLow(pdma_phys_fcp_rsp));
sgl->word2 = le32_to_cpu(sgl->word2);
bf_set(lpfc_sli4_sge_last, sgl, 1);
sgl->word2 = cpu_to_le32(sgl->word2);
sgl->sge_len = cpu_to_le32(sizeof(struct fcp_rsp));
iocb = &psb->cur_iocbq.iocb;
iocb->un.fcpi64.bdl.ulpIoTag32 = 0;
iocb->un.fcpi64.bdl.bdeFlags = BUFF_TYPE_BDE_64;
iocb->un.fcpi64.bdl.bdeSize = sizeof(struct fcp_cmnd);
iocb->un.fcpi64.bdl.addrLow = putPaddrLow(pdma_phys_fcp_cmd);
iocb->un.fcpi64.bdl.addrHigh = putPaddrHigh(pdma_phys_fcp_cmd);
iocb->ulpBdeCount = 1;
iocb->ulpLe = 1;
iocb->ulpClass = CLASS3;
psb->cur_iocbq.context1 = psb;
if (phba->cfg_sg_dma_buf_size > SGL_PAGE_SIZE)
pdma_phys_bpl1 = pdma_phys_bpl + SGL_PAGE_SIZE;
else
pdma_phys_bpl1 = 0;
psb->dma_phys_bpl = pdma_phys_bpl;
phba->sli4_hba.lpfc_scsi_psb_array[index] = psb;
if (non_sequential_xri) {
status = lpfc_sli4_post_sgl(phba, pdma_phys_bpl,
pdma_phys_bpl1,
psb->cur_iocbq.sli4_xritag);
if (status) {
psb->exch_busy = 1;
} else {
psb->exch_busy = 0;
psb->status = IOSTAT_SUCCESS;
}
lpfc_release_scsi_buf_s4(phba, psb);
break;
}
}
if (bcnt) {
if (!phba->sli4_hba.extents_in_use)
status = lpfc_sli4_post_scsi_sgl_block(phba,
&sblist,
bcnt);
else
status = lpfc_sli4_post_scsi_sgl_blk_ext(phba,
&sblist,
bcnt);
if (status) {
lpfc_printf_log(phba, KERN_ERR, LOG_MBOX | LOG_SLI,
"3021 SCSI SGL post error %d\n",
status);
bcnt = 0;
}
while (!list_empty(&sblist)) {
list_remove_head(&sblist, psb, struct lpfc_scsi_buf,
list);
if (status) {
psb->exch_busy = 1;
} else {
psb->exch_busy = 0;
psb->status = IOSTAT_SUCCESS;
}
lpfc_release_scsi_buf_s4(phba, psb);
}
}
return bcnt + non_sequential_xri;
}
static inline int
lpfc_new_scsi_buf(struct lpfc_vport *vport, int num_to_alloc)
{
return vport->phba->lpfc_new_scsi_buf(vport, num_to_alloc);
}
static struct lpfc_scsi_buf*
lpfc_get_scsi_buf_s3(struct lpfc_hba *phba, struct lpfc_nodelist *ndlp)
{
struct lpfc_scsi_buf * lpfc_cmd = NULL;
struct list_head *scsi_buf_list = &phba->lpfc_scsi_buf_list;
unsigned long iflag = 0;
spin_lock_irqsave(&phba->scsi_buf_list_lock, iflag);
list_remove_head(scsi_buf_list, lpfc_cmd, struct lpfc_scsi_buf, list);
if (lpfc_cmd) {
lpfc_cmd->seg_cnt = 0;
lpfc_cmd->nonsg_phys = 0;
lpfc_cmd->prot_seg_cnt = 0;
}
spin_unlock_irqrestore(&phba->scsi_buf_list_lock, iflag);
return lpfc_cmd;
}
static struct lpfc_scsi_buf*
lpfc_get_scsi_buf_s4(struct lpfc_hba *phba, struct lpfc_nodelist *ndlp)
{
struct lpfc_scsi_buf *lpfc_cmd ;
unsigned long iflag = 0;
int found = 0;
spin_lock_irqsave(&phba->scsi_buf_list_lock, iflag);
list_for_each_entry(lpfc_cmd, &phba->lpfc_scsi_buf_list,
list) {
if (lpfc_test_rrq_active(phba, ndlp,
lpfc_cmd->cur_iocbq.sli4_xritag))
continue;
list_del(&lpfc_cmd->list);
found = 1;
lpfc_cmd->seg_cnt = 0;
lpfc_cmd->nonsg_phys = 0;
lpfc_cmd->prot_seg_cnt = 0;
break;
}
spin_unlock_irqrestore(&phba->scsi_buf_list_lock,
iflag);
if (!found)
return NULL;
else
return lpfc_cmd;
}
static struct lpfc_scsi_buf*
lpfc_get_scsi_buf(struct lpfc_hba *phba, struct lpfc_nodelist *ndlp)
{
return phba->lpfc_get_scsi_buf(phba, ndlp);
}
static void
lpfc_release_scsi_buf_s3(struct lpfc_hba *phba, struct lpfc_scsi_buf *psb)
{
unsigned long iflag = 0;
spin_lock_irqsave(&phba->scsi_buf_list_lock, iflag);
psb->pCmd = NULL;
list_add_tail(&psb->list, &phba->lpfc_scsi_buf_list);
spin_unlock_irqrestore(&phba->scsi_buf_list_lock, iflag);
}
static void
lpfc_release_scsi_buf_s4(struct lpfc_hba *phba, struct lpfc_scsi_buf *psb)
{
unsigned long iflag = 0;
if (psb->exch_busy) {
spin_lock_irqsave(&phba->sli4_hba.abts_scsi_buf_list_lock,
iflag);
psb->pCmd = NULL;
list_add_tail(&psb->list,
&phba->sli4_hba.lpfc_abts_scsi_buf_list);
spin_unlock_irqrestore(&phba->sli4_hba.abts_scsi_buf_list_lock,
iflag);
} else {
spin_lock_irqsave(&phba->scsi_buf_list_lock, iflag);
psb->pCmd = NULL;
list_add_tail(&psb->list, &phba->lpfc_scsi_buf_list);
spin_unlock_irqrestore(&phba->scsi_buf_list_lock, iflag);
}
}
static void
lpfc_release_scsi_buf(struct lpfc_hba *phba, struct lpfc_scsi_buf *psb)
{
phba->lpfc_release_scsi_buf(phba, psb);
}
static int
lpfc_scsi_prep_dma_buf_s3(struct lpfc_hba *phba, struct lpfc_scsi_buf *lpfc_cmd)
{
struct scsi_cmnd *scsi_cmnd = lpfc_cmd->pCmd;
struct scatterlist *sgel = NULL;
struct fcp_cmnd *fcp_cmnd = lpfc_cmd->fcp_cmnd;
struct ulp_bde64 *bpl = lpfc_cmd->fcp_bpl;
struct lpfc_iocbq *iocbq = &lpfc_cmd->cur_iocbq;
IOCB_t *iocb_cmd = &lpfc_cmd->cur_iocbq.iocb;
struct ulp_bde64 *data_bde = iocb_cmd->unsli3.fcp_ext.dbde;
dma_addr_t physaddr;
uint32_t num_bde = 0;
int nseg, datadir = scsi_cmnd->sc_data_direction;
bpl += 2;
if (scsi_sg_count(scsi_cmnd)) {
nseg = dma_map_sg(&phba->pcidev->dev, scsi_sglist(scsi_cmnd),
scsi_sg_count(scsi_cmnd), datadir);
if (unlikely(!nseg))
return 1;
lpfc_cmd->seg_cnt = nseg;
if (lpfc_cmd->seg_cnt > phba->cfg_sg_seg_cnt) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9064 BLKGRD: %s: Too many sg segments from "
"dma_map_sg. Config %d, seg_cnt %d\n",
__func__, phba->cfg_sg_seg_cnt,
lpfc_cmd->seg_cnt);
scsi_dma_unmap(scsi_cmnd);
return 1;
}
scsi_for_each_sg(scsi_cmnd, sgel, nseg, num_bde) {
physaddr = sg_dma_address(sgel);
if (phba->sli_rev == 3 &&
!(phba->sli3_options & LPFC_SLI3_BG_ENABLED) &&
!(iocbq->iocb_flag & DSS_SECURITY_OP) &&
nseg <= LPFC_EXT_DATA_BDE_COUNT) {
data_bde->tus.f.bdeFlags = BUFF_TYPE_BDE_64;
data_bde->tus.f.bdeSize = sg_dma_len(sgel);
data_bde->addrLow = putPaddrLow(physaddr);
data_bde->addrHigh = putPaddrHigh(physaddr);
data_bde++;
} else {
bpl->tus.f.bdeFlags = BUFF_TYPE_BDE_64;
bpl->tus.f.bdeSize = sg_dma_len(sgel);
bpl->tus.w = le32_to_cpu(bpl->tus.w);
bpl->addrLow =
le32_to_cpu(putPaddrLow(physaddr));
bpl->addrHigh =
le32_to_cpu(putPaddrHigh(physaddr));
bpl++;
}
}
}
if (phba->sli_rev == 3 &&
!(phba->sli3_options & LPFC_SLI3_BG_ENABLED) &&
!(iocbq->iocb_flag & DSS_SECURITY_OP)) {
if (num_bde > LPFC_EXT_DATA_BDE_COUNT) {
physaddr = lpfc_cmd->dma_handle;
data_bde->tus.f.bdeFlags = BUFF_TYPE_BLP_64;
data_bde->tus.f.bdeSize = (num_bde *
sizeof(struct ulp_bde64));
physaddr += (sizeof(struct fcp_cmnd) +
sizeof(struct fcp_rsp) +
(2 * sizeof(struct ulp_bde64)));
data_bde->addrHigh = putPaddrHigh(physaddr);
data_bde->addrLow = putPaddrLow(physaddr);
iocb_cmd->unsli3.fcp_ext.ebde_count = 2;
} else {
iocb_cmd->unsli3.fcp_ext.ebde_count = (num_bde + 1);
}
} else {
iocb_cmd->un.fcpi64.bdl.bdeSize =
((num_bde + 2) * sizeof(struct ulp_bde64));
iocb_cmd->unsli3.fcp_ext.ebde_count = (num_bde + 1);
}
fcp_cmnd->fcpDl = cpu_to_be32(scsi_bufflen(scsi_cmnd));
iocb_cmd->un.fcpi.fcpi_parm = scsi_bufflen(scsi_cmnd);
return 0;
}
static int
lpfc_sc_to_bg_opcodes(struct lpfc_hba *phba, struct scsi_cmnd *sc,
uint8_t *txop, uint8_t *rxop)
{
uint8_t guard_type = scsi_host_get_guard(sc->device->host);
uint8_t ret = 0;
if (guard_type == SHOST_DIX_GUARD_IP) {
switch (scsi_get_prot_op(sc)) {
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_WRITE_STRIP:
*txop = BG_OP_IN_CSUM_OUT_NODIF;
*rxop = BG_OP_IN_NODIF_OUT_CSUM;
break;
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_WRITE_INSERT:
*txop = BG_OP_IN_NODIF_OUT_CRC;
*rxop = BG_OP_IN_CRC_OUT_NODIF;
break;
case SCSI_PROT_READ_PASS:
case SCSI_PROT_WRITE_PASS:
*txop = BG_OP_IN_CSUM_OUT_CRC;
*rxop = BG_OP_IN_CRC_OUT_CSUM;
break;
case SCSI_PROT_NORMAL:
default:
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9063 BLKGRD: Bad op/guard:%d/%d combination\n",
scsi_get_prot_op(sc), guard_type);
ret = 1;
break;
}
} else if (guard_type == SHOST_DIX_GUARD_CRC) {
switch (scsi_get_prot_op(sc)) {
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_WRITE_INSERT:
*txop = BG_OP_IN_NODIF_OUT_CRC;
*rxop = BG_OP_IN_CRC_OUT_NODIF;
break;
case SCSI_PROT_READ_PASS:
case SCSI_PROT_WRITE_PASS:
*txop = BG_OP_IN_CRC_OUT_CRC;
*rxop = BG_OP_IN_CRC_OUT_CRC;
break;
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_WRITE_STRIP:
case SCSI_PROT_NORMAL:
default:
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9075 BLKGRD: Bad op/guard:%d/%d combination\n",
scsi_get_prot_op(sc), guard_type);
ret = 1;
break;
}
} else {
BUG();
}
return ret;
}
static inline unsigned
lpfc_cmd_blksize(struct scsi_cmnd *sc)
{
return sc->device->sector_size;
}
static inline void
lpfc_get_cmd_dif_parms(struct scsi_cmnd *sc, uint16_t *apptagmask,
uint16_t *apptagval, uint32_t *reftag)
{
struct scsi_dif_tuple *spt;
unsigned char op = scsi_get_prot_op(sc);
unsigned int protcnt = scsi_prot_sg_count(sc);
static int cnt;
if (protcnt && (op == SCSI_PROT_WRITE_STRIP ||
op == SCSI_PROT_WRITE_PASS)) {
cnt++;
spt = page_address(sg_page(scsi_prot_sglist(sc))) +
scsi_prot_sglist(sc)[0].offset;
*apptagmask = 0;
*apptagval = 0;
*reftag = cpu_to_be32(spt->ref_tag);
} else {
*reftag = (uint32_t) (0xffffffff & scsi_get_lba(sc));
*apptagmask = 0;
*apptagval = 0;
}
}
static int
lpfc_bg_setup_bpl(struct lpfc_hba *phba, struct scsi_cmnd *sc,
struct ulp_bde64 *bpl, int datasegcnt)
{
struct scatterlist *sgde = NULL;
struct lpfc_pde5 *pde5 = NULL;
struct lpfc_pde6 *pde6 = NULL;
dma_addr_t physaddr;
int i = 0, num_bde = 0, status;
int datadir = sc->sc_data_direction;
unsigned blksize;
uint32_t reftag;
uint16_t apptagmask, apptagval;
uint8_t txop, rxop;
status = lpfc_sc_to_bg_opcodes(phba, sc, &txop, &rxop);
if (status)
goto out;
blksize = lpfc_cmd_blksize(sc);
lpfc_get_cmd_dif_parms(sc, &apptagmask, &apptagval, &reftag);
pde5 = (struct lpfc_pde5 *) bpl;
memset(pde5, 0, sizeof(struct lpfc_pde5));
bf_set(pde5_type, pde5, LPFC_PDE5_DESCRIPTOR);
pde5->reftag = reftag;
pde5->word0 = cpu_to_le32(pde5->word0);
pde5->reftag = cpu_to_le32(pde5->reftag);
num_bde++;
bpl++;
pde6 = (struct lpfc_pde6 *) bpl;
memset(pde6, 0, sizeof(struct lpfc_pde6));
bf_set(pde6_type, pde6, LPFC_PDE6_DESCRIPTOR);
bf_set(pde6_optx, pde6, txop);
bf_set(pde6_oprx, pde6, rxop);
if (datadir == DMA_FROM_DEVICE) {
bf_set(pde6_ce, pde6, 1);
bf_set(pde6_re, pde6, 1);
bf_set(pde6_ae, pde6, 1);
}
bf_set(pde6_ai, pde6, 1);
bf_set(pde6_apptagval, pde6, apptagval);
pde6->word0 = cpu_to_le32(pde6->word0);
pde6->word1 = cpu_to_le32(pde6->word1);
pde6->word2 = cpu_to_le32(pde6->word2);
num_bde++;
bpl++;
scsi_for_each_sg(sc, sgde, datasegcnt, i) {
physaddr = sg_dma_address(sgde);
bpl->addrLow = le32_to_cpu(putPaddrLow(physaddr));
bpl->addrHigh = le32_to_cpu(putPaddrHigh(physaddr));
bpl->tus.f.bdeSize = sg_dma_len(sgde);
if (datadir == DMA_TO_DEVICE)
bpl->tus.f.bdeFlags = BUFF_TYPE_BDE_64;
else
bpl->tus.f.bdeFlags = BUFF_TYPE_BDE_64I;
bpl->tus.w = le32_to_cpu(bpl->tus.w);
bpl++;
num_bde++;
}
out:
return num_bde;
}
static int
lpfc_bg_setup_bpl_prot(struct lpfc_hba *phba, struct scsi_cmnd *sc,
struct ulp_bde64 *bpl, int datacnt, int protcnt)
{
struct scatterlist *sgde = NULL;
struct scatterlist *sgpe = NULL;
struct lpfc_pde5 *pde5 = NULL;
struct lpfc_pde6 *pde6 = NULL;
struct lpfc_pde7 *pde7 = NULL;
dma_addr_t dataphysaddr, protphysaddr;
unsigned short curr_data = 0, curr_prot = 0;
unsigned int split_offset;
unsigned int protgroup_len, protgroup_offset = 0, protgroup_remainder;
unsigned int protgrp_blks, protgrp_bytes;
unsigned int remainder, subtotal;
int status;
int datadir = sc->sc_data_direction;
unsigned char pgdone = 0, alldone = 0;
unsigned blksize;
uint32_t reftag;
uint16_t apptagmask, apptagval;
uint8_t txop, rxop;
int num_bde = 0;
sgpe = scsi_prot_sglist(sc);
sgde = scsi_sglist(sc);
if (!sgpe || !sgde) {
lpfc_printf_log(phba, KERN_ERR, LOG_FCP,
"9020 Invalid s/g entry: data=0x%p prot=0x%p\n",
sgpe, sgde);
return 0;
}
status = lpfc_sc_to_bg_opcodes(phba, sc, &txop, &rxop);
if (status)
goto out;
blksize = lpfc_cmd_blksize(sc);
lpfc_get_cmd_dif_parms(sc, &apptagmask, &apptagval, &reftag);
split_offset = 0;
do {
pde5 = (struct lpfc_pde5 *) bpl;
memset(pde5, 0, sizeof(struct lpfc_pde5));
bf_set(pde5_type, pde5, LPFC_PDE5_DESCRIPTOR);
pde5->reftag = reftag;
pde5->word0 = cpu_to_le32(pde5->word0);
pde5->reftag = cpu_to_le32(pde5->reftag);
num_bde++;
bpl++;
pde6 = (struct lpfc_pde6 *) bpl;
memset(pde6, 0, sizeof(struct lpfc_pde6));
bf_set(pde6_type, pde6, LPFC_PDE6_DESCRIPTOR);
bf_set(pde6_optx, pde6, txop);
bf_set(pde6_oprx, pde6, rxop);
bf_set(pde6_ce, pde6, 1);
bf_set(pde6_re, pde6, 1);
bf_set(pde6_ae, pde6, 1);
bf_set(pde6_ai, pde6, 1);
bf_set(pde6_apptagval, pde6, apptagval);
pde6->word0 = cpu_to_le32(pde6->word0);
pde6->word1 = cpu_to_le32(pde6->word1);
pde6->word2 = cpu_to_le32(pde6->word2);
num_bde++;
bpl++;
protphysaddr = sg_dma_address(sgpe) + protgroup_offset;
protgroup_len = sg_dma_len(sgpe) - protgroup_offset;
BUG_ON(protgroup_len % 8);
pde7 = (struct lpfc_pde7 *) bpl;
memset(pde7, 0, sizeof(struct lpfc_pde7));
bf_set(pde7_type, pde7, LPFC_PDE7_DESCRIPTOR);
pde7->addrHigh = le32_to_cpu(putPaddrLow(protphysaddr));
pde7->addrLow = le32_to_cpu(putPaddrHigh(protphysaddr));
protgrp_blks = protgroup_len / 8;
protgrp_bytes = protgrp_blks * blksize;
if ((pde7->addrLow & 0xfff) + protgroup_len > 0x1000) {
protgroup_remainder = 0x1000 - (pde7->addrLow & 0xfff);
protgroup_offset += protgroup_remainder;
protgrp_blks = protgroup_remainder / 8;
protgrp_bytes = protgroup_remainder * blksize;
} else {
protgroup_offset = 0;
curr_prot++;
}
num_bde++;
pgdone = 0;
subtotal = 0;
while (!pgdone) {
if (!sgde) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9065 BLKGRD:%s Invalid data segment\n",
__func__);
return 0;
}
bpl++;
dataphysaddr = sg_dma_address(sgde) + split_offset;
bpl->addrLow = le32_to_cpu(putPaddrLow(dataphysaddr));
bpl->addrHigh = le32_to_cpu(putPaddrHigh(dataphysaddr));
remainder = sg_dma_len(sgde) - split_offset;
if ((subtotal + remainder) <= protgrp_bytes) {
bpl->tus.f.bdeSize = remainder;
split_offset = 0;
if ((subtotal + remainder) == protgrp_bytes)
pgdone = 1;
} else {
bpl->tus.f.bdeSize = protgrp_bytes - subtotal;
split_offset += bpl->tus.f.bdeSize;
}
subtotal += bpl->tus.f.bdeSize;
if (datadir == DMA_TO_DEVICE)
bpl->tus.f.bdeFlags = BUFF_TYPE_BDE_64;
else
bpl->tus.f.bdeFlags = BUFF_TYPE_BDE_64I;
bpl->tus.w = le32_to_cpu(bpl->tus.w);
num_bde++;
curr_data++;
if (split_offset)
break;
sgde = sg_next(sgde);
}
if (protgroup_offset) {
reftag += protgrp_blks;
bpl++;
continue;
}
if (curr_prot == protcnt) {
alldone = 1;
} else if (curr_prot < protcnt) {
sgpe = sg_next(sgpe);
bpl++;
reftag += protgrp_blks;
} else {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9054 BLKGRD: bug in %s\n", __func__);
}
} while (!alldone);
out:
return num_bde;
}
static int
lpfc_prot_group_type(struct lpfc_hba *phba, struct scsi_cmnd *sc)
{
int ret = LPFC_PG_TYPE_INVALID;
unsigned char op = scsi_get_prot_op(sc);
switch (op) {
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_WRITE_INSERT:
ret = LPFC_PG_TYPE_NO_DIF;
break;
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_WRITE_STRIP:
case SCSI_PROT_READ_PASS:
case SCSI_PROT_WRITE_PASS:
ret = LPFC_PG_TYPE_DIF_BUF;
break;
default:
lpfc_printf_log(phba, KERN_ERR, LOG_FCP,
"9021 Unsupported protection op:%d\n", op);
break;
}
return ret;
}
static int
lpfc_bg_scsi_prep_dma_buf(struct lpfc_hba *phba,
struct lpfc_scsi_buf *lpfc_cmd)
{
struct scsi_cmnd *scsi_cmnd = lpfc_cmd->pCmd;
struct fcp_cmnd *fcp_cmnd = lpfc_cmd->fcp_cmnd;
struct ulp_bde64 *bpl = lpfc_cmd->fcp_bpl;
IOCB_t *iocb_cmd = &lpfc_cmd->cur_iocbq.iocb;
uint32_t num_bde = 0;
int datasegcnt, protsegcnt, datadir = scsi_cmnd->sc_data_direction;
int prot_group_type = 0;
int diflen, fcpdl;
unsigned blksize;
bpl += 2;
if (scsi_sg_count(scsi_cmnd)) {
datasegcnt = dma_map_sg(&phba->pcidev->dev,
scsi_sglist(scsi_cmnd),
scsi_sg_count(scsi_cmnd), datadir);
if (unlikely(!datasegcnt))
return 1;
lpfc_cmd->seg_cnt = datasegcnt;
if (lpfc_cmd->seg_cnt > phba->cfg_sg_seg_cnt) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9067 BLKGRD: %s: Too many sg segments"
" from dma_map_sg. Config %d, seg_cnt"
" %d\n",
__func__, phba->cfg_sg_seg_cnt,
lpfc_cmd->seg_cnt);
scsi_dma_unmap(scsi_cmnd);
return 1;
}
prot_group_type = lpfc_prot_group_type(phba, scsi_cmnd);
switch (prot_group_type) {
case LPFC_PG_TYPE_NO_DIF:
num_bde = lpfc_bg_setup_bpl(phba, scsi_cmnd, bpl,
datasegcnt);
if (num_bde < 2)
goto err;
break;
case LPFC_PG_TYPE_DIF_BUF:{
protsegcnt = dma_map_sg(&phba->pcidev->dev,
scsi_prot_sglist(scsi_cmnd),
scsi_prot_sg_count(scsi_cmnd), datadir);
if (unlikely(!protsegcnt)) {
scsi_dma_unmap(scsi_cmnd);
return 1;
}
lpfc_cmd->prot_seg_cnt = protsegcnt;
if (lpfc_cmd->prot_seg_cnt
> phba->cfg_prot_sg_seg_cnt) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9068 BLKGRD: %s: Too many prot sg "
"segments from dma_map_sg. Config %d,"
"prot_seg_cnt %d\n", __func__,
phba->cfg_prot_sg_seg_cnt,
lpfc_cmd->prot_seg_cnt);
dma_unmap_sg(&phba->pcidev->dev,
scsi_prot_sglist(scsi_cmnd),
scsi_prot_sg_count(scsi_cmnd),
datadir);
scsi_dma_unmap(scsi_cmnd);
return 1;
}
num_bde = lpfc_bg_setup_bpl_prot(phba, scsi_cmnd, bpl,
datasegcnt, protsegcnt);
if (num_bde < 3)
goto err;
break;
}
case LPFC_PG_TYPE_INVALID:
default:
lpfc_printf_log(phba, KERN_ERR, LOG_FCP,
"9022 Unexpected protection group %i\n",
prot_group_type);
return 1;
}
}
iocb_cmd->un.fcpi64.bdl.bdeSize = (2 * sizeof(struct ulp_bde64));
iocb_cmd->un.fcpi64.bdl.bdeSize += (num_bde * sizeof(struct ulp_bde64));
iocb_cmd->ulpBdeCount = 1;
iocb_cmd->ulpLe = 1;
fcpdl = scsi_bufflen(scsi_cmnd);
if (scsi_get_prot_type(scsi_cmnd) == SCSI_PROT_DIF_TYPE1) {
blksize = lpfc_cmd_blksize(scsi_cmnd);
diflen = (fcpdl / blksize) * 8;
fcpdl += diflen;
}
fcp_cmnd->fcpDl = be32_to_cpu(fcpdl);
iocb_cmd->un.fcpi.fcpi_parm = fcpdl;
return 0;
err:
lpfc_printf_log(phba, KERN_ERR, LOG_FCP,
"9023 Could not setup all needed BDE's"
"prot_group_type=%d, num_bde=%d\n",
prot_group_type, num_bde);
return 1;
}
static int
lpfc_parse_bg_err(struct lpfc_hba *phba, struct lpfc_scsi_buf *lpfc_cmd,
struct lpfc_iocbq *pIocbOut)
{
struct scsi_cmnd *cmd = lpfc_cmd->pCmd;
struct sli3_bg_fields *bgf = &pIocbOut->iocb.unsli3.sli3_bg;
int ret = 0;
uint32_t bghm = bgf->bghm;
uint32_t bgstat = bgf->bgstat;
uint64_t failing_sector = 0;
lpfc_printf_log(phba, KERN_ERR, LOG_BG, "9069 BLKGRD: BG ERROR in cmd"
" 0x%x lba 0x%llx blk cnt 0x%x "
"bgstat=0x%x bghm=0x%x\n",
cmd->cmnd[0], (unsigned long long)scsi_get_lba(cmd),
blk_rq_sectors(cmd->request), bgstat, bghm);
spin_lock(&_dump_buf_lock);
if (!_dump_buf_done) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG, "9070 BLKGRD: Saving"
" Data for %u blocks to debugfs\n",
(cmd->cmnd[7] << 8 | cmd->cmnd[8]));
lpfc_debug_save_data(phba, cmd);
if (lpfc_prot_group_type(phba, cmd) ==
LPFC_PG_TYPE_DIF_BUF) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG, "9071 BLKGRD: "
"Saving DIF for %u blocks to debugfs\n",
(cmd->cmnd[7] << 8 | cmd->cmnd[8]));
lpfc_debug_save_dif(phba, cmd);
}
_dump_buf_done = 1;
}
spin_unlock(&_dump_buf_lock);
if (lpfc_bgs_get_invalid_prof(bgstat)) {
cmd->result = ScsiResult(DID_ERROR, 0);
lpfc_printf_log(phba, KERN_ERR, LOG_BG, "9072 BLKGRD: Invalid"
" BlockGuard profile. bgstat:0x%x\n",
bgstat);
ret = (-1);
goto out;
}
if (lpfc_bgs_get_uninit_dif_block(bgstat)) {
cmd->result = ScsiResult(DID_ERROR, 0);
lpfc_printf_log(phba, KERN_ERR, LOG_BG, "9073 BLKGRD: "
"Invalid BlockGuard DIF Block. bgstat:0x%x\n",
bgstat);
ret = (-1);
goto out;
}
if (lpfc_bgs_get_guard_err(bgstat)) {
ret = 1;
scsi_build_sense_buffer(1, cmd->sense_buffer, ILLEGAL_REQUEST,
0x10, 0x1);
cmd->result = DRIVER_SENSE << 24
| ScsiResult(DID_ABORT, SAM_STAT_CHECK_CONDITION);
phba->bg_guard_err_cnt++;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9055 BLKGRD: guard_tag error\n");
}
if (lpfc_bgs_get_reftag_err(bgstat)) {
ret = 1;
scsi_build_sense_buffer(1, cmd->sense_buffer, ILLEGAL_REQUEST,
0x10, 0x3);
cmd->result = DRIVER_SENSE << 24
| ScsiResult(DID_ABORT, SAM_STAT_CHECK_CONDITION);
phba->bg_reftag_err_cnt++;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9056 BLKGRD: ref_tag error\n");
}
if (lpfc_bgs_get_apptag_err(bgstat)) {
ret = 1;
scsi_build_sense_buffer(1, cmd->sense_buffer, ILLEGAL_REQUEST,
0x10, 0x2);
cmd->result = DRIVER_SENSE << 24
| ScsiResult(DID_ABORT, SAM_STAT_CHECK_CONDITION);
phba->bg_apptag_err_cnt++;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9061 BLKGRD: app_tag error\n");
}
if (lpfc_bgs_get_hi_water_mark_present(bgstat)) {
cmd->sense_buffer[8] = 0;
cmd->sense_buffer[9] = 0xa;
bghm /= cmd->device->sector_size;
failing_sector = scsi_get_lba(cmd);
failing_sector += bghm;
put_unaligned_be64(failing_sector, &cmd->sense_buffer[10]);
}
if (!ret) {
cmd->result = ScsiResult(DID_ERROR, 0);
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9057 BLKGRD: no errors reported!\n");
}
out:
return ret;
}
static int
lpfc_scsi_prep_dma_buf_s4(struct lpfc_hba *phba, struct lpfc_scsi_buf *lpfc_cmd)
{
struct scsi_cmnd *scsi_cmnd = lpfc_cmd->pCmd;
struct scatterlist *sgel = NULL;
struct fcp_cmnd *fcp_cmnd = lpfc_cmd->fcp_cmnd;
struct sli4_sge *sgl = (struct sli4_sge *)lpfc_cmd->fcp_bpl;
struct sli4_sge *first_data_sgl;
IOCB_t *iocb_cmd = &lpfc_cmd->cur_iocbq.iocb;
dma_addr_t physaddr;
uint32_t num_bde = 0;
uint32_t dma_len;
uint32_t dma_offset = 0;
int nseg;
struct ulp_bde64 *bde;
if (scsi_sg_count(scsi_cmnd)) {
nseg = scsi_dma_map(scsi_cmnd);
if (unlikely(!nseg))
return 1;
sgl += 1;
sgl->word2 = le32_to_cpu(sgl->word2);
bf_set(lpfc_sli4_sge_last, sgl, 0);
sgl->word2 = cpu_to_le32(sgl->word2);
sgl += 1;
first_data_sgl = sgl;
lpfc_cmd->seg_cnt = nseg;
if (lpfc_cmd->seg_cnt > phba->cfg_sg_seg_cnt) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG, "9074 BLKGRD:"
" %s: Too many sg segments from "
"dma_map_sg. Config %d, seg_cnt %d\n",
__func__, phba->cfg_sg_seg_cnt,
lpfc_cmd->seg_cnt);
scsi_dma_unmap(scsi_cmnd);
return 1;
}
scsi_for_each_sg(scsi_cmnd, sgel, nseg, num_bde) {
physaddr = sg_dma_address(sgel);
dma_len = sg_dma_len(sgel);
sgl->addr_lo = cpu_to_le32(putPaddrLow(physaddr));
sgl->addr_hi = cpu_to_le32(putPaddrHigh(physaddr));
sgl->word2 = le32_to_cpu(sgl->word2);
if ((num_bde + 1) == nseg)
bf_set(lpfc_sli4_sge_last, sgl, 1);
else
bf_set(lpfc_sli4_sge_last, sgl, 0);
bf_set(lpfc_sli4_sge_offset, sgl, dma_offset);
sgl->word2 = cpu_to_le32(sgl->word2);
sgl->sge_len = cpu_to_le32(dma_len);
dma_offset += dma_len;
sgl++;
}
if (phba->sli3_options & LPFC_SLI4_PERFH_ENABLED) {
bde = (struct ulp_bde64 *)
&(iocb_cmd->unsli3.sli3Words[5]);
bde->addrLow = first_data_sgl->addr_lo;
bde->addrHigh = first_data_sgl->addr_hi;
bde->tus.f.bdeSize =
le32_to_cpu(first_data_sgl->sge_len);
bde->tus.f.bdeFlags = BUFF_TYPE_BDE_64;
bde->tus.w = cpu_to_le32(bde->tus.w);
}
} else {
sgl += 1;
sgl->word2 = le32_to_cpu(sgl->word2);
bf_set(lpfc_sli4_sge_last, sgl, 1);
sgl->word2 = cpu_to_le32(sgl->word2);
}
fcp_cmnd->fcpDl = cpu_to_be32(scsi_bufflen(scsi_cmnd));
iocb_cmd->un.fcpi.fcpi_parm = scsi_bufflen(scsi_cmnd);
return 0;
}
static inline int
lpfc_scsi_prep_dma_buf(struct lpfc_hba *phba, struct lpfc_scsi_buf *lpfc_cmd)
{
return phba->lpfc_scsi_prep_dma_buf(phba, lpfc_cmd);
}
static void
lpfc_send_scsi_error_event(struct lpfc_hba *phba, struct lpfc_vport *vport,
struct lpfc_scsi_buf *lpfc_cmd, struct lpfc_iocbq *rsp_iocb) {
struct scsi_cmnd *cmnd = lpfc_cmd->pCmd;
struct fcp_rsp *fcprsp = lpfc_cmd->fcp_rsp;
uint32_t resp_info = fcprsp->rspStatus2;
uint32_t scsi_status = fcprsp->rspStatus3;
uint32_t fcpi_parm = rsp_iocb->iocb.un.fcpi.fcpi_parm;
struct lpfc_fast_path_event *fast_path_evt = NULL;
struct lpfc_nodelist *pnode = lpfc_cmd->rdata->pnode;
unsigned long flags;
if (!pnode || !NLP_CHK_NODE_ACT(pnode))
return;
if ((cmnd->result == SAM_STAT_TASK_SET_FULL) ||
(cmnd->result == SAM_STAT_BUSY)) {
fast_path_evt = lpfc_alloc_fast_evt(phba);
if (!fast_path_evt)
return;
fast_path_evt->un.scsi_evt.event_type =
FC_REG_SCSI_EVENT;
fast_path_evt->un.scsi_evt.subcategory =
(cmnd->result == SAM_STAT_TASK_SET_FULL) ?
LPFC_EVENT_QFULL : LPFC_EVENT_DEVBSY;
fast_path_evt->un.scsi_evt.lun = cmnd->device->lun;
memcpy(&fast_path_evt->un.scsi_evt.wwpn,
&pnode->nlp_portname, sizeof(struct lpfc_name));
memcpy(&fast_path_evt->un.scsi_evt.wwnn,
&pnode->nlp_nodename, sizeof(struct lpfc_name));
} else if ((resp_info & SNS_LEN_VALID) && fcprsp->rspSnsLen &&
((cmnd->cmnd[0] == READ_10) || (cmnd->cmnd[0] == WRITE_10))) {
fast_path_evt = lpfc_alloc_fast_evt(phba);
if (!fast_path_evt)
return;
fast_path_evt->un.check_cond_evt.scsi_event.event_type =
FC_REG_SCSI_EVENT;
fast_path_evt->un.check_cond_evt.scsi_event.subcategory =
LPFC_EVENT_CHECK_COND;
fast_path_evt->un.check_cond_evt.scsi_event.lun =
cmnd->device->lun;
memcpy(&fast_path_evt->un.check_cond_evt.scsi_event.wwpn,
&pnode->nlp_portname, sizeof(struct lpfc_name));
memcpy(&fast_path_evt->un.check_cond_evt.scsi_event.wwnn,
&pnode->nlp_nodename, sizeof(struct lpfc_name));
fast_path_evt->un.check_cond_evt.sense_key =
cmnd->sense_buffer[2] & 0xf;
fast_path_evt->un.check_cond_evt.asc = cmnd->sense_buffer[12];
fast_path_evt->un.check_cond_evt.ascq = cmnd->sense_buffer[13];
} else if ((cmnd->sc_data_direction == DMA_FROM_DEVICE) &&
fcpi_parm &&
((be32_to_cpu(fcprsp->rspResId) != fcpi_parm) ||
((scsi_status == SAM_STAT_GOOD) &&
!(resp_info & (RESID_UNDER | RESID_OVER))))) {
fast_path_evt = lpfc_alloc_fast_evt(phba);
if (!fast_path_evt)
return;
fast_path_evt->un.read_check_error.header.event_type =
FC_REG_FABRIC_EVENT;
fast_path_evt->un.read_check_error.header.subcategory =
LPFC_EVENT_FCPRDCHKERR;
memcpy(&fast_path_evt->un.read_check_error.header.wwpn,
&pnode->nlp_portname, sizeof(struct lpfc_name));
memcpy(&fast_path_evt->un.read_check_error.header.wwnn,
&pnode->nlp_nodename, sizeof(struct lpfc_name));
fast_path_evt->un.read_check_error.lun = cmnd->device->lun;
fast_path_evt->un.read_check_error.opcode = cmnd->cmnd[0];
fast_path_evt->un.read_check_error.fcpiparam =
fcpi_parm;
} else
return;
fast_path_evt->vport = vport;
spin_lock_irqsave(&phba->hbalock, flags);
list_add_tail(&fast_path_evt->work_evt.evt_listp, &phba->work_list);
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_worker_wake_up(phba);
return;
}
static void
lpfc_scsi_unprep_dma_buf(struct lpfc_hba *phba, struct lpfc_scsi_buf *psb)
{
if (psb->seg_cnt > 0)
scsi_dma_unmap(psb->pCmd);
if (psb->prot_seg_cnt > 0)
dma_unmap_sg(&phba->pcidev->dev, scsi_prot_sglist(psb->pCmd),
scsi_prot_sg_count(psb->pCmd),
psb->pCmd->sc_data_direction);
}
static void
lpfc_handle_fcp_err(struct lpfc_vport *vport, struct lpfc_scsi_buf *lpfc_cmd,
struct lpfc_iocbq *rsp_iocb)
{
struct scsi_cmnd *cmnd = lpfc_cmd->pCmd;
struct fcp_cmnd *fcpcmd = lpfc_cmd->fcp_cmnd;
struct fcp_rsp *fcprsp = lpfc_cmd->fcp_rsp;
uint32_t fcpi_parm = rsp_iocb->iocb.un.fcpi.fcpi_parm;
uint32_t resp_info = fcprsp->rspStatus2;
uint32_t scsi_status = fcprsp->rspStatus3;
uint32_t *lp;
uint32_t host_status = DID_OK;
uint32_t rsplen = 0;
uint32_t logit = LOG_FCP | LOG_FCP_ERROR;
if (fcpcmd->fcpCntl2) {
scsi_status = 0;
goto out;
}
if (resp_info & RSP_LEN_VALID) {
rsplen = be32_to_cpu(fcprsp->rspRspLen);
if (rsplen != 0 && rsplen != 4 && rsplen != 8) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"2719 Invalid response length: "
"tgt x%x lun x%x cmnd x%x rsplen x%x\n",
cmnd->device->id,
cmnd->device->lun, cmnd->cmnd[0],
rsplen);
host_status = DID_ERROR;
goto out;
}
if (fcprsp->rspInfo3 != RSP_NO_FAILURE) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"2757 Protocol failure detected during "
"processing of FCP I/O op: "
"tgt x%x lun x%x cmnd x%x rspInfo3 x%x\n",
cmnd->device->id,
cmnd->device->lun, cmnd->cmnd[0],
fcprsp->rspInfo3);
host_status = DID_ERROR;
goto out;
}
}
if ((resp_info & SNS_LEN_VALID) && fcprsp->rspSnsLen) {
uint32_t snslen = be32_to_cpu(fcprsp->rspSnsLen);
if (snslen > SCSI_SENSE_BUFFERSIZE)
snslen = SCSI_SENSE_BUFFERSIZE;
if (resp_info & RSP_LEN_VALID)
rsplen = be32_to_cpu(fcprsp->rspRspLen);
memcpy(cmnd->sense_buffer, &fcprsp->rspInfo0 + rsplen, snslen);
}
lp = (uint32_t *)cmnd->sense_buffer;
if (!scsi_status && (resp_info & RESID_UNDER))
logit = LOG_FCP;
lpfc_printf_vlog(vport, KERN_WARNING, logit,
"9024 FCP command x%x failed: x%x SNS x%x x%x "
"Data: x%x x%x x%x x%x x%x\n",
cmnd->cmnd[0], scsi_status,
be32_to_cpu(*lp), be32_to_cpu(*(lp + 3)), resp_info,
be32_to_cpu(fcprsp->rspResId),
be32_to_cpu(fcprsp->rspSnsLen),
be32_to_cpu(fcprsp->rspRspLen),
fcprsp->rspInfo3);
scsi_set_resid(cmnd, 0);
if (resp_info & RESID_UNDER) {
scsi_set_resid(cmnd, be32_to_cpu(fcprsp->rspResId));
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"9025 FCP Read Underrun, expected %d, "
"residual %d Data: x%x x%x x%x\n",
be32_to_cpu(fcpcmd->fcpDl),
scsi_get_resid(cmnd), fcpi_parm, cmnd->cmnd[0],
cmnd->underflow);
if ((cmnd->sc_data_direction == DMA_FROM_DEVICE) &&
fcpi_parm &&
(scsi_get_resid(cmnd) != fcpi_parm)) {
lpfc_printf_vlog(vport, KERN_WARNING,
LOG_FCP | LOG_FCP_ERROR,
"9026 FCP Read Check Error "
"and Underrun Data: x%x x%x x%x x%x\n",
be32_to_cpu(fcpcmd->fcpDl),
scsi_get_resid(cmnd), fcpi_parm,
cmnd->cmnd[0]);
scsi_set_resid(cmnd, scsi_bufflen(cmnd));
host_status = DID_ERROR;
}
if (!(resp_info & SNS_LEN_VALID) &&
(scsi_status == SAM_STAT_GOOD) &&
(scsi_bufflen(cmnd) - scsi_get_resid(cmnd)
< cmnd->underflow)) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"9027 FCP command x%x residual "
"underrun converted to error "
"Data: x%x x%x x%x\n",
cmnd->cmnd[0], scsi_bufflen(cmnd),
scsi_get_resid(cmnd), cmnd->underflow);
host_status = DID_ERROR;
}
} else if (resp_info & RESID_OVER) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"9028 FCP command x%x residual overrun error. "
"Data: x%x x%x\n", cmnd->cmnd[0],
scsi_bufflen(cmnd), scsi_get_resid(cmnd));
host_status = DID_ERROR;
} else if (fcpi_parm && (cmnd->sc_data_direction == DMA_FROM_DEVICE)) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP | LOG_FCP_ERROR,
"9029 FCP Read Check Error Data: "
"x%x x%x x%x x%x x%x\n",
be32_to_cpu(fcpcmd->fcpDl),
be32_to_cpu(fcprsp->rspResId),
fcpi_parm, cmnd->cmnd[0], scsi_status);
switch (scsi_status) {
case SAM_STAT_GOOD:
case SAM_STAT_CHECK_CONDITION:
host_status = DID_ERROR;
break;
}
scsi_set_resid(cmnd, scsi_bufflen(cmnd));
}
out:
cmnd->result = ScsiResult(host_status, scsi_status);
lpfc_send_scsi_error_event(vport->phba, vport, lpfc_cmd, rsp_iocb);
}
static void
lpfc_scsi_cmd_iocb_cmpl(struct lpfc_hba *phba, struct lpfc_iocbq *pIocbIn,
struct lpfc_iocbq *pIocbOut)
{
struct lpfc_scsi_buf *lpfc_cmd =
(struct lpfc_scsi_buf *) pIocbIn->context1;
struct lpfc_vport *vport = pIocbIn->vport;
struct lpfc_rport_data *rdata = lpfc_cmd->rdata;
struct lpfc_nodelist *pnode = rdata->pnode;
struct scsi_cmnd *cmd;
int result;
struct scsi_device *tmp_sdev;
int depth;
unsigned long flags;
struct lpfc_fast_path_event *fast_path_evt;
struct Scsi_Host *shost;
uint32_t queue_depth, scsi_id;
if (!(lpfc_cmd->pCmd))
return;
cmd = lpfc_cmd->pCmd;
shost = cmd->device->host;
lpfc_cmd->result = pIocbOut->iocb.un.ulpWord[4];
lpfc_cmd->status = pIocbOut->iocb.ulpStatus;
lpfc_cmd->exch_busy = pIocbOut->iocb_flag & LPFC_EXCHANGE_BUSY;
if (pnode && NLP_CHK_NODE_ACT(pnode))
atomic_dec(&pnode->cmd_pending);
if (lpfc_cmd->status) {
if (lpfc_cmd->status == IOSTAT_LOCAL_REJECT &&
(lpfc_cmd->result & IOERR_DRVR_MASK))
lpfc_cmd->status = IOSTAT_DRIVER_REJECT;
else if (lpfc_cmd->status >= IOSTAT_CNT)
lpfc_cmd->status = IOSTAT_DEFAULT;
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"9030 FCP cmd x%x failed <%d/%d> "
"status: x%x result: x%x Data: x%x x%x\n",
cmd->cmnd[0],
cmd->device ? cmd->device->id : 0xffff,
cmd->device ? cmd->device->lun : 0xffff,
lpfc_cmd->status, lpfc_cmd->result,
pIocbOut->iocb.ulpContext,
lpfc_cmd->cur_iocbq.iocb.ulpIoTag);
switch (lpfc_cmd->status) {
case IOSTAT_FCP_RSP_ERROR:
lpfc_handle_fcp_err(vport, lpfc_cmd, pIocbOut);
break;
case IOSTAT_NPORT_BSY:
case IOSTAT_FABRIC_BSY:
cmd->result = ScsiResult(DID_TRANSPORT_DISRUPTED, 0);
fast_path_evt = lpfc_alloc_fast_evt(phba);
if (!fast_path_evt)
break;
fast_path_evt->un.fabric_evt.event_type =
FC_REG_FABRIC_EVENT;
fast_path_evt->un.fabric_evt.subcategory =
(lpfc_cmd->status == IOSTAT_NPORT_BSY) ?
LPFC_EVENT_PORT_BUSY : LPFC_EVENT_FABRIC_BUSY;
if (pnode && NLP_CHK_NODE_ACT(pnode)) {
memcpy(&fast_path_evt->un.fabric_evt.wwpn,
&pnode->nlp_portname,
sizeof(struct lpfc_name));
memcpy(&fast_path_evt->un.fabric_evt.wwnn,
&pnode->nlp_nodename,
sizeof(struct lpfc_name));
}
fast_path_evt->vport = vport;
fast_path_evt->work_evt.evt =
LPFC_EVT_FASTPATH_MGMT_EVT;
spin_lock_irqsave(&phba->hbalock, flags);
list_add_tail(&fast_path_evt->work_evt.evt_listp,
&phba->work_list);
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_worker_wake_up(phba);
break;
case IOSTAT_LOCAL_REJECT:
case IOSTAT_REMOTE_STOP:
if (lpfc_cmd->result == IOERR_ELXSEC_KEY_UNWRAP_ERROR ||
lpfc_cmd->result ==
IOERR_ELXSEC_KEY_UNWRAP_COMPARE_ERROR ||
lpfc_cmd->result == IOERR_ELXSEC_CRYPTO_ERROR ||
lpfc_cmd->result ==
IOERR_ELXSEC_CRYPTO_COMPARE_ERROR) {
cmd->result = ScsiResult(DID_NO_CONNECT, 0);
break;
}
if (lpfc_cmd->result == IOERR_INVALID_RPI ||
lpfc_cmd->result == IOERR_NO_RESOURCES ||
lpfc_cmd->result == IOERR_ABORT_REQUESTED ||
lpfc_cmd->result == IOERR_SLER_CMD_RCV_FAILURE) {
cmd->result = ScsiResult(DID_REQUEUE, 0);
break;
}
if ((lpfc_cmd->result == IOERR_RX_DMA_FAILED ||
lpfc_cmd->result == IOERR_TX_DMA_FAILED) &&
pIocbOut->iocb.unsli3.sli3_bg.bgstat) {
if (scsi_get_prot_op(cmd) != SCSI_PROT_NORMAL) {
lpfc_parse_bg_err(phba, lpfc_cmd,
pIocbOut);
break;
} else {
lpfc_printf_vlog(vport, KERN_WARNING,
LOG_BG,
"9031 non-zero BGSTAT "
"on unprotected cmd\n");
}
}
if ((lpfc_cmd->status == IOSTAT_REMOTE_STOP)
&& (phba->sli_rev == LPFC_SLI_REV4)
&& (pnode && NLP_CHK_NODE_ACT(pnode))) {
lpfc_set_rrq_active(phba, pnode,
lpfc_cmd->cur_iocbq.sli4_xritag,
0, 0);
}
default:
cmd->result = ScsiResult(DID_ERROR, 0);
break;
}
if (!pnode || !NLP_CHK_NODE_ACT(pnode)
|| (pnode->nlp_state != NLP_STE_MAPPED_NODE))
cmd->result = ScsiResult(DID_TRANSPORT_DISRUPTED,
SAM_STAT_BUSY);
} else
cmd->result = ScsiResult(DID_OK, 0);
if (cmd->result || lpfc_cmd->fcp_rsp->rspSnsLen) {
uint32_t *lp = (uint32_t *)cmd->sense_buffer;
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"0710 Iodone <%d/%d> cmd %p, error "
"x%x SNS x%x x%x Data: x%x x%x\n",
cmd->device->id, cmd->device->lun, cmd,
cmd->result, *lp, *(lp + 3), cmd->retries,
scsi_get_resid(cmd));
}
lpfc_update_stats(phba, lpfc_cmd);
result = cmd->result;
if (vport->cfg_max_scsicmpl_time &&
time_after(jiffies, lpfc_cmd->start_time +
msecs_to_jiffies(vport->cfg_max_scsicmpl_time))) {
spin_lock_irqsave(shost->host_lock, flags);
if (pnode && NLP_CHK_NODE_ACT(pnode)) {
if (pnode->cmd_qdepth >
atomic_read(&pnode->cmd_pending) &&
(atomic_read(&pnode->cmd_pending) >
LPFC_MIN_TGT_QDEPTH) &&
((cmd->cmnd[0] == READ_10) ||
(cmd->cmnd[0] == WRITE_10)))
pnode->cmd_qdepth =
atomic_read(&pnode->cmd_pending);
pnode->last_change_time = jiffies;
}
spin_unlock_irqrestore(shost->host_lock, flags);
} else if (pnode && NLP_CHK_NODE_ACT(pnode)) {
if ((pnode->cmd_qdepth < vport->cfg_tgt_queue_depth) &&
time_after(jiffies, pnode->last_change_time +
msecs_to_jiffies(LPFC_TGTQ_INTERVAL))) {
spin_lock_irqsave(shost->host_lock, flags);
depth = pnode->cmd_qdepth * LPFC_TGTQ_RAMPUP_PCENT
/ 100;
depth = depth ? depth : 1;
pnode->cmd_qdepth += depth;
if (pnode->cmd_qdepth > vport->cfg_tgt_queue_depth)
pnode->cmd_qdepth = vport->cfg_tgt_queue_depth;
pnode->last_change_time = jiffies;
spin_unlock_irqrestore(shost->host_lock, flags);
}
}
lpfc_scsi_unprep_dma_buf(phba, lpfc_cmd);
queue_depth = cmd->device->queue_depth;
scsi_id = cmd->device->id;
cmd->scsi_done(cmd);
if (phba->cfg_poll & ENABLE_FCP_RING_POLLING) {
spin_lock_irqsave(shost->host_lock, flags);
lpfc_cmd->pCmd = NULL;
if (lpfc_cmd->waitq)
wake_up(lpfc_cmd->waitq);
spin_unlock_irqrestore(shost->host_lock, flags);
lpfc_release_scsi_buf(phba, lpfc_cmd);
return;
}
if (!result)
lpfc_rampup_queue_depth(vport, queue_depth);
if (result == SAM_STAT_TASK_SET_FULL && pnode &&
NLP_CHK_NODE_ACT(pnode)) {
shost_for_each_device(tmp_sdev, shost) {
if (tmp_sdev->id != scsi_id)
continue;
depth = scsi_track_queue_full(tmp_sdev,
tmp_sdev->queue_depth-1);
if (depth <= 0)
continue;
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"0711 detected queue full - lun queue "
"depth adjusted to %d.\n", depth);
lpfc_send_sdev_queuedepth_change_event(phba, vport,
pnode,
tmp_sdev->lun,
depth+1, depth);
}
}
spin_lock_irqsave(shost->host_lock, flags);
lpfc_cmd->pCmd = NULL;
if (lpfc_cmd->waitq)
wake_up(lpfc_cmd->waitq);
spin_unlock_irqrestore(shost->host_lock, flags);
lpfc_release_scsi_buf(phba, lpfc_cmd);
}
static void
lpfc_fcpcmd_to_iocb(uint8_t *data, struct fcp_cmnd *fcp_cmnd)
{
int i, j;
for (i = 0, j = 0; i < sizeof(struct fcp_cmnd);
i += sizeof(uint32_t), j++) {
((uint32_t *)data)[j] = cpu_to_be32(((uint32_t *)fcp_cmnd)[j]);
}
}
static void
lpfc_scsi_prep_cmnd(struct lpfc_vport *vport, struct lpfc_scsi_buf *lpfc_cmd,
struct lpfc_nodelist *pnode)
{
struct lpfc_hba *phba = vport->phba;
struct scsi_cmnd *scsi_cmnd = lpfc_cmd->pCmd;
struct fcp_cmnd *fcp_cmnd = lpfc_cmd->fcp_cmnd;
IOCB_t *iocb_cmd = &lpfc_cmd->cur_iocbq.iocb;
struct lpfc_iocbq *piocbq = &(lpfc_cmd->cur_iocbq);
int datadir = scsi_cmnd->sc_data_direction;
char tag[2];
if (!pnode || !NLP_CHK_NODE_ACT(pnode))
return;
lpfc_cmd->fcp_rsp->rspSnsLen = 0;
lpfc_cmd->fcp_cmnd->fcpCntl2 = 0;
int_to_scsilun(lpfc_cmd->pCmd->device->lun,
&lpfc_cmd->fcp_cmnd->fcp_lun);
memcpy(&fcp_cmnd->fcpCdb[0], scsi_cmnd->cmnd, 16);
if (scsi_populate_tag_msg(scsi_cmnd, tag)) {
switch (tag[0]) {
case HEAD_OF_QUEUE_TAG:
fcp_cmnd->fcpCntl1 = HEAD_OF_Q;
break;
case ORDERED_QUEUE_TAG:
fcp_cmnd->fcpCntl1 = ORDERED_Q;
break;
default:
fcp_cmnd->fcpCntl1 = SIMPLE_Q;
break;
}
} else
fcp_cmnd->fcpCntl1 = 0;
if (scsi_sg_count(scsi_cmnd)) {
if (datadir == DMA_TO_DEVICE) {
iocb_cmd->ulpCommand = CMD_FCP_IWRITE64_CR;
if (phba->sli_rev < LPFC_SLI_REV4) {
iocb_cmd->un.fcpi.fcpi_parm = 0;
iocb_cmd->ulpPU = 0;
} else
iocb_cmd->ulpPU = PARM_READ_CHECK;
fcp_cmnd->fcpCntl3 = WRITE_DATA;
phba->fc4OutputRequests++;
} else {
iocb_cmd->ulpCommand = CMD_FCP_IREAD64_CR;
iocb_cmd->ulpPU = PARM_READ_CHECK;
fcp_cmnd->fcpCntl3 = READ_DATA;
phba->fc4InputRequests++;
}
} else {
iocb_cmd->ulpCommand = CMD_FCP_ICMND64_CR;
iocb_cmd->un.fcpi.fcpi_parm = 0;
iocb_cmd->ulpPU = 0;
fcp_cmnd->fcpCntl3 = 0;
phba->fc4ControlRequests++;
}
if (phba->sli_rev == 3 &&
!(phba->sli3_options & LPFC_SLI3_BG_ENABLED))
lpfc_fcpcmd_to_iocb(iocb_cmd->unsli3.fcp_ext.icd, fcp_cmnd);
piocbq->iocb.ulpContext = pnode->nlp_rpi;
if (phba->sli_rev == LPFC_SLI_REV4)
piocbq->iocb.ulpContext =
phba->sli4_hba.rpi_ids[pnode->nlp_rpi];
if (pnode->nlp_fcp_info & NLP_FCP_2_DEVICE)
piocbq->iocb.ulpFCP2Rcvy = 1;
else
piocbq->iocb.ulpFCP2Rcvy = 0;
piocbq->iocb.ulpClass = (pnode->nlp_fcp_info & 0x0f);
piocbq->context1 = lpfc_cmd;
piocbq->iocb_cmpl = lpfc_scsi_cmd_iocb_cmpl;
piocbq->iocb.ulpTimeout = lpfc_cmd->timeout;
piocbq->vport = vport;
}
static int
lpfc_scsi_prep_task_mgmt_cmd(struct lpfc_vport *vport,
struct lpfc_scsi_buf *lpfc_cmd,
unsigned int lun,
uint8_t task_mgmt_cmd)
{
struct lpfc_iocbq *piocbq;
IOCB_t *piocb;
struct fcp_cmnd *fcp_cmnd;
struct lpfc_rport_data *rdata = lpfc_cmd->rdata;
struct lpfc_nodelist *ndlp = rdata->pnode;
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp) ||
ndlp->nlp_state != NLP_STE_MAPPED_NODE)
return 0;
piocbq = &(lpfc_cmd->cur_iocbq);
piocbq->vport = vport;
piocb = &piocbq->iocb;
fcp_cmnd = lpfc_cmd->fcp_cmnd;
memset(fcp_cmnd, 0, sizeof(struct fcp_cmnd));
int_to_scsilun(lun, &fcp_cmnd->fcp_lun);
fcp_cmnd->fcpCntl2 = task_mgmt_cmd;
if (vport->phba->sli_rev == 3 &&
!(vport->phba->sli3_options & LPFC_SLI3_BG_ENABLED))
lpfc_fcpcmd_to_iocb(piocb->unsli3.fcp_ext.icd, fcp_cmnd);
piocb->ulpCommand = CMD_FCP_ICMND64_CR;
piocb->ulpContext = ndlp->nlp_rpi;
if (vport->phba->sli_rev == LPFC_SLI_REV4) {
piocb->ulpContext =
vport->phba->sli4_hba.rpi_ids[ndlp->nlp_rpi];
}
if (ndlp->nlp_fcp_info & NLP_FCP_2_DEVICE) {
piocb->ulpFCP2Rcvy = 1;
}
piocb->ulpClass = (ndlp->nlp_fcp_info & 0x0f);
if (lpfc_cmd->timeout > 0xff) {
piocb->ulpTimeout = 0;
} else
piocb->ulpTimeout = lpfc_cmd->timeout;
if (vport->phba->sli_rev == LPFC_SLI_REV4)
lpfc_sli4_set_rsp_sgl_last(vport->phba, lpfc_cmd);
return 1;
}
int
lpfc_scsi_api_table_setup(struct lpfc_hba *phba, uint8_t dev_grp)
{
phba->lpfc_scsi_unprep_dma_buf = lpfc_scsi_unprep_dma_buf;
phba->lpfc_scsi_prep_cmnd = lpfc_scsi_prep_cmnd;
switch (dev_grp) {
case LPFC_PCI_DEV_LP:
phba->lpfc_new_scsi_buf = lpfc_new_scsi_buf_s3;
phba->lpfc_scsi_prep_dma_buf = lpfc_scsi_prep_dma_buf_s3;
phba->lpfc_release_scsi_buf = lpfc_release_scsi_buf_s3;
phba->lpfc_get_scsi_buf = lpfc_get_scsi_buf_s3;
break;
case LPFC_PCI_DEV_OC:
phba->lpfc_new_scsi_buf = lpfc_new_scsi_buf_s4;
phba->lpfc_scsi_prep_dma_buf = lpfc_scsi_prep_dma_buf_s4;
phba->lpfc_release_scsi_buf = lpfc_release_scsi_buf_s4;
phba->lpfc_get_scsi_buf = lpfc_get_scsi_buf_s4;
break;
default:
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"1418 Invalid HBA PCI-device group: 0x%x\n",
dev_grp);
return -ENODEV;
break;
}
phba->lpfc_rampdown_queue_depth = lpfc_rampdown_queue_depth;
phba->lpfc_scsi_cmd_iocb_cmpl = lpfc_scsi_cmd_iocb_cmpl;
return 0;
}
static void
lpfc_tskmgmt_def_cmpl(struct lpfc_hba *phba,
struct lpfc_iocbq *cmdiocbq,
struct lpfc_iocbq *rspiocbq)
{
struct lpfc_scsi_buf *lpfc_cmd =
(struct lpfc_scsi_buf *) cmdiocbq->context1;
if (lpfc_cmd)
lpfc_release_scsi_buf(phba, lpfc_cmd);
return;
}
const char *
lpfc_info(struct Scsi_Host *host)
{
struct lpfc_vport *vport = (struct lpfc_vport *) host->hostdata;
struct lpfc_hba *phba = vport->phba;
int len;
static char lpfcinfobuf[384];
memset(lpfcinfobuf,0,384);
if (phba && phba->pcidev){
strncpy(lpfcinfobuf, phba->ModelDesc, 256);
len = strlen(lpfcinfobuf);
snprintf(lpfcinfobuf + len,
384-len,
" on PCI bus %02x device %02x irq %d",
phba->pcidev->bus->number,
phba->pcidev->devfn,
phba->pcidev->irq);
len = strlen(lpfcinfobuf);
if (phba->Port[0]) {
snprintf(lpfcinfobuf + len,
384-len,
" port %s",
phba->Port);
}
len = strlen(lpfcinfobuf);
if (phba->sli4_hba.link_state.logical_speed) {
snprintf(lpfcinfobuf + len,
384-len,
" Logical Link Speed: %d Mbps",
phba->sli4_hba.link_state.logical_speed * 10);
}
}
return lpfcinfobuf;
}
static __inline__ void lpfc_poll_rearm_timer(struct lpfc_hba * phba)
{
unsigned long poll_tmo_expires =
(jiffies + msecs_to_jiffies(phba->cfg_poll_tmo));
if (phba->sli.ring[LPFC_FCP_RING].txcmplq_cnt)
mod_timer(&phba->fcp_poll_timer,
poll_tmo_expires);
}
void lpfc_poll_start_timer(struct lpfc_hba * phba)
{
lpfc_poll_rearm_timer(phba);
}
void lpfc_poll_timeout(unsigned long ptr)
{
struct lpfc_hba *phba = (struct lpfc_hba *) ptr;
if (phba->cfg_poll & ENABLE_FCP_RING_POLLING) {
lpfc_sli_handle_fast_ring_event(phba,
&phba->sli.ring[LPFC_FCP_RING], HA_R0RE_REQ);
if (phba->cfg_poll & DISABLE_FCP_RING_INT)
lpfc_poll_rearm_timer(phba);
}
}
static int
lpfc_queuecommand_lck(struct scsi_cmnd *cmnd, void (*done) (struct scsi_cmnd *))
{
struct Scsi_Host *shost = cmnd->device->host;
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
struct lpfc_rport_data *rdata = cmnd->device->hostdata;
struct lpfc_nodelist *ndlp;
struct lpfc_scsi_buf *lpfc_cmd;
struct fc_rport *rport = starget_to_rport(scsi_target(cmnd->device));
int err;
err = fc_remote_port_chkready(rport);
if (err) {
cmnd->result = err;
goto out_fail_command;
}
ndlp = rdata->pnode;
if (!(phba->sli3_options & LPFC_SLI3_BG_ENABLED) &&
scsi_get_prot_op(cmnd) != SCSI_PROT_NORMAL) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9058 BLKGRD: ERROR: rcvd protected cmd:%02x"
" op:%02x str=%s without registering for"
" BlockGuard - Rejecting command\n",
cmnd->cmnd[0], scsi_get_prot_op(cmnd),
dif_op_str[scsi_get_prot_op(cmnd)]);
goto out_fail_command;
}
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp)) {
cmnd->result = ScsiResult(DID_IMM_RETRY, 0);
goto out_fail_command;
}
if (atomic_read(&ndlp->cmd_pending) >= ndlp->cmd_qdepth)
goto out_tgt_busy;
lpfc_cmd = lpfc_get_scsi_buf(phba, ndlp);
if (lpfc_cmd == NULL) {
lpfc_rampdown_queue_depth(phba);
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"0707 driver's buffer pool is empty, "
"IO busied\n");
goto out_host_busy;
}
lpfc_cmd->pCmd = cmnd;
lpfc_cmd->rdata = rdata;
lpfc_cmd->timeout = 0;
lpfc_cmd->start_time = jiffies;
cmnd->host_scribble = (unsigned char *)lpfc_cmd;
cmnd->scsi_done = done;
if (scsi_get_prot_op(cmnd) != SCSI_PROT_NORMAL) {
if (vport->phba->cfg_enable_bg) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_BG,
"9033 BLKGRD: rcvd protected cmd:%02x op:%02x "
"str=%s\n",
cmnd->cmnd[0], scsi_get_prot_op(cmnd),
dif_op_str[scsi_get_prot_op(cmnd)]);
lpfc_printf_vlog(vport, KERN_WARNING, LOG_BG,
"9034 BLKGRD: CDB: %02x %02x %02x %02x %02x "
"%02x %02x %02x %02x %02x\n",
cmnd->cmnd[0], cmnd->cmnd[1], cmnd->cmnd[2],
cmnd->cmnd[3], cmnd->cmnd[4], cmnd->cmnd[5],
cmnd->cmnd[6], cmnd->cmnd[7], cmnd->cmnd[8],
cmnd->cmnd[9]);
if (cmnd->cmnd[0] == READ_10)
lpfc_printf_vlog(vport, KERN_WARNING, LOG_BG,
"9035 BLKGRD: READ @ sector %llu, "
"count %u\n",
(unsigned long long)scsi_get_lba(cmnd),
blk_rq_sectors(cmnd->request));
else if (cmnd->cmnd[0] == WRITE_10)
lpfc_printf_vlog(vport, KERN_WARNING, LOG_BG,
"9036 BLKGRD: WRITE @ sector %llu, "
"count %u cmd=%p\n",
(unsigned long long)scsi_get_lba(cmnd),
blk_rq_sectors(cmnd->request),
cmnd);
}
err = lpfc_bg_scsi_prep_dma_buf(phba, lpfc_cmd);
} else {
if (vport->phba->cfg_enable_bg) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_BG,
"9038 BLKGRD: rcvd unprotected cmd:"
"%02x op:%02x str=%s\n",
cmnd->cmnd[0], scsi_get_prot_op(cmnd),
dif_op_str[scsi_get_prot_op(cmnd)]);
lpfc_printf_vlog(vport, KERN_WARNING, LOG_BG,
"9039 BLKGRD: CDB: %02x %02x %02x "
"%02x %02x %02x %02x %02x %02x %02x\n",
cmnd->cmnd[0], cmnd->cmnd[1],
cmnd->cmnd[2], cmnd->cmnd[3],
cmnd->cmnd[4], cmnd->cmnd[5],
cmnd->cmnd[6], cmnd->cmnd[7],
cmnd->cmnd[8], cmnd->cmnd[9]);
if (cmnd->cmnd[0] == READ_10)
lpfc_printf_vlog(vport, KERN_WARNING, LOG_BG,
"9040 dbg: READ @ sector %llu, "
"count %u\n",
(unsigned long long)scsi_get_lba(cmnd),
blk_rq_sectors(cmnd->request));
else if (cmnd->cmnd[0] == WRITE_10)
lpfc_printf_vlog(vport, KERN_WARNING, LOG_BG,
"9041 dbg: WRITE @ sector %llu, "
"count %u cmd=%p\n",
(unsigned long long)scsi_get_lba(cmnd),
blk_rq_sectors(cmnd->request), cmnd);
else
lpfc_printf_vlog(vport, KERN_WARNING, LOG_BG,
"9042 dbg: parser not implemented\n");
}
err = lpfc_scsi_prep_dma_buf(phba, lpfc_cmd);
}
if (err)
goto out_host_busy_free_buf;
lpfc_scsi_prep_cmnd(vport, lpfc_cmd, ndlp);
atomic_inc(&ndlp->cmd_pending);
err = lpfc_sli_issue_iocb(phba, LPFC_FCP_RING,
&lpfc_cmd->cur_iocbq, SLI_IOCB_RET_IOCB);
if (err) {
atomic_dec(&ndlp->cmd_pending);
goto out_host_busy_free_buf;
}
if (phba->cfg_poll & ENABLE_FCP_RING_POLLING) {
spin_unlock(shost->host_lock);
lpfc_sli_handle_fast_ring_event(phba,
&phba->sli.ring[LPFC_FCP_RING], HA_R0RE_REQ);
spin_lock(shost->host_lock);
if (phba->cfg_poll & DISABLE_FCP_RING_INT)
lpfc_poll_rearm_timer(phba);
}
return 0;
out_host_busy_free_buf:
lpfc_scsi_unprep_dma_buf(phba, lpfc_cmd);
lpfc_release_scsi_buf(phba, lpfc_cmd);
out_host_busy:
return SCSI_MLQUEUE_HOST_BUSY;
out_tgt_busy:
return SCSI_MLQUEUE_TARGET_BUSY;
out_fail_command:
done(cmnd);
return 0;
}
char *
lpfc_taskmgmt_name(uint8_t task_mgmt_cmd)
{
switch (task_mgmt_cmd) {
case FCP_ABORT_TASK_SET:
return "ABORT_TASK_SET";
case FCP_CLEAR_TASK_SET:
return "FCP_CLEAR_TASK_SET";
case FCP_BUS_RESET:
return "FCP_BUS_RESET";
case FCP_LUN_RESET:
return "FCP_LUN_RESET";
case FCP_TARGET_RESET:
return "FCP_TARGET_RESET";
case FCP_CLEAR_ACA:
return "FCP_CLEAR_ACA";
case FCP_TERMINATE_TASK:
return "FCP_TERMINATE_TASK";
default:
return "unknown";
}
}
static int
lpfc_send_taskmgmt(struct lpfc_vport *vport, struct lpfc_rport_data *rdata,
unsigned tgt_id, unsigned int lun_id,
uint8_t task_mgmt_cmd)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_scsi_buf *lpfc_cmd;
struct lpfc_iocbq *iocbq;
struct lpfc_iocbq *iocbqrsp;
struct lpfc_nodelist *pnode = rdata->pnode;
int ret;
int status;
if (!pnode || !NLP_CHK_NODE_ACT(pnode))
return FAILED;
lpfc_cmd = lpfc_get_scsi_buf(phba, rdata->pnode);
if (lpfc_cmd == NULL)
return FAILED;
lpfc_cmd->timeout = 60;
lpfc_cmd->rdata = rdata;
status = lpfc_scsi_prep_task_mgmt_cmd(vport, lpfc_cmd, lun_id,
task_mgmt_cmd);
if (!status) {
lpfc_release_scsi_buf(phba, lpfc_cmd);
return FAILED;
}
iocbq = &lpfc_cmd->cur_iocbq;
iocbqrsp = lpfc_sli_get_iocbq(phba);
if (iocbqrsp == NULL) {
lpfc_release_scsi_buf(phba, lpfc_cmd);
return FAILED;
}
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"0702 Issue %s to TGT %d LUN %d "
"rpi x%x nlp_flag x%x Data: x%x x%x\n",
lpfc_taskmgmt_name(task_mgmt_cmd), tgt_id, lun_id,
pnode->nlp_rpi, pnode->nlp_flag, iocbq->sli4_xritag,
iocbq->iocb_flag);
status = lpfc_sli_issue_iocb_wait(phba, LPFC_FCP_RING,
iocbq, iocbqrsp, lpfc_cmd->timeout);
if (status != IOCB_SUCCESS) {
if (status == IOCB_TIMEDOUT) {
iocbq->iocb_cmpl = lpfc_tskmgmt_def_cmpl;
ret = TIMEOUT_ERROR;
} else
ret = FAILED;
lpfc_cmd->status = IOSTAT_DRIVER_REJECT;
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0727 TMF %s to TGT %d LUN %d failed (%d, %d) "
"iocb_flag x%x\n",
lpfc_taskmgmt_name(task_mgmt_cmd),
tgt_id, lun_id, iocbqrsp->iocb.ulpStatus,
iocbqrsp->iocb.un.ulpWord[4],
iocbq->iocb_flag);
} else if (status == IOCB_BUSY)
ret = FAILED;
else
ret = SUCCESS;
lpfc_sli_release_iocbq(phba, iocbqrsp);
if (ret != TIMEOUT_ERROR)
lpfc_release_scsi_buf(phba, lpfc_cmd);
return ret;
}
static int
lpfc_chk_tgt_mapped(struct lpfc_vport *vport, struct scsi_cmnd *cmnd)
{
struct lpfc_rport_data *rdata = cmnd->device->hostdata;
struct lpfc_nodelist *pnode;
unsigned long later;
if (!rdata) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"0797 Tgt Map rport failure: rdata x%p\n", rdata);
return FAILED;
}
pnode = rdata->pnode;
later = msecs_to_jiffies(2 * vport->cfg_devloss_tmo * 1000) + jiffies;
while (time_after(later, jiffies)) {
if (!pnode || !NLP_CHK_NODE_ACT(pnode))
return FAILED;
if (pnode->nlp_state == NLP_STE_MAPPED_NODE)
return SUCCESS;
schedule_timeout_uninterruptible(msecs_to_jiffies(500));
rdata = cmnd->device->hostdata;
if (!rdata)
return FAILED;
pnode = rdata->pnode;
}
if (!pnode || !NLP_CHK_NODE_ACT(pnode) ||
(pnode->nlp_state != NLP_STE_MAPPED_NODE))
return FAILED;
return SUCCESS;
}
static int
lpfc_reset_flush_io_context(struct lpfc_vport *vport, uint16_t tgt_id,
uint64_t lun_id, lpfc_ctx_cmd context)
{
struct lpfc_hba *phba = vport->phba;
unsigned long later;
int cnt;
cnt = lpfc_sli_sum_iocb(vport, tgt_id, lun_id, context);
if (cnt)
lpfc_sli_abort_iocb(vport, &phba->sli.ring[phba->sli.fcp_ring],
tgt_id, lun_id, context);
later = msecs_to_jiffies(2 * vport->cfg_devloss_tmo * 1000) + jiffies;
while (time_after(later, jiffies) && cnt) {
schedule_timeout_uninterruptible(msecs_to_jiffies(20));
cnt = lpfc_sli_sum_iocb(vport, tgt_id, lun_id, context);
}
if (cnt) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0724 I/O flush failure for context %s : cnt x%x\n",
((context == LPFC_CTX_LUN) ? "LUN" :
((context == LPFC_CTX_TGT) ? "TGT" :
((context == LPFC_CTX_HOST) ? "HOST" : "Unknown"))),
cnt);
return FAILED;
}
return SUCCESS;
}
static int
lpfc_device_reset_handler(struct scsi_cmnd *cmnd)
{
struct Scsi_Host *shost = cmnd->device->host;
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_rport_data *rdata = cmnd->device->hostdata;
struct lpfc_nodelist *pnode;
unsigned tgt_id = cmnd->device->id;
unsigned int lun_id = cmnd->device->lun;
struct lpfc_scsi_event_header scsi_event;
int status;
if (!rdata) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0798 Device Reset rport failure: rdata x%p\n", rdata);
return FAILED;
}
pnode = rdata->pnode;
status = fc_block_scsi_eh(cmnd);
if (status)
return status;
status = lpfc_chk_tgt_mapped(vport, cmnd);
if (status == FAILED) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0721 Device Reset rport failure: rdata x%p\n", rdata);
return FAILED;
}
scsi_event.event_type = FC_REG_SCSI_EVENT;
scsi_event.subcategory = LPFC_EVENT_LUNRESET;
scsi_event.lun = lun_id;
memcpy(scsi_event.wwpn, &pnode->nlp_portname, sizeof(struct lpfc_name));
memcpy(scsi_event.wwnn, &pnode->nlp_nodename, sizeof(struct lpfc_name));
fc_host_post_vendor_event(shost, fc_get_event_number(),
sizeof(scsi_event), (char *)&scsi_event, LPFC_NL_VENDOR_ID);
status = lpfc_send_taskmgmt(vport, rdata, tgt_id, lun_id,
FCP_LUN_RESET);
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0713 SCSI layer issued Device Reset (%d, %d) "
"return x%x\n", tgt_id, lun_id, status);
status = lpfc_reset_flush_io_context(vport, tgt_id, lun_id,
LPFC_CTX_LUN);
return status;
}
static int
lpfc_target_reset_handler(struct scsi_cmnd *cmnd)
{
struct Scsi_Host *shost = cmnd->device->host;
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_rport_data *rdata = cmnd->device->hostdata;
struct lpfc_nodelist *pnode;
unsigned tgt_id = cmnd->device->id;
unsigned int lun_id = cmnd->device->lun;
struct lpfc_scsi_event_header scsi_event;
int status;
if (!rdata) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0799 Target Reset rport failure: rdata x%p\n", rdata);
return FAILED;
}
pnode = rdata->pnode;
status = fc_block_scsi_eh(cmnd);
if (status)
return status;
status = lpfc_chk_tgt_mapped(vport, cmnd);
if (status == FAILED) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0722 Target Reset rport failure: rdata x%p\n", rdata);
return FAILED;
}
scsi_event.event_type = FC_REG_SCSI_EVENT;
scsi_event.subcategory = LPFC_EVENT_TGTRESET;
scsi_event.lun = 0;
memcpy(scsi_event.wwpn, &pnode->nlp_portname, sizeof(struct lpfc_name));
memcpy(scsi_event.wwnn, &pnode->nlp_nodename, sizeof(struct lpfc_name));
fc_host_post_vendor_event(shost, fc_get_event_number(),
sizeof(scsi_event), (char *)&scsi_event, LPFC_NL_VENDOR_ID);
status = lpfc_send_taskmgmt(vport, rdata, tgt_id, lun_id,
FCP_TARGET_RESET);
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0723 SCSI layer issued Target Reset (%d, %d) "
"return x%x\n", tgt_id, lun_id, status);
status = lpfc_reset_flush_io_context(vport, tgt_id, lun_id,
LPFC_CTX_TGT);
return status;
}
static int
lpfc_bus_reset_handler(struct scsi_cmnd *cmnd)
{
struct Scsi_Host *shost = cmnd->device->host;
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_nodelist *ndlp = NULL;
struct lpfc_scsi_event_header scsi_event;
int match;
int ret = SUCCESS, status, i;
scsi_event.event_type = FC_REG_SCSI_EVENT;
scsi_event.subcategory = LPFC_EVENT_BUSRESET;
scsi_event.lun = 0;
memcpy(scsi_event.wwpn, &vport->fc_portname, sizeof(struct lpfc_name));
memcpy(scsi_event.wwnn, &vport->fc_nodename, sizeof(struct lpfc_name));
fc_host_post_vendor_event(shost, fc_get_event_number(),
sizeof(scsi_event), (char *)&scsi_event, LPFC_NL_VENDOR_ID);
ret = fc_block_scsi_eh(cmnd);
if (ret)
return ret;
for (i = 0; i < LPFC_MAX_TARGET; i++) {
match = 0;
spin_lock_irq(shost->host_lock);
list_for_each_entry(ndlp, &vport->fc_nodes, nlp_listp) {
if (!NLP_CHK_NODE_ACT(ndlp))
continue;
if (ndlp->nlp_state == NLP_STE_MAPPED_NODE &&
ndlp->nlp_sid == i &&
ndlp->rport) {
match = 1;
break;
}
}
spin_unlock_irq(shost->host_lock);
if (!match)
continue;
status = lpfc_send_taskmgmt(vport, ndlp->rport->dd_data,
i, 0, FCP_TARGET_RESET);
if (status != SUCCESS) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0700 Bus Reset on target %d failed\n",
i);
ret = FAILED;
}
}
status = lpfc_reset_flush_io_context(vport, 0, 0, LPFC_CTX_HOST);
if (status != SUCCESS)
ret = FAILED;
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0714 SCSI layer issued Bus Reset Data: x%x\n", ret);
return ret;
}
static int
lpfc_slave_alloc(struct scsi_device *sdev)
{
struct lpfc_vport *vport = (struct lpfc_vport *) sdev->host->hostdata;
struct lpfc_hba *phba = vport->phba;
struct fc_rport *rport = starget_to_rport(scsi_target(sdev));
uint32_t total = 0;
uint32_t num_to_alloc = 0;
int num_allocated = 0;
uint32_t sdev_cnt;
if (!rport || fc_remote_port_chkready(rport))
return -ENXIO;
sdev->hostdata = rport->dd_data;
sdev_cnt = atomic_inc_return(&phba->sdev_cnt);
total = phba->total_scsi_bufs;
num_to_alloc = vport->cfg_lun_queue_depth + 2;
if ((sdev_cnt * (vport->cfg_lun_queue_depth + 2)) < total)
return 0;
if (total >= phba->cfg_hba_queue_depth - LPFC_DISC_IOCB_BUFF_COUNT ) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"0704 At limitation of %d preallocated "
"command buffers\n", total);
return 0;
} else if (total + num_to_alloc >
phba->cfg_hba_queue_depth - LPFC_DISC_IOCB_BUFF_COUNT ) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"0705 Allocation request of %d "
"command buffers will exceed max of %d. "
"Reducing allocation request to %d.\n",
num_to_alloc, phba->cfg_hba_queue_depth,
(phba->cfg_hba_queue_depth - total));
num_to_alloc = phba->cfg_hba_queue_depth - total;
}
num_allocated = lpfc_new_scsi_buf(vport, num_to_alloc);
if (num_to_alloc != num_allocated) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"0708 Allocation request of %d "
"command buffers did not succeed. "
"Allocated %d buffers.\n",
num_to_alloc, num_allocated);
}
if (num_allocated > 0)
phba->total_scsi_bufs += num_allocated;
return 0;
}
static int
lpfc_slave_configure(struct scsi_device *sdev)
{
struct lpfc_vport *vport = (struct lpfc_vport *) sdev->host->hostdata;
struct lpfc_hba *phba = vport->phba;
if (sdev->tagged_supported)
scsi_activate_tcq(sdev, vport->cfg_lun_queue_depth);
else
scsi_deactivate_tcq(sdev, vport->cfg_lun_queue_depth);
if (phba->cfg_poll & ENABLE_FCP_RING_POLLING) {
lpfc_sli_handle_fast_ring_event(phba,
&phba->sli.ring[LPFC_FCP_RING], HA_R0RE_REQ);
if (phba->cfg_poll & DISABLE_FCP_RING_INT)
lpfc_poll_rearm_timer(phba);
}
return 0;
}
static void
lpfc_slave_destroy(struct scsi_device *sdev)
{
struct lpfc_vport *vport = (struct lpfc_vport *) sdev->host->hostdata;
struct lpfc_hba *phba = vport->phba;
atomic_dec(&phba->sdev_cnt);
sdev->hostdata = NULL;
return;
}
