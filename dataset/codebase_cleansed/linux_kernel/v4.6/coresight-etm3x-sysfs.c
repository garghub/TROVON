static ssize_t nr_addr_cmp_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->nr_addr_cmp;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t nr_cntr_show(struct device *dev,
struct device_attribute *attr, char *buf)
{ unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->nr_cntr;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t nr_ctxid_cmp_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->nr_ctxid_cmp;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t etmsr_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long flags, val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
pm_runtime_get_sync(drvdata->dev);
spin_lock_irqsave(&drvdata->spinlock, flags);
CS_UNLOCK(drvdata->base);
val = etm_readl(drvdata, ETMSR);
CS_LOCK(drvdata->base);
spin_unlock_irqrestore(&drvdata->spinlock, flags);
pm_runtime_put(drvdata->dev);
return sprintf(buf, "%#lx\n", val);
}
static ssize_t reset_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int i, ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
if (val) {
spin_lock(&drvdata->spinlock);
memset(config, 0, sizeof(struct etm_config));
config->mode = ETM_MODE_EXCLUDE;
config->trigger_event = ETM_DEFAULT_EVENT_VAL;
for (i = 0; i < drvdata->nr_addr_cmp; i++) {
config->addr_type[i] = ETM_ADDR_TYPE_NONE;
}
etm_set_default(config);
spin_unlock(&drvdata->spinlock);
}
return size;
}
static ssize_t mode_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->mode;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t mode_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
spin_lock(&drvdata->spinlock);
config->mode = val & ETM_MODE_ALL;
if (config->mode & ETM_MODE_EXCLUDE)
config->enable_ctrl1 |= ETMTECR1_INC_EXC;
else
config->enable_ctrl1 &= ~ETMTECR1_INC_EXC;
if (config->mode & ETM_MODE_CYCACC)
config->ctrl |= ETMCR_CYC_ACC;
else
config->ctrl &= ~ETMCR_CYC_ACC;
if (config->mode & ETM_MODE_STALL) {
if (!(drvdata->etmccr & ETMCCR_FIFOFULL)) {
dev_warn(drvdata->dev, "stall mode not supported\n");
ret = -EINVAL;
goto err_unlock;
}
config->ctrl |= ETMCR_STALL_MODE;
} else
config->ctrl &= ~ETMCR_STALL_MODE;
if (config->mode & ETM_MODE_TIMESTAMP) {
if (!(drvdata->etmccer & ETMCCER_TIMESTAMP)) {
dev_warn(drvdata->dev, "timestamp not supported\n");
ret = -EINVAL;
goto err_unlock;
}
config->ctrl |= ETMCR_TIMESTAMP_EN;
} else
config->ctrl &= ~ETMCR_TIMESTAMP_EN;
if (config->mode & ETM_MODE_CTXID)
config->ctrl |= ETMCR_CTXID_SIZE;
else
config->ctrl &= ~ETMCR_CTXID_SIZE;
if (config->mode & (ETM_MODE_EXCL_KERN | ETM_MODE_EXCL_USER))
etm_config_trace_mode(config);
spin_unlock(&drvdata->spinlock);
return size;
err_unlock:
spin_unlock(&drvdata->spinlock);
return ret;
}
static ssize_t trigger_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->trigger_event;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t trigger_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->trigger_event = val & ETM_EVENT_MASK;
return size;
}
static ssize_t enable_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->enable_event;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t enable_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->enable_event = val & ETM_EVENT_MASK;
return size;
}
static ssize_t fifofull_level_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->fifofull_level;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t fifofull_level_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->fifofull_level = val;
return size;
}
static ssize_t addr_idx_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->addr_idx;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t addr_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
if (val >= drvdata->nr_addr_cmp)
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->addr_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_single_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u8 idx;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_SINGLE)) {
spin_unlock(&drvdata->spinlock);
return -EINVAL;
}
val = config->addr_val[idx];
spin_unlock(&drvdata->spinlock);
return sprintf(buf, "%#lx\n", val);
}
static ssize_t addr_single_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_SINGLE)) {
spin_unlock(&drvdata->spinlock);
return -EINVAL;
}
config->addr_val[idx] = val;
config->addr_type[idx] = ETM_ADDR_TYPE_SINGLE;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_range_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u8 idx;
unsigned long val1, val2;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
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
val1 = config->addr_val[idx];
val2 = config->addr_val[idx + 1];
spin_unlock(&drvdata->spinlock);
return sprintf(buf, "%#lx %#lx\n", val1, val2);
}
static ssize_t addr_range_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
unsigned long val1, val2;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
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
config->addr_val[idx] = val1;
config->addr_type[idx] = ETM_ADDR_TYPE_RANGE;
config->addr_val[idx + 1] = val2;
config->addr_type[idx + 1] = ETM_ADDR_TYPE_RANGE;
config->enable_ctrl1 |= (1 << (idx/2));
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_start_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u8 idx;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_START)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
val = config->addr_val[idx];
spin_unlock(&drvdata->spinlock);
return sprintf(buf, "%#lx\n", val);
}
static ssize_t addr_start_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_START)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
config->addr_val[idx] = val;
config->addr_type[idx] = ETM_ADDR_TYPE_START;
config->startstop_ctrl |= (1 << idx);
config->enable_ctrl1 |= BIT(25);
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_stop_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u8 idx;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_STOP)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
val = config->addr_val[idx];
spin_unlock(&drvdata->spinlock);
return sprintf(buf, "%#lx\n", val);
}
static ssize_t addr_stop_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
u8 idx;
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
spin_lock(&drvdata->spinlock);
idx = config->addr_idx;
if (!(config->addr_type[idx] == ETM_ADDR_TYPE_NONE ||
config->addr_type[idx] == ETM_ADDR_TYPE_STOP)) {
spin_unlock(&drvdata->spinlock);
return -EPERM;
}
config->addr_val[idx] = val;
config->addr_type[idx] = ETM_ADDR_TYPE_STOP;
config->startstop_ctrl |= (1 << (idx + 16));
config->enable_ctrl1 |= ETMTECR1_START_STOP;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t addr_acctype_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
val = config->addr_acctype[config->addr_idx];
spin_unlock(&drvdata->spinlock);
return sprintf(buf, "%#lx\n", val);
}
static ssize_t addr_acctype_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
spin_lock(&drvdata->spinlock);
config->addr_acctype[config->addr_idx] = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t cntr_idx_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->cntr_idx;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t cntr_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
if (val >= drvdata->nr_cntr)
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->cntr_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t cntr_rld_val_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
val = config->cntr_rld_val[config->cntr_idx];
spin_unlock(&drvdata->spinlock);
return sprintf(buf, "%#lx\n", val);
}
static ssize_t cntr_rld_val_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
spin_lock(&drvdata->spinlock);
config->cntr_rld_val[config->cntr_idx] = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t cntr_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
val = config->cntr_event[config->cntr_idx];
spin_unlock(&drvdata->spinlock);
return sprintf(buf, "%#lx\n", val);
}
static ssize_t cntr_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
spin_lock(&drvdata->spinlock);
config->cntr_event[config->cntr_idx] = val & ETM_EVENT_MASK;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t cntr_rld_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
val = config->cntr_rld_event[config->cntr_idx];
spin_unlock(&drvdata->spinlock);
return sprintf(buf, "%#lx\n", val);
}
static ssize_t cntr_rld_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
spin_lock(&drvdata->spinlock);
config->cntr_rld_event[config->cntr_idx] = val & ETM_EVENT_MASK;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t cntr_val_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int i, ret = 0;
u32 val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
if (!local_read(&drvdata->mode)) {
spin_lock(&drvdata->spinlock);
for (i = 0; i < drvdata->nr_cntr; i++)
ret += sprintf(buf, "counter %d: %x\n",
i, config->cntr_val[i]);
spin_unlock(&drvdata->spinlock);
return ret;
}
for (i = 0; i < drvdata->nr_cntr; i++) {
val = etm_readl(drvdata, ETMCNTVRn(i));
ret += sprintf(buf, "counter %d: %x\n", i, val);
}
return ret;
}
static ssize_t cntr_val_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
spin_lock(&drvdata->spinlock);
config->cntr_val[config->cntr_idx] = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t seq_12_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->seq_12_event;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t seq_12_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->seq_12_event = val & ETM_EVENT_MASK;
return size;
}
static ssize_t seq_21_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->seq_21_event;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t seq_21_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->seq_21_event = val & ETM_EVENT_MASK;
return size;
}
static ssize_t seq_23_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->seq_23_event;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t seq_23_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->seq_23_event = val & ETM_EVENT_MASK;
return size;
}
static ssize_t seq_31_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->seq_31_event;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t seq_31_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->seq_31_event = val & ETM_EVENT_MASK;
return size;
}
static ssize_t seq_32_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->seq_32_event;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t seq_32_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->seq_32_event = val & ETM_EVENT_MASK;
return size;
}
static ssize_t seq_13_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->seq_13_event;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t seq_13_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->seq_13_event = val & ETM_EVENT_MASK;
return size;
}
static ssize_t seq_curr_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val, flags;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
if (!local_read(&drvdata->mode)) {
val = config->seq_curr_state;
goto out;
}
pm_runtime_get_sync(drvdata->dev);
spin_lock_irqsave(&drvdata->spinlock, flags);
CS_UNLOCK(drvdata->base);
val = (etm_readl(drvdata, ETMSQR) & ETM_SQR_MASK);
CS_LOCK(drvdata->base);
spin_unlock_irqrestore(&drvdata->spinlock, flags);
pm_runtime_put(drvdata->dev);
out:
return sprintf(buf, "%#lx\n", val);
}
static ssize_t seq_curr_state_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
if (val > ETM_SEQ_STATE_MAX_VAL)
return -EINVAL;
config->seq_curr_state = val;
return size;
}
static ssize_t ctxid_idx_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->ctxid_idx;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t ctxid_idx_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
if (val >= drvdata->nr_ctxid_cmp)
return -EINVAL;
spin_lock(&drvdata->spinlock);
config->ctxid_idx = val;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t ctxid_pid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
spin_lock(&drvdata->spinlock);
val = config->ctxid_vpid[config->ctxid_idx];
spin_unlock(&drvdata->spinlock);
return sprintf(buf, "%#lx\n", val);
}
static ssize_t ctxid_pid_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long vpid, pid;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &vpid);
if (ret)
return ret;
pid = coresight_vpid_to_pid(vpid);
spin_lock(&drvdata->spinlock);
config->ctxid_pid[config->ctxid_idx] = pid;
config->ctxid_vpid[config->ctxid_idx] = vpid;
spin_unlock(&drvdata->spinlock);
return size;
}
static ssize_t ctxid_mask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->ctxid_mask;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t ctxid_mask_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->ctxid_mask = val;
return size;
}
static ssize_t sync_freq_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->sync_freq;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t sync_freq_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->sync_freq = val & ETM_SYNC_MASK;
return size;
}
static ssize_t timestamp_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
val = config->timestamp_event;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t timestamp_event_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
struct etm_config *config = &drvdata->config;
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
config->timestamp_event = val & ETM_EVENT_MASK;
return size;
}
static ssize_t cpu_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = drvdata->cpu;
return scnprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t traceid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
val = etm_get_trace_id(drvdata);
return sprintf(buf, "%#lx\n", val);
}
static ssize_t traceid_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
drvdata->traceid = val & ETM_TRACEID_MASK;
return size;
}
