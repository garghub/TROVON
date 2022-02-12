static inline int
nvmet_fc_iodnum(struct nvmet_fc_ls_iod *iodptr)
{
return (iodptr - iodptr->tgtport->iod);
}
static inline int
nvmet_fc_fodnum(struct nvmet_fc_fcp_iod *fodptr)
{
return (fodptr - fodptr->queue->fod);
}
static inline u64
nvmet_fc_makeconnid(struct nvmet_fc_tgt_assoc *assoc, u16 qid)
{
return (assoc->association_id | qid);
}
static inline u64
nvmet_fc_getassociationid(u64 connectionid)
{
return connectionid & ~NVMET_FC_QUEUEID_MASK;
}
static inline u16
nvmet_fc_getqueueid(u64 connectionid)
{
return (u16)(connectionid & NVMET_FC_QUEUEID_MASK);
}
static inline struct nvmet_fc_tgtport *
targetport_to_tgtport(struct nvmet_fc_target_port *targetport)
{
return container_of(targetport, struct nvmet_fc_tgtport,
fc_target_port);
}
static inline struct nvmet_fc_fcp_iod *
nvmet_req_to_fod(struct nvmet_req *nvme_req)
{
return container_of(nvme_req, struct nvmet_fc_fcp_iod, req);
}
static inline dma_addr_t
fc_dma_map_single(struct device *dev, void *ptr, size_t size,
enum dma_data_direction dir)
{
return dev ? dma_map_single(dev, ptr, size, dir) : (dma_addr_t)0L;
}
static inline int
fc_dma_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
return dev ? dma_mapping_error(dev, dma_addr) : 0;
}
static inline void
fc_dma_unmap_single(struct device *dev, dma_addr_t addr, size_t size,
enum dma_data_direction dir)
{
if (dev)
dma_unmap_single(dev, addr, size, dir);
}
static inline void
fc_dma_sync_single_for_cpu(struct device *dev, dma_addr_t addr, size_t size,
enum dma_data_direction dir)
{
if (dev)
dma_sync_single_for_cpu(dev, addr, size, dir);
}
static inline void
fc_dma_sync_single_for_device(struct device *dev, dma_addr_t addr, size_t size,
enum dma_data_direction dir)
{
if (dev)
dma_sync_single_for_device(dev, addr, size, dir);
}
static int
fc_map_sg(struct scatterlist *sg, int nents)
{
struct scatterlist *s;
int i;
WARN_ON(nents == 0 || sg[0].length == 0);
for_each_sg(sg, s, nents, i) {
s->dma_address = 0L;
#ifdef CONFIG_NEED_SG_DMA_LENGTH
s->dma_length = s->length;
#endif
}
return nents;
}
static inline int
fc_dma_map_sg(struct device *dev, struct scatterlist *sg, int nents,
enum dma_data_direction dir)
{
return dev ? dma_map_sg(dev, sg, nents, dir) : fc_map_sg(sg, nents);
}
static inline void
fc_dma_unmap_sg(struct device *dev, struct scatterlist *sg, int nents,
enum dma_data_direction dir)
{
if (dev)
dma_unmap_sg(dev, sg, nents, dir);
}
static int
nvmet_fc_alloc_ls_iodlist(struct nvmet_fc_tgtport *tgtport)
{
struct nvmet_fc_ls_iod *iod;
int i;
iod = kcalloc(NVMET_LS_CTX_COUNT, sizeof(struct nvmet_fc_ls_iod),
GFP_KERNEL);
if (!iod)
return -ENOMEM;
tgtport->iod = iod;
for (i = 0; i < NVMET_LS_CTX_COUNT; iod++, i++) {
INIT_WORK(&iod->work, nvmet_fc_handle_ls_rqst_work);
iod->tgtport = tgtport;
list_add_tail(&iod->ls_list, &tgtport->ls_list);
iod->rqstbuf = kcalloc(2, NVME_FC_MAX_LS_BUFFER_SIZE,
GFP_KERNEL);
if (!iod->rqstbuf)
goto out_fail;
iod->rspbuf = iod->rqstbuf + NVME_FC_MAX_LS_BUFFER_SIZE;
iod->rspdma = fc_dma_map_single(tgtport->dev, iod->rspbuf,
NVME_FC_MAX_LS_BUFFER_SIZE,
DMA_TO_DEVICE);
if (fc_dma_mapping_error(tgtport->dev, iod->rspdma))
goto out_fail;
}
return 0;
out_fail:
kfree(iod->rqstbuf);
list_del(&iod->ls_list);
for (iod--, i--; i >= 0; iod--, i--) {
fc_dma_unmap_single(tgtport->dev, iod->rspdma,
NVME_FC_MAX_LS_BUFFER_SIZE, DMA_TO_DEVICE);
kfree(iod->rqstbuf);
list_del(&iod->ls_list);
}
kfree(iod);
return -EFAULT;
}
static void
nvmet_fc_free_ls_iodlist(struct nvmet_fc_tgtport *tgtport)
{
struct nvmet_fc_ls_iod *iod = tgtport->iod;
int i;
for (i = 0; i < NVMET_LS_CTX_COUNT; iod++, i++) {
fc_dma_unmap_single(tgtport->dev,
iod->rspdma, NVME_FC_MAX_LS_BUFFER_SIZE,
DMA_TO_DEVICE);
kfree(iod->rqstbuf);
list_del(&iod->ls_list);
}
kfree(tgtport->iod);
}
static struct nvmet_fc_ls_iod *
nvmet_fc_alloc_ls_iod(struct nvmet_fc_tgtport *tgtport)
{
struct nvmet_fc_ls_iod *iod;
unsigned long flags;
spin_lock_irqsave(&tgtport->lock, flags);
iod = list_first_entry_or_null(&tgtport->ls_list,
struct nvmet_fc_ls_iod, ls_list);
if (iod)
list_move_tail(&iod->ls_list, &tgtport->ls_busylist);
spin_unlock_irqrestore(&tgtport->lock, flags);
return iod;
}
static void
nvmet_fc_free_ls_iod(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_ls_iod *iod)
{
unsigned long flags;
spin_lock_irqsave(&tgtport->lock, flags);
list_move(&iod->ls_list, &tgtport->ls_list);
spin_unlock_irqrestore(&tgtport->lock, flags);
}
static void
nvmet_fc_prep_fcp_iodlist(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_tgt_queue *queue)
{
struct nvmet_fc_fcp_iod *fod = queue->fod;
int i;
for (i = 0; i < queue->sqsize; fod++, i++) {
INIT_WORK(&fod->work, nvmet_fc_handle_fcp_rqst_work);
INIT_WORK(&fod->done_work, nvmet_fc_fcp_rqst_op_done_work);
fod->tgtport = tgtport;
fod->queue = queue;
fod->active = false;
fod->abort = false;
fod->aborted = false;
fod->fcpreq = NULL;
list_add_tail(&fod->fcp_list, &queue->fod_list);
spin_lock_init(&fod->flock);
fod->rspdma = fc_dma_map_single(tgtport->dev, &fod->rspiubuf,
sizeof(fod->rspiubuf), DMA_TO_DEVICE);
if (fc_dma_mapping_error(tgtport->dev, fod->rspdma)) {
list_del(&fod->fcp_list);
for (fod--, i--; i >= 0; fod--, i--) {
fc_dma_unmap_single(tgtport->dev, fod->rspdma,
sizeof(fod->rspiubuf),
DMA_TO_DEVICE);
fod->rspdma = 0L;
list_del(&fod->fcp_list);
}
return;
}
}
}
static void
nvmet_fc_destroy_fcp_iodlist(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_tgt_queue *queue)
{
struct nvmet_fc_fcp_iod *fod = queue->fod;
int i;
for (i = 0; i < queue->sqsize; fod++, i++) {
if (fod->rspdma)
fc_dma_unmap_single(tgtport->dev, fod->rspdma,
sizeof(fod->rspiubuf), DMA_TO_DEVICE);
}
}
static struct nvmet_fc_fcp_iod *
nvmet_fc_alloc_fcp_iod(struct nvmet_fc_tgt_queue *queue)
{
struct nvmet_fc_fcp_iod *fod;
lockdep_assert_held(&queue->qlock);
fod = list_first_entry_or_null(&queue->fod_list,
struct nvmet_fc_fcp_iod, fcp_list);
if (fod) {
list_del(&fod->fcp_list);
fod->active = true;
}
return fod;
}
static void
nvmet_fc_queue_fcp_req(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_tgt_queue *queue,
struct nvmefc_tgt_fcp_req *fcpreq)
{
struct nvmet_fc_fcp_iod *fod = fcpreq->nvmet_fc_private;
fcpreq->hwqid = queue->qid ?
((queue->qid - 1) % tgtport->ops->max_hw_queues) : 0;
if (tgtport->ops->target_features & NVMET_FCTGTFEAT_CMD_IN_ISR)
queue_work_on(queue->cpu, queue->work_q, &fod->work);
else
nvmet_fc_handle_fcp_rqst(tgtport, fod);
}
static void
nvmet_fc_free_fcp_iod(struct nvmet_fc_tgt_queue *queue,
struct nvmet_fc_fcp_iod *fod)
{
struct nvmefc_tgt_fcp_req *fcpreq = fod->fcpreq;
struct nvmet_fc_tgtport *tgtport = fod->tgtport;
struct nvmet_fc_defer_fcp_req *deferfcp;
unsigned long flags;
fc_dma_sync_single_for_cpu(tgtport->dev, fod->rspdma,
sizeof(fod->rspiubuf), DMA_TO_DEVICE);
fcpreq->nvmet_fc_private = NULL;
fod->active = false;
fod->abort = false;
fod->aborted = false;
fod->writedataactive = false;
fod->fcpreq = NULL;
tgtport->ops->fcp_req_release(&tgtport->fc_target_port, fcpreq);
spin_lock_irqsave(&queue->qlock, flags);
deferfcp = list_first_entry_or_null(&queue->pending_cmd_list,
struct nvmet_fc_defer_fcp_req, req_list);
if (!deferfcp) {
list_add_tail(&fod->fcp_list, &fod->queue->fod_list);
spin_unlock_irqrestore(&queue->qlock, flags);
nvmet_fc_tgt_q_put(queue);
return;
}
list_del(&deferfcp->req_list);
fcpreq = deferfcp->fcp_req;
list_add_tail(&deferfcp->req_list, &queue->avail_defer_list);
spin_unlock_irqrestore(&queue->qlock, flags);
memcpy(&fod->cmdiubuf, fcpreq->rspaddr, fcpreq->rsplen);
fcpreq->rspaddr = NULL;
fcpreq->rsplen = 0;
fcpreq->nvmet_fc_private = fod;
fod->fcpreq = fcpreq;
fod->active = true;
tgtport->ops->defer_rcv(&tgtport->fc_target_port, fcpreq);
nvmet_fc_queue_fcp_req(tgtport, queue, fcpreq);
}
static int
nvmet_fc_queue_to_cpu(struct nvmet_fc_tgtport *tgtport, int qid)
{
int cpu, idx, cnt;
if (tgtport->ops->max_hw_queues == 1)
return WORK_CPU_UNBOUND;
idx = !qid ? 0 : (qid - 1) % num_active_cpus();
for (cpu = 0, cnt = 0; ; ) {
if (cpu_active(cpu)) {
if (cnt == idx)
break;
cnt++;
}
cpu = (cpu + 1) % num_possible_cpus();
}
return cpu;
}
static struct nvmet_fc_tgt_queue *
nvmet_fc_alloc_target_queue(struct nvmet_fc_tgt_assoc *assoc,
u16 qid, u16 sqsize)
{
struct nvmet_fc_tgt_queue *queue;
unsigned long flags;
int ret;
if (qid >= NVMET_NR_QUEUES)
return NULL;
queue = kzalloc((sizeof(*queue) +
(sizeof(struct nvmet_fc_fcp_iod) * sqsize)),
GFP_KERNEL);
if (!queue)
return NULL;
if (!nvmet_fc_tgt_a_get(assoc))
goto out_free_queue;
queue->work_q = alloc_workqueue("ntfc%d.%d.%d", 0, 0,
assoc->tgtport->fc_target_port.port_num,
assoc->a_id, qid);
if (!queue->work_q)
goto out_a_put;
queue->fod = (struct nvmet_fc_fcp_iod *)&queue[1];
queue->qid = qid;
queue->sqsize = sqsize;
queue->assoc = assoc;
queue->port = assoc->tgtport->port;
queue->cpu = nvmet_fc_queue_to_cpu(assoc->tgtport, qid);
INIT_LIST_HEAD(&queue->fod_list);
INIT_LIST_HEAD(&queue->avail_defer_list);
INIT_LIST_HEAD(&queue->pending_cmd_list);
atomic_set(&queue->connected, 0);
atomic_set(&queue->sqtail, 0);
atomic_set(&queue->rsn, 1);
atomic_set(&queue->zrspcnt, 0);
spin_lock_init(&queue->qlock);
kref_init(&queue->ref);
nvmet_fc_prep_fcp_iodlist(assoc->tgtport, queue);
ret = nvmet_sq_init(&queue->nvme_sq);
if (ret)
goto out_fail_iodlist;
WARN_ON(assoc->queues[qid]);
spin_lock_irqsave(&assoc->tgtport->lock, flags);
assoc->queues[qid] = queue;
spin_unlock_irqrestore(&assoc->tgtport->lock, flags);
return queue;
out_fail_iodlist:
nvmet_fc_destroy_fcp_iodlist(assoc->tgtport, queue);
destroy_workqueue(queue->work_q);
out_a_put:
nvmet_fc_tgt_a_put(assoc);
out_free_queue:
kfree(queue);
return NULL;
}
static void
nvmet_fc_tgt_queue_free(struct kref *ref)
{
struct nvmet_fc_tgt_queue *queue =
container_of(ref, struct nvmet_fc_tgt_queue, ref);
unsigned long flags;
spin_lock_irqsave(&queue->assoc->tgtport->lock, flags);
queue->assoc->queues[queue->qid] = NULL;
spin_unlock_irqrestore(&queue->assoc->tgtport->lock, flags);
nvmet_fc_destroy_fcp_iodlist(queue->assoc->tgtport, queue);
nvmet_fc_tgt_a_put(queue->assoc);
destroy_workqueue(queue->work_q);
kfree(queue);
}
static void
nvmet_fc_tgt_q_put(struct nvmet_fc_tgt_queue *queue)
{
kref_put(&queue->ref, nvmet_fc_tgt_queue_free);
}
static int
nvmet_fc_tgt_q_get(struct nvmet_fc_tgt_queue *queue)
{
return kref_get_unless_zero(&queue->ref);
}
static void
nvmet_fc_delete_target_queue(struct nvmet_fc_tgt_queue *queue)
{
struct nvmet_fc_tgtport *tgtport = queue->assoc->tgtport;
struct nvmet_fc_fcp_iod *fod = queue->fod;
struct nvmet_fc_defer_fcp_req *deferfcp, *tempptr;
unsigned long flags;
int i, writedataactive;
bool disconnect;
disconnect = atomic_xchg(&queue->connected, 0);
spin_lock_irqsave(&queue->qlock, flags);
for (i = 0; i < queue->sqsize; fod++, i++) {
if (fod->active) {
spin_lock(&fod->flock);
fod->abort = true;
writedataactive = fod->writedataactive;
spin_unlock(&fod->flock);
if (writedataactive) {
spin_lock(&fod->flock);
fod->aborted = true;
spin_unlock(&fod->flock);
tgtport->ops->fcp_abort(
&tgtport->fc_target_port, fod->fcpreq);
}
}
}
list_for_each_entry_safe(deferfcp, tempptr, &queue->avail_defer_list,
req_list) {
list_del(&deferfcp->req_list);
kfree(deferfcp);
}
for (;;) {
deferfcp = list_first_entry_or_null(&queue->pending_cmd_list,
struct nvmet_fc_defer_fcp_req, req_list);
if (!deferfcp)
break;
list_del(&deferfcp->req_list);
spin_unlock_irqrestore(&queue->qlock, flags);
tgtport->ops->defer_rcv(&tgtport->fc_target_port,
deferfcp->fcp_req);
tgtport->ops->fcp_abort(&tgtport->fc_target_port,
deferfcp->fcp_req);
tgtport->ops->fcp_req_release(&tgtport->fc_target_port,
deferfcp->fcp_req);
kfree(deferfcp);
spin_lock_irqsave(&queue->qlock, flags);
}
spin_unlock_irqrestore(&queue->qlock, flags);
flush_workqueue(queue->work_q);
if (disconnect)
nvmet_sq_destroy(&queue->nvme_sq);
nvmet_fc_tgt_q_put(queue);
}
static struct nvmet_fc_tgt_queue *
nvmet_fc_find_target_queue(struct nvmet_fc_tgtport *tgtport,
u64 connection_id)
{
struct nvmet_fc_tgt_assoc *assoc;
struct nvmet_fc_tgt_queue *queue;
u64 association_id = nvmet_fc_getassociationid(connection_id);
u16 qid = nvmet_fc_getqueueid(connection_id);
unsigned long flags;
spin_lock_irqsave(&tgtport->lock, flags);
list_for_each_entry(assoc, &tgtport->assoc_list, a_list) {
if (association_id == assoc->association_id) {
queue = assoc->queues[qid];
if (queue &&
(!atomic_read(&queue->connected) ||
!nvmet_fc_tgt_q_get(queue)))
queue = NULL;
spin_unlock_irqrestore(&tgtport->lock, flags);
return queue;
}
}
spin_unlock_irqrestore(&tgtport->lock, flags);
return NULL;
}
static struct nvmet_fc_tgt_assoc *
nvmet_fc_alloc_target_assoc(struct nvmet_fc_tgtport *tgtport)
{
struct nvmet_fc_tgt_assoc *assoc, *tmpassoc;
unsigned long flags;
u64 ran;
int idx;
bool needrandom = true;
assoc = kzalloc(sizeof(*assoc), GFP_KERNEL);
if (!assoc)
return NULL;
idx = ida_simple_get(&tgtport->assoc_cnt, 0, 0, GFP_KERNEL);
if (idx < 0)
goto out_free_assoc;
if (!nvmet_fc_tgtport_get(tgtport))
goto out_ida_put;
assoc->tgtport = tgtport;
assoc->a_id = idx;
INIT_LIST_HEAD(&assoc->a_list);
kref_init(&assoc->ref);
while (needrandom) {
get_random_bytes(&ran, sizeof(ran) - BYTES_FOR_QID);
ran = ran << BYTES_FOR_QID_SHIFT;
spin_lock_irqsave(&tgtport->lock, flags);
needrandom = false;
list_for_each_entry(tmpassoc, &tgtport->assoc_list, a_list)
if (ran == tmpassoc->association_id) {
needrandom = true;
break;
}
if (!needrandom) {
assoc->association_id = ran;
list_add_tail(&assoc->a_list, &tgtport->assoc_list);
}
spin_unlock_irqrestore(&tgtport->lock, flags);
}
return assoc;
out_ida_put:
ida_simple_remove(&tgtport->assoc_cnt, idx);
out_free_assoc:
kfree(assoc);
return NULL;
}
static void
nvmet_fc_target_assoc_free(struct kref *ref)
{
struct nvmet_fc_tgt_assoc *assoc =
container_of(ref, struct nvmet_fc_tgt_assoc, ref);
struct nvmet_fc_tgtport *tgtport = assoc->tgtport;
unsigned long flags;
spin_lock_irqsave(&tgtport->lock, flags);
list_del(&assoc->a_list);
spin_unlock_irqrestore(&tgtport->lock, flags);
ida_simple_remove(&tgtport->assoc_cnt, assoc->a_id);
kfree(assoc);
nvmet_fc_tgtport_put(tgtport);
}
static void
nvmet_fc_tgt_a_put(struct nvmet_fc_tgt_assoc *assoc)
{
kref_put(&assoc->ref, nvmet_fc_target_assoc_free);
}
static int
nvmet_fc_tgt_a_get(struct nvmet_fc_tgt_assoc *assoc)
{
return kref_get_unless_zero(&assoc->ref);
}
static void
nvmet_fc_delete_target_assoc(struct nvmet_fc_tgt_assoc *assoc)
{
struct nvmet_fc_tgtport *tgtport = assoc->tgtport;
struct nvmet_fc_tgt_queue *queue;
unsigned long flags;
int i;
spin_lock_irqsave(&tgtport->lock, flags);
for (i = NVMET_NR_QUEUES - 1; i >= 0; i--) {
queue = assoc->queues[i];
if (queue) {
if (!nvmet_fc_tgt_q_get(queue))
continue;
spin_unlock_irqrestore(&tgtport->lock, flags);
nvmet_fc_delete_target_queue(queue);
nvmet_fc_tgt_q_put(queue);
spin_lock_irqsave(&tgtport->lock, flags);
}
}
spin_unlock_irqrestore(&tgtport->lock, flags);
nvmet_fc_tgt_a_put(assoc);
}
static struct nvmet_fc_tgt_assoc *
nvmet_fc_find_target_assoc(struct nvmet_fc_tgtport *tgtport,
u64 association_id)
{
struct nvmet_fc_tgt_assoc *assoc;
struct nvmet_fc_tgt_assoc *ret = NULL;
unsigned long flags;
spin_lock_irqsave(&tgtport->lock, flags);
list_for_each_entry(assoc, &tgtport->assoc_list, a_list) {
if (association_id == assoc->association_id) {
ret = assoc;
nvmet_fc_tgt_a_get(assoc);
break;
}
}
spin_unlock_irqrestore(&tgtport->lock, flags);
return ret;
}
int
nvmet_fc_register_targetport(struct nvmet_fc_port_info *pinfo,
struct nvmet_fc_target_template *template,
struct device *dev,
struct nvmet_fc_target_port **portptr)
{
struct nvmet_fc_tgtport *newrec;
unsigned long flags;
int ret, idx;
if (!template->xmt_ls_rsp || !template->fcp_op ||
!template->fcp_abort ||
!template->fcp_req_release || !template->targetport_delete ||
!template->max_hw_queues || !template->max_sgl_segments ||
!template->max_dif_sgl_segments || !template->dma_boundary) {
ret = -EINVAL;
goto out_regtgt_failed;
}
newrec = kzalloc((sizeof(*newrec) + template->target_priv_sz),
GFP_KERNEL);
if (!newrec) {
ret = -ENOMEM;
goto out_regtgt_failed;
}
idx = ida_simple_get(&nvmet_fc_tgtport_cnt, 0, 0, GFP_KERNEL);
if (idx < 0) {
ret = -ENOSPC;
goto out_fail_kfree;
}
if (!get_device(dev) && dev) {
ret = -ENODEV;
goto out_ida_put;
}
newrec->fc_target_port.node_name = pinfo->node_name;
newrec->fc_target_port.port_name = pinfo->port_name;
newrec->fc_target_port.private = &newrec[1];
newrec->fc_target_port.port_id = pinfo->port_id;
newrec->fc_target_port.port_num = idx;
INIT_LIST_HEAD(&newrec->tgt_list);
newrec->dev = dev;
newrec->ops = template;
spin_lock_init(&newrec->lock);
INIT_LIST_HEAD(&newrec->ls_list);
INIT_LIST_HEAD(&newrec->ls_busylist);
INIT_LIST_HEAD(&newrec->assoc_list);
kref_init(&newrec->ref);
ida_init(&newrec->assoc_cnt);
ret = nvmet_fc_alloc_ls_iodlist(newrec);
if (ret) {
ret = -ENOMEM;
goto out_free_newrec;
}
spin_lock_irqsave(&nvmet_fc_tgtlock, flags);
list_add_tail(&newrec->tgt_list, &nvmet_fc_target_list);
spin_unlock_irqrestore(&nvmet_fc_tgtlock, flags);
*portptr = &newrec->fc_target_port;
return 0;
out_free_newrec:
put_device(dev);
out_ida_put:
ida_simple_remove(&nvmet_fc_tgtport_cnt, idx);
out_fail_kfree:
kfree(newrec);
out_regtgt_failed:
*portptr = NULL;
return ret;
}
static void
nvmet_fc_free_tgtport(struct kref *ref)
{
struct nvmet_fc_tgtport *tgtport =
container_of(ref, struct nvmet_fc_tgtport, ref);
struct device *dev = tgtport->dev;
unsigned long flags;
spin_lock_irqsave(&nvmet_fc_tgtlock, flags);
list_del(&tgtport->tgt_list);
spin_unlock_irqrestore(&nvmet_fc_tgtlock, flags);
nvmet_fc_free_ls_iodlist(tgtport);
tgtport->ops->targetport_delete(&tgtport->fc_target_port);
ida_simple_remove(&nvmet_fc_tgtport_cnt,
tgtport->fc_target_port.port_num);
ida_destroy(&tgtport->assoc_cnt);
kfree(tgtport);
put_device(dev);
}
static void
nvmet_fc_tgtport_put(struct nvmet_fc_tgtport *tgtport)
{
kref_put(&tgtport->ref, nvmet_fc_free_tgtport);
}
static int
nvmet_fc_tgtport_get(struct nvmet_fc_tgtport *tgtport)
{
return kref_get_unless_zero(&tgtport->ref);
}
static void
__nvmet_fc_free_assocs(struct nvmet_fc_tgtport *tgtport)
{
struct nvmet_fc_tgt_assoc *assoc, *next;
unsigned long flags;
spin_lock_irqsave(&tgtport->lock, flags);
list_for_each_entry_safe(assoc, next,
&tgtport->assoc_list, a_list) {
if (!nvmet_fc_tgt_a_get(assoc))
continue;
spin_unlock_irqrestore(&tgtport->lock, flags);
nvmet_fc_delete_target_assoc(assoc);
nvmet_fc_tgt_a_put(assoc);
spin_lock_irqsave(&tgtport->lock, flags);
}
spin_unlock_irqrestore(&tgtport->lock, flags);
}
static void
nvmet_fc_delete_ctrl(struct nvmet_ctrl *ctrl)
{
struct nvmet_fc_tgtport *tgtport, *next;
struct nvmet_fc_tgt_assoc *assoc;
struct nvmet_fc_tgt_queue *queue;
unsigned long flags;
bool found_ctrl = false;
spin_lock_irqsave(&nvmet_fc_tgtlock, flags);
list_for_each_entry_safe(tgtport, next, &nvmet_fc_target_list,
tgt_list) {
if (!nvmet_fc_tgtport_get(tgtport))
continue;
spin_unlock_irqrestore(&nvmet_fc_tgtlock, flags);
spin_lock_irqsave(&tgtport->lock, flags);
list_for_each_entry(assoc, &tgtport->assoc_list, a_list) {
queue = assoc->queues[0];
if (queue && queue->nvme_sq.ctrl == ctrl) {
if (nvmet_fc_tgt_a_get(assoc))
found_ctrl = true;
break;
}
}
spin_unlock_irqrestore(&tgtport->lock, flags);
nvmet_fc_tgtport_put(tgtport);
if (found_ctrl) {
nvmet_fc_delete_target_assoc(assoc);
nvmet_fc_tgt_a_put(assoc);
return;
}
spin_lock_irqsave(&nvmet_fc_tgtlock, flags);
}
spin_unlock_irqrestore(&nvmet_fc_tgtlock, flags);
}
int
nvmet_fc_unregister_targetport(struct nvmet_fc_target_port *target_port)
{
struct nvmet_fc_tgtport *tgtport = targetport_to_tgtport(target_port);
__nvmet_fc_free_assocs(tgtport);
nvmet_fc_tgtport_put(tgtport);
return 0;
}
static void
nvmet_fc_format_rsp_hdr(void *buf, u8 ls_cmd, __be32 desc_len, u8 rqst_ls_cmd)
{
struct fcnvme_ls_acc_hdr *acc = buf;
acc->w0.ls_cmd = ls_cmd;
acc->desc_list_len = desc_len;
acc->rqst.desc_tag = cpu_to_be32(FCNVME_LSDESC_RQST);
acc->rqst.desc_len =
fcnvme_lsdesc_len(sizeof(struct fcnvme_lsdesc_rqst));
acc->rqst.w0.ls_cmd = rqst_ls_cmd;
}
static int
nvmet_fc_format_rjt(void *buf, u16 buflen, u8 ls_cmd,
u8 reason, u8 explanation, u8 vendor)
{
struct fcnvme_ls_rjt *rjt = buf;
nvmet_fc_format_rsp_hdr(buf, FCNVME_LSDESC_RQST,
fcnvme_lsdesc_len(sizeof(struct fcnvme_ls_rjt)),
ls_cmd);
rjt->rjt.desc_tag = cpu_to_be32(FCNVME_LSDESC_RJT);
rjt->rjt.desc_len = fcnvme_lsdesc_len(sizeof(struct fcnvme_lsdesc_rjt));
rjt->rjt.reason_code = reason;
rjt->rjt.reason_explanation = explanation;
rjt->rjt.vendor = vendor;
return sizeof(struct fcnvme_ls_rjt);
}
static void
nvmet_fc_ls_create_association(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_ls_iod *iod)
{
struct fcnvme_ls_cr_assoc_rqst *rqst =
(struct fcnvme_ls_cr_assoc_rqst *)iod->rqstbuf;
struct fcnvme_ls_cr_assoc_acc *acc =
(struct fcnvme_ls_cr_assoc_acc *)iod->rspbuf;
struct nvmet_fc_tgt_queue *queue;
int ret = 0;
memset(acc, 0, sizeof(*acc));
if (iod->rqstdatalen < FCNVME_LSDESC_CRA_RQST_MINLEN)
ret = VERR_CR_ASSOC_LEN;
else if (be32_to_cpu(rqst->desc_list_len) <
FCNVME_LSDESC_CRA_RQST_MIN_LISTLEN)
ret = VERR_CR_ASSOC_RQST_LEN;
else if (rqst->assoc_cmd.desc_tag !=
cpu_to_be32(FCNVME_LSDESC_CREATE_ASSOC_CMD))
ret = VERR_CR_ASSOC_CMD;
else if (be32_to_cpu(rqst->assoc_cmd.desc_len) <
FCNVME_LSDESC_CRA_CMD_DESC_MIN_DESCLEN)
ret = VERR_CR_ASSOC_CMD_LEN;
else if (!rqst->assoc_cmd.ersp_ratio ||
(be16_to_cpu(rqst->assoc_cmd.ersp_ratio) >=
be16_to_cpu(rqst->assoc_cmd.sqsize)))
ret = VERR_ERSP_RATIO;
else {
iod->assoc = nvmet_fc_alloc_target_assoc(tgtport);
if (!iod->assoc)
ret = VERR_ASSOC_ALLOC_FAIL;
else {
queue = nvmet_fc_alloc_target_queue(iod->assoc, 0,
be16_to_cpu(rqst->assoc_cmd.sqsize));
if (!queue)
ret = VERR_QUEUE_ALLOC_FAIL;
}
}
if (ret) {
dev_err(tgtport->dev,
"Create Association LS failed: %s\n",
validation_errors[ret]);
iod->lsreq->rsplen = nvmet_fc_format_rjt(acc,
NVME_FC_MAX_LS_BUFFER_SIZE, rqst->w0.ls_cmd,
FCNVME_RJT_RC_LOGIC,
FCNVME_RJT_EXP_NONE, 0);
return;
}
queue->ersp_ratio = be16_to_cpu(rqst->assoc_cmd.ersp_ratio);
atomic_set(&queue->connected, 1);
queue->sqhd = 0;
iod->lsreq->rsplen = sizeof(*acc);
nvmet_fc_format_rsp_hdr(acc, FCNVME_LS_ACC,
fcnvme_lsdesc_len(
sizeof(struct fcnvme_ls_cr_assoc_acc)),
FCNVME_LS_CREATE_ASSOCIATION);
acc->associd.desc_tag = cpu_to_be32(FCNVME_LSDESC_ASSOC_ID);
acc->associd.desc_len =
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_assoc_id));
acc->associd.association_id =
cpu_to_be64(nvmet_fc_makeconnid(iod->assoc, 0));
acc->connectid.desc_tag = cpu_to_be32(FCNVME_LSDESC_CONN_ID);
acc->connectid.desc_len =
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_conn_id));
acc->connectid.connection_id = acc->associd.association_id;
}
static void
nvmet_fc_ls_create_connection(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_ls_iod *iod)
{
struct fcnvme_ls_cr_conn_rqst *rqst =
(struct fcnvme_ls_cr_conn_rqst *)iod->rqstbuf;
struct fcnvme_ls_cr_conn_acc *acc =
(struct fcnvme_ls_cr_conn_acc *)iod->rspbuf;
struct nvmet_fc_tgt_queue *queue;
int ret = 0;
memset(acc, 0, sizeof(*acc));
if (iod->rqstdatalen < sizeof(struct fcnvme_ls_cr_conn_rqst))
ret = VERR_CR_CONN_LEN;
else if (rqst->desc_list_len !=
fcnvme_lsdesc_len(
sizeof(struct fcnvme_ls_cr_conn_rqst)))
ret = VERR_CR_CONN_RQST_LEN;
else if (rqst->associd.desc_tag != cpu_to_be32(FCNVME_LSDESC_ASSOC_ID))
ret = VERR_ASSOC_ID;
else if (rqst->associd.desc_len !=
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_assoc_id)))
ret = VERR_ASSOC_ID_LEN;
else if (rqst->connect_cmd.desc_tag !=
cpu_to_be32(FCNVME_LSDESC_CREATE_CONN_CMD))
ret = VERR_CR_CONN_CMD;
else if (rqst->connect_cmd.desc_len !=
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_cr_conn_cmd)))
ret = VERR_CR_CONN_CMD_LEN;
else if (!rqst->connect_cmd.ersp_ratio ||
(be16_to_cpu(rqst->connect_cmd.ersp_ratio) >=
be16_to_cpu(rqst->connect_cmd.sqsize)))
ret = VERR_ERSP_RATIO;
else {
iod->assoc = nvmet_fc_find_target_assoc(tgtport,
be64_to_cpu(rqst->associd.association_id));
if (!iod->assoc)
ret = VERR_NO_ASSOC;
else {
queue = nvmet_fc_alloc_target_queue(iod->assoc,
be16_to_cpu(rqst->connect_cmd.qid),
be16_to_cpu(rqst->connect_cmd.sqsize));
if (!queue)
ret = VERR_QUEUE_ALLOC_FAIL;
nvmet_fc_tgt_a_put(iod->assoc);
}
}
if (ret) {
dev_err(tgtport->dev,
"Create Connection LS failed: %s\n",
validation_errors[ret]);
iod->lsreq->rsplen = nvmet_fc_format_rjt(acc,
NVME_FC_MAX_LS_BUFFER_SIZE, rqst->w0.ls_cmd,
(ret == VERR_NO_ASSOC) ?
FCNVME_RJT_RC_INV_ASSOC :
FCNVME_RJT_RC_LOGIC,
FCNVME_RJT_EXP_NONE, 0);
return;
}
queue->ersp_ratio = be16_to_cpu(rqst->connect_cmd.ersp_ratio);
atomic_set(&queue->connected, 1);
queue->sqhd = 0;
iod->lsreq->rsplen = sizeof(*acc);
nvmet_fc_format_rsp_hdr(acc, FCNVME_LS_ACC,
fcnvme_lsdesc_len(sizeof(struct fcnvme_ls_cr_conn_acc)),
FCNVME_LS_CREATE_CONNECTION);
acc->connectid.desc_tag = cpu_to_be32(FCNVME_LSDESC_CONN_ID);
acc->connectid.desc_len =
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_conn_id));
acc->connectid.connection_id =
cpu_to_be64(nvmet_fc_makeconnid(iod->assoc,
be16_to_cpu(rqst->connect_cmd.qid)));
}
static void
nvmet_fc_ls_disconnect(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_ls_iod *iod)
{
struct fcnvme_ls_disconnect_rqst *rqst =
(struct fcnvme_ls_disconnect_rqst *)iod->rqstbuf;
struct fcnvme_ls_disconnect_acc *acc =
(struct fcnvme_ls_disconnect_acc *)iod->rspbuf;
struct nvmet_fc_tgt_queue *queue = NULL;
struct nvmet_fc_tgt_assoc *assoc;
int ret = 0;
bool del_assoc = false;
memset(acc, 0, sizeof(*acc));
if (iod->rqstdatalen < sizeof(struct fcnvme_ls_disconnect_rqst))
ret = VERR_DISCONN_LEN;
else if (rqst->desc_list_len !=
fcnvme_lsdesc_len(
sizeof(struct fcnvme_ls_disconnect_rqst)))
ret = VERR_DISCONN_RQST_LEN;
else if (rqst->associd.desc_tag != cpu_to_be32(FCNVME_LSDESC_ASSOC_ID))
ret = VERR_ASSOC_ID;
else if (rqst->associd.desc_len !=
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_assoc_id)))
ret = VERR_ASSOC_ID_LEN;
else if (rqst->discon_cmd.desc_tag !=
cpu_to_be32(FCNVME_LSDESC_DISCONN_CMD))
ret = VERR_DISCONN_CMD;
else if (rqst->discon_cmd.desc_len !=
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_disconn_cmd)))
ret = VERR_DISCONN_CMD_LEN;
else if ((rqst->discon_cmd.scope != FCNVME_DISCONN_ASSOCIATION) &&
(rqst->discon_cmd.scope != FCNVME_DISCONN_CONNECTION))
ret = VERR_DISCONN_SCOPE;
else {
assoc = nvmet_fc_find_target_assoc(tgtport,
be64_to_cpu(rqst->associd.association_id));
iod->assoc = assoc;
if (assoc) {
if (rqst->discon_cmd.scope ==
FCNVME_DISCONN_CONNECTION) {
queue = nvmet_fc_find_target_queue(tgtport,
be64_to_cpu(
rqst->discon_cmd.id));
if (!queue) {
nvmet_fc_tgt_a_put(assoc);
ret = VERR_NO_CONN;
}
}
} else
ret = VERR_NO_ASSOC;
}
if (ret) {
dev_err(tgtport->dev,
"Disconnect LS failed: %s\n",
validation_errors[ret]);
iod->lsreq->rsplen = nvmet_fc_format_rjt(acc,
NVME_FC_MAX_LS_BUFFER_SIZE, rqst->w0.ls_cmd,
(ret == VERR_NO_ASSOC) ?
FCNVME_RJT_RC_INV_ASSOC :
(ret == VERR_NO_CONN) ?
FCNVME_RJT_RC_INV_CONN :
FCNVME_RJT_RC_LOGIC,
FCNVME_RJT_EXP_NONE, 0);
return;
}
iod->lsreq->rsplen = sizeof(*acc);
nvmet_fc_format_rsp_hdr(acc, FCNVME_LS_ACC,
fcnvme_lsdesc_len(
sizeof(struct fcnvme_ls_disconnect_acc)),
FCNVME_LS_DISCONNECT);
if (queue) {
int qid = queue->qid;
nvmet_fc_delete_target_queue(queue);
nvmet_fc_tgt_q_put(queue);
if (!qid)
del_assoc = true;
}
nvmet_fc_tgt_a_put(iod->assoc);
if (del_assoc)
nvmet_fc_delete_target_assoc(iod->assoc);
}
static void
nvmet_fc_xmt_ls_rsp_done(struct nvmefc_tgt_ls_req *lsreq)
{
struct nvmet_fc_ls_iod *iod = lsreq->nvmet_fc_private;
struct nvmet_fc_tgtport *tgtport = iod->tgtport;
fc_dma_sync_single_for_cpu(tgtport->dev, iod->rspdma,
NVME_FC_MAX_LS_BUFFER_SIZE, DMA_TO_DEVICE);
nvmet_fc_free_ls_iod(tgtport, iod);
nvmet_fc_tgtport_put(tgtport);
}
static void
nvmet_fc_xmt_ls_rsp(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_ls_iod *iod)
{
int ret;
fc_dma_sync_single_for_device(tgtport->dev, iod->rspdma,
NVME_FC_MAX_LS_BUFFER_SIZE, DMA_TO_DEVICE);
ret = tgtport->ops->xmt_ls_rsp(&tgtport->fc_target_port, iod->lsreq);
if (ret)
nvmet_fc_xmt_ls_rsp_done(iod->lsreq);
}
static void
nvmet_fc_handle_ls_rqst(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_ls_iod *iod)
{
struct fcnvme_ls_rqst_w0 *w0 =
(struct fcnvme_ls_rqst_w0 *)iod->rqstbuf;
iod->lsreq->nvmet_fc_private = iod;
iod->lsreq->rspbuf = iod->rspbuf;
iod->lsreq->rspdma = iod->rspdma;
iod->lsreq->done = nvmet_fc_xmt_ls_rsp_done;
iod->lsreq->rsplen = 0;
iod->assoc = NULL;
switch (w0->ls_cmd) {
case FCNVME_LS_CREATE_ASSOCIATION:
nvmet_fc_ls_create_association(tgtport, iod);
break;
case FCNVME_LS_CREATE_CONNECTION:
nvmet_fc_ls_create_connection(tgtport, iod);
break;
case FCNVME_LS_DISCONNECT:
nvmet_fc_ls_disconnect(tgtport, iod);
break;
default:
iod->lsreq->rsplen = nvmet_fc_format_rjt(iod->rspbuf,
NVME_FC_MAX_LS_BUFFER_SIZE, w0->ls_cmd,
FCNVME_RJT_RC_INVAL, FCNVME_RJT_EXP_NONE, 0);
}
nvmet_fc_xmt_ls_rsp(tgtport, iod);
}
static void
nvmet_fc_handle_ls_rqst_work(struct work_struct *work)
{
struct nvmet_fc_ls_iod *iod =
container_of(work, struct nvmet_fc_ls_iod, work);
struct nvmet_fc_tgtport *tgtport = iod->tgtport;
nvmet_fc_handle_ls_rqst(tgtport, iod);
}
int
nvmet_fc_rcv_ls_req(struct nvmet_fc_target_port *target_port,
struct nvmefc_tgt_ls_req *lsreq,
void *lsreqbuf, u32 lsreqbuf_len)
{
struct nvmet_fc_tgtport *tgtport = targetport_to_tgtport(target_port);
struct nvmet_fc_ls_iod *iod;
if (lsreqbuf_len > NVME_FC_MAX_LS_BUFFER_SIZE)
return -E2BIG;
if (!nvmet_fc_tgtport_get(tgtport))
return -ESHUTDOWN;
iod = nvmet_fc_alloc_ls_iod(tgtport);
if (!iod) {
nvmet_fc_tgtport_put(tgtport);
return -ENOENT;
}
iod->lsreq = lsreq;
iod->fcpreq = NULL;
memcpy(iod->rqstbuf, lsreqbuf, lsreqbuf_len);
iod->rqstdatalen = lsreqbuf_len;
schedule_work(&iod->work);
return 0;
}
static int
nvmet_fc_alloc_tgt_pgs(struct nvmet_fc_fcp_iod *fod)
{
struct scatterlist *sg;
struct page *page;
unsigned int nent;
u32 page_len, length;
int i = 0;
length = fod->total_length;
nent = DIV_ROUND_UP(length, PAGE_SIZE);
sg = kmalloc_array(nent, sizeof(struct scatterlist), GFP_KERNEL);
if (!sg)
goto out;
sg_init_table(sg, nent);
while (length) {
page_len = min_t(u32, length, PAGE_SIZE);
page = alloc_page(GFP_KERNEL);
if (!page)
goto out_free_pages;
sg_set_page(&sg[i], page, page_len, 0);
length -= page_len;
i++;
}
fod->data_sg = sg;
fod->data_sg_cnt = nent;
fod->data_sg_cnt = fc_dma_map_sg(fod->tgtport->dev, sg, nent,
((fod->io_dir == NVMET_FCP_WRITE) ?
DMA_FROM_DEVICE : DMA_TO_DEVICE));
return 0;
out_free_pages:
while (i > 0) {
i--;
__free_page(sg_page(&sg[i]));
}
kfree(sg);
fod->data_sg = NULL;
fod->data_sg_cnt = 0;
out:
return NVME_SC_INTERNAL;
}
static void
nvmet_fc_free_tgt_pgs(struct nvmet_fc_fcp_iod *fod)
{
struct scatterlist *sg;
int count;
if (!fod->data_sg || !fod->data_sg_cnt)
return;
fc_dma_unmap_sg(fod->tgtport->dev, fod->data_sg, fod->data_sg_cnt,
((fod->io_dir == NVMET_FCP_WRITE) ?
DMA_FROM_DEVICE : DMA_TO_DEVICE));
for_each_sg(fod->data_sg, sg, fod->data_sg_cnt, count)
__free_page(sg_page(sg));
kfree(fod->data_sg);
fod->data_sg = NULL;
fod->data_sg_cnt = 0;
}
static bool
queue_90percent_full(struct nvmet_fc_tgt_queue *q, u32 sqhd)
{
u32 sqtail, used;
sqtail = atomic_read(&q->sqtail) % q->sqsize;
used = (sqtail < sqhd) ? (sqtail + q->sqsize - sqhd) : (sqtail - sqhd);
return ((used * 10) >= (((u32)(q->sqsize - 1) * 9)));
}
static void
nvmet_fc_prep_fcp_rsp(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_fcp_iod *fod)
{
struct nvme_fc_ersp_iu *ersp = &fod->rspiubuf;
struct nvme_common_command *sqe = &fod->cmdiubuf.sqe.common;
struct nvme_completion *cqe = &ersp->cqe;
u32 *cqewd = (u32 *)cqe;
bool send_ersp = false;
u32 rsn, rspcnt, xfr_length;
if (fod->fcpreq->op == NVMET_FCOP_READDATA_RSP)
xfr_length = fod->total_length;
else
xfr_length = fod->offset;
rspcnt = atomic_inc_return(&fod->queue->zrspcnt);
if (!(rspcnt % fod->queue->ersp_ratio) ||
sqe->opcode == nvme_fabrics_command ||
xfr_length != fod->total_length ||
(le16_to_cpu(cqe->status) & 0xFFFE) || cqewd[0] || cqewd[1] ||
(sqe->flags & (NVME_CMD_FUSE_FIRST | NVME_CMD_FUSE_SECOND)) ||
queue_90percent_full(fod->queue, le16_to_cpu(cqe->sq_head)))
send_ersp = true;
fod->fcpreq->rspaddr = ersp;
fod->fcpreq->rspdma = fod->rspdma;
if (!send_ersp) {
memset(ersp, 0, NVME_FC_SIZEOF_ZEROS_RSP);
fod->fcpreq->rsplen = NVME_FC_SIZEOF_ZEROS_RSP;
} else {
ersp->iu_len = cpu_to_be16(sizeof(*ersp)/sizeof(u32));
rsn = atomic_inc_return(&fod->queue->rsn);
ersp->rsn = cpu_to_be32(rsn);
ersp->xfrd_len = cpu_to_be32(xfr_length);
fod->fcpreq->rsplen = sizeof(*ersp);
}
fc_dma_sync_single_for_device(tgtport->dev, fod->rspdma,
sizeof(fod->rspiubuf), DMA_TO_DEVICE);
}
static void
nvmet_fc_abort_op(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_fcp_iod *fod)
{
struct nvmefc_tgt_fcp_req *fcpreq = fod->fcpreq;
nvmet_fc_free_tgt_pgs(fod);
if (!fod->aborted)
tgtport->ops->fcp_abort(&tgtport->fc_target_port, fcpreq);
nvmet_fc_free_fcp_iod(fod->queue, fod);
}
static void
nvmet_fc_xmt_fcp_rsp(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_fcp_iod *fod)
{
int ret;
fod->fcpreq->op = NVMET_FCOP_RSP;
fod->fcpreq->timeout = 0;
nvmet_fc_prep_fcp_rsp(tgtport, fod);
ret = tgtport->ops->fcp_op(&tgtport->fc_target_port, fod->fcpreq);
if (ret)
nvmet_fc_abort_op(tgtport, fod);
}
static void
nvmet_fc_transfer_fcp_data(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_fcp_iod *fod, u8 op)
{
struct nvmefc_tgt_fcp_req *fcpreq = fod->fcpreq;
struct scatterlist *sg, *datasg;
unsigned long flags;
u32 tlen, sg_off;
int ret;
fcpreq->op = op;
fcpreq->offset = fod->offset;
fcpreq->timeout = NVME_FC_TGTOP_TIMEOUT_SEC;
tlen = min_t(u32, (NVMET_FC_MAX_KB_PER_XFR * 1024),
(fod->total_length - fod->offset));
tlen = min_t(u32, tlen, NVME_FC_MAX_SEGMENTS * PAGE_SIZE);
tlen = min_t(u32, tlen, fod->tgtport->ops->max_sgl_segments
* PAGE_SIZE);
fcpreq->transfer_length = tlen;
fcpreq->transferred_length = 0;
fcpreq->fcp_error = 0;
fcpreq->rsplen = 0;
fcpreq->sg_cnt = 0;
datasg = fod->next_sg;
sg_off = fod->next_sg_offset;
for (sg = fcpreq->sg ; tlen; sg++) {
*sg = *datasg;
if (sg_off) {
sg->offset += sg_off;
sg->length -= sg_off;
sg->dma_address += sg_off;
sg_off = 0;
}
if (tlen < sg->length) {
sg->length = tlen;
fod->next_sg = datasg;
fod->next_sg_offset += tlen;
} else if (tlen == sg->length) {
fod->next_sg_offset = 0;
fod->next_sg = sg_next(datasg);
} else {
fod->next_sg_offset = 0;
datasg = sg_next(datasg);
}
tlen -= sg->length;
fcpreq->sg_cnt++;
}
if ((op == NVMET_FCOP_READDATA) &&
((fod->offset + fcpreq->transfer_length) == fod->total_length) &&
(tgtport->ops->target_features & NVMET_FCTGTFEAT_READDATA_RSP)) {
fcpreq->op = NVMET_FCOP_READDATA_RSP;
nvmet_fc_prep_fcp_rsp(tgtport, fod);
}
ret = tgtport->ops->fcp_op(&tgtport->fc_target_port, fod->fcpreq);
if (ret) {
fod->abort = true;
if (op == NVMET_FCOP_WRITEDATA) {
spin_lock_irqsave(&fod->flock, flags);
fod->writedataactive = false;
spin_unlock_irqrestore(&fod->flock, flags);
nvmet_req_complete(&fod->req,
NVME_SC_FC_TRANSPORT_ERROR);
} else {
fcpreq->fcp_error = ret;
fcpreq->transferred_length = 0;
nvmet_fc_xmt_fcp_op_done(fod->fcpreq);
}
}
}
static inline bool
__nvmet_fc_fod_op_abort(struct nvmet_fc_fcp_iod *fod, bool abort)
{
struct nvmefc_tgt_fcp_req *fcpreq = fod->fcpreq;
struct nvmet_fc_tgtport *tgtport = fod->tgtport;
if (abort) {
if (fcpreq->op == NVMET_FCOP_WRITEDATA) {
nvmet_req_complete(&fod->req,
NVME_SC_FC_TRANSPORT_ERROR);
return true;
}
nvmet_fc_abort_op(tgtport, fod);
return true;
}
return false;
}
static void
nvmet_fc_fod_op_done(struct nvmet_fc_fcp_iod *fod)
{
struct nvmefc_tgt_fcp_req *fcpreq = fod->fcpreq;
struct nvmet_fc_tgtport *tgtport = fod->tgtport;
unsigned long flags;
bool abort;
spin_lock_irqsave(&fod->flock, flags);
abort = fod->abort;
fod->writedataactive = false;
spin_unlock_irqrestore(&fod->flock, flags);
switch (fcpreq->op) {
case NVMET_FCOP_WRITEDATA:
if (__nvmet_fc_fod_op_abort(fod, abort))
return;
if (fcpreq->fcp_error ||
fcpreq->transferred_length != fcpreq->transfer_length) {
spin_lock(&fod->flock);
fod->abort = true;
spin_unlock(&fod->flock);
nvmet_req_complete(&fod->req,
NVME_SC_FC_TRANSPORT_ERROR);
return;
}
fod->offset += fcpreq->transferred_length;
if (fod->offset != fod->total_length) {
spin_lock_irqsave(&fod->flock, flags);
fod->writedataactive = true;
spin_unlock_irqrestore(&fod->flock, flags);
nvmet_fc_transfer_fcp_data(tgtport, fod,
NVMET_FCOP_WRITEDATA);
return;
}
fod->req.execute(&fod->req);
break;
case NVMET_FCOP_READDATA:
case NVMET_FCOP_READDATA_RSP:
if (__nvmet_fc_fod_op_abort(fod, abort))
return;
if (fcpreq->fcp_error ||
fcpreq->transferred_length != fcpreq->transfer_length) {
nvmet_fc_abort_op(tgtport, fod);
return;
}
if (fcpreq->op == NVMET_FCOP_READDATA_RSP) {
nvmet_fc_free_tgt_pgs(fod);
nvmet_fc_free_fcp_iod(fod->queue, fod);
return;
}
fod->offset += fcpreq->transferred_length;
if (fod->offset != fod->total_length) {
nvmet_fc_transfer_fcp_data(tgtport, fod,
NVMET_FCOP_READDATA);
return;
}
nvmet_fc_free_tgt_pgs(fod);
nvmet_fc_xmt_fcp_rsp(tgtport, fod);
break;
case NVMET_FCOP_RSP:
if (__nvmet_fc_fod_op_abort(fod, abort))
return;
nvmet_fc_free_fcp_iod(fod->queue, fod);
break;
default:
break;
}
}
static void
nvmet_fc_fcp_rqst_op_done_work(struct work_struct *work)
{
struct nvmet_fc_fcp_iod *fod =
container_of(work, struct nvmet_fc_fcp_iod, done_work);
nvmet_fc_fod_op_done(fod);
}
static void
nvmet_fc_xmt_fcp_op_done(struct nvmefc_tgt_fcp_req *fcpreq)
{
struct nvmet_fc_fcp_iod *fod = fcpreq->nvmet_fc_private;
struct nvmet_fc_tgt_queue *queue = fod->queue;
if (fod->tgtport->ops->target_features & NVMET_FCTGTFEAT_OPDONE_IN_ISR)
queue_work_on(queue->cpu, queue->work_q, &fod->done_work);
else
nvmet_fc_fod_op_done(fod);
}
static void
__nvmet_fc_fcp_nvme_cmd_done(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_fcp_iod *fod, int status)
{
struct nvme_common_command *sqe = &fod->cmdiubuf.sqe.common;
struct nvme_completion *cqe = &fod->rspiubuf.cqe;
unsigned long flags;
bool abort;
spin_lock_irqsave(&fod->flock, flags);
abort = fod->abort;
spin_unlock_irqrestore(&fod->flock, flags);
if (!status)
fod->queue->sqhd = cqe->sq_head;
if (abort) {
nvmet_fc_abort_op(tgtport, fod);
return;
}
if (status) {
memset(cqe, 0, sizeof(*cqe));
cqe->sq_head = fod->queue->sqhd;
cqe->sq_id = cpu_to_le16(fod->queue->qid);
cqe->command_id = sqe->command_id;
cqe->status = cpu_to_le16(status);
} else {
if ((fod->io_dir == NVMET_FCP_READ) && (fod->data_sg_cnt)) {
nvmet_fc_transfer_fcp_data(tgtport, fod,
NVMET_FCOP_READDATA);
return;
}
}
nvmet_fc_free_tgt_pgs(fod);
nvmet_fc_xmt_fcp_rsp(tgtport, fod);
}
static void
nvmet_fc_fcp_nvme_cmd_done(struct nvmet_req *nvme_req)
{
struct nvmet_fc_fcp_iod *fod = nvmet_req_to_fod(nvme_req);
struct nvmet_fc_tgtport *tgtport = fod->tgtport;
__nvmet_fc_fcp_nvme_cmd_done(tgtport, fod, 0);
}
static void
nvmet_fc_handle_fcp_rqst(struct nvmet_fc_tgtport *tgtport,
struct nvmet_fc_fcp_iod *fod)
{
struct nvme_fc_cmd_iu *cmdiu = &fod->cmdiubuf;
int ret;
fod->fcpreq->done = nvmet_fc_xmt_fcp_op_done;
fod->total_length = be32_to_cpu(cmdiu->data_len);
if (cmdiu->flags & FCNVME_CMD_FLAGS_WRITE) {
fod->io_dir = NVMET_FCP_WRITE;
if (!nvme_is_write(&cmdiu->sqe))
goto transport_error;
} else if (cmdiu->flags & FCNVME_CMD_FLAGS_READ) {
fod->io_dir = NVMET_FCP_READ;
if (nvme_is_write(&cmdiu->sqe))
goto transport_error;
} else {
fod->io_dir = NVMET_FCP_NODATA;
if (fod->total_length)
goto transport_error;
}
fod->req.cmd = &fod->cmdiubuf.sqe;
fod->req.rsp = &fod->rspiubuf.cqe;
fod->req.port = fod->queue->port;
fod->req.execute = NULL;
memset(&fod->rspiubuf, 0, sizeof(fod->rspiubuf));
fod->data_sg = NULL;
fod->data_sg_cnt = 0;
ret = nvmet_req_init(&fod->req,
&fod->queue->nvme_cq,
&fod->queue->nvme_sq,
&nvmet_fc_tgt_fcp_ops);
if (!ret) {
return;
}
atomic_inc(&fod->queue->sqtail);
if (fod->total_length) {
ret = nvmet_fc_alloc_tgt_pgs(fod);
if (ret) {
nvmet_req_complete(&fod->req, ret);
return;
}
}
fod->req.sg = fod->data_sg;
fod->req.sg_cnt = fod->data_sg_cnt;
fod->offset = 0;
fod->next_sg = fod->data_sg;
fod->next_sg_offset = 0;
if (fod->io_dir == NVMET_FCP_WRITE) {
nvmet_fc_transfer_fcp_data(tgtport, fod, NVMET_FCOP_WRITEDATA);
return;
}
fod->req.execute(&fod->req);
return;
transport_error:
nvmet_fc_abort_op(tgtport, fod);
}
static void
nvmet_fc_handle_fcp_rqst_work(struct work_struct *work)
{
struct nvmet_fc_fcp_iod *fod =
container_of(work, struct nvmet_fc_fcp_iod, work);
struct nvmet_fc_tgtport *tgtport = fod->tgtport;
nvmet_fc_handle_fcp_rqst(tgtport, fod);
}
int
nvmet_fc_rcv_fcp_req(struct nvmet_fc_target_port *target_port,
struct nvmefc_tgt_fcp_req *fcpreq,
void *cmdiubuf, u32 cmdiubuf_len)
{
struct nvmet_fc_tgtport *tgtport = targetport_to_tgtport(target_port);
struct nvme_fc_cmd_iu *cmdiu = cmdiubuf;
struct nvmet_fc_tgt_queue *queue;
struct nvmet_fc_fcp_iod *fod;
struct nvmet_fc_defer_fcp_req *deferfcp;
unsigned long flags;
if ((cmdiubuf_len != sizeof(*cmdiu)) ||
(cmdiu->scsi_id != NVME_CMD_SCSI_ID) ||
(cmdiu->fc_id != NVME_CMD_FC_ID) ||
(be16_to_cpu(cmdiu->iu_len) != (sizeof(*cmdiu)/4)))
return -EIO;
queue = nvmet_fc_find_target_queue(tgtport,
be64_to_cpu(cmdiu->connection_id));
if (!queue)
return -ENOTCONN;
spin_lock_irqsave(&queue->qlock, flags);
fod = nvmet_fc_alloc_fcp_iod(queue);
if (fod) {
spin_unlock_irqrestore(&queue->qlock, flags);
fcpreq->nvmet_fc_private = fod;
fod->fcpreq = fcpreq;
memcpy(&fod->cmdiubuf, cmdiubuf, cmdiubuf_len);
nvmet_fc_queue_fcp_req(tgtport, queue, fcpreq);
return 0;
}
if (!tgtport->ops->defer_rcv) {
spin_unlock_irqrestore(&queue->qlock, flags);
nvmet_fc_tgt_q_put(queue);
return -ENOENT;
}
deferfcp = list_first_entry_or_null(&queue->avail_defer_list,
struct nvmet_fc_defer_fcp_req, req_list);
if (deferfcp) {
list_del(&deferfcp->req_list);
} else {
spin_unlock_irqrestore(&queue->qlock, flags);
deferfcp = kmalloc(sizeof(*deferfcp), GFP_KERNEL);
if (!deferfcp) {
nvmet_fc_tgt_q_put(queue);
return -ENOMEM;
}
spin_lock_irqsave(&queue->qlock, flags);
}
fcpreq->rspaddr = cmdiubuf;
fcpreq->rsplen = cmdiubuf_len;
deferfcp->fcp_req = fcpreq;
list_add_tail(&deferfcp->req_list, &queue->pending_cmd_list);
spin_unlock_irqrestore(&queue->qlock, flags);
return -EOVERFLOW;
}
void
nvmet_fc_rcv_fcp_abort(struct nvmet_fc_target_port *target_port,
struct nvmefc_tgt_fcp_req *fcpreq)
{
struct nvmet_fc_fcp_iod *fod = fcpreq->nvmet_fc_private;
struct nvmet_fc_tgt_queue *queue;
unsigned long flags;
if (!fod || fod->fcpreq != fcpreq)
return;
queue = fod->queue;
spin_lock_irqsave(&queue->qlock, flags);
if (fod->active) {
spin_lock(&fod->flock);
fod->abort = true;
fod->aborted = true;
spin_unlock(&fod->flock);
}
spin_unlock_irqrestore(&queue->qlock, flags);
}
static int
__nvme_fc_parse_u64(substring_t *sstr, u64 *val)
{
u64 token64;
if (match_u64(sstr, &token64))
return -EINVAL;
*val = token64;
return 0;
}
static int
nvme_fc_parse_traddr(struct nvmet_fc_traddr *traddr, char *buf, size_t blen)
{
char name[2 + NVME_FC_TRADDR_HEXNAMELEN + 1];
substring_t wwn = { name, &name[sizeof(name)-1] };
int nnoffset, pnoffset;
if (strnlen(buf, blen) == NVME_FC_TRADDR_MAXLENGTH &&
!strncmp(buf, "nn-0x", NVME_FC_TRADDR_OXNNLEN) &&
!strncmp(&buf[NVME_FC_TRADDR_MAX_PN_OFFSET],
"pn-0x", NVME_FC_TRADDR_OXNNLEN)) {
nnoffset = NVME_FC_TRADDR_OXNNLEN;
pnoffset = NVME_FC_TRADDR_MAX_PN_OFFSET +
NVME_FC_TRADDR_OXNNLEN;
} else if ((strnlen(buf, blen) == NVME_FC_TRADDR_MINLENGTH &&
!strncmp(buf, "nn-", NVME_FC_TRADDR_NNLEN) &&
!strncmp(&buf[NVME_FC_TRADDR_MIN_PN_OFFSET],
"pn-", NVME_FC_TRADDR_NNLEN))) {
nnoffset = NVME_FC_TRADDR_NNLEN;
pnoffset = NVME_FC_TRADDR_MIN_PN_OFFSET + NVME_FC_TRADDR_NNLEN;
} else
goto out_einval;
name[0] = '0';
name[1] = 'x';
name[2 + NVME_FC_TRADDR_HEXNAMELEN] = 0;
memcpy(&name[2], &buf[nnoffset], NVME_FC_TRADDR_HEXNAMELEN);
if (__nvme_fc_parse_u64(&wwn, &traddr->nn))
goto out_einval;
memcpy(&name[2], &buf[pnoffset], NVME_FC_TRADDR_HEXNAMELEN);
if (__nvme_fc_parse_u64(&wwn, &traddr->pn))
goto out_einval;
return 0;
out_einval:
pr_warn("%s: bad traddr string\n", __func__);
return -EINVAL;
}
static int
nvmet_fc_add_port(struct nvmet_port *port)
{
struct nvmet_fc_tgtport *tgtport;
struct nvmet_fc_traddr traddr = { 0L, 0L };
unsigned long flags;
int ret;
if ((port->disc_addr.trtype != NVMF_TRTYPE_FC) ||
(port->disc_addr.adrfam != NVMF_ADDR_FAMILY_FC))
return -EINVAL;
ret = nvme_fc_parse_traddr(&traddr, port->disc_addr.traddr,
sizeof(port->disc_addr.traddr));
if (ret)
return ret;
ret = -ENXIO;
spin_lock_irqsave(&nvmet_fc_tgtlock, flags);
list_for_each_entry(tgtport, &nvmet_fc_target_list, tgt_list) {
if ((tgtport->fc_target_port.node_name == traddr.nn) &&
(tgtport->fc_target_port.port_name == traddr.pn)) {
if (!tgtport->port) {
tgtport->port = port;
port->priv = tgtport;
nvmet_fc_tgtport_get(tgtport);
ret = 0;
} else
ret = -EALREADY;
break;
}
}
spin_unlock_irqrestore(&nvmet_fc_tgtlock, flags);
return ret;
}
static void
nvmet_fc_remove_port(struct nvmet_port *port)
{
struct nvmet_fc_tgtport *tgtport = port->priv;
unsigned long flags;
spin_lock_irqsave(&nvmet_fc_tgtlock, flags);
if (tgtport->port == port) {
nvmet_fc_tgtport_put(tgtport);
tgtport->port = NULL;
}
spin_unlock_irqrestore(&nvmet_fc_tgtlock, flags);
}
static int __init nvmet_fc_init_module(void)
{
return nvmet_register_transport(&nvmet_fc_tgt_fcp_ops);
}
static void __exit nvmet_fc_exit_module(void)
{
if (!list_empty(&nvmet_fc_target_list))
pr_warn("%s: targetport list not empty\n", __func__);
nvmet_unregister_transport(&nvmet_fc_tgt_fcp_ops);
ida_destroy(&nvmet_fc_tgtport_cnt);
}
