static struct virtio_ccw_device *to_vc_device(struct virtio_device *vdev)
{
return container_of(vdev, struct virtio_ccw_device, vdev);
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
static inline long do_kvm_notify(struct subchannel_id schid,
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
vcdev->config_block->index = index;
ccw->cmd_code = CCW_CMD_READ_VQ_CONF;
ccw->flags = 0;
ccw->count = sizeof(struct vq_config_block);
ccw->cda = (__u32)(unsigned long)(vcdev->config_block);
ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_READ_VQ_CONF);
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
info->info_block->queue = 0;
info->info_block->align = 0;
info->info_block->index = index;
info->info_block->num = 0;
ccw->cmd_code = CCW_CMD_SET_VQ;
ccw->flags = 0;
ccw->count = sizeof(*info->info_block);
ccw->cda = (__u32)(unsigned long)(info->info_block);
ret = ccw_io_helper(vcdev, ccw,
VIRTIO_CCW_DOING_SET_VQ | index);
if (ret && (ret != -ENODEV))
dev_warn(&vq->vdev->dev, "Error %d while deleting queue %d",
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
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return;
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
info->info_block->queue = (__u64)info->queue;
info->info_block->align = KVM_VIRTIO_CCW_RING_ALIGN;
info->info_block->index = i;
info->info_block->num = info->num;
ccw->cmd_code = CCW_CMD_SET_VQ;
ccw->flags = 0;
ccw->count = sizeof(*info->info_block);
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
static int virtio_ccw_find_vqs(struct virtio_device *vdev, unsigned nvqs,
struct virtqueue *vqs[],
vq_callback_t *callbacks[],
const char *names[])
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
vcdev->indicators = 0;
ccw->cmd_code = CCW_CMD_SET_IND;
ccw->flags = 0;
ccw->count = sizeof(vcdev->indicators);
ccw->cda = (__u32)(unsigned long) indicatorp;
ret = ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_SET_IND);
if (ret)
goto out;
*indicatorp = (unsigned long) &vcdev->indicators2;
vcdev->indicators2 = 0;
ccw->cmd_code = CCW_CMD_SET_CONF_IND;
ccw->flags = 0;
ccw->count = sizeof(vcdev->indicators2);
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
static u32 virtio_ccw_get_features(struct virtio_device *vdev)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
struct virtio_feature_desc *features;
int ret, rc;
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
out_free:
kfree(features);
kfree(ccw);
return rc;
}
static void virtio_ccw_finalize_features(struct virtio_device *vdev)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
struct virtio_feature_desc *features;
int i;
struct ccw1 *ccw;
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return;
features = kzalloc(sizeof(*features), GFP_DMA | GFP_KERNEL);
if (!features)
goto out_free;
vring_transport_features(vdev);
for (i = 0; i < sizeof(*vdev->features) / sizeof(features->features);
i++) {
int highbits = i % 2 ? 32 : 0;
features->index = i;
features->features = cpu_to_le32(vdev->features[i / 2]
>> highbits);
ccw->cmd_code = CCW_CMD_WRITE_FEAT;
ccw->flags = 0;
ccw->count = sizeof(*features);
ccw->cda = (__u32)(unsigned long)features;
ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_WRITE_FEAT);
}
out_free:
kfree(features);
kfree(ccw);
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
memcpy(vcdev->config, config_area, sizeof(vcdev->config));
memcpy(buf, &vcdev->config[offset], len);
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
return *vcdev->status;
}
static void virtio_ccw_set_status(struct virtio_device *vdev, u8 status)
{
struct virtio_ccw_device *vcdev = to_vc_device(vdev);
struct ccw1 *ccw;
ccw = kzalloc(sizeof(*ccw), GFP_DMA | GFP_KERNEL);
if (!ccw)
return;
*vcdev->status = status;
ccw->cmd_code = CCW_CMD_WRITE_STATUS;
ccw->flags = 0;
ccw->count = sizeof(status);
ccw->cda = (__u32)(unsigned long)vcdev->status;
ccw_io_helper(vcdev, ccw, VIRTIO_CCW_DOING_WRITE_STATUS);
kfree(ccw);
}
static void virtio_ccw_release_dev(struct device *_d)
{
struct virtio_device *dev = container_of(_d, struct virtio_device,
dev);
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
static void virtio_ccw_int_handler(struct ccw_device *cdev,
unsigned long intparm,
struct irb *irb)
{
__u32 activity = intparm & VIRTIO_CCW_INTPARM_MASK;
struct virtio_ccw_device *vcdev = dev_get_drvdata(&cdev->dev);
int i;
struct virtqueue *vq;
struct virtio_driver *drv;
if ((intparm == 0) &&
(scsw_stctl(&irb->scsw) ==
(SCSW_STCTL_ALERT_STATUS | SCSW_STCTL_STATUS_PEND))) {
}
if (irb_is_error(irb))
vcdev->err = -EIO;
if (vcdev->curr_io & activity) {
switch (activity) {
case VIRTIO_CCW_DOING_READ_FEAT:
case VIRTIO_CCW_DOING_WRITE_FEAT:
case VIRTIO_CCW_DOING_READ_CONFIG:
case VIRTIO_CCW_DOING_WRITE_CONFIG:
case VIRTIO_CCW_DOING_WRITE_STATUS:
case VIRTIO_CCW_DOING_SET_VQ:
case VIRTIO_CCW_DOING_SET_IND:
case VIRTIO_CCW_DOING_SET_CONF_IND:
case VIRTIO_CCW_DOING_RESET:
case VIRTIO_CCW_DOING_READ_VQ_CONF:
vcdev->curr_io &= ~activity;
wake_up(&vcdev->wait_q);
break;
default:
dev_warn(&cdev->dev, "Suspicious activity '%08x'\n",
activity);
WARN_ON(1);
break;
}
}
for_each_set_bit(i, &vcdev->indicators,
sizeof(vcdev->indicators) * BITS_PER_BYTE) {
clear_bit(i, &vcdev->indicators);
barrier();
vq = virtio_ccw_vq_by_ind(vcdev, i);
vring_interrupt(0, vq);
}
if (test_bit(0, &vcdev->indicators2)) {
drv = container_of(vcdev->vdev.dev.driver,
struct virtio_driver, driver);
if (drv && drv->config_changed)
drv->config_changed(&vcdev->vdev);
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
static void virtio_ccw_remove(struct ccw_device *cdev)
{
struct virtio_ccw_device *vcdev = dev_get_drvdata(&cdev->dev);
if (cdev->online) {
unregister_virtio_device(&vcdev->vdev);
dev_set_drvdata(&cdev->dev, NULL);
}
cdev->handler = NULL;
}
static int virtio_ccw_offline(struct ccw_device *cdev)
{
struct virtio_ccw_device *vcdev = dev_get_drvdata(&cdev->dev);
unregister_virtio_device(&vcdev->vdev);
dev_set_drvdata(&cdev->dev, NULL);
return 0;
}
static int virtio_ccw_online(struct ccw_device *cdev)
{
int ret;
struct virtio_ccw_device *vcdev;
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
vcdev->vdev.dev.parent = &cdev->dev;
vcdev->vdev.dev.release = virtio_ccw_release_dev;
vcdev->vdev.config = &virtio_ccw_config_ops;
vcdev->cdev = cdev;
init_waitqueue_head(&vcdev->wait_q);
INIT_LIST_HEAD(&vcdev->virtqueues);
spin_lock_init(&vcdev->lock);
dev_set_drvdata(&cdev->dev, vcdev);
vcdev->vdev.id.vendor = cdev->id.cu_type;
vcdev->vdev.id.device = cdev->id.cu_model;
ret = register_virtio_device(&vcdev->vdev);
if (ret) {
dev_warn(&cdev->dev, "Failed to register virtio device: %d\n",
ret);
goto out_put;
}
return 0;
out_put:
dev_set_drvdata(&cdev->dev, NULL);
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
return 0;
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
static void __exit virtio_ccw_exit(void)
{
ccw_driver_unregister(&virtio_ccw_driver);
}
