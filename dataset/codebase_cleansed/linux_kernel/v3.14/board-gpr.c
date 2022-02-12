const char *get_system_type(void)
{
return "GPR";
}
void __init prom_init(void)
{
unsigned char *memsize_str;
unsigned long memsize;
prom_argc = fw_arg0;
prom_argv = (char **)fw_arg1;
prom_envp = (char **)fw_arg2;
prom_init_cmdline();
memsize_str = prom_getenv("memsize");
if (!memsize_str || kstrtoul(memsize_str, 0, &memsize))
memsize = 0x04000000;
add_memory_region(0, memsize, BOOT_MEM_RAM);
}
void prom_putchar(unsigned char c)
{
alchemy_uart_putchar(AU1000_UART0_PHYS_ADDR, c);
}
static void gpr_reset(char *c)
{
alchemy_gpio_direction_output(4, 0);
alchemy_gpio_direction_output(5, 0);
printk(KERN_EMERG "Triggering watchdog soft reset...\n");
raw_local_irq_disable();
alchemy_gpio_direction_output(1, 0);
udelay(1);
alchemy_gpio_set_value(1, 1);
while (1)
cpu_wait();
}
static void gpr_power_off(void)
{
while (1)
cpu_wait();
}
void __init board_setup(void)
{
printk(KERN_INFO "Trapeze ITS GPR board\n");
pm_power_off = gpr_power_off;
_machine_halt = gpr_power_off;
_machine_restart = gpr_reset;
alchemy_uart_enable(AU1000_UART3_PHYS_ADDR);
alchemy_uart_enable(AU1000_UART1_PHYS_ADDR);
alchemy_gpio_direction_output(215, 1);
}
static int gpr_map_pci_irq(const struct pci_dev *d, u8 slot, u8 pin)
{
if ((slot == 0) && (pin == 1))
return AU1550_PCI_INTA;
else if ((slot == 0) && (pin == 2))
return AU1550_PCI_INTB;
return 0xff;
}
static int __init gpr_pci_init(void)
{
return platform_device_register(&gpr_pci_host_dev);
}
static int __init gpr_dev_init(void)
{
i2c_register_board_info(0, gpr_i2c_info, ARRAY_SIZE(gpr_i2c_info));
return platform_add_devices(gpr_devices, ARRAY_SIZE(gpr_devices));
}
