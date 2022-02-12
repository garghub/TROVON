static int mop500_sdi0_ios_handler(struct device *dev, struct mmc_ios *ios)
{
switch (ios->power_mode) {
case MMC_POWER_UP:
case MMC_POWER_ON:
gpio_direction_output(sdi0_vsel, 0);
gpio_direction_output(sdi0_en, 1);
break;
case MMC_POWER_OFF:
gpio_direction_output(sdi0_vsel, 0);
gpio_direction_output(sdi0_en, 0);
break;
}
return 0;
}
static void sdi0_configure(struct device *parent)
{
int ret;
ret = gpio_request(sdi0_en, "level shifter enable");
if (!ret)
ret = gpio_request(sdi0_vsel,
"level shifter 1v8-3v select");
if (ret) {
pr_warning("unable to config sdi0 gpios for level shifter.\n");
return;
}
gpio_direction_output(sdi0_vsel, 0);
gpio_direction_output(sdi0_en, 1);
db8500_add_sdi0(parent, &mop500_sdi0_data, U8500_SDI_V2_PERIPHID);
}
void mop500_sdi_tc35892_init(struct device *parent)
{
mop500_sdi0_data.gpio_cd = GPIO_SDMMC_CD;
sdi0_en = GPIO_SDMMC_EN;
sdi0_vsel = GPIO_SDMMC_1V8_3V_SEL;
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
sdi0_en = SNOWBALL_SDMMC_EN_GPIO;
sdi0_vsel = SNOWBALL_SDMMC_1V8_3V_GPIO;
sdi0_configure(parent);
}
void __init hrefv60_sdi_init(struct device *parent)
{
db8500_add_sdi2(parent, &mop500_sdi2_data, U8500_SDI_V2_PERIPHID);
db8500_add_sdi4(parent, &mop500_sdi4_data, U8500_SDI_V2_PERIPHID);
mop500_sdi0_data.gpio_cd = HREFV60_SDMMC_CD_GPIO;
sdi0_en = HREFV60_SDMMC_EN_GPIO;
sdi0_vsel = HREFV60_SDMMC_1V8_3V_GPIO;
sdi0_configure(parent);
db8500_add_sdi1(parent, &mop500_sdi1_data, U8500_SDI_V2_PERIPHID);
}
