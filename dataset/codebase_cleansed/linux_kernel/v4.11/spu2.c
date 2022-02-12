static char *spu2_ciph_type_name(enum spu2_cipher_type cipher_type)
{
if (cipher_type >= SPU2_CIPHER_TYPE_LAST)
return "Reserved";
return spu2_cipher_type_names[cipher_type];
}
static char *spu2_ciph_mode_name(enum spu2_cipher_mode cipher_mode)
{
if (cipher_mode >= SPU2_CIPHER_MODE_LAST)
return "Reserved";
return spu2_cipher_mode_names[cipher_mode];
}
static char *spu2_hash_type_name(enum spu2_hash_type hash_type)
{
if (hash_type >= SPU2_HASH_TYPE_LAST)
return "Reserved";
return spu2_hash_type_names[hash_type];
}
static char *spu2_hash_mode_name(enum spu2_hash_mode hash_mode)
{
if (hash_mode >= SPU2_HASH_MODE_LAST)
return "Reserved";
return spu2_hash_mode_names[hash_mode];
}
static int spu2_cipher_mode_xlate(enum spu_cipher_mode cipher_mode,
enum spu2_cipher_mode *spu2_mode)
{
switch (cipher_mode) {
case CIPHER_MODE_ECB:
*spu2_mode = SPU2_CIPHER_MODE_ECB;
break;
case CIPHER_MODE_CBC:
*spu2_mode = SPU2_CIPHER_MODE_CBC;
break;
case CIPHER_MODE_OFB:
*spu2_mode = SPU2_CIPHER_MODE_OFB;
break;
case CIPHER_MODE_CFB:
*spu2_mode = SPU2_CIPHER_MODE_CFB;
break;
case CIPHER_MODE_CTR:
*spu2_mode = SPU2_CIPHER_MODE_CTR;
break;
case CIPHER_MODE_CCM:
*spu2_mode = SPU2_CIPHER_MODE_CCM;
break;
case CIPHER_MODE_GCM:
*spu2_mode = SPU2_CIPHER_MODE_GCM;
break;
case CIPHER_MODE_XTS:
*spu2_mode = SPU2_CIPHER_MODE_XTS;
break;
default:
return -EINVAL;
}
return 0;
}
static int spu2_cipher_xlate(enum spu_cipher_alg cipher_alg,
enum spu_cipher_mode cipher_mode,
enum spu_cipher_type cipher_type,
enum spu2_cipher_type *spu2_type,
enum spu2_cipher_mode *spu2_mode)
{
int err;
err = spu2_cipher_mode_xlate(cipher_mode, spu2_mode);
if (err) {
flow_log("Invalid cipher mode %d\n", cipher_mode);
return err;
}
switch (cipher_alg) {
case CIPHER_ALG_NONE:
*spu2_type = SPU2_CIPHER_TYPE_NONE;
break;
case CIPHER_ALG_RC4:
err = -EINVAL;
*spu2_type = SPU2_CIPHER_TYPE_NONE;
break;
case CIPHER_ALG_DES:
*spu2_type = SPU2_CIPHER_TYPE_DES;
break;
case CIPHER_ALG_3DES:
*spu2_type = SPU2_CIPHER_TYPE_3DES;
break;
case CIPHER_ALG_AES:
switch (cipher_type) {
case CIPHER_TYPE_AES128:
*spu2_type = SPU2_CIPHER_TYPE_AES128;
break;
case CIPHER_TYPE_AES192:
*spu2_type = SPU2_CIPHER_TYPE_AES192;
break;
case CIPHER_TYPE_AES256:
*spu2_type = SPU2_CIPHER_TYPE_AES256;
break;
default:
err = -EINVAL;
}
break;
case CIPHER_ALG_LAST:
default:
err = -EINVAL;
break;
}
if (err)
flow_log("Invalid cipher alg %d or type %d\n",
cipher_alg, cipher_type);
return err;
}
static int spu2_hash_mode_xlate(enum hash_mode hash_mode,
enum spu2_hash_mode *spu2_mode)
{
switch (hash_mode) {
case HASH_MODE_XCBC:
*spu2_mode = SPU2_HASH_MODE_XCBC_MAC;
break;
case HASH_MODE_CMAC:
*spu2_mode = SPU2_HASH_MODE_CMAC;
break;
case HASH_MODE_HMAC:
*spu2_mode = SPU2_HASH_MODE_HMAC;
break;
case HASH_MODE_CCM:
*spu2_mode = SPU2_HASH_MODE_CCM;
break;
case HASH_MODE_GCM:
*spu2_mode = SPU2_HASH_MODE_GCM;
break;
default:
return -EINVAL;
}
return 0;
}
static int
spu2_hash_xlate(enum hash_alg hash_alg, enum hash_mode hash_mode,
enum hash_type hash_type, enum spu_cipher_type ciph_type,
enum spu2_hash_type *spu2_type, enum spu2_hash_mode *spu2_mode)
{
int err;
err = spu2_hash_mode_xlate(hash_mode, spu2_mode);
if (err) {
flow_log("Invalid hash mode %d\n", hash_mode);
return err;
}
switch (hash_alg) {
case HASH_ALG_NONE:
*spu2_type = SPU2_HASH_TYPE_NONE;
break;
case HASH_ALG_MD5:
*spu2_type = SPU2_HASH_TYPE_MD5;
break;
case HASH_ALG_SHA1:
*spu2_type = SPU2_HASH_TYPE_SHA1;
break;
case HASH_ALG_SHA224:
*spu2_type = SPU2_HASH_TYPE_SHA224;
break;
case HASH_ALG_SHA256:
*spu2_type = SPU2_HASH_TYPE_SHA256;
break;
case HASH_ALG_SHA384:
*spu2_type = SPU2_HASH_TYPE_SHA384;
break;
case HASH_ALG_SHA512:
*spu2_type = SPU2_HASH_TYPE_SHA512;
break;
case HASH_ALG_AES:
switch (ciph_type) {
case CIPHER_TYPE_AES128:
*spu2_type = SPU2_HASH_TYPE_AES128;
break;
case CIPHER_TYPE_AES192:
*spu2_type = SPU2_HASH_TYPE_AES192;
break;
case CIPHER_TYPE_AES256:
*spu2_type = SPU2_HASH_TYPE_AES256;
break;
default:
err = -EINVAL;
}
break;
case HASH_ALG_SHA3_224:
*spu2_type = SPU2_HASH_TYPE_SHA3_224;
break;
case HASH_ALG_SHA3_256:
*spu2_type = SPU2_HASH_TYPE_SHA3_256;
break;
case HASH_ALG_SHA3_384:
*spu2_type = SPU2_HASH_TYPE_SHA3_384;
break;
case HASH_ALG_SHA3_512:
*spu2_type = SPU2_HASH_TYPE_SHA3_512;
case HASH_ALG_LAST:
default:
err = -EINVAL;
break;
}
if (err)
flow_log("Invalid hash alg %d or type %d\n",
hash_alg, hash_type);
return err;
}
static void spu2_dump_fmd_ctrl0(u64 ctrl0)
{
enum spu2_cipher_type ciph_type;
enum spu2_cipher_mode ciph_mode;
enum spu2_hash_type hash_type;
enum spu2_hash_mode hash_mode;
char *ciph_name;
char *ciph_mode_name;
char *hash_name;
char *hash_mode_name;
u8 cfb;
u8 proto;
packet_log(" FMD CTRL0 %#16llx\n", ctrl0);
if (ctrl0 & SPU2_CIPH_ENCRYPT_EN)
packet_log(" encrypt\n");
else
packet_log(" decrypt\n");
ciph_type = (ctrl0 & SPU2_CIPH_TYPE) >> SPU2_CIPH_TYPE_SHIFT;
ciph_name = spu2_ciph_type_name(ciph_type);
packet_log(" Cipher type: %s\n", ciph_name);
if (ciph_type != SPU2_CIPHER_TYPE_NONE) {
ciph_mode = (ctrl0 & SPU2_CIPH_MODE) >> SPU2_CIPH_MODE_SHIFT;
ciph_mode_name = spu2_ciph_mode_name(ciph_mode);
packet_log(" Cipher mode: %s\n", ciph_mode_name);
}
cfb = (ctrl0 & SPU2_CFB_MASK) >> SPU2_CFB_MASK_SHIFT;
packet_log(" CFB %#x\n", cfb);
proto = (ctrl0 & SPU2_PROTO_SEL) >> SPU2_PROTO_SEL_SHIFT;
packet_log(" protocol %#x\n", proto);
if (ctrl0 & SPU2_HASH_FIRST)
packet_log(" hash first\n");
else
packet_log(" cipher first\n");
if (ctrl0 & SPU2_CHK_TAG)
packet_log(" check tag\n");
hash_type = (ctrl0 & SPU2_HASH_TYPE) >> SPU2_HASH_TYPE_SHIFT;
hash_name = spu2_hash_type_name(hash_type);
packet_log(" Hash type: %s\n", hash_name);
if (hash_type != SPU2_HASH_TYPE_NONE) {
hash_mode = (ctrl0 & SPU2_HASH_MODE) >> SPU2_HASH_MODE_SHIFT;
hash_mode_name = spu2_hash_mode_name(hash_mode);
packet_log(" Hash mode: %s\n", hash_mode_name);
}
if (ctrl0 & SPU2_CIPH_PAD_EN) {
packet_log(" Cipher pad: %#2llx\n",
(ctrl0 & SPU2_CIPH_PAD) >> SPU2_CIPH_PAD_SHIFT);
}
}
static void spu2_dump_fmd_ctrl1(u64 ctrl1)
{
u8 hash_key_len;
u8 ciph_key_len;
u8 ret_iv_len;
u8 iv_offset;
u8 iv_len;
u8 hash_tag_len;
u8 ret_md;
packet_log(" FMD CTRL1 %#16llx\n", ctrl1);
if (ctrl1 & SPU2_TAG_LOC)
packet_log(" Tag after payload\n");
packet_log(" Msg includes ");
if (ctrl1 & SPU2_HAS_FR_DATA)
packet_log("FD ");
if (ctrl1 & SPU2_HAS_AAD1)
packet_log("AAD1 ");
if (ctrl1 & SPU2_HAS_NAAD)
packet_log("NAAD ");
if (ctrl1 & SPU2_HAS_AAD2)
packet_log("AAD2 ");
if (ctrl1 & SPU2_HAS_ESN)
packet_log("ESN ");
packet_log("\n");
hash_key_len = (ctrl1 & SPU2_HASH_KEY_LEN) >> SPU2_HASH_KEY_LEN_SHIFT;
packet_log(" Hash key len %u\n", hash_key_len);
ciph_key_len = (ctrl1 & SPU2_CIPH_KEY_LEN) >> SPU2_CIPH_KEY_LEN_SHIFT;
packet_log(" Cipher key len %u\n", ciph_key_len);
if (ctrl1 & SPU2_GENIV)
packet_log(" Generate IV\n");
if (ctrl1 & SPU2_HASH_IV)
packet_log(" IV included in hash\n");
if (ctrl1 & SPU2_RET_IV)
packet_log(" Return IV in output before payload\n");
ret_iv_len = (ctrl1 & SPU2_RET_IV_LEN) >> SPU2_RET_IV_LEN_SHIFT;
packet_log(" Length of returned IV %u bytes\n",
ret_iv_len ? ret_iv_len : 16);
iv_offset = (ctrl1 & SPU2_IV_OFFSET) >> SPU2_IV_OFFSET_SHIFT;
packet_log(" IV offset %u\n", iv_offset);
iv_len = (ctrl1 & SPU2_IV_LEN) >> SPU2_IV_LEN_SHIFT;
packet_log(" Input IV len %u bytes\n", iv_len);
hash_tag_len = (ctrl1 & SPU2_HASH_TAG_LEN) >> SPU2_HASH_TAG_LEN_SHIFT;
packet_log(" Hash tag length %u bytes\n", hash_tag_len);
packet_log(" Return ");
ret_md = (ctrl1 & SPU2_RETURN_MD) >> SPU2_RETURN_MD_SHIFT;
if (ret_md)
packet_log("FMD ");
if (ret_md == SPU2_RET_FMD_OMD)
packet_log("OMD ");
else if (ret_md == SPU2_RET_FMD_OMD_IV)
packet_log("OMD IV ");
if (ctrl1 & SPU2_RETURN_FD)
packet_log("FD ");
if (ctrl1 & SPU2_RETURN_AAD1)
packet_log("AAD1 ");
if (ctrl1 & SPU2_RETURN_NAAD)
packet_log("NAAD ");
if (ctrl1 & SPU2_RETURN_AAD2)
packet_log("AAD2 ");
if (ctrl1 & SPU2_RETURN_PAY)
packet_log("Payload");
packet_log("\n");
}
static void spu2_dump_fmd_ctrl2(u64 ctrl2)
{
packet_log(" FMD CTRL2 %#16llx\n", ctrl2);
packet_log(" AAD1 offset %llu length %llu bytes\n",
ctrl2 & SPU2_AAD1_OFFSET,
(ctrl2 & SPU2_AAD1_LEN) >> SPU2_AAD1_LEN_SHIFT);
packet_log(" AAD2 offset %llu\n",
(ctrl2 & SPU2_AAD2_OFFSET) >> SPU2_AAD2_OFFSET_SHIFT);
packet_log(" Payload offset %llu\n",
(ctrl2 & SPU2_PL_OFFSET) >> SPU2_PL_OFFSET_SHIFT);
}
static void spu2_dump_fmd_ctrl3(u64 ctrl3)
{
packet_log(" FMD CTRL3 %#16llx\n", ctrl3);
packet_log(" Payload length %llu bytes\n", ctrl3 & SPU2_PL_LEN);
packet_log(" TLS length %llu bytes\n",
(ctrl3 & SPU2_TLS_LEN) >> SPU2_TLS_LEN_SHIFT);
}
static void spu2_dump_fmd(struct SPU2_FMD *fmd)
{
spu2_dump_fmd_ctrl0(le64_to_cpu(fmd->ctrl0));
spu2_dump_fmd_ctrl1(le64_to_cpu(fmd->ctrl1));
spu2_dump_fmd_ctrl2(le64_to_cpu(fmd->ctrl2));
spu2_dump_fmd_ctrl3(le64_to_cpu(fmd->ctrl3));
}
static void spu2_dump_omd(u8 *omd, u16 hash_key_len, u16 ciph_key_len,
u16 hash_iv_len, u16 ciph_iv_len)
{
u8 *ptr = omd;
packet_log(" OMD:\n");
if (hash_key_len) {
packet_log(" Hash Key Length %u bytes\n", hash_key_len);
packet_dump(" KEY: ", ptr, hash_key_len);
ptr += hash_key_len;
}
if (ciph_key_len) {
packet_log(" Cipher Key Length %u bytes\n", ciph_key_len);
packet_dump(" KEY: ", ptr, ciph_key_len);
ptr += ciph_key_len;
}
if (hash_iv_len) {
packet_log(" Hash IV Length %u bytes\n", hash_iv_len);
packet_dump(" hash IV: ", ptr, hash_iv_len);
ptr += ciph_key_len;
}
if (ciph_iv_len) {
packet_log(" Cipher IV Length %u bytes\n", ciph_iv_len);
packet_dump(" cipher IV: ", ptr, ciph_iv_len);
}
}
void spu2_dump_msg_hdr(u8 *buf, unsigned int buf_len)
{
struct SPU2_FMD *fmd = (struct SPU2_FMD *)buf;
u8 *omd;
u64 ctrl1;
u16 hash_key_len;
u16 ciph_key_len;
u16 hash_iv_len;
u16 ciph_iv_len;
u16 omd_len;
packet_log("\n");
packet_log("SPU2 message header %p len: %u\n", buf, buf_len);
spu2_dump_fmd(fmd);
omd = (u8 *)(fmd + 1);
ctrl1 = le64_to_cpu(fmd->ctrl1);
hash_key_len = (ctrl1 & SPU2_HASH_KEY_LEN) >> SPU2_HASH_KEY_LEN_SHIFT;
ciph_key_len = (ctrl1 & SPU2_CIPH_KEY_LEN) >> SPU2_CIPH_KEY_LEN_SHIFT;
hash_iv_len = 0;
ciph_iv_len = (ctrl1 & SPU2_IV_LEN) >> SPU2_IV_LEN_SHIFT;
spu2_dump_omd(omd, hash_key_len, ciph_key_len, hash_iv_len,
ciph_iv_len);
omd_len = hash_key_len + ciph_key_len + hash_iv_len + ciph_iv_len;
if (FMD_SIZE + omd_len != buf_len) {
packet_log
(" Packet parsed incorrectly. buf_len %u, sum of MD %zu\n",
buf_len, FMD_SIZE + omd_len);
}
packet_log("\n");
}
static int spu2_fmd_init(struct SPU2_FMD *fmd,
enum spu2_cipher_type spu2_type,
enum spu2_cipher_mode spu2_mode,
u32 cipher_key_len, u32 cipher_iv_len)
{
u64 ctrl0;
u64 ctrl1;
u64 ctrl2;
u64 ctrl3;
u32 aad1_offset;
u32 aad2_offset;
u16 aad1_len = 0;
u64 payload_offset;
ctrl0 = (spu2_type << SPU2_CIPH_TYPE_SHIFT) |
(spu2_mode << SPU2_CIPH_MODE_SHIFT);
ctrl1 = (cipher_key_len << SPU2_CIPH_KEY_LEN_SHIFT) |
((u64)cipher_iv_len << SPU2_IV_LEN_SHIFT) |
((u64)SPU2_RET_FMD_ONLY << SPU2_RETURN_MD_SHIFT) | SPU2_RETURN_PAY;
aad1_offset = 0;
aad2_offset = aad1_offset;
payload_offset = 0;
ctrl2 = aad1_offset |
(aad1_len << SPU2_AAD1_LEN_SHIFT) |
(aad2_offset << SPU2_AAD2_OFFSET_SHIFT) |
(payload_offset << SPU2_PL_OFFSET_SHIFT);
ctrl3 = 0;
fmd->ctrl0 = cpu_to_le64(ctrl0);
fmd->ctrl1 = cpu_to_le64(ctrl1);
fmd->ctrl2 = cpu_to_le64(ctrl2);
fmd->ctrl3 = cpu_to_le64(ctrl3);
return 0;
}
static void spu2_fmd_ctrl0_write(struct SPU2_FMD *fmd,
bool is_inbound, bool auth_first,
enum spu2_proto_sel protocol,
enum spu2_cipher_type cipher_type,
enum spu2_cipher_mode cipher_mode,
enum spu2_hash_type auth_type,
enum spu2_hash_mode auth_mode)
{
u64 ctrl0 = 0;
if ((cipher_type != SPU2_CIPHER_TYPE_NONE) && !is_inbound)
ctrl0 |= SPU2_CIPH_ENCRYPT_EN;
ctrl0 |= ((u64)cipher_type << SPU2_CIPH_TYPE_SHIFT) |
((u64)cipher_mode << SPU2_CIPH_MODE_SHIFT);
if (protocol)
ctrl0 |= (u64)protocol << SPU2_PROTO_SEL_SHIFT;
if (auth_first)
ctrl0 |= SPU2_HASH_FIRST;
if (is_inbound && (auth_type != SPU2_HASH_TYPE_NONE))
ctrl0 |= SPU2_CHK_TAG;
ctrl0 |= (((u64)auth_type << SPU2_HASH_TYPE_SHIFT) |
((u64)auth_mode << SPU2_HASH_MODE_SHIFT));
fmd->ctrl0 = cpu_to_le64(ctrl0);
}
static void spu2_fmd_ctrl1_write(struct SPU2_FMD *fmd, bool is_inbound,
u64 assoc_size,
u64 auth_key_len, u64 cipher_key_len,
bool gen_iv, bool hash_iv, bool return_iv,
u64 ret_iv_len, u64 ret_iv_offset,
u64 cipher_iv_len, u64 digest_size,
bool return_payload, bool return_md)
{
u64 ctrl1 = 0;
if (is_inbound && digest_size)
ctrl1 |= SPU2_TAG_LOC;
if (assoc_size) {
ctrl1 |= SPU2_HAS_AAD2;
ctrl1 |= SPU2_RETURN_AAD2;
}
if (auth_key_len)
ctrl1 |= ((auth_key_len << SPU2_HASH_KEY_LEN_SHIFT) &
SPU2_HASH_KEY_LEN);
if (cipher_key_len)
ctrl1 |= ((cipher_key_len << SPU2_CIPH_KEY_LEN_SHIFT) &
SPU2_CIPH_KEY_LEN);
if (gen_iv)
ctrl1 |= SPU2_GENIV;
if (hash_iv)
ctrl1 |= SPU2_HASH_IV;
if (return_iv) {
ctrl1 |= SPU2_RET_IV;
ctrl1 |= ret_iv_len << SPU2_RET_IV_LEN_SHIFT;
ctrl1 |= ret_iv_offset << SPU2_IV_OFFSET_SHIFT;
}
ctrl1 |= ((cipher_iv_len << SPU2_IV_LEN_SHIFT) & SPU2_IV_LEN);
if (digest_size)
ctrl1 |= ((digest_size << SPU2_HASH_TAG_LEN_SHIFT) &
SPU2_HASH_TAG_LEN);
if (return_md)
ctrl1 |= ((u64)SPU2_RET_FMD_ONLY << SPU2_RETURN_MD_SHIFT);
else
ctrl1 |= ((u64)SPU2_RET_NO_MD << SPU2_RETURN_MD_SHIFT);
if (return_payload)
ctrl1 |= SPU2_RETURN_PAY;
fmd->ctrl1 = cpu_to_le64(ctrl1);
}
static void spu2_fmd_ctrl2_write(struct SPU2_FMD *fmd, u64 cipher_offset,
u64 auth_key_len, u64 auth_iv_len,
u64 cipher_key_len, u64 cipher_iv_len)
{
u64 ctrl2;
u64 aad1_offset;
u64 aad2_offset;
u16 aad1_len = 0;
u64 payload_offset;
aad1_offset = 0;
aad2_offset = aad1_offset;
payload_offset = cipher_offset;
ctrl2 = aad1_offset |
(aad1_len << SPU2_AAD1_LEN_SHIFT) |
(aad2_offset << SPU2_AAD2_OFFSET_SHIFT) |
(payload_offset << SPU2_PL_OFFSET_SHIFT);
fmd->ctrl2 = cpu_to_le64(ctrl2);
}
static void spu2_fmd_ctrl3_write(struct SPU2_FMD *fmd, u64 payload_len)
{
u64 ctrl3;
ctrl3 = payload_len & SPU2_PL_LEN;
fmd->ctrl3 = cpu_to_le64(ctrl3);
}
u32 spu2_ctx_max_payload(enum spu_cipher_alg cipher_alg,
enum spu_cipher_mode cipher_mode,
unsigned int blocksize)
{
if ((cipher_alg == CIPHER_ALG_AES) &&
(cipher_mode == CIPHER_MODE_CCM)) {
u32 excess = SPU2_MAX_PAYLOAD % blocksize;
return SPU2_MAX_PAYLOAD - excess;
} else {
return SPU_MAX_PAYLOAD_INF;
}
}
u32 spu2_payload_length(u8 *spu_hdr)
{
struct SPU2_FMD *fmd = (struct SPU2_FMD *)spu_hdr;
u32 pl_len;
u64 ctrl3;
ctrl3 = le64_to_cpu(fmd->ctrl3);
pl_len = ctrl3 & SPU2_PL_LEN;
return pl_len;
}
u16 spu2_response_hdr_len(u16 auth_key_len, u16 enc_key_len, bool is_hash)
{
return FMD_SIZE;
}
u16 spu2_hash_pad_len(enum hash_alg hash_alg, enum hash_mode hash_mode,
u32 chunksize, u16 hash_block_size)
{
return 0;
}
u32 spu2_gcm_ccm_pad_len(enum spu_cipher_mode cipher_mode,
unsigned int data_size)
{
return 0;
}
u32 spu2_assoc_resp_len(enum spu_cipher_mode cipher_mode,
unsigned int assoc_len, unsigned int iv_len,
bool is_encrypt)
{
u32 resp_len = assoc_len;
if (is_encrypt)
resp_len += iv_len;
return resp_len;
}
u8 spu2_aead_ivlen(enum spu_cipher_mode cipher_mode, u16 iv_len)
{
return 0;
}
enum hash_type spu2_hash_type(u32 src_sent)
{
return HASH_TYPE_FULL;
}
u32 spu2_digest_size(u32 alg_digest_size, enum hash_alg alg,
enum hash_type htype)
{
return alg_digest_size;
}
u32 spu2_create_request(u8 *spu_hdr,
struct spu_request_opts *req_opts,
struct spu_cipher_parms *cipher_parms,
struct spu_hash_parms *hash_parms,
struct spu_aead_parms *aead_parms,
unsigned int data_size)
{
struct SPU2_FMD *fmd;
u8 *ptr;
unsigned int buf_len;
int err;
enum spu2_cipher_type spu2_ciph_type = SPU2_CIPHER_TYPE_NONE;
enum spu2_cipher_mode spu2_ciph_mode;
enum spu2_hash_type spu2_auth_type = SPU2_HASH_TYPE_NONE;
enum spu2_hash_mode spu2_auth_mode;
bool return_md = true;
enum spu2_proto_sel proto = SPU2_PROTO_RESV;
unsigned int payload_len =
hash_parms->prebuf_len + data_size + hash_parms->pad_len -
((req_opts->is_aead && req_opts->is_inbound) ?
hash_parms->digestsize : 0);
unsigned int cipher_offset = aead_parms->assoc_size +
aead_parms->aad_pad_len + aead_parms->iv_len;
#ifdef DEBUG
unsigned int real_db_size = spu_real_db_size(aead_parms->assoc_size,
aead_parms->iv_len,
hash_parms->prebuf_len,
data_size,
aead_parms->aad_pad_len,
aead_parms->data_pad_len,
hash_parms->pad_len);
#endif
unsigned int assoc_size = aead_parms->assoc_size;
if (req_opts->is_aead &&
(cipher_parms->alg == CIPHER_ALG_AES) &&
(cipher_parms->mode == CIPHER_MODE_GCM))
req_opts->auth_first = req_opts->is_inbound;
if (req_opts->is_aead &&
(cipher_parms->alg == CIPHER_ALG_AES) &&
(cipher_parms->mode == CIPHER_MODE_CCM))
req_opts->auth_first = !req_opts->is_inbound;
flow_log("%s()\n", __func__);
flow_log(" in:%u authFirst:%u\n",
req_opts->is_inbound, req_opts->auth_first);
flow_log(" cipher alg:%u mode:%u type %u\n", cipher_parms->alg,
cipher_parms->mode, cipher_parms->type);
flow_log(" is_esp: %s\n", req_opts->is_esp ? "yes" : "no");
flow_log(" key: %d\n", cipher_parms->key_len);
flow_dump(" key: ", cipher_parms->key_buf, cipher_parms->key_len);
flow_log(" iv: %d\n", cipher_parms->iv_len);
flow_dump(" iv: ", cipher_parms->iv_buf, cipher_parms->iv_len);
flow_log(" auth alg:%u mode:%u type %u\n",
hash_parms->alg, hash_parms->mode, hash_parms->type);
flow_log(" digestsize: %u\n", hash_parms->digestsize);
flow_log(" authkey: %d\n", hash_parms->key_len);
flow_dump(" authkey: ", hash_parms->key_buf, hash_parms->key_len);
flow_log(" assoc_size:%u\n", assoc_size);
flow_log(" prebuf_len:%u\n", hash_parms->prebuf_len);
flow_log(" data_size:%u\n", data_size);
flow_log(" hash_pad_len:%u\n", hash_parms->pad_len);
flow_log(" real_db_size:%u\n", real_db_size);
flow_log(" cipher_offset:%u payload_len:%u\n",
cipher_offset, payload_len);
flow_log(" aead_iv: %u\n", aead_parms->iv_len);
err = spu2_cipher_xlate(cipher_parms->alg, cipher_parms->mode,
cipher_parms->type,
&spu2_ciph_type, &spu2_ciph_mode);
if ((req_opts->is_rfc4543) ||
((spu2_ciph_mode == SPU2_CIPHER_MODE_GCM) &&
(payload_len == 0))) {
spu2_ciph_type = SPU2_CIPHER_TYPE_NONE;
hash_parms->key_len = cipher_parms->key_len;
memcpy(hash_parms->key_buf, cipher_parms->key_buf,
cipher_parms->key_len);
cipher_parms->key_len = 0;
if (req_opts->is_rfc4543)
payload_len += assoc_size;
else
payload_len = assoc_size;
cipher_offset = 0;
assoc_size = 0;
}
if (err)
return 0;
flow_log("spu2 cipher type %s, cipher mode %s\n",
spu2_ciph_type_name(spu2_ciph_type),
spu2_ciph_mode_name(spu2_ciph_mode));
err = spu2_hash_xlate(hash_parms->alg, hash_parms->mode,
hash_parms->type,
cipher_parms->type,
&spu2_auth_type, &spu2_auth_mode);
if (err)
return 0;
flow_log("spu2 hash type %s, hash mode %s\n",
spu2_hash_type_name(spu2_auth_type),
spu2_hash_mode_name(spu2_auth_mode));
fmd = (struct SPU2_FMD *)spu_hdr;
spu2_fmd_ctrl0_write(fmd, req_opts->is_inbound, req_opts->auth_first,
proto, spu2_ciph_type, spu2_ciph_mode,
spu2_auth_type, spu2_auth_mode);
spu2_fmd_ctrl1_write(fmd, req_opts->is_inbound, assoc_size,
hash_parms->key_len, cipher_parms->key_len,
false, false,
aead_parms->return_iv, aead_parms->ret_iv_len,
aead_parms->ret_iv_off,
cipher_parms->iv_len, hash_parms->digestsize,
!req_opts->bd_suppress, return_md);
spu2_fmd_ctrl2_write(fmd, cipher_offset, hash_parms->key_len, 0,
cipher_parms->key_len, cipher_parms->iv_len);
spu2_fmd_ctrl3_write(fmd, payload_len);
ptr = (u8 *)(fmd + 1);
buf_len = sizeof(struct SPU2_FMD);
if (hash_parms->key_len) {
memcpy(ptr, hash_parms->key_buf, hash_parms->key_len);
ptr += hash_parms->key_len;
buf_len += hash_parms->key_len;
}
if (cipher_parms->key_len) {
memcpy(ptr, cipher_parms->key_buf, cipher_parms->key_len);
ptr += cipher_parms->key_len;
buf_len += cipher_parms->key_len;
}
if (cipher_parms->iv_len) {
memcpy(ptr, cipher_parms->iv_buf, cipher_parms->iv_len);
ptr += cipher_parms->iv_len;
buf_len += cipher_parms->iv_len;
}
packet_dump(" SPU request header: ", spu_hdr, buf_len);
return buf_len;
}
u16 spu2_cipher_req_init(u8 *spu_hdr, struct spu_cipher_parms *cipher_parms)
{
struct SPU2_FMD *fmd;
u8 *omd;
enum spu2_cipher_type spu2_type = SPU2_CIPHER_TYPE_NONE;
enum spu2_cipher_mode spu2_mode;
int err;
flow_log("%s()\n", __func__);
flow_log(" cipher alg:%u mode:%u type %u\n", cipher_parms->alg,
cipher_parms->mode, cipher_parms->type);
flow_log(" cipher_iv_len: %u\n", cipher_parms->iv_len);
flow_log(" key: %d\n", cipher_parms->key_len);
flow_dump(" key: ", cipher_parms->key_buf, cipher_parms->key_len);
err = spu2_cipher_xlate(cipher_parms->alg, cipher_parms->mode,
cipher_parms->type, &spu2_type, &spu2_mode);
if (err)
return 0;
flow_log("spu2 cipher type %s, cipher mode %s\n",
spu2_ciph_type_name(spu2_type),
spu2_ciph_mode_name(spu2_mode));
fmd = (struct SPU2_FMD *)spu_hdr;
err = spu2_fmd_init(fmd, spu2_type, spu2_mode, cipher_parms->key_len,
cipher_parms->iv_len);
if (err)
return 0;
omd = (u8 *)(fmd + 1);
if (cipher_parms->key_buf && cipher_parms->key_len)
memcpy(omd, cipher_parms->key_buf, cipher_parms->key_len);
packet_dump(" SPU request header: ", spu_hdr,
FMD_SIZE + cipher_parms->key_len + cipher_parms->iv_len);
return FMD_SIZE + cipher_parms->key_len + cipher_parms->iv_len;
}
void spu2_cipher_req_finish(u8 *spu_hdr,
u16 spu_req_hdr_len,
unsigned int is_inbound,
struct spu_cipher_parms *cipher_parms,
bool update_key,
unsigned int data_size)
{
struct SPU2_FMD *fmd;
u8 *omd;
u64 ctrl0;
u64 ctrl3;
flow_log("%s()\n", __func__);
flow_log(" in: %u\n", is_inbound);
flow_log(" cipher alg: %u, cipher_type: %u\n", cipher_parms->alg,
cipher_parms->type);
if (update_key) {
flow_log(" cipher key len: %u\n", cipher_parms->key_len);
flow_dump(" key: ", cipher_parms->key_buf,
cipher_parms->key_len);
}
flow_log(" iv len: %d\n", cipher_parms->iv_len);
flow_dump(" iv: ", cipher_parms->iv_buf, cipher_parms->iv_len);
flow_log(" data_size: %u\n", data_size);
fmd = (struct SPU2_FMD *)spu_hdr;
omd = (u8 *)(fmd + 1);
ctrl0 = le64_to_cpu(fmd->ctrl0);
if (is_inbound)
ctrl0 &= ~SPU2_CIPH_ENCRYPT_EN;
else
ctrl0 |= SPU2_CIPH_ENCRYPT_EN;
fmd->ctrl0 = cpu_to_le64(ctrl0);
if (cipher_parms->alg && cipher_parms->iv_buf && cipher_parms->iv_len) {
memcpy(omd + cipher_parms->key_len, cipher_parms->iv_buf,
cipher_parms->iv_len);
}
ctrl3 = le64_to_cpu(fmd->ctrl3);
data_size &= SPU2_PL_LEN;
ctrl3 |= data_size;
fmd->ctrl3 = cpu_to_le64(ctrl3);
packet_dump(" SPU request header: ", spu_hdr, spu_req_hdr_len);
}
void spu2_request_pad(u8 *pad_start, u32 gcm_padding, u32 hash_pad_len,
enum hash_alg auth_alg, enum hash_mode auth_mode,
unsigned int total_sent, u32 status_padding)
{
u8 *ptr = pad_start;
if (gcm_padding > 0) {
flow_log(" GCM: padding to 16 byte alignment: %u bytes\n",
gcm_padding);
memset(ptr, 0, gcm_padding);
ptr += gcm_padding;
}
if (hash_pad_len > 0) {
memset(ptr, 0, hash_pad_len);
*ptr = 0x80;
ptr += (hash_pad_len - sizeof(u64));
if (auth_alg == HASH_ALG_MD5)
*(u64 *)ptr = cpu_to_le64((u64)total_sent * 8);
else
*(u64 *)ptr = cpu_to_be64((u64)total_sent * 8);
ptr += sizeof(u64);
}
if (status_padding > 0) {
flow_log(" STAT: padding to 4 byte alignment: %u bytes\n",
status_padding);
memset(ptr, 0, status_padding);
ptr += status_padding;
}
}
u8 spu2_xts_tweak_in_payload(void)
{
return 0;
}
u8 spu2_tx_status_len(void)
{
return SPU2_TX_STATUS_LEN;
}
u8 spu2_rx_status_len(void)
{
return SPU2_RX_STATUS_LEN;
}
int spu2_status_process(u8 *statp)
{
u16 status = le16_to_cpu(*(__le16 *)statp);
if (status == 0)
return 0;
flow_log("rx status is %#x\n", status);
if (status == SPU2_INVALID_ICV)
return SPU_INVALID_ICV;
return -EBADMSG;
}
void spu2_ccm_update_iv(unsigned int digestsize,
struct spu_cipher_parms *cipher_parms,
unsigned int assoclen, unsigned int chunksize,
bool is_encrypt, bool is_esp)
{
int L;
if (is_esp)
L = CCM_ESP_L_VALUE;
else
L = ((cipher_parms->iv_buf[0] & CCM_B0_L_PRIME) >>
CCM_B0_L_PRIME_SHIFT) + 1;
cipher_parms->iv_len -= (1 + L);
memmove(cipher_parms->iv_buf, &cipher_parms->iv_buf[1],
cipher_parms->iv_len);
}
u32 spu2_wordalign_padlen(u32 data_size)
{
return 0;
}
