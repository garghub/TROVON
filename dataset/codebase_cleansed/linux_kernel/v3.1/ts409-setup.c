static int __init qnap_ts409_pci_map_irq(const struct pci_dev *dev, u8 slot,
u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
return -1;
}
static int __init qnap_ts409_pci_init(void)
{
if (machine_is_ts409())
pci_common_init(&qnap_ts409_pci);
return 0;
}
static void __init qnap_ts409_init(void)
{
orion5x_init();
orion5x_mpp_conf(ts409_mpp_modes);
orion5x_setup_dev_boot_win(QNAP_TS409_NOR_BOOT_BASE,
QNAP_TS409_NOR_BOOT_SIZE);
platform_device_register(&qnap_ts409_nor_flash);
orion5x_ehci0_init();
qnap_tsx09_find_mac_addr(QNAP_TS409_NOR_BOOT_BASE +
qnap_ts409_partitions[5].offset,
qnap_ts409_partitions[5].size);
orion5x_eth_init(&qnap_tsx09_eth_data);
orion5x_i2c_init();
orion5x_uart0_init();
orion5x_uart1_init();
platform_device_register(&qnap_ts409_button_device);
if (gpio_request(TS409_RTC_GPIO, "rtc") == 0) {
if (gpio_direction_input(TS409_RTC_GPIO) == 0)
qnap_ts409_i2c_rtc.irq = gpio_to_irq(TS409_RTC_GPIO);
else
gpio_free(TS409_RTC_GPIO);
}
if (qnap_ts409_i2c_rtc.irq == 0)
pr_warning("qnap_ts409_init: failed to get RTC IRQ\n");
i2c_register_board_info(0, &qnap_ts409_i2c_rtc, 1);
platform_device_register(&ts409_leds);
pm_power_off = qnap_tsx09_power_off;
}
