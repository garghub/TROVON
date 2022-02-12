struct aac_driver_ident* aac_get_driver_ident(int devtype)
{
return &aac_drivers[devtype];
}
static int aac_biosparm(struct scsi_device *sdev, struct block_device *bdev,
sector_t capacity, int *geom)
{
struct diskparm *param = (struct diskparm *)geom;
unsigned char *buf;
dprintk((KERN_DEBUG "aac_biosparm.\n"));
if (capacity >= 2 * 1024 * 1024) {
if(capacity >= 4 * 1024 * 1024) {
param->heads = 255;
param->sectors = 63;
} else {
param->heads = 128;
param->sectors = 32;
}
} else {
param->heads = 64;
param->sectors = 32;
}
param->cylinders = cap_to_cyls(capacity, param->heads * param->sectors);
buf = scsi_bios_ptable(bdev);
if (!buf)
return 0;
if(*(__le16 *)(buf + 0x40) == cpu_to_le16(0xaa55)) {
struct partition *first = (struct partition * )buf;
struct partition *entry = first;
int saved_cylinders = param->cylinders;
int num;
unsigned char end_head, end_sec;
for(num = 0; num < 4; num++) {
end_head = entry->end_head;
end_sec = entry->end_sector & 0x3f;
if(end_head == 63) {
param->heads = 64;
param->sectors = 32;
break;
} else if(end_head == 127) {
param->heads = 128;
param->sectors = 32;
break;
} else if(end_head == 254) {
param->heads = 255;
param->sectors = 63;
break;
}
entry++;
}
if (num == 4) {
end_head = first->end_head;
end_sec = first->end_sector & 0x3f;
}
param->cylinders = cap_to_cyls(capacity, param->heads * param->sectors);
if (num < 4 && end_sec == param->sectors) {
if (param->cylinders != saved_cylinders)
dprintk((KERN_DEBUG "Adopting geometry: heads=%d, sectors=%d from partition table %d.\n",
param->heads, param->sectors, num));
} else if (end_head > 0 || end_sec > 0) {
dprintk((KERN_DEBUG "Strange geometry: heads=%d, sectors=%d in partition table %d.\n",
end_head + 1, end_sec, num));
dprintk((KERN_DEBUG "Using geometry: heads=%d, sectors=%d.\n",
param->heads, param->sectors));
}
}
kfree(buf);
return 0;
}
static int aac_slave_configure(struct scsi_device *sdev)
{
struct aac_dev *aac = (struct aac_dev *)sdev->host->hostdata;
if (aac->jbod && (sdev->type == TYPE_DISK))
sdev->removable = 1;
if ((sdev->type == TYPE_DISK) &&
(sdev_channel(sdev) != CONTAINER_CHANNEL) &&
(!aac->jbod || sdev->inq_periph_qual) &&
(!aac->raid_scsi_mode || (sdev_channel(sdev) != 2))) {
if (expose_physicals == 0)
return -ENXIO;
if (expose_physicals < 0)
sdev->no_uld_attach = 1;
}
if (sdev->tagged_supported && (sdev->type == TYPE_DISK) &&
(!aac->raid_scsi_mode || (sdev_channel(sdev) != 2)) &&
!sdev->no_uld_attach) {
struct scsi_device * dev;
struct Scsi_Host *host = sdev->host;
unsigned num_lsu = 0;
unsigned num_one = 0;
unsigned depth;
unsigned cid;
if (sdev->request_queue->rq_timeout < (45 * HZ))
blk_queue_rq_timeout(sdev->request_queue, 45*HZ);
for (cid = 0; cid < aac->maximum_num_containers; ++cid)
if (aac->fsa_dev[cid].valid)
++num_lsu;
__shost_for_each_device(dev, host) {
if (dev->tagged_supported && (dev->type == TYPE_DISK) &&
(!aac->raid_scsi_mode ||
(sdev_channel(sdev) != 2)) &&
!dev->no_uld_attach) {
if ((sdev_channel(dev) != CONTAINER_CHANNEL)
|| !aac->fsa_dev[sdev_id(dev)].valid)
++num_lsu;
} else
++num_one;
}
if (num_lsu == 0)
++num_lsu;
depth = (host->can_queue - num_one) / num_lsu;
if (depth > 256)
depth = 256;
else if (depth < 2)
depth = 2;
scsi_adjust_queue_depth(sdev, MSG_ORDERED_TAG, depth);
} else
scsi_adjust_queue_depth(sdev, 0, 1);
return 0;
}
static int aac_change_queue_depth(struct scsi_device *sdev, int depth,
int reason)
{
if (reason != SCSI_QDEPTH_DEFAULT)
return -EOPNOTSUPP;
if (sdev->tagged_supported && (sdev->type == TYPE_DISK) &&
(sdev_channel(sdev) == CONTAINER_CHANNEL)) {
struct scsi_device * dev;
struct Scsi_Host *host = sdev->host;
unsigned num = 0;
__shost_for_each_device(dev, host) {
if (dev->tagged_supported && (dev->type == TYPE_DISK) &&
(sdev_channel(dev) == CONTAINER_CHANNEL))
++num;
++num;
}
if (num >= host->can_queue)
num = host->can_queue - 1;
if (depth > (host->can_queue - num))
depth = host->can_queue - num;
if (depth > 256)
depth = 256;
else if (depth < 2)
depth = 2;
scsi_adjust_queue_depth(sdev, MSG_ORDERED_TAG, depth);
} else
scsi_adjust_queue_depth(sdev, 0, 1);
return sdev->queue_depth;
}
static ssize_t aac_show_raid_level(struct device *dev, struct device_attribute *attr, char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
struct aac_dev *aac = (struct aac_dev *)(sdev->host->hostdata);
if (sdev_channel(sdev) != CONTAINER_CHANNEL)
return snprintf(buf, PAGE_SIZE, sdev->no_uld_attach
? "Hidden\n" :
((aac->jbod && (sdev->type == TYPE_DISK)) ? "JBOD\n" : ""));
return snprintf(buf, PAGE_SIZE, "%s\n",
get_container_type(aac->fsa_dev[sdev_id(sdev)].type));
}
static int aac_ioctl(struct scsi_device *sdev, int cmd, void __user * arg)
{
struct aac_dev *dev = (struct aac_dev *)sdev->host->hostdata;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
return aac_do_ioctl(dev, cmd, arg);
}
static int aac_eh_abort(struct scsi_cmnd* cmd)
{
struct scsi_device * dev = cmd->device;
struct Scsi_Host * host = dev->host;
struct aac_dev * aac = (struct aac_dev *)host->hostdata;
int count;
int ret = FAILED;
printk(KERN_ERR "%s: Host adapter abort request (%d,%d,%d,%d)\n",
AAC_DRIVERNAME,
host->host_no, sdev_channel(dev), sdev_id(dev), dev->lun);
switch (cmd->cmnd[0]) {
case SERVICE_ACTION_IN:
if (!(aac->raw_io_interface) ||
!(aac->raw_io_64) ||
((cmd->cmnd[1] & 0x1f) != SAI_READ_CAPACITY_16))
break;
case INQUIRY:
case READ_CAPACITY:
for (count = 0; count < (host->can_queue + AAC_NUM_MGT_FIB); ++count) {
struct fib * fib = &aac->fibs[count];
if (fib->hw_fib_va->header.XferState &&
(fib->flags & FIB_CONTEXT_FLAG) &&
(fib->callback_data == cmd)) {
fib->flags |= FIB_CONTEXT_FLAG_TIMED_OUT;
cmd->SCp.phase = AAC_OWNER_ERROR_HANDLER;
ret = SUCCESS;
}
}
break;
case TEST_UNIT_READY:
for (count = 0; count < (host->can_queue + AAC_NUM_MGT_FIB); ++count) {
struct scsi_cmnd * command;
struct fib * fib = &aac->fibs[count];
if ((fib->hw_fib_va->header.XferState & cpu_to_le32(Async | NoResponseExpected)) &&
(fib->flags & FIB_CONTEXT_FLAG) &&
((command = fib->callback_data)) &&
(command->device == cmd->device)) {
fib->flags |= FIB_CONTEXT_FLAG_TIMED_OUT;
command->SCp.phase = AAC_OWNER_ERROR_HANDLER;
if (command == cmd)
ret = SUCCESS;
}
}
}
return ret;
}
static int aac_eh_reset(struct scsi_cmnd* cmd)
{
struct scsi_device * dev = cmd->device;
struct Scsi_Host * host = dev->host;
struct scsi_cmnd * command;
int count;
struct aac_dev * aac = (struct aac_dev *)host->hostdata;
unsigned long flags;
for (count = 0; count < (host->can_queue + AAC_NUM_MGT_FIB); ++count) {
struct fib * fib = &aac->fibs[count];
if (fib->hw_fib_va->header.XferState &&
(fib->flags & FIB_CONTEXT_FLAG) &&
(fib->callback_data == cmd)) {
fib->flags |= FIB_CONTEXT_FLAG_TIMED_OUT;
cmd->SCp.phase = AAC_OWNER_ERROR_HANDLER;
}
}
printk(KERN_ERR "%s: Host adapter reset request. SCSI hang ?\n",
AAC_DRIVERNAME);
if ((count = aac_check_health(aac)))
return count;
for (count = 60; count; --count) {
int active = aac->in_reset;
if (active == 0)
__shost_for_each_device(dev, host) {
spin_lock_irqsave(&dev->list_lock, flags);
list_for_each_entry(command, &dev->cmd_list, list) {
if ((command != cmd) &&
(command->SCp.phase == AAC_OWNER_FIRMWARE)) {
active++;
break;
}
}
spin_unlock_irqrestore(&dev->list_lock, flags);
if (active)
break;
}
if (active == 0)
return SUCCESS;
ssleep(1);
}
printk(KERN_ERR "%s: SCSI bus appears hung\n", AAC_DRIVERNAME);
if (((aac->supplement_adapter_info.SupportedOptions2 &
AAC_OPTION_MU_RESET) ||
(aac->supplement_adapter_info.SupportedOptions2 &
AAC_OPTION_DOORBELL_RESET)) &&
aac_check_reset &&
((aac_check_reset != 1) ||
!(aac->supplement_adapter_info.SupportedOptions2 &
AAC_OPTION_IGNORE_RESET)))
aac_reset_adapter(aac, 2);
return SUCCESS;
}
static int aac_cfg_open(struct inode *inode, struct file *file)
{
struct aac_dev *aac;
unsigned minor_number = iminor(inode);
int err = -ENODEV;
mutex_lock(&aac_mutex);
list_for_each_entry(aac, &aac_devices, entry) {
if (aac->id == minor_number) {
file->private_data = aac;
err = 0;
break;
}
}
mutex_unlock(&aac_mutex);
return err;
}
static long aac_cfg_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
int ret;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
mutex_lock(&aac_mutex);
ret = aac_do_ioctl(file->private_data, cmd, (void __user *)arg);
mutex_unlock(&aac_mutex);
return ret;
}
static long aac_compat_do_ioctl(struct aac_dev *dev, unsigned cmd, unsigned long arg)
{
long ret;
mutex_lock(&aac_mutex);
switch (cmd) {
case FSACTL_MINIPORT_REV_CHECK:
case FSACTL_SENDFIB:
case FSACTL_OPEN_GET_ADAPTER_FIB:
case FSACTL_CLOSE_GET_ADAPTER_FIB:
case FSACTL_SEND_RAW_SRB:
case FSACTL_GET_PCI_INFO:
case FSACTL_QUERY_DISK:
case FSACTL_DELETE_DISK:
case FSACTL_FORCE_DELETE_DISK:
case FSACTL_GET_CONTAINERS:
case FSACTL_SEND_LARGE_FIB:
ret = aac_do_ioctl(dev, cmd, (void __user *)arg);
break;
case FSACTL_GET_NEXT_ADAPTER_FIB: {
struct fib_ioctl __user *f;
f = compat_alloc_user_space(sizeof(*f));
ret = 0;
if (clear_user(f, sizeof(*f)))
ret = -EFAULT;
if (copy_in_user(f, (void __user *)arg, sizeof(struct fib_ioctl) - sizeof(u32)))
ret = -EFAULT;
if (!ret)
ret = aac_do_ioctl(dev, cmd, f);
break;
}
default:
ret = -ENOIOCTLCMD;
break;
}
mutex_unlock(&aac_mutex);
return ret;
}
static int aac_compat_ioctl(struct scsi_device *sdev, int cmd, void __user *arg)
{
struct aac_dev *dev = (struct aac_dev *)sdev->host->hostdata;
return aac_compat_do_ioctl(dev, cmd, (unsigned long)arg);
}
static long aac_compat_cfg_ioctl(struct file *file, unsigned cmd, unsigned long arg)
{
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
return aac_compat_do_ioctl(file->private_data, cmd, arg);
}
static ssize_t aac_show_model(struct device *device,
struct device_attribute *attr, char *buf)
{
struct aac_dev *dev = (struct aac_dev*)class_to_shost(device)->hostdata;
int len;
if (dev->supplement_adapter_info.AdapterTypeText[0]) {
char * cp = dev->supplement_adapter_info.AdapterTypeText;
while (*cp && *cp != ' ')
++cp;
while (*cp == ' ')
++cp;
len = snprintf(buf, PAGE_SIZE, "%s\n", cp);
} else
len = snprintf(buf, PAGE_SIZE, "%s\n",
aac_drivers[dev->cardtype].model);
return len;
}
static ssize_t aac_show_vendor(struct device *device,
struct device_attribute *attr, char *buf)
{
struct aac_dev *dev = (struct aac_dev*)class_to_shost(device)->hostdata;
int len;
if (dev->supplement_adapter_info.AdapterTypeText[0]) {
char * cp = dev->supplement_adapter_info.AdapterTypeText;
while (*cp && *cp != ' ')
++cp;
len = snprintf(buf, PAGE_SIZE, "%.*s\n",
(int)(cp - (char *)dev->supplement_adapter_info.AdapterTypeText),
dev->supplement_adapter_info.AdapterTypeText);
} else
len = snprintf(buf, PAGE_SIZE, "%s\n",
aac_drivers[dev->cardtype].vname);
return len;
}
static ssize_t aac_show_flags(struct device *cdev,
struct device_attribute *attr, char *buf)
{
int len = 0;
struct aac_dev *dev = (struct aac_dev*)class_to_shost(cdev)->hostdata;
if (nblank(dprintk(x)))
len = snprintf(buf, PAGE_SIZE, "dprintk\n");
#ifdef AAC_DETAILED_STATUS_INFO
len += snprintf(buf + len, PAGE_SIZE - len,
"AAC_DETAILED_STATUS_INFO\n");
#endif
if (dev->raw_io_interface && dev->raw_io_64)
len += snprintf(buf + len, PAGE_SIZE - len,
"SAI_READ_CAPACITY_16\n");
if (dev->jbod)
len += snprintf(buf + len, PAGE_SIZE - len, "SUPPORTED_JBOD\n");
if (dev->supplement_adapter_info.SupportedOptions2 &
AAC_OPTION_POWER_MANAGEMENT)
len += snprintf(buf + len, PAGE_SIZE - len,
"SUPPORTED_POWER_MANAGEMENT\n");
if (dev->msi)
len += snprintf(buf + len, PAGE_SIZE - len, "PCI_HAS_MSI\n");
return len;
}
static ssize_t aac_show_kernel_version(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct aac_dev *dev = (struct aac_dev*)class_to_shost(device)->hostdata;
int len, tmp;
tmp = le32_to_cpu(dev->adapter_info.kernelrev);
len = snprintf(buf, PAGE_SIZE, "%d.%d-%d[%d]\n",
tmp >> 24, (tmp >> 16) & 0xff, tmp & 0xff,
le32_to_cpu(dev->adapter_info.kernelbuild));
return len;
}
static ssize_t aac_show_monitor_version(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct aac_dev *dev = (struct aac_dev*)class_to_shost(device)->hostdata;
int len, tmp;
tmp = le32_to_cpu(dev->adapter_info.monitorrev);
len = snprintf(buf, PAGE_SIZE, "%d.%d-%d[%d]\n",
tmp >> 24, (tmp >> 16) & 0xff, tmp & 0xff,
le32_to_cpu(dev->adapter_info.monitorbuild));
return len;
}
static ssize_t aac_show_bios_version(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct aac_dev *dev = (struct aac_dev*)class_to_shost(device)->hostdata;
int len, tmp;
tmp = le32_to_cpu(dev->adapter_info.biosrev);
len = snprintf(buf, PAGE_SIZE, "%d.%d-%d[%d]\n",
tmp >> 24, (tmp >> 16) & 0xff, tmp & 0xff,
le32_to_cpu(dev->adapter_info.biosbuild));
return len;
}
static ssize_t aac_show_serial_number(struct device *device,
struct device_attribute *attr, char *buf)
{
struct aac_dev *dev = (struct aac_dev*)class_to_shost(device)->hostdata;
int len = 0;
if (le32_to_cpu(dev->adapter_info.serial[0]) != 0xBAD0)
len = snprintf(buf, 16, "%06X\n",
le32_to_cpu(dev->adapter_info.serial[0]));
if (len &&
!memcmp(&dev->supplement_adapter_info.MfgPcbaSerialNo[
sizeof(dev->supplement_adapter_info.MfgPcbaSerialNo)-len],
buf, len-1))
len = snprintf(buf, 16, "%.*s\n",
(int)sizeof(dev->supplement_adapter_info.MfgPcbaSerialNo),
dev->supplement_adapter_info.MfgPcbaSerialNo);
return min(len, 16);
}
static ssize_t aac_show_max_channel(struct device *device,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n",
class_to_shost(device)->max_channel);
}
static ssize_t aac_show_max_id(struct device *device,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n",
class_to_shost(device)->max_id);
}
static ssize_t aac_store_reset_adapter(struct device *device,
struct device_attribute *attr,
const char *buf, size_t count)
{
int retval = -EACCES;
if (!capable(CAP_SYS_ADMIN))
return retval;
retval = aac_reset_adapter((struct aac_dev*)class_to_shost(device)->hostdata, buf[0] == '!');
if (retval >= 0)
retval = count;
return retval;
}
static ssize_t aac_show_reset_adapter(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct aac_dev *dev = (struct aac_dev*)class_to_shost(device)->hostdata;
int len, tmp;
tmp = aac_adapter_check_health(dev);
if ((tmp == 0) && dev->in_reset)
tmp = -EBUSY;
len = snprintf(buf, PAGE_SIZE, "0x%x\n", tmp);
return len;
}
ssize_t aac_get_serial_number(struct device *device, char *buf)
{
return aac_show_serial_number(device, &aac_serial_number, buf);
}
static void __aac_shutdown(struct aac_dev * aac)
{
if (aac->aif_thread) {
int i;
for (i = 0; i < (aac->scsi_host_ptr->can_queue + AAC_NUM_MGT_FIB); i++) {
struct fib *fib = &aac->fibs[i];
if (!(fib->hw_fib_va->header.XferState & cpu_to_le32(NoResponseExpected | Async)) &&
(fib->hw_fib_va->header.XferState & cpu_to_le32(ResponseExpected)))
up(&fib->event_wait);
}
kthread_stop(aac->thread);
}
aac_send_shutdown(aac);
aac_adapter_disable_int(aac);
free_irq(aac->pdev->irq, aac);
if (aac->msi)
pci_disable_msi(aac->pdev);
}
static int __devinit aac_probe_one(struct pci_dev *pdev,
const struct pci_device_id *id)
{
unsigned index = id->driver_data;
struct Scsi_Host *shost;
struct aac_dev *aac;
struct list_head *insert = &aac_devices;
int error = -ENODEV;
int unique_id = 0;
u64 dmamask;
extern int aac_sync_mode;
list_for_each_entry(aac, &aac_devices, entry) {
if (aac->id > unique_id)
break;
insert = &aac->entry;
unique_id++;
}
pci_disable_link_state(pdev, PCIE_LINK_STATE_L0S | PCIE_LINK_STATE_L1 |
PCIE_LINK_STATE_CLKPM);
error = pci_enable_device(pdev);
if (error)
goto out;
error = -ENODEV;
if (aac_drivers[index].quirks & AAC_QUIRK_31BIT)
dmamask = DMA_BIT_MASK(31);
else
dmamask = DMA_BIT_MASK(32);
if (pci_set_dma_mask(pdev, dmamask) ||
pci_set_consistent_dma_mask(pdev, dmamask))
goto out_disable_pdev;
pci_set_master(pdev);
shost = scsi_host_alloc(&aac_driver_template, sizeof(struct aac_dev));
if (!shost)
goto out_disable_pdev;
shost->irq = pdev->irq;
shost->unique_id = unique_id;
shost->max_cmd_len = 16;
aac = (struct aac_dev *)shost->hostdata;
aac->base_start = pci_resource_start(pdev, 0);
aac->scsi_host_ptr = shost;
aac->pdev = pdev;
aac->name = aac_driver_template.name;
aac->id = shost->unique_id;
aac->cardtype = index;
INIT_LIST_HEAD(&aac->entry);
aac->fibs = kzalloc(sizeof(struct fib) * (shost->can_queue + AAC_NUM_MGT_FIB), GFP_KERNEL);
if (!aac->fibs)
goto out_free_host;
spin_lock_init(&aac->fib_lock);
aac->base_size = AAC_MIN_FOOTPRINT_SIZE;
if ((*aac_drivers[index].init)(aac))
goto out_unmap;
if (aac->sync_mode) {
if (aac_sync_mode)
printk(KERN_INFO "%s%d: Sync. mode enforced "
"by driver parameter. This will cause "
"a significant performance decrease!\n",
aac->name,
aac->id);
else
printk(KERN_INFO "%s%d: Async. mode not supported "
"by current driver, sync. mode enforced."
"\nPlease update driver to get full performance.\n",
aac->name,
aac->id);
}
aac->thread = kthread_run(aac_command_thread, aac, AAC_DRIVERNAME);
if (IS_ERR(aac->thread)) {
printk(KERN_ERR "aacraid: Unable to create command thread.\n");
error = PTR_ERR(aac->thread);
aac->thread = NULL;
goto out_deinit;
}
if (aac_drivers[index].quirks & AAC_QUIRK_31BIT)
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32)))
goto out_deinit;
aac->maximum_num_channels = aac_drivers[index].channels;
error = aac_get_adapter_info(aac);
if (error < 0)
goto out_deinit;
if ((aac_drivers[index].quirks & AAC_QUIRK_34SG) &&
(shost->sg_tablesize > 34)) {
shost->sg_tablesize = 34;
shost->max_sectors = (shost->sg_tablesize * 8) + 112;
}
if ((aac_drivers[index].quirks & AAC_QUIRK_17SG) &&
(shost->sg_tablesize > 17)) {
shost->sg_tablesize = 17;
shost->max_sectors = (shost->sg_tablesize * 8) + 112;
}
error = pci_set_dma_max_seg_size(pdev,
(aac->adapter_info.options & AAC_OPT_NEW_COMM) ?
(shost->max_sectors << 9) : 65536);
if (error)
goto out_deinit;
if (aac_drivers[index].quirks & AAC_QUIRK_34SG)
aac->printf_enabled = 1;
else
aac->printf_enabled = 0;
if (aac->nondasd_support || expose_physicals || aac->jbod)
shost->max_channel = aac->maximum_num_channels;
else
shost->max_channel = 0;
aac_get_config_status(aac, 0);
aac_get_containers(aac);
list_add(&aac->entry, insert);
shost->max_id = aac->maximum_num_containers;
if (shost->max_id < aac->maximum_num_physicals)
shost->max_id = aac->maximum_num_physicals;
if (shost->max_id < MAXIMUM_NUM_CONTAINERS)
shost->max_id = MAXIMUM_NUM_CONTAINERS;
else
shost->this_id = shost->max_id;
shost->max_lun = AAC_MAX_LUN;
pci_set_drvdata(pdev, shost);
error = scsi_add_host(shost, &pdev->dev);
if (error)
goto out_deinit;
scsi_scan_host(shost);
return 0;
out_deinit:
__aac_shutdown(aac);
out_unmap:
aac_fib_map_free(aac);
if (aac->comm_addr)
pci_free_consistent(aac->pdev, aac->comm_size, aac->comm_addr,
aac->comm_phys);
kfree(aac->queues);
aac_adapter_ioremap(aac, 0);
kfree(aac->fibs);
kfree(aac->fsa_dev);
out_free_host:
scsi_host_put(shost);
out_disable_pdev:
pci_disable_device(pdev);
out:
return error;
}
static void aac_shutdown(struct pci_dev *dev)
{
struct Scsi_Host *shost = pci_get_drvdata(dev);
scsi_block_requests(shost);
__aac_shutdown((struct aac_dev *)shost->hostdata);
}
static void __devexit aac_remove_one(struct pci_dev *pdev)
{
struct Scsi_Host *shost = pci_get_drvdata(pdev);
struct aac_dev *aac = (struct aac_dev *)shost->hostdata;
scsi_remove_host(shost);
__aac_shutdown(aac);
aac_fib_map_free(aac);
pci_free_consistent(aac->pdev, aac->comm_size, aac->comm_addr,
aac->comm_phys);
kfree(aac->queues);
aac_adapter_ioremap(aac, 0);
kfree(aac->fibs);
kfree(aac->fsa_dev);
list_del(&aac->entry);
scsi_host_put(shost);
pci_disable_device(pdev);
if (list_empty(&aac_devices)) {
unregister_chrdev(aac_cfg_major, "aac");
aac_cfg_major = -1;
}
}
static int __init aac_init(void)
{
int error;
printk(KERN_INFO "Adaptec %s driver %s\n",
AAC_DRIVERNAME, aac_driver_version);
error = pci_register_driver(&aac_pci_driver);
if (error < 0)
return error;
aac_cfg_major = register_chrdev( 0, "aac", &aac_cfg_fops);
if (aac_cfg_major < 0) {
printk(KERN_WARNING
"aacraid: unable to register \"aac\" device.\n");
}
return 0;
}
static void __exit aac_exit(void)
{
if (aac_cfg_major > -1)
unregister_chrdev(aac_cfg_major, "aac");
pci_unregister_driver(&aac_pci_driver);
}
