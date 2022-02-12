static int __init do_ne_probe(struct net_device *dev)
{
unsigned long base_addr = dev->base_addr;
#ifdef NEEDS_PORTLIST
int orig_irq = dev->irq;
#endif
if (base_addr > 0x1ff) {
int ret = ne_probe1(dev, base_addr);
if (ret)
netdev_warn(dev, "ne.c: No NE*000 card found at "
"i/o = %#lx\n", base_addr);
return ret;
}
else if (base_addr != 0)
return -ENXIO;
if (isapnp_present() && (ne_probe_isapnp(dev) == 0))
return 0;
#ifdef NEEDS_PORTLIST
for (base_addr = 0; netcard_portlist[base_addr] != 0; base_addr++) {
int ioaddr = netcard_portlist[base_addr];
dev->irq = orig_irq;
if (ne_probe1(dev, ioaddr) == 0)
return 0;
}
#endif
return -ENODEV;
}
static int __init ne_probe_isapnp(struct net_device *dev)
{
int i;
for (i = 0; isapnp_clone_list[i].vendor != 0; i++) {
struct pnp_dev *idev = NULL;
while ((idev = pnp_find_dev(NULL,
isapnp_clone_list[i].vendor,
isapnp_clone_list[i].function,
idev))) {
if (pnp_device_attach(idev) < 0)
continue;
if (pnp_activate_dev(idev) < 0) {
pnp_device_detach(idev);
continue;
}
if (!pnp_port_valid(idev, 0) || !pnp_irq_valid(idev, 0)) {
pnp_device_detach(idev);
continue;
}
dev->base_addr = pnp_port_start(idev, 0);
dev->irq = pnp_irq(idev, 0);
netdev_info(dev,
"ne.c: ISAPnP reports %s at i/o %#lx, irq %d.\n",
(char *) isapnp_clone_list[i].driver_data,
dev->base_addr, dev->irq);
if (ne_probe1(dev, dev->base_addr) != 0) {
netdev_err(dev,
"ne.c: Probe of ISAPnP card at %#lx failed.\n",
dev->base_addr);
pnp_device_detach(idev);
return -ENXIO;
}
ei_status.priv = (unsigned long)idev;
break;
}
if (!idev)
continue;
return 0;
}
return -ENODEV;
}
static int __init ne_probe1(struct net_device *dev, unsigned long ioaddr)
{
int i;
unsigned char SA_prom[32];
int wordlength = 2;
const char *name = NULL;
int start_page, stop_page;
int neX000, ctron, copam, bad_card;
int reg0, ret;
static unsigned version_printed;
struct ei_device *ei_local = netdev_priv(dev);
if (!request_region(ioaddr, NE_IO_EXTENT, DRV_NAME))
return -EBUSY;
reg0 = inb_p(ioaddr);
if (reg0 == 0xFF) {
ret = -ENODEV;
goto err_out;
}
{
int regd;
outb_p(E8390_NODMA+E8390_PAGE1+E8390_STOP, ioaddr + E8390_CMD);
regd = inb_p(ioaddr + 0x0d);
outb_p(0xff, ioaddr + 0x0d);
outb_p(E8390_NODMA+E8390_PAGE0, ioaddr + E8390_CMD);
inb_p(ioaddr + EN0_COUNTER0);
if (inb_p(ioaddr + EN0_COUNTER0) != 0) {
outb_p(reg0, ioaddr);
outb_p(regd, ioaddr + 0x0d);
ret = -ENODEV;
goto err_out;
}
}
if ((ne_msg_enable & NETIF_MSG_DRV) && (version_printed++ == 0))
netdev_info(dev, "%s%s", version1, version2);
netdev_info(dev, "NE*000 ethercard probe at %#3lx:", ioaddr);
bad_card = ((dev->base_addr != 0) && (dev->mem_end == BAD));
{
unsigned long reset_start_time = jiffies;
outb(inb(ioaddr + NE_RESET), ioaddr + NE_RESET);
while ((inb_p(ioaddr + EN0_ISR) & ENISR_RESET) == 0)
if (time_after(jiffies, reset_start_time + 2*HZ/100)) {
if (bad_card) {
pr_cont(" (warning: no reset ack)");
break;
} else {
pr_cont(" not found (no reset ack).\n");
ret = -ENODEV;
goto err_out;
}
}
outb_p(0xff, ioaddr + EN0_ISR);
}
{
struct {unsigned char value, offset; } program_seq[] =
{
{E8390_NODMA+E8390_PAGE0+E8390_STOP, E8390_CMD},
{0x48, EN0_DCFG},
{0x00, EN0_RCNTLO},
{0x00, EN0_RCNTHI},
{0x00, EN0_IMR},
{0xFF, EN0_ISR},
{E8390_RXOFF, EN0_RXCR},
{E8390_TXOFF, EN0_TXCR},
{32, EN0_RCNTLO},
{0x00, EN0_RCNTHI},
{0x00, EN0_RSARLO},
{0x00, EN0_RSARHI},
{E8390_RREAD+E8390_START, E8390_CMD},
};
for (i = 0; i < ARRAY_SIZE(program_seq); i++)
outb_p(program_seq[i].value, ioaddr + program_seq[i].offset);
}
for(i = 0; i < 32 ; i+=2) {
SA_prom[i] = inb(ioaddr + NE_DATAPORT);
SA_prom[i+1] = inb(ioaddr + NE_DATAPORT);
if (SA_prom[i] != SA_prom[i+1])
wordlength = 1;
}
if (wordlength == 2)
{
for (i = 0; i < 16; i++)
SA_prom[i] = SA_prom[i+i];
outb_p(DCR_VAL, ioaddr + EN0_DCFG);
start_page = NESM_START_PG;
if ((DCR_VAL & 0x01) == 0 &&
inb(ioaddr + EN0_RCNTLO) == 0x50 &&
inb(ioaddr + EN0_RCNTHI) == 0x70)
stop_page = 0x60;
else
stop_page = NESM_STOP_PG;
} else {
start_page = NE1SM_START_PG;
stop_page = NE1SM_STOP_PG;
}
#if defined(CONFIG_PLAT_MAPPI) || defined(CONFIG_PLAT_OAKS32R)
neX000 = ((SA_prom[14] == 0x57 && SA_prom[15] == 0x57)
|| (SA_prom[14] == 0x42 && SA_prom[15] == 0x42));
#else
neX000 = (SA_prom[14] == 0x57 && SA_prom[15] == 0x57);
#endif
ctron = (SA_prom[0] == 0x00 && SA_prom[1] == 0x00 && SA_prom[2] == 0x1d);
copam = (SA_prom[14] == 0x49 && SA_prom[15] == 0x00);
if (neX000 || bad_card || copam) {
name = (wordlength == 2) ? "NE2000" : "NE1000";
}
else if (ctron)
{
name = (wordlength == 2) ? "Ctron-8" : "Ctron-16";
start_page = 0x01;
stop_page = (wordlength == 2) ? 0x40 : 0x20;
}
else
{
#ifdef SUPPORT_NE_BAD_CLONES
for (i = 0; bad_clone_list[i].name8; i++)
{
if (SA_prom[0] == bad_clone_list[i].SAprefix[0] &&
SA_prom[1] == bad_clone_list[i].SAprefix[1] &&
SA_prom[2] == bad_clone_list[i].SAprefix[2])
{
if (wordlength == 2)
{
name = bad_clone_list[i].name16;
} else {
name = bad_clone_list[i].name8;
}
break;
}
}
if (bad_clone_list[i].name8 == NULL)
{
pr_cont(" not found (invalid signature %2.2x %2.2x).\n",
SA_prom[14], SA_prom[15]);
ret = -ENXIO;
goto err_out;
}
#else
pr_cont(" not found.\n");
ret = -ENXIO;
goto err_out;
#endif
}
if (dev->irq < 2)
{
unsigned long cookie = probe_irq_on();
outb_p(0x50, ioaddr + EN0_IMR);
outb_p(0x00, ioaddr + EN0_RCNTLO);
outb_p(0x00, ioaddr + EN0_RCNTHI);
outb_p(E8390_RREAD+E8390_START, ioaddr);
mdelay(10);
outb_p(0x00, ioaddr + EN0_IMR);
dev->irq = probe_irq_off(cookie);
if (netif_msg_probe(ei_local))
pr_cont(" autoirq is %d", dev->irq);
} else if (dev->irq == 2)
dev->irq = 9;
if (! dev->irq) {
pr_cont(" failed to detect IRQ line.\n");
ret = -EAGAIN;
goto err_out;
}
ret = request_irq(dev->irq, eip_interrupt, 0, name, dev);
if (ret) {
pr_cont(" unable to get IRQ %d (errno=%d).\n", dev->irq, ret);
goto err_out;
}
dev->base_addr = ioaddr;
#ifdef CONFIG_PLAT_MAPPI
outb_p(E8390_NODMA + E8390_PAGE1 + E8390_STOP,
ioaddr + E8390_CMD);
for (i = 0; i < ETH_ALEN; i++) {
dev->dev_addr[i] = SA_prom[i]
= inb_p(ioaddr + EN1_PHYS_SHIFT(i));
}
#else
for (i = 0; i < ETH_ALEN; i++) {
dev->dev_addr[i] = SA_prom[i];
}
#endif
pr_cont("%pM\n", dev->dev_addr);
ei_status.name = name;
ei_status.tx_start_page = start_page;
ei_status.stop_page = stop_page;
ei_status.word16 = (wordlength == 2 && (DCR_VAL & 0x01));
ei_status.rx_start_page = start_page + TX_PAGES;
#ifdef PACKETBUF_MEMSIZE
ei_status.stop_page = ei_status.tx_start_page + PACKETBUF_MEMSIZE;
#endif
ei_status.reset_8390 = &ne_reset_8390;
ei_status.block_input = &ne_block_input;
ei_status.block_output = &ne_block_output;
ei_status.get_8390_hdr = &ne_get_8390_hdr;
ei_status.priv = 0;
dev->netdev_ops = &eip_netdev_ops;
NS8390p_init(dev, 0);
ei_local->msg_enable = ne_msg_enable;
ret = register_netdev(dev);
if (ret)
goto out_irq;
netdev_info(dev, "%s found at %#lx, using IRQ %d.\n",
name, ioaddr, dev->irq);
return 0;
out_irq:
free_irq(dev->irq, dev);
err_out:
release_region(ioaddr, NE_IO_EXTENT);
return ret;
}
static void ne_reset_8390(struct net_device *dev)
{
unsigned long reset_start_time = jiffies;
struct ei_device *ei_local = netdev_priv(dev);
netif_dbg(ei_local, hw, dev, "resetting the 8390 t=%ld...\n", jiffies);
outb(inb(NE_BASE + NE_RESET), NE_BASE + NE_RESET);
ei_status.txing = 0;
ei_status.dmaing = 0;
while ((inb_p(NE_BASE+EN0_ISR) & ENISR_RESET) == 0)
if (time_after(jiffies, reset_start_time + 2*HZ/100)) {
netdev_err(dev, "ne_reset_8390() did not complete.\n");
break;
}
outb_p(ENISR_RESET, NE_BASE + EN0_ISR);
}
static void ne_get_8390_hdr(struct net_device *dev, struct e8390_pkt_hdr *hdr, int ring_page)
{
int nic_base = dev->base_addr;
if (ei_status.dmaing)
{
netdev_err(dev, "DMAing conflict in ne_get_8390_hdr "
"[DMAstat:%d][irqlock:%d].\n",
ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, nic_base+ NE_CMD);
outb_p(sizeof(struct e8390_pkt_hdr), nic_base + EN0_RCNTLO);
outb_p(0, nic_base + EN0_RCNTHI);
outb_p(0, nic_base + EN0_RSARLO);
outb_p(ring_page, nic_base + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, nic_base + NE_CMD);
if (ei_status.word16)
insw(NE_BASE + NE_DATAPORT, hdr, sizeof(struct e8390_pkt_hdr)>>1);
else
insb(NE_BASE + NE_DATAPORT, hdr, sizeof(struct e8390_pkt_hdr));
outb_p(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
le16_to_cpus(&hdr->count);
}
static void ne_block_input(struct net_device *dev, int count, struct sk_buff *skb, int ring_offset)
{
#ifdef NE_SANITY_CHECK
int xfer_count = count;
struct ei_device *ei_local = netdev_priv(dev);
#endif
int nic_base = dev->base_addr;
char *buf = skb->data;
if (ei_status.dmaing)
{
netdev_err(dev, "DMAing conflict in ne_block_input "
"[DMAstat:%d][irqlock:%d].\n",
ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, nic_base+ NE_CMD);
outb_p(count & 0xff, nic_base + EN0_RCNTLO);
outb_p(count >> 8, nic_base + EN0_RCNTHI);
outb_p(ring_offset & 0xff, nic_base + EN0_RSARLO);
outb_p(ring_offset >> 8, nic_base + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, nic_base + NE_CMD);
if (ei_status.word16)
{
insw(NE_BASE + NE_DATAPORT,buf,count>>1);
if (count & 0x01)
{
buf[count-1] = inb(NE_BASE + NE_DATAPORT);
#ifdef NE_SANITY_CHECK
xfer_count++;
#endif
}
} else {
insb(NE_BASE + NE_DATAPORT, buf, count);
}
#ifdef NE_SANITY_CHECK
if (netif_msg_rx_status(ei_local))
{
int addr, tries = 20;
do {
int high = inb_p(nic_base + EN0_RSARHI);
int low = inb_p(nic_base + EN0_RSARLO);
addr = (high << 8) + low;
if (((ring_offset + xfer_count) & 0xff) == low)
break;
} while (--tries > 0);
if (tries <= 0)
netdev_warn(dev, "RX transfer address mismatch,"
"%#4.4x (expected) vs. %#4.4x (actual).\n",
ring_offset + xfer_count, addr);
}
#endif
outb_p(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static void ne_block_output(struct net_device *dev, int count,
const unsigned char *buf, const int start_page)
{
int nic_base = NE_BASE;
unsigned long dma_start;
#ifdef NE_SANITY_CHECK
int retries = 0;
struct ei_device *ei_local = netdev_priv(dev);
#endif
if (ei_status.word16 && (count & 0x01))
count++;
if (ei_status.dmaing)
{
netdev_err(dev, "DMAing conflict in ne_block_output."
"[DMAstat:%d][irqlock:%d]\n",
ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_PAGE0+E8390_START+E8390_NODMA, nic_base + NE_CMD);
#ifdef NE_SANITY_CHECK
retry:
#endif
#ifdef NE8390_RW_BUGFIX
outb_p(0x42, nic_base + EN0_RCNTLO);
outb_p(0x00, nic_base + EN0_RCNTHI);
outb_p(0x42, nic_base + EN0_RSARLO);
outb_p(0x00, nic_base + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, nic_base + NE_CMD);
udelay(6);
#endif
outb_p(ENISR_RDC, nic_base + EN0_ISR);
outb_p(count & 0xff, nic_base + EN0_RCNTLO);
outb_p(count >> 8, nic_base + EN0_RCNTHI);
outb_p(0x00, nic_base + EN0_RSARLO);
outb_p(start_page, nic_base + EN0_RSARHI);
outb_p(E8390_RWRITE+E8390_START, nic_base + NE_CMD);
if (ei_status.word16) {
outsw(NE_BASE + NE_DATAPORT, buf, count>>1);
} else {
outsb(NE_BASE + NE_DATAPORT, buf, count);
}
dma_start = jiffies;
#ifdef NE_SANITY_CHECK
if (netif_msg_tx_queued(ei_local))
{
int addr, tries = 20;
do {
int high = inb_p(nic_base + EN0_RSARHI);
int low = inb_p(nic_base + EN0_RSARLO);
addr = (high << 8) + low;
if ((start_page << 8) + count == addr)
break;
} while (--tries > 0);
if (tries <= 0)
{
netdev_warn(dev, "Tx packet transfer address mismatch,"
"%#4.4x (expected) vs. %#4.4x (actual).\n",
(start_page << 8) + count, addr);
if (retries++ == 0)
goto retry;
}
}
#endif
while ((inb_p(nic_base + EN0_ISR) & ENISR_RDC) == 0)
if (time_after(jiffies, dma_start + 2*HZ/100)) {
netdev_warn(dev, "timeout waiting for Tx RDC.\n");
ne_reset_8390(dev);
NS8390p_init(dev, 1);
break;
}
outb_p(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static int __init ne_drv_probe(struct platform_device *pdev)
{
struct net_device *dev;
int err, this_dev = pdev->id;
struct resource *res;
dev = alloc_eip_netdev();
if (!dev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (res) {
dev->base_addr = res->start;
dev->irq = platform_get_irq(pdev, 0);
} else {
if (this_dev < 0 || this_dev >= MAX_NE_CARDS) {
free_netdev(dev);
return -EINVAL;
}
dev->base_addr = io[this_dev];
dev->irq = irq[this_dev];
dev->mem_end = bad[this_dev];
}
SET_NETDEV_DEV(dev, &pdev->dev);
err = do_ne_probe(dev);
if (err) {
free_netdev(dev);
return err;
}
platform_set_drvdata(pdev, dev);
if (!res) {
io[this_dev] = dev->base_addr;
irq[this_dev] = dev->irq;
}
return 0;
}
static int ne_drv_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
if (dev) {
struct pnp_dev *idev = (struct pnp_dev *)ei_status.priv;
netif_device_detach(dev);
unregister_netdev(dev);
if (idev)
pnp_device_detach(idev);
ei_status.priv = 0;
free_irq(dev->irq, dev);
release_region(dev->base_addr, NE_IO_EXTENT);
free_netdev(dev);
}
return 0;
}
static void ne_loop_rm_unreg(int all)
{
int this_dev;
struct platform_device *pdev;
for (this_dev = 0; this_dev < MAX_NE_CARDS; this_dev++) {
pdev = pdev_ne[this_dev];
if (pdev && (!platform_get_drvdata(pdev) || all)) {
ne_drv_remove(pdev);
platform_device_unregister(pdev);
pdev_ne[this_dev] = NULL;
}
}
}
static int ne_drv_suspend(struct platform_device *pdev, pm_message_t state)
{
struct net_device *dev = platform_get_drvdata(pdev);
if (netif_running(dev)) {
struct pnp_dev *idev = (struct pnp_dev *)ei_status.priv;
netif_device_detach(dev);
if (idev)
pnp_stop_dev(idev);
}
return 0;
}
static int ne_drv_resume(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
if (netif_running(dev)) {
struct pnp_dev *idev = (struct pnp_dev *)ei_status.priv;
if (idev)
pnp_start_dev(idev);
ne_reset_8390(dev);
NS8390p_init(dev, 1);
netif_device_attach(dev);
}
return 0;
}
static void __init ne_add_devices(void)
{
int this_dev;
struct platform_device *pdev;
for (this_dev = 0; this_dev < MAX_NE_CARDS; this_dev++) {
if (pdev_ne[this_dev])
continue;
pdev = platform_device_register_simple(
DRV_NAME, this_dev, NULL, 0);
if (IS_ERR(pdev))
continue;
pdev_ne[this_dev] = pdev;
}
}
int __init init_module(void)
{
int retval;
ne_add_devices();
retval = platform_driver_probe(&ne_driver, ne_drv_probe);
if (retval) {
if (io[0] == 0)
pr_notice("ne.c: You must supply \"io=0xNNN\""
" value(s) for ISA cards.\n");
ne_loop_rm_unreg(1);
return retval;
}
ne_loop_rm_unreg(0);
return retval;
}
static int __init ne_init(void)
{
int retval = platform_driver_probe(&ne_driver, ne_drv_probe);
ne_loop_rm_unreg(0);
return retval;
}
struct net_device * __init ne_probe(int unit)
{
int this_dev;
struct net_device *dev;
this_dev = 0;
while ((pdev_ne[this_dev] && platform_get_drvdata(pdev_ne[this_dev])) ||
io[this_dev]) {
if (++this_dev == MAX_NE_CARDS)
return ERR_PTR(-ENOMEM);
}
dev = alloc_eip_netdev();
if (!dev)
return ERR_PTR(-ENOMEM);
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
io[this_dev] = dev->base_addr;
irq[this_dev] = dev->irq;
bad[this_dev] = dev->mem_end;
free_netdev(dev);
ne_add_devices();
for (this_dev = 0; this_dev < MAX_NE_CARDS; this_dev++) {
if (pdev_ne[this_dev]) {
dev = platform_get_drvdata(pdev_ne[this_dev]);
if (dev)
return dev;
}
}
return ERR_PTR(-ENODEV);
}
static void __exit ne_exit(void)
{
platform_driver_unregister(&ne_driver);
ne_loop_rm_unreg(1);
}
