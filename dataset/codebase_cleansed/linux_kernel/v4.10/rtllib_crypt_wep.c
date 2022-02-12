static void *prism2_wep_init(int keyidx)
{
struct prism2_wep_data *priv;
priv = kzalloc(sizeof(*priv), GFP_ATOMIC);
if (priv == NULL)
goto fail;
priv->key_idx = keyidx;
priv->tx_tfm = crypto_alloc_skcipher("ecb(arc4)", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(priv->tx_tfm)) {
pr_debug("rtllib_crypt_wep: could not allocate crypto API arc4\n");
priv->tx_tfm = NULL;
goto fail;
}
priv->rx_tfm = crypto_alloc_skcipher("ecb(arc4)", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(priv->rx_tfm)) {
pr_debug("rtllib_crypt_wep: could not allocate crypto API arc4\n");
priv->rx_tfm = NULL;
goto fail;
}
get_random_bytes(&priv->iv, 4);
return priv;
fail:
if (priv) {
crypto_free_skcipher(priv->tx_tfm);
crypto_free_skcipher(priv->rx_tfm);
kfree(priv);
}
return NULL;
}
static void prism2_wep_deinit(void *priv)
{
struct prism2_wep_data *_priv = priv;
if (_priv) {
crypto_free_skcipher(_priv->tx_tfm);
crypto_free_skcipher(_priv->rx_tfm);
}
kfree(priv);
}
static int prism2_wep_encrypt(struct sk_buff *skb, int hdr_len, void *priv)
{
struct prism2_wep_data *wep = priv;
u32 klen, len;
u8 key[WEP_KEY_LEN + 3];
u8 *pos;
struct cb_desc *tcb_desc = (struct cb_desc *)(skb->cb +
MAX_DEV_ADDR_SIZE);
u32 crc;
u8 *icv;
struct scatterlist sg;
int err;
if (skb_headroom(skb) < 4 || skb_tailroom(skb) < 4 ||
skb->len < hdr_len){
pr_err("Error!!! headroom=%d tailroom=%d skblen=%d hdr_len=%d\n",
skb_headroom(skb), skb_tailroom(skb), skb->len, hdr_len);
return -1;
}
len = skb->len - hdr_len;
pos = skb_push(skb, 4);
memmove(pos, pos + 4, hdr_len);
pos += hdr_len;
klen = 3 + wep->key_len;
wep->iv++;
if ((wep->iv & 0xff00) == 0xff00) {
u8 B = (wep->iv >> 16) & 0xff;
if (B >= 3 && B < klen)
wep->iv += 0x0100;
}
*pos++ = key[0] = (wep->iv >> 16) & 0xff;
*pos++ = key[1] = (wep->iv >> 8) & 0xff;
*pos++ = key[2] = wep->iv & 0xff;
*pos++ = wep->key_idx << 6;
memcpy(key + 3, wep->key, wep->key_len);
if (!tcb_desc->bHwSec) {
SKCIPHER_REQUEST_ON_STACK(req, wep->tx_tfm);
crc = ~crc32_le(~0, pos, len);
icv = skb_put(skb, 4);
icv[0] = crc;
icv[1] = crc >> 8;
icv[2] = crc >> 16;
icv[3] = crc >> 24;
sg_init_one(&sg, pos, len+4);
crypto_skcipher_setkey(wep->tx_tfm, key, klen);
skcipher_request_set_tfm(req, wep->tx_tfm);
skcipher_request_set_callback(req, 0, NULL, NULL);
skcipher_request_set_crypt(req, &sg, &sg, len + 4, NULL);
err = crypto_skcipher_encrypt(req);
skcipher_request_zero(req);
return err;
}
return 0;
}
static int prism2_wep_decrypt(struct sk_buff *skb, int hdr_len, void *priv)
{
struct prism2_wep_data *wep = priv;
u32 klen, plen;
u8 key[WEP_KEY_LEN + 3];
u8 keyidx, *pos;
struct cb_desc *tcb_desc = (struct cb_desc *)(skb->cb +
MAX_DEV_ADDR_SIZE);
u32 crc;
u8 icv[4];
struct scatterlist sg;
int err;
if (skb->len < hdr_len + 8)
return -1;
pos = skb->data + hdr_len;
key[0] = *pos++;
key[1] = *pos++;
key[2] = *pos++;
keyidx = *pos++ >> 6;
if (keyidx != wep->key_idx)
return -1;
klen = 3 + wep->key_len;
memcpy(key + 3, wep->key, wep->key_len);
plen = skb->len - hdr_len - 8;
if (!tcb_desc->bHwSec) {
SKCIPHER_REQUEST_ON_STACK(req, wep->rx_tfm);
sg_init_one(&sg, pos, plen+4);
crypto_skcipher_setkey(wep->rx_tfm, key, klen);
skcipher_request_set_tfm(req, wep->rx_tfm);
skcipher_request_set_callback(req, 0, NULL, NULL);
skcipher_request_set_crypt(req, &sg, &sg, plen + 4, NULL);
err = crypto_skcipher_decrypt(req);
skcipher_request_zero(req);
if (err)
return -7;
crc = ~crc32_le(~0, pos, plen);
icv[0] = crc;
icv[1] = crc >> 8;
icv[2] = crc >> 16;
icv[3] = crc >> 24;
if (memcmp(icv, pos + plen, 4) != 0) {
return -2;
}
}
memmove(skb->data + 4, skb->data, hdr_len);
skb_pull(skb, 4);
skb_trim(skb, skb->len - 4);
return 0;
}
static int prism2_wep_set_key(void *key, int len, u8 *seq, void *priv)
{
struct prism2_wep_data *wep = priv;
if (len < 0 || len > WEP_KEY_LEN)
return -1;
memcpy(wep->key, key, len);
wep->key_len = len;
return 0;
}
static int prism2_wep_get_key(void *key, int len, u8 *seq, void *priv)
{
struct prism2_wep_data *wep = priv;
if (len < wep->key_len)
return -1;
memcpy(key, wep->key, wep->key_len);
return wep->key_len;
}
static void prism2_wep_print_stats(struct seq_file *m, void *priv)
{
struct prism2_wep_data *wep = priv;
seq_printf(m, "key[%d] alg=WEP len=%d\n", wep->key_idx, wep->key_len);
}
static int __init rtllib_crypto_wep_init(void)
{
return lib80211_register_crypto_ops(&rtllib_crypt_wep);
}
static void __exit rtllib_crypto_wep_exit(void)
{
lib80211_unregister_crypto_ops(&rtllib_crypt_wep);
}
