void x509_free_certificate(struct x509_certificate *cert)
{
if (cert) {
public_key_destroy(cert->pub);
kfree(cert->issuer);
kfree(cert->subject);
kfree(cert->fingerprint);
kfree(cert->authority);
kfree(cert);
}
}
struct x509_certificate *x509_cert_parse(const void *data, size_t datalen)
{
struct x509_certificate *cert;
struct x509_parse_context *ctx;
long ret;
ret = -ENOMEM;
cert = kzalloc(sizeof(struct x509_certificate), GFP_KERNEL);
if (!cert)
goto error_no_cert;
cert->pub = kzalloc(sizeof(struct public_key), GFP_KERNEL);
if (!cert->pub)
goto error_no_ctx;
ctx = kzalloc(sizeof(struct x509_parse_context), GFP_KERNEL);
if (!ctx)
goto error_no_ctx;
ctx->cert = cert;
ctx->data = (unsigned long)data;
ret = asn1_ber_decoder(&x509_decoder, ctx, data, datalen);
if (ret < 0)
goto error_decode;
ret = asn1_ber_decoder(&x509_rsakey_decoder, ctx,
ctx->key, ctx->key_size);
if (ret < 0)
goto error_decode;
kfree(ctx);
return cert;
error_decode:
kfree(ctx);
error_no_ctx:
x509_free_certificate(cert);
error_no_cert:
return ERR_PTR(ret);
}
int x509_note_OID(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
ctx->last_oid = look_up_OID(value, vlen);
if (ctx->last_oid == OID__NR) {
char buffer[50];
sprint_oid(value, vlen, buffer, sizeof(buffer));
pr_debug("Unknown OID: [%lu] %s\n",
(unsigned long)value - ctx->data, buffer);
}
return 0;
}
int x509_note_tbs_certificate(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
pr_debug("x509_note_tbs_certificate(,%zu,%02x,%ld,%zu)!\n",
hdrlen, tag, (unsigned long)value - ctx->data, vlen);
ctx->cert->tbs = value - hdrlen;
ctx->cert->tbs_size = vlen + hdrlen;
return 0;
}
int x509_note_pkey_algo(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
pr_debug("PubKey Algo: %u\n", ctx->last_oid);
switch (ctx->last_oid) {
case OID_md2WithRSAEncryption:
case OID_md3WithRSAEncryption:
default:
return -ENOPKG;
case OID_md4WithRSAEncryption:
ctx->cert->sig_hash_algo = PKEY_HASH_MD5;
ctx->cert->sig_pkey_algo = PKEY_ALGO_RSA;
break;
case OID_sha1WithRSAEncryption:
ctx->cert->sig_hash_algo = PKEY_HASH_SHA1;
ctx->cert->sig_pkey_algo = PKEY_ALGO_RSA;
break;
case OID_sha256WithRSAEncryption:
ctx->cert->sig_hash_algo = PKEY_HASH_SHA256;
ctx->cert->sig_pkey_algo = PKEY_ALGO_RSA;
break;
case OID_sha384WithRSAEncryption:
ctx->cert->sig_hash_algo = PKEY_HASH_SHA384;
ctx->cert->sig_pkey_algo = PKEY_ALGO_RSA;
break;
case OID_sha512WithRSAEncryption:
ctx->cert->sig_hash_algo = PKEY_HASH_SHA512;
ctx->cert->sig_pkey_algo = PKEY_ALGO_RSA;
break;
case OID_sha224WithRSAEncryption:
ctx->cert->sig_hash_algo = PKEY_HASH_SHA224;
ctx->cert->sig_pkey_algo = PKEY_ALGO_RSA;
break;
}
ctx->algo_oid = ctx->last_oid;
return 0;
}
int x509_note_signature(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
pr_debug("Signature type: %u size %zu\n", ctx->last_oid, vlen);
if (ctx->last_oid != ctx->algo_oid) {
pr_warn("Got cert with pkey (%u) and sig (%u) algorithm OIDs\n",
ctx->algo_oid, ctx->last_oid);
return -EINVAL;
}
ctx->cert->sig = value;
ctx->cert->sig_size = vlen;
return 0;
}
int x509_extract_name_segment(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
switch (ctx->last_oid) {
case OID_commonName:
ctx->cn_size = vlen;
ctx->cn_offset = (unsigned long)value - ctx->data;
break;
case OID_organizationName:
ctx->o_size = vlen;
ctx->o_offset = (unsigned long)value - ctx->data;
break;
case OID_email_address:
ctx->email_size = vlen;
ctx->email_offset = (unsigned long)value - ctx->data;
break;
default:
break;
}
return 0;
}
static int x509_fabricate_name(struct x509_parse_context *ctx, size_t hdrlen,
unsigned char tag,
char **_name, size_t vlen)
{
const void *name, *data = (const void *)ctx->data;
size_t namesize;
char *buffer;
if (*_name)
return -EINVAL;
if (!ctx->cn_size && !ctx->o_size && !ctx->email_size) {
buffer = kmalloc(1, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
buffer[0] = 0;
goto done;
}
if (ctx->cn_size && ctx->o_size) {
namesize = ctx->cn_size;
name = data + ctx->cn_offset;
if (ctx->cn_size >= ctx->o_size &&
memcmp(data + ctx->cn_offset, data + ctx->o_offset,
ctx->o_size) == 0)
goto single_component;
if (ctx->cn_size >= 7 &&
ctx->o_size >= 7 &&
memcmp(data + ctx->cn_offset, data + ctx->o_offset, 7) == 0)
goto single_component;
buffer = kmalloc(ctx->o_size + 2 + ctx->cn_size + 1,
GFP_KERNEL);
if (!buffer)
return -ENOMEM;
memcpy(buffer,
data + ctx->o_offset, ctx->o_size);
buffer[ctx->o_size + 0] = ':';
buffer[ctx->o_size + 1] = ' ';
memcpy(buffer + ctx->o_size + 2,
data + ctx->cn_offset, ctx->cn_size);
buffer[ctx->o_size + 2 + ctx->cn_size] = 0;
goto done;
} else if (ctx->cn_size) {
namesize = ctx->cn_size;
name = data + ctx->cn_offset;
} else if (ctx->o_size) {
namesize = ctx->o_size;
name = data + ctx->o_offset;
} else {
namesize = ctx->email_size;
name = data + ctx->email_offset;
}
single_component:
buffer = kmalloc(namesize + 1, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
memcpy(buffer, name, namesize);
buffer[namesize] = 0;
done:
*_name = buffer;
ctx->cn_size = 0;
ctx->o_size = 0;
ctx->email_size = 0;
return 0;
}
int x509_note_issuer(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
return x509_fabricate_name(ctx, hdrlen, tag, &ctx->cert->issuer, vlen);
}
int x509_note_subject(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
return x509_fabricate_name(ctx, hdrlen, tag, &ctx->cert->subject, vlen);
}
int x509_extract_key_data(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
if (ctx->last_oid != OID_rsaEncryption)
return -ENOPKG;
ctx->cert->pkey_algo = PKEY_ALGO_RSA;
ctx->key = value + 1;
ctx->key_size = vlen - 1;
return 0;
}
int rsa_extract_mpi(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
MPI mpi;
if (ctx->nr_mpi >= ARRAY_SIZE(ctx->cert->pub->mpi)) {
pr_err("Too many public key MPIs in certificate\n");
return -EBADMSG;
}
mpi = mpi_read_raw_data(value, vlen);
if (!mpi)
return -ENOMEM;
ctx->cert->pub->mpi[ctx->nr_mpi++] = mpi;
return 0;
}
int x509_process_extension(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
const unsigned char *v = value;
char *f;
int i;
pr_debug("Extension: %u\n", ctx->last_oid);
if (ctx->last_oid == OID_subjectKeyIdentifier) {
if (vlen < 3)
return -EBADMSG;
if (v[0] != ASN1_OTS || v[1] != vlen - 2)
return -EBADMSG;
v += 2;
vlen -= 2;
f = kmalloc(vlen * 2 + 1, GFP_KERNEL);
if (!f)
return -ENOMEM;
for (i = 0; i < vlen; i++)
sprintf(f + i * 2, "%02x", v[i]);
pr_debug("fingerprint %s\n", f);
ctx->cert->fingerprint = f;
return 0;
}
if (ctx->last_oid == OID_authorityKeyIdentifier) {
if (vlen < 5)
return -EBADMSG;
if (v[0] != (ASN1_SEQ | (ASN1_CONS << 5)) ||
v[1] != vlen - 2 ||
v[2] != (ASN1_CONT << 6) ||
v[3] != vlen - 4)
return -EBADMSG;
v += 4;
vlen -= 4;
f = kmalloc(vlen * 2 + 1, GFP_KERNEL);
if (!f)
return -ENOMEM;
for (i = 0; i < vlen; i++)
sprintf(f + i * 2, "%02x", v[i]);
pr_debug("authority %s\n", f);
ctx->cert->authority = f;
return 0;
}
return 0;
}
static int x509_note_time(struct tm *tm, size_t hdrlen,
unsigned char tag,
const unsigned char *value, size_t vlen)
{
const unsigned char *p = value;
#define dec2bin(X) ((X) - '0')
#define DD2bin(P) ({ unsigned x = dec2bin(P[0]) * 10 + dec2bin(P[1]); P += 2; x; })
if (tag == ASN1_UNITIM) {
if (vlen != 13)
goto unsupported_time;
tm->tm_year = DD2bin(p);
if (tm->tm_year >= 50)
tm->tm_year += 1900;
else
tm->tm_year += 2000;
} else if (tag == ASN1_GENTIM) {
if (vlen != 15)
goto unsupported_time;
tm->tm_year = DD2bin(p) * 100 + DD2bin(p);
} else {
goto unsupported_time;
}
tm->tm_year -= 1900;
tm->tm_mon = DD2bin(p) - 1;
tm->tm_mday = DD2bin(p);
tm->tm_hour = DD2bin(p);
tm->tm_min = DD2bin(p);
tm->tm_sec = DD2bin(p);
if (*p != 'Z')
goto unsupported_time;
return 0;
unsupported_time:
pr_debug("Got unsupported time [tag %02x]: '%*.*s'\n",
tag, (int)vlen, (int)vlen, value);
return -EBADMSG;
}
int x509_note_not_before(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
return x509_note_time(&ctx->cert->valid_from, hdrlen, tag, value, vlen);
}
int x509_note_not_after(void *context, size_t hdrlen,
unsigned char tag,
const void *value, size_t vlen)
{
struct x509_parse_context *ctx = context;
return x509_note_time(&ctx->cert->valid_to, hdrlen, tag, value, vlen);
}
