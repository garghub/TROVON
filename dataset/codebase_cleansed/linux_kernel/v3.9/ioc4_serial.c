static inline int port_is_active(struct ioc4_port *port,
struct uart_port *uart_port)
{
if (port) {
if ((port->ip_flags & PORT_ACTIVE)
&& (port->ip_port == uart_port))
return 1;
}
return 0;
}
static inline void
write_ireg(struct ioc4_soft *ioc4_soft, uint32_t val, int which, int type)
{
struct ioc4_misc_regs __iomem *mem = ioc4_soft->is_ioc4_misc_addr;
unsigned long flags;
spin_lock_irqsave(&ioc4_soft->is_ir_lock, flags);
switch (type) {
case IOC4_SIO_INTR_TYPE:
switch (which) {
case IOC4_W_IES:
writel(val, &mem->sio_ies.raw);
break;
case IOC4_W_IEC:
writel(val, &mem->sio_iec.raw);
break;
}
break;
case IOC4_OTHER_INTR_TYPE:
switch (which) {
case IOC4_W_IES:
writel(val, &mem->other_ies.raw);
break;
case IOC4_W_IEC:
writel(val, &mem->other_iec.raw);
break;
}
break;
default:
break;
}
spin_unlock_irqrestore(&ioc4_soft->is_ir_lock, flags);
}
static int set_baud(struct ioc4_port *port, int baud)
{
int actual_baud;
int diff;
int lcr;
unsigned short divisor;
struct ioc4_uartregs __iomem *uart;
divisor = SER_DIVISOR(baud, port->ip_pci_bus_speed);
if (!divisor)
return 1;
actual_baud = DIVISOR_TO_BAUD(divisor, port->ip_pci_bus_speed);
diff = actual_baud - baud;
if (diff < 0)
diff = -diff;
if (diff * 100 > actual_baud)
return 1;
uart = port->ip_uart_regs;
lcr = readb(&uart->i4u_lcr);
writeb(lcr | UART_LCR_DLAB, &uart->i4u_lcr);
writeb((unsigned char)divisor, &uart->i4u_dll);
writeb((unsigned char)(divisor >> 8), &uart->i4u_dlm);
writeb(lcr, &uart->i4u_lcr);
return 0;
}
static struct ioc4_port *get_ioc4_port(struct uart_port *the_port, int set)
{
struct ioc4_driver_data *idd = dev_get_drvdata(the_port->dev);
struct ioc4_control *control = idd->idd_serial_data;
struct ioc4_port *port;
int port_num, port_type;
if (control) {
for ( port_num = 0; port_num < IOC4_NUM_SERIAL_PORTS;
port_num++ ) {
port = control->ic_port[port_num].icp_port;
if (!port)
continue;
for (port_type = UART_PORT_MIN;
port_type < UART_PORT_COUNT;
port_type++) {
if (the_port == port->ip_all_ports
[port_type]) {
if (set) {
port->ip_port = the_port;
}
return port;
}
}
}
}
return NULL;
}
static inline uint32_t
pending_intrs(struct ioc4_soft *soft, int type)
{
struct ioc4_misc_regs __iomem *mem = soft->is_ioc4_misc_addr;
unsigned long flag;
uint32_t intrs = 0;
BUG_ON(!((type == IOC4_SIO_INTR_TYPE)
|| (type == IOC4_OTHER_INTR_TYPE)));
spin_lock_irqsave(&soft->is_ir_lock, flag);
switch (type) {
case IOC4_SIO_INTR_TYPE:
intrs = readl(&mem->sio_ir.raw) & readl(&mem->sio_ies.raw);
break;
case IOC4_OTHER_INTR_TYPE:
intrs = readl(&mem->other_ir.raw) & readl(&mem->other_ies.raw);
intrs &= ~(IOC4_OTHER_IR_ATA_INT | IOC4_OTHER_IR_ATA_MEMERR);
break;
default:
break;
}
spin_unlock_irqrestore(&soft->is_ir_lock, flag);
return intrs;
}
static int inline port_init(struct ioc4_port *port)
{
uint32_t sio_cr;
struct hooks *hooks = port->ip_hooks;
struct ioc4_uartregs __iomem *uart;
writel(IOC4_SSCR_RESET, &port->ip_serial_regs->sscr);
do
sio_cr = readl(&port->ip_mem->sio_cr.raw);
while (!(sio_cr & IOC4_SIO_CR_SIO_DIAG_IDLE));
writel(0, &port->ip_serial_regs->sscr);
port->ip_tx_prod = readl(&port->ip_serial_regs->stcir) & PROD_CONS_MASK;
writel(port->ip_tx_prod, &port->ip_serial_regs->stpir);
port->ip_rx_cons = readl(&port->ip_serial_regs->srpir) & PROD_CONS_MASK;
writel(port->ip_rx_cons | IOC4_SRCIR_ARM, &port->ip_serial_regs->srcir);
uart = port->ip_uart_regs;
writeb(0, &uart->i4u_lcr);
writeb(0, &uart->i4u_ier);
set_baud(port, port->ip_baud);
writeb(UART_LCR_WLEN8 | 0, &uart->i4u_lcr);
writeb(UART_FCR_ENABLE_FIFO, &uart->i4u_fcr);
writeb(UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT,
&uart->i4u_fcr);
writeb(0, &uart->i4u_mcr);
readb(&uart->i4u_msr);
if (port->ip_hooks == &hooks_array[0]
|| port->ip_hooks == &hooks_array[2]) {
unsigned long ring_pci_addr;
uint32_t __iomem *sbbr_l;
uint32_t __iomem *sbbr_h;
if (port->ip_hooks == &hooks_array[0]) {
sbbr_l = &port->ip_serial->sbbr01_l;
sbbr_h = &port->ip_serial->sbbr01_h;
} else {
sbbr_l = &port->ip_serial->sbbr23_l;
sbbr_h = &port->ip_serial->sbbr23_h;
}
ring_pci_addr = (unsigned long __iomem)port->ip_dma_ringbuf;
DPRINT_CONFIG(("%s: ring_pci_addr 0x%lx\n",
__func__, ring_pci_addr));
writel((unsigned int)((uint64_t)ring_pci_addr >> 32), sbbr_h);
writel((unsigned int)ring_pci_addr | IOC4_BUF_SIZE_BIT, sbbr_l);
}
writel(IOC4_SRTR_HZ / 100, &port->ip_serial_regs->srtr);
port->ip_sscr = (ENTRIES_PER_RING * 3 / 4);
writel(port->ip_sscr, &port->ip_serial_regs->sscr);
write_ireg(port->ip_ioc4_soft, hooks->intr_clear,
IOC4_W_IEC, IOC4_SIO_INTR_TYPE);
port->ip_ienb &= ~hooks->intr_clear;
writel(hooks->intr_clear, &port->ip_mem->sio_ir.raw);
return 0;
}
static void handle_dma_error_intr(void *arg, uint32_t other_ir)
{
struct ioc4_port *port = (struct ioc4_port *)arg;
struct hooks *hooks = port->ip_hooks;
unsigned long flags;
spin_lock_irqsave(&port->ip_lock, flags);
writel(hooks->intr_dma_error, &port->ip_mem->other_ir.raw);
if (readl(&port->ip_mem->pci_err_addr_l.raw) & IOC4_PCI_ERR_ADDR_VLD) {
printk(KERN_ERR
"PCI error address is 0x%llx, "
"master is serial port %c %s\n",
(((uint64_t)readl(&port->ip_mem->pci_err_addr_h)
<< 32)
| readl(&port->ip_mem->pci_err_addr_l.raw))
& IOC4_PCI_ERR_ADDR_ADDR_MSK, '1' +
((char)(readl(&port->ip_mem->pci_err_addr_l.raw) &
IOC4_PCI_ERR_ADDR_MST_NUM_MSK) >> 1),
(readl(&port->ip_mem->pci_err_addr_l.raw)
& IOC4_PCI_ERR_ADDR_MST_TYP_MSK)
? "RX" : "TX");
if (readl(&port->ip_mem->pci_err_addr_l.raw)
& IOC4_PCI_ERR_ADDR_MUL_ERR) {
printk(KERN_ERR
"Multiple errors occurred\n");
}
}
spin_unlock_irqrestore(&port->ip_lock, flags);
write_ireg(port->ip_ioc4_soft, hooks->intr_dma_error, IOC4_W_IES,
IOC4_OTHER_INTR_TYPE);
}
static void
intr_connect(struct ioc4_soft *soft, int type,
uint32_t intrbits, ioc4_intr_func_f * intr, void *info)
{
int i;
struct ioc4_intr_info *intr_ptr;
BUG_ON(!((type == IOC4_SIO_INTR_TYPE)
|| (type == IOC4_OTHER_INTR_TYPE)));
i = atomic_inc_return(&soft-> is_intr_type[type].is_num_intrs) - 1;
BUG_ON(!(i < MAX_IOC4_INTR_ENTS || (printk("i %d\n", i), 0)));
intr_ptr = &soft->is_intr_type[type].is_intr_info[i];
intr_ptr->sd_bits = intrbits;
intr_ptr->sd_intr = intr;
intr_ptr->sd_info = info;
}
static irqreturn_t ioc4_intr(int irq, void *arg)
{
struct ioc4_soft *soft;
uint32_t this_ir, this_mir;
int xx, num_intrs = 0;
int intr_type;
int handled = 0;
struct ioc4_intr_info *intr_info;
soft = arg;
for (intr_type = 0; intr_type < IOC4_NUM_INTR_TYPES; intr_type++) {
num_intrs = (int)atomic_read(
&soft->is_intr_type[intr_type].is_num_intrs);
this_mir = this_ir = pending_intrs(soft, intr_type);
for (xx = 0; xx < num_intrs; xx++) {
intr_info = &soft->is_intr_type[intr_type].is_intr_info[xx];
if ((this_mir = this_ir & intr_info->sd_bits)) {
handled++;
write_ireg(soft, intr_info->sd_bits, IOC4_W_IEC,
intr_type);
intr_info->sd_intr(intr_info->sd_info, this_mir);
this_ir &= ~this_mir;
}
}
}
#ifdef DEBUG_INTERRUPTS
{
struct ioc4_misc_regs __iomem *mem = soft->is_ioc4_misc_addr;
unsigned long flag;
spin_lock_irqsave(&soft->is_ir_lock, flag);
printk ("%s : %d : mem 0x%p sio_ir 0x%x sio_ies 0x%x "
"other_ir 0x%x other_ies 0x%x mask 0x%x\n",
__func__, __LINE__,
(void *)mem, readl(&mem->sio_ir.raw),
readl(&mem->sio_ies.raw),
readl(&mem->other_ir.raw),
readl(&mem->other_ies.raw),
IOC4_OTHER_IR_ATA_INT | IOC4_OTHER_IR_ATA_MEMERR);
spin_unlock_irqrestore(&soft->is_ir_lock, flag);
}
#endif
return handled ? IRQ_HANDLED : IRQ_NONE;
}
static int inline ioc4_attach_local(struct ioc4_driver_data *idd)
{
struct ioc4_port *port;
struct ioc4_port *ports[IOC4_NUM_SERIAL_PORTS];
int port_number;
uint16_t ioc4_revid_min = 62;
uint16_t ioc4_revid;
struct pci_dev *pdev = idd->idd_pdev;
struct ioc4_control* control = idd->idd_serial_data;
struct ioc4_soft *soft = control->ic_soft;
void __iomem *ioc4_misc = idd->idd_misc_regs;
void __iomem *ioc4_serial = soft->is_ioc4_serial_addr;
pci_read_config_word(pdev, PCI_COMMAND_SPECIAL, &ioc4_revid);
printk(KERN_INFO "IOC4 firmware revision %d\n", ioc4_revid);
if (ioc4_revid < ioc4_revid_min) {
printk(KERN_WARNING
"IOC4 serial not supported on firmware rev %d, "
"please upgrade to rev %d or higher\n",
ioc4_revid, ioc4_revid_min);
return -EPERM;
}
BUG_ON(ioc4_misc == NULL);
BUG_ON(ioc4_serial == NULL);
for (port_number = 0; port_number < IOC4_NUM_SERIAL_PORTS;
port_number++) {
port = kzalloc(sizeof(struct ioc4_port), GFP_KERNEL);
if (!port) {
printk(KERN_WARNING
"IOC4 serial memory not available for port\n");
return -ENOMEM;
}
spin_lock_init(&port->ip_lock);
ports[port_number] = port;
control->ic_port[port_number].icp_port = port;
port->ip_ioc4_soft = soft;
port->ip_pdev = pdev;
port->ip_ienb = 0;
if (idd->count_period/IOC4_EXTINT_COUNT_DIVISOR < 20) {
port->ip_pci_bus_speed = IOC4_SER_XIN_CLK_66;
} else {
port->ip_pci_bus_speed = IOC4_SER_XIN_CLK_33;
}
port->ip_baud = 9600;
port->ip_control = control;
port->ip_mem = ioc4_misc;
port->ip_serial = ioc4_serial;
port->ip_hooks = &hooks_array[port_number];
switch (port_number) {
case 0:
port->ip_serial_regs = &(port->ip_serial->port_0);
port->ip_uart_regs = &(port->ip_serial->uart_0);
break;
case 1:
port->ip_serial_regs = &(port->ip_serial->port_1);
port->ip_uart_regs = &(port->ip_serial->uart_1);
break;
case 2:
port->ip_serial_regs = &(port->ip_serial->port_2);
port->ip_uart_regs = &(port->ip_serial->uart_2);
break;
default:
case 3:
port->ip_serial_regs = &(port->ip_serial->port_3);
port->ip_uart_regs = &(port->ip_serial->uart_3);
break;
}
if (port_number && (port_number & 1)) {
port->ip_dma_ringbuf =
ports[port_number - 1]->ip_dma_ringbuf;
port->ip_cpu_ringbuf =
ports[port_number - 1]->ip_cpu_ringbuf;
port->ip_inring = RING(port, RX_1_OR_3);
port->ip_outring = RING(port, TX_1_OR_3);
} else {
if (port->ip_dma_ringbuf == 0) {
port->ip_cpu_ringbuf = pci_alloc_consistent
(pdev, TOTAL_RING_BUF_SIZE,
&port->ip_dma_ringbuf);
}
BUG_ON(!((((int64_t)port->ip_dma_ringbuf) &
(TOTAL_RING_BUF_SIZE - 1)) == 0));
DPRINT_CONFIG(("%s : ip_cpu_ringbuf 0x%p "
"ip_dma_ringbuf 0x%p\n",
__func__,
(void *)port->ip_cpu_ringbuf,
(void *)port->ip_dma_ringbuf));
port->ip_inring = RING(port, RX_0_OR_2);
port->ip_outring = RING(port, TX_0_OR_2);
}
DPRINT_CONFIG(("%s : port %d [addr 0x%p] control 0x%p",
__func__,
port_number, (void *)port, (void *)control));
DPRINT_CONFIG((" ip_serial_regs 0x%p ip_uart_regs 0x%p\n",
(void *)port->ip_serial_regs,
(void *)port->ip_uart_regs));
port_init(port);
DPRINT_CONFIG(("%s: port_number %d port 0x%p inring 0x%p "
"outring 0x%p\n",
__func__,
port_number, (void *)port,
(void *)port->ip_inring,
(void *)port->ip_outring));
intr_connect(soft, IOC4_SIO_INTR_TYPE,
GET_SIO_IR(port_number),
handle_intr, port);
intr_connect(soft, IOC4_OTHER_INTR_TYPE,
GET_OTHER_IR(port_number),
handle_dma_error_intr, port);
}
return 0;
}
static void enable_intrs(struct ioc4_port *port, uint32_t mask)
{
struct hooks *hooks = port->ip_hooks;
if ((port->ip_ienb & mask) != mask) {
write_ireg(port->ip_ioc4_soft, mask, IOC4_W_IES,
IOC4_SIO_INTR_TYPE);
port->ip_ienb |= mask;
}
if (port->ip_ienb)
write_ireg(port->ip_ioc4_soft, hooks->intr_dma_error,
IOC4_W_IES, IOC4_OTHER_INTR_TYPE);
}
static inline int local_open(struct ioc4_port *port)
{
int spiniter = 0;
port->ip_flags = PORT_ACTIVE;
if (port->ip_sscr & IOC4_SSCR_DMA_EN) {
writel(port->ip_sscr | IOC4_SSCR_DMA_PAUSE,
&port->ip_serial_regs->sscr);
while((readl(&port->ip_serial_regs-> sscr)
& IOC4_SSCR_PAUSE_STATE) == 0) {
spiniter++;
if (spiniter > MAXITER) {
port->ip_flags = PORT_INACTIVE;
return -1;
}
}
}
writeb(UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_RCVR,
&port->ip_uart_regs->i4u_fcr);
writeb(UART_LCR_WLEN8, &port->ip_uart_regs->i4u_lcr);
port->ip_sscr &= ~IOC4_SSCR_RX_THRESHOLD;
port->ip_sscr |= 1;
writel(port->ip_sscr, &port->ip_serial_regs->sscr);
port->ip_tx_lowat = 1;
return 0;
}
static inline int set_rx_timeout(struct ioc4_port *port, int timeout)
{
int threshold;
port->ip_rx_timeout = timeout;
threshold = timeout * port->ip_baud / 4000;
if (threshold == 0)
threshold = 1;
if ((unsigned)threshold > (unsigned)IOC4_SSCR_RX_THRESHOLD)
return 1;
port->ip_sscr &= ~IOC4_SSCR_RX_THRESHOLD;
port->ip_sscr |= threshold;
writel(port->ip_sscr, &port->ip_serial_regs->sscr);
timeout = timeout * IOC4_SRTR_HZ / 100;
if (timeout > IOC4_SRTR_CNT)
timeout = IOC4_SRTR_CNT;
writel(timeout, &port->ip_serial_regs->srtr);
return 0;
}
static inline int
config_port(struct ioc4_port *port,
int baud, int byte_size, int stop_bits, int parenb, int parodd)
{
char lcr, sizebits;
int spiniter = 0;
DPRINT_CONFIG(("%s: baud %d byte_size %d stop %d parenb %d parodd %d\n",
__func__, baud, byte_size, stop_bits, parenb, parodd));
if (set_baud(port, baud))
return 1;
switch (byte_size) {
case 5:
sizebits = UART_LCR_WLEN5;
break;
case 6:
sizebits = UART_LCR_WLEN6;
break;
case 7:
sizebits = UART_LCR_WLEN7;
break;
case 8:
sizebits = UART_LCR_WLEN8;
break;
default:
return 1;
}
if (port->ip_sscr & IOC4_SSCR_DMA_EN) {
writel(port->ip_sscr | IOC4_SSCR_DMA_PAUSE,
&port->ip_serial_regs->sscr);
while((readl(&port->ip_serial_regs->sscr)
& IOC4_SSCR_PAUSE_STATE) == 0) {
spiniter++;
if (spiniter > MAXITER)
return -1;
}
}
lcr = readb(&port->ip_uart_regs->i4u_lcr);
lcr &= ~(LCR_MASK_BITS_CHAR | UART_LCR_EPAR |
UART_LCR_PARITY | LCR_MASK_STOP_BITS);
lcr |= sizebits;
if (parenb) {
lcr |= UART_LCR_PARITY;
if (!parodd)
lcr |= UART_LCR_EPAR;
}
if (stop_bits)
lcr |= UART_LCR_STOP ;
writeb(lcr, &port->ip_uart_regs->i4u_lcr);
if (port->ip_sscr & IOC4_SSCR_DMA_EN) {
writel(port->ip_sscr, &port->ip_serial_regs->sscr);
}
port->ip_baud = baud;
port->ip_tx_lowat = (TX_LOWAT_CHARS(baud) + 3) / 4;
if (port->ip_tx_lowat == 0)
port->ip_tx_lowat = 1;
set_rx_timeout(port, 2);
return 0;
}
static inline int do_write(struct ioc4_port *port, char *buf, int len)
{
int prod_ptr, cons_ptr, total = 0;
struct ring *outring;
struct ring_entry *entry;
struct hooks *hooks = port->ip_hooks;
BUG_ON(!(len >= 0));
prod_ptr = port->ip_tx_prod;
cons_ptr = readl(&port->ip_serial_regs->stcir) & PROD_CONS_MASK;
outring = port->ip_outring;
cons_ptr = (cons_ptr - (int)sizeof(struct ring_entry)) & PROD_CONS_MASK;
while ((prod_ptr != cons_ptr) && (len > 0)) {
int xx;
entry = (struct ring_entry *)((caddr_t) outring + prod_ptr);
entry->ring_allsc = 0;
for (xx = 0; (xx < 4) && (len > 0); xx++) {
entry->ring_data[xx] = *buf++;
entry->ring_sc[xx] = IOC4_TXCB_VALID;
len--;
total++;
}
if (!(port->ip_flags & LOWAT_WRITTEN) &&
((cons_ptr - prod_ptr) & PROD_CONS_MASK)
<= port->ip_tx_lowat
* (int)sizeof(struct ring_entry)) {
port->ip_flags |= LOWAT_WRITTEN;
entry->ring_sc[0] |= IOC4_TXCB_INT_WHEN_DONE;
}
prod_ptr += sizeof(struct ring_entry);
prod_ptr &= PROD_CONS_MASK;
}
if (total > 0 && !(port->ip_sscr & IOC4_SSCR_DMA_EN)) {
port->ip_sscr |= IOC4_SSCR_DMA_EN;
writel(port->ip_sscr, &port->ip_serial_regs->sscr);
}
if (!uart_tx_stopped(port->ip_port)) {
writel(prod_ptr, &port->ip_serial_regs->stpir);
if (total > 0)
enable_intrs(port, hooks->intr_tx_mt);
}
port->ip_tx_prod = prod_ptr;
return total;
}
static void disable_intrs(struct ioc4_port *port, uint32_t mask)
{
struct hooks *hooks = port->ip_hooks;
if (port->ip_ienb & mask) {
write_ireg(port->ip_ioc4_soft, mask, IOC4_W_IEC,
IOC4_SIO_INTR_TYPE);
port->ip_ienb &= ~mask;
}
if (!port->ip_ienb)
write_ireg(port->ip_ioc4_soft, hooks->intr_dma_error,
IOC4_W_IEC, IOC4_OTHER_INTR_TYPE);
}
static int set_notification(struct ioc4_port *port, int mask, int set_on)
{
struct hooks *hooks = port->ip_hooks;
uint32_t intrbits, sscrbits;
BUG_ON(!mask);
intrbits = sscrbits = 0;
if (mask & N_DATA_READY)
intrbits |= (hooks->intr_rx_timer | hooks->intr_rx_high);
if (mask & N_OUTPUT_LOWAT)
intrbits |= hooks->intr_tx_explicit;
if (mask & N_DDCD) {
intrbits |= hooks->intr_delta_dcd;
sscrbits |= IOC4_SSCR_RX_RING_DCD;
}
if (mask & N_DCTS)
intrbits |= hooks->intr_delta_cts;
if (set_on) {
enable_intrs(port, intrbits);
port->ip_notify |= mask;
port->ip_sscr |= sscrbits;
} else {
disable_intrs(port, intrbits);
port->ip_notify &= ~mask;
port->ip_sscr &= ~sscrbits;
}
if (port->ip_notify & (N_DATA_READY | N_DDCD))
port->ip_sscr |= IOC4_SSCR_DMA_EN;
else if (!(port->ip_ienb & hooks->intr_tx_mt))
port->ip_sscr &= ~IOC4_SSCR_DMA_EN;
writel(port->ip_sscr, &port->ip_serial_regs->sscr);
return 0;
}
static inline int set_mcr(struct uart_port *the_port,
int mask1, int mask2)
{
struct ioc4_port *port = get_ioc4_port(the_port, 0);
uint32_t shadow;
int spiniter = 0;
char mcr;
if (!port)
return -1;
if (port->ip_sscr & IOC4_SSCR_DMA_EN) {
writel(port->ip_sscr | IOC4_SSCR_DMA_PAUSE,
&port->ip_serial_regs->sscr);
while ((readl(&port->ip_serial_regs->sscr)
& IOC4_SSCR_PAUSE_STATE) == 0) {
spiniter++;
if (spiniter > MAXITER)
return -1;
}
}
shadow = readl(&port->ip_serial_regs->shadow);
mcr = (shadow & 0xff000000) >> 24;
mcr |= mask1;
shadow |= mask2;
writeb(mcr, &port->ip_uart_regs->i4u_mcr);
writel(shadow, &port->ip_serial_regs->shadow);
if (port->ip_sscr & IOC4_SSCR_DMA_EN) {
writel(port->ip_sscr, &port->ip_serial_regs->sscr);
}
return 0;
}
static int ioc4_set_proto(struct ioc4_port *port, int proto)
{
struct hooks *hooks = port->ip_hooks;
switch (proto) {
case PROTO_RS232:
writel(0, (&port->ip_mem->gppr[hooks->rs422_select_pin].raw));
break;
case PROTO_RS422:
writel(1, (&port->ip_mem->gppr[hooks->rs422_select_pin].raw));
break;
default:
return 1;
}
return 0;
}
static void transmit_chars(struct uart_port *the_port)
{
int xmit_count, tail, head;
int result;
char *start;
struct tty_struct *tty;
struct ioc4_port *port = get_ioc4_port(the_port, 0);
struct uart_state *state;
if (!the_port)
return;
if (!port)
return;
state = the_port->state;
tty = state->port.tty;
if (uart_circ_empty(&state->xmit) || uart_tx_stopped(the_port)) {
set_notification(port, N_ALL_OUTPUT, 0);
return;
}
head = state->xmit.head;
tail = state->xmit.tail;
start = (char *)&state->xmit.buf[tail];
xmit_count = (head < tail) ? (UART_XMIT_SIZE - tail) : (head - tail);
if (xmit_count > 0) {
result = do_write(port, start, xmit_count);
if (result > 0) {
xmit_count -= result;
the_port->icount.tx += result;
tail += result;
tail &= UART_XMIT_SIZE - 1;
state->xmit.tail = tail;
start = (char *)&state->xmit.buf[tail];
}
}
if (uart_circ_chars_pending(&state->xmit) < WAKEUP_CHARS)
uart_write_wakeup(the_port);
if (uart_circ_empty(&state->xmit)) {
set_notification(port, N_OUTPUT_LOWAT, 0);
} else {
set_notification(port, N_OUTPUT_LOWAT, 1);
}
}
static void
ioc4_change_speed(struct uart_port *the_port,
struct ktermios *new_termios, struct ktermios *old_termios)
{
struct ioc4_port *port = get_ioc4_port(the_port, 0);
int baud, bits;
unsigned cflag, iflag;
int new_parity = 0, new_parity_enable = 0, new_stop = 0, new_data = 8;
struct uart_state *state = the_port->state;
cflag = new_termios->c_cflag;
iflag = new_termios->c_iflag;
switch (cflag & CSIZE) {
case CS5:
new_data = 5;
bits = 7;
break;
case CS6:
new_data = 6;
bits = 8;
break;
case CS7:
new_data = 7;
bits = 9;
break;
case CS8:
new_data = 8;
bits = 10;
break;
default:
new_data = 5;
bits = 7;
break;
}
if (cflag & CSTOPB) {
bits++;
new_stop = 1;
}
if (cflag & PARENB) {
bits++;
new_parity_enable = 1;
if (cflag & PARODD)
new_parity = 1;
}
baud = uart_get_baud_rate(the_port, new_termios, old_termios,
MIN_BAUD_SUPPORTED, MAX_BAUD_SUPPORTED);
DPRINT_CONFIG(("%s: returned baud %d\n", __func__, baud));
if (!baud)
baud = 9600;
if (!the_port->fifosize)
the_port->fifosize = IOC4_FIFO_CHARS;
the_port->timeout = ((the_port->fifosize * HZ * bits) / (baud / 10));
the_port->timeout += HZ / 50;
the_port->ignore_status_mask = N_ALL_INPUT;
state->port.low_latency = 1;
if (iflag & IGNPAR)
the_port->ignore_status_mask &= ~(N_PARITY_ERROR
| N_FRAMING_ERROR);
if (iflag & IGNBRK) {
the_port->ignore_status_mask &= ~N_BREAK;
if (iflag & IGNPAR)
the_port->ignore_status_mask &= ~N_OVERRUN_ERROR;
}
if (!(cflag & CREAD)) {
the_port->ignore_status_mask &= ~N_DATA_READY;
}
if (cflag & CRTSCTS) {
port->ip_sscr |= IOC4_SSCR_HFC_EN;
}
else {
port->ip_sscr &= ~IOC4_SSCR_HFC_EN;
}
writel(port->ip_sscr, &port->ip_serial_regs->sscr);
DPRINT_CONFIG(("%s : port 0x%p cflag 0%o "
"config_port(baud %d data %d stop %d p enable %d parity %d),"
" notification 0x%x\n",
__func__, (void *)port, cflag, baud, new_data, new_stop,
new_parity_enable, new_parity, the_port->ignore_status_mask));
if ((config_port(port, baud,
new_data,
new_stop,
new_parity_enable,
new_parity)) >= 0) {
set_notification(port, the_port->ignore_status_mask, 1);
}
}
static inline int ic4_startup_local(struct uart_port *the_port)
{
struct ioc4_port *port;
struct uart_state *state;
if (!the_port)
return -1;
port = get_ioc4_port(the_port, 0);
if (!port)
return -1;
state = the_port->state;
local_open(port);
ioc4_set_proto(port, the_port->mapbase);
ioc4_change_speed(the_port, &state->port.tty->termios,
(struct ktermios *)0);
return 0;
}
static void ioc4_cb_output_lowat(struct uart_port *the_port)
{
unsigned long pflags;
if (the_port) {
spin_lock_irqsave(&the_port->lock, pflags);
transmit_chars(the_port);
spin_unlock_irqrestore(&the_port->lock, pflags);
}
}
static void handle_intr(void *arg, uint32_t sio_ir)
{
struct ioc4_port *port = (struct ioc4_port *)arg;
struct hooks *hooks = port->ip_hooks;
unsigned int rx_high_rd_aborted = 0;
unsigned long flags;
struct uart_port *the_port;
int loop_counter;
sio_ir &= ~(hooks->intr_tx_mt);
spin_lock_irqsave(&port->ip_lock, flags);
loop_counter = MAXITER;
do {
uint32_t shadow;
if ( loop_counter-- <= 0 ) {
printk(KERN_WARNING "IOC4 serial: "
"possible hang condition/"
"port stuck on interrupt.\n");
break;
}
if (sio_ir & hooks->intr_delta_dcd) {
writel(hooks->intr_delta_dcd,
&port->ip_mem->sio_ir.raw);
shadow = readl(&port->ip_serial_regs->shadow);
if ((port->ip_notify & N_DDCD)
&& (shadow & IOC4_SHADOW_DCD)
&& (port->ip_port)) {
the_port = port->ip_port;
the_port->icount.dcd = 1;
wake_up_interruptible
(&the_port->state->port.delta_msr_wait);
} else if ((port->ip_notify & N_DDCD)
&& !(shadow & IOC4_SHADOW_DCD)) {
port->ip_flags |= DCD_ON;
}
}
if (sio_ir & hooks->intr_delta_cts) {
writel(hooks->intr_delta_cts,
&port->ip_mem->sio_ir.raw);
shadow = readl(&port->ip_serial_regs->shadow);
if ((port->ip_notify & N_DCTS)
&& (port->ip_port)) {
the_port = port->ip_port;
the_port->icount.cts =
(shadow & IOC4_SHADOW_CTS) ? 1 : 0;
wake_up_interruptible
(&the_port->state->port.delta_msr_wait);
}
}
if (sio_ir & hooks->intr_rx_timer) {
writel(hooks->intr_rx_timer,
&port->ip_mem->sio_ir.raw);
if ((port->ip_notify & N_DATA_READY)
&& (port->ip_port)) {
receive_chars(port->ip_port);
}
}
else if (sio_ir & hooks->intr_rx_high) {
if ((port->ip_notify & N_DATA_READY)
&& port->ip_port) {
receive_chars(port->ip_port);
}
if ((sio_ir = PENDING(port)) & hooks->intr_rx_high) {
if ((port->ip_flags & READ_ABORTED) == 0) {
port->ip_ienb &= ~hooks->intr_rx_high;
port->ip_flags |= INPUT_HIGH;
} else {
rx_high_rd_aborted++;
}
}
}
if (sio_ir & hooks->intr_tx_explicit) {
port->ip_flags &= ~LOWAT_WRITTEN;
writel(hooks->intr_tx_explicit,
&port->ip_mem->sio_ir.raw);
if (port->ip_notify & N_OUTPUT_LOWAT)
ioc4_cb_output_lowat(port->ip_port);
}
else if (sio_ir & hooks->intr_tx_mt) {
if (port->ip_notify & N_OUTPUT_LOWAT) {
ioc4_cb_output_lowat(port->ip_port);
sio_ir = PENDING(port);
}
if (sio_ir & hooks->intr_tx_mt) {
if (!(port->ip_notify
& (N_DATA_READY | N_DDCD))) {
BUG_ON(!(port->ip_sscr
& IOC4_SSCR_DMA_EN));
port->ip_sscr &= ~IOC4_SSCR_DMA_EN;
writel(port->ip_sscr,
&port->ip_serial_regs->sscr);
}
port->ip_ienb &= ~hooks->intr_tx_mt;
}
}
sio_ir = PENDING(port);
if (rx_high_rd_aborted && (sio_ir == hooks->intr_rx_high)) {
sio_ir &= ~hooks->intr_rx_high;
}
} while (sio_ir & hooks->intr_all);
spin_unlock_irqrestore(&port->ip_lock, flags);
write_ireg(port->ip_ioc4_soft, port->ip_ienb, IOC4_W_IES,
IOC4_SIO_INTR_TYPE);
}
static void ioc4_cb_post_ncs(struct uart_port *the_port, int ncs)
{
struct uart_icount *icount;
icount = &the_port->icount;
if (ncs & NCS_BREAK)
icount->brk++;
if (ncs & NCS_FRAMING)
icount->frame++;
if (ncs & NCS_OVERRUN)
icount->overrun++;
if (ncs & NCS_PARITY)
icount->parity++;
}
static inline int do_read(struct uart_port *the_port, unsigned char *buf,
int len)
{
int prod_ptr, cons_ptr, total;
struct ioc4_port *port = get_ioc4_port(the_port, 0);
struct ring *inring;
struct ring_entry *entry;
struct hooks *hooks;
int byte_num;
char *sc;
int loop_counter;
BUG_ON(!(len >= 0));
BUG_ON(!port);
hooks = port->ip_hooks;
writel(port->ip_rx_cons | IOC4_SRCIR_ARM, &port->ip_serial_regs->srcir);
prod_ptr = readl(&port->ip_serial_regs->srpir) & PROD_CONS_MASK;
cons_ptr = port->ip_rx_cons;
if (prod_ptr == cons_ptr) {
int reset_dma = 0;
if (!(port->ip_sscr & IOC4_SSCR_DMA_EN)) {
port->ip_sscr |= IOC4_SSCR_DMA_EN;
reset_dma = 1;
}
writel(port->ip_sscr | IOC4_SSCR_RX_DRAIN,
&port->ip_serial_regs->sscr);
prod_ptr = readl(&port->ip_serial_regs->srpir)
& PROD_CONS_MASK;
if (prod_ptr == cons_ptr) {
loop_counter = 0;
while (readl(&port->ip_serial_regs->sscr) &
IOC4_SSCR_RX_DRAIN) {
loop_counter++;
if (loop_counter > MAXITER)
return -1;
}
prod_ptr = readl(&port->ip_serial_regs->srpir)
& PROD_CONS_MASK;
}
if (reset_dma) {
port->ip_sscr &= ~IOC4_SSCR_DMA_EN;
writel(port->ip_sscr, &port->ip_serial_regs->sscr);
}
}
inring = port->ip_inring;
port->ip_flags &= ~READ_ABORTED;
total = 0;
loop_counter = 0xfffff;
while ((prod_ptr != cons_ptr) && (len > 0)) {
entry = (struct ring_entry *)((caddr_t)inring + cons_ptr);
if ( loop_counter-- <= 0 ) {
printk(KERN_WARNING "IOC4 serial: "
"possible hang condition/"
"port stuck on read.\n");
break;
}
if ((entry->ring_allsc & RING_ANY_VALID) == 0) {
port->ip_flags |= READ_ABORTED;
len = 0;
break;
}
for (byte_num = 0; byte_num < 4 && len > 0; byte_num++) {
sc = &(entry->ring_sc[byte_num]);
if ((*sc & IOC4_RXSB_MODEM_VALID)
&& (port->ip_notify & N_DDCD)) {
if ((port->ip_flags & DCD_ON)
&& !(*sc & IOC4_RXSB_DCD)) {
if (total > 0) {
len = 0;
break;
}
port->ip_flags &= ~DCD_ON;
*sc &= ~IOC4_RXSB_MODEM_VALID;
if ((entry->ring_allsc & RING_ANY_VALID)
== 0) {
cons_ptr += (int)sizeof
(struct ring_entry);
cons_ptr &= PROD_CONS_MASK;
}
writel(cons_ptr,
&port->ip_serial_regs->srcir);
port->ip_rx_cons = cons_ptr;
if ((port->ip_notify & N_DDCD)
&& port->ip_port) {
the_port->icount.dcd = 0;
wake_up_interruptible
(&the_port->state->
port.delta_msr_wait);
}
return 0;
}
}
if (*sc & IOC4_RXSB_MODEM_VALID) {
if ((*sc & IOC4_RXSB_OVERRUN)
&& (port->ip_notify & N_OVERRUN_ERROR)) {
ioc4_cb_post_ncs(the_port, NCS_OVERRUN);
}
*sc &= ~IOC4_RXSB_MODEM_VALID;
}
if ((*sc & IOC4_RXSB_DATA_VALID) &&
((*sc & (IOC4_RXSB_PAR_ERR
| IOC4_RXSB_FRAME_ERR
| IOC4_RXSB_BREAK))
&& (port->ip_notify & (N_PARITY_ERROR
| N_FRAMING_ERROR
| N_BREAK)))) {
if (total > 0) {
len = 0;
break;
} else {
if ((*sc & IOC4_RXSB_PAR_ERR) &&
(port->ip_notify & N_PARITY_ERROR)) {
ioc4_cb_post_ncs(the_port,
NCS_PARITY);
}
if ((*sc & IOC4_RXSB_FRAME_ERR) &&
(port->ip_notify & N_FRAMING_ERROR)){
ioc4_cb_post_ncs(the_port,
NCS_FRAMING);
}
if ((*sc & IOC4_RXSB_BREAK)
&& (port->ip_notify & N_BREAK)) {
ioc4_cb_post_ncs
(the_port,
NCS_BREAK);
}
len = 1;
}
}
if (*sc & IOC4_RXSB_DATA_VALID) {
*sc &= ~IOC4_RXSB_DATA_VALID;
*buf = entry->ring_data[byte_num];
buf++;
len--;
total++;
}
}
if ((entry->ring_allsc & RING_ANY_VALID) == 0) {
cons_ptr += (int)sizeof(struct ring_entry);
cons_ptr &= PROD_CONS_MASK;
}
}
writel(cons_ptr, &port->ip_serial_regs->srcir);
port->ip_rx_cons = cons_ptr;
if ((port->ip_flags & INPUT_HIGH) && (((prod_ptr - cons_ptr)
& PROD_CONS_MASK) < ((port->ip_sscr &
IOC4_SSCR_RX_THRESHOLD)
<< IOC4_PROD_CONS_PTR_OFF))) {
port->ip_flags &= ~INPUT_HIGH;
enable_intrs(port, hooks->intr_rx_high);
}
return total;
}
static void receive_chars(struct uart_port *the_port)
{
unsigned char ch[IOC4_MAX_CHARS];
int read_count, request_count = IOC4_MAX_CHARS;
struct uart_icount *icount;
struct uart_state *state = the_port->state;
unsigned long pflags;
if (!state)
return;
spin_lock_irqsave(&the_port->lock, pflags);
request_count = tty_buffer_request_room(&state->port, IOC4_MAX_CHARS);
if (request_count > 0) {
icount = &the_port->icount;
read_count = do_read(the_port, ch, request_count);
if (read_count > 0) {
tty_insert_flip_string(&state->port, ch, read_count);
icount->rx += read_count;
}
}
spin_unlock_irqrestore(&the_port->lock, pflags);
tty_flip_buffer_push(&state->port);
}
static const char *ic4_type(struct uart_port *the_port)
{
if (the_port->mapbase == PROTO_RS232)
return "SGI IOC4 Serial [rs232]";
else
return "SGI IOC4 Serial [rs422]";
}
static unsigned int ic4_tx_empty(struct uart_port *the_port)
{
struct ioc4_port *port = get_ioc4_port(the_port, 0);
unsigned int ret = 0;
if (port_is_active(port, the_port)) {
if (readl(&port->ip_serial_regs->shadow) & IOC4_SHADOW_TEMT)
ret = TIOCSER_TEMT;
}
return ret;
}
static void ic4_stop_tx(struct uart_port *the_port)
{
struct ioc4_port *port = get_ioc4_port(the_port, 0);
if (port_is_active(port, the_port))
set_notification(port, N_OUTPUT_LOWAT, 0);
}
static void null_void_function(struct uart_port *the_port)
{
}
static void ic4_shutdown(struct uart_port *the_port)
{
unsigned long port_flags;
struct ioc4_port *port;
struct uart_state *state;
port = get_ioc4_port(the_port, 0);
if (!port)
return;
state = the_port->state;
port->ip_port = NULL;
wake_up_interruptible(&state->port.delta_msr_wait);
if (state->port.tty)
set_bit(TTY_IO_ERROR, &state->port.tty->flags);
spin_lock_irqsave(&the_port->lock, port_flags);
set_notification(port, N_ALL, 0);
port->ip_flags = PORT_INACTIVE;
spin_unlock_irqrestore(&the_port->lock, port_flags);
}
static void ic4_set_mctrl(struct uart_port *the_port, unsigned int mctrl)
{
unsigned char mcr = 0;
struct ioc4_port *port;
port = get_ioc4_port(the_port, 0);
if (!port_is_active(port, the_port))
return;
if (mctrl & TIOCM_RTS)
mcr |= UART_MCR_RTS;
if (mctrl & TIOCM_DTR)
mcr |= UART_MCR_DTR;
if (mctrl & TIOCM_OUT1)
mcr |= UART_MCR_OUT1;
if (mctrl & TIOCM_OUT2)
mcr |= UART_MCR_OUT2;
if (mctrl & TIOCM_LOOP)
mcr |= UART_MCR_LOOP;
set_mcr(the_port, mcr, IOC4_SHADOW_DTR);
}
static unsigned int ic4_get_mctrl(struct uart_port *the_port)
{
struct ioc4_port *port = get_ioc4_port(the_port, 0);
uint32_t shadow;
unsigned int ret = 0;
if (!port_is_active(port, the_port))
return 0;
shadow = readl(&port->ip_serial_regs->shadow);
if (shadow & IOC4_SHADOW_DCD)
ret |= TIOCM_CAR;
if (shadow & IOC4_SHADOW_DR)
ret |= TIOCM_DSR;
if (shadow & IOC4_SHADOW_CTS)
ret |= TIOCM_CTS;
return ret;
}
static void ic4_start_tx(struct uart_port *the_port)
{
struct ioc4_port *port = get_ioc4_port(the_port, 0);
if (port_is_active(port, the_port)) {
set_notification(port, N_OUTPUT_LOWAT, 1);
enable_intrs(port, port->ip_hooks->intr_tx_mt);
}
}
static void ic4_break_ctl(struct uart_port *the_port, int break_state)
{
}
static int ic4_startup(struct uart_port *the_port)
{
int retval;
struct ioc4_port *port;
struct ioc4_control *control;
struct uart_state *state;
unsigned long port_flags;
if (!the_port)
return -ENODEV;
port = get_ioc4_port(the_port, 1);
if (!port)
return -ENODEV;
state = the_port->state;
control = port->ip_control;
if (!control) {
port->ip_port = NULL;
return -ENODEV;
}
spin_lock_irqsave(&the_port->lock, port_flags);
retval = ic4_startup_local(the_port);
spin_unlock_irqrestore(&the_port->lock, port_flags);
return retval;
}
static void
ic4_set_termios(struct uart_port *the_port,
struct ktermios *termios, struct ktermios *old_termios)
{
unsigned long port_flags;
spin_lock_irqsave(&the_port->lock, port_flags);
ioc4_change_speed(the_port, termios, old_termios);
spin_unlock_irqrestore(&the_port->lock, port_flags);
}
static int ic4_request_port(struct uart_port *port)
{
return 0;
}
static int ioc4_serial_remove_one(struct ioc4_driver_data *idd)
{
int port_num, port_type;
struct ioc4_control *control;
struct uart_port *the_port;
struct ioc4_port *port;
struct ioc4_soft *soft;
control = idd->idd_serial_data;
if (!control)
return 0;
for (port_num = 0; port_num < IOC4_NUM_SERIAL_PORTS; port_num++) {
for (port_type = UART_PORT_MIN;
port_type < UART_PORT_COUNT;
port_type++) {
the_port = &control->ic_port[port_num].icp_uart_port
[port_type];
if (the_port) {
switch (port_type) {
case UART_PORT_RS422:
uart_remove_one_port(&ioc4_uart_rs422,
the_port);
break;
default:
case UART_PORT_RS232:
uart_remove_one_port(&ioc4_uart_rs232,
the_port);
break;
}
}
}
port = control->ic_port[port_num].icp_port;
if (!(port_num & 1) && port) {
pci_free_consistent(port->ip_pdev,
TOTAL_RING_BUF_SIZE,
port->ip_cpu_ringbuf,
port->ip_dma_ringbuf);
kfree(port);
}
}
soft = control->ic_soft;
if (soft) {
free_irq(control->ic_irq, soft);
if (soft->is_ioc4_serial_addr) {
iounmap(soft->is_ioc4_serial_addr);
release_mem_region((unsigned long)
soft->is_ioc4_serial_addr,
sizeof(struct ioc4_serial));
}
kfree(soft);
}
kfree(control);
idd->idd_serial_data = NULL;
return 0;
}
static inline int
ioc4_serial_core_attach(struct pci_dev *pdev, int port_type)
{
struct ioc4_port *port;
struct uart_port *the_port;
struct ioc4_driver_data *idd = pci_get_drvdata(pdev);
struct ioc4_control *control = idd->idd_serial_data;
int port_num;
int port_type_idx;
struct uart_driver *u_driver;
DPRINT_CONFIG(("%s: attach pdev 0x%p - control 0x%p\n",
__func__, pdev, (void *)control));
if (!control)
return -ENODEV;
port_type_idx = (port_type == PROTO_RS232) ? UART_PORT_RS232
: UART_PORT_RS422;
u_driver = (port_type == PROTO_RS232) ? &ioc4_uart_rs232
: &ioc4_uart_rs422;
for (port_num = 0; port_num < IOC4_NUM_SERIAL_PORTS; port_num++) {
the_port = &control->ic_port[port_num].icp_uart_port
[port_type_idx];
port = control->ic_port[port_num].icp_port;
port->ip_all_ports[port_type_idx] = the_port;
DPRINT_CONFIG(("%s: attach the_port 0x%p / port 0x%p : type %s\n",
__func__, (void *)the_port,
(void *)port,
port_type == PROTO_RS232 ? "rs232" : "rs422"));
the_port->membase = (unsigned char __iomem *)1;
the_port->iobase = (pdev->bus->number << 16) | port_num;
the_port->line = (Num_of_ioc4_cards << 2) | port_num;
the_port->mapbase = port_type;
the_port->type = PORT_16550A;
the_port->fifosize = IOC4_FIFO_CHARS;
the_port->ops = &ioc4_ops;
the_port->irq = control->ic_irq;
the_port->dev = &pdev->dev;
spin_lock_init(&the_port->lock);
if (uart_add_one_port(u_driver, the_port) < 0) {
printk(KERN_WARNING
"%s: unable to add port %d bus %d\n",
__func__, the_port->line, pdev->bus->number);
} else {
DPRINT_CONFIG(
("IOC4 serial port %d irq = %d, bus %d\n",
the_port->line, the_port->irq, pdev->bus->number));
}
}
return 0;
}
int
ioc4_serial_attach_one(struct ioc4_driver_data *idd)
{
unsigned long tmp_addr1;
struct ioc4_serial __iomem *serial;
struct ioc4_soft *soft;
struct ioc4_control *control;
int ret = 0;
DPRINT_CONFIG(("%s (0x%p, 0x%p)\n", __func__, idd->idd_pdev,
idd->idd_pci_id));
if (idd->idd_variant == IOC4_VARIANT_PCI_RT)
return 0;
tmp_addr1 = idd->idd_bar0 + IOC4_SERIAL_OFFSET;
if (!request_mem_region(tmp_addr1, sizeof(struct ioc4_serial),
"sioc4_uart")) {
printk(KERN_WARNING
"ioc4 (%p): unable to get request region for "
"uart space\n", (void *)idd->idd_pdev);
ret = -ENODEV;
goto out1;
}
serial = ioremap(tmp_addr1, sizeof(struct ioc4_serial));
if (!serial) {
printk(KERN_WARNING
"ioc4 (%p) : unable to remap ioc4 serial register\n",
(void *)idd->idd_pdev);
ret = -ENODEV;
goto out2;
}
DPRINT_CONFIG(("%s : mem 0x%p, serial 0x%p\n",
__func__, (void *)idd->idd_misc_regs,
(void *)serial));
control = kzalloc(sizeof(struct ioc4_control), GFP_KERNEL);
if (!control) {
printk(KERN_WARNING "ioc4_attach_one"
": unable to get memory for the IOC4\n");
ret = -ENOMEM;
goto out2;
}
idd->idd_serial_data = control;
soft = kzalloc(sizeof(struct ioc4_soft), GFP_KERNEL);
if (!soft) {
printk(KERN_WARNING
"ioc4 (%p): unable to get memory for the soft struct\n",
(void *)idd->idd_pdev);
ret = -ENOMEM;
goto out3;
}
spin_lock_init(&soft->is_ir_lock);
soft->is_ioc4_misc_addr = idd->idd_misc_regs;
soft->is_ioc4_serial_addr = serial;
writel(0xf << IOC4_SIO_CR_CMD_PULSE_SHIFT,
&idd->idd_misc_regs->sio_cr.raw);
writel(IOC4_GPCR_UART0_MODESEL | IOC4_GPCR_UART1_MODESEL
| IOC4_GPCR_UART2_MODESEL | IOC4_GPCR_UART3_MODESEL,
&idd->idd_misc_regs->gpcr_s.raw);
write_ireg(soft, ~0, IOC4_W_IEC, IOC4_SIO_INTR_TYPE);
writel(~0, &idd->idd_misc_regs->sio_ir.raw);
write_ireg(soft, IOC4_OTHER_IR_SER_MEMERR, IOC4_W_IEC,
IOC4_OTHER_INTR_TYPE);
writel(IOC4_OTHER_IR_SER_MEMERR, &idd->idd_misc_regs->other_ir.raw);
control->ic_soft = soft;
if (!request_irq(idd->idd_pdev->irq, ioc4_intr, IRQF_SHARED,
"sgi-ioc4serial", soft)) {
control->ic_irq = idd->idd_pdev->irq;
} else {
printk(KERN_WARNING
"%s : request_irq fails for IRQ 0x%x\n ",
__func__, idd->idd_pdev->irq);
}
ret = ioc4_attach_local(idd);
if (ret)
goto out4;
if ((ret = ioc4_serial_core_attach(idd->idd_pdev, PROTO_RS232)))
goto out4;
if ((ret = ioc4_serial_core_attach(idd->idd_pdev, PROTO_RS422)))
goto out5;
Num_of_ioc4_cards++;
return ret;
out5:
ioc4_serial_remove_one(idd);
return ret;
out4:
kfree(soft);
out3:
kfree(control);
out2:
if (serial)
iounmap(serial);
release_mem_region(tmp_addr1, sizeof(struct ioc4_serial));
out1:
return ret;
}
static int __init ioc4_serial_init(void)
{
int ret;
if ((ret = uart_register_driver(&ioc4_uart_rs232)) < 0) {
printk(KERN_WARNING
"%s: Couldn't register rs232 IOC4 serial driver\n",
__func__);
goto out;
}
if ((ret = uart_register_driver(&ioc4_uart_rs422)) < 0) {
printk(KERN_WARNING
"%s: Couldn't register rs422 IOC4 serial driver\n",
__func__);
goto out_uart_rs232;
}
ret = ioc4_register_submodule(&ioc4_serial_submodule);
if (ret)
goto out_uart_rs422;
return 0;
out_uart_rs422:
uart_unregister_driver(&ioc4_uart_rs422);
out_uart_rs232:
uart_unregister_driver(&ioc4_uart_rs232);
out:
return ret;
}
static void __exit ioc4_serial_exit(void)
{
ioc4_unregister_submodule(&ioc4_serial_submodule);
uart_unregister_driver(&ioc4_uart_rs232);
uart_unregister_driver(&ioc4_uart_rs422);
}
