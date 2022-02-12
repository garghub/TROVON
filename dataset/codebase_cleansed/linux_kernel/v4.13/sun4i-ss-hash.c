int sun4i_hash_crainit(struct crypto_tfm *tfm)
{
struct sun4i_tfm_ctx *op = crypto_tfm_ctx(tfm);
struct ahash_alg *alg = __crypto_ahash_alg(tfm->__crt_alg);
struct sun4i_ss_alg_template *algt;
memset(op, 0, sizeof(struct sun4i_tfm_ctx));
algt = container_of(alg, struct sun4i_ss_alg_template, alg.hash);
op->ss = algt->ss;
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct sun4i_req_ctx));
return 0;
}
int sun4i_hash_init(struct ahash_request *areq)
{
struct sun4i_req_ctx *op = ahash_request_ctx(areq);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(areq);
struct ahash_alg *alg = __crypto_ahash_alg(tfm->base.__crt_alg);
struct sun4i_ss_alg_template *algt;
memset(op, 0, sizeof(struct sun4i_req_ctx));
algt = container_of(alg, struct sun4i_ss_alg_template, alg.hash);
op->mode = algt->mode;
return 0;
}
int sun4i_hash_export_md5(struct ahash_request *areq, void *out)
{
struct sun4i_req_ctx *op = ahash_request_ctx(areq);
struct md5_state *octx = out;
int i;
octx->byte_count = op->byte_count + op->len;
memcpy(octx->block, op->buf, op->len);
if (op->byte_count) {
for (i = 0; i < 4; i++)
octx->hash[i] = op->hash[i];
} else {
octx->hash[0] = SHA1_H0;
octx->hash[1] = SHA1_H1;
octx->hash[2] = SHA1_H2;
octx->hash[3] = SHA1_H3;
}
return 0;
}
int sun4i_hash_import_md5(struct ahash_request *areq, const void *in)
{
struct sun4i_req_ctx *op = ahash_request_ctx(areq);
const struct md5_state *ictx = in;
int i;
sun4i_hash_init(areq);
op->byte_count = ictx->byte_count & ~0x3F;
op->len = ictx->byte_count & 0x3F;
memcpy(op->buf, ictx->block, op->len);
for (i = 0; i < 4; i++)
op->hash[i] = ictx->hash[i];
return 0;
}
int sun4i_hash_export_sha1(struct ahash_request *areq, void *out)
{
struct sun4i_req_ctx *op = ahash_request_ctx(areq);
struct sha1_state *octx = out;
int i;
octx->count = op->byte_count + op->len;
memcpy(octx->buffer, op->buf, op->len);
if (op->byte_count) {
for (i = 0; i < 5; i++)
octx->state[i] = op->hash[i];
} else {
octx->state[0] = SHA1_H0;
octx->state[1] = SHA1_H1;
octx->state[2] = SHA1_H2;
octx->state[3] = SHA1_H3;
octx->state[4] = SHA1_H4;
}
return 0;
}
int sun4i_hash_import_sha1(struct ahash_request *areq, const void *in)
{
struct sun4i_req_ctx *op = ahash_request_ctx(areq);
const struct sha1_state *ictx = in;
int i;
sun4i_hash_init(areq);
op->byte_count = ictx->count & ~0x3F;
op->len = ictx->count & 0x3F;
memcpy(op->buf, ictx->buffer, op->len);
for (i = 0; i < 5; i++)
op->hash[i] = ictx->state[i];
return 0;
}
static int sun4i_hash(struct ahash_request *areq)
{
unsigned int i = 0, end, fill, min_fill, nwait, nbw = 0, j = 0, todo;
unsigned int in_i = 0;
u32 spaces, rx_cnt = SS_RX_DEFAULT, bf[32] = {0}, wb = 0, v, ivmode = 0;
struct sun4i_req_ctx *op = ahash_request_ctx(areq);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(areq);
struct sun4i_tfm_ctx *tfmctx = crypto_ahash_ctx(tfm);
struct sun4i_ss_ctx *ss = tfmctx->ss;
struct scatterlist *in_sg = areq->src;
struct sg_mapping_iter mi;
int in_r, err = 0;
size_t copied = 0;
dev_dbg(ss->dev, "%s %s bc=%llu len=%u mode=%x wl=%u h0=%0x",
__func__, crypto_tfm_alg_name(areq->base.tfm),
op->byte_count, areq->nbytes, op->mode,
op->len, op->hash[0]);
if (unlikely(!areq->nbytes) && !(op->flags & SS_HASH_FINAL))
return 0;
if (unlikely(areq->nbytes > UINT_MAX - op->len)) {
dev_err(ss->dev, "Cannot process too large request\n");
return -EINVAL;
}
if (op->len + areq->nbytes < 64 && !(op->flags & SS_HASH_FINAL)) {
copied = sg_pcopy_to_buffer(areq->src, sg_nents(areq->src),
op->buf + op->len, areq->nbytes, 0);
op->len += copied;
return 0;
}
spin_lock_bh(&ss->slock);
if (op->byte_count) {
ivmode = SS_IV_ARBITRARY;
for (i = 0; i < 5; i++)
writel(op->hash[i], ss->base + SS_IV0 + i * 4);
}
writel(op->mode | SS_ENABLED | ivmode, ss->base + SS_CTL);
if (!(op->flags & SS_HASH_UPDATE))
goto hash_final;
if (!(op->flags & SS_HASH_FINAL)) {
end = ((areq->nbytes + op->len) / 64) * 64 - op->len;
if (end > areq->nbytes || areq->nbytes - end > 63) {
dev_err(ss->dev, "ERROR: Bound error %u %u\n",
end, areq->nbytes);
err = -EINVAL;
goto release_ss;
}
} else {
end = ((areq->nbytes + op->len) / 4) * 4 - op->len;
}
i = 1;
while (in_sg && i == 1) {
if (in_sg->length % 4)
i = 0;
in_sg = sg_next(in_sg);
}
if (i == 1 && !op->len && areq->nbytes)
dev_dbg(ss->dev, "We can DMA\n");
i = 0;
sg_miter_start(&mi, areq->src, sg_nents(areq->src),
SG_MITER_FROM_SG | SG_MITER_ATOMIC);
sg_miter_next(&mi);
in_i = 0;
do {
if (op->len || (mi.length - in_i) < 4) {
while (op->len < 64 && i < end) {
in_r = min3(mi.length - in_i, end - i,
64 - op->len);
memcpy(op->buf + op->len, mi.addr + in_i, in_r);
op->len += in_r;
i += in_r;
in_i += in_r;
if (in_i == mi.length) {
sg_miter_next(&mi);
in_i = 0;
}
}
if (op->len > 3 && !(op->len % 4)) {
writesl(ss->base + SS_RXFIFO, op->buf,
op->len / 4);
op->byte_count += op->len;
op->len = 0;
}
}
if (mi.length - in_i > 3 && i < end) {
in_r = min3(mi.length - in_i, areq->nbytes - i,
((mi.length - in_i) / 4) * 4);
todo = min3((u32)(end - i) / 4, rx_cnt, (u32)in_r / 4);
writesl(ss->base + SS_RXFIFO, mi.addr + in_i, todo);
op->byte_count += todo * 4;
i += todo * 4;
in_i += todo * 4;
rx_cnt -= todo;
if (!rx_cnt) {
spaces = readl(ss->base + SS_FCSR);
rx_cnt = SS_RXFIFO_SPACES(spaces);
}
if (in_i == mi.length) {
sg_miter_next(&mi);
in_i = 0;
}
}
} while (i < end);
if ((areq->nbytes - i) < 64) {
while (i < areq->nbytes && in_i < mi.length && op->len < 64) {
in_r = min3(mi.length - in_i, areq->nbytes - i,
64 - op->len);
memcpy(op->buf + op->len, mi.addr + in_i, in_r);
op->len += in_r;
i += in_r;
in_i += in_r;
if (in_i == mi.length) {
sg_miter_next(&mi);
in_i = 0;
}
}
}
sg_miter_stop(&mi);
if (op->flags & SS_HASH_FINAL)
goto hash_final;
writel(op->mode | SS_ENABLED | SS_DATA_END, ss->base + SS_CTL);
i = 0;
do {
v = readl(ss->base + SS_CTL);
i++;
} while (i < SS_TIMEOUT && (v & SS_DATA_END));
if (unlikely(i >= SS_TIMEOUT)) {
dev_err_ratelimited(ss->dev,
"ERROR: hash end timeout %d>%d ctl=%x len=%u\n",
i, SS_TIMEOUT, v, areq->nbytes);
err = -EIO;
goto release_ss;
}
ndelay(1);
for (i = 0; i < crypto_ahash_digestsize(tfm) / 4; i++)
op->hash[i] = readl(ss->base + SS_MD0 + i * 4);
goto release_ss;
hash_final:
if (op->len) {
nwait = op->len / 4;
if (nwait) {
writesl(ss->base + SS_RXFIFO, op->buf, nwait);
op->byte_count += 4 * nwait;
}
nbw = op->len - 4 * nwait;
if (nbw) {
wb = *(u32 *)(op->buf + nwait * 4);
wb &= GENMASK((nbw * 8) - 1, 0);
op->byte_count += nbw;
}
}
wb |= ((1 << 7) << (nbw * 8));
bf[j++] = wb;
fill = 64 - (op->byte_count % 64);
min_fill = 2 * sizeof(u32) + (nbw ? 0 : sizeof(u32));
if (fill < min_fill)
fill += 64;
j += (fill - min_fill) / sizeof(u32);
if (op->mode == SS_OP_SHA1) {
__be64 bits = cpu_to_be64(op->byte_count << 3);
bf[j++] = lower_32_bits(bits);
bf[j++] = upper_32_bits(bits);
} else {
__le64 bits = op->byte_count << 3;
bf[j++] = lower_32_bits(bits);
bf[j++] = upper_32_bits(bits);
}
writesl(ss->base + SS_RXFIFO, bf, j);
writel(op->mode | SS_ENABLED | SS_DATA_END, ss->base + SS_CTL);
i = 0;
do {
v = readl(ss->base + SS_CTL);
i++;
} while (i < SS_TIMEOUT && (v & SS_DATA_END));
if (unlikely(i >= SS_TIMEOUT)) {
dev_err_ratelimited(ss->dev,
"ERROR: hash end timeout %d>%d ctl=%x len=%u\n",
i, SS_TIMEOUT, v, areq->nbytes);
err = -EIO;
goto release_ss;
}
ndelay(1);
if (op->mode == SS_OP_SHA1) {
for (i = 0; i < 5; i++) {
v = cpu_to_be32(readl(ss->base + SS_MD0 + i * 4));
memcpy(areq->result + i * 4, &v, 4);
}
} else {
for (i = 0; i < 4; i++) {
v = readl(ss->base + SS_MD0 + i * 4);
memcpy(areq->result + i * 4, &v, 4);
}
}
release_ss:
writel(0, ss->base + SS_CTL);
spin_unlock_bh(&ss->slock);
return err;
}
int sun4i_hash_final(struct ahash_request *areq)
{
struct sun4i_req_ctx *op = ahash_request_ctx(areq);
op->flags = SS_HASH_FINAL;
return sun4i_hash(areq);
}
int sun4i_hash_update(struct ahash_request *areq)
{
struct sun4i_req_ctx *op = ahash_request_ctx(areq);
op->flags = SS_HASH_UPDATE;
return sun4i_hash(areq);
}
int sun4i_hash_finup(struct ahash_request *areq)
{
struct sun4i_req_ctx *op = ahash_request_ctx(areq);
op->flags = SS_HASH_UPDATE | SS_HASH_FINAL;
return sun4i_hash(areq);
}
int sun4i_hash_digest(struct ahash_request *areq)
{
int err;
struct sun4i_req_ctx *op = ahash_request_ctx(areq);
err = sun4i_hash_init(areq);
if (err)
return err;
op->flags = SS_HASH_UPDATE | SS_HASH_FINAL;
return sun4i_hash(areq);
}
