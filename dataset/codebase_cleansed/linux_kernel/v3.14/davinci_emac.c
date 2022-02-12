static void emac_dump_regs(struct emac_priv *priv)
{
struct device *emac_dev = &priv->ndev->dev;
dev_info(emac_dev, "EMAC Basic registers\n");
if (priv->version == EMAC_VERSION_1) {
dev_info(emac_dev, "EMAC: EWCTL: %08X, EWINTTCNT: %08X\n",
emac_ctrl_read(EMAC_CTRL_EWCTL),
emac_ctrl_read(EMAC_CTRL_EWINTTCNT));
}
dev_info(emac_dev, "EMAC: EmuControl:%08X, FifoControl: %08X\n",
emac_read(EMAC_EMCONTROL), emac_read(EMAC_FIFOCONTROL));
dev_info(emac_dev, "EMAC: MBPEnable:%08X, RXUnicastSet: %08X, "\
"RXMaxLen=%08X\n", emac_read(EMAC_RXMBPENABLE),
emac_read(EMAC_RXUNICASTSET), emac_read(EMAC_RXMAXLEN));
dev_info(emac_dev, "EMAC: MacControl:%08X, MacStatus: %08X, "\
"MacConfig=%08X\n", emac_read(EMAC_MACCONTROL),
emac_read(EMAC_MACSTATUS), emac_read(EMAC_MACCONFIG));
dev_info(emac_dev, "EMAC Statistics\n");
dev_info(emac_dev, "EMAC: rx_good_frames:%d\n",
emac_read(EMAC_RXGOODFRAMES));
dev_info(emac_dev, "EMAC: rx_broadcast_frames:%d\n",
emac_read(EMAC_RXBCASTFRAMES));
dev_info(emac_dev, "EMAC: rx_multicast_frames:%d\n",
emac_read(EMAC_RXMCASTFRAMES));
dev_info(emac_dev, "EMAC: rx_pause_frames:%d\n",
emac_read(EMAC_RXPAUSEFRAMES));
dev_info(emac_dev, "EMAC: rx_crcerrors:%d\n",
emac_read(EMAC_RXCRCERRORS));
dev_info(emac_dev, "EMAC: rx_align_code_errors:%d\n",
emac_read(EMAC_RXALIGNCODEERRORS));
dev_info(emac_dev, "EMAC: rx_oversized_frames:%d\n",
emac_read(EMAC_RXOVERSIZED));
dev_info(emac_dev, "EMAC: rx_jabber_frames:%d\n",
emac_read(EMAC_RXJABBER));
dev_info(emac_dev, "EMAC: rx_undersized_frames:%d\n",
emac_read(EMAC_RXUNDERSIZED));
dev_info(emac_dev, "EMAC: rx_fragments:%d\n",
emac_read(EMAC_RXFRAGMENTS));
dev_info(emac_dev, "EMAC: rx_filtered_frames:%d\n",
emac_read(EMAC_RXFILTERED));
dev_info(emac_dev, "EMAC: rx_qos_filtered_frames:%d\n",
emac_read(EMAC_RXQOSFILTERED));
dev_info(emac_dev, "EMAC: rx_octets:%d\n",
emac_read(EMAC_RXOCTETS));
dev_info(emac_dev, "EMAC: tx_goodframes:%d\n",
emac_read(EMAC_TXGOODFRAMES));
dev_info(emac_dev, "EMAC: tx_bcastframes:%d\n",
emac_read(EMAC_TXBCASTFRAMES));
dev_info(emac_dev, "EMAC: tx_mcastframes:%d\n",
emac_read(EMAC_TXMCASTFRAMES));
dev_info(emac_dev, "EMAC: tx_pause_frames:%d\n",
emac_read(EMAC_TXPAUSEFRAMES));
dev_info(emac_dev, "EMAC: tx_deferred_frames:%d\n",
emac_read(EMAC_TXDEFERRED));
dev_info(emac_dev, "EMAC: tx_collision_frames:%d\n",
emac_read(EMAC_TXCOLLISION));
dev_info(emac_dev, "EMAC: tx_single_coll_frames:%d\n",
emac_read(EMAC_TXSINGLECOLL));
dev_info(emac_dev, "EMAC: tx_mult_coll_frames:%d\n",
emac_read(EMAC_TXMULTICOLL));
dev_info(emac_dev, "EMAC: tx_excessive_collisions:%d\n",
emac_read(EMAC_TXEXCESSIVECOLL));
dev_info(emac_dev, "EMAC: tx_late_collisions:%d\n",
emac_read(EMAC_TXLATECOLL));
dev_info(emac_dev, "EMAC: tx_underrun:%d\n",
emac_read(EMAC_TXUNDERRUN));
dev_info(emac_dev, "EMAC: tx_carrier_sense_errors:%d\n",
emac_read(EMAC_TXCARRIERSENSE));
dev_info(emac_dev, "EMAC: tx_octets:%d\n",
emac_read(EMAC_TXOCTETS));
dev_info(emac_dev, "EMAC: net_octets:%d\n",
emac_read(EMAC_NETOCTETS));
dev_info(emac_dev, "EMAC: rx_sof_overruns:%d\n",
emac_read(EMAC_RXSOFOVERRUNS));
dev_info(emac_dev, "EMAC: rx_mof_overruns:%d\n",
emac_read(EMAC_RXMOFOVERRUNS));
dev_info(emac_dev, "EMAC: rx_dma_overruns:%d\n",
emac_read(EMAC_RXDMAOVERRUNS));
cpdma_ctlr_dump(priv->dma);
}
static void emac_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, emac_version_string, sizeof(info->driver));
strlcpy(info->version, EMAC_MODULE_VERSION, sizeof(info->version));
}
static int emac_get_settings(struct net_device *ndev,
struct ethtool_cmd *ecmd)
{
struct emac_priv *priv = netdev_priv(ndev);
if (priv->phydev)
return phy_ethtool_gset(priv->phydev, ecmd);
else
return -EOPNOTSUPP;
}
static int emac_set_settings(struct net_device *ndev, struct ethtool_cmd *ecmd)
{
struct emac_priv *priv = netdev_priv(ndev);
if (priv->phydev)
return phy_ethtool_sset(priv->phydev, ecmd);
else
return -EOPNOTSUPP;
}
static int emac_get_coalesce(struct net_device *ndev,
struct ethtool_coalesce *coal)
{
struct emac_priv *priv = netdev_priv(ndev);
coal->rx_coalesce_usecs = priv->coal_intvl;
return 0;
}
static int emac_set_coalesce(struct net_device *ndev,
struct ethtool_coalesce *coal)
{
struct emac_priv *priv = netdev_priv(ndev);
u32 int_ctrl, num_interrupts = 0;
u32 prescale = 0, addnl_dvdr = 1, coal_intvl = 0;
if (!coal->rx_coalesce_usecs)
return -EINVAL;
coal_intvl = coal->rx_coalesce_usecs;
switch (priv->version) {
case EMAC_VERSION_2:
int_ctrl = emac_ctrl_read(EMAC_DM646X_CMINTCTRL);
prescale = priv->bus_freq_mhz * 4;
if (coal_intvl < EMAC_DM646X_CMINTMIN_INTVL)
coal_intvl = EMAC_DM646X_CMINTMIN_INTVL;
if (coal_intvl > EMAC_DM646X_CMINTMAX_INTVL) {
addnl_dvdr = EMAC_DM646X_INTPRESCALE_MASK / prescale;
if (addnl_dvdr > 1) {
prescale *= addnl_dvdr;
if (coal_intvl > (EMAC_DM646X_CMINTMAX_INTVL
* addnl_dvdr))
coal_intvl = (EMAC_DM646X_CMINTMAX_INTVL
* addnl_dvdr);
} else {
addnl_dvdr = 1;
coal_intvl = EMAC_DM646X_CMINTMAX_INTVL;
}
}
num_interrupts = (1000 * addnl_dvdr) / coal_intvl;
int_ctrl |= EMAC_DM646X_INTPACEEN;
int_ctrl &= (~EMAC_DM646X_INTPRESCALE_MASK);
int_ctrl |= (prescale & EMAC_DM646X_INTPRESCALE_MASK);
emac_ctrl_write(EMAC_DM646X_CMINTCTRL, int_ctrl);
emac_ctrl_write(EMAC_DM646X_CMRXINTMAX, num_interrupts);
emac_ctrl_write(EMAC_DM646X_CMTXINTMAX, num_interrupts);
break;
default:
int_ctrl = emac_ctrl_read(EMAC_CTRL_EWINTTCNT);
int_ctrl &= (~EMAC_DM644X_EWINTCNT_MASK);
prescale = coal_intvl * priv->bus_freq_mhz;
if (prescale > EMAC_DM644X_EWINTCNT_MASK) {
prescale = EMAC_DM644X_EWINTCNT_MASK;
coal_intvl = prescale / priv->bus_freq_mhz;
}
emac_ctrl_write(EMAC_CTRL_EWINTTCNT, (int_ctrl | prescale));
break;
}
printk(KERN_INFO"Set coalesce to %d usecs.\n", coal_intvl);
priv->coal_intvl = coal_intvl;
return 0;
}
static void emac_update_phystatus(struct emac_priv *priv)
{
u32 mac_control;
u32 new_duplex;
u32 cur_duplex;
struct net_device *ndev = priv->ndev;
mac_control = emac_read(EMAC_MACCONTROL);
cur_duplex = (mac_control & EMAC_MACCONTROL_FULLDUPLEXEN) ?
DUPLEX_FULL : DUPLEX_HALF;
if (priv->phydev)
new_duplex = priv->phydev->duplex;
else
new_duplex = DUPLEX_FULL;
if ((priv->link) && (new_duplex != cur_duplex)) {
priv->duplex = new_duplex;
if (DUPLEX_FULL == priv->duplex)
mac_control |= (EMAC_MACCONTROL_FULLDUPLEXEN);
else
mac_control &= ~(EMAC_MACCONTROL_FULLDUPLEXEN);
}
if (priv->speed == SPEED_1000 && (priv->version == EMAC_VERSION_2)) {
mac_control = emac_read(EMAC_MACCONTROL);
mac_control |= (EMAC_DM646X_MACCONTORL_GIG |
EMAC_DM646X_MACCONTORL_GIGFORCE);
} else {
mac_control &= ~(EMAC_DM646X_MACCONTORL_GIGFORCE |
EMAC_DM646X_MACCONTORL_GIG);
if (priv->rmii_en && (priv->speed == SPEED_100))
mac_control |= EMAC_MACCONTROL_RMIISPEED_MASK;
else
mac_control &= ~EMAC_MACCONTROL_RMIISPEED_MASK;
}
emac_write(EMAC_MACCONTROL, mac_control);
if (priv->link) {
if (!netif_carrier_ok(ndev))
netif_carrier_on(ndev);
if (netif_running(ndev) && netif_queue_stopped(ndev))
netif_wake_queue(ndev);
} else {
if (netif_carrier_ok(ndev))
netif_carrier_off(ndev);
if (!netif_queue_stopped(ndev))
netif_stop_queue(ndev);
}
}
static u32 hash_get(u8 *addr)
{
u32 hash;
u8 tmpval;
int cnt;
hash = 0;
for (cnt = 0; cnt < 2; cnt++) {
tmpval = *addr++;
hash ^= (tmpval >> 2) ^ (tmpval << 4);
tmpval = *addr++;
hash ^= (tmpval >> 4) ^ (tmpval << 2);
tmpval = *addr++;
hash ^= (tmpval >> 6) ^ (tmpval);
}
return hash & 0x3F;
}
static int hash_add(struct emac_priv *priv, u8 *mac_addr)
{
struct device *emac_dev = &priv->ndev->dev;
u32 rc = 0;
u32 hash_bit;
u32 hash_value = hash_get(mac_addr);
if (hash_value >= EMAC_NUM_MULTICAST_BITS) {
if (netif_msg_drv(priv)) {
dev_err(emac_dev, "DaVinci EMAC: hash_add(): Invalid "\
"Hash %08x, should not be greater than %08x",
hash_value, (EMAC_NUM_MULTICAST_BITS - 1));
}
return -1;
}
if (priv->multicast_hash_cnt[hash_value] == 0) {
rc = 1;
if (hash_value < 32) {
hash_bit = BIT(hash_value);
priv->mac_hash1 |= hash_bit;
} else {
hash_bit = BIT((hash_value - 32));
priv->mac_hash2 |= hash_bit;
}
}
++priv->multicast_hash_cnt[hash_value];
return rc;
}
static int hash_del(struct emac_priv *priv, u8 *mac_addr)
{
u32 hash_value;
u32 hash_bit;
hash_value = hash_get(mac_addr);
if (priv->multicast_hash_cnt[hash_value] > 0) {
--priv->multicast_hash_cnt[hash_value];
}
if (priv->multicast_hash_cnt[hash_value] > 0)
return 0;
if (hash_value < 32) {
hash_bit = BIT(hash_value);
priv->mac_hash1 &= ~hash_bit;
} else {
hash_bit = BIT((hash_value - 32));
priv->mac_hash2 &= ~hash_bit;
}
return 1;
}
static void emac_add_mcast(struct emac_priv *priv, u32 action, u8 *mac_addr)
{
struct device *emac_dev = &priv->ndev->dev;
int update = -1;
switch (action) {
case EMAC_MULTICAST_ADD:
update = hash_add(priv, mac_addr);
break;
case EMAC_MULTICAST_DEL:
update = hash_del(priv, mac_addr);
break;
case EMAC_ALL_MULTI_SET:
update = 1;
priv->mac_hash1 = EMAC_ALL_MULTI_REG_VALUE;
priv->mac_hash2 = EMAC_ALL_MULTI_REG_VALUE;
break;
case EMAC_ALL_MULTI_CLR:
update = 1;
priv->mac_hash1 = 0;
priv->mac_hash2 = 0;
memset(&(priv->multicast_hash_cnt[0]), 0,
sizeof(priv->multicast_hash_cnt[0]) *
EMAC_NUM_MULTICAST_BITS);
break;
default:
if (netif_msg_drv(priv))
dev_err(emac_dev, "DaVinci EMAC: add_mcast"\
": bad operation %d", action);
break;
}
if (update > 0) {
emac_write(EMAC_MACHASH1, priv->mac_hash1);
emac_write(EMAC_MACHASH2, priv->mac_hash2);
}
}
static void emac_dev_mcast_set(struct net_device *ndev)
{
u32 mbp_enable;
struct emac_priv *priv = netdev_priv(ndev);
mbp_enable = emac_read(EMAC_RXMBPENABLE);
if (ndev->flags & IFF_PROMISC) {
mbp_enable &= (~EMAC_MBP_PROMISCCH(EMAC_DEF_PROM_CH));
mbp_enable |= (EMAC_MBP_RXPROMISC);
} else {
mbp_enable = (mbp_enable & ~EMAC_MBP_RXPROMISC);
if ((ndev->flags & IFF_ALLMULTI) ||
netdev_mc_count(ndev) > EMAC_DEF_MAX_MULTICAST_ADDRESSES) {
mbp_enable = (mbp_enable | EMAC_MBP_RXMCAST);
emac_add_mcast(priv, EMAC_ALL_MULTI_SET, NULL);
} else if (!netdev_mc_empty(ndev)) {
struct netdev_hw_addr *ha;
mbp_enable = (mbp_enable | EMAC_MBP_RXMCAST);
emac_add_mcast(priv, EMAC_ALL_MULTI_CLR, NULL);
netdev_for_each_mc_addr(ha, ndev) {
emac_add_mcast(priv, EMAC_MULTICAST_ADD,
(u8 *) ha->addr);
}
} else {
mbp_enable = (mbp_enable & ~EMAC_MBP_RXMCAST);
emac_add_mcast(priv, EMAC_ALL_MULTI_CLR, NULL);
}
}
emac_write(EMAC_RXMBPENABLE, mbp_enable);
}
static void emac_int_disable(struct emac_priv *priv)
{
if (priv->version == EMAC_VERSION_2) {
unsigned long flags;
local_irq_save(flags);
emac_ctrl_write(EMAC_DM646X_CMRXINTEN, 0x0);
emac_ctrl_write(EMAC_DM646X_CMTXINTEN, 0x0);
if (priv->int_disable)
priv->int_disable();
local_irq_restore(flags);
} else {
emac_ctrl_write(EMAC_CTRL_EWCTL, 0x0);
}
}
static void emac_int_enable(struct emac_priv *priv)
{
if (priv->version == EMAC_VERSION_2) {
if (priv->int_enable)
priv->int_enable();
emac_ctrl_write(EMAC_DM646X_CMRXINTEN, 0xff);
emac_ctrl_write(EMAC_DM646X_CMTXINTEN, 0xff);
emac_write(EMAC_DM646X_MACEOIVECTOR,
EMAC_DM646X_MAC_EOI_C0_RXEN);
emac_write(EMAC_DM646X_MACEOIVECTOR,
EMAC_DM646X_MAC_EOI_C0_TXEN);
} else {
emac_ctrl_write(EMAC_CTRL_EWCTL, 0x1);
}
}
static irqreturn_t emac_irq(int irq, void *dev_id)
{
struct net_device *ndev = (struct net_device *)dev_id;
struct emac_priv *priv = netdev_priv(ndev);
++priv->isr_count;
if (likely(netif_running(priv->ndev))) {
emac_int_disable(priv);
napi_schedule(&priv->napi);
} else {
}
return IRQ_HANDLED;
}
static struct sk_buff *emac_rx_alloc(struct emac_priv *priv)
{
struct sk_buff *skb = netdev_alloc_skb(priv->ndev, priv->rx_buf_size);
if (WARN_ON(!skb))
return NULL;
skb_reserve(skb, NET_IP_ALIGN);
return skb;
}
static void emac_rx_handler(void *token, int len, int status)
{
struct sk_buff *skb = token;
struct net_device *ndev = skb->dev;
struct emac_priv *priv = netdev_priv(ndev);
struct device *emac_dev = &ndev->dev;
int ret;
if (unlikely(!netif_running(ndev))) {
dev_kfree_skb_any(skb);
return;
}
if (status < 0) {
ndev->stats.rx_errors++;
goto recycle;
}
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, ndev);
netif_receive_skb(skb);
ndev->stats.rx_bytes += len;
ndev->stats.rx_packets++;
skb = emac_rx_alloc(priv);
if (!skb) {
if (netif_msg_rx_err(priv) && net_ratelimit())
dev_err(emac_dev, "failed rx buffer alloc\n");
return;
}
recycle:
ret = cpdma_chan_submit(priv->rxchan, skb, skb->data,
skb_tailroom(skb), 0);
WARN_ON(ret == -ENOMEM);
if (unlikely(ret < 0))
dev_kfree_skb_any(skb);
}
static void emac_tx_handler(void *token, int len, int status)
{
struct sk_buff *skb = token;
struct net_device *ndev = skb->dev;
if (unlikely(netif_queue_stopped(ndev)))
netif_wake_queue(ndev);
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += len;
dev_kfree_skb_any(skb);
}
static int emac_dev_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct device *emac_dev = &ndev->dev;
int ret_code;
struct emac_priv *priv = netdev_priv(ndev);
if (unlikely(!priv->link)) {
if (netif_msg_tx_err(priv) && net_ratelimit())
dev_err(emac_dev, "DaVinci EMAC: No link to transmit");
goto fail_tx;
}
ret_code = skb_padto(skb, EMAC_DEF_MIN_ETHPKTSIZE);
if (unlikely(ret_code < 0)) {
if (netif_msg_tx_err(priv) && net_ratelimit())
dev_err(emac_dev, "DaVinci EMAC: packet pad failed");
goto fail_tx;
}
skb_tx_timestamp(skb);
ret_code = cpdma_chan_submit(priv->txchan, skb, skb->data, skb->len,
0);
if (unlikely(ret_code != 0)) {
if (netif_msg_tx_err(priv) && net_ratelimit())
dev_err(emac_dev, "DaVinci EMAC: desc submit failed");
goto fail_tx;
}
if (unlikely(!cpdma_check_free_tx_desc(priv->txchan)))
netif_stop_queue(ndev);
return NETDEV_TX_OK;
fail_tx:
ndev->stats.tx_dropped++;
netif_stop_queue(ndev);
return NETDEV_TX_BUSY;
}
static void emac_dev_tx_timeout(struct net_device *ndev)
{
struct emac_priv *priv = netdev_priv(ndev);
struct device *emac_dev = &ndev->dev;
if (netif_msg_tx_err(priv))
dev_err(emac_dev, "DaVinci EMAC: xmit timeout, restarting TX");
emac_dump_regs(priv);
ndev->stats.tx_errors++;
emac_int_disable(priv);
cpdma_chan_stop(priv->txchan);
cpdma_chan_start(priv->txchan);
emac_int_enable(priv);
}
static void emac_set_type0addr(struct emac_priv *priv, u32 ch, char *mac_addr)
{
u32 val;
val = ((mac_addr[5] << 8) | (mac_addr[4]));
emac_write(EMAC_MACSRCADDRLO, val);
val = ((mac_addr[3] << 24) | (mac_addr[2] << 16) | \
(mac_addr[1] << 8) | (mac_addr[0]));
emac_write(EMAC_MACSRCADDRHI, val);
val = emac_read(EMAC_RXUNICASTSET);
val |= BIT(ch);
emac_write(EMAC_RXUNICASTSET, val);
val = emac_read(EMAC_RXUNICASTCLEAR);
val &= ~BIT(ch);
emac_write(EMAC_RXUNICASTCLEAR, val);
}
static void emac_set_type1addr(struct emac_priv *priv, u32 ch, char *mac_addr)
{
u32 val;
emac_write(EMAC_MACINDEX, ch);
val = ((mac_addr[5] << 8) | mac_addr[4]);
emac_write(EMAC_MACADDRLO, val);
val = ((mac_addr[3] << 24) | (mac_addr[2] << 16) | \
(mac_addr[1] << 8) | (mac_addr[0]));
emac_write(EMAC_MACADDRHI, val);
emac_set_type0addr(priv, ch, mac_addr);
}
static void emac_set_type2addr(struct emac_priv *priv, u32 ch,
char *mac_addr, int index, int match)
{
u32 val;
emac_write(EMAC_MACINDEX, index);
val = ((mac_addr[3] << 24) | (mac_addr[2] << 16) | \
(mac_addr[1] << 8) | (mac_addr[0]));
emac_write(EMAC_MACADDRHI, val);
val = ((mac_addr[5] << 8) | mac_addr[4] | ((ch & 0x7) << 16) | \
(match << 19) | BIT(20));
emac_write(EMAC_MACADDRLO, val);
emac_set_type0addr(priv, ch, mac_addr);
}
static void emac_setmac(struct emac_priv *priv, u32 ch, char *mac_addr)
{
struct device *emac_dev = &priv->ndev->dev;
if (priv->rx_addr_type == 0) {
emac_set_type0addr(priv, ch, mac_addr);
} else if (priv->rx_addr_type == 1) {
u32 cnt;
for (cnt = 0; cnt < EMAC_MAX_TXRX_CHANNELS; cnt++)
emac_set_type1addr(priv, ch, mac_addr);
} else if (priv->rx_addr_type == 2) {
emac_set_type2addr(priv, ch, mac_addr, ch, 1);
emac_set_type0addr(priv, ch, mac_addr);
} else {
if (netif_msg_drv(priv))
dev_err(emac_dev, "DaVinci EMAC: Wrong addressing\n");
}
}
static int emac_dev_setmac_addr(struct net_device *ndev, void *addr)
{
struct emac_priv *priv = netdev_priv(ndev);
struct device *emac_dev = &priv->ndev->dev;
struct sockaddr *sa = addr;
if (!is_valid_ether_addr(sa->sa_data))
return -EADDRNOTAVAIL;
memcpy(priv->mac_addr, sa->sa_data, ndev->addr_len);
memcpy(ndev->dev_addr, sa->sa_data, ndev->addr_len);
if (netif_running(ndev)) {
emac_setmac(priv, EMAC_DEF_RX_CH, priv->mac_addr);
}
if (netif_msg_drv(priv))
dev_notice(emac_dev, "DaVinci EMAC: emac_dev_setmac_addr %pM\n",
priv->mac_addr);
return 0;
}
static int emac_hw_enable(struct emac_priv *priv)
{
u32 val, mbp_enable, mac_control;
emac_write(EMAC_SOFTRESET, 1);
while (emac_read(EMAC_SOFTRESET))
cpu_relax();
emac_int_disable(priv);
mac_control =
(((EMAC_DEF_TXPRIO_FIXED) ? (EMAC_MACCONTROL_TXPTYPE) : 0x0) |
((priv->speed == 1000) ? EMAC_MACCONTROL_GIGABITEN : 0x0) |
((EMAC_DEF_TXPACING_EN) ? (EMAC_MACCONTROL_TXPACEEN) : 0x0) |
((priv->duplex == DUPLEX_FULL) ? 0x1 : 0));
emac_write(EMAC_MACCONTROL, mac_control);
mbp_enable =
(((EMAC_DEF_PASS_CRC) ? (EMAC_RXMBP_PASSCRC_MASK) : 0x0) |
((EMAC_DEF_QOS_EN) ? (EMAC_RXMBP_QOSEN_MASK) : 0x0) |
((EMAC_DEF_NO_BUFF_CHAIN) ? (EMAC_RXMBP_NOCHAIN_MASK) : 0x0) |
((EMAC_DEF_MACCTRL_FRAME_EN) ? (EMAC_RXMBP_CMFEN_MASK) : 0x0) |
((EMAC_DEF_SHORT_FRAME_EN) ? (EMAC_RXMBP_CSFEN_MASK) : 0x0) |
((EMAC_DEF_ERROR_FRAME_EN) ? (EMAC_RXMBP_CEFEN_MASK) : 0x0) |
((EMAC_DEF_PROM_EN) ? (EMAC_RXMBP_CAFEN_MASK) : 0x0) |
((EMAC_DEF_PROM_CH & EMAC_RXMBP_CHMASK) << \
EMAC_RXMBP_PROMCH_SHIFT) |
((EMAC_DEF_BCAST_EN) ? (EMAC_RXMBP_BROADEN_MASK) : 0x0) |
((EMAC_DEF_BCAST_CH & EMAC_RXMBP_CHMASK) << \
EMAC_RXMBP_BROADCH_SHIFT) |
((EMAC_DEF_MCAST_EN) ? (EMAC_RXMBP_MULTIEN_MASK) : 0x0) |
((EMAC_DEF_MCAST_CH & EMAC_RXMBP_CHMASK) << \
EMAC_RXMBP_MULTICH_SHIFT));
emac_write(EMAC_RXMBPENABLE, mbp_enable);
emac_write(EMAC_RXMAXLEN, (EMAC_DEF_MAX_FRAME_SIZE &
EMAC_RX_MAX_LEN_MASK));
emac_write(EMAC_RXBUFFEROFFSET, (EMAC_DEF_BUFFER_OFFSET &
EMAC_RX_BUFFER_OFFSET_MASK));
emac_write(EMAC_RXFILTERLOWTHRESH, 0);
emac_write(EMAC_RXUNICASTCLEAR, EMAC_RX_UNICAST_CLEAR_ALL);
priv->rx_addr_type = (emac_read(EMAC_MACCONFIG) >> 8) & 0xFF;
emac_write(EMAC_MACINTMASKSET, EMAC_MAC_HOST_ERR_INTMASK_VAL);
emac_setmac(priv, EMAC_DEF_RX_CH, priv->mac_addr);
val = emac_read(EMAC_MACCONTROL);
val |= (EMAC_MACCONTROL_GMIIEN);
emac_write(EMAC_MACCONTROL, val);
napi_enable(&priv->napi);
emac_int_enable(priv);
return 0;
}
static int emac_poll(struct napi_struct *napi, int budget)
{
unsigned int mask;
struct emac_priv *priv = container_of(napi, struct emac_priv, napi);
struct net_device *ndev = priv->ndev;
struct device *emac_dev = &ndev->dev;
u32 status = 0;
u32 num_tx_pkts = 0, num_rx_pkts = 0;
status = emac_read(EMAC_MACINVECTOR);
mask = EMAC_DM644X_MAC_IN_VECTOR_TX_INT_VEC;
if (priv->version == EMAC_VERSION_2)
mask = EMAC_DM646X_MAC_IN_VECTOR_TX_INT_VEC;
if (status & mask) {
num_tx_pkts = cpdma_chan_process(priv->txchan,
EMAC_DEF_TX_MAX_SERVICE);
}
mask = EMAC_DM644X_MAC_IN_VECTOR_RX_INT_VEC;
if (priv->version == EMAC_VERSION_2)
mask = EMAC_DM646X_MAC_IN_VECTOR_RX_INT_VEC;
if (status & mask) {
num_rx_pkts = cpdma_chan_process(priv->rxchan, budget);
}
mask = EMAC_DM644X_MAC_IN_VECTOR_HOST_INT;
if (priv->version == EMAC_VERSION_2)
mask = EMAC_DM646X_MAC_IN_VECTOR_HOST_INT;
if (unlikely(status & mask)) {
u32 ch, cause;
dev_err(emac_dev, "DaVinci EMAC: Fatal Hardware Error\n");
netif_stop_queue(ndev);
napi_disable(&priv->napi);
status = emac_read(EMAC_MACSTATUS);
cause = ((status & EMAC_MACSTATUS_TXERRCODE_MASK) >>
EMAC_MACSTATUS_TXERRCODE_SHIFT);
if (cause) {
ch = ((status & EMAC_MACSTATUS_TXERRCH_MASK) >>
EMAC_MACSTATUS_TXERRCH_SHIFT);
if (net_ratelimit()) {
dev_err(emac_dev, "TX Host error %s on ch=%d\n",
&emac_txhost_errcodes[cause][0], ch);
}
}
cause = ((status & EMAC_MACSTATUS_RXERRCODE_MASK) >>
EMAC_MACSTATUS_RXERRCODE_SHIFT);
if (cause) {
ch = ((status & EMAC_MACSTATUS_RXERRCH_MASK) >>
EMAC_MACSTATUS_RXERRCH_SHIFT);
if (netif_msg_hw(priv) && net_ratelimit())
dev_err(emac_dev, "RX Host error %s on ch=%d\n",
&emac_rxhost_errcodes[cause][0], ch);
}
} else if (num_rx_pkts < budget) {
napi_complete(napi);
emac_int_enable(priv);
}
return num_rx_pkts;
}
static void emac_poll_controller(struct net_device *ndev)
{
struct emac_priv *priv = netdev_priv(ndev);
emac_int_disable(priv);
emac_irq(ndev->irq, ndev);
emac_int_enable(priv);
}
static void emac_adjust_link(struct net_device *ndev)
{
struct emac_priv *priv = netdev_priv(ndev);
struct phy_device *phydev = priv->phydev;
unsigned long flags;
int new_state = 0;
spin_lock_irqsave(&priv->lock, flags);
if (phydev->link) {
if (phydev->duplex != priv->duplex) {
new_state = 1;
priv->duplex = phydev->duplex;
}
if (phydev->speed != priv->speed) {
new_state = 1;
priv->speed = phydev->speed;
}
if (!priv->link) {
new_state = 1;
priv->link = 1;
}
} else if (priv->link) {
new_state = 1;
priv->link = 0;
priv->speed = 0;
priv->duplex = ~0;
}
if (new_state) {
emac_update_phystatus(priv);
phy_print_status(priv->phydev);
}
spin_unlock_irqrestore(&priv->lock, flags);
}
static int emac_devioctl(struct net_device *ndev, struct ifreq *ifrq, int cmd)
{
struct emac_priv *priv = netdev_priv(ndev);
if (!(netif_running(ndev)))
return -EINVAL;
return phy_mii_ioctl(priv->phydev, ifrq, cmd);
}
static int match_first_device(struct device *dev, void *data)
{
return !strncmp(dev_name(dev), "davinci_mdio", 12);
}
static int emac_dev_open(struct net_device *ndev)
{
struct device *emac_dev = &ndev->dev;
u32 cnt;
struct resource *res;
int q, m, ret;
int res_num = 0, irq_num = 0;
int i = 0;
struct emac_priv *priv = netdev_priv(ndev);
pm_runtime_get(&priv->pdev->dev);
netif_carrier_off(ndev);
for (cnt = 0; cnt < ETH_ALEN; cnt++)
ndev->dev_addr[cnt] = priv->mac_addr[cnt];
priv->rx_buf_size = EMAC_DEF_MAX_FRAME_SIZE + NET_IP_ALIGN;
priv->mac_hash1 = 0;
priv->mac_hash2 = 0;
emac_write(EMAC_MACHASH1, 0);
emac_write(EMAC_MACHASH2, 0);
for (i = 0; i < EMAC_DEF_RX_NUM_DESC; i++) {
struct sk_buff *skb = emac_rx_alloc(priv);
if (!skb)
break;
ret = cpdma_chan_submit(priv->rxchan, skb, skb->data,
skb_tailroom(skb), 0);
if (WARN_ON(ret < 0))
break;
}
while ((res = platform_get_resource(priv->pdev, IORESOURCE_IRQ,
res_num))) {
for (irq_num = res->start; irq_num <= res->end; irq_num++) {
dev_err(emac_dev, "Request IRQ %d\n", irq_num);
if (request_irq(irq_num, emac_irq, 0, ndev->name,
ndev)) {
dev_err(emac_dev,
"DaVinci EMAC: request_irq() failed\n");
ret = -EBUSY;
goto rollback;
}
}
res_num++;
}
res_num--;
irq_num--;
emac_hw_enable(priv);
if (priv->coal_intvl != 0) {
struct ethtool_coalesce coal;
coal.rx_coalesce_usecs = (priv->coal_intvl << 4);
emac_set_coalesce(ndev, &coal);
}
cpdma_ctlr_start(priv->dma);
priv->phydev = NULL;
if (!priv->phy_id) {
struct device *phy;
phy = bus_find_device(&mdio_bus_type, NULL, NULL,
match_first_device);
if (phy)
priv->phy_id = dev_name(phy);
}
if (priv->phy_id && *priv->phy_id) {
priv->phydev = phy_connect(ndev, priv->phy_id,
&emac_adjust_link,
PHY_INTERFACE_MODE_MII);
if (IS_ERR(priv->phydev)) {
dev_err(emac_dev, "could not connect to phy %s\n",
priv->phy_id);
ret = PTR_ERR(priv->phydev);
priv->phydev = NULL;
goto err;
}
priv->link = 0;
priv->speed = 0;
priv->duplex = ~0;
dev_info(emac_dev, "attached PHY driver [%s] "
"(mii_bus:phy_addr=%s, id=%x)\n",
priv->phydev->drv->name, dev_name(&priv->phydev->dev),
priv->phydev->phy_id);
} else {
dev_notice(emac_dev, "no phy, defaulting to 100/full\n");
priv->link = 1;
priv->speed = SPEED_100;
priv->duplex = DUPLEX_FULL;
emac_update_phystatus(priv);
}
if (!netif_running(ndev))
emac_dump_regs(priv);
if (netif_msg_drv(priv))
dev_notice(emac_dev, "DaVinci EMAC: Opened %s\n", ndev->name);
if (priv->phydev)
phy_start(priv->phydev);
return 0;
err:
emac_int_disable(priv);
napi_disable(&priv->napi);
rollback:
for (q = res_num; q >= 0; q--) {
res = platform_get_resource(priv->pdev, IORESOURCE_IRQ, q);
if (q != res_num)
irq_num = res->end;
for (m = irq_num; m >= res->start; m--)
free_irq(m, ndev);
}
cpdma_ctlr_stop(priv->dma);
pm_runtime_put(&priv->pdev->dev);
return ret;
}
static int emac_dev_stop(struct net_device *ndev)
{
struct resource *res;
int i = 0;
int irq_num;
struct emac_priv *priv = netdev_priv(ndev);
struct device *emac_dev = &ndev->dev;
netif_stop_queue(ndev);
napi_disable(&priv->napi);
netif_carrier_off(ndev);
emac_int_disable(priv);
cpdma_ctlr_stop(priv->dma);
emac_write(EMAC_SOFTRESET, 1);
if (priv->phydev)
phy_disconnect(priv->phydev);
while ((res = platform_get_resource(priv->pdev, IORESOURCE_IRQ, i))) {
for (irq_num = res->start; irq_num <= res->end; irq_num++)
free_irq(irq_num, priv->ndev);
i++;
}
if (netif_msg_drv(priv))
dev_notice(emac_dev, "DaVinci EMAC: %s stopped\n", ndev->name);
pm_runtime_put(&priv->pdev->dev);
return 0;
}
static struct net_device_stats *emac_dev_getnetstats(struct net_device *ndev)
{
struct emac_priv *priv = netdev_priv(ndev);
u32 mac_control;
u32 stats_clear_mask;
mac_control = emac_read(EMAC_MACCONTROL);
if (mac_control & EMAC_MACCONTROL_GMIIEN)
stats_clear_mask = EMAC_STATS_CLR_MASK;
else
stats_clear_mask = 0;
ndev->stats.multicast += emac_read(EMAC_RXMCASTFRAMES);
emac_write(EMAC_RXMCASTFRAMES, stats_clear_mask);
ndev->stats.collisions += (emac_read(EMAC_TXCOLLISION) +
emac_read(EMAC_TXSINGLECOLL) +
emac_read(EMAC_TXMULTICOLL));
emac_write(EMAC_TXCOLLISION, stats_clear_mask);
emac_write(EMAC_TXSINGLECOLL, stats_clear_mask);
emac_write(EMAC_TXMULTICOLL, stats_clear_mask);
ndev->stats.rx_length_errors += (emac_read(EMAC_RXOVERSIZED) +
emac_read(EMAC_RXJABBER) +
emac_read(EMAC_RXUNDERSIZED));
emac_write(EMAC_RXOVERSIZED, stats_clear_mask);
emac_write(EMAC_RXJABBER, stats_clear_mask);
emac_write(EMAC_RXUNDERSIZED, stats_clear_mask);
ndev->stats.rx_over_errors += (emac_read(EMAC_RXSOFOVERRUNS) +
emac_read(EMAC_RXMOFOVERRUNS));
emac_write(EMAC_RXSOFOVERRUNS, stats_clear_mask);
emac_write(EMAC_RXMOFOVERRUNS, stats_clear_mask);
ndev->stats.rx_fifo_errors += emac_read(EMAC_RXDMAOVERRUNS);
emac_write(EMAC_RXDMAOVERRUNS, stats_clear_mask);
ndev->stats.tx_carrier_errors +=
emac_read(EMAC_TXCARRIERSENSE);
emac_write(EMAC_TXCARRIERSENSE, stats_clear_mask);
ndev->stats.tx_fifo_errors += emac_read(EMAC_TXUNDERRUN);
emac_write(EMAC_TXUNDERRUN, stats_clear_mask);
return &ndev->stats;
}
static struct emac_platform_data *
davinci_emac_of_get_pdata(struct platform_device *pdev, struct emac_priv *priv)
{
struct device_node *np;
const struct of_device_id *match;
const struct emac_platform_data *auxdata;
struct emac_platform_data *pdata = NULL;
const u8 *mac_addr;
if (!IS_ENABLED(CONFIG_OF) || !pdev->dev.of_node)
return dev_get_platdata(&pdev->dev);
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
np = pdev->dev.of_node;
pdata->version = EMAC_VERSION_2;
if (!is_valid_ether_addr(pdata->mac_addr)) {
mac_addr = of_get_mac_address(np);
if (mac_addr)
memcpy(pdata->mac_addr, mac_addr, ETH_ALEN);
}
of_property_read_u32(np, "ti,davinci-ctrl-reg-offset",
&pdata->ctrl_reg_offset);
of_property_read_u32(np, "ti,davinci-ctrl-mod-reg-offset",
&pdata->ctrl_mod_reg_offset);
of_property_read_u32(np, "ti,davinci-ctrl-ram-offset",
&pdata->ctrl_ram_offset);
of_property_read_u32(np, "ti,davinci-ctrl-ram-size",
&pdata->ctrl_ram_size);
of_property_read_u8(np, "ti,davinci-rmii-en", &pdata->rmii_en);
pdata->no_bd_ram = of_property_read_bool(np, "ti,davinci-no-bd-ram");
priv->phy_node = of_parse_phandle(np, "phy-handle", 0);
if (!priv->phy_node)
pdata->phy_id = NULL;
auxdata = pdev->dev.platform_data;
if (auxdata) {
pdata->interrupt_enable = auxdata->interrupt_enable;
pdata->interrupt_disable = auxdata->interrupt_disable;
}
match = of_match_device(davinci_emac_of_match, &pdev->dev);
if (match && match->data) {
auxdata = match->data;
pdata->version = auxdata->version;
pdata->hw_ram_addr = auxdata->hw_ram_addr;
}
pdev->dev.platform_data = pdata;
return pdata;
}
static int davinci_emac_probe(struct platform_device *pdev)
{
int rc = 0;
struct resource *res;
struct net_device *ndev;
struct emac_priv *priv;
unsigned long hw_ram_addr;
struct emac_platform_data *pdata;
struct device *emac_dev;
struct cpdma_params dma_params;
struct clk *emac_clk;
unsigned long emac_bus_frequency;
emac_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(emac_clk)) {
dev_err(&pdev->dev, "failed to get EMAC clock\n");
return -EBUSY;
}
emac_bus_frequency = clk_get_rate(emac_clk);
ndev = alloc_etherdev(sizeof(struct emac_priv));
if (!ndev)
return -ENOMEM;
platform_set_drvdata(pdev, ndev);
priv = netdev_priv(ndev);
priv->pdev = pdev;
priv->ndev = ndev;
priv->msg_enable = netif_msg_init(debug_level, DAVINCI_EMAC_DEBUG);
spin_lock_init(&priv->lock);
pdata = davinci_emac_of_get_pdata(pdev, priv);
if (!pdata) {
dev_err(&pdev->dev, "no platform data\n");
rc = -ENODEV;
goto no_pdata;
}
memcpy(priv->mac_addr, pdata->mac_addr, ETH_ALEN);
priv->phy_id = pdata->phy_id;
priv->rmii_en = pdata->rmii_en;
priv->version = pdata->version;
priv->int_enable = pdata->interrupt_enable;
priv->int_disable = pdata->interrupt_disable;
priv->coal_intvl = 0;
priv->bus_freq_mhz = (u32)(emac_bus_frequency / 1000000);
emac_dev = &ndev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->emac_base_phys = res->start + pdata->ctrl_reg_offset;
priv->remap_addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->remap_addr)) {
rc = PTR_ERR(priv->remap_addr);
goto no_pdata;
}
priv->emac_base = priv->remap_addr + pdata->ctrl_reg_offset;
ndev->base_addr = (unsigned long)priv->remap_addr;
priv->ctrl_base = priv->remap_addr + pdata->ctrl_mod_reg_offset;
hw_ram_addr = pdata->hw_ram_addr;
if (!hw_ram_addr)
hw_ram_addr = (u32 __force)res->start + pdata->ctrl_ram_offset;
memset(&dma_params, 0, sizeof(dma_params));
dma_params.dev = emac_dev;
dma_params.dmaregs = priv->emac_base;
dma_params.rxthresh = priv->emac_base + 0x120;
dma_params.rxfree = priv->emac_base + 0x140;
dma_params.txhdp = priv->emac_base + 0x600;
dma_params.rxhdp = priv->emac_base + 0x620;
dma_params.txcp = priv->emac_base + 0x640;
dma_params.rxcp = priv->emac_base + 0x660;
dma_params.num_chan = EMAC_MAX_TXRX_CHANNELS;
dma_params.min_packet_size = EMAC_DEF_MIN_ETHPKTSIZE;
dma_params.desc_hw_addr = hw_ram_addr;
dma_params.desc_mem_size = pdata->ctrl_ram_size;
dma_params.desc_align = 16;
dma_params.desc_mem_phys = pdata->no_bd_ram ? 0 :
(u32 __force)res->start + pdata->ctrl_ram_offset;
priv->dma = cpdma_ctlr_create(&dma_params);
if (!priv->dma) {
dev_err(&pdev->dev, "error initializing DMA\n");
rc = -ENOMEM;
goto no_pdata;
}
priv->txchan = cpdma_chan_create(priv->dma, tx_chan_num(EMAC_DEF_TX_CH),
emac_tx_handler);
priv->rxchan = cpdma_chan_create(priv->dma, rx_chan_num(EMAC_DEF_RX_CH),
emac_rx_handler);
if (WARN_ON(!priv->txchan || !priv->rxchan)) {
rc = -ENOMEM;
goto no_cpdma_chan;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(&pdev->dev, "error getting irq res\n");
rc = -ENOENT;
goto no_cpdma_chan;
}
ndev->irq = res->start;
if (!is_valid_ether_addr(priv->mac_addr)) {
eth_hw_addr_random(ndev);
memcpy(priv->mac_addr, ndev->dev_addr, ndev->addr_len);
dev_warn(&pdev->dev, "using random MAC addr: %pM\n",
priv->mac_addr);
}
ndev->netdev_ops = &emac_netdev_ops;
SET_ETHTOOL_OPS(ndev, &ethtool_ops);
netif_napi_add(ndev, &priv->napi, emac_poll, EMAC_POLL_WEIGHT);
SET_NETDEV_DEV(ndev, &pdev->dev);
rc = register_netdev(ndev);
if (rc) {
dev_err(&pdev->dev, "error in register_netdev\n");
rc = -ENODEV;
goto no_cpdma_chan;
}
if (netif_msg_probe(priv)) {
dev_notice(emac_dev, "DaVinci EMAC Probe found device "\
"(regs: %p, irq: %d)\n",
(void *)priv->emac_base_phys, ndev->irq);
}
pm_runtime_enable(&pdev->dev);
pm_runtime_resume(&pdev->dev);
return 0;
no_cpdma_chan:
if (priv->txchan)
cpdma_chan_destroy(priv->txchan);
if (priv->rxchan)
cpdma_chan_destroy(priv->rxchan);
cpdma_ctlr_destroy(priv->dma);
no_pdata:
free_netdev(ndev);
return rc;
}
static int davinci_emac_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct emac_priv *priv = netdev_priv(ndev);
dev_notice(&ndev->dev, "DaVinci EMAC: davinci_emac_remove()\n");
if (priv->txchan)
cpdma_chan_destroy(priv->txchan);
if (priv->rxchan)
cpdma_chan_destroy(priv->rxchan);
cpdma_ctlr_destroy(priv->dma);
unregister_netdev(ndev);
free_netdev(ndev);
return 0;
}
static int davinci_emac_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *ndev = platform_get_drvdata(pdev);
if (netif_running(ndev))
emac_dev_stop(ndev);
return 0;
}
static int davinci_emac_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *ndev = platform_get_drvdata(pdev);
if (netif_running(ndev))
emac_dev_open(ndev);
return 0;
}
static int __init davinci_emac_init(void)
{
return platform_driver_register(&davinci_emac_driver);
}
static void __exit davinci_emac_exit(void)
{
platform_driver_unregister(&davinci_emac_driver);
}
