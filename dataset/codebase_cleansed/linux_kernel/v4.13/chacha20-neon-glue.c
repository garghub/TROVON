static void chacha20_doneon(u32 *state, u8 *dst, const u8 *src,
unsigned int bytes)
{
u8 buf[CHACHA20_BLOCK_SIZE];
while (bytes >= CHACHA20_BLOCK_SIZE * 4) {
chacha20_4block_xor_neon(state, dst, src);
bytes -= CHACHA20_BLOCK_SIZE * 4;
src += CHACHA20_BLOCK_SIZE * 4;
dst += CHACHA20_BLOCK_SIZE * 4;
state[12] += 4;
}
while (bytes >= CHACHA20_BLOCK_SIZE) {
chacha20_block_xor_neon(state, dst, src);
bytes -= CHACHA20_BLOCK_SIZE;
src += CHACHA20_BLOCK_SIZE;
dst += CHACHA20_BLOCK_SIZE;
state[12]++;
}
if (bytes) {
memcpy(buf, src, bytes);
chacha20_block_xor_neon(state, buf, buf);
memcpy(dst, buf, bytes);
}
}
static int chacha20_neon(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct chacha20_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
u32 state[16];
int err;
if (req->cryptlen <= CHACHA20_BLOCK_SIZE || !may_use_simd())
return crypto_chacha20_crypt(req);
err = skcipher_walk_virt(&walk, req, true);
crypto_chacha20_init(state, ctx, walk.iv);
kernel_neon_begin();
while (walk.nbytes > 0) {
unsigned int nbytes = walk.nbytes;
if (nbytes < walk.total)
nbytes = round_down(nbytes, walk.stride);
chacha20_doneon(state, walk.dst.virt.addr, walk.src.virt.addr,
nbytes);
err = skcipher_walk_done(&walk, walk.nbytes - nbytes);
}
kernel_neon_end();
return err;
}
static int __init chacha20_simd_mod_init(void)
{
if (!(elf_hwcap & HWCAP_NEON))
return -ENODEV;
return crypto_register_skcipher(&alg);
}
static void __exit chacha20_simd_mod_fini(void)
{
crypto_unregister_skcipher(&alg);
}
