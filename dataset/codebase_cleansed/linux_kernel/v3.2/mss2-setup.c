static int __init mss2_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
return -1;
}
static int __init mss2_pci_init(void)
{
if (machine_is_mss2())
pci_common_init(&mss2_pci);
return 0;
}
static void mss2_power_off(void)
{
u32 reg;
reg = readl(RSTOUTn_MASK);
reg |= 1 << 2;
writel(reg, RSTOUTn_MASK);
reg = readl(CPU_SOFT_RESET);
reg |= 1;
writel(reg, CPU_SOFT_RESET);
}
static void __init mss2_init(void)
{
orion5x_init();
orion5x_mpp_conf(mss2_mpp_modes);
orion5x_ehci0_init();
orion5x_ehci1_init();
orion5x_eth_init(&mss2_eth_data);
orion5x_i2c_init();
orion5x_sata_init(&mss2_sata_data);
orion5x_uart0_init();
orion5x_xor_init();
orion5x_setup_dev_boot_win(MSS2_NOR_BOOT_BASE, MSS2_NOR_BOOT_SIZE);
platform_device_register(&mss2_nor_flash);
platform_device_register(&mss2_button_device);
if (gpio_request(MSS2_GPIO_RTC_IRQ, "rtc") == 0) {
if (gpio_direction_input(MSS2_GPIO_RTC_IRQ) == 0)
mss2_i2c_rtc.irq = gpio_to_irq(MSS2_GPIO_RTC_IRQ);
else
gpio_free(MSS2_GPIO_RTC_IRQ);
}
i2c_register_board_info(0, &mss2_i2c_rtc, 1);
pm_power_off = mss2_power_off;
}
