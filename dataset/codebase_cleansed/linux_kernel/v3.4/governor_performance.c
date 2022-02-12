static int devfreq_performance_func(struct devfreq *df,
unsigned long *freq)
{
if (!df->max_freq)
*freq = UINT_MAX;
else
*freq = df->max_freq;
return 0;
}
