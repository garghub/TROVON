static inline struct dpaa2_io *service_select_by_cpu(struct dpaa2_io *d,
int cpu)
{
if (d)
return d;
if (unlikely(cpu >= num_possible_cpus()))
return NULL;
if (unlikely(cpu < 0))
cpu = smp_processor_id();
return dpio_by_cpu[cpu];
}
static inline struct dpaa2_io *service_select(struct dpaa2_io *d)
{
if (d)
return d;
spin_lock(&dpio_list_lock);
d = list_entry(dpio_list.next, struct dpaa2_io, node);
list_del(&d->node);
list_add_tail(&d->node, &dpio_list);
spin_unlock(&dpio_list_lock);
return d;
}
struct dpaa2_io *dpaa2_io_create(const struct dpaa2_io_desc *desc)
{
struct dpaa2_io *obj = kmalloc(sizeof(*obj), GFP_KERNEL);
if (!obj)
return NULL;
if (desc->cpu >= num_possible_cpus()) {
kfree(obj);
return NULL;
}
atomic_set(&obj->refs, 1);
obj->dpio_desc = *desc;
obj->swp_desc.cena_bar = obj->dpio_desc.regs_cena;
obj->swp_desc.cinh_bar = obj->dpio_desc.regs_cinh;
obj->swp_desc.qman_version = obj->dpio_desc.qman_version;
obj->swp = qbman_swp_init(&obj->swp_desc);
if (!obj->swp) {
kfree(obj);
return NULL;
}
INIT_LIST_HEAD(&obj->node);
spin_lock_init(&obj->lock_mgmt_cmd);
spin_lock_init(&obj->lock_notifications);
INIT_LIST_HEAD(&obj->notifications);
qbman_swp_interrupt_set_trigger(obj->swp,
QBMAN_SWP_INTERRUPT_DQRI);
qbman_swp_interrupt_clear_status(obj->swp, 0xffffffff);
if (obj->dpio_desc.receives_notifications)
qbman_swp_push_set(obj->swp, 0, 1);
spin_lock(&dpio_list_lock);
list_add_tail(&obj->node, &dpio_list);
if (desc->cpu >= 0 && !dpio_by_cpu[desc->cpu])
dpio_by_cpu[desc->cpu] = obj;
spin_unlock(&dpio_list_lock);
return obj;
}
void dpaa2_io_down(struct dpaa2_io *d)
{
if (!atomic_dec_and_test(&d->refs))
return;
kfree(d);
}
irqreturn_t dpaa2_io_irq(struct dpaa2_io *obj)
{
const struct dpaa2_dq *dq;
int max = 0;
struct qbman_swp *swp;
u32 status;
swp = obj->swp;
status = qbman_swp_interrupt_read_status(swp);
if (!status)
return IRQ_NONE;
dq = qbman_swp_dqrr_next(swp);
while (dq) {
if (qbman_result_is_SCN(dq)) {
struct dpaa2_io_notification_ctx *ctx;
u64 q64;
q64 = qbman_result_SCN_ctx(dq);
ctx = (void *)q64;
ctx->cb(ctx);
} else {
pr_crit("fsl-mc-dpio: Unrecognised/ignored DQRR entry\n");
}
qbman_swp_dqrr_consume(swp, dq);
++max;
if (max > DPAA_POLL_MAX)
goto done;
dq = qbman_swp_dqrr_next(swp);
}
done:
qbman_swp_interrupt_clear_status(swp, status);
qbman_swp_interrupt_set_inhibit(swp, 0);
return IRQ_HANDLED;
}
int dpaa2_io_service_register(struct dpaa2_io *d,
struct dpaa2_io_notification_ctx *ctx)
{
unsigned long irqflags;
d = service_select_by_cpu(d, ctx->desired_cpu);
if (!d)
return -ENODEV;
ctx->dpio_id = d->dpio_desc.dpio_id;
ctx->qman64 = (u64)ctx;
ctx->dpio_private = d;
spin_lock_irqsave(&d->lock_notifications, irqflags);
list_add(&ctx->node, &d->notifications);
spin_unlock_irqrestore(&d->lock_notifications, irqflags);
if (ctx->is_cdan)
qbman_swp_CDAN_set_context_enable(d->swp,
(u16)ctx->id,
ctx->qman64);
return 0;
}
void dpaa2_io_service_deregister(struct dpaa2_io *service,
struct dpaa2_io_notification_ctx *ctx)
{
struct dpaa2_io *d = ctx->dpio_private;
unsigned long irqflags;
if (ctx->is_cdan)
qbman_swp_CDAN_disable(d->swp, (u16)ctx->id);
spin_lock_irqsave(&d->lock_notifications, irqflags);
list_del(&ctx->node);
spin_unlock_irqrestore(&d->lock_notifications, irqflags);
}
int dpaa2_io_service_rearm(struct dpaa2_io *d,
struct dpaa2_io_notification_ctx *ctx)
{
unsigned long irqflags;
int err;
d = service_select_by_cpu(d, ctx->desired_cpu);
if (!unlikely(d))
return -ENODEV;
spin_lock_irqsave(&d->lock_mgmt_cmd, irqflags);
if (ctx->is_cdan)
err = qbman_swp_CDAN_enable(d->swp, (u16)ctx->id);
else
err = qbman_swp_fq_schedule(d->swp, ctx->id);
spin_unlock_irqrestore(&d->lock_mgmt_cmd, irqflags);
return err;
}
int dpaa2_io_service_pull_fq(struct dpaa2_io *d, u32 fqid,
struct dpaa2_io_store *s)
{
struct qbman_pull_desc pd;
int err;
qbman_pull_desc_clear(&pd);
qbman_pull_desc_set_storage(&pd, s->vaddr, s->paddr, 1);
qbman_pull_desc_set_numframes(&pd, (u8)s->max);
qbman_pull_desc_set_fq(&pd, fqid);
d = service_select(d);
if (!d)
return -ENODEV;
s->swp = d->swp;
err = qbman_swp_pull(d->swp, &pd);
if (err)
s->swp = NULL;
return err;
}
int dpaa2_io_service_pull_channel(struct dpaa2_io *d, u32 channelid,
struct dpaa2_io_store *s)
{
struct qbman_pull_desc pd;
int err;
qbman_pull_desc_clear(&pd);
qbman_pull_desc_set_storage(&pd, s->vaddr, s->paddr, 1);
qbman_pull_desc_set_numframes(&pd, (u8)s->max);
qbman_pull_desc_set_channel(&pd, channelid, qbman_pull_type_prio);
d = service_select(d);
if (!d)
return -ENODEV;
s->swp = d->swp;
err = qbman_swp_pull(d->swp, &pd);
if (err)
s->swp = NULL;
return err;
}
int dpaa2_io_service_enqueue_fq(struct dpaa2_io *d,
u32 fqid,
const struct dpaa2_fd *fd)
{
struct qbman_eq_desc ed;
d = service_select(d);
if (!d)
return -ENODEV;
qbman_eq_desc_clear(&ed);
qbman_eq_desc_set_no_orp(&ed, 0);
qbman_eq_desc_set_fq(&ed, fqid);
return qbman_swp_enqueue(d->swp, &ed, fd);
}
int dpaa2_io_service_enqueue_qd(struct dpaa2_io *d,
u32 qdid, u8 prio, u16 qdbin,
const struct dpaa2_fd *fd)
{
struct qbman_eq_desc ed;
d = service_select(d);
if (!d)
return -ENODEV;
qbman_eq_desc_clear(&ed);
qbman_eq_desc_set_no_orp(&ed, 0);
qbman_eq_desc_set_qd(&ed, qdid, qdbin, prio);
return qbman_swp_enqueue(d->swp, &ed, fd);
}
int dpaa2_io_service_release(struct dpaa2_io *d,
u32 bpid,
const u64 *buffers,
unsigned int num_buffers)
{
struct qbman_release_desc rd;
d = service_select(d);
if (!d)
return -ENODEV;
qbman_release_desc_clear(&rd);
qbman_release_desc_set_bpid(&rd, bpid);
return qbman_swp_release(d->swp, &rd, buffers, num_buffers);
}
int dpaa2_io_service_acquire(struct dpaa2_io *d,
u32 bpid,
u64 *buffers,
unsigned int num_buffers)
{
unsigned long irqflags;
int err;
d = service_select(d);
if (!d)
return -ENODEV;
spin_lock_irqsave(&d->lock_mgmt_cmd, irqflags);
err = qbman_swp_acquire(d->swp, bpid, buffers, num_buffers);
spin_unlock_irqrestore(&d->lock_mgmt_cmd, irqflags);
return err;
}
struct dpaa2_io_store *dpaa2_io_store_create(unsigned int max_frames,
struct device *dev)
{
struct dpaa2_io_store *ret;
size_t size;
if (!max_frames || (max_frames > 16))
return NULL;
ret = kmalloc(sizeof(*ret), GFP_KERNEL);
if (!ret)
return NULL;
ret->max = max_frames;
size = max_frames * sizeof(struct dpaa2_dq) + 64;
ret->alloced_addr = kzalloc(size, GFP_KERNEL);
if (!ret->alloced_addr) {
kfree(ret);
return NULL;
}
ret->vaddr = PTR_ALIGN(ret->alloced_addr, 64);
ret->paddr = dma_map_single(dev, ret->vaddr,
sizeof(struct dpaa2_dq) * max_frames,
DMA_FROM_DEVICE);
if (dma_mapping_error(dev, ret->paddr)) {
kfree(ret->alloced_addr);
kfree(ret);
return NULL;
}
ret->idx = 0;
ret->dev = dev;
return ret;
}
void dpaa2_io_store_destroy(struct dpaa2_io_store *s)
{
dma_unmap_single(s->dev, s->paddr, sizeof(struct dpaa2_dq) * s->max,
DMA_FROM_DEVICE);
kfree(s->alloced_addr);
kfree(s);
}
struct dpaa2_dq *dpaa2_io_store_next(struct dpaa2_io_store *s, int *is_last)
{
int match;
struct dpaa2_dq *ret = &s->vaddr[s->idx];
match = qbman_result_has_new_result(s->swp, ret);
if (!match) {
*is_last = 0;
return NULL;
}
s->idx++;
if (dpaa2_dq_is_pull_complete(ret)) {
*is_last = 1;
s->idx = 0;
if (!(dpaa2_dq_flags(ret) & DPAA2_DQ_STAT_VALIDFRAME))
ret = NULL;
} else {
*is_last = 0;
}
return ret;
}
