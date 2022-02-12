static u16 bonito_fpga_read(u32 offset)
{
return __raw_readw(0xf0003000 + offset);
}
static void bonito_fpga_write(u32 offset, u16 val)
{
__raw_writew(val, 0xf0003000 + offset);
}
static void bonito_fpga_irq_disable(struct irq_data *data)
{
unsigned int irq = data->irq;
u32 addr = (irq < 1016) ? IRQMR0 : IRQMR1;
int shift = irq % 16;
bonito_fpga_write(addr, bonito_fpga_read(addr) | (1 << shift));
}
static void bonito_fpga_irq_enable(struct irq_data *data)
{
unsigned int irq = data->irq;
u32 addr = (irq < 1016) ? IRQMR0 : IRQMR1;
int shift = irq % 16;
bonito_fpga_write(addr, bonito_fpga_read(addr) & ~(1 << shift));
}
static void bonito_fpga_irq_demux(unsigned int irq, struct irq_desc *desc)
{
u32 val = bonito_fpga_read(IRQSR1) << 16 |
bonito_fpga_read(IRQSR0);
u32 mask = bonito_fpga_read(IRQMR1) << 16 |
bonito_fpga_read(IRQMR0);
int i;
val &= ~mask;
for (i = 0; i < 32; i++) {
if (!(val & (1 << i)))
continue;
generic_handle_irq(FPGA_IRQ_BASE + i);
}
}
static void bonito_fpga_init(void)
{
int i;
bonito_fpga_write(IRQMR0, 0xffff);
bonito_fpga_write(IRQMR1, 0xffff);
bonito_fpga_write(DEVRSTCR1,
(1 << 2));
for (i = FPGA_IRQ_BASE; i < FPGA_IRQ_BASE + 32; i++) {
irq_set_chip_and_handler_name(i, &bonito_fpga_irq_chip,
handle_level_irq, "level");
set_irq_flags(i, IRQF_VALID);
}
irq_set_chained_handler(evt2irq(0x0340), bonito_fpga_irq_demux);
irq_set_irq_type(evt2irq(0x0340), IRQ_TYPE_LEVEL_LOW);
}
static int __init pmic_init(void)
{
struct i2c_adapter *a = i2c_get_adapter(0);
struct i2c_msg msg;
__u8 buf[2];
int i, ret;
if (!pmic_settings)
return 0;
if (!a)
return 0;
msg.addr = 0x46;
msg.buf = buf;
msg.len = 2;
msg.flags = 0;
for (i = 0; ; i += 2) {
buf[0] = pmic_settings[i + 0];
buf[1] = pmic_settings[i + 1];
if ((0xff == buf[0]) && (0xff == buf[1]))
break;
ret = i2c_transfer(a, &msg, 1);
if (ret < 0) {
pr_err("i2c transfer fail\n");
break;
}
}
return 0;
}
static void __init bonito_map_io(void)
{
r8a7740_map_io();
iotable_init(bonito_io_desc, ARRAY_SIZE(bonito_io_desc));
}
static void __init bonito_init(void)
{
u16 val;
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
r8a7740_pinmux_init();
bonito_fpga_init();
pmic_settings = pmic_do_2A;
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0002000), 0x40440000, 0x82000fff);
#endif
r8a7740_add_standard_devices();
platform_add_devices(bonito_core_devices,
ARRAY_SIZE(bonito_core_devices));
gpio_request(GPIO_PORT176, NULL);
gpio_direction_input(GPIO_PORT176);
if (!gpio_get_value(GPIO_PORT176)) {
u16 bsw2;
u16 bsw3;
u16 bsw4;
gpio_request(GPIO_FN_CS5B, NULL);
gpio_request(GPIO_FN_CS6A, NULL);
gpio_request(GPIO_FN_CS5A_PORT105, NULL);
gpio_request(GPIO_FN_IRQ10, NULL);
val = bonito_fpga_read(BVERR);
pr_info("bonito version: cpu %02x, base %02x\n",
((val >> 8) & 0xFF),
((val >> 0) & 0xFF));
bsw2 = bonito_fpga_read(BUSSWMR2);
bsw3 = bonito_fpga_read(BUSSWMR3);
bsw4 = bonito_fpga_read(BUSSWMR4);
if (BIT_OFF(bsw2, 1) &&
BIT_OFF(bsw3, 9) &&
BIT_OFF(bsw4, 4)) {
gpio_request(GPIO_FN_SCIFA5_TXD_PORT91, NULL);
gpio_request(GPIO_FN_SCIFA5_RXD_PORT92, NULL);
}
if (BIT_ON(bsw2, 3) &&
BIT_ON(bsw2, 2)) {
gpio_request(GPIO_FN_LCDC0_SELECT, NULL);
gpio_request(GPIO_FN_LCD0_D0, NULL);
gpio_request(GPIO_FN_LCD0_D1, NULL);
gpio_request(GPIO_FN_LCD0_D2, NULL);
gpio_request(GPIO_FN_LCD0_D3, NULL);
gpio_request(GPIO_FN_LCD0_D4, NULL);
gpio_request(GPIO_FN_LCD0_D5, NULL);
gpio_request(GPIO_FN_LCD0_D6, NULL);
gpio_request(GPIO_FN_LCD0_D7, NULL);
gpio_request(GPIO_FN_LCD0_D8, NULL);
gpio_request(GPIO_FN_LCD0_D9, NULL);
gpio_request(GPIO_FN_LCD0_D10, NULL);
gpio_request(GPIO_FN_LCD0_D11, NULL);
gpio_request(GPIO_FN_LCD0_D12, NULL);
gpio_request(GPIO_FN_LCD0_D13, NULL);
gpio_request(GPIO_FN_LCD0_D14, NULL);
gpio_request(GPIO_FN_LCD0_D15, NULL);
gpio_request(GPIO_FN_LCD0_D16, NULL);
gpio_request(GPIO_FN_LCD0_D17, NULL);
gpio_request(GPIO_FN_LCD0_D18_PORT163, NULL);
gpio_request(GPIO_FN_LCD0_D19_PORT162, NULL);
gpio_request(GPIO_FN_LCD0_D20_PORT161, NULL);
gpio_request(GPIO_FN_LCD0_D21_PORT158, NULL);
gpio_request(GPIO_FN_LCD0_D22_PORT160, NULL);
gpio_request(GPIO_FN_LCD0_D23_PORT159, NULL);
gpio_request(GPIO_FN_LCD0_DCK, NULL);
gpio_request(GPIO_FN_LCD0_VSYN, NULL);
gpio_request(GPIO_FN_LCD0_HSYN, NULL);
gpio_request(GPIO_FN_LCD0_DISP, NULL);
gpio_request(GPIO_FN_LCD0_LCLK_PORT165, NULL);
gpio_request(GPIO_PORT61, NULL);
gpio_direction_output(GPIO_PORT61, 1);
bonito_fpga_write(LCDCR, 1);
__raw_writew(0x00FF , VCCQ1LCDCR);
__raw_writew(0xFFFF , VCCQ1CR);
}
platform_add_devices(bonito_base_devices,
ARRAY_SIZE(bonito_base_devices));
}
}
static void __init bonito_earlytimer_init(void)
{
u16 val;
u8 md_ck = 0;
val = bonito_fpga_read(A1MDSR);
if (val & (1 << 10))
md_ck |= MD_CK2;
if (val & (1 << 9))
md_ck |= MD_CK1;
if (val & (1 << 8))
md_ck |= MD_CK0;
r8a7740_clock_init(md_ck);
shmobile_earlytimer_init();
}
static void __init bonito_add_early_devices(void)
{
r8a7740_add_early_devices();
shmobile_timer.init = bonito_earlytimer_init;
}
