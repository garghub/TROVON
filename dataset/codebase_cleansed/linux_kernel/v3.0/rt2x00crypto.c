enum cipher rt2x00crypto_key_to_cipher(struct ieee80211_key_conf *key)
{
switch (key->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
return CIPHER_WEP64;
case WLAN_CIPHER_SUITE_WEP104:
return CIPHER_WEP128;
case WLAN_CIPHER_SUITE_TKIP:
return CIPHER_TKIP;
case WLAN_CIPHER_SUITE_CCMP:
return CIPHER_AES;
default:
return CIPHER_NONE;
}
}
void rt2x00crypto_create_tx_descriptor(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(entry->skb);
struct ieee80211_key_conf *hw_key = tx_info->control.hw_key;
if (!test_bit(CAPABILITY_HW_CRYPTO, &rt2x00dev->cap_flags) || !hw_key)
return;
__set_bit(ENTRY_TXD_ENCRYPT, &txdesc->flags);
txdesc->cipher = rt2x00crypto_key_to_cipher(hw_key);
if (hw_key->flags & IEEE80211_KEY_FLAG_PAIRWISE)
__set_bit(ENTRY_TXD_ENCRYPT_PAIRWISE, &txdesc->flags);
txdesc->key_idx = hw_key->hw_key_idx;
txdesc->iv_offset = txdesc->header_length;
txdesc->iv_len = hw_key->iv_len;
if (!(hw_key->flags & IEEE80211_KEY_FLAG_GENERATE_IV))
__set_bit(ENTRY_TXD_ENCRYPT_IV, &txdesc->flags);
if (!(hw_key->flags & IEEE80211_KEY_FLAG_GENERATE_MMIC))
__set_bit(ENTRY_TXD_ENCRYPT_MMIC, &txdesc->flags);
}
unsigned int rt2x00crypto_tx_overhead(struct rt2x00_dev *rt2x00dev,
struct sk_buff *skb)
{
struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
struct ieee80211_key_conf *key = tx_info->control.hw_key;
unsigned int overhead = 0;
if (!test_bit(CAPABILITY_HW_CRYPTO, &rt2x00dev->cap_flags) || !key)
return overhead;
overhead += key->icv_len;
if (!(key->flags & IEEE80211_KEY_FLAG_GENERATE_IV))
overhead += key->iv_len;
if (!(key->flags & IEEE80211_KEY_FLAG_GENERATE_MMIC)) {
if (key->cipher == WLAN_CIPHER_SUITE_TKIP)
overhead += 8;
}
return overhead;
}
void rt2x00crypto_tx_copy_iv(struct sk_buff *skb, struct txentry_desc *txdesc)
{
struct skb_frame_desc *skbdesc = get_skb_frame_desc(skb);
if (unlikely(!txdesc->iv_len))
return;
memcpy(skbdesc->iv, skb->data + txdesc->iv_offset, txdesc->iv_len);
}
void rt2x00crypto_tx_remove_iv(struct sk_buff *skb, struct txentry_desc *txdesc)
{
struct skb_frame_desc *skbdesc = get_skb_frame_desc(skb);
if (unlikely(!txdesc->iv_len))
return;
memcpy(skbdesc->iv, skb->data + txdesc->iv_offset, txdesc->iv_len);
memmove(skb->data + txdesc->iv_len, skb->data, txdesc->iv_offset);
skb_pull(skb, txdesc->iv_len);
txdesc->length -= txdesc->iv_len;
skbdesc->flags |= SKBDESC_IV_STRIPPED;
}
void rt2x00crypto_tx_insert_iv(struct sk_buff *skb, unsigned int header_length)
{
struct skb_frame_desc *skbdesc = get_skb_frame_desc(skb);
const unsigned int iv_len =
((!!(skbdesc->iv[0])) * 4) + ((!!(skbdesc->iv[1])) * 4);
if (!(skbdesc->flags & SKBDESC_IV_STRIPPED))
return;
skb_push(skb, iv_len);
memmove(skb->data, skb->data + iv_len, header_length);
memcpy(skb->data + header_length, skbdesc->iv, iv_len);
skbdesc->flags &= ~SKBDESC_IV_STRIPPED;
}
void rt2x00crypto_rx_insert_iv(struct sk_buff *skb,
unsigned int header_length,
struct rxdone_entry_desc *rxdesc)
{
unsigned int payload_len = rxdesc->size - header_length;
unsigned int align = ALIGN_SIZE(skb, header_length);
unsigned int iv_len;
unsigned int icv_len;
unsigned int transfer = 0;
switch (rxdesc->cipher) {
case CIPHER_WEP64:
case CIPHER_WEP128:
iv_len = 4;
icv_len = 4;
break;
case CIPHER_TKIP:
iv_len = 8;
icv_len = 4;
break;
case CIPHER_AES:
iv_len = 8;
icv_len = 8;
break;
default:
return;
}
if (rxdesc->dev_flags & RXDONE_L2PAD) {
skb_push(skb, iv_len - align);
skb_put(skb, icv_len);
memmove(skb->data + transfer,
skb->data + transfer + (iv_len - align),
header_length);
transfer += header_length;
} else {
skb_push(skb, iv_len + align);
if (align < icv_len)
skb_put(skb, icv_len - align);
else if (align > icv_len)
skb_trim(skb, rxdesc->size + iv_len + icv_len);
memmove(skb->data + transfer,
skb->data + transfer + iv_len + align,
header_length);
transfer += header_length;
}
memcpy(skb->data + transfer, rxdesc->iv, iv_len);
transfer += iv_len;
if (!(rxdesc->dev_flags & RXDONE_L2PAD)) {
memmove(skb->data + transfer,
skb->data + transfer + align,
payload_len);
}
transfer += payload_len;
memcpy(skb->data + transfer, &rxdesc->icv, 4);
transfer += icv_len;
rxdesc->size = transfer;
rxdesc->flags &= ~RX_FLAG_IV_STRIPPED;
}
