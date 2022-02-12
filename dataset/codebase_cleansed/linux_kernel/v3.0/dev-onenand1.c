void s3c64xx_onenand1_set_platdata(struct onenand_platform_data *pdata)
{
struct onenand_platform_data *pd;
pd = kmemdup(pdata, sizeof(struct onenand_platform_data), GFP_KERNEL);
if (!pd)
printk(KERN_ERR "%s: no memory for platform data\n", __func__);
s3c64xx_device_onenand1.dev.platform_data = pd;
}
