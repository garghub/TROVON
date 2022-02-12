static void __init db1300_gpio_config(void)
{
int *i;
i = &db1300_dev_pins[0];
while (*i != -1)
au1300_pinfunc_to_dev(*i++);
i = &db1300_gpio_pins[0];
while (*i != -1)
au1300_gpio_direction_input(*i++);
au1300_set_dbdma_gpio(1, AU1300_PIN_FG3AUX);
}
static void au1300_nand_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *this = mtd_to_nand(mtd);
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
static int au1300_nand_device_ready(struct mtd_info *mtd)
{
return alchemy_rdsmem(AU1000_MEM_STSTAT) & 1;
}
static irqreturn_t db1300_mmc_cd(int irq, void *ptr)
{
void(*mmc_cd)(struct mmc_host *, unsigned long);
if (irq == DB1300_SD1_INSERT_INT) {
disable_irq_nosync(DB1300_SD1_INSERT_INT);
enable_irq(DB1300_SD1_EJECT_INT);
} else {
disable_irq_nosync(DB1300_SD1_EJECT_INT);
enable_irq(DB1300_SD1_INSERT_INT);
}
mmc_cd = symbol_get(mmc_detect_change);
mmc_cd(ptr, msecs_to_jiffies(500));
symbol_put(mmc_detect_change);
return IRQ_HANDLED;
}
static int db1300_mmc_card_readonly(void *mmc_host)
{
return bcsr_read(BCSR_STATUS) & BCSR_STATUS_SD0WP;
}
static int db1300_mmc_card_inserted(void *mmc_host)
{
return bcsr_read(BCSR_SIGSTAT) & (1 << 12);
}
static int db1300_mmc_cd_setup(void *mmc_host, int en)
{
int ret;
if (en) {
ret = request_irq(DB1300_SD1_INSERT_INT, db1300_mmc_cd, 0,
"sd_insert", mmc_host);
if (ret)
goto out;
ret = request_irq(DB1300_SD1_EJECT_INT, db1300_mmc_cd, 0,
"sd_eject", mmc_host);
if (ret) {
free_irq(DB1300_SD1_INSERT_INT, mmc_host);
goto out;
}
if (db1300_mmc_card_inserted(mmc_host))
enable_irq(DB1300_SD1_EJECT_INT);
else
enable_irq(DB1300_SD1_INSERT_INT);
} else {
free_irq(DB1300_SD1_INSERT_INT, mmc_host);
free_irq(DB1300_SD1_EJECT_INT, mmc_host);
}
ret = 0;
out:
return ret;
}
static void db1300_mmcled_set(struct led_classdev *led,
enum led_brightness brightness)
{
if (brightness != LED_OFF)
bcsr_mod(BCSR_LEDS, BCSR_LEDS_LED0, 0);
else
bcsr_mod(BCSR_LEDS, 0, BCSR_LEDS_LED0);
}
static int db1300_movinand_inserted(void *mmc_host)
{
return 0;
}
static int db1300_movinand_readonly(void *mmc_host)
{
return 0;
}
static void db1300_movinand_led_set(struct led_classdev *led,
enum led_brightness brightness)
{
if (brightness != LED_OFF)
bcsr_mod(BCSR_LEDS, BCSR_LEDS_LED1, 0);
else
bcsr_mod(BCSR_LEDS, 0, BCSR_LEDS_LED1);
}
static int db1300fb_panel_index(void)
{
return 9;
}
static int db1300fb_panel_init(void)
{
bcsr_mod(BCSR_BOARD, BCSR_BOARD_LCDVEE | BCSR_BOARD_LCDVDD,
BCSR_BOARD_LCDBL);
return 0;
}
static int db1300fb_panel_shutdown(void)
{
bcsr_mod(BCSR_BOARD, BCSR_BOARD_LCDBL,
BCSR_BOARD_LCDVEE | BCSR_BOARD_LCDVDD);
return 0;
}
static void db1300_wm97xx_irqen(struct wm97xx *wm, int enable)
{
if (enable)
enable_irq(DB1300_AC97_PEN_INT);
else
disable_irq_nosync(DB1300_AC97_PEN_INT);
}
static int db1300_wm97xx_probe(struct platform_device *pdev)
{
struct wm97xx *wm = platform_get_drvdata(pdev);
wm97xx_config_gpio(wm, WM97XX_GPIO_13, WM97XX_GPIO_IN,
WM97XX_GPIO_POL_LOW, WM97XX_GPIO_STICKY,
WM97XX_GPIO_WAKE);
wm97xx_config_gpio(wm, WM97XX_GPIO_3, WM97XX_GPIO_OUT,
WM97XX_GPIO_POL_LOW, WM97XX_GPIO_NOTSTICKY,
WM97XX_GPIO_NOWAKE);
wm->pen_irq = DB1300_AC97_PEN_INT;
return wm97xx_register_mach_ops(wm, &db1300_wm97xx_ops);
}
int __init db1300_dev_setup(void)
{
int swapped, cpldirq;
struct clk *c;
cpldirq = au1300_gpio_to_irq(AU1300_PIN_EXTCLK1);
irq_set_irq_type(cpldirq, IRQ_TYPE_LEVEL_HIGH);
bcsr_init_irq(DB1300_FIRST_INT, DB1300_LAST_INT, cpldirq);
irq_set_status_flags(DB1300_SD1_INSERT_INT, IRQ_NOAUTOEN);
irq_set_status_flags(DB1300_SD1_EJECT_INT, IRQ_NOAUTOEN);
irq_set_status_flags(DB1300_CF_INSERT_INT, IRQ_NOAUTOEN);
irq_set_status_flags(DB1300_CF_EJECT_INT, IRQ_NOAUTOEN);
prom_get_ethernet_addr(&db1300_eth_config.mac[0]);
i2c_register_board_info(0, db1300_i2c_devs,
ARRAY_SIZE(db1300_i2c_devs));
if (platform_driver_register(&db1300_wm97xx_driver))
pr_warn("DB1300: failed to init touch pen irq support!\n");
__raw_writel(PSC_SEL_CLK_SERCLK,
(void __iomem *)KSEG1ADDR(AU1300_PSC1_PHYS_ADDR) + PSC_SEL_OFFSET);
wmb();
__raw_writel(PSC_SEL_CLK_SERCLK,
(void __iomem *)KSEG1ADDR(AU1300_PSC2_PHYS_ADDR) + PSC_SEL_OFFSET);
wmb();
c = clk_get(NULL, "psc3_intclk");
if (!IS_ERR(c)) {
clk_set_rate(c, 50000000);
clk_prepare_enable(c);
clk_put(c);
}
__raw_writel(PSC_SEL_CLK_INTCLK,
(void __iomem *)KSEG1ADDR(AU1300_PSC3_PHYS_ADDR) + PSC_SEL_OFFSET);
wmb();
bcsr_mod(BCSR_RESETS, 0, BCSR_RESETS_USBHPWR | BCSR_RESETS_OTGPWR);
db1x_register_pcmcia_socket(
AU1000_PCMCIA_ATTR_PHYS_ADDR,
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x00400000 - 1,
AU1000_PCMCIA_MEM_PHYS_ADDR,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x00400000 - 1,
AU1000_PCMCIA_IO_PHYS_ADDR,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x00010000 - 1,
DB1300_CF_INT, DB1300_CF_INSERT_INT, 0, DB1300_CF_EJECT_INT, 1);
swapped = bcsr_read(BCSR_STATUS) & BCSR_STATUS_DB1200_SWAPBOOT;
db1x_register_norflash(64 << 20, 2, swapped);
return platform_add_devices(db1300_dev, ARRAY_SIZE(db1300_dev));
}
int __init db1300_board_setup(void)
{
unsigned short whoami;
bcsr_init(DB1300_BCSR_PHYS_ADDR,
DB1300_BCSR_PHYS_ADDR + DB1300_BCSR_HEXLED_OFS);
whoami = bcsr_read(BCSR_WHOAMI);
if (BCSR_WHOAMI_BOARD(whoami) != BCSR_WHOAMI_DB1300)
return -ENODEV;
db1300_gpio_config();
printk(KERN_INFO "NetLogic DBAu1300 Development Platform.\n\t"
"BoardID %d CPLD Rev %d DaughtercardID %d\n",
BCSR_WHOAMI_BOARD(whoami), BCSR_WHOAMI_CPLD(whoami),
BCSR_WHOAMI_DCID(whoami));
alchemy_uart_enable(AU1300_UART0_PHYS_ADDR);
alchemy_uart_enable(AU1300_UART1_PHYS_ADDR);
alchemy_uart_enable(AU1300_UART3_PHYS_ADDR);
return 0;
}
