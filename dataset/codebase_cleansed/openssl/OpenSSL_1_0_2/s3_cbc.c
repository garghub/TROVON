int ssl3_cbc_remove_padding(const SSL *s,
SSL3_RECORD *rec,
unsigned block_size, unsigned mac_size)
{
unsigned padding_length, good;
const unsigned overhead = 1 + mac_size;
if (overhead > rec->length)
return 0;
padding_length = rec->data[rec->length - 1];
good = constant_time_ge(rec->length, padding_length + overhead);
good &= constant_time_ge(block_size, padding_length + 1);
padding_length = good & (padding_length + 1);
rec->length -= padding_length;
rec->type |= padding_length << 8;
return constant_time_select_int(good, 1, -1);
}
int tls1_cbc_remove_padding(const SSL *s,
SSL3_RECORD *rec,
unsigned block_size, unsigned mac_size)
{
unsigned padding_length, good, to_check, i;
const unsigned overhead = 1 + mac_size;
if (SSL_USE_EXPLICIT_IV(s)) {
if (overhead + block_size > rec->length)
return 0;
rec->data += block_size;
rec->input += block_size;
rec->length -= block_size;
} else if (overhead > rec->length)
return 0;
padding_length = rec->data[rec->length - 1];
if ((s->options & SSL_OP_TLS_BLOCK_PADDING_BUG) && !s->expand) {
if ((memcmp(s->s3->read_sequence, "\0\0\0\0\0\0\0\0", 8) == 0) &&
!(padding_length & 1)) {
s->s3->flags |= TLS1_FLAGS_TLS_PADDING_BUG;
}
if ((s->s3->flags & TLS1_FLAGS_TLS_PADDING_BUG) && padding_length > 0) {
padding_length--;
}
}
if (EVP_CIPHER_flags(s->enc_read_ctx->cipher) & EVP_CIPH_FLAG_AEAD_CIPHER) {
rec->length -= padding_length + 1;
return 1;
}
good = constant_time_ge(rec->length, overhead + padding_length);
to_check = 255;
if (to_check > rec->length - 1)
to_check = rec->length - 1;
for (i = 0; i < to_check; i++) {
unsigned char mask = constant_time_ge_8(padding_length, i);
unsigned char b = rec->data[rec->length - 1 - i];
good &= ~(mask & (padding_length ^ b));
}
good = constant_time_eq(0xff, good & 0xff);
padding_length = good & (padding_length + 1);
rec->length -= padding_length;
rec->type |= padding_length << 8;
return constant_time_select_int(good, 1, -1);
}
void ssl3_cbc_copy_mac(unsigned char *out,
const SSL3_RECORD *rec,
unsigned md_size, unsigned orig_len)
{
#if defined(CBC_MAC_ROTATE_IN_PLACE)
unsigned char rotated_mac_buf[64 + EVP_MAX_MD_SIZE];
unsigned char *rotated_mac;
#else
unsigned char rotated_mac[EVP_MAX_MD_SIZE];
#endif
unsigned mac_end = rec->length;
unsigned mac_start = mac_end - md_size;
unsigned scan_start = 0;
unsigned i, j;
unsigned div_spoiler;
unsigned rotate_offset;
OPENSSL_assert(orig_len >= md_size);
OPENSSL_assert(md_size <= EVP_MAX_MD_SIZE);
#if defined(CBC_MAC_ROTATE_IN_PLACE)
rotated_mac = rotated_mac_buf + ((0 - (size_t)rotated_mac_buf) & 63);
#endif
if (orig_len > md_size + 255 + 1)
scan_start = orig_len - (md_size + 255 + 1);
div_spoiler = md_size >> 1;
div_spoiler <<= (sizeof(div_spoiler) - 1) * 8;
rotate_offset = (div_spoiler + mac_start - scan_start) % md_size;
memset(rotated_mac, 0, md_size);
for (i = scan_start, j = 0; i < orig_len; i++) {
unsigned char mac_started = constant_time_ge_8(i, mac_start);
unsigned char mac_ended = constant_time_ge_8(i, mac_end);
unsigned char b = rec->data[i];
rotated_mac[j++] |= b & mac_started & ~mac_ended;
j &= constant_time_lt(j, md_size);
}
#if defined(CBC_MAC_ROTATE_IN_PLACE)
j = 0;
for (i = 0; i < md_size; i++) {
((volatile unsigned char *)rotated_mac)[rotate_offset ^ 32];
out[j++] = rotated_mac[rotate_offset++];
rotate_offset &= constant_time_lt(rotate_offset, md_size);
}
#else
memset(out, 0, md_size);
rotate_offset = md_size - rotate_offset;
rotate_offset &= constant_time_lt(rotate_offset, md_size);
for (i = 0; i < md_size; i++) {
for (j = 0; j < md_size; j++)
out[j] |= rotated_mac[i] & constant_time_eq_8(j, rotate_offset);
rotate_offset++;
rotate_offset &= constant_time_lt(rotate_offset, md_size);
}
#endif
}
static void tls1_md5_final_raw(void *ctx, unsigned char *md_out)
{
MD5_CTX *md5 = ctx;
u32toLE(md5->A, md_out);
u32toLE(md5->B, md_out);
u32toLE(md5->C, md_out);
u32toLE(md5->D, md_out);
}
static void tls1_sha1_final_raw(void *ctx, unsigned char *md_out)
{
SHA_CTX *sha1 = ctx;
l2n(sha1->h0, md_out);
l2n(sha1->h1, md_out);
l2n(sha1->h2, md_out);
l2n(sha1->h3, md_out);
l2n(sha1->h4, md_out);
}
static void tls1_sha256_final_raw(void *ctx, unsigned char *md_out)
{
SHA256_CTX *sha256 = ctx;
unsigned i;
for (i = 0; i < 8; i++) {
l2n(sha256->h[i], md_out);
}
}
static void tls1_sha512_final_raw(void *ctx, unsigned char *md_out)
{
SHA512_CTX *sha512 = ctx;
unsigned i;
for (i = 0; i < 8; i++) {
l2n8(sha512->h[i], md_out);
}
}
char ssl3_cbc_record_digest_supported(const EVP_MD_CTX *ctx)
{
#ifdef OPENSSL_FIPS
if (FIPS_mode())
return 0;
#endif
switch (EVP_MD_CTX_type(ctx)) {
case NID_md5:
case NID_sha1:
#ifndef OPENSSL_NO_SHA256
case NID_sha224:
case NID_sha256:
#endif
#ifndef OPENSSL_NO_SHA512
case NID_sha384:
case NID_sha512:
#endif
return 1;
default:
return 0;
}
}
void ssl3_cbc_digest_record(const EVP_MD_CTX *ctx,
unsigned char *md_out,
size_t *md_out_size,
const unsigned char header[13],
const unsigned char *data,
size_t data_plus_mac_size,
size_t data_plus_mac_plus_padding_size,
const unsigned char *mac_secret,
unsigned mac_secret_length, char is_sslv3)
{
union {
double align;
unsigned char c[sizeof(LARGEST_DIGEST_CTX)];
} md_state;
void (*md_final_raw) (void *ctx, unsigned char *md_out);
void (*md_transform) (void *ctx, const unsigned char *block);
unsigned md_size, md_block_size = 64;
unsigned sslv3_pad_length = 40, header_length, variance_blocks,
len, max_mac_bytes, num_blocks,
num_starting_blocks, k, mac_end_offset, c, index_a, index_b;
unsigned int bits;
unsigned char length_bytes[MAX_HASH_BIT_COUNT_BYTES];
unsigned char hmac_pad[MAX_HASH_BLOCK_SIZE];
unsigned char first_block[MAX_HASH_BLOCK_SIZE];
unsigned char mac_out[EVP_MAX_MD_SIZE];
unsigned i, j, md_out_size_u;
EVP_MD_CTX md_ctx;
unsigned md_length_size = 8;
char length_is_big_endian = 1;
OPENSSL_assert(data_plus_mac_plus_padding_size < 1024 * 1024);
switch (EVP_MD_CTX_type(ctx)) {
case NID_md5:
MD5_Init((MD5_CTX *)md_state.c);
md_final_raw = tls1_md5_final_raw;
md_transform =
(void (*)(void *ctx, const unsigned char *block))MD5_Transform;
md_size = 16;
sslv3_pad_length = 48;
length_is_big_endian = 0;
break;
case NID_sha1:
SHA1_Init((SHA_CTX *)md_state.c);
md_final_raw = tls1_sha1_final_raw;
md_transform =
(void (*)(void *ctx, const unsigned char *block))SHA1_Transform;
md_size = 20;
break;
#ifndef OPENSSL_NO_SHA256
case NID_sha224:
SHA224_Init((SHA256_CTX *)md_state.c);
md_final_raw = tls1_sha256_final_raw;
md_transform =
(void (*)(void *ctx, const unsigned char *block))SHA256_Transform;
md_size = 224 / 8;
break;
case NID_sha256:
SHA256_Init((SHA256_CTX *)md_state.c);
md_final_raw = tls1_sha256_final_raw;
md_transform =
(void (*)(void *ctx, const unsigned char *block))SHA256_Transform;
md_size = 32;
break;
#endif
#ifndef OPENSSL_NO_SHA512
case NID_sha384:
SHA384_Init((SHA512_CTX *)md_state.c);
md_final_raw = tls1_sha512_final_raw;
md_transform =
(void (*)(void *ctx, const unsigned char *block))SHA512_Transform;
md_size = 384 / 8;
md_block_size = 128;
md_length_size = 16;
break;
case NID_sha512:
SHA512_Init((SHA512_CTX *)md_state.c);
md_final_raw = tls1_sha512_final_raw;
md_transform =
(void (*)(void *ctx, const unsigned char *block))SHA512_Transform;
md_size = 64;
md_block_size = 128;
md_length_size = 16;
break;
#endif
default:
OPENSSL_assert(0);
if (md_out_size)
*md_out_size = -1;
return;
}
OPENSSL_assert(md_length_size <= MAX_HASH_BIT_COUNT_BYTES);
OPENSSL_assert(md_block_size <= MAX_HASH_BLOCK_SIZE);
OPENSSL_assert(md_size <= EVP_MAX_MD_SIZE);
header_length = 13;
if (is_sslv3) {
header_length = mac_secret_length + sslv3_pad_length + 8 +
1 +
2 ;
}
variance_blocks = is_sslv3 ? 2 : 6;
len = data_plus_mac_plus_padding_size + header_length;
max_mac_bytes = len - md_size - 1;
num_blocks =
(max_mac_bytes + 1 + md_length_size + md_block_size -
1) / md_block_size;
num_starting_blocks = 0;
k = 0;
mac_end_offset = data_plus_mac_size + header_length - md_size;
c = mac_end_offset % md_block_size;
index_a = mac_end_offset / md_block_size;
index_b = (mac_end_offset + md_length_size) / md_block_size;
if (num_blocks > variance_blocks + (is_sslv3 ? 1 : 0)) {
num_starting_blocks = num_blocks - variance_blocks;
k = md_block_size * num_starting_blocks;
}
bits = 8 * mac_end_offset;
if (!is_sslv3) {
bits += 8 * md_block_size;
memset(hmac_pad, 0, md_block_size);
OPENSSL_assert(mac_secret_length <= sizeof(hmac_pad));
memcpy(hmac_pad, mac_secret, mac_secret_length);
for (i = 0; i < md_block_size; i++)
hmac_pad[i] ^= 0x36;
md_transform(md_state.c, hmac_pad);
}
if (length_is_big_endian) {
memset(length_bytes, 0, md_length_size - 4);
length_bytes[md_length_size - 4] = (unsigned char)(bits >> 24);
length_bytes[md_length_size - 3] = (unsigned char)(bits >> 16);
length_bytes[md_length_size - 2] = (unsigned char)(bits >> 8);
length_bytes[md_length_size - 1] = (unsigned char)bits;
} else {
memset(length_bytes, 0, md_length_size);
length_bytes[md_length_size - 5] = (unsigned char)(bits >> 24);
length_bytes[md_length_size - 6] = (unsigned char)(bits >> 16);
length_bytes[md_length_size - 7] = (unsigned char)(bits >> 8);
length_bytes[md_length_size - 8] = (unsigned char)bits;
}
if (k > 0) {
if (is_sslv3) {
unsigned overhang = header_length - md_block_size;
md_transform(md_state.c, header);
memcpy(first_block, header + md_block_size, overhang);
memcpy(first_block + overhang, data, md_block_size - overhang);
md_transform(md_state.c, first_block);
for (i = 1; i < k / md_block_size - 1; i++)
md_transform(md_state.c, data + md_block_size * i - overhang);
} else {
memcpy(first_block, header, 13);
memcpy(first_block + 13, data, md_block_size - 13);
md_transform(md_state.c, first_block);
for (i = 1; i < k / md_block_size; i++)
md_transform(md_state.c, data + md_block_size * i - 13);
}
}
memset(mac_out, 0, sizeof(mac_out));
for (i = num_starting_blocks; i <= num_starting_blocks + variance_blocks;
i++) {
unsigned char block[MAX_HASH_BLOCK_SIZE];
unsigned char is_block_a = constant_time_eq_8(i, index_a);
unsigned char is_block_b = constant_time_eq_8(i, index_b);
for (j = 0; j < md_block_size; j++) {
unsigned char b = 0, is_past_c, is_past_cp1;
if (k < header_length)
b = header[k];
else if (k < data_plus_mac_plus_padding_size + header_length)
b = data[k - header_length];
k++;
is_past_c = is_block_a & constant_time_ge_8(j, c);
is_past_cp1 = is_block_a & constant_time_ge_8(j, c + 1);
b = constant_time_select_8(is_past_c, 0x80, b);
b = b & ~is_past_cp1;
b &= ~is_block_b | is_block_a;
if (j >= md_block_size - md_length_size) {
b = constant_time_select_8(is_block_b,
length_bytes[j -
(md_block_size -
md_length_size)], b);
}
block[j] = b;
}
md_transform(md_state.c, block);
md_final_raw(md_state.c, block);
for (j = 0; j < md_size; j++)
mac_out[j] |= block[j] & is_block_b;
}
EVP_MD_CTX_init(&md_ctx);
EVP_DigestInit_ex(&md_ctx, ctx->digest, NULL );
if (is_sslv3) {
memset(hmac_pad, 0x5c, sslv3_pad_length);
EVP_DigestUpdate(&md_ctx, mac_secret, mac_secret_length);
EVP_DigestUpdate(&md_ctx, hmac_pad, sslv3_pad_length);
EVP_DigestUpdate(&md_ctx, mac_out, md_size);
} else {
for (i = 0; i < md_block_size; i++)
hmac_pad[i] ^= 0x6a;
EVP_DigestUpdate(&md_ctx, hmac_pad, md_block_size);
EVP_DigestUpdate(&md_ctx, mac_out, md_size);
}
EVP_DigestFinal(&md_ctx, md_out, &md_out_size_u);
if (md_out_size)
*md_out_size = md_out_size_u;
EVP_MD_CTX_cleanup(&md_ctx);
}
void tls_fips_digest_extra(const EVP_CIPHER_CTX *cipher_ctx,
EVP_MD_CTX *mac_ctx, const unsigned char *data,
size_t data_len, size_t orig_len)
{
size_t block_size, digest_pad, blocks_data, blocks_orig;
if (EVP_CIPHER_CTX_mode(cipher_ctx) != EVP_CIPH_CBC_MODE)
return;
block_size = EVP_MD_CTX_block_size(mac_ctx);
digest_pad = block_size == 64 ? 21 : 29;
blocks_orig = (orig_len + digest_pad) / block_size;
blocks_data = (data_len + digest_pad) / block_size;
EVP_DigestSignUpdate(mac_ctx, data,
(blocks_orig - blocks_data + 1) * block_size);
}
