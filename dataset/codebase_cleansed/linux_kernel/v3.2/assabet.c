void ASSABET_BCR_frob(unsigned int mask, unsigned int val)
{
unsigned long flags;
local_irq_save(flags);
BCR_value = (BCR_value & ~mask) | val;
ASSABET_BCR = BCR_value;
local_irq_restore(flags);
}
static void assabet_backlight_power(int on)
{
#ifndef ASSABET_PAL_VIDEO
if (on)
ASSABET_BCR_set(ASSABET_BCR_LIGHT_ON);
else
#endif
ASSABET_BCR_clear(ASSABET_BCR_LIGHT_ON);
}
static void assabet_lcd_power(int on)
{
#ifndef ASSABET_PAL_VIDEO
if (on) {
ASSABET_BCR_set(ASSABET_BCR_LCD_ON);
udelay(500);
} else
#endif
ASSABET_BCR_clear(ASSABET_BCR_LCD_ON);
}
static int assabet_irda_set_power(struct device *dev, unsigned int state)
{
static unsigned int bcr_state[4] = {
ASSABET_BCR_IRDA_MD0,
ASSABET_BCR_IRDA_MD1|ASSABET_BCR_IRDA_MD0,
ASSABET_BCR_IRDA_MD1,
0
};
if (state < 4) {
state = bcr_state[state];
ASSABET_BCR_clear(state ^ (ASSABET_BCR_IRDA_MD1|
ASSABET_BCR_IRDA_MD0));
ASSABET_BCR_set(state);
}
return 0;
}
static void assabet_irda_set_speed(struct device *dev, unsigned int speed)
{
if (speed < 4000000)
ASSABET_BCR_clear(ASSABET_BCR_IRDA_FSEL);
else
ASSABET_BCR_set(ASSABET_BCR_IRDA_FSEL);
}
static void __init assabet_init(void)
{
GPDR |= GPIO_GPIO16;
GPSR = GPIO_GPIO16;
GPDR |= GPIO_SSP_TXD | GPIO_SSP_SCLK | GPIO_SSP_SFRM;
GPCR = GPIO_SSP_TXD | GPIO_SSP_SCLK | GPIO_SSP_SFRM;
PWER = PWER_GPIO0;
PGSR = 0;
PCFR = 0;
PSDR = 0;
PPDR |= PPC_TXD3 | PPC_TXD1;
PPSR |= PPC_TXD3 | PPC_TXD1;
sa1100fb_lcd_power = assabet_lcd_power;
sa1100fb_backlight_power = assabet_backlight_power;
if (machine_has_neponset()) {
ASSABET_BCR = BCR_value = ASSABET_BCR_DB1111;
#ifndef CONFIG_ASSABET_NEPONSET
printk( "Warning: Neponset detected but full support "
"hasn't been configured in the kernel\n" );
#endif
}
sa11x0_register_mtd(&assabet_flash_data, assabet_flash_resources,
ARRAY_SIZE(assabet_flash_resources));
sa11x0_register_irda(&assabet_irda_data);
sa11x0_register_mcp(&assabet_mcp_data);
}
static void __init map_sa1100_gpio_regs( void )
{
unsigned long phys = __PREG(GPLR) & PMD_MASK;
unsigned long virt = io_p2v(phys);
int prot = PMD_TYPE_SECT | PMD_SECT_AP_WRITE | PMD_DOMAIN(DOMAIN_IO);
pmd_t *pmd;
pmd = pmd_offset(pgd_offset_k(virt), virt);
*pmd = __pmd(phys | prot);
flush_pmd_entry(pmd);
}
static void __init get_assabet_scr(void)
{
unsigned long scr, i;
GPDR |= 0x3fc;
GPSR = 0x3fc;
GPDR &= ~(0x3fc);
for(i = 100; i--; )
scr = GPLR;
GPDR |= 0x3fc;
scr &= 0x3fc;
SCR_value = scr;
}
static void __init
fixup_assabet(struct tag *tags, char **cmdline, struct meminfo *mi)
{
map_sa1100_gpio_regs();
get_assabet_scr();
if (machine_has_neponset())
printk("Neponset expansion board detected\n");
}
static void assabet_uart_pm(struct uart_port *port, u_int state, u_int oldstate)
{
if (port->mapbase == _Ser1UTCR0) {
if (state)
ASSABET_BCR_clear(ASSABET_BCR_RS232EN |
ASSABET_BCR_COM_RTS |
ASSABET_BCR_COM_DTR);
else
ASSABET_BCR_set(ASSABET_BCR_RS232EN |
ASSABET_BCR_COM_RTS |
ASSABET_BCR_COM_DTR);
}
}
static void assabet_set_mctrl(struct uart_port *port, u_int mctrl)
{
if (port->mapbase == _Ser1UTCR0) {
u_int set = 0, clear = 0;
if (mctrl & TIOCM_RTS)
clear |= ASSABET_BCR_COM_RTS;
else
set |= ASSABET_BCR_COM_RTS;
if (mctrl & TIOCM_DTR)
clear |= ASSABET_BCR_COM_DTR;
else
set |= ASSABET_BCR_COM_DTR;
ASSABET_BCR_clear(clear);
ASSABET_BCR_set(set);
}
}
static u_int assabet_get_mctrl(struct uart_port *port)
{
u_int ret = 0;
u_int bsr = ASSABET_BSR;
bsr = ASSABET_BSR;
if (port->mapbase == _Ser1UTCR0) {
if (bsr & ASSABET_BSR_COM_DCD)
ret |= TIOCM_CD;
if (bsr & ASSABET_BSR_COM_CTS)
ret |= TIOCM_CTS;
if (bsr & ASSABET_BSR_COM_DSR)
ret |= TIOCM_DSR;
} else if (port->mapbase == _Ser3UTCR0) {
if (bsr & ASSABET_BSR_RAD_DCD)
ret |= TIOCM_CD;
if (bsr & ASSABET_BSR_RAD_CTS)
ret |= TIOCM_CTS;
if (bsr & ASSABET_BSR_RAD_DSR)
ret |= TIOCM_DSR;
if (bsr & ASSABET_BSR_RAD_RI)
ret |= TIOCM_RI;
} else {
ret = TIOCM_CD | TIOCM_CTS | TIOCM_DSR;
}
return ret;
}
static void __init assabet_map_io(void)
{
sa1100_map_io();
iotable_init(assabet_io_desc, ARRAY_SIZE(assabet_io_desc));
Ser1SDCR0 |= SDCR0_SUS;
if (machine_has_neponset()) {
#ifdef CONFIG_ASSABET_NEPONSET
extern void neponset_map_io(void);
neponset_map_io();
#endif
} else {
sa1100_register_uart_fns(&assabet_port_fns);
}
sa1100_register_uart(0, 1);
sa1100_register_uart(2, 3);
}
