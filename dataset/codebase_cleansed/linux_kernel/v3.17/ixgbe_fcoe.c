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
int len;
struct ixgbe_fcoe *fcoe;
struct ixgbe_adapter *adapter;
struct ixgbe_fcoe_ddp *ddp;
u32 fcbuff;
if (!netdev)
return 0;
if (xid >= IXGBE_FCOE_DDP_MAX)
return 0;
adapter = netdev_priv(netdev);
fcoe = &adapter->fcoe;
ddp = &fcoe->ddp[xid];
if (!ddp->udl)
return 0;
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
dma_unmap_sg(&adapter->pdev->dev, ddp->sgl, ddp->sgc,
DMA_FROM_DEVICE);
if (ddp->pool) {
dma_pool_free(ddp->pool, ddp->udl, ddp->udp);
ddp->pool = NULL;
}
ixgbe_fcoe_clear_ddp(ddp);
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
struct ixgbe_fcoe_ddp_pool *ddp_pool;
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
ddp = &fcoe->ddp[xid];
if (ddp->sgl) {
e_err(drv, "xid 0x%x w/ non-null sgl=%p nents=%d\n",
xid, ddp->sgl, ddp->sgc);
return 0;
}
ixgbe_fcoe_clear_ddp(ddp);
if (!fcoe->ddp_pool) {
e_warn(drv, "No ddp_pool resources allocated\n");
return 0;
}
ddp_pool = per_cpu_ptr(fcoe->ddp_pool, get_cpu());
if (!ddp_pool->pool) {
e_warn(drv, "xid=0x%x no ddp pool for fcoe\n", xid);
goto out_noddp;
}
dmacount = dma_map_sg(&adapter->pdev->dev, sgl, sgc, DMA_FROM_DEVICE);
if (dmacount == 0) {
e_err(drv, "xid 0x%x DMA map error\n", xid);
goto out_noddp;
}
ddp->udl = dma_pool_alloc(ddp_pool->pool, GFP_ATOMIC, &ddp->udp);
if (!ddp->udl) {
e_err(drv, "failed allocated ddp context\n");
goto out_noddp_unmap;
}
ddp->pool = ddp_pool->pool;
ddp->sgl = sgl;
ddp->sgc = sgc;
j = 0;
for_each_sg(sgl, sg, dmacount, i) {
addr = sg_dma_address(sg);
len = sg_dma_len(sg);
while (len) {
if (j >= IXGBE_BUFFCNT_MAX) {
ddp_pool->noddp++;
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
ddp_pool->noddp_ext_buff++;
goto out_noddp_free;
}
ddp->udl[j] = (u64)(fcoe->extra_ddp_buffer_dma);
j++;
lastsize = 1;
}
put_cpu();
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
dma_pool_free(ddp->pool, ddp->udl, ddp->udp);
ixgbe_fcoe_clear_ddp(ddp);
out_noddp_unmap:
dma_unmap_sg(&adapter->pdev->dev, sgl, sgc, DMA_FROM_DEVICE);
out_noddp:
put_cpu();
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
int rc = -EINVAL;
struct ixgbe_fcoe *fcoe;
struct ixgbe_fcoe_ddp *ddp;
struct fc_frame_header *fh;
struct fcoe_crc_eof *crc;
__le32 fcerr = ixgbe_test_staterr(rx_desc, IXGBE_RXDADV_ERR_FCERR);
__le32 ddp_err;
u32 fctl;
u16 xid;
if (fcerr == cpu_to_le32(IXGBE_FCERR_BADCRC))
skb->ip_summed = CHECKSUM_NONE;
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
return -EINVAL;
fcoe = &adapter->fcoe;
ddp = &fcoe->ddp[xid];
if (!ddp->udl)
return -EINVAL;
ddp_err = ixgbe_test_staterr(rx_desc, IXGBE_RXDADV_ERR_FCEOFE |
IXGBE_RXDADV_ERR_FCERR);
if (ddp_err)
return -EINVAL;
switch (ixgbe_test_staterr(rx_desc, IXGBE_RXDADV_STAT_FCSTAT)) {
case cpu_to_le32(IXGBE_RXDADV_STAT_FCSTAT_DDP):
ddp->len = le32_to_cpu(rx_desc->wb.lower.hi_dword.rss);
rc = 0;
break;
case cpu_to_le32(IXGBE_RXDADV_STAT_FCSTAT_FCPRSP):
dma_unmap_sg(&adapter->pdev->dev, ddp->sgl,
ddp->sgc, DMA_FROM_DEVICE);
ddp->err = ddp_err;
ddp->sgl = NULL;
ddp->sgc = 0;
case cpu_to_le32(IXGBE_RXDADV_STAT_FCSTAT_NODDP):
ddp->len = le32_to_cpu(rx_desc->wb.lower.hi_dword.rss);
if (ddp->len)
rc = ddp->len;
break;
case cpu_to_le32(IXGBE_RXDADV_STAT_FCSTAT_NOMTCH):
default:
break;
}
if ((fh->fh_r_ctl == FC_RCTL_DD_SOL_DATA) &&
(fctl & FC_FC_END_SEQ)) {
skb_linearize(skb);
crc = (struct fcoe_crc_eof *)skb_put(skb, sizeof(*crc));
crc->fcoe_eof = FC_EOF_T;
}
return rc;
}
int ixgbe_fso(struct ixgbe_ring *tx_ring,
struct ixgbe_tx_buffer *first,
u8 *hdr_len)
{
struct sk_buff *skb = first->skb;
struct fc_frame_header *fh;
u32 vlan_macip_lens;
u32 fcoe_sof_eof = 0;
u32 mss_l4len_idx;
u8 sof, eof;
if (skb_is_gso(skb) && (skb_shinfo(skb)->gso_type != SKB_GSO_FCOE)) {
dev_err(tx_ring->dev, "Wrong gso type %d:expecting SKB_GSO_FCOE\n",
skb_shinfo(skb)->gso_type);
return -EINVAL;
}
skb_set_network_header(skb, skb->mac_len);
skb_set_transport_header(skb, skb->mac_len +
sizeof(struct fcoe_hdr));
sof = ((struct fcoe_hdr *)skb_network_header(skb))->fcoe_sof;
switch (sof) {
case FC_SOF_I2:
fcoe_sof_eof = IXGBE_ADVTXD_FCOEF_ORIS;
break;
case FC_SOF_I3:
fcoe_sof_eof = IXGBE_ADVTXD_FCOEF_SOF |
IXGBE_ADVTXD_FCOEF_ORIS;
break;
case FC_SOF_N2:
break;
case FC_SOF_N3:
fcoe_sof_eof = IXGBE_ADVTXD_FCOEF_SOF;
break;
default:
dev_warn(tx_ring->dev, "unknown sof = 0x%x\n", sof);
return -EINVAL;
}
skb_copy_bits(skb, skb->len - 4, &eof, 1);
switch (eof) {
case FC_EOF_N:
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_EOF_N;
break;
case FC_EOF_T:
if (skb_is_gso(skb))
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_EOF_N |
IXGBE_ADVTXD_FCOEF_ORIE;
else
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_EOF_T;
break;
case FC_EOF_NI:
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_EOF_NI;
break;
case FC_EOF_A:
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_EOF_A;
break;
default:
dev_warn(tx_ring->dev, "unknown eof = 0x%x\n", eof);
return -EINVAL;
}
fh = (struct fc_frame_header *)skb_transport_header(skb);
if (fh->fh_f_ctl[2] & FC_FC_REL_OFF)
fcoe_sof_eof |= IXGBE_ADVTXD_FCOEF_PARINC;
*hdr_len = sizeof(struct fcoe_crc_eof);
if (skb_is_gso(skb)) {
*hdr_len += skb_transport_offset(skb) +
sizeof(struct fc_frame_header);
first->gso_segs = DIV_ROUND_UP(skb->len - *hdr_len,
skb_shinfo(skb)->gso_size);
first->bytecount += (first->gso_segs - 1) * *hdr_len;
first->tx_flags |= IXGBE_TX_FLAGS_TSO;
}
first->tx_flags |= IXGBE_TX_FLAGS_FCOE | IXGBE_TX_FLAGS_CC;
mss_l4len_idx = skb_shinfo(skb)->gso_size << IXGBE_ADVTXD_MSS_SHIFT;
vlan_macip_lens = skb_transport_offset(skb) +
sizeof(struct fc_frame_header);
vlan_macip_lens |= (skb_transport_offset(skb) - 4)
<< IXGBE_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= first->tx_flags & IXGBE_TX_FLAGS_VLAN_MASK;
ixgbe_tx_ctxtdesc(tx_ring, vlan_macip_lens, fcoe_sof_eof,
IXGBE_ADVTXT_TUCMD_FCOE, mss_l4len_idx);
return 0;
}
static void ixgbe_fcoe_dma_pool_free(struct ixgbe_fcoe *fcoe, unsigned int cpu)
{
struct ixgbe_fcoe_ddp_pool *ddp_pool;
ddp_pool = per_cpu_ptr(fcoe->ddp_pool, cpu);
if (ddp_pool->pool)
dma_pool_destroy(ddp_pool->pool);
ddp_pool->pool = NULL;
}
static int ixgbe_fcoe_dma_pool_alloc(struct ixgbe_fcoe *fcoe,
struct device *dev,
unsigned int cpu)
{
struct ixgbe_fcoe_ddp_pool *ddp_pool;
struct dma_pool *pool;
char pool_name[32];
snprintf(pool_name, 32, "ixgbe_fcoe_ddp_%u", cpu);
pool = dma_pool_create(pool_name, dev, IXGBE_FCPTR_MAX,
IXGBE_FCPTR_ALIGN, PAGE_SIZE);
if (!pool)
return -ENOMEM;
ddp_pool = per_cpu_ptr(fcoe->ddp_pool, cpu);
ddp_pool->pool = pool;
ddp_pool->noddp = 0;
ddp_pool->noddp_ext_buff = 0;
return 0;
}
void ixgbe_configure_fcoe(struct ixgbe_adapter *adapter)
{
struct ixgbe_ring_feature *fcoe = &adapter->ring_feature[RING_F_FCOE];
struct ixgbe_hw *hw = &adapter->hw;
int i, fcoe_q, fcoe_i;
u32 etqf;
if (!(adapter->netdev->features & NETIF_F_FCOE_CRC))
return;
etqf = ETH_P_FCOE | IXGBE_ETQF_FCOE | IXGBE_ETQF_FILTER_EN;
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) {
etqf |= IXGBE_ETQF_POOL_ENABLE;
etqf |= VMDQ_P(0) << IXGBE_ETQF_POOL_SHIFT;
}
IXGBE_WRITE_REG(hw, IXGBE_ETQF(IXGBE_ETQF_FILTER_FCOE), etqf);
IXGBE_WRITE_REG(hw, IXGBE_ETQS(IXGBE_ETQF_FILTER_FCOE), 0);
if (!(adapter->flags & IXGBE_FLAG_FCOE_ENABLED))
return;
for (i = 0; i < IXGBE_FCRETA_SIZE; i++) {
fcoe_i = fcoe->offset + (i % fcoe->indices);
fcoe_i &= IXGBE_FCRETA_ENTRY_MASK;
fcoe_q = adapter->rx_ring[fcoe_i]->reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_FCRETA(i), fcoe_q);
}
IXGBE_WRITE_REG(hw, IXGBE_FCRECTL, IXGBE_FCRECTL_ENA);
etqf = ETH_P_FIP | IXGBE_ETQF_FILTER_EN;
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) {
etqf |= IXGBE_ETQF_POOL_ENABLE;
etqf |= VMDQ_P(0) << IXGBE_ETQF_POOL_SHIFT;
}
IXGBE_WRITE_REG(hw, IXGBE_ETQF(IXGBE_ETQF_FILTER_FIP), etqf);
fcoe_q = adapter->rx_ring[fcoe->offset]->reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_ETQS(IXGBE_ETQF_FILTER_FIP),
IXGBE_ETQS_QUEUE_EN |
(fcoe_q << IXGBE_ETQS_RX_QUEUE_SHIFT));
IXGBE_WRITE_REG(hw, IXGBE_FCRXCTRL,
IXGBE_FCRXCTRL_FCCRCBO |
(FC_FCOE_VER << IXGBE_FCRXCTRL_FCOEVER_SHIFT));
}
void ixgbe_free_fcoe_ddp_resources(struct ixgbe_adapter *adapter)
{
struct ixgbe_fcoe *fcoe = &adapter->fcoe;
int cpu, i;
if (!fcoe->ddp_pool)
return;
for (i = 0; i < IXGBE_FCOE_DDP_MAX; i++)
ixgbe_fcoe_ddp_put(adapter->netdev, i);
for_each_possible_cpu(cpu)
ixgbe_fcoe_dma_pool_free(fcoe, cpu);
dma_unmap_single(&adapter->pdev->dev,
fcoe->extra_ddp_buffer_dma,
IXGBE_FCBUFF_MIN,
DMA_FROM_DEVICE);
kfree(fcoe->extra_ddp_buffer);
fcoe->extra_ddp_buffer = NULL;
fcoe->extra_ddp_buffer_dma = 0;
}
int ixgbe_setup_fcoe_ddp_resources(struct ixgbe_adapter *adapter)
{
struct ixgbe_fcoe *fcoe = &adapter->fcoe;
struct device *dev = &adapter->pdev->dev;
void *buffer;
dma_addr_t dma;
unsigned int cpu;
if (!fcoe->ddp_pool)
return 0;
buffer = kmalloc(IXGBE_FCBUFF_MIN, GFP_ATOMIC);
if (!buffer)
return -ENOMEM;
dma = dma_map_single(dev, buffer, IXGBE_FCBUFF_MIN, DMA_FROM_DEVICE);
if (dma_mapping_error(dev, dma)) {
e_err(drv, "failed to map extra DDP buffer\n");
kfree(buffer);
return -ENOMEM;
}
fcoe->extra_ddp_buffer = buffer;
fcoe->extra_ddp_buffer_dma = dma;
for_each_possible_cpu(cpu) {
int err = ixgbe_fcoe_dma_pool_alloc(fcoe, dev, cpu);
if (!err)
continue;
e_err(drv, "failed to alloc DDP pool on cpu:%d\n", cpu);
ixgbe_free_fcoe_ddp_resources(adapter);
return -ENOMEM;
}
return 0;
}
static int ixgbe_fcoe_ddp_enable(struct ixgbe_adapter *adapter)
{
struct ixgbe_fcoe *fcoe = &adapter->fcoe;
if (!(adapter->flags & IXGBE_FLAG_FCOE_CAPABLE))
return -EINVAL;
fcoe->ddp_pool = alloc_percpu(struct ixgbe_fcoe_ddp_pool);
if (!fcoe->ddp_pool) {
e_err(drv, "failed to allocate percpu DDP resources\n");
return -ENOMEM;
}
adapter->netdev->fcoe_ddp_xid = IXGBE_FCOE_DDP_MAX - 1;
return 0;
}
static void ixgbe_fcoe_ddp_disable(struct ixgbe_adapter *adapter)
{
struct ixgbe_fcoe *fcoe = &adapter->fcoe;
adapter->netdev->fcoe_ddp_xid = 0;
if (!fcoe->ddp_pool)
return;
free_percpu(fcoe->ddp_pool);
fcoe->ddp_pool = NULL;
}
int ixgbe_fcoe_enable(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_fcoe *fcoe = &adapter->fcoe;
atomic_inc(&fcoe->refcnt);
if (!(adapter->flags & IXGBE_FLAG_FCOE_CAPABLE))
return -EINVAL;
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED)
return -EINVAL;
e_info(drv, "Enabling FCoE offload features.\n");
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
e_warn(probe, "Enabling FCoE on PF will disable legacy VFs\n");
if (netif_running(netdev))
netdev->netdev_ops->ndo_stop(netdev);
ixgbe_fcoe_ddp_enable(adapter);
adapter->flags |= IXGBE_FLAG_FCOE_ENABLED;
netdev->features |= NETIF_F_FCOE_MTU;
netdev_features_change(netdev);
ixgbe_clear_interrupt_scheme(adapter);
ixgbe_init_interrupt_scheme(adapter);
if (netif_running(netdev))
netdev->netdev_ops->ndo_open(netdev);
return 0;
}
int ixgbe_fcoe_disable(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (!atomic_dec_and_test(&adapter->fcoe.refcnt))
return -EINVAL;
if (!(adapter->flags & IXGBE_FLAG_FCOE_ENABLED))
return -EINVAL;
e_info(drv, "Disabling FCoE offload features.\n");
if (netif_running(netdev))
netdev->netdev_ops->ndo_stop(netdev);
ixgbe_fcoe_ddp_disable(adapter);
adapter->flags &= ~IXGBE_FLAG_FCOE_ENABLED;
netdev->features &= ~NETIF_F_FCOE_MTU;
netdev_features_change(netdev);
ixgbe_clear_interrupt_scheme(adapter);
ixgbe_init_interrupt_scheme(adapter);
if (netif_running(netdev))
netdev->netdev_ops->ndo_open(netdev);
return 0;
}
int ixgbe_fcoe_get_wwn(struct net_device *netdev, u64 *wwn, int type)
{
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
return 0;
}
return -EINVAL;
}
int ixgbe_fcoe_get_hbainfo(struct net_device *netdev,
struct netdev_fcoe_hbainfo *info)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int i, pos;
u8 buf[8];
if (!info)
return -EINVAL;
if (hw->mac.type != ixgbe_mac_82599EB &&
hw->mac.type != ixgbe_mac_X540)
return -EINVAL;
snprintf(info->manufacturer, sizeof(info->manufacturer),
"Intel Corporation");
pos = pci_find_ext_capability(adapter->pdev, PCI_EXT_CAP_ID_DSN);
if (pos) {
pos += 4;
for (i = 0; i < 8; i++)
pci_read_config_byte(adapter->pdev, pos + i, &buf[i]);
snprintf(info->serial_number, sizeof(info->serial_number),
"%02X%02X%02X%02X%02X%02X%02X%02X",
buf[7], buf[6], buf[5], buf[4],
buf[3], buf[2], buf[1], buf[0]);
} else
snprintf(info->serial_number, sizeof(info->serial_number),
"Unknown");
snprintf(info->hardware_version,
sizeof(info->hardware_version),
"Rev %d", hw->revision_id);
snprintf(info->driver_version,
sizeof(info->driver_version),
"%s v%s",
ixgbe_driver_name,
ixgbe_driver_version);
snprintf(info->firmware_version,
sizeof(info->firmware_version),
"0x%08x",
(adapter->eeprom_verh << 16) |
adapter->eeprom_verl);
if (hw->mac.type == ixgbe_mac_82599EB) {
snprintf(info->model,
sizeof(info->model),
"Intel 82599");
} else {
snprintf(info->model,
sizeof(info->model),
"Intel X540");
}
snprintf(info->model_description,
sizeof(info->model_description),
"%s",
ixgbe_default_device_descr);
return 0;
}
u8 ixgbe_fcoe_get_tc(struct ixgbe_adapter *adapter)
{
#ifdef CONFIG_IXGBE_DCB
return netdev_get_prio_tc_map(adapter->netdev, adapter->fcoe.up);
#else
return 0;
#endif
}
