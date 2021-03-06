void gdbstub_io_init(void)
{
__UART(LCR) = UART_LCR_WLEN8;
__UART(FCR) =
UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR |
UART_FCR_CLEAR_XMIT |
UART_FCR_TRIGGER_1;
FLOWCTL_CLEAR(DTR);
FLOWCTL_SET(RTS);
__UART(IER) = UART_IER_RDI | UART_IER_RLSI;
mb();
__set_IRR(6, __UART_IRR_NMI);
}
void gdbstub_set_baud(unsigned baud)
{
unsigned value, high, low;
u8 lcr;
value = __serial_clock_speed_HZ / 16 / baud;
high = __serial_clock_speed_HZ / 16 / value;
low = __serial_clock_speed_HZ / 16 / (value + 1);
if (low + (high - low) / 2 > baud)
value++;
lcr = __UART(LCR);
__UART(LCR) |= UART_LCR_DLAB;
mb();
__UART(DLL) = value & 0xff;
__UART(DLM) = (value >> 8) & 0xff;
mb();
__UART(LCR) = lcr;
mb();
}
void gdbstub_do_rx(void)
{
unsigned ix, nix;
ix = gdbstub_rx_inp;
while (__UART(LSR) & UART_LSR_DR) {
nix = (ix + 2) & 0xfff;
if (nix == gdbstub_rx_outp)
break;
gdbstub_rx_buffer[ix++] = __UART(LSR);
gdbstub_rx_buffer[ix++] = __UART(RX);
ix = nix;
}
gdbstub_rx_inp = ix;
__clr_RC(15);
__clr_IRL();
}
int gdbstub_rx_char(unsigned char *_ch, int nonblock)
{
unsigned ix;
u8 ch, st;
*_ch = 0xff;
if (gdbstub_rx_unget) {
*_ch = gdbstub_rx_unget;
gdbstub_rx_unget = 0;
return 0;
}
try_again:
gdbstub_do_rx();
ix = gdbstub_rx_outp;
if (ix == gdbstub_rx_inp) {
if (nonblock)
return -EAGAIN;
goto try_again;
}
st = gdbstub_rx_buffer[ix++];
ch = gdbstub_rx_buffer[ix++];
gdbstub_rx_outp = ix & 0x00000fff;
if (st & UART_LSR_BI) {
gdbstub_proto("### GDB Rx Break Detected ###\n");
return -EINTR;
}
else if (st & (UART_LSR_FE|UART_LSR_OE|UART_LSR_PE)) {
gdbstub_io("### GDB Rx Error (st=%02x) ###\n",st);
return -EIO;
}
else {
gdbstub_io("### GDB Rx %02x (st=%02x) ###\n",ch,st);
*_ch = ch & 0x7f;
return 0;
}
}
void gdbstub_tx_char(unsigned char ch)
{
FLOWCTL_SET(DTR);
LSR_WAIT_FOR(THRE);
if (ch == 0x0a) {
__UART(TX) = 0x0d;
mb();
LSR_WAIT_FOR(THRE);
}
__UART(TX) = ch;
mb();
FLOWCTL_CLEAR(DTR);
}
void gdbstub_tx_flush(void)
{
LSR_WAIT_FOR(TEMT);
LSR_WAIT_FOR(THRE);
FLOWCTL_CLEAR(DTR);
}
