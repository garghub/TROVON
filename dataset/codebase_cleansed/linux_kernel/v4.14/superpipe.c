static void marshal_rele_to_resize(struct dk_cxlflash_release *release,
struct dk_cxlflash_resize *resize)
{
resize->hdr = release->hdr;
resize->context_id = release->context_id;
resize->rsrc_handle = release->rsrc_handle;
}
static void marshal_det_to_rele(struct dk_cxlflash_detach *detach,
struct dk_cxlflash_release *release)
{
release->hdr = detach->hdr;
release->context_id = detach->context_id;
}
static void marshal_udir_to_rele(struct dk_cxlflash_udirect *udirect,
struct dk_cxlflash_release *release)
{
release->hdr = udirect->hdr;
release->context_id = udirect->context_id;
release->rsrc_handle = udirect->rsrc_handle;
}
void cxlflash_free_errpage(void)
{
mutex_lock(&global.mutex);
if (global.err_page) {
__free_page(global.err_page);
global.err_page = NULL;
}
mutex_unlock(&global.mutex);
}
void cxlflash_stop_term_user_contexts(struct cxlflash_cfg *cfg)
{
struct device *dev = &cfg->dev->dev;
int i, found = true;
cxlflash_mark_contexts_error(cfg);
while (true) {
for (i = 0; i < MAX_CONTEXT; i++)
if (cfg->ctx_tbl[i]) {
found = true;
break;
}
if (!found && list_empty(&cfg->ctx_err_recovery))
return;
dev_dbg(dev, "%s: Wait for user contexts to quiesce...\n",
__func__);
wake_up_all(&cfg->reset_waitq);
ssleep(1);
found = false;
}
}
static struct ctx_info *find_error_context(struct cxlflash_cfg *cfg, u64 rctxid,
struct file *file)
{
struct ctx_info *ctxi;
list_for_each_entry(ctxi, &cfg->ctx_err_recovery, list)
if ((ctxi->ctxid == rctxid) || (ctxi->file == file))
return ctxi;
return NULL;
}
struct ctx_info *get_context(struct cxlflash_cfg *cfg, u64 rctxid,
void *arg, enum ctx_ctrl ctx_ctrl)
{
struct device *dev = &cfg->dev->dev;
struct ctx_info *ctxi = NULL;
struct lun_access *lun_access = NULL;
struct file *file = NULL;
struct llun_info *lli = arg;
u64 ctxid = DECODE_CTXID(rctxid);
int rc;
pid_t pid = current->tgid, ctxpid = 0;
if (ctx_ctrl & CTX_CTRL_FILE) {
lli = NULL;
file = (struct file *)arg;
}
if (ctx_ctrl & CTX_CTRL_CLONE)
pid = current->parent->tgid;
if (likely(ctxid < MAX_CONTEXT)) {
while (true) {
mutex_lock(&cfg->ctx_tbl_list_mutex);
ctxi = cfg->ctx_tbl[ctxid];
if (ctxi)
if ((file && (ctxi->file != file)) ||
(!file && (ctxi->ctxid != rctxid)))
ctxi = NULL;
if ((ctx_ctrl & CTX_CTRL_ERR) ||
(!ctxi && (ctx_ctrl & CTX_CTRL_ERR_FALLBACK)))
ctxi = find_error_context(cfg, rctxid, file);
if (!ctxi) {
mutex_unlock(&cfg->ctx_tbl_list_mutex);
goto out;
}
rc = mutex_trylock(&ctxi->mutex);
mutex_unlock(&cfg->ctx_tbl_list_mutex);
if (rc)
break;
}
if (ctxi->unavail)
goto denied;
ctxpid = ctxi->pid;
if (likely(!(ctx_ctrl & CTX_CTRL_NOPID)))
if (pid != ctxpid)
goto denied;
if (lli) {
list_for_each_entry(lun_access, &ctxi->luns, list)
if (lun_access->lli == lli)
goto out;
goto denied;
}
}
out:
dev_dbg(dev, "%s: rctxid=%016llx ctxinfo=%p ctxpid=%u pid=%u "
"ctx_ctrl=%u\n", __func__, rctxid, ctxi, ctxpid, pid,
ctx_ctrl);
return ctxi;
denied:
mutex_unlock(&ctxi->mutex);
ctxi = NULL;
goto out;
}
void put_context(struct ctx_info *ctxi)
{
mutex_unlock(&ctxi->mutex);
}
static int afu_attach(struct cxlflash_cfg *cfg, struct ctx_info *ctxi)
{
struct device *dev = &cfg->dev->dev;
struct afu *afu = cfg->afu;
struct sisl_ctrl_map __iomem *ctrl_map = ctxi->ctrl_map;
int rc = 0;
struct hwq *hwq = get_hwq(afu, PRIMARY_HWQ);
u64 val;
readq_be(&ctrl_map->mbox_r);
val = (SISL_CTX_CAP_READ_CMD | SISL_CTX_CAP_WRITE_CMD);
writeq_be(val, &ctrl_map->ctx_cap);
val = readq_be(&ctrl_map->ctx_cap);
if (val != (SISL_CTX_CAP_READ_CMD | SISL_CTX_CAP_WRITE_CMD)) {
dev_err(dev, "%s: ctx may be closed val=%016llx\n",
__func__, val);
rc = -EAGAIN;
goto out;
}
writeq_be((u64)ctxi->rht_start, &ctrl_map->rht_start);
val = SISL_RHT_CNT_ID((u64)MAX_RHT_PER_CONTEXT, (u64)(hwq->ctx_hndl));
writeq_be(val, &ctrl_map->rht_cnt_id);
out:
dev_dbg(dev, "%s: returning rc=%d\n", __func__, rc);
return rc;
}
static int read_cap16(struct scsi_device *sdev, struct llun_info *lli)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct glun_info *gli = lli->parent;
struct scsi_sense_hdr sshdr;
u8 *cmd_buf = NULL;
u8 *scsi_cmd = NULL;
u8 *sense_buf = NULL;
int rc = 0;
int result = 0;
int retry_cnt = 0;
u32 to = CMD_TIMEOUT * HZ;
retry:
cmd_buf = kzalloc(CMD_BUFSIZE, GFP_KERNEL);
scsi_cmd = kzalloc(MAX_COMMAND_SIZE, GFP_KERNEL);
sense_buf = kzalloc(SCSI_SENSE_BUFFERSIZE, GFP_KERNEL);
if (unlikely(!cmd_buf || !scsi_cmd || !sense_buf)) {
rc = -ENOMEM;
goto out;
}
scsi_cmd[0] = SERVICE_ACTION_IN_16;
scsi_cmd[1] = SAI_READ_CAPACITY_16;
put_unaligned_be32(CMD_BUFSIZE, &scsi_cmd[10]);
dev_dbg(dev, "%s: %ssending cmd(%02x)\n", __func__,
retry_cnt ? "re" : "", scsi_cmd[0]);
up_read(&cfg->ioctl_rwsem);
result = scsi_execute(sdev, scsi_cmd, DMA_FROM_DEVICE, cmd_buf,
CMD_BUFSIZE, sense_buf, &sshdr, to, CMD_RETRIES,
0, 0, NULL);
down_read(&cfg->ioctl_rwsem);
rc = check_state(cfg);
if (rc) {
dev_err(dev, "%s: Failed state result=%08x\n",
__func__, result);
rc = -ENODEV;
goto out;
}
if (driver_byte(result) == DRIVER_SENSE) {
result &= ~(0xFF<<24);
if (result & SAM_STAT_CHECK_CONDITION) {
switch (sshdr.sense_key) {
case NO_SENSE:
case RECOVERED_ERROR:
case NOT_READY:
result &= ~SAM_STAT_CHECK_CONDITION;
break;
case UNIT_ATTENTION:
switch (sshdr.asc) {
case 0x29:
case 0x2A:
case 0x3F:
if (retry_cnt++ < 1) {
kfree(cmd_buf);
kfree(scsi_cmd);
kfree(sense_buf);
goto retry;
}
}
break;
default:
break;
}
}
}
if (result) {
dev_err(dev, "%s: command failed, result=%08x\n",
__func__, result);
rc = -EIO;
goto out;
}
mutex_lock(&gli->mutex);
gli->max_lba = be64_to_cpu(*((__be64 *)&cmd_buf[0]));
gli->blk_len = be32_to_cpu(*((__be32 *)&cmd_buf[8]));
mutex_unlock(&gli->mutex);
out:
kfree(cmd_buf);
kfree(scsi_cmd);
kfree(sense_buf);
dev_dbg(dev, "%s: maxlba=%lld blklen=%d rc=%d\n",
__func__, gli->max_lba, gli->blk_len, rc);
return rc;
}
struct sisl_rht_entry *get_rhte(struct ctx_info *ctxi, res_hndl_t rhndl,
struct llun_info *lli)
{
struct cxlflash_cfg *cfg = ctxi->cfg;
struct device *dev = &cfg->dev->dev;
struct sisl_rht_entry *rhte = NULL;
if (unlikely(!ctxi->rht_start)) {
dev_dbg(dev, "%s: Context does not have allocated RHT\n",
__func__);
goto out;
}
if (unlikely(rhndl >= MAX_RHT_PER_CONTEXT)) {
dev_dbg(dev, "%s: Bad resource handle rhndl=%d\n",
__func__, rhndl);
goto out;
}
if (unlikely(ctxi->rht_lun[rhndl] != lli)) {
dev_dbg(dev, "%s: Bad resource handle LUN rhndl=%d\n",
__func__, rhndl);
goto out;
}
rhte = &ctxi->rht_start[rhndl];
if (unlikely(rhte->nmask == 0)) {
dev_dbg(dev, "%s: Unopened resource handle rhndl=%d\n",
__func__, rhndl);
rhte = NULL;
goto out;
}
out:
return rhte;
}
struct sisl_rht_entry *rhte_checkout(struct ctx_info *ctxi,
struct llun_info *lli)
{
struct cxlflash_cfg *cfg = ctxi->cfg;
struct device *dev = &cfg->dev->dev;
struct sisl_rht_entry *rhte = NULL;
int i;
for (i = 0; i < MAX_RHT_PER_CONTEXT; i++)
if (ctxi->rht_start[i].nmask == 0) {
rhte = &ctxi->rht_start[i];
ctxi->rht_out++;
break;
}
if (likely(rhte))
ctxi->rht_lun[i] = lli;
dev_dbg(dev, "%s: returning rhte=%p index=%d\n", __func__, rhte, i);
return rhte;
}
void rhte_checkin(struct ctx_info *ctxi,
struct sisl_rht_entry *rhte)
{
u32 rsrc_handle = rhte - ctxi->rht_start;
rhte->nmask = 0;
rhte->fp = 0;
ctxi->rht_out--;
ctxi->rht_lun[rsrc_handle] = NULL;
ctxi->rht_needs_ws[rsrc_handle] = false;
}
static void rht_format1(struct sisl_rht_entry *rhte, u64 lun_id, u32 perm,
u32 port_sel)
{
struct sisl_rht_entry_f1 dummy = { 0 };
struct sisl_rht_entry_f1 *rhte_f1 = (struct sisl_rht_entry_f1 *)rhte;
memset(rhte_f1, 0, sizeof(*rhte_f1));
rhte_f1->fp = SISL_RHT_FP(1U, 0);
dma_wmb();
rhte_f1->lun_id = lun_id;
dma_wmb();
dummy.valid = 0x80;
dummy.fp = SISL_RHT_FP(1U, perm);
dummy.port_sel = port_sel;
rhte_f1->dw = dummy.dw;
dma_wmb();
}
int cxlflash_lun_attach(struct glun_info *gli, enum lun_mode mode, bool locked)
{
int rc = 0;
if (!locked)
mutex_lock(&gli->mutex);
if (gli->mode == MODE_NONE)
gli->mode = mode;
else if (gli->mode != mode) {
pr_debug("%s: gli_mode=%d requested_mode=%d\n",
__func__, gli->mode, mode);
rc = -EINVAL;
goto out;
}
gli->users++;
WARN_ON(gli->users <= 0);
out:
pr_debug("%s: Returning rc=%d gli->mode=%u gli->users=%u\n",
__func__, rc, gli->mode, gli->users);
if (!locked)
mutex_unlock(&gli->mutex);
return rc;
}
void cxlflash_lun_detach(struct glun_info *gli)
{
mutex_lock(&gli->mutex);
WARN_ON(gli->mode == MODE_NONE);
if (--gli->users == 0) {
gli->mode = MODE_NONE;
cxlflash_ba_terminate(&gli->blka.ba_lun);
}
pr_debug("%s: gli->users=%u\n", __func__, gli->users);
WARN_ON(gli->users < 0);
mutex_unlock(&gli->mutex);
}
int _cxlflash_disk_release(struct scsi_device *sdev,
struct ctx_info *ctxi,
struct dk_cxlflash_release *release)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct llun_info *lli = sdev->hostdata;
struct glun_info *gli = lli->parent;
struct afu *afu = cfg->afu;
bool put_ctx = false;
struct dk_cxlflash_resize size;
res_hndl_t rhndl = release->rsrc_handle;
int rc = 0;
int rcr = 0;
u64 ctxid = DECODE_CTXID(release->context_id),
rctxid = release->context_id;
struct sisl_rht_entry *rhte;
struct sisl_rht_entry_f1 *rhte_f1;
dev_dbg(dev, "%s: ctxid=%llu rhndl=%llu gli->mode=%u gli->users=%u\n",
__func__, ctxid, release->rsrc_handle, gli->mode, gli->users);
if (!ctxi) {
ctxi = get_context(cfg, rctxid, lli, CTX_CTRL_ERR_FALLBACK);
if (unlikely(!ctxi)) {
dev_dbg(dev, "%s: Bad context ctxid=%llu\n",
__func__, ctxid);
rc = -EINVAL;
goto out;
}
put_ctx = true;
}
rhte = get_rhte(ctxi, rhndl, lli);
if (unlikely(!rhte)) {
dev_dbg(dev, "%s: Bad resource handle rhndl=%d\n",
__func__, rhndl);
rc = -EINVAL;
goto out;
}
switch (gli->mode) {
case MODE_VIRTUAL:
marshal_rele_to_resize(release, &size);
size.req_size = 0;
rc = _cxlflash_vlun_resize(sdev, ctxi, &size);
if (rc) {
dev_dbg(dev, "%s: resize failed rc %d\n", __func__, rc);
goto out;
}
break;
case MODE_PHYSICAL:
rhte_f1 = (struct sisl_rht_entry_f1 *)rhte;
rhte_f1->valid = 0;
dma_wmb();
rhte_f1->lun_id = 0;
dma_wmb();
rhte_f1->dw = 0;
dma_wmb();
if (!ctxi->err_recovery_active) {
rcr = cxlflash_afu_sync(afu, ctxid, rhndl, AFU_HW_SYNC);
if (unlikely(rcr))
dev_dbg(dev, "%s: AFU sync failed rc=%d\n",
__func__, rcr);
}
break;
default:
WARN(1, "Unsupported LUN mode!");
goto out;
}
rhte_checkin(ctxi, rhte);
cxlflash_lun_detach(gli);
out:
if (put_ctx)
put_context(ctxi);
dev_dbg(dev, "%s: returning rc=%d\n", __func__, rc);
return rc;
}
int cxlflash_disk_release(struct scsi_device *sdev,
struct dk_cxlflash_release *release)
{
return _cxlflash_disk_release(sdev, NULL, release);
}
static void destroy_context(struct cxlflash_cfg *cfg,
struct ctx_info *ctxi)
{
struct afu *afu = cfg->afu;
if (ctxi->initialized) {
WARN_ON(!list_empty(&ctxi->luns));
if (afu->afu_map && ctxi->ctrl_map) {
writeq_be(0, &ctxi->ctrl_map->rht_start);
writeq_be(0, &ctxi->ctrl_map->rht_cnt_id);
writeq_be(0, &ctxi->ctrl_map->ctx_cap);
}
}
free_page((ulong)ctxi->rht_start);
kfree(ctxi->rht_needs_ws);
kfree(ctxi->rht_lun);
kfree(ctxi);
}
static struct ctx_info *create_context(struct cxlflash_cfg *cfg)
{
struct device *dev = &cfg->dev->dev;
struct ctx_info *ctxi = NULL;
struct llun_info **lli = NULL;
u8 *ws = NULL;
struct sisl_rht_entry *rhte;
ctxi = kzalloc(sizeof(*ctxi), GFP_KERNEL);
lli = kzalloc((MAX_RHT_PER_CONTEXT * sizeof(*lli)), GFP_KERNEL);
ws = kzalloc((MAX_RHT_PER_CONTEXT * sizeof(*ws)), GFP_KERNEL);
if (unlikely(!ctxi || !lli || !ws)) {
dev_err(dev, "%s: Unable to allocate context\n", __func__);
goto err;
}
rhte = (struct sisl_rht_entry *)get_zeroed_page(GFP_KERNEL);
if (unlikely(!rhte)) {
dev_err(dev, "%s: Unable to allocate RHT\n", __func__);
goto err;
}
ctxi->rht_lun = lli;
ctxi->rht_needs_ws = ws;
ctxi->rht_start = rhte;
out:
return ctxi;
err:
kfree(ws);
kfree(lli);
kfree(ctxi);
ctxi = NULL;
goto out;
}
static void init_context(struct ctx_info *ctxi, struct cxlflash_cfg *cfg,
struct cxl_context *ctx, int ctxid, struct file *file,
u32 perms)
{
struct afu *afu = cfg->afu;
ctxi->rht_perms = perms;
ctxi->ctrl_map = &afu->afu_map->ctrls[ctxid].ctrl;
ctxi->ctxid = ENCODE_CTXID(ctxi, ctxid);
ctxi->pid = current->tgid;
ctxi->ctx = ctx;
ctxi->cfg = cfg;
ctxi->file = file;
ctxi->initialized = true;
mutex_init(&ctxi->mutex);
kref_init(&ctxi->kref);
INIT_LIST_HEAD(&ctxi->luns);
INIT_LIST_HEAD(&ctxi->list);
}
static void remove_context(struct kref *kref)
{
struct ctx_info *ctxi = container_of(kref, struct ctx_info, kref);
struct cxlflash_cfg *cfg = ctxi->cfg;
u64 ctxid = DECODE_CTXID(ctxi->ctxid);
WARN_ON(!mutex_is_locked(&ctxi->mutex));
ctxi->unavail = true;
mutex_unlock(&ctxi->mutex);
mutex_lock(&cfg->ctx_tbl_list_mutex);
mutex_lock(&ctxi->mutex);
if (!list_empty(&ctxi->list))
list_del(&ctxi->list);
cfg->ctx_tbl[ctxid] = NULL;
mutex_unlock(&cfg->ctx_tbl_list_mutex);
mutex_unlock(&ctxi->mutex);
destroy_context(cfg, ctxi);
}
static int _cxlflash_disk_detach(struct scsi_device *sdev,
struct ctx_info *ctxi,
struct dk_cxlflash_detach *detach)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct llun_info *lli = sdev->hostdata;
struct lun_access *lun_access, *t;
struct dk_cxlflash_release rel;
bool put_ctx = false;
int i;
int rc = 0;
u64 ctxid = DECODE_CTXID(detach->context_id),
rctxid = detach->context_id;
dev_dbg(dev, "%s: ctxid=%llu\n", __func__, ctxid);
if (!ctxi) {
ctxi = get_context(cfg, rctxid, lli, CTX_CTRL_ERR_FALLBACK);
if (unlikely(!ctxi)) {
dev_dbg(dev, "%s: Bad context ctxid=%llu\n",
__func__, ctxid);
rc = -EINVAL;
goto out;
}
put_ctx = true;
}
if (ctxi->rht_out) {
marshal_det_to_rele(detach, &rel);
for (i = 0; i < MAX_RHT_PER_CONTEXT; i++) {
if (ctxi->rht_lun[i] == lli) {
rel.rsrc_handle = i;
_cxlflash_disk_release(sdev, ctxi, &rel);
}
if (ctxi->rht_out == 0)
break;
}
}
list_for_each_entry_safe(lun_access, t, &ctxi->luns, list)
if (lun_access->lli == lli) {
list_del(&lun_access->list);
kfree(lun_access);
lun_access = NULL;
break;
}
if (kref_put(&ctxi->kref, remove_context))
put_ctx = false;
scsi_device_put(sdev);
out:
if (put_ctx)
put_context(ctxi);
dev_dbg(dev, "%s: returning rc=%d\n", __func__, rc);
return rc;
}
static int cxlflash_disk_detach(struct scsi_device *sdev,
struct dk_cxlflash_detach *detach)
{
return _cxlflash_disk_detach(sdev, NULL, detach);
}
static int cxlflash_cxl_release(struct inode *inode, struct file *file)
{
struct cxl_context *ctx = cxl_fops_get_context(file);
struct cxlflash_cfg *cfg = container_of(file->f_op, struct cxlflash_cfg,
cxl_fops);
struct device *dev = &cfg->dev->dev;
struct ctx_info *ctxi = NULL;
struct dk_cxlflash_detach detach = { { 0 }, 0 };
struct lun_access *lun_access, *t;
enum ctx_ctrl ctrl = CTX_CTRL_ERR_FALLBACK | CTX_CTRL_FILE;
int ctxid;
ctxid = cxl_process_element(ctx);
if (unlikely(ctxid < 0)) {
dev_err(dev, "%s: Context %p was closed ctxid=%d\n",
__func__, ctx, ctxid);
goto out;
}
ctxi = get_context(cfg, ctxid, file, ctrl);
if (unlikely(!ctxi)) {
ctxi = get_context(cfg, ctxid, file, ctrl | CTX_CTRL_CLONE);
if (!ctxi) {
dev_dbg(dev, "%s: ctxid=%d already free\n",
__func__, ctxid);
goto out_release;
}
dev_dbg(dev, "%s: Another process owns ctxid=%d\n",
__func__, ctxid);
put_context(ctxi);
goto out;
}
dev_dbg(dev, "%s: close for ctxid=%d\n", __func__, ctxid);
detach.context_id = ctxi->ctxid;
list_for_each_entry_safe(lun_access, t, &ctxi->luns, list)
_cxlflash_disk_detach(lun_access->sdev, ctxi, &detach);
out_release:
cxl_fd_release(inode, file);
out:
dev_dbg(dev, "%s: returning\n", __func__);
return 0;
}
static void unmap_context(struct ctx_info *ctxi)
{
unmap_mapping_range(ctxi->file->f_mapping, 0, 0, 1);
}
static struct page *get_err_page(struct cxlflash_cfg *cfg)
{
struct page *err_page = global.err_page;
struct device *dev = &cfg->dev->dev;
if (unlikely(!err_page)) {
err_page = alloc_page(GFP_KERNEL);
if (unlikely(!err_page)) {
dev_err(dev, "%s: Unable to allocate err_page\n",
__func__);
goto out;
}
memset(page_address(err_page), -1, PAGE_SIZE);
mutex_lock(&global.mutex);
if (likely(!global.err_page))
global.err_page = err_page;
else {
__free_page(err_page);
err_page = global.err_page;
}
mutex_unlock(&global.mutex);
}
out:
dev_dbg(dev, "%s: returning err_page=%p\n", __func__, err_page);
return err_page;
}
static int cxlflash_mmap_fault(struct vm_fault *vmf)
{
struct vm_area_struct *vma = vmf->vma;
struct file *file = vma->vm_file;
struct cxl_context *ctx = cxl_fops_get_context(file);
struct cxlflash_cfg *cfg = container_of(file->f_op, struct cxlflash_cfg,
cxl_fops);
struct device *dev = &cfg->dev->dev;
struct ctx_info *ctxi = NULL;
struct page *err_page = NULL;
enum ctx_ctrl ctrl = CTX_CTRL_ERR_FALLBACK | CTX_CTRL_FILE;
int rc = 0;
int ctxid;
ctxid = cxl_process_element(ctx);
if (unlikely(ctxid < 0)) {
dev_err(dev, "%s: Context %p was closed ctxid=%d\n",
__func__, ctx, ctxid);
goto err;
}
ctxi = get_context(cfg, ctxid, file, ctrl);
if (unlikely(!ctxi)) {
dev_dbg(dev, "%s: Bad context ctxid=%d\n", __func__, ctxid);
goto err;
}
dev_dbg(dev, "%s: fault for context %d\n", __func__, ctxid);
if (likely(!ctxi->err_recovery_active)) {
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
rc = ctxi->cxl_mmap_vmops->fault(vmf);
} else {
dev_dbg(dev, "%s: err recovery active, use err_page\n",
__func__);
err_page = get_err_page(cfg);
if (unlikely(!err_page)) {
dev_err(dev, "%s: Could not get err_page\n", __func__);
rc = VM_FAULT_RETRY;
goto out;
}
get_page(err_page);
vmf->page = err_page;
vma->vm_page_prot = pgprot_cached(vma->vm_page_prot);
}
out:
if (likely(ctxi))
put_context(ctxi);
dev_dbg(dev, "%s: returning rc=%d\n", __func__, rc);
return rc;
err:
rc = VM_FAULT_SIGBUS;
goto out;
}
static int cxlflash_cxl_mmap(struct file *file, struct vm_area_struct *vma)
{
struct cxl_context *ctx = cxl_fops_get_context(file);
struct cxlflash_cfg *cfg = container_of(file->f_op, struct cxlflash_cfg,
cxl_fops);
struct device *dev = &cfg->dev->dev;
struct ctx_info *ctxi = NULL;
enum ctx_ctrl ctrl = CTX_CTRL_ERR_FALLBACK | CTX_CTRL_FILE;
int ctxid;
int rc = 0;
ctxid = cxl_process_element(ctx);
if (unlikely(ctxid < 0)) {
dev_err(dev, "%s: Context %p was closed ctxid=%d\n",
__func__, ctx, ctxid);
rc = -EIO;
goto out;
}
ctxi = get_context(cfg, ctxid, file, ctrl);
if (unlikely(!ctxi)) {
dev_dbg(dev, "%s: Bad context ctxid=%d\n", __func__, ctxid);
rc = -EIO;
goto out;
}
dev_dbg(dev, "%s: mmap for context %d\n", __func__, ctxid);
rc = cxl_fd_mmap(file, vma);
if (likely(!rc)) {
ctxi->cxl_mmap_vmops = vma->vm_ops;
vma->vm_ops = &cxlflash_mmap_vmops;
}
out:
if (likely(ctxi))
put_context(ctxi);
return rc;
}
int cxlflash_mark_contexts_error(struct cxlflash_cfg *cfg)
{
int i, rc = 0;
struct ctx_info *ctxi = NULL;
mutex_lock(&cfg->ctx_tbl_list_mutex);
for (i = 0; i < MAX_CONTEXT; i++) {
ctxi = cfg->ctx_tbl[i];
if (ctxi) {
mutex_lock(&ctxi->mutex);
cfg->ctx_tbl[i] = NULL;
list_add(&ctxi->list, &cfg->ctx_err_recovery);
ctxi->err_recovery_active = true;
ctxi->ctrl_map = NULL;
unmap_context(ctxi);
mutex_unlock(&ctxi->mutex);
}
}
mutex_unlock(&cfg->ctx_tbl_list_mutex);
return rc;
}
int check_state(struct cxlflash_cfg *cfg)
{
struct device *dev = &cfg->dev->dev;
int rc = 0;
retry:
switch (cfg->state) {
case STATE_RESET:
dev_dbg(dev, "%s: Reset state, going to wait...\n", __func__);
up_read(&cfg->ioctl_rwsem);
rc = wait_event_interruptible(cfg->reset_waitq,
cfg->state != STATE_RESET);
down_read(&cfg->ioctl_rwsem);
if (unlikely(rc))
break;
goto retry;
case STATE_FAILTERM:
dev_dbg(dev, "%s: Failed/Terminating\n", __func__);
rc = -ENODEV;
break;
default:
break;
}
return rc;
}
static int cxlflash_disk_attach(struct scsi_device *sdev,
struct dk_cxlflash_attach *attach)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct afu *afu = cfg->afu;
struct llun_info *lli = sdev->hostdata;
struct glun_info *gli = lli->parent;
struct cxl_ioctl_start_work *work;
struct ctx_info *ctxi = NULL;
struct lun_access *lun_access = NULL;
int rc = 0;
u32 perms;
int ctxid = -1;
u64 flags = 0UL;
u64 rctxid = 0UL;
struct file *file = NULL;
struct cxl_context *ctx = NULL;
int fd = -1;
if (attach->num_interrupts > 4) {
dev_dbg(dev, "%s: Cannot support this many interrupts %llu\n",
__func__, attach->num_interrupts);
rc = -EINVAL;
goto out;
}
if (gli->max_lba == 0) {
dev_dbg(dev, "%s: No capacity info for LUN=%016llx\n",
__func__, lli->lun_id[sdev->channel]);
rc = read_cap16(sdev, lli);
if (rc) {
dev_err(dev, "%s: Invalid device rc=%d\n",
__func__, rc);
rc = -ENODEV;
goto out;
}
dev_dbg(dev, "%s: LBA = %016llx\n", __func__, gli->max_lba);
dev_dbg(dev, "%s: BLK_LEN = %08x\n", __func__, gli->blk_len);
}
if (attach->hdr.flags & DK_CXLFLASH_ATTACH_REUSE_CONTEXT) {
rctxid = attach->context_id;
ctxi = get_context(cfg, rctxid, NULL, 0);
if (!ctxi) {
dev_dbg(dev, "%s: Bad context rctxid=%016llx\n",
__func__, rctxid);
rc = -EINVAL;
goto out;
}
list_for_each_entry(lun_access, &ctxi->luns, list)
if (lun_access->lli == lli) {
dev_dbg(dev, "%s: Already attached\n",
__func__);
rc = -EINVAL;
goto out;
}
}
rc = scsi_device_get(sdev);
if (unlikely(rc)) {
dev_err(dev, "%s: Unable to get sdev reference\n", __func__);
goto out;
}
lun_access = kzalloc(sizeof(*lun_access), GFP_KERNEL);
if (unlikely(!lun_access)) {
dev_err(dev, "%s: Unable to allocate lun_access\n", __func__);
rc = -ENOMEM;
goto err;
}
lun_access->lli = lli;
lun_access->sdev = sdev;
if (ctxi) {
dev_dbg(dev, "%s: Reusing context for LUN rctxid=%016llx\n",
__func__, rctxid);
kref_get(&ctxi->kref);
list_add(&lun_access->list, &ctxi->luns);
goto out_attach;
}
ctxi = create_context(cfg);
if (unlikely(!ctxi)) {
dev_err(dev, "%s: Failed to create context ctxid=%d\n",
__func__, ctxid);
rc = -ENOMEM;
goto err;
}
ctx = cxl_dev_context_init(cfg->dev);
if (IS_ERR_OR_NULL(ctx)) {
dev_err(dev, "%s: Could not initialize context %p\n",
__func__, ctx);
rc = -ENODEV;
goto err;
}
work = &ctxi->work;
work->num_interrupts = attach->num_interrupts;
work->flags = CXL_START_WORK_NUM_IRQS;
rc = cxl_start_work(ctx, work);
if (unlikely(rc)) {
dev_dbg(dev, "%s: Could not start context rc=%d\n",
__func__, rc);
goto err;
}
ctxid = cxl_process_element(ctx);
if (unlikely((ctxid >= MAX_CONTEXT) || (ctxid < 0))) {
dev_err(dev, "%s: ctxid=%d invalid\n", __func__, ctxid);
rc = -EPERM;
goto err;
}
file = cxl_get_fd(ctx, &cfg->cxl_fops, &fd);
if (unlikely(fd < 0)) {
rc = -ENODEV;
dev_err(dev, "%s: Could not get file descriptor\n", __func__);
goto err;
}
perms = SISL_RHT_PERM(attach->hdr.flags + 1);
init_context(ctxi, cfg, ctx, ctxid, file, perms);
rc = afu_attach(cfg, ctxi);
if (unlikely(rc)) {
dev_err(dev, "%s: Could not attach AFU rc %d\n", __func__, rc);
goto err;
}
list_add(&lun_access->list, &ctxi->luns);
mutex_lock(&cfg->ctx_tbl_list_mutex);
mutex_lock(&ctxi->mutex);
cfg->ctx_tbl[ctxid] = ctxi;
mutex_unlock(&cfg->ctx_tbl_list_mutex);
fd_install(fd, file);
out_attach:
if (fd != -1)
flags |= DK_CXLFLASH_APP_CLOSE_ADAP_FD;
if (afu_is_sq_cmd_mode(afu))
flags |= DK_CXLFLASH_CONTEXT_SQ_CMD_MODE;
attach->hdr.return_flags = flags;
attach->context_id = ctxi->ctxid;
attach->block_size = gli->blk_len;
attach->mmio_size = sizeof(afu->afu_map->hosts[0].harea);
attach->last_lba = gli->max_lba;
attach->max_xfer = sdev->host->max_sectors * MAX_SECTOR_UNIT;
attach->max_xfer /= gli->blk_len;
out:
attach->adap_fd = fd;
if (ctxi)
put_context(ctxi);
dev_dbg(dev, "%s: returning ctxid=%d fd=%d bs=%lld rc=%d llba=%lld\n",
__func__, ctxid, fd, attach->block_size, rc, attach->last_lba);
return rc;
err:
if (!IS_ERR_OR_NULL(ctx)) {
cxl_stop_context(ctx);
cxl_release_context(ctx);
ctx = NULL;
}
if (fd > 0) {
file->f_op = &null_fops;
fput(file);
put_unused_fd(fd);
fd = -1;
file = NULL;
}
if (ctxi) {
destroy_context(cfg, ctxi);
ctxi = NULL;
}
kfree(lun_access);
scsi_device_put(sdev);
goto out;
}
static int recover_context(struct cxlflash_cfg *cfg,
struct ctx_info *ctxi,
int *adap_fd)
{
struct device *dev = &cfg->dev->dev;
int rc = 0;
int fd = -1;
int ctxid = -1;
struct file *file;
struct cxl_context *ctx;
struct afu *afu = cfg->afu;
ctx = cxl_dev_context_init(cfg->dev);
if (IS_ERR_OR_NULL(ctx)) {
dev_err(dev, "%s: Could not initialize context %p\n",
__func__, ctx);
rc = -ENODEV;
goto out;
}
rc = cxl_start_work(ctx, &ctxi->work);
if (unlikely(rc)) {
dev_dbg(dev, "%s: Could not start context rc=%d\n",
__func__, rc);
goto err1;
}
ctxid = cxl_process_element(ctx);
if (unlikely((ctxid >= MAX_CONTEXT) || (ctxid < 0))) {
dev_err(dev, "%s: ctxid=%d invalid\n", __func__, ctxid);
rc = -EPERM;
goto err2;
}
file = cxl_get_fd(ctx, &cfg->cxl_fops, &fd);
if (unlikely(fd < 0)) {
rc = -ENODEV;
dev_err(dev, "%s: Could not get file descriptor\n", __func__);
goto err2;
}
ctxi->ctrl_map = &afu->afu_map->ctrls[ctxid].ctrl;
rc = afu_attach(cfg, ctxi);
if (rc) {
dev_err(dev, "%s: Could not attach AFU rc %d\n", __func__, rc);
goto err3;
}
ctxi->ctxid = ENCODE_CTXID(ctxi, ctxid);
ctxi->ctx = ctx;
ctxi->file = file;
mutex_unlock(&ctxi->mutex);
mutex_lock(&cfg->ctx_tbl_list_mutex);
mutex_lock(&ctxi->mutex);
list_del_init(&ctxi->list);
cfg->ctx_tbl[ctxid] = ctxi;
mutex_unlock(&cfg->ctx_tbl_list_mutex);
fd_install(fd, file);
*adap_fd = fd;
out:
dev_dbg(dev, "%s: returning ctxid=%d fd=%d rc=%d\n",
__func__, ctxid, fd, rc);
return rc;
err3:
fput(file);
put_unused_fd(fd);
err2:
cxl_stop_context(ctx);
err1:
cxl_release_context(ctx);
goto out;
}
static int cxlflash_afu_recover(struct scsi_device *sdev,
struct dk_cxlflash_recover_afu *recover)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct llun_info *lli = sdev->hostdata;
struct afu *afu = cfg->afu;
struct ctx_info *ctxi = NULL;
struct mutex *mutex = &cfg->ctx_recovery_mutex;
struct hwq *hwq = get_hwq(afu, PRIMARY_HWQ);
u64 flags;
u64 ctxid = DECODE_CTXID(recover->context_id),
rctxid = recover->context_id;
long reg;
bool locked = true;
int lretry = 20;
int new_adap_fd = -1;
int rc = 0;
atomic_inc(&cfg->recovery_threads);
up_read(&cfg->ioctl_rwsem);
rc = mutex_lock_interruptible(mutex);
down_read(&cfg->ioctl_rwsem);
if (rc) {
locked = false;
goto out;
}
rc = check_state(cfg);
if (rc) {
dev_err(dev, "%s: Failed state rc=%d\n", __func__, rc);
rc = -ENODEV;
goto out;
}
dev_dbg(dev, "%s: reason=%016llx rctxid=%016llx\n",
__func__, recover->reason, rctxid);
retry:
ctxi = get_context(cfg, rctxid, lli, CTX_CTRL_ERR_FALLBACK);
if (unlikely(!ctxi)) {
dev_dbg(dev, "%s: Bad context ctxid=%llu\n", __func__, ctxid);
rc = -EINVAL;
goto out;
}
if (ctxi->err_recovery_active) {
retry_recover:
rc = recover_context(cfg, ctxi, &new_adap_fd);
if (unlikely(rc)) {
dev_err(dev, "%s: Recovery failed ctxid=%llu rc=%d\n",
__func__, ctxid, rc);
if ((rc == -ENODEV) &&
((atomic_read(&cfg->recovery_threads) > 1) ||
(lretry--))) {
dev_dbg(dev, "%s: Going to try again\n",
__func__);
mutex_unlock(mutex);
msleep(100);
rc = mutex_lock_interruptible(mutex);
if (rc) {
locked = false;
goto out;
}
goto retry_recover;
}
goto out;
}
ctxi->err_recovery_active = false;
flags = DK_CXLFLASH_APP_CLOSE_ADAP_FD |
DK_CXLFLASH_RECOVER_AFU_CONTEXT_RESET;
if (afu_is_sq_cmd_mode(afu))
flags |= DK_CXLFLASH_CONTEXT_SQ_CMD_MODE;
recover->hdr.return_flags = flags;
recover->context_id = ctxi->ctxid;
recover->adap_fd = new_adap_fd;
recover->mmio_size = sizeof(afu->afu_map->hosts[0].harea);
goto out;
}
reg = readq_be(&hwq->ctrl_map->mbox_r);
if (reg == -1) {
dev_dbg(dev, "%s: MMIO fail, wait for recovery.\n", __func__);
put_context(ctxi);
ctxi = NULL;
ssleep(1);
rc = check_state(cfg);
if (unlikely(rc))
goto out;
goto retry;
}
dev_dbg(dev, "%s: MMIO working, no recovery required\n", __func__);
out:
if (likely(ctxi))
put_context(ctxi);
if (locked)
mutex_unlock(mutex);
atomic_dec_if_positive(&cfg->recovery_threads);
return rc;
}
static int process_sense(struct scsi_device *sdev,
struct dk_cxlflash_verify *verify)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct llun_info *lli = sdev->hostdata;
struct glun_info *gli = lli->parent;
u64 prev_lba = gli->max_lba;
struct scsi_sense_hdr sshdr = { 0 };
int rc = 0;
rc = scsi_normalize_sense((const u8 *)&verify->sense_data,
DK_CXLFLASH_VERIFY_SENSE_LEN, &sshdr);
if (!rc) {
dev_err(dev, "%s: Failed to normalize sense data\n", __func__);
rc = -EINVAL;
goto out;
}
switch (sshdr.sense_key) {
case NO_SENSE:
case RECOVERED_ERROR:
case NOT_READY:
break;
case UNIT_ATTENTION:
switch (sshdr.asc) {
case 0x29:
case 0x2A:
rc = read_cap16(sdev, lli);
if (rc) {
rc = -ENODEV;
break;
}
if (prev_lba != gli->max_lba)
dev_dbg(dev, "%s: Capacity changed old=%lld "
"new=%lld\n", __func__, prev_lba,
gli->max_lba);
break;
case 0x3F:
scsi_scan_host(cfg->host);
break;
default:
rc = -EIO;
break;
}
break;
default:
rc = -EIO;
break;
}
out:
dev_dbg(dev, "%s: sense_key %x asc %x ascq %x rc %d\n", __func__,
sshdr.sense_key, sshdr.asc, sshdr.ascq, rc);
return rc;
}
static int cxlflash_disk_verify(struct scsi_device *sdev,
struct dk_cxlflash_verify *verify)
{
int rc = 0;
struct ctx_info *ctxi = NULL;
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct llun_info *lli = sdev->hostdata;
struct glun_info *gli = lli->parent;
struct sisl_rht_entry *rhte = NULL;
res_hndl_t rhndl = verify->rsrc_handle;
u64 ctxid = DECODE_CTXID(verify->context_id),
rctxid = verify->context_id;
u64 last_lba = 0;
dev_dbg(dev, "%s: ctxid=%llu rhndl=%016llx, hint=%016llx, "
"flags=%016llx\n", __func__, ctxid, verify->rsrc_handle,
verify->hint, verify->hdr.flags);
ctxi = get_context(cfg, rctxid, lli, 0);
if (unlikely(!ctxi)) {
dev_dbg(dev, "%s: Bad context ctxid=%llu\n", __func__, ctxid);
rc = -EINVAL;
goto out;
}
rhte = get_rhte(ctxi, rhndl, lli);
if (unlikely(!rhte)) {
dev_dbg(dev, "%s: Bad resource handle rhndl=%d\n",
__func__, rhndl);
rc = -EINVAL;
goto out;
}
if (verify->hint & DK_CXLFLASH_VERIFY_HINT_SENSE) {
ctxi->unavail = true;
mutex_unlock(&ctxi->mutex);
rc = process_sense(sdev, verify);
if (unlikely(rc)) {
dev_err(dev, "%s: Failed to validate sense data (%d)\n",
__func__, rc);
mutex_lock(&ctxi->mutex);
ctxi->unavail = false;
goto out;
}
mutex_lock(&ctxi->mutex);
ctxi->unavail = false;
}
switch (gli->mode) {
case MODE_PHYSICAL:
last_lba = gli->max_lba;
break;
case MODE_VIRTUAL:
last_lba = ((u64)rhte->lxt_cnt * MC_CHUNK_SIZE * gli->blk_len);
last_lba /= CXLFLASH_BLOCK_SIZE;
last_lba--;
break;
default:
WARN(1, "Unsupported LUN mode!");
}
verify->last_lba = last_lba;
out:
if (likely(ctxi))
put_context(ctxi);
dev_dbg(dev, "%s: returning rc=%d llba=%llx\n",
__func__, rc, verify->last_lba);
return rc;
}
static char *decode_ioctl(int cmd)
{
switch (cmd) {
case DK_CXLFLASH_ATTACH:
return __stringify_1(DK_CXLFLASH_ATTACH);
case DK_CXLFLASH_USER_DIRECT:
return __stringify_1(DK_CXLFLASH_USER_DIRECT);
case DK_CXLFLASH_USER_VIRTUAL:
return __stringify_1(DK_CXLFLASH_USER_VIRTUAL);
case DK_CXLFLASH_VLUN_RESIZE:
return __stringify_1(DK_CXLFLASH_VLUN_RESIZE);
case DK_CXLFLASH_RELEASE:
return __stringify_1(DK_CXLFLASH_RELEASE);
case DK_CXLFLASH_DETACH:
return __stringify_1(DK_CXLFLASH_DETACH);
case DK_CXLFLASH_VERIFY:
return __stringify_1(DK_CXLFLASH_VERIFY);
case DK_CXLFLASH_VLUN_CLONE:
return __stringify_1(DK_CXLFLASH_VLUN_CLONE);
case DK_CXLFLASH_RECOVER_AFU:
return __stringify_1(DK_CXLFLASH_RECOVER_AFU);
case DK_CXLFLASH_MANAGE_LUN:
return __stringify_1(DK_CXLFLASH_MANAGE_LUN);
}
return "UNKNOWN";
}
static int cxlflash_disk_direct_open(struct scsi_device *sdev, void *arg)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct afu *afu = cfg->afu;
struct llun_info *lli = sdev->hostdata;
struct glun_info *gli = lli->parent;
struct dk_cxlflash_release rel = { { 0 }, 0 };
struct dk_cxlflash_udirect *pphys = (struct dk_cxlflash_udirect *)arg;
u64 ctxid = DECODE_CTXID(pphys->context_id),
rctxid = pphys->context_id;
u64 lun_size = 0;
u64 last_lba = 0;
u64 rsrc_handle = -1;
u32 port = CHAN2PORTMASK(sdev->channel);
int rc = 0;
struct ctx_info *ctxi = NULL;
struct sisl_rht_entry *rhte = NULL;
dev_dbg(dev, "%s: ctxid=%llu ls=%llu\n", __func__, ctxid, lun_size);
rc = cxlflash_lun_attach(gli, MODE_PHYSICAL, false);
if (unlikely(rc)) {
dev_dbg(dev, "%s: Failed attach to LUN (PHYSICAL)\n", __func__);
goto out;
}
ctxi = get_context(cfg, rctxid, lli, 0);
if (unlikely(!ctxi)) {
dev_dbg(dev, "%s: Bad context ctxid=%llu\n", __func__, ctxid);
rc = -EINVAL;
goto err1;
}
rhte = rhte_checkout(ctxi, lli);
if (unlikely(!rhte)) {
dev_dbg(dev, "%s: Too many opens ctxid=%lld\n",
__func__, ctxid);
rc = -EMFILE;
goto err1;
}
rsrc_handle = (rhte - ctxi->rht_start);
rht_format1(rhte, lli->lun_id[sdev->channel], ctxi->rht_perms, port);
last_lba = gli->max_lba;
pphys->hdr.return_flags = 0;
pphys->last_lba = last_lba;
pphys->rsrc_handle = rsrc_handle;
rc = cxlflash_afu_sync(afu, ctxid, rsrc_handle, AFU_LW_SYNC);
if (unlikely(rc)) {
dev_dbg(dev, "%s: AFU sync failed rc=%d\n", __func__, rc);
goto err2;
}
out:
if (likely(ctxi))
put_context(ctxi);
dev_dbg(dev, "%s: returning handle=%llu rc=%d llba=%llu\n",
__func__, rsrc_handle, rc, last_lba);
return rc;
err2:
marshal_udir_to_rele(pphys, &rel);
_cxlflash_disk_release(sdev, ctxi, &rel);
goto out;
err1:
cxlflash_lun_detach(gli);
goto out;
}
static int ioctl_common(struct scsi_device *sdev, int cmd)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct llun_info *lli = sdev->hostdata;
int rc = 0;
if (unlikely(!lli)) {
dev_dbg(dev, "%s: Unknown LUN\n", __func__);
rc = -EINVAL;
goto out;
}
rc = check_state(cfg);
if (unlikely(rc) && (cfg->state == STATE_FAILTERM)) {
switch (cmd) {
case DK_CXLFLASH_VLUN_RESIZE:
case DK_CXLFLASH_RELEASE:
case DK_CXLFLASH_DETACH:
dev_dbg(dev, "%s: Command override rc=%d\n",
__func__, rc);
rc = 0;
break;
}
}
out:
return rc;
}
int cxlflash_ioctl(struct scsi_device *sdev, int cmd, void __user *arg)
{
typedef int (*sioctl) (struct scsi_device *, void *);
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct afu *afu = cfg->afu;
struct dk_cxlflash_hdr *hdr;
char buf[sizeof(union cxlflash_ioctls)];
size_t size = 0;
bool known_ioctl = false;
int idx;
int rc = 0;
struct Scsi_Host *shost = sdev->host;
sioctl do_ioctl = NULL;
static const struct {
size_t size;
sioctl ioctl;
} ioctl_tbl[] = {
{sizeof(struct dk_cxlflash_attach), (sioctl)cxlflash_disk_attach},
{sizeof(struct dk_cxlflash_udirect), cxlflash_disk_direct_open},
{sizeof(struct dk_cxlflash_release), (sioctl)cxlflash_disk_release},
{sizeof(struct dk_cxlflash_detach), (sioctl)cxlflash_disk_detach},
{sizeof(struct dk_cxlflash_verify), (sioctl)cxlflash_disk_verify},
{sizeof(struct dk_cxlflash_recover_afu), (sioctl)cxlflash_afu_recover},
{sizeof(struct dk_cxlflash_manage_lun), (sioctl)cxlflash_manage_lun},
{sizeof(struct dk_cxlflash_uvirtual), cxlflash_disk_virtual_open},
{sizeof(struct dk_cxlflash_resize), (sioctl)cxlflash_vlun_resize},
{sizeof(struct dk_cxlflash_clone), (sioctl)cxlflash_disk_clone},
};
down_read(&cfg->ioctl_rwsem);
if (afu->internal_lun)
switch (cmd) {
case DK_CXLFLASH_RELEASE:
case DK_CXLFLASH_USER_VIRTUAL:
case DK_CXLFLASH_VLUN_RESIZE:
case DK_CXLFLASH_VLUN_CLONE:
dev_dbg(dev, "%s: %s not supported for lun_mode=%d\n",
__func__, decode_ioctl(cmd), afu->internal_lun);
rc = -EINVAL;
goto cxlflash_ioctl_exit;
}
switch (cmd) {
case DK_CXLFLASH_ATTACH:
case DK_CXLFLASH_USER_DIRECT:
case DK_CXLFLASH_RELEASE:
case DK_CXLFLASH_DETACH:
case DK_CXLFLASH_VERIFY:
case DK_CXLFLASH_RECOVER_AFU:
case DK_CXLFLASH_USER_VIRTUAL:
case DK_CXLFLASH_VLUN_RESIZE:
case DK_CXLFLASH_VLUN_CLONE:
dev_dbg(dev, "%s: %s (%08X) on dev(%d/%d/%d/%llu)\n",
__func__, decode_ioctl(cmd), cmd, shost->host_no,
sdev->channel, sdev->id, sdev->lun);
rc = ioctl_common(sdev, cmd);
if (unlikely(rc))
goto cxlflash_ioctl_exit;
case DK_CXLFLASH_MANAGE_LUN:
known_ioctl = true;
idx = _IOC_NR(cmd) - _IOC_NR(DK_CXLFLASH_ATTACH);
size = ioctl_tbl[idx].size;
do_ioctl = ioctl_tbl[idx].ioctl;
if (likely(do_ioctl))
break;
default:
rc = -EINVAL;
goto cxlflash_ioctl_exit;
}
if (unlikely(copy_from_user(&buf, arg, size))) {
dev_err(dev, "%s: copy_from_user() fail "
"size=%lu cmd=%d (%s) arg=%p\n",
__func__, size, cmd, decode_ioctl(cmd), arg);
rc = -EFAULT;
goto cxlflash_ioctl_exit;
}
hdr = (struct dk_cxlflash_hdr *)&buf;
if (hdr->version != DK_CXLFLASH_VERSION_0) {
dev_dbg(dev, "%s: Version %u not supported for %s\n",
__func__, hdr->version, decode_ioctl(cmd));
rc = -EINVAL;
goto cxlflash_ioctl_exit;
}
if (hdr->rsvd[0] || hdr->rsvd[1] || hdr->rsvd[2] || hdr->return_flags) {
dev_dbg(dev, "%s: Reserved/rflags populated\n", __func__);
rc = -EINVAL;
goto cxlflash_ioctl_exit;
}
rc = do_ioctl(sdev, (void *)&buf);
if (likely(!rc))
if (unlikely(copy_to_user(arg, &buf, size))) {
dev_err(dev, "%s: copy_to_user() fail "
"size=%lu cmd=%d (%s) arg=%p\n",
__func__, size, cmd, decode_ioctl(cmd), arg);
rc = -EFAULT;
}
cxlflash_ioctl_exit:
up_read(&cfg->ioctl_rwsem);
if (unlikely(rc && known_ioctl))
dev_err(dev, "%s: ioctl %s (%08X) on dev(%d/%d/%d/%llu) "
"returned rc %d\n", __func__,
decode_ioctl(cmd), cmd, shost->host_no,
sdev->channel, sdev->id, sdev->lun, rc);
else
dev_dbg(dev, "%s: ioctl %s (%08X) on dev(%d/%d/%d/%llu) "
"returned rc %d\n", __func__, decode_ioctl(cmd),
cmd, shost->host_no, sdev->channel, sdev->id,
sdev->lun, rc);
return rc;
}
