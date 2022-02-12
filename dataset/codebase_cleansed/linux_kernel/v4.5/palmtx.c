static void __init palmtx_nor_init(void)
{
platform_device_register(&palmtx_flash);
}
static inline void palmtx_nor_init(void) {}
static void __init palmtx_kpc_init(void)
{
pxa_set_keypad_info(&palmtx_keypad_platform_data);
}
static inline void palmtx_kpc_init(void) {}
static void __init palmtx_keys_init(void)
{
platform_device_register(&palmtx_pxa_keys);
}
static inline void palmtx_keys_init(void) {}
static void palmtx_nand_cmd_ctl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *this = mtd_to_nand(mtd);
char __iomem *nandaddr = this->IO_ADDR_W;
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
writeb(cmd, PALMTX_NAND_CLE_VIRT);
else if (ctrl & NAND_ALE)
writeb(cmd, PALMTX_NAND_ALE_VIRT);
else
writeb(cmd, nandaddr);
}
static void __init palmtx_nand_init(void)
{
platform_device_register(&palmtx_nand);
}
static inline void palmtx_nand_init(void) {}
static void __init palmtx_map_io(void)
{
pxa27x_map_io();
iotable_init(palmtx_io_desc, ARRAY_SIZE(palmtx_io_desc));
}
static void __init palmtx_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(palmtx_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
palm27x_mmc_init(GPIO_NR_PALMTX_SD_DETECT_N, GPIO_NR_PALMTX_SD_READONLY,
GPIO_NR_PALMTX_SD_POWER, 0);
palm27x_pm_init(PALMTX_STR_BASE);
palm27x_lcd_init(-1, &palm_320x480_lcd_mode);
palm27x_udc_init(GPIO_NR_PALMTX_USB_DETECT_N,
GPIO_NR_PALMTX_USB_PULLUP, 1);
palm27x_irda_init(GPIO_NR_PALMTX_IR_DISABLE);
palm27x_ac97_init(PALMTX_BAT_MIN_VOLTAGE, PALMTX_BAT_MAX_VOLTAGE,
GPIO_NR_PALMTX_EARPHONE_DETECT, 95);
palm27x_pwm_init(GPIO_NR_PALMTX_BL_POWER, GPIO_NR_PALMTX_LCD_POWER);
palm27x_power_init(GPIO_NR_PALMTX_POWER_DETECT, -1);
palm27x_pmic_init();
palmtx_kpc_init();
palmtx_keys_init();
palmtx_nor_init();
palmtx_nand_init();
}
