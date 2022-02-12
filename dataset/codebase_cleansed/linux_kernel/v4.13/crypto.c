static void wusb_key_dump(const void *buf, size_t len)
{
print_hex_dump(KERN_ERR, " ", DUMP_PREFIX_OFFSET, 16, 1,
buf, len, 0);
}
static void bytewise_xor(void *_bo, const void *_bi1, const void *_bi2,
size_t size)
{
u8 *bo = _bo;
const u8 *bi1 = _bi1, *bi2 = _bi2;
size_t itr;
for (itr = 0; itr < size; itr++)
bo[itr] = bi1[itr] ^ bi2[itr];
}
static int wusb_ccm_mac(struct crypto_skcipher *tfm_cbc,
struct crypto_cipher *tfm_aes,
struct wusb_mac_scratch *scratch,
void *mic,
const struct aes_ccm_nonce *n,
const struct aes_ccm_label *a, const void *b,
size_t blen)
{
int result = 0;
SKCIPHER_REQUEST_ON_STACK(req, tfm_cbc);
struct scatterlist sg[4], sg_dst;
void *dst_buf;
size_t dst_size;
u8 iv[crypto_skcipher_ivsize(tfm_cbc)];
size_t zero_padding;
WARN_ON(sizeof(*a) != sizeof(scratch->b1) - sizeof(scratch->b1.la));
WARN_ON(sizeof(scratch->b0) != sizeof(struct aes_ccm_block));
WARN_ON(sizeof(scratch->b1) != sizeof(struct aes_ccm_block));
WARN_ON(sizeof(scratch->ax) != sizeof(struct aes_ccm_block));
result = -ENOMEM;
zero_padding = blen % sizeof(struct aes_ccm_block);
if (zero_padding)
zero_padding = sizeof(struct aes_ccm_block) - zero_padding;
dst_size = blen + sizeof(scratch->b0) + sizeof(scratch->b1) +
zero_padding;
dst_buf = kzalloc(dst_size, GFP_KERNEL);
if (!dst_buf)
goto error_dst_buf;
memset(iv, 0, sizeof(iv));
scratch->b0.flags = 0x59;
scratch->b0.ccm_nonce = *n;
scratch->b0.lm = cpu_to_be16(0);
scratch->b1.la = cpu_to_be16(blen + 14);
memcpy(&scratch->b1.mac_header, a, sizeof(*a));
sg_init_table(sg, ARRAY_SIZE(sg));
sg_set_buf(&sg[0], &scratch->b0, sizeof(scratch->b0));
sg_set_buf(&sg[1], &scratch->b1, sizeof(scratch->b1));
sg_set_buf(&sg[2], b, blen);
sg_set_page(&sg[3], ZERO_PAGE(0), zero_padding, 0);
sg_init_one(&sg_dst, dst_buf, dst_size);
skcipher_request_set_tfm(req, tfm_cbc);
skcipher_request_set_callback(req, 0, NULL, NULL);
skcipher_request_set_crypt(req, sg, &sg_dst, dst_size, iv);
result = crypto_skcipher_encrypt(req);
skcipher_request_zero(req);
if (result < 0) {
printk(KERN_ERR "E: can't compute CBC-MAC tag (MIC): %d\n",
result);
goto error_cbc_crypt;
}
scratch->ax.flags = 0x01;
scratch->ax.ccm_nonce = *n;
scratch->ax.counter = 0;
crypto_cipher_encrypt_one(tfm_aes, (void *)&scratch->ax,
(void *)&scratch->ax);
bytewise_xor(mic, &scratch->ax, iv, 8);
result = 8;
error_cbc_crypt:
kfree(dst_buf);
error_dst_buf:
return result;
}
ssize_t wusb_prf(void *out, size_t out_size,
const u8 key[16], const struct aes_ccm_nonce *_n,
const struct aes_ccm_label *a,
const void *b, size_t blen, size_t len)
{
ssize_t result, bytes = 0, bitr;
struct aes_ccm_nonce n = *_n;
struct crypto_skcipher *tfm_cbc;
struct crypto_cipher *tfm_aes;
struct wusb_mac_scratch *scratch;
u64 sfn = 0;
__le64 sfn_le;
tfm_cbc = crypto_alloc_skcipher("cbc(aes)", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm_cbc)) {
result = PTR_ERR(tfm_cbc);
printk(KERN_ERR "E: can't load CBC(AES): %d\n", (int)result);
goto error_alloc_cbc;
}
result = crypto_skcipher_setkey(tfm_cbc, key, 16);
if (result < 0) {
printk(KERN_ERR "E: can't set CBC key: %d\n", (int)result);
goto error_setkey_cbc;
}
tfm_aes = crypto_alloc_cipher("aes", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm_aes)) {
result = PTR_ERR(tfm_aes);
printk(KERN_ERR "E: can't load AES: %d\n", (int)result);
goto error_alloc_aes;
}
result = crypto_cipher_setkey(tfm_aes, key, 16);
if (result < 0) {
printk(KERN_ERR "E: can't set AES key: %d\n", (int)result);
goto error_setkey_aes;
}
scratch = kmalloc(sizeof(*scratch), GFP_KERNEL);
if (!scratch) {
result = -ENOMEM;
goto error_alloc_scratch;
}
for (bitr = 0; bitr < (len + 63) / 64; bitr++) {
sfn_le = cpu_to_le64(sfn++);
memcpy(&n.sfn, &sfn_le, sizeof(n.sfn));
result = wusb_ccm_mac(tfm_cbc, tfm_aes, scratch, out + bytes,
&n, a, b, blen);
if (result < 0)
goto error_ccm_mac;
bytes += result;
}
result = bytes;
kfree(scratch);
error_alloc_scratch:
error_ccm_mac:
error_setkey_aes:
crypto_free_cipher(tfm_aes);
error_alloc_aes:
error_setkey_cbc:
crypto_free_skcipher(tfm_cbc);
error_alloc_cbc:
return result;
}
static int wusb_oob_mic_verify(void)
{
int result;
u8 mic[8];
struct usb_handshake stv_hsmic_hs = {
.bMessageNumber = 2,
.bStatus = 00,
.tTKID = { 0x76, 0x98, 0x01 },
.bReserved = 00,
.CDID = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35,
0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b,
0x3c, 0x3d, 0x3e, 0x3f },
.nonce = { 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,
0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
0x2c, 0x2d, 0x2e, 0x2f },
.MIC = { 0x75, 0x6a, 0x97, 0x51, 0x0c, 0x8c,
0x14, 0x7b },
};
size_t hs_size;
result = wusb_oob_mic(mic, stv_hsmic_key, &stv_hsmic_n, &stv_hsmic_hs);
if (result < 0)
printk(KERN_ERR "E: WUSB OOB MIC test: failed: %d\n", result);
else if (memcmp(stv_hsmic_hs.MIC, mic, sizeof(mic))) {
printk(KERN_ERR "E: OOB MIC test: "
"mismatch between MIC result and WUSB1.0[A2]\n");
hs_size = sizeof(stv_hsmic_hs) - sizeof(stv_hsmic_hs.MIC);
printk(KERN_ERR "E: Handshake2 in: (%zu bytes)\n", hs_size);
wusb_key_dump(&stv_hsmic_hs, hs_size);
printk(KERN_ERR "E: CCM Nonce in: (%zu bytes)\n",
sizeof(stv_hsmic_n));
wusb_key_dump(&stv_hsmic_n, sizeof(stv_hsmic_n));
printk(KERN_ERR "E: MIC out:\n");
wusb_key_dump(mic, sizeof(mic));
printk(KERN_ERR "E: MIC out (from WUSB1.0[A.2]):\n");
wusb_key_dump(stv_hsmic_hs.MIC, sizeof(stv_hsmic_hs.MIC));
result = -EINVAL;
} else
result = 0;
return result;
}
static int wusb_key_derive_verify(void)
{
int result = 0;
struct wusb_keydvt_out keydvt_out;
struct wusb_keydvt_in stv_keydvt_in_a1 = {
.hnonce = {
0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
},
.dnonce = {
0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f
}
};
result = wusb_key_derive(&keydvt_out, stv_key_a1, &stv_keydvt_n_a1,
&stv_keydvt_in_a1);
if (result < 0)
printk(KERN_ERR "E: WUSB key derivation test: "
"derivation failed: %d\n", result);
if (memcmp(&stv_keydvt_out_a1, &keydvt_out, sizeof(keydvt_out))) {
printk(KERN_ERR "E: WUSB key derivation test: "
"mismatch between key derivation result "
"and WUSB1.0[A1] Errata 2006/12\n");
printk(KERN_ERR "E: keydvt in: key\n");
wusb_key_dump(stv_key_a1, sizeof(stv_key_a1));
printk(KERN_ERR "E: keydvt in: nonce\n");
wusb_key_dump(&stv_keydvt_n_a1, sizeof(stv_keydvt_n_a1));
printk(KERN_ERR "E: keydvt in: hnonce & dnonce\n");
wusb_key_dump(&stv_keydvt_in_a1, sizeof(stv_keydvt_in_a1));
printk(KERN_ERR "E: keydvt out: KCK\n");
wusb_key_dump(&keydvt_out.kck, sizeof(keydvt_out.kck));
printk(KERN_ERR "E: keydvt out: PTK\n");
wusb_key_dump(&keydvt_out.ptk, sizeof(keydvt_out.ptk));
result = -EINVAL;
} else
result = 0;
return result;
}
int wusb_crypto_init(void)
{
int result;
if (debug_crypto_verify) {
result = wusb_key_derive_verify();
if (result < 0)
return result;
return wusb_oob_mic_verify();
}
return 0;
}
void wusb_crypto_exit(void)
{
}
