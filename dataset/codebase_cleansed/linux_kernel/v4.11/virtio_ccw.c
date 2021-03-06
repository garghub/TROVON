static struct virtio_ccw_device *to_vc_device(struct virtio_device *vdev)
{
return container_of(vdev, struct virtio_ccw_device, vdev);
}
static void drop_airq_indicator(struct virtqueue *vq, struct airq_info *info)
{
unsigned long i, flags;
write_lock_irqsave(&info->lock, flags);
for (i = 0; i < airq_iv_end(info->aiv); i++) {
if (vq == (void *)airq_iv_get_ptr(info->aiv, i)) {
airq_iv_free_bit(info->aiv, i);
airq_iv_set_ptr(info->aiv, i, 0);
break;
}
}
write_unlock_irqrestore(&info->lock, flags);
}
static void virtio_airq_handler(struct airq_struct *airq)
{
struct airq_info *info = container_of(airq, struct airq_info, airq);
unsigned long ai;
inc_irq_stat(IRQIO_VAI);
read_lock(&info->lock);
for (ai = 0;;) {
ai = airq_iv_scan(info->aiv, ai, airq_iv_end(info->aiv));
if (ai == -1UL)
break;
vring_interrupt(0, (void *)airq_iv_get_ptr(info->aiv, ai));
}
info->summary_indicator = 0;
smp_wmb();
for (ai = 0;;) {
ai = airq_iv_scan(info->aiv, ai, airq_iv_end(info->aiv));
if (ai == -1UL)
break;
vring_interrupt(0, (void *)airq_iv_get_ptr(info->aiv, ai));
}
read_unlock(&info->lock);
}
static struct airq_info *new_airq_info(void)
{
struct airq_info *info;
int rc;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return NULL;
rwlock_init(&info->lock);
info->aiv = airq_iv_create(VIRTIO_IV_BITS, AIRQ_IV_ALLOC | AIRQ_IV_PTR);
if (!info->aiv) {
kfree(info);
return NULL;
}
info->airq.handler = virtio_airq_handler;
info->airq.lsi_ptr = &info->summary_indicator;
info->airq.lsi_mask = 0xff;
info->airq.isc = VIRTIO_AIRQ_ISC;
rc = register_adapter_interrupt(&info->airq);
if (rc) {
airq_iv_release(info->aiv);
kfree(info);
return NULL;
}
return info;
}
static unsigned long get_airq_indicator(struct virtqueue *vqs[], int nvqs,
u64 *first, void **airq_info)
{
int i, j;
struct airq_info *info;
unsigned long indicator_addr = 0;
unsigned long bit, flags;
for (i = 0; i < MAX_AIRQ_AREAS && !indicator_addr; i++) {
if (!airq_areas[i])
airq_areas[i] = new_airq_info();
info = airq_areas[i];
if (!info)
return 0;
write_lock_irqsave(&info->lock, flags);
bit = airq_iv_alloc(info->aiv, nvqs);
if (bit == -1UL) {
write_unlock_irqrestore(&info->lock, flags);
continue;
}
*first = bit;
*airq_info = info;
indicator_addr = (unsigned long)info->aiv->vector;
for (j = 0; j < nvqs; j++) {
airq_iv_set_ptr(info->aiv, bit + j,
(unsigned long)vqs[j]);
}
write_unlock_irqrestore(&info->lock, flags);
}
return indicator_addr;
}
static void virtio_ccw_drop_indicators(struct virtio_ccw_device *vcdev)
{
struct virtio_ccw_vq_info *info;
list_for_each_entry(info, &vcdev->virtqueues, node)
drop_airq_indicator(info->vq, vcdev->airq_info);
}
static int doing_io(struct virtio_ccw_device *vcdev, __u32 flag)
{
unsigned long flags;
__u32 ret;
spin_lock_irqsave(get_ccwdev_lock(vcdev->cdev), flags);
if (vcdev->err)
ret = 0;
else
ret = vcdev->curr_io & flag;
spin_unlock_irqrestore(get_ccwdev_lock(vcdev->cdev), flags);
return ret;
}
static int ccw_io_helper(struct virtio_ccw_device *vcdev,
struct ccw1 *ccw, __u32 intparm)
{
int ret;
unsigned long flags;
int flag = intparm & VIRTIO_CCW_INTPARM_MASK;
do {
spin_lock_irqsave(get_ccwdev_lock(vcdev->cdev), flags);
ret = ccw_device_start(vcdev->cdev, ccw, intparm, 0, 0);
if (!ret) {
if (!vcdev->curr_io)
vcdev->err = 0;
vcdev->curr_io |= flag;
}
spin_unlock_irqrestore(get_ccwdev_lock(vcdev->cdev), flags);
cpu_relax();
} while (ret == -EBUSY);
wait_event(vcdev->wait_q, doing_io(vcdev, flag) == 0);
return ret ? ret : vcdev->err;
}
static void virtio_ccw_drop_indicator(struct virtio_ccw_device *vcdev,
struct ccw1 *ccw)
{
int ret;
unsigned long *indicatorp = NULL;
struct virtio_thinint_area *thinint_area = NULL;
struct airq_info *airq_info = vcdev->airq_info;
if (vcdev->is_thinint) {
thinint_area = kzalloc(sizeof(*thinint_area),
GFP_DMA | GFP_KERNEL);
if (!thinint_area)
return;
thinint_area->summary_indicator =
(unsigned long) &airq_info->summary_indicator;
thinint_area->isc = VIRTIO_AIRQ_ISC;
ccw->cmd_code = CCW_CMD_SET_IND_ADAPTER;
ccw->count = sizeof(*thinint_area);
ccw->cda = (__u32)(unsigned long) thinint_area;
} else {
indicatorp = kmalloc(sizeof(&vcdev->indicators),
GFP_DMA | GFP_KERNEL);
if (!indicatorp)
return;
*indicatorp = 0;
ccw->cmd_code = CCW_CMD_SET_IND;
ccw->count = sizeof(&vcdev->indicators);
ccw->cda = (__u32)(unsigned long) indicatorp;
}
vcdev->indicators = 0;
ccw->flags = 0;
ret = ccw_io_helper(vcdev, ccw,
vcdev->is_thinint ?
VIRTIO_CCW_DOING_SET_IND_ADAPTER :
VIRTIO_CCW_DOING_SET_IND);
if (ret && (ret != -ENODEV))
dev_info(&vcdev->cdev->dev,
"Failed to deregister indicators (%d)\n", ret);
else if (vcdev->is_thinint)
virtio_ccw_drop_indicators(vcdev);
kfree(indicatorp);
kfree(thinint_area);
}
static inline long __do_kvm_notify(struct subchannel_id schid,
unsigned long queue_index,
long cookie)
{
register unsigned long __nr asm("1") = KVM_S390_VIRTIO_CCW_NOTIFY;
register struct subchannel_id __schid asm("2") = schid;
register unsigned long __index asm("3") = queue_index;
register long __rc asm("2");
register long __cookie asm("4") = cookie;
asm volatile ("diag 2,4,0x500\n"
: "=d" (__rc) : "d" (__nr), "d" (__schid), "d" (__index),
"d"(__cookie)
: "memory", "cc");
return __rc;
}
static inline long do_kvm_notify(struct subchannel_id schid,
unsigned long queue_index,
long cookie)
{
diag_stat_inc(DIAG_STAT_X500);
return __do_kvm_notify(schid, queue_index, cookie);
}
static bool virtio_ccw_kvm_notify(struct virtqueue *vq)
{
struct virtio_ccw_vq_info *info = vq->priv;
struct virtio_ccw_device *vcdev;
struct subchannel_id schid;
vcdev = to_vc_device(info->vq->vdev);
ccw_device_get_schid(vcdev->cdev, &schid);
info->cookie = do_kvm_notify(schid, vq->index, info->cookie);
if (info->cookie < 0)
return false;
return true;
}
static int virtio_ccw_read_vq_conf(struct virtio_ccw_device *vcdev,
struct ccw1 *ccw, int index)
{
int ret;
vcdev->config_block->index = index;
ccw->cmd_code = CCW_CMD_READ_VQ_CONF;
ccw->flags = 0;
ccw->count = sizeof(struct vq_config_block);
ccw->cda = (__u32)(unsigned long)(vcdev->config_block);
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_READ_VQ_CONF);
if (ret)
return ret;
return vcdev->config_block->num;
}
static void virtio_ccw_del_vq(struct virtqueue *vq, struct ccw1 *ccw)
{
struct virtio_ccw_device *vcdev = to_vc_device(vq->vdev);
struct virtio_ccw_vq_info *info = vq->priv;
unsigned long flags;
unsigned long size;
int ret;
unsigned int index = vq->index;
spin_lock_irqsave(&vcdev->lock, flags);
list_del(&info->node);
spin_unlock_irqrestore(&vcdev->lock, flags);
if (vcdev->revision == 0) {
info->info_block->l.queue = 0;
info->info_block->l.align = 0;
info->info_block->l.index = index;
info->info_block->l.num = 0;
ccw->count = sizeof(info->info_block->l);
} else {
info->info_block->s.desc = 0;
info->info_block->s.index = index;
info->info_block->s.num = 0;
info->info_block->s.avail = 0;
info->info_block->s.used = 0;
ccw->count = sizeof(info->info_block->s);
}
ccw->cmd_code = CCW_CMD_SET_VQ;
ccw->flags = 0;
ccw->cda = (__u32)(unsigned long)(info->info_block);
ret = ccw_io_helper(vcdev, ccw,
VIRTIO_CCW_DOING_SET_VQ | index);
if (ret && (ret != -ENODEV))
dev_warn(&vq->vdev->dev, "Error %d while deleting queue %d\n",
ret, index);
vring_del_virtqueue(vq);
size = PAGE_ALIGN(vring_size(info->num, KVM_VIRTIO_CCW_RING_ALIGN));
free_pages_exact(info->queue, size);
kfree(info->info_block);
kfree(info);
}
static void virtio_ccw_del_vqs(struct virtio_device *vdev)
{
struct virtqueue *vq, *n;
struct ccw1 *ccw;
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return;
virtio_ccw_drop_indicator(vcdev, ccw);
list_for_each_entry_safe(vq, n, &vdev->vqs, list)
virtio_ccw_del_vq(vq, ccw);
kfree(ccw);
}
static struct virtqueue *virtio_ccw_setup_vq(struct virtio_device *vdev,
int i, vq_callback_t *callback,
const char *name,
struct ccw1 *ccw)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
int err;
struct virtqueue *vq = NULL;
struct virtio_ccw_vq_info *info;
unsigned long size = 0;
unsigned long flags;
info = kzalloc(sizeof(struct virtio_ccw_vq_info), GFP_KERNEL);
if (!info) {
dev_warn(&vcdev->cdev->dev, "no info\n");
err = -ENOMEM;
goto out_err;
}
info->info_block = kzalloc(sizeof(*info->info_block),
GFP_DMA | GFP_KERNEL);
if (!info->info_block) {
dev_warn(&vcdev->cdev->dev, "no info block\n");
err = -ENOMEM;
goto out_err;
}
info->num = virtio_ccw_read_vq_conf(vcdev, ccw, i);
if (info->num < 0) {
err = info->num;
goto out_err;
}
size = PAGE_ALIGN(vring_size(info->num, KVM_VIRTIO_CCW_RING_ALIGN));
info->queue = alloc_pages_exact(size, GFP_KERNEL | __GFP_ZERO);
if (info->queue == NULL) {
dev_warn(&vcdev->cdev->dev, "no queue\n");
err = -ENOMEM;
goto out_err;
}
vq = vring_new_virtqueue(i, info->num, KVM_VIRTIO_CCW_RING_ALIGN, vdev,
true, info->queue, virtio_ccw_kvm_notify,
callback, name);
if (!vq) {
dev_warn(&vcdev->cdev->dev, "no vq\n");
err = -ENOMEM;
goto out_err;
}
if (vcdev->revision == 0) {
info->info_block->l.queue = (__u64)info->queue;
info->info_block->l.align = KVM_VIRTIO_CCW_RING_ALIGN;
info->info_block->l.index = i;
info->info_block->l.num = info->num;
ccw->count = sizeof(info->info_block->l);
} else {
info->info_block->s.desc = (__u64)info->queue;
info->info_block->s.index = i;
info->info_block->s.num = info->num;
info->info_block->s.avail = (__u64)virtqueue_get_avail(vq);
info->info_block->s.used = (__u64)virtqueue_get_used(vq);
ccw->count = sizeof(info->info_block->s);
}
ccw->cmd_code = CCW_CMD_SET_VQ;
ccw->flags = 0;
ccw->cda = (__u32)(unsigned long)(info->info_block);
err = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_SET_VQ | i);
if (err) {
dev_warn(&vcdev->cdev->dev, "SET_VQ failed\n");
goto out_err;
}
info->vq = vq;
vq->priv = info;
spin_lock_irqsave(&vcdev->lock, flags);
list_add(&info->node, &vcdev->virtqueues);
spin_unlock_irqrestore(&vcdev->lock, flags);
return vq;
out_err:
if (vq)
vring_del_virtqueue(vq);
if (info) {
if (info->queue)
free_pages_exact(info->queue, size);
kfree(info->info_block);
}
kfree(info);
return ERR_PTR(err);
}
static int virtio_ccw_register_adapter_ind(struct virtio_ccw_device *vcdev,
struct virtqueue *vqs[], int nvqs,
struct ccw1 *ccw)
{
int ret;
struct virtio_thinint_area *thinint_area = NULL;
struct airq_info *info;
thinint_area = kzalloc(sizeof(*thinint_area), GFP_DMA | GFP_KERNEL);
if (!thinint_area) {
ret = -ENOMEM;
goto out;
}
thinint_area->indicator = get_airq_indicator(vqs, nvqs,
&thinint_area->bit_nr,
&vcdev->airq_info);
if (!thinint_area->indicator) {
ret = -ENOSPC;
goto out;
}
info = vcdev->airq_info;
thinint_area->summary_indicator =
(unsigned long) &info->summary_indicator;
thinint_area->isc = VIRTIO_AIRQ_ISC;
ccw->cmd_code = CCW_CMD_SET_IND_ADAPTER;
ccw->flags = CCW_FLAG_SLI;
ccw->count = sizeof(*thinint_area);
ccw->cda = (__u32)(unsigned long)thinint_area;
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_SET_IND_ADAPTER);
if (ret) {
if (ret == -EOPNOTSUPP) {
virtio_ccw_use_airq = 0;
pr_info("Adapter interrupts unsupported on host\n");
} else
dev_warn(&vcdev->cdev->dev,
"enabling adapter interrupts = %d\n", ret);
virtio_ccw_drop_indicators(vcdev);
}
out:
kfree(thinint_area);
return ret;
}
static int virtio_ccw_find_vqs(struct virtio_device *vdev, unsigned nvqs,
struct virtqueue *vqs[],
vq_callback_t *callbacks[],
const char * const names[],
struct irq_affinity *desc)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
unsigned long *indicatorp = NULL;
int ret, i;
struct ccw1 *ccw;
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return -ENOMEM;
for (i = 0; i < nvqs; ++i) {
vqs[i] = virtio_ccw_setup_vq(vdev, i, callbacks[i], names[i],
ccw);
if (IS_ERR(vqs[i])) {
ret = PTR_ERR(vqs[i]);
vqs[i] = NULL;
goto out;
}
}
ret = -ENOMEM;
indicatorp = kmalloc(sizeof(&vcdev->indicators), GFP_DMA | GFP_KERNEL);
if (!indicatorp)
goto out;
*indicatorp = (unsigned long) &vcdev->indicators;
if (vcdev->is_thinint) {
ret = virtio_ccw_register_adapter_ind(vcdev, vqs, nvqs, ccw);
if (ret)
vcdev->is_thinint = false;
}
if (!vcdev->is_thinint) {
vcdev->indicators = 0;
ccw->cmd_code = CCW_CMD_SET_IND;
ccw->flags = 0;
ccw->count = sizeof(&vcdev->indicators);
ccw->cda = (__u32)(unsigned long) indicatorp;
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_SET_IND);
if (ret)
goto out;
}
*indicatorp = (unsigned long) &vcdev->indicators2;
vcdev->indicators2 = 0;
ccw->cmd_code = CCW_CMD_SET_CONF_IND;
ccw->flags = 0;
ccw->count = sizeof(&vcdev->indicators2);
ccw->cda = (__u32)(unsigned long) indicatorp;
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_SET_CONF_IND);
if (ret)
goto out;
kfree(indicatorp);
kfree(ccw);
return 0;
out:
kfree(indicatorp);
kfree(ccw);
virtio_ccw_del_vqs(vdev);
return ret;
}
static void virtio_ccw_reset(struct virtio_device *vdev)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
struct ccw1 *ccw;
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return;
*vcdev->status = 0;
ccw->cmd_code = CCW_CMD_VDEV_RESET;
ccw->flags = 0;
ccw->count = 0;
ccw->cda = 0;
ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_RESET);
kfree(ccw);
}
static u64 virtio_ccw_get_features(struct virtio_device *vdev)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
struct virtio_feature_desc *features;
int ret;
u64 rc;
struct ccw1 *ccw;
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return 0;
features = kzalloc(sizeof(*features), GFP_DMA | GFP_KERNEL);
if (!features) {
rc = 0;
goto out_free;
}
features->index = 0;
ccw->cmd_code = CCW_CMD_READ_FEAT;
ccw->flags = 0;
ccw->count = sizeof(*features);
ccw->cda = (__u32)(unsigned long)features;
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_READ_FEAT);
if (ret) {
rc = 0;
goto out_free;
}
rc = le32_to_cpu(features->features);
if (vcdev->revision == 0)
goto out_free;
features->index = 1;
ccw->cmd_code = CCW_CMD_READ_FEAT;
ccw->flags = 0;
ccw->count = sizeof(*features);
ccw->cda = (__u32)(unsigned long)features;
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_READ_FEAT);
if (ret == 0)
rc |= (u64)le32_to_cpu(features->features) << 32;
out_free:
kfree(features);
kfree(ccw);
return rc;
}
static int virtio_ccw_finalize_features(struct virtio_device *vdev)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
struct virtio_feature_desc *features;
struct ccw1 *ccw;
int ret;
if (vcdev->revision >= 1 &&
!__virtio_test_bit(vdev, VIRTIO_F_VERSION_1)) {
dev_err(&vdev->dev, "virtio: device uses revision 1 "
"but does not have VIRTIO_F_VERSION_1\n");
return -EINVAL;
}
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return -ENOMEM;
features = kzalloc(sizeof(*features), GFP_DMA | GFP_KERNEL);
if (!features) {
ret = -ENOMEM;
goto out_free;
}
vring_transport_features(vdev);
features->index = 0;
features->features = cpu_to_le32((u32)vdev->features);
ccw->cmd_code = CCW_CMD_WRITE_FEAT;
ccw->flags = 0;
ccw->count = sizeof(*features);
ccw->cda = (__u32)(unsigned long)features;
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_WRITE_FEAT);
if (ret)
goto out_free;
if (vcdev->revision == 0)
goto out_free;
features->index = 1;
features->features = cpu_to_le32(vdev->features >> 32);
ccw->cmd_code = CCW_CMD_WRITE_FEAT;
ccw->flags = 0;
ccw->count = sizeof(*features);
ccw->cda = (__u32)(unsigned long)features;
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_WRITE_FEAT);
out_free:
kfree(features);
kfree(ccw);
return ret;
}
static void virtio_ccw_get_config(struct virtio_device *vdev,
unsigned int offset, void *buf, unsigned len)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
int ret;
struct ccw1 *ccw;
void *config_area;
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return;
config_area = kzalloc(VIRTIO_CCW_CONFIG_SIZE, GFP_DMA | GFP_KERNEL);
if (!config_area)
goto out_free;
ccw->cmd_code = CCW_CMD_READ_CONF;
ccw->flags = 0;
ccw->count = offset + len;
ccw->cda = (__u32)(unsigned long)config_area;
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_READ_CONFIG);
if (ret)
goto out_free;
memcpy(vcdev->config, config_area, offset + len);
if (buf)
memcpy(buf, &vcdev->config[offset], len);
if (vcdev->config_ready < offset + len)
vcdev->config_ready = offset + len;
out_free:
kfree(config_area);
kfree(ccw);
}
static void virtio_ccw_set_config(struct virtio_device *vdev,
unsigned int offset, const void *buf,
unsigned len)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
struct ccw1 *ccw;
void *config_area;
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return;
config_area = kzalloc(VIRTIO_CCW_CONFIG_SIZE, GFP_DMA | GFP_KERNEL);
if (!config_area)
goto out_free;
if (vcdev->config_ready < offset)
virtio_ccw_get_config(vdev, 0, NULL, offset);
memcpy(&vcdev->config[offset], buf, len);
memcpy(config_area, vcdev->config, sizeof(vcdev->config));
ccw->cmd_code = CCW_CMD_WRITE_CONF;
ccw->flags = 0;
ccw->count = offset + len;
ccw->cda = (__u32)(unsigned long)config_area;
ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_WRITE_CONFIG);
out_free:
kfree(config_area);
kfree(ccw);
}
static u8 virtio_ccw_get_status(struct virtio_device *vdev)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
u8 old_status = *vcdev->status;
struct ccw1 *ccw;
if (vcdev->revision < 1)
return *vcdev->status;
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return old_status;
ccw->cmd_code = CCW_CMD_READ_STATUS;
ccw->flags = 0;
ccw->count = sizeof(*vcdev->status);
ccw->cda = (__u32)(unsigned long)vcdev->status;
ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_READ_STATUS);
kfree(ccw);
return *vcdev->status;
}
static void virtio_ccw_set_status(struct virtio_device *vdev, u8 status)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
u8 old_status = *vcdev->status;
struct ccw1 *ccw;
int ret;
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return;
*vcdev->status = status;
ccw->cmd_code = CCW_CMD_WRITE_STATUS;
ccw->flags = 0;
ccw->count = sizeof(status);
ccw->cda = (__u32)(unsigned long)vcdev->status;
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_WRITE_STATUS);
if (ret)
*vcdev->status = old_status;
kfree(ccw);
}
static void virtio_ccw_release_dev(struct device *_d)
{
struct virtio_device *dev = dev_to_virtio(_d);
struct virtio_ccw_device *vcdev = to_vc_device(dev);
kfree(vcdev->status);
kfree(vcdev->config_block);
kfree(vcdev);
}
static int irb_is_error(struct irb *irb)
{
if (scsw_cstat(&irb->scsw) != 0)
return 1;
if (scsw_dstat(&irb->scsw) & ~(DEV_STAT_CHN_END | DEV_STAT_DEV_END))
return 1;
if (scsw_cc(&irb->scsw) != 0)
return 1;
return 0;
}
static struct virtqueue *virtio_ccw_vq_by_ind(struct virtio_ccw_device *vcdev,
int index)
{
struct virtio_ccw_vq_info *info;
unsigned long flags;
struct virtqueue *vq;
vq = NULL;
spin_lock_irqsave(&vcdev->lock, flags);
list_for_each_entry(info, &vcdev->virtqueues, node) {
if (info->vq->index == index) {
vq = info->vq;
break;
}
}
spin_unlock_irqrestore(&vcdev->lock, flags);
return vq;
}
static void virtio_ccw_check_activity(struct virtio_ccw_device *vcdev,
__u32 activity)
{
if (vcdev->curr_io & activity) {
switch (activity) {
case VIRTIO_CCW_DOING_READ_FEAT:
case VIRTIO_CCW_DOING_WRITE_FEAT:
case VIRTIO_CCW_DOING_READ_CONFIG:
case VIRTIO_CCW_DOING_WRITE_CONFIG:
case VIRTIO_CCW_DOING_WRITE_STATUS:
case VIRTIO_CCW_DOING_READ_STATUS:
case VIRTIO_CCW_DOING_SET_VQ:
case VIRTIO_CCW_DOING_SET_IND:
case VIRTIO_CCW_DOING_SET_CONF_IND:
case VIRTIO_CCW_DOING_RESET:
case VIRTIO_CCW_DOING_READ_VQ_CONF:
case VIRTIO_CCW_DOING_SET_IND_ADAPTER:
case VIRTIO_CCW_DOING_SET_VIRTIO_REV:
vcdev->curr_io &= ~activity;
wake_up(&vcdev->wait_q);
break;
default:
dev_warn(&vcdev->cdev->dev,
"Suspicious activity '%08x'\n", activity);
WARN_ON(1);
break;
}
}
}
static void virtio_ccw_int_handler(struct ccw_device *cdev,
unsigned long intparm,
struct irb *irb)
{
__u32 activity = intparm & VIRTIO_CCW_INTPARM_MASK;
struct virtio_ccw_device *vcdev = dev_get_drvdata(&cdev->dev);
int i;
struct virtqueue *vq;
if (!vcdev)
return;
if (IS_ERR(irb)) {
vcdev->err = PTR_ERR(irb);
virtio_ccw_check_activity(vcdev, activity);
return;
}
if ((intparm == 0) &&
(scsw_stctl(&irb->scsw) ==
(SCSW_STCTL_ALERT_STATUS | SCSW_STCTL_STATUS_PEND))) {
}
if (irb_is_error(irb)) {
if ((scsw_dstat(&irb->scsw) & DEV_STAT_UNIT_CHECK) &&
(irb->ecw[0] & SNS0_CMD_REJECT))
vcdev->err = -EOPNOTSUPP;
else
vcdev->err = -EIO;
}
virtio_ccw_check_activity(vcdev, activity);
for_each_set_bit(i, &vcdev->indicators,
sizeof(vcdev->indicators) * BITS_PER_BYTE) {
clear_bit(i, &vcdev->indicators);
barrier();
vq = virtio_ccw_vq_by_ind(vcdev, i);
vring_interrupt(0, vq);
}
if (test_bit(0, &vcdev->indicators2)) {
virtio_config_changed(&vcdev->vdev);
clear_bit(0, &vcdev->indicators2);
}
}
static int virtio_ccw_check_autoonline(struct ccw_device *cdev)
{
struct ccw_dev_id id;
ccw_device_get_id(cdev, &id);
if (test_bit(id.devno, devs_no_auto[id.ssid]))
return 0;
return 1;
}
static void virtio_ccw_auto_online(void *data, async_cookie_t cookie)
{
struct ccw_device *cdev = data;
int ret;
ret = ccw_device_set_online(cdev);
if (ret)
dev_warn(&cdev->dev, "Failed to set online: %d\n", ret);
}
static int virtio_ccw_probe(struct ccw_device *cdev)
{
cdev->handler = virtio_ccw_int_handler;
if (virtio_ccw_check_autoonline(cdev))
async_schedule(virtio_ccw_auto_online, cdev);
return 0;
}
static struct virtio_ccw_device *virtio_grab_drvdata(struct ccw_device *cdev)
{
unsigned long flags;
struct virtio_ccw_device *vcdev;
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
vcdev = dev_get_drvdata(&cdev->dev);
if (!vcdev || vcdev->going_away) {
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
return NULL;
}
vcdev->going_away = true;
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
return vcdev;
}
static void virtio_ccw_remove(struct ccw_device *cdev)
{
unsigned long flags;
struct virtio_ccw_device *vcdev = virtio_grab_drvdata(cdev);
if (vcdev && cdev->online) {
if (vcdev->device_lost)
virtio_break_device(&vcdev->vdev);
unregister_virtio_device(&vcdev->vdev);
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
dev_set_drvdata(&cdev->dev, NULL);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
}
cdev->handler = NULL;
}
static int virtio_ccw_offline(struct ccw_device *cdev)
{
unsigned long flags;
struct virtio_ccw_device *vcdev = virtio_grab_drvdata(cdev);
if (!vcdev)
return 0;
if (vcdev->device_lost)
virtio_break_device(&vcdev->vdev);
unregister_virtio_device(&vcdev->vdev);
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
dev_set_drvdata(&cdev->dev, NULL);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
return 0;
}
static int virtio_ccw_set_transport_rev(struct virtio_ccw_device *vcdev)
{
struct virtio_rev_info *rev;
struct ccw1 *ccw;
int ret;
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return -ENOMEM;
rev = kzalloc(sizeof(*rev), GFP_DMA | GFP_KERNEL);
if (!rev) {
kfree(ccw);
return -ENOMEM;
}
ccw->cmd_code = CCW_CMD_SET_VIRTIO_REV;
ccw->flags = 0;
ccw->count = sizeof(*rev);
ccw->cda = (__u32)(unsigned long)rev;
vcdev->revision = VIRTIO_CCW_REV_MAX;
do {
rev->revision = vcdev->revision;
rev->length = 0;
ret = ccw_io_helper(vcdev, ccw,
VIRTIO_CCW_DOING_SET_VIRTIO_REV);
if (ret == -EOPNOTSUPP) {
if (vcdev->revision == 0)
ret = 0;
else
vcdev->revision--;
}
} while (ret == -EOPNOTSUPP);
kfree(ccw);
kfree(rev);
return ret;
}
static int virtio_ccw_online(struct ccw_device *cdev)
{
int ret;
struct virtio_ccw_device *vcdev;
unsigned long flags;
vcdev = kzalloc(sizeof(*vcdev), GFP_KERNEL);
if (!vcdev) {
dev_warn(&cdev->dev, "Could not get memory for virtio\n");
ret = -ENOMEM;
goto out_free;
}
vcdev->config_block = kzalloc(sizeof(*vcdev->config_block),
GFP_DMA | GFP_KERNEL);
if (!vcdev->config_block) {
ret = -ENOMEM;
goto out_free;
}
vcdev->status = kzalloc(sizeof(*vcdev->status), GFP_DMA | GFP_KERNEL);
if (!vcdev->status) {
ret = -ENOMEM;
goto out_free;
}
vcdev->is_thinint = virtio_ccw_use_airq;
vcdev->vdev.dev.parent = &cdev->dev;
vcdev->vdev.dev.release = virtio_ccw_release_dev;
vcdev->vdev.config = &virtio_ccw_config_ops;
vcdev->cdev = cdev;
init_waitqueue_head(&vcdev->wait_q);
INIT_LIST_HEAD(&vcdev->virtqueues);
spin_lock_init(&vcdev->lock);
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
dev_set_drvdata(&cdev->dev, vcdev);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
vcdev->vdev.id.vendor = cdev->id.cu_type;
vcdev->vdev.id.device = cdev->id.cu_model;
ret = virtio_ccw_set_transport_rev(vcdev);
if (ret)
goto out_free;
ret = register_virtio_device(&vcdev->vdev);
if (ret) {
dev_warn(&cdev->dev, "Failed to register virtio device: %d\n",
ret);
goto out_put;
}
return 0;
out_put:
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
dev_set_drvdata(&cdev->dev, NULL);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
put_device(&vcdev->vdev.dev);
return ret;
out_free:
if (vcdev) {
kfree(vcdev->status);
kfree(vcdev->config_block);
}
kfree(vcdev);
return ret;
}
static int virtio_ccw_cio_notify(struct ccw_device *cdev, int event)
{
int rc;
struct virtio_ccw_device *vcdev = dev_get_drvdata(&cdev->dev);
if (!vcdev)
return NOTIFY_DONE;
switch (event) {
case CIO_GONE:
vcdev->device_lost = true;
rc = NOTIFY_DONE;
break;
default:
rc = NOTIFY_DONE;
break;
}
return rc;
}
static int __init pure_hex(char **cp, unsigned int *val, int min_digit,
int max_digit, int max_val)
{
int diff;
diff = 0;
*val = 0;
while (diff <= max_digit) {
int value = hex_to_bin(**cp);
if (value < 0)
break;
*val = *val * 16 + value;
(*cp)++;
diff++;
}
if ((diff < min_digit) || (diff > max_digit) || (*val > max_val))
return 1;
return 0;
}
static int __init parse_busid(char *str, unsigned int *cssid,
unsigned int *ssid, unsigned int *devno)
{
char *str_work;
int rc, ret;
rc = 1;
if (*str == '\0')
goto out;
str_work = str;
ret = pure_hex(&str_work, cssid, 1, 2, __MAX_CSSID);
if (ret || (str_work[0] != '.'))
goto out;
str_work++;
ret = pure_hex(&str_work, ssid, 1, 1, __MAX_SSID);
if (ret || (str_work[0] != '.'))
goto out;
str_work++;
ret = pure_hex(&str_work, devno, 4, 4, __MAX_SUBCHANNEL);
if (ret || (str_work[0] != '\0'))
goto out;
rc = 0;
out:
return rc;
}
static void __init no_auto_parse(void)
{
unsigned int from_cssid, to_cssid, from_ssid, to_ssid, from, to;
char *parm, *str;
int rc;
str = no_auto;
while ((parm = strsep(&str, ","))) {
rc = parse_busid(strsep(&parm, "-"), &from_cssid,
&from_ssid, &from);
if (rc)
continue;
if (parm != NULL) {
rc = parse_busid(parm, &to_cssid,
&to_ssid, &to);
if ((from_ssid > to_ssid) ||
((from_ssid == to_ssid) && (from > to)))
rc = -EINVAL;
} else {
to_cssid = from_cssid;
to_ssid = from_ssid;
to = from;
}
if (rc)
continue;
while ((from_ssid < to_ssid) ||
((from_ssid == to_ssid) && (from <= to))) {
set_bit(from, devs_no_auto[from_ssid]);
from++;
if (from > __MAX_SUBCHANNEL) {
from_ssid++;
from = 0;
}
}
}
}
static int __init virtio_ccw_init(void)
{
no_auto_parse();
return ccw_driver_register(&virtio_ccw_driver);
}
