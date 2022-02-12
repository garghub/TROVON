static u32 ocb_ntz(u64 n)
{
u32 cnt = 0;
while (!(n & 1)) {
n >>= 1;
cnt++;
}
return cnt;
}
static void ocb_block_lshift(const unsigned char *in, size_t shift,
unsigned char *out)
{
unsigned char shift_mask;
int i;
unsigned char mask[15];
shift_mask = 0xff;
shift_mask <<= (8 - shift);
for (i = 15; i >= 0; i--) {
if (i > 0) {
mask[i - 1] = in[i] & shift_mask;
mask[i - 1] >>= 8 - shift;
}
out[i] = in[i] << shift;
if (i != 15) {
out[i] ^= mask[i];
}
}
}
static void ocb_double(OCB_BLOCK *in, OCB_BLOCK *out)
{
unsigned char mask;
mask = in->c[0] & 0x80;
mask >>= 7;
mask *= 135;
ocb_block_lshift(in->c, 1, out->c);
out->c[15] ^= mask;
}
static void ocb_block_xor(const unsigned char *in1,
const unsigned char *in2, size_t len,
unsigned char *out)
{
size_t i;
for (i = 0; i < len; i++) {
out[i] = in1[i] ^ in2[i];
}
}
static OCB_BLOCK *ocb_lookup_l(OCB128_CONTEXT *ctx, size_t idx)
{
size_t l_index = ctx->l_index;
if (idx <= l_index) {
return ctx->l + idx;
}
if (idx >= ctx->max_l_index) {
void *tmp_ptr;
ctx->max_l_index += (idx - ctx->max_l_index + 4) & ~3;
tmp_ptr =
OPENSSL_realloc(ctx->l, ctx->max_l_index * sizeof(OCB_BLOCK));
if (tmp_ptr == NULL)
return NULL;
ctx->l = tmp_ptr;
}
while (l_index < idx) {
ocb_double(ctx->l + l_index, ctx->l + l_index + 1);
l_index++;
}
ctx->l_index = l_index;
return ctx->l + idx;
}
OCB128_CONTEXT *CRYPTO_ocb128_new(void *keyenc, void *keydec,
block128_f encrypt, block128_f decrypt,
ocb128_f stream)
{
OCB128_CONTEXT *octx;
int ret;
if ((octx = OPENSSL_malloc(sizeof(*octx))) != NULL) {
ret = CRYPTO_ocb128_init(octx, keyenc, keydec, encrypt, decrypt,
stream);
if (ret)
return octx;
OPENSSL_free(octx);
}
return NULL;
}
int CRYPTO_ocb128_init(OCB128_CONTEXT *ctx, void *keyenc, void *keydec,
block128_f encrypt, block128_f decrypt,
ocb128_f stream)
{
memset(ctx, 0, sizeof(*ctx));
ctx->l_index = 0;
ctx->max_l_index = 5;
ctx->l = OPENSSL_malloc(ctx->max_l_index * 16);
if (ctx->l == NULL)
return 0;
ctx->encrypt = encrypt;
ctx->decrypt = decrypt;
ctx->stream = stream;
ctx->keyenc = keyenc;
ctx->keydec = keydec;
ctx->encrypt(ctx->l_star.c, ctx->l_star.c, ctx->keyenc);
ocb_double(&ctx->l_star, &ctx->l_dollar);
ocb_double(&ctx->l_dollar, ctx->l);
ocb_double(ctx->l, ctx->l+1);
ocb_double(ctx->l+1, ctx->l+2);
ocb_double(ctx->l+2, ctx->l+3);
ocb_double(ctx->l+3, ctx->l+4);
ctx->l_index = 4;
return 1;
}
int CRYPTO_ocb128_copy_ctx(OCB128_CONTEXT *dest, OCB128_CONTEXT *src,
void *keyenc, void *keydec)
{
memcpy(dest, src, sizeof(OCB128_CONTEXT));
if (keyenc)
dest->keyenc = keyenc;
if (keydec)
dest->keydec = keydec;
if (src->l) {
dest->l = OPENSSL_malloc(src->max_l_index * 16);
if (dest->l == NULL)
return 0;
memcpy(dest->l, src->l, (src->l_index + 1) * 16);
}
return 1;
}
int CRYPTO_ocb128_setiv(OCB128_CONTEXT *ctx, const unsigned char *iv,
size_t len, size_t taglen)
{
unsigned char ktop[16], tmp[16], mask;
unsigned char stretch[24], nonce[16];
size_t bottom, shift;
if ((len > 15) || (len < 1) || (taglen > 16) || (taglen < 1)) {
return -1;
}
nonce[0] = ((taglen * 8) % 128) << 1;
memset(nonce + 1, 0, 15);
memcpy(nonce + 16 - len, iv, len);
nonce[15 - len] |= 1;
memcpy(tmp, nonce, 16);
tmp[15] &= 0xc0;
ctx->encrypt(tmp, ktop, ctx->keyenc);
memcpy(stretch, ktop, 16);
ocb_block_xor(ktop, ktop + 1, 8, stretch + 16);
bottom = nonce[15] & 0x3f;
shift = bottom % 8;
ocb_block_lshift(stretch + (bottom / 8), shift, ctx->offset.c);
mask = 0xff;
mask <<= 8 - shift;
ctx->offset.c[15] |=
(*(stretch + (bottom / 8) + 16) & mask) >> (8 - shift);
return 1;
}
int CRYPTO_ocb128_aad(OCB128_CONTEXT *ctx, const unsigned char *aad,
size_t len)
{
u64 i, all_num_blocks;
size_t num_blocks, last_len;
OCB_BLOCK tmp1;
OCB_BLOCK tmp2;
num_blocks = len / 16;
all_num_blocks = num_blocks + ctx->blocks_hashed;
for (i = ctx->blocks_hashed + 1; i <= all_num_blocks; i++) {
OCB_BLOCK *lookup;
OCB_BLOCK *aad_block;
lookup = ocb_lookup_l(ctx, ocb_ntz(i));
if (lookup == NULL)
return 0;
ocb_block16_xor(&ctx->offset_aad, lookup, &ctx->offset_aad);
aad_block = (OCB_BLOCK *)(aad + ((i - ctx->blocks_hashed - 1) * 16));
ocb_block16_xor(&ctx->offset_aad, aad_block, &tmp1);
ctx->encrypt(tmp1.c, tmp2.c, ctx->keyenc);
ocb_block16_xor(&ctx->sum, &tmp2, &ctx->sum);
}
last_len = len % 16;
if (last_len > 0) {
ocb_block16_xor(&ctx->offset_aad, &ctx->l_star, &ctx->offset_aad);
memset(&tmp1, 0, 16);
memcpy(&tmp1, aad + (num_blocks * 16), last_len);
((unsigned char *)&tmp1)[last_len] = 0x80;
ocb_block16_xor(&ctx->offset_aad, &tmp1, &tmp2);
ctx->encrypt(tmp2.c, tmp1.c, ctx->keyenc);
ocb_block16_xor(&ctx->sum, &tmp1, &ctx->sum);
}
ctx->blocks_hashed = all_num_blocks;
return 1;
}
int CRYPTO_ocb128_encrypt(OCB128_CONTEXT *ctx,
const unsigned char *in, unsigned char *out,
size_t len)
{
u64 i, all_num_blocks;
size_t num_blocks, last_len;
OCB_BLOCK tmp1;
OCB_BLOCK tmp2;
OCB_BLOCK pad;
num_blocks = len / 16;
all_num_blocks = num_blocks + ctx->blocks_processed;
if (num_blocks && all_num_blocks == (size_t)all_num_blocks
&& ctx->stream != NULL) {
size_t max_idx = 0, top = (size_t)all_num_blocks;
while (top >>= 1)
max_idx++;
if (ocb_lookup_l(ctx, max_idx) == NULL)
return 0;
ctx->stream(in, out, num_blocks, ctx->keyenc,
(size_t)ctx->blocks_processed + 1, ctx->offset.c,
(const unsigned char (*)[16])ctx->l, ctx->checksum.c);
} else {
for (i = ctx->blocks_processed + 1; i <= all_num_blocks; i++) {
OCB_BLOCK *lookup;
OCB_BLOCK *inblock;
OCB_BLOCK *outblock;
lookup = ocb_lookup_l(ctx, ocb_ntz(i));
if (lookup == NULL)
return 0;
ocb_block16_xor(&ctx->offset, lookup, &ctx->offset);
inblock =
(OCB_BLOCK *)(in + ((i - ctx->blocks_processed - 1) * 16));
ocb_block16_xor_misaligned(&ctx->offset, inblock, &tmp1);
ocb_block16_xor_misaligned(&ctx->checksum, inblock, &ctx->checksum);
ctx->encrypt(tmp1.c, tmp2.c, ctx->keyenc);
outblock =
(OCB_BLOCK *)(out + ((i - ctx->blocks_processed - 1) * 16));
ocb_block16_xor_misaligned(&ctx->offset, &tmp2, outblock);
}
}
last_len = len % 16;
if (last_len > 0) {
ocb_block16_xor(&ctx->offset, &ctx->l_star, &ctx->offset);
ctx->encrypt(ctx->offset.c, pad.c, ctx->keyenc);
ocb_block_xor(in + (len / 16) * 16, (unsigned char *)&pad, last_len,
out + (num_blocks * 16));
memset(&tmp1, 0, 16);
memcpy(&tmp1, in + (len / 16) * 16, last_len);
((unsigned char *)(&tmp1))[last_len] = 0x80;
ocb_block16_xor(&ctx->checksum, &tmp1, &ctx->checksum);
}
ctx->blocks_processed = all_num_blocks;
return 1;
}
int CRYPTO_ocb128_decrypt(OCB128_CONTEXT *ctx,
const unsigned char *in, unsigned char *out,
size_t len)
{
u64 i, all_num_blocks;
size_t num_blocks, last_len;
OCB_BLOCK tmp1;
OCB_BLOCK tmp2;
OCB_BLOCK pad;
num_blocks = len / 16;
all_num_blocks = num_blocks + ctx->blocks_processed;
if (num_blocks && all_num_blocks == (size_t)all_num_blocks
&& ctx->stream != NULL) {
size_t max_idx = 0, top = (size_t)all_num_blocks;
while (top >>= 1)
max_idx++;
if (ocb_lookup_l(ctx, max_idx) == NULL)
return 0;
ctx->stream(in, out, num_blocks, ctx->keydec,
(size_t)ctx->blocks_processed + 1, ctx->offset.c,
(const unsigned char (*)[16])ctx->l, ctx->checksum.c);
} else {
for (i = ctx->blocks_processed + 1; i <= all_num_blocks; i++) {
OCB_BLOCK *inblock;
OCB_BLOCK *outblock;
OCB_BLOCK *lookup = ocb_lookup_l(ctx, ocb_ntz(i));
if (lookup == NULL)
return 0;
ocb_block16_xor(&ctx->offset, lookup, &ctx->offset);
inblock =
(OCB_BLOCK *)(in + ((i - ctx->blocks_processed - 1) * 16));
ocb_block16_xor_misaligned(&ctx->offset, inblock, &tmp1);
ctx->decrypt(tmp1.c, tmp2.c, ctx->keydec);
outblock =
(OCB_BLOCK *)(out + ((i - ctx->blocks_processed - 1) * 16));
ocb_block16_xor_misaligned(&ctx->offset, &tmp2, outblock);
ocb_block16_xor_misaligned(&ctx->checksum, outblock, &ctx->checksum);
}
}
last_len = len % 16;
if (last_len > 0) {
ocb_block16_xor(&ctx->offset, &ctx->l_star, &ctx->offset);
ctx->encrypt(ctx->offset.c, pad.c, ctx->keyenc);
ocb_block_xor(in + (len / 16) * 16, (unsigned char *)&pad, last_len,
out + (num_blocks * 16));
memset(&tmp1, 0, 16);
memcpy(&tmp1, out + (len / 16) * 16, last_len);
((unsigned char *)(&tmp1))[last_len] = 0x80;
ocb_block16_xor(&ctx->checksum, &tmp1, &ctx->checksum);
}
ctx->blocks_processed = all_num_blocks;
return 1;
}
int CRYPTO_ocb128_finish(OCB128_CONTEXT *ctx, const unsigned char *tag,
size_t len)
{
OCB_BLOCK tmp1, tmp2;
ocb_block16_xor(&ctx->checksum, &ctx->offset, &tmp1);
ocb_block16_xor(&tmp1, &ctx->l_dollar, &tmp2);
ctx->encrypt(tmp2.c, tmp1.c, ctx->keyenc);
ocb_block16_xor(&tmp1, &ctx->sum, &ctx->tag);
if (len > 16 || len < 1) {
return -1;
}
if (tag)
return CRYPTO_memcmp(&ctx->tag, tag, len);
else
return -1;
}
int CRYPTO_ocb128_tag(OCB128_CONTEXT *ctx, unsigned char *tag, size_t len)
{
if (len > 16 || len < 1) {
return -1;
}
CRYPTO_ocb128_finish(ctx, NULL, 0);
memcpy(tag, &ctx->tag, len);
return 1;
}
void CRYPTO_ocb128_cleanup(OCB128_CONTEXT *ctx)
{
if (ctx) {
OPENSSL_clear_free(ctx->l, ctx->max_l_index * 16);
OPENSSL_cleanse(ctx, sizeof(*ctx));
}
}
