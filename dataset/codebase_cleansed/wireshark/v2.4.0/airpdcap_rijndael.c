UCHAR *
AES_unwrap(UCHAR *kek, UINT16 key_len, UCHAR *cipher_text, UINT16 cipher_len)
{
UCHAR *output;
UCHAR a[8], b[16];
UCHAR *r;
gint16 i, j, n;
gcry_cipher_hd_t rijndael_handle;
if (kek == NULL || cipher_len < 16 || cipher_text == NULL) {
return NULL;
}
output = (guint8 *) g_malloc0(cipher_len);
n = (cipher_len/8)-1;
memcpy(a, cipher_text, 8);
r = output;
memcpy(r, cipher_text+8, cipher_len - 8);
if (gcry_cipher_open(&rijndael_handle, GCRY_CIPHER_AES, GCRY_CIPHER_MODE_ECB, 0)) {
return output;
}
if (gcry_cipher_setkey(rijndael_handle, kek, key_len)) {
gcry_cipher_close(rijndael_handle);
return output;
}
for (j=5; j >= 0; --j){
r = output + (n - 1) * 8;
for (i = n; i >= 1; --i){
UINT16 t = (n*j) + i;
memcpy(b, a, 8);
b[7] ^= t;
memcpy(b+8, r, 8);
gcry_cipher_decrypt(rijndael_handle, b, 16, NULL, 0);
memcpy(a,b,8);
memcpy(r, b+8, 8);
r -= 8;
}
}
gcry_cipher_close(rijndael_handle);
return output;
}
