static inline void esrever ( unsigned char *d, int l )
{
for(;--l>0;--l,d++){*d^=*(d+l);*(d+l)^=*d;*d^=*(d+l);}
}
static inline void ypcmem ( unsigned char *d, const unsigned char *s, int l )
{
for(d+=l;l--;)*--d=*s++;
}
static __inline void esrever ( unsigned char *d, int l )
{
for(;--l>0;--l,d++){*d^=*(d+l);*(d+l)^=*d;*d^=*(d+l);}
}
static __inline void ypcmem ( unsigned char *d, const unsigned char *s, int l )
{
for(d+=l;l--;)*--d=*s++;
}
static int bind_helper ( ENGINE *e )
{
#ifndef OPENSSL_NO_RSA
const RSA_METHOD *meth_rsa ;
#endif
#ifndef OPENSSL_NO_DSA
const DSA_METHOD *meth_dsa ;
#endif
#ifndef OPENSSL_NO_DH
const DH_METHOD *meth_dh ;
#endif
const RAND_METHOD *meth_rand ;
if ( !ENGINE_set_id ( e, engine_zencod_id ) ||
!ENGINE_set_name ( e, engine_zencod_name ) ||
#ifndef OPENSSL_NO_RSA
!ENGINE_set_RSA ( e, &zencod_rsa ) ||
#endif
#ifndef OPENSSL_NO_DSA
!ENGINE_set_DSA ( e, &zencod_dsa ) ||
#endif
#ifndef OPENSSL_NO_DH
!ENGINE_set_DH ( e, &zencod_dh ) ||
#endif
!ENGINE_set_RAND ( e, &zencod_rand ) ||
!ENGINE_set_destroy_function ( e, zencod_destroy ) ||
!ENGINE_set_init_function ( e, zencod_init ) ||
!ENGINE_set_finish_function ( e, zencod_finish ) ||
!ENGINE_set_ctrl_function ( e, zencod_ctrl ) ||
!ENGINE_set_cmd_defns ( e, zencod_cmd_defns ) ||
!ENGINE_set_digests ( e, engine_digests ) ||
!ENGINE_set_ciphers ( e, engine_ciphers ) ) {
return 0 ;
}
#ifndef OPENSSL_NO_RSA
meth_rsa = RSA_PKCS1_SSLeay () ;
zencod_rsa.rsa_pub_enc = meth_rsa->rsa_pub_enc ;
zencod_rsa.rsa_pub_dec = meth_rsa->rsa_pub_dec ;
zencod_rsa.rsa_priv_enc = meth_rsa->rsa_priv_enc ;
zencod_rsa.rsa_priv_dec = meth_rsa->rsa_priv_dec ;
zencod_rsa.init = meth_rsa->init ;
zencod_rsa.finish = meth_rsa->finish ;
#endif
#ifndef OPENSSL_NO_DSA
meth_dsa = DSA_OpenSSL () ;
zencod_dsa.dsa_sign_setup = meth_dsa->dsa_sign_setup ;
zencod_dsa.dsa_mod_exp = meth_dsa->dsa_mod_exp ;
zencod_dsa.init = meth_dsa->init ;
zencod_dsa.finish = meth_dsa->finish ;
#endif
#ifndef OPENSSL_NO_DH
meth_dh = DH_OpenSSL () ;
zencod_dh.init = meth_dh->init ;
zencod_dh.finish = meth_dh->finish ;
#endif
meth_rand = RAND_SSLeay () ;
zencod_rand.cleanup = meth_rand->cleanup ;
zencod_rand.add = meth_rand->add ;
ERR_load_ZENCOD_strings () ;
return 1 ;
}
static ENGINE *ENGINE_zencod ( void )
{
ENGINE *eng = ENGINE_new () ;
if ( !eng ) {
return NULL ;
}
if ( !bind_helper ( eng ) ) {
ENGINE_free ( eng ) ;
return NULL ;
}
return eng ;
}
static
#endif
void ENGINE_load_zencod ( void )
{
ENGINE *toadd = ENGINE_zencod ( ) ;
if ( !toadd ) return ;
ENGINE_add ( toadd ) ;
ENGINE_free ( toadd ) ;
ERR_clear_error ( ) ;
}
static int zencod_destroy (ENGINE *e )
{
ERR_unload_ZENCOD_strings () ;
return 1 ;
}
static int zencod_init ( ENGINE *e )
{
t_zencod_test *ptr_0 ;
t_zencod_bytes2bits *ptr_1 ;
t_zencod_bits2bytes *ptr_2 ;
t_zencod_new_number *ptr_3 ;
t_zencod_init_number *ptr_4 ;
t_zencod_rsa_mod_exp *ptr_exp_1 ;
t_zencod_rsa_mod_exp_crt *ptr_exp_2 ;
t_zencod_dsa_do_sign *ptr_dsa_1 ;
t_zencod_dsa_do_verify *ptr_dsa_2 ;
t_zencod_dh_generate_key *ptr_dh_1 ;
t_zencod_dh_compute_key *ptr_dh_2 ;
t_zencod_rand_bytes *ptr_rand_1 ;
t_zencod_math_mod_exp *ptr_math_1 ;
t_zencod_md5_init *ptr_md5_1 ;
t_zencod_md5_update *ptr_md5_2 ;
t_zencod_md5_do_final *ptr_md5_3 ;
t_zencod_sha1_init *ptr_sha1_1 ;
t_zencod_sha1_update *ptr_sha1_2 ;
t_zencod_sha1_do_final *ptr_sha1_3 ;
t_zencod_xdes_cipher *ptr_xdes_1 ;
t_zencod_rc4_cipher *ptr_rc4_1 ;
CHEESE () ;
if ( zencod_dso != NULL ) {
ZENCODerr ( ZENCOD_F_ZENCOD_INIT, ZENCOD_R_ALREADY_LOADED ) ;
goto err ;
}
zencod_dso = DSO_load ( NULL, ZENCOD_LIBNAME, NULL, 0 ) ;
if ( zencod_dso == NULL ) {
ZENCODerr ( ZENCOD_F_ZENCOD_INIT, ZENCOD_R_DSO_FAILURE ) ;
goto err ;
}
if ( ! ( ptr_1 = (t_zencod_bytes2bits*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_1 ) ) ||
! ( ptr_2 = (t_zencod_bits2bytes*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_2 ) ) ||
! ( ptr_3 = (t_zencod_new_number*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_3 ) ) ||
! ( ptr_4 = (t_zencod_init_number*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_4 ) ) ||
! ( ptr_exp_1 = (t_zencod_rsa_mod_exp*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_exp_1 ) ) ||
! ( ptr_exp_2 = (t_zencod_rsa_mod_exp_crt*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_exp_2 ) ) ||
! ( ptr_dsa_1 = (t_zencod_dsa_do_sign*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_dsa_1 ) ) ||
! ( ptr_dsa_2 = (t_zencod_dsa_do_verify*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_dsa_2 ) ) ||
! ( ptr_dh_1 = (t_zencod_dh_generate_key*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_dh_1 ) ) ||
! ( ptr_dh_2 = (t_zencod_dh_compute_key*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_dh_2 ) ) ||
! ( ptr_rand_1 = (t_zencod_rand_bytes*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_rand_1 ) ) ||
! ( ptr_math_1 = (t_zencod_math_mod_exp*) DSO_bind_func ( zencod_dso, ZENCOD_Fct_math_1 ) ) ||
! ( ptr_0 = (t_zencod_test *) DSO_bind_func ( zencod_dso, ZENCOD_Fct_0 ) ) ||
! ( ptr_md5_1 = (t_zencod_md5_init *) DSO_bind_func ( zencod_dso, ZENCOD_Fct_md5_1 ) ) ||
! ( ptr_md5_2 = (t_zencod_md5_update *) DSO_bind_func ( zencod_dso, ZENCOD_Fct_md5_2 ) ) ||
! ( ptr_md5_3 = (t_zencod_md5_do_final *) DSO_bind_func ( zencod_dso, ZENCOD_Fct_md5_3 ) ) ||
! ( ptr_sha1_1 = (t_zencod_sha1_init *) DSO_bind_func ( zencod_dso, ZENCOD_Fct_sha1_1 ) ) ||
! ( ptr_sha1_2 = (t_zencod_sha1_update *) DSO_bind_func ( zencod_dso, ZENCOD_Fct_sha1_2 ) ) ||
! ( ptr_sha1_3 = (t_zencod_sha1_do_final *) DSO_bind_func ( zencod_dso, ZENCOD_Fct_sha1_3 ) ) ||
! ( ptr_xdes_1 = (t_zencod_xdes_cipher *) DSO_bind_func ( zencod_dso, ZENCOD_Fct_xdes_1 ) ) ||
! ( ptr_rc4_1 = (t_zencod_rc4_cipher *) DSO_bind_func ( zencod_dso, ZENCOD_Fct_rc4_1 ) ) ) {
ZENCODerr ( ZENCOD_F_ZENCOD_INIT, ZENCOD_R_DSO_FAILURE ) ;
goto err ;
}
ptr_zencod_test = ptr_0 ;
ptr_zencod_bytes2bits = ptr_1 ;
ptr_zencod_bits2bytes = ptr_2 ;
ptr_zencod_new_number = ptr_3 ;
ptr_zencod_init_number = ptr_4 ;
ptr_zencod_rsa_mod_exp = ptr_exp_1 ;
ptr_zencod_rsa_mod_exp_crt = ptr_exp_2 ;
ptr_zencod_dsa_do_sign = ptr_dsa_1 ;
ptr_zencod_dsa_do_verify = ptr_dsa_2 ;
ptr_zencod_dh_generate_key = ptr_dh_1 ;
ptr_zencod_dh_compute_key = ptr_dh_2 ;
ptr_zencod_rand_bytes = ptr_rand_1 ;
ptr_zencod_math_mod_exp = ptr_math_1 ;
ptr_zencod_test = ptr_0 ;
ptr_zencod_md5_init = ptr_md5_1 ;
ptr_zencod_md5_update = ptr_md5_2 ;
ptr_zencod_md5_do_final = ptr_md5_3 ;
ptr_zencod_sha1_init = ptr_sha1_1 ;
ptr_zencod_sha1_update = ptr_sha1_2 ;
ptr_zencod_sha1_do_final = ptr_sha1_3 ;
ptr_zencod_xdes_cipher = ptr_xdes_1 ;
ptr_zencod_rc4_cipher = ptr_rc4_1 ;
if ( ptr_zencod_test () != 0 ) {
ZENCODerr ( ZENCOD_F_ZENCOD_INIT, ZENCOD_R_UNIT_FAILURE ) ;
goto err ;
}
return 1 ;
err :
if ( zencod_dso ) {
DSO_free ( zencod_dso ) ;
}
zencod_dso = NULL ;
ptr_zencod_bytes2bits = NULL ;
ptr_zencod_bits2bytes = NULL ;
ptr_zencod_new_number = NULL ;
ptr_zencod_init_number = NULL ;
ptr_zencod_rsa_mod_exp = NULL ;
ptr_zencod_rsa_mod_exp_crt = NULL ;
ptr_zencod_dsa_do_sign = NULL ;
ptr_zencod_dsa_do_verify = NULL ;
ptr_zencod_dh_generate_key = NULL ;
ptr_zencod_dh_compute_key = NULL ;
ptr_zencod_rand_bytes = NULL ;
ptr_zencod_math_mod_exp = NULL ;
ptr_zencod_test = NULL ;
ptr_zencod_md5_init = NULL ;
ptr_zencod_md5_update = NULL ;
ptr_zencod_md5_do_final = NULL ;
ptr_zencod_sha1_init = NULL ;
ptr_zencod_sha1_update = NULL ;
ptr_zencod_sha1_do_final = NULL ;
ptr_zencod_xdes_cipher = NULL ;
ptr_zencod_rc4_cipher = NULL ;
return 0 ;
}
static int zencod_finish ( ENGINE *e )
{
CHEESE () ;
if ( zencod_dso == NULL ) {
ZENCODerr ( ZENCOD_F_ZENCOD_FINISH, ZENCOD_R_NOT_LOADED ) ;
return 0 ;
}
if ( !DSO_free ( zencod_dso ) ) {
ZENCODerr ( ZENCOD_F_ZENCOD_FINISH, ZENCOD_R_DSO_FAILURE ) ;
return 0 ;
}
zencod_dso = NULL ;
ptr_zencod_bytes2bits = NULL ;
ptr_zencod_bits2bytes = NULL ;
ptr_zencod_new_number = NULL ;
ptr_zencod_init_number = NULL ;
ptr_zencod_rsa_mod_exp = NULL ;
ptr_zencod_rsa_mod_exp_crt = NULL ;
ptr_zencod_dsa_do_sign = NULL ;
ptr_zencod_dsa_do_verify = NULL ;
ptr_zencod_dh_generate_key = NULL ;
ptr_zencod_dh_compute_key = NULL ;
ptr_zencod_rand_bytes = NULL ;
ptr_zencod_math_mod_exp = NULL ;
ptr_zencod_test = NULL ;
ptr_zencod_md5_init = NULL ;
ptr_zencod_md5_update = NULL ;
ptr_zencod_md5_do_final = NULL ;
ptr_zencod_sha1_init = NULL ;
ptr_zencod_sha1_update = NULL ;
ptr_zencod_sha1_do_final = NULL ;
ptr_zencod_xdes_cipher = NULL ;
ptr_zencod_rc4_cipher = NULL ;
return 1 ;
}
static int zencod_ctrl ( ENGINE *e, int cmd, long i, void *p, void (*f) () )
{
int initialised = ( ( zencod_dso == NULL ) ? 0 : 1 ) ;
CHEESE () ;
switch ( cmd ) {
case ZENCOD_CMD_SO_PATH :
if ( p == NULL ) {
ZENCODerr ( ZENCOD_F_ZENCOD_CTRL, ERR_R_PASSED_NULL_PARAMETER ) ;
return 0 ;
}
if ( initialised ) {
ZENCODerr ( ZENCOD_F_ZENCOD_CTRL, ZENCOD_R_ALREADY_LOADED ) ;
return 0 ;
}
ZENCOD_LIBNAME = (const char *) p ;
return 1 ;
default :
break ;
}
ZENCODerr ( ZENCOD_F_ZENCOD_CTRL, ZENCOD_R_CTRL_COMMAND_NOT_IMPLEMENTED ) ;
return 0 ;
}
static int zencod_bn_mod_exp ( BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx )
{
zen_nb_t y, x, e, n;
int ret;
CHEESE () ;
if ( !zencod_dso ) {
ENGINEerr(ZENCOD_F_ZENCOD_BN_MOD_EXP, ZENCOD_R_NOT_LOADED);
return 0;
}
if ( !bn_wexpand(r, m->top + 1) ) {
ENGINEerr(ZENCOD_F_ZENCOD_BN_MOD_EXP, ZENCOD_R_BN_EXPAND_FAIL);
return 0;
}
memset(r->d, 0, BN_num_bytes(m));
ptr_zencod_init_number ( &y, (r->dmax - 1) * sizeof (BN_ULONG) * 8, (unsigned char *) r->d ) ;
BIGNUM2ZEN ( &x, a ) ;
BIGNUM2ZEN ( &e, p ) ;
BIGNUM2ZEN ( &n, m ) ;
ret = ptr_zencod_math_mod_exp ( &y, &e, &x, &n ) ;
if ( ret ) {
PERROR("zenbridge_math_mod_exp");
ENGINEerr(ZENCOD_F_ZENCOD_BN_MOD_EXP, ZENCOD_R_REQUEST_FAILED);
return 0;
}
r->top = (BN_num_bits(m) + BN_BITS2 - 1) / BN_BITS2;
return 1;
}
static int RSA_zencod_rsa_mod_exp ( BIGNUM *r0, const BIGNUM *i, RSA *rsa )
{
CHEESE () ;
if ( !zencod_dso ) {
ENGINEerr(ZENCOD_F_ZENCOD_RSA_MOD_EXP_CRT, ZENCOD_R_NOT_LOADED);
return 0;
}
if ( !rsa->p || !rsa->q || !rsa->dmp1 || !rsa->dmq1 || !rsa->iqmp ) {
ENGINEerr(ZENCOD_F_ZENCOD_RSA_MOD_EXP_CRT, ZENCOD_R_BAD_KEY_COMPONENTS);
return 0;
}
if ( RSA_size(rsa) * 8 > ZENBRIDGE_MAX_KEYSIZE_RSA_CRT ) {
const RSA_METHOD *meth;
meth = RSA_PKCS1_SSLeay();
return meth->rsa_mod_exp(r0, i, rsa);
} else {
zen_nb_t y, x, p, q, dmp1, dmq1, iqmp;
if ( !bn_expand(r0, RSA_size(rsa) * 8) ) {
ENGINEerr(ZENCOD_F_ZENCOD_RSA_MOD_EXP_CRT, ZENCOD_R_BN_EXPAND_FAIL);
return 0;
}
r0->top = (RSA_size(rsa) * 8 + BN_BITS2 - 1) / BN_BITS2;
BIGNUM2ZEN ( &x, i ) ;
BIGNUM2ZEN ( &y, r0 ) ;
BIGNUM2ZEN ( &p, rsa->p ) ;
BIGNUM2ZEN ( &q, rsa->q ) ;
BIGNUM2ZEN ( &dmp1, rsa->dmp1 ) ;
BIGNUM2ZEN ( &dmq1, rsa->dmq1 ) ;
BIGNUM2ZEN ( &iqmp, rsa->iqmp ) ;
if ( ptr_zencod_rsa_mod_exp_crt ( &y, &x, &p, &q, &dmp1, &dmq1, &iqmp ) < 0 ) {
PERROR("zenbridge_rsa_mod_exp_crt");
ENGINEerr(ZENCOD_F_ZENCOD_RSA_MOD_EXP_CRT, ZENCOD_R_REQUEST_FAILED);
return 0;
}
return 1;
}
}
static int RSA_zencod_bn_mod_exp ( BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx )
{
CHEESE () ;
if ( !zencod_dso ) {
ENGINEerr(ZENCOD_F_ZENCOD_RSA_MOD_EXP, ZENCOD_R_NOT_LOADED);
return 0;
}
if ( BN_num_bits(m) > ZENBRIDGE_MAX_KEYSIZE_RSA ) {
const RSA_METHOD *meth;
meth = RSA_PKCS1_SSLeay();
return meth->bn_mod_exp(r, a, p, m, ctx, m_ctx);
} else {
zen_nb_t y, x, e, n;
if ( !bn_expand(r, BN_num_bits(m)) ) {
ENGINEerr(ZENCOD_F_ZENCOD_RSA_MOD_EXP, ZENCOD_R_BN_EXPAND_FAIL);
return 0;
}
r->top = (BN_num_bits(m) + BN_BITS2 - 1) / BN_BITS2;
BIGNUM2ZEN ( &x, a ) ;
BIGNUM2ZEN ( &y, r ) ;
BIGNUM2ZEN ( &e, p ) ;
BIGNUM2ZEN ( &n, m ) ;
if ( ptr_zencod_rsa_mod_exp ( &y, &x, &n, &e ) < 0 ) {
PERROR("zenbridge_rsa_mod_exp");
ENGINEerr(ZENCOD_F_ZENCOD_RSA_MOD_EXP, ZENCOD_R_REQUEST_FAILED);
return 0;
}
return 1;
}
}
static DSA_SIG *DSA_zencod_do_sign ( const unsigned char *dgst, int dlen, DSA *dsa )
{
zen_nb_t p, q, g, x, y, r, s, data;
DSA_SIG *sig;
BIGNUM *bn_r = NULL;
BIGNUM *bn_s = NULL;
char msg[20];
CHEESE();
if ( !zencod_dso ) {
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_SIGN, ZENCOD_R_NOT_LOADED);
goto FAILED;
}
if ( dlen > 160 ) {
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_SIGN, ZENCOD_R_REQUEST_FAILED);
goto FAILED;
}
if ( BN_num_bits(dsa->p) > ZENBRIDGE_MAX_KEYSIZE_DSA_SIGN ||
BN_num_bits(dsa->g) > ZENBRIDGE_MAX_KEYSIZE_DSA_SIGN ) {
const DSA_METHOD *meth;
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_SIGN, ZENCOD_R_BAD_KEY_COMPONENTS);
meth = DSA_OpenSSL();
return meth->dsa_do_sign(dgst, dlen, dsa);
}
if ( !(bn_s = BN_new()) || !(bn_r = BN_new()) ) {
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_SIGN, ZENCOD_R_BAD_KEY_COMPONENTS);
goto FAILED;
}
if ( !bn_expand(bn_r, 160) || !bn_expand(bn_s, 160) ) {
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_SIGN, ZENCOD_R_BN_EXPAND_FAIL);
goto FAILED;
}
bn_r->top = bn_s->top = (160 + BN_BITS2 - 1) / BN_BITS2;
BIGNUM2ZEN ( &p, dsa->p ) ;
BIGNUM2ZEN ( &q, dsa->q ) ;
BIGNUM2ZEN ( &g, dsa->g ) ;
BIGNUM2ZEN ( &x, dsa->priv_key ) ;
BIGNUM2ZEN ( &y, dsa->pub_key ) ;
BIGNUM2ZEN ( &r, bn_r ) ;
BIGNUM2ZEN ( &s, bn_s ) ;
q.len = x.len = 160;
ypcmem(msg, dgst, 20);
ptr_zencod_init_number ( &data, 160, msg ) ;
if ( ptr_zencod_dsa_do_sign ( 0, &data, &y, &p, &q, &g, &x, &r, &s ) < 0 ) {
PERROR("zenbridge_dsa_do_sign");
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_SIGN, ZENCOD_R_REQUEST_FAILED);
goto FAILED;
}
if ( !( sig = DSA_SIG_new () ) ) {
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_SIGN, ZENCOD_R_REQUEST_FAILED);
goto FAILED;
}
sig->r = bn_r;
sig->s = bn_s;
return sig;
FAILED:
if (bn_r)
BN_free(bn_r);
if (bn_s)
BN_free(bn_s);
return NULL;
}
static int DSA_zencod_do_verify ( const unsigned char *dgst, int dlen, DSA_SIG *sig, DSA *dsa )
{
zen_nb_t data, p, q, g, y, r, s, v;
char msg[20];
char v_data[20];
int ret;
CHEESE();
if ( !zencod_dso ) {
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_VERIFY, ZENCOD_R_NOT_LOADED);
return 0;
}
if ( dlen > 160 ) {
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_SIGN, ZENCOD_R_REQUEST_FAILED);
return 0;
}
if ( BN_num_bits(dsa->p) > ZENBRIDGE_MAX_KEYSIZE_DSA_SIGN ||
BN_num_bits(dsa->g) > ZENBRIDGE_MAX_KEYSIZE_DSA_SIGN ) {
const DSA_METHOD *meth;
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_SIGN, ZENCOD_R_BAD_KEY_COMPONENTS);
meth = DSA_OpenSSL();
return meth->dsa_do_verify(dgst, dlen, sig, dsa);
}
BIGNUM2ZEN ( &p, dsa->p ) ;
BIGNUM2ZEN ( &q, dsa->q ) ;
BIGNUM2ZEN ( &g, dsa->g ) ;
BIGNUM2ZEN ( &y, dsa->pub_key ) ;
BIGNUM2ZEN ( &r, sig->r ) ;
BIGNUM2ZEN ( &s, sig->s ) ;
ptr_zencod_init_number ( &v, 160, v_data ) ;
ypcmem(msg, dgst, 20);
ptr_zencod_init_number ( &data, 160, msg ) ;
if ( ( ret = ptr_zencod_dsa_do_verify ( 0, &data, &p, &q, &g, &y, &r, &s, &v ) ) < 0 ) {
PERROR("zenbridge_dsa_do_verify");
ENGINEerr(ZENCOD_F_ZENCOD_DSA_DO_VERIFY, ZENCOD_R_REQUEST_FAILED);
return 0;
}
return ( ( ret == 0 ) ? 1 : ret ) ;
}
static int DSA_zencod_bn_mod_exp ( DSA *dsa, BIGNUM *r, BIGNUM *a, const BIGNUM *p, const BIGNUM *m,
BN_CTX *ctx, BN_MONT_CTX *m_ctx )
{
CHEESE () ;
return zencod_bn_mod_exp ( r, a, p, m, ctx ) ;
}
static int DH_zencod_generate_key ( DH *dh )
{
BIGNUM *bn_prv = NULL;
BIGNUM *bn_pub = NULL;
zen_nb_t y, x, g, p;
int generate_x;
CHEESE();
if ( !zencod_dso ) {
ENGINEerr(ZENCOD_F_ZENCOD_DH_GENERATE, ZENCOD_R_NOT_LOADED);
return 0;
}
if ( dh->priv_key ) {
bn_prv = dh->priv_key;
generate_x = 0;
} else {
if (!(bn_prv = BN_new())) {
ENGINEerr(ZENCOD_F_ZENCOD_DH_GENERATE, ZENCOD_R_BN_EXPAND_FAIL);
goto FAILED;
}
generate_x = 1;
}
if ( dh->pub_key )
bn_pub = dh->pub_key;
else
if ( !( bn_pub = BN_new () ) ) {
ENGINEerr(ZENCOD_F_ZENCOD_DH_GENERATE, ZENCOD_R_BN_EXPAND_FAIL);
goto FAILED;
}
if ( !bn_wexpand ( bn_prv, dh->p->dmax ) ||
!bn_wexpand ( bn_pub, dh->p->dmax ) ) {
ENGINEerr(ZENCOD_F_ZENCOD_DH_GENERATE, ZENCOD_R_BN_EXPAND_FAIL);
goto FAILED;
}
bn_prv->top = dh->p->top;
bn_pub->top = dh->p->top;
BIGNUM2ZEN ( &p, dh->p ) ;
BIGNUM2ZEN ( &g, dh->g ) ;
BIGNUM2ZEN ( &y, bn_pub ) ;
BIGNUM2ZEN ( &x, bn_prv ) ;
x.len = DH_size(dh) * 8;
p.len = ptr_zencod_bytes2bits ( p.data, ZEN_BYTES ( p.len ) ) ;
g.len = ptr_zencod_bytes2bits ( g.data, ZEN_BYTES ( g.len ) ) ;
if ( ptr_zencod_dh_generate_key ( &y, &x, &g, &p, generate_x ) < 0 ) {
perror("zenbridge_dh_generate_key");
ENGINEerr(ZENCOD_F_ZENCOD_DH_GENERATE, ZENCOD_R_REQUEST_FAILED);
goto FAILED;
}
dh->priv_key = bn_prv;
dh->pub_key = bn_pub;
return 1;
FAILED:
if (!dh->priv_key && bn_prv)
BN_free(bn_prv);
if (!dh->pub_key && bn_pub)
BN_free(bn_pub);
return 0;
}
static int DH_zencod_compute_key ( unsigned char *key, const BIGNUM *pub_key, DH *dh )
{
zen_nb_t y, x, p, k;
CHEESE();
if ( !zencod_dso ) {
ENGINEerr(ZENCOD_F_ZENCOD_DH_COMPUTE, ZENCOD_R_NOT_LOADED);
return 0;
}
if ( !dh->priv_key ) {
ENGINEerr(ZENCOD_F_ZENCOD_DH_COMPUTE, ZENCOD_R_BAD_KEY_COMPONENTS);
return 0;
}
BIGNUM2ZEN ( &y, pub_key ) ;
BIGNUM2ZEN ( &x, dh->priv_key ) ;
BIGNUM2ZEN ( &p, dh->p ) ;
ptr_zencod_init_number ( &k, p.len, key ) ;
p.len = ptr_zencod_bytes2bits ( p.data, ZEN_BYTES ( p.len ) ) ;
y.len = ptr_zencod_bytes2bits ( y.data, ZEN_BYTES ( y.len ) ) ;
x.len = ptr_zencod_bytes2bits ( x.data, ZEN_BYTES ( x.len ) ) ;
if ( ptr_zencod_dh_compute_key ( &k, &y, &x, &p ) < 0 ) {
ENGINEerr(ZENCOD_F_ZENCOD_DH_COMPUTE, ZENCOD_R_REQUEST_FAILED);
return 0;
}
k.len = ptr_zencod_bytes2bits ( k.data, ZEN_BYTES ( k.len ) ) ;
esrever ( key, ZEN_BYTES ( k.len ) ) ;
return ZEN_BYTES ( k.len ) ;
}
static int DH_zencod_bn_mod_exp ( const DH *dh, BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx )
{
CHEESE () ;
return zencod_bn_mod_exp ( r, a, p, m, ctx ) ;
}
static void RAND_zencod_seed ( const void *buf, int num )
{
}
static int RAND_zencod_rand_bytes ( unsigned char *buf, int num )
{
zen_nb_t r;
CHEESE();
if ( !zencod_dso ) {
ENGINEerr(ZENCOD_F_ZENCOD_RAND, ZENCOD_R_NOT_LOADED);
return 0;
}
ptr_zencod_init_number ( &r, num * 8, buf ) ;
if ( ptr_zencod_rand_bytes ( &r, ZENBRIDGE_RNG_DIRECT ) < 0 ) {
PERROR("zenbridge_rand_bytes");
ENGINEerr(ZENCOD_F_ZENCOD_RAND, ZENCOD_R_REQUEST_FAILED);
return 0;
}
return 1;
}
static int RAND_zencod_rand_status ( void )
{
CHEESE () ;
return 1;
}
static int bind_fn ( ENGINE *e, const char *id )
{
if ( id && ( strcmp ( id, engine_zencod_id ) != 0 ) ) {
return 0 ;
}
if ( !bind_helper ( e ) ) {
return 0 ;
}
return 1 ;
}
static int engine_digests ( ENGINE *e, const EVP_MD **digest, const int **nids, int nid )
{
#ifdef DEBUG_ZENCOD_MD
fprintf ( stderr, "\t=>Function : static int engine_digests () called !\n" ) ;
#endif
if ( !digest ) {
*nids = engine_digest_nids ;
return engine_digest_nids_num ;
}
if ( nid == NID_md5 ) {
*digest = &engine_md5_md ;
}
else if ( nid == NID_sha1 ) {
*digest = &engine_sha1_md ;
}
else {
*digest = NULL ;
return 0 ;
}
return 1 ;
}
static int engine_sha1_init ( EVP_MD_CTX *ctx )
{
int to_return = 0 ;
to_return = ptr_zencod_sha1_init ( (ZEN_MD_DATA *) ctx->md_data ) ;
to_return = !to_return ;
return to_return ;
}
static int engine_sha1_update ( EVP_MD_CTX *ctx, const void *data, unsigned long count )
{
zen_nb_t input ;
int to_return = 0 ;
input.len = count ;
input.data = (unsigned char *) data ;
to_return = ptr_zencod_sha1_update ( (ZEN_MD_DATA *) ctx->md_data, (const zen_nb_t *) &input ) ;
to_return = !to_return ;
return to_return ;
}
static int engine_sha1_final ( EVP_MD_CTX *ctx, unsigned char *md )
{
zen_nb_t output ;
int to_return = 0 ;
output.len = SHA_DIGEST_LENGTH ;
output.data = md ;
to_return = ptr_zencod_sha1_do_final ( (ZEN_MD_DATA *) ctx->md_data, (zen_nb_t *) &output ) ;
to_return = !to_return ;
return to_return ;
}
static int engine_md5_init ( EVP_MD_CTX *ctx )
{
int to_return = 0 ;
to_return = ptr_zencod_md5_init ( (ZEN_MD_DATA *) ctx->md_data ) ;
to_return = !to_return ;
return to_return ;
}
static int engine_md5_update ( EVP_MD_CTX *ctx, const void *data, unsigned long count )
{
zen_nb_t input ;
int to_return = 0 ;
input.len = count ;
input.data = (unsigned char *) data ;
to_return = ptr_zencod_md5_update ( (ZEN_MD_DATA *) ctx->md_data, (const zen_nb_t *) &input ) ;
to_return = !to_return ;
return to_return ;
}
static int engine_md5_final ( EVP_MD_CTX *ctx, unsigned char *md )
{
zen_nb_t output ;
int to_return = 0 ;
output.len = MD5_DIGEST_LENGTH ;
output.data = md ;
to_return = ptr_zencod_md5_do_final ( (ZEN_MD_DATA *) ctx->md_data, (zen_nb_t *) &output ) ;
to_return = !to_return ;
return to_return ;
}
static int engine_md_cleanup ( EVP_MD_CTX *ctx )
{
ZEN_MD_DATA *zen_md_data = (ZEN_MD_DATA *) ctx->md_data ;
if ( zen_md_data->HashBuffer != NULL ) {
OPENSSL_free ( zen_md_data->HashBuffer ) ;
zen_md_data->HashBufferSize = 0 ;
ctx->md_data = NULL ;
}
return 1 ;
}
static int engine_md_copy ( EVP_MD_CTX *to, const EVP_MD_CTX *from )
{
const ZEN_MD_DATA *from_md = (ZEN_MD_DATA *) from->md_data ;
ZEN_MD_DATA *to_md = (ZEN_MD_DATA *) to->md_data ;
to_md->HashBuffer = OPENSSL_malloc ( from_md->HashBufferSize ) ;
memcpy ( to_md->HashBuffer, from_md->HashBuffer, from_md->HashBufferSize ) ;
return 1;
}
static int engine_ciphers ( ENGINE *e, const EVP_CIPHER **cipher, const int **nids, int nid )
{
if ( !cipher ) {
*nids = engine_cipher_nids ;
return engine_cipher_nids_num ;
}
if ( nid == NID_rc4 ) {
*cipher = &engine_rc4 ;
}
else if ( nid == NID_rc4_40 ) {
*cipher = &engine_rc4_40 ;
}
else if ( nid == NID_des_cbc ) {
*cipher = &engine_des_cbc ;
}
else if ( nid == NID_des_ede3_cbc ) {
*cipher = &engine_des_ede3_cbc ;
}
else {
*cipher = NULL ;
return 0 ;
}
return 1 ;
}
static int engine_rc4_init_key ( EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc )
{
int to_return = 0 ;
int i = 0 ;
int nb = 0 ;
NEW_ZEN_RC4_KEY *tmp_rc4_key = NULL ;
tmp_rc4_key = (NEW_ZEN_RC4_KEY *) ( ctx->cipher_data ) ;
tmp_rc4_key->first = 0 ;
tmp_rc4_key->len = ctx->key_len ;
tmp_rc4_key->rc4_state [ 0 ] = 0x00 ;
tmp_rc4_key->rc4_state [ 2 ] = 0x00 ;
nb = 256 / ctx->key_len ;
for ( i = 0; i < nb ; i++ ) {
memcpy ( &( tmp_rc4_key->rc4_state [ 4 + i*ctx->key_len ] ), key, ctx->key_len ) ;
}
to_return = 1 ;
return to_return ;
}
static int engine_rc4_cipher ( EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, unsigned int in_len )
{
zen_nb_t output, input ;
zen_nb_t rc4key ;
int to_return = 0 ;
NEW_ZEN_RC4_KEY *tmp_rc4_key = NULL ;
input.len = in_len ;
input.data = (unsigned char *) in ;
output.len = in_len ;
output.data = (unsigned char *) out ;
tmp_rc4_key = ( (NEW_ZEN_RC4_KEY *) ( ctx->cipher_data ) ) ;
rc4key.len = 260 ;
rc4key.data = &( tmp_rc4_key->rc4_state [ 0 ] ) ;
to_return = ptr_zencod_rc4_cipher ( &output, &input, (const zen_nb_t *) &rc4key, &( tmp_rc4_key->rc4_state [0] ), &( tmp_rc4_key->rc4_state [3] ), !tmp_rc4_key->first ) ;
to_return = !to_return ;
tmp_rc4_key->first = 1 ;
tmp_rc4_key = NULL ;
return to_return ;
}
static int engine_des_init_key ( EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc )
{
ZEN_DES_KEY *tmp_des_key = NULL ;
int to_return = 0 ;
tmp_des_key = (ZEN_DES_KEY *) ( ctx->cipher_data ) ;
memcpy ( &( tmp_des_key->des_key [ 0 ] ), key, 8 ) ;
memcpy ( &( tmp_des_key->des_key [ 8 ] ), key, 8 ) ;
memcpy ( &( tmp_des_key->des_key [ 16 ] ), key, 8 ) ;
memcpy ( &( tmp_des_key->des_iv [ 0 ] ), iv, 8 ) ;
to_return = 1 ;
return to_return ;
}
static int engine_des_cbc_cipher ( EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, unsigned int inl )
{
zen_nb_t output, input ;
zen_nb_t deskey_1, deskey_2, deskey_3, iv ;
int to_return = 0 ;
input.len = inl ;
input.data = (unsigned char *) in ;
output.len = inl ;
output.data = out ;
deskey_1.len = 8 ;
deskey_2.len = 8 ;
deskey_3.len = 8 ;
deskey_1.data = (unsigned char *) ( (ZEN_DES_KEY *) ( ctx->cipher_data ) )->des_key ;
deskey_2.data = (unsigned char *) &( (ZEN_DES_KEY *) ( ctx->cipher_data ) )->des_key [ 8 ] ;
deskey_3.data = (unsigned char *) &( (ZEN_DES_KEY *) ( ctx->cipher_data ) )->des_key [ 16 ] ;
memcpy ( ( (ZEN_DES_KEY *) ( ctx->cipher_data ) )->des_iv, ctx->iv, 8 ) ;
iv.len = 8 ;
iv.data = (unsigned char *) ( (ZEN_DES_KEY *) ( ctx->cipher_data ) )->des_iv ;
if ( ctx->encrypt == 0 ) {
memcpy ( ctx->iv, &( input.data [ input.len - 8 ] ), 8 ) ;
}
to_return = ptr_zencod_xdes_cipher ( &output, &input,
(zen_nb_t *) &deskey_1, (zen_nb_t *) &deskey_2, (zen_nb_t *) &deskey_3, &iv, ctx->encrypt ) ;
to_return = !to_return ;
if ( ctx->encrypt == 1 ) {
memcpy ( ctx->iv, &( output.data [ output.len - 8 ] ), 8 ) ;
}
return to_return ;
}
static int engine_des_ede3_init_key ( EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc )
{
ZEN_3DES_KEY *tmp_3des_key = NULL ;
int to_return = 0 ;
tmp_3des_key = (ZEN_3DES_KEY *) ( ctx->cipher_data ) ;
memcpy ( &( tmp_3des_key->des3_key [ 0 ] ), key, 24 ) ;
memcpy ( &( tmp_3des_key->des3_iv [ 0 ] ), iv, 8 ) ;
to_return = 1;
return to_return ;
}
static int engine_des_ede3_cbc_cipher ( EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in,
unsigned int in_len )
{
zen_nb_t output, input ;
zen_nb_t deskey_1, deskey_2, deskey_3, iv ;
int to_return = 0 ;
input.len = in_len ;
input.data = (unsigned char *) in ;
output.len = in_len ;
output.data = out ;
deskey_1.len = 8 ;
deskey_2.len = 8 ;
deskey_3.len = 8 ;
deskey_1.data = (unsigned char *) ( (ZEN_3DES_KEY *) ( ctx->cipher_data ) )->des3_key ;
deskey_2.data = (unsigned char *) &( (ZEN_3DES_KEY *) ( ctx->cipher_data ) )->des3_key [ 8 ] ;
deskey_3.data = (unsigned char *) &( (ZEN_3DES_KEY *) ( ctx->cipher_data ) )->des3_key [ 16 ] ;
memcpy ( ( (ZEN_3DES_KEY *) ( ctx->cipher_data ) )->des3_iv, ctx->iv, 8 ) ;
iv.len = 8 ;
iv.data = (unsigned char *) ( (ZEN_3DES_KEY *) ( ctx->cipher_data ) )->des3_iv ;
if ( ctx->encrypt == 0 ) {
memcpy ( ctx->iv, &( input.data [ input.len - 8 ] ), 8 ) ;
}
to_return = ptr_zencod_xdes_cipher ( &output, &input,
(zen_nb_t *) &deskey_1, (zen_nb_t *) &deskey_2, (zen_nb_t *) &deskey_3, &iv, ctx->encrypt ) ;
to_return = !to_return ;
if ( ctx->encrypt == 1 ) {
memcpy ( ctx->iv, &( output.data [ output.len - 8 ] ), 8 ) ;
}
return to_return ;
}
static int engine_cipher_cleanup ( EVP_CIPHER_CTX *ctx )
{
if ( ctx->cipher->nid == NID_rc4 || ctx->cipher->nid == NID_rc4_40 ) {
}
else if ( ctx->cipher->nid == NID_des_cbc ) {
}
else if ( ctx->cipher->nid == NID_des_ede3_cbc ) {
}
return 1 ;
}
