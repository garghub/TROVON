static u8 select_channel(void)
{
u8 chan_idx = atomic_inc_return(&iproc_priv.next_chan);
return chan_idx % iproc_priv.spu.num_spu;
}
static int
spu_ablkcipher_rx_sg_create(struct brcm_message *mssg,
struct iproc_reqctx_s *rctx,
u8 rx_frag_num,
unsigned int chunksize, u32 stat_pad_len)
{
struct spu_hw *spu = &iproc_priv.spu;
struct scatterlist *sg;
struct iproc_ctx_s *ctx = rctx->ctx;
u32 datalen;
mssg->spu.dst = kcalloc(rx_frag_num, sizeof(struct scatterlist),
rctx->gfp);
if (!mssg->spu.dst)
return -ENOMEM;
sg = mssg->spu.dst;
sg_init_table(sg, rx_frag_num);
sg_set_buf(sg++, rctx->msg_buf.spu_resp_hdr, ctx->spu_resp_hdr_len);
if ((ctx->cipher.mode == CIPHER_MODE_XTS) &&
spu->spu_xts_tweak_in_payload())
sg_set_buf(sg++, rctx->msg_buf.c.supdt_tweak,
SPU_XTS_TWEAK_SIZE);
datalen = spu_msg_sg_add(&sg, &rctx->dst_sg, &rctx->dst_skip,
rctx->dst_nents, chunksize);
if (datalen < chunksize) {
pr_err("%s(): failed to copy dst sg to mbox msg. chunksize %u, datalen %u",
__func__, chunksize, datalen);
return -EFAULT;
}
if (ctx->cipher.alg == CIPHER_ALG_RC4)
sg_set_buf(sg++, rctx->msg_buf.c.supdt_tweak, SPU_SUPDT_LEN);
if (stat_pad_len)
sg_set_buf(sg++, rctx->msg_buf.rx_stat_pad, stat_pad_len);
memset(rctx->msg_buf.rx_stat, 0, SPU_RX_STATUS_LEN);
sg_set_buf(sg, rctx->msg_buf.rx_stat, spu->spu_rx_status_len());
return 0;
}
static int
spu_ablkcipher_tx_sg_create(struct brcm_message *mssg,
struct iproc_reqctx_s *rctx,
u8 tx_frag_num, unsigned int chunksize, u32 pad_len)
{
struct spu_hw *spu = &iproc_priv.spu;
struct scatterlist *sg;
struct iproc_ctx_s *ctx = rctx->ctx;
u32 datalen;
u32 stat_len;
mssg->spu.src = kcalloc(tx_frag_num, sizeof(struct scatterlist),
rctx->gfp);
if (unlikely(!mssg->spu.src))
return -ENOMEM;
sg = mssg->spu.src;
sg_init_table(sg, tx_frag_num);
sg_set_buf(sg++, rctx->msg_buf.bcm_spu_req_hdr,
BCM_HDR_LEN + ctx->spu_req_hdr_len);
if ((ctx->cipher.mode == CIPHER_MODE_XTS) &&
spu->spu_xts_tweak_in_payload())
sg_set_buf(sg++, rctx->msg_buf.iv_ctr, SPU_XTS_TWEAK_SIZE);
datalen = spu_msg_sg_add(&sg, &rctx->src_sg, &rctx->src_skip,
rctx->src_nents, chunksize);
if (unlikely(datalen < chunksize)) {
pr_err("%s(): failed to copy src sg to mbox msg",
__func__);
return -EFAULT;
}
if (pad_len)
sg_set_buf(sg++, rctx->msg_buf.spu_req_pad, pad_len);
stat_len = spu->spu_tx_status_len();
if (stat_len) {
memset(rctx->msg_buf.tx_stat, 0, stat_len);
sg_set_buf(sg, rctx->msg_buf.tx_stat, stat_len);
}
return 0;
}
static int handle_ablkcipher_req(struct iproc_reqctx_s *rctx)
{
struct spu_hw *spu = &iproc_priv.spu;
struct crypto_async_request *areq = rctx->parent;
struct ablkcipher_request *req =
container_of(areq, struct ablkcipher_request, base);
struct iproc_ctx_s *ctx = rctx->ctx;
struct spu_cipher_parms cipher_parms;
int err = 0;
unsigned int chunksize = 0;
int remaining = 0;
int chunk_start;
u8 local_iv_ctr[MAX_IV_SIZE];
u32 stat_pad_len;
u32 pad_len;
bool update_key = false;
struct brcm_message *mssg;
int retry_cnt = 0;
u8 rx_frag_num = 2;
u8 tx_frag_num = 1;
flow_log("%s\n", __func__);
cipher_parms.alg = ctx->cipher.alg;
cipher_parms.mode = ctx->cipher.mode;
cipher_parms.type = ctx->cipher_type;
cipher_parms.key_len = ctx->enckeylen;
cipher_parms.key_buf = ctx->enckey;
cipher_parms.iv_buf = local_iv_ctr;
cipher_parms.iv_len = rctx->iv_ctr_len;
mssg = &rctx->mb_mssg;
chunk_start = rctx->src_sent;
remaining = rctx->total_todo - chunk_start;
if ((ctx->max_payload != SPU_MAX_PAYLOAD_INF) &&
(remaining > ctx->max_payload))
chunksize = ctx->max_payload;
else
chunksize = remaining;
rctx->src_sent += chunksize;
rctx->total_sent = rctx->src_sent;
rctx->src_nents = spu_sg_count(rctx->src_sg, rctx->src_skip, chunksize);
rctx->dst_nents = spu_sg_count(rctx->dst_sg, rctx->dst_skip, chunksize);
if ((ctx->cipher.mode == CIPHER_MODE_CBC) &&
rctx->is_encrypt && chunk_start)
sg_copy_part_to_buf(req->dst, rctx->msg_buf.iv_ctr,
rctx->iv_ctr_len,
chunk_start - rctx->iv_ctr_len);
if (rctx->iv_ctr_len) {
__builtin_memcpy(local_iv_ctr, rctx->msg_buf.iv_ctr,
rctx->iv_ctr_len);
if ((ctx->cipher.mode == CIPHER_MODE_CBC) &&
!rctx->is_encrypt) {
sg_copy_part_to_buf(req->src, rctx->msg_buf.iv_ctr,
rctx->iv_ctr_len,
rctx->src_sent - rctx->iv_ctr_len);
} else if (ctx->cipher.mode == CIPHER_MODE_CTR) {
add_to_ctr(rctx->msg_buf.iv_ctr, chunksize >> 4);
}
}
if (ctx->cipher.alg == CIPHER_ALG_RC4) {
rx_frag_num++;
if (chunk_start) {
cipher_parms.key_buf = rctx->msg_buf.c.supdt_tweak;
update_key = true;
cipher_parms.type = CIPHER_TYPE_UPDT;
} else if (!rctx->is_encrypt) {
update_key = true;
cipher_parms.type = CIPHER_TYPE_INIT;
}
}
if (ctx->max_payload == SPU_MAX_PAYLOAD_INF)
flow_log("max_payload infinite\n");
else
flow_log("max_payload %u\n", ctx->max_payload);
flow_log("sent:%u start:%u remains:%u size:%u\n",
rctx->src_sent, chunk_start, remaining, chunksize);
memcpy(rctx->msg_buf.bcm_spu_req_hdr, ctx->bcm_spu_req_hdr,
sizeof(rctx->msg_buf.bcm_spu_req_hdr));
spu->spu_cipher_req_finish(rctx->msg_buf.bcm_spu_req_hdr + BCM_HDR_LEN,
ctx->spu_req_hdr_len, !(rctx->is_encrypt),
&cipher_parms, update_key, chunksize);
atomic64_add(chunksize, &iproc_priv.bytes_out);
stat_pad_len = spu->spu_wordalign_padlen(chunksize);
if (stat_pad_len)
rx_frag_num++;
pad_len = stat_pad_len;
if (pad_len) {
tx_frag_num++;
spu->spu_request_pad(rctx->msg_buf.spu_req_pad, 0,
0, ctx->auth.alg, ctx->auth.mode,
rctx->total_sent, stat_pad_len);
}
spu->spu_dump_msg_hdr(rctx->msg_buf.bcm_spu_req_hdr + BCM_HDR_LEN,
ctx->spu_req_hdr_len);
packet_log("payload:\n");
dump_sg(rctx->src_sg, rctx->src_skip, chunksize);
packet_dump(" pad: ", rctx->msg_buf.spu_req_pad, pad_len);
memset(mssg, 0, sizeof(*mssg));
mssg->type = BRCM_MESSAGE_SPU;
mssg->ctx = rctx;
rx_frag_num += rctx->dst_nents;
if ((ctx->cipher.mode == CIPHER_MODE_XTS) &&
spu->spu_xts_tweak_in_payload())
rx_frag_num++;
err = spu_ablkcipher_rx_sg_create(mssg, rctx, rx_frag_num, chunksize,
stat_pad_len);
if (err)
return err;
tx_frag_num += rctx->src_nents;
if (spu->spu_tx_status_len())
tx_frag_num++;
if ((ctx->cipher.mode == CIPHER_MODE_XTS) &&
spu->spu_xts_tweak_in_payload())
tx_frag_num++;
err = spu_ablkcipher_tx_sg_create(mssg, rctx, tx_frag_num, chunksize,
pad_len);
if (err)
return err;
err = mbox_send_message(iproc_priv.mbox[rctx->chan_idx], mssg);
if (req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP) {
while ((err == -ENOBUFS) && (retry_cnt < SPU_MB_RETRY_MAX)) {
retry_cnt++;
usleep_range(MBOX_SLEEP_MIN, MBOX_SLEEP_MAX);
err = mbox_send_message(iproc_priv.mbox[rctx->chan_idx],
mssg);
atomic_inc(&iproc_priv.mb_no_spc);
}
}
if (unlikely(err < 0)) {
atomic_inc(&iproc_priv.mb_send_fail);
return err;
}
return -EINPROGRESS;
}
static void handle_ablkcipher_resp(struct iproc_reqctx_s *rctx)
{
struct spu_hw *spu = &iproc_priv.spu;
#ifdef DEBUG
struct crypto_async_request *areq = rctx->parent;
struct ablkcipher_request *req = ablkcipher_request_cast(areq);
#endif
struct iproc_ctx_s *ctx = rctx->ctx;
u32 payload_len;
payload_len = spu->spu_payload_length(rctx->msg_buf.spu_resp_hdr);
if ((ctx->cipher.mode == CIPHER_MODE_XTS) &&
spu->spu_xts_tweak_in_payload() &&
(payload_len >= SPU_XTS_TWEAK_SIZE))
payload_len -= SPU_XTS_TWEAK_SIZE;
atomic64_add(payload_len, &iproc_priv.bytes_in);
flow_log("%s() offset: %u, bd_len: %u BD:\n",
__func__, rctx->total_received, payload_len);
dump_sg(req->dst, rctx->total_received, payload_len);
if (ctx->cipher.alg == CIPHER_ALG_RC4)
packet_dump(" supdt ", rctx->msg_buf.c.supdt_tweak,
SPU_SUPDT_LEN);
rctx->total_received += payload_len;
if (rctx->total_received == rctx->total_todo) {
atomic_inc(&iproc_priv.op_counts[SPU_OP_CIPHER]);
atomic_inc(
&iproc_priv.cipher_cnt[ctx->cipher.alg][ctx->cipher.mode]);
}
}
static int
spu_ahash_rx_sg_create(struct brcm_message *mssg,
struct iproc_reqctx_s *rctx,
u8 rx_frag_num, unsigned int digestsize,
u32 stat_pad_len)
{
struct spu_hw *spu = &iproc_priv.spu;
struct scatterlist *sg;
struct iproc_ctx_s *ctx = rctx->ctx;
mssg->spu.dst = kcalloc(rx_frag_num, sizeof(struct scatterlist),
rctx->gfp);
if (!mssg->spu.dst)
return -ENOMEM;
sg = mssg->spu.dst;
sg_init_table(sg, rx_frag_num);
sg_set_buf(sg++, rctx->msg_buf.spu_resp_hdr, ctx->spu_resp_hdr_len);
sg_set_buf(sg++, rctx->msg_buf.digest, digestsize);
if (stat_pad_len)
sg_set_buf(sg++, rctx->msg_buf.rx_stat_pad, stat_pad_len);
memset(rctx->msg_buf.rx_stat, 0, SPU_RX_STATUS_LEN);
sg_set_buf(sg, rctx->msg_buf.rx_stat, spu->spu_rx_status_len());
return 0;
}
static int
spu_ahash_tx_sg_create(struct brcm_message *mssg,
struct iproc_reqctx_s *rctx,
u8 tx_frag_num,
u32 spu_hdr_len,
unsigned int hash_carry_len,
unsigned int new_data_len, u32 pad_len)
{
struct spu_hw *spu = &iproc_priv.spu;
struct scatterlist *sg;
u32 datalen;
u32 stat_len;
mssg->spu.src = kcalloc(tx_frag_num, sizeof(struct scatterlist),
rctx->gfp);
if (!mssg->spu.src)
return -ENOMEM;
sg = mssg->spu.src;
sg_init_table(sg, tx_frag_num);
sg_set_buf(sg++, rctx->msg_buf.bcm_spu_req_hdr,
BCM_HDR_LEN + spu_hdr_len);
if (hash_carry_len)
sg_set_buf(sg++, rctx->hash_carry, hash_carry_len);
if (new_data_len) {
datalen = spu_msg_sg_add(&sg, &rctx->src_sg, &rctx->src_skip,
rctx->src_nents, new_data_len);
if (datalen < new_data_len) {
pr_err("%s(): failed to copy src sg to mbox msg",
__func__);
return -EFAULT;
}
}
if (pad_len)
sg_set_buf(sg++, rctx->msg_buf.spu_req_pad, pad_len);
stat_len = spu->spu_tx_status_len();
if (stat_len) {
memset(rctx->msg_buf.tx_stat, 0, stat_len);
sg_set_buf(sg, rctx->msg_buf.tx_stat, stat_len);
}
return 0;
}
static int handle_ahash_req(struct iproc_reqctx_s *rctx)
{
struct spu_hw *spu = &iproc_priv.spu;
struct crypto_async_request *areq = rctx->parent;
struct ahash_request *req = ahash_request_cast(areq);
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct crypto_tfm *tfm = crypto_ahash_tfm(ahash);
unsigned int blocksize = crypto_tfm_alg_blocksize(tfm);
struct iproc_ctx_s *ctx = rctx->ctx;
unsigned int nbytes_to_hash = 0;
int err = 0;
unsigned int chunksize = 0;
unsigned int new_data_len;
unsigned int chunk_start = 0;
u32 db_size;
int pad_len = 0;
u32 data_pad_len = 0;
u32 stat_pad_len = 0;
struct brcm_message *mssg;
struct spu_request_opts req_opts;
struct spu_cipher_parms cipher_parms;
struct spu_hash_parms hash_parms;
struct spu_aead_parms aead_parms;
unsigned int local_nbuf;
u32 spu_hdr_len;
unsigned int digestsize;
u16 rem = 0;
int retry_cnt = 0;
u8 rx_frag_num = 3;
u8 tx_frag_num = 1;
flow_log("total_todo %u, total_sent %u\n",
rctx->total_todo, rctx->total_sent);
memset(&req_opts, 0, sizeof(req_opts));
memset(&cipher_parms, 0, sizeof(cipher_parms));
memset(&hash_parms, 0, sizeof(hash_parms));
memset(&aead_parms, 0, sizeof(aead_parms));
req_opts.bd_suppress = true;
hash_parms.alg = ctx->auth.alg;
hash_parms.mode = ctx->auth.mode;
hash_parms.type = HASH_TYPE_NONE;
hash_parms.key_buf = (u8 *)ctx->authkey;
hash_parms.key_len = ctx->authkeylen;
cipher_parms.type = ctx->cipher_type;
mssg = &rctx->mb_mssg;
chunk_start = rctx->src_sent;
nbytes_to_hash = rctx->total_todo - rctx->total_sent;
chunksize = nbytes_to_hash;
if ((ctx->max_payload != SPU_MAX_PAYLOAD_INF) &&
(chunksize > ctx->max_payload))
chunksize = ctx->max_payload;
if (!rctx->is_final) {
u8 *dest = rctx->hash_carry + rctx->hash_carry_len;
u16 new_len;
rem = chunksize % blocksize;
if (rem) {
chunksize -= rem;
if (chunksize == 0) {
new_len = rem - rctx->hash_carry_len;
sg_copy_part_to_buf(req->src, dest, new_len,
rctx->src_sent);
rctx->hash_carry_len = rem;
flow_log("Exiting with hash carry len: %u\n",
rctx->hash_carry_len);
packet_dump(" buf: ",
rctx->hash_carry,
rctx->hash_carry_len);
return -EAGAIN;
}
}
}
local_nbuf = rctx->hash_carry_len;
rctx->hash_carry_len = 0;
if (local_nbuf)
tx_frag_num++;
new_data_len = chunksize - local_nbuf;
rctx->src_nents = spu_sg_count(rctx->src_sg, rctx->src_skip,
new_data_len);
if (hash_parms.alg == HASH_ALG_AES)
hash_parms.type = cipher_parms.type;
else
hash_parms.type = spu->spu_hash_type(rctx->total_sent);
digestsize = spu->spu_digest_size(ctx->digestsize, ctx->auth.alg,
hash_parms.type);
hash_parms.digestsize = digestsize;
rctx->total_sent += chunksize;
rctx->src_sent += new_data_len;
if ((rctx->total_sent == rctx->total_todo) && rctx->is_final)
hash_parms.pad_len = spu->spu_hash_pad_len(hash_parms.alg,
hash_parms.mode,
chunksize,
blocksize);
if ((hash_parms.type == HASH_TYPE_UPDT) &&
(hash_parms.alg != HASH_ALG_AES)) {
hash_parms.key_buf = rctx->incr_hash;
hash_parms.key_len = digestsize;
}
atomic64_add(chunksize, &iproc_priv.bytes_out);
flow_log("%s() final: %u nbuf: %u ",
__func__, rctx->is_final, local_nbuf);
if (ctx->max_payload == SPU_MAX_PAYLOAD_INF)
flow_log("max_payload infinite\n");
else
flow_log("max_payload %u\n", ctx->max_payload);
flow_log("chunk_start: %u chunk_size: %u\n", chunk_start, chunksize);
memcpy(rctx->msg_buf.bcm_spu_req_hdr, BCMHEADER, BCM_HDR_LEN);
hash_parms.prebuf_len = local_nbuf;
spu_hdr_len = spu->spu_create_request(rctx->msg_buf.bcm_spu_req_hdr +
BCM_HDR_LEN,
&req_opts, &cipher_parms,
&hash_parms, &aead_parms,
new_data_len);
if (spu_hdr_len == 0) {
pr_err("Failed to create SPU request header\n");
return -EFAULT;
}
data_pad_len = spu->spu_gcm_ccm_pad_len(ctx->cipher.mode, chunksize);
db_size = spu_real_db_size(0, 0, local_nbuf, new_data_len,
0, 0, hash_parms.pad_len);
if (spu->spu_tx_status_len())
stat_pad_len = spu->spu_wordalign_padlen(db_size);
if (stat_pad_len)
rx_frag_num++;
pad_len = hash_parms.pad_len + data_pad_len + stat_pad_len;
if (pad_len) {
tx_frag_num++;
spu->spu_request_pad(rctx->msg_buf.spu_req_pad, data_pad_len,
hash_parms.pad_len, ctx->auth.alg,
ctx->auth.mode, rctx->total_sent,
stat_pad_len);
}
spu->spu_dump_msg_hdr(rctx->msg_buf.bcm_spu_req_hdr + BCM_HDR_LEN,
spu_hdr_len);
packet_dump(" prebuf: ", rctx->hash_carry, local_nbuf);
flow_log("Data:\n");
dump_sg(rctx->src_sg, rctx->src_skip, new_data_len);
packet_dump(" pad: ", rctx->msg_buf.spu_req_pad, pad_len);
memset(mssg, 0, sizeof(*mssg));
mssg->type = BRCM_MESSAGE_SPU;
mssg->ctx = rctx;
err = spu_ahash_rx_sg_create(mssg, rctx, rx_frag_num, digestsize,
stat_pad_len);
if (err)
return err;
tx_frag_num += rctx->src_nents;
if (spu->spu_tx_status_len())
tx_frag_num++;
err = spu_ahash_tx_sg_create(mssg, rctx, tx_frag_num, spu_hdr_len,
local_nbuf, new_data_len, pad_len);
if (err)
return err;
err = mbox_send_message(iproc_priv.mbox[rctx->chan_idx], mssg);
if (req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP) {
while ((err == -ENOBUFS) && (retry_cnt < SPU_MB_RETRY_MAX)) {
retry_cnt++;
usleep_range(MBOX_SLEEP_MIN, MBOX_SLEEP_MAX);
err = mbox_send_message(iproc_priv.mbox[rctx->chan_idx],
mssg);
atomic_inc(&iproc_priv.mb_no_spc);
}
}
if (err < 0) {
atomic_inc(&iproc_priv.mb_send_fail);
return err;
}
return -EINPROGRESS;
}
static int spu_hmac_outer_hash(struct ahash_request *req,
struct iproc_ctx_s *ctx)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
unsigned int blocksize =
crypto_tfm_alg_blocksize(crypto_ahash_tfm(ahash));
int rc;
switch (ctx->auth.alg) {
case HASH_ALG_MD5:
rc = do_shash("md5", req->result, ctx->opad, blocksize,
req->result, ctx->digestsize, NULL, 0);
break;
case HASH_ALG_SHA1:
rc = do_shash("sha1", req->result, ctx->opad, blocksize,
req->result, ctx->digestsize, NULL, 0);
break;
case HASH_ALG_SHA224:
rc = do_shash("sha224", req->result, ctx->opad, blocksize,
req->result, ctx->digestsize, NULL, 0);
break;
case HASH_ALG_SHA256:
rc = do_shash("sha256", req->result, ctx->opad, blocksize,
req->result, ctx->digestsize, NULL, 0);
break;
case HASH_ALG_SHA384:
rc = do_shash("sha384", req->result, ctx->opad, blocksize,
req->result, ctx->digestsize, NULL, 0);
break;
case HASH_ALG_SHA512:
rc = do_shash("sha512", req->result, ctx->opad, blocksize,
req->result, ctx->digestsize, NULL, 0);
break;
default:
pr_err("%s() Error : unknown hmac type\n", __func__);
rc = -EINVAL;
}
return rc;
}
static int ahash_req_done(struct iproc_reqctx_s *rctx)
{
struct spu_hw *spu = &iproc_priv.spu;
struct crypto_async_request *areq = rctx->parent;
struct ahash_request *req = ahash_request_cast(areq);
struct iproc_ctx_s *ctx = rctx->ctx;
int err;
memcpy(req->result, rctx->msg_buf.digest, ctx->digestsize);
if (spu->spu_type == SPU_TYPE_SPUM) {
if (ctx->auth.alg == HASH_ALG_MD5) {
__swab32s((u32 *)req->result);
__swab32s(((u32 *)req->result) + 1);
__swab32s(((u32 *)req->result) + 2);
__swab32s(((u32 *)req->result) + 3);
__swab32s(((u32 *)req->result) + 4);
}
}
flow_dump(" digest ", req->result, ctx->digestsize);
if (rctx->is_sw_hmac) {
err = spu_hmac_outer_hash(req, ctx);
if (err < 0)
return err;
flow_dump(" hmac: ", req->result, ctx->digestsize);
}
if (rctx->is_sw_hmac || ctx->auth.mode == HASH_MODE_HMAC) {
atomic_inc(&iproc_priv.op_counts[SPU_OP_HMAC]);
atomic_inc(&iproc_priv.hmac_cnt[ctx->auth.alg]);
} else {
atomic_inc(&iproc_priv.op_counts[SPU_OP_HASH]);
atomic_inc(&iproc_priv.hash_cnt[ctx->auth.alg]);
}
return 0;
}
static void handle_ahash_resp(struct iproc_reqctx_s *rctx)
{
struct iproc_ctx_s *ctx = rctx->ctx;
#ifdef DEBUG
struct crypto_async_request *areq = rctx->parent;
struct ahash_request *req = ahash_request_cast(areq);
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
unsigned int blocksize =
crypto_tfm_alg_blocksize(crypto_ahash_tfm(ahash));
#endif
memcpy(rctx->incr_hash, rctx->msg_buf.digest, MAX_DIGEST_SIZE);
flow_log("%s() blocksize:%u digestsize:%u\n",
__func__, blocksize, ctx->digestsize);
atomic64_add(ctx->digestsize, &iproc_priv.bytes_in);
if (rctx->is_final && (rctx->total_sent == rctx->total_todo))
ahash_req_done(rctx);
}
static int spu_aead_rx_sg_create(struct brcm_message *mssg,
struct aead_request *req,
struct iproc_reqctx_s *rctx,
u8 rx_frag_num,
unsigned int assoc_len,
u32 ret_iv_len, unsigned int resp_len,
unsigned int digestsize, u32 stat_pad_len)
{
struct spu_hw *spu = &iproc_priv.spu;
struct scatterlist *sg;
struct iproc_ctx_s *ctx = rctx->ctx;
u32 datalen;
u32 assoc_buf_len;
u8 data_padlen = 0;
if (ctx->is_rfc4543) {
data_padlen = spu->spu_gcm_ccm_pad_len(ctx->cipher.mode,
assoc_len + resp_len);
assoc_buf_len = assoc_len;
} else {
data_padlen = spu->spu_gcm_ccm_pad_len(ctx->cipher.mode,
resp_len);
assoc_buf_len = spu->spu_assoc_resp_len(ctx->cipher.mode,
assoc_len, ret_iv_len,
rctx->is_encrypt);
}
if (ctx->cipher.mode == CIPHER_MODE_CCM)
data_padlen += spu->spu_wordalign_padlen(assoc_buf_len +
resp_len +
data_padlen);
if (data_padlen)
rx_frag_num++;
mssg->spu.dst = kcalloc(rx_frag_num, sizeof(struct scatterlist),
rctx->gfp);
if (!mssg->spu.dst)
return -ENOMEM;
sg = mssg->spu.dst;
sg_init_table(sg, rx_frag_num);
sg_set_buf(sg++, rctx->msg_buf.spu_resp_hdr, ctx->spu_resp_hdr_len);
if (assoc_buf_len) {
memset(rctx->msg_buf.a.resp_aad, 0, assoc_buf_len);
sg_set_buf(sg++, rctx->msg_buf.a.resp_aad, assoc_buf_len);
}
if (resp_len) {
datalen = spu_msg_sg_add(&sg, &rctx->dst_sg, &rctx->dst_skip,
rctx->dst_nents, resp_len);
if (datalen < (resp_len)) {
pr_err("%s(): failed to copy dst sg to mbox msg. expected len %u, datalen %u",
__func__, resp_len, datalen);
return -EFAULT;
}
}
if (data_padlen) {
memset(rctx->msg_buf.a.gcmpad, 0, data_padlen);
sg_set_buf(sg++, rctx->msg_buf.a.gcmpad, data_padlen);
}
sg_set_buf(sg++, rctx->msg_buf.digest, digestsize);
flow_log("stat_pad_len %u\n", stat_pad_len);
if (stat_pad_len) {
memset(rctx->msg_buf.rx_stat_pad, 0, stat_pad_len);
sg_set_buf(sg++, rctx->msg_buf.rx_stat_pad, stat_pad_len);
}
memset(rctx->msg_buf.rx_stat, 0, SPU_RX_STATUS_LEN);
sg_set_buf(sg, rctx->msg_buf.rx_stat, spu->spu_rx_status_len());
return 0;
}
static int spu_aead_tx_sg_create(struct brcm_message *mssg,
struct iproc_reqctx_s *rctx,
u8 tx_frag_num,
u32 spu_hdr_len,
struct scatterlist *assoc,
unsigned int assoc_len,
int assoc_nents,
unsigned int aead_iv_len,
unsigned int chunksize,
u32 aad_pad_len, u32 pad_len, bool incl_icv)
{
struct spu_hw *spu = &iproc_priv.spu;
struct scatterlist *sg;
struct scatterlist *assoc_sg = assoc;
struct iproc_ctx_s *ctx = rctx->ctx;
u32 datalen;
u32 written;
u32 assoc_offset = 0;
u32 stat_len;
mssg->spu.src = kcalloc(tx_frag_num, sizeof(struct scatterlist),
rctx->gfp);
if (!mssg->spu.src)
return -ENOMEM;
sg = mssg->spu.src;
sg_init_table(sg, tx_frag_num);
sg_set_buf(sg++, rctx->msg_buf.bcm_spu_req_hdr,
BCM_HDR_LEN + spu_hdr_len);
if (assoc_len) {
written = spu_msg_sg_add(&sg, &assoc_sg, &assoc_offset,
assoc_nents, assoc_len);
if (written < assoc_len) {
pr_err("%s(): failed to copy assoc sg to mbox msg",
__func__);
return -EFAULT;
}
}
if (aead_iv_len)
sg_set_buf(sg++, rctx->msg_buf.iv_ctr, aead_iv_len);
if (aad_pad_len) {
memset(rctx->msg_buf.a.req_aad_pad, 0, aad_pad_len);
sg_set_buf(sg++, rctx->msg_buf.a.req_aad_pad, aad_pad_len);
}
datalen = chunksize;
if ((chunksize > ctx->digestsize) && incl_icv)
datalen -= ctx->digestsize;
if (datalen) {
written = spu_msg_sg_add(&sg, &rctx->src_sg, &rctx->src_skip,
rctx->src_nents, datalen);
if (written < datalen) {
pr_err("%s(): failed to copy src sg to mbox msg",
__func__);
return -EFAULT;
}
}
if (pad_len) {
memset(rctx->msg_buf.spu_req_pad, 0, pad_len);
sg_set_buf(sg++, rctx->msg_buf.spu_req_pad, pad_len);
}
if (incl_icv)
sg_set_buf(sg++, rctx->msg_buf.digest, ctx->digestsize);
stat_len = spu->spu_tx_status_len();
if (stat_len) {
memset(rctx->msg_buf.tx_stat, 0, stat_len);
sg_set_buf(sg, rctx->msg_buf.tx_stat, stat_len);
}
return 0;
}
static int handle_aead_req(struct iproc_reqctx_s *rctx)
{
struct spu_hw *spu = &iproc_priv.spu;
struct crypto_async_request *areq = rctx->parent;
struct aead_request *req = container_of(areq,
struct aead_request, base);
struct iproc_ctx_s *ctx = rctx->ctx;
int err;
unsigned int chunksize;
unsigned int resp_len;
u32 spu_hdr_len;
u32 db_size;
u32 stat_pad_len;
u32 pad_len;
struct brcm_message *mssg;
struct spu_request_opts req_opts;
struct spu_cipher_parms cipher_parms;
struct spu_hash_parms hash_parms;
struct spu_aead_parms aead_parms;
int assoc_nents = 0;
bool incl_icv = false;
unsigned int digestsize = ctx->digestsize;
int retry_cnt = 0;
u8 rx_frag_num = 2;
u8 tx_frag_num = 1;
chunksize = rctx->total_todo;
flow_log("%s: chunksize %u\n", __func__, chunksize);
memset(&req_opts, 0, sizeof(req_opts));
memset(&hash_parms, 0, sizeof(hash_parms));
memset(&aead_parms, 0, sizeof(aead_parms));
req_opts.is_inbound = !(rctx->is_encrypt);
req_opts.auth_first = ctx->auth_first;
req_opts.is_aead = true;
req_opts.is_esp = ctx->is_esp;
cipher_parms.alg = ctx->cipher.alg;
cipher_parms.mode = ctx->cipher.mode;
cipher_parms.type = ctx->cipher_type;
cipher_parms.key_buf = ctx->enckey;
cipher_parms.key_len = ctx->enckeylen;
cipher_parms.iv_buf = rctx->msg_buf.iv_ctr;
cipher_parms.iv_len = rctx->iv_ctr_len;
hash_parms.alg = ctx->auth.alg;
hash_parms.mode = ctx->auth.mode;
hash_parms.type = HASH_TYPE_NONE;
hash_parms.key_buf = (u8 *)ctx->authkey;
hash_parms.key_len = ctx->authkeylen;
hash_parms.digestsize = digestsize;
if ((ctx->auth.alg == HASH_ALG_SHA224) &&
(ctx->authkeylen < SHA224_DIGEST_SIZE))
hash_parms.key_len = SHA224_DIGEST_SIZE;
aead_parms.assoc_size = req->assoclen;
if (ctx->is_esp && !ctx->is_rfc4543) {
aead_parms.assoc_size -= GCM_ESP_IV_SIZE;
if (rctx->is_encrypt) {
aead_parms.return_iv = true;
aead_parms.ret_iv_len = GCM_ESP_IV_SIZE;
aead_parms.ret_iv_off = GCM_ESP_SALT_SIZE;
}
} else {
aead_parms.ret_iv_len = 0;
}
rctx->src_nents = spu_sg_count(rctx->src_sg, rctx->src_skip, chunksize);
rctx->dst_nents = spu_sg_count(rctx->dst_sg, rctx->dst_skip, chunksize);
if (aead_parms.assoc_size)
assoc_nents = spu_sg_count(rctx->assoc, 0,
aead_parms.assoc_size);
mssg = &rctx->mb_mssg;
rctx->total_sent = chunksize;
rctx->src_sent = chunksize;
if (spu->spu_assoc_resp_len(ctx->cipher.mode,
aead_parms.assoc_size,
aead_parms.ret_iv_len,
rctx->is_encrypt))
rx_frag_num++;
aead_parms.iv_len = spu->spu_aead_ivlen(ctx->cipher.mode,
rctx->iv_ctr_len);
if (ctx->auth.alg == HASH_ALG_AES)
hash_parms.type = ctx->cipher_type;
aead_parms.aad_pad_len = spu->spu_gcm_ccm_pad_len(ctx->cipher.mode,
aead_parms.assoc_size);
aead_parms.data_pad_len = spu->spu_gcm_ccm_pad_len(ctx->cipher.mode,
chunksize);
if (ctx->cipher.mode == CIPHER_MODE_CCM) {
aead_parms.aad_pad_len = spu->spu_gcm_ccm_pad_len(
ctx->cipher.mode,
aead_parms.assoc_size + 2);
if (!rctx->is_encrypt)
aead_parms.data_pad_len =
spu->spu_gcm_ccm_pad_len(ctx->cipher.mode,
chunksize - digestsize);
spu->spu_ccm_update_iv(digestsize, &cipher_parms, req->assoclen,
chunksize, rctx->is_encrypt,
ctx->is_esp);
}
if (ctx->is_rfc4543) {
aead_parms.aad_pad_len = 0;
if (!rctx->is_encrypt)
aead_parms.data_pad_len = spu->spu_gcm_ccm_pad_len(
ctx->cipher.mode,
aead_parms.assoc_size + chunksize -
digestsize);
else
aead_parms.data_pad_len = spu->spu_gcm_ccm_pad_len(
ctx->cipher.mode,
aead_parms.assoc_size + chunksize);
req_opts.is_rfc4543 = true;
}
if (spu_req_incl_icv(ctx->cipher.mode, rctx->is_encrypt)) {
incl_icv = true;
tx_frag_num++;
sg_copy_part_to_buf(req->src, rctx->msg_buf.digest, digestsize,
req->assoclen + rctx->total_sent -
digestsize);
}
atomic64_add(chunksize, &iproc_priv.bytes_out);
flow_log("%s()-sent chunksize:%u\n", __func__, chunksize);
memcpy(rctx->msg_buf.bcm_spu_req_hdr, BCMHEADER, BCM_HDR_LEN);
spu_hdr_len = spu->spu_create_request(rctx->msg_buf.bcm_spu_req_hdr +
BCM_HDR_LEN, &req_opts,
&cipher_parms, &hash_parms,
&aead_parms, chunksize);
db_size = spu_real_db_size(aead_parms.assoc_size, aead_parms.iv_len, 0,
chunksize, aead_parms.aad_pad_len,
aead_parms.data_pad_len, 0);
stat_pad_len = spu->spu_wordalign_padlen(db_size);
if (stat_pad_len)
rx_frag_num++;
pad_len = aead_parms.data_pad_len + stat_pad_len;
if (pad_len) {
tx_frag_num++;
spu->spu_request_pad(rctx->msg_buf.spu_req_pad,
aead_parms.data_pad_len, 0,
ctx->auth.alg, ctx->auth.mode,
rctx->total_sent, stat_pad_len);
}
spu->spu_dump_msg_hdr(rctx->msg_buf.bcm_spu_req_hdr + BCM_HDR_LEN,
spu_hdr_len);
dump_sg(rctx->assoc, 0, aead_parms.assoc_size);
packet_dump(" aead iv: ", rctx->msg_buf.iv_ctr, aead_parms.iv_len);
packet_log("BD:\n");
dump_sg(rctx->src_sg, rctx->src_skip, chunksize);
packet_dump(" pad: ", rctx->msg_buf.spu_req_pad, pad_len);
memset(mssg, 0, sizeof(*mssg));
mssg->type = BRCM_MESSAGE_SPU;
mssg->ctx = rctx;
rx_frag_num += rctx->dst_nents;
resp_len = chunksize;
rx_frag_num++;
if (((ctx->cipher.mode == CIPHER_MODE_GCM) ||
(ctx->cipher.mode == CIPHER_MODE_CCM)) && !rctx->is_encrypt) {
resp_len -= ctx->digestsize;
if (resp_len == 0)
rx_frag_num -= rctx->dst_nents;
}
err = spu_aead_rx_sg_create(mssg, req, rctx, rx_frag_num,
aead_parms.assoc_size,
aead_parms.ret_iv_len, resp_len, digestsize,
stat_pad_len);
if (err)
return err;
tx_frag_num += rctx->src_nents;
tx_frag_num += assoc_nents;
if (aead_parms.aad_pad_len)
tx_frag_num++;
if (aead_parms.iv_len)
tx_frag_num++;
if (spu->spu_tx_status_len())
tx_frag_num++;
err = spu_aead_tx_sg_create(mssg, rctx, tx_frag_num, spu_hdr_len,
rctx->assoc, aead_parms.assoc_size,
assoc_nents, aead_parms.iv_len, chunksize,
aead_parms.aad_pad_len, pad_len, incl_icv);
if (err)
return err;
err = mbox_send_message(iproc_priv.mbox[rctx->chan_idx], mssg);
if (req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP) {
while ((err == -ENOBUFS) && (retry_cnt < SPU_MB_RETRY_MAX)) {
retry_cnt++;
usleep_range(MBOX_SLEEP_MIN, MBOX_SLEEP_MAX);
err = mbox_send_message(iproc_priv.mbox[rctx->chan_idx],
mssg);
atomic_inc(&iproc_priv.mb_no_spc);
}
}
if (err < 0) {
atomic_inc(&iproc_priv.mb_send_fail);
return err;
}
return -EINPROGRESS;
}
static void handle_aead_resp(struct iproc_reqctx_s *rctx)
{
struct spu_hw *spu = &iproc_priv.spu;
struct crypto_async_request *areq = rctx->parent;
struct aead_request *req = container_of(areq,
struct aead_request, base);
struct iproc_ctx_s *ctx = rctx->ctx;
u32 payload_len;
unsigned int icv_offset;
u32 result_len;
payload_len = spu->spu_payload_length(rctx->msg_buf.spu_resp_hdr);
flow_log("payload_len %u\n", payload_len);
atomic64_add(payload_len, &iproc_priv.bytes_in);
if (req->assoclen)
packet_dump(" assoc_data ", rctx->msg_buf.a.resp_aad,
req->assoclen);
result_len = req->cryptlen;
if (rctx->is_encrypt) {
icv_offset = req->assoclen + rctx->total_sent;
packet_dump(" ICV: ", rctx->msg_buf.digest, ctx->digestsize);
flow_log("copying ICV to dst sg at offset %u\n", icv_offset);
sg_copy_part_from_buf(req->dst, rctx->msg_buf.digest,
ctx->digestsize, icv_offset);
result_len += ctx->digestsize;
}
packet_log("response data: ");
dump_sg(req->dst, req->assoclen, result_len);
atomic_inc(&iproc_priv.op_counts[SPU_OP_AEAD]);
if (ctx->cipher.alg == CIPHER_ALG_AES) {
if (ctx->cipher.mode == CIPHER_MODE_CCM)
atomic_inc(&iproc_priv.aead_cnt[AES_CCM]);
else if (ctx->cipher.mode == CIPHER_MODE_GCM)
atomic_inc(&iproc_priv.aead_cnt[AES_GCM]);
else
atomic_inc(&iproc_priv.aead_cnt[AUTHENC]);
} else {
atomic_inc(&iproc_priv.aead_cnt[AUTHENC]);
}
}
static void spu_chunk_cleanup(struct iproc_reqctx_s *rctx)
{
struct brcm_message *mssg = &rctx->mb_mssg;
kfree(mssg->spu.src);
kfree(mssg->spu.dst);
memset(mssg, 0, sizeof(struct brcm_message));
}
static void finish_req(struct iproc_reqctx_s *rctx, int err)
{
struct crypto_async_request *areq = rctx->parent;
flow_log("%s() err:%d\n\n", __func__, err);
spu_chunk_cleanup(rctx);
if (areq)
areq->complete(areq, err);
}
static void spu_rx_callback(struct mbox_client *cl, void *msg)
{
struct spu_hw *spu = &iproc_priv.spu;
struct brcm_message *mssg = msg;
struct iproc_reqctx_s *rctx;
struct iproc_ctx_s *ctx;
struct crypto_async_request *areq;
int err = 0;
rctx = mssg->ctx;
if (unlikely(!rctx)) {
pr_err("%s(): no request context", __func__);
err = -EFAULT;
goto cb_finish;
}
areq = rctx->parent;
ctx = rctx->ctx;
err = spu->spu_status_process(rctx->msg_buf.rx_stat);
if (err != 0) {
if (err == SPU_INVALID_ICV)
atomic_inc(&iproc_priv.bad_icv);
err = -EBADMSG;
goto cb_finish;
}
switch (rctx->ctx->alg->type) {
case CRYPTO_ALG_TYPE_ABLKCIPHER:
handle_ablkcipher_resp(rctx);
break;
case CRYPTO_ALG_TYPE_AHASH:
handle_ahash_resp(rctx);
break;
case CRYPTO_ALG_TYPE_AEAD:
handle_aead_resp(rctx);
break;
default:
err = -EINVAL;
goto cb_finish;
}
if (rctx->total_sent < rctx->total_todo) {
spu_chunk_cleanup(rctx);
switch (rctx->ctx->alg->type) {
case CRYPTO_ALG_TYPE_ABLKCIPHER:
err = handle_ablkcipher_req(rctx);
break;
case CRYPTO_ALG_TYPE_AHASH:
err = handle_ahash_req(rctx);
if (err == -EAGAIN)
err = 0;
break;
case CRYPTO_ALG_TYPE_AEAD:
err = handle_aead_req(rctx);
break;
default:
err = -EINVAL;
}
if (err == -EINPROGRESS)
return;
}
cb_finish:
finish_req(rctx, err);
}
static int ablkcipher_enqueue(struct ablkcipher_request *req, bool encrypt)
{
struct iproc_reqctx_s *rctx = ablkcipher_request_ctx(req);
struct iproc_ctx_s *ctx =
crypto_ablkcipher_ctx(crypto_ablkcipher_reqtfm(req));
int err;
flow_log("%s() enc:%u\n", __func__, encrypt);
rctx->gfp = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
rctx->parent = &req->base;
rctx->is_encrypt = encrypt;
rctx->bd_suppress = false;
rctx->total_todo = req->nbytes;
rctx->src_sent = 0;
rctx->total_sent = 0;
rctx->total_received = 0;
rctx->ctx = ctx;
rctx->src_sg = req->src;
rctx->src_nents = 0;
rctx->src_skip = 0;
rctx->dst_sg = req->dst;
rctx->dst_nents = 0;
rctx->dst_skip = 0;
if (ctx->cipher.mode == CIPHER_MODE_CBC ||
ctx->cipher.mode == CIPHER_MODE_CTR ||
ctx->cipher.mode == CIPHER_MODE_OFB ||
ctx->cipher.mode == CIPHER_MODE_XTS ||
ctx->cipher.mode == CIPHER_MODE_GCM ||
ctx->cipher.mode == CIPHER_MODE_CCM) {
rctx->iv_ctr_len =
crypto_ablkcipher_ivsize(crypto_ablkcipher_reqtfm(req));
memcpy(rctx->msg_buf.iv_ctr, req->info, rctx->iv_ctr_len);
} else {
rctx->iv_ctr_len = 0;
}
rctx->chan_idx = select_channel();
err = handle_ablkcipher_req(rctx);
if (err != -EINPROGRESS)
spu_chunk_cleanup(rctx);
return err;
}
static int des_setkey(struct crypto_ablkcipher *cipher, const u8 *key,
unsigned int keylen)
{
struct iproc_ctx_s *ctx = crypto_ablkcipher_ctx(cipher);
u32 tmp[DES_EXPKEY_WORDS];
if (keylen == DES_KEY_SIZE) {
if (des_ekey(tmp, key) == 0) {
if (crypto_ablkcipher_get_flags(cipher) &
CRYPTO_TFM_REQ_WEAK_KEY) {
u32 flags = CRYPTO_TFM_RES_WEAK_KEY;
crypto_ablkcipher_set_flags(cipher, flags);
return -EINVAL;
}
}
ctx->cipher_type = CIPHER_TYPE_DES;
} else {
crypto_ablkcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
return 0;
}
static int threedes_setkey(struct crypto_ablkcipher *cipher, const u8 *key,
unsigned int keylen)
{
struct iproc_ctx_s *ctx = crypto_ablkcipher_ctx(cipher);
if (keylen == (DES_KEY_SIZE * 3)) {
const u32 *K = (const u32 *)key;
u32 flags = CRYPTO_TFM_RES_BAD_KEY_SCHED;
if (!((K[0] ^ K[2]) | (K[1] ^ K[3])) ||
!((K[2] ^ K[4]) | (K[3] ^ K[5]))) {
crypto_ablkcipher_set_flags(cipher, flags);
return -EINVAL;
}
ctx->cipher_type = CIPHER_TYPE_3DES;
} else {
crypto_ablkcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
return 0;
}
static int aes_setkey(struct crypto_ablkcipher *cipher, const u8 *key,
unsigned int keylen)
{
struct iproc_ctx_s *ctx = crypto_ablkcipher_ctx(cipher);
if (ctx->cipher.mode == CIPHER_MODE_XTS)
keylen = keylen / 2;
switch (keylen) {
case AES_KEYSIZE_128:
ctx->cipher_type = CIPHER_TYPE_AES128;
break;
case AES_KEYSIZE_192:
ctx->cipher_type = CIPHER_TYPE_AES192;
break;
case AES_KEYSIZE_256:
ctx->cipher_type = CIPHER_TYPE_AES256;
break;
default:
crypto_ablkcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
WARN_ON((ctx->max_payload != SPU_MAX_PAYLOAD_INF) &&
((ctx->max_payload % AES_BLOCK_SIZE) != 0));
return 0;
}
static int rc4_setkey(struct crypto_ablkcipher *cipher, const u8 *key,
unsigned int keylen)
{
struct iproc_ctx_s *ctx = crypto_ablkcipher_ctx(cipher);
int i;
ctx->enckeylen = ARC4_MAX_KEY_SIZE + ARC4_STATE_SIZE;
ctx->enckey[0] = 0x00;
ctx->enckey[1] = 0x00;
ctx->enckey[2] = 0x00;
ctx->enckey[3] = 0x00;
for (i = 0; i < ARC4_MAX_KEY_SIZE; i++)
ctx->enckey[i + ARC4_STATE_SIZE] = key[i % keylen];
ctx->cipher_type = CIPHER_TYPE_INIT;
return 0;
}
static int ablkcipher_setkey(struct crypto_ablkcipher *cipher, const u8 *key,
unsigned int keylen)
{
struct spu_hw *spu = &iproc_priv.spu;
struct iproc_ctx_s *ctx = crypto_ablkcipher_ctx(cipher);
struct spu_cipher_parms cipher_parms;
u32 alloc_len = 0;
int err;
flow_log("ablkcipher_setkey() keylen: %d\n", keylen);
flow_dump(" key: ", key, keylen);
switch (ctx->cipher.alg) {
case CIPHER_ALG_DES:
err = des_setkey(cipher, key, keylen);
break;
case CIPHER_ALG_3DES:
err = threedes_setkey(cipher, key, keylen);
break;
case CIPHER_ALG_AES:
err = aes_setkey(cipher, key, keylen);
break;
case CIPHER_ALG_RC4:
err = rc4_setkey(cipher, key, keylen);
break;
default:
pr_err("%s() Error: unknown cipher alg\n", __func__);
err = -EINVAL;
}
if (err)
return err;
if (ctx->cipher.alg != CIPHER_ALG_RC4) {
memcpy(ctx->enckey, key, keylen);
ctx->enckeylen = keylen;
}
if ((ctx->cipher.alg == CIPHER_ALG_AES) &&
(ctx->cipher.mode == CIPHER_MODE_XTS)) {
unsigned int xts_keylen = keylen / 2;
memcpy(ctx->enckey, key + xts_keylen, xts_keylen);
memcpy(ctx->enckey + xts_keylen, key, xts_keylen);
}
if (spu->spu_type == SPU_TYPE_SPUM)
alloc_len = BCM_HDR_LEN + SPU_HEADER_ALLOC_LEN;
else if (spu->spu_type == SPU_TYPE_SPU2)
alloc_len = BCM_HDR_LEN + SPU2_HEADER_ALLOC_LEN;
memset(ctx->bcm_spu_req_hdr, 0, alloc_len);
cipher_parms.iv_buf = NULL;
cipher_parms.iv_len = crypto_ablkcipher_ivsize(cipher);
flow_log("%s: iv_len %u\n", __func__, cipher_parms.iv_len);
cipher_parms.alg = ctx->cipher.alg;
cipher_parms.mode = ctx->cipher.mode;
cipher_parms.type = ctx->cipher_type;
cipher_parms.key_buf = ctx->enckey;
cipher_parms.key_len = ctx->enckeylen;
memcpy(ctx->bcm_spu_req_hdr, BCMHEADER, BCM_HDR_LEN);
ctx->spu_req_hdr_len =
spu->spu_cipher_req_init(ctx->bcm_spu_req_hdr + BCM_HDR_LEN,
&cipher_parms);
ctx->spu_resp_hdr_len = spu->spu_response_hdr_len(ctx->authkeylen,
ctx->enckeylen,
false);
atomic_inc(&iproc_priv.setkey_cnt[SPU_OP_CIPHER]);
return 0;
}
static int ablkcipher_encrypt(struct ablkcipher_request *req)
{
flow_log("ablkcipher_encrypt() nbytes:%u\n", req->nbytes);
return ablkcipher_enqueue(req, true);
}
static int ablkcipher_decrypt(struct ablkcipher_request *req)
{
flow_log("ablkcipher_decrypt() nbytes:%u\n", req->nbytes);
return ablkcipher_enqueue(req, false);
}
static int ahash_enqueue(struct ahash_request *req)
{
struct iproc_reqctx_s *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct iproc_ctx_s *ctx = crypto_ahash_ctx(tfm);
int err = 0;
const char *alg_name;
flow_log("ahash_enqueue() nbytes:%u\n", req->nbytes);
rctx->gfp = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
rctx->parent = &req->base;
rctx->ctx = ctx;
rctx->bd_suppress = true;
memset(&rctx->mb_mssg, 0, sizeof(struct brcm_message));
rctx->src_sg = req->src;
rctx->src_skip = 0;
rctx->src_nents = 0;
rctx->dst_sg = NULL;
rctx->dst_skip = 0;
rctx->dst_nents = 0;
if ((rctx->is_final == 1) && (rctx->total_todo == 0) &&
(iproc_priv.spu.spu_type == SPU_TYPE_SPU2)) {
alg_name = crypto_tfm_alg_name(crypto_ahash_tfm(tfm));
flow_log("Doing %sfinal %s zero-len hash request in software\n",
rctx->is_final ? "" : "non-", alg_name);
err = do_shash((unsigned char *)alg_name, req->result,
NULL, 0, NULL, 0, ctx->authkey,
ctx->authkeylen);
if (err < 0)
flow_log("Hash request failed with error %d\n", err);
return err;
}
rctx->chan_idx = select_channel();
err = handle_ahash_req(rctx);
if (err != -EINPROGRESS)
spu_chunk_cleanup(rctx);
if (err == -EAGAIN)
err = 0;
return err;
}
static int __ahash_init(struct ahash_request *req)
{
struct spu_hw *spu = &iproc_priv.spu;
struct iproc_reqctx_s *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct iproc_ctx_s *ctx = crypto_ahash_ctx(tfm);
flow_log("%s()\n", __func__);
rctx->hash_carry_len = 0;
rctx->is_final = 0;
rctx->total_todo = 0;
rctx->src_sent = 0;
rctx->total_sent = 0;
rctx->total_received = 0;
ctx->digestsize = crypto_ahash_digestsize(tfm);
WARN_ON(ctx->digestsize > MAX_DIGEST_SIZE);
rctx->is_sw_hmac = false;
ctx->spu_resp_hdr_len = spu->spu_response_hdr_len(ctx->authkeylen, 0,
true);
return 0;
}
bool spu_no_incr_hash(struct iproc_ctx_s *ctx)
{
struct spu_hw *spu = &iproc_priv.spu;
if (spu->spu_type == SPU_TYPE_SPU2)
return true;
if ((ctx->auth.alg == HASH_ALG_AES) &&
(ctx->auth.mode == HASH_MODE_XCBC))
return true;
return false;
}
static int ahash_init(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct iproc_ctx_s *ctx = crypto_ahash_ctx(tfm);
const char *alg_name;
struct crypto_shash *hash;
int ret;
gfp_t gfp;
if (spu_no_incr_hash(ctx)) {
alg_name = crypto_tfm_alg_name(crypto_ahash_tfm(tfm));
hash = crypto_alloc_shash(alg_name, 0, 0);
if (IS_ERR(hash)) {
ret = PTR_ERR(hash);
goto err;
}
gfp = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
ctx->shash = kmalloc(sizeof(*ctx->shash) +
crypto_shash_descsize(hash), gfp);
if (!ctx->shash) {
ret = -ENOMEM;
goto err_hash;
}
ctx->shash->tfm = hash;
ctx->shash->flags = 0;
if (ctx->authkeylen > 0) {
ret = crypto_shash_setkey(hash, ctx->authkey,
ctx->authkeylen);
if (ret)
goto err_shash;
}
ret = crypto_shash_init(ctx->shash);
if (ret)
goto err_shash;
} else {
ret = __ahash_init(req);
}
return ret;
err_shash:
kfree(ctx->shash);
err_hash:
crypto_free_shash(hash);
err:
return ret;
}
static int __ahash_update(struct ahash_request *req)
{
struct iproc_reqctx_s *rctx = ahash_request_ctx(req);
flow_log("ahash_update() nbytes:%u\n", req->nbytes);
if (!req->nbytes)
return 0;
rctx->total_todo += req->nbytes;
rctx->src_sent = 0;
return ahash_enqueue(req);
}
static int ahash_update(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct iproc_ctx_s *ctx = crypto_ahash_ctx(tfm);
u8 *tmpbuf;
int ret;
int nents;
gfp_t gfp;
if (spu_no_incr_hash(ctx)) {
if (req->src)
nents = sg_nents(req->src);
else
return -EINVAL;
gfp = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
tmpbuf = kmalloc(req->nbytes, gfp);
if (!tmpbuf)
return -ENOMEM;
if (sg_copy_to_buffer(req->src, nents, tmpbuf, req->nbytes) !=
req->nbytes) {
kfree(tmpbuf);
return -EINVAL;
}
ret = crypto_shash_update(ctx->shash, tmpbuf, req->nbytes);
kfree(tmpbuf);
} else {
ret = __ahash_update(req);
}
return ret;
}
static int __ahash_final(struct ahash_request *req)
{
struct iproc_reqctx_s *rctx = ahash_request_ctx(req);
flow_log("ahash_final() nbytes:%u\n", req->nbytes);
rctx->is_final = 1;
return ahash_enqueue(req);
}
static int ahash_final(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct iproc_ctx_s *ctx = crypto_ahash_ctx(tfm);
int ret;
if (spu_no_incr_hash(ctx)) {
ret = crypto_shash_final(ctx->shash, req->result);
crypto_free_shash(ctx->shash->tfm);
kfree(ctx->shash);
} else {
ret = __ahash_final(req);
}
return ret;
}
static int __ahash_finup(struct ahash_request *req)
{
struct iproc_reqctx_s *rctx = ahash_request_ctx(req);
flow_log("ahash_finup() nbytes:%u\n", req->nbytes);
rctx->total_todo += req->nbytes;
rctx->src_sent = 0;
rctx->is_final = 1;
return ahash_enqueue(req);
}
static int ahash_finup(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct iproc_ctx_s *ctx = crypto_ahash_ctx(tfm);
u8 *tmpbuf;
int ret;
int nents;
gfp_t gfp;
if (spu_no_incr_hash(ctx)) {
if (req->src) {
nents = sg_nents(req->src);
} else {
ret = -EINVAL;
goto ahash_finup_exit;
}
gfp = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
tmpbuf = kmalloc(req->nbytes, gfp);
if (!tmpbuf) {
ret = -ENOMEM;
goto ahash_finup_exit;
}
if (sg_copy_to_buffer(req->src, nents, tmpbuf, req->nbytes) !=
req->nbytes) {
ret = -EINVAL;
goto ahash_finup_free;
}
ret = crypto_shash_finup(ctx->shash, tmpbuf, req->nbytes,
req->result);
} else {
return __ahash_finup(req);
}
ahash_finup_free:
kfree(tmpbuf);
ahash_finup_exit:
crypto_free_shash(ctx->shash->tfm);
kfree(ctx->shash);
return ret;
}
static int ahash_digest(struct ahash_request *req)
{
int err = 0;
flow_log("ahash_digest() nbytes:%u\n", req->nbytes);
err = __ahash_init(req);
if (!err)
err = __ahash_finup(req);
return err;
}
static int ahash_setkey(struct crypto_ahash *ahash, const u8 *key,
unsigned int keylen)
{
struct iproc_ctx_s *ctx = crypto_ahash_ctx(ahash);
flow_log("%s() ahash:%p key:%p keylen:%u\n",
__func__, ahash, key, keylen);
flow_dump(" key: ", key, keylen);
if (ctx->auth.alg == HASH_ALG_AES) {
switch (keylen) {
case AES_KEYSIZE_128:
ctx->cipher_type = CIPHER_TYPE_AES128;
break;
case AES_KEYSIZE_192:
ctx->cipher_type = CIPHER_TYPE_AES192;
break;
case AES_KEYSIZE_256:
ctx->cipher_type = CIPHER_TYPE_AES256;
break;
default:
pr_err("%s() Error: Invalid key length\n", __func__);
return -EINVAL;
}
} else {
pr_err("%s() Error: unknown hash alg\n", __func__);
return -EINVAL;
}
memcpy(ctx->authkey, key, keylen);
ctx->authkeylen = keylen;
return 0;
}
static int ahash_export(struct ahash_request *req, void *out)
{
const struct iproc_reqctx_s *rctx = ahash_request_ctx(req);
struct spu_hash_export_s *spu_exp = (struct spu_hash_export_s *)out;
spu_exp->total_todo = rctx->total_todo;
spu_exp->total_sent = rctx->total_sent;
spu_exp->is_sw_hmac = rctx->is_sw_hmac;
memcpy(spu_exp->hash_carry, rctx->hash_carry, sizeof(rctx->hash_carry));
spu_exp->hash_carry_len = rctx->hash_carry_len;
memcpy(spu_exp->incr_hash, rctx->incr_hash, sizeof(rctx->incr_hash));
return 0;
}
static int ahash_import(struct ahash_request *req, const void *in)
{
struct iproc_reqctx_s *rctx = ahash_request_ctx(req);
struct spu_hash_export_s *spu_exp = (struct spu_hash_export_s *)in;
rctx->total_todo = spu_exp->total_todo;
rctx->total_sent = spu_exp->total_sent;
rctx->is_sw_hmac = spu_exp->is_sw_hmac;
memcpy(rctx->hash_carry, spu_exp->hash_carry, sizeof(rctx->hash_carry));
rctx->hash_carry_len = spu_exp->hash_carry_len;
memcpy(rctx->incr_hash, spu_exp->incr_hash, sizeof(rctx->incr_hash));
return 0;
}
static int ahash_hmac_setkey(struct crypto_ahash *ahash, const u8 *key,
unsigned int keylen)
{
struct iproc_ctx_s *ctx = crypto_ahash_ctx(ahash);
unsigned int blocksize =
crypto_tfm_alg_blocksize(crypto_ahash_tfm(ahash));
unsigned int digestsize = crypto_ahash_digestsize(ahash);
unsigned int index;
int rc;
flow_log("%s() ahash:%p key:%p keylen:%u blksz:%u digestsz:%u\n",
__func__, ahash, key, keylen, blocksize, digestsize);
flow_dump(" key: ", key, keylen);
if (keylen > blocksize) {
switch (ctx->auth.alg) {
case HASH_ALG_MD5:
rc = do_shash("md5", ctx->authkey, key, keylen, NULL,
0, NULL, 0);
break;
case HASH_ALG_SHA1:
rc = do_shash("sha1", ctx->authkey, key, keylen, NULL,
0, NULL, 0);
break;
case HASH_ALG_SHA224:
rc = do_shash("sha224", ctx->authkey, key, keylen, NULL,
0, NULL, 0);
break;
case HASH_ALG_SHA256:
rc = do_shash("sha256", ctx->authkey, key, keylen, NULL,
0, NULL, 0);
break;
case HASH_ALG_SHA384:
rc = do_shash("sha384", ctx->authkey, key, keylen, NULL,
0, NULL, 0);
break;
case HASH_ALG_SHA512:
rc = do_shash("sha512", ctx->authkey, key, keylen, NULL,
0, NULL, 0);
break;
case HASH_ALG_SHA3_224:
rc = do_shash("sha3-224", ctx->authkey, key, keylen,
NULL, 0, NULL, 0);
break;
case HASH_ALG_SHA3_256:
rc = do_shash("sha3-256", ctx->authkey, key, keylen,
NULL, 0, NULL, 0);
break;
case HASH_ALG_SHA3_384:
rc = do_shash("sha3-384", ctx->authkey, key, keylen,
NULL, 0, NULL, 0);
break;
case HASH_ALG_SHA3_512:
rc = do_shash("sha3-512", ctx->authkey, key, keylen,
NULL, 0, NULL, 0);
break;
default:
pr_err("%s() Error: unknown hash alg\n", __func__);
return -EINVAL;
}
if (rc < 0) {
pr_err("%s() Error %d computing shash for %s\n",
__func__, rc, hash_alg_name[ctx->auth.alg]);
return rc;
}
ctx->authkeylen = digestsize;
flow_log(" keylen > digestsize... hashed\n");
flow_dump(" newkey: ", ctx->authkey, ctx->authkeylen);
} else {
memcpy(ctx->authkey, key, keylen);
ctx->authkeylen = keylen;
}
if (iproc_priv.spu.spu_type == SPU_TYPE_SPUM) {
memcpy(ctx->ipad, ctx->authkey, ctx->authkeylen);
memset(ctx->ipad + ctx->authkeylen, 0,
blocksize - ctx->authkeylen);
ctx->authkeylen = 0;
memcpy(ctx->opad, ctx->ipad, blocksize);
for (index = 0; index < blocksize; index++) {
ctx->ipad[index] ^= 0x36;
ctx->opad[index] ^= 0x5c;
}
flow_dump(" ipad: ", ctx->ipad, blocksize);
flow_dump(" opad: ", ctx->opad, blocksize);
}
ctx->digestsize = digestsize;
atomic_inc(&iproc_priv.setkey_cnt[SPU_OP_HMAC]);
return 0;
}
static int ahash_hmac_init(struct ahash_request *req)
{
struct iproc_reqctx_s *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct iproc_ctx_s *ctx = crypto_ahash_ctx(tfm);
unsigned int blocksize =
crypto_tfm_alg_blocksize(crypto_ahash_tfm(tfm));
flow_log("ahash_hmac_init()\n");
ahash_init(req);
if (!spu_no_incr_hash(ctx)) {
rctx->is_sw_hmac = true;
ctx->auth.mode = HASH_MODE_HASH;
memcpy(rctx->hash_carry, ctx->ipad, blocksize);
rctx->hash_carry_len = blocksize;
rctx->total_todo += blocksize;
}
return 0;
}
static int ahash_hmac_update(struct ahash_request *req)
{
flow_log("ahash_hmac_update() nbytes:%u\n", req->nbytes);
if (!req->nbytes)
return 0;
return ahash_update(req);
}
static int ahash_hmac_final(struct ahash_request *req)
{
flow_log("ahash_hmac_final() nbytes:%u\n", req->nbytes);
return ahash_final(req);
}
static int ahash_hmac_finup(struct ahash_request *req)
{
flow_log("ahash_hmac_finupl() nbytes:%u\n", req->nbytes);
return ahash_finup(req);
}
static int ahash_hmac_digest(struct ahash_request *req)
{
struct iproc_reqctx_s *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct iproc_ctx_s *ctx = crypto_ahash_ctx(tfm);
unsigned int blocksize =
crypto_tfm_alg_blocksize(crypto_ahash_tfm(tfm));
flow_log("ahash_hmac_digest() nbytes:%u\n", req->nbytes);
__ahash_init(req);
if (iproc_priv.spu.spu_type == SPU_TYPE_SPU2) {
rctx->is_sw_hmac = false;
ctx->auth.mode = HASH_MODE_HMAC;
} else {
rctx->is_sw_hmac = true;
ctx->auth.mode = HASH_MODE_HASH;
memcpy(rctx->hash_carry, ctx->ipad, blocksize);
rctx->hash_carry_len = blocksize;
rctx->total_todo += blocksize;
}
return __ahash_finup(req);
}
static int aead_need_fallback(struct aead_request *req)
{
struct iproc_reqctx_s *rctx = aead_request_ctx(req);
struct spu_hw *spu = &iproc_priv.spu;
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct iproc_ctx_s *ctx = crypto_aead_ctx(aead);
u32 payload_len;
if (((ctx->cipher.mode == CIPHER_MODE_GCM) ||
(ctx->cipher.mode == CIPHER_MODE_CCM)) &&
(req->assoclen == 0)) {
if ((rctx->is_encrypt && (req->cryptlen == 0)) ||
(!rctx->is_encrypt && (req->cryptlen == ctx->digestsize))) {
flow_log("AES GCM/CCM needs fallback for 0 len req\n");
return 1;
}
}
if ((ctx->cipher.mode == CIPHER_MODE_CCM) &&
(spu->spu_type == SPU_TYPE_SPUM) &&
(ctx->digestsize != 8) && (ctx->digestsize != 12) &&
(ctx->digestsize != 16)) {
flow_log("%s() AES CCM needs fallbck for digest size %d\n",
__func__, ctx->digestsize);
return 1;
}
if ((ctx->cipher.mode == CIPHER_MODE_CCM) &&
(spu->spu_subtype == SPU_SUBTYPE_SPUM_NSP) &&
(req->assoclen == 0)) {
flow_log("%s() AES_CCM needs fallback for 0 len AAD on NSP\n",
__func__);
return 1;
}
payload_len = req->cryptlen;
if (spu->spu_type == SPU_TYPE_SPUM)
payload_len += req->assoclen;
flow_log("%s() payload len: %u\n", __func__, payload_len);
if (ctx->max_payload == SPU_MAX_PAYLOAD_INF)
return 0;
else
return payload_len > ctx->max_payload;
}
static void aead_complete(struct crypto_async_request *areq, int err)
{
struct aead_request *req =
container_of(areq, struct aead_request, base);
struct iproc_reqctx_s *rctx = aead_request_ctx(req);
struct crypto_aead *aead = crypto_aead_reqtfm(req);
flow_log("%s() err:%d\n", __func__, err);
areq->tfm = crypto_aead_tfm(aead);
areq->complete = rctx->old_complete;
areq->data = rctx->old_data;
areq->complete(areq, err);
}
static int aead_do_fallback(struct aead_request *req, bool is_encrypt)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct crypto_tfm *tfm = crypto_aead_tfm(aead);
struct iproc_reqctx_s *rctx = aead_request_ctx(req);
struct iproc_ctx_s *ctx = crypto_tfm_ctx(tfm);
int err;
u32 req_flags;
flow_log("%s() enc:%u\n", __func__, is_encrypt);
if (ctx->fallback_cipher) {
rctx->old_tfm = tfm;
aead_request_set_tfm(req, ctx->fallback_cipher);
rctx->old_complete = req->base.complete;
rctx->old_data = req->base.data;
req_flags = aead_request_flags(req);
aead_request_set_callback(req, req_flags, aead_complete, req);
err = is_encrypt ? crypto_aead_encrypt(req) :
crypto_aead_decrypt(req);
if (err == 0) {
aead_request_set_callback(req, req_flags,
rctx->old_complete, req);
req->base.data = rctx->old_data;
aead_request_set_tfm(req, aead);
flow_log("%s() fallback completed successfully\n\n",
__func__);
}
} else {
err = -EINVAL;
}
return err;
}
static int aead_enqueue(struct aead_request *req, bool is_encrypt)
{
struct iproc_reqctx_s *rctx = aead_request_ctx(req);
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct iproc_ctx_s *ctx = crypto_aead_ctx(aead);
int err;
flow_log("%s() enc:%u\n", __func__, is_encrypt);
if (req->assoclen > MAX_ASSOC_SIZE) {
pr_err
("%s() Error: associated data too long. (%u > %u bytes)\n",
__func__, req->assoclen, MAX_ASSOC_SIZE);
return -EINVAL;
}
rctx->gfp = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
rctx->parent = &req->base;
rctx->is_encrypt = is_encrypt;
rctx->bd_suppress = false;
rctx->total_todo = req->cryptlen;
rctx->src_sent = 0;
rctx->total_sent = 0;
rctx->total_received = 0;
rctx->is_sw_hmac = false;
rctx->ctx = ctx;
memset(&rctx->mb_mssg, 0, sizeof(struct brcm_message));
rctx->assoc = req->src;
if (spu_sg_at_offset(req->src, req->assoclen, &rctx->src_sg,
&rctx->src_skip) < 0) {
pr_err("%s() Error: Unable to find start of src data\n",
__func__);
return -EINVAL;
}
rctx->src_nents = 0;
rctx->dst_nents = 0;
if (req->dst == req->src) {
rctx->dst_sg = rctx->src_sg;
rctx->dst_skip = rctx->src_skip;
} else {
if (spu_sg_at_offset(req->dst, req->assoclen, &rctx->dst_sg,
&rctx->dst_skip) < 0) {
pr_err("%s() Error: Unable to find start of dst data\n",
__func__);
return -EINVAL;
}
}
if (ctx->cipher.mode == CIPHER_MODE_CBC ||
ctx->cipher.mode == CIPHER_MODE_CTR ||
ctx->cipher.mode == CIPHER_MODE_OFB ||
ctx->cipher.mode == CIPHER_MODE_XTS ||
ctx->cipher.mode == CIPHER_MODE_GCM) {
rctx->iv_ctr_len =
ctx->salt_len +
crypto_aead_ivsize(crypto_aead_reqtfm(req));
} else if (ctx->cipher.mode == CIPHER_MODE_CCM) {
rctx->iv_ctr_len = CCM_AES_IV_SIZE;
} else {
rctx->iv_ctr_len = 0;
}
rctx->hash_carry_len = 0;
flow_log(" src sg: %p\n", req->src);
flow_log(" rctx->src_sg: %p, src_skip %u\n",
rctx->src_sg, rctx->src_skip);
flow_log(" assoc: %p, assoclen %u\n", rctx->assoc, req->assoclen);
flow_log(" dst sg: %p\n", req->dst);
flow_log(" rctx->dst_sg: %p, dst_skip %u\n",
rctx->dst_sg, rctx->dst_skip);
flow_log(" iv_ctr_len:%u\n", rctx->iv_ctr_len);
flow_dump(" iv: ", req->iv, rctx->iv_ctr_len);
flow_log(" authkeylen:%u\n", ctx->authkeylen);
flow_log(" is_esp: %s\n", ctx->is_esp ? "yes" : "no");
if (ctx->max_payload == SPU_MAX_PAYLOAD_INF)
flow_log(" max_payload infinite");
else
flow_log(" max_payload: %u\n", ctx->max_payload);
if (unlikely(aead_need_fallback(req)))
return aead_do_fallback(req, is_encrypt);
if (rctx->iv_ctr_len) {
if (ctx->salt_len)
memcpy(rctx->msg_buf.iv_ctr + ctx->salt_offset,
ctx->salt, ctx->salt_len);
memcpy(rctx->msg_buf.iv_ctr + ctx->salt_offset + ctx->salt_len,
req->iv,
rctx->iv_ctr_len - ctx->salt_len - ctx->salt_offset);
}
rctx->chan_idx = select_channel();
err = handle_aead_req(rctx);
if (err != -EINPROGRESS)
spu_chunk_cleanup(rctx);
return err;
}
static int aead_authenc_setkey(struct crypto_aead *cipher,
const u8 *key, unsigned int keylen)
{
struct spu_hw *spu = &iproc_priv.spu;
struct iproc_ctx_s *ctx = crypto_aead_ctx(cipher);
struct crypto_tfm *tfm = crypto_aead_tfm(cipher);
struct rtattr *rta = (void *)key;
struct crypto_authenc_key_param *param;
const u8 *origkey = key;
const unsigned int origkeylen = keylen;
int ret = 0;
flow_log("%s() aead:%p key:%p keylen:%u\n", __func__, cipher, key,
keylen);
flow_dump(" key: ", key, keylen);
if (!RTA_OK(rta, keylen))
goto badkey;
if (rta->rta_type != CRYPTO_AUTHENC_KEYA_PARAM)
goto badkey;
if (RTA_PAYLOAD(rta) < sizeof(*param))
goto badkey;
param = RTA_DATA(rta);
ctx->enckeylen = be32_to_cpu(param->enckeylen);
key += RTA_ALIGN(rta->rta_len);
keylen -= RTA_ALIGN(rta->rta_len);
if (keylen < ctx->enckeylen)
goto badkey;
if (ctx->enckeylen > MAX_KEY_SIZE)
goto badkey;
ctx->authkeylen = keylen - ctx->enckeylen;
if (ctx->authkeylen > MAX_KEY_SIZE)
goto badkey;
memcpy(ctx->enckey, key + ctx->authkeylen, ctx->enckeylen);
memset(ctx->authkey, 0, sizeof(ctx->authkey));
memcpy(ctx->authkey, key, ctx->authkeylen);
switch (ctx->alg->cipher_info.alg) {
case CIPHER_ALG_DES:
if (ctx->enckeylen == DES_KEY_SIZE) {
u32 tmp[DES_EXPKEY_WORDS];
u32 flags = CRYPTO_TFM_RES_WEAK_KEY;
if (des_ekey(tmp, key) == 0) {
if (crypto_aead_get_flags(cipher) &
CRYPTO_TFM_REQ_WEAK_KEY) {
crypto_aead_set_flags(cipher, flags);
return -EINVAL;
}
}
ctx->cipher_type = CIPHER_TYPE_DES;
} else {
goto badkey;
}
break;
case CIPHER_ALG_3DES:
if (ctx->enckeylen == (DES_KEY_SIZE * 3)) {
const u32 *K = (const u32 *)key;
u32 flags = CRYPTO_TFM_RES_BAD_KEY_SCHED;
if (!((K[0] ^ K[2]) | (K[1] ^ K[3])) ||
!((K[2] ^ K[4]) | (K[3] ^ K[5]))) {
crypto_aead_set_flags(cipher, flags);
return -EINVAL;
}
ctx->cipher_type = CIPHER_TYPE_3DES;
} else {
crypto_aead_set_flags(cipher,
CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
break;
case CIPHER_ALG_AES:
switch (ctx->enckeylen) {
case AES_KEYSIZE_128:
ctx->cipher_type = CIPHER_TYPE_AES128;
break;
case AES_KEYSIZE_192:
ctx->cipher_type = CIPHER_TYPE_AES192;
break;
case AES_KEYSIZE_256:
ctx->cipher_type = CIPHER_TYPE_AES256;
break;
default:
goto badkey;
}
break;
case CIPHER_ALG_RC4:
ctx->cipher_type = CIPHER_TYPE_INIT;
break;
default:
pr_err("%s() Error: Unknown cipher alg\n", __func__);
return -EINVAL;
}
flow_log(" enckeylen:%u authkeylen:%u\n", ctx->enckeylen,
ctx->authkeylen);
flow_dump(" enc: ", ctx->enckey, ctx->enckeylen);
flow_dump(" auth: ", ctx->authkey, ctx->authkeylen);
if (ctx->fallback_cipher) {
flow_log(" running fallback setkey()\n");
ctx->fallback_cipher->base.crt_flags &= ~CRYPTO_TFM_REQ_MASK;
ctx->fallback_cipher->base.crt_flags |=
tfm->crt_flags & CRYPTO_TFM_REQ_MASK;
ret =
crypto_aead_setkey(ctx->fallback_cipher, origkey,
origkeylen);
if (ret) {
flow_log(" fallback setkey() returned:%d\n", ret);
tfm->crt_flags &= ~CRYPTO_TFM_RES_MASK;
tfm->crt_flags |=
(ctx->fallback_cipher->base.crt_flags &
CRYPTO_TFM_RES_MASK);
}
}
ctx->spu_resp_hdr_len = spu->spu_response_hdr_len(ctx->authkeylen,
ctx->enckeylen,
false);
atomic_inc(&iproc_priv.setkey_cnt[SPU_OP_AEAD]);
return ret;
badkey:
ctx->enckeylen = 0;
ctx->authkeylen = 0;
ctx->digestsize = 0;
crypto_aead_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static int aead_gcm_ccm_setkey(struct crypto_aead *cipher,
const u8 *key, unsigned int keylen)
{
struct spu_hw *spu = &iproc_priv.spu;
struct iproc_ctx_s *ctx = crypto_aead_ctx(cipher);
struct crypto_tfm *tfm = crypto_aead_tfm(cipher);
int ret = 0;
flow_log("%s() keylen:%u\n", __func__, keylen);
flow_dump(" key: ", key, keylen);
if (!ctx->is_esp)
ctx->digestsize = keylen;
ctx->enckeylen = keylen;
ctx->authkeylen = 0;
memcpy(ctx->enckey, key, ctx->enckeylen);
switch (ctx->enckeylen) {
case AES_KEYSIZE_128:
ctx->cipher_type = CIPHER_TYPE_AES128;
break;
case AES_KEYSIZE_192:
ctx->cipher_type = CIPHER_TYPE_AES192;
break;
case AES_KEYSIZE_256:
ctx->cipher_type = CIPHER_TYPE_AES256;
break;
default:
goto badkey;
}
flow_log(" enckeylen:%u authkeylen:%u\n", ctx->enckeylen,
ctx->authkeylen);
flow_dump(" enc: ", ctx->enckey, ctx->enckeylen);
flow_dump(" auth: ", ctx->authkey, ctx->authkeylen);
if (ctx->fallback_cipher) {
flow_log(" running fallback setkey()\n");
ctx->fallback_cipher->base.crt_flags &= ~CRYPTO_TFM_REQ_MASK;
ctx->fallback_cipher->base.crt_flags |=
tfm->crt_flags & CRYPTO_TFM_REQ_MASK;
ret = crypto_aead_setkey(ctx->fallback_cipher, key,
keylen + ctx->salt_len);
if (ret) {
flow_log(" fallback setkey() returned:%d\n", ret);
tfm->crt_flags &= ~CRYPTO_TFM_RES_MASK;
tfm->crt_flags |=
(ctx->fallback_cipher->base.crt_flags &
CRYPTO_TFM_RES_MASK);
}
}
ctx->spu_resp_hdr_len = spu->spu_response_hdr_len(ctx->authkeylen,
ctx->enckeylen,
false);
atomic_inc(&iproc_priv.setkey_cnt[SPU_OP_AEAD]);
flow_log(" enckeylen:%u authkeylen:%u\n", ctx->enckeylen,
ctx->authkeylen);
return ret;
badkey:
ctx->enckeylen = 0;
ctx->authkeylen = 0;
ctx->digestsize = 0;
crypto_aead_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static int aead_gcm_esp_setkey(struct crypto_aead *cipher,
const u8 *key, unsigned int keylen)
{
struct iproc_ctx_s *ctx = crypto_aead_ctx(cipher);
flow_log("%s\n", __func__);
ctx->salt_len = GCM_ESP_SALT_SIZE;
ctx->salt_offset = GCM_ESP_SALT_OFFSET;
memcpy(ctx->salt, key + keylen - GCM_ESP_SALT_SIZE, GCM_ESP_SALT_SIZE);
keylen -= GCM_ESP_SALT_SIZE;
ctx->digestsize = GCM_ESP_DIGESTSIZE;
ctx->is_esp = true;
flow_dump("salt: ", ctx->salt, GCM_ESP_SALT_SIZE);
return aead_gcm_ccm_setkey(cipher, key, keylen);
}
static int rfc4543_gcm_esp_setkey(struct crypto_aead *cipher,
const u8 *key, unsigned int keylen)
{
struct iproc_ctx_s *ctx = crypto_aead_ctx(cipher);
flow_log("%s\n", __func__);
ctx->salt_len = GCM_ESP_SALT_SIZE;
ctx->salt_offset = GCM_ESP_SALT_OFFSET;
memcpy(ctx->salt, key + keylen - GCM_ESP_SALT_SIZE, GCM_ESP_SALT_SIZE);
keylen -= GCM_ESP_SALT_SIZE;
ctx->digestsize = GCM_ESP_DIGESTSIZE;
ctx->is_esp = true;
ctx->is_rfc4543 = true;
flow_dump("salt: ", ctx->salt, GCM_ESP_SALT_SIZE);
return aead_gcm_ccm_setkey(cipher, key, keylen);
}
static int aead_ccm_esp_setkey(struct crypto_aead *cipher,
const u8 *key, unsigned int keylen)
{
struct iproc_ctx_s *ctx = crypto_aead_ctx(cipher);
flow_log("%s\n", __func__);
ctx->salt_len = CCM_ESP_SALT_SIZE;
ctx->salt_offset = CCM_ESP_SALT_OFFSET;
memcpy(ctx->salt, key + keylen - CCM_ESP_SALT_SIZE, CCM_ESP_SALT_SIZE);
keylen -= CCM_ESP_SALT_SIZE;
ctx->is_esp = true;
flow_dump("salt: ", ctx->salt, CCM_ESP_SALT_SIZE);
return aead_gcm_ccm_setkey(cipher, key, keylen);
}
static int aead_setauthsize(struct crypto_aead *cipher, unsigned int authsize)
{
struct iproc_ctx_s *ctx = crypto_aead_ctx(cipher);
int ret = 0;
flow_log("%s() authkeylen:%u authsize:%u\n",
__func__, ctx->authkeylen, authsize);
ctx->digestsize = authsize;
if (ctx->fallback_cipher) {
flow_log(" running fallback setauth()\n");
ret = crypto_aead_setauthsize(ctx->fallback_cipher, authsize);
if (ret)
flow_log(" fallback setauth() returned:%d\n", ret);
}
return ret;
}
static int aead_encrypt(struct aead_request *req)
{
flow_log("%s() cryptlen:%u %08x\n", __func__, req->cryptlen,
req->cryptlen);
dump_sg(req->src, 0, req->cryptlen + req->assoclen);
flow_log(" assoc_len:%u\n", req->assoclen);
return aead_enqueue(req, true);
}
static int aead_decrypt(struct aead_request *req)
{
flow_log("%s() cryptlen:%u\n", __func__, req->cryptlen);
dump_sg(req->src, 0, req->cryptlen + req->assoclen);
flow_log(" assoc_len:%u\n", req->assoclen);
return aead_enqueue(req, false);
}
static int generic_cra_init(struct crypto_tfm *tfm,
struct iproc_alg_s *cipher_alg)
{
struct spu_hw *spu = &iproc_priv.spu;
struct iproc_ctx_s *ctx = crypto_tfm_ctx(tfm);
unsigned int blocksize = crypto_tfm_alg_blocksize(tfm);
flow_log("%s()\n", __func__);
ctx->alg = cipher_alg;
ctx->cipher = cipher_alg->cipher_info;
ctx->auth = cipher_alg->auth_info;
ctx->auth_first = cipher_alg->auth_first;
ctx->max_payload = spu->spu_ctx_max_payload(ctx->cipher.alg,
ctx->cipher.mode,
blocksize);
ctx->fallback_cipher = NULL;
ctx->enckeylen = 0;
ctx->authkeylen = 0;
atomic_inc(&iproc_priv.stream_count);
atomic_inc(&iproc_priv.session_count);
return 0;
}
static int ablkcipher_cra_init(struct crypto_tfm *tfm)
{
struct crypto_alg *alg = tfm->__crt_alg;
struct iproc_alg_s *cipher_alg;
flow_log("%s()\n", __func__);
tfm->crt_ablkcipher.reqsize = sizeof(struct iproc_reqctx_s);
cipher_alg = container_of(alg, struct iproc_alg_s, alg.crypto);
return generic_cra_init(tfm, cipher_alg);
}
static int ahash_cra_init(struct crypto_tfm *tfm)
{
int err;
struct crypto_alg *alg = tfm->__crt_alg;
struct iproc_alg_s *cipher_alg;
cipher_alg = container_of(__crypto_ahash_alg(alg), struct iproc_alg_s,
alg.hash);
err = generic_cra_init(tfm, cipher_alg);
flow_log("%s()\n", __func__);
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct iproc_reqctx_s));
return err;
}
static int aead_cra_init(struct crypto_aead *aead)
{
struct crypto_tfm *tfm = crypto_aead_tfm(aead);
struct iproc_ctx_s *ctx = crypto_tfm_ctx(tfm);
struct crypto_alg *alg = tfm->__crt_alg;
struct aead_alg *aalg = container_of(alg, struct aead_alg, base);
struct iproc_alg_s *cipher_alg = container_of(aalg, struct iproc_alg_s,
alg.aead);
int err = generic_cra_init(tfm, cipher_alg);
flow_log("%s()\n", __func__);
crypto_aead_set_reqsize(aead, sizeof(struct iproc_reqctx_s));
ctx->is_esp = false;
ctx->salt_len = 0;
ctx->salt_offset = 0;
get_random_bytes(ctx->iv, MAX_IV_SIZE);
flow_dump(" iv: ", ctx->iv, MAX_IV_SIZE);
if (!err) {
if (alg->cra_flags & CRYPTO_ALG_NEED_FALLBACK) {
flow_log("%s() creating fallback cipher\n", __func__);
ctx->fallback_cipher =
crypto_alloc_aead(alg->cra_name, 0,
CRYPTO_ALG_ASYNC |
CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(ctx->fallback_cipher)) {
pr_err("%s() Error: failed to allocate fallback for %s\n",
__func__, alg->cra_name);
return PTR_ERR(ctx->fallback_cipher);
}
}
}
return err;
}
static void generic_cra_exit(struct crypto_tfm *tfm)
{
atomic_dec(&iproc_priv.session_count);
}
static void aead_cra_exit(struct crypto_aead *aead)
{
struct crypto_tfm *tfm = crypto_aead_tfm(aead);
struct iproc_ctx_s *ctx = crypto_tfm_ctx(tfm);
generic_cra_exit(tfm);
if (ctx->fallback_cipher) {
crypto_free_aead(ctx->fallback_cipher);
ctx->fallback_cipher = NULL;
}
}
static void spu_functions_register(struct device *dev,
enum spu_spu_type spu_type,
enum spu_spu_subtype spu_subtype)
{
struct spu_hw *spu = &iproc_priv.spu;
if (spu_type == SPU_TYPE_SPUM) {
dev_dbg(dev, "Registering SPUM functions");
spu->spu_dump_msg_hdr = spum_dump_msg_hdr;
spu->spu_payload_length = spum_payload_length;
spu->spu_response_hdr_len = spum_response_hdr_len;
spu->spu_hash_pad_len = spum_hash_pad_len;
spu->spu_gcm_ccm_pad_len = spum_gcm_ccm_pad_len;
spu->spu_assoc_resp_len = spum_assoc_resp_len;
spu->spu_aead_ivlen = spum_aead_ivlen;
spu->spu_hash_type = spum_hash_type;
spu->spu_digest_size = spum_digest_size;
spu->spu_create_request = spum_create_request;
spu->spu_cipher_req_init = spum_cipher_req_init;
spu->spu_cipher_req_finish = spum_cipher_req_finish;
spu->spu_request_pad = spum_request_pad;
spu->spu_tx_status_len = spum_tx_status_len;
spu->spu_rx_status_len = spum_rx_status_len;
spu->spu_status_process = spum_status_process;
spu->spu_xts_tweak_in_payload = spum_xts_tweak_in_payload;
spu->spu_ccm_update_iv = spum_ccm_update_iv;
spu->spu_wordalign_padlen = spum_wordalign_padlen;
if (spu_subtype == SPU_SUBTYPE_SPUM_NS2)
spu->spu_ctx_max_payload = spum_ns2_ctx_max_payload;
else
spu->spu_ctx_max_payload = spum_nsp_ctx_max_payload;
} else {
dev_dbg(dev, "Registering SPU2 functions");
spu->spu_dump_msg_hdr = spu2_dump_msg_hdr;
spu->spu_ctx_max_payload = spu2_ctx_max_payload;
spu->spu_payload_length = spu2_payload_length;
spu->spu_response_hdr_len = spu2_response_hdr_len;
spu->spu_hash_pad_len = spu2_hash_pad_len;
spu->spu_gcm_ccm_pad_len = spu2_gcm_ccm_pad_len;
spu->spu_assoc_resp_len = spu2_assoc_resp_len;
spu->spu_aead_ivlen = spu2_aead_ivlen;
spu->spu_hash_type = spu2_hash_type;
spu->spu_digest_size = spu2_digest_size;
spu->spu_create_request = spu2_create_request;
spu->spu_cipher_req_init = spu2_cipher_req_init;
spu->spu_cipher_req_finish = spu2_cipher_req_finish;
spu->spu_request_pad = spu2_request_pad;
spu->spu_tx_status_len = spu2_tx_status_len;
spu->spu_rx_status_len = spu2_rx_status_len;
spu->spu_status_process = spu2_status_process;
spu->spu_xts_tweak_in_payload = spu2_xts_tweak_in_payload;
spu->spu_ccm_update_iv = spu2_ccm_update_iv;
spu->spu_wordalign_padlen = spu2_wordalign_padlen;
}
}
static int spu_mb_init(struct device *dev)
{
struct mbox_client *mcl = &iproc_priv.mcl[iproc_priv.spu.num_spu];
int err;
mcl->dev = dev;
mcl->tx_block = false;
mcl->tx_tout = 0;
mcl->knows_txdone = false;
mcl->rx_callback = spu_rx_callback;
mcl->tx_done = NULL;
iproc_priv.mbox[iproc_priv.spu.num_spu] =
mbox_request_channel(mcl, 0);
if (IS_ERR(iproc_priv.mbox[iproc_priv.spu.num_spu])) {
err = (int)PTR_ERR(iproc_priv.mbox[iproc_priv.spu.num_spu]);
dev_err(dev,
"Mbox channel %d request failed with err %d",
iproc_priv.spu.num_spu, err);
iproc_priv.mbox[iproc_priv.spu.num_spu] = NULL;
return err;
}
return 0;
}
static void spu_mb_release(struct platform_device *pdev)
{
int i;
for (i = 0; i < iproc_priv.spu.num_spu; i++)
mbox_free_channel(iproc_priv.mbox[i]);
}
static void spu_counters_init(void)
{
int i;
int j;
atomic_set(&iproc_priv.session_count, 0);
atomic_set(&iproc_priv.stream_count, 0);
atomic_set(&iproc_priv.next_chan, (int)iproc_priv.spu.num_spu);
atomic64_set(&iproc_priv.bytes_in, 0);
atomic64_set(&iproc_priv.bytes_out, 0);
for (i = 0; i < SPU_OP_NUM; i++) {
atomic_set(&iproc_priv.op_counts[i], 0);
atomic_set(&iproc_priv.setkey_cnt[i], 0);
}
for (i = 0; i < CIPHER_ALG_LAST; i++)
for (j = 0; j < CIPHER_MODE_LAST; j++)
atomic_set(&iproc_priv.cipher_cnt[i][j], 0);
for (i = 0; i < HASH_ALG_LAST; i++) {
atomic_set(&iproc_priv.hash_cnt[i], 0);
atomic_set(&iproc_priv.hmac_cnt[i], 0);
}
for (i = 0; i < AEAD_TYPE_LAST; i++)
atomic_set(&iproc_priv.aead_cnt[i], 0);
atomic_set(&iproc_priv.mb_no_spc, 0);
atomic_set(&iproc_priv.mb_send_fail, 0);
atomic_set(&iproc_priv.bad_icv, 0);
}
static int spu_register_ablkcipher(struct iproc_alg_s *driver_alg)
{
struct spu_hw *spu = &iproc_priv.spu;
struct crypto_alg *crypto = &driver_alg->alg.crypto;
int err;
if ((driver_alg->cipher_info.alg == CIPHER_ALG_RC4) &&
(spu->spu_type == SPU_TYPE_SPU2))
return 0;
crypto->cra_module = THIS_MODULE;
crypto->cra_priority = cipher_pri;
crypto->cra_alignmask = 0;
crypto->cra_ctxsize = sizeof(struct iproc_ctx_s);
INIT_LIST_HEAD(&crypto->cra_list);
crypto->cra_init = ablkcipher_cra_init;
crypto->cra_exit = generic_cra_exit;
crypto->cra_type = &crypto_ablkcipher_type;
crypto->cra_flags = CRYPTO_ALG_TYPE_ABLKCIPHER | CRYPTO_ALG_ASYNC |
CRYPTO_ALG_KERN_DRIVER_ONLY;
crypto->cra_ablkcipher.setkey = ablkcipher_setkey;
crypto->cra_ablkcipher.encrypt = ablkcipher_encrypt;
crypto->cra_ablkcipher.decrypt = ablkcipher_decrypt;
err = crypto_register_alg(crypto);
if (err == 0)
driver_alg->registered = true;
pr_debug(" registered ablkcipher %s\n", crypto->cra_driver_name);
return err;
}
static int spu_register_ahash(struct iproc_alg_s *driver_alg)
{
struct spu_hw *spu = &iproc_priv.spu;
struct ahash_alg *hash = &driver_alg->alg.hash;
int err;
if ((driver_alg->auth_info.alg == HASH_ALG_AES) &&
(driver_alg->auth_info.mode != HASH_MODE_XCBC) &&
(spu->spu_type == SPU_TYPE_SPUM))
return 0;
if ((driver_alg->auth_info.alg >= HASH_ALG_SHA3_224) &&
(spu->spu_subtype != SPU_SUBTYPE_SPU2_V2))
return 0;
hash->halg.base.cra_module = THIS_MODULE;
hash->halg.base.cra_priority = hash_pri;
hash->halg.base.cra_alignmask = 0;
hash->halg.base.cra_ctxsize = sizeof(struct iproc_ctx_s);
hash->halg.base.cra_init = ahash_cra_init;
hash->halg.base.cra_exit = generic_cra_exit;
hash->halg.base.cra_type = &crypto_ahash_type;
hash->halg.base.cra_flags = CRYPTO_ALG_TYPE_AHASH | CRYPTO_ALG_ASYNC;
hash->halg.statesize = sizeof(struct spu_hash_export_s);
if (driver_alg->auth_info.mode != HASH_MODE_HMAC) {
hash->setkey = ahash_setkey;
hash->init = ahash_init;
hash->update = ahash_update;
hash->final = ahash_final;
hash->finup = ahash_finup;
hash->digest = ahash_digest;
} else {
hash->setkey = ahash_hmac_setkey;
hash->init = ahash_hmac_init;
hash->update = ahash_hmac_update;
hash->final = ahash_hmac_final;
hash->finup = ahash_hmac_finup;
hash->digest = ahash_hmac_digest;
}
hash->export = ahash_export;
hash->import = ahash_import;
err = crypto_register_ahash(hash);
if (err == 0)
driver_alg->registered = true;
pr_debug(" registered ahash %s\n",
hash->halg.base.cra_driver_name);
return err;
}
static int spu_register_aead(struct iproc_alg_s *driver_alg)
{
struct aead_alg *aead = &driver_alg->alg.aead;
int err;
aead->base.cra_module = THIS_MODULE;
aead->base.cra_priority = aead_pri;
aead->base.cra_alignmask = 0;
aead->base.cra_ctxsize = sizeof(struct iproc_ctx_s);
INIT_LIST_HEAD(&aead->base.cra_list);
aead->base.cra_flags |= CRYPTO_ALG_TYPE_AEAD | CRYPTO_ALG_ASYNC;
aead->setauthsize = aead_setauthsize;
aead->encrypt = aead_encrypt;
aead->decrypt = aead_decrypt;
aead->init = aead_cra_init;
aead->exit = aead_cra_exit;
err = crypto_register_aead(aead);
if (err == 0)
driver_alg->registered = true;
pr_debug(" registered aead %s\n", aead->base.cra_driver_name);
return err;
}
static int spu_algs_register(struct device *dev)
{
int i, j;
int err;
for (i = 0; i < ARRAY_SIZE(driver_algs); i++) {
switch (driver_algs[i].type) {
case CRYPTO_ALG_TYPE_ABLKCIPHER:
err = spu_register_ablkcipher(&driver_algs[i]);
break;
case CRYPTO_ALG_TYPE_AHASH:
err = spu_register_ahash(&driver_algs[i]);
break;
case CRYPTO_ALG_TYPE_AEAD:
err = spu_register_aead(&driver_algs[i]);
break;
default:
dev_err(dev,
"iproc-crypto: unknown alg type: %d",
driver_algs[i].type);
err = -EINVAL;
}
if (err) {
dev_err(dev, "alg registration failed with error %d\n",
err);
goto err_algs;
}
}
return 0;
err_algs:
for (j = 0; j < i; j++) {
if (!driver_algs[j].registered)
continue;
switch (driver_algs[j].type) {
case CRYPTO_ALG_TYPE_ABLKCIPHER:
crypto_unregister_alg(&driver_algs[j].alg.crypto);
driver_algs[j].registered = false;
break;
case CRYPTO_ALG_TYPE_AHASH:
crypto_unregister_ahash(&driver_algs[j].alg.hash);
driver_algs[j].registered = false;
break;
case CRYPTO_ALG_TYPE_AEAD:
crypto_unregister_aead(&driver_algs[j].alg.aead);
driver_algs[j].registered = false;
break;
}
}
return err;
}
static int spu_dt_read(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct spu_hw *spu = &iproc_priv.spu;
struct resource *spu_ctrl_regs;
const struct of_device_id *match;
const struct spu_type_subtype *matched_spu_type;
void __iomem *spu_reg_vbase[MAX_SPUS];
int err;
match = of_match_device(of_match_ptr(bcm_spu_dt_ids), dev);
matched_spu_type = match->data;
if (iproc_priv.spu.num_spu > 1) {
if ((spu->spu_type != matched_spu_type->type) ||
(spu->spu_subtype != matched_spu_type->subtype)) {
err = -EINVAL;
dev_err(&pdev->dev, "Multiple SPU types not allowed");
return err;
}
} else {
spu->spu_type = matched_spu_type->type;
spu->spu_subtype = matched_spu_type->subtype;
}
spu_ctrl_regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!spu_ctrl_regs) {
err = -EINVAL;
dev_err(&pdev->dev, "Invalid/missing registers for SPU\n");
return err;
}
spu_reg_vbase[iproc_priv.spu.num_spu] =
devm_ioremap_resource(dev, spu_ctrl_regs);
if (IS_ERR(spu_reg_vbase[iproc_priv.spu.num_spu])) {
err = PTR_ERR(spu_reg_vbase[iproc_priv.spu.num_spu]);
dev_err(&pdev->dev, "Failed to map registers: %d\n",
err);
spu_reg_vbase[iproc_priv.spu.num_spu] = NULL;
return err;
}
dev_dbg(dev, "SPU %d detected.", iproc_priv.spu.num_spu);
spu->reg_vbase[iproc_priv.spu.num_spu] = spu_reg_vbase;
return 0;
}
int bcm_spu_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct spu_hw *spu = &iproc_priv.spu;
int err = 0;
iproc_priv.pdev[iproc_priv.spu.num_spu] = pdev;
platform_set_drvdata(iproc_priv.pdev[iproc_priv.spu.num_spu],
&iproc_priv);
err = spu_dt_read(pdev);
if (err < 0)
goto failure;
err = spu_mb_init(&pdev->dev);
if (err < 0)
goto failure;
iproc_priv.spu.num_spu++;
if (iproc_priv.inited)
return 0;
if (spu->spu_type == SPU_TYPE_SPUM)
iproc_priv.bcm_hdr_len = 8;
else if (spu->spu_type == SPU_TYPE_SPU2)
iproc_priv.bcm_hdr_len = 0;
spu_functions_register(&pdev->dev, spu->spu_type, spu->spu_subtype);
spu_counters_init();
spu_setup_debugfs();
err = spu_algs_register(dev);
if (err < 0)
goto fail_reg;
iproc_priv.inited = true;
return 0;
fail_reg:
spu_free_debugfs();
failure:
spu_mb_release(pdev);
dev_err(dev, "%s failed with error %d.\n", __func__, err);
return err;
}
int bcm_spu_remove(struct platform_device *pdev)
{
int i;
struct device *dev = &pdev->dev;
char *cdn;
for (i = 0; i < ARRAY_SIZE(driver_algs); i++) {
if (!driver_algs[i].registered)
continue;
switch (driver_algs[i].type) {
case CRYPTO_ALG_TYPE_ABLKCIPHER:
crypto_unregister_alg(&driver_algs[i].alg.crypto);
dev_dbg(dev, " unregistered cipher %s\n",
driver_algs[i].alg.crypto.cra_driver_name);
driver_algs[i].registered = false;
break;
case CRYPTO_ALG_TYPE_AHASH:
crypto_unregister_ahash(&driver_algs[i].alg.hash);
cdn = driver_algs[i].alg.hash.halg.base.cra_driver_name;
dev_dbg(dev, " unregistered hash %s\n", cdn);
driver_algs[i].registered = false;
break;
case CRYPTO_ALG_TYPE_AEAD:
crypto_unregister_aead(&driver_algs[i].alg.aead);
dev_dbg(dev, " unregistered aead %s\n",
driver_algs[i].alg.aead.base.cra_driver_name);
driver_algs[i].registered = false;
break;
}
}
spu_free_debugfs();
spu_mb_release(pdev);
return 0;
}
