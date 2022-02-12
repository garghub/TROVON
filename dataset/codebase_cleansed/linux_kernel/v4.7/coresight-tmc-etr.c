void tmc_etr_enable_hw(struct tmc_drvdata *drvdata)
{
u32 axictl;
memset(drvdata->vaddr, 0, drvdata->size);
CS_UNLOCK(drvdata->base);
tmc_wait_for_tmcready(drvdata);
writel_relaxed(drvdata->size / 4, drvdata->base + TMC_RSZ);
writel_relaxed(TMC_MODE_CIRCULAR_BUFFER, drvdata->base + TMC_MODE);
axictl = readl_relaxed(drvdata->base + TMC_AXICTL);
axictl |= TMC_AXICTL_WR_BURST_16;
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
if (local_read(&drvdata->mode) == CS_MODE_SYSFS)
tmc_etr_dump_hw(drvdata);
tmc_disable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static int tmc_enable_etr_sink_sysfs(struct coresight_device *csdev, u32 mode)
{
int ret = 0;
bool used = false;
long val;
unsigned long flags;
void __iomem *vaddr = NULL;
dma_addr_t paddr;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
if (WARN_ON(mode != CS_MODE_SYSFS))
return -EINVAL;
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
val = local_xchg(&drvdata->mode, mode);
if (val == CS_MODE_SYSFS)
goto out;
if (drvdata->buf == NULL) {
used = true;
drvdata->vaddr = vaddr;
drvdata->paddr = paddr;
drvdata->buf = drvdata->vaddr;
}
memset(drvdata->vaddr, 0, drvdata->size);
tmc_etr_enable_hw(drvdata);
out:
spin_unlock_irqrestore(&drvdata->spinlock, flags);
if (!used && vaddr)
dma_free_coherent(drvdata->dev, drvdata->size, vaddr, paddr);
if (!ret)
dev_info(drvdata->dev, "TMC-ETR enabled\n");
return ret;
}
static int tmc_enable_etr_sink_perf(struct coresight_device *csdev, u32 mode)
{
int ret = 0;
long val;
unsigned long flags;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
if (WARN_ON(mode != CS_MODE_PERF))
return -EINVAL;
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
ret = -EINVAL;
goto out;
}
val = local_xchg(&drvdata->mode, mode);
if (val != CS_MODE_DISABLED) {
ret = -EINVAL;
goto out;
}
tmc_etr_enable_hw(drvdata);
out:
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return ret;
}
static int tmc_enable_etr_sink(struct coresight_device *csdev, u32 mode)
{
switch (mode) {
case CS_MODE_SYSFS:
return tmc_enable_etr_sink_sysfs(csdev, mode);
case CS_MODE_PERF:
return tmc_enable_etr_sink_perf(csdev, mode);
}
return -EINVAL;
}
static void tmc_disable_etr_sink(struct coresight_device *csdev)
{
long val;
unsigned long flags;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return;
}
val = local_xchg(&drvdata->mode, CS_MODE_DISABLED);
if (val != CS_MODE_DISABLED)
tmc_etr_disable_hw(drvdata);
spin_unlock_irqrestore(&drvdata->spinlock, flags);
dev_info(drvdata->dev, "TMC-ETR disabled\n");
}
int tmc_read_prepare_etr(struct tmc_drvdata *drvdata)
{
int ret = 0;
long val;
unsigned long flags;
if (WARN_ON_ONCE(drvdata->config_type != TMC_CONFIG_TYPE_ETR))
return -EINVAL;
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
ret = -EBUSY;
goto out;
}
val = local_read(&drvdata->mode);
if (val == CS_MODE_PERF) {
ret = -EINVAL;
goto out;
}
if (drvdata->buf == NULL) {
ret = -EINVAL;
goto out;
}
if (val == CS_MODE_SYSFS)
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
if (local_read(&drvdata->mode) == CS_MODE_SYSFS) {
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
