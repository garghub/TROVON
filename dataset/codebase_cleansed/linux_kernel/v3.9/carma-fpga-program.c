static void fpga_drop_firmware_data(struct fpga_dev *priv)
{
videobuf_dma_free(&priv->vb);
priv->vb_allocated = false;
priv->bytes = 0;
}
static void fpga_dev_remove(struct kref *ref)
{
struct fpga_dev *priv = container_of(ref, struct fpga_dev, ref);
fpga_drop_firmware_data(priv);
mutex_destroy(&priv->lock);
kfree(priv);
}
static void ledtrig_fpga_programmed(bool enabled)
{
if (enabled)
led_trigger_event(ledtrig_fpga, LED_FULL);
else
led_trigger_event(ledtrig_fpga, LED_OFF);
}
static int fpga_fifo_size(void __iomem *regs)
{
return ioread32be(regs + FPGA_CONFIG_FIFO_SIZE);
}
static int fpga_config_error(void __iomem *regs)
{
return ioread32be(regs + FPGA_CONFIG_STATUS) & CFG_STATUS_ERR_MASK;
}
static int fpga_fifo_empty(void __iomem *regs)
{
return ioread32be(regs + FPGA_CONFIG_FIFO_USED) == 0;
}
static void fpga_fifo_write(void __iomem *regs, u32 val)
{
iowrite32be(val, regs + FPGA_FIFO_ADDRESS);
}
static void fpga_set_byte_count(void __iomem *regs, u32 count)
{
iowrite32be(count, regs + FPGA_CONFIG_TOTAL_BYTE_COUNT);
}
static void fpga_programmer_enable(struct fpga_dev *priv, bool dma)
{
u32 val;
val = (dma) ? (CFG_CTL_ENABLE | CFG_CTL_DMA) : CFG_CTL_ENABLE;
iowrite32be(val, priv->regs + FPGA_CONFIG_CONTROL);
}
static void fpga_programmer_disable(struct fpga_dev *priv)
{
iowrite32be(0x0, priv->regs + FPGA_CONFIG_CONTROL);
}
static void fpga_dump_registers(struct fpga_dev *priv)
{
u32 control, status, size, used, total, curr;
if (priv->status == 0)
return;
control = ioread32be(priv->regs + FPGA_CONFIG_CONTROL);
status = ioread32be(priv->regs + FPGA_CONFIG_STATUS);
size = ioread32be(priv->regs + FPGA_CONFIG_FIFO_SIZE);
used = ioread32be(priv->regs + FPGA_CONFIG_FIFO_USED);
total = ioread32be(priv->regs + FPGA_CONFIG_TOTAL_BYTE_COUNT);
curr = ioread32be(priv->regs + FPGA_CONFIG_CUR_BYTE_COUNT);
dev_err(priv->dev, "Configuration failed, dumping status registers\n");
dev_err(priv->dev, "Control: 0x%.8x\n", control);
dev_err(priv->dev, "Status: 0x%.8x\n", status);
dev_err(priv->dev, "FIFO Size: 0x%.8x\n", size);
dev_err(priv->dev, "FIFO Used: 0x%.8x\n", used);
dev_err(priv->dev, "FIFO Total: 0x%.8x\n", total);
dev_err(priv->dev, "FIFO Curr: 0x%.8x\n", curr);
}
static bool fpga_power_good(struct fpga_dev *priv)
{
u8 val;
val = ioread8(priv->regs + CTL_PWR_STATUS);
if (val & PWR_STATUS_ERROR_MASK)
return false;
return val == PWR_STATUS_GOOD;
}
static void fpga_disable_power_supplies(struct fpga_dev *priv)
{
unsigned long start;
u8 val;
iowrite8(0x0, priv->regs + CTL_PWR_CONTROL);
msleep(500);
start = jiffies;
while (time_before(jiffies, start + HZ)) {
val = ioread8(priv->regs + CTL_PWR_STATUS);
if (!(val & PWR_STATUS_GOOD))
break;
usleep_range(5000, 10000);
}
val = ioread8(priv->regs + CTL_PWR_STATUS);
if (val & PWR_STATUS_GOOD) {
dev_err(priv->dev, "power disable failed: "
"power goods: status 0x%.2x\n", val);
}
if (val & PWR_STATUS_ERROR_MASK) {
dev_err(priv->dev, "power disable failed: "
"alarm bit set: status 0x%.2x\n", val);
}
}
static int fpga_enable_power_supplies(struct fpga_dev *priv)
{
unsigned long start = jiffies;
if (fpga_power_good(priv)) {
dev_dbg(priv->dev, "power was already good\n");
return 0;
}
iowrite8(PWR_CONTROL_ENABLE, priv->regs + CTL_PWR_CONTROL);
while (time_before(jiffies, start + HZ)) {
if (fpga_power_good(priv))
return 0;
usleep_range(5000, 10000);
}
return fpga_power_good(priv) ? 0 : -ETIMEDOUT;
}
static bool fpga_power_enabled(struct fpga_dev *priv)
{
u8 val;
val = ioread8(priv->regs + CTL_PWR_CONTROL);
if (val & PWR_CONTROL_ENABLE)
return true;
return false;
}
static bool fpga_running(struct fpga_dev *priv)
{
if (!fpga_power_good(priv))
return false;
return ioread32be(priv->regs + FPGA_CONFIG_STATUS) & (1 << 18);
}
static int fpga_program_block(struct fpga_dev *priv, void *buf, size_t count)
{
u32 *data = buf;
int size = fpga_fifo_size(priv->regs);
int i, len;
unsigned long timeout;
BUG_ON(count % 4 != 0);
while (count > 0) {
len = min_t(size_t, count, size);
timeout = jiffies + HZ / 4;
for (i = 0; i < len / 4; i++)
fpga_fifo_write(priv->regs, data[i]);
count -= len;
data += len / 4;
while (true) {
if (fpga_fifo_empty(priv->regs)) {
break;
} else {
dev_dbg(priv->dev, "Fifo not empty\n");
cpu_relax();
}
if (fpga_config_error(priv->regs)) {
dev_err(priv->dev, "Error detected\n");
return -EIO;
}
if (time_after(jiffies, timeout)) {
dev_err(priv->dev, "Fifo drain timeout\n");
return -ETIMEDOUT;
}
usleep_range(5000, 10000);
}
}
return 0;
}
static noinline int fpga_program_cpu(struct fpga_dev *priv)
{
int ret;
fpga_programmer_disable(priv);
fpga_set_byte_count(priv->regs, priv->bytes);
dev_dbg(priv->dev, "total byte count %u bytes\n", priv->bytes);
fpga_programmer_enable(priv, false);
dev_dbg(priv->dev, "enabled the controller\n");
ret = fpga_program_block(priv, priv->vb.vaddr, priv->bytes);
if (ret)
goto out_disable_controller;
ret = wait_for_completion_timeout(&priv->completion, 2 * HZ);
if (!ret) {
dev_err(priv->dev, "Timed out waiting for completion\n");
ret = -ETIMEDOUT;
goto out_disable_controller;
}
ret = priv->status;
out_disable_controller:
fpga_programmer_disable(priv);
return ret;
}
static noinline int fpga_program_dma(struct fpga_dev *priv)
{
struct videobuf_dmabuf *vb = &priv->vb;
struct dma_chan *chan = priv->chan;
struct dma_async_tx_descriptor *tx;
size_t num_pages, len, avail = 0;
struct dma_slave_config config;
struct scatterlist *sg;
struct sg_table table;
dma_cookie_t cookie;
int ret, i;
fpga_programmer_disable(priv);
num_pages = DIV_ROUND_UP(priv->bytes, FIFO_MAX_LEN);
ret = sg_alloc_table(&table, num_pages, GFP_KERNEL);
if (ret) {
dev_err(priv->dev, "Unable to allocate dst scatterlist\n");
ret = -ENOMEM;
goto out_return;
}
avail = priv->bytes;
for_each_sg(table.sgl, sg, num_pages, i) {
len = min_t(size_t, avail, FIFO_MAX_LEN);
sg_dma_address(sg) = FIFO_DMA_ADDRESS;
sg_dma_len(sg) = len;
avail -= len;
}
ret = videobuf_dma_map(priv->dev, &priv->vb);
if (ret) {
dev_err(priv->dev, "Unable to map buffer for DMA\n");
goto out_free_table;
}
memset(&config, 0, sizeof(config));
config.direction = DMA_MEM_TO_DEV;
config.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
config.dst_maxburst = fpga_fifo_size(priv->regs) / 2 / 4;
ret = chan->device->device_control(chan, DMA_SLAVE_CONFIG,
(unsigned long)&config);
if (ret) {
dev_err(priv->dev, "DMA slave configuration failed\n");
goto out_dma_unmap;
}
ret = chan->device->device_control(chan, FSLDMA_EXTERNAL_START, 1);
if (ret) {
dev_err(priv->dev, "DMA external control setup failed\n");
goto out_dma_unmap;
}
tx = chan->device->device_prep_dma_sg(chan,
table.sgl, num_pages,
vb->sglist, vb->sglen, 0);
if (!tx) {
dev_err(priv->dev, "Unable to prep DMA transaction\n");
ret = -ENOMEM;
goto out_dma_unmap;
}
cookie = tx->tx_submit(tx);
if (dma_submit_error(cookie)) {
dev_err(priv->dev, "Unable to submit DMA transaction\n");
ret = -ENOMEM;
goto out_dma_unmap;
}
dma_async_issue_pending(chan);
fpga_set_byte_count(priv->regs, priv->bytes);
dev_dbg(priv->dev, "total byte count %u bytes\n", priv->bytes);
fpga_programmer_enable(priv, true);
dev_dbg(priv->dev, "enabled the controller\n");
ret = wait_for_completion_timeout(&priv->completion, 2 * HZ);
if (!ret) {
dev_err(priv->dev, "Timed out waiting for completion\n");
ret = -ETIMEDOUT;
goto out_disable_controller;
}
ret = priv->status;
out_disable_controller:
fpga_programmer_disable(priv);
out_dma_unmap:
videobuf_dma_unmap(priv->dev, vb);
out_free_table:
sg_free_table(&table);
out_return:
return ret;
}
static irqreturn_t fpga_irq(int irq, void *dev_id)
{
struct fpga_dev *priv = dev_id;
priv->status = fpga_config_error(priv->regs) ? -EIO : 0;
dev_dbg(priv->dev, "INTERRUPT status %d\n", priv->status);
fpga_dump_registers(priv);
fpga_programmer_disable(priv);
complete(&priv->completion);
return IRQ_HANDLED;
}
static int fpga_do_stop(struct fpga_dev *priv)
{
u32 val;
ledtrig_fpga_programmed(false);
val = CFG_CTL_ENABLE | CFG_CTL_RESET;
iowrite32be(val, priv->regs + FPGA_CONFIG_CONTROL);
iowrite32be(0x0, priv->regs + FPGA_CONFIG_CONTROL);
return 0;
}
static noinline int fpga_do_program(struct fpga_dev *priv)
{
int ret;
if (priv->bytes != priv->fw_size) {
dev_err(priv->dev, "Incorrect bitfile size: got %zu bytes, "
"should be %zu bytes\n",
priv->bytes, priv->fw_size);
return -EINVAL;
}
if (!fpga_power_enabled(priv)) {
dev_err(priv->dev, "Power not enabled\n");
return -EINVAL;
}
if (!fpga_power_good(priv)) {
dev_err(priv->dev, "Power not good\n");
return -EINVAL;
}
ledtrig_fpga_programmed(false);
ret = fpga_program_dma(priv);
if (ret) {
dev_warn(priv->dev, "Falling back to CPU programming\n");
ret = fpga_program_cpu(priv);
}
if (ret) {
dev_err(priv->dev, "Unable to program FPGA's\n");
return ret;
}
fpga_drop_firmware_data(priv);
dev_dbg(priv->dev, "FPGA programming successful\n");
ledtrig_fpga_programmed(true);
return 0;
}
static int fpga_open(struct inode *inode, struct file *filp)
{
struct fpga_dev *priv = container_of(filp->private_data,
struct fpga_dev, miscdev);
unsigned int nr_pages;
int ret;
ret = mutex_lock_interruptible(&priv->lock);
if (ret)
return ret;
filp->private_data = priv;
kref_get(&priv->ref);
if (filp->f_flags & O_TRUNC)
priv->bytes = 0;
if (priv->vb_allocated)
return 0;
nr_pages = DIV_ROUND_UP(priv->fw_size, PAGE_SIZE);
ret = videobuf_dma_init_kernel(&priv->vb, DMA_TO_DEVICE, nr_pages);
if (ret) {
dev_err(priv->dev, "unable to allocate data buffer\n");
mutex_unlock(&priv->lock);
kref_put(&priv->ref, fpga_dev_remove);
return ret;
}
priv->vb_allocated = true;
return 0;
}
static int fpga_release(struct inode *inode, struct file *filp)
{
struct fpga_dev *priv = filp->private_data;
mutex_unlock(&priv->lock);
kref_put(&priv->ref, fpga_dev_remove);
return 0;
}
static ssize_t fpga_write(struct file *filp, const char __user *buf,
size_t count, loff_t *f_pos)
{
struct fpga_dev *priv = filp->private_data;
if (priv->bytes >= priv->fw_size)
return -ENOSPC;
count = min_t(size_t, priv->fw_size - priv->bytes, count);
if (copy_from_user(priv->vb.vaddr + priv->bytes, buf, count))
return -EFAULT;
priv->bytes += count;
return count;
}
static ssize_t fpga_read(struct file *filp, char __user *buf, size_t count,
loff_t *f_pos)
{
struct fpga_dev *priv = filp->private_data;
count = min_t(size_t, priv->bytes - *f_pos, count);
if (copy_to_user(buf, priv->vb.vaddr + *f_pos, count))
return -EFAULT;
*f_pos += count;
return count;
}
static loff_t fpga_llseek(struct file *filp, loff_t offset, int origin)
{
struct fpga_dev *priv = filp->private_data;
loff_t newpos;
if ((filp->f_flags & O_ACCMODE) != O_RDONLY)
return -EINVAL;
switch (origin) {
case SEEK_SET:
newpos = offset;
break;
case SEEK_CUR:
newpos = filp->f_pos + offset;
break;
case SEEK_END:
newpos = priv->fw_size - offset;
break;
default:
return -EINVAL;
}
if (newpos > priv->fw_size)
return -EINVAL;
filp->f_pos = newpos;
return newpos;
}
static ssize_t pfail_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fpga_dev *priv = dev_get_drvdata(dev);
u8 val;
val = ioread8(priv->regs + CTL_PWR_FAIL);
return snprintf(buf, PAGE_SIZE, "0x%.2x\n", val);
}
static ssize_t pgood_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fpga_dev *priv = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", fpga_power_good(priv));
}
static ssize_t penable_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fpga_dev *priv = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", fpga_power_enabled(priv));
}
static ssize_t penable_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct fpga_dev *priv = dev_get_drvdata(dev);
unsigned long val;
int ret;
if (strict_strtoul(buf, 0, &val))
return -EINVAL;
if (val) {
ret = fpga_enable_power_supplies(priv);
if (ret)
return ret;
} else {
fpga_do_stop(priv);
fpga_disable_power_supplies(priv);
}
return count;
}
static ssize_t program_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fpga_dev *priv = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", fpga_running(priv));
}
static ssize_t program_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct fpga_dev *priv = dev_get_drvdata(dev);
unsigned long val;
int ret;
if (strict_strtoul(buf, 0, &val))
return -EINVAL;
if (mutex_lock_interruptible(&priv->lock))
return -ERESTARTSYS;
ret = val ? fpga_do_program(priv) : fpga_do_stop(priv);
if (ret)
goto out_unlock;
ret = count;
out_unlock:
mutex_unlock(&priv->lock);
return ret;
}
static bool dma_filter(struct dma_chan *chan, void *data)
{
return chan->chan_id == 0 && chan->device->dev_id == 0;
}
static int fpga_of_remove(struct platform_device *op)
{
struct fpga_dev *priv = dev_get_drvdata(&op->dev);
struct device *this_device = priv->miscdev.this_device;
sysfs_remove_group(&this_device->kobj, &fpga_attr_group);
misc_deregister(&priv->miscdev);
free_irq(priv->irq, priv);
irq_dispose_mapping(priv->irq);
fpga_disable_power_supplies(priv);
iounmap(priv->immr);
iounmap(priv->regs);
dma_release_channel(priv->chan);
kref_put(&priv->ref, fpga_dev_remove);
return 0;
}
static int fpga_of_probe(struct platform_device *op)
{
struct device_node *of_node = op->dev.of_node;
struct device *this_device;
struct fpga_dev *priv;
dma_cap_mask_t mask;
u32 ver;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&op->dev, "Unable to allocate private data\n");
ret = -ENOMEM;
goto out_return;
}
priv->miscdev.minor = MISC_DYNAMIC_MINOR;
priv->miscdev.name = drv_name;
priv->miscdev.fops = &fpga_fops;
kref_init(&priv->ref);
dev_set_drvdata(&op->dev, priv);
priv->dev = &op->dev;
mutex_init(&priv->lock);
init_completion(&priv->completion);
videobuf_dma_init(&priv->vb);
dev_set_drvdata(priv->dev, priv);
dma_cap_zero(mask);
dma_cap_set(DMA_MEMCPY, mask);
dma_cap_set(DMA_SLAVE, mask);
dma_cap_set(DMA_SG, mask);
priv->chan = dma_request_channel(mask, dma_filter, NULL);
if (!priv->chan) {
dev_err(&op->dev, "Unable to acquire DMA channel #0\n");
ret = -ENODEV;
goto out_free_priv;
}
priv->regs = of_iomap(of_node, 0);
if (!priv->regs) {
dev_err(&op->dev, "Unable to ioremap registers\n");
ret = -ENOMEM;
goto out_dma_release_channel;
}
priv->immr = ioremap(get_immrbase(), 0x100000);
if (!priv->immr) {
dev_err(&op->dev, "Unable to ioremap IMMR\n");
ret = -ENOMEM;
goto out_unmap_regs;
}
if ((ioread32be(priv->immr + 0x114) & 0xE00) != 0xE00) {
dev_err(&op->dev, "External DMA control not configured\n");
ret = -ENODEV;
goto out_unmap_immr;
}
ver = ioread8(priv->regs + CTL_CPLD_VERSION);
if (ver != 0x02 && ver != 0x03) {
dev_err(&op->dev, "CTL-CPLD is not version 0x02 or 0x03!\n");
ret = -ENODEV;
goto out_unmap_immr;
}
ver = ioread32be(priv->regs + SYS_REG_VERSION);
priv->fw_size = (ver & (1 << 18)) ? FW_SIZE_EP2S130 : FW_SIZE_EP2S90;
priv->irq = irq_of_parse_and_map(of_node, 0);
if (priv->irq == NO_IRQ) {
dev_err(&op->dev, "Unable to find IRQ line\n");
ret = -ENODEV;
goto out_unmap_immr;
}
ret = request_irq(priv->irq, fpga_irq, IRQF_SHARED, drv_name, priv);
if (ret) {
dev_err(&op->dev, "Unable to request IRQ %d\n", priv->irq);
ret = -ENODEV;
goto out_irq_dispose_mapping;
}
fpga_do_stop(priv);
ret = misc_register(&priv->miscdev);
if (ret) {
dev_err(&op->dev, "Unable to register miscdevice\n");
goto out_free_irq;
}
this_device = priv->miscdev.this_device;
dev_set_drvdata(this_device, priv);
ret = sysfs_create_group(&this_device->kobj, &fpga_attr_group);
if (ret) {
dev_err(&op->dev, "Unable to create sysfs files\n");
goto out_misc_deregister;
}
dev_info(priv->dev, "CARMA FPGA Programmer: %s rev%s with %s FPGAs\n",
(ver & (1 << 17)) ? "Correlator" : "Digitizer",
(ver & (1 << 16)) ? "B" : "A",
(ver & (1 << 18)) ? "EP2S130" : "EP2S90");
return 0;
out_misc_deregister:
misc_deregister(&priv->miscdev);
out_free_irq:
free_irq(priv->irq, priv);
out_irq_dispose_mapping:
irq_dispose_mapping(priv->irq);
out_unmap_immr:
iounmap(priv->immr);
out_unmap_regs:
iounmap(priv->regs);
out_dma_release_channel:
dma_release_channel(priv->chan);
out_free_priv:
kref_put(&priv->ref, fpga_dev_remove);
out_return:
return ret;
}
static int __init fpga_init(void)
{
led_trigger_register_simple("fpga", &ledtrig_fpga);
return platform_driver_register(&fpga_of_driver);
}
static void __exit fpga_exit(void)
{
platform_driver_unregister(&fpga_of_driver);
led_trigger_unregister_simple(ledtrig_fpga);
}
