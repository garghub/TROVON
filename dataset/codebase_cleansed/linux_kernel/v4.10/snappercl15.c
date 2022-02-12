static void snappercl15_nand_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *chip = mtd_to_nand(mtd);
static u16 nand_state = SNAPPERCL15_NAND_WPN;
u16 set;
if (ctrl & NAND_CTRL_CHANGE) {
set = SNAPPERCL15_NAND_CEN | SNAPPERCL15_NAND_WPN;
if (ctrl & NAND_NCE)
set &= ~SNAPPERCL15_NAND_CEN;
if (ctrl & NAND_CLE)
set |= SNAPPERCL15_NAND_CLE;
if (ctrl & NAND_ALE)
set |= SNAPPERCL15_NAND_ALE;
nand_state &= ~(SNAPPERCL15_NAND_CEN |
SNAPPERCL15_NAND_CLE |
SNAPPERCL15_NAND_ALE);
nand_state |= set;
__raw_writew(nand_state, NAND_CTRL_ADDR(chip));
}
if (cmd != NAND_CMD_NONE)
__raw_writew((cmd & 0xff) | nand_state, chip->IO_ADDR_W);
}
static int snappercl15_nand_dev_ready(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
return !!(__raw_readw(NAND_CTRL_ADDR(chip)) & SNAPPERCL15_NAND_RDY);
}
static void __init snappercl15_register_audio(void)
{
ep93xx_register_i2s();
platform_device_register(&snappercl15_audio_device);
}
static void __init snappercl15_init_machine(void)
{
ep93xx_init_devices();
ep93xx_register_eth(&snappercl15_eth_data, 1);
ep93xx_register_i2c(&snappercl15_i2c_gpio_data, snappercl15_i2c_data,
ARRAY_SIZE(snappercl15_i2c_data));
ep93xx_register_fb(&snappercl15_fb_info);
snappercl15_register_audio();
platform_device_register(&snappercl15_nand_device);
}
