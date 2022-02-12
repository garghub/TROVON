static inline volatile struct a2232memory *a2232mem(unsigned int board)
{
return (volatile struct a2232memory *)ZTWO_VADDR(zd_a2232[board]->resource.start);
}
static inline volatile struct a2232status *a2232stat(unsigned int board,
unsigned int portonboard)
{
volatile struct a2232memory *mem = a2232mem(board);
return &(mem->Status[portonboard]);
}
static inline void a2232_receive_char(struct a2232_port *port, int ch, int err)
{
struct tty_struct *tty = port->gs.port.tty;
#if 0
switch(err) {
case TTY_BREAK:
break;
case TTY_PARITY:
break;
case TTY_OVERRUN:
break;
case TTY_FRAME:
break;
}
#endif
tty_insert_flip_char(tty, ch, err);
tty_flip_buffer_push(tty);
}
static void a2232_disable_tx_interrupts(void *ptr)
{
struct a2232_port *port;
volatile struct a2232status *stat;
unsigned long flags;
port = ptr;
stat = a2232stat(port->which_a2232, port->which_port_on_a2232);
stat->OutDisable = -1;
local_irq_save(flags);
port->gs.port.flags &= ~GS_TX_INTEN;
local_irq_restore(flags);
}
static void a2232_enable_tx_interrupts(void *ptr)
{
struct a2232_port *port;
volatile struct a2232status *stat;
unsigned long flags;
port = ptr;
stat = a2232stat(port->which_a2232, port->which_port_on_a2232);
stat->OutDisable = 0;
local_irq_save(flags);
port->gs.port.flags |= GS_TX_INTEN;
local_irq_restore(flags);
}
static void a2232_disable_rx_interrupts(void *ptr)
{
struct a2232_port *port;
port = ptr;
port->disable_rx = -1;
}
static void a2232_enable_rx_interrupts(void *ptr)
{
struct a2232_port *port;
port = ptr;
port->disable_rx = 0;
}
static int a2232_carrier_raised(struct tty_port *port)
{
struct a2232_port *ap = container_of(port, struct a2232_port, gs.port);
return ap->cd_status;
}
static void a2232_shutdown_port(void *ptr)
{
struct a2232_port *port;
volatile struct a2232status *stat;
unsigned long flags;
port = ptr;
stat = a2232stat(port->which_a2232, port->which_port_on_a2232);
local_irq_save(flags);
port->gs.port.flags &= ~GS_ACTIVE;
if (port->gs.port.tty && port->gs.port.tty->termios->c_cflag & HUPCL) {
stat->Command = ( (stat->Command & ~A2232CMD_CMask) |
A2232CMD_Close );
stat->OutFlush = -1;
stat->Setup = -1;
}
local_irq_restore(flags);
}
static int a2232_set_real_termios(void *ptr)
{
unsigned int cflag, baud, chsize, stopb, parity, softflow;
int rate;
int a2232_param, a2232_cmd;
unsigned long flags;
unsigned int i;
struct a2232_port *port = ptr;
volatile struct a2232status *status;
volatile struct a2232memory *mem;
if (!port->gs.port.tty || !port->gs.port.tty->termios) return 0;
status = a2232stat(port->which_a2232, port->which_port_on_a2232);
mem = a2232mem(port->which_a2232);
a2232_param = a2232_cmd = 0;
baud = port->gs.baud;
if (baud == 0) {
local_irq_save(flags);
status->Command = ( (status->Command & ~A2232CMD_CMask) |
A2232CMD_Close );
status->OutFlush = -1;
status->Setup = -1;
local_irq_restore(flags);
return 0;
}
rate = A2232_BAUD_TABLE_NOAVAIL;
for (i=0; i < A2232_BAUD_TABLE_NUM_RATES * 3; i += 3){
if (a2232_baud_table[i] == baud){
if (mem->Common.Crystal == A2232_TURBO) rate = a2232_baud_table[i+2];
else rate = a2232_baud_table[i+1];
}
}
if (rate == A2232_BAUD_TABLE_NOAVAIL){
printk("a2232: Board %d Port %d unsupported baud rate: %d baud. Using another.\n",port->which_a2232,port->which_port_on_a2232,baud);
rate = A2232PARAM_B9600;
}
a2232_param |= rate;
cflag = port->gs.port.tty->termios->c_cflag;
chsize = cflag & CSIZE;
switch (chsize){
case CS8: a2232_param |= A2232PARAM_8Bit; break;
case CS7: a2232_param |= A2232PARAM_7Bit; break;
case CS6: a2232_param |= A2232PARAM_6Bit; break;
case CS5: a2232_param |= A2232PARAM_5Bit; break;
default: printk("a2232: Board %d Port %d unsupported character size: %d. Using 8 data bits.\n",
port->which_a2232,port->which_port_on_a2232,chsize);
a2232_param |= A2232PARAM_8Bit; break;
}
stopb = cflag & CSTOPB;
if (stopb){
printk("a2232: Board %d Port %d 2 stop bits unsupported. Using 1 stop bit.\n",
port->which_a2232,port->which_port_on_a2232);
}
if (!(cflag & CRTSCTS)){
#ifndef A2232_SUPPRESS_RTSCTS_WARNING
printk("a2232: Board %d Port %d cannot switch off firmware-implemented RTS/CTS hardware flow control.\n",
port->which_a2232,port->which_port_on_a2232);
#endif
}
softflow = !!( port->gs.port.tty->termios->c_iflag & IXOFF );
parity = cflag & (PARENB | PARODD);
if (parity & PARENB){
if (parity & PARODD){
a2232_cmd |= A2232CMD_OddParity;
}
else{
a2232_cmd |= A2232CMD_EvenParity;
}
}
else a2232_cmd |= A2232CMD_NoParity;
if (cflag & CLOCAL)
port->gs.port.flags &= ~ASYNC_CHECK_CD;
else
port->gs.port.flags |= ASYNC_CHECK_CD;
local_irq_save(flags);
status->Param = a2232_param | A2232PARAM_RcvBaud;
status->Command = a2232_cmd | A2232CMD_Open | A2232CMD_Enable;
status->SoftFlow = softflow;
status->OutDisable = 0;
status->Setup = -1;
local_irq_restore(flags);
return 0;
}
static int a2232_chars_in_buffer(void *ptr)
{
struct a2232_port *port;
volatile struct a2232status *status;
unsigned char ret;
port = ptr;
status = a2232stat(port->which_a2232, port->which_port_on_a2232);
#if A2232_IOBUFLEN != 256
#error "Re-Implement a2232_chars_in_buffer()!"
#endif
ret = (status->OutHead - status->OutTail);
return ret;
}
static void a2232_close(void *ptr)
{
a2232_disable_tx_interrupts(ptr);
a2232_disable_rx_interrupts(ptr);
}
static void a2232_hungup(void *ptr)
{
a2232_close(ptr);
}
static int a2232_ioctl( struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
return -ENOIOCTLCMD;
}
static void a2232_throttle(struct tty_struct *tty)
{
struct a2232_port *port = tty->driver_data;
port->throttle_input = -1;
}
static void a2232_unthrottle(struct tty_struct *tty)
{
struct a2232_port *port = tty->driver_data;
port->throttle_input = 0;
}
static int a2232_open(struct tty_struct * tty, struct file * filp)
{
int line;
int retval;
struct a2232_port *port;
line = tty->index;
port = &a2232_ports[line];
tty->driver_data = port;
port->gs.port.tty = tty;
port->gs.port.count++;
retval = gs_init_port(&port->gs);
if (retval) {
port->gs.port.count--;
return retval;
}
port->gs.port.flags |= GS_ACTIVE;
retval = gs_block_til_ready(port, filp);
if (retval) {
port->gs.port.count--;
return retval;
}
a2232_enable_rx_interrupts(port);
return 0;
}
static irqreturn_t a2232_vbl_inter(int irq, void *data)
{
#if A2232_IOBUFLEN != 256
#error "Re-Implement a2232_vbl_inter()!"
#endif
struct a2232_port *port;
volatile struct a2232memory *mem;
volatile struct a2232status *status;
unsigned char newhead;
unsigned char bufpos;
unsigned char ncd, ocd, ccd;
volatile u_char *ibuf, *cbuf, *obuf;
int ch, err, n, p;
for (n = 0; n < nr_a2232; n++){
mem = a2232mem(n);
for (p = 0; p < NUMLINES; p++){
err = 0;
port = &a2232_ports[n*NUMLINES+p];
if ( port->gs.port.flags & GS_ACTIVE ){
status = a2232stat(n,p);
if (!port->disable_rx && !port->throttle_input){
newhead = status->InHead;
bufpos = status->InTail;
if (newhead != bufpos) {
ibuf = mem->InBuf[p];
cbuf = mem->InCtl[p];
while (bufpos != newhead) {
switch (cbuf[bufpos]) {
case A2232INCTL_EVENT:
switch (ibuf[bufpos++]) {
case A2232EVENT_Break:
break;
case A2232EVENT_Sync:
printk("A2232: 65EC02 software sent SYNC event, don't know what to do. Ignoring.");
break;
default:
printk("A2232: 65EC02 software broken, unknown event type %d occurred.\n",ibuf[bufpos-1]);
}
break;
case A2232INCTL_CHAR:
a2232_receive_char(port, ibuf[bufpos], err);
bufpos++;
break;
default:
printk("A2232: 65EC02 software broken, unknown data type %d occurred.\n",cbuf[bufpos]);
bufpos++;
}
}
status->InTail = bufpos;
}
}
obuf = mem->OutBuf[p];
bufpos = status->OutHead;
while ( (port->gs.xmit_cnt > 0) &&
(!port->gs.port.tty->stopped) &&
(!port->gs.port.tty->hw_stopped) ){
if (((bufpos+1) & A2232_IOBUFLENMASK) != status->OutTail) {
ch = port->gs.xmit_buf[port->gs.xmit_tail];
port->gs.xmit_tail = (port->gs.xmit_tail+1) & (SERIAL_XMIT_SIZE-1);
obuf[bufpos++] = ch;
port->gs.xmit_cnt--;
}
else{
break;
}
}
status->OutHead = bufpos;
if ((port->gs.xmit_cnt <= port->gs.wakeup_chars) && port->gs.port.tty) {
tty_wakeup(port->gs.port.tty);
}
}
}
newhead = mem->Common.CDHead;
bufpos = mem->Common.CDTail;
if (newhead != bufpos){
ocd = mem->Common.CDStatus;
while (newhead != bufpos){
ncd = mem->CDBuf[bufpos++];
ccd = ncd ^ ocd;
ocd = ncd;
for(p=0; p < NUMLINES; p++){
if (ccd & 1){
struct a2232_port *port = &a2232_ports[n*7+p];
port->cd_status = !(ncd & 1);
if (!(port->gs.port.flags & ASYNC_CHECK_CD))
;
else if (port->cd_status) {
wake_up_interruptible(&port->gs.port.open_wait);
}
else {
if (port->gs.port.tty)
tty_hangup (port->gs.port.tty);
}
}
ccd >>= 1;
ncd >>= 1;
}
}
mem->Common.CDStatus = ocd;
mem->Common.CDTail = bufpos;
}
}
return IRQ_HANDLED;
}
static void a2232_init_portstructs(void)
{
struct a2232_port *port;
int i;
for (i = 0; i < MAX_A2232_BOARDS*NUMLINES; i++) {
port = a2232_ports + i;
tty_port_init(&port->gs.port);
port->gs.port.ops = &a2232_port_ops;
port->which_a2232 = i/NUMLINES;
port->which_port_on_a2232 = i%NUMLINES;
port->disable_rx = port->throttle_input = port->cd_status = 0;
port->gs.magic = A2232_MAGIC;
port->gs.close_delay = HZ/2;
port->gs.closing_wait = 30 * HZ;
port->gs.rd = &a2232_real_driver;
}
}
static int a2232_init_drivers(void)
{
int error;
a2232_driver = alloc_tty_driver(NUMLINES * nr_a2232);
if (!a2232_driver)
return -ENOMEM;
a2232_driver->owner = THIS_MODULE;
a2232_driver->driver_name = "commodore_a2232";
a2232_driver->name = "ttyY";
a2232_driver->major = A2232_NORMAL_MAJOR;
a2232_driver->type = TTY_DRIVER_TYPE_SERIAL;
a2232_driver->subtype = SERIAL_TYPE_NORMAL;
a2232_driver->init_termios = tty_std_termios;
a2232_driver->init_termios.c_cflag =
B9600 | CS8 | CREAD | HUPCL | CLOCAL;
a2232_driver->init_termios.c_ispeed = 9600;
a2232_driver->init_termios.c_ospeed = 9600;
a2232_driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(a2232_driver, &a2232_ops);
if ((error = tty_register_driver(a2232_driver))) {
printk(KERN_ERR "A2232: Couldn't register A2232 driver, error = %d\n",
error);
put_tty_driver(a2232_driver);
return 1;
}
return 0;
}
static int __init a2232board_init(void)
{
struct zorro_dev *z;
unsigned int boardaddr;
int bcount;
short start;
u_char *from;
volatile u_char *to;
volatile struct a2232memory *mem;
int error, i;
#ifdef CONFIG_SMP
return -ENODEV;
#endif
if (!MACH_IS_AMIGA){
return -ENODEV;
}
printk("Commodore A2232 driver initializing.\n");
z = NULL;
nr_a2232 = 0;
while ( (z = zorro_find_device(ZORRO_WILDCARD, z)) ){
if ( (z->id != ZORRO_PROD_CBM_A2232_PROTOTYPE) &&
(z->id != ZORRO_PROD_CBM_A2232) ){
continue;
}
if (!zorro_request_device(z,"A2232 driver"))
continue;
printk("Commodore A2232 found (#%d).\n",nr_a2232);
zd_a2232[nr_a2232] = z;
boardaddr = ZTWO_VADDR( z->resource.start );
printk("Board is located at address 0x%x, size is 0x%x.\n", boardaddr, (unsigned int) ((z->resource.end+1) - (z->resource.start)));
mem = (volatile struct a2232memory *) boardaddr;
(void) mem->Enable6502Reset;
to = (u_char *)mem; from = a2232_65EC02code; bcount = sizeof(a2232_65EC02code) - 2;
start = *(short *)from;
from += sizeof(start);
to += start;
while(bcount--) *to++ = *from++;
printk("65EC02 software uploaded to the A2232 memory.\n");
mem->Common.Crystal = A2232_UNKNOWN;
(void) mem->ResetBoard;
printk("A2232's 65EC02 CPU up and running.\n");
for (bcount = 0; bcount < 2000; bcount++) {
udelay(1000);
if (mem->Common.Crystal)
break;
}
printk((mem->Common.Crystal?"A2232 oscillator crystal detected by 65EC02 software: ":"65EC02 software could not determine A2232 oscillator crystal: "));
switch (mem->Common.Crystal){
case A2232_UNKNOWN:
printk("Unknown crystal.\n");
break;
case A2232_NORMAL:
printk ("Normal crystal.\n");
break;
case A2232_TURBO:
printk ("Turbo crystal.\n");
break;
default:
printk ("0x%x. Huh?\n",mem->Common.Crystal);
}
nr_a2232++;
}
printk("Total: %d A2232 boards initialized.\n", nr_a2232);
a2232_init_portstructs();
if (a2232_init_drivers()) return -ENODEV;
error = request_irq(IRQ_AMIGA_VERTB, a2232_vbl_inter, 0,
"A2232 serial VBL", a2232_driver_ID);
if (error) {
for (i = 0; i < nr_a2232; i++)
zorro_release_device(zd_a2232[i]);
tty_unregister_driver(a2232_driver);
put_tty_driver(a2232_driver);
}
return error;
}
static void __exit a2232board_exit(void)
{
int i;
for (i = 0; i < nr_a2232; i++) {
zorro_release_device(zd_a2232[i]);
}
tty_unregister_driver(a2232_driver);
put_tty_driver(a2232_driver);
free_irq(IRQ_AMIGA_VERTB, a2232_driver_ID);
}
