static int hwicap_command_desync(struct hwicap_drvdata *drvdata)
{
u32 buffer[4];
u32 index = 0;
buffer[index++] = hwicap_type_1_write(drvdata->config_regs->CMD) | 1;
buffer[index++] = XHI_CMD_DESYNCH;
buffer[index++] = XHI_NOOP_PACKET;
buffer[index++] = XHI_NOOP_PACKET;
return drvdata->config->set_configuration(drvdata,
&buffer[0], index);
}
static int hwicap_get_configuration_register(struct hwicap_drvdata *drvdata,
u32 reg, u32 *reg_data)
{
int status;
u32 buffer[6];
u32 index = 0;
buffer[index++] = XHI_DUMMY_PACKET;
buffer[index++] = XHI_NOOP_PACKET;
buffer[index++] = XHI_SYNC_PACKET;
buffer[index++] = XHI_NOOP_PACKET;
buffer[index++] = XHI_NOOP_PACKET;
status = drvdata->config->set_configuration(drvdata,
&buffer[0], index);
if (status)
return status;
status = drvdata->config->get_status(drvdata);
if ((status & XHI_SR_DALIGN_MASK) != XHI_SR_DALIGN_MASK)
return -EIO;
index = 0;
buffer[index++] = hwicap_type_1_read(reg) | 1;
buffer[index++] = XHI_NOOP_PACKET;
buffer[index++] = XHI_NOOP_PACKET;
status = drvdata->config->set_configuration(drvdata,
&buffer[0], index);
if (status)
return status;
status = drvdata->config->get_configuration(drvdata, reg_data, 1);
if (status)
return status;
return 0;
}
static int hwicap_initialize_hwicap(struct hwicap_drvdata *drvdata)
{
int status;
u32 idcode;
dev_dbg(drvdata->dev, "initializing\n");
dev_dbg(drvdata->dev, "Reset...\n");
drvdata->config->reset(drvdata);
dev_dbg(drvdata->dev, "Desync...\n");
status = hwicap_command_desync(drvdata);
if (status)
return status;
dev_dbg(drvdata->dev, "Reading IDCODE...\n");
status = hwicap_get_configuration_register(
drvdata, drvdata->config_regs->IDCODE, &idcode);
dev_dbg(drvdata->dev, "IDCODE = %x\n", idcode);
if (status)
return status;
dev_dbg(drvdata->dev, "Desync...\n");
status = hwicap_command_desync(drvdata);
if (status)
return status;
return 0;
}
static ssize_t
hwicap_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
struct hwicap_drvdata *drvdata = file->private_data;
ssize_t bytes_to_read = 0;
u32 *kbuf;
u32 words;
u32 bytes_remaining;
int status;
status = mutex_lock_interruptible(&drvdata->sem);
if (status)
return status;
if (drvdata->read_buffer_in_use) {
bytes_to_read =
(count < drvdata->read_buffer_in_use) ? count :
drvdata->read_buffer_in_use;
if (copy_to_user(buf, drvdata->read_buffer, bytes_to_read)) {
status = -EFAULT;
goto error;
}
drvdata->read_buffer_in_use -= bytes_to_read;
memmove(drvdata->read_buffer,
drvdata->read_buffer + bytes_to_read,
4 - bytes_to_read);
} else {
kbuf = (u32 *) get_zeroed_page(GFP_KERNEL);
if (!kbuf) {
status = -ENOMEM;
goto error;
}
words = ((count + 3) >> 2);
bytes_to_read = words << 2;
if (bytes_to_read > PAGE_SIZE)
bytes_to_read = PAGE_SIZE;
bytes_remaining = bytes_to_read & 3;
bytes_to_read &= ~3;
words = bytes_to_read >> 2;
status = drvdata->config->get_configuration(drvdata,
kbuf, words);
if (status) {
free_page((unsigned long)kbuf);
goto error;
}
if (copy_to_user(buf, kbuf, bytes_to_read)) {
free_page((unsigned long)kbuf);
status = -EFAULT;
goto error;
}
memcpy(drvdata->read_buffer,
kbuf,
bytes_remaining);
drvdata->read_buffer_in_use = bytes_remaining;
free_page((unsigned long)kbuf);
}
status = bytes_to_read;
error:
mutex_unlock(&drvdata->sem);
return status;
}
static ssize_t
hwicap_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct hwicap_drvdata *drvdata = file->private_data;
ssize_t written = 0;
ssize_t left = count;
u32 *kbuf;
ssize_t len;
ssize_t status;
status = mutex_lock_interruptible(&drvdata->sem);
if (status)
return status;
left += drvdata->write_buffer_in_use;
if (left < 4) {
status = 0;
goto error;
}
kbuf = (u32 *) __get_free_page(GFP_KERNEL);
if (!kbuf) {
status = -ENOMEM;
goto error;
}
while (left > 3) {
len = left;
if (len > PAGE_SIZE)
len = PAGE_SIZE;
len &= ~3;
if (drvdata->write_buffer_in_use) {
memcpy(kbuf, drvdata->write_buffer,
drvdata->write_buffer_in_use);
if (copy_from_user(
(((char *)kbuf) + drvdata->write_buffer_in_use),
buf + written,
len - (drvdata->write_buffer_in_use))) {
free_page((unsigned long)kbuf);
status = -EFAULT;
goto error;
}
} else {
if (copy_from_user(kbuf, buf + written, len)) {
free_page((unsigned long)kbuf);
status = -EFAULT;
goto error;
}
}
status = drvdata->config->set_configuration(drvdata,
kbuf, len >> 2);
if (status) {
free_page((unsigned long)kbuf);
status = -EFAULT;
goto error;
}
if (drvdata->write_buffer_in_use) {
len -= drvdata->write_buffer_in_use;
left -= drvdata->write_buffer_in_use;
drvdata->write_buffer_in_use = 0;
}
written += len;
left -= len;
}
if ((left > 0) && (left < 4)) {
if (!copy_from_user(drvdata->write_buffer,
buf + written, left)) {
drvdata->write_buffer_in_use = left;
written += left;
left = 0;
}
}
free_page((unsigned long)kbuf);
status = written;
error:
mutex_unlock(&drvdata->sem);
return status;
}
static int hwicap_open(struct inode *inode, struct file *file)
{
struct hwicap_drvdata *drvdata;
int status;
mutex_lock(&hwicap_mutex);
drvdata = container_of(inode->i_cdev, struct hwicap_drvdata, cdev);
status = mutex_lock_interruptible(&drvdata->sem);
if (status)
goto out;
if (drvdata->is_open) {
status = -EBUSY;
goto error;
}
status = hwicap_initialize_hwicap(drvdata);
if (status) {
dev_err(drvdata->dev, "Failed to open file");
goto error;
}
file->private_data = drvdata;
drvdata->write_buffer_in_use = 0;
drvdata->read_buffer_in_use = 0;
drvdata->is_open = 1;
error:
mutex_unlock(&drvdata->sem);
out:
mutex_unlock(&hwicap_mutex);
return status;
}
static int hwicap_release(struct inode *inode, struct file *file)
{
struct hwicap_drvdata *drvdata = file->private_data;
int i;
int status = 0;
mutex_lock(&drvdata->sem);
if (drvdata->write_buffer_in_use) {
for (i = drvdata->write_buffer_in_use; i < 4; i++)
drvdata->write_buffer[i] = 0;
status = drvdata->config->set_configuration(drvdata,
(u32 *) drvdata->write_buffer, 1);
if (status)
goto error;
}
status = hwicap_command_desync(drvdata);
if (status)
goto error;
error:
drvdata->is_open = 0;
mutex_unlock(&drvdata->sem);
return status;
}
static int __devinit hwicap_setup(struct device *dev, int id,
const struct resource *regs_res,
const struct hwicap_driver_config *config,
const struct config_registers *config_regs)
{
dev_t devt;
struct hwicap_drvdata *drvdata = NULL;
int retval = 0;
dev_info(dev, "Xilinx icap port driver\n");
mutex_lock(&icap_sem);
if (id < 0) {
for (id = 0; id < HWICAP_DEVICES; id++)
if (!probed_devices[id])
break;
}
if (id < 0 || id >= HWICAP_DEVICES) {
mutex_unlock(&icap_sem);
dev_err(dev, "%s%i too large\n", DRIVER_NAME, id);
return -EINVAL;
}
if (probed_devices[id]) {
mutex_unlock(&icap_sem);
dev_err(dev, "cannot assign to %s%i; it is already in use\n",
DRIVER_NAME, id);
return -EBUSY;
}
probed_devices[id] = 1;
mutex_unlock(&icap_sem);
devt = MKDEV(XHWICAP_MAJOR, XHWICAP_MINOR + id);
drvdata = kzalloc(sizeof(struct hwicap_drvdata), GFP_KERNEL);
if (!drvdata) {
dev_err(dev, "Couldn't allocate device private record\n");
retval = -ENOMEM;
goto failed0;
}
dev_set_drvdata(dev, (void *)drvdata);
if (!regs_res) {
dev_err(dev, "Couldn't get registers resource\n");
retval = -EFAULT;
goto failed1;
}
drvdata->mem_start = regs_res->start;
drvdata->mem_end = regs_res->end;
drvdata->mem_size = resource_size(regs_res);
if (!request_mem_region(drvdata->mem_start,
drvdata->mem_size, DRIVER_NAME)) {
dev_err(dev, "Couldn't lock memory region at %Lx\n",
(unsigned long long) regs_res->start);
retval = -EBUSY;
goto failed1;
}
drvdata->devt = devt;
drvdata->dev = dev;
drvdata->base_address = ioremap(drvdata->mem_start, drvdata->mem_size);
if (!drvdata->base_address) {
dev_err(dev, "ioremap() failed\n");
goto failed2;
}
drvdata->config = config;
drvdata->config_regs = config_regs;
mutex_init(&drvdata->sem);
drvdata->is_open = 0;
dev_info(dev, "ioremap %llx to %p with size %llx\n",
(unsigned long long) drvdata->mem_start,
drvdata->base_address,
(unsigned long long) drvdata->mem_size);
cdev_init(&drvdata->cdev, &hwicap_fops);
drvdata->cdev.owner = THIS_MODULE;
retval = cdev_add(&drvdata->cdev, devt, 1);
if (retval) {
dev_err(dev, "cdev_add() failed\n");
goto failed3;
}
device_create(icap_class, dev, devt, NULL, "%s%d", DRIVER_NAME, id);
return 0;
failed3:
iounmap(drvdata->base_address);
failed2:
release_mem_region(regs_res->start, drvdata->mem_size);
failed1:
kfree(drvdata);
failed0:
mutex_lock(&icap_sem);
probed_devices[id] = 0;
mutex_unlock(&icap_sem);
return retval;
}
static int __devexit hwicap_remove(struct device *dev)
{
struct hwicap_drvdata *drvdata;
drvdata = (struct hwicap_drvdata *)dev_get_drvdata(dev);
if (!drvdata)
return 0;
device_destroy(icap_class, drvdata->devt);
cdev_del(&drvdata->cdev);
iounmap(drvdata->base_address);
release_mem_region(drvdata->mem_start, drvdata->mem_size);
kfree(drvdata);
dev_set_drvdata(dev, NULL);
mutex_lock(&icap_sem);
probed_devices[MINOR(dev->devt)-XHWICAP_MINOR] = 0;
mutex_unlock(&icap_sem);
return 0;
}
static int __devinit hwicap_of_probe(struct platform_device *op,
const struct hwicap_driver_config *config)
{
struct resource res;
const unsigned int *id;
const char *family;
int rc;
const struct config_registers *regs;
rc = of_address_to_resource(op->dev.of_node, 0, &res);
if (rc) {
dev_err(&op->dev, "invalid address\n");
return rc;
}
id = of_get_property(op->dev.of_node, "port-number", NULL);
regs = &v4_config_registers;
family = of_get_property(op->dev.of_node, "xlnx,family", NULL);
if (family) {
if (!strcmp(family, "virtex2p")) {
regs = &v2_config_registers;
} else if (!strcmp(family, "virtex4")) {
regs = &v4_config_registers;
} else if (!strcmp(family, "virtex5")) {
regs = &v5_config_registers;
}
}
return hwicap_setup(&op->dev, id ? *id : -1, &res, config,
regs);
}
static inline int hwicap_of_probe(struct platform_device *op,
const struct hwicap_driver_config *config)
{
return -EINVAL;
}
static int __devinit hwicap_drv_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct resource *res;
const struct config_registers *regs;
const char *family;
match = of_match_device(hwicap_of_match, &pdev->dev);
if (match)
return hwicap_of_probe(pdev, match->data);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
regs = &v4_config_registers;
family = pdev->dev.platform_data;
if (family) {
if (!strcmp(family, "virtex2p")) {
regs = &v2_config_registers;
} else if (!strcmp(family, "virtex4")) {
regs = &v4_config_registers;
} else if (!strcmp(family, "virtex5")) {
regs = &v5_config_registers;
}
}
return hwicap_setup(&pdev->dev, pdev->id, res,
&buffer_icap_config, regs);
}
static int __devexit hwicap_drv_remove(struct platform_device *pdev)
{
return hwicap_remove(&pdev->dev);
}
static int __init hwicap_module_init(void)
{
dev_t devt;
int retval;
icap_class = class_create(THIS_MODULE, "xilinx_config");
mutex_init(&icap_sem);
devt = MKDEV(XHWICAP_MAJOR, XHWICAP_MINOR);
retval = register_chrdev_region(devt,
HWICAP_DEVICES,
DRIVER_NAME);
if (retval < 0)
return retval;
retval = platform_driver_register(&hwicap_platform_driver);
if (retval)
goto failed;
return retval;
failed:
unregister_chrdev_region(devt, HWICAP_DEVICES);
return retval;
}
static void __exit hwicap_module_cleanup(void)
{
dev_t devt = MKDEV(XHWICAP_MAJOR, XHWICAP_MINOR);
class_destroy(icap_class);
platform_driver_unregister(&hwicap_platform_driver);
unregister_chrdev_region(devt, HWICAP_DEVICES);
}
