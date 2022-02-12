static int dwmac4_wrback_get_tx_status(void *data, struct stmmac_extra_stats *x,
struct dma_desc *p,
void __iomem *ioaddr)
{
struct net_device_stats *stats = (struct net_device_stats *)data;
unsigned int tdes3;
int ret = tx_done;
tdes3 = p->des3;
if (unlikely(tdes3 & TDES3_OWN))
return tx_dma_own;
if (likely(!(tdes3 & TDES3_LAST_DESCRIPTOR)))
return tx_not_ls;
if (unlikely(tdes3 & TDES3_ERROR_SUMMARY)) {
if (unlikely(tdes3 & TDES3_JABBER_TIMEOUT))
x->tx_jabber++;
if (unlikely(tdes3 & TDES3_PACKET_FLUSHED))
x->tx_frame_flushed++;
if (unlikely(tdes3 & TDES3_LOSS_CARRIER)) {
x->tx_losscarrier++;
stats->tx_carrier_errors++;
}
if (unlikely(tdes3 & TDES3_NO_CARRIER)) {
x->tx_carrier++;
stats->tx_carrier_errors++;
}
if (unlikely((tdes3 & TDES3_LATE_COLLISION) ||
(tdes3 & TDES3_EXCESSIVE_COLLISION)))
stats->collisions +=
(tdes3 & TDES3_COLLISION_COUNT_MASK)
>> TDES3_COLLISION_COUNT_SHIFT;
if (unlikely(tdes3 & TDES3_EXCESSIVE_DEFERRAL))
x->tx_deferred++;
if (unlikely(tdes3 & TDES3_UNDERFLOW_ERROR))
x->tx_underflow++;
if (unlikely(tdes3 & TDES3_IP_HDR_ERROR))
x->tx_ip_header_error++;
if (unlikely(tdes3 & TDES3_PAYLOAD_ERROR))
x->tx_payload_error++;
ret = tx_err;
}
if (unlikely(tdes3 & TDES3_DEFERRED))
x->tx_deferred++;
return ret;
}
static int dwmac4_wrback_get_rx_status(void *data, struct stmmac_extra_stats *x,
struct dma_desc *p)
{
struct net_device_stats *stats = (struct net_device_stats *)data;
unsigned int rdes1 = p->des1;
unsigned int rdes2 = p->des2;
unsigned int rdes3 = p->des3;
int message_type;
int ret = good_frame;
if (unlikely(rdes3 & RDES3_OWN))
return dma_own;
if (likely(!(rdes3 & RDES3_LAST_DESCRIPTOR)))
return discard_frame;
if (unlikely(rdes3 & RDES3_ERROR_SUMMARY)) {
if (unlikely(rdes3 & RDES3_GIANT_PACKET))
stats->rx_length_errors++;
if (unlikely(rdes3 & RDES3_OVERFLOW_ERROR))
x->rx_gmac_overflow++;
if (unlikely(rdes3 & RDES3_RECEIVE_WATCHDOG))
x->rx_watchdog++;
if (unlikely(rdes3 & RDES3_RECEIVE_ERROR))
x->rx_mii++;
if (unlikely(rdes3 & RDES3_CRC_ERROR)) {
x->rx_crc++;
stats->rx_crc_errors++;
}
if (unlikely(rdes3 & RDES3_DRIBBLE_ERROR))
x->dribbling_bit++;
ret = discard_frame;
}
message_type = (rdes1 & ERDES4_MSG_TYPE_MASK) >> 8;
if (rdes1 & RDES1_IP_HDR_ERROR)
x->ip_hdr_err++;
if (rdes1 & RDES1_IP_CSUM_BYPASSED)
x->ip_csum_bypassed++;
if (rdes1 & RDES1_IPV4_HEADER)
x->ipv4_pkt_rcvd++;
if (rdes1 & RDES1_IPV6_HEADER)
x->ipv6_pkt_rcvd++;
if (message_type == RDES_EXT_SYNC)
x->rx_msg_type_sync++;
else if (message_type == RDES_EXT_FOLLOW_UP)
x->rx_msg_type_follow_up++;
else if (message_type == RDES_EXT_DELAY_REQ)
x->rx_msg_type_delay_req++;
else if (message_type == RDES_EXT_DELAY_RESP)
x->rx_msg_type_delay_resp++;
else if (message_type == RDES_EXT_PDELAY_REQ)
x->rx_msg_type_pdelay_req++;
else if (message_type == RDES_EXT_PDELAY_RESP)
x->rx_msg_type_pdelay_resp++;
else if (message_type == RDES_EXT_PDELAY_FOLLOW_UP)
x->rx_msg_type_pdelay_follow_up++;
else
x->rx_msg_type_ext_no_ptp++;
if (rdes1 & RDES1_PTP_PACKET_TYPE)
x->ptp_frame_type++;
if (rdes1 & RDES1_PTP_VER)
x->ptp_ver++;
if (rdes1 & RDES1_TIMESTAMP_DROPPED)
x->timestamp_dropped++;
if (unlikely(rdes2 & RDES2_SA_FILTER_FAIL)) {
x->sa_rx_filter_fail++;
ret = discard_frame;
}
if (unlikely(rdes2 & RDES2_DA_FILTER_FAIL)) {
x->da_rx_filter_fail++;
ret = discard_frame;
}
if (rdes2 & RDES2_L3_FILTER_MATCH)
x->l3_filter_match++;
if (rdes2 & RDES2_L4_FILTER_MATCH)
x->l4_filter_match++;
if ((rdes2 & RDES2_L3_L4_FILT_NB_MATCH_MASK)
>> RDES2_L3_L4_FILT_NB_MATCH_SHIFT)
x->l3_l4_filter_no_match++;
return ret;
}
static int dwmac4_rd_get_tx_len(struct dma_desc *p)
{
return (p->des2 & TDES2_BUFFER1_SIZE_MASK);
}
static int dwmac4_get_tx_owner(struct dma_desc *p)
{
return (p->des3 & TDES3_OWN) >> TDES3_OWN_SHIFT;
}
static void dwmac4_set_tx_owner(struct dma_desc *p)
{
p->des3 |= TDES3_OWN;
}
static void dwmac4_set_rx_owner(struct dma_desc *p)
{
p->des3 |= RDES3_OWN;
}
static int dwmac4_get_tx_ls(struct dma_desc *p)
{
return (p->des3 & TDES3_LAST_DESCRIPTOR) >> TDES3_LAST_DESCRIPTOR_SHIFT;
}
static int dwmac4_wrback_get_rx_frame_len(struct dma_desc *p, int rx_coe)
{
return (p->des3 & RDES3_PACKET_SIZE_MASK);
}
static void dwmac4_rd_enable_tx_timestamp(struct dma_desc *p)
{
p->des2 |= TDES2_TIMESTAMP_ENABLE;
}
static int dwmac4_wrback_get_tx_timestamp_status(struct dma_desc *p)
{
return (p->des3 & TDES3_TIMESTAMP_STATUS)
>> TDES3_TIMESTAMP_STATUS_SHIFT;
}
static u64 dwmac4_wrback_get_timestamp(void *desc, u32 ats)
{
struct dma_desc *p = (struct dma_desc *)desc;
u64 ns;
ns = p->des0;
ns += p->des1 * 1000000000ULL;
return ns;
}
static int dwmac4_context_get_rx_timestamp_status(void *desc, u32 ats)
{
struct dma_desc *p = (struct dma_desc *)desc;
return (p->des1 & RDES1_TIMESTAMP_AVAILABLE)
>> RDES1_TIMESTAMP_AVAILABLE_SHIFT;
}
static void dwmac4_rd_init_rx_desc(struct dma_desc *p, int disable_rx_ic,
int mode, int end)
{
p->des3 = RDES3_OWN | RDES3_BUFFER1_VALID_ADDR;
if (!disable_rx_ic)
p->des3 |= RDES3_INT_ON_COMPLETION_EN;
}
static void dwmac4_rd_init_tx_desc(struct dma_desc *p, int mode, int end)
{
p->des0 = 0;
p->des1 = 0;
p->des2 = 0;
p->des3 = 0;
}
static void dwmac4_rd_prepare_tx_desc(struct dma_desc *p, int is_fs, int len,
bool csum_flag, int mode, bool tx_own,
bool ls)
{
unsigned int tdes3 = p->des3;
p->des2 |= (len & TDES2_BUFFER1_SIZE_MASK);
if (is_fs)
tdes3 |= TDES3_FIRST_DESCRIPTOR;
else
tdes3 &= ~TDES3_FIRST_DESCRIPTOR;
if (likely(csum_flag))
tdes3 |= (TX_CIC_FULL << TDES3_CHECKSUM_INSERTION_SHIFT);
else
tdes3 &= ~(TX_CIC_FULL << TDES3_CHECKSUM_INSERTION_SHIFT);
if (ls)
tdes3 |= TDES3_LAST_DESCRIPTOR;
else
tdes3 &= ~TDES3_LAST_DESCRIPTOR;
if (tx_own)
tdes3 |= TDES3_OWN;
if (is_fs & tx_own)
wmb();
p->des3 = tdes3;
}
static void dwmac4_rd_prepare_tso_tx_desc(struct dma_desc *p, int is_fs,
int len1, int len2, bool tx_own,
bool ls, unsigned int tcphdrlen,
unsigned int tcppayloadlen)
{
unsigned int tdes3 = p->des3;
if (len1)
p->des2 |= (len1 & TDES2_BUFFER1_SIZE_MASK);
if (len2)
p->des2 |= (len2 << TDES2_BUFFER2_SIZE_MASK_SHIFT)
& TDES2_BUFFER2_SIZE_MASK;
if (is_fs) {
tdes3 |= TDES3_FIRST_DESCRIPTOR |
TDES3_TCP_SEGMENTATION_ENABLE |
((tcphdrlen << TDES3_HDR_LEN_SHIFT) &
TDES3_SLOT_NUMBER_MASK) |
((tcppayloadlen & TDES3_TCP_PKT_PAYLOAD_MASK));
} else {
tdes3 &= ~TDES3_FIRST_DESCRIPTOR;
}
if (ls)
tdes3 |= TDES3_LAST_DESCRIPTOR;
else
tdes3 &= ~TDES3_LAST_DESCRIPTOR;
if (tx_own)
tdes3 |= TDES3_OWN;
if (is_fs & tx_own)
wmb();
p->des3 = tdes3;
}
static void dwmac4_release_tx_desc(struct dma_desc *p, int mode)
{
p->des2 = 0;
p->des3 = 0;
}
static void dwmac4_rd_set_tx_ic(struct dma_desc *p)
{
p->des2 |= TDES2_INTERRUPT_ON_COMPLETION;
}
static void dwmac4_display_ring(void *head, unsigned int size, bool rx)
{
struct dma_desc *p = (struct dma_desc *)head;
int i;
pr_info("%s descriptor ring:\n", rx ? "RX" : "TX");
for (i = 0; i < size; i++) {
if (p->des0)
pr_info("%d [0x%x]: 0x%x 0x%x 0x%x 0x%x\n",
i, (unsigned int)virt_to_phys(p),
p->des0, p->des1, p->des2, p->des3);
p++;
}
}
static void dwmac4_set_mss_ctxt(struct dma_desc *p, unsigned int mss)
{
p->des0 = 0;
p->des1 = 0;
p->des2 = mss;
p->des3 = TDES3_CONTEXT_TYPE | TDES3_CTXT_TCMSSV;
}
