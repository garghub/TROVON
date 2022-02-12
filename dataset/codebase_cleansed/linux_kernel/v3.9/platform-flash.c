static void xlr_nand_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
if (ctrl & NAND_CLE)
nlm_write_reg(nand_priv.flash_mmio,
FLASH_NAND_CLE(nand_priv.cs), cmd);
else if (ctrl & NAND_ALE)
nlm_write_reg(nand_priv.flash_mmio,
FLASH_NAND_ALE(nand_priv.cs), cmd);
}
static void setup_flash_resource(uint64_t flash_mmio,
uint64_t flash_map_base, int cs, struct resource *res)
{
u32 base, mask;
base = nlm_read_reg(flash_mmio, FLASH_CSBASE_ADDR(cs));
mask = nlm_read_reg(flash_mmio, FLASH_CSADDR_MASK(cs));
res->start = flash_map_base + ((unsigned long)base << 16);
res->end = res->start + (mask + 1) * 64 * 1024;
}
static int __init xlr_flash_init(void)
{
uint64_t gpio_mmio, flash_mmio, flash_map_base;
u32 gpio_resetcfg, flash_bar;
int cs, boot_nand, boot_nor;
flash_bar = nlm_read_reg(nlm_io_base, BRIDGE_FLASH_BAR);
flash_map_base = (flash_bar & 0xffff0000) << 8;
gpio_mmio = nlm_mmio_base(NETLOGIC_IO_GPIO_OFFSET);
flash_mmio = nlm_mmio_base(NETLOGIC_IO_FLASH_OFFSET);
gpio_resetcfg = nlm_read_reg(gpio_mmio, GPIO_PWRON_RESET_CFG_REG);
boot_nor = boot_nand = 0;
if (nlm_chip_is_xls()) {
if (gpio_resetcfg & (1 << 16))
boot_nand = 1;
if ((gpio_resetcfg & (1 << 15)) == 0)
boot_nor = 1;
} else {
if ((gpio_resetcfg & (1 << 16)) == 0)
boot_nor = 1;
}
cs = 0;
if (boot_nand) {
nand_priv.cs = cs;
nand_priv.flash_mmio = flash_mmio;
setup_flash_resource(flash_mmio, flash_map_base, cs,
xlr_nand_res);
nlm_write_reg(flash_mmio, FLASH_CSDEV_PARM(cs),
FLASH_NAND_CSDEV_PARAM);
nlm_write_reg(flash_mmio, FLASH_CSTIME_PARMA(cs),
FLASH_NAND_CSTIME_PARAMA);
nlm_write_reg(flash_mmio, FLASH_CSTIME_PARMB(cs),
FLASH_NAND_CSTIME_PARAMB);
pr_info("ChipSelect %d: NAND Flash %pR\n", cs, xlr_nand_res);
return platform_device_register(&xlr_nand_dev);
}
if (boot_nor) {
setup_flash_resource(flash_mmio, flash_map_base, cs,
xlr_nor_res);
pr_info("ChipSelect %d: NOR Flash %pR\n", cs, xlr_nor_res);
return platform_device_register(&xlr_nor_dev);
}
return 0;
}
