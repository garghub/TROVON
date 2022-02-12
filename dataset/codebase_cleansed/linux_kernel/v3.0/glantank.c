static void __init glantank_timer_init(void)
{
iop_init_time(200000000);
}
void __init glantank_map_io(void)
{
iop3xx_map_io();
iotable_init(glantank_io_desc, ARRAY_SIZE(glantank_io_desc));
}
static int __init
glantank_pci_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
static int pci_irq_table[][4] = {
{INTD, INTD, INTD, INTD},
{INTA, INTA, INTA, INTA},
{INTB, INTB, INTB, INTB},
{INTC, INTC, INTC, INTC},
};
BUG_ON(pin < 1 || pin > 4);
return pci_irq_table[slot % 4][pin - 1];
}
static int __init glantank_pci_init(void)
{
if (machine_is_glantank())
pci_common_init(&glantank_pci);
return 0;
}
static void glantank_power_off(void)
{
__raw_writeb(0x01, 0xfe8d0004);
while (1)
;
}
static void __init glantank_init_machine(void)
{
platform_device_register(&iop3xx_i2c0_device);
platform_device_register(&iop3xx_i2c1_device);
platform_device_register(&glantank_flash_device);
platform_device_register(&glantank_serial_device);
platform_device_register(&iop3xx_dma_0_channel);
platform_device_register(&iop3xx_dma_1_channel);
i2c_register_board_info(0, glantank_i2c_devices,
ARRAY_SIZE(glantank_i2c_devices));
pm_power_off = glantank_power_off;
}
