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
OPENSSL_free(s->tlsext_session_ticket);
ssl3_free(s);
}
void tls1_clear(SSL *s)
{
ssl3_clear(s);
if (s->method->version == TLS_ANY_VERSION)
s->version = TLS_MAX_VERSION;
else
s->version = s->method->version;
}
int tls1_ec_curve_id2nid(int curve_id, unsigned int *pflags)
{
const tls_curve_info *cinfo;
if ((curve_id < 1) || ((unsigned int)curve_id > OSSL_NELEM(nid_list)))
return 0;
cinfo = nid_list + curve_id - 1;
if (pflags)
*pflags = cinfo->flags;
return cinfo->nid;
}
int tls1_ec_nid2curve_id(int nid)
{
size_t i;
for (i = 0; i < OSSL_NELEM(nid_list); i++) {
if (nid_list[i].nid == nid)
return i + 1;
}
return 0;
}
static int tls1_get_curvelist(SSL *s, int sess,
const unsigned char **pcurves, size_t *num_curves)
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
*pcurves = eccurves_default;
pcurveslen = sizeof(eccurves_default);
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
static int tls_curve_allowed(SSL *s, const unsigned char *curve, int op)
{
const tls_curve_info *cinfo;
if (curve[0])
return 1;
if ((curve[1] < 1) || ((size_t)curve[1] > OSSL_NELEM(nid_list)))
return 0;
cinfo = &nid_list[curve[1] - 1];
# ifdef OPENSSL_NO_EC2M
if (cinfo->flags & TLS_CURVE_CHAR2)
return 0;
# endif
return ssl_security(s, op, cinfo->secbits, cinfo->nid, (void *)curve);
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
return tls_curve_allowed(s, p + 1, SSL_SECOP_CURVE_CHECK);
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
(s, !(s->options & SSL_OP_CIPHER_SERVER_PREFERENCE), &pref, &num_pref))
return nmatch == -1 ? 0 : NID_undef;
if (num_supp == 0 && (s->options & SSL_OP_CIPHER_SERVER_PREFERENCE) != 0) {
supp = eccurves_all;
num_supp = sizeof(eccurves_all) / 2;
} else if (num_pref == 0 &&
(s->options & SSL_OP_CIPHER_SERVER_PREFERENCE) == 0) {
pref = eccurves_all;
num_pref = sizeof(eccurves_all) / 2;
}
k = 0;
for (i = 0; i < num_pref; i++, pref += 2) {
const unsigned char *tsupp = supp;
for (j = 0; j < num_supp; j++, tsupp += 2) {
if (pref[0] == tsupp[0] && pref[1] == tsupp[1]) {
if (!tls_curve_allowed(s, pref, SSL_SECOP_CURVE_SHARED))
continue;
if (nmatch == k) {
int id = (pref[0] << 8) | pref[1];
return tls1_ec_curve_id2nid(id, NULL);
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
clist = OPENSSL_malloc(ncurves * 2);
if (clist == NULL)
return 0;
for (i = 0, p = clist; i < ncurves; i++) {
unsigned long idmask;
int id;
id = tls1_ec_nid2curve_id(curves[i]);
idmask = 1L << id;
if (!id || (dup_list & idmask)) {
OPENSSL_free(clist);
return 0;
}
dup_list |= idmask;
s2n(id, p);
}
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
if (elem == NULL)
return 0;
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
int tls1_set_curves_list(unsigned char **pext, size_t *pextlen, const char *str)
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
int id;
const EC_GROUP *grp;
if (!ec)
return 0;
grp = EC_KEY_get0_group(ec);
if (!grp)
return 0;
id = EC_GROUP_get_curve_name(grp);
id = tls1_ec_nid2curve_id(id);
if (id == 0)
return 0;
curve_id[0] = 0;
curve_id[1] = (unsigned char)id;
if (comp_id) {
if (EC_KEY_get0_public_key(ec) == NULL)
return 0;
if (EC_KEY_get_conv_form(ec) == POINT_CONVERSION_UNCOMPRESSED) {
*comp_id = TLSEXT_ECPOINTFORMAT_uncompressed;
} else {
if ((nid_list[id - 1].flags & TLS_CURVE_TYPE) == TLS_CURVE_PRIME)
*comp_id = TLSEXT_ECPOINTFORMAT_ansiX962_compressed_prime;
else
*comp_id = TLSEXT_ECPOINTFORMAT_ansiX962_compressed_char2;
}
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
if (j == 1 && num_curves == 0) {
break;
}
for (i = 0; i < num_curves; i++, pcurves += 2) {
if (pcurves[0] == curve_id[0] && pcurves[1] == curve_id[1])
break;
}
if (i == num_curves)
return 0;
if (!s->server)
break;
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
pkey = X509_get0_pubkey(x);
if (!pkey)
return 0;
if (EVP_PKEY_id(pkey) != EVP_PKEY_EC)
return 1;
rv = tls1_set_ec_id(curve_id, &comp_id, EVP_PKEY_get0_EC_KEY(pkey));
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
s->s3->tmp.md[SSL_PKEY_ECC] = EVP_sha256();
else
s->s3->tmp.md[SSL_PKEY_ECC] = EVP_sha384();
}
}
return rv;
}
int tls1_check_ec_tmp_key(SSL *s, unsigned long cid)
{
if (tls1_suiteb(s)) {
unsigned char curve_id[2];
if (cid == TLS1_CK_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256)
curve_id[1] = TLSEXT_curve_P_256;
else if (cid == TLS1_CK_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384)
curve_id[1] = TLSEXT_curve_P_384;
else
return 0;
curve_id[0] = 0;
if (!tls1_check_ec_key(s, curve_id, NULL))
return 0;
return 1;
}
if (tls1_shared_curve(s, 0))
return 1;
return 0;
}
static int tls1_check_cert_param(SSL *s, X509 *x, int set_ee_md)
{
return 1;
}
size_t tls12_get_psigalgs(SSL *s, const unsigned char **psigs)
{
#ifndef OPENSSL_NO_EC
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
#endif
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
#ifndef OPENSSL_NO_EC
if (EVP_PKEY_id(pkey) == EVP_PKEY_EC) {
unsigned char curve_id[2], comp_id;
if (!tls1_set_ec_id(curve_id, &comp_id, EVP_PKEY_get0_EC_KEY(pkey)))
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
#endif
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
if (!ssl_security(s, SSL_SECOP_SIGALG_CHECK,
EVP_MD_size(*pmd) * 4, EVP_MD_type(*pmd), (void *)sig)) {
SSLerr(SSL_F_TLS12_CHECK_PEER_SIGALG, SSL_R_WRONG_SIGNATURE_TYPE);
return 0;
}
s->s3->tmp.peer_md = *pmd;
return 1;
}
void ssl_set_client_disabled(SSL *s)
{
s->s3->tmp.mask_a = 0;
s->s3->tmp.mask_k = 0;
ssl_set_sig_mask(&s->s3->tmp.mask_a, s, SSL_SECOP_SIGALG_MASK);
ssl_get_client_min_max_version(s, &s->s3->tmp.min_ver, &s->s3->tmp.max_ver);
#ifndef OPENSSL_NO_PSK
if (!s->psk_client_callback) {
s->s3->tmp.mask_a |= SSL_aPSK;
s->s3->tmp.mask_k |= SSL_PSK;
}
#endif
#ifndef OPENSSL_NO_SRP
if (!(s->srp_ctx.srp_Mask & SSL_kSRP)) {
s->s3->tmp.mask_a |= SSL_aSRP;
s->s3->tmp.mask_k |= SSL_kSRP;
}
#endif
}
int ssl_cipher_disabled(SSL *s, const SSL_CIPHER *c, int op)
{
if (c->algorithm_mkey & s->s3->tmp.mask_k
|| c->algorithm_auth & s->s3->tmp.mask_a)
return 1;
if (s->s3->tmp.max_ver == 0)
return 1;
if (!SSL_IS_DTLS(s) && ((c->min_tls > s->s3->tmp.max_ver)
|| (c->max_tls < s->s3->tmp.min_ver)))
return 1;
if (SSL_IS_DTLS(s) && (DTLS_VERSION_GT(c->min_dtls, s->s3->tmp.max_ver)
|| DTLS_VERSION_LT(c->max_dtls, s->s3->tmp.min_ver)))
return 1;
return !ssl_security(s, op, c->strength_bits, 0, (void *)c);
}
static int tls_use_ticket(SSL *s)
{
if (s->options & SSL_OP_NO_TICKET)
return 0;
return ssl_security(s, SSL_SECOP_TICKET, 0, 0, NULL);
}
static int compare_uint(const void *p1, const void *p2)
{
unsigned int u1 = *((const unsigned int *)p1);
unsigned int u2 = *((const unsigned int *)p2);
if (u1 < u2)
return -1;
else if (u1 > u2)
return 1;
else
return 0;
}
static int tls1_check_duplicate_extensions(const PACKET *packet)
{
PACKET extensions = *packet;
size_t num_extensions = 0, i = 0;
unsigned int *extension_types = NULL;
int ret = 0;
while (PACKET_remaining(&extensions) > 0) {
unsigned int type;
PACKET extension;
if (!PACKET_get_net_2(&extensions, &type) ||
!PACKET_get_length_prefixed_2(&extensions, &extension)) {
goto done;
}
num_extensions++;
}
if (num_extensions <= 1)
return 1;
extension_types = OPENSSL_malloc(sizeof(unsigned int) * num_extensions);
if (extension_types == NULL) {
SSLerr(SSL_F_TLS1_CHECK_DUPLICATE_EXTENSIONS, ERR_R_MALLOC_FAILURE);
goto done;
}
extensions = *packet;
for (i = 0; i < num_extensions; i++) {
PACKET extension;
if (!PACKET_get_net_2(&extensions, &extension_types[i]) ||
!PACKET_get_length_prefixed_2(&extensions, &extension)) {
SSLerr(SSL_F_TLS1_CHECK_DUPLICATE_EXTENSIONS, ERR_R_INTERNAL_ERROR);
goto done;
}
}
if (PACKET_remaining(&extensions) != 0) {
SSLerr(SSL_F_TLS1_CHECK_DUPLICATE_EXTENSIONS, ERR_R_INTERNAL_ERROR);
goto done;
}
qsort(extension_types, num_extensions, sizeof(unsigned int), compare_uint);
for (i = 1; i < num_extensions; i++) {
if (extension_types[i - 1] == extension_types[i])
goto done;
}
ret = 1;
done:
OPENSSL_free(extension_types);
return ret;
}
unsigned char *ssl_add_clienthello_tlsext(SSL *s, unsigned char *buf,
unsigned char *limit, int *al)
{
int extdatalen = 0;
unsigned char *orig = buf;
unsigned char *ret = buf;
#ifndef OPENSSL_NO_EC
int using_ecc = 0;
if (s->version >= TLS1_VERSION || SSL_IS_DTLS(s)) {
int i;
unsigned long alg_k, alg_a;
STACK_OF(SSL_CIPHER) *cipher_stack = SSL_get_ciphers(s);
for (i = 0; i < sk_SSL_CIPHER_num(cipher_stack); i++) {
const SSL_CIPHER *c = sk_SSL_CIPHER_value(cipher_stack, i);
alg_k = c->algorithm_mkey;
alg_a = c->algorithm_auth;
if ((alg_k & (SSL_kECDHE | SSL_kECDHEPSK))
|| (alg_a & SSL_aECDSA)) {
using_ecc = 1;
break;
}
}
}
#endif
ret += 2;
if (ret >= limit)
return NULL;
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
if (s->client_version == SSL3_VERSION)
goto done;
if (s->tlsext_hostname != NULL) {
unsigned long size_str;
long lenmax;
if ((lenmax = limit - ret - 9) < 0
|| (size_str = strlen(s->tlsext_hostname)) > (unsigned long)lenmax)
return NULL;
s2n(TLSEXT_TYPE_server_name, ret);
s2n(size_str + 5, ret);
s2n(size_str + 3, ret);
*(ret++) = (unsigned char)TLSEXT_NAMETYPE_host_name;
s2n(size_str, ret);
memcpy(ret, s->tlsext_hostname, size_str);
ret += size_str;
}
#ifndef OPENSSL_NO_SRP
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
#endif
#ifndef OPENSSL_NO_EC
if (using_ecc) {
long lenmax;
const unsigned char *pcurves, *pformats;
size_t num_curves, num_formats, curves_list_len;
size_t i;
unsigned char *etmp;
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
s2n(TLSEXT_TYPE_elliptic_curves, ret);
etmp = ret + 4;
for (i = 0; i < num_curves; i++, pcurves += 2) {
if (tls_curve_allowed(s, pcurves, SSL_SECOP_CURVE_SUPPORTED)) {
*etmp++ = pcurves[0];
*etmp++ = pcurves[1];
}
}
curves_list_len = etmp - ret - 4;
s2n(curves_list_len + 2, ret);
s2n(curves_list_len, ret);
ret += curves_list_len;
}
#endif
if (tls_use_ticket(s)) {
int ticklen;
if (!s->new_session && s->session && s->session->tlsext_tick)
ticklen = s->session->tlsext_ticklen;
else if (s->session && s->tlsext_session_ticket &&
s->tlsext_session_ticket->data) {
ticklen = s->tlsext_session_ticket->length;
s->session->tlsext_tick = OPENSSL_malloc(ticklen);
if (s->session->tlsext_tick == NULL)
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
if (SSL_CLIENT_USE_SIGALGS(s)) {
size_t salglen;
const unsigned char *salg;
unsigned char *etmp;
salglen = tls12_get_psigalgs(s, &salg);
if ((size_t)(limit - ret) < salglen + 6)
return NULL;
s2n(TLSEXT_TYPE_signature_algorithms, ret);
etmp = ret;
ret += 4;
salglen = tls12_copy_sigalgs(s, ret, salg, salglen);
s2n(salglen + 2, etmp);
s2n(salglen, etmp);
ret += salglen;
}
#ifndef OPENSSL_NO_OCSP
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
#endif
#ifndef OPENSSL_NO_HEARTBEATS
if (SSL_IS_DTLS(s)) {
if ((limit - ret - 4 - 1) < 0)
return NULL;
s2n(TLSEXT_TYPE_heartbeat, ret);
s2n(1, ret);
if (s->tlsext_heartbeat & SSL_DTLSEXT_HB_DONT_RECV_REQUESTS)
*(ret++) = SSL_DTLSEXT_HB_DONT_SEND_REQUESTS;
else
*(ret++) = SSL_DTLSEXT_HB_ENABLED;
}
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
if (s->ctx->next_proto_select_cb && !s->s3->tmp.finish_md_len) {
if (limit - ret - 4 < 0)
return NULL;
s2n(TLSEXT_TYPE_next_proto_neg, ret);
s2n(0, ret);
}
#endif
if (s->alpn_client_proto_list && !s->s3->tmp.finish_md_len) {
if ((size_t)(limit - ret) < 6 + s->alpn_client_proto_list_len)
return NULL;
s2n(TLSEXT_TYPE_application_layer_protocol_negotiation, ret);
s2n(2 + s->alpn_client_proto_list_len, ret);
s2n(s->alpn_client_proto_list_len, ret);
memcpy(ret, s->alpn_client_proto_list, s->alpn_client_proto_list_len);
ret += s->alpn_client_proto_list_len;
s->s3->alpn_sent = 1;
}
#ifndef OPENSSL_NO_SRTP
if (SSL_IS_DTLS(s) && SSL_get_srtp_profiles(s)) {
int el;
if (ssl_add_clienthello_use_srtp_ext(s, 0, &el, 0)) {
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
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
#endif
custom_ext_init(&s->cert->cli_ext);
if (!custom_ext_add(s, 0, &ret, limit, al))
return NULL;
s2n(TLSEXT_TYPE_encrypt_then_mac, ret);
s2n(0, ret);
#ifndef OPENSSL_NO_CT
if (s->ct_validation_callback != NULL) {
s2n(TLSEXT_TYPE_signed_certificate_timestamp, ret);
s2n(0, ret);
}
#endif
s2n(TLSEXT_TYPE_extended_master_secret, ret);
s2n(0, ret);
if (s->options & SSL_OP_TLSEXT_PADDING) {
int hlen = ret - (unsigned char *)s->init_buf->data;
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
done:
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
#ifndef OPENSSL_NO_NEXTPROTONEG
int next_proto_neg_seen;
#endif
#ifndef OPENSSL_NO_EC
unsigned long alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
unsigned long alg_a = s->s3->tmp.new_cipher->algorithm_auth;
int using_ecc = (alg_k & SSL_kECDHE) || (alg_a & SSL_aECDSA);
using_ecc = using_ecc && (s->session->tlsext_ecpointformatlist != NULL);
#endif
ret += 2;
if (ret >= limit)
return NULL;
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
if (s->version == SSL3_VERSION)
goto done;
if (!s->hit && s->servername_done == 1
&& s->session->tlsext_hostname != NULL) {
if ((long)(limit - ret - 4) < 0)
return NULL;
s2n(TLSEXT_TYPE_server_name, ret);
s2n(0, ret);
}
#ifndef OPENSSL_NO_EC
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
#endif
if (s->tlsext_ticket_expected && tls_use_ticket(s)) {
if ((long)(limit - ret - 4) < 0)
return NULL;
s2n(TLSEXT_TYPE_session_ticket, ret);
s2n(0, ret);
} else {
s->tlsext_ticket_expected = 0;
}
if (s->tlsext_status_expected) {
if ((long)(limit - ret - 4) < 0)
return NULL;
s2n(TLSEXT_TYPE_status_request, ret);
s2n(0, ret);
}
#ifndef OPENSSL_NO_SRTP
if (SSL_IS_DTLS(s) && s->srtp_profile) {
int el;
if (ssl_add_serverhello_use_srtp_ext(s, 0, &el, 0)) {
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
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
#endif
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
#ifndef OPENSSL_NO_HEARTBEATS
if (SSL_IS_DTLS(s) && (s->tlsext_heartbeat & SSL_DTLSEXT_HB_ENABLED)) {
if ((limit - ret - 4 - 1) < 0)
return NULL;
s2n(TLSEXT_TYPE_heartbeat, ret);
s2n(1, ret);
if (s->tlsext_heartbeat & SSL_DTLSEXT_HB_DONT_RECV_REQUESTS)
*(ret++) = SSL_DTLSEXT_HB_DONT_SEND_REQUESTS;
else
*(ret++) = SSL_DTLSEXT_HB_ENABLED;
}
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
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
#endif
if (!custom_ext_add(s, 1, &ret, limit, al))
return NULL;
if (s->s3->flags & TLS1_FLAGS_ENCRYPT_THEN_MAC) {
if (s->s3->tmp.new_cipher->algorithm_mac == SSL_AEAD
|| s->s3->tmp.new_cipher->algorithm_enc == SSL_RC4
|| s->s3->tmp.new_cipher->algorithm_enc == SSL_eGOST2814789CNT
|| s->s3->tmp.new_cipher->algorithm_enc == SSL_eGOST2814789CNT12)
s->s3->flags &= ~TLS1_FLAGS_ENCRYPT_THEN_MAC;
else {
s2n(TLSEXT_TYPE_encrypt_then_mac, ret);
s2n(0, ret);
}
}
if (s->s3->flags & TLS1_FLAGS_RECEIVED_EXTMS) {
s2n(TLSEXT_TYPE_extended_master_secret, ret);
s2n(0, ret);
}
if (s->s3->alpn_selected != NULL) {
const unsigned char *selected = s->s3->alpn_selected;
unsigned int len = s->s3->alpn_selected_len;
if ((long)(limit - ret - 4 - 2 - 1 - len) < 0)
return NULL;
s2n(TLSEXT_TYPE_application_layer_protocol_negotiation, ret);
s2n(3 + len, ret);
s2n(1 + len, ret);
*ret++ = len;
memcpy(ret, selected, len);
ret += len;
}
done:
if ((extdatalen = ret - orig - 2) == 0)
return orig;
s2n(extdatalen, orig);
return ret;
}
static int tls1_alpn_handle_client_hello(SSL *s, PACKET *pkt, int *al)
{
PACKET protocol_list, save_protocol_list, protocol;
*al = SSL_AD_DECODE_ERROR;
if (!PACKET_as_length_prefixed_2(pkt, &protocol_list)
|| PACKET_remaining(&protocol_list) < 2) {
return 0;
}
save_protocol_list = protocol_list;
do {
if (!PACKET_get_length_prefixed_1(&protocol_list, &protocol)
|| PACKET_remaining(&protocol) == 0) {
return 0;
}
} while (PACKET_remaining(&protocol_list) != 0);
if (!PACKET_memdup(&save_protocol_list,
&s->s3->alpn_proposed, &s->s3->alpn_proposed_len)) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
return 1;
}
static int tls1_alpn_handle_client_hello_late(SSL *s, int *al)
{
const unsigned char *selected = NULL;
unsigned char selected_len = 0;
if (s->ctx->alpn_select_cb != NULL && s->s3->alpn_proposed != NULL) {
int r = s->ctx->alpn_select_cb(s, &selected, &selected_len,
s->s3->alpn_proposed,
s->s3->alpn_proposed_len,
s->ctx->alpn_select_cb_arg);
if (r == SSL_TLSEXT_ERR_OK) {
OPENSSL_free(s->s3->alpn_selected);
s->s3->alpn_selected = OPENSSL_memdup(selected, selected_len);
if (s->s3->alpn_selected == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
s->s3->alpn_selected_len = selected_len;
#ifndef OPENSSL_NO_NEXTPROTONEG
s->s3->next_proto_neg_seen = 0;
#endif
} else {
*al = SSL_AD_NO_APPLICATION_PROTOCOL;
return 0;
}
}
return 1;
}
static void ssl_check_for_safari(SSL *s, const PACKET *pkt)
{
unsigned int type;
PACKET sni, tmppkt;
size_t ext_len;
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
0x00, 0x0d,
0x00, 0x0c,
0x00, 0x0a,
0x05, 0x01,
0x04, 0x01,
0x02, 0x01,
0x04, 0x03,
0x02, 0x03,
};
static const size_t kSafariCommonExtensionsLength = 18;
tmppkt = *pkt;
if (!PACKET_forward(&tmppkt, 2)
|| !PACKET_get_net_2(&tmppkt, &type)
|| !PACKET_get_length_prefixed_2(&tmppkt, &sni)) {
return;
}
if (type != TLSEXT_TYPE_server_name)
return;
ext_len = TLS1_get_client_version(s) >= TLS1_2_VERSION ?
sizeof(kSafariExtensionsBlock) : kSafariCommonExtensionsLength;
s->s3->is_probably_safari = PACKET_equal(&tmppkt, kSafariExtensionsBlock,
ext_len);
}
static int ssl_scan_clienthello_tlsext(SSL *s, PACKET *pkt, int *al)
{
unsigned int type;
int renegotiate_seen = 0;
PACKET extensions;
*al = SSL_AD_DECODE_ERROR;
s->servername_done = 0;
s->tlsext_status_type = -1;
#ifndef OPENSSL_NO_NEXTPROTONEG
s->s3->next_proto_neg_seen = 0;
#endif
OPENSSL_free(s->s3->alpn_selected);
s->s3->alpn_selected = NULL;
s->s3->alpn_selected_len = 0;
OPENSSL_free(s->s3->alpn_proposed);
s->s3->alpn_proposed = NULL;
s->s3->alpn_proposed_len = 0;
#ifndef OPENSSL_NO_HEARTBEATS
s->tlsext_heartbeat &= ~(SSL_DTLSEXT_HB_ENABLED |
SSL_DTLSEXT_HB_DONT_SEND_REQUESTS);
#endif
#ifndef OPENSSL_NO_EC
if (s->options & SSL_OP_SAFARI_ECDHE_ECDSA_BUG)
ssl_check_for_safari(s, pkt);
#endif
OPENSSL_free(s->s3->tmp.peer_sigalgs);
s->s3->tmp.peer_sigalgs = NULL;
s->s3->flags &= ~TLS1_FLAGS_ENCRYPT_THEN_MAC;
#ifndef OPENSSL_NO_SRP
OPENSSL_free(s->srp_ctx.login);
s->srp_ctx.login = NULL;
#endif
s->srtp_profile = NULL;
if (PACKET_remaining(pkt) == 0)
goto ri_check;
if (!PACKET_as_length_prefixed_2(pkt, &extensions))
return 0;
if (!tls1_check_duplicate_extensions(&extensions))
return 0;
while (PACKET_get_net_2(&extensions, &type)) {
PACKET extension;
if (!PACKET_get_length_prefixed_2(&extensions, &extension))
return 0;
if (s->tlsext_debug_cb)
s->tlsext_debug_cb(s, 0, type, PACKET_data(&extension),
PACKET_remaining(&extension),
s->tlsext_debug_arg);
if (type == TLSEXT_TYPE_renegotiate) {
if (!ssl_parse_clienthello_renegotiate_ext(s, &extension, al))
return 0;
renegotiate_seen = 1;
} else if (s->version == SSL3_VERSION) {
}
else if (type == TLSEXT_TYPE_server_name) {
unsigned int servname_type;
PACKET sni, hostname;
if (!PACKET_as_length_prefixed_2(&extension, &sni)
|| PACKET_remaining(&sni) == 0) {
return 0;
}
if (!PACKET_get_1(&sni, &servname_type)
|| servname_type != TLSEXT_NAMETYPE_host_name
|| !PACKET_as_length_prefixed_2(&sni, &hostname)) {
return 0;
}
if (!s->hit) {
if (PACKET_remaining(&hostname) > TLSEXT_MAXLEN_host_name) {
*al = TLS1_AD_UNRECOGNIZED_NAME;
return 0;
}
if (PACKET_contains_zero_byte(&hostname)) {
*al = TLS1_AD_UNRECOGNIZED_NAME;
return 0;
}
if (!PACKET_strndup(&hostname, &s->session->tlsext_hostname)) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
s->servername_done = 1;
} else {
s->servername_done = s->session->tlsext_hostname
&& PACKET_equal(&hostname, s->session->tlsext_hostname,
strlen(s->session->tlsext_hostname));
}
}
#ifndef OPENSSL_NO_SRP
else if (type == TLSEXT_TYPE_srp) {
PACKET srp_I;
if (!PACKET_as_length_prefixed_1(&extension, &srp_I))
return 0;
if (PACKET_contains_zero_byte(&srp_I))
return 0;
if (!PACKET_strndup(&srp_I, &s->srp_ctx.login)) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
}
#endif
#ifndef OPENSSL_NO_EC
else if (type == TLSEXT_TYPE_ec_point_formats) {
PACKET ec_point_format_list;
if (!PACKET_as_length_prefixed_1(&extension, &ec_point_format_list)
|| PACKET_remaining(&ec_point_format_list) == 0) {
return 0;
}
if (!s->hit) {
if (!PACKET_memdup(&ec_point_format_list,
&s->session->tlsext_ecpointformatlist,
&s->
session->tlsext_ecpointformatlist_length)) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
}
} else if (type == TLSEXT_TYPE_elliptic_curves) {
PACKET elliptic_curve_list;
if (!PACKET_as_length_prefixed_2(&extension, &elliptic_curve_list)
|| PACKET_remaining(&elliptic_curve_list) == 0
|| (PACKET_remaining(&elliptic_curve_list) % 2) != 0) {
return 0;
}
if (!s->hit) {
if (!PACKET_memdup(&elliptic_curve_list,
&s->session->tlsext_ellipticcurvelist,
&s->
session->tlsext_ellipticcurvelist_length)) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
}
}
#endif
else if (type == TLSEXT_TYPE_session_ticket) {
if (s->tls_session_ticket_ext_cb &&
!s->tls_session_ticket_ext_cb(s, PACKET_data(&extension),
PACKET_remaining(&extension),
s->tls_session_ticket_ext_cb_arg))
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
} else if (type == TLSEXT_TYPE_signature_algorithms) {
PACKET supported_sig_algs;
if (!PACKET_as_length_prefixed_2(&extension, &supported_sig_algs)
|| (PACKET_remaining(&supported_sig_algs) % 2) != 0
|| PACKET_remaining(&supported_sig_algs) == 0) {
return 0;
}
if (!s->hit) {
if (!tls1_save_sigalgs(s, PACKET_data(&supported_sig_algs),
PACKET_remaining(&supported_sig_algs))) {
return 0;
}
}
} else if (type == TLSEXT_TYPE_status_request) {
if (!PACKET_get_1(&extension,
(unsigned int *)&s->tlsext_status_type)) {
return 0;
}
#ifndef OPENSSL_NO_OCSP
if (s->tlsext_status_type == TLSEXT_STATUSTYPE_ocsp) {
const unsigned char *ext_data;
PACKET responder_id_list, exts;
if (!PACKET_get_length_prefixed_2
(&extension, &responder_id_list))
return 0;
while (PACKET_remaining(&responder_id_list) > 0) {
OCSP_RESPID *id;
PACKET responder_id;
const unsigned char *id_data;
if (!PACKET_get_length_prefixed_2(&responder_id_list,
&responder_id)
|| PACKET_remaining(&responder_id) == 0) {
return 0;
}
if (s->tlsext_ocsp_ids == NULL
&& (s->tlsext_ocsp_ids =
sk_OCSP_RESPID_new_null()) == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
id_data = PACKET_data(&responder_id);
id = d2i_OCSP_RESPID(NULL, &id_data,
PACKET_remaining(&responder_id));
if (id == NULL)
return 0;
if (id_data != PACKET_end(&responder_id)) {
OCSP_RESPID_free(id);
return 0;
}
if (!sk_OCSP_RESPID_push(s->tlsext_ocsp_ids, id)) {
OCSP_RESPID_free(id);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
}
if (!PACKET_as_length_prefixed_2(&extension, &exts))
return 0;
if (PACKET_remaining(&exts) > 0) {
ext_data = PACKET_data(&exts);
sk_X509_EXTENSION_pop_free(s->tlsext_ocsp_exts,
X509_EXTENSION_free);
s->tlsext_ocsp_exts =
d2i_X509_EXTENSIONS(NULL, &ext_data,
PACKET_remaining(&exts));
if (s->tlsext_ocsp_exts == NULL
|| ext_data != PACKET_end(&exts)) {
return 0;
}
}
} else
#endif
{
s->tlsext_status_type = -1;
}
}
#ifndef OPENSSL_NO_HEARTBEATS
else if (SSL_IS_DTLS(s) && type == TLSEXT_TYPE_heartbeat) {
unsigned int hbtype;
if (!PACKET_get_1(&extension, &hbtype)
|| PACKET_remaining(&extension)) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
switch (hbtype) {
case 0x01:
s->tlsext_heartbeat |= SSL_DTLSEXT_HB_ENABLED;
break;
case 0x02:
s->tlsext_heartbeat |= SSL_DTLSEXT_HB_ENABLED;
s->tlsext_heartbeat |= SSL_DTLSEXT_HB_DONT_SEND_REQUESTS;
break;
default:
*al = SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
}
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
else if (type == TLSEXT_TYPE_next_proto_neg &&
s->s3->tmp.finish_md_len == 0) {
s->s3->next_proto_neg_seen = 1;
}
#endif
else if (type == TLSEXT_TYPE_application_layer_protocol_negotiation &&
s->s3->tmp.finish_md_len == 0) {
if (!tls1_alpn_handle_client_hello(s, &extension, al))
return 0;
}
#ifndef OPENSSL_NO_SRTP
else if (SSL_IS_DTLS(s) && SSL_get_srtp_profiles(s)
&& type == TLSEXT_TYPE_use_srtp) {
if (ssl_parse_clienthello_use_srtp_ext(s, &extension, al))
return 0;
}
#endif
else if (type == TLSEXT_TYPE_encrypt_then_mac)
s->s3->flags |= TLS1_FLAGS_ENCRYPT_THEN_MAC;
else if (!s->hit) {
if (custom_ext_parse(s, 1, type, PACKET_data(&extension),
PACKET_remaining(&extension), al) <= 0)
return 0;
}
}
if (PACKET_remaining(pkt) != 0) {
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
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
int ssl_parse_clienthello_tlsext(SSL *s, PACKET *pkt)
{
int al = -1;
custom_ext_init(&s->cert->srv_ext);
if (ssl_scan_clienthello_tlsext(s, pkt, &al) <= 0) {
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return 0;
}
if (ssl_check_clienthello_tlsext_early(s) <= 0) {
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_TLSEXT, SSL_R_CLIENTHELLO_TLSEXT);
return 0;
}
return 1;
}
static char ssl_next_proto_validate(PACKET *pkt)
{
PACKET tmp_protocol;
while (PACKET_remaining(pkt)) {
if (!PACKET_get_length_prefixed_1(pkt, &tmp_protocol)
|| PACKET_remaining(&tmp_protocol) == 0)
return 0;
}
return 1;
}
static int ssl_scan_serverhello_tlsext(SSL *s, PACKET *pkt, int *al)
{
unsigned int length, type, size;
int tlsext_servername = 0;
int renegotiate_seen = 0;
#ifndef OPENSSL_NO_NEXTPROTONEG
s->s3->next_proto_neg_seen = 0;
#endif
s->tlsext_ticket_expected = 0;
OPENSSL_free(s->s3->alpn_selected);
s->s3->alpn_selected = NULL;
#ifndef OPENSSL_NO_HEARTBEATS
s->tlsext_heartbeat &= ~(SSL_DTLSEXT_HB_ENABLED |
SSL_DTLSEXT_HB_DONT_SEND_REQUESTS);
#endif
s->s3->flags &= ~TLS1_FLAGS_ENCRYPT_THEN_MAC;
s->s3->flags &= ~TLS1_FLAGS_RECEIVED_EXTMS;
if (!PACKET_get_net_2(pkt, &length))
goto ri_check;
if (PACKET_remaining(pkt) != length) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (!tls1_check_duplicate_extensions(pkt)) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
while (PACKET_get_net_2(pkt, &type) && PACKET_get_net_2(pkt, &size)) {
const unsigned char *data;
PACKET spkt;
if (!PACKET_get_sub_packet(pkt, &spkt, size)
|| !PACKET_peek_bytes(&spkt, &data, size))
goto ri_check;
if (s->tlsext_debug_cb)
s->tlsext_debug_cb(s, 1, type, data, size, s->tlsext_debug_arg);
if (type == TLSEXT_TYPE_renegotiate) {
if (!ssl_parse_serverhello_renegotiate_ext(s, &spkt, al))
return 0;
renegotiate_seen = 1;
} else if (s->version == SSL3_VERSION) {
} else if (type == TLSEXT_TYPE_server_name) {
if (s->tlsext_hostname == NULL || size > 0) {
*al = TLS1_AD_UNRECOGNIZED_NAME;
return 0;
}
tlsext_servername = 1;
}
#ifndef OPENSSL_NO_EC
else if (type == TLSEXT_TYPE_ec_point_formats) {
unsigned int ecpointformatlist_length;
if (!PACKET_get_1(&spkt, &ecpointformatlist_length)
|| ecpointformatlist_length != size - 1) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
if (!s->hit) {
s->session->tlsext_ecpointformatlist_length = 0;
OPENSSL_free(s->session->tlsext_ecpointformatlist);
if ((s->session->tlsext_ecpointformatlist =
OPENSSL_malloc(ecpointformatlist_length)) == NULL) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
s->session->tlsext_ecpointformatlist_length =
ecpointformatlist_length;
if (!PACKET_copy_bytes(&spkt,
s->session->tlsext_ecpointformatlist,
ecpointformatlist_length)) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
}
}
#endif
else if (type == TLSEXT_TYPE_session_ticket) {
if (s->tls_session_ticket_ext_cb &&
!s->tls_session_ticket_ext_cb(s, data, size,
s->tls_session_ticket_ext_cb_arg))
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
if (!tls_use_ticket(s) || (size > 0)) {
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
s->tlsext_ticket_expected = 1;
} else if (type == TLSEXT_TYPE_status_request) {
if ((s->tlsext_status_type == -1) || (size > 0)) {
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
s->tlsext_status_expected = 1;
}
#ifndef OPENSSL_NO_CT
else if (type == TLSEXT_TYPE_signed_certificate_timestamp &&
s->ct_validation_callback != NULL) {
if (s->tlsext_scts != NULL) {
OPENSSL_free(s->tlsext_scts);
s->tlsext_scts = NULL;
}
s->tlsext_scts_len = size;
if (size > 0) {
s->tlsext_scts = OPENSSL_malloc(size);
if (s->tlsext_scts == NULL) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
memcpy(s->tlsext_scts, data, size);
}
}
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
else if (type == TLSEXT_TYPE_next_proto_neg &&
s->s3->tmp.finish_md_len == 0) {
unsigned char *selected;
unsigned char selected_len;
if (s->ctx->next_proto_select_cb == NULL) {
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
if (!ssl_next_proto_validate(&spkt)) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
if (s->ctx->next_proto_select_cb(s, &selected, &selected_len, data,
size,
s->
ctx->next_proto_select_cb_arg) !=
SSL_TLSEXT_ERR_OK) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
s->next_proto_negotiated = OPENSSL_malloc(selected_len);
if (s->next_proto_negotiated == NULL) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
memcpy(s->next_proto_negotiated, selected, selected_len);
s->next_proto_negotiated_len = selected_len;
s->s3->next_proto_neg_seen = 1;
}
#endif
else if (type == TLSEXT_TYPE_application_layer_protocol_negotiation) {
unsigned len;
if (!s->s3->alpn_sent) {
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
if (!PACKET_get_net_2(&spkt, &len)
|| PACKET_remaining(&spkt) != len || !PACKET_get_1(&spkt, &len)
|| PACKET_remaining(&spkt) != len) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
OPENSSL_free(s->s3->alpn_selected);
s->s3->alpn_selected = OPENSSL_malloc(len);
if (s->s3->alpn_selected == NULL) {
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
if (!PACKET_copy_bytes(&spkt, s->s3->alpn_selected, len)) {
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
s->s3->alpn_selected_len = len;
}
#ifndef OPENSSL_NO_HEARTBEATS
else if (SSL_IS_DTLS(s) && type == TLSEXT_TYPE_heartbeat) {
unsigned int hbtype;
if (!PACKET_get_1(&spkt, &hbtype)) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
switch (hbtype) {
case 0x01:
s->tlsext_heartbeat |= SSL_DTLSEXT_HB_ENABLED;
break;
case 0x02:
s->tlsext_heartbeat |= SSL_DTLSEXT_HB_ENABLED;
s->tlsext_heartbeat |= SSL_DTLSEXT_HB_DONT_SEND_REQUESTS;
break;
default:
*al = SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
}
#endif
#ifndef OPENSSL_NO_SRTP
else if (SSL_IS_DTLS(s) && type == TLSEXT_TYPE_use_srtp) {
if (ssl_parse_serverhello_use_srtp_ext(s, &spkt, al))
return 0;
}
#endif
else if (type == TLSEXT_TYPE_encrypt_then_mac) {
if (s->s3->tmp.new_cipher->algorithm_mac != SSL_AEAD
&& s->s3->tmp.new_cipher->algorithm_enc != SSL_RC4)
s->s3->flags |= TLS1_FLAGS_ENCRYPT_THEN_MAC;
} else if (type == TLSEXT_TYPE_extended_master_secret) {
s->s3->flags |= TLS1_FLAGS_RECEIVED_EXTMS;
if (!s->hit)
s->session->flags |= SSL_SESS_FLAG_EXTMS;
}
else if (custom_ext_parse(s, 0, type, data, size, al) <= 0)
return 0;
}
if (PACKET_remaining(pkt) != 0) {
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (!s->hit && tlsext_servername == 1) {
if (s->tlsext_hostname) {
if (s->session->tlsext_hostname == NULL) {
s->session->tlsext_hostname =
OPENSSL_strdup(s->tlsext_hostname);
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
ri_check:
if (!renegotiate_seen && !(s->options & SSL_OP_LEGACY_SERVER_CONNECT)
&& !(s->options & SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION)) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_SSL_SCAN_SERVERHELLO_TLSEXT,
SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED);
return 0;
}
if (s->hit) {
if (!(s->s3->flags & TLS1_FLAGS_RECEIVED_EXTMS) !=
!(s->session->flags & SSL_SESS_FLAG_EXTMS)) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_SSL_SCAN_SERVERHELLO_TLSEXT, SSL_R_INCONSISTENT_EXTMS);
return 0;
}
}
return 1;
}
int ssl_prepare_clienthello_tlsext(SSL *s)
{
s->s3->alpn_sent = 0;
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
#ifndef OPENSSL_NO_EC
#endif
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
void ssl_set_default_md(SSL *s)
{
const EVP_MD **pmd = s->s3->tmp.md;
#ifndef OPENSSL_NO_DSA
pmd[SSL_PKEY_DSA_SIGN] = ssl_md(SSL_MD_SHA1_IDX);
#endif
#ifndef OPENSSL_NO_RSA
if (SSL_USE_SIGALGS(s))
pmd[SSL_PKEY_RSA_SIGN] = ssl_md(SSL_MD_SHA1_IDX);
else
pmd[SSL_PKEY_RSA_SIGN] = ssl_md(SSL_MD_MD5_SHA1_IDX);
pmd[SSL_PKEY_RSA_ENC] = pmd[SSL_PKEY_RSA_SIGN];
#endif
#ifndef OPENSSL_NO_EC
pmd[SSL_PKEY_ECC] = ssl_md(SSL_MD_SHA1_IDX);
#endif
#ifndef OPENSSL_NO_GOST
pmd[SSL_PKEY_GOST01] = ssl_md(SSL_MD_GOST94_IDX);
pmd[SSL_PKEY_GOST12_256] = ssl_md(SSL_MD_GOST12_256_IDX);
pmd[SSL_PKEY_GOST12_512] = ssl_md(SSL_MD_GOST12_512_IDX);
#endif
}
int tls1_set_server_sigalgs(SSL *s)
{
int al;
size_t i;
OPENSSL_free(s->cert->shared_sigalgs);
s->cert->shared_sigalgs = NULL;
s->cert->shared_sigalgslen = 0;
for (i = 0; i < SSL_PKEY_NUM; i++) {
s->s3->tmp.md[i] = NULL;
s->s3->tmp.valid_flags[i] = 0;
}
if (s->s3->tmp.peer_sigalgs) {
if (!tls1_process_sigalgs(s)) {
SSLerr(SSL_F_TLS1_SET_SERVER_SIGALGS, ERR_R_MALLOC_FAILURE);
al = SSL_AD_INTERNAL_ERROR;
goto err;
}
if (!s->cert->shared_sigalgs) {
SSLerr(SSL_F_TLS1_SET_SERVER_SIGALGS,
SSL_R_NO_SHARED_SIGNATURE_ALGORITHMS);
al = SSL_AD_ILLEGAL_PARAMETER;
goto err;
}
} else {
ssl_set_default_md(s);
}
return 1;
err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return 0;
}
int ssl_check_clienthello_tlsext_late(SSL *s, int *al)
{
s->tlsext_status_expected = 0;
if ((s->tlsext_status_type != -1) && s->ctx && s->ctx->tlsext_status_cb) {
int ret;
CERT_PKEY *certpkey;
certpkey = ssl_get_server_send_pkey(s);
if (certpkey != NULL) {
s->cert->key = certpkey;
ret = s->ctx->tlsext_status_cb(s, s->ctx->tlsext_status_arg);
switch (ret) {
case SSL_TLSEXT_ERR_NOACK:
s->tlsext_status_expected = 0;
break;
case SSL_TLSEXT_ERR_OK:
if (s->tlsext_ocsp_resp)
s->tlsext_status_expected = 1;
break;
case SSL_TLSEXT_ERR_ALERT_FATAL:
default:
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
}
}
if (!tls1_alpn_handle_client_hello_late(s, al)) {
return 0;
}
return 1;
}
int ssl_check_serverhello_tlsext(SSL *s)
{
int ret = SSL_TLSEXT_ERR_NOACK;
int al = SSL_AD_UNRECOGNIZED_NAME;
#ifndef OPENSSL_NO_EC
unsigned long alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
unsigned long alg_a = s->s3->tmp.new_cipher->algorithm_auth;
if ((s->tlsext_ecpointformatlist != NULL)
&& (s->tlsext_ecpointformatlist_length > 0)
&& (s->session->tlsext_ecpointformatlist != NULL)
&& (s->session->tlsext_ecpointformatlist_length > 0)
&& ((alg_k & SSL_kECDHE) || (alg_a & SSL_aECDSA))) {
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
#endif
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
OPENSSL_free(s->tlsext_ocsp_resp);
s->tlsext_ocsp_resp = NULL;
s->tlsext_ocsp_resplen = -1;
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
int ssl_parse_serverhello_tlsext(SSL *s, PACKET *pkt)
{
int al = -1;
if (s->version < SSL3_VERSION)
return 1;
if (ssl_scan_serverhello_tlsext(s, pkt, &al) <= 0) {
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return 0;
}
if (ssl_check_serverhello_tlsext(s) <= 0) {
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_TLSEXT, SSL_R_SERVERHELLO_TLSEXT);
return 0;
}
return 1;
}
int tls_check_serverhello_tlsext_early(SSL *s, const PACKET *ext,
const PACKET *session_id,
SSL_SESSION **ret)
{
unsigned int i;
PACKET local_ext = *ext;
int retv = -1;
int have_ticket = 0;
int use_ticket = tls_use_ticket(s);
*ret = NULL;
s->tlsext_ticket_expected = 0;
s->s3->flags &= ~TLS1_FLAGS_RECEIVED_EXTMS;
if ((s->version <= SSL3_VERSION))
return 0;
if (!PACKET_get_net_2(&local_ext, &i)) {
retv = 0;
goto end;
}
while (PACKET_remaining(&local_ext) >= 4) {
unsigned int type, size;
if (!PACKET_get_net_2(&local_ext, &type)
|| !PACKET_get_net_2(&local_ext, &size)) {
retv = -1;
goto end;
}
if (PACKET_remaining(&local_ext) < size) {
retv = 0;
goto end;
}
if (type == TLSEXT_TYPE_session_ticket && use_ticket) {
int r;
const unsigned char *etick;
if (have_ticket != 0) {
retv = -1;
goto end;
}
have_ticket = 1;
if (size == 0) {
s->tlsext_ticket_expected = 1;
retv = 1;
continue;
}
if (s->tls_session_secret_cb) {
retv = 2;
continue;
}
if (!PACKET_get_bytes(&local_ext, &etick, size)) {
retv = -1;
goto end;
}
r = tls_decrypt_ticket(s, etick, size, PACKET_data(session_id),
PACKET_remaining(session_id), ret);
switch (r) {
case 2:
s->tlsext_ticket_expected = 1;
retv = 2;
break;
case 3:
retv = r;
break;
case 4:
s->tlsext_ticket_expected = 1;
retv = 3;
break;
default:
retv = -1;
break;
}
continue;
} else {
if (type == TLSEXT_TYPE_extended_master_secret)
s->s3->flags |= TLS1_FLAGS_RECEIVED_EXTMS;
if (!PACKET_forward(&local_ext, size)) {
retv = -1;
goto end;
}
}
}
if (have_ticket == 0)
retv = 0;
end:
return retv;
}
static int tls_decrypt_ticket(SSL *s, const unsigned char *etick,
int eticklen, const unsigned char *sess_id,
int sesslen, SSL_SESSION **psess)
{
SSL_SESSION *sess;
unsigned char *sdec;
const unsigned char *p;
int slen, mlen, renew_ticket = 0, ret = -1;
unsigned char tick_hmac[EVP_MAX_MD_SIZE];
HMAC_CTX *hctx = NULL;
EVP_CIPHER_CTX *ctx;
SSL_CTX *tctx = s->initial_ctx;
hctx = HMAC_CTX_new();
if (hctx == NULL)
return -2;
ctx = EVP_CIPHER_CTX_new();
if (ctx == NULL) {
ret = -2;
goto err;
}
if (tctx->tlsext_ticket_key_cb) {
unsigned char *nctick = (unsigned char *)etick;
int rv = tctx->tlsext_ticket_key_cb(s, nctick, nctick + 16,
ctx, hctx, 0);
if (rv < 0)
goto err;
if (rv == 0) {
ret = 2;
goto err;
}
if (rv == 2)
renew_ticket = 1;
} else {
if (memcmp(etick, tctx->tlsext_tick_key_name,
sizeof(tctx->tlsext_tick_key_name)) != 0) {
ret = 2;
goto err;
}
if (HMAC_Init_ex(hctx, tctx->tlsext_tick_hmac_key,
sizeof(tctx->tlsext_tick_hmac_key),
EVP_sha256(), NULL) <= 0
|| EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL,
tctx->tlsext_tick_aes_key,
etick + sizeof(tctx->tlsext_tick_key_name)) <=
0) {
goto err;
}
}
mlen = HMAC_size(hctx);
if (mlen < 0) {
goto err;
}
if (eticklen <=
TLSEXT_KEYNAME_LENGTH + EVP_CIPHER_CTX_iv_length(ctx) + mlen) {
ret = 2;
goto err;
}
eticklen -= mlen;
if (HMAC_Update(hctx, etick, eticklen) <= 0
|| HMAC_Final(hctx, tick_hmac, NULL) <= 0) {
goto err;
}
HMAC_CTX_free(hctx);
if (CRYPTO_memcmp(tick_hmac, etick + eticklen, mlen)) {
EVP_CIPHER_CTX_free(ctx);
return 2;
}
p = etick + 16 + EVP_CIPHER_CTX_iv_length(ctx);
eticklen -= 16 + EVP_CIPHER_CTX_iv_length(ctx);
sdec = OPENSSL_malloc(eticklen);
if (sdec == NULL || EVP_DecryptUpdate(ctx, sdec, &slen, p, eticklen) <= 0) {
EVP_CIPHER_CTX_free(ctx);
OPENSSL_free(sdec);
return -1;
}
if (EVP_DecryptFinal(ctx, sdec + slen, &mlen) <= 0) {
EVP_CIPHER_CTX_free(ctx);
OPENSSL_free(sdec);
return 2;
}
slen += mlen;
EVP_CIPHER_CTX_free(ctx);
ctx = NULL;
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
err:
EVP_CIPHER_CTX_free(ctx);
HMAC_CTX_free(hctx);
return ret;
}
static int tls12_find_id(int nid, const tls12_lookup *table, size_t tlen)
{
size_t i;
for (i = 0; i < tlen; i++) {
if (table[i].nid == nid)
return table[i].id;
}
return -1;
}
static int tls12_find_nid(int id, const tls12_lookup *table, size_t tlen)
{
size_t i;
for (i = 0; i < tlen; i++) {
if ((table[i].id) == id)
return table[i].nid;
}
return NID_undef;
}
int tls12_get_sigandhash(unsigned char *p, const EVP_PKEY *pk, const EVP_MD *md)
{
int sig_id, md_id;
if (!md)
return 0;
md_id = tls12_find_id(EVP_MD_type(md), tls12_md, OSSL_NELEM(tls12_md));
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
return tls12_find_id(EVP_PKEY_id(pk), tls12_sig, OSSL_NELEM(tls12_sig));
}
static const tls12_hash_info *tls12_get_hash_info(unsigned char hash_alg)
{
unsigned int i;
if (hash_alg == 0)
return NULL;
for (i = 0; i < OSSL_NELEM(tls12_md_info); i++) {
if (tls12_md_info[i].tlsext_hash == hash_alg)
return tls12_md_info + i;
}
return NULL;
}
const EVP_MD *tls12_get_hash(unsigned char hash_alg)
{
const tls12_hash_info *inf;
if (hash_alg == TLSEXT_hash_md5 && FIPS_mode())
return NULL;
inf = tls12_get_hash_info(hash_alg);
if (!inf)
return NULL;
return ssl_md(inf->md_idx);
}
static int tls12_get_pkey_idx(unsigned char sig_alg)
{
switch (sig_alg) {
#ifndef OPENSSL_NO_RSA
case TLSEXT_signature_rsa:
return SSL_PKEY_RSA_SIGN;
#endif
#ifndef OPENSSL_NO_DSA
case TLSEXT_signature_dsa:
return SSL_PKEY_DSA_SIGN;
#endif
#ifndef OPENSSL_NO_EC
case TLSEXT_signature_ecdsa:
return SSL_PKEY_ECC;
#endif
#ifndef OPENSSL_NO_GOST
case TLSEXT_signature_gostr34102001:
return SSL_PKEY_GOST01;
case TLSEXT_signature_gostr34102012_256:
return SSL_PKEY_GOST12_256;
case TLSEXT_signature_gostr34102012_512:
return SSL_PKEY_GOST12_512;
#endif
}
return -1;
}
static void tls1_lookup_sigalg(int *phash_nid, int *psign_nid,
int *psignhash_nid, const unsigned char *data)
{
int sign_nid = NID_undef, hash_nid = NID_undef;
if (!phash_nid && !psign_nid && !psignhash_nid)
return;
if (phash_nid || psignhash_nid) {
hash_nid = tls12_find_nid(data[0], tls12_md, OSSL_NELEM(tls12_md));
if (phash_nid)
*phash_nid = hash_nid;
}
if (psign_nid || psignhash_nid) {
sign_nid = tls12_find_nid(data[1], tls12_sig, OSSL_NELEM(tls12_sig));
if (psign_nid)
*psign_nid = sign_nid;
}
if (psignhash_nid) {
if (sign_nid == NID_undef || hash_nid == NID_undef
|| OBJ_find_sigid_by_algs(psignhash_nid, hash_nid, sign_nid) <= 0)
*psignhash_nid = NID_undef;
}
}
static int tls12_sigalg_allowed(SSL *s, int op, const unsigned char *ptmp)
{
const tls12_hash_info *hinf = tls12_get_hash_info(ptmp[0]);
if (hinf == NULL || ssl_md(hinf->md_idx) == NULL)
return 0;
if (tls12_get_pkey_idx(ptmp[1]) == -1)
return 0;
return ssl_security(s, op, hinf->secbits, hinf->nid, (void *)ptmp);
}
void ssl_set_sig_mask(uint32_t *pmask_a, SSL *s, int op)
{
const unsigned char *sigalgs;
size_t i, sigalgslen;
int have_rsa = 0, have_dsa = 0, have_ecdsa = 0;
sigalgslen = tls12_get_psigalgs(s, &sigalgs);
for (i = 0; i < sigalgslen; i += 2, sigalgs += 2) {
switch (sigalgs[1]) {
#ifndef OPENSSL_NO_RSA
case TLSEXT_signature_rsa:
if (!have_rsa && tls12_sigalg_allowed(s, op, sigalgs))
have_rsa = 1;
break;
#endif
#ifndef OPENSSL_NO_DSA
case TLSEXT_signature_dsa:
if (!have_dsa && tls12_sigalg_allowed(s, op, sigalgs))
have_dsa = 1;
break;
#endif
#ifndef OPENSSL_NO_EC
case TLSEXT_signature_ecdsa:
if (!have_ecdsa && tls12_sigalg_allowed(s, op, sigalgs))
have_ecdsa = 1;
break;
#endif
}
}
if (!have_rsa)
*pmask_a |= SSL_aRSA;
if (!have_dsa)
*pmask_a |= SSL_aDSS;
if (!have_ecdsa)
*pmask_a |= SSL_aECDSA;
}
size_t tls12_copy_sigalgs(SSL *s, unsigned char *out,
const unsigned char *psig, size_t psiglen)
{
unsigned char *tmpout = out;
size_t i;
for (i = 0; i < psiglen; i += 2, psig += 2) {
if (tls12_sigalg_allowed(s, SSL_SECOP_SIGALG_SUPPORTED, psig)) {
*tmpout++ = psig[0];
*tmpout++ = psig[1];
}
}
return tmpout - out;
}
static int tls12_shared_sigalgs(SSL *s, TLS_SIGALGS *shsig,
const unsigned char *pref, size_t preflen,
const unsigned char *allow, size_t allowlen)
{
const unsigned char *ptmp, *atmp;
size_t i, j, nmatch = 0;
for (i = 0, ptmp = pref; i < preflen; i += 2, ptmp += 2) {
if (!tls12_sigalg_allowed(s, SSL_SECOP_SIGALG_SHARED, ptmp))
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
OPENSSL_free(c->shared_sigalgs);
c->shared_sigalgs = NULL;
c->shared_sigalgslen = 0;
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
allow = s->s3->tmp.peer_sigalgs;
allowlen = s->s3->tmp.peer_sigalgslen;
} else {
allow = conf;
allowlen = conflen;
pref = s->s3->tmp.peer_sigalgs;
preflen = s->s3->tmp.peer_sigalgslen;
}
nmatch = tls12_shared_sigalgs(s, NULL, pref, preflen, allow, allowlen);
if (nmatch) {
salgs = OPENSSL_malloc(nmatch * sizeof(TLS_SIGALGS));
if (salgs == NULL)
return 0;
nmatch = tls12_shared_sigalgs(s, salgs, pref, preflen, allow, allowlen);
} else {
salgs = NULL;
}
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
OPENSSL_free(s->s3->tmp.peer_sigalgs);
s->s3->tmp.peer_sigalgs = OPENSSL_malloc(dsize);
if (s->s3->tmp.peer_sigalgs == NULL)
return 0;
s->s3->tmp.peer_sigalgslen = dsize;
memcpy(s->s3->tmp.peer_sigalgs, data, dsize);
return 1;
}
int tls1_process_sigalgs(SSL *s)
{
int idx;
size_t i;
const EVP_MD *md;
const EVP_MD **pmd = s->s3->tmp.md;
uint32_t *pvalid = s->s3->tmp.valid_flags;
CERT *c = s->cert;
TLS_SIGALGS *sigptr;
if (!tls1_set_shared_sigalgs(s))
return 0;
for (i = 0, sigptr = c->shared_sigalgs;
i < c->shared_sigalgslen; i++, sigptr++) {
idx = tls12_get_pkey_idx(sigptr->rsign);
if (idx > 0 && pmd[idx] == NULL) {
md = tls12_get_hash(sigptr->rhash);
pmd[idx] = md;
pvalid[idx] = CERT_PKEY_EXPLICIT_SIGN;
if (idx == SSL_PKEY_RSA_SIGN) {
pvalid[SSL_PKEY_RSA_ENC] = CERT_PKEY_EXPLICIT_SIGN;
pmd[SSL_PKEY_RSA_ENC] = md;
}
}
}
if (!(s->cert->cert_flags & SSL_CERT_FLAGS_CHECK_TLS_STRICT)) {
#ifndef OPENSSL_NO_DSA
if (pmd[SSL_PKEY_DSA_SIGN] == NULL)
pmd[SSL_PKEY_DSA_SIGN] = EVP_sha1();
#endif
#ifndef OPENSSL_NO_RSA
if (pmd[SSL_PKEY_RSA_SIGN] == NULL) {
pmd[SSL_PKEY_RSA_SIGN] = EVP_sha1();
pmd[SSL_PKEY_RSA_ENC] = EVP_sha1();
}
#endif
#ifndef OPENSSL_NO_EC
if (pmd[SSL_PKEY_ECC] == NULL)
pmd[SSL_PKEY_ECC] = EVP_sha1();
#endif
#ifndef OPENSSL_NO_GOST
if (pmd[SSL_PKEY_GOST01] == NULL)
pmd[SSL_PKEY_GOST01] = EVP_get_digestbynid(NID_id_GostR3411_94);
if (pmd[SSL_PKEY_GOST12_256] == NULL)
pmd[SSL_PKEY_GOST12_256] =
EVP_get_digestbynid(NID_id_GostR3411_2012_256);
if (pmd[SSL_PKEY_GOST12_512] == NULL)
pmd[SSL_PKEY_GOST12_512] =
EVP_get_digestbynid(NID_id_GostR3411_2012_512);
#endif
}
return 1;
}
int SSL_get_sigalgs(SSL *s, int idx,
int *psign, int *phash, int *psignhash,
unsigned char *rsig, unsigned char *rhash)
{
const unsigned char *psig = s->s3->tmp.peer_sigalgs;
if (psig == NULL)
return 0;
if (idx >= 0) {
idx <<= 1;
if (idx >= (int)s->s3->tmp.peer_sigalgslen)
return 0;
psig += idx;
if (rhash)
*rhash = psig[0];
if (rsig)
*rsig = psig[1];
tls1_lookup_sigalg(phash, psign, psignhash, psig);
}
return s->s3->tmp.peer_sigalgslen / 2;
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
static void get_sigorhash(int *psig, int *phash, const char *str)
{
if (strcmp(str, "RSA") == 0) {
*psig = EVP_PKEY_RSA;
} else if (strcmp(str, "DSA") == 0) {
*psig = EVP_PKEY_DSA;
} else if (strcmp(str, "ECDSA") == 0) {
*psig = EVP_PKEY_EC;
} else {
*phash = OBJ_sn2nid(str);
if (*phash == NID_undef)
*phash = OBJ_ln2nid(str);
}
}
static int sig_cb(const char *elem, int len, void *arg)
{
sig_cb_st *sarg = arg;
size_t i;
char etmp[20], *p;
int sig_alg = NID_undef, hash_alg = NID_undef;
if (elem == NULL)
return 0;
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
get_sigorhash(&sig_alg, &hash_alg, etmp);
get_sigorhash(&sig_alg, &hash_alg, p);
if (sig_alg == NID_undef || hash_alg == NID_undef)
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
int tls1_set_sigalgs(CERT *c, const int *psig_nids, size_t salglen, int client)
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
rhash = tls12_find_id(*psig_nids++, tls12_md, OSSL_NELEM(tls12_md));
rsign = tls12_find_id(*psig_nids++, tls12_sig, OSSL_NELEM(tls12_sig));
if (rhash == -1 || rsign == -1)
goto err;
*sptr++ = rhash;
*sptr++ = rsign;
}
if (client) {
OPENSSL_free(c->client_sigalgs);
c->client_sigalgs = sigalgs;
c->client_sigalgslen = salglen;
} else {
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
tls1_check_chain(s, NULL, NULL, NULL, SSL_PKEY_ECC);
tls1_check_chain(s, NULL, NULL, NULL, SSL_PKEY_GOST01);
tls1_check_chain(s, NULL, NULL, NULL, SSL_PKEY_GOST12_256);
tls1_check_chain(s, NULL, NULL, NULL, SSL_PKEY_GOST12_512);
}
DH *ssl_get_auto_dh(SSL *s)
{
int dh_secbits = 80;
if (s->cert->dh_tmp_auto == 2)
return DH_get_1024_160();
if (s->s3->tmp.new_cipher->algorithm_auth & (SSL_aNULL | SSL_aPSK)) {
if (s->s3->tmp.new_cipher->strength_bits == 256)
dh_secbits = 128;
else
dh_secbits = 80;
} else {
CERT_PKEY *cpk = ssl_get_server_send_pkey(s);
dh_secbits = EVP_PKEY_security_bits(cpk->privatekey);
}
if (dh_secbits >= 128) {
DH *dhp = DH_new();
BIGNUM *p, *g;
if (dhp == NULL)
return NULL;
g = BN_new();
if (g != NULL)
BN_set_word(g, 2);
if (dh_secbits >= 192)
p = BN_get_rfc3526_prime_8192(NULL);
else
p = BN_get_rfc3526_prime_3072(NULL);
if (p == NULL || g == NULL || !DH_set0_pqg(dhp, p, NULL, g)) {
DH_free(dhp);
BN_free(p);
BN_free(g);
return NULL;
}
return dhp;
}
if (dh_secbits >= 112)
return DH_get_2048_224();
return DH_get_1024_160();
}
static int ssl_security_cert_key(SSL *s, SSL_CTX *ctx, X509 *x, int op)
{
int secbits = -1;
EVP_PKEY *pkey = X509_get0_pubkey(x);
if (pkey) {
secbits = EVP_PKEY_security_bits(pkey);
}
if (s)
return ssl_security(s, op, secbits, 0, x);
else
return ssl_ctx_security(ctx, op, secbits, 0, x);
}
static int ssl_security_cert_sig(SSL *s, SSL_CTX *ctx, X509 *x, int op)
{
int secbits = -1, md_nid = NID_undef, sig_nid;
if ((X509_get_extension_flags(x) & EXFLAG_SS) != 0)
return 1;
sig_nid = X509_get_signature_nid(x);
if (sig_nid && OBJ_find_sigid_algs(sig_nid, &md_nid, NULL)) {
const EVP_MD *md;
if (md_nid && (md = EVP_get_digestbynid(md_nid)))
secbits = EVP_MD_size(md) * 4;
}
if (s)
return ssl_security(s, op, secbits, md_nid, x);
else
return ssl_ctx_security(ctx, op, secbits, md_nid, x);
}
int ssl_security_cert(SSL *s, SSL_CTX *ctx, X509 *x, int vfy, int is_ee)
{
if (vfy)
vfy = SSL_SECOP_PEER;
if (is_ee) {
if (!ssl_security_cert_key(s, ctx, x, SSL_SECOP_EE_KEY | vfy))
return SSL_R_EE_KEY_TOO_SMALL;
} else {
if (!ssl_security_cert_key(s, ctx, x, SSL_SECOP_CA_KEY | vfy))
return SSL_R_CA_KEY_TOO_SMALL;
}
if (!ssl_security_cert_sig(s, ctx, x, SSL_SECOP_CA_MD | vfy))
return SSL_R_CA_MD_TOO_WEAK;
return 1;
}
