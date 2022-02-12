static u16 tkipS(u16 val)
{
return tkip_sbox[val & 0xff] ^ swab16(tkip_sbox[val >> 8]);
}
static u8 *write_tkip_iv(u8 *pos, u16 iv16)
{
*pos++ = iv16 >> 8;
*pos++ = ((iv16 >> 8) | 0x20) & 0x7f;
*pos++ = iv16 & 0xFF;
return pos;
}
static void tkip_mixing_phase1(const u8 *tk, struct tkip_ctx *ctx,
const u8 *ta, u32 tsc_IV32)
{
int i, j;
u16 *p1k = ctx->p1k;
p1k[0] = tsc_IV32 & 0xFFFF;
p1k[1] = tsc_IV32 >> 16;
p1k[2] = get_unaligned_le16(ta + 0);
p1k[3] = get_unaligned_le16(ta + 2);
p1k[4] = get_unaligned_le16(ta + 4);
for (i = 0; i < PHASE1_LOOP_COUNT; i++) {
j = 2 * (i & 1);
p1k[0] += tkipS(p1k[4] ^ get_unaligned_le16(tk + 0 + j));
p1k[1] += tkipS(p1k[0] ^ get_unaligned_le16(tk + 4 + j));
p1k[2] += tkipS(p1k[1] ^ get_unaligned_le16(tk + 8 + j));
p1k[3] += tkipS(p1k[2] ^ get_unaligned_le16(tk + 12 + j));
p1k[4] += tkipS(p1k[3] ^ get_unaligned_le16(tk + 0 + j)) + i;
}
ctx->state = TKIP_STATE_PHASE1_DONE;
ctx->p1k_iv32 = tsc_IV32;
}
static void tkip_mixing_phase2(const u8 *tk, struct tkip_ctx *ctx,
u16 tsc_IV16, u8 *rc4key)
{
u16 ppk[6];
const u16 *p1k = ctx->p1k;
int i;
ppk[0] = p1k[0];
ppk[1] = p1k[1];
ppk[2] = p1k[2];
ppk[3] = p1k[3];
ppk[4] = p1k[4];
ppk[5] = p1k[4] + tsc_IV16;
ppk[0] += tkipS(ppk[5] ^ get_unaligned_le16(tk + 0));
ppk[1] += tkipS(ppk[0] ^ get_unaligned_le16(tk + 2));
ppk[2] += tkipS(ppk[1] ^ get_unaligned_le16(tk + 4));
ppk[3] += tkipS(ppk[2] ^ get_unaligned_le16(tk + 6));
ppk[4] += tkipS(ppk[3] ^ get_unaligned_le16(tk + 8));
ppk[5] += tkipS(ppk[4] ^ get_unaligned_le16(tk + 10));
ppk[0] += ror16(ppk[5] ^ get_unaligned_le16(tk + 12), 1);
ppk[1] += ror16(ppk[0] ^ get_unaligned_le16(tk + 14), 1);
ppk[2] += ror16(ppk[1], 1);
ppk[3] += ror16(ppk[2], 1);
ppk[4] += ror16(ppk[3], 1);
ppk[5] += ror16(ppk[4], 1);
rc4key = write_tkip_iv(rc4key, tsc_IV16);
*rc4key++ = ((ppk[5] ^ get_unaligned_le16(tk)) >> 1) & 0xFF;
for (i = 0; i < 6; i++)
put_unaligned_le16(ppk[i], rc4key + 2 * i);
}
u8 *ieee80211_tkip_add_iv(u8 *pos, struct ieee80211_key_conf *keyconf, u64 pn)
{
pos = write_tkip_iv(pos, TKIP_PN_TO_IV16(pn));
*pos++ = (keyconf->keyidx << 6) | (1 << 5) ;
put_unaligned_le32(TKIP_PN_TO_IV32(pn), pos);
return pos + 4;
}
static void ieee80211_compute_tkip_p1k(struct ieee80211_key *key, u32 iv32)
{
struct ieee80211_sub_if_data *sdata = key->sdata;
struct tkip_ctx *ctx = &key->u.tkip.tx;
const u8 *tk = &key->conf.key[NL80211_TKIP_DATA_OFFSET_ENCR_KEY];
lockdep_assert_held(&key->u.tkip.txlock);
if (ctx->p1k_iv32 != iv32 || ctx->state == TKIP_STATE_NOT_INIT)
tkip_mixing_phase1(tk, ctx, sdata->vif.addr, iv32);
}
void ieee80211_get_tkip_p1k_iv(struct ieee80211_key_conf *keyconf,
u32 iv32, u16 *p1k)
{
struct ieee80211_key *key = (struct ieee80211_key *)
container_of(keyconf, struct ieee80211_key, conf);
struct tkip_ctx *ctx = &key->u.tkip.tx;
spin_lock_bh(&key->u.tkip.txlock);
ieee80211_compute_tkip_p1k(key, iv32);
memcpy(p1k, ctx->p1k, sizeof(ctx->p1k));
spin_unlock_bh(&key->u.tkip.txlock);
}
void ieee80211_get_tkip_rx_p1k(struct ieee80211_key_conf *keyconf,
const u8 *ta, u32 iv32, u16 *p1k)
{
const u8 *tk = &keyconf->key[NL80211_TKIP_DATA_OFFSET_ENCR_KEY];
struct tkip_ctx ctx;
tkip_mixing_phase1(tk, &ctx, ta, iv32);
memcpy(p1k, ctx.p1k, sizeof(ctx.p1k));
}
void ieee80211_get_tkip_p2k(struct ieee80211_key_conf *keyconf,
struct sk_buff *skb, u8 *p2k)
{
struct ieee80211_key *key = (struct ieee80211_key *)
container_of(keyconf, struct ieee80211_key, conf);
const u8 *tk = &key->conf.key[NL80211_TKIP_DATA_OFFSET_ENCR_KEY];
struct tkip_ctx *ctx = &key->u.tkip.tx;
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
const u8 *data = (u8 *)hdr + ieee80211_hdrlen(hdr->frame_control);
u32 iv32 = get_unaligned_le32(&data[4]);
u16 iv16 = data[2] | (data[0] << 8);
spin_lock(&key->u.tkip.txlock);
ieee80211_compute_tkip_p1k(key, iv32);
tkip_mixing_phase2(tk, ctx, iv16, p2k);
spin_unlock(&key->u.tkip.txlock);
}
int ieee80211_tkip_encrypt_data(struct crypto_cipher *tfm,
struct ieee80211_key *key,
struct sk_buff *skb,
u8 *payload, size_t payload_len)
{
u8 rc4key[16];
ieee80211_get_tkip_p2k(&key->conf, skb, rc4key);
return ieee80211_wep_encrypt_data(tfm, rc4key, 16,
payload, payload_len);
}
int ieee80211_tkip_decrypt_data(struct crypto_cipher *tfm,
struct ieee80211_key *key,
u8 *payload, size_t payload_len, u8 *ta,
u8 *ra, int only_iv, int queue,
u32 *out_iv32, u16 *out_iv16)
{
u32 iv32;
u32 iv16;
u8 rc4key[16], keyid, *pos = payload;
int res;
const u8 *tk = &key->conf.key[NL80211_TKIP_DATA_OFFSET_ENCR_KEY];
struct tkip_ctx_rx *rx_ctx = &key->u.tkip.rx[queue];
if (payload_len < 12)
return -1;
iv16 = (pos[0] << 8) | pos[2];
keyid = pos[3];
iv32 = get_unaligned_le32(pos + 4);
pos += 8;
if (!(keyid & (1 << 5)))
return TKIP_DECRYPT_NO_EXT_IV;
if ((keyid >> 6) != key->conf.keyidx)
return TKIP_DECRYPT_INVALID_KEYIDX;
if (rx_ctx->ctx.state != TKIP_STATE_NOT_INIT &&
(iv32 < rx_ctx->iv32 ||
(iv32 == rx_ctx->iv32 && iv16 <= rx_ctx->iv16)))
return TKIP_DECRYPT_REPLAY;
if (only_iv) {
res = TKIP_DECRYPT_OK;
rx_ctx->ctx.state = TKIP_STATE_PHASE1_HW_UPLOADED;
goto done;
}
if (rx_ctx->ctx.state == TKIP_STATE_NOT_INIT ||
rx_ctx->iv32 != iv32) {
tkip_mixing_phase1(tk, &rx_ctx->ctx, ta, iv32);
}
if (key->local->ops->update_tkip_key &&
key->flags & KEY_FLAG_UPLOADED_TO_HARDWARE &&
rx_ctx->ctx.state != TKIP_STATE_PHASE1_HW_UPLOADED) {
struct ieee80211_sub_if_data *sdata = key->sdata;
if (sdata->vif.type == NL80211_IFTYPE_AP_VLAN)
sdata = container_of(key->sdata->bss,
struct ieee80211_sub_if_data, u.ap);
drv_update_tkip_key(key->local, sdata, &key->conf, key->sta,
iv32, rx_ctx->ctx.p1k);
rx_ctx->ctx.state = TKIP_STATE_PHASE1_HW_UPLOADED;
}
tkip_mixing_phase2(tk, &rx_ctx->ctx, iv16, rc4key);
res = ieee80211_wep_decrypt_data(tfm, rc4key, 16, pos, payload_len - 12);
done:
if (res == TKIP_DECRYPT_OK) {
*out_iv32 = iv32;
*out_iv16 = iv16;
}
return res;
}
