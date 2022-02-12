static void etm4_os_unlock(struct etmv4_drvdata *drvdata)
{
writel_relaxed(0x0, drvdata->base + TRCOSLAR);
drvdata->os_unlock = true;
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
if (!local_read(&drvdata->mode))
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
struct etmv4_config *config = &drvdata->config;
CS_UNLOCK(drvdata->base);
etm4_os_unlock(drvdata);
writel_relaxed(0, drvdata->base + TRCPRGCTLR);
if (coresight_timeout(drvdata->base, TRCSTATR, TRCSTATR_IDLE_BIT, 1))
dev_err(drvdata->dev,
"timeout observed when probing at offset %#x\n",
TRCSTATR);
writel_relaxed(config->pe_sel, drvdata->base + TRCPROCSELR);
writel_relaxed(config->cfg, drvdata->base + TRCCONFIGR);
writel_relaxed(0x0, drvdata->base + TRCAUXCTLR);
writel_relaxed(config->eventctrl0, drvdata->base + TRCEVENTCTL0R);
writel_relaxed(config->eventctrl1, drvdata->base + TRCEVENTCTL1R);
writel_relaxed(config->stall_ctrl, drvdata->base + TRCSTALLCTLR);
writel_relaxed(config->ts_ctrl, drvdata->base + TRCTSCTLR);
writel_relaxed(config->syncfreq, drvdata->base + TRCSYNCPR);
writel_relaxed(config->ccctlr, drvdata->base + TRCCCCTLR);
writel_relaxed(config->bb_ctrl, drvdata->base + TRCBBCTLR);
writel_relaxed(drvdata->trcid, drvdata->base + TRCTRACEIDR);
writel_relaxed(config->vinst_ctrl, drvdata->base + TRCVICTLR);
writel_relaxed(config->viiectlr, drvdata->base + TRCVIIECTLR);
writel_relaxed(config->vissctlr,
drvdata->base + TRCVISSCTLR);
writel_relaxed(config->vipcssctlr,
drvdata->base + TRCVIPCSSCTLR);
for (i = 0; i < drvdata->nrseqstate - 1; i++)
writel_relaxed(config->seq_ctrl[i],
drvdata->base + TRCSEQEVRn(i));
writel_relaxed(config->seq_rst, drvdata->base + TRCSEQRSTEVR);
writel_relaxed(config->seq_state, drvdata->base + TRCSEQSTR);
writel_relaxed(config->ext_inp, drvdata->base + TRCEXTINSELR);
for (i = 0; i < drvdata->nr_cntr; i++) {
writel_relaxed(config->cntrldvr[i],
drvdata->base + TRCCNTRLDVRn(i));
writel_relaxed(config->cntr_ctrl[i],
drvdata->base + TRCCNTCTLRn(i));
writel_relaxed(config->cntr_val[i],
drvdata->base + TRCCNTVRn(i));
}
for (i = 0; i < drvdata->nr_resource * 2; i++)
writel_relaxed(config->res_ctrl[i],
drvdata->base + TRCRSCTLRn(i));
for (i = 0; i < drvdata->nr_ss_cmp; i++) {
writel_relaxed(config->ss_ctrl[i],
drvdata->base + TRCSSCCRn(i));
writel_relaxed(config->ss_status[i],
drvdata->base + TRCSSCSRn(i));
writel_relaxed(config->ss_pe_cmp[i],
drvdata->base + TRCSSPCICRn(i));
}
for (i = 0; i < drvdata->nr_addr_cmp; i++) {
writeq_relaxed(config->addr_val[i],
drvdata->base + TRCACVRn(i));
writeq_relaxed(config->addr_acc[i],
drvdata->base + TRCACATRn(i));
}
for (i = 0; i < drvdata->numcidc; i++)
writeq_relaxed(config->ctxid_pid[i],
drvdata->base + TRCCIDCVRn(i));
writel_relaxed(config->ctxid_mask0, drvdata->base + TRCCIDCCTLR0);
writel_relaxed(config->ctxid_mask1, drvdata->base + TRCCIDCCTLR1);
for (i = 0; i < drvdata->numvmidc; i++)
writeq_relaxed(config->vmid_val[i],
drvdata->base + TRCVMIDCVRn(i));
writel_relaxed(config->vmid_mask0, drvdata->base + TRCVMIDCCTLR0);
writel_relaxed(config->vmid_mask1, drvdata->base + TRCVMIDCCTLR1);
writel_relaxed(1, drvdata->base + TRCPRGCTLR);
if (coresight_timeout(drvdata->base, TRCSTATR, TRCSTATR_IDLE_BIT, 0))
dev_err(drvdata->dev,
"timeout observed when probing at offset %#x\n",
TRCSTATR);
CS_LOCK(drvdata->base);
dev_dbg(drvdata->dev, "cpu: %d enable smp call done\n", drvdata->cpu);
}
static int etm4_parse_event_config(struct etmv4_drvdata *drvdata,
struct perf_event_attr *attr)
{
struct etmv4_config *config = &drvdata->config;
if (!attr)
return -EINVAL;
memset(config, 0, sizeof(struct etmv4_config));
if (attr->exclude_kernel)
config->mode = ETM_MODE_EXCL_KERN;
if (attr->exclude_user)
config->mode = ETM_MODE_EXCL_USER;
etm4_set_default(config);
if (config->mode)
etm4_config_trace_mode(config);
if (attr->config & BIT(ETM_OPT_CYCACC))
config->cfg |= ETMv4_MODE_CYCACC;
if (attr->config & BIT(ETM_OPT_TS))
config->cfg |= ETMv4_MODE_TIMESTAMP;
return 0;
}
static int etm4_enable_perf(struct coresight_device *csdev,
struct perf_event_attr *attr)
{
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
if (WARN_ON_ONCE(drvdata->cpu != smp_processor_id()))
return -EINVAL;
etm4_parse_event_config(drvdata, attr);
etm4_enable_hw(drvdata);
return 0;
}
static int etm4_enable_sysfs(struct coresight_device *csdev)
{
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
int ret;
spin_lock(&drvdata->spinlock);
ret = smp_call_function_single(drvdata->cpu,
etm4_enable_hw, drvdata, 1);
if (ret)
goto err;
drvdata->sticky_enable = true;
spin_unlock(&drvdata->spinlock);
dev_info(drvdata->dev, "ETM tracing enabled\n");
return 0;
err:
spin_unlock(&drvdata->spinlock);
return ret;
}
static int etm4_enable(struct coresight_device *csdev,
struct perf_event_attr *attr, u32 mode)
{
int ret;
u32 val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
val = local_cmpxchg(&drvdata->mode, CS_MODE_DISABLED, mode);
if (val)
return -EBUSY;
switch (mode) {
case CS_MODE_SYSFS:
ret = etm4_enable_sysfs(csdev);
break;
case CS_MODE_PERF:
ret = etm4_enable_perf(csdev, attr);
break;
default:
ret = -EINVAL;
}
if (ret)
local_set(&drvdata->mode, CS_MODE_DISABLED);
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
static int etm4_disable_perf(struct coresight_device *csdev)
{
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
if (WARN_ON_ONCE(drvdata->cpu != smp_processor_id()))
return -EINVAL;
etm4_disable_hw(drvdata);
return 0;
}
static void etm4_disable_sysfs(struct coresight_device *csdev)
{
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
get_online_cpus();
spin_lock(&drvdata->spinlock);
smp_call_function_single(drvdata->cpu, etm4_disable_hw, drvdata, 1);
spin_unlock(&drvdata->spinlock);
put_online_cpus();
dev_info(drvdata->dev, "ETM tracing disabled\n");
}
static void etm4_disable(struct coresight_device *csdev)
{
u32 mode;
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
mode = local_read(&drvdata->mode);
switch (mode) {
case CS_MODE_DISABLED:
break;
case CS_MODE_SYSFS:
etm4_disable_sysfs(csdev);
break;
case CS_MODE_PERF:
etm4_disable_perf(csdev);
break;
}
if (mode)
local_set(&drvdata->mode, CS_MODE_DISABLED);
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
etm4_os_unlock(drvdata);
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
static void etm4_set_default(struct etmv4_config *config)
{
if (WARN_ON_ONCE(!config))
return;
config->eventctrl0 = 0x0;
config->eventctrl1 = 0x0;
config->stall_ctrl = 0x0;
config->syncfreq = 0xC;
config->ts_ctrl = 0x0;
config->vinst_ctrl |= BIT(0);
config->vinst_ctrl |= BIT(9);
config->addr_val[ETM_DEFAULT_ADDR_COMP] = 0x0;
config->addr_acc[ETM_DEFAULT_ADDR_COMP] &= ~(BIT(0) | BIT(1));
config->addr_acc[ETM_DEFAULT_ADDR_COMP] |= ETM_EXLEVEL_NS_HYP;
config->addr_acc[ETM_DEFAULT_ADDR_COMP] |= (ETM_EXLEVEL_S_APP |
ETM_EXLEVEL_S_OS |
ETM_EXLEVEL_S_HYP);
config->addr_type[ETM_DEFAULT_ADDR_COMP] = ETM_ADDR_TYPE_RANGE;
config->addr_val[ETM_DEFAULT_ADDR_COMP + 1] = ~0x0;
config->addr_acc[ETM_DEFAULT_ADDR_COMP + 1] &= ~(BIT(0) | BIT(1));
config->addr_acc[ETM_DEFAULT_ADDR_COMP + 1] =
config->addr_acc[ETM_DEFAULT_ADDR_COMP];
config->addr_type[ETM_DEFAULT_ADDR_COMP + 1] = ETM_ADDR_TYPE_RANGE;
config->viiectlr = BIT(0);
config->vissctlr = 0x0;
}
void etm4_config_trace_mode(struct etmv4_config *config)
{
u32 addr_acc, mode;
mode = config->mode;
mode &= (ETM_MODE_EXCL_KERN | ETM_MODE_EXCL_USER);
WARN_ON_ONCE(mode == (ETM_MODE_EXCL_KERN | ETM_MODE_EXCL_USER));
if (!(mode & ETM_MODE_EXCL_KERN) && !(mode & ETM_MODE_EXCL_USER))
return;
addr_acc = config->addr_acc[ETM_DEFAULT_ADDR_COMP];
addr_acc &= ~(ETM_EXLEVEL_NS_APP | ETM_EXLEVEL_NS_OS);
if (mode & ETM_MODE_EXCL_KERN)
addr_acc |= ETM_EXLEVEL_NS_OS;
else
addr_acc |= ETM_EXLEVEL_NS_APP;
config->addr_acc[ETM_DEFAULT_ADDR_COMP] = addr_acc;
config->addr_acc[ETM_DEFAULT_ADDR_COMP + 1] = addr_acc;
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
if (local_read(&etmdrvdata[cpu]->mode))
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
if (local_read(&etmdrvdata[cpu]->mode))
etm4_disable_hw(etmdrvdata[cpu]);
spin_unlock(&etmdrvdata[cpu]->spinlock);
break;
}
out:
return NOTIFY_OK;
}
static void etm4_init_trace_id(struct etmv4_drvdata *drvdata)
{
drvdata->trcid = coresight_get_trace_id(drvdata->cpu);
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
etm4_init_trace_id(drvdata);
etm4_set_default(&drvdata->config);
desc->type = CORESIGHT_DEV_TYPE_SOURCE;
desc->subtype.source_subtype = CORESIGHT_DEV_SUBTYPE_SOURCE_PROC;
desc->ops = &etm4_cs_ops;
desc->pdata = pdata;
desc->dev = dev;
desc->groups = coresight_etmv4_groups;
drvdata->csdev = coresight_register(desc);
if (IS_ERR(drvdata->csdev)) {
ret = PTR_ERR(drvdata->csdev);
goto err_arch_supported;
}
ret = etm_perf_symlink(drvdata->csdev, true);
if (ret) {
coresight_unregister(drvdata->csdev);
goto err_arch_supported;
}
pm_runtime_put(&adev->dev);
dev_info(dev, "%s initialized\n", (char *)id->data);
if (boot_enable) {
coresight_enable(drvdata->csdev);
drvdata->boot_enable = true;
}
return 0;
err_arch_supported:
if (--etm4_count == 0)
unregister_hotcpu_notifier(&etm4_cpu_notifier);
return ret;
}
