static void wl1251_rx_header(struct wl1251 *wl,
struct wl1251_rx_descriptor *desc)
{
u32 rx_packet_ring_addr;
rx_packet_ring_addr = wl->data_path->rx_packet_ring_addr;
if (wl->rx_current_buffer)
rx_packet_ring_addr += wl->data_path->rx_packet_ring_chunk_size;
wl1251_mem_read(wl, rx_packet_ring_addr, desc, sizeof(*desc));
}
static void wl1251_rx_status(struct wl1251 *wl,
struct wl1251_rx_descriptor *desc,
struct ieee80211_rx_status *status,
u8 beacon)
{
u64 mactime;
int ret;
memset(status, 0, sizeof(struct ieee80211_rx_status));
status->band = IEEE80211_BAND_2GHZ;
status->mactime = desc->timestamp;
if ((wl->bss_type == BSS_TYPE_IBSS) && beacon) {
ret = wl1251_acx_tsf_info(wl, &mactime);
if (ret == 0)
status->mactime = mactime;
}
status->signal = desc->rssi;
wl->noise = desc->rssi - desc->snr / 2;
status->freq = ieee80211_channel_to_frequency(desc->channel,
status->band);
status->flag |= RX_FLAG_MACTIME_MPDU;
if (desc->flags & RX_DESC_ENCRYPTION_MASK) {
status->flag |= RX_FLAG_IV_STRIPPED | RX_FLAG_MMIC_STRIPPED;
if (likely(!(desc->flags & RX_DESC_DECRYPT_FAIL)))
status->flag |= RX_FLAG_DECRYPTED;
if (unlikely(desc->flags & RX_DESC_MIC_FAIL))
status->flag |= RX_FLAG_MMIC_ERROR;
}
if (unlikely(!(desc->flags & RX_DESC_VALID_FCS)))
status->flag |= RX_FLAG_FAILED_FCS_CRC;
switch (desc->rate) {
case RATE_2MBPS:
status->rate_idx = 1;
break;
case RATE_5_5MBPS:
status->rate_idx = 2;
break;
case RATE_11MBPS:
status->rate_idx = 3;
break;
case RATE_6MBPS:
status->rate_idx = 4;
break;
case RATE_9MBPS:
status->rate_idx = 5;
break;
case RATE_18MBPS:
status->rate_idx = 7;
break;
case RATE_24MBPS:
status->rate_idx = 8;
break;
case RATE_36MBPS:
status->rate_idx = 9;
break;
case RATE_48MBPS:
status->rate_idx = 10;
break;
case RATE_54MBPS:
status->rate_idx = 11;
break;
}
if (desc->rate == RATE_1MBPS) {
if (!(desc->mod_pre & OFDM_RATE_BIT))
status->rate_idx = 0;
else
status->rate_idx = 6;
}
if (desc->mod_pre & SHORT_PREAMBLE_BIT)
status->flag |= RX_FLAG_SHORTPRE;
}
static void wl1251_rx_body(struct wl1251 *wl,
struct wl1251_rx_descriptor *desc)
{
struct sk_buff *skb;
struct ieee80211_rx_status status;
u8 *rx_buffer, beacon = 0;
u16 length, *fc;
u32 curr_id, last_id_inc, rx_packet_ring_addr;
length = WL1251_RX_ALIGN(desc->length - PLCP_HEADER_LENGTH);
curr_id = (desc->flags & RX_DESC_SEQNUM_MASK) >> RX_DESC_PACKETID_SHIFT;
last_id_inc = (wl->rx_last_id + 1) % (RX_MAX_PACKET_ID + 1);
if (last_id_inc != curr_id) {
wl1251_warning("curr ID:%d, last ID inc:%d",
curr_id, last_id_inc);
wl->rx_last_id = curr_id;
} else {
wl->rx_last_id = last_id_inc;
}
rx_packet_ring_addr = wl->data_path->rx_packet_ring_addr +
sizeof(struct wl1251_rx_descriptor) + 20;
if (wl->rx_current_buffer)
rx_packet_ring_addr += wl->data_path->rx_packet_ring_chunk_size;
skb = __dev_alloc_skb(length, GFP_KERNEL);
if (!skb) {
wl1251_error("Couldn't allocate RX frame");
return;
}
rx_buffer = skb_put(skb, length);
wl1251_mem_read(wl, rx_packet_ring_addr, rx_buffer, length);
skb->len = desc->length - PLCP_HEADER_LENGTH;
fc = (u16 *)skb->data;
if ((*fc & IEEE80211_FCTL_STYPE) == IEEE80211_STYPE_BEACON)
beacon = 1;
wl1251_rx_status(wl, desc, &status, beacon);
wl1251_debug(DEBUG_RX, "rx skb 0x%p: %d B %s", skb, skb->len,
beacon ? "beacon" : "");
memcpy(IEEE80211_SKB_RXCB(skb), &status, sizeof(status));
ieee80211_rx_ni(wl->hw, skb);
}
static void wl1251_rx_ack(struct wl1251 *wl)
{
u32 data, addr;
if (wl->rx_current_buffer) {
addr = ACX_REG_INTERRUPT_TRIG_H;
data = INTR_TRIG_RX_PROC1;
} else {
addr = ACX_REG_INTERRUPT_TRIG;
data = INTR_TRIG_RX_PROC0;
}
wl1251_reg_write32(wl, addr, data);
wl->rx_current_buffer = !wl->rx_current_buffer;
}
void wl1251_rx(struct wl1251 *wl)
{
struct wl1251_rx_descriptor *rx_desc;
if (wl->state != WL1251_STATE_ON)
return;
rx_desc = wl->rx_descriptor;
wl1251_rx_header(wl, rx_desc);
wl1251_rx_body(wl, rx_desc);
wl1251_rx_ack(wl);
}
