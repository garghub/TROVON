struct platform_device *__init
mxs_add_gpmi_nand(const struct gpmi_nand_platform_data *pdata,
const struct mxs_gpmi_nand_data *data)
{
return mxs_add_platform_device_dmamask(data->devid, -1,
data->res, GPMI_NAND_RES_SIZE,
pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
