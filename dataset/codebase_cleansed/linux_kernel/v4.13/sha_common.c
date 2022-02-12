int s390_sha_update(struct shash_desc *desc, const u8 *data, unsigned int len)
{
struct s390_sha_ctx *ctx = shash_desc_ctx(desc);
unsigned int bsize = crypto_shash_blocksize(desc->tfm);
unsigned int index, n;
index = ctx->count & (bsize - 1);
ctx->count += len;
if ((index + len) < bsize)
goto store;
if (index) {
memcpy(ctx->buf + index, data, bsize - index);
cpacf_kimd(ctx->func, ctx->state, ctx->buf, bsize);
data += bsize - index;
len -= bsize - index;
index = 0;
}
if (len >= bsize) {
n = len & ~(bsize - 1);
cpacf_kimd(ctx->func, ctx->state, data, n);
data += n;
len -= n;
}
store:
if (len)
memcpy(ctx->buf + index , data, len);
return 0;
}
int s390_sha_final(struct shash_desc *desc, u8 *out)
{
struct s390_sha_ctx *ctx = shash_desc_ctx(desc);
unsigned int bsize = crypto_shash_blocksize(desc->tfm);
u64 bits;
unsigned int index, end, plen;
plen = (bsize > SHA256_BLOCK_SIZE) ? 16 : 8;
index = ctx->count & (bsize - 1);
end = (index < bsize - plen) ? bsize : (2 * bsize);
ctx->buf[index] = 0x80;
index++;
memset(ctx->buf + index, 0x00, end - index - 8);
bits = ctx->count * 8;
memcpy(ctx->buf + end - 8, &bits, sizeof(bits));
cpacf_kimd(ctx->func, ctx->state, ctx->buf, end);
memcpy(out, ctx->state, crypto_shash_digestsize(desc->tfm));
memset(ctx, 0, sizeof *ctx);
return 0;
}
