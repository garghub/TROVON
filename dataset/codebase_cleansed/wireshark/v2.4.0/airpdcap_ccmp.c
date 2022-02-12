static void ccmp_init_blocks(
gcry_cipher_hd_t rijndael_handle,
PAIRPDCAP_MAC_FRAME wh,
UINT64 pn,
size_t dlen,
UINT8 b0[AES_BLOCK_LEN],
UINT8 aad[2 * AES_BLOCK_LEN],
UINT8 a[AES_BLOCK_LEN],
UINT8 b[AES_BLOCK_LEN])
{
UINT8 mgmt = (AIRPDCAP_TYPE(wh->fc[0]) == AIRPDCAP_TYPE_MANAGEMENT);
#define IS_4ADDRESS(wh) \
((wh->fc[1] & AIRPDCAP_FC1_DIR_MASK) == AIRPDCAP_FC1_DIR_DSTODS)
#define IS_QOS_DATA(wh) AIRPDCAP_QOS_HAS_SEQ(wh)
memset(aad, 0, 2*AES_BLOCK_LEN);
b0[0] = 0x59;
AIRPDCAP_ADDR_COPY(b0 + 2, wh->addr2);
b0[8] = (UINT8)(pn >> 40);
b0[9] = (UINT8)(pn >> 32);
b0[10] = (UINT8)(pn >> 24);
b0[11] = (UINT8)(pn >> 16);
b0[12] = (UINT8)(pn >> 8);
b0[13] = (UINT8)(pn >> 0);
b0[14] = (UINT8)((UINT8)(dlen >> 8) & 0xff);
b0[15] = (UINT8)(dlen & 0xff);
aad[0] = 0;
if (!mgmt)
aad[2] = (UINT8)(wh->fc[0] & 0x8f);
else
aad[2] = wh->fc[0];
aad[3] = (UINT8)(wh->fc[1] & 0xc7);
memcpy(aad + 4, &wh->addr1[0], 3 * AIRPDCAP_MAC_LEN);
aad[22] = (UINT8)(wh->seq[0] & AIRPDCAP_SEQ_FRAG_MASK);
aad[23] = 0;
if (IS_4ADDRESS(wh)) {
AIRPDCAP_ADDR_COPY(aad + 24,
((PAIRPDCAP_MAC_FRAME_ADDR4)wh)->addr4);
if (IS_QOS_DATA(wh)) {
PAIRPDCAP_MAC_FRAME_ADDR4_QOS qwh4 =
(PAIRPDCAP_MAC_FRAME_ADDR4_QOS) wh;
aad[30] = (UINT8)(qwh4->qos[0] & 0x0f);
aad[31] = 0;
b0[1] = aad[30];
aad[1] = 22 + AIRPDCAP_MAC_LEN + 2;
} else {
memset(&aad[30], 0, 2);
b0[1] = 0;
aad[1] = 22 + AIRPDCAP_MAC_LEN;
}
} else {
if (IS_QOS_DATA(wh)) {
PAIRPDCAP_MAC_FRAME_QOS qwh =
(PAIRPDCAP_MAC_FRAME_QOS) wh;
aad[24] = (UINT8)(qwh->qos[0] & 0x0f);
aad[25] = 0;
b0[1] = aad[24];
aad[1] = 22 + 2;
} else {
memset(&aad[24], 0, 2);
b0[1] = 0;
aad[1] = 22;
}
if (mgmt)
b0[1] |= 0x10;
memset(&aad[26], 0, 4);
}
gcry_cipher_encrypt(rijndael_handle, a, AES_BLOCK_LEN, b0, AES_BLOCK_LEN);
XOR_BLOCK(a, aad, AES_BLOCK_LEN);
gcry_cipher_encrypt(rijndael_handle, a, AES_BLOCK_LEN, NULL, 0);
XOR_BLOCK(a, &aad[AES_BLOCK_LEN], AES_BLOCK_LEN);
gcry_cipher_encrypt(rijndael_handle, a, AES_BLOCK_LEN, NULL, 0);
b0[0] &= 0x07;
b0[14] = b0[15] = 0;
gcry_cipher_encrypt(rijndael_handle, b, AES_BLOCK_LEN, b0, AES_BLOCK_LEN);
#undef IS_QOS_DATA
#undef IS_4ADDRESS
}
INT AirPDcapCcmpDecrypt(
UINT8 *m,
gint mac_header_len,
INT len,
UCHAR TK1[16])
{
PAIRPDCAP_MAC_FRAME wh;
UINT8 aad[2 * AES_BLOCK_LEN];
UINT8 b0[AES_BLOCK_LEN], b[AES_BLOCK_LEN], a[AES_BLOCK_LEN];
UINT8 mic[AES_BLOCK_LEN];
size_t data_len;
UINT i;
UINT8 *pos;
UINT space;
INT z = mac_header_len;
gcry_cipher_hd_t rijndael_handle;
UINT64 PN;
UINT8 *ivp=m+z;
PN = READ_6(ivp[0], ivp[1], ivp[4], ivp[5], ivp[6], ivp[7]);
if (gcry_cipher_open(&rijndael_handle, GCRY_CIPHER_AES, GCRY_CIPHER_MODE_ECB, 0)) {
return 1;
}
if (gcry_cipher_setkey(rijndael_handle, TK1, 16)) {
gcry_cipher_close(rijndael_handle);
return 1;
}
wh = (PAIRPDCAP_MAC_FRAME )m;
data_len = len - (z + AIRPDCAP_CCMP_HEADER+AIRPDCAP_CCMP_TRAILER);
if (data_len < 1) {
gcry_cipher_close(rijndael_handle);
return 0;
}
ccmp_init_blocks(rijndael_handle, wh, PN, data_len, b0, aad, a, b);
memcpy(mic, m+len-AIRPDCAP_CCMP_TRAILER, AIRPDCAP_CCMP_TRAILER);
XOR_BLOCK(mic, b, AIRPDCAP_CCMP_TRAILER);
i = 1;
pos = (UINT8 *)m + z + AIRPDCAP_CCMP_HEADER;
space = len - (z + AIRPDCAP_CCMP_HEADER);
if (space > data_len)
space = (UINT)data_len;
while (space >= AES_BLOCK_LEN) {
CCMP_DECRYPT(i, b, b0, pos, a, AES_BLOCK_LEN);
pos += AES_BLOCK_LEN, space -= AES_BLOCK_LEN;
i++;
}
if (space != 0)
CCMP_DECRYPT(i, b, b0, pos, a, space);
gcry_cipher_close(rijndael_handle);
if (memcmp(mic, a, AIRPDCAP_CCMP_TRAILER) == 0) {
return 0;
}
return 1;
}
