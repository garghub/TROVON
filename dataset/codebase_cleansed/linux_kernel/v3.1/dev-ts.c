void __init s3c24xx_ts_set_platdata(struct s3c2410_ts_mach_info *pd)
{
s3c_set_platdata(pd, sizeof(struct s3c2410_ts_mach_info),
&s3c_device_ts);
}
