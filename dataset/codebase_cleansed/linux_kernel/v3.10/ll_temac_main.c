u32 temac_ior(struct temac_local *lp, int offset)
{
return in_be32((u32 *)(lp->regs + offset));
}
void temac_iow(struct temac_local *lp, int offset, u32 value)
{
out_be32((u32 *) (lp->regs + offset), value);
}
int temac_indirect_busywait(struct temac_local *lp)
{
long end = jiffies + 2;
while (!(temac_ior(lp, XTE_RDY0_OFFSET) & XTE_RDY0_HARD_ACS_RDY_MASK)) {
if (end - jiffies <= 0) {
WARN_ON(1);
return -ETIMEDOUT;
}
msleep(1);
}
return 0;
}
u32 temac_indirect_in32(struct temac_local *lp, int reg)
{
u32 val;
if (temac_indirect_busywait(lp))
return -ETIMEDOUT;
temac_iow(lp, XTE_CTL0_OFFSET, reg);
if (temac_indirect_busywait(lp))
return -ETIMEDOUT;
val = temac_ior(lp, XTE_LSW0_OFFSET);
return val;
}
void temac_indirect_out32(struct temac_local *lp, int reg, u32 value)
{
if (temac_indirect_busywait(lp))
return;
temac_iow(lp, XTE_LSW0_OFFSET, value);
temac_iow(lp, XTE_CTL0_OFFSET, CNTLREG_WRITE_ENABLE_MASK | reg);
temac_indirect_busywait(lp);
}
static u32 temac_dma_in32(struct temac_local *lp, int reg)
{
return in_be32((u32 *)(lp->sdma_regs + (reg << 2)));
}
static void temac_dma_out32(struct temac_local *lp, int reg, u32 value)
{
out_be32((u32 *)(lp->sdma_regs + (reg << 2)), value);
}
static u32 temac_dma_dcr_in(struct temac_local *lp, int reg)
{
return dcr_read(lp->sdma_dcrs, reg);
}
static void temac_dma_dcr_out(struct temac_local *lp, int reg, u32 value)
{
dcr_write(lp->sdma_dcrs, reg, value);
}
static int temac_dcr_setup(struct temac_local *lp, struct platform_device *op,
struct device_node *np)
{
unsigned int dcrs;
dcrs = dcr_resource_start(np, 0);
if (dcrs != 0) {
lp->sdma_dcrs = dcr_map(np, dcrs, dcr_resource_len(np, 0));
lp->dma_in = temac_dma_dcr_in;
lp->dma_out = temac_dma_dcr_out;
dev_dbg(&op->dev, "DCR base: %x\n", dcrs);
return 0;
}
return -1;
}
static int temac_dcr_setup(struct temac_local *lp, struct platform_device *op,
struct device_node *np)
{
return -1;
}
static void temac_dma_bd_release(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
int i;
lp->dma_out(lp, DMA_CONTROL_REG, DMA_CONTROL_RST);
for (i = 0; i < RX_BD_NUM; i++) {
if (!lp->rx_skb[i])
break;
else {
dma_unmap_single(ndev->dev.parent, lp->rx_bd_v[i].phys,
XTE_MAX_JUMBO_FRAME_SIZE, DMA_FROM_DEVICE);
dev_kfree_skb(lp->rx_skb[i]);
}
}
if (lp->rx_bd_v)
dma_free_coherent(ndev->dev.parent,
sizeof(*lp->rx_bd_v) * RX_BD_NUM,
lp->rx_bd_v, lp->rx_bd_p);
if (lp->tx_bd_v)
dma_free_coherent(ndev->dev.parent,
sizeof(*lp->tx_bd_v) * TX_BD_NUM,
lp->tx_bd_v, lp->tx_bd_p);
if (lp->rx_skb)
kfree(lp->rx_skb);
}
static int temac_dma_bd_init(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
struct sk_buff *skb;
int i;
lp->rx_skb = kcalloc(RX_BD_NUM, sizeof(*lp->rx_skb), GFP_KERNEL);
if (!lp->rx_skb)
goto out;
lp->tx_bd_v = dma_alloc_coherent(ndev->dev.parent,
sizeof(*lp->tx_bd_v) * TX_BD_NUM,
&lp->tx_bd_p, GFP_KERNEL | __GFP_ZERO);
if (!lp->tx_bd_v)
goto out;
lp->rx_bd_v = dma_alloc_coherent(ndev->dev.parent,
sizeof(*lp->rx_bd_v) * RX_BD_NUM,
&lp->rx_bd_p, GFP_KERNEL | __GFP_ZERO);
if (!lp->rx_bd_v)
goto out;
for (i = 0; i < TX_BD_NUM; i++) {
lp->tx_bd_v[i].next = lp->tx_bd_p +
sizeof(*lp->tx_bd_v) * ((i + 1) % TX_BD_NUM);
}
for (i = 0; i < RX_BD_NUM; i++) {
lp->rx_bd_v[i].next = lp->rx_bd_p +
sizeof(*lp->rx_bd_v) * ((i + 1) % RX_BD_NUM);
skb = netdev_alloc_skb_ip_align(ndev,
XTE_MAX_JUMBO_FRAME_SIZE);
if (!skb)
goto out;
lp->rx_skb[i] = skb;
lp->rx_bd_v[i].phys = dma_map_single(ndev->dev.parent,
skb->data,
XTE_MAX_JUMBO_FRAME_SIZE,
DMA_FROM_DEVICE);
lp->rx_bd_v[i].len = XTE_MAX_JUMBO_FRAME_SIZE;
lp->rx_bd_v[i].app0 = STS_CTRL_APP0_IRQONEND;
}
lp->dma_out(lp, TX_CHNL_CTRL, 0x10220400 |
CHNL_CTRL_IRQ_EN |
CHNL_CTRL_IRQ_DLY_EN |
CHNL_CTRL_IRQ_COAL_EN);
lp->dma_out(lp, RX_CHNL_CTRL, 0xff070000 |
CHNL_CTRL_IRQ_EN |
CHNL_CTRL_IRQ_DLY_EN |
CHNL_CTRL_IRQ_COAL_EN |
CHNL_CTRL_IRQ_IOE);
lp->dma_out(lp, RX_CURDESC_PTR, lp->rx_bd_p);
lp->dma_out(lp, RX_TAILDESC_PTR,
lp->rx_bd_p + (sizeof(*lp->rx_bd_v) * (RX_BD_NUM - 1)));
lp->dma_out(lp, TX_CURDESC_PTR, lp->tx_bd_p);
return 0;
out:
temac_dma_bd_release(ndev);
return -ENOMEM;
}
static void temac_do_set_mac_address(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
mutex_lock(&lp->indirect_mutex);
temac_indirect_out32(lp, XTE_UAW0_OFFSET,
(ndev->dev_addr[0]) |
(ndev->dev_addr[1] << 8) |
(ndev->dev_addr[2] << 16) |
(ndev->dev_addr[3] << 24));
temac_indirect_out32(lp, XTE_UAW1_OFFSET,
(ndev->dev_addr[4] & 0x000000ff) |
(ndev->dev_addr[5] << 8));
mutex_unlock(&lp->indirect_mutex);
}
static int temac_init_mac_address(struct net_device *ndev, void *address)
{
memcpy(ndev->dev_addr, address, ETH_ALEN);
if (!is_valid_ether_addr(ndev->dev_addr))
eth_hw_addr_random(ndev);
temac_do_set_mac_address(ndev);
return 0;
}
static int temac_set_mac_address(struct net_device *ndev, void *p)
{
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(ndev->dev_addr, addr->sa_data, ETH_ALEN);
temac_do_set_mac_address(ndev);
return 0;
}
static void temac_set_multicast_list(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
u32 multi_addr_msw, multi_addr_lsw, val;
int i;
mutex_lock(&lp->indirect_mutex);
if (ndev->flags & (IFF_ALLMULTI | IFF_PROMISC) ||
netdev_mc_count(ndev) > MULTICAST_CAM_TABLE_NUM) {
ndev->flags |= IFF_PROMISC;
temac_indirect_out32(lp, XTE_AFM_OFFSET, XTE_AFM_EPPRM_MASK);
dev_info(&ndev->dev, "Promiscuous mode enabled.\n");
} else if (!netdev_mc_empty(ndev)) {
struct netdev_hw_addr *ha;
i = 0;
netdev_for_each_mc_addr(ha, ndev) {
if (i >= MULTICAST_CAM_TABLE_NUM)
break;
multi_addr_msw = ((ha->addr[3] << 24) |
(ha->addr[2] << 16) |
(ha->addr[1] << 8) |
(ha->addr[0]));
temac_indirect_out32(lp, XTE_MAW0_OFFSET,
multi_addr_msw);
multi_addr_lsw = ((ha->addr[5] << 8) |
(ha->addr[4]) | (i << 16));
temac_indirect_out32(lp, XTE_MAW1_OFFSET,
multi_addr_lsw);
i++;
}
} else {
val = temac_indirect_in32(lp, XTE_AFM_OFFSET);
temac_indirect_out32(lp, XTE_AFM_OFFSET,
val & ~XTE_AFM_EPPRM_MASK);
temac_indirect_out32(lp, XTE_MAW0_OFFSET, 0);
temac_indirect_out32(lp, XTE_MAW1_OFFSET, 0);
dev_info(&ndev->dev, "Promiscuous mode disabled.\n");
}
mutex_unlock(&lp->indirect_mutex);
}
static u32 temac_setoptions(struct net_device *ndev, u32 options)
{
struct temac_local *lp = netdev_priv(ndev);
struct temac_option *tp = &temac_options[0];
int reg;
mutex_lock(&lp->indirect_mutex);
while (tp->opt) {
reg = temac_indirect_in32(lp, tp->reg) & ~tp->m_or;
if (options & tp->opt)
reg |= tp->m_or;
temac_indirect_out32(lp, tp->reg, reg);
tp++;
}
lp->options |= options;
mutex_unlock(&lp->indirect_mutex);
return 0;
}
static void temac_device_reset(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
u32 timeout;
u32 val;
dev_dbg(&ndev->dev, "%s()\n", __func__);
mutex_lock(&lp->indirect_mutex);
temac_indirect_out32(lp, XTE_RXC1_OFFSET, XTE_RXC1_RXRST_MASK);
timeout = 1000;
while (temac_indirect_in32(lp, XTE_RXC1_OFFSET) & XTE_RXC1_RXRST_MASK) {
udelay(1);
if (--timeout == 0) {
dev_err(&ndev->dev,
"temac_device_reset RX reset timeout!!\n");
break;
}
}
temac_indirect_out32(lp, XTE_TXC_OFFSET, XTE_TXC_TXRST_MASK);
timeout = 1000;
while (temac_indirect_in32(lp, XTE_TXC_OFFSET) & XTE_TXC_TXRST_MASK) {
udelay(1);
if (--timeout == 0) {
dev_err(&ndev->dev,
"temac_device_reset TX reset timeout!!\n");
break;
}
}
val = temac_indirect_in32(lp, XTE_RXC1_OFFSET);
temac_indirect_out32(lp, XTE_RXC1_OFFSET, val & ~XTE_RXC1_RXEN_MASK);
lp->dma_out(lp, DMA_CONTROL_REG, DMA_CONTROL_RST);
timeout = 1000;
while (lp->dma_in(lp, DMA_CONTROL_REG) & DMA_CONTROL_RST) {
udelay(1);
if (--timeout == 0) {
dev_err(&ndev->dev,
"temac_device_reset DMA reset timeout!!\n");
break;
}
}
lp->dma_out(lp, DMA_CONTROL_REG, DMA_TAIL_ENABLE);
if (temac_dma_bd_init(ndev)) {
dev_err(&ndev->dev,
"temac_device_reset descriptor allocation failed\n");
}
temac_indirect_out32(lp, XTE_RXC0_OFFSET, 0);
temac_indirect_out32(lp, XTE_RXC1_OFFSET, 0);
temac_indirect_out32(lp, XTE_TXC_OFFSET, 0);
temac_indirect_out32(lp, XTE_FCC_OFFSET, XTE_FCC_RXFLO_MASK);
mutex_unlock(&lp->indirect_mutex);
temac_setoptions(ndev,
lp->options & ~(XTE_OPTION_TXEN | XTE_OPTION_RXEN));
temac_do_set_mac_address(ndev);
temac_set_multicast_list(ndev);
if (temac_setoptions(ndev, lp->options))
dev_err(&ndev->dev, "Error setting TEMAC options\n");
ndev->trans_start = jiffies;
}
void temac_adjust_link(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
struct phy_device *phy = lp->phy_dev;
u32 mii_speed;
int link_state;
link_state = phy->speed | (phy->duplex << 1) | phy->link;
mutex_lock(&lp->indirect_mutex);
if (lp->last_link != link_state) {
mii_speed = temac_indirect_in32(lp, XTE_EMCFG_OFFSET);
mii_speed &= ~XTE_EMCFG_LINKSPD_MASK;
switch (phy->speed) {
case SPEED_1000: mii_speed |= XTE_EMCFG_LINKSPD_1000; break;
case SPEED_100: mii_speed |= XTE_EMCFG_LINKSPD_100; break;
case SPEED_10: mii_speed |= XTE_EMCFG_LINKSPD_10; break;
}
temac_indirect_out32(lp, XTE_EMCFG_OFFSET, mii_speed);
lp->last_link = link_state;
phy_print_status(phy);
}
mutex_unlock(&lp->indirect_mutex);
}
static void temac_start_xmit_done(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
struct cdmac_bd *cur_p;
unsigned int stat = 0;
cur_p = &lp->tx_bd_v[lp->tx_bd_ci];
stat = cur_p->app0;
while (stat & STS_CTRL_APP0_CMPLT) {
dma_unmap_single(ndev->dev.parent, cur_p->phys, cur_p->len,
DMA_TO_DEVICE);
if (cur_p->app4)
dev_kfree_skb_irq((struct sk_buff *)cur_p->app4);
cur_p->app0 = 0;
cur_p->app1 = 0;
cur_p->app2 = 0;
cur_p->app3 = 0;
cur_p->app4 = 0;
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += cur_p->len;
lp->tx_bd_ci++;
if (lp->tx_bd_ci >= TX_BD_NUM)
lp->tx_bd_ci = 0;
cur_p = &lp->tx_bd_v[lp->tx_bd_ci];
stat = cur_p->app0;
}
netif_wake_queue(ndev);
}
static inline int temac_check_tx_bd_space(struct temac_local *lp, int num_frag)
{
struct cdmac_bd *cur_p;
int tail;
tail = lp->tx_bd_tail;
cur_p = &lp->tx_bd_v[tail];
do {
if (cur_p->app0)
return NETDEV_TX_BUSY;
tail++;
if (tail >= TX_BD_NUM)
tail = 0;
cur_p = &lp->tx_bd_v[tail];
num_frag--;
} while (num_frag >= 0);
return 0;
}
static int temac_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
struct cdmac_bd *cur_p;
dma_addr_t start_p, tail_p;
int ii;
unsigned long num_frag;
skb_frag_t *frag;
num_frag = skb_shinfo(skb)->nr_frags;
frag = &skb_shinfo(skb)->frags[0];
start_p = lp->tx_bd_p + sizeof(*lp->tx_bd_v) * lp->tx_bd_tail;
cur_p = &lp->tx_bd_v[lp->tx_bd_tail];
if (temac_check_tx_bd_space(lp, num_frag)) {
if (!netif_queue_stopped(ndev)) {
netif_stop_queue(ndev);
return NETDEV_TX_BUSY;
}
return NETDEV_TX_BUSY;
}
cur_p->app0 = 0;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
unsigned int csum_start_off = skb_checksum_start_offset(skb);
unsigned int csum_index_off = csum_start_off + skb->csum_offset;
cur_p->app0 |= 1;
cur_p->app1 = (csum_start_off << 16) | csum_index_off;
cur_p->app2 = 0;
}
cur_p->app0 |= STS_CTRL_APP0_SOP;
cur_p->len = skb_headlen(skb);
cur_p->phys = dma_map_single(ndev->dev.parent, skb->data, skb->len,
DMA_TO_DEVICE);
cur_p->app4 = (unsigned long)skb;
for (ii = 0; ii < num_frag; ii++) {
lp->tx_bd_tail++;
if (lp->tx_bd_tail >= TX_BD_NUM)
lp->tx_bd_tail = 0;
cur_p = &lp->tx_bd_v[lp->tx_bd_tail];
cur_p->phys = dma_map_single(ndev->dev.parent,
skb_frag_address(frag),
skb_frag_size(frag), DMA_TO_DEVICE);
cur_p->len = skb_frag_size(frag);
cur_p->app0 = 0;
frag++;
}
cur_p->app0 |= STS_CTRL_APP0_EOP;
tail_p = lp->tx_bd_p + sizeof(*lp->tx_bd_v) * lp->tx_bd_tail;
lp->tx_bd_tail++;
if (lp->tx_bd_tail >= TX_BD_NUM)
lp->tx_bd_tail = 0;
skb_tx_timestamp(skb);
lp->dma_out(lp, TX_TAILDESC_PTR, tail_p);
return NETDEV_TX_OK;
}
static void ll_temac_recv(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
struct sk_buff *skb, *new_skb;
unsigned int bdstat;
struct cdmac_bd *cur_p;
dma_addr_t tail_p;
int length;
unsigned long flags;
spin_lock_irqsave(&lp->rx_lock, flags);
tail_p = lp->rx_bd_p + sizeof(*lp->rx_bd_v) * lp->rx_bd_ci;
cur_p = &lp->rx_bd_v[lp->rx_bd_ci];
bdstat = cur_p->app0;
while ((bdstat & STS_CTRL_APP0_CMPLT)) {
skb = lp->rx_skb[lp->rx_bd_ci];
length = cur_p->app4 & 0x3FFF;
dma_unmap_single(ndev->dev.parent, cur_p->phys, length,
DMA_FROM_DEVICE);
skb_put(skb, length);
skb->protocol = eth_type_trans(skb, ndev);
skb_checksum_none_assert(skb);
if (((lp->temac_features & TEMAC_FEATURE_RX_CSUM) != 0) &&
(skb->protocol == __constant_htons(ETH_P_IP)) &&
(skb->len > 64)) {
skb->csum = cur_p->app3 & 0xFFFF;
skb->ip_summed = CHECKSUM_COMPLETE;
}
if (!skb_defer_rx_timestamp(skb))
netif_rx(skb);
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += length;
new_skb = netdev_alloc_skb_ip_align(ndev,
XTE_MAX_JUMBO_FRAME_SIZE);
if (!new_skb) {
spin_unlock_irqrestore(&lp->rx_lock, flags);
return;
}
cur_p->app0 = STS_CTRL_APP0_IRQONEND;
cur_p->phys = dma_map_single(ndev->dev.parent, new_skb->data,
XTE_MAX_JUMBO_FRAME_SIZE,
DMA_FROM_DEVICE);
cur_p->len = XTE_MAX_JUMBO_FRAME_SIZE;
lp->rx_skb[lp->rx_bd_ci] = new_skb;
lp->rx_bd_ci++;
if (lp->rx_bd_ci >= RX_BD_NUM)
lp->rx_bd_ci = 0;
cur_p = &lp->rx_bd_v[lp->rx_bd_ci];
bdstat = cur_p->app0;
}
lp->dma_out(lp, RX_TAILDESC_PTR, tail_p);
spin_unlock_irqrestore(&lp->rx_lock, flags);
}
static irqreturn_t ll_temac_tx_irq(int irq, void *_ndev)
{
struct net_device *ndev = _ndev;
struct temac_local *lp = netdev_priv(ndev);
unsigned int status;
status = lp->dma_in(lp, TX_IRQ_REG);
lp->dma_out(lp, TX_IRQ_REG, status);
if (status & (IRQ_COAL | IRQ_DLY))
temac_start_xmit_done(lp->ndev);
if (status & 0x080)
dev_err(&ndev->dev, "DMA error 0x%x\n", status);
return IRQ_HANDLED;
}
static irqreturn_t ll_temac_rx_irq(int irq, void *_ndev)
{
struct net_device *ndev = _ndev;
struct temac_local *lp = netdev_priv(ndev);
unsigned int status;
status = lp->dma_in(lp, RX_IRQ_REG);
lp->dma_out(lp, RX_IRQ_REG, status);
if (status & (IRQ_COAL | IRQ_DLY))
ll_temac_recv(lp->ndev);
return IRQ_HANDLED;
}
static int temac_open(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
int rc;
dev_dbg(&ndev->dev, "temac_open()\n");
if (lp->phy_node) {
lp->phy_dev = of_phy_connect(lp->ndev, lp->phy_node,
temac_adjust_link, 0, 0);
if (!lp->phy_dev) {
dev_err(lp->dev, "of_phy_connect() failed\n");
return -ENODEV;
}
phy_start(lp->phy_dev);
}
temac_device_reset(ndev);
rc = request_irq(lp->tx_irq, ll_temac_tx_irq, 0, ndev->name, ndev);
if (rc)
goto err_tx_irq;
rc = request_irq(lp->rx_irq, ll_temac_rx_irq, 0, ndev->name, ndev);
if (rc)
goto err_rx_irq;
return 0;
err_rx_irq:
free_irq(lp->tx_irq, ndev);
err_tx_irq:
if (lp->phy_dev)
phy_disconnect(lp->phy_dev);
lp->phy_dev = NULL;
dev_err(lp->dev, "request_irq() failed\n");
return rc;
}
static int temac_stop(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
dev_dbg(&ndev->dev, "temac_close()\n");
free_irq(lp->tx_irq, ndev);
free_irq(lp->rx_irq, ndev);
if (lp->phy_dev)
phy_disconnect(lp->phy_dev);
lp->phy_dev = NULL;
temac_dma_bd_release(ndev);
return 0;
}
static void
temac_poll_controller(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
disable_irq(lp->tx_irq);
disable_irq(lp->rx_irq);
ll_temac_rx_irq(lp->tx_irq, ndev);
ll_temac_tx_irq(lp->rx_irq, ndev);
enable_irq(lp->tx_irq);
enable_irq(lp->rx_irq);
}
static int temac_ioctl(struct net_device *ndev, struct ifreq *rq, int cmd)
{
struct temac_local *lp = netdev_priv(ndev);
if (!netif_running(ndev))
return -EINVAL;
if (!lp->phy_dev)
return -EINVAL;
return phy_mii_ioctl(lp->phy_dev, rq, cmd);
}
static ssize_t temac_show_llink_regs(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct temac_local *lp = netdev_priv(ndev);
int i, len = 0;
for (i = 0; i < 0x11; i++)
len += sprintf(buf + len, "%.8x%s", lp->dma_in(lp, i),
(i % 8) == 7 ? "\n" : " ");
len += sprintf(buf + len, "\n");
return len;
}
static int temac_get_settings(struct net_device *ndev, struct ethtool_cmd *cmd)
{
struct temac_local *lp = netdev_priv(ndev);
return phy_ethtool_gset(lp->phy_dev, cmd);
}
static int temac_set_settings(struct net_device *ndev, struct ethtool_cmd *cmd)
{
struct temac_local *lp = netdev_priv(ndev);
return phy_ethtool_sset(lp->phy_dev, cmd);
}
static int temac_nway_reset(struct net_device *ndev)
{
struct temac_local *lp = netdev_priv(ndev);
return phy_start_aneg(lp->phy_dev);
}
static int temac_of_probe(struct platform_device *op)
{
struct device_node *np;
struct temac_local *lp;
struct net_device *ndev;
const void *addr;
__be32 *p;
int size, rc = 0;
ndev = alloc_etherdev(sizeof(*lp));
if (!ndev)
return -ENOMEM;
ether_setup(ndev);
dev_set_drvdata(&op->dev, ndev);
SET_NETDEV_DEV(ndev, &op->dev);
ndev->flags &= ~IFF_MULTICAST;
ndev->features = NETIF_F_SG | NETIF_F_FRAGLIST;
ndev->netdev_ops = &temac_netdev_ops;
ndev->ethtool_ops = &temac_ethtool_ops;
#if 0
ndev->features |= NETIF_F_IP_CSUM;
ndev->features |= NETIF_F_HW_CSUM;
ndev->features |= NETIF_F_IPV6_CSUM;
ndev->features |= NETIF_F_HIGHDMA;
ndev->features |= NETIF_F_HW_VLAN_CTAG_TX;
ndev->features |= NETIF_F_HW_VLAN_CTAG_RX;
ndev->features |= NETIF_F_HW_VLAN_CTAG_FILTER;
ndev->features |= NETIF_F_VLAN_CHALLENGED;
ndev->features |= NETIF_F_GSO;
ndev->features |= NETIF_F_MULTI_QUEUE;
ndev->features |= NETIF_F_LRO;
#endif
lp = netdev_priv(ndev);
lp->ndev = ndev;
lp->dev = &op->dev;
lp->options = XTE_OPTION_DEFAULTS;
spin_lock_init(&lp->rx_lock);
mutex_init(&lp->indirect_mutex);
lp->regs = of_iomap(op->dev.of_node, 0);
if (!lp->regs) {
dev_err(&op->dev, "could not map temac regs.\n");
goto nodev;
}
lp->temac_features = 0;
p = (__be32 *)of_get_property(op->dev.of_node, "xlnx,txcsum", NULL);
if (p && be32_to_cpu(*p)) {
lp->temac_features |= TEMAC_FEATURE_TX_CSUM;
ndev->features |= NETIF_F_IP_CSUM;
}
p = (__be32 *)of_get_property(op->dev.of_node, "xlnx,rxcsum", NULL);
if (p && be32_to_cpu(*p))
lp->temac_features |= TEMAC_FEATURE_RX_CSUM;
np = of_parse_phandle(op->dev.of_node, "llink-connected", 0);
if (!np) {
dev_err(&op->dev, "could not find DMA node\n");
goto err_iounmap;
}
if (temac_dcr_setup(lp, op, np)) {
lp->sdma_regs = of_iomap(np, 0);
if (lp->sdma_regs) {
lp->dma_in = temac_dma_in32;
lp->dma_out = temac_dma_out32;
dev_dbg(&op->dev, "MEM base: %p\n", lp->sdma_regs);
} else {
dev_err(&op->dev, "unable to map DMA registers\n");
of_node_put(np);
goto err_iounmap;
}
}
lp->rx_irq = irq_of_parse_and_map(np, 0);
lp->tx_irq = irq_of_parse_and_map(np, 1);
of_node_put(np);
if (!lp->rx_irq || !lp->tx_irq) {
dev_err(&op->dev, "could not determine irqs\n");
rc = -ENOMEM;
goto err_iounmap_2;
}
addr = of_get_property(op->dev.of_node, "local-mac-address", &size);
if ((!addr) || (size != 6)) {
dev_err(&op->dev, "could not find MAC address\n");
rc = -ENODEV;
goto err_iounmap_2;
}
temac_init_mac_address(ndev, (void *)addr);
rc = temac_mdio_setup(lp, op->dev.of_node);
if (rc)
dev_warn(&op->dev, "error registering MDIO bus\n");
lp->phy_node = of_parse_phandle(op->dev.of_node, "phy-handle", 0);
if (lp->phy_node)
dev_dbg(lp->dev, "using PHY node %s (%p)\n", np->full_name, np);
rc = sysfs_create_group(&lp->dev->kobj, &temac_attr_group);
if (rc) {
dev_err(lp->dev, "Error creating sysfs files\n");
goto err_iounmap_2;
}
rc = register_netdev(lp->ndev);
if (rc) {
dev_err(lp->dev, "register_netdev() error (%i)\n", rc);
goto err_register_ndev;
}
return 0;
err_register_ndev:
sysfs_remove_group(&lp->dev->kobj, &temac_attr_group);
err_iounmap_2:
if (lp->sdma_regs)
iounmap(lp->sdma_regs);
err_iounmap:
iounmap(lp->regs);
nodev:
free_netdev(ndev);
ndev = NULL;
return rc;
}
static int temac_of_remove(struct platform_device *op)
{
struct net_device *ndev = dev_get_drvdata(&op->dev);
struct temac_local *lp = netdev_priv(ndev);
temac_mdio_teardown(lp);
unregister_netdev(ndev);
sysfs_remove_group(&lp->dev->kobj, &temac_attr_group);
if (lp->phy_node)
of_node_put(lp->phy_node);
lp->phy_node = NULL;
dev_set_drvdata(&op->dev, NULL);
iounmap(lp->regs);
if (lp->sdma_regs)
iounmap(lp->sdma_regs);
free_netdev(ndev);
return 0;
}
