static void arcfour_init(struct arc4context *parc4ctx, u8 * key, u32 key_len)
{
u32 t, u;
u32 keyindex;
u32 stateindex;
u8 * state;
u32 counter;
state = parc4ctx->state;
parc4ctx->x = 0;
parc4ctx->y = 0;
for (counter = 0; counter < 256; counter++)
state[counter] = (u8)counter;
keyindex = 0;
stateindex = 0;
for (counter = 0; counter < 256; counter++)
{
t = state[counter];
stateindex = (stateindex + key[keyindex] + t) & 0xff;
u = state[stateindex];
state[stateindex] = (u8)t;
state[counter] = (u8)u;
if (++keyindex >= key_len)
keyindex = 0;
}
}
static u32 arcfour_byte( struct arc4context *parc4ctx)
{
u32 x;
u32 y;
u32 sx, sy;
u8 * state;
state = parc4ctx->state;
x = (parc4ctx->x + 1) & 0xff;
sx = state[x];
y = (sx + parc4ctx->y) & 0xff;
sy = state[y];
parc4ctx->x = x;
parc4ctx->y = y;
state[y] = (u8)sx;
state[x] = (u8)sy;
return state[(sx + sy) & 0xff];
}
static void arcfour_encrypt( struct arc4context *parc4ctx,
u8 * dest,
u8 * src,
u32 len)
{
u32 i;
for (i = 0; i < len; i++)
dest[i] = src[i] ^ (unsigned char)arcfour_byte(parc4ctx);
}
static u8 crc32_reverseBit(u8 data)
{
u8 retval = ((data << 7) & 0x80) | ((data << 5) & 0x40) |
((data << 3) & 0x20) | ((data << 1) & 0x10) |
((data >> 1) & 0x08) | ((data >> 3) & 0x04) |
((data >> 5) & 0x02) | ((data >> 7) & 0x01);
return retval;
}
static void crc32_init(void)
{
if (bcrc32initialized == 1)
return;
else{
int i, j;
u32 c;
u8 *p = (u8 *)&c, *p1;
u8 k;
c = 0x12340000;
for (i = 0; i < 256; ++i)
{
k = crc32_reverseBit((u8)i);
for (c = ((u32)k) << 24, j = 8; j > 0; --j) {
c = c & 0x80000000 ? (c << 1) ^ CRC32_POLY : (c << 1);
}
p1 = (u8 *)&crc32_table[i];
p1[0] = crc32_reverseBit(p[3]);
p1[1] = crc32_reverseBit(p[2]);
p1[2] = crc32_reverseBit(p[1]);
p1[3] = crc32_reverseBit(p[0]);
}
bcrc32initialized = 1;
}
}
static u32 getcrc32(u8 *buf, int len)
{
u8 *p;
u32 crc;
if (bcrc32initialized == 0) crc32_init();
crc = 0xffffffff;
for (p = buf; len > 0; ++p, --len)
crc = crc32_table[ (crc ^ *p) & 0xff] ^ (crc >> 8);
return ~crc;
}
void rtw_wep_encrypt23a(struct rtw_adapter *padapter,
struct xmit_frame *pxmitframe)
{
unsigned char crc[4];
struct arc4context mycontext;
int curfragnum, length, index;
u32 keylength;
u8 *pframe, *payload, *iv;
u8 wepkey[16];
u8 hw_hdr_offset = 0;
struct pkt_attrib *pattrib = &pxmitframe->attrib;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct xmit_priv *pxmitpriv = &padapter->xmitpriv;
if (!pxmitframe->buf_addr)
return;
hw_hdr_offset = TXDESC_OFFSET;
pframe = pxmitframe->buf_addr + hw_hdr_offset;
if ((pattrib->encrypt != _WEP40_) && (pattrib->encrypt != _WEP104_))
return;
index = psecuritypriv->dot11PrivacyKeyIndex;
keylength = psecuritypriv->dot11DefKeylen[index];
for (curfragnum = 0; curfragnum < pattrib->nr_frags ; curfragnum++) {
iv = pframe + pattrib->hdrlen;
memcpy(&wepkey[0], iv, 3);
memcpy(&wepkey[3], &psecuritypriv->dot11DefKey[index].skey[0],
keylength);
payload = pframe + pattrib->iv_len + pattrib->hdrlen;
if ((curfragnum + 1) == pattrib->nr_frags) {
length = pattrib->last_txcmdsz - pattrib->hdrlen -
pattrib->iv_len- pattrib->icv_len;
*((u32 *)crc) = cpu_to_le32(getcrc32(payload, length));
arcfour_init(&mycontext, wepkey, 3 + keylength);
arcfour_encrypt(&mycontext, payload, payload, length);
arcfour_encrypt(&mycontext, payload + length, crc, 4);
} else {
length = pxmitpriv->frag_len - pattrib->hdrlen -
pattrib->iv_len - pattrib->icv_len;
*((u32 *)crc) = cpu_to_le32(getcrc32(payload, length));
arcfour_init(&mycontext, wepkey, 3 + keylength);
arcfour_encrypt(&mycontext, payload, payload, length);
arcfour_encrypt(&mycontext, payload + length, crc, 4);
pframe += pxmitpriv->frag_len;
pframe = PTR_ALIGN(pframe, 4);
}
}
}
void rtw_wep_decrypt23a(struct rtw_adapter *padapter,
struct recv_frame *precvframe)
{
u8 crc[4];
struct arc4context mycontext;
int length;
u32 keylength;
u8 *pframe, *payload, *iv, wepkey[16];
u8 keyindex;
struct rx_pkt_attrib *prxattrib = &precvframe->attrib;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct sk_buff * skb = precvframe->pkt;
pframe = skb->data;
if ((prxattrib->encrypt != _WEP40_) && (prxattrib->encrypt != _WEP104_))
return;
iv = pframe + prxattrib->hdrlen;
keyindex = prxattrib->key_index;
keylength = psecuritypriv->dot11DefKeylen[keyindex];
memcpy(&wepkey[0], iv, 3);
memcpy(&wepkey[3], &psecuritypriv->dot11DefKey[keyindex].skey[0],
keylength);
length = skb->len - prxattrib->hdrlen - prxattrib->iv_len;
payload = pframe + prxattrib->iv_len + prxattrib->hdrlen;
arcfour_init(&mycontext, wepkey, 3 + keylength);
arcfour_encrypt(&mycontext, payload, payload, length);
*((u32 *)crc) = le32_to_cpu(getcrc32(payload, length - 4));
if (crc[3] != payload[length - 1] || crc[2] != payload[length - 2] ||
crc[1] != payload[length - 3] || crc[0] != payload[length - 4]) {
RT_TRACE(_module_rtl871x_security_c_, _drv_err_,
("rtw_wep_decrypt23a:icv error crc[3](%x)!= payload"
"[length-1](%x) || crc[2](%x)!= payload[length-2](%x)"
" || crc[1](%x)!= payload[length-3](%x) || crc[0](%x)"
"!= payload[length-4](%x)\n",
crc[3], payload[length - 1],
crc[2], payload[length - 2],
crc[1], payload[length - 3],
crc[0], payload[length - 4]));
}
return;
}
static u32 secmicgetuint32(u8 * p)
{
s32 i;
u32 res = 0;
for (i = 0; i<4; i++)
{
res |= ((u32)(*p++)) << (8*i);
}
return res;
}
static void secmicputuint32(u8 * p, u32 val)
{
long i;
for (i = 0; i<4; i++)
{
*p++ = (u8) (val & 0xff);
val >>= 8;
}
}
static void secmicclear(struct mic_data *pmicdata)
{
pmicdata->L = pmicdata->K0;
pmicdata->R = pmicdata->K1;
pmicdata->nBytesInM = 0;
pmicdata->M = 0;
}
void rtw_secmicsetkey23a(struct mic_data *pmicdata, u8 * key)
{
pmicdata->K0 = secmicgetuint32(key);
pmicdata->K1 = secmicgetuint32(key + 4);
secmicclear(pmicdata);
}
void rtw_secmicappend23abyte23a(struct mic_data *pmicdata, u8 b)
{
pmicdata->M |= ((unsigned long)b) << (8*pmicdata->nBytesInM);
pmicdata->nBytesInM++;
if (pmicdata->nBytesInM >= 4)
{
pmicdata->L ^= pmicdata->M;
pmicdata->R ^= ROL32(pmicdata->L, 17);
pmicdata->L += pmicdata->R;
pmicdata->R ^= ((pmicdata->L & 0xff00ff00) >> 8) | ((pmicdata->L & 0x00ff00ff) << 8);
pmicdata->L += pmicdata->R;
pmicdata->R ^= ROL32(pmicdata->L, 3);
pmicdata->L += pmicdata->R;
pmicdata->R ^= ROR32(pmicdata->L, 2);
pmicdata->L += pmicdata->R;
pmicdata->M = 0;
pmicdata->nBytesInM = 0;
}
}
void rtw_secmicappend23a(struct mic_data *pmicdata, u8 * src, u32 nbytes)
{
while(nbytes > 0)
{
rtw_secmicappend23abyte23a(pmicdata, *src++);
nbytes--;
}
}
void rtw_secgetmic23a(struct mic_data *pmicdata, u8 * dst)
{
rtw_secmicappend23abyte23a(pmicdata, 0x5a);
rtw_secmicappend23abyte23a(pmicdata, 0);
rtw_secmicappend23abyte23a(pmicdata, 0);
rtw_secmicappend23abyte23a(pmicdata, 0);
rtw_secmicappend23abyte23a(pmicdata, 0);
while(pmicdata->nBytesInM != 0)
{
rtw_secmicappend23abyte23a(pmicdata, 0);
}
secmicputuint32(dst, pmicdata->L);
secmicputuint32(dst+4, pmicdata->R);
secmicclear(pmicdata);
}
void rtw_seccalctkipmic23a(u8 * key, u8 *header, u8 *data, u32 data_len, u8 *mic_code, u8 pri)
{
struct mic_data micdata;
u8 priority[4]={0x0, 0x0, 0x0, 0x0};
rtw_secmicsetkey23a(&micdata, key);
priority[0]= pri;
if (header[1]&1) {
rtw_secmicappend23a(&micdata, &header[16], 6);
if (header[1]&2)
rtw_secmicappend23a(&micdata, &header[24], 6);
else
rtw_secmicappend23a(&micdata, &header[10], 6);
}
else{
rtw_secmicappend23a(&micdata, &header[4], 6);
if (header[1]&2)
rtw_secmicappend23a(&micdata, &header[16], 6);
else
rtw_secmicappend23a(&micdata, &header[10], 6);
}
rtw_secmicappend23a(&micdata, &priority[0], 4);
rtw_secmicappend23a(&micdata, data, data_len);
rtw_secgetmic23a(&micdata, mic_code);
}
static void phase1(u16 *p1k, const u8 *tk, const u8 *ta, u32 iv32)
{
int i;
p1k[0] = Lo16(iv32);
p1k[1] = Hi16(iv32);
p1k[2] = Mk16(ta[1], ta[0]);
p1k[3] = Mk16(ta[3], ta[2]);
p1k[4] = Mk16(ta[5], ta[4]);
for (i = 0; i < PHASE1_LOOP_CNT ;i++)
{
p1k[0] += _S_(p1k[4] ^ TK16((i&1)+0));
p1k[1] += _S_(p1k[0] ^ TK16((i&1)+2));
p1k[2] += _S_(p1k[1] ^ TK16((i&1)+4));
p1k[3] += _S_(p1k[2] ^ TK16((i&1)+6));
p1k[4] += _S_(p1k[3] ^ TK16((i&1)+0));
p1k[4] += (unsigned short)i;
}
}
static void phase2(u8 *rc4key, const u8 *tk, const u16 *p1k, u16 iv16)
{
int i;
u16 PPK[6];
for (i = 0;i<5;i++) PPK[i]= p1k[i];
PPK[5] = p1k[4] +iv16;
PPK[0] += _S_(PPK[5] ^ TK16(0));
PPK[1] += _S_(PPK[0] ^ TK16(1));
PPK[2] += _S_(PPK[1] ^ TK16(2));
PPK[3] += _S_(PPK[2] ^ TK16(3));
PPK[4] += _S_(PPK[3] ^ TK16(4));
PPK[5] += _S_(PPK[4] ^ TK16(5));
PPK[0] += RotR1(PPK[5] ^ TK16(6));
PPK[1] += RotR1(PPK[0] ^ TK16(7));
PPK[2] += RotR1(PPK[1]);
PPK[3] += RotR1(PPK[2]);
PPK[4] += RotR1(PPK[3]);
PPK[5] += RotR1(PPK[4]);
rc4key[0] = Hi8(iv16);
rc4key[1] = (Hi8(iv16) | 0x20) & 0x7F;
rc4key[2] = Lo8(iv16);
rc4key[3] = Lo8((PPK[5] ^ TK16(0)) >> 1);
for (i = 0;i<6;i++)
{
rc4key[4+2*i] = Lo8(PPK[i]);
rc4key[5+2*i] = Hi8(PPK[i]);
}
}
u32 rtw_tkip_encrypt23a(struct rtw_adapter *padapter,
struct xmit_frame *pxmitframe)
{
u16 pnl;
u32 pnh;
u8 rc4key[16];
u8 ttkey[16];
u8 crc[4];
u8 hw_hdr_offset = 0;
struct arc4context mycontext;
int curfragnum, length;
u32 prwskeylen;
u8 *pframe, *payload,*iv,*prwskey;
union pn48 dot11txpn;
struct sta_info *stainfo;
struct pkt_attrib *pattrib = &pxmitframe->attrib;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct xmit_priv *pxmitpriv = &padapter->xmitpriv;
u32 res = _SUCCESS;
if (!pxmitframe->buf_addr)
return _FAIL;
hw_hdr_offset = TXDESC_OFFSET;
pframe = pxmitframe->buf_addr + hw_hdr_offset;
if (pattrib->encrypt == _TKIP_) {
if (pattrib->psta)
{
stainfo = pattrib->psta;
}
else
{
DBG_8723A("%s, call rtw_get_stainfo()\n", __func__);
stainfo = rtw_get_stainfo23a(&padapter->stapriv,
&pattrib->ra[0]);
}
if (stainfo!= NULL) {
if (!(stainfo->state &_FW_LINKED))
{
DBG_8723A("%s, psta->state(0x%x) != _FW_LINKED\n", __func__, stainfo->state);
return _FAIL;
}
RT_TRACE(_module_rtl871x_security_c_, _drv_err_, ("rtw_tkip_encrypt23a: stainfo!= NULL!!!\n"));
if (is_multicast_ether_addr(pattrib->ra))
prwskey = psecuritypriv->dot118021XGrpKey[psecuritypriv->dot118021XGrpKeyid].skey;
else
prwskey = &stainfo->dot118021x_UncstKey.skey[0];
prwskeylen = 16;
for (curfragnum = 0;curfragnum<pattrib->nr_frags;curfragnum++) {
iv = pframe+pattrib->hdrlen;
payload = pframe+pattrib->iv_len+pattrib->hdrlen;
GET_TKIP_PN(iv, dot11txpn);
pnl = (u16)(dot11txpn.val);
pnh = (u32)(dot11txpn.val>>16);
phase1((u16 *)&ttkey[0], prwskey,&pattrib->ta[0], pnh);
phase2(&rc4key[0], prwskey, (u16 *)&ttkey[0], pnl);
if ((curfragnum+1) == pattrib->nr_frags) {
length = pattrib->last_txcmdsz-pattrib->hdrlen-pattrib->iv_len- pattrib->icv_len;
RT_TRACE(_module_rtl871x_security_c_, _drv_info_, ("pattrib->iv_len =%x, pattrib->icv_len =%x\n", pattrib->iv_len, pattrib->icv_len));
*((u32 *)crc) = cpu_to_le32(getcrc32(payload, length));
arcfour_init(&mycontext, rc4key, 16);
arcfour_encrypt(&mycontext, payload, payload, length);
arcfour_encrypt(&mycontext, payload+length, crc, 4);
}
else{
length = pxmitpriv->frag_len-pattrib->hdrlen-pattrib->iv_len-pattrib->icv_len ;
*((u32 *)crc) = cpu_to_le32(getcrc32(payload, length));
arcfour_init(&mycontext, rc4key, 16);
arcfour_encrypt(&mycontext, payload, payload, length);
arcfour_encrypt(&mycontext, payload+length, crc, 4);
pframe+= pxmitpriv->frag_len;
pframe = PTR_ALIGN(pframe, 4);
}
}
}
else{
RT_TRACE(_module_rtl871x_security_c_, _drv_err_, ("rtw_tkip_encrypt23a: stainfo == NULL!!!\n"));
DBG_8723A("%s, psta == NUL\n", __func__);
res = _FAIL;
}
}
return res;
}
u32 rtw_tkip_decrypt23a(struct rtw_adapter *padapter,
struct recv_frame *precvframe)
{
u16 pnl;
u32 pnh;
u8 rc4key[16];
u8 ttkey[16];
u8 crc[4];
struct arc4context mycontext;
int length;
u32 prwskeylen;
u8 *pframe, *payload,*iv,*prwskey;
union pn48 dot11txpn;
struct sta_info *stainfo;
struct rx_pkt_attrib *prxattrib = &precvframe->attrib;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct sk_buff * skb = precvframe->pkt;
u32 res = _SUCCESS;
pframe = skb->data;
if (prxattrib->encrypt == _TKIP_) {
stainfo = rtw_get_stainfo23a(&padapter->stapriv,
&prxattrib->ta[0]);
if (stainfo!= NULL) {
if (is_multicast_ether_addr(prxattrib->ra)) {
if (psecuritypriv->binstallGrpkey == false) {
res = _FAIL;
DBG_8723A("%s:rx bc/mc packets, but didn't install group key!!!!!!!!!!\n", __func__);
goto exit;
}
prwskey = psecuritypriv->dot118021XGrpKey[prxattrib->key_index].skey;
prwskeylen = 16;
} else {
RT_TRACE(_module_rtl871x_security_c_, _drv_err_, ("rtw_tkip_decrypt23a: stainfo!= NULL!!!\n"));
prwskey = &stainfo->dot118021x_UncstKey.skey[0];
prwskeylen = 16;
}
iv = pframe+prxattrib->hdrlen;
payload = pframe+prxattrib->iv_len+prxattrib->hdrlen;
length = skb->len - prxattrib->hdrlen-prxattrib->iv_len;
GET_TKIP_PN(iv, dot11txpn);
pnl = (u16)(dot11txpn.val);
pnh = (u32)(dot11txpn.val>>16);
phase1((u16 *)&ttkey[0], prwskey,&prxattrib->ta[0], pnh);
phase2(&rc4key[0], prwskey, (unsigned short *)&ttkey[0], pnl);
arcfour_init(&mycontext, rc4key, 16);
arcfour_encrypt(&mycontext, payload, payload, length);
*((u32 *)crc) = le32_to_cpu(getcrc32(payload, length-4));
if (crc[3]!= payload[length-1] || crc[2]!= payload[length-2] || crc[1]!= payload[length-3] || crc[0]!= payload[length-4])
{
RT_TRACE(_module_rtl871x_security_c_, _drv_err_, ("rtw_wep_decrypt23a:icv error crc[3](%x)!= payload[length-1](%x) || crc[2](%x)!= payload[length-2](%x) || crc[1](%x)!= payload[length-3](%x) || crc[0](%x)!= payload[length-4](%x)\n",
crc[3], payload[length-1], crc[2], payload[length-2], crc[1], payload[length-3], crc[0], payload[length-4]));
res = _FAIL;
}
} else {
RT_TRACE(_module_rtl871x_security_c_, _drv_err_, ("rtw_tkip_decrypt23a: stainfo == NULL!!!\n"));
res = _FAIL;
}
}
exit:
return res;
}
static void xor_128(u8 *a, u8 *b, u8 *out)
{
int i;
for (i = 0;i<16; i++)
out[i] = a[i] ^ b[i];
}
static void xor_32(u8 *a, u8 *b, u8 *out)
{
int i;
for (i = 0; i < 4; i++)
out[i] = a[i] ^ b[i];
}
static u8 sbox(u8 a)
{
return sbox_table[(int)a];
}
static void next_key(u8 *key, int round)
{
u8 rcon;
u8 sbox_key[4];
u8 rcon_table[12] =
{
0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
0x1b, 0x36, 0x36, 0x36
};
sbox_key[0] = sbox(key[13]);
sbox_key[1] = sbox(key[14]);
sbox_key[2] = sbox(key[15]);
sbox_key[3] = sbox(key[12]);
rcon = rcon_table[round];
xor_32(&key[0], sbox_key, &key[0]);
key[0] = key[0] ^ rcon;
xor_32(&key[4], &key[0], &key[4]);
xor_32(&key[8], &key[4], &key[8]);
xor_32(&key[12], &key[8], &key[12]);
}
static void byte_sub(u8 *in, u8 *out)
{
int i;
for (i = 0; i< 16; i++)
{
out[i] = sbox(in[i]);
}
}
static void shift_row(u8 *in, u8 *out)
{
out[0] = in[0];
out[1] = in[5];
out[2] = in[10];
out[3] = in[15];
out[4] = in[4];
out[5] = in[9];
out[6] = in[14];
out[7] = in[3];
out[8] = in[8];
out[9] = in[13];
out[10] = in[2];
out[11] = in[7];
out[12] = in[12];
out[13] = in[1];
out[14] = in[6];
out[15] = in[11];
}
static void mix_column(u8 *in, u8 *out)
{
int i;
u8 add1b[4];
u8 add1bf7[4];
u8 rotl[4];
u8 swap_halfs[4];
u8 andf7[4];
u8 rotr[4];
u8 temp[4];
u8 tempb[4];
for (i = 0 ; i<4; i++)
{
if ((in[i] & 0x80) == 0x80)
add1b[i] = 0x1b;
else
add1b[i] = 0x00;
}
swap_halfs[0] = in[2];
swap_halfs[1] = in[3];
swap_halfs[2] = in[0];
swap_halfs[3] = in[1];
rotl[0] = in[3];
rotl[1] = in[0];
rotl[2] = in[1];
rotl[3] = in[2];
andf7[0] = in[0] & 0x7f;
andf7[1] = in[1] & 0x7f;
andf7[2] = in[2] & 0x7f;
andf7[3] = in[3] & 0x7f;
for (i = 3; i>0; i--)
{
andf7[i] = andf7[i] << 1;
if ((andf7[i-1] & 0x80) == 0x80)
{
andf7[i] = (andf7[i] | 0x01);
}
}
andf7[0] = andf7[0] << 1;
andf7[0] = andf7[0] & 0xfe;
xor_32(add1b, andf7, add1bf7);
xor_32(in, add1bf7, rotr);
temp[0] = rotr[0];
rotr[0] = rotr[1];
rotr[1] = rotr[2];
rotr[2] = rotr[3];
rotr[3] = temp[0];
xor_32(add1bf7, rotr, temp);
xor_32(swap_halfs, rotl, tempb);
xor_32(temp, tempb, out);
}
static void aes128k128d(u8 *key, u8 *data, u8 *ciphertext)
{
int round;
int i;
u8 intermediatea[16];
u8 intermediateb[16];
u8 round_key[16];
for (i = 0; i<16; i++) round_key[i] = key[i];
for (round = 0; round < 11; round++)
{
if (round == 0)
{
xor_128(round_key, data, ciphertext);
next_key(round_key, round);
}
else if (round == 10)
{
byte_sub(ciphertext, intermediatea);
shift_row(intermediatea, intermediateb);
xor_128(intermediateb, round_key, ciphertext);
}
else
{
byte_sub(ciphertext, intermediatea);
shift_row(intermediatea, intermediateb);
mix_column(&intermediateb[0], &intermediatea[0]);
mix_column(&intermediateb[4], &intermediatea[4]);
mix_column(&intermediateb[8], &intermediatea[8]);
mix_column(&intermediateb[12], &intermediatea[12]);
xor_128(intermediatea, round_key, ciphertext);
next_key(round_key, round);
}
}
}
static void construct_mic_iv(u8 *mic_iv, int qc_exists, int a4_exists, u8 *mpdu,
uint payload_length, u8 *pn_vector)
{
int i;
mic_iv[0] = 0x59;
if (qc_exists && a4_exists)
mic_iv[1] = mpdu[30] & 0x0f;
if (qc_exists && !a4_exists)
mic_iv[1] = mpdu[24] & 0x0f;
if (!qc_exists)
mic_iv[1] = 0x00;
for (i = 2; i < 8; i++)
mic_iv[i] = mpdu[i + 8];
for (i = 8; i < 14; i++)
mic_iv[i] = pn_vector[13 - i];
mic_iv[14] = (unsigned char)(payload_length / 256);
mic_iv[15] = (unsigned char)(payload_length % 256);
}
static void construct_mic_header1(u8 *mic_header1, int header_length, u8 *mpdu)
{
mic_header1[0] = (u8)((header_length - 2) / 256);
mic_header1[1] = (u8)((header_length - 2) % 256);
mic_header1[2] = mpdu[0] & 0xcf;
mic_header1[3] = mpdu[1] & 0xc7;
mic_header1[4] = mpdu[4];
mic_header1[5] = mpdu[5];
mic_header1[6] = mpdu[6];
mic_header1[7] = mpdu[7];
mic_header1[8] = mpdu[8];
mic_header1[9] = mpdu[9];
mic_header1[10] = mpdu[10];
mic_header1[11] = mpdu[11];
mic_header1[12] = mpdu[12];
mic_header1[13] = mpdu[13];
mic_header1[14] = mpdu[14];
mic_header1[15] = mpdu[15];
}
static void construct_mic_header2(
u8 *mic_header2,
u8 *mpdu,
int a4_exists,
int qc_exists
)
{
int i;
for (i = 0; i<16; i++) mic_header2[i]= 0x00;
mic_header2[0] = mpdu[16];
mic_header2[1] = mpdu[17];
mic_header2[2] = mpdu[18];
mic_header2[3] = mpdu[19];
mic_header2[4] = mpdu[20];
mic_header2[5] = mpdu[21];
mic_header2[6] = 0x00;
mic_header2[7] = 0x00;
if (!qc_exists && a4_exists)
{
for (i = 0;i<6;i++) mic_header2[8+i] = mpdu[24+i];
}
if (qc_exists && !a4_exists)
{
mic_header2[8] = mpdu[24] & 0x0f;
mic_header2[9] = mpdu[25] & 0x00;
}
if (qc_exists && a4_exists)
{
for (i = 0;i<6;i++) mic_header2[8+i] = mpdu[24+i];
mic_header2[14] = mpdu[30] & 0x0f;
mic_header2[15] = mpdu[31] & 0x00;
}
}
static void construct_ctr_preload(u8 *ctr_preload, int a4_exists, int qc_exists,
u8 *mpdu, u8 *pn_vector, int c)
{
int i = 0;
for (i = 0; i<16; i++) ctr_preload[i] = 0x00;
i = 0;
ctr_preload[0] = 0x01;
if (qc_exists && a4_exists)
ctr_preload[1] = mpdu[30] & 0x0f;
if (qc_exists && !a4_exists)
ctr_preload[1] = mpdu[24] & 0x0f;
for (i = 2; i < 8; i++)
ctr_preload[i] = mpdu[i + 8];
for (i = 8; i < 14; i++)
ctr_preload[i] = pn_vector[13 - i];
ctr_preload[14] = (unsigned char) (c / 256);
ctr_preload[15] = (unsigned char) (c % 256);
}
static void bitwise_xor(u8 *ina, u8 *inb, u8 *out)
{
int i;
for (i = 0; i < 16; i++)
out[i] = ina[i] ^ inb[i];
}
static int aes_cipher(u8 *key, uint hdrlen, u8 *pframe, uint plen)
{
uint qc_exists, a4_exists, i, j, payload_remainder,
num_blocks, payload_index;
u8 pn_vector[6];
u8 mic_iv[16];
u8 mic_header1[16];
u8 mic_header2[16];
u8 ctr_preload[16];
u8 chain_buffer[16];
u8 aes_out[16];
u8 padded_buffer[16];
u8 mic[8];
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)pframe;
u16 frsubtype = le16_to_cpu(hdr->frame_control) & IEEE80211_FCTL_STYPE;
memset((void *)mic_iv, 0, 16);
memset((void *)mic_header1, 0, 16);
memset((void *)mic_header2, 0, 16);
memset((void *)ctr_preload, 0, 16);
memset((void *)chain_buffer, 0, 16);
memset((void *)aes_out, 0, 16);
memset((void *)padded_buffer, 0, 16);
if ((hdrlen == sizeof(struct ieee80211_hdr_3addr) ||
(hdrlen == sizeof(struct ieee80211_qos_hdr))))
a4_exists = 0;
else
a4_exists = 1;
if (ieee80211_is_data(hdr->frame_control)) {
if ((frsubtype == IEEE80211_STYPE_DATA_CFACK) ||
(frsubtype == IEEE80211_STYPE_DATA_CFPOLL) ||
(frsubtype == IEEE80211_STYPE_DATA_CFACKPOLL)) {
qc_exists = 1;
if (hdrlen != sizeof(struct ieee80211_qos_hdr))
hdrlen += 2;
} else if ((frsubtype == IEEE80211_STYPE_QOS_DATA) ||
(frsubtype == IEEE80211_STYPE_QOS_DATA_CFACK) ||
(frsubtype == IEEE80211_STYPE_QOS_DATA_CFPOLL) ||
(frsubtype == IEEE80211_STYPE_QOS_DATA_CFACKPOLL)) {
if (hdrlen != sizeof(struct ieee80211_qos_hdr))
hdrlen += 2;
qc_exists = 1;
} else {
qc_exists = 0;
}
} else {
qc_exists = 0;
}
pn_vector[0]= pframe[hdrlen];
pn_vector[1]= pframe[hdrlen+1];
pn_vector[2]= pframe[hdrlen+4];
pn_vector[3]= pframe[hdrlen+5];
pn_vector[4]= pframe[hdrlen+6];
pn_vector[5]= pframe[hdrlen+7];
construct_mic_iv(mic_iv, qc_exists, a4_exists, pframe, plen, pn_vector);
construct_mic_header1(mic_header1, hdrlen, pframe);
construct_mic_header2(mic_header2, pframe, a4_exists, qc_exists);
payload_remainder = plen % 16;
num_blocks = plen / 16;
payload_index = (hdrlen + 8);
aes128k128d(key, mic_iv, aes_out);
bitwise_xor(aes_out, mic_header1, chain_buffer);
aes128k128d(key, chain_buffer, aes_out);
bitwise_xor(aes_out, mic_header2, chain_buffer);
aes128k128d(key, chain_buffer, aes_out);
for (i = 0; i < num_blocks; i++) {
bitwise_xor(aes_out, &pframe[payload_index], chain_buffer);
payload_index += 16;
aes128k128d(key, chain_buffer, aes_out);
}
if (payload_remainder > 0) {
for (j = 0; j < 16; j++)
padded_buffer[j] = 0x00;
for (j = 0; j < payload_remainder; j++)
padded_buffer[j] = pframe[payload_index++];
bitwise_xor(aes_out, padded_buffer, chain_buffer);
aes128k128d(key, chain_buffer, aes_out);
}
for (j = 0; j < 8; j++)
mic[j] = aes_out[j];
for (j = 0; j < 8; j++)
pframe[payload_index+j] = mic[j];
payload_index = hdrlen + 8;
for (i = 0; i < num_blocks; i++) {
construct_ctr_preload(ctr_preload, a4_exists, qc_exists,
pframe, pn_vector, i+1);
aes128k128d(key, ctr_preload, aes_out);
bitwise_xor(aes_out, &pframe[payload_index], chain_buffer);
for (j = 0; j < 16; j++)
pframe[payload_index++] = chain_buffer[j];
}
if (payload_remainder > 0) {
construct_ctr_preload(ctr_preload, a4_exists, qc_exists, pframe,
pn_vector, num_blocks+1);
for (j = 0; j < 16; j++)
padded_buffer[j] = 0x00;
for (j = 0; j < payload_remainder; j++)
padded_buffer[j] = pframe[payload_index+j];
aes128k128d(key, ctr_preload, aes_out);
bitwise_xor(aes_out, padded_buffer, chain_buffer);
for (j = 0; j < payload_remainder;j++)
pframe[payload_index++] = chain_buffer[j];
}
construct_ctr_preload(ctr_preload, a4_exists, qc_exists, pframe,
pn_vector, 0);
for (j = 0; j < 16; j++)
padded_buffer[j] = 0x00;
for (j = 0; j < 8; j++)
padded_buffer[j] = pframe[j+hdrlen+8+plen];
aes128k128d(key, ctr_preload, aes_out);
bitwise_xor(aes_out, padded_buffer, chain_buffer);
for (j = 0; j < 8;j++)
pframe[payload_index++] = chain_buffer[j];
return _SUCCESS;
}
u32 rtw_aes_encrypt23a(struct rtw_adapter *padapter, struct xmit_frame *pxmitframe)
{
int curfragnum, length;
u32 prwskeylen;
u8 *pframe, *prwskey;
u8 hw_hdr_offset = 0;
struct sta_info *stainfo;
struct pkt_attrib *pattrib = &pxmitframe->attrib;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct xmit_priv *pxmitpriv = &padapter->xmitpriv;
u32 res = _SUCCESS;
if (!pxmitframe->buf_addr)
return _FAIL;
hw_hdr_offset = TXDESC_OFFSET;
pframe = pxmitframe->buf_addr + hw_hdr_offset;
if (pattrib->encrypt != _AES_)
return _FAIL;
if (pattrib->psta) {
stainfo = pattrib->psta;
} else {
DBG_8723A("%s, call rtw_get_stainfo23a()\n", __func__);
stainfo = rtw_get_stainfo23a(&padapter->stapriv, &pattrib->ra[0]);
}
if (!stainfo) {
RT_TRACE(_module_rtl871x_security_c_, _drv_err_,
("rtw_aes_encrypt23a: stainfo == NULL!!!\n"));
DBG_8723A("%s, psta == NUL\n", __func__);
res = _FAIL;
goto out;
}
if (!(stainfo->state &_FW_LINKED)) {
DBG_8723A("%s, psta->state(0x%x) != _FW_LINKED\n",
__func__, stainfo->state);
return _FAIL;
}
RT_TRACE(_module_rtl871x_security_c_, _drv_err_,
("rtw_aes_encrypt23a: stainfo!= NULL!!!\n"));
if (is_multicast_ether_addr(pattrib->ra))
prwskey = psecuritypriv->dot118021XGrpKey[psecuritypriv->dot118021XGrpKeyid].skey;
else
prwskey = &stainfo->dot118021x_UncstKey.skey[0];
prwskeylen = 16;
for (curfragnum = 0; curfragnum < pattrib->nr_frags; curfragnum++) {
if ((curfragnum + 1) == pattrib->nr_frags) {
length = pattrib->last_txcmdsz -
pattrib->hdrlen-pattrib->iv_len -
pattrib->icv_len;
aes_cipher(prwskey, pattrib->hdrlen, pframe, length);
} else {
length = pxmitpriv->frag_len-pattrib->hdrlen -
pattrib->iv_len - pattrib->icv_len;
aes_cipher(prwskey, pattrib->hdrlen, pframe, length);
pframe += pxmitpriv->frag_len;
pframe = PTR_ALIGN(pframe, 4);
}
}
out:
return res;
}
static int aes_decipher(u8 *key, uint hdrlen,
u8 *pframe, uint plen)
{
static u8 message[MAX_MSG_SIZE];
uint qc_exists, a4_exists, i, j, payload_remainder,
num_blocks, payload_index;
int res = _SUCCESS;
u8 pn_vector[6];
u8 mic_iv[16];
u8 mic_header1[16];
u8 mic_header2[16];
u8 ctr_preload[16];
u8 chain_buffer[16];
u8 aes_out[16];
u8 padded_buffer[16];
u8 mic[8];
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)pframe;
u16 frsubtype = le16_to_cpu(hdr->frame_control) & IEEE80211_FCTL_STYPE;
memset((void *)mic_iv, 0, 16);
memset((void *)mic_header1, 0, 16);
memset((void *)mic_header2, 0, 16);
memset((void *)ctr_preload, 0, 16);
memset((void *)chain_buffer, 0, 16);
memset((void *)aes_out, 0, 16);
memset((void *)padded_buffer, 0, 16);
num_blocks = (plen-8) / 16;
payload_remainder = (plen-8) % 16;
pn_vector[0] = pframe[hdrlen];
pn_vector[1] = pframe[hdrlen+1];
pn_vector[2] = pframe[hdrlen+4];
pn_vector[3] = pframe[hdrlen+5];
pn_vector[4] = pframe[hdrlen+6];
pn_vector[5] = pframe[hdrlen+7];
if ((hdrlen == sizeof(struct ieee80211_hdr_3addr) ||
(hdrlen == sizeof(struct ieee80211_qos_hdr))))
a4_exists = 0;
else
a4_exists = 1;
if (ieee80211_is_data(hdr->frame_control)) {
if ((frsubtype == IEEE80211_STYPE_DATA_CFACK) ||
(frsubtype == IEEE80211_STYPE_DATA_CFPOLL) ||
(frsubtype == IEEE80211_STYPE_DATA_CFACKPOLL)) {
qc_exists = 1;
if (hdrlen != sizeof(struct ieee80211_hdr_3addr))
hdrlen += 2;
} else if ((frsubtype == IEEE80211_STYPE_QOS_DATA) ||
(frsubtype == IEEE80211_STYPE_QOS_DATA_CFACK) ||
(frsubtype == IEEE80211_STYPE_QOS_DATA_CFPOLL) ||
(frsubtype == IEEE80211_STYPE_QOS_DATA_CFACKPOLL)) {
if (hdrlen != sizeof(struct ieee80211_hdr_3addr))
hdrlen += 2;
qc_exists = 1;
} else {
qc_exists = 0;
}
} else {
qc_exists = 0;
}
payload_index = hdrlen + 8;
for (i = 0; i < num_blocks; i++) {
construct_ctr_preload(ctr_preload, a4_exists, qc_exists,
pframe, pn_vector, i+1);
aes128k128d(key, ctr_preload, aes_out);
bitwise_xor(aes_out, &pframe[payload_index], chain_buffer);
for (j = 0; j < 16; j++)
pframe[payload_index++] = chain_buffer[j];
}
if (payload_remainder > 0) {
construct_ctr_preload(ctr_preload, a4_exists, qc_exists, pframe,
pn_vector, num_blocks+1);
for (j = 0; j < 16; j++)
padded_buffer[j] = 0x00;
for (j = 0; j < payload_remainder; j++)
padded_buffer[j] = pframe[payload_index+j];
aes128k128d(key, ctr_preload, aes_out);
bitwise_xor(aes_out, padded_buffer, chain_buffer);
for (j = 0; j < payload_remainder; j++)
pframe[payload_index++] = chain_buffer[j];
}
if ((hdrlen +plen+8) <= MAX_MSG_SIZE)
memcpy(message, pframe, (hdrlen+plen+8));
pn_vector[0] = pframe[hdrlen];
pn_vector[1] = pframe[hdrlen+1];
pn_vector[2] = pframe[hdrlen+4];
pn_vector[3] = pframe[hdrlen+5];
pn_vector[4] = pframe[hdrlen+6];
pn_vector[5] = pframe[hdrlen+7];
construct_mic_iv(mic_iv, qc_exists, a4_exists, message,
plen-8, pn_vector);
construct_mic_header1(mic_header1, hdrlen, message);
construct_mic_header2(mic_header2, message, a4_exists, qc_exists);
payload_remainder = (plen-8) % 16;
num_blocks = (plen-8) / 16;
payload_index = (hdrlen + 8);
aes128k128d(key, mic_iv, aes_out);
bitwise_xor(aes_out, mic_header1, chain_buffer);
aes128k128d(key, chain_buffer, aes_out);
bitwise_xor(aes_out, mic_header2, chain_buffer);
aes128k128d(key, chain_buffer, aes_out);
for (i = 0; i < num_blocks; i++) {
bitwise_xor(aes_out, &message[payload_index], chain_buffer);
payload_index += 16;
aes128k128d(key, chain_buffer, aes_out);
}
if (payload_remainder > 0) {
for (j = 0; j < 16; j++)
padded_buffer[j] = 0x00;
for (j = 0; j < payload_remainder; j++)
padded_buffer[j] = message[payload_index++];
bitwise_xor(aes_out, padded_buffer, chain_buffer);
aes128k128d(key, chain_buffer, aes_out);
}
for (j = 0 ; j < 8; j++)
mic[j] = aes_out[j];
for (j = 0; j < 8; j++)
message[payload_index+j] = mic[j];
payload_index = hdrlen + 8;
for (i = 0; i< num_blocks; i++) {
construct_ctr_preload(ctr_preload, a4_exists, qc_exists,
message, pn_vector, i+1);
aes128k128d(key, ctr_preload, aes_out);
bitwise_xor(aes_out, &message[payload_index], chain_buffer);
for (j = 0; j < 16; j++)
message[payload_index++] = chain_buffer[j];
}
if (payload_remainder > 0) {
construct_ctr_preload(ctr_preload, a4_exists, qc_exists,
message, pn_vector, num_blocks+1);
for (j = 0; j < 16; j++)
padded_buffer[j] = 0x00;
for (j = 0; j < payload_remainder; j++)
padded_buffer[j] = message[payload_index+j];
aes128k128d(key, ctr_preload, aes_out);
bitwise_xor(aes_out, padded_buffer, chain_buffer);
for (j = 0; j < payload_remainder; j++)
message[payload_index++] = chain_buffer[j];
}
construct_ctr_preload(ctr_preload, a4_exists, qc_exists, message,
pn_vector, 0);
for (j = 0; j < 16; j++)
padded_buffer[j] = 0x00;
for (j = 0; j < 8; j++)
padded_buffer[j] = message[j+hdrlen+8+plen-8];
aes128k128d(key, ctr_preload, aes_out);
bitwise_xor(aes_out, padded_buffer, chain_buffer);
for (j = 0; j < 8; j++)
message[payload_index++] = chain_buffer[j];
for (i = 0; i < 8; i++) {
if (pframe[hdrlen+8+plen-8+i] != message[hdrlen+8+plen-8+i]) {
RT_TRACE(_module_rtl871x_security_c_, _drv_err_,
("aes_decipher:mic check error mic[%d]: pframe(%x) != message(%x)\n",
i, pframe[hdrlen+8+plen-8+i], message[hdrlen+8+plen-8+i]));
DBG_8723A("aes_decipher:mic check error mic[%d]: pframe(%x) != message(%x)\n",
i, pframe[hdrlen+8+plen-8+i], message[hdrlen+8+plen-8+i]);
res = _FAIL;
}
}
return res;
}
u32 rtw_aes_decrypt23a(struct rtw_adapter *padapter, struct recv_frame *precvframe)
{
struct sta_info *stainfo;
struct rx_pkt_attrib *prxattrib = &precvframe->attrib;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct sk_buff *skb = precvframe->pkt;
int length;
u8 *pframe, *prwskey;
u32 res = _SUCCESS;
pframe = skb->data;
if (prxattrib->encrypt != _AES_)
return _FAIL;
stainfo = rtw_get_stainfo23a(&padapter->stapriv, &prxattrib->ta[0]);
if (!stainfo) {
RT_TRACE(_module_rtl871x_security_c_, _drv_err_,
("rtw_aes_encrypt23a: stainfo == NULL!!!\n"));
res = _FAIL;
goto exit;
}
RT_TRACE(_module_rtl871x_security_c_, _drv_err_,
("rtw_aes_decrypt23a: stainfo!= NULL!!!\n"));
if (is_multicast_ether_addr(prxattrib->ra)) {
if (!psecuritypriv->binstallGrpkey) {
res = _FAIL;
DBG_8723A("%s:rx bc/mc packets, but didn't install "
"group key!!!!!!!!!!\n", __func__);
goto exit;
}
prwskey = psecuritypriv->dot118021XGrpKey[prxattrib->key_index].skey;
if (psecuritypriv->dot118021XGrpKeyid != prxattrib->key_index) {
DBG_8723A("not match packet_index =%d, install_index ="
"%d\n", prxattrib->key_index,
psecuritypriv->dot118021XGrpKeyid);
res = _FAIL;
goto exit;
}
} else {
prwskey = &stainfo->dot118021x_UncstKey.skey[0];
}
length = skb->len - prxattrib->hdrlen - prxattrib->iv_len;
res = aes_decipher(prwskey, prxattrib->hdrlen, pframe, length);
exit:
return res;
}
void rtw_use_tkipkey_handler23a(void *FunctionContext)
{
struct rtw_adapter *padapter = (struct rtw_adapter *)FunctionContext;
RT_TRACE(_module_rtl871x_security_c_, _drv_err_, ("^^^rtw_use_tkipkey_handler23a ^^^\n"));
padapter->securitypriv.busetkipkey = true;
RT_TRACE(_module_rtl871x_security_c_, _drv_err_,
("^^^rtw_use_tkipkey_handler23a padapter->securitypriv.busetkipkey =%d^^^\n",
padapter->securitypriv.busetkipkey));
}
