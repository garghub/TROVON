static void ec_bhf_print_status(struct ec_bhf_priv *priv)
{
struct device *dev = PRIV_TO_DEV(priv);
dev_dbg(dev, "Frame error counter: %d\n",
ioread8(priv->mac_io + MAC_FRAME_ERR_CNT));
dev_dbg(dev, "RX error counter: %d\n",
ioread8(priv->mac_io + MAC_RX_ERR_CNT));
dev_dbg(dev, "CRC error counter: %d\n",
ioread8(priv->mac_io + MAC_CRC_ERR_CNT));
dev_dbg(dev, "TX frame counter: %d\n",
ioread32(priv->mac_io + MAC_TX_FRAME_CNT));
dev_dbg(dev, "RX frame counter: %d\n",
ioread32(priv->mac_io + MAC_RX_FRAME_CNT));
dev_dbg(dev, "TX fifo level: %d\n",
ioread8(priv->mac_io + MAC_TX_FIFO_LVL));
dev_dbg(dev, "Dropped frames: %d\n",
ioread8(priv->mac_io + MAC_DROPPED_FRMS));
dev_dbg(dev, "Connected with CCAT slot: %d\n",
ioread8(priv->mac_io + MAC_CONNECTED_CCAT_FLAG));
dev_dbg(dev, "Link status: %d\n",
ioread8(priv->mii_io + MII_LINK_STATUS));
}
static void ec_bhf_reset(struct ec_bhf_priv *priv)
{
iowrite8(0, priv->mac_io + MAC_FRAME_ERR_CNT);
iowrite8(0, priv->mac_io + MAC_RX_ERR_CNT);
iowrite8(0, priv->mac_io + MAC_CRC_ERR_CNT);
iowrite8(0, priv->mac_io + MAC_LNK_LST_ERR_CNT);
iowrite32(0, priv->mac_io + MAC_TX_FRAME_CNT);
iowrite32(0, priv->mac_io + MAC_RX_FRAME_CNT);
iowrite8(0, priv->mac_io + MAC_DROPPED_FRMS);
iowrite8(0, priv->fifo_io + FIFO_TX_RESET);
iowrite8(0, priv->fifo_io + FIFO_RX_RESET);
iowrite8(0, priv->mac_io + MAC_TX_FIFO_LVL);
}
static void ec_bhf_send_packet(struct ec_bhf_priv *priv, struct tx_desc *desc)
{
u32 len = le16_to_cpu(desc->header.len) + sizeof(desc->header);
u32 addr = (u8 *)desc - priv->tx_buf.buf;
iowrite32((ALIGN(len, 8) << 24) | addr, priv->fifo_io + FIFO_TX_REG);
dev_dbg(PRIV_TO_DEV(priv), "Done sending packet\n");
}
static int ec_bhf_desc_sent(struct tx_desc *desc)
{
return le32_to_cpu(desc->header.sent) & TX_HDR_SENT;
}
static void ec_bhf_process_tx(struct ec_bhf_priv *priv)
{
if (unlikely(netif_queue_stopped(priv->net_dev))) {
smp_rmb();
if (ec_bhf_desc_sent(&priv->tx_descs[priv->tx_dnext]))
netif_wake_queue(priv->net_dev);
}
}
static int ec_bhf_pkt_received(struct rx_desc *desc)
{
return le32_to_cpu(desc->header.recv) & RXHDR_NEXT_RECV_FLAG;
}
static void ec_bhf_add_rx_desc(struct ec_bhf_priv *priv, struct rx_desc *desc)
{
iowrite32(FIFO_RX_ADDR_VALID | ((u8 *)(desc) - priv->rx_buf.buf),
priv->fifo_io + FIFO_RX_REG);
}
static void ec_bhf_process_rx(struct ec_bhf_priv *priv)
{
struct rx_desc *desc = &priv->rx_descs[priv->rx_dnext];
struct device *dev = PRIV_TO_DEV(priv);
while (ec_bhf_pkt_received(desc)) {
int pkt_size = (le16_to_cpu(desc->header.len) &
RXHDR_LEN_MASK) - sizeof(struct rx_header) - 4;
u8 *data = desc->data;
struct sk_buff *skb;
skb = netdev_alloc_skb_ip_align(priv->net_dev, pkt_size);
dev_dbg(dev, "Received packet, size: %d\n", pkt_size);
if (skb) {
memcpy(skb_put(skb, pkt_size), data, pkt_size);
skb->protocol = eth_type_trans(skb, priv->net_dev);
dev_dbg(dev, "Protocol type: %x\n", skb->protocol);
priv->stat_rx_bytes += pkt_size;
netif_rx(skb);
} else {
dev_err_ratelimited(dev,
"Couldn't allocate a skb_buff for a packet of size %u\n",
pkt_size);
}
desc->header.recv = 0;
ec_bhf_add_rx_desc(priv, desc);
priv->rx_dnext = (priv->rx_dnext + 1) % priv->rx_dcount;
desc = &priv->rx_descs[priv->rx_dnext];
}
}
static enum hrtimer_restart ec_bhf_timer_fun(struct hrtimer *timer)
{
struct ec_bhf_priv *priv = container_of(timer, struct ec_bhf_priv,
hrtimer);
ec_bhf_process_rx(priv);
ec_bhf_process_tx(priv);
if (!netif_running(priv->net_dev))
return HRTIMER_NORESTART;
hrtimer_forward_now(timer, ktime_set(0, polling_frequency));
return HRTIMER_RESTART;
}
static int ec_bhf_setup_offsets(struct ec_bhf_priv *priv)
{
struct device *dev = PRIV_TO_DEV(priv);
unsigned block_count, i;
void __iomem *ec_info;
dev_dbg(dev, "Info block:\n");
dev_dbg(dev, "Type of function: %x\n", (unsigned)ioread16(priv->io));
dev_dbg(dev, "Revision of function: %x\n",
(unsigned)ioread16(priv->io + INFO_BLOCK_REV));
block_count = ioread8(priv->io + INFO_BLOCK_BLK_CNT);
dev_dbg(dev, "Number of function blocks: %x\n", block_count);
for (i = 0; i < block_count; i++) {
u16 type = ioread16(priv->io + i * INFO_BLOCK_SIZE +
INFO_BLOCK_TYPE);
if (type == ETHERCAT_MASTER_ID)
break;
}
if (i == block_count) {
dev_err(dev, "EtherCAT master with DMA block not found\n");
return -ENODEV;
}
dev_dbg(dev, "EtherCAT master with DMA block found at pos: %d\n", i);
ec_info = priv->io + i * INFO_BLOCK_SIZE;
dev_dbg(dev, "EtherCAT master revision: %d\n",
ioread16(ec_info + INFO_BLOCK_REV));
priv->tx_dma_chan = ioread8(ec_info + INFO_BLOCK_TX_CHAN);
dev_dbg(dev, "EtherCAT master tx dma channel: %d\n",
priv->tx_dma_chan);
priv->rx_dma_chan = ioread8(ec_info + INFO_BLOCK_RX_CHAN);
dev_dbg(dev, "EtherCAT master rx dma channel: %d\n",
priv->rx_dma_chan);
priv->ec_io = priv->io + ioread32(ec_info + INFO_BLOCK_OFFSET);
priv->mii_io = priv->ec_io + ioread32(priv->ec_io + EC_MII_OFFSET);
priv->fifo_io = priv->ec_io + ioread32(priv->ec_io + EC_FIFO_OFFSET);
priv->mac_io = priv->ec_io + ioread32(priv->ec_io + EC_MAC_OFFSET);
dev_dbg(dev,
"EtherCAT block addres: %p, fifo address: %p, mii address: %p, mac address: %p\n",
priv->ec_io, priv->fifo_io, priv->mii_io, priv->mac_io);
return 0;
}
static netdev_tx_t ec_bhf_start_xmit(struct sk_buff *skb,
struct net_device *net_dev)
{
struct ec_bhf_priv *priv = netdev_priv(net_dev);
struct tx_desc *desc;
unsigned len;
dev_dbg(PRIV_TO_DEV(priv), "Starting xmit\n");
desc = &priv->tx_descs[priv->tx_dnext];
skb_copy_and_csum_dev(skb, desc->data);
len = skb->len;
memset(&desc->header, 0, sizeof(desc->header));
desc->header.len = cpu_to_le16(len);
desc->header.port = TX_HDR_PORT_0;
ec_bhf_send_packet(priv, desc);
priv->tx_dnext = (priv->tx_dnext + 1) % priv->tx_dcount;
if (!ec_bhf_desc_sent(&priv->tx_descs[priv->tx_dnext])) {
smp_wmb();
netif_stop_queue(net_dev);
dev_dbg(PRIV_TO_DEV(priv), "Stopping netif queue\n");
ec_bhf_print_status(priv);
}
priv->stat_tx_bytes += len;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int ec_bhf_alloc_dma_mem(struct ec_bhf_priv *priv,
struct bhf_dma *buf,
int channel,
int size)
{
int offset = channel * DMA_CHAN_SIZE + DMA_CHAN_OFFSET;
struct device *dev = PRIV_TO_DEV(priv);
u32 mask;
iowrite32(0xffffffff, priv->dma_io + offset);
mask = ioread32(priv->dma_io + offset);
mask &= DMA_WINDOW_SIZE_MASK;
dev_dbg(dev, "Read mask %x for channel %d\n", mask, channel);
buf->len = min_t(int, ~mask + 1, size);
buf->alloc_len = 2 * buf->len;
dev_dbg(dev, "Allocating %d bytes for channel %d",
(int)buf->alloc_len, channel);
buf->alloc = dma_alloc_coherent(dev, buf->alloc_len, &buf->alloc_phys,
GFP_KERNEL);
if (buf->alloc == NULL) {
dev_info(dev, "Failed to allocate buffer\n");
return -ENOMEM;
}
buf->buf_phys = (buf->alloc_phys + buf->len) & mask;
buf->buf = buf->alloc + (buf->buf_phys - buf->alloc_phys);
iowrite32(0, priv->dma_io + offset + 4);
iowrite32(buf->buf_phys, priv->dma_io + offset);
dev_dbg(dev, "Buffer: %x and read from dev: %x",
(unsigned)buf->buf_phys, ioread32(priv->dma_io + offset));
return 0;
}
static void ec_bhf_setup_tx_descs(struct ec_bhf_priv *priv)
{
int i = 0;
priv->tx_dcount = priv->tx_buf.len / sizeof(struct tx_desc);
priv->tx_descs = (struct tx_desc *) priv->tx_buf.buf;
priv->tx_dnext = 0;
for (i = 0; i < priv->tx_dcount; i++)
priv->tx_descs[i].header.sent = cpu_to_le32(TX_HDR_SENT);
}
static void ec_bhf_setup_rx_descs(struct ec_bhf_priv *priv)
{
int i;
priv->rx_dcount = priv->rx_buf.len / sizeof(struct rx_desc);
priv->rx_descs = (struct rx_desc *) priv->rx_buf.buf;
priv->rx_dnext = 0;
for (i = 0; i < priv->rx_dcount; i++) {
struct rx_desc *desc = &priv->rx_descs[i];
u32 next;
if (i != priv->rx_dcount - 1)
next = (u8 *)(desc + 1) - priv->rx_buf.buf;
else
next = 0;
next |= RXHDR_NEXT_VALID;
desc->header.next = cpu_to_le32(next);
desc->header.recv = 0;
ec_bhf_add_rx_desc(priv, desc);
}
}
static int ec_bhf_open(struct net_device *net_dev)
{
struct ec_bhf_priv *priv = netdev_priv(net_dev);
struct device *dev = PRIV_TO_DEV(priv);
int err = 0;
dev_info(dev, "Opening device\n");
ec_bhf_reset(priv);
err = ec_bhf_alloc_dma_mem(priv, &priv->rx_buf, priv->rx_dma_chan,
FIFO_SIZE * sizeof(struct rx_desc));
if (err) {
dev_err(dev, "Failed to allocate rx buffer\n");
goto out;
}
ec_bhf_setup_rx_descs(priv);
dev_info(dev, "RX buffer allocated, address: %x\n",
(unsigned)priv->rx_buf.buf_phys);
err = ec_bhf_alloc_dma_mem(priv, &priv->tx_buf, priv->tx_dma_chan,
FIFO_SIZE * sizeof(struct tx_desc));
if (err) {
dev_err(dev, "Failed to allocate tx buffer\n");
goto error_rx_free;
}
dev_dbg(dev, "TX buffer allocated, addres: %x\n",
(unsigned)priv->tx_buf.buf_phys);
iowrite8(0, priv->mii_io + MII_MAC_FILT_FLAG);
ec_bhf_setup_tx_descs(priv);
netif_start_queue(net_dev);
hrtimer_init(&priv->hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
priv->hrtimer.function = ec_bhf_timer_fun;
hrtimer_start(&priv->hrtimer, ktime_set(0, polling_frequency),
HRTIMER_MODE_REL);
dev_info(PRIV_TO_DEV(priv), "Device open\n");
ec_bhf_print_status(priv);
return 0;
error_rx_free:
dma_free_coherent(dev, priv->rx_buf.alloc_len, priv->rx_buf.alloc,
priv->rx_buf.alloc_len);
out:
return err;
}
static int ec_bhf_stop(struct net_device *net_dev)
{
struct ec_bhf_priv *priv = netdev_priv(net_dev);
struct device *dev = PRIV_TO_DEV(priv);
hrtimer_cancel(&priv->hrtimer);
ec_bhf_reset(priv);
netif_tx_disable(net_dev);
dma_free_coherent(dev, priv->tx_buf.alloc_len,
priv->tx_buf.alloc, priv->tx_buf.alloc_phys);
dma_free_coherent(dev, priv->rx_buf.alloc_len,
priv->rx_buf.alloc, priv->rx_buf.alloc_phys);
return 0;
}
static struct rtnl_link_stats64 *
ec_bhf_get_stats(struct net_device *net_dev,
struct rtnl_link_stats64 *stats)
{
struct ec_bhf_priv *priv = netdev_priv(net_dev);
stats->rx_errors = ioread8(priv->mac_io + MAC_RX_ERR_CNT) +
ioread8(priv->mac_io + MAC_CRC_ERR_CNT) +
ioread8(priv->mac_io + MAC_FRAME_ERR_CNT);
stats->rx_packets = ioread32(priv->mac_io + MAC_RX_FRAME_CNT);
stats->tx_packets = ioread32(priv->mac_io + MAC_TX_FRAME_CNT);
stats->rx_dropped = ioread8(priv->mac_io + MAC_DROPPED_FRMS);
stats->tx_bytes = priv->stat_tx_bytes;
stats->rx_bytes = priv->stat_rx_bytes;
return stats;
}
static int ec_bhf_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct net_device *net_dev;
struct ec_bhf_priv *priv;
void __iomem *dma_io;
void __iomem *io;
int err = 0;
err = pci_enable_device(dev);
if (err)
return err;
pci_set_master(dev);
err = pci_set_dma_mask(dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&dev->dev,
"Required dma mask not supported, failed to initialize device\n");
err = -EIO;
goto err_disable_dev;
}
err = pci_set_consistent_dma_mask(dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&dev->dev,
"Required dma mask not supported, failed to initialize device\n");
goto err_disable_dev;
}
err = pci_request_regions(dev, "ec_bhf");
if (err) {
dev_err(&dev->dev, "Failed to request pci memory regions\n");
goto err_disable_dev;
}
io = pci_iomap(dev, 0, 0);
if (!io) {
dev_err(&dev->dev, "Failed to map pci card memory bar 0");
err = -EIO;
goto err_release_regions;
}
dma_io = pci_iomap(dev, 2, 0);
if (!dma_io) {
dev_err(&dev->dev, "Failed to map pci card memory bar 2");
err = -EIO;
goto err_unmap;
}
net_dev = alloc_etherdev(sizeof(struct ec_bhf_priv));
if (net_dev == NULL) {
err = -ENOMEM;
goto err_unmap_dma_io;
}
pci_set_drvdata(dev, net_dev);
SET_NETDEV_DEV(net_dev, &dev->dev);
net_dev->features = 0;
net_dev->flags |= IFF_NOARP;
net_dev->netdev_ops = &ec_bhf_netdev_ops;
priv = netdev_priv(net_dev);
priv->net_dev = net_dev;
priv->io = io;
priv->dma_io = dma_io;
priv->dev = dev;
err = ec_bhf_setup_offsets(priv);
if (err < 0)
goto err_free_net_dev;
memcpy_fromio(net_dev->dev_addr, priv->mii_io + MII_MAC_ADDR, 6);
dev_dbg(&dev->dev, "CX5020 Ethercat master address: %pM\n",
net_dev->dev_addr);
err = register_netdev(net_dev);
if (err < 0)
goto err_free_net_dev;
return 0;
err_free_net_dev:
free_netdev(net_dev);
err_unmap_dma_io:
pci_iounmap(dev, dma_io);
err_unmap:
pci_iounmap(dev, io);
err_release_regions:
pci_release_regions(dev);
err_disable_dev:
pci_clear_master(dev);
pci_disable_device(dev);
return err;
}
static void ec_bhf_remove(struct pci_dev *dev)
{
struct net_device *net_dev = pci_get_drvdata(dev);
struct ec_bhf_priv *priv = netdev_priv(net_dev);
unregister_netdev(net_dev);
free_netdev(net_dev);
pci_iounmap(dev, priv->dma_io);
pci_iounmap(dev, priv->io);
pci_release_regions(dev);
pci_clear_master(dev);
pci_disable_device(dev);
}
static int __init ec_bhf_init(void)
{
return pci_register_driver(&pci_driver);
}
static void __exit ec_bhf_exit(void)
{
pci_unregister_driver(&pci_driver);
}
