static void nps_enet_clean_rx_fifo(struct net_device *ndev, u32 frame_len)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
u32 i, len = DIV_ROUND_UP(frame_len, sizeof(u32));
for (i = 0; i < len; i++)
nps_enet_reg_get(priv, NPS_ENET_REG_RX_BUF);
}
static void nps_enet_read_rx_fifo(struct net_device *ndev,
unsigned char *dst, u32 length)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
s32 i, last = length & (sizeof(u32) - 1);
u32 *reg = (u32 *)dst, len = length / sizeof(u32);
bool dst_is_aligned = IS_ALIGNED((unsigned long)dst, sizeof(u32));
if (dst_is_aligned) {
ioread32_rep(priv->regs_base + NPS_ENET_REG_RX_BUF, reg, len);
reg += len;
}
else {
for (i = 0; i < len; i++, reg++) {
u32 buf = nps_enet_reg_get(priv, NPS_ENET_REG_RX_BUF);
put_unaligned_be32(buf, reg);
}
}
if (last) {
u32 buf;
ioread32_rep(priv->regs_base + NPS_ENET_REG_RX_BUF, &buf, 1);
memcpy((u8 *)reg, &buf, last);
}
}
static u32 nps_enet_rx_handler(struct net_device *ndev)
{
u32 frame_len, err = 0;
u32 work_done = 0;
struct nps_enet_priv *priv = netdev_priv(ndev);
struct sk_buff *skb;
u32 rx_ctrl_value = nps_enet_reg_get(priv, NPS_ENET_REG_RX_CTL);
u32 rx_ctrl_cr = (rx_ctrl_value & RX_CTL_CR_MASK) >> RX_CTL_CR_SHIFT;
u32 rx_ctrl_er = (rx_ctrl_value & RX_CTL_ER_MASK) >> RX_CTL_ER_SHIFT;
u32 rx_ctrl_crc = (rx_ctrl_value & RX_CTL_CRC_MASK) >> RX_CTL_CRC_SHIFT;
frame_len = (rx_ctrl_value & RX_CTL_NR_MASK) >> RX_CTL_NR_SHIFT;
if (!rx_ctrl_cr)
return work_done;
work_done++;
if (rx_ctrl_er) {
ndev->stats.rx_errors++;
err = 1;
}
if (rx_ctrl_crc) {
ndev->stats.rx_crc_errors++;
ndev->stats.rx_dropped++;
err = 1;
}
if (unlikely(frame_len < ETH_ZLEN)) {
ndev->stats.rx_length_errors++;
ndev->stats.rx_dropped++;
err = 1;
}
if (err)
goto rx_irq_clean;
skb = netdev_alloc_skb_ip_align(ndev, frame_len);
if (unlikely(!skb)) {
ndev->stats.rx_errors++;
ndev->stats.rx_dropped++;
goto rx_irq_clean;
}
nps_enet_read_rx_fifo(ndev, skb->data, frame_len);
skb_put(skb, frame_len);
skb->protocol = eth_type_trans(skb, ndev);
skb->ip_summed = CHECKSUM_UNNECESSARY;
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += frame_len;
netif_receive_skb(skb);
goto rx_irq_frame_done;
rx_irq_clean:
nps_enet_clean_rx_fifo(ndev, frame_len);
rx_irq_frame_done:
nps_enet_reg_set(priv, NPS_ENET_REG_RX_CTL, 0);
return work_done;
}
static void nps_enet_tx_handler(struct net_device *ndev)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
u32 tx_ctrl_value = nps_enet_reg_get(priv, NPS_ENET_REG_TX_CTL);
u32 tx_ctrl_ct = (tx_ctrl_value & TX_CTL_CT_MASK) >> TX_CTL_CT_SHIFT;
u32 tx_ctrl_et = (tx_ctrl_value & TX_CTL_ET_MASK) >> TX_CTL_ET_SHIFT;
u32 tx_ctrl_nt = (tx_ctrl_value & TX_CTL_NT_MASK) >> TX_CTL_NT_SHIFT;
if (!priv->tx_skb || tx_ctrl_ct)
return;
nps_enet_reg_set(priv, NPS_ENET_REG_TX_CTL, 0);
if (unlikely(tx_ctrl_et)) {
ndev->stats.tx_errors++;
} else {
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += tx_ctrl_nt;
}
dev_kfree_skb(priv->tx_skb);
priv->tx_skb = NULL;
if (netif_queue_stopped(ndev))
netif_wake_queue(ndev);
}
static int nps_enet_poll(struct napi_struct *napi, int budget)
{
struct net_device *ndev = napi->dev;
struct nps_enet_priv *priv = netdev_priv(ndev);
u32 work_done;
nps_enet_tx_handler(ndev);
work_done = nps_enet_rx_handler(ndev);
if (work_done < budget) {
u32 buf_int_enable_value = 0;
u32 tx_ctrl_value = nps_enet_reg_get(priv, NPS_ENET_REG_TX_CTL);
u32 tx_ctrl_ct =
(tx_ctrl_value & TX_CTL_CT_MASK) >> TX_CTL_CT_SHIFT;
napi_complete(napi);
buf_int_enable_value |= NPS_ENET_ENABLE << RX_RDY_SHIFT;
buf_int_enable_value |= NPS_ENET_ENABLE << TX_DONE_SHIFT;
nps_enet_reg_set(priv, NPS_ENET_REG_BUF_INT_ENABLE,
buf_int_enable_value);
if (priv->tx_skb && !tx_ctrl_ct)
napi_reschedule(napi);
}
return work_done;
}
static irqreturn_t nps_enet_irq_handler(s32 irq, void *dev_instance)
{
struct net_device *ndev = dev_instance;
struct nps_enet_priv *priv = netdev_priv(ndev);
u32 rx_ctrl_value = nps_enet_reg_get(priv, NPS_ENET_REG_RX_CTL);
u32 tx_ctrl_value = nps_enet_reg_get(priv, NPS_ENET_REG_TX_CTL);
u32 tx_ctrl_ct = (tx_ctrl_value & TX_CTL_CT_MASK) >> TX_CTL_CT_SHIFT;
u32 rx_ctrl_cr = (rx_ctrl_value & RX_CTL_CR_MASK) >> RX_CTL_CR_SHIFT;
if ((!tx_ctrl_ct && priv->tx_skb) || rx_ctrl_cr)
if (likely(napi_schedule_prep(&priv->napi))) {
nps_enet_reg_set(priv, NPS_ENET_REG_BUF_INT_ENABLE, 0);
__napi_schedule(&priv->napi);
}
return IRQ_HANDLED;
}
static void nps_enet_set_hw_mac_address(struct net_device *ndev)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
u32 ge_mac_cfg_1_value = 0;
u32 *ge_mac_cfg_2_value = &priv->ge_mac_cfg_2_value;
ge_mac_cfg_1_value |= ndev->dev_addr[0] << CFG_1_OCTET_0_SHIFT;
ge_mac_cfg_1_value |= ndev->dev_addr[1] << CFG_1_OCTET_1_SHIFT;
ge_mac_cfg_1_value |= ndev->dev_addr[2] << CFG_1_OCTET_2_SHIFT;
ge_mac_cfg_1_value |= ndev->dev_addr[3] << CFG_1_OCTET_3_SHIFT;
*ge_mac_cfg_2_value = (*ge_mac_cfg_2_value & ~CFG_2_OCTET_4_MASK)
| ndev->dev_addr[4] << CFG_2_OCTET_4_SHIFT;
*ge_mac_cfg_2_value = (*ge_mac_cfg_2_value & ~CFG_2_OCTET_5_MASK)
| ndev->dev_addr[5] << CFG_2_OCTET_5_SHIFT;
nps_enet_reg_set(priv, NPS_ENET_REG_GE_MAC_CFG_1,
ge_mac_cfg_1_value);
nps_enet_reg_set(priv, NPS_ENET_REG_GE_MAC_CFG_2,
*ge_mac_cfg_2_value);
}
static void nps_enet_hw_reset(struct net_device *ndev)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
u32 ge_rst_value = 0, phase_fifo_ctl_value = 0;
ge_rst_value |= NPS_ENET_ENABLE << RST_GMAC_0_SHIFT;
nps_enet_reg_set(priv, NPS_ENET_REG_GE_RST, ge_rst_value);
usleep_range(10, 20);
nps_enet_reg_set(priv, NPS_ENET_REG_GE_RST, ge_rst_value);
phase_fifo_ctl_value |= NPS_ENET_ENABLE << PHASE_FIFO_CTL_RST_SHIFT;
phase_fifo_ctl_value |= NPS_ENET_ENABLE << PHASE_FIFO_CTL_INIT_SHIFT;
nps_enet_reg_set(priv, NPS_ENET_REG_PHASE_FIFO_CTL,
phase_fifo_ctl_value);
usleep_range(10, 20);
phase_fifo_ctl_value = 0;
nps_enet_reg_set(priv, NPS_ENET_REG_PHASE_FIFO_CTL,
phase_fifo_ctl_value);
}
static void nps_enet_hw_enable_control(struct net_device *ndev)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
u32 ge_mac_cfg_0_value = 0, buf_int_enable_value = 0;
u32 *ge_mac_cfg_2_value = &priv->ge_mac_cfg_2_value;
u32 *ge_mac_cfg_3_value = &priv->ge_mac_cfg_3_value;
s32 max_frame_length;
*ge_mac_cfg_2_value = (*ge_mac_cfg_2_value & ~CFG_2_STAT_EN_MASK)
| NPS_ENET_GE_MAC_CFG_2_STAT_EN << CFG_2_STAT_EN_SHIFT;
*ge_mac_cfg_2_value = (*ge_mac_cfg_2_value & ~CFG_2_DISK_DA_MASK)
| NPS_ENET_ENABLE << CFG_2_DISK_DA_SHIFT;
*ge_mac_cfg_2_value = (*ge_mac_cfg_2_value & ~CFG_2_DISK_MC_MASK)
| NPS_ENET_ENABLE << CFG_2_DISK_MC_SHIFT;
nps_enet_reg_set(priv, NPS_ENET_REG_GE_MAC_CFG_2,
*ge_mac_cfg_2_value);
max_frame_length = ETH_HLEN + ndev->mtu + ETH_FCS_LEN;
if (max_frame_length <= NPS_ENET_MAX_FRAME_LENGTH) {
*ge_mac_cfg_3_value =
(*ge_mac_cfg_3_value & ~CFG_3_MAX_LEN_MASK)
| max_frame_length << CFG_3_MAX_LEN_SHIFT;
}
buf_int_enable_value |= NPS_ENET_ENABLE << RX_RDY_SHIFT;
buf_int_enable_value |= NPS_ENET_ENABLE << TX_DONE_SHIFT;
nps_enet_reg_set(priv, NPS_ENET_REG_BUF_INT_ENABLE,
buf_int_enable_value);
nps_enet_set_hw_mac_address(ndev);
ge_mac_cfg_0_value |= NPS_ENET_ENABLE << CFG_0_TX_PAD_EN_SHIFT;
ge_mac_cfg_0_value |= NPS_ENET_ENABLE << CFG_0_TX_CRC_EN_SHIFT;
ge_mac_cfg_0_value |= NPS_ENET_ENABLE << CFG_0_RX_CRC_STRIP_SHIFT;
ge_mac_cfg_0_value |=
NPS_ENET_GE_MAC_CFG_0_RX_IFG << CFG_0_RX_IFG_SHIFT;
ge_mac_cfg_0_value |=
NPS_ENET_GE_MAC_CFG_0_TX_IFG << CFG_0_TX_IFG_SHIFT;
ge_mac_cfg_0_value |= NPS_ENET_ENABLE << CFG_0_RX_PR_CHECK_EN_SHIFT;
ge_mac_cfg_0_value |=
NPS_ENET_GE_MAC_CFG_0_TX_PR_LEN << CFG_0_TX_PR_LEN_SHIFT;
ge_mac_cfg_0_value |= NPS_ENET_ENABLE << CFG_0_TX_FC_EN_SHIFT;
ge_mac_cfg_0_value |= NPS_ENET_ENABLE << CFG_0_RX_FC_EN_SHIFT;
ge_mac_cfg_0_value |=
NPS_ENET_GE_MAC_CFG_0_TX_FC_RETR << CFG_0_TX_FC_RETR_SHIFT;
*ge_mac_cfg_3_value = (*ge_mac_cfg_3_value & ~CFG_3_CF_DROP_MASK)
| NPS_ENET_ENABLE << CFG_3_CF_DROP_SHIFT;
ge_mac_cfg_0_value |= NPS_ENET_ENABLE << CFG_0_RX_EN_SHIFT;
ge_mac_cfg_0_value |= NPS_ENET_ENABLE << CFG_0_TX_EN_SHIFT;
nps_enet_reg_set(priv, NPS_ENET_REG_GE_MAC_CFG_3,
*ge_mac_cfg_3_value);
nps_enet_reg_set(priv, NPS_ENET_REG_GE_MAC_CFG_0,
ge_mac_cfg_0_value);
}
static void nps_enet_hw_disable_control(struct net_device *ndev)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
nps_enet_reg_set(priv, NPS_ENET_REG_BUF_INT_ENABLE, 0);
nps_enet_reg_set(priv, NPS_ENET_REG_GE_MAC_CFG_0, 0);
}
static void nps_enet_send_frame(struct net_device *ndev,
struct sk_buff *skb)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
u32 tx_ctrl_value = 0;
short length = skb->len;
u32 i, len = DIV_ROUND_UP(length, sizeof(u32));
u32 *src = (void *)skb->data;
bool src_is_aligned = IS_ALIGNED((unsigned long)src, sizeof(u32));
if (src_is_aligned)
iowrite32_rep(priv->regs_base + NPS_ENET_REG_TX_BUF, src, len);
else
for (i = 0; i < len; i++, src++)
nps_enet_reg_set(priv, NPS_ENET_REG_TX_BUF,
get_unaligned_be32(src));
tx_ctrl_value |= length << TX_CTL_NT_SHIFT;
tx_ctrl_value |= NPS_ENET_ENABLE << TX_CTL_CT_SHIFT;
nps_enet_reg_set(priv, NPS_ENET_REG_TX_CTL, tx_ctrl_value);
}
static s32 nps_enet_set_mac_address(struct net_device *ndev, void *p)
{
struct sockaddr *addr = p;
s32 res;
if (netif_running(ndev))
return -EBUSY;
res = eth_mac_addr(ndev, p);
if (!res) {
ether_addr_copy(ndev->dev_addr, addr->sa_data);
nps_enet_set_hw_mac_address(ndev);
}
return res;
}
static void nps_enet_set_rx_mode(struct net_device *ndev)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
u32 ge_mac_cfg_2_value = priv->ge_mac_cfg_2_value;
if (ndev->flags & IFF_PROMISC) {
ge_mac_cfg_2_value = (ge_mac_cfg_2_value & ~CFG_2_DISK_DA_MASK)
| NPS_ENET_DISABLE << CFG_2_DISK_DA_SHIFT;
ge_mac_cfg_2_value = (ge_mac_cfg_2_value & ~CFG_2_DISK_MC_MASK)
| NPS_ENET_DISABLE << CFG_2_DISK_MC_SHIFT;
} else {
ge_mac_cfg_2_value = (ge_mac_cfg_2_value & ~CFG_2_DISK_DA_MASK)
| NPS_ENET_ENABLE << CFG_2_DISK_DA_SHIFT;
ge_mac_cfg_2_value = (ge_mac_cfg_2_value & ~CFG_2_DISK_MC_MASK)
| NPS_ENET_ENABLE << CFG_2_DISK_MC_SHIFT;
}
nps_enet_reg_set(priv, NPS_ENET_REG_GE_MAC_CFG_2, ge_mac_cfg_2_value);
}
static s32 nps_enet_open(struct net_device *ndev)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
s32 err;
priv->tx_skb = NULL;
priv->ge_mac_cfg_2_value = 0;
priv->ge_mac_cfg_3_value = 0;
priv->ge_mac_cfg_3_value |=
NPS_ENET_GE_MAC_CFG_3_RX_IFG_TH << CFG_3_RX_IFG_TH_SHIFT;
priv->ge_mac_cfg_3_value |=
NPS_ENET_GE_MAC_CFG_3_MAX_LEN << CFG_3_MAX_LEN_SHIFT;
nps_enet_hw_disable_control(ndev);
err = request_irq(priv->irq, nps_enet_irq_handler,
0, "enet-rx-tx", ndev);
if (err)
return err;
napi_enable(&priv->napi);
nps_enet_hw_reset(ndev);
nps_enet_hw_enable_control(ndev);
netif_start_queue(ndev);
return 0;
}
static s32 nps_enet_stop(struct net_device *ndev)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
napi_disable(&priv->napi);
netif_stop_queue(ndev);
nps_enet_hw_disable_control(ndev);
free_irq(priv->irq, ndev);
return 0;
}
static netdev_tx_t nps_enet_start_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
struct nps_enet_priv *priv = netdev_priv(ndev);
netif_stop_queue(ndev);
priv->tx_skb = skb;
wmb();
nps_enet_send_frame(ndev, skb);
return NETDEV_TX_OK;
}
static void nps_enet_poll_controller(struct net_device *ndev)
{
disable_irq(ndev->irq);
nps_enet_irq_handler(ndev->irq, ndev);
enable_irq(ndev->irq);
}
static s32 nps_enet_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct net_device *ndev;
struct nps_enet_priv *priv;
s32 err = 0;
const char *mac_addr;
struct resource *res_regs;
if (!dev->of_node)
return -ENODEV;
ndev = alloc_etherdev(sizeof(struct nps_enet_priv));
if (!ndev)
return -ENOMEM;
platform_set_drvdata(pdev, ndev);
SET_NETDEV_DEV(ndev, dev);
priv = netdev_priv(ndev);
ndev->netdev_ops = &nps_netdev_ops;
ndev->watchdog_timeo = (400 * HZ / 1000);
ndev->flags &= ~IFF_MULTICAST;
res_regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->regs_base = devm_ioremap_resource(dev, res_regs);
if (IS_ERR(priv->regs_base)) {
err = PTR_ERR(priv->regs_base);
goto out_netdev;
}
dev_dbg(dev, "Registers base address is 0x%p\n", priv->regs_base);
mac_addr = of_get_mac_address(dev->of_node);
if (mac_addr)
ether_addr_copy(ndev->dev_addr, mac_addr);
else
eth_hw_addr_random(ndev);
priv->irq = platform_get_irq(pdev, 0);
if (!priv->irq) {
dev_err(dev, "failed to retrieve <irq Rx-Tx> value from device tree\n");
err = -ENODEV;
goto out_netdev;
}
netif_napi_add(ndev, &priv->napi, nps_enet_poll,
NPS_ENET_NAPI_POLL_WEIGHT);
err = register_netdev(ndev);
if (err) {
dev_err(dev, "Failed to register ndev for %s, err = 0x%08x\n",
ndev->name, (s32)err);
goto out_netif_api;
}
dev_info(dev, "(rx/tx=%d)\n", priv->irq);
return 0;
out_netif_api:
netif_napi_del(&priv->napi);
out_netdev:
if (err)
free_netdev(ndev);
return err;
}
static s32 nps_enet_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct nps_enet_priv *priv = netdev_priv(ndev);
unregister_netdev(ndev);
free_netdev(ndev);
netif_napi_del(&priv->napi);
return 0;
}
