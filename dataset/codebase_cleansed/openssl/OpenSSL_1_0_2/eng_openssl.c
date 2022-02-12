static int bind_helper(ENGINE *e)
{
if (!ENGINE_set_id(e, engine_openssl_id)
|| !ENGINE_set_name(e, engine_openssl_name)
#ifndef TEST_ENG_OPENSSL_NO_ALGORITHMS
# ifndef OPENSSL_NO_RSA
|| !ENGINE_set_RSA(e, RSA_get_default_method())
# endif
# ifndef OPENSSL_NO_DSA
|| !ENGINE_set_DSA(e, DSA_get_default_method())
# endif
# ifndef OPENSSL_NO_ECDH
|| !ENGINE_set_ECDH(e, ECDH_OpenSSL())
# endif
# ifndef OPENSSL_NO_ECDSA
|| !ENGINE_set_ECDSA(e, ECDSA_OpenSSL())
# endif
# ifndef OPENSSL_NO_DH
|| !ENGINE_set_DH(e, DH_get_default_method())
# endif
|| !ENGINE_set_RAND(e, RAND_SSLeay())
# ifdef TEST_ENG_OPENSSL_RC4
|| !ENGINE_set_ciphers(e, openssl_ciphers)
# endif
# ifdef TEST_ENG_OPENSSL_SHA
|| !ENGINE_set_digests(e, openssl_digests)
# endif
#endif
#ifdef TEST_ENG_OPENSSL_PKEY
|| !ENGINE_set_load_privkey_function(e, openssl_load_privkey)
#endif
)
return 0;
return 1;
}
static ENGINE *engine_openssl(void)
{
ENGINE *ret = ENGINE_new();
if (!ret)
return NULL;
if (!bind_helper(ret)) {
ENGINE_free(ret);
return NULL;
}
return ret;
}
void ENGINE_load_openssl(void)
{
ENGINE *toadd = engine_openssl();
if (!toadd)
return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static int bind_fn(ENGINE *e, const char *id)
{
if (id && (strcmp(id, engine_openssl_id) != 0))
return 0;
if (!bind_helper(e))
return 0;
return 1;
}
static int test_rc4_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
# ifdef TEST_ENG_OPENSSL_RC4_P_INIT
fprintf(stderr, "(TEST_ENG_OPENSSL_RC4) test_init_key() called\n");
# endif
memcpy(&test(ctx)->key[0], key, EVP_CIPHER_CTX_key_length(ctx));
RC4_set_key(&test(ctx)->ks, EVP_CIPHER_CTX_key_length(ctx),
test(ctx)->key);
return 1;
}
static int test_rc4_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
# ifdef TEST_ENG_OPENSSL_RC4_P_CIPHER
fprintf(stderr, "(TEST_ENG_OPENSSL_RC4) test_cipher() called\n");
# endif
RC4(&test(ctx)->ks, inl, in, out);
return 1;
}
static int openssl_ciphers(ENGINE *e, const EVP_CIPHER **cipher,
const int **nids, int nid)
{
if (!cipher) {
*nids = test_cipher_nids;
return test_cipher_nids_number;
}
if (nid == NID_rc4)
*cipher = &test_r4_cipher;
else if (nid == NID_rc4_40)
*cipher = &test_r4_40_cipher;
else {
# ifdef TEST_ENG_OPENSSL_RC4_OTHERS
fprintf(stderr, "(TEST_ENG_OPENSSL_RC4) returning NULL for "
"nid %d\n", nid);
# endif
*cipher = NULL;
return 0;
}
return 1;
}
static int test_sha1_init(EVP_MD_CTX *ctx)
{
# ifdef TEST_ENG_OPENSSL_SHA_P_INIT
fprintf(stderr, "(TEST_ENG_OPENSSL_SHA) test_sha1_init() called\n");
# endif
return SHA1_Init(ctx->md_data);
}
static int test_sha1_update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
# ifdef TEST_ENG_OPENSSL_SHA_P_UPDATE
fprintf(stderr, "(TEST_ENG_OPENSSL_SHA) test_sha1_update() called\n");
# endif
return SHA1_Update(ctx->md_data, data, count);
}
static int test_sha1_final(EVP_MD_CTX *ctx, unsigned char *md)
{
# ifdef TEST_ENG_OPENSSL_SHA_P_FINAL
fprintf(stderr, "(TEST_ENG_OPENSSL_SHA) test_sha1_final() called\n");
# endif
return SHA1_Final(md, ctx->md_data);
}
static int openssl_digests(ENGINE *e, const EVP_MD **digest,
const int **nids, int nid)
{
if (!digest) {
*nids = test_digest_nids;
return test_digest_nids_number;
}
if (nid == NID_sha1)
*digest = &test_sha_md;
else {
# ifdef TEST_ENG_OPENSSL_SHA_OTHERS
fprintf(stderr, "(TEST_ENG_OPENSSL_SHA) returning NULL for "
"nid %d\n", nid);
# endif
*digest = NULL;
return 0;
}
return 1;
}
static EVP_PKEY *openssl_load_privkey(ENGINE *eng, const char *key_id,
UI_METHOD *ui_method,
void *callback_data)
{
BIO *in;
EVP_PKEY *key;
fprintf(stderr, "(TEST_ENG_OPENSSL_PKEY)Loading Private key %s\n",
key_id);
in = BIO_new_file(key_id, "r");
if (!in)
return NULL;
key = PEM_read_bio_PrivateKey(in, NULL, 0, NULL);
BIO_free(in);
return key;
}
