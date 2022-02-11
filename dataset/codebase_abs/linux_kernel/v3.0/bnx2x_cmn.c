static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
struct V_6 V_7 = V_5 -> V_8 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_8 = V_7 ;
}
static inline void F_2 ( struct V_1 * V_2 , int V_9 , int V_10 )
{
struct V_4 * V_11 = & V_2 -> V_5 [ V_9 ] ;
struct V_4 * V_12 = & V_2 -> V_5 [ V_10 ] ;
struct V_6 V_7 = V_12 -> V_8 ;
memcpy ( V_12 , V_11 , sizeof( * V_12 ) ) ;
V_12 -> V_3 = V_10 ;
V_12 -> V_8 = V_7 ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_4 * V_5 ,
T_1 V_13 )
{
struct V_14 * V_15 = & V_5 -> V_16 [ V_13 ] ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = V_15 -> V_22 ;
T_1 V_23 = F_4 ( V_15 -> V_24 ) , V_25 ;
int V_26 ;
F_5 ( & V_22 -> V_27 ) ;
F_6 ( V_28 , L_1 ,
V_13 , V_15 , V_22 ) ;
F_6 ( V_28 , L_2 , V_23 ) ;
V_18 = & V_5 -> V_29 [ V_23 ] . V_30 ;
F_7 ( & V_2 -> V_31 -> V_32 , F_8 ( V_18 ) ,
F_9 ( V_18 ) , V_33 ) ;
V_26 = F_10 ( V_18 -> V_26 ) - 1 ;
#ifdef F_11
if ( ( V_26 - 1 ) > ( V_34 + 2 ) ) {
F_12 ( L_3 ) ;
F_13 () ;
}
#endif
V_25 = V_26 + V_15 -> V_24 ;
V_23 = F_4 ( F_14 ( V_23 ) ) ;
-- V_26 ;
V_23 = F_4 ( F_14 ( V_23 ) ) ;
if ( V_15 -> V_35 & V_36 ) {
-- V_26 ;
V_23 = F_4 ( F_14 ( V_23 ) ) ;
}
while ( V_26 > 0 ) {
F_6 ( V_28 , L_4 , V_23 ) ;
V_20 = & V_5 -> V_29 [ V_23 ] . V_37 ;
F_15 ( & V_2 -> V_31 -> V_32 , F_8 ( V_20 ) ,
F_9 ( V_20 ) , V_33 ) ;
if ( -- V_26 )
V_23 = F_4 ( F_14 ( V_23 ) ) ;
}
F_16 ( ! V_22 ) ;
F_17 ( V_22 ) ;
V_15 -> V_24 = 0 ;
V_15 -> V_22 = NULL ;
return V_25 ;
}
int F_18 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_38 * V_39 ;
T_1 V_40 , V_41 , V_42 = V_5 -> V_43 ;
#ifdef F_11
if ( F_19 ( V_2 -> V_44 ) )
return - 1 ;
#endif
V_39 = F_20 ( V_2 -> V_32 , V_5 -> V_3 ) ;
V_40 = F_10 ( * V_5 -> V_45 ) ;
V_41 = V_5 -> V_46 ;
while ( V_41 != V_40 ) {
T_1 V_47 ;
V_47 = F_4 ( V_41 ) ;
F_6 ( V_48 , L_5
L_6 ,
V_5 -> V_3 , V_40 , V_41 , V_47 ) ;
V_42 = F_3 ( V_2 , V_5 , V_47 ) ;
V_41 ++ ;
}
V_5 -> V_46 = V_41 ;
V_5 -> V_43 = V_42 ;
F_21 () ;
if ( F_19 ( F_22 ( V_39 ) ) ) {
F_23 ( V_39 , F_24 () ) ;
if ( ( F_22 ( V_39 ) ) &&
( V_2 -> V_49 == V_50 ) &&
( F_25 ( V_5 ) >= V_34 + 3 ) )
F_26 ( V_39 ) ;
F_27 ( V_39 ) ;
}
return 0 ;
}
static inline void F_28 ( struct V_4 * V_5 ,
T_1 V_13 )
{
T_1 V_51 = V_5 -> V_52 ;
if ( F_29 ( V_13 , V_51 ) > 0 )
V_5 -> V_52 = V_13 ;
}
static void F_30 ( struct V_4 * V_5 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
T_1 V_55 = F_31 ( F_10 ( V_54 -> V_56 ) -
F_10 ( V_54 -> V_57 ) ) >>
V_58 ;
T_1 V_51 , V_59 , V_60 ;
T_1 V_61 = 0 ;
T_1 V_62 ;
if ( ! V_55 )
return;
for ( V_62 = 0 ; V_62 < V_55 ; V_62 ++ )
F_32 ( V_5 ,
F_33 ( F_10 ( V_54 -> V_63 . V_64 [ V_62 ] ) ) ) ;
F_6 ( V_65 , L_7 ,
V_55 - 1 , F_10 ( V_54 -> V_63 . V_64 [ V_55 - 1 ] ) ) ;
F_5 ( ( void * ) ( V_5 -> V_66 ) ) ;
F_28 ( V_5 ,
F_10 ( V_54 -> V_63 . V_64 [ V_55 - 1 ] ) ) ;
V_51 = F_33 ( V_5 -> V_52 ) ;
V_59 = V_51 >> V_67 ;
V_60 = F_33 ( V_5 -> V_68 ) >> V_67 ;
if ( V_59 + 1 != V_60 )
V_59 ++ ;
for ( V_62 = V_60 ; V_62 != V_59 ; V_62 = F_34 ( V_62 ) ) {
if ( F_35 ( V_5 -> V_66 [ V_62 ] ) )
break;
V_5 -> V_66 [ V_62 ] = V_69 ;
V_61 += V_70 ;
}
if ( V_61 > 0 ) {
V_5 -> V_68 += V_61 ;
F_36 ( V_5 ) ;
}
F_6 ( V_65 ,
L_8 ,
V_5 -> V_52 , V_5 -> V_68 ) ;
}
static void F_37 ( struct V_4 * V_5 , T_1 V_71 ,
struct V_21 * V_22 , T_1 V_72 , T_1 V_73 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_74 * V_75 = & V_5 -> V_76 [ V_72 ] ;
struct V_74 * V_77 = & V_5 -> V_76 [ V_73 ] ;
struct V_78 * V_79 = & V_5 -> V_80 [ V_73 ] ;
T_2 V_81 ;
V_77 -> V_22 = V_5 -> V_82 [ V_71 ] . V_22 ;
V_81 = F_38 ( & V_2 -> V_31 -> V_32 , V_5 -> V_82 [ V_71 ] . V_22 -> V_83 ,
V_5 -> V_84 , V_85 ) ;
F_39 ( V_77 , V_81 , V_81 ) ;
V_5 -> V_82 [ V_71 ] = * V_75 ;
if ( V_5 -> V_86 [ V_71 ] != V_87 )
F_12 ( L_9 , V_71 ) ;
V_5 -> V_86 [ V_71 ] = V_88 ;
V_79 -> V_89 = F_40 ( F_41 ( V_81 ) ) ;
V_79 -> V_90 = F_40 ( F_42 ( V_81 ) ) ;
#ifdef F_11
V_5 -> V_91 |= ( 1 << V_71 ) ;
#ifdef F_43
F_6 (NETIF_MSG_RX_STATUS, L_10 ,
#else
DP(NETIF_MSG_RX_STATUS, L_11,
#endif
fp->tpa_queue_used);
#endif
}
#define F_44 12
static inline u16 bnx2x_set_lro_mss(struct bnx2x *bp, u16 parsing_flags,
u16 len_on_bd)
{
u16 hdrs_len = ETH_HLEN + sizeof(struct iphdr) + sizeof(struct tcphdr);
if (parsing_flags & PARSING_FLAGS_TIME_STAMP_EXIST_FLAG)
hdrs_len += TPA_TSTAMP_OPT_LEN;
return len_on_bd - hdrs_len;
}
static int bnx2x_fill_frag_skb(struct bnx2x *bp, struct bnx2x_fastpath *fp,
struct sk_buff *skb,
struct eth_fast_path_rx_cqe *fp_cqe,
u16 cqe_idx, u16 parsing_flags)
{
struct sw_rx_page *rx_pg, old_rx_pg;
u16 len_on_bd = le16_to_cpu(fp_cqe->len_on_bd);
u32 i, frag_len, frag_size, pages;
int err;
int j;
frag_size = le16_to_cpu(fp_cqe->pkt_len) - len_on_bd;
pages = SGE_PAGE_ALIGN(frag_size) >> SGE_PAGE_SHIFT;
if (frag_size)
skb_shinfo(skb)->gso_size = bnx2x_set_lro_mss(bp, parsing_flags,
len_on_bd);
#ifdef F_11
if (pages > min_t(u32, 8, MAX_SKB_FRAGS)*SGE_PAGE_SIZE*PAGES_PER_SGE) {
BNX2X_ERR(L_12,
pages, cqe_idx);
BNX2X_ERR(L_13,
fp_cqe->pkt_len, len_on_bd);
bnx2x_panic();
return -EINVAL;
}
#endif
for (i = 0, j = 0; i < pages; i += PAGES_PER_SGE, j++) {
u16 sge_idx =
RX_SGE(le16_to_cpu(fp_cqe->sgl_or_raw_data.sgl[j]));
frag_len = min(frag_size, (u32)(SGE_PAGE_SIZE*PAGES_PER_SGE));
rx_pg = &fp->rx_page_ring[sge_idx];
old_rx_pg = *rx_pg;
err = bnx2x_alloc_rx_sge(bp, fp, sge_idx);
if (unlikely(err)) {
fp->eth_q_stats.rx_skb_alloc_failed++;
return err;
}
dma_unmap_page(&bp->pdev->dev,
dma_unmap_addr(&old_rx_pg, mapping),
SGE_PAGE_SIZE*PAGES_PER_SGE, DMA_FROM_DEVICE);
skb_fill_page_desc(skb, j, old_rx_pg.page, 0, frag_len);
skb->data_len += frag_len;
skb->truesize += frag_len;
skb->len += frag_len;
frag_size -= frag_len;
}
return 0;
}
static void bnx2x_tpa_stop(struct bnx2x *bp, struct bnx2x_fastpath *fp,
u16 queue, int pad, int len, union eth_rx_cqe *cqe,
u16 cqe_idx)
{
struct sw_rx_bd *rx_buf = &fp->tpa_pool[queue];
struct sk_buff *skb = rx_buf->skb;
struct sk_buff *new_skb = netdev_alloc_skb(bp->dev, fp->rx_buf_size);
dma_unmap_single(&bp->pdev->dev, dma_unmap_addr(rx_buf, mapping),
fp->rx_buf_size, DMA_FROM_DEVICE);
if (likely(new_skb)) {
u16 parsing_flags =
le16_to_cpu(cqe->fast_path_cqe.pars_flags.flags);
prefetch(skb);
prefetch(((char *)(skb)) + L1_CACHE_BYTES);
#ifdef F_11
if (pad + len > fp->rx_buf_size) {
BNX2X_ERR(L_14
L_15,
pad, len, fp->rx_buf_size);
bnx2x_panic();
return;
}
#endif
skb_reserve(skb, pad);
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, bp->dev);
skb->ip_summed = CHECKSUM_UNNECESSARY;
{
struct iphdr *iph;
iph = (struct iphdr *)skb->data;
iph->check = 0;
iph->check = ip_fast_csum((u8 *)iph, iph->ihl);
}
if (!bnx2x_fill_frag_skb(bp, fp, skb,
&cqe->fast_path_cqe, cqe_idx,
parsing_flags)) {
if (parsing_flags & PARSING_FLAGS_VLAN)
__vlan_hwaccel_put_tag(skb,
le16_to_cpu(cqe->fast_path_cqe.
vlan_tag));
napi_gro_receive(&fp->napi, skb);
} else {
DP(NETIF_MSG_RX_STATUS, L_16
L_17);
dev_kfree_skb_any(skb);
}
fp->tpa_pool[queue].skb = new_skb;
} else {
DP(NETIF_MSG_RX_STATUS,
L_18);
fp->eth_q_stats.rx_skb_alloc_failed++;
}
fp->tpa_state[queue] = BNX2X_TPA_STOP;
}
static inline void bnx2x_set_skb_rxhash(struct bnx2x *bp, union eth_rx_cqe *cqe,
struct sk_buff *skb)
{
if ((bp->dev->features & NETIF_F_RXHASH) &&
(cqe->fast_path_cqe.status_flags &
ETH_FAST_PATH_RX_CQE_RSS_HASH_FLG))
skb->rxhash =
le32_to_cpu(cqe->fast_path_cqe.rss_hash_result);
}
int bnx2x_rx_int(struct bnx2x_fastpath *fp, int budget)
{
struct bnx2x *bp = fp->bp;
u16 bd_cons, bd_prod, bd_prod_fw, comp_ring_cons;
u16 hw_comp_cons, sw_comp_cons, sw_comp_prod;
int rx_pkt = 0;
#ifdef F_11
if (unlikely(bp->panic))
return 0;
#endif
hw_comp_cons = le16_to_cpu(*fp->rx_cons_sb);
if ((hw_comp_cons & MAX_RCQ_DESC_CNT) == MAX_RCQ_DESC_CNT)
hw_comp_cons++;
bd_cons = fp->rx_bd_cons;
bd_prod = fp->rx_bd_prod;
bd_prod_fw = bd_prod;
sw_comp_cons = fp->rx_comp_cons;
sw_comp_prod = fp->rx_comp_prod;
rmb();
DP(NETIF_MSG_RX_STATUS,
L_19,
fp->index, hw_comp_cons, sw_comp_cons);
while (sw_comp_cons != hw_comp_cons) {
struct sw_rx_bd *rx_buf = NULL;
struct sk_buff *skb;
union eth_rx_cqe *cqe;
u8 cqe_fp_flags;
u16 len, pad;
comp_ring_cons = RCQ_BD(sw_comp_cons);
bd_prod = RX_BD(bd_prod);
bd_cons = RX_BD(bd_cons);
prefetch((void *)(PAGE_ALIGN((unsigned long)
(&fp->rx_desc_ring[bd_prod])) -
PAGE_SIZE + 1));
cqe = &fp->rx_comp_ring[comp_ring_cons];
cqe_fp_flags = cqe->fast_path_cqe.type_error_flags;
DP(NETIF_MSG_RX_STATUS, L_20
L_21, CQE_TYPE(cqe_fp_flags),
cqe_fp_flags, cqe->fast_path_cqe.status_flags,
le32_to_cpu(cqe->fast_path_cqe.rss_hash_result),
le16_to_cpu(cqe->fast_path_cqe.vlan_tag),
le16_to_cpu(cqe->fast_path_cqe.pkt_len));
if (unlikely(CQE_TYPE(cqe_fp_flags))) {
bnx2x_sp_event(fp, cqe);
goto next_cqe;
} else {
rx_buf = &fp->rx_buf_ring[bd_cons];
skb = rx_buf->skb;
prefetch(skb);
len = le16_to_cpu(cqe->fast_path_cqe.pkt_len);
pad = cqe->fast_path_cqe.placement_offset;
if ((!fp->disable_tpa) &&
(TPA_TYPE(cqe_fp_flags) !=
(TPA_TYPE_START | TPA_TYPE_END))) {
u16 queue = cqe->fast_path_cqe.queue_index;
if (TPA_TYPE(cqe_fp_flags) == TPA_TYPE_START) {
DP(NETIF_MSG_RX_STATUS,
L_22,
queue);
bnx2x_tpa_start(fp, queue, skb,
bd_cons, bd_prod);
bnx2x_set_skb_rxhash(bp, cqe, skb);
goto next_rx;
} else {
DP(NETIF_MSG_RX_STATUS,
L_23,
queue);
if (!BNX2X_RX_SUM_FIX(cqe))
BNX2X_ERR(L_24
L_25);
len = le16_to_cpu(cqe->fast_path_cqe.
len_on_bd);
bnx2x_tpa_stop(bp, fp, queue, pad,
len, cqe, comp_ring_cons);
#ifdef F_11
if (bp->panic)
return 0;
#endif
bnx2x_update_sge_prod(fp,
&cqe->fast_path_cqe);
goto next_cqe;
}
}
dma_sync_single_for_device(&bp->pdev->dev,
dma_unmap_addr(rx_buf, mapping),
pad + RX_COPY_THRESH,
DMA_FROM_DEVICE);
prefetch(((char *)(skb)) + L1_CACHE_BYTES);
if (unlikely(cqe_fp_flags & ETH_RX_ERROR_FALGS)) {
DP(NETIF_MSG_RX_ERR,
L_26,
cqe_fp_flags, sw_comp_cons);
fp->eth_q_stats.rx_err_discard_pkt++;
goto reuse_rx;
}
if ((bp->dev->mtu > ETH_MAX_PACKET_SIZE) &&
(len <= RX_COPY_THRESH)) {
struct sk_buff *new_skb;
new_skb = netdev_alloc_skb(bp->dev,
len + pad);
if (new_skb == NULL) {
DP(NETIF_MSG_RX_ERR,
L_27
L_28);
fp->eth_q_stats.rx_skb_alloc_failed++;
goto reuse_rx;
}
skb_copy_from_linear_data_offset(skb, pad,
new_skb->data + pad, len);
skb_reserve(new_skb, pad);
skb_put(new_skb, len);
bnx2x_reuse_rx_skb(fp, bd_cons, bd_prod);
skb = new_skb;
} else
if (likely(bnx2x_alloc_rx_skb(bp, fp, bd_prod) == 0)) {
dma_unmap_single(&bp->pdev->dev,
dma_unmap_addr(rx_buf, mapping),
fp->rx_buf_size,
DMA_FROM_DEVICE);
skb_reserve(skb, pad);
skb_put(skb, len);
} else {
DP(NETIF_MSG_RX_ERR,
L_29
L_30);
fp->eth_q_stats.rx_skb_alloc_failed++;
reuse_rx:
bnx2x_reuse_rx_skb(fp, bd_cons, bd_prod);
goto next_rx;
}
skb->protocol = eth_type_trans(skb, bp->dev);
bnx2x_set_skb_rxhash(bp, cqe, skb);
skb_checksum_none_assert(skb);
if (bp->dev->features & NETIF_F_RXCSUM) {
if (likely(BNX2X_RX_CSUM_OK(cqe)))
skb->ip_summed = CHECKSUM_UNNECESSARY;
else
fp->eth_q_stats.hw_csum_err++;
}
}
skb_record_rx_queue(skb, fp->index);
if (le16_to_cpu(cqe->fast_path_cqe.pars_flags.flags) &
PARSING_FLAGS_VLAN)
__vlan_hwaccel_put_tag(skb,
le16_to_cpu(cqe->fast_path_cqe.vlan_tag));
napi_gro_receive(&fp->napi, skb);
next_rx:
rx_buf->skb = NULL;
bd_cons = NEXT_RX_IDX(bd_cons);
bd_prod = NEXT_RX_IDX(bd_prod);
bd_prod_fw = NEXT_RX_IDX(bd_prod_fw);
rx_pkt++;
next_cqe:
sw_comp_prod = NEXT_RCQ_IDX(sw_comp_prod);
sw_comp_cons = NEXT_RCQ_IDX(sw_comp_cons);
if (rx_pkt == budget)
break;
}
fp->rx_bd_cons = bd_cons;
fp->rx_bd_prod = bd_prod_fw;
fp->rx_comp_cons = sw_comp_cons;
fp->rx_comp_prod = sw_comp_prod;
bnx2x_update_rx_prod(bp, fp, bd_prod_fw, sw_comp_prod,
fp->rx_sge_prod);
fp->rx_pkt += rx_pkt;
fp->rx_calls++;
return rx_pkt;
}
static irqreturn_t bnx2x_msix_fp_int(int irq, void *fp_cookie)
{
struct bnx2x_fastpath *fp = fp_cookie;
struct bnx2x *bp = fp->bp;
if (unlikely(atomic_read(&bp->intr_sem) != 0)) {
DP(NETIF_MSG_INTR, L_31);
return IRQ_HANDLED;
}
DP(BNX2X_MSG_FP, L_32
L_33,
fp->index, fp->fw_sb_id, fp->igu_sb_id);
bnx2x_ack_sb(bp, fp->igu_sb_id, USTORM_ID, 0, IGU_INT_DISABLE, 0);
#ifdef F_11
if (unlikely(bp->panic))
return IRQ_HANDLED;
#endif
prefetch(fp->rx_cons_sb);
prefetch(fp->tx_cons_sb);
prefetch(&fp->sb_running_index[SM_RX_ID]);
napi_schedule(&bnx2x_fp(bp, fp->index, napi));
return IRQ_HANDLED;
}
void bnx2x_acquire_phy_lock(struct bnx2x *bp)
{
mutex_lock(&bp->port.phy_mutex);
if (bp->port.need_hw_lock)
bnx2x_acquire_hw_lock(bp, HW_LOCK_RESOURCE_MDIO);
}
void bnx2x_release_phy_lock(struct bnx2x *bp)
{
if (bp->port.need_hw_lock)
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_MDIO);
mutex_unlock(&bp->port.phy_mutex);
}
u16 bnx2x_get_mf_speed(struct bnx2x *bp)
{
u16 line_speed = bp->link_vars.line_speed;
if (IS_MF(bp)) {
u16 maxCfg = bnx2x_extract_max_cfg(bp,
bp->mf_config[BP_VN(bp)]);
if (IS_MF_SI(bp))
line_speed = (line_speed * maxCfg) / 100;
else {
u16 vn_max_rate = maxCfg * 100;
if (vn_max_rate < line_speed)
line_speed = vn_max_rate;
}
}
return line_speed;
}
static inline void bnx2x_fill_report_data(struct bnx2x *bp,
struct bnx2x_link_report_data *data)
{
u16 line_speed = bnx2x_get_mf_speed(bp);
memset(data, 0, sizeof(*data));
data->line_speed = line_speed;
if (!bp->link_vars.link_up || (bp->flags & MF_FUNC_DIS))
__set_bit(BNX2X_LINK_REPORT_LINK_DOWN,
&data->link_report_flags);
if (bp->link_vars.duplex == DUPLEX_FULL)
__set_bit(BNX2X_LINK_REPORT_FD, &data->link_report_flags);
if (bp->link_vars.flow_ctrl & BNX2X_FLOW_CTRL_RX)
__set_bit(BNX2X_LINK_REPORT_RX_FC_ON, &data->link_report_flags);
if (bp->link_vars.flow_ctrl & BNX2X_FLOW_CTRL_TX)
__set_bit(BNX2X_LINK_REPORT_TX_FC_ON, &data->link_report_flags);
}
void bnx2x_link_report(struct bnx2x *bp)
{
bnx2x_acquire_phy_lock(bp);
__bnx2x_link_report(bp);
bnx2x_release_phy_lock(bp);
}
void __bnx2x_link_report(struct bnx2x *bp)
{
struct bnx2x_link_report_data cur_data;
if (!CHIP_IS_E1(bp))
bnx2x_read_mf_cfg(bp);
bnx2x_fill_report_data(bp, &cur_data);
if (!memcmp(&cur_data, &bp->last_reported_link, sizeof(cur_data)) ||
(test_bit(BNX2X_LINK_REPORT_LINK_DOWN,
&bp->last_reported_link.link_report_flags) &&
test_bit(BNX2X_LINK_REPORT_LINK_DOWN,
&cur_data.link_report_flags)))
return;
bp->link_cnt++;
memcpy(&bp->last_reported_link, &cur_data, sizeof(cur_data));
if (test_bit(BNX2X_LINK_REPORT_LINK_DOWN,
&cur_data.link_report_flags)) {
netif_carrier_off(bp->dev);
netdev_err(bp->dev, L_34);
return;
} else {
netif_carrier_on(bp->dev);
netdev_info(bp->dev, L_35);
pr_cont(L_36, cur_data.line_speed);
if (test_and_clear_bit(BNX2X_LINK_REPORT_FD,
&cur_data.link_report_flags))
pr_cont(L_37);
else
pr_cont(L_38);
if (cur_data.link_report_flags) {
if (test_bit(BNX2X_LINK_REPORT_RX_FC_ON,
&cur_data.link_report_flags)) {
pr_cont(L_39);
if (test_bit(BNX2X_LINK_REPORT_TX_FC_ON,
&cur_data.link_report_flags))
pr_cont(L_40);
} else {
pr_cont(L_41);
}
pr_cont(L_42);
}
pr_cont(L_43);
}
}
void bnx2x_init_rx_rings(struct bnx2x *bp)
{
int func = BP_FUNC(bp);
int max_agg_queues = CHIP_IS_E1(bp) ? ETH_MAX_AGGREGATION_QUEUES_E1 :
ETH_MAX_AGGREGATION_QUEUES_E1H;
u16 ring_prod;
int i, j;
for_each_rx_queue(bp, j) {
struct bnx2x_fastpath *fp = &bp->fp[j];
DP(NETIF_MSG_IFUP,
L_44, bp->dev->mtu, fp->rx_buf_size);
if (!fp->disable_tpa) {
for (i = 0; i < max_agg_queues; i++) {
fp->tpa_pool[i].skb =
netdev_alloc_skb(bp->dev, fp->rx_buf_size);
if (!fp->tpa_pool[i].skb) {
BNX2X_ERR(L_45
L_46
L_47
L_48, j);
bnx2x_free_tpa_pool(bp, fp, i);
fp->disable_tpa = 1;
break;
}
dma_unmap_addr_set((struct sw_rx_bd *)
&bp->fp->tpa_pool[i],
mapping, 0);
fp->tpa_state[i] = BNX2X_TPA_STOP;
}
bnx2x_set_next_page_sgl(fp);
bnx2x_init_sge_ring_bit_mask(fp);
for (i = 0, ring_prod = 0;
i < MAX_RX_SGE_CNT*NUM_RX_SGE_PAGES; i++) {
if (bnx2x_alloc_rx_sge(bp, fp, ring_prod) < 0) {
BNX2X_ERR(L_49
L_50, i);
BNX2X_ERR(L_51
L_52, j);
bnx2x_free_rx_sge_range(bp,
fp, ring_prod);
bnx2x_free_tpa_pool(bp,
fp, max_agg_queues);
fp->disable_tpa = 1;
ring_prod = 0;
break;
}
ring_prod = NEXT_SGE_IDX(ring_prod);
}
fp->rx_sge_prod = ring_prod;
}
}
for_each_rx_queue(bp, j) {
struct bnx2x_fastpath *fp = &bp->fp[j];
fp->rx_bd_cons = 0;
bnx2x_update_rx_prod(bp, fp, fp->rx_bd_prod, fp->rx_comp_prod,
fp->rx_sge_prod);
if (j != 0)
continue;
if (!CHIP_IS_E2(bp)) {
REG_WR(bp, BAR_USTRORM_INTMEM +
USTORM_MEM_WORKAROUND_ADDRESS_OFFSET(func),
U64_LO(fp->rx_comp_mapping));
REG_WR(bp, BAR_USTRORM_INTMEM +
USTORM_MEM_WORKAROUND_ADDRESS_OFFSET(func) + 4,
U64_HI(fp->rx_comp_mapping));
}
}
}
static void bnx2x_free_tx_skbs(struct bnx2x *bp)
{
int i;
for_each_tx_queue(bp, i) {
struct bnx2x_fastpath *fp = &bp->fp[i];
u16 bd_cons = fp->tx_bd_cons;
u16 sw_prod = fp->tx_pkt_prod;
u16 sw_cons = fp->tx_pkt_cons;
while (sw_cons != sw_prod) {
bd_cons = bnx2x_free_tx_pkt(bp, fp, TX_BD(sw_cons));
sw_cons++;
}
}
}
static void bnx2x_free_rx_bds(struct bnx2x_fastpath *fp)
{
struct bnx2x *bp = fp->bp;
int i;
if (fp->rx_buf_ring == NULL)
return;
for (i = 0; i < NUM_RX_BD; i++) {
struct sw_rx_bd *rx_buf = &fp->rx_buf_ring[i];
struct sk_buff *skb = rx_buf->skb;
if (skb == NULL)
continue;
dma_unmap_single(&bp->pdev->dev,
dma_unmap_addr(rx_buf, mapping),
fp->rx_buf_size, DMA_FROM_DEVICE);
rx_buf->skb = NULL;
dev_kfree_skb(skb);
}
}
static void bnx2x_free_rx_skbs(struct bnx2x *bp)
{
int j;
for_each_rx_queue(bp, j) {
struct bnx2x_fastpath *fp = &bp->fp[j];
bnx2x_free_rx_bds(fp);
if (!fp->disable_tpa)
bnx2x_free_tpa_pool(bp, fp, CHIP_IS_E1(bp) ?
ETH_MAX_AGGREGATION_QUEUES_E1 :
ETH_MAX_AGGREGATION_QUEUES_E1H);
}
}
void bnx2x_free_skbs(struct bnx2x *bp)
{
bnx2x_free_tx_skbs(bp);
bnx2x_free_rx_skbs(bp);
}
void bnx2x_update_max_mf_config(struct bnx2x *bp, u32 value)
{
u32 mf_cfg = bp->mf_config[BP_VN(bp)];
if (value != bnx2x_extract_max_cfg(bp, mf_cfg)) {
mf_cfg &= ~FUNC_MF_CFG_MAX_BW_MASK;
mf_cfg |= (value << FUNC_MF_CFG_MAX_BW_SHIFT)
& FUNC_MF_CFG_MAX_BW_MASK;
bnx2x_fw_command(bp, DRV_MSG_CODE_SET_MF_BW, mf_cfg);
}
}
static void bnx2x_free_msix_irqs(struct bnx2x *bp)
{
int i, offset = 1;
free_irq(bp->msix_table[0].vector, bp->dev);
DP(NETIF_MSG_IFDOWN, L_53,
bp->msix_table[0].vector);
#ifdef F_45
offset++;
#endif
for_each_eth_queue(bp, i) {
DP(NETIF_MSG_IFDOWN, L_54
L_55, i, bp->msix_table[i + offset].vector,
bnx2x_fp(bp, i, state));
free_irq(bp->msix_table[i + offset].vector, &bp->fp[i]);
}
}
void bnx2x_free_irq(struct bnx2x *bp)
{
if (bp->flags & USING_MSIX_FLAG)
bnx2x_free_msix_irqs(bp);
else if (bp->flags & USING_MSI_FLAG)
free_irq(bp->pdev->irq, bp->dev);
else
free_irq(bp->pdev->irq, bp->dev);
}
int bnx2x_enable_msix(struct bnx2x *bp)
{
int msix_vec = 0 , i, rc, req_cnt;
bp->msix_table[msix_vec].entry = msix_vec;
DP(NETIF_MSG_IFUP, L_56,
bp->msix_table[0].entry);
msix_vec++;
#ifdef F_45
bp->msix_table[msix_vec].entry = msix_vec;
DP(NETIF_MSG_IFUP, L_57,
bp->msix_table[msix_vec].entry, bp->msix_table[msix_vec].entry);
msix_vec++;
#endif
for_each_eth_queue(bp, i) {
bp->msix_table[msix_vec].entry = msix_vec;
DP(NETIF_MSG_IFUP, L_58
L_59, msix_vec, msix_vec, i);
msix_vec++;
}
req_cnt = BNX2X_NUM_ETH_QUEUES(bp) + CNIC_CONTEXT_USE + 1;
rc = pci_enable_msix(bp->pdev, &bp->msix_table[0], req_cnt);
if (rc >= BNX2X_MIN_MSIX_VEC_CNT) {
int diff = req_cnt - rc;
DP(NETIF_MSG_IFUP,
L_60, rc);
rc = pci_enable_msix(bp->pdev, &bp->msix_table[0], rc);
if (rc) {
DP(NETIF_MSG_IFUP,
L_61, rc);
return rc;
}
bp->num_queues -= diff;
DP(NETIF_MSG_IFUP, L_62,
bp->num_queues);
} else if (rc) {
if (rc == -ENOMEM)
bp->flags |= DISABLE_MSI_FLAG;
DP(NETIF_MSG_IFUP, L_61, rc);
return rc;
}
bp->flags |= USING_MSIX_FLAG;
return 0;
}
static int bnx2x_req_msix_irqs(struct bnx2x *bp)
{
int i, rc, offset = 1;
rc = request_irq(bp->msix_table[0].vector, bnx2x_msix_sp_int, 0,
bp->dev->name, bp->dev);
if (rc) {
BNX2X_ERR(L_63);
return -EBUSY;
}
#ifdef F_45
offset++;
#endif
for_each_eth_queue(bp, i) {
struct bnx2x_fastpath *fp = &bp->fp[i];
snprintf(fp->name, sizeof(fp->name), L_64,
bp->dev->name, i);
rc = request_irq(bp->msix_table[offset].vector,
bnx2x_msix_fp_int, 0, fp->name, fp);
if (rc) {
BNX2X_ERR(L_65, i, rc);
bnx2x_free_msix_irqs(bp);
return -EBUSY;
}
offset++;
fp->state = BNX2X_FP_STATE_IRQ;
}
i = BNX2X_NUM_ETH_QUEUES(bp);
offset = 1 + CNIC_CONTEXT_USE;
netdev_info(bp->dev, L_66
L_67,
bp->msix_table[0].vector,
0, bp->msix_table[offset].vector,
i - 1, bp->msix_table[offset + i - 1].vector);
return 0;
}
int bnx2x_enable_msi(struct bnx2x *bp)
{
int rc;
rc = pci_enable_msi(bp->pdev);
if (rc) {
DP(NETIF_MSG_IFUP, L_68);
return -1;
}
bp->flags |= USING_MSI_FLAG;
return 0;
}
static int bnx2x_req_irq(struct bnx2x *bp)
{
unsigned long flags;
int rc;
if (bp->flags & USING_MSI_FLAG)
flags = 0;
else
flags = IRQF_SHARED;
rc = request_irq(bp->pdev->irq, bnx2x_interrupt, flags,
bp->dev->name, bp->dev);
if (!rc)
bnx2x_fp(bp, 0, state) = BNX2X_FP_STATE_IRQ;
return rc;
}
static void bnx2x_napi_enable(struct bnx2x *bp)
{
int i;
for_each_napi_queue(bp, i)
napi_enable(&bnx2x_fp(bp, i, napi));
}
static void bnx2x_napi_disable(struct bnx2x *bp)
{
int i;
for_each_napi_queue(bp, i)
napi_disable(&bnx2x_fp(bp, i, napi));
}
void bnx2x_netif_start(struct bnx2x *bp)
{
int intr_sem;
intr_sem = atomic_dec_and_test(&bp->intr_sem);
smp_wmb();
if (intr_sem) {
if (netif_running(bp->dev)) {
bnx2x_napi_enable(bp);
bnx2x_int_enable(bp);
if (bp->state == BNX2X_STATE_OPEN)
netif_tx_wake_all_queues(bp->dev);
}
}
}
void bnx2x_netif_stop(struct bnx2x *bp, int disable_hw)
{
bnx2x_int_disable_sync(bp, disable_hw);
bnx2x_napi_disable(bp);
netif_tx_disable(bp->dev);
}
u16 bnx2x_select_queue(struct net_device *dev, struct sk_buff *skb)
{
#ifdef F_45
struct bnx2x *bp = netdev_priv(dev);
if (NO_FCOE(bp))
return skb_tx_hash(dev, skb);
else {
struct ethhdr *hdr = (struct ethhdr *)skb->data;
u16 ether_type = ntohs(hdr->h_proto);
if (ether_type == ETH_P_8021Q) {
struct vlan_ethhdr *vhdr =
(struct vlan_ethhdr *)skb->data;
ether_type = ntohs(vhdr->h_vlan_encapsulated_proto);
}
if ((ether_type == ETH_P_FCOE) || (ether_type == ETH_P_FIP))
return bnx2x_fcoe(bp, index);
}
#endif
return __skb_tx_hash(dev, skb,
dev->real_num_tx_queues - FCOE_CONTEXT_USE);
}
void bnx2x_set_num_queues(struct bnx2x *bp)
{
switch (bp->multi_mode) {
case ETH_RSS_MODE_DISABLED:
bp->num_queues = 1;
break;
case ETH_RSS_MODE_REGULAR:
bp->num_queues = bnx2x_calc_num_queues(bp);
break;
default:
bp->num_queues = 1;
break;
}
bp->num_queues += NONE_ETH_CONTEXT_USE;
}
#ifdef F_45
static inline void bnx2x_set_fcoe_eth_macs(struct bnx2x *bp)
{
if (!NO_FCOE(bp)) {
if (!IS_MF_SD(bp))
bnx2x_set_fip_eth_mac_addr(bp, 1);
bnx2x_set_all_enode_macs(bp, 1);
bp->flags |= FCOE_MACS_SET;
}
}
#endif
static void bnx2x_release_firmware(struct bnx2x *bp)
{
kfree(bp->init_ops_offsets);
kfree(bp->init_ops);
kfree(bp->init_data);
release_firmware(bp->firmware);
}
static inline int bnx2x_set_real_num_queues(struct bnx2x *bp)
{
int rc, num = bp->num_queues;
#ifdef F_45
if (NO_FCOE(bp))
num -= FCOE_CONTEXT_USE;
#endif
netif_set_real_num_tx_queues(bp->dev, num);
rc = netif_set_real_num_rx_queues(bp->dev, num);
return rc;
}
static inline void bnx2x_set_rx_buf_size(struct bnx2x *bp)
{
int i;
for_each_queue(bp, i) {
struct bnx2x_fastpath *fp = &bp->fp[i];
if (IS_FCOE_IDX(i))
fp->rx_buf_size =
BNX2X_FCOE_MINI_JUMBO_MTU + ETH_OVREHEAD +
BNX2X_RX_ALIGN + IP_HEADER_ALIGNMENT_PADDING;
else
fp->rx_buf_size =
bp->dev->mtu + ETH_OVREHEAD + BNX2X_RX_ALIGN +
IP_HEADER_ALIGNMENT_PADDING;
}
}
int bnx2x_nic_load(struct bnx2x *bp, int load_mode)
{
u32 load_code;
int i, rc;
rc = bnx2x_init_firmware(bp);
if (rc) {
BNX2X_ERR(L_69);
return rc;
}
#ifdef F_11
if (unlikely(bp->panic))
return -EPERM;
#endif
bp->state = BNX2X_STATE_OPENING_WAIT4_LOAD;
bnx2x_acquire_phy_lock(bp);
memset(&bp->last_reported_link, 0, sizeof(bp->last_reported_link));
__set_bit(BNX2X_LINK_REPORT_LINK_DOWN,
&bp->last_reported_link.link_report_flags);
bnx2x_release_phy_lock(bp);
bnx2x_ilt_set_info(bp);
for_each_queue(bp, i)
bnx2x_bz_fp(bp, i);
bnx2x_set_rx_buf_size(bp);
for_each_queue(bp, i)
bnx2x_fp(bp, i, disable_tpa) =
((bp->flags & TPA_ENABLE_FLAG) == 0);
#ifdef F_45
bnx2x_fcoe(bp, disable_tpa) = 1;
#endif
if (bnx2x_alloc_mem(bp))
return -ENOMEM;
rc = bnx2x_set_real_num_queues(bp);
if (rc) {
BNX2X_ERR(L_70);
goto load_error0;
}
bnx2x_napi_enable(bp);
if (!BP_NOMCP(bp)) {
load_code = bnx2x_fw_command(bp, DRV_MSG_CODE_LOAD_REQ, 0);
if (!load_code) {
BNX2X_ERR(L_71);
rc = -EBUSY;
goto load_error1;
}
if (load_code == FW_MSG_CODE_DRV_LOAD_REFUSED) {
rc = -EBUSY;
goto load_error1;
}
} else {
int path = BP_PATH(bp);
int port = BP_PORT(bp);
DP(NETIF_MSG_IFUP, L_72,
path, load_count[path][0], load_count[path][1],
load_count[path][2]);
load_count[path][0]++;
load_count[path][1 + port]++;
DP(NETIF_MSG_IFUP, L_73,
path, load_count[path][0], load_count[path][1],
load_count[path][2]);
if (load_count[path][0] == 1)
load_code = FW_MSG_CODE_DRV_LOAD_COMMON;
else if (load_count[path][1 + port] == 1)
load_code = FW_MSG_CODE_DRV_LOAD_PORT;
else
load_code = FW_MSG_CODE_DRV_LOAD_FUNCTION;
}
if ((load_code == FW_MSG_CODE_DRV_LOAD_COMMON) ||
(load_code == FW_MSG_CODE_DRV_LOAD_COMMON_CHIP) ||
(load_code == FW_MSG_CODE_DRV_LOAD_PORT))
bp->port.pmf = 1;
else
bp->port.pmf = 0;
DP(NETIF_MSG_LINK, L_74, bp->port.pmf);
rc = bnx2x_init_hw(bp, load_code);
if (rc) {
BNX2X_ERR(L_75);
bnx2x_fw_command(bp, DRV_MSG_CODE_LOAD_DONE, 0);
goto load_error2;
}
rc = bnx2x_setup_irqs(bp);
if (rc) {
bnx2x_fw_command(bp, DRV_MSG_CODE_LOAD_DONE, 0);
goto load_error2;
}
bnx2x_nic_init(bp, load_code);
if (((load_code == FW_MSG_CODE_DRV_LOAD_COMMON) ||
(load_code == FW_MSG_CODE_DRV_LOAD_COMMON_CHIP)) &&
(bp->common.shmem2_base))
SHMEM2_WR(bp, dcc_support,
(SHMEM_DCC_SUPPORT_DISABLE_ENABLE_PF_TLV |
SHMEM_DCC_SUPPORT_BANDWIDTH_ALLOCATION_TLV));
if (!BP_NOMCP(bp)) {
load_code = bnx2x_fw_command(bp, DRV_MSG_CODE_LOAD_DONE, 0);
if (!load_code) {
BNX2X_ERR(L_71);
rc = -EBUSY;
goto load_error3;
}
}
bnx2x_dcbx_init(bp);
bp->state = BNX2X_STATE_OPENING_WAIT4_PORT;
rc = bnx2x_func_start(bp);
if (rc) {
BNX2X_ERR(L_76);
#ifndef F_11
goto load_error3;
#else
bp->panic = 1;
return -EBUSY;
#endif
}
rc = bnx2x_setup_client(bp, &bp->fp[0], 1 );
if (rc) {
BNX2X_ERR(L_77);
#ifndef F_11
goto load_error3;
#else
bp->panic = 1;
return -EBUSY;
#endif
}
if (!CHIP_IS_E1(bp) &&
(bp->mf_config[BP_VN(bp)] & FUNC_MF_CFG_FUNC_DISABLED)) {
DP(NETIF_MSG_IFUP, L_78);
bp->flags |= MF_FUNC_DIS;
}
#ifdef F_45
REG_WR(bp, TM_REG_EN_LINEAR0_TIMER + BP_PORT(bp)*4, 1);
#endif
for_each_nondefault_queue(bp, i) {
rc = bnx2x_setup_client(bp, &bp->fp[i], 0);
if (rc)
#ifdef F_45
goto load_error4;
#else
goto load_error3;
#endif
}
bp->state = BNX2X_STATE_OPEN;
#ifdef F_45
bnx2x_set_fcoe_eth_macs(bp);
#endif
bnx2x_set_eth_mac(bp, 1);
if (CHIP_IS_E1(bp))
bnx2x_invalidate_e1_mc_list(bp);
else
bnx2x_invalidate_e1h_mc_list(bp);
bnx2x_invalidate_uc_list(bp);
if (bp->pending_max) {
bnx2x_update_max_mf_config(bp, bp->pending_max);
bp->pending_max = 0;
}
if (bp->port.pmf)
bnx2x_initial_phy_init(bp, load_mode);
bnx2x_set_rx_mode(bp->dev);
switch (load_mode) {
case LOAD_NORMAL:
netif_tx_wake_all_queues(bp->dev);
break;
case LOAD_OPEN:
netif_tx_start_all_queues(bp->dev);
smp_mb__after_clear_bit();
break;
case LOAD_DIAG:
bp->state = BNX2X_STATE_DIAG;
break;
default:
break;
}
if (!bp->port.pmf)
bnx2x__link_status_update(bp);
mod_timer(&bp->timer, jiffies + bp->current_interval);
#ifdef F_45
bnx2x_setup_cnic_irq_info(bp);
if (bp->state == BNX2X_STATE_OPEN)
bnx2x_cnic_notify(bp, CNIC_CTL_START_CMD);
#endif
bnx2x_inc_load_cnt(bp);
bnx2x_release_firmware(bp);
return 0;
#ifdef F_45
load_error4:
REG_WR(bp, TM_REG_EN_LINEAR0_TIMER + BP_PORT(bp)*4, 0);
#endif
load_error3:
bnx2x_int_disable_sync(bp, 1);
bnx2x_free_skbs(bp);
for_each_rx_queue(bp, i)
bnx2x_free_rx_sge_range(bp, bp->fp + i, NUM_RX_SGE);
bnx2x_free_irq(bp);
load_error2:
if (!BP_NOMCP(bp)) {
bnx2x_fw_command(bp, DRV_MSG_CODE_UNLOAD_REQ_WOL_MCP, 0);
bnx2x_fw_command(bp, DRV_MSG_CODE_UNLOAD_DONE, 0);
}
bp->port.pmf = 0;
load_error1:
bnx2x_napi_disable(bp);
load_error0:
bnx2x_free_mem(bp);
bnx2x_release_firmware(bp);
return rc;
}
int bnx2x_nic_unload(struct bnx2x *bp, int unload_mode)
{
int i;
if (bp->state == BNX2X_STATE_CLOSED) {
bp->recovery_state = BNX2X_RECOVERY_DONE;
bp->is_leader = 0;
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_RESERVED_08);
smp_wmb();
return -EINVAL;
}
#ifdef F_45
bnx2x_cnic_notify(bp, CNIC_CTL_STOP_CMD);
#endif
bp->state = BNX2X_STATE_CLOSING_WAIT4_HALT;
bp->rx_mode = BNX2X_RX_MODE_NONE;
bnx2x_set_storm_rx_mode(bp);
bnx2x_tx_disable(bp);
del_timer_sync(&bp->timer);
SHMEM_WR(bp, func_mb[BP_FW_MB_IDX(bp)].drv_pulse_mb,
(DRV_PULSE_ALWAYS_ALIVE | bp->fw_drv_pulse_wr_seq));
bnx2x_stats_handle(bp, STATS_EVENT_STOP);
if (unload_mode != UNLOAD_RECOVERY)
bnx2x_chip_cleanup(bp, unload_mode);
else {
bnx2x_netif_stop(bp, 1);
bnx2x_free_irq(bp);
}
bp->port.pmf = 0;
bnx2x_free_skbs(bp);
for_each_rx_queue(bp, i)
bnx2x_free_rx_sge_range(bp, bp->fp + i, NUM_RX_SGE);
bnx2x_free_mem(bp);
bp->state = BNX2X_STATE_CLOSED;
if ((!bnx2x_dec_load_cnt(bp)) && (!bnx2x_chk_parity_attn(bp)) &&
bnx2x_reset_is_done(bp))
bnx2x_disable_close_the_gate(bp);
if (unload_mode == UNLOAD_RECOVERY)
bp->fw_seq = 0;
return 0;
}
int bnx2x_set_power_state(struct bnx2x *bp, pci_power_t state)
{
u16 pmcsr;
if (!bp->pm_cap) {
DP(NETIF_MSG_HW, L_79);
return 0;
}
pci_read_config_word(bp->pdev, bp->pm_cap + PCI_PM_CTRL, &pmcsr);
switch (state) {
case PCI_D0:
pci_write_config_word(bp->pdev, bp->pm_cap + PCI_PM_CTRL,
((pmcsr & ~PCI_PM_CTRL_STATE_MASK) |
PCI_PM_CTRL_PME_STATUS));
if (pmcsr & PCI_PM_CTRL_STATE_MASK)
msleep(20);
break;
case PCI_D3hot:
if (atomic_read(&bp->pdev->enable_cnt) != 1)
return 0;
if (CHIP_REV_IS_SLOW(bp))
return 0;
pmcsr &= ~PCI_PM_CTRL_STATE_MASK;
pmcsr |= 3;
if (bp->wol)
pmcsr |= PCI_PM_CTRL_PME_ENABLE;
pci_write_config_word(bp->pdev, bp->pm_cap + PCI_PM_CTRL,
pmcsr);
break;
default:
return -EINVAL;
}
return 0;
}
int bnx2x_poll(struct napi_struct *napi, int budget)
{
int work_done = 0;
struct bnx2x_fastpath *fp = container_of(napi, struct bnx2x_fastpath,
napi);
struct bnx2x *bp = fp->bp;
while (1) {
#ifdef F_11
if (unlikely(bp->panic)) {
napi_complete(napi);
return 0;
}
#endif
if (bnx2x_has_tx_work(fp))
bnx2x_tx_int(fp);
if (bnx2x_has_rx_work(fp)) {
work_done += bnx2x_rx_int(fp, budget - work_done);
if (work_done >= budget)
break;
}
if (!(bnx2x_has_rx_work(fp) || bnx2x_has_tx_work(fp))) {
#ifdef F_45
if (IS_FCOE_FP(fp)) {
napi_complete(napi);
break;
}
#endif
bnx2x_update_fpsb_idx(fp);
rmb();
if (!(bnx2x_has_rx_work(fp) || bnx2x_has_tx_work(fp))) {
napi_complete(napi);
DP(NETIF_MSG_HW,
L_80, fp->fp_hc_idx);
bnx2x_ack_sb(bp, fp->igu_sb_id, USTORM_ID,
le16_to_cpu(fp->fp_hc_idx),
IGU_INT_ENABLE, 1);
break;
}
}
}
return work_done;
}
static noinline u16 bnx2x_tx_split(struct bnx2x *bp,
struct bnx2x_fastpath *fp,
struct sw_tx_bd *tx_buf,
struct eth_tx_start_bd **tx_bd, u16 hlen,
u16 bd_prod, int nbd)
{
struct eth_tx_start_bd *h_tx_bd = *tx_bd;
struct eth_tx_bd *d_tx_bd;
dma_addr_t mapping;
int old_len = le16_to_cpu(h_tx_bd->nbytes);
h_tx_bd->nbd = cpu_to_le16(nbd);
h_tx_bd->nbytes = cpu_to_le16(hlen);
DP(NETIF_MSG_TX_QUEUED, L_81
L_82, h_tx_bd->nbytes, h_tx_bd->addr_hi,
h_tx_bd->addr_lo, h_tx_bd->nbd);
bd_prod = TX_BD(NEXT_TX_IDX(bd_prod));
d_tx_bd = &fp->tx_desc_ring[bd_prod].reg_bd;
mapping = HILO_U64(le32_to_cpu(h_tx_bd->addr_hi),
le32_to_cpu(h_tx_bd->addr_lo)) + hlen;
d_tx_bd->addr_hi = cpu_to_le32(U64_HI(mapping));
d_tx_bd->addr_lo = cpu_to_le32(U64_LO(mapping));
d_tx_bd->nbytes = cpu_to_le16(old_len - hlen);
tx_buf->flags |= BNX2X_TSO_SPLIT_BD;
DP(NETIF_MSG_TX_QUEUED,
L_83,
d_tx_bd->nbytes, d_tx_bd->addr_hi, d_tx_bd->addr_lo);
*tx_bd = (struct eth_tx_start_bd *)d_tx_bd;
return bd_prod;
}
static inline u16 bnx2x_csum_fix(unsigned char *t_header, u16 csum, s8 fix)
{
if (fix > 0)
csum = (u16) ~csum_fold(csum_sub(csum,
csum_partial(t_header - fix, fix, 0)));
else if (fix < 0)
csum = (u16) ~csum_fold(csum_add(csum,
csum_partial(t_header, -fix, 0)));
return swab16(csum);
}
static inline u32 bnx2x_xmit_type(struct bnx2x *bp, struct sk_buff *skb)
{
u32 rc;
if (skb->ip_summed != CHECKSUM_PARTIAL)
rc = XMIT_PLAIN;
else {
if (vlan_get_protocol(skb) == htons(ETH_P_IPV6)) {
rc = XMIT_CSUM_V6;
if (ipv6_hdr(skb)->nexthdr == IPPROTO_TCP)
rc |= XMIT_CSUM_TCP;
} else {
rc = XMIT_CSUM_V4;
if (ip_hdr(skb)->protocol == IPPROTO_TCP)
rc |= XMIT_CSUM_TCP;
}
}
if (skb_is_gso_v6(skb))
rc |= XMIT_GSO_V6 | XMIT_CSUM_TCP | XMIT_CSUM_V6;
else if (skb_is_gso(skb))
rc |= XMIT_GSO_V4 | XMIT_CSUM_V4 | XMIT_CSUM_TCP;
return rc;
}
#if ( V_34 >= V_92 - 3 )
static int bnx2x_pkt_req_lin(struct bnx2x *bp, struct sk_buff *skb,
u32 xmit_type)
{
int to_copy = 0;
int hlen = 0;
int first_bd_sz = 0;
if (skb_shinfo(skb)->nr_frags >= (MAX_FETCH_BD - 3)) {
if (xmit_type & XMIT_GSO) {
unsigned short lso_mss = skb_shinfo(skb)->gso_size;
int wnd_size = MAX_FETCH_BD - 3;
int num_wnds = skb_shinfo(skb)->nr_frags - wnd_size;
int wnd_idx = 0;
int frag_idx = 0;
u32 wnd_sum = 0;
hlen = (int)(skb_transport_header(skb) - skb->data) +
tcp_hdrlen(skb);
first_bd_sz = skb_headlen(skb) - hlen;
wnd_sum = first_bd_sz;
for (frag_idx = 0; frag_idx < wnd_size - 1; frag_idx++)
wnd_sum +=
skb_shinfo(skb)->frags[frag_idx].size;
if (first_bd_sz > 0) {
if (unlikely(wnd_sum < lso_mss)) {
to_copy = 1;
goto exit_lbl;
}
wnd_sum -= first_bd_sz;
}
for (wnd_idx = 0; wnd_idx <= num_wnds; wnd_idx++) {
wnd_sum +=
skb_shinfo(skb)->frags[wnd_idx + wnd_size - 1].size;
if (unlikely(wnd_sum < lso_mss)) {
to_copy = 1;
break;
}
wnd_sum -=
skb_shinfo(skb)->frags[wnd_idx].size;
}
} else {
to_copy = 1;
}
}
exit_lbl:
if (unlikely(to_copy))
DP(NETIF_MSG_TX_QUEUED,
L_84
L_85,
(xmit_type & XMIT_GSO) ? L_86 : L_87,
skb_shinfo(skb)->nr_frags, hlen, first_bd_sz);
return to_copy;
}
#endif
static inline void bnx2x_set_pbd_gso_e2(struct sk_buff *skb, u32 *parsing_data,
u32 xmit_type)
{
*parsing_data |= (skb_shinfo(skb)->gso_size <<
ETH_TX_PARSE_BD_E2_LSO_MSS_SHIFT) &
ETH_TX_PARSE_BD_E2_LSO_MSS;
if ((xmit_type & XMIT_GSO_V6) &&
(ipv6_hdr(skb)->nexthdr == NEXTHDR_IPV6))
*parsing_data |= ETH_TX_PARSE_BD_E2_IPV6_WITH_EXT_HDR;
}
static inline void bnx2x_set_pbd_gso(struct sk_buff *skb,
struct eth_tx_parse_bd_e1x *pbd,
u32 xmit_type)
{
pbd->lso_mss = cpu_to_le16(skb_shinfo(skb)->gso_size);
pbd->tcp_send_seq = swab32(tcp_hdr(skb)->seq);
pbd->tcp_flags = pbd_tcp_flags(skb);
if (xmit_type & XMIT_GSO_V4) {
pbd->ip_id = swab16(ip_hdr(skb)->id);
pbd->tcp_pseudo_csum =
swab16(~csum_tcpudp_magic(ip_hdr(skb)->saddr,
ip_hdr(skb)->daddr,
0, IPPROTO_TCP, 0));
} else
pbd->tcp_pseudo_csum =
swab16(~csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
&ipv6_hdr(skb)->daddr,
0, IPPROTO_TCP, 0));
pbd->global_data |= ETH_TX_PARSE_BD_E1X_PSEUDO_CS_WITHOUT_LEN;
}
static inline u8 bnx2x_set_pbd_csum_e2(struct bnx2x *bp, struct sk_buff *skb,
u32 *parsing_data, u32 xmit_type)
{
*parsing_data |=
((((u8 *)skb_transport_header(skb) - skb->data) >> 1) <<
ETH_TX_PARSE_BD_E2_TCP_HDR_START_OFFSET_W_SHIFT) &
ETH_TX_PARSE_BD_E2_TCP_HDR_START_OFFSET_W;
if (xmit_type & XMIT_CSUM_TCP) {
*parsing_data |= ((tcp_hdrlen(skb) / 4) <<
ETH_TX_PARSE_BD_E2_TCP_HDR_LENGTH_DW_SHIFT) &
ETH_TX_PARSE_BD_E2_TCP_HDR_LENGTH_DW;
return skb_transport_header(skb) + tcp_hdrlen(skb) - skb->data;
} else
return skb_transport_header(skb) +
sizeof(struct udphdr) - skb->data;
}
static inline u8 bnx2x_set_pbd_csum(struct bnx2x *bp, struct sk_buff *skb,
struct eth_tx_parse_bd_e1x *pbd,
u32 xmit_type)
{
u8 hlen = (skb_network_header(skb) - skb->data) >> 1;
pbd->global_data =
(hlen | ((skb->protocol == cpu_to_be16(ETH_P_8021Q)) <<
ETH_TX_PARSE_BD_E1X_LLC_SNAP_EN_SHIFT));
pbd->ip_hlen_w = (skb_transport_header(skb) -
skb_network_header(skb)) >> 1;
hlen += pbd->ip_hlen_w;
if (xmit_type & XMIT_CSUM_TCP)
hlen += tcp_hdrlen(skb) / 2;
else
hlen += sizeof(struct udphdr) / 2;
pbd->total_hlen_w = cpu_to_le16(hlen);
hlen = hlen*2;
if (xmit_type & XMIT_CSUM_TCP) {
pbd->tcp_pseudo_csum = swab16(tcp_hdr(skb)->check);
} else {
s8 fix = SKB_CS_OFF(skb);
DP(NETIF_MSG_TX_QUEUED,
L_88,
le16_to_cpu(pbd->total_hlen_w), fix, SKB_CS(skb));
pbd->tcp_pseudo_csum =
bnx2x_csum_fix(skb_transport_header(skb),
SKB_CS(skb), fix);
DP(NETIF_MSG_TX_QUEUED, L_89,
pbd->tcp_pseudo_csum);
}
return hlen;
}
netdev_tx_t bnx2x_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct bnx2x *bp = netdev_priv(dev);
struct bnx2x_fastpath *fp;
struct netdev_queue *txq;
struct sw_tx_bd *tx_buf;
struct eth_tx_start_bd *tx_start_bd;
struct eth_tx_bd *tx_data_bd, *total_pkt_bd = NULL;
struct eth_tx_parse_bd_e1x *pbd_e1x = NULL;
struct eth_tx_parse_bd_e2 *pbd_e2 = NULL;
u32 pbd_e2_parsing_data = 0;
u16 pkt_prod, bd_prod;
int nbd, fp_index;
dma_addr_t mapping;
u32 xmit_type = bnx2x_xmit_type(bp, skb);
int i;
u8 hlen = 0;
__le16 pkt_size = 0;
struct ethhdr *eth;
u8 mac_type = UNICAST_ADDRESS;
#ifdef F_11
if (unlikely(bp->panic))
return NETDEV_TX_BUSY;
#endif
fp_index = skb_get_queue_mapping(skb);
txq = netdev_get_tx_queue(dev, fp_index);
fp = &bp->fp[fp_index];
if (unlikely(bnx2x_tx_avail(fp) < (skb_shinfo(skb)->nr_frags + 3))) {
fp->eth_q_stats.driver_xoff++;
netif_tx_stop_queue(txq);
BNX2X_ERR(L_90);
return NETDEV_TX_BUSY;
}
DP(NETIF_MSG_TX_QUEUED, L_91
L_92,
fp_index, skb->ip_summed, skb->protocol, ipv6_hdr(skb)->nexthdr,
ip_hdr(skb)->protocol, skb_shinfo(skb)->gso_type, xmit_type);
eth = (struct ethhdr *)skb->data;
if (unlikely(is_multicast_ether_addr(eth->h_dest))) {
if (is_broadcast_ether_addr(eth->h_dest))
mac_type = BROADCAST_ADDRESS;
else
mac_type = MULTICAST_ADDRESS;
}
#if ( V_34 >= V_92 - 3 )
if (bnx2x_pkt_req_lin(bp, skb, xmit_type)) {
bp->lin_cnt++;
if (skb_linearize(skb) != 0) {
DP(NETIF_MSG_TX_QUEUED, L_93
L_94);
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
}
#endif
pkt_prod = fp->tx_pkt_prod++;
bd_prod = TX_BD(fp->tx_bd_prod);
tx_buf = &fp->tx_buf_ring[TX_BD(pkt_prod)];
tx_start_bd = &fp->tx_desc_ring[bd_prod].start_bd;
tx_start_bd->bd_flags.as_bitfield = ETH_TX_BD_FLAGS_START_BD;
SET_FLAG(tx_start_bd->general_data, ETH_TX_START_BD_ETH_ADDR_TYPE,
mac_type);
SET_FLAG(tx_start_bd->general_data, ETH_TX_START_BD_HDR_NBDS, 1);
tx_buf->first_bd = fp->tx_bd_prod;
tx_buf->skb = skb;
tx_buf->flags = 0;
DP(NETIF_MSG_TX_QUEUED,
L_95,
pkt_prod, tx_buf, fp->tx_pkt_prod, bd_prod, tx_start_bd);
if (vlan_tx_tag_present(skb)) {
tx_start_bd->vlan_or_ethertype =
cpu_to_le16(vlan_tx_tag_get(skb));
tx_start_bd->bd_flags.as_bitfield |=
(X_ETH_OUTBAND_VLAN << ETH_TX_BD_FLAGS_VLAN_MODE_SHIFT);
} else
tx_start_bd->vlan_or_ethertype = cpu_to_le16(pkt_prod);
bd_prod = TX_BD(NEXT_TX_IDX(bd_prod));
if (xmit_type & XMIT_CSUM) {
tx_start_bd->bd_flags.as_bitfield |= ETH_TX_BD_FLAGS_L4_CSUM;
if (xmit_type & XMIT_CSUM_V4)
tx_start_bd->bd_flags.as_bitfield |=
ETH_TX_BD_FLAGS_IP_CSUM;
else
tx_start_bd->bd_flags.as_bitfield |=
ETH_TX_BD_FLAGS_IPV6;
if (!(xmit_type & XMIT_CSUM_TCP))
tx_start_bd->bd_flags.as_bitfield |=
ETH_TX_BD_FLAGS_IS_UDP;
}
if (CHIP_IS_E2(bp)) {
pbd_e2 = &fp->tx_desc_ring[bd_prod].parse_bd_e2;
memset(pbd_e2, 0, sizeof(struct eth_tx_parse_bd_e2));
if (xmit_type & XMIT_CSUM)
hlen = bnx2x_set_pbd_csum_e2(bp, skb,
&pbd_e2_parsing_data,
xmit_type);
} else {
pbd_e1x = &fp->tx_desc_ring[bd_prod].parse_bd_e1x;
memset(pbd_e1x, 0, sizeof(struct eth_tx_parse_bd_e1x));
if (xmit_type & XMIT_CSUM)
hlen = bnx2x_set_pbd_csum(bp, skb, pbd_e1x, xmit_type);
}
mapping = dma_map_single(&bp->pdev->dev, skb->data,
skb_headlen(skb), DMA_TO_DEVICE);
tx_start_bd->addr_hi = cpu_to_le32(U64_HI(mapping));
tx_start_bd->addr_lo = cpu_to_le32(U64_LO(mapping));
nbd = skb_shinfo(skb)->nr_frags + 2;
tx_start_bd->nbd = cpu_to_le16(nbd);
tx_start_bd->nbytes = cpu_to_le16(skb_headlen(skb));
pkt_size = tx_start_bd->nbytes;
DP(NETIF_MSG_TX_QUEUED, L_96
L_97,
tx_start_bd, tx_start_bd->addr_hi, tx_start_bd->addr_lo,
le16_to_cpu(tx_start_bd->nbd), le16_to_cpu(tx_start_bd->nbytes),
tx_start_bd->bd_flags.as_bitfield,
le16_to_cpu(tx_start_bd->vlan_or_ethertype));
if (xmit_type & XMIT_GSO) {
DP(NETIF_MSG_TX_QUEUED,
L_98,
skb->len, hlen, skb_headlen(skb),
skb_shinfo(skb)->gso_size);
tx_start_bd->bd_flags.as_bitfield |= ETH_TX_BD_FLAGS_SW_LSO;
if (unlikely(skb_headlen(skb) > hlen))
bd_prod = bnx2x_tx_split(bp, fp, tx_buf, &tx_start_bd,
hlen, bd_prod, ++nbd);
if (CHIP_IS_E2(bp))
bnx2x_set_pbd_gso_e2(skb, &pbd_e2_parsing_data,
xmit_type);
else
bnx2x_set_pbd_gso(skb, pbd_e1x, xmit_type);
}
if (pbd_e2_parsing_data)
pbd_e2->parsing_data = cpu_to_le32(pbd_e2_parsing_data);
tx_data_bd = (struct eth_tx_bd *)tx_start_bd;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
bd_prod = TX_BD(NEXT_TX_IDX(bd_prod));
tx_data_bd = &fp->tx_desc_ring[bd_prod].reg_bd;
if (total_pkt_bd == NULL)
total_pkt_bd = &fp->tx_desc_ring[bd_prod].reg_bd;
mapping = dma_map_page(&bp->pdev->dev, frag->page,
frag->page_offset,
frag->size, DMA_TO_DEVICE);
tx_data_bd->addr_hi = cpu_to_le32(U64_HI(mapping));
tx_data_bd->addr_lo = cpu_to_le32(U64_LO(mapping));
tx_data_bd->nbytes = cpu_to_le16(frag->size);
le16_add_cpu(&pkt_size, frag->size);
DP(NETIF_MSG_TX_QUEUED,
L_99,
i, tx_data_bd, tx_data_bd->addr_hi, tx_data_bd->addr_lo,
le16_to_cpu(tx_data_bd->nbytes));
}
DP(NETIF_MSG_TX_QUEUED, L_100, tx_data_bd);
bd_prod = TX_BD(NEXT_TX_IDX(bd_prod));
if (TX_BD_POFF(bd_prod) < nbd)
nbd++;
if (total_pkt_bd != NULL)
total_pkt_bd->total_pkt_bytes = pkt_size;
if (pbd_e1x)
DP(NETIF_MSG_TX_QUEUED,
L_101
L_102,
pbd_e1x, pbd_e1x->global_data, pbd_e1x->ip_hlen_w,
pbd_e1x->ip_id, pbd_e1x->lso_mss, pbd_e1x->tcp_flags,
pbd_e1x->tcp_pseudo_csum, pbd_e1x->tcp_send_seq,
le16_to_cpu(pbd_e1x->total_hlen_w));
if (pbd_e2)
DP(NETIF_MSG_TX_QUEUED,
L_103,
pbd_e2, pbd_e2->dst_mac_addr_hi, pbd_e2->dst_mac_addr_mid,
pbd_e2->dst_mac_addr_lo, pbd_e2->src_mac_addr_hi,
pbd_e2->src_mac_addr_mid, pbd_e2->src_mac_addr_lo,
pbd_e2->parsing_data);
DP(NETIF_MSG_TX_QUEUED, L_104, nbd, bd_prod);
wmb();
fp->tx_db.data.prod += nbd;
barrier();
DOORBELL(bp, fp->cid, fp->tx_db.raw);
mmiowb();
fp->tx_bd_prod += nbd;
if (unlikely(bnx2x_tx_avail(fp) < MAX_SKB_FRAGS + 3)) {
netif_tx_stop_queue(txq);
smp_mb();
fp->eth_q_stats.driver_xoff++;
if (bnx2x_tx_avail(fp) >= MAX_SKB_FRAGS + 3)
netif_tx_wake_queue(txq);
}
fp->tx_pkt++;
return NETDEV_TX_OK;
}
int bnx2x_change_mac_addr(struct net_device *dev, void *p)
{
struct sockaddr *addr = p;
struct bnx2x *bp = netdev_priv(dev);
if (!is_valid_ether_addr((u8 *)(addr->sa_data)))
return -EINVAL;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
if (netif_running(dev))
bnx2x_set_eth_mac(bp, 1);
return 0;
}
static void bnx2x_free_fp_mem_at(struct bnx2x *bp, int fp_index)
{
union host_hc_status_block *sb = &bnx2x_fp(bp, fp_index, status_blk);
struct bnx2x_fastpath *fp = &bp->fp[fp_index];
#ifdef F_45
if (IS_FCOE_IDX(fp_index)) {
memset(sb, 0, sizeof(union host_hc_status_block));
fp->status_blk_mapping = 0;
} else {
#endif
if (CHIP_IS_E2(bp))
BNX2X_PCI_FREE(sb->e2_sb,
bnx2x_fp(bp, fp_index,
status_blk_mapping),
sizeof(struct host_hc_status_block_e2));
else
BNX2X_PCI_FREE(sb->e1x_sb,
bnx2x_fp(bp, fp_index,
status_blk_mapping),
sizeof(struct host_hc_status_block_e1x));
#ifdef F_45
}
#endif
if (!skip_rx_queue(bp, fp_index)) {
bnx2x_free_rx_bds(fp);
BNX2X_FREE(bnx2x_fp(bp, fp_index, rx_buf_ring));
BNX2X_PCI_FREE(bnx2x_fp(bp, fp_index, rx_desc_ring),
bnx2x_fp(bp, fp_index, rx_desc_mapping),
sizeof(struct eth_rx_bd) * NUM_RX_BD);
BNX2X_PCI_FREE(bnx2x_fp(bp, fp_index, rx_comp_ring),
bnx2x_fp(bp, fp_index, rx_comp_mapping),
sizeof(struct eth_fast_path_rx_cqe) *
NUM_RCQ_BD);
BNX2X_FREE(bnx2x_fp(bp, fp_index, rx_page_ring));
BNX2X_PCI_FREE(bnx2x_fp(bp, fp_index, rx_sge_ring),
bnx2x_fp(bp, fp_index, rx_sge_mapping),
BCM_PAGE_SIZE * NUM_RX_SGE_PAGES);
}
if (!skip_tx_queue(bp, fp_index)) {
BNX2X_FREE(bnx2x_fp(bp, fp_index, tx_buf_ring));
BNX2X_PCI_FREE(bnx2x_fp(bp, fp_index, tx_desc_ring),
bnx2x_fp(bp, fp_index, tx_desc_mapping),
sizeof(union eth_tx_bd_types) * NUM_TX_BD);
}
}
void bnx2x_free_fp_mem(struct bnx2x *bp)
{
int i;
for_each_queue(bp, i)
bnx2x_free_fp_mem_at(bp, i);
}
static inline void set_sb_shortcuts(struct bnx2x *bp, int index)
{
union host_hc_status_block status_blk = bnx2x_fp(bp, index, status_blk);
if (CHIP_IS_E2(bp)) {
bnx2x_fp(bp, index, sb_index_values) =
(__le16 *)status_blk.e2_sb->sb.index_values;
bnx2x_fp(bp, index, sb_running_index) =
(__le16 *)status_blk.e2_sb->sb.running_index;
} else {
bnx2x_fp(bp, index, sb_index_values) =
(__le16 *)status_blk.e1x_sb->sb.index_values;
bnx2x_fp(bp, index, sb_running_index) =
(__le16 *)status_blk.e1x_sb->sb.running_index;
}
}
static int bnx2x_alloc_fp_mem_at(struct bnx2x *bp, int index)
{
union host_hc_status_block *sb;
struct bnx2x_fastpath *fp = &bp->fp[index];
int ring_size = 0;
int rx_ring_size = bp->rx_ring_size ? bp->rx_ring_size :
MAX_RX_AVAIL/bp->num_queues;
rx_ring_size = max_t(int, fp->disable_tpa ? MIN_RX_SIZE_NONTPA :
MIN_RX_SIZE_TPA,
rx_ring_size);
bnx2x_fp(bp, index, bp) = bp;
bnx2x_fp(bp, index, index) = index;
sb = &bnx2x_fp(bp, index, status_blk);
#ifdef F_45
if (!IS_FCOE_IDX(index)) {
#endif
if (CHIP_IS_E2(bp))
BNX2X_PCI_ALLOC(sb->e2_sb,
&bnx2x_fp(bp, index, status_blk_mapping),
sizeof(struct host_hc_status_block_e2));
else
BNX2X_PCI_ALLOC(sb->e1x_sb,
&bnx2x_fp(bp, index, status_blk_mapping),
sizeof(struct host_hc_status_block_e1x));
#ifdef F_45
}
#endif
set_sb_shortcuts(bp, index);
if (!skip_tx_queue(bp, index)) {
BNX2X_ALLOC(bnx2x_fp(bp, index, tx_buf_ring),
sizeof(struct sw_tx_bd) * NUM_TX_BD);
BNX2X_PCI_ALLOC(bnx2x_fp(bp, index, tx_desc_ring),
&bnx2x_fp(bp, index, tx_desc_mapping),
sizeof(union eth_tx_bd_types) * NUM_TX_BD);
}
if (!skip_rx_queue(bp, index)) {
BNX2X_ALLOC(bnx2x_fp(bp, index, rx_buf_ring),
sizeof(struct sw_rx_bd) * NUM_RX_BD);
BNX2X_PCI_ALLOC(bnx2x_fp(bp, index, rx_desc_ring),
&bnx2x_fp(bp, index, rx_desc_mapping),
sizeof(struct eth_rx_bd) * NUM_RX_BD);
BNX2X_PCI_ALLOC(bnx2x_fp(bp, index, rx_comp_ring),
&bnx2x_fp(bp, index, rx_comp_mapping),
sizeof(struct eth_fast_path_rx_cqe) *
NUM_RCQ_BD);
BNX2X_ALLOC(bnx2x_fp(bp, index, rx_page_ring),
sizeof(struct sw_rx_page) * NUM_RX_SGE);
BNX2X_PCI_ALLOC(bnx2x_fp(bp, index, rx_sge_ring),
&bnx2x_fp(bp, index, rx_sge_mapping),
BCM_PAGE_SIZE * NUM_RX_SGE_PAGES);
bnx2x_set_next_page_rx_bd(fp);
bnx2x_set_next_page_rx_cq(fp);
ring_size = bnx2x_alloc_rx_bds(fp, rx_ring_size);
if (ring_size < rx_ring_size)
goto alloc_mem_err;
}
return 0;
alloc_mem_err:
BNX2X_ERR(L_105,
index, ring_size);
if (ring_size < (fp->disable_tpa ?
MIN_RX_SIZE_NONTPA : MIN_RX_SIZE_TPA)) {
bnx2x_free_fp_mem_at(bp, index);
return -ENOMEM;
}
return 0;
}
int bnx2x_alloc_fp_mem(struct bnx2x *bp)
{
int i;
if (bnx2x_alloc_fp_mem_at(bp, 0))
return -ENOMEM;
#ifdef F_45
if (bnx2x_alloc_fp_mem_at(bp, FCOE_IDX))
return -ENOMEM;
#endif
for_each_nondefault_eth_queue(bp, i)
if (bnx2x_alloc_fp_mem_at(bp, i))
break;
if (i != BNX2X_NUM_ETH_QUEUES(bp)) {
int delta = BNX2X_NUM_ETH_QUEUES(bp) - i;
WARN_ON(delta < 0);
#ifdef F_45
bnx2x_move_fp(bp, FCOE_IDX, FCOE_IDX - delta);
#endif
bp->num_queues -= delta;
BNX2X_ERR(L_106,
bp->num_queues + delta, bp->num_queues);
}
return 0;
}
static int bnx2x_setup_irqs(struct bnx2x *bp)
{
int rc = 0;
if (bp->flags & USING_MSIX_FLAG) {
rc = bnx2x_req_msix_irqs(bp);
if (rc)
return rc;
} else {
bnx2x_ack_int(bp);
rc = bnx2x_req_irq(bp);
if (rc) {
BNX2X_ERR(L_107, rc);
return rc;
}
if (bp->flags & USING_MSI_FLAG) {
bp->dev->irq = bp->pdev->irq;
netdev_info(bp->dev, L_108,
bp->pdev->irq);
}
}
return 0;
}
void bnx2x_free_mem_bp(struct bnx2x *bp)
{
kfree(bp->fp);
kfree(bp->msix_table);
kfree(bp->ilt);
}
int __devinit bnx2x_alloc_mem_bp(struct bnx2x *bp)
{
struct bnx2x_fastpath *fp;
struct msix_entry *tbl;
struct bnx2x_ilt *ilt;
fp = kzalloc(L2_FP_COUNT(bp->l2_cid_count)*sizeof(*fp), GFP_KERNEL);
if (!fp)
goto alloc_err;
bp->fp = fp;
tbl = kzalloc((FP_SB_COUNT(bp->l2_cid_count) + 1) * sizeof(*tbl),
GFP_KERNEL);
if (!tbl)
goto alloc_err;
bp->msix_table = tbl;
ilt = kzalloc(sizeof(*ilt), GFP_KERNEL);
if (!ilt)
goto alloc_err;
bp->ilt = ilt;
return 0;
alloc_err:
bnx2x_free_mem_bp(bp);
return -ENOMEM;
}
static int bnx2x_reload_if_running(struct net_device *dev)
{
struct bnx2x *bp = netdev_priv(dev);
if (unlikely(!netif_running(dev)))
return 0;
bnx2x_nic_unload(bp, UNLOAD_NORMAL);
return bnx2x_nic_load(bp, LOAD_NORMAL);
}
int bnx2x_change_mtu(struct net_device *dev, int new_mtu)
{
struct bnx2x *bp = netdev_priv(dev);
if (bp->recovery_state != BNX2X_RECOVERY_DONE) {
printk(KERN_ERR L_109);
return -EAGAIN;
}
if ((new_mtu > ETH_MAX_JUMBO_PACKET_SIZE) ||
((new_mtu + ETH_HLEN) < ETH_MIN_PACKET_SIZE))
return -EINVAL;
dev->mtu = new_mtu;
return bnx2x_reload_if_running(dev);
}
u32 bnx2x_fix_features(struct net_device *dev, u32 features)
{
struct bnx2x *bp = netdev_priv(dev);
if (!(features & NETIF_F_RXCSUM) || bp->disable_tpa)
features &= ~NETIF_F_LRO;
return features;
}
int bnx2x_set_features(struct net_device *dev, u32 features)
{
struct bnx2x *bp = netdev_priv(dev);
u32 flags = bp->flags;
bool bnx2x_reload = false;
if (features & NETIF_F_LRO)
flags |= TPA_ENABLE_FLAG;
else
flags &= ~TPA_ENABLE_FLAG;
if (features & NETIF_F_LOOPBACK) {
if (bp->link_params.loopback_mode != LOOPBACK_BMAC) {
bp->link_params.loopback_mode = LOOPBACK_BMAC;
bnx2x_reload = true;
}
} else {
if (bp->link_params.loopback_mode != LOOPBACK_NONE) {
bp->link_params.loopback_mode = LOOPBACK_NONE;
bnx2x_reload = true;
}
}
if (flags ^ bp->flags) {
bp->flags = flags;
bnx2x_reload = true;
}
if (bnx2x_reload) {
if (bp->recovery_state == BNX2X_RECOVERY_DONE)
return bnx2x_reload_if_running(dev);
}
return 0;
}
void bnx2x_tx_timeout(struct net_device *dev)
{
struct bnx2x *bp = netdev_priv(dev);
#ifdef F_11
if (!bp->panic)
bnx2x_panic();
#endif
schedule_delayed_work(&bp->reset_task, 0);
}
int bnx2x_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct bnx2x *bp;
if (!dev) {
dev_err(&pdev->dev, L_110);
return -ENODEV;
}
bp = netdev_priv(dev);
rtnl_lock();
pci_save_state(pdev);
if (!netif_running(dev)) {
rtnl_unlock();
return 0;
}
netif_device_detach(dev);
bnx2x_nic_unload(bp, UNLOAD_CLOSE);
bnx2x_set_power_state(bp, pci_choose_state(pdev, state));
rtnl_unlock();
return 0;
}
int bnx2x_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct bnx2x *bp;
int rc;
if (!dev) {
dev_err(&pdev->dev, L_110);
return -ENODEV;
}
bp = netdev_priv(dev);
if (bp->recovery_state != BNX2X_RECOVERY_DONE) {
printk(KERN_ERR L_109);
return -EAGAIN;
}
rtnl_lock();
pci_restore_state(pdev);
if (!netif_running(dev)) {
rtnl_unlock();
return 0;
}
bnx2x_set_power_state(bp, PCI_D0);
netif_device_attach(dev);
bp->fw_seq = 0;
rc = bnx2x_nic_load(bp, LOAD_OPEN);
rtnl_unlock();
return rc;
}
