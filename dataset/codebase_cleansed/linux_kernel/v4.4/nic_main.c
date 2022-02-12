static inline bool pass1_silicon(struct nicpf *nic)
{
return nic->pdev->revision < 8;
}
static void nic_reg_write(struct nicpf *nic, u64 offset, u64 val)
{
writeq_relaxed(val, nic->reg_base + offset);
}
static u64 nic_reg_read(struct nicpf *nic, u64 offset)
{
return readq_relaxed(nic->reg_base + offset);
}
static void nic_enable_mbx_intr(struct nicpf *nic)
{
nic_reg_write(nic, NIC_PF_MAILBOX_ENA_W1S, ~0ull);
nic_reg_write(nic, NIC_PF_MAILBOX_ENA_W1S + sizeof(u64), ~0ull);
}
static void nic_clear_mbx_intr(struct nicpf *nic, int vf, int mbx_reg)
{
nic_reg_write(nic, NIC_PF_MAILBOX_INT + (mbx_reg << 3), BIT_ULL(vf));
}
static u64 nic_get_mbx_addr(int vf)
{
return NIC_PF_VF_0_127_MAILBOX_0_1 + (vf << NIC_VF_NUM_SHIFT);
}
static void nic_send_msg_to_vf(struct nicpf *nic, int vf, union nic_mbx *mbx)
{
void __iomem *mbx_addr = nic->reg_base + nic_get_mbx_addr(vf);
u64 *msg = (u64 *)mbx;
if (pass1_silicon(nic)) {
writeq_relaxed(msg[0], mbx_addr);
writeq_relaxed(msg[1], mbx_addr + 8);
} else {
writeq_relaxed(msg[1], mbx_addr + 8);
writeq_relaxed(msg[0], mbx_addr);
}
}
static void nic_mbx_send_ready(struct nicpf *nic, int vf)
{
union nic_mbx mbx = {};
int bgx_idx, lmac;
const char *mac;
mbx.nic_cfg.msg = NIC_MBOX_MSG_READY;
mbx.nic_cfg.vf_id = vf;
mbx.nic_cfg.tns_mode = NIC_TNS_BYPASS_MODE;
if (vf < MAX_LMAC) {
bgx_idx = NIC_GET_BGX_FROM_VF_LMAC_MAP(nic->vf_lmac_map[vf]);
lmac = NIC_GET_LMAC_FROM_VF_LMAC_MAP(nic->vf_lmac_map[vf]);
mac = bgx_get_lmac_mac(nic->node, bgx_idx, lmac);
if (mac)
ether_addr_copy((u8 *)&mbx.nic_cfg.mac_addr, mac);
}
mbx.nic_cfg.sqs_mode = (vf >= nic->num_vf_en) ? true : false;
mbx.nic_cfg.node_id = nic->node;
mbx.nic_cfg.loopback_supported = vf < MAX_LMAC;
nic_send_msg_to_vf(nic, vf, &mbx);
}
static void nic_mbx_send_ack(struct nicpf *nic, int vf)
{
union nic_mbx mbx = {};
mbx.msg.msg = NIC_MBOX_MSG_ACK;
nic_send_msg_to_vf(nic, vf, &mbx);
}
static void nic_mbx_send_nack(struct nicpf *nic, int vf)
{
union nic_mbx mbx = {};
mbx.msg.msg = NIC_MBOX_MSG_NACK;
nic_send_msg_to_vf(nic, vf, &mbx);
}
static int nic_rcv_queue_sw_sync(struct nicpf *nic)
{
u16 timeout = ~0x00;
nic_reg_write(nic, NIC_PF_SW_SYNC_RX, 0x01);
while (timeout) {
if (nic_reg_read(nic, NIC_PF_SW_SYNC_RX_DONE) & 0x1)
break;
timeout--;
}
nic_reg_write(nic, NIC_PF_SW_SYNC_RX, 0x00);
if (!timeout) {
dev_err(&nic->pdev->dev, "Receive queue software sync failed");
return 1;
}
return 0;
}
static void nic_get_bgx_stats(struct nicpf *nic, struct bgx_stats_msg *bgx)
{
int bgx_idx, lmac;
union nic_mbx mbx = {};
bgx_idx = NIC_GET_BGX_FROM_VF_LMAC_MAP(nic->vf_lmac_map[bgx->vf_id]);
lmac = NIC_GET_LMAC_FROM_VF_LMAC_MAP(nic->vf_lmac_map[bgx->vf_id]);
mbx.bgx_stats.msg = NIC_MBOX_MSG_BGX_STATS;
mbx.bgx_stats.vf_id = bgx->vf_id;
mbx.bgx_stats.rx = bgx->rx;
mbx.bgx_stats.idx = bgx->idx;
if (bgx->rx)
mbx.bgx_stats.stats = bgx_get_rx_stats(nic->node, bgx_idx,
lmac, bgx->idx);
else
mbx.bgx_stats.stats = bgx_get_tx_stats(nic->node, bgx_idx,
lmac, bgx->idx);
nic_send_msg_to_vf(nic, bgx->vf_id, &mbx);
}
static int nic_update_hw_frs(struct nicpf *nic, int new_frs, int vf)
{
if ((new_frs > NIC_HW_MAX_FRS) || (new_frs < NIC_HW_MIN_FRS)) {
dev_err(&nic->pdev->dev,
"Invalid MTU setting from VF%d rejected, should be between %d and %d\n",
vf, NIC_HW_MIN_FRS, NIC_HW_MAX_FRS);
return 1;
}
new_frs += ETH_HLEN;
if (new_frs <= nic->pkind.maxlen)
return 0;
nic->pkind.maxlen = new_frs;
nic_reg_write(nic, NIC_PF_PKIND_0_15_CFG, *(u64 *)&nic->pkind);
return 0;
}
static void nic_set_tx_pkt_pad(struct nicpf *nic, int size)
{
int lmac;
u64 lmac_cfg;
if (size > 60)
size = 60;
for (lmac = 0; lmac < (MAX_BGX_PER_CN88XX * MAX_LMAC_PER_BGX); lmac++) {
lmac_cfg = nic_reg_read(nic, NIC_PF_LMAC_0_7_CFG | (lmac << 3));
lmac_cfg &= ~(0xF << 2);
lmac_cfg |= ((size / 4) << 2);
nic_reg_write(nic, NIC_PF_LMAC_0_7_CFG | (lmac << 3), lmac_cfg);
}
}
static void nic_set_lmac_vf_mapping(struct nicpf *nic)
{
unsigned bgx_map = bgx_get_map(nic->node);
int bgx, next_bgx_lmac = 0;
int lmac, lmac_cnt = 0;
u64 lmac_credit;
nic->num_vf_en = 0;
for (bgx = 0; bgx < NIC_MAX_BGX; bgx++) {
if (!(bgx_map & (1 << bgx)))
continue;
lmac_cnt = bgx_get_lmac_count(nic->node, bgx);
for (lmac = 0; lmac < lmac_cnt; lmac++)
nic->vf_lmac_map[next_bgx_lmac++] =
NIC_SET_VF_LMAC_MAP(bgx, lmac);
nic->num_vf_en += lmac_cnt;
lmac_credit = (1ull << 1);
lmac_credit |= (0x1ff << 2);
lmac_credit |= (((((48 * 1024) / lmac_cnt) -
NIC_HW_MAX_FRS) / 16) << 12);
lmac = bgx * MAX_LMAC_PER_BGX;
for (; lmac < lmac_cnt + (bgx * MAX_LMAC_PER_BGX); lmac++)
nic_reg_write(nic,
NIC_PF_LMAC_0_7_CREDIT + (lmac * 8),
lmac_credit);
}
}
static void nic_init_hw(struct nicpf *nic)
{
int i;
nic_reg_write(nic, NIC_PF_CFG, 0x3);
nic_reg_write(nic, NIC_PF_BP_CFG, (1ULL << 6) | 0x03);
nic_reg_write(nic, NIC_PF_INTF_0_1_SEND_CFG,
(NIC_TNS_BYPASS_MODE << 7) | BGX0_BLOCK);
nic_reg_write(nic, NIC_PF_INTF_0_1_SEND_CFG | (1 << 8),
(NIC_TNS_BYPASS_MODE << 7) | BGX1_BLOCK);
nic_reg_write(nic, NIC_PF_INTF_0_1_BP_CFG,
(1ULL << 63) | BGX0_BLOCK);
nic_reg_write(nic, NIC_PF_INTF_0_1_BP_CFG + (1 << 8),
(1ULL << 63) | BGX1_BLOCK);
nic->pkind.minlen = 0;
nic->pkind.maxlen = NIC_HW_MAX_FRS + ETH_HLEN;
nic->pkind.lenerr_en = 1;
nic->pkind.rx_hdr = 0;
nic->pkind.hdr_sl = 0;
for (i = 0; i < NIC_MAX_PKIND; i++)
nic_reg_write(nic, NIC_PF_PKIND_0_15_CFG | (i << 3),
*(u64 *)&nic->pkind);
nic_set_tx_pkt_pad(nic, NIC_HW_MIN_FRS);
nic_reg_write(nic, NIC_PF_INTR_TIMER_CFG, NICPF_CLK_PER_INT_TICK);
nic_reg_write(nic, NIC_PF_RX_ETYPE_0_7,
(2 << 19) | (ETYPE_ALG_VLAN_STRIP << 16) | ETH_P_8021Q);
}
static void nic_config_cpi(struct nicpf *nic, struct cpi_cfg_msg *cfg)
{
u32 vnic, bgx, lmac, chan;
u32 padd, cpi_count = 0;
u64 cpi_base, cpi, rssi_base, rssi;
u8 qset, rq_idx = 0;
vnic = cfg->vf_id;
bgx = NIC_GET_BGX_FROM_VF_LMAC_MAP(nic->vf_lmac_map[vnic]);
lmac = NIC_GET_LMAC_FROM_VF_LMAC_MAP(nic->vf_lmac_map[vnic]);
chan = (lmac * MAX_BGX_CHANS_PER_LMAC) + (bgx * NIC_CHANS_PER_INF);
cpi_base = (lmac * NIC_MAX_CPI_PER_LMAC) + (bgx * NIC_CPI_PER_BGX);
rssi_base = (lmac * nic->rss_ind_tbl_size) + (bgx * NIC_RSSI_PER_BGX);
nic_reg_write(nic, NIC_PF_CHAN_0_255_RX_BP_CFG | (chan << 3),
(1ull << 63) | (vnic << 0));
nic_reg_write(nic, NIC_PF_CHAN_0_255_RX_CFG | (chan << 3),
((u64)cfg->cpi_alg << 62) | (cpi_base << 48));
if (cfg->cpi_alg == CPI_ALG_NONE)
cpi_count = 1;
else if (cfg->cpi_alg == CPI_ALG_VLAN)
cpi_count = 8;
else if (cfg->cpi_alg == CPI_ALG_VLAN16)
cpi_count = 16;
else if (cfg->cpi_alg == CPI_ALG_DIFF)
cpi_count = NIC_MAX_CPI_PER_LMAC;
qset = cfg->vf_id;
rssi = rssi_base;
for (; rssi < (rssi_base + cfg->rq_cnt); rssi++) {
nic_reg_write(nic, NIC_PF_RSSI_0_4097_RQ | (rssi << 3),
(qset << 3) | rq_idx);
rq_idx++;
}
rssi = 0;
cpi = cpi_base;
for (; cpi < (cpi_base + cpi_count); cpi++) {
if (cfg->cpi_alg != CPI_ALG_DIFF)
padd = cpi % cpi_count;
else
padd = cpi % 8;
if (pass1_silicon(nic)) {
nic_reg_write(nic, NIC_PF_CPI_0_2047_CFG | (cpi << 3),
(vnic << 24) | (padd << 16) |
(rssi_base + rssi));
} else {
nic_reg_write(nic, NIC_PF_CPI_0_2047_CFG | (cpi << 3),
(padd << 16));
nic_reg_write(nic, NIC_PF_MPI_0_2047_CFG | (cpi << 3),
(vnic << 24) | (rssi_base + rssi));
}
if ((rssi + 1) >= cfg->rq_cnt)
continue;
if (cfg->cpi_alg == CPI_ALG_VLAN)
rssi++;
else if (cfg->cpi_alg == CPI_ALG_VLAN16)
rssi = ((cpi - cpi_base) & 0xe) >> 1;
else if (cfg->cpi_alg == CPI_ALG_DIFF)
rssi = ((cpi - cpi_base) & 0x38) >> 3;
}
nic->cpi_base[cfg->vf_id] = cpi_base;
nic->rssi_base[cfg->vf_id] = rssi_base;
}
static void nic_send_rss_size(struct nicpf *nic, int vf)
{
union nic_mbx mbx = {};
u64 *msg;
msg = (u64 *)&mbx;
mbx.rss_size.msg = NIC_MBOX_MSG_RSS_SIZE;
mbx.rss_size.ind_tbl_size = nic->rss_ind_tbl_size;
nic_send_msg_to_vf(nic, vf, &mbx);
}
static void nic_config_rss(struct nicpf *nic, struct rss_cfg_msg *cfg)
{
u8 qset, idx = 0;
u64 cpi_cfg, cpi_base, rssi_base, rssi;
u64 idx_addr;
rssi_base = nic->rssi_base[cfg->vf_id] + cfg->tbl_offset;
rssi = rssi_base;
qset = cfg->vf_id;
for (; rssi < (rssi_base + cfg->tbl_len); rssi++) {
u8 svf = cfg->ind_tbl[idx] >> 3;
if (svf)
qset = nic->vf_sqs[cfg->vf_id][svf - 1];
else
qset = cfg->vf_id;
nic_reg_write(nic, NIC_PF_RSSI_0_4097_RQ | (rssi << 3),
(qset << 3) | (cfg->ind_tbl[idx] & 0x7));
idx++;
}
cpi_base = nic->cpi_base[cfg->vf_id];
if (pass1_silicon(nic))
idx_addr = NIC_PF_CPI_0_2047_CFG;
else
idx_addr = NIC_PF_MPI_0_2047_CFG;
cpi_cfg = nic_reg_read(nic, idx_addr | (cpi_base << 3));
cpi_cfg &= ~(0xFULL << 20);
cpi_cfg |= (cfg->hash_bits << 20);
nic_reg_write(nic, idx_addr | (cpi_base << 3), cpi_cfg);
}
static void nic_tx_channel_cfg(struct nicpf *nic, u8 vnic,
struct sq_cfg_msg *sq)
{
u32 bgx, lmac, chan;
u32 tl2, tl3, tl4;
u32 rr_quantum;
u8 sq_idx = sq->sq_num;
u8 pqs_vnic;
if (sq->sqs_mode)
pqs_vnic = nic->pqs_vf[vnic];
else
pqs_vnic = vnic;
bgx = NIC_GET_BGX_FROM_VF_LMAC_MAP(nic->vf_lmac_map[pqs_vnic]);
lmac = NIC_GET_LMAC_FROM_VF_LMAC_MAP(nic->vf_lmac_map[pqs_vnic]);
rr_quantum = ((NIC_HW_MAX_FRS + 24) / 4);
tl4 = (lmac * NIC_TL4_PER_LMAC) + (bgx * NIC_TL4_PER_BGX);
tl4 += sq_idx;
if (sq->sqs_mode)
tl4 += vnic * 8;
tl3 = tl4 / (NIC_MAX_TL4 / NIC_MAX_TL3);
nic_reg_write(nic, NIC_PF_QSET_0_127_SQ_0_7_CFG2 |
((u64)vnic << NIC_QS_ID_SHIFT) |
((u32)sq_idx << NIC_Q_NUM_SHIFT), tl4);
nic_reg_write(nic, NIC_PF_TL4_0_1023_CFG | (tl4 << 3),
((u64)vnic << 27) | ((u32)sq_idx << 24) | rr_quantum);
nic_reg_write(nic, NIC_PF_TL3_0_255_CFG | (tl3 << 3), rr_quantum);
chan = (lmac * MAX_BGX_CHANS_PER_LMAC) + (bgx * NIC_CHANS_PER_INF);
nic_reg_write(nic, NIC_PF_TL3_0_255_CHAN | (tl3 << 3), chan);
nic_reg_write(nic, NIC_PF_CHAN_0_255_TX_CFG | (chan << 3), 1);
tl2 = tl3 >> 2;
nic_reg_write(nic, NIC_PF_TL3A_0_63_CFG | (tl2 << 3), tl2);
nic_reg_write(nic, NIC_PF_TL2_0_63_CFG | (tl2 << 3), rr_quantum);
nic_reg_write(nic, NIC_PF_TL2_0_63_PRI | (tl2 << 3), 0x00);
}
static void nic_send_pnicvf(struct nicpf *nic, int sqs)
{
union nic_mbx mbx = {};
mbx.nicvf.msg = NIC_MBOX_MSG_PNICVF_PTR;
mbx.nicvf.nicvf = nic->nicvf[nic->pqs_vf[sqs]];
nic_send_msg_to_vf(nic, sqs, &mbx);
}
static void nic_send_snicvf(struct nicpf *nic, struct nicvf_ptr *nicvf)
{
union nic_mbx mbx = {};
int sqs_id = nic->vf_sqs[nicvf->vf_id][nicvf->sqs_id];
mbx.nicvf.msg = NIC_MBOX_MSG_SNICVF_PTR;
mbx.nicvf.sqs_id = nicvf->sqs_id;
mbx.nicvf.nicvf = nic->nicvf[sqs_id];
nic_send_msg_to_vf(nic, nicvf->vf_id, &mbx);
}
static int nic_nxt_avail_sqs(struct nicpf *nic)
{
int sqs;
for (sqs = 0; sqs < nic->num_sqs_en; sqs++) {
if (!nic->sqs_used[sqs])
nic->sqs_used[sqs] = true;
else
continue;
return sqs + nic->num_vf_en;
}
return -1;
}
static void nic_alloc_sqs(struct nicpf *nic, struct sqs_alloc *sqs)
{
union nic_mbx mbx = {};
int idx, alloc_qs = 0;
int sqs_id;
if (!nic->num_sqs_en)
goto send_mbox;
for (idx = 0; idx < sqs->qs_count; idx++) {
sqs_id = nic_nxt_avail_sqs(nic);
if (sqs_id < 0)
break;
nic->vf_sqs[sqs->vf_id][idx] = sqs_id;
nic->pqs_vf[sqs_id] = sqs->vf_id;
alloc_qs++;
}
send_mbox:
mbx.sqs_alloc.msg = NIC_MBOX_MSG_ALLOC_SQS;
mbx.sqs_alloc.vf_id = sqs->vf_id;
mbx.sqs_alloc.qs_count = alloc_qs;
nic_send_msg_to_vf(nic, sqs->vf_id, &mbx);
}
static int nic_config_loopback(struct nicpf *nic, struct set_loopback *lbk)
{
int bgx_idx, lmac_idx;
if (lbk->vf_id > MAX_LMAC)
return -1;
bgx_idx = NIC_GET_BGX_FROM_VF_LMAC_MAP(nic->vf_lmac_map[lbk->vf_id]);
lmac_idx = NIC_GET_LMAC_FROM_VF_LMAC_MAP(nic->vf_lmac_map[lbk->vf_id]);
bgx_lmac_internal_loopback(nic->node, bgx_idx, lmac_idx, lbk->enable);
return 0;
}
static void nic_enable_vf(struct nicpf *nic, int vf, bool enable)
{
int bgx, lmac;
nic->vf_enabled[vf] = enable;
if (vf >= nic->num_vf_en)
return;
bgx = NIC_GET_BGX_FROM_VF_LMAC_MAP(nic->vf_lmac_map[vf]);
lmac = NIC_GET_LMAC_FROM_VF_LMAC_MAP(nic->vf_lmac_map[vf]);
bgx_lmac_rx_tx_enable(nic->node, bgx, lmac, enable);
}
static void nic_handle_mbx_intr(struct nicpf *nic, int vf)
{
union nic_mbx mbx = {};
u64 *mbx_data;
u64 mbx_addr;
u64 reg_addr;
u64 cfg;
int bgx, lmac;
int i;
int ret = 0;
nic->mbx_lock[vf] = true;
mbx_addr = nic_get_mbx_addr(vf);
mbx_data = (u64 *)&mbx;
for (i = 0; i < NIC_PF_VF_MAILBOX_SIZE; i++) {
*mbx_data = nic_reg_read(nic, mbx_addr);
mbx_data++;
mbx_addr += sizeof(u64);
}
dev_dbg(&nic->pdev->dev, "%s: Mailbox msg %d from VF%d\n",
__func__, mbx.msg.msg, vf);
switch (mbx.msg.msg) {
case NIC_MBOX_MSG_READY:
nic_mbx_send_ready(nic, vf);
if (vf < MAX_LMAC) {
nic->link[vf] = 0;
nic->duplex[vf] = 0;
nic->speed[vf] = 0;
}
ret = 1;
break;
case NIC_MBOX_MSG_QS_CFG:
reg_addr = NIC_PF_QSET_0_127_CFG |
(mbx.qs.num << NIC_QS_ID_SHIFT);
cfg = mbx.qs.cfg;
if (vf >= nic->num_vf_en) {
cfg = cfg & (~0x7FULL);
cfg |= nic->pqs_vf[vf];
}
nic_reg_write(nic, reg_addr, cfg);
break;
case NIC_MBOX_MSG_RQ_CFG:
reg_addr = NIC_PF_QSET_0_127_RQ_0_7_CFG |
(mbx.rq.qs_num << NIC_QS_ID_SHIFT) |
(mbx.rq.rq_num << NIC_Q_NUM_SHIFT);
nic_reg_write(nic, reg_addr, mbx.rq.cfg);
break;
case NIC_MBOX_MSG_RQ_BP_CFG:
reg_addr = NIC_PF_QSET_0_127_RQ_0_7_BP_CFG |
(mbx.rq.qs_num << NIC_QS_ID_SHIFT) |
(mbx.rq.rq_num << NIC_Q_NUM_SHIFT);
nic_reg_write(nic, reg_addr, mbx.rq.cfg);
break;
case NIC_MBOX_MSG_RQ_SW_SYNC:
ret = nic_rcv_queue_sw_sync(nic);
break;
case NIC_MBOX_MSG_RQ_DROP_CFG:
reg_addr = NIC_PF_QSET_0_127_RQ_0_7_DROP_CFG |
(mbx.rq.qs_num << NIC_QS_ID_SHIFT) |
(mbx.rq.rq_num << NIC_Q_NUM_SHIFT);
nic_reg_write(nic, reg_addr, mbx.rq.cfg);
break;
case NIC_MBOX_MSG_SQ_CFG:
reg_addr = NIC_PF_QSET_0_127_SQ_0_7_CFG |
(mbx.sq.qs_num << NIC_QS_ID_SHIFT) |
(mbx.sq.sq_num << NIC_Q_NUM_SHIFT);
nic_reg_write(nic, reg_addr, mbx.sq.cfg);
nic_tx_channel_cfg(nic, mbx.qs.num, &mbx.sq);
break;
case NIC_MBOX_MSG_SET_MAC:
if (vf >= nic->num_vf_en)
break;
lmac = mbx.mac.vf_id;
bgx = NIC_GET_BGX_FROM_VF_LMAC_MAP(nic->vf_lmac_map[lmac]);
lmac = NIC_GET_LMAC_FROM_VF_LMAC_MAP(nic->vf_lmac_map[lmac]);
bgx_set_lmac_mac(nic->node, bgx, lmac, mbx.mac.mac_addr);
break;
case NIC_MBOX_MSG_SET_MAX_FRS:
ret = nic_update_hw_frs(nic, mbx.frs.max_frs,
mbx.frs.vf_id);
break;
case NIC_MBOX_MSG_CPI_CFG:
nic_config_cpi(nic, &mbx.cpi_cfg);
break;
case NIC_MBOX_MSG_RSS_SIZE:
nic_send_rss_size(nic, vf);
goto unlock;
case NIC_MBOX_MSG_RSS_CFG:
case NIC_MBOX_MSG_RSS_CFG_CONT:
nic_config_rss(nic, &mbx.rss_cfg);
break;
case NIC_MBOX_MSG_CFG_DONE:
nic_enable_vf(nic, vf, true);
goto unlock;
case NIC_MBOX_MSG_SHUTDOWN:
if (vf >= nic->num_vf_en)
nic->sqs_used[vf - nic->num_vf_en] = false;
nic->pqs_vf[vf] = 0;
nic_enable_vf(nic, vf, false);
break;
case NIC_MBOX_MSG_ALLOC_SQS:
nic_alloc_sqs(nic, &mbx.sqs_alloc);
goto unlock;
case NIC_MBOX_MSG_NICVF_PTR:
nic->nicvf[vf] = mbx.nicvf.nicvf;
break;
case NIC_MBOX_MSG_PNICVF_PTR:
nic_send_pnicvf(nic, vf);
goto unlock;
case NIC_MBOX_MSG_SNICVF_PTR:
nic_send_snicvf(nic, &mbx.nicvf);
goto unlock;
case NIC_MBOX_MSG_BGX_STATS:
nic_get_bgx_stats(nic, &mbx.bgx_stats);
goto unlock;
case NIC_MBOX_MSG_LOOPBACK:
ret = nic_config_loopback(nic, &mbx.lbk);
break;
default:
dev_err(&nic->pdev->dev,
"Invalid msg from VF%d, msg 0x%x\n", vf, mbx.msg.msg);
break;
}
if (!ret)
nic_mbx_send_ack(nic, vf);
else if (mbx.msg.msg != NIC_MBOX_MSG_READY)
nic_mbx_send_nack(nic, vf);
unlock:
nic->mbx_lock[vf] = false;
}
static void nic_mbx_intr_handler (struct nicpf *nic, int mbx)
{
u64 intr;
u8 vf, vf_per_mbx_reg = 64;
intr = nic_reg_read(nic, NIC_PF_MAILBOX_INT + (mbx << 3));
dev_dbg(&nic->pdev->dev, "PF interrupt Mbox%d 0x%llx\n", mbx, intr);
for (vf = 0; vf < vf_per_mbx_reg; vf++) {
if (intr & (1ULL << vf)) {
dev_dbg(&nic->pdev->dev, "Intr from VF %d\n",
vf + (mbx * vf_per_mbx_reg));
nic_handle_mbx_intr(nic, vf + (mbx * vf_per_mbx_reg));
nic_clear_mbx_intr(nic, vf, mbx);
}
}
}
static irqreturn_t nic_mbx0_intr_handler (int irq, void *nic_irq)
{
struct nicpf *nic = (struct nicpf *)nic_irq;
nic_mbx_intr_handler(nic, 0);
return IRQ_HANDLED;
}
static irqreturn_t nic_mbx1_intr_handler (int irq, void *nic_irq)
{
struct nicpf *nic = (struct nicpf *)nic_irq;
nic_mbx_intr_handler(nic, 1);
return IRQ_HANDLED;
}
static int nic_enable_msix(struct nicpf *nic)
{
int i, ret;
nic->num_vec = NIC_PF_MSIX_VECTORS;
for (i = 0; i < nic->num_vec; i++)
nic->msix_entries[i].entry = i;
ret = pci_enable_msix(nic->pdev, nic->msix_entries, nic->num_vec);
if (ret) {
dev_err(&nic->pdev->dev,
"Request for #%d msix vectors failed\n",
nic->num_vec);
return ret;
}
nic->msix_enabled = 1;
return 0;
}
static void nic_disable_msix(struct nicpf *nic)
{
if (nic->msix_enabled) {
pci_disable_msix(nic->pdev);
nic->msix_enabled = 0;
nic->num_vec = 0;
}
}
static void nic_free_all_interrupts(struct nicpf *nic)
{
int irq;
for (irq = 0; irq < nic->num_vec; irq++) {
if (nic->irq_allocated[irq])
free_irq(nic->msix_entries[irq].vector, nic);
nic->irq_allocated[irq] = false;
}
}
static int nic_register_interrupts(struct nicpf *nic)
{
int ret;
ret = nic_enable_msix(nic);
if (ret)
return ret;
ret = request_irq(nic->msix_entries[NIC_PF_INTR_ID_MBOX0].vector,
nic_mbx0_intr_handler, 0, "NIC Mbox0", nic);
if (ret)
goto fail;
nic->irq_allocated[NIC_PF_INTR_ID_MBOX0] = true;
ret = request_irq(nic->msix_entries[NIC_PF_INTR_ID_MBOX1].vector,
nic_mbx1_intr_handler, 0, "NIC Mbox1", nic);
if (ret)
goto fail;
nic->irq_allocated[NIC_PF_INTR_ID_MBOX1] = true;
nic_enable_mbx_intr(nic);
return 0;
fail:
dev_err(&nic->pdev->dev, "Request irq failed\n");
nic_free_all_interrupts(nic);
return ret;
}
static void nic_unregister_interrupts(struct nicpf *nic)
{
nic_free_all_interrupts(nic);
nic_disable_msix(nic);
}
static int nic_num_sqs_en(struct nicpf *nic, int vf_en)
{
int pos, sqs_per_vf = MAX_SQS_PER_VF_SINGLE_NODE;
u16 total_vf;
if (nr_node_ids > 1)
sqs_per_vf = MAX_SQS_PER_VF;
pos = pci_find_ext_capability(nic->pdev, PCI_EXT_CAP_ID_SRIOV);
pci_read_config_word(nic->pdev, (pos + PCI_SRIOV_TOTAL_VF), &total_vf);
return min(total_vf - vf_en, vf_en * sqs_per_vf);
}
static int nic_sriov_init(struct pci_dev *pdev, struct nicpf *nic)
{
int pos = 0;
int vf_en;
int err;
u16 total_vf_cnt;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_SRIOV);
if (!pos) {
dev_err(&pdev->dev, "SRIOV capability is not found in PCIe config space\n");
return -ENODEV;
}
pci_read_config_word(pdev, (pos + PCI_SRIOV_TOTAL_VF), &total_vf_cnt);
if (total_vf_cnt < nic->num_vf_en)
nic->num_vf_en = total_vf_cnt;
if (!total_vf_cnt)
return 0;
vf_en = nic->num_vf_en;
nic->num_sqs_en = nic_num_sqs_en(nic, nic->num_vf_en);
vf_en += nic->num_sqs_en;
err = pci_enable_sriov(pdev, vf_en);
if (err) {
dev_err(&pdev->dev, "SRIOV enable failed, num VF is %d\n",
vf_en);
nic->num_vf_en = 0;
return err;
}
dev_info(&pdev->dev, "SRIOV enabled, number of VF available %d\n",
vf_en);
nic->flags |= NIC_SRIOV_ENABLED;
return 0;
}
static void nic_poll_for_link(struct work_struct *work)
{
union nic_mbx mbx = {};
struct nicpf *nic;
struct bgx_link_status link;
u8 vf, bgx, lmac;
nic = container_of(work, struct nicpf, dwork.work);
mbx.link_status.msg = NIC_MBOX_MSG_BGX_LINK_CHANGE;
for (vf = 0; vf < nic->num_vf_en; vf++) {
if (!nic->vf_enabled[vf])
continue;
bgx = NIC_GET_BGX_FROM_VF_LMAC_MAP(nic->vf_lmac_map[vf]);
lmac = NIC_GET_LMAC_FROM_VF_LMAC_MAP(nic->vf_lmac_map[vf]);
bgx_get_lmac_link_state(nic->node, bgx, lmac, &link);
if (nic->link[vf] == link.link_up)
continue;
if (!nic->mbx_lock[vf]) {
nic->link[vf] = link.link_up;
nic->duplex[vf] = link.duplex;
nic->speed[vf] = link.speed;
mbx.link_status.link_up = link.link_up;
mbx.link_status.duplex = link.duplex;
mbx.link_status.speed = link.speed;
nic_send_msg_to_vf(nic, vf, &mbx);
}
}
queue_delayed_work(nic->check_link, &nic->dwork, HZ * 2);
}
static int nic_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct device *dev = &pdev->dev;
struct nicpf *nic;
int err;
BUILD_BUG_ON(sizeof(union nic_mbx) > 16);
nic = devm_kzalloc(dev, sizeof(*nic), GFP_KERNEL);
if (!nic)
return -ENOMEM;
pci_set_drvdata(pdev, nic);
nic->pdev = pdev;
err = pci_enable_device(pdev);
if (err) {
dev_err(dev, "Failed to enable PCI device\n");
pci_set_drvdata(pdev, NULL);
return err;
}
err = pci_request_regions(pdev, DRV_NAME);
if (err) {
dev_err(dev, "PCI request regions failed 0x%x\n", err);
goto err_disable_device;
}
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(48));
if (err) {
dev_err(dev, "Unable to get usable DMA configuration\n");
goto err_release_regions;
}
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(48));
if (err) {
dev_err(dev, "Unable to get 48-bit DMA for consistent allocations\n");
goto err_release_regions;
}
nic->reg_base = pcim_iomap(pdev, PCI_CFG_REG_BAR_NUM, 0);
if (!nic->reg_base) {
dev_err(dev, "Cannot map config register space, aborting\n");
err = -ENOMEM;
goto err_release_regions;
}
nic->node = nic_get_node_id(pdev);
nic_set_lmac_vf_mapping(nic);
nic_init_hw(nic);
nic->rss_ind_tbl_size = NIC_MAX_RSS_IDR_TBL_SIZE;
err = nic_register_interrupts(nic);
if (err)
goto err_release_regions;
err = nic_sriov_init(pdev, nic);
if (err)
goto err_unregister_interrupts;
nic->check_link = alloc_workqueue("check_link_status",
WQ_UNBOUND | WQ_MEM_RECLAIM, 1);
if (!nic->check_link) {
err = -ENOMEM;
goto err_disable_sriov;
}
INIT_DELAYED_WORK(&nic->dwork, nic_poll_for_link);
queue_delayed_work(nic->check_link, &nic->dwork, 0);
return 0;
err_disable_sriov:
if (nic->flags & NIC_SRIOV_ENABLED)
pci_disable_sriov(pdev);
err_unregister_interrupts:
nic_unregister_interrupts(nic);
err_release_regions:
pci_release_regions(pdev);
err_disable_device:
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
return err;
}
static void nic_remove(struct pci_dev *pdev)
{
struct nicpf *nic = pci_get_drvdata(pdev);
if (nic->flags & NIC_SRIOV_ENABLED)
pci_disable_sriov(pdev);
if (nic->check_link) {
cancel_delayed_work_sync(&nic->dwork);
destroy_workqueue(nic->check_link);
}
nic_unregister_interrupts(nic);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int __init nic_init_module(void)
{
pr_info("%s, ver %s\n", DRV_NAME, DRV_VERSION);
return pci_register_driver(&nic_driver);
}
static void __exit nic_cleanup_module(void)
{
pci_unregister_driver(&nic_driver);
}
