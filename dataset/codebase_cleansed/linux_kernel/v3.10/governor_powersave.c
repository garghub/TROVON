static int devfreq_powersave_func(struct devfreq *df,
unsigned long *freq)
{
*freq = df->min_freq;
return 0;
}
static int devfreq_powersave_handler(struct devfreq *devfreq,
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
static int __init devfreq_powersave_init(void)
{
return devfreq_add_governor(&devfreq_powersave);
}
static void __exit devfreq_powersave_exit(void)
{
int ret;
ret = devfreq_remove_governor(&devfreq_powersave);
if (ret)
pr_err("%s: failed remove governor %d\n", __func__, ret);
return;
}
