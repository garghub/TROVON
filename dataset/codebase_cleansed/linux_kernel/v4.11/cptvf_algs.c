static void cvm_callback(u32 status, void *arg)
{
struct crypto_async_request *req = (struct crypto_async_request *)arg;
req->complete(req, !status);
}
static inline void update_input_iv(struct cpt_request_info *req_info,
u8 *iv, u32 enc_iv_len,
u32 *argcnt)
{
req_info->in[*argcnt].vptr = (void *)iv;
req_info->in[*argcnt].size = enc_iv_len;
req_info->req.dlen += enc_iv_len;
++(*argcnt);
}
static inline void update_output_iv(struct cpt_request_info *req_info,
u8 *iv, u32 enc_iv_len,
u32 *argcnt)
{
req_info->out[*argcnt].vptr = (void *)iv;
req_info->out[*argcnt].size = enc_iv_len;
req_info->rlen += enc_iv_len;
++(*argcnt);
}
static inline void update_input_data(struct cpt_request_info *req_info,
struct scatterlist *inp_sg,
u32 nbytes, u32 *argcnt)
{
req_info->req.dlen += nbytes;
while (nbytes) {
u32 len = min(nbytes, inp_sg->length);
u8 *ptr = sg_virt(inp_sg);
req_info->in[*argcnt].vptr = (void *)ptr;
req_info->in[*argcnt].size = len;
nbytes -= len;
++(*argcnt);
++inp_sg;
}
}
static inline void update_output_data(struct cpt_request_info *req_info,
struct scatterlist *outp_sg,
u32 nbytes, u32 *argcnt)
{
req_info->rlen += nbytes;
while (nbytes) {
u32 len = min(nbytes, outp_sg->length);
u8 *ptr = sg_virt(outp_sg);
req_info->out[*argcnt].vptr = (void *)ptr;
req_info->out[*argcnt].size = len;
nbytes -= len;
++(*argcnt);
++outp_sg;
}
}
static inline u32 create_ctx_hdr(struct ablkcipher_request *req, u32 enc,
u32 cipher_type, u32 aes_key_type,
u32 *argcnt)
{
struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
struct cvm_enc_ctx *ctx = crypto_ablkcipher_ctx(tfm);
struct cvm_req_ctx *rctx = ablkcipher_request_ctx(req);
struct fc_context *fctx = &rctx->fctx;
u64 *offset_control = &rctx->control_word;
u32 enc_iv_len = crypto_ablkcipher_ivsize(tfm);
struct cpt_request_info *req_info = &rctx->cpt_req;
u64 *ctrl_flags = NULL;
req_info->ctrl.s.grp = 0;
req_info->ctrl.s.dma_mode = DMA_GATHER_SCATTER;
req_info->ctrl.s.se_req = SE_CORE_REQ;
req_info->req.opcode.s.major = MAJOR_OP_FC |
DMA_MODE_FLAG(DMA_GATHER_SCATTER);
if (enc)
req_info->req.opcode.s.minor = 2;
else
req_info->req.opcode.s.minor = 3;
req_info->req.param1 = req->nbytes;
req_info->req.param2 = 0;
fctx->enc.enc_ctrl.e.enc_cipher = cipher_type;
fctx->enc.enc_ctrl.e.aes_key = aes_key_type;
fctx->enc.enc_ctrl.e.iv_source = FROM_DPTR;
if (cipher_type == AES_XTS)
memcpy(fctx->enc.encr_key, ctx->enc_key, ctx->key_len * 2);
else
memcpy(fctx->enc.encr_key, ctx->enc_key, ctx->key_len);
ctrl_flags = (u64 *)&fctx->enc.enc_ctrl.flags;
*ctrl_flags = cpu_to_be64(*ctrl_flags);
*offset_control = cpu_to_be64(((u64)(enc_iv_len) << 16));
req_info->in[*argcnt].vptr = (u8 *)offset_control;
req_info->in[*argcnt].size = CONTROL_WORD_LEN;
req_info->req.dlen += CONTROL_WORD_LEN;
++(*argcnt);
req_info->in[*argcnt].vptr = (u8 *)fctx;
req_info->in[*argcnt].size = sizeof(struct fc_context);
req_info->req.dlen += sizeof(struct fc_context);
++(*argcnt);
return 0;
}
static inline u32 create_input_list(struct ablkcipher_request *req, u32 enc,
u32 cipher_type, u32 aes_key_type,
u32 enc_iv_len)
{
struct cvm_req_ctx *rctx = ablkcipher_request_ctx(req);
struct cpt_request_info *req_info = &rctx->cpt_req;
u32 argcnt = 0;
create_ctx_hdr(req, enc, cipher_type, aes_key_type, &argcnt);
update_input_iv(req_info, req->info, enc_iv_len, &argcnt);
update_input_data(req_info, req->src, req->nbytes, &argcnt);
req_info->incnt = argcnt;
return 0;
}
static inline void store_cb_info(struct ablkcipher_request *req,
struct cpt_request_info *req_info)
{
req_info->callback = (void *)cvm_callback;
req_info->callback_arg = (void *)&req->base;
}
static inline void create_output_list(struct ablkcipher_request *req,
u32 cipher_type,
u32 enc_iv_len)
{
struct cvm_req_ctx *rctx = ablkcipher_request_ctx(req);
struct cpt_request_info *req_info = &rctx->cpt_req;
u32 argcnt = 0;
update_output_iv(req_info, req->info, enc_iv_len, &argcnt);
update_output_data(req_info, req->dst, req->nbytes, &argcnt);
req_info->outcnt = argcnt;
}
static inline int cvm_enc_dec(struct ablkcipher_request *req, u32 enc,
u32 cipher_type)
{
struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
struct cvm_enc_ctx *ctx = crypto_ablkcipher_ctx(tfm);
u32 key_type = AES_128_BIT;
struct cvm_req_ctx *rctx = ablkcipher_request_ctx(req);
u32 enc_iv_len = crypto_ablkcipher_ivsize(tfm);
struct fc_context *fctx = &rctx->fctx;
struct cpt_request_info *req_info = &rctx->cpt_req;
void *cdev = NULL;
int status;
switch (ctx->key_len) {
case 16:
key_type = AES_128_BIT;
break;
case 24:
key_type = AES_192_BIT;
break;
case 32:
if (cipher_type == AES_XTS)
key_type = AES_128_BIT;
else
key_type = AES_256_BIT;
break;
case 64:
if (cipher_type == AES_XTS)
key_type = AES_256_BIT;
else
return -EINVAL;
break;
default:
return -EINVAL;
}
if (cipher_type == DES3_CBC)
key_type = 0;
memset(req_info, 0, sizeof(struct cpt_request_info));
memset(fctx, 0, sizeof(struct fc_context));
create_input_list(req, enc, cipher_type, key_type, enc_iv_len);
create_output_list(req, cipher_type, enc_iv_len);
store_cb_info(req, req_info);
cdev = dev_handle.cdev[smp_processor_id()];
status = cptvf_do_request(cdev, req_info);
if (status)
return status;
else
return -EINPROGRESS;
}
int cvm_des3_encrypt_cbc(struct ablkcipher_request *req)
{
return cvm_enc_dec(req, true, DES3_CBC);
}
int cvm_des3_decrypt_cbc(struct ablkcipher_request *req)
{
return cvm_enc_dec(req, false, DES3_CBC);
}
int cvm_aes_encrypt_xts(struct ablkcipher_request *req)
{
return cvm_enc_dec(req, true, AES_XTS);
}
int cvm_aes_decrypt_xts(struct ablkcipher_request *req)
{
return cvm_enc_dec(req, false, AES_XTS);
}
int cvm_aes_encrypt_cbc(struct ablkcipher_request *req)
{
return cvm_enc_dec(req, true, AES_CBC);
}
int cvm_aes_decrypt_cbc(struct ablkcipher_request *req)
{
return cvm_enc_dec(req, false, AES_CBC);
}
int cvm_xts_setkey(struct crypto_ablkcipher *cipher, const u8 *key,
u32 keylen)
{
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(cipher);
struct cvm_enc_ctx *ctx = crypto_tfm_ctx(tfm);
int err;
const u8 *key1 = key;
const u8 *key2 = key + (keylen / 2);
err = xts_check_key(tfm, key, keylen);
if (err)
return err;
ctx->key_len = keylen;
memcpy(ctx->enc_key, key1, keylen / 2);
memcpy(ctx->enc_key + KEY2_OFFSET, key2, keylen / 2);
return 0;
}
int cvm_enc_dec_setkey(struct crypto_ablkcipher *cipher, const u8 *key,
u32 keylen)
{
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(cipher);
struct cvm_enc_ctx *ctx = crypto_tfm_ctx(tfm);
if ((keylen == 16) || (keylen == 24) || (keylen == 32)) {
ctx->key_len = keylen;
memcpy(ctx->enc_key, key, keylen);
return 0;
}
crypto_ablkcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
int cvm_enc_dec_init(struct crypto_tfm *tfm)
{
struct cvm_enc_ctx *ctx = crypto_tfm_ctx(tfm);
memset(ctx, 0, sizeof(*ctx));
tfm->crt_ablkcipher.reqsize = sizeof(struct cvm_req_ctx) +
sizeof(struct ablkcipher_request);
return 0;
}
static inline int cav_register_algs(void)
{
int err = 0;
err = crypto_register_algs(algs, ARRAY_SIZE(algs));
if (err)
return err;
return 0;
}
static inline void cav_unregister_algs(void)
{
crypto_unregister_algs(algs, ARRAY_SIZE(algs));
}
int cvm_crypto_init(struct cpt_vf *cptvf)
{
struct pci_dev *pdev = cptvf->pdev;
u32 dev_count;
dev_count = dev_handle.dev_count;
dev_handle.cdev[dev_count] = cptvf;
dev_handle.dev_count++;
if (dev_count == 3) {
if (cav_register_algs()) {
dev_err(&pdev->dev, "Error in registering crypto algorithms\n");
return -EINVAL;
}
}
return 0;
}
void cvm_crypto_exit(void)
{
u32 dev_count;
dev_count = --dev_handle.dev_count;
if (!dev_count)
cav_unregister_algs();
}
