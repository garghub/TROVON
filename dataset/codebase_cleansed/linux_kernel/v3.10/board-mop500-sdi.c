static void sdi0_configure(struct device *parent)
{
db8500_add_sdi0(parent, &mop500_sdi0_data, U8500_SDI_V2_PERIPHID);
}
void mop500_sdi_tc35892_init(struct device *parent)
{
mop500_sdi0_data.gpio_cd = GPIO_SDMMC_CD;
sdi0_configure(parent);
}
void __init mop500_sdi_init(struct device *parent)
{
db8500_add_sdi2(parent, &mop500_sdi2_data, U8500_SDI_V2_PERIPHID);
db8500_add_sdi4(parent, &mop500_sdi4_data, U8500_SDI_V2_PERIPHID);
}
void __init snowball_sdi_init(struct device *parent)
{
mop500_sdi0_data.capabilities &= ~MMC_CAP_SD_HIGHSPEED;
db8500_add_sdi4(parent, &mop500_sdi4_data, U8500_SDI_V2_PERIPHID);
mop500_sdi0_data.gpio_cd = SNOWBALL_SDMMC_CD_GPIO;
mop500_sdi0_data.cd_invert = true;
sdi0_configure(parent);
}
void __init hrefv60_sdi_init(struct device *parent)
{
db8500_add_sdi2(parent, &mop500_sdi2_data, U8500_SDI_V2_PERIPHID);
db8500_add_sdi4(parent, &mop500_sdi4_data, U8500_SDI_V2_PERIPHID);
mop500_sdi0_data.gpio_cd = HREFV60_SDMMC_CD_GPIO;
sdi0_configure(parent);
db8500_add_sdi1(parent, &mop500_sdi1_data, U8500_SDI_V2_PERIPHID);
}
