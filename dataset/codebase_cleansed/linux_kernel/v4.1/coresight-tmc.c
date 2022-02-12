static void tmc_wait_for_ready(struct tmc_drvdata *drvdata)
{
if (coresight_timeout(drvdata->base,
TMC_STS, TMC_STS_TRIGGERED_BIT, 1)) {
dev_err(drvdata->dev,
"timeout observed when probing at offset %#x\n",
TMC_STS);
}
}
static void tmc_flush_and_stop(struct tmc_drvdata *drvdata)
{
u32 ffcr;
ffcr = readl_relaxed(drvdata->base + TMC_FFCR);
ffcr |= TMC_FFCR_STOP_ON_FLUSH;
writel_relaxed(ffcr, drvdata->base + TMC_FFCR);
ffcr |= TMC_FFCR_FLUSHMAN;
writel_relaxed(ffcr, drvdata->base + TMC_FFCR);
if (coresight_timeout(drvdata->base,
TMC_FFCR, TMC_FFCR_FLUSHMAN_BIT, 0)) {
dev_err(drvdata->dev,
"timeout observed when probing at offset %#x\n",
TMC_FFCR);
}
tmc_wait_for_ready(drvdata);
}
static void tmc_enable_hw(struct tmc_drvdata *drvdata)
{
writel_relaxed(TMC_CTL_CAPT_EN, drvdata->base + TMC_CTL);
}
static void tmc_disable_hw(struct tmc_drvdata *drvdata)
{
writel_relaxed(0x0, drvdata->base + TMC_CTL);
}
static void tmc_etb_enable_hw(struct tmc_drvdata *drvdata)
{
memset(drvdata->buf, 0, drvdata->size);
CS_UNLOCK(drvdata->base);
writel_relaxed(TMC_MODE_CIRCULAR_BUFFER, drvdata->base + TMC_MODE);
writel_relaxed(TMC_FFCR_EN_FMT | TMC_FFCR_EN_TI |
TMC_FFCR_FON_FLIN | TMC_FFCR_FON_TRIG_EVT |
TMC_FFCR_TRIGON_TRIGIN,
drvdata->base + TMC_FFCR);
writel_relaxed(drvdata->trigger_cntr, drvdata->base + TMC_TRG);
tmc_enable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static void tmc_etr_enable_hw(struct tmc_drvdata *drvdata)
{
u32 axictl;
memset(drvdata->vaddr, 0, drvdata->size);
CS_UNLOCK(drvdata->base);
writel_relaxed(drvdata->size / 4, drvdata->base + TMC_RSZ);
writel_relaxed(TMC_MODE_CIRCULAR_BUFFER, drvdata->base + TMC_MODE);
axictl = readl_relaxed(drvdata->base + TMC_AXICTL);
axictl |= TMC_AXICTL_WR_BURST_LEN;
writel_relaxed(axictl, drvdata->base + TMC_AXICTL);
axictl &= ~TMC_AXICTL_SCT_GAT_MODE;
writel_relaxed(axictl, drvdata->base + TMC_AXICTL);
axictl = (axictl &
~(TMC_AXICTL_PROT_CTL_B0 | TMC_AXICTL_PROT_CTL_B1)) |
TMC_AXICTL_PROT_CTL_B1;
writel_relaxed(axictl, drvdata->base + TMC_AXICTL);
writel_relaxed(drvdata->paddr, drvdata->base + TMC_DBALO);
writel_relaxed(0x0, drvdata->base + TMC_DBAHI);
writel_relaxed(TMC_FFCR_EN_FMT | TMC_FFCR_EN_TI |
TMC_FFCR_FON_FLIN | TMC_FFCR_FON_TRIG_EVT |
TMC_FFCR_TRIGON_TRIGIN,
drvdata->base + TMC_FFCR);
writel_relaxed(drvdata->trigger_cntr, drvdata->base + TMC_TRG);
tmc_enable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static void tmc_etf_enable_hw(struct tmc_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
writel_relaxed(TMC_MODE_HARDWARE_FIFO, drvdata->base + TMC_MODE);
writel_relaxed(TMC_FFCR_EN_FMT | TMC_FFCR_EN_TI,
drvdata->base + TMC_FFCR);
writel_relaxed(0x0, drvdata->base + TMC_BUFWM);
tmc_enable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static int tmc_enable(struct tmc_drvdata *drvdata, enum tmc_mode mode)
{
int ret;
unsigned long flags;
ret = clk_prepare_enable(drvdata->clk);
if (ret)
return ret;
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
spin_unlock_irqrestore(&drvdata->spinlock, flags);
clk_disable_unprepare(drvdata->clk);
return -EBUSY;
}
if (drvdata->config_type == TMC_CONFIG_TYPE_ETB) {
tmc_etb_enable_hw(drvdata);
} else if (drvdata->config_type == TMC_CONFIG_TYPE_ETR) {
tmc_etr_enable_hw(drvdata);
} else {
if (mode == TMC_MODE_CIRCULAR_BUFFER)
tmc_etb_enable_hw(drvdata);
else
tmc_etf_enable_hw(drvdata);
}
drvdata->enable = true;
spin_unlock_irqrestore(&drvdata->spinlock, flags);
dev_info(drvdata->dev, "TMC enabled\n");
return 0;
}
static int tmc_enable_sink(struct coresight_device *csdev)
{
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
return tmc_enable(drvdata, TMC_MODE_CIRCULAR_BUFFER);
}
static int tmc_enable_link(struct coresight_device *csdev, int inport,
int outport)
{
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
return tmc_enable(drvdata, TMC_MODE_HARDWARE_FIFO);
}
static void tmc_etb_dump_hw(struct tmc_drvdata *drvdata)
{
enum tmc_mem_intf_width memwidth;
u8 memwords;
char *bufp;
u32 read_data;
int i;
memwidth = BMVAL(readl_relaxed(drvdata->base + CORESIGHT_DEVID), 8, 10);
if (memwidth == TMC_MEM_INTF_WIDTH_32BITS)
memwords = 1;
else if (memwidth == TMC_MEM_INTF_WIDTH_64BITS)
memwords = 2;
else if (memwidth == TMC_MEM_INTF_WIDTH_128BITS)
memwords = 4;
else
memwords = 8;
bufp = drvdata->buf;
while (1) {
for (i = 0; i < memwords; i++) {
read_data = readl_relaxed(drvdata->base + TMC_RRD);
if (read_data == 0xFFFFFFFF)
return;
memcpy(bufp, &read_data, 4);
bufp += 4;
}
}
}
static void tmc_etb_disable_hw(struct tmc_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
tmc_flush_and_stop(drvdata);
tmc_etb_dump_hw(drvdata);
tmc_disable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static void tmc_etr_dump_hw(struct tmc_drvdata *drvdata)
{
u32 rwp, val;
rwp = readl_relaxed(drvdata->base + TMC_RWP);
val = readl_relaxed(drvdata->base + TMC_STS);
if (val & BIT(0))
drvdata->buf = drvdata->vaddr + rwp - drvdata->paddr;
else
drvdata->buf = drvdata->vaddr;
}
static void tmc_etr_disable_hw(struct tmc_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
tmc_flush_and_stop(drvdata);
tmc_etr_dump_hw(drvdata);
tmc_disable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static void tmc_etf_disable_hw(struct tmc_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
tmc_flush_and_stop(drvdata);
tmc_disable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static void tmc_disable(struct tmc_drvdata *drvdata, enum tmc_mode mode)
{
unsigned long flags;
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading)
goto out;
if (drvdata->config_type == TMC_CONFIG_TYPE_ETB) {
tmc_etb_disable_hw(drvdata);
} else if (drvdata->config_type == TMC_CONFIG_TYPE_ETR) {
tmc_etr_disable_hw(drvdata);
} else {
if (mode == TMC_MODE_CIRCULAR_BUFFER)
tmc_etb_disable_hw(drvdata);
else
tmc_etf_disable_hw(drvdata);
}
out:
drvdata->enable = false;
spin_unlock_irqrestore(&drvdata->spinlock, flags);
clk_disable_unprepare(drvdata->clk);
dev_info(drvdata->dev, "TMC disabled\n");
}
static void tmc_disable_sink(struct coresight_device *csdev)
{
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
tmc_disable(drvdata, TMC_MODE_CIRCULAR_BUFFER);
}
static void tmc_disable_link(struct coresight_device *csdev, int inport,
int outport)
{
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
tmc_disable(drvdata, TMC_MODE_HARDWARE_FIFO);
}
static int tmc_read_prepare(struct tmc_drvdata *drvdata)
{
int ret;
unsigned long flags;
enum tmc_mode mode;
spin_lock_irqsave(&drvdata->spinlock, flags);
if (!drvdata->enable)
goto out;
if (drvdata->config_type == TMC_CONFIG_TYPE_ETB) {
tmc_etb_disable_hw(drvdata);
} else if (drvdata->config_type == TMC_CONFIG_TYPE_ETR) {
tmc_etr_disable_hw(drvdata);
} else {
mode = readl_relaxed(drvdata->base + TMC_MODE);
if (mode == TMC_MODE_CIRCULAR_BUFFER) {
tmc_etb_disable_hw(drvdata);
} else {
ret = -ENODEV;
goto err;
}
}
out:
drvdata->reading = true;
spin_unlock_irqrestore(&drvdata->spinlock, flags);
dev_info(drvdata->dev, "TMC read start\n");
return 0;
err:
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return ret;
}
static void tmc_read_unprepare(struct tmc_drvdata *drvdata)
{
unsigned long flags;
enum tmc_mode mode;
spin_lock_irqsave(&drvdata->spinlock, flags);
if (!drvdata->enable)
goto out;
if (drvdata->config_type == TMC_CONFIG_TYPE_ETB) {
tmc_etb_enable_hw(drvdata);
} else if (drvdata->config_type == TMC_CONFIG_TYPE_ETR) {
tmc_etr_enable_hw(drvdata);
} else {
mode = readl_relaxed(drvdata->base + TMC_MODE);
if (mode == TMC_MODE_CIRCULAR_BUFFER)
tmc_etb_enable_hw(drvdata);
}
out:
drvdata->reading = false;
spin_unlock_irqrestore(&drvdata->spinlock, flags);
dev_info(drvdata->dev, "TMC read end\n");
}
static int tmc_open(struct inode *inode, struct file *file)
{
struct tmc_drvdata *drvdata = container_of(file->private_data,
struct tmc_drvdata, miscdev);
int ret = 0;
if (drvdata->read_count++)
goto out;
ret = tmc_read_prepare(drvdata);
if (ret)
return ret;
out:
nonseekable_open(inode, file);
dev_dbg(drvdata->dev, "%s: successfully opened\n", __func__);
return 0;
}
static ssize_t tmc_read(struct file *file, char __user *data, size_t len,
loff_t *ppos)
{
struct tmc_drvdata *drvdata = container_of(file->private_data,
struct tmc_drvdata, miscdev);
char *bufp = drvdata->buf + *ppos;
if (*ppos + len > drvdata->size)
len = drvdata->size - *ppos;
if (drvdata->config_type == TMC_CONFIG_TYPE_ETR) {
if (bufp == (char *)(drvdata->vaddr + drvdata->size))
bufp = drvdata->vaddr;
else if (bufp > (char *)(drvdata->vaddr + drvdata->size))
bufp -= drvdata->size;
if ((bufp + len) > (char *)(drvdata->vaddr + drvdata->size))
len = (char *)(drvdata->vaddr + drvdata->size) - bufp;
}
if (copy_to_user(data, bufp, len)) {
dev_dbg(drvdata->dev, "%s: copy_to_user failed\n", __func__);
return -EFAULT;
}
*ppos += len;
dev_dbg(drvdata->dev, "%s: %zu bytes copied, %d bytes left\n",
__func__, len, (int)(drvdata->size - *ppos));
return len;
}
static int tmc_release(struct inode *inode, struct file *file)
{
struct tmc_drvdata *drvdata = container_of(file->private_data,
struct tmc_drvdata, miscdev);
if (--drvdata->read_count) {
if (drvdata->read_count < 0) {
dev_err(drvdata->dev, "mismatched close\n");
drvdata->read_count = 0;
}
goto out;
}
tmc_read_unprepare(drvdata);
out:
dev_dbg(drvdata->dev, "%s: released\n", __func__);
return 0;
}
static ssize_t status_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
unsigned long flags;
u32 tmc_rsz, tmc_sts, tmc_rrp, tmc_rwp, tmc_trg;
u32 tmc_ctl, tmc_ffsr, tmc_ffcr, tmc_mode, tmc_pscr;
u32 devid;
struct tmc_drvdata *drvdata = dev_get_drvdata(dev->parent);
ret = clk_prepare_enable(drvdata->clk);
if (ret)
goto out;
spin_lock_irqsave(&drvdata->spinlock, flags);
CS_UNLOCK(drvdata->base);
tmc_rsz = readl_relaxed(drvdata->base + TMC_RSZ);
tmc_sts = readl_relaxed(drvdata->base + TMC_STS);
tmc_rrp = readl_relaxed(drvdata->base + TMC_RRP);
tmc_rwp = readl_relaxed(drvdata->base + TMC_RWP);
tmc_trg = readl_relaxed(drvdata->base + TMC_TRG);
tmc_ctl = readl_relaxed(drvdata->base + TMC_CTL);
tmc_ffsr = readl_relaxed(drvdata->base + TMC_FFSR);
tmc_ffcr = readl_relaxed(drvdata->base + TMC_FFCR);
tmc_mode = readl_relaxed(drvdata->base + TMC_MODE);
tmc_pscr = readl_relaxed(drvdata->base + TMC_PSCR);
devid = readl_relaxed(drvdata->base + CORESIGHT_DEVID);
CS_LOCK(drvdata->base);
spin_unlock_irqrestore(&drvdata->spinlock, flags);
clk_disable_unprepare(drvdata->clk);
return sprintf(buf,
"Depth:\t\t0x%x\n"
"Status:\t\t0x%x\n"
"RAM read ptr:\t0x%x\n"
"RAM wrt ptr:\t0x%x\n"
"Trigger cnt:\t0x%x\n"
"Control:\t0x%x\n"
"Flush status:\t0x%x\n"
"Flush ctrl:\t0x%x\n"
"Mode:\t\t0x%x\n"
"PSRC:\t\t0x%x\n"
"DEVID:\t\t0x%x\n",
tmc_rsz, tmc_sts, tmc_rrp, tmc_rwp, tmc_trg,
tmc_ctl, tmc_ffsr, tmc_ffcr, tmc_mode, tmc_pscr, devid);
out:
return -EINVAL;
}
static ssize_t trigger_cntr_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tmc_drvdata *drvdata = dev_get_drvdata(dev->parent);
unsigned long val = drvdata->trigger_cntr;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t trigger_cntr_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct tmc_drvdata *drvdata = dev_get_drvdata(dev->parent);
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
drvdata->trigger_cntr = val;
return size;
}
static int tmc_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret = 0;
u32 devid;
void __iomem *base;
struct device *dev = &adev->dev;
struct coresight_platform_data *pdata = NULL;
struct tmc_drvdata *drvdata;
struct resource *res = &adev->res;
struct coresight_desc *desc;
struct device_node *np = adev->dev.of_node;
if (np) {
pdata = of_get_coresight_platform_data(dev, np);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
adev->dev.platform_data = pdata;
}
drvdata = devm_kzalloc(dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
drvdata->dev = &adev->dev;
dev_set_drvdata(dev, drvdata);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
drvdata->base = base;
spin_lock_init(&drvdata->spinlock);
drvdata->clk = adev->pclk;
ret = clk_prepare_enable(drvdata->clk);
if (ret)
return ret;
devid = readl_relaxed(drvdata->base + CORESIGHT_DEVID);
drvdata->config_type = BMVAL(devid, 6, 7);
if (drvdata->config_type == TMC_CONFIG_TYPE_ETR) {
if (np)
ret = of_property_read_u32(np,
"arm,buffer-size",
&drvdata->size);
if (ret)
drvdata->size = SZ_1M;
} else {
drvdata->size = readl_relaxed(drvdata->base + TMC_RSZ) * 4;
}
clk_disable_unprepare(drvdata->clk);
if (drvdata->config_type == TMC_CONFIG_TYPE_ETR) {
drvdata->vaddr = dma_alloc_coherent(dev, drvdata->size,
&drvdata->paddr, GFP_KERNEL);
if (!drvdata->vaddr)
return -ENOMEM;
memset(drvdata->vaddr, 0, drvdata->size);
drvdata->buf = drvdata->vaddr;
} else {
drvdata->buf = devm_kzalloc(dev, drvdata->size, GFP_KERNEL);
if (!drvdata->buf)
return -ENOMEM;
}
desc = devm_kzalloc(dev, sizeof(*desc), GFP_KERNEL);
if (!desc) {
ret = -ENOMEM;
goto err_devm_kzalloc;
}
desc->pdata = pdata;
desc->dev = dev;
desc->subtype.sink_subtype = CORESIGHT_DEV_SUBTYPE_SINK_BUFFER;
if (drvdata->config_type == TMC_CONFIG_TYPE_ETB) {
desc->type = CORESIGHT_DEV_TYPE_SINK;
desc->ops = &tmc_etb_cs_ops;
desc->groups = coresight_etb_groups;
} else if (drvdata->config_type == TMC_CONFIG_TYPE_ETR) {
desc->type = CORESIGHT_DEV_TYPE_SINK;
desc->ops = &tmc_etr_cs_ops;
desc->groups = coresight_etr_groups;
} else {
desc->type = CORESIGHT_DEV_TYPE_LINKSINK;
desc->subtype.link_subtype = CORESIGHT_DEV_SUBTYPE_LINK_FIFO;
desc->ops = &tmc_etf_cs_ops;
desc->groups = coresight_etf_groups;
}
drvdata->csdev = coresight_register(desc);
if (IS_ERR(drvdata->csdev)) {
ret = PTR_ERR(drvdata->csdev);
goto err_devm_kzalloc;
}
drvdata->miscdev.name = pdata->name;
drvdata->miscdev.minor = MISC_DYNAMIC_MINOR;
drvdata->miscdev.fops = &tmc_fops;
ret = misc_register(&drvdata->miscdev);
if (ret)
goto err_misc_register;
dev_info(dev, "TMC initialized\n");
return 0;
err_misc_register:
coresight_unregister(drvdata->csdev);
err_devm_kzalloc:
if (drvdata->config_type == TMC_CONFIG_TYPE_ETR)
dma_free_coherent(dev, drvdata->size,
&drvdata->paddr, GFP_KERNEL);
return ret;
}
static int tmc_remove(struct amba_device *adev)
{
struct tmc_drvdata *drvdata = amba_get_drvdata(adev);
misc_deregister(&drvdata->miscdev);
coresight_unregister(drvdata->csdev);
if (drvdata->config_type == TMC_CONFIG_TYPE_ETR)
dma_free_coherent(drvdata->dev, drvdata->size,
&drvdata->paddr, GFP_KERNEL);
return 0;
}
