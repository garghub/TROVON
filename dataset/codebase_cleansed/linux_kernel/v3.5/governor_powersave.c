static int devfreq_powersave_func(struct devfreq *df,
unsigned long *freq)
{
*freq = df->min_freq;
return 0;
}
static int powersave_init(struct devfreq *devfreq)
{
return update_devfreq(devfreq);
}
