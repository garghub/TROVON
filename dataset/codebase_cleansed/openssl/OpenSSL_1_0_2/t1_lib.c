long tls1_default_timeout(void)
{
return (60 * 60 * 2);
}
int tls1_new(SSL *s)
{
if (!ssl3_new(s))
return (0);
s->method->ssl_clear(s);
return (1);
}
void tls1_free(SSL *s)
{
#ifndef OPENSSL_NO_TLSEXT
if (s->tlsext_session_ticket) {
OPENSSL_free(s->tlsext_session_ticket);
}
#endif
ssl3_free(s);
}
void tls1_clear(SSL *s)
{
ssl3_clear(s);
s->version = s->method->version;
}
int tls1_ec_curve_id2nid(int curve_id)
{
if ((curve_id < 1) || ((unsigned int)curve_id >
sizeof(nid_list) / sizeof(nid_list[0])))
return 0;
return nid_list[curve_id - 1];
}
int tls1_ec_nid2curve_id(int nid)
{
switch (nid) {
case NID_sect163k1:
return 1;
case NID_sect163r1:
return 2;
case NID_sect163r2:
return 3;
case NID_sect193r1:
return 4;
case NID_sect193r2:
return 5;
case NID_sect233k1:
return 6;
case NID_sect233r1:
return 7;
case NID_sect239k1:
return 8;
case NID_sect283k1:
return 9;
case NID_sect283r1:
return 10;
case NID_sect409k1:
return 11;
case NID_sect409r1:
return 12;
case NID_sect571k1:
return 13;
case NID_sect571r1:
return 14;
case NID_secp160k1:
return 15;
case NID_secp160r1:
return 16;
case NID_secp160r2:
return 17;
case NID_secp192k1:
return 18;
case NID_X9_62_prime192v1:
return 19;
case NID_secp224k1:
return 20;
case NID_secp224r1:
return 21;
case NID_secp256k1:
return 22;
case NID_X9_62_prime256v1:
return 23;
case NID_secp384r1:
return 24;
case NID_secp521r1:
return 25;
case NID_brainpoolP256r1:
return 26;
case NID_brainpoolP384r1:
return 27;
case NID_brainpoolP512r1:
return 28;
default:
return 0;
}
}
static int tls1_get_curvelist(SSL *s, int sess,
const unsigned char **pcurves,
size_t *num_curves)
{
size_t pcurveslen = 0;
if (sess) {
*pcurves = s->session->tlsext_ellipticcurvelist;
pcurveslen = s->session->tlsext_ellipticcurvelist_length;
} else {
switch (tls1_suiteb(s)) {
case SSL_CERT_FLAG_SUITEB_128_LOS:
*pcurves = suiteb_curves;
pcurveslen = sizeof(suiteb_curves);
break;
case SSL_CERT_FLAG_SUITEB_128_LOS_ONLY:
*pcurves = suiteb_curves;
pcurveslen = 2;
break;
case SSL_CERT_FLAG_SUITEB_192_LOS:
*pcurves = suiteb_curves + 2;
pcurveslen = 2;
break;
default:
*pcurves = s->tlsext_ellipticcurvelist;
pcurveslen = s->tlsext_ellipticcurvelist_length;
}
if (!*pcurves) {
# ifdef OPENSSL_FIPS
if (FIPS_mode()) {
*pcurves = fips_curves_default;
*pcurveslen = sizeof(fips_curves_default);
} else
# endif
{
*pcurves = eccurves_default;
pcurveslen = sizeof(eccurves_default);
}
}
}
if (pcurveslen & 1) {
SSLerr(SSL_F_TLS1_GET_CURVELIST, ERR_R_INTERNAL_ERROR);
*num_curves = 0;
return 0;
} else {
*num_curves = pcurveslen / 2;
return 1;
}
}
int tls1_check_curve(SSL *s, const unsigned char *p, size_t len)
{
const unsigned char *curves;
size_t num_curves, i;
unsigned int suiteb_flags = tls1_suiteb(s);
if (len != 3 || p[0] != NAMED_CURVE_TYPE)
return 0;
if (suiteb_flags) {
unsigned long cid = s->s3->tmp.new_cipher->id;
if (p[1])
return 0;
if (cid == TLS1_CK_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256) {
if (p[2] != TLSEXT_curve_P_256)
return 0;
} else if (cid == TLS1_CK_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384) {
if (p[2] != TLSEXT_curve_P_384)
return 0;
} else
return 0;
}
if (!tls1_get_curvelist(s, 0, &curves, &num_curves))
return 0;
for (i = 0; i < num_curves; i++, curves += 2) {
if (p[1] == curves[0] && p[2] == curves[1])
return 1;
}
return 0;
}
int tls1_shared_curve(SSL *s, int nmatch)
{
const unsigned char *pref, *supp;
size_t num_pref, num_supp, i, j;
int k;
if (s->server == 0)
return -1;
if (nmatch == -2) {
if (tls1_suiteb(s)) {
unsigned long cid = s->s3->tmp.new_cipher->id;
if (cid == TLS1_CK_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256)
return NID_X9_62_prime256v1;
if (cid == TLS1_CK_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384)
return NID_secp384r1;
return NID_undef;
}
nmatch = 0;
}
if (!tls1_get_curvelist
(s, (s->options & SSL_OP_CIPHER_SERVER_PREFERENCE) != 0, &supp,
&num_supp))
return nmatch == -1 ? 0 : NID_undef;
if (!tls1_get_curvelist
(s, !(s->options & SSL_OP_CIPHER_SERVER_PREFERENCE), &pref,
&num_pref))
return nmatch == -1 ? 0 : NID_undef;
k = 0;
for (i = 0; i < num_pref; i++, pref += 2) {
const unsigned char *tsupp = supp;
for (j = 0; j < num_supp; j++, tsupp += 2) {
if (pref[0] == tsupp[0] && pref[1] == tsupp[1]) {
if (nmatch == k) {
int id = (pref[0] << 8) | pref[1];
return tls1_ec_curve_id2nid(id);
}
k++;
}
}
}
if (nmatch == -1)
return k;
return NID_undef;
}
int tls1_set_curves(unsigned char **pext, size_t *pextlen,
int *curves, size_t ncurves)
{
unsigned char *clist, *p;
size_t i;
unsigned long dup_list = 0;
# ifdef OPENSSL_NO_EC2M
EC_GROUP *curve;
# endif
clist = OPENSSL_malloc(ncurves * 2);
if (!clist)
return 0;
for (i = 0, p = clist; i < ncurves; i++) {
unsigned long idmask;
int id;
id = tls1_ec_nid2curve_id(curves[i]);
# ifdef OPENSSL_FIPS
if (FIPS_mode() && id > 25) {
OPENSSL_free(clist);
return 0;
}
# endif
# ifdef OPENSSL_NO_EC2M
curve = EC_GROUP_new_by_curve_name(curves[i]);
if (!curve || EC_METHOD_get_field_type(EC_GROUP_method_of(curve))
== NID_X9_62_characteristic_two_field) {
if (curve)
EC_GROUP_free(curve);
OPENSSL_free(clist);
return 0;
} else
EC_GROUP_free(curve);
# endif
idmask = 1L << id;
if (!id || (dup_list & idmask)) {
OPENSSL_free(clist);
return 0;
}
dup_list |= idmask;
s2n(id, p);
}
if (*pext)
OPENSSL_free(*pext);
*pext = clist;
*pextlen = ncurves * 2;
return 1;
}
static int nid_cb(const char *elem, int len, void *arg)
{
nid_cb_st *narg = arg;
size_t i;
int nid;
char etmp[20];
if (narg->nidcnt == MAX_CURVELIST)
return 0;
if (len > (int)(sizeof(etmp) - 1))
return 0;
memcpy(etmp, elem, len);
etmp[len] = 0;
nid = EC_curve_nist2nid(etmp);
if (nid == NID_undef)
nid = OBJ_sn2nid(etmp);
if (nid == NID_undef)
nid = OBJ_ln2nid(etmp);
if (nid == NID_undef)
return 0;
for (i = 0; i < narg->nidcnt; i++)
if (narg->nid_arr[i] == nid)
return 0;
narg->nid_arr[narg->nidcnt++] = nid;
return 1;
}
int tls1_set_curves_list(unsigned char **pext, size_t *pextlen,
const char *str)
{
nid_cb_st ncb;
ncb.nidcnt = 0;
if (!CONF_parse_list(str, ':', 1, nid_cb, &ncb))
return 0;
if (pext == NULL)
return 1;
return tls1_set_curves(pext, pextlen, ncb.nid_arr, ncb.nidcnt);
}
static int tls1_set_ec_id(unsigned char *curve_id, unsigned char *comp_id,
EC_KEY *ec)
{
int is_prime, id;
const EC_GROUP *grp;
const EC_METHOD *meth;
if (!ec)
return 0;
grp = EC_KEY_get0_group(ec);
if (!grp)
return 0;
meth = EC_GROUP_method_of(grp);
if (!meth)
return 0;
if (EC_METHOD_get_field_type(meth) == NID_X9_62_prime_field)
is_prime = 1;
else
is_prime = 0;
id = EC_GROUP_get_curve_name(grp);
id = tls1_ec_nid2curve_id(id);
if (id) {
curve_id[0] = 0;
curve_id[1] = (unsigned char)id;
} else {
curve_id[0] = 0xff;
if (is_prime)
curve_id[1] = 0x01;
else
curve_id[1] = 0x02;
}
if (comp_id) {
if (EC_KEY_get0_public_key(ec) == NULL)
return 0;
if (EC_KEY_get_conv_form(ec) == POINT_CONVERSION_COMPRESSED) {
if (is_prime)
*comp_id = TLSEXT_ECPOINTFORMAT_ansiX962_compressed_prime;
else
*comp_id = TLSEXT_ECPOINTFORMAT_ansiX962_compressed_char2;
} else
*comp_id = TLSEXT_ECPOINTFORMAT_uncompressed;
}
return 1;
}
static int tls1_check_ec_key(SSL *s,
unsigned char *curve_id, unsigned char *comp_id)
{
const unsigned char *pformats, *pcurves;
size_t num_formats, num_curves, i;
int j;
if (comp_id && s->session->tlsext_ecpointformatlist) {
pformats = s->session->tlsext_ecpointformatlist;
num_formats = s->session->tlsext_ecpointformatlist_length;
for (i = 0; i < num_formats; i++, pformats++) {
if (*comp_id == *pformats)
break;
}
if (i == num_formats)
return 0;
}
if (!curve_id)
return 1;
for (j = 0; j <= 1; j++) {
if (!tls1_get_curvelist(s, j, &pcurves, &num_curves))
return 0;
for (i = 0; i < num_curves; i++, pcurves += 2) {
if (pcurves[0] == curve_id[0] && pcurves[1] == curve_id[1])
break;
}
if (i == num_curves)
return 0;
if (!s->server)
return 1;
}
return 1;
}
static void tls1_get_formatlist(SSL *s, const unsigned char **pformats,
size_t *num_formats)
{
if (s->tlsext_ecpointformatlist) {
*pformats = s->tlsext_ecpointformatlist;
*num_formats = s->tlsext_ecpointformatlist_length;
} else {
*pformats = ecformats_default;
if (tls1_suiteb(s))
*num_formats = sizeof(ecformats_default) - 1;
else
*num_formats = sizeof(ecformats_default);
}
}
static int tls1_check_cert_param(SSL *s, X509 *x, int set_ee_md)
{
unsigned char comp_id, curve_id[2];
EVP_PKEY *pkey;
int rv;
pkey = X509_get_pubkey(x);
if (!pkey)
return 0;
if (pkey->type != EVP_PKEY_EC) {
EVP_PKEY_free(pkey);
return 1;
}
rv = tls1_set_ec_id(curve_id, &comp_id, pkey->pkey.ec);
EVP_PKEY_free(pkey);
if (!rv)
return 0;
rv = tls1_check_ec_key(s, s->server ? curve_id : NULL, &comp_id);
if (!rv)
return 0;
if (set_ee_md && tls1_suiteb(s)) {
int check_md;
size_t i;
CERT *c = s->cert;
if (curve_id[0])
return 0;
if (curve_id[1] == TLSEXT_curve_P_256)
check_md = NID_ecdsa_with_SHA256;
else if (curve_id[1] == TLSEXT_curve_P_384)
check_md = NID_ecdsa_with_SHA384;
else
return 0;
for (i = 0; i < c->shared_sigalgslen; i++)
if (check_md == c->shared_sigalgs[i].signandhash_nid)
break;
if (i == c->shared_sigalgslen)
return 0;
if (set_ee_md == 2) {
if (check_md == NID_ecdsa_with_SHA256)
c->pkeys[SSL_PKEY_ECC].digest = EVP_sha256();
else
c->pkeys[SSL_PKEY_ECC].digest = EVP_sha384();
}
}
return rv;
}
int tls1_check_ec_tmp_key(SSL *s, unsigned long cid)
{
unsigned char curve_id[2];
EC_KEY *ec = s->cert->ecdh_tmp;
# ifdef OPENSSL_SSL_DEBUG_BROKEN_PROTOCOL
if (s->cert->cert_flags & SSL_CERT_FLAG_BROKEN_PROTOCOL)
return 1;
# endif
if (tls1_suiteb(s)) {
if (cid == TLS1_CK_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256)
curve_id[1] = TLSEXT_curve_P_256;
else if (cid == TLS1_CK_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384)
curve_id[1] = TLSEXT_curve_P_384;
else
return 0;
curve_id[0] = 0;
if (!tls1_check_ec_key(s, curve_id, NULL))
return 0;
if (s->cert->ecdh_tmp_auto || s->cert->ecdh_tmp_cb)
return 1;
else {
unsigned char curve_tmp[2];
if (!ec)
return 0;
if (!tls1_set_ec_id(curve_tmp, NULL, ec))
return 0;
if (!curve_tmp[0] || curve_tmp[1] == curve_id[1])
return 1;
return 0;
}
}
if (s->cert->ecdh_tmp_auto) {
if (tls1_shared_curve(s, 0))
return 1;
else
return 0;
}
if (!ec) {
if (s->cert->ecdh_tmp_cb)
return 1;
else
return 0;
}
if (!tls1_set_ec_id(curve_id, NULL, ec))
return 0;
# if 0
return 1;
# else
return tls1_check_ec_key(s, curve_id, NULL);
# endif
}
static int tls1_check_cert_param(SSL *s, X509 *x, int set_ee_md)
{
return 1;
}
size_t tls12_get_psigalgs(SSL *s, const unsigned char **psigs)
{
# ifndef OPENSSL_NO_EC
switch (tls1_suiteb(s)) {
case SSL_CERT_FLAG_SUITEB_128_LOS:
*psigs = suiteb_sigalgs;
return sizeof(suiteb_sigalgs);
case SSL_CERT_FLAG_SUITEB_128_LOS_ONLY:
*psigs = suiteb_sigalgs;
return 2;
case SSL_CERT_FLAG_SUITEB_192_LOS:
*psigs = suiteb_sigalgs + 2;
return 2;
}
# endif
if (s->server && s->cert->client_sigalgs) {
*psigs = s->cert->client_sigalgs;
return s->cert->client_sigalgslen;
} else if (s->cert->conf_sigalgs) {
*psigs = s->cert->conf_sigalgs;
return s->cert->conf_sigalgslen;
} else {
*psigs = tls12_sigalgs;
return sizeof(tls12_sigalgs);
}
}
int tls12_check_peer_sigalg(const EVP_MD **pmd, SSL *s,
const unsigned char *sig, EVP_PKEY *pkey)
{
const unsigned char *sent_sigs;
size_t sent_sigslen, i;
int sigalg = tls12_get_sigid(pkey);
if (sigalg == -1)
return -1;
if (sigalg != (int)sig[1]) {
SSLerr(SSL_F_TLS12_CHECK_PEER_SIGALG, SSL_R_WRONG_SIGNATURE_TYPE);
return 0;
}
# ifndef OPENSSL_NO_EC
if (pkey->type == EVP_PKEY_EC) {
unsigned char curve_id[2], comp_id;
if (!tls1_set_ec_id(curve_id, &comp_id, pkey->pkey.ec))
return 0;
if (!s->server && !tls1_check_ec_key(s, curve_id, &comp_id)) {
SSLerr(SSL_F_TLS12_CHECK_PEER_SIGALG, SSL_R_WRONG_CURVE);
return 0;
}
if (tls1_suiteb(s)) {
if (curve_id[0])
return 0;
if (curve_id[1] == TLSEXT_curve_P_256) {
if (sig[0] != TLSEXT_hash_sha256) {
SSLerr(SSL_F_TLS12_CHECK_PEER_SIGALG,
SSL_R_ILLEGAL_SUITEB_DIGEST);
return 0;
}
} else if (curve_id[1] == TLSEXT_curve_P_384) {
if (sig[0] != TLSEXT_hash_sha384) {
SSLerr(SSL_F_TLS12_CHECK_PEER_SIGALG,
SSL_R_ILLEGAL_SUITEB_DIGEST);
return 0;
}
} else
return 0;
}
} else if (tls1_suiteb(s))
return 0;
# endif
sent_sigslen = tls12_get_psigalgs(s, &sent_sigs);
for (i = 0; i < sent_sigslen; i += 2, sent_sigs += 2) {
if (sig[0] == sent_sigs[0] && sig[1] == sent_sigs[1])
break;
}
if (i == sent_sigslen
&& (sig[0] != TLSEXT_hash_sha1
|| s->cert->cert_flags & SSL_CERT_FLAGS_CHECK_TLS_STRICT)) {
SSLerr(SSL_F_TLS12_CHECK_PEER_SIGALG, SSL_R_WRONG_SIGNATURE_TYPE);
return 0;
}
*pmd = tls12_get_hash(sig[0]);
if (*pmd == NULL) {
SSLerr(SSL_F_TLS12_CHECK_PEER_SIGALG, SSL_R_UNKNOWN_DIGEST);
return 0;
}
if (s->session && s->session->sess_cert)
s->session->sess_cert->peer_key->digest = *pmd;
return 1;
}
void ssl_set_client_disabled(SSL *s)
{
CERT *c = s->cert;
const unsigned char *sigalgs;
size_t i, sigalgslen;
int have_rsa = 0, have_dsa = 0, have_ecdsa = 0;
c->mask_a = 0;
c->mask_k = 0;
if (!SSL_CLIENT_USE_TLS1_2_CIPHERS(s))
c->mask_ssl = SSL_TLSV1_2;
else
c->mask_ssl = 0;
sigalgslen = tls12_get_psigalgs(s, &sigalgs);
for (i = 0; i < sigalgslen; i += 2, sigalgs += 2) {
switch (sigalgs[1]) {
# ifndef OPENSSL_NO_RSA
case TLSEXT_signature_rsa:
have_rsa = 1;
break;
# endif
# ifndef OPENSSL_NO_DSA
case TLSEXT_signature_dsa:
have_dsa = 1;
break;
# endif
# ifndef OPENSSL_NO_ECDSA
case TLSEXT_signature_ecdsa:
have_ecdsa = 1;
break;
# endif
}
}
if (!have_rsa) {
c->mask_a |= SSL_aRSA;
c->mask_k |= SSL_kDHr | SSL_kECDHr;
}
if (!have_dsa) {
c->mask_a |= SSL_aDSS;
c->mask_k |= SSL_kDHd;
}
if (!have_ecdsa) {
c->mask_a |= SSL_aECDSA;
c->mask_k |= SSL_kECDHe;
}
# ifndef OPENSSL_NO_KRB5
if (!kssl_tgt_is_available(s->kssl_ctx)) {
c->mask_a |= SSL_aKRB5;
c->mask_k |= SSL_kKRB5;
}
# endif
# ifndef OPENSSL_NO_PSK
if (!s->psk_client_callback) {
c->mask_a |= SSL_aPSK;
c->mask_k |= SSL_kPSK;
}
# endif
# ifndef OPENSSL_NO_SRP
if (!(s->srp_ctx.srp_Mask & SSL_kSRP)) {
c->mask_a |= SSL_aSRP;
c->mask_k |= SSL_kSRP;
}
# endif
c->valid = 1;
}
unsigned char *ssl_add_clienthello_tlsext(SSL *s, unsigned char *buf,
unsigned char *limit, int *al)
{
int extdatalen = 0;
unsigned char *orig = buf;
unsigned char *ret = buf;
# ifndef OPENSSL_NO_EC
int using_ecc = 0;
if (s->version >= TLS1_VERSION || SSL_IS_DTLS(s)) {
int i;
unsigned long alg_k, alg_a;
STACK_OF(SSL_CIPHER) *cipher_stack = SSL_get_ciphers(s);
for (i = 0; i < sk_SSL_CIPHER_num(cipher_stack); i++) {
SSL_CIPHER *c = sk_SSL_CIPHER_value(cipher_stack, i);
alg_k = c->algorithm_mkey;
alg_a = c->algorithm_auth;
if ((alg_k & (SSL_kEECDH | SSL_kECDHr | SSL_kECDHe)
|| (alg_a & SSL_aECDSA))) {
using_ecc = 1;
break;
}
}
}
# endif
if (s->client_version == SSL3_VERSION && !s->s3->send_connection_binding)
return orig;
ret += 2;
if (ret >= limit)
return NULL;
if (s->tlsext_hostname != NULL) {
unsigned long size_str;
long lenmax;
if ((lenmax = limit - ret - 9) < 0
|| (size_str =
strlen(s->tlsext_hostname)) > (unsigned long)lenmax)
return NULL;
s2n(TLSEXT_TYPE_server_name, ret);
s2n(size_str + 5, ret);
s2n(size_str + 3, ret);
*(ret++) = (unsigned char)TLSEXT_NAMETYPE_host_name;
s2n(size_str, ret);
memcpy(ret, s->tlsext_hostname, size_str);
ret += size_str;
}
if (s->renegotiate) {
int el;
if (!ssl_add_clienthello_renegotiate_ext(s, 0, &el, 0)) {
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
if ((limit - ret - 4 - el) < 0)
return NULL;
s2n(TLSEXT_TYPE_renegotiate, ret);
s2n(el, ret);
if (!ssl_add_clienthello_renegotiate_ext(s, ret, &el, el)) {
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
ret += el;
}
# ifndef OPENSSL_NO_SRP
if (s->srp_ctx.login != NULL) {
int login_len = strlen(s->srp_ctx.login);
if (login_len > 255 || login_len == 0) {
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
if ((limit - ret - 5 - login_len) < 0)
return NULL;
s2n(TLSEXT_TYPE_srp, ret);
s2n(login_len + 1, ret);
(*ret++) = (unsigned char)login_len;
memcpy(ret, s->srp_ctx.login, login_len);
ret += login_len;
}
# endif
# ifndef OPENSSL_NO_EC
if (using_ecc) {
long lenmax;
const unsigned char *pcurves, *pformats;
size_t num_curves, num_formats, curves_list_len;
tls1_get_formatlist(s, &pformats, &num_formats);
if ((lenmax = limit - ret - 5) < 0)
return NULL;
if (num_formats > (size_t)lenmax)
return NULL;
if (num_formats > 255) {
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
s2n(TLSEXT_TYPE_ec_point_formats, ret);
s2n(num_formats + 1, ret);
*(ret++) = (unsigned char)num_formats;
memcpy(ret, pformats, num_formats);
ret += num_formats;
pcurves = s->tlsext_ellipticcurvelist;
if (!tls1_get_curvelist(s, 0, &pcurves, &num_curves))
return NULL;
if ((lenmax = limit - ret - 6) < 0)
return NULL;
if (num_curves > (size_t)lenmax / 2)
return NULL;
if (num_curves > 65532 / 2) {
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
curves_list_len = 2 * num_curves;
s2n(TLSEXT_TYPE_elliptic_curves, ret);
s2n(curves_list_len + 2, ret);
s2n(curves_list_len, ret);
memcpy(ret, pcurves, curves_list_len);
ret += curves_list_len;
}
# endif
if (!(SSL_get_options(s) & SSL_OP_NO_TICKET)) {
int ticklen;
if (!s->new_session && s->session && s->session->tlsext_tick)
ticklen = s->session->tlsext_ticklen;
else if (s->session && s->tlsext_session_ticket &&
s->tlsext_session_ticket->data) {
ticklen = s->tlsext_session_ticket->length;
s->session->tlsext_tick = OPENSSL_malloc(ticklen);
if (!s->session->tlsext_tick)
return NULL;
memcpy(s->session->tlsext_tick,
s->tlsext_session_ticket->data, ticklen);
s->session->tlsext_ticklen = ticklen;
} else
ticklen = 0;
if (ticklen == 0 && s->tlsext_session_ticket &&
s->tlsext_session_ticket->data == NULL)
goto skip_ext;
if ((long)(limit - ret - 4 - ticklen) < 0)
return NULL;
s2n(TLSEXT_TYPE_session_ticket, ret);
s2n(ticklen, ret);
if (ticklen) {
memcpy(ret, s->session->tlsext_tick, ticklen);
ret += ticklen;
}
}
skip_ext:
if (SSL_USE_SIGALGS(s)) {
size_t salglen;
const unsigned char *salg;
salglen = tls12_get_psigalgs(s, &salg);
if ((size_t)(limit - ret) < salglen + 6)
return NULL;
s2n(TLSEXT_TYPE_signature_algorithms, ret);
s2n(salglen + 2, ret);
s2n(salglen, ret);
memcpy(ret, salg, salglen);
ret += salglen;
}
# ifdef TLSEXT_TYPE_opaque_prf_input
if (s->s3->client_opaque_prf_input != NULL) {
size_t col = s->s3->client_opaque_prf_input_len;
if ((long)(limit - ret - 6 - col < 0))
return NULL;
if (col > 0xFFFD)
return NULL;
s2n(TLSEXT_TYPE_opaque_prf_input, ret);
s2n(col + 2, ret);
s2n(col, ret);
memcpy(ret, s->s3->client_opaque_prf_input, col);
ret += col;
}
# endif
if (s->tlsext_status_type == TLSEXT_STATUSTYPE_ocsp) {
int i;
long extlen, idlen, itmp;
OCSP_RESPID *id;
idlen = 0;
for (i = 0; i < sk_OCSP_RESPID_num(s->tlsext_ocsp_ids); i++) {
id = sk_OCSP_RESPID_value(s->tlsext_ocsp_ids, i);
itmp = i2d_OCSP_RESPID(id, NULL);
if (itmp <= 0)
return NULL;
idlen += itmp + 2;
}
if (s->tlsext_ocsp_exts) {
extlen = i2d_X509_EXTENSIONS(s->tlsext_ocsp_exts, NULL);
if (extlen < 0)
return NULL;
} else
extlen = 0;
if ((long)(limit - ret - 7 - extlen - idlen) < 0)
return NULL;
s2n(TLSEXT_TYPE_status_request, ret);
if (extlen + idlen > 0xFFF0)
return NULL;
s2n(extlen + idlen + 5, ret);
*(ret++) = TLSEXT_STATUSTYPE_ocsp;
s2n(idlen, ret);
for (i = 0; i < sk_OCSP_RESPID_num(s->tlsext_ocsp_ids); i++) {
unsigned char *q = ret;
id = sk_OCSP_RESPID_value(s->tlsext_ocsp_ids, i);
ret += 2;
itmp = i2d_OCSP_RESPID(id, &ret);
s2n(itmp, q);
}
s2n(extlen, ret);
if (extlen > 0)
i2d_X509_EXTENSIONS(s->tlsext_ocsp_exts, &ret);
}
# ifndef OPENSSL_NO_HEARTBEATS
if ((limit - ret - 4 - 1) < 0)
return NULL;
s2n(TLSEXT_TYPE_heartbeat, ret);
s2n(1, ret);
if (s->tlsext_heartbeat & SSL_TLSEXT_HB_DONT_RECV_REQUESTS)
*(ret++) = SSL_TLSEXT_HB_DONT_SEND_REQUESTS;
else
*(ret++) = SSL_TLSEXT_HB_ENABLED;
# endif
# ifndef OPENSSL_NO_NEXTPROTONEG
if (s->ctx->next_proto_select_cb && !s->s3->tmp.finish_md_len) {
if (limit - ret - 4 < 0)
return NULL;
s2n(TLSEXT_TYPE_next_proto_neg, ret);
s2n(0, ret);
}
# endif
if (s->alpn_client_proto_list && !s->s3->tmp.finish_md_len) {
if ((size_t)(limit - ret) < 6 + s->alpn_client_proto_list_len)
return NULL;
s2n(TLSEXT_TYPE_application_layer_protocol_negotiation, ret);
s2n(2 + s->alpn_client_proto_list_len, ret);
s2n(s->alpn_client_proto_list_len, ret);
memcpy(ret, s->alpn_client_proto_list, s->alpn_client_proto_list_len);
ret += s->alpn_client_proto_list_len;
}
# ifndef OPENSSL_NO_SRTP
if (SSL_IS_DTLS(s) && SSL_get_srtp_profiles(s)) {
int el;
ssl_add_clienthello_use_srtp_ext(s, 0, &el, 0);
if ((limit - ret - 4 - el) < 0)
return NULL;
s2n(TLSEXT_TYPE_use_srtp, ret);
s2n(el, ret);
if (ssl_add_clienthello_use_srtp_ext(s, ret, &el, el)) {
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
ret += el;
}
# endif
custom_ext_init(&s->cert->cli_ext);
if (!custom_ext_add(s, 0, &ret, limit, al))
return NULL;
if (s->options & SSL_OP_TLSEXT_PADDING) {
int hlen = ret - (unsigned char *)s->init_buf->data;
if (s->state == SSL23_ST_CW_CLNT_HELLO_A)
hlen -= 5;
if (hlen > 0xff && hlen < 0x200) {
hlen = 0x200 - hlen;
if (hlen >= 4)
hlen -= 4;
else
hlen = 0;
s2n(TLSEXT_TYPE_padding, ret);
s2n(hlen, ret);
memset(ret, 0, hlen);
ret += hlen;
}
}
if ((extdatalen = ret - orig - 2) == 0)
return orig;
s2n(extdatalen, orig);
return ret;
}
unsigned char *ssl_add_serverhello_tlsext(SSL *s, unsigned char *buf,
unsigned char *limit, int *al)
{
int extdatalen = 0;
unsigned char *orig = buf;
unsigned char *ret = buf;
# ifndef OPENSSL_NO_NEXTPROTONEG
int next_proto_neg_seen;
# endif
# ifndef OPENSSL_NO_EC
unsigned long alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
unsigned long alg_a = s->s3->tmp.new_cipher->algorithm_auth;
int using_ecc = (alg_k & (SSL_kEECDH | SSL_kECDHr | SSL_kECDHe))
|| (alg_a & SSL_aECDSA);
using_ecc = using_ecc && (s->session->tlsext_ecpointformatlist != NULL);
# endif
if (s->version == SSL3_VERSION && !s->s3->send_connection_binding)
return orig;
ret += 2;
if (ret >= limit)
return NULL;
if (!s->hit && s->servername_done == 1
&& s->session->tlsext_hostname != NULL) {
if ((long)(limit - ret - 4) < 0)
return NULL;
s2n(TLSEXT_TYPE_server_name, ret);
s2n(0, ret);
}
if (s->s3->send_connection_binding) {
int el;
if (!ssl_add_serverhello_renegotiate_ext(s, 0, &el, 0)) {
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
if ((limit - ret - 4 - el) < 0)
return NULL;
s2n(TLSEXT_TYPE_renegotiate, ret);
s2n(el, ret);
if (!ssl_add_serverhello_renegotiate_ext(s, ret, &el, el)) {
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
ret += el;
}
# ifndef OPENSSL_NO_EC
if (using_ecc) {
const unsigned char *plist;
size_t plistlen;
long lenmax;
tls1_get_formatlist(s, &plist, &plistlen);
if ((lenmax = limit - ret - 5) < 0)
return NULL;
if (plistlen > (size_t)lenmax)
return NULL;
if (plistlen > 255) {
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
s2n(TLSEXT_TYPE_ec_point_formats, ret);
s2n(plistlen + 1, ret);
*(ret++) = (unsigned char)plistlen;
memcpy(ret, plist, plistlen);
ret += plistlen;
}
# endif
if (s->tlsext_ticket_expected && !(SSL_get_options(s) & SSL_OP_NO_TICKET)) {
if ((long)(limit - ret - 4) < 0)
return NULL;
s2n(TLSEXT_TYPE_session_ticket, ret);
s2n(0, ret);
}
if (s->tlsext_status_expected) {
if ((long)(limit - ret - 4) < 0)
return NULL;
s2n(TLSEXT_TYPE_status_request, ret);
s2n(0, ret);
}
# ifdef TLSEXT_TYPE_opaque_prf_input
if (s->s3->server_opaque_prf_input != NULL) {
size_t sol = s->s3->server_opaque_prf_input_len;
if ((long)(limit - ret - 6 - sol) < 0)
return NULL;
if (sol > 0xFFFD)
return NULL;
s2n(TLSEXT_TYPE_opaque_prf_input, ret);
s2n(sol + 2, ret);
s2n(sol, ret);
memcpy(ret, s->s3->server_opaque_prf_input, sol);
ret += sol;
}
# endif
# ifndef OPENSSL_NO_SRTP
if (SSL_IS_DTLS(s) && s->srtp_profile) {
int el;
ssl_add_serverhello_use_srtp_ext(s, 0, &el, 0);
if ((limit - ret - 4 - el) < 0)
return NULL;
s2n(TLSEXT_TYPE_use_srtp, ret);
s2n(el, ret);
if (ssl_add_serverhello_use_srtp_ext(s, ret, &el, el)) {
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
ret += el;
}
# endif
if (((s->s3->tmp.new_cipher->id & 0xFFFF) == 0x80
|| (s->s3->tmp.new_cipher->id & 0xFFFF) == 0x81)
&& (SSL_get_options(s) & SSL_OP_CRYPTOPRO_TLSEXT_BUG)) {
const unsigned char cryptopro_ext[36] = {
0xfd, 0xe8,
0x00, 0x20,
0x30, 0x1e, 0x30, 0x08, 0x06, 0x06, 0x2a, 0x85,
0x03, 0x02, 0x02, 0x09, 0x30, 0x08, 0x06, 0x06,
0x2a, 0x85, 0x03, 0x02, 0x02, 0x16, 0x30, 0x08,
0x06, 0x06, 0x2a, 0x85, 0x03, 0x02, 0x02, 0x17
};
if (limit - ret < 36)
return NULL;
memcpy(ret, cryptopro_ext, 36);
ret += 36;
}
# ifndef OPENSSL_NO_HEARTBEATS
if (s->tlsext_heartbeat & SSL_TLSEXT_HB_ENABLED) {
if ((limit - ret - 4 - 1) < 0)
return NULL;
s2n(TLSEXT_TYPE_heartbeat, ret);
s2n(1, ret);
if (s->tlsext_heartbeat & SSL_TLSEXT_HB_DONT_RECV_REQUESTS)
*(ret++) = SSL_TLSEXT_HB_DONT_SEND_REQUESTS;
else
*(ret++) = SSL_TLSEXT_HB_ENABLED;
}
# endif
# ifndef OPENSSL_NO_NEXTPROTONEG
next_proto_neg_seen = s->s3->next_proto_neg_seen;
s->s3->next_proto_neg_seen = 0;
if (next_proto_neg_seen && s->ctx->next_protos_advertised_cb) {
const unsigned char *npa;
unsigned int npalen;
int r;
r = s->ctx->next_protos_advertised_cb(s, &npa, &npalen,
s->
ctx->next_protos_advertised_cb_arg);
if (r == SSL_TLSEXT_ERR_OK) {
if ((long)(limit - ret - 4 - npalen) < 0)
return NULL;
s2n(TLSEXT_TYPE_next_proto_neg, ret);
s2n(npalen, ret);
memcpy(ret, npa, npalen);
ret += npalen;
s->s3->next_proto_neg_seen = 1;
}
}
# endif
if (!custom_ext_add(s, 1, &ret, limit, al))
return NULL;
if (s->s3->alpn_selected) {
const unsigned char *selected = s->s3->alpn_selected;
unsigned len = s->s3->alpn_selected_len;
if ((long)(limit - ret - 4 - 2 - 1 - len) < 0)
return NULL;
s2n(TLSEXT_TYPE_application_layer_protocol_negotiation, ret);
s2n(3 + len, ret);
s2n(1 + len, ret);
*ret++ = len;
memcpy(ret, selected, len);
ret += len;
}
if ((extdatalen = ret - orig - 2) == 0)
return orig;
s2n(extdatalen, orig);
return ret;
}
static void ssl_check_for_safari(SSL *s, const unsigned char *data,
const unsigned char *d, int n)
{
unsigned short type, size;
static const unsigned char kSafariExtensionsBlock[] = {
0x00, 0x0a,
0x00, 0x08,
0x00, 0x06,
0x00, 0x17,
0x00, 0x18,
0x00, 0x19,
0x00, 0x0b,
0x00, 0x02,
0x01,
0x00,
};
static const unsigned char kSafariTLS12ExtensionsBlock[] = {
0x00, 0x0d,
0x00, 0x0c,
0x00, 0x0a,
0x05, 0x01,
0x04, 0x01,
0x02, 0x01,
0x04, 0x03,
0x02, 0x03,
};
if (data >= (d + n - 2))
return;
data += 2;
if (data > (d + n - 4))
return;
n2s(data, type);
n2s(data, size);
if (type != TLSEXT_TYPE_server_name)
return;
if (data + size > d + n)
return;
data += size;
if (TLS1_get_client_version(s) >= TLS1_2_VERSION) {
const size_t len1 = sizeof(kSafariExtensionsBlock);
const size_t len2 = sizeof(kSafariTLS12ExtensionsBlock);
if (data + len1 + len2 != d + n)
return;
if (memcmp(data, kSafariExtensionsBlock, len1) != 0)
return;
if (memcmp(data + len1, kSafariTLS12ExtensionsBlock, len2) != 0)
return;
} else {
const size_t len = sizeof(kSafariExtensionsBlock);
if (data + len != d + n)
return;
if (memcmp(data, kSafariExtensionsBlock, len) != 0)
return;
}
s->s3->is_probably_safari = 1;
}
static int tls1_alpn_handle_client_hello(SSL *s, const unsigned char *data,
unsigned data_len, int *al)
{
unsigned i;
unsigned proto_len;
const unsigned char *selected;
unsigned char selected_len;
int r;
if (s->ctx->alpn_select_cb == NULL)
return 0;
if (data_len < 2)
goto parse_error;
i = ((unsigned)data[0]) << 8 | ((unsigned)data[1]);
data_len -= 2;
data += 2;
if (data_len != i)
goto parse_error;
if (data_len < 2)
goto parse_error;
for (i = 0; i < data_len;) {
proto_len = data[i];
i++;
if (proto_len == 0)
goto parse_error;
if (i + proto_len < i || i + proto_len > data_len)
goto parse_error;
i += proto_len;
}
r = s->ctx->alpn_select_cb(s, &selected, &selected_len, data, data_len,
s->ctx->alpn_select_cb_arg);
if (r == SSL_TLSEXT_ERR_OK) {
if (s->s3->alpn_selected)
OPENSSL_free(s->s3->alpn_selected);
s->s3->alpn_selected = OPENSSL_malloc(selected_len);
if (!s->s3->alpn_selected) {
*al = SSL_AD_INTERNAL_ERROR;
return -1;
}
memcpy(s->s3->alpn_selected, selected, selected_len);
s->s3->alpn_selected_len = selected_len;
}
return 0;
parse_error:
*al = SSL_AD_DECODE_ERROR;
return -1;
}
static int ssl_scan_clienthello_tlsext(SSL *s, unsigned char **p,
unsigned char *d, int n, int *al)
{
unsigned short type;
unsigned short size;
unsigned short len;
unsigned char *data = *p;
int renegotiate_seen = 0;
s->servername_done = 0;
s->tlsext_status_type = -1;
# ifndef OPENSSL_NO_NEXTPROTONEG
s->s3->next_proto_neg_seen = 0;
# endif
if (s->s3->alpn_selected) {
OPENSSL_free(s->s3->alpn_selected);
s->s3->alpn_selected = NULL;
}
# ifndef OPENSSL_NO_HEARTBEATS
s->tlsext_heartbeat &= ~(SSL_TLSEXT_HB_ENABLED |
SSL_TLSEXT_HB_DONT_SEND_REQUESTS);
# endif
# ifndef OPENSSL_NO_EC
if (s->options & SSL_OP_SAFARI_ECDHE_ECDSA_BUG)
ssl_check_for_safari(s, data, d, n);
# endif
if (s->cert->peer_sigalgs) {
OPENSSL_free(s->cert->peer_sigalgs);
s->cert->peer_sigalgs = NULL;
}
# ifndef OPENSSL_NO_SRP
if (s->srp_ctx.login != NULL) {
OPENSSL_free(s->srp_ctx.login);
s->srp_ctx.login = NULL;
}
# endif
s->srtp_profile = NULL;
if (data >= (d + n - 2))
goto ri_check;
n2s(data, len);
if (data > (d + n - len))
goto ri_check;
while (data <= (d + n - 4)) {
n2s(data, type);
n2s(data, size);
if (data + size > (d + n))
goto ri_check;
# if 0
fprintf(stderr, "Received extension type %d size %d\n", type, size);
# endif
if (s->tlsext_debug_cb)
s->tlsext_debug_cb(s, 0, type, data, size, s->tlsext_debug_arg);
if (type == TLSEXT_TYPE_server_name) {
unsigned char *sdata;
int servname_type;
int dsize;
if (size < 2) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
n2s(data, dsize);
size -= 2;
if (dsize > size) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
sdata = data;
while (dsize > 3) {
servname_type = *(sdata++);
n2s(sdata, len);
dsize -= 3;
if (len > dsize) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (s->servername_done == 0)
switch (servname_type) {
case TLSEXT_NAMETYPE_host_name:
if (!s->hit) {
if (s->session->tlsext_hostname) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (len > TLSEXT_MAXLEN_host_name) {
*al = TLS1_AD_UNRECOGNIZED_NAME;
return 0;
}
if ((s->session->tlsext_hostname =
OPENSSL_malloc(len + 1)) == NULL) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
memcpy(s->session->tlsext_hostname, sdata, len);
s->session->tlsext_hostname[len] = '\0';
if (strlen(s->session->tlsext_hostname) != len) {
OPENSSL_free(s->session->tlsext_hostname);
s->session->tlsext_hostname = NULL;
*al = TLS1_AD_UNRECOGNIZED_NAME;
return 0;
}
s->servername_done = 1;
} else
s->servername_done = s->session->tlsext_hostname
&& strlen(s->session->tlsext_hostname) == len
&& strncmp(s->session->tlsext_hostname,
(char *)sdata, len) == 0;
break;
default:
break;
}
dsize -= len;
}
if (dsize != 0) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
}
# ifndef OPENSSL_NO_SRP
else if (type == TLSEXT_TYPE_srp) {
if (size <= 0 || ((len = data[0])) != (size - 1)) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (s->srp_ctx.login != NULL) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if ((s->srp_ctx.login = OPENSSL_malloc(len + 1)) == NULL)
return -1;
memcpy(s->srp_ctx.login, &data[1], len);
s->srp_ctx.login[len] = '\0';
if (strlen(s->srp_ctx.login) != len) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
}
# endif
# ifndef OPENSSL_NO_EC
else if (type == TLSEXT_TYPE_ec_point_formats) {
unsigned char *sdata = data;
int ecpointformatlist_length = *(sdata++);
if (ecpointformatlist_length != size - 1 ||
ecpointformatlist_length < 1) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
if (!s->hit) {
if (s->session->tlsext_ecpointformatlist) {
OPENSSL_free(s->session->tlsext_ecpointformatlist);
s->session->tlsext_ecpointformatlist = NULL;
}
s->session->tlsext_ecpointformatlist_length = 0;
if ((s->session->tlsext_ecpointformatlist =
OPENSSL_malloc(ecpointformatlist_length)) == NULL) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
s->session->tlsext_ecpointformatlist_length =
ecpointformatlist_length;
memcpy(s->session->tlsext_ecpointformatlist, sdata,
ecpointformatlist_length);
}
# if 0
fprintf(stderr,
"ssl_parse_clienthello_tlsext s->session->tlsext_ecpointformatlist (length=%i) ",
s->session->tlsext_ecpointformatlist_length);
sdata = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
fprintf(stderr, "%i ", *(sdata++));
fprintf(stderr, "\n");
# endif
} else if (type == TLSEXT_TYPE_elliptic_curves) {
unsigned char *sdata = data;
int ellipticcurvelist_length = (*(sdata++) << 8);
ellipticcurvelist_length += (*(sdata++));
if (ellipticcurvelist_length != size - 2 ||
ellipticcurvelist_length < 1 ||
ellipticcurvelist_length & 1) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
if (!s->hit) {
if (s->session->tlsext_ellipticcurvelist) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
s->session->tlsext_ellipticcurvelist_length = 0;
if ((s->session->tlsext_ellipticcurvelist =
OPENSSL_malloc(ellipticcurvelist_length)) == NULL) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
s->session->tlsext_ellipticcurvelist_length =
ellipticcurvelist_length;
memcpy(s->session->tlsext_ellipticcurvelist, sdata,
ellipticcurvelist_length);
}
# if 0
fprintf(stderr,
"ssl_parse_clienthello_tlsext s->session->tlsext_ellipticcurvelist (length=%i) ",
s->session->tlsext_ellipticcurvelist_length);
sdata = s->session->tlsext_ellipticcurvelist;
for (i = 0; i < s->session->tlsext_ellipticcurvelist_length; i++)
fprintf(stderr, "%i ", *(sdata++));
fprintf(stderr, "\n");
# endif
}
# endif
# ifdef TLSEXT_TYPE_opaque_prf_input
else if (type == TLSEXT_TYPE_opaque_prf_input) {
unsigned char *sdata = data;
if (size < 2) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
n2s(sdata, s->s3->client_opaque_prf_input_len);
if (s->s3->client_opaque_prf_input_len != size - 2) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (s->s3->client_opaque_prf_input != NULL) {
OPENSSL_free(s->s3->client_opaque_prf_input);
}
if (s->s3->client_opaque_prf_input_len == 0)
s->s3->client_opaque_prf_input = OPENSSL_malloc(1);
else
s->s3->client_opaque_prf_input =
BUF_memdup(sdata, s->s3->client_opaque_prf_input_len);
if (s->s3->client_opaque_prf_input == NULL) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
}
# endif
else if (type == TLSEXT_TYPE_session_ticket) {
if (s->tls_session_ticket_ext_cb &&
!s->tls_session_ticket_ext_cb(s, data, size,
s->tls_session_ticket_ext_cb_arg))
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
} else if (type == TLSEXT_TYPE_renegotiate) {
if (!ssl_parse_clienthello_renegotiate_ext(s, data, size, al))
return 0;
renegotiate_seen = 1;
} else if (type == TLSEXT_TYPE_signature_algorithms) {
int dsize;
if (s->cert->peer_sigalgs || size < 2) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
n2s(data, dsize);
size -= 2;
if (dsize != size || dsize & 1 || !dsize) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (!tls1_save_sigalgs(s, data, dsize)) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
} else if (type == TLSEXT_TYPE_status_request) {
if (size < 5) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
s->tlsext_status_type = *data++;
size--;
if (s->tlsext_status_type == TLSEXT_STATUSTYPE_ocsp) {
const unsigned char *sdata;
int dsize;
n2s(data, dsize);
size -= 2;
if (dsize > size) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
while (dsize > 0) {
OCSP_RESPID *id;
int idsize;
if (dsize < 4) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
n2s(data, idsize);
dsize -= 2 + idsize;
size -= 2 + idsize;
if (dsize < 0) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
sdata = data;
data += idsize;
id = d2i_OCSP_RESPID(NULL, &sdata, idsize);
if (!id) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (data != sdata) {
OCSP_RESPID_free(id);
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (!s->tlsext_ocsp_ids
&& !(s->tlsext_ocsp_ids =
sk_OCSP_RESPID_new_null())) {
OCSP_RESPID_free(id);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
if (!sk_OCSP_RESPID_push(s->tlsext_ocsp_ids, id)) {
OCSP_RESPID_free(id);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
}
if (size < 2) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
n2s(data, dsize);
size -= 2;
if (dsize != size) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
sdata = data;
if (dsize > 0) {
if (s->tlsext_ocsp_exts) {
sk_X509_EXTENSION_pop_free(s->tlsext_ocsp_exts,
X509_EXTENSION_free);
}
s->tlsext_ocsp_exts =
d2i_X509_EXTENSIONS(NULL, &sdata, dsize);
if (!s->tlsext_ocsp_exts || (data + dsize != sdata)) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
}
}
else
s->tlsext_status_type = -1;
}
# ifndef OPENSSL_NO_HEARTBEATS
else if (type == TLSEXT_TYPE_heartbeat) {
switch (data[0]) {
case 0x01:
s->tlsext_heartbeat |= SSL_TLSEXT_HB_ENABLED;
break;
case 0x02:
s->tlsext_heartbeat |= SSL_TLSEXT_HB_ENABLED;
s->tlsext_heartbeat |= SSL_TLSEXT_HB_DONT_SEND_REQUESTS;
break;
default:
*al = SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
}
# endif
# ifndef OPENSSL_NO_NEXTPROTONEG
else if (type == TLSEXT_TYPE_next_proto_neg &&
s->s3->tmp.finish_md_len == 0 &&
s->s3->alpn_selected == NULL) {
s->s3->next_proto_neg_seen = 1;
}
# endif
else if (type == TLSEXT_TYPE_application_layer_protocol_negotiation &&
s->ctx->alpn_select_cb && s->s3->tmp.finish_md_len == 0) {
if (tls1_alpn_handle_client_hello(s, data, size, al) != 0)
return 0;
# ifndef OPENSSL_NO_NEXTPROTONEG
s->s3->next_proto_neg_seen = 0;
# endif
}
# ifndef OPENSSL_NO_SRTP
else if (SSL_IS_DTLS(s) && SSL_get_srtp_profiles(s)
&& type == TLSEXT_TYPE_use_srtp) {
if (ssl_parse_clienthello_use_srtp_ext(s, data, size, al))
return 0;
}
# endif
data += size;
}
*p = data;
ri_check:
if (!renegotiate_seen && s->renegotiate &&
!(s->options & SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION)) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_SSL_SCAN_CLIENTHELLO_TLSEXT,
SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED);
return 0;
}
return 1;
}
static int ssl_scan_clienthello_custom_tlsext(SSL *s,
const unsigned char *data,
const unsigned char *limit,
int *al)
{
unsigned short type, size, len;
if (s->hit || s->cert->srv_ext.meths_count == 0)
return 1;
if (data >= limit - 2)
return 1;
n2s(data, len);
if (data > limit - len)
return 1;
while (data <= limit - 4) {
n2s(data, type);
n2s(data, size);
if (data + size > limit)
return 1;
if (custom_ext_parse(s, 1 , type, data, size, al) <= 0)
return 0;
data += size;
}
return 1;
}
int ssl_parse_clienthello_tlsext(SSL *s, unsigned char **p, unsigned char *d,
int n)
{
int al = -1;
unsigned char *ptmp = *p;
if (ssl_scan_clienthello_tlsext(s, p, d, n, &al) <= 0) {
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return 0;
}
if (ssl_check_clienthello_tlsext_early(s) <= 0) {
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_TLSEXT, SSL_R_CLIENTHELLO_TLSEXT);
return 0;
}
custom_ext_init(&s->cert->srv_ext);
if (ssl_scan_clienthello_custom_tlsext(s, ptmp, d + n, &al) <= 0) {
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return 0;
}
return 1;
}
static char ssl_next_proto_validate(unsigned char *d, unsigned len)
{
unsigned int off = 0;
while (off < len) {
if (d[off] == 0)
return 0;
off += d[off];
off++;
}
return off == len;
}
static int ssl_scan_serverhello_tlsext(SSL *s, unsigned char **p,
unsigned char *d, int n, int *al)
{
unsigned short length;
unsigned short type;
unsigned short size;
unsigned char *data = *p;
int tlsext_servername = 0;
int renegotiate_seen = 0;
# ifndef OPENSSL_NO_NEXTPROTONEG
s->s3->next_proto_neg_seen = 0;
# endif
s->tlsext_ticket_expected = 0;
if (s->s3->alpn_selected) {
OPENSSL_free(s->s3->alpn_selected);
s->s3->alpn_selected = NULL;
}
# ifndef OPENSSL_NO_HEARTBEATS
s->tlsext_heartbeat &= ~(SSL_TLSEXT_HB_ENABLED |
SSL_TLSEXT_HB_DONT_SEND_REQUESTS);
# endif
if (data >= (d + n - 2))
goto ri_check;
n2s(data, length);
if (data + length != d + n) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
while (data <= (d + n - 4)) {
n2s(data, type);
n2s(data, size);
if (data + size > (d + n))
goto ri_check;
if (s->tlsext_debug_cb)
s->tlsext_debug_cb(s, 1, type, data, size, s->tlsext_debug_arg);
if (type == TLSEXT_TYPE_server_name) {
if (s->tlsext_hostname == NULL || size > 0) {
*al = TLS1_AD_UNRECOGNIZED_NAME;
return 0;
}
tlsext_servername = 1;
}
# ifndef OPENSSL_NO_EC
else if (type == TLSEXT_TYPE_ec_point_formats) {
unsigned char *sdata = data;
int ecpointformatlist_length = *(sdata++);
if (ecpointformatlist_length != size - 1) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
if (!s->hit) {
s->session->tlsext_ecpointformatlist_length = 0;
if (s->session->tlsext_ecpointformatlist != NULL)
OPENSSL_free(s->session->tlsext_ecpointformatlist);
if ((s->session->tlsext_ecpointformatlist =
OPENSSL_malloc(ecpointformatlist_length)) == NULL) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
s->session->tlsext_ecpointformatlist_length =
ecpointformatlist_length;
memcpy(s->session->tlsext_ecpointformatlist, sdata,
ecpointformatlist_length);
}
# if 0
fprintf(stderr,
"ssl_parse_serverhello_tlsext s->session->tlsext_ecpointformatlist ");
sdata = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
fprintf(stderr, "%i ", *(sdata++));
fprintf(stderr, "\n");
# endif
}
# endif
else if (type == TLSEXT_TYPE_session_ticket) {
if (s->tls_session_ticket_ext_cb &&
!s->tls_session_ticket_ext_cb(s, data, size,
s->tls_session_ticket_ext_cb_arg))
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
if ((SSL_get_options(s) & SSL_OP_NO_TICKET)
|| (size > 0)) {
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
s->tlsext_ticket_expected = 1;
}
# ifdef TLSEXT_TYPE_opaque_prf_input
else if (type == TLSEXT_TYPE_opaque_prf_input) {
unsigned char *sdata = data;
if (size < 2) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
n2s(sdata, s->s3->server_opaque_prf_input_len);
if (s->s3->server_opaque_prf_input_len != size - 2) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (s->s3->server_opaque_prf_input != NULL) {
OPENSSL_free(s->s3->server_opaque_prf_input);
}
if (s->s3->server_opaque_prf_input_len == 0) {
s->s3->server_opaque_prf_input = OPENSSL_malloc(1);
} else {
s->s3->server_opaque_prf_input =
BUF_memdup(sdata, s->s3->server_opaque_prf_input_len);
}
if (s->s3->server_opaque_prf_input == NULL) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
}
# endif
else if (type == TLSEXT_TYPE_status_request) {
if ((s->tlsext_status_type == -1) || (size > 0)) {
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
s->tlsext_status_expected = 1;
}
# ifndef OPENSSL_NO_NEXTPROTONEG
else if (type == TLSEXT_TYPE_next_proto_neg &&
s->s3->tmp.finish_md_len == 0) {
unsigned char *selected;
unsigned char selected_len;
if (s->ctx->next_proto_select_cb == NULL) {
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
if (!ssl_next_proto_validate(data, size)) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
if (s->
ctx->next_proto_select_cb(s, &selected, &selected_len, data,
size,
s->ctx->next_proto_select_cb_arg) !=
SSL_TLSEXT_ERR_OK) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
s->next_proto_negotiated = OPENSSL_malloc(selected_len);
if (!s->next_proto_negotiated) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
memcpy(s->next_proto_negotiated, selected, selected_len);
s->next_proto_negotiated_len = selected_len;
s->s3->next_proto_neg_seen = 1;
}
# endif
else if (type == TLSEXT_TYPE_application_layer_protocol_negotiation) {
unsigned len;
if (s->alpn_client_proto_list == NULL) {
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
if (size < 4) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
len = data[0];
len <<= 8;
len |= data[1];
if (len != (unsigned)size - 2) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
len = data[2];
if (len != (unsigned)size - 3) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
if (s->s3->alpn_selected)
OPENSSL_free(s->s3->alpn_selected);
s->s3->alpn_selected = OPENSSL_malloc(len);
if (!s->s3->alpn_selected) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
memcpy(s->s3->alpn_selected, data + 3, len);
s->s3->alpn_selected_len = len;
}
else if (type == TLSEXT_TYPE_renegotiate) {
if (!ssl_parse_serverhello_renegotiate_ext(s, data, size, al))
return 0;
renegotiate_seen = 1;
}
# ifndef OPENSSL_NO_HEARTBEATS
else if (type == TLSEXT_TYPE_heartbeat) {
switch (data[0]) {
case 0x01:
s->tlsext_heartbeat |= SSL_TLSEXT_HB_ENABLED;
break;
case 0x02:
s->tlsext_heartbeat |= SSL_TLSEXT_HB_ENABLED;
s->tlsext_heartbeat |= SSL_TLSEXT_HB_DONT_SEND_REQUESTS;
break;
default:
*al = SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
}
# endif
# ifndef OPENSSL_NO_SRTP
else if (SSL_IS_DTLS(s) && type == TLSEXT_TYPE_use_srtp) {
if (ssl_parse_serverhello_use_srtp_ext(s, data, size, al))
return 0;
}
# endif
else if (custom_ext_parse(s, 0, type, data, size, al) <= 0)
return 0;
data += size;
}
if (data != d + n) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (!s->hit && tlsext_servername == 1) {
if (s->tlsext_hostname) {
if (s->session->tlsext_hostname == NULL) {
s->session->tlsext_hostname = BUF_strdup(s->tlsext_hostname);
if (!s->session->tlsext_hostname) {
*al = SSL_AD_UNRECOGNIZED_NAME;
return 0;
}
} else {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
}
}
*p = data;
ri_check:
if (!renegotiate_seen && !(s->options & SSL_OP_LEGACY_SERVER_CONNECT)
&& !(s->options & SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION)) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_SSL_SCAN_SERVERHELLO_TLSEXT,
SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED);
return 0;
}
return 1;
}
int ssl_prepare_clienthello_tlsext(SSL *s)
{
# ifdef TLSEXT_TYPE_opaque_prf_input
{
int r = 1;
if (s->ctx->tlsext_opaque_prf_input_callback != 0) {
r = s->ctx->tlsext_opaque_prf_input_callback(s, NULL, 0,
s->
ctx->tlsext_opaque_prf_input_callback_arg);
if (!r)
return -1;
}
if (s->tlsext_opaque_prf_input != NULL) {
if (s->s3->client_opaque_prf_input != NULL) {
OPENSSL_free(s->s3->client_opaque_prf_input);
}
if (s->tlsext_opaque_prf_input_len == 0) {
s->s3->client_opaque_prf_input = OPENSSL_malloc(1);
} else {
s->s3->client_opaque_prf_input =
BUF_memdup(s->tlsext_opaque_prf_input,
s->tlsext_opaque_prf_input_len);
}
if (s->s3->client_opaque_prf_input == NULL) {
SSLerr(SSL_F_SSL_PREPARE_CLIENTHELLO_TLSEXT,
ERR_R_MALLOC_FAILURE);
return -1;
}
s->s3->client_opaque_prf_input_len =
s->tlsext_opaque_prf_input_len;
}
if (r == 2)
s->s3->server_opaque_prf_input_len =
s->tlsext_opaque_prf_input_len;
}
# endif
return 1;
}
int ssl_prepare_serverhello_tlsext(SSL *s)
{
return 1;
}
static int ssl_check_clienthello_tlsext_early(SSL *s)
{
int ret = SSL_TLSEXT_ERR_NOACK;
int al = SSL_AD_UNRECOGNIZED_NAME;
# ifndef OPENSSL_NO_EC
# endif
if (s->ctx != NULL && s->ctx->tlsext_servername_callback != 0)
ret =
s->ctx->tlsext_servername_callback(s, &al,
s->ctx->tlsext_servername_arg);
else if (s->initial_ctx != NULL
&& s->initial_ctx->tlsext_servername_callback != 0)
ret =
s->initial_ctx->tlsext_servername_callback(s, &al,
s->
initial_ctx->tlsext_servername_arg);
# ifdef TLSEXT_TYPE_opaque_prf_input
{
int r = 1;
if (s->ctx->tlsext_opaque_prf_input_callback != 0) {
r = s->ctx->tlsext_opaque_prf_input_callback(s, NULL, 0,
s->
ctx->tlsext_opaque_prf_input_callback_arg);
if (!r) {
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_INTERNAL_ERROR;
goto err;
}
}
if (s->s3->server_opaque_prf_input != NULL) {
OPENSSL_free(s->s3->server_opaque_prf_input);
}
s->s3->server_opaque_prf_input = NULL;
if (s->tlsext_opaque_prf_input != NULL) {
if (s->s3->client_opaque_prf_input != NULL &&
s->s3->client_opaque_prf_input_len ==
s->tlsext_opaque_prf_input_len) {
if (s->tlsext_opaque_prf_input_len == 0) {
s->s3->server_opaque_prf_input = OPENSSL_malloc(1);
} else {
s->s3->server_opaque_prf_input =
BUF_memdup(s->tlsext_opaque_prf_input,
s->tlsext_opaque_prf_input_len);
}
if (s->s3->server_opaque_prf_input == NULL) {
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_INTERNAL_ERROR;
goto err;
}
s->s3->server_opaque_prf_input_len =
s->tlsext_opaque_prf_input_len;
}
}
if (r == 2 && s->s3->server_opaque_prf_input == NULL) {
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_HANDSHAKE_FAILURE;
}
}
err:
# endif
switch (ret) {
case SSL_TLSEXT_ERR_ALERT_FATAL:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return -1;
case SSL_TLSEXT_ERR_ALERT_WARNING:
ssl3_send_alert(s, SSL3_AL_WARNING, al);
return 1;
case SSL_TLSEXT_ERR_NOACK:
s->servername_done = 0;
default:
return 1;
}
}
int tls1_set_server_sigalgs(SSL *s)
{
int al;
size_t i;
if (s->cert->shared_sigalgs) {
OPENSSL_free(s->cert->shared_sigalgs);
s->cert->shared_sigalgs = NULL;
}
for (i = 0; i < SSL_PKEY_NUM; i++) {
s->cert->pkeys[i].digest = NULL;
s->cert->pkeys[i].valid_flags = 0;
}
if (s->cert->peer_sigalgs) {
if (!tls1_process_sigalgs(s)) {
SSLerr(SSL_F_TLS1_SET_SERVER_SIGALGS, ERR_R_MALLOC_FAILURE);
al = SSL_AD_INTERNAL_ERROR;
goto err;
}
if (!s->cert->shared_sigalgs) {
SSLerr(SSL_F_TLS1_SET_SERVER_SIGALGS,
SSL_R_NO_SHARED_SIGATURE_ALGORITHMS);
al = SSL_AD_ILLEGAL_PARAMETER;
goto err;
}
} else
ssl_cert_set_default_md(s->cert);
return 1;
err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return 0;
}
int ssl_check_clienthello_tlsext_late(SSL *s)
{
int ret = SSL_TLSEXT_ERR_OK;
int al;
if ((s->tlsext_status_type != -1) && s->ctx && s->ctx->tlsext_status_cb) {
int r;
CERT_PKEY *certpkey;
certpkey = ssl_get_server_send_pkey(s);
if (certpkey == NULL) {
s->tlsext_status_expected = 0;
return 1;
}
s->cert->key = certpkey;
r = s->ctx->tlsext_status_cb(s, s->ctx->tlsext_status_arg);
switch (r) {
case SSL_TLSEXT_ERR_NOACK:
s->tlsext_status_expected = 0;
break;
case SSL_TLSEXT_ERR_OK:
if (s->tlsext_ocsp_resp)
s->tlsext_status_expected = 1;
else
s->tlsext_status_expected = 0;
break;
case SSL_TLSEXT_ERR_ALERT_FATAL:
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_INTERNAL_ERROR;
goto err;
}
} else
s->tlsext_status_expected = 0;
err:
switch (ret) {
case SSL_TLSEXT_ERR_ALERT_FATAL:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return -1;
case SSL_TLSEXT_ERR_ALERT_WARNING:
ssl3_send_alert(s, SSL3_AL_WARNING, al);
return 1;
default:
return 1;
}
}
int ssl_check_serverhello_tlsext(SSL *s)
{
int ret = SSL_TLSEXT_ERR_NOACK;
int al = SSL_AD_UNRECOGNIZED_NAME;
# ifndef OPENSSL_NO_EC
unsigned long alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
unsigned long alg_a = s->s3->tmp.new_cipher->algorithm_auth;
if ((s->tlsext_ecpointformatlist != NULL)
&& (s->tlsext_ecpointformatlist_length > 0)
&& (s->session->tlsext_ecpointformatlist != NULL)
&& (s->session->tlsext_ecpointformatlist_length > 0)
&& ((alg_k & (SSL_kEECDH | SSL_kECDHr | SSL_kECDHe))
|| (alg_a & SSL_aECDSA))) {
size_t i;
unsigned char *list;
int found_uncompressed = 0;
list = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++) {
if (*(list++) == TLSEXT_ECPOINTFORMAT_uncompressed) {
found_uncompressed = 1;
break;
}
}
if (!found_uncompressed) {
SSLerr(SSL_F_SSL_CHECK_SERVERHELLO_TLSEXT,
SSL_R_TLS_INVALID_ECPOINTFORMAT_LIST);
return -1;
}
}
ret = SSL_TLSEXT_ERR_OK;
# endif
if (s->ctx != NULL && s->ctx->tlsext_servername_callback != 0)
ret =
s->ctx->tlsext_servername_callback(s, &al,
s->ctx->tlsext_servername_arg);
else if (s->initial_ctx != NULL
&& s->initial_ctx->tlsext_servername_callback != 0)
ret =
s->initial_ctx->tlsext_servername_callback(s, &al,
s->
initial_ctx->tlsext_servername_arg);
# ifdef TLSEXT_TYPE_opaque_prf_input
if (s->s3->server_opaque_prf_input_len > 0) {
if (s->s3->server_opaque_prf_input == NULL) {
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_HANDSHAKE_FAILURE;
}
if (s->s3->client_opaque_prf_input == NULL ||
s->s3->client_opaque_prf_input_len !=
s->s3->server_opaque_prf_input_len) {
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_ILLEGAL_PARAMETER;
}
}
# endif
if ((s->tlsext_status_type != -1) && !(s->tlsext_status_expected)
&& s->ctx && s->ctx->tlsext_status_cb) {
int r;
if (s->tlsext_ocsp_resp) {
OPENSSL_free(s->tlsext_ocsp_resp);
s->tlsext_ocsp_resp = NULL;
}
s->tlsext_ocsp_resplen = -1;
r = s->ctx->tlsext_status_cb(s, s->ctx->tlsext_status_arg);
if (r == 0) {
al = SSL_AD_BAD_CERTIFICATE_STATUS_RESPONSE;
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
}
if (r < 0) {
al = SSL_AD_INTERNAL_ERROR;
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
}
}
switch (ret) {
case SSL_TLSEXT_ERR_ALERT_FATAL:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return -1;
case SSL_TLSEXT_ERR_ALERT_WARNING:
ssl3_send_alert(s, SSL3_AL_WARNING, al);
return 1;
case SSL_TLSEXT_ERR_NOACK:
s->servername_done = 0;
default:
return 1;
}
}
int ssl_parse_serverhello_tlsext(SSL *s, unsigned char **p, unsigned char *d,
int n)
{
int al = -1;
if (s->version < SSL3_VERSION)
return 1;
if (ssl_scan_serverhello_tlsext(s, p, d, n, &al) <= 0) {
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return 0;
}
if (ssl_check_serverhello_tlsext(s) <= 0) {
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_TLSEXT, SSL_R_SERVERHELLO_TLSEXT);
return 0;
}
return 1;
}
int tls1_process_ticket(SSL *s, unsigned char *session_id, int len,
const unsigned char *limit, SSL_SESSION **ret)
{
const unsigned char *p = session_id + len;
unsigned short i;
*ret = NULL;
s->tlsext_ticket_expected = 0;
if (SSL_get_options(s) & SSL_OP_NO_TICKET)
return 0;
if ((s->version <= SSL3_VERSION) || !limit)
return 0;
if (p >= limit)
return -1;
if (SSL_IS_DTLS(s)) {
i = *(p++);
p += i;
if (p >= limit)
return -1;
}
n2s(p, i);
p += i;
if (p >= limit)
return -1;
i = *(p++);
p += i;
if (p > limit)
return -1;
if ((p + 2) >= limit)
return 0;
n2s(p, i);
while ((p + 4) <= limit) {
unsigned short type, size;
n2s(p, type);
n2s(p, size);
if (p + size > limit)
return 0;
if (type == TLSEXT_TYPE_session_ticket) {
int r;
if (size == 0) {
s->tlsext_ticket_expected = 1;
return 1;
}
if (s->tls_session_secret_cb) {
return 2;
}
r = tls_decrypt_ticket(s, p, size, session_id, len, ret);
switch (r) {
case 2:
s->tlsext_ticket_expected = 1;
return 2;
case 3:
return r;
case 4:
s->tlsext_ticket_expected = 1;
return 3;
default:
return -1;
}
}
p += size;
}
return 0;
}
static int tls_decrypt_ticket(SSL *s, const unsigned char *etick,
int eticklen, const unsigned char *sess_id,
int sesslen, SSL_SESSION **psess)
{
SSL_SESSION *sess;
unsigned char *sdec;
const unsigned char *p;
int slen, mlen, renew_ticket = 0;
unsigned char tick_hmac[EVP_MAX_MD_SIZE];
HMAC_CTX hctx;
EVP_CIPHER_CTX ctx;
SSL_CTX *tctx = s->initial_ctx;
if (eticklen < 48)
return 2;
HMAC_CTX_init(&hctx);
EVP_CIPHER_CTX_init(&ctx);
if (tctx->tlsext_ticket_key_cb) {
unsigned char *nctick = (unsigned char *)etick;
int rv = tctx->tlsext_ticket_key_cb(s, nctick, nctick + 16,
&ctx, &hctx, 0);
if (rv < 0)
return -1;
if (rv == 0)
return 2;
if (rv == 2)
renew_ticket = 1;
} else {
if (memcmp(etick, tctx->tlsext_tick_key_name, 16))
return 2;
HMAC_Init_ex(&hctx, tctx->tlsext_tick_hmac_key, 16,
tlsext_tick_md(), NULL);
EVP_DecryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL,
tctx->tlsext_tick_aes_key, etick + 16);
}
mlen = HMAC_size(&hctx);
if (mlen < 0) {
EVP_CIPHER_CTX_cleanup(&ctx);
return -1;
}
eticklen -= mlen;
HMAC_Update(&hctx, etick, eticklen);
HMAC_Final(&hctx, tick_hmac, NULL);
HMAC_CTX_cleanup(&hctx);
if (CRYPTO_memcmp(tick_hmac, etick + eticklen, mlen)) {
EVP_CIPHER_CTX_cleanup(&ctx);
return 2;
}
p = etick + 16 + EVP_CIPHER_CTX_iv_length(&ctx);
eticklen -= 16 + EVP_CIPHER_CTX_iv_length(&ctx);
sdec = OPENSSL_malloc(eticklen);
if (!sdec) {
EVP_CIPHER_CTX_cleanup(&ctx);
return -1;
}
EVP_DecryptUpdate(&ctx, sdec, &slen, p, eticklen);
if (EVP_DecryptFinal(&ctx, sdec + slen, &mlen) <= 0) {
EVP_CIPHER_CTX_cleanup(&ctx);
OPENSSL_free(sdec);
return 2;
}
slen += mlen;
EVP_CIPHER_CTX_cleanup(&ctx);
p = sdec;
sess = d2i_SSL_SESSION(NULL, &p, slen);
OPENSSL_free(sdec);
if (sess) {
if (sesslen)
memcpy(sess->session_id, sess_id, sesslen);
sess->session_id_length = sesslen;
*psess = sess;
if (renew_ticket)
return 4;
else
return 3;
}
ERR_clear_error();
return 2;
}
static int tls12_find_id(int nid, tls12_lookup *table, size_t tlen)
{
size_t i;
for (i = 0; i < tlen; i++) {
if (table[i].nid == nid)
return table[i].id;
}
return -1;
}
static int tls12_find_nid(int id, tls12_lookup *table, size_t tlen)
{
size_t i;
for (i = 0; i < tlen; i++) {
if ((table[i].id) == id)
return table[i].nid;
}
return NID_undef;
}
int tls12_get_sigandhash(unsigned char *p, const EVP_PKEY *pk,
const EVP_MD *md)
{
int sig_id, md_id;
if (!md)
return 0;
md_id = tls12_find_id(EVP_MD_type(md), tls12_md,
sizeof(tls12_md) / sizeof(tls12_lookup));
if (md_id == -1)
return 0;
sig_id = tls12_get_sigid(pk);
if (sig_id == -1)
return 0;
p[0] = (unsigned char)md_id;
p[1] = (unsigned char)sig_id;
return 1;
}
int tls12_get_sigid(const EVP_PKEY *pk)
{
return tls12_find_id(pk->type, tls12_sig,
sizeof(tls12_sig) / sizeof(tls12_lookup));
}
const EVP_MD *tls12_get_hash(unsigned char hash_alg)
{
switch (hash_alg) {
# ifndef OPENSSL_NO_MD5
case TLSEXT_hash_md5:
# ifdef OPENSSL_FIPS
if (FIPS_mode())
return NULL;
# endif
return EVP_md5();
# endif
# ifndef OPENSSL_NO_SHA
case TLSEXT_hash_sha1:
return EVP_sha1();
# endif
# ifndef OPENSSL_NO_SHA256
case TLSEXT_hash_sha224:
return EVP_sha224();
case TLSEXT_hash_sha256:
return EVP_sha256();
# endif
# ifndef OPENSSL_NO_SHA512
case TLSEXT_hash_sha384:
return EVP_sha384();
case TLSEXT_hash_sha512:
return EVP_sha512();
# endif
default:
return NULL;
}
}
static int tls12_get_pkey_idx(unsigned char sig_alg)
{
switch (sig_alg) {
# ifndef OPENSSL_NO_RSA
case TLSEXT_signature_rsa:
return SSL_PKEY_RSA_SIGN;
# endif
# ifndef OPENSSL_NO_DSA
case TLSEXT_signature_dsa:
return SSL_PKEY_DSA_SIGN;
# endif
# ifndef OPENSSL_NO_ECDSA
case TLSEXT_signature_ecdsa:
return SSL_PKEY_ECC;
# endif
}
return -1;
}
static void tls1_lookup_sigalg(int *phash_nid, int *psign_nid,
int *psignhash_nid, const unsigned char *data)
{
int sign_nid = 0, hash_nid = 0;
if (!phash_nid && !psign_nid && !psignhash_nid)
return;
if (phash_nid || psignhash_nid) {
hash_nid = tls12_find_nid(data[0], tls12_md,
sizeof(tls12_md) / sizeof(tls12_lookup));
if (phash_nid)
*phash_nid = hash_nid;
}
if (psign_nid || psignhash_nid) {
sign_nid = tls12_find_nid(data[1], tls12_sig,
sizeof(tls12_sig) / sizeof(tls12_lookup));
if (psign_nid)
*psign_nid = sign_nid;
}
if (psignhash_nid) {
if (sign_nid && hash_nid)
OBJ_find_sigid_by_algs(psignhash_nid, hash_nid, sign_nid);
else
*psignhash_nid = NID_undef;
}
}
static int tls12_do_shared_sigalgs(TLS_SIGALGS *shsig,
const unsigned char *pref, size_t preflen,
const unsigned char *allow,
size_t allowlen)
{
const unsigned char *ptmp, *atmp;
size_t i, j, nmatch = 0;
for (i = 0, ptmp = pref; i < preflen; i += 2, ptmp += 2) {
if (tls12_get_hash(ptmp[0]) == NULL)
continue;
if (tls12_get_pkey_idx(ptmp[1]) == -1)
continue;
for (j = 0, atmp = allow; j < allowlen; j += 2, atmp += 2) {
if (ptmp[0] == atmp[0] && ptmp[1] == atmp[1]) {
nmatch++;
if (shsig) {
shsig->rhash = ptmp[0];
shsig->rsign = ptmp[1];
tls1_lookup_sigalg(&shsig->hash_nid,
&shsig->sign_nid,
&shsig->signandhash_nid, ptmp);
shsig++;
}
break;
}
}
}
return nmatch;
}
static int tls1_set_shared_sigalgs(SSL *s)
{
const unsigned char *pref, *allow, *conf;
size_t preflen, allowlen, conflen;
size_t nmatch;
TLS_SIGALGS *salgs = NULL;
CERT *c = s->cert;
unsigned int is_suiteb = tls1_suiteb(s);
if (c->shared_sigalgs) {
OPENSSL_free(c->shared_sigalgs);
c->shared_sigalgs = NULL;
}
if (!s->server && c->client_sigalgs && !is_suiteb) {
conf = c->client_sigalgs;
conflen = c->client_sigalgslen;
} else if (c->conf_sigalgs && !is_suiteb) {
conf = c->conf_sigalgs;
conflen = c->conf_sigalgslen;
} else
conflen = tls12_get_psigalgs(s, &conf);
if (s->options & SSL_OP_CIPHER_SERVER_PREFERENCE || is_suiteb) {
pref = conf;
preflen = conflen;
allow = c->peer_sigalgs;
allowlen = c->peer_sigalgslen;
} else {
allow = conf;
allowlen = conflen;
pref = c->peer_sigalgs;
preflen = c->peer_sigalgslen;
}
nmatch = tls12_do_shared_sigalgs(NULL, pref, preflen, allow, allowlen);
if (!nmatch)
return 1;
salgs = OPENSSL_malloc(nmatch * sizeof(TLS_SIGALGS));
if (!salgs)
return 0;
nmatch = tls12_do_shared_sigalgs(salgs, pref, preflen, allow, allowlen);
c->shared_sigalgs = salgs;
c->shared_sigalgslen = nmatch;
return 1;
}
int tls1_save_sigalgs(SSL *s, const unsigned char *data, int dsize)
{
CERT *c = s->cert;
if (!SSL_USE_SIGALGS(s))
return 1;
if (!c)
return 0;
if (c->peer_sigalgs)
OPENSSL_free(c->peer_sigalgs);
c->peer_sigalgs = OPENSSL_malloc(dsize);
if (!c->peer_sigalgs)
return 0;
c->peer_sigalgslen = dsize;
memcpy(c->peer_sigalgs, data, dsize);
return 1;
}
int tls1_process_sigalgs(SSL *s)
{
int idx;
size_t i;
const EVP_MD *md;
CERT *c = s->cert;
TLS_SIGALGS *sigptr;
if (!tls1_set_shared_sigalgs(s))
return 0;
# ifdef OPENSSL_SSL_DEBUG_BROKEN_PROTOCOL
if (s->cert->cert_flags & SSL_CERT_FLAG_BROKEN_PROTOCOL) {
const unsigned char *sigs = NULL;
if (s->server)
sigs = c->conf_sigalgs;
else
sigs = c->client_sigalgs;
if (sigs) {
idx = tls12_get_pkey_idx(sigs[1]);
md = tls12_get_hash(sigs[0]);
c->pkeys[idx].digest = md;
c->pkeys[idx].valid_flags = CERT_PKEY_EXPLICIT_SIGN;
if (idx == SSL_PKEY_RSA_SIGN) {
c->pkeys[SSL_PKEY_RSA_ENC].valid_flags =
CERT_PKEY_EXPLICIT_SIGN;
c->pkeys[SSL_PKEY_RSA_ENC].digest = md;
}
}
}
# endif
for (i = 0, sigptr = c->shared_sigalgs;
i < c->shared_sigalgslen; i++, sigptr++) {
idx = tls12_get_pkey_idx(sigptr->rsign);
if (idx > 0 && c->pkeys[idx].digest == NULL) {
md = tls12_get_hash(sigptr->rhash);
c->pkeys[idx].digest = md;
c->pkeys[idx].valid_flags = CERT_PKEY_EXPLICIT_SIGN;
if (idx == SSL_PKEY_RSA_SIGN) {
c->pkeys[SSL_PKEY_RSA_ENC].valid_flags =
CERT_PKEY_EXPLICIT_SIGN;
c->pkeys[SSL_PKEY_RSA_ENC].digest = md;
}
}
}
if (!(s->cert->cert_flags & SSL_CERT_FLAGS_CHECK_TLS_STRICT)) {
# ifndef OPENSSL_NO_DSA
if (!c->pkeys[SSL_PKEY_DSA_SIGN].digest)
c->pkeys[SSL_PKEY_DSA_SIGN].digest = EVP_sha1();
# endif
# ifndef OPENSSL_NO_RSA
if (!c->pkeys[SSL_PKEY_RSA_SIGN].digest) {
c->pkeys[SSL_PKEY_RSA_SIGN].digest = EVP_sha1();
c->pkeys[SSL_PKEY_RSA_ENC].digest = EVP_sha1();
}
# endif
# ifndef OPENSSL_NO_ECDSA
if (!c->pkeys[SSL_PKEY_ECC].digest)
c->pkeys[SSL_PKEY_ECC].digest = EVP_sha1();
# endif
}
return 1;
}
int SSL_get_sigalgs(SSL *s, int idx,
int *psign, int *phash, int *psignhash,
unsigned char *rsig, unsigned char *rhash)
{
const unsigned char *psig = s->cert->peer_sigalgs;
if (psig == NULL)
return 0;
if (idx >= 0) {
idx <<= 1;
if (idx >= (int)s->cert->peer_sigalgslen)
return 0;
psig += idx;
if (rhash)
*rhash = psig[0];
if (rsig)
*rsig = psig[1];
tls1_lookup_sigalg(phash, psign, psignhash, psig);
}
return s->cert->peer_sigalgslen / 2;
}
int SSL_get_shared_sigalgs(SSL *s, int idx,
int *psign, int *phash, int *psignhash,
unsigned char *rsig, unsigned char *rhash)
{
TLS_SIGALGS *shsigalgs = s->cert->shared_sigalgs;
if (!shsigalgs || idx >= (int)s->cert->shared_sigalgslen)
return 0;
shsigalgs += idx;
if (phash)
*phash = shsigalgs->hash_nid;
if (psign)
*psign = shsigalgs->sign_nid;
if (psignhash)
*psignhash = shsigalgs->signandhash_nid;
if (rsig)
*rsig = shsigalgs->rsign;
if (rhash)
*rhash = shsigalgs->rhash;
return s->cert->shared_sigalgslen;
}
int tls1_process_heartbeat(SSL *s)
{
unsigned char *p = &s->s3->rrec.data[0], *pl;
unsigned short hbtype;
unsigned int payload;
unsigned int padding = 16;
if (s->msg_callback)
s->msg_callback(0, s->version, TLS1_RT_HEARTBEAT,
&s->s3->rrec.data[0], s->s3->rrec.length,
s, s->msg_callback_arg);
if (1 + 2 + 16 > s->s3->rrec.length)
return 0;
hbtype = *p++;
n2s(p, payload);
if (1 + 2 + payload + 16 > s->s3->rrec.length)
return 0;
pl = p;
if (hbtype == TLS1_HB_REQUEST) {
unsigned char *buffer, *bp;
int r;
buffer = OPENSSL_malloc(1 + 2 + payload + padding);
bp = buffer;
*bp++ = TLS1_HB_RESPONSE;
s2n(payload, bp);
memcpy(bp, pl, payload);
bp += payload;
RAND_pseudo_bytes(bp, padding);
r = ssl3_write_bytes(s, TLS1_RT_HEARTBEAT, buffer,
3 + payload + padding);
if (r >= 0 && s->msg_callback)
s->msg_callback(1, s->version, TLS1_RT_HEARTBEAT,
buffer, 3 + payload + padding,
s, s->msg_callback_arg);
OPENSSL_free(buffer);
if (r < 0)
return r;
} else if (hbtype == TLS1_HB_RESPONSE) {
unsigned int seq;
n2s(pl, seq);
if (payload == 18 && seq == s->tlsext_hb_seq) {
s->tlsext_hb_seq++;
s->tlsext_hb_pending = 0;
}
}
return 0;
}
int tls1_heartbeat(SSL *s)
{
unsigned char *buf, *p;
int ret;
unsigned int payload = 18;
unsigned int padding = 16;
if (!(s->tlsext_heartbeat & SSL_TLSEXT_HB_ENABLED) ||
s->tlsext_heartbeat & SSL_TLSEXT_HB_DONT_SEND_REQUESTS) {
SSLerr(SSL_F_TLS1_HEARTBEAT, SSL_R_TLS_HEARTBEAT_PEER_DOESNT_ACCEPT);
return -1;
}
if (s->tlsext_hb_pending) {
SSLerr(SSL_F_TLS1_HEARTBEAT, SSL_R_TLS_HEARTBEAT_PENDING);
return -1;
}
if (SSL_in_init(s) || s->in_handshake) {
SSLerr(SSL_F_TLS1_HEARTBEAT, SSL_R_UNEXPECTED_MESSAGE);
return -1;
}
OPENSSL_assert(payload + padding <= 16381);
buf = OPENSSL_malloc(1 + 2 + payload + padding);
p = buf;
*p++ = TLS1_HB_REQUEST;
s2n(payload, p);
s2n(s->tlsext_hb_seq, p);
RAND_pseudo_bytes(p, 16);
p += 16;
RAND_pseudo_bytes(p, padding);
ret = ssl3_write_bytes(s, TLS1_RT_HEARTBEAT, buf, 3 + payload + padding);
if (ret >= 0) {
if (s->msg_callback)
s->msg_callback(1, s->version, TLS1_RT_HEARTBEAT,
buf, 3 + payload + padding,
s, s->msg_callback_arg);
s->tlsext_hb_pending = 1;
}
OPENSSL_free(buf);
return ret;
}
static int sig_cb(const char *elem, int len, void *arg)
{
sig_cb_st *sarg = arg;
size_t i;
char etmp[20], *p;
int sig_alg, hash_alg;
if (sarg->sigalgcnt == MAX_SIGALGLEN)
return 0;
if (len > (int)(sizeof(etmp) - 1))
return 0;
memcpy(etmp, elem, len);
etmp[len] = 0;
p = strchr(etmp, '+');
if (!p)
return 0;
*p = 0;
p++;
if (!*p)
return 0;
if (!strcmp(etmp, "RSA"))
sig_alg = EVP_PKEY_RSA;
else if (!strcmp(etmp, "DSA"))
sig_alg = EVP_PKEY_DSA;
else if (!strcmp(etmp, "ECDSA"))
sig_alg = EVP_PKEY_EC;
else
return 0;
hash_alg = OBJ_sn2nid(p);
if (hash_alg == NID_undef)
hash_alg = OBJ_ln2nid(p);
if (hash_alg == NID_undef)
return 0;
for (i = 0; i < sarg->sigalgcnt; i += 2) {
if (sarg->sigalgs[i] == sig_alg && sarg->sigalgs[i + 1] == hash_alg)
return 0;
}
sarg->sigalgs[sarg->sigalgcnt++] = hash_alg;
sarg->sigalgs[sarg->sigalgcnt++] = sig_alg;
return 1;
}
int tls1_set_sigalgs_list(CERT *c, const char *str, int client)
{
sig_cb_st sig;
sig.sigalgcnt = 0;
if (!CONF_parse_list(str, ':', 1, sig_cb, &sig))
return 0;
if (c == NULL)
return 1;
return tls1_set_sigalgs(c, sig.sigalgs, sig.sigalgcnt, client);
}
int tls1_set_sigalgs(CERT *c, const int *psig_nids, size_t salglen,
int client)
{
unsigned char *sigalgs, *sptr;
int rhash, rsign;
size_t i;
if (salglen & 1)
return 0;
sigalgs = OPENSSL_malloc(salglen);
if (sigalgs == NULL)
return 0;
for (i = 0, sptr = sigalgs; i < salglen; i += 2) {
rhash = tls12_find_id(*psig_nids++, tls12_md,
sizeof(tls12_md) / sizeof(tls12_lookup));
rsign = tls12_find_id(*psig_nids++, tls12_sig,
sizeof(tls12_sig) / sizeof(tls12_lookup));
if (rhash == -1 || rsign == -1)
goto err;
*sptr++ = rhash;
*sptr++ = rsign;
}
if (client) {
if (c->client_sigalgs)
OPENSSL_free(c->client_sigalgs);
c->client_sigalgs = sigalgs;
c->client_sigalgslen = salglen;
} else {
if (c->conf_sigalgs)
OPENSSL_free(c->conf_sigalgs);
c->conf_sigalgs = sigalgs;
c->conf_sigalgslen = salglen;
}
return 1;
err:
OPENSSL_free(sigalgs);
return 0;
}
static int tls1_check_sig_alg(CERT *c, X509 *x, int default_nid)
{
int sig_nid;
size_t i;
if (default_nid == -1)
return 1;
sig_nid = X509_get_signature_nid(x);
if (default_nid)
return sig_nid == default_nid ? 1 : 0;
for (i = 0; i < c->shared_sigalgslen; i++)
if (sig_nid == c->shared_sigalgs[i].signandhash_nid)
return 1;
return 0;
}
void tls1_set_cert_validity(SSL *s)
{
tls1_check_chain(s, NULL, NULL, NULL, SSL_PKEY_RSA_ENC);
tls1_check_chain(s, NULL, NULL, NULL, SSL_PKEY_RSA_SIGN);
tls1_check_chain(s, NULL, NULL, NULL, SSL_PKEY_DSA_SIGN);
tls1_check_chain(s, NULL, NULL, NULL, SSL_PKEY_DH_RSA);
tls1_check_chain(s, NULL, NULL, NULL, SSL_PKEY_DH_DSA);
tls1_check_chain(s, NULL, NULL, NULL, SSL_PKEY_ECC);
}
