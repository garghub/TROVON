static int __devinit streamer_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *dev;
struct streamer_private *streamer_priv;
unsigned long pio_start, pio_end, pio_flags, pio_len;
unsigned long mmio_start, mmio_end, mmio_flags, mmio_len;
int rc = 0;
static int card_no=-1;
u16 pcr;
#if STREAMER_DEBUG
printk("lanstreamer::streamer_init_one, entry pdev %p\n",pdev);
#endif
card_no++;
dev = alloc_trdev(sizeof(*streamer_priv));
if (dev==NULL) {
printk(KERN_ERR "lanstreamer: out of memory.\n");
return -ENOMEM;
}
streamer_priv = netdev_priv(dev);
#if STREAMER_NETWORK_MONITOR
#ifdef CONFIG_PROC_FS
if (!dev_streamer)
create_proc_read_entry("streamer_tr", 0, init_net.proc_net,
streamer_proc_info, NULL);
streamer_priv->next = dev_streamer;
dev_streamer = streamer_priv;
#endif
#endif
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
printk(KERN_ERR "%s: No suitable PCI mapping available.\n",
dev->name);
rc = -ENODEV;
goto err_out;
}
rc = pci_enable_device(pdev);
if (rc) {
printk(KERN_ERR "lanstreamer: unable to enable pci device\n");
rc=-EIO;
goto err_out;
}
pci_set_master(pdev);
rc = pci_set_mwi(pdev);
if (rc) {
printk(KERN_ERR "lanstreamer: unable to enable MWI on pci device\n");
goto err_out_disable;
}
pio_start = pci_resource_start(pdev, 0);
pio_end = pci_resource_end(pdev, 0);
pio_flags = pci_resource_flags(pdev, 0);
pio_len = pci_resource_len(pdev, 0);
mmio_start = pci_resource_start(pdev, 1);
mmio_end = pci_resource_end(pdev, 1);
mmio_flags = pci_resource_flags(pdev, 1);
mmio_len = pci_resource_len(pdev, 1);
#if STREAMER_DEBUG
printk("lanstreamer: pio_start %x pio_end %x pio_len %x pio_flags %x\n",
pio_start, pio_end, pio_len, pio_flags);
printk("lanstreamer: mmio_start %x mmio_end %x mmio_len %x mmio_flags %x\n",
mmio_start, mmio_end, mmio_flags, mmio_len);
#endif
if (!request_region(pio_start, pio_len, "lanstreamer")) {
printk(KERN_ERR "lanstreamer: unable to get pci io addr %lx\n",
pio_start);
rc= -EBUSY;
goto err_out_mwi;
}
if (!request_mem_region(mmio_start, mmio_len, "lanstreamer")) {
printk(KERN_ERR "lanstreamer: unable to get pci mmio addr %lx\n",
mmio_start);
rc= -EBUSY;
goto err_out_free_pio;
}
streamer_priv->streamer_mmio=ioremap(mmio_start, mmio_len);
if (streamer_priv->streamer_mmio == NULL) {
printk(KERN_ERR "lanstreamer: unable to remap MMIO %lx\n",
mmio_start);
rc= -EIO;
goto err_out_free_mmio;
}
init_waitqueue_head(&streamer_priv->srb_wait);
init_waitqueue_head(&streamer_priv->trb_wait);
dev->netdev_ops = &streamer_netdev_ops;
dev->irq = pdev->irq;
dev->base_addr=pio_start;
SET_NETDEV_DEV(dev, &pdev->dev);
streamer_priv->streamer_card_name = (char *)pdev->resource[0].name;
streamer_priv->pci_dev = pdev;
if ((pkt_buf_sz[card_no] < 100) || (pkt_buf_sz[card_no] > 18000))
streamer_priv->pkt_buf_sz = PKT_BUF_SZ;
else
streamer_priv->pkt_buf_sz = pkt_buf_sz[card_no];
streamer_priv->streamer_ring_speed = ringspeed[card_no];
streamer_priv->streamer_message_level = message_level[card_no];
pci_set_drvdata(pdev, dev);
spin_lock_init(&streamer_priv->streamer_lock);
pci_read_config_word (pdev, PCI_COMMAND, &pcr);
pcr |= PCI_COMMAND_SERR;
pci_write_config_word (pdev, PCI_COMMAND, pcr);
printk("%s\n", version);
printk("%s: %s. I/O at %hx, MMIO at %p, using irq %d\n",dev->name,
streamer_priv->streamer_card_name,
(unsigned int) dev->base_addr,
streamer_priv->streamer_mmio,
dev->irq);
if (streamer_reset(dev))
goto err_out_unmap;
rc = register_netdev(dev);
if (rc)
goto err_out_unmap;
return 0;
err_out_unmap:
iounmap(streamer_priv->streamer_mmio);
err_out_free_mmio:
release_mem_region(mmio_start, mmio_len);
err_out_free_pio:
release_region(pio_start, pio_len);
err_out_mwi:
pci_clear_mwi(pdev);
err_out_disable:
pci_disable_device(pdev);
err_out:
free_netdev(dev);
#if STREAMER_DEBUG
printk("lanstreamer: Exit error %x\n",rc);
#endif
return rc;
}
static void __devexit streamer_remove_one(struct pci_dev *pdev)
{
struct net_device *dev=pci_get_drvdata(pdev);
struct streamer_private *streamer_priv;
#if STREAMER_DEBUG
printk("lanstreamer::streamer_remove_one entry pdev %p\n",pdev);
#endif
if (dev == NULL) {
printk(KERN_ERR "lanstreamer::streamer_remove_one, ERROR dev is NULL\n");
return;
}
streamer_priv=netdev_priv(dev);
if (streamer_priv == NULL) {
printk(KERN_ERR "lanstreamer::streamer_remove_one, ERROR dev->priv is NULL\n");
return;
}
#if STREAMER_NETWORK_MONITOR
#ifdef CONFIG_PROC_FS
{
struct streamer_private **p, **next;
for (p = &dev_streamer; *p; p = next) {
next = &(*p)->next;
if (*p == streamer_priv) {
*p = *next;
break;
}
}
if (!dev_streamer)
remove_proc_entry("streamer_tr", init_net.proc_net);
}
#endif
#endif
unregister_netdev(dev);
iounmap(streamer_priv->streamer_mmio);
release_mem_region(pci_resource_start(pdev, 1), pci_resource_len(pdev,1));
release_region(pci_resource_start(pdev, 0), pci_resource_len(pdev,0));
pci_clear_mwi(pdev);
pci_disable_device(pdev);
free_netdev(dev);
pci_set_drvdata(pdev, NULL);
}
static int streamer_reset(struct net_device *dev)
{
struct streamer_private *streamer_priv;
__u8 __iomem *streamer_mmio;
unsigned long t;
unsigned int uaa_addr;
struct sk_buff *skb = NULL;
__u16 misr;
streamer_priv = netdev_priv(dev);
streamer_mmio = streamer_priv->streamer_mmio;
writew(readw(streamer_mmio + BCTL) | BCTL_SOFTRESET, streamer_mmio + BCTL);
t = jiffies;
ssleep(1);
writew(readw(streamer_mmio + BCTL) & ~BCTL_SOFTRESET,
streamer_mmio + BCTL);
#if STREAMER_DEBUG
printk("BCTL: %x\n", readw(streamer_mmio + BCTL));
printk("GPR: %x\n", readw(streamer_mmio + GPR));
printk("SISRMASK: %x\n", readw(streamer_mmio + SISR_MASK));
#endif
writew(readw(streamer_mmio + BCTL) | (BCTL_RX_FIFO_8 | BCTL_TX_FIFO_8), streamer_mmio + BCTL );
if (streamer_priv->streamer_ring_speed == 0) {
writew(readw(streamer_mmio + GPR) | GPR_AUTOSENSE,
streamer_mmio + GPR);
if (streamer_priv->streamer_message_level)
printk(KERN_INFO "%s: Ringspeed autosense mode on\n",
dev->name);
} else if (streamer_priv->streamer_ring_speed == 16) {
if (streamer_priv->streamer_message_level)
printk(KERN_INFO "%s: Trying to open at 16 Mbps as requested\n",
dev->name);
writew(GPR_16MBPS, streamer_mmio + GPR);
} else if (streamer_priv->streamer_ring_speed == 4) {
if (streamer_priv->streamer_message_level)
printk(KERN_INFO "%s: Trying to open at 4 Mbps as requested\n",
dev->name);
writew(0, streamer_mmio + GPR);
}
skb = dev_alloc_skb(streamer_priv->pkt_buf_sz);
if (!skb) {
printk(KERN_INFO "%s: skb allocation for diagnostics failed...proceeding\n",
dev->name);
} else {
struct streamer_rx_desc *rx_ring;
u8 *data;
rx_ring=(struct streamer_rx_desc *)skb->data;
data=((u8 *)skb->data)+sizeof(struct streamer_rx_desc);
rx_ring->forward=0;
rx_ring->status=0;
rx_ring->buffer=cpu_to_le32(pci_map_single(streamer_priv->pci_dev, data,
512, PCI_DMA_FROMDEVICE));
rx_ring->framelen_buflen=512;
writel(cpu_to_le32(pci_map_single(streamer_priv->pci_dev, rx_ring, 512, PCI_DMA_FROMDEVICE)),
streamer_mmio+RXBDA);
}
#if STREAMER_DEBUG
printk("GPR = %x\n", readw(streamer_mmio + GPR));
#endif
writew(SISR_MI, streamer_mmio + SISR_MASK_SUM);
while (!((readw(streamer_mmio + SISR)) & SISR_SRB_REPLY)) {
msleep_interruptible(100);
if (time_after(jiffies, t + 40 * HZ)) {
printk(KERN_ERR
"IBM PCI tokenring card not responding\n");
release_region(dev->base_addr, STREAMER_IO_SPACE);
if (skb)
dev_kfree_skb(skb);
return -1;
}
}
writew(~SISR_SRB_REPLY, streamer_mmio + SISR_RUM);
misr = readw(streamer_mmio + MISR_RUM);
writew(~misr, streamer_mmio + MISR_RUM);
if (skb)
dev_kfree_skb(skb);
#if STREAMER_DEBUG
printk("LAPWWO: %x, LAPA: %x LAPE: %x\n",
readw(streamer_mmio + LAPWWO), readw(streamer_mmio + LAPA),
readw(streamer_mmio + LAPE));
#endif
#if STREAMER_DEBUG
{
int i;
writew(readw(streamer_mmio + LAPWWO),
streamer_mmio + LAPA);
printk("initialization response srb dump: ");
for (i = 0; i < 10; i++)
printk("%x:",
ntohs(readw(streamer_mmio + LAPDINC)));
printk("\n");
}
#endif
writew(readw(streamer_mmio + LAPWWO) + 6, streamer_mmio + LAPA);
if (readw(streamer_mmio + LAPD)) {
printk(KERN_INFO "tokenring card initialization failed. errorcode : %x\n",
ntohs(readw(streamer_mmio + LAPD)));
release_region(dev->base_addr, STREAMER_IO_SPACE);
return -1;
}
writew(readw(streamer_mmio + LAPWWO) + 8, streamer_mmio + LAPA);
uaa_addr = ntohs(readw(streamer_mmio + LAPDINC));
readw(streamer_mmio + LAPDINC);
streamer_priv->streamer_addr_table_addr = ntohs(readw(streamer_mmio + LAPDINC));
streamer_priv->streamer_parms_addr = ntohs(readw(streamer_mmio + LAPDINC));
#if STREAMER_DEBUG
printk("UAA resides at %x\n", uaa_addr);
#endif
{
int i;
__u16 addr;
writew(uaa_addr, streamer_mmio + LAPA);
for (i = 0; i < 6; i += 2) {
addr=ntohs(readw(streamer_mmio+LAPDINC));
dev->dev_addr[i]= (addr >> 8) & 0xff;
dev->dev_addr[i+1]= addr & 0xff;
}
#if STREAMER_DEBUG
printk("Adapter address: %pM\n", dev->dev_addr);
#endif
}
return 0;
}
static int streamer_open(struct net_device *dev)
{
struct streamer_private *streamer_priv = netdev_priv(dev);
__u8 __iomem *streamer_mmio = streamer_priv->streamer_mmio;
unsigned long flags;
char open_error[255];
int i, open_finished = 1;
__u16 srb_word;
__u16 srb_open;
int rc;
if (readw(streamer_mmio+BMCTL_SUM) & BMCTL_RX_ENABLED) {
rc=streamer_reset(dev);
}
if (request_irq(dev->irq, streamer_interrupt, IRQF_SHARED, "lanstreamer", dev)) {
return -EAGAIN;
}
#if STREAMER_DEBUG
printk("BMCTL: %x\n", readw(streamer_mmio + BMCTL_SUM));
printk("pending ints: %x\n", readw(streamer_mmio + SISR));
#endif
writew(SISR_MI | SISR_SRB_REPLY, streamer_mmio + SISR_MASK);
writew(LISR_LIE, streamer_mmio + LISR);
writew(readw(streamer_mmio + LAPWWO), streamer_mmio + LAPA);
#if STREAMER_DEBUG
printk("LAPWWO: %x, LAPA: %x\n", readw(streamer_mmio + LAPWWO),
readw(streamer_mmio + LAPA));
printk("LAPE: %x\n", readw(streamer_mmio + LAPE));
printk("SISR Mask = %04x\n", readw(streamer_mmio + SISR_MASK));
#endif
do {
for (i = 0; i < SRB_COMMAND_SIZE; i += 2) {
writew(0, streamer_mmio + LAPDINC);
}
writew(readw(streamer_mmio+LAPWWO),streamer_mmio+LAPA);
writew(htons(SRB_OPEN_ADAPTER<<8),streamer_mmio+LAPDINC) ;
writew(htons(STREAMER_CLEAR_RET_CODE<<8),streamer_mmio+LAPDINC);
writew(STREAMER_CLEAR_RET_CODE, streamer_mmio + LAPDINC);
writew(readw(streamer_mmio + LAPWWO) + 8, streamer_mmio + LAPA);
#if STREAMER_NETWORK_MONITOR
writew(htons(OPEN_ADAPTER_ENABLE_FDX | OPEN_ADAPTER_PASS_ADC_MAC | OPEN_ADAPTER_PASS_ATT_MAC | OPEN_ADAPTER_PASS_BEACON), streamer_mmio + LAPDINC);
#else
writew(htons(OPEN_ADAPTER_ENABLE_FDX), streamer_mmio + LAPDINC);
#endif
if (streamer_priv->streamer_laa[0]) {
writew(readw(streamer_mmio + LAPWWO) + 12, streamer_mmio + LAPA);
writew(htons((streamer_priv->streamer_laa[0] << 8) |
streamer_priv->streamer_laa[1]),streamer_mmio+LAPDINC);
writew(htons((streamer_priv->streamer_laa[2] << 8) |
streamer_priv->streamer_laa[3]),streamer_mmio+LAPDINC);
writew(htons((streamer_priv->streamer_laa[4] << 8) |
streamer_priv->streamer_laa[5]),streamer_mmio+LAPDINC);
memcpy(dev->dev_addr, streamer_priv->streamer_laa, dev->addr_len);
}
srb_open = readw(streamer_mmio + LAPWWO);
#if STREAMER_DEBUG
writew(readw(streamer_mmio + LAPWWO),
streamer_mmio + LAPA);
printk("srb open request:\n");
for (i = 0; i < 16; i++) {
printk("%x:", ntohs(readw(streamer_mmio + LAPDINC)));
}
printk("\n");
#endif
spin_lock_irqsave(&streamer_priv->streamer_lock, flags);
streamer_priv->srb_queued = 1;
writew(LISR_SRB_CMD, streamer_mmio + LISR_SUM);
spin_unlock_irqrestore(&streamer_priv->streamer_lock, flags);
while (streamer_priv->srb_queued) {
interruptible_sleep_on_timeout(&streamer_priv->srb_wait, 5 * HZ);
if (signal_pending(current)) {
printk(KERN_WARNING "%s: SRB timed out.\n", dev->name);
printk(KERN_WARNING "SISR=%x MISR=%x, LISR=%x\n",
readw(streamer_mmio + SISR),
readw(streamer_mmio + MISR_RUM),
readw(streamer_mmio + LISR));
streamer_priv->srb_queued = 0;
break;
}
}
#if STREAMER_DEBUG
printk("SISR_MASK: %x\n", readw(streamer_mmio + SISR_MASK));
printk("srb open response:\n");
writew(srb_open, streamer_mmio + LAPA);
for (i = 0; i < 10; i++) {
printk("%x:",
ntohs(readw(streamer_mmio + LAPDINC)));
}
#endif
writew(srb_open + 2, streamer_mmio + LAPA);
srb_word = ntohs(readw(streamer_mmio + LAPD)) >> 8;
if (srb_word == STREAMER_CLEAR_RET_CODE) {
printk(KERN_WARNING "%s: Adapter Open time out or error.\n",
dev->name);
return -EIO;
}
if (srb_word != 0) {
if (srb_word == 0x07) {
if (!streamer_priv->streamer_ring_speed && open_finished) {
printk(KERN_WARNING "%s: Retrying at different ring speed\n",
dev->name);
open_finished = 0;
} else {
__u16 error_code;
writew(srb_open + 6, streamer_mmio + LAPA);
error_code = ntohs(readw(streamer_mmio + LAPD));
strcpy(open_error, open_maj_error[(error_code & 0xf0) >> 4]);
strcat(open_error, " - ");
strcat(open_error, open_min_error[(error_code & 0x0f)]);
if (!streamer_priv->streamer_ring_speed &&
((error_code & 0x0f) == 0x0d))
{
printk(KERN_WARNING "%s: Tried to autosense ring speed with no monitors present\n", dev->name);
printk(KERN_WARNING "%s: Please try again with a specified ring speed\n", dev->name);
free_irq(dev->irq, dev);
return -EIO;
}
printk(KERN_WARNING "%s: %s\n",
dev->name, open_error);
free_irq(dev->irq, dev);
return -EIO;
}
} else {
printk(KERN_WARNING "%s: Bad OPEN response: %x\n",
dev->name, srb_word);
free_irq(dev->irq, dev);
return -EIO;
}
} else
open_finished = 1;
} while (!(open_finished));
writew(srb_open + 18, streamer_mmio + LAPA);
srb_word=ntohs(readw(streamer_mmio+LAPD)) >> 8;
if (srb_word & (1 << 3))
if (streamer_priv->streamer_message_level)
printk(KERN_INFO "%s: Opened in FDX Mode\n", dev->name);
if (srb_word & 1)
streamer_priv->streamer_ring_speed = 16;
else
streamer_priv->streamer_ring_speed = 4;
if (streamer_priv->streamer_message_level)
printk(KERN_INFO "%s: Opened in %d Mbps mode\n",
dev->name,
streamer_priv->streamer_ring_speed);
writew(srb_open + 8, streamer_mmio + LAPA);
streamer_priv->asb = ntohs(readw(streamer_mmio + LAPDINC));
streamer_priv->srb = ntohs(readw(streamer_mmio + LAPDINC));
streamer_priv->arb = ntohs(readw(streamer_mmio + LAPDINC));
readw(streamer_mmio + LAPDINC);
streamer_priv->trb = ntohs(readw(streamer_mmio + LAPDINC));
streamer_priv->streamer_receive_options = 0x00;
streamer_priv->streamer_copy_all_options = 0;
writew(~BMCTL_RX_DIS, streamer_mmio + BMCTL_RUM);
streamer_priv->streamer_rx_ring=
kmalloc( sizeof(struct streamer_rx_desc)*
STREAMER_RX_RING_SIZE,GFP_KERNEL);
if (!streamer_priv->streamer_rx_ring) {
printk(KERN_WARNING "%s ALLOC of streamer rx ring FAILED!!\n",dev->name);
return -EIO;
}
for (i = 0; i < STREAMER_RX_RING_SIZE; i++) {
struct sk_buff *skb;
skb = dev_alloc_skb(streamer_priv->pkt_buf_sz);
if (skb == NULL)
break;
skb->dev = dev;
streamer_priv->streamer_rx_ring[i].forward =
cpu_to_le32(pci_map_single(streamer_priv->pci_dev, &streamer_priv->streamer_rx_ring[i + 1],
sizeof(struct streamer_rx_desc), PCI_DMA_FROMDEVICE));
streamer_priv->streamer_rx_ring[i].status = 0;
streamer_priv->streamer_rx_ring[i].buffer =
cpu_to_le32(pci_map_single(streamer_priv->pci_dev, skb->data,
streamer_priv->pkt_buf_sz, PCI_DMA_FROMDEVICE));
streamer_priv->streamer_rx_ring[i].framelen_buflen = streamer_priv->pkt_buf_sz;
streamer_priv->rx_ring_skb[i] = skb;
}
streamer_priv->streamer_rx_ring[STREAMER_RX_RING_SIZE - 1].forward =
cpu_to_le32(pci_map_single(streamer_priv->pci_dev, &streamer_priv->streamer_rx_ring[0],
sizeof(struct streamer_rx_desc), PCI_DMA_FROMDEVICE));
if (i == 0) {
printk(KERN_WARNING "%s: Not enough memory to allocate rx buffers. Adapter disabled\n", dev->name);
free_irq(dev->irq, dev);
return -EIO;
}
streamer_priv->rx_ring_last_received = STREAMER_RX_RING_SIZE - 1;
writel(cpu_to_le32(pci_map_single(streamer_priv->pci_dev, &streamer_priv->streamer_rx_ring[0],
sizeof(struct streamer_rx_desc), PCI_DMA_TODEVICE)),
streamer_mmio + RXBDA);
writel(cpu_to_le32(pci_map_single(streamer_priv->pci_dev, &streamer_priv->streamer_rx_ring[STREAMER_RX_RING_SIZE - 1],
sizeof(struct streamer_rx_desc), PCI_DMA_TODEVICE)),
streamer_mmio + RXLBDA);
writew(MISR_RX_NOBUF | MISR_RX_EOF, streamer_mmio + MISR_MASK);
streamer_priv->streamer_tx_ring=kmalloc(sizeof(struct streamer_tx_desc)*
STREAMER_TX_RING_SIZE,GFP_KERNEL);
if (!streamer_priv->streamer_tx_ring) {
printk(KERN_WARNING "%s ALLOC of streamer_tx_ring FAILED\n",dev->name);
return -EIO;
}
writew(~BMCTL_TX2_DIS, streamer_mmio + BMCTL_RUM);
for (i = 0; i < STREAMER_TX_RING_SIZE; i++) {
streamer_priv->streamer_tx_ring[i].forward = cpu_to_le32(pci_map_single(streamer_priv->pci_dev,
&streamer_priv->streamer_tx_ring[i + 1],
sizeof(struct streamer_tx_desc),
PCI_DMA_TODEVICE));
streamer_priv->streamer_tx_ring[i].status = 0;
streamer_priv->streamer_tx_ring[i].bufcnt_framelen = 0;
streamer_priv->streamer_tx_ring[i].buffer = 0;
streamer_priv->streamer_tx_ring[i].buflen = 0;
streamer_priv->streamer_tx_ring[i].rsvd1 = 0;
streamer_priv->streamer_tx_ring[i].rsvd2 = 0;
streamer_priv->streamer_tx_ring[i].rsvd3 = 0;
}
streamer_priv->streamer_tx_ring[STREAMER_TX_RING_SIZE - 1].forward =
cpu_to_le32(pci_map_single(streamer_priv->pci_dev, &streamer_priv->streamer_tx_ring[0],
sizeof(struct streamer_tx_desc), PCI_DMA_TODEVICE));
streamer_priv->free_tx_ring_entries = STREAMER_TX_RING_SIZE;
streamer_priv->tx_ring_free = 0;
streamer_priv->tx_ring_last_status = STREAMER_TX_RING_SIZE - 1;
writew(MISR_TX2_EOF | MISR_RX_NOBUF | MISR_RX_EOF, streamer_mmio + MISR_MASK);
writew(SISR_ADAPTER_CHECK | SISR_ARB_CMD | SISR_TRB_REPLY | SISR_ASB_FREE, streamer_mmio + SISR_MASK_SUM);
#if STREAMER_DEBUG
printk("BMCTL: %x\n", readw(streamer_mmio + BMCTL_SUM));
printk("SISR MASK: %x\n", readw(streamer_mmio + SISR_MASK));
#endif
#if STREAMER_NETWORK_MONITOR
writew(streamer_priv->streamer_addr_table_addr, streamer_mmio + LAPA);
printk("%s: Node Address: %04x:%04x:%04x\n", dev->name,
ntohs(readw(streamer_mmio + LAPDINC)),
ntohs(readw(streamer_mmio + LAPDINC)),
ntohs(readw(streamer_mmio + LAPDINC)));
readw(streamer_mmio + LAPDINC);
readw(streamer_mmio + LAPDINC);
printk("%s: Functional Address: %04x:%04x\n", dev->name,
ntohs(readw(streamer_mmio + LAPDINC)),
ntohs(readw(streamer_mmio + LAPDINC)));
writew(streamer_priv->streamer_parms_addr + 4,
streamer_mmio + LAPA);
printk("%s: NAUN Address: %04x:%04x:%04x\n", dev->name,
ntohs(readw(streamer_mmio + LAPDINC)),
ntohs(readw(streamer_mmio + LAPDINC)),
ntohs(readw(streamer_mmio + LAPDINC)));
#endif
netif_start_queue(dev);
netif_carrier_on(dev);
return 0;
}
static void streamer_rx(struct net_device *dev)
{
struct streamer_private *streamer_priv =
netdev_priv(dev);
__u8 __iomem *streamer_mmio = streamer_priv->streamer_mmio;
struct streamer_rx_desc *rx_desc;
int rx_ring_last_received, length, frame_length, buffer_cnt = 0;
struct sk_buff *skb, *skb2;
rx_desc = &streamer_priv->streamer_rx_ring[(streamer_priv->rx_ring_last_received + 1) & (STREAMER_RX_RING_SIZE - 1)];
rx_ring_last_received = streamer_priv->rx_ring_last_received;
while (rx_desc->status & 0x01000000) {
if (rx_ring_last_received != streamer_priv->rx_ring_last_received)
{
printk(KERN_WARNING "RX Error 1 rx_ring_last_received not the same %x %x\n",
rx_ring_last_received, streamer_priv->rx_ring_last_received);
}
streamer_priv->rx_ring_last_received = (streamer_priv->rx_ring_last_received + 1) & (STREAMER_RX_RING_SIZE - 1);
rx_ring_last_received = streamer_priv->rx_ring_last_received;
length = rx_desc->framelen_buflen & 0xffff;
frame_length = (rx_desc->framelen_buflen >> 16) & 0xffff;
if (rx_desc->status & 0x7E830000) {
if (streamer_priv->streamer_message_level) {
printk(KERN_WARNING "%s: Rx Error %x\n",
dev->name, rx_desc->status);
}
} else {
if (rx_desc->status & 0x80000000) {
buffer_cnt = 1;
skb = dev_alloc_skb(streamer_priv->pkt_buf_sz);
} else {
skb = dev_alloc_skb(frame_length);
}
if (skb == NULL)
{
printk(KERN_WARNING "%s: Not enough memory to copy packet to upper layers.\n", dev->name);
dev->stats.rx_dropped++;
} else {
if (buffer_cnt == 1) {
pci_unmap_single(streamer_priv->pci_dev,
le32_to_cpu(streamer_priv->streamer_rx_ring[rx_ring_last_received].buffer),
streamer_priv->pkt_buf_sz,
PCI_DMA_FROMDEVICE);
skb2 = streamer_priv->rx_ring_skb[rx_ring_last_received];
#if STREAMER_DEBUG_PACKETS
{
int i;
printk("streamer_rx packet print: skb->data2 %p skb->head %p\n", skb2->data, skb2->head);
for (i = 0; i < frame_length; i++)
{
printk("%x:", skb2->data[i]);
if (((i + 1) % 16) == 0)
printk("\n");
}
printk("\n");
}
#endif
skb_put(skb2, length);
skb2->protocol = tr_type_trans(skb2, dev);
streamer_priv->streamer_rx_ring[rx_ring_last_received].status = 0;
streamer_priv->streamer_rx_ring[rx_ring_last_received].framelen_buflen = streamer_priv->pkt_buf_sz;
streamer_priv->streamer_rx_ring[rx_ring_last_received].buffer =
cpu_to_le32(pci_map_single(streamer_priv->pci_dev, skb->data, streamer_priv->pkt_buf_sz,
PCI_DMA_FROMDEVICE));
streamer_priv->rx_ring_skb[rx_ring_last_received] = skb;
writel(cpu_to_le32(pci_map_single(streamer_priv->pci_dev,
&streamer_priv->streamer_rx_ring[rx_ring_last_received],
sizeof(struct streamer_rx_desc), PCI_DMA_FROMDEVICE)),
streamer_mmio + RXLBDA);
netif_rx(skb2);
} else {
do {
pci_unmap_single(streamer_priv->pci_dev, le32_to_cpu(rx_desc->buffer), length, PCI_DMA_FROMDEVICE),
memcpy(skb_put(skb, length), (void *)rx_desc->buffer, length);
streamer_priv->streamer_rx_ring[rx_ring_last_received].status = 0;
streamer_priv->streamer_rx_ring[rx_ring_last_received].framelen_buflen = streamer_priv->pkt_buf_sz;
writel(cpu_to_le32(pci_map_single(streamer_priv->pci_dev,
&streamer_priv->streamer_rx_ring[rx_ring_last_received],
length, PCI_DMA_FROMDEVICE)),
streamer_mmio + RXLBDA);
if (rx_desc->status & 0x80000000)
break;
if (rx_ring_last_received!= streamer_priv->rx_ring_last_received)
{
printk("RX Error rx_ring_last_received not the same %x %x\n",
rx_ring_last_received,
streamer_priv->rx_ring_last_received);
}
rx_desc = &streamer_priv->streamer_rx_ring[(streamer_priv->rx_ring_last_received+1) & (STREAMER_RX_RING_SIZE-1)];
length = rx_desc->framelen_buflen & 0xffff;
streamer_priv->rx_ring_last_received = (streamer_priv->rx_ring_last_received+1) & (STREAMER_RX_RING_SIZE - 1);
rx_ring_last_received = streamer_priv->rx_ring_last_received;
} while (1);
skb->protocol = tr_type_trans(skb, dev);
netif_rx(skb);
}
dev->stats.rx_packets++;
dev->stats.rx_bytes += length;
}
}
rx_desc = &streamer_priv->streamer_rx_ring[(rx_ring_last_received + 1) & (STREAMER_RX_RING_SIZE - 1)];
}
}
static irqreturn_t streamer_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *) dev_id;
struct streamer_private *streamer_priv =
netdev_priv(dev);
__u8 __iomem *streamer_mmio = streamer_priv->streamer_mmio;
__u16 sisr;
__u16 misr;
u8 max_intr = MAX_INTR;
spin_lock(&streamer_priv->streamer_lock);
sisr = readw(streamer_mmio + SISR);
while((sisr & (SISR_MI | SISR_SRB_REPLY | SISR_ADAPTER_CHECK | SISR_ASB_FREE |
SISR_ARB_CMD | SISR_TRB_REPLY | SISR_PAR_ERR | SISR_SERR_ERR)) &&
(max_intr > 0)) {
if(sisr & SISR_PAR_ERR) {
writew(~SISR_PAR_ERR, streamer_mmio + SISR_RUM);
(void)readw(streamer_mmio + SISR_RUM);
}
else if(sisr & SISR_SERR_ERR) {
writew(~SISR_SERR_ERR, streamer_mmio + SISR_RUM);
(void)readw(streamer_mmio + SISR_RUM);
}
else if(sisr & SISR_MI) {
misr = readw(streamer_mmio + MISR_RUM);
if (misr & MISR_TX2_EOF) {
while(streamer_priv->streamer_tx_ring[(streamer_priv->tx_ring_last_status + 1) & (STREAMER_TX_RING_SIZE - 1)].status) {
streamer_priv->tx_ring_last_status = (streamer_priv->tx_ring_last_status + 1) & (STREAMER_TX_RING_SIZE - 1);
streamer_priv->free_tx_ring_entries++;
dev->stats.tx_bytes += streamer_priv->tx_ring_skb[streamer_priv->tx_ring_last_status]->len;
dev->stats.tx_packets++;
dev_kfree_skb_irq(streamer_priv->tx_ring_skb[streamer_priv->tx_ring_last_status]);
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_last_status].buffer = 0xdeadbeef;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_last_status].status = 0;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_last_status].bufcnt_framelen = 0;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_last_status].buflen = 0;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_last_status].rsvd1 = 0;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_last_status].rsvd2 = 0;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_last_status].rsvd3 = 0;
}
netif_wake_queue(dev);
}
if (misr & MISR_RX_EOF) {
streamer_rx(dev);
}
if (misr & MISR_RX_NOBUF) {
}
writew(~misr, streamer_mmio + MISR_RUM);
(void)readw(streamer_mmio + MISR_RUM);
}
else if (sisr & SISR_SRB_REPLY) {
if (streamer_priv->srb_queued == 1) {
wake_up_interruptible(&streamer_priv->srb_wait);
} else if (streamer_priv->srb_queued == 2) {
streamer_srb_bh(dev);
}
streamer_priv->srb_queued = 0;
writew(~SISR_SRB_REPLY, streamer_mmio + SISR_RUM);
(void)readw(streamer_mmio + SISR_RUM);
}
else if (sisr & SISR_ADAPTER_CHECK) {
printk(KERN_WARNING "%s: Adapter Check Interrupt Raised, 8 bytes of information follow:\n", dev->name);
writel(readl(streamer_mmio + LAPWWO), streamer_mmio + LAPA);
printk(KERN_WARNING "%s: Words %x:%x:%x:%x:\n",
dev->name, readw(streamer_mmio + LAPDINC),
ntohs(readw(streamer_mmio + LAPDINC)),
ntohs(readw(streamer_mmio + LAPDINC)),
ntohs(readw(streamer_mmio + LAPDINC)));
netif_stop_queue(dev);
netif_carrier_off(dev);
printk(KERN_WARNING "%s: Adapter must be manually reset.\n", dev->name);
}
else if (sisr & SISR_ASB_FREE) {
if (streamer_priv->asb_queued) {
streamer_asb_bh(dev);
}
writew(~SISR_ASB_FREE, streamer_mmio + SISR_RUM);
(void)readw(streamer_mmio + SISR_RUM);
}
else if (sisr & SISR_ARB_CMD) {
streamer_arb_cmd(dev);
writew(~SISR_ARB_CMD, streamer_mmio + SISR_RUM);
(void)readw(streamer_mmio + SISR_RUM);
}
else if (sisr & SISR_TRB_REPLY) {
if (streamer_priv->trb_queued) {
wake_up_interruptible(&streamer_priv->
trb_wait);
}
streamer_priv->trb_queued = 0;
writew(~SISR_TRB_REPLY, streamer_mmio + SISR_RUM);
(void)readw(streamer_mmio + SISR_RUM);
}
sisr = readw(streamer_mmio + SISR);
max_intr--;
}
spin_unlock(&streamer_priv->streamer_lock) ;
return IRQ_HANDLED;
}
static netdev_tx_t streamer_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct streamer_private *streamer_priv =
netdev_priv(dev);
__u8 __iomem *streamer_mmio = streamer_priv->streamer_mmio;
unsigned long flags ;
spin_lock_irqsave(&streamer_priv->streamer_lock, flags);
if (streamer_priv->free_tx_ring_entries) {
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_free].status = 0;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_free].bufcnt_framelen = 0x00020000 | skb->len;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_free].buffer =
cpu_to_le32(pci_map_single(streamer_priv->pci_dev, skb->data, skb->len, PCI_DMA_TODEVICE));
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_free].rsvd1 = skb->len;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_free].rsvd2 = 0;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_free].rsvd3 = 0;
streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_free].buflen = skb->len;
streamer_priv->tx_ring_skb[streamer_priv->tx_ring_free] = skb;
streamer_priv->free_tx_ring_entries--;
#if STREAMER_DEBUG_PACKETS
{
int i;
printk("streamer_xmit packet print:\n");
for (i = 0; i < skb->len; i++) {
printk("%x:", skb->data[i]);
if (((i + 1) % 16) == 0)
printk("\n");
}
printk("\n");
}
#endif
writel(cpu_to_le32(pci_map_single(streamer_priv->pci_dev,
&streamer_priv->streamer_tx_ring[streamer_priv->tx_ring_free],
sizeof(struct streamer_tx_desc), PCI_DMA_TODEVICE)),
streamer_mmio + TX2LFDA);
(void)readl(streamer_mmio + TX2LFDA);
streamer_priv->tx_ring_free = (streamer_priv->tx_ring_free + 1) & (STREAMER_TX_RING_SIZE - 1);
spin_unlock_irqrestore(&streamer_priv->streamer_lock,flags);
return NETDEV_TX_OK;
} else {
netif_stop_queue(dev);
spin_unlock_irqrestore(&streamer_priv->streamer_lock,flags);
return NETDEV_TX_BUSY;
}
}
static int streamer_close(struct net_device *dev)
{
struct streamer_private *streamer_priv =
netdev_priv(dev);
__u8 __iomem *streamer_mmio = streamer_priv->streamer_mmio;
unsigned long flags;
int i;
netif_stop_queue(dev);
netif_carrier_off(dev);
writew(streamer_priv->srb, streamer_mmio + LAPA);
writew(htons(SRB_CLOSE_ADAPTER << 8),streamer_mmio+LAPDINC);
writew(htons(STREAMER_CLEAR_RET_CODE << 8), streamer_mmio+LAPDINC);
spin_lock_irqsave(&streamer_priv->streamer_lock, flags);
streamer_priv->srb_queued = 1;
writew(LISR_SRB_CMD, streamer_mmio + LISR_SUM);
spin_unlock_irqrestore(&streamer_priv->streamer_lock, flags);
while (streamer_priv->srb_queued)
{
interruptible_sleep_on_timeout(&streamer_priv->srb_wait,
jiffies + 60 * HZ);
if (signal_pending(current))
{
printk(KERN_WARNING "%s: SRB timed out.\n", dev->name);
printk(KERN_WARNING "SISR=%x MISR=%x LISR=%x\n",
readw(streamer_mmio + SISR),
readw(streamer_mmio + MISR_RUM),
readw(streamer_mmio + LISR));
streamer_priv->srb_queued = 0;
break;
}
}
streamer_priv->rx_ring_last_received = (streamer_priv->rx_ring_last_received + 1) & (STREAMER_RX_RING_SIZE - 1);
for (i = 0; i < STREAMER_RX_RING_SIZE; i++) {
if (streamer_priv->rx_ring_skb[streamer_priv->rx_ring_last_received]) {
dev_kfree_skb(streamer_priv->rx_ring_skb[streamer_priv->rx_ring_last_received]);
}
streamer_priv->rx_ring_last_received = (streamer_priv->rx_ring_last_received + 1) & (STREAMER_RX_RING_SIZE - 1);
}
#if STREAMER_DEBUG
writew(streamer_priv->srb, streamer_mmio + LAPA);
printk("srb): ");
for (i = 0; i < 2; i++) {
printk("%x ", ntohs(readw(streamer_mmio + LAPDINC)));
}
printk("\n");
#endif
free_irq(dev->irq, dev);
return 0;
}
static void streamer_set_rx_mode(struct net_device *dev)
{
struct streamer_private *streamer_priv =
netdev_priv(dev);
__u8 __iomem *streamer_mmio = streamer_priv->streamer_mmio;
__u8 options = 0;
struct netdev_hw_addr *ha;
unsigned char dev_mc_address[5];
writel(streamer_priv->srb, streamer_mmio + LAPA);
options = streamer_priv->streamer_copy_all_options;
if (dev->flags & IFF_PROMISC)
options |= (3 << 5);
else
options &= ~(3 << 5);
if ((options ^ streamer_priv->streamer_copy_all_options))
{
writew(htons(SRB_MODIFY_RECEIVE_OPTIONS << 8), streamer_mmio+LAPDINC);
writew(htons(STREAMER_CLEAR_RET_CODE << 8), streamer_mmio+LAPDINC);
writew(htons((streamer_priv->streamer_receive_options << 8) | options),streamer_mmio+LAPDINC);
writew(htons(0x4a41),streamer_mmio+LAPDINC);
writew(htons(0x4d45),streamer_mmio+LAPDINC);
writew(htons(0x5320),streamer_mmio+LAPDINC);
writew(0x2020, streamer_mmio + LAPDINC);
streamer_priv->srb_queued = 2;
writel(LISR_SRB_CMD, streamer_mmio + LISR_SUM);
streamer_priv->streamer_copy_all_options = options;
return;
}
writel(streamer_priv->srb,streamer_mmio+LAPA);
dev_mc_address[0] = dev_mc_address[1] = dev_mc_address[2] = dev_mc_address[3] = 0 ;
netdev_for_each_mc_addr(ha, dev) {
dev_mc_address[0] |= ha->addr[2];
dev_mc_address[1] |= ha->addr[3];
dev_mc_address[2] |= ha->addr[4];
dev_mc_address[3] |= ha->addr[5];
}
writew(htons(SRB_SET_FUNC_ADDRESS << 8),streamer_mmio+LAPDINC);
writew(htons(STREAMER_CLEAR_RET_CODE << 8), streamer_mmio+LAPDINC);
writew(0,streamer_mmio+LAPDINC);
writew(htons( (dev_mc_address[0] << 8) | dev_mc_address[1]),streamer_mmio+LAPDINC);
writew(htons( (dev_mc_address[2] << 8) | dev_mc_address[3]),streamer_mmio+LAPDINC);
streamer_priv->srb_queued = 2 ;
writel(LISR_SRB_CMD,streamer_mmio+LISR_SUM);
}
static void streamer_srb_bh(struct net_device *dev)
{
struct streamer_private *streamer_priv = netdev_priv(dev);
__u8 __iomem *streamer_mmio = streamer_priv->streamer_mmio;
__u16 srb_word;
writew(streamer_priv->srb, streamer_mmio + LAPA);
srb_word=ntohs(readw(streamer_mmio+LAPDINC)) >> 8;
switch (srb_word) {
case SRB_MODIFY_RECEIVE_OPTIONS:
srb_word=ntohs(readw(streamer_mmio+LAPDINC)) >> 8;
switch (srb_word) {
case 0x01:
printk(KERN_WARNING "%s: Unrecognized srb command\n", dev->name);
break;
case 0x04:
printk(KERN_WARNING "%s: Adapter must be open for this operation, doh!!\n", dev->name);
break;
default:
if (streamer_priv->streamer_message_level)
printk(KERN_WARNING "%s: Receive Options Modified to %x,%x\n",
dev->name,
streamer_priv->streamer_copy_all_options,
streamer_priv->streamer_receive_options);
break;
}
break;
case SRB_SET_GROUP_ADDRESS:
srb_word=ntohs(readw(streamer_mmio+LAPDINC)) >> 8;
switch (srb_word) {
case 0x00:
break;
case 0x01:
printk(KERN_WARNING "%s: Unrecognized srb command\n",dev->name);
break;
case 0x04:
printk(KERN_WARNING "%s: Adapter must be open for this operation, doh!!\n", dev->name);
break;
case 0x3c:
printk(KERN_WARNING "%s: Group/Functional address indicator bits not set correctly\n", dev->name);
break;
case 0x3e:
printk(KERN_WARNING "%s: Group address registers full\n", dev->name);
break;
case 0x55:
printk(KERN_INFO "%s: Group Address already set.\n", dev->name);
break;
default:
break;
}
break;
case SRB_RESET_GROUP_ADDRESS:
srb_word=ntohs(readw(streamer_mmio+LAPDINC)) >> 8;
switch (srb_word) {
case 0x00:
break;
case 0x01:
printk(KERN_WARNING "%s: Unrecognized srb command\n", dev->name);
break;
case 0x04:
printk(KERN_WARNING "%s: Adapter must be open for this operation, doh!!\n", dev->name);
break;
case 0x39:
printk(KERN_INFO "%s: Group address not found\n", dev->name);
break;
default:
break;
}
break;
case SRB_SET_FUNC_ADDRESS:
srb_word=ntohs(readw(streamer_mmio+LAPDINC)) >> 8;
switch (srb_word) {
case 0x00:
if (streamer_priv->streamer_message_level)
printk(KERN_INFO "%s: Functional Address Mask Set\n", dev->name);
break;
case 0x01:
printk(KERN_WARNING "%s: Unrecognized srb command\n", dev->name);
break;
case 0x04:
printk(KERN_WARNING "%s: Adapter must be open for this operation, doh!!\n", dev->name);
break;
default:
break;
}
break;
case SRB_READ_LOG:
srb_word=ntohs(readw(streamer_mmio+LAPDINC)) >> 8;
switch (srb_word) {
case 0x00:
{
int i;
if (streamer_priv->streamer_message_level)
printk(KERN_INFO "%s: Read Log command complete\n", dev->name);
printk("Read Log statistics: ");
writew(streamer_priv->srb + 6,
streamer_mmio + LAPA);
for (i = 0; i < 5; i++) {
printk("%x:", ntohs(readw(streamer_mmio + LAPDINC)));
}
printk("\n");
}
break;
case 0x01:
printk(KERN_WARNING "%s: Unrecognized srb command\n", dev->name);
break;
case 0x04:
printk(KERN_WARNING "%s: Adapter must be open for this operation, doh!!\n", dev->name);
break;
}
break;
case SRB_READ_SR_COUNTERS:
srb_word=ntohs(readw(streamer_mmio+LAPDINC)) >> 8;
switch (srb_word) {
case 0x00:
if (streamer_priv->streamer_message_level)
printk(KERN_INFO "%s: Read Source Routing Counters issued\n", dev->name);
break;
case 0x01:
printk(KERN_WARNING "%s: Unrecognized srb command\n", dev->name);
break;
case 0x04:
printk(KERN_WARNING "%s: Adapter must be open for this operation, doh!!\n", dev->name);
break;
default:
break;
}
break;
default:
printk(KERN_WARNING "%s: Unrecognized srb bh return value.\n", dev->name);
break;
}
}
static int streamer_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr *saddr = addr;
struct streamer_private *streamer_priv = netdev_priv(dev);
if (netif_running(dev))
{
printk(KERN_WARNING "%s: Cannot set mac/laa address while card is open\n", dev->name);
return -EIO;
}
memcpy(streamer_priv->streamer_laa, saddr->sa_data, dev->addr_len);
if (streamer_priv->streamer_message_level) {
printk(KERN_INFO "%s: MAC/LAA Set to = %x.%x.%x.%x.%x.%x\n",
dev->name, streamer_priv->streamer_laa[0],
streamer_priv->streamer_laa[1],
streamer_priv->streamer_laa[2],
streamer_priv->streamer_laa[3],
streamer_priv->streamer_laa[4],
streamer_priv->streamer_laa[5]);
}
return 0;
}
static void streamer_arb_cmd(struct net_device *dev)
{
struct streamer_private *streamer_priv =
netdev_priv(dev);
__u8 __iomem *streamer_mmio = streamer_priv->streamer_mmio;
__u8 header_len;
__u16 frame_len, buffer_len;
struct sk_buff *mac_frame;
__u8 frame_data[256];
__u16 buff_off;
__u16 lan_status = 0, lan_status_diff;
__u8 fdx_prot_error;
__u16 next_ptr;
__u16 arb_word;
#if STREAMER_NETWORK_MONITOR
struct trh_hdr *mac_hdr;
#endif
writew(streamer_priv->arb, streamer_mmio + LAPA);
arb_word=ntohs(readw(streamer_mmio+LAPD)) >> 8;
if (arb_word == ARB_RECEIVE_DATA) {
writew(streamer_priv->arb + 6, streamer_mmio + LAPA);
streamer_priv->mac_rx_buffer = buff_off = ntohs(readw(streamer_mmio + LAPDINC));
header_len=ntohs(readw(streamer_mmio+LAPDINC)) >> 8;
frame_len = ntohs(readw(streamer_mmio + LAPDINC));
#if STREAMER_DEBUG
{
int i;
__u16 next;
__u8 status;
__u16 len;
writew(ntohs(buff_off), streamer_mmio + LAPA);
next = htons(readw(streamer_mmio + LAPDINC));
status =
ntohs(readw(streamer_mmio + LAPDINC)) & 0xff;
len = ntohs(readw(streamer_mmio + LAPDINC));
for (i = 0; i < 7; i++) {
printk("Loc %d = %04x\n", i,
ntohs(readw
(streamer_mmio + LAPDINC)));
}
printk("next %04x, fs %02x, len %04x\n", next,
status, len);
}
#endif
if (!(mac_frame = dev_alloc_skb(frame_len))) {
printk(KERN_WARNING "%s: Memory squeeze, dropping frame.\n",
dev->name);
goto drop_frame;
}
do {
int i;
__u16 rx_word;
writew(htons(buff_off), streamer_mmio + LAPA);
next_ptr = ntohs(readw(streamer_mmio + LAPDINC));
readw(streamer_mmio + LAPDINC);
buffer_len = ntohs(readw(streamer_mmio + LAPDINC));
if (buffer_len > 256)
break;
i = 0;
while (i < buffer_len) {
rx_word=ntohs(readw(streamer_mmio+LAPDINC));
frame_data[i]=rx_word >> 8;
frame_data[i+1]=rx_word & 0xff;
i += 2;
}
memcpy(skb_put(mac_frame, buffer_len),
frame_data, buffer_len);
} while (next_ptr && (buff_off = next_ptr));
mac_frame->protocol = tr_type_trans(mac_frame, dev);
#if STREAMER_NETWORK_MONITOR
printk(KERN_WARNING "%s: Received MAC Frame, details:\n",
dev->name);
mac_hdr = tr_hdr(mac_frame);
printk(KERN_WARNING
"%s: MAC Frame Dest. Addr: %pM\n",
dev->name, mac_hdr->daddr);
printk(KERN_WARNING
"%s: MAC Frame Srce. Addr: %pM\n",
dev->name, mac_hdr->saddr);
#endif
netif_rx(mac_frame);
drop_frame:
writel(LISR_ARB_FREE, streamer_priv->streamer_mmio + LISR_SUM);
if (!(readl(streamer_priv->streamer_mmio + SISR) & SISR_ASB_FREE))
{
streamer_priv->asb_queued = 1;
writel(LISR_ASB_FREE_REQ, streamer_priv->streamer_mmio + LISR_SUM);
return;
}
writew(streamer_priv->asb, streamer_mmio + LAPA);
writew(htons(ASB_RECEIVE_DATA << 8), streamer_mmio+LAPDINC);
writew(htons(STREAMER_CLEAR_RET_CODE << 8), streamer_mmio+LAPDINC);
writew(0, streamer_mmio + LAPDINC);
writew(htons(streamer_priv->mac_rx_buffer), streamer_mmio + LAPD);
writel(LISR_ASB_REPLY | LISR_ASB_FREE_REQ, streamer_priv->streamer_mmio + LISR_SUM);
streamer_priv->asb_queued = 2;
return;
} else if (arb_word == ARB_LAN_CHANGE_STATUS) {
writew(streamer_priv->arb + 6, streamer_mmio + LAPA);
lan_status = ntohs(readw(streamer_mmio + LAPDINC));
fdx_prot_error = ntohs(readw(streamer_mmio+LAPD)) >> 8;
writew(LISR_ARB_FREE, streamer_priv->streamer_mmio + LISR_SUM);
lan_status_diff = (streamer_priv->streamer_lan_status ^ lan_status) &
lan_status;
if (lan_status_diff & (LSC_LWF | LSC_ARW | LSC_FPE | LSC_RR))
{
if (lan_status_diff & LSC_LWF)
printk(KERN_WARNING "%s: Short circuit detected on the lobe\n", dev->name);
if (lan_status_diff & LSC_ARW)
printk(KERN_WARNING "%s: Auto removal error\n", dev->name);
if (lan_status_diff & LSC_FPE)
printk(KERN_WARNING "%s: FDX Protocol Error\n", dev->name);
if (lan_status_diff & LSC_RR)
printk(KERN_WARNING "%s: Force remove MAC frame received\n", dev->name);
netif_stop_queue(dev);
netif_carrier_off(dev);
printk(KERN_WARNING "%s: Adapter must be manually reset.\n", dev->name);
}
if (streamer_priv->streamer_message_level) {
if (lan_status_diff & LSC_SIG_LOSS)
printk(KERN_WARNING "%s: No receive signal detected\n", dev->name);
if (lan_status_diff & LSC_HARD_ERR)
printk(KERN_INFO "%s: Beaconing\n", dev->name);
if (lan_status_diff & LSC_SOFT_ERR)
printk(KERN_WARNING "%s: Adapter transmitted Soft Error Report Mac Frame\n", dev->name);
if (lan_status_diff & LSC_TRAN_BCN)
printk(KERN_INFO "%s: We are transmitting the beacon, aaah\n", dev->name);
if (lan_status_diff & LSC_SS)
printk(KERN_INFO "%s: Single Station on the ring\n", dev->name);
if (lan_status_diff & LSC_RING_REC)
printk(KERN_INFO "%s: Ring recovery ongoing\n", dev->name);
if (lan_status_diff & LSC_FDX_MODE)
printk(KERN_INFO "%s: Operating in FDX mode\n", dev->name);
}
if (lan_status_diff & LSC_CO) {
if (streamer_priv->streamer_message_level)
printk(KERN_INFO "%s: Counter Overflow\n", dev->name);
writew(streamer_priv->srb, streamer_mmio + LAPA);
writew(htons(SRB_READ_LOG << 8),streamer_mmio+LAPDINC);
writew(htons(STREAMER_CLEAR_RET_CODE << 8), streamer_mmio+LAPDINC);
writew(0, streamer_mmio + LAPDINC);
streamer_priv->srb_queued = 2;
writew(LISR_SRB_CMD, streamer_mmio + LISR_SUM);
}
if (lan_status_diff & LSC_SR_CO) {
if (streamer_priv->streamer_message_level)
printk(KERN_INFO "%s: Source routing counters overflow\n", dev->name);
writew(streamer_priv->srb, streamer_mmio + LAPA);
writew(htons(SRB_READ_SR_COUNTERS << 8),
streamer_mmio+LAPDINC);
writew(htons(STREAMER_CLEAR_RET_CODE << 8),
streamer_mmio+LAPDINC);
streamer_priv->srb_queued = 2;
writew(LISR_SRB_CMD, streamer_mmio + LISR_SUM);
}
streamer_priv->streamer_lan_status = lan_status;
}
else
printk(KERN_WARNING "%s: Unknown arb command\n", dev->name);
}
static void streamer_asb_bh(struct net_device *dev)
{
struct streamer_private *streamer_priv =
netdev_priv(dev);
__u8 __iomem *streamer_mmio = streamer_priv->streamer_mmio;
if (streamer_priv->asb_queued == 1)
{
writew(streamer_priv->asb, streamer_mmio + LAPA);
writew(htons(ASB_RECEIVE_DATA << 8),streamer_mmio+LAPDINC);
writew(htons(STREAMER_CLEAR_RET_CODE << 8), streamer_mmio+LAPDINC);
writew(0, streamer_mmio + LAPDINC);
writew(htons(streamer_priv->mac_rx_buffer), streamer_mmio + LAPD);
writel(LISR_ASB_REPLY | LISR_ASB_FREE_REQ, streamer_priv->streamer_mmio + LISR_SUM);
streamer_priv->asb_queued = 2;
return;
}
if (streamer_priv->asb_queued == 2) {
__u8 rc;
writew(streamer_priv->asb + 2, streamer_mmio + LAPA);
rc=ntohs(readw(streamer_mmio+LAPD)) >> 8;
switch (rc) {
case 0x01:
printk(KERN_WARNING "%s: Unrecognized command code\n", dev->name);
break;
case 0x26:
printk(KERN_WARNING "%s: Unrecognized buffer address\n", dev->name);
break;
case 0xFF:
break;
default:
printk(KERN_WARNING "%s: Invalid return code in asb\n", dev->name);
break;
}
}
streamer_priv->asb_queued = 0;
}
static int streamer_change_mtu(struct net_device *dev, int mtu)
{
struct streamer_private *streamer_priv =
netdev_priv(dev);
__u16 max_mtu;
if (streamer_priv->streamer_ring_speed == 4)
max_mtu = 4500;
else
max_mtu = 18000;
if (mtu > max_mtu)
return -EINVAL;
if (mtu < 100)
return -EINVAL;
dev->mtu = mtu;
streamer_priv->pkt_buf_sz = mtu + TR_HLEN;
return 0;
}
static int streamer_proc_info(char *buffer, char **start, off_t offset,
int length, int *eof, void *data)
{
struct streamer_private *sdev=NULL;
struct pci_dev *pci_device = NULL;
int len = 0;
off_t begin = 0;
off_t pos = 0;
int size;
struct net_device *dev;
size = sprintf(buffer, "IBM LanStreamer/MPC Chipset Token Ring Adapters\n");
pos += size;
len += size;
for(sdev=dev_streamer; sdev; sdev=sdev->next) {
pci_device=sdev->pci_dev;
dev=pci_get_drvdata(pci_device);
size = sprintf_info(buffer + len, dev);
len += size;
pos = begin + len;
if (pos < offset) {
len = 0;
begin = pos;
}
if (pos > offset + length)
break;
}
*start = buffer + (offset - begin);
len -= (offset - begin);
if (len > length)
len = length;
return len;
}
static int sprintf_info(char *buffer, struct net_device *dev)
{
struct streamer_private *streamer_priv =
netdev_priv(dev);
__u8 __iomem *streamer_mmio = streamer_priv->streamer_mmio;
struct streamer_adapter_addr_table sat;
struct streamer_parameters_table spt;
int size = 0;
int i;
writew(streamer_priv->streamer_addr_table_addr, streamer_mmio + LAPA);
for (i = 0; i < 14; i += 2) {
__u16 io_word;
__u8 *datap = (__u8 *) & sat;
io_word=ntohs(readw(streamer_mmio+LAPDINC));
datap[size]=io_word >> 8;
datap[size+1]=io_word & 0xff;
}
writew(streamer_priv->streamer_parms_addr, streamer_mmio + LAPA);
for (i = 0; i < 68; i += 2) {
__u16 io_word;
__u8 *datap = (__u8 *) & spt;
io_word=ntohs(readw(streamer_mmio+LAPDINC));
datap[size]=io_word >> 8;
datap[size+1]=io_word & 0xff;
}
size = sprintf(buffer, "\n%6s: Adapter Address : Node Address : Functional Addr\n", dev->name);
size += sprintf(buffer + size,
"%6s: %pM : %pM : %02x:%02x:%02x:%02x\n",
dev->name, dev->dev_addr, sat.node_addr,
sat.func_addr[0], sat.func_addr[1],
sat.func_addr[2], sat.func_addr[3]);
size += sprintf(buffer + size, "\n%6s: Token Ring Parameters Table:\n", dev->name);
size += sprintf(buffer + size, "%6s: Physical Addr : Up Node Address : Poll Address : AccPri : Auth Src : Att Code :\n", dev->name);
size += sprintf(buffer + size,
"%6s: %02x:%02x:%02x:%02x : %pM : %pM : %04x : %04x : %04x :\n",
dev->name, spt.phys_addr[0], spt.phys_addr[1],
spt.phys_addr[2], spt.phys_addr[3],
spt.up_node_addr, spt.poll_addr,
ntohs(spt.acc_priority), ntohs(spt.auth_source_class),
ntohs(spt.att_code));
size += sprintf(buffer + size, "%6s: Source Address : Bcn T : Maj. V : Lan St : Lcl Rg : Mon Err : Frame Correl : \n", dev->name);
size += sprintf(buffer + size,
"%6s: %pM : %04x : %04x : %04x : %04x : %04x : %04x : \n",
dev->name, spt.source_addr,
ntohs(spt.beacon_type), ntohs(spt.major_vector),
ntohs(spt.lan_status), ntohs(spt.local_ring),
ntohs(spt.mon_error), ntohs(spt.frame_correl));
size += sprintf(buffer + size, "%6s: Beacon Details : Tx : Rx : NAUN Node Address : NAUN Node Phys : \n",
dev->name);
size += sprintf(buffer + size,
"%6s: : %02x : %02x : %pM : %02x:%02x:%02x:%02x : \n",
dev->name, ntohs(spt.beacon_transmit),
ntohs(spt.beacon_receive),
spt.beacon_naun,
spt.beacon_phys[0], spt.beacon_phys[1],
spt.beacon_phys[2], spt.beacon_phys[3]);
return size;
}
static int __init streamer_init_module(void) {
return pci_register_driver(&streamer_pci_driver);
}
static void __exit streamer_cleanup_module(void) {
pci_unregister_driver(&streamer_pci_driver);
}
