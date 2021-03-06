asmlinkage void debug_stub(void)
{
unsigned long hsr0;
int type = 0;
static u8 inited = 0;
if (!inited) {
debug_stub_init();
type = -1;
inited = 1;
}
hsr0 = __get_HSR(0);
if (hsr0 & HSR0_ETMD)
__set_HSR(0, hsr0 & ~HSR0_ETMD);
__debug_status.dcr &= ~DCR_SE;
if (__debug_frame->pc == (unsigned long) __break_hijack_kernel_event_breaks_here) {
*__debug_frame = *__frame;
__frame = __debug_frame->next_frame;
__debug_status.brr = (__debug_frame->tbr & TBR_TT) << 12;
__debug_status.brr |= BRR_EB;
}
if (__debug_frame->pc == (unsigned long) __debug_bug_trap + 4) {
__debug_frame->pc = __debug_frame->lr;
type = __debug_frame->gr8;
}
#ifdef CONFIG_GDBSTUB
gdbstub(type);
#endif
if (hsr0 & HSR0_ETMD)
__set_HSR(0, __get_HSR(0) | HSR0_ETMD);
}
static void __init debug_stub_init(void)
{
__set_IRR(6, 0xff000000);
__set_IITMR(1, 0x20000000);
asm volatile(" movgs gr0,ibar0 \n"
" movgs gr0,ibar1 \n"
" movgs gr0,ibar2 \n"
" movgs gr0,ibar3 \n"
" movgs gr0,dbar0 \n"
" movgs gr0,dbmr00 \n"
" movgs gr0,dbmr01 \n"
" movgs gr0,dbdr00 \n"
" movgs gr0,dbdr01 \n"
" movgs gr0,dbar1 \n"
" movgs gr0,dbmr10 \n"
" movgs gr0,dbmr11 \n"
" movgs gr0,dbdr10 \n"
" movgs gr0,dbdr11 \n"
);
if (__debug_frame->pc == (unsigned long) __debug_stub_init_break)
__debug_frame->pc = (unsigned long) start_kernel;
__debug_status.dcr = DCR_EBE;
#ifdef CONFIG_GDBSTUB
gdbstub_init();
#endif
__clr_MASK_all();
__clr_MASK(15);
__clr_RC(15);
}
void debug_stub_exit(int status)
{
#ifdef CONFIG_GDBSTUB
gdbstub_exit(status);
#endif
}
void debug_to_serial(const char *p, int n)
{
char ch;
for (; n > 0; n--) {
ch = *p++;
FLOWCTL_SET0(DTR);
LSR_WAIT_FOR0(THRE);
if (ch == 0x0a) {
__UART0(TX) = 0x0d;
mb();
LSR_WAIT_FOR0(THRE);
}
__UART0(TX) = ch;
mb();
FLOWCTL_CLEAR0(DTR);
}
}
void debug_to_serial2(const char *fmt, ...)
{
va_list va;
char buf[64];
int n;
va_start(va, fmt);
n = vsprintf(buf, fmt, va);
va_end(va);
debug_to_serial(buf, n);
}
void __init console_set_baud(unsigned baud)
{
unsigned value, high, low;
u8 lcr;
value = __serial_clock_speed_HZ / 16 / baud;
high = __serial_clock_speed_HZ / 16 / value;
low = __serial_clock_speed_HZ / 16 / (value + 1);
if (low + (high - low) / 2 > baud)
value++;
lcr = __UART0(LCR);
__UART0(LCR) |= UART_LCR_DLAB;
mb();
__UART0(DLL) = value & 0xff;
__UART0(DLM) = (value >> 8) & 0xff;
mb();
__UART0(LCR) = lcr;
mb();
}
int __init console_get_baud(void)
{
unsigned value;
u8 lcr;
lcr = __UART0(LCR);
__UART0(LCR) |= UART_LCR_DLAB;
mb();
value = __UART0(DLM) << 8;
value |= __UART0(DLL);
__UART0(LCR) = lcr;
mb();
return value;
}
void __debug_bug_printk(const char *file, unsigned line)
{
printk("kernel BUG at %s:%d!\n", file, line);
}
