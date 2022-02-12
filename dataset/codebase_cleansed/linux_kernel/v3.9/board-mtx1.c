const char *get_system_type(void)
{
return "MTX-1";
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
if (!memsize_str)
memsize = 0x04000000;
else
strict_strtoul(memsize_str, 0, &memsize);
add_memory_region(0, memsize, BOOT_MEM_RAM);
}
void prom_putchar(unsigned char c)
{
alchemy_uart_putchar(AU1000_UART0_PHYS_ADDR, c);
}
static void mtx1_reset(char *c)
{
__asm__ __volatile__("jr\t%0" : : "r"(0xbfc00000));
}
static void mtx1_power_off(void)
{
while (1)
asm volatile (
" .set mips32 \n"
" wait \n"
" .set mips0 \n");
}
void __init board_setup(void)
{
#if IS_ENABLED(CONFIG_USB_OHCI_HCD)
alchemy_gpio_direction_output(204, 0);
#endif
au_writel(SYS_PF_NI2, SYS_PINFUNC);
au_writel(~0, KSEG1ADDR(AU1000_SYS_PHYS_ADDR) + SYS_TRIOUTCLR);
alchemy_gpio_direction_output(0, 0);
alchemy_gpio_direction_output(3, 1);
alchemy_gpio_direction_output(1, 1);
alchemy_gpio_direction_output(5, 0);
alchemy_gpio_direction_output(211, 1);
alchemy_gpio_direction_output(212, 0);
pm_power_off = mtx1_power_off;
_machine_halt = mtx1_power_off;
_machine_restart = mtx1_reset;
printk(KERN_INFO "4G Systems MTX-1 Board\n");
}
static int mtx1_pci_idsel(unsigned int devsel, int assert)
{
udelay(1);
if (assert && devsel != 0)
alchemy_gpio_set_value(1, 0);
else
alchemy_gpio_set_value(1, 1);
udelay(1);
return 1;
}
static int mtx1_map_pci_irq(const struct pci_dev *d, u8 slot, u8 pin)
{
return mtx1_irqtab[slot][pin];
}
static int __init mtx1_register_devices(void)
{
int rc;
irq_set_irq_type(AU1500_GPIO204_INT, IRQ_TYPE_LEVEL_HIGH);
irq_set_irq_type(AU1500_GPIO201_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO202_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO203_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO205_INT, IRQ_TYPE_LEVEL_LOW);
au1xxx_override_eth_cfg(0, &mtx1_au1000_eth0_pdata);
rc = gpio_request(mtx1_gpio_button[0].gpio,
mtx1_gpio_button[0].desc);
if (rc < 0) {
printk(KERN_INFO "mtx1: failed to request %d\n",
mtx1_gpio_button[0].gpio);
goto out;
}
gpio_direction_input(mtx1_gpio_button[0].gpio);
out:
return platform_add_devices(mtx1_devs, ARRAY_SIZE(mtx1_devs));
}
