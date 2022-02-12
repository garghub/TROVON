static int devfreq_simple_ondemand_func(struct devfreq *df,
unsigned long *freq)
{
struct devfreq_dev_status stat;
int err = df->profile->get_dev_status(df->dev.parent, &stat);
unsigned long long a, b;
unsigned int dfso_upthreshold = DFSO_UPTHRESHOLD;
unsigned int dfso_downdifferential = DFSO_DOWNDIFFERENCTIAL;
struct devfreq_simple_ondemand_data *data = df->data;
if (err)
return err;
if (data) {
if (data->upthreshold)
dfso_upthreshold = data->upthreshold;
if (data->downdifferential)
dfso_downdifferential = data->downdifferential;
}
if (dfso_upthreshold > 100 ||
dfso_upthreshold < dfso_downdifferential)
return -EINVAL;
if (stat.total_time == 0) {
*freq = UINT_MAX;
return 0;
}
if (stat.busy_time >= (1 << 24) || stat.total_time >= (1 << 24)) {
stat.busy_time >>= 7;
stat.total_time >>= 7;
}
if (stat.busy_time * 100 >
stat.total_time * dfso_upthreshold) {
*freq = UINT_MAX;
return 0;
}
if (stat.current_frequency == 0) {
*freq = UINT_MAX;
return 0;
}
if (stat.busy_time * 100 >
stat.total_time * (dfso_upthreshold - dfso_downdifferential)) {
*freq = stat.current_frequency;
return 0;
}
a = stat.busy_time;
a *= stat.current_frequency;
b = div_u64(a, stat.total_time);
b *= 100;
b = div_u64(b, (dfso_upthreshold - dfso_downdifferential / 2));
*freq = (unsigned long) b;
return 0;
}
