static void etm_os_unlock(struct etm_drvdata *drvdata)
{
etm_writel(drvdata, 0x0, ETMOSLAR);
drvdata->os_unlock = true;
isb();
}
static void etm_set_pwrdwn(struct etm_drvdata *drvdata)
{
u32 etmcr;
mb();
isb();
etmcr = etm_readl(drvdata, ETMCR);
etmcr |= ETMCR_PWD_DWN;
etm_writel(drvdata, etmcr, ETMCR);
}
static void etm_clr_pwrdwn(struct etm_drvdata *drvdata)
{
u32 etmcr;
etmcr = etm_readl(drvdata, ETMCR);
etmcr &= ~ETMCR_PWD_DWN;
etm_writel(drvdata, etmcr, ETMCR);
mb();
isb();
}
static void etm_set_pwrup(struct etm_drvdata *drvdata)
{
u32 etmpdcr;
etmpdcr = readl_relaxed(drvdata->base + ETMPDCR);
etmpdcr |= ETMPDCR_PWD_UP;
writel_relaxed(etmpdcr, drvdata->base + ETMPDCR);
mb();
isb();
}
static void etm_clr_pwrup(struct etm_drvdata *drvdata)
{
u32 etmpdcr;
mb();
isb();
etmpdcr = readl_relaxed(drvdata->base + ETMPDCR);
etmpdcr &= ~ETMPDCR_PWD_UP;
writel_relaxed(etmpdcr, drvdata->base + ETMPDCR);
}
static int coresight_timeout_etm(struct etm_drvdata *drvdata, u32 offset,
int position, int value)
{
int i;
u32 val;
for (i = TIMEOUT_US; i > 0; i--) {
val = etm_readl(drvdata, offset);
if (value) {
if (val & BIT(position))
return 0;
} else {
if (!(val & BIT(position)))
return 0;
}
if (i - 1)
udelay(1);
}
return -EAGAIN;
}
static void etm_set_prog(struct etm_drvdata *drvdata)
{
u32 etmcr;
etmcr = etm_readl(drvdata, ETMCR);
etmcr |= ETMCR_ETM_PRG;
etm_writel(drvdata, etmcr, ETMCR);
isb();
if (coresight_timeout_etm(drvdata, ETMSR, ETMSR_PROG_BIT, 1)) {
dev_err(drvdata->dev,
"%s: timeout observed when probing at offset %#x\n",
__func__, ETMSR);
}
}
static void etm_clr_prog(struct etm_drvdata *drvdata)
{
u32 etmcr;
etmcr = etm_readl(drvdata, ETMCR);
etmcr &= ~ETMCR_ETM_PRG;
etm_writel(drvdata, etmcr, ETMCR);
isb();
if (coresight_timeout_etm(drvdata, ETMSR, ETMSR_PROG_BIT, 0)) {
dev_err(drvdata->dev,
"%s: timeout observed when probing at offset %#x\n",
__func__, ETMSR);
}
}
void etm_set_default(struct etm_config *config)
{
int i;
if (WARN_ON_ONCE(!config))
return;
config->enable_ctrl1 = BIT(24);
config->enable_ctrl2 = 0x0;
config->enable_event = ETM_HARD_WIRE_RES_A;
config->trigger_event = ETM_DEFAULT_EVENT_VAL;
config->enable_event = ETM_HARD_WIRE_RES_A;
config->seq_12_event = ETM_DEFAULT_EVENT_VAL;
config->seq_21_event = ETM_DEFAULT_EVENT_VAL;
config->seq_23_event = ETM_DEFAULT_EVENT_VAL;
config->seq_31_event = ETM_DEFAULT_EVENT_VAL;
config->seq_32_event = ETM_DEFAULT_EVENT_VAL;
config->seq_13_event = ETM_DEFAULT_EVENT_VAL;
config->timestamp_event = ETM_DEFAULT_EVENT_VAL;
for (i = 0; i < ETM_MAX_CNTR; i++) {
config->cntr_rld_val[i] = 0x0;
config->cntr_event[i] = ETM_DEFAULT_EVENT_VAL;
config->cntr_rld_event[i] = ETM_DEFAULT_EVENT_VAL;
config->cntr_val[i] = 0x0;
}
config->seq_curr_state = 0x0;
config->ctxid_idx = 0x0;
for (i = 0; i < ETM_MAX_CTXID_CMP; i++) {
config->ctxid_pid[i] = 0x0;
config->ctxid_vpid[i] = 0x0;
}
config->ctxid_mask = 0x0;
config->sync_freq = 0x400;
}
void etm_config_trace_mode(struct etm_config *config)
{
u32 flags, mode;
mode = config->mode;
mode &= (ETM_MODE_EXCL_KERN | ETM_MODE_EXCL_USER);
if (mode == (ETM_MODE_EXCL_KERN | ETM_MODE_EXCL_USER))
return;
if (!(mode & ETM_MODE_EXCL_KERN) && !(mode & ETM_MODE_EXCL_USER))
return;
flags = (1 << 0 |
3 << 3 |
0 << 5 |
0 << 7 |
0 << 8);
config->enable_ctrl2 = 0x0;
config->enable_ctrl1 = ETMTECR1_ADDR_COMP_1;
flags |= (0 << 12 | 1 << 10);
if (mode & ETM_MODE_EXCL_USER) {
flags |= (1 << 13 | 0 << 11);
} else {
flags |= (1 << 13 | 1 << 11);
}
config->addr_val[0] = (u32) 0x0;
config->addr_val[1] = (u32) ~0x0;
config->addr_acctype[0] = flags;
config->addr_acctype[1] = flags;
config->addr_type[0] = ETM_ADDR_TYPE_RANGE;
config->addr_type[1] = ETM_ADDR_TYPE_RANGE;
}
static int etm_parse_event_config(struct etm_drvdata *drvdata,
struct perf_event *event)
{
struct etm_config *config = &drvdata->config;
struct perf_event_attr *attr = &event->attr;
if (!attr)
return -EINVAL;
memset(config, 0, sizeof(struct etm_config));
if (attr->exclude_kernel)
config->mode = ETM_MODE_EXCL_KERN;
if (attr->exclude_user)
config->mode = ETM_MODE_EXCL_USER;
etm_set_default(config);
if (config->mode)
etm_config_trace_mode(config);
if (attr->config & ~ETM3X_SUPPORTED_OPTIONS)
return -EINVAL;
config->ctrl = attr->config;
if ((config->ctrl & ETMCR_RETURN_STACK) &&
!(drvdata->etmccer & ETMCCER_RETSTACK))
config->ctrl &= ~ETMCR_RETURN_STACK;
return 0;
}
static void etm_enable_hw(void *info)
{
int i;
u32 etmcr;
struct etm_drvdata *drvdata = info;
struct etm_config *config = &drvdata->config;
CS_UNLOCK(drvdata->base);
etm_clr_pwrdwn(drvdata);
etm_set_pwrup(drvdata);
etm_os_unlock(drvdata);
etm_set_prog(drvdata);
etmcr = etm_readl(drvdata, ETMCR);
etmcr &= ~ETM3X_SUPPORTED_OPTIONS;
etmcr |= drvdata->port_size;
etmcr |= ETMCR_ETM_EN;
etm_writel(drvdata, config->ctrl | etmcr, ETMCR);
etm_writel(drvdata, config->trigger_event, ETMTRIGGER);
etm_writel(drvdata, config->startstop_ctrl, ETMTSSCR);
etm_writel(drvdata, config->enable_event, ETMTEEVR);
etm_writel(drvdata, config->enable_ctrl1, ETMTECR1);
etm_writel(drvdata, config->fifofull_level, ETMFFLR);
for (i = 0; i < drvdata->nr_addr_cmp; i++) {
etm_writel(drvdata, config->addr_val[i], ETMACVRn(i));
etm_writel(drvdata, config->addr_acctype[i], ETMACTRn(i));
}
for (i = 0; i < drvdata->nr_cntr; i++) {
etm_writel(drvdata, config->cntr_rld_val[i], ETMCNTRLDVRn(i));
etm_writel(drvdata, config->cntr_event[i], ETMCNTENRn(i));
etm_writel(drvdata, config->cntr_rld_event[i],
ETMCNTRLDEVRn(i));
etm_writel(drvdata, config->cntr_val[i], ETMCNTVRn(i));
}
etm_writel(drvdata, config->seq_12_event, ETMSQ12EVR);
etm_writel(drvdata, config->seq_21_event, ETMSQ21EVR);
etm_writel(drvdata, config->seq_23_event, ETMSQ23EVR);
etm_writel(drvdata, config->seq_31_event, ETMSQ31EVR);
etm_writel(drvdata, config->seq_32_event, ETMSQ32EVR);
etm_writel(drvdata, config->seq_13_event, ETMSQ13EVR);
etm_writel(drvdata, config->seq_curr_state, ETMSQR);
for (i = 0; i < drvdata->nr_ext_out; i++)
etm_writel(drvdata, ETM_DEFAULT_EVENT_VAL, ETMEXTOUTEVRn(i));
for (i = 0; i < drvdata->nr_ctxid_cmp; i++)
etm_writel(drvdata, config->ctxid_pid[i], ETMCIDCVRn(i));
etm_writel(drvdata, config->ctxid_mask, ETMCIDCMR);
etm_writel(drvdata, config->sync_freq, ETMSYNCFR);
etm_writel(drvdata, 0x0, ETMEXTINSELR);
etm_writel(drvdata, config->timestamp_event, ETMTSEVR);
etm_writel(drvdata, 0x0, ETMAUXCR);
etm_writel(drvdata, drvdata->traceid, ETMTRACEIDR);
etm_writel(drvdata, 0x0, ETMVMIDCVR);
etm_clr_prog(drvdata);
CS_LOCK(drvdata->base);
dev_dbg(drvdata->dev, "cpu: %d enable smp call done\n", drvdata->cpu);
}
static int etm_cpu_id(struct coresight_device *csdev)
{
struct etm_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
return drvdata->cpu;
}
int etm_get_trace_id(struct etm_drvdata *drvdata)
{
unsigned long flags;
int trace_id = -1;
if (!drvdata)
goto out;
if (!local_read(&drvdata->mode))
return drvdata->traceid;
pm_runtime_get_sync(drvdata->dev);
spin_lock_irqsave(&drvdata->spinlock, flags);
CS_UNLOCK(drvdata->base);
trace_id = (etm_readl(drvdata, ETMTRACEIDR) & ETM_TRACEID_MASK);
CS_LOCK(drvdata->base);
spin_unlock_irqrestore(&drvdata->spinlock, flags);
pm_runtime_put(drvdata->dev);
out:
return trace_id;
}
static int etm_trace_id(struct coresight_device *csdev)
{
struct etm_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
return etm_get_trace_id(drvdata);
}
static int etm_enable_perf(struct coresight_device *csdev,
struct perf_event *event)
{
struct etm_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
if (WARN_ON_ONCE(drvdata->cpu != smp_processor_id()))
return -EINVAL;
etm_parse_event_config(drvdata, event);
etm_enable_hw(drvdata);
return 0;
}
static int etm_enable_sysfs(struct coresight_device *csdev)
{
struct etm_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
int ret;
spin_lock(&drvdata->spinlock);
if (cpu_online(drvdata->cpu)) {
ret = smp_call_function_single(drvdata->cpu,
etm_enable_hw, drvdata, 1);
if (ret)
goto err;
}
drvdata->sticky_enable = true;
spin_unlock(&drvdata->spinlock);
dev_info(drvdata->dev, "ETM tracing enabled\n");
return 0;
err:
spin_unlock(&drvdata->spinlock);
return ret;
}
static int etm_enable(struct coresight_device *csdev,
struct perf_event *event, u32 mode)
{
int ret;
u32 val;
struct etm_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
val = local_cmpxchg(&drvdata->mode, CS_MODE_DISABLED, mode);
if (val)
return -EBUSY;
switch (mode) {
case CS_MODE_SYSFS:
ret = etm_enable_sysfs(csdev);
break;
case CS_MODE_PERF:
ret = etm_enable_perf(csdev, event);
break;
default:
ret = -EINVAL;
}
if (ret)
local_set(&drvdata->mode, CS_MODE_DISABLED);
return ret;
}
static void etm_disable_hw(void *info)
{
int i;
struct etm_drvdata *drvdata = info;
struct etm_config *config = &drvdata->config;
CS_UNLOCK(drvdata->base);
etm_set_prog(drvdata);
config->seq_curr_state = (etm_readl(drvdata, ETMSQR) & ETM_SQR_MASK);
for (i = 0; i < drvdata->nr_cntr; i++)
config->cntr_val[i] = etm_readl(drvdata, ETMCNTVRn(i));
etm_set_pwrdwn(drvdata);
CS_LOCK(drvdata->base);
dev_dbg(drvdata->dev, "cpu: %d disable smp call done\n", drvdata->cpu);
}
static void etm_disable_perf(struct coresight_device *csdev)
{
struct etm_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
if (WARN_ON_ONCE(drvdata->cpu != smp_processor_id()))
return;
CS_UNLOCK(drvdata->base);
etm_set_prog(drvdata);
etm_set_pwrdwn(drvdata);
CS_LOCK(drvdata->base);
}
static void etm_disable_sysfs(struct coresight_device *csdev)
{
struct etm_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
cpus_read_lock();
spin_lock(&drvdata->spinlock);
smp_call_function_single(drvdata->cpu, etm_disable_hw, drvdata, 1);
spin_unlock(&drvdata->spinlock);
cpus_read_unlock();
dev_info(drvdata->dev, "ETM tracing disabled\n");
}
static void etm_disable(struct coresight_device *csdev,
struct perf_event *event)
{
u32 mode;
struct etm_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
mode = local_read(&drvdata->mode);
switch (mode) {
case CS_MODE_DISABLED:
break;
case CS_MODE_SYSFS:
etm_disable_sysfs(csdev);
break;
case CS_MODE_PERF:
etm_disable_perf(csdev);
break;
default:
WARN_ON_ONCE(mode);
return;
}
if (mode)
local_set(&drvdata->mode, CS_MODE_DISABLED);
}
static int etm_online_cpu(unsigned int cpu)
{
if (!etmdrvdata[cpu])
return 0;
if (etmdrvdata[cpu]->boot_enable && !etmdrvdata[cpu]->sticky_enable)
coresight_enable(etmdrvdata[cpu]->csdev);
return 0;
}
static int etm_starting_cpu(unsigned int cpu)
{
if (!etmdrvdata[cpu])
return 0;
spin_lock(&etmdrvdata[cpu]->spinlock);
if (!etmdrvdata[cpu]->os_unlock) {
etm_os_unlock(etmdrvdata[cpu]);
etmdrvdata[cpu]->os_unlock = true;
}
if (local_read(&etmdrvdata[cpu]->mode))
etm_enable_hw(etmdrvdata[cpu]);
spin_unlock(&etmdrvdata[cpu]->spinlock);
return 0;
}
static int etm_dying_cpu(unsigned int cpu)
{
if (!etmdrvdata[cpu])
return 0;
spin_lock(&etmdrvdata[cpu]->spinlock);
if (local_read(&etmdrvdata[cpu]->mode))
etm_disable_hw(etmdrvdata[cpu]);
spin_unlock(&etmdrvdata[cpu]->spinlock);
return 0;
}
static bool etm_arch_supported(u8 arch)
{
switch (arch) {
case ETM_ARCH_V3_3:
break;
case ETM_ARCH_V3_5:
break;
case PFT_ARCH_V1_0:
break;
case PFT_ARCH_V1_1:
break;
default:
return false;
}
return true;
}
static void etm_init_arch_data(void *info)
{
u32 etmidr;
u32 etmccr;
struct etm_drvdata *drvdata = info;
etm_os_unlock(drvdata);
CS_UNLOCK(drvdata->base);
(void)etm_readl(drvdata, ETMPDSR);
etm_set_pwrup(drvdata);
etm_clr_pwrdwn(drvdata);
etm_set_prog(drvdata);
etmidr = etm_readl(drvdata, ETMIDR);
drvdata->arch = BMVAL(etmidr, 4, 11);
drvdata->port_size = etm_readl(drvdata, ETMCR) & PORT_SIZE_MASK;
drvdata->etmccer = etm_readl(drvdata, ETMCCER);
etmccr = etm_readl(drvdata, ETMCCR);
drvdata->etmccr = etmccr;
drvdata->nr_addr_cmp = BMVAL(etmccr, 0, 3) * 2;
drvdata->nr_cntr = BMVAL(etmccr, 13, 15);
drvdata->nr_ext_inp = BMVAL(etmccr, 17, 19);
drvdata->nr_ext_out = BMVAL(etmccr, 20, 22);
drvdata->nr_ctxid_cmp = BMVAL(etmccr, 24, 25);
etm_set_pwrdwn(drvdata);
etm_clr_pwrup(drvdata);
CS_LOCK(drvdata->base);
}
static void etm_init_trace_id(struct etm_drvdata *drvdata)
{
drvdata->traceid = coresight_get_trace_id(drvdata->cpu);
}
static int etm_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret;
void __iomem *base;
struct device *dev = &adev->dev;
struct coresight_platform_data *pdata = NULL;
struct etm_drvdata *drvdata;
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
drvdata->use_cp14 = of_property_read_bool(np, "arm,cp14");
}
drvdata->dev = &adev->dev;
dev_set_drvdata(dev, drvdata);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
drvdata->base = base;
spin_lock_init(&drvdata->spinlock);
drvdata->atclk = devm_clk_get(&adev->dev, "atclk");
if (!IS_ERR(drvdata->atclk)) {
ret = clk_prepare_enable(drvdata->atclk);
if (ret)
return ret;
}
drvdata->cpu = pdata ? pdata->cpu : 0;
cpus_read_lock();
etmdrvdata[drvdata->cpu] = drvdata;
if (smp_call_function_single(drvdata->cpu,
etm_init_arch_data, drvdata, 1))
dev_err(dev, "ETM arch init failed\n");
if (!etm_count++) {
cpuhp_setup_state_nocalls_cpuslocked(CPUHP_AP_ARM_CORESIGHT_STARTING,
"arm/coresight:starting",
etm_starting_cpu, etm_dying_cpu);
ret = cpuhp_setup_state_nocalls_cpuslocked(CPUHP_AP_ONLINE_DYN,
"arm/coresight:online",
etm_online_cpu, NULL);
if (ret < 0)
goto err_arch_supported;
hp_online = ret;
}
cpus_read_unlock();
if (etm_arch_supported(drvdata->arch) == false) {
ret = -EINVAL;
goto err_arch_supported;
}
etm_init_trace_id(drvdata);
etm_set_default(&drvdata->config);
desc.type = CORESIGHT_DEV_TYPE_SOURCE;
desc.subtype.source_subtype = CORESIGHT_DEV_SUBTYPE_SOURCE_PROC;
desc.ops = &etm_cs_ops;
desc.pdata = pdata;
desc.dev = dev;
desc.groups = coresight_etm_groups;
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
if (--etm_count == 0) {
cpuhp_remove_state_nocalls(CPUHP_AP_ARM_CORESIGHT_STARTING);
if (hp_online)
cpuhp_remove_state_nocalls(hp_online);
}
return ret;
}
static int etm_runtime_suspend(struct device *dev)
{
struct etm_drvdata *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_disable_unprepare(drvdata->atclk);
return 0;
}
static int etm_runtime_resume(struct device *dev)
{
struct etm_drvdata *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_prepare_enable(drvdata->atclk);
return 0;
}
