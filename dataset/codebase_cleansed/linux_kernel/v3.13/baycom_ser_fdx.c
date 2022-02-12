static inline void baycom_int_freq(struct baycom_state *bc)
{
#ifdef BAYCOM_DEBUG
unsigned long cur_jiffies = jiffies;
bc->debug_vals.cur_intcnt++;
if (time_after_eq(cur_jiffies, bc->debug_vals.last_jiffies + HZ)) {
bc->debug_vals.last_jiffies = cur_jiffies;
bc->debug_vals.last_intcnt = bc->debug_vals.cur_intcnt;
bc->debug_vals.cur_intcnt = 0;
bc->debug_vals.last_pllcorr = bc->debug_vals.cur_pllcorr;
bc->debug_vals.cur_pllcorr = 0;
}
#endif
}
static inline void ser12_set_divisor(struct net_device *dev,
unsigned int divisor)
{
outb(0x81, LCR(dev->base_addr));
outb(divisor, DLL(dev->base_addr));
outb(divisor >> 8, DLM(dev->base_addr));
outb(0x01, LCR(dev->base_addr));
outb(0x00, THR(dev->base_addr));
}
static __inline__ void ser12_rx(struct net_device *dev, struct baycom_state *bc, struct timeval *tv, unsigned char curs)
{
int timediff;
int bdus8 = bc->baud_us >> 3;
int bdus4 = bc->baud_us >> 2;
int bdus2 = bc->baud_us >> 1;
timediff = 1000000 + tv->tv_usec - bc->modem.ser12.pll_time;
while (timediff >= 500000)
timediff -= 1000000;
while (timediff >= bdus2) {
timediff -= bc->baud_us;
bc->modem.ser12.pll_time += bc->baud_us;
bc->modem.ser12.dcd_time--;
if (bc->modem.shreg & 1) {
hdlcdrv_putbits(&bc->hdrv, (bc->modem.shreg >> 1) ^ 0xffff);
bc->modem.shreg = 0x10000;
}
bc->modem.shreg >>= 1;
}
if (bc->modem.ser12.dcd_time <= 0) {
if (!bc->opt_dcd)
hdlcdrv_setdcd(&bc->hdrv, (bc->modem.ser12.dcd_sum0 +
bc->modem.ser12.dcd_sum1 +
bc->modem.ser12.dcd_sum2) < 0);
bc->modem.ser12.dcd_sum2 = bc->modem.ser12.dcd_sum1;
bc->modem.ser12.dcd_sum1 = bc->modem.ser12.dcd_sum0;
bc->modem.ser12.dcd_sum0 = 2;
bc->modem.ser12.dcd_time += 120;
}
if (bc->modem.ser12.last_rxbit != curs) {
bc->modem.ser12.last_rxbit = curs;
bc->modem.shreg |= 0x10000;
if (timediff > 0)
bc->modem.ser12.pll_time += bdus8;
else
bc->modem.ser12.pll_time += 1000000 - bdus8;
if (abs(timediff) > bdus4)
bc->modem.ser12.dcd_sum0 += 4;
else
bc->modem.ser12.dcd_sum0--;
#ifdef BAYCOM_DEBUG
bc->debug_vals.cur_pllcorr = timediff;
#endif
}
while (bc->modem.ser12.pll_time >= 1000000)
bc->modem.ser12.pll_time -= 1000000;
}
static irqreturn_t ser12_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct baycom_state *bc = netdev_priv(dev);
struct timeval tv;
unsigned char iir, msr;
unsigned int txcount = 0;
if (!bc || bc->hdrv.magic != HDLCDRV_MAGIC)
return IRQ_NONE;
if ((iir = inb(IIR(dev->base_addr))) & 1)
return IRQ_NONE;
do_gettimeofday(&tv);
msr = inb(MSR(dev->base_addr));
if ((msr & 8) && bc->opt_dcd)
hdlcdrv_setdcd(&bc->hdrv, !((msr ^ bc->opt_dcd) & 0x80));
do {
switch (iir & 6) {
case 6:
inb(LSR(dev->base_addr));
break;
case 4:
inb(RBR(dev->base_addr));
break;
case 2:
outb(0x00, THR(dev->base_addr));
baycom_int_freq(bc);
txcount++;
if (bc->modem.ptt)
outb(0x0e | (!!bc->modem.ser12.tx_bit), MCR(dev->base_addr));
else
outb(0x0d, MCR(dev->base_addr));
break;
default:
msr = inb(MSR(dev->base_addr));
if ((msr & 8) && bc->opt_dcd)
hdlcdrv_setdcd(&bc->hdrv, !((msr ^ bc->opt_dcd) & 0x80));
break;
}
iir = inb(IIR(dev->base_addr));
} while (!(iir & 1));
ser12_rx(dev, bc, &tv, msr & 0x10);
if (bc->modem.ptt && txcount) {
if (bc->modem.ser12.txshreg <= 1) {
bc->modem.ser12.txshreg = 0x10000 | hdlcdrv_getbits(&bc->hdrv);
if (!hdlcdrv_ptt(&bc->hdrv)) {
ser12_set_divisor(dev, 115200/100/8);
bc->modem.ptt = 0;
goto end_transmit;
}
}
bc->modem.ser12.tx_bit = !(bc->modem.ser12.tx_bit ^ (bc->modem.ser12.txshreg & 1));
bc->modem.ser12.txshreg >>= 1;
}
end_transmit:
local_irq_enable();
if (!bc->modem.ptt && txcount) {
hdlcdrv_arbitrate(dev, &bc->hdrv);
if (hdlcdrv_ptt(&bc->hdrv)) {
ser12_set_divisor(dev, bc->baud_uartdiv);
bc->modem.ser12.txshreg = 1;
bc->modem.ptt = 1;
}
}
hdlcdrv_transmitter(dev, &bc->hdrv);
hdlcdrv_receiver(dev, &bc->hdrv);
local_irq_disable();
return IRQ_HANDLED;
}
static enum uart ser12_check_uart(unsigned int iobase)
{
unsigned char b1,b2,b3;
enum uart u;
enum uart uart_tab[] =
{ c_uart_16450, c_uart_unknown, c_uart_16550, c_uart_16550A };
b1 = inb(MCR(iobase));
outb(b1 | 0x10, MCR(iobase));
b2 = inb(MSR(iobase));
outb(0x1a, MCR(iobase));
b3 = inb(MSR(iobase)) & 0xf0;
outb(b1, MCR(iobase));
outb(b2, MSR(iobase));
if (b3 != 0x90)
return c_uart_unknown;
inb(RBR(iobase));
inb(RBR(iobase));
outb(0x01, FCR(iobase));
u = uart_tab[(inb(IIR(iobase)) >> 6) & 3];
if (u == c_uart_16450) {
outb(0x5a, SCR(iobase));
b1 = inb(SCR(iobase));
outb(0xa5, SCR(iobase));
b2 = inb(SCR(iobase));
if ((b1 != 0x5a) || (b2 != 0xa5))
u = c_uart_8250;
}
return u;
}
static int ser12_open(struct net_device *dev)
{
struct baycom_state *bc = netdev_priv(dev);
enum uart u;
if (!dev || !bc)
return -ENXIO;
if (!dev->base_addr || dev->base_addr > 0xffff-SER12_EXTENT ||
dev->irq < 2 || dev->irq > nr_irqs) {
printk(KERN_INFO "baycom_ser_fdx: invalid portnumber (max %u) "
"or irq (2 <= irq <= %d)\n",
0xffff-SER12_EXTENT, nr_irqs);
return -ENXIO;
}
if (bc->baud < 300 || bc->baud > 4800) {
printk(KERN_INFO "baycom_ser_fdx: invalid baudrate "
"(300...4800)\n");
return -EINVAL;
}
if (!request_region(dev->base_addr, SER12_EXTENT, "baycom_ser_fdx")) {
printk(KERN_WARNING "BAYCOM_SER_FSX: I/O port 0x%04lx busy\n",
dev->base_addr);
return -EACCES;
}
memset(&bc->modem, 0, sizeof(bc->modem));
bc->hdrv.par.bitrate = bc->baud;
bc->baud_us = 1000000/bc->baud;
bc->baud_uartdiv = (115200/8)/bc->baud;
if ((u = ser12_check_uart(dev->base_addr)) == c_uart_unknown){
release_region(dev->base_addr, SER12_EXTENT);
return -EIO;
}
outb(0, FCR(dev->base_addr));
outb(0x0d, MCR(dev->base_addr));
outb(0, IER(dev->base_addr));
if (request_irq(dev->irq, ser12_interrupt, IRQF_SHARED,
"baycom_ser_fdx", dev)) {
release_region(dev->base_addr, SER12_EXTENT);
return -EBUSY;
}
ser12_set_divisor(dev, 115200/100/8);
outb(0x0a, IER(dev->base_addr));
outb(0x00, THR(dev->base_addr));
hdlcdrv_setdcd(&bc->hdrv, 0);
printk(KERN_INFO "%s: ser_fdx at iobase 0x%lx irq %u baud %u uart %s\n",
bc_drvname, dev->base_addr, dev->irq, bc->baud, uart_str[u]);
return 0;
}
static int ser12_close(struct net_device *dev)
{
struct baycom_state *bc = netdev_priv(dev);
if (!dev || !bc)
return -EINVAL;
outb(0, IER(dev->base_addr));
outb(1, MCR(dev->base_addr));
free_irq(dev->irq, dev);
release_region(dev->base_addr, SER12_EXTENT);
printk(KERN_INFO "%s: close ser_fdx at iobase 0x%lx irq %u\n",
bc_drvname, dev->base_addr, dev->irq);
return 0;
}
static int baycom_setmode(struct baycom_state *bc, const char *modestr)
{
unsigned int baud;
if (!strncmp(modestr, "ser", 3)) {
baud = simple_strtoul(modestr+3, NULL, 10);
if (baud >= 3 && baud <= 48)
bc->baud = baud*100;
}
if (strchr(modestr, '*'))
bc->opt_dcd = 0;
else if (strchr(modestr, '+'))
bc->opt_dcd = -1;
else
bc->opt_dcd = 1;
return 0;
}
static int baycom_ioctl(struct net_device *dev, struct ifreq *ifr,
struct hdlcdrv_ioctl *hi, int cmd)
{
struct baycom_state *bc;
struct baycom_ioctl bi;
if (!dev)
return -EINVAL;
bc = netdev_priv(dev);
BUG_ON(bc->hdrv.magic != HDLCDRV_MAGIC);
if (cmd != SIOCDEVPRIVATE)
return -ENOIOCTLCMD;
switch (hi->cmd) {
default:
break;
case HDLCDRVCTL_GETMODE:
sprintf(hi->data.modename, "ser%u", bc->baud / 100);
if (bc->opt_dcd <= 0)
strcat(hi->data.modename, (!bc->opt_dcd) ? "*" : "+");
if (copy_to_user(ifr->ifr_data, hi, sizeof(struct hdlcdrv_ioctl)))
return -EFAULT;
return 0;
case HDLCDRVCTL_SETMODE:
if (netif_running(dev) || !capable(CAP_NET_ADMIN))
return -EACCES;
hi->data.modename[sizeof(hi->data.modename)-1] = '\0';
return baycom_setmode(bc, hi->data.modename);
case HDLCDRVCTL_MODELIST:
strcpy(hi->data.modename, "ser12,ser3,ser24");
if (copy_to_user(ifr->ifr_data, hi, sizeof(struct hdlcdrv_ioctl)))
return -EFAULT;
return 0;
case HDLCDRVCTL_MODEMPARMASK:
return HDLCDRV_PARMASK_IOBASE | HDLCDRV_PARMASK_IRQ;
}
if (copy_from_user(&bi, ifr->ifr_data, sizeof(bi)))
return -EFAULT;
switch (bi.cmd) {
default:
return -ENOIOCTLCMD;
#ifdef BAYCOM_DEBUG
case BAYCOMCTL_GETDEBUG:
bi.data.dbg.debug1 = bc->hdrv.ptt_keyed;
bi.data.dbg.debug2 = bc->debug_vals.last_intcnt;
bi.data.dbg.debug3 = bc->debug_vals.last_pllcorr;
break;
#endif
}
if (copy_to_user(ifr->ifr_data, &bi, sizeof(bi)))
return -EFAULT;
return 0;
}
static int __init init_baycomserfdx(void)
{
int i, found = 0;
char set_hw = 1;
printk(bc_drvinfo);
for (i = 0; i < NR_PORTS; i++) {
struct net_device *dev;
struct baycom_state *bc;
char ifname[IFNAMSIZ];
sprintf(ifname, "bcsf%d", i);
if (!mode[i])
set_hw = 0;
if (!set_hw)
iobase[i] = irq[i] = 0;
dev = hdlcdrv_register(&ser12_ops,
sizeof(struct baycom_state),
ifname, iobase[i], irq[i], 0);
if (IS_ERR(dev))
break;
bc = netdev_priv(dev);
if (set_hw && baycom_setmode(bc, mode[i]))
set_hw = 0;
bc->baud = baud[i];
found++;
baycom_device[i] = dev;
}
if (!found)
return -ENXIO;
return 0;
}
static void __exit cleanup_baycomserfdx(void)
{
int i;
for(i = 0; i < NR_PORTS; i++) {
struct net_device *dev = baycom_device[i];
if (dev)
hdlcdrv_unregister(dev);
}
}
static int __init baycom_ser_fdx_setup(char *str)
{
static unsigned nr_dev;
int ints[4];
if (nr_dev >= NR_PORTS)
return 0;
str = get_options(str, 4, ints);
if (ints[0] < 2)
return 0;
mode[nr_dev] = str;
iobase[nr_dev] = ints[1];
irq[nr_dev] = ints[2];
if (ints[0] >= 3)
baud[nr_dev] = ints[3];
nr_dev++;
return 1;
}
