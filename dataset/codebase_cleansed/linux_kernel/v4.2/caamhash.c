static inline int map_seq_out_ptr_ctx(u32 *desc, struct device *jrdev,
struct caam_hash_state *state,
int ctx_len)
{
state->ctx_dma = dma_map_single(jrdev, state->caam_ctx,
ctx_len, DMA_FROM_DEVICE);
if (dma_mapping_error(jrdev, state->ctx_dma)) {
dev_err(jrdev, "unable to map ctx\n");
return -ENOMEM;
}
append_seq_out_ptr(desc, state->ctx_dma, ctx_len, 0);
return 0;
}
static inline dma_addr_t map_seq_out_ptr_result(u32 *desc, struct device *jrdev,
u8 *result, int digestsize)
{
dma_addr_t dst_dma;
dst_dma = dma_map_single(jrdev, result, digestsize, DMA_FROM_DEVICE);
append_seq_out_ptr(desc, dst_dma, digestsize, 0);
return dst_dma;
}
static inline dma_addr_t buf_map_to_sec4_sg(struct device *jrdev,
struct sec4_sg_entry *sec4_sg,
u8 *buf, int buflen)
{
dma_addr_t buf_dma;
buf_dma = dma_map_single(jrdev, buf, buflen, DMA_TO_DEVICE);
dma_to_sec4_sg_one(sec4_sg, buf_dma, buflen, 0);
return buf_dma;
}
static inline void src_map_to_sec4_sg(struct device *jrdev,
struct scatterlist *src, int src_nents,
struct sec4_sg_entry *sec4_sg,
bool chained)
{
dma_map_sg_chained(jrdev, src, src_nents, DMA_TO_DEVICE, chained);
sg_to_sec4_sg_last(src, src_nents, sec4_sg, 0);
}
static inline dma_addr_t
try_buf_map_to_sec4_sg(struct device *jrdev, struct sec4_sg_entry *sec4_sg,
u8 *buf, dma_addr_t buf_dma, int buflen,
int last_buflen)
{
if (buf_dma && !dma_mapping_error(jrdev, buf_dma))
dma_unmap_single(jrdev, buf_dma, last_buflen, DMA_TO_DEVICE);
if (buflen)
buf_dma = buf_map_to_sec4_sg(jrdev, sec4_sg, buf, buflen);
else
buf_dma = 0;
return buf_dma;
}
static inline int ctx_map_to_sec4_sg(u32 *desc, struct device *jrdev,
struct caam_hash_state *state, int ctx_len,
struct sec4_sg_entry *sec4_sg, u32 flag)
{
state->ctx_dma = dma_map_single(jrdev, state->caam_ctx, ctx_len, flag);
if (dma_mapping_error(jrdev, state->ctx_dma)) {
dev_err(jrdev, "unable to map ctx\n");
return -ENOMEM;
}
dma_to_sec4_sg_one(sec4_sg, state->ctx_dma, ctx_len, 0);
return 0;
}
static inline void append_key_ahash(u32 *desc, struct caam_hash_ctx *ctx)
{
append_key_as_imm(desc, ctx->key, ctx->split_key_pad_len,
ctx->split_key_len, CLASS_2 |
KEY_DEST_MDHA_SPLIT | KEY_ENC);
}
static inline void init_sh_desc_key_ahash(u32 *desc, struct caam_hash_ctx *ctx)
{
u32 *key_jump_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL);
if (ctx->split_key_len) {
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
append_key_ahash(desc, ctx);
set_jump_tgt_here(desc, key_jump_cmd);
}
append_cmd(desc, SET_OK_NO_PROP_ERRORS | CMD_LOAD);
}
static inline void ahash_append_load_str(u32 *desc, int digestsize)
{
append_math_add(desc, VARSEQINLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS2 | FIFOLD_TYPE_LAST2 |
FIFOLD_TYPE_MSG | KEY_VLF);
append_seq_store(desc, digestsize, LDST_CLASS_2_CCB |
LDST_SRCDST_BYTE_CONTEXT);
}
static inline void ahash_ctx_data_to_out(u32 *desc, u32 op, u32 state,
int digestsize,
struct caam_hash_ctx *ctx)
{
init_sh_desc_key_ahash(desc, ctx);
append_cmd(desc, CMD_SEQ_LOAD | LDST_SRCDST_BYTE_CONTEXT |
LDST_CLASS_2_CCB | ctx->ctx_len);
append_operation(desc, op | state | OP_ALG_ENCRYPT);
ahash_append_load_str(desc, digestsize);
}
static inline void ahash_data_to_out(u32 *desc, u32 op, u32 state,
int digestsize, struct caam_hash_ctx *ctx)
{
init_sh_desc_key_ahash(desc, ctx);
append_operation(desc, op | state | OP_ALG_ENCRYPT);
ahash_append_load_str(desc, digestsize);
}
static int ahash_set_sh_desc(struct crypto_ahash *ahash)
{
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
int digestsize = crypto_ahash_digestsize(ahash);
struct device *jrdev = ctx->jrdev;
u32 have_key = 0;
u32 *desc;
if (ctx->split_key_len)
have_key = OP_ALG_AAI_HMAC_PRECOMP;
desc = ctx->sh_desc_update;
init_sh_desc(desc, HDR_SHARE_SERIAL);
append_cmd(desc, CMD_SEQ_LOAD | LDST_SRCDST_BYTE_CONTEXT |
LDST_CLASS_2_CCB | ctx->ctx_len);
append_operation(desc, ctx->alg_type | OP_ALG_AS_UPDATE |
OP_ALG_ENCRYPT);
ahash_append_load_str(desc, ctx->ctx_len);
ctx->sh_desc_update_dma = dma_map_single(jrdev, desc, desc_bytes(desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->sh_desc_update_dma)) {
dev_err(jrdev, "unable to map shared descriptor\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"ahash update shdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
desc = ctx->sh_desc_update_first;
ahash_data_to_out(desc, have_key | ctx->alg_type, OP_ALG_AS_INIT,
ctx->ctx_len, ctx);
ctx->sh_desc_update_first_dma = dma_map_single(jrdev, desc,
desc_bytes(desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->sh_desc_update_first_dma)) {
dev_err(jrdev, "unable to map shared descriptor\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"ahash update first shdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
desc = ctx->sh_desc_fin;
ahash_ctx_data_to_out(desc, have_key | ctx->alg_type,
OP_ALG_AS_FINALIZE, digestsize, ctx);
ctx->sh_desc_fin_dma = dma_map_single(jrdev, desc, desc_bytes(desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->sh_desc_fin_dma)) {
dev_err(jrdev, "unable to map shared descriptor\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ahash final shdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
desc = ctx->sh_desc_finup;
ahash_ctx_data_to_out(desc, have_key | ctx->alg_type,
OP_ALG_AS_FINALIZE, digestsize, ctx);
ctx->sh_desc_finup_dma = dma_map_single(jrdev, desc, desc_bytes(desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->sh_desc_finup_dma)) {
dev_err(jrdev, "unable to map shared descriptor\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ahash finup shdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
desc = ctx->sh_desc_digest;
ahash_data_to_out(desc, have_key | ctx->alg_type, OP_ALG_AS_INITFINAL,
digestsize, ctx);
ctx->sh_desc_digest_dma = dma_map_single(jrdev, desc,
desc_bytes(desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->sh_desc_digest_dma)) {
dev_err(jrdev, "unable to map shared descriptor\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"ahash digest shdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
return 0;
}
static int gen_split_hash_key(struct caam_hash_ctx *ctx, const u8 *key_in,
u32 keylen)
{
return gen_split_key(ctx->jrdev, ctx->key, ctx->split_key_len,
ctx->split_key_pad_len, key_in, keylen,
ctx->alg_op);
}
static int hash_digest_key(struct caam_hash_ctx *ctx, const u8 *key_in,
u32 *keylen, u8 *key_out, u32 digestsize)
{
struct device *jrdev = ctx->jrdev;
u32 *desc;
struct split_key_result result;
dma_addr_t src_dma, dst_dma;
int ret = 0;
desc = kmalloc(CAAM_CMD_SZ * 8 + CAAM_PTR_SZ * 2, GFP_KERNEL | GFP_DMA);
if (!desc) {
dev_err(jrdev, "unable to allocate key input memory\n");
return -ENOMEM;
}
init_job_desc(desc, 0);
src_dma = dma_map_single(jrdev, (void *)key_in, *keylen,
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, src_dma)) {
dev_err(jrdev, "unable to map key input memory\n");
kfree(desc);
return -ENOMEM;
}
dst_dma = dma_map_single(jrdev, (void *)key_out, digestsize,
DMA_FROM_DEVICE);
if (dma_mapping_error(jrdev, dst_dma)) {
dev_err(jrdev, "unable to map key output memory\n");
dma_unmap_single(jrdev, src_dma, *keylen, DMA_TO_DEVICE);
kfree(desc);
return -ENOMEM;
}
append_operation(desc, ctx->alg_type | OP_ALG_ENCRYPT |
OP_ALG_AS_INITFINAL);
append_seq_in_ptr(desc, src_dma, *keylen, 0);
append_seq_fifo_load(desc, *keylen, FIFOLD_CLASS_CLASS2 |
FIFOLD_TYPE_LAST2 | FIFOLD_TYPE_MSG);
append_seq_out_ptr(desc, dst_dma, digestsize, 0);
append_seq_store(desc, digestsize, LDST_CLASS_2_CCB |
LDST_SRCDST_BYTE_CONTEXT);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "key_in@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, key_in, *keylen, 1);
print_hex_dump(KERN_ERR, "jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
result.err = 0;
init_completion(&result.completion);
ret = caam_jr_enqueue(jrdev, desc, split_key_done, &result);
if (!ret) {
wait_for_completion_interruptible(&result.completion);
ret = result.err;
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"digested key@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, key_in,
digestsize, 1);
#endif
}
dma_unmap_single(jrdev, src_dma, *keylen, DMA_TO_DEVICE);
dma_unmap_single(jrdev, dst_dma, digestsize, DMA_FROM_DEVICE);
*keylen = digestsize;
kfree(desc);
return ret;
}
static int ahash_setkey(struct crypto_ahash *ahash,
const u8 *key, unsigned int keylen)
{
static const u8 mdpadlen[] = { 16, 20, 32, 32, 64, 64 };
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct device *jrdev = ctx->jrdev;
int blocksize = crypto_tfm_alg_blocksize(&ahash->base);
int digestsize = crypto_ahash_digestsize(ahash);
int ret = 0;
u8 *hashed_key = NULL;
#ifdef DEBUG
printk(KERN_ERR "keylen %d\n", keylen);
#endif
if (keylen > blocksize) {
hashed_key = kmalloc(sizeof(u8) * digestsize, GFP_KERNEL |
GFP_DMA);
if (!hashed_key)
return -ENOMEM;
ret = hash_digest_key(ctx, key, &keylen, hashed_key,
digestsize);
if (ret)
goto badkey;
key = hashed_key;
}
ctx->split_key_len = mdpadlen[(ctx->alg_op & OP_ALG_ALGSEL_SUBMASK) >>
OP_ALG_ALGSEL_SHIFT] * 2;
ctx->split_key_pad_len = ALIGN(ctx->split_key_len, 16);
#ifdef DEBUG
printk(KERN_ERR "split_key_len %d split_key_pad_len %d\n",
ctx->split_key_len, ctx->split_key_pad_len);
print_hex_dump(KERN_ERR, "key in @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, key, keylen, 1);
#endif
ret = gen_split_hash_key(ctx, key, keylen);
if (ret)
goto badkey;
ctx->key_dma = dma_map_single(jrdev, ctx->key, ctx->split_key_pad_len,
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->key_dma)) {
dev_err(jrdev, "unable to map key i/o memory\n");
ret = -ENOMEM;
goto map_err;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx.key@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, ctx->key,
ctx->split_key_pad_len, 1);
#endif
ret = ahash_set_sh_desc(ahash);
if (ret) {
dma_unmap_single(jrdev, ctx->key_dma, ctx->split_key_pad_len,
DMA_TO_DEVICE);
}
map_err:
kfree(hashed_key);
return ret;
badkey:
kfree(hashed_key);
crypto_ahash_set_flags(ahash, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static inline void ahash_unmap(struct device *dev,
struct ahash_edesc *edesc,
struct ahash_request *req, int dst_len)
{
if (edesc->src_nents)
dma_unmap_sg_chained(dev, req->src, edesc->src_nents,
DMA_TO_DEVICE, edesc->chained);
if (edesc->dst_dma)
dma_unmap_single(dev, edesc->dst_dma, dst_len, DMA_FROM_DEVICE);
if (edesc->sec4_sg_bytes)
dma_unmap_single(dev, edesc->sec4_sg_dma,
edesc->sec4_sg_bytes, DMA_TO_DEVICE);
}
static inline void ahash_unmap_ctx(struct device *dev,
struct ahash_edesc *edesc,
struct ahash_request *req, int dst_len, u32 flag)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
if (state->ctx_dma)
dma_unmap_single(dev, state->ctx_dma, ctx->ctx_len, flag);
ahash_unmap(dev, edesc, req, dst_len);
}
static void ahash_done(struct device *jrdev, u32 *desc, u32 err,
void *context)
{
struct ahash_request *req = context;
struct ahash_edesc *edesc;
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
int digestsize = crypto_ahash_digestsize(ahash);
#ifdef DEBUG
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
dev_err(jrdev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
edesc = (struct ahash_edesc *)((char *)desc -
offsetof(struct ahash_edesc, hw_desc));
if (err)
caam_jr_strstatus(jrdev, err);
ahash_unmap(jrdev, edesc, req, digestsize);
kfree(edesc);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, state->caam_ctx,
ctx->ctx_len, 1);
if (req->result)
print_hex_dump(KERN_ERR, "result@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, req->result,
digestsize, 1);
#endif
req->base.complete(&req->base, err);
}
static void ahash_done_bi(struct device *jrdev, u32 *desc, u32 err,
void *context)
{
struct ahash_request *req = context;
struct ahash_edesc *edesc;
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
#ifdef DEBUG
struct caam_hash_state *state = ahash_request_ctx(req);
int digestsize = crypto_ahash_digestsize(ahash);
dev_err(jrdev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
edesc = (struct ahash_edesc *)((char *)desc -
offsetof(struct ahash_edesc, hw_desc));
if (err)
caam_jr_strstatus(jrdev, err);
ahash_unmap_ctx(jrdev, edesc, req, ctx->ctx_len, DMA_BIDIRECTIONAL);
kfree(edesc);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, state->caam_ctx,
ctx->ctx_len, 1);
if (req->result)
print_hex_dump(KERN_ERR, "result@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, req->result,
digestsize, 1);
#endif
req->base.complete(&req->base, err);
}
static void ahash_done_ctx_src(struct device *jrdev, u32 *desc, u32 err,
void *context)
{
struct ahash_request *req = context;
struct ahash_edesc *edesc;
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
int digestsize = crypto_ahash_digestsize(ahash);
#ifdef DEBUG
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
dev_err(jrdev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
edesc = (struct ahash_edesc *)((char *)desc -
offsetof(struct ahash_edesc, hw_desc));
if (err)
caam_jr_strstatus(jrdev, err);
ahash_unmap_ctx(jrdev, edesc, req, digestsize, DMA_TO_DEVICE);
kfree(edesc);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, state->caam_ctx,
ctx->ctx_len, 1);
if (req->result)
print_hex_dump(KERN_ERR, "result@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, req->result,
digestsize, 1);
#endif
req->base.complete(&req->base, err);
}
static void ahash_done_ctx_dst(struct device *jrdev, u32 *desc, u32 err,
void *context)
{
struct ahash_request *req = context;
struct ahash_edesc *edesc;
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
#ifdef DEBUG
struct caam_hash_state *state = ahash_request_ctx(req);
int digestsize = crypto_ahash_digestsize(ahash);
dev_err(jrdev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
edesc = (struct ahash_edesc *)((char *)desc -
offsetof(struct ahash_edesc, hw_desc));
if (err)
caam_jr_strstatus(jrdev, err);
ahash_unmap_ctx(jrdev, edesc, req, ctx->ctx_len, DMA_FROM_DEVICE);
kfree(edesc);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, state->caam_ctx,
ctx->ctx_len, 1);
if (req->result)
print_hex_dump(KERN_ERR, "result@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, req->result,
digestsize, 1);
#endif
req->base.complete(&req->base, err);
}
static int ahash_update_ctx(struct ahash_request *req)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
u8 *buf = state->current_buf ? state->buf_1 : state->buf_0;
int *buflen = state->current_buf ? &state->buflen_1 : &state->buflen_0;
u8 *next_buf = state->current_buf ? state->buf_0 : state->buf_1;
int *next_buflen = state->current_buf ? &state->buflen_0 :
&state->buflen_1, last_buflen;
int in_len = *buflen + req->nbytes, to_hash;
u32 *sh_desc = ctx->sh_desc_update, *desc;
dma_addr_t ptr = ctx->sh_desc_update_dma;
int src_nents, sec4_sg_bytes, sec4_sg_src_index;
struct ahash_edesc *edesc;
bool chained = false;
int ret = 0;
int sh_len;
last_buflen = *next_buflen;
*next_buflen = in_len & (crypto_tfm_alg_blocksize(&ahash->base) - 1);
to_hash = in_len - *next_buflen;
if (to_hash) {
src_nents = __sg_count(req->src, req->nbytes - (*next_buflen),
&chained);
sec4_sg_src_index = 1 + (*buflen ? 1 : 0);
sec4_sg_bytes = (sec4_sg_src_index + src_nents) *
sizeof(struct sec4_sg_entry);
edesc = kmalloc(sizeof(struct ahash_edesc) + DESC_JOB_IO_LEN +
sec4_sg_bytes, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev,
"could not allocate extended descriptor\n");
return -ENOMEM;
}
edesc->src_nents = src_nents;
edesc->chained = chained;
edesc->sec4_sg_bytes = sec4_sg_bytes;
edesc->sec4_sg = (void *)edesc + sizeof(struct ahash_edesc) +
DESC_JOB_IO_LEN;
ret = ctx_map_to_sec4_sg(desc, jrdev, state, ctx->ctx_len,
edesc->sec4_sg, DMA_BIDIRECTIONAL);
if (ret)
return ret;
state->buf_dma = try_buf_map_to_sec4_sg(jrdev,
edesc->sec4_sg + 1,
buf, state->buf_dma,
*buflen, last_buflen);
if (src_nents) {
src_map_to_sec4_sg(jrdev, req->src, src_nents,
edesc->sec4_sg + sec4_sg_src_index,
chained);
if (*next_buflen)
scatterwalk_map_and_copy(next_buf, req->src,
to_hash - *buflen,
*next_buflen, 0);
} else {
(edesc->sec4_sg + sec4_sg_src_index - 1)->len |=
SEC4_SG_LEN_FIN;
}
state->current_buf = !state->current_buf;
sh_len = desc_len(sh_desc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ptr, sh_len, HDR_SHARE_DEFER |
HDR_REVERSE);
edesc->sec4_sg_dma = dma_map_single(jrdev, edesc->sec4_sg,
sec4_sg_bytes,
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, edesc->sec4_sg_dma)) {
dev_err(jrdev, "unable to map S/G table\n");
return -ENOMEM;
}
append_seq_in_ptr(desc, edesc->sec4_sg_dma, ctx->ctx_len +
to_hash, LDST_SGF);
append_seq_out_ptr(desc, state->ctx_dma, ctx->ctx_len, 0);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
ret = caam_jr_enqueue(jrdev, desc, ahash_done_bi, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
ahash_unmap_ctx(jrdev, edesc, req, ctx->ctx_len,
DMA_BIDIRECTIONAL);
kfree(edesc);
}
} else if (*next_buflen) {
scatterwalk_map_and_copy(buf + *buflen, req->src, 0,
req->nbytes, 0);
*buflen = *next_buflen;
*next_buflen = last_buflen;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "buf@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, buf, *buflen, 1);
print_hex_dump(KERN_ERR, "next buf@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, next_buf,
*next_buflen, 1);
#endif
return ret;
}
static int ahash_final_ctx(struct ahash_request *req)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
u8 *buf = state->current_buf ? state->buf_1 : state->buf_0;
int buflen = state->current_buf ? state->buflen_1 : state->buflen_0;
int last_buflen = state->current_buf ? state->buflen_0 :
state->buflen_1;
u32 *sh_desc = ctx->sh_desc_fin, *desc;
dma_addr_t ptr = ctx->sh_desc_fin_dma;
int sec4_sg_bytes, sec4_sg_src_index;
int digestsize = crypto_ahash_digestsize(ahash);
struct ahash_edesc *edesc;
int ret = 0;
int sh_len;
sec4_sg_src_index = 1 + (buflen ? 1 : 0);
sec4_sg_bytes = sec4_sg_src_index * sizeof(struct sec4_sg_entry);
edesc = kmalloc(sizeof(struct ahash_edesc) + DESC_JOB_IO_LEN +
sec4_sg_bytes, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev, "could not allocate extended descriptor\n");
return -ENOMEM;
}
sh_len = desc_len(sh_desc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ptr, sh_len, HDR_SHARE_DEFER | HDR_REVERSE);
edesc->sec4_sg_bytes = sec4_sg_bytes;
edesc->sec4_sg = (void *)edesc + sizeof(struct ahash_edesc) +
DESC_JOB_IO_LEN;
edesc->src_nents = 0;
ret = ctx_map_to_sec4_sg(desc, jrdev, state, ctx->ctx_len,
edesc->sec4_sg, DMA_TO_DEVICE);
if (ret)
return ret;
state->buf_dma = try_buf_map_to_sec4_sg(jrdev, edesc->sec4_sg + 1,
buf, state->buf_dma, buflen,
last_buflen);
(edesc->sec4_sg + sec4_sg_src_index - 1)->len |= SEC4_SG_LEN_FIN;
edesc->sec4_sg_dma = dma_map_single(jrdev, edesc->sec4_sg,
sec4_sg_bytes, DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, edesc->sec4_sg_dma)) {
dev_err(jrdev, "unable to map S/G table\n");
return -ENOMEM;
}
append_seq_in_ptr(desc, edesc->sec4_sg_dma, ctx->ctx_len + buflen,
LDST_SGF);
edesc->dst_dma = map_seq_out_ptr_result(desc, jrdev, req->result,
digestsize);
if (dma_mapping_error(jrdev, edesc->dst_dma)) {
dev_err(jrdev, "unable to map dst\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
ret = caam_jr_enqueue(jrdev, desc, ahash_done_ctx_src, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
ahash_unmap_ctx(jrdev, edesc, req, digestsize, DMA_FROM_DEVICE);
kfree(edesc);
}
return ret;
}
static int ahash_finup_ctx(struct ahash_request *req)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
u8 *buf = state->current_buf ? state->buf_1 : state->buf_0;
int buflen = state->current_buf ? state->buflen_1 : state->buflen_0;
int last_buflen = state->current_buf ? state->buflen_0 :
state->buflen_1;
u32 *sh_desc = ctx->sh_desc_finup, *desc;
dma_addr_t ptr = ctx->sh_desc_finup_dma;
int sec4_sg_bytes, sec4_sg_src_index;
int src_nents;
int digestsize = crypto_ahash_digestsize(ahash);
struct ahash_edesc *edesc;
bool chained = false;
int ret = 0;
int sh_len;
src_nents = __sg_count(req->src, req->nbytes, &chained);
sec4_sg_src_index = 1 + (buflen ? 1 : 0);
sec4_sg_bytes = (sec4_sg_src_index + src_nents) *
sizeof(struct sec4_sg_entry);
edesc = kmalloc(sizeof(struct ahash_edesc) + DESC_JOB_IO_LEN +
sec4_sg_bytes, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev, "could not allocate extended descriptor\n");
return -ENOMEM;
}
sh_len = desc_len(sh_desc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ptr, sh_len, HDR_SHARE_DEFER | HDR_REVERSE);
edesc->src_nents = src_nents;
edesc->chained = chained;
edesc->sec4_sg_bytes = sec4_sg_bytes;
edesc->sec4_sg = (void *)edesc + sizeof(struct ahash_edesc) +
DESC_JOB_IO_LEN;
ret = ctx_map_to_sec4_sg(desc, jrdev, state, ctx->ctx_len,
edesc->sec4_sg, DMA_TO_DEVICE);
if (ret)
return ret;
state->buf_dma = try_buf_map_to_sec4_sg(jrdev, edesc->sec4_sg + 1,
buf, state->buf_dma, buflen,
last_buflen);
src_map_to_sec4_sg(jrdev, req->src, src_nents, edesc->sec4_sg +
sec4_sg_src_index, chained);
edesc->sec4_sg_dma = dma_map_single(jrdev, edesc->sec4_sg,
sec4_sg_bytes, DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, edesc->sec4_sg_dma)) {
dev_err(jrdev, "unable to map S/G table\n");
return -ENOMEM;
}
append_seq_in_ptr(desc, edesc->sec4_sg_dma, ctx->ctx_len +
buflen + req->nbytes, LDST_SGF);
edesc->dst_dma = map_seq_out_ptr_result(desc, jrdev, req->result,
digestsize);
if (dma_mapping_error(jrdev, edesc->dst_dma)) {
dev_err(jrdev, "unable to map dst\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
ret = caam_jr_enqueue(jrdev, desc, ahash_done_ctx_src, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
ahash_unmap_ctx(jrdev, edesc, req, digestsize, DMA_FROM_DEVICE);
kfree(edesc);
}
return ret;
}
static int ahash_digest(struct ahash_request *req)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
u32 *sh_desc = ctx->sh_desc_digest, *desc;
dma_addr_t ptr = ctx->sh_desc_digest_dma;
int digestsize = crypto_ahash_digestsize(ahash);
int src_nents, sec4_sg_bytes;
dma_addr_t src_dma;
struct ahash_edesc *edesc;
bool chained = false;
int ret = 0;
u32 options;
int sh_len;
src_nents = sg_count(req->src, req->nbytes, &chained);
dma_map_sg_chained(jrdev, req->src, src_nents ? : 1, DMA_TO_DEVICE,
chained);
sec4_sg_bytes = src_nents * sizeof(struct sec4_sg_entry);
edesc = kmalloc(sizeof(struct ahash_edesc) + sec4_sg_bytes +
DESC_JOB_IO_LEN, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev, "could not allocate extended descriptor\n");
return -ENOMEM;
}
edesc->sec4_sg = (void *)edesc + sizeof(struct ahash_edesc) +
DESC_JOB_IO_LEN;
edesc->sec4_sg_bytes = sec4_sg_bytes;
edesc->src_nents = src_nents;
edesc->chained = chained;
sh_len = desc_len(sh_desc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ptr, sh_len, HDR_SHARE_DEFER | HDR_REVERSE);
if (src_nents) {
sg_to_sec4_sg_last(req->src, src_nents, edesc->sec4_sg, 0);
edesc->sec4_sg_dma = dma_map_single(jrdev, edesc->sec4_sg,
sec4_sg_bytes, DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, edesc->sec4_sg_dma)) {
dev_err(jrdev, "unable to map S/G table\n");
return -ENOMEM;
}
src_dma = edesc->sec4_sg_dma;
options = LDST_SGF;
} else {
src_dma = sg_dma_address(req->src);
options = 0;
}
append_seq_in_ptr(desc, src_dma, req->nbytes, options);
edesc->dst_dma = map_seq_out_ptr_result(desc, jrdev, req->result,
digestsize);
if (dma_mapping_error(jrdev, edesc->dst_dma)) {
dev_err(jrdev, "unable to map dst\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
ret = caam_jr_enqueue(jrdev, desc, ahash_done, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
ahash_unmap(jrdev, edesc, req, digestsize);
kfree(edesc);
}
return ret;
}
static int ahash_final_no_ctx(struct ahash_request *req)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
u8 *buf = state->current_buf ? state->buf_1 : state->buf_0;
int buflen = state->current_buf ? state->buflen_1 : state->buflen_0;
u32 *sh_desc = ctx->sh_desc_digest, *desc;
dma_addr_t ptr = ctx->sh_desc_digest_dma;
int digestsize = crypto_ahash_digestsize(ahash);
struct ahash_edesc *edesc;
int ret = 0;
int sh_len;
edesc = kmalloc(sizeof(struct ahash_edesc) + DESC_JOB_IO_LEN,
GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev, "could not allocate extended descriptor\n");
return -ENOMEM;
}
edesc->sec4_sg_bytes = 0;
sh_len = desc_len(sh_desc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ptr, sh_len, HDR_SHARE_DEFER | HDR_REVERSE);
state->buf_dma = dma_map_single(jrdev, buf, buflen, DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, state->buf_dma)) {
dev_err(jrdev, "unable to map src\n");
return -ENOMEM;
}
append_seq_in_ptr(desc, state->buf_dma, buflen, 0);
edesc->dst_dma = map_seq_out_ptr_result(desc, jrdev, req->result,
digestsize);
if (dma_mapping_error(jrdev, edesc->dst_dma)) {
dev_err(jrdev, "unable to map dst\n");
return -ENOMEM;
}
edesc->src_nents = 0;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
ret = caam_jr_enqueue(jrdev, desc, ahash_done, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
ahash_unmap(jrdev, edesc, req, digestsize);
kfree(edesc);
}
return ret;
}
static int ahash_update_no_ctx(struct ahash_request *req)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
u8 *buf = state->current_buf ? state->buf_1 : state->buf_0;
int *buflen = state->current_buf ? &state->buflen_1 : &state->buflen_0;
u8 *next_buf = state->current_buf ? state->buf_0 : state->buf_1;
int *next_buflen = state->current_buf ? &state->buflen_0 :
&state->buflen_1;
int in_len = *buflen + req->nbytes, to_hash;
int sec4_sg_bytes, src_nents;
struct ahash_edesc *edesc;
u32 *desc, *sh_desc = ctx->sh_desc_update_first;
dma_addr_t ptr = ctx->sh_desc_update_first_dma;
bool chained = false;
int ret = 0;
int sh_len;
*next_buflen = in_len & (crypto_tfm_alg_blocksize(&ahash->base) - 1);
to_hash = in_len - *next_buflen;
if (to_hash) {
src_nents = __sg_count(req->src, req->nbytes - (*next_buflen),
&chained);
sec4_sg_bytes = (1 + src_nents) *
sizeof(struct sec4_sg_entry);
edesc = kmalloc(sizeof(struct ahash_edesc) + DESC_JOB_IO_LEN +
sec4_sg_bytes, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev,
"could not allocate extended descriptor\n");
return -ENOMEM;
}
edesc->src_nents = src_nents;
edesc->chained = chained;
edesc->sec4_sg_bytes = sec4_sg_bytes;
edesc->sec4_sg = (void *)edesc + sizeof(struct ahash_edesc) +
DESC_JOB_IO_LEN;
edesc->dst_dma = 0;
state->buf_dma = buf_map_to_sec4_sg(jrdev, edesc->sec4_sg,
buf, *buflen);
src_map_to_sec4_sg(jrdev, req->src, src_nents,
edesc->sec4_sg + 1, chained);
if (*next_buflen) {
scatterwalk_map_and_copy(next_buf, req->src,
to_hash - *buflen,
*next_buflen, 0);
}
state->current_buf = !state->current_buf;
sh_len = desc_len(sh_desc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ptr, sh_len, HDR_SHARE_DEFER |
HDR_REVERSE);
edesc->sec4_sg_dma = dma_map_single(jrdev, edesc->sec4_sg,
sec4_sg_bytes,
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, edesc->sec4_sg_dma)) {
dev_err(jrdev, "unable to map S/G table\n");
return -ENOMEM;
}
append_seq_in_ptr(desc, edesc->sec4_sg_dma, to_hash, LDST_SGF);
ret = map_seq_out_ptr_ctx(desc, jrdev, state, ctx->ctx_len);
if (ret)
return ret;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
ret = caam_jr_enqueue(jrdev, desc, ahash_done_ctx_dst, req);
if (!ret) {
ret = -EINPROGRESS;
state->update = ahash_update_ctx;
state->finup = ahash_finup_ctx;
state->final = ahash_final_ctx;
} else {
ahash_unmap_ctx(jrdev, edesc, req, ctx->ctx_len,
DMA_TO_DEVICE);
kfree(edesc);
}
} else if (*next_buflen) {
scatterwalk_map_and_copy(buf + *buflen, req->src, 0,
req->nbytes, 0);
*buflen = *next_buflen;
*next_buflen = 0;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "buf@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, buf, *buflen, 1);
print_hex_dump(KERN_ERR, "next buf@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, next_buf,
*next_buflen, 1);
#endif
return ret;
}
static int ahash_finup_no_ctx(struct ahash_request *req)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
u8 *buf = state->current_buf ? state->buf_1 : state->buf_0;
int buflen = state->current_buf ? state->buflen_1 : state->buflen_0;
int last_buflen = state->current_buf ? state->buflen_0 :
state->buflen_1;
u32 *sh_desc = ctx->sh_desc_digest, *desc;
dma_addr_t ptr = ctx->sh_desc_digest_dma;
int sec4_sg_bytes, sec4_sg_src_index, src_nents;
int digestsize = crypto_ahash_digestsize(ahash);
struct ahash_edesc *edesc;
bool chained = false;
int sh_len;
int ret = 0;
src_nents = __sg_count(req->src, req->nbytes, &chained);
sec4_sg_src_index = 2;
sec4_sg_bytes = (sec4_sg_src_index + src_nents) *
sizeof(struct sec4_sg_entry);
edesc = kmalloc(sizeof(struct ahash_edesc) + DESC_JOB_IO_LEN +
sec4_sg_bytes, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev, "could not allocate extended descriptor\n");
return -ENOMEM;
}
sh_len = desc_len(sh_desc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ptr, sh_len, HDR_SHARE_DEFER | HDR_REVERSE);
edesc->src_nents = src_nents;
edesc->chained = chained;
edesc->sec4_sg_bytes = sec4_sg_bytes;
edesc->sec4_sg = (void *)edesc + sizeof(struct ahash_edesc) +
DESC_JOB_IO_LEN;
state->buf_dma = try_buf_map_to_sec4_sg(jrdev, edesc->sec4_sg, buf,
state->buf_dma, buflen,
last_buflen);
src_map_to_sec4_sg(jrdev, req->src, src_nents, edesc->sec4_sg + 1,
chained);
edesc->sec4_sg_dma = dma_map_single(jrdev, edesc->sec4_sg,
sec4_sg_bytes, DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, edesc->sec4_sg_dma)) {
dev_err(jrdev, "unable to map S/G table\n");
return -ENOMEM;
}
append_seq_in_ptr(desc, edesc->sec4_sg_dma, buflen +
req->nbytes, LDST_SGF);
edesc->dst_dma = map_seq_out_ptr_result(desc, jrdev, req->result,
digestsize);
if (dma_mapping_error(jrdev, edesc->dst_dma)) {
dev_err(jrdev, "unable to map dst\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
ret = caam_jr_enqueue(jrdev, desc, ahash_done, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
ahash_unmap(jrdev, edesc, req, digestsize);
kfree(edesc);
}
return ret;
}
static int ahash_update_first(struct ahash_request *req)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
u8 *next_buf = state->current_buf ? state->buf_1 : state->buf_0;
int *next_buflen = state->current_buf ?
&state->buflen_1 : &state->buflen_0;
int to_hash;
u32 *sh_desc = ctx->sh_desc_update_first, *desc;
dma_addr_t ptr = ctx->sh_desc_update_first_dma;
int sec4_sg_bytes, src_nents;
dma_addr_t src_dma;
u32 options;
struct ahash_edesc *edesc;
bool chained = false;
int ret = 0;
int sh_len;
*next_buflen = req->nbytes & (crypto_tfm_alg_blocksize(&ahash->base) -
1);
to_hash = req->nbytes - *next_buflen;
if (to_hash) {
src_nents = sg_count(req->src, req->nbytes - (*next_buflen),
&chained);
dma_map_sg_chained(jrdev, req->src, src_nents ? : 1,
DMA_TO_DEVICE, chained);
sec4_sg_bytes = src_nents * sizeof(struct sec4_sg_entry);
edesc = kmalloc(sizeof(struct ahash_edesc) + DESC_JOB_IO_LEN +
sec4_sg_bytes, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev,
"could not allocate extended descriptor\n");
return -ENOMEM;
}
edesc->src_nents = src_nents;
edesc->chained = chained;
edesc->sec4_sg_bytes = sec4_sg_bytes;
edesc->sec4_sg = (void *)edesc + sizeof(struct ahash_edesc) +
DESC_JOB_IO_LEN;
edesc->dst_dma = 0;
if (src_nents) {
sg_to_sec4_sg_last(req->src, src_nents,
edesc->sec4_sg, 0);
edesc->sec4_sg_dma = dma_map_single(jrdev,
edesc->sec4_sg,
sec4_sg_bytes,
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, edesc->sec4_sg_dma)) {
dev_err(jrdev, "unable to map S/G table\n");
return -ENOMEM;
}
src_dma = edesc->sec4_sg_dma;
options = LDST_SGF;
} else {
src_dma = sg_dma_address(req->src);
options = 0;
}
if (*next_buflen)
scatterwalk_map_and_copy(next_buf, req->src, to_hash,
*next_buflen, 0);
sh_len = desc_len(sh_desc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ptr, sh_len, HDR_SHARE_DEFER |
HDR_REVERSE);
append_seq_in_ptr(desc, src_dma, to_hash, options);
ret = map_seq_out_ptr_ctx(desc, jrdev, state, ctx->ctx_len);
if (ret)
return ret;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
ret = caam_jr_enqueue(jrdev, desc, ahash_done_ctx_dst,
req);
if (!ret) {
ret = -EINPROGRESS;
state->update = ahash_update_ctx;
state->finup = ahash_finup_ctx;
state->final = ahash_final_ctx;
} else {
ahash_unmap_ctx(jrdev, edesc, req, ctx->ctx_len,
DMA_TO_DEVICE);
kfree(edesc);
}
} else if (*next_buflen) {
state->update = ahash_update_no_ctx;
state->finup = ahash_finup_no_ctx;
state->final = ahash_final_no_ctx;
scatterwalk_map_and_copy(next_buf, req->src, 0,
req->nbytes, 0);
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "next buf@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, next_buf,
*next_buflen, 1);
#endif
return ret;
}
static int ahash_finup_first(struct ahash_request *req)
{
return ahash_digest(req);
}
static int ahash_init(struct ahash_request *req)
{
struct caam_hash_state *state = ahash_request_ctx(req);
state->update = ahash_update_first;
state->finup = ahash_finup_first;
state->final = ahash_final_no_ctx;
state->current_buf = 0;
state->buf_dma = 0;
state->buflen_0 = 0;
state->buflen_1 = 0;
return 0;
}
static int ahash_update(struct ahash_request *req)
{
struct caam_hash_state *state = ahash_request_ctx(req);
return state->update(req);
}
static int ahash_finup(struct ahash_request *req)
{
struct caam_hash_state *state = ahash_request_ctx(req);
return state->finup(req);
}
static int ahash_final(struct ahash_request *req)
{
struct caam_hash_state *state = ahash_request_ctx(req);
return state->final(req);
}
static int ahash_export(struct ahash_request *req, void *out)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
memcpy(out, ctx, sizeof(struct caam_hash_ctx));
memcpy(out + sizeof(struct caam_hash_ctx), state,
sizeof(struct caam_hash_state));
return 0;
}
static int ahash_import(struct ahash_request *req, const void *in)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct caam_hash_ctx *ctx = crypto_ahash_ctx(ahash);
struct caam_hash_state *state = ahash_request_ctx(req);
memcpy(ctx, in, sizeof(struct caam_hash_ctx));
memcpy(state, in + sizeof(struct caam_hash_ctx),
sizeof(struct caam_hash_state));
return 0;
}
static int caam_hash_cra_init(struct crypto_tfm *tfm)
{
struct crypto_ahash *ahash = __crypto_ahash_cast(tfm);
struct crypto_alg *base = tfm->__crt_alg;
struct hash_alg_common *halg =
container_of(base, struct hash_alg_common, base);
struct ahash_alg *alg =
container_of(halg, struct ahash_alg, halg);
struct caam_hash_alg *caam_hash =
container_of(alg, struct caam_hash_alg, ahash_alg);
struct caam_hash_ctx *ctx = crypto_tfm_ctx(tfm);
static const u8 runninglen[] = { HASH_MSG_LEN + MD5_DIGEST_SIZE,
HASH_MSG_LEN + SHA1_DIGEST_SIZE,
HASH_MSG_LEN + 32,
HASH_MSG_LEN + SHA256_DIGEST_SIZE,
HASH_MSG_LEN + 64,
HASH_MSG_LEN + SHA512_DIGEST_SIZE };
int ret = 0;
ctx->jrdev = caam_jr_alloc();
if (IS_ERR(ctx->jrdev)) {
pr_err("Job Ring Device allocation for transform failed\n");
return PTR_ERR(ctx->jrdev);
}
ctx->alg_type = OP_TYPE_CLASS2_ALG | caam_hash->alg_type;
ctx->alg_op = OP_TYPE_CLASS2_ALG | caam_hash->alg_op;
ctx->ctx_len = runninglen[(ctx->alg_op & OP_ALG_ALGSEL_SUBMASK) >>
OP_ALG_ALGSEL_SHIFT];
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct caam_hash_state));
ret = ahash_set_sh_desc(ahash);
return ret;
}
static void caam_hash_cra_exit(struct crypto_tfm *tfm)
{
struct caam_hash_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->sh_desc_update_dma &&
!dma_mapping_error(ctx->jrdev, ctx->sh_desc_update_dma))
dma_unmap_single(ctx->jrdev, ctx->sh_desc_update_dma,
desc_bytes(ctx->sh_desc_update),
DMA_TO_DEVICE);
if (ctx->sh_desc_update_first_dma &&
!dma_mapping_error(ctx->jrdev, ctx->sh_desc_update_first_dma))
dma_unmap_single(ctx->jrdev, ctx->sh_desc_update_first_dma,
desc_bytes(ctx->sh_desc_update_first),
DMA_TO_DEVICE);
if (ctx->sh_desc_fin_dma &&
!dma_mapping_error(ctx->jrdev, ctx->sh_desc_fin_dma))
dma_unmap_single(ctx->jrdev, ctx->sh_desc_fin_dma,
desc_bytes(ctx->sh_desc_fin), DMA_TO_DEVICE);
if (ctx->sh_desc_digest_dma &&
!dma_mapping_error(ctx->jrdev, ctx->sh_desc_digest_dma))
dma_unmap_single(ctx->jrdev, ctx->sh_desc_digest_dma,
desc_bytes(ctx->sh_desc_digest),
DMA_TO_DEVICE);
if (ctx->sh_desc_finup_dma &&
!dma_mapping_error(ctx->jrdev, ctx->sh_desc_finup_dma))
dma_unmap_single(ctx->jrdev, ctx->sh_desc_finup_dma,
desc_bytes(ctx->sh_desc_finup), DMA_TO_DEVICE);
caam_jr_free(ctx->jrdev);
}
static void __exit caam_algapi_hash_exit(void)
{
struct caam_hash_alg *t_alg, *n;
if (!hash_list.next)
return;
list_for_each_entry_safe(t_alg, n, &hash_list, entry) {
crypto_unregister_ahash(&t_alg->ahash_alg);
list_del(&t_alg->entry);
kfree(t_alg);
}
}
static struct caam_hash_alg *
caam_hash_alloc(struct caam_hash_template *template,
bool keyed)
{
struct caam_hash_alg *t_alg;
struct ahash_alg *halg;
struct crypto_alg *alg;
t_alg = kzalloc(sizeof(struct caam_hash_alg), GFP_KERNEL);
if (!t_alg) {
pr_err("failed to allocate t_alg\n");
return ERR_PTR(-ENOMEM);
}
t_alg->ahash_alg = template->template_ahash;
halg = &t_alg->ahash_alg;
alg = &halg->halg.base;
if (keyed) {
snprintf(alg->cra_name, CRYPTO_MAX_ALG_NAME, "%s",
template->hmac_name);
snprintf(alg->cra_driver_name, CRYPTO_MAX_ALG_NAME, "%s",
template->hmac_driver_name);
} else {
snprintf(alg->cra_name, CRYPTO_MAX_ALG_NAME, "%s",
template->name);
snprintf(alg->cra_driver_name, CRYPTO_MAX_ALG_NAME, "%s",
template->driver_name);
}
alg->cra_module = THIS_MODULE;
alg->cra_init = caam_hash_cra_init;
alg->cra_exit = caam_hash_cra_exit;
alg->cra_ctxsize = sizeof(struct caam_hash_ctx);
alg->cra_priority = CAAM_CRA_PRIORITY;
alg->cra_blocksize = template->blocksize;
alg->cra_alignmask = 0;
alg->cra_flags = CRYPTO_ALG_ASYNC | CRYPTO_ALG_TYPE_AHASH;
alg->cra_type = &crypto_ahash_type;
t_alg->alg_type = template->alg_type;
t_alg->alg_op = template->alg_op;
return t_alg;
}
static int __init caam_algapi_hash_init(void)
{
struct device_node *dev_node;
struct platform_device *pdev;
struct device *ctrldev;
void *priv;
int i = 0, err = 0;
dev_node = of_find_compatible_node(NULL, NULL, "fsl,sec-v4.0");
if (!dev_node) {
dev_node = of_find_compatible_node(NULL, NULL, "fsl,sec4.0");
if (!dev_node)
return -ENODEV;
}
pdev = of_find_device_by_node(dev_node);
if (!pdev) {
of_node_put(dev_node);
return -ENODEV;
}
ctrldev = &pdev->dev;
priv = dev_get_drvdata(ctrldev);
of_node_put(dev_node);
if (!priv)
return -ENODEV;
INIT_LIST_HEAD(&hash_list);
for (i = 0; i < ARRAY_SIZE(driver_hash); i++) {
struct caam_hash_alg *t_alg;
t_alg = caam_hash_alloc(&driver_hash[i], true);
if (IS_ERR(t_alg)) {
err = PTR_ERR(t_alg);
pr_warn("%s alg allocation failed\n",
driver_hash[i].driver_name);
continue;
}
err = crypto_register_ahash(&t_alg->ahash_alg);
if (err) {
pr_warn("%s alg registration failed\n",
t_alg->ahash_alg.halg.base.cra_driver_name);
kfree(t_alg);
} else
list_add_tail(&t_alg->entry, &hash_list);
t_alg = caam_hash_alloc(&driver_hash[i], false);
if (IS_ERR(t_alg)) {
err = PTR_ERR(t_alg);
pr_warn("%s alg allocation failed\n",
driver_hash[i].driver_name);
continue;
}
err = crypto_register_ahash(&t_alg->ahash_alg);
if (err) {
pr_warn("%s alg registration failed\n",
t_alg->ahash_alg.halg.base.cra_driver_name);
kfree(t_alg);
} else
list_add_tail(&t_alg->entry, &hash_list);
}
return err;
}
