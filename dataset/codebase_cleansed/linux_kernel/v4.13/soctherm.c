static inline void clk_writel(struct tegra_soctherm *ts, u32 value, u32 reg)
{
writel(value, (ts->clk_regs + reg));
}
static inline u32 clk_readl(struct tegra_soctherm *ts, u32 reg)
{
return readl(ts->clk_regs + reg);
}
static inline void ccroc_writel(struct tegra_soctherm *ts, u32 value, u32 reg)
{
writel(value, (ts->ccroc_regs + reg));
}
static inline u32 ccroc_readl(struct tegra_soctherm *ts, u32 reg)
{
return readl(ts->ccroc_regs + reg);
}
static void enable_tsensor(struct tegra_soctherm *tegra, unsigned int i)
{
const struct tegra_tsensor *sensor = &tegra->soc->tsensors[i];
void __iomem *base = tegra->regs + sensor->base;
unsigned int val;
val = sensor->config->tall << SENSOR_CONFIG0_TALL_SHIFT;
writel(val, base + SENSOR_CONFIG0);
val = (sensor->config->tsample - 1) << SENSOR_CONFIG1_TSAMPLE_SHIFT;
val |= sensor->config->tiddq_en << SENSOR_CONFIG1_TIDDQ_EN_SHIFT;
val |= sensor->config->ten_count << SENSOR_CONFIG1_TEN_COUNT_SHIFT;
val |= SENSOR_CONFIG1_TEMP_ENABLE;
writel(val, base + SENSOR_CONFIG1);
writel(tegra->calib[i], base + SENSOR_CONFIG2);
}
static int translate_temp(u16 val)
{
int t;
t = ((val & READBACK_VALUE_MASK) >> READBACK_VALUE_SHIFT) * 1000;
if (val & READBACK_ADD_HALF)
t += 500;
if (val & READBACK_NEGATE)
t *= -1;
return t;
}
static int tegra_thermctl_get_temp(void *data, int *out_temp)
{
struct tegra_thermctl_zone *zone = data;
u32 val;
val = readl(zone->reg);
val = REG_GET_MASK(val, zone->sg->sensor_temp_mask);
*out_temp = translate_temp(val);
return 0;
}
static int tegra_thermctl_set_trip_temp(void *data, int trip, int temp)
{
struct tegra_thermctl_zone *zone = data;
struct thermal_zone_device *tz = zone->tz;
struct tegra_soctherm *ts = zone->ts;
const struct tegra_tsensor_group *sg = zone->sg;
struct device *dev = zone->dev;
enum thermal_trip_type type;
int ret;
if (!tz)
return -EINVAL;
ret = tz->ops->get_trip_type(tz, trip, &type);
if (ret)
return ret;
if (type == THERMAL_TRIP_CRITICAL) {
return thermtrip_program(dev, sg, temp);
} else if (type == THERMAL_TRIP_HOT) {
int i;
for (i = 0; i < THROTTLE_SIZE; i++) {
struct thermal_cooling_device *cdev;
struct soctherm_throt_cfg *stc;
if (!ts->throt_cfgs[i].init)
continue;
cdev = ts->throt_cfgs[i].cdev;
if (get_thermal_instance(tz, cdev, trip))
stc = find_throttle_cfg_by_name(ts, cdev->type);
else
continue;
return throttrip_program(dev, sg, stc, temp);
}
}
return 0;
}
static int enforce_temp_range(struct device *dev, int trip_temp)
{
int temp;
temp = clamp_val(trip_temp, min_low_temp, max_high_temp);
if (temp != trip_temp)
dev_info(dev, "soctherm: trip temperature %d forced to %d\n",
trip_temp, temp);
return temp;
}
static int thermtrip_program(struct device *dev,
const struct tegra_tsensor_group *sg,
int trip_temp)
{
struct tegra_soctherm *ts = dev_get_drvdata(dev);
int temp;
u32 r;
if (!sg || !sg->thermtrip_threshold_mask)
return -EINVAL;
temp = enforce_temp_range(dev, trip_temp) / ts->soc->thresh_grain;
r = readl(ts->regs + THERMCTL_THERMTRIP_CTL);
r = REG_SET_MASK(r, sg->thermtrip_threshold_mask, temp);
r = REG_SET_MASK(r, sg->thermtrip_enable_mask, 1);
r = REG_SET_MASK(r, sg->thermtrip_any_en_mask, 0);
writel(r, ts->regs + THERMCTL_THERMTRIP_CTL);
return 0;
}
static int throttrip_program(struct device *dev,
const struct tegra_tsensor_group *sg,
struct soctherm_throt_cfg *stc,
int trip_temp)
{
struct tegra_soctherm *ts = dev_get_drvdata(dev);
int temp, cpu_throt, gpu_throt;
unsigned int throt;
u32 r, reg_off;
if (!dev || !sg || !stc || !stc->init)
return -EINVAL;
temp = enforce_temp_range(dev, trip_temp) / ts->soc->thresh_grain;
throt = stc->id;
reg_off = THERMCTL_LVL_REG(sg->thermctl_lvl0_offset, throt + 1);
if (throt == THROTTLE_LIGHT) {
cpu_throt = THERMCTL_LVL0_CPU0_CPU_THROT_LIGHT;
gpu_throt = THERMCTL_LVL0_CPU0_GPU_THROT_LIGHT;
} else {
cpu_throt = THERMCTL_LVL0_CPU0_CPU_THROT_HEAVY;
gpu_throt = THERMCTL_LVL0_CPU0_GPU_THROT_HEAVY;
if (throt != THROTTLE_HEAVY)
dev_warn(dev,
"invalid throt id %d - assuming HEAVY",
throt);
}
r = readl(ts->regs + reg_off);
r = REG_SET_MASK(r, sg->thermctl_lvl0_up_thresh_mask, temp);
r = REG_SET_MASK(r, sg->thermctl_lvl0_dn_thresh_mask, temp);
r = REG_SET_MASK(r, THERMCTL_LVL0_CPU0_CPU_THROT_MASK, cpu_throt);
r = REG_SET_MASK(r, THERMCTL_LVL0_CPU0_GPU_THROT_MASK, gpu_throt);
r = REG_SET_MASK(r, THERMCTL_LVL0_CPU0_EN_MASK, 1);
writel(r, ts->regs + reg_off);
return 0;
}
static struct soctherm_throt_cfg *
find_throttle_cfg_by_name(struct tegra_soctherm *ts, const char *name)
{
unsigned int i;
for (i = 0; ts->throt_cfgs[i].name; i++)
if (!strcmp(ts->throt_cfgs[i].name, name))
return &ts->throt_cfgs[i];
return NULL;
}
static int get_hot_temp(struct thermal_zone_device *tz, int *trip, int *temp)
{
int ntrips, i, ret;
enum thermal_trip_type type;
ntrips = of_thermal_get_ntrips(tz);
if (ntrips <= 0)
return -EINVAL;
for (i = 0; i < ntrips; i++) {
ret = tz->ops->get_trip_type(tz, i, &type);
if (ret)
return -EINVAL;
if (type == THERMAL_TRIP_HOT) {
ret = tz->ops->get_trip_temp(tz, i, temp);
if (!ret)
*trip = i;
return ret;
}
}
return -EINVAL;
}
static int tegra_soctherm_set_hwtrips(struct device *dev,
const struct tegra_tsensor_group *sg,
struct thermal_zone_device *tz)
{
struct tegra_soctherm *ts = dev_get_drvdata(dev);
struct soctherm_throt_cfg *stc;
int i, trip, temperature;
int ret;
ret = tz->ops->get_crit_temp(tz, &temperature);
if (ret) {
dev_warn(dev, "thermtrip: %s: missing critical temperature\n",
sg->name);
goto set_throttle;
}
ret = thermtrip_program(dev, sg, temperature);
if (ret) {
dev_err(dev, "thermtrip: %s: error during enable\n",
sg->name);
return ret;
}
dev_info(dev,
"thermtrip: will shut down when %s reaches %d mC\n",
sg->name, temperature);
set_throttle:
ret = get_hot_temp(tz, &trip, &temperature);
if (ret) {
dev_warn(dev, "throttrip: %s: missing hot temperature\n",
sg->name);
return 0;
}
for (i = 0; i < THROTTLE_SIZE; i++) {
struct thermal_cooling_device *cdev;
if (!ts->throt_cfgs[i].init)
continue;
cdev = ts->throt_cfgs[i].cdev;
if (get_thermal_instance(tz, cdev, trip))
stc = find_throttle_cfg_by_name(ts, cdev->type);
else
continue;
ret = throttrip_program(dev, sg, stc, temperature);
if (ret) {
dev_err(dev, "throttrip: %s: error during enable\n",
sg->name);
return ret;
}
dev_info(dev,
"throttrip: will throttle when %s reaches %d mC\n",
sg->name, temperature);
break;
}
if (i == THROTTLE_SIZE)
dev_warn(dev, "throttrip: %s: missing throttle cdev\n",
sg->name);
return 0;
}
static int regs_show(struct seq_file *s, void *data)
{
struct platform_device *pdev = s->private;
struct tegra_soctherm *ts = platform_get_drvdata(pdev);
const struct tegra_tsensor *tsensors = ts->soc->tsensors;
const struct tegra_tsensor_group **ttgs = ts->soc->ttgs;
u32 r, state;
int i, level;
seq_puts(s, "-----TSENSE (convert HW)-----\n");
for (i = 0; i < ts->soc->num_tsensors; i++) {
r = readl(ts->regs + tsensors[i].base + SENSOR_CONFIG1);
state = REG_GET_MASK(r, SENSOR_CONFIG1_TEMP_ENABLE);
seq_printf(s, "%s: ", tsensors[i].name);
seq_printf(s, "En(%d) ", state);
if (!state) {
seq_puts(s, "\n");
continue;
}
state = REG_GET_MASK(r, SENSOR_CONFIG1_TIDDQ_EN_MASK);
seq_printf(s, "tiddq(%d) ", state);
state = REG_GET_MASK(r, SENSOR_CONFIG1_TEN_COUNT_MASK);
seq_printf(s, "ten_count(%d) ", state);
state = REG_GET_MASK(r, SENSOR_CONFIG1_TSAMPLE_MASK);
seq_printf(s, "tsample(%d) ", state + 1);
r = readl(ts->regs + tsensors[i].base + SENSOR_STATUS1);
state = REG_GET_MASK(r, SENSOR_STATUS1_TEMP_VALID_MASK);
seq_printf(s, "Temp(%d/", state);
state = REG_GET_MASK(r, SENSOR_STATUS1_TEMP_MASK);
seq_printf(s, "%d) ", translate_temp(state));
r = readl(ts->regs + tsensors[i].base + SENSOR_STATUS0);
state = REG_GET_MASK(r, SENSOR_STATUS0_VALID_MASK);
seq_printf(s, "Capture(%d/", state);
state = REG_GET_MASK(r, SENSOR_STATUS0_CAPTURE_MASK);
seq_printf(s, "%d) ", state);
r = readl(ts->regs + tsensors[i].base + SENSOR_CONFIG0);
state = REG_GET_MASK(r, SENSOR_CONFIG0_STOP);
seq_printf(s, "Stop(%d) ", state);
state = REG_GET_MASK(r, SENSOR_CONFIG0_TALL_MASK);
seq_printf(s, "Tall(%d) ", state);
state = REG_GET_MASK(r, SENSOR_CONFIG0_TCALC_OVER);
seq_printf(s, "Over(%d/", state);
state = REG_GET_MASK(r, SENSOR_CONFIG0_OVER);
seq_printf(s, "%d/", state);
state = REG_GET_MASK(r, SENSOR_CONFIG0_CPTR_OVER);
seq_printf(s, "%d) ", state);
r = readl(ts->regs + tsensors[i].base + SENSOR_CONFIG2);
state = REG_GET_MASK(r, SENSOR_CONFIG2_THERMA_MASK);
seq_printf(s, "Therm_A/B(%d/", state);
state = REG_GET_MASK(r, SENSOR_CONFIG2_THERMB_MASK);
seq_printf(s, "%d)\n", (s16)state);
}
r = readl(ts->regs + SENSOR_PDIV);
seq_printf(s, "PDIV: 0x%x\n", r);
r = readl(ts->regs + SENSOR_HOTSPOT_OFF);
seq_printf(s, "HOTSPOT: 0x%x\n", r);
seq_puts(s, "\n");
seq_puts(s, "-----SOC_THERM-----\n");
r = readl(ts->regs + SENSOR_TEMP1);
state = REG_GET_MASK(r, SENSOR_TEMP1_CPU_TEMP_MASK);
seq_printf(s, "Temperatures: CPU(%d) ", translate_temp(state));
state = REG_GET_MASK(r, SENSOR_TEMP1_GPU_TEMP_MASK);
seq_printf(s, " GPU(%d) ", translate_temp(state));
r = readl(ts->regs + SENSOR_TEMP2);
state = REG_GET_MASK(r, SENSOR_TEMP2_PLLX_TEMP_MASK);
seq_printf(s, " PLLX(%d) ", translate_temp(state));
state = REG_GET_MASK(r, SENSOR_TEMP2_MEM_TEMP_MASK);
seq_printf(s, " MEM(%d)\n", translate_temp(state));
for (i = 0; i < ts->soc->num_ttgs; i++) {
seq_printf(s, "%s:\n", ttgs[i]->name);
for (level = 0; level < 4; level++) {
s32 v;
u32 mask;
u16 off = ttgs[i]->thermctl_lvl0_offset;
r = readl(ts->regs + THERMCTL_LVL_REG(off, level));
mask = ttgs[i]->thermctl_lvl0_up_thresh_mask;
state = REG_GET_MASK(r, mask);
v = sign_extend32(state, ts->soc->bptt - 1);
v *= ts->soc->thresh_grain;
seq_printf(s, " %d: Up/Dn(%d /", level, v);
mask = ttgs[i]->thermctl_lvl0_dn_thresh_mask;
state = REG_GET_MASK(r, mask);
v = sign_extend32(state, ts->soc->bptt - 1);
v *= ts->soc->thresh_grain;
seq_printf(s, "%d ) ", v);
mask = THERMCTL_LVL0_CPU0_EN_MASK;
state = REG_GET_MASK(r, mask);
seq_printf(s, "En(%d) ", state);
mask = THERMCTL_LVL0_CPU0_CPU_THROT_MASK;
state = REG_GET_MASK(r, mask);
seq_puts(s, "CPU Throt");
if (!state)
seq_printf(s, "(%s) ", "none");
else if (state == THERMCTL_LVL0_CPU0_CPU_THROT_LIGHT)
seq_printf(s, "(%s) ", "L");
else if (state == THERMCTL_LVL0_CPU0_CPU_THROT_HEAVY)
seq_printf(s, "(%s) ", "H");
else
seq_printf(s, "(%s) ", "H+L");
mask = THERMCTL_LVL0_CPU0_GPU_THROT_MASK;
state = REG_GET_MASK(r, mask);
seq_puts(s, "GPU Throt");
if (!state)
seq_printf(s, "(%s) ", "none");
else if (state == THERMCTL_LVL0_CPU0_GPU_THROT_LIGHT)
seq_printf(s, "(%s) ", "L");
else if (state == THERMCTL_LVL0_CPU0_GPU_THROT_HEAVY)
seq_printf(s, "(%s) ", "H");
else
seq_printf(s, "(%s) ", "H+L");
mask = THERMCTL_LVL0_CPU0_STATUS_MASK;
state = REG_GET_MASK(r, mask);
seq_printf(s, "Status(%s)\n",
state == 0 ? "LO" :
state == 1 ? "In" :
state == 2 ? "Res" : "HI");
}
}
r = readl(ts->regs + THERMCTL_STATS_CTL);
seq_printf(s, "STATS: Up(%s) Dn(%s)\n",
r & STATS_CTL_EN_UP ? "En" : "--",
r & STATS_CTL_EN_DN ? "En" : "--");
for (level = 0; level < 4; level++) {
u16 off;
off = THERMCTL_LVL0_UP_STATS;
r = readl(ts->regs + THERMCTL_LVL_REG(off, level));
seq_printf(s, " Level_%d Up(%d) ", level, r);
off = THERMCTL_LVL0_DN_STATS;
r = readl(ts->regs + THERMCTL_LVL_REG(off, level));
seq_printf(s, "Dn(%d)\n", r);
}
r = readl(ts->regs + THERMCTL_THERMTRIP_CTL);
state = REG_GET_MASK(r, ttgs[0]->thermtrip_any_en_mask);
seq_printf(s, "Thermtrip Any En(%d)\n", state);
for (i = 0; i < ts->soc->num_ttgs; i++) {
state = REG_GET_MASK(r, ttgs[i]->thermtrip_enable_mask);
seq_printf(s, " %s En(%d) ", ttgs[i]->name, state);
state = REG_GET_MASK(r, ttgs[i]->thermtrip_threshold_mask);
state *= ts->soc->thresh_grain;
seq_printf(s, "Thresh(%d)\n", state);
}
r = readl(ts->regs + THROT_GLOBAL_CFG);
seq_puts(s, "\n");
seq_printf(s, "GLOBAL THROTTLE CONFIG: 0x%08x\n", r);
seq_puts(s, "---------------------------------------------------\n");
r = readl(ts->regs + THROT_STATUS);
state = REG_GET_MASK(r, THROT_STATUS_BREACH_MASK);
seq_printf(s, "THROT STATUS: breach(%d) ", state);
state = REG_GET_MASK(r, THROT_STATUS_STATE_MASK);
seq_printf(s, "state(%d) ", state);
state = REG_GET_MASK(r, THROT_STATUS_ENABLED_MASK);
seq_printf(s, "enabled(%d)\n", state);
r = readl(ts->regs + CPU_PSKIP_STATUS);
if (ts->soc->use_ccroc) {
state = REG_GET_MASK(r, XPU_PSKIP_STATUS_ENABLED_MASK);
seq_printf(s, "CPU PSKIP STATUS: enabled(%d)\n", state);
} else {
state = REG_GET_MASK(r, XPU_PSKIP_STATUS_M_MASK);
seq_printf(s, "CPU PSKIP STATUS: M(%d) ", state);
state = REG_GET_MASK(r, XPU_PSKIP_STATUS_N_MASK);
seq_printf(s, "N(%d) ", state);
state = REG_GET_MASK(r, XPU_PSKIP_STATUS_ENABLED_MASK);
seq_printf(s, "enabled(%d)\n", state);
}
return 0;
}
static int regs_open(struct inode *inode, struct file *file)
{
return single_open(file, regs_show, inode->i_private);
}
static void soctherm_debug_init(struct platform_device *pdev)
{
struct tegra_soctherm *tegra = platform_get_drvdata(pdev);
struct dentry *root, *file;
root = debugfs_create_dir("soctherm", NULL);
if (!root) {
dev_err(&pdev->dev, "failed to create debugfs directory\n");
return;
}
tegra->debugfs_dir = root;
file = debugfs_create_file("reg_contents", 0644, root,
pdev, &regs_fops);
if (!file) {
dev_err(&pdev->dev, "failed to create debugfs file\n");
debugfs_remove_recursive(tegra->debugfs_dir);
tegra->debugfs_dir = NULL;
}
}
static inline void soctherm_debug_init(struct platform_device *pdev) {}
static int soctherm_clk_enable(struct platform_device *pdev, bool enable)
{
struct tegra_soctherm *tegra = platform_get_drvdata(pdev);
int err;
if (!tegra->clock_soctherm || !tegra->clock_tsensor)
return -EINVAL;
reset_control_assert(tegra->reset);
if (enable) {
err = clk_prepare_enable(tegra->clock_soctherm);
if (err) {
reset_control_deassert(tegra->reset);
return err;
}
err = clk_prepare_enable(tegra->clock_tsensor);
if (err) {
clk_disable_unprepare(tegra->clock_soctherm);
reset_control_deassert(tegra->reset);
return err;
}
} else {
clk_disable_unprepare(tegra->clock_tsensor);
clk_disable_unprepare(tegra->clock_soctherm);
}
reset_control_deassert(tegra->reset);
return 0;
}
static int throt_get_cdev_max_state(struct thermal_cooling_device *cdev,
unsigned long *max_state)
{
*max_state = 1;
return 0;
}
static int throt_get_cdev_cur_state(struct thermal_cooling_device *cdev,
unsigned long *cur_state)
{
struct tegra_soctherm *ts = cdev->devdata;
u32 r;
r = readl(ts->regs + THROT_STATUS);
if (REG_GET_MASK(r, THROT_STATUS_STATE_MASK))
*cur_state = 1;
else
*cur_state = 0;
return 0;
}
static int throt_set_cdev_state(struct thermal_cooling_device *cdev,
unsigned long cur_state)
{
return 0;
}
static void soctherm_init_hw_throt_cdev(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct tegra_soctherm *ts = dev_get_drvdata(dev);
struct device_node *np_stc, *np_stcc;
const char *name;
u32 val;
int i, r;
for (i = 0; i < THROTTLE_SIZE; i++) {
ts->throt_cfgs[i].name = throt_names[i];
ts->throt_cfgs[i].id = i;
ts->throt_cfgs[i].init = false;
}
np_stc = of_get_child_by_name(dev->of_node, "throttle-cfgs");
if (!np_stc) {
dev_info(dev,
"throttle-cfg: no throttle-cfgs - not enabling\n");
return;
}
for_each_child_of_node(np_stc, np_stcc) {
struct soctherm_throt_cfg *stc;
struct thermal_cooling_device *tcd;
name = np_stcc->name;
stc = find_throttle_cfg_by_name(ts, name);
if (!stc) {
dev_err(dev,
"throttle-cfg: could not find %s\n", name);
continue;
}
r = of_property_read_u32(np_stcc, "nvidia,priority", &val);
if (r) {
dev_info(dev,
"throttle-cfg: %s: missing priority\n", name);
continue;
}
stc->priority = val;
if (ts->soc->use_ccroc) {
r = of_property_read_u32(np_stcc,
"nvidia,cpu-throt-level",
&val);
if (r) {
dev_info(dev,
"throttle-cfg: %s: missing cpu-throt-level\n",
name);
continue;
}
stc->cpu_throt_level = val;
} else {
r = of_property_read_u32(np_stcc,
"nvidia,cpu-throt-percent",
&val);
if (r) {
dev_info(dev,
"throttle-cfg: %s: missing cpu-throt-percent\n",
name);
continue;
}
stc->cpu_throt_depth = val;
}
tcd = thermal_of_cooling_device_register(np_stcc,
(char *)name, ts,
&throt_cooling_ops);
of_node_put(np_stcc);
if (IS_ERR_OR_NULL(tcd)) {
dev_err(dev,
"throttle-cfg: %s: failed to register cooling device\n",
name);
continue;
}
stc->cdev = tcd;
stc->init = true;
}
of_node_put(np_stc);
}
static void throttlectl_cpu_level_cfg(struct tegra_soctherm *ts, int level)
{
u8 depth, dividend;
u32 r;
switch (level) {
case TEGRA_SOCTHERM_THROT_LEVEL_LOW:
depth = 50;
break;
case TEGRA_SOCTHERM_THROT_LEVEL_MED:
depth = 75;
break;
case TEGRA_SOCTHERM_THROT_LEVEL_HIGH:
depth = 80;
break;
case TEGRA_SOCTHERM_THROT_LEVEL_NONE:
return;
default:
return;
}
dividend = THROT_DEPTH_DIVIDEND(depth);
r = ccroc_readl(ts, CCROC_THROT_PSKIP_RAMP_CPU_REG(level));
r = REG_SET_MASK(r, CCROC_THROT_PSKIP_RAMP_DURATION_MASK, 0xff);
r = REG_SET_MASK(r, CCROC_THROT_PSKIP_RAMP_STEP_MASK, 0xf);
ccroc_writel(ts, r, CCROC_THROT_PSKIP_RAMP_CPU_REG(level));
r = ccroc_readl(ts, CCROC_THROT_PSKIP_CTRL_CPU_REG(level));
r = REG_SET_MASK(r, CCROC_THROT_PSKIP_CTRL_ENB_MASK, 1);
r = REG_SET_MASK(r, CCROC_THROT_PSKIP_CTRL_DIVIDEND_MASK, dividend);
r = REG_SET_MASK(r, CCROC_THROT_PSKIP_CTRL_DIVISOR_MASK, 0xff);
ccroc_writel(ts, r, CCROC_THROT_PSKIP_CTRL_CPU_REG(level));
}
static void throttlectl_cpu_level_select(struct tegra_soctherm *ts,
enum soctherm_throttle_id throt)
{
u32 r, throt_vect;
switch (ts->throt_cfgs[throt].cpu_throt_level) {
case TEGRA_SOCTHERM_THROT_LEVEL_LOW:
throt_vect = THROT_VECT_LOW;
break;
case TEGRA_SOCTHERM_THROT_LEVEL_MED:
throt_vect = THROT_VECT_MED;
break;
case TEGRA_SOCTHERM_THROT_LEVEL_HIGH:
throt_vect = THROT_VECT_HIGH;
break;
default:
throt_vect = THROT_VECT_NONE;
break;
}
r = readl(ts->regs + THROT_PSKIP_CTRL(throt, THROTTLE_DEV_CPU));
r = REG_SET_MASK(r, THROT_PSKIP_CTRL_ENABLE_MASK, 1);
r = REG_SET_MASK(r, THROT_PSKIP_CTRL_VECT_CPU_MASK, throt_vect);
r = REG_SET_MASK(r, THROT_PSKIP_CTRL_VECT2_CPU_MASK, throt_vect);
writel(r, ts->regs + THROT_PSKIP_CTRL(throt, THROTTLE_DEV_CPU));
r = REG_SET_MASK(0, THROT_PSKIP_RAMP_SEQ_BYPASS_MODE_MASK, 1);
writel(r, ts->regs + THROT_PSKIP_RAMP(throt, THROTTLE_DEV_CPU));
}
static void throttlectl_cpu_mn(struct tegra_soctherm *ts,
enum soctherm_throttle_id throt)
{
u32 r;
int depth;
u8 dividend;
depth = ts->throt_cfgs[throt].cpu_throt_depth;
dividend = THROT_DEPTH_DIVIDEND(depth);
r = readl(ts->regs + THROT_PSKIP_CTRL(throt, THROTTLE_DEV_CPU));
r = REG_SET_MASK(r, THROT_PSKIP_CTRL_ENABLE_MASK, 1);
r = REG_SET_MASK(r, THROT_PSKIP_CTRL_DIVIDEND_MASK, dividend);
r = REG_SET_MASK(r, THROT_PSKIP_CTRL_DIVISOR_MASK, 0xff);
writel(r, ts->regs + THROT_PSKIP_CTRL(throt, THROTTLE_DEV_CPU));
r = readl(ts->regs + THROT_PSKIP_RAMP(throt, THROTTLE_DEV_CPU));
r = REG_SET_MASK(r, THROT_PSKIP_RAMP_DURATION_MASK, 0xff);
r = REG_SET_MASK(r, THROT_PSKIP_RAMP_STEP_MASK, 0xf);
writel(r, ts->regs + THROT_PSKIP_RAMP(throt, THROTTLE_DEV_CPU));
}
static void soctherm_throttle_program(struct tegra_soctherm *ts,
enum soctherm_throttle_id throt)
{
u32 r;
struct soctherm_throt_cfg stc = ts->throt_cfgs[throt];
if (!stc.init)
return;
if (ts->soc->use_ccroc)
throttlectl_cpu_level_select(ts, throt);
else
throttlectl_cpu_mn(ts, throt);
r = REG_SET_MASK(0, THROT_PRIORITY_LITE_PRIO_MASK, stc.priority);
writel(r, ts->regs + THROT_PRIORITY_CTRL(throt));
r = REG_SET_MASK(0, THROT_DELAY_LITE_DELAY_MASK, 0);
writel(r, ts->regs + THROT_DELAY_CTRL(throt));
r = readl(ts->regs + THROT_PRIORITY_LOCK);
r = REG_GET_MASK(r, THROT_PRIORITY_LOCK_PRIORITY_MASK);
if (r >= stc.priority)
return;
r = REG_SET_MASK(0, THROT_PRIORITY_LOCK_PRIORITY_MASK,
stc.priority);
writel(r, ts->regs + THROT_PRIORITY_LOCK);
}
static void tegra_soctherm_throttle(struct device *dev)
{
struct tegra_soctherm *ts = dev_get_drvdata(dev);
u32 v;
int i;
if (ts->soc->use_ccroc) {
throttlectl_cpu_level_cfg(ts, TEGRA_SOCTHERM_THROT_LEVEL_LOW);
throttlectl_cpu_level_cfg(ts, TEGRA_SOCTHERM_THROT_LEVEL_MED);
throttlectl_cpu_level_cfg(ts, TEGRA_SOCTHERM_THROT_LEVEL_HIGH);
}
for (i = 0; i < THROTTLE_SIZE; i++)
soctherm_throttle_program(ts, i);
v = REG_SET_MASK(0, THROT_GLOBAL_ENB_MASK, 1);
if (ts->soc->use_ccroc) {
ccroc_writel(ts, v, CCROC_GLOBAL_CFG);
v = ccroc_readl(ts, CCROC_SUPER_CCLKG_DIVIDER);
v = REG_SET_MASK(v, CDIVG_USE_THERM_CONTROLS_MASK, 1);
ccroc_writel(ts, v, CCROC_SUPER_CCLKG_DIVIDER);
} else {
writel(v, ts->regs + THROT_GLOBAL_CFG);
v = clk_readl(ts, CAR_SUPER_CCLKG_DIVIDER);
v = REG_SET_MASK(v, CDIVG_USE_THERM_CONTROLS_MASK, 1);
clk_writel(ts, v, CAR_SUPER_CCLKG_DIVIDER);
}
v = STATS_CTL_CLR_DN | STATS_CTL_EN_DN |
STATS_CTL_CLR_UP | STATS_CTL_EN_UP;
writel(v, ts->regs + THERMCTL_STATS_CTL);
}
static void soctherm_init(struct platform_device *pdev)
{
struct tegra_soctherm *tegra = platform_get_drvdata(pdev);
const struct tegra_tsensor_group **ttgs = tegra->soc->ttgs;
int i;
u32 pdiv, hotspot;
for (i = 0; i < tegra->soc->num_tsensors; ++i)
enable_tsensor(tegra, i);
pdiv = readl(tegra->regs + SENSOR_PDIV);
hotspot = readl(tegra->regs + SENSOR_HOTSPOT_OFF);
for (i = 0; i < tegra->soc->num_ttgs; ++i) {
pdiv = REG_SET_MASK(pdiv, ttgs[i]->pdiv_mask,
ttgs[i]->pdiv);
if (ttgs[i]->id == TEGRA124_SOCTHERM_SENSOR_PLLX)
continue;
hotspot = REG_SET_MASK(hotspot,
ttgs[i]->pllx_hotspot_mask,
ttgs[i]->pllx_hotspot_diff);
}
writel(pdiv, tegra->regs + SENSOR_PDIV);
writel(hotspot, tegra->regs + SENSOR_HOTSPOT_OFF);
tegra_soctherm_throttle(&pdev->dev);
}
static int tegra_soctherm_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct tegra_soctherm *tegra;
struct thermal_zone_device *z;
struct tsensor_shared_calib shared_calib;
struct resource *res;
struct tegra_soctherm_soc *soc;
unsigned int i;
int err;
match = of_match_node(tegra_soctherm_of_match, pdev->dev.of_node);
if (!match)
return -ENODEV;
soc = (struct tegra_soctherm_soc *)match->data;
if (soc->num_ttgs > TEGRA124_SOCTHERM_SENSOR_NUM)
return -EINVAL;
tegra = devm_kzalloc(&pdev->dev, sizeof(*tegra), GFP_KERNEL);
if (!tegra)
return -ENOMEM;
dev_set_drvdata(&pdev->dev, tegra);
tegra->soc = soc;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"soctherm-reg");
tegra->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(tegra->regs)) {
dev_err(&pdev->dev, "can't get soctherm registers");
return PTR_ERR(tegra->regs);
}
if (!tegra->soc->use_ccroc) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"car-reg");
tegra->clk_regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(tegra->clk_regs)) {
dev_err(&pdev->dev, "can't get car clk registers");
return PTR_ERR(tegra->clk_regs);
}
} else {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"ccroc-reg");
tegra->ccroc_regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(tegra->ccroc_regs)) {
dev_err(&pdev->dev, "can't get ccroc registers");
return PTR_ERR(tegra->ccroc_regs);
}
}
tegra->reset = devm_reset_control_get(&pdev->dev, "soctherm");
if (IS_ERR(tegra->reset)) {
dev_err(&pdev->dev, "can't get soctherm reset\n");
return PTR_ERR(tegra->reset);
}
tegra->clock_tsensor = devm_clk_get(&pdev->dev, "tsensor");
if (IS_ERR(tegra->clock_tsensor)) {
dev_err(&pdev->dev, "can't get tsensor clock\n");
return PTR_ERR(tegra->clock_tsensor);
}
tegra->clock_soctherm = devm_clk_get(&pdev->dev, "soctherm");
if (IS_ERR(tegra->clock_soctherm)) {
dev_err(&pdev->dev, "can't get soctherm clock\n");
return PTR_ERR(tegra->clock_soctherm);
}
tegra->calib = devm_kzalloc(&pdev->dev,
sizeof(u32) * soc->num_tsensors,
GFP_KERNEL);
if (!tegra->calib)
return -ENOMEM;
err = tegra_calc_shared_calib(soc->tfuse, &shared_calib);
if (err)
return err;
for (i = 0; i < soc->num_tsensors; ++i) {
err = tegra_calc_tsensor_calib(&soc->tsensors[i],
&shared_calib,
&tegra->calib[i]);
if (err)
return err;
}
tegra->thermctl_tzs = devm_kzalloc(&pdev->dev,
sizeof(*z) * soc->num_ttgs,
GFP_KERNEL);
if (!tegra->thermctl_tzs)
return -ENOMEM;
err = soctherm_clk_enable(pdev, true);
if (err)
return err;
soctherm_init_hw_throt_cdev(pdev);
soctherm_init(pdev);
for (i = 0; i < soc->num_ttgs; ++i) {
struct tegra_thermctl_zone *zone =
devm_kzalloc(&pdev->dev, sizeof(*zone), GFP_KERNEL);
if (!zone) {
err = -ENOMEM;
goto disable_clocks;
}
zone->reg = tegra->regs + soc->ttgs[i]->sensor_temp_offset;
zone->dev = &pdev->dev;
zone->sg = soc->ttgs[i];
zone->ts = tegra;
z = devm_thermal_zone_of_sensor_register(&pdev->dev,
soc->ttgs[i]->id, zone,
&tegra_of_thermal_ops);
if (IS_ERR(z)) {
err = PTR_ERR(z);
dev_err(&pdev->dev, "failed to register sensor: %d\n",
err);
goto disable_clocks;
}
zone->tz = z;
tegra->thermctl_tzs[soc->ttgs[i]->id] = z;
err = tegra_soctherm_set_hwtrips(&pdev->dev, soc->ttgs[i], z);
if (err)
goto disable_clocks;
}
soctherm_debug_init(pdev);
return 0;
disable_clocks:
soctherm_clk_enable(pdev, false);
return err;
}
static int tegra_soctherm_remove(struct platform_device *pdev)
{
struct tegra_soctherm *tegra = platform_get_drvdata(pdev);
debugfs_remove_recursive(tegra->debugfs_dir);
soctherm_clk_enable(pdev, false);
return 0;
}
static int __maybe_unused soctherm_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
soctherm_clk_enable(pdev, false);
return 0;
}
static int __maybe_unused soctherm_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct tegra_soctherm *tegra = platform_get_drvdata(pdev);
struct tegra_soctherm_soc *soc = tegra->soc;
int err, i;
err = soctherm_clk_enable(pdev, true);
if (err) {
dev_err(&pdev->dev,
"Resume failed: enable clocks failed\n");
return err;
}
soctherm_init(pdev);
for (i = 0; i < soc->num_ttgs; ++i) {
struct thermal_zone_device *tz;
tz = tegra->thermctl_tzs[soc->ttgs[i]->id];
err = tegra_soctherm_set_hwtrips(dev, soc->ttgs[i], tz);
if (err) {
dev_err(&pdev->dev,
"Resume failed: set hwtrips failed\n");
return err;
}
}
return 0;
}
