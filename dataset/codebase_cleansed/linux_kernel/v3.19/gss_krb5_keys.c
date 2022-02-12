static void krb5_nfold(u32 inbits, const u8 *in,
u32 outbits, u8 *out)
{
unsigned long ulcm;
int byte, i, msbit;
inbits >>= 3;
outbits >>= 3;
ulcm = lcm(inbits, outbits);
memset(out, 0, outbits);
byte = 0;
for (i = ulcm-1; i >= 0; i--) {
msbit = (
((inbits << 3) - 1)
+ (((inbits << 3) + 13) * (i/inbits))
+ ((inbits - (i % inbits)) << 3)
) % (inbits << 3);
byte += (((in[((inbits - 1) - (msbit >> 3)) % inbits] << 8)|
(in[((inbits) - (msbit >> 3)) % inbits]))
>> ((msbit & 7) + 1)) & 0xff;
byte += out[i % outbits];
out[i % outbits] = byte & 0xff;
byte >>= 8;
}
if (byte) {
for (i = outbits - 1; i >= 0; i--) {
byte += out[i];
out[i] = byte & 0xff;
byte >>= 8;
}
}
}
u32 krb5_derive_key(const struct gss_krb5_enctype *gk5e,
const struct xdr_netobj *inkey,
struct xdr_netobj *outkey,
const struct xdr_netobj *in_constant,
gfp_t gfp_mask)
{
size_t blocksize, keybytes, keylength, n;
unsigned char *inblockdata, *outblockdata, *rawkey;
struct xdr_netobj inblock, outblock;
struct crypto_blkcipher *cipher;
u32 ret = EINVAL;
blocksize = gk5e->blocksize;
keybytes = gk5e->keybytes;
keylength = gk5e->keylength;
if ((inkey->len != keylength) || (outkey->len != keylength))
goto err_return;
cipher = crypto_alloc_blkcipher(gk5e->encrypt_name, 0,
CRYPTO_ALG_ASYNC);
if (IS_ERR(cipher))
goto err_return;
if (crypto_blkcipher_setkey(cipher, inkey->data, inkey->len))
goto err_return;
ret = ENOMEM;
inblockdata = kmalloc(blocksize, gfp_mask);
if (inblockdata == NULL)
goto err_free_cipher;
outblockdata = kmalloc(blocksize, gfp_mask);
if (outblockdata == NULL)
goto err_free_in;
rawkey = kmalloc(keybytes, gfp_mask);
if (rawkey == NULL)
goto err_free_out;
inblock.data = (char *) inblockdata;
inblock.len = blocksize;
outblock.data = (char *) outblockdata;
outblock.len = blocksize;
if (in_constant->len == inblock.len) {
memcpy(inblock.data, in_constant->data, inblock.len);
} else {
krb5_nfold(in_constant->len * 8, in_constant->data,
inblock.len * 8, inblock.data);
}
n = 0;
while (n < keybytes) {
(*(gk5e->encrypt))(cipher, NULL, inblock.data,
outblock.data, inblock.len);
if ((keybytes - n) <= outblock.len) {
memcpy(rawkey + n, outblock.data, (keybytes - n));
break;
}
memcpy(rawkey + n, outblock.data, outblock.len);
memcpy(inblock.data, outblock.data, outblock.len);
n += outblock.len;
}
inblock.data = (char *) rawkey;
inblock.len = keybytes;
BUG_ON(gk5e->mk_key == NULL);
ret = (*(gk5e->mk_key))(gk5e, &inblock, outkey);
if (ret) {
dprintk("%s: got %d from mk_key function for '%s'\n",
__func__, ret, gk5e->encrypt_name);
goto err_free_raw;
}
ret = 0;
err_free_raw:
memset(rawkey, 0, keybytes);
kfree(rawkey);
err_free_out:
memset(outblockdata, 0, blocksize);
kfree(outblockdata);
err_free_in:
memset(inblockdata, 0, blocksize);
kfree(inblockdata);
err_free_cipher:
crypto_free_blkcipher(cipher);
err_return:
return ret;
}
static void mit_des_fixup_key_parity(u8 key[8])
{
int i;
for (i = 0; i < 8; i++) {
key[i] &= 0xfe;
key[i] |= 1^parity_char(key[i]);
}
}
u32 gss_krb5_des3_make_key(const struct gss_krb5_enctype *gk5e,
struct xdr_netobj *randombits,
struct xdr_netobj *key)
{
int i;
u32 ret = EINVAL;
if (key->len != 24) {
dprintk("%s: key->len is %d\n", __func__, key->len);
goto err_out;
}
if (randombits->len != 21) {
dprintk("%s: randombits->len is %d\n",
__func__, randombits->len);
goto err_out;
}
for (i = 0; i < 3; i++) {
memcpy(key->data + i*8, randombits->data + i*7, 7);
key->data[i*8+7] = (((key->data[i*8]&1)<<1) |
((key->data[i*8+1]&1)<<2) |
((key->data[i*8+2]&1)<<3) |
((key->data[i*8+3]&1)<<4) |
((key->data[i*8+4]&1)<<5) |
((key->data[i*8+5]&1)<<6) |
((key->data[i*8+6]&1)<<7));
mit_des_fixup_key_parity(key->data + i*8);
}
ret = 0;
err_out:
return ret;
}
u32 gss_krb5_aes_make_key(const struct gss_krb5_enctype *gk5e,
struct xdr_netobj *randombits,
struct xdr_netobj *key)
{
u32 ret = EINVAL;
if (key->len != 16 && key->len != 32) {
dprintk("%s: key->len is %d\n", __func__, key->len);
goto err_out;
}
if (randombits->len != 16 && randombits->len != 32) {
dprintk("%s: randombits->len is %d\n",
__func__, randombits->len);
goto err_out;
}
if (randombits->len != key->len) {
dprintk("%s: randombits->len is %d, key->len is %d\n",
__func__, randombits->len, key->len);
goto err_out;
}
memcpy(key->data, randombits->data, key->len);
ret = 0;
err_out:
return ret;
}
