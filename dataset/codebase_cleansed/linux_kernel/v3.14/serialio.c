const struct old_serial_port *spk_serial_init(int index)
{
int baud = 9600, quot = 0;
unsigned int cval = 0;
int cflag = CREAD | HUPCL | CLOCAL | B9600 | CS8;
const struct old_serial_port *ser = rs_table + index;
int err;
quot = ser->baud_base / baud;
cval = cflag & (CSIZE | CSTOPB);
#if defined(__powerpc__) || defined(__alpha__)
cval >>= 8;
#else
cval >>= 4;
#endif
if (cflag & PARENB)
cval |= UART_LCR_PARITY;
if (!(cflag & PARODD))
cval |= UART_LCR_EPAR;
if (synth_request_region(ser->port, 8)) {
printk(KERN_INFO "Ports not available, trying to steal them\n");
__release_region(&ioport_resource, ser->port, 8);
err = synth_request_region(ser->port, 8);
if (err) {
pr_warn("Unable to allocate port at %x, errno %i",
ser->port, err);
return NULL;
}
}
outb(cval | UART_LCR_DLAB, ser->port + UART_LCR);
outb(quot & 0xff, ser->port + UART_DLL);
outb(quot >> 8, ser->port + UART_DLM);
outb(cval, ser->port + UART_LCR);
outb(0, ser->port + UART_IER);
outb(UART_MCR_DTR | UART_MCR_RTS, ser->port + UART_MCR);
if (inb(ser->port + UART_LSR) == 0xff) {
synth_release_region(ser->port, 8);
serstate = NULL;
return NULL;
}
mdelay(1);
speakup_info.port_tts = ser->port;
serstate = ser;
start_serial_interrupt(ser->irq);
return ser;
}
static irqreturn_t synth_readbuf_handler(int irq, void *dev_id)
{
unsigned long flags;
int c;
spin_lock_irqsave(&speakup_info.spinlock, flags);
while (inb_p(speakup_info.port_tts + UART_LSR) & UART_LSR_DR) {
c = inb_p(speakup_info.port_tts+UART_RX);
synth->read_buff_add((u_char) c);
}
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
return IRQ_HANDLED;
}
static void start_serial_interrupt(int irq)
{
int rv;
if (synth->read_buff_add == NULL)
return;
rv = request_irq(irq, synth_readbuf_handler, IRQF_SHARED,
"serial", (void *) synth_readbuf_handler);
if (rv)
printk(KERN_ERR "Unable to request Speakup serial I R Q\n");
outb(UART_MCR_DTR | UART_MCR_RTS | UART_MCR_OUT2,
speakup_info.port_tts + UART_MCR);
outb(UART_IER_MSI|UART_IER_RLSI|UART_IER_RDI,
speakup_info.port_tts + UART_IER);
inb(speakup_info.port_tts+UART_LSR);
inb(speakup_info.port_tts+UART_RX);
inb(speakup_info.port_tts+UART_IIR);
inb(speakup_info.port_tts+UART_MSR);
outb(1, speakup_info.port_tts + UART_FCR);
}
void spk_stop_serial_interrupt(void)
{
if (speakup_info.port_tts == 0)
return;
if (synth->read_buff_add == NULL)
return;
outb(0, speakup_info.port_tts+UART_IER);
free_irq(serstate->irq, (void *) synth_readbuf_handler);
}
int spk_wait_for_xmitr(void)
{
int tmout = SPK_XMITR_TIMEOUT;
if ((synth->alive) && (timeouts >= NUM_DISABLE_TIMEOUTS)) {
pr_warn("%s: too many timeouts, deactivating speakup\n",
synth->long_name);
synth->alive = 0;
speakup_start_ttys();
timeouts = 0;
return 0;
}
while (spk_serial_tx_busy()) {
if (--tmout == 0) {
pr_warn("%s: timed out (tx busy)\n", synth->long_name);
timeouts++;
return 0;
}
udelay(1);
}
tmout = SPK_CTS_TIMEOUT;
while (!((inb_p(speakup_info.port_tts + UART_MSR)) & UART_MSR_CTS)) {
if (--tmout == 0) {
timeouts++;
return 0;
}
udelay(1);
}
timeouts = 0;
return 1;
}
unsigned char spk_serial_in(void)
{
int tmout = SPK_SERIAL_TIMEOUT;
while (!(inb_p(speakup_info.port_tts + UART_LSR) & UART_LSR_DR)) {
if (--tmout == 0) {
pr_warn("time out while waiting for input.\n");
return 0xff;
}
udelay(1);
}
return inb_p(speakup_info.port_tts + UART_RX);
}
unsigned char spk_serial_in_nowait(void)
{
unsigned char lsr;
lsr = inb_p(speakup_info.port_tts + UART_LSR);
if (!(lsr & UART_LSR_DR))
return 0;
return inb_p(speakup_info.port_tts + UART_RX);
}
int spk_serial_out(const char ch)
{
if (synth->alive && spk_wait_for_xmitr()) {
outb_p(ch, speakup_info.port_tts);
return 1;
}
return 0;
}
void spk_serial_release(void)
{
if (speakup_info.port_tts == 0)
return;
synth_release_region(speakup_info.port_tts, 8);
speakup_info.port_tts = 0;
}
