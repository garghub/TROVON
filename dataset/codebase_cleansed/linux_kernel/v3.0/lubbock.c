void lubbock_set_hexled(uint32_t value)
{
LUB_HEXLED = value;
}
void lubbock_set_misc_wr(unsigned int mask, unsigned int set)
{
unsigned long flags;
local_irq_save(flags);
LUB_MISC_WR = (LUB_MISC_WR & ~mask) | (set & mask);
local_irq_restore(flags);
}
static void lubbock_mask_irq(struct irq_data *d)
{
int lubbock_irq = (d->irq - LUBBOCK_IRQ(0));
LUB_IRQ_MASK_EN = (lubbock_irq_enabled &= ~(1 << lubbock_irq));
}
static void lubbock_unmask_irq(struct irq_data *d)
{
int lubbock_irq = (d->irq - LUBBOCK_IRQ(0));
LUB_IRQ_SET_CLR &= ~(1 << lubbock_irq);
LUB_IRQ_MASK_EN = (lubbock_irq_enabled |= (1 << lubbock_irq));
}
static void lubbock_irq_handler(unsigned int irq, struct irq_desc *desc)
{
unsigned long pending = LUB_IRQ_SET_CLR & lubbock_irq_enabled;
do {
desc->irq_data.chip->irq_ack(&desc->irq_data);
if (likely(pending)) {
irq = LUBBOCK_IRQ(0) + __ffs(pending);
generic_handle_irq(irq);
}
pending = LUB_IRQ_SET_CLR & lubbock_irq_enabled;
} while (pending);
}
static void __init lubbock_init_irq(void)
{
int irq;
pxa25x_init_irq();
for (irq = LUBBOCK_IRQ(0); irq <= LUBBOCK_LAST_IRQ; irq++) {
irq_set_chip_and_handler(irq, &lubbock_irq_chip,
handle_level_irq);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
irq_set_chained_handler(IRQ_GPIO(0), lubbock_irq_handler);
irq_set_irq_type(IRQ_GPIO(0), IRQ_TYPE_EDGE_FALLING);
}
static void lubbock_irq_resume(void)
{
LUB_IRQ_MASK_EN = lubbock_irq_enabled;
}
static int __init lubbock_irq_device_init(void)
{
if (machine_is_lubbock()) {
register_syscore_ops(&lubbock_irq_syscore_ops);
return 0;
}
return -ENODEV;
}
static int lubbock_udc_is_connected(void)
{
return (LUB_MISC_RD & (1 << 9)) == 0;
}
static int lubbock_ads7846_pendown_state(void)
{
return 0;
}
static void ads7846_cs(u32 command)
{
static const unsigned TS_nCS = 1 << 11;
lubbock_set_misc_wr(TS_nCS, (command == PXA2XX_CS_ASSERT) ? 0 : TS_nCS);
}
static void lubbock_mmc_poll(unsigned long data)
{
unsigned long flags;
local_irq_save(flags);
LUB_IRQ_SET_CLR &= ~(1 << 0);
local_irq_restore(flags);
if (LUB_IRQ_SET_CLR & (1 << 0))
mod_timer(&mmc_timer, jiffies + MMC_POLL_RATE);
else {
(void) mmc_detect_int(LUBBOCK_SD_IRQ, (void *)data);
enable_irq(LUBBOCK_SD_IRQ);
}
}
static irqreturn_t lubbock_detect_int(int irq, void *data)
{
disable_irq(irq);
mod_timer(&mmc_timer, jiffies + MMC_POLL_RATE);
return mmc_detect_int(irq, data);
}
static int lubbock_mci_init(struct device *dev,
irq_handler_t detect_int,
void *data)
{
mmc_detect_int = detect_int;
init_timer(&mmc_timer);
mmc_timer.data = (unsigned long) data;
return request_irq(LUBBOCK_SD_IRQ, lubbock_detect_int,
IRQF_SAMPLE_RANDOM, "lubbock-sd-detect", data);
}
static int lubbock_mci_get_ro(struct device *dev)
{
return (LUB_MISC_RD & (1 << 2)) != 0;
}
static void lubbock_mci_exit(struct device *dev, void *data)
{
free_irq(LUBBOCK_SD_IRQ, data);
del_timer_sync(&mmc_timer);
}
static void lubbock_irda_transceiver_mode(struct device *dev, int mode)
{
unsigned long flags;
local_irq_save(flags);
if (mode & IR_SIRMODE) {
LUB_MISC_WR &= ~(1 << 4);
} else if (mode & IR_FIRMODE) {
LUB_MISC_WR |= 1 << 4;
}
pxa2xx_transceiver_mode(dev, mode);
local_irq_restore(flags);
}
static void __init lubbock_init(void)
{
int flashboot = (LUB_CONF_SWITCHES & 1);
pxa2xx_mfp_config(ARRAY_AND_SIZE(lubbock_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
clk_add_alias("SA1111_CLK", NULL, "GPIO11_CLK", NULL);
pxa_set_udc_info(&udc_info);
pxa_set_fb_info(NULL, &sharp_lm8v31);
pxa_set_mci_info(&lubbock_mci_platform_data);
pxa_set_ficp_info(&lubbock_ficp_platform_data);
pxa_set_ac97_info(NULL);
lubbock_flash_data[0].width = lubbock_flash_data[1].width =
(__raw_readl(BOOT_DEF) & 1) ? 2 : 4;
printk(KERN_NOTICE "Lubbock configured to boot from %s (bank %d)\n",
flashboot?"Flash":"ROM", flashboot);
lubbock_flash_data[flashboot^1].name = "application-flash";
lubbock_flash_data[flashboot].name = "boot-rom";
(void) platform_add_devices(devices, ARRAY_SIZE(devices));
pxa2xx_set_spi_info(1, &pxa_ssp_master_info);
spi_register_board_info(spi_board_info, ARRAY_SIZE(spi_board_info));
}
static void __init lubbock_map_io(void)
{
pxa25x_map_io();
iotable_init(lubbock_io_desc, ARRAY_SIZE(lubbock_io_desc));
PCFR |= PCFR_OPDE;
}
