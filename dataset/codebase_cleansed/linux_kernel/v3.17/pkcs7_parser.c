void pkcs7_free_message(struct pkcs7_message *pkcs7)
{
struct x509_certificate *cert;
struct pkcs7_signed_info *sinfo;
if (pkcs7) {
while (pkcs7->certs) {
cert = pkcs7->certs;
pkcs7->certs = cert->next;
x509_free_certificate(cert);
}
while (pkcs7->crl) {
cert = pkcs7->crl;
pkcs7->crl = cert->next;
x509_free_certificate(cert);
}
while (pkcs7->signed_infos) {
sinfo = pkcs7->signed_infos;
pkcs7->signed_infos = sinfo->next;
mpi_free(sinfo->sig.mpi[0]);
kfree(sinfo->sig.digest);
kfree(sinfo);
}
kfree(pkcs7);
}
}
struct pkcs7_message *pkcs7_parse_message(const void *data, size_t datalen)
{
struct pkcs7_parse_context *ctx;
struct pkcs7_message *msg;
long ret;
ret = -ENOMEM;
msg = kzalloc(sizeof(struct pkcs7_message), GFP_KERNEL);
if (!msg)
goto error_no_sig;
ctx = kzalloc(sizeof(struct pkcs7_parse_context), GFP_KERNEL);
if (!ctx)
goto error_no_ctx;
ctx->sinfo = kzalloc(sizeof(struct pkcs7_signed_info), GFP_KERNEL);
if (!ctx->sinfo)
goto error_no_sinfo;
ctx->msg = msg;
ctx->data = (unsigned long)data;
ctx->ppcerts = &ctx->certs;
ctx->ppsinfo = &ctx->msg->signed_infos;
ret = asn1_ber_decoder(&pkcs7_decoder, ctx, data, datalen);
if (ret < 0)
goto error_decode;
while (ctx->certs) {
struct x509_certificate *cert = ctx->certs;
ctx->certs = cert->next;
x509_free_certificate(cert);
}
mpi_free(ctx->sinfo->sig.mpi[0]);
kfree(ctx->sinfo->sig.digest);
kfree(ctx->sinfo);
kfree(ctx);
return msg;
error_decode:
mpi_free(ctx->sinfo->sig.mpi[0]);
kfree(ctx->sinfo->sig.digest);
kfree(ctx->sinfo);
error_no_sinfo:
kfree(ctx);
error_no_ctx:
pkcs7_free_message(msg);
error_no_sig:
return ERR_PTR(ret);
}
int pkcs7_get_content_data(const struct pkcs7_message *pkcs7,
const void **_data, size_t *_data_len,
bool want_wrapper)
{
size_t wrapper;
if (!pkcs7->data)
return -ENODATA;
wrapper = want_wrapper ? pkcs7->data_hdrlen : 0;
*_data = pkcs7->data - wrapper;
*_data_len = pkcs7->data_len + wrapper;
return 0;
}
int pkcs7_note_OID(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
ctx->last_oid = look_up_OID(value, vlen);
if (ctx->last_oid == OID__NR) {
char buffer[50];
sprint_oid(value, vlen, buffer, sizeof(buffer));
printk("PKCS7: Unknown OID: [%lu] %s\n",
(unsigned long)value - ctx->data, buffer);
}
return 0;
}
int pkcs7_sig_note_digest_algo(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
switch (ctx->last_oid) {
case OID_md4:
ctx->sinfo->sig.pkey_hash_algo = HASH_ALGO_MD4;
break;
case OID_md5:
ctx->sinfo->sig.pkey_hash_algo = HASH_ALGO_MD5;
break;
case OID_sha1:
ctx->sinfo->sig.pkey_hash_algo = HASH_ALGO_SHA1;
break;
case OID_sha256:
ctx->sinfo->sig.pkey_hash_algo = HASH_ALGO_SHA256;
break;
default:
printk("Unsupported digest algo: %u\n", ctx->last_oid);
return -ENOPKG;
}
return 0;
}
int pkcs7_sig_note_pkey_algo(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
switch (ctx->last_oid) {
case OID_rsaEncryption:
ctx->sinfo->sig.pkey_algo = PKEY_ALGO_RSA;
break;
default:
printk("Unsupported pkey algo: %u\n", ctx->last_oid);
return -ENOPKG;
}
return 0;
}
int pkcs7_extract_cert(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
struct x509_certificate *x509;
if (tag != ((ASN1_UNIV << 6) | ASN1_CONS_BIT | ASN1_SEQ)) {
pr_debug("Cert began with tag %02x at %lu\n",
tag, (unsigned long)ctx - ctx->data);
return -EBADMSG;
}
value -= hdrlen;
vlen += hdrlen;
if (((u8*)value)[1] == 0x80)
vlen += 2;
x509 = x509_cert_parse(value, vlen);
if (IS_ERR(x509))
return PTR_ERR(x509);
pr_debug("Got cert for %s\n", x509->subject);
pr_debug("- fingerprint %s\n", x509->fingerprint);
x509->index = ++ctx->x509_index;
*ctx->ppcerts = x509;
ctx->ppcerts = &x509->next;
return 0;
}
int pkcs7_note_certificate_list(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
pr_devel("Got cert list (%02x)\n", tag);
*ctx->ppcerts = ctx->msg->certs;
ctx->msg->certs = ctx->certs;
ctx->certs = NULL;
ctx->ppcerts = &ctx->certs;
return 0;
}
int pkcs7_note_data(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
pr_debug("Got data\n");
ctx->msg->data = value;
ctx->msg->data_len = vlen;
ctx->msg->data_hdrlen = hdrlen;
ctx->msg->data_type = ctx->last_oid;
return 0;
}
int pkcs7_sig_note_authenticated_attr(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
pr_devel("AuthAttr: %02x %zu [%*ph]\n", tag, vlen, (unsigned)vlen, value);
switch (ctx->last_oid) {
case OID_messageDigest:
if (tag != ASN1_OTS)
return -EBADMSG;
ctx->sinfo->msgdigest = value;
ctx->sinfo->msgdigest_len = vlen;
return 0;
default:
return 0;
}
}
int pkcs7_sig_note_set_of_authattrs(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
ctx->sinfo->authattrs = value - (hdrlen - 1);
ctx->sinfo->authattrs_len = vlen + (hdrlen - 1);
return 0;
}
int pkcs7_sig_note_serial(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
ctx->sinfo->raw_serial = value;
ctx->sinfo->raw_serial_size = vlen;
return 0;
}
int pkcs7_sig_note_issuer(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
ctx->sinfo->raw_issuer = value;
ctx->sinfo->raw_issuer_size = vlen;
return 0;
}
int pkcs7_sig_note_signature(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
MPI mpi;
BUG_ON(ctx->sinfo->sig.pkey_algo != PKEY_ALGO_RSA);
mpi = mpi_read_raw_data(value, vlen);
if (!mpi)
return -ENOMEM;
ctx->sinfo->sig.mpi[0] = mpi;
ctx->sinfo->sig.nr_mpi = 1;
return 0;
}
int pkcs7_note_signed_info(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct pkcs7_parse_context *ctx = context;
ctx->sinfo->index = ++ctx->sinfo_index;
*ctx->ppsinfo = ctx->sinfo;
ctx->ppsinfo = &ctx->sinfo->next;
ctx->sinfo = kzalloc(sizeof(struct pkcs7_signed_info), GFP_KERNEL);
if (!ctx->sinfo)
return -ENOMEM;
return 0;
}
