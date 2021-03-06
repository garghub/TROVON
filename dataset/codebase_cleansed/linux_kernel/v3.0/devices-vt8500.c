void __init vt8500_set_resources(void)
{
struct resource tmp[3];
tmp[0] = wmt_mmio_res(VT8500_LCDC_BASE, SZ_1K);
tmp[1] = wmt_irq_res(IRQ_LCDC);
wmt_res_add(&vt8500_device_lcdc, tmp, 2);
tmp[0] = wmt_mmio_res(VT8500_UART0_BASE, 0x1040);
tmp[1] = wmt_irq_res(IRQ_UART0);
wmt_res_add(&vt8500_device_uart0, tmp, 2);
tmp[0] = wmt_mmio_res(VT8500_UART1_BASE, 0x1040);
tmp[1] = wmt_irq_res(IRQ_UART1);
wmt_res_add(&vt8500_device_uart1, tmp, 2);
tmp[0] = wmt_mmio_res(VT8500_UART2_BASE, 0x1040);
tmp[1] = wmt_irq_res(IRQ_UART2);
wmt_res_add(&vt8500_device_uart2, tmp, 2);
tmp[0] = wmt_mmio_res(VT8500_UART3_BASE, 0x1040);
tmp[1] = wmt_irq_res(IRQ_UART3);
wmt_res_add(&vt8500_device_uart3, tmp, 2);
tmp[0] = wmt_mmio_res(VT8500_EHCI_BASE, SZ_512);
tmp[1] = wmt_irq_res(IRQ_EHCI);
wmt_res_add(&vt8500_device_ehci, tmp, 2);
tmp[0] = wmt_mmio_res(VT8500_GEGEA_BASE, SZ_256);
wmt_res_add(&vt8500_device_ge_rops, tmp, 1);
tmp[0] = wmt_mmio_res(VT8500_PWM_BASE, 0x44);
wmt_res_add(&vt8500_device_pwm, tmp, 1);
tmp[0] = wmt_mmio_res(VT8500_RTC_BASE, 0x2c);
tmp[1] = wmt_irq_res(IRQ_RTC);
tmp[2] = wmt_irq_res(IRQ_RTCSM);
wmt_res_add(&vt8500_device_rtc, tmp, 3);
}
static void __init vt8500_set_externs(void)
{
wmt_ic_base = VT8500_IC_BASE;
wmt_gpio_base = VT8500_GPIO_BASE;
wmt_pmc_base = VT8500_PMC_BASE;
wmt_i8042_base = VT8500_PS2_BASE;
wmt_nr_irqs = VT8500_NR_IRQS;
wmt_timer_irq = IRQ_PMCOS0;
wmt_gpio_ext_irq[0] = IRQ_EXT0;
wmt_gpio_ext_irq[1] = IRQ_EXT1;
wmt_gpio_ext_irq[2] = IRQ_EXT2;
wmt_gpio_ext_irq[3] = IRQ_EXT3;
wmt_gpio_ext_irq[4] = IRQ_EXT4;
wmt_gpio_ext_irq[5] = IRQ_EXT5;
wmt_gpio_ext_irq[6] = IRQ_EXT6;
wmt_gpio_ext_irq[7] = IRQ_EXT7;
wmt_i8042_kbd_irq = IRQ_PS2KBD;
wmt_i8042_aux_irq = IRQ_PS2MOUSE;
}
void __init vt8500_map_io(void)
{
iotable_init(wmt_io_desc, ARRAY_SIZE(wmt_io_desc));
vt8500_set_externs();
}
