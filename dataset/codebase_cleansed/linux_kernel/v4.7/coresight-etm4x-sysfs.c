static int etm4_set_mode_exclude(struct etmv4_drvdata *drvdata, bool exclude)
{
u8 idx;
struct etmv4_config *config = &drvdata->config;
idx = config->addr_idx;
if (BMVAL(config->addr_acc[idx], 0, 1) == ETM_INSTR_ADDR) {
if (idx % 2 != 0)
return -EINVAL;
if (config->addr_type[idx] != ETM_ADDR_TYPE_RANGE ||
config->addr_type[idx + 1] != ETM_ADDR_TYPE_RANGE)
return -EINVAL;
if (exclude == true) {
config->viiectlr |= BIT(idx / 2 + 16);
config->viiectlr &= ~BIT(idx / 2);
} else {
config->viiectlr |= BIT(idx / 2);
config->viiectlr &= ~BIT(idx / 2 + 16);
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
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
if (val)
config->mode = 0x0;
config->mode &= ~(ETM_MODE_LOAD | ETM_MODE_STORE);
config->cfg &= ~(BIT(1) | BIT(2));
config->mode &= ~(ETM_MODE_DATA_TRACE_ADDR |
ETM_MODE_DATA_TRACE_VAL);
config->cfg &= ~(BIT(16) | BIT(17));
config->eventctrl0 = 0x0;
config->eventctrl1 = 0x0;
config->ts_ctrl = 0x0;
config->stall_ctrl = 0x0;
if (drvdata->syncpr == false)
config->syncfreq = 0x8;
config->vinst_ctrl |= BIT(0);
if (drvdata->nr_addr_cmp == true) {
config->mode |= ETM_MODE_VIEWINST_STARTSTOP;
config->vinst_ctrl |= BIT(9);
}
config->viiectlr = 0x0;
config->vissctlr = 0x0;
for (i = 0; i < drvdata->nrseqstate-1; i++)
config->seq_ctrl[i] = 0x0;
config->seq_rst = 0x0;
config->seq_state = 0x0;
config->ext_inp = 0x0;
config->cntr_idx = 0x0;
for (i = 0; i < drvdata->nr_cntr; i++) {
config->cntrldvr[i] = 0x0;
config->cntr_ctrl[i] = 0x0;
config->cntr_val[i] = 0x0;
}
config->res_idx = 0x0;
for (i = 0; i < drvdata->nr_resource; i++)
config->res_ctrl[i] = 0x0;
for (i = 0; i < drvdata->nr_ss_cmp; i++) {
config->ss_ctrl[i] = 0x0;
config->ss_pe_cmp[i] = 0x0;
}
config->addr_idx = 0x0;
for (i = 0; i < drvdata->nr_addr_cmp * 2; i++) {
config->addr_val[i] = 0x0;
config->addr_acc[i] = 0x0;
config->addr_type[i] = ETM_ADDR_TYPE_NONE;
}
config->ctxid_idx = 0x0;
for (i = 0; i < drvdata->numcidc; i++) {
config->ctxid_pid[i] = 0x0;
config->ctxid_vpid[i] = 0x0;
}
config->ctxid_mask0 = 0x0;
config->ctxid_mask1 = 0x0;
config->vmid_idx = 0x0;
for (i = 0; i < drvdata->numvmidc; i++)
config->vmid_val[i] = 0x0;
config->vmid_mask0 = 0x0;
config->vmid_mask1 = 0x0;
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
struct etmv4_config *config = &drvdata->config;
val = config->mode;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t mode_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val, mode;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->mode = val & ETMv4_MODE_ALL;
if (config->mode & ETM_MODE_EXCLUDE)
etm4_set_mode_exclude(drvdata, true);
else
etm4_set_mode_exclude(drvdata, false);
if (drvdata->instrp0 == true) {
config->cfg &= ~(BIT(1) | BIT(2));
if (config->mode & ETM_MODE_LOAD)
config->cfg |= BIT(1);
if (config->mode & ETM_MODE_STORE)
config->cfg |= BIT(2);
if (config->mode & ETM_MODE_LOAD_STORE)
config->cfg |= BIT(1) | BIT(2);
}
if ((config->mode & ETM_MODE_BB) && (drvdata->trcbb == true))
config->cfg |= BIT(3);
else
config->cfg &= ~BIT(3);
if ((config->mode & ETMv4_MODE_CYCACC) &&
(drvdata->trccci == true))
config->cfg |= BIT(4);
else
config->cfg &= ~BIT(4);
if ((config->mode & ETMv4_MODE_CTXID) && (drvdata->ctxid_size))
config->cfg |= BIT(6);
else
config->cfg &= ~BIT(6);
if ((config->mode & ETM_MODE_VMID) && (drvdata->vmid_size))
config->cfg |= BIT(7);
else
config->cfg &= ~BIT(7);
mode = ETM_MODE_COND(config->mode);
if (drvdata->trccond == true) {
config->cfg &= ~(BIT(8) | BIT(9) | BIT(10));
config->cfg |= mode << 8;
}
if ((config->mode & ETMv4_MODE_TIMESTAMP) && (drvdata->ts_size))
config->cfg |= BIT(11);
else
config->cfg &= ~BIT(11);
if ((config->mode & ETM_MODE_RETURNSTACK) &&
(drvdata->retstack == true))
config->cfg |= BIT(12);
else
config->cfg &= ~BIT(12);
mode = ETM_MODE_QELEM(config->mode);
config->cfg &= ~(BIT(13) | BIT(14));
if ((mode & BIT(0)) && (drvdata->q_support & BIT(0)))
config->cfg |= BIT(13);
if ((mode & BIT(1)) && (drvdata->q_support & BIT(1)))
config->cfg |= BIT(14);
if ((config->mode & ETM_MODE_ATB_TRIGGER) &&
(drvdata->atbtrig == true))
config->eventctrl1 |= BIT(11);
else
config->eventctrl1 &= ~BIT(11);
if ((config->mode & ETM_MODE_LPOVERRIDE) &&
(drvdata->lpoverride == true))
config->eventctrl1 |= BIT(12);
else
config->eventctrl1 &= ~BIT(12);
if (config->mode & ETM_MODE_ISTALL_EN)
config->stall_ctrl |= BIT(8);
else
config->stall_ctrl &= ~BIT(8);
if (config->mode & ETM_MODE_INSTPRIO)
config->stall_ctrl |= BIT(10);
else
config->stall_ctrl &= ~BIT(10);
if ((config->mode & ETM_MODE_NOOVERFLOW) &&
(drvdata->nooverflow == true))
config->stall_ctrl |= BIT(13);
else
config->stall_ctrl &= ~BIT(13);
if (config->mode & ETM_MODE_VIEWINST_STARTSTOP)
config->vinst_ctrl |= BIT(9);
else
config->vinst_ctrl &= ~BIT(9);
if (config->mode & ETM_MODE_TRACE_RESET)
config->vinst_ctrl |= BIT(10);
else
config->vinst_ctrl &= ~BIT(10);
if ((config->mode & ETM_MODE_TRACE_ERR) &&
(drvdata->trc_error == true))
config->vinst_ctrl |= BIT(11);
else
config->vinst_ctrl &= ~BIT(11);
if (config->mode & (ETM_MODE_EXCL_KERN | ETM_MODE_EXCL_USER))
etm4_config_trace_mode(config);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t pe_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->pe_sel;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t pe_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
if (val > drvdata->nr_pe) {
spin_unlock(&drvdata->spinlock);
return -EINVAL;
}
config->pe_sel = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t event_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->eventctrl0;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
switch (drvdata->nr_event) {
case 0x0:
config->eventctrl0 = val & 0xFF;
break;
case 0x1:
config->eventctrl0 = val & 0xFFFF;
break;
case 0x2:
config->eventctrl0 = val & 0xFFFFFF;
break;
case 0x3:
config->eventctrl0 = val;
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
struct etmv4_config *config = &drvdata->config;
val = BMVAL(config->eventctrl1, 0, 3);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t event_instren_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->eventctrl1 &= ~(BIT(0) | BIT(1) | BIT(2) | BIT(3));
switch (drvdata->nr_event) {
case 0x0:
config->eventctrl1 |= val & BIT(1);
break;
case 0x1:
config->eventctrl1 |= val & (BIT(0) | BIT(1));
break;
case 0x2:
config->eventctrl1 |= val & (BIT(0) | BIT(1) | BIT(2));
break;
case 0x3:
config->eventctrl1 |= val & 0xF;
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
struct etmv4_config *config = &drvdata->config;
val = config->ts_ctrl;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t event_ts_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (!drvdata->ts_size)
return -EINVAL;
config->ts_ctrl = val & ETMv4_EVENT_MASK;
return size;
}
static ssize_t syncfreq_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->syncfreq;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t syncfreq_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (drvdata->syncpr == true)
return -EINVAL;
config->syncfreq = val & ETMv4_SYNC_MASK;
return size;
}
static ssize_t cyc_threshold_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->ccctlr;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t cyc_threshold_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val < drvdata->ccitmin)
return -EINVAL;
config->ccctlr = val & ETM_CYC_THRESHOLD_MASK;
return size;
}
static ssize_t bb_ctrl_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->bb_ctrl;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t bb_ctrl_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (drvdata->trcbb == false)
return -EINVAL;
if (!drvdata->nr_addr_cmp)
return -EINVAL;
if (BMVAL(val, 0, 7) > drvdata->nr_addr_cmp)
return -EINVAL;
config->bb_ctrl = val;
return size;
}
static ssize_t event_vinst_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->vinst_ctrl & ETMv4_EVENT_MASK;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t event_vinst_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
val &= ETMv4_EVENT_MASK;
config->vinst_ctrl &= ~ETMv4_EVENT_MASK;
config->vinst_ctrl |= val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t s_exlevel_vinst_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = BMVAL(config->vinst_ctrl, 16, 19);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t s_exlevel_vinst_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->vinst_ctrl &= ~(BIT(16) | BIT(17) | BIT(19));
val &= drvdata->s_ex_level;
config->vinst_ctrl |= (val << 16);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t ns_exlevel_vinst_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = BMVAL(config->vinst_ctrl, 20, 23);
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t ns_exlevel_vinst_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->vinst_ctrl &= ~(BIT(20) | BIT(21) | BIT(22));
val &= drvdata->ns_ex_level;
config->vinst_ctrl |= (val << 20);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->addr_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t addr_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->nr_addr_cmp * 2)
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->addr_idx = val;
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
val = BMVAL(config->addr_acc[idx], 0, 1);
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
struct etmv4_config *config = &drvdata->config;
if (strlen(buf) >= 20)
return -EINVAL;
if (sscanf(buf, "%s", str) != 1)
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!strcmp(str, "instr"))
config->addr_acc[idx] &= ~(BIT(0) | BIT(1));
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
struct etmv4_config *config = &drvdata->config;
idx = config->addr_idx;
spin_lock(&drvdata->spinlock);
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_SINGLE)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
val = (unsigned long)config->addr_val[idx];
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
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_SINGLE)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
config->addr_val[idx] = (u64)val;
config->addr_type[idx] = ETM_ADDR_TYPE_SINGLE;
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (idx % 2 != 0) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
if (!((config->addr_type[idx] == ETM_ADDR_TYPE_NONE &&
config->addr_type[idx + 1] == ETM_ADDR_TYPE_NONE) ||
(config->addr_type[idx] == ETM_ADDR_TYPE_RANGE &&
config->addr_type[idx + 1] == ETM_ADDR_TYPE_RANGE))) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
val1 = (unsigned long)config->addr_val[idx];
val2 = (unsigned long)config->addr_val[idx + 1];
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
struct etmv4_config *config = &drvdata->config;
if (sscanf(buf, "%lx %lx", &val1, &val2) != 2)
return -EINVAL;
if (val1 > val2)
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (idx % 2 != 0) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
if (!((config->addr_type[idx] == ETM_ADDR_TYPE_NONE &&
config->addr_type[idx + 1] == ETM_ADDR_TYPE_NONE) ||
(config->addr_type[idx] == ETM_ADDR_TYPE_RANGE &&
config->addr_type[idx + 1] == ETM_ADDR_TYPE_RANGE))) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
config->addr_val[idx] = (u64)val1;
config->addr_type[idx] = ETM_ADDR_TYPE_RANGE;
config->addr_val[idx + 1] = (u64)val2;
config->addr_type[idx + 1] = ETM_ADDR_TYPE_RANGE;
if (config->mode & ETM_MODE_EXCLUDE)
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_START)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
val = (unsigned long)config->addr_val[idx];
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
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!drvdata->nr_addr_cmp) {
spin_unlock(&drvdata->spinlock);
return -EINVAL;
}
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_START)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
config->addr_val[idx] = (u64)val;
config->addr_type[idx] = ETM_ADDR_TYPE_START;
config->vissctlr |= BIT(idx);
config->vinst_ctrl |= BIT(9);
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_STOP)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
val = (unsigned long)config->addr_val[idx];
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
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!drvdata->nr_addr_cmp) {
spin_unlock(&drvdata->spinlock);
return -EINVAL;
}
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_STOP)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
config->addr_val[idx] = (u64)val;
config->addr_type[idx] = ETM_ADDR_TYPE_STOP;
config->vissctlr |= BIT(idx + 16);
config->vinst_ctrl |= BIT(9);
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
val = BMVAL(config->addr_acc[idx], 2, 3);
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
struct etmv4_config *config = &drvdata->config;
if (strlen(buf) >= 10)
return -EINVAL;
if (sscanf(buf, "%s", str) != 1)
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!strcmp(str, "none"))
config->addr_acc[idx] &= ~(BIT(2) | BIT(3));
else if (!strcmp(str, "ctxid")) {
if (drvdata->numcidc) {
config->addr_acc[idx] |= BIT(2);
config->addr_acc[idx] &= ~BIT(3);
}
} else if (!strcmp(str, "vmid")) {
if (drvdata->numvmidc) {
config->addr_acc[idx] &= ~BIT(2);
config->addr_acc[idx] |= BIT(3);
}
} else if (!strcmp(str, "all")) {
if (drvdata->numcidc)
config->addr_acc[idx] |= BIT(2);
if (drvdata->numvmidc)
config->addr_acc[idx] |= BIT(3);
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
val = BMVAL(config->addr_acc[idx], 4, 6);
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
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if ((drvdata->numcidc <= 1) && (drvdata->numvmidc <= 1))
return -EINVAL;
if (val >= (drvdata->numcidc >= drvdata->numvmidc ?
drvdata->numcidc : drvdata->numvmidc))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
config->addr_acc[idx] &= ~(BIT(4) | BIT(5) | BIT(6));
config->addr_acc[idx] |= (val << 4);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t seq_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->seq_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t seq_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->nrseqstate - 1)
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->seq_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t seq_state_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->seq_state;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t seq_state_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->nrseqstate)
return -EINVAL;
config->seq_state = val;
return size;
}
static ssize_t seq_event_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 idx;
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->seq_idx;
val = config->seq_ctrl[idx];
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
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->seq_idx;
config->seq_ctrl[idx] = val & 0xFF;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t seq_reset_event_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->seq_rst;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t seq_reset_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (!(drvdata->nrseqstate))
return -EINVAL;
config->seq_rst = val & ETMv4_EVENT_MASK;
return size;
}
static ssize_t cntr_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->cntr_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t cntr_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->nr_cntr)
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->cntr_idx = val;
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->cntr_idx;
val = config->cntrldvr[idx];
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
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val > ETM_CNTR_MAX_VAL)
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->cntr_idx;
config->cntrldvr[idx] = val;
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->cntr_idx;
val = config->cntr_val[idx];
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
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val > ETM_CNTR_MAX_VAL)
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->cntr_idx;
config->cntr_val[idx] = val;
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->cntr_idx;
val = config->cntr_ctrl[idx];
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
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->cntr_idx;
config->cntr_ctrl[idx] = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t res_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->res_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t res_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if ((val == 0) || (val >= drvdata->nr_resource))
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->res_idx = val;
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->res_idx;
val = config->res_ctrl[idx];
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
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
idx = config->res_idx;
if (idx % 2 != 0)
val &= ~BIT(21);
config->res_ctrl[idx] = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t ctxid_idx_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = config->ctxid_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t ctxid_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->numcidc)
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->ctxid_idx = val;
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
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->ctxid_idx;
val = (unsigned long)config->ctxid_vpid[idx];
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
struct etmv4_config *config = &drvdata->config;
if (!drvdata->ctxid_size || !drvdata->numcidc)
return -EINVAL;
if (kstrtoul(buf, 16, &vpid))
return -EINVAL;
pid = coresight_vpid_to_pid(vpid);
spin_lock(&drvdata->spinlock);
idx = config->ctxid_idx;
config->ctxid_pid[idx] = (u64)pid;
config->ctxid_vpid[idx] = (u64)vpid;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t ctxid_masks_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val1, val2;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
val1 = config->ctxid_mask0;
val2 = config->ctxid_mask1;
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
struct etmv4_config *config = &drvdata->config;
if (!drvdata->ctxid_size || !drvdata->numcidc)
return -EINVAL;
if (sscanf(buf, "%lx %lx", &val1, &val2) != 2)
return -EINVAL;
spin_lock(&drvdata->spinlock);
switch (drvdata->numcidc) {
case 0x1:
config->ctxid_mask0 = val1 & 0xFF;
break;
case 0x2:
config->ctxid_mask0 = val1 & 0xFFFF;
break;
case 0x3:
config->ctxid_mask0 = val1 & 0xFFFFFF;
break;
case 0x4:
config->ctxid_mask0 = val1;
break;
case 0x5:
config->ctxid_mask0 = val1;
config->ctxid_mask1 = val2 & 0xFF;
break;
case 0x6:
config->ctxid_mask0 = val1;
config->ctxid_mask1 = val2 & 0xFFFF;
break;
case 0x7:
config->ctxid_mask0 = val1;
config->ctxid_mask1 = val2 & 0xFFFFFF;
break;
case 0x8:
config->ctxid_mask0 = val1;
config->ctxid_mask1 = val2;
break;
default:
break;
}
mask = config->ctxid_mask0;
for (i = 0; i < drvdata->numcidc; i++) {
maskbyte = mask & ETMv4_EVENT_MASK;
for (j = 0; j < 8; j++) {
if (maskbyte & 1)
config->ctxid_pid[i] &= ~(0xFF << (j * 8));
maskbyte >>= 1;
}
if (i == 3)
mask = config->ctxid_mask1;
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
struct etmv4_config *config = &drvdata->config;
val = config->vmid_idx;
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t vmid_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
if (val >= drvdata->numvmidc)
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->vmid_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t vmid_val_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
val = (unsigned long)config->vmid_val[config->vmid_idx];
return scnprintf(buf, PAGE_SIZE, "%#lx\n", val);
}
static ssize_t vmid_val_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
if (!drvdata->vmid_size || !drvdata->numvmidc)
return -EINVAL;
if (kstrtoul(buf, 16, &val))
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->vmid_val[config->vmid_idx] = (u64)val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t vmid_masks_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val1, val2;
struct etmv4_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etmv4_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
val1 = config->vmid_mask0;
val2 = config->vmid_mask1;
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
struct etmv4_config *config = &drvdata->config;
if (!drvdata->vmid_size || !drvdata->numvmidc)
return -EINVAL;
if (sscanf(buf, "%lx %lx", &val1, &val2) != 2)
return -EINVAL;
spin_lock(&drvdata->spinlock);
switch (drvdata->numvmidc) {
case 0x1:
config->vmid_mask0 = val1 & 0xFF;
break;
case 0x2:
config->vmid_mask0 = val1 & 0xFFFF;
break;
case 0x3:
config->vmid_mask0 = val1 & 0xFFFFFF;
break;
case 0x4:
config->vmid_mask0 = val1;
break;
case 0x5:
config->vmid_mask0 = val1;
config->vmid_mask1 = val2 & 0xFF;
break;
case 0x6:
config->vmid_mask0 = val1;
config->vmid_mask1 = val2 & 0xFFFF;
break;
case 0x7:
config->vmid_mask0 = val1;
config->vmid_mask1 = val2 & 0xFFFFFF;
break;
case 0x8:
config->vmid_mask0 = val1;
config->vmid_mask1 = val2;
break;
default:
break;
}
mask = config->vmid_mask0;
for (i = 0; i < drvdata->numvmidc; i++) {
maskbyte = mask & ETMv4_EVENT_MASK;
for (j = 0; j < 8; j++) {
if (maskbyte & 1)
config->vmid_val[i] &= ~(0xFF << (j * 8));
maskbyte >>= 1;
}
if (i == 3)
mask = config->vmid_mask1;
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
