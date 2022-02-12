int __init db1000_board_setup(void)
{
bcsr_init(DB1000_BCSR_PHYS_ADDR,
DB1000_BCSR_PHYS_ADDR + DB1000_BCSR_HEXLED_OFS);
switch (BCSR_WHOAMI_BOARD(bcsr_read(BCSR_WHOAMI))) {
case BCSR_WHOAMI_DB1000:
case BCSR_WHOAMI_DB1500:
case BCSR_WHOAMI_DB1100:
case BCSR_WHOAMI_PB1500:
case BCSR_WHOAMI_PB1500R2:
case BCSR_WHOAMI_PB1100:
pr_info("AMD Alchemy %s Board\n", get_system_type());
return 0;
}
return -ENODEV;
}
static int db1500_map_pci_irq(const struct pci_dev *d, u8 slot, u8 pin)
{
if ((slot < 12) || (slot > 13) || pin == 0)
return -1;
if (slot == 12)
return (pin == 1) ? AU1500_PCI_INTA : 0xff;
if (slot == 13) {
switch (pin) {
case 1: return AU1500_PCI_INTA;
case 2: return AU1500_PCI_INTB;
case 3: return AU1500_PCI_INTC;
case 4: return AU1500_PCI_INTD;
}
}
return -1;
}
int __init db1500_pci_setup(void)
{
return platform_device_register(&db1500_pci_host_dev);
}
static irqreturn_t db1100_mmc_cd(int irq, void *ptr)
{
void (*mmc_cd)(struct mmc_host *, unsigned long);
mmc_cd = symbol_get(mmc_detect_change);
mmc_cd(ptr, msecs_to_jiffies(500));
symbol_put(mmc_detect_change);
return IRQ_HANDLED;
}
static int db1100_mmc_cd_setup(void *mmc_host, int en)
{
int ret = 0, irq;
if (BCSR_WHOAMI_BOARD(bcsr_read(BCSR_WHOAMI)) == BCSR_WHOAMI_DB1100)
irq = AU1100_GPIO19_INT;
else
irq = AU1100_GPIO14_INT;
if (en) {
irq_set_irq_type(irq, IRQ_TYPE_EDGE_BOTH);
ret = request_irq(irq, db1100_mmc_cd, 0,
"sd0_cd", mmc_host);
} else
free_irq(irq, mmc_host);
return ret;
}
static int db1100_mmc1_cd_setup(void *mmc_host, int en)
{
int ret = 0, irq;
if (BCSR_WHOAMI_BOARD(bcsr_read(BCSR_WHOAMI)) == BCSR_WHOAMI_DB1100)
irq = AU1100_GPIO20_INT;
else
irq = AU1100_GPIO15_INT;
if (en) {
irq_set_irq_type(irq, IRQ_TYPE_EDGE_BOTH);
ret = request_irq(irq, db1100_mmc_cd, 0,
"sd1_cd", mmc_host);
} else
free_irq(irq, mmc_host);
return ret;
}
static int db1100_mmc_card_readonly(void *mmc_host)
{
return (bcsr_read(BCSR_STATUS) & BCSR_STATUS_SD0WP) ? 0 : 1;
}
static int db1100_mmc_card_inserted(void *mmc_host)
{
return !alchemy_gpio_get_value(19);
}
static void db1100_mmc_set_power(void *mmc_host, int state)
{
int bit;
if (BCSR_WHOAMI_BOARD(bcsr_read(BCSR_WHOAMI)) == BCSR_WHOAMI_DB1100)
bit = BCSR_BOARD_SD0PWR;
else
bit = BCSR_BOARD_PB1100_SD0PWR;
if (state) {
bcsr_mod(BCSR_BOARD, 0, bit);
msleep(400);
} else
bcsr_mod(BCSR_BOARD, bit, 0);
}
static void db1100_mmcled_set(struct led_classdev *led, enum led_brightness b)
{
if (b != LED_OFF)
bcsr_mod(BCSR_LEDS, BCSR_LEDS_LED0, 0);
else
bcsr_mod(BCSR_LEDS, 0, BCSR_LEDS_LED0);
}
static int db1100_mmc1_card_readonly(void *mmc_host)
{
return (bcsr_read(BCSR_BOARD) & BCSR_BOARD_SD1WP) ? 1 : 0;
}
static int db1100_mmc1_card_inserted(void *mmc_host)
{
return !alchemy_gpio_get_value(20);
}
static void db1100_mmc1_set_power(void *mmc_host, int state)
{
int bit;
if (BCSR_WHOAMI_BOARD(bcsr_read(BCSR_WHOAMI)) == BCSR_WHOAMI_DB1100)
bit = BCSR_BOARD_SD1PWR;
else
bit = BCSR_BOARD_PB1100_SD1PWR;
if (state) {
bcsr_mod(BCSR_BOARD, 0, bit);
msleep(400);
} else
bcsr_mod(BCSR_BOARD, bit, 0);
}
static void db1100_mmc1led_set(struct led_classdev *led, enum led_brightness b)
{
if (b != LED_OFF)
bcsr_mod(BCSR_LEDS, BCSR_LEDS_LED1, 0);
else
bcsr_mod(BCSR_LEDS, 0, BCSR_LEDS_LED1);
}
static void db1000_irda_set_phy_mode(int mode)
{
unsigned short mask = BCSR_RESETS_IRDA_MODE_MASK | BCSR_RESETS_FIR_SEL;
switch (mode) {
case AU1000_IRDA_PHY_MODE_OFF:
bcsr_mod(BCSR_RESETS, mask, BCSR_RESETS_IRDA_MODE_OFF);
break;
case AU1000_IRDA_PHY_MODE_SIR:
bcsr_mod(BCSR_RESETS, mask, BCSR_RESETS_IRDA_MODE_FULL);
break;
case AU1000_IRDA_PHY_MODE_FIR:
bcsr_mod(BCSR_RESETS, mask, BCSR_RESETS_IRDA_MODE_FULL |
BCSR_RESETS_FIR_SEL);
break;
}
}
int __init db1000_dev_setup(void)
{
int board = BCSR_WHOAMI_BOARD(bcsr_read(BCSR_WHOAMI));
int c0, c1, d0, d1, s0, s1, flashsize = 32, twosocks = 1;
unsigned long pfc;
struct clk *c, *p;
if (board == BCSR_WHOAMI_DB1500) {
c0 = AU1500_GPIO2_INT;
c1 = AU1500_GPIO5_INT;
d0 = AU1500_GPIO0_INT;
d1 = AU1500_GPIO3_INT;
s0 = AU1500_GPIO1_INT;
s1 = AU1500_GPIO4_INT;
} else if (board == BCSR_WHOAMI_DB1100) {
c0 = AU1100_GPIO2_INT;
c1 = AU1100_GPIO5_INT;
d0 = AU1100_GPIO0_INT;
d1 = AU1100_GPIO3_INT;
s0 = AU1100_GPIO1_INT;
s1 = AU1100_GPIO4_INT;
gpio_request(19, "sd0_cd");
gpio_request(20, "sd1_cd");
gpio_direction_input(19);
gpio_direction_input(20);
pfc = alchemy_rdsys(AU1000_SYS_PINFUNC);
pfc |= (1 << 0);
alchemy_wrsys(pfc, AU1000_SYS_PINFUNC);
spi_register_board_info(db1100_spi_info,
ARRAY_SIZE(db1100_spi_info));
p = clk_get(NULL, "auxpll_clk");
c = clk_get(NULL, "lcd_intclk");
if (!IS_ERR(c) && !IS_ERR(p)) {
clk_set_parent(c, p);
clk_set_rate(c, clk_get_rate(p));
}
if (!IS_ERR(c))
clk_put(c);
if (!IS_ERR(p))
clk_put(p);
platform_add_devices(db1100_devs, ARRAY_SIZE(db1100_devs));
platform_device_register(&db1100_spi_dev);
} else if (board == BCSR_WHOAMI_DB1000) {
c0 = AU1000_GPIO2_INT;
c1 = AU1000_GPIO5_INT;
d0 = AU1000_GPIO0_INT;
d1 = AU1000_GPIO3_INT;
s0 = AU1000_GPIO1_INT;
s1 = AU1000_GPIO4_INT;
platform_add_devices(db1000_devs, ARRAY_SIZE(db1000_devs));
} else if ((board == BCSR_WHOAMI_PB1500) ||
(board == BCSR_WHOAMI_PB1500R2)) {
c0 = AU1500_GPIO203_INT;
d0 = AU1500_GPIO201_INT;
s0 = AU1500_GPIO202_INT;
twosocks = 0;
flashsize = 64;
irq_set_irq_type(AU1500_GPIO204_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO205_INT, IRQ_TYPE_LEVEL_LOW);
} else if (board == BCSR_WHOAMI_PB1100) {
c0 = AU1100_GPIO11_INT;
d0 = AU1100_GPIO9_INT;
s0 = AU1100_GPIO10_INT;
twosocks = 0;
flashsize = 64;
irq_set_irq_type(AU1100_GPIO8_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1100_GPIO12_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1100_GPIO13_INT, IRQ_TYPE_LEVEL_LOW);
platform_add_devices(db1100_devs, ARRAY_SIZE(db1100_devs));
} else
return 0;
irq_set_irq_type(d0, IRQ_TYPE_EDGE_BOTH);
irq_set_irq_type(c0, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(s0, IRQ_TYPE_LEVEL_LOW);
db1x_register_pcmcia_socket(
AU1000_PCMCIA_ATTR_PHYS_ADDR,
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x000400000 - 1,
AU1000_PCMCIA_MEM_PHYS_ADDR,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x000400000 - 1,
AU1000_PCMCIA_IO_PHYS_ADDR,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x000010000 - 1,
c0, d0, 0, 0, 0);
if (twosocks) {
irq_set_irq_type(d1, IRQ_TYPE_EDGE_BOTH);
irq_set_irq_type(c1, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(s1, IRQ_TYPE_LEVEL_LOW);
db1x_register_pcmcia_socket(
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x004000000,
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x004400000 - 1,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x004000000,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x004400000 - 1,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x004000000,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x004010000 - 1,
c1, d1, 0, 0, 1);
}
platform_add_devices(db1x00_devs, ARRAY_SIZE(db1x00_devs));
db1x_register_norflash(flashsize << 20, 4 , F_SWAPPED);
return 0;
}
