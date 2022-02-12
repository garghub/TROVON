static struct bufdesc *fec_enet_get_nextdesc(struct bufdesc *bdp,
struct bufdesc_prop *bd)
{
return (bdp >= bd->last) ? bd->base
: (struct bufdesc *)(((void *)bdp) + bd->dsize);
}
static struct bufdesc *fec_enet_get_prevdesc(struct bufdesc *bdp,
struct bufdesc_prop *bd)
{
return (bdp <= bd->base) ? bd->last
: (struct bufdesc *)(((void *)bdp) - bd->dsize);
}
static int fec_enet_get_bd_index(struct bufdesc *bdp,
struct bufdesc_prop *bd)
{
return ((const char *)bdp - (const char *)bd->base) >> bd->dsize_log2;
}
static int fec_enet_get_free_txdesc_num(struct fec_enet_priv_tx_q *txq)
{
int entries;
entries = (((const char *)txq->dirty_tx -
(const char *)txq->bd.cur) >> txq->bd.dsize_log2) - 1;
return entries >= 0 ? entries : entries + txq->bd.ring_size;
}
static void swap_buffer(void *bufaddr, int len)
{
int i;
unsigned int *buf = bufaddr;
for (i = 0; i < len; i += 4, buf++)
swab32s(buf);
}
static void swap_buffer2(void *dst_buf, void *src_buf, int len)
{
int i;
unsigned int *src = src_buf;
unsigned int *dst = dst_buf;
for (i = 0; i < len; i += 4, src++, dst++)
*dst = swab32p(src);
}
static void fec_dump(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct bufdesc *bdp;
struct fec_enet_priv_tx_q *txq;
int index = 0;
netdev_info(ndev, "TX ring dump\n");
pr_info("Nr SC addr len SKB\n");
txq = fep->tx_queue[0];
bdp = txq->bd.base;
do {
pr_info("%3u %c%c 0x%04x 0x%08x %4u %p\n",
index,
bdp == txq->bd.cur ? 'S' : ' ',
bdp == txq->dirty_tx ? 'H' : ' ',
fec16_to_cpu(bdp->cbd_sc),
fec32_to_cpu(bdp->cbd_bufaddr),
fec16_to_cpu(bdp->cbd_datlen),
txq->tx_skbuff[index]);
bdp = fec_enet_get_nextdesc(bdp, &txq->bd);
index++;
} while (bdp != txq->bd.base);
}
static inline bool is_ipv4_pkt(struct sk_buff *skb)
{
return skb->protocol == htons(ETH_P_IP) && ip_hdr(skb)->version == 4;
}
static int
fec_enet_clear_csum(struct sk_buff *skb, struct net_device *ndev)
{
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
if (unlikely(skb_cow_head(skb, 0)))
return -1;
if (is_ipv4_pkt(skb))
ip_hdr(skb)->check = 0;
*(__sum16 *)(skb->head + skb->csum_start + skb->csum_offset) = 0;
return 0;
}
static struct bufdesc *
fec_enet_txq_submit_frag_skb(struct fec_enet_priv_tx_q *txq,
struct sk_buff *skb,
struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct bufdesc *bdp = txq->bd.cur;
struct bufdesc_ex *ebdp;
int nr_frags = skb_shinfo(skb)->nr_frags;
int frag, frag_len;
unsigned short status;
unsigned int estatus = 0;
skb_frag_t *this_frag;
unsigned int index;
void *bufaddr;
dma_addr_t addr;
int i;
for (frag = 0; frag < nr_frags; frag++) {
this_frag = &skb_shinfo(skb)->frags[frag];
bdp = fec_enet_get_nextdesc(bdp, &txq->bd);
ebdp = (struct bufdesc_ex *)bdp;
status = fec16_to_cpu(bdp->cbd_sc);
status &= ~BD_ENET_TX_STATS;
status |= (BD_ENET_TX_TC | BD_ENET_TX_READY);
frag_len = skb_shinfo(skb)->frags[frag].size;
if (frag == nr_frags - 1) {
status |= (BD_ENET_TX_INTR | BD_ENET_TX_LAST);
if (fep->bufdesc_ex) {
estatus |= BD_ENET_TX_INT;
if (unlikely(skb_shinfo(skb)->tx_flags &
SKBTX_HW_TSTAMP && fep->hwts_tx_en))
estatus |= BD_ENET_TX_TS;
}
}
if (fep->bufdesc_ex) {
if (fep->quirks & FEC_QUIRK_HAS_AVB)
estatus |= FEC_TX_BD_FTYPE(txq->bd.qid);
if (skb->ip_summed == CHECKSUM_PARTIAL)
estatus |= BD_ENET_TX_PINS | BD_ENET_TX_IINS;
ebdp->cbd_bdu = 0;
ebdp->cbd_esc = cpu_to_fec32(estatus);
}
bufaddr = page_address(this_frag->page.p) + this_frag->page_offset;
index = fec_enet_get_bd_index(bdp, &txq->bd);
if (((unsigned long) bufaddr) & fep->tx_align ||
fep->quirks & FEC_QUIRK_SWAP_FRAME) {
memcpy(txq->tx_bounce[index], bufaddr, frag_len);
bufaddr = txq->tx_bounce[index];
if (fep->quirks & FEC_QUIRK_SWAP_FRAME)
swap_buffer(bufaddr, frag_len);
}
addr = dma_map_single(&fep->pdev->dev, bufaddr, frag_len,
DMA_TO_DEVICE);
if (dma_mapping_error(&fep->pdev->dev, addr)) {
if (net_ratelimit())
netdev_err(ndev, "Tx DMA memory map failed\n");
goto dma_mapping_error;
}
bdp->cbd_bufaddr = cpu_to_fec32(addr);
bdp->cbd_datlen = cpu_to_fec16(frag_len);
wmb();
bdp->cbd_sc = cpu_to_fec16(status);
}
return bdp;
dma_mapping_error:
bdp = txq->bd.cur;
for (i = 0; i < frag; i++) {
bdp = fec_enet_get_nextdesc(bdp, &txq->bd);
dma_unmap_single(&fep->pdev->dev, fec32_to_cpu(bdp->cbd_bufaddr),
fec16_to_cpu(bdp->cbd_datlen), DMA_TO_DEVICE);
}
return ERR_PTR(-ENOMEM);
}
static int fec_enet_txq_submit_skb(struct fec_enet_priv_tx_q *txq,
struct sk_buff *skb, struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int nr_frags = skb_shinfo(skb)->nr_frags;
struct bufdesc *bdp, *last_bdp;
void *bufaddr;
dma_addr_t addr;
unsigned short status;
unsigned short buflen;
unsigned int estatus = 0;
unsigned int index;
int entries_free;
entries_free = fec_enet_get_free_txdesc_num(txq);
if (entries_free < MAX_SKB_FRAGS + 1) {
dev_kfree_skb_any(skb);
if (net_ratelimit())
netdev_err(ndev, "NOT enough BD for SG!\n");
return NETDEV_TX_OK;
}
if (fec_enet_clear_csum(skb, ndev)) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
bdp = txq->bd.cur;
last_bdp = bdp;
status = fec16_to_cpu(bdp->cbd_sc);
status &= ~BD_ENET_TX_STATS;
bufaddr = skb->data;
buflen = skb_headlen(skb);
index = fec_enet_get_bd_index(bdp, &txq->bd);
if (((unsigned long) bufaddr) & fep->tx_align ||
fep->quirks & FEC_QUIRK_SWAP_FRAME) {
memcpy(txq->tx_bounce[index], skb->data, buflen);
bufaddr = txq->tx_bounce[index];
if (fep->quirks & FEC_QUIRK_SWAP_FRAME)
swap_buffer(bufaddr, buflen);
}
addr = dma_map_single(&fep->pdev->dev, bufaddr, buflen, DMA_TO_DEVICE);
if (dma_mapping_error(&fep->pdev->dev, addr)) {
dev_kfree_skb_any(skb);
if (net_ratelimit())
netdev_err(ndev, "Tx DMA memory map failed\n");
return NETDEV_TX_OK;
}
if (nr_frags) {
last_bdp = fec_enet_txq_submit_frag_skb(txq, skb, ndev);
if (IS_ERR(last_bdp)) {
dma_unmap_single(&fep->pdev->dev, addr,
buflen, DMA_TO_DEVICE);
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
} else {
status |= (BD_ENET_TX_INTR | BD_ENET_TX_LAST);
if (fep->bufdesc_ex) {
estatus = BD_ENET_TX_INT;
if (unlikely(skb_shinfo(skb)->tx_flags &
SKBTX_HW_TSTAMP && fep->hwts_tx_en))
estatus |= BD_ENET_TX_TS;
}
}
bdp->cbd_bufaddr = cpu_to_fec32(addr);
bdp->cbd_datlen = cpu_to_fec16(buflen);
if (fep->bufdesc_ex) {
struct bufdesc_ex *ebdp = (struct bufdesc_ex *)bdp;
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP &&
fep->hwts_tx_en))
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
if (fep->quirks & FEC_QUIRK_HAS_AVB)
estatus |= FEC_TX_BD_FTYPE(txq->bd.qid);
if (skb->ip_summed == CHECKSUM_PARTIAL)
estatus |= BD_ENET_TX_PINS | BD_ENET_TX_IINS;
ebdp->cbd_bdu = 0;
ebdp->cbd_esc = cpu_to_fec32(estatus);
}
index = fec_enet_get_bd_index(last_bdp, &txq->bd);
txq->tx_skbuff[index] = skb;
wmb();
status |= (BD_ENET_TX_READY | BD_ENET_TX_TC);
bdp->cbd_sc = cpu_to_fec16(status);
bdp = fec_enet_get_nextdesc(last_bdp, &txq->bd);
skb_tx_timestamp(skb);
wmb();
txq->bd.cur = bdp;
writel(0, txq->bd.reg_desc_active);
return 0;
}
static int
fec_enet_txq_put_data_tso(struct fec_enet_priv_tx_q *txq, struct sk_buff *skb,
struct net_device *ndev,
struct bufdesc *bdp, int index, char *data,
int size, bool last_tcp, bool is_last)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct bufdesc_ex *ebdp = container_of(bdp, struct bufdesc_ex, desc);
unsigned short status;
unsigned int estatus = 0;
dma_addr_t addr;
status = fec16_to_cpu(bdp->cbd_sc);
status &= ~BD_ENET_TX_STATS;
status |= (BD_ENET_TX_TC | BD_ENET_TX_READY);
if (((unsigned long) data) & fep->tx_align ||
fep->quirks & FEC_QUIRK_SWAP_FRAME) {
memcpy(txq->tx_bounce[index], data, size);
data = txq->tx_bounce[index];
if (fep->quirks & FEC_QUIRK_SWAP_FRAME)
swap_buffer(data, size);
}
addr = dma_map_single(&fep->pdev->dev, data, size, DMA_TO_DEVICE);
if (dma_mapping_error(&fep->pdev->dev, addr)) {
dev_kfree_skb_any(skb);
if (net_ratelimit())
netdev_err(ndev, "Tx DMA memory map failed\n");
return NETDEV_TX_BUSY;
}
bdp->cbd_datlen = cpu_to_fec16(size);
bdp->cbd_bufaddr = cpu_to_fec32(addr);
if (fep->bufdesc_ex) {
if (fep->quirks & FEC_QUIRK_HAS_AVB)
estatus |= FEC_TX_BD_FTYPE(txq->bd.qid);
if (skb->ip_summed == CHECKSUM_PARTIAL)
estatus |= BD_ENET_TX_PINS | BD_ENET_TX_IINS;
ebdp->cbd_bdu = 0;
ebdp->cbd_esc = cpu_to_fec32(estatus);
}
if (last_tcp)
status |= (BD_ENET_TX_LAST | BD_ENET_TX_TC);
if (is_last) {
status |= BD_ENET_TX_INTR;
if (fep->bufdesc_ex)
ebdp->cbd_esc |= cpu_to_fec32(BD_ENET_TX_INT);
}
bdp->cbd_sc = cpu_to_fec16(status);
return 0;
}
static int
fec_enet_txq_put_hdr_tso(struct fec_enet_priv_tx_q *txq,
struct sk_buff *skb, struct net_device *ndev,
struct bufdesc *bdp, int index)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int hdr_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
struct bufdesc_ex *ebdp = container_of(bdp, struct bufdesc_ex, desc);
void *bufaddr;
unsigned long dmabuf;
unsigned short status;
unsigned int estatus = 0;
status = fec16_to_cpu(bdp->cbd_sc);
status &= ~BD_ENET_TX_STATS;
status |= (BD_ENET_TX_TC | BD_ENET_TX_READY);
bufaddr = txq->tso_hdrs + index * TSO_HEADER_SIZE;
dmabuf = txq->tso_hdrs_dma + index * TSO_HEADER_SIZE;
if (((unsigned long)bufaddr) & fep->tx_align ||
fep->quirks & FEC_QUIRK_SWAP_FRAME) {
memcpy(txq->tx_bounce[index], skb->data, hdr_len);
bufaddr = txq->tx_bounce[index];
if (fep->quirks & FEC_QUIRK_SWAP_FRAME)
swap_buffer(bufaddr, hdr_len);
dmabuf = dma_map_single(&fep->pdev->dev, bufaddr,
hdr_len, DMA_TO_DEVICE);
if (dma_mapping_error(&fep->pdev->dev, dmabuf)) {
dev_kfree_skb_any(skb);
if (net_ratelimit())
netdev_err(ndev, "Tx DMA memory map failed\n");
return NETDEV_TX_BUSY;
}
}
bdp->cbd_bufaddr = cpu_to_fec32(dmabuf);
bdp->cbd_datlen = cpu_to_fec16(hdr_len);
if (fep->bufdesc_ex) {
if (fep->quirks & FEC_QUIRK_HAS_AVB)
estatus |= FEC_TX_BD_FTYPE(txq->bd.qid);
if (skb->ip_summed == CHECKSUM_PARTIAL)
estatus |= BD_ENET_TX_PINS | BD_ENET_TX_IINS;
ebdp->cbd_bdu = 0;
ebdp->cbd_esc = cpu_to_fec32(estatus);
}
bdp->cbd_sc = cpu_to_fec16(status);
return 0;
}
static int fec_enet_txq_submit_tso(struct fec_enet_priv_tx_q *txq,
struct sk_buff *skb,
struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int hdr_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
int total_len, data_left;
struct bufdesc *bdp = txq->bd.cur;
struct tso_t tso;
unsigned int index = 0;
int ret;
if (tso_count_descs(skb) >= fec_enet_get_free_txdesc_num(txq)) {
dev_kfree_skb_any(skb);
if (net_ratelimit())
netdev_err(ndev, "NOT enough BD for TSO!\n");
return NETDEV_TX_OK;
}
if (fec_enet_clear_csum(skb, ndev)) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
tso_start(skb, &tso);
total_len = skb->len - hdr_len;
while (total_len > 0) {
char *hdr;
index = fec_enet_get_bd_index(bdp, &txq->bd);
data_left = min_t(int, skb_shinfo(skb)->gso_size, total_len);
total_len -= data_left;
hdr = txq->tso_hdrs + index * TSO_HEADER_SIZE;
tso_build_hdr(skb, hdr, &tso, data_left, total_len == 0);
ret = fec_enet_txq_put_hdr_tso(txq, skb, ndev, bdp, index);
if (ret)
goto err_release;
while (data_left > 0) {
int size;
size = min_t(int, tso.size, data_left);
bdp = fec_enet_get_nextdesc(bdp, &txq->bd);
index = fec_enet_get_bd_index(bdp, &txq->bd);
ret = fec_enet_txq_put_data_tso(txq, skb, ndev,
bdp, index,
tso.data, size,
size == data_left,
total_len == 0);
if (ret)
goto err_release;
data_left -= size;
tso_build_data(skb, &tso, size);
}
bdp = fec_enet_get_nextdesc(bdp, &txq->bd);
}
txq->tx_skbuff[index] = skb;
skb_tx_timestamp(skb);
txq->bd.cur = bdp;
if (!(fep->quirks & FEC_QUIRK_ERR007885) ||
!readl(txq->bd.reg_desc_active) ||
!readl(txq->bd.reg_desc_active) ||
!readl(txq->bd.reg_desc_active) ||
!readl(txq->bd.reg_desc_active))
writel(0, txq->bd.reg_desc_active);
return 0;
err_release:
return ret;
}
static netdev_tx_t
fec_enet_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int entries_free;
unsigned short queue;
struct fec_enet_priv_tx_q *txq;
struct netdev_queue *nq;
int ret;
queue = skb_get_queue_mapping(skb);
txq = fep->tx_queue[queue];
nq = netdev_get_tx_queue(ndev, queue);
if (skb_is_gso(skb))
ret = fec_enet_txq_submit_tso(txq, skb, ndev);
else
ret = fec_enet_txq_submit_skb(txq, skb, ndev);
if (ret)
return ret;
entries_free = fec_enet_get_free_txdesc_num(txq);
if (entries_free <= txq->tx_stop_threshold)
netif_tx_stop_queue(nq);
return NETDEV_TX_OK;
}
static void fec_enet_bd_init(struct net_device *dev)
{
struct fec_enet_private *fep = netdev_priv(dev);
struct fec_enet_priv_tx_q *txq;
struct fec_enet_priv_rx_q *rxq;
struct bufdesc *bdp;
unsigned int i;
unsigned int q;
for (q = 0; q < fep->num_rx_queues; q++) {
rxq = fep->rx_queue[q];
bdp = rxq->bd.base;
for (i = 0; i < rxq->bd.ring_size; i++) {
if (bdp->cbd_bufaddr)
bdp->cbd_sc = cpu_to_fec16(BD_ENET_RX_EMPTY);
else
bdp->cbd_sc = cpu_to_fec16(0);
bdp = fec_enet_get_nextdesc(bdp, &rxq->bd);
}
bdp = fec_enet_get_prevdesc(bdp, &rxq->bd);
bdp->cbd_sc |= cpu_to_fec16(BD_SC_WRAP);
rxq->bd.cur = rxq->bd.base;
}
for (q = 0; q < fep->num_tx_queues; q++) {
txq = fep->tx_queue[q];
bdp = txq->bd.base;
txq->bd.cur = bdp;
for (i = 0; i < txq->bd.ring_size; i++) {
bdp->cbd_sc = cpu_to_fec16(0);
if (txq->tx_skbuff[i]) {
dev_kfree_skb_any(txq->tx_skbuff[i]);
txq->tx_skbuff[i] = NULL;
}
bdp->cbd_bufaddr = cpu_to_fec32(0);
bdp = fec_enet_get_nextdesc(bdp, &txq->bd);
}
bdp = fec_enet_get_prevdesc(bdp, &txq->bd);
bdp->cbd_sc |= cpu_to_fec16(BD_SC_WRAP);
txq->dirty_tx = bdp;
}
}
static void fec_enet_active_rxring(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int i;
for (i = 0; i < fep->num_rx_queues; i++)
writel(0, fep->rx_queue[i]->bd.reg_desc_active);
}
static void fec_enet_enable_ring(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct fec_enet_priv_tx_q *txq;
struct fec_enet_priv_rx_q *rxq;
int i;
for (i = 0; i < fep->num_rx_queues; i++) {
rxq = fep->rx_queue[i];
writel(rxq->bd.dma, fep->hwp + FEC_R_DES_START(i));
writel(PKT_MAXBLR_SIZE, fep->hwp + FEC_R_BUFF_SIZE(i));
if (i)
writel(RCMR_MATCHEN | RCMR_CMP(i),
fep->hwp + FEC_RCMR(i));
}
for (i = 0; i < fep->num_tx_queues; i++) {
txq = fep->tx_queue[i];
writel(txq->bd.dma, fep->hwp + FEC_X_DES_START(i));
if (i)
writel(DMA_CLASS_EN | IDLE_SLOPE(i),
fep->hwp + FEC_DMA_CFG(i));
}
}
static void fec_enet_reset_skb(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct fec_enet_priv_tx_q *txq;
int i, j;
for (i = 0; i < fep->num_tx_queues; i++) {
txq = fep->tx_queue[i];
for (j = 0; j < txq->bd.ring_size; j++) {
if (txq->tx_skbuff[j]) {
dev_kfree_skb_any(txq->tx_skbuff[j]);
txq->tx_skbuff[j] = NULL;
}
}
}
}
static void
fec_restart(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
u32 val;
u32 temp_mac[2];
u32 rcntl = OPT_FRAME_SIZE | 0x04;
u32 ecntl = 0x2;
if (fep->quirks & FEC_QUIRK_HAS_AVB) {
writel(0, fep->hwp + FEC_ECNTRL);
} else {
writel(1, fep->hwp + FEC_ECNTRL);
udelay(10);
}
memcpy(&temp_mac, ndev->dev_addr, ETH_ALEN);
writel((__force u32)cpu_to_be32(temp_mac[0]),
fep->hwp + FEC_ADDR_LOW);
writel((__force u32)cpu_to_be32(temp_mac[1]),
fep->hwp + FEC_ADDR_HIGH);
writel(0xffffffff, fep->hwp + FEC_IEVENT);
fec_enet_bd_init(ndev);
fec_enet_enable_ring(ndev);
fec_enet_reset_skb(ndev);
if (fep->full_duplex == DUPLEX_FULL) {
writel(0x04, fep->hwp + FEC_X_CNTRL);
} else {
rcntl |= 0x02;
writel(0x0, fep->hwp + FEC_X_CNTRL);
}
writel(fep->phy_speed, fep->hwp + FEC_MII_SPEED);
#if !defined(CONFIG_M5272)
if (fep->quirks & FEC_QUIRK_HAS_RACC) {
val = readl(fep->hwp + FEC_RACC);
val |= FEC_RACC_SHIFT16;
if (fep->csum_flags & FLAG_RX_CSUM_ENABLED)
val |= FEC_RACC_OPTIONS;
else
val &= ~FEC_RACC_OPTIONS;
writel(val, fep->hwp + FEC_RACC);
writel(PKT_MAXBUF_SIZE, fep->hwp + FEC_FTRL);
}
#endif
if (fep->quirks & FEC_QUIRK_ENET_MAC) {
rcntl |= 0x40000000 | 0x00000020;
if (fep->phy_interface == PHY_INTERFACE_MODE_RGMII ||
fep->phy_interface == PHY_INTERFACE_MODE_RGMII_ID ||
fep->phy_interface == PHY_INTERFACE_MODE_RGMII_RXID ||
fep->phy_interface == PHY_INTERFACE_MODE_RGMII_TXID)
rcntl |= (1 << 6);
else if (fep->phy_interface == PHY_INTERFACE_MODE_RMII)
rcntl |= (1 << 8);
else
rcntl &= ~(1 << 8);
if (ndev->phydev) {
if (ndev->phydev->speed == SPEED_1000)
ecntl |= (1 << 5);
else if (ndev->phydev->speed == SPEED_100)
rcntl &= ~(1 << 9);
else
rcntl |= (1 << 9);
}
} else {
#ifdef FEC_MIIGSK_ENR
if (fep->quirks & FEC_QUIRK_USE_GASKET) {
u32 cfgr;
writel(0, fep->hwp + FEC_MIIGSK_ENR);
while (readl(fep->hwp + FEC_MIIGSK_ENR) & 4)
udelay(1);
cfgr = (fep->phy_interface == PHY_INTERFACE_MODE_RMII)
? BM_MIIGSK_CFGR_RMII : BM_MIIGSK_CFGR_MII;
if (ndev->phydev && ndev->phydev->speed == SPEED_10)
cfgr |= BM_MIIGSK_CFGR_FRCONT_10M;
writel(cfgr, fep->hwp + FEC_MIIGSK_CFGR);
writel(2, fep->hwp + FEC_MIIGSK_ENR);
}
#endif
}
#if !defined(CONFIG_M5272)
if ((fep->pause_flag & FEC_PAUSE_FLAG_ENABLE) ||
((fep->pause_flag & FEC_PAUSE_FLAG_AUTONEG) &&
ndev->phydev && ndev->phydev->pause)) {
rcntl |= FEC_ENET_FCE;
writel(FEC_ENET_RSEM_V, fep->hwp + FEC_R_FIFO_RSEM);
writel(FEC_ENET_RSFL_V, fep->hwp + FEC_R_FIFO_RSFL);
writel(FEC_ENET_RAEM_V, fep->hwp + FEC_R_FIFO_RAEM);
writel(FEC_ENET_RAFL_V, fep->hwp + FEC_R_FIFO_RAFL);
writel(FEC_ENET_OPD_V, fep->hwp + FEC_OPD);
} else {
rcntl &= ~FEC_ENET_FCE;
}
#endif
writel(rcntl, fep->hwp + FEC_R_CNTRL);
set_multicast_list(ndev);
#ifndef CONFIG_M5272
writel(0, fep->hwp + FEC_HASH_TABLE_HIGH);
writel(0, fep->hwp + FEC_HASH_TABLE_LOW);
#endif
if (fep->quirks & FEC_QUIRK_ENET_MAC) {
ecntl |= (1 << 8);
writel(1 << 8, fep->hwp + FEC_X_WMRK);
}
if (fep->bufdesc_ex)
ecntl |= (1 << 4);
#ifndef CONFIG_M5272
writel(0 << 31, fep->hwp + FEC_MIB_CTRLSTAT);
#endif
writel(ecntl, fep->hwp + FEC_ECNTRL);
fec_enet_active_rxring(ndev);
if (fep->bufdesc_ex)
fec_ptp_start_cyclecounter(ndev);
if (fep->link)
writel(FEC_DEFAULT_IMASK, fep->hwp + FEC_IMASK);
else
writel(FEC_ENET_MII, fep->hwp + FEC_IMASK);
fec_enet_itr_coal_init(ndev);
}
static void
fec_stop(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct fec_platform_data *pdata = fep->pdev->dev.platform_data;
u32 rmii_mode = readl(fep->hwp + FEC_R_CNTRL) & (1 << 8);
u32 val;
if (fep->link) {
writel(1, fep->hwp + FEC_X_CNTRL);
udelay(10);
if (!(readl(fep->hwp + FEC_IEVENT) & FEC_ENET_GRA))
netdev_err(ndev, "Graceful transmit stop did not complete!\n");
}
if (!(fep->wol_flag & FEC_WOL_FLAG_SLEEP_ON)) {
if (fep->quirks & FEC_QUIRK_HAS_AVB) {
writel(0, fep->hwp + FEC_ECNTRL);
} else {
writel(1, fep->hwp + FEC_ECNTRL);
udelay(10);
}
writel(FEC_DEFAULT_IMASK, fep->hwp + FEC_IMASK);
} else {
writel(FEC_DEFAULT_IMASK | FEC_ENET_WAKEUP, fep->hwp + FEC_IMASK);
val = readl(fep->hwp + FEC_ECNTRL);
val |= (FEC_ECR_MAGICEN | FEC_ECR_SLEEP);
writel(val, fep->hwp + FEC_ECNTRL);
if (pdata && pdata->sleep_mode_enable)
pdata->sleep_mode_enable(true);
}
writel(fep->phy_speed, fep->hwp + FEC_MII_SPEED);
if (fep->quirks & FEC_QUIRK_ENET_MAC &&
!(fep->wol_flag & FEC_WOL_FLAG_SLEEP_ON)) {
writel(2, fep->hwp + FEC_ECNTRL);
writel(rmii_mode, fep->hwp + FEC_R_CNTRL);
}
}
static void
fec_timeout(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
fec_dump(ndev);
ndev->stats.tx_errors++;
schedule_work(&fep->tx_timeout_work);
}
static void fec_enet_timeout_work(struct work_struct *work)
{
struct fec_enet_private *fep =
container_of(work, struct fec_enet_private, tx_timeout_work);
struct net_device *ndev = fep->netdev;
rtnl_lock();
if (netif_device_present(ndev) || netif_running(ndev)) {
napi_disable(&fep->napi);
netif_tx_lock_bh(ndev);
fec_restart(ndev);
netif_wake_queue(ndev);
netif_tx_unlock_bh(ndev);
napi_enable(&fep->napi);
}
rtnl_unlock();
}
static void
fec_enet_hwtstamp(struct fec_enet_private *fep, unsigned ts,
struct skb_shared_hwtstamps *hwtstamps)
{
unsigned long flags;
u64 ns;
spin_lock_irqsave(&fep->tmreg_lock, flags);
ns = timecounter_cyc2time(&fep->tc, ts);
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
memset(hwtstamps, 0, sizeof(*hwtstamps));
hwtstamps->hwtstamp = ns_to_ktime(ns);
}
static void
fec_enet_tx_queue(struct net_device *ndev, u16 queue_id)
{
struct fec_enet_private *fep;
struct bufdesc *bdp;
unsigned short status;
struct sk_buff *skb;
struct fec_enet_priv_tx_q *txq;
struct netdev_queue *nq;
int index = 0;
int entries_free;
fep = netdev_priv(ndev);
queue_id = FEC_ENET_GET_QUQUE(queue_id);
txq = fep->tx_queue[queue_id];
nq = netdev_get_tx_queue(ndev, queue_id);
bdp = txq->dirty_tx;
bdp = fec_enet_get_nextdesc(bdp, &txq->bd);
while (bdp != READ_ONCE(txq->bd.cur)) {
rmb();
status = fec16_to_cpu(READ_ONCE(bdp->cbd_sc));
if (status & BD_ENET_TX_READY)
break;
index = fec_enet_get_bd_index(bdp, &txq->bd);
skb = txq->tx_skbuff[index];
txq->tx_skbuff[index] = NULL;
if (!IS_TSO_HEADER(txq, fec32_to_cpu(bdp->cbd_bufaddr)))
dma_unmap_single(&fep->pdev->dev,
fec32_to_cpu(bdp->cbd_bufaddr),
fec16_to_cpu(bdp->cbd_datlen),
DMA_TO_DEVICE);
bdp->cbd_bufaddr = cpu_to_fec32(0);
if (!skb)
goto skb_done;
if (status & (BD_ENET_TX_HB | BD_ENET_TX_LC |
BD_ENET_TX_RL | BD_ENET_TX_UN |
BD_ENET_TX_CSL)) {
ndev->stats.tx_errors++;
if (status & BD_ENET_TX_HB)
ndev->stats.tx_heartbeat_errors++;
if (status & BD_ENET_TX_LC)
ndev->stats.tx_window_errors++;
if (status & BD_ENET_TX_RL)
ndev->stats.tx_aborted_errors++;
if (status & BD_ENET_TX_UN)
ndev->stats.tx_fifo_errors++;
if (status & BD_ENET_TX_CSL)
ndev->stats.tx_carrier_errors++;
} else {
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += skb->len;
}
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_IN_PROGRESS) &&
fep->bufdesc_ex) {
struct skb_shared_hwtstamps shhwtstamps;
struct bufdesc_ex *ebdp = (struct bufdesc_ex *)bdp;
fec_enet_hwtstamp(fep, fec32_to_cpu(ebdp->ts), &shhwtstamps);
skb_tstamp_tx(skb, &shhwtstamps);
}
if (status & BD_ENET_TX_DEF)
ndev->stats.collisions++;
dev_kfree_skb_any(skb);
skb_done:
wmb();
txq->dirty_tx = bdp;
bdp = fec_enet_get_nextdesc(bdp, &txq->bd);
if (netif_queue_stopped(ndev)) {
entries_free = fec_enet_get_free_txdesc_num(txq);
if (entries_free >= txq->tx_wake_threshold)
netif_tx_wake_queue(nq);
}
}
if (bdp != txq->bd.cur &&
readl(txq->bd.reg_desc_active) == 0)
writel(0, txq->bd.reg_desc_active);
}
static void
fec_enet_tx(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
u16 queue_id;
for_each_set_bit(queue_id, &fep->work_tx, FEC_ENET_MAX_TX_QS) {
clear_bit(queue_id, &fep->work_tx);
fec_enet_tx_queue(ndev, queue_id);
}
return;
}
static int
fec_enet_new_rxbdp(struct net_device *ndev, struct bufdesc *bdp, struct sk_buff *skb)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int off;
off = ((unsigned long)skb->data) & fep->rx_align;
if (off)
skb_reserve(skb, fep->rx_align + 1 - off);
bdp->cbd_bufaddr = cpu_to_fec32(dma_map_single(&fep->pdev->dev, skb->data, FEC_ENET_RX_FRSIZE - fep->rx_align, DMA_FROM_DEVICE));
if (dma_mapping_error(&fep->pdev->dev, fec32_to_cpu(bdp->cbd_bufaddr))) {
if (net_ratelimit())
netdev_err(ndev, "Rx DMA memory map failed\n");
return -ENOMEM;
}
return 0;
}
static bool fec_enet_copybreak(struct net_device *ndev, struct sk_buff **skb,
struct bufdesc *bdp, u32 length, bool swap)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct sk_buff *new_skb;
if (length > fep->rx_copybreak)
return false;
new_skb = netdev_alloc_skb(ndev, length);
if (!new_skb)
return false;
dma_sync_single_for_cpu(&fep->pdev->dev,
fec32_to_cpu(bdp->cbd_bufaddr),
FEC_ENET_RX_FRSIZE - fep->rx_align,
DMA_FROM_DEVICE);
if (!swap)
memcpy(new_skb->data, (*skb)->data, length);
else
swap_buffer2(new_skb->data, (*skb)->data, length);
*skb = new_skb;
return true;
}
static int
fec_enet_rx_queue(struct net_device *ndev, int budget, u16 queue_id)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct fec_enet_priv_rx_q *rxq;
struct bufdesc *bdp;
unsigned short status;
struct sk_buff *skb_new = NULL;
struct sk_buff *skb;
ushort pkt_len;
__u8 *data;
int pkt_received = 0;
struct bufdesc_ex *ebdp = NULL;
bool vlan_packet_rcvd = false;
u16 vlan_tag;
int index = 0;
bool is_copybreak;
bool need_swap = fep->quirks & FEC_QUIRK_SWAP_FRAME;
#ifdef CONFIG_M532x
flush_cache_all();
#endif
queue_id = FEC_ENET_GET_QUQUE(queue_id);
rxq = fep->rx_queue[queue_id];
bdp = rxq->bd.cur;
while (!((status = fec16_to_cpu(bdp->cbd_sc)) & BD_ENET_RX_EMPTY)) {
if (pkt_received >= budget)
break;
pkt_received++;
writel(FEC_ENET_RXF, fep->hwp + FEC_IEVENT);
status ^= BD_ENET_RX_LAST;
if (status & (BD_ENET_RX_LG | BD_ENET_RX_SH | BD_ENET_RX_NO |
BD_ENET_RX_CR | BD_ENET_RX_OV | BD_ENET_RX_LAST |
BD_ENET_RX_CL)) {
ndev->stats.rx_errors++;
if (status & BD_ENET_RX_OV) {
ndev->stats.rx_fifo_errors++;
goto rx_processing_done;
}
if (status & (BD_ENET_RX_LG | BD_ENET_RX_SH
| BD_ENET_RX_LAST)) {
ndev->stats.rx_length_errors++;
if (status & BD_ENET_RX_LAST)
netdev_err(ndev, "rcv is not +last\n");
}
if (status & BD_ENET_RX_CR)
ndev->stats.rx_crc_errors++;
if (status & (BD_ENET_RX_NO | BD_ENET_RX_CL))
ndev->stats.rx_frame_errors++;
goto rx_processing_done;
}
ndev->stats.rx_packets++;
pkt_len = fec16_to_cpu(bdp->cbd_datlen);
ndev->stats.rx_bytes += pkt_len;
index = fec_enet_get_bd_index(bdp, &rxq->bd);
skb = rxq->rx_skbuff[index];
is_copybreak = fec_enet_copybreak(ndev, &skb, bdp, pkt_len - 4,
need_swap);
if (!is_copybreak) {
skb_new = netdev_alloc_skb(ndev, FEC_ENET_RX_FRSIZE);
if (unlikely(!skb_new)) {
ndev->stats.rx_dropped++;
goto rx_processing_done;
}
dma_unmap_single(&fep->pdev->dev,
fec32_to_cpu(bdp->cbd_bufaddr),
FEC_ENET_RX_FRSIZE - fep->rx_align,
DMA_FROM_DEVICE);
}
prefetch(skb->data - NET_IP_ALIGN);
skb_put(skb, pkt_len - 4);
data = skb->data;
if (!is_copybreak && need_swap)
swap_buffer(data, pkt_len);
#if !defined(CONFIG_M5272)
if (fep->quirks & FEC_QUIRK_HAS_RACC)
data = skb_pull_inline(skb, 2);
#endif
ebdp = NULL;
if (fep->bufdesc_ex)
ebdp = (struct bufdesc_ex *)bdp;
vlan_packet_rcvd = false;
if ((ndev->features & NETIF_F_HW_VLAN_CTAG_RX) &&
fep->bufdesc_ex &&
(ebdp->cbd_esc & cpu_to_fec32(BD_ENET_RX_VLAN))) {
struct vlan_hdr *vlan_header =
(struct vlan_hdr *) (data + ETH_HLEN);
vlan_tag = ntohs(vlan_header->h_vlan_TCI);
vlan_packet_rcvd = true;
memmove(skb->data + VLAN_HLEN, data, ETH_ALEN * 2);
skb_pull(skb, VLAN_HLEN);
}
skb->protocol = eth_type_trans(skb, ndev);
if (fep->hwts_rx_en && fep->bufdesc_ex)
fec_enet_hwtstamp(fep, fec32_to_cpu(ebdp->ts),
skb_hwtstamps(skb));
if (fep->bufdesc_ex &&
(fep->csum_flags & FLAG_RX_CSUM_ENABLED)) {
if (!(ebdp->cbd_esc & cpu_to_fec32(FLAG_RX_CSUM_ERROR))) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
} else {
skb_checksum_none_assert(skb);
}
}
if (vlan_packet_rcvd)
__vlan_hwaccel_put_tag(skb,
htons(ETH_P_8021Q),
vlan_tag);
napi_gro_receive(&fep->napi, skb);
if (is_copybreak) {
dma_sync_single_for_device(&fep->pdev->dev,
fec32_to_cpu(bdp->cbd_bufaddr),
FEC_ENET_RX_FRSIZE - fep->rx_align,
DMA_FROM_DEVICE);
} else {
rxq->rx_skbuff[index] = skb_new;
fec_enet_new_rxbdp(ndev, bdp, skb_new);
}
rx_processing_done:
status &= ~BD_ENET_RX_STATS;
status |= BD_ENET_RX_EMPTY;
if (fep->bufdesc_ex) {
struct bufdesc_ex *ebdp = (struct bufdesc_ex *)bdp;
ebdp->cbd_esc = cpu_to_fec32(BD_ENET_RX_INT);
ebdp->cbd_prot = 0;
ebdp->cbd_bdu = 0;
}
wmb();
bdp->cbd_sc = cpu_to_fec16(status);
bdp = fec_enet_get_nextdesc(bdp, &rxq->bd);
writel(0, rxq->bd.reg_desc_active);
}
rxq->bd.cur = bdp;
return pkt_received;
}
static int
fec_enet_rx(struct net_device *ndev, int budget)
{
int pkt_received = 0;
u16 queue_id;
struct fec_enet_private *fep = netdev_priv(ndev);
for_each_set_bit(queue_id, &fep->work_rx, FEC_ENET_MAX_RX_QS) {
int ret;
ret = fec_enet_rx_queue(ndev,
budget - pkt_received, queue_id);
if (ret < budget - pkt_received)
clear_bit(queue_id, &fep->work_rx);
pkt_received += ret;
}
return pkt_received;
}
static bool
fec_enet_collect_events(struct fec_enet_private *fep, uint int_events)
{
if (int_events == 0)
return false;
if (int_events & FEC_ENET_RXF)
fep->work_rx |= (1 << 2);
if (int_events & FEC_ENET_RXF_1)
fep->work_rx |= (1 << 0);
if (int_events & FEC_ENET_RXF_2)
fep->work_rx |= (1 << 1);
if (int_events & FEC_ENET_TXF)
fep->work_tx |= (1 << 2);
if (int_events & FEC_ENET_TXF_1)
fep->work_tx |= (1 << 0);
if (int_events & FEC_ENET_TXF_2)
fep->work_tx |= (1 << 1);
return true;
}
static irqreturn_t
fec_enet_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = dev_id;
struct fec_enet_private *fep = netdev_priv(ndev);
uint int_events;
irqreturn_t ret = IRQ_NONE;
int_events = readl(fep->hwp + FEC_IEVENT);
writel(int_events, fep->hwp + FEC_IEVENT);
fec_enet_collect_events(fep, int_events);
if ((fep->work_tx || fep->work_rx) && fep->link) {
ret = IRQ_HANDLED;
if (napi_schedule_prep(&fep->napi)) {
writel(FEC_NAPI_IMASK, fep->hwp + FEC_IMASK);
__napi_schedule(&fep->napi);
}
}
if (int_events & FEC_ENET_MII) {
ret = IRQ_HANDLED;
complete(&fep->mdio_done);
}
if (fep->ptp_clock)
fec_ptp_check_pps_event(fep);
return ret;
}
static int fec_enet_rx_napi(struct napi_struct *napi, int budget)
{
struct net_device *ndev = napi->dev;
struct fec_enet_private *fep = netdev_priv(ndev);
int pkts;
pkts = fec_enet_rx(ndev, budget);
fec_enet_tx(ndev);
if (pkts < budget) {
napi_complete_done(napi, pkts);
writel(FEC_DEFAULT_IMASK, fep->hwp + FEC_IMASK);
}
return pkts;
}
static void fec_get_mac(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct fec_platform_data *pdata = dev_get_platdata(&fep->pdev->dev);
unsigned char *iap, tmpaddr[ETH_ALEN];
iap = macaddr;
if (!is_valid_ether_addr(iap)) {
struct device_node *np = fep->pdev->dev.of_node;
if (np) {
const char *mac = of_get_mac_address(np);
if (mac)
iap = (unsigned char *) mac;
}
}
if (!is_valid_ether_addr(iap)) {
#ifdef CONFIG_M5272
if (FEC_FLASHMAC)
iap = (unsigned char *)FEC_FLASHMAC;
#else
if (pdata)
iap = (unsigned char *)&pdata->mac;
#endif
}
if (!is_valid_ether_addr(iap)) {
*((__be32 *) &tmpaddr[0]) =
cpu_to_be32(readl(fep->hwp + FEC_ADDR_LOW));
*((__be16 *) &tmpaddr[4]) =
cpu_to_be16(readl(fep->hwp + FEC_ADDR_HIGH) >> 16);
iap = &tmpaddr[0];
}
if (!is_valid_ether_addr(iap)) {
netdev_err(ndev, "Invalid MAC address: %pM\n", iap);
eth_hw_addr_random(ndev);
netdev_info(ndev, "Using random MAC address: %pM\n",
ndev->dev_addr);
return;
}
memcpy(ndev->dev_addr, iap, ETH_ALEN);
if (iap == macaddr)
ndev->dev_addr[ETH_ALEN-1] = macaddr[ETH_ALEN-1] + fep->dev_id;
}
static void fec_enet_adjust_link(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phy_dev = ndev->phydev;
int status_change = 0;
if (fep->mii_timeout && phy_dev->state == PHY_HALTED) {
phy_dev->state = PHY_RESUMING;
return;
}
if (!netif_running(ndev) || !netif_device_present(ndev)) {
fep->link = 0;
} else if (phy_dev->link) {
if (!fep->link) {
fep->link = phy_dev->link;
status_change = 1;
}
if (fep->full_duplex != phy_dev->duplex) {
fep->full_duplex = phy_dev->duplex;
status_change = 1;
}
if (phy_dev->speed != fep->speed) {
fep->speed = phy_dev->speed;
status_change = 1;
}
if (status_change) {
napi_disable(&fep->napi);
netif_tx_lock_bh(ndev);
fec_restart(ndev);
netif_wake_queue(ndev);
netif_tx_unlock_bh(ndev);
napi_enable(&fep->napi);
}
} else {
if (fep->link) {
napi_disable(&fep->napi);
netif_tx_lock_bh(ndev);
fec_stop(ndev);
netif_tx_unlock_bh(ndev);
napi_enable(&fep->napi);
fep->link = phy_dev->link;
status_change = 1;
}
}
if (status_change)
phy_print_status(phy_dev);
}
static int fec_enet_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
struct fec_enet_private *fep = bus->priv;
struct device *dev = &fep->pdev->dev;
unsigned long time_left;
int ret = 0;
ret = pm_runtime_get_sync(dev);
if (ret < 0)
return ret;
fep->mii_timeout = 0;
reinit_completion(&fep->mdio_done);
writel(FEC_MMFR_ST | FEC_MMFR_OP_READ |
FEC_MMFR_PA(mii_id) | FEC_MMFR_RA(regnum) |
FEC_MMFR_TA, fep->hwp + FEC_MII_DATA);
time_left = wait_for_completion_timeout(&fep->mdio_done,
usecs_to_jiffies(FEC_MII_TIMEOUT));
if (time_left == 0) {
fep->mii_timeout = 1;
netdev_err(fep->netdev, "MDIO read timeout\n");
ret = -ETIMEDOUT;
goto out;
}
ret = FEC_MMFR_DATA(readl(fep->hwp + FEC_MII_DATA));
out:
pm_runtime_mark_last_busy(dev);
pm_runtime_put_autosuspend(dev);
return ret;
}
static int fec_enet_mdio_write(struct mii_bus *bus, int mii_id, int regnum,
u16 value)
{
struct fec_enet_private *fep = bus->priv;
struct device *dev = &fep->pdev->dev;
unsigned long time_left;
int ret;
ret = pm_runtime_get_sync(dev);
if (ret < 0)
return ret;
else
ret = 0;
fep->mii_timeout = 0;
reinit_completion(&fep->mdio_done);
writel(FEC_MMFR_ST | FEC_MMFR_OP_WRITE |
FEC_MMFR_PA(mii_id) | FEC_MMFR_RA(regnum) |
FEC_MMFR_TA | FEC_MMFR_DATA(value),
fep->hwp + FEC_MII_DATA);
time_left = wait_for_completion_timeout(&fep->mdio_done,
usecs_to_jiffies(FEC_MII_TIMEOUT));
if (time_left == 0) {
fep->mii_timeout = 1;
netdev_err(fep->netdev, "MDIO write timeout\n");
ret = -ETIMEDOUT;
}
pm_runtime_mark_last_busy(dev);
pm_runtime_put_autosuspend(dev);
return ret;
}
static int fec_enet_clk_enable(struct net_device *ndev, bool enable)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int ret;
if (enable) {
ret = clk_prepare_enable(fep->clk_ahb);
if (ret)
return ret;
ret = clk_prepare_enable(fep->clk_enet_out);
if (ret)
goto failed_clk_enet_out;
if (fep->clk_ptp) {
mutex_lock(&fep->ptp_clk_mutex);
ret = clk_prepare_enable(fep->clk_ptp);
if (ret) {
mutex_unlock(&fep->ptp_clk_mutex);
goto failed_clk_ptp;
} else {
fep->ptp_clk_on = true;
}
mutex_unlock(&fep->ptp_clk_mutex);
}
ret = clk_prepare_enable(fep->clk_ref);
if (ret)
goto failed_clk_ref;
} else {
clk_disable_unprepare(fep->clk_ahb);
clk_disable_unprepare(fep->clk_enet_out);
if (fep->clk_ptp) {
mutex_lock(&fep->ptp_clk_mutex);
clk_disable_unprepare(fep->clk_ptp);
fep->ptp_clk_on = false;
mutex_unlock(&fep->ptp_clk_mutex);
}
clk_disable_unprepare(fep->clk_ref);
}
return 0;
failed_clk_ref:
if (fep->clk_ref)
clk_disable_unprepare(fep->clk_ref);
failed_clk_ptp:
if (fep->clk_enet_out)
clk_disable_unprepare(fep->clk_enet_out);
failed_clk_enet_out:
clk_disable_unprepare(fep->clk_ahb);
return ret;
}
static int fec_enet_mii_probe(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phy_dev = NULL;
char mdio_bus_id[MII_BUS_ID_SIZE];
char phy_name[MII_BUS_ID_SIZE + 3];
int phy_id;
int dev_id = fep->dev_id;
if (fep->phy_node) {
phy_dev = of_phy_connect(ndev, fep->phy_node,
&fec_enet_adjust_link, 0,
fep->phy_interface);
if (!phy_dev)
return -ENODEV;
} else {
for (phy_id = 0; (phy_id < PHY_MAX_ADDR); phy_id++) {
if (!mdiobus_is_registered_device(fep->mii_bus, phy_id))
continue;
if (dev_id--)
continue;
strlcpy(mdio_bus_id, fep->mii_bus->id, MII_BUS_ID_SIZE);
break;
}
if (phy_id >= PHY_MAX_ADDR) {
netdev_info(ndev, "no PHY, assuming direct connection to switch\n");
strlcpy(mdio_bus_id, "fixed-0", MII_BUS_ID_SIZE);
phy_id = 0;
}
snprintf(phy_name, sizeof(phy_name),
PHY_ID_FMT, mdio_bus_id, phy_id);
phy_dev = phy_connect(ndev, phy_name, &fec_enet_adjust_link,
fep->phy_interface);
}
if (IS_ERR(phy_dev)) {
netdev_err(ndev, "could not attach to PHY\n");
return PTR_ERR(phy_dev);
}
if (fep->quirks & FEC_QUIRK_HAS_GBIT) {
phy_dev->supported &= PHY_GBIT_FEATURES;
phy_dev->supported &= ~SUPPORTED_1000baseT_Half;
#if !defined(CONFIG_M5272)
phy_dev->supported |= SUPPORTED_Pause;
#endif
}
else
phy_dev->supported &= PHY_BASIC_FEATURES;
phy_dev->advertising = phy_dev->supported;
fep->link = 0;
fep->full_duplex = 0;
phy_attached_info(phy_dev);
return 0;
}
static int fec_enet_mii_init(struct platform_device *pdev)
{
static struct mii_bus *fec0_mii_bus;
struct net_device *ndev = platform_get_drvdata(pdev);
struct fec_enet_private *fep = netdev_priv(ndev);
struct device_node *node;
int err = -ENXIO;
u32 mii_speed, holdtime;
if ((fep->quirks & FEC_QUIRK_SINGLE_MDIO) && fep->dev_id > 0) {
if (mii_cnt && fec0_mii_bus) {
fep->mii_bus = fec0_mii_bus;
mii_cnt++;
return 0;
}
return -ENOENT;
}
fep->mii_timeout = 0;
mii_speed = DIV_ROUND_UP(clk_get_rate(fep->clk_ipg), 5000000);
if (fep->quirks & FEC_QUIRK_ENET_MAC)
mii_speed--;
if (mii_speed > 63) {
dev_err(&pdev->dev,
"fec clock (%lu) too fast to get right mii speed\n",
clk_get_rate(fep->clk_ipg));
err = -EINVAL;
goto err_out;
}
holdtime = DIV_ROUND_UP(clk_get_rate(fep->clk_ipg), 100000000) - 1;
fep->phy_speed = mii_speed << 1 | holdtime << 8;
writel(fep->phy_speed, fep->hwp + FEC_MII_SPEED);
fep->mii_bus = mdiobus_alloc();
if (fep->mii_bus == NULL) {
err = -ENOMEM;
goto err_out;
}
fep->mii_bus->name = "fec_enet_mii_bus";
fep->mii_bus->read = fec_enet_mdio_read;
fep->mii_bus->write = fec_enet_mdio_write;
snprintf(fep->mii_bus->id, MII_BUS_ID_SIZE, "%s-%x",
pdev->name, fep->dev_id + 1);
fep->mii_bus->priv = fep;
fep->mii_bus->parent = &pdev->dev;
node = of_get_child_by_name(pdev->dev.of_node, "mdio");
if (node) {
err = of_mdiobus_register(fep->mii_bus, node);
of_node_put(node);
} else {
err = mdiobus_register(fep->mii_bus);
}
if (err)
goto err_out_free_mdiobus;
mii_cnt++;
if (fep->quirks & FEC_QUIRK_SINGLE_MDIO)
fec0_mii_bus = fep->mii_bus;
return 0;
err_out_free_mdiobus:
mdiobus_free(fep->mii_bus);
err_out:
return err;
}
static void fec_enet_mii_remove(struct fec_enet_private *fep)
{
if (--mii_cnt == 0) {
mdiobus_unregister(fep->mii_bus);
mdiobus_free(fep->mii_bus);
}
}
static void fec_enet_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
struct fec_enet_private *fep = netdev_priv(ndev);
strlcpy(info->driver, fep->pdev->dev.driver->name,
sizeof(info->driver));
strlcpy(info->version, "Revision: 1.0", sizeof(info->version));
strlcpy(info->bus_info, dev_name(&ndev->dev), sizeof(info->bus_info));
}
static int fec_enet_get_regs_len(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct resource *r;
int s = 0;
r = platform_get_resource(fep->pdev, IORESOURCE_MEM, 0);
if (r)
s = resource_size(r);
return s;
}
static void fec_enet_get_regs(struct net_device *ndev,
struct ethtool_regs *regs, void *regbuf)
{
struct fec_enet_private *fep = netdev_priv(ndev);
u32 __iomem *theregs = (u32 __iomem *)fep->hwp;
u32 *buf = (u32 *)regbuf;
u32 i, off;
memset(buf, 0, regs->len);
for (i = 0; i < ARRAY_SIZE(fec_enet_register_offset); i++) {
off = fec_enet_register_offset[i] / 4;
buf[off] = readl(&theregs[off]);
}
}
static int fec_enet_get_ts_info(struct net_device *ndev,
struct ethtool_ts_info *info)
{
struct fec_enet_private *fep = netdev_priv(ndev);
if (fep->bufdesc_ex) {
info->so_timestamping = SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE |
SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
if (fep->ptp_clock)
info->phc_index = ptp_clock_index(fep->ptp_clock);
else
info->phc_index = -1;
info->tx_types = (1 << HWTSTAMP_TX_OFF) |
(1 << HWTSTAMP_TX_ON);
info->rx_filters = (1 << HWTSTAMP_FILTER_NONE) |
(1 << HWTSTAMP_FILTER_ALL);
return 0;
} else {
return ethtool_op_get_ts_info(ndev, info);
}
}
static void fec_enet_get_pauseparam(struct net_device *ndev,
struct ethtool_pauseparam *pause)
{
struct fec_enet_private *fep = netdev_priv(ndev);
pause->autoneg = (fep->pause_flag & FEC_PAUSE_FLAG_AUTONEG) != 0;
pause->tx_pause = (fep->pause_flag & FEC_PAUSE_FLAG_ENABLE) != 0;
pause->rx_pause = pause->tx_pause;
}
static int fec_enet_set_pauseparam(struct net_device *ndev,
struct ethtool_pauseparam *pause)
{
struct fec_enet_private *fep = netdev_priv(ndev);
if (!ndev->phydev)
return -ENODEV;
if (pause->tx_pause != pause->rx_pause) {
netdev_info(ndev,
"hardware only support enable/disable both tx and rx");
return -EINVAL;
}
fep->pause_flag = 0;
fep->pause_flag |= pause->rx_pause ? FEC_PAUSE_FLAG_ENABLE : 0;
fep->pause_flag |= pause->autoneg ? FEC_PAUSE_FLAG_AUTONEG : 0;
if (pause->rx_pause || pause->autoneg) {
ndev->phydev->supported |= ADVERTISED_Pause;
ndev->phydev->advertising |= ADVERTISED_Pause;
} else {
ndev->phydev->supported &= ~ADVERTISED_Pause;
ndev->phydev->advertising &= ~ADVERTISED_Pause;
}
if (pause->autoneg) {
if (netif_running(ndev))
fec_stop(ndev);
phy_start_aneg(ndev->phydev);
}
if (netif_running(ndev)) {
napi_disable(&fep->napi);
netif_tx_lock_bh(ndev);
fec_restart(ndev);
netif_wake_queue(ndev);
netif_tx_unlock_bh(ndev);
napi_enable(&fep->napi);
}
return 0;
}
static void fec_enet_update_ethtool_stats(struct net_device *dev)
{
struct fec_enet_private *fep = netdev_priv(dev);
int i;
for (i = 0; i < ARRAY_SIZE(fec_stats); i++)
fep->ethtool_stats[i] = readl(fep->hwp + fec_stats[i].offset);
}
static void fec_enet_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct fec_enet_private *fep = netdev_priv(dev);
if (netif_running(dev))
fec_enet_update_ethtool_stats(dev);
memcpy(data, fep->ethtool_stats, FEC_STATS_SIZE);
}
static void fec_enet_get_strings(struct net_device *netdev,
u32 stringset, u8 *data)
{
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < ARRAY_SIZE(fec_stats); i++)
memcpy(data + i * ETH_GSTRING_LEN,
fec_stats[i].name, ETH_GSTRING_LEN);
break;
}
}
static int fec_enet_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(fec_stats);
default:
return -EOPNOTSUPP;
}
}
static void fec_enet_clear_ethtool_stats(struct net_device *dev)
{
struct fec_enet_private *fep = netdev_priv(dev);
int i;
writel(FEC_MIB_CTRLSTAT_DISABLE, fep->hwp + FEC_MIB_CTRLSTAT);
for (i = 0; i < ARRAY_SIZE(fec_stats); i++)
writel(0, fep->hwp + fec_stats[i].offset);
writel(0, fep->hwp + FEC_MIB_CTRLSTAT);
}
static inline void fec_enet_update_ethtool_stats(struct net_device *dev)
{
}
static inline void fec_enet_clear_ethtool_stats(struct net_device *dev)
{
}
static int fec_enet_us_to_itr_clock(struct net_device *ndev, int us)
{
struct fec_enet_private *fep = netdev_priv(ndev);
return us * (fep->itr_clk_rate / 64000) / 1000;
}
static void fec_enet_itr_coal_set(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int rx_itr, tx_itr;
if (!fep->rx_time_itr || !fep->rx_pkts_itr ||
!fep->tx_time_itr || !fep->tx_pkts_itr)
return;
rx_itr = FEC_ITR_CLK_SEL;
tx_itr = FEC_ITR_CLK_SEL;
rx_itr |= FEC_ITR_ICFT(fep->rx_pkts_itr);
rx_itr |= FEC_ITR_ICTT(fec_enet_us_to_itr_clock(ndev, fep->rx_time_itr));
tx_itr |= FEC_ITR_ICFT(fep->tx_pkts_itr);
tx_itr |= FEC_ITR_ICTT(fec_enet_us_to_itr_clock(ndev, fep->tx_time_itr));
rx_itr |= FEC_ITR_EN;
tx_itr |= FEC_ITR_EN;
writel(tx_itr, fep->hwp + FEC_TXIC0);
writel(rx_itr, fep->hwp + FEC_RXIC0);
if (fep->quirks & FEC_QUIRK_HAS_AVB) {
writel(tx_itr, fep->hwp + FEC_TXIC1);
writel(rx_itr, fep->hwp + FEC_RXIC1);
writel(tx_itr, fep->hwp + FEC_TXIC2);
writel(rx_itr, fep->hwp + FEC_RXIC2);
}
}
static int
fec_enet_get_coalesce(struct net_device *ndev, struct ethtool_coalesce *ec)
{
struct fec_enet_private *fep = netdev_priv(ndev);
if (!(fep->quirks & FEC_QUIRK_HAS_COALESCE))
return -EOPNOTSUPP;
ec->rx_coalesce_usecs = fep->rx_time_itr;
ec->rx_max_coalesced_frames = fep->rx_pkts_itr;
ec->tx_coalesce_usecs = fep->tx_time_itr;
ec->tx_max_coalesced_frames = fep->tx_pkts_itr;
return 0;
}
static int
fec_enet_set_coalesce(struct net_device *ndev, struct ethtool_coalesce *ec)
{
struct fec_enet_private *fep = netdev_priv(ndev);
unsigned int cycle;
if (!(fep->quirks & FEC_QUIRK_HAS_COALESCE))
return -EOPNOTSUPP;
if (ec->rx_max_coalesced_frames > 255) {
pr_err("Rx coalesced frames exceed hardware limitation\n");
return -EINVAL;
}
if (ec->tx_max_coalesced_frames > 255) {
pr_err("Tx coalesced frame exceed hardware limitation\n");
return -EINVAL;
}
cycle = fec_enet_us_to_itr_clock(ndev, fep->rx_time_itr);
if (cycle > 0xFFFF) {
pr_err("Rx coalesced usec exceed hardware limitation\n");
return -EINVAL;
}
cycle = fec_enet_us_to_itr_clock(ndev, fep->tx_time_itr);
if (cycle > 0xFFFF) {
pr_err("Rx coalesced usec exceed hardware limitation\n");
return -EINVAL;
}
fep->rx_time_itr = ec->rx_coalesce_usecs;
fep->rx_pkts_itr = ec->rx_max_coalesced_frames;
fep->tx_time_itr = ec->tx_coalesce_usecs;
fep->tx_pkts_itr = ec->tx_max_coalesced_frames;
fec_enet_itr_coal_set(ndev);
return 0;
}
static void fec_enet_itr_coal_init(struct net_device *ndev)
{
struct ethtool_coalesce ec;
ec.rx_coalesce_usecs = FEC_ITR_ICTT_DEFAULT;
ec.rx_max_coalesced_frames = FEC_ITR_ICFT_DEFAULT;
ec.tx_coalesce_usecs = FEC_ITR_ICTT_DEFAULT;
ec.tx_max_coalesced_frames = FEC_ITR_ICFT_DEFAULT;
fec_enet_set_coalesce(ndev, &ec);
}
static int fec_enet_get_tunable(struct net_device *netdev,
const struct ethtool_tunable *tuna,
void *data)
{
struct fec_enet_private *fep = netdev_priv(netdev);
int ret = 0;
switch (tuna->id) {
case ETHTOOL_RX_COPYBREAK:
*(u32 *)data = fep->rx_copybreak;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int fec_enet_set_tunable(struct net_device *netdev,
const struct ethtool_tunable *tuna,
const void *data)
{
struct fec_enet_private *fep = netdev_priv(netdev);
int ret = 0;
switch (tuna->id) {
case ETHTOOL_RX_COPYBREAK:
fep->rx_copybreak = *(u32 *)data;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static void
fec_enet_get_wol(struct net_device *ndev, struct ethtool_wolinfo *wol)
{
struct fec_enet_private *fep = netdev_priv(ndev);
if (fep->wol_flag & FEC_WOL_HAS_MAGIC_PACKET) {
wol->supported = WAKE_MAGIC;
wol->wolopts = fep->wol_flag & FEC_WOL_FLAG_ENABLE ? WAKE_MAGIC : 0;
} else {
wol->supported = wol->wolopts = 0;
}
}
static int
fec_enet_set_wol(struct net_device *ndev, struct ethtool_wolinfo *wol)
{
struct fec_enet_private *fep = netdev_priv(ndev);
if (!(fep->wol_flag & FEC_WOL_HAS_MAGIC_PACKET))
return -EINVAL;
if (wol->wolopts & ~WAKE_MAGIC)
return -EINVAL;
device_set_wakeup_enable(&ndev->dev, wol->wolopts & WAKE_MAGIC);
if (device_may_wakeup(&ndev->dev)) {
fep->wol_flag |= FEC_WOL_FLAG_ENABLE;
if (fep->irq[0] > 0)
enable_irq_wake(fep->irq[0]);
} else {
fep->wol_flag &= (~FEC_WOL_FLAG_ENABLE);
if (fep->irq[0] > 0)
disable_irq_wake(fep->irq[0]);
}
return 0;
}
static int fec_enet_ioctl(struct net_device *ndev, struct ifreq *rq, int cmd)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phydev = ndev->phydev;
if (!netif_running(ndev))
return -EINVAL;
if (!phydev)
return -ENODEV;
if (fep->bufdesc_ex) {
if (cmd == SIOCSHWTSTAMP)
return fec_ptp_set(ndev, rq);
if (cmd == SIOCGHWTSTAMP)
return fec_ptp_get(ndev, rq);
}
return phy_mii_ioctl(phydev, rq, cmd);
}
static void fec_enet_free_buffers(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
unsigned int i;
struct sk_buff *skb;
struct bufdesc *bdp;
struct fec_enet_priv_tx_q *txq;
struct fec_enet_priv_rx_q *rxq;
unsigned int q;
for (q = 0; q < fep->num_rx_queues; q++) {
rxq = fep->rx_queue[q];
bdp = rxq->bd.base;
for (i = 0; i < rxq->bd.ring_size; i++) {
skb = rxq->rx_skbuff[i];
rxq->rx_skbuff[i] = NULL;
if (skb) {
dma_unmap_single(&fep->pdev->dev,
fec32_to_cpu(bdp->cbd_bufaddr),
FEC_ENET_RX_FRSIZE - fep->rx_align,
DMA_FROM_DEVICE);
dev_kfree_skb(skb);
}
bdp = fec_enet_get_nextdesc(bdp, &rxq->bd);
}
}
for (q = 0; q < fep->num_tx_queues; q++) {
txq = fep->tx_queue[q];
bdp = txq->bd.base;
for (i = 0; i < txq->bd.ring_size; i++) {
kfree(txq->tx_bounce[i]);
txq->tx_bounce[i] = NULL;
skb = txq->tx_skbuff[i];
txq->tx_skbuff[i] = NULL;
dev_kfree_skb(skb);
}
}
}
static void fec_enet_free_queue(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int i;
struct fec_enet_priv_tx_q *txq;
for (i = 0; i < fep->num_tx_queues; i++)
if (fep->tx_queue[i] && fep->tx_queue[i]->tso_hdrs) {
txq = fep->tx_queue[i];
dma_free_coherent(&fep->pdev->dev,
txq->bd.ring_size * TSO_HEADER_SIZE,
txq->tso_hdrs,
txq->tso_hdrs_dma);
}
for (i = 0; i < fep->num_rx_queues; i++)
kfree(fep->rx_queue[i]);
for (i = 0; i < fep->num_tx_queues; i++)
kfree(fep->tx_queue[i]);
}
static int fec_enet_alloc_queue(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int i;
int ret = 0;
struct fec_enet_priv_tx_q *txq;
for (i = 0; i < fep->num_tx_queues; i++) {
txq = kzalloc(sizeof(*txq), GFP_KERNEL);
if (!txq) {
ret = -ENOMEM;
goto alloc_failed;
}
fep->tx_queue[i] = txq;
txq->bd.ring_size = TX_RING_SIZE;
fep->total_tx_ring_size += fep->tx_queue[i]->bd.ring_size;
txq->tx_stop_threshold = FEC_MAX_SKB_DESCS;
txq->tx_wake_threshold =
(txq->bd.ring_size - txq->tx_stop_threshold) / 2;
txq->tso_hdrs = dma_alloc_coherent(&fep->pdev->dev,
txq->bd.ring_size * TSO_HEADER_SIZE,
&txq->tso_hdrs_dma,
GFP_KERNEL);
if (!txq->tso_hdrs) {
ret = -ENOMEM;
goto alloc_failed;
}
}
for (i = 0; i < fep->num_rx_queues; i++) {
fep->rx_queue[i] = kzalloc(sizeof(*fep->rx_queue[i]),
GFP_KERNEL);
if (!fep->rx_queue[i]) {
ret = -ENOMEM;
goto alloc_failed;
}
fep->rx_queue[i]->bd.ring_size = RX_RING_SIZE;
fep->total_rx_ring_size += fep->rx_queue[i]->bd.ring_size;
}
return ret;
alloc_failed:
fec_enet_free_queue(ndev);
return ret;
}
static int
fec_enet_alloc_rxq_buffers(struct net_device *ndev, unsigned int queue)
{
struct fec_enet_private *fep = netdev_priv(ndev);
unsigned int i;
struct sk_buff *skb;
struct bufdesc *bdp;
struct fec_enet_priv_rx_q *rxq;
rxq = fep->rx_queue[queue];
bdp = rxq->bd.base;
for (i = 0; i < rxq->bd.ring_size; i++) {
skb = netdev_alloc_skb(ndev, FEC_ENET_RX_FRSIZE);
if (!skb)
goto err_alloc;
if (fec_enet_new_rxbdp(ndev, bdp, skb)) {
dev_kfree_skb(skb);
goto err_alloc;
}
rxq->rx_skbuff[i] = skb;
bdp->cbd_sc = cpu_to_fec16(BD_ENET_RX_EMPTY);
if (fep->bufdesc_ex) {
struct bufdesc_ex *ebdp = (struct bufdesc_ex *)bdp;
ebdp->cbd_esc = cpu_to_fec32(BD_ENET_RX_INT);
}
bdp = fec_enet_get_nextdesc(bdp, &rxq->bd);
}
bdp = fec_enet_get_prevdesc(bdp, &rxq->bd);
bdp->cbd_sc |= cpu_to_fec16(BD_SC_WRAP);
return 0;
err_alloc:
fec_enet_free_buffers(ndev);
return -ENOMEM;
}
static int
fec_enet_alloc_txq_buffers(struct net_device *ndev, unsigned int queue)
{
struct fec_enet_private *fep = netdev_priv(ndev);
unsigned int i;
struct bufdesc *bdp;
struct fec_enet_priv_tx_q *txq;
txq = fep->tx_queue[queue];
bdp = txq->bd.base;
for (i = 0; i < txq->bd.ring_size; i++) {
txq->tx_bounce[i] = kmalloc(FEC_ENET_TX_FRSIZE, GFP_KERNEL);
if (!txq->tx_bounce[i])
goto err_alloc;
bdp->cbd_sc = cpu_to_fec16(0);
bdp->cbd_bufaddr = cpu_to_fec32(0);
if (fep->bufdesc_ex) {
struct bufdesc_ex *ebdp = (struct bufdesc_ex *)bdp;
ebdp->cbd_esc = cpu_to_fec32(BD_ENET_TX_INT);
}
bdp = fec_enet_get_nextdesc(bdp, &txq->bd);
}
bdp = fec_enet_get_prevdesc(bdp, &txq->bd);
bdp->cbd_sc |= cpu_to_fec16(BD_SC_WRAP);
return 0;
err_alloc:
fec_enet_free_buffers(ndev);
return -ENOMEM;
}
static int fec_enet_alloc_buffers(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
unsigned int i;
for (i = 0; i < fep->num_rx_queues; i++)
if (fec_enet_alloc_rxq_buffers(ndev, i))
return -ENOMEM;
for (i = 0; i < fep->num_tx_queues; i++)
if (fec_enet_alloc_txq_buffers(ndev, i))
return -ENOMEM;
return 0;
}
static int
fec_enet_open(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int ret;
ret = pm_runtime_get_sync(&fep->pdev->dev);
if (ret < 0)
return ret;
pinctrl_pm_select_default_state(&fep->pdev->dev);
ret = fec_enet_clk_enable(ndev, true);
if (ret)
goto clk_enable;
ret = fec_enet_alloc_buffers(ndev);
if (ret)
goto err_enet_alloc;
fec_restart(ndev);
ret = fec_enet_mii_probe(ndev);
if (ret)
goto err_enet_mii_probe;
if (fep->quirks & FEC_QUIRK_ERR006687)
imx6q_cpuidle_fec_irqs_used();
napi_enable(&fep->napi);
phy_start(ndev->phydev);
netif_tx_start_all_queues(ndev);
device_set_wakeup_enable(&ndev->dev, fep->wol_flag &
FEC_WOL_FLAG_ENABLE);
return 0;
err_enet_mii_probe:
fec_enet_free_buffers(ndev);
err_enet_alloc:
fec_enet_clk_enable(ndev, false);
clk_enable:
pm_runtime_mark_last_busy(&fep->pdev->dev);
pm_runtime_put_autosuspend(&fep->pdev->dev);
pinctrl_pm_select_sleep_state(&fep->pdev->dev);
return ret;
}
static int
fec_enet_close(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
phy_stop(ndev->phydev);
if (netif_device_present(ndev)) {
napi_disable(&fep->napi);
netif_tx_disable(ndev);
fec_stop(ndev);
}
phy_disconnect(ndev->phydev);
if (fep->quirks & FEC_QUIRK_ERR006687)
imx6q_cpuidle_fec_irqs_unused();
fec_enet_update_ethtool_stats(ndev);
fec_enet_clk_enable(ndev, false);
pinctrl_pm_select_sleep_state(&fep->pdev->dev);
pm_runtime_mark_last_busy(&fep->pdev->dev);
pm_runtime_put_autosuspend(&fep->pdev->dev);
fec_enet_free_buffers(ndev);
return 0;
}
static void set_multicast_list(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct netdev_hw_addr *ha;
unsigned int i, bit, data, crc, tmp;
unsigned char hash;
unsigned int hash_high = 0, hash_low = 0;
if (ndev->flags & IFF_PROMISC) {
tmp = readl(fep->hwp + FEC_R_CNTRL);
tmp |= 0x8;
writel(tmp, fep->hwp + FEC_R_CNTRL);
return;
}
tmp = readl(fep->hwp + FEC_R_CNTRL);
tmp &= ~0x8;
writel(tmp, fep->hwp + FEC_R_CNTRL);
if (ndev->flags & IFF_ALLMULTI) {
writel(0xffffffff, fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
writel(0xffffffff, fep->hwp + FEC_GRP_HASH_TABLE_LOW);
return;
}
netdev_for_each_mc_addr(ha, ndev) {
crc = 0xffffffff;
for (i = 0; i < ndev->addr_len; i++) {
data = ha->addr[i];
for (bit = 0; bit < 8; bit++, data >>= 1) {
crc = (crc >> 1) ^
(((crc ^ data) & 1) ? CRC32_POLY : 0);
}
}
hash = (crc >> (32 - FEC_HASH_BITS)) & 0x3f;
if (hash > 31)
hash_high |= 1 << (hash - 32);
else
hash_low |= 1 << hash;
}
writel(hash_high, fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
writel(hash_low, fep->hwp + FEC_GRP_HASH_TABLE_LOW);
}
static int
fec_set_mac_address(struct net_device *ndev, void *p)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct sockaddr *addr = p;
if (addr) {
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(ndev->dev_addr, addr->sa_data, ndev->addr_len);
}
if (!netif_running(ndev))
return 0;
writel(ndev->dev_addr[3] | (ndev->dev_addr[2] << 8) |
(ndev->dev_addr[1] << 16) | (ndev->dev_addr[0] << 24),
fep->hwp + FEC_ADDR_LOW);
writel((ndev->dev_addr[5] << 16) | (ndev->dev_addr[4] << 24),
fep->hwp + FEC_ADDR_HIGH);
return 0;
}
static void fec_poll_controller(struct net_device *dev)
{
int i;
struct fec_enet_private *fep = netdev_priv(dev);
for (i = 0; i < FEC_IRQ_NUM; i++) {
if (fep->irq[i] > 0) {
disable_irq(fep->irq[i]);
fec_enet_interrupt(fep->irq[i], dev);
enable_irq(fep->irq[i]);
}
}
}
static inline void fec_enet_set_netdev_features(struct net_device *netdev,
netdev_features_t features)
{
struct fec_enet_private *fep = netdev_priv(netdev);
netdev_features_t changed = features ^ netdev->features;
netdev->features = features;
if (changed & NETIF_F_RXCSUM) {
if (features & NETIF_F_RXCSUM)
fep->csum_flags |= FLAG_RX_CSUM_ENABLED;
else
fep->csum_flags &= ~FLAG_RX_CSUM_ENABLED;
}
}
static int fec_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct fec_enet_private *fep = netdev_priv(netdev);
netdev_features_t changed = features ^ netdev->features;
if (netif_running(netdev) && changed & NETIF_F_RXCSUM) {
napi_disable(&fep->napi);
netif_tx_lock_bh(netdev);
fec_stop(netdev);
fec_enet_set_netdev_features(netdev, features);
fec_restart(netdev);
netif_tx_wake_all_queues(netdev);
netif_tx_unlock_bh(netdev);
napi_enable(&fep->napi);
} else {
fec_enet_set_netdev_features(netdev, features);
}
return 0;
}
static int fec_enet_init(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct bufdesc *cbd_base;
dma_addr_t bd_dma;
int bd_size;
unsigned int i;
unsigned dsize = fep->bufdesc_ex ? sizeof(struct bufdesc_ex) :
sizeof(struct bufdesc);
unsigned dsize_log2 = __fls(dsize);
WARN_ON(dsize != (1 << dsize_log2));
#if defined(CONFIG_ARM)
fep->rx_align = 0xf;
fep->tx_align = 0xf;
#else
fep->rx_align = 0x3;
fep->tx_align = 0x3;
#endif
fec_enet_alloc_queue(ndev);
bd_size = (fep->total_tx_ring_size + fep->total_rx_ring_size) * dsize;
cbd_base = dmam_alloc_coherent(&fep->pdev->dev, bd_size, &bd_dma,
GFP_KERNEL);
if (!cbd_base) {
return -ENOMEM;
}
memset(cbd_base, 0, bd_size);
fec_get_mac(ndev);
fec_set_mac_address(ndev, NULL);
for (i = 0; i < fep->num_rx_queues; i++) {
struct fec_enet_priv_rx_q *rxq = fep->rx_queue[i];
unsigned size = dsize * rxq->bd.ring_size;
rxq->bd.qid = i;
rxq->bd.base = cbd_base;
rxq->bd.cur = cbd_base;
rxq->bd.dma = bd_dma;
rxq->bd.dsize = dsize;
rxq->bd.dsize_log2 = dsize_log2;
rxq->bd.reg_desc_active = fep->hwp + offset_des_active_rxq[i];
bd_dma += size;
cbd_base = (struct bufdesc *)(((void *)cbd_base) + size);
rxq->bd.last = (struct bufdesc *)(((void *)cbd_base) - dsize);
}
for (i = 0; i < fep->num_tx_queues; i++) {
struct fec_enet_priv_tx_q *txq = fep->tx_queue[i];
unsigned size = dsize * txq->bd.ring_size;
txq->bd.qid = i;
txq->bd.base = cbd_base;
txq->bd.cur = cbd_base;
txq->bd.dma = bd_dma;
txq->bd.dsize = dsize;
txq->bd.dsize_log2 = dsize_log2;
txq->bd.reg_desc_active = fep->hwp + offset_des_active_txq[i];
bd_dma += size;
cbd_base = (struct bufdesc *)(((void *)cbd_base) + size);
txq->bd.last = (struct bufdesc *)(((void *)cbd_base) - dsize);
}
ndev->watchdog_timeo = TX_TIMEOUT;
ndev->netdev_ops = &fec_netdev_ops;
ndev->ethtool_ops = &fec_enet_ethtool_ops;
writel(FEC_RX_DISABLED_IMASK, fep->hwp + FEC_IMASK);
netif_napi_add(ndev, &fep->napi, fec_enet_rx_napi, NAPI_POLL_WEIGHT);
if (fep->quirks & FEC_QUIRK_HAS_VLAN)
ndev->features |= NETIF_F_HW_VLAN_CTAG_RX;
if (fep->quirks & FEC_QUIRK_HAS_CSUM) {
ndev->gso_max_segs = FEC_MAX_TSO_SEGS;
ndev->features |= (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM
| NETIF_F_RXCSUM | NETIF_F_SG | NETIF_F_TSO);
fep->csum_flags |= FLAG_RX_CSUM_ENABLED;
}
if (fep->quirks & FEC_QUIRK_HAS_AVB) {
fep->tx_align = 0;
fep->rx_align = 0x3f;
}
ndev->hw_features = ndev->features;
fec_restart(ndev);
if (fep->quirks & FEC_QUIRK_MIB_CLEAR)
fec_enet_clear_ethtool_stats(ndev);
else
fec_enet_update_ethtool_stats(ndev);
return 0;
}
static int fec_reset_phy(struct platform_device *pdev)
{
int err, phy_reset;
bool active_high = false;
int msec = 1, phy_post_delay = 0;
struct device_node *np = pdev->dev.of_node;
if (!np)
return 0;
err = of_property_read_u32(np, "phy-reset-duration", &msec);
if (!err && msec > 1000)
msec = 1;
phy_reset = of_get_named_gpio(np, "phy-reset-gpios", 0);
if (phy_reset == -EPROBE_DEFER)
return phy_reset;
else if (!gpio_is_valid(phy_reset))
return 0;
err = of_property_read_u32(np, "phy-reset-post-delay", &phy_post_delay);
if (!err && phy_post_delay > 1000)
return -EINVAL;
active_high = of_property_read_bool(np, "phy-reset-active-high");
err = devm_gpio_request_one(&pdev->dev, phy_reset,
active_high ? GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW,
"phy-reset");
if (err) {
dev_err(&pdev->dev, "failed to get phy-reset-gpios: %d\n", err);
return err;
}
if (msec > 20)
msleep(msec);
else
usleep_range(msec * 1000, msec * 1000 + 1000);
gpio_set_value_cansleep(phy_reset, !active_high);
if (!phy_post_delay)
return 0;
if (phy_post_delay > 20)
msleep(phy_post_delay);
else
usleep_range(phy_post_delay * 1000,
phy_post_delay * 1000 + 1000);
return 0;
}
static int fec_reset_phy(struct platform_device *pdev)
{
return 0;
}
static void
fec_enet_get_queue_num(struct platform_device *pdev, int *num_tx, int *num_rx)
{
struct device_node *np = pdev->dev.of_node;
*num_tx = *num_rx = 1;
if (!np || !of_device_is_available(np))
return;
of_property_read_u32(np, "fsl,num-tx-queues", num_tx);
of_property_read_u32(np, "fsl,num-rx-queues", num_rx);
if (*num_tx < 1 || *num_tx > FEC_ENET_MAX_TX_QS) {
dev_warn(&pdev->dev, "Invalid num_tx(=%d), fall back to 1\n",
*num_tx);
*num_tx = 1;
return;
}
if (*num_rx < 1 || *num_rx > FEC_ENET_MAX_RX_QS) {
dev_warn(&pdev->dev, "Invalid num_rx(=%d), fall back to 1\n",
*num_rx);
*num_rx = 1;
return;
}
}
static int
fec_probe(struct platform_device *pdev)
{
struct fec_enet_private *fep;
struct fec_platform_data *pdata;
struct net_device *ndev;
int i, irq, ret = 0;
struct resource *r;
const struct of_device_id *of_id;
static int dev_id;
struct device_node *np = pdev->dev.of_node, *phy_node;
int num_tx_qs;
int num_rx_qs;
fec_enet_get_queue_num(pdev, &num_tx_qs, &num_rx_qs);
ndev = alloc_etherdev_mqs(sizeof(struct fec_enet_private) +
FEC_STATS_SIZE, num_tx_qs, num_rx_qs);
if (!ndev)
return -ENOMEM;
SET_NETDEV_DEV(ndev, &pdev->dev);
fep = netdev_priv(ndev);
of_id = of_match_device(fec_dt_ids, &pdev->dev);
if (of_id)
pdev->id_entry = of_id->data;
fep->quirks = pdev->id_entry->driver_data;
fep->netdev = ndev;
fep->num_rx_queues = num_rx_qs;
fep->num_tx_queues = num_tx_qs;
#if !defined(CONFIG_M5272)
if (fep->quirks & FEC_QUIRK_HAS_GBIT)
fep->pause_flag |= FEC_PAUSE_FLAG_AUTONEG;
#endif
pinctrl_pm_select_default_state(&pdev->dev);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
fep->hwp = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(fep->hwp)) {
ret = PTR_ERR(fep->hwp);
goto failed_ioremap;
}
fep->pdev = pdev;
fep->dev_id = dev_id++;
platform_set_drvdata(pdev, ndev);
if ((of_machine_is_compatible("fsl,imx6q") ||
of_machine_is_compatible("fsl,imx6dl")) &&
!of_property_read_bool(np, "fsl,err006687-workaround-present"))
fep->quirks |= FEC_QUIRK_ERR006687;
if (of_get_property(np, "fsl,magic-packet", NULL))
fep->wol_flag |= FEC_WOL_HAS_MAGIC_PACKET;
phy_node = of_parse_phandle(np, "phy-handle", 0);
if (!phy_node && of_phy_is_fixed_link(np)) {
ret = of_phy_register_fixed_link(np);
if (ret < 0) {
dev_err(&pdev->dev,
"broken fixed-link specification\n");
goto failed_phy;
}
phy_node = of_node_get(np);
}
fep->phy_node = phy_node;
ret = of_get_phy_mode(pdev->dev.of_node);
if (ret < 0) {
pdata = dev_get_platdata(&pdev->dev);
if (pdata)
fep->phy_interface = pdata->phy;
else
fep->phy_interface = PHY_INTERFACE_MODE_MII;
} else {
fep->phy_interface = ret;
}
fep->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(fep->clk_ipg)) {
ret = PTR_ERR(fep->clk_ipg);
goto failed_clk;
}
fep->clk_ahb = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(fep->clk_ahb)) {
ret = PTR_ERR(fep->clk_ahb);
goto failed_clk;
}
fep->itr_clk_rate = clk_get_rate(fep->clk_ahb);
fep->clk_enet_out = devm_clk_get(&pdev->dev, "enet_out");
if (IS_ERR(fep->clk_enet_out))
fep->clk_enet_out = NULL;
fep->ptp_clk_on = false;
mutex_init(&fep->ptp_clk_mutex);
fep->clk_ref = devm_clk_get(&pdev->dev, "enet_clk_ref");
if (IS_ERR(fep->clk_ref))
fep->clk_ref = NULL;
fep->bufdesc_ex = fep->quirks & FEC_QUIRK_HAS_BUFDESC_EX;
fep->clk_ptp = devm_clk_get(&pdev->dev, "ptp");
if (IS_ERR(fep->clk_ptp)) {
fep->clk_ptp = NULL;
fep->bufdesc_ex = false;
}
ret = fec_enet_clk_enable(ndev, true);
if (ret)
goto failed_clk;
ret = clk_prepare_enable(fep->clk_ipg);
if (ret)
goto failed_clk_ipg;
fep->reg_phy = devm_regulator_get(&pdev->dev, "phy");
if (!IS_ERR(fep->reg_phy)) {
ret = regulator_enable(fep->reg_phy);
if (ret) {
dev_err(&pdev->dev,
"Failed to enable phy regulator: %d\n", ret);
clk_disable_unprepare(fep->clk_ipg);
goto failed_regulator;
}
} else {
fep->reg_phy = NULL;
}
pm_runtime_set_autosuspend_delay(&pdev->dev, FEC_MDIO_PM_TIMEOUT);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_get_noresume(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
ret = fec_reset_phy(pdev);
if (ret)
goto failed_reset;
if (fep->bufdesc_ex)
fec_ptp_init(pdev);
ret = fec_enet_init(ndev);
if (ret)
goto failed_init;
for (i = 0; i < FEC_IRQ_NUM; i++) {
irq = platform_get_irq(pdev, i);
if (irq < 0) {
if (i)
break;
ret = irq;
goto failed_irq;
}
ret = devm_request_irq(&pdev->dev, irq, fec_enet_interrupt,
0, pdev->name, ndev);
if (ret)
goto failed_irq;
fep->irq[i] = irq;
}
init_completion(&fep->mdio_done);
ret = fec_enet_mii_init(pdev);
if (ret)
goto failed_mii_init;
netif_carrier_off(ndev);
fec_enet_clk_enable(ndev, false);
pinctrl_pm_select_sleep_state(&pdev->dev);
ret = register_netdev(ndev);
if (ret)
goto failed_register;
device_init_wakeup(&ndev->dev, fep->wol_flag &
FEC_WOL_HAS_MAGIC_PACKET);
if (fep->bufdesc_ex && fep->ptp_clock)
netdev_info(ndev, "registered PHC device %d\n", fep->dev_id);
fep->rx_copybreak = COPYBREAK_DEFAULT;
INIT_WORK(&fep->tx_timeout_work, fec_enet_timeout_work);
pm_runtime_mark_last_busy(&pdev->dev);
pm_runtime_put_autosuspend(&pdev->dev);
return 0;
failed_register:
fec_enet_mii_remove(fep);
failed_mii_init:
failed_irq:
failed_init:
fec_ptp_stop(pdev);
if (fep->reg_phy)
regulator_disable(fep->reg_phy);
failed_reset:
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
failed_regulator:
failed_clk_ipg:
fec_enet_clk_enable(ndev, false);
failed_clk:
if (of_phy_is_fixed_link(np))
of_phy_deregister_fixed_link(np);
failed_phy:
of_node_put(phy_node);
failed_ioremap:
free_netdev(ndev);
return ret;
}
static int
fec_drv_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct fec_enet_private *fep = netdev_priv(ndev);
struct device_node *np = pdev->dev.of_node;
cancel_work_sync(&fep->tx_timeout_work);
fec_ptp_stop(pdev);
unregister_netdev(ndev);
fec_enet_mii_remove(fep);
if (fep->reg_phy)
regulator_disable(fep->reg_phy);
if (of_phy_is_fixed_link(np))
of_phy_deregister_fixed_link(np);
of_node_put(fep->phy_node);
free_netdev(ndev);
return 0;
}
static int __maybe_unused fec_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct fec_enet_private *fep = netdev_priv(ndev);
rtnl_lock();
if (netif_running(ndev)) {
if (fep->wol_flag & FEC_WOL_FLAG_ENABLE)
fep->wol_flag |= FEC_WOL_FLAG_SLEEP_ON;
phy_stop(ndev->phydev);
napi_disable(&fep->napi);
netif_tx_lock_bh(ndev);
netif_device_detach(ndev);
netif_tx_unlock_bh(ndev);
fec_stop(ndev);
fec_enet_clk_enable(ndev, false);
if (!(fep->wol_flag & FEC_WOL_FLAG_ENABLE))
pinctrl_pm_select_sleep_state(&fep->pdev->dev);
}
rtnl_unlock();
if (fep->reg_phy && !(fep->wol_flag & FEC_WOL_FLAG_ENABLE))
regulator_disable(fep->reg_phy);
if (fep->clk_enet_out || fep->reg_phy)
fep->link = 0;
return 0;
}
static int __maybe_unused fec_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct fec_enet_private *fep = netdev_priv(ndev);
struct fec_platform_data *pdata = fep->pdev->dev.platform_data;
int ret;
int val;
if (fep->reg_phy && !(fep->wol_flag & FEC_WOL_FLAG_ENABLE)) {
ret = regulator_enable(fep->reg_phy);
if (ret)
return ret;
}
rtnl_lock();
if (netif_running(ndev)) {
ret = fec_enet_clk_enable(ndev, true);
if (ret) {
rtnl_unlock();
goto failed_clk;
}
if (fep->wol_flag & FEC_WOL_FLAG_ENABLE) {
if (pdata && pdata->sleep_mode_enable)
pdata->sleep_mode_enable(false);
val = readl(fep->hwp + FEC_ECNTRL);
val &= ~(FEC_ECR_MAGICEN | FEC_ECR_SLEEP);
writel(val, fep->hwp + FEC_ECNTRL);
fep->wol_flag &= ~FEC_WOL_FLAG_SLEEP_ON;
} else {
pinctrl_pm_select_default_state(&fep->pdev->dev);
}
fec_restart(ndev);
netif_tx_lock_bh(ndev);
netif_device_attach(ndev);
netif_tx_unlock_bh(ndev);
napi_enable(&fep->napi);
phy_start(ndev->phydev);
}
rtnl_unlock();
return 0;
failed_clk:
if (fep->reg_phy)
regulator_disable(fep->reg_phy);
return ret;
}
static int __maybe_unused fec_runtime_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct fec_enet_private *fep = netdev_priv(ndev);
clk_disable_unprepare(fep->clk_ipg);
return 0;
}
static int __maybe_unused fec_runtime_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct fec_enet_private *fep = netdev_priv(ndev);
return clk_prepare_enable(fep->clk_ipg);
}
