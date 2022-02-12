static void __init em7210_timer_init(void)
{
iop_init_time(200000000);
}
void __init em7210_map_io(void)
{
iop3xx_map_io();
iotable_init(em7210_io_desc, ARRAY_SIZE(em7210_io_desc));
}
static int __init
em7210_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static int pci_irq_table[][4] = {
{INTB, INTB, INTB, INTB},
{INTA, INTA, INTA, INTA},
{INTD, INTD, INTD, INTD},
{INTC, INTC, INTC, INTC},
{INTD, INTA, INTA, INTA},
{INTD, INTC, INTA, INTA},
};
if (pin < 1 || pin > 4)
return -1;
return pci_irq_table[slot % 6][pin - 1];
}
static int __init em7210_pci_init(void)
{
if (machine_is_em7210())
pci_common_init(&em7210_pci);
return 0;
}
void em7210_power_off(void)
{
int ret;
ret = gpio_direction_output(EM7210_HARDWARE_POWER, 1);
if (ret)
pr_crit("could not drive power off GPIO high\n");
}
static int __init em7210_request_gpios(void)
{
int ret;
if (!machine_is_em7210())
return 0;
ret = gpio_request(EM7210_HARDWARE_POWER, "power");
if (ret) {
pr_err("could not request power off GPIO\n");
return 0;
}
pm_power_off = em7210_power_off;
return 0;
}
static void __init em7210_init_machine(void)
{
register_iop32x_gpio();
platform_device_register(&em7210_serial_device);
platform_device_register(&iop3xx_i2c0_device);
platform_device_register(&iop3xx_i2c1_device);
platform_device_register(&em7210_flash_device);
platform_device_register(&iop3xx_dma_0_channel);
platform_device_register(&iop3xx_dma_1_channel);
i2c_register_board_info(0, em7210_i2c_devices,
ARRAY_SIZE(em7210_i2c_devices));
}
