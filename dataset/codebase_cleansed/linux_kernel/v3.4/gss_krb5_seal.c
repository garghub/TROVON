static char *
setup_token(struct krb5_ctx *ctx, struct xdr_netobj *token)
{
__be16 *ptr, *krb5_hdr;
int body_size = GSS_KRB5_TOK_HDR_LEN + ctx->gk5e->cksumlength;
token->len = g_token_size(&ctx->mech_used, body_size);
ptr = (__be16 *)token->data;
g_make_token_header(&ctx->mech_used, body_size, (unsigned char **)&ptr);
krb5_hdr = ptr;
*ptr++ = KG_TOK_MIC_MSG;
*ptr++ = cpu_to_le16(ctx->gk5e->signalg);
*ptr++ = SEAL_ALG_NONE;
*ptr++ = 0xffff;
return (char *)krb5_hdr;
}
static void *
setup_token_v2(struct krb5_ctx *ctx, struct xdr_netobj *token)
{
__be16 *ptr, *krb5_hdr;
u8 *p, flags = 0x00;
if ((ctx->flags & KRB5_CTX_FLAG_INITIATOR) == 0)
flags |= 0x01;
if (ctx->flags & KRB5_CTX_FLAG_ACCEPTOR_SUBKEY)
flags |= 0x04;
krb5_hdr = ptr = (__be16 *)token->data;
*ptr++ = KG2_TOK_MIC;
p = (u8 *)ptr;
*p++ = flags;
*p++ = 0xff;
ptr = (__be16 *)p;
*ptr++ = 0xffff;
*ptr++ = 0xffff;
token->len = GSS_KRB5_TOK_HDR_LEN + ctx->gk5e->cksumlength;
return krb5_hdr;
}
static u32
gss_get_mic_v1(struct krb5_ctx *ctx, struct xdr_buf *text,
struct xdr_netobj *token)
{
char cksumdata[GSS_KRB5_MAX_CKSUM_LEN];
struct xdr_netobj md5cksum = {.len = sizeof(cksumdata),
.data = cksumdata};
void *ptr;
s32 now;
u32 seq_send;
u8 *cksumkey;
dprintk("RPC: %s\n", __func__);
BUG_ON(ctx == NULL);
now = get_seconds();
ptr = setup_token(ctx, token);
if (ctx->gk5e->keyed_cksum)
cksumkey = ctx->cksum;
else
cksumkey = NULL;
if (make_checksum(ctx, ptr, 8, text, 0, cksumkey,
KG_USAGE_SIGN, &md5cksum))
return GSS_S_FAILURE;
memcpy(ptr + GSS_KRB5_TOK_HDR_LEN, md5cksum.data, md5cksum.len);
spin_lock(&krb5_seq_lock);
seq_send = ctx->seq_send++;
spin_unlock(&krb5_seq_lock);
if (krb5_make_seq_num(ctx, ctx->seq, ctx->initiate ? 0 : 0xff,
seq_send, ptr + GSS_KRB5_TOK_HDR_LEN, ptr + 8))
return GSS_S_FAILURE;
return (ctx->endtime < now) ? GSS_S_CONTEXT_EXPIRED : GSS_S_COMPLETE;
}
static u32
gss_get_mic_v2(struct krb5_ctx *ctx, struct xdr_buf *text,
struct xdr_netobj *token)
{
char cksumdata[GSS_KRB5_MAX_CKSUM_LEN];
struct xdr_netobj cksumobj = { .len = sizeof(cksumdata),
.data = cksumdata};
void *krb5_hdr;
s32 now;
u64 seq_send;
u8 *cksumkey;
unsigned int cksum_usage;
dprintk("RPC: %s\n", __func__);
krb5_hdr = setup_token_v2(ctx, token);
spin_lock(&krb5_seq_lock);
seq_send = ctx->seq_send64++;
spin_unlock(&krb5_seq_lock);
*((u64 *)(krb5_hdr + 8)) = cpu_to_be64(seq_send);
if (ctx->initiate) {
cksumkey = ctx->initiator_sign;
cksum_usage = KG_USAGE_INITIATOR_SIGN;
} else {
cksumkey = ctx->acceptor_sign;
cksum_usage = KG_USAGE_ACCEPTOR_SIGN;
}
if (make_checksum_v2(ctx, krb5_hdr, GSS_KRB5_TOK_HDR_LEN,
text, 0, cksumkey, cksum_usage, &cksumobj))
return GSS_S_FAILURE;
memcpy(krb5_hdr + GSS_KRB5_TOK_HDR_LEN, cksumobj.data, cksumobj.len);
now = get_seconds();
return (ctx->endtime < now) ? GSS_S_CONTEXT_EXPIRED : GSS_S_COMPLETE;
}
u32
gss_get_mic_kerberos(struct gss_ctx *gss_ctx, struct xdr_buf *text,
struct xdr_netobj *token)
{
struct krb5_ctx *ctx = gss_ctx->internal_ctx_id;
switch (ctx->enctype) {
default:
BUG();
case ENCTYPE_DES_CBC_RAW:
case ENCTYPE_DES3_CBC_RAW:
case ENCTYPE_ARCFOUR_HMAC:
return gss_get_mic_v1(ctx, text, token);
case ENCTYPE_AES128_CTS_HMAC_SHA1_96:
case ENCTYPE_AES256_CTS_HMAC_SHA1_96:
return gss_get_mic_v2(ctx, text, token);
}
}
