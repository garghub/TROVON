static void print_binary(unsigned int number)
{
int i,i2;
char buffer[64];
memset(buffer,0,64);
i2=0;
for (i=31;i>=0;i--) {
if (number & (1<<i))
buffer[i2++]='1';
else
buffer[i2++]='0';
if ((i&3)==0)
buffer[i2++]=' ';
}
pr_debug("%s\n",buffer);
}
static int xircom_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct device *d = &pdev->dev;
struct net_device *dev = NULL;
struct xircom_private *private;
unsigned long flags;
unsigned short tmp16;
int rc;
rc = pci_enable_device(pdev);
if (rc < 0)
goto out;
pci_write_config_dword(pdev, PCI_POWERMGMT, 0x0000);
pci_set_master(pdev);
pci_read_config_word (pdev,PCI_STATUS, &tmp16);
pci_write_config_word (pdev, PCI_STATUS,tmp16);
rc = pci_request_regions(pdev, "xircom_cb");
if (rc < 0) {
pr_err("%s: failed to allocate io-region\n", __func__);
goto err_disable;
}
rc = -ENOMEM;
dev = alloc_etherdev(sizeof(struct xircom_private));
if (!dev)
goto err_release;
private = netdev_priv(dev);
private->rx_buffer = dma_alloc_coherent(d, 8192,
&private->rx_dma_handle,
GFP_KERNEL);
if (private->rx_buffer == NULL)
goto rx_buf_fail;
private->tx_buffer = dma_alloc_coherent(d, 8192,
&private->tx_dma_handle,
GFP_KERNEL);
if (private->tx_buffer == NULL)
goto tx_buf_fail;
SET_NETDEV_DEV(dev, &pdev->dev);
private->dev = dev;
private->pdev = pdev;
private->ioaddr = pci_iomap(pdev, 0, 0);
if (!private->ioaddr)
goto reg_fail;
spin_lock_init(&private->lock);
initialize_card(private);
read_mac_address(private);
setup_descriptors(private);
dev->netdev_ops = &netdev_ops;
pci_set_drvdata(pdev, dev);
rc = register_netdev(dev);
if (rc < 0) {
pr_err("%s: netdevice registration failed\n", __func__);
goto err_unmap;
}
netdev_info(dev, "Xircom cardbus revision %i at irq %i\n",
pdev->revision, pdev->irq);
transceiver_voodoo(private);
spin_lock_irqsave(&private->lock,flags);
activate_transmitter(private);
activate_receiver(private);
spin_unlock_irqrestore(&private->lock,flags);
trigger_receive(private);
out:
return rc;
err_unmap:
pci_iounmap(pdev, private->ioaddr);
reg_fail:
pci_set_drvdata(pdev, NULL);
dma_free_coherent(d, 8192, private->tx_buffer, private->tx_dma_handle);
tx_buf_fail:
dma_free_coherent(d, 8192, private->rx_buffer, private->rx_dma_handle);
rx_buf_fail:
free_netdev(dev);
err_release:
pci_release_regions(pdev);
err_disable:
pci_disable_device(pdev);
goto out;
}
static void xircom_remove(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct xircom_private *card = netdev_priv(dev);
struct device *d = &pdev->dev;
unregister_netdev(dev);
pci_iounmap(pdev, card->ioaddr);
pci_set_drvdata(pdev, NULL);
dma_free_coherent(d, 8192, card->tx_buffer, card->tx_dma_handle);
dma_free_coherent(d, 8192, card->rx_buffer, card->rx_dma_handle);
free_netdev(dev);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static irqreturn_t xircom_interrupt(int irq, void *dev_instance)
{
struct net_device *dev = (struct net_device *) dev_instance;
struct xircom_private *card = netdev_priv(dev);
void __iomem *ioaddr = card->ioaddr;
unsigned int status;
int i;
spin_lock(&card->lock);
status = xr32(CSR5);
#if defined DEBUG && DEBUG > 1
print_binary(status);
pr_debug("tx status 0x%08x 0x%08x\n",
card->tx_buffer[0], card->tx_buffer[4]);
pr_debug("rx status 0x%08x 0x%08x\n",
card->rx_buffer[0], card->rx_buffer[4]);
#endif
if (status == 0 || status == 0xffffffff) {
spin_unlock(&card->lock);
return IRQ_NONE;
}
if (link_status_changed(card)) {
int newlink;
netdev_dbg(dev, "Link status has changed\n");
newlink = link_status(card);
netdev_info(dev, "Link is %d mbit\n", newlink);
if (newlink)
netif_carrier_on(dev);
else
netif_carrier_off(dev);
}
status |= 0xffffffff;
xw32(CSR5, status);
for (i=0;i<NUMDESCRIPTORS;i++)
investigate_write_descriptor(dev,card,i,bufferoffsets[i]);
for (i=0;i<NUMDESCRIPTORS;i++)
investigate_read_descriptor(dev,card,i,bufferoffsets[i]);
spin_unlock(&card->lock);
return IRQ_HANDLED;
}
static netdev_tx_t xircom_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct xircom_private *card;
unsigned long flags;
int nextdescriptor;
int desc;
card = netdev_priv(dev);
spin_lock_irqsave(&card->lock,flags);
for (desc=0;desc<NUMDESCRIPTORS;desc++)
investigate_write_descriptor(dev,card,desc,bufferoffsets[desc]);
nextdescriptor = (card->transmit_used +1) % (NUMDESCRIPTORS);
desc = card->transmit_used;
if (card->tx_buffer[4*desc]==0) {
memset(&card->tx_buffer[bufferoffsets[desc]/4],0,1536);
skb_copy_from_linear_data(skb,
&(card->tx_buffer[bufferoffsets[desc] / 4]),
skb->len);
card->tx_buffer[4*desc+1] = cpu_to_le32(skb->len);
if (desc == NUMDESCRIPTORS - 1)
card->tx_buffer[4*desc+1] |= cpu_to_le32(1<<25);
card->tx_buffer[4*desc+1] |= cpu_to_le32(0xF0000000);
card->tx_skb[desc] = skb;
wmb();
card->tx_buffer[4*desc] = cpu_to_le32(0x80000000);
trigger_transmit(card);
if (card->tx_buffer[nextdescriptor*4] & cpu_to_le32(0x8000000)) {
netif_stop_queue(dev);
}
card->transmit_used = nextdescriptor;
spin_unlock_irqrestore(&card->lock,flags);
return NETDEV_TX_OK;
}
netif_stop_queue(dev);
spin_unlock_irqrestore(&card->lock,flags);
trigger_transmit(card);
return NETDEV_TX_BUSY;
}
static int xircom_open(struct net_device *dev)
{
struct xircom_private *xp = netdev_priv(dev);
const int irq = xp->pdev->irq;
int retval;
netdev_info(dev, "xircom cardbus adaptor found, using irq %i\n", irq);
retval = request_irq(irq, xircom_interrupt, IRQF_SHARED, dev->name, dev);
if (retval)
return retval;
xircom_up(xp);
xp->open = 1;
return 0;
}
static int xircom_close(struct net_device *dev)
{
struct xircom_private *card;
unsigned long flags;
card = netdev_priv(dev);
netif_stop_queue(dev);
spin_lock_irqsave(&card->lock,flags);
disable_all_interrupts(card);
#if 0
deactivate_receiver(card);
deactivate_transmitter(card);
#endif
remove_descriptors(card);
spin_unlock_irqrestore(&card->lock,flags);
card->open = 0;
free_irq(card->pdev->irq, dev);
return 0;
}
static void xircom_poll_controller(struct net_device *dev)
{
struct xircom_private *xp = netdev_priv(dev);
const int irq = xp->pdev->irq;
disable_irq(irq);
xircom_interrupt(irq, dev);
enable_irq(irq);
}
static void initialize_card(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned long flags;
u32 val;
spin_lock_irqsave(&card->lock, flags);
val = xr32(CSR0);
val |= 0x01;
xw32(CSR0, val);
udelay(100);
val = xr32(CSR0);
val &= ~0x01;
xw32(CSR0, val);
val = 0;
xw32(CSR0, val);
disable_all_interrupts(card);
deactivate_receiver(card);
deactivate_transmitter(card);
spin_unlock_irqrestore(&card->lock, flags);
}
static void trigger_transmit(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
xw32(CSR1, 0);
}
static void trigger_receive(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
xw32(CSR2, 0);
}
static void setup_descriptors(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
u32 address;
int i;
BUG_ON(card->rx_buffer == NULL);
BUG_ON(card->tx_buffer == NULL);
memset(card->rx_buffer, 0, 128);
for (i=0;i<NUMDESCRIPTORS;i++ ) {
card->rx_buffer[i*4 + 0] = cpu_to_le32(0x80000000);
card->rx_buffer[i*4 + 1] = cpu_to_le32(1536);
if (i == NUMDESCRIPTORS - 1)
card->rx_buffer[i*4 + 1] |= cpu_to_le32(1 << 25);
address = card->rx_dma_handle;
card->rx_buffer[i*4 + 2] = cpu_to_le32(address + bufferoffsets[i]);
card->rx_buffer[i*4 + 3] = 0;
}
wmb();
address = card->rx_dma_handle;
xw32(CSR3, address);
memset(card->tx_buffer, 0, 128);
for (i=0;i<NUMDESCRIPTORS;i++ ) {
card->tx_buffer[i*4 + 0] = 0x00000000;
card->tx_buffer[i*4 + 1] = cpu_to_le32(1536);
if (i == NUMDESCRIPTORS - 1)
card->tx_buffer[i*4 + 1] |= cpu_to_le32(1 << 25);
address = card->tx_dma_handle;
card->tx_buffer[i*4 + 2] = cpu_to_le32(address + bufferoffsets[i]);
card->tx_buffer[i*4 + 3] = 0;
}
wmb();
address = card->tx_dma_handle;
xw32(CSR4, address);
}
static void remove_descriptors(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
val = 0;
xw32(CSR3, val);
xw32(CSR4, val);
}
static int link_status_changed(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
val = xr32(CSR5);
if (!(val & (1 << 27)))
return 0;
val = (1 << 27);
xw32(CSR5, val);
return 1;
}
static int transmit_active(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
if (!(xr32(CSR5) & (7 << 20)))
return 0;
return 1;
}
static int receive_active(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
if (!(xr32(CSR5) & (7 << 17)))
return 0;
return 1;
}
static void activate_receiver(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
int counter;
val = xr32(CSR6);
if ((val&2) && (receive_active(card)))
return;
val = val & ~2;
xw32(CSR6, val);
counter = 10;
while (counter > 0) {
if (!receive_active(card))
break;
udelay(50);
counter--;
if (counter <= 0)
netdev_err(card->dev, "Receiver failed to deactivate\n");
}
val = xr32(CSR6);
val = val | 2;
xw32(CSR6, val);
counter = 10;
while (counter > 0) {
if (receive_active(card))
break;
udelay(50);
counter--;
if (counter <= 0)
netdev_err(card->dev,
"Receiver failed to re-activate\n");
}
}
static void deactivate_receiver(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
int counter;
val = xr32(CSR6);
val = val & ~2;
xw32(CSR6, val);
counter = 10;
while (counter > 0) {
if (!receive_active(card))
break;
udelay(50);
counter--;
if (counter <= 0)
netdev_err(card->dev, "Receiver failed to deactivate\n");
}
}
static void activate_transmitter(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
int counter;
val = xr32(CSR6);
if ((val&(1<<13)) && (transmit_active(card)))
return;
val = val & ~(1 << 13);
xw32(CSR6, val);
counter = 10;
while (counter > 0) {
if (!transmit_active(card))
break;
udelay(50);
counter--;
if (counter <= 0)
netdev_err(card->dev,
"Transmitter failed to deactivate\n");
}
val = xr32(CSR6);
val = val | (1 << 13);
xw32(CSR6, val);
counter = 10;
while (counter > 0) {
if (transmit_active(card))
break;
udelay(50);
counter--;
if (counter <= 0)
netdev_err(card->dev,
"Transmitter failed to re-activate\n");
}
}
static void deactivate_transmitter(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
int counter;
val = xr32(CSR6);
val = val & ~2;
xw32(CSR6, val);
counter = 20;
while (counter > 0) {
if (!transmit_active(card))
break;
udelay(50);
counter--;
if (counter <= 0)
netdev_err(card->dev,
"Transmitter failed to deactivate\n");
}
}
static void enable_transmit_interrupt(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
val = xr32(CSR7);
val |= 1;
xw32(CSR7, val);
}
static void enable_receive_interrupt(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
val = xr32(CSR7);
val = val | (1 << 6);
xw32(CSR7, val);
}
static void enable_link_interrupt(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
val = xr32(CSR7);
val = val | (1 << 27);
xw32(CSR7, val);
}
static void disable_all_interrupts(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
xw32(CSR7, 0);
}
static void enable_common_interrupts(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
val = xr32(CSR7);
val |= (1<<16);
val |= (1<<15);
val |= (1<<13);
val |= (1<<8);
val |= (1<<7);
val |= (1<<5);
val |= (1<<2);
val |= (1<<1);
xw32(CSR7, val);
}
static int enable_promisc(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned int val;
val = xr32(CSR6);
val = val | (1 << 6);
xw32(CSR6, val);
return 1;
}
static int link_status(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
u8 val;
val = xr8(CSR12);
if (!(val & (1 << 2)))
return 10;
if (!(val & (1 << 1)))
return 100;
return 0;
}
static void read_mac_address(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned long flags;
u8 link;
int i;
spin_lock_irqsave(&card->lock, flags);
xw32(CSR9, 1 << 12);
for (i = 0x100; i < 0x1f7; i += link + 2) {
u8 tuple, data_id, data_count;
xw32(CSR10, i);
tuple = xr32(CSR9);
xw32(CSR10, i + 1);
link = xr32(CSR9);
xw32(CSR10, i + 2);
data_id = xr32(CSR9);
xw32(CSR10, i + 3);
data_count = xr32(CSR9);
if ((tuple == 0x22) && (data_id == 0x04) && (data_count == 0x06)) {
int j;
for (j = 0; j < 6; j++) {
xw32(CSR10, i + j + 4);
card->dev->dev_addr[j] = xr32(CSR9) & 0xff;
}
break;
} else if (link == 0) {
break;
}
}
spin_unlock_irqrestore(&card->lock, flags);
pr_debug(" %pM\n", card->dev->dev_addr);
}
static void transceiver_voodoo(struct xircom_private *card)
{
void __iomem *ioaddr = card->ioaddr;
unsigned long flags;
pci_write_config_dword(card->pdev, PCI_POWERMGMT, 0x0000);
setup_descriptors(card);
spin_lock_irqsave(&card->lock, flags);
xw32(CSR15, 0x0008);
udelay(25);
xw32(CSR15, 0xa8050000);
udelay(25);
xw32(CSR15, 0xa00f0000);
udelay(25);
spin_unlock_irqrestore(&card->lock, flags);
netif_start_queue(card->dev);
}
static void xircom_up(struct xircom_private *card)
{
unsigned long flags;
int i;
pci_write_config_dword(card->pdev, PCI_POWERMGMT, 0x0000);
setup_descriptors(card);
spin_lock_irqsave(&card->lock, flags);
enable_link_interrupt(card);
enable_transmit_interrupt(card);
enable_receive_interrupt(card);
enable_common_interrupts(card);
enable_promisc(card);
for (i=0;i<NUMDESCRIPTORS;i++)
investigate_read_descriptor(card->dev,card,i,bufferoffsets[i]);
spin_unlock_irqrestore(&card->lock, flags);
trigger_receive(card);
trigger_transmit(card);
netif_start_queue(card->dev);
}
static void
investigate_read_descriptor(struct net_device *dev, struct xircom_private *card,
int descnr, unsigned int bufferoffset)
{
int status;
status = le32_to_cpu(card->rx_buffer[4*descnr]);
if (status > 0) {
short pkt_len = ((status >> 16) & 0x7ff) - 4;
struct sk_buff *skb;
if (pkt_len > 1518) {
netdev_err(dev, "Packet length %i is bogus\n", pkt_len);
pkt_len = 1518;
}
skb = netdev_alloc_skb(dev, pkt_len + 2);
if (skb == NULL) {
dev->stats.rx_dropped++;
goto out;
}
skb_reserve(skb, 2);
skb_copy_to_linear_data(skb,
&card->rx_buffer[bufferoffset / 4],
pkt_len);
skb_put(skb, pkt_len);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
out:
card->rx_buffer[4*descnr] = cpu_to_le32(0x80000000);
trigger_receive(card);
}
}
static void
investigate_write_descriptor(struct net_device *dev,
struct xircom_private *card,
int descnr, unsigned int bufferoffset)
{
int status;
status = le32_to_cpu(card->tx_buffer[4*descnr]);
#if 0
if (status & 0x8000) {
pr_err("Major transmit error status %x\n", status);
card->tx_buffer[4*descnr] = 0;
netif_wake_queue (dev);
}
#endif
if (status > 0) {
if (card->tx_skb[descnr]!=NULL) {
dev->stats.tx_bytes += card->tx_skb[descnr]->len;
dev_kfree_skb_irq(card->tx_skb[descnr]);
}
card->tx_skb[descnr] = NULL;
if (status & (1 << 8))
dev->stats.collisions++;
card->tx_buffer[4*descnr] = 0;
netif_wake_queue (dev);
dev->stats.tx_packets++;
}
}
static int __init xircom_init(void)
{
return pci_register_driver(&xircom_ops);
}
static void __exit xircom_exit(void)
{
pci_unregister_driver(&xircom_ops);
}
