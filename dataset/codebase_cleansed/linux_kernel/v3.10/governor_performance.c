static int devfreq_performance_func(struct devfreq *df,
unsigned long *freq)
{
if (!df->max_freq)
*freq = UINT_MAX;
else
*freq = df->max_freq;
return 0;
}
static int devfreq_performance_handler(struct devfreq *devfreq,
unsigned int event, void *data)
{
int ret = 0;
if (event == DEVFREQ_GOV_START) {
mutex_lock(&devfreq->lock);
ret = update_devfreq(devfreq);
mutex_unlock(&devfreq->lock);
}
return ret;
}
static int __init devfreq_performance_init(void)
{
return devfreq_add_governor(&devfreq_performance);
}
static void __exit devfreq_performance_exit(void)
{
int ret;
ret = devfreq_remove_governor(&devfreq_performance);
if (ret)
pr_err("%s: failed remove governor %d\n", __func__, ret);
return;
}
