static int devfreq_performance_func(struct devfreq *df,
unsigned long *freq)
{
*freq = UINT_MAX;
return 0;
}
