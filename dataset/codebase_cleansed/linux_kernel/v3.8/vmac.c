static void poly_step_func(u64 *ahi, u64 *alo,
const u64 *kh, const u64 *kl,
const u64 *mh, const u64 *ml)
{
#define a0 (*(((u32 *)alo)+INDEX_LOW))
#define a1 (*(((u32 *)alo)+INDEX_HIGH))
#define a2 (*(((u32 *)ahi)+INDEX_LOW))
#define a3 (*(((u32 *)ahi)+INDEX_HIGH))
#define k0 (*(((u32 *)kl)+INDEX_LOW))
#define k1 (*(((u32 *)kl)+INDEX_HIGH))
#define k2 (*(((u32 *)kh)+INDEX_LOW))
#define k3 (*(((u32 *)kh)+INDEX_HIGH))
u64 p, q, t;
u32 t2;
p = MUL32(a3, k3);
p += p;
p += *(u64 *)mh;
p += MUL32(a0, k2);
p += MUL32(a1, k1);
p += MUL32(a2, k0);
t = (u32)(p);
p >>= 32;
p += MUL32(a0, k3);
p += MUL32(a1, k2);
p += MUL32(a2, k1);
p += MUL32(a3, k0);
t |= ((u64)((u32)p & 0x7fffffff)) << 32;
p >>= 31;
p += (u64)(((u32 *)ml)[INDEX_LOW]);
p += MUL32(a0, k0);
q = MUL32(a1, k3);
q += MUL32(a2, k2);
q += MUL32(a3, k1);
q += q;
p += q;
t2 = (u32)(p);
p >>= 32;
p += (u64)(((u32 *)ml)[INDEX_HIGH]);
p += MUL32(a0, k1);
p += MUL32(a1, k0);
q = MUL32(a2, k3);
q += MUL32(a3, k2);
q += q;
p += q;
*(u64 *)(alo) = (p << 32) | t2;
p >>= 32;
*(u64 *)(ahi) = p + t;
#undef a0
#undef a1
#undef a2
#undef a3
#undef k0
#undef k1
#undef k2
#undef k3
}
static void vhash_abort(struct vmac_ctx *ctx)
{
ctx->polytmp[0] = ctx->polykey[0] ;
ctx->polytmp[1] = ctx->polykey[1] ;
ctx->first_block_processed = 0;
}
static u64 l3hash(u64 p1, u64 p2, u64 k1, u64 k2, u64 len)
{
u64 rh, rl, t, z = 0;
t = p1 >> 63;
p1 &= m63;
ADD128(p1, p2, len, t);
t = (p1 > m63) + ((p1 == m63) && (p2 == m64));
ADD128(p1, p2, z, t);
p1 &= m63;
t = p1 + (p2 >> 32);
t += (t >> 32);
t += (u32)t > 0xfffffffeu;
p1 += (t >> 32);
p2 += (p1 << 32);
p1 += k1;
p1 += (0 - (p1 < k1)) & 257;
p2 += k2;
p2 += (0 - (p2 < k2)) & 257;
MUL64(rh, rl, p1, p2);
t = rh >> 56;
ADD128(t, rl, z, rh);
rh <<= 8;
ADD128(t, rl, z, rh);
t += t << 8;
rl += t;
rl += (0 - (rl < t)) & 257;
rl += (0 - (rl > p64-1)) & 257;
return rl;
}
static void vhash_update(const unsigned char *m,
unsigned int mbytes,
struct vmac_ctx *ctx)
{
u64 rh, rl, *mptr;
const u64 *kptr = (u64 *)ctx->nhkey;
int i;
u64 ch, cl;
u64 pkh = ctx->polykey[0];
u64 pkl = ctx->polykey[1];
if (!mbytes)
return;
BUG_ON(mbytes % VMAC_NHBYTES);
mptr = (u64 *)m;
i = mbytes / VMAC_NHBYTES;
ch = ctx->polytmp[0];
cl = ctx->polytmp[1];
if (!ctx->first_block_processed) {
ctx->first_block_processed = 1;
nh_vmac_nhbytes(mptr, kptr, VMAC_NHBYTES/8, rh, rl);
rh &= m62;
ADD128(ch, cl, rh, rl);
mptr += (VMAC_NHBYTES/sizeof(u64));
i--;
}
while (i--) {
nh_vmac_nhbytes(mptr, kptr, VMAC_NHBYTES/8, rh, rl);
rh &= m62;
poly_step(ch, cl, pkh, pkl, rh, rl);
mptr += (VMAC_NHBYTES/sizeof(u64));
}
ctx->polytmp[0] = ch;
ctx->polytmp[1] = cl;
}
static u64 vhash(unsigned char m[], unsigned int mbytes,
u64 *tagl, struct vmac_ctx *ctx)
{
u64 rh, rl, *mptr;
const u64 *kptr = (u64 *)ctx->nhkey;
int i, remaining;
u64 ch, cl;
u64 pkh = ctx->polykey[0];
u64 pkl = ctx->polykey[1];
mptr = (u64 *)m;
i = mbytes / VMAC_NHBYTES;
remaining = mbytes % VMAC_NHBYTES;
if (ctx->first_block_processed) {
ch = ctx->polytmp[0];
cl = ctx->polytmp[1];
} else if (i) {
nh_vmac_nhbytes(mptr, kptr, VMAC_NHBYTES/8, ch, cl);
ch &= m62;
ADD128(ch, cl, pkh, pkl);
mptr += (VMAC_NHBYTES/sizeof(u64));
i--;
} else if (remaining) {
nh_16(mptr, kptr, 2*((remaining+15)/16), ch, cl);
ch &= m62;
ADD128(ch, cl, pkh, pkl);
mptr += (VMAC_NHBYTES/sizeof(u64));
goto do_l3;
} else {
ch = pkh; cl = pkl;
goto do_l3;
}
while (i--) {
nh_vmac_nhbytes(mptr, kptr, VMAC_NHBYTES/8, rh, rl);
rh &= m62;
poly_step(ch, cl, pkh, pkl, rh, rl);
mptr += (VMAC_NHBYTES/sizeof(u64));
}
if (remaining) {
nh_16(mptr, kptr, 2*((remaining+15)/16), rh, rl);
rh &= m62;
poly_step(ch, cl, pkh, pkl, rh, rl);
}
do_l3:
vhash_abort(ctx);
remaining *= 8;
return l3hash(ch, cl, ctx->l3key[0], ctx->l3key[1], remaining);
}
static u64 vmac(unsigned char m[], unsigned int mbytes,
const unsigned char n[16], u64 *tagl,
struct vmac_ctx_t *ctx)
{
u64 *in_n, *out_p;
u64 p, h;
int i;
in_n = ctx->__vmac_ctx.cached_nonce;
out_p = ctx->__vmac_ctx.cached_aes;
i = n[15] & 1;
if ((*(u64 *)(n+8) != in_n[1]) || (*(u64 *)(n) != in_n[0])) {
in_n[0] = *(u64 *)(n);
in_n[1] = *(u64 *)(n+8);
((unsigned char *)in_n)[15] &= 0xFE;
crypto_cipher_encrypt_one(ctx->child,
(unsigned char *)out_p, (unsigned char *)in_n);
((unsigned char *)in_n)[15] |= (unsigned char)(1-i);
}
p = be64_to_cpup(out_p + i);
h = vhash(m, mbytes, (u64 *)0, &ctx->__vmac_ctx);
return le64_to_cpu(p + h);
}
static int vmac_set_key(unsigned char user_key[], struct vmac_ctx_t *ctx)
{
u64 in[2] = {0}, out[2];
unsigned i;
int err = 0;
err = crypto_cipher_setkey(ctx->child, user_key, VMAC_KEY_LEN);
if (err)
return err;
((unsigned char *)in)[0] = 0x80;
for (i = 0; i < sizeof(ctx->__vmac_ctx.nhkey)/8; i += 2) {
crypto_cipher_encrypt_one(ctx->child,
(unsigned char *)out, (unsigned char *)in);
ctx->__vmac_ctx.nhkey[i] = be64_to_cpup(out);
ctx->__vmac_ctx.nhkey[i+1] = be64_to_cpup(out+1);
((unsigned char *)in)[15] += 1;
}
((unsigned char *)in)[0] = 0xC0;
in[1] = 0;
for (i = 0; i < sizeof(ctx->__vmac_ctx.polykey)/8; i += 2) {
crypto_cipher_encrypt_one(ctx->child,
(unsigned char *)out, (unsigned char *)in);
ctx->__vmac_ctx.polytmp[i] =
ctx->__vmac_ctx.polykey[i] =
be64_to_cpup(out) & mpoly;
ctx->__vmac_ctx.polytmp[i+1] =
ctx->__vmac_ctx.polykey[i+1] =
be64_to_cpup(out+1) & mpoly;
((unsigned char *)in)[15] += 1;
}
((unsigned char *)in)[0] = 0xE0;
in[1] = 0;
for (i = 0; i < sizeof(ctx->__vmac_ctx.l3key)/8; i += 2) {
do {
crypto_cipher_encrypt_one(ctx->child,
(unsigned char *)out, (unsigned char *)in);
ctx->__vmac_ctx.l3key[i] = be64_to_cpup(out);
ctx->__vmac_ctx.l3key[i+1] = be64_to_cpup(out+1);
((unsigned char *)in)[15] += 1;
} while (ctx->__vmac_ctx.l3key[i] >= p64
|| ctx->__vmac_ctx.l3key[i+1] >= p64);
}
ctx->__vmac_ctx.cached_nonce[0] = (u64)-1;
ctx->__vmac_ctx.cached_nonce[1] = (u64)0;
ctx->__vmac_ctx.first_block_processed = 0;
return err;
}
static int vmac_setkey(struct crypto_shash *parent,
const u8 *key, unsigned int keylen)
{
struct vmac_ctx_t *ctx = crypto_shash_ctx(parent);
if (keylen != VMAC_KEY_LEN) {
crypto_shash_set_flags(parent, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
return vmac_set_key((u8 *)key, ctx);
}
static int vmac_init(struct shash_desc *pdesc)
{
return 0;
}
static int vmac_update(struct shash_desc *pdesc, const u8 *p,
unsigned int len)
{
struct crypto_shash *parent = pdesc->tfm;
struct vmac_ctx_t *ctx = crypto_shash_ctx(parent);
int expand;
int min;
expand = VMAC_NHBYTES - ctx->partial_size > 0 ?
VMAC_NHBYTES - ctx->partial_size : 0;
min = len < expand ? len : expand;
memcpy(ctx->partial + ctx->partial_size, p, min);
ctx->partial_size += min;
if (len < expand)
return 0;
vhash_update(ctx->partial, VMAC_NHBYTES, &ctx->__vmac_ctx);
ctx->partial_size = 0;
len -= expand;
p += expand;
if (len % VMAC_NHBYTES) {
memcpy(ctx->partial, p + len - (len % VMAC_NHBYTES),
len % VMAC_NHBYTES);
ctx->partial_size = len % VMAC_NHBYTES;
}
vhash_update(p, len - len % VMAC_NHBYTES, &ctx->__vmac_ctx);
return 0;
}
static int vmac_final(struct shash_desc *pdesc, u8 *out)
{
struct crypto_shash *parent = pdesc->tfm;
struct vmac_ctx_t *ctx = crypto_shash_ctx(parent);
vmac_t mac;
u8 nonce[16] = {};
if (ctx->partial_size) {
memset(ctx->partial + ctx->partial_size, 0,
VMAC_NHBYTES - ctx->partial_size);
}
mac = vmac(ctx->partial, ctx->partial_size, nonce, NULL, ctx);
memcpy(out, &mac, sizeof(vmac_t));
memset(&mac, 0, sizeof(vmac_t));
memset(&ctx->__vmac_ctx, 0, sizeof(struct vmac_ctx));
ctx->partial_size = 0;
return 0;
}
static int vmac_init_tfm(struct crypto_tfm *tfm)
{
struct crypto_cipher *cipher;
struct crypto_instance *inst = (void *)tfm->__crt_alg;
struct crypto_spawn *spawn = crypto_instance_ctx(inst);
struct vmac_ctx_t *ctx = crypto_tfm_ctx(tfm);
cipher = crypto_spawn_cipher(spawn);
if (IS_ERR(cipher))
return PTR_ERR(cipher);
ctx->child = cipher;
return 0;
}
static void vmac_exit_tfm(struct crypto_tfm *tfm)
{
struct vmac_ctx_t *ctx = crypto_tfm_ctx(tfm);
crypto_free_cipher(ctx->child);
}
static int vmac_create(struct crypto_template *tmpl, struct rtattr **tb)
{
struct shash_instance *inst;
struct crypto_alg *alg;
int err;
err = crypto_check_attr_type(tb, CRYPTO_ALG_TYPE_SHASH);
if (err)
return err;
alg = crypto_get_attr_alg(tb, CRYPTO_ALG_TYPE_CIPHER,
CRYPTO_ALG_TYPE_MASK);
if (IS_ERR(alg))
return PTR_ERR(alg);
inst = shash_alloc_instance("vmac", alg);
err = PTR_ERR(inst);
if (IS_ERR(inst))
goto out_put_alg;
err = crypto_init_spawn(shash_instance_ctx(inst), alg,
shash_crypto_instance(inst),
CRYPTO_ALG_TYPE_MASK);
if (err)
goto out_free_inst;
inst->alg.base.cra_priority = alg->cra_priority;
inst->alg.base.cra_blocksize = alg->cra_blocksize;
inst->alg.base.cra_alignmask = alg->cra_alignmask;
inst->alg.digestsize = sizeof(vmac_t);
inst->alg.base.cra_ctxsize = sizeof(struct vmac_ctx_t);
inst->alg.base.cra_init = vmac_init_tfm;
inst->alg.base.cra_exit = vmac_exit_tfm;
inst->alg.init = vmac_init;
inst->alg.update = vmac_update;
inst->alg.final = vmac_final;
inst->alg.setkey = vmac_setkey;
err = shash_register_instance(tmpl, inst);
if (err) {
out_free_inst:
shash_free_instance(shash_crypto_instance(inst));
}
out_put_alg:
crypto_mod_put(alg);
return err;
}
static int __init vmac_module_init(void)
{
return crypto_register_template(&vmac_tmpl);
}
static void __exit vmac_module_exit(void)
{
crypto_unregister_template(&vmac_tmpl);
}
