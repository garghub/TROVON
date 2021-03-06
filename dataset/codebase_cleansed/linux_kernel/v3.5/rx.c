static u32 wlcore_rx_get_buf_size(struct wl1271 *wl,
u32 rx_pkt_desc)
{
if (wl->quirks & WLCORE_QUIRK_RX_BLOCKSIZE_ALIGN)
return (rx_pkt_desc & ALIGNED_RX_BUF_SIZE_MASK) >>
ALIGNED_RX_BUF_SIZE_SHIFT;
return (rx_pkt_desc & RX_BUF_SIZE_MASK) >> RX_BUF_SIZE_SHIFT_DIV;
}
static u32 wlcore_rx_get_align_buf_size(struct wl1271 *wl, u32 pkt_len)
{
if (wl->quirks & WLCORE_QUIRK_RX_BLOCKSIZE_ALIGN)
return ALIGN(pkt_len, WL12XX_BUS_BLOCK_SIZE);
return pkt_len;
}
static void wl1271_rx_status(struct wl1271 *wl,
struct wl1271_rx_descriptor *desc,
struct ieee80211_rx_status *status,
u8 beacon)
{
memset(status, 0, sizeof(struct ieee80211_rx_status));
if ((desc->flags & WL1271_RX_DESC_BAND_MASK) == WL1271_RX_DESC_BAND_BG)
status->band = IEEE80211_BAND_2GHZ;
else
status->band = IEEE80211_BAND_5GHZ;
status->rate_idx = wlcore_rate_to_idx(wl, desc->rate, status->band);
if (desc->rate <= wl->hw_min_ht_rate)
status->flag |= RX_FLAG_HT;
status->signal = desc->rssi;
wl->noise = desc->rssi - (desc->snr >> 1);
status->freq = ieee80211_channel_to_frequency(desc->channel,
status->band);
if (desc->flags & WL1271_RX_DESC_ENCRYPT_MASK) {
u8 desc_err_code = desc->status & WL1271_RX_DESC_STATUS_MASK;
status->flag |= RX_FLAG_IV_STRIPPED | RX_FLAG_MMIC_STRIPPED |
RX_FLAG_DECRYPTED;
if (unlikely(desc_err_code == WL1271_RX_DESC_MIC_FAIL)) {
status->flag |= RX_FLAG_MMIC_ERROR;
wl1271_warning("Michael MIC error");
}
}
}
static int wl1271_rx_handle_data(struct wl1271 *wl, u8 *data, u32 length,
enum wl_rx_buf_align rx_align, u8 *hlid)
{
struct wl1271_rx_descriptor *desc;
struct sk_buff *skb;
struct ieee80211_hdr *hdr;
u8 *buf;
u8 beacon = 0;
u8 is_data = 0;
u8 reserved = 0;
u16 seq_num;
u32 pkt_data_len;
if (unlikely(wl->plt))
return -EINVAL;
pkt_data_len = wlcore_hw_get_rx_packet_len(wl, data, length);
if (!pkt_data_len) {
wl1271_error("Invalid packet arrived from HW. length %d",
length);
return -EINVAL;
}
if (rx_align == WLCORE_RX_BUF_UNALIGNED)
reserved = NET_IP_ALIGN;
desc = (struct wl1271_rx_descriptor *) data;
if (desc->packet_class == WL12XX_RX_CLASS_LOGGER) {
size_t len = length - sizeof(*desc);
wl12xx_copy_fwlog(wl, data + sizeof(*desc), len);
wake_up_interruptible(&wl->fwlog_waitq);
return 0;
}
switch (desc->status & WL1271_RX_DESC_STATUS_MASK) {
case WL1271_RX_DESC_DRIVER_RX_Q_FAIL:
case WL1271_RX_DESC_DECRYPT_FAIL:
wl1271_warning("corrupted packet in RX with status: 0x%x",
desc->status & WL1271_RX_DESC_STATUS_MASK);
return -EINVAL;
case WL1271_RX_DESC_SUCCESS:
case WL1271_RX_DESC_MIC_FAIL:
break;
default:
wl1271_error("invalid RX descriptor status: 0x%x",
desc->status & WL1271_RX_DESC_STATUS_MASK);
return -EINVAL;
}
skb = __dev_alloc_skb(pkt_data_len + reserved, GFP_KERNEL);
if (!skb) {
wl1271_error("Couldn't allocate RX frame");
return -ENOMEM;
}
skb_reserve(skb, reserved);
buf = skb_put(skb, pkt_data_len);
memcpy(buf, data + sizeof(*desc), pkt_data_len);
if (rx_align == WLCORE_RX_BUF_PADDED)
skb_pull(skb, NET_IP_ALIGN);
*hlid = desc->hlid;
hdr = (struct ieee80211_hdr *)skb->data;
if (ieee80211_is_beacon(hdr->frame_control))
beacon = 1;
if (ieee80211_is_data_present(hdr->frame_control))
is_data = 1;
wl1271_rx_status(wl, desc, IEEE80211_SKB_RXCB(skb), beacon);
seq_num = (le16_to_cpu(hdr->seq_ctrl) & IEEE80211_SCTL_SEQ) >> 4;
wl1271_debug(DEBUG_RX, "rx skb 0x%p: %d B %s seq %d hlid %d", skb,
skb->len - desc->pad_len,
beacon ? "beacon" : "",
seq_num, *hlid);
skb_queue_tail(&wl->deferred_rx_queue, skb);
queue_work(wl->freezable_wq, &wl->netstack_work);
return is_data;
}
void wl12xx_rx(struct wl1271 *wl, struct wl_fw_status *status)
{
unsigned long active_hlids[BITS_TO_LONGS(WL12XX_MAX_LINKS)] = {0};
u32 buf_size;
u32 fw_rx_counter = status->fw_rx_counter & NUM_RX_PKT_DESC_MOD_MASK;
u32 drv_rx_counter = wl->rx_counter & NUM_RX_PKT_DESC_MOD_MASK;
u32 rx_counter;
u32 pkt_len, align_pkt_len;
u32 pkt_offset, des;
u8 hlid;
enum wl_rx_buf_align rx_align;
while (drv_rx_counter != fw_rx_counter) {
buf_size = 0;
rx_counter = drv_rx_counter;
while (rx_counter != fw_rx_counter) {
des = le32_to_cpu(status->rx_pkt_descs[rx_counter]);
pkt_len = wlcore_rx_get_buf_size(wl, des);
align_pkt_len = wlcore_rx_get_align_buf_size(wl,
pkt_len);
if (buf_size + align_pkt_len > WL1271_AGGR_BUFFER_SIZE)
break;
buf_size += align_pkt_len;
rx_counter++;
rx_counter &= NUM_RX_PKT_DESC_MOD_MASK;
}
if (buf_size == 0) {
wl1271_warning("received empty data");
break;
}
des = le32_to_cpu(status->rx_pkt_descs[drv_rx_counter]);
wlcore_hw_prepare_read(wl, des, buf_size);
wlcore_read_data(wl, REG_SLV_MEM_DATA, wl->aggr_buf,
buf_size, true);
pkt_offset = 0;
while (pkt_offset < buf_size) {
des = le32_to_cpu(status->rx_pkt_descs[drv_rx_counter]);
pkt_len = wlcore_rx_get_buf_size(wl, des);
rx_align = wlcore_hw_get_rx_buf_align(wl, des);
if (wl1271_rx_handle_data(wl,
wl->aggr_buf + pkt_offset,
pkt_len, rx_align,
&hlid) == 1) {
if (hlid < WL12XX_MAX_LINKS)
__set_bit(hlid, active_hlids);
else
WARN(1,
"hlid exceeded WL12XX_MAX_LINKS "
"(%d)\n", hlid);
}
wl->rx_counter++;
drv_rx_counter++;
drv_rx_counter &= NUM_RX_PKT_DESC_MOD_MASK;
pkt_offset += wlcore_rx_get_align_buf_size(wl, pkt_len);
}
}
if (wl->quirks & WLCORE_QUIRK_END_OF_TRANSACTION)
wl1271_write32(wl, WL12XX_REG_RX_DRIVER_COUNTER,
wl->rx_counter);
wl12xx_rearm_rx_streaming(wl, active_hlids);
}
int wl1271_rx_filter_enable(struct wl1271 *wl,
int index, bool enable,
struct wl12xx_rx_filter *filter)
{
int ret;
if (wl->rx_filter_enabled[index] == enable) {
wl1271_warning("Request to enable an already "
"enabled rx filter %d", index);
return 0;
}
ret = wl1271_acx_set_rx_filter(wl, index, enable, filter);
if (ret) {
wl1271_error("Failed to %s rx data filter %d (err=%d)",
enable ? "enable" : "disable", index, ret);
return ret;
}
wl->rx_filter_enabled[index] = enable;
return 0;
}
void wl1271_rx_filter_clear_all(struct wl1271 *wl)
{
int i;
for (i = 0; i < WL1271_MAX_RX_FILTERS; i++) {
if (!wl->rx_filter_enabled[i])
continue;
wl1271_rx_filter_enable(wl, i, 0, NULL);
}
}
