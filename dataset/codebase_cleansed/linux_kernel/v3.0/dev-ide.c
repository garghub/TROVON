void s3c_ide_set_platdata(struct s3c_ide_platdata *pdata)
{
s3c_set_platdata(pdata, sizeof(struct s3c_ide_platdata),
&s3c_device_cfcon);
}
