void spum_dump_msg_hdr(u8 *buf, unsigned int buf_len)
{
u8 *ptr = buf;
struct SPUHEADER *spuh = (struct SPUHEADER *)buf;
unsigned int hash_key_len = 0;
unsigned int hash_state_len = 0;
unsigned int cipher_key_len = 0;
unsigned int iv_len;
u32 pflags;
u32 cflags;
u32 ecf;
u32 cipher_alg;
u32 cipher_mode;
u32 cipher_type;
u32 hash_alg;
u32 hash_mode;
u32 hash_type;
u32 sctx_size;
u32 sctx_pl_len;
packet_log("\n");
packet_log("SPU Message header %p len: %u\n", buf, buf_len);
packet_log(" MH 0x%08x\n", be32_to_cpu(*((u32 *)ptr)));
if (spuh->mh.flags & MH_SCTX_PRES)
packet_log(" SCTX present\n");
if (spuh->mh.flags & MH_BDESC_PRES)
packet_log(" BDESC present\n");
if (spuh->mh.flags & MH_MFM_PRES)
packet_log(" MFM present\n");
if (spuh->mh.flags & MH_BD_PRES)
packet_log(" BD present\n");
if (spuh->mh.flags & MH_HASH_PRES)
packet_log(" HASH present\n");
if (spuh->mh.flags & MH_SUPDT_PRES)
packet_log(" SUPDT present\n");
packet_log(" Opcode 0x%02x\n", spuh->mh.op_code);
ptr += sizeof(spuh->mh) + sizeof(spuh->emh);
if (spuh->mh.flags & MH_SCTX_PRES) {
pflags = be32_to_cpu(spuh->sa.proto_flags);
packet_log(" SCTX[0] 0x%08x\n", pflags);
sctx_size = pflags & SCTX_SIZE;
packet_log(" Size %u words\n", sctx_size);
cflags = be32_to_cpu(spuh->sa.cipher_flags);
packet_log(" SCTX[1] 0x%08x\n", cflags);
packet_log(" Inbound:%lu (1:decrypt/vrfy 0:encrypt/auth)\n",
(cflags & CIPHER_INBOUND) >> CIPHER_INBOUND_SHIFT);
packet_log(" Order:%lu (1:AuthFirst 0:EncFirst)\n",
(cflags & CIPHER_ORDER) >> CIPHER_ORDER_SHIFT);
packet_log(" ICV_IS_512:%lx\n",
(cflags & ICV_IS_512) >> ICV_IS_512_SHIFT);
cipher_alg = (cflags & CIPHER_ALG) >> CIPHER_ALG_SHIFT;
cipher_mode = (cflags & CIPHER_MODE) >> CIPHER_MODE_SHIFT;
cipher_type = (cflags & CIPHER_TYPE) >> CIPHER_TYPE_SHIFT;
packet_log(" Crypto Alg:%u Mode:%u Type:%u\n",
cipher_alg, cipher_mode, cipher_type);
hash_alg = (cflags & HASH_ALG) >> HASH_ALG_SHIFT;
hash_mode = (cflags & HASH_MODE) >> HASH_MODE_SHIFT;
hash_type = (cflags & HASH_TYPE) >> HASH_TYPE_SHIFT;
packet_log(" Hash Alg:%x Mode:%x Type:%x\n",
hash_alg, hash_mode, hash_type);
packet_log(" UPDT_Offset:%u\n", cflags & UPDT_OFST);
ecf = be32_to_cpu(spuh->sa.ecf);
packet_log(" SCTX[2] 0x%08x\n", ecf);
packet_log(" WriteICV:%lu CheckICV:%lu ICV_SIZE:%u ",
(ecf & INSERT_ICV) >> INSERT_ICV_SHIFT,
(ecf & CHECK_ICV) >> CHECK_ICV_SHIFT,
(ecf & ICV_SIZE) >> ICV_SIZE_SHIFT);
packet_log("BD_SUPPRESS:%lu\n",
(ecf & BD_SUPPRESS) >> BD_SUPPRESS_SHIFT);
packet_log(" SCTX_IV:%lu ExplicitIV:%lu GenIV:%lu ",
(ecf & SCTX_IV) >> SCTX_IV_SHIFT,
(ecf & EXPLICIT_IV) >> EXPLICIT_IV_SHIFT,
(ecf & GEN_IV) >> GEN_IV_SHIFT);
packet_log("IV_OV_OFST:%lu EXP_IV_SIZE:%u\n",
(ecf & IV_OFFSET) >> IV_OFFSET_SHIFT,
ecf & EXP_IV_SIZE);
ptr += sizeof(struct SCTX);
if (hash_alg && hash_mode) {
char *name = "NONE";
switch (hash_alg) {
case HASH_ALG_MD5:
hash_key_len = 16;
name = "MD5";
break;
case HASH_ALG_SHA1:
hash_key_len = 20;
name = "SHA1";
break;
case HASH_ALG_SHA224:
hash_key_len = 28;
name = "SHA224";
break;
case HASH_ALG_SHA256:
hash_key_len = 32;
name = "SHA256";
break;
case HASH_ALG_SHA384:
hash_key_len = 48;
name = "SHA384";
break;
case HASH_ALG_SHA512:
hash_key_len = 64;
name = "SHA512";
break;
case HASH_ALG_AES:
hash_key_len = 0;
name = "AES";
break;
case HASH_ALG_NONE:
break;
}
packet_log(" Auth Key Type:%s Length:%u Bytes\n",
name, hash_key_len);
packet_dump(" KEY: ", ptr, hash_key_len);
ptr += hash_key_len;
} else if ((hash_alg == HASH_ALG_AES) &&
(hash_mode == HASH_MODE_XCBC)) {
char *name = "NONE";
switch (cipher_type) {
case CIPHER_TYPE_AES128:
hash_key_len = 16;
name = "AES128-XCBC";
break;
case CIPHER_TYPE_AES192:
hash_key_len = 24;
name = "AES192-XCBC";
break;
case CIPHER_TYPE_AES256:
hash_key_len = 32;
name = "AES256-XCBC";
break;
}
packet_log(" Auth Key Type:%s Length:%u Bytes\n",
name, hash_key_len);
packet_dump(" KEY: ", ptr, hash_key_len);
ptr += hash_key_len;
}
if (hash_alg && (hash_mode == HASH_MODE_NONE) &&
(hash_type == HASH_TYPE_UPDT)) {
char *name = "NONE";
switch (hash_alg) {
case HASH_ALG_MD5:
hash_state_len = 16;
name = "MD5";
break;
case HASH_ALG_SHA1:
hash_state_len = 20;
name = "SHA1";
break;
case HASH_ALG_SHA224:
hash_state_len = 32;
name = "SHA224";
break;
case HASH_ALG_SHA256:
hash_state_len = 32;
name = "SHA256";
break;
case HASH_ALG_SHA384:
hash_state_len = 48;
name = "SHA384";
break;
case HASH_ALG_SHA512:
hash_state_len = 64;
name = "SHA512";
break;
case HASH_ALG_AES:
hash_state_len = 0;
name = "AES";
break;
case HASH_ALG_NONE:
break;
}
packet_log(" Auth State Type:%s Length:%u Bytes\n",
name, hash_state_len);
packet_dump(" State: ", ptr, hash_state_len);
ptr += hash_state_len;
}
if (cipher_alg) {
char *name = "NONE";
switch (cipher_alg) {
case CIPHER_ALG_DES:
cipher_key_len = 8;
name = "DES";
break;
case CIPHER_ALG_3DES:
cipher_key_len = 24;
name = "3DES";
break;
case CIPHER_ALG_RC4:
cipher_key_len = 260;
name = "ARC4";
break;
case CIPHER_ALG_AES:
switch (cipher_type) {
case CIPHER_TYPE_AES128:
cipher_key_len = 16;
name = "AES128";
break;
case CIPHER_TYPE_AES192:
cipher_key_len = 24;
name = "AES192";
break;
case CIPHER_TYPE_AES256:
cipher_key_len = 32;
name = "AES256";
break;
}
break;
case CIPHER_ALG_NONE:
break;
}
packet_log(" Cipher Key Type:%s Length:%u Bytes\n",
name, cipher_key_len);
if (cipher_mode == CIPHER_MODE_XTS) {
packet_dump(" KEY2: ", ptr, cipher_key_len);
ptr += cipher_key_len;
packet_dump(" KEY1: ", ptr, cipher_key_len);
ptr += cipher_key_len;
cipher_key_len *= 2;
} else {
packet_dump(" KEY: ", ptr, cipher_key_len);
ptr += cipher_key_len;
}
if (ecf & SCTX_IV) {
sctx_pl_len = sctx_size * sizeof(u32) -
sizeof(struct SCTX);
iv_len = sctx_pl_len -
(hash_key_len + hash_state_len +
cipher_key_len);
packet_log(" IV Length:%u Bytes\n", iv_len);
packet_dump(" IV: ", ptr, iv_len);
ptr += iv_len;
}
}
}
if (spuh->mh.flags & MH_BDESC_PRES) {
#ifdef DEBUG
struct BDESC_HEADER *bdesc = (struct BDESC_HEADER *)ptr;
#endif
packet_log(" BDESC[0] 0x%08x\n", be32_to_cpu(*((u32 *)ptr)));
packet_log(" OffsetMAC:%u LengthMAC:%u\n",
be16_to_cpu(bdesc->offset_mac),
be16_to_cpu(bdesc->length_mac));
ptr += sizeof(u32);
packet_log(" BDESC[1] 0x%08x\n", be32_to_cpu(*((u32 *)ptr)));
packet_log(" OffsetCrypto:%u LengthCrypto:%u\n",
be16_to_cpu(bdesc->offset_crypto),
be16_to_cpu(bdesc->length_crypto));
ptr += sizeof(u32);
packet_log(" BDESC[2] 0x%08x\n", be32_to_cpu(*((u32 *)ptr)));
packet_log(" OffsetICV:%u OffsetIV:%u\n",
be16_to_cpu(bdesc->offset_icv),
be16_to_cpu(bdesc->offset_iv));
ptr += sizeof(u32);
}
if (spuh->mh.flags & MH_BD_PRES) {
#ifdef DEBUG
struct BD_HEADER *bd = (struct BD_HEADER *)ptr;
#endif
packet_log(" BD[0] 0x%08x\n", be32_to_cpu(*((u32 *)ptr)));
packet_log(" Size:%ubytes PrevLength:%u\n",
be16_to_cpu(bd->size), be16_to_cpu(bd->prev_length));
ptr += 4;
}
if (buf + buf_len != ptr) {
packet_log(" Packet parsed incorrectly. ");
packet_log("buf:%p buf_len:%u buf+buf_len:%p ptr:%p\n",
buf, buf_len, buf + buf_len, ptr);
}
packet_log("\n");
}
u32 spum_ns2_ctx_max_payload(enum spu_cipher_alg cipher_alg,
enum spu_cipher_mode cipher_mode,
unsigned int blocksize)
{
u32 max_payload = SPUM_NS2_MAX_PAYLOAD;
u32 excess;
if (cipher_mode == CIPHER_MODE_XTS)
max_payload -= SPU_XTS_TWEAK_SIZE;
excess = max_payload % blocksize;
return max_payload - excess;
}
u32 spum_nsp_ctx_max_payload(enum spu_cipher_alg cipher_alg,
enum spu_cipher_mode cipher_mode,
unsigned int blocksize)
{
u32 max_payload = SPUM_NSP_MAX_PAYLOAD;
u32 excess;
if (cipher_mode == CIPHER_MODE_XTS)
max_payload -= SPU_XTS_TWEAK_SIZE;
excess = max_payload % blocksize;
return max_payload - excess;
}
u32 spum_payload_length(u8 *spu_hdr)
{
struct BD_HEADER *bd;
u32 pl_len;
bd = (struct BD_HEADER *)(spu_hdr + 8);
pl_len = be16_to_cpu(bd->size);
return pl_len;
}
u16 spum_response_hdr_len(u16 auth_key_len, u16 enc_key_len, bool is_hash)
{
if (is_hash)
return SPU_HASH_RESP_HDR_LEN;
else
return SPU_RESP_HDR_LEN;
}
u16 spum_hash_pad_len(enum hash_alg hash_alg, enum hash_mode hash_mode,
u32 chunksize, u16 hash_block_size)
{
unsigned int length_len;
unsigned int used_space_last_block;
int hash_pad_len;
if ((hash_alg == HASH_ALG_AES) && (hash_mode == HASH_MODE_XCBC)) {
used_space_last_block = chunksize % hash_block_size;
hash_pad_len = hash_block_size - used_space_last_block;
if (hash_pad_len >= hash_block_size)
hash_pad_len -= hash_block_size;
return hash_pad_len;
}
used_space_last_block = chunksize % hash_block_size + 1;
if ((hash_alg == HASH_ALG_SHA384) || (hash_alg == HASH_ALG_SHA512))
length_len = 2 * sizeof(u64);
else
length_len = sizeof(u64);
used_space_last_block += length_len;
hash_pad_len = hash_block_size - used_space_last_block;
if (hash_pad_len < 0)
hash_pad_len += hash_block_size;
hash_pad_len += 1 + length_len;
return hash_pad_len;
}
u32 spum_gcm_ccm_pad_len(enum spu_cipher_mode cipher_mode,
unsigned int data_size)
{
u32 pad_len = 0;
u32 m1 = SPU_GCM_CCM_ALIGN - 1;
if ((cipher_mode == CIPHER_MODE_GCM) ||
(cipher_mode == CIPHER_MODE_CCM))
pad_len = ((data_size + m1) & ~m1) - data_size;
return pad_len;
}
u32 spum_assoc_resp_len(enum spu_cipher_mode cipher_mode,
unsigned int assoc_len, unsigned int iv_len,
bool is_encrypt)
{
u32 buflen = 0;
u32 pad;
if (assoc_len)
buflen = assoc_len;
if (cipher_mode == CIPHER_MODE_GCM) {
pad = spum_gcm_ccm_pad_len(cipher_mode, buflen);
buflen += pad;
}
if (cipher_mode == CIPHER_MODE_CCM) {
pad = spum_gcm_ccm_pad_len(cipher_mode, buflen + 2);
buflen += pad;
}
return buflen;
}
u8 spum_aead_ivlen(enum spu_cipher_mode cipher_mode, u16 iv_len)
{
return 0;
}
enum hash_type spum_hash_type(u32 src_sent)
{
return src_sent ? HASH_TYPE_UPDT : HASH_TYPE_INIT;
}
u32 spum_digest_size(u32 alg_digest_size, enum hash_alg alg,
enum hash_type htype)
{
u32 digestsize = alg_digest_size;
if ((htype == HASH_TYPE_INIT) || (htype == HASH_TYPE_UPDT)) {
if (alg == HASH_ALG_SHA224)
digestsize = SHA256_DIGEST_SIZE;
else if (alg == HASH_ALG_SHA384)
digestsize = SHA512_DIGEST_SIZE;
}
return digestsize;
}
u32 spum_create_request(u8 *spu_hdr,
struct spu_request_opts *req_opts,
struct spu_cipher_parms *cipher_parms,
struct spu_hash_parms *hash_parms,
struct spu_aead_parms *aead_parms,
unsigned int data_size)
{
struct SPUHEADER *spuh;
struct BDESC_HEADER *bdesc;
struct BD_HEADER *bd;
u8 *ptr;
u32 protocol_bits = 0;
u32 cipher_bits = 0;
u32 ecf_bits = 0;
u8 sctx_words = 0;
unsigned int buf_len = 0;
unsigned int cipher_len = hash_parms->prebuf_len + data_size +
hash_parms->pad_len;
unsigned int cipher_offset = aead_parms->assoc_size +
aead_parms->iv_len + aead_parms->aad_pad_len;
unsigned int real_db_size = spu_real_db_size(aead_parms->assoc_size,
aead_parms->iv_len,
hash_parms->prebuf_len,
data_size,
aead_parms->aad_pad_len,
aead_parms->data_pad_len,
hash_parms->pad_len);
unsigned int auth_offset = 0;
unsigned int offset_iv = 0;
unsigned int auth_len;
auth_len = real_db_size;
if (req_opts->is_aead && req_opts->is_inbound)
cipher_len -= hash_parms->digestsize;
if (req_opts->is_aead && req_opts->is_inbound)
auth_len -= hash_parms->digestsize;
if ((hash_parms->alg == HASH_ALG_AES) &&
(hash_parms->mode == HASH_MODE_XCBC)) {
auth_len -= hash_parms->pad_len;
cipher_len -= hash_parms->pad_len;
}
flow_log("%s()\n", __func__);
flow_log(" in:%u authFirst:%u\n",
req_opts->is_inbound, req_opts->auth_first);
flow_log(" %s. cipher alg:%u mode:%u type %u\n",
spu_alg_name(cipher_parms->alg, cipher_parms->mode),
cipher_parms->alg, cipher_parms->mode, cipher_parms->type);
flow_log(" key: %d\n", cipher_parms->key_len);
flow_dump(" key: ", cipher_parms->key_buf, cipher_parms->key_len);
flow_log(" iv: %d\n", cipher_parms->iv_len);
flow_dump(" iv: ", cipher_parms->iv_buf, cipher_parms->iv_len);
flow_log(" auth alg:%u mode:%u type %u\n",
hash_parms->alg, hash_parms->mode, hash_parms->type);
flow_log(" digestsize: %u\n", hash_parms->digestsize);
flow_log(" authkey: %d\n", hash_parms->key_len);
flow_dump(" authkey: ", hash_parms->key_buf, hash_parms->key_len);
flow_log(" assoc_size:%u\n", aead_parms->assoc_size);
flow_log(" prebuf_len:%u\n", hash_parms->prebuf_len);
flow_log(" data_size:%u\n", data_size);
flow_log(" hash_pad_len:%u\n", hash_parms->pad_len);
flow_log(" real_db_size:%u\n", real_db_size);
flow_log(" auth_offset:%u auth_len:%u cipher_offset:%u cipher_len:%u\n",
auth_offset, auth_len, cipher_offset, cipher_len);
flow_log(" aead_iv: %u\n", aead_parms->iv_len);
ptr = spu_hdr;
memset(ptr, 0, sizeof(struct SPUHEADER));
spuh = (struct SPUHEADER *)ptr;
ptr += sizeof(struct SPUHEADER);
buf_len += sizeof(struct SPUHEADER);
spuh->mh.op_code = SPU_CRYPTO_OPERATION_GENERIC;
spuh->mh.flags |= (MH_SCTX_PRES | MH_BDESC_PRES | MH_BD_PRES);
sctx_words = 3;
if (req_opts->is_inbound)
cipher_bits |= CIPHER_INBOUND;
if (req_opts->auth_first)
cipher_bits |= CIPHER_ORDER;
cipher_bits |= cipher_parms->alg << CIPHER_ALG_SHIFT;
cipher_bits |= cipher_parms->mode << CIPHER_MODE_SHIFT;
cipher_bits |= cipher_parms->type << CIPHER_TYPE_SHIFT;
cipher_bits |= hash_parms->alg << HASH_ALG_SHIFT;
cipher_bits |= hash_parms->mode << HASH_MODE_SHIFT;
cipher_bits |= hash_parms->type << HASH_TYPE_SHIFT;
if (hash_parms->alg) {
if (hash_parms->key_len) {
memcpy(ptr, hash_parms->key_buf, hash_parms->key_len);
ptr += hash_parms->key_len;
buf_len += hash_parms->key_len;
sctx_words += hash_parms->key_len / 4;
}
if ((cipher_parms->mode == CIPHER_MODE_GCM) ||
(cipher_parms->mode == CIPHER_MODE_CCM))
offset_iv = aead_parms->assoc_size;
if (!req_opts->is_inbound) {
if ((cipher_parms->mode == CIPHER_MODE_GCM) ||
(cipher_parms->mode == CIPHER_MODE_CCM))
ecf_bits |= 1 << INSERT_ICV_SHIFT;
} else {
ecf_bits |= CHECK_ICV;
}
if (hash_parms->digestsize == 64)
cipher_bits |= ICV_IS_512;
else
ecf_bits |=
(hash_parms->digestsize / 4) << ICV_SIZE_SHIFT;
}
if (req_opts->bd_suppress)
ecf_bits |= BD_SUPPRESS;
if (cipher_parms->alg) {
if (cipher_parms->key_len) {
memcpy(ptr, cipher_parms->key_buf,
cipher_parms->key_len);
ptr += cipher_parms->key_len;
buf_len += cipher_parms->key_len;
sctx_words += cipher_parms->key_len / 4;
}
if (cipher_parms->iv_buf && cipher_parms->iv_len) {
ecf_bits |= SCTX_IV;
memcpy(ptr, cipher_parms->iv_buf, cipher_parms->iv_len);
ptr += cipher_parms->iv_len;
buf_len += cipher_parms->iv_len;
sctx_words += cipher_parms->iv_len / 4;
}
}
if (req_opts->is_rfc4543) {
if (req_opts->is_inbound)
data_size -= hash_parms->digestsize;
offset_iv = aead_parms->assoc_size + data_size;
cipher_len = 0;
cipher_offset = offset_iv;
auth_len = cipher_offset + aead_parms->data_pad_len;
}
protocol_bits |= sctx_words;
spuh->sa.proto_flags = cpu_to_be32(protocol_bits);
spuh->sa.cipher_flags = cpu_to_be32(cipher_bits);
spuh->sa.ecf = cpu_to_be32(ecf_bits);
bdesc = (struct BDESC_HEADER *)ptr;
bdesc->offset_mac = cpu_to_be16(auth_offset);
bdesc->length_mac = cpu_to_be16(auth_len);
bdesc->offset_crypto = cpu_to_be16(cipher_offset);
bdesc->length_crypto = cpu_to_be16(cipher_len);
if (cipher_parms->mode == CIPHER_MODE_CCM)
auth_len += spum_wordalign_padlen(auth_len);
bdesc->offset_icv = cpu_to_be16(auth_len);
bdesc->offset_iv = cpu_to_be16(offset_iv);
ptr += sizeof(struct BDESC_HEADER);
buf_len += sizeof(struct BDESC_HEADER);
bd = (struct BD_HEADER *)ptr;
bd->size = cpu_to_be16(real_db_size);
bd->prev_length = 0;
ptr += sizeof(struct BD_HEADER);
buf_len += sizeof(struct BD_HEADER);
packet_dump(" SPU request header: ", spu_hdr, buf_len);
return buf_len;
}
u16 spum_cipher_req_init(u8 *spu_hdr, struct spu_cipher_parms *cipher_parms)
{
struct SPUHEADER *spuh;
u32 protocol_bits = 0;
u32 cipher_bits = 0;
u32 ecf_bits = 0;
u8 sctx_words = 0;
u8 *ptr = spu_hdr;
flow_log("%s()\n", __func__);
flow_log(" cipher alg:%u mode:%u type %u\n", cipher_parms->alg,
cipher_parms->mode, cipher_parms->type);
flow_log(" cipher_iv_len: %u\n", cipher_parms->iv_len);
flow_log(" key: %d\n", cipher_parms->key_len);
flow_dump(" key: ", cipher_parms->key_buf, cipher_parms->key_len);
memset(spu_hdr, 0, sizeof(struct SPUHEADER));
ptr += sizeof(struct SPUHEADER);
spuh = (struct SPUHEADER *)spu_hdr;
spuh->mh.op_code = SPU_CRYPTO_OPERATION_GENERIC;
spuh->mh.flags |= (MH_SCTX_PRES | MH_BDESC_PRES | MH_BD_PRES);
sctx_words = 3;
if (cipher_parms->alg) {
if (cipher_parms->key_len) {
ptr += cipher_parms->key_len;
sctx_words += cipher_parms->key_len / 4;
}
if (cipher_parms->iv_len) {
ecf_bits |= SCTX_IV;
ptr += cipher_parms->iv_len;
sctx_words += cipher_parms->iv_len / 4;
}
}
cipher_bits |= cipher_parms->alg << CIPHER_ALG_SHIFT;
cipher_bits |= cipher_parms->mode << CIPHER_MODE_SHIFT;
cipher_bits |= cipher_parms->type << CIPHER_TYPE_SHIFT;
if (cipher_parms->alg && cipher_parms->key_len)
memcpy(spuh + 1, cipher_parms->key_buf, cipher_parms->key_len);
protocol_bits |= sctx_words;
spuh->sa.proto_flags = cpu_to_be32(protocol_bits);
spuh->sa.cipher_flags = cpu_to_be32(cipher_bits);
spuh->sa.ecf = cpu_to_be32(ecf_bits);
packet_dump(" SPU request header: ", spu_hdr,
sizeof(struct SPUHEADER));
return sizeof(struct SPUHEADER) + cipher_parms->key_len +
cipher_parms->iv_len + sizeof(struct BDESC_HEADER) +
sizeof(struct BD_HEADER);
}
void spum_cipher_req_finish(u8 *spu_hdr,
u16 spu_req_hdr_len,
unsigned int is_inbound,
struct spu_cipher_parms *cipher_parms,
bool update_key,
unsigned int data_size)
{
struct SPUHEADER *spuh;
struct BDESC_HEADER *bdesc;
struct BD_HEADER *bd;
u8 *bdesc_ptr = spu_hdr + spu_req_hdr_len -
(sizeof(struct BD_HEADER) + sizeof(struct BDESC_HEADER));
u32 cipher_bits;
flow_log("%s()\n", __func__);
flow_log(" in: %u\n", is_inbound);
flow_log(" cipher alg: %u, cipher_type: %u\n", cipher_parms->alg,
cipher_parms->type);
if (update_key) {
flow_log(" cipher key len: %u\n", cipher_parms->key_len);
flow_dump(" key: ", cipher_parms->key_buf,
cipher_parms->key_len);
}
if (cipher_parms->mode == CIPHER_MODE_XTS)
memset(cipher_parms->iv_buf, 0, cipher_parms->iv_len);
flow_log(" iv len: %d\n", cipher_parms->iv_len);
flow_dump(" iv: ", cipher_parms->iv_buf, cipher_parms->iv_len);
flow_log(" data_size: %u\n", data_size);
spuh = (struct SPUHEADER *)spu_hdr;
cipher_bits = be32_to_cpu(spuh->sa.cipher_flags);
if (is_inbound)
cipher_bits |= CIPHER_INBOUND;
else
cipher_bits &= ~CIPHER_INBOUND;
if (update_key) {
spuh->sa.cipher_flags |=
cipher_parms->type << CIPHER_TYPE_SHIFT;
memcpy(spuh + 1, cipher_parms->key_buf, cipher_parms->key_len);
}
if (cipher_parms->alg && cipher_parms->iv_buf && cipher_parms->iv_len)
memcpy(bdesc_ptr - cipher_parms->iv_len, cipher_parms->iv_buf,
cipher_parms->iv_len);
spuh->sa.cipher_flags = cpu_to_be32(cipher_bits);
bdesc = (struct BDESC_HEADER *)bdesc_ptr;
bdesc->offset_mac = 0;
bdesc->length_mac = 0;
bdesc->offset_crypto = 0;
if (cipher_parms->mode == CIPHER_MODE_XTS)
bdesc->length_crypto = cpu_to_be16(data_size +
SPU_XTS_TWEAK_SIZE);
else
bdesc->length_crypto = cpu_to_be16(data_size);
bdesc->offset_icv = 0;
bdesc->offset_iv = 0;
bd = (struct BD_HEADER *)(bdesc_ptr + sizeof(struct BDESC_HEADER));
bd->size = cpu_to_be16(data_size);
if (cipher_parms->mode == CIPHER_MODE_XTS)
bd->size = cpu_to_be16(data_size + SPU_XTS_TWEAK_SIZE);
else
bd->size = cpu_to_be16(data_size);
bd->prev_length = 0;
packet_dump(" SPU request header: ", spu_hdr, spu_req_hdr_len);
}
void spum_request_pad(u8 *pad_start,
u32 gcm_ccm_padding,
u32 hash_pad_len,
enum hash_alg auth_alg,
enum hash_mode auth_mode,
unsigned int total_sent, u32 status_padding)
{
u8 *ptr = pad_start;
if (gcm_ccm_padding > 0) {
flow_log(" GCM: padding to 16 byte alignment: %u bytes\n",
gcm_ccm_padding);
memset(ptr, 0, gcm_ccm_padding);
ptr += gcm_ccm_padding;
}
if (hash_pad_len > 0) {
memset(ptr, 0, hash_pad_len);
if ((auth_alg == HASH_ALG_AES) &&
(auth_mode == HASH_MODE_XCBC)) {
ptr += hash_pad_len;
} else {
*ptr = 0x80;
ptr += (hash_pad_len - sizeof(u64));
if (auth_alg == HASH_ALG_MD5)
*(u64 *)ptr = cpu_to_le64((u64)total_sent * 8);
else
*(u64 *)ptr = cpu_to_be64((u64)total_sent * 8);
ptr += sizeof(u64);
}
}
if (status_padding > 0) {
flow_log(" STAT: padding to 4 byte alignment: %u bytes\n",
status_padding);
memset(ptr, 0, status_padding);
ptr += status_padding;
}
}
u8 spum_xts_tweak_in_payload(void)
{
return 1;
}
u8 spum_tx_status_len(void)
{
return SPU_TX_STATUS_LEN;
}
u8 spum_rx_status_len(void)
{
return SPU_RX_STATUS_LEN;
}
int spum_status_process(u8 *statp)
{
u32 status;
status = __be32_to_cpu(*(__be32 *)statp);
flow_log("SPU response STATUS %#08x\n", status);
if (status & SPU_STATUS_ERROR_FLAG) {
pr_err("%s() Warning: Error result from SPU: %#08x\n",
__func__, status);
if (status & SPU_STATUS_INVALID_ICV)
return SPU_INVALID_ICV;
return -EBADMSG;
}
return 0;
}
void spum_ccm_update_iv(unsigned int digestsize,
struct spu_cipher_parms *cipher_parms,
unsigned int assoclen,
unsigned int chunksize,
bool is_encrypt,
bool is_esp)
{
u8 L;
u8 mprime;
u8 adata;
if (cipher_parms->iv_len != CCM_AES_IV_SIZE) {
pr_err("%s(): Invalid IV len %d for CCM mode, should be %d\n",
__func__, cipher_parms->iv_len, CCM_AES_IV_SIZE);
return;
}
if (is_esp) {
L = CCM_ESP_L_VALUE;
} else {
L = ((cipher_parms->iv_buf[0] & CCM_B0_L_PRIME) >>
CCM_B0_L_PRIME_SHIFT) + 1;
}
mprime = (digestsize - 2) >> 1;
adata = (assoclen > 0);
cipher_parms->iv_buf[0] = (adata << CCM_B0_ADATA_SHIFT) |
(mprime << CCM_B0_M_PRIME_SHIFT) |
((L - 1) << CCM_B0_L_PRIME_SHIFT);
if (!is_encrypt)
chunksize -= digestsize;
format_value_ccm(chunksize, &cipher_parms->iv_buf[15 - L + 1], L);
}
u32 spum_wordalign_padlen(u32 data_size)
{
return ((data_size + 3) & ~3) - data_size;
}
