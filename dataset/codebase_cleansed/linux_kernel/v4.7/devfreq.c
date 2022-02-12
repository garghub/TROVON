static struct devfreq *find_device_devfreq(struct device *dev)
{
struct devfreq *tmp_devfreq;
if (IS_ERR_OR_NULL(dev)) {
pr_err("DEVFREQ: %s: Invalid parameters\n", __func__);
return ERR_PTR(-EINVAL);
}
WARN(!mutex_is_locked(&devfreq_list_lock),
"devfreq_list_lock must be locked.");
list_for_each_entry(tmp_devfreq, &devfreq_list, node) {
if (tmp_devfreq->dev.parent == dev)
return tmp_devfreq;
}
return ERR_PTR(-ENODEV);
}
static int devfreq_get_freq_level(struct devfreq *devfreq, unsigned long freq)
{
int lev;
for (lev = 0; lev < devfreq->profile->max_state; lev++)
if (freq == devfreq->profile->freq_table[lev])
return lev;
return -EINVAL;
}
static void devfreq_set_freq_table(struct devfreq *devfreq)
{
struct devfreq_dev_profile *profile = devfreq->profile;
struct dev_pm_opp *opp;
unsigned long freq;
int i, count;
count = dev_pm_opp_get_opp_count(devfreq->dev.parent);
if (count <= 0)
return;
profile->max_state = count;
profile->freq_table = devm_kcalloc(devfreq->dev.parent,
profile->max_state,
sizeof(*profile->freq_table),
GFP_KERNEL);
if (!profile->freq_table) {
profile->max_state = 0;
return;
}
rcu_read_lock();
for (i = 0, freq = 0; i < profile->max_state; i++, freq++) {
opp = dev_pm_opp_find_freq_ceil(devfreq->dev.parent, &freq);
if (IS_ERR(opp)) {
devm_kfree(devfreq->dev.parent, profile->freq_table);
profile->max_state = 0;
rcu_read_unlock();
return;
}
profile->freq_table[i] = freq;
}
rcu_read_unlock();
}
static int devfreq_update_status(struct devfreq *devfreq, unsigned long freq)
{
int lev, prev_lev, ret = 0;
unsigned long cur_time;
cur_time = jiffies;
prev_lev = devfreq_get_freq_level(devfreq, devfreq->previous_freq);
if (prev_lev < 0) {
ret = prev_lev;
goto out;
}
devfreq->time_in_state[prev_lev] +=
cur_time - devfreq->last_stat_updated;
lev = devfreq_get_freq_level(devfreq, freq);
if (lev < 0) {
ret = lev;
goto out;
}
if (lev != prev_lev) {
devfreq->trans_table[(prev_lev *
devfreq->profile->max_state) + lev]++;
devfreq->total_trans++;
}
out:
devfreq->last_stat_updated = cur_time;
return ret;
}
static struct devfreq_governor *find_devfreq_governor(const char *name)
{
struct devfreq_governor *tmp_governor;
if (IS_ERR_OR_NULL(name)) {
pr_err("DEVFREQ: %s: Invalid parameters\n", __func__);
return ERR_PTR(-EINVAL);
}
WARN(!mutex_is_locked(&devfreq_list_lock),
"devfreq_list_lock must be locked.");
list_for_each_entry(tmp_governor, &devfreq_governor_list, node) {
if (!strncmp(tmp_governor->name, name, DEVFREQ_NAME_LEN))
return tmp_governor;
}
return ERR_PTR(-ENODEV);
}
static int devfreq_notify_transition(struct devfreq *devfreq,
struct devfreq_freqs *freqs, unsigned int state)
{
if (!devfreq)
return -EINVAL;
switch (state) {
case DEVFREQ_PRECHANGE:
srcu_notifier_call_chain(&devfreq->transition_notifier_list,
DEVFREQ_PRECHANGE, freqs);
break;
case DEVFREQ_POSTCHANGE:
srcu_notifier_call_chain(&devfreq->transition_notifier_list,
DEVFREQ_POSTCHANGE, freqs);
break;
default:
return -EINVAL;
}
return 0;
}
int update_devfreq(struct devfreq *devfreq)
{
struct devfreq_freqs freqs;
unsigned long freq, cur_freq;
int err = 0;
u32 flags = 0;
if (!mutex_is_locked(&devfreq->lock)) {
WARN(true, "devfreq->lock must be locked by the caller.\n");
return -EINVAL;
}
if (!devfreq->governor)
return -EINVAL;
err = devfreq->governor->get_target_freq(devfreq, &freq);
if (err)
return err;
if (devfreq->min_freq && freq < devfreq->min_freq) {
freq = devfreq->min_freq;
flags &= ~DEVFREQ_FLAG_LEAST_UPPER_BOUND;
}
if (devfreq->max_freq && freq > devfreq->max_freq) {
freq = devfreq->max_freq;
flags |= DEVFREQ_FLAG_LEAST_UPPER_BOUND;
}
if (devfreq->profile->get_cur_freq)
devfreq->profile->get_cur_freq(devfreq->dev.parent, &cur_freq);
else
cur_freq = devfreq->previous_freq;
freqs.old = cur_freq;
freqs.new = freq;
devfreq_notify_transition(devfreq, &freqs, DEVFREQ_PRECHANGE);
err = devfreq->profile->target(devfreq->dev.parent, &freq, flags);
if (err) {
freqs.new = cur_freq;
devfreq_notify_transition(devfreq, &freqs, DEVFREQ_POSTCHANGE);
return err;
}
freqs.new = freq;
devfreq_notify_transition(devfreq, &freqs, DEVFREQ_POSTCHANGE);
if (devfreq->profile->freq_table)
if (devfreq_update_status(devfreq, freq))
dev_err(&devfreq->dev,
"Couldn't update frequency transition information.\n");
devfreq->previous_freq = freq;
return err;
}
static void devfreq_monitor(struct work_struct *work)
{
int err;
struct devfreq *devfreq = container_of(work,
struct devfreq, work.work);
mutex_lock(&devfreq->lock);
err = update_devfreq(devfreq);
if (err)
dev_err(&devfreq->dev, "dvfs failed with (%d) error\n", err);
queue_delayed_work(devfreq_wq, &devfreq->work,
msecs_to_jiffies(devfreq->profile->polling_ms));
mutex_unlock(&devfreq->lock);
}
void devfreq_monitor_start(struct devfreq *devfreq)
{
INIT_DEFERRABLE_WORK(&devfreq->work, devfreq_monitor);
if (devfreq->profile->polling_ms)
queue_delayed_work(devfreq_wq, &devfreq->work,
msecs_to_jiffies(devfreq->profile->polling_ms));
}
void devfreq_monitor_stop(struct devfreq *devfreq)
{
cancel_delayed_work_sync(&devfreq->work);
}
void devfreq_monitor_suspend(struct devfreq *devfreq)
{
mutex_lock(&devfreq->lock);
if (devfreq->stop_polling) {
mutex_unlock(&devfreq->lock);
return;
}
devfreq_update_status(devfreq, devfreq->previous_freq);
devfreq->stop_polling = true;
mutex_unlock(&devfreq->lock);
cancel_delayed_work_sync(&devfreq->work);
}
void devfreq_monitor_resume(struct devfreq *devfreq)
{
unsigned long freq;
mutex_lock(&devfreq->lock);
if (!devfreq->stop_polling)
goto out;
if (!delayed_work_pending(&devfreq->work) &&
devfreq->profile->polling_ms)
queue_delayed_work(devfreq_wq, &devfreq->work,
msecs_to_jiffies(devfreq->profile->polling_ms));
devfreq->last_stat_updated = jiffies;
devfreq->stop_polling = false;
if (devfreq->profile->get_cur_freq &&
!devfreq->profile->get_cur_freq(devfreq->dev.parent, &freq))
devfreq->previous_freq = freq;
out:
mutex_unlock(&devfreq->lock);
}
void devfreq_interval_update(struct devfreq *devfreq, unsigned int *delay)
{
unsigned int cur_delay = devfreq->profile->polling_ms;
unsigned int new_delay = *delay;
mutex_lock(&devfreq->lock);
devfreq->profile->polling_ms = new_delay;
if (devfreq->stop_polling)
goto out;
if (!new_delay) {
mutex_unlock(&devfreq->lock);
cancel_delayed_work_sync(&devfreq->work);
return;
}
if (!cur_delay) {
queue_delayed_work(devfreq_wq, &devfreq->work,
msecs_to_jiffies(devfreq->profile->polling_ms));
goto out;
}
if (cur_delay > new_delay) {
mutex_unlock(&devfreq->lock);
cancel_delayed_work_sync(&devfreq->work);
mutex_lock(&devfreq->lock);
if (!devfreq->stop_polling)
queue_delayed_work(devfreq_wq, &devfreq->work,
msecs_to_jiffies(devfreq->profile->polling_ms));
}
out:
mutex_unlock(&devfreq->lock);
}
static int devfreq_notifier_call(struct notifier_block *nb, unsigned long type,
void *devp)
{
struct devfreq *devfreq = container_of(nb, struct devfreq, nb);
int ret;
mutex_lock(&devfreq->lock);
ret = update_devfreq(devfreq);
mutex_unlock(&devfreq->lock);
return ret;
}
static void _remove_devfreq(struct devfreq *devfreq)
{
mutex_lock(&devfreq_list_lock);
if (IS_ERR(find_device_devfreq(devfreq->dev.parent))) {
mutex_unlock(&devfreq_list_lock);
dev_warn(&devfreq->dev, "releasing devfreq which doesn't exist\n");
return;
}
list_del(&devfreq->node);
mutex_unlock(&devfreq_list_lock);
if (devfreq->governor)
devfreq->governor->event_handler(devfreq,
DEVFREQ_GOV_STOP, NULL);
if (devfreq->profile->exit)
devfreq->profile->exit(devfreq->dev.parent);
mutex_destroy(&devfreq->lock);
kfree(devfreq);
}
static void devfreq_dev_release(struct device *dev)
{
struct devfreq *devfreq = to_devfreq(dev);
_remove_devfreq(devfreq);
}
struct devfreq *devfreq_add_device(struct device *dev,
struct devfreq_dev_profile *profile,
const char *governor_name,
void *data)
{
struct devfreq *devfreq;
struct devfreq_governor *governor;
int err = 0;
if (!dev || !profile || !governor_name) {
dev_err(dev, "%s: Invalid parameters.\n", __func__);
return ERR_PTR(-EINVAL);
}
mutex_lock(&devfreq_list_lock);
devfreq = find_device_devfreq(dev);
mutex_unlock(&devfreq_list_lock);
if (!IS_ERR(devfreq)) {
dev_err(dev, "%s: Unable to create devfreq for the device. It already has one.\n", __func__);
err = -EINVAL;
goto err_out;
}
devfreq = kzalloc(sizeof(struct devfreq), GFP_KERNEL);
if (!devfreq) {
dev_err(dev, "%s: Unable to create devfreq for the device\n",
__func__);
err = -ENOMEM;
goto err_out;
}
mutex_init(&devfreq->lock);
mutex_lock(&devfreq->lock);
devfreq->dev.parent = dev;
devfreq->dev.class = devfreq_class;
devfreq->dev.release = devfreq_dev_release;
devfreq->profile = profile;
strncpy(devfreq->governor_name, governor_name, DEVFREQ_NAME_LEN);
devfreq->previous_freq = profile->initial_freq;
devfreq->last_status.current_frequency = profile->initial_freq;
devfreq->data = data;
devfreq->nb.notifier_call = devfreq_notifier_call;
if (!devfreq->profile->max_state && !devfreq->profile->freq_table) {
mutex_unlock(&devfreq->lock);
devfreq_set_freq_table(devfreq);
mutex_lock(&devfreq->lock);
}
dev_set_name(&devfreq->dev, "%s", dev_name(dev));
err = device_register(&devfreq->dev);
if (err) {
mutex_unlock(&devfreq->lock);
goto err_out;
}
devfreq->trans_table = devm_kzalloc(&devfreq->dev, sizeof(unsigned int) *
devfreq->profile->max_state *
devfreq->profile->max_state,
GFP_KERNEL);
devfreq->time_in_state = devm_kzalloc(&devfreq->dev, sizeof(unsigned long) *
devfreq->profile->max_state,
GFP_KERNEL);
devfreq->last_stat_updated = jiffies;
srcu_init_notifier_head(&devfreq->transition_notifier_list);
mutex_unlock(&devfreq->lock);
mutex_lock(&devfreq_list_lock);
list_add(&devfreq->node, &devfreq_list);
governor = find_devfreq_governor(devfreq->governor_name);
if (!IS_ERR(governor))
devfreq->governor = governor;
if (devfreq->governor)
err = devfreq->governor->event_handler(devfreq,
DEVFREQ_GOV_START, NULL);
mutex_unlock(&devfreq_list_lock);
if (err) {
dev_err(dev, "%s: Unable to start governor for the device\n",
__func__);
goto err_init;
}
return devfreq;
err_init:
list_del(&devfreq->node);
device_unregister(&devfreq->dev);
err_out:
return ERR_PTR(err);
}
int devfreq_remove_device(struct devfreq *devfreq)
{
if (!devfreq)
return -EINVAL;
device_unregister(&devfreq->dev);
return 0;
}
static int devm_devfreq_dev_match(struct device *dev, void *res, void *data)
{
struct devfreq **r = res;
if (WARN_ON(!r || !*r))
return 0;
return *r == data;
}
static void devm_devfreq_dev_release(struct device *dev, void *res)
{
devfreq_remove_device(*(struct devfreq **)res);
}
struct devfreq *devm_devfreq_add_device(struct device *dev,
struct devfreq_dev_profile *profile,
const char *governor_name,
void *data)
{
struct devfreq **ptr, *devfreq;
ptr = devres_alloc(devm_devfreq_dev_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
devfreq = devfreq_add_device(dev, profile, governor_name, data);
if (IS_ERR(devfreq)) {
devres_free(ptr);
return ERR_PTR(-ENOMEM);
}
*ptr = devfreq;
devres_add(dev, ptr);
return devfreq;
}
struct devfreq *devfreq_get_devfreq_by_phandle(struct device *dev, int index)
{
struct device_node *node;
struct devfreq *devfreq;
if (!dev)
return ERR_PTR(-EINVAL);
if (!dev->of_node)
return ERR_PTR(-EINVAL);
node = of_parse_phandle(dev->of_node, "devfreq", index);
if (!node)
return ERR_PTR(-ENODEV);
mutex_lock(&devfreq_list_lock);
list_for_each_entry(devfreq, &devfreq_list, node) {
if (devfreq->dev.parent
&& devfreq->dev.parent->of_node == node) {
mutex_unlock(&devfreq_list_lock);
return devfreq;
}
}
mutex_unlock(&devfreq_list_lock);
return ERR_PTR(-EPROBE_DEFER);
}
struct devfreq *devfreq_get_devfreq_by_phandle(struct device *dev, int index)
{
return ERR_PTR(-ENODEV);
}
void devm_devfreq_remove_device(struct device *dev, struct devfreq *devfreq)
{
WARN_ON(devres_release(dev, devm_devfreq_dev_release,
devm_devfreq_dev_match, devfreq));
}
int devfreq_suspend_device(struct devfreq *devfreq)
{
if (!devfreq)
return -EINVAL;
if (!devfreq->governor)
return 0;
return devfreq->governor->event_handler(devfreq,
DEVFREQ_GOV_SUSPEND, NULL);
}
int devfreq_resume_device(struct devfreq *devfreq)
{
if (!devfreq)
return -EINVAL;
if (!devfreq->governor)
return 0;
return devfreq->governor->event_handler(devfreq,
DEVFREQ_GOV_RESUME, NULL);
}
int devfreq_add_governor(struct devfreq_governor *governor)
{
struct devfreq_governor *g;
struct devfreq *devfreq;
int err = 0;
if (!governor) {
pr_err("%s: Invalid parameters.\n", __func__);
return -EINVAL;
}
mutex_lock(&devfreq_list_lock);
g = find_devfreq_governor(governor->name);
if (!IS_ERR(g)) {
pr_err("%s: governor %s already registered\n", __func__,
g->name);
err = -EINVAL;
goto err_out;
}
list_add(&governor->node, &devfreq_governor_list);
list_for_each_entry(devfreq, &devfreq_list, node) {
int ret = 0;
struct device *dev = devfreq->dev.parent;
if (!strncmp(devfreq->governor_name, governor->name,
DEVFREQ_NAME_LEN)) {
if (devfreq->governor) {
dev_warn(dev,
"%s: Governor %s already present\n",
__func__, devfreq->governor->name);
ret = devfreq->governor->event_handler(devfreq,
DEVFREQ_GOV_STOP, NULL);
if (ret) {
dev_warn(dev,
"%s: Governor %s stop = %d\n",
__func__,
devfreq->governor->name, ret);
}
}
devfreq->governor = governor;
ret = devfreq->governor->event_handler(devfreq,
DEVFREQ_GOV_START, NULL);
if (ret) {
dev_warn(dev, "%s: Governor %s start=%d\n",
__func__, devfreq->governor->name,
ret);
}
}
}
err_out:
mutex_unlock(&devfreq_list_lock);
return err;
}
int devfreq_remove_governor(struct devfreq_governor *governor)
{
struct devfreq_governor *g;
struct devfreq *devfreq;
int err = 0;
if (!governor) {
pr_err("%s: Invalid parameters.\n", __func__);
return -EINVAL;
}
mutex_lock(&devfreq_list_lock);
g = find_devfreq_governor(governor->name);
if (IS_ERR(g)) {
pr_err("%s: governor %s not registered\n", __func__,
governor->name);
err = PTR_ERR(g);
goto err_out;
}
list_for_each_entry(devfreq, &devfreq_list, node) {
int ret;
struct device *dev = devfreq->dev.parent;
if (!strncmp(devfreq->governor_name, governor->name,
DEVFREQ_NAME_LEN)) {
if (!devfreq->governor) {
dev_warn(dev, "%s: Governor %s NOT present\n",
__func__, governor->name);
continue;
}
ret = devfreq->governor->event_handler(devfreq,
DEVFREQ_GOV_STOP, NULL);
if (ret) {
dev_warn(dev, "%s: Governor %s stop=%d\n",
__func__, devfreq->governor->name,
ret);
}
devfreq->governor = NULL;
}
}
list_del(&governor->node);
err_out:
mutex_unlock(&devfreq_list_lock);
return err;
}
static ssize_t governor_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
if (!to_devfreq(dev)->governor)
return -EINVAL;
return sprintf(buf, "%s\n", to_devfreq(dev)->governor->name);
}
static ssize_t governor_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct devfreq *df = to_devfreq(dev);
int ret;
char str_governor[DEVFREQ_NAME_LEN + 1];
struct devfreq_governor *governor;
ret = sscanf(buf, "%" __stringify(DEVFREQ_NAME_LEN) "s", str_governor);
if (ret != 1)
return -EINVAL;
mutex_lock(&devfreq_list_lock);
governor = find_devfreq_governor(str_governor);
if (IS_ERR(governor)) {
ret = PTR_ERR(governor);
goto out;
}
if (df->governor == governor) {
ret = 0;
goto out;
}
if (df->governor) {
ret = df->governor->event_handler(df, DEVFREQ_GOV_STOP, NULL);
if (ret) {
dev_warn(dev, "%s: Governor %s not stopped(%d)\n",
__func__, df->governor->name, ret);
goto out;
}
}
df->governor = governor;
strncpy(df->governor_name, governor->name, DEVFREQ_NAME_LEN);
ret = df->governor->event_handler(df, DEVFREQ_GOV_START, NULL);
if (ret)
dev_warn(dev, "%s: Governor %s not started(%d)\n",
__func__, df->governor->name, ret);
out:
mutex_unlock(&devfreq_list_lock);
if (!ret)
ret = count;
return ret;
}
static ssize_t available_governors_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct devfreq_governor *tmp_governor;
ssize_t count = 0;
mutex_lock(&devfreq_list_lock);
list_for_each_entry(tmp_governor, &devfreq_governor_list, node)
count += scnprintf(&buf[count], (PAGE_SIZE - count - 2),
"%s ", tmp_governor->name);
mutex_unlock(&devfreq_list_lock);
if (count)
count--;
count += sprintf(&buf[count], "\n");
return count;
}
static ssize_t cur_freq_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
unsigned long freq;
struct devfreq *devfreq = to_devfreq(dev);
if (devfreq->profile->get_cur_freq &&
!devfreq->profile->get_cur_freq(devfreq->dev.parent, &freq))
return sprintf(buf, "%lu\n", freq);
return sprintf(buf, "%lu\n", devfreq->previous_freq);
}
static ssize_t target_freq_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%lu\n", to_devfreq(dev)->previous_freq);
}
static ssize_t polling_interval_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", to_devfreq(dev)->profile->polling_ms);
}
static ssize_t polling_interval_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct devfreq *df = to_devfreq(dev);
unsigned int value;
int ret;
if (!df->governor)
return -EINVAL;
ret = sscanf(buf, "%u", &value);
if (ret != 1)
return -EINVAL;
df->governor->event_handler(df, DEVFREQ_GOV_INTERVAL, &value);
ret = count;
return ret;
}
static ssize_t min_freq_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct devfreq *df = to_devfreq(dev);
unsigned long value;
int ret;
unsigned long max;
ret = sscanf(buf, "%lu", &value);
if (ret != 1)
return -EINVAL;
mutex_lock(&df->lock);
max = df->max_freq;
if (value && max && value > max) {
ret = -EINVAL;
goto unlock;
}
df->min_freq = value;
update_devfreq(df);
ret = count;
unlock:
mutex_unlock(&df->lock);
return ret;
}
static ssize_t max_freq_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct devfreq *df = to_devfreq(dev);
unsigned long value;
int ret;
unsigned long min;
ret = sscanf(buf, "%lu", &value);
if (ret != 1)
return -EINVAL;
mutex_lock(&df->lock);
min = df->min_freq;
if (value && min && value < min) {
ret = -EINVAL;
goto unlock;
}
df->max_freq = value;
update_devfreq(df);
ret = count;
unlock:
mutex_unlock(&df->lock);
return ret;
}
static ssize_t available_frequencies_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct devfreq *df = to_devfreq(d);
struct device *dev = df->dev.parent;
struct dev_pm_opp *opp;
ssize_t count = 0;
unsigned long freq = 0;
rcu_read_lock();
do {
opp = dev_pm_opp_find_freq_ceil(dev, &freq);
if (IS_ERR(opp))
break;
count += scnprintf(&buf[count], (PAGE_SIZE - count - 2),
"%lu ", freq);
freq++;
} while (1);
rcu_read_unlock();
if (count)
count--;
count += sprintf(&buf[count], "\n");
return count;
}
static ssize_t trans_stat_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct devfreq *devfreq = to_devfreq(dev);
ssize_t len;
int i, j;
unsigned int max_state = devfreq->profile->max_state;
if (!devfreq->stop_polling &&
devfreq_update_status(devfreq, devfreq->previous_freq))
return 0;
if (max_state == 0)
return sprintf(buf, "Not Supported.\n");
len = sprintf(buf, " From : To\n");
len += sprintf(buf + len, " :");
for (i = 0; i < max_state; i++)
len += sprintf(buf + len, "%10lu",
devfreq->profile->freq_table[i]);
len += sprintf(buf + len, " time(ms)\n");
for (i = 0; i < max_state; i++) {
if (devfreq->profile->freq_table[i]
== devfreq->previous_freq) {
len += sprintf(buf + len, "*");
} else {
len += sprintf(buf + len, " ");
}
len += sprintf(buf + len, "%10lu:",
devfreq->profile->freq_table[i]);
for (j = 0; j < max_state; j++)
len += sprintf(buf + len, "%10u",
devfreq->trans_table[(i * max_state) + j]);
len += sprintf(buf + len, "%10u\n",
jiffies_to_msecs(devfreq->time_in_state[i]));
}
len += sprintf(buf + len, "Total transition : %u\n",
devfreq->total_trans);
return len;
}
static int __init devfreq_init(void)
{
devfreq_class = class_create(THIS_MODULE, "devfreq");
if (IS_ERR(devfreq_class)) {
pr_err("%s: couldn't create class\n", __FILE__);
return PTR_ERR(devfreq_class);
}
devfreq_wq = create_freezable_workqueue("devfreq_wq");
if (!devfreq_wq) {
class_destroy(devfreq_class);
pr_err("%s: couldn't create workqueue\n", __FILE__);
return -ENOMEM;
}
devfreq_class->dev_groups = devfreq_groups;
return 0;
}
static void __exit devfreq_exit(void)
{
class_destroy(devfreq_class);
destroy_workqueue(devfreq_wq);
}
struct dev_pm_opp *devfreq_recommended_opp(struct device *dev,
unsigned long *freq,
u32 flags)
{
struct dev_pm_opp *opp;
if (flags & DEVFREQ_FLAG_LEAST_UPPER_BOUND) {
opp = dev_pm_opp_find_freq_floor(dev, freq);
if (opp == ERR_PTR(-ERANGE))
opp = dev_pm_opp_find_freq_ceil(dev, freq);
} else {
opp = dev_pm_opp_find_freq_ceil(dev, freq);
if (opp == ERR_PTR(-ERANGE))
opp = dev_pm_opp_find_freq_floor(dev, freq);
}
return opp;
}
int devfreq_register_opp_notifier(struct device *dev, struct devfreq *devfreq)
{
struct srcu_notifier_head *nh;
int ret = 0;
rcu_read_lock();
nh = dev_pm_opp_get_notifier(dev);
if (IS_ERR(nh))
ret = PTR_ERR(nh);
rcu_read_unlock();
if (!ret)
ret = srcu_notifier_chain_register(nh, &devfreq->nb);
return ret;
}
int devfreq_unregister_opp_notifier(struct device *dev, struct devfreq *devfreq)
{
struct srcu_notifier_head *nh;
int ret = 0;
rcu_read_lock();
nh = dev_pm_opp_get_notifier(dev);
if (IS_ERR(nh))
ret = PTR_ERR(nh);
rcu_read_unlock();
if (!ret)
ret = srcu_notifier_chain_unregister(nh, &devfreq->nb);
return ret;
}
static void devm_devfreq_opp_release(struct device *dev, void *res)
{
devfreq_unregister_opp_notifier(dev, *(struct devfreq **)res);
}
int devm_devfreq_register_opp_notifier(struct device *dev,
struct devfreq *devfreq)
{
struct devfreq **ptr;
int ret;
ptr = devres_alloc(devm_devfreq_opp_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return -ENOMEM;
ret = devfreq_register_opp_notifier(dev, devfreq);
if (ret) {
devres_free(ptr);
return ret;
}
*ptr = devfreq;
devres_add(dev, ptr);
return 0;
}
void devm_devfreq_unregister_opp_notifier(struct device *dev,
struct devfreq *devfreq)
{
WARN_ON(devres_release(dev, devm_devfreq_opp_release,
devm_devfreq_dev_match, devfreq));
}
int devfreq_register_notifier(struct devfreq *devfreq,
struct notifier_block *nb,
unsigned int list)
{
int ret = 0;
if (!devfreq)
return -EINVAL;
switch (list) {
case DEVFREQ_TRANSITION_NOTIFIER:
ret = srcu_notifier_chain_register(
&devfreq->transition_notifier_list, nb);
break;
default:
ret = -EINVAL;
}
return ret;
}
int devfreq_unregister_notifier(struct devfreq *devfreq,
struct notifier_block *nb,
unsigned int list)
{
int ret = 0;
if (!devfreq)
return -EINVAL;
switch (list) {
case DEVFREQ_TRANSITION_NOTIFIER:
ret = srcu_notifier_chain_unregister(
&devfreq->transition_notifier_list, nb);
break;
default:
ret = -EINVAL;
}
return ret;
}
static void devm_devfreq_notifier_release(struct device *dev, void *res)
{
struct devfreq_notifier_devres *this = res;
devfreq_unregister_notifier(this->devfreq, this->nb, this->list);
}
int devm_devfreq_register_notifier(struct device *dev,
struct devfreq *devfreq,
struct notifier_block *nb,
unsigned int list)
{
struct devfreq_notifier_devres *ptr;
int ret;
ptr = devres_alloc(devm_devfreq_notifier_release, sizeof(*ptr),
GFP_KERNEL);
if (!ptr)
return -ENOMEM;
ret = devfreq_register_notifier(devfreq, nb, list);
if (ret) {
devres_free(ptr);
return ret;
}
ptr->devfreq = devfreq;
ptr->nb = nb;
ptr->list = list;
devres_add(dev, ptr);
return 0;
}
void devm_devfreq_unregister_notifier(struct device *dev,
struct devfreq *devfreq,
struct notifier_block *nb,
unsigned int list)
{
WARN_ON(devres_release(dev, devm_devfreq_notifier_release,
devm_devfreq_dev_match, devfreq));
}
