static void sh_eth_set_duplex(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
if (mdp->duplex)
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) | ECMR_DM, ECMR);
else
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) & ~ECMR_DM, ECMR);
}
static void sh_eth_set_rate(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
switch (mdp->speed) {
case 10:
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) & ~ECMR_RTM, ECMR);
break;
case 100:
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) | ECMR_RTM, ECMR);
break;
default:
break;
}
}
static void sh_eth_set_duplex(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
if (mdp->duplex)
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) | ECMR_DM, ECMR);
else
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) & ~ECMR_DM, ECMR);
}
static void sh_eth_set_rate(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
switch (mdp->speed) {
case 10:
sh_eth_write(ndev, 0, RTRATE);
break;
case 100:
sh_eth_write(ndev, 1, RTRATE);
break;
default:
break;
}
}
static void sh_eth_chip_reset_giga(struct net_device *ndev)
{
int i;
unsigned long mahr[2], malr[2];
for (i = 0; i < 2; i++) {
malr[i] = readl(GIGA_MALR(i));
mahr[i] = readl(GIGA_MAHR(i));
}
writel(ARSTR_ARSTR, SH_GIGA_ETH_BASE + 0x1800);
mdelay(1);
for (i = 0; i < 2; i++) {
writel(malr[i], GIGA_MALR(i));
writel(mahr[i], GIGA_MAHR(i));
}
}
static void sh_eth_reset(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int cnt = 100;
if (sh_eth_is_gether(mdp)) {
sh_eth_write(ndev, 0x03, EDSR);
sh_eth_write(ndev, sh_eth_read(ndev, EDMR) | EDMR_SRST_GETHER,
EDMR);
while (cnt > 0) {
if (!(sh_eth_read(ndev, EDMR) & 0x3))
break;
mdelay(1);
cnt--;
}
if (cnt < 0)
printk(KERN_ERR "Device reset fail\n");
sh_eth_write(ndev, 0x0, TDLAR);
sh_eth_write(ndev, 0x0, TDFAR);
sh_eth_write(ndev, 0x0, TDFXR);
sh_eth_write(ndev, 0x0, TDFFR);
sh_eth_write(ndev, 0x0, RDLAR);
sh_eth_write(ndev, 0x0, RDFAR);
sh_eth_write(ndev, 0x0, RDFXR);
sh_eth_write(ndev, 0x0, RDFFR);
} else {
sh_eth_write(ndev, sh_eth_read(ndev, EDMR) | EDMR_SRST_ETHER,
EDMR);
mdelay(3);
sh_eth_write(ndev, sh_eth_read(ndev, EDMR) & ~EDMR_SRST_ETHER,
EDMR);
}
}
static void sh_eth_set_duplex_giga(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
if (mdp->duplex)
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) | ECMR_DM, ECMR);
else
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) & ~ECMR_DM, ECMR);
}
static void sh_eth_set_rate_giga(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
switch (mdp->speed) {
case 10:
sh_eth_write(ndev, 0x00000000, GECMR);
break;
case 100:
sh_eth_write(ndev, 0x00000010, GECMR);
break;
case 1000:
sh_eth_write(ndev, 0x00000020, GECMR);
break;
default:
break;
}
}
static struct sh_eth_cpu_data *sh_eth_get_cpu_data(struct sh_eth_private *mdp)
{
if (sh_eth_is_gether(mdp))
return &sh_eth_my_cpu_data_giga;
else
return &sh_eth_my_cpu_data;
}
static void sh_eth_chip_reset(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
sh_eth_tsu_write(mdp, ARSTR_ARSTR, ARSTR);
mdelay(1);
}
static void sh_eth_reset(struct net_device *ndev)
{
int cnt = 100;
sh_eth_write(ndev, EDSR_ENALL, EDSR);
sh_eth_write(ndev, sh_eth_read(ndev, EDMR) | EDMR_SRST_GETHER, EDMR);
while (cnt > 0) {
if (!(sh_eth_read(ndev, EDMR) & 0x3))
break;
mdelay(1);
cnt--;
}
if (cnt == 0)
printk(KERN_ERR "Device reset fail\n");
sh_eth_write(ndev, 0x0, TDLAR);
sh_eth_write(ndev, 0x0, TDFAR);
sh_eth_write(ndev, 0x0, TDFXR);
sh_eth_write(ndev, 0x0, TDFFR);
sh_eth_write(ndev, 0x0, RDLAR);
sh_eth_write(ndev, 0x0, RDFAR);
sh_eth_write(ndev, 0x0, RDFXR);
sh_eth_write(ndev, 0x0, RDFFR);
}
static void sh_eth_set_duplex(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
if (mdp->duplex)
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) | ECMR_DM, ECMR);
else
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) & ~ECMR_DM, ECMR);
}
static void sh_eth_set_rate(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
switch (mdp->speed) {
case 10:
sh_eth_write(ndev, GECMR_10, GECMR);
break;
case 100:
sh_eth_write(ndev, GECMR_100, GECMR);
break;
case 1000:
sh_eth_write(ndev, GECMR_1000, GECMR);
break;
default:
break;
}
}
static void sh_eth_set_default_cpu_data(struct sh_eth_cpu_data *cd)
{
if (!cd->ecsr_value)
cd->ecsr_value = DEFAULT_ECSR_INIT;
if (!cd->ecsipr_value)
cd->ecsipr_value = DEFAULT_ECSIPR_INIT;
if (!cd->fcftr_value)
cd->fcftr_value = DEFAULT_FIFO_F_D_RFF | \
DEFAULT_FIFO_F_D_RFD;
if (!cd->fdr_value)
cd->fdr_value = DEFAULT_FDR_INIT;
if (!cd->rmcr_value)
cd->rmcr_value = DEFAULT_RMCR_VALUE;
if (!cd->tx_check)
cd->tx_check = DEFAULT_TX_CHECK;
if (!cd->eesr_err_check)
cd->eesr_err_check = DEFAULT_EESR_ERR_CHECK;
if (!cd->tx_error_check)
cd->tx_error_check = DEFAULT_TX_ERROR_CHECK;
}
static void sh_eth_reset(struct net_device *ndev)
{
sh_eth_write(ndev, sh_eth_read(ndev, EDMR) | EDMR_SRST_ETHER, EDMR);
mdelay(3);
sh_eth_write(ndev, sh_eth_read(ndev, EDMR) & ~EDMR_SRST_ETHER, EDMR);
}
static void sh_eth_set_receive_align(struct sk_buff *skb)
{
int reserve;
reserve = SH4_SKB_RX_ALIGN - ((u32)skb->data & (SH4_SKB_RX_ALIGN - 1));
if (reserve)
skb_reserve(skb, reserve);
}
static void sh_eth_set_receive_align(struct sk_buff *skb)
{
skb_reserve(skb, SH2_SH3_SKB_RX_ALIGN);
}
static inline __u32 cpu_to_edmac(struct sh_eth_private *mdp, u32 x)
{
switch (mdp->edmac_endian) {
case EDMAC_LITTLE_ENDIAN:
return cpu_to_le32(x);
case EDMAC_BIG_ENDIAN:
return cpu_to_be32(x);
}
return x;
}
static inline __u32 edmac_to_cpu(struct sh_eth_private *mdp, u32 x)
{
switch (mdp->edmac_endian) {
case EDMAC_LITTLE_ENDIAN:
return le32_to_cpu(x);
case EDMAC_BIG_ENDIAN:
return be32_to_cpu(x);
}
return x;
}
static void update_mac_address(struct net_device *ndev)
{
sh_eth_write(ndev,
(ndev->dev_addr[0] << 24) | (ndev->dev_addr[1] << 16) |
(ndev->dev_addr[2] << 8) | (ndev->dev_addr[3]), MAHR);
sh_eth_write(ndev,
(ndev->dev_addr[4] << 8) | (ndev->dev_addr[5]), MALR);
}
static void read_mac_address(struct net_device *ndev, unsigned char *mac)
{
if (mac[0] || mac[1] || mac[2] || mac[3] || mac[4] || mac[5]) {
memcpy(ndev->dev_addr, mac, 6);
} else {
ndev->dev_addr[0] = (sh_eth_read(ndev, MAHR) >> 24);
ndev->dev_addr[1] = (sh_eth_read(ndev, MAHR) >> 16) & 0xFF;
ndev->dev_addr[2] = (sh_eth_read(ndev, MAHR) >> 8) & 0xFF;
ndev->dev_addr[3] = (sh_eth_read(ndev, MAHR) & 0xFF);
ndev->dev_addr[4] = (sh_eth_read(ndev, MALR) >> 8) & 0xFF;
ndev->dev_addr[5] = (sh_eth_read(ndev, MALR) & 0xFF);
}
}
static int sh_eth_is_gether(struct sh_eth_private *mdp)
{
if (mdp->reg_offset == sh_eth_offset_gigabit)
return 1;
else
return 0;
}
static unsigned long sh_eth_get_edtrr_trns(struct sh_eth_private *mdp)
{
if (sh_eth_is_gether(mdp))
return EDTRR_TRNS_GETHER;
else
return EDTRR_TRNS_ETHER;
}
static void bb_set(u32 addr, u32 msk)
{
writel(readl(addr) | msk, addr);
}
static void bb_clr(u32 addr, u32 msk)
{
writel((readl(addr) & ~msk), addr);
}
static int bb_read(u32 addr, u32 msk)
{
return (readl(addr) & msk) != 0;
}
static void sh_mmd_ctrl(struct mdiobb_ctrl *ctrl, int bit)
{
struct bb_info *bitbang = container_of(ctrl, struct bb_info, ctrl);
if (bitbang->set_gate)
bitbang->set_gate(bitbang->addr);
if (bit)
bb_set(bitbang->addr, bitbang->mmd_msk);
else
bb_clr(bitbang->addr, bitbang->mmd_msk);
}
static void sh_set_mdio(struct mdiobb_ctrl *ctrl, int bit)
{
struct bb_info *bitbang = container_of(ctrl, struct bb_info, ctrl);
if (bitbang->set_gate)
bitbang->set_gate(bitbang->addr);
if (bit)
bb_set(bitbang->addr, bitbang->mdo_msk);
else
bb_clr(bitbang->addr, bitbang->mdo_msk);
}
static int sh_get_mdio(struct mdiobb_ctrl *ctrl)
{
struct bb_info *bitbang = container_of(ctrl, struct bb_info, ctrl);
if (bitbang->set_gate)
bitbang->set_gate(bitbang->addr);
return bb_read(bitbang->addr, bitbang->mdi_msk);
}
static void sh_mdc_ctrl(struct mdiobb_ctrl *ctrl, int bit)
{
struct bb_info *bitbang = container_of(ctrl, struct bb_info, ctrl);
if (bitbang->set_gate)
bitbang->set_gate(bitbang->addr);
if (bit)
bb_set(bitbang->addr, bitbang->mdc_msk);
else
bb_clr(bitbang->addr, bitbang->mdc_msk);
}
static void sh_eth_ring_free(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int i;
if (mdp->rx_skbuff) {
for (i = 0; i < RX_RING_SIZE; i++) {
if (mdp->rx_skbuff[i])
dev_kfree_skb(mdp->rx_skbuff[i]);
}
}
kfree(mdp->rx_skbuff);
if (mdp->tx_skbuff) {
for (i = 0; i < TX_RING_SIZE; i++) {
if (mdp->tx_skbuff[i])
dev_kfree_skb(mdp->tx_skbuff[i]);
}
}
kfree(mdp->tx_skbuff);
}
static void sh_eth_ring_format(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int i;
struct sk_buff *skb;
struct sh_eth_rxdesc *rxdesc = NULL;
struct sh_eth_txdesc *txdesc = NULL;
int rx_ringsize = sizeof(*rxdesc) * RX_RING_SIZE;
int tx_ringsize = sizeof(*txdesc) * TX_RING_SIZE;
mdp->cur_rx = mdp->cur_tx = 0;
mdp->dirty_rx = mdp->dirty_tx = 0;
memset(mdp->rx_ring, 0, rx_ringsize);
for (i = 0; i < RX_RING_SIZE; i++) {
mdp->rx_skbuff[i] = NULL;
skb = dev_alloc_skb(mdp->rx_buf_sz);
mdp->rx_skbuff[i] = skb;
if (skb == NULL)
break;
dma_map_single(&ndev->dev, skb->tail, mdp->rx_buf_sz,
DMA_FROM_DEVICE);
skb->dev = ndev;
sh_eth_set_receive_align(skb);
rxdesc = &mdp->rx_ring[i];
rxdesc->addr = virt_to_phys(PTR_ALIGN(skb->data, 4));
rxdesc->status = cpu_to_edmac(mdp, RD_RACT | RD_RFP);
rxdesc->buffer_length = ALIGN(mdp->rx_buf_sz, 16);
if (i == 0) {
sh_eth_write(ndev, mdp->rx_desc_dma, RDLAR);
if (sh_eth_is_gether(mdp))
sh_eth_write(ndev, mdp->rx_desc_dma, RDFAR);
}
}
mdp->dirty_rx = (u32) (i - RX_RING_SIZE);
rxdesc->status |= cpu_to_edmac(mdp, RD_RDEL);
memset(mdp->tx_ring, 0, tx_ringsize);
for (i = 0; i < TX_RING_SIZE; i++) {
mdp->tx_skbuff[i] = NULL;
txdesc = &mdp->tx_ring[i];
txdesc->status = cpu_to_edmac(mdp, TD_TFP);
txdesc->buffer_length = 0;
if (i == 0) {
sh_eth_write(ndev, mdp->tx_desc_dma, TDLAR);
if (sh_eth_is_gether(mdp))
sh_eth_write(ndev, mdp->tx_desc_dma, TDFAR);
}
}
txdesc->status |= cpu_to_edmac(mdp, TD_TDLE);
}
static int sh_eth_ring_init(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int rx_ringsize, tx_ringsize, ret = 0;
mdp->rx_buf_sz = (ndev->mtu <= 1492 ? PKT_BUF_SZ :
(((ndev->mtu + 26 + 7) & ~7) + 2 + 16));
if (mdp->cd->rpadir)
mdp->rx_buf_sz += NET_IP_ALIGN;
mdp->rx_skbuff = kmalloc(sizeof(*mdp->rx_skbuff) * RX_RING_SIZE,
GFP_KERNEL);
if (!mdp->rx_skbuff) {
dev_err(&ndev->dev, "Cannot allocate Rx skb\n");
ret = -ENOMEM;
return ret;
}
mdp->tx_skbuff = kmalloc(sizeof(*mdp->tx_skbuff) * TX_RING_SIZE,
GFP_KERNEL);
if (!mdp->tx_skbuff) {
dev_err(&ndev->dev, "Cannot allocate Tx skb\n");
ret = -ENOMEM;
goto skb_ring_free;
}
rx_ringsize = sizeof(struct sh_eth_rxdesc) * RX_RING_SIZE;
mdp->rx_ring = dma_alloc_coherent(NULL, rx_ringsize, &mdp->rx_desc_dma,
GFP_KERNEL);
if (!mdp->rx_ring) {
dev_err(&ndev->dev, "Cannot allocate Rx Ring (size %d bytes)\n",
rx_ringsize);
ret = -ENOMEM;
goto desc_ring_free;
}
mdp->dirty_rx = 0;
tx_ringsize = sizeof(struct sh_eth_txdesc) * TX_RING_SIZE;
mdp->tx_ring = dma_alloc_coherent(NULL, tx_ringsize, &mdp->tx_desc_dma,
GFP_KERNEL);
if (!mdp->tx_ring) {
dev_err(&ndev->dev, "Cannot allocate Tx Ring (size %d bytes)\n",
tx_ringsize);
ret = -ENOMEM;
goto desc_ring_free;
}
return ret;
desc_ring_free:
dma_free_coherent(NULL, rx_ringsize, mdp->rx_ring, mdp->rx_desc_dma);
skb_ring_free:
sh_eth_ring_free(ndev);
return ret;
}
static int sh_eth_dev_init(struct net_device *ndev)
{
int ret = 0;
struct sh_eth_private *mdp = netdev_priv(ndev);
u_int32_t rx_int_var, tx_int_var;
u32 val;
sh_eth_reset(ndev);
sh_eth_ring_format(ndev);
if (mdp->cd->rpadir)
sh_eth_write(ndev, mdp->cd->rpadir_value, RPADIR);
sh_eth_write(ndev, 0, EESIPR);
#if defined(__LITTLE_ENDIAN__)
if (mdp->cd->hw_swap)
sh_eth_write(ndev, EDMR_EL, EDMR);
else
#endif
sh_eth_write(ndev, 0, EDMR);
sh_eth_write(ndev, mdp->cd->fdr_value, FDR);
sh_eth_write(ndev, 0, TFTR);
sh_eth_write(ndev, mdp->cd->rmcr_value, RMCR);
rx_int_var = mdp->rx_int_var = DESC_I_RINT8 | DESC_I_RINT5;
tx_int_var = mdp->tx_int_var = DESC_I_TINT2;
sh_eth_write(ndev, rx_int_var | tx_int_var, TRSCER);
if (mdp->cd->bculr)
sh_eth_write(ndev, 0x800, BCULR);
sh_eth_write(ndev, mdp->cd->fcftr_value, FCFTR);
if (!mdp->cd->no_trimd)
sh_eth_write(ndev, 0, TRIMD);
sh_eth_write(ndev, RFLR_VALUE, RFLR);
sh_eth_write(ndev, sh_eth_read(ndev, EESR), EESR);
sh_eth_write(ndev, mdp->cd->eesipr_value, EESIPR);
val = (sh_eth_read(ndev, ECMR) & ECMR_DM) |
ECMR_ZPF | (mdp->duplex ? ECMR_DM : 0) | ECMR_TE | ECMR_RE;
sh_eth_write(ndev, val, ECMR);
if (mdp->cd->set_rate)
mdp->cd->set_rate(ndev);
sh_eth_write(ndev, mdp->cd->ecsr_value, ECSR);
sh_eth_write(ndev, mdp->cd->ecsipr_value, ECSIPR);
update_mac_address(ndev);
if (mdp->cd->apr)
sh_eth_write(ndev, APR_AP, APR);
if (mdp->cd->mpr)
sh_eth_write(ndev, MPR_MP, MPR);
if (mdp->cd->tpauser)
sh_eth_write(ndev, TPAUSER_UNLIMITED, TPAUSER);
sh_eth_write(ndev, EDRRR_R, EDRRR);
netif_start_queue(ndev);
return ret;
}
static int sh_eth_txfree(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct sh_eth_txdesc *txdesc;
int freeNum = 0;
int entry = 0;
for (; mdp->cur_tx - mdp->dirty_tx > 0; mdp->dirty_tx++) {
entry = mdp->dirty_tx % TX_RING_SIZE;
txdesc = &mdp->tx_ring[entry];
if (txdesc->status & cpu_to_edmac(mdp, TD_TACT))
break;
if (mdp->tx_skbuff[entry]) {
dev_kfree_skb_irq(mdp->tx_skbuff[entry]);
mdp->tx_skbuff[entry] = NULL;
freeNum++;
}
txdesc->status = cpu_to_edmac(mdp, TD_TFP);
if (entry >= TX_RING_SIZE - 1)
txdesc->status |= cpu_to_edmac(mdp, TD_TDLE);
mdp->stats.tx_packets++;
mdp->stats.tx_bytes += txdesc->buffer_length;
}
return freeNum;
}
static int sh_eth_rx(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct sh_eth_rxdesc *rxdesc;
int entry = mdp->cur_rx % RX_RING_SIZE;
int boguscnt = (mdp->dirty_rx + RX_RING_SIZE) - mdp->cur_rx;
struct sk_buff *skb;
u16 pkt_len = 0;
u32 desc_status;
rxdesc = &mdp->rx_ring[entry];
while (!(rxdesc->status & cpu_to_edmac(mdp, RD_RACT))) {
desc_status = edmac_to_cpu(mdp, rxdesc->status);
pkt_len = rxdesc->frame_length;
if (--boguscnt < 0)
break;
if (!(desc_status & RDFEND))
mdp->stats.rx_length_errors++;
if (desc_status & (RD_RFS1 | RD_RFS2 | RD_RFS3 | RD_RFS4 |
RD_RFS5 | RD_RFS6 | RD_RFS10)) {
mdp->stats.rx_errors++;
if (desc_status & RD_RFS1)
mdp->stats.rx_crc_errors++;
if (desc_status & RD_RFS2)
mdp->stats.rx_frame_errors++;
if (desc_status & RD_RFS3)
mdp->stats.rx_length_errors++;
if (desc_status & RD_RFS4)
mdp->stats.rx_length_errors++;
if (desc_status & RD_RFS6)
mdp->stats.rx_missed_errors++;
if (desc_status & RD_RFS10)
mdp->stats.rx_over_errors++;
} else {
if (!mdp->cd->hw_swap)
sh_eth_soft_swap(
phys_to_virt(ALIGN(rxdesc->addr, 4)),
pkt_len + 2);
skb = mdp->rx_skbuff[entry];
mdp->rx_skbuff[entry] = NULL;
if (mdp->cd->rpadir)
skb_reserve(skb, NET_IP_ALIGN);
skb_put(skb, pkt_len);
skb->protocol = eth_type_trans(skb, ndev);
netif_rx(skb);
mdp->stats.rx_packets++;
mdp->stats.rx_bytes += pkt_len;
}
rxdesc->status |= cpu_to_edmac(mdp, RD_RACT);
entry = (++mdp->cur_rx) % RX_RING_SIZE;
rxdesc = &mdp->rx_ring[entry];
}
for (; mdp->cur_rx - mdp->dirty_rx > 0; mdp->dirty_rx++) {
entry = mdp->dirty_rx % RX_RING_SIZE;
rxdesc = &mdp->rx_ring[entry];
rxdesc->buffer_length = ALIGN(mdp->rx_buf_sz, 16);
if (mdp->rx_skbuff[entry] == NULL) {
skb = dev_alloc_skb(mdp->rx_buf_sz);
mdp->rx_skbuff[entry] = skb;
if (skb == NULL)
break;
dma_map_single(&ndev->dev, skb->tail, mdp->rx_buf_sz,
DMA_FROM_DEVICE);
skb->dev = ndev;
sh_eth_set_receive_align(skb);
skb_checksum_none_assert(skb);
rxdesc->addr = virt_to_phys(PTR_ALIGN(skb->data, 4));
}
if (entry >= RX_RING_SIZE - 1)
rxdesc->status |=
cpu_to_edmac(mdp, RD_RACT | RD_RFP | RD_RDEL);
else
rxdesc->status |=
cpu_to_edmac(mdp, RD_RACT | RD_RFP);
}
if (!(sh_eth_read(ndev, EDRRR) & EDRRR_R))
sh_eth_write(ndev, EDRRR_R, EDRRR);
return 0;
}
static void sh_eth_rcv_snd_disable(struct net_device *ndev)
{
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) &
~(ECMR_RE | ECMR_TE), ECMR);
}
static void sh_eth_rcv_snd_enable(struct net_device *ndev)
{
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) |
(ECMR_RE | ECMR_TE), ECMR);
}
static void sh_eth_error(struct net_device *ndev, int intr_status)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
u32 felic_stat;
u32 link_stat;
u32 mask;
if (intr_status & EESR_ECI) {
felic_stat = sh_eth_read(ndev, ECSR);
sh_eth_write(ndev, felic_stat, ECSR);
if (felic_stat & ECSR_ICD)
mdp->stats.tx_carrier_errors++;
if (felic_stat & ECSR_LCHNG) {
if (mdp->cd->no_psr || mdp->no_ether_link) {
if (mdp->link == PHY_DOWN)
link_stat = 0;
else
link_stat = PHY_ST_LINK;
} else {
link_stat = (sh_eth_read(ndev, PSR));
if (mdp->ether_link_active_low)
link_stat = ~link_stat;
}
if (!(link_stat & PHY_ST_LINK))
sh_eth_rcv_snd_disable(ndev);
else {
sh_eth_write(ndev, sh_eth_read(ndev, EESIPR) &
~DMAC_M_ECI, EESIPR);
sh_eth_write(ndev, sh_eth_read(ndev, ECSR),
ECSR);
sh_eth_write(ndev, sh_eth_read(ndev, EESIPR) |
DMAC_M_ECI, EESIPR);
sh_eth_rcv_snd_enable(ndev);
}
}
}
if (intr_status & EESR_TWB) {
if (intr_status & EESR_TABT)
mdp->stats.tx_aborted_errors++;
if (netif_msg_tx_err(mdp))
dev_err(&ndev->dev, "Transmit Abort\n");
}
if (intr_status & EESR_RABT) {
if (intr_status & EESR_RFRMER) {
mdp->stats.rx_frame_errors++;
if (netif_msg_rx_err(mdp))
dev_err(&ndev->dev, "Receive Abort\n");
}
}
if (intr_status & EESR_TDE) {
mdp->stats.tx_fifo_errors++;
if (netif_msg_tx_err(mdp))
dev_err(&ndev->dev, "Transmit Descriptor Empty\n");
}
if (intr_status & EESR_TFE) {
mdp->stats.tx_fifo_errors++;
if (netif_msg_tx_err(mdp))
dev_err(&ndev->dev, "Transmit FIFO Under flow\n");
}
if (intr_status & EESR_RDE) {
mdp->stats.rx_over_errors++;
if (sh_eth_read(ndev, EDRRR) ^ EDRRR_R)
sh_eth_write(ndev, EDRRR_R, EDRRR);
if (netif_msg_rx_err(mdp))
dev_err(&ndev->dev, "Receive Descriptor Empty\n");
}
if (intr_status & EESR_RFE) {
mdp->stats.rx_fifo_errors++;
if (netif_msg_rx_err(mdp))
dev_err(&ndev->dev, "Receive FIFO Overflow\n");
}
if (!mdp->cd->no_ade && (intr_status & EESR_ADE)) {
mdp->stats.tx_fifo_errors++;
if (netif_msg_tx_err(mdp))
dev_err(&ndev->dev, "Address Error\n");
}
mask = EESR_TWB | EESR_TABT | EESR_ADE | EESR_TDE | EESR_TFE;
if (mdp->cd->no_ade)
mask &= ~EESR_ADE;
if (intr_status & mask) {
u32 edtrr = sh_eth_read(ndev, EDTRR);
dev_err(&ndev->dev, "TX error. status=%8.8x cur_tx=%8.8x ",
intr_status, mdp->cur_tx);
dev_err(&ndev->dev, "dirty_tx=%8.8x state=%8.8x EDTRR=%8.8x.\n",
mdp->dirty_tx, (u32) ndev->state, edtrr);
sh_eth_txfree(ndev);
if (edtrr ^ sh_eth_get_edtrr_trns(mdp)) {
sh_eth_write(ndev, sh_eth_get_edtrr_trns(mdp), EDTRR);
}
netif_wake_queue(ndev);
}
}
static irqreturn_t sh_eth_interrupt(int irq, void *netdev)
{
struct net_device *ndev = netdev;
struct sh_eth_private *mdp = netdev_priv(ndev);
struct sh_eth_cpu_data *cd = mdp->cd;
irqreturn_t ret = IRQ_NONE;
u32 intr_status = 0;
spin_lock(&mdp->lock);
intr_status = sh_eth_read(ndev, EESR);
if (intr_status & (EESR_FRC | EESR_RMAF | EESR_RRF |
EESR_RTLF | EESR_RTSF | EESR_PRE | EESR_CERF |
cd->tx_check | cd->eesr_err_check)) {
sh_eth_write(ndev, intr_status, EESR);
ret = IRQ_HANDLED;
} else
goto other_irq;
if (intr_status & (EESR_FRC |
EESR_RMAF |
EESR_RRF |
EESR_RTLF |
EESR_RTSF |
EESR_PRE |
EESR_CERF)){
sh_eth_rx(ndev);
}
if (intr_status & cd->tx_check) {
sh_eth_txfree(ndev);
netif_wake_queue(ndev);
}
if (intr_status & cd->eesr_err_check)
sh_eth_error(ndev, intr_status);
other_irq:
spin_unlock(&mdp->lock);
return ret;
}
static void sh_eth_timer(unsigned long data)
{
struct net_device *ndev = (struct net_device *)data;
struct sh_eth_private *mdp = netdev_priv(ndev);
mod_timer(&mdp->timer, jiffies + (10 * HZ));
}
static void sh_eth_adjust_link(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct phy_device *phydev = mdp->phydev;
int new_state = 0;
if (phydev->link != PHY_DOWN) {
if (phydev->duplex != mdp->duplex) {
new_state = 1;
mdp->duplex = phydev->duplex;
if (mdp->cd->set_duplex)
mdp->cd->set_duplex(ndev);
}
if (phydev->speed != mdp->speed) {
new_state = 1;
mdp->speed = phydev->speed;
if (mdp->cd->set_rate)
mdp->cd->set_rate(ndev);
}
if (mdp->link == PHY_DOWN) {
sh_eth_write(ndev,
(sh_eth_read(ndev, ECMR) & ~ECMR_TXF), ECMR);
new_state = 1;
mdp->link = phydev->link;
}
} else if (mdp->link) {
new_state = 1;
mdp->link = PHY_DOWN;
mdp->speed = 0;
mdp->duplex = -1;
}
if (new_state && netif_msg_link(mdp))
phy_print_status(phydev);
}
static int sh_eth_phy_init(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
char phy_id[MII_BUS_ID_SIZE + 3];
struct phy_device *phydev = NULL;
snprintf(phy_id, sizeof(phy_id), PHY_ID_FMT,
mdp->mii_bus->id , mdp->phy_id);
mdp->link = PHY_DOWN;
mdp->speed = 0;
mdp->duplex = -1;
phydev = phy_connect(ndev, phy_id, sh_eth_adjust_link,
0, mdp->phy_interface);
if (IS_ERR(phydev)) {
dev_err(&ndev->dev, "phy_connect failed\n");
return PTR_ERR(phydev);
}
dev_info(&ndev->dev, "attached phy %i to driver %s\n",
phydev->addr, phydev->drv->name);
mdp->phydev = phydev;
return 0;
}
static int sh_eth_phy_start(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int ret;
ret = sh_eth_phy_init(ndev);
if (ret)
return ret;
phy_write(mdp->phydev, MII_BMCR, BMCR_RESET);
phy_start(mdp->phydev);
return 0;
}
static int sh_eth_get_settings(struct net_device *ndev,
struct ethtool_cmd *ecmd)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
unsigned long flags;
int ret;
spin_lock_irqsave(&mdp->lock, flags);
ret = phy_ethtool_gset(mdp->phydev, ecmd);
spin_unlock_irqrestore(&mdp->lock, flags);
return ret;
}
static int sh_eth_set_settings(struct net_device *ndev,
struct ethtool_cmd *ecmd)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
unsigned long flags;
int ret;
spin_lock_irqsave(&mdp->lock, flags);
sh_eth_rcv_snd_disable(ndev);
ret = phy_ethtool_sset(mdp->phydev, ecmd);
if (ret)
goto error_exit;
if (ecmd->duplex == DUPLEX_FULL)
mdp->duplex = 1;
else
mdp->duplex = 0;
if (mdp->cd->set_duplex)
mdp->cd->set_duplex(ndev);
error_exit:
mdelay(1);
sh_eth_rcv_snd_enable(ndev);
spin_unlock_irqrestore(&mdp->lock, flags);
return ret;
}
static int sh_eth_nway_reset(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
unsigned long flags;
int ret;
spin_lock_irqsave(&mdp->lock, flags);
ret = phy_start_aneg(mdp->phydev);
spin_unlock_irqrestore(&mdp->lock, flags);
return ret;
}
static u32 sh_eth_get_msglevel(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
return mdp->msg_enable;
}
static void sh_eth_set_msglevel(struct net_device *ndev, u32 value)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
mdp->msg_enable = value;
}
static int sh_eth_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return SH_ETH_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void sh_eth_get_ethtool_stats(struct net_device *ndev,
struct ethtool_stats *stats, u64 *data)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int i = 0;
data[i++] = mdp->cur_rx;
data[i++] = mdp->cur_tx;
data[i++] = mdp->dirty_rx;
data[i++] = mdp->dirty_tx;
}
static void sh_eth_get_strings(struct net_device *ndev, u32 stringset, u8 *data)
{
switch (stringset) {
case ETH_SS_STATS:
memcpy(data, *sh_eth_gstrings_stats,
sizeof(sh_eth_gstrings_stats));
break;
}
}
static int sh_eth_open(struct net_device *ndev)
{
int ret = 0;
struct sh_eth_private *mdp = netdev_priv(ndev);
pm_runtime_get_sync(&mdp->pdev->dev);
ret = request_irq(ndev->irq, sh_eth_interrupt,
#if defined(CONFIG_CPU_SUBTYPE_SH7763) || \
defined(CONFIG_CPU_SUBTYPE_SH7764) || \
defined(CONFIG_CPU_SUBTYPE_SH7757)
IRQF_SHARED,
#else
0,
#endif
ndev->name, ndev);
if (ret) {
dev_err(&ndev->dev, "Can not assign IRQ number\n");
return ret;
}
ret = sh_eth_ring_init(ndev);
if (ret)
goto out_free_irq;
ret = sh_eth_dev_init(ndev);
if (ret)
goto out_free_irq;
ret = sh_eth_phy_start(ndev);
if (ret)
goto out_free_irq;
init_timer(&mdp->timer);
mdp->timer.expires = (jiffies + (24 * HZ)) / 10;
setup_timer(&mdp->timer, sh_eth_timer, (unsigned long)ndev);
return ret;
out_free_irq:
free_irq(ndev->irq, ndev);
pm_runtime_put_sync(&mdp->pdev->dev);
return ret;
}
static void sh_eth_tx_timeout(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct sh_eth_rxdesc *rxdesc;
int i;
netif_stop_queue(ndev);
if (netif_msg_timer(mdp))
dev_err(&ndev->dev, "%s: transmit timed out, status %8.8x,"
" resetting...\n", ndev->name, (int)sh_eth_read(ndev, EESR));
mdp->stats.tx_errors++;
del_timer_sync(&mdp->timer);
for (i = 0; i < RX_RING_SIZE; i++) {
rxdesc = &mdp->rx_ring[i];
rxdesc->status = 0;
rxdesc->addr = 0xBADF00D0;
if (mdp->rx_skbuff[i])
dev_kfree_skb(mdp->rx_skbuff[i]);
mdp->rx_skbuff[i] = NULL;
}
for (i = 0; i < TX_RING_SIZE; i++) {
if (mdp->tx_skbuff[i])
dev_kfree_skb(mdp->tx_skbuff[i]);
mdp->tx_skbuff[i] = NULL;
}
sh_eth_dev_init(ndev);
mdp->timer.expires = (jiffies + (24 * HZ)) / 10;
add_timer(&mdp->timer);
}
static int sh_eth_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct sh_eth_txdesc *txdesc;
u32 entry;
unsigned long flags;
spin_lock_irqsave(&mdp->lock, flags);
if ((mdp->cur_tx - mdp->dirty_tx) >= (TX_RING_SIZE - 4)) {
if (!sh_eth_txfree(ndev)) {
if (netif_msg_tx_queued(mdp))
dev_warn(&ndev->dev, "TxFD exhausted.\n");
netif_stop_queue(ndev);
spin_unlock_irqrestore(&mdp->lock, flags);
return NETDEV_TX_BUSY;
}
}
spin_unlock_irqrestore(&mdp->lock, flags);
entry = mdp->cur_tx % TX_RING_SIZE;
mdp->tx_skbuff[entry] = skb;
txdesc = &mdp->tx_ring[entry];
txdesc->addr = virt_to_phys(skb->data);
if (!mdp->cd->hw_swap)
sh_eth_soft_swap(phys_to_virt(ALIGN(txdesc->addr, 4)),
skb->len + 2);
__flush_purge_region(skb->data, skb->len);
if (skb->len < ETHERSMALL)
txdesc->buffer_length = ETHERSMALL;
else
txdesc->buffer_length = skb->len;
if (entry >= TX_RING_SIZE - 1)
txdesc->status |= cpu_to_edmac(mdp, TD_TACT | TD_TDLE);
else
txdesc->status |= cpu_to_edmac(mdp, TD_TACT);
mdp->cur_tx++;
if (!(sh_eth_read(ndev, EDTRR) & sh_eth_get_edtrr_trns(mdp)))
sh_eth_write(ndev, sh_eth_get_edtrr_trns(mdp), EDTRR);
return NETDEV_TX_OK;
}
static int sh_eth_close(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int ringsize;
netif_stop_queue(ndev);
sh_eth_write(ndev, 0x0000, EESIPR);
sh_eth_write(ndev, 0, EDTRR);
sh_eth_write(ndev, 0, EDRRR);
if (mdp->phydev) {
phy_stop(mdp->phydev);
phy_disconnect(mdp->phydev);
}
free_irq(ndev->irq, ndev);
del_timer_sync(&mdp->timer);
sh_eth_ring_free(ndev);
ringsize = sizeof(struct sh_eth_rxdesc) * RX_RING_SIZE;
dma_free_coherent(NULL, ringsize, mdp->rx_ring, mdp->rx_desc_dma);
ringsize = sizeof(struct sh_eth_txdesc) * TX_RING_SIZE;
dma_free_coherent(NULL, ringsize, mdp->tx_ring, mdp->tx_desc_dma);
pm_runtime_put_sync(&mdp->pdev->dev);
return 0;
}
static struct net_device_stats *sh_eth_get_stats(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
pm_runtime_get_sync(&mdp->pdev->dev);
mdp->stats.tx_dropped += sh_eth_read(ndev, TROCR);
sh_eth_write(ndev, 0, TROCR);
mdp->stats.collisions += sh_eth_read(ndev, CDCR);
sh_eth_write(ndev, 0, CDCR);
mdp->stats.tx_carrier_errors += sh_eth_read(ndev, LCCR);
sh_eth_write(ndev, 0, LCCR);
if (sh_eth_is_gether(mdp)) {
mdp->stats.tx_carrier_errors += sh_eth_read(ndev, CERCR);
sh_eth_write(ndev, 0, CERCR);
mdp->stats.tx_carrier_errors += sh_eth_read(ndev, CEECR);
sh_eth_write(ndev, 0, CEECR);
} else {
mdp->stats.tx_carrier_errors += sh_eth_read(ndev, CNDCR);
sh_eth_write(ndev, 0, CNDCR);
}
pm_runtime_put_sync(&mdp->pdev->dev);
return &mdp->stats;
}
static int sh_eth_do_ioctl(struct net_device *ndev, struct ifreq *rq,
int cmd)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct phy_device *phydev = mdp->phydev;
if (!netif_running(ndev))
return -EINVAL;
if (!phydev)
return -ENODEV;
return phy_mii_ioctl(phydev, rq, cmd);
}
static void sh_eth_set_multicast_list(struct net_device *ndev)
{
if (ndev->flags & IFF_PROMISC) {
sh_eth_write(ndev, (sh_eth_read(ndev, ECMR) & ~ECMR_MCT) |
ECMR_PRM, ECMR);
} else {
sh_eth_write(ndev, (sh_eth_read(ndev, ECMR) & ~ECMR_PRM) |
ECMR_MCT, ECMR);
}
}
static void sh_eth_tsu_init(struct sh_eth_private *mdp)
{
sh_eth_tsu_write(mdp, 0, TSU_FWEN0);
sh_eth_tsu_write(mdp, 0, TSU_FWEN1);
sh_eth_tsu_write(mdp, 0, TSU_FCM);
sh_eth_tsu_write(mdp, 0xc, TSU_BSYSL0);
sh_eth_tsu_write(mdp, 0xc, TSU_BSYSL1);
sh_eth_tsu_write(mdp, 0, TSU_PRISL0);
sh_eth_tsu_write(mdp, 0, TSU_PRISL1);
sh_eth_tsu_write(mdp, 0, TSU_FWSL0);
sh_eth_tsu_write(mdp, 0, TSU_FWSL1);
sh_eth_tsu_write(mdp, TSU_FWSLC_POSTENU | TSU_FWSLC_POSTENL, TSU_FWSLC);
if (sh_eth_is_gether(mdp)) {
sh_eth_tsu_write(mdp, 0, TSU_QTAG0);
sh_eth_tsu_write(mdp, 0, TSU_QTAG1);
} else {
sh_eth_tsu_write(mdp, 0, TSU_QTAGM0);
sh_eth_tsu_write(mdp, 0, TSU_QTAGM1);
}
sh_eth_tsu_write(mdp, 0, TSU_FWSR);
sh_eth_tsu_write(mdp, 0, TSU_FWINMK);
sh_eth_tsu_write(mdp, 0, TSU_TEN);
sh_eth_tsu_write(mdp, 0, TSU_POST1);
sh_eth_tsu_write(mdp, 0, TSU_POST2);
sh_eth_tsu_write(mdp, 0, TSU_POST3);
sh_eth_tsu_write(mdp, 0, TSU_POST4);
}
static int sh_mdio_release(struct net_device *ndev)
{
struct mii_bus *bus = dev_get_drvdata(&ndev->dev);
mdiobus_unregister(bus);
dev_set_drvdata(&ndev->dev, NULL);
kfree(bus->irq);
free_mdio_bitbang(bus);
return 0;
}
static int sh_mdio_init(struct net_device *ndev, int id,
struct sh_eth_plat_data *pd)
{
int ret, i;
struct bb_info *bitbang;
struct sh_eth_private *mdp = netdev_priv(ndev);
bitbang = kzalloc(sizeof(struct bb_info), GFP_KERNEL);
if (!bitbang) {
ret = -ENOMEM;
goto out;
}
bitbang->addr = ndev->base_addr + mdp->reg_offset[PIR];
bitbang->set_gate = pd->set_mdio_gate;
bitbang->mdi_msk = 0x08;
bitbang->mdo_msk = 0x04;
bitbang->mmd_msk = 0x02;
bitbang->mdc_msk = 0x01;
bitbang->ctrl.ops = &bb_ops;
mdp->mii_bus = alloc_mdio_bitbang(&bitbang->ctrl);
if (!mdp->mii_bus) {
ret = -ENOMEM;
goto out_free_bitbang;
}
mdp->mii_bus->name = "sh_mii";
mdp->mii_bus->parent = &ndev->dev;
snprintf(mdp->mii_bus->id, MII_BUS_ID_SIZE, "%x", id);
mdp->mii_bus->irq = kmalloc(sizeof(int)*PHY_MAX_ADDR, GFP_KERNEL);
if (!mdp->mii_bus->irq) {
ret = -ENOMEM;
goto out_free_bus;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
mdp->mii_bus->irq[i] = PHY_POLL;
ret = mdiobus_register(mdp->mii_bus);
if (ret)
goto out_free_irq;
dev_set_drvdata(&ndev->dev, mdp->mii_bus);
return 0;
out_free_irq:
kfree(mdp->mii_bus->irq);
out_free_bus:
free_mdio_bitbang(mdp->mii_bus);
out_free_bitbang:
kfree(bitbang);
out:
return ret;
}
static const u16 *sh_eth_get_register_offset(int register_type)
{
const u16 *reg_offset = NULL;
switch (register_type) {
case SH_ETH_REG_GIGABIT:
reg_offset = sh_eth_offset_gigabit;
break;
case SH_ETH_REG_FAST_SH4:
reg_offset = sh_eth_offset_fast_sh4;
break;
case SH_ETH_REG_FAST_SH3_SH2:
reg_offset = sh_eth_offset_fast_sh3_sh2;
break;
default:
printk(KERN_ERR "Unknown register type (%d)\n", register_type);
break;
}
return reg_offset;
}
static int sh_eth_drv_probe(struct platform_device *pdev)
{
int ret, devno = 0;
struct resource *res;
struct net_device *ndev = NULL;
struct sh_eth_private *mdp;
struct sh_eth_plat_data *pd;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(res == NULL)) {
dev_err(&pdev->dev, "invalid resource\n");
ret = -EINVAL;
goto out;
}
ndev = alloc_etherdev(sizeof(struct sh_eth_private));
if (!ndev) {
dev_err(&pdev->dev, "Could not allocate device.\n");
ret = -ENOMEM;
goto out;
}
ndev->base_addr = res->start;
devno = pdev->id;
if (devno < 0)
devno = 0;
ndev->dma = -1;
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
ret = -ENODEV;
goto out_release;
}
ndev->irq = ret;
SET_NETDEV_DEV(ndev, &pdev->dev);
ether_setup(ndev);
mdp = netdev_priv(ndev);
spin_lock_init(&mdp->lock);
mdp->pdev = pdev;
pm_runtime_enable(&pdev->dev);
pm_runtime_resume(&pdev->dev);
pd = (struct sh_eth_plat_data *)(pdev->dev.platform_data);
mdp->phy_id = pd->phy;
mdp->phy_interface = pd->phy_interface;
mdp->edmac_endian = pd->edmac_endian;
mdp->no_ether_link = pd->no_ether_link;
mdp->ether_link_active_low = pd->ether_link_active_low;
mdp->reg_offset = sh_eth_get_register_offset(pd->register_type);
#if defined(SH_ETH_HAS_BOTH_MODULES)
mdp->cd = sh_eth_get_cpu_data(mdp);
#else
mdp->cd = &sh_eth_my_cpu_data;
#endif
sh_eth_set_default_cpu_data(mdp->cd);
ndev->netdev_ops = &sh_eth_netdev_ops;
SET_ETHTOOL_OPS(ndev, &sh_eth_ethtool_ops);
ndev->watchdog_timeo = TX_TIMEOUT;
mdp->msg_enable = SH_ETH_DEF_MSG_ENABLE;
mdp->post_rx = POST_RX >> (devno << 1);
mdp->post_fw = POST_FW >> (devno << 1);
read_mac_address(ndev, pd->mac_addr);
if (!devno) {
if (mdp->cd->tsu) {
struct resource *rtsu;
rtsu = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!rtsu) {
dev_err(&pdev->dev, "Not found TSU resource\n");
goto out_release;
}
mdp->tsu_addr = ioremap(rtsu->start,
resource_size(rtsu));
}
if (mdp->cd->chip_reset)
mdp->cd->chip_reset(ndev);
if (mdp->cd->tsu) {
sh_eth_tsu_init(mdp);
}
}
ret = register_netdev(ndev);
if (ret)
goto out_release;
ret = sh_mdio_init(ndev, pdev->id, pd);
if (ret)
goto out_unregister;
pr_info("Base address at 0x%x, %pM, IRQ %d.\n",
(u32)ndev->base_addr, ndev->dev_addr, ndev->irq);
platform_set_drvdata(pdev, ndev);
return ret;
out_unregister:
unregister_netdev(ndev);
out_release:
if (mdp->tsu_addr)
iounmap(mdp->tsu_addr);
if (ndev)
free_netdev(ndev);
out:
return ret;
}
static int sh_eth_drv_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct sh_eth_private *mdp = netdev_priv(ndev);
iounmap(mdp->tsu_addr);
sh_mdio_release(ndev);
unregister_netdev(ndev);
pm_runtime_disable(&pdev->dev);
free_netdev(ndev);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int sh_eth_runtime_nop(struct device *dev)
{
return 0;
}
static int __init sh_eth_init(void)
{
return platform_driver_register(&sh_eth_driver);
}
static void __exit sh_eth_cleanup(void)
{
platform_driver_unregister(&sh_eth_driver);
}
