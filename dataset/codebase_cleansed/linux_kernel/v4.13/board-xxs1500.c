const char *get_system_type(void)
{
return "XXS1500";
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
static void xxs1500_reset(char *c)
{
__asm__ __volatile__("jr\t%0" : : "r"(0xbfc00000));
}
static void xxs1500_power_off(void)
{
while (1)
asm volatile (
" .set mips32 \n"
" wait \n"
" .set mips0 \n");
}
void __init board_setup(void)
{
u32 pin_func;
pm_power_off = xxs1500_power_off;
_machine_halt = xxs1500_power_off;
_machine_restart = xxs1500_reset;
alchemy_gpio1_input_enable();
alchemy_gpio2_enable();
pin_func = alchemy_rdsys(AU1000_SYS_PINFUNC) & ~SYS_PF_UR3;
pin_func |= SYS_PF_UR3;
alchemy_wrsys(pin_func, AU1000_SYS_PINFUNC);
alchemy_uart_enable(AU1000_UART3_PHYS_ADDR);
__raw_writel(1, (void __iomem *)KSEG1ADDR(AU1000_UART3_PHYS_ADDR + 0x18));
wmb();
}
static int __init xxs1500_dev_init(void)
{
irq_set_irq_type(AU1500_GPIO204_INT, IRQ_TYPE_LEVEL_HIGH);
irq_set_irq_type(AU1500_GPIO201_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO202_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO203_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO205_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO207_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO0_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO1_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO2_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO3_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO4_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1500_GPIO5_INT, IRQ_TYPE_LEVEL_LOW);
return platform_add_devices(xxs1500_devs,
ARRAY_SIZE(xxs1500_devs));
}
