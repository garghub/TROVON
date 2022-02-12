static void
str_to_key(unsigned char *str, unsigned char *key)
{
int i;
key[0] = str[0] >> 1;
key[1] = ((str[0] & 0x01) << 6) | (str[1] >> 2);
key[2] = ((str[1] & 0x03) << 5) | (str[2] >> 3);
key[3] = ((str[2] & 0x07) << 4) | (str[3] >> 4);
key[4] = ((str[3] & 0x0F) << 3) | (str[4] >> 5);
key[5] = ((str[4] & 0x1F) << 2) | (str[5] >> 6);
key[6] = ((str[5] & 0x3F) << 1) | (str[6] >> 7);
key[7] = str[6] & 0x7F;
for (i = 0; i < 8; i++)
key[i] = (key[i] << 1);
}
static int
smbhash(unsigned char *out, const unsigned char *in, unsigned char *key)
{
int rc;
unsigned char key2[8];
struct crypto_blkcipher *tfm_des;
struct scatterlist sgin, sgout;
struct blkcipher_desc desc;
str_to_key(key, key2);
tfm_des = crypto_alloc_blkcipher("ecb(des)", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm_des)) {
rc = PTR_ERR(tfm_des);
cERROR(1, "could not allocate des crypto API\n");
goto smbhash_err;
}
desc.tfm = tfm_des;
crypto_blkcipher_setkey(tfm_des, key2, 8);
sg_init_one(&sgin, in, 8);
sg_init_one(&sgout, out, 8);
rc = crypto_blkcipher_encrypt(&desc, &sgout, &sgin, 8);
if (rc)
cERROR(1, "could not encrypt crypt key rc: %d\n", rc);
crypto_free_blkcipher(tfm_des);
smbhash_err:
return rc;
}
static int
E_P16(unsigned char *p14, unsigned char *p16)
{
int rc;
unsigned char sp8[8] =
{ 0x4b, 0x47, 0x53, 0x21, 0x40, 0x23, 0x24, 0x25 };
rc = smbhash(p16, sp8, p14);
if (rc)
return rc;
rc = smbhash(p16 + 8, sp8, p14 + 7);
return rc;
}
static int
E_P24(unsigned char *p21, const unsigned char *c8, unsigned char *p24)
{
int rc;
rc = smbhash(p24, c8, p21);
if (rc)
return rc;
rc = smbhash(p24 + 8, c8, p21 + 7);
if (rc)
return rc;
rc = smbhash(p24 + 16, c8, p21 + 14);
return rc;
}
int
mdfour(unsigned char *md4_hash, unsigned char *link_str, int link_len)
{
int rc;
unsigned int size;
struct crypto_shash *md4;
struct sdesc *sdescmd4;
md4 = crypto_alloc_shash("md4", 0, 0);
if (IS_ERR(md4)) {
rc = PTR_ERR(md4);
cERROR(1, "%s: Crypto md4 allocation error %d\n", __func__, rc);
return rc;
}
size = sizeof(struct shash_desc) + crypto_shash_descsize(md4);
sdescmd4 = kmalloc(size, GFP_KERNEL);
if (!sdescmd4) {
rc = -ENOMEM;
cERROR(1, "%s: Memory allocation failure\n", __func__);
goto mdfour_err;
}
sdescmd4->shash.tfm = md4;
sdescmd4->shash.flags = 0x0;
rc = crypto_shash_init(&sdescmd4->shash);
if (rc) {
cERROR(1, "%s: Could not init md4 shash\n", __func__);
goto mdfour_err;
}
rc = crypto_shash_update(&sdescmd4->shash, link_str, link_len);
if (rc) {
cERROR(1, "%s: Could not update with link_str\n", __func__);
goto mdfour_err;
}
rc = crypto_shash_final(&sdescmd4->shash, md4_hash);
if (rc)
cERROR(1, "%s: Could not genereate md4 hash\n", __func__);
mdfour_err:
crypto_free_shash(md4);
kfree(sdescmd4);
return rc;
}
int
SMBencrypt(unsigned char *passwd, const unsigned char *c8, unsigned char *p24)
{
int rc;
unsigned char p14[14], p16[16], p21[21];
memset(p14, '\0', 14);
memset(p16, '\0', 16);
memset(p21, '\0', 21);
memcpy(p14, passwd, 14);
rc = E_P16(p14, p16);
if (rc)
return rc;
memcpy(p21, p16, 16);
rc = E_P24(p21, c8, p24);
return rc;
}
static int
_my_wcslen(__u16 *str)
{
int len = 0;
while (*str++ != 0)
len++;
return len;
}
static int
_my_mbstowcs(__u16 *dst, const unsigned char *src, int len)
{
int i;
__u16 val;
for (i = 0; i < len; i++) {
val = *src;
SSVAL(dst, 0, val);
dst++;
src++;
if (val == 0)
break;
}
return i;
}
int
E_md4hash(const unsigned char *passwd, unsigned char *p16)
{
int rc;
int len;
__u16 wpwd[129];
if (passwd) {
len = strlen((char *) passwd);
if (len > 128)
len = 128;
_my_mbstowcs(wpwd, passwd, len);
} else
len = 0;
wpwd[len] = 0;
len = _my_wcslen(wpwd) * sizeof(__u16);
rc = mdfour(p16, (unsigned char *) wpwd, len);
memset(wpwd, 0, 129 * 2);
return rc;
}
int
SMBNTencrypt(unsigned char *passwd, unsigned char *c8, unsigned char *p24)
{
int rc;
unsigned char p16[16], p21[21];
memset(p16, '\0', 16);
memset(p21, '\0', 21);
rc = E_md4hash(passwd, p16);
if (rc) {
cFYI(1, "%s Can't generate NT hash, error: %d", __func__, rc);
return rc;
}
memcpy(p21, p16, 16);
rc = E_P24(p21, c8, p24);
return rc;
}
