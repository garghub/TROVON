static inline void append_dec_op1(u32 *desc, u32 type)
{
u32 *jump_cmd, *uncond_jump_cmd;
jump_cmd = append_jump(desc, JUMP_TEST_ALL | JUMP_COND_SHRD);
append_operation(desc, type | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT);
uncond_jump_cmd = append_jump(desc, JUMP_TEST_ALL);
set_jump_tgt_here(desc, jump_cmd);
append_operation(desc, type | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT | OP_ALG_AAI_DK);
set_jump_tgt_here(desc, uncond_jump_cmd);
}
static inline void append_dec_shr_done(u32 *desc)
{
u32 *jump_cmd;
jump_cmd = append_jump(desc, JUMP_CLASS_CLASS1 | JUMP_TEST_ALL);
set_jump_tgt_here(desc, jump_cmd);
append_cmd(desc, SET_OK_NO_PROP_ERRORS | CMD_LOAD);
}
static inline void aead_append_src_dst(u32 *desc, u32 msg_type)
{
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_BOTH |
KEY_VLF | msg_type | FIFOLD_TYPE_LASTBOTH);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_MESSAGE_DATA | KEY_VLF);
}
static inline void aead_append_ld_iv(u32 *desc, int ivsize)
{
append_cmd(desc, CMD_SEQ_LOAD | LDST_SRCDST_BYTE_CONTEXT |
LDST_CLASS_1_CCB | ivsize);
append_move(desc, MOVE_SRC_CLASS1CTX | MOVE_DEST_CLASS2INFIFO | ivsize);
}
static inline void ablkcipher_append_src_dst(u32 *desc)
{
append_math_add(desc, VARSEQOUTLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_math_add(desc, VARSEQINLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 |
KEY_VLF | FIFOLD_TYPE_MSG | FIFOLD_TYPE_LAST1);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_MESSAGE_DATA | KEY_VLF);
}
static void append_key_aead(u32 *desc, struct caam_ctx *ctx,
int keys_fit_inline)
{
if (keys_fit_inline) {
append_key_as_imm(desc, ctx->key, ctx->split_key_pad_len,
ctx->split_key_len, CLASS_2 |
KEY_DEST_MDHA_SPLIT | KEY_ENC);
append_key_as_imm(desc, (void *)ctx->key +
ctx->split_key_pad_len, ctx->enckeylen,
ctx->enckeylen, CLASS_1 | KEY_DEST_CLASS_REG);
} else {
append_key(desc, ctx->key_dma, ctx->split_key_len, CLASS_2 |
KEY_DEST_MDHA_SPLIT | KEY_ENC);
append_key(desc, ctx->key_dma + ctx->split_key_pad_len,
ctx->enckeylen, CLASS_1 | KEY_DEST_CLASS_REG);
}
}
static void init_sh_desc_key_aead(u32 *desc, struct caam_ctx *ctx,
int keys_fit_inline)
{
u32 *key_jump_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
append_key_aead(desc, ctx, keys_fit_inline);
set_jump_tgt_here(desc, key_jump_cmd);
append_cmd(desc, SET_OK_NO_PROP_ERRORS | CMD_LOAD);
}
static int aead_set_sh_desc(struct crypto_aead *aead)
{
struct aead_tfm *tfm = &aead->base.crt_aead;
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
bool keys_fit_inline = false;
u32 *key_jump_cmd, *jump_cmd;
u32 geniv, moveiv;
u32 *desc;
if (!ctx->enckeylen || !ctx->authsize)
return 0;
if (DESC_AEAD_ENC_LEN + DESC_JOB_IO_LEN +
ctx->split_key_pad_len + ctx->enckeylen <=
CAAM_DESC_BYTES_MAX)
keys_fit_inline = true;
desc = ctx->sh_desc_enc;
init_sh_desc_key_aead(desc, ctx, keys_fit_inline);
append_operation(desc, ctx->class2_alg_type |
OP_ALG_AS_INITFINAL | OP_ALG_ENCRYPT);
append_math_sub_imm_u32(desc, REG3, SEQOUTLEN, IMM, ctx->authsize);
append_math_sub_imm_u32(desc, REG2, SEQINLEN, IMM, tfm->ivsize);
append_math_sub(desc, VARSEQINLEN, REG2, REG3, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS2 | FIFOLD_TYPE_MSG |
KEY_VLF);
aead_append_ld_iv(desc, tfm->ivsize);
append_operation(desc, ctx->class1_alg_type |
OP_ALG_AS_INITFINAL | OP_ALG_ENCRYPT);
append_math_add(desc, VARSEQINLEN, ZERO, REG3, CAAM_CMD_SZ);
append_math_add(desc, VARSEQOUTLEN, ZERO, REG3, CAAM_CMD_SZ);
aead_append_src_dst(desc, FIFOLD_TYPE_MSG1OUT2);
append_seq_store(desc, ctx->authsize, LDST_CLASS_2_CCB |
LDST_SRCDST_BYTE_CONTEXT);
ctx->sh_desc_enc_dma = dma_map_single(jrdev, desc,
desc_bytes(desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->sh_desc_enc_dma)) {
dev_err(jrdev, "unable to map shared descriptor\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "aead enc shdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
if (DESC_AEAD_DEC_LEN + DESC_JOB_IO_LEN +
ctx->split_key_pad_len + ctx->enckeylen <=
CAAM_DESC_BYTES_MAX)
keys_fit_inline = true;
desc = ctx->sh_desc_dec;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
append_key_aead(desc, ctx, keys_fit_inline);
jump_cmd = append_jump(desc, JUMP_TEST_ALL);
set_jump_tgt_here(desc, key_jump_cmd);
append_cmd(desc, SET_OK_NO_PROP_ERRORS | CMD_LOAD);
set_jump_tgt_here(desc, jump_cmd);
append_operation(desc, ctx->class2_alg_type |
OP_ALG_AS_INITFINAL | OP_ALG_DECRYPT | OP_ALG_ICV_ON);
append_math_sub_imm_u32(desc, REG3, SEQINLEN, IMM,
ctx->authsize + tfm->ivsize)
append_math_sub(desc, REG2, SEQOUTLEN, REG0, CAAM_CMD_SZ);
append_math_sub(desc, VARSEQINLEN, REG3, REG2, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS2 | FIFOLD_TYPE_MSG |
KEY_VLF);
aead_append_ld_iv(desc, tfm->ivsize);
append_dec_op1(desc, ctx->class1_alg_type);
append_math_add(desc, VARSEQINLEN, ZERO, REG2, CAAM_CMD_SZ);
append_math_add(desc, VARSEQOUTLEN, ZERO, REG2, CAAM_CMD_SZ);
aead_append_src_dst(desc, FIFOLD_TYPE_MSG);
append_seq_fifo_load(desc, ctx->authsize, FIFOLD_CLASS_CLASS2 |
FIFOLD_TYPE_LAST2 | FIFOLD_TYPE_ICV);
append_dec_shr_done(desc);
ctx->sh_desc_dec_dma = dma_map_single(jrdev, desc,
desc_bytes(desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->sh_desc_dec_dma)) {
dev_err(jrdev, "unable to map shared descriptor\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "aead dec shdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
if (DESC_AEAD_GIVENC_LEN + DESC_JOB_IO_LEN +
ctx->split_key_pad_len + ctx->enckeylen <=
CAAM_DESC_BYTES_MAX)
keys_fit_inline = true;
desc = ctx->sh_desc_givenc;
init_sh_desc_key_aead(desc, ctx, keys_fit_inline);
geniv = NFIFOENTRY_STYPE_PAD | NFIFOENTRY_DEST_DECO |
NFIFOENTRY_DTYPE_MSG | NFIFOENTRY_LC1 |
NFIFOENTRY_PTYPE_RND | (tfm->ivsize << NFIFOENTRY_DLEN_SHIFT);
append_load_imm_u32(desc, geniv, LDST_CLASS_IND_CCB |
LDST_SRCDST_WORD_INFO_FIFO | LDST_IMM);
append_cmd(desc, CMD_LOAD | DISABLE_AUTO_INFO_FIFO);
append_move(desc, MOVE_SRC_INFIFO |
MOVE_DEST_CLASS1CTX | (tfm->ivsize << MOVE_LEN_SHIFT));
append_cmd(desc, CMD_LOAD | ENABLE_AUTO_INFO_FIFO);
append_move(desc, MOVE_SRC_CLASS1CTX |
MOVE_DEST_OUTFIFO | (tfm->ivsize << MOVE_LEN_SHIFT));
append_operation(desc, ctx->class2_alg_type |
OP_ALG_AS_INITFINAL | OP_ALG_ENCRYPT);
append_math_sub_imm_u32(desc, REG3, SEQOUTLEN, IMM, ctx->authsize);
append_math_sub(desc, VARSEQINLEN, SEQINLEN, REG3, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS2 | FIFOLD_TYPE_MSG |
KEY_VLF);
moveiv = NFIFOENTRY_STYPE_OFIFO | NFIFOENTRY_DEST_CLASS2 |
NFIFOENTRY_DTYPE_MSG | (tfm->ivsize << NFIFOENTRY_DLEN_SHIFT);
append_load_imm_u32(desc, moveiv, LDST_CLASS_IND_CCB |
LDST_SRCDST_WORD_INFO_FIFO | LDST_IMM);
append_load_imm_u32(desc, tfm->ivsize, LDST_CLASS_2_CCB |
LDST_SRCDST_WORD_DATASZ_REG | LDST_IMM);
append_operation(desc, ctx->class1_alg_type |
OP_ALG_AS_INITFINAL | OP_ALG_ENCRYPT);
append_math_add(desc, VARSEQOUTLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_load(desc, tfm->ivsize,
FIFOLD_CLASS_SKIP);
append_math_add(desc, VARSEQINLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
aead_append_src_dst(desc, FIFOLD_TYPE_MSG1OUT2);
append_seq_store(desc, ctx->authsize, LDST_CLASS_2_CCB |
LDST_SRCDST_BYTE_CONTEXT);
ctx->sh_desc_givenc_dma = dma_map_single(jrdev, desc,
desc_bytes(desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->sh_desc_givenc_dma)) {
dev_err(jrdev, "unable to map shared descriptor\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "aead givenc shdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
return 0;
}
static int aead_setauthsize(struct crypto_aead *authenc,
unsigned int authsize)
{
struct caam_ctx *ctx = crypto_aead_ctx(authenc);
ctx->authsize = authsize;
aead_set_sh_desc(authenc);
return 0;
}
static u32 gen_split_aead_key(struct caam_ctx *ctx, const u8 *key_in,
u32 authkeylen)
{
return gen_split_key(ctx->jrdev, ctx->key, ctx->split_key_len,
ctx->split_key_pad_len, key_in, authkeylen,
ctx->alg_op);
}
static int aead_setkey(struct crypto_aead *aead,
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
print_hex_dump(KERN_ERR, "key in @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, key, keylen, 1);
#endif
ret = gen_split_aead_key(ctx, key, authkeylen);
if (ret) {
goto badkey;
}
memcpy(ctx->key + ctx->split_key_pad_len, key + authkeylen, enckeylen);
ctx->key_dma = dma_map_single(jrdev, ctx->key, ctx->split_key_pad_len +
enckeylen, DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->key_dma)) {
dev_err(jrdev, "unable to map key i/o memory\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx.key@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, ctx->key,
ctx->split_key_pad_len + enckeylen, 1);
#endif
ctx->enckeylen = enckeylen;
ret = aead_set_sh_desc(aead);
if (ret) {
dma_unmap_single(jrdev, ctx->key_dma, ctx->split_key_pad_len +
enckeylen, DMA_TO_DEVICE);
}
return ret;
badkey:
crypto_aead_set_flags(aead, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static int ablkcipher_setkey(struct crypto_ablkcipher *ablkcipher,
const u8 *key, unsigned int keylen)
{
struct caam_ctx *ctx = crypto_ablkcipher_ctx(ablkcipher);
struct ablkcipher_tfm *tfm = &ablkcipher->base.crt_ablkcipher;
struct device *jrdev = ctx->jrdev;
int ret = 0;
u32 *key_jump_cmd, *jump_cmd;
u32 *desc;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "key in @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, key, keylen, 1);
#endif
memcpy(ctx->key, key, keylen);
ctx->key_dma = dma_map_single(jrdev, ctx->key, keylen,
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->key_dma)) {
dev_err(jrdev, "unable to map key i/o memory\n");
return -ENOMEM;
}
ctx->enckeylen = keylen;
desc = ctx->sh_desc_enc;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
append_key_as_imm(desc, (void *)ctx->key, ctx->enckeylen,
ctx->enckeylen, CLASS_1 |
KEY_DEST_CLASS_REG);
set_jump_tgt_here(desc, key_jump_cmd);
append_cmd(desc, SET_OK_NO_PROP_ERRORS | CMD_LOAD);
append_cmd(desc, CMD_SEQ_LOAD | LDST_SRCDST_BYTE_CONTEXT |
LDST_CLASS_1_CCB | tfm->ivsize);
append_operation(desc, ctx->class1_alg_type |
OP_ALG_AS_INITFINAL | OP_ALG_ENCRYPT);
ablkcipher_append_src_dst(desc);
ctx->sh_desc_enc_dma = dma_map_single(jrdev, desc,
desc_bytes(desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->sh_desc_enc_dma)) {
dev_err(jrdev, "unable to map shared descriptor\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"ablkcipher enc shdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
desc = ctx->sh_desc_dec;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
append_key_as_imm(desc, (void *)ctx->key, ctx->enckeylen,
ctx->enckeylen, CLASS_1 |
KEY_DEST_CLASS_REG);
jump_cmd = append_jump(desc, JUMP_TEST_ALL);
set_jump_tgt_here(desc, key_jump_cmd);
append_cmd(desc, SET_OK_NO_PROP_ERRORS | CMD_LOAD);
set_jump_tgt_here(desc, jump_cmd);
append_cmd(desc, CMD_SEQ_LOAD | LDST_SRCDST_BYTE_CONTEXT |
LDST_CLASS_1_CCB | tfm->ivsize);
append_dec_op1(desc, ctx->class1_alg_type);
ablkcipher_append_src_dst(desc);
append_dec_shr_done(desc);
ctx->sh_desc_dec_dma = dma_map_single(jrdev, desc,
desc_bytes(desc),
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, ctx->sh_desc_enc_dma)) {
dev_err(jrdev, "unable to map shared descriptor\n");
return -ENOMEM;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"ablkcipher dec shdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc,
desc_bytes(desc), 1);
#endif
return ret;
}
static void caam_unmap(struct device *dev, struct scatterlist *src,
struct scatterlist *dst, int src_nents,
bool src_chained, int dst_nents, bool dst_chained,
dma_addr_t iv_dma, int ivsize, dma_addr_t sec4_sg_dma,
int sec4_sg_bytes)
{
if (dst != src) {
dma_unmap_sg_chained(dev, src, src_nents ? : 1, DMA_TO_DEVICE,
src_chained);
dma_unmap_sg_chained(dev, dst, dst_nents ? : 1, DMA_FROM_DEVICE,
dst_chained);
} else {
dma_unmap_sg_chained(dev, src, src_nents ? : 1,
DMA_BIDIRECTIONAL, src_chained);
}
if (iv_dma)
dma_unmap_single(dev, iv_dma, ivsize, DMA_TO_DEVICE);
if (sec4_sg_bytes)
dma_unmap_single(dev, sec4_sg_dma, sec4_sg_bytes,
DMA_TO_DEVICE);
}
static void aead_unmap(struct device *dev,
struct aead_edesc *edesc,
struct aead_request *req)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
int ivsize = crypto_aead_ivsize(aead);
dma_unmap_sg_chained(dev, req->assoc, edesc->assoc_nents,
DMA_TO_DEVICE, edesc->assoc_chained);
caam_unmap(dev, req->src, req->dst,
edesc->src_nents, edesc->src_chained, edesc->dst_nents,
edesc->dst_chained, edesc->iv_dma, ivsize,
edesc->sec4_sg_dma, edesc->sec4_sg_bytes);
}
static void ablkcipher_unmap(struct device *dev,
struct ablkcipher_edesc *edesc,
struct ablkcipher_request *req)
{
struct crypto_ablkcipher *ablkcipher = crypto_ablkcipher_reqtfm(req);
int ivsize = crypto_ablkcipher_ivsize(ablkcipher);
caam_unmap(dev, req->src, req->dst,
edesc->src_nents, edesc->src_chained, edesc->dst_nents,
edesc->dst_chained, edesc->iv_dma, ivsize,
edesc->sec4_sg_dma, edesc->sec4_sg_bytes);
}
static void aead_encrypt_done(struct device *jrdev, u32 *desc, u32 err,
void *context)
{
struct aead_request *req = context;
struct aead_edesc *edesc;
#ifdef DEBUG
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
int ivsize = crypto_aead_ivsize(aead);
dev_err(jrdev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
edesc = (struct aead_edesc *)((char *)desc -
offsetof(struct aead_edesc, hw_desc));
if (err) {
char tmp[CAAM_ERROR_STR_MAX];
dev_err(jrdev, "%08x: %s\n", err, caam_jr_strstatus(tmp, err));
}
aead_unmap(jrdev, edesc, req);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "assoc @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->assoc),
req->assoclen , 1);
print_hex_dump(KERN_ERR, "dstiv @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->src) - ivsize,
edesc->src_nents ? 100 : ivsize, 1);
print_hex_dump(KERN_ERR, "dst @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->src),
edesc->src_nents ? 100 : req->cryptlen +
ctx->authsize + 4, 1);
#endif
kfree(edesc);
aead_request_complete(req, err);
}
static void aead_decrypt_done(struct device *jrdev, u32 *desc, u32 err,
void *context)
{
struct aead_request *req = context;
struct aead_edesc *edesc;
#ifdef DEBUG
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
int ivsize = crypto_aead_ivsize(aead);
dev_err(jrdev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
edesc = (struct aead_edesc *)((char *)desc -
offsetof(struct aead_edesc, hw_desc));
#ifdef DEBUG
print_hex_dump(KERN_ERR, "dstiv @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, req->iv,
ivsize, 1);
print_hex_dump(KERN_ERR, "dst @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->dst),
req->cryptlen, 1);
#endif
if (err) {
char tmp[CAAM_ERROR_STR_MAX];
dev_err(jrdev, "%08x: %s\n", err, caam_jr_strstatus(tmp, err));
}
aead_unmap(jrdev, edesc, req);
if ((err & JRSTA_CCBERR_ERRID_MASK) == JRSTA_CCBERR_ERRID_ICVCHK)
err = -EBADMSG;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "iphdrout@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4,
((char *)sg_virt(req->assoc) - sizeof(struct iphdr)),
sizeof(struct iphdr) + req->assoclen +
((req->cryptlen > 1500) ? 1500 : req->cryptlen) +
ctx->authsize + 36, 1);
if (!err && edesc->sec4_sg_bytes) {
struct scatterlist *sg = sg_last(req->src, edesc->src_nents);
print_hex_dump(KERN_ERR, "sglastout@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(sg),
sg->length + ctx->authsize + 16, 1);
}
#endif
kfree(edesc);
aead_request_complete(req, err);
}
static void ablkcipher_encrypt_done(struct device *jrdev, u32 *desc, u32 err,
void *context)
{
struct ablkcipher_request *req = context;
struct ablkcipher_edesc *edesc;
#ifdef DEBUG
struct crypto_ablkcipher *ablkcipher = crypto_ablkcipher_reqtfm(req);
int ivsize = crypto_ablkcipher_ivsize(ablkcipher);
dev_err(jrdev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
edesc = (struct ablkcipher_edesc *)((char *)desc -
offsetof(struct ablkcipher_edesc, hw_desc));
if (err) {
char tmp[CAAM_ERROR_STR_MAX];
dev_err(jrdev, "%08x: %s\n", err, caam_jr_strstatus(tmp, err));
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "dstiv @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, req->info,
edesc->src_nents > 1 ? 100 : ivsize, 1);
print_hex_dump(KERN_ERR, "dst @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->src),
edesc->dst_nents > 1 ? 100 : req->nbytes, 1);
#endif
ablkcipher_unmap(jrdev, edesc, req);
kfree(edesc);
ablkcipher_request_complete(req, err);
}
static void ablkcipher_decrypt_done(struct device *jrdev, u32 *desc, u32 err,
void *context)
{
struct ablkcipher_request *req = context;
struct ablkcipher_edesc *edesc;
#ifdef DEBUG
struct crypto_ablkcipher *ablkcipher = crypto_ablkcipher_reqtfm(req);
int ivsize = crypto_ablkcipher_ivsize(ablkcipher);
dev_err(jrdev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
edesc = (struct ablkcipher_edesc *)((char *)desc -
offsetof(struct ablkcipher_edesc, hw_desc));
if (err) {
char tmp[CAAM_ERROR_STR_MAX];
dev_err(jrdev, "%08x: %s\n", err, caam_jr_strstatus(tmp, err));
}
#ifdef DEBUG
print_hex_dump(KERN_ERR, "dstiv @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, req->info,
ivsize, 1);
print_hex_dump(KERN_ERR, "dst @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->src),
edesc->dst_nents > 1 ? 100 : req->nbytes, 1);
#endif
ablkcipher_unmap(jrdev, edesc, req);
kfree(edesc);
ablkcipher_request_complete(req, err);
}
static void init_aead_job(u32 *sh_desc, dma_addr_t ptr,
struct aead_edesc *edesc,
struct aead_request *req,
bool all_contig, bool encrypt)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
int ivsize = crypto_aead_ivsize(aead);
int authsize = ctx->authsize;
u32 *desc = edesc->hw_desc;
u32 out_options = 0, in_options;
dma_addr_t dst_dma, src_dma;
int len, sec4_sg_index = 0;
#ifdef DEBUG
debug("assoclen %d cryptlen %d authsize %d\n",
req->assoclen, req->cryptlen, authsize);
print_hex_dump(KERN_ERR, "assoc @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->assoc),
req->assoclen , 1);
print_hex_dump(KERN_ERR, "presciv@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, req->iv,
edesc->src_nents ? 100 : ivsize, 1);
print_hex_dump(KERN_ERR, "src @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->src),
edesc->src_nents ? 100 : req->cryptlen, 1);
print_hex_dump(KERN_ERR, "shrdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sh_desc,
desc_bytes(sh_desc), 1);
#endif
len = desc_len(sh_desc);
init_job_desc_shared(desc, ptr, len, HDR_SHARE_DEFER | HDR_REVERSE);
if (all_contig) {
src_dma = sg_dma_address(req->assoc);
in_options = 0;
} else {
src_dma = edesc->sec4_sg_dma;
sec4_sg_index += (edesc->assoc_nents ? : 1) + 1 +
(edesc->src_nents ? : 1);
in_options = LDST_SGF;
}
if (encrypt)
append_seq_in_ptr(desc, src_dma, req->assoclen + ivsize +
req->cryptlen - authsize, in_options);
else
append_seq_in_ptr(desc, src_dma, req->assoclen + ivsize +
req->cryptlen, in_options);
if (likely(req->src == req->dst)) {
if (all_contig) {
dst_dma = sg_dma_address(req->src);
} else {
dst_dma = src_dma + sizeof(struct sec4_sg_entry) *
((edesc->assoc_nents ? : 1) + 1);
out_options = LDST_SGF;
}
} else {
if (!edesc->dst_nents) {
dst_dma = sg_dma_address(req->dst);
} else {
dst_dma = edesc->sec4_sg_dma +
sec4_sg_index *
sizeof(struct sec4_sg_entry);
out_options = LDST_SGF;
}
}
if (encrypt)
append_seq_out_ptr(desc, dst_dma, req->cryptlen, out_options);
else
append_seq_out_ptr(desc, dst_dma, req->cryptlen - authsize,
out_options);
}
static void init_aead_giv_job(u32 *sh_desc, dma_addr_t ptr,
struct aead_edesc *edesc,
struct aead_request *req,
int contig)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
int ivsize = crypto_aead_ivsize(aead);
int authsize = ctx->authsize;
u32 *desc = edesc->hw_desc;
u32 out_options = 0, in_options;
dma_addr_t dst_dma, src_dma;
int len, sec4_sg_index = 0;
#ifdef DEBUG
debug("assoclen %d cryptlen %d authsize %d\n",
req->assoclen, req->cryptlen, authsize);
print_hex_dump(KERN_ERR, "assoc @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->assoc),
req->assoclen , 1);
print_hex_dump(KERN_ERR, "presciv@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, req->iv, ivsize, 1);
print_hex_dump(KERN_ERR, "src @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->src),
edesc->src_nents > 1 ? 100 : req->cryptlen, 1);
print_hex_dump(KERN_ERR, "shrdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sh_desc,
desc_bytes(sh_desc), 1);
#endif
len = desc_len(sh_desc);
init_job_desc_shared(desc, ptr, len, HDR_SHARE_DEFER | HDR_REVERSE);
if (contig & GIV_SRC_CONTIG) {
src_dma = sg_dma_address(req->assoc);
in_options = 0;
} else {
src_dma = edesc->sec4_sg_dma;
sec4_sg_index += edesc->assoc_nents + 1 + edesc->src_nents;
in_options = LDST_SGF;
}
append_seq_in_ptr(desc, src_dma, req->assoclen + ivsize +
req->cryptlen - authsize, in_options);
if (contig & GIV_DST_CONTIG) {
dst_dma = edesc->iv_dma;
} else {
if (likely(req->src == req->dst)) {
dst_dma = src_dma + sizeof(struct sec4_sg_entry) *
edesc->assoc_nents;
out_options = LDST_SGF;
} else {
dst_dma = edesc->sec4_sg_dma +
sec4_sg_index *
sizeof(struct sec4_sg_entry);
out_options = LDST_SGF;
}
}
append_seq_out_ptr(desc, dst_dma, ivsize + req->cryptlen, out_options);
}
static void init_ablkcipher_job(u32 *sh_desc, dma_addr_t ptr,
struct ablkcipher_edesc *edesc,
struct ablkcipher_request *req,
bool iv_contig)
{
struct crypto_ablkcipher *ablkcipher = crypto_ablkcipher_reqtfm(req);
int ivsize = crypto_ablkcipher_ivsize(ablkcipher);
u32 *desc = edesc->hw_desc;
u32 out_options = 0, in_options;
dma_addr_t dst_dma, src_dma;
int len, sec4_sg_index = 0;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "presciv@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, req->info,
ivsize, 1);
print_hex_dump(KERN_ERR, "src @"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->src),
edesc->src_nents ? 100 : req->nbytes, 1);
#endif
len = desc_len(sh_desc);
init_job_desc_shared(desc, ptr, len, HDR_SHARE_DEFER | HDR_REVERSE);
if (iv_contig) {
src_dma = edesc->iv_dma;
in_options = 0;
} else {
src_dma = edesc->sec4_sg_dma;
sec4_sg_index += (iv_contig ? 0 : 1) + edesc->src_nents;
in_options = LDST_SGF;
}
append_seq_in_ptr(desc, src_dma, req->nbytes + ivsize, in_options);
if (likely(req->src == req->dst)) {
if (!edesc->src_nents && iv_contig) {
dst_dma = sg_dma_address(req->src);
} else {
dst_dma = edesc->sec4_sg_dma +
sizeof(struct sec4_sg_entry);
out_options = LDST_SGF;
}
} else {
if (!edesc->dst_nents) {
dst_dma = sg_dma_address(req->dst);
} else {
dst_dma = edesc->sec4_sg_dma +
sec4_sg_index * sizeof(struct sec4_sg_entry);
out_options = LDST_SGF;
}
}
append_seq_out_ptr(desc, dst_dma, req->nbytes, out_options);
}
static struct aead_edesc *aead_edesc_alloc(struct aead_request *req,
int desc_bytes, bool *all_contig_ptr)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
int assoc_nents, src_nents, dst_nents = 0;
struct aead_edesc *edesc;
dma_addr_t iv_dma = 0;
int sgc;
bool all_contig = true;
bool assoc_chained = false, src_chained = false, dst_chained = false;
int ivsize = crypto_aead_ivsize(aead);
int sec4_sg_index, sec4_sg_len = 0, sec4_sg_bytes;
assoc_nents = sg_count(req->assoc, req->assoclen, &assoc_chained);
src_nents = sg_count(req->src, req->cryptlen, &src_chained);
if (unlikely(req->dst != req->src))
dst_nents = sg_count(req->dst, req->cryptlen, &dst_chained);
sgc = dma_map_sg_chained(jrdev, req->assoc, assoc_nents ? : 1,
DMA_TO_DEVICE, assoc_chained);
if (likely(req->src == req->dst)) {
sgc = dma_map_sg_chained(jrdev, req->src, src_nents ? : 1,
DMA_BIDIRECTIONAL, src_chained);
} else {
sgc = dma_map_sg_chained(jrdev, req->src, src_nents ? : 1,
DMA_TO_DEVICE, src_chained);
sgc = dma_map_sg_chained(jrdev, req->dst, dst_nents ? : 1,
DMA_FROM_DEVICE, dst_chained);
}
iv_dma = dma_map_single(jrdev, req->iv, ivsize, DMA_TO_DEVICE);
if (assoc_nents || sg_dma_address(req->assoc) + req->assoclen !=
iv_dma || src_nents || iv_dma + ivsize !=
sg_dma_address(req->src)) {
all_contig = false;
assoc_nents = assoc_nents ? : 1;
src_nents = src_nents ? : 1;
sec4_sg_len = assoc_nents + 1 + src_nents;
}
sec4_sg_len += dst_nents;
sec4_sg_bytes = sec4_sg_len * sizeof(struct sec4_sg_entry);
edesc = kmalloc(sizeof(struct aead_edesc) + desc_bytes +
sec4_sg_bytes, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev, "could not allocate extended descriptor\n");
return ERR_PTR(-ENOMEM);
}
edesc->assoc_nents = assoc_nents;
edesc->assoc_chained = assoc_chained;
edesc->src_nents = src_nents;
edesc->src_chained = src_chained;
edesc->dst_nents = dst_nents;
edesc->dst_chained = dst_chained;
edesc->iv_dma = iv_dma;
edesc->sec4_sg_bytes = sec4_sg_bytes;
edesc->sec4_sg = (void *)edesc + sizeof(struct aead_edesc) +
desc_bytes;
edesc->sec4_sg_dma = dma_map_single(jrdev, edesc->sec4_sg,
sec4_sg_bytes, DMA_TO_DEVICE);
*all_contig_ptr = all_contig;
sec4_sg_index = 0;
if (!all_contig) {
sg_to_sec4_sg(req->assoc,
(assoc_nents ? : 1),
edesc->sec4_sg +
sec4_sg_index, 0);
sec4_sg_index += assoc_nents ? : 1;
dma_to_sec4_sg_one(edesc->sec4_sg + sec4_sg_index,
iv_dma, ivsize, 0);
sec4_sg_index += 1;
sg_to_sec4_sg_last(req->src,
(src_nents ? : 1),
edesc->sec4_sg +
sec4_sg_index, 0);
sec4_sg_index += src_nents ? : 1;
}
if (dst_nents) {
sg_to_sec4_sg_last(req->dst, dst_nents,
edesc->sec4_sg + sec4_sg_index, 0);
}
return edesc;
}
static int aead_encrypt(struct aead_request *req)
{
struct aead_edesc *edesc;
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
bool all_contig;
u32 *desc;
int ret = 0;
req->cryptlen += ctx->authsize;
edesc = aead_edesc_alloc(req, DESC_JOB_IO_LEN *
CAAM_CMD_SZ, &all_contig);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
init_aead_job(ctx->sh_desc_enc, ctx->sh_desc_enc_dma, edesc, req,
all_contig, true);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "aead jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, edesc->hw_desc,
desc_bytes(edesc->hw_desc), 1);
#endif
desc = edesc->hw_desc;
ret = caam_jr_enqueue(jrdev, desc, aead_encrypt_done, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
aead_unmap(jrdev, edesc, req);
kfree(edesc);
}
return ret;
}
static int aead_decrypt(struct aead_request *req)
{
struct aead_edesc *edesc;
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
bool all_contig;
u32 *desc;
int ret = 0;
edesc = aead_edesc_alloc(req, DESC_JOB_IO_LEN *
CAAM_CMD_SZ, &all_contig);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "dec src@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->src),
req->cryptlen, 1);
#endif
init_aead_job(ctx->sh_desc_dec,
ctx->sh_desc_dec_dma, edesc, req, all_contig, false);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "aead jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, edesc->hw_desc,
desc_bytes(edesc->hw_desc), 1);
#endif
desc = edesc->hw_desc;
ret = caam_jr_enqueue(jrdev, desc, aead_decrypt_done, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
aead_unmap(jrdev, edesc, req);
kfree(edesc);
}
return ret;
}
static struct aead_edesc *aead_giv_edesc_alloc(struct aead_givcrypt_request
*greq, int desc_bytes,
u32 *contig_ptr)
{
struct aead_request *req = &greq->areq;
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
int assoc_nents, src_nents, dst_nents = 0;
struct aead_edesc *edesc;
dma_addr_t iv_dma = 0;
int sgc;
u32 contig = GIV_SRC_CONTIG | GIV_DST_CONTIG;
int ivsize = crypto_aead_ivsize(aead);
bool assoc_chained = false, src_chained = false, dst_chained = false;
int sec4_sg_index, sec4_sg_len = 0, sec4_sg_bytes;
assoc_nents = sg_count(req->assoc, req->assoclen, &assoc_chained);
src_nents = sg_count(req->src, req->cryptlen, &src_chained);
if (unlikely(req->dst != req->src))
dst_nents = sg_count(req->dst, req->cryptlen, &dst_chained);
sgc = dma_map_sg_chained(jrdev, req->assoc, assoc_nents ? : 1,
DMA_TO_DEVICE, assoc_chained);
if (likely(req->src == req->dst)) {
sgc = dma_map_sg_chained(jrdev, req->src, src_nents ? : 1,
DMA_BIDIRECTIONAL, src_chained);
} else {
sgc = dma_map_sg_chained(jrdev, req->src, src_nents ? : 1,
DMA_TO_DEVICE, src_chained);
sgc = dma_map_sg_chained(jrdev, req->dst, dst_nents ? : 1,
DMA_FROM_DEVICE, dst_chained);
}
iv_dma = dma_map_single(jrdev, greq->giv, ivsize, DMA_TO_DEVICE);
if (assoc_nents || sg_dma_address(req->assoc) + req->assoclen !=
iv_dma || src_nents || iv_dma + ivsize != sg_dma_address(req->src))
contig &= ~GIV_SRC_CONTIG;
if (dst_nents || iv_dma + ivsize != sg_dma_address(req->dst))
contig &= ~GIV_DST_CONTIG;
if (unlikely(req->src != req->dst)) {
dst_nents = dst_nents ? : 1;
sec4_sg_len += 1;
}
if (!(contig & GIV_SRC_CONTIG)) {
assoc_nents = assoc_nents ? : 1;
src_nents = src_nents ? : 1;
sec4_sg_len += assoc_nents + 1 + src_nents;
if (likely(req->src == req->dst))
contig &= ~GIV_DST_CONTIG;
}
sec4_sg_len += dst_nents;
sec4_sg_bytes = sec4_sg_len * sizeof(struct sec4_sg_entry);
edesc = kmalloc(sizeof(struct aead_edesc) + desc_bytes +
sec4_sg_bytes, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev, "could not allocate extended descriptor\n");
return ERR_PTR(-ENOMEM);
}
edesc->assoc_nents = assoc_nents;
edesc->assoc_chained = assoc_chained;
edesc->src_nents = src_nents;
edesc->src_chained = src_chained;
edesc->dst_nents = dst_nents;
edesc->dst_chained = dst_chained;
edesc->iv_dma = iv_dma;
edesc->sec4_sg_bytes = sec4_sg_bytes;
edesc->sec4_sg = (void *)edesc + sizeof(struct aead_edesc) +
desc_bytes;
edesc->sec4_sg_dma = dma_map_single(jrdev, edesc->sec4_sg,
sec4_sg_bytes, DMA_TO_DEVICE);
*contig_ptr = contig;
sec4_sg_index = 0;
if (!(contig & GIV_SRC_CONTIG)) {
sg_to_sec4_sg(req->assoc, assoc_nents,
edesc->sec4_sg +
sec4_sg_index, 0);
sec4_sg_index += assoc_nents;
dma_to_sec4_sg_one(edesc->sec4_sg + sec4_sg_index,
iv_dma, ivsize, 0);
sec4_sg_index += 1;
sg_to_sec4_sg_last(req->src, src_nents,
edesc->sec4_sg +
sec4_sg_index, 0);
sec4_sg_index += src_nents;
}
if (unlikely(req->src != req->dst && !(contig & GIV_DST_CONTIG))) {
dma_to_sec4_sg_one(edesc->sec4_sg + sec4_sg_index,
iv_dma, ivsize, 0);
sec4_sg_index += 1;
sg_to_sec4_sg_last(req->dst, dst_nents,
edesc->sec4_sg + sec4_sg_index, 0);
}
return edesc;
}
static int aead_givencrypt(struct aead_givcrypt_request *areq)
{
struct aead_request *req = &areq->areq;
struct aead_edesc *edesc;
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct caam_ctx *ctx = crypto_aead_ctx(aead);
struct device *jrdev = ctx->jrdev;
u32 contig;
u32 *desc;
int ret = 0;
req->cryptlen += ctx->authsize;
edesc = aead_giv_edesc_alloc(areq, DESC_JOB_IO_LEN *
CAAM_CMD_SZ, &contig);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "giv src@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, sg_virt(req->src),
req->cryptlen, 1);
#endif
init_aead_giv_job(ctx->sh_desc_givenc,
ctx->sh_desc_givenc_dma, edesc, req, contig);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "aead jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, edesc->hw_desc,
desc_bytes(edesc->hw_desc), 1);
#endif
desc = edesc->hw_desc;
ret = caam_jr_enqueue(jrdev, desc, aead_encrypt_done, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
aead_unmap(jrdev, edesc, req);
kfree(edesc);
}
return ret;
}
static struct ablkcipher_edesc *ablkcipher_edesc_alloc(struct ablkcipher_request
*req, int desc_bytes,
bool *iv_contig_out)
{
struct crypto_ablkcipher *ablkcipher = crypto_ablkcipher_reqtfm(req);
struct caam_ctx *ctx = crypto_ablkcipher_ctx(ablkcipher);
struct device *jrdev = ctx->jrdev;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ?
GFP_KERNEL : GFP_ATOMIC;
int src_nents, dst_nents = 0, sec4_sg_bytes;
struct ablkcipher_edesc *edesc;
dma_addr_t iv_dma = 0;
bool iv_contig = false;
int sgc;
int ivsize = crypto_ablkcipher_ivsize(ablkcipher);
bool src_chained = false, dst_chained = false;
int sec4_sg_index;
src_nents = sg_count(req->src, req->nbytes, &src_chained);
if (req->dst != req->src)
dst_nents = sg_count(req->dst, req->nbytes, &dst_chained);
if (likely(req->src == req->dst)) {
sgc = dma_map_sg_chained(jrdev, req->src, src_nents ? : 1,
DMA_BIDIRECTIONAL, src_chained);
} else {
sgc = dma_map_sg_chained(jrdev, req->src, src_nents ? : 1,
DMA_TO_DEVICE, src_chained);
sgc = dma_map_sg_chained(jrdev, req->dst, dst_nents ? : 1,
DMA_FROM_DEVICE, dst_chained);
}
iv_dma = dma_map_single(jrdev, req->info, ivsize, DMA_TO_DEVICE);
if (!src_nents && iv_dma + ivsize == sg_dma_address(req->src))
iv_contig = true;
else
src_nents = src_nents ? : 1;
sec4_sg_bytes = ((iv_contig ? 0 : 1) + src_nents + dst_nents) *
sizeof(struct sec4_sg_entry);
edesc = kmalloc(sizeof(struct ablkcipher_edesc) + desc_bytes +
sec4_sg_bytes, GFP_DMA | flags);
if (!edesc) {
dev_err(jrdev, "could not allocate extended descriptor\n");
return ERR_PTR(-ENOMEM);
}
edesc->src_nents = src_nents;
edesc->src_chained = src_chained;
edesc->dst_nents = dst_nents;
edesc->dst_chained = dst_chained;
edesc->sec4_sg_bytes = sec4_sg_bytes;
edesc->sec4_sg = (void *)edesc + sizeof(struct ablkcipher_edesc) +
desc_bytes;
sec4_sg_index = 0;
if (!iv_contig) {
dma_to_sec4_sg_one(edesc->sec4_sg, iv_dma, ivsize, 0);
sg_to_sec4_sg_last(req->src, src_nents,
edesc->sec4_sg + 1, 0);
sec4_sg_index += 1 + src_nents;
}
if (dst_nents) {
sg_to_sec4_sg_last(req->dst, dst_nents,
edesc->sec4_sg + sec4_sg_index, 0);
}
edesc->sec4_sg_dma = dma_map_single(jrdev, edesc->sec4_sg,
sec4_sg_bytes, DMA_TO_DEVICE);
edesc->iv_dma = iv_dma;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ablkcipher sec4_sg@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, edesc->sec4_sg,
sec4_sg_bytes, 1);
#endif
*iv_contig_out = iv_contig;
return edesc;
}
static int ablkcipher_encrypt(struct ablkcipher_request *req)
{
struct ablkcipher_edesc *edesc;
struct crypto_ablkcipher *ablkcipher = crypto_ablkcipher_reqtfm(req);
struct caam_ctx *ctx = crypto_ablkcipher_ctx(ablkcipher);
struct device *jrdev = ctx->jrdev;
bool iv_contig;
u32 *desc;
int ret = 0;
edesc = ablkcipher_edesc_alloc(req, DESC_JOB_IO_LEN *
CAAM_CMD_SZ, &iv_contig);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
init_ablkcipher_job(ctx->sh_desc_enc,
ctx->sh_desc_enc_dma, edesc, req, iv_contig);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ablkcipher jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, edesc->hw_desc,
desc_bytes(edesc->hw_desc), 1);
#endif
desc = edesc->hw_desc;
ret = caam_jr_enqueue(jrdev, desc, ablkcipher_encrypt_done, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
ablkcipher_unmap(jrdev, edesc, req);
kfree(edesc);
}
return ret;
}
static int ablkcipher_decrypt(struct ablkcipher_request *req)
{
struct ablkcipher_edesc *edesc;
struct crypto_ablkcipher *ablkcipher = crypto_ablkcipher_reqtfm(req);
struct caam_ctx *ctx = crypto_ablkcipher_ctx(ablkcipher);
struct device *jrdev = ctx->jrdev;
bool iv_contig;
u32 *desc;
int ret = 0;
edesc = ablkcipher_edesc_alloc(req, DESC_JOB_IO_LEN *
CAAM_CMD_SZ, &iv_contig);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
init_ablkcipher_job(ctx->sh_desc_dec,
ctx->sh_desc_dec_dma, edesc, req, iv_contig);
desc = edesc->hw_desc;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ablkcipher jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, edesc->hw_desc,
desc_bytes(edesc->hw_desc), 1);
#endif
ret = caam_jr_enqueue(jrdev, desc, ablkcipher_decrypt_done, req);
if (!ret) {
ret = -EINPROGRESS;
} else {
ablkcipher_unmap(jrdev, edesc, req);
kfree(edesc);
}
return ret;
}
static int caam_cra_init(struct crypto_tfm *tfm)
{
struct crypto_alg *alg = tfm->__crt_alg;
struct caam_crypto_alg *caam_alg =
container_of(alg, struct caam_crypto_alg, crypto_alg);
struct caam_ctx *ctx = crypto_tfm_ctx(tfm);
struct caam_drv_private *priv = dev_get_drvdata(caam_alg->ctrldev);
int tgt_jr = atomic_inc_return(&priv->tfm_count);
ctx->jrdev = priv->jrdev[(tgt_jr / 2) % priv->total_jobrs];
ctx->class1_alg_type = OP_TYPE_CLASS1_ALG | caam_alg->class1_alg_type;
ctx->class2_alg_type = OP_TYPE_CLASS2_ALG | caam_alg->class2_alg_type;
ctx->alg_op = OP_TYPE_CLASS2_ALG | caam_alg->alg_op;
return 0;
}
static void caam_cra_exit(struct crypto_tfm *tfm)
{
struct caam_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->sh_desc_enc_dma &&
!dma_mapping_error(ctx->jrdev, ctx->sh_desc_enc_dma))
dma_unmap_single(ctx->jrdev, ctx->sh_desc_enc_dma,
desc_bytes(ctx->sh_desc_enc), DMA_TO_DEVICE);
if (ctx->sh_desc_dec_dma &&
!dma_mapping_error(ctx->jrdev, ctx->sh_desc_dec_dma))
dma_unmap_single(ctx->jrdev, ctx->sh_desc_dec_dma,
desc_bytes(ctx->sh_desc_dec), DMA_TO_DEVICE);
if (ctx->sh_desc_givenc_dma &&
!dma_mapping_error(ctx->jrdev, ctx->sh_desc_givenc_dma))
dma_unmap_single(ctx->jrdev, ctx->sh_desc_givenc_dma,
desc_bytes(ctx->sh_desc_givenc),
DMA_TO_DEVICE);
}
static void __exit caam_algapi_exit(void)
{
struct device_node *dev_node;
struct platform_device *pdev;
struct device *ctrldev;
struct caam_drv_private *priv;
struct caam_crypto_alg *t_alg, *n;
dev_node = of_find_compatible_node(NULL, NULL, "fsl,sec-v4.0");
if (!dev_node) {
dev_node = of_find_compatible_node(NULL, NULL, "fsl,sec4.0");
if (!dev_node)
return;
}
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
alg->cra_blocksize = template->blocksize;
alg->cra_alignmask = 0;
alg->cra_ctxsize = sizeof(struct caam_ctx);
alg->cra_flags = CRYPTO_ALG_ASYNC | CRYPTO_ALG_KERN_DRIVER_ONLY |
template->type;
switch (template->type) {
case CRYPTO_ALG_TYPE_ABLKCIPHER:
alg->cra_type = &crypto_ablkcipher_type;
alg->cra_ablkcipher = template->template_ablkcipher;
break;
case CRYPTO_ALG_TYPE_AEAD:
alg->cra_type = &crypto_aead_type;
alg->cra_aead = template->template_aead;
break;
}
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
struct device *ctrldev;
struct caam_drv_private *priv;
int i = 0, err = 0;
dev_node = of_find_compatible_node(NULL, NULL, "fsl,sec-v4.0");
if (!dev_node) {
dev_node = of_find_compatible_node(NULL, NULL, "fsl,sec4.0");
if (!dev_node)
return -ENODEV;
}
pdev = of_find_device_by_node(dev_node);
if (!pdev)
return -ENODEV;
ctrldev = &pdev->dev;
priv = dev_get_drvdata(ctrldev);
of_node_put(dev_node);
INIT_LIST_HEAD(&priv->alg_list);
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
} else
list_add_tail(&t_alg->entry, &priv->alg_list);
}
if (!list_empty(&priv->alg_list))
dev_info(ctrldev, "%s algorithms registered in /proc/crypto\n",
(char *)of_get_property(dev_node, "compatible", NULL));
return err;
}
