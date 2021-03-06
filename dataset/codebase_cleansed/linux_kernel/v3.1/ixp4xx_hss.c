static inline struct port* dev_to_port(struct net_device *dev)
{
return dev_to_hdlc(dev)->priv;
}
static inline void memcpy_swab32(u32 *dest, u32 *src, int cnt)
{
int i;
for (i = 0; i < cnt; i++)
dest[i] = swab32(src[i]);
}
static void hss_npe_send(struct port *port, struct msg *msg, const char* what)
{
u32 *val = (u32*)msg;
if (npe_send_message(port->npe, msg, what)) {
pr_crit("HSS-%i: unable to send command [%08X:%08X] to %s\n",
port->id, val[0], val[1], npe_name(port->npe));
BUG();
}
}
static void hss_config_set_lut(struct port *port)
{
struct msg msg;
int ch;
memset(&msg, 0, sizeof(msg));
msg.cmd = PORT_CONFIG_WRITE;
msg.hss_port = port->id;
for (ch = 0; ch < MAX_CHANNELS; ch++) {
msg.data32 >>= 2;
msg.data32 |= TDMMAP_HDLC << 30;
if (ch % 16 == 15) {
msg.index = HSS_CONFIG_TX_LUT + ((ch / 4) & ~3);
hss_npe_send(port, &msg, "HSS_SET_TX_LUT");
msg.index += HSS_CONFIG_RX_LUT - HSS_CONFIG_TX_LUT;
hss_npe_send(port, &msg, "HSS_SET_RX_LUT");
}
}
}
static void hss_config(struct port *port)
{
struct msg msg;
memset(&msg, 0, sizeof(msg));
msg.cmd = PORT_CONFIG_WRITE;
msg.hss_port = port->id;
msg.index = HSS_CONFIG_TX_PCR;
msg.data32 = PCR_FRM_PULSE_DISABLED | PCR_MSB_ENDIAN |
PCR_TX_DATA_ENABLE | PCR_SOF_NO_FBIT;
if (port->clock_type == CLOCK_INT)
msg.data32 |= PCR_SYNC_CLK_DIR_OUTPUT;
hss_npe_send(port, &msg, "HSS_SET_TX_PCR");
msg.index = HSS_CONFIG_RX_PCR;
msg.data32 ^= PCR_TX_DATA_ENABLE | PCR_DCLK_EDGE_RISING;
hss_npe_send(port, &msg, "HSS_SET_RX_PCR");
memset(&msg, 0, sizeof(msg));
msg.cmd = PORT_CONFIG_WRITE;
msg.hss_port = port->id;
msg.index = HSS_CONFIG_CORE_CR;
msg.data32 = (port->loopback ? CCR_LOOPBACK : 0) |
(port->id ? CCR_SECOND_HSS : 0);
hss_npe_send(port, &msg, "HSS_SET_CORE_CR");
memset(&msg, 0, sizeof(msg));
msg.cmd = PORT_CONFIG_WRITE;
msg.hss_port = port->id;
msg.index = HSS_CONFIG_CLOCK_CR;
msg.data32 = port->clock_reg;
hss_npe_send(port, &msg, "HSS_SET_CLOCK_CR");
memset(&msg, 0, sizeof(msg));
msg.cmd = PORT_CONFIG_WRITE;
msg.hss_port = port->id;
msg.index = HSS_CONFIG_TX_FCR;
msg.data16a = FRAME_OFFSET;
msg.data16b = FRAME_SIZE - 1;
hss_npe_send(port, &msg, "HSS_SET_TX_FCR");
memset(&msg, 0, sizeof(msg));
msg.cmd = PORT_CONFIG_WRITE;
msg.hss_port = port->id;
msg.index = HSS_CONFIG_RX_FCR;
msg.data16a = FRAME_OFFSET;
msg.data16b = FRAME_SIZE - 1;
hss_npe_send(port, &msg, "HSS_SET_RX_FCR");
hss_config_set_lut(port);
memset(&msg, 0, sizeof(msg));
msg.cmd = PORT_CONFIG_LOAD;
msg.hss_port = port->id;
hss_npe_send(port, &msg, "HSS_LOAD_CONFIG");
if (npe_recv_message(port->npe, &msg, "HSS_LOAD_CONFIG") ||
msg.cmd != PORT_CONFIG_LOAD || msg.data32) {
pr_crit("HSS-%i: HSS_LOAD_CONFIG failed\n", port->id);
BUG();
}
npe_recv_message(port->npe, &msg, "FLUSH_IT");
}
static void hss_set_hdlc_cfg(struct port *port)
{
struct msg msg;
memset(&msg, 0, sizeof(msg));
msg.cmd = PKT_PIPE_HDLC_CFG_WRITE;
msg.hss_port = port->id;
msg.data8a = port->hdlc_cfg;
msg.data8b = port->hdlc_cfg | (PKT_EXTRA_FLAGS << 3);
hss_npe_send(port, &msg, "HSS_SET_HDLC_CFG");
}
static u32 hss_get_status(struct port *port)
{
struct msg msg;
memset(&msg, 0, sizeof(msg));
msg.cmd = PORT_ERROR_READ;
msg.hss_port = port->id;
hss_npe_send(port, &msg, "PORT_ERROR_READ");
if (npe_recv_message(port->npe, &msg, "PORT_ERROR_READ")) {
pr_crit("HSS-%i: unable to read HSS status\n", port->id);
BUG();
}
return msg.data32;
}
static void hss_start_hdlc(struct port *port)
{
struct msg msg;
memset(&msg, 0, sizeof(msg));
msg.cmd = PKT_PIPE_FLOW_ENABLE;
msg.hss_port = port->id;
msg.data32 = 0;
hss_npe_send(port, &msg, "HSS_ENABLE_PKT_PIPE");
}
static void hss_stop_hdlc(struct port *port)
{
struct msg msg;
memset(&msg, 0, sizeof(msg));
msg.cmd = PKT_PIPE_FLOW_DISABLE;
msg.hss_port = port->id;
hss_npe_send(port, &msg, "HSS_DISABLE_PKT_PIPE");
hss_get_status(port);
}
static int hss_load_firmware(struct port *port)
{
struct msg msg;
int err;
if (port->initialized)
return 0;
if (!npe_running(port->npe) &&
(err = npe_load_firmware(port->npe, npe_name(port->npe),
port->dev)))
return err;
memset(&msg, 0, sizeof(msg));
msg.cmd = PKT_NUM_PIPES_WRITE;
msg.hss_port = port->id;
msg.data8a = PKT_NUM_PIPES;
hss_npe_send(port, &msg, "HSS_SET_PKT_PIPES");
msg.cmd = PKT_PIPE_FIFO_SIZEW_WRITE;
msg.data8a = PKT_PIPE_FIFO_SIZEW;
hss_npe_send(port, &msg, "HSS_SET_PKT_FIFO");
msg.cmd = PKT_PIPE_MODE_WRITE;
msg.data8a = NPE_PKT_MODE_HDLC;
hss_npe_send(port, &msg, "HSS_SET_PKT_MODE");
msg.cmd = PKT_PIPE_RX_SIZE_WRITE;
msg.data16a = HDLC_MAX_MRU;
hss_npe_send(port, &msg, "HSS_SET_PKT_RX_SIZE");
msg.cmd = PKT_PIPE_IDLE_PATTERN_WRITE;
msg.data32 = 0x7F7F7F7F;
hss_npe_send(port, &msg, "HSS_SET_PKT_IDLE");
port->initialized = 1;
return 0;
}
static inline void debug_pkt(struct net_device *dev, const char *func,
u8 *data, int len)
{
#if DEBUG_PKT_BYTES
int i;
printk(KERN_DEBUG "%s: %s(%i)", dev->name, func, len);
for (i = 0; i < len; i++) {
if (i >= DEBUG_PKT_BYTES)
break;
printk("%s%02X", !(i % 4) ? " " : "", data[i]);
}
printk("\n");
#endif
}
static inline void debug_desc(u32 phys, struct desc *desc)
{
#if DEBUG_DESC
printk(KERN_DEBUG "%X: %X %3X %3X %08X %X %X\n",
phys, desc->next, desc->buf_len, desc->pkt_len,
desc->data, desc->status, desc->error_count);
#endif
}
static inline int queue_get_desc(unsigned int queue, struct port *port,
int is_tx)
{
u32 phys, tab_phys, n_desc;
struct desc *tab;
if (!(phys = qmgr_get_entry(queue)))
return -1;
BUG_ON(phys & 0x1F);
tab_phys = is_tx ? tx_desc_phys(port, 0) : rx_desc_phys(port, 0);
tab = is_tx ? tx_desc_ptr(port, 0) : rx_desc_ptr(port, 0);
n_desc = (phys - tab_phys) / sizeof(struct desc);
BUG_ON(n_desc >= (is_tx ? TX_DESCS : RX_DESCS));
debug_desc(phys, &tab[n_desc]);
BUG_ON(tab[n_desc].next);
return n_desc;
}
static inline void queue_put_desc(unsigned int queue, u32 phys,
struct desc *desc)
{
debug_desc(phys, desc);
BUG_ON(phys & 0x1F);
qmgr_put_entry(queue, phys);
}
static inline void dma_unmap_tx(struct port *port, struct desc *desc)
{
#ifdef __ARMEB__
dma_unmap_single(&port->netdev->dev, desc->data,
desc->buf_len, DMA_TO_DEVICE);
#else
dma_unmap_single(&port->netdev->dev, desc->data & ~3,
ALIGN((desc->data & 3) + desc->buf_len, 4),
DMA_TO_DEVICE);
#endif
}
static void hss_hdlc_set_carrier(void *pdev, int carrier)
{
struct net_device *netdev = pdev;
struct port *port = dev_to_port(netdev);
unsigned long flags;
spin_lock_irqsave(&npe_lock, flags);
port->carrier = carrier;
if (!port->loopback) {
if (carrier)
netif_carrier_on(netdev);
else
netif_carrier_off(netdev);
}
spin_unlock_irqrestore(&npe_lock, flags);
}
static void hss_hdlc_rx_irq(void *pdev)
{
struct net_device *dev = pdev;
struct port *port = dev_to_port(dev);
#if DEBUG_RX
printk(KERN_DEBUG "%s: hss_hdlc_rx_irq\n", dev->name);
#endif
qmgr_disable_irq(queue_ids[port->id].rx);
napi_schedule(&port->napi);
}
static int hss_hdlc_poll(struct napi_struct *napi, int budget)
{
struct port *port = container_of(napi, struct port, napi);
struct net_device *dev = port->netdev;
unsigned int rxq = queue_ids[port->id].rx;
unsigned int rxfreeq = queue_ids[port->id].rxfree;
int received = 0;
#if DEBUG_RX
printk(KERN_DEBUG "%s: hss_hdlc_poll\n", dev->name);
#endif
while (received < budget) {
struct sk_buff *skb;
struct desc *desc;
int n;
#ifdef __ARMEB__
struct sk_buff *temp;
u32 phys;
#endif
if ((n = queue_get_desc(rxq, port, 0)) < 0) {
#if DEBUG_RX
printk(KERN_DEBUG "%s: hss_hdlc_poll"
" napi_complete\n", dev->name);
#endif
napi_complete(napi);
qmgr_enable_irq(rxq);
if (!qmgr_stat_empty(rxq) &&
napi_reschedule(napi)) {
#if DEBUG_RX
printk(KERN_DEBUG "%s: hss_hdlc_poll"
" napi_reschedule succeeded\n",
dev->name);
#endif
qmgr_disable_irq(rxq);
continue;
}
#if DEBUG_RX
printk(KERN_DEBUG "%s: hss_hdlc_poll all done\n",
dev->name);
#endif
return received;
}
desc = rx_desc_ptr(port, n);
#if 0
if (desc->error_count)
printk(KERN_DEBUG "%s: hss_hdlc_poll status 0x%02X"
" errors %u\n", dev->name, desc->status,
desc->error_count);
#endif
skb = NULL;
switch (desc->status) {
case 0:
#ifdef __ARMEB__
if ((skb = netdev_alloc_skb(dev, RX_SIZE)) != NULL) {
phys = dma_map_single(&dev->dev, skb->data,
RX_SIZE,
DMA_FROM_DEVICE);
if (dma_mapping_error(&dev->dev, phys)) {
dev_kfree_skb(skb);
skb = NULL;
}
}
#else
skb = netdev_alloc_skb(dev, desc->pkt_len);
#endif
if (!skb)
dev->stats.rx_dropped++;
break;
case ERR_HDLC_ALIGN:
case ERR_HDLC_ABORT:
dev->stats.rx_frame_errors++;
dev->stats.rx_errors++;
break;
case ERR_HDLC_FCS:
dev->stats.rx_crc_errors++;
dev->stats.rx_errors++;
break;
case ERR_HDLC_TOO_LONG:
dev->stats.rx_length_errors++;
dev->stats.rx_errors++;
break;
default:
netdev_err(dev, "hss_hdlc_poll: status 0x%02X errors %u\n",
desc->status, desc->error_count);
dev->stats.rx_errors++;
}
if (!skb) {
desc->buf_len = RX_SIZE;
desc->pkt_len = desc->status = 0;
queue_put_desc(rxfreeq, rx_desc_phys(port, n), desc);
continue;
}
#ifdef __ARMEB__
temp = skb;
skb = port->rx_buff_tab[n];
dma_unmap_single(&dev->dev, desc->data,
RX_SIZE, DMA_FROM_DEVICE);
#else
dma_sync_single_for_cpu(&dev->dev, desc->data,
RX_SIZE, DMA_FROM_DEVICE);
memcpy_swab32((u32 *)skb->data, (u32 *)port->rx_buff_tab[n],
ALIGN(desc->pkt_len, 4) / 4);
#endif
skb_put(skb, desc->pkt_len);
debug_pkt(dev, "hss_hdlc_poll", skb->data, skb->len);
skb->protocol = hdlc_type_trans(skb, dev);
dev->stats.rx_packets++;
dev->stats.rx_bytes += skb->len;
netif_receive_skb(skb);
#ifdef __ARMEB__
port->rx_buff_tab[n] = temp;
desc->data = phys;
#endif
desc->buf_len = RX_SIZE;
desc->pkt_len = 0;
queue_put_desc(rxfreeq, rx_desc_phys(port, n), desc);
received++;
}
#if DEBUG_RX
printk(KERN_DEBUG "hss_hdlc_poll: end, not all work done\n");
#endif
return received;
}
static void hss_hdlc_txdone_irq(void *pdev)
{
struct net_device *dev = pdev;
struct port *port = dev_to_port(dev);
int n_desc;
#if DEBUG_TX
printk(KERN_DEBUG DRV_NAME ": hss_hdlc_txdone_irq\n");
#endif
while ((n_desc = queue_get_desc(queue_ids[port->id].txdone,
port, 1)) >= 0) {
struct desc *desc;
int start;
desc = tx_desc_ptr(port, n_desc);
dev->stats.tx_packets++;
dev->stats.tx_bytes += desc->pkt_len;
dma_unmap_tx(port, desc);
#if DEBUG_TX
printk(KERN_DEBUG "%s: hss_hdlc_txdone_irq free %p\n",
dev->name, port->tx_buff_tab[n_desc]);
#endif
free_buffer_irq(port->tx_buff_tab[n_desc]);
port->tx_buff_tab[n_desc] = NULL;
start = qmgr_stat_below_low_watermark(port->plat->txreadyq);
queue_put_desc(port->plat->txreadyq,
tx_desc_phys(port, n_desc), desc);
if (start) {
#if DEBUG_TX
printk(KERN_DEBUG "%s: hss_hdlc_txdone_irq xmit"
" ready\n", dev->name);
#endif
netif_wake_queue(dev);
}
}
}
static int hss_hdlc_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct port *port = dev_to_port(dev);
unsigned int txreadyq = port->plat->txreadyq;
int len, offset, bytes, n;
void *mem;
u32 phys;
struct desc *desc;
#if DEBUG_TX
printk(KERN_DEBUG "%s: hss_hdlc_xmit\n", dev->name);
#endif
if (unlikely(skb->len > HDLC_MAX_MRU)) {
dev_kfree_skb(skb);
dev->stats.tx_errors++;
return NETDEV_TX_OK;
}
debug_pkt(dev, "hss_hdlc_xmit", skb->data, skb->len);
len = skb->len;
#ifdef __ARMEB__
offset = 0;
bytes = len;
mem = skb->data;
#else
offset = (int)skb->data & 3;
bytes = ALIGN(offset + len, 4);
if (!(mem = kmalloc(bytes, GFP_ATOMIC))) {
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
memcpy_swab32(mem, (u32 *)((int)skb->data & ~3), bytes / 4);
dev_kfree_skb(skb);
#endif
phys = dma_map_single(&dev->dev, mem, bytes, DMA_TO_DEVICE);
if (dma_mapping_error(&dev->dev, phys)) {
#ifdef __ARMEB__
dev_kfree_skb(skb);
#else
kfree(mem);
#endif
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
n = queue_get_desc(txreadyq, port, 1);
BUG_ON(n < 0);
desc = tx_desc_ptr(port, n);
#ifdef __ARMEB__
port->tx_buff_tab[n] = skb;
#else
port->tx_buff_tab[n] = mem;
#endif
desc->data = phys + offset;
desc->buf_len = desc->pkt_len = len;
wmb();
queue_put_desc(queue_ids[port->id].tx, tx_desc_phys(port, n), desc);
if (qmgr_stat_below_low_watermark(txreadyq)) {
#if DEBUG_TX
printk(KERN_DEBUG "%s: hss_hdlc_xmit queue full\n", dev->name);
#endif
netif_stop_queue(dev);
if (!qmgr_stat_below_low_watermark(txreadyq)) {
#if DEBUG_TX
printk(KERN_DEBUG "%s: hss_hdlc_xmit ready again\n",
dev->name);
#endif
netif_wake_queue(dev);
}
}
#if DEBUG_TX
printk(KERN_DEBUG "%s: hss_hdlc_xmit end\n", dev->name);
#endif
return NETDEV_TX_OK;
}
static int request_hdlc_queues(struct port *port)
{
int err;
err = qmgr_request_queue(queue_ids[port->id].rxfree, RX_DESCS, 0, 0,
"%s:RX-free", port->netdev->name);
if (err)
return err;
err = qmgr_request_queue(queue_ids[port->id].rx, RX_DESCS, 0, 0,
"%s:RX", port->netdev->name);
if (err)
goto rel_rxfree;
err = qmgr_request_queue(queue_ids[port->id].tx, TX_DESCS, 0, 0,
"%s:TX", port->netdev->name);
if (err)
goto rel_rx;
err = qmgr_request_queue(port->plat->txreadyq, TX_DESCS, 0, 0,
"%s:TX-ready", port->netdev->name);
if (err)
goto rel_tx;
err = qmgr_request_queue(queue_ids[port->id].txdone, TX_DESCS, 0, 0,
"%s:TX-done", port->netdev->name);
if (err)
goto rel_txready;
return 0;
rel_txready:
qmgr_release_queue(port->plat->txreadyq);
rel_tx:
qmgr_release_queue(queue_ids[port->id].tx);
rel_rx:
qmgr_release_queue(queue_ids[port->id].rx);
rel_rxfree:
qmgr_release_queue(queue_ids[port->id].rxfree);
printk(KERN_DEBUG "%s: unable to request hardware queues\n",
port->netdev->name);
return err;
}
static void release_hdlc_queues(struct port *port)
{
qmgr_release_queue(queue_ids[port->id].rxfree);
qmgr_release_queue(queue_ids[port->id].rx);
qmgr_release_queue(queue_ids[port->id].txdone);
qmgr_release_queue(queue_ids[port->id].tx);
qmgr_release_queue(port->plat->txreadyq);
}
static int init_hdlc_queues(struct port *port)
{
int i;
if (!ports_open)
if (!(dma_pool = dma_pool_create(DRV_NAME, NULL,
POOL_ALLOC_SIZE, 32, 0)))
return -ENOMEM;
if (!(port->desc_tab = dma_pool_alloc(dma_pool, GFP_KERNEL,
&port->desc_tab_phys)))
return -ENOMEM;
memset(port->desc_tab, 0, POOL_ALLOC_SIZE);
memset(port->rx_buff_tab, 0, sizeof(port->rx_buff_tab));
memset(port->tx_buff_tab, 0, sizeof(port->tx_buff_tab));
for (i = 0; i < RX_DESCS; i++) {
struct desc *desc = rx_desc_ptr(port, i);
buffer_t *buff;
void *data;
#ifdef __ARMEB__
if (!(buff = netdev_alloc_skb(port->netdev, RX_SIZE)))
return -ENOMEM;
data = buff->data;
#else
if (!(buff = kmalloc(RX_SIZE, GFP_KERNEL)))
return -ENOMEM;
data = buff;
#endif
desc->buf_len = RX_SIZE;
desc->data = dma_map_single(&port->netdev->dev, data,
RX_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(&port->netdev->dev, desc->data)) {
free_buffer(buff);
return -EIO;
}
port->rx_buff_tab[i] = buff;
}
return 0;
}
static void destroy_hdlc_queues(struct port *port)
{
int i;
if (port->desc_tab) {
for (i = 0; i < RX_DESCS; i++) {
struct desc *desc = rx_desc_ptr(port, i);
buffer_t *buff = port->rx_buff_tab[i];
if (buff) {
dma_unmap_single(&port->netdev->dev,
desc->data, RX_SIZE,
DMA_FROM_DEVICE);
free_buffer(buff);
}
}
for (i = 0; i < TX_DESCS; i++) {
struct desc *desc = tx_desc_ptr(port, i);
buffer_t *buff = port->tx_buff_tab[i];
if (buff) {
dma_unmap_tx(port, desc);
free_buffer(buff);
}
}
dma_pool_free(dma_pool, port->desc_tab, port->desc_tab_phys);
port->desc_tab = NULL;
}
if (!ports_open && dma_pool) {
dma_pool_destroy(dma_pool);
dma_pool = NULL;
}
}
static int hss_hdlc_open(struct net_device *dev)
{
struct port *port = dev_to_port(dev);
unsigned long flags;
int i, err = 0;
if ((err = hdlc_open(dev)))
return err;
if ((err = hss_load_firmware(port)))
goto err_hdlc_close;
if ((err = request_hdlc_queues(port)))
goto err_hdlc_close;
if ((err = init_hdlc_queues(port)))
goto err_destroy_queues;
spin_lock_irqsave(&npe_lock, flags);
if (port->plat->open)
if ((err = port->plat->open(port->id, dev,
hss_hdlc_set_carrier)))
goto err_unlock;
spin_unlock_irqrestore(&npe_lock, flags);
for (i = 0; i < TX_DESCS; i++)
queue_put_desc(port->plat->txreadyq,
tx_desc_phys(port, i), tx_desc_ptr(port, i));
for (i = 0; i < RX_DESCS; i++)
queue_put_desc(queue_ids[port->id].rxfree,
rx_desc_phys(port, i), rx_desc_ptr(port, i));
napi_enable(&port->napi);
netif_start_queue(dev);
qmgr_set_irq(queue_ids[port->id].rx, QUEUE_IRQ_SRC_NOT_EMPTY,
hss_hdlc_rx_irq, dev);
qmgr_set_irq(queue_ids[port->id].txdone, QUEUE_IRQ_SRC_NOT_EMPTY,
hss_hdlc_txdone_irq, dev);
qmgr_enable_irq(queue_ids[port->id].txdone);
ports_open++;
hss_set_hdlc_cfg(port);
hss_config(port);
hss_start_hdlc(port);
napi_schedule(&port->napi);
return 0;
err_unlock:
spin_unlock_irqrestore(&npe_lock, flags);
err_destroy_queues:
destroy_hdlc_queues(port);
release_hdlc_queues(port);
err_hdlc_close:
hdlc_close(dev);
return err;
}
static int hss_hdlc_close(struct net_device *dev)
{
struct port *port = dev_to_port(dev);
unsigned long flags;
int i, buffs = RX_DESCS;
spin_lock_irqsave(&npe_lock, flags);
ports_open--;
qmgr_disable_irq(queue_ids[port->id].rx);
netif_stop_queue(dev);
napi_disable(&port->napi);
hss_stop_hdlc(port);
while (queue_get_desc(queue_ids[port->id].rxfree, port, 0) >= 0)
buffs--;
while (queue_get_desc(queue_ids[port->id].rx, port, 0) >= 0)
buffs--;
if (buffs)
netdev_crit(dev, "unable to drain RX queue, %i buffer(s) left in NPE\n",
buffs);
buffs = TX_DESCS;
while (queue_get_desc(queue_ids[port->id].tx, port, 1) >= 0)
buffs--;
i = 0;
do {
while (queue_get_desc(port->plat->txreadyq, port, 1) >= 0)
buffs--;
if (!buffs)
break;
} while (++i < MAX_CLOSE_WAIT);
if (buffs)
netdev_crit(dev, "unable to drain TX queue, %i buffer(s) left in NPE\n",
buffs);
#if DEBUG_CLOSE
if (!buffs)
printk(KERN_DEBUG "Draining TX queues took %i cycles\n", i);
#endif
qmgr_disable_irq(queue_ids[port->id].txdone);
if (port->plat->close)
port->plat->close(port->id, dev);
spin_unlock_irqrestore(&npe_lock, flags);
destroy_hdlc_queues(port);
release_hdlc_queues(port);
hdlc_close(dev);
return 0;
}
static int hss_hdlc_attach(struct net_device *dev, unsigned short encoding,
unsigned short parity)
{
struct port *port = dev_to_port(dev);
if (encoding != ENCODING_NRZ)
return -EINVAL;
switch(parity) {
case PARITY_CRC16_PR1_CCITT:
port->hdlc_cfg = 0;
return 0;
case PARITY_CRC32_PR1_CCITT:
port->hdlc_cfg = PKT_HDLC_CRC_32;
return 0;
default:
return -EINVAL;
}
}
static u32 check_clock(u32 rate, u32 a, u32 b, u32 c,
u32 *best, u32 *best_diff, u32 *reg)
{
u64 new_rate;
u32 new_diff;
new_rate = ixp4xx_timer_freq * (u64)(c + 1);
do_div(new_rate, a * (c + 1) + b + 1);
new_diff = abs((u32)new_rate - rate);
if (new_diff < *best_diff) {
*best = new_rate;
*best_diff = new_diff;
*reg = (a << 22) | (b << 12) | c;
}
return new_diff;
}
static void find_best_clock(u32 rate, u32 *best, u32 *reg)
{
u32 a, b, diff = 0xFFFFFFFF;
a = ixp4xx_timer_freq / rate;
if (a > 0x3FF) {
check_clock(rate, 0x3FF, 1, 1, best, &diff, reg);
return;
}
if (a == 0) {
a = 1;
rate = ixp4xx_timer_freq;
}
if (rate * a == ixp4xx_timer_freq) {
check_clock(rate, a - 1, 1, 1, best, &diff, reg);
return;
}
for (b = 0; b < 0x400; b++) {
u64 c = (b + 1) * (u64)rate;
do_div(c, ixp4xx_timer_freq - rate * a);
c--;
if (c >= 0xFFF) {
if (b == 0 &&
!check_clock(rate, a - 1, 1, 1, best, &diff, reg))
return;
check_clock(rate, a, b, 0xFFF, best, &diff, reg);
return;
}
if (!check_clock(rate, a, b, c, best, &diff, reg))
return;
if (!check_clock(rate, a, b, c + 1, best, &diff, reg))
return;
}
}
static int hss_hdlc_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
const size_t size = sizeof(sync_serial_settings);
sync_serial_settings new_line;
sync_serial_settings __user *line = ifr->ifr_settings.ifs_ifsu.sync;
struct port *port = dev_to_port(dev);
unsigned long flags;
int clk;
if (cmd != SIOCWANDEV)
return hdlc_ioctl(dev, ifr, cmd);
switch(ifr->ifr_settings.type) {
case IF_GET_IFACE:
ifr->ifr_settings.type = IF_IFACE_V35;
if (ifr->ifr_settings.size < size) {
ifr->ifr_settings.size = size;
return -ENOBUFS;
}
memset(&new_line, 0, sizeof(new_line));
new_line.clock_type = port->clock_type;
new_line.clock_rate = port->clock_rate;
new_line.loopback = port->loopback;
if (copy_to_user(line, &new_line, size))
return -EFAULT;
return 0;
case IF_IFACE_SYNC_SERIAL:
case IF_IFACE_V35:
if(!capable(CAP_NET_ADMIN))
return -EPERM;
if (copy_from_user(&new_line, line, size))
return -EFAULT;
clk = new_line.clock_type;
if (port->plat->set_clock)
clk = port->plat->set_clock(port->id, clk);
if (clk != CLOCK_EXT && clk != CLOCK_INT)
return -EINVAL;
if (new_line.loopback != 0 && new_line.loopback != 1)
return -EINVAL;
port->clock_type = clk;
if (clk == CLOCK_INT)
find_best_clock(new_line.clock_rate, &port->clock_rate,
&port->clock_reg);
else {
port->clock_rate = 0;
port->clock_reg = CLK42X_SPEED_2048KHZ;
}
port->loopback = new_line.loopback;
spin_lock_irqsave(&npe_lock, flags);
if (dev->flags & IFF_UP)
hss_config(port);
if (port->loopback || port->carrier)
netif_carrier_on(port->netdev);
else
netif_carrier_off(port->netdev);
spin_unlock_irqrestore(&npe_lock, flags);
return 0;
default:
return hdlc_ioctl(dev, ifr, cmd);
}
}
static int __devinit hss_init_one(struct platform_device *pdev)
{
struct port *port;
struct net_device *dev;
hdlc_device *hdlc;
int err;
if ((port = kzalloc(sizeof(*port), GFP_KERNEL)) == NULL)
return -ENOMEM;
if ((port->npe = npe_request(0)) == NULL) {
err = -ENODEV;
goto err_free;
}
if ((port->netdev = dev = alloc_hdlcdev(port)) == NULL) {
err = -ENOMEM;
goto err_plat;
}
SET_NETDEV_DEV(dev, &pdev->dev);
hdlc = dev_to_hdlc(dev);
hdlc->attach = hss_hdlc_attach;
hdlc->xmit = hss_hdlc_xmit;
dev->netdev_ops = &hss_hdlc_ops;
dev->tx_queue_len = 100;
port->clock_type = CLOCK_EXT;
port->clock_rate = 0;
port->clock_reg = CLK42X_SPEED_2048KHZ;
port->id = pdev->id;
port->dev = &pdev->dev;
port->plat = pdev->dev.platform_data;
netif_napi_add(dev, &port->napi, hss_hdlc_poll, NAPI_WEIGHT);
if ((err = register_hdlc_device(dev)))
goto err_free_netdev;
platform_set_drvdata(pdev, port);
netdev_info(dev, "HSS-%i\n", port->id);
return 0;
err_free_netdev:
free_netdev(dev);
err_plat:
npe_release(port->npe);
err_free:
kfree(port);
return err;
}
static int __devexit hss_remove_one(struct platform_device *pdev)
{
struct port *port = platform_get_drvdata(pdev);
unregister_hdlc_device(port->netdev);
free_netdev(port->netdev);
npe_release(port->npe);
platform_set_drvdata(pdev, NULL);
kfree(port);
return 0;
}
static int __init hss_init_module(void)
{
if ((ixp4xx_read_feature_bits() &
(IXP4XX_FEATURE_HDLC | IXP4XX_FEATURE_HSS)) !=
(IXP4XX_FEATURE_HDLC | IXP4XX_FEATURE_HSS))
return -ENODEV;
spin_lock_init(&npe_lock);
return platform_driver_register(&ixp4xx_hss_driver);
}
static void __exit hss_cleanup_module(void)
{
platform_driver_unregister(&ixp4xx_hss_driver);
}
