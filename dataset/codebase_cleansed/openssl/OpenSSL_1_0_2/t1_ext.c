static custom_ext_method *custom_ext_find(custom_ext_methods *exts,
unsigned int ext_type)
{
size_t i;
custom_ext_method *meth = exts->meths;
for (i = 0; i < exts->meths_count; i++, meth++) {
if (ext_type == meth->ext_type)
return meth;
}
return NULL;
}
void custom_ext_init(custom_ext_methods *exts)
{
size_t i;
custom_ext_method *meth = exts->meths;
for (i = 0; i < exts->meths_count; i++, meth++)
meth->ext_flags = 0;
}
int custom_ext_parse(SSL *s, int server,
unsigned int ext_type,
const unsigned char *ext_data, size_t ext_size, int *al)
{
custom_ext_methods *exts = server ? &s->cert->srv_ext : &s->cert->cli_ext;
custom_ext_method *meth;
meth = custom_ext_find(exts, ext_type);
if (!meth)
return 1;
if (!server) {
if (!(meth->ext_flags & SSL_EXT_FLAG_SENT)) {
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
}
if (meth->ext_flags & SSL_EXT_FLAG_RECEIVED) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
meth->ext_flags |= SSL_EXT_FLAG_RECEIVED;
if (!meth->parse_cb)
return 1;
return meth->parse_cb(s, ext_type, ext_data, ext_size, al,
meth->parse_arg);
}
int custom_ext_add(SSL *s, int server,
unsigned char **pret, unsigned char *limit, int *al)
{
custom_ext_methods *exts = server ? &s->cert->srv_ext : &s->cert->cli_ext;
custom_ext_method *meth;
unsigned char *ret = *pret;
size_t i;
for (i = 0; i < exts->meths_count; i++) {
const unsigned char *out = NULL;
size_t outlen = 0;
meth = exts->meths + i;
if (server) {
if (!(meth->ext_flags & SSL_EXT_FLAG_RECEIVED))
continue;
if (!meth->add_cb)
continue;
}
if (meth->add_cb) {
int cb_retval = 0;
cb_retval = meth->add_cb(s, meth->ext_type,
&out, &outlen, al, meth->add_arg);
if (cb_retval < 0)
return 0;
if (cb_retval == 0)
continue;
}
if (4 > limit - ret || outlen > (size_t)(limit - ret - 4))
return 0;
s2n(meth->ext_type, ret);
s2n(outlen, ret);
if (outlen) {
memcpy(ret, out, outlen);
ret += outlen;
}
OPENSSL_assert(!(meth->ext_flags & SSL_EXT_FLAG_SENT));
meth->ext_flags |= SSL_EXT_FLAG_SENT;
if (meth->free_cb)
meth->free_cb(s, meth->ext_type, out, meth->add_arg);
}
*pret = ret;
return 1;
}
int custom_exts_copy(custom_ext_methods *dst, const custom_ext_methods *src)
{
if (src->meths_count) {
dst->meths =
BUF_memdup(src->meths,
sizeof(custom_ext_method) * src->meths_count);
if (dst->meths == NULL)
return 0;
dst->meths_count = src->meths_count;
}
return 1;
}
void custom_exts_free(custom_ext_methods *exts)
{
if (exts->meths)
OPENSSL_free(exts->meths);
}
static int custom_ext_meth_add(custom_ext_methods *exts,
unsigned int ext_type,
custom_ext_add_cb add_cb,
custom_ext_free_cb free_cb,
void *add_arg,
custom_ext_parse_cb parse_cb, void *parse_arg)
{
custom_ext_method *meth;
if (!add_cb && free_cb)
return 0;
if (SSL_extension_supported(ext_type))
return 0;
if (ext_type > 0xffff)
return 0;
if (custom_ext_find(exts, ext_type))
return 0;
exts->meths = OPENSSL_realloc(exts->meths,
(exts->meths_count +
1) * sizeof(custom_ext_method));
if (!exts->meths) {
exts->meths_count = 0;
return 0;
}
meth = exts->meths + exts->meths_count;
memset(meth, 0, sizeof(custom_ext_method));
meth->parse_cb = parse_cb;
meth->add_cb = add_cb;
meth->free_cb = free_cb;
meth->ext_type = ext_type;
meth->add_arg = add_arg;
meth->parse_arg = parse_arg;
exts->meths_count++;
return 1;
}
int SSL_CTX_add_client_custom_ext(SSL_CTX *ctx, unsigned int ext_type,
custom_ext_add_cb add_cb,
custom_ext_free_cb free_cb,
void *add_arg,
custom_ext_parse_cb parse_cb,
void *parse_arg)
{
return custom_ext_meth_add(&ctx->cert->cli_ext, ext_type,
add_cb, free_cb, add_arg, parse_cb, parse_arg);
}
int SSL_CTX_add_server_custom_ext(SSL_CTX *ctx, unsigned int ext_type,
custom_ext_add_cb add_cb,
custom_ext_free_cb free_cb,
void *add_arg,
custom_ext_parse_cb parse_cb,
void *parse_arg)
{
return custom_ext_meth_add(&ctx->cert->srv_ext, ext_type,
add_cb, free_cb, add_arg, parse_cb, parse_arg);
}
int SSL_extension_supported(unsigned int ext_type)
{
switch (ext_type) {
case TLSEXT_TYPE_application_layer_protocol_negotiation:
case TLSEXT_TYPE_ec_point_formats:
case TLSEXT_TYPE_elliptic_curves:
case TLSEXT_TYPE_heartbeat:
case TLSEXT_TYPE_next_proto_neg:
case TLSEXT_TYPE_padding:
case TLSEXT_TYPE_renegotiate:
case TLSEXT_TYPE_server_name:
case TLSEXT_TYPE_session_ticket:
case TLSEXT_TYPE_signature_algorithms:
case TLSEXT_TYPE_srp:
case TLSEXT_TYPE_status_request:
case TLSEXT_TYPE_use_srtp:
# ifdef TLSEXT_TYPE_opaque_prf_input
case TLSEXT_TYPE_opaque_prf_input:
# endif
# ifdef TLSEXT_TYPE_encrypt_then_mac
case TLSEXT_TYPE_encrypt_then_mac:
# endif
return 1;
default:
return 0;
}
}
