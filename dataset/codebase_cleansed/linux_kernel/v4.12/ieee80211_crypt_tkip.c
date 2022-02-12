static void *ieee80211_tkip_init(int key_idx)
{
struct ieee80211_tkip_data *priv;
priv = kzalloc(sizeof(*priv), GFP_ATOMIC);
if (!priv)
goto fail;
priv->key_idx = key_idx;
priv->tx_tfm_arc4 = crypto_alloc_skcipher("ecb(arc4)", 0,
CRYPTO_ALG_ASYNC);
if (IS_ERR(priv->tx_tfm_arc4)) {
printk(KERN_DEBUG "ieee80211_crypt_tkip: could not allocate "
"crypto API arc4\n");
priv->tx_tfm_arc4 = NULL;
goto fail;
}
priv->tx_tfm_michael = crypto_alloc_ahash("michael_mic", 0,
CRYPTO_ALG_ASYNC);
if (IS_ERR(priv->tx_tfm_michael)) {
printk(KERN_DEBUG "ieee80211_crypt_tkip: could not allocate "
"crypto API michael_mic\n");
priv->tx_tfm_michael = NULL;
goto fail;
}
priv->rx_tfm_arc4 = crypto_alloc_skcipher("ecb(arc4)", 0,
CRYPTO_ALG_ASYNC);
if (IS_ERR(priv->rx_tfm_arc4)) {
printk(KERN_DEBUG "ieee80211_crypt_tkip: could not allocate "
"crypto API arc4\n");
priv->rx_tfm_arc4 = NULL;
goto fail;
}
priv->rx_tfm_michael = crypto_alloc_ahash("michael_mic", 0,
CRYPTO_ALG_ASYNC);
if (IS_ERR(priv->rx_tfm_michael)) {
printk(KERN_DEBUG "ieee80211_crypt_tkip: could not allocate "
"crypto API michael_mic\n");
priv->rx_tfm_michael = NULL;
goto fail;
}
return priv;
fail:
if (priv) {
crypto_free_ahash(priv->tx_tfm_michael);
crypto_free_skcipher(priv->tx_tfm_arc4);
crypto_free_ahash(priv->rx_tfm_michael);
crypto_free_skcipher(priv->rx_tfm_arc4);
kfree(priv);
}
return NULL;
}
static void ieee80211_tkip_deinit(void *priv)
{
struct ieee80211_tkip_data *_priv = priv;
if (_priv) {
crypto_free_ahash(_priv->tx_tfm_michael);
crypto_free_skcipher(_priv->tx_tfm_arc4);
crypto_free_ahash(_priv->rx_tfm_michael);
crypto_free_skcipher(_priv->rx_tfm_arc4);
}
kfree(priv);
}
static inline u16 RotR1(u16 val)
{
return (val >> 1) | (val << 15);
}
static inline u8 Lo8(u16 val)
{
return val & 0xff;
}
static inline u8 Hi8(u16 val)
{
return val >> 8;
}
static inline u16 Lo16(u32 val)
{
return val & 0xffff;
}
static inline u16 Hi16(u32 val)
{
return val >> 16;
}
static inline u16 Mk16(u8 hi, u8 lo)
{
return lo | (((u16) hi) << 8);
}
static inline u16 Mk16_le(u16 *v)
{
return le16_to_cpu(*v);
}
static inline u16 _S_(u16 v)
{
u16 t = Sbox[Hi8(v)];
return Sbox[Lo8(v)] ^ ((t << 8) | (t >> 8));
}
static void tkip_mixing_phase1(u16 *TTAK, const u8 *TK, const u8 *TA, u32 IV32)
{
int i, j;
TTAK[0] = Lo16(IV32);
TTAK[1] = Hi16(IV32);
TTAK[2] = Mk16(TA[1], TA[0]);
TTAK[3] = Mk16(TA[3], TA[2]);
TTAK[4] = Mk16(TA[5], TA[4]);
for (i = 0; i < PHASE1_LOOP_COUNT; i++) {
j = 2 * (i & 1);
TTAK[0] += _S_(TTAK[4] ^ Mk16(TK[1 + j], TK[0 + j]));
TTAK[1] += _S_(TTAK[0] ^ Mk16(TK[5 + j], TK[4 + j]));
TTAK[2] += _S_(TTAK[1] ^ Mk16(TK[9 + j], TK[8 + j]));
TTAK[3] += _S_(TTAK[2] ^ Mk16(TK[13 + j], TK[12 + j]));
TTAK[4] += _S_(TTAK[3] ^ Mk16(TK[1 + j], TK[0 + j])) + i;
}
}
static void tkip_mixing_phase2(u8 *WEPSeed, const u8 *TK, const u16 *TTAK,
u16 IV16)
{
u16 *PPK = (u16 *) &WEPSeed[4];
PPK[0] = TTAK[0];
PPK[1] = TTAK[1];
PPK[2] = TTAK[2];
PPK[3] = TTAK[3];
PPK[4] = TTAK[4];
PPK[5] = TTAK[4] + IV16;
PPK[0] += _S_(PPK[5] ^ Mk16_le((u16 *) &TK[0]));
PPK[1] += _S_(PPK[0] ^ Mk16_le((u16 *) &TK[2]));
PPK[2] += _S_(PPK[1] ^ Mk16_le((u16 *) &TK[4]));
PPK[3] += _S_(PPK[2] ^ Mk16_le((u16 *) &TK[6]));
PPK[4] += _S_(PPK[3] ^ Mk16_le((u16 *) &TK[8]));
PPK[5] += _S_(PPK[4] ^ Mk16_le((u16 *) &TK[10]));
PPK[0] += RotR1(PPK[5] ^ Mk16_le((u16 *) &TK[12]));
PPK[1] += RotR1(PPK[0] ^ Mk16_le((u16 *) &TK[14]));
PPK[2] += RotR1(PPK[1]);
PPK[3] += RotR1(PPK[2]);
PPK[4] += RotR1(PPK[3]);
PPK[5] += RotR1(PPK[4]);
WEPSeed[0] = Hi8(IV16);
WEPSeed[1] = (Hi8(IV16) | 0x20) & 0x7F;
WEPSeed[2] = Lo8(IV16);
WEPSeed[3] = Lo8((PPK[5] ^ Mk16_le((u16 *) &TK[0])) >> 1);
#ifdef __BIG_ENDIAN
{
int i;
for (i = 0; i < 6; i++)
PPK[i] = (PPK[i] << 8) | (PPK[i] >> 8);
}
#endif
}
static int ieee80211_tkip_encrypt(struct sk_buff *skb, int hdr_len, void *priv)
{
struct ieee80211_tkip_data *tkey = priv;
int len;
u8 *pos;
struct rtl_80211_hdr_4addr *hdr;
struct cb_desc *tcb_desc = (struct cb_desc *)(skb->cb + MAX_DEV_ADDR_SIZE);
int ret = 0;
u8 rc4key[16], *icv;
u32 crc;
struct scatterlist sg;
if (skb_headroom(skb) < 8 || skb_tailroom(skb) < 4 ||
skb->len < hdr_len)
return -1;
hdr = (struct rtl_80211_hdr_4addr *) skb->data;
if (!tcb_desc->bHwSec) {
if (!tkey->tx_phase1_done) {
tkip_mixing_phase1(tkey->tx_ttak, tkey->key, hdr->addr2,
tkey->tx_iv32);
tkey->tx_phase1_done = 1;
}
tkip_mixing_phase2(rc4key, tkey->key, tkey->tx_ttak, tkey->tx_iv16);
} else
tkey->tx_phase1_done = 1;
len = skb->len - hdr_len;
pos = skb_push(skb, 8);
memmove(pos, pos + 8, hdr_len);
pos += hdr_len;
if (tcb_desc->bHwSec) {
*pos++ = Hi8(tkey->tx_iv16);
*pos++ = (Hi8(tkey->tx_iv16) | 0x20) & 0x7F;
*pos++ = Lo8(tkey->tx_iv16);
} else {
*pos++ = rc4key[0];
*pos++ = rc4key[1];
*pos++ = rc4key[2];
}
*pos++ = (tkey->key_idx << 6) | (1 << 5) ;
*pos++ = tkey->tx_iv32 & 0xff;
*pos++ = (tkey->tx_iv32 >> 8) & 0xff;
*pos++ = (tkey->tx_iv32 >> 16) & 0xff;
*pos++ = (tkey->tx_iv32 >> 24) & 0xff;
if (!tcb_desc->bHwSec) {
SKCIPHER_REQUEST_ON_STACK(req, tkey->tx_tfm_arc4);
icv = skb_put(skb, 4);
crc = ~crc32_le(~0, pos, len);
icv[0] = crc;
icv[1] = crc >> 8;
icv[2] = crc >> 16;
icv[3] = crc >> 24;
crypto_skcipher_setkey(tkey->tx_tfm_arc4, rc4key, 16);
sg_init_one(&sg, pos, len+4);
skcipher_request_set_tfm(req, tkey->tx_tfm_arc4);
skcipher_request_set_callback(req, 0, NULL, NULL);
skcipher_request_set_crypt(req, &sg, &sg, len + 4, NULL);
ret = crypto_skcipher_encrypt(req);
skcipher_request_zero(req);
}
tkey->tx_iv16++;
if (tkey->tx_iv16 == 0) {
tkey->tx_phase1_done = 0;
tkey->tx_iv32++;
}
if (!tcb_desc->bHwSec)
return ret;
else
return 0;
}
static int ieee80211_tkip_decrypt(struct sk_buff *skb, int hdr_len, void *priv)
{
struct ieee80211_tkip_data *tkey = priv;
u8 keyidx, *pos;
u32 iv32;
u16 iv16;
struct rtl_80211_hdr_4addr *hdr;
struct cb_desc *tcb_desc = (struct cb_desc *)(skb->cb + MAX_DEV_ADDR_SIZE);
u8 rc4key[16];
u8 icv[4];
u32 crc;
struct scatterlist sg;
int plen;
int err;
if (skb->len < hdr_len + 8 + 4)
return -1;
hdr = (struct rtl_80211_hdr_4addr *) skb->data;
pos = skb->data + hdr_len;
keyidx = pos[3];
if (!(keyidx & (1 << 5))) {
if (net_ratelimit()) {
printk(KERN_DEBUG "TKIP: received packet without ExtIV"
" flag from %pM\n", hdr->addr2);
}
return -2;
}
keyidx >>= 6;
if (tkey->key_idx != keyidx) {
printk(KERN_DEBUG "TKIP: RX tkey->key_idx=%d frame "
"keyidx=%d priv=%p\n", tkey->key_idx, keyidx, priv);
return -6;
}
if (!tkey->key_set) {
if (net_ratelimit()) {
printk(KERN_DEBUG "TKIP: received packet from %pM"
" with keyid=%d that does not have a configured"
" key\n", hdr->addr2, keyidx);
}
return -3;
}
iv16 = (pos[0] << 8) | pos[2];
iv32 = pos[4] | (pos[5] << 8) | (pos[6] << 16) | (pos[7] << 24);
pos += 8;
if (!tcb_desc->bHwSec) {
SKCIPHER_REQUEST_ON_STACK(req, tkey->rx_tfm_arc4);
if (iv32 < tkey->rx_iv32 ||
(iv32 == tkey->rx_iv32 && iv16 <= tkey->rx_iv16)) {
if (net_ratelimit()) {
printk(KERN_DEBUG "TKIP: replay detected: STA=%pM"
" previous TSC %08x%04x received TSC "
"%08x%04x\n", hdr->addr2,
tkey->rx_iv32, tkey->rx_iv16, iv32, iv16);
}
tkey->dot11RSNAStatsTKIPReplays++;
return -4;
}
if (iv32 != tkey->rx_iv32 || !tkey->rx_phase1_done) {
tkip_mixing_phase1(tkey->rx_ttak, tkey->key, hdr->addr2, iv32);
tkey->rx_phase1_done = 1;
}
tkip_mixing_phase2(rc4key, tkey->key, tkey->rx_ttak, iv16);
plen = skb->len - hdr_len - 12;
crypto_skcipher_setkey(tkey->rx_tfm_arc4, rc4key, 16);
sg_init_one(&sg, pos, plen+4);
skcipher_request_set_tfm(req, tkey->rx_tfm_arc4);
skcipher_request_set_callback(req, 0, NULL, NULL);
skcipher_request_set_crypt(req, &sg, &sg, plen + 4, NULL);
err = crypto_skcipher_decrypt(req);
skcipher_request_zero(req);
if (err) {
if (net_ratelimit()) {
printk(KERN_DEBUG ": TKIP: failed to decrypt "
"received packet from %pM\n",
hdr->addr2);
}
return -7;
}
crc = ~crc32_le(~0, pos, plen);
icv[0] = crc;
icv[1] = crc >> 8;
icv[2] = crc >> 16;
icv[3] = crc >> 24;
if (memcmp(icv, pos + plen, 4) != 0) {
if (iv32 != tkey->rx_iv32) {
tkey->rx_phase1_done = 0;
}
if (net_ratelimit()) {
printk(KERN_DEBUG "TKIP: ICV error detected: STA="
"%pM\n", hdr->addr2);
}
tkey->dot11RSNAStatsTKIPICVErrors++;
return -5;
}
}
tkey->rx_iv32_new = iv32;
tkey->rx_iv16_new = iv16;
memmove(skb->data + 8, skb->data, hdr_len);
skb_pull(skb, 8);
skb_trim(skb, skb->len - 4);
return keyidx;
}
static int michael_mic(struct crypto_ahash *tfm_michael, u8 *key, u8 *hdr,
u8 *data, size_t data_len, u8 *mic)
{
AHASH_REQUEST_ON_STACK(req, tfm_michael);
struct scatterlist sg[2];
int err;
if (tfm_michael == NULL) {
printk(KERN_WARNING "michael_mic: tfm_michael == NULL\n");
return -1;
}
sg_init_table(sg, 2);
sg_set_buf(&sg[0], hdr, 16);
sg_set_buf(&sg[1], data, data_len);
if (crypto_ahash_setkey(tfm_michael, key, 8))
return -1;
ahash_request_set_tfm(req, tfm_michael);
ahash_request_set_callback(req, 0, NULL, NULL);
ahash_request_set_crypt(req, sg, mic, data_len + 16);
err = crypto_ahash_digest(req);
ahash_request_zero(req);
return err;
}
static void michael_mic_hdr(struct sk_buff *skb, u8 *hdr)
{
struct rtl_80211_hdr_4addr *hdr11;
hdr11 = (struct rtl_80211_hdr_4addr *) skb->data;
switch (le16_to_cpu(hdr11->frame_ctl) &
(IEEE80211_FCTL_FROMDS | IEEE80211_FCTL_TODS)) {
case IEEE80211_FCTL_TODS:
memcpy(hdr, hdr11->addr3, ETH_ALEN);
memcpy(hdr + ETH_ALEN, hdr11->addr2, ETH_ALEN);
break;
case IEEE80211_FCTL_FROMDS:
memcpy(hdr, hdr11->addr1, ETH_ALEN);
memcpy(hdr + ETH_ALEN, hdr11->addr3, ETH_ALEN);
break;
case IEEE80211_FCTL_FROMDS | IEEE80211_FCTL_TODS:
memcpy(hdr, hdr11->addr3, ETH_ALEN);
memcpy(hdr + ETH_ALEN, hdr11->addr4, ETH_ALEN);
break;
default:
memcpy(hdr, hdr11->addr1, ETH_ALEN);
memcpy(hdr + ETH_ALEN, hdr11->addr2, ETH_ALEN);
break;
}
hdr[12] = 0;
hdr[13] = hdr[14] = hdr[15] = 0;
}
static int ieee80211_michael_mic_add(struct sk_buff *skb, int hdr_len, void *priv)
{
struct ieee80211_tkip_data *tkey = priv;
u8 *pos;
struct rtl_80211_hdr_4addr *hdr;
hdr = (struct rtl_80211_hdr_4addr *) skb->data;
if (skb_tailroom(skb) < 8 || skb->len < hdr_len) {
printk(KERN_DEBUG "Invalid packet for Michael MIC add "
"(tailroom=%d hdr_len=%d skb->len=%d)\n",
skb_tailroom(skb), hdr_len, skb->len);
return -1;
}
michael_mic_hdr(skb, tkey->tx_hdr);
if (IEEE80211_QOS_HAS_SEQ(le16_to_cpu(hdr->frame_ctl)))
tkey->tx_hdr[12] = *(skb->data + hdr_len - 2) & 0x07;
pos = skb_put(skb, 8);
if (michael_mic(tkey->tx_tfm_michael, &tkey->key[16], tkey->tx_hdr,
skb->data + hdr_len, skb->len - 8 - hdr_len, pos))
return -1;
return 0;
}
static void ieee80211_michael_mic_failure(struct net_device *dev,
struct rtl_80211_hdr_4addr *hdr,
int keyidx)
{
union iwreq_data wrqu;
struct iw_michaelmicfailure ev;
memset(&ev, 0, sizeof(ev));
ev.flags = keyidx & IW_MICFAILURE_KEY_ID;
if (hdr->addr1[0] & 0x01)
ev.flags |= IW_MICFAILURE_GROUP;
else
ev.flags |= IW_MICFAILURE_PAIRWISE;
ev.src_addr.sa_family = ARPHRD_ETHER;
memcpy(ev.src_addr.sa_data, hdr->addr2, ETH_ALEN);
memset(&wrqu, 0, sizeof(wrqu));
wrqu.data.length = sizeof(ev);
wireless_send_event(dev, IWEVMICHAELMICFAILURE, &wrqu, (char *) &ev);
}
static int ieee80211_michael_mic_verify(struct sk_buff *skb, int keyidx,
int hdr_len, void *priv)
{
struct ieee80211_tkip_data *tkey = priv;
u8 mic[8];
struct rtl_80211_hdr_4addr *hdr;
hdr = (struct rtl_80211_hdr_4addr *) skb->data;
if (!tkey->key_set)
return -1;
michael_mic_hdr(skb, tkey->rx_hdr);
if (IEEE80211_QOS_HAS_SEQ(le16_to_cpu(hdr->frame_ctl)))
tkey->rx_hdr[12] = *(skb->data + hdr_len - 2) & 0x07;
if (michael_mic(tkey->rx_tfm_michael, &tkey->key[24], tkey->rx_hdr,
skb->data + hdr_len, skb->len - 8 - hdr_len, mic))
return -1;
if (memcmp(mic, skb->data + skb->len - 8, 8) != 0) {
struct rtl_80211_hdr_4addr *hdr;
hdr = (struct rtl_80211_hdr_4addr *) skb->data;
printk(KERN_DEBUG "%s: Michael MIC verification failed for "
"MSDU from %pM keyidx=%d\n",
skb->dev ? skb->dev->name : "N/A", hdr->addr2,
keyidx);
if (skb->dev)
ieee80211_michael_mic_failure(skb->dev, hdr, keyidx);
tkey->dot11RSNAStatsTKIPLocalMICFailures++;
return -1;
}
tkey->rx_iv32 = tkey->rx_iv32_new;
tkey->rx_iv16 = tkey->rx_iv16_new;
skb_trim(skb, skb->len - 8);
return 0;
}
static int ieee80211_tkip_set_key(void *key, int len, u8 *seq, void *priv)
{
struct ieee80211_tkip_data *tkey = priv;
int keyidx;
struct crypto_ahash *tfm = tkey->tx_tfm_michael;
struct crypto_skcipher *tfm2 = tkey->tx_tfm_arc4;
struct crypto_ahash *tfm3 = tkey->rx_tfm_michael;
struct crypto_skcipher *tfm4 = tkey->rx_tfm_arc4;
keyidx = tkey->key_idx;
memset(tkey, 0, sizeof(*tkey));
tkey->key_idx = keyidx;
tkey->tx_tfm_michael = tfm;
tkey->tx_tfm_arc4 = tfm2;
tkey->rx_tfm_michael = tfm3;
tkey->rx_tfm_arc4 = tfm4;
if (len == TKIP_KEY_LEN) {
memcpy(tkey->key, key, TKIP_KEY_LEN);
tkey->key_set = 1;
tkey->tx_iv16 = 1;
if (seq) {
tkey->rx_iv32 = (seq[5] << 24) | (seq[4] << 16) |
(seq[3] << 8) | seq[2];
tkey->rx_iv16 = (seq[1] << 8) | seq[0];
}
} else if (len == 0)
tkey->key_set = 0;
else
return -1;
return 0;
}
static int ieee80211_tkip_get_key(void *key, int len, u8 *seq, void *priv)
{
struct ieee80211_tkip_data *tkey = priv;
if (len < TKIP_KEY_LEN)
return -1;
if (!tkey->key_set)
return 0;
memcpy(key, tkey->key, TKIP_KEY_LEN);
if (seq) {
u16 iv16 = tkey->tx_iv16;
u32 iv32 = tkey->tx_iv32;
if (iv16 == 0)
iv32--;
iv16--;
seq[0] = tkey->tx_iv16;
seq[1] = tkey->tx_iv16 >> 8;
seq[2] = tkey->tx_iv32;
seq[3] = tkey->tx_iv32 >> 8;
seq[4] = tkey->tx_iv32 >> 16;
seq[5] = tkey->tx_iv32 >> 24;
}
return TKIP_KEY_LEN;
}
static char *ieee80211_tkip_print_stats(char *p, void *priv)
{
struct ieee80211_tkip_data *tkip = priv;
p += sprintf(p, "key[%d] alg=TKIP key_set=%d "
"tx_pn=%02x%02x%02x%02x%02x%02x "
"rx_pn=%02x%02x%02x%02x%02x%02x "
"replays=%d icv_errors=%d local_mic_failures=%d\n",
tkip->key_idx, tkip->key_set,
(tkip->tx_iv32 >> 24) & 0xff,
(tkip->tx_iv32 >> 16) & 0xff,
(tkip->tx_iv32 >> 8) & 0xff,
tkip->tx_iv32 & 0xff,
(tkip->tx_iv16 >> 8) & 0xff,
tkip->tx_iv16 & 0xff,
(tkip->rx_iv32 >> 24) & 0xff,
(tkip->rx_iv32 >> 16) & 0xff,
(tkip->rx_iv32 >> 8) & 0xff,
tkip->rx_iv32 & 0xff,
(tkip->rx_iv16 >> 8) & 0xff,
tkip->rx_iv16 & 0xff,
tkip->dot11RSNAStatsTKIPReplays,
tkip->dot11RSNAStatsTKIPICVErrors,
tkip->dot11RSNAStatsTKIPLocalMICFailures);
return p;
}
int __init ieee80211_crypto_tkip_init(void)
{
return ieee80211_register_crypto_ops(&ieee80211_crypt_tkip);
}
void __exit ieee80211_crypto_tkip_exit(void)
{
ieee80211_unregister_crypto_ops(&ieee80211_crypt_tkip);
}
void ieee80211_tkip_null(void)
{
return;
}
