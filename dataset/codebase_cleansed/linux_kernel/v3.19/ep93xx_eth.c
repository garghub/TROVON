static int ep93xx_mdio_read(struct net_device *dev, int phy_id, int reg)
{
struct ep93xx_priv *ep = netdev_priv(dev);
int data;
int i;
wrl(ep, REG_MIICMD, REG_MIICMD_READ | (phy_id << 5) | reg);
for (i = 0; i < 10; i++) {
if ((rdl(ep, REG_MIISTS) & REG_MIISTS_BUSY) == 0)
break;
msleep(1);
}
if (i == 10) {
pr_info("mdio read timed out\n");
data = 0xffff;
} else {
data = rdl(ep, REG_MIIDATA);
}
return data;
}
static void ep93xx_mdio_write(struct net_device *dev, int phy_id, int reg, int data)
{
struct ep93xx_priv *ep = netdev_priv(dev);
int i;
wrl(ep, REG_MIIDATA, data);
wrl(ep, REG_MIICMD, REG_MIICMD_WRITE | (phy_id << 5) | reg);
for (i = 0; i < 10; i++) {
if ((rdl(ep, REG_MIISTS) & REG_MIISTS_BUSY) == 0)
break;
msleep(1);
}
if (i == 10)
pr_info("mdio write timed out\n");
}
static int ep93xx_rx(struct net_device *dev, int processed, int budget)
{
struct ep93xx_priv *ep = netdev_priv(dev);
while (processed < budget) {
int entry;
struct ep93xx_rstat *rstat;
u32 rstat0;
u32 rstat1;
int length;
struct sk_buff *skb;
entry = ep->rx_pointer;
rstat = ep->descs->rstat + entry;
rstat0 = rstat->rstat0;
rstat1 = rstat->rstat1;
if (!(rstat0 & RSTAT0_RFP) || !(rstat1 & RSTAT1_RFP))
break;
rstat->rstat0 = 0;
rstat->rstat1 = 0;
if (!(rstat0 & RSTAT0_EOF))
pr_crit("not end-of-frame %.8x %.8x\n", rstat0, rstat1);
if (!(rstat0 & RSTAT0_EOB))
pr_crit("not end-of-buffer %.8x %.8x\n", rstat0, rstat1);
if ((rstat1 & RSTAT1_BUFFER_INDEX) >> 16 != entry)
pr_crit("entry mismatch %.8x %.8x\n", rstat0, rstat1);
if (!(rstat0 & RSTAT0_RWE)) {
dev->stats.rx_errors++;
if (rstat0 & RSTAT0_OE)
dev->stats.rx_fifo_errors++;
if (rstat0 & RSTAT0_FE)
dev->stats.rx_frame_errors++;
if (rstat0 & (RSTAT0_RUNT | RSTAT0_EDATA))
dev->stats.rx_length_errors++;
if (rstat0 & RSTAT0_CRCE)
dev->stats.rx_crc_errors++;
goto err;
}
length = rstat1 & RSTAT1_FRAME_LENGTH;
if (length > MAX_PKT_SIZE) {
pr_notice("invalid length %.8x %.8x\n", rstat0, rstat1);
goto err;
}
if (rstat0 & RSTAT0_CRCI)
length -= 4;
skb = netdev_alloc_skb(dev, length + 2);
if (likely(skb != NULL)) {
struct ep93xx_rdesc *rxd = &ep->descs->rdesc[entry];
skb_reserve(skb, 2);
dma_sync_single_for_cpu(dev->dev.parent, rxd->buf_addr,
length, DMA_FROM_DEVICE);
skb_copy_to_linear_data(skb, ep->rx_buf[entry], length);
dma_sync_single_for_device(dev->dev.parent,
rxd->buf_addr, length,
DMA_FROM_DEVICE);
skb_put(skb, length);
skb->protocol = eth_type_trans(skb, dev);
netif_receive_skb(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += length;
} else {
dev->stats.rx_dropped++;
}
err:
ep->rx_pointer = (entry + 1) & (RX_QUEUE_ENTRIES - 1);
processed++;
}
return processed;
}
static int ep93xx_have_more_rx(struct ep93xx_priv *ep)
{
struct ep93xx_rstat *rstat = ep->descs->rstat + ep->rx_pointer;
return !!((rstat->rstat0 & RSTAT0_RFP) && (rstat->rstat1 & RSTAT1_RFP));
}
static int ep93xx_poll(struct napi_struct *napi, int budget)
{
struct ep93xx_priv *ep = container_of(napi, struct ep93xx_priv, napi);
struct net_device *dev = ep->dev;
int rx = 0;
poll_some_more:
rx = ep93xx_rx(dev, rx, budget);
if (rx < budget) {
int more = 0;
spin_lock_irq(&ep->rx_lock);
__napi_complete(napi);
wrl(ep, REG_INTEN, REG_INTEN_TX | REG_INTEN_RX);
if (ep93xx_have_more_rx(ep)) {
wrl(ep, REG_INTEN, REG_INTEN_TX);
wrl(ep, REG_INTSTSP, REG_INTSTS_RX);
more = 1;
}
spin_unlock_irq(&ep->rx_lock);
if (more && napi_reschedule(napi))
goto poll_some_more;
}
if (rx) {
wrw(ep, REG_RXDENQ, rx);
wrw(ep, REG_RXSTSENQ, rx);
}
return rx;
}
static int ep93xx_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ep93xx_priv *ep = netdev_priv(dev);
struct ep93xx_tdesc *txd;
int entry;
if (unlikely(skb->len > MAX_PKT_SIZE)) {
dev->stats.tx_dropped++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
entry = ep->tx_pointer;
ep->tx_pointer = (ep->tx_pointer + 1) & (TX_QUEUE_ENTRIES - 1);
txd = &ep->descs->tdesc[entry];
txd->tdesc1 = TDESC1_EOF | (entry << 16) | (skb->len & 0xfff);
dma_sync_single_for_cpu(dev->dev.parent, txd->buf_addr, skb->len,
DMA_TO_DEVICE);
skb_copy_and_csum_dev(skb, ep->tx_buf[entry]);
dma_sync_single_for_device(dev->dev.parent, txd->buf_addr, skb->len,
DMA_TO_DEVICE);
dev_kfree_skb(skb);
spin_lock_irq(&ep->tx_pending_lock);
ep->tx_pending++;
if (ep->tx_pending == TX_QUEUE_ENTRIES)
netif_stop_queue(dev);
spin_unlock_irq(&ep->tx_pending_lock);
wrl(ep, REG_TXDENQ, 1);
return NETDEV_TX_OK;
}
static void ep93xx_tx_complete(struct net_device *dev)
{
struct ep93xx_priv *ep = netdev_priv(dev);
int wake;
wake = 0;
spin_lock(&ep->tx_pending_lock);
while (1) {
int entry;
struct ep93xx_tstat *tstat;
u32 tstat0;
entry = ep->tx_clean_pointer;
tstat = ep->descs->tstat + entry;
tstat0 = tstat->tstat0;
if (!(tstat0 & TSTAT0_TXFP))
break;
tstat->tstat0 = 0;
if (tstat0 & TSTAT0_FA)
pr_crit("frame aborted %.8x\n", tstat0);
if ((tstat0 & TSTAT0_BUFFER_INDEX) != entry)
pr_crit("entry mismatch %.8x\n", tstat0);
if (tstat0 & TSTAT0_TXWE) {
int length = ep->descs->tdesc[entry].tdesc1 & 0xfff;
dev->stats.tx_packets++;
dev->stats.tx_bytes += length;
} else {
dev->stats.tx_errors++;
}
if (tstat0 & TSTAT0_OW)
dev->stats.tx_window_errors++;
if (tstat0 & TSTAT0_TXU)
dev->stats.tx_fifo_errors++;
dev->stats.collisions += (tstat0 >> 16) & 0x1f;
ep->tx_clean_pointer = (entry + 1) & (TX_QUEUE_ENTRIES - 1);
if (ep->tx_pending == TX_QUEUE_ENTRIES)
wake = 1;
ep->tx_pending--;
}
spin_unlock(&ep->tx_pending_lock);
if (wake)
netif_wake_queue(dev);
}
static irqreturn_t ep93xx_irq(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct ep93xx_priv *ep = netdev_priv(dev);
u32 status;
status = rdl(ep, REG_INTSTSC);
if (status == 0)
return IRQ_NONE;
if (status & REG_INTSTS_RX) {
spin_lock(&ep->rx_lock);
if (likely(napi_schedule_prep(&ep->napi))) {
wrl(ep, REG_INTEN, REG_INTEN_TX);
__napi_schedule(&ep->napi);
}
spin_unlock(&ep->rx_lock);
}
if (status & REG_INTSTS_TX)
ep93xx_tx_complete(dev);
return IRQ_HANDLED;
}
static void ep93xx_free_buffers(struct ep93xx_priv *ep)
{
struct device *dev = ep->dev->dev.parent;
int i;
for (i = 0; i < RX_QUEUE_ENTRIES; i++) {
dma_addr_t d;
d = ep->descs->rdesc[i].buf_addr;
if (d)
dma_unmap_single(dev, d, PKT_BUF_SIZE, DMA_FROM_DEVICE);
if (ep->rx_buf[i] != NULL)
kfree(ep->rx_buf[i]);
}
for (i = 0; i < TX_QUEUE_ENTRIES; i++) {
dma_addr_t d;
d = ep->descs->tdesc[i].buf_addr;
if (d)
dma_unmap_single(dev, d, PKT_BUF_SIZE, DMA_TO_DEVICE);
if (ep->tx_buf[i] != NULL)
kfree(ep->tx_buf[i]);
}
dma_free_coherent(dev, sizeof(struct ep93xx_descs), ep->descs,
ep->descs_dma_addr);
}
static int ep93xx_alloc_buffers(struct ep93xx_priv *ep)
{
struct device *dev = ep->dev->dev.parent;
int i;
ep->descs = dma_alloc_coherent(dev, sizeof(struct ep93xx_descs),
&ep->descs_dma_addr, GFP_KERNEL);
if (ep->descs == NULL)
return 1;
for (i = 0; i < RX_QUEUE_ENTRIES; i++) {
void *buf;
dma_addr_t d;
buf = kmalloc(PKT_BUF_SIZE, GFP_KERNEL);
if (buf == NULL)
goto err;
d = dma_map_single(dev, buf, PKT_BUF_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(dev, d)) {
kfree(buf);
goto err;
}
ep->rx_buf[i] = buf;
ep->descs->rdesc[i].buf_addr = d;
ep->descs->rdesc[i].rdesc1 = (i << 16) | PKT_BUF_SIZE;
}
for (i = 0; i < TX_QUEUE_ENTRIES; i++) {
void *buf;
dma_addr_t d;
buf = kmalloc(PKT_BUF_SIZE, GFP_KERNEL);
if (buf == NULL)
goto err;
d = dma_map_single(dev, buf, PKT_BUF_SIZE, DMA_TO_DEVICE);
if (dma_mapping_error(dev, d)) {
kfree(buf);
goto err;
}
ep->tx_buf[i] = buf;
ep->descs->tdesc[i].buf_addr = d;
}
return 0;
err:
ep93xx_free_buffers(ep);
return 1;
}
static int ep93xx_start_hw(struct net_device *dev)
{
struct ep93xx_priv *ep = netdev_priv(dev);
unsigned long addr;
int i;
wrl(ep, REG_SELFCTL, REG_SELFCTL_RESET);
for (i = 0; i < 10; i++) {
if ((rdl(ep, REG_SELFCTL) & REG_SELFCTL_RESET) == 0)
break;
msleep(1);
}
if (i == 10) {
pr_crit("hw failed to reset\n");
return 1;
}
wrl(ep, REG_SELFCTL, ((ep->mdc_divisor - 1) << 9));
if ((ep93xx_mdio_read(dev, ep->mii.phy_id, MII_BMSR) & 0x0040) != 0)
wrl(ep, REG_SELFCTL, ((ep->mdc_divisor - 1) << 9) | (1 << 8));
addr = ep->descs_dma_addr + offsetof(struct ep93xx_descs, rdesc);
wrl(ep, REG_RXDQBADD, addr);
wrl(ep, REG_RXDCURADD, addr);
wrw(ep, REG_RXDQBLEN, RX_QUEUE_ENTRIES * sizeof(struct ep93xx_rdesc));
addr = ep->descs_dma_addr + offsetof(struct ep93xx_descs, rstat);
wrl(ep, REG_RXSTSQBADD, addr);
wrl(ep, REG_RXSTSQCURADD, addr);
wrw(ep, REG_RXSTSQBLEN, RX_QUEUE_ENTRIES * sizeof(struct ep93xx_rstat));
addr = ep->descs_dma_addr + offsetof(struct ep93xx_descs, tdesc);
wrl(ep, REG_TXDQBADD, addr);
wrl(ep, REG_TXDQCURADD, addr);
wrw(ep, REG_TXDQBLEN, TX_QUEUE_ENTRIES * sizeof(struct ep93xx_tdesc));
addr = ep->descs_dma_addr + offsetof(struct ep93xx_descs, tstat);
wrl(ep, REG_TXSTSQBADD, addr);
wrl(ep, REG_TXSTSQCURADD, addr);
wrw(ep, REG_TXSTSQBLEN, TX_QUEUE_ENTRIES * sizeof(struct ep93xx_tstat));
wrl(ep, REG_BMCTL, REG_BMCTL_ENABLE_TX | REG_BMCTL_ENABLE_RX);
wrl(ep, REG_INTEN, REG_INTEN_TX | REG_INTEN_RX);
wrl(ep, REG_GIINTMSK, 0);
for (i = 0; i < 10; i++) {
if ((rdl(ep, REG_BMSTS) & REG_BMSTS_RX_ACTIVE) != 0)
break;
msleep(1);
}
if (i == 10) {
pr_crit("hw failed to start\n");
return 1;
}
wrl(ep, REG_RXDENQ, RX_QUEUE_ENTRIES);
wrl(ep, REG_RXSTSENQ, RX_QUEUE_ENTRIES);
wrb(ep, REG_INDAD0, dev->dev_addr[0]);
wrb(ep, REG_INDAD1, dev->dev_addr[1]);
wrb(ep, REG_INDAD2, dev->dev_addr[2]);
wrb(ep, REG_INDAD3, dev->dev_addr[3]);
wrb(ep, REG_INDAD4, dev->dev_addr[4]);
wrb(ep, REG_INDAD5, dev->dev_addr[5]);
wrl(ep, REG_AFP, 0);
wrl(ep, REG_MAXFRMLEN, (MAX_PKT_SIZE << 16) | MAX_PKT_SIZE);
wrl(ep, REG_RXCTL, REG_RXCTL_DEFAULT);
wrl(ep, REG_TXCTL, REG_TXCTL_ENABLE);
return 0;
}
static void ep93xx_stop_hw(struct net_device *dev)
{
struct ep93xx_priv *ep = netdev_priv(dev);
int i;
wrl(ep, REG_SELFCTL, REG_SELFCTL_RESET);
for (i = 0; i < 10; i++) {
if ((rdl(ep, REG_SELFCTL) & REG_SELFCTL_RESET) == 0)
break;
msleep(1);
}
if (i == 10)
pr_crit("hw failed to reset\n");
}
static int ep93xx_open(struct net_device *dev)
{
struct ep93xx_priv *ep = netdev_priv(dev);
int err;
if (ep93xx_alloc_buffers(ep))
return -ENOMEM;
napi_enable(&ep->napi);
if (ep93xx_start_hw(dev)) {
napi_disable(&ep->napi);
ep93xx_free_buffers(ep);
return -EIO;
}
spin_lock_init(&ep->rx_lock);
ep->rx_pointer = 0;
ep->tx_clean_pointer = 0;
ep->tx_pointer = 0;
spin_lock_init(&ep->tx_pending_lock);
ep->tx_pending = 0;
err = request_irq(ep->irq, ep93xx_irq, IRQF_SHARED, dev->name, dev);
if (err) {
napi_disable(&ep->napi);
ep93xx_stop_hw(dev);
ep93xx_free_buffers(ep);
return err;
}
wrl(ep, REG_GIINTMSK, REG_GIINTMSK_ENABLE);
netif_start_queue(dev);
return 0;
}
static int ep93xx_close(struct net_device *dev)
{
struct ep93xx_priv *ep = netdev_priv(dev);
napi_disable(&ep->napi);
netif_stop_queue(dev);
wrl(ep, REG_GIINTMSK, 0);
free_irq(ep->irq, dev);
ep93xx_stop_hw(dev);
ep93xx_free_buffers(ep);
return 0;
}
static int ep93xx_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct ep93xx_priv *ep = netdev_priv(dev);
struct mii_ioctl_data *data = if_mii(ifr);
return generic_mii_ioctl(&ep->mii, data, cmd, NULL);
}
static void ep93xx_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_MODULE_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_MODULE_VERSION, sizeof(info->version));
}
static int ep93xx_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct ep93xx_priv *ep = netdev_priv(dev);
return mii_ethtool_gset(&ep->mii, cmd);
}
static int ep93xx_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct ep93xx_priv *ep = netdev_priv(dev);
return mii_ethtool_sset(&ep->mii, cmd);
}
static int ep93xx_nway_reset(struct net_device *dev)
{
struct ep93xx_priv *ep = netdev_priv(dev);
return mii_nway_restart(&ep->mii);
}
static u32 ep93xx_get_link(struct net_device *dev)
{
struct ep93xx_priv *ep = netdev_priv(dev);
return mii_link_ok(&ep->mii);
}
static struct net_device *ep93xx_dev_alloc(struct ep93xx_eth_data *data)
{
struct net_device *dev;
dev = alloc_etherdev(sizeof(struct ep93xx_priv));
if (dev == NULL)
return NULL;
memcpy(dev->dev_addr, data->dev_addr, ETH_ALEN);
dev->ethtool_ops = &ep93xx_ethtool_ops;
dev->netdev_ops = &ep93xx_netdev_ops;
dev->features |= NETIF_F_SG | NETIF_F_HW_CSUM;
return dev;
}
static int ep93xx_eth_remove(struct platform_device *pdev)
{
struct net_device *dev;
struct ep93xx_priv *ep;
dev = platform_get_drvdata(pdev);
if (dev == NULL)
return 0;
ep = netdev_priv(dev);
unregister_netdev(dev);
ep93xx_free_buffers(ep);
if (ep->base_addr != NULL)
iounmap(ep->base_addr);
if (ep->res != NULL) {
release_resource(ep->res);
kfree(ep->res);
}
free_netdev(dev);
return 0;
}
static int ep93xx_eth_probe(struct platform_device *pdev)
{
struct ep93xx_eth_data *data;
struct net_device *dev;
struct ep93xx_priv *ep;
struct resource *mem;
int irq;
int err;
if (pdev == NULL)
return -ENODEV;
data = dev_get_platdata(&pdev->dev);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!mem || irq < 0)
return -ENXIO;
dev = ep93xx_dev_alloc(data);
if (dev == NULL) {
err = -ENOMEM;
goto err_out;
}
ep = netdev_priv(dev);
ep->dev = dev;
SET_NETDEV_DEV(dev, &pdev->dev);
netif_napi_add(dev, &ep->napi, ep93xx_poll, 64);
platform_set_drvdata(pdev, dev);
ep->res = request_mem_region(mem->start, resource_size(mem),
dev_name(&pdev->dev));
if (ep->res == NULL) {
dev_err(&pdev->dev, "Could not reserve memory region\n");
err = -ENOMEM;
goto err_out;
}
ep->base_addr = ioremap(mem->start, resource_size(mem));
if (ep->base_addr == NULL) {
dev_err(&pdev->dev, "Failed to ioremap ethernet registers\n");
err = -EIO;
goto err_out;
}
ep->irq = irq;
ep->mii.phy_id = data->phy_id;
ep->mii.phy_id_mask = 0x1f;
ep->mii.reg_num_mask = 0x1f;
ep->mii.dev = dev;
ep->mii.mdio_read = ep93xx_mdio_read;
ep->mii.mdio_write = ep93xx_mdio_write;
ep->mdc_divisor = 40;
if (is_zero_ether_addr(dev->dev_addr))
eth_hw_addr_random(dev);
err = register_netdev(dev);
if (err) {
dev_err(&pdev->dev, "Failed to register netdev\n");
goto err_out;
}
printk(KERN_INFO "%s: ep93xx on-chip ethernet, IRQ %d, %pM\n",
dev->name, ep->irq, dev->dev_addr);
return 0;
err_out:
ep93xx_eth_remove(pdev);
return err;
}
