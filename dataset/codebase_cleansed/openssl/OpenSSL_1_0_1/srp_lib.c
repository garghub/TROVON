static BIGNUM *srp_Calc_k(BIGNUM *N, BIGNUM *g)
{
unsigned char digest[SHA_DIGEST_LENGTH];
unsigned char *tmp;
EVP_MD_CTX ctxt;
int longg ;
int longN = BN_num_bytes(N);
if ((tmp = OPENSSL_malloc(longN)) == NULL)
return NULL;
BN_bn2bin(N,tmp) ;
EVP_MD_CTX_init(&ctxt);
EVP_DigestInit_ex(&ctxt, EVP_sha1(), NULL);
EVP_DigestUpdate(&ctxt, tmp, longN);
memset(tmp, 0, longN);
longg = BN_bn2bin(g,tmp) ;
EVP_DigestUpdate(&ctxt, tmp + longg, longN-longg);
EVP_DigestUpdate(&ctxt, tmp, longg);
OPENSSL_free(tmp);
EVP_DigestFinal_ex(&ctxt, digest, NULL);
EVP_MD_CTX_cleanup(&ctxt);
return BN_bin2bn(digest, sizeof(digest), NULL);
}
BIGNUM *SRP_Calc_u(BIGNUM *A, BIGNUM *B, BIGNUM *N)
{
BIGNUM *u;
unsigned char cu[SHA_DIGEST_LENGTH];
unsigned char *cAB;
EVP_MD_CTX ctxt;
int longN;
if ((A == NULL) ||(B == NULL) || (N == NULL))
return NULL;
longN= BN_num_bytes(N);
if ((cAB = OPENSSL_malloc(2*longN)) == NULL)
return NULL;
memset(cAB, 0, longN);
EVP_MD_CTX_init(&ctxt);
EVP_DigestInit_ex(&ctxt, EVP_sha1(), NULL);
EVP_DigestUpdate(&ctxt, cAB + BN_bn2bin(A,cAB+longN), longN);
EVP_DigestUpdate(&ctxt, cAB + BN_bn2bin(B,cAB+longN), longN);
OPENSSL_free(cAB);
EVP_DigestFinal_ex(&ctxt, cu, NULL);
EVP_MD_CTX_cleanup(&ctxt);
if (!(u = BN_bin2bn(cu, sizeof(cu), NULL)))
return NULL;
if (!BN_is_zero(u))
return u;
BN_free(u);
return NULL;
}
BIGNUM *SRP_Calc_server_key(BIGNUM *A, BIGNUM *v, BIGNUM *u, BIGNUM *b, BIGNUM *N)
{
BIGNUM *tmp = NULL, *S = NULL;
BN_CTX *bn_ctx;
if (u == NULL || A == NULL || v == NULL || b == NULL || N == NULL)
return NULL;
if ((bn_ctx = BN_CTX_new()) == NULL ||
(tmp = BN_new()) == NULL ||
(S = BN_new()) == NULL )
goto err;
if (!BN_mod_exp(tmp,v,u,N,bn_ctx))
goto err;
if (!BN_mod_mul(tmp,A,tmp,N,bn_ctx))
goto err;
if (!BN_mod_exp(S,tmp,b,N,bn_ctx))
goto err;
err:
BN_CTX_free(bn_ctx);
BN_clear_free(tmp);
return S;
}
BIGNUM *SRP_Calc_B(BIGNUM *b, BIGNUM *N, BIGNUM *g, BIGNUM *v)
{
BIGNUM *kv = NULL, *gb = NULL;
BIGNUM *B = NULL, *k = NULL;
BN_CTX *bn_ctx;
if (b == NULL || N == NULL || g == NULL || v == NULL ||
(bn_ctx = BN_CTX_new()) == NULL)
return NULL;
if ( (kv = BN_new()) == NULL ||
(gb = BN_new()) == NULL ||
(B = BN_new())== NULL)
goto err;
if (!BN_mod_exp(gb,g,b,N,bn_ctx) ||
!(k = srp_Calc_k(N,g)) ||
!BN_mod_mul(kv,v,k,N,bn_ctx) ||
!BN_mod_add(B,gb,kv,N,bn_ctx))
{
BN_free(B);
B = NULL;
}
err:
BN_CTX_free(bn_ctx);
BN_clear_free(kv);
BN_clear_free(gb);
BN_free(k);
return B;
}
BIGNUM *SRP_Calc_x(BIGNUM *s, const char *user, const char *pass)
{
unsigned char dig[SHA_DIGEST_LENGTH];
EVP_MD_CTX ctxt;
unsigned char *cs;
if ((s == NULL) ||
(user == NULL) ||
(pass == NULL))
return NULL;
if ((cs = OPENSSL_malloc(BN_num_bytes(s))) == NULL)
return NULL;
EVP_MD_CTX_init(&ctxt);
EVP_DigestInit_ex(&ctxt, EVP_sha1(), NULL);
EVP_DigestUpdate(&ctxt, user, strlen(user));
EVP_DigestUpdate(&ctxt, ":", 1);
EVP_DigestUpdate(&ctxt, pass, strlen(pass));
EVP_DigestFinal_ex(&ctxt, dig, NULL);
EVP_DigestInit_ex(&ctxt, EVP_sha1(), NULL);
BN_bn2bin(s,cs);
EVP_DigestUpdate(&ctxt, cs, BN_num_bytes(s));
OPENSSL_free(cs);
EVP_DigestUpdate(&ctxt, dig, sizeof(dig));
EVP_DigestFinal_ex(&ctxt, dig, NULL);
EVP_MD_CTX_cleanup(&ctxt);
return BN_bin2bn(dig, sizeof(dig), NULL);
}
BIGNUM *SRP_Calc_A(BIGNUM *a, BIGNUM *N, BIGNUM *g)
{
BN_CTX *bn_ctx;
BIGNUM * A = NULL;
if (a == NULL || N == NULL || g == NULL ||
(bn_ctx = BN_CTX_new()) == NULL)
return NULL;
if ((A = BN_new()) != NULL &&
!BN_mod_exp(A,g,a,N,bn_ctx))
{
BN_free(A);
A = NULL;
}
BN_CTX_free(bn_ctx);
return A;
}
BIGNUM *SRP_Calc_client_key(BIGNUM *N, BIGNUM *B, BIGNUM *g, BIGNUM *x, BIGNUM *a, BIGNUM *u)
{
BIGNUM *tmp = NULL, *tmp2 = NULL, *tmp3 = NULL , *k = NULL, *K = NULL;
BN_CTX *bn_ctx;
if (u == NULL || B == NULL || N == NULL || g == NULL || x == NULL || a == NULL ||
(bn_ctx = BN_CTX_new()) == NULL)
return NULL;
if ((tmp = BN_new()) == NULL ||
(tmp2 = BN_new())== NULL ||
(tmp3 = BN_new())== NULL ||
(K = BN_new()) == NULL)
goto err;
if (!BN_mod_exp(tmp,g,x,N,bn_ctx))
goto err;
if (!(k = srp_Calc_k(N,g)))
goto err;
if (!BN_mod_mul(tmp2,tmp,k,N,bn_ctx))
goto err;
if (!BN_mod_sub(tmp,B,tmp2,N,bn_ctx))
goto err;
if (!BN_mod_mul(tmp3,u,x,N,bn_ctx))
goto err;
if (!BN_mod_add(tmp2,a,tmp3,N,bn_ctx))
goto err;
if (!BN_mod_exp(K,tmp,tmp2,N,bn_ctx))
goto err;
err :
BN_CTX_free(bn_ctx);
BN_clear_free(tmp);
BN_clear_free(tmp2);
BN_clear_free(tmp3);
BN_free(k);
return K;
}
int SRP_Verify_B_mod_N(BIGNUM *B, BIGNUM *N)
{
BIGNUM *r;
BN_CTX *bn_ctx;
int ret = 0;
if (B == NULL || N == NULL ||
(bn_ctx = BN_CTX_new()) == NULL)
return 0;
if ((r = BN_new()) == NULL)
goto err;
if (!BN_nnmod(r,B,N,bn_ctx))
goto err;
ret = !BN_is_zero(r);
err:
BN_CTX_free(bn_ctx);
BN_free(r);
return ret;
}
int SRP_Verify_A_mod_N(BIGNUM *A, BIGNUM *N)
{
return SRP_Verify_B_mod_N(A,N) ;
}
char *SRP_check_known_gN_param(BIGNUM *g, BIGNUM *N)
{
size_t i;
if ((g == NULL) || (N == NULL))
return 0;
srp_bn_print(g);
srp_bn_print(N);
for(i = 0; i < KNOWN_GN_NUMBER; i++)
{
if (BN_cmp(knowngN[i].g, g) == 0 && BN_cmp(knowngN[i].N, N) == 0)
return knowngN[i].id;
}
return NULL;
}
SRP_gN *SRP_get_default_gN(const char *id)
{
size_t i;
if (id == NULL)
return knowngN;
for(i = 0; i < KNOWN_GN_NUMBER; i++)
{
if (strcmp(knowngN[i].id, id)==0)
return knowngN + i;
}
return NULL;
}
