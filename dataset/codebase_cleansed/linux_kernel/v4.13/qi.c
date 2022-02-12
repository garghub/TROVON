int caam_qi_enqueue(struct device *qidev, struct caam_drv_req *req)
{
struct qm_fd fd;
dma_addr_t addr;
int ret;
int num_retries = 0;
qm_fd_clear_fd(&fd);
qm_fd_set_compound(&fd, qm_sg_entry_get_len(&req->fd_sgt[1]));
addr = dma_map_single(qidev, req->fd_sgt, sizeof(req->fd_sgt),
DMA_BIDIRECTIONAL);
if (dma_mapping_error(qidev, addr)) {
dev_err(qidev, "DMA mapping error for QI enqueue request\n");
return -EIO;
}
qm_fd_addr_set64(&fd, addr);
do {
ret = qman_enqueue(req->drv_ctx->req_fq, &fd);
if (likely(!ret))
return 0;
if (ret != -EBUSY)
break;
num_retries++;
} while (num_retries < CAAM_QI_ENQUEUE_RETRIES);
dev_err(qidev, "qman_enqueue failed: %d\n", ret);
return ret;
}
static void caam_fq_ern_cb(struct qman_portal *qm, struct qman_fq *fq,
const union qm_mr_entry *msg)
{
const struct qm_fd *fd;
struct caam_drv_req *drv_req;
struct device *qidev = &(raw_cpu_ptr(&pcpu_qipriv)->net_dev.dev);
fd = &msg->ern.fd;
if (qm_fd_get_format(fd) != qm_fd_compound) {
dev_err(qidev, "Non-compound FD from CAAM\n");
return;
}
drv_req = (struct caam_drv_req *)phys_to_virt(qm_fd_addr_get64(fd));
if (!drv_req) {
dev_err(qidev,
"Can't find original request for CAAM response\n");
return;
}
dma_unmap_single(drv_req->drv_ctx->qidev, qm_fd_addr(fd),
sizeof(drv_req->fd_sgt), DMA_BIDIRECTIONAL);
drv_req->cbk(drv_req, -EIO);
}
static struct qman_fq *create_caam_req_fq(struct device *qidev,
struct qman_fq *rsp_fq,
dma_addr_t hwdesc,
int fq_sched_flag)
{
int ret;
struct qman_fq *req_fq;
struct qm_mcc_initfq opts;
req_fq = kzalloc(sizeof(*req_fq), GFP_ATOMIC);
if (!req_fq)
return ERR_PTR(-ENOMEM);
req_fq->cb.ern = caam_fq_ern_cb;
req_fq->cb.fqs = NULL;
ret = qman_create_fq(0, QMAN_FQ_FLAG_DYNAMIC_FQID |
QMAN_FQ_FLAG_TO_DCPORTAL, req_fq);
if (ret) {
dev_err(qidev, "Failed to create session req FQ\n");
goto create_req_fq_fail;
}
memset(&opts, 0, sizeof(opts));
opts.we_mask = cpu_to_be16(QM_INITFQ_WE_FQCTRL | QM_INITFQ_WE_DESTWQ |
QM_INITFQ_WE_CONTEXTB |
QM_INITFQ_WE_CONTEXTA | QM_INITFQ_WE_CGID);
opts.fqd.fq_ctrl = cpu_to_be16(QM_FQCTRL_CPCSTASH | QM_FQCTRL_CGE);
qm_fqd_set_destwq(&opts.fqd, qm_channel_caam, 2);
opts.fqd.context_b = cpu_to_be32(qman_fq_fqid(rsp_fq));
qm_fqd_context_a_set64(&opts.fqd, hwdesc);
opts.fqd.cgid = qipriv.cgr.cgrid;
ret = qman_init_fq(req_fq, fq_sched_flag, &opts);
if (ret) {
dev_err(qidev, "Failed to init session req FQ\n");
goto init_req_fq_fail;
}
dev_info(qidev, "Allocated request FQ %u for CPU %u\n", req_fq->fqid,
smp_processor_id());
return req_fq;
init_req_fq_fail:
qman_destroy_fq(req_fq);
create_req_fq_fail:
kfree(req_fq);
return ERR_PTR(ret);
}
static int empty_retired_fq(struct device *qidev, struct qman_fq *fq)
{
int ret;
ret = qman_volatile_dequeue(fq, QMAN_VOLATILE_FLAG_WAIT_INT |
QMAN_VOLATILE_FLAG_FINISH,
QM_VDQCR_PRECEDENCE_VDQCR |
QM_VDQCR_NUMFRAMES_TILLEMPTY);
if (ret) {
dev_err(qidev, "Volatile dequeue fail for FQ: %u\n", fq->fqid);
return ret;
}
do {
struct qman_portal *p;
p = qman_get_affine_portal(smp_processor_id());
qman_p_poll_dqrr(p, 16);
} while (fq->flags & QMAN_FQ_STATE_NE);
return 0;
}
static int kill_fq(struct device *qidev, struct qman_fq *fq)
{
u32 flags;
int ret;
ret = qman_retire_fq(fq, &flags);
if (ret < 0) {
dev_err(qidev, "qman_retire_fq failed: %d\n", ret);
return ret;
}
if (!ret)
goto empty_fq;
if (ret == 1) {
do {
msleep(20);
} while (fq->state != qman_fq_state_retired);
WARN_ON(fq->flags & QMAN_FQ_STATE_BLOCKOOS);
WARN_ON(fq->flags & QMAN_FQ_STATE_ORL);
}
empty_fq:
if (fq->flags & QMAN_FQ_STATE_NE) {
ret = empty_retired_fq(qidev, fq);
if (ret) {
dev_err(qidev, "empty_retired_fq fail for FQ: %u\n",
fq->fqid);
return ret;
}
}
ret = qman_oos_fq(fq);
if (ret)
dev_err(qidev, "OOS of FQID: %u failed\n", fq->fqid);
qman_destroy_fq(fq);
return ret;
}
static int empty_caam_fq(struct qman_fq *fq)
{
int ret;
struct qm_mcr_queryfq_np np;
do {
ret = qman_query_fq_np(fq, &np);
if (ret)
return ret;
if (!qm_mcr_np_get(&np, frm_cnt))
break;
msleep(20);
} while (1);
msleep(20);
return 0;
}
int caam_drv_ctx_update(struct caam_drv_ctx *drv_ctx, u32 *sh_desc)
{
int ret;
u32 num_words;
struct qman_fq *new_fq, *old_fq;
struct device *qidev = drv_ctx->qidev;
num_words = desc_len(sh_desc);
if (num_words > MAX_SDLEN) {
dev_err(qidev, "Invalid descriptor len: %d words\n", num_words);
return -EINVAL;
}
old_fq = drv_ctx->req_fq;
new_fq = create_caam_req_fq(drv_ctx->qidev, drv_ctx->rsp_fq,
drv_ctx->context_a, 0);
if (unlikely(IS_ERR_OR_NULL(new_fq))) {
dev_err(qidev, "FQ allocation for shdesc update failed\n");
return PTR_ERR(new_fq);
}
drv_ctx->req_fq = new_fq;
ret = empty_caam_fq(old_fq);
if (ret) {
dev_err(qidev, "Old CAAM FQ empty failed: %d\n", ret);
drv_ctx->req_fq = old_fq;
if (kill_fq(qidev, new_fq))
dev_warn(qidev, "New CAAM FQ: %u kill failed\n",
new_fq->fqid);
return ret;
}
drv_ctx->prehdr[0] = cpu_to_caam32((1 << PREHDR_RSLS_SHIFT) |
num_words);
memcpy(drv_ctx->sh_desc, sh_desc, desc_bytes(sh_desc));
dma_sync_single_for_device(qidev, drv_ctx->context_a,
sizeof(drv_ctx->sh_desc) +
sizeof(drv_ctx->prehdr),
DMA_BIDIRECTIONAL);
ret = qman_schedule_fq(new_fq);
if (ret) {
dev_err(qidev, "Fail to sched new CAAM FQ, ecode = %d\n", ret);
drv_ctx->req_fq = old_fq;
if (kill_fq(qidev, new_fq))
dev_warn(qidev, "New CAAM FQ: %u kill failed\n",
new_fq->fqid);
} else if (kill_fq(qidev, old_fq)) {
dev_warn(qidev, "Old CAAM FQ: %u kill failed\n", old_fq->fqid);
}
return 0;
}
struct caam_drv_ctx *caam_drv_ctx_init(struct device *qidev,
int *cpu,
u32 *sh_desc)
{
size_t size;
u32 num_words;
dma_addr_t hwdesc;
struct caam_drv_ctx *drv_ctx;
const cpumask_t *cpus = qman_affine_cpus();
static DEFINE_PER_CPU(int, last_cpu);
num_words = desc_len(sh_desc);
if (num_words > MAX_SDLEN) {
dev_err(qidev, "Invalid descriptor len: %d words\n",
num_words);
return ERR_PTR(-EINVAL);
}
drv_ctx = kzalloc(sizeof(*drv_ctx), GFP_ATOMIC);
if (!drv_ctx)
return ERR_PTR(-ENOMEM);
drv_ctx->prehdr[0] = cpu_to_caam32((1 << PREHDR_RSLS_SHIFT) |
num_words);
memcpy(drv_ctx->sh_desc, sh_desc, desc_bytes(sh_desc));
size = sizeof(drv_ctx->prehdr) + sizeof(drv_ctx->sh_desc);
hwdesc = dma_map_single(qidev, drv_ctx->prehdr, size,
DMA_BIDIRECTIONAL);
if (dma_mapping_error(qidev, hwdesc)) {
dev_err(qidev, "DMA map error for preheader + shdesc\n");
kfree(drv_ctx);
return ERR_PTR(-ENOMEM);
}
drv_ctx->context_a = hwdesc;
if (!cpumask_test_cpu(*cpu, cpus)) {
int *pcpu = &get_cpu_var(last_cpu);
*pcpu = cpumask_next(*pcpu, cpus);
if (*pcpu >= nr_cpu_ids)
*pcpu = cpumask_first(cpus);
*cpu = *pcpu;
put_cpu_var(last_cpu);
}
drv_ctx->cpu = *cpu;
drv_ctx->rsp_fq = per_cpu(pcpu_qipriv.rsp_fq, drv_ctx->cpu);
drv_ctx->req_fq = create_caam_req_fq(qidev, drv_ctx->rsp_fq, hwdesc,
QMAN_INITFQ_FLAG_SCHED);
if (unlikely(IS_ERR_OR_NULL(drv_ctx->req_fq))) {
dev_err(qidev, "create_caam_req_fq failed\n");
dma_unmap_single(qidev, hwdesc, size, DMA_BIDIRECTIONAL);
kfree(drv_ctx);
return ERR_PTR(-ENOMEM);
}
drv_ctx->qidev = qidev;
return drv_ctx;
}
void *qi_cache_alloc(gfp_t flags)
{
return kmem_cache_alloc(qi_cache, flags);
}
void qi_cache_free(void *obj)
{
kmem_cache_free(qi_cache, obj);
}
static int caam_qi_poll(struct napi_struct *napi, int budget)
{
struct caam_napi *np = container_of(napi, struct caam_napi, irqtask);
int cleaned = qman_p_poll_dqrr(np->p, budget);
if (cleaned < budget) {
napi_complete(napi);
qman_p_irqsource_add(np->p, QM_PIRQ_DQRI);
}
return cleaned;
}
void caam_drv_ctx_rel(struct caam_drv_ctx *drv_ctx)
{
if (IS_ERR_OR_NULL(drv_ctx))
return;
if (kill_fq(drv_ctx->qidev, drv_ctx->req_fq))
dev_err(drv_ctx->qidev, "Crypto session req FQ kill failed\n");
dma_unmap_single(drv_ctx->qidev, drv_ctx->context_a,
sizeof(drv_ctx->sh_desc) + sizeof(drv_ctx->prehdr),
DMA_BIDIRECTIONAL);
kfree(drv_ctx);
}
int caam_qi_shutdown(struct device *qidev)
{
int i, ret;
struct caam_qi_priv *priv = dev_get_drvdata(qidev);
const cpumask_t *cpus = qman_affine_cpus();
struct cpumask old_cpumask = current->cpus_allowed;
for_each_cpu(i, cpus) {
struct napi_struct *irqtask;
irqtask = &per_cpu_ptr(&pcpu_qipriv.caam_napi, i)->irqtask;
napi_disable(irqtask);
netif_napi_del(irqtask);
if (kill_fq(qidev, per_cpu(pcpu_qipriv.rsp_fq, i)))
dev_err(qidev, "Rsp FQ kill failed, cpu: %d\n", i);
kfree(per_cpu(pcpu_qipriv.rsp_fq, i));
}
set_cpus_allowed_ptr(current, get_cpu_mask(mod_init_cpu));
ret = qman_delete_cgr(&priv->cgr);
if (ret)
dev_err(qidev, "Deletion of CGR failed: %d\n", ret);
else
qman_release_cgrid(priv->cgr.cgrid);
kmem_cache_destroy(qi_cache);
set_cpus_allowed_ptr(current, &old_cpumask);
platform_device_unregister(priv->qi_pdev);
return ret;
}
static void cgr_cb(struct qman_portal *qm, struct qman_cgr *cgr, int congested)
{
caam_congested = congested;
if (congested) {
#ifdef CONFIG_DEBUG_FS
times_congested++;
#endif
pr_debug_ratelimited("CAAM entered congestion\n");
} else {
pr_debug_ratelimited("CAAM exited congestion\n");
}
}
static int caam_qi_napi_schedule(struct qman_portal *p, struct caam_napi *np)
{
if (unlikely(in_irq() || !in_serving_softirq())) {
qman_p_irqsource_remove(p, QM_PIRQ_DQRI);
np->p = p;
napi_schedule(&np->irqtask);
return 1;
}
return 0;
}
static enum qman_cb_dqrr_result caam_rsp_fq_dqrr_cb(struct qman_portal *p,
struct qman_fq *rsp_fq,
const struct qm_dqrr_entry *dqrr)
{
struct caam_napi *caam_napi = raw_cpu_ptr(&pcpu_qipriv.caam_napi);
struct caam_drv_req *drv_req;
const struct qm_fd *fd;
struct device *qidev = &(raw_cpu_ptr(&pcpu_qipriv)->net_dev.dev);
u32 status;
if (caam_qi_napi_schedule(p, caam_napi))
return qman_cb_dqrr_stop;
fd = &dqrr->fd;
status = be32_to_cpu(fd->status);
if (unlikely(status))
dev_err(qidev, "Error: %#x in CAAM response FD\n", status);
if (unlikely(qm_fd_get_format(fd) != qm_fd_compound)) {
dev_err(qidev, "Non-compound FD from CAAM\n");
return qman_cb_dqrr_consume;
}
drv_req = (struct caam_drv_req *)phys_to_virt(qm_fd_addr_get64(fd));
if (unlikely(!drv_req)) {
dev_err(qidev,
"Can't find original request for caam response\n");
return qman_cb_dqrr_consume;
}
dma_unmap_single(drv_req->drv_ctx->qidev, qm_fd_addr(fd),
sizeof(drv_req->fd_sgt), DMA_BIDIRECTIONAL);
drv_req->cbk(drv_req, status);
return qman_cb_dqrr_consume;
}
static int alloc_rsp_fq_cpu(struct device *qidev, unsigned int cpu)
{
struct qm_mcc_initfq opts;
struct qman_fq *fq;
int ret;
fq = kzalloc(sizeof(*fq), GFP_KERNEL | GFP_DMA);
if (!fq)
return -ENOMEM;
fq->cb.dqrr = caam_rsp_fq_dqrr_cb;
ret = qman_create_fq(0, QMAN_FQ_FLAG_NO_ENQUEUE |
QMAN_FQ_FLAG_DYNAMIC_FQID, fq);
if (ret) {
dev_err(qidev, "Rsp FQ create failed\n");
kfree(fq);
return -ENODEV;
}
memset(&opts, 0, sizeof(opts));
opts.we_mask = cpu_to_be16(QM_INITFQ_WE_FQCTRL | QM_INITFQ_WE_DESTWQ |
QM_INITFQ_WE_CONTEXTB |
QM_INITFQ_WE_CONTEXTA | QM_INITFQ_WE_CGID);
opts.fqd.fq_ctrl = cpu_to_be16(QM_FQCTRL_CTXASTASHING |
QM_FQCTRL_CPCSTASH | QM_FQCTRL_CGE);
qm_fqd_set_destwq(&opts.fqd, qman_affine_channel(cpu), 3);
opts.fqd.cgid = qipriv.cgr.cgrid;
opts.fqd.context_a.stashing.exclusive = QM_STASHING_EXCL_CTX |
QM_STASHING_EXCL_DATA;
qm_fqd_set_stashing(&opts.fqd, 0, 1, 1);
ret = qman_init_fq(fq, QMAN_INITFQ_FLAG_SCHED, &opts);
if (ret) {
dev_err(qidev, "Rsp FQ init failed\n");
kfree(fq);
return -ENODEV;
}
per_cpu(pcpu_qipriv.rsp_fq, cpu) = fq;
dev_info(qidev, "Allocated response FQ %u for CPU %u", fq->fqid, cpu);
return 0;
}
static int init_cgr(struct device *qidev)
{
int ret;
struct qm_mcc_initcgr opts;
const u64 cpus = *(u64 *)qman_affine_cpus();
const int num_cpus = hweight64(cpus);
const u64 val = num_cpus * MAX_RSP_FQ_BACKLOG_PER_CPU;
ret = qman_alloc_cgrid(&qipriv.cgr.cgrid);
if (ret) {
dev_err(qidev, "CGR alloc failed for rsp FQs: %d\n", ret);
return ret;
}
qipriv.cgr.cb = cgr_cb;
memset(&opts, 0, sizeof(opts));
opts.we_mask = cpu_to_be16(QM_CGR_WE_CSCN_EN | QM_CGR_WE_CS_THRES |
QM_CGR_WE_MODE);
opts.cgr.cscn_en = QM_CGR_EN;
opts.cgr.mode = QMAN_CGR_MODE_FRAME;
qm_cgr_cs_thres_set64(&opts.cgr.cs_thres, val, 1);
ret = qman_create_cgr(&qipriv.cgr, QMAN_CGR_FLAG_USE_INIT, &opts);
if (ret) {
dev_err(qidev, "Error %d creating CAAM CGRID: %u\n", ret,
qipriv.cgr.cgrid);
return ret;
}
dev_info(qidev, "Congestion threshold set to %llu\n", val);
return 0;
}
static int alloc_rsp_fqs(struct device *qidev)
{
int ret, i;
const cpumask_t *cpus = qman_affine_cpus();
for_each_cpu(i, cpus) {
ret = alloc_rsp_fq_cpu(qidev, i);
if (ret) {
dev_err(qidev, "CAAM rsp FQ alloc failed, cpu: %u", i);
return ret;
}
}
return 0;
}
static void free_rsp_fqs(void)
{
int i;
const cpumask_t *cpus = qman_affine_cpus();
for_each_cpu(i, cpus)
kfree(per_cpu(pcpu_qipriv.rsp_fq, i));
}
int caam_qi_init(struct platform_device *caam_pdev)
{
int err, i;
struct platform_device *qi_pdev;
struct device *ctrldev = &caam_pdev->dev, *qidev;
struct caam_drv_private *ctrlpriv;
const cpumask_t *cpus = qman_affine_cpus();
struct cpumask old_cpumask = current->cpus_allowed;
static struct platform_device_info qi_pdev_info = {
.name = "caam_qi",
.id = PLATFORM_DEVID_NONE
};
mod_init_cpu = cpumask_first(cpus);
set_cpus_allowed_ptr(current, get_cpu_mask(mod_init_cpu));
qi_pdev_info.parent = ctrldev;
qi_pdev_info.dma_mask = dma_get_mask(ctrldev);
qi_pdev = platform_device_register_full(&qi_pdev_info);
if (IS_ERR(qi_pdev))
return PTR_ERR(qi_pdev);
ctrlpriv = dev_get_drvdata(ctrldev);
qidev = &qi_pdev->dev;
qipriv.qi_pdev = qi_pdev;
dev_set_drvdata(qidev, &qipriv);
err = init_cgr(qidev);
if (err) {
dev_err(qidev, "CGR initialization failed: %d\n", err);
platform_device_unregister(qi_pdev);
return err;
}
err = alloc_rsp_fqs(qidev);
if (err) {
dev_err(qidev, "Can't allocate CAAM response FQs: %d\n", err);
free_rsp_fqs();
platform_device_unregister(qi_pdev);
return err;
}
for_each_cpu(i, cpus) {
struct caam_qi_pcpu_priv *priv = per_cpu_ptr(&pcpu_qipriv, i);
struct caam_napi *caam_napi = &priv->caam_napi;
struct napi_struct *irqtask = &caam_napi->irqtask;
struct net_device *net_dev = &priv->net_dev;
net_dev->dev = *qidev;
INIT_LIST_HEAD(&net_dev->napi_list);
netif_napi_add(net_dev, irqtask, caam_qi_poll,
CAAM_NAPI_WEIGHT);
napi_enable(irqtask);
}
ctrlpriv->qidev = qidev;
qi_cache = kmem_cache_create("caamqicache", CAAM_QI_MEMCACHE_SIZE, 0,
SLAB_CACHE_DMA, NULL);
if (!qi_cache) {
dev_err(qidev, "Can't allocate CAAM cache\n");
free_rsp_fqs();
platform_device_unregister(qi_pdev);
return -ENOMEM;
}
set_cpus_allowed_ptr(current, &old_cpumask);
#ifdef CONFIG_DEBUG_FS
ctrlpriv->qi_congested = debugfs_create_file("qi_congested", 0444,
ctrlpriv->ctl,
&times_congested,
&caam_fops_u64_ro);
#endif
dev_info(qidev, "Linux CAAM Queue I/F driver initialised\n");
return 0;
}
