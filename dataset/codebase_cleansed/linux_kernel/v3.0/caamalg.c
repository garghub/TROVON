static int aead_authenc_setauthsize(struct crypto_aead *authenc,
unsigned int authsize)
{
struct caam_ctx *ctx = crypto_aead_ctx(authenc);
ctx->authsize = authsize;
return 0;
}
static void split_key_done(struct device *dev, u32 *desc, u32 err,
void *context)
{
struct split_key_result *res = context;
#ifdef DEBUG
dev_err(dev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
if (err) {
char tmp[CAAM_ERROR_STR_MAX];
dev_err(dev, "%08x: %s\n", err, caam_jr_strstatus(tmp, err));
}
res->err = err;
complete(&res->completion);
}
static u32 gen_split_key(struct caam_ctx *ctx, const u8 *key_in, u32 authkeylen)
{
struct device *jrdev = ctx->jrdev;
u32 *desc;
struct split_key_result result;
dma_addr_t dma_addr_in, dma_addr_out;
int ret = 0;
desc = kmalloc(CAAM_CMD_SZ * 6 + CAAM_PTR_SZ * 2, GFP_KERNEL | GFP_DMA);
init_job_desc(desc, 0);
dma_addr_in = dma_map_single(jrdev, (void *)key_in, authkeylen,
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, dma_addr_in)) {
dev_err(jrdev, "unable to map key input memory\n");
kfree(desc);
return -ENOMEM;
}
append_key(desc, dma_addr_in, authkeylen, CLASS_2 |
KEY_DEST_CLASS_REG);
append_operation(desc, ctx->alg_op | OP_ALG_DECRYPT |
OP_ALG_AS_INIT);
append_fifo_load_as_imm(desc, NULL, 0, LDST_CLASS_2_CCB |
FIFOLD_TYPE_MSG | FIFOLD_TYPE_LAST2);
dma_addr_out = dma_map_single(jrdev, ctx->key, ctx->split_key_pad_len,
DMA_FROM_DEVICE);
if (dma_mapping_error(jrdev, dma_addr_out)) {
dev_err(jrdev, "unable to map key output memory\n");
kfree(desc);
return -ENOMEM;
}
append_fifo_store(desc, dma_addr_out, ctx->split_key_len,
LDST_CLASS_2_CCB | FIFOST_TYPE_SPLIT_KEK);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx.key@"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, key_in, authkeylen, 1);
print_hex_dump(KERN_ERR, "jobdesc@"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
result.err = 0;
init_completion(&result.completion);
ret = caam_jr_enqueue(jrdev, desc, split_key_done, &result);
if (!ret) {
wait_for_completion_interruptible(&result.completion);
ret = result.err;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx.key@"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, ctx->key,
ctx->split_key_pad_len, 1);
#endif
}
dma_unmap_single(jrdev, dma_addr_out, ctx->split_key_pad_len,
DMA_FROM_DEVICE);
dma_unmap_single(jrdev, dma_addr_in, authkeylen, DMA_TO_DEVICE);
kfree(desc);
return ret;
}
static int build_sh_desc_ipsec(struct caam_ctx *ctx)
{
struct device *jrdev = ctx->jrdev;
u32 *sh_desc;
u32 *jump_cmd;
bool keys_fit_inline = 0;
if ((DESC_AEAD_GIVENCRYPT_TEXT_LEN +
DESC_AEAD_SHARED_TEXT_LEN) * CAAM_CMD_SZ +
ctx->split_key_pad_len + ctx->enckeylen <= CAAM_DESC_BYTES_MAX)
keys_fit_inline = 1;
sh_desc = kmalloc(CAAM_CMD_SZ * DESC_AEAD_SHARED_TEXT_LEN +
(keys_fit_inline ?
ctx->split_key_pad_len + ctx->enckeylen :
CAAM_PTR_SZ * 2), GFP_DMA | GFP_KERNEL);
if (!sh_desc) {
dev_err(jrdev, "could not allocate shared descriptor\n");
return -ENOMEM;
}
init_sh_desc(sh_desc, HDR_SAVECTX | HDR_SHARE_SERIAL);
jump_cmd = append_jump(sh_desc, CLASS_BOTH | JUMP_TEST_ALL |
JUMP_COND_SHRD | JUMP_COND_SELF);
if (keys_fit_inline) {
append_key_as_imm(sh_desc, ctx->key, ctx->split_key_pad_len,
ctx->split_key_len,
CLASS_2 | KEY_DEST_MDHA_SPLIT | KEY_ENC);
append_key_as_imm(sh_desc, (void *)ctx->key +
ctx->split_key_pad_len, ctx->enckeylen,
ctx->enckeylen, CLASS_1 | KEY_DEST_CLASS_REG);
} else {
append_key(sh_desc, ctx->key_phys, ctx->split_key_len, CLASS_2 |
KEY_DEST_MDHA_SPLIT | KEY_ENC);
append_key(sh_desc, ctx->key_phys + ctx->split_key_pad_len,
ctx->enckeylen, CLASS_1 | KEY_DEST_CLASS_REG);
}
set_jump_tgt_here(sh_desc, jump_cmd);
ctx->shared_desc_phys = dma_map_single(jrdev, sh_desc,
desc_bytes(sh_desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->shared_desc_phys)) {
dev_err(jrdev, "unable to map shared descriptor\n");
kfree(sh_desc);
return -ENOMEM;
}
ctx->sh_desc = sh_desc;
return 0;
}
static int aead_authenc_setkey(struct crypto_aead *aead,
const u8 *key, unsigned int keylen)
{
static const u8 mdpadlen[] = { 16, 20, 32, 32, 64, 64 };
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
struct rtattr *rta = (void *)key;
struct crypto_authenc_key_param *param;
unsigned int authkeylen;
unsigned int enckeylen;
int ret = 0;
param = RTA_DATA(rta);
enckeylen = be32_to_cpu(param->enckeylen);
key += RTA_ALIGN(rta->rta_len);
keylen -= RTA_ALIGN(rta->rta_len);
if (keylen < enckeylen)
goto badkey;
authkeylen = keylen - enckeylen;
if (keylen > CAAM_MAX_KEY_SIZE)
goto badkey;
ctx->split_key_len = mdpadlen[(ctx->alg_op & OP_ALG_ALGSEL_SUBMASK) >>
OP_ALG_ALGSEL_SHIFT] * 2;
ctx->split_key_pad_len = ALIGN(ctx->split_key_len, 16);
#ifdef DEBUG
printk(KERN_ERR "keylen %d enckeylen %d authkeylen %d\n",
keylen, enckeylen, authkeylen);
printk(KERN_ERR "split_key_len %d split_key_pad_len %d\n",
ctx->split_key_len, ctx->split_key_pad_len);
print_hex_dump(KERN_ERR, "key in @"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, key, keylen, 1);
#endif
ctx->key = kmalloc(ctx->split_key_pad_len + enckeylen,
GFP_KERNEL | GFP_DMA);
if (!ctx->key) {
dev_err(jrdev, "could not allocate key output memory\n");
return -ENOMEM;
}
ret = gen_split_key(ctx, key, authkeylen);
if (ret) {
kfree(ctx->key);
goto badkey;
}
memcpy(ctx->key + ctx->split_key_pad_len, key + authkeylen, enckeylen);
ctx->key_phys = dma_map_single(jrdev, ctx->key, ctx->split_key_pad_len +
enckeylen, DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->key_phys)) {
dev_err(jrdev, "unable to map key i/o memory\n");
kfree(ctx->key);
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx.key@"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, ctx->key,
ctx->split_key_pad_len + enckeylen, 1);
#endif
ctx->enckeylen = enckeylen;
ret = build_sh_desc_ipsec(ctx);
if (ret) {
dma_unmap_single(jrdev, ctx->key_phys, ctx->split_key_pad_len +
enckeylen, DMA_TO_DEVICE);
kfree(ctx->key);
}
return ret;
badkey:
crypto_aead_set_flags(aead, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static void ipsec_esp_unmap(struct device *dev,
struct ipsec_esp_edesc *edesc,
struct aead_request *areq)
{
dma_unmap_sg(dev, areq->assoc, edesc->assoc_nents, DMA_TO_DEVICE);
if (unlikely(areq->dst != areq->src)) {
dma_unmap_sg(dev, areq->src, edesc->src_nents,
DMA_TO_DEVICE);
dma_unmap_sg(dev, areq->dst, edesc->dst_nents,
DMA_FROM_DEVICE);
} else {
dma_unmap_sg(dev, areq->src, edesc->src_nents,
DMA_BIDIRECTIONAL);
}
if (edesc->link_tbl_bytes)
dma_unmap_single(dev, edesc->link_tbl_dma,
edesc->link_tbl_bytes,
DMA_TO_DEVICE);
}
static void ipsec_esp_encrypt_done(struct device *jrdev, u32 *desc, u32 err,
void *context)
{
struct aead_request *areq = context;
struct ipsec_esp_edesc *edesc;
#ifdef DEBUG
struct crypto_aead *aead = crypto_aead_reqtfm(areq);
int ivsize = crypto_aead_ivsize(aead);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
dev_err(jrdev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
edesc = (struct ipsec_esp_edesc *)((char *)desc -
offsetof(struct ipsec_esp_edesc, hw_desc));
if (err) {
char tmp[CAAM_ERROR_STR_MAX];
dev_err(jrdev, "%08x: %s\n", err, caam_jr_strstatus(tmp, err));
}
ipsec_esp_unmap(jrdev, edesc, areq);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "assoc @"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(areq->assoc),
areq->assoclen , 1);
print_hex_dump(KERN_ERR, "dstiv @"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(areq->src) - ivsize,
edesc->src_nents ? 100 : ivsize, 1);
print_hex_dump(KERN_ERR, "dst @"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(areq->src),
edesc->src_nents ? 100 : areq->cryptlen +
ctx->authsize + 4, 1);
#endif
kfree(edesc);
aead_request_complete(areq, err);
}
static void ipsec_esp_decrypt_done(struct device *jrdev, u32 *desc, u32 err,
void *context)
{
struct aead_request *areq = context;
struct ipsec_esp_edesc *edesc;
#ifdef DEBUG
struct crypto_aead *aead = crypto_aead_reqtfm(areq);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
dev_err(jrdev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
edesc = (struct ipsec_esp_edesc *)((char *)desc -
offsetof(struct ipsec_esp_edesc, hw_desc));
if (err) {
char tmp[CAAM_ERROR_STR_MAX];
dev_err(jrdev, "%08x: %s\n", err, caam_jr_strstatus(tmp, err));
}
ipsec_esp_unmap(jrdev, edesc, areq);
if ((err & JRSTA_CCBERR_ERRID_MASK) == JRSTA_CCBERR_ERRID_ICVCHK)
err = -EBADMSG;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "iphdrout@"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4,
((char *)sg_virt(areq->assoc) - sizeof(struct iphdr)),
sizeof(struct iphdr) + areq->assoclen +
((areq->cryptlen > 1500) ? 1500 : areq->cryptlen) +
ctx->authsize + 36, 1);
if (!err && edesc->link_tbl_bytes) {
struct scatterlist *sg = sg_last(areq->src, edesc->src_nents);
print_hex_dump(KERN_ERR, "sglastout@"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(sg),
sg->length + ctx->authsize + 16, 1);
}
#endif
kfree(edesc);
aead_request_complete(areq, err);
}
static void sg_to_link_tbl(struct scatterlist *sg, int sg_count,
struct link_tbl_entry *link_tbl_ptr, u32 offset)
{
while (sg_count) {
link_tbl_ptr->ptr = sg_dma_address(sg);
link_tbl_ptr->len = sg_dma_len(sg);
link_tbl_ptr->reserved = 0;
link_tbl_ptr->buf_pool_id = 0;
link_tbl_ptr->offset = offset;
link_tbl_ptr++;
sg = sg_next(sg);
sg_count--;
}
link_tbl_ptr--;
link_tbl_ptr->len |= 0x40000000;
}
static int ipsec_esp(struct ipsec_esp_edesc *edesc, struct aead_request *areq,
u32 encrypt,
void (*callback) (struct device *dev, u32 *desc,
u32 err, void *context))
{
struct crypto_aead *aead = crypto_aead_reqtfm(areq);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
u32 *desc = edesc->hw_desc, options;
int ret, sg_count, assoc_sg_count;
int ivsize = crypto_aead_ivsize(aead);
int authsize = ctx->authsize;
dma_addr_t ptr, dst_dma, src_dma;
#ifdef DEBUG
u32 *sh_desc = ctx->sh_desc;
debug("assoclen %d cryptlen %d authsize %d\n",
areq->assoclen, areq->cryptlen, authsize);
print_hex_dump(KERN_ERR, "assoc @"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(areq->assoc),
areq->assoclen , 1);
print_hex_dump(KERN_ERR, "presciv@"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(areq->src) - ivsize,
edesc->src_nents ? 100 : ivsize, 1);
print_hex_dump(KERN_ERR, "src @"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(areq->src),
edesc->src_nents ? 100 : areq->cryptlen + authsize, 1);
print_hex_dump(KERN_ERR, "shrdesc@"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sh_desc,
desc_bytes(sh_desc), 1);
#endif
assoc_sg_count = dma_map_sg(jrdev, areq->assoc, edesc->assoc_nents ?: 1,
DMA_TO_DEVICE);
if (areq->src == areq->dst)
sg_count = dma_map_sg(jrdev, areq->src, edesc->src_nents ? : 1,
DMA_BIDIRECTIONAL);
else
sg_count = dma_map_sg(jrdev, areq->src, edesc->src_nents ? : 1,
DMA_TO_DEVICE);
append_operation(desc, ctx->class2_alg_type | OP_ALG_AS_INITFINAL |
(encrypt ? : OP_ALG_ICV_ON));
options = FIFOLD_CLASS_CLASS2 | FIFOLD_TYPE_MSG;
if (!edesc->assoc_nents) {
ptr = sg_dma_address(areq->assoc);
} else {
sg_to_link_tbl(areq->assoc, edesc->assoc_nents,
edesc->link_tbl, 0);
ptr = edesc->link_tbl_dma;
options |= LDST_SGF;
}
append_fifo_load(desc, ptr, areq->assoclen, options);
append_move(desc, MOVE_SRC_CLASS1CTX | MOVE_DEST_CLASS2INFIFO | ivsize);
if (!encrypt) {
u32 *jump_cmd, *uncond_jump_cmd;
jump_cmd = append_jump(desc, JUMP_TEST_ALL | JUMP_COND_SHRD);
append_operation(desc, ctx->class1_alg_type |
OP_ALG_AS_INITFINAL);
uncond_jump_cmd = append_jump(desc, 0);
set_jump_tgt_here(desc, jump_cmd);
append_operation(desc, ctx->class1_alg_type |
OP_ALG_AS_INITFINAL | OP_ALG_AAI_DK);
set_jump_tgt_here(desc, uncond_jump_cmd);
} else
append_operation(desc, ctx->class1_alg_type |
OP_ALG_AS_INITFINAL | encrypt);
options = 0;
if (!edesc->src_nents) {
src_dma = sg_dma_address(areq->src);
} else {
sg_to_link_tbl(areq->src, edesc->src_nents, edesc->link_tbl +
edesc->assoc_nents, 0);
src_dma = edesc->link_tbl_dma + edesc->assoc_nents *
sizeof(struct link_tbl_entry);
options |= LDST_SGF;
}
append_seq_in_ptr(desc, src_dma, areq->cryptlen + authsize, options);
append_seq_fifo_load(desc, areq->cryptlen, FIFOLD_CLASS_BOTH |
FIFOLD_TYPE_LASTBOTH |
(encrypt ? FIFOLD_TYPE_MSG1OUT2
: FIFOLD_TYPE_MSG));
if (areq->src == areq->dst) {
dst_dma = src_dma;
} else {
sg_count = dma_map_sg(jrdev, areq->dst, edesc->dst_nents ? : 1,
DMA_FROM_DEVICE);
if (!edesc->dst_nents) {
dst_dma = sg_dma_address(areq->dst);
options = 0;
} else {
sg_to_link_tbl(areq->dst, edesc->dst_nents,
edesc->link_tbl + edesc->assoc_nents +
edesc->src_nents, 0);
dst_dma = edesc->link_tbl_dma + (edesc->assoc_nents +
edesc->src_nents) *
sizeof(struct link_tbl_entry);
options = LDST_SGF;
}
}
append_seq_out_ptr(desc, dst_dma, areq->cryptlen + authsize, options);
append_seq_fifo_store(desc, areq->cryptlen, FIFOST_TYPE_MESSAGE_DATA);
if (encrypt)
append_seq_store(desc, authsize, LDST_CLASS_2_CCB |
LDST_SRCDST_BYTE_CONTEXT);
else
append_seq_fifo_load(desc, authsize, FIFOLD_CLASS_CLASS2 |
FIFOLD_TYPE_LAST2 | FIFOLD_TYPE_ICV);
#ifdef DEBUG
debug("job_desc_len %d\n", desc_len(desc));
print_hex_dump(KERN_ERR, "jobdesc@"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc) , 1);
print_hex_dump(KERN_ERR, "jdlinkt@"xstr(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, edesc->link_tbl,
edesc->link_tbl_bytes, 1);
#endif
ret = caam_jr_enqueue(jrdev, desc, callback, areq);
if (!ret)
ret = -EINPROGRESS;
else {
ipsec_esp_unmap(jrdev, edesc, areq);
kfree(edesc);
}
return ret;
}
static int sg_count(struct scatterlist *sg_list, int nbytes, int *chained)
{
struct scatterlist *sg = sg_list;
int sg_nents = 0;
*chained = 0;
while (nbytes > 0) {
sg_nents++;
nbytes -= sg->length;
if (!sg_is_last(sg) && (sg + 1)->length == 0)
*chained = 1;
sg = scatterwalk_sg_next(sg);
}
return sg_nents;
}
static struct ipsec_esp_edesc *ipsec_esp_edesc_alloc(struct aead_request *areq,
int desc_bytes)
{
struct crypto_aead *aead = crypto_aead_reqtfm(areq);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
gfp_t flags = areq->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP ? GFP_KERNEL :
GFP_ATOMIC;
int assoc_nents, src_nents, dst_nents = 0, chained, link_tbl_bytes;
struct ipsec_esp_edesc *edesc;
assoc_nents = sg_count(areq->assoc, areq->assoclen, &chained);
BUG_ON(chained);
if (likely(assoc_nents == 1))
assoc_nents = 0;
src_nents = sg_count(areq->src, areq->cryptlen + ctx->authsize,
&chained);
BUG_ON(chained);
if (src_nents == 1)
src_nents = 0;
if (unlikely(areq->dst != areq->src)) {
dst_nents = sg_count(areq->dst, areq->cryptlen + ctx->authsize,
&chained);
BUG_ON(chained);
if (dst_nents == 1)
dst_nents = 0;
}
link_tbl_bytes = (assoc_nents + src_nents + dst_nents) *
sizeof(struct link_tbl_entry);
debug("link_tbl_bytes %d\n", link_tbl_bytes);
edesc = kmalloc(sizeof(struct ipsec_esp_edesc) + desc_bytes +
link_tbl_bytes, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev, "could not allocate extended descriptor\n");
return ERR_PTR(-ENOMEM);
}
edesc->assoc_nents = assoc_nents;
edesc->src_nents = src_nents;
edesc->dst_nents = dst_nents;
edesc->link_tbl = (void *)edesc + sizeof(struct ipsec_esp_edesc) +
desc_bytes;
edesc->link_tbl_dma = dma_map_single(jrdev, edesc->link_tbl,
link_tbl_bytes, DMA_TO_DEVICE);
edesc->link_tbl_bytes = link_tbl_bytes;
return edesc;
}
static int aead_authenc_encrypt(struct aead_request *areq)
{
struct ipsec_esp_edesc *edesc;
struct crypto_aead *aead = crypto_aead_reqtfm(areq);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
int ivsize = crypto_aead_ivsize(aead);
u32 *desc;
dma_addr_t iv_dma;
edesc = ipsec_esp_edesc_alloc(areq, DESC_AEAD_ENCRYPT_TEXT_LEN *
CAAM_CMD_SZ);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ctx->shared_desc_phys,
desc_len(ctx->sh_desc), HDR_SHARE_DEFER);
iv_dma = dma_map_single(jrdev, areq->iv, ivsize, DMA_TO_DEVICE);
append_load(desc, iv_dma, ivsize,
LDST_CLASS_1_CCB | LDST_SRCDST_BYTE_CONTEXT);
return ipsec_esp(edesc, areq, OP_ALG_ENCRYPT, ipsec_esp_encrypt_done);
}
static int aead_authenc_decrypt(struct aead_request *req)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
int ivsize = crypto_aead_ivsize(aead);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
struct ipsec_esp_edesc *edesc;
u32 *desc;
dma_addr_t iv_dma;
req->cryptlen -= ctx->authsize;
edesc = ipsec_esp_edesc_alloc(req, DESC_AEAD_DECRYPT_TEXT_LEN *
CAAM_CMD_SZ);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ctx->shared_desc_phys,
desc_len(ctx->sh_desc), HDR_SHARE_DEFER);
iv_dma = dma_map_single(jrdev, req->iv, ivsize, DMA_TO_DEVICE);
append_load(desc, iv_dma, ivsize,
LDST_CLASS_1_CCB | LDST_SRCDST_BYTE_CONTEXT);
return ipsec_esp(edesc, req, !OP_ALG_ENCRYPT, ipsec_esp_decrypt_done);
}
static int aead_authenc_givencrypt(struct aead_givcrypt_request *req)
{
struct aead_request *areq = &req->areq;
struct ipsec_esp_edesc *edesc;
struct crypto_aead *aead = crypto_aead_reqtfm(areq);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
int ivsize = crypto_aead_ivsize(aead);
dma_addr_t iv_dma;
u32 *desc;
iv_dma = dma_map_single(jrdev, req->giv, ivsize, DMA_FROM_DEVICE);
debug("%s: giv %p\n", __func__, req->giv);
edesc = ipsec_esp_edesc_alloc(areq, DESC_AEAD_GIVENCRYPT_TEXT_LEN *
CAAM_CMD_SZ);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
desc = edesc->hw_desc;
init_job_desc_shared(desc, ctx->shared_desc_phys,
desc_len(ctx->sh_desc), HDR_SHARE_DEFER);
append_load_imm_u32(desc, NFIFOENTRY_DEST_DECO | NFIFOENTRY_LC1 |
NFIFOENTRY_STYPE_PAD | NFIFOENTRY_DTYPE_MSG |
NFIFOENTRY_PTYPE_RND | ivsize,
LDST_SRCDST_WORD_INFO_FIFO);
append_cmd(desc, CMD_LOAD | DISABLE_AUTO_INFO_FIFO);
append_move(desc, MOVE_SRC_INFIFO | MOVE_DEST_CLASS1CTX | ivsize);
append_cmd(desc, CMD_LOAD | ENABLE_AUTO_INFO_FIFO);
append_move(desc, MOVE_SRC_CLASS1CTX | MOVE_DEST_OUTFIFO | ivsize);
append_fifo_store(desc, iv_dma, ivsize, FIFOST_TYPE_MESSAGE_DATA);
return ipsec_esp(edesc, areq, OP_ALG_ENCRYPT, ipsec_esp_encrypt_done);
}
static int caam_cra_init(struct crypto_tfm *tfm)
{
struct crypto_alg *alg = tfm->__crt_alg;
struct caam_crypto_alg *caam_alg =
container_of(alg, struct caam_crypto_alg, crypto_alg);
struct caam_ctx *ctx = crypto_tfm_ctx(tfm);
struct caam_drv_private *priv = dev_get_drvdata(caam_alg->ctrldev);
int tgt_jr = atomic_inc_return(&priv->tfm_count);
ctx->jrdev = priv->algapi_jr[(tgt_jr / 2) % priv->num_jrs_for_algapi];
ctx->class1_alg_type = OP_TYPE_CLASS1_ALG | caam_alg->class1_alg_type;
ctx->class2_alg_type = OP_TYPE_CLASS2_ALG | caam_alg->class2_alg_type;
ctx->alg_op = OP_TYPE_CLASS2_ALG | caam_alg->alg_op;
return 0;
}
static void caam_cra_exit(struct crypto_tfm *tfm)
{
struct caam_ctx *ctx = crypto_tfm_ctx(tfm);
if (!dma_mapping_error(ctx->jrdev, ctx->shared_desc_phys))
dma_unmap_single(ctx->jrdev, ctx->shared_desc_phys,
desc_bytes(ctx->sh_desc), DMA_TO_DEVICE);
kfree(ctx->sh_desc);
if (!dma_mapping_error(ctx->jrdev, ctx->key_phys))
dma_unmap_single(ctx->jrdev, ctx->key_phys,
ctx->split_key_pad_len + ctx->enckeylen,
DMA_TO_DEVICE);
kfree(ctx->key);
}
static void __exit caam_algapi_exit(void)
{
struct device_node *dev_node;
struct platform_device *pdev;
struct device *ctrldev;
struct caam_drv_private *priv;
struct caam_crypto_alg *t_alg, *n;
int i, err;
dev_node = of_find_compatible_node(NULL, NULL, "fsl,sec-v4.0");
if (!dev_node)
return;
pdev = of_find_device_by_node(dev_node);
if (!pdev)
return;
ctrldev = &pdev->dev;
of_node_put(dev_node);
priv = dev_get_drvdata(ctrldev);
if (!priv->alg_list.next)
return;
list_for_each_entry_safe(t_alg, n, &priv->alg_list, entry) {
crypto_unregister_alg(&t_alg->crypto_alg);
list_del(&t_alg->entry);
kfree(t_alg);
}
for (i = 0; i < priv->total_jobrs; i++) {
err = caam_jr_deregister(priv->algapi_jr[i]);
if (err < 0)
break;
}
kfree(priv->algapi_jr);
}
static struct caam_crypto_alg *caam_alg_alloc(struct device *ctrldev,
struct caam_alg_template
*template)
{
struct caam_crypto_alg *t_alg;
struct crypto_alg *alg;
t_alg = kzalloc(sizeof(struct caam_crypto_alg), GFP_KERNEL);
if (!t_alg) {
dev_err(ctrldev, "failed to allocate t_alg\n");
return ERR_PTR(-ENOMEM);
}
alg = &t_alg->crypto_alg;
snprintf(alg->cra_name, CRYPTO_MAX_ALG_NAME, "%s", template->name);
snprintf(alg->cra_driver_name, CRYPTO_MAX_ALG_NAME, "%s",
template->driver_name);
alg->cra_module = THIS_MODULE;
alg->cra_init = caam_cra_init;
alg->cra_exit = caam_cra_exit;
alg->cra_priority = CAAM_CRA_PRIORITY;
alg->cra_flags = CRYPTO_ALG_TYPE_AEAD | CRYPTO_ALG_ASYNC;
alg->cra_blocksize = template->blocksize;
alg->cra_alignmask = 0;
alg->cra_type = &crypto_aead_type;
alg->cra_ctxsize = sizeof(struct caam_ctx);
alg->cra_u.aead = template->aead;
t_alg->class1_alg_type = template->class1_alg_type;
t_alg->class2_alg_type = template->class2_alg_type;
t_alg->alg_op = template->alg_op;
t_alg->ctrldev = ctrldev;
return t_alg;
}
static int __init caam_algapi_init(void)
{
struct device_node *dev_node;
struct platform_device *pdev;
struct device *ctrldev, **jrdev;
struct caam_drv_private *priv;
int i = 0, err = 0;
dev_node = of_find_compatible_node(NULL, NULL, "fsl,sec-v4.0");
if (!dev_node)
return -ENODEV;
pdev = of_find_device_by_node(dev_node);
if (!pdev)
return -ENODEV;
ctrldev = &pdev->dev;
priv = dev_get_drvdata(ctrldev);
of_node_put(dev_node);
INIT_LIST_HEAD(&priv->alg_list);
jrdev = kmalloc(sizeof(*jrdev) * priv->total_jobrs, GFP_KERNEL);
if (!jrdev)
return -ENOMEM;
for (i = 0; i < priv->total_jobrs; i++) {
err = caam_jr_register(ctrldev, &jrdev[i]);
if (err < 0)
break;
}
if (err < 0 && i == 0) {
dev_err(ctrldev, "algapi error in job ring registration: %d\n",
err);
kfree(jrdev);
return err;
}
priv->num_jrs_for_algapi = i;
priv->algapi_jr = jrdev;
atomic_set(&priv->tfm_count, -1);
for (i = 0; i < ARRAY_SIZE(driver_algs); i++) {
struct caam_crypto_alg *t_alg;
t_alg = caam_alg_alloc(ctrldev, &driver_algs[i]);
if (IS_ERR(t_alg)) {
err = PTR_ERR(t_alg);
dev_warn(ctrldev, "%s alg allocation failed\n",
driver_algs[i].driver_name);
continue;
}
err = crypto_register_alg(&t_alg->crypto_alg);
if (err) {
dev_warn(ctrldev, "%s alg registration failed\n",
t_alg->crypto_alg.cra_driver_name);
kfree(t_alg);
} else {
list_add_tail(&t_alg->entry, &priv->alg_list);
dev_info(ctrldev, "%s\n",
t_alg->crypto_alg.cra_driver_name);
}
}
return err;
}
