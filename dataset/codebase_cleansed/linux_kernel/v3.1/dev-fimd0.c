void __init s5p_fimd0_set_platdata(struct s3c_fb_platdata *pd)
{
s3c_set_platdata(pd, sizeof(struct s3c_fb_platdata),
&s5p_device_fimd0);
}
