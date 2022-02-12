void tmc_wait_for_tmcready(struct tmc_drvdata *drvdata)
{
if (coresight_timeout(drvdata->base,
TMC_STS, TMC_STS_TMCREADY_BIT, 1)) {
dev_err(drvdata->dev,
"timeout while waiting for TMC to be Ready\n");
}
}
void tmc_flush_and_stop(struct tmc_drvdata *drvdata)
{
u32 ffcr;
ffcr = readl_relaxed(drvdata->base + TMC_FFCR);
ffcr |= TMC_FFCR_STOP_ON_FLUSH;
writel_relaxed(ffcr, drvdata->base + TMC_FFCR);
ffcr |= BIT(TMC_FFCR_FLUSHMAN_BIT);
writel_relaxed(ffcr, drvdata->base + TMC_FFCR);
if (coresight_timeout(drvdata->base,
TMC_FFCR, TMC_FFCR_FLUSHMAN_BIT, 0)) {
dev_err(drvdata->dev,
"timeout while waiting for completion of Manual Flush\n");
}
tmc_wait_for_tmcready(drvdata);
}
void tmc_enable_hw(struct tmc_drvdata *drvdata)
{
writel_relaxed(TMC_CTL_CAPT_EN, drvdata->base + TMC_CTL);
}
void tmc_disable_hw(struct tmc_drvdata *drvdata)
{
writel_relaxed(0x0, drvdata->base + TMC_CTL);
}
static int tmc_read_prepare(struct tmc_drvdata *drvdata)
{
int ret = 0;
switch (drvdata->config_type) {
case TMC_CONFIG_TYPE_ETB:
case TMC_CONFIG_TYPE_ETF:
ret = tmc_read_prepare_etb(drvdata);
break;
case TMC_CONFIG_TYPE_ETR:
ret = tmc_read_prepare_etr(drvdata);
break;
default:
ret = -EINVAL;
}
if (!ret)
dev_info(drvdata->dev, "TMC read start\n");
return ret;
}
static int tmc_read_unprepare(struct tmc_drvdata *drvdata)
{
int ret = 0;
switch (drvdata->config_type) {
case TMC_CONFIG_TYPE_ETB:
case TMC_CONFIG_TYPE_ETF:
ret = tmc_read_unprepare_etb(drvdata);
break;
case TMC_CONFIG_TYPE_ETR:
ret = tmc_read_unprepare_etr(drvdata);
break;
default:
ret = -EINVAL;
}
if (!ret)
dev_info(drvdata->dev, "TMC read end\n");
return ret;
}
static int tmc_open(struct inode *inode, struct file *file)
{
int ret;
struct tmc_drvdata *drvdata = container_of(file->private_data,
struct tmc_drvdata, miscdev);
ret = tmc_read_prepare(drvdata);
if (ret)
return ret;
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
if (*ppos + len > drvdata->len)
len = drvdata->len - *ppos;
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
__func__, len, (int)(drvdata->len - *ppos));
return len;
}
static int tmc_release(struct inode *inode, struct file *file)
{
int ret;
struct tmc_drvdata *drvdata = container_of(file->private_data,
struct tmc_drvdata, miscdev);
ret = tmc_read_unprepare(drvdata);
if (ret)
return ret;
dev_dbg(drvdata->dev, "%s: released\n", __func__);
return 0;
}
static enum tmc_mem_intf_width tmc_get_memwidth(u32 devid)
{
enum tmc_mem_intf_width memwidth;
switch (BMVAL(devid, 8, 10)) {
case 0x2:
memwidth = TMC_MEM_INTF_WIDTH_32BITS;
break;
case 0x3:
memwidth = TMC_MEM_INTF_WIDTH_64BITS;
break;
case 0x4:
memwidth = TMC_MEM_INTF_WIDTH_128BITS;
break;
case 0x5:
memwidth = TMC_MEM_INTF_WIDTH_256BITS;
break;
default:
memwidth = 0;
}
return memwidth;
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
static int tmc_etr_setup_caps(struct tmc_drvdata *drvdata,
u32 devid, void *dev_caps)
{
u32 dma_mask = 0;
tmc_etr_init_caps(drvdata, (u32)(unsigned long)dev_caps);
if (!(devid & TMC_DEVID_NOSCAT))
tmc_etr_set_cap(drvdata, TMC_ETR_SG);
if (devid & TMC_DEVID_AXIAW_VALID)
dma_mask = ((devid >> TMC_DEVID_AXIAW_SHIFT) &
TMC_DEVID_AXIAW_MASK);
switch (dma_mask) {
case 32:
case 40:
case 44:
case 48:
case 52:
dev_info(drvdata->dev, "Detected dma mask %dbits\n", dma_mask);
break;
default:
dma_mask = 40;
}
return dma_set_mask_and_coherent(drvdata->dev, DMA_BIT_MASK(dma_mask));
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
struct coresight_desc desc = { 0 };
struct device_node *np = adev->dev.of_node;
if (np) {
pdata = of_get_coresight_platform_data(dev, np);
if (IS_ERR(pdata)) {
ret = PTR_ERR(pdata);
goto out;
}
adev->dev.platform_data = pdata;
}
ret = -ENOMEM;
drvdata = devm_kzalloc(dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
goto out;
drvdata->dev = &adev->dev;
dev_set_drvdata(dev, drvdata);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base)) {
ret = PTR_ERR(base);
goto out;
}
drvdata->base = base;
spin_lock_init(&drvdata->spinlock);
devid = readl_relaxed(drvdata->base + CORESIGHT_DEVID);
drvdata->config_type = BMVAL(devid, 6, 7);
drvdata->memwidth = tmc_get_memwidth(devid);
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
pm_runtime_put(&adev->dev);
desc.pdata = pdata;
desc.dev = dev;
desc.groups = coresight_tmc_groups;
switch (drvdata->config_type) {
case TMC_CONFIG_TYPE_ETB:
desc.type = CORESIGHT_DEV_TYPE_SINK;
desc.subtype.sink_subtype = CORESIGHT_DEV_SUBTYPE_SINK_BUFFER;
desc.ops = &tmc_etb_cs_ops;
break;
case TMC_CONFIG_TYPE_ETR:
desc.type = CORESIGHT_DEV_TYPE_SINK;
desc.subtype.sink_subtype = CORESIGHT_DEV_SUBTYPE_SINK_BUFFER;
desc.ops = &tmc_etr_cs_ops;
ret = tmc_etr_setup_caps(drvdata, devid, id->data);
if (ret)
goto out;
break;
case TMC_CONFIG_TYPE_ETF:
desc.type = CORESIGHT_DEV_TYPE_LINKSINK;
desc.subtype.link_subtype = CORESIGHT_DEV_SUBTYPE_LINK_FIFO;
desc.ops = &tmc_etf_cs_ops;
break;
default:
pr_err("%s: Unsupported TMC config\n", pdata->name);
ret = -EINVAL;
goto out;
}
drvdata->csdev = coresight_register(&desc);
if (IS_ERR(drvdata->csdev)) {
ret = PTR_ERR(drvdata->csdev);
goto out;
}
drvdata->miscdev.name = pdata->name;
drvdata->miscdev.minor = MISC_DYNAMIC_MINOR;
drvdata->miscdev.fops = &tmc_fops;
ret = misc_register(&drvdata->miscdev);
if (ret)
coresight_unregister(drvdata->csdev);
out:
return ret;
}
