static int __init badge4_sa1111_init(void)
{
sa1110_mb_disable();
return platform_add_devices(devices, ARRAY_SIZE(devices));
}
static int __init five_v_on_setup(char *ignore)
{
five_v_on = 1;
return 1;
}
static int __init badge4_init(void)
{
int ret;
if (!machine_is_badge4())
return -ENODEV;
GPCR = (BADGE4_GPIO_LGP2 | BADGE4_GPIO_LGP3 |
BADGE4_GPIO_LGP4 | BADGE4_GPIO_LGP5 |
BADGE4_GPIO_LGP6 | BADGE4_GPIO_LGP7 |
BADGE4_GPIO_LGP8 | BADGE4_GPIO_LGP9 |
BADGE4_GPIO_GPA_VID | BADGE4_GPIO_GPB_VID |
BADGE4_GPIO_GPC_VID);
GPDR &= ~BADGE4_GPIO_INT_VID;
GPDR |= (BADGE4_GPIO_LGP2 | BADGE4_GPIO_LGP3 |
BADGE4_GPIO_LGP4 | BADGE4_GPIO_LGP5 |
BADGE4_GPIO_LGP6 | BADGE4_GPIO_LGP7 |
BADGE4_GPIO_LGP8 | BADGE4_GPIO_LGP9 |
BADGE4_GPIO_GPA_VID | BADGE4_GPIO_GPB_VID |
BADGE4_GPIO_GPC_VID);
GPCR = (BADGE4_GPIO_SDSDA | BADGE4_GPIO_SDSCL);
GPDR |= (BADGE4_GPIO_SDSDA | BADGE4_GPIO_SDSCL);
GPCR = (BADGE4_GPIO_UART_HS1 | BADGE4_GPIO_UART_HS2);
GPDR |= (BADGE4_GPIO_UART_HS1 | BADGE4_GPIO_UART_HS2);
GPCR = BADGE4_GPIO_MUXSEL0;
GPDR |= BADGE4_GPIO_MUXSEL0;
GPDR &= ~(BADGE4_GPIO_TESTPT_J5 | BADGE4_GPIO_TESTPT_J6);
GPCR = BADGE4_GPIO_TESTPT_J7;
GPDR |= BADGE4_GPIO_TESTPT_J7;
GPCR = BADGE4_GPIO_PCMEN5V;
GPDR |= BADGE4_GPIO_PCMEN5V;
printk(KERN_DEBUG __FILE__ ": SDRAM CPLD typ1=%d typ0=%d\n",
!!(GPLR & BADGE4_GPIO_SDTYP1),
!!(GPLR & BADGE4_GPIO_SDTYP0));
PGSR = 0;
PWER = 0;
PCFR = 0;
PSDR = 0;
PWER |= PWER_GPIO26;
PWER |= PWER_RTC;
PGSR |= BADGE4_GPIO_SA1111_NRST;
PGSR |= (GPLR & (BADGE4_GPIO_SDTYP0|BADGE4_GPIO_SDTYP1));
ret = badge4_sa1111_init();
if (ret < 0)
printk(KERN_ERR
"%s: SA-1111 initialization failed (%d)\n",
__func__, ret);
badge4_set_5V(BADGE4_5V_INITIALLY, five_v_on);
sa11x0_register_mtd(&badge4_flash_data, &badge4_flash_resource, 1);
return 0;
}
void badge4_set_5V(unsigned subsystem, int on)
{
unsigned long flags;
unsigned old_5V_bitmap;
local_irq_save(flags);
old_5V_bitmap = badge4_5V_bitmap;
if (on) {
badge4_5V_bitmap |= subsystem;
} else {
badge4_5V_bitmap &= ~subsystem;
}
if ((!old_5V_bitmap) && (badge4_5V_bitmap)) {
printk(KERN_INFO "%s: enabling 5V supply rail\n", __func__);
GPSR = BADGE4_GPIO_PCMEN5V;
} else if ((old_5V_bitmap) && (!badge4_5V_bitmap)) {
printk(KERN_INFO "%s: disabling 5V supply rail\n", __func__);
GPCR = BADGE4_GPIO_PCMEN5V;
}
local_irq_restore(flags);
}
static void
badge4_uart_pm(struct uart_port *port, u_int state, u_int oldstate)
{
if (!state) {
Ser1SDCR0 |= SDCR0_UART;
}
}
static void __init badge4_map_io(void)
{
sa1100_map_io();
iotable_init(badge4_io_desc, ARRAY_SIZE(badge4_io_desc));
sa1100_register_uart_fns(&badge4_port_fns);
sa1100_register_uart(0, 3);
sa1100_register_uart(1, 1);
}
