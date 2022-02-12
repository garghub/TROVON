static inline bool ixgbe_rx_is_fcoe(union ixgbe_adv_rx_desc *rx_desc)
{
u16 p;
p = le16_to_cpu(rx_desc->wb.lower.lo_dword.hs_rss.pkt_info);
if (p & IXGBE_RXDADV_PKTTYPE_ETQF) {
p &= IXGBE_RXDADV_PKTTYPE_ETQF_MASK;
p >>= IXGBE_RXDADV_PKTTYPE_ETQF_SHIFT;
return p == IXGBE_ETQF_FILTER_FCOE;
}
return false;
}
static inline void ixgbe_fcoe_clear_ddp(struct ixgbe_fcoe_ddp *ddp)
{
ddp->len = 0;
ddp->err = 1;
ddp->udl = NULL;
ddp->udp = 0UL;
ddp->sgl = NULL;
ddp->sgc = 0;
}
int ixgbe_fcoe_ddp_put(struct net_device *netdev, u16 xid)
{
int len = 0;
struct ixgbe_fcoe *fcoe;
struct ixgbe_adapter *adapter;
struct ixgbe_fcoe_ddp *ddp;
u32 fcbuff;
if (!netdev)
goto out_ddp_put;
if (xid >= IXGBE_FCOE_DDP_MAX)
goto out_ddp_put;
adapter = netdev_priv(netdev);
fcoe = &adapter->fcoe;
ddp = &fcoe->ddp[xid];
if (!ddp->udl)
goto out_ddp_put;
len = ddp->len;
if (ddp->err) {
spin_lock_bh(&fcoe->lock);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_FCFLT, 0);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_FCFLTRW,
(xid | IXGBE_FCFLTRW_WE));
IXGBE_WRITE_REG(&adapter->hw, IXGBE_FCBUFF, 0);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_FCDMARW,
(xid | IXGBE_FCDMARW_WE));
IXGBE_WRITE_REG(&adapter->hw, IXGBE_FCDMARW,
(xid | IXGBE_FCDMARW_RE));
fcbuff = IXGBE_READ_REG(&adapter->hw, IXGBE_FCBUFF);
spin_unlock_bh(&fcoe->lock);
if (fcbuff & IXGBE_FCBUFF_VALID)
udelay(100);
}
if (ddp->sgl)
pci_unmap_sg(adapter->pdev, ddp->sgl, ddp->sgc,
DMA_FROM_DEVICE);
pci_pool_free(fcoe->pool, ddp->udl, ddp->udp);
ixgbe_fcoe_clear_ddp(ddp);
out_ddp_put:
return len;
}
static int ixgbe_fcoe_ddp_setup(struct net_device *netdev, u16 xid,
struct scatterlist *sgl, unsigned int sgc,
int target_mode)
{
struct ixgbe_adapter *adapter;
struct ixgbe_hw *hw;
struct ixgbe_fcoe *fcoe;
struct ixgbe_fcoe_ddp *ddp;
struct scatterlist *sg;
unsigned int i, j, dmacount;
unsigned int len;
static const unsigned int bufflen = IXGBE_FCBUFF_MIN;
unsigned int firstoff = 0;
unsigned int lastsize;
unsigned int thisoff = 0;
unsigned int thislen = 0;
u32 fcbuff, fcdmarw, fcfltrw, fcrxctl;
dma_addr_t addr = 0;
if (!netdev || !sgl)
return 0;
adapter = netdev_priv(netdev);
if (xid >= IXGBE_FCOE_DDP_MAX) {
e_warn(drv, "xid=0x%x out-of-range\n", xid);
return 0;
}
if (test_bit(__IXGBE_DOWN, &adapter->state) ||
test_bit(__IXGBE_RESETTING, &adapter->state))
return 0;
fcoe = &adapter->fcoe;
if (!fcoe->pool) {
e_warn(drv, "xid=0x%x no ddp pool for fcoe\n", xid);
return 0;
}
ddp = &fcoe->ddp[xid];
if (ddp->sgl) {
e_err(drv, "xid 0x%x w/ non-null sgl=%p nents=%d\n",
xid, ddp->sgl, ddp->sgc);
return 0;
}
ixgbe_fcoe_clear_ddp(ddp);
dmacount = pci_map_sg(adapter->pdev, sgl, sgc, DMA_FROM_DEVICE);
if (dmacount == 0) {
e_err(drv, "xid 0x%x DMA map error\n", xid);
return 0;
}
ddp->udl = pci_pool_alloc(fcoe->pool, GFP_ATOMIC, &ddp->udp);
if (!ddp->udl) {
e_err(drv, "failed allocated ddp context\n");
goto out_noddp_unmap;
}
ddp->sgl = sgl;
ddp->sgc = sgc;
j = 0;
for_each_sg(sgl, sg, dmacount, i) {
addr = sg_dma_address(sg);
len = sg_dma_len(sg);
while (len) {
if (j >= IXGBE_BUFFCNT_MAX) {
e_err(drv, "xid=%x:%d,%d,%d:addr=%llx "
"not enough descriptors\n",
xid, i, j, dmacount, (u64)addr);
goto out_noddp_free;
}
thisoff = addr & ((dma_addr_t)bufflen - 1);
thislen = min((bufflen - thisoff), len);
if ((j != 0) && (thisoff))
goto out_noddp_free;
if (((i != (dmacount - 1)) || (thislen != len))
&& ((thislen + thisoff) != bufflen))
goto out_noddp_free;
ddp->udl[j] = (u64)(addr - thisoff);
if (j == 0)
firstoff = thisoff;
len -= thislen;
addr += thislen;
j++;
}
}
lastsize = thisoff + thislen;
if (lastsize == bufflen) {
if (j >= IXGBE_BUFFCNT_MAX) {
e_err(drv, "xid=%x:%d,%d,%d:addr=%llx "
"not enough user buffers. We need an extra "
"buffer because lastsize is bufflen.\n",
xid, i, j, dmacount, (u64)addr);
goto out_noddp_free;
}
ddp->udl[j] = (u64)(fcoe->extra_ddp_buffer_dma);
j++;
lastsize = 1;
}
fcbuff = (IXGBE_FCBUFF_4KB << IXGBE_FCBUFF_BUFFSIZE_SHIFT);
fcbuff |= ((j & 0xff) << IXGBE_FCBUFF_BUFFCNT_SHIFT);
fcbuff |= (firstoff << IXGBE_FCBUFF_OFFSET_SHIFT);
if (target_mode)
fcbuff |= (IXGBE_FCBUFF_WRCONTX);
fcbuff |= (IXGBE_FCBUFF_VALID);
fcdmarw = xid;
fcdmarw |= IXGBE_FCDMARW_WE;
fcdmarw |= (lastsize << IXGBE_FCDMARW_LASTSIZE_SHIFT);
fcfltrw = xid;
fcfltrw |= IXGBE_FCFLTRW_WE;
hw = &adapter->hw;
spin_lock_bh(&fcoe->lock);
if (target_mode && !test_bit(__IXGBE_FCOE_TARGET, &fcoe->mode)) {
set_bit(__IXGBE_FCOE_TARGET, &fcoe->mode);
fcrxctl = IXGBE_READ_REG(hw, IXGBE_FCRXCTRL);
fcrxctl |= IXGBE_FCRXCTRL_LASTSEQH;
IXGBE_WRITE_REG(hw, IXGBE_FCRXCTRL, fcrxctl);
}
IXGBE_WRITE_REG(hw, IXGBE_FCPTRL, ddp->udp & DMA_BIT_MASK(32));
IXGBE_WRITE_REG(hw, IXGBE_FCPTRH, (u64)ddp->udp >> 32);
IXGBE_WRITE_REG(hw, IXGBE_FCBUFF, fcbuff);
IXGBE_WRITE_REG(hw, IXGBE_FCDMARW, fcdmarw);
IXGBE_WRITE_REG(hw, IXGBE_FCPARAM, 0);
IXGBE_WRITE_REG(hw, IXGBE_FCFLT, IXGBE_FCFLT_VALID);
IXGBE_WRITE_REG(hw, IXGBE_FCFLTRW, fcfltrw);
spin_unlock_bh(&fcoe->lock);
return 1;
out_noddp_free:
pci_pool_free(fcoe->pool, ddp->udl, ddp->udp);
ixgbe_fcoe_clear_ddp(ddp);
out_noddp_unmap:
pci_unmap_sg(adapter->pdev, sgl, sgc, DMA_FROM_DEVICE);
return 0;
}
int ixgbe_fcoe_ddp_get(struct net_device *netdev, u16 xid,
struct scatterlist *sgl, unsigned int sgc)
{
return ixgbe_fcoe_ddp_setup(netdev, xid, sgl, sgc, 0);
}
int ixgbe_fcoe_ddp_target(struct net_device *netdev, u16 xid,
struct scatterlist *sgl, unsigned int sgc)
{
return ixgbe_fcoe_ddp_setup(netdev, xid, sgl, sgc, 1);
}
int ixgbe_fcoe_ddp(struct ixgbe_adapter *adapter,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
u16 xid;
u32 fctl;
u32 sterr, fceofe, fcerr, fcstat;
int rc = -EINVAL;
struct ixgbe_fcoe *fcoe;
struct ixgbe_fcoe_ddp *ddp;
struct fc_frame_header *fh;
struct fcoe_crc_eof *crc;
if (!ixgbe_rx_is_fcoe(rx_desc))
goto ddp_out;
sterr = le32_to_cpu(rx_desc->wb.upper.status_error);
fcerr = (sterr & IXGBE_RXDADV_ERR_FCERR);
fceofe = (sterr & IXGBE_RXDADV_ERR_FCEOFE);
if (fcerr == IXGBE_FCERR_BADCRC)
skb_checksum_none_assert(skb);
else
skb->ip_summed = CHECKSUM_UNNECESSARY;
if (eth_hdr(skb)->h_proto == htons(ETH_P_8021Q))
fh = (struct fc_frame_header *)(skb->data +
sizeof(struct vlan_hdr) + sizeof(struct fcoe_hdr));
else
fh = (struct fc_frame_header *)(skb->data +
sizeof(struct fcoe_hdr));
fctl = ntoh24(fh->fh_f_ctl);
if (fctl & FC_FC_EX_CTX)
xid = be16_to_cpu(fh->fh_ox_id);
else
xid = be16_to_cpu(fh->fh_rx_id);
if (xid >= IXGBE_FCOE_DDP_MAX)
goto ddp_out;
fcoe = &adapter->fcoe;
ddp = &fcoe->ddp[xid];
if (!ddp->udl)
goto ddp_out;
if (fcerr | fceofe)
goto ddp_out;
fcstat = (sterr & IXGBE_RXDADV_STAT_FCSTAT);
if (fcstat) {
ddp->len = le32_to_cpu(rx_desc->wb.lower.hi_dword.rss);
if (fcstat == IXGBE_RXDADV_STAT_FCSTAT_FCPRSP) {
pci_unmap_sg(adapter->pdev, ddp->sgl,
ddp->sgc, DMA_FROM_DEVICE);
ddp->err = (fcerr | fceofe);
ddp->sgl = NULL;
ddp->sgc = 0;
}
if (fcstat == IXGBE_RXDADV_STAT_FCSTAT_DDP)
rc = 0;
else if (ddp->len)
rc = ddp->len;
}
if ((fh->fh_r_ctl == FC_RCTL_DD_SOL_DATA) &&
(fctl & FC_FC_END_SEQ)) {
crc = (struct fcoe_crc_eof *)skb_put(skb, sizeof(*crc));
crc->fcoe_eof = FC_EOF_T;
}
ddp_out:
return rc;
}
int ixgbe_fso(struct ixgbe_adapter *adapter,
struct ixgbe_ring *tx_ring, struct sk_buff *skb,
u32 tx_flags, u8 *hdr_len)
{
u8 sof, eof;
u32 vlan_macip_lens;
u32 fcoe_sof_eof;
u32 type_tucmd;
u32 mss_l4len_idx;
int mss = 0;
unsigned int i;
struct ixgbe_tx_buffer *tx_buffer_info;
struct ixgbe_adv_tx_context_desc *context_desc;
struct fc_frame_header *fh;
if (skb_is_gso(skb) && (skb_shinfo(skb)->gso_type != SKB_GSO_FCOE)) {
e_err(drv, "Wrong gso type %d:expecting SKB_GSO_FCOE\n",
skb_shinfo(skb)->gso_type);
return -EINVAL;
}
skb_set_network_header(skb, skb->mac_len);
skb_set_transport_header(skb, skb->mac_len +
sizeof(struct fcoe_hdr));
fcoe_sof_eof = 0;
sof = ((struct fcoe_hdr *)skb_network_header(skb))->fcoe_sof;
switch (sof) {
case FC_SOF_I2:
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_ORIS;
break;
case FC_SOF_I3:
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_SOF;
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_ORIS;
break;
case FC_SOF_N2:
break;
case FC_SOF_N3:
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_SOF;
break;
default:
e_warn(drv, "unknown sof = 0x%x\n", sof);
return -EINVAL;
}
skb_copy_bits(skb, skb->len - 4, &eof, 1);
switch (eof) {
case FC_EOF_N:
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_EOF_N;
break;
case FC_EOF_T:
if (skb_is_gso(skb)) {
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_EOF_N;
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_ORIE;
} else {
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_EOF_T;
}
break;
case FC_EOF_NI:
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_EOF_NI;
break;
case FC_EOF_A:
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_EOF_A;
break;
default:
e_warn(drv, "unknown eof = 0x%x\n", eof);
return -EINVAL;
}
fh = (struct fc_frame_header *)skb_transport_header(skb);
if (fh->fh_f_ctl[2] & FC_FC_REL_OFF)
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_PARINC;
*hdr_len = sizeof(struct fcoe_crc_eof);
if (skb_is_gso(skb))
*hdr_len += (skb_transport_offset(skb) +
sizeof(struct fc_frame_header));
vlan_macip_lens = (skb_transport_offset(skb) +
sizeof(struct fc_frame_header));
vlan_macip_lens |= ((skb_transport_offset(skb) - 4)
<< IXGBE_ADVTXD_MACLEN_SHIFT);
vlan_macip_lens |= (tx_flags & IXGBE_TX_FLAGS_VLAN_MASK);
type_tucmd = IXGBE_TXD_CMD_DEXT | IXGBE_ADVTXD_DTYP_CTXT |
IXGBE_ADVTXT_TUCMD_FCOE;
if (skb_is_gso(skb))
mss = skb_shinfo(skb)->gso_size;
mss_l4len_idx = (mss << IXGBE_ADVTXD_MSS_SHIFT) |
(1 << IXGBE_ADVTXD_IDX_SHIFT);
i = tx_ring->next_to_use;
context_desc = IXGBE_TX_CTXTDESC_ADV(tx_ring, i);
context_desc->vlan_macip_lens = cpu_to_le32(vlan_macip_lens);
context_desc->seqnum_seed = cpu_to_le32(fcoe_sof_eof);
context_desc->type_tucmd_mlhl = cpu_to_le32(type_tucmd);
context_desc->mss_l4len_idx = cpu_to_le32(mss_l4len_idx);
tx_buffer_info = &tx_ring->tx_buffer_info[i];
tx_buffer_info->time_stamp = jiffies;
tx_buffer_info->next_to_watch = i;
i++;
if (i == tx_ring->count)
i = 0;
tx_ring->next_to_use = i;
return skb_is_gso(skb);
}
void ixgbe_configure_fcoe(struct ixgbe_adapter *adapter)
{
int i, fcoe_q, fcoe_i;
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_fcoe *fcoe = &adapter->fcoe;
struct ixgbe_ring_feature *f = &adapter->ring_feature[RING_F_FCOE];
#ifdef CONFIG_IXGBE_DCB
u8 tc;
u32 up2tc;
#endif
if (!fcoe->pool) {
fcoe->pool = pci_pool_create("ixgbe_fcoe_ddp",
adapter->pdev, IXGBE_FCPTR_MAX,
IXGBE_FCPTR_ALIGN, PAGE_SIZE);
if (!fcoe->pool)
e_err(drv, "failed to allocated FCoE DDP pool\n");
spin_lock_init(&fcoe->lock);
fcoe->extra_ddp_buffer = kmalloc(IXGBE_FCBUFF_MIN, GFP_ATOMIC);
if (fcoe->extra_ddp_buffer == NULL) {
e_err(drv, "failed to allocated extra DDP buffer\n");
goto out_extra_ddp_buffer_alloc;
}
fcoe->extra_ddp_buffer_dma =
dma_map_single(&adapter->pdev->dev,
fcoe->extra_ddp_buffer,
IXGBE_FCBUFF_MIN,
DMA_FROM_DEVICE);
if (dma_mapping_error(&adapter->pdev->dev,
fcoe->extra_ddp_buffer_dma)) {
e_err(drv, "failed to map extra DDP buffer\n");
goto out_extra_ddp_buffer_dma;
}
}
IXGBE_WRITE_REG(hw, IXGBE_ETQF(IXGBE_ETQF_FILTER_FCOE),
(ETH_P_FCOE | IXGBE_ETQF_FCOE | IXGBE_ETQF_FILTER_EN));
IXGBE_WRITE_REG(hw, IXGBE_ETQF(IXGBE_ETQF_FILTER_FIP),
(ETH_P_FIP | IXGBE_ETQF_FILTER_EN));
if (adapter->ring_feature[RING_F_FCOE].indices) {
for (i = 0; i < IXGBE_FCRETA_SIZE; i++) {
fcoe_i = f->mask + i % f->indices;
fcoe_i &= IXGBE_FCRETA_ENTRY_MASK;
fcoe_q = adapter->rx_ring[fcoe_i]->reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_FCRETA(i), fcoe_q);
}
IXGBE_WRITE_REG(hw, IXGBE_FCRECTL, IXGBE_FCRECTL_ENA);
IXGBE_WRITE_REG(hw, IXGBE_ETQS(IXGBE_ETQF_FILTER_FCOE), 0);
} else {
fcoe_i = f->mask;
fcoe_q = adapter->rx_ring[fcoe_i]->reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_FCRECTL, 0);
IXGBE_WRITE_REG(hw, IXGBE_ETQS(IXGBE_ETQF_FILTER_FCOE),
IXGBE_ETQS_QUEUE_EN |
(fcoe_q << IXGBE_ETQS_RX_QUEUE_SHIFT));
}
fcoe_i = f->mask;
fcoe_q = adapter->rx_ring[fcoe_i]->reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_ETQS(IXGBE_ETQF_FILTER_FIP),
IXGBE_ETQS_QUEUE_EN |
(fcoe_q << IXGBE_ETQS_RX_QUEUE_SHIFT));
IXGBE_WRITE_REG(hw, IXGBE_FCRXCTRL,
IXGBE_FCRXCTRL_FCOELLI |
IXGBE_FCRXCTRL_FCCRCBO |
(FC_FCOE_VER << IXGBE_FCRXCTRL_FCOEVER_SHIFT));
#ifdef CONFIG_IXGBE_DCB
up2tc = IXGBE_READ_REG(&adapter->hw, IXGBE_RTTUP2TC);
for (i = 0; i < MAX_USER_PRIORITY; i++) {
tc = (u8)(up2tc >> (i * IXGBE_RTTUP2TC_UP_SHIFT));
tc &= (MAX_TRAFFIC_CLASS - 1);
if (fcoe->tc == tc) {
fcoe->up = i;
break;
}
}
#endif
return;
out_extra_ddp_buffer_dma:
kfree(fcoe->extra_ddp_buffer);
out_extra_ddp_buffer_alloc:
pci_pool_destroy(fcoe->pool);
fcoe->pool = NULL;
}
void ixgbe_cleanup_fcoe(struct ixgbe_adapter *adapter)
{
int i;
struct ixgbe_fcoe *fcoe = &adapter->fcoe;
if (fcoe->pool) {
for (i = 0; i < IXGBE_FCOE_DDP_MAX; i++)
ixgbe_fcoe_ddp_put(adapter->netdev, i);
dma_unmap_single(&adapter->pdev->dev,
fcoe->extra_ddp_buffer_dma,
IXGBE_FCBUFF_MIN,
DMA_FROM_DEVICE);
kfree(fcoe->extra_ddp_buffer);
pci_pool_destroy(fcoe->pool);
fcoe->pool = NULL;
}
}
int ixgbe_fcoe_enable(struct net_device *netdev)
{
int rc = -EINVAL;
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_fcoe *fcoe = &adapter->fcoe;
if (!(adapter->flags & IXGBE_FLAG_FCOE_CAPABLE))
goto out_enable;
atomic_inc(&fcoe->refcnt);
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED)
goto out_enable;
e_info(drv, "Enabling FCoE offload features.\n");
if (netif_running(netdev))
netdev->netdev_ops->ndo_stop(netdev);
ixgbe_clear_interrupt_scheme(adapter);
adapter->flags |= IXGBE_FLAG_FCOE_ENABLED;
adapter->ring_feature[RING_F_FCOE].indices = IXGBE_FCRETA_SIZE;
netdev->features |= NETIF_F_FCOE_CRC;
netdev->features |= NETIF_F_FSO;
netdev->features |= NETIF_F_FCOE_MTU;
netdev->fcoe_ddp_xid = IXGBE_FCOE_DDP_MAX - 1;
ixgbe_init_interrupt_scheme(adapter);
netdev_features_change(netdev);
if (netif_running(netdev))
netdev->netdev_ops->ndo_open(netdev);
rc = 0;
out_enable:
return rc;
}
int ixgbe_fcoe_disable(struct net_device *netdev)
{
int rc = -EINVAL;
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_fcoe *fcoe = &adapter->fcoe;
if (!(adapter->flags & IXGBE_FLAG_FCOE_CAPABLE))
goto out_disable;
if (!(adapter->flags & IXGBE_FLAG_FCOE_ENABLED))
goto out_disable;
if (!atomic_dec_and_test(&fcoe->refcnt))
goto out_disable;
e_info(drv, "Disabling FCoE offload features.\n");
netdev->features &= ~NETIF_F_FCOE_CRC;
netdev->features &= ~NETIF_F_FSO;
netdev->features &= ~NETIF_F_FCOE_MTU;
netdev->fcoe_ddp_xid = 0;
netdev_features_change(netdev);
if (netif_running(netdev))
netdev->netdev_ops->ndo_stop(netdev);
ixgbe_clear_interrupt_scheme(adapter);
adapter->flags &= ~IXGBE_FLAG_FCOE_ENABLED;
adapter->ring_feature[RING_F_FCOE].indices = 0;
ixgbe_cleanup_fcoe(adapter);
ixgbe_init_interrupt_scheme(adapter);
if (netif_running(netdev))
netdev->netdev_ops->ndo_open(netdev);
rc = 0;
out_disable:
return rc;
}
u8 ixgbe_fcoe_setapp(struct ixgbe_adapter *adapter, u8 up)
{
int i;
u32 up2tc;
if (up) {
up2tc = IXGBE_READ_REG(&adapter->hw, IXGBE_RTTUP2TC);
for (i = 0; i < MAX_USER_PRIORITY; i++) {
if (up & (1 << i)) {
up2tc >>= (i * IXGBE_RTTUP2TC_UP_SHIFT);
up2tc &= (MAX_TRAFFIC_CLASS - 1);
adapter->fcoe.tc = (u8)up2tc;
adapter->fcoe.up = i;
return 0;
}
}
}
return 1;
}
int ixgbe_fcoe_get_wwn(struct net_device *netdev, u64 *wwn, int type)
{
int rc = -EINVAL;
u16 prefix = 0xffff;
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_mac_info *mac = &adapter->hw.mac;
switch (type) {
case NETDEV_FCOE_WWNN:
prefix = mac->wwnn_prefix;
break;
case NETDEV_FCOE_WWPN:
prefix = mac->wwpn_prefix;
break;
default:
break;
}
if ((prefix != 0xffff) &&
is_valid_ether_addr(mac->san_addr)) {
*wwn = ((u64) prefix << 48) |
((u64) mac->san_addr[0] << 40) |
((u64) mac->san_addr[1] << 32) |
((u64) mac->san_addr[2] << 24) |
((u64) mac->san_addr[3] << 16) |
((u64) mac->san_addr[4] << 8) |
((u64) mac->san_addr[5]);
rc = 0;
}
return rc;
}
