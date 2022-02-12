static int bind_helper(ENGINE *e)
{
#ifndef OPENSSL_NO_RSA
const RSA_METHOD *meth1;
#endif
if(!ENGINE_set_id(e, engine_e_gmp_id) ||
!ENGINE_set_name(e, engine_e_gmp_name) ||
#ifndef OPENSSL_NO_RSA
!ENGINE_set_RSA(e, &e_gmp_rsa) ||
#endif
!ENGINE_set_destroy_function(e, e_gmp_destroy) ||
!ENGINE_set_init_function(e, e_gmp_init) ||
!ENGINE_set_finish_function(e, e_gmp_finish) ||
!ENGINE_set_ctrl_function(e, e_gmp_ctrl) ||
!ENGINE_set_cmd_defns(e, e_gmp_cmd_defns))
return 0;
#ifndef OPENSSL_NO_RSA
meth1 = RSA_PKCS1_SSLeay();
e_gmp_rsa.rsa_pub_enc = meth1->rsa_pub_enc;
e_gmp_rsa.rsa_pub_dec = meth1->rsa_pub_dec;
e_gmp_rsa.rsa_priv_enc = meth1->rsa_priv_enc;
e_gmp_rsa.rsa_priv_dec = meth1->rsa_priv_dec;
e_gmp_rsa.bn_mod_exp = meth1->bn_mod_exp;
#endif
ERR_load_GMP_strings();
return 1;
}
static ENGINE *engine_gmp(void)
{
ENGINE *ret = ENGINE_new();
if(!ret)
return NULL;
if(!bind_helper(ret))
{
ENGINE_free(ret);
return NULL;
}
return ret;
}
void ENGINE_load_gmp(void)
{
ENGINE *toadd = engine_gmp();
if(!toadd) return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static int e_gmp_destroy(ENGINE *e)
{
ERR_unload_GMP_strings();
return 1;
}
static int e_gmp_init(ENGINE *e)
{
#ifndef OPENSSL_NO_RSA
if (hndidx_rsa == -1)
hndidx_rsa = RSA_get_ex_new_index(0,
"GMP-based RSA key handle",
NULL, NULL, NULL);
#endif
if (hndidx_rsa == -1)
return 0;
return 1;
}
static int e_gmp_finish(ENGINE *e)
{
return 1;
}
static int e_gmp_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f)(void))
{
int to_return = 1;
switch(cmd)
{
#if 0
case E_GMP_CMD_SO_PATH:
#endif
default:
GMPerr(GMP_F_E_GMP_CTRL,
GMP_R_CTRL_COMMAND_NOT_IMPLEMENTED);
to_return = 0;
break;
}
return to_return;
}
static int bn2gmp(const BIGNUM *bn, mpz_t g)
{
int toret;
char *tmpchar = BN_bn2hex(bn);
if(!tmpchar) return 0;
toret = (mpz_set_str(g, tmpchar, 16) == 0 ? 1 : 0);
OPENSSL_free(tmpchar);
return toret;
}
static int gmp2bn(mpz_t g, BIGNUM *bn)
{
int toret;
char *tmpchar = OPENSSL_malloc(mpz_sizeinbase(g, 16) + 10);
if(!tmpchar) return 0;
mpz_get_str(tmpchar, 16, g);
toret = BN_hex2bn(&bn, tmpchar);
OPENSSL_free(tmpchar);
return toret;
}
static E_GMP_RSA_CTX *e_gmp_get_rsa(RSA *rsa)
{
E_GMP_RSA_CTX *hptr = RSA_get_ex_data(rsa, hndidx_rsa);
if(hptr) return hptr;
hptr = OPENSSL_malloc(sizeof(E_GMP_RSA_CTX));
if(!hptr) return NULL;
mpz_init(hptr->n);
mpz_init(hptr->d);
mpz_init(hptr->e);
mpz_init(hptr->p);
mpz_init(hptr->q);
mpz_init(hptr->dmp1);
mpz_init(hptr->dmq1);
mpz_init(hptr->iqmp);
mpz_init(hptr->r0);
mpz_init(hptr->r1);
mpz_init(hptr->I0);
mpz_init(hptr->m1);
if(!bn2gmp(rsa->n, hptr->n) || !bn2gmp(rsa->e, hptr->e))
goto err;
if(!rsa->p || !rsa->q || !rsa->d || !rsa->dmp1 || !rsa->dmq1 || !rsa->iqmp)
{
hptr->public_only = 1;
return hptr;
}
if(!bn2gmp(rsa->d, hptr->d) || !bn2gmp(rsa->p, hptr->p) ||
!bn2gmp(rsa->q, hptr->q) || !bn2gmp(rsa->dmp1, hptr->dmp1) ||
!bn2gmp(rsa->dmq1, hptr->dmq1) || !bn2gmp(rsa->iqmp, hptr->iqmp))
goto err;
hptr->public_only = 0;
RSA_set_ex_data(rsa, hndidx_rsa, hptr);
return hptr;
err:
mpz_clear(hptr->n);
mpz_clear(hptr->d);
mpz_clear(hptr->e);
mpz_clear(hptr->p);
mpz_clear(hptr->q);
mpz_clear(hptr->dmp1);
mpz_clear(hptr->dmq1);
mpz_clear(hptr->iqmp);
mpz_clear(hptr->r0);
mpz_clear(hptr->r1);
mpz_clear(hptr->I0);
mpz_clear(hptr->m1);
OPENSSL_free(hptr);
return NULL;
}
static int e_gmp_rsa_finish(RSA *rsa)
{
E_GMP_RSA_CTX *hptr = RSA_get_ex_data(rsa, hndidx_rsa);
if(!hptr) return 0;
mpz_clear(hptr->n);
mpz_clear(hptr->d);
mpz_clear(hptr->e);
mpz_clear(hptr->p);
mpz_clear(hptr->q);
mpz_clear(hptr->dmp1);
mpz_clear(hptr->dmq1);
mpz_clear(hptr->iqmp);
mpz_clear(hptr->r0);
mpz_clear(hptr->r1);
mpz_clear(hptr->I0);
mpz_clear(hptr->m1);
OPENSSL_free(hptr);
RSA_set_ex_data(rsa, hndidx_rsa, NULL);
return 1;
}
static int e_gmp_rsa_mod_exp(BIGNUM *r, const BIGNUM *I, RSA *rsa, BN_CTX *ctx)
{
E_GMP_RSA_CTX *hptr;
int to_return = 0;
hptr = e_gmp_get_rsa(rsa);
if(!hptr)
{
GMPerr(GMP_F_E_GMP_RSA_MOD_EXP,
GMP_R_KEY_CONTEXT_ERROR);
return 0;
}
if(hptr->public_only)
{
GMPerr(GMP_F_E_GMP_RSA_MOD_EXP,
GMP_R_MISSING_KEY_COMPONENTS);
return 0;
}
if(!bn2gmp(I, hptr->I0))
return 0;
mpz_mod(hptr->r1, hptr->I0, hptr->q);
mpz_powm(hptr->m1, hptr->r1, hptr->dmq1, hptr->q);
mpz_mod(hptr->r1, hptr->I0, hptr->p);
mpz_powm(hptr->r0, hptr->r1, hptr->dmp1, hptr->p);
mpz_sub(hptr->r0, hptr->r0, hptr->m1);
if(mpz_sgn(hptr->r0) < 0)
mpz_add(hptr->r0, hptr->r0, hptr->p);
mpz_mul(hptr->r1, hptr->r0, hptr->iqmp);
mpz_mod(hptr->r0, hptr->r1, hptr->p);
if(mpz_sgn(hptr->r0) < 0)
mpz_add(hptr->r0, hptr->r0, hptr->p);
mpz_mul(hptr->r1, hptr->r0, hptr->q);
mpz_add(hptr->r0, hptr->r1, hptr->m1);
if(gmp2bn(hptr->r0, r))
to_return = 1;
return 1;
}
static int bind_fn(ENGINE *e, const char *id)
{
if(id && (strcmp(id, engine_e_gmp_id) != 0))
return 0;
if(!bind_helper(e))
return 0;
return 1;
}
