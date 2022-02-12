static int __devinit ne2k_pci_init_one (struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *dev;
int i;
unsigned char SA_prom[32];
int start_page, stop_page;
int irq, reg0, chip_idx = ent->driver_data;
static unsigned int fnd_cnt;
long ioaddr;
int flags = pci_clone_list[chip_idx].flags;
#ifndef MODULE
static int printed_version;
if (!printed_version++)
printk(version);
#endif
fnd_cnt++;
i = pci_enable_device (pdev);
if (i)
return i;
ioaddr = pci_resource_start (pdev, 0);
irq = pdev->irq;
if (!ioaddr || ((pci_resource_flags (pdev, 0) & IORESOURCE_IO) == 0)) {
dev_err(&pdev->dev, "no I/O resource at PCI BAR #0\n");
return -ENODEV;
}
if (request_region (ioaddr, NE_IO_EXTENT, DRV_NAME) == NULL) {
dev_err(&pdev->dev, "I/O resource 0x%x @ 0x%lx busy\n",
NE_IO_EXTENT, ioaddr);
return -EBUSY;
}
reg0 = inb(ioaddr);
if (reg0 == 0xFF)
goto err_out_free_res;
{
int regd;
outb(E8390_NODMA+E8390_PAGE1+E8390_STOP, ioaddr + E8390_CMD);
regd = inb(ioaddr + 0x0d);
outb(0xff, ioaddr + 0x0d);
outb(E8390_NODMA+E8390_PAGE0, ioaddr + E8390_CMD);
inb(ioaddr + EN0_COUNTER0);
if (inb(ioaddr + EN0_COUNTER0) != 0) {
outb(reg0, ioaddr);
outb(regd, ioaddr + 0x0d);
goto err_out_free_res;
}
}
dev = alloc_ei_netdev();
if (!dev) {
dev_err(&pdev->dev, "cannot allocate ethernet device\n");
goto err_out_free_res;
}
dev->netdev_ops = &ne2k_netdev_ops;
SET_NETDEV_DEV(dev, &pdev->dev);
{
unsigned long reset_start_time = jiffies;
outb(inb(ioaddr + NE_RESET), ioaddr + NE_RESET);
while ((inb(ioaddr + EN0_ISR) & ENISR_RESET) == 0)
if (jiffies - reset_start_time > 2) {
dev_err(&pdev->dev,
"Card failure (no reset ack).\n");
goto err_out_free_netdev;
}
outb(0xff, ioaddr + EN0_ISR);
}
{
struct {unsigned char value, offset; } program_seq[] = {
{E8390_NODMA+E8390_PAGE0+E8390_STOP, E8390_CMD},
{0x49, EN0_DCFG},
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
outb(program_seq[i].value, ioaddr + program_seq[i].offset);
}
if (flags & ONLY_32BIT_IO) {
for (i = 0; i < 4 ; i++)
((u32 *)SA_prom)[i] = le32_to_cpu(inl(ioaddr + NE_DATAPORT));
} else
for(i = 0; i < 32 ; i++)
SA_prom[i] = inb(ioaddr + NE_DATAPORT);
outb(0x49, ioaddr + EN0_DCFG);
start_page = NESM_START_PG;
stop_page = flags & STOP_PG_0x60 ? 0x60 : NESM_STOP_PG;
dev->irq = irq;
dev->base_addr = ioaddr;
pci_set_drvdata(pdev, dev);
ei_status.name = pci_clone_list[chip_idx].name;
ei_status.tx_start_page = start_page;
ei_status.stop_page = stop_page;
ei_status.word16 = 1;
ei_status.ne2k_flags = flags;
if (fnd_cnt < MAX_UNITS) {
if (full_duplex[fnd_cnt] > 0 || (options[fnd_cnt] & FORCE_FDX))
ei_status.ne2k_flags |= FORCE_FDX;
}
ei_status.rx_start_page = start_page + TX_PAGES;
#ifdef PACKETBUF_MEMSIZE
ei_status.stop_page = ei_status.tx_start_page + PACKETBUF_MEMSIZE;
#endif
ei_status.reset_8390 = &ne2k_pci_reset_8390;
ei_status.block_input = &ne2k_pci_block_input;
ei_status.block_output = &ne2k_pci_block_output;
ei_status.get_8390_hdr = &ne2k_pci_get_8390_hdr;
ei_status.priv = (unsigned long) pdev;
dev->ethtool_ops = &ne2k_pci_ethtool_ops;
NS8390_init(dev, 0);
memcpy(dev->dev_addr, SA_prom, dev->addr_len);
memcpy(dev->perm_addr, dev->dev_addr, dev->addr_len);
i = register_netdev(dev);
if (i)
goto err_out_free_netdev;
printk("%s: %s found at %#lx, IRQ %d, %pM.\n",
dev->name, pci_clone_list[chip_idx].name, ioaddr, dev->irq,
dev->dev_addr);
return 0;
err_out_free_netdev:
free_netdev (dev);
err_out_free_res:
release_region (ioaddr, NE_IO_EXTENT);
pci_set_drvdata (pdev, NULL);
return -ENODEV;
}
static inline int set_realtek_fdx(struct net_device *dev)
{
long ioaddr = dev->base_addr;
outb(0xC0 + E8390_NODMA, ioaddr + NE_CMD);
outb(0xC0, ioaddr + 0x01);
outb(0x40, ioaddr + 0x06);
outb(0x00, ioaddr + 0x01);
outb(E8390_PAGE0 + E8390_NODMA, ioaddr + NE_CMD);
return 0;
}
static inline int set_holtek_fdx(struct net_device *dev)
{
long ioaddr = dev->base_addr;
outb(inb(ioaddr + 0x20) | 0x80, ioaddr + 0x20);
return 0;
}
static int ne2k_pci_set_fdx(struct net_device *dev)
{
if (ei_status.ne2k_flags & REALTEK_FDX)
return set_realtek_fdx(dev);
else if (ei_status.ne2k_flags & HOLTEK_FDX)
return set_holtek_fdx(dev);
return -EOPNOTSUPP;
}
static int ne2k_pci_open(struct net_device *dev)
{
int ret = request_irq(dev->irq, ei_interrupt, IRQF_SHARED, dev->name, dev);
if (ret)
return ret;
if (ei_status.ne2k_flags & FORCE_FDX)
ne2k_pci_set_fdx(dev);
ei_open(dev);
return 0;
}
static int ne2k_pci_close(struct net_device *dev)
{
ei_close(dev);
free_irq(dev->irq, dev);
return 0;
}
static void ne2k_pci_reset_8390(struct net_device *dev)
{
unsigned long reset_start_time = jiffies;
if (debug > 1) printk("%s: Resetting the 8390 t=%ld...",
dev->name, jiffies);
outb(inb(NE_BASE + NE_RESET), NE_BASE + NE_RESET);
ei_status.txing = 0;
ei_status.dmaing = 0;
while ((inb(NE_BASE+EN0_ISR) & ENISR_RESET) == 0)
if (jiffies - reset_start_time > 2) {
printk("%s: ne2k_pci_reset_8390() did not complete.\n", dev->name);
break;
}
outb(ENISR_RESET, NE_BASE + EN0_ISR);
}
static void ne2k_pci_get_8390_hdr(struct net_device *dev, struct e8390_pkt_hdr *hdr, int ring_page)
{
long nic_base = dev->base_addr;
if (ei_status.dmaing) {
printk("%s: DMAing conflict in ne2k_pci_get_8390_hdr "
"[DMAstat:%d][irqlock:%d].\n",
dev->name, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb(E8390_NODMA+E8390_PAGE0+E8390_START, nic_base+ NE_CMD);
outb(sizeof(struct e8390_pkt_hdr), nic_base + EN0_RCNTLO);
outb(0, nic_base + EN0_RCNTHI);
outb(0, nic_base + EN0_RSARLO);
outb(ring_page, nic_base + EN0_RSARHI);
outb(E8390_RREAD+E8390_START, nic_base + NE_CMD);
if (ei_status.ne2k_flags & ONLY_16BIT_IO) {
insw(NE_BASE + NE_DATAPORT, hdr, sizeof(struct e8390_pkt_hdr)>>1);
} else {
*(u32*)hdr = le32_to_cpu(inl(NE_BASE + NE_DATAPORT));
le16_to_cpus(&hdr->count);
}
outb(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static void ne2k_pci_block_input(struct net_device *dev, int count,
struct sk_buff *skb, int ring_offset)
{
long nic_base = dev->base_addr;
char *buf = skb->data;
if (ei_status.dmaing) {
printk("%s: DMAing conflict in ne2k_pci_block_input "
"[DMAstat:%d][irqlock:%d].\n",
dev->name, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
if (ei_status.ne2k_flags & ONLY_32BIT_IO)
count = (count + 3) & 0xFFFC;
outb(E8390_NODMA+E8390_PAGE0+E8390_START, nic_base+ NE_CMD);
outb(count & 0xff, nic_base + EN0_RCNTLO);
outb(count >> 8, nic_base + EN0_RCNTHI);
outb(ring_offset & 0xff, nic_base + EN0_RSARLO);
outb(ring_offset >> 8, nic_base + EN0_RSARHI);
outb(E8390_RREAD+E8390_START, nic_base + NE_CMD);
if (ei_status.ne2k_flags & ONLY_16BIT_IO) {
insw(NE_BASE + NE_DATAPORT,buf,count>>1);
if (count & 0x01) {
buf[count-1] = inb(NE_BASE + NE_DATAPORT);
}
} else {
insl(NE_BASE + NE_DATAPORT, buf, count>>2);
if (count & 3) {
buf += count & ~3;
if (count & 2) {
__le16 *b = (__le16 *)buf;
*b++ = cpu_to_le16(inw(NE_BASE + NE_DATAPORT));
buf = (char *)b;
}
if (count & 1)
*buf = inb(NE_BASE + NE_DATAPORT);
}
}
outb(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static void ne2k_pci_block_output(struct net_device *dev, int count,
const unsigned char *buf, const int start_page)
{
long nic_base = NE_BASE;
unsigned long dma_start;
if (ei_status.ne2k_flags & ONLY_32BIT_IO)
count = (count + 3) & 0xFFFC;
else
if (count & 0x01)
count++;
if (ei_status.dmaing) {
printk("%s: DMAing conflict in ne2k_pci_block_output."
"[DMAstat:%d][irqlock:%d]\n",
dev->name, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb(E8390_PAGE0+E8390_START+E8390_NODMA, nic_base + NE_CMD);
#ifdef NE8390_RW_BUGFIX
outb(0x42, nic_base + EN0_RCNTLO);
outb(0x00, nic_base + EN0_RCNTHI);
outb(0x42, nic_base + EN0_RSARLO);
outb(0x00, nic_base + EN0_RSARHI);
outb(E8390_RREAD+E8390_START, nic_base + NE_CMD);
#endif
outb(ENISR_RDC, nic_base + EN0_ISR);
outb(count & 0xff, nic_base + EN0_RCNTLO);
outb(count >> 8, nic_base + EN0_RCNTHI);
outb(0x00, nic_base + EN0_RSARLO);
outb(start_page, nic_base + EN0_RSARHI);
outb(E8390_RWRITE+E8390_START, nic_base + NE_CMD);
if (ei_status.ne2k_flags & ONLY_16BIT_IO) {
outsw(NE_BASE + NE_DATAPORT, buf, count>>1);
} else {
outsl(NE_BASE + NE_DATAPORT, buf, count>>2);
if (count & 3) {
buf += count & ~3;
if (count & 2) {
__le16 *b = (__le16 *)buf;
outw(le16_to_cpu(*b++), NE_BASE + NE_DATAPORT);
buf = (char *)b;
}
}
}
dma_start = jiffies;
while ((inb(nic_base + EN0_ISR) & ENISR_RDC) == 0)
if (jiffies - dma_start > 2) {
printk(KERN_WARNING "%s: timeout waiting for Tx RDC.\n", dev->name);
ne2k_pci_reset_8390(dev);
NS8390_init(dev,1);
break;
}
outb(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static void ne2k_pci_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct ei_device *ei = netdev_priv(dev);
struct pci_dev *pci_dev = (struct pci_dev *) ei->priv;
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(pci_dev), sizeof(info->bus_info));
}
static void __devexit ne2k_pci_remove_one (struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
BUG_ON(!dev);
unregister_netdev(dev);
release_region(dev->base_addr, NE_IO_EXTENT);
free_netdev(dev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int ne2k_pci_suspend (struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata (pdev);
netif_device_detach(dev);
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int ne2k_pci_resume (struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata (pdev);
int rc;
pci_set_power_state(pdev, 0);
pci_restore_state(pdev);
rc = pci_enable_device(pdev);
if (rc)
return rc;
NS8390_init(dev, 1);
netif_device_attach(dev);
return 0;
}
static int __init ne2k_pci_init(void)
{
#ifdef MODULE
printk(version);
#endif
return pci_register_driver(&ne2k_driver);
}
static void __exit ne2k_pci_cleanup(void)
{
pci_unregister_driver (&ne2k_driver);
}
