static int update_param(struct nx842_crypto_param *p,
unsigned int slen, unsigned int dlen)
{
if (p->iremain < slen)
return -EOVERFLOW;
if (p->oremain < dlen)
return -ENOSPC;
p->in += slen;
p->iremain -= slen;
p->out += dlen;
p->oremain -= dlen;
p->ototal += dlen;
return 0;
}
static int nx842_crypto_init(struct crypto_tfm *tfm)
{
struct nx842_crypto_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->wmem = kmalloc(nx842_workmem_size(), GFP_KERNEL);
ctx->sbounce = (u8 *)__get_free_pages(GFP_KERNEL, BOUNCE_BUFFER_ORDER);
ctx->dbounce = (u8 *)__get_free_pages(GFP_KERNEL, BOUNCE_BUFFER_ORDER);
if (!ctx->wmem || !ctx->sbounce || !ctx->dbounce) {
kfree(ctx->wmem);
free_page((unsigned long)ctx->sbounce);
free_page((unsigned long)ctx->dbounce);
return -ENOMEM;
}
return 0;
}
static void nx842_crypto_exit(struct crypto_tfm *tfm)
{
struct nx842_crypto_ctx *ctx = crypto_tfm_ctx(tfm);
kfree(ctx->wmem);
free_page((unsigned long)ctx->sbounce);
free_page((unsigned long)ctx->dbounce);
}
static int read_constraints(struct nx842_constraints *c)
{
int ret;
ret = nx842_constraints(c);
if (ret) {
pr_err_ratelimited("could not get nx842 constraints : %d\n",
ret);
return ret;
}
if (c->maximum > BOUNCE_BUFFER_SIZE) {
c->maximum = BOUNCE_BUFFER_SIZE;
pr_info_once("limiting nx842 maximum to %x\n", c->maximum);
}
return 0;
}
static int nx842_crypto_add_header(struct nx842_crypto_header *hdr, u8 *buf)
{
int s = NX842_CRYPTO_HEADER_SIZE(hdr->groups);
if (s > be16_to_cpu(hdr->group[0].padding)) {
pr_err("Internal error: no space for header\n");
return -EINVAL;
}
memcpy(buf, hdr, s);
print_hex_dump_debug("header ", DUMP_PREFIX_OFFSET, 16, 1, buf, s, 0);
return 0;
}
static int compress(struct nx842_crypto_ctx *ctx,
struct nx842_crypto_param *p,
struct nx842_crypto_header_group *g,
struct nx842_constraints *c,
u16 *ignore,
unsigned int hdrsize)
{
unsigned int slen = p->iremain, dlen = p->oremain, tmplen;
unsigned int adj_slen = slen;
u8 *src = p->in, *dst = p->out;
int ret, dskip = 0;
ktime_t timeout;
if (p->iremain == 0)
return -EOVERFLOW;
if (p->oremain == 0 || hdrsize + c->minimum > dlen)
return -ENOSPC;
if (slen % c->multiple)
adj_slen = round_up(slen, c->multiple);
if (slen < c->minimum)
adj_slen = c->minimum;
if (slen > c->maximum)
adj_slen = slen = c->maximum;
if (adj_slen > slen || (u64)src % c->alignment) {
adj_slen = min(adj_slen, BOUNCE_BUFFER_SIZE);
slen = min(slen, BOUNCE_BUFFER_SIZE);
if (adj_slen > slen)
memset(ctx->sbounce + slen, 0, adj_slen - slen);
memcpy(ctx->sbounce, src, slen);
src = ctx->sbounce;
slen = adj_slen;
pr_debug("using comp sbounce buffer, len %x\n", slen);
}
dst += hdrsize;
dlen -= hdrsize;
if ((u64)dst % c->alignment) {
dskip = (int)(PTR_ALIGN(dst, c->alignment) - dst);
dst += dskip;
dlen -= dskip;
}
if (dlen % c->multiple)
dlen = round_down(dlen, c->multiple);
if (dlen < c->minimum) {
nospc:
dst = ctx->dbounce;
dlen = min(p->oremain, BOUNCE_BUFFER_SIZE);
dlen = round_down(dlen, c->multiple);
dskip = 0;
pr_debug("using comp dbounce buffer, len %x\n", dlen);
}
if (dlen > c->maximum)
dlen = c->maximum;
tmplen = dlen;
timeout = ktime_add_ms(ktime_get(), COMP_BUSY_TIMEOUT);
do {
dlen = tmplen;
ret = nx842_compress(src, slen, dst, &dlen, ctx->wmem);
if (ret == -ENOSPC && dst != ctx->dbounce)
goto nospc;
} while (ret == -EBUSY && ktime_before(ktime_get(), timeout));
if (ret)
return ret;
dskip += hdrsize;
if (dst == ctx->dbounce)
memcpy(p->out + dskip, dst, dlen);
g->padding = cpu_to_be16(dskip);
g->compressed_length = cpu_to_be32(dlen);
g->uncompressed_length = cpu_to_be32(slen);
if (p->iremain < slen) {
*ignore = slen - p->iremain;
slen = p->iremain;
}
pr_debug("compress slen %x ignore %x dlen %x padding %x\n",
slen, *ignore, dlen, dskip);
return update_param(p, slen, dskip + dlen);
}
static int nx842_crypto_compress(struct crypto_tfm *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
struct nx842_crypto_ctx *ctx = crypto_tfm_ctx(tfm);
struct nx842_crypto_header *hdr = &ctx->header;
struct nx842_crypto_param p;
struct nx842_constraints c;
unsigned int groups, hdrsize, h;
int ret, n;
bool add_header;
u16 ignore = 0;
p.in = (u8 *)src;
p.iremain = slen;
p.out = dst;
p.oremain = *dlen;
p.ototal = 0;
*dlen = 0;
ret = read_constraints(&c);
if (ret)
return ret;
groups = min_t(unsigned int, NX842_CRYPTO_GROUP_MAX,
DIV_ROUND_UP(p.iremain, c.maximum));
hdrsize = NX842_CRYPTO_HEADER_SIZE(groups);
add_header = (p.iremain % c.multiple ||
p.iremain < c.minimum ||
p.iremain > c.maximum ||
(u64)p.in % c.alignment ||
p.oremain % c.multiple ||
p.oremain < c.minimum ||
p.oremain > c.maximum ||
(u64)p.out % c.alignment);
hdr->magic = cpu_to_be16(NX842_CRYPTO_MAGIC);
hdr->groups = 0;
hdr->ignore = 0;
while (p.iremain > 0) {
n = hdr->groups++;
if (hdr->groups > NX842_CRYPTO_GROUP_MAX)
return -ENOSPC;
h = !n && add_header ? hdrsize : 0;
if (ignore)
pr_warn("interal error, ignore is set %x\n", ignore);
ret = compress(ctx, &p, &hdr->group[n], &c, &ignore, h);
if (ret)
return ret;
}
if (!add_header && hdr->groups > 1) {
pr_err("Internal error: No header but multiple groups\n");
return -EINVAL;
}
hdr->ignore = cpu_to_be16(ignore);
if (ignore)
pr_debug("marked %d bytes as ignore\n", ignore);
if (add_header)
ret = nx842_crypto_add_header(hdr, dst);
if (ret)
return ret;
*dlen = p.ototal;
pr_debug("compress total slen %x dlen %x\n", slen, *dlen);
return 0;
}
static int decompress(struct nx842_crypto_ctx *ctx,
struct nx842_crypto_param *p,
struct nx842_crypto_header_group *g,
struct nx842_constraints *c,
u16 ignore,
bool usehw)
{
unsigned int slen = be32_to_cpu(g->compressed_length);
unsigned int required_len = be32_to_cpu(g->uncompressed_length);
unsigned int dlen = p->oremain, tmplen;
unsigned int adj_slen = slen;
u8 *src = p->in, *dst = p->out;
u16 padding = be16_to_cpu(g->padding);
int ret, spadding = 0, dpadding = 0;
ktime_t timeout;
if (!slen || !required_len)
return -EINVAL;
if (p->iremain <= 0 || padding + slen > p->iremain)
return -EOVERFLOW;
if (p->oremain <= 0 || required_len - ignore > p->oremain)
return -ENOSPC;
src += padding;
if (!usehw)
goto usesw;
if (slen % c->multiple)
adj_slen = round_up(slen, c->multiple);
if (slen < c->minimum)
adj_slen = c->minimum;
if (slen > c->maximum)
goto usesw;
if (slen < adj_slen || (u64)src % c->alignment) {
if (slen < adj_slen)
memset(ctx->sbounce + slen, 0, adj_slen - slen);
memcpy(ctx->sbounce, src, slen);
src = ctx->sbounce;
spadding = adj_slen - slen;
slen = adj_slen;
pr_debug("using decomp sbounce buffer, len %x\n", slen);
}
if (dlen % c->multiple)
dlen = round_down(dlen, c->multiple);
if (dlen < required_len || (u64)dst % c->alignment) {
dst = ctx->dbounce;
dlen = min(required_len, BOUNCE_BUFFER_SIZE);
pr_debug("using decomp dbounce buffer, len %x\n", dlen);
}
if (dlen < c->minimum)
goto usesw;
if (dlen > c->maximum)
dlen = c->maximum;
tmplen = dlen;
timeout = ktime_add_ms(ktime_get(), DECOMP_BUSY_TIMEOUT);
do {
dlen = tmplen;
ret = nx842_decompress(src, slen, dst, &dlen, ctx->wmem);
} while (ret == -EBUSY && ktime_before(ktime_get(), timeout));
if (ret) {
usesw:
src = p->in + padding;
slen = be32_to_cpu(g->compressed_length);
spadding = 0;
dst = p->out;
dlen = p->oremain;
dpadding = 0;
if (dlen < required_len) {
dst = ctx->dbounce;
dlen = BOUNCE_BUFFER_SIZE;
}
pr_info_ratelimited("using software 842 decompression\n");
ret = sw842_decompress(src, slen, dst, &dlen);
}
if (ret)
return ret;
slen -= spadding;
dlen -= ignore;
if (ignore)
pr_debug("ignoring last %x bytes\n", ignore);
if (dst == ctx->dbounce)
memcpy(p->out, dst, dlen);
pr_debug("decompress slen %x padding %x dlen %x ignore %x\n",
slen, padding, dlen, ignore);
return update_param(p, slen + padding, dlen);
}
static int nx842_crypto_decompress(struct crypto_tfm *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
struct nx842_crypto_ctx *ctx = crypto_tfm_ctx(tfm);
struct nx842_crypto_header *hdr;
struct nx842_crypto_param p;
struct nx842_constraints c;
int n, ret, hdr_len;
u16 ignore = 0;
bool usehw = true;
p.in = (u8 *)src;
p.iremain = slen;
p.out = dst;
p.oremain = *dlen;
p.ototal = 0;
*dlen = 0;
if (read_constraints(&c))
usehw = false;
hdr = (struct nx842_crypto_header *)src;
if (be16_to_cpu(hdr->magic) != NX842_CRYPTO_MAGIC) {
struct nx842_crypto_header_group g = {
.padding = 0,
.compressed_length = cpu_to_be32(p.iremain),
.uncompressed_length = cpu_to_be32(p.oremain),
};
ret = decompress(ctx, &p, &g, &c, 0, usehw);
if (ret)
return ret;
*dlen = p.ototal;
return 0;
}
if (!hdr->groups) {
pr_err("header has no groups\n");
return -EINVAL;
}
if (hdr->groups > NX842_CRYPTO_GROUP_MAX) {
pr_err("header has too many groups %x, max %x\n",
hdr->groups, NX842_CRYPTO_GROUP_MAX);
return -EINVAL;
}
hdr_len = NX842_CRYPTO_HEADER_SIZE(hdr->groups);
if (hdr_len > slen)
return -EOVERFLOW;
memcpy(&ctx->header, src, hdr_len);
hdr = &ctx->header;
for (n = 0; n < hdr->groups; n++) {
if (n + 1 == hdr->groups)
ignore = be16_to_cpu(hdr->ignore);
ret = decompress(ctx, &p, &hdr->group[n], &c, ignore, usehw);
if (ret)
return ret;
}
*dlen = p.ototal;
pr_debug("decompress total slen %x dlen %x\n", slen, *dlen);
return 0;
}
static int __init nx842_crypto_mod_init(void)
{
return crypto_register_alg(&alg);
}
static void __exit nx842_crypto_mod_exit(void)
{
crypto_unregister_alg(&alg);
}
