static u8 ks_rdreg8(struct ks_net *ks, int offset)
{
u16 data;
u8 shift_bit = offset & 0x03;
u8 shift_data = (offset & 1) << 3;
ks->cmd_reg_cache = (u16) offset | (u16)(BE0 << shift_bit);
iowrite16(ks->cmd_reg_cache, ks->hw_addr_cmd);
data = ioread16(ks->hw_addr);
return (u8)(data >> shift_data);
}
static u16 ks_rdreg16(struct ks_net *ks, int offset)
{
ks->cmd_reg_cache = (u16)offset | ((BE1 | BE0) << (offset & 0x02));
iowrite16(ks->cmd_reg_cache, ks->hw_addr_cmd);
return ioread16(ks->hw_addr);
}
static void ks_wrreg8(struct ks_net *ks, int offset, u8 value)
{
u8 shift_bit = (offset & 0x03);
u16 value_write = (u16)(value << ((offset & 1) << 3));
ks->cmd_reg_cache = (u16)offset | (BE0 << shift_bit);
iowrite16(ks->cmd_reg_cache, ks->hw_addr_cmd);
iowrite16(value_write, ks->hw_addr);
}
static void ks_wrreg16(struct ks_net *ks, int offset, u16 value)
{
ks->cmd_reg_cache = (u16)offset | ((BE1 | BE0) << (offset & 0x02));
iowrite16(ks->cmd_reg_cache, ks->hw_addr_cmd);
iowrite16(value, ks->hw_addr);
}
static inline void ks_inblk(struct ks_net *ks, u16 *wptr, u32 len)
{
len >>= 1;
while (len--)
*wptr++ = (u16)ioread16(ks->hw_addr);
}
static inline void ks_outblk(struct ks_net *ks, u16 *wptr, u32 len)
{
len >>= 1;
while (len--)
iowrite16(*wptr++, ks->hw_addr);
}
static void ks_disable_int(struct ks_net *ks)
{
ks_wrreg16(ks, KS_IER, 0x0000);
}
static void ks_enable_int(struct ks_net *ks)
{
ks_wrreg16(ks, KS_IER, ks->rc_ier);
}
static inline u16 ks_tx_fifo_space(struct ks_net *ks)
{
return ks_rdreg16(ks, KS_TXMIR) & 0x1fff;
}
static inline void ks_save_cmd_reg(struct ks_net *ks)
{
ks->cmd_reg_cache_int = ks->cmd_reg_cache;
}
static inline void ks_restore_cmd_reg(struct ks_net *ks)
{
ks->cmd_reg_cache = ks->cmd_reg_cache_int;
iowrite16(ks->cmd_reg_cache, ks->hw_addr_cmd);
}
static void ks_set_powermode(struct ks_net *ks, unsigned pwrmode)
{
unsigned pmecr;
netif_dbg(ks, hw, ks->netdev, "setting power mode %d\n", pwrmode);
ks_rdreg16(ks, KS_GRR);
pmecr = ks_rdreg16(ks, KS_PMECR);
pmecr &= ~PMECR_PM_MASK;
pmecr |= pwrmode;
ks_wrreg16(ks, KS_PMECR, pmecr);
}
static void ks_read_config(struct ks_net *ks)
{
u16 reg_data = 0;
reg_data = ks_rdreg8(ks, KS_CCR) & 0x00FF;
reg_data |= ks_rdreg8(ks, KS_CCR+1) << 8;
ks->sharedbus = (reg_data & CCR_SHARED) == CCR_SHARED;
if (reg_data & CCR_8BIT) {
ks->bus_width = ENUM_BUS_8BIT;
ks->extra_byte = 1;
} else if (reg_data & CCR_16BIT) {
ks->bus_width = ENUM_BUS_16BIT;
ks->extra_byte = 2;
} else {
ks->bus_width = ENUM_BUS_32BIT;
ks->extra_byte = 4;
}
}
static void ks_soft_reset(struct ks_net *ks, unsigned op)
{
ks_wrreg16(ks, KS_IER, 0x0000);
ks_wrreg16(ks, KS_GRR, op);
mdelay(10);
ks_wrreg16(ks, KS_GRR, 0);
mdelay(1);
}
void ks_enable_qmu(struct ks_net *ks)
{
u16 w;
w = ks_rdreg16(ks, KS_TXCR);
ks_wrreg16(ks, KS_TXCR, w | TXCR_TXE);
w = ks_rdreg16(ks, KS_RXQCR);
ks_wrreg16(ks, KS_RXQCR, w | RXQCR_RXFCTE);
w = ks_rdreg16(ks, KS_RXCR1);
ks_wrreg16(ks, KS_RXCR1, w | RXCR1_RXE);
ks->enabled = true;
}
static void ks_disable_qmu(struct ks_net *ks)
{
u16 w;
w = ks_rdreg16(ks, KS_TXCR);
w &= ~TXCR_TXE;
ks_wrreg16(ks, KS_TXCR, w);
w = ks_rdreg16(ks, KS_RXCR1);
w &= ~RXCR1_RXE ;
ks_wrreg16(ks, KS_RXCR1, w);
ks->enabled = false;
}
static inline void ks_read_qmu(struct ks_net *ks, u16 *buf, u32 len)
{
u32 r = ks->extra_byte & 0x1 ;
u32 w = ks->extra_byte - r;
ks_wrreg16(ks, KS_RXFDPR, RXFDPR_RXFPAI);
ks_wrreg8(ks, KS_RXQCR, (ks->rc_rxqcr | RXQCR_SDA) & 0xff);
if (unlikely(r))
ioread8(ks->hw_addr);
ks_inblk(ks, buf, w + 2 + 2);
ks_inblk(ks, buf, ALIGN(len, 4));
ks_wrreg8(ks, KS_RXQCR, ks->rc_rxqcr);
}
static void ks_rcv(struct ks_net *ks, struct net_device *netdev)
{
u32 i;
struct type_frame_head *frame_hdr = ks->frame_head_info;
struct sk_buff *skb;
ks->frame_cnt = ks_rdreg16(ks, KS_RXFCTR) >> 8;
for (i = 0; i < ks->frame_cnt; i++) {
frame_hdr->sts = ks_rdreg16(ks, KS_RXFHSR);
frame_hdr->len = ks_rdreg16(ks, KS_RXFHBCR);
frame_hdr++;
}
frame_hdr = ks->frame_head_info;
while (ks->frame_cnt--) {
skb = dev_alloc_skb(frame_hdr->len + 16);
if (likely(skb && (frame_hdr->sts & RXFSHR_RXFV) &&
(frame_hdr->len < RX_BUF_SIZE) && frame_hdr->len)) {
skb_reserve(skb, 2);
ks_read_qmu(ks, (u16 *)skb->data, frame_hdr->len);
skb_put(skb, frame_hdr->len);
skb->protocol = eth_type_trans(skb, netdev);
netif_rx(skb);
} else {
pr_err("%s: err:skb alloc\n", __func__);
ks_wrreg16(ks, KS_RXQCR, (ks->rc_rxqcr | RXQCR_RRXEF));
if (skb)
dev_kfree_skb_irq(skb);
}
frame_hdr++;
}
}
static void ks_update_link_status(struct net_device *netdev, struct ks_net *ks)
{
u32 link_up_status;
if (ks_rdreg16(ks, KS_P1SR) & P1SR_LINK_GOOD) {
netif_carrier_on(netdev);
link_up_status = true;
} else {
netif_carrier_off(netdev);
link_up_status = false;
}
netif_dbg(ks, link, ks->netdev,
"%s: %s\n", __func__, link_up_status ? "UP" : "DOWN");
}
static irqreturn_t ks_irq(int irq, void *pw)
{
struct net_device *netdev = pw;
struct ks_net *ks = netdev_priv(netdev);
u16 status;
ks_save_cmd_reg(ks);
status = ks_rdreg16(ks, KS_ISR);
if (unlikely(!status)) {
ks_restore_cmd_reg(ks);
return IRQ_NONE;
}
ks_wrreg16(ks, KS_ISR, status);
if (likely(status & IRQ_RXI))
ks_rcv(ks, netdev);
if (unlikely(status & IRQ_LCI))
ks_update_link_status(netdev, ks);
if (unlikely(status & IRQ_TXI))
netif_wake_queue(netdev);
if (unlikely(status & IRQ_LDI)) {
u16 pmecr = ks_rdreg16(ks, KS_PMECR);
pmecr &= ~PMECR_WKEVT_MASK;
ks_wrreg16(ks, KS_PMECR, pmecr | PMECR_WKEVT_LINK);
}
ks_restore_cmd_reg(ks);
return IRQ_HANDLED;
}
static int ks_net_open(struct net_device *netdev)
{
struct ks_net *ks = netdev_priv(netdev);
int err;
#define KS_INT_FLAGS (IRQF_DISABLED|IRQF_TRIGGER_LOW)
netif_dbg(ks, ifup, ks->netdev, "%s - entry\n", __func__);
err = request_irq(ks->irq, ks_irq, KS_INT_FLAGS, DRV_NAME, netdev);
if (err) {
pr_err("Failed to request IRQ: %d: %d\n", ks->irq, err);
return err;
}
ks_set_powermode(ks, PMECR_PM_NORMAL);
mdelay(1);
ks_wrreg16(ks, KS_ISR, 0xffff);
ks_enable_int(ks);
ks_enable_qmu(ks);
netif_start_queue(ks->netdev);
netif_dbg(ks, ifup, ks->netdev, "network device up\n");
return 0;
}
static int ks_net_stop(struct net_device *netdev)
{
struct ks_net *ks = netdev_priv(netdev);
netif_info(ks, ifdown, netdev, "shutting down\n");
netif_stop_queue(netdev);
mutex_lock(&ks->lock);
ks_wrreg16(ks, KS_IER, 0x0000);
ks_wrreg16(ks, KS_ISR, 0xffff);
ks_disable_qmu(ks);
ks_set_powermode(ks, PMECR_PM_SOFTDOWN);
free_irq(ks->irq, netdev);
mutex_unlock(&ks->lock);
return 0;
}
static void ks_write_qmu(struct ks_net *ks, u8 *pdata, u16 len)
{
ks->txh.txw[0] = 0;
ks->txh.txw[1] = cpu_to_le16(len);
ks_wrreg8(ks, KS_RXQCR, (ks->rc_rxqcr | RXQCR_SDA) & 0xff);
ks_outblk(ks, ks->txh.txw, 4);
ks_outblk(ks, (u16 *)pdata, ALIGN(len, 4));
ks_wrreg8(ks, KS_RXQCR, ks->rc_rxqcr);
ks_wrreg16(ks, KS_TXQCR, TXQCR_METFE);
while (ks_rdreg16(ks, KS_TXQCR) & TXQCR_METFE)
;
}
static int ks_start_xmit(struct sk_buff *skb, struct net_device *netdev)
{
int retv = NETDEV_TX_OK;
struct ks_net *ks = netdev_priv(netdev);
disable_irq(netdev->irq);
ks_disable_int(ks);
spin_lock(&ks->statelock);
if (likely(ks_tx_fifo_space(ks) >= skb->len + 12)) {
ks_write_qmu(ks, skb->data, skb->len);
dev_kfree_skb(skb);
} else
retv = NETDEV_TX_BUSY;
spin_unlock(&ks->statelock);
ks_enable_int(ks);
enable_irq(netdev->irq);
return retv;
}
static void ks_start_rx(struct ks_net *ks)
{
u16 cntl;
cntl = ks_rdreg16(ks, KS_RXCR1);
cntl |= RXCR1_RXE ;
ks_wrreg16(ks, KS_RXCR1, cntl);
}
static void ks_stop_rx(struct ks_net *ks)
{
u16 cntl;
cntl = ks_rdreg16(ks, KS_RXCR1);
cntl &= ~RXCR1_RXE ;
ks_wrreg16(ks, KS_RXCR1, cntl);
}
static unsigned long ether_gen_crc(int length, u8 *data)
{
long crc = -1;
while (--length >= 0) {
u8 current_octet = *data++;
int bit;
for (bit = 0; bit < 8; bit++, current_octet >>= 1) {
crc = (crc << 1) ^
((crc < 0) ^ (current_octet & 1) ?
ethernet_polynomial : 0);
}
}
return (unsigned long)crc;
}
static void ks_set_grpaddr(struct ks_net *ks)
{
u8 i;
u32 index, position, value;
memset(ks->mcast_bits, 0, sizeof(u8) * HW_MCAST_SIZE);
for (i = 0; i < ks->mcast_lst_size; i++) {
position = (ether_gen_crc(6, ks->mcast_lst[i]) >> 26) & 0x3f;
index = position >> 3;
value = 1 << (position & 7);
ks->mcast_bits[index] |= (u8)value;
}
for (i = 0; i < HW_MCAST_SIZE; i++) {
if (i & 1) {
ks_wrreg16(ks, (u16)((KS_MAHTR0 + i) & ~1),
(ks->mcast_bits[i] << 8) |
ks->mcast_bits[i - 1]);
}
}
}
static void ks_clear_mcast(struct ks_net *ks)
{
u16 i, mcast_size;
for (i = 0; i < HW_MCAST_SIZE; i++)
ks->mcast_bits[i] = 0;
mcast_size = HW_MCAST_SIZE >> 2;
for (i = 0; i < mcast_size; i++)
ks_wrreg16(ks, KS_MAHTR0 + (2*i), 0);
}
static void ks_set_promis(struct ks_net *ks, u16 promiscuous_mode)
{
u16 cntl;
ks->promiscuous = promiscuous_mode;
ks_stop_rx(ks);
cntl = ks_rdreg16(ks, KS_RXCR1);
cntl &= ~RXCR1_FILTER_MASK;
if (promiscuous_mode)
cntl |= RXCR1_RXAE | RXCR1_RXINVF;
else
cntl |= RXCR1_RXPAFMA;
ks_wrreg16(ks, KS_RXCR1, cntl);
if (ks->enabled)
ks_start_rx(ks);
}
static void ks_set_mcast(struct ks_net *ks, u16 mcast)
{
u16 cntl;
ks->all_mcast = mcast;
ks_stop_rx(ks);
cntl = ks_rdreg16(ks, KS_RXCR1);
cntl &= ~RXCR1_FILTER_MASK;
if (mcast)
cntl |= (RXCR1_RXAE | RXCR1_RXMAFMA | RXCR1_RXPAFMA);
else
cntl |= RXCR1_RXPAFMA;
ks_wrreg16(ks, KS_RXCR1, cntl);
if (ks->enabled)
ks_start_rx(ks);
}
static void ks_set_rx_mode(struct net_device *netdev)
{
struct ks_net *ks = netdev_priv(netdev);
struct netdev_hw_addr *ha;
if ((netdev->flags & IFF_PROMISC) == IFF_PROMISC)
ks_set_promis(ks,
(u16)((netdev->flags & IFF_PROMISC) == IFF_PROMISC));
else if ((netdev->flags & IFF_ALLMULTI) == IFF_ALLMULTI)
ks_set_mcast(ks,
(u16)((netdev->flags & IFF_ALLMULTI) == IFF_ALLMULTI));
else
ks_set_promis(ks, false);
if ((netdev->flags & IFF_MULTICAST) && netdev_mc_count(netdev)) {
if (netdev_mc_count(netdev) <= MAX_MCAST_LST) {
int i = 0;
netdev_for_each_mc_addr(ha, netdev) {
if (!(*ha->addr & 1))
continue;
if (i >= MAX_MCAST_LST)
break;
memcpy(ks->mcast_lst[i++], ha->addr, ETH_ALEN);
}
ks->mcast_lst_size = (u8)i;
ks_set_grpaddr(ks);
} else {
ks->mcast_lst_size = MAX_MCAST_LST;
ks_set_mcast(ks, true);
}
} else {
ks->mcast_lst_size = 0;
ks_clear_mcast(ks);
}
}
static void ks_set_mac(struct ks_net *ks, u8 *data)
{
u16 *pw = (u16 *)data;
u16 w, u;
ks_stop_rx(ks);
u = *pw++;
w = ((u & 0xFF) << 8) | ((u >> 8) & 0xFF);
ks_wrreg16(ks, KS_MARH, w);
u = *pw++;
w = ((u & 0xFF) << 8) | ((u >> 8) & 0xFF);
ks_wrreg16(ks, KS_MARM, w);
u = *pw;
w = ((u & 0xFF) << 8) | ((u >> 8) & 0xFF);
ks_wrreg16(ks, KS_MARL, w);
memcpy(ks->mac_addr, data, 6);
if (ks->enabled)
ks_start_rx(ks);
}
static int ks_set_mac_address(struct net_device *netdev, void *paddr)
{
struct ks_net *ks = netdev_priv(netdev);
struct sockaddr *addr = paddr;
u8 *da;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
da = (u8 *)netdev->dev_addr;
ks_set_mac(ks, da);
return 0;
}
static int ks_net_ioctl(struct net_device *netdev, struct ifreq *req, int cmd)
{
struct ks_net *ks = netdev_priv(netdev);
if (!netif_running(netdev))
return -EINVAL;
return generic_mii_ioctl(&ks->mii, if_mii(req), cmd, NULL);
}
static void ks_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *di)
{
strlcpy(di->driver, DRV_NAME, sizeof(di->driver));
strlcpy(di->version, "1.00", sizeof(di->version));
strlcpy(di->bus_info, dev_name(netdev->dev.parent),
sizeof(di->bus_info));
}
static u32 ks_get_msglevel(struct net_device *netdev)
{
struct ks_net *ks = netdev_priv(netdev);
return ks->msg_enable;
}
static void ks_set_msglevel(struct net_device *netdev, u32 to)
{
struct ks_net *ks = netdev_priv(netdev);
ks->msg_enable = to;
}
static int ks_get_settings(struct net_device *netdev, struct ethtool_cmd *cmd)
{
struct ks_net *ks = netdev_priv(netdev);
return mii_ethtool_gset(&ks->mii, cmd);
}
static int ks_set_settings(struct net_device *netdev, struct ethtool_cmd *cmd)
{
struct ks_net *ks = netdev_priv(netdev);
return mii_ethtool_sset(&ks->mii, cmd);
}
static u32 ks_get_link(struct net_device *netdev)
{
struct ks_net *ks = netdev_priv(netdev);
return mii_link_ok(&ks->mii);
}
static int ks_nway_reset(struct net_device *netdev)
{
struct ks_net *ks = netdev_priv(netdev);
return mii_nway_restart(&ks->mii);
}
static int ks_phy_reg(int reg)
{
switch (reg) {
case MII_BMCR:
return KS_P1MBCR;
case MII_BMSR:
return KS_P1MBSR;
case MII_PHYSID1:
return KS_PHY1ILR;
case MII_PHYSID2:
return KS_PHY1IHR;
case MII_ADVERTISE:
return KS_P1ANAR;
case MII_LPA:
return KS_P1ANLPR;
}
return 0x0;
}
static int ks_phy_read(struct net_device *netdev, int phy_addr, int reg)
{
struct ks_net *ks = netdev_priv(netdev);
int ksreg;
int result;
ksreg = ks_phy_reg(reg);
if (!ksreg)
return 0x0;
mutex_lock(&ks->lock);
result = ks_rdreg16(ks, ksreg);
mutex_unlock(&ks->lock);
return result;
}
static void ks_phy_write(struct net_device *netdev,
int phy, int reg, int value)
{
struct ks_net *ks = netdev_priv(netdev);
int ksreg;
ksreg = ks_phy_reg(reg);
if (ksreg) {
mutex_lock(&ks->lock);
ks_wrreg16(ks, ksreg, value);
mutex_unlock(&ks->lock);
}
}
static int ks_read_selftest(struct ks_net *ks)
{
unsigned both_done = MBIR_TXMBF | MBIR_RXMBF;
int ret = 0;
unsigned rd;
rd = ks_rdreg16(ks, KS_MBIR);
if ((rd & both_done) != both_done) {
netdev_warn(ks->netdev, "Memory selftest not finished\n");
return 0;
}
if (rd & MBIR_TXMBFA) {
netdev_err(ks->netdev, "TX memory selftest fails\n");
ret |= 1;
}
if (rd & MBIR_RXMBFA) {
netdev_err(ks->netdev, "RX memory selftest fails\n");
ret |= 2;
}
netdev_info(ks->netdev, "the selftest passes\n");
return ret;
}
static void ks_setup(struct ks_net *ks)
{
u16 w;
ks_wrreg16(ks, KS_TXFDPR, TXFDPR_TXFPAI);
ks_wrreg16(ks, KS_RXFDPR, RXFDPR_RXFPAI);
ks_wrreg16(ks, KS_RXFCTR, 1 & RXFCTR_THRESHOLD_MASK);
ks->rc_rxqcr = RXQCR_CMD_CNTL;
ks_wrreg16(ks, KS_RXQCR, ks->rc_rxqcr);
w = ks_rdreg16(ks, KS_P1MBCR);
w &= ~P1MBCR_FORCE_FDX;
ks_wrreg16(ks, KS_P1MBCR, w);
w = TXCR_TXFCE | TXCR_TXPE | TXCR_TXCRC | TXCR_TCGIP;
ks_wrreg16(ks, KS_TXCR, w);
w = RXCR1_RXFCE | RXCR1_RXBE | RXCR1_RXUE | RXCR1_RXME | RXCR1_RXIPFCC;
if (ks->promiscuous)
w |= (RXCR1_RXAE | RXCR1_RXINVF);
else if (ks->all_mcast)
w |= (RXCR1_RXAE | RXCR1_RXMAFMA | RXCR1_RXPAFMA);
else
w |= RXCR1_RXPAFMA;
ks_wrreg16(ks, KS_RXCR1, w);
}
static void ks_setup_int(struct ks_net *ks)
{
ks->rc_ier = 0x00;
ks_wrreg16(ks, KS_ISR, 0xffff);
ks->rc_ier = (IRQ_LCI | IRQ_TXI | IRQ_RXI);
}
static int ks_hw_init(struct ks_net *ks)
{
#define MHEADER_SIZE (sizeof(struct type_frame_head) * MAX_RECV_FRAMES)
ks->promiscuous = 0;
ks->all_mcast = 0;
ks->mcast_lst_size = 0;
ks->frame_head_info = (struct type_frame_head *) \
kmalloc(MHEADER_SIZE, GFP_KERNEL);
if (!ks->frame_head_info) {
pr_err("Error: Fail to allocate frame memory\n");
return false;
}
ks_set_mac(ks, KS_DEFAULT_MAC_ADDRESS);
return true;
}
static int __devinit ks8851_probe(struct platform_device *pdev)
{
int err = -ENOMEM;
struct resource *io_d, *io_c;
struct net_device *netdev;
struct ks_net *ks;
u16 id, data;
io_d = platform_get_resource(pdev, IORESOURCE_MEM, 0);
io_c = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!request_mem_region(io_d->start, resource_size(io_d), DRV_NAME))
goto err_mem_region;
if (!request_mem_region(io_c->start, resource_size(io_c), DRV_NAME))
goto err_mem_region1;
netdev = alloc_etherdev(sizeof(struct ks_net));
if (!netdev)
goto err_alloc_etherdev;
SET_NETDEV_DEV(netdev, &pdev->dev);
ks = netdev_priv(netdev);
ks->netdev = netdev;
ks->hw_addr = ioremap(io_d->start, resource_size(io_d));
if (!ks->hw_addr)
goto err_ioremap;
ks->hw_addr_cmd = ioremap(io_c->start, resource_size(io_c));
if (!ks->hw_addr_cmd)
goto err_ioremap1;
ks->irq = platform_get_irq(pdev, 0);
if (ks->irq < 0) {
err = ks->irq;
goto err_get_irq;
}
ks->pdev = pdev;
mutex_init(&ks->lock);
spin_lock_init(&ks->statelock);
netdev->netdev_ops = &ks_netdev_ops;
netdev->ethtool_ops = &ks_ethtool_ops;
ks->mii.dev = netdev;
ks->mii.phy_id = 1,
ks->mii.phy_id_mask = 1;
ks->mii.reg_num_mask = 0xf;
ks->mii.mdio_read = ks_phy_read;
ks->mii.mdio_write = ks_phy_write;
netdev_info(netdev, "message enable is %d\n", msg_enable);
ks->msg_enable = netif_msg_init(msg_enable, (NETIF_MSG_DRV |
NETIF_MSG_PROBE |
NETIF_MSG_LINK));
ks_read_config(ks);
if ((ks_rdreg16(ks, KS_CIDER) & ~CIDER_REV_MASK) != CIDER_ID) {
netdev_err(netdev, "failed to read device ID\n");
err = -ENODEV;
goto err_register;
}
if (ks_read_selftest(ks)) {
netdev_err(netdev, "failed to read device ID\n");
err = -ENODEV;
goto err_register;
}
err = register_netdev(netdev);
if (err)
goto err_register;
platform_set_drvdata(pdev, netdev);
ks_soft_reset(ks, GRR_GSR);
ks_hw_init(ks);
ks_disable_qmu(ks);
ks_setup(ks);
ks_setup_int(ks);
memcpy(netdev->dev_addr, ks->mac_addr, 6);
data = ks_rdreg16(ks, KS_OBCR);
ks_wrreg16(ks, KS_OBCR, data | OBCR_ODS_16MA);
random_ether_addr(netdev->dev_addr);
ks_set_mac(ks, netdev->dev_addr);
id = ks_rdreg16(ks, KS_CIDER);
netdev_info(netdev, "Found chip, family: 0x%x, id: 0x%x, rev: 0x%x\n",
(id >> 8) & 0xff, (id >> 4) & 0xf, (id >> 1) & 0x7);
return 0;
err_register:
err_get_irq:
iounmap(ks->hw_addr_cmd);
err_ioremap1:
iounmap(ks->hw_addr);
err_ioremap:
free_netdev(netdev);
err_alloc_etherdev:
release_mem_region(io_c->start, resource_size(io_c));
err_mem_region1:
release_mem_region(io_d->start, resource_size(io_d));
err_mem_region:
return err;
}
static int __devexit ks8851_remove(struct platform_device *pdev)
{
struct net_device *netdev = platform_get_drvdata(pdev);
struct ks_net *ks = netdev_priv(netdev);
struct resource *iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
kfree(ks->frame_head_info);
unregister_netdev(netdev);
iounmap(ks->hw_addr);
free_netdev(netdev);
release_mem_region(iomem->start, resource_size(iomem));
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init ks8851_init(void)
{
return platform_driver_register(&ks8851_platform_driver);
}
static void __exit ks8851_exit(void)
{
platform_driver_unregister(&ks8851_platform_driver);
}
