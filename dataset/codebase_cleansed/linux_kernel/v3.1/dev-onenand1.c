void s3c64xx_onenand1_set_platdata(struct onenand_platform_data *pdata)
{
s3c_set_platdata(pdata, sizeof(struct onenand_platform_data),
&s3c64xx_device_onenand1);
}
