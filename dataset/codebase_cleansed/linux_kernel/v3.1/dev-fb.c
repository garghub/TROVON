void __init s3c_fb_set_platdata(struct s3c_fb_platdata *pd)
{
s3c_set_platdata(pd, sizeof(struct s3c_fb_platdata),
&s3c_device_fb);
}
