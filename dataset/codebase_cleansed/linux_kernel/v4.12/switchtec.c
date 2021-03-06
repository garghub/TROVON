static struct switchtec_dev *to_stdev(struct device *dev)
{
return container_of(dev, struct switchtec_dev, dev);
}
static struct switchtec_user *stuser_create(struct switchtec_dev *stdev)
{
struct switchtec_user *stuser;
stuser = kzalloc(sizeof(*stuser), GFP_KERNEL);
if (!stuser)
return ERR_PTR(-ENOMEM);
get_device(&stdev->dev);
stuser->stdev = stdev;
kref_init(&stuser->kref);
INIT_LIST_HEAD(&stuser->list);
init_completion(&stuser->comp);
stuser->event_cnt = atomic_read(&stdev->event_cnt);
dev_dbg(&stdev->dev, "%s: %p\n", __func__, stuser);
return stuser;
}
static void stuser_free(struct kref *kref)
{
struct switchtec_user *stuser;
stuser = container_of(kref, struct switchtec_user, kref);
dev_dbg(&stuser->stdev->dev, "%s: %p\n", __func__, stuser);
put_device(&stuser->stdev->dev);
kfree(stuser);
}
static void stuser_put(struct switchtec_user *stuser)
{
kref_put(&stuser->kref, stuser_free);
}
static void stuser_set_state(struct switchtec_user *stuser,
enum mrpc_state state)
{
const char * const state_names[] = {
[MRPC_IDLE] = "IDLE",
[MRPC_QUEUED] = "QUEUED",
[MRPC_RUNNING] = "RUNNING",
[MRPC_DONE] = "DONE",
};
stuser->state = state;
dev_dbg(&stuser->stdev->dev, "stuser state %p -> %s",
stuser, state_names[state]);
}
static void mrpc_cmd_submit(struct switchtec_dev *stdev)
{
struct switchtec_user *stuser;
if (stdev->mrpc_busy)
return;
if (list_empty(&stdev->mrpc_queue))
return;
stuser = list_entry(stdev->mrpc_queue.next, struct switchtec_user,
list);
stuser_set_state(stuser, MRPC_RUNNING);
stdev->mrpc_busy = 1;
memcpy_toio(&stdev->mmio_mrpc->input_data,
stuser->data, stuser->data_len);
iowrite32(stuser->cmd, &stdev->mmio_mrpc->cmd);
stuser->status = ioread32(&stdev->mmio_mrpc->status);
if (stuser->status != SWITCHTEC_MRPC_STATUS_INPROGRESS)
mrpc_complete_cmd(stdev);
schedule_delayed_work(&stdev->mrpc_timeout,
msecs_to_jiffies(500));
}
static int mrpc_queue_cmd(struct switchtec_user *stuser)
{
struct switchtec_dev *stdev = stuser->stdev;
kref_get(&stuser->kref);
stuser->read_len = sizeof(stuser->data);
stuser_set_state(stuser, MRPC_QUEUED);
init_completion(&stuser->comp);
list_add_tail(&stuser->list, &stdev->mrpc_queue);
mrpc_cmd_submit(stdev);
return 0;
}
static void mrpc_complete_cmd(struct switchtec_dev *stdev)
{
struct switchtec_user *stuser;
if (list_empty(&stdev->mrpc_queue))
return;
stuser = list_entry(stdev->mrpc_queue.next, struct switchtec_user,
list);
stuser->status = ioread32(&stdev->mmio_mrpc->status);
if (stuser->status == SWITCHTEC_MRPC_STATUS_INPROGRESS)
return;
stuser_set_state(stuser, MRPC_DONE);
stuser->return_code = 0;
if (stuser->status != SWITCHTEC_MRPC_STATUS_DONE)
goto out;
stuser->return_code = ioread32(&stdev->mmio_mrpc->ret_value);
if (stuser->return_code != 0)
goto out;
memcpy_fromio(stuser->data, &stdev->mmio_mrpc->output_data,
stuser->read_len);
out:
complete_all(&stuser->comp);
list_del_init(&stuser->list);
stuser_put(stuser);
stdev->mrpc_busy = 0;
mrpc_cmd_submit(stdev);
}
static void mrpc_event_work(struct work_struct *work)
{
struct switchtec_dev *stdev;
stdev = container_of(work, struct switchtec_dev, mrpc_work);
dev_dbg(&stdev->dev, "%s\n", __func__);
mutex_lock(&stdev->mrpc_mutex);
cancel_delayed_work(&stdev->mrpc_timeout);
mrpc_complete_cmd(stdev);
mutex_unlock(&stdev->mrpc_mutex);
}
static void mrpc_timeout_work(struct work_struct *work)
{
struct switchtec_dev *stdev;
u32 status;
stdev = container_of(work, struct switchtec_dev, mrpc_timeout.work);
dev_dbg(&stdev->dev, "%s\n", __func__);
mutex_lock(&stdev->mrpc_mutex);
status = ioread32(&stdev->mmio_mrpc->status);
if (status == SWITCHTEC_MRPC_STATUS_INPROGRESS) {
schedule_delayed_work(&stdev->mrpc_timeout,
msecs_to_jiffies(500));
goto out;
}
mrpc_complete_cmd(stdev);
out:
mutex_unlock(&stdev->mrpc_mutex);
}
static ssize_t device_version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct switchtec_dev *stdev = to_stdev(dev);
u32 ver;
ver = ioread32(&stdev->mmio_sys_info->device_version);
return sprintf(buf, "%x\n", ver);
}
static ssize_t fw_version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct switchtec_dev *stdev = to_stdev(dev);
u32 ver;
ver = ioread32(&stdev->mmio_sys_info->firmware_version);
return sprintf(buf, "%08x\n", ver);
}
static ssize_t io_string_show(char *buf, void __iomem *attr, size_t len)
{
int i;
memcpy_fromio(buf, attr, len);
buf[len] = '\n';
buf[len + 1] = 0;
for (i = len - 1; i > 0; i--) {
if (buf[i] != ' ')
break;
buf[i] = '\n';
buf[i + 1] = 0;
}
return strlen(buf);
}
static ssize_t component_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct switchtec_dev *stdev = to_stdev(dev);
int id = ioread16(&stdev->mmio_sys_info->component_id);
return sprintf(buf, "PM%04X\n", id);
}
static ssize_t component_revision_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct switchtec_dev *stdev = to_stdev(dev);
int rev = ioread8(&stdev->mmio_sys_info->component_revision);
return sprintf(buf, "%d\n", rev);
}
static ssize_t partition_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct switchtec_dev *stdev = to_stdev(dev);
return sprintf(buf, "%d\n", stdev->partition);
}
static ssize_t partition_count_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct switchtec_dev *stdev = to_stdev(dev);
return sprintf(buf, "%d\n", stdev->partition_count);
}
static int switchtec_dev_open(struct inode *inode, struct file *filp)
{
struct switchtec_dev *stdev;
struct switchtec_user *stuser;
stdev = container_of(inode->i_cdev, struct switchtec_dev, cdev);
stuser = stuser_create(stdev);
if (IS_ERR(stuser))
return PTR_ERR(stuser);
filp->private_data = stuser;
nonseekable_open(inode, filp);
dev_dbg(&stdev->dev, "%s: %p\n", __func__, stuser);
return 0;
}
static int switchtec_dev_release(struct inode *inode, struct file *filp)
{
struct switchtec_user *stuser = filp->private_data;
stuser_put(stuser);
return 0;
}
static int lock_mutex_and_test_alive(struct switchtec_dev *stdev)
{
if (mutex_lock_interruptible(&stdev->mrpc_mutex))
return -EINTR;
if (!stdev->alive) {
mutex_unlock(&stdev->mrpc_mutex);
return -ENODEV;
}
return 0;
}
static ssize_t switchtec_dev_write(struct file *filp, const char __user *data,
size_t size, loff_t *off)
{
struct switchtec_user *stuser = filp->private_data;
struct switchtec_dev *stdev = stuser->stdev;
int rc;
if (size < sizeof(stuser->cmd) ||
size > sizeof(stuser->cmd) + sizeof(stuser->data))
return -EINVAL;
stuser->data_len = size - sizeof(stuser->cmd);
rc = lock_mutex_and_test_alive(stdev);
if (rc)
return rc;
if (stuser->state != MRPC_IDLE) {
rc = -EBADE;
goto out;
}
rc = copy_from_user(&stuser->cmd, data, sizeof(stuser->cmd));
if (rc) {
rc = -EFAULT;
goto out;
}
data += sizeof(stuser->cmd);
rc = copy_from_user(&stuser->data, data, size - sizeof(stuser->cmd));
if (rc) {
rc = -EFAULT;
goto out;
}
rc = mrpc_queue_cmd(stuser);
out:
mutex_unlock(&stdev->mrpc_mutex);
if (rc)
return rc;
return size;
}
static ssize_t switchtec_dev_read(struct file *filp, char __user *data,
size_t size, loff_t *off)
{
struct switchtec_user *stuser = filp->private_data;
struct switchtec_dev *stdev = stuser->stdev;
int rc;
if (size < sizeof(stuser->cmd) ||
size > sizeof(stuser->cmd) + sizeof(stuser->data))
return -EINVAL;
rc = lock_mutex_and_test_alive(stdev);
if (rc)
return rc;
if (stuser->state == MRPC_IDLE) {
mutex_unlock(&stdev->mrpc_mutex);
return -EBADE;
}
stuser->read_len = size - sizeof(stuser->return_code);
mutex_unlock(&stdev->mrpc_mutex);
if (filp->f_flags & O_NONBLOCK) {
if (!try_wait_for_completion(&stuser->comp))
return -EAGAIN;
} else {
rc = wait_for_completion_interruptible(&stuser->comp);
if (rc < 0)
return rc;
}
rc = lock_mutex_and_test_alive(stdev);
if (rc)
return rc;
if (stuser->state != MRPC_DONE) {
mutex_unlock(&stdev->mrpc_mutex);
return -EBADE;
}
rc = copy_to_user(data, &stuser->return_code,
sizeof(stuser->return_code));
if (rc) {
rc = -EFAULT;
goto out;
}
data += sizeof(stuser->return_code);
rc = copy_to_user(data, &stuser->data,
size - sizeof(stuser->return_code));
if (rc) {
rc = -EFAULT;
goto out;
}
stuser_set_state(stuser, MRPC_IDLE);
out:
mutex_unlock(&stdev->mrpc_mutex);
if (stuser->status == SWITCHTEC_MRPC_STATUS_DONE)
return size;
else if (stuser->status == SWITCHTEC_MRPC_STATUS_INTERRUPTED)
return -ENXIO;
else
return -EBADMSG;
}
static unsigned int switchtec_dev_poll(struct file *filp, poll_table *wait)
{
struct switchtec_user *stuser = filp->private_data;
struct switchtec_dev *stdev = stuser->stdev;
int ret = 0;
poll_wait(filp, &stuser->comp.wait, wait);
poll_wait(filp, &stdev->event_wq, wait);
if (lock_mutex_and_test_alive(stdev))
return POLLIN | POLLRDHUP | POLLOUT | POLLERR | POLLHUP;
mutex_unlock(&stdev->mrpc_mutex);
if (try_wait_for_completion(&stuser->comp))
ret |= POLLIN | POLLRDNORM;
if (stuser->event_cnt != atomic_read(&stdev->event_cnt))
ret |= POLLPRI | POLLRDBAND;
return ret;
}
static int ioctl_flash_info(struct switchtec_dev *stdev,
struct switchtec_ioctl_flash_info __user *uinfo)
{
struct switchtec_ioctl_flash_info info = {0};
struct flash_info_regs __iomem *fi = stdev->mmio_flash_info;
info.flash_length = ioread32(&fi->flash_length);
info.num_partitions = SWITCHTEC_IOCTL_NUM_PARTITIONS;
if (copy_to_user(uinfo, &info, sizeof(info)))
return -EFAULT;
return 0;
}
static void set_fw_info_part(struct switchtec_ioctl_flash_part_info *info,
struct partition_info __iomem *pi)
{
info->address = ioread32(&pi->address);
info->length = ioread32(&pi->length);
}
static int ioctl_flash_part_info(struct switchtec_dev *stdev,
struct switchtec_ioctl_flash_part_info __user *uinfo)
{
struct switchtec_ioctl_flash_part_info info = {0};
struct flash_info_regs __iomem *fi = stdev->mmio_flash_info;
u32 active_addr = -1;
if (copy_from_user(&info, uinfo, sizeof(info)))
return -EFAULT;
switch (info.flash_partition) {
case SWITCHTEC_IOCTL_PART_CFG0:
active_addr = ioread32(&fi->active_cfg);
set_fw_info_part(&info, &fi->cfg0);
break;
case SWITCHTEC_IOCTL_PART_CFG1:
active_addr = ioread32(&fi->active_cfg);
set_fw_info_part(&info, &fi->cfg1);
break;
case SWITCHTEC_IOCTL_PART_IMG0:
active_addr = ioread32(&fi->active_img);
set_fw_info_part(&info, &fi->img0);
break;
case SWITCHTEC_IOCTL_PART_IMG1:
active_addr = ioread32(&fi->active_img);
set_fw_info_part(&info, &fi->img1);
break;
case SWITCHTEC_IOCTL_PART_NVLOG:
set_fw_info_part(&info, &fi->nvlog);
break;
case SWITCHTEC_IOCTL_PART_VENDOR0:
set_fw_info_part(&info, &fi->vendor[0]);
break;
case SWITCHTEC_IOCTL_PART_VENDOR1:
set_fw_info_part(&info, &fi->vendor[1]);
break;
case SWITCHTEC_IOCTL_PART_VENDOR2:
set_fw_info_part(&info, &fi->vendor[2]);
break;
case SWITCHTEC_IOCTL_PART_VENDOR3:
set_fw_info_part(&info, &fi->vendor[3]);
break;
case SWITCHTEC_IOCTL_PART_VENDOR4:
set_fw_info_part(&info, &fi->vendor[4]);
break;
case SWITCHTEC_IOCTL_PART_VENDOR5:
set_fw_info_part(&info, &fi->vendor[5]);
break;
case SWITCHTEC_IOCTL_PART_VENDOR6:
set_fw_info_part(&info, &fi->vendor[6]);
break;
case SWITCHTEC_IOCTL_PART_VENDOR7:
set_fw_info_part(&info, &fi->vendor[7]);
break;
default:
return -EINVAL;
}
if (info.address == active_addr)
info.active = 1;
if (copy_to_user(uinfo, &info, sizeof(info)))
return -EFAULT;
return 0;
}
static int ioctl_event_summary(struct switchtec_dev *stdev,
struct switchtec_user *stuser,
struct switchtec_ioctl_event_summary __user *usum)
{
struct switchtec_ioctl_event_summary s = {0};
int i;
u32 reg;
s.global = ioread32(&stdev->mmio_sw_event->global_summary);
s.part_bitmap = ioread32(&stdev->mmio_sw_event->part_event_bitmap);
s.local_part = ioread32(&stdev->mmio_part_cfg->part_event_summary);
for (i = 0; i < stdev->partition_count; i++) {
reg = ioread32(&stdev->mmio_part_cfg_all[i].part_event_summary);
s.part[i] = reg;
}
for (i = 0; i < SWITCHTEC_MAX_PFF_CSR; i++) {
reg = ioread16(&stdev->mmio_pff_csr[i].vendor_id);
if (reg != MICROSEMI_VENDOR_ID)
break;
reg = ioread32(&stdev->mmio_pff_csr[i].pff_event_summary);
s.pff[i] = reg;
}
if (copy_to_user(usum, &s, sizeof(s)))
return -EFAULT;
stuser->event_cnt = atomic_read(&stdev->event_cnt);
return 0;
}
static u32 __iomem *global_ev_reg(struct switchtec_dev *stdev,
size_t offset, int index)
{
return (void __iomem *)stdev->mmio_sw_event + offset;
}
static u32 __iomem *part_ev_reg(struct switchtec_dev *stdev,
size_t offset, int index)
{
return (void __iomem *)&stdev->mmio_part_cfg_all[index] + offset;
}
static u32 __iomem *pff_ev_reg(struct switchtec_dev *stdev,
size_t offset, int index)
{
return (void __iomem *)&stdev->mmio_pff_csr[index] + offset;
}
static u32 __iomem *event_hdr_addr(struct switchtec_dev *stdev,
int event_id, int index)
{
size_t off;
if (event_id < 0 || event_id >= SWITCHTEC_IOCTL_MAX_EVENTS)
return ERR_PTR(-EINVAL);
off = event_regs[event_id].offset;
if (event_regs[event_id].map_reg == part_ev_reg) {
if (index == SWITCHTEC_IOCTL_EVENT_LOCAL_PART_IDX)
index = stdev->partition;
else if (index < 0 || index >= stdev->partition_count)
return ERR_PTR(-EINVAL);
} else if (event_regs[event_id].map_reg == pff_ev_reg) {
if (index < 0 || index >= stdev->pff_csr_count)
return ERR_PTR(-EINVAL);
}
return event_regs[event_id].map_reg(stdev, off, index);
}
static int event_ctl(struct switchtec_dev *stdev,
struct switchtec_ioctl_event_ctl *ctl)
{
int i;
u32 __iomem *reg;
u32 hdr;
reg = event_hdr_addr(stdev, ctl->event_id, ctl->index);
if (IS_ERR(reg))
return PTR_ERR(reg);
hdr = ioread32(reg);
for (i = 0; i < ARRAY_SIZE(ctl->data); i++)
ctl->data[i] = ioread32(&reg[i + 1]);
ctl->occurred = hdr & SWITCHTEC_EVENT_OCCURRED;
ctl->count = (hdr >> 5) & 0xFF;
if (!(ctl->flags & SWITCHTEC_IOCTL_EVENT_FLAG_CLEAR))
hdr &= ~SWITCHTEC_EVENT_CLEAR;
if (ctl->flags & SWITCHTEC_IOCTL_EVENT_FLAG_EN_POLL)
hdr |= SWITCHTEC_EVENT_EN_IRQ;
if (ctl->flags & SWITCHTEC_IOCTL_EVENT_FLAG_DIS_POLL)
hdr &= ~SWITCHTEC_EVENT_EN_IRQ;
if (ctl->flags & SWITCHTEC_IOCTL_EVENT_FLAG_EN_LOG)
hdr |= SWITCHTEC_EVENT_EN_LOG;
if (ctl->flags & SWITCHTEC_IOCTL_EVENT_FLAG_DIS_LOG)
hdr &= ~SWITCHTEC_EVENT_EN_LOG;
if (ctl->flags & SWITCHTEC_IOCTL_EVENT_FLAG_EN_CLI)
hdr |= SWITCHTEC_EVENT_EN_CLI;
if (ctl->flags & SWITCHTEC_IOCTL_EVENT_FLAG_DIS_CLI)
hdr &= ~SWITCHTEC_EVENT_EN_CLI;
if (ctl->flags & SWITCHTEC_IOCTL_EVENT_FLAG_EN_FATAL)
hdr |= SWITCHTEC_EVENT_FATAL;
if (ctl->flags & SWITCHTEC_IOCTL_EVENT_FLAG_DIS_FATAL)
hdr &= ~SWITCHTEC_EVENT_FATAL;
if (ctl->flags)
iowrite32(hdr, reg);
ctl->flags = 0;
if (hdr & SWITCHTEC_EVENT_EN_IRQ)
ctl->flags |= SWITCHTEC_IOCTL_EVENT_FLAG_EN_POLL;
if (hdr & SWITCHTEC_EVENT_EN_LOG)
ctl->flags |= SWITCHTEC_IOCTL_EVENT_FLAG_EN_LOG;
if (hdr & SWITCHTEC_EVENT_EN_CLI)
ctl->flags |= SWITCHTEC_IOCTL_EVENT_FLAG_EN_CLI;
if (hdr & SWITCHTEC_EVENT_FATAL)
ctl->flags |= SWITCHTEC_IOCTL_EVENT_FLAG_EN_FATAL;
return 0;
}
static int ioctl_event_ctl(struct switchtec_dev *stdev,
struct switchtec_ioctl_event_ctl __user *uctl)
{
int ret;
int nr_idxs;
struct switchtec_ioctl_event_ctl ctl;
if (copy_from_user(&ctl, uctl, sizeof(ctl)))
return -EFAULT;
if (ctl.event_id >= SWITCHTEC_IOCTL_MAX_EVENTS)
return -EINVAL;
if (ctl.flags & SWITCHTEC_IOCTL_EVENT_FLAG_UNUSED)
return -EINVAL;
if (ctl.index == SWITCHTEC_IOCTL_EVENT_IDX_ALL) {
if (event_regs[ctl.event_id].map_reg == global_ev_reg)
nr_idxs = 1;
else if (event_regs[ctl.event_id].map_reg == part_ev_reg)
nr_idxs = stdev->partition_count;
else if (event_regs[ctl.event_id].map_reg == pff_ev_reg)
nr_idxs = stdev->pff_csr_count;
else
return -EINVAL;
for (ctl.index = 0; ctl.index < nr_idxs; ctl.index++) {
ret = event_ctl(stdev, &ctl);
if (ret < 0)
return ret;
}
} else {
ret = event_ctl(stdev, &ctl);
if (ret < 0)
return ret;
}
if (copy_to_user(uctl, &ctl, sizeof(ctl)))
return -EFAULT;
return 0;
}
static int ioctl_pff_to_port(struct switchtec_dev *stdev,
struct switchtec_ioctl_pff_port *up)
{
int i, part;
u32 reg;
struct part_cfg_regs *pcfg;
struct switchtec_ioctl_pff_port p;
if (copy_from_user(&p, up, sizeof(p)))
return -EFAULT;
p.port = -1;
for (part = 0; part < stdev->partition_count; part++) {
pcfg = &stdev->mmio_part_cfg_all[part];
p.partition = part;
reg = ioread32(&pcfg->usp_pff_inst_id);
if (reg == p.pff) {
p.port = 0;
break;
}
reg = ioread32(&pcfg->vep_pff_inst_id);
if (reg == p.pff) {
p.port = SWITCHTEC_IOCTL_PFF_VEP;
break;
}
for (i = 0; i < ARRAY_SIZE(pcfg->dsp_pff_inst_id); i++) {
reg = ioread32(&pcfg->dsp_pff_inst_id[i]);
if (reg != p.pff)
continue;
p.port = i + 1;
break;
}
if (p.port != -1)
break;
}
if (copy_to_user(up, &p, sizeof(p)))
return -EFAULT;
return 0;
}
static int ioctl_port_to_pff(struct switchtec_dev *stdev,
struct switchtec_ioctl_pff_port *up)
{
struct switchtec_ioctl_pff_port p;
struct part_cfg_regs *pcfg;
if (copy_from_user(&p, up, sizeof(p)))
return -EFAULT;
if (p.partition == SWITCHTEC_IOCTL_EVENT_LOCAL_PART_IDX)
pcfg = stdev->mmio_part_cfg;
else if (p.partition < stdev->partition_count)
pcfg = &stdev->mmio_part_cfg_all[p.partition];
else
return -EINVAL;
switch (p.port) {
case 0:
p.pff = ioread32(&pcfg->usp_pff_inst_id);
break;
case SWITCHTEC_IOCTL_PFF_VEP:
p.pff = ioread32(&pcfg->vep_pff_inst_id);
break;
default:
if (p.port > ARRAY_SIZE(pcfg->dsp_pff_inst_id))
return -EINVAL;
p.pff = ioread32(&pcfg->dsp_pff_inst_id[p.port - 1]);
break;
}
if (copy_to_user(up, &p, sizeof(p)))
return -EFAULT;
return 0;
}
static long switchtec_dev_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct switchtec_user *stuser = filp->private_data;
struct switchtec_dev *stdev = stuser->stdev;
int rc;
void __user *argp = (void __user *)arg;
rc = lock_mutex_and_test_alive(stdev);
if (rc)
return rc;
switch (cmd) {
case SWITCHTEC_IOCTL_FLASH_INFO:
rc = ioctl_flash_info(stdev, argp);
break;
case SWITCHTEC_IOCTL_FLASH_PART_INFO:
rc = ioctl_flash_part_info(stdev, argp);
break;
case SWITCHTEC_IOCTL_EVENT_SUMMARY:
rc = ioctl_event_summary(stdev, stuser, argp);
break;
case SWITCHTEC_IOCTL_EVENT_CTL:
rc = ioctl_event_ctl(stdev, argp);
break;
case SWITCHTEC_IOCTL_PFF_TO_PORT:
rc = ioctl_pff_to_port(stdev, argp);
break;
case SWITCHTEC_IOCTL_PORT_TO_PFF:
rc = ioctl_port_to_pff(stdev, argp);
break;
default:
rc = -ENOTTY;
break;
}
mutex_unlock(&stdev->mrpc_mutex);
return rc;
}
static void stdev_release(struct device *dev)
{
struct switchtec_dev *stdev = to_stdev(dev);
kfree(stdev);
}
static void stdev_kill(struct switchtec_dev *stdev)
{
struct switchtec_user *stuser, *tmpuser;
pci_clear_master(stdev->pdev);
cancel_delayed_work_sync(&stdev->mrpc_timeout);
mutex_lock(&stdev->mrpc_mutex);
stdev->alive = false;
list_for_each_entry_safe(stuser, tmpuser, &stdev->mrpc_queue, list) {
complete_all(&stuser->comp);
list_del_init(&stuser->list);
stuser_put(stuser);
}
mutex_unlock(&stdev->mrpc_mutex);
wake_up_interruptible(&stdev->event_wq);
}
static struct switchtec_dev *stdev_create(struct pci_dev *pdev)
{
struct switchtec_dev *stdev;
int minor;
struct device *dev;
struct cdev *cdev;
int rc;
stdev = kzalloc_node(sizeof(*stdev), GFP_KERNEL,
dev_to_node(&pdev->dev));
if (!stdev)
return ERR_PTR(-ENOMEM);
stdev->alive = true;
stdev->pdev = pdev;
INIT_LIST_HEAD(&stdev->mrpc_queue);
mutex_init(&stdev->mrpc_mutex);
stdev->mrpc_busy = 0;
INIT_WORK(&stdev->mrpc_work, mrpc_event_work);
INIT_DELAYED_WORK(&stdev->mrpc_timeout, mrpc_timeout_work);
init_waitqueue_head(&stdev->event_wq);
atomic_set(&stdev->event_cnt, 0);
dev = &stdev->dev;
device_initialize(dev);
dev->class = switchtec_class;
dev->parent = &pdev->dev;
dev->groups = switchtec_device_groups;
dev->release = stdev_release;
minor = ida_simple_get(&switchtec_minor_ida, 0, 0,
GFP_KERNEL);
if (minor < 0) {
rc = minor;
goto err_put;
}
dev->devt = MKDEV(MAJOR(switchtec_devt), minor);
dev_set_name(dev, "switchtec%d", minor);
cdev = &stdev->cdev;
cdev_init(cdev, &switchtec_fops);
cdev->owner = THIS_MODULE;
return stdev;
err_put:
put_device(&stdev->dev);
return ERR_PTR(rc);
}
static int mask_event(struct switchtec_dev *stdev, int eid, int idx)
{
size_t off = event_regs[eid].offset;
u32 __iomem *hdr_reg;
u32 hdr;
hdr_reg = event_regs[eid].map_reg(stdev, off, idx);
hdr = ioread32(hdr_reg);
if (!(hdr & SWITCHTEC_EVENT_OCCURRED && hdr & SWITCHTEC_EVENT_EN_IRQ))
return 0;
dev_dbg(&stdev->dev, "%s: %d %d %x\n", __func__, eid, idx, hdr);
hdr &= ~(SWITCHTEC_EVENT_EN_IRQ | SWITCHTEC_EVENT_OCCURRED);
iowrite32(hdr, hdr_reg);
return 1;
}
static int mask_all_events(struct switchtec_dev *stdev, int eid)
{
int idx;
int count = 0;
if (event_regs[eid].map_reg == part_ev_reg) {
for (idx = 0; idx < stdev->partition_count; idx++)
count += mask_event(stdev, eid, idx);
} else if (event_regs[eid].map_reg == pff_ev_reg) {
for (idx = 0; idx < stdev->pff_csr_count; idx++) {
if (!stdev->pff_local[idx])
continue;
count += mask_event(stdev, eid, idx);
}
} else {
count += mask_event(stdev, eid, 0);
}
return count;
}
static irqreturn_t switchtec_event_isr(int irq, void *dev)
{
struct switchtec_dev *stdev = dev;
u32 reg;
irqreturn_t ret = IRQ_NONE;
int eid, event_count = 0;
reg = ioread32(&stdev->mmio_part_cfg->mrpc_comp_hdr);
if (reg & SWITCHTEC_EVENT_OCCURRED) {
dev_dbg(&stdev->dev, "%s: mrpc comp\n", __func__);
ret = IRQ_HANDLED;
schedule_work(&stdev->mrpc_work);
iowrite32(reg, &stdev->mmio_part_cfg->mrpc_comp_hdr);
}
for (eid = 0; eid < SWITCHTEC_IOCTL_MAX_EVENTS; eid++)
event_count += mask_all_events(stdev, eid);
if (event_count) {
atomic_inc(&stdev->event_cnt);
wake_up_interruptible(&stdev->event_wq);
dev_dbg(&stdev->dev, "%s: %d events\n", __func__,
event_count);
return IRQ_HANDLED;
}
return ret;
}
static int switchtec_init_isr(struct switchtec_dev *stdev)
{
int nvecs;
int event_irq;
nvecs = pci_alloc_irq_vectors(stdev->pdev, 1, 4,
PCI_IRQ_MSIX | PCI_IRQ_MSI);
if (nvecs < 0)
return nvecs;
event_irq = ioread32(&stdev->mmio_part_cfg->vep_vector_number);
if (event_irq < 0 || event_irq >= nvecs)
return -EFAULT;
event_irq = pci_irq_vector(stdev->pdev, event_irq);
if (event_irq < 0)
return event_irq;
return devm_request_irq(&stdev->pdev->dev, event_irq,
switchtec_event_isr, 0,
KBUILD_MODNAME, stdev);
}
static void init_pff(struct switchtec_dev *stdev)
{
int i;
u32 reg;
struct part_cfg_regs *pcfg = stdev->mmio_part_cfg;
for (i = 0; i < SWITCHTEC_MAX_PFF_CSR; i++) {
reg = ioread16(&stdev->mmio_pff_csr[i].vendor_id);
if (reg != MICROSEMI_VENDOR_ID)
break;
}
stdev->pff_csr_count = i;
reg = ioread32(&pcfg->usp_pff_inst_id);
if (reg < SWITCHTEC_MAX_PFF_CSR)
stdev->pff_local[reg] = 1;
reg = ioread32(&pcfg->vep_pff_inst_id);
if (reg < SWITCHTEC_MAX_PFF_CSR)
stdev->pff_local[reg] = 1;
for (i = 0; i < ARRAY_SIZE(pcfg->dsp_pff_inst_id); i++) {
reg = ioread32(&pcfg->dsp_pff_inst_id[i]);
if (reg < SWITCHTEC_MAX_PFF_CSR)
stdev->pff_local[reg] = 1;
}
}
static int switchtec_init_pci(struct switchtec_dev *stdev,
struct pci_dev *pdev)
{
int rc;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
rc = pcim_iomap_regions(pdev, 0x1, KBUILD_MODNAME);
if (rc)
return rc;
pci_set_master(pdev);
stdev->mmio = pcim_iomap_table(pdev)[0];
stdev->mmio_mrpc = stdev->mmio + SWITCHTEC_GAS_MRPC_OFFSET;
stdev->mmio_sw_event = stdev->mmio + SWITCHTEC_GAS_SW_EVENT_OFFSET;
stdev->mmio_sys_info = stdev->mmio + SWITCHTEC_GAS_SYS_INFO_OFFSET;
stdev->mmio_flash_info = stdev->mmio + SWITCHTEC_GAS_FLASH_INFO_OFFSET;
stdev->mmio_ntb = stdev->mmio + SWITCHTEC_GAS_NTB_OFFSET;
stdev->partition = ioread8(&stdev->mmio_sys_info->partition_id);
stdev->partition_count = ioread8(&stdev->mmio_ntb->partition_count);
stdev->mmio_part_cfg_all = stdev->mmio + SWITCHTEC_GAS_PART_CFG_OFFSET;
stdev->mmio_part_cfg = &stdev->mmio_part_cfg_all[stdev->partition];
stdev->mmio_pff_csr = stdev->mmio + SWITCHTEC_GAS_PFF_CSR_OFFSET;
if (stdev->partition_count < 1)
stdev->partition_count = 1;
init_pff(stdev);
pci_set_drvdata(pdev, stdev);
return 0;
}
static int switchtec_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct switchtec_dev *stdev;
int rc;
stdev = stdev_create(pdev);
if (IS_ERR(stdev))
return PTR_ERR(stdev);
rc = switchtec_init_pci(stdev, pdev);
if (rc)
goto err_put;
rc = switchtec_init_isr(stdev);
if (rc) {
dev_err(&stdev->dev, "failed to init isr.\n");
goto err_put;
}
iowrite32(SWITCHTEC_EVENT_CLEAR |
SWITCHTEC_EVENT_EN_IRQ,
&stdev->mmio_part_cfg->mrpc_comp_hdr);
rc = cdev_device_add(&stdev->cdev, &stdev->dev);
if (rc)
goto err_devadd;
dev_info(&stdev->dev, "Management device registered.\n");
return 0;
err_devadd:
stdev_kill(stdev);
err_put:
ida_simple_remove(&switchtec_minor_ida, MINOR(stdev->dev.devt));
put_device(&stdev->dev);
return rc;
}
static void switchtec_pci_remove(struct pci_dev *pdev)
{
struct switchtec_dev *stdev = pci_get_drvdata(pdev);
pci_set_drvdata(pdev, NULL);
cdev_device_del(&stdev->cdev, &stdev->dev);
ida_simple_remove(&switchtec_minor_ida, MINOR(stdev->dev.devt));
dev_info(&stdev->dev, "unregistered.\n");
stdev_kill(stdev);
put_device(&stdev->dev);
}
static int __init switchtec_init(void)
{
int rc;
rc = alloc_chrdev_region(&switchtec_devt, 0, max_devices,
"switchtec");
if (rc)
return rc;
switchtec_class = class_create(THIS_MODULE, "switchtec");
if (IS_ERR(switchtec_class)) {
rc = PTR_ERR(switchtec_class);
goto err_create_class;
}
rc = pci_register_driver(&switchtec_pci_driver);
if (rc)
goto err_pci_register;
pr_info(KBUILD_MODNAME ": loaded.\n");
return 0;
err_pci_register:
class_destroy(switchtec_class);
err_create_class:
unregister_chrdev_region(switchtec_devt, max_devices);
return rc;
}
static void __exit switchtec_exit(void)
{
pci_unregister_driver(&switchtec_pci_driver);
class_destroy(switchtec_class);
unregister_chrdev_region(switchtec_devt, max_devices);
ida_destroy(&switchtec_minor_ida);
pr_info(KBUILD_MODNAME ": unloaded.\n");
}
