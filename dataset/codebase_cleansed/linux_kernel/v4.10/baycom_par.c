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
static inline void par96_tx(struct net_device *dev, struct baycom_state *bc)
{
int i;
unsigned int data = hdlcdrv_getbits(&bc->hdrv);
struct parport *pp = bc->pdev->port;
for(i = 0; i < PAR96_BURSTBITS; i++, data >>= 1) {
unsigned char val = PAR97_POWER;
bc->modem.par96.scram = ((bc->modem.par96.scram << 1) |
(bc->modem.par96.scram & 1));
if (!(data & 1))
bc->modem.par96.scram ^= 1;
if (bc->modem.par96.scram & (PAR96_SCRAM_TAP1 << 1))
bc->modem.par96.scram ^=
(PAR96_SCRAM_TAPN << 1);
if (bc->modem.par96.scram & (PAR96_SCRAM_TAP1 << 2))
val |= PAR96_TXBIT;
pp->ops->write_data(pp, val);
pp->ops->write_data(pp, val | PAR96_BURST);
}
}
static inline void par96_rx(struct net_device *dev, struct baycom_state *bc)
{
int i;
unsigned int data, mask, mask2, descx;
struct parport *pp = bc->pdev->port;
for(data = i = 0; i < PAR96_BURSTBITS; i++) {
bc->modem.par96.descram = (bc->modem.par96.descram << 1);
if (pp->ops->read_status(pp) & PAR96_RXBIT)
bc->modem.par96.descram |= 1;
descx = bc->modem.par96.descram ^
(bc->modem.par96.descram >> 1);
pp->ops->write_data(pp, PAR97_POWER | PAR96_PTT);
descx ^= ((descx >> PAR96_DESCRAM_TAPSH1) ^
(descx >> PAR96_DESCRAM_TAPSH2));
data >>= 1;
if (!(descx & 1))
data |= 0x8000;
pp->ops->write_data(pp, PAR97_POWER | PAR96_PTT | PAR96_BURST);
}
hdlcdrv_putbits(&bc->hdrv, data);
if (bc->options & BAYCOM_OPTIONS_SOFTDCD) {
bc->modem.par96.dcd_shreg = (bc->modem.par96.dcd_shreg >> 16)
| (data << 16);
for(mask = 0x1fe00, mask2 = 0xfc00, i = 0;
i < PAR96_BURSTBITS; i++, mask <<= 1, mask2 <<= 1)
if ((bc->modem.par96.dcd_shreg & mask) == mask2)
bc->modem.par96.dcd_count = HDLCDRV_MAXFLEN+4;
for(mask = 0x1fe00, mask2 = 0x1fe00, i = 0;
i < PAR96_BURSTBITS; i++, mask <<= 1, mask2 <<= 1)
if (((bc->modem.par96.dcd_shreg & mask) == mask2) &&
(bc->modem.par96.dcd_count >= 0))
bc->modem.par96.dcd_count -= HDLCDRV_MAXFLEN-10;
if (bc->modem.par96.dcd_count >= 0)
bc->modem.par96.dcd_count -= 2;
hdlcdrv_setdcd(&bc->hdrv, bc->modem.par96.dcd_count > 0);
} else {
hdlcdrv_setdcd(&bc->hdrv, !!(pp->ops->read_status(pp) & PAR96_DCD));
}
}
static void par96_interrupt(void *dev_id)
{
struct net_device *dev = dev_id;
struct baycom_state *bc = netdev_priv(dev);
baycom_int_freq(bc);
if (hdlcdrv_ptt(&bc->hdrv))
par96_tx(dev, bc);
else {
par96_rx(dev, bc);
if (--bc->modem.arb_divider <= 0) {
bc->modem.arb_divider = 6;
local_irq_enable();
hdlcdrv_arbitrate(dev, &bc->hdrv);
}
}
local_irq_enable();
hdlcdrv_transmitter(dev, &bc->hdrv);
hdlcdrv_receiver(dev, &bc->hdrv);
local_irq_disable();
}
static void par96_wakeup(void *handle)
{
struct net_device *dev = (struct net_device *)handle;
struct baycom_state *bc = netdev_priv(dev);
printk(KERN_DEBUG "baycom_par: %s: why am I being woken up?\n", dev->name);
if (!parport_claim(bc->pdev))
printk(KERN_DEBUG "baycom_par: %s: I'm broken.\n", dev->name);
}
static int par96_open(struct net_device *dev)
{
struct baycom_state *bc = netdev_priv(dev);
struct parport *pp;
if (!dev || !bc)
return -ENXIO;
pp = parport_find_base(dev->base_addr);
if (!pp) {
printk(KERN_ERR "baycom_par: parport at 0x%lx unknown\n", dev->base_addr);
return -ENXIO;
}
if (pp->irq < 0) {
printk(KERN_ERR "baycom_par: parport at 0x%lx has no irq\n", pp->base);
parport_put_port(pp);
return -ENXIO;
}
if ((~pp->modes) & (PARPORT_MODE_PCSPP | PARPORT_MODE_SAFEININT)) {
printk(KERN_ERR "baycom_par: parport at 0x%lx cannot be used\n", pp->base);
parport_put_port(pp);
return -ENXIO;
}
memset(&bc->modem, 0, sizeof(bc->modem));
bc->hdrv.par.bitrate = 9600;
bc->pdev = parport_register_device(pp, dev->name, NULL, par96_wakeup,
par96_interrupt, PARPORT_DEV_EXCL, dev);
parport_put_port(pp);
if (!bc->pdev) {
printk(KERN_ERR "baycom_par: cannot register parport at 0x%lx\n", dev->base_addr);
return -ENXIO;
}
if (parport_claim(bc->pdev)) {
printk(KERN_ERR "baycom_par: parport at 0x%lx busy\n", pp->base);
parport_unregister_device(bc->pdev);
return -EBUSY;
}
pp = bc->pdev->port;
dev->irq = pp->irq;
pp->ops->data_forward(pp);
bc->hdrv.par.bitrate = 9600;
pp->ops->write_data(pp, PAR96_PTT | PAR97_POWER);
pp->ops->enable_irq(pp);
printk(KERN_INFO "%s: par96 at iobase 0x%lx irq %u options 0x%x\n",
bc_drvname, dev->base_addr, dev->irq, bc->options);
return 0;
}
static int par96_close(struct net_device *dev)
{
struct baycom_state *bc = netdev_priv(dev);
struct parport *pp;
if (!dev || !bc)
return -EINVAL;
pp = bc->pdev->port;
pp->ops->disable_irq(pp);
pp->ops->write_data(pp, PAR96_PTT | PAR97_POWER);
parport_release(bc->pdev);
parport_unregister_device(bc->pdev);
printk(KERN_INFO "%s: close par96 at iobase 0x%lx irq %u\n",
bc_drvname, dev->base_addr, dev->irq);
return 0;
}
static int baycom_setmode(struct baycom_state *bc, const char *modestr)
{
if (!strncmp(modestr, "picpar", 6))
bc->options = 0;
else if (!strncmp(modestr, "par96", 5))
bc->options = BAYCOM_OPTIONS_SOFTDCD;
else
bc->options = !!strchr(modestr, '*');
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
strcpy(hi->data.modename, bc->options ? "par96" : "picpar");
if (copy_to_user(ifr->ifr_data, hi, sizeof(struct hdlcdrv_ioctl)))
return -EFAULT;
return 0;
case HDLCDRVCTL_SETMODE:
if (netif_running(dev) || !capable(CAP_NET_ADMIN))
return -EACCES;
hi->data.modename[sizeof(hi->data.modename)-1] = '\0';
return baycom_setmode(bc, hi->data.modename);
case HDLCDRVCTL_MODELIST:
strcpy(hi->data.modename, "par96,picpar");
if (copy_to_user(ifr->ifr_data, hi, sizeof(struct hdlcdrv_ioctl)))
return -EFAULT;
return 0;
case HDLCDRVCTL_MODEMPARMASK:
return HDLCDRV_PARMASK_IOBASE;
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
static int __init init_baycompar(void)
{
int i, found = 0;
char set_hw = 1;
printk(bc_drvinfo);
for (i = 0; i < NR_PORTS; i++) {
struct net_device *dev;
struct baycom_state *bc;
char ifname[IFNAMSIZ];
sprintf(ifname, "bcp%d", i);
if (!mode[i])
set_hw = 0;
if (!set_hw)
iobase[i] = 0;
dev = hdlcdrv_register(&par96_ops,
sizeof(struct baycom_state),
ifname, iobase[i], 0, 0);
if (IS_ERR(dev))
break;
bc = netdev_priv(dev);
if (set_hw && baycom_setmode(bc, mode[i]))
set_hw = 0;
found++;
baycom_device[i] = dev;
}
if (!found)
return -ENXIO;
return 0;
}
static void __exit cleanup_baycompar(void)
{
int i;
for(i = 0; i < NR_PORTS; i++) {
struct net_device *dev = baycom_device[i];
if (dev)
hdlcdrv_unregister(dev);
}
}
static int __init baycom_par_setup(char *str)
{
static unsigned nr_dev;
int ints[2];
if (nr_dev >= NR_PORTS)
return 0;
str = get_options(str, 2, ints);
if (ints[0] < 1)
return 0;
mode[nr_dev] = str;
iobase[nr_dev] = ints[1];
nr_dev++;
return 1;
}
