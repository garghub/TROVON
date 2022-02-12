static void tmc_etr_enable_hw(struct tmc_drvdata *drvdata)
{
u32 axictl, sts;
memset(drvdata->vaddr, 0, drvdata->size);
CS_UNLOCK(drvdata->base);
tmc_wait_for_tmcready(drvdata);
writel_relaxed(drvdata->size / 4, drvdata->base + TMC_RSZ);
writel_relaxed(TMC_MODE_CIRCULAR_BUFFER, drvdata->base + TMC_MODE);
axictl = readl_relaxed(drvdata->base + TMC_AXICTL);
axictl &= ~TMC_AXICTL_CLEAR_MASK;
axictl |= (TMC_AXICTL_PROT_CTL_B1 | TMC_AXICTL_WR_BURST_16);
axictl |= TMC_AXICTL_AXCACHE_OS;
if (tmc_etr_has_cap(drvdata, TMC_ETR_AXI_ARCACHE)) {
axictl &= ~TMC_AXICTL_ARCACHE_MASK;
axictl |= TMC_AXICTL_ARCACHE_OS;
}
writel_relaxed(axictl, drvdata->base + TMC_AXICTL);
tmc_write_dba(drvdata, drvdata->paddr);
if (tmc_etr_has_cap(drvdata, TMC_ETR_SAVE_RESTORE)) {
tmc_write_rrp(drvdata, drvdata->paddr);
tmc_write_rwp(drvdata, drvdata->paddr);
sts = readl_relaxed(drvdata->base + TMC_STS) & ~TMC_STS_FULL;
writel_relaxed(sts, drvdata->base + TMC_STS);
}
writel_relaxed(TMC_FFCR_EN_FMT | TMC_FFCR_EN_TI |
TMC_FFCR_FON_FLIN | TMC_FFCR_FON_TRIG_EVT |
TMC_FFCR_TRIGON_TRIGIN,
drvdata->base + TMC_FFCR);
writel_relaxed(drvdata->trigger_cntr, drvdata->base + TMC_TRG);
tmc_enable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static void tmc_etr_dump_hw(struct tmc_drvdata *drvdata)
{
const u32 *barrier;
u32 val;
u32 *temp;
u64 rwp;
rwp = tmc_read_rwp(drvdata);
val = readl_relaxed(drvdata->base + TMC_STS);
if (val & TMC_STS_FULL) {
drvdata->buf = drvdata->vaddr + rwp - drvdata->paddr;
drvdata->len = drvdata->size;
barrier = barrier_pkt;
temp = (u32 *)drvdata->buf;
while (*barrier) {
*temp = *barrier;
temp++;
barrier++;
}
} else {
drvdata->buf = drvdata->vaddr;
drvdata->len = rwp - drvdata->paddr;
}
}
static void tmc_etr_disable_hw(struct tmc_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
tmc_flush_and_stop(drvdata);
if (drvdata->mode == CS_MODE_SYSFS)
tmc_etr_dump_hw(drvdata);
tmc_disable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static int tmc_enable_etr_sink_sysfs(struct coresight_device *csdev)
{
int ret = 0;
bool used = false;
unsigned long flags;
void __iomem *vaddr = NULL;
dma_addr_t paddr;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
spin_lock_irqsave(&drvdata->spinlock, flags);
if (!drvdata->vaddr) {
spin_unlock_irqrestore(&drvdata->spinlock, flags);
vaddr = dma_alloc_coherent(drvdata->dev, drvdata->size,
&paddr, GFP_KERNEL);
if (!vaddr)
return -ENOMEM;
spin_lock_irqsave(&drvdata->spinlock, flags);
}
if (drvdata->reading) {
ret = -EBUSY;
goto out;
}
if (drvdata->mode == CS_MODE_SYSFS)
goto out;
if (drvdata->buf == NULL) {
used = true;
drvdata->vaddr = vaddr;
drvdata->paddr = paddr;
drvdata->buf = drvdata->vaddr;
}
drvdata->mode = CS_MODE_SYSFS;
tmc_etr_enable_hw(drvdata);
out:
spin_unlock_irqrestore(&drvdata->spinlock, flags);
if (!used && vaddr)
dma_free_coherent(drvdata->dev, drvdata->size, vaddr, paddr);
if (!ret)
dev_info(drvdata->dev, "TMC-ETR enabled\n");
return ret;
}
static int tmc_enable_etr_sink_perf(struct coresight_device *csdev)
{
int ret = 0;
unsigned long flags;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
ret = -EINVAL;
goto out;
}
if (drvdata->mode != CS_MODE_DISABLED) {
ret = -EINVAL;
goto out;
}
drvdata->mode = CS_MODE_PERF;
tmc_etr_enable_hw(drvdata);
out:
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return ret;
}
static int tmc_enable_etr_sink(struct coresight_device *csdev, u32 mode)
{
switch (mode) {
case CS_MODE_SYSFS:
return tmc_enable_etr_sink_sysfs(csdev);
case CS_MODE_PERF:
return tmc_enable_etr_sink_perf(csdev);
}
return -EINVAL;
}
static void tmc_disable_etr_sink(struct coresight_device *csdev)
{
unsigned long flags;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return;
}
if (drvdata->mode != CS_MODE_DISABLED) {
tmc_etr_disable_hw(drvdata);
drvdata->mode = CS_MODE_DISABLED;
}
spin_unlock_irqrestore(&drvdata->spinlock, flags);
dev_info(drvdata->dev, "TMC-ETR disabled\n");
}
int tmc_read_prepare_etr(struct tmc_drvdata *drvdata)
{
int ret = 0;
unsigned long flags;
if (WARN_ON_ONCE(drvdata->config_type != TMC_CONFIG_TYPE_ETR))
return -EINVAL;
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
ret = -EBUSY;
goto out;
}
if (drvdata->mode == CS_MODE_PERF) {
ret = -EINVAL;
goto out;
}
if (drvdata->buf == NULL) {
ret = -EINVAL;
goto out;
}
if (drvdata->mode == CS_MODE_SYSFS)
tmc_etr_disable_hw(drvdata);
drvdata->reading = true;
out:
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return ret;
}
int tmc_read_unprepare_etr(struct tmc_drvdata *drvdata)
{
unsigned long flags;
dma_addr_t paddr;
void __iomem *vaddr = NULL;
if (WARN_ON_ONCE(drvdata->config_type != TMC_CONFIG_TYPE_ETR))
return -EINVAL;
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->mode == CS_MODE_SYSFS) {
tmc_etr_enable_hw(drvdata);
} else {
vaddr = drvdata->vaddr;
paddr = drvdata->paddr;
drvdata->buf = drvdata->vaddr = NULL;
}
drvdata->reading = false;
spin_unlock_irqrestore(&drvdata->spinlock, flags);
if (vaddr)
dma_free_coherent(drvdata->dev, drvdata->size, vaddr, paddr);
return 0;
}
