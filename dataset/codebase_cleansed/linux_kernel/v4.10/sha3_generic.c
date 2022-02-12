static void keccakf(u64 st[25])
{
int i, j, round;
u64 t, bc[5];
for (round = 0; round < KECCAK_ROUNDS; round++) {
for (i = 0; i < 5; i++)
bc[i] = st[i] ^ st[i + 5] ^ st[i + 10] ^ st[i + 15]
^ st[i + 20];
for (i = 0; i < 5; i++) {
t = bc[(i + 4) % 5] ^ ROTL64(bc[(i + 1) % 5], 1);
for (j = 0; j < 25; j += 5)
st[j + i] ^= t;
}
t = st[1];
for (i = 0; i < 24; i++) {
j = keccakf_piln[i];
bc[0] = st[j];
st[j] = ROTL64(t, keccakf_rotc[i]);
t = bc[0];
}
for (j = 0; j < 25; j += 5) {
for (i = 0; i < 5; i++)
bc[i] = st[j + i];
for (i = 0; i < 5; i++)
st[j + i] ^= (~bc[(i + 1) % 5]) &
bc[(i + 2) % 5];
}
st[0] ^= keccakf_rndc[round];
}
}
static void sha3_init(struct sha3_state *sctx, unsigned int digest_sz)
{
memset(sctx, 0, sizeof(*sctx));
sctx->md_len = digest_sz;
sctx->rsiz = 200 - 2 * digest_sz;
sctx->rsizw = sctx->rsiz / 8;
}
static int sha3_224_init(struct shash_desc *desc)
{
struct sha3_state *sctx = shash_desc_ctx(desc);
sha3_init(sctx, SHA3_224_DIGEST_SIZE);
return 0;
}
static int sha3_256_init(struct shash_desc *desc)
{
struct sha3_state *sctx = shash_desc_ctx(desc);
sha3_init(sctx, SHA3_256_DIGEST_SIZE);
return 0;
}
static int sha3_384_init(struct shash_desc *desc)
{
struct sha3_state *sctx = shash_desc_ctx(desc);
sha3_init(sctx, SHA3_384_DIGEST_SIZE);
return 0;
}
static int sha3_512_init(struct shash_desc *desc)
{
struct sha3_state *sctx = shash_desc_ctx(desc);
sha3_init(sctx, SHA3_512_DIGEST_SIZE);
return 0;
}
static int sha3_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha3_state *sctx = shash_desc_ctx(desc);
unsigned int done;
const u8 *src;
done = 0;
src = data;
if ((sctx->partial + len) > (sctx->rsiz - 1)) {
if (sctx->partial) {
done = -sctx->partial;
memcpy(sctx->buf + sctx->partial, data,
done + sctx->rsiz);
src = sctx->buf;
}
do {
unsigned int i;
for (i = 0; i < sctx->rsizw; i++)
sctx->st[i] ^= ((u64 *) src)[i];
keccakf(sctx->st);
done += sctx->rsiz;
src = data + done;
} while (done + (sctx->rsiz - 1) < len);
sctx->partial = 0;
}
memcpy(sctx->buf + sctx->partial, src, len - done);
sctx->partial += (len - done);
return 0;
}
static int sha3_final(struct shash_desc *desc, u8 *out)
{
struct sha3_state *sctx = shash_desc_ctx(desc);
unsigned int i, inlen = sctx->partial;
sctx->buf[inlen++] = 0x06;
memset(sctx->buf + inlen, 0, sctx->rsiz - inlen);
sctx->buf[sctx->rsiz - 1] |= 0x80;
for (i = 0; i < sctx->rsizw; i++)
sctx->st[i] ^= ((u64 *) sctx->buf)[i];
keccakf(sctx->st);
for (i = 0; i < sctx->rsizw; i++)
sctx->st[i] = cpu_to_le64(sctx->st[i]);
memcpy(out, sctx->st, sctx->md_len);
memset(sctx, 0, sizeof(*sctx));
return 0;
}
static int __init sha3_generic_mod_init(void)
{
int ret;
ret = crypto_register_shash(&sha3_224);
if (ret < 0)
goto err_out;
ret = crypto_register_shash(&sha3_256);
if (ret < 0)
goto err_out_224;
ret = crypto_register_shash(&sha3_384);
if (ret < 0)
goto err_out_256;
ret = crypto_register_shash(&sha3_512);
if (ret < 0)
goto err_out_384;
return 0;
err_out_384:
crypto_unregister_shash(&sha3_384);
err_out_256:
crypto_unregister_shash(&sha3_256);
err_out_224:
crypto_unregister_shash(&sha3_224);
err_out:
return ret;
}
static void __exit sha3_generic_mod_fini(void)
{
crypto_unregister_shash(&sha3_224);
crypto_unregister_shash(&sha3_256);
crypto_unregister_shash(&sha3_384);
crypto_unregister_shash(&sha3_512);
}
