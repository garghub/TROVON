static struct lpfc_rport_data *
lpfc_rport_data_from_scsi_device(struct scsi_device *sdev)
{
struct lpfc_vport *vport = (struct lpfc_vport *)sdev->host->hostdata;
if (vport->phba->cfg_fof)
return ((struct lpfc_device_data *)sdev->hostdata)->rport_data;
else
return (struct lpfc_rport_data *)sdev->hostdata;
}
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
static inline unsigned
lpfc_cmd_blksize(struct scsi_cmnd *sc)
{
return sc->device->sector_size;
}
static inline unsigned
lpfc_cmd_protect(struct scsi_cmnd *sc, int flag)
{
return 1;
}
static inline unsigned
lpfc_cmd_guard_csum(struct scsi_cmnd *sc)
{
if (lpfc_prot_group_type(NULL, sc) == LPFC_PG_TYPE_NO_DIF)
return 0;
if (scsi_host_get_guard(sc->device->host) == SHOST_DIX_GUARD_IP)
return 1;
return 0;
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
void
lpfc_rampdown_queue_depth(struct lpfc_hba *phba)
{
unsigned long flags;
uint32_t evt_posted;
unsigned long expires;
spin_lock_irqsave(&phba->hbalock, flags);
atomic_inc(&phba->num_rsrc_err);
phba->last_rsrc_error_time = jiffies;
expires = phba->last_ramp_down_time + QUEUE_RAMP_DOWN_INTERVAL;
if (time_after(expires, jiffies)) {
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
if (num_rsrc_err == 0)
return;
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
scsi_change_queue_depth(sdev, new_queue_depth);
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
int bcnt, bpl_size;
bpl_size = phba->cfg_sg_dma_buf_size -
(sizeof(struct fcp_cmnd) + sizeof(struct fcp_rsp));
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"9067 ALLOC %d scsi_bufs: %d (%d + %d + %d)\n",
num_to_alloc, phba->cfg_sg_dma_buf_size,
(int)sizeof(struct fcp_cmnd),
(int)sizeof(struct fcp_rsp), bpl_size);
for (bcnt = 0; bcnt < num_to_alloc; bcnt++) {
psb = kzalloc(sizeof(struct lpfc_scsi_buf), GFP_KERNEL);
if (!psb)
break;
psb->data = pci_pool_zalloc(phba->lpfc_sg_dma_buf_pool,
GFP_KERNEL, &psb->dma_handle);
if (!psb->data) {
kfree(psb);
break;
}
iotag = lpfc_sli_next_iotag(phba, &psb->cur_iocbq);
if (iotag == 0) {
pci_pool_free(phba->lpfc_sg_dma_buf_pool,
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
if (!(phba->cfg_enable_fc4_type & LPFC_ENABLE_FCP))
return;
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
struct lpfc_sli_ring *pring = phba->sli4_hba.els_wq->pring;
if (!(phba->cfg_enable_fc4_type & LPFC_ENABLE_FCP))
return;
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
if (ndlp) {
lpfc_set_rrq_active(phba, ndlp,
psb->cur_iocbq.sli4_lxritag, rxid, 1);
lpfc_sli4_abts_err_handler(phba, ndlp, axri);
}
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
if (!list_empty(&pring->txq))
lpfc_worker_wake_up(phba);
return;
}
spin_unlock_irqrestore(&phba->hbalock, iflag);
}
static int
lpfc_sli4_post_scsi_sgl_list(struct lpfc_hba *phba,
struct list_head *post_sblist, int sb_count)
{
struct lpfc_scsi_buf *psb, *psb_next;
int status, sgl_size;
int post_cnt = 0, block_cnt = 0, num_posting = 0, num_posted = 0;
dma_addr_t pdma_phys_bpl1;
int last_xritag = NO_XRI;
LIST_HEAD(prep_sblist);
LIST_HEAD(blck_sblist);
LIST_HEAD(scsi_sblist);
if (sb_count <= 0)
return -EINVAL;
sgl_size = phba->cfg_sg_dma_buf_size -
(sizeof(struct fcp_cmnd) + sizeof(struct fcp_rsp));
list_for_each_entry_safe(psb, psb_next, post_sblist, list) {
list_del_init(&psb->list);
block_cnt++;
if ((last_xritag != NO_XRI) &&
(psb->cur_iocbq.sli4_xritag != last_xritag + 1)) {
list_splice_init(&prep_sblist, &blck_sblist);
post_cnt = block_cnt - 1;
list_add_tail(&psb->list, &prep_sblist);
block_cnt = 1;
} else {
list_add_tail(&psb->list, &prep_sblist);
if (block_cnt == LPFC_NEMBED_MBOX_SGL_CNT) {
list_splice_init(&prep_sblist, &blck_sblist);
post_cnt = block_cnt;
block_cnt = 0;
}
}
num_posting++;
last_xritag = psb->cur_iocbq.sli4_xritag;
if (num_posting == sb_count) {
if (post_cnt == 0) {
list_splice_init(&prep_sblist, &blck_sblist);
post_cnt = block_cnt;
} else if (block_cnt == 1) {
if (sgl_size > SGL_PAGE_SIZE)
pdma_phys_bpl1 = psb->dma_phys_bpl +
SGL_PAGE_SIZE;
else
pdma_phys_bpl1 = 0;
status = lpfc_sli4_post_sgl(phba,
psb->dma_phys_bpl,
pdma_phys_bpl1,
psb->cur_iocbq.sli4_xritag);
if (status) {
psb->exch_busy = 1;
} else {
psb->exch_busy = 0;
psb->status = IOSTAT_SUCCESS;
num_posted++;
}
list_add_tail(&psb->list, &scsi_sblist);
}
}
if (post_cnt == 0)
continue;
status = lpfc_sli4_post_scsi_sgl_block(phba, &blck_sblist,
post_cnt);
if (block_cnt == 0)
last_xritag = NO_XRI;
post_cnt = 0;
while (!list_empty(&blck_sblist)) {
list_remove_head(&blck_sblist, psb,
struct lpfc_scsi_buf, list);
if (status) {
psb->exch_busy = 1;
} else {
psb->exch_busy = 0;
psb->status = IOSTAT_SUCCESS;
num_posted++;
}
list_add_tail(&psb->list, &scsi_sblist);
}
}
while (!list_empty(&scsi_sblist)) {
list_remove_head(&scsi_sblist, psb,
struct lpfc_scsi_buf, list);
lpfc_release_scsi_buf_s4(phba, psb);
}
return num_posted;
}
int
lpfc_sli4_repost_scsi_sgl_list(struct lpfc_hba *phba)
{
LIST_HEAD(post_sblist);
int num_posted, rc = 0;
spin_lock_irq(&phba->scsi_buf_list_get_lock);
spin_lock(&phba->scsi_buf_list_put_lock);
list_splice_init(&phba->lpfc_scsi_buf_list_get, &post_sblist);
list_splice(&phba->lpfc_scsi_buf_list_put, &post_sblist);
spin_unlock(&phba->scsi_buf_list_put_lock);
spin_unlock_irq(&phba->scsi_buf_list_get_lock);
if (!list_empty(&post_sblist)) {
num_posted = lpfc_sli4_post_scsi_sgl_list(phba, &post_sblist,
phba->sli4_hba.scsi_xri_cnt);
if (num_posted == 0)
rc = -EIO;
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
dma_addr_t pdma_phys_bpl;
uint16_t iotag, lxri = 0;
int bcnt, num_posted, sgl_size;
LIST_HEAD(prep_sblist);
LIST_HEAD(post_sblist);
LIST_HEAD(scsi_sblist);
sgl_size = phba->cfg_sg_dma_buf_size -
(sizeof(struct fcp_cmnd) + sizeof(struct fcp_rsp));
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"9068 ALLOC %d scsi_bufs: %d (%d + %d + %d)\n",
num_to_alloc, phba->cfg_sg_dma_buf_size, sgl_size,
(int)sizeof(struct fcp_cmnd),
(int)sizeof(struct fcp_rsp));
for (bcnt = 0; bcnt < num_to_alloc; bcnt++) {
psb = kzalloc(sizeof(struct lpfc_scsi_buf), GFP_KERNEL);
if (!psb)
break;
psb->data = pci_pool_zalloc(phba->lpfc_sg_dma_buf_pool,
GFP_KERNEL, &psb->dma_handle);
if (!psb->data) {
kfree(psb);
break;
}
if (phba->cfg_enable_bg && (((unsigned long)(psb->data) &
(unsigned long)(SLI4_PAGE_SIZE - 1)) != 0)) {
pci_pool_free(phba->lpfc_sg_dma_buf_pool,
psb->data, psb->dma_handle);
kfree(psb);
break;
}
lxri = lpfc_sli4_next_xritag(phba);
if (lxri == NO_XRI) {
pci_pool_free(phba->lpfc_sg_dma_buf_pool,
psb->data, psb->dma_handle);
kfree(psb);
break;
}
iotag = lpfc_sli_next_iotag(phba, &psb->cur_iocbq);
if (iotag == 0) {
pci_pool_free(phba->lpfc_sg_dma_buf_pool,
psb->data, psb->dma_handle);
kfree(psb);
lpfc_printf_log(phba, KERN_ERR, LOG_FCP,
"3368 Failed to allocate IOTAG for"
" XRI:0x%x\n", lxri);
lpfc_sli4_free_xri(phba, lxri);
break;
}
psb->cur_iocbq.sli4_lxritag = lxri;
psb->cur_iocbq.sli4_xritag = phba->sli4_hba.xri_ids[lxri];
psb->cur_iocbq.iocb_flag |= LPFC_IO_FCP;
psb->fcp_bpl = psb->data;
psb->fcp_cmnd = (psb->data + sgl_size);
psb->fcp_rsp = (struct fcp_rsp *)((uint8_t *)psb->fcp_cmnd +
sizeof(struct fcp_cmnd));
sgl = (struct sli4_sge *)psb->fcp_bpl;
pdma_phys_bpl = psb->dma_handle;
pdma_phys_fcp_cmd = (psb->dma_handle + sgl_size);
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
psb->dma_phys_bpl = pdma_phys_bpl;
list_add_tail(&psb->list, &post_sblist);
spin_lock_irq(&phba->scsi_buf_list_get_lock);
phba->sli4_hba.scsi_xri_cnt++;
spin_unlock_irq(&phba->scsi_buf_list_get_lock);
}
lpfc_printf_log(phba, KERN_INFO, LOG_BG | LOG_FCP,
"3021 Allocate %d out of %d requested new SCSI "
"buffers\n", bcnt, num_to_alloc);
if (!list_empty(&post_sblist))
num_posted = lpfc_sli4_post_scsi_sgl_list(phba,
&post_sblist, bcnt);
else
num_posted = 0;
return num_posted;
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
struct list_head *scsi_buf_list_get = &phba->lpfc_scsi_buf_list_get;
unsigned long iflag = 0;
spin_lock_irqsave(&phba->scsi_buf_list_get_lock, iflag);
list_remove_head(scsi_buf_list_get, lpfc_cmd, struct lpfc_scsi_buf,
list);
if (!lpfc_cmd) {
spin_lock(&phba->scsi_buf_list_put_lock);
list_splice(&phba->lpfc_scsi_buf_list_put,
&phba->lpfc_scsi_buf_list_get);
INIT_LIST_HEAD(&phba->lpfc_scsi_buf_list_put);
list_remove_head(scsi_buf_list_get, lpfc_cmd,
struct lpfc_scsi_buf, list);
spin_unlock(&phba->scsi_buf_list_put_lock);
}
spin_unlock_irqrestore(&phba->scsi_buf_list_get_lock, iflag);
return lpfc_cmd;
}
static struct lpfc_scsi_buf*
lpfc_get_scsi_buf_s4(struct lpfc_hba *phba, struct lpfc_nodelist *ndlp)
{
struct lpfc_scsi_buf *lpfc_cmd, *lpfc_cmd_next;
unsigned long iflag = 0;
int found = 0;
spin_lock_irqsave(&phba->scsi_buf_list_get_lock, iflag);
list_for_each_entry_safe(lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if (lpfc_test_rrq_active(phba, ndlp,
lpfc_cmd->cur_iocbq.sli4_lxritag))
continue;
list_del(&lpfc_cmd->list);
found = 1;
break;
}
if (!found) {
spin_lock(&phba->scsi_buf_list_put_lock);
list_splice(&phba->lpfc_scsi_buf_list_put,
&phba->lpfc_scsi_buf_list_get);
INIT_LIST_HEAD(&phba->lpfc_scsi_buf_list_put);
spin_unlock(&phba->scsi_buf_list_put_lock);
list_for_each_entry_safe(lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if (lpfc_test_rrq_active(
phba, ndlp, lpfc_cmd->cur_iocbq.sli4_lxritag))
continue;
list_del(&lpfc_cmd->list);
found = 1;
break;
}
}
spin_unlock_irqrestore(&phba->scsi_buf_list_get_lock, iflag);
if (!found)
return NULL;
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
psb->seg_cnt = 0;
psb->nonsg_phys = 0;
psb->prot_seg_cnt = 0;
spin_lock_irqsave(&phba->scsi_buf_list_put_lock, iflag);
psb->pCmd = NULL;
psb->cur_iocbq.iocb_flag = LPFC_IO_FCP;
list_add_tail(&psb->list, &phba->lpfc_scsi_buf_list_put);
spin_unlock_irqrestore(&phba->scsi_buf_list_put_lock, iflag);
}
static void
lpfc_release_scsi_buf_s4(struct lpfc_hba *phba, struct lpfc_scsi_buf *psb)
{
unsigned long iflag = 0;
psb->seg_cnt = 0;
psb->nonsg_phys = 0;
psb->prot_seg_cnt = 0;
if (psb->exch_busy) {
spin_lock_irqsave(&phba->sli4_hba.abts_scsi_buf_list_lock,
iflag);
psb->pCmd = NULL;
list_add_tail(&psb->list,
&phba->sli4_hba.lpfc_abts_scsi_buf_list);
spin_unlock_irqrestore(&phba->sli4_hba.abts_scsi_buf_list_lock,
iflag);
} else {
psb->pCmd = NULL;
psb->cur_iocbq.iocb_flag = LPFC_IO_FCP;
spin_lock_irqsave(&phba->scsi_buf_list_put_lock, iflag);
list_add_tail(&psb->list, &phba->lpfc_scsi_buf_list_put);
spin_unlock_irqrestore(&phba->scsi_buf_list_put_lock, iflag);
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
lpfc_cmd->seg_cnt = 0;
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
lpfc_bg_err_inject(struct lpfc_hba *phba, struct scsi_cmnd *sc,
uint32_t *reftag, uint16_t *apptag, uint32_t new_guard)
{
struct scatterlist *sgpe;
struct lpfc_scsi_buf *lpfc_cmd = NULL;
struct scsi_dif_tuple *src = NULL;
struct lpfc_nodelist *ndlp;
struct lpfc_rport_data *rdata;
uint32_t op = scsi_get_prot_op(sc);
uint32_t blksize;
uint32_t numblks;
sector_t lba;
int rc = 0;
int blockoff = 0;
if (op == SCSI_PROT_NORMAL)
return 0;
sgpe = scsi_prot_sglist(sc);
lba = scsi_get_lba(sc);
if (phba->lpfc_injerr_lba != LPFC_INJERR_LBA_OFF) {
blksize = lpfc_cmd_blksize(sc);
numblks = (scsi_bufflen(sc) + blksize - 1) / blksize;
if ((phba->lpfc_injerr_lba < lba) ||
(phba->lpfc_injerr_lba >= (lba + numblks)))
return 0;
if (sgpe) {
blockoff = phba->lpfc_injerr_lba - lba;
numblks = sg_dma_len(sgpe) /
sizeof(struct scsi_dif_tuple);
if (numblks < blockoff)
blockoff = numblks;
}
}
rdata = lpfc_rport_data_from_scsi_device(sc->device);
if (rdata && rdata->pnode) {
ndlp = rdata->pnode;
if (phba->lpfc_injerr_nportid &&
(phba->lpfc_injerr_nportid != ndlp->nlp_DID))
return 0;
if (phba->lpfc_injerr_wwpn.u.wwn[0] &&
(memcmp(&ndlp->nlp_portname, &phba->lpfc_injerr_wwpn,
sizeof(struct lpfc_name)) != 0))
return 0;
}
if (sgpe) {
src = (struct scsi_dif_tuple *)sg_virt(sgpe);
src += blockoff;
lpfc_cmd = (struct lpfc_scsi_buf *)sc->host_scribble;
}
if (reftag) {
if (phba->lpfc_injerr_wref_cnt) {
switch (op) {
case SCSI_PROT_WRITE_PASS:
if (src) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9076 BLKGRD: Injecting reftag error: "
"write lba x%lx + x%x oldrefTag x%x\n",
(unsigned long)lba, blockoff,
be32_to_cpu(src->ref_tag));
if (lpfc_cmd) {
lpfc_cmd->prot_data_type =
LPFC_INJERR_REFTAG;
lpfc_cmd->prot_data_segment =
src;
lpfc_cmd->prot_data =
src->ref_tag;
}
src->ref_tag = cpu_to_be32(0xDEADBEEF);
phba->lpfc_injerr_wref_cnt--;
if (phba->lpfc_injerr_wref_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc = BG_ERR_TGT | BG_ERR_CHECK;
break;
}
case SCSI_PROT_WRITE_INSERT:
*reftag = 0xDEADBEEF;
phba->lpfc_injerr_wref_cnt--;
if (phba->lpfc_injerr_wref_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc = BG_ERR_TGT | BG_ERR_CHECK;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9078 BLKGRD: Injecting reftag error: "
"write lba x%lx\n", (unsigned long)lba);
break;
case SCSI_PROT_WRITE_STRIP:
*reftag = 0xDEADBEEF;
phba->lpfc_injerr_wref_cnt--;
if (phba->lpfc_injerr_wref_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc = BG_ERR_INIT;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9077 BLKGRD: Injecting reftag error: "
"write lba x%lx\n", (unsigned long)lba);
break;
}
}
if (phba->lpfc_injerr_rref_cnt) {
switch (op) {
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_READ_PASS:
*reftag = 0xDEADBEEF;
phba->lpfc_injerr_rref_cnt--;
if (phba->lpfc_injerr_rref_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc = BG_ERR_INIT;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9079 BLKGRD: Injecting reftag error: "
"read lba x%lx\n", (unsigned long)lba);
break;
}
}
}
if (apptag) {
if (phba->lpfc_injerr_wapp_cnt) {
switch (op) {
case SCSI_PROT_WRITE_PASS:
if (src) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9080 BLKGRD: Injecting apptag error: "
"write lba x%lx + x%x oldappTag x%x\n",
(unsigned long)lba, blockoff,
be16_to_cpu(src->app_tag));
if (lpfc_cmd) {
lpfc_cmd->prot_data_type =
LPFC_INJERR_APPTAG;
lpfc_cmd->prot_data_segment =
src;
lpfc_cmd->prot_data =
src->app_tag;
}
src->app_tag = cpu_to_be16(0xDEAD);
phba->lpfc_injerr_wapp_cnt--;
if (phba->lpfc_injerr_wapp_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc = BG_ERR_TGT | BG_ERR_CHECK;
break;
}
case SCSI_PROT_WRITE_INSERT:
*apptag = 0xDEAD;
phba->lpfc_injerr_wapp_cnt--;
if (phba->lpfc_injerr_wapp_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc = BG_ERR_TGT | BG_ERR_CHECK;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"0813 BLKGRD: Injecting apptag error: "
"write lba x%lx\n", (unsigned long)lba);
break;
case SCSI_PROT_WRITE_STRIP:
*apptag = 0xDEAD;
phba->lpfc_injerr_wapp_cnt--;
if (phba->lpfc_injerr_wapp_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc = BG_ERR_INIT;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"0812 BLKGRD: Injecting apptag error: "
"write lba x%lx\n", (unsigned long)lba);
break;
}
}
if (phba->lpfc_injerr_rapp_cnt) {
switch (op) {
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_READ_PASS:
*apptag = 0xDEAD;
phba->lpfc_injerr_rapp_cnt--;
if (phba->lpfc_injerr_rapp_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc = BG_ERR_INIT;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"0814 BLKGRD: Injecting apptag error: "
"read lba x%lx\n", (unsigned long)lba);
break;
}
}
}
if (new_guard) {
if (phba->lpfc_injerr_wgrd_cnt) {
switch (op) {
case SCSI_PROT_WRITE_PASS:
rc = BG_ERR_CHECK;
case SCSI_PROT_WRITE_INSERT:
phba->lpfc_injerr_wgrd_cnt--;
if (phba->lpfc_injerr_wgrd_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc |= BG_ERR_TGT | BG_ERR_SWAP;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"0817 BLKGRD: Injecting guard error: "
"write lba x%lx\n", (unsigned long)lba);
break;
case SCSI_PROT_WRITE_STRIP:
phba->lpfc_injerr_wgrd_cnt--;
if (phba->lpfc_injerr_wgrd_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc = BG_ERR_INIT | BG_ERR_SWAP;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"0816 BLKGRD: Injecting guard error: "
"write lba x%lx\n", (unsigned long)lba);
break;
}
}
if (phba->lpfc_injerr_rgrd_cnt) {
switch (op) {
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_READ_PASS:
phba->lpfc_injerr_rgrd_cnt--;
if (phba->lpfc_injerr_rgrd_cnt == 0) {
phba->lpfc_injerr_nportid = 0;
phba->lpfc_injerr_lba =
LPFC_INJERR_LBA_OFF;
memset(&phba->lpfc_injerr_wwpn,
0, sizeof(struct lpfc_name));
}
rc = BG_ERR_INIT | BG_ERR_SWAP;
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"0818 BLKGRD: Injecting guard error: "
"read lba x%lx\n", (unsigned long)lba);
}
}
}
return rc;
}
static int
lpfc_sc_to_bg_opcodes(struct lpfc_hba *phba, struct scsi_cmnd *sc,
uint8_t *txop, uint8_t *rxop)
{
uint8_t ret = 0;
if (lpfc_cmd_guard_csum(sc)) {
switch (scsi_get_prot_op(sc)) {
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_WRITE_STRIP:
*rxop = BG_OP_IN_NODIF_OUT_CSUM;
*txop = BG_OP_IN_CSUM_OUT_NODIF;
break;
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_WRITE_INSERT:
*rxop = BG_OP_IN_CRC_OUT_NODIF;
*txop = BG_OP_IN_NODIF_OUT_CRC;
break;
case SCSI_PROT_READ_PASS:
case SCSI_PROT_WRITE_PASS:
*rxop = BG_OP_IN_CRC_OUT_CSUM;
*txop = BG_OP_IN_CSUM_OUT_CRC;
break;
case SCSI_PROT_NORMAL:
default:
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9063 BLKGRD: Bad op/guard:%d/IP combination\n",
scsi_get_prot_op(sc));
ret = 1;
break;
}
} else {
switch (scsi_get_prot_op(sc)) {
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_WRITE_INSERT:
*rxop = BG_OP_IN_CRC_OUT_NODIF;
*txop = BG_OP_IN_NODIF_OUT_CRC;
break;
case SCSI_PROT_READ_PASS:
case SCSI_PROT_WRITE_PASS:
*rxop = BG_OP_IN_CRC_OUT_CRC;
*txop = BG_OP_IN_CRC_OUT_CRC;
break;
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_WRITE_STRIP:
*rxop = BG_OP_IN_NODIF_OUT_CRC;
*txop = BG_OP_IN_CRC_OUT_NODIF;
break;
case SCSI_PROT_NORMAL:
default:
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9075 BLKGRD: Bad op/guard:%d/CRC combination\n",
scsi_get_prot_op(sc));
ret = 1;
break;
}
}
return ret;
}
static int
lpfc_bg_err_opcodes(struct lpfc_hba *phba, struct scsi_cmnd *sc,
uint8_t *txop, uint8_t *rxop)
{
uint8_t ret = 0;
if (lpfc_cmd_guard_csum(sc)) {
switch (scsi_get_prot_op(sc)) {
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_WRITE_STRIP:
*rxop = BG_OP_IN_NODIF_OUT_CRC;
*txop = BG_OP_IN_CRC_OUT_NODIF;
break;
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_WRITE_INSERT:
*rxop = BG_OP_IN_CSUM_OUT_NODIF;
*txop = BG_OP_IN_NODIF_OUT_CSUM;
break;
case SCSI_PROT_READ_PASS:
case SCSI_PROT_WRITE_PASS:
*rxop = BG_OP_IN_CSUM_OUT_CRC;
*txop = BG_OP_IN_CRC_OUT_CSUM;
break;
case SCSI_PROT_NORMAL:
default:
break;
}
} else {
switch (scsi_get_prot_op(sc)) {
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_WRITE_INSERT:
*rxop = BG_OP_IN_CSUM_OUT_NODIF;
*txop = BG_OP_IN_NODIF_OUT_CSUM;
break;
case SCSI_PROT_READ_PASS:
case SCSI_PROT_WRITE_PASS:
*rxop = BG_OP_IN_CSUM_OUT_CSUM;
*txop = BG_OP_IN_CSUM_OUT_CSUM;
break;
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_WRITE_STRIP:
*rxop = BG_OP_IN_NODIF_OUT_CSUM;
*txop = BG_OP_IN_CSUM_OUT_NODIF;
break;
case SCSI_PROT_NORMAL:
default:
break;
}
}
return ret;
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
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
uint32_t rc;
#endif
uint32_t checking = 1;
uint32_t reftag;
uint8_t txop, rxop;
status = lpfc_sc_to_bg_opcodes(phba, sc, &txop, &rxop);
if (status)
goto out;
reftag = (uint32_t)scsi_get_lba(sc);
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
rc = lpfc_bg_err_inject(phba, sc, &reftag, NULL, 1);
if (rc) {
if (rc & BG_ERR_SWAP)
lpfc_bg_err_opcodes(phba, sc, &txop, &rxop);
if (rc & BG_ERR_CHECK)
checking = 0;
}
#endif
pde5 = (struct lpfc_pde5 *) bpl;
memset(pde5, 0, sizeof(struct lpfc_pde5));
bf_set(pde5_type, pde5, LPFC_PDE5_DESCRIPTOR);
pde5->word0 = cpu_to_le32(pde5->word0);
pde5->reftag = cpu_to_le32(reftag);
num_bde++;
bpl++;
pde6 = (struct lpfc_pde6 *) bpl;
memset(pde6, 0, sizeof(struct lpfc_pde6));
bf_set(pde6_type, pde6, LPFC_PDE6_DESCRIPTOR);
bf_set(pde6_optx, pde6, txop);
bf_set(pde6_oprx, pde6, rxop);
if (datadir == DMA_FROM_DEVICE) {
if (lpfc_cmd_protect(sc, LPFC_CHECK_PROTECT_GUARD))
bf_set(pde6_ce, pde6, checking);
else
bf_set(pde6_ce, pde6, 0);
if (lpfc_cmd_protect(sc, LPFC_CHECK_PROTECT_REF))
bf_set(pde6_re, pde6, checking);
else
bf_set(pde6_re, pde6, 0);
}
bf_set(pde6_ai, pde6, 1);
bf_set(pde6_ae, pde6, 0);
bf_set(pde6_apptagval, pde6, 0);
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
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
uint32_t rc;
#endif
uint32_t checking = 1;
uint32_t reftag;
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
reftag = (uint32_t)scsi_get_lba(sc);
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
rc = lpfc_bg_err_inject(phba, sc, &reftag, NULL, 1);
if (rc) {
if (rc & BG_ERR_SWAP)
lpfc_bg_err_opcodes(phba, sc, &txop, &rxop);
if (rc & BG_ERR_CHECK)
checking = 0;
}
#endif
split_offset = 0;
do {
if (num_bde >= (phba->cfg_total_seg_cnt - 2))
return num_bde + 3;
pde5 = (struct lpfc_pde5 *) bpl;
memset(pde5, 0, sizeof(struct lpfc_pde5));
bf_set(pde5_type, pde5, LPFC_PDE5_DESCRIPTOR);
pde5->word0 = cpu_to_le32(pde5->word0);
pde5->reftag = cpu_to_le32(reftag);
num_bde++;
bpl++;
pde6 = (struct lpfc_pde6 *) bpl;
memset(pde6, 0, sizeof(struct lpfc_pde6));
bf_set(pde6_type, pde6, LPFC_PDE6_DESCRIPTOR);
bf_set(pde6_optx, pde6, txop);
bf_set(pde6_oprx, pde6, rxop);
if (lpfc_cmd_protect(sc, LPFC_CHECK_PROTECT_GUARD))
bf_set(pde6_ce, pde6, checking);
else
bf_set(pde6_ce, pde6, 0);
if (lpfc_cmd_protect(sc, LPFC_CHECK_PROTECT_REF))
bf_set(pde6_re, pde6, checking);
else
bf_set(pde6_re, pde6, 0);
bf_set(pde6_ai, pde6, 1);
bf_set(pde6_ae, pde6, 0);
bf_set(pde6_apptagval, pde6, 0);
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
pde7->addrHigh = le32_to_cpu(putPaddrHigh(protphysaddr));
pde7->addrLow = le32_to_cpu(putPaddrLow(protphysaddr));
protgrp_blks = protgroup_len / 8;
protgrp_bytes = protgrp_blks * blksize;
if ((pde7->addrLow & 0xfff) + protgroup_len > 0x1000) {
protgroup_remainder = 0x1000 - (pde7->addrLow & 0xfff);
protgroup_offset += protgroup_remainder;
protgrp_blks = protgroup_remainder / 8;
protgrp_bytes = protgrp_blks * blksize;
} else {
protgroup_offset = 0;
curr_prot++;
}
num_bde++;
pgdone = 0;
subtotal = 0;
while (!pgdone) {
if (num_bde >= phba->cfg_total_seg_cnt)
return num_bde + 1;
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
lpfc_bg_setup_sgl(struct lpfc_hba *phba, struct scsi_cmnd *sc,
struct sli4_sge *sgl, int datasegcnt)
{
struct scatterlist *sgde = NULL;
struct sli4_sge_diseed *diseed = NULL;
dma_addr_t physaddr;
int i = 0, num_sge = 0, status;
uint32_t reftag;
uint8_t txop, rxop;
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
uint32_t rc;
#endif
uint32_t checking = 1;
uint32_t dma_len;
uint32_t dma_offset = 0;
status = lpfc_sc_to_bg_opcodes(phba, sc, &txop, &rxop);
if (status)
goto out;
reftag = (uint32_t)scsi_get_lba(sc);
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
rc = lpfc_bg_err_inject(phba, sc, &reftag, NULL, 1);
if (rc) {
if (rc & BG_ERR_SWAP)
lpfc_bg_err_opcodes(phba, sc, &txop, &rxop);
if (rc & BG_ERR_CHECK)
checking = 0;
}
#endif
diseed = (struct sli4_sge_diseed *) sgl;
memset(diseed, 0, sizeof(struct sli4_sge_diseed));
bf_set(lpfc_sli4_sge_type, sgl, LPFC_SGE_TYPE_DISEED);
diseed->ref_tag = cpu_to_le32(reftag);
diseed->ref_tag_tran = diseed->ref_tag;
if (sc->sc_data_direction == DMA_FROM_DEVICE) {
if (lpfc_cmd_protect(sc, LPFC_CHECK_PROTECT_GUARD))
bf_set(lpfc_sli4_sge_dif_ce, diseed, checking);
else
bf_set(lpfc_sli4_sge_dif_ce, diseed, 0);
if (lpfc_cmd_protect(sc, LPFC_CHECK_PROTECT_REF))
bf_set(lpfc_sli4_sge_dif_re, diseed, checking);
else
bf_set(lpfc_sli4_sge_dif_re, diseed, 0);
}
bf_set(lpfc_sli4_sge_dif_optx, diseed, txop);
bf_set(lpfc_sli4_sge_dif_oprx, diseed, rxop);
bf_set(lpfc_sli4_sge_dif_ai, diseed, 1);
bf_set(lpfc_sli4_sge_dif_me, diseed, 0);
diseed->word2 = cpu_to_le32(diseed->word2);
diseed->word3 = cpu_to_le32(diseed->word3);
num_sge++;
sgl++;
scsi_for_each_sg(sc, sgde, datasegcnt, i) {
physaddr = sg_dma_address(sgde);
dma_len = sg_dma_len(sgde);
sgl->addr_lo = cpu_to_le32(putPaddrLow(physaddr));
sgl->addr_hi = cpu_to_le32(putPaddrHigh(physaddr));
if ((i + 1) == datasegcnt)
bf_set(lpfc_sli4_sge_last, sgl, 1);
else
bf_set(lpfc_sli4_sge_last, sgl, 0);
bf_set(lpfc_sli4_sge_offset, sgl, dma_offset);
bf_set(lpfc_sli4_sge_type, sgl, LPFC_SGE_TYPE_DATA);
sgl->sge_len = cpu_to_le32(dma_len);
dma_offset += dma_len;
sgl++;
num_sge++;
}
out:
return num_sge;
}
static int
lpfc_bg_setup_sgl_prot(struct lpfc_hba *phba, struct scsi_cmnd *sc,
struct sli4_sge *sgl, int datacnt, int protcnt)
{
struct scatterlist *sgde = NULL;
struct scatterlist *sgpe = NULL;
struct sli4_sge_diseed *diseed = NULL;
dma_addr_t dataphysaddr, protphysaddr;
unsigned short curr_data = 0, curr_prot = 0;
unsigned int split_offset;
unsigned int protgroup_len, protgroup_offset = 0, protgroup_remainder;
unsigned int protgrp_blks, protgrp_bytes;
unsigned int remainder, subtotal;
int status;
unsigned char pgdone = 0, alldone = 0;
unsigned blksize;
uint32_t reftag;
uint8_t txop, rxop;
uint32_t dma_len;
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
uint32_t rc;
#endif
uint32_t checking = 1;
uint32_t dma_offset = 0;
int num_sge = 0;
sgpe = scsi_prot_sglist(sc);
sgde = scsi_sglist(sc);
if (!sgpe || !sgde) {
lpfc_printf_log(phba, KERN_ERR, LOG_FCP,
"9082 Invalid s/g entry: data=0x%p prot=0x%p\n",
sgpe, sgde);
return 0;
}
status = lpfc_sc_to_bg_opcodes(phba, sc, &txop, &rxop);
if (status)
goto out;
blksize = lpfc_cmd_blksize(sc);
reftag = (uint32_t)scsi_get_lba(sc);
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
rc = lpfc_bg_err_inject(phba, sc, &reftag, NULL, 1);
if (rc) {
if (rc & BG_ERR_SWAP)
lpfc_bg_err_opcodes(phba, sc, &txop, &rxop);
if (rc & BG_ERR_CHECK)
checking = 0;
}
#endif
split_offset = 0;
do {
if (num_sge >= (phba->cfg_total_seg_cnt - 2))
return num_sge + 3;
diseed = (struct sli4_sge_diseed *) sgl;
memset(diseed, 0, sizeof(struct sli4_sge_diseed));
bf_set(lpfc_sli4_sge_type, sgl, LPFC_SGE_TYPE_DISEED);
diseed->ref_tag = cpu_to_le32(reftag);
diseed->ref_tag_tran = diseed->ref_tag;
if (lpfc_cmd_protect(sc, LPFC_CHECK_PROTECT_GUARD)) {
bf_set(lpfc_sli4_sge_dif_ce, diseed, checking);
} else {
bf_set(lpfc_sli4_sge_dif_ce, diseed, 0);
if (txop == BG_OP_IN_CRC_OUT_CRC) {
txop = BG_OP_RAW_MODE;
rxop = BG_OP_RAW_MODE;
}
}
if (lpfc_cmd_protect(sc, LPFC_CHECK_PROTECT_REF))
bf_set(lpfc_sli4_sge_dif_re, diseed, checking);
else
bf_set(lpfc_sli4_sge_dif_re, diseed, 0);
bf_set(lpfc_sli4_sge_dif_optx, diseed, txop);
bf_set(lpfc_sli4_sge_dif_oprx, diseed, rxop);
bf_set(lpfc_sli4_sge_dif_ai, diseed, 1);
bf_set(lpfc_sli4_sge_dif_me, diseed, 0);
diseed->word2 = cpu_to_le32(diseed->word2);
diseed->word3 = cpu_to_le32(diseed->word3);
num_sge++;
sgl++;
protphysaddr = sg_dma_address(sgpe) + protgroup_offset;
protgroup_len = sg_dma_len(sgpe) - protgroup_offset;
BUG_ON(protgroup_len % 8);
sgl->word2 = 0;
bf_set(lpfc_sli4_sge_type, sgl, LPFC_SGE_TYPE_DIF);
sgl->addr_hi = le32_to_cpu(putPaddrHigh(protphysaddr));
sgl->addr_lo = le32_to_cpu(putPaddrLow(protphysaddr));
sgl->word2 = cpu_to_le32(sgl->word2);
protgrp_blks = protgroup_len / 8;
protgrp_bytes = protgrp_blks * blksize;
if ((sgl->addr_lo & 0xfff) + protgroup_len > 0x1000) {
protgroup_remainder = 0x1000 - (sgl->addr_lo & 0xfff);
protgroup_offset += protgroup_remainder;
protgrp_blks = protgroup_remainder / 8;
protgrp_bytes = protgrp_blks * blksize;
} else {
protgroup_offset = 0;
curr_prot++;
}
num_sge++;
pgdone = 0;
subtotal = 0;
while (!pgdone) {
if (num_sge >= phba->cfg_total_seg_cnt)
return num_sge + 1;
if (!sgde) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9086 BLKGRD:%s Invalid data segment\n",
__func__);
return 0;
}
sgl++;
dataphysaddr = sg_dma_address(sgde) + split_offset;
remainder = sg_dma_len(sgde) - split_offset;
if ((subtotal + remainder) <= protgrp_bytes) {
dma_len = remainder;
split_offset = 0;
if ((subtotal + remainder) == protgrp_bytes)
pgdone = 1;
} else {
dma_len = protgrp_bytes - subtotal;
split_offset += dma_len;
}
subtotal += dma_len;
sgl->addr_lo = cpu_to_le32(putPaddrLow(dataphysaddr));
sgl->addr_hi = cpu_to_le32(putPaddrHigh(dataphysaddr));
bf_set(lpfc_sli4_sge_last, sgl, 0);
bf_set(lpfc_sli4_sge_offset, sgl, dma_offset);
bf_set(lpfc_sli4_sge_type, sgl, LPFC_SGE_TYPE_DATA);
sgl->sge_len = cpu_to_le32(dma_len);
dma_offset += dma_len;
num_sge++;
curr_data++;
if (split_offset)
break;
sgde = sg_next(sgde);
}
if (protgroup_offset) {
reftag += protgrp_blks;
sgl++;
continue;
}
if (curr_prot == protcnt) {
bf_set(lpfc_sli4_sge_last, sgl, 1);
alldone = 1;
} else if (curr_prot < protcnt) {
sgpe = sg_next(sgpe);
sgl++;
reftag += protgrp_blks;
} else {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9085 BLKGRD: bug in %s\n", __func__);
}
} while (!alldone);
out:
return num_sge;
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
if (phba)
lpfc_printf_log(phba, KERN_ERR, LOG_FCP,
"9021 Unsupported protection op:%d\n",
op);
break;
}
return ret;
}
static int
lpfc_bg_scsi_adjust_dl(struct lpfc_hba *phba,
struct lpfc_scsi_buf *lpfc_cmd)
{
struct scsi_cmnd *sc = lpfc_cmd->pCmd;
int fcpdl;
fcpdl = scsi_bufflen(sc);
if (sc->sc_data_direction == DMA_FROM_DEVICE) {
if (scsi_get_prot_op(sc) == SCSI_PROT_READ_INSERT)
return fcpdl;
} else {
if (scsi_get_prot_op(sc) == SCSI_PROT_WRITE_STRIP)
return fcpdl;
}
fcpdl += (fcpdl / lpfc_cmd_blksize(sc)) * 8;
return fcpdl;
}
static int
lpfc_bg_scsi_prep_dma_buf_s3(struct lpfc_hba *phba,
struct lpfc_scsi_buf *lpfc_cmd)
{
struct scsi_cmnd *scsi_cmnd = lpfc_cmd->pCmd;
struct fcp_cmnd *fcp_cmnd = lpfc_cmd->fcp_cmnd;
struct ulp_bde64 *bpl = lpfc_cmd->fcp_bpl;
IOCB_t *iocb_cmd = &lpfc_cmd->cur_iocbq.iocb;
uint32_t num_bde = 0;
int datasegcnt, protsegcnt, datadir = scsi_cmnd->sc_data_direction;
int prot_group_type = 0;
int fcpdl;
bpl += 2;
if (scsi_sg_count(scsi_cmnd)) {
datasegcnt = dma_map_sg(&phba->pcidev->dev,
scsi_sglist(scsi_cmnd),
scsi_sg_count(scsi_cmnd), datadir);
if (unlikely(!datasegcnt))
return 1;
lpfc_cmd->seg_cnt = datasegcnt;
if (lpfc_cmd->seg_cnt > phba->cfg_sg_seg_cnt)
goto err;
prot_group_type = lpfc_prot_group_type(phba, scsi_cmnd);
switch (prot_group_type) {
case LPFC_PG_TYPE_NO_DIF:
if ((lpfc_cmd->seg_cnt + 2) > phba->cfg_total_seg_cnt)
goto err;
num_bde = lpfc_bg_setup_bpl(phba, scsi_cmnd, bpl,
datasegcnt);
if (num_bde < 2)
goto err;
break;
case LPFC_PG_TYPE_DIF_BUF:
protsegcnt = dma_map_sg(&phba->pcidev->dev,
scsi_prot_sglist(scsi_cmnd),
scsi_prot_sg_count(scsi_cmnd), datadir);
if (unlikely(!protsegcnt)) {
scsi_dma_unmap(scsi_cmnd);
return 1;
}
lpfc_cmd->prot_seg_cnt = protsegcnt;
if ((lpfc_cmd->prot_seg_cnt * 4) >
(phba->cfg_total_seg_cnt - 2))
goto err;
num_bde = lpfc_bg_setup_bpl_prot(phba, scsi_cmnd, bpl,
datasegcnt, protsegcnt);
if ((num_bde < 3) ||
(num_bde > phba->cfg_total_seg_cnt))
goto err;
break;
case LPFC_PG_TYPE_INVALID:
default:
scsi_dma_unmap(scsi_cmnd);
lpfc_cmd->seg_cnt = 0;
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
fcpdl = lpfc_bg_scsi_adjust_dl(phba, lpfc_cmd);
fcp_cmnd->fcpDl = be32_to_cpu(fcpdl);
iocb_cmd->un.fcpi.fcpi_parm = fcpdl;
return 0;
err:
if (lpfc_cmd->seg_cnt)
scsi_dma_unmap(scsi_cmnd);
if (lpfc_cmd->prot_seg_cnt)
dma_unmap_sg(&phba->pcidev->dev, scsi_prot_sglist(scsi_cmnd),
scsi_prot_sg_count(scsi_cmnd),
scsi_cmnd->sc_data_direction);
lpfc_printf_log(phba, KERN_ERR, LOG_FCP,
"9023 Cannot setup S/G List for HBA"
"IO segs %d/%d BPL %d SCSI %d: %d %d\n",
lpfc_cmd->seg_cnt, lpfc_cmd->prot_seg_cnt,
phba->cfg_total_seg_cnt, phba->cfg_sg_seg_cnt,
prot_group_type, num_bde);
lpfc_cmd->seg_cnt = 0;
lpfc_cmd->prot_seg_cnt = 0;
return 1;
}
static uint16_t
lpfc_bg_crc(uint8_t *data, int count)
{
uint16_t crc = 0;
uint16_t x;
crc = crc_t10dif(data, count);
x = cpu_to_be16(crc);
return x;
}
static uint16_t
lpfc_bg_csum(uint8_t *data, int count)
{
uint16_t ret;
ret = ip_compute_csum(data, count);
return ret;
}
static void
lpfc_calc_bg_err(struct lpfc_hba *phba, struct lpfc_scsi_buf *lpfc_cmd)
{
struct scatterlist *sgpe;
struct scatterlist *sgde;
struct scsi_cmnd *cmd = lpfc_cmd->pCmd;
struct scsi_dif_tuple *src = NULL;
uint8_t *data_src = NULL;
uint16_t guard_tag;
uint16_t start_app_tag, app_tag;
uint32_t start_ref_tag, ref_tag;
int prot, protsegcnt;
int err_type, len, data_len;
int chk_ref, chk_app, chk_guard;
uint16_t sum;
unsigned blksize;
err_type = BGS_GUARD_ERR_MASK;
sum = 0;
guard_tag = 0;
prot = scsi_get_prot_op(cmd);
if ((prot == SCSI_PROT_READ_STRIP) ||
(prot == SCSI_PROT_WRITE_INSERT) ||
(prot == SCSI_PROT_NORMAL))
goto out;
chk_ref = 1;
chk_app = 0;
chk_guard = 0;
sgpe = scsi_prot_sglist(cmd);
protsegcnt = lpfc_cmd->prot_seg_cnt;
if (sgpe && protsegcnt) {
sgde = scsi_sglist(cmd);
blksize = lpfc_cmd_blksize(cmd);
data_src = (uint8_t *)sg_virt(sgde);
data_len = sgde->length;
if ((data_len & (blksize - 1)) == 0)
chk_guard = 1;
src = (struct scsi_dif_tuple *)sg_virt(sgpe);
start_ref_tag = (uint32_t)scsi_get_lba(cmd);
start_app_tag = src->app_tag;
len = sgpe->length;
while (src && protsegcnt) {
while (len) {
if ((src->ref_tag == T10_PI_REF_ESCAPE) ||
(src->app_tag == T10_PI_APP_ESCAPE)) {
start_ref_tag++;
goto skipit;
}
if (chk_guard) {
guard_tag = src->guard_tag;
if (lpfc_cmd_guard_csum(cmd))
sum = lpfc_bg_csum(data_src,
blksize);
else
sum = lpfc_bg_crc(data_src,
blksize);
if ((guard_tag != sum)) {
err_type = BGS_GUARD_ERR_MASK;
goto out;
}
}
ref_tag = be32_to_cpu(src->ref_tag);
if (chk_ref && (ref_tag != start_ref_tag)) {
err_type = BGS_REFTAG_ERR_MASK;
goto out;
}
start_ref_tag++;
app_tag = src->app_tag;
if (chk_app && (app_tag != start_app_tag)) {
err_type = BGS_APPTAG_ERR_MASK;
goto out;
}
skipit:
len -= sizeof(struct scsi_dif_tuple);
if (len < 0)
len = 0;
src++;
data_src += blksize;
data_len -= blksize;
if (chk_guard && (data_len == 0)) {
chk_guard = 0;
sgde = sg_next(sgde);
if (!sgde)
goto out;
data_src = (uint8_t *)sg_virt(sgde);
data_len = sgde->length;
if ((data_len & (blksize - 1)) == 0)
chk_guard = 1;
}
}
sgpe = sg_next(sgpe);
if (sgpe) {
src = (struct scsi_dif_tuple *)sg_virt(sgpe);
len = sgpe->length;
} else {
src = NULL;
}
protsegcnt--;
}
}
out:
if (err_type == BGS_GUARD_ERR_MASK) {
scsi_build_sense_buffer(1, cmd->sense_buffer, ILLEGAL_REQUEST,
0x10, 0x1);
cmd->result = DRIVER_SENSE << 24
| ScsiResult(DID_ABORT, SAM_STAT_CHECK_CONDITION);
phba->bg_guard_err_cnt++;
lpfc_printf_log(phba, KERN_WARNING, LOG_FCP | LOG_BG,
"9069 BLKGRD: LBA %lx grd_tag error %x != %x\n",
(unsigned long)scsi_get_lba(cmd),
sum, guard_tag);
} else if (err_type == BGS_REFTAG_ERR_MASK) {
scsi_build_sense_buffer(1, cmd->sense_buffer, ILLEGAL_REQUEST,
0x10, 0x3);
cmd->result = DRIVER_SENSE << 24
| ScsiResult(DID_ABORT, SAM_STAT_CHECK_CONDITION);
phba->bg_reftag_err_cnt++;
lpfc_printf_log(phba, KERN_WARNING, LOG_FCP | LOG_BG,
"9066 BLKGRD: LBA %lx ref_tag error %x != %x\n",
(unsigned long)scsi_get_lba(cmd),
ref_tag, start_ref_tag);
} else if (err_type == BGS_APPTAG_ERR_MASK) {
scsi_build_sense_buffer(1, cmd->sense_buffer, ILLEGAL_REQUEST,
0x10, 0x2);
cmd->result = DRIVER_SENSE << 24
| ScsiResult(DID_ABORT, SAM_STAT_CHECK_CONDITION);
phba->bg_apptag_err_cnt++;
lpfc_printf_log(phba, KERN_WARNING, LOG_FCP | LOG_BG,
"9041 BLKGRD: LBA %lx app_tag error %x != %x\n",
(unsigned long)scsi_get_lba(cmd),
app_tag, start_app_tag);
}
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
lpfc_printf_log(phba, KERN_WARNING, LOG_FCP | LOG_BG,
"9072 BLKGRD: Invalid BG Profile in cmd"
" 0x%x lba 0x%llx blk cnt 0x%x "
"bgstat=x%x bghm=x%x\n", cmd->cmnd[0],
(unsigned long long)scsi_get_lba(cmd),
blk_rq_sectors(cmd->request), bgstat, bghm);
ret = (-1);
goto out;
}
if (lpfc_bgs_get_uninit_dif_block(bgstat)) {
cmd->result = ScsiResult(DID_ERROR, 0);
lpfc_printf_log(phba, KERN_WARNING, LOG_FCP | LOG_BG,
"9073 BLKGRD: Invalid BG PDIF Block in cmd"
" 0x%x lba 0x%llx blk cnt 0x%x "
"bgstat=x%x bghm=x%x\n", cmd->cmnd[0],
(unsigned long long)scsi_get_lba(cmd),
blk_rq_sectors(cmd->request), bgstat, bghm);
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
lpfc_printf_log(phba, KERN_WARNING, LOG_FCP | LOG_BG,
"9055 BLKGRD: Guard Tag error in cmd"
" 0x%x lba 0x%llx blk cnt 0x%x "
"bgstat=x%x bghm=x%x\n", cmd->cmnd[0],
(unsigned long long)scsi_get_lba(cmd),
blk_rq_sectors(cmd->request), bgstat, bghm);
}
if (lpfc_bgs_get_reftag_err(bgstat)) {
ret = 1;
scsi_build_sense_buffer(1, cmd->sense_buffer, ILLEGAL_REQUEST,
0x10, 0x3);
cmd->result = DRIVER_SENSE << 24
| ScsiResult(DID_ABORT, SAM_STAT_CHECK_CONDITION);
phba->bg_reftag_err_cnt++;
lpfc_printf_log(phba, KERN_WARNING, LOG_FCP | LOG_BG,
"9056 BLKGRD: Ref Tag error in cmd"
" 0x%x lba 0x%llx blk cnt 0x%x "
"bgstat=x%x bghm=x%x\n", cmd->cmnd[0],
(unsigned long long)scsi_get_lba(cmd),
blk_rq_sectors(cmd->request), bgstat, bghm);
}
if (lpfc_bgs_get_apptag_err(bgstat)) {
ret = 1;
scsi_build_sense_buffer(1, cmd->sense_buffer, ILLEGAL_REQUEST,
0x10, 0x2);
cmd->result = DRIVER_SENSE << 24
| ScsiResult(DID_ABORT, SAM_STAT_CHECK_CONDITION);
phba->bg_apptag_err_cnt++;
lpfc_printf_log(phba, KERN_WARNING, LOG_FCP | LOG_BG,
"9061 BLKGRD: App Tag error in cmd"
" 0x%x lba 0x%llx blk cnt 0x%x "
"bgstat=x%x bghm=x%x\n", cmd->cmnd[0],
(unsigned long long)scsi_get_lba(cmd),
blk_rq_sectors(cmd->request), bgstat, bghm);
}
if (lpfc_bgs_get_hi_water_mark_present(bgstat)) {
cmd->sense_buffer[7] = 0xc;
cmd->sense_buffer[8] = 0;
cmd->sense_buffer[9] = 0xa;
cmd->sense_buffer[10] = 0x80;
switch (scsi_get_prot_op(cmd)) {
case SCSI_PROT_READ_INSERT:
case SCSI_PROT_WRITE_STRIP:
bghm /= cmd->device->sector_size;
break;
case SCSI_PROT_READ_STRIP:
case SCSI_PROT_WRITE_INSERT:
case SCSI_PROT_READ_PASS:
case SCSI_PROT_WRITE_PASS:
bghm /= (cmd->device->sector_size +
sizeof(struct scsi_dif_tuple));
break;
}
failing_sector = scsi_get_lba(cmd);
failing_sector += bghm;
put_unaligned_be64(failing_sector, &cmd->sense_buffer[12]);
}
if (!ret) {
lpfc_printf_log(phba, KERN_WARNING, LOG_FCP | LOG_BG,
"9057 BLKGRD: Unknown error in cmd"
" 0x%x lba 0x%llx blk cnt 0x%x "
"bgstat=x%x bghm=x%x\n", cmd->cmnd[0],
(unsigned long long)scsi_get_lba(cmd),
blk_rq_sectors(cmd->request), bgstat, bghm);
lpfc_calc_bg_err(phba, lpfc_cmd);
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
if (unlikely(nseg <= 0))
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
lpfc_cmd->seg_cnt = 0;
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
bf_set(lpfc_sli4_sge_type, sgl, LPFC_SGE_TYPE_DATA);
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
if ((phba->cfg_fof) && ((struct lpfc_device_data *)
scsi_cmnd->device->hostdata)->oas_enabled) {
lpfc_cmd->cur_iocbq.iocb_flag |= (LPFC_IO_OAS | LPFC_IO_FOF);
lpfc_cmd->cur_iocbq.priority = ((struct lpfc_device_data *)
scsi_cmnd->device->hostdata)->priority;
}
return 0;
}
static int
lpfc_bg_scsi_prep_dma_buf_s4(struct lpfc_hba *phba,
struct lpfc_scsi_buf *lpfc_cmd)
{
struct scsi_cmnd *scsi_cmnd = lpfc_cmd->pCmd;
struct fcp_cmnd *fcp_cmnd = lpfc_cmd->fcp_cmnd;
struct sli4_sge *sgl = (struct sli4_sge *)(lpfc_cmd->fcp_bpl);
IOCB_t *iocb_cmd = &lpfc_cmd->cur_iocbq.iocb;
uint32_t num_sge = 0;
int datasegcnt, protsegcnt, datadir = scsi_cmnd->sc_data_direction;
int prot_group_type = 0;
int fcpdl;
if (scsi_sg_count(scsi_cmnd)) {
datasegcnt = dma_map_sg(&phba->pcidev->dev,
scsi_sglist(scsi_cmnd),
scsi_sg_count(scsi_cmnd), datadir);
if (unlikely(!datasegcnt))
return 1;
sgl += 1;
sgl->word2 = le32_to_cpu(sgl->word2);
bf_set(lpfc_sli4_sge_last, sgl, 0);
sgl->word2 = cpu_to_le32(sgl->word2);
sgl += 1;
lpfc_cmd->seg_cnt = datasegcnt;
if (lpfc_cmd->seg_cnt > phba->cfg_sg_seg_cnt)
goto err;
prot_group_type = lpfc_prot_group_type(phba, scsi_cmnd);
switch (prot_group_type) {
case LPFC_PG_TYPE_NO_DIF:
if ((lpfc_cmd->seg_cnt + 1) > phba->cfg_total_seg_cnt)
goto err;
num_sge = lpfc_bg_setup_sgl(phba, scsi_cmnd, sgl,
datasegcnt);
if (num_sge < 2)
goto err;
break;
case LPFC_PG_TYPE_DIF_BUF:
protsegcnt = dma_map_sg(&phba->pcidev->dev,
scsi_prot_sglist(scsi_cmnd),
scsi_prot_sg_count(scsi_cmnd), datadir);
if (unlikely(!protsegcnt)) {
scsi_dma_unmap(scsi_cmnd);
return 1;
}
lpfc_cmd->prot_seg_cnt = protsegcnt;
if ((lpfc_cmd->prot_seg_cnt * 3) >
(phba->cfg_total_seg_cnt - 2))
goto err;
num_sge = lpfc_bg_setup_sgl_prot(phba, scsi_cmnd, sgl,
datasegcnt, protsegcnt);
if ((num_sge < 3) ||
(num_sge > phba->cfg_total_seg_cnt))
goto err;
break;
case LPFC_PG_TYPE_INVALID:
default:
scsi_dma_unmap(scsi_cmnd);
lpfc_cmd->seg_cnt = 0;
lpfc_printf_log(phba, KERN_ERR, LOG_FCP,
"9083 Unexpected protection group %i\n",
prot_group_type);
return 1;
}
}
switch (scsi_get_prot_op(scsi_cmnd)) {
case SCSI_PROT_WRITE_STRIP:
case SCSI_PROT_READ_STRIP:
lpfc_cmd->cur_iocbq.iocb_flag |= LPFC_IO_DIF_STRIP;
break;
case SCSI_PROT_WRITE_INSERT:
case SCSI_PROT_READ_INSERT:
lpfc_cmd->cur_iocbq.iocb_flag |= LPFC_IO_DIF_INSERT;
break;
case SCSI_PROT_WRITE_PASS:
case SCSI_PROT_READ_PASS:
lpfc_cmd->cur_iocbq.iocb_flag |= LPFC_IO_DIF_PASS;
break;
}
fcpdl = lpfc_bg_scsi_adjust_dl(phba, lpfc_cmd);
fcp_cmnd->fcpDl = be32_to_cpu(fcpdl);
iocb_cmd->un.fcpi.fcpi_parm = fcpdl;
if ((phba->cfg_fof) && ((struct lpfc_device_data *)
scsi_cmnd->device->hostdata)->oas_enabled)
lpfc_cmd->cur_iocbq.iocb_flag |= (LPFC_IO_OAS | LPFC_IO_FOF);
return 0;
err:
if (lpfc_cmd->seg_cnt)
scsi_dma_unmap(scsi_cmnd);
if (lpfc_cmd->prot_seg_cnt)
dma_unmap_sg(&phba->pcidev->dev, scsi_prot_sglist(scsi_cmnd),
scsi_prot_sg_count(scsi_cmnd),
scsi_cmnd->sc_data_direction);
lpfc_printf_log(phba, KERN_ERR, LOG_FCP,
"9084 Cannot setup S/G List for HBA"
"IO segs %d/%d SGL %d SCSI %d: %d %d\n",
lpfc_cmd->seg_cnt, lpfc_cmd->prot_seg_cnt,
phba->cfg_total_seg_cnt, phba->cfg_sg_seg_cnt,
prot_group_type, num_sge);
lpfc_cmd->seg_cnt = 0;
lpfc_cmd->prot_seg_cnt = 0;
return 1;
}
static inline int
lpfc_scsi_prep_dma_buf(struct lpfc_hba *phba, struct lpfc_scsi_buf *lpfc_cmd)
{
return phba->lpfc_scsi_prep_dma_buf(phba, lpfc_cmd);
}
static inline int
lpfc_bg_scsi_prep_dma_buf(struct lpfc_hba *phba, struct lpfc_scsi_buf *lpfc_cmd)
{
return phba->lpfc_bg_scsi_prep_dma_buf(phba, lpfc_cmd);
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
struct lpfc_hba *phba = vport->phba;
struct scsi_cmnd *cmnd = lpfc_cmd->pCmd;
struct fcp_cmnd *fcpcmd = lpfc_cmd->fcp_cmnd;
struct fcp_rsp *fcprsp = lpfc_cmd->fcp_rsp;
uint32_t fcpi_parm = rsp_iocb->iocb.un.fcpi.fcpi_parm;
uint32_t resp_info = fcprsp->rspStatus2;
uint32_t scsi_status = fcprsp->rspStatus3;
uint32_t *lp;
uint32_t host_status = DID_OK;
uint32_t rsplen = 0;
uint32_t fcpDl;
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
"tgt x%x lun x%llx cmnd x%x rsplen x%x\n",
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
"tgt x%x lun x%llx cmnd x%x rspInfo3 x%x\n",
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
if (!scsi_status && (resp_info & RESID_UNDER)) {
if (vport->cfg_log_verbose & LOG_FCP)
logit = LOG_FCP_ERROR;
if (vport->cfg_log_verbose & LOG_FCP_UNDER)
logit = LOG_FCP_UNDER;
}
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
fcpDl = be32_to_cpu(fcpcmd->fcpDl);
if (resp_info & RESID_UNDER) {
scsi_set_resid(cmnd, be32_to_cpu(fcprsp->rspResId));
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP_UNDER,
"9025 FCP Read Underrun, expected %d, "
"residual %d Data: x%x x%x x%x\n",
fcpDl,
scsi_get_resid(cmnd), fcpi_parm, cmnd->cmnd[0],
cmnd->underflow);
if ((cmnd->sc_data_direction == DMA_FROM_DEVICE) &&
fcpi_parm &&
(scsi_get_resid(cmnd) != fcpi_parm)) {
lpfc_printf_vlog(vport, KERN_WARNING,
LOG_FCP | LOG_FCP_ERROR,
"9026 FCP Read Check Error "
"and Underrun Data: x%x x%x x%x x%x\n",
fcpDl,
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
} else if (fcpi_parm) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP | LOG_FCP_ERROR,
"9029 FCP %s Check Error xri x%x Data: "
"x%x x%x x%x x%x x%x\n",
((cmnd->sc_data_direction == DMA_FROM_DEVICE) ?
"Read" : "Write"),
((phba->sli_rev == LPFC_SLI_REV4) ?
lpfc_cmd->cur_iocbq.sli4_xritag :
rsp_iocb->iocb.ulpContext),
fcpDl, be32_to_cpu(fcprsp->rspResId),
fcpi_parm, cmnd->cmnd[0], scsi_status);
if (fcpi_parm > fcpDl)
goto out;
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
int lpfc_sli4_scmd_to_wqidx_distr(struct lpfc_hba *phba,
struct lpfc_scsi_buf *lpfc_cmd)
{
struct scsi_cmnd *cmnd = lpfc_cmd->pCmd;
struct lpfc_vector_map_info *cpup;
int chann, cpu;
uint32_t tag;
uint16_t hwq;
if (cmnd && shost_use_blk_mq(cmnd->device->host)) {
tag = blk_mq_unique_tag(cmnd->request);
hwq = blk_mq_unique_tag_to_hwq(tag);
return hwq;
}
if (phba->cfg_fcp_io_sched == LPFC_FCP_SCHED_BY_CPU
&& phba->cfg_fcp_io_channel > 1) {
cpu = smp_processor_id();
if (cpu < phba->sli4_hba.num_present_cpu) {
cpup = phba->sli4_hba.cpu_map;
cpup += cpu;
return cpup->channel_id;
}
}
chann = atomic_add_return(1, &phba->fcp_qidx);
chann = chann % phba->cfg_fcp_io_channel;
return chann;
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
int depth;
unsigned long flags;
struct lpfc_fast_path_event *fast_path_evt;
struct Scsi_Host *shost;
uint32_t logit = LOG_FCP;
atomic_inc(&phba->fc4ScsiIoCmpls);
cmd = lpfc_cmd->pCmd;
if (!cmd)
return;
shost = cmd->device->host;
lpfc_cmd->result = (pIocbOut->iocb.un.ulpWord[4] & IOERR_PARAM_MASK);
lpfc_cmd->status = pIocbOut->iocb.ulpStatus;
lpfc_cmd->exch_busy = pIocbOut->iocb_flag & LPFC_EXCHANGE_BUSY;
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
if (lpfc_cmd->prot_data_type) {
struct scsi_dif_tuple *src = NULL;
src = (struct scsi_dif_tuple *)lpfc_cmd->prot_data_segment;
switch (lpfc_cmd->prot_data_type) {
case LPFC_INJERR_REFTAG:
src->ref_tag =
lpfc_cmd->prot_data;
break;
case LPFC_INJERR_APPTAG:
src->app_tag =
(uint16_t)lpfc_cmd->prot_data;
break;
case LPFC_INJERR_GUARD:
src->guard_tag =
(uint16_t)lpfc_cmd->prot_data;
break;
default:
break;
}
lpfc_cmd->prot_data = 0;
lpfc_cmd->prot_data_type = 0;
lpfc_cmd->prot_data_segment = NULL;
}
#endif
if (pnode && NLP_CHK_NODE_ACT(pnode))
atomic_dec(&pnode->cmd_pending);
if (lpfc_cmd->status) {
if (lpfc_cmd->status == IOSTAT_LOCAL_REJECT &&
(lpfc_cmd->result & IOERR_DRVR_MASK))
lpfc_cmd->status = IOSTAT_DRIVER_REJECT;
else if (lpfc_cmd->status >= IOSTAT_CNT)
lpfc_cmd->status = IOSTAT_DEFAULT;
if (lpfc_cmd->status == IOSTAT_FCP_RSP_ERROR &&
!lpfc_cmd->fcp_rsp->rspStatus3 &&
(lpfc_cmd->fcp_rsp->rspStatus2 & RESID_UNDER) &&
!(vport->cfg_log_verbose & LOG_FCP_UNDER))
logit = 0;
else
logit = LOG_FCP | LOG_FCP_UNDER;
lpfc_printf_vlog(vport, KERN_WARNING, logit,
"9030 FCP cmd x%x failed <%d/%lld> "
"status: x%x result: x%x "
"sid: x%x did: x%x oxid: x%x "
"Data: x%x x%x\n",
cmd->cmnd[0],
cmd->device ? cmd->device->id : 0xffff,
cmd->device ? cmd->device->lun : 0xffff,
lpfc_cmd->status, lpfc_cmd->result,
vport->fc_myDID,
(pnode) ? pnode->nlp_DID : 0,
phba->sli_rev == LPFC_SLI_REV4 ?
lpfc_cmd->cur_iocbq.sli4_xritag : 0xffff,
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
lpfc_cmd->cur_iocbq.sli4_lxritag,
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
"0710 Iodone <%d/%llu> cmd %p, error "
"x%x SNS x%x x%x Data: x%x x%x\n",
cmd->device->id, cmd->device->lun, cmd,
cmd->result, *lp, *(lp + 3), cmd->retries,
scsi_get_resid(cmd));
}
lpfc_update_stats(phba, lpfc_cmd);
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
spin_lock_irqsave(&phba->hbalock, flags);
lpfc_cmd->pCmd = NULL;
spin_unlock_irqrestore(&phba->hbalock, flags);
cmd->scsi_done(cmd);
spin_lock_irqsave(shost->host_lock, flags);
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
uint8_t *ptr;
bool sli4;
uint32_t fcpdl;
if (!pnode || !NLP_CHK_NODE_ACT(pnode))
return;
lpfc_cmd->fcp_rsp->rspSnsLen = 0;
lpfc_cmd->fcp_cmnd->fcpCntl2 = 0;
int_to_scsilun(lpfc_cmd->pCmd->device->lun,
&lpfc_cmd->fcp_cmnd->fcp_lun);
ptr = &fcp_cmnd->fcpCdb[0];
memcpy(ptr, scsi_cmnd->cmnd, scsi_cmnd->cmd_len);
if (scsi_cmnd->cmd_len < LPFC_FCP_CDB_LEN) {
ptr += scsi_cmnd->cmd_len;
memset(ptr, 0, (LPFC_FCP_CDB_LEN - scsi_cmnd->cmd_len));
}
fcp_cmnd->fcpCntl1 = SIMPLE_Q;
sli4 = (phba->sli_rev == LPFC_SLI_REV4);
piocbq->iocb.un.fcpi.fcpi_XRdy = 0;
if (scsi_sg_count(scsi_cmnd)) {
if (datadir == DMA_TO_DEVICE) {
iocb_cmd->ulpCommand = CMD_FCP_IWRITE64_CR;
iocb_cmd->ulpPU = PARM_READ_CHECK;
if (vport->cfg_first_burst_size &&
(pnode->nlp_flag & NLP_FIRSTBURST)) {
fcpdl = scsi_bufflen(scsi_cmnd);
if (fcpdl < vport->cfg_first_burst_size)
piocbq->iocb.un.fcpi.fcpi_XRdy = fcpdl;
else
piocbq->iocb.un.fcpi.fcpi_XRdy =
vport->cfg_first_burst_size;
}
fcp_cmnd->fcpCntl3 = WRITE_DATA;
atomic_inc(&phba->fc4ScsiOutputRequests);
} else {
iocb_cmd->ulpCommand = CMD_FCP_IREAD64_CR;
iocb_cmd->ulpPU = PARM_READ_CHECK;
fcp_cmnd->fcpCntl3 = READ_DATA;
atomic_inc(&phba->fc4ScsiInputRequests);
}
} else {
iocb_cmd->ulpCommand = CMD_FCP_ICMND64_CR;
iocb_cmd->un.fcpi.fcpi_parm = 0;
iocb_cmd->ulpPU = 0;
fcp_cmnd->fcpCntl3 = 0;
atomic_inc(&phba->fc4ScsiControlRequests);
}
if (phba->sli_rev == 3 &&
!(phba->sli3_options & LPFC_SLI3_BG_ENABLED))
lpfc_fcpcmd_to_iocb(iocb_cmd->unsli3.fcp_ext.icd, fcp_cmnd);
piocbq->iocb.ulpContext = pnode->nlp_rpi;
if (sli4)
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
uint64_t lun,
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
piocb->ulpFCP2Rcvy = (ndlp->nlp_fcp_info & NLP_FCP_2_DEVICE) ? 1 : 0;
piocb->ulpClass = (ndlp->nlp_fcp_info & 0x0f);
piocb->ulpPU = 0;
piocb->un.fcpi.fcpi_parm = 0;
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
phba->lpfc_bg_scsi_prep_dma_buf = lpfc_bg_scsi_prep_dma_buf_s3;
phba->lpfc_release_scsi_buf = lpfc_release_scsi_buf_s3;
phba->lpfc_get_scsi_buf = lpfc_get_scsi_buf_s3;
break;
case LPFC_PCI_DEV_OC:
phba->lpfc_new_scsi_buf = lpfc_new_scsi_buf_s4;
phba->lpfc_scsi_prep_dma_buf = lpfc_scsi_prep_dma_buf_s4;
phba->lpfc_bg_scsi_prep_dma_buf = lpfc_bg_scsi_prep_dma_buf_s4;
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
int len, link_speed = 0;
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
link_speed = lpfc_sli_port_speed_get(phba);
if (link_speed != 0)
snprintf(lpfcinfobuf + len, 384-len,
" Logical Link Speed: %d Mbps", link_speed);
}
return lpfcinfobuf;
}
static __inline__ void lpfc_poll_rearm_timer(struct lpfc_hba * phba)
{
unsigned long poll_tmo_expires =
(jiffies + msecs_to_jiffies(phba->cfg_poll_tmo));
if (!list_empty(&phba->sli.sli3_ring[LPFC_FCP_RING].txcmplq))
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
&phba->sli.sli3_ring[LPFC_FCP_RING], HA_R0RE_REQ);
if (phba->cfg_poll & DISABLE_FCP_RING_INT)
lpfc_poll_rearm_timer(phba);
}
}
static int
lpfc_queuecommand(struct Scsi_Host *shost, struct scsi_cmnd *cmnd)
{
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
struct lpfc_rport_data *rdata;
struct lpfc_nodelist *ndlp;
struct lpfc_scsi_buf *lpfc_cmd;
struct fc_rport *rport = starget_to_rport(scsi_target(cmnd->device));
int err;
rdata = lpfc_rport_data_from_scsi_device(cmnd->device);
err = fc_remote_port_chkready(rport);
if (err) {
cmnd->result = err;
goto out_fail_command;
}
ndlp = rdata->pnode;
if ((scsi_get_prot_op(cmnd) != SCSI_PROT_NORMAL) &&
(!(phba->sli3_options & LPFC_SLI3_BG_ENABLED))) {
lpfc_printf_log(phba, KERN_ERR, LOG_BG,
"9058 BLKGRD: ERROR: rcvd protected cmd:%02x"
" op:%02x str=%s without registering for"
" BlockGuard - Rejecting command\n",
cmnd->cmnd[0], scsi_get_prot_op(cmnd),
dif_op_str[scsi_get_prot_op(cmnd)]);
goto out_fail_command;
}
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp))
goto out_tgt_busy;
if (atomic_read(&ndlp->cmd_pending) >= ndlp->cmd_qdepth)
goto out_tgt_busy;
lpfc_cmd = lpfc_get_scsi_buf(phba, ndlp);
if (lpfc_cmd == NULL) {
lpfc_rampdown_queue_depth(phba);
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP_ERROR,
"0707 driver's buffer pool is empty, "
"IO busied\n");
goto out_host_busy;
}
lpfc_cmd->pCmd = cmnd;
lpfc_cmd->rdata = rdata;
lpfc_cmd->timeout = 0;
lpfc_cmd->start_time = jiffies;
cmnd->host_scribble = (unsigned char *)lpfc_cmd;
if (scsi_get_prot_op(cmnd) != SCSI_PROT_NORMAL) {
if (vport->phba->cfg_enable_bg) {
lpfc_printf_vlog(vport,
KERN_INFO, LOG_SCSI_CMD,
"9033 BLKGRD: rcvd %s cmd:x%x "
"sector x%llx cnt %u pt %x\n",
dif_op_str[scsi_get_prot_op(cmnd)],
cmnd->cmnd[0],
(unsigned long long)scsi_get_lba(cmnd),
blk_rq_sectors(cmnd->request),
(cmnd->cmnd[1]>>5));
}
err = lpfc_bg_scsi_prep_dma_buf(phba, lpfc_cmd);
} else {
if (vport->phba->cfg_enable_bg) {
lpfc_printf_vlog(vport,
KERN_INFO, LOG_SCSI_CMD,
"9038 BLKGRD: rcvd PROT_NORMAL cmd: "
"x%x sector x%llx cnt %u pt %x\n",
cmnd->cmnd[0],
(unsigned long long)scsi_get_lba(cmnd),
blk_rq_sectors(cmnd->request),
(cmnd->cmnd[1]>>5));
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
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"3376 FCP could not issue IOCB err %x"
"FCP cmd x%x <%d/%llu> "
"sid: x%x did: x%x oxid: x%x "
"Data: x%x x%x x%x x%x\n",
err, cmnd->cmnd[0],
cmnd->device ? cmnd->device->id : 0xffff,
cmnd->device ? cmnd->device->lun : (u64) -1,
vport->fc_myDID, ndlp->nlp_DID,
phba->sli_rev == LPFC_SLI_REV4 ?
lpfc_cmd->cur_iocbq.sli4_xritag : 0xffff,
lpfc_cmd->cur_iocbq.iocb.ulpContext,
lpfc_cmd->cur_iocbq.iocb.ulpIoTag,
lpfc_cmd->cur_iocbq.iocb.ulpTimeout,
(uint32_t)
(cmnd->request->timeout / 1000));
switch (lpfc_cmd->fcp_cmnd->fcpCntl3) {
case WRITE_DATA:
atomic_dec(&phba->fc4ScsiOutputRequests);
break;
case READ_DATA:
atomic_dec(&phba->fc4ScsiInputRequests);
break;
default:
atomic_dec(&phba->fc4ScsiControlRequests);
}
goto out_host_busy_free_buf;
}
if (phba->cfg_poll & ENABLE_FCP_RING_POLLING) {
lpfc_sli_handle_fast_ring_event(phba,
&phba->sli.sli3_ring[LPFC_FCP_RING], HA_R0RE_REQ);
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
cmnd->scsi_done(cmnd);
return 0;
}
static int
lpfc_abort_handler(struct scsi_cmnd *cmnd)
{
struct Scsi_Host *shost = cmnd->device->host;
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
struct lpfc_iocbq *iocb;
struct lpfc_iocbq *abtsiocb;
struct lpfc_scsi_buf *lpfc_cmd;
IOCB_t *cmd, *icmd;
int ret = SUCCESS, status = 0;
struct lpfc_sli_ring *pring_s4;
int ret_val;
unsigned long flags, iflags;
DECLARE_WAIT_QUEUE_HEAD_ONSTACK(waitq);
status = fc_block_scsi_eh(cmnd);
if (status != 0 && status != SUCCESS)
return status;
spin_lock_irqsave(&phba->hbalock, flags);
if (phba->hba_flag & HBA_FCP_IOQ_FLUSH) {
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"3168 SCSI Layer abort requested I/O has been "
"flushed by LLD.\n");
return FAILED;
}
lpfc_cmd = (struct lpfc_scsi_buf *)cmnd->host_scribble;
if (!lpfc_cmd || !lpfc_cmd->pCmd) {
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"2873 SCSI Layer I/O Abort Request IO CMPL Status "
"x%x ID %d LUN %llu\n",
SUCCESS, cmnd->device->id, cmnd->device->lun);
return SUCCESS;
}
iocb = &lpfc_cmd->cur_iocbq;
if (!(iocb->iocb_flag & LPFC_IO_ON_TXCMPLQ)) {
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"3169 SCSI Layer abort requested I/O has been "
"cancelled by LLD.\n");
return FAILED;
}
if (lpfc_cmd->pCmd != cmnd) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"3170 SCSI Layer abort requested I/O has been "
"completed by LLD.\n");
goto out_unlock;
}
BUG_ON(iocb->context1 != lpfc_cmd);
if (iocb->iocb_flag & LPFC_DRIVER_ABORTED) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"3389 SCSI Layer I/O Abort Request is pending\n");
spin_unlock_irqrestore(&phba->hbalock, flags);
goto wait_for_cmpl;
}
abtsiocb = __lpfc_sli_get_iocbq(phba);
if (abtsiocb == NULL) {
ret = FAILED;
goto out_unlock;
}
iocb->iocb_flag |= LPFC_DRIVER_ABORTED;
cmd = &iocb->iocb;
icmd = &abtsiocb->iocb;
icmd->un.acxri.abortType = ABORT_TYPE_ABTS;
icmd->un.acxri.abortContextTag = cmd->ulpContext;
if (phba->sli_rev == LPFC_SLI_REV4)
icmd->un.acxri.abortIoTag = iocb->sli4_xritag;
else
icmd->un.acxri.abortIoTag = cmd->ulpIoTag;
icmd->ulpLe = 1;
icmd->ulpClass = cmd->ulpClass;
abtsiocb->hba_wqidx = iocb->hba_wqidx;
abtsiocb->iocb_flag |= LPFC_USE_FCPWQIDX;
if (iocb->iocb_flag & LPFC_IO_FOF)
abtsiocb->iocb_flag |= LPFC_IO_FOF;
if (lpfc_is_link_up(phba))
icmd->ulpCommand = CMD_ABORT_XRI_CN;
else
icmd->ulpCommand = CMD_CLOSE_XRI_CN;
abtsiocb->iocb_cmpl = lpfc_sli_abort_fcp_cmpl;
abtsiocb->vport = vport;
if (phba->sli_rev == LPFC_SLI_REV4) {
pring_s4 = lpfc_sli4_calc_ring(phba, iocb);
if (pring_s4 == NULL) {
ret = FAILED;
goto out_unlock;
}
spin_lock_irqsave(&pring_s4->ring_lock, iflags);
ret_val = __lpfc_sli_issue_iocb(phba, pring_s4->ringno,
abtsiocb, 0);
spin_unlock_irqrestore(&pring_s4->ring_lock, iflags);
} else {
ret_val = __lpfc_sli_issue_iocb(phba, LPFC_FCP_RING,
abtsiocb, 0);
}
spin_unlock_irqrestore(&phba->hbalock, flags);
if (ret_val == IOCB_ERROR) {
lpfc_sli_release_iocbq(phba, abtsiocb);
ret = FAILED;
goto out;
}
if (phba->cfg_poll & DISABLE_FCP_RING_INT)
lpfc_sli_handle_fast_ring_event(phba,
&phba->sli.sli3_ring[LPFC_FCP_RING], HA_R0RE_REQ);
wait_for_cmpl:
lpfc_cmd->waitq = &waitq;
wait_event_timeout(waitq,
(lpfc_cmd->pCmd != cmnd),
msecs_to_jiffies(2*vport->cfg_devloss_tmo*1000));
spin_lock_irqsave(shost->host_lock, flags);
lpfc_cmd->waitq = NULL;
spin_unlock_irqrestore(shost->host_lock, flags);
if (lpfc_cmd->pCmd == cmnd) {
ret = FAILED;
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0748 abort handler timed out waiting "
"for aborting I/O (xri:x%x) to complete: "
"ret %#x, ID %d, LUN %llu\n",
iocb->sli4_xritag, ret,
cmnd->device->id, cmnd->device->lun);
}
goto out;
out_unlock:
spin_unlock_irqrestore(&phba->hbalock, flags);
out:
lpfc_printf_vlog(vport, KERN_WARNING, LOG_FCP,
"0749 SCSI Layer I/O Abort Request Status x%x ID %d "
"LUN %llu\n", ret, cmnd->device->id,
cmnd->device->lun);
return ret;
}
static char *
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
lpfc_check_fcp_rsp(struct lpfc_vport *vport, struct lpfc_scsi_buf *lpfc_cmd)
{
struct fcp_rsp *fcprsp = lpfc_cmd->fcp_rsp;
uint32_t rsp_info;
uint32_t rsp_len;
uint8_t rsp_info_code;
int ret = FAILED;
if (fcprsp == NULL)
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"0703 fcp_rsp is missing\n");
else {
rsp_info = fcprsp->rspStatus2;
rsp_len = be32_to_cpu(fcprsp->rspRspLen);
rsp_info_code = fcprsp->rspInfo3;
lpfc_printf_vlog(vport, KERN_INFO,
LOG_FCP,
"0706 fcp_rsp valid 0x%x,"
" rsp len=%d code 0x%x\n",
rsp_info,
rsp_len, rsp_info_code);
if ((fcprsp->rspStatus2&RSP_LEN_VALID) && (rsp_len == 8)) {
switch (rsp_info_code) {
case RSP_NO_FAILURE:
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"0715 Task Mgmt No Failure\n");
ret = SUCCESS;
break;
case RSP_TM_NOT_SUPPORTED:
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"0716 Task Mgmt Target "
"reject\n");
break;
case RSP_TM_NOT_COMPLETED:
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"0717 Task Mgmt Target "
"failed TM\n");
break;
case RSP_TM_INVALID_LU:
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"0718 Task Mgmt to invalid "
"LUN\n");
break;
}
}
}
return ret;
}
static int
lpfc_send_taskmgmt(struct lpfc_vport *vport, struct scsi_cmnd *cmnd,
unsigned int tgt_id, uint64_t lun_id,
uint8_t task_mgmt_cmd)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_scsi_buf *lpfc_cmd;
struct lpfc_iocbq *iocbq;
struct lpfc_iocbq *iocbqrsp;
struct lpfc_rport_data *rdata;
struct lpfc_nodelist *pnode;
int ret;
int status;
rdata = lpfc_rport_data_from_scsi_device(cmnd->device);
if (!rdata || !rdata->pnode || !NLP_CHK_NODE_ACT(rdata->pnode))
return FAILED;
pnode = rdata->pnode;
lpfc_cmd = lpfc_get_scsi_buf(phba, pnode);
if (lpfc_cmd == NULL)
return FAILED;
lpfc_cmd->timeout = phba->cfg_task_mgmt_tmo;
lpfc_cmd->rdata = rdata;
lpfc_cmd->pCmd = cmnd;
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
iocbq->iocb_cmpl = lpfc_tskmgmt_def_cmpl;
lpfc_printf_vlog(vport, KERN_INFO, LOG_FCP,
"0702 Issue %s to TGT %d LUN %llu "
"rpi x%x nlp_flag x%x Data: x%x x%x\n",
lpfc_taskmgmt_name(task_mgmt_cmd), tgt_id, lun_id,
pnode->nlp_rpi, pnode->nlp_flag, iocbq->sli4_xritag,
iocbq->iocb_flag);
status = lpfc_sli_issue_iocb_wait(phba, LPFC_FCP_RING,
iocbq, iocbqrsp, lpfc_cmd->timeout);
if ((status != IOCB_SUCCESS) ||
(iocbqrsp->iocb.ulpStatus != IOSTAT_SUCCESS)) {
if (status != IOCB_SUCCESS ||
iocbqrsp->iocb.ulpStatus != IOSTAT_FCP_RSP_ERROR)
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0727 TMF %s to TGT %d LUN %llu "
"failed (%d, %d) iocb_flag x%x\n",
lpfc_taskmgmt_name(task_mgmt_cmd),
tgt_id, lun_id,
iocbqrsp->iocb.ulpStatus,
iocbqrsp->iocb.un.ulpWord[4],
iocbq->iocb_flag);
if (status == IOCB_SUCCESS) {
if (iocbqrsp->iocb.ulpStatus == IOSTAT_FCP_RSP_ERROR)
ret = lpfc_check_fcp_rsp(vport, lpfc_cmd);
else
ret = FAILED;
} else if (status == IOCB_TIMEDOUT) {
ret = TIMEOUT_ERROR;
} else {
ret = FAILED;
}
} else
ret = SUCCESS;
lpfc_sli_release_iocbq(phba, iocbqrsp);
if (ret != TIMEOUT_ERROR)
lpfc_release_scsi_buf(phba, lpfc_cmd);
return ret;
}
static int
lpfc_chk_tgt_mapped(struct lpfc_vport *vport, struct scsi_cmnd *cmnd)
{
struct lpfc_rport_data *rdata;
struct lpfc_nodelist *pnode;
unsigned long later;
rdata = lpfc_rport_data_from_scsi_device(cmnd->device);
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
rdata = lpfc_rport_data_from_scsi_device(cmnd->device);
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
lpfc_sli_abort_taskmgmt(vport,
&phba->sli.sli3_ring[LPFC_FCP_RING],
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
struct lpfc_rport_data *rdata;
struct lpfc_nodelist *pnode;
unsigned tgt_id = cmnd->device->id;
uint64_t lun_id = cmnd->device->lun;
struct lpfc_scsi_event_header scsi_event;
int status;
rdata = lpfc_rport_data_from_scsi_device(cmnd->device);
if (!rdata || !rdata->pnode) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0798 Device Reset rport failure: rdata x%p\n",
rdata);
return FAILED;
}
pnode = rdata->pnode;
status = fc_block_scsi_eh(cmnd);
if (status != 0 && status != SUCCESS)
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
status = lpfc_send_taskmgmt(vport, cmnd, tgt_id, lun_id,
FCP_LUN_RESET);
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0713 SCSI layer issued Device Reset (%d, %llu) "
"return x%x\n", tgt_id, lun_id, status);
if (status == SUCCESS)
status = lpfc_reset_flush_io_context(vport, tgt_id, lun_id,
LPFC_CTX_LUN);
return status;
}
static int
lpfc_target_reset_handler(struct scsi_cmnd *cmnd)
{
struct Scsi_Host *shost = cmnd->device->host;
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_rport_data *rdata;
struct lpfc_nodelist *pnode;
unsigned tgt_id = cmnd->device->id;
uint64_t lun_id = cmnd->device->lun;
struct lpfc_scsi_event_header scsi_event;
int status;
rdata = lpfc_rport_data_from_scsi_device(cmnd->device);
if (!rdata) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0799 Target Reset rport failure: rdata x%p\n", rdata);
return FAILED;
}
pnode = rdata->pnode;
status = fc_block_scsi_eh(cmnd);
if (status != 0 && status != SUCCESS)
return status;
status = lpfc_chk_tgt_mapped(vport, cmnd);
if (status == FAILED) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0722 Target Reset rport failure: rdata x%p\n", rdata);
if (pnode) {
spin_lock_irq(shost->host_lock);
pnode->nlp_flag &= ~NLP_NPR_ADISC;
pnode->nlp_fcp_info &= ~NLP_FCP_2_DEVICE;
spin_unlock_irq(shost->host_lock);
}
lpfc_reset_flush_io_context(vport, tgt_id, lun_id,
LPFC_CTX_TGT);
return FAST_IO_FAIL;
}
scsi_event.event_type = FC_REG_SCSI_EVENT;
scsi_event.subcategory = LPFC_EVENT_TGTRESET;
scsi_event.lun = 0;
memcpy(scsi_event.wwpn, &pnode->nlp_portname, sizeof(struct lpfc_name));
memcpy(scsi_event.wwnn, &pnode->nlp_nodename, sizeof(struct lpfc_name));
fc_host_post_vendor_event(shost, fc_get_event_number(),
sizeof(scsi_event), (char *)&scsi_event, LPFC_NL_VENDOR_ID);
status = lpfc_send_taskmgmt(vport, cmnd, tgt_id, lun_id,
FCP_TARGET_RESET);
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"0723 SCSI layer issued Target Reset (%d, %llu) "
"return x%x\n", tgt_id, lun_id, status);
if (status == SUCCESS)
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
status = fc_block_scsi_eh(cmnd);
if (status != 0 && status != SUCCESS)
return status;
for (i = 0; i < LPFC_MAX_TARGET; i++) {
match = 0;
spin_lock_irq(shost->host_lock);
list_for_each_entry(ndlp, &vport->fc_nodes, nlp_listp) {
if (!NLP_CHK_NODE_ACT(ndlp))
continue;
if (vport->phba->cfg_fcp2_no_tgt_reset &&
(ndlp->nlp_fcp_info & NLP_FCP_2_DEVICE))
continue;
if (ndlp->nlp_state == NLP_STE_MAPPED_NODE &&
ndlp->nlp_sid == i &&
ndlp->rport &&
ndlp->nlp_type & NLP_FCP_TARGET) {
match = 1;
break;
}
}
spin_unlock_irq(shost->host_lock);
if (!match)
continue;
status = lpfc_send_taskmgmt(vport, cmnd,
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
lpfc_host_reset_handler(struct scsi_cmnd *cmnd)
{
struct Scsi_Host *shost = cmnd->device->host;
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int rc, ret = SUCCESS;
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"3172 SCSI layer issued Host Reset Data:\n");
lpfc_offline_prep(phba, LPFC_MBX_WAIT);
lpfc_offline(phba);
rc = lpfc_sli_brdrestart(phba);
if (rc)
ret = FAILED;
rc = lpfc_online(phba);
if (rc)
ret = FAILED;
lpfc_unblock_mgmt_io(phba);
if (ret == FAILED) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
"3323 Failed host reset, bring it offline\n");
lpfc_sli4_offline_eratt(phba);
}
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
struct lpfc_device_data *device_data;
unsigned long flags;
struct lpfc_name target_wwpn;
if (!rport || fc_remote_port_chkready(rport))
return -ENXIO;
if (phba->cfg_fof) {
u64_to_wwn(rport->port_name, target_wwpn.u.wwn);
spin_lock_irqsave(&phba->devicelock, flags);
device_data = __lpfc_get_device_data(phba,
&phba->luns,
&vport->fc_portname,
&target_wwpn,
sdev->lun);
if (!device_data) {
spin_unlock_irqrestore(&phba->devicelock, flags);
device_data = lpfc_create_device_data(phba,
&vport->fc_portname,
&target_wwpn,
sdev->lun,
phba->cfg_XLanePriority,
true);
if (!device_data)
return -ENOMEM;
spin_lock_irqsave(&phba->devicelock, flags);
list_add_tail(&device_data->listentry, &phba->luns);
}
device_data->rport_data = rport->dd_data;
device_data->available = true;
spin_unlock_irqrestore(&phba->devicelock, flags);
sdev->hostdata = device_data;
} else {
sdev->hostdata = rport->dd_data;
}
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
lpfc_printf_vlog(vport, KERN_ERR, LOG_FCP,
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
scsi_change_queue_depth(sdev, vport->cfg_lun_queue_depth);
if (phba->cfg_poll & ENABLE_FCP_RING_POLLING) {
lpfc_sli_handle_fast_ring_event(phba,
&phba->sli.sli3_ring[LPFC_FCP_RING], HA_R0RE_REQ);
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
unsigned long flags;
struct lpfc_device_data *device_data = sdev->hostdata;
atomic_dec(&phba->sdev_cnt);
if ((phba->cfg_fof) && (device_data)) {
spin_lock_irqsave(&phba->devicelock, flags);
device_data->available = false;
if (!device_data->oas_enabled)
lpfc_delete_device_data(phba, device_data);
spin_unlock_irqrestore(&phba->devicelock, flags);
}
sdev->hostdata = NULL;
return;
}
struct lpfc_device_data*
lpfc_create_device_data(struct lpfc_hba *phba, struct lpfc_name *vport_wwpn,
struct lpfc_name *target_wwpn, uint64_t lun,
uint32_t pri, bool atomic_create)
{
struct lpfc_device_data *lun_info;
int memory_flags;
if (unlikely(!phba) || !vport_wwpn || !target_wwpn ||
!(phba->cfg_fof))
return NULL;
if (atomic_create)
memory_flags = GFP_ATOMIC;
else
memory_flags = GFP_KERNEL;
lun_info = mempool_alloc(phba->device_data_mem_pool, memory_flags);
if (!lun_info)
return NULL;
INIT_LIST_HEAD(&lun_info->listentry);
lun_info->rport_data = NULL;
memcpy(&lun_info->device_id.vport_wwpn, vport_wwpn,
sizeof(struct lpfc_name));
memcpy(&lun_info->device_id.target_wwpn, target_wwpn,
sizeof(struct lpfc_name));
lun_info->device_id.lun = lun;
lun_info->oas_enabled = false;
lun_info->priority = pri;
lun_info->available = false;
return lun_info;
}
void
lpfc_delete_device_data(struct lpfc_hba *phba,
struct lpfc_device_data *lun_info)
{
if (unlikely(!phba) || !lun_info ||
!(phba->cfg_fof))
return;
if (!list_empty(&lun_info->listentry))
list_del(&lun_info->listentry);
mempool_free(lun_info, phba->device_data_mem_pool);
return;
}
struct lpfc_device_data*
__lpfc_get_device_data(struct lpfc_hba *phba, struct list_head *list,
struct lpfc_name *vport_wwpn,
struct lpfc_name *target_wwpn, uint64_t lun)
{
struct lpfc_device_data *lun_info;
if (unlikely(!phba) || !list || !vport_wwpn || !target_wwpn ||
!phba->cfg_fof)
return NULL;
list_for_each_entry(lun_info, list, listentry) {
if ((memcmp(&lun_info->device_id.vport_wwpn, vport_wwpn,
sizeof(struct lpfc_name)) == 0) &&
(memcmp(&lun_info->device_id.target_wwpn, target_wwpn,
sizeof(struct lpfc_name)) == 0) &&
(lun_info->device_id.lun == lun))
return lun_info;
}
return NULL;
}
bool
lpfc_find_next_oas_lun(struct lpfc_hba *phba, struct lpfc_name *vport_wwpn,
struct lpfc_name *target_wwpn, uint64_t *starting_lun,
struct lpfc_name *found_vport_wwpn,
struct lpfc_name *found_target_wwpn,
uint64_t *found_lun,
uint32_t *found_lun_status,
uint32_t *found_lun_pri)
{
unsigned long flags;
struct lpfc_device_data *lun_info;
struct lpfc_device_id *device_id;
uint64_t lun;
bool found = false;
if (unlikely(!phba) || !vport_wwpn || !target_wwpn ||
!starting_lun || !found_vport_wwpn ||
!found_target_wwpn || !found_lun || !found_lun_status ||
(*starting_lun == NO_MORE_OAS_LUN) ||
!phba->cfg_fof)
return false;
lun = *starting_lun;
*found_lun = NO_MORE_OAS_LUN;
*starting_lun = NO_MORE_OAS_LUN;
spin_lock_irqsave(&phba->devicelock, flags);
list_for_each_entry(lun_info, &phba->luns, listentry) {
if (((wwn_to_u64(vport_wwpn->u.wwn) == 0) ||
(memcmp(&lun_info->device_id.vport_wwpn, vport_wwpn,
sizeof(struct lpfc_name)) == 0)) &&
((wwn_to_u64(target_wwpn->u.wwn) == 0) ||
(memcmp(&lun_info->device_id.target_wwpn, target_wwpn,
sizeof(struct lpfc_name)) == 0)) &&
(lun_info->oas_enabled)) {
device_id = &lun_info->device_id;
if ((!found) &&
((lun == FIND_FIRST_OAS_LUN) ||
(device_id->lun == lun))) {
*found_lun = device_id->lun;
memcpy(found_vport_wwpn,
&device_id->vport_wwpn,
sizeof(struct lpfc_name));
memcpy(found_target_wwpn,
&device_id->target_wwpn,
sizeof(struct lpfc_name));
if (lun_info->available)
*found_lun_status =
OAS_LUN_STATUS_EXISTS;
else
*found_lun_status = 0;
*found_lun_pri = lun_info->priority;
if (phba->cfg_oas_flags & OAS_FIND_ANY_VPORT)
memset(vport_wwpn, 0x0,
sizeof(struct lpfc_name));
if (phba->cfg_oas_flags & OAS_FIND_ANY_TARGET)
memset(target_wwpn, 0x0,
sizeof(struct lpfc_name));
found = true;
} else if (found) {
*starting_lun = device_id->lun;
memcpy(vport_wwpn, &device_id->vport_wwpn,
sizeof(struct lpfc_name));
memcpy(target_wwpn, &device_id->target_wwpn,
sizeof(struct lpfc_name));
break;
}
}
}
spin_unlock_irqrestore(&phba->devicelock, flags);
return found;
}
bool
lpfc_enable_oas_lun(struct lpfc_hba *phba, struct lpfc_name *vport_wwpn,
struct lpfc_name *target_wwpn, uint64_t lun, uint8_t pri)
{
struct lpfc_device_data *lun_info;
unsigned long flags;
if (unlikely(!phba) || !vport_wwpn || !target_wwpn ||
!phba->cfg_fof)
return false;
spin_lock_irqsave(&phba->devicelock, flags);
lun_info = __lpfc_get_device_data(phba, &phba->luns, vport_wwpn,
target_wwpn, lun);
if (lun_info) {
if (!lun_info->oas_enabled)
lun_info->oas_enabled = true;
lun_info->priority = pri;
spin_unlock_irqrestore(&phba->devicelock, flags);
return true;
}
lun_info = lpfc_create_device_data(phba, vport_wwpn, target_wwpn, lun,
pri, false);
if (lun_info) {
lun_info->oas_enabled = true;
lun_info->priority = pri;
lun_info->available = false;
list_add_tail(&lun_info->listentry, &phba->luns);
spin_unlock_irqrestore(&phba->devicelock, flags);
return true;
}
spin_unlock_irqrestore(&phba->devicelock, flags);
return false;
}
bool
lpfc_disable_oas_lun(struct lpfc_hba *phba, struct lpfc_name *vport_wwpn,
struct lpfc_name *target_wwpn, uint64_t lun, uint8_t pri)
{
struct lpfc_device_data *lun_info;
unsigned long flags;
if (unlikely(!phba) || !vport_wwpn || !target_wwpn ||
!phba->cfg_fof)
return false;
spin_lock_irqsave(&phba->devicelock, flags);
lun_info = __lpfc_get_device_data(phba,
&phba->luns, vport_wwpn,
target_wwpn, lun);
if (lun_info) {
lun_info->oas_enabled = false;
lun_info->priority = pri;
if (!lun_info->available)
lpfc_delete_device_data(phba, lun_info);
spin_unlock_irqrestore(&phba->devicelock, flags);
return true;
}
spin_unlock_irqrestore(&phba->devicelock, flags);
return false;
}
static int
lpfc_no_command(struct Scsi_Host *shost, struct scsi_cmnd *cmnd)
{
return SCSI_MLQUEUE_HOST_BUSY;
}
static int
lpfc_no_handler(struct scsi_cmnd *cmnd)
{
return FAILED;
}
static int
lpfc_no_slave(struct scsi_device *sdev)
{
return -ENODEV;
}
