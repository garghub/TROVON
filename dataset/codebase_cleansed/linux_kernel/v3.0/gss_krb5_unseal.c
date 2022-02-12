static u32
gss_verify_mic_v1(struct krb5_ctx *ctx,
struct xdr_buf *message_buffer, struct xdr_netobj *read_token)
{
int signalg;
int sealalg;
char cksumdata[GSS_KRB5_MAX_CKSUM_LEN];
struct xdr_netobj md5cksum = {.len = sizeof(cksumdata),
.data = cksumdata};
s32 now;
int direction;
u32 seqnum;
unsigned char *ptr = (unsigned char *)read_token->data;
int bodysize;
u8 *cksumkey;
dprintk("RPC: krb5_read_token\n");
if (g_verify_token_header(&ctx->mech_used, &bodysize, &ptr,
read_token->len))
return GSS_S_DEFECTIVE_TOKEN;
if ((ptr[0] != ((KG_TOK_MIC_MSG >> 8) & 0xff)) ||
(ptr[1] != (KG_TOK_MIC_MSG & 0xff)))
return GSS_S_DEFECTIVE_TOKEN;
signalg = ptr[2] + (ptr[3] << 8);
if (signalg != ctx->gk5e->signalg)
return GSS_S_DEFECTIVE_TOKEN;
sealalg = ptr[4] + (ptr[5] << 8);
if (sealalg != SEAL_ALG_NONE)
return GSS_S_DEFECTIVE_TOKEN;
if ((ptr[6] != 0xff) || (ptr[7] != 0xff))
return GSS_S_DEFECTIVE_TOKEN;
if (ctx->gk5e->keyed_cksum)
cksumkey = ctx->cksum;
else
cksumkey = NULL;
if (make_checksum(ctx, ptr, 8, message_buffer, 0,
cksumkey, KG_USAGE_SIGN, &md5cksum))
return GSS_S_FAILURE;
if (memcmp(md5cksum.data, ptr + GSS_KRB5_TOK_HDR_LEN,
ctx->gk5e->cksumlength))
return GSS_S_BAD_SIG;
now = get_seconds();
if (now > ctx->endtime)
return GSS_S_CONTEXT_EXPIRED;
if (krb5_get_seq_num(ctx, ptr + GSS_KRB5_TOK_HDR_LEN, ptr + 8,
&direction, &seqnum))
return GSS_S_FAILURE;
if ((ctx->initiate && direction != 0xff) ||
(!ctx->initiate && direction != 0))
return GSS_S_BAD_SIG;
return GSS_S_COMPLETE;
}
static u32
gss_verify_mic_v2(struct krb5_ctx *ctx,
struct xdr_buf *message_buffer, struct xdr_netobj *read_token)
{
char cksumdata[GSS_KRB5_MAX_CKSUM_LEN];
struct xdr_netobj cksumobj = {.len = sizeof(cksumdata),
.data = cksumdata};
s32 now;
u64 seqnum;
u8 *ptr = read_token->data;
u8 *cksumkey;
u8 flags;
int i;
unsigned int cksum_usage;
dprintk("RPC: %s\n", __func__);
if (be16_to_cpu(*((__be16 *)ptr)) != KG2_TOK_MIC)
return GSS_S_DEFECTIVE_TOKEN;
flags = ptr[2];
if ((!ctx->initiate && (flags & KG2_TOKEN_FLAG_SENTBYACCEPTOR)) ||
(ctx->initiate && !(flags & KG2_TOKEN_FLAG_SENTBYACCEPTOR)))
return GSS_S_BAD_SIG;
if (flags & KG2_TOKEN_FLAG_SEALED) {
dprintk("%s: token has unexpected sealed flag\n", __func__);
return GSS_S_FAILURE;
}
for (i = 3; i < 8; i++)
if (ptr[i] != 0xff)
return GSS_S_DEFECTIVE_TOKEN;
if (ctx->initiate) {
cksumkey = ctx->acceptor_sign;
cksum_usage = KG_USAGE_ACCEPTOR_SIGN;
} else {
cksumkey = ctx->initiator_sign;
cksum_usage = KG_USAGE_INITIATOR_SIGN;
}
if (make_checksum_v2(ctx, ptr, GSS_KRB5_TOK_HDR_LEN, message_buffer, 0,
cksumkey, cksum_usage, &cksumobj))
return GSS_S_FAILURE;
if (memcmp(cksumobj.data, ptr + GSS_KRB5_TOK_HDR_LEN,
ctx->gk5e->cksumlength))
return GSS_S_BAD_SIG;
now = get_seconds();
if (now > ctx->endtime)
return GSS_S_CONTEXT_EXPIRED;
seqnum = be64_to_cpup((__be64 *)ptr + 8);
return GSS_S_COMPLETE;
}
u32
gss_verify_mic_kerberos(struct gss_ctx *gss_ctx,
struct xdr_buf *message_buffer,
struct xdr_netobj *read_token)
{
struct krb5_ctx *ctx = gss_ctx->internal_ctx_id;
switch (ctx->enctype) {
default:
BUG();
case ENCTYPE_DES_CBC_RAW:
case ENCTYPE_DES3_CBC_RAW:
case ENCTYPE_ARCFOUR_HMAC:
return gss_verify_mic_v1(ctx, message_buffer, read_token);
case ENCTYPE_AES128_CTS_HMAC_SHA1_96:
case ENCTYPE_AES256_CTS_HMAC_SHA1_96:
return gss_verify_mic_v2(ctx, message_buffer, read_token);
}
}
