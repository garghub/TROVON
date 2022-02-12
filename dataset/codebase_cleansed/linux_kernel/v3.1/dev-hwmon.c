void __init s3c_hwmon_set_platdata(struct s3c_hwmon_pdata *pd)
{
s3c_set_platdata(pd, sizeof(struct s3c_hwmon_pdata),
&s3c_device_hwmon);
}
