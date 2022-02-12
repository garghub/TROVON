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
return drvdata->trcid;
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
"timeout while waiting for Idle Trace Status\n");
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
writel_relaxed(readl_relaxed(drvdata->base + TRCPDCR) | TRCPDCR_PU,
drvdata->base + TRCPDCR);
writel_relaxed(1, drvdata->base + TRCPRGCTLR);
if (coresight_timeout(drvdata->base, TRCSTATR, TRCSTATR_IDLE_BIT, 0))
dev_err(drvdata->dev,
"timeout while waiting for Idle Trace Status\n");
CS_LOCK(drvdata->base);
dev_dbg(drvdata->dev, "cpu: %d enable smp call done\n", drvdata->cpu);
}
static int etm4_parse_event_config(struct etmv4_drvdata *drvdata,
struct perf_event *event)
{
int ret = 0;
struct etmv4_config *config = &drvdata->config;
struct perf_event_attr *attr = &event->attr;
if (!attr) {
ret = -EINVAL;
goto out;
}
memset(config, 0, sizeof(struct etmv4_config));
if (attr->exclude_kernel)
config->mode = ETM_MODE_EXCL_KERN;
if (attr->exclude_user)
config->mode = ETM_MODE_EXCL_USER;
etm4_set_default_config(config);
ret = etm4_set_event_filters(drvdata, event);
if (ret)
goto out;
if (attr->config & BIT(ETM_OPT_CYCACC))
config->cfg |= ETMv4_MODE_CYCACC;
if (attr->config & BIT(ETM_OPT_TS))
config->cfg |= ETMv4_MODE_TIMESTAMP;
out:
return ret;
}
static int etm4_enable_perf(struct coresight_device *csdev,
struct perf_event *event)
{
int ret = 0;
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
if (WARN_ON_ONCE(drvdata->cpu != smp_processor_id())) {
ret = -EINVAL;
goto out;
}
ret = etm4_parse_event_config(drvdata, event);
if (ret)
goto out;
etm4_enable_hw(drvdata);
out:
return ret;
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
struct perf_event *event, u32 mode)
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
ret = etm4_enable_perf(csdev, event);
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
control = readl_relaxed(drvdata->base + TRCPDCR);
control &= ~TRCPDCR_PU;
writel_relaxed(control, drvdata->base + TRCPDCR);
control = readl_relaxed(drvdata->base + TRCPRGCTLR);
control &= ~0x1;
mb();
isb();
writel_relaxed(control, drvdata->base + TRCPRGCTLR);
CS_LOCK(drvdata->base);
dev_dbg(drvdata->dev, "cpu: %d disable smp call done\n", drvdata->cpu);
}
static int etm4_disable_perf(struct coresight_device *csdev,
struct perf_event *event)
{
u32 control;
struct etm_filters *filters = event->hw.addr_filters;
struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
if (WARN_ON_ONCE(drvdata->cpu != smp_processor_id()))
return -EINVAL;
etm4_disable_hw(drvdata);
control = readl_relaxed(drvdata->base + TRCVICTLR);
filters->ssstatus = (control & BIT(9));
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
static void etm4_disable(struct coresight_device *csdev,
struct perf_event *event)
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
etm4_disable_perf(csdev, event);
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
static void etm4_set_default_config(struct etmv4_config *config)
{
config->eventctrl0 = 0x0;
config->eventctrl1 = 0x0;
config->stall_ctrl = 0x0;
config->syncfreq = 0xC;
config->ts_ctrl = 0x0;
config->vinst_ctrl |= BIT(0);
}
static u64 etm4_get_access_type(struct etmv4_config *config)
{
u64 access_type = 0;
access_type = ETM_EXLEVEL_NS_HYP;
if (config->mode & ETM_MODE_EXCL_KERN)
access_type |= ETM_EXLEVEL_NS_OS;
if (config->mode & ETM_MODE_EXCL_USER)
access_type |= ETM_EXLEVEL_NS_APP;
access_type |= (ETM_EXLEVEL_S_APP |
ETM_EXLEVEL_S_OS |
ETM_EXLEVEL_S_HYP);
return access_type;
}
static void etm4_set_comparator_filter(struct etmv4_config *config,
u64 start, u64 stop, int comparator)
{
u64 access_type = etm4_get_access_type(config);
config->addr_val[comparator] = start;
config->addr_acc[comparator] = access_type;
config->addr_type[comparator] = ETM_ADDR_TYPE_RANGE;
config->addr_val[comparator + 1] = stop;
config->addr_acc[comparator + 1] = access_type;
config->addr_type[comparator + 1] = ETM_ADDR_TYPE_RANGE;
config->viiectlr |= BIT(comparator / 2);
}
static void etm4_set_start_stop_filter(struct etmv4_config *config,
u64 address, int comparator,
enum etm_addr_type type)
{
int shift;
u64 access_type = etm4_get_access_type(config);
config->addr_val[comparator] = address;
config->addr_acc[comparator] = access_type;
config->addr_type[comparator] = type;
shift = (type == ETM_ADDR_TYPE_START ? 0 : 16);
config->vissctlr |= BIT(shift + comparator);
}
static void etm4_set_default_filter(struct etmv4_config *config)
{
u64 start, stop;
start = 0x0;
stop = ~0x0;
etm4_set_comparator_filter(config, start, stop,
ETM_DEFAULT_ADDR_COMP);
config->vinst_ctrl |= BIT(9);
config->vissctlr = 0x0;
}
static void etm4_set_default(struct etmv4_config *config)
{
if (WARN_ON_ONCE(!config))
return;
etm4_set_default_config(config);
etm4_set_default_filter(config);
}
static int etm4_get_next_comparator(struct etmv4_drvdata *drvdata, u32 type)
{
int nr_comparator, index = 0;
struct etmv4_config *config = &drvdata->config;
nr_comparator = drvdata->nr_addr_cmp * 2;
while (index < nr_comparator) {
switch (type) {
case ETM_ADDR_TYPE_RANGE:
if (config->addr_type[index] == ETM_ADDR_TYPE_NONE &&
config->addr_type[index + 1] == ETM_ADDR_TYPE_NONE)
return index;
index += 2;
break;
case ETM_ADDR_TYPE_START:
case ETM_ADDR_TYPE_STOP:
if (config->addr_type[index] == ETM_ADDR_TYPE_NONE)
return index;
index += 1;
break;
default:
return -EINVAL;
}
}
return -ENOSPC;
}
static int etm4_set_event_filters(struct etmv4_drvdata *drvdata,
struct perf_event *event)
{
int i, comparator, ret = 0;
u64 address;
struct etmv4_config *config = &drvdata->config;
struct etm_filters *filters = event->hw.addr_filters;
if (!filters)
goto default_filter;
perf_event_addr_filters_sync(event);
if (!filters->nr_filters)
goto default_filter;
for (i = 0; i < filters->nr_filters; i++) {
struct etm_filter *filter = &filters->etm_filter[i];
enum etm_addr_type type = filter->type;
comparator = etm4_get_next_comparator(drvdata, type);
if (comparator < 0) {
ret = comparator;
goto out;
}
switch (type) {
case ETM_ADDR_TYPE_RANGE:
etm4_set_comparator_filter(config,
filter->start_addr,
filter->stop_addr,
comparator);
config->vinst_ctrl |= BIT(9);
config->vissctlr = 0x0;
break;
case ETM_ADDR_TYPE_START:
case ETM_ADDR_TYPE_STOP:
address = (type == ETM_ADDR_TYPE_START ?
filter->start_addr :
filter->stop_addr);
etm4_set_start_stop_filter(config, address,
comparator, type);
if (filters->ssstatus)
config->vinst_ctrl |= BIT(9);
config->viiectlr = 0x0;
break;
default:
ret = -EINVAL;
goto out;
}
}
goto out;
default_filter:
etm4_set_default_filter(config);
out:
return ret;
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
static int etm4_online_cpu(unsigned int cpu)
{
if (!etmdrvdata[cpu])
return 0;
if (etmdrvdata[cpu]->boot_enable && !etmdrvdata[cpu]->sticky_enable)
coresight_enable(etmdrvdata[cpu]->csdev);
return 0;
}
static int etm4_starting_cpu(unsigned int cpu)
{
if (!etmdrvdata[cpu])
return 0;
spin_lock(&etmdrvdata[cpu]->spinlock);
if (!etmdrvdata[cpu]->os_unlock) {
etm4_os_unlock(etmdrvdata[cpu]);
etmdrvdata[cpu]->os_unlock = true;
}
if (local_read(&etmdrvdata[cpu]->mode))
etm4_enable_hw(etmdrvdata[cpu]);
spin_unlock(&etmdrvdata[cpu]->spinlock);
return 0;
}
static int etm4_dying_cpu(unsigned int cpu)
{
if (!etmdrvdata[cpu])
return 0;
spin_lock(&etmdrvdata[cpu]->spinlock);
if (local_read(&etmdrvdata[cpu]->mode))
etm4_disable_hw(etmdrvdata[cpu]);
spin_unlock(&etmdrvdata[cpu]->spinlock);
return 0;
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
struct coresight_desc desc = { 0 };
struct device_node *np = adev->dev.of_node;
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
if (!etm4_count++) {
cpuhp_setup_state_nocalls(CPUHP_AP_ARM_CORESIGHT_STARTING,
"arm/coresight4:starting",
etm4_starting_cpu, etm4_dying_cpu);
ret = cpuhp_setup_state_nocalls(CPUHP_AP_ONLINE_DYN,
"arm/coresight4:online",
etm4_online_cpu, NULL);
if (ret < 0)
goto err_arch_supported;
hp_online = ret;
}
put_online_cpus();
if (etm4_arch_supported(drvdata->arch) == false) {
ret = -EINVAL;
goto err_arch_supported;
}
etm4_init_trace_id(drvdata);
etm4_set_default(&drvdata->config);
desc.type = CORESIGHT_DEV_TYPE_SOURCE;
desc.subtype.source_subtype = CORESIGHT_DEV_SUBTYPE_SOURCE_PROC;
desc.ops = &etm4_cs_ops;
desc.pdata = pdata;
desc.dev = dev;
desc.groups = coresight_etmv4_groups;
drvdata->csdev = coresight_register(&desc);
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
if (--etm4_count == 0) {
cpuhp_remove_state_nocalls(CPUHP_AP_ARM_CORESIGHT_STARTING);
if (hp_online)
cpuhp_remove_state_nocalls(hp_online);
}
return ret;
}
