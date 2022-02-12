static int ixpdev_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ixpdev_priv *ip = netdev_priv(dev);
struct ixpdev_tx_desc *desc;
int entry;
unsigned long flags;
if (unlikely(skb->len > PAGE_SIZE)) {
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
entry = tx_pointer;
tx_pointer = (tx_pointer + 1) % TX_BUF_COUNT;
desc = tx_desc + entry;
desc->pkt_length = skb->len;
desc->channel = ip->channel;
skb_copy_and_csum_dev(skb, phys_to_virt(desc->buf_addr));
dev_kfree_skb(skb);
ixp2000_reg_write(RING_TX_PENDING,
TX_BUF_DESC_BASE + (entry * sizeof(struct ixpdev_tx_desc)));
local_irq_save(flags);
ip->tx_queue_entries++;
if (ip->tx_queue_entries == TX_BUF_COUNT_PER_CHAN)
netif_stop_queue(dev);
local_irq_restore(flags);
return NETDEV_TX_OK;
}
static int ixpdev_rx(struct net_device *dev, int processed, int budget)
{
while (processed < budget) {
struct ixpdev_rx_desc *desc;
struct sk_buff *skb;
void *buf;
u32 _desc;
_desc = ixp2000_reg_read(RING_RX_DONE);
if (_desc == 0)
return 0;
desc = rx_desc +
((_desc - RX_BUF_DESC_BASE) / sizeof(struct ixpdev_rx_desc));
buf = phys_to_virt(desc->buf_addr);
if (desc->pkt_length < 4 || desc->pkt_length > PAGE_SIZE) {
printk(KERN_ERR "ixp2000: rx err, length %d\n",
desc->pkt_length);
goto err;
}
if (desc->channel < 0 || desc->channel >= nds_count) {
printk(KERN_ERR "ixp2000: rx err, channel %d\n",
desc->channel);
goto err;
}
desc->pkt_length -= 4;
if (unlikely(!netif_running(nds[desc->channel])))
goto err;
skb = netdev_alloc_skb_ip_align(dev, desc->pkt_length);
if (likely(skb != NULL)) {
skb_copy_to_linear_data(skb, buf, desc->pkt_length);
skb_put(skb, desc->pkt_length);
skb->protocol = eth_type_trans(skb, nds[desc->channel]);
netif_receive_skb(skb);
}
err:
ixp2000_reg_write(RING_RX_PENDING, _desc);
processed++;
}
return processed;
}
static int ixpdev_poll(struct napi_struct *napi, int budget)
{
struct ixpdev_priv *ip = container_of(napi, struct ixpdev_priv, napi);
struct net_device *dev = ip->dev;
int rx;
rx = 0;
do {
ixp2000_reg_write(IXP2000_IRQ_THD_RAW_STATUS_A_0, 0x00ff);
rx = ixpdev_rx(dev, rx, budget);
if (rx >= budget)
break;
} while (ixp2000_reg_read(IXP2000_IRQ_THD_RAW_STATUS_A_0) & 0x00ff);
napi_complete(napi);
ixp2000_reg_write(IXP2000_IRQ_THD_ENABLE_SET_A_0, 0x00ff);
return rx;
}
static void ixpdev_tx_complete(void)
{
int channel;
u32 wake;
wake = 0;
while (1) {
struct ixpdev_priv *ip;
u32 desc;
int entry;
desc = ixp2000_reg_read(RING_TX_DONE);
if (desc == 0)
break;
entry = (desc - TX_BUF_DESC_BASE) / sizeof(struct ixpdev_tx_desc);
channel = tx_desc[entry].channel;
if (channel < 0 || channel >= nds_count) {
printk(KERN_ERR "ixp2000: txcomp channel index "
"out of bounds (%d, %.8i, %d)\n",
channel, (unsigned int)desc, entry);
continue;
}
ip = netdev_priv(nds[channel]);
if (ip->tx_queue_entries == TX_BUF_COUNT_PER_CHAN)
wake |= 1 << channel;
ip->tx_queue_entries--;
}
for (channel = 0; wake != 0; channel++) {
if (wake & (1 << channel)) {
netif_wake_queue(nds[channel]);
wake &= ~(1 << channel);
}
}
}
static irqreturn_t ixpdev_interrupt(int irq, void *dev_id)
{
u32 status;
status = ixp2000_reg_read(IXP2000_IRQ_THD_STATUS_A_0);
if (status == 0)
return IRQ_NONE;
if (status & 0x00ff) {
struct net_device *dev = nds[0];
struct ixpdev_priv *ip = netdev_priv(dev);
ixp2000_reg_wrb(IXP2000_IRQ_THD_ENABLE_CLEAR_A_0, 0x00ff);
if (likely(napi_schedule_prep(&ip->napi))) {
__napi_schedule(&ip->napi);
} else {
printk(KERN_CRIT "ixp2000: irq while polling!!\n");
}
}
if (status & 0xff00) {
ixp2000_reg_wrb(IXP2000_IRQ_THD_RAW_STATUS_A_0, 0xff00);
ixpdev_tx_complete();
}
return IRQ_HANDLED;
}
static void ixpdev_poll_controller(struct net_device *dev)
{
disable_irq(IRQ_IXP2000_THDA0);
ixpdev_interrupt(IRQ_IXP2000_THDA0, dev);
enable_irq(IRQ_IXP2000_THDA0);
}
static int ixpdev_open(struct net_device *dev)
{
struct ixpdev_priv *ip = netdev_priv(dev);
int err;
napi_enable(&ip->napi);
if (!nds_open++) {
err = request_irq(IRQ_IXP2000_THDA0, ixpdev_interrupt,
IRQF_SHARED, "ixp2000_eth", nds);
if (err) {
nds_open--;
napi_disable(&ip->napi);
return err;
}
ixp2000_reg_write(IXP2000_IRQ_THD_ENABLE_SET_A_0, 0xffff);
}
set_port_admin_status(ip->channel, 1);
netif_start_queue(dev);
return 0;
}
static int ixpdev_close(struct net_device *dev)
{
struct ixpdev_priv *ip = netdev_priv(dev);
netif_stop_queue(dev);
napi_disable(&ip->napi);
set_port_admin_status(ip->channel, 0);
if (!--nds_open) {
ixp2000_reg_write(IXP2000_IRQ_THD_ENABLE_CLEAR_A_0, 0xffff);
free_irq(IRQ_IXP2000_THDA0, nds);
}
return 0;
}
static struct net_device_stats *ixpdev_get_stats(struct net_device *dev)
{
struct ixpdev_priv *ip = netdev_priv(dev);
pm3386_get_stats(ip->channel, &(dev->stats));
return &(dev->stats);
}
struct net_device *ixpdev_alloc(int channel, int sizeof_priv)
{
struct net_device *dev;
struct ixpdev_priv *ip;
dev = alloc_etherdev(sizeof_priv);
if (dev == NULL)
return NULL;
dev->netdev_ops = &ixpdev_netdev_ops;
dev->features |= NETIF_F_SG | NETIF_F_HW_CSUM;
ip = netdev_priv(dev);
ip->dev = dev;
netif_napi_add(dev, &ip->napi, ixpdev_poll, 64);
ip->channel = channel;
ip->tx_queue_entries = 0;
return dev;
}
int ixpdev_init(int __nds_count, struct net_device **__nds,
void (*__set_port_admin_status)(int port, int up))
{
int i;
int err;
BUILD_BUG_ON(RX_BUF_COUNT > 192 || TX_BUF_COUNT > 192);
printk(KERN_INFO "IXP2000 MSF ethernet driver %s\n", DRV_MODULE_VERSION);
nds_count = __nds_count;
nds = __nds;
set_port_admin_status = __set_port_admin_status;
for (i = 0; i < RX_BUF_COUNT; i++) {
void *buf;
buf = (void *)get_zeroed_page(GFP_KERNEL);
if (buf == NULL) {
err = -ENOMEM;
while (--i >= 0)
free_page((unsigned long)phys_to_virt(rx_desc[i].buf_addr));
goto err_out;
}
rx_desc[i].buf_addr = virt_to_phys(buf);
rx_desc[i].buf_length = PAGE_SIZE;
}
for (i = 0; i < TX_BUF_COUNT; i++) {
void *buf;
buf = (void *)get_zeroed_page(GFP_KERNEL);
if (buf == NULL) {
err = -ENOMEM;
while (--i >= 0)
free_page((unsigned long)phys_to_virt(tx_desc[i].buf_addr));
goto err_free_rx;
}
tx_desc[i].buf_addr = virt_to_phys(buf);
}
ixp2000_reg_write(RING_RX_PENDING_BASE, 0x44000000);
ixp2000_reg_write(RING_RX_PENDING_HEAD, 0x00000000);
ixp2000_reg_write(RING_RX_PENDING_TAIL, 0x00000000);
ixp2000_reg_write(RING_RX_DONE_BASE, 0x40000400);
ixp2000_reg_write(RING_RX_DONE_HEAD, 0x00000000);
ixp2000_reg_write(RING_RX_DONE_TAIL, 0x00000000);
for (i = 0; i < RX_BUF_COUNT; i++) {
ixp2000_reg_write(RING_RX_PENDING,
RX_BUF_DESC_BASE + (i * sizeof(struct ixpdev_rx_desc)));
}
ixp2000_uengine_load(0, &ixp2400_rx);
ixp2000_uengine_start_contexts(0, 0xff);
ixp2000_reg_write(RING_TX_PENDING_BASE, 0x44000800);
ixp2000_reg_write(RING_TX_PENDING_HEAD, 0x00000000);
ixp2000_reg_write(RING_TX_PENDING_TAIL, 0x00000000);
ixp2000_reg_write(RING_TX_DONE_BASE, 0x40000c00);
ixp2000_reg_write(RING_TX_DONE_HEAD, 0x00000000);
ixp2000_reg_write(RING_TX_DONE_TAIL, 0x00000000);
ixp2000_uengine_load(1, &ixp2400_tx);
ixp2000_uengine_start_contexts(1, 0xff);
for (i = 0; i < nds_count; i++) {
err = register_netdev(nds[i]);
if (err) {
while (--i >= 0)
unregister_netdev(nds[i]);
goto err_free_tx;
}
}
for (i = 0; i < nds_count; i++) {
printk(KERN_INFO "%s: IXP2000 MSF ethernet (port %d), %pM.\n",
nds[i]->name, i, nds[i]->dev_addr);
}
return 0;
err_free_tx:
for (i = 0; i < TX_BUF_COUNT; i++)
free_page((unsigned long)phys_to_virt(tx_desc[i].buf_addr));
err_free_rx:
for (i = 0; i < RX_BUF_COUNT; i++)
free_page((unsigned long)phys_to_virt(rx_desc[i].buf_addr));
err_out:
return err;
}
void ixpdev_deinit(void)
{
int i;
for (i = 0; i < nds_count; i++)
unregister_netdev(nds[i]);
ixp2000_uengine_stop_contexts(1, 0xff);
ixp2000_uengine_stop_contexts(0, 0xff);
ixp2000_uengine_reset(0x3);
for (i = 0; i < TX_BUF_COUNT; i++)
free_page((unsigned long)phys_to_virt(tx_desc[i].buf_addr));
for (i = 0; i < RX_BUF_COUNT; i++)
free_page((unsigned long)phys_to_virt(rx_desc[i].buf_addr));
}
