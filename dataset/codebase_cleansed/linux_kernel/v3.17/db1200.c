static int __init db1200_detect_board(void)
{
int bid;
bcsr_init(DB1200_BCSR_PHYS_ADDR,
DB1200_BCSR_PHYS_ADDR + DB1200_BCSR_HEXLED_OFS);
if (BCSR_WHOAMI_DB1200 == BCSR_WHOAMI_BOARD(bcsr_read(BCSR_WHOAMI))) {
unsigned short t = bcsr_read(BCSR_HEXLEDS);
bcsr_write(BCSR_HEXLEDS, ~t);
if (bcsr_read(BCSR_HEXLEDS) != t) {
bcsr_write(BCSR_HEXLEDS, t);
return 0;
}
}
bcsr_init(PB1200_BCSR_PHYS_ADDR,
PB1200_BCSR_PHYS_ADDR + PB1200_BCSR_HEXLED_OFS);
bid = BCSR_WHOAMI_BOARD(bcsr_read(BCSR_WHOAMI));
if ((bid == BCSR_WHOAMI_PB1200_DDR1) ||
(bid == BCSR_WHOAMI_PB1200_DDR2)) {
unsigned short t = bcsr_read(BCSR_HEXLEDS);
bcsr_write(BCSR_HEXLEDS, ~t);
if (bcsr_read(BCSR_HEXLEDS) != t) {
bcsr_write(BCSR_HEXLEDS, t);
return 0;
}
}
return 1;
}
int __init db1200_board_setup(void)
{
unsigned short whoami;
if (db1200_detect_board())
return -ENODEV;
whoami = bcsr_read(BCSR_WHOAMI);
switch (BCSR_WHOAMI_BOARD(whoami)) {
case BCSR_WHOAMI_PB1200_DDR1:
case BCSR_WHOAMI_PB1200_DDR2:
case BCSR_WHOAMI_DB1200:
break;
default:
return -ENODEV;
}
printk(KERN_INFO "Alchemy/AMD/RMI %s Board, CPLD Rev %d"
" Board-ID %d Daughtercard ID %d\n", get_system_type(),
(whoami >> 4) & 0xf, (whoami >> 8) & 0xf, whoami & 0xf);
return 0;
}
static void au1200_nand_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
unsigned long ioaddr = (unsigned long)this->IO_ADDR_W;
ioaddr &= 0xffffff00;
if (ctrl & NAND_CLE) {
ioaddr += MEM_STNAND_CMD;
} else if (ctrl & NAND_ALE) {
ioaddr += MEM_STNAND_ADDR;
} else {
ioaddr += MEM_STNAND_DATA;
}
this->IO_ADDR_R = this->IO_ADDR_W = (void __iomem *)ioaddr;
if (cmd != NAND_CMD_NONE) {
__raw_writeb(cmd, this->IO_ADDR_W);
wmb();
}
}
static int au1200_nand_device_ready(struct mtd_info *mtd)
{
return alchemy_rdsmem(AU1000_MEM_STSTAT) & 1;
}
static irqreturn_t db1200_mmc_cd(int irq, void *ptr)
{
void(*mmc_cd)(struct mmc_host *, unsigned long);
if (irq == DB1200_SD0_INSERT_INT) {
disable_irq_nosync(DB1200_SD0_INSERT_INT);
enable_irq(DB1200_SD0_EJECT_INT);
} else {
disable_irq_nosync(DB1200_SD0_EJECT_INT);
enable_irq(DB1200_SD0_INSERT_INT);
}
mmc_cd = symbol_get(mmc_detect_change);
if (mmc_cd) {
mmc_cd(ptr, msecs_to_jiffies(500));
symbol_put(mmc_detect_change);
}
return IRQ_HANDLED;
}
static int db1200_mmc_cd_setup(void *mmc_host, int en)
{
int ret;
if (en) {
ret = request_irq(DB1200_SD0_INSERT_INT, db1200_mmc_cd,
0, "sd_insert", mmc_host);
if (ret)
goto out;
ret = request_irq(DB1200_SD0_EJECT_INT, db1200_mmc_cd,
0, "sd_eject", mmc_host);
if (ret) {
free_irq(DB1200_SD0_INSERT_INT, mmc_host);
goto out;
}
if (bcsr_read(BCSR_SIGSTAT) & BCSR_INT_SD0INSERT)
enable_irq(DB1200_SD0_EJECT_INT);
else
enable_irq(DB1200_SD0_INSERT_INT);
} else {
free_irq(DB1200_SD0_INSERT_INT, mmc_host);
free_irq(DB1200_SD0_EJECT_INT, mmc_host);
}
ret = 0;
out:
return ret;
}
static void db1200_mmc_set_power(void *mmc_host, int state)
{
if (state) {
bcsr_mod(BCSR_BOARD, 0, BCSR_BOARD_SD0PWR);
msleep(400);
} else
bcsr_mod(BCSR_BOARD, BCSR_BOARD_SD0PWR, 0);
}
static int db1200_mmc_card_readonly(void *mmc_host)
{
return (bcsr_read(BCSR_STATUS) & BCSR_STATUS_SD0WP) ? 1 : 0;
}
static int db1200_mmc_card_inserted(void *mmc_host)
{
return (bcsr_read(BCSR_SIGSTAT) & BCSR_INT_SD0INSERT) ? 1 : 0;
}
static void db1200_mmcled_set(struct led_classdev *led,
enum led_brightness brightness)
{
if (brightness != LED_OFF)
bcsr_mod(BCSR_LEDS, BCSR_LEDS_LED0, 0);
else
bcsr_mod(BCSR_LEDS, 0, BCSR_LEDS_LED0);
}
static irqreturn_t pb1200_mmc1_cd(int irq, void *ptr)
{
void(*mmc_cd)(struct mmc_host *, unsigned long);
if (irq == PB1200_SD1_INSERT_INT) {
disable_irq_nosync(PB1200_SD1_INSERT_INT);
enable_irq(PB1200_SD1_EJECT_INT);
} else {
disable_irq_nosync(PB1200_SD1_EJECT_INT);
enable_irq(PB1200_SD1_INSERT_INT);
}
mmc_cd = symbol_get(mmc_detect_change);
if (mmc_cd) {
mmc_cd(ptr, msecs_to_jiffies(500));
symbol_put(mmc_detect_change);
}
return IRQ_HANDLED;
}
static int pb1200_mmc1_cd_setup(void *mmc_host, int en)
{
int ret;
if (en) {
ret = request_irq(PB1200_SD1_INSERT_INT, pb1200_mmc1_cd, 0,
"sd1_insert", mmc_host);
if (ret)
goto out;
ret = request_irq(PB1200_SD1_EJECT_INT, pb1200_mmc1_cd, 0,
"sd1_eject", mmc_host);
if (ret) {
free_irq(PB1200_SD1_INSERT_INT, mmc_host);
goto out;
}
if (bcsr_read(BCSR_SIGSTAT) & BCSR_INT_SD1INSERT)
enable_irq(PB1200_SD1_EJECT_INT);
else
enable_irq(PB1200_SD1_INSERT_INT);
} else {
free_irq(PB1200_SD1_INSERT_INT, mmc_host);
free_irq(PB1200_SD1_EJECT_INT, mmc_host);
}
ret = 0;
out:
return ret;
}
static void pb1200_mmc1led_set(struct led_classdev *led,
enum led_brightness brightness)
{
if (brightness != LED_OFF)
bcsr_mod(BCSR_LEDS, BCSR_LEDS_LED1, 0);
else
bcsr_mod(BCSR_LEDS, 0, BCSR_LEDS_LED1);
}
static void pb1200_mmc1_set_power(void *mmc_host, int state)
{
if (state) {
bcsr_mod(BCSR_BOARD, 0, BCSR_BOARD_SD1PWR);
msleep(400);
} else
bcsr_mod(BCSR_BOARD, BCSR_BOARD_SD1PWR, 0);
}
static int pb1200_mmc1_card_readonly(void *mmc_host)
{
return (bcsr_read(BCSR_STATUS) & BCSR_STATUS_SD1WP) ? 1 : 0;
}
static int pb1200_mmc1_card_inserted(void *mmc_host)
{
return (bcsr_read(BCSR_SIGSTAT) & BCSR_INT_SD1INSERT) ? 1 : 0;
}
static int db1200fb_panel_index(void)
{
return (bcsr_read(BCSR_SWITCHES) >> 8) & 0x0f;
}
static int db1200fb_panel_init(void)
{
bcsr_mod(BCSR_BOARD, 0, BCSR_BOARD_LCDVEE | BCSR_BOARD_LCDVDD |
BCSR_BOARD_LCDBL);
return 0;
}
static int db1200fb_panel_shutdown(void)
{
bcsr_mod(BCSR_BOARD, BCSR_BOARD_LCDVEE | BCSR_BOARD_LCDVDD |
BCSR_BOARD_LCDBL, 0);
return 0;
}
static void db1200_spi_cs_en(struct au1550_spi_info *spi, int cs, int pol)
{
if (cs)
bcsr_mod(BCSR_RESETS, 0, BCSR_RESETS_SPISEL);
else
bcsr_mod(BCSR_RESETS, BCSR_RESETS_SPISEL, 0);
}
static int __init pb1200_res_fixup(void)
{
if (BCSR_WHOAMI_CPLD(bcsr_read(BCSR_WHOAMI)) <= 3) {
printk(KERN_ERR "WARNING!!!\n");
printk(KERN_ERR "WARNING!!!\n");
printk(KERN_ERR "PB1200 must be at CPLD rev 4. Please have\n");
printk(KERN_ERR "the board updated to latest revisions.\n");
printk(KERN_ERR "This software will not work reliably\n");
printk(KERN_ERR "on anything older than CPLD rev 4.!\n");
printk(KERN_ERR "WARNING!!!\n");
printk(KERN_ERR "WARNING!!!\n");
return 1;
}
db1200_nand_res[0].start = PB1200_NAND_PHYS_ADDR;
db1200_nand_res[0].end = PB1200_NAND_PHYS_ADDR + 0xff;
db1200_ide_res[0].start = PB1200_IDE_PHYS_ADDR;
db1200_ide_res[0].end = PB1200_IDE_PHYS_ADDR + DB1200_IDE_PHYS_LEN - 1;
db1200_eth_res[0].start = PB1200_ETH_PHYS_ADDR;
db1200_eth_res[0].end = PB1200_ETH_PHYS_ADDR + 0xff;
return 0;
}
int __init db1200_dev_setup(void)
{
unsigned long pfc;
unsigned short sw;
int swapped, bid;
struct clk *c;
bid = BCSR_WHOAMI_BOARD(bcsr_read(BCSR_WHOAMI));
if ((bid == BCSR_WHOAMI_PB1200_DDR1) ||
(bid == BCSR_WHOAMI_PB1200_DDR2)) {
if (pb1200_res_fixup())
return -ENODEV;
}
irq_set_irq_type(AU1200_GPIO7_INT, IRQ_TYPE_LEVEL_LOW);
bcsr_init_irq(DB1200_INT_BEGIN, DB1200_INT_END, AU1200_GPIO7_INT);
pfc = alchemy_rdsys(AU1000_SYS_PINFUNC);
pfc &= ~(SYS_PINFUNC_P0A | SYS_PINFUNC_P0B);
pfc &= ~(SYS_PINFUNC_P1A | SYS_PINFUNC_P1B | SYS_PINFUNC_FS3);
pfc |= SYS_PINFUNC_P1C;
alchemy_wrsys(pfc, AU1000_SYS_PINFUNC);
c = clk_get(NULL, "psc0_intclk");
if (!IS_ERR(c)) {
pfc = clk_round_rate(c, 50000000);
if ((pfc < 1) || (abs(50000000 - pfc) > 2500000))
pr_warn("DB1200: cant get I2C close to 50MHz\n");
else
clk_set_rate(c, pfc);
clk_prepare_enable(c);
clk_put(c);
}
irq_set_status_flags(DB1200_SD0_INSERT_INT, IRQ_NOAUTOEN);
irq_set_status_flags(DB1200_SD0_EJECT_INT, IRQ_NOAUTOEN);
irq_set_status_flags(DB1200_PC0_INSERT_INT, IRQ_NOAUTOEN);
irq_set_status_flags(DB1200_PC0_EJECT_INT, IRQ_NOAUTOEN);
irq_set_status_flags(DB1200_PC1_INSERT_INT, IRQ_NOAUTOEN);
irq_set_status_flags(DB1200_PC1_EJECT_INT, IRQ_NOAUTOEN);
i2c_register_board_info(0, db1200_i2c_devs,
ARRAY_SIZE(db1200_i2c_devs));
spi_register_board_info(db1200_spi_devs,
ARRAY_SIZE(db1200_i2c_devs));
pfc = alchemy_rdsys(AU1000_SYS_PINFUNC) & ~SYS_PINFUNC_P0A;
gpio_request(215, "otg-vbus");
gpio_direction_output(215, 1);
printk(KERN_INFO "%s device configuration:\n", get_system_type());
sw = bcsr_read(BCSR_SWITCHES);
if (sw & BCSR_SWITCHES_DIP_8) {
db1200_devs[0] = &db1200_i2c_dev;
bcsr_mod(BCSR_RESETS, BCSR_RESETS_PSC0MUX, 0);
pfc |= (2 << 17);
printk(KERN_INFO " S6.8 OFF: PSC0 mode I2C\n");
printk(KERN_INFO " OTG port VBUS supply available!\n");
} else {
db1200_devs[0] = &db1200_spi_dev;
bcsr_mod(BCSR_RESETS, 0, BCSR_RESETS_PSC0MUX);
pfc |= (1 << 17);
printk(KERN_INFO " S6.8 ON : PSC0 mode SPI\n");
printk(KERN_INFO " OTG port VBUS supply disabled\n");
}
alchemy_wrsys(pfc, AU1000_SYS_PINFUNC);
sw &= BCSR_SWITCHES_DIP_8 | BCSR_SWITCHES_DIP_7;
if (sw == BCSR_SWITCHES_DIP_8) {
bcsr_mod(BCSR_RESETS, 0, BCSR_RESETS_PSC1MUX);
db1200_audio_dev.name = "au1xpsc_i2s";
db1200_sound_dev.name = "db1200-i2s";
printk(KERN_INFO " S6.7 ON : PSC1 mode I2S\n");
} else {
bcsr_mod(BCSR_RESETS, BCSR_RESETS_PSC1MUX, 0);
db1200_audio_dev.name = "au1xpsc_ac97";
db1200_sound_dev.name = "db1200-ac97";
printk(KERN_INFO " S6.7 OFF: PSC1 mode AC97\n");
}
__raw_writel(PSC_SEL_CLK_SERCLK,
(void __iomem *)KSEG1ADDR(AU1550_PSC1_PHYS_ADDR) + PSC_SEL_OFFSET);
wmb();
db1x_register_pcmcia_socket(
AU1000_PCMCIA_ATTR_PHYS_ADDR,
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x000400000 - 1,
AU1000_PCMCIA_MEM_PHYS_ADDR,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x000400000 - 1,
AU1000_PCMCIA_IO_PHYS_ADDR,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x000010000 - 1,
DB1200_PC0_INT, DB1200_PC0_INSERT_INT,
0, DB1200_PC0_EJECT_INT, 0);
db1x_register_pcmcia_socket(
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x004000000,
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x004400000 - 1,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x004000000,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x004400000 - 1,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x004000000,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x004010000 - 1,
DB1200_PC1_INT, DB1200_PC1_INSERT_INT,
0, DB1200_PC1_EJECT_INT, 1);
swapped = bcsr_read(BCSR_STATUS) & BCSR_STATUS_DB1200_SWAPBOOT;
db1x_register_norflash(64 << 20, 2, swapped);
platform_add_devices(db1200_devs, ARRAY_SIZE(db1200_devs));
if ((bid == BCSR_WHOAMI_PB1200_DDR1) ||
(bid == BCSR_WHOAMI_PB1200_DDR2))
platform_add_devices(pb1200_devs, ARRAY_SIZE(pb1200_devs));
return 0;
}
