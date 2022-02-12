UCHAR *
AES_unwrap(UCHAR *kek, UINT16 key_len, UCHAR *cipher_text, UINT16 cipher_len)
{
UCHAR *output;
UCHAR a[8], b[16];
UCHAR *r;
gint16 i, j, n;
rijndael_ctx ctx;
if (kek == NULL || cipher_len < 16 || cipher_text == NULL) {
return NULL;
}
output = (guint8 *) g_malloc0(cipher_len);
n = (cipher_len/8)-1;
memcpy(a, cipher_text, 8);
r = output;
memcpy(r, cipher_text+8, cipher_len - 8);
for (j=5; j >= 0; --j){
r = output + (n - 1) * 8;
for (i = n; i >= 1; --i){
UINT16 t = (n*j) + i;
memcpy(b, a, 8);
b[7] ^= t;
memcpy(b+8, r, 8);
rijndael_set_key(&ctx, kek, key_len*8 );
rijndael_decrypt(&ctx, b, b);
memcpy(a,b,8);
memcpy(r, b+8, 8);
r -= 8;
}
}
return output;
}
