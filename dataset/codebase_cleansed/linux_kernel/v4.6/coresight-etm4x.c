static void etm4_os_unlock(void *info)
{
struct etmv4_drvdata *drvdata = (struct etmv4_drvdata *)info;
writel_relaxed(0x0, drvdata->base + TRCOSLAR);
isb();
}
static bool etm4_arch_supported(u8 arch)
{
switch (arch) {
case ETM_ARCH_V4:
break;
default:
return false;
}
return true;
}
static int etm4_cpu_id(struct coresight_device *csdev)
{
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
return drvdata->cpu;
}
static int etm4_trace_id(struct coresight_device *csdev)
{
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
unsigned long flags;
int trace_id = -1;
if (!drvdata->enable)
return drvdata->trcid;
spin_lock_irqsave(&drvdata->spinlock, flags);
CS_UNLOCK(drvdata->base);
trace_id = readl_relaxed(drvdata->base + TRCTRACEIDR);
trace_id &= ETM_TRACEID_MASK;
CS_LOCK(drvdata->base);
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return trace_id;
}
static void etm4_enable_hw(void *info)
{
int i;
struct etmv4_drvdata *drvdata = info;
CS_UNLOCK(drvdata->base);
etm4_os_unlock(drvdata);
writel_relaxed(0, drvdata->base + TRCPRGCTLR);
if (coresight_timeout(drvdata->base, TRCSTATR, TRCSTATR_IDLE_BIT, 1))
dev_err(drvdata->dev,
"timeout observed when probing at offset %#x\n",
TRCSTATR);
writel_relaxed(drvdata->pe_sel, drvdata->base + TRCPROCSELR);
writel_relaxed(drvdata->cfg, drvdata->base + TRCCONFIGR);
writel_relaxed(0x0, drvdata->base + TRCAUXCTLR);
writel_relaxed(drvdata->eventctrl0, drvdata->base + TRCEVENTCTL0R);
writel_relaxed(drvdata->eventctrl1, drvdata->base + TRCEVENTCTL1R);
writel_relaxed(drvdata->stall_ctrl, drvdata->base + TRCSTALLCTLR);
writel_relaxed(drvdata->ts_ctrl, drvdata->base + TRCTSCTLR);
writel_relaxed(drvdata->syncfreq, drvdata->base + TRCSYNCPR);
writel_relaxed(drvdata->ccctlr, drvdata->base + TRCCCCTLR);
writel_relaxed(drvdata->bb_ctrl, drvdata->base + TRCBBCTLR);
writel_relaxed(drvdata->trcid, drvdata->base + TRCTRACEIDR);
writel_relaxed(drvdata->vinst_ctrl, drvdata->base + TRCVICTLR);
writel_relaxed(drvdata->viiectlr, drvdata->base + TRCVIIECTLR);
writel_relaxed(drvdata->vissctlr,
drvdata->base + TRCVISSCTLR);
writel_relaxed(drvdata->vipcssctlr,
drvdata->base + TRCVIPCSSCTLR);
for (i = 0; i < drvdata->nrseqstate - 1; i++)
writel_relaxed(drvdata->seq_ctrl[i],
drvdata->base + TRCSEQEVRn(i));
writel_relaxed(drvdata->seq_rst, drvdata->base + TRCSEQRSTEVR);
writel_relaxed(drvdata->seq_state, drvdata->base + TRCSEQSTR);
writel_relaxed(drvdata->ext_inp, drvdata->base + TRCEXTINSELR);
for (i = 0; i < drvdata->nr_cntr; i++) {
writel_relaxed(drvdata->cntrldvr[i],
drvdata->base + TRCCNTRLDVRn(i));
writel_relaxed(drvdata->cntr_ctrl[i],
drvdata->base + TRCCNTCTLRn(i));
writel_relaxed(drvdata->cntr_val[i],
drvdata->base + TRCCNTVRn(i));
}
for (i = 2; i < drvdata->nr_resource * 2; i++)
writel_relaxed(drvdata->res_ctrl[i],
drvdata->base + TRCRSCTLRn(i));
for (i = 0; i < drvdata->nr_ss_cmp; i++) {
writel_relaxed(drvdata->ss_ctrl[i],
drvdata->base + TRCSSCCRn(i));
writel_relaxed(drvdata->ss_status[i],
drvdata->base + TRCSSCSRn(i));
writel_relaxed(drvdata->ss_pe_cmp[i],
drvdata->base + TRCSSPCICRn(i));
}
for (i = 0; i < drvdata->nr_addr_cmp; i++) {
writeq_relaxed(drvdata->addr_val[i],
drvdata->base + TRCACVRn(i));
writeq_relaxed(drvdata->addr_acc[i],
drvdata->base + TRCACATRn(i));
}
for (i = 0; i < drvdata->numcidc; i++)
writeq_relaxed(drvdata->ctxid_pid[i],
drvdata->base + TRCCIDCVRn(i));
writel_relaxed(drvdata->ctxid_mask0, drvdata->base + TRCCIDCCTLR0);
writel_relaxed(drvdata->ctxid_mask1, drvdata->base + TRCCIDCCTLR1);
for (i = 0; i < drvdata->numvmidc; i++)
writeq_relaxed(drvdata->vmid_val[i],
drvdata->base + TRCVMIDCVRn(i));
writel_relaxed(drvdata->vmid_mask0, drvdata->base + TRCVMIDCCTLR0);
writel_relaxed(drvdata->vmid_mask1, drvdata->base + TRCVMIDCCTLR1);
writel_relaxed(1, drvdata->base + TRCPRGCTLR);
if (coresight_timeout(drvdata->base, TRCSTATR, TRCSTATR_IDLE_BIT, 0))
dev_err(drvdata->dev,
"timeout observed when probing at offset %#x\n",
TRCSTATR);
CS_LOCK(drvdata->base);
dev_dbg(drvdata->dev, "cpu: %d enable smp call done\n", drvdata->cpu);
}
static int etm4_enable(struct coresight_device *csdev,
struct perf_event_attr *attr, u32 mode)
{
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
int ret;
spin_lock(&drvdata->spinlock);
ret = smp_call_function_single(drvdata->cpu,
etm4_enable_hw, drvdata, 1);
if (ret)
goto err;
drvdata->enable = true;
drvdata->sticky_enable = true;
spin_unlock(&drvdata->spinlock);
dev_info(drvdata->dev, "ETM tracing enabled\n");
return 0;
err:
spin_unlock(&drvdata->spinlock);
return ret;
}
static void etm4_disable_hw(void *info)
{
u32 control;
struct etmv4_drvdata *drvdata = info;
CS_UNLOCK(drvdata->base);
control = readl_relaxed(drvdata->base + TRCPRGCTLR);
control &= ~0x1;
mb();
isb();
writel_relaxed(control, drvdata->base + TRCPRGCTLR);
CS_LOCK(drvdata->base);
dev_dbg(drvdata->dev, "cpu: %d disable smp call done\n", drvdata->cpu);
}
static void etm4_disable(struct coresight_device *csdev)
{
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
get_online_cpus();
spin_lock(&drvdata->spinlock);
smp_call_function_single(drvdata->cpu, etm4_disable_hw, drvdata, 1);
drvdata->enable = false;
spin_unlock(&drvdata->spinlock);
put_online_cpus();
dev_info(drvdata->dev, "ETM tracing disabled\n");
}
static int etm4_set_mode_exclude(struct etmv4_drvdata *drvdata, bool exclude)
{
u8 idx = drvdata->addr_idx;
if (BMVAL(drvdata->addr_acc[idx], 0, 1) == ETM_INSTR_ADDR) {
if (idx % 2 != 0)
return -EINVAL;
if (drvdata->addr_type[idx] != ETM_ADDR_TYPE_RANGE ||
drvdata->addr_type[idx + 1] != ETM_ADDR_TYPE_RANGE)
return -EINVAL;
if (exclude == true) {
drvdata->viiectlr |= BIT(idx / 2 + 16);
drvdata->viiectlr &= ~BIT(idx / 2);
} else {
drvdata->viiectlr |= BIT(idx / 2);
drvdata->viiectlr &= ~BIT(idx / 2 + 16);
}
}
return 0;
}
static ssize_t nr_pe_cmp_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->nr_pe_cmp;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t nr_addr_cmp_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->nr_addr_cmp;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t nr_cntr_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->nr_cntr;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t nr_ext_inp_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->nr_ext_inp;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t numcidc_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->numcidc;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t numvmidc_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->numvmidc;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t nrseqstate_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->nrseqstate;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t nr_resource_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->nr_resource;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t nr_ss_cmp_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->nr_ss_cmp;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t reset_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int i;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
if (val)
drvdata->mode = 0x0;
drvdata->mode &= ~(ETM_MODE_LOAD | ETM_MODE_STORE);
drvdata->cfg &= ~(BIT(1) | BIT(2));
drvdata->mode &= ~(ETM_MODE_DATA_TRACE_ADDR |
ETM_MODE_DATA_TRACE_VAL);
drvdata->cfg &= ~(BIT(16) | BIT(17));
drvdata->eventctrl0 = 0x0;
drvdata->eventctrl1 = 0x0;
drvdata->ts_ctrl = 0x0;
drvdata->stall_ctrl = 0x0;
if (drvdata->syncpr == false)
drvdata->syncfreq = 0x8;
drvdata->vinst_ctrl |= BIT(0);
if (drvdata->nr_addr_cmp == true) {
drvdata->mode |= ETM_MODE_VIEWINST_STARTSTOP;
drvdata->vinst_ctrl |= BIT(9);
}
drvdata->viiectlr = 0x0;
drvdata->vissctlr = 0x0;
for (i = 0; i < drvdata->nrseqstate-1; i++)
drvdata->seq_ctrl[i] = 0x0;
drvdata->seq_rst = 0x0;
drvdata->seq_state = 0x0;
drvdata->ext_inp = 0x0;
drvdata->cntr_idx = 0x0;
for (i = 0; i < drvdata->nr_cntr; i++) {
drvdata->cntrldvr[i] = 0x0;
drvdata->cntr_ctrl[i] = 0x0;
drvdata->cntr_val[i] = 0x0;
}
drvdata->res_idx = 0x2;
for (i = 2; i < drvdata->nr_resource * 2; i++)
drvdata->res_ctrl[i] = 0x0;
for (i = 0; i < drvdata->nr_ss_cmp; i++) {
drvdata->ss_ctrl[i] = 0x0;
drvdata->ss_pe_cmp[i] = 0x0;
}
drvdata->addr_idx = 0x0;
for (i = 0; i < drvdata->nr_addr_cmp * 2; i++) {
drvdata->addr_val[i] = 0x0;
drvdata->addr_acc[i] = 0x0;
drvdata->addr_type[i] = ETM_ADDR_TYPE_NONE;
}
drvdata->ctxid_idx = 0x0;
for (i = 0; i < drvdata->numcidc; i++) {
drvdata->ctxid_pid[i] = 0x0;
drvdata->ctxid_vpid[i] = 0x0;
}
drvdata->ctxid_mask0 = 0x0;
drvdata->ctxid_mask1 = 0x0;
drvdata->vmid_idx = 0x0;
for (i = 0; i < drvdata->numvmidc; i++)
drvdata->vmid_val[i] = 0x0;
drvdata->vmid_mask0 = 0x0;
drvdata->vmid_mask1 = 0x0;
drvdata->trcid = drvdata->cpu + 1;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t mode_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->mode;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t mode_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val, mode;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->mode = val & ETMv4_MODE_ALL;
if (drvdata->mode & ETM_MODE_EXCLUDE)
etm4_set_mode_exclude(drvdata, true);
else
etm4_set_mode_exclude(drvdata, false);
if (drvdata->instrp0 == true) {
drvdata->cfg &= ~(BIT(1) | BIT(2));
if (drvdata->mode & ETM_MODE_LOAD)
drvdata->cfg |= BIT(1);
if (drvdata->mode & ETM_MODE_STORE)
drvdata->cfg |= BIT(2);
if (drvdata->mode & ETM_MODE_LOAD_STORE)
drvdata->cfg |= BIT(1) | BIT(2);
}
if ((drvdata->mode & ETM_MODE_BB) && (drvdata->trcbb == true))
drvdata->cfg |= BIT(3);
else
drvdata->cfg &= ~BIT(3);
if ((drvdata->mode & ETMv4_MODE_CYCACC) &&
(drvdata->trccci == true))
drvdata->cfg |= BIT(4);
else
drvdata->cfg &= ~BIT(4);
if ((drvdata->mode & ETMv4_MODE_CTXID) && (drvdata->ctxid_size))
drvdata->cfg |= BIT(6);
else
drvdata->cfg &= ~BIT(6);
if ((drvdata->mode & ETM_MODE_VMID) && (drvdata->vmid_size))
drvdata->cfg |= BIT(7);
else
drvdata->cfg &= ~BIT(7);
mode = ETM_MODE_COND(drvdata->mode);
if (drvdata->trccond == true) {
drvdata->cfg &= ~(BIT(8) | BIT(9) | BIT(10));
drvdata->cfg |= mode << 8;
}
if ((drvdata->mode & ETMv4_MODE_TIMESTAMP) && (drvdata->ts_size))
drvdata->cfg |= BIT(11);
else
drvdata->cfg &= ~BIT(11);
if ((drvdata->mode & ETM_MODE_RETURNSTACK) &&
(drvdata->retstack == true))
drvdata->cfg |= BIT(12);
else
drvdata->cfg &= ~BIT(12);
mode = ETM_MODE_QELEM(drvdata->mode);
drvdata->cfg &= ~(BIT(13) | BIT(14));
if ((mode & BIT(0)) && (drvdata->q_support & BIT(0)))
drvdata->cfg |= BIT(13);
if ((mode & BIT(1)) && (drvdata->q_support & BIT(1)))
drvdata->cfg |= BIT(14);
if ((drvdata->mode & ETM_MODE_ATB_TRIGGER) &&
(drvdata->atbtrig == true))
drvdata->eventctrl1 |= BIT(11);
else
drvdata->eventctrl1 &= ~BIT(11);
if ((drvdata->mode & ETM_MODE_LPOVERRIDE) &&
(drvdata->lpoverride == true))
drvdata->eventctrl1 |= BIT(12);
else
drvdata->eventctrl1 &= ~BIT(12);
if (drvdata->mode & ETM_MODE_ISTALL_EN)
drvdata->stall_ctrl |= BIT(8);
else
drvdata->stall_ctrl &= ~BIT(8);
if (drvdata->mode & ETM_MODE_INSTPRIO)
drvdata->stall_ctrl |= BIT(10);
else
drvdata->stall_ctrl &= ~BIT(10);
if ((drvdata->mode & ETM_MODE_NOOVERFLOW) &&
(drvdata->nooverflow == true))
drvdata->stall_ctrl |= BIT(13);
else
drvdata->stall_ctrl &= ~BIT(13);
if (drvdata->mode & ETM_MODE_VIEWINST_STARTSTOP)
drvdata->vinst_ctrl |= BIT(9);
else
drvdata->vinst_ctrl &= ~BIT(9);
if (drvdata->mode & ETM_MODE_TRACE_RESET)
drvdata->vinst_ctrl |= BIT(10);
else
drvdata->vinst_ctrl &= ~BIT(10);
if ((drvdata->mode & ETM_MODE_TRACE_ERR) &&
(drvdata->trc_error == true))
drvdata->vinst_ctrl |= BIT(11);
else
drvdata->vinst_ctrl &= ~BIT(11);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t pe_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->pe_sel;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t pe_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
if (val > drvdata->nr_pe) {
spin_unlock(&drvdata->spinlock);
return -EINVAL;
}
drvdata->pe_sel = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t event_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->eventctrl0;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
switch (drvdata->nr_event) {
case 0x0:
drvdata->eventctrl0 = val & 0xFF;
break;
case 0x1:
drvdata->eventctrl0 = val & 0xFFFF;
break;
case 0x2:
drvdata->eventctrl0 = val & 0xFFFFFF;
break;
case 0x3:
drvdata->eventctrl0 = val;
break;
default:
break;
}
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t event_instren_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = BMVAL(drvdata->eventctrl1, 0, 3);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t event_instren_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->eventctrl1 &= ~(BIT(0) | BIT(1) | BIT(2) | BIT(3));
switch (drvdata->nr_event) {
case 0x0:
drvdata->eventctrl1 |= val & BIT(1);
break;
case 0x1:
drvdata->eventctrl1 |= val & (BIT(0) | BIT(1));
break;
case 0x2:
drvdata->eventctrl1 |= val & (BIT(0) | BIT(1) | BIT(2));
break;
case 0x3:
drvdata->eventctrl1 |= val & 0xF;
break;
default:
break;
}
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t event_ts_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->ts_ctrl;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t event_ts_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (!drvdata->ts_size)
return -EINVAL;
drvdata->ts_ctrl = val & ETMv4_EVENT_MASK;
return size;
}
static ssize_t syncfreq_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->syncfreq;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t syncfreq_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (drvdata->syncpr == true)
return -EINVAL;
drvdata->syncfreq = val & ETMv4_SYNC_MASK;
return size;
}
static ssize_t cyc_threshold_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->ccctlr;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t cyc_threshold_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val < drvdata->ccitmin)
return -EINVAL;
drvdata->ccctlr = val & ETM_CYC_THRESHOLD_MASK;
return size;
}
static ssize_t bb_ctrl_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->bb_ctrl;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t bb_ctrl_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (drvdata->trcbb == false)
return -EINVAL;
if (!drvdata->nr_addr_cmp)
return -EINVAL;
if (BMVAL(val, 0, 7) > drvdata->nr_addr_cmp)
return -EINVAL;
drvdata->bb_ctrl = val;
return size;
}
static ssize_t event_vinst_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->vinst_ctrl & ETMv4_EVENT_MASK;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t event_vinst_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
val &= ETMv4_EVENT_MASK;
drvdata->vinst_ctrl &= ~ETMv4_EVENT_MASK;
drvdata->vinst_ctrl |= val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t s_exlevel_vinst_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = BMVAL(drvdata->vinst_ctrl, 16, 19);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t s_exlevel_vinst_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->vinst_ctrl &= ~(BIT(16) | BIT(17) | BIT(19));
val &= drvdata->s_ex_level;
drvdata->vinst_ctrl |= (val << 16);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t ns_exlevel_vinst_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = BMVAL(drvdata->vinst_ctrl, 20, 23);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t ns_exlevel_vinst_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->vinst_ctrl &= ~(BIT(20) | BIT(21) | BIT(22));
val &= drvdata->ns_ex_level;
drvdata->vinst_ctrl |= (val << 20);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->addr_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t addr_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->nr_addr_cmp * 2)
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->addr_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_instdatatype_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
ssize_t len;
u8 val, idx;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
val = BMVAL(drvdata->addr_acc[idx], 0, 1);
len = scnprintf(buf, PAGE_SIZE, "%s\n",
val == ETM_INSTR_ADDR ? "instr" :
(val == ETM_DATA_LOAD_ADDR ? "data_load" :
(val == ETM_DATA_STORE_ADDR ? "data_store" :
"data_load_store")));
spin_unlock(&drvdata->spinlock);
return len;
}
static ssize_t addr_instdatatype_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
char str[20] = "";
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (strlen(buf) >= 20)
return -EINVAL;
if (sscanf(buf, "%s", str) != 1)
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
if (!strcmp(str, "instr"))
drvdata->addr_acc[idx] &= ~(BIT(0) | BIT(1));
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_single_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
idx = drvdata->addr_idx;
spin_lock(&drvdata->spinlock);
if (!(drvdata->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
drvdata->addr_type[idx] == ETM_ADDR_TYPE_SINGLE)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
val = (unsigned long)drvdata->addr_val[idx];
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t addr_single_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
if (!(drvdata->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
drvdata->addr_type[idx] == ETM_ADDR_TYPE_SINGLE)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
drvdata->addr_val[idx] = (u64)val;
drvdata->addr_type[idx] = ETM_ADDR_TYPE_SINGLE;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_range_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val1, val2;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
if (idx % 2 != 0) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
if (!((drvdata->addr_type[idx] == ETM_ADDR_TYPE_NONE &&
drvdata->addr_type[idx + 1] == ETM_ADDR_TYPE_NONE) ||
(drvdata->addr_type[idx] == ETM_ADDR_TYPE_RANGE &&
drvdata->addr_type[idx + 1] == ETM_ADDR_TYPE_RANGE))) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
val1 = (unsigned long)drvdata->addr_val[idx];
val2 = (unsigned long)drvdata->addr_val[idx + 1];
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx %#lx\n", val1, val2);
}
static ssize_t addr_range_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val1, val2;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (sscanf(buf, "%lx %lx", &val1, &val2) != 2)
return -EINVAL;
if (val1 > val2)
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
if (idx % 2 != 0) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
if (!((drvdata->addr_type[idx] == ETM_ADDR_TYPE_NONE &&
drvdata->addr_type[idx + 1] == ETM_ADDR_TYPE_NONE) ||
(drvdata->addr_type[idx] == ETM_ADDR_TYPE_RANGE &&
drvdata->addr_type[idx + 1] == ETM_ADDR_TYPE_RANGE))) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
drvdata->addr_val[idx] = (u64)val1;
drvdata->addr_type[idx] = ETM_ADDR_TYPE_RANGE;
drvdata->addr_val[idx + 1] = (u64)val2;
drvdata->addr_type[idx + 1] = ETM_ADDR_TYPE_RANGE;
if (drvdata->mode & ETM_MODE_EXCLUDE)
etm4_set_mode_exclude(drvdata, true);
else
etm4_set_mode_exclude(drvdata, false);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_start_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
if (!(drvdata->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
drvdata->addr_type[idx] == ETM_ADDR_TYPE_START)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
val = (unsigned long)drvdata->addr_val[idx];
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t addr_start_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
if (!drvdata->nr_addr_cmp) {
spin_unlock(&drvdata->spinlock);
return -EINVAL;
}
if (!(drvdata->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
drvdata->addr_type[idx] == ETM_ADDR_TYPE_START)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
drvdata->addr_val[idx] = (u64)val;
drvdata->addr_type[idx] = ETM_ADDR_TYPE_START;
drvdata->vissctlr |= BIT(idx);
drvdata->vinst_ctrl |= BIT(9);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_stop_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
if (!(drvdata->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
drvdata->addr_type[idx] == ETM_ADDR_TYPE_STOP)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
val = (unsigned long)drvdata->addr_val[idx];
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t addr_stop_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
if (!drvdata->nr_addr_cmp) {
spin_unlock(&drvdata->spinlock);
return -EINVAL;
}
if (!(drvdata->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
drvdata->addr_type[idx] == ETM_ADDR_TYPE_STOP)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
drvdata->addr_val[idx] = (u64)val;
drvdata->addr_type[idx] = ETM_ADDR_TYPE_STOP;
drvdata->vissctlr |= BIT(idx + 16);
drvdata->vinst_ctrl |= BIT(9);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_ctxtype_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
ssize_t len;
u8 idx, val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
val = BMVAL(drvdata->addr_acc[idx], 2, 3);
len = scnprintf(buf, PAGE_SIZE, "%s\n", val == ETM_CTX_NONE ? "none" :
(val == ETM_CTX_CTXID ? "ctxid" :
(val == ETM_CTX_VMID ? "vmid" : "all")));
spin_unlock(&drvdata->spinlock);
return len;
}
static ssize_t addr_ctxtype_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
char str[10] = "";
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (strlen(buf) >= 10)
return -EINVAL;
if (sscanf(buf, "%s", str) != 1)
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
if (!strcmp(str, "none"))
drvdata->addr_acc[idx] &= ~(BIT(2) | BIT(3));
else if (!strcmp(str, "ctxid")) {
if (drvdata->numcidc) {
drvdata->addr_acc[idx] |= BIT(2);
drvdata->addr_acc[idx] &= ~BIT(3);
}
} else if (!strcmp(str, "vmid")) {
if (drvdata->numvmidc) {
drvdata->addr_acc[idx] &= ~BIT(2);
drvdata->addr_acc[idx] |= BIT(3);
}
} else if (!strcmp(str, "all")) {
if (drvdata->numcidc)
drvdata->addr_acc[idx] |= BIT(2);
if (drvdata->numvmidc)
drvdata->addr_acc[idx] |= BIT(3);
}
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_context_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
val = BMVAL(drvdata->addr_acc[idx], 4, 6);
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t addr_context_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if ((drvdata->numcidc <= 1) && (drvdata->numvmidc <= 1))
return -EINVAL;
if (val >= (drvdata->numcidc >= drvdata->numvmidc ?
drvdata->numcidc : drvdata->numvmidc))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->addr_idx;
drvdata->addr_acc[idx] &= ~(BIT(4) | BIT(5) | BIT(6));
drvdata->addr_acc[idx] |= (val << 4);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t seq_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->seq_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t seq_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->nrseqstate - 1)
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->seq_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t seq_state_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->seq_state;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t seq_state_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->nrseqstate)
return -EINVAL;
drvdata->seq_state = val;
return size;
}
static ssize_t seq_event_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->seq_idx;
val = drvdata->seq_ctrl[idx];
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t seq_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->seq_idx;
drvdata->seq_ctrl[idx] = val & 0xFF;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t seq_reset_event_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->seq_rst;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t seq_reset_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (!(drvdata->nrseqstate))
return -EINVAL;
drvdata->seq_rst = val & ETMv4_EVENT_MASK;
return size;
}
static ssize_t cntr_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->cntr_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t cntr_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->nr_cntr)
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->cntr_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t cntrldvr_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->cntr_idx;
val = drvdata->cntrldvr[idx];
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t cntrldvr_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val > ETM_CNTR_MAX_VAL)
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->cntr_idx;
drvdata->cntrldvr[idx] = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t cntr_val_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->cntr_idx;
val = drvdata->cntr_val[idx];
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t cntr_val_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val > ETM_CNTR_MAX_VAL)
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->cntr_idx;
drvdata->cntr_val[idx] = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t cntr_ctrl_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->cntr_idx;
val = drvdata->cntr_ctrl[idx];
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t cntr_ctrl_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->cntr_idx;
drvdata->cntr_ctrl[idx] = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t res_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->res_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t res_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val < 2 || val >= drvdata->nr_resource * 2)
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->res_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t res_ctrl_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->res_idx;
val = drvdata->res_ctrl[idx];
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t res_ctrl_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = drvdata->res_idx;
if (idx % 2 != 0)
val &= ~BIT(21);
drvdata->res_ctrl[idx] = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t ctxid_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->ctxid_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t ctxid_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->numcidc)
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->ctxid_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t ctxid_pid_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
idx = drvdata->ctxid_idx;
val = (unsigned long)drvdata->ctxid_vpid[idx];
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t ctxid_pid_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long vpid, pid;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (!drvdata->ctxid_size || !drvdata->numcidc)
return -EINVAL;
if (kstrtoul(buf, 16, &vpid))
return -EINVAL;
pid = coresight_vpid_to_pid(vpid);
spin_lock(&drvdata->spinlock);
idx = drvdata->ctxid_idx;
drvdata->ctxid_pid[idx] = (u64)pid;
drvdata->ctxid_vpid[idx] = (u64)vpid;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t ctxid_masks_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val1, val2;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
val1 = drvdata->ctxid_mask0;
val2 = drvdata->ctxid_mask1;
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx %#lx\n", val1, val2);
}
static ssize_t ctxid_masks_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 i, j, maskbyte;
unsigned long val1, val2, mask;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (!drvdata->ctxid_size || !drvdata->numcidc)
return -EINVAL;
if (sscanf(buf, "%lx %lx", &val1, &val2) != 2)
return -EINVAL;
spin_lock(&drvdata->spinlock);
switch (drvdata->numcidc) {
case 0x1:
drvdata->ctxid_mask0 = val1 & 0xFF;
break;
case 0x2:
drvdata->ctxid_mask0 = val1 & 0xFFFF;
break;
case 0x3:
drvdata->ctxid_mask0 = val1 & 0xFFFFFF;
break;
case 0x4:
drvdata->ctxid_mask0 = val1;
break;
case 0x5:
drvdata->ctxid_mask0 = val1;
drvdata->ctxid_mask1 = val2 & 0xFF;
break;
case 0x6:
drvdata->ctxid_mask0 = val1;
drvdata->ctxid_mask1 = val2 & 0xFFFF;
break;
case 0x7:
drvdata->ctxid_mask0 = val1;
drvdata->ctxid_mask1 = val2 & 0xFFFFFF;
break;
case 0x8:
drvdata->ctxid_mask0 = val1;
drvdata->ctxid_mask1 = val2;
break;
default:
break;
}
mask = drvdata->ctxid_mask0;
for (i = 0; i < drvdata->numcidc; i++) {
maskbyte = mask & ETMv4_EVENT_MASK;
for (j = 0; j < 8; j++) {
if (maskbyte & 1)
drvdata->ctxid_pid[i] &= ~(0xFF << (j * 8));
maskbyte >>= 1;
}
if (i == 3)
mask = drvdata->ctxid_mask1;
else
mask >>= 0x8;
}
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t vmid_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->vmid_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t vmid_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->numvmidc)
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->vmid_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t vmid_val_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = (unsigned long)drvdata->vmid_val[drvdata->vmid_idx];
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t vmid_val_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (!drvdata->vmid_size || !drvdata->numvmidc)
return -EINVAL;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
drvdata->vmid_val[drvdata->vmid_idx] = (u64)val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t vmid_masks_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val1, val2;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
spin_lock(&drvdata->spinlock);
val1 = drvdata->vmid_mask0;
val2 = drvdata->vmid_mask1;
spin_unlock(&drvdata->spinlock);
return scnprintf(buf, PAGE_SIZE, "%#lx %#lx\n", val1, val2);
}
static ssize_t vmid_masks_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 i, j, maskbyte;
unsigned long val1, val2, mask;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
if (!drvdata->vmid_size || !drvdata->numvmidc)
return -EINVAL;
if (sscanf(buf, "%lx %lx", &val1, &val2) != 2)
return -EINVAL;
spin_lock(&drvdata->spinlock);
switch (drvdata->numvmidc) {
case 0x1:
drvdata->vmid_mask0 = val1 & 0xFF;
break;
case 0x2:
drvdata->vmid_mask0 = val1 & 0xFFFF;
break;
case 0x3:
drvdata->vmid_mask0 = val1 & 0xFFFFFF;
break;
case 0x4:
drvdata->vmid_mask0 = val1;
break;
case 0x5:
drvdata->vmid_mask0 = val1;
drvdata->vmid_mask1 = val2 & 0xFF;
break;
case 0x6:
drvdata->vmid_mask0 = val1;
drvdata->vmid_mask1 = val2 & 0xFFFF;
break;
case 0x7:
drvdata->vmid_mask0 = val1;
drvdata->vmid_mask1 = val2 & 0xFFFFFF;
break;
case 0x8:
drvdata->vmid_mask0 = val1;
drvdata->vmid_mask1 = val2;
break;
default:
break;
}
mask = drvdata->vmid_mask0;
for (i = 0; i < drvdata->numvmidc; i++) {
maskbyte = mask & ETMv4_EVENT_MASK;
for (j = 0; j < 8; j++) {
if (maskbyte & 1)
drvdata->vmid_val[i] &= ~(0xFF << (j * 8));
maskbyte >>= 1;
}
if (i == 3)
mask = drvdata->vmid_mask1;
else
mask >>= 0x8;
}
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t cpu_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->cpu;
return scnprintf(buf, PAGE_SIZE, "%d\n", val);
}
static void etm4_init_arch_data(void *info)
{
u32 etmidr0;
u32 etmidr1;
u32 etmidr2;
u32 etmidr3;
u32 etmidr4;
u32 etmidr5;
struct etmv4_drvdata *drvdata = info;
CS_UNLOCK(drvdata->base);
etmidr0 = readl_relaxed(drvdata->base + TRCIDR0);
if (BMVAL(etmidr0, 1, 1) && BMVAL(etmidr0, 2, 2))
drvdata->instrp0 = true;
else
drvdata->instrp0 = false;
if (BMVAL(etmidr0, 5, 5))
drvdata->trcbb = true;
else
drvdata->trcbb = false;
if (BMVAL(etmidr0, 6, 6))
drvdata->trccond = true;
else
drvdata->trccond = false;
if (BMVAL(etmidr0, 7, 7))
drvdata->trccci = true;
else
drvdata->trccci = false;
if (BMVAL(etmidr0, 9, 9))
drvdata->retstack = true;
else
drvdata->retstack = false;
drvdata->nr_event = BMVAL(etmidr0, 10, 11);
drvdata->q_support = BMVAL(etmidr0, 15, 16);
drvdata->ts_size = BMVAL(etmidr0, 24, 28);
etmidr1 = readl_relaxed(drvdata->base + TRCIDR1);
drvdata->arch = BMVAL(etmidr1, 4, 11);
etmidr2 = readl_relaxed(drvdata->base + TRCIDR2);
drvdata->ctxid_size = BMVAL(etmidr2, 5, 9);
drvdata->vmid_size = BMVAL(etmidr2, 10, 14);
drvdata->ccsize = BMVAL(etmidr2, 25, 28);
etmidr3 = readl_relaxed(drvdata->base + TRCIDR3);
drvdata->ccitmin = BMVAL(etmidr3, 0, 11);
drvdata->s_ex_level = BMVAL(etmidr3, 16, 19);
drvdata->ns_ex_level = BMVAL(etmidr3, 20, 23);
if (BMVAL(etmidr3, 24, 24))
drvdata->trc_error = true;
else
drvdata->trc_error = false;
if (BMVAL(etmidr3, 25, 25))
drvdata->syncpr = true;
else
drvdata->syncpr = false;
if (BMVAL(etmidr3, 26, 26))
drvdata->stallctl = true;
else
drvdata->stallctl = false;
if (BMVAL(etmidr3, 27, 27))
drvdata->sysstall = true;
else
drvdata->sysstall = false;
drvdata->nr_pe = BMVAL(etmidr3, 28, 30);
if (BMVAL(etmidr3, 31, 31))
drvdata->nooverflow = true;
else
drvdata->nooverflow = false;
etmidr4 = readl_relaxed(drvdata->base + TRCIDR4);
drvdata->nr_addr_cmp = BMVAL(etmidr4, 0, 3);
drvdata->nr_pe_cmp = BMVAL(etmidr4, 12, 15);
drvdata->nr_resource = BMVAL(etmidr4, 16, 19) + 1;
drvdata->nr_ss_cmp = BMVAL(etmidr4, 20, 23);
drvdata->numcidc = BMVAL(etmidr4, 24, 27);
drvdata->numvmidc = BMVAL(etmidr4, 28, 31);
etmidr5 = readl_relaxed(drvdata->base + TRCIDR5);
drvdata->nr_ext_inp = BMVAL(etmidr5, 0, 8);
drvdata->trcid_size = BMVAL(etmidr5, 16, 21);
if (BMVAL(etmidr5, 22, 22))
drvdata->atbtrig = true;
else
drvdata->atbtrig = false;
if (BMVAL(etmidr5, 23, 23))
drvdata->lpoverride = true;
else
drvdata->lpoverride = false;
drvdata->nrseqstate = BMVAL(etmidr5, 25, 27);
drvdata->nr_cntr = BMVAL(etmidr5, 28, 30);
CS_LOCK(drvdata->base);
}
static void etm4_init_default_data(struct etmv4_drvdata *drvdata)
{
int i;
drvdata->pe_sel = 0x0;
drvdata->cfg = (ETMv4_MODE_CTXID | ETM_MODE_VMID |
ETMv4_MODE_TIMESTAMP | ETM_MODE_RETURNSTACK);
drvdata->eventctrl0 = 0x0;
drvdata->eventctrl1 = 0x0;
drvdata->stall_ctrl = 0x0;
drvdata->ts_ctrl = 0x0;
if (drvdata->syncpr == false)
drvdata->syncfreq = 0xC;
drvdata->vinst_ctrl |= BIT(0);
if (drvdata->nr_addr_cmp)
drvdata->vinst_ctrl |= BIT(9);
drvdata->viiectlr = 0x0;
drvdata->vissctlr = 0x0;
for (i = 0; i < drvdata->nrseqstate-1; i++)
drvdata->seq_ctrl[i] = 0x0;
drvdata->seq_rst = 0x0;
drvdata->seq_state = 0x0;
drvdata->ext_inp = 0x0;
for (i = 0; i < drvdata->nr_cntr; i++) {
drvdata->cntrldvr[i] = 0x0;
drvdata->cntr_ctrl[i] = 0x0;
drvdata->cntr_val[i] = 0x0;
}
drvdata->res_idx = 0x2;
for (i = 2; i < drvdata->nr_resource * 2; i++)
drvdata->res_ctrl[i] = 0x0;
for (i = 0; i < drvdata->nr_ss_cmp; i++) {
drvdata->ss_ctrl[i] = 0x0;
drvdata->ss_pe_cmp[i] = 0x0;
}
if (drvdata->nr_addr_cmp >= 1) {
drvdata->addr_val[0] = (unsigned long)_stext;
drvdata->addr_val[1] = (unsigned long)_etext;
drvdata->addr_type[0] = ETM_ADDR_TYPE_RANGE;
drvdata->addr_type[1] = ETM_ADDR_TYPE_RANGE;
}
for (i = 0; i < drvdata->numcidc; i++) {
drvdata->ctxid_pid[i] = 0x0;
drvdata->ctxid_vpid[i] = 0x0;
}
drvdata->ctxid_mask0 = 0x0;
drvdata->ctxid_mask1 = 0x0;
for (i = 0; i < drvdata->numvmidc; i++)
drvdata->vmid_val[i] = 0x0;
drvdata->vmid_mask0 = 0x0;
drvdata->vmid_mask1 = 0x0;
drvdata->trcid = 0x20 + drvdata->cpu;
}
static int etm4_cpu_callback(struct notifier_block *nfb, unsigned long action,
void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
if (!etmdrvdata[cpu])
goto out;
switch (action & (~CPU_TASKS_FROZEN)) {
case CPU_STARTING:
spin_lock(&etmdrvdata[cpu]->spinlock);
if (!etmdrvdata[cpu]->os_unlock) {
etm4_os_unlock(etmdrvdata[cpu]);
etmdrvdata[cpu]->os_unlock = true;
}
if (etmdrvdata[cpu]->enable)
etm4_enable_hw(etmdrvdata[cpu]);
spin_unlock(&etmdrvdata[cpu]->spinlock);
break;
case CPU_ONLINE:
if (etmdrvdata[cpu]->boot_enable &&
!etmdrvdata[cpu]->sticky_enable)
coresight_enable(etmdrvdata[cpu]->csdev);
break;
case CPU_DYING:
spin_lock(&etmdrvdata[cpu]->spinlock);
if (etmdrvdata[cpu]->enable)
etm4_disable_hw(etmdrvdata[cpu]);
spin_unlock(&etmdrvdata[cpu]->spinlock);
break;
}
out:
return NOTIFY_OK;
}
static int etm4_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret;
void __iomem *base;
struct device *dev = &adev->dev;
struct coresight_platform_data *pdata = NULL;
struct etmv4_drvdata *drvdata;
struct resource *res = &adev->res;
struct coresight_desc *desc;
struct device_node *np = adev->dev.of_node;
desc = devm_kzalloc(dev, sizeof(*desc), GFP_KERNEL);
if (!desc)
return -ENOMEM;
drvdata = devm_kzalloc(dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
if (np) {
pdata = of_get_coresight_platform_data(dev, np);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
adev->dev.platform_data = pdata;
}
drvdata->dev = &adev->dev;
dev_set_drvdata(dev, drvdata);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
drvdata->base = base;
spin_lock_init(&drvdata->spinlock);
drvdata->cpu = pdata ? pdata->cpu : 0;
get_online_cpus();
etmdrvdata[drvdata->cpu] = drvdata;
if (!smp_call_function_single(drvdata->cpu, etm4_os_unlock, drvdata, 1))
drvdata->os_unlock = true;
if (smp_call_function_single(drvdata->cpu,
etm4_init_arch_data, drvdata, 1))
dev_err(dev, "ETM arch init failed\n");
if (!etm4_count++)
register_hotcpu_notifier(&etm4_cpu_notifier);
put_online_cpus();
if (etm4_arch_supported(drvdata->arch) == false) {
ret = -EINVAL;
goto err_arch_supported;
}
etm4_init_default_data(drvdata);
pm_runtime_put(&adev->dev);
desc->type = CORESIGHT_DEV_TYPE_SOURCE;
desc->subtype.source_subtype = CORESIGHT_DEV_SUBTYPE_SOURCE_PROC;
desc->ops = &etm4_cs_ops;
desc->pdata = pdata;
desc->dev = dev;
desc->groups = coresight_etmv4_groups;
drvdata->csdev = coresight_register(desc);
if (IS_ERR(drvdata->csdev)) {
ret = PTR_ERR(drvdata->csdev);
goto err_coresight_register;
}
dev_info(dev, "%s initialized\n", (char *)id->data);
if (boot_enable) {
coresight_enable(drvdata->csdev);
drvdata->boot_enable = true;
}
return 0;
err_arch_supported:
pm_runtime_put(&adev->dev);
err_coresight_register:
if (--etm4_count == 0)
unregister_hotcpu_notifier(&etm4_cpu_notifier);
return ret;
}
