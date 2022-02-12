static int devfreq_passive_get_target_freq(struct devfreq *devfreq,
unsigned long *freq)
{
struct devfreq_passive_data *p_data
= (struct devfreq_passive_data *)devfreq->data;
struct devfreq *parent_devfreq = (struct devfreq *)p_data->parent;
unsigned long child_freq = ULONG_MAX;
struct dev_pm_opp *opp;
int i, count, ret = 0;
if (p_data->get_target_freq) {
ret = p_data->get_target_freq(devfreq, freq);
goto out;
}
if (!devfreq->profile || !devfreq->profile->freq_table
|| devfreq->profile->max_state <= 0)
return -EINVAL;
opp = devfreq_recommended_opp(parent_devfreq->dev.parent, freq, 0);
if (IS_ERR(opp)) {
ret = PTR_ERR(opp);
goto out;
}
dev_pm_opp_put(opp);
for (i = 0; i < parent_devfreq->profile->max_state; i++)
if (parent_devfreq->profile->freq_table[i] == *freq)
break;
if (i == parent_devfreq->profile->max_state) {
ret = -EINVAL;
goto out;
}
if (i < devfreq->profile->max_state) {
child_freq = devfreq->profile->freq_table[i];
} else {
count = devfreq->profile->max_state;
child_freq = devfreq->profile->freq_table[count - 1];
}
*freq = child_freq;
out:
return ret;
}
static int update_devfreq_passive(struct devfreq *devfreq, unsigned long freq)
{
int ret;
if (!devfreq->governor)
return -EINVAL;
mutex_lock_nested(&devfreq->lock, SINGLE_DEPTH_NESTING);
ret = devfreq->governor->get_target_freq(devfreq, &freq);
if (ret < 0)
goto out;
ret = devfreq->profile->target(devfreq->dev.parent, &freq, 0);
if (ret < 0)
goto out;
if (devfreq->profile->freq_table
&& (devfreq_update_status(devfreq, freq)))
dev_err(&devfreq->dev,
"Couldn't update frequency transition information.\n");
devfreq->previous_freq = freq;
out:
mutex_unlock(&devfreq->lock);
return 0;
}
static int devfreq_passive_notifier_call(struct notifier_block *nb,
unsigned long event, void *ptr)
{
struct devfreq_passive_data *data
= container_of(nb, struct devfreq_passive_data, nb);
struct devfreq *devfreq = (struct devfreq *)data->this;
struct devfreq *parent = (struct devfreq *)data->parent;
struct devfreq_freqs *freqs = (struct devfreq_freqs *)ptr;
unsigned long freq = freqs->new;
switch (event) {
case DEVFREQ_PRECHANGE:
if (parent->previous_freq > freq)
update_devfreq_passive(devfreq, freq);
break;
case DEVFREQ_POSTCHANGE:
if (parent->previous_freq < freq)
update_devfreq_passive(devfreq, freq);
break;
}
return NOTIFY_DONE;
}
static int devfreq_passive_event_handler(struct devfreq *devfreq,
unsigned int event, void *data)
{
struct device *dev = devfreq->dev.parent;
struct devfreq_passive_data *p_data
= (struct devfreq_passive_data *)devfreq->data;
struct devfreq *parent = (struct devfreq *)p_data->parent;
struct notifier_block *nb = &p_data->nb;
int ret = 0;
if (!parent)
return -EPROBE_DEFER;
switch (event) {
case DEVFREQ_GOV_START:
if (!p_data->this)
p_data->this = devfreq;
nb->notifier_call = devfreq_passive_notifier_call;
ret = devm_devfreq_register_notifier(dev, parent, nb,
DEVFREQ_TRANSITION_NOTIFIER);
break;
case DEVFREQ_GOV_STOP:
devm_devfreq_unregister_notifier(dev, parent, nb,
DEVFREQ_TRANSITION_NOTIFIER);
break;
default:
break;
}
return ret;
}
static int __init devfreq_passive_init(void)
{
return devfreq_add_governor(&devfreq_passive);
}
static void __exit devfreq_passive_exit(void)
{
int ret;
ret = devfreq_remove_governor(&devfreq_passive);
if (ret)
pr_err("%s: failed remove governor %d\n", __func__, ret);
}
