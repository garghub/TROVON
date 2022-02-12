static inline bool ath9k_check_auto_sleep(struct ath_softc *sc)
{
return sc->ps_enabled &&
(sc->sc_ah->caps.hw_caps & ATH9K_HW_CAP_AUTOSLEEP);
}
static void ath_rx_buf_link(struct ath_softc *sc, struct ath_buf *bf)
{
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
struct ath_desc *ds;
struct sk_buff *skb;
ATH_RXBUF_RESET(bf);
ds = bf->bf_desc;
ds->ds_link = 0;
ds->ds_data = bf->bf_buf_addr;
skb = bf->bf_mpdu;
BUG_ON(skb == NULL);
ds->ds_vdata = skb->data;
ath9k_hw_setuprxdesc(ah, ds,
common->rx_bufsize,
0);
if (sc->rx.rxlink == NULL)
ath9k_hw_putrxbuf(ah, bf->bf_daddr);
else
*sc->rx.rxlink = bf->bf_daddr;
sc->rx.rxlink = &ds->ds_link;
}
static void ath_setdefantenna(struct ath_softc *sc, u32 antenna)
{
ath9k_hw_setantenna(sc->sc_ah, antenna);
sc->rx.defant = antenna;
sc->rx.rxotherant = 0;
}
static void ath_opmode_init(struct ath_softc *sc)
{
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
u32 rfilt, mfilt[2];
rfilt = ath_calcrxfilter(sc);
ath9k_hw_setrxfilter(ah, rfilt);
ath_hw_setbssidmask(common);
ath9k_hw_setopmode(ah);
mfilt[0] = mfilt[1] = ~0;
ath9k_hw_setmcastfilter(ah, mfilt[0], mfilt[1]);
}
static bool ath_rx_edma_buf_link(struct ath_softc *sc,
enum ath9k_rx_qtype qtype)
{
struct ath_hw *ah = sc->sc_ah;
struct ath_rx_edma *rx_edma;
struct sk_buff *skb;
struct ath_buf *bf;
rx_edma = &sc->rx.rx_edma[qtype];
if (skb_queue_len(&rx_edma->rx_fifo) >= rx_edma->rx_fifo_hwsize)
return false;
bf = list_first_entry(&sc->rx.rxbuf, struct ath_buf, list);
list_del_init(&bf->list);
skb = bf->bf_mpdu;
ATH_RXBUF_RESET(bf);
memset(skb->data, 0, ah->caps.rx_status_len);
dma_sync_single_for_device(sc->dev, bf->bf_buf_addr,
ah->caps.rx_status_len, DMA_TO_DEVICE);
SKB_CB_ATHBUF(skb) = bf;
ath9k_hw_addrxbuf_edma(ah, bf->bf_buf_addr, qtype);
skb_queue_tail(&rx_edma->rx_fifo, skb);
return true;
}
static void ath_rx_addbuffer_edma(struct ath_softc *sc,
enum ath9k_rx_qtype qtype, int size)
{
struct ath_common *common = ath9k_hw_common(sc->sc_ah);
struct ath_buf *bf, *tbf;
if (list_empty(&sc->rx.rxbuf)) {
ath_dbg(common, QUEUE, "No free rx buf available\n");
return;
}
list_for_each_entry_safe(bf, tbf, &sc->rx.rxbuf, list)
if (!ath_rx_edma_buf_link(sc, qtype))
break;
}
static void ath_rx_remove_buffer(struct ath_softc *sc,
enum ath9k_rx_qtype qtype)
{
struct ath_buf *bf;
struct ath_rx_edma *rx_edma;
struct sk_buff *skb;
rx_edma = &sc->rx.rx_edma[qtype];
while ((skb = skb_dequeue(&rx_edma->rx_fifo)) != NULL) {
bf = SKB_CB_ATHBUF(skb);
BUG_ON(!bf);
list_add_tail(&bf->list, &sc->rx.rxbuf);
}
}
static void ath_rx_edma_cleanup(struct ath_softc *sc)
{
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
struct ath_buf *bf;
ath_rx_remove_buffer(sc, ATH9K_RX_QUEUE_LP);
ath_rx_remove_buffer(sc, ATH9K_RX_QUEUE_HP);
list_for_each_entry(bf, &sc->rx.rxbuf, list) {
if (bf->bf_mpdu) {
dma_unmap_single(sc->dev, bf->bf_buf_addr,
common->rx_bufsize,
DMA_BIDIRECTIONAL);
dev_kfree_skb_any(bf->bf_mpdu);
bf->bf_buf_addr = 0;
bf->bf_mpdu = NULL;
}
}
INIT_LIST_HEAD(&sc->rx.rxbuf);
kfree(sc->rx.rx_bufptr);
sc->rx.rx_bufptr = NULL;
}
static void ath_rx_edma_init_queue(struct ath_rx_edma *rx_edma, int size)
{
skb_queue_head_init(&rx_edma->rx_fifo);
rx_edma->rx_fifo_hwsize = size;
}
static int ath_rx_edma_init(struct ath_softc *sc, int nbufs)
{
struct ath_common *common = ath9k_hw_common(sc->sc_ah);
struct ath_hw *ah = sc->sc_ah;
struct sk_buff *skb;
struct ath_buf *bf;
int error = 0, i;
u32 size;
ath9k_hw_set_rx_bufsize(ah, common->rx_bufsize -
ah->caps.rx_status_len);
ath_rx_edma_init_queue(&sc->rx.rx_edma[ATH9K_RX_QUEUE_LP],
ah->caps.rx_lp_qdepth);
ath_rx_edma_init_queue(&sc->rx.rx_edma[ATH9K_RX_QUEUE_HP],
ah->caps.rx_hp_qdepth);
size = sizeof(struct ath_buf) * nbufs;
bf = kzalloc(size, GFP_KERNEL);
if (!bf)
return -ENOMEM;
INIT_LIST_HEAD(&sc->rx.rxbuf);
sc->rx.rx_bufptr = bf;
for (i = 0; i < nbufs; i++, bf++) {
skb = ath_rxbuf_alloc(common, common->rx_bufsize, GFP_KERNEL);
if (!skb) {
error = -ENOMEM;
goto rx_init_fail;
}
memset(skb->data, 0, common->rx_bufsize);
bf->bf_mpdu = skb;
bf->bf_buf_addr = dma_map_single(sc->dev, skb->data,
common->rx_bufsize,
DMA_BIDIRECTIONAL);
if (unlikely(dma_mapping_error(sc->dev,
bf->bf_buf_addr))) {
dev_kfree_skb_any(skb);
bf->bf_mpdu = NULL;
bf->bf_buf_addr = 0;
ath_err(common,
"dma_mapping_error() on RX init\n");
error = -ENOMEM;
goto rx_init_fail;
}
list_add_tail(&bf->list, &sc->rx.rxbuf);
}
return 0;
rx_init_fail:
ath_rx_edma_cleanup(sc);
return error;
}
static void ath_edma_start_recv(struct ath_softc *sc)
{
spin_lock_bh(&sc->rx.rxbuflock);
ath9k_hw_rxena(sc->sc_ah);
ath_rx_addbuffer_edma(sc, ATH9K_RX_QUEUE_HP,
sc->rx.rx_edma[ATH9K_RX_QUEUE_HP].rx_fifo_hwsize);
ath_rx_addbuffer_edma(sc, ATH9K_RX_QUEUE_LP,
sc->rx.rx_edma[ATH9K_RX_QUEUE_LP].rx_fifo_hwsize);
ath_opmode_init(sc);
ath9k_hw_startpcureceive(sc->sc_ah, !!(sc->hw->conf.flags & IEEE80211_CONF_OFFCHANNEL));
spin_unlock_bh(&sc->rx.rxbuflock);
}
static void ath_edma_stop_recv(struct ath_softc *sc)
{
ath_rx_remove_buffer(sc, ATH9K_RX_QUEUE_HP);
ath_rx_remove_buffer(sc, ATH9K_RX_QUEUE_LP);
}
int ath_rx_init(struct ath_softc *sc, int nbufs)
{
struct ath_common *common = ath9k_hw_common(sc->sc_ah);
struct sk_buff *skb;
struct ath_buf *bf;
int error = 0;
spin_lock_init(&sc->sc_pcu_lock);
spin_lock_init(&sc->rx.rxbuflock);
clear_bit(SC_OP_RXFLUSH, &sc->sc_flags);
common->rx_bufsize = IEEE80211_MAX_MPDU_LEN / 2 +
sc->sc_ah->caps.rx_status_len;
if (sc->sc_ah->caps.hw_caps & ATH9K_HW_CAP_EDMA) {
return ath_rx_edma_init(sc, nbufs);
} else {
ath_dbg(common, CONFIG, "cachelsz %u rxbufsize %u\n",
common->cachelsz, common->rx_bufsize);
error = ath_descdma_setup(sc, &sc->rx.rxdma, &sc->rx.rxbuf,
"rx", nbufs, 1, 0);
if (error != 0) {
ath_err(common,
"failed to allocate rx descriptors: %d\n",
error);
goto err;
}
list_for_each_entry(bf, &sc->rx.rxbuf, list) {
skb = ath_rxbuf_alloc(common, common->rx_bufsize,
GFP_KERNEL);
if (skb == NULL) {
error = -ENOMEM;
goto err;
}
bf->bf_mpdu = skb;
bf->bf_buf_addr = dma_map_single(sc->dev, skb->data,
common->rx_bufsize,
DMA_FROM_DEVICE);
if (unlikely(dma_mapping_error(sc->dev,
bf->bf_buf_addr))) {
dev_kfree_skb_any(skb);
bf->bf_mpdu = NULL;
bf->bf_buf_addr = 0;
ath_err(common,
"dma_mapping_error() on RX init\n");
error = -ENOMEM;
goto err;
}
}
sc->rx.rxlink = NULL;
}
err:
if (error)
ath_rx_cleanup(sc);
return error;
}
void ath_rx_cleanup(struct ath_softc *sc)
{
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
struct sk_buff *skb;
struct ath_buf *bf;
if (sc->sc_ah->caps.hw_caps & ATH9K_HW_CAP_EDMA) {
ath_rx_edma_cleanup(sc);
return;
} else {
list_for_each_entry(bf, &sc->rx.rxbuf, list) {
skb = bf->bf_mpdu;
if (skb) {
dma_unmap_single(sc->dev, bf->bf_buf_addr,
common->rx_bufsize,
DMA_FROM_DEVICE);
dev_kfree_skb(skb);
bf->bf_buf_addr = 0;
bf->bf_mpdu = NULL;
}
}
if (sc->rx.rxdma.dd_desc_len != 0)
ath_descdma_cleanup(sc, &sc->rx.rxdma, &sc->rx.rxbuf);
}
}
u32 ath_calcrxfilter(struct ath_softc *sc)
{
u32 rfilt;
rfilt = ATH9K_RX_FILTER_UCAST | ATH9K_RX_FILTER_BCAST
| ATH9K_RX_FILTER_MCAST;
if (sc->rx.rxfilter & FIF_PROBE_REQ)
rfilt |= ATH9K_RX_FILTER_PROBEREQ;
if (sc->sc_ah->is_monitoring)
rfilt |= ATH9K_RX_FILTER_PROM;
if (sc->rx.rxfilter & FIF_CONTROL)
rfilt |= ATH9K_RX_FILTER_CONTROL;
if ((sc->sc_ah->opmode == NL80211_IFTYPE_STATION) &&
(sc->nvifs <= 1) &&
!(sc->rx.rxfilter & FIF_BCN_PRBRESP_PROMISC))
rfilt |= ATH9K_RX_FILTER_MYBEACON;
else
rfilt |= ATH9K_RX_FILTER_BEACON;
if ((sc->sc_ah->opmode == NL80211_IFTYPE_AP) ||
(sc->rx.rxfilter & FIF_PSPOLL))
rfilt |= ATH9K_RX_FILTER_PSPOLL;
if (conf_is_ht(&sc->hw->conf))
rfilt |= ATH9K_RX_FILTER_COMP_BAR;
if (sc->nvifs > 1 || (sc->rx.rxfilter & FIF_OTHER_BSS)) {
if (sc->sc_ah->hw_version.macVersion <= AR_SREV_VERSION_9160)
rfilt |= ATH9K_RX_FILTER_PROM;
rfilt |= ATH9K_RX_FILTER_MCAST_BCAST_ALL;
}
if (AR_SREV_9550(sc->sc_ah))
rfilt |= ATH9K_RX_FILTER_4ADDRESS;
return rfilt;
}
int ath_startrecv(struct ath_softc *sc)
{
struct ath_hw *ah = sc->sc_ah;
struct ath_buf *bf, *tbf;
if (ah->caps.hw_caps & ATH9K_HW_CAP_EDMA) {
ath_edma_start_recv(sc);
return 0;
}
spin_lock_bh(&sc->rx.rxbuflock);
if (list_empty(&sc->rx.rxbuf))
goto start_recv;
sc->rx.rxlink = NULL;
list_for_each_entry_safe(bf, tbf, &sc->rx.rxbuf, list) {
ath_rx_buf_link(sc, bf);
}
if (list_empty(&sc->rx.rxbuf))
goto start_recv;
bf = list_first_entry(&sc->rx.rxbuf, struct ath_buf, list);
ath9k_hw_putrxbuf(ah, bf->bf_daddr);
ath9k_hw_rxena(ah);
start_recv:
ath_opmode_init(sc);
ath9k_hw_startpcureceive(ah, !!(sc->hw->conf.flags & IEEE80211_CONF_OFFCHANNEL));
spin_unlock_bh(&sc->rx.rxbuflock);
return 0;
}
bool ath_stoprecv(struct ath_softc *sc)
{
struct ath_hw *ah = sc->sc_ah;
bool stopped, reset = false;
spin_lock_bh(&sc->rx.rxbuflock);
ath9k_hw_abortpcurecv(ah);
ath9k_hw_setrxfilter(ah, 0);
stopped = ath9k_hw_stopdmarecv(ah, &reset);
if (sc->sc_ah->caps.hw_caps & ATH9K_HW_CAP_EDMA)
ath_edma_stop_recv(sc);
else
sc->rx.rxlink = NULL;
spin_unlock_bh(&sc->rx.rxbuflock);
if (!(ah->ah_flags & AH_UNPLUGGED) &&
unlikely(!stopped)) {
ath_err(ath9k_hw_common(sc->sc_ah),
"Could not stop RX, we could be "
"confusing the DMA engine when we start RX up\n");
ATH_DBG_WARN_ON_ONCE(!stopped);
}
return stopped && !reset;
}
void ath_flushrecv(struct ath_softc *sc)
{
set_bit(SC_OP_RXFLUSH, &sc->sc_flags);
if (sc->sc_ah->caps.hw_caps & ATH9K_HW_CAP_EDMA)
ath_rx_tasklet(sc, 1, true);
ath_rx_tasklet(sc, 1, false);
clear_bit(SC_OP_RXFLUSH, &sc->sc_flags);
}
static bool ath_beacon_dtim_pending_cab(struct sk_buff *skb)
{
struct ieee80211_mgmt *mgmt;
u8 *pos, *end, id, elen;
struct ieee80211_tim_ie *tim;
mgmt = (struct ieee80211_mgmt *)skb->data;
pos = mgmt->u.beacon.variable;
end = skb->data + skb->len;
while (pos + 2 < end) {
id = *pos++;
elen = *pos++;
if (pos + elen > end)
break;
if (id == WLAN_EID_TIM) {
if (elen < sizeof(*tim))
break;
tim = (struct ieee80211_tim_ie *) pos;
if (tim->dtim_count != 0)
break;
return tim->bitmap_ctrl & 0x01;
}
pos += elen;
}
return false;
}
static void ath_rx_ps_beacon(struct ath_softc *sc, struct sk_buff *skb)
{
struct ath_common *common = ath9k_hw_common(sc->sc_ah);
if (skb->len < 24 + 8 + 2 + 2)
return;
sc->ps_flags &= ~PS_WAIT_FOR_BEACON;
if (sc->ps_flags & PS_BEACON_SYNC) {
sc->ps_flags &= ~PS_BEACON_SYNC;
ath_dbg(common, PS,
"Reconfigure Beacon timers based on timestamp from the AP\n");
ath9k_set_beacon(sc);
}
if (ath_beacon_dtim_pending_cab(skb)) {
ath_dbg(common, PS,
"Received DTIM beacon indicating buffered broadcast/multicast frame(s)\n");
sc->ps_flags |= PS_WAIT_FOR_CAB | PS_WAIT_FOR_BEACON;
return;
}
if (sc->ps_flags & PS_WAIT_FOR_CAB) {
sc->ps_flags &= ~PS_WAIT_FOR_CAB;
ath_dbg(common, PS, "PS wait for CAB frames timed out\n");
}
}
static void ath_rx_ps(struct ath_softc *sc, struct sk_buff *skb, bool mybeacon)
{
struct ieee80211_hdr *hdr;
struct ath_common *common = ath9k_hw_common(sc->sc_ah);
hdr = (struct ieee80211_hdr *)skb->data;
if (((sc->ps_flags & PS_WAIT_FOR_BEACON) || ath9k_check_auto_sleep(sc))
&& mybeacon) {
ath_rx_ps_beacon(sc, skb);
} else if ((sc->ps_flags & PS_WAIT_FOR_CAB) &&
(ieee80211_is_data(hdr->frame_control) ||
ieee80211_is_action(hdr->frame_control)) &&
is_multicast_ether_addr(hdr->addr1) &&
!ieee80211_has_moredata(hdr->frame_control)) {
sc->ps_flags &= ~(PS_WAIT_FOR_CAB | PS_WAIT_FOR_BEACON);
ath_dbg(common, PS,
"All PS CAB frames received, back to sleep\n");
} else if ((sc->ps_flags & PS_WAIT_FOR_PSPOLL_DATA) &&
!is_multicast_ether_addr(hdr->addr1) &&
!ieee80211_has_morefrags(hdr->frame_control)) {
sc->ps_flags &= ~PS_WAIT_FOR_PSPOLL_DATA;
ath_dbg(common, PS,
"Going back to sleep after having received PS-Poll data (0x%lx)\n",
sc->ps_flags & (PS_WAIT_FOR_BEACON |
PS_WAIT_FOR_CAB |
PS_WAIT_FOR_PSPOLL_DATA |
PS_WAIT_FOR_TX_ACK));
}
}
static bool ath_edma_get_buffers(struct ath_softc *sc,
enum ath9k_rx_qtype qtype,
struct ath_rx_status *rs,
struct ath_buf **dest)
{
struct ath_rx_edma *rx_edma = &sc->rx.rx_edma[qtype];
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
struct sk_buff *skb;
struct ath_buf *bf;
int ret;
skb = skb_peek(&rx_edma->rx_fifo);
if (!skb)
return false;
bf = SKB_CB_ATHBUF(skb);
BUG_ON(!bf);
dma_sync_single_for_cpu(sc->dev, bf->bf_buf_addr,
common->rx_bufsize, DMA_FROM_DEVICE);
ret = ath9k_hw_process_rxdesc_edma(ah, rs, skb->data);
if (ret == -EINPROGRESS) {
dma_sync_single_for_device(sc->dev, bf->bf_buf_addr,
common->rx_bufsize, DMA_FROM_DEVICE);
return false;
}
__skb_unlink(skb, &rx_edma->rx_fifo);
if (ret == -EINVAL) {
list_add_tail(&bf->list, &sc->rx.rxbuf);
ath_rx_edma_buf_link(sc, qtype);
skb = skb_peek(&rx_edma->rx_fifo);
if (skb) {
bf = SKB_CB_ATHBUF(skb);
BUG_ON(!bf);
__skb_unlink(skb, &rx_edma->rx_fifo);
list_add_tail(&bf->list, &sc->rx.rxbuf);
ath_rx_edma_buf_link(sc, qtype);
}
bf = NULL;
}
*dest = bf;
return true;
}
static struct ath_buf *ath_edma_get_next_rx_buf(struct ath_softc *sc,
struct ath_rx_status *rs,
enum ath9k_rx_qtype qtype)
{
struct ath_buf *bf = NULL;
while (ath_edma_get_buffers(sc, qtype, rs, &bf)) {
if (!bf)
continue;
return bf;
}
return NULL;
}
static struct ath_buf *ath_get_next_rx_buf(struct ath_softc *sc,
struct ath_rx_status *rs)
{
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
struct ath_desc *ds;
struct ath_buf *bf;
int ret;
if (list_empty(&sc->rx.rxbuf)) {
sc->rx.rxlink = NULL;
return NULL;
}
bf = list_first_entry(&sc->rx.rxbuf, struct ath_buf, list);
ds = bf->bf_desc;
ret = ath9k_hw_rxprocdesc(ah, ds, rs);
if (ret == -EINPROGRESS) {
struct ath_rx_status trs;
struct ath_buf *tbf;
struct ath_desc *tds;
memset(&trs, 0, sizeof(trs));
if (list_is_last(&bf->list, &sc->rx.rxbuf)) {
sc->rx.rxlink = NULL;
return NULL;
}
tbf = list_entry(bf->list.next, struct ath_buf, list);
tds = tbf->bf_desc;
ret = ath9k_hw_rxprocdesc(ah, tds, &trs);
if (ret == -EINPROGRESS)
return NULL;
}
if (!bf->bf_mpdu)
return bf;
dma_sync_single_for_cpu(sc->dev, bf->bf_buf_addr,
common->rx_bufsize,
DMA_FROM_DEVICE);
return bf;
}
static bool ath9k_rx_accept(struct ath_common *common,
struct ieee80211_hdr *hdr,
struct ieee80211_rx_status *rxs,
struct ath_rx_status *rx_stats,
bool *decrypt_error)
{
struct ath_softc *sc = (struct ath_softc *) common->priv;
bool is_mc, is_valid_tkip, strip_mic, mic_error;
struct ath_hw *ah = common->ah;
__le16 fc;
u8 rx_status_len = ah->caps.rx_status_len;
fc = hdr->frame_control;
is_mc = !!is_multicast_ether_addr(hdr->addr1);
is_valid_tkip = rx_stats->rs_keyix != ATH9K_RXKEYIX_INVALID &&
test_bit(rx_stats->rs_keyix, common->tkip_keymap);
strip_mic = is_valid_tkip && ieee80211_is_data(fc) &&
ieee80211_has_protected(fc) &&
!(rx_stats->rs_status &
(ATH9K_RXERR_DECRYPT | ATH9K_RXERR_CRC | ATH9K_RXERR_MIC |
ATH9K_RXERR_KEYMISS));
if (rx_stats->rs_keyix == ATH9K_RXKEYIX_INVALID ||
!test_bit(rx_stats->rs_keyix, common->ccmp_keymap))
rx_stats->rs_status &= ~ATH9K_RXERR_KEYMISS;
if (!rx_stats->rs_datalen) {
RX_STAT_INC(rx_len_err);
return false;
}
if (rx_stats->rs_datalen > (common->rx_bufsize - rx_status_len)) {
RX_STAT_INC(rx_len_err);
return false;
}
if (rx_stats->rs_more)
return true;
mic_error = is_valid_tkip && !ieee80211_is_ctl(fc) &&
!ieee80211_has_morefrags(fc) &&
!(le16_to_cpu(hdr->seq_ctrl) & IEEE80211_SCTL_FRAG) &&
(rx_stats->rs_status & ATH9K_RXERR_MIC);
if (rx_stats->rs_status != 0) {
u8 status_mask;
if (rx_stats->rs_status & ATH9K_RXERR_CRC) {
rxs->flag |= RX_FLAG_FAILED_FCS_CRC;
mic_error = false;
}
if (rx_stats->rs_status & ATH9K_RXERR_PHY)
return false;
if ((rx_stats->rs_status & ATH9K_RXERR_DECRYPT) ||
(!is_mc && (rx_stats->rs_status & ATH9K_RXERR_KEYMISS))) {
*decrypt_error = true;
mic_error = false;
}
status_mask = ATH9K_RXERR_DECRYPT | ATH9K_RXERR_MIC |
ATH9K_RXERR_KEYMISS;
if (ah->is_monitoring && (sc->rx.rxfilter & FIF_FCSFAIL))
status_mask |= ATH9K_RXERR_CRC;
if (rx_stats->rs_status & ~status_mask)
return false;
}
if (strip_mic)
rxs->flag |= RX_FLAG_MMIC_STRIPPED;
else if (is_mc && mic_error)
rxs->flag |= RX_FLAG_MMIC_ERROR;
return true;
}
static int ath9k_process_rate(struct ath_common *common,
struct ieee80211_hw *hw,
struct ath_rx_status *rx_stats,
struct ieee80211_rx_status *rxs)
{
struct ieee80211_supported_band *sband;
enum ieee80211_band band;
unsigned int i = 0;
struct ath_softc __maybe_unused *sc = common->priv;
band = hw->conf.channel->band;
sband = hw->wiphy->bands[band];
if (rx_stats->rs_rate & 0x80) {
rxs->flag |= RX_FLAG_HT;
if (rx_stats->rs_flags & ATH9K_RX_2040)
rxs->flag |= RX_FLAG_40MHZ;
if (rx_stats->rs_flags & ATH9K_RX_GI)
rxs->flag |= RX_FLAG_SHORT_GI;
rxs->rate_idx = rx_stats->rs_rate & 0x7f;
return 0;
}
for (i = 0; i < sband->n_bitrates; i++) {
if (sband->bitrates[i].hw_value == rx_stats->rs_rate) {
rxs->rate_idx = i;
return 0;
}
if (sband->bitrates[i].hw_value_short == rx_stats->rs_rate) {
rxs->flag |= RX_FLAG_SHORTPRE;
rxs->rate_idx = i;
return 0;
}
}
ath_dbg(common, ANY,
"unsupported hw bitrate detected 0x%02x using 1 Mbit\n",
rx_stats->rs_rate);
RX_STAT_INC(rx_rate_err);
return -EINVAL;
}
static void ath9k_process_rssi(struct ath_common *common,
struct ieee80211_hw *hw,
struct ieee80211_hdr *hdr,
struct ath_rx_status *rx_stats)
{
struct ath_softc *sc = hw->priv;
struct ath_hw *ah = common->ah;
int last_rssi;
int rssi = rx_stats->rs_rssi;
if (!rx_stats->is_mybeacon ||
((ah->opmode != NL80211_IFTYPE_STATION) &&
(ah->opmode != NL80211_IFTYPE_ADHOC)))
return;
if (rx_stats->rs_rssi != ATH9K_RSSI_BAD && !rx_stats->rs_moreaggr)
ATH_RSSI_LPF(sc->last_rssi, rx_stats->rs_rssi);
last_rssi = sc->last_rssi;
if (likely(last_rssi != ATH_RSSI_DUMMY_MARKER))
rssi = ATH_EP_RND(last_rssi, ATH_RSSI_EP_MULTIPLIER);
if (rssi < 0)
rssi = 0;
ah->stats.avgbrssi = rssi;
}
static int ath9k_rx_skb_preprocess(struct ath_common *common,
struct ieee80211_hw *hw,
struct ieee80211_hdr *hdr,
struct ath_rx_status *rx_stats,
struct ieee80211_rx_status *rx_status,
bool *decrypt_error)
{
struct ath_hw *ah = common->ah;
if (!ath9k_rx_accept(common, hdr, rx_status, rx_stats, decrypt_error))
return -EINVAL;
if (rx_stats->rs_more)
return 0;
ath9k_process_rssi(common, hw, hdr, rx_stats);
if (ath9k_process_rate(common, hw, rx_stats, rx_status))
return -EINVAL;
rx_status->band = hw->conf.channel->band;
rx_status->freq = hw->conf.channel->center_freq;
rx_status->signal = ah->noise + rx_stats->rs_rssi;
rx_status->antenna = rx_stats->rs_antenna;
rx_status->flag |= RX_FLAG_MACTIME_MPDU;
if (rx_stats->rs_moreaggr)
rx_status->flag |= RX_FLAG_NO_SIGNAL_VAL;
return 0;
}
static void ath9k_rx_skb_postprocess(struct ath_common *common,
struct sk_buff *skb,
struct ath_rx_status *rx_stats,
struct ieee80211_rx_status *rxs,
bool decrypt_error)
{
struct ath_hw *ah = common->ah;
struct ieee80211_hdr *hdr;
int hdrlen, padpos, padsize;
u8 keyix;
__le16 fc;
hdr = (struct ieee80211_hdr *) skb->data;
hdrlen = ieee80211_get_hdrlen_from_skb(skb);
fc = hdr->frame_control;
padpos = ath9k_cmn_padpos(hdr->frame_control);
padsize = padpos & 3;
if (padsize && skb->len>=padpos+padsize+FCS_LEN) {
memmove(skb->data + padsize, skb->data, padpos);
skb_pull(skb, padsize);
}
keyix = rx_stats->rs_keyix;
if (!(keyix == ATH9K_RXKEYIX_INVALID) && !decrypt_error &&
ieee80211_has_protected(fc)) {
rxs->flag |= RX_FLAG_DECRYPTED;
} else if (ieee80211_has_protected(fc)
&& !decrypt_error && skb->len >= hdrlen + 4) {
keyix = skb->data[hdrlen + 3] >> 6;
if (test_bit(keyix, common->keymap))
rxs->flag |= RX_FLAG_DECRYPTED;
}
if (ah->sw_mgmt_crypto &&
(rxs->flag & RX_FLAG_DECRYPTED) &&
ieee80211_is_mgmt(fc))
rxs->flag &= ~RX_FLAG_DECRYPTED;
}
int ath_rx_tasklet(struct ath_softc *sc, int flush, bool hp)
{
struct ath_buf *bf;
struct sk_buff *skb = NULL, *requeue_skb, *hdr_skb;
struct ieee80211_rx_status *rxs;
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
struct ieee80211_hw *hw = sc->hw;
struct ieee80211_hdr *hdr;
int retval;
struct ath_rx_status rs;
enum ath9k_rx_qtype qtype;
bool edma = !!(ah->caps.hw_caps & ATH9K_HW_CAP_EDMA);
int dma_type;
u8 rx_status_len = ah->caps.rx_status_len;
u64 tsf = 0;
u32 tsf_lower = 0;
unsigned long flags;
if (edma)
dma_type = DMA_BIDIRECTIONAL;
else
dma_type = DMA_FROM_DEVICE;
qtype = hp ? ATH9K_RX_QUEUE_HP : ATH9K_RX_QUEUE_LP;
spin_lock_bh(&sc->rx.rxbuflock);
tsf = ath9k_hw_gettsf64(ah);
tsf_lower = tsf & 0xffffffff;
do {
bool decrypt_error = false;
if (test_bit(SC_OP_RXFLUSH, &sc->sc_flags) && (flush == 0))
break;
memset(&rs, 0, sizeof(rs));
if (edma)
bf = ath_edma_get_next_rx_buf(sc, &rs, qtype);
else
bf = ath_get_next_rx_buf(sc, &rs);
if (!bf)
break;
skb = bf->bf_mpdu;
if (!skb)
continue;
if (sc->rx.frag)
hdr_skb = sc->rx.frag;
else
hdr_skb = skb;
hdr = (struct ieee80211_hdr *) (hdr_skb->data + rx_status_len);
rxs = IEEE80211_SKB_RXCB(hdr_skb);
if (ieee80211_is_beacon(hdr->frame_control)) {
RX_STAT_INC(rx_beacons);
if (!is_zero_ether_addr(common->curbssid) &&
ether_addr_equal(hdr->addr3, common->curbssid))
rs.is_mybeacon = true;
else
rs.is_mybeacon = false;
}
else
rs.is_mybeacon = false;
sc->rx.num_pkts++;
ath_debug_stat_rx(sc, &rs);
if (test_bit(SC_OP_RXFLUSH, &sc->sc_flags)) {
RX_STAT_INC(rx_drop_rxflush);
goto requeue_drop_frag;
}
memset(rxs, 0, sizeof(struct ieee80211_rx_status));
rxs->mactime = (tsf & ~0xffffffffULL) | rs.rs_tstamp;
if (rs.rs_tstamp > tsf_lower &&
unlikely(rs.rs_tstamp - tsf_lower > 0x10000000))
rxs->mactime -= 0x100000000ULL;
if (rs.rs_tstamp < tsf_lower &&
unlikely(tsf_lower - rs.rs_tstamp > 0x10000000))
rxs->mactime += 0x100000000ULL;
retval = ath9k_rx_skb_preprocess(common, hw, hdr, &rs,
rxs, &decrypt_error);
if (retval)
goto requeue_drop_frag;
if (rs.is_mybeacon) {
sc->hw_busy_count = 0;
ath_start_rx_poll(sc, 3);
}
requeue_skb = ath_rxbuf_alloc(common, common->rx_bufsize, GFP_ATOMIC);
if (!requeue_skb) {
RX_STAT_INC(rx_oom_err);
goto requeue_drop_frag;
}
dma_unmap_single(sc->dev, bf->bf_buf_addr,
common->rx_bufsize,
dma_type);
skb_put(skb, rs.rs_datalen + ah->caps.rx_status_len);
if (ah->caps.rx_status_len)
skb_pull(skb, ah->caps.rx_status_len);
if (!rs.rs_more)
ath9k_rx_skb_postprocess(common, hdr_skb, &rs,
rxs, decrypt_error);
bf->bf_mpdu = requeue_skb;
bf->bf_buf_addr = dma_map_single(sc->dev, requeue_skb->data,
common->rx_bufsize,
dma_type);
if (unlikely(dma_mapping_error(sc->dev,
bf->bf_buf_addr))) {
dev_kfree_skb_any(requeue_skb);
bf->bf_mpdu = NULL;
bf->bf_buf_addr = 0;
ath_err(common, "dma_mapping_error() on RX\n");
ieee80211_rx(hw, skb);
break;
}
if (rs.rs_more) {
RX_STAT_INC(rx_frags);
if (sc->rx.frag) {
dev_kfree_skb_any(sc->rx.frag);
dev_kfree_skb_any(skb);
RX_STAT_INC(rx_too_many_frags_err);
skb = NULL;
}
sc->rx.frag = skb;
goto requeue;
}
if (sc->rx.frag) {
int space = skb->len - skb_tailroom(hdr_skb);
if (pskb_expand_head(hdr_skb, 0, space, GFP_ATOMIC) < 0) {
dev_kfree_skb(skb);
RX_STAT_INC(rx_oom_err);
goto requeue_drop_frag;
}
sc->rx.frag = NULL;
skb_copy_from_linear_data(skb, skb_put(hdr_skb, skb->len),
skb->len);
dev_kfree_skb_any(skb);
skb = hdr_skb;
}
if (ah->caps.hw_caps & ATH9K_HW_CAP_ANT_DIV_COMB) {
if (sc->rx.defant != rs.rs_antenna) {
if (++sc->rx.rxotherant >= 3)
ath_setdefantenna(sc, rs.rs_antenna);
} else {
sc->rx.rxotherant = 0;
}
}
if (rxs->flag & RX_FLAG_MMIC_STRIPPED)
skb_trim(skb, skb->len - 8);
spin_lock_irqsave(&sc->sc_pm_lock, flags);
if ((sc->ps_flags & (PS_WAIT_FOR_BEACON |
PS_WAIT_FOR_CAB |
PS_WAIT_FOR_PSPOLL_DATA)) ||
ath9k_check_auto_sleep(sc))
ath_rx_ps(sc, skb, rs.is_mybeacon);
spin_unlock_irqrestore(&sc->sc_pm_lock, flags);
if ((ah->caps.hw_caps & ATH9K_HW_CAP_ANT_DIV_COMB) && sc->ant_rx == 3)
ath_ant_comb_scan(sc, &rs);
ieee80211_rx(hw, skb);
requeue_drop_frag:
if (sc->rx.frag) {
dev_kfree_skb_any(sc->rx.frag);
sc->rx.frag = NULL;
}
requeue:
if (edma) {
list_add_tail(&bf->list, &sc->rx.rxbuf);
ath_rx_edma_buf_link(sc, qtype);
} else {
list_move_tail(&bf->list, &sc->rx.rxbuf);
ath_rx_buf_link(sc, bf);
if (!flush)
ath9k_hw_rxena(ah);
}
} while (1);
spin_unlock_bh(&sc->rx.rxbuflock);
if (!(ah->imask & ATH9K_INT_RXEOL)) {
ah->imask |= (ATH9K_INT_RXEOL | ATH9K_INT_RXORN);
ath9k_hw_set_interrupts(ah);
}
return 0;
}
