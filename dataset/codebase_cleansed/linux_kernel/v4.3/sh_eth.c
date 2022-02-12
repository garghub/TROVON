static bool sh_eth_is_gether(struct sh_eth_private *mdp)
{
return mdp->reg_offset == sh_eth_offset_gigabit;
}
static bool sh_eth_is_rz_fast_ether(struct sh_eth_private *mdp)
{
return mdp->reg_offset == sh_eth_offset_fast_rz;
}
static void sh_eth_select_mii(struct net_device *ndev)
{
u32 value = 0x0;
struct sh_eth_private *mdp = netdev_priv(ndev);
switch (mdp->phy_interface) {
case PHY_INTERFACE_MODE_GMII:
value = 0x2;
break;
case PHY_INTERFACE_MODE_MII:
value = 0x1;
break;
case PHY_INTERFACE_MODE_RMII:
value = 0x0;
break;
default:
netdev_warn(ndev,
"PHY interface mode was not setup. Set to MII.\n");
value = 0x1;
break;
}
sh_eth_write(ndev, value, RMII_MII);
}
static void sh_eth_set_duplex(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
if (mdp->duplex)
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) | ECMR_DM, ECMR);
else
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) & ~ECMR_DM, ECMR);
}
static void sh_eth_set_rate_r8a777x(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
switch (mdp->speed) {
case 10:
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) & ~ECMR_ELB, ECMR);
break;
case 100:
sh_eth_write(ndev, sh_eth_read(ndev, ECMR) | ECMR_ELB, ECMR);
break;
default:
break;
}
}
static void sh_eth_set_rate_sh7724(struct net_device *ndev)
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
static void sh_eth_set_rate_sh7757(struct net_device *ndev)
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
u32 mahr[2], malr[2];
for (i = 0; i < 2; i++) {
malr[i] = ioread32((void *)GIGA_MALR(i));
mahr[i] = ioread32((void *)GIGA_MAHR(i));
}
iowrite32(ARSTR_ARSTR, (void *)(SH_GIGA_ETH_BASE + 0x1800));
mdelay(1);
for (i = 0; i < 2; i++) {
iowrite32(malr[i], (void *)GIGA_MALR(i));
iowrite32(mahr[i], (void *)GIGA_MAHR(i));
}
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
static void sh_eth_chip_reset(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
sh_eth_tsu_write(mdp, ARSTR_ARSTR, ARSTR);
mdelay(1);
}
static void sh_eth_set_rate_gether(struct net_device *ndev)
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
static void sh_eth_chip_reset_r8a7740(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
sh_eth_tsu_write(mdp, ARSTR_ARSTR, ARSTR);
mdelay(1);
sh_eth_select_mii(ndev);
}
static void sh_eth_set_default_cpu_data(struct sh_eth_cpu_data *cd)
{
if (!cd->ecsr_value)
cd->ecsr_value = DEFAULT_ECSR_INIT;
if (!cd->ecsipr_value)
cd->ecsipr_value = DEFAULT_ECSIPR_INIT;
if (!cd->fcftr_value)
cd->fcftr_value = DEFAULT_FIFO_F_D_RFF |
DEFAULT_FIFO_F_D_RFD;
if (!cd->fdr_value)
cd->fdr_value = DEFAULT_FDR_INIT;
if (!cd->tx_check)
cd->tx_check = DEFAULT_TX_CHECK;
if (!cd->eesr_err_check)
cd->eesr_err_check = DEFAULT_EESR_ERR_CHECK;
if (!cd->trscer_err_mask)
cd->trscer_err_mask = DEFAULT_TRSCER_ERR_MASK;
}
static int sh_eth_check_reset(struct net_device *ndev)
{
int ret = 0;
int cnt = 100;
while (cnt > 0) {
if (!(sh_eth_read(ndev, EDMR) & 0x3))
break;
mdelay(1);
cnt--;
}
if (cnt <= 0) {
netdev_err(ndev, "Device reset failed\n");
ret = -ETIMEDOUT;
}
return ret;
}
static int sh_eth_reset(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int ret = 0;
if (sh_eth_is_gether(mdp) || sh_eth_is_rz_fast_ether(mdp)) {
sh_eth_write(ndev, EDSR_ENALL, EDSR);
sh_eth_write(ndev, sh_eth_read(ndev, EDMR) | EDMR_SRST_GETHER,
EDMR);
ret = sh_eth_check_reset(ndev);
if (ret)
return ret;
sh_eth_write(ndev, 0x0, TDLAR);
sh_eth_write(ndev, 0x0, TDFAR);
sh_eth_write(ndev, 0x0, TDFXR);
sh_eth_write(ndev, 0x0, TDFFR);
sh_eth_write(ndev, 0x0, RDLAR);
sh_eth_write(ndev, 0x0, RDFAR);
sh_eth_write(ndev, 0x0, RDFXR);
sh_eth_write(ndev, 0x0, RDFFR);
if (mdp->cd->hw_crc)
sh_eth_write(ndev, 0x0, CSMR);
if (mdp->cd->select_mii)
sh_eth_select_mii(ndev);
} else {
sh_eth_write(ndev, sh_eth_read(ndev, EDMR) | EDMR_SRST_ETHER,
EDMR);
mdelay(3);
sh_eth_write(ndev, sh_eth_read(ndev, EDMR) & ~EDMR_SRST_ETHER,
EDMR);
}
return ret;
}
static void sh_eth_set_receive_align(struct sk_buff *skb)
{
uintptr_t reserve = (uintptr_t)skb->data & (SH_ETH_RX_ALIGN - 1);
if (reserve)
skb_reserve(skb, SH_ETH_RX_ALIGN - reserve);
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
memcpy(ndev->dev_addr, mac, ETH_ALEN);
} else {
ndev->dev_addr[0] = (sh_eth_read(ndev, MAHR) >> 24);
ndev->dev_addr[1] = (sh_eth_read(ndev, MAHR) >> 16) & 0xFF;
ndev->dev_addr[2] = (sh_eth_read(ndev, MAHR) >> 8) & 0xFF;
ndev->dev_addr[3] = (sh_eth_read(ndev, MAHR) & 0xFF);
ndev->dev_addr[4] = (sh_eth_read(ndev, MALR) >> 8) & 0xFF;
ndev->dev_addr[5] = (sh_eth_read(ndev, MALR) & 0xFF);
}
}
static u32 sh_eth_get_edtrr_trns(struct sh_eth_private *mdp)
{
if (sh_eth_is_gether(mdp) || sh_eth_is_rz_fast_ether(mdp))
return EDTRR_TRNS_GETHER;
else
return EDTRR_TRNS_ETHER;
}
static void bb_set(void *addr, u32 msk)
{
iowrite32(ioread32(addr) | msk, addr);
}
static void bb_clr(void *addr, u32 msk)
{
iowrite32((ioread32(addr) & ~msk), addr);
}
static int bb_read(void *addr, u32 msk)
{
return (ioread32(addr) & msk) != 0;
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
for (i = 0; i < mdp->num_rx_ring; i++)
dev_kfree_skb(mdp->rx_skbuff[i]);
}
kfree(mdp->rx_skbuff);
mdp->rx_skbuff = NULL;
if (mdp->tx_skbuff) {
for (i = 0; i < mdp->num_tx_ring; i++)
dev_kfree_skb(mdp->tx_skbuff[i]);
}
kfree(mdp->tx_skbuff);
mdp->tx_skbuff = NULL;
}
static void sh_eth_ring_format(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int i;
struct sk_buff *skb;
struct sh_eth_rxdesc *rxdesc = NULL;
struct sh_eth_txdesc *txdesc = NULL;
int rx_ringsize = sizeof(*rxdesc) * mdp->num_rx_ring;
int tx_ringsize = sizeof(*txdesc) * mdp->num_tx_ring;
int skbuff_size = mdp->rx_buf_sz + SH_ETH_RX_ALIGN + 32 - 1;
dma_addr_t dma_addr;
mdp->cur_rx = 0;
mdp->cur_tx = 0;
mdp->dirty_rx = 0;
mdp->dirty_tx = 0;
memset(mdp->rx_ring, 0, rx_ringsize);
for (i = 0; i < mdp->num_rx_ring; i++) {
mdp->rx_skbuff[i] = NULL;
skb = netdev_alloc_skb(ndev, skbuff_size);
if (skb == NULL)
break;
sh_eth_set_receive_align(skb);
rxdesc = &mdp->rx_ring[i];
rxdesc->buffer_length = ALIGN(mdp->rx_buf_sz, 32);
dma_addr = dma_map_single(&ndev->dev, skb->data,
rxdesc->buffer_length,
DMA_FROM_DEVICE);
if (dma_mapping_error(&ndev->dev, dma_addr)) {
kfree_skb(skb);
break;
}
mdp->rx_skbuff[i] = skb;
rxdesc->addr = dma_addr;
rxdesc->status = cpu_to_edmac(mdp, RD_RACT | RD_RFP);
if (i == 0) {
sh_eth_write(ndev, mdp->rx_desc_dma, RDLAR);
if (sh_eth_is_gether(mdp) ||
sh_eth_is_rz_fast_ether(mdp))
sh_eth_write(ndev, mdp->rx_desc_dma, RDFAR);
}
}
mdp->dirty_rx = (u32) (i - mdp->num_rx_ring);
rxdesc->status |= cpu_to_edmac(mdp, RD_RDEL);
memset(mdp->tx_ring, 0, tx_ringsize);
for (i = 0; i < mdp->num_tx_ring; i++) {
mdp->tx_skbuff[i] = NULL;
txdesc = &mdp->tx_ring[i];
txdesc->status = cpu_to_edmac(mdp, TD_TFP);
txdesc->buffer_length = 0;
if (i == 0) {
sh_eth_write(ndev, mdp->tx_desc_dma, TDLAR);
if (sh_eth_is_gether(mdp) ||
sh_eth_is_rz_fast_ether(mdp))
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
mdp->rx_skbuff = kmalloc_array(mdp->num_rx_ring,
sizeof(*mdp->rx_skbuff), GFP_KERNEL);
if (!mdp->rx_skbuff) {
ret = -ENOMEM;
return ret;
}
mdp->tx_skbuff = kmalloc_array(mdp->num_tx_ring,
sizeof(*mdp->tx_skbuff), GFP_KERNEL);
if (!mdp->tx_skbuff) {
ret = -ENOMEM;
goto skb_ring_free;
}
rx_ringsize = sizeof(struct sh_eth_rxdesc) * mdp->num_rx_ring;
mdp->rx_ring = dma_alloc_coherent(NULL, rx_ringsize, &mdp->rx_desc_dma,
GFP_KERNEL);
if (!mdp->rx_ring) {
ret = -ENOMEM;
goto desc_ring_free;
}
mdp->dirty_rx = 0;
tx_ringsize = sizeof(struct sh_eth_txdesc) * mdp->num_tx_ring;
mdp->tx_ring = dma_alloc_coherent(NULL, tx_ringsize, &mdp->tx_desc_dma,
GFP_KERNEL);
if (!mdp->tx_ring) {
ret = -ENOMEM;
goto desc_ring_free;
}
return ret;
desc_ring_free:
dma_free_coherent(NULL, rx_ringsize, mdp->rx_ring, mdp->rx_desc_dma);
skb_ring_free:
sh_eth_ring_free(ndev);
mdp->tx_ring = NULL;
mdp->rx_ring = NULL;
return ret;
}
static void sh_eth_free_dma_buffer(struct sh_eth_private *mdp)
{
int ringsize;
if (mdp->rx_ring) {
ringsize = sizeof(struct sh_eth_rxdesc) * mdp->num_rx_ring;
dma_free_coherent(NULL, ringsize, mdp->rx_ring,
mdp->rx_desc_dma);
mdp->rx_ring = NULL;
}
if (mdp->tx_ring) {
ringsize = sizeof(struct sh_eth_txdesc) * mdp->num_tx_ring;
dma_free_coherent(NULL, ringsize, mdp->tx_ring,
mdp->tx_desc_dma);
mdp->tx_ring = NULL;
}
}
static int sh_eth_dev_init(struct net_device *ndev, bool start)
{
int ret = 0;
struct sh_eth_private *mdp = netdev_priv(ndev);
u32 val;
ret = sh_eth_reset(ndev);
if (ret)
return ret;
if (mdp->cd->rmiimode)
sh_eth_write(ndev, 0x1, RMIIMODE);
sh_eth_ring_format(ndev);
if (mdp->cd->rpadir)
sh_eth_write(ndev, mdp->cd->rpadir_value, RPADIR);
sh_eth_write(ndev, 0, EESIPR);
#if defined(__LITTLE_ENDIAN)
if (mdp->cd->hw_swap)
sh_eth_write(ndev, EDMR_EL, EDMR);
else
#endif
sh_eth_write(ndev, 0, EDMR);
sh_eth_write(ndev, mdp->cd->fdr_value, FDR);
sh_eth_write(ndev, 0, TFTR);
sh_eth_write(ndev, RMCR_RNC, RMCR);
sh_eth_write(ndev, mdp->cd->trscer_err_mask, TRSCER);
if (mdp->cd->bculr)
sh_eth_write(ndev, 0x800, BCULR);
sh_eth_write(ndev, mdp->cd->fcftr_value, FCFTR);
if (!mdp->cd->no_trimd)
sh_eth_write(ndev, 0, TRIMD);
sh_eth_write(ndev, ndev->mtu + ETH_HLEN + VLAN_HLEN + ETH_FCS_LEN,
RFLR);
sh_eth_write(ndev, sh_eth_read(ndev, EESR), EESR);
if (start) {
mdp->irq_enabled = true;
sh_eth_write(ndev, mdp->cd->eesipr_value, EESIPR);
}
val = (sh_eth_read(ndev, ECMR) & ECMR_DM) |
ECMR_ZPF | (mdp->duplex ? ECMR_DM : 0) | ECMR_TE | ECMR_RE;
sh_eth_write(ndev, val, ECMR);
if (mdp->cd->set_rate)
mdp->cd->set_rate(ndev);
sh_eth_write(ndev, mdp->cd->ecsr_value, ECSR);
if (start)
sh_eth_write(ndev, mdp->cd->ecsipr_value, ECSIPR);
update_mac_address(ndev);
if (mdp->cd->apr)
sh_eth_write(ndev, APR_AP, APR);
if (mdp->cd->mpr)
sh_eth_write(ndev, MPR_MP, MPR);
if (mdp->cd->tpauser)
sh_eth_write(ndev, TPAUSER_UNLIMITED, TPAUSER);
if (start) {
sh_eth_write(ndev, EDRRR_R, EDRRR);
netif_start_queue(ndev);
}
return ret;
}
static void sh_eth_dev_exit(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int i;
for (i = 0; i < mdp->num_tx_ring; i++)
mdp->tx_ring[i].status &= ~cpu_to_edmac(mdp, TD_TACT);
sh_eth_rcv_snd_disable(ndev);
sh_eth_write(ndev, 0, EDRRR);
msleep(2);
sh_eth_get_stats(ndev);
sh_eth_reset(ndev);
update_mac_address(ndev);
}
static int sh_eth_txfree(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct sh_eth_txdesc *txdesc;
int free_num = 0;
int entry = 0;
for (; mdp->cur_tx - mdp->dirty_tx > 0; mdp->dirty_tx++) {
entry = mdp->dirty_tx % mdp->num_tx_ring;
txdesc = &mdp->tx_ring[entry];
if (txdesc->status & cpu_to_edmac(mdp, TD_TACT))
break;
rmb();
netif_info(mdp, tx_done, ndev,
"tx entry %d status 0x%08x\n",
entry, edmac_to_cpu(mdp, txdesc->status));
if (mdp->tx_skbuff[entry]) {
dma_unmap_single(&ndev->dev, txdesc->addr,
txdesc->buffer_length, DMA_TO_DEVICE);
dev_kfree_skb_irq(mdp->tx_skbuff[entry]);
mdp->tx_skbuff[entry] = NULL;
free_num++;
}
txdesc->status = cpu_to_edmac(mdp, TD_TFP);
if (entry >= mdp->num_tx_ring - 1)
txdesc->status |= cpu_to_edmac(mdp, TD_TDLE);
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += txdesc->buffer_length;
}
return free_num;
}
static int sh_eth_rx(struct net_device *ndev, u32 intr_status, int *quota)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct sh_eth_rxdesc *rxdesc;
int entry = mdp->cur_rx % mdp->num_rx_ring;
int boguscnt = (mdp->dirty_rx + mdp->num_rx_ring) - mdp->cur_rx;
int limit;
struct sk_buff *skb;
u16 pkt_len = 0;
u32 desc_status;
int skbuff_size = mdp->rx_buf_sz + SH_ETH_RX_ALIGN + 32 - 1;
dma_addr_t dma_addr;
boguscnt = min(boguscnt, *quota);
limit = boguscnt;
rxdesc = &mdp->rx_ring[entry];
while (!(rxdesc->status & cpu_to_edmac(mdp, RD_RACT))) {
rmb();
desc_status = edmac_to_cpu(mdp, rxdesc->status);
pkt_len = rxdesc->frame_length;
if (--boguscnt < 0)
break;
netif_info(mdp, rx_status, ndev,
"rx entry %d status 0x%08x len %d\n",
entry, desc_status, pkt_len);
if (!(desc_status & RDFEND))
ndev->stats.rx_length_errors++;
if (mdp->cd->shift_rd0)
desc_status >>= 16;
if (desc_status & (RD_RFS1 | RD_RFS2 | RD_RFS3 | RD_RFS4 |
RD_RFS5 | RD_RFS6 | RD_RFS10)) {
ndev->stats.rx_errors++;
if (desc_status & RD_RFS1)
ndev->stats.rx_crc_errors++;
if (desc_status & RD_RFS2)
ndev->stats.rx_frame_errors++;
if (desc_status & RD_RFS3)
ndev->stats.rx_length_errors++;
if (desc_status & RD_RFS4)
ndev->stats.rx_length_errors++;
if (desc_status & RD_RFS6)
ndev->stats.rx_missed_errors++;
if (desc_status & RD_RFS10)
ndev->stats.rx_over_errors++;
} else {
if (!mdp->cd->hw_swap)
sh_eth_soft_swap(
phys_to_virt(ALIGN(rxdesc->addr, 4)),
pkt_len + 2);
skb = mdp->rx_skbuff[entry];
mdp->rx_skbuff[entry] = NULL;
if (mdp->cd->rpadir)
skb_reserve(skb, NET_IP_ALIGN);
dma_unmap_single(&ndev->dev, rxdesc->addr,
ALIGN(mdp->rx_buf_sz, 32),
DMA_FROM_DEVICE);
skb_put(skb, pkt_len);
skb->protocol = eth_type_trans(skb, ndev);
netif_receive_skb(skb);
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += pkt_len;
if (desc_status & RD_RFS8)
ndev->stats.multicast++;
}
entry = (++mdp->cur_rx) % mdp->num_rx_ring;
rxdesc = &mdp->rx_ring[entry];
}
for (; mdp->cur_rx - mdp->dirty_rx > 0; mdp->dirty_rx++) {
entry = mdp->dirty_rx % mdp->num_rx_ring;
rxdesc = &mdp->rx_ring[entry];
rxdesc->buffer_length = ALIGN(mdp->rx_buf_sz, 32);
if (mdp->rx_skbuff[entry] == NULL) {
skb = netdev_alloc_skb(ndev, skbuff_size);
if (skb == NULL)
break;
sh_eth_set_receive_align(skb);
dma_addr = dma_map_single(&ndev->dev, skb->data,
rxdesc->buffer_length,
DMA_FROM_DEVICE);
if (dma_mapping_error(&ndev->dev, dma_addr)) {
kfree_skb(skb);
break;
}
mdp->rx_skbuff[entry] = skb;
skb_checksum_none_assert(skb);
rxdesc->addr = dma_addr;
}
wmb();
if (entry >= mdp->num_rx_ring - 1)
rxdesc->status |=
cpu_to_edmac(mdp, RD_RACT | RD_RFP | RD_RDEL);
else
rxdesc->status |=
cpu_to_edmac(mdp, RD_RACT | RD_RFP);
}
if (!(sh_eth_read(ndev, EDRRR) & EDRRR_R)) {
if (intr_status & EESR_RDE &&
mdp->reg_offset[RDFAR] != SH_ETH_OFFSET_INVALID) {
u32 count = (sh_eth_read(ndev, RDFAR) -
sh_eth_read(ndev, RDLAR)) >> 4;
mdp->cur_rx = count;
mdp->dirty_rx = count;
}
sh_eth_write(ndev, EDRRR_R, EDRRR);
}
*quota -= limit - boguscnt - 1;
return *quota <= 0;
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
static void sh_eth_error(struct net_device *ndev, u32 intr_status)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
u32 felic_stat;
u32 link_stat;
u32 mask;
if (intr_status & EESR_ECI) {
felic_stat = sh_eth_read(ndev, ECSR);
sh_eth_write(ndev, felic_stat, ECSR);
if (felic_stat & ECSR_ICD)
ndev->stats.tx_carrier_errors++;
if (felic_stat & ECSR_LCHNG) {
if (mdp->cd->no_psr || mdp->no_ether_link) {
goto ignore_link;
} else {
link_stat = (sh_eth_read(ndev, PSR));
if (mdp->ether_link_active_low)
link_stat = ~link_stat;
}
if (!(link_stat & PHY_ST_LINK)) {
sh_eth_rcv_snd_disable(ndev);
} else {
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
ignore_link:
if (intr_status & EESR_TWB) {
if (intr_status & EESR_TABT) {
ndev->stats.tx_aborted_errors++;
netif_err(mdp, tx_err, ndev, "Transmit Abort\n");
}
}
if (intr_status & EESR_RABT) {
if (intr_status & EESR_RFRMER) {
ndev->stats.rx_frame_errors++;
}
}
if (intr_status & EESR_TDE) {
ndev->stats.tx_fifo_errors++;
netif_err(mdp, tx_err, ndev, "Transmit Descriptor Empty\n");
}
if (intr_status & EESR_TFE) {
ndev->stats.tx_fifo_errors++;
netif_err(mdp, tx_err, ndev, "Transmit FIFO Under flow\n");
}
if (intr_status & EESR_RDE) {
ndev->stats.rx_over_errors++;
}
if (intr_status & EESR_RFE) {
ndev->stats.rx_fifo_errors++;
}
if (!mdp->cd->no_ade && (intr_status & EESR_ADE)) {
ndev->stats.tx_fifo_errors++;
netif_err(mdp, tx_err, ndev, "Address Error\n");
}
mask = EESR_TWB | EESR_TABT | EESR_ADE | EESR_TDE | EESR_TFE;
if (mdp->cd->no_ade)
mask &= ~EESR_ADE;
if (intr_status & mask) {
u32 edtrr = sh_eth_read(ndev, EDTRR);
netdev_err(ndev, "TX error. status=%8.8x cur_tx=%8.8x dirty_tx=%8.8x state=%8.8x EDTRR=%8.8x.\n",
intr_status, mdp->cur_tx, mdp->dirty_tx,
(u32)ndev->state, edtrr);
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
u32 intr_status, intr_enable;
spin_lock(&mdp->lock);
intr_status = sh_eth_read(ndev, EESR);
intr_enable = sh_eth_read(ndev, EESIPR);
intr_status &= intr_enable | DMAC_M_ECI;
if (intr_status & (EESR_RX_CHECK | cd->tx_check | cd->eesr_err_check))
ret = IRQ_HANDLED;
else
goto out;
if (!likely(mdp->irq_enabled)) {
sh_eth_write(ndev, 0, EESIPR);
goto out;
}
if (intr_status & EESR_RX_CHECK) {
if (napi_schedule_prep(&mdp->napi)) {
sh_eth_write(ndev, intr_enable & ~EESR_RX_CHECK,
EESIPR);
__napi_schedule(&mdp->napi);
} else {
netdev_warn(ndev,
"ignoring interrupt, status 0x%08x, mask 0x%08x.\n",
intr_status, intr_enable);
}
}
if (intr_status & cd->tx_check) {
sh_eth_write(ndev, intr_status & cd->tx_check, EESR);
sh_eth_txfree(ndev);
netif_wake_queue(ndev);
}
if (intr_status & cd->eesr_err_check) {
sh_eth_write(ndev, intr_status & cd->eesr_err_check, EESR);
sh_eth_error(ndev, intr_status);
}
out:
spin_unlock(&mdp->lock);
return ret;
}
static int sh_eth_poll(struct napi_struct *napi, int budget)
{
struct sh_eth_private *mdp = container_of(napi, struct sh_eth_private,
napi);
struct net_device *ndev = napi->dev;
int quota = budget;
u32 intr_status;
for (;;) {
intr_status = sh_eth_read(ndev, EESR);
if (!(intr_status & EESR_RX_CHECK))
break;
sh_eth_write(ndev, intr_status & EESR_RX_CHECK, EESR);
if (sh_eth_rx(ndev, intr_status, &quota))
goto out;
}
napi_complete(napi);
if (mdp->irq_enabled)
sh_eth_write(ndev, mdp->cd->eesipr_value, EESIPR);
out:
return budget - quota;
}
static void sh_eth_adjust_link(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct phy_device *phydev = mdp->phydev;
int new_state = 0;
if (phydev->link) {
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
if (!mdp->link) {
sh_eth_write(ndev,
sh_eth_read(ndev, ECMR) & ~ECMR_TXF,
ECMR);
new_state = 1;
mdp->link = phydev->link;
if (mdp->cd->no_psr || mdp->no_ether_link)
sh_eth_rcv_snd_enable(ndev);
}
} else if (mdp->link) {
new_state = 1;
mdp->link = 0;
mdp->speed = 0;
mdp->duplex = -1;
if (mdp->cd->no_psr || mdp->no_ether_link)
sh_eth_rcv_snd_disable(ndev);
}
if (new_state && netif_msg_link(mdp))
phy_print_status(phydev);
}
static int sh_eth_phy_init(struct net_device *ndev)
{
struct device_node *np = ndev->dev.parent->of_node;
struct sh_eth_private *mdp = netdev_priv(ndev);
struct phy_device *phydev = NULL;
mdp->link = 0;
mdp->speed = 0;
mdp->duplex = -1;
if (np) {
struct device_node *pn;
pn = of_parse_phandle(np, "phy-handle", 0);
phydev = of_phy_connect(ndev, pn,
sh_eth_adjust_link, 0,
mdp->phy_interface);
if (!phydev)
phydev = ERR_PTR(-ENOENT);
} else {
char phy_id[MII_BUS_ID_SIZE + 3];
snprintf(phy_id, sizeof(phy_id), PHY_ID_FMT,
mdp->mii_bus->id, mdp->phy_id);
phydev = phy_connect(ndev, phy_id, sh_eth_adjust_link,
mdp->phy_interface);
}
if (IS_ERR(phydev)) {
netdev_err(ndev, "failed to connect PHY\n");
return PTR_ERR(phydev);
}
netdev_info(ndev, "attached PHY %d (IRQ %d) to driver %s\n",
phydev->addr, phydev->irq, phydev->drv->name);
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
phy_start(mdp->phydev);
return 0;
}
static int sh_eth_get_settings(struct net_device *ndev,
struct ethtool_cmd *ecmd)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
unsigned long flags;
int ret;
if (!mdp->phydev)
return -ENODEV;
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
if (!mdp->phydev)
return -ENODEV;
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
static size_t __sh_eth_get_regs(struct net_device *ndev, u32 *buf)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct sh_eth_cpu_data *cd = mdp->cd;
u32 *valid_map;
size_t len;
BUILD_BUG_ON(SH_ETH_MAX_REGISTER_OFFSET > SH_ETH_REG_DUMP_MAX_REGS);
len = DIV_ROUND_UP(SH_ETH_REG_DUMP_MAX_REGS, 32);
if (buf) {
valid_map = buf;
buf += len;
} else {
valid_map = NULL;
}
#define mark_reg_valid(reg) valid_map[reg / 32] |= 1U << (reg % 32)
#define add_reg_from(reg, read_expr) do { \
if (mdp->reg_offset[reg] != SH_ETH_OFFSET_INVALID) { \
if (buf) { \
mark_reg_valid(reg); \
*buf++ = read_expr; \
} \
++len; \
} \
} while (0)
#define add_reg(reg) add_reg_from(reg, sh_eth_read(ndev, reg))
#define add_tsu_reg(reg) add_reg_from(reg, sh_eth_tsu_read(mdp, reg))
add_reg(EDSR);
add_reg(EDMR);
add_reg(EDTRR);
add_reg(EDRRR);
add_reg(EESR);
add_reg(EESIPR);
add_reg(TDLAR);
add_reg(TDFAR);
add_reg(TDFXR);
add_reg(TDFFR);
add_reg(RDLAR);
add_reg(RDFAR);
add_reg(RDFXR);
add_reg(RDFFR);
add_reg(TRSCER);
add_reg(RMFCR);
add_reg(TFTR);
add_reg(FDR);
add_reg(RMCR);
add_reg(TFUCR);
add_reg(RFOCR);
if (cd->rmiimode)
add_reg(RMIIMODE);
add_reg(FCFTR);
if (cd->rpadir)
add_reg(RPADIR);
if (!cd->no_trimd)
add_reg(TRIMD);
add_reg(ECMR);
add_reg(ECSR);
add_reg(ECSIPR);
add_reg(PIR);
if (!cd->no_psr)
add_reg(PSR);
add_reg(RDMLR);
add_reg(RFLR);
add_reg(IPGR);
if (cd->apr)
add_reg(APR);
if (cd->mpr)
add_reg(MPR);
add_reg(RFCR);
add_reg(RFCF);
if (cd->tpauser)
add_reg(TPAUSER);
add_reg(TPAUSECR);
add_reg(GECMR);
if (cd->bculr)
add_reg(BCULR);
add_reg(MAHR);
add_reg(MALR);
add_reg(TROCR);
add_reg(CDCR);
add_reg(LCCR);
add_reg(CNDCR);
add_reg(CEFCR);
add_reg(FRECR);
add_reg(TSFRCR);
add_reg(TLFRCR);
add_reg(CERCR);
add_reg(CEECR);
add_reg(MAFCR);
if (cd->rtrate)
add_reg(RTRATE);
if (cd->hw_crc)
add_reg(CSMR);
if (cd->select_mii)
add_reg(RMII_MII);
add_reg(ARSTR);
if (cd->tsu) {
add_tsu_reg(TSU_CTRST);
add_tsu_reg(TSU_FWEN0);
add_tsu_reg(TSU_FWEN1);
add_tsu_reg(TSU_FCM);
add_tsu_reg(TSU_BSYSL0);
add_tsu_reg(TSU_BSYSL1);
add_tsu_reg(TSU_PRISL0);
add_tsu_reg(TSU_PRISL1);
add_tsu_reg(TSU_FWSL0);
add_tsu_reg(TSU_FWSL1);
add_tsu_reg(TSU_FWSLC);
add_tsu_reg(TSU_QTAG0);
add_tsu_reg(TSU_QTAG1);
add_tsu_reg(TSU_QTAGM0);
add_tsu_reg(TSU_QTAGM1);
add_tsu_reg(TSU_FWSR);
add_tsu_reg(TSU_FWINMK);
add_tsu_reg(TSU_ADQT0);
add_tsu_reg(TSU_ADQT1);
add_tsu_reg(TSU_VTAG0);
add_tsu_reg(TSU_VTAG1);
add_tsu_reg(TSU_ADSBSY);
add_tsu_reg(TSU_TEN);
add_tsu_reg(TSU_POST1);
add_tsu_reg(TSU_POST2);
add_tsu_reg(TSU_POST3);
add_tsu_reg(TSU_POST4);
if (mdp->reg_offset[TSU_ADRH0] != SH_ETH_OFFSET_INVALID) {
if (buf) {
unsigned int i;
mark_reg_valid(TSU_ADRH0);
for (i = 0; i < SH_ETH_TSU_CAM_ENTRIES * 2; i++)
*buf++ = ioread32(
mdp->tsu_addr +
mdp->reg_offset[TSU_ADRH0] +
i * 4);
}
len += SH_ETH_TSU_CAM_ENTRIES * 2;
}
}
#undef mark_reg_valid
#undef add_reg_from
#undef add_reg
#undef add_tsu_reg
return len * 4;
}
static int sh_eth_get_regs_len(struct net_device *ndev)
{
return __sh_eth_get_regs(ndev, NULL);
}
static void sh_eth_get_regs(struct net_device *ndev, struct ethtool_regs *regs,
void *buf)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
regs->version = SH_ETH_REG_DUMP_VERSION;
pm_runtime_get_sync(&mdp->pdev->dev);
__sh_eth_get_regs(ndev, buf);
pm_runtime_put_sync(&mdp->pdev->dev);
}
static int sh_eth_nway_reset(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
unsigned long flags;
int ret;
if (!mdp->phydev)
return -ENODEV;
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
static void sh_eth_get_ringparam(struct net_device *ndev,
struct ethtool_ringparam *ring)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
ring->rx_max_pending = RX_RING_MAX;
ring->tx_max_pending = TX_RING_MAX;
ring->rx_pending = mdp->num_rx_ring;
ring->tx_pending = mdp->num_tx_ring;
}
static int sh_eth_set_ringparam(struct net_device *ndev,
struct ethtool_ringparam *ring)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int ret;
if (ring->tx_pending > TX_RING_MAX ||
ring->rx_pending > RX_RING_MAX ||
ring->tx_pending < TX_RING_MIN ||
ring->rx_pending < RX_RING_MIN)
return -EINVAL;
if (ring->rx_mini_pending || ring->rx_jumbo_pending)
return -EINVAL;
if (netif_running(ndev)) {
netif_device_detach(ndev);
netif_tx_disable(ndev);
mdp->irq_enabled = false;
synchronize_irq(ndev->irq);
napi_synchronize(&mdp->napi);
sh_eth_write(ndev, 0x0000, EESIPR);
sh_eth_dev_exit(ndev);
sh_eth_ring_free(ndev);
sh_eth_free_dma_buffer(mdp);
}
mdp->num_rx_ring = ring->rx_pending;
mdp->num_tx_ring = ring->tx_pending;
if (netif_running(ndev)) {
ret = sh_eth_ring_init(ndev);
if (ret < 0) {
netdev_err(ndev, "%s: sh_eth_ring_init failed.\n",
__func__);
return ret;
}
ret = sh_eth_dev_init(ndev, false);
if (ret < 0) {
netdev_err(ndev, "%s: sh_eth_dev_init failed.\n",
__func__);
return ret;
}
mdp->irq_enabled = true;
sh_eth_write(ndev, mdp->cd->eesipr_value, EESIPR);
sh_eth_write(ndev, EDRRR_R, EDRRR);
netif_device_attach(ndev);
}
return 0;
}
static int sh_eth_open(struct net_device *ndev)
{
int ret = 0;
struct sh_eth_private *mdp = netdev_priv(ndev);
pm_runtime_get_sync(&mdp->pdev->dev);
napi_enable(&mdp->napi);
ret = request_irq(ndev->irq, sh_eth_interrupt,
mdp->cd->irq_flags, ndev->name, ndev);
if (ret) {
netdev_err(ndev, "Can not assign IRQ number\n");
goto out_napi_off;
}
ret = sh_eth_ring_init(ndev);
if (ret)
goto out_free_irq;
ret = sh_eth_dev_init(ndev, true);
if (ret)
goto out_free_irq;
ret = sh_eth_phy_start(ndev);
if (ret)
goto out_free_irq;
mdp->is_opened = 1;
return ret;
out_free_irq:
free_irq(ndev->irq, ndev);
out_napi_off:
napi_disable(&mdp->napi);
pm_runtime_put_sync(&mdp->pdev->dev);
return ret;
}
static void sh_eth_tx_timeout(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct sh_eth_rxdesc *rxdesc;
int i;
netif_stop_queue(ndev);
netif_err(mdp, timer, ndev,
"transmit timed out, status %8.8x, resetting...\n",
sh_eth_read(ndev, EESR));
ndev->stats.tx_errors++;
for (i = 0; i < mdp->num_rx_ring; i++) {
rxdesc = &mdp->rx_ring[i];
rxdesc->status = 0;
rxdesc->addr = 0xBADF00D0;
dev_kfree_skb(mdp->rx_skbuff[i]);
mdp->rx_skbuff[i] = NULL;
}
for (i = 0; i < mdp->num_tx_ring; i++) {
dev_kfree_skb(mdp->tx_skbuff[i]);
mdp->tx_skbuff[i] = NULL;
}
sh_eth_dev_init(ndev, true);
}
static int sh_eth_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct sh_eth_txdesc *txdesc;
u32 entry;
unsigned long flags;
spin_lock_irqsave(&mdp->lock, flags);
if ((mdp->cur_tx - mdp->dirty_tx) >= (mdp->num_tx_ring - 4)) {
if (!sh_eth_txfree(ndev)) {
netif_warn(mdp, tx_queued, ndev, "TxFD exhausted.\n");
netif_stop_queue(ndev);
spin_unlock_irqrestore(&mdp->lock, flags);
return NETDEV_TX_BUSY;
}
}
spin_unlock_irqrestore(&mdp->lock, flags);
if (skb_put_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
entry = mdp->cur_tx % mdp->num_tx_ring;
mdp->tx_skbuff[entry] = skb;
txdesc = &mdp->tx_ring[entry];
if (!mdp->cd->hw_swap)
sh_eth_soft_swap(phys_to_virt(ALIGN(txdesc->addr, 4)),
skb->len + 2);
txdesc->addr = dma_map_single(&ndev->dev, skb->data, skb->len,
DMA_TO_DEVICE);
if (dma_mapping_error(&ndev->dev, txdesc->addr)) {
kfree_skb(skb);
return NETDEV_TX_OK;
}
txdesc->buffer_length = skb->len;
wmb();
if (entry >= mdp->num_tx_ring - 1)
txdesc->status |= cpu_to_edmac(mdp, TD_TACT | TD_TDLE);
else
txdesc->status |= cpu_to_edmac(mdp, TD_TACT);
mdp->cur_tx++;
if (!(sh_eth_read(ndev, EDTRR) & sh_eth_get_edtrr_trns(mdp)))
sh_eth_write(ndev, sh_eth_get_edtrr_trns(mdp), EDTRR);
return NETDEV_TX_OK;
}
static void
sh_eth_update_stat(struct net_device *ndev, unsigned long *stat, int reg)
{
u32 delta = sh_eth_read(ndev, reg);
if (delta) {
*stat += delta;
sh_eth_write(ndev, 0, reg);
}
}
static struct net_device_stats *sh_eth_get_stats(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
if (sh_eth_is_rz_fast_ether(mdp))
return &ndev->stats;
if (!mdp->is_opened)
return &ndev->stats;
sh_eth_update_stat(ndev, &ndev->stats.tx_dropped, TROCR);
sh_eth_update_stat(ndev, &ndev->stats.collisions, CDCR);
sh_eth_update_stat(ndev, &ndev->stats.tx_carrier_errors, LCCR);
if (sh_eth_is_gether(mdp)) {
sh_eth_update_stat(ndev, &ndev->stats.tx_carrier_errors,
CERCR);
sh_eth_update_stat(ndev, &ndev->stats.tx_carrier_errors,
CEECR);
} else {
sh_eth_update_stat(ndev, &ndev->stats.tx_carrier_errors,
CNDCR);
}
return &ndev->stats;
}
static int sh_eth_close(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
netif_stop_queue(ndev);
mdp->irq_enabled = false;
synchronize_irq(ndev->irq);
napi_disable(&mdp->napi);
sh_eth_write(ndev, 0x0000, EESIPR);
sh_eth_dev_exit(ndev);
if (mdp->phydev) {
phy_stop(mdp->phydev);
phy_disconnect(mdp->phydev);
mdp->phydev = NULL;
}
free_irq(ndev->irq, ndev);
sh_eth_ring_free(ndev);
sh_eth_free_dma_buffer(mdp);
pm_runtime_put_sync(&mdp->pdev->dev);
mdp->is_opened = 0;
return 0;
}
static int sh_eth_do_ioctl(struct net_device *ndev, struct ifreq *rq, int cmd)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
struct phy_device *phydev = mdp->phydev;
if (!netif_running(ndev))
return -EINVAL;
if (!phydev)
return -ENODEV;
return phy_mii_ioctl(phydev, rq, cmd);
}
static void *sh_eth_tsu_get_post_reg_offset(struct sh_eth_private *mdp,
int entry)
{
return sh_eth_tsu_get_offset(mdp, TSU_POST1) + (entry / 8 * 4);
}
static u32 sh_eth_tsu_get_post_mask(int entry)
{
return 0x0f << (28 - ((entry % 8) * 4));
}
static u32 sh_eth_tsu_get_post_bit(struct sh_eth_private *mdp, int entry)
{
return (0x08 >> (mdp->port << 1)) << (28 - ((entry % 8) * 4));
}
static void sh_eth_tsu_enable_cam_entry_post(struct net_device *ndev,
int entry)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
u32 tmp;
void *reg_offset;
reg_offset = sh_eth_tsu_get_post_reg_offset(mdp, entry);
tmp = ioread32(reg_offset);
iowrite32(tmp | sh_eth_tsu_get_post_bit(mdp, entry), reg_offset);
}
static bool sh_eth_tsu_disable_cam_entry_post(struct net_device *ndev,
int entry)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
u32 post_mask, ref_mask, tmp;
void *reg_offset;
reg_offset = sh_eth_tsu_get_post_reg_offset(mdp, entry);
post_mask = sh_eth_tsu_get_post_mask(entry);
ref_mask = sh_eth_tsu_get_post_bit(mdp, entry) & ~post_mask;
tmp = ioread32(reg_offset);
iowrite32(tmp & ~post_mask, reg_offset);
return tmp & ref_mask;
}
static int sh_eth_tsu_busy(struct net_device *ndev)
{
int timeout = SH_ETH_TSU_TIMEOUT_MS * 100;
struct sh_eth_private *mdp = netdev_priv(ndev);
while ((sh_eth_tsu_read(mdp, TSU_ADSBSY) & TSU_ADSBSY_0)) {
udelay(10);
timeout--;
if (timeout <= 0) {
netdev_err(ndev, "%s: timeout\n", __func__);
return -ETIMEDOUT;
}
}
return 0;
}
static int sh_eth_tsu_write_entry(struct net_device *ndev, void *reg,
const u8 *addr)
{
u32 val;
val = addr[0] << 24 | addr[1] << 16 | addr[2] << 8 | addr[3];
iowrite32(val, reg);
if (sh_eth_tsu_busy(ndev) < 0)
return -EBUSY;
val = addr[4] << 8 | addr[5];
iowrite32(val, reg + 4);
if (sh_eth_tsu_busy(ndev) < 0)
return -EBUSY;
return 0;
}
static void sh_eth_tsu_read_entry(void *reg, u8 *addr)
{
u32 val;
val = ioread32(reg);
addr[0] = (val >> 24) & 0xff;
addr[1] = (val >> 16) & 0xff;
addr[2] = (val >> 8) & 0xff;
addr[3] = val & 0xff;
val = ioread32(reg + 4);
addr[4] = (val >> 8) & 0xff;
addr[5] = val & 0xff;
}
static int sh_eth_tsu_find_entry(struct net_device *ndev, const u8 *addr)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
void *reg_offset = sh_eth_tsu_get_offset(mdp, TSU_ADRH0);
int i;
u8 c_addr[ETH_ALEN];
for (i = 0; i < SH_ETH_TSU_CAM_ENTRIES; i++, reg_offset += 8) {
sh_eth_tsu_read_entry(reg_offset, c_addr);
if (ether_addr_equal(addr, c_addr))
return i;
}
return -ENOENT;
}
static int sh_eth_tsu_find_empty(struct net_device *ndev)
{
u8 blank[ETH_ALEN];
int entry;
memset(blank, 0, sizeof(blank));
entry = sh_eth_tsu_find_entry(ndev, blank);
return (entry < 0) ? -ENOMEM : entry;
}
static int sh_eth_tsu_disable_cam_entry_table(struct net_device *ndev,
int entry)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
void *reg_offset = sh_eth_tsu_get_offset(mdp, TSU_ADRH0);
int ret;
u8 blank[ETH_ALEN];
sh_eth_tsu_write(mdp, sh_eth_tsu_read(mdp, TSU_TEN) &
~(1 << (31 - entry)), TSU_TEN);
memset(blank, 0, sizeof(blank));
ret = sh_eth_tsu_write_entry(ndev, reg_offset + entry * 8, blank);
if (ret < 0)
return ret;
return 0;
}
static int sh_eth_tsu_add_entry(struct net_device *ndev, const u8 *addr)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
void *reg_offset = sh_eth_tsu_get_offset(mdp, TSU_ADRH0);
int i, ret;
if (!mdp->cd->tsu)
return 0;
i = sh_eth_tsu_find_entry(ndev, addr);
if (i < 0) {
i = sh_eth_tsu_find_empty(ndev);
if (i < 0)
return -ENOMEM;
ret = sh_eth_tsu_write_entry(ndev, reg_offset + i * 8, addr);
if (ret < 0)
return ret;
sh_eth_tsu_write(mdp, sh_eth_tsu_read(mdp, TSU_TEN) |
(1 << (31 - i)), TSU_TEN);
}
sh_eth_tsu_enable_cam_entry_post(ndev, i);
return 0;
}
static int sh_eth_tsu_del_entry(struct net_device *ndev, const u8 *addr)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int i, ret;
if (!mdp->cd->tsu)
return 0;
i = sh_eth_tsu_find_entry(ndev, addr);
if (i) {
if (sh_eth_tsu_disable_cam_entry_post(ndev, i))
goto done;
ret = sh_eth_tsu_disable_cam_entry_table(ndev, i);
if (ret < 0)
return ret;
}
done:
return 0;
}
static int sh_eth_tsu_purge_all(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int i, ret;
if (!mdp->cd->tsu)
return 0;
for (i = 0; i < SH_ETH_TSU_CAM_ENTRIES; i++) {
if (sh_eth_tsu_disable_cam_entry_post(ndev, i))
continue;
ret = sh_eth_tsu_disable_cam_entry_table(ndev, i);
if (ret < 0)
return ret;
}
return 0;
}
static void sh_eth_tsu_purge_mcast(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
u8 addr[ETH_ALEN];
void *reg_offset = sh_eth_tsu_get_offset(mdp, TSU_ADRH0);
int i;
if (!mdp->cd->tsu)
return;
for (i = 0; i < SH_ETH_TSU_CAM_ENTRIES; i++, reg_offset += 8) {
sh_eth_tsu_read_entry(reg_offset, addr);
if (is_multicast_ether_addr(addr))
sh_eth_tsu_del_entry(ndev, addr);
}
}
static void sh_eth_set_rx_mode(struct net_device *ndev)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
u32 ecmr_bits;
int mcast_all = 0;
unsigned long flags;
spin_lock_irqsave(&mdp->lock, flags);
ecmr_bits = sh_eth_read(ndev, ECMR) & ~ECMR_PRM;
if (mdp->cd->tsu)
ecmr_bits |= ECMR_MCT;
if (!(ndev->flags & IFF_MULTICAST)) {
sh_eth_tsu_purge_mcast(ndev);
mcast_all = 1;
}
if (ndev->flags & IFF_ALLMULTI) {
sh_eth_tsu_purge_mcast(ndev);
ecmr_bits &= ~ECMR_MCT;
mcast_all = 1;
}
if (ndev->flags & IFF_PROMISC) {
sh_eth_tsu_purge_all(ndev);
ecmr_bits = (ecmr_bits & ~ECMR_MCT) | ECMR_PRM;
} else if (mdp->cd->tsu) {
struct netdev_hw_addr *ha;
netdev_for_each_mc_addr(ha, ndev) {
if (mcast_all && is_multicast_ether_addr(ha->addr))
continue;
if (sh_eth_tsu_add_entry(ndev, ha->addr) < 0) {
if (!mcast_all) {
sh_eth_tsu_purge_mcast(ndev);
ecmr_bits &= ~ECMR_MCT;
mcast_all = 1;
}
}
}
}
sh_eth_write(ndev, ecmr_bits, ECMR);
spin_unlock_irqrestore(&mdp->lock, flags);
}
static int sh_eth_get_vtag_index(struct sh_eth_private *mdp)
{
if (!mdp->port)
return TSU_VTAG0;
else
return TSU_VTAG1;
}
static int sh_eth_vlan_rx_add_vid(struct net_device *ndev,
__be16 proto, u16 vid)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int vtag_reg_index = sh_eth_get_vtag_index(mdp);
if (unlikely(!mdp->cd->tsu))
return -EPERM;
if (!vid)
return 0;
mdp->vlan_num_ids++;
if (mdp->vlan_num_ids > 1) {
sh_eth_tsu_write(mdp, 0, vtag_reg_index);
return 0;
}
sh_eth_tsu_write(mdp, TSU_VTAG_ENABLE | (vid & TSU_VTAG_VID_MASK),
vtag_reg_index);
return 0;
}
static int sh_eth_vlan_rx_kill_vid(struct net_device *ndev,
__be16 proto, u16 vid)
{
struct sh_eth_private *mdp = netdev_priv(ndev);
int vtag_reg_index = sh_eth_get_vtag_index(mdp);
if (unlikely(!mdp->cd->tsu))
return -EPERM;
if (!vid)
return 0;
mdp->vlan_num_ids--;
sh_eth_tsu_write(mdp, 0, vtag_reg_index);
return 0;
}
static void sh_eth_tsu_init(struct sh_eth_private *mdp)
{
if (sh_eth_is_rz_fast_ether(mdp)) {
sh_eth_tsu_write(mdp, 0, TSU_TEN);
return;
}
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
static int sh_mdio_release(struct sh_eth_private *mdp)
{
mdiobus_unregister(mdp->mii_bus);
free_mdio_bitbang(mdp->mii_bus);
return 0;
}
static int sh_mdio_init(struct sh_eth_private *mdp,
struct sh_eth_plat_data *pd)
{
int ret, i;
struct bb_info *bitbang;
struct platform_device *pdev = mdp->pdev;
struct device *dev = &mdp->pdev->dev;
bitbang = devm_kzalloc(dev, sizeof(struct bb_info), GFP_KERNEL);
if (!bitbang)
return -ENOMEM;
bitbang->addr = mdp->addr + mdp->reg_offset[PIR];
bitbang->set_gate = pd->set_mdio_gate;
bitbang->mdi_msk = PIR_MDI;
bitbang->mdo_msk = PIR_MDO;
bitbang->mmd_msk = PIR_MMD;
bitbang->mdc_msk = PIR_MDC;
bitbang->ctrl.ops = &bb_ops;
mdp->mii_bus = alloc_mdio_bitbang(&bitbang->ctrl);
if (!mdp->mii_bus)
return -ENOMEM;
mdp->mii_bus->name = "sh_mii";
mdp->mii_bus->parent = dev;
snprintf(mdp->mii_bus->id, MII_BUS_ID_SIZE, "%s-%x",
pdev->name, pdev->id);
mdp->mii_bus->irq = devm_kmalloc_array(dev, PHY_MAX_ADDR, sizeof(int),
GFP_KERNEL);
if (!mdp->mii_bus->irq) {
ret = -ENOMEM;
goto out_free_bus;
}
if (dev->of_node) {
ret = of_mdiobus_register(mdp->mii_bus, dev->of_node);
} else {
for (i = 0; i < PHY_MAX_ADDR; i++)
mdp->mii_bus->irq[i] = PHY_POLL;
if (pd->phy_irq > 0)
mdp->mii_bus->irq[pd->phy] = pd->phy_irq;
ret = mdiobus_register(mdp->mii_bus);
}
if (ret)
goto out_free_bus;
return 0;
out_free_bus:
free_mdio_bitbang(mdp->mii_bus);
return ret;
}
static const u16 *sh_eth_get_register_offset(int register_type)
{
const u16 *reg_offset = NULL;
switch (register_type) {
case SH_ETH_REG_GIGABIT:
reg_offset = sh_eth_offset_gigabit;
break;
case SH_ETH_REG_FAST_RZ:
reg_offset = sh_eth_offset_fast_rz;
break;
case SH_ETH_REG_FAST_RCAR:
reg_offset = sh_eth_offset_fast_rcar;
break;
case SH_ETH_REG_FAST_SH4:
reg_offset = sh_eth_offset_fast_sh4;
break;
case SH_ETH_REG_FAST_SH3_SH2:
reg_offset = sh_eth_offset_fast_sh3_sh2;
break;
default:
break;
}
return reg_offset;
}
static struct sh_eth_plat_data *sh_eth_parse_dt(struct device *dev)
{
struct device_node *np = dev->of_node;
struct sh_eth_plat_data *pdata;
const char *mac_addr;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
pdata->phy_interface = of_get_phy_mode(np);
mac_addr = of_get_mac_address(np);
if (mac_addr)
memcpy(pdata->mac_addr, mac_addr, ETH_ALEN);
pdata->no_ether_link =
of_property_read_bool(np, "renesas,no-ether-link");
pdata->ether_link_active_low =
of_property_read_bool(np, "renesas,ether-link-active-low");
return pdata;
}
static inline struct sh_eth_plat_data *sh_eth_parse_dt(struct device *dev)
{
return NULL;
}
static int sh_eth_drv_probe(struct platform_device *pdev)
{
int ret, devno = 0;
struct resource *res;
struct net_device *ndev = NULL;
struct sh_eth_private *mdp = NULL;
struct sh_eth_plat_data *pd = dev_get_platdata(&pdev->dev);
const struct platform_device_id *id = platform_get_device_id(pdev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ndev = alloc_etherdev(sizeof(struct sh_eth_private));
if (!ndev)
return -ENOMEM;
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
devno = pdev->id;
if (devno < 0)
devno = 0;
ndev->dma = -1;
ret = platform_get_irq(pdev, 0);
if (ret < 0)
goto out_release;
ndev->irq = ret;
SET_NETDEV_DEV(ndev, &pdev->dev);
mdp = netdev_priv(ndev);
mdp->num_tx_ring = TX_RING_SIZE;
mdp->num_rx_ring = RX_RING_SIZE;
mdp->addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mdp->addr)) {
ret = PTR_ERR(mdp->addr);
goto out_release;
}
ndev->base_addr = res->start;
spin_lock_init(&mdp->lock);
mdp->pdev = pdev;
if (pdev->dev.of_node)
pd = sh_eth_parse_dt(&pdev->dev);
if (!pd) {
dev_err(&pdev->dev, "no platform data\n");
ret = -EINVAL;
goto out_release;
}
mdp->phy_id = pd->phy;
mdp->phy_interface = pd->phy_interface;
mdp->edmac_endian = pd->edmac_endian;
mdp->no_ether_link = pd->no_ether_link;
mdp->ether_link_active_low = pd->ether_link_active_low;
if (id) {
mdp->cd = (struct sh_eth_cpu_data *)id->driver_data;
} else {
const struct of_device_id *match;
match = of_match_device(of_match_ptr(sh_eth_match_table),
&pdev->dev);
mdp->cd = (struct sh_eth_cpu_data *)match->data;
}
mdp->reg_offset = sh_eth_get_register_offset(mdp->cd->register_type);
if (!mdp->reg_offset) {
dev_err(&pdev->dev, "Unknown register type (%d)\n",
mdp->cd->register_type);
ret = -EINVAL;
goto out_release;
}
sh_eth_set_default_cpu_data(mdp->cd);
if (mdp->cd->tsu)
ndev->netdev_ops = &sh_eth_netdev_ops_tsu;
else
ndev->netdev_ops = &sh_eth_netdev_ops;
ndev->ethtool_ops = &sh_eth_ethtool_ops;
ndev->watchdog_timeo = TX_TIMEOUT;
mdp->msg_enable = SH_ETH_DEF_MSG_ENABLE;
read_mac_address(ndev, pd->mac_addr);
if (!is_valid_ether_addr(ndev->dev_addr)) {
dev_warn(&pdev->dev,
"no valid MAC address supplied, using a random one.\n");
eth_hw_addr_random(ndev);
}
if (mdp->cd->tsu) {
struct resource *rtsu;
rtsu = platform_get_resource(pdev, IORESOURCE_MEM, 1);
mdp->tsu_addr = devm_ioremap_resource(&pdev->dev, rtsu);
if (IS_ERR(mdp->tsu_addr)) {
ret = PTR_ERR(mdp->tsu_addr);
goto out_release;
}
mdp->port = devno % 2;
ndev->features = NETIF_F_HW_VLAN_CTAG_FILTER;
}
if (!devno || pd->needs_init) {
if (mdp->cd->chip_reset)
mdp->cd->chip_reset(ndev);
if (mdp->cd->tsu) {
sh_eth_tsu_init(mdp);
}
}
if (mdp->cd->rmiimode)
sh_eth_write(ndev, 0x1, RMIIMODE);
ret = sh_mdio_init(mdp, pd);
if (ret) {
dev_err(&ndev->dev, "failed to initialise MDIO\n");
goto out_release;
}
netif_napi_add(ndev, &mdp->napi, sh_eth_poll, 64);
ret = register_netdev(ndev);
if (ret)
goto out_napi_del;
netdev_info(ndev, "Base address at 0x%x, %pM, IRQ %d.\n",
(u32)ndev->base_addr, ndev->dev_addr, ndev->irq);
pm_runtime_put(&pdev->dev);
platform_set_drvdata(pdev, ndev);
return ret;
out_napi_del:
netif_napi_del(&mdp->napi);
sh_mdio_release(mdp);
out_release:
if (ndev)
free_netdev(ndev);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return ret;
}
static int sh_eth_drv_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct sh_eth_private *mdp = netdev_priv(ndev);
unregister_netdev(ndev);
netif_napi_del(&mdp->napi);
sh_mdio_release(mdp);
pm_runtime_disable(&pdev->dev);
free_netdev(ndev);
return 0;
}
static int sh_eth_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
int ret = 0;
if (netif_running(ndev)) {
netif_device_detach(ndev);
ret = sh_eth_close(ndev);
}
return ret;
}
static int sh_eth_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
int ret = 0;
if (netif_running(ndev)) {
ret = sh_eth_open(ndev);
if (ret < 0)
return ret;
netif_device_attach(ndev);
}
return ret;
}
static int sh_eth_runtime_nop(struct device *dev)
{
return 0;
}
