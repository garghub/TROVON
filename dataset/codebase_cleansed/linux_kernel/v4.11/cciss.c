static void cciss_procinit(ctlr_info_t *h)
{
}
static void set_performant_mode(ctlr_info_t *h, CommandList_struct *c)
{
if (likely(h->transMethod & CFGTBL_Trans_Performant))
c->busaddr |= 1 | (h->blockFetchTable[c->Header.SGList] << 1);
}
static inline void addQ(struct list_head *list, CommandList_struct *c)
{
list_add_tail(&c->list, list);
}
static inline void removeQ(CommandList_struct *c)
{
if (WARN_ON(list_empty(&c->list))) {
c->cmd_type = CMD_MSG_STALE;
return;
}
list_del_init(&c->list);
}
static void enqueue_cmd_and_start_io(ctlr_info_t *h,
CommandList_struct *c)
{
unsigned long flags;
set_performant_mode(h, c);
spin_lock_irqsave(&h->lock, flags);
addQ(&h->reqQ, c);
h->Qdepth++;
if (h->Qdepth > h->maxQsinceinit)
h->maxQsinceinit = h->Qdepth;
start_io(h);
spin_unlock_irqrestore(&h->lock, flags);
}
static void cciss_free_sg_chain_blocks(SGDescriptor_struct **cmd_sg_list,
int nr_cmds)
{
int i;
if (!cmd_sg_list)
return;
for (i = 0; i < nr_cmds; i++) {
kfree(cmd_sg_list[i]);
cmd_sg_list[i] = NULL;
}
kfree(cmd_sg_list);
}
static SGDescriptor_struct **cciss_allocate_sg_chain_blocks(
ctlr_info_t *h, int chainsize, int nr_cmds)
{
int j;
SGDescriptor_struct **cmd_sg_list;
if (chainsize <= 0)
return NULL;
cmd_sg_list = kmalloc(sizeof(*cmd_sg_list) * nr_cmds, GFP_KERNEL);
if (!cmd_sg_list)
return NULL;
for (j = 0; j < nr_cmds; j++) {
cmd_sg_list[j] = kmalloc((chainsize *
sizeof(*cmd_sg_list[j])), GFP_KERNEL);
if (!cmd_sg_list[j]) {
dev_err(&h->pdev->dev, "Cannot get memory "
"for s/g chains.\n");
goto clean;
}
}
return cmd_sg_list;
clean:
cciss_free_sg_chain_blocks(cmd_sg_list, nr_cmds);
return NULL;
}
static void cciss_unmap_sg_chain_block(ctlr_info_t *h, CommandList_struct *c)
{
SGDescriptor_struct *chain_sg;
u64bit temp64;
if (c->Header.SGTotal <= h->max_cmd_sgentries)
return;
chain_sg = &c->SG[h->max_cmd_sgentries - 1];
temp64.val32.lower = chain_sg->Addr.lower;
temp64.val32.upper = chain_sg->Addr.upper;
pci_unmap_single(h->pdev, temp64.val, chain_sg->Len, PCI_DMA_TODEVICE);
}
static int cciss_map_sg_chain_block(ctlr_info_t *h, CommandList_struct *c,
SGDescriptor_struct *chain_block, int len)
{
SGDescriptor_struct *chain_sg;
u64bit temp64;
chain_sg = &c->SG[h->max_cmd_sgentries - 1];
chain_sg->Ext = CCISS_SG_CHAIN;
chain_sg->Len = len;
temp64.val = pci_map_single(h->pdev, chain_block, len,
PCI_DMA_TODEVICE);
if (dma_mapping_error(&h->pdev->dev, temp64.val)) {
dev_warn(&h->pdev->dev,
"%s: error mapping chain block for DMA\n",
__func__);
return -1;
}
chain_sg->Addr.lower = temp64.val32.lower;
chain_sg->Addr.upper = temp64.val32.upper;
return 0;
}
static void cciss_seq_show_header(struct seq_file *seq)
{
ctlr_info_t *h = seq->private;
seq_printf(seq, "%s: HP %s Controller\n"
"Board ID: 0x%08lx\n"
"Firmware Version: %c%c%c%c\n"
"IRQ: %d\n"
"Logical drives: %d\n"
"Current Q depth: %d\n"
"Current # commands on controller: %d\n"
"Max Q depth since init: %d\n"
"Max # commands on controller since init: %d\n"
"Max SG entries since init: %d\n",
h->devname,
h->product_name,
(unsigned long)h->board_id,
h->firm_ver[0], h->firm_ver[1], h->firm_ver[2],
h->firm_ver[3], (unsigned int)h->intr[h->intr_mode],
h->num_luns,
h->Qdepth, h->commands_outstanding,
h->maxQsinceinit, h->max_outstanding, h->maxSG);
#ifdef CONFIG_CISS_SCSI_TAPE
cciss_seq_tape_report(seq, h);
#endif
}
static void *cciss_seq_start(struct seq_file *seq, loff_t *pos)
{
ctlr_info_t *h = seq->private;
unsigned long flags;
spin_lock_irqsave(&h->lock, flags);
if (h->busy_configuring) {
spin_unlock_irqrestore(&h->lock, flags);
return ERR_PTR(-EBUSY);
}
h->busy_configuring = 1;
spin_unlock_irqrestore(&h->lock, flags);
if (*pos == 0)
cciss_seq_show_header(seq);
return pos;
}
static int cciss_seq_show(struct seq_file *seq, void *v)
{
sector_t vol_sz, vol_sz_frac;
ctlr_info_t *h = seq->private;
unsigned ctlr = h->ctlr;
loff_t *pos = v;
drive_info_struct *drv = h->drv[*pos];
if (*pos > h->highest_lun)
return 0;
if (drv == NULL)
return 0;
if (drv->heads == 0)
return 0;
vol_sz = drv->nr_blocks;
vol_sz_frac = sector_div(vol_sz, ENG_GIG_FACTOR);
vol_sz_frac *= 100;
sector_div(vol_sz_frac, ENG_GIG_FACTOR);
if (drv->raid_level < 0 || drv->raid_level > RAID_UNKNOWN)
drv->raid_level = RAID_UNKNOWN;
seq_printf(seq, "cciss/c%dd%d:"
"\t%4u.%02uGB\tRAID %s\n",
ctlr, (int) *pos, (int)vol_sz, (int)vol_sz_frac,
raid_label[drv->raid_level]);
return 0;
}
static void *cciss_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
ctlr_info_t *h = seq->private;
if (*pos > h->highest_lun)
return NULL;
*pos += 1;
return pos;
}
static void cciss_seq_stop(struct seq_file *seq, void *v)
{
ctlr_info_t *h = seq->private;
if (v == ERR_PTR(-EBUSY))
return;
h->busy_configuring = 0;
}
static int cciss_seq_open(struct inode *inode, struct file *file)
{
int ret = seq_open(file, &cciss_seq_ops);
struct seq_file *seq = file->private_data;
if (!ret)
seq->private = PDE_DATA(inode);
return ret;
}
static ssize_t
cciss_proc_write(struct file *file, const char __user *buf,
size_t length, loff_t *ppos)
{
int err;
char *buffer;
#ifndef CONFIG_CISS_SCSI_TAPE
return -EINVAL;
#endif
if (!buf || length > PAGE_SIZE - 1)
return -EINVAL;
buffer = memdup_user_nul(buf, length);
if (IS_ERR(buffer))
return PTR_ERR(buffer);
#ifdef CONFIG_CISS_SCSI_TAPE
if (strncmp(ENGAGE_SCSI, buffer, sizeof ENGAGE_SCSI - 1) == 0) {
struct seq_file *seq = file->private_data;
ctlr_info_t *h = seq->private;
err = cciss_engage_scsi(h);
if (err == 0)
err = length;
} else
#endif
err = -EINVAL;
kfree(buffer);
return err;
}
static void cciss_procinit(ctlr_info_t *h)
{
struct proc_dir_entry *pde;
if (proc_cciss == NULL)
proc_cciss = proc_mkdir("driver/cciss", NULL);
if (!proc_cciss)
return;
pde = proc_create_data(h->devname, S_IWUSR | S_IRUSR | S_IRGRP |
S_IROTH, proc_cciss,
&cciss_proc_fops, h);
}
static int ctlr_is_hard_resettable(u32 board_id)
{
int i;
for (i = 0; i < ARRAY_SIZE(unresettable_controller); i++)
if (unresettable_controller[i] == board_id)
return 0;
return 1;
}
static int ctlr_is_soft_resettable(u32 board_id)
{
int i;
for (i = 0; i < ARRAY_SIZE(soft_unresettable_controller); i++)
if (soft_unresettable_controller[i] == board_id)
return 0;
return 1;
}
static int ctlr_is_resettable(u32 board_id)
{
return ctlr_is_hard_resettable(board_id) ||
ctlr_is_soft_resettable(board_id);
}
static ssize_t host_show_resettable(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ctlr_info *h = to_hba(dev);
return snprintf(buf, 20, "%d\n", ctlr_is_resettable(h->board_id));
}
static ssize_t host_store_rescan(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ctlr_info *h = to_hba(dev);
add_to_scan_list(h);
wake_up_process(cciss_scan_thread);
wait_for_completion_interruptible(&h->scan_wait);
return count;
}
static ssize_t host_show_transport_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ctlr_info *h = to_hba(dev);
return snprintf(buf, 20, "%s\n",
h->transMethod & CFGTBL_Trans_Performant ?
"performant" : "simple");
}
static ssize_t dev_show_unique_id(struct device *dev,
struct device_attribute *attr,
char *buf)
{
drive_info_struct *drv = to_drv(dev);
struct ctlr_info *h = to_hba(drv->dev.parent);
__u8 sn[16];
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&h->lock, flags);
if (h->busy_configuring)
ret = -EBUSY;
else
memcpy(sn, drv->serial_no, sizeof(sn));
spin_unlock_irqrestore(&h->lock, flags);
if (ret)
return ret;
else
return snprintf(buf, 16 * 2 + 2,
"%02X%02X%02X%02X%02X%02X%02X%02X"
"%02X%02X%02X%02X%02X%02X%02X%02X\n",
sn[0], sn[1], sn[2], sn[3],
sn[4], sn[5], sn[6], sn[7],
sn[8], sn[9], sn[10], sn[11],
sn[12], sn[13], sn[14], sn[15]);
}
static ssize_t dev_show_vendor(struct device *dev,
struct device_attribute *attr,
char *buf)
{
drive_info_struct *drv = to_drv(dev);
struct ctlr_info *h = to_hba(drv->dev.parent);
char vendor[VENDOR_LEN + 1];
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&h->lock, flags);
if (h->busy_configuring)
ret = -EBUSY;
else
memcpy(vendor, drv->vendor, VENDOR_LEN + 1);
spin_unlock_irqrestore(&h->lock, flags);
if (ret)
return ret;
else
return snprintf(buf, sizeof(vendor) + 1, "%s\n", drv->vendor);
}
static ssize_t dev_show_model(struct device *dev,
struct device_attribute *attr,
char *buf)
{
drive_info_struct *drv = to_drv(dev);
struct ctlr_info *h = to_hba(drv->dev.parent);
char model[MODEL_LEN + 1];
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&h->lock, flags);
if (h->busy_configuring)
ret = -EBUSY;
else
memcpy(model, drv->model, MODEL_LEN + 1);
spin_unlock_irqrestore(&h->lock, flags);
if (ret)
return ret;
else
return snprintf(buf, sizeof(model) + 1, "%s\n", drv->model);
}
static ssize_t dev_show_rev(struct device *dev,
struct device_attribute *attr,
char *buf)
{
drive_info_struct *drv = to_drv(dev);
struct ctlr_info *h = to_hba(drv->dev.parent);
char rev[REV_LEN + 1];
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&h->lock, flags);
if (h->busy_configuring)
ret = -EBUSY;
else
memcpy(rev, drv->rev, REV_LEN + 1);
spin_unlock_irqrestore(&h->lock, flags);
if (ret)
return ret;
else
return snprintf(buf, sizeof(rev) + 1, "%s\n", drv->rev);
}
static ssize_t cciss_show_lunid(struct device *dev,
struct device_attribute *attr, char *buf)
{
drive_info_struct *drv = to_drv(dev);
struct ctlr_info *h = to_hba(drv->dev.parent);
unsigned long flags;
unsigned char lunid[8];
spin_lock_irqsave(&h->lock, flags);
if (h->busy_configuring) {
spin_unlock_irqrestore(&h->lock, flags);
return -EBUSY;
}
if (!drv->heads) {
spin_unlock_irqrestore(&h->lock, flags);
return -ENOTTY;
}
memcpy(lunid, drv->LunID, sizeof(lunid));
spin_unlock_irqrestore(&h->lock, flags);
return snprintf(buf, 20, "0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
lunid[0], lunid[1], lunid[2], lunid[3],
lunid[4], lunid[5], lunid[6], lunid[7]);
}
static ssize_t cciss_show_raid_level(struct device *dev,
struct device_attribute *attr, char *buf)
{
drive_info_struct *drv = to_drv(dev);
struct ctlr_info *h = to_hba(drv->dev.parent);
int raid;
unsigned long flags;
spin_lock_irqsave(&h->lock, flags);
if (h->busy_configuring) {
spin_unlock_irqrestore(&h->lock, flags);
return -EBUSY;
}
raid = drv->raid_level;
spin_unlock_irqrestore(&h->lock, flags);
if (raid < 0 || raid > RAID_UNKNOWN)
raid = RAID_UNKNOWN;
return snprintf(buf, strlen(raid_label[raid]) + 7, "RAID %s\n",
raid_label[raid]);
}
static ssize_t cciss_show_usage_count(struct device *dev,
struct device_attribute *attr, char *buf)
{
drive_info_struct *drv = to_drv(dev);
struct ctlr_info *h = to_hba(drv->dev.parent);
unsigned long flags;
int count;
spin_lock_irqsave(&h->lock, flags);
if (h->busy_configuring) {
spin_unlock_irqrestore(&h->lock, flags);
return -EBUSY;
}
count = drv->usage_count;
spin_unlock_irqrestore(&h->lock, flags);
return snprintf(buf, 20, "%d\n", count);
}
static void cciss_hba_release(struct device *dev)
{
}
static int cciss_create_hba_sysfs_entry(struct ctlr_info *h)
{
device_initialize(&h->dev);
h->dev.type = &cciss_host_type;
h->dev.bus = &cciss_bus_type;
dev_set_name(&h->dev, "%s", h->devname);
h->dev.parent = &h->pdev->dev;
return device_add(&h->dev);
}
static void cciss_destroy_hba_sysfs_entry(struct ctlr_info *h)
{
device_del(&h->dev);
put_device(&h->dev);
}
static void cciss_device_release(struct device *dev)
{
drive_info_struct *drv = to_drv(dev);
kfree(drv);
}
static long cciss_create_ld_sysfs_entry(struct ctlr_info *h,
int drv_index)
{
struct device *dev;
if (h->drv[drv_index]->device_initialized)
return 0;
dev = &h->drv[drv_index]->dev;
device_initialize(dev);
dev->type = &cciss_dev_type;
dev->bus = &cciss_bus_type;
dev_set_name(dev, "c%dd%d", h->ctlr, drv_index);
dev->parent = &h->dev;
h->drv[drv_index]->device_initialized = 1;
return device_add(dev);
}
static void cciss_destroy_ld_sysfs_entry(struct ctlr_info *h, int drv_index,
int ctlr_exiting)
{
struct device *dev = &h->drv[drv_index]->dev;
if (drv_index == 0 && !ctlr_exiting)
return;
device_del(dev);
put_device(dev);
h->drv[drv_index] = NULL;
}
static CommandList_struct *cmd_alloc(ctlr_info_t *h)
{
CommandList_struct *c;
int i;
u64bit temp64;
dma_addr_t cmd_dma_handle, err_dma_handle;
do {
i = find_first_zero_bit(h->cmd_pool_bits, h->nr_cmds);
if (i == h->nr_cmds)
return NULL;
} while (test_and_set_bit(i, h->cmd_pool_bits) != 0);
c = h->cmd_pool + i;
memset(c, 0, sizeof(CommandList_struct));
cmd_dma_handle = h->cmd_pool_dhandle + i * sizeof(CommandList_struct);
c->err_info = h->errinfo_pool + i;
memset(c->err_info, 0, sizeof(ErrorInfo_struct));
err_dma_handle = h->errinfo_pool_dhandle
+ i * sizeof(ErrorInfo_struct);
h->nr_allocs++;
c->cmdindex = i;
INIT_LIST_HEAD(&c->list);
c->busaddr = (__u32) cmd_dma_handle;
temp64.val = (__u64) err_dma_handle;
c->ErrDesc.Addr.lower = temp64.val32.lower;
c->ErrDesc.Addr.upper = temp64.val32.upper;
c->ErrDesc.Len = sizeof(ErrorInfo_struct);
c->ctlr = h->ctlr;
return c;
}
static CommandList_struct *cmd_special_alloc(ctlr_info_t *h)
{
CommandList_struct *c;
u64bit temp64;
dma_addr_t cmd_dma_handle, err_dma_handle;
c = pci_zalloc_consistent(h->pdev, sizeof(CommandList_struct),
&cmd_dma_handle);
if (c == NULL)
return NULL;
c->cmdindex = -1;
c->err_info = pci_zalloc_consistent(h->pdev, sizeof(ErrorInfo_struct),
&err_dma_handle);
if (c->err_info == NULL) {
pci_free_consistent(h->pdev,
sizeof(CommandList_struct), c, cmd_dma_handle);
return NULL;
}
INIT_LIST_HEAD(&c->list);
c->busaddr = (__u32) cmd_dma_handle;
temp64.val = (__u64) err_dma_handle;
c->ErrDesc.Addr.lower = temp64.val32.lower;
c->ErrDesc.Addr.upper = temp64.val32.upper;
c->ErrDesc.Len = sizeof(ErrorInfo_struct);
c->ctlr = h->ctlr;
return c;
}
static void cmd_free(ctlr_info_t *h, CommandList_struct *c)
{
int i;
i = c - h->cmd_pool;
clear_bit(i, h->cmd_pool_bits);
h->nr_frees++;
}
static void cmd_special_free(ctlr_info_t *h, CommandList_struct *c)
{
u64bit temp64;
temp64.val32.lower = c->ErrDesc.Addr.lower;
temp64.val32.upper = c->ErrDesc.Addr.upper;
pci_free_consistent(h->pdev, sizeof(ErrorInfo_struct),
c->err_info, (dma_addr_t) temp64.val);
pci_free_consistent(h->pdev, sizeof(CommandList_struct), c,
(dma_addr_t) cciss_tag_discard_error_bits(h, (u32) c->busaddr));
}
static inline ctlr_info_t *get_host(struct gendisk *disk)
{
return disk->queue->queuedata;
}
static inline drive_info_struct *get_drv(struct gendisk *disk)
{
return disk->private_data;
}
static int cciss_open(struct block_device *bdev, fmode_t mode)
{
ctlr_info_t *h = get_host(bdev->bd_disk);
drive_info_struct *drv = get_drv(bdev->bd_disk);
dev_dbg(&h->pdev->dev, "cciss_open %s\n", bdev->bd_disk->disk_name);
if (drv->busy_configuring)
return -EBUSY;
if (drv->heads == 0) {
if (MINOR(bdev->bd_dev) != 0) {
if (MINOR(bdev->bd_dev) & 0x0f) {
return -ENXIO;
} else if (memcmp(drv->LunID, CTLR_LUNID,
sizeof(drv->LunID))) {
return -ENXIO;
}
}
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
}
drv->usage_count++;
h->usage_count++;
return 0;
}
static int cciss_unlocked_open(struct block_device *bdev, fmode_t mode)
{
int ret;
mutex_lock(&cciss_mutex);
ret = cciss_open(bdev, mode);
mutex_unlock(&cciss_mutex);
return ret;
}
static void cciss_release(struct gendisk *disk, fmode_t mode)
{
ctlr_info_t *h;
drive_info_struct *drv;
mutex_lock(&cciss_mutex);
h = get_host(disk);
drv = get_drv(disk);
dev_dbg(&h->pdev->dev, "cciss_release %s\n", disk->disk_name);
drv->usage_count--;
h->usage_count--;
mutex_unlock(&cciss_mutex);
}
static int cciss_compat_ioctl(struct block_device *bdev, fmode_t mode,
unsigned cmd, unsigned long arg)
{
switch (cmd) {
case CCISS_GETPCIINFO:
case CCISS_GETINTINFO:
case CCISS_SETINTINFO:
case CCISS_GETNODENAME:
case CCISS_SETNODENAME:
case CCISS_GETHEARTBEAT:
case CCISS_GETBUSTYPES:
case CCISS_GETFIRMVER:
case CCISS_GETDRIVVER:
case CCISS_REVALIDVOLS:
case CCISS_DEREGDISK:
case CCISS_REGNEWDISK:
case CCISS_REGNEWD:
case CCISS_RESCANDISK:
case CCISS_GETLUNINFO:
return cciss_ioctl(bdev, mode, cmd, arg);
case CCISS_PASSTHRU32:
return cciss_ioctl32_passthru(bdev, mode, cmd, arg);
case CCISS_BIG_PASSTHRU32:
return cciss_ioctl32_big_passthru(bdev, mode, cmd, arg);
default:
return -ENOIOCTLCMD;
}
}
static int cciss_ioctl32_passthru(struct block_device *bdev, fmode_t mode,
unsigned cmd, unsigned long arg)
{
IOCTL32_Command_struct __user *arg32 =
(IOCTL32_Command_struct __user *) arg;
IOCTL_Command_struct arg64;
IOCTL_Command_struct __user *p = compat_alloc_user_space(sizeof(arg64));
int err;
u32 cp;
memset(&arg64, 0, sizeof(arg64));
err = 0;
err |=
copy_from_user(&arg64.LUN_info, &arg32->LUN_info,
sizeof(arg64.LUN_info));
err |=
copy_from_user(&arg64.Request, &arg32->Request,
sizeof(arg64.Request));
err |=
copy_from_user(&arg64.error_info, &arg32->error_info,
sizeof(arg64.error_info));
err |= get_user(arg64.buf_size, &arg32->buf_size);
err |= get_user(cp, &arg32->buf);
arg64.buf = compat_ptr(cp);
err |= copy_to_user(p, &arg64, sizeof(arg64));
if (err)
return -EFAULT;
err = cciss_ioctl(bdev, mode, CCISS_PASSTHRU, (unsigned long)p);
if (err)
return err;
err |=
copy_in_user(&arg32->error_info, &p->error_info,
sizeof(arg32->error_info));
if (err)
return -EFAULT;
return err;
}
static int cciss_ioctl32_big_passthru(struct block_device *bdev, fmode_t mode,
unsigned cmd, unsigned long arg)
{
BIG_IOCTL32_Command_struct __user *arg32 =
(BIG_IOCTL32_Command_struct __user *) arg;
BIG_IOCTL_Command_struct arg64;
BIG_IOCTL_Command_struct __user *p =
compat_alloc_user_space(sizeof(arg64));
int err;
u32 cp;
memset(&arg64, 0, sizeof(arg64));
err = 0;
err |=
copy_from_user(&arg64.LUN_info, &arg32->LUN_info,
sizeof(arg64.LUN_info));
err |=
copy_from_user(&arg64.Request, &arg32->Request,
sizeof(arg64.Request));
err |=
copy_from_user(&arg64.error_info, &arg32->error_info,
sizeof(arg64.error_info));
err |= get_user(arg64.buf_size, &arg32->buf_size);
err |= get_user(arg64.malloc_size, &arg32->malloc_size);
err |= get_user(cp, &arg32->buf);
arg64.buf = compat_ptr(cp);
err |= copy_to_user(p, &arg64, sizeof(arg64));
if (err)
return -EFAULT;
err = cciss_ioctl(bdev, mode, CCISS_BIG_PASSTHRU, (unsigned long)p);
if (err)
return err;
err |=
copy_in_user(&arg32->error_info, &p->error_info,
sizeof(arg32->error_info));
if (err)
return -EFAULT;
return err;
}
static int cciss_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
drive_info_struct *drv = get_drv(bdev->bd_disk);
if (!drv->cylinders)
return -ENXIO;
geo->heads = drv->heads;
geo->sectors = drv->sectors;
geo->cylinders = drv->cylinders;
return 0;
}
static void check_ioctl_unit_attention(ctlr_info_t *h, CommandList_struct *c)
{
if (c->err_info->CommandStatus == CMD_TARGET_STATUS &&
c->err_info->ScsiStatus != SAM_STAT_CHECK_CONDITION)
(void)check_for_unit_attention(h, c);
}
static int cciss_getpciinfo(ctlr_info_t *h, void __user *argp)
{
cciss_pci_info_struct pciinfo;
if (!argp)
return -EINVAL;
pciinfo.domain = pci_domain_nr(h->pdev->bus);
pciinfo.bus = h->pdev->bus->number;
pciinfo.dev_fn = h->pdev->devfn;
pciinfo.board_id = h->board_id;
if (copy_to_user(argp, &pciinfo, sizeof(cciss_pci_info_struct)))
return -EFAULT;
return 0;
}
static int cciss_getintinfo(ctlr_info_t *h, void __user *argp)
{
cciss_coalint_struct intinfo;
unsigned long flags;
if (!argp)
return -EINVAL;
spin_lock_irqsave(&h->lock, flags);
intinfo.delay = readl(&h->cfgtable->HostWrite.CoalIntDelay);
intinfo.count = readl(&h->cfgtable->HostWrite.CoalIntCount);
spin_unlock_irqrestore(&h->lock, flags);
if (copy_to_user
(argp, &intinfo, sizeof(cciss_coalint_struct)))
return -EFAULT;
return 0;
}
static int cciss_setintinfo(ctlr_info_t *h, void __user *argp)
{
cciss_coalint_struct intinfo;
unsigned long flags;
int i;
if (!argp)
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (copy_from_user(&intinfo, argp, sizeof(intinfo)))
return -EFAULT;
if ((intinfo.delay == 0) && (intinfo.count == 0))
return -EINVAL;
spin_lock_irqsave(&h->lock, flags);
writel(intinfo.delay, &(h->cfgtable->HostWrite.CoalIntDelay));
writel(intinfo.count, &(h->cfgtable->HostWrite.CoalIntCount));
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
for (i = 0; i < MAX_IOCTL_CONFIG_WAIT; i++) {
if (!(readl(h->vaddr + SA5_DOORBELL) & CFGTBL_ChangeReq))
break;
udelay(1000);
}
spin_unlock_irqrestore(&h->lock, flags);
if (i >= MAX_IOCTL_CONFIG_WAIT)
return -EAGAIN;
return 0;
}
static int cciss_getnodename(ctlr_info_t *h, void __user *argp)
{
NodeName_type NodeName;
unsigned long flags;
int i;
if (!argp)
return -EINVAL;
spin_lock_irqsave(&h->lock, flags);
for (i = 0; i < 16; i++)
NodeName[i] = readb(&h->cfgtable->ServerName[i]);
spin_unlock_irqrestore(&h->lock, flags);
if (copy_to_user(argp, NodeName, sizeof(NodeName_type)))
return -EFAULT;
return 0;
}
static int cciss_setnodename(ctlr_info_t *h, void __user *argp)
{
NodeName_type NodeName;
unsigned long flags;
int i;
if (!argp)
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (copy_from_user(NodeName, argp, sizeof(NodeName_type)))
return -EFAULT;
spin_lock_irqsave(&h->lock, flags);
for (i = 0; i < 16; i++)
writeb(NodeName[i], &h->cfgtable->ServerName[i]);
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
for (i = 0; i < MAX_IOCTL_CONFIG_WAIT; i++) {
if (!(readl(h->vaddr + SA5_DOORBELL) & CFGTBL_ChangeReq))
break;
udelay(1000);
}
spin_unlock_irqrestore(&h->lock, flags);
if (i >= MAX_IOCTL_CONFIG_WAIT)
return -EAGAIN;
return 0;
}
static int cciss_getheartbeat(ctlr_info_t *h, void __user *argp)
{
Heartbeat_type heartbeat;
unsigned long flags;
if (!argp)
return -EINVAL;
spin_lock_irqsave(&h->lock, flags);
heartbeat = readl(&h->cfgtable->HeartBeat);
spin_unlock_irqrestore(&h->lock, flags);
if (copy_to_user(argp, &heartbeat, sizeof(Heartbeat_type)))
return -EFAULT;
return 0;
}
static int cciss_getbustypes(ctlr_info_t *h, void __user *argp)
{
BusTypes_type BusTypes;
unsigned long flags;
if (!argp)
return -EINVAL;
spin_lock_irqsave(&h->lock, flags);
BusTypes = readl(&h->cfgtable->BusTypes);
spin_unlock_irqrestore(&h->lock, flags);
if (copy_to_user(argp, &BusTypes, sizeof(BusTypes_type)))
return -EFAULT;
return 0;
}
static int cciss_getfirmver(ctlr_info_t *h, void __user *argp)
{
FirmwareVer_type firmware;
if (!argp)
return -EINVAL;
memcpy(firmware, h->firm_ver, 4);
if (copy_to_user
(argp, firmware, sizeof(FirmwareVer_type)))
return -EFAULT;
return 0;
}
static int cciss_getdrivver(ctlr_info_t *h, void __user *argp)
{
DriverVer_type DriverVer = DRIVER_VERSION;
if (!argp)
return -EINVAL;
if (copy_to_user(argp, &DriverVer, sizeof(DriverVer_type)))
return -EFAULT;
return 0;
}
static int cciss_getluninfo(ctlr_info_t *h,
struct gendisk *disk, void __user *argp)
{
LogvolInfo_struct luninfo;
drive_info_struct *drv = get_drv(disk);
if (!argp)
return -EINVAL;
memcpy(&luninfo.LunID, drv->LunID, sizeof(luninfo.LunID));
luninfo.num_opens = drv->usage_count;
luninfo.num_parts = 0;
if (copy_to_user(argp, &luninfo, sizeof(LogvolInfo_struct)))
return -EFAULT;
return 0;
}
static int cciss_passthru(ctlr_info_t *h, void __user *argp)
{
IOCTL_Command_struct iocommand;
CommandList_struct *c;
char *buff = NULL;
u64bit temp64;
DECLARE_COMPLETION_ONSTACK(wait);
if (!argp)
return -EINVAL;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
if (copy_from_user
(&iocommand, argp, sizeof(IOCTL_Command_struct)))
return -EFAULT;
if ((iocommand.buf_size < 1) &&
(iocommand.Request.Type.Direction != XFER_NONE)) {
return -EINVAL;
}
if (iocommand.buf_size > 0) {
buff = kmalloc(iocommand.buf_size, GFP_KERNEL);
if (buff == NULL)
return -EFAULT;
}
if (iocommand.Request.Type.Direction == XFER_WRITE) {
if (copy_from_user(buff, iocommand.buf, iocommand.buf_size)) {
kfree(buff);
return -EFAULT;
}
} else {
memset(buff, 0, iocommand.buf_size);
}
c = cmd_special_alloc(h);
if (!c) {
kfree(buff);
return -ENOMEM;
}
c->cmd_type = CMD_IOCTL_PEND;
c->Header.ReplyQueue = 0;
if (iocommand.buf_size > 0) {
c->Header.SGList = 1;
c->Header.SGTotal = 1;
} else {
c->Header.SGList = 0;
c->Header.SGTotal = 0;
}
c->Header.LUN = iocommand.LUN_info;
c->Header.Tag.lower = c->busaddr;
c->Request = iocommand.Request;
if (iocommand.buf_size > 0) {
temp64.val = pci_map_single(h->pdev, buff,
iocommand.buf_size, PCI_DMA_BIDIRECTIONAL);
c->SG[0].Addr.lower = temp64.val32.lower;
c->SG[0].Addr.upper = temp64.val32.upper;
c->SG[0].Len = iocommand.buf_size;
c->SG[0].Ext = 0;
}
c->waiting = &wait;
enqueue_cmd_and_start_io(h, c);
wait_for_completion(&wait);
temp64.val32.lower = c->SG[0].Addr.lower;
temp64.val32.upper = c->SG[0].Addr.upper;
pci_unmap_single(h->pdev, (dma_addr_t) temp64.val, iocommand.buf_size,
PCI_DMA_BIDIRECTIONAL);
check_ioctl_unit_attention(h, c);
iocommand.error_info = *(c->err_info);
if (copy_to_user(argp, &iocommand, sizeof(IOCTL_Command_struct))) {
kfree(buff);
cmd_special_free(h, c);
return -EFAULT;
}
if (iocommand.Request.Type.Direction == XFER_READ) {
if (copy_to_user(iocommand.buf, buff, iocommand.buf_size)) {
kfree(buff);
cmd_special_free(h, c);
return -EFAULT;
}
}
kfree(buff);
cmd_special_free(h, c);
return 0;
}
static int cciss_bigpassthru(ctlr_info_t *h, void __user *argp)
{
BIG_IOCTL_Command_struct *ioc;
CommandList_struct *c;
unsigned char **buff = NULL;
int *buff_size = NULL;
u64bit temp64;
BYTE sg_used = 0;
int status = 0;
int i;
DECLARE_COMPLETION_ONSTACK(wait);
__u32 left;
__u32 sz;
BYTE __user *data_ptr;
if (!argp)
return -EINVAL;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
ioc = kmalloc(sizeof(*ioc), GFP_KERNEL);
if (!ioc) {
status = -ENOMEM;
goto cleanup1;
}
if (copy_from_user(ioc, argp, sizeof(*ioc))) {
status = -EFAULT;
goto cleanup1;
}
if ((ioc->buf_size < 1) &&
(ioc->Request.Type.Direction != XFER_NONE)) {
status = -EINVAL;
goto cleanup1;
}
if (ioc->malloc_size > MAX_KMALLOC_SIZE) {
status = -EINVAL;
goto cleanup1;
}
if (ioc->buf_size > ioc->malloc_size * MAXSGENTRIES) {
status = -EINVAL;
goto cleanup1;
}
buff = kzalloc(MAXSGENTRIES * sizeof(char *), GFP_KERNEL);
if (!buff) {
status = -ENOMEM;
goto cleanup1;
}
buff_size = kmalloc(MAXSGENTRIES * sizeof(int), GFP_KERNEL);
if (!buff_size) {
status = -ENOMEM;
goto cleanup1;
}
left = ioc->buf_size;
data_ptr = ioc->buf;
while (left) {
sz = (left > ioc->malloc_size) ? ioc->malloc_size : left;
buff_size[sg_used] = sz;
buff[sg_used] = kmalloc(sz, GFP_KERNEL);
if (buff[sg_used] == NULL) {
status = -ENOMEM;
goto cleanup1;
}
if (ioc->Request.Type.Direction == XFER_WRITE) {
if (copy_from_user(buff[sg_used], data_ptr, sz)) {
status = -EFAULT;
goto cleanup1;
}
} else {
memset(buff[sg_used], 0, sz);
}
left -= sz;
data_ptr += sz;
sg_used++;
}
c = cmd_special_alloc(h);
if (!c) {
status = -ENOMEM;
goto cleanup1;
}
c->cmd_type = CMD_IOCTL_PEND;
c->Header.ReplyQueue = 0;
c->Header.SGList = sg_used;
c->Header.SGTotal = sg_used;
c->Header.LUN = ioc->LUN_info;
c->Header.Tag.lower = c->busaddr;
c->Request = ioc->Request;
for (i = 0; i < sg_used; i++) {
temp64.val = pci_map_single(h->pdev, buff[i], buff_size[i],
PCI_DMA_BIDIRECTIONAL);
c->SG[i].Addr.lower = temp64.val32.lower;
c->SG[i].Addr.upper = temp64.val32.upper;
c->SG[i].Len = buff_size[i];
c->SG[i].Ext = 0;
}
c->waiting = &wait;
enqueue_cmd_and_start_io(h, c);
wait_for_completion(&wait);
for (i = 0; i < sg_used; i++) {
temp64.val32.lower = c->SG[i].Addr.lower;
temp64.val32.upper = c->SG[i].Addr.upper;
pci_unmap_single(h->pdev,
(dma_addr_t) temp64.val, buff_size[i],
PCI_DMA_BIDIRECTIONAL);
}
check_ioctl_unit_attention(h, c);
ioc->error_info = *(c->err_info);
if (copy_to_user(argp, ioc, sizeof(*ioc))) {
cmd_special_free(h, c);
status = -EFAULT;
goto cleanup1;
}
if (ioc->Request.Type.Direction == XFER_READ) {
BYTE __user *ptr = ioc->buf;
for (i = 0; i < sg_used; i++) {
if (copy_to_user(ptr, buff[i], buff_size[i])) {
cmd_special_free(h, c);
status = -EFAULT;
goto cleanup1;
}
ptr += buff_size[i];
}
}
cmd_special_free(h, c);
status = 0;
cleanup1:
if (buff) {
for (i = 0; i < sg_used; i++)
kfree(buff[i]);
kfree(buff);
}
kfree(buff_size);
kfree(ioc);
return status;
}
static int cciss_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
struct gendisk *disk = bdev->bd_disk;
ctlr_info_t *h = get_host(disk);
void __user *argp = (void __user *)arg;
dev_dbg(&h->pdev->dev, "cciss_ioctl: Called with cmd=%x %lx\n",
cmd, arg);
switch (cmd) {
case CCISS_GETPCIINFO:
return cciss_getpciinfo(h, argp);
case CCISS_GETINTINFO:
return cciss_getintinfo(h, argp);
case CCISS_SETINTINFO:
return cciss_setintinfo(h, argp);
case CCISS_GETNODENAME:
return cciss_getnodename(h, argp);
case CCISS_SETNODENAME:
return cciss_setnodename(h, argp);
case CCISS_GETHEARTBEAT:
return cciss_getheartbeat(h, argp);
case CCISS_GETBUSTYPES:
return cciss_getbustypes(h, argp);
case CCISS_GETFIRMVER:
return cciss_getfirmver(h, argp);
case CCISS_GETDRIVVER:
return cciss_getdrivver(h, argp);
case CCISS_DEREGDISK:
case CCISS_REGNEWD:
case CCISS_REVALIDVOLS:
return rebuild_lun_table(h, 0, 1);
case CCISS_GETLUNINFO:
return cciss_getluninfo(h, disk, argp);
case CCISS_PASSTHRU:
return cciss_passthru(h, argp);
case CCISS_BIG_PASSTHRU:
return cciss_bigpassthru(h, argp);
case SG_GET_VERSION_NUM:
case SG_SET_TIMEOUT:
case SG_GET_TIMEOUT:
case SG_GET_RESERVED_SIZE:
case SG_SET_RESERVED_SIZE:
case SG_EMULATED_HOST:
case SG_IO:
case SCSI_IOCTL_SEND_COMMAND:
return scsi_cmd_blk_ioctl(bdev, mode, cmd, argp);
case CDROM_SEND_PACKET:
case CDROMCLOSETRAY:
case CDROMEJECT:
case SCSI_IOCTL_GET_IDLUN:
case SCSI_IOCTL_GET_BUS_NUMBER:
default:
return -ENOTTY;
}
}
static void cciss_check_queues(ctlr_info_t *h)
{
int start_queue = h->next_to_run;
int i;
if ((find_first_zero_bit(h->cmd_pool_bits, h->nr_cmds)) == h->nr_cmds)
return;
for (i = 0; i < h->highest_lun + 1; i++) {
int curr_queue = (start_queue + i) % (h->highest_lun + 1);
if (!h->drv[curr_queue])
continue;
if (!(h->drv[curr_queue]->queue) ||
!(h->drv[curr_queue]->heads))
continue;
blk_start_queue(h->gendisk[curr_queue]->queue);
if ((find_first_zero_bit(h->cmd_pool_bits, h->nr_cmds)) == h->nr_cmds) {
if (curr_queue == start_queue) {
h->next_to_run =
(start_queue + 1) % (h->highest_lun + 1);
break;
} else {
h->next_to_run = curr_queue;
break;
}
}
}
}
static void cciss_softirq_done(struct request *rq)
{
CommandList_struct *c = rq->completion_data;
ctlr_info_t *h = hba[c->ctlr];
SGDescriptor_struct *curr_sg = c->SG;
u64bit temp64;
unsigned long flags;
int i, ddir;
int sg_index = 0;
if (c->Request.Type.Direction == XFER_READ)
ddir = PCI_DMA_FROMDEVICE;
else
ddir = PCI_DMA_TODEVICE;
for (i = 0; i < c->Header.SGList; i++) {
if (curr_sg[sg_index].Ext == CCISS_SG_CHAIN) {
cciss_unmap_sg_chain_block(h, c);
curr_sg = h->cmd_sg_list[c->cmdindex];
sg_index = 0;
}
temp64.val32.lower = curr_sg[sg_index].Addr.lower;
temp64.val32.upper = curr_sg[sg_index].Addr.upper;
pci_unmap_page(h->pdev, temp64.val, curr_sg[sg_index].Len,
ddir);
++sg_index;
}
dev_dbg(&h->pdev->dev, "Done with %p\n", rq);
if (blk_rq_is_passthrough(rq))
scsi_req(rq)->resid_len = c->err_info->ResidualCnt;
blk_end_request_all(rq, (rq->errors == 0) ? 0 : -EIO);
spin_lock_irqsave(&h->lock, flags);
cmd_free(h, c);
cciss_check_queues(h);
spin_unlock_irqrestore(&h->lock, flags);
}
static inline void log_unit_to_scsi3addr(ctlr_info_t *h,
unsigned char scsi3addr[], uint32_t log_unit)
{
memcpy(scsi3addr, h->drv[log_unit]->LunID,
sizeof(h->drv[log_unit]->LunID));
}
static void cciss_get_device_descr(ctlr_info_t *h, int logvol,
char *vendor, char *model, char *rev)
{
int rc;
InquiryData_struct *inq_buf;
unsigned char scsi3addr[8];
*vendor = '\0';
*model = '\0';
*rev = '\0';
inq_buf = kzalloc(sizeof(InquiryData_struct), GFP_KERNEL);
if (!inq_buf)
return;
log_unit_to_scsi3addr(h, scsi3addr, logvol);
rc = sendcmd_withirq(h, CISS_INQUIRY, inq_buf, sizeof(*inq_buf), 0,
scsi3addr, TYPE_CMD);
if (rc == IO_OK) {
memcpy(vendor, &inq_buf->data_byte[8], VENDOR_LEN);
vendor[VENDOR_LEN] = '\0';
memcpy(model, &inq_buf->data_byte[16], MODEL_LEN);
model[MODEL_LEN] = '\0';
memcpy(rev, &inq_buf->data_byte[32], REV_LEN);
rev[REV_LEN] = '\0';
}
kfree(inq_buf);
return;
}
static void cciss_get_serial_no(ctlr_info_t *h, int logvol,
unsigned char *serial_no, int buflen)
{
#define PAGE_83_INQ_BYTES 64
int rc;
unsigned char *buf;
unsigned char scsi3addr[8];
if (buflen > 16)
buflen = 16;
memset(serial_no, 0xff, buflen);
buf = kzalloc(PAGE_83_INQ_BYTES, GFP_KERNEL);
if (!buf)
return;
memset(serial_no, 0, buflen);
log_unit_to_scsi3addr(h, scsi3addr, logvol);
rc = sendcmd_withirq(h, CISS_INQUIRY, buf,
PAGE_83_INQ_BYTES, 0x83, scsi3addr, TYPE_CMD);
if (rc == IO_OK)
memcpy(serial_no, &buf[8], buflen);
kfree(buf);
return;
}
static int cciss_add_disk(ctlr_info_t *h, struct gendisk *disk,
int drv_index)
{
disk->queue = blk_alloc_queue(GFP_KERNEL);
if (!disk->queue)
goto init_queue_failure;
disk->queue->cmd_size = sizeof(struct scsi_request);
disk->queue->request_fn = do_cciss_request;
disk->queue->queue_lock = &h->lock;
if (blk_init_allocated_queue(disk->queue) < 0)
goto cleanup_queue;
sprintf(disk->disk_name, "cciss/c%dd%d", h->ctlr, drv_index);
disk->major = h->major;
disk->first_minor = drv_index << NWD_SHIFT;
disk->fops = &cciss_fops;
if (cciss_create_ld_sysfs_entry(h, drv_index))
goto cleanup_queue;
disk->private_data = h->drv[drv_index];
blk_queue_bounce_limit(disk->queue, h->pdev->dma_mask);
blk_queue_max_segments(disk->queue, h->maxsgentries);
blk_queue_max_hw_sectors(disk->queue, h->cciss_max_sectors);
blk_queue_softirq_done(disk->queue, cciss_softirq_done);
disk->queue->queuedata = h;
blk_queue_logical_block_size(disk->queue,
h->drv[drv_index]->block_size);
wmb();
h->drv[drv_index]->queue = disk->queue;
device_add_disk(&h->drv[drv_index]->dev, disk);
return 0;
cleanup_queue:
blk_cleanup_queue(disk->queue);
disk->queue = NULL;
init_queue_failure:
return -1;
}
static void cciss_update_drive_info(ctlr_info_t *h, int drv_index,
int first_time, int via_ioctl)
{
struct gendisk *disk;
InquiryData_struct *inq_buff = NULL;
unsigned int block_size;
sector_t total_size;
unsigned long flags = 0;
int ret = 0;
drive_info_struct *drvinfo;
inq_buff = kmalloc(sizeof(InquiryData_struct), GFP_KERNEL);
drvinfo = kzalloc(sizeof(*drvinfo), GFP_KERNEL);
if (inq_buff == NULL || drvinfo == NULL)
goto mem_msg;
if (h->cciss_read == CCISS_READ_16) {
cciss_read_capacity_16(h, drv_index,
&total_size, &block_size);
} else {
cciss_read_capacity(h, drv_index, &total_size, &block_size);
if (total_size == 0xFFFFFFFFULL) {
cciss_read_capacity_16(h, drv_index,
&total_size, &block_size);
h->cciss_read = CCISS_READ_16;
h->cciss_write = CCISS_WRITE_16;
} else {
h->cciss_read = CCISS_READ_10;
h->cciss_write = CCISS_WRITE_10;
}
}
cciss_geometry_inquiry(h, drv_index, total_size, block_size,
inq_buff, drvinfo);
drvinfo->block_size = block_size;
drvinfo->nr_blocks = total_size + 1;
cciss_get_device_descr(h, drv_index, drvinfo->vendor,
drvinfo->model, drvinfo->rev);
cciss_get_serial_no(h, drv_index, drvinfo->serial_no,
sizeof(drvinfo->serial_no));
memcpy(drvinfo->LunID, h->drv[drv_index]->LunID,
sizeof(drvinfo->LunID));
if (h->drv[drv_index]->raid_level != -1 &&
((memcmp(drvinfo->serial_no,
h->drv[drv_index]->serial_no, 16) == 0) &&
drvinfo->block_size == h->drv[drv_index]->block_size &&
drvinfo->nr_blocks == h->drv[drv_index]->nr_blocks &&
drvinfo->heads == h->drv[drv_index]->heads &&
drvinfo->sectors == h->drv[drv_index]->sectors &&
drvinfo->cylinders == h->drv[drv_index]->cylinders))
goto freeret;
if (h->drv[drv_index]->raid_level != -1 && drv_index != 0) {
dev_warn(&h->pdev->dev, "disk %d has changed.\n", drv_index);
spin_lock_irqsave(&h->lock, flags);
h->drv[drv_index]->busy_configuring = 1;
spin_unlock_irqrestore(&h->lock, flags);
ret = deregister_disk(h, drv_index, 0, via_ioctl);
}
if (ret)
goto freeret;
if (h->drv[drv_index] == NULL) {
drvinfo->device_initialized = 0;
h->drv[drv_index] = drvinfo;
drvinfo = NULL;
} else {
h->drv[drv_index]->block_size = drvinfo->block_size;
h->drv[drv_index]->nr_blocks = drvinfo->nr_blocks;
h->drv[drv_index]->heads = drvinfo->heads;
h->drv[drv_index]->sectors = drvinfo->sectors;
h->drv[drv_index]->cylinders = drvinfo->cylinders;
h->drv[drv_index]->raid_level = drvinfo->raid_level;
memcpy(h->drv[drv_index]->serial_no, drvinfo->serial_no, 16);
memcpy(h->drv[drv_index]->vendor, drvinfo->vendor,
VENDOR_LEN + 1);
memcpy(h->drv[drv_index]->model, drvinfo->model, MODEL_LEN + 1);
memcpy(h->drv[drv_index]->rev, drvinfo->rev, REV_LEN + 1);
}
++h->num_luns;
disk = h->gendisk[drv_index];
set_capacity(disk, h->drv[drv_index]->nr_blocks);
if (drv_index || first_time) {
if (cciss_add_disk(h, disk, drv_index) != 0) {
cciss_free_gendisk(h, drv_index);
cciss_free_drive_info(h, drv_index);
dev_warn(&h->pdev->dev, "could not update disk %d\n",
drv_index);
--h->num_luns;
}
}
freeret:
kfree(inq_buff);
kfree(drvinfo);
return;
mem_msg:
dev_err(&h->pdev->dev, "out of memory\n");
goto freeret;
}
static int cciss_alloc_drive_info(ctlr_info_t *h, int controller_node)
{
int i;
drive_info_struct *drv;
for (i = 0; i < CISS_MAX_LUN; i++) {
if (h->drv[i] && i != 0)
continue;
if (i == 0 && h->drv[i] && h->drv[i]->raid_level != -1)
continue;
if (i > h->highest_lun && !controller_node)
h->highest_lun = i;
if (i == 0 && h->drv[i] != NULL)
return i;
drv = kzalloc(sizeof(*drv), GFP_KERNEL);
if (!drv)
return -1;
drv->raid_level = -1;
h->drv[i] = drv;
return i;
}
return -1;
}
static void cciss_free_drive_info(ctlr_info_t *h, int drv_index)
{
kfree(h->drv[drv_index]);
h->drv[drv_index] = NULL;
}
static void cciss_free_gendisk(ctlr_info_t *h, int drv_index)
{
put_disk(h->gendisk[drv_index]);
h->gendisk[drv_index] = NULL;
}
static int cciss_add_gendisk(ctlr_info_t *h, unsigned char lunid[],
int controller_node)
{
int drv_index;
drv_index = cciss_alloc_drive_info(h, controller_node);
if (drv_index == -1)
return -1;
if (!h->gendisk[drv_index]) {
h->gendisk[drv_index] =
alloc_disk(1 << NWD_SHIFT);
if (!h->gendisk[drv_index]) {
dev_err(&h->pdev->dev,
"could not allocate a new disk %d\n",
drv_index);
goto err_free_drive_info;
}
}
memcpy(h->drv[drv_index]->LunID, lunid,
sizeof(h->drv[drv_index]->LunID));
if (cciss_create_ld_sysfs_entry(h, drv_index))
goto err_free_disk;
h->drv[drv_index]->busy_configuring = 0;
wmb();
return drv_index;
err_free_disk:
cciss_free_gendisk(h, drv_index);
err_free_drive_info:
cciss_free_drive_info(h, drv_index);
return -1;
}
static void cciss_add_controller_node(ctlr_info_t *h)
{
struct gendisk *disk;
int drv_index;
if (h->gendisk[0] != NULL)
return;
drv_index = cciss_add_gendisk(h, CTLR_LUNID, 1);
if (drv_index == -1)
goto error;
h->drv[drv_index]->block_size = 512;
h->drv[drv_index]->nr_blocks = 0;
h->drv[drv_index]->heads = 0;
h->drv[drv_index]->sectors = 0;
h->drv[drv_index]->cylinders = 0;
h->drv[drv_index]->raid_level = -1;
memset(h->drv[drv_index]->serial_no, 0, 16);
disk = h->gendisk[drv_index];
if (cciss_add_disk(h, disk, drv_index) == 0)
return;
cciss_free_gendisk(h, drv_index);
cciss_free_drive_info(h, drv_index);
error:
dev_warn(&h->pdev->dev, "could not add disk 0.\n");
return;
}
static int rebuild_lun_table(ctlr_info_t *h, int first_time,
int via_ioctl)
{
int num_luns;
ReportLunData_struct *ld_buff = NULL;
int return_code;
int listlength = 0;
int i;
int drv_found;
int drv_index = 0;
unsigned char lunid[8] = CTLR_LUNID;
unsigned long flags;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
spin_lock_irqsave(&h->lock, flags);
if (h->busy_configuring) {
spin_unlock_irqrestore(&h->lock, flags);
return -EBUSY;
}
h->busy_configuring = 1;
spin_unlock_irqrestore(&h->lock, flags);
ld_buff = kzalloc(sizeof(ReportLunData_struct), GFP_KERNEL);
if (ld_buff == NULL)
goto mem_msg;
return_code = sendcmd_withirq(h, CISS_REPORT_LOG, ld_buff,
sizeof(ReportLunData_struct),
0, CTLR_LUNID, TYPE_CMD);
if (return_code == IO_OK)
listlength = be32_to_cpu(*(__be32 *) ld_buff->LUNListLength);
else {
dev_warn(&h->pdev->dev,
"report logical volume command failed\n");
listlength = 0;
goto freeret;
}
num_luns = listlength / 8;
if (num_luns > CISS_MAX_LUN) {
num_luns = CISS_MAX_LUN;
dev_warn(&h->pdev->dev, "more luns configured"
" on controller than can be handled by"
" this driver.\n");
}
if (num_luns == 0)
cciss_add_controller_node(h);
for (i = 0; i <= h->highest_lun; i++) {
int j;
drv_found = 0;
if (h->drv[i] == NULL)
continue;
for (j = 0; j < num_luns; j++) {
memcpy(lunid, &ld_buff->LUN[j][0], sizeof(lunid));
if (memcmp(h->drv[i]->LunID, lunid,
sizeof(lunid)) == 0) {
drv_found = 1;
break;
}
}
if (!drv_found) {
spin_lock_irqsave(&h->lock, flags);
h->drv[i]->busy_configuring = 1;
spin_unlock_irqrestore(&h->lock, flags);
return_code = deregister_disk(h, i, 1, via_ioctl);
if (h->drv[i] != NULL)
h->drv[i]->busy_configuring = 0;
}
}
for (i = 0; i < num_luns; i++) {
int j;
drv_found = 0;
memcpy(lunid, &ld_buff->LUN[i][0], sizeof(lunid));
for (j = 0; j <= h->highest_lun; j++) {
if (h->drv[j] != NULL &&
memcmp(h->drv[j]->LunID, lunid,
sizeof(h->drv[j]->LunID)) == 0) {
drv_index = j;
drv_found = 1;
break;
}
}
if (!drv_found) {
drv_index = cciss_add_gendisk(h, lunid, 0);
if (drv_index == -1)
goto freeret;
}
cciss_update_drive_info(h, drv_index, first_time, via_ioctl);
}
freeret:
kfree(ld_buff);
h->busy_configuring = 0;
return -1;
mem_msg:
dev_err(&h->pdev->dev, "out of memory\n");
h->busy_configuring = 0;
goto freeret;
}
static void cciss_clear_drive_info(drive_info_struct *drive_info)
{
drive_info->nr_blocks = 0;
drive_info->block_size = 0;
drive_info->heads = 0;
drive_info->sectors = 0;
drive_info->cylinders = 0;
drive_info->raid_level = -1;
memset(drive_info->serial_no, 0, sizeof(drive_info->serial_no));
memset(drive_info->model, 0, sizeof(drive_info->model));
memset(drive_info->rev, 0, sizeof(drive_info->rev));
memset(drive_info->vendor, 0, sizeof(drive_info->vendor));
}
static int deregister_disk(ctlr_info_t *h, int drv_index,
int clear_all, int via_ioctl)
{
int i;
struct gendisk *disk;
drive_info_struct *drv;
int recalculate_highest_lun;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
drv = h->drv[drv_index];
disk = h->gendisk[drv_index];
if (clear_all || (h->gendisk[0] == disk)) {
if (drv->usage_count > via_ioctl)
return -EBUSY;
} else if (drv->usage_count > 0)
return -EBUSY;
recalculate_highest_lun = (drv == h->drv[h->highest_lun]);
if (h->gendisk[0] != disk) {
struct request_queue *q = disk->queue;
if (disk->flags & GENHD_FL_UP) {
cciss_destroy_ld_sysfs_entry(h, drv_index, 0);
del_gendisk(disk);
}
if (q)
blk_cleanup_queue(q);
if (clear_all){
for (i=0; i < CISS_MAX_LUN; i++){
if (h->gendisk[i] == disk) {
h->gendisk[i] = NULL;
break;
}
}
put_disk(disk);
}
} else {
set_capacity(disk, 0);
cciss_clear_drive_info(drv);
}
--h->num_luns;
if (clear_all && recalculate_highest_lun) {
int newhighest = -1;
for (i = 0; i <= h->highest_lun; i++) {
if (h->drv[i] && h->drv[i]->heads)
newhighest = i;
}
h->highest_lun = newhighest;
}
return 0;
}
static int fill_cmd(ctlr_info_t *h, CommandList_struct *c, __u8 cmd, void *buff,
size_t size, __u8 page_code, unsigned char *scsi3addr,
int cmd_type)
{
u64bit buff_dma_handle;
int status = IO_OK;
c->cmd_type = CMD_IOCTL_PEND;
c->Header.ReplyQueue = 0;
if (buff != NULL) {
c->Header.SGList = 1;
c->Header.SGTotal = 1;
} else {
c->Header.SGList = 0;
c->Header.SGTotal = 0;
}
c->Header.Tag.lower = c->busaddr;
memcpy(c->Header.LUN.LunAddrBytes, scsi3addr, 8);
c->Request.Type.Type = cmd_type;
if (cmd_type == TYPE_CMD) {
switch (cmd) {
case CISS_INQUIRY:
if (page_code != 0) {
c->Request.CDB[1] = 0x01;
c->Request.CDB[2] = page_code;
}
c->Request.CDBLen = 6;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_READ;
c->Request.Timeout = 0;
c->Request.CDB[0] = CISS_INQUIRY;
c->Request.CDB[4] = size & 0xFF;
break;
case CISS_REPORT_LOG:
case CISS_REPORT_PHYS:
c->Request.CDBLen = 12;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_READ;
c->Request.Timeout = 0;
c->Request.CDB[0] = cmd;
c->Request.CDB[6] = (size >> 24) & 0xFF;
c->Request.CDB[7] = (size >> 16) & 0xFF;
c->Request.CDB[8] = (size >> 8) & 0xFF;
c->Request.CDB[9] = size & 0xFF;
break;
case CCISS_READ_CAPACITY:
c->Request.CDBLen = 10;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_READ;
c->Request.Timeout = 0;
c->Request.CDB[0] = cmd;
break;
case CCISS_READ_CAPACITY_16:
c->Request.CDBLen = 16;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_READ;
c->Request.Timeout = 0;
c->Request.CDB[0] = cmd;
c->Request.CDB[1] = 0x10;
c->Request.CDB[10] = (size >> 24) & 0xFF;
c->Request.CDB[11] = (size >> 16) & 0xFF;
c->Request.CDB[12] = (size >> 8) & 0xFF;
c->Request.CDB[13] = size & 0xFF;
c->Request.Timeout = 0;
c->Request.CDB[0] = cmd;
break;
case CCISS_CACHE_FLUSH:
c->Request.CDBLen = 12;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_WRITE;
c->Request.Timeout = 0;
c->Request.CDB[0] = BMIC_WRITE;
c->Request.CDB[6] = BMIC_CACHE_FLUSH;
c->Request.CDB[7] = (size >> 8) & 0xFF;
c->Request.CDB[8] = size & 0xFF;
break;
case TEST_UNIT_READY:
c->Request.CDBLen = 6;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_NONE;
c->Request.Timeout = 0;
break;
default:
dev_warn(&h->pdev->dev, "Unknown Command 0x%c\n", cmd);
return IO_ERROR;
}
} else if (cmd_type == TYPE_MSG) {
switch (cmd) {
case CCISS_ABORT_MSG:
c->Request.CDBLen = 12;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_WRITE;
c->Request.Timeout = 0;
c->Request.CDB[0] = cmd;
c->Request.CDB[1] = 0;
memcpy(&c->Request.CDB[4], buff, 8);
break;
case CCISS_RESET_MSG:
c->Request.CDBLen = 16;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_NONE;
c->Request.Timeout = 0;
memset(&c->Request.CDB[0], 0, sizeof(c->Request.CDB));
c->Request.CDB[0] = cmd;
c->Request.CDB[1] = CCISS_RESET_TYPE_TARGET;
break;
case CCISS_NOOP_MSG:
c->Request.CDBLen = 1;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_WRITE;
c->Request.Timeout = 0;
c->Request.CDB[0] = cmd;
break;
default:
dev_warn(&h->pdev->dev,
"unknown message type %d\n", cmd);
return IO_ERROR;
}
} else {
dev_warn(&h->pdev->dev, "unknown command type %d\n", cmd_type);
return IO_ERROR;
}
if (size > 0) {
buff_dma_handle.val = (__u64) pci_map_single(h->pdev,
buff, size,
PCI_DMA_BIDIRECTIONAL);
c->SG[0].Addr.lower = buff_dma_handle.val32.lower;
c->SG[0].Addr.upper = buff_dma_handle.val32.upper;
c->SG[0].Len = size;
c->SG[0].Ext = 0;
}
return status;
}
static int cciss_send_reset(ctlr_info_t *h, unsigned char *scsi3addr,
u8 reset_type)
{
CommandList_struct *c;
int return_status;
c = cmd_alloc(h);
if (!c)
return -ENOMEM;
return_status = fill_cmd(h, c, CCISS_RESET_MSG, NULL, 0, 0,
CTLR_LUNID, TYPE_MSG);
c->Request.CDB[1] = reset_type;
if (return_status != IO_OK) {
cmd_special_free(h, c);
return return_status;
}
c->waiting = NULL;
enqueue_cmd_and_start_io(h, c);
return 0;
}
static int check_target_status(ctlr_info_t *h, CommandList_struct *c)
{
switch (c->err_info->ScsiStatus) {
case SAM_STAT_GOOD:
return IO_OK;
case SAM_STAT_CHECK_CONDITION:
switch (0xf & c->err_info->SenseInfo[2]) {
case 0: return IO_OK;
case 1: return IO_OK;
default:
if (check_for_unit_attention(h, c))
return IO_NEEDS_RETRY;
dev_warn(&h->pdev->dev, "cmd 0x%02x "
"check condition, sense key = 0x%02x\n",
c->Request.CDB[0], c->err_info->SenseInfo[2]);
}
break;
default:
dev_warn(&h->pdev->dev, "cmd 0x%02x"
"scsi status = 0x%02x\n",
c->Request.CDB[0], c->err_info->ScsiStatus);
break;
}
return IO_ERROR;
}
static int process_sendcmd_error(ctlr_info_t *h, CommandList_struct *c)
{
int return_status = IO_OK;
if (c->err_info->CommandStatus == CMD_SUCCESS)
return IO_OK;
switch (c->err_info->CommandStatus) {
case CMD_TARGET_STATUS:
return_status = check_target_status(h, c);
break;
case CMD_DATA_UNDERRUN:
case CMD_DATA_OVERRUN:
break;
case CMD_INVALID:
dev_warn(&h->pdev->dev, "cmd 0x%02x is "
"reported invalid\n", c->Request.CDB[0]);
return_status = IO_ERROR;
break;
case CMD_PROTOCOL_ERR:
dev_warn(&h->pdev->dev, "cmd 0x%02x has "
"protocol error\n", c->Request.CDB[0]);
return_status = IO_ERROR;
break;
case CMD_HARDWARE_ERR:
dev_warn(&h->pdev->dev, "cmd 0x%02x had "
" hardware error\n", c->Request.CDB[0]);
return_status = IO_ERROR;
break;
case CMD_CONNECTION_LOST:
dev_warn(&h->pdev->dev, "cmd 0x%02x had "
"connection lost\n", c->Request.CDB[0]);
return_status = IO_ERROR;
break;
case CMD_ABORTED:
dev_warn(&h->pdev->dev, "cmd 0x%02x was "
"aborted\n", c->Request.CDB[0]);
return_status = IO_ERROR;
break;
case CMD_ABORT_FAILED:
dev_warn(&h->pdev->dev, "cmd 0x%02x reports "
"abort failed\n", c->Request.CDB[0]);
return_status = IO_ERROR;
break;
case CMD_UNSOLICITED_ABORT:
dev_warn(&h->pdev->dev, "unsolicited abort 0x%02x\n",
c->Request.CDB[0]);
return_status = IO_NEEDS_RETRY;
break;
case CMD_UNABORTABLE:
dev_warn(&h->pdev->dev, "cmd unabortable\n");
return_status = IO_ERROR;
break;
default:
dev_warn(&h->pdev->dev, "cmd 0x%02x returned "
"unknown status %x\n", c->Request.CDB[0],
c->err_info->CommandStatus);
return_status = IO_ERROR;
}
return return_status;
}
static int sendcmd_withirq_core(ctlr_info_t *h, CommandList_struct *c,
int attempt_retry)
{
DECLARE_COMPLETION_ONSTACK(wait);
u64bit buff_dma_handle;
int return_status = IO_OK;
resend_cmd2:
c->waiting = &wait;
enqueue_cmd_and_start_io(h, c);
wait_for_completion(&wait);
if (c->err_info->CommandStatus == 0 || !attempt_retry)
goto command_done;
return_status = process_sendcmd_error(h, c);
if (return_status == IO_NEEDS_RETRY &&
c->retry_count < MAX_CMD_RETRIES) {
dev_warn(&h->pdev->dev, "retrying 0x%02x\n",
c->Request.CDB[0]);
c->retry_count++;
memset(c->err_info, 0, sizeof(ErrorInfo_struct));
return_status = IO_OK;
reinit_completion(&wait);
goto resend_cmd2;
}
command_done:
buff_dma_handle.val32.lower = c->SG[0].Addr.lower;
buff_dma_handle.val32.upper = c->SG[0].Addr.upper;
pci_unmap_single(h->pdev, (dma_addr_t) buff_dma_handle.val,
c->SG[0].Len, PCI_DMA_BIDIRECTIONAL);
return return_status;
}
static int sendcmd_withirq(ctlr_info_t *h, __u8 cmd, void *buff, size_t size,
__u8 page_code, unsigned char scsi3addr[],
int cmd_type)
{
CommandList_struct *c;
int return_status;
c = cmd_special_alloc(h);
if (!c)
return -ENOMEM;
return_status = fill_cmd(h, c, cmd, buff, size, page_code,
scsi3addr, cmd_type);
if (return_status == IO_OK)
return_status = sendcmd_withirq_core(h, c, 1);
cmd_special_free(h, c);
return return_status;
}
static void cciss_geometry_inquiry(ctlr_info_t *h, int logvol,
sector_t total_size,
unsigned int block_size,
InquiryData_struct *inq_buff,
drive_info_struct *drv)
{
int return_code;
unsigned long t;
unsigned char scsi3addr[8];
memset(inq_buff, 0, sizeof(InquiryData_struct));
log_unit_to_scsi3addr(h, scsi3addr, logvol);
return_code = sendcmd_withirq(h, CISS_INQUIRY, inq_buff,
sizeof(*inq_buff), 0xC1, scsi3addr, TYPE_CMD);
if (return_code == IO_OK) {
if (inq_buff->data_byte[8] == 0xFF) {
dev_warn(&h->pdev->dev,
"reading geometry failed, volume "
"does not support reading geometry\n");
drv->heads = 255;
drv->sectors = 32;
drv->cylinders = total_size + 1;
drv->raid_level = RAID_UNKNOWN;
} else {
drv->heads = inq_buff->data_byte[6];
drv->sectors = inq_buff->data_byte[7];
drv->cylinders = (inq_buff->data_byte[4] & 0xff) << 8;
drv->cylinders += inq_buff->data_byte[5];
drv->raid_level = inq_buff->data_byte[8];
}
drv->block_size = block_size;
drv->nr_blocks = total_size + 1;
t = drv->heads * drv->sectors;
if (t > 1) {
sector_t real_size = total_size + 1;
unsigned long rem = sector_div(real_size, t);
if (rem)
real_size++;
drv->cylinders = real_size;
}
} else {
dev_warn(&h->pdev->dev, "reading geometry failed\n");
}
}
static void
cciss_read_capacity(ctlr_info_t *h, int logvol, sector_t *total_size,
unsigned int *block_size)
{
ReadCapdata_struct *buf;
int return_code;
unsigned char scsi3addr[8];
buf = kzalloc(sizeof(ReadCapdata_struct), GFP_KERNEL);
if (!buf) {
dev_warn(&h->pdev->dev, "out of memory\n");
return;
}
log_unit_to_scsi3addr(h, scsi3addr, logvol);
return_code = sendcmd_withirq(h, CCISS_READ_CAPACITY, buf,
sizeof(ReadCapdata_struct), 0, scsi3addr, TYPE_CMD);
if (return_code == IO_OK) {
*total_size = be32_to_cpu(*(__be32 *) buf->total_size);
*block_size = be32_to_cpu(*(__be32 *) buf->block_size);
} else {
dev_warn(&h->pdev->dev, "read capacity failed\n");
*total_size = 0;
*block_size = BLOCK_SIZE;
}
kfree(buf);
}
static void cciss_read_capacity_16(ctlr_info_t *h, int logvol,
sector_t *total_size, unsigned int *block_size)
{
ReadCapdata_struct_16 *buf;
int return_code;
unsigned char scsi3addr[8];
buf = kzalloc(sizeof(ReadCapdata_struct_16), GFP_KERNEL);
if (!buf) {
dev_warn(&h->pdev->dev, "out of memory\n");
return;
}
log_unit_to_scsi3addr(h, scsi3addr, logvol);
return_code = sendcmd_withirq(h, CCISS_READ_CAPACITY_16,
buf, sizeof(ReadCapdata_struct_16),
0, scsi3addr, TYPE_CMD);
if (return_code == IO_OK) {
*total_size = be64_to_cpu(*(__be64 *) buf->total_size);
*block_size = be32_to_cpu(*(__be32 *) buf->block_size);
} else {
dev_warn(&h->pdev->dev, "read capacity failed\n");
*total_size = 0;
*block_size = BLOCK_SIZE;
}
dev_info(&h->pdev->dev, " blocks= %llu block_size= %d\n",
(unsigned long long)*total_size+1, *block_size);
kfree(buf);
}
static int cciss_revalidate(struct gendisk *disk)
{
ctlr_info_t *h = get_host(disk);
drive_info_struct *drv = get_drv(disk);
int logvol;
int FOUND = 0;
unsigned int block_size;
sector_t total_size;
InquiryData_struct *inq_buff = NULL;
for (logvol = 0; logvol <= h->highest_lun; logvol++) {
if (!h->drv[logvol])
continue;
if (memcmp(h->drv[logvol]->LunID, drv->LunID,
sizeof(drv->LunID)) == 0) {
FOUND = 1;
break;
}
}
if (!FOUND)
return 1;
inq_buff = kmalloc(sizeof(InquiryData_struct), GFP_KERNEL);
if (inq_buff == NULL) {
dev_warn(&h->pdev->dev, "out of memory\n");
return 1;
}
if (h->cciss_read == CCISS_READ_10) {
cciss_read_capacity(h, logvol,
&total_size, &block_size);
} else {
cciss_read_capacity_16(h, logvol,
&total_size, &block_size);
}
cciss_geometry_inquiry(h, logvol, total_size, block_size,
inq_buff, drv);
blk_queue_logical_block_size(drv->queue, drv->block_size);
set_capacity(disk, drv->nr_blocks);
kfree(inq_buff);
return 0;
}
static void __iomem *remap_pci_mem(ulong base, ulong size)
{
ulong page_base = ((ulong) base) & PAGE_MASK;
ulong page_offs = ((ulong) base) - page_base;
void __iomem *page_remapped = ioremap(page_base, page_offs + size);
return page_remapped ? (page_remapped + page_offs) : NULL;
}
static void start_io(ctlr_info_t *h)
{
CommandList_struct *c;
while (!list_empty(&h->reqQ)) {
c = list_entry(h->reqQ.next, CommandList_struct, list);
if ((h->access.fifo_full(h))) {
dev_warn(&h->pdev->dev, "fifo full\n");
break;
}
removeQ(c);
h->Qdepth--;
h->access.submit_command(h, c);
addQ(&h->cmpQ, c);
}
}
static inline void resend_cciss_cmd(ctlr_info_t *h, CommandList_struct *c)
{
memset(c->err_info, 0, sizeof(ErrorInfo_struct));
addQ(&h->reqQ, c);
h->Qdepth++;
if (h->Qdepth > h->maxQsinceinit)
h->maxQsinceinit = h->Qdepth;
start_io(h);
}
static inline unsigned int make_status_bytes(unsigned int scsi_status_byte,
unsigned int msg_byte, unsigned int host_byte,
unsigned int driver_byte)
{
return (scsi_status_byte & 0xff) |
((msg_byte & 0xff) << 8) |
((host_byte & 0xff) << 16) |
((driver_byte & 0xff) << 24);
}
static inline int evaluate_target_status(ctlr_info_t *h,
CommandList_struct *cmd, int *retry_cmd)
{
unsigned char sense_key;
unsigned char status_byte, msg_byte, host_byte, driver_byte;
int error_value;
*retry_cmd = 0;
status_byte = cmd->err_info->ScsiStatus;
driver_byte = DRIVER_OK;
msg_byte = cmd->err_info->CommandStatus;
if (blk_rq_is_passthrough(cmd->rq))
host_byte = DID_PASSTHROUGH;
else
host_byte = DID_OK;
error_value = make_status_bytes(status_byte, msg_byte,
host_byte, driver_byte);
if (cmd->err_info->ScsiStatus != SAM_STAT_CHECK_CONDITION) {
if (!blk_rq_is_passthrough(cmd->rq))
dev_warn(&h->pdev->dev, "cmd %p "
"has SCSI Status 0x%x\n",
cmd, cmd->err_info->ScsiStatus);
return error_value;
}
sense_key = 0xf & cmd->err_info->SenseInfo[2];
if (((sense_key == 0x0) || (sense_key == 0x1)) &&
!blk_rq_is_passthrough(cmd->rq))
error_value = 0;
if (check_for_unit_attention(h, cmd)) {
*retry_cmd = !blk_rq_is_passthrough(cmd->rq);
return 0;
}
if (!blk_rq_is_passthrough(cmd->rq)) {
if (error_value != 0)
dev_warn(&h->pdev->dev, "cmd %p has CHECK CONDITION"
" sense key = 0x%x\n", cmd, sense_key);
return error_value;
}
scsi_req(cmd->rq)->sense_len = cmd->err_info->SenseLen;
return error_value;
}
static inline void complete_command(ctlr_info_t *h, CommandList_struct *cmd,
int timeout)
{
int retry_cmd = 0;
struct request *rq = cmd->rq;
rq->errors = 0;
if (timeout)
rq->errors = make_status_bytes(0, 0, 0, DRIVER_TIMEOUT);
if (cmd->err_info->CommandStatus == 0)
goto after_error_processing;
switch (cmd->err_info->CommandStatus) {
case CMD_TARGET_STATUS:
rq->errors = evaluate_target_status(h, cmd, &retry_cmd);
break;
case CMD_DATA_UNDERRUN:
if (!blk_rq_is_passthrough(cmd->rq)) {
dev_warn(&h->pdev->dev, "cmd %p has"
" completed with data underrun "
"reported\n", cmd);
}
break;
case CMD_DATA_OVERRUN:
if (!blk_rq_is_passthrough(cmd->rq))
dev_warn(&h->pdev->dev, "cciss: cmd %p has"
" completed with data overrun "
"reported\n", cmd);
break;
case CMD_INVALID:
dev_warn(&h->pdev->dev, "cciss: cmd %p is "
"reported invalid\n", cmd);
rq->errors = make_status_bytes(SAM_STAT_GOOD,
cmd->err_info->CommandStatus, DRIVER_OK,
blk_rq_is_passthrough(cmd->rq) ?
DID_PASSTHROUGH : DID_ERROR);
break;
case CMD_PROTOCOL_ERR:
dev_warn(&h->pdev->dev, "cciss: cmd %p has "
"protocol error\n", cmd);
rq->errors = make_status_bytes(SAM_STAT_GOOD,
cmd->err_info->CommandStatus, DRIVER_OK,
blk_rq_is_passthrough(cmd->rq) ?
DID_PASSTHROUGH : DID_ERROR);
break;
case CMD_HARDWARE_ERR:
dev_warn(&h->pdev->dev, "cciss: cmd %p had "
" hardware error\n", cmd);
rq->errors = make_status_bytes(SAM_STAT_GOOD,
cmd->err_info->CommandStatus, DRIVER_OK,
blk_rq_is_passthrough(cmd->rq) ?
DID_PASSTHROUGH : DID_ERROR);
break;
case CMD_CONNECTION_LOST:
dev_warn(&h->pdev->dev, "cciss: cmd %p had "
"connection lost\n", cmd);
rq->errors = make_status_bytes(SAM_STAT_GOOD,
cmd->err_info->CommandStatus, DRIVER_OK,
blk_rq_is_passthrough(cmd->rq) ?
DID_PASSTHROUGH : DID_ERROR);
break;
case CMD_ABORTED:
dev_warn(&h->pdev->dev, "cciss: cmd %p was "
"aborted\n", cmd);
rq->errors = make_status_bytes(SAM_STAT_GOOD,
cmd->err_info->CommandStatus, DRIVER_OK,
blk_rq_is_passthrough(cmd->rq) ?
DID_PASSTHROUGH : DID_ABORT);
break;
case CMD_ABORT_FAILED:
dev_warn(&h->pdev->dev, "cciss: cmd %p reports "
"abort failed\n", cmd);
rq->errors = make_status_bytes(SAM_STAT_GOOD,
cmd->err_info->CommandStatus, DRIVER_OK,
blk_rq_is_passthrough(cmd->rq) ?
DID_PASSTHROUGH : DID_ERROR);
break;
case CMD_UNSOLICITED_ABORT:
dev_warn(&h->pdev->dev, "cciss%d: unsolicited "
"abort %p\n", h->ctlr, cmd);
if (cmd->retry_count < MAX_CMD_RETRIES) {
retry_cmd = 1;
dev_warn(&h->pdev->dev, "retrying %p\n", cmd);
cmd->retry_count++;
} else
dev_warn(&h->pdev->dev,
"%p retried too many times\n", cmd);
rq->errors = make_status_bytes(SAM_STAT_GOOD,
cmd->err_info->CommandStatus, DRIVER_OK,
blk_rq_is_passthrough(cmd->rq) ?
DID_PASSTHROUGH : DID_ABORT);
break;
case CMD_TIMEOUT:
dev_warn(&h->pdev->dev, "cmd %p timedout\n", cmd);
rq->errors = make_status_bytes(SAM_STAT_GOOD,
cmd->err_info->CommandStatus, DRIVER_OK,
blk_rq_is_passthrough(cmd->rq) ?
DID_PASSTHROUGH : DID_ERROR);
break;
case CMD_UNABORTABLE:
dev_warn(&h->pdev->dev, "cmd %p unabortable\n", cmd);
rq->errors = make_status_bytes(SAM_STAT_GOOD,
cmd->err_info->CommandStatus, DRIVER_OK,
blk_rq_is_passthrough(cmd->rq) ?
DID_PASSTHROUGH : DID_ERROR);
break;
default:
dev_warn(&h->pdev->dev, "cmd %p returned "
"unknown status %x\n", cmd,
cmd->err_info->CommandStatus);
rq->errors = make_status_bytes(SAM_STAT_GOOD,
cmd->err_info->CommandStatus, DRIVER_OK,
blk_rq_is_passthrough(cmd->rq) ?
DID_PASSTHROUGH : DID_ERROR);
}
after_error_processing:
if (retry_cmd) {
resend_cciss_cmd(h, cmd);
return;
}
cmd->rq->completion_data = cmd;
blk_complete_request(cmd->rq);
}
static inline u32 cciss_tag_contains_index(u32 tag)
{
#define DIRECT_LOOKUP_BIT 0x10
return tag & DIRECT_LOOKUP_BIT;
}
static inline u32 cciss_tag_to_index(u32 tag)
{
#define DIRECT_LOOKUP_SHIFT 5
return tag >> DIRECT_LOOKUP_SHIFT;
}
static inline u32 cciss_tag_discard_error_bits(ctlr_info_t *h, u32 tag)
{
#define CCISS_PERF_ERROR_BITS ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define CCISS_SIMPLE_ERROR_BITS 0x03
if (likely(h->transMethod & CFGTBL_Trans_Performant))
return tag & ~CCISS_PERF_ERROR_BITS;
return tag & ~CCISS_SIMPLE_ERROR_BITS;
}
static inline void cciss_mark_tag_indexed(u32 *tag)
{
*tag |= DIRECT_LOOKUP_BIT;
}
static inline void cciss_set_tag_index(u32 *tag, u32 index)
{
*tag |= (index << DIRECT_LOOKUP_SHIFT);
}
static void do_cciss_request(struct request_queue *q)
{
ctlr_info_t *h = q->queuedata;
CommandList_struct *c;
sector_t start_blk;
int seg;
struct request *creq;
u64bit temp64;
struct scatterlist *tmp_sg;
SGDescriptor_struct *curr_sg;
drive_info_struct *drv;
int i, dir;
int sg_index = 0;
int chained = 0;
queue:
creq = blk_peek_request(q);
if (!creq)
goto startio;
BUG_ON(creq->nr_phys_segments > h->maxsgentries);
c = cmd_alloc(h);
if (!c)
goto full;
blk_start_request(creq);
tmp_sg = h->scatter_list[c->cmdindex];
spin_unlock_irq(q->queue_lock);
c->cmd_type = CMD_RWREQ;
c->rq = creq;
drv = creq->rq_disk->private_data;
c->Header.ReplyQueue = 0;
cciss_set_tag_index(&c->Header.Tag.lower, c->cmdindex);
cciss_mark_tag_indexed(&c->Header.Tag.lower);
memcpy(&c->Header.LUN, drv->LunID, sizeof(drv->LunID));
c->Request.CDBLen = 10;
c->Request.Type.Type = TYPE_CMD;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction =
(rq_data_dir(creq) == READ) ? XFER_READ : XFER_WRITE;
c->Request.Timeout = 0;
c->Request.CDB[0] =
(rq_data_dir(creq) == READ) ? h->cciss_read : h->cciss_write;
start_blk = blk_rq_pos(creq);
dev_dbg(&h->pdev->dev, "sector =%d nr_sectors=%d\n",
(int)blk_rq_pos(creq), (int)blk_rq_sectors(creq));
sg_init_table(tmp_sg, h->maxsgentries);
seg = blk_rq_map_sg(q, creq, tmp_sg);
if (c->Request.Type.Direction == XFER_READ)
dir = PCI_DMA_FROMDEVICE;
else
dir = PCI_DMA_TODEVICE;
curr_sg = c->SG;
sg_index = 0;
chained = 0;
for (i = 0; i < seg; i++) {
if (((sg_index+1) == (h->max_cmd_sgentries)) &&
!chained && ((seg - i) > 1)) {
curr_sg = h->cmd_sg_list[c->cmdindex];
sg_index = 0;
chained = 1;
}
curr_sg[sg_index].Len = tmp_sg[i].length;
temp64.val = (__u64) pci_map_page(h->pdev, sg_page(&tmp_sg[i]),
tmp_sg[i].offset,
tmp_sg[i].length, dir);
if (dma_mapping_error(&h->pdev->dev, temp64.val)) {
dev_warn(&h->pdev->dev,
"%s: error mapping page for DMA\n", __func__);
creq->errors = make_status_bytes(SAM_STAT_GOOD,
0, DRIVER_OK,
DID_SOFT_ERROR);
cmd_free(h, c);
return;
}
curr_sg[sg_index].Addr.lower = temp64.val32.lower;
curr_sg[sg_index].Addr.upper = temp64.val32.upper;
curr_sg[sg_index].Ext = 0;
++sg_index;
}
if (chained) {
if (cciss_map_sg_chain_block(h, c, h->cmd_sg_list[c->cmdindex],
(seg - (h->max_cmd_sgentries - 1)) *
sizeof(SGDescriptor_struct))) {
creq->errors = make_status_bytes(SAM_STAT_GOOD,
0, DRIVER_OK,
DID_SOFT_ERROR);
cmd_free(h, c);
return;
}
}
if (seg > h->maxSG)
h->maxSG = seg;
dev_dbg(&h->pdev->dev, "Submitting %u sectors in %d segments "
"chained[%d]\n",
blk_rq_sectors(creq), seg, chained);
c->Header.SGTotal = seg + chained;
if (seg <= h->max_cmd_sgentries)
c->Header.SGList = c->Header.SGTotal;
else
c->Header.SGList = h->max_cmd_sgentries;
set_performant_mode(h, c);
switch (req_op(creq)) {
case REQ_OP_READ:
case REQ_OP_WRITE:
if(h->cciss_read == CCISS_READ_10) {
c->Request.CDB[1] = 0;
c->Request.CDB[2] = (start_blk >> 24) & 0xff;
c->Request.CDB[3] = (start_blk >> 16) & 0xff;
c->Request.CDB[4] = (start_blk >> 8) & 0xff;
c->Request.CDB[5] = start_blk & 0xff;
c->Request.CDB[6] = 0;
c->Request.CDB[7] = (blk_rq_sectors(creq) >> 8) & 0xff;
c->Request.CDB[8] = blk_rq_sectors(creq) & 0xff;
c->Request.CDB[9] = c->Request.CDB[11] = c->Request.CDB[12] = 0;
} else {
u32 upper32 = upper_32_bits(start_blk);
c->Request.CDBLen = 16;
c->Request.CDB[1]= 0;
c->Request.CDB[2]= (upper32 >> 24) & 0xff;
c->Request.CDB[3]= (upper32 >> 16) & 0xff;
c->Request.CDB[4]= (upper32 >> 8) & 0xff;
c->Request.CDB[5]= upper32 & 0xff;
c->Request.CDB[6]= (start_blk >> 24) & 0xff;
c->Request.CDB[7]= (start_blk >> 16) & 0xff;
c->Request.CDB[8]= (start_blk >> 8) & 0xff;
c->Request.CDB[9]= start_blk & 0xff;
c->Request.CDB[10]= (blk_rq_sectors(creq) >> 24) & 0xff;
c->Request.CDB[11]= (blk_rq_sectors(creq) >> 16) & 0xff;
c->Request.CDB[12]= (blk_rq_sectors(creq) >> 8) & 0xff;
c->Request.CDB[13]= blk_rq_sectors(creq) & 0xff;
c->Request.CDB[14] = c->Request.CDB[15] = 0;
}
break;
case REQ_OP_SCSI_IN:
case REQ_OP_SCSI_OUT:
c->Request.CDBLen = scsi_req(creq)->cmd_len;
memcpy(c->Request.CDB, scsi_req(creq)->cmd, BLK_MAX_CDB);
scsi_req(creq)->sense = c->err_info->SenseInfo;
break;
default:
dev_warn(&h->pdev->dev, "bad request type %d\n",
creq->cmd_flags);
BUG();
}
spin_lock_irq(q->queue_lock);
addQ(&h->reqQ, c);
h->Qdepth++;
if (h->Qdepth > h->maxQsinceinit)
h->maxQsinceinit = h->Qdepth;
goto queue;
full:
blk_stop_queue(q);
startio:
start_io(h);
}
static inline unsigned long get_next_completion(ctlr_info_t *h)
{
return h->access.command_completed(h);
}
static inline int interrupt_pending(ctlr_info_t *h)
{
return h->access.intr_pending(h);
}
static inline long interrupt_not_for_us(ctlr_info_t *h)
{
return ((h->access.intr_pending(h) == 0) ||
(h->interrupts_enabled == 0));
}
static inline int bad_tag(ctlr_info_t *h, u32 tag_index,
u32 raw_tag)
{
if (unlikely(tag_index >= h->nr_cmds)) {
dev_warn(&h->pdev->dev, "bad tag 0x%08x ignored.\n", raw_tag);
return 1;
}
return 0;
}
static inline void finish_cmd(ctlr_info_t *h, CommandList_struct *c,
u32 raw_tag)
{
removeQ(c);
if (likely(c->cmd_type == CMD_RWREQ))
complete_command(h, c, 0);
else if (c->cmd_type == CMD_IOCTL_PEND)
complete(c->waiting);
#ifdef CONFIG_CISS_SCSI_TAPE
else if (c->cmd_type == CMD_SCSI)
complete_scsi_command(c, 0, raw_tag);
#endif
}
static inline u32 next_command(ctlr_info_t *h)
{
u32 a;
if (unlikely(!(h->transMethod & CFGTBL_Trans_Performant)))
return h->access.command_completed(h);
if ((*(h->reply_pool_head) & 1) == (h->reply_pool_wraparound)) {
a = *(h->reply_pool_head);
(h->reply_pool_head)++;
h->commands_outstanding--;
} else {
a = FIFO_EMPTY;
}
if (h->reply_pool_head == (h->reply_pool + h->max_commands)) {
h->reply_pool_head = h->reply_pool;
h->reply_pool_wraparound ^= 1;
}
return a;
}
static inline u32 process_indexed_cmd(ctlr_info_t *h, u32 raw_tag)
{
u32 tag_index;
CommandList_struct *c;
tag_index = cciss_tag_to_index(raw_tag);
if (bad_tag(h, tag_index, raw_tag))
return next_command(h);
c = h->cmd_pool + tag_index;
finish_cmd(h, c, raw_tag);
return next_command(h);
}
static inline u32 process_nonindexed_cmd(ctlr_info_t *h, u32 raw_tag)
{
CommandList_struct *c = NULL;
__u32 busaddr_masked, tag_masked;
tag_masked = cciss_tag_discard_error_bits(h, raw_tag);
list_for_each_entry(c, &h->cmpQ, list) {
busaddr_masked = cciss_tag_discard_error_bits(h, c->busaddr);
if (busaddr_masked == tag_masked) {
finish_cmd(h, c, raw_tag);
return next_command(h);
}
}
bad_tag(h, h->nr_cmds + 1, raw_tag);
return next_command(h);
}
static int ignore_bogus_interrupt(ctlr_info_t *h)
{
if (likely(!reset_devices))
return 0;
if (likely(h->interrupts_enabled))
return 0;
dev_info(&h->pdev->dev, "Received interrupt while interrupts disabled "
"(known firmware bug.) Ignoring.\n");
return 1;
}
static irqreturn_t cciss_intx_discard_completions(int irq, void *dev_id)
{
ctlr_info_t *h = dev_id;
unsigned long flags;
u32 raw_tag;
if (ignore_bogus_interrupt(h))
return IRQ_NONE;
if (interrupt_not_for_us(h))
return IRQ_NONE;
spin_lock_irqsave(&h->lock, flags);
while (interrupt_pending(h)) {
raw_tag = get_next_completion(h);
while (raw_tag != FIFO_EMPTY)
raw_tag = next_command(h);
}
spin_unlock_irqrestore(&h->lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t cciss_msix_discard_completions(int irq, void *dev_id)
{
ctlr_info_t *h = dev_id;
unsigned long flags;
u32 raw_tag;
if (ignore_bogus_interrupt(h))
return IRQ_NONE;
spin_lock_irqsave(&h->lock, flags);
raw_tag = get_next_completion(h);
while (raw_tag != FIFO_EMPTY)
raw_tag = next_command(h);
spin_unlock_irqrestore(&h->lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t do_cciss_intx(int irq, void *dev_id)
{
ctlr_info_t *h = dev_id;
unsigned long flags;
u32 raw_tag;
if (interrupt_not_for_us(h))
return IRQ_NONE;
spin_lock_irqsave(&h->lock, flags);
while (interrupt_pending(h)) {
raw_tag = get_next_completion(h);
while (raw_tag != FIFO_EMPTY) {
if (cciss_tag_contains_index(raw_tag))
raw_tag = process_indexed_cmd(h, raw_tag);
else
raw_tag = process_nonindexed_cmd(h, raw_tag);
}
}
spin_unlock_irqrestore(&h->lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t do_cciss_msix_intr(int irq, void *dev_id)
{
ctlr_info_t *h = dev_id;
unsigned long flags;
u32 raw_tag;
spin_lock_irqsave(&h->lock, flags);
raw_tag = get_next_completion(h);
while (raw_tag != FIFO_EMPTY) {
if (cciss_tag_contains_index(raw_tag))
raw_tag = process_indexed_cmd(h, raw_tag);
else
raw_tag = process_nonindexed_cmd(h, raw_tag);
}
spin_unlock_irqrestore(&h->lock, flags);
return IRQ_HANDLED;
}
static int add_to_scan_list(struct ctlr_info *h)
{
struct ctlr_info *test_h;
int found = 0;
int ret = 0;
if (h->busy_initializing)
return 0;
if (!mutex_trylock(&h->busy_shutting_down))
return 0;
mutex_lock(&scan_mutex);
list_for_each_entry(test_h, &scan_q, scan_list) {
if (test_h == h) {
found = 1;
break;
}
}
if (!found && !h->busy_scanning) {
reinit_completion(&h->scan_wait);
list_add_tail(&h->scan_list, &scan_q);
ret = 1;
}
mutex_unlock(&scan_mutex);
mutex_unlock(&h->busy_shutting_down);
return ret;
}
static void remove_from_scan_list(struct ctlr_info *h)
{
struct ctlr_info *test_h, *tmp_h;
mutex_lock(&scan_mutex);
list_for_each_entry_safe(test_h, tmp_h, &scan_q, scan_list) {
if (test_h == h) {
list_del(&h->scan_list);
complete_all(&h->scan_wait);
mutex_unlock(&scan_mutex);
return;
}
}
if (h->busy_scanning) {
mutex_unlock(&scan_mutex);
wait_for_completion(&h->scan_wait);
} else {
mutex_unlock(&scan_mutex);
}
}
static int scan_thread(void *data)
{
struct ctlr_info *h;
while (1) {
set_current_state(TASK_INTERRUPTIBLE);
schedule();
if (kthread_should_stop())
break;
while (1) {
mutex_lock(&scan_mutex);
if (list_empty(&scan_q)) {
mutex_unlock(&scan_mutex);
break;
}
h = list_entry(scan_q.next,
struct ctlr_info,
scan_list);
list_del(&h->scan_list);
h->busy_scanning = 1;
mutex_unlock(&scan_mutex);
rebuild_lun_table(h, 0, 0);
complete_all(&h->scan_wait);
mutex_lock(&scan_mutex);
h->busy_scanning = 0;
mutex_unlock(&scan_mutex);
}
}
return 0;
}
static int check_for_unit_attention(ctlr_info_t *h, CommandList_struct *c)
{
if (c->err_info->SenseInfo[2] != UNIT_ATTENTION)
return 0;
switch (c->err_info->SenseInfo[12]) {
case STATE_CHANGED:
dev_warn(&h->pdev->dev, "a state change "
"detected, command retried\n");
return 1;
break;
case LUN_FAILED:
dev_warn(&h->pdev->dev, "LUN failure "
"detected, action required\n");
return 1;
break;
case REPORT_LUNS_CHANGED:
dev_warn(&h->pdev->dev, "report LUN data changed\n");
return 1;
break;
case POWER_OR_RESET:
dev_warn(&h->pdev->dev,
"a power on or device reset detected\n");
return 1;
break;
case UNIT_ATTENTION_CLEARED:
dev_warn(&h->pdev->dev,
"unit attention cleared by another initiator\n");
return 1;
break;
default:
dev_warn(&h->pdev->dev, "unknown unit attention detected\n");
return 1;
}
}
static void print_cfg_table(ctlr_info_t *h)
{
int i;
char temp_name[17];
CfgTable_struct *tb = h->cfgtable;
dev_dbg(&h->pdev->dev, "Controller Configuration information\n");
dev_dbg(&h->pdev->dev, "------------------------------------\n");
for (i = 0; i < 4; i++)
temp_name[i] = readb(&(tb->Signature[i]));
temp_name[4] = '\0';
dev_dbg(&h->pdev->dev, " Signature = %s\n", temp_name);
dev_dbg(&h->pdev->dev, " Spec Number = %d\n",
readl(&(tb->SpecValence)));
dev_dbg(&h->pdev->dev, " Transport methods supported = 0x%x\n",
readl(&(tb->TransportSupport)));
dev_dbg(&h->pdev->dev, " Transport methods active = 0x%x\n",
readl(&(tb->TransportActive)));
dev_dbg(&h->pdev->dev, " Requested transport Method = 0x%x\n",
readl(&(tb->HostWrite.TransportRequest)));
dev_dbg(&h->pdev->dev, " Coalesce Interrupt Delay = 0x%x\n",
readl(&(tb->HostWrite.CoalIntDelay)));
dev_dbg(&h->pdev->dev, " Coalesce Interrupt Count = 0x%x\n",
readl(&(tb->HostWrite.CoalIntCount)));
dev_dbg(&h->pdev->dev, " Max outstanding commands = 0x%x\n",
readl(&(tb->CmdsOutMax)));
dev_dbg(&h->pdev->dev, " Bus Types = 0x%x\n",
readl(&(tb->BusTypes)));
for (i = 0; i < 16; i++)
temp_name[i] = readb(&(tb->ServerName[i]));
temp_name[16] = '\0';
dev_dbg(&h->pdev->dev, " Server Name = %s\n", temp_name);
dev_dbg(&h->pdev->dev, " Heartbeat Counter = 0x%x\n\n\n",
readl(&(tb->HeartBeat)));
}
static int find_PCI_BAR_index(struct pci_dev *pdev, unsigned long pci_bar_addr)
{
int i, offset, mem_type, bar_type;
if (pci_bar_addr == PCI_BASE_ADDRESS_0)
return 0;
offset = 0;
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
bar_type = pci_resource_flags(pdev, i) & PCI_BASE_ADDRESS_SPACE;
if (bar_type == PCI_BASE_ADDRESS_SPACE_IO)
offset += 4;
else {
mem_type = pci_resource_flags(pdev, i) &
PCI_BASE_ADDRESS_MEM_TYPE_MASK;
switch (mem_type) {
case PCI_BASE_ADDRESS_MEM_TYPE_32:
case PCI_BASE_ADDRESS_MEM_TYPE_1M:
offset += 4;
break;
case PCI_BASE_ADDRESS_MEM_TYPE_64:
offset += 8;
break;
default:
dev_warn(&pdev->dev,
"Base address is invalid\n");
return -1;
break;
}
}
if (offset == pci_bar_addr - PCI_BASE_ADDRESS_0)
return i + 1;
}
return -1;
}
static void calc_bucket_map(int bucket[], int num_buckets,
int nsgs, int *bucket_map)
{
int i, j, b, size;
#define MINIMUM_TRANSFER_BLOCKS 4
#define NUM_BUCKETS 8
for (i = 0; i <= nsgs; i++) {
size = i + MINIMUM_TRANSFER_BLOCKS;
b = num_buckets;
for (j = 0; j < 8; j++) {
if (bucket[j] >= size) {
b = j;
break;
}
}
bucket_map[i] = b;
}
}
static void cciss_wait_for_mode_change_ack(ctlr_info_t *h)
{
int i;
for (i = 0; i < MAX_CONFIG_WAIT; i++) {
if (!(readl(h->vaddr + SA5_DOORBELL) & CFGTBL_ChangeReq))
break;
usleep_range(10000, 20000);
}
}
static void cciss_enter_performant_mode(ctlr_info_t *h, u32 use_short_tags)
{
__u32 trans_offset;
int bft[8] = { 5, 6, 8, 10, 12, 20, 28, MAXSGENTRIES + 4};
unsigned long register_value;
BUILD_BUG_ON(28 > MAXSGENTRIES + 4);
h->reply_pool_wraparound = 1;
memset(h->reply_pool, 0, h->max_commands * sizeof(__u64));
h->reply_pool_head = h->reply_pool;
trans_offset = readl(&(h->cfgtable->TransMethodOffset));
calc_bucket_map(bft, ARRAY_SIZE(bft), h->maxsgentries,
h->blockFetchTable);
writel(bft[0], &h->transtable->BlockFetch0);
writel(bft[1], &h->transtable->BlockFetch1);
writel(bft[2], &h->transtable->BlockFetch2);
writel(bft[3], &h->transtable->BlockFetch3);
writel(bft[4], &h->transtable->BlockFetch4);
writel(bft[5], &h->transtable->BlockFetch5);
writel(bft[6], &h->transtable->BlockFetch6);
writel(bft[7], &h->transtable->BlockFetch7);
writel(h->max_commands, &h->transtable->RepQSize);
writel(1, &h->transtable->RepQCount);
writel(0, &h->transtable->RepQCtrAddrLow32);
writel(0, &h->transtable->RepQCtrAddrHigh32);
writel(h->reply_pool_dhandle, &h->transtable->RepQAddr0Low32);
writel(0, &h->transtable->RepQAddr0High32);
writel(CFGTBL_Trans_Performant | use_short_tags,
&(h->cfgtable->HostWrite.TransportRequest));
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
cciss_wait_for_mode_change_ack(h);
register_value = readl(&(h->cfgtable->TransportActive));
if (!(register_value & CFGTBL_Trans_Performant))
dev_warn(&h->pdev->dev, "cciss: unable to get board into"
" performant mode\n");
}
static void cciss_put_controller_into_performant_mode(ctlr_info_t *h)
{
__u32 trans_support;
if (cciss_simple_mode)
return;
dev_dbg(&h->pdev->dev, "Trying to put board into Performant mode\n");
trans_support = readl(&(h->cfgtable->TransportSupport));
if (!(trans_support & PERFORMANT_MODE))
return;
dev_dbg(&h->pdev->dev, "Placing controller into performant mode\n");
if ((sizeof(CommandList_struct) % 32) != 0) {
dev_warn(&h->pdev->dev, "%s %d %s\n",
"cciss info: command size[",
(int)sizeof(CommandList_struct),
"] not divisible by 32, no performant mode..\n");
return;
}
h->reply_pool = (__u64 *)pci_alloc_consistent(
h->pdev, h->max_commands * sizeof(__u64),
&(h->reply_pool_dhandle));
h->blockFetchTable = kmalloc(((h->maxsgentries+1) *
sizeof(__u32)), GFP_KERNEL);
if ((h->reply_pool == NULL) || (h->blockFetchTable == NULL))
goto clean_up;
cciss_enter_performant_mode(h,
trans_support & CFGTBL_Trans_use_short_tags);
h->access = SA5_performant_access;
h->transMethod = CFGTBL_Trans_Performant;
return;
clean_up:
kfree(h->blockFetchTable);
if (h->reply_pool)
pci_free_consistent(h->pdev,
h->max_commands * sizeof(__u64),
h->reply_pool,
h->reply_pool_dhandle);
return;
}
static void cciss_interrupt_mode(ctlr_info_t *h)
{
int ret;
if ((h->board_id == 0x40700E11) || (h->board_id == 0x40800E11) ||
(h->board_id == 0x40820E11) || (h->board_id == 0x40830E11))
goto default_int_mode;
ret = pci_alloc_irq_vectors(h->pdev, 4, 4, PCI_IRQ_MSIX);
if (ret >= 0) {
h->intr[0] = pci_irq_vector(h->pdev, 0);
h->intr[1] = pci_irq_vector(h->pdev, 1);
h->intr[2] = pci_irq_vector(h->pdev, 2);
h->intr[3] = pci_irq_vector(h->pdev, 3);
return;
}
ret = pci_alloc_irq_vectors(h->pdev, 1, 1, PCI_IRQ_MSI);
default_int_mode:
h->intr[h->intr_mode] = pci_irq_vector(h->pdev, 0);
return;
}
static int cciss_lookup_board_id(struct pci_dev *pdev, u32 *board_id)
{
int i;
u32 subsystem_vendor_id, subsystem_device_id;
subsystem_vendor_id = pdev->subsystem_vendor;
subsystem_device_id = pdev->subsystem_device;
*board_id = ((subsystem_device_id << 16) & 0xffff0000) |
subsystem_vendor_id;
for (i = 0; i < ARRAY_SIZE(products); i++) {
if (cciss_allow_hpsa)
return -ENODEV;
if (*board_id == products[i].board_id)
return i;
}
dev_warn(&pdev->dev, "unrecognized board ID: 0x%08x, ignoring.\n",
*board_id);
return -ENODEV;
}
static inline bool cciss_board_disabled(ctlr_info_t *h)
{
u16 command;
(void) pci_read_config_word(h->pdev, PCI_COMMAND, &command);
return ((command & PCI_COMMAND_MEMORY) == 0);
}
static int cciss_pci_find_memory_BAR(struct pci_dev *pdev,
unsigned long *memory_bar)
{
int i;
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++)
if (pci_resource_flags(pdev, i) & IORESOURCE_MEM) {
*memory_bar = pci_resource_start(pdev, i);
dev_dbg(&pdev->dev, "memory BAR = %lx\n",
*memory_bar);
return 0;
}
dev_warn(&pdev->dev, "no memory BAR found\n");
return -ENODEV;
}
static int cciss_wait_for_board_state(struct pci_dev *pdev,
void __iomem *vaddr, int wait_for_ready)
#define BOARD_READY 1
#define BOARD_NOT_READY 0
{
int i, iterations;
u32 scratchpad;
if (wait_for_ready)
iterations = CCISS_BOARD_READY_ITERATIONS;
else
iterations = CCISS_BOARD_NOT_READY_ITERATIONS;
for (i = 0; i < iterations; i++) {
scratchpad = readl(vaddr + SA5_SCRATCHPAD_OFFSET);
if (wait_for_ready) {
if (scratchpad == CCISS_FIRMWARE_READY)
return 0;
} else {
if (scratchpad != CCISS_FIRMWARE_READY)
return 0;
}
msleep(CCISS_BOARD_READY_POLL_INTERVAL_MSECS);
}
dev_warn(&pdev->dev, "board not ready, timed out.\n");
return -ENODEV;
}
static int cciss_find_cfg_addrs(struct pci_dev *pdev, void __iomem *vaddr,
u32 *cfg_base_addr, u64 *cfg_base_addr_index,
u64 *cfg_offset)
{
*cfg_base_addr = readl(vaddr + SA5_CTCFG_OFFSET);
*cfg_offset = readl(vaddr + SA5_CTMEM_OFFSET);
*cfg_base_addr &= (u32) 0x0000ffff;
*cfg_base_addr_index = find_PCI_BAR_index(pdev, *cfg_base_addr);
if (*cfg_base_addr_index == -1) {
dev_warn(&pdev->dev, "cannot find cfg_base_addr_index, "
"*cfg_base_addr = 0x%08x\n", *cfg_base_addr);
return -ENODEV;
}
return 0;
}
static int cciss_find_cfgtables(ctlr_info_t *h)
{
u64 cfg_offset;
u32 cfg_base_addr;
u64 cfg_base_addr_index;
u32 trans_offset;
int rc;
rc = cciss_find_cfg_addrs(h->pdev, h->vaddr, &cfg_base_addr,
&cfg_base_addr_index, &cfg_offset);
if (rc)
return rc;
h->cfgtable = remap_pci_mem(pci_resource_start(h->pdev,
cfg_base_addr_index) + cfg_offset, sizeof(*h->cfgtable));
if (!h->cfgtable)
return -ENOMEM;
rc = write_driver_ver_to_cfgtable(h->cfgtable);
if (rc)
return rc;
trans_offset = readl(&h->cfgtable->TransMethodOffset);
h->transtable = remap_pci_mem(pci_resource_start(h->pdev,
cfg_base_addr_index)+cfg_offset+trans_offset,
sizeof(*h->transtable));
if (!h->transtable)
return -ENOMEM;
return 0;
}
static void cciss_get_max_perf_mode_cmds(struct ctlr_info *h)
{
h->max_commands = readl(&(h->cfgtable->MaxPerformantModeCommands));
if (reset_devices && h->max_commands > 32)
h->max_commands = 32;
if (h->max_commands < 16) {
dev_warn(&h->pdev->dev, "Controller reports "
"max supported commands of %d, an obvious lie. "
"Using 16. Ensure that firmware is up to date.\n",
h->max_commands);
h->max_commands = 16;
}
}
static void cciss_find_board_params(ctlr_info_t *h)
{
cciss_get_max_perf_mode_cmds(h);
h->nr_cmds = h->max_commands - 4 - cciss_tape_cmds;
h->maxsgentries = readl(&(h->cfgtable->MaxSGElements));
if (h->board_id == 0x3225103C)
h->maxsgentries = MAXSGENTRIES;
h->max_cmd_sgentries = 31;
if (h->maxsgentries > 512) {
h->max_cmd_sgentries = 32;
h->chainsize = h->maxsgentries - h->max_cmd_sgentries + 1;
h->maxsgentries--;
} else {
h->maxsgentries = 31;
h->chainsize = 0;
}
}
static inline bool CISS_signature_present(ctlr_info_t *h)
{
if (!check_signature(h->cfgtable->Signature, "CISS", 4)) {
dev_warn(&h->pdev->dev, "not a valid CISS config table\n");
return false;
}
return true;
}
static inline void cciss_enable_scsi_prefetch(ctlr_info_t *h)
{
#ifdef CONFIG_X86
u32 prefetch;
prefetch = readl(&(h->cfgtable->SCSI_Prefetch));
prefetch |= 0x100;
writel(prefetch, &(h->cfgtable->SCSI_Prefetch));
#endif
}
static inline void cciss_p600_dma_prefetch_quirk(ctlr_info_t *h)
{
u32 dma_prefetch;
__u32 dma_refetch;
if (h->board_id != 0x3225103C)
return;
dma_prefetch = readl(h->vaddr + I2O_DMA1_CFG);
dma_prefetch |= 0x8000;
writel(dma_prefetch, h->vaddr + I2O_DMA1_CFG);
pci_read_config_dword(h->pdev, PCI_COMMAND_PARITY, &dma_refetch);
dma_refetch |= 0x1;
pci_write_config_dword(h->pdev, PCI_COMMAND_PARITY, dma_refetch);
}
static int cciss_pci_init(ctlr_info_t *h)
{
int prod_index, err;
prod_index = cciss_lookup_board_id(h->pdev, &h->board_id);
if (prod_index < 0)
return -ENODEV;
h->product_name = products[prod_index].product_name;
h->access = *(products[prod_index].access);
if (cciss_board_disabled(h)) {
dev_warn(&h->pdev->dev, "controller appears to be disabled\n");
return -ENODEV;
}
pci_disable_link_state(h->pdev, PCIE_LINK_STATE_L0S |
PCIE_LINK_STATE_L1 | PCIE_LINK_STATE_CLKPM);
err = pci_enable_device(h->pdev);
if (err) {
dev_warn(&h->pdev->dev, "Unable to Enable PCI device\n");
return err;
}
err = pci_request_regions(h->pdev, "cciss");
if (err) {
dev_warn(&h->pdev->dev,
"Cannot obtain PCI resources, aborting\n");
return err;
}
dev_dbg(&h->pdev->dev, "irq = %x\n", h->pdev->irq);
dev_dbg(&h->pdev->dev, "board_id = %x\n", h->board_id);
cciss_interrupt_mode(h);
err = cciss_pci_find_memory_BAR(h->pdev, &h->paddr);
if (err)
goto err_out_free_res;
h->vaddr = remap_pci_mem(h->paddr, 0x250);
if (!h->vaddr) {
err = -ENOMEM;
goto err_out_free_res;
}
err = cciss_wait_for_board_state(h->pdev, h->vaddr, BOARD_READY);
if (err)
goto err_out_free_res;
err = cciss_find_cfgtables(h);
if (err)
goto err_out_free_res;
print_cfg_table(h);
cciss_find_board_params(h);
if (!CISS_signature_present(h)) {
err = -ENODEV;
goto err_out_free_res;
}
cciss_enable_scsi_prefetch(h);
cciss_p600_dma_prefetch_quirk(h);
err = cciss_enter_simple_mode(h);
if (err)
goto err_out_free_res;
cciss_put_controller_into_performant_mode(h);
return 0;
err_out_free_res:
if (h->transtable)
iounmap(h->transtable);
if (h->cfgtable)
iounmap(h->cfgtable);
if (h->vaddr)
iounmap(h->vaddr);
pci_release_regions(h->pdev);
return err;
}
static int alloc_cciss_hba(struct pci_dev *pdev)
{
int i;
for (i = 0; i < MAX_CTLR; i++) {
if (!hba[i]) {
ctlr_info_t *h;
h = kzalloc(sizeof(ctlr_info_t), GFP_KERNEL);
if (!h)
goto Enomem;
hba[i] = h;
return i;
}
}
dev_warn(&pdev->dev, "This driver supports a maximum"
" of %d controllers.\n", MAX_CTLR);
return -1;
Enomem:
dev_warn(&pdev->dev, "out of memory.\n");
return -1;
}
static void free_hba(ctlr_info_t *h)
{
int i;
hba[h->ctlr] = NULL;
for (i = 0; i < h->highest_lun + 1; i++)
if (h->gendisk[i] != NULL)
put_disk(h->gendisk[i]);
kfree(h);
}
static int cciss_message(struct pci_dev *pdev, unsigned char opcode,
unsigned char type)
{
typedef struct {
CommandListHeader_struct CommandHeader;
RequestBlock_struct Request;
ErrDescriptor_struct ErrorDescriptor;
} Command;
static const size_t cmd_sz = sizeof(Command) + sizeof(ErrorInfo_struct);
Command *cmd;
dma_addr_t paddr64;
uint32_t paddr32, tag;
void __iomem *vaddr;
int i, err;
vaddr = ioremap_nocache(pci_resource_start(pdev, 0), pci_resource_len(pdev, 0));
if (vaddr == NULL)
return -ENOMEM;
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
iounmap(vaddr);
return -ENOMEM;
}
cmd = pci_alloc_consistent(pdev, cmd_sz, &paddr64);
if (cmd == NULL) {
iounmap(vaddr);
return -ENOMEM;
}
paddr32 = paddr64;
cmd->CommandHeader.ReplyQueue = 0;
cmd->CommandHeader.SGList = 0;
cmd->CommandHeader.SGTotal = 0;
cmd->CommandHeader.Tag.lower = paddr32;
cmd->CommandHeader.Tag.upper = 0;
memset(&cmd->CommandHeader.LUN.LunAddrBytes, 0, 8);
cmd->Request.CDBLen = 16;
cmd->Request.Type.Type = TYPE_MSG;
cmd->Request.Type.Attribute = ATTR_HEADOFQUEUE;
cmd->Request.Type.Direction = XFER_NONE;
cmd->Request.Timeout = 0;
cmd->Request.CDB[0] = opcode;
cmd->Request.CDB[1] = type;
memset(&cmd->Request.CDB[2], 0, 14);
cmd->ErrorDescriptor.Addr.lower = paddr32 + sizeof(Command);
cmd->ErrorDescriptor.Addr.upper = 0;
cmd->ErrorDescriptor.Len = sizeof(ErrorInfo_struct);
writel(paddr32, vaddr + SA5_REQUEST_PORT_OFFSET);
for (i = 0; i < 10; i++) {
tag = readl(vaddr + SA5_REPLY_PORT_OFFSET);
if ((tag & ~3) == paddr32)
break;
msleep(CCISS_POST_RESET_NOOP_TIMEOUT_MSECS);
}
iounmap(vaddr);
if (i == 10) {
dev_err(&pdev->dev,
"controller message %02x:%02x timed out\n",
opcode, type);
return -ETIMEDOUT;
}
pci_free_consistent(pdev, cmd_sz, cmd, paddr64);
if (tag & 2) {
dev_err(&pdev->dev, "controller message %02x:%02x failed\n",
opcode, type);
return -EIO;
}
dev_info(&pdev->dev, "controller message %02x:%02x succeeded\n",
opcode, type);
return 0;
}
static int cciss_controller_hard_reset(struct pci_dev *pdev,
void * __iomem vaddr, u32 use_doorbell)
{
u16 pmcsr;
int pos;
if (use_doorbell) {
dev_info(&pdev->dev, "using doorbell to reset controller\n");
writel(use_doorbell, vaddr + SA5_DOORBELL);
} else {
pos = pci_find_capability(pdev, PCI_CAP_ID_PM);
if (pos == 0) {
dev_err(&pdev->dev,
"cciss_controller_hard_reset: "
"PCI PM not supported\n");
return -ENODEV;
}
dev_info(&pdev->dev, "using PCI PM to reset controller\n");
pci_read_config_word(pdev, pos + PCI_PM_CTRL, &pmcsr);
pmcsr &= ~PCI_PM_CTRL_STATE_MASK;
pmcsr |= PCI_D3hot;
pci_write_config_word(pdev, pos + PCI_PM_CTRL, pmcsr);
msleep(500);
pmcsr &= ~PCI_PM_CTRL_STATE_MASK;
pmcsr |= PCI_D0;
pci_write_config_word(pdev, pos + PCI_PM_CTRL, pmcsr);
msleep(500);
}
return 0;
}
static void init_driver_version(char *driver_version, int len)
{
memset(driver_version, 0, len);
strncpy(driver_version, "cciss " DRIVER_NAME, len - 1);
}
static int write_driver_ver_to_cfgtable(CfgTable_struct __iomem *cfgtable)
{
char *driver_version;
int i, size = sizeof(cfgtable->driver_version);
driver_version = kmalloc(size, GFP_KERNEL);
if (!driver_version)
return -ENOMEM;
init_driver_version(driver_version, size);
for (i = 0; i < size; i++)
writeb(driver_version[i], &cfgtable->driver_version[i]);
kfree(driver_version);
return 0;
}
static void read_driver_ver_from_cfgtable(CfgTable_struct __iomem *cfgtable,
unsigned char *driver_ver)
{
int i;
for (i = 0; i < sizeof(cfgtable->driver_version); i++)
driver_ver[i] = readb(&cfgtable->driver_version[i]);
}
static int controller_reset_failed(CfgTable_struct __iomem *cfgtable)
{
char *driver_ver, *old_driver_ver;
int rc, size = sizeof(cfgtable->driver_version);
old_driver_ver = kmalloc(2 * size, GFP_KERNEL);
if (!old_driver_ver)
return -ENOMEM;
driver_ver = old_driver_ver + size;
init_driver_version(old_driver_ver, size);
read_driver_ver_from_cfgtable(cfgtable, driver_ver);
rc = !memcmp(driver_ver, old_driver_ver, size);
kfree(old_driver_ver);
return rc;
}
static int cciss_kdump_hard_reset_controller(struct pci_dev *pdev)
{
u64 cfg_offset;
u32 cfg_base_addr;
u64 cfg_base_addr_index;
void __iomem *vaddr;
unsigned long paddr;
u32 misc_fw_support;
int rc;
CfgTable_struct __iomem *cfgtable;
u32 use_doorbell;
u32 board_id;
u16 command_register;
cciss_lookup_board_id(pdev, &board_id);
if (!ctlr_is_resettable(board_id)) {
dev_warn(&pdev->dev, "Controller not resettable\n");
return -ENODEV;
}
if (!ctlr_is_hard_resettable(board_id))
return -ENOTSUPP;
pci_read_config_word(pdev, 4, &command_register);
pci_disable_device(pdev);
pci_save_state(pdev);
rc = cciss_pci_find_memory_BAR(pdev, &paddr);
if (rc)
return rc;
vaddr = remap_pci_mem(paddr, 0x250);
if (!vaddr)
return -ENOMEM;
rc = cciss_find_cfg_addrs(pdev, vaddr, &cfg_base_addr,
&cfg_base_addr_index, &cfg_offset);
if (rc)
goto unmap_vaddr;
cfgtable = remap_pci_mem(pci_resource_start(pdev,
cfg_base_addr_index) + cfg_offset, sizeof(*cfgtable));
if (!cfgtable) {
rc = -ENOMEM;
goto unmap_vaddr;
}
rc = write_driver_ver_to_cfgtable(cfgtable);
if (rc)
goto unmap_vaddr;
misc_fw_support = readl(&cfgtable->misc_fw_support);
use_doorbell = misc_fw_support & MISC_FW_DOORBELL_RESET2;
if (use_doorbell) {
use_doorbell = DOORBELL_CTLR_RESET2;
} else {
use_doorbell = misc_fw_support & MISC_FW_DOORBELL_RESET;
if (use_doorbell) {
dev_warn(&pdev->dev, "Controller claims that "
"'Bit 2 doorbell reset' is "
"supported, but not 'bit 5 doorbell reset'. "
"Firmware update is recommended.\n");
rc = -ENOTSUPP;
goto unmap_cfgtable;
}
}
rc = cciss_controller_hard_reset(pdev, vaddr, use_doorbell);
if (rc)
goto unmap_cfgtable;
pci_restore_state(pdev);
rc = pci_enable_device(pdev);
if (rc) {
dev_warn(&pdev->dev, "failed to enable device.\n");
goto unmap_cfgtable;
}
pci_write_config_word(pdev, 4, command_register);
msleep(CCISS_POST_RESET_PAUSE_MSECS);
dev_info(&pdev->dev, "Waiting for board to reset.\n");
rc = cciss_wait_for_board_state(pdev, vaddr, BOARD_NOT_READY);
if (rc) {
dev_warn(&pdev->dev, "Failed waiting for board to hard reset."
" Will try soft reset.\n");
rc = -ENOTSUPP;
goto unmap_cfgtable;
}
rc = cciss_wait_for_board_state(pdev, vaddr, BOARD_READY);
if (rc) {
dev_warn(&pdev->dev,
"failed waiting for board to become ready "
"after hard reset\n");
goto unmap_cfgtable;
}
rc = controller_reset_failed(vaddr);
if (rc < 0)
goto unmap_cfgtable;
if (rc) {
dev_warn(&pdev->dev, "Unable to successfully hard reset "
"controller. Will try soft reset.\n");
rc = -ENOTSUPP;
} else {
dev_info(&pdev->dev, "Board ready after hard reset.\n");
}
unmap_cfgtable:
iounmap(cfgtable);
unmap_vaddr:
iounmap(vaddr);
return rc;
}
static int cciss_init_reset_devices(struct pci_dev *pdev)
{
int rc, i;
if (!reset_devices)
return 0;
rc = cciss_kdump_hard_reset_controller(pdev);
if (rc == -ENOTSUPP)
return rc;
if (rc)
return -ENODEV;
dev_warn(&pdev->dev, "Waiting for controller to respond to no-op\n");
for (i = 0; i < CCISS_POST_RESET_NOOP_RETRIES; i++) {
if (cciss_noop(pdev) == 0)
break;
else
dev_warn(&pdev->dev, "no-op failed%s\n",
(i < CCISS_POST_RESET_NOOP_RETRIES - 1 ?
"; re-trying" : ""));
msleep(CCISS_POST_RESET_NOOP_INTERVAL_MSECS);
}
return 0;
}
static int cciss_allocate_cmd_pool(ctlr_info_t *h)
{
h->cmd_pool_bits = kmalloc(BITS_TO_LONGS(h->nr_cmds) *
sizeof(unsigned long), GFP_KERNEL);
h->cmd_pool = pci_alloc_consistent(h->pdev,
h->nr_cmds * sizeof(CommandList_struct),
&(h->cmd_pool_dhandle));
h->errinfo_pool = pci_alloc_consistent(h->pdev,
h->nr_cmds * sizeof(ErrorInfo_struct),
&(h->errinfo_pool_dhandle));
if ((h->cmd_pool_bits == NULL)
|| (h->cmd_pool == NULL)
|| (h->errinfo_pool == NULL)) {
dev_err(&h->pdev->dev, "out of memory");
return -ENOMEM;
}
return 0;
}
static int cciss_allocate_scatterlists(ctlr_info_t *h)
{
int i;
h->scatter_list = kzalloc(h->max_commands *
sizeof(struct scatterlist *), GFP_KERNEL);
if (!h->scatter_list)
return -ENOMEM;
for (i = 0; i < h->nr_cmds; i++) {
h->scatter_list[i] = kmalloc(sizeof(struct scatterlist) *
h->maxsgentries, GFP_KERNEL);
if (h->scatter_list[i] == NULL) {
dev_err(&h->pdev->dev, "could not allocate "
"s/g lists\n");
return -ENOMEM;
}
}
return 0;
}
static void cciss_free_scatterlists(ctlr_info_t *h)
{
int i;
if (h->scatter_list) {
for (i = 0; i < h->nr_cmds; i++)
kfree(h->scatter_list[i]);
kfree(h->scatter_list);
}
}
static void cciss_free_cmd_pool(ctlr_info_t *h)
{
kfree(h->cmd_pool_bits);
if (h->cmd_pool)
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(CommandList_struct),
h->cmd_pool, h->cmd_pool_dhandle);
if (h->errinfo_pool)
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(ErrorInfo_struct),
h->errinfo_pool, h->errinfo_pool_dhandle);
}
static int cciss_request_irq(ctlr_info_t *h,
irqreturn_t (*msixhandler)(int, void *),
irqreturn_t (*intxhandler)(int, void *))
{
if (h->pdev->msi_enabled || h->pdev->msix_enabled) {
if (!request_irq(h->intr[h->intr_mode], msixhandler,
0, h->devname, h))
return 0;
dev_err(&h->pdev->dev, "Unable to get msi irq %d"
" for %s\n", h->intr[h->intr_mode],
h->devname);
return -1;
}
if (!request_irq(h->intr[h->intr_mode], intxhandler,
IRQF_SHARED, h->devname, h))
return 0;
dev_err(&h->pdev->dev, "Unable to get irq %d for %s\n",
h->intr[h->intr_mode], h->devname);
return -1;
}
static int cciss_kdump_soft_reset(ctlr_info_t *h)
{
if (cciss_send_reset(h, CTLR_LUNID, CCISS_RESET_TYPE_CONTROLLER)) {
dev_warn(&h->pdev->dev, "Resetting array controller failed.\n");
return -EIO;
}
dev_info(&h->pdev->dev, "Waiting for board to soft reset.\n");
if (cciss_wait_for_board_state(h->pdev, h->vaddr, BOARD_NOT_READY)) {
dev_warn(&h->pdev->dev, "Soft reset had no effect.\n");
return -1;
}
dev_info(&h->pdev->dev, "Board reset, awaiting READY status.\n");
if (cciss_wait_for_board_state(h->pdev, h->vaddr, BOARD_READY)) {
dev_warn(&h->pdev->dev, "Board failed to become ready "
"after soft reset.\n");
return -1;
}
return 0;
}
static void cciss_undo_allocations_after_kdump_soft_reset(ctlr_info_t *h)
{
int ctlr = h->ctlr;
free_irq(h->intr[h->intr_mode], h);
pci_free_irq_vectors(h->pdev);
cciss_free_sg_chain_blocks(h->cmd_sg_list, h->nr_cmds);
cciss_free_scatterlists(h);
cciss_free_cmd_pool(h);
kfree(h->blockFetchTable);
if (h->reply_pool)
pci_free_consistent(h->pdev, h->max_commands * sizeof(__u64),
h->reply_pool, h->reply_pool_dhandle);
if (h->transtable)
iounmap(h->transtable);
if (h->cfgtable)
iounmap(h->cfgtable);
if (h->vaddr)
iounmap(h->vaddr);
unregister_blkdev(h->major, h->devname);
cciss_destroy_hba_sysfs_entry(h);
pci_release_regions(h->pdev);
kfree(h);
hba[ctlr] = NULL;
}
static int cciss_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int i;
int j = 0;
int rc;
int try_soft_reset = 0;
int dac, return_code;
InquiryData_struct *inq_buff;
ctlr_info_t *h;
unsigned long flags;
if ((reset_devices) && (cciss_allow_hpsa == 1))
return -ENODEV;
rc = cciss_init_reset_devices(pdev);
if (rc) {
if (rc != -ENOTSUPP)
return rc;
try_soft_reset = 1;
rc = 0;
}
reinit_after_soft_reset:
i = alloc_cciss_hba(pdev);
if (i < 0)
return -ENOMEM;
h = hba[i];
h->pdev = pdev;
h->busy_initializing = 1;
h->intr_mode = cciss_simple_mode ? SIMPLE_MODE_INT : PERF_MODE_INT;
INIT_LIST_HEAD(&h->cmpQ);
INIT_LIST_HEAD(&h->reqQ);
mutex_init(&h->busy_shutting_down);
if (cciss_pci_init(h) != 0)
goto clean_no_release_regions;
sprintf(h->devname, "cciss%d", i);
h->ctlr = i;
if (cciss_tape_cmds < 2)
cciss_tape_cmds = 2;
if (cciss_tape_cmds > 16)
cciss_tape_cmds = 16;
init_completion(&h->scan_wait);
if (cciss_create_hba_sysfs_entry(h))
goto clean0;
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64)))
dac = 1;
else if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(32)))
dac = 0;
else {
dev_err(&h->pdev->dev, "no suitable DMA available\n");
goto clean1;
}
if (i < MAX_CTLR_ORIG)
h->major = COMPAQ_CISS_MAJOR + i;
rc = register_blkdev(h->major, h->devname);
if (rc == -EBUSY || rc == -EINVAL) {
dev_err(&h->pdev->dev,
"Unable to get major number %d for %s "
"on hba %d\n", h->major, h->devname, i);
goto clean1;
} else {
if (i >= MAX_CTLR_ORIG)
h->major = rc;
}
h->access.set_intr_mask(h, CCISS_INTR_OFF);
rc = cciss_request_irq(h, do_cciss_msix_intr, do_cciss_intx);
if (rc)
goto clean2;
dev_info(&h->pdev->dev, "%s: <0x%x> at PCI %s IRQ %d%s using DAC\n",
h->devname, pdev->device, pci_name(pdev),
h->intr[h->intr_mode], dac ? "" : " not");
if (cciss_allocate_cmd_pool(h))
goto clean4;
if (cciss_allocate_scatterlists(h))
goto clean4;
h->cmd_sg_list = cciss_allocate_sg_chain_blocks(h,
h->chainsize, h->nr_cmds);
if (!h->cmd_sg_list && h->chainsize > 0)
goto clean4;
spin_lock_init(&h->lock);
pci_set_drvdata(pdev, h);
bitmap_zero(h->cmd_pool_bits, h->nr_cmds);
h->num_luns = 0;
h->highest_lun = -1;
for (j = 0; j < CISS_MAX_LUN; j++) {
h->drv[j] = NULL;
h->gendisk[j] = NULL;
}
if (try_soft_reset) {
spin_lock_irqsave(&h->lock, flags);
h->access.set_intr_mask(h, CCISS_INTR_OFF);
spin_unlock_irqrestore(&h->lock, flags);
free_irq(h->intr[h->intr_mode], h);
rc = cciss_request_irq(h, cciss_msix_discard_completions,
cciss_intx_discard_completions);
if (rc) {
dev_warn(&h->pdev->dev, "Failed to request_irq after "
"soft reset.\n");
goto clean4;
}
rc = cciss_kdump_soft_reset(h);
if (rc) {
dev_warn(&h->pdev->dev, "Soft reset failed.\n");
goto clean4;
}
dev_info(&h->pdev->dev, "Board READY.\n");
dev_info(&h->pdev->dev,
"Waiting for stale completions to drain.\n");
h->access.set_intr_mask(h, CCISS_INTR_ON);
msleep(10000);
h->access.set_intr_mask(h, CCISS_INTR_OFF);
rc = controller_reset_failed(h->cfgtable);
if (rc)
dev_info(&h->pdev->dev,
"Soft reset appears to have failed.\n");
cciss_undo_allocations_after_kdump_soft_reset(h);
try_soft_reset = 0;
if (rc)
return -ENODEV;
goto reinit_after_soft_reset;
}
cciss_scsi_setup(h);
h->access.set_intr_mask(h, CCISS_INTR_ON);
inq_buff = kzalloc(sizeof(InquiryData_struct), GFP_KERNEL);
if (inq_buff == NULL) {
dev_err(&h->pdev->dev, "out of memory\n");
goto clean4;
}
return_code = sendcmd_withirq(h, CISS_INQUIRY, inq_buff,
sizeof(InquiryData_struct), 0, CTLR_LUNID, TYPE_CMD);
if (return_code == IO_OK) {
h->firm_ver[0] = inq_buff->data_byte[32];
h->firm_ver[1] = inq_buff->data_byte[33];
h->firm_ver[2] = inq_buff->data_byte[34];
h->firm_ver[3] = inq_buff->data_byte[35];
} else {
dev_warn(&h->pdev->dev, "unable to determine firmware"
" version of controller\n");
}
kfree(inq_buff);
cciss_procinit(h);
h->cciss_max_sectors = 8192;
rebuild_lun_table(h, 1, 0);
cciss_engage_scsi(h);
h->busy_initializing = 0;
return 0;
clean4:
cciss_free_cmd_pool(h);
cciss_free_scatterlists(h);
cciss_free_sg_chain_blocks(h->cmd_sg_list, h->nr_cmds);
free_irq(h->intr[h->intr_mode], h);
clean2:
unregister_blkdev(h->major, h->devname);
clean1:
cciss_destroy_hba_sysfs_entry(h);
clean0:
pci_release_regions(pdev);
clean_no_release_regions:
h->busy_initializing = 0;
pci_set_drvdata(pdev, NULL);
free_hba(h);
return -ENODEV;
}
static void cciss_shutdown(struct pci_dev *pdev)
{
ctlr_info_t *h;
char *flush_buf;
int return_code;
h = pci_get_drvdata(pdev);
flush_buf = kzalloc(4, GFP_KERNEL);
if (!flush_buf) {
dev_warn(&h->pdev->dev, "cache not flushed, out of memory.\n");
return;
}
return_code = sendcmd_withirq(h, CCISS_CACHE_FLUSH, flush_buf,
4, 0, CTLR_LUNID, TYPE_CMD);
kfree(flush_buf);
if (return_code != IO_OK)
dev_warn(&h->pdev->dev, "Error flushing cache\n");
h->access.set_intr_mask(h, CCISS_INTR_OFF);
free_irq(h->intr[h->intr_mode], h);
}
static int cciss_enter_simple_mode(struct ctlr_info *h)
{
u32 trans_support;
trans_support = readl(&(h->cfgtable->TransportSupport));
if (!(trans_support & SIMPLE_MODE))
return -ENOTSUPP;
h->max_commands = readl(&(h->cfgtable->CmdsOutMax));
writel(CFGTBL_Trans_Simple, &(h->cfgtable->HostWrite.TransportRequest));
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
cciss_wait_for_mode_change_ack(h);
print_cfg_table(h);
if (!(readl(&(h->cfgtable->TransportActive)) & CFGTBL_Trans_Simple)) {
dev_warn(&h->pdev->dev, "unable to get board into simple mode\n");
return -ENODEV;
}
h->transMethod = CFGTBL_Trans_Simple;
return 0;
}
static void cciss_remove_one(struct pci_dev *pdev)
{
ctlr_info_t *h;
int i, j;
if (pci_get_drvdata(pdev) == NULL) {
dev_err(&pdev->dev, "Unable to remove device\n");
return;
}
h = pci_get_drvdata(pdev);
i = h->ctlr;
if (hba[i] == NULL) {
dev_err(&pdev->dev, "device appears to already be removed\n");
return;
}
mutex_lock(&h->busy_shutting_down);
remove_from_scan_list(h);
remove_proc_entry(h->devname, proc_cciss);
unregister_blkdev(h->major, h->devname);
for (j = 0; j < CISS_MAX_LUN; j++) {
struct gendisk *disk = h->gendisk[j];
if (disk) {
struct request_queue *q = disk->queue;
if (disk->flags & GENHD_FL_UP) {
cciss_destroy_ld_sysfs_entry(h, j, 1);
del_gendisk(disk);
}
if (q)
blk_cleanup_queue(q);
}
}
#ifdef CONFIG_CISS_SCSI_TAPE
cciss_unregister_scsi(h);
#endif
cciss_shutdown(pdev);
pci_free_irq_vectors(h->pdev);
iounmap(h->transtable);
iounmap(h->cfgtable);
iounmap(h->vaddr);
cciss_free_cmd_pool(h);
for (j = 0; j < h->nr_cmds; j++)
kfree(h->scatter_list[j]);
kfree(h->scatter_list);
cciss_free_sg_chain_blocks(h->cmd_sg_list, h->nr_cmds);
kfree(h->blockFetchTable);
if (h->reply_pool)
pci_free_consistent(h->pdev, h->max_commands * sizeof(__u64),
h->reply_pool, h->reply_pool_dhandle);
pci_release_regions(pdev);
pci_set_drvdata(pdev, NULL);
cciss_destroy_hba_sysfs_entry(h);
mutex_unlock(&h->busy_shutting_down);
free_hba(h);
}
static int __init cciss_init(void)
{
int err;
BUILD_BUG_ON(sizeof(CommandList_struct) % COMMANDLIST_ALIGNMENT);
printk(KERN_INFO DRIVER_NAME "\n");
err = bus_register(&cciss_bus_type);
if (err)
return err;
cciss_scan_thread = kthread_run(scan_thread, NULL, "cciss_scan");
if (IS_ERR(cciss_scan_thread)) {
err = PTR_ERR(cciss_scan_thread);
goto err_bus_unregister;
}
err = pci_register_driver(&cciss_pci_driver);
if (err)
goto err_thread_stop;
return err;
err_thread_stop:
kthread_stop(cciss_scan_thread);
err_bus_unregister:
bus_unregister(&cciss_bus_type);
return err;
}
static void __exit cciss_cleanup(void)
{
int i;
pci_unregister_driver(&cciss_pci_driver);
for (i = 0; i < MAX_CTLR; i++) {
if (hba[i] != NULL) {
dev_warn(&hba[i]->pdev->dev,
"had to remove controller\n");
cciss_remove_one(hba[i]->pdev);
}
}
kthread_stop(cciss_scan_thread);
if (proc_cciss)
remove_proc_entry("driver/cciss", NULL);
bus_unregister(&cciss_bus_type);
}
