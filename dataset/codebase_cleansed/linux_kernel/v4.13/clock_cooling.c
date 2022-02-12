static int clock_cooling_get_property(struct clock_cooling_device *ccdev,
unsigned long input,
unsigned long *output,
enum clock_cooling_property property)
{
int i;
unsigned long max_level = 0, level = 0;
unsigned int freq = CPUFREQ_ENTRY_INVALID;
int descend = -1;
struct cpufreq_frequency_table *pos, *table = ccdev->freq_table;
if (!output)
return -EINVAL;
if (!table)
return -EINVAL;
cpufreq_for_each_valid_entry(pos, table) {
if (freq == pos->frequency)
continue;
if (freq != CPUFREQ_ENTRY_INVALID && descend == -1)
descend = freq > pos->frequency;
freq = pos->frequency;
max_level++;
}
if (max_level == 0)
return -EINVAL;
max_level--;
if (property == GET_MAXL) {
*output = max_level;
return 0;
}
if (property == GET_FREQ)
level = descend ? input : (max_level - input);
i = 0;
cpufreq_for_each_valid_entry(pos, table) {
if (freq == pos->frequency)
continue;
freq = pos->frequency;
if (property == GET_LEVEL && (unsigned int)input == freq) {
*output = descend ? i : (max_level - i);
return 0;
}
if (property == GET_FREQ && level == i) {
*output = freq;
return 0;
}
i++;
}
return -EINVAL;
}
unsigned long clock_cooling_get_level(struct thermal_cooling_device *cdev,
unsigned long freq)
{
struct clock_cooling_device *ccdev = cdev->devdata;
unsigned long val;
if (clock_cooling_get_property(ccdev, (unsigned long)freq, &val,
GET_LEVEL))
return THERMAL_CSTATE_INVALID;
return val;
}
static unsigned long
clock_cooling_get_frequency(struct clock_cooling_device *ccdev,
unsigned long level)
{
int ret = 0;
unsigned long freq;
ret = clock_cooling_get_property(ccdev, level, &freq, GET_FREQ);
if (ret)
return 0;
return freq;
}
static int clock_cooling_apply(struct clock_cooling_device *ccdev,
unsigned long cooling_state)
{
unsigned long clip_freq, cur_freq;
int ret = 0;
if (ccdev->clock_state == cooling_state)
return 0;
clip_freq = clock_cooling_get_frequency(ccdev, cooling_state);
if (!clip_freq)
return -EINVAL;
cur_freq = clk_get_rate(ccdev->clk);
mutex_lock(&ccdev->lock);
ccdev->clock_state = cooling_state;
ccdev->clock_val = clip_freq;
if (cur_freq > clip_freq)
ret = clk_set_rate(ccdev->clk, clip_freq);
mutex_unlock(&ccdev->lock);
return ret;
}
static int clock_cooling_clock_notifier(struct notifier_block *nb,
unsigned long event, void *data)
{
struct clk_notifier_data *ndata = data;
struct clock_cooling_device *ccdev = to_clock_cooling_device(nb);
switch (event) {
case PRE_RATE_CHANGE:
if (ndata->new_rate > ccdev->clock_val)
return NOTIFY_BAD;
case POST_RATE_CHANGE:
case ABORT_RATE_CHANGE:
default:
return NOTIFY_DONE;
}
}
static int clock_cooling_get_max_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct clock_cooling_device *ccdev = cdev->devdata;
unsigned long count = 0;
int ret;
ret = clock_cooling_get_property(ccdev, 0, &count, GET_MAXL);
if (!ret)
*state = count;
return ret;
}
static int clock_cooling_get_cur_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct clock_cooling_device *ccdev = cdev->devdata;
*state = ccdev->clock_state;
return 0;
}
static int clock_cooling_set_cur_state(struct thermal_cooling_device *cdev,
unsigned long state)
{
struct clock_cooling_device *clock_device = cdev->devdata;
return clock_cooling_apply(clock_device, state);
}
struct thermal_cooling_device *
clock_cooling_register(struct device *dev, const char *clock_name)
{
struct thermal_cooling_device *cdev;
struct clock_cooling_device *ccdev = NULL;
char dev_name[THERMAL_NAME_LENGTH];
int ret = 0;
ccdev = devm_kzalloc(dev, sizeof(*ccdev), GFP_KERNEL);
if (!ccdev)
return ERR_PTR(-ENOMEM);
mutex_init(&ccdev->lock);
ccdev->dev = dev;
ccdev->clk = devm_clk_get(dev, clock_name);
if (IS_ERR(ccdev->clk))
return ERR_CAST(ccdev->clk);
ret = ida_simple_get(&clock_ida, 0, 0, GFP_KERNEL);
if (ret < 0)
return ERR_PTR(ret);
ccdev->id = ret;
snprintf(dev_name, sizeof(dev_name), "thermal-clock-%d", ccdev->id);
cdev = thermal_cooling_device_register(dev_name, ccdev,
&clock_cooling_ops);
if (IS_ERR(cdev)) {
ida_simple_remove(&clock_ida, ccdev->id);
return ERR_PTR(-EINVAL);
}
ccdev->cdev = cdev;
ccdev->clk_rate_change_nb.notifier_call = clock_cooling_clock_notifier;
ret = dev_pm_opp_init_cpufreq_table(dev, &ccdev->freq_table);
if (ret) {
ida_simple_remove(&clock_ida, ccdev->id);
return ERR_PTR(ret);
}
ccdev->clock_state = 0;
ccdev->clock_val = clock_cooling_get_frequency(ccdev, 0);
clk_notifier_register(ccdev->clk, &ccdev->clk_rate_change_nb);
return cdev;
}
void clock_cooling_unregister(struct thermal_cooling_device *cdev)
{
struct clock_cooling_device *ccdev;
if (!cdev)
return;
ccdev = cdev->devdata;
clk_notifier_unregister(ccdev->clk, &ccdev->clk_rate_change_nb);
dev_pm_opp_free_cpufreq_table(ccdev->dev, &ccdev->freq_table);
thermal_cooling_device_unregister(ccdev->cdev);
ida_simple_remove(&clock_ida, ccdev->id);
}
