static void udbg_550_flush(void)
{
if (udbg_comport) {
while ((in_8(&udbg_comport->lsr) & LSR_THRE) == 0)
;
}
}
static void udbg_550_putc(char c)
{
if (udbg_comport) {
if (c == '\n')
udbg_550_putc('\r');
udbg_550_flush();
out_8(&udbg_comport->thr, c);
}
}
static int udbg_550_getc_poll(void)
{
if (udbg_comport) {
if ((in_8(&udbg_comport->lsr) & LSR_DR) != 0)
return in_8(&udbg_comport->rbr);
else
return -1;
}
return -1;
}
static int udbg_550_getc(void)
{
if (udbg_comport) {
while ((in_8(&udbg_comport->lsr) & LSR_DR) == 0)
;
return in_8(&udbg_comport->rbr);
}
return -1;
}
void udbg_init_uart(void __iomem *comport, unsigned int speed,
unsigned int clock)
{
unsigned int dll, base_bauds;
if (clock == 0)
clock = 1843200;
if (speed == 0)
speed = 9600;
base_bauds = clock / 16;
dll = base_bauds / speed;
if (comport) {
udbg_comport = (struct NS16550 __iomem *)comport;
out_8(&udbg_comport->lcr, 0x00);
out_8(&udbg_comport->ier, 0xff);
out_8(&udbg_comport->ier, 0x00);
out_8(&udbg_comport->lcr, LCR_DLAB);
out_8(&udbg_comport->dll, dll & 0xff);
out_8(&udbg_comport->dlm, dll >> 8);
out_8(&udbg_comport->lcr, 0x03);
out_8(&udbg_comport->mcr, 0x03);
out_8(&udbg_comport->fcr ,0x07);
udbg_putc = udbg_550_putc;
udbg_flush = udbg_550_flush;
udbg_getc = udbg_550_getc;
udbg_getc_poll = udbg_550_getc_poll;
}
}
unsigned int udbg_probe_uart_speed(void __iomem *comport, unsigned int clock)
{
unsigned int dll, dlm, divisor, prescaler, speed;
u8 old_lcr;
struct NS16550 __iomem *port = comport;
old_lcr = in_8(&port->lcr);
out_8(&port->lcr, LCR_DLAB);
dll = in_8(&port->dll);
dlm = in_8(&port->dlm);
divisor = dlm << 8 | dll;
if (in_8(&port->mcr) & 0x80)
prescaler = 4;
else
prescaler = 1;
out_8(&port->lcr, old_lcr);
speed = (clock / prescaler) / (divisor * 16);
if (speed > (clock / 16))
speed = 9600;
return speed;
}
void udbg_maple_real_flush(void)
{
if (udbg_comport) {
while ((real_readb(&udbg_comport->lsr) & LSR_THRE) == 0)
;
}
}
void udbg_maple_real_putc(char c)
{
if (udbg_comport) {
if (c == '\n')
udbg_maple_real_putc('\r');
udbg_maple_real_flush();
real_writeb(c, &udbg_comport->thr); eieio();
}
}
void __init udbg_init_maple_realmode(void)
{
udbg_comport = (struct NS16550 __iomem *)0xf40003f8;
udbg_putc = udbg_maple_real_putc;
udbg_flush = udbg_maple_real_flush;
udbg_getc = NULL;
udbg_getc_poll = NULL;
}
void udbg_pas_real_flush(void)
{
if (udbg_comport) {
while ((real_205_readb(&udbg_comport->lsr) & LSR_THRE) == 0)
;
}
}
void udbg_pas_real_putc(char c)
{
if (udbg_comport) {
if (c == '\n')
udbg_pas_real_putc('\r');
udbg_pas_real_flush();
real_205_writeb(c, &udbg_comport->thr); eieio();
}
}
void udbg_init_pas_realmode(void)
{
udbg_comport = (struct NS16550 __iomem *)0xfcff03f8UL;
udbg_putc = udbg_pas_real_putc;
udbg_flush = udbg_pas_real_flush;
udbg_getc = NULL;
udbg_getc_poll = NULL;
}
static void udbg_44x_as1_flush(void)
{
if (udbg_comport) {
while ((as1_readb(&udbg_comport->lsr) & LSR_THRE) == 0)
;
}
}
static void udbg_44x_as1_putc(char c)
{
if (udbg_comport) {
if (c == '\n')
udbg_44x_as1_putc('\r');
udbg_44x_as1_flush();
as1_writeb(c, &udbg_comport->thr); eieio();
}
}
static int udbg_44x_as1_getc(void)
{
if (udbg_comport) {
while ((as1_readb(&udbg_comport->lsr) & LSR_DR) == 0)
;
return as1_readb(&udbg_comport->rbr);
}
return -1;
}
void __init udbg_init_44x_as1(void)
{
udbg_comport =
(struct NS16550 __iomem *)PPC44x_EARLY_DEBUG_VIRTADDR;
udbg_putc = udbg_44x_as1_putc;
udbg_flush = udbg_44x_as1_flush;
udbg_getc = udbg_44x_as1_getc;
}
static void udbg_40x_real_flush(void)
{
if (udbg_comport) {
while ((real_readb(&udbg_comport->lsr) & LSR_THRE) == 0)
;
}
}
static void udbg_40x_real_putc(char c)
{
if (udbg_comport) {
if (c == '\n')
udbg_40x_real_putc('\r');
udbg_40x_real_flush();
real_writeb(c, &udbg_comport->thr); eieio();
}
}
static int udbg_40x_real_getc(void)
{
if (udbg_comport) {
while ((real_readb(&udbg_comport->lsr) & LSR_DR) == 0)
;
return real_readb(&udbg_comport->rbr);
}
return -1;
}
void __init udbg_init_40x_realmode(void)
{
udbg_comport = (struct NS16550 __iomem *)
CONFIG_PPC_EARLY_DEBUG_40x_PHYSADDR;
udbg_putc = udbg_40x_real_putc;
udbg_flush = udbg_40x_real_flush;
udbg_getc = udbg_40x_real_getc;
udbg_getc_poll = NULL;
}
static void udbg_wsp_flush(void)
{
if (udbg_comport) {
while ((readb(&udbg_comport->lsr) & LSR_THRE) == 0)
;
}
}
static void udbg_wsp_putc(char c)
{
if (udbg_comport) {
if (c == '\n')
udbg_wsp_putc('\r');
udbg_wsp_flush();
writeb(c, &udbg_comport->thr); eieio();
}
}
static int udbg_wsp_getc(void)
{
if (udbg_comport) {
while ((readb(&udbg_comport->lsr) & LSR_DR) == 0)
;
return readb(&udbg_comport->rbr);
}
return -1;
}
static int udbg_wsp_getc_poll(void)
{
if (udbg_comport)
if (readb(&udbg_comport->lsr) & LSR_DR)
return readb(&udbg_comport->rbr);
return -1;
}
void __init udbg_init_wsp(void)
{
udbg_comport = (struct NS16550 __iomem *)WSP_UART_VIRT;
udbg_init_uart(udbg_comport, 57600, 50000000);
udbg_putc = udbg_wsp_putc;
udbg_flush = udbg_wsp_flush;
udbg_getc = udbg_wsp_getc;
udbg_getc_poll = udbg_wsp_getc_poll;
}
