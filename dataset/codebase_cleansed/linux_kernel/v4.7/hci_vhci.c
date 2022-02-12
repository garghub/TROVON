static int vhci_open_dev(struct hci_dev *hdev)
{
return 0;
}
static int vhci_close_dev(struct hci_dev *hdev)
{
struct vhci_data *data = hci_get_drvdata(hdev);
skb_queue_purge(&data->readq);
return 0;
}
static int vhci_flush(struct hci_dev *hdev)
{
struct vhci_data *data = hci_get_drvdata(hdev);
skb_queue_purge(&data->readq);
return 0;
}
static int vhci_send_frame(struct hci_dev *hdev, struct sk_buff *skb)
{
struct vhci_data *data = hci_get_drvdata(hdev);
memcpy(skb_push(skb, 1), &hci_skb_pkt_type(skb), 1);
skb_queue_tail(&data->readq, skb);
wake_up_interruptible(&data->read_wait);
return 0;
}
static int __vhci_create_device(struct vhci_data *data, __u8 opcode)
{
struct hci_dev *hdev;
struct sk_buff *skb;
__u8 dev_type;
if (data->hdev)
return -EBADFD;
dev_type = opcode & 0x03;
if (dev_type != HCI_BREDR && dev_type != HCI_AMP)
return -EINVAL;
if (opcode & 0x3c)
return -EINVAL;
skb = bt_skb_alloc(4, GFP_KERNEL);
if (!skb)
return -ENOMEM;
hdev = hci_alloc_dev();
if (!hdev) {
kfree_skb(skb);
return -ENOMEM;
}
data->hdev = hdev;
hdev->bus = HCI_VIRTUAL;
hdev->dev_type = dev_type;
hci_set_drvdata(hdev, data);
hdev->open = vhci_open_dev;
hdev->close = vhci_close_dev;
hdev->flush = vhci_flush;
hdev->send = vhci_send_frame;
if (opcode & 0x40)
set_bit(HCI_QUIRK_EXTERNAL_CONFIG, &hdev->quirks);
if (opcode & 0x80)
set_bit(HCI_QUIRK_RAW_DEVICE, &hdev->quirks);
if (hci_register_dev(hdev) < 0) {
BT_ERR("Can't register HCI device");
hci_free_dev(hdev);
data->hdev = NULL;
kfree_skb(skb);
return -EBUSY;
}
hci_skb_pkt_type(skb) = HCI_VENDOR_PKT;
*skb_put(skb, 1) = 0xff;
*skb_put(skb, 1) = opcode;
put_unaligned_le16(hdev->id, skb_put(skb, 2));
skb_queue_tail(&data->readq, skb);
wake_up_interruptible(&data->read_wait);
return 0;
}
static int vhci_create_device(struct vhci_data *data, __u8 opcode)
{
int err;
mutex_lock(&data->open_mutex);
err = __vhci_create_device(data, opcode);
mutex_unlock(&data->open_mutex);
return err;
}
static inline ssize_t vhci_get_user(struct vhci_data *data,
struct iov_iter *from)
{
size_t len = iov_iter_count(from);
struct sk_buff *skb;
__u8 pkt_type, opcode;
int ret;
if (len < 2 || len > HCI_MAX_FRAME_SIZE)
return -EINVAL;
skb = bt_skb_alloc(len, GFP_KERNEL);
if (!skb)
return -ENOMEM;
if (copy_from_iter(skb_put(skb, len), len, from) != len) {
kfree_skb(skb);
return -EFAULT;
}
pkt_type = *((__u8 *) skb->data);
skb_pull(skb, 1);
switch (pkt_type) {
case HCI_EVENT_PKT:
case HCI_ACLDATA_PKT:
case HCI_SCODATA_PKT:
if (!data->hdev) {
kfree_skb(skb);
return -ENODEV;
}
hci_skb_pkt_type(skb) = pkt_type;
ret = hci_recv_frame(data->hdev, skb);
break;
case HCI_VENDOR_PKT:
cancel_delayed_work_sync(&data->open_timeout);
opcode = *((__u8 *) skb->data);
skb_pull(skb, 1);
if (skb->len > 0) {
kfree_skb(skb);
return -EINVAL;
}
kfree_skb(skb);
ret = vhci_create_device(data, opcode);
break;
default:
kfree_skb(skb);
return -EINVAL;
}
return (ret < 0) ? ret : len;
}
static inline ssize_t vhci_put_user(struct vhci_data *data,
struct sk_buff *skb,
char __user *buf, int count)
{
char __user *ptr = buf;
int len;
len = min_t(unsigned int, skb->len, count);
if (copy_to_user(ptr, skb->data, len))
return -EFAULT;
if (!data->hdev)
return len;
data->hdev->stat.byte_tx += len;
switch (hci_skb_pkt_type(skb)) {
case HCI_COMMAND_PKT:
data->hdev->stat.cmd_tx++;
break;
case HCI_ACLDATA_PKT:
data->hdev->stat.acl_tx++;
break;
case HCI_SCODATA_PKT:
data->hdev->stat.sco_tx++;
break;
}
return len;
}
static ssize_t vhci_read(struct file *file,
char __user *buf, size_t count, loff_t *pos)
{
struct vhci_data *data = file->private_data;
struct sk_buff *skb;
ssize_t ret = 0;
while (count) {
skb = skb_dequeue(&data->readq);
if (skb) {
ret = vhci_put_user(data, skb, buf, count);
if (ret < 0)
skb_queue_head(&data->readq, skb);
else
kfree_skb(skb);
break;
}
if (file->f_flags & O_NONBLOCK) {
ret = -EAGAIN;
break;
}
ret = wait_event_interruptible(data->read_wait,
!skb_queue_empty(&data->readq));
if (ret < 0)
break;
}
return ret;
}
static ssize_t vhci_write(struct kiocb *iocb, struct iov_iter *from)
{
struct file *file = iocb->ki_filp;
struct vhci_data *data = file->private_data;
return vhci_get_user(data, from);
}
static unsigned int vhci_poll(struct file *file, poll_table *wait)
{
struct vhci_data *data = file->private_data;
poll_wait(file, &data->read_wait, wait);
if (!skb_queue_empty(&data->readq))
return POLLIN | POLLRDNORM;
return POLLOUT | POLLWRNORM;
}
static void vhci_open_timeout(struct work_struct *work)
{
struct vhci_data *data = container_of(work, struct vhci_data,
open_timeout.work);
vhci_create_device(data, amp ? HCI_AMP : HCI_BREDR);
}
static int vhci_open(struct inode *inode, struct file *file)
{
struct vhci_data *data;
data = kzalloc(sizeof(struct vhci_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
skb_queue_head_init(&data->readq);
init_waitqueue_head(&data->read_wait);
mutex_init(&data->open_mutex);
INIT_DELAYED_WORK(&data->open_timeout, vhci_open_timeout);
file->private_data = data;
nonseekable_open(inode, file);
schedule_delayed_work(&data->open_timeout, msecs_to_jiffies(1000));
return 0;
}
static int vhci_release(struct inode *inode, struct file *file)
{
struct vhci_data *data = file->private_data;
struct hci_dev *hdev;
cancel_delayed_work_sync(&data->open_timeout);
hdev = data->hdev;
if (hdev) {
hci_unregister_dev(hdev);
hci_free_dev(hdev);
}
skb_queue_purge(&data->readq);
file->private_data = NULL;
kfree(data);
return 0;
}
static int __init vhci_init(void)
{
BT_INFO("Virtual HCI driver ver %s", VERSION);
return misc_register(&vhci_miscdev);
}
static void __exit vhci_exit(void)
{
misc_deregister(&vhci_miscdev);
}
