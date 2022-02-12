static u32 mop500_sdi0_vdd_handler(struct device *dev, unsigned int vdd,
unsigned char power_mode)
{
switch (power_mode) {
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
return MCI_FBCLKEN | MCI_CMDDIREN | MCI_DATA0DIREN |
MCI_DATA2DIREN | MCI_DATA31DIREN;
}
static void sdi0_configure(void)
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
if (cpu_is_u8500v2())
db8500_add_sdi0(&mop500_sdi0_data, 0x10480180);
else
db8500_add_sdi0(&mop500_sdi0_data, 0);
}
void mop500_sdi_tc35892_init(void)
{
mop500_sdi0_data.gpio_cd = GPIO_SDMMC_CD;
sdi0_en = GPIO_SDMMC_EN;
sdi0_vsel = GPIO_SDMMC_1V8_3V_SEL;
sdi0_configure();
}
void __init mop500_sdi_init(void)
{
u32 periphid = 0;
if (cpu_is_u8500v2())
periphid = 0x10480180;
if (!cpu_is_u8500v10())
mop500_sdi2_data.capabilities |= MMC_CAP_MMC_HIGHSPEED;
db8500_add_sdi2(&mop500_sdi2_data, periphid);
db8500_add_sdi4(&mop500_sdi4_data, periphid);
}
void __init snowball_sdi_init(void)
{
u32 periphid = 0x10480180;
mop500_sdi2_data.capabilities |= MMC_CAP_MMC_HIGHSPEED;
db8500_add_sdi4(&mop500_sdi4_data, periphid);
mop500_sdi0_data.gpio_cd = SNOWBALL_SDMMC_CD_GPIO;
mop500_sdi0_data.cd_invert = true;
sdi0_en = SNOWBALL_SDMMC_EN_GPIO;
sdi0_vsel = SNOWBALL_SDMMC_1V8_3V_GPIO;
sdi0_configure();
}
void __init hrefv60_sdi_init(void)
{
u32 periphid = 0x10480180;
mop500_sdi2_data.capabilities |= MMC_CAP_MMC_HIGHSPEED;
db8500_add_sdi2(&mop500_sdi2_data, periphid);
db8500_add_sdi4(&mop500_sdi4_data, periphid);
mop500_sdi0_data.gpio_cd = HREFV60_SDMMC_CD_GPIO;
sdi0_en = HREFV60_SDMMC_EN_GPIO;
sdi0_vsel = HREFV60_SDMMC_1V8_3V_GPIO;
sdi0_configure();
}
