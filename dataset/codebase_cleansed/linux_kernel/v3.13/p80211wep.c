int wep_change_key(wlandevice_t *wlandev, int keynum, u8 *key, int keylen)
{
if (keylen < 0)
return -1;
if (keylen >= MAX_KEYLEN)
return -1;
if (key == NULL)
return -1;
if (keynum < 0)
return -1;
if (keynum >= NUM_WEPKEYS)
return -1;
#ifdef WEP_DEBUG
pr_debug("WEP key %d len %d = %*phC\n", keynum, keylen,
8, key);
#endif
wlandev->wep_keylens[keynum] = keylen;
memcpy(wlandev->wep_keys[keynum], key, keylen);
return 0;
}
int wep_decrypt(wlandevice_t *wlandev, u8 *buf, u32 len, int key_override,
u8 *iv, u8 *icv)
{
u32 i, j, k, crc, keylen;
u8 s[256], key[64], c_crc[4];
u8 keyidx;
if (len <= 0)
return -1;
key[0] = iv[0];
key[1] = iv[1];
key[2] = iv[2];
keyidx = WEP_KEY(iv[3]);
if (key_override >= 0)
keyidx = key_override;
if (keyidx >= NUM_WEPKEYS)
return -2;
keylen = wlandev->wep_keylens[keyidx];
if (keylen == 0)
return -3;
memcpy(key + 3, wlandev->wep_keys[keyidx], keylen);
keylen += 3;
#ifdef WEP_DEBUG
pr_debug("D %d: %*ph (%d %d) %*phC\n", len, 3, key,
keyidx, keylen, 5, key + 3);
#endif
for (i = 0; i < 256; i++)
s[i] = i;
j = 0;
for (i = 0; i < 256; i++) {
j = (j + s[i] + key[i % keylen]) & 0xff;
swap(i, j);
}
crc = ~0;
i = j = 0;
for (k = 0; k < len; k++) {
i = (i + 1) & 0xff;
j = (j + s[i]) & 0xff;
swap(i, j);
buf[k] ^= s[(s[i] + s[j]) & 0xff];
crc = wep_crc32_table[(crc ^ buf[k]) & 0xff] ^ (crc >> 8);
}
crc = ~crc;
c_crc[0] = crc;
c_crc[1] = crc >> 8;
c_crc[2] = crc >> 16;
c_crc[3] = crc >> 24;
for (k = 0; k < 4; k++) {
i = (i + 1) & 0xff;
j = (j + s[i]) & 0xff;
swap(i, j);
if ((c_crc[k] ^ s[(s[i] + s[j]) & 0xff]) != icv[k])
return -(4 | (k << 4));
}
return 0;
}
int wep_encrypt(wlandevice_t *wlandev, u8 *buf, u8 *dst, u32 len, int keynum,
u8 *iv, u8 *icv)
{
u32 i, j, k, crc, keylen;
u8 s[256], key[64];
if (len <= 0)
return -1;
if (keynum >= NUM_WEPKEYS)
return -2;
keylen = wlandev->wep_keylens[keynum];
if (keylen <= 0)
return -3;
get_random_bytes(iv, 3);
while ((iv[1] == 0xff) && (iv[0] >= 3) && (iv[0] < keylen))
get_random_bytes(iv, 3);
iv[3] = (keynum & 0x03) << 6;
key[0] = iv[0];
key[1] = iv[1];
key[2] = iv[2];
memcpy(key + 3, wlandev->wep_keys[keynum], keylen);
keylen += 3;
#ifdef WEP_DEBUG
pr_debug("E %d (%d/%d %d) %*ph %*phC\n", len,
iv[3], keynum, keylen, 3, key, 5, key + 3);
#endif
for (i = 0; i < 256; i++)
s[i] = i;
j = 0;
for (i = 0; i < 256; i++) {
j = (j + s[i] + key[i % keylen]) & 0xff;
swap(i, j);
}
crc = ~0;
i = j = 0;
for (k = 0; k < len; k++) {
crc = wep_crc32_table[(crc ^ buf[k]) & 0xff] ^ (crc >> 8);
i = (i + 1) & 0xff;
j = (j + s[i]) & 0xff;
swap(i, j);
dst[k] = buf[k] ^ s[(s[i] + s[j]) & 0xff];
}
crc = ~crc;
icv[0] = crc;
icv[1] = crc >> 8;
icv[2] = crc >> 16;
icv[3] = crc >> 24;
for (k = 0; k < 4; k++) {
i = (i + 1) & 0xff;
j = (j + s[i]) & 0xff;
swap(i, j);
icv[k] ^= s[(s[i] + s[j]) & 0xff];
}
return 0;
}
