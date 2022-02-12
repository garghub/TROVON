int main(int argc, char **argv)
{
BIO *bio_err;
X509_REQ *req = NULL;
EVP_PKEY *pkey = NULL;
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON);
bio_err = BIO_new_fp(stderr, BIO_NOCLOSE);
mkreq(&req, &pkey, 512, 0, 365);
RSA_print_fp(stdout, pkey->pkey.rsa, 0);
X509_REQ_print_fp(stdout, req);
PEM_write_X509_REQ(stdout, req);
X509_REQ_free(req);
EVP_PKEY_free(pkey);
#ifndef OPENSSL_NO_ENGINE
ENGINE_cleanup();
#endif
CRYPTO_cleanup_all_ex_data();
CRYPTO_mem_leaks(bio_err);
BIO_free(bio_err);
return (0);
}
static void callback(int p, int n, void *arg)
{
char c = 'B';
if (p == 0)
c = '.';
if (p == 1)
c = '+';
if (p == 2)
c = '*';
if (p == 3)
c = '\n';
fputc(c, stderr);
}
int mkreq(X509_REQ **req, EVP_PKEY **pkeyp, int bits, int serial, int days)
{
X509_REQ *x;
EVP_PKEY *pk;
RSA *rsa;
X509_NAME *name = NULL;
STACK_OF(X509_EXTENSION) *exts = NULL;
if ((pk = EVP_PKEY_new()) == NULL)
goto err;
if ((x = X509_REQ_new()) == NULL)
goto err;
rsa = RSA_generate_key(bits, RSA_F4, callback, NULL);
if (!EVP_PKEY_assign_RSA(pk, rsa))
goto err;
rsa = NULL;
X509_REQ_set_pubkey(x, pk);
name = X509_REQ_get_subject_name(x);
X509_NAME_add_entry_by_txt(name, "C", MBSTRING_ASC, "UK", -1, -1, 0);
X509_NAME_add_entry_by_txt(name, "CN",
MBSTRING_ASC, "OpenSSL Group", -1, -1, 0);
#ifdef REQUEST_EXTENSIONS
exts = sk_X509_EXTENSION_new_null();
add_ext(exts, NID_key_usage, "critical,digitalSignature,keyEncipherment");
add_ext(exts, NID_subject_alt_name, "email:steve@openssl.org");
add_ext(exts, NID_netscape_cert_type, "client,email");
# ifdef CUSTOM_EXT
{
int nid;
nid = OBJ_create("1.2.3.4", "MyAlias", "My Test Alias Extension");
X509V3_EXT_add_alias(nid, NID_netscape_comment);
add_ext(x, nid, "example comment alias");
}
# endif
X509_REQ_add_extensions(x, exts);
sk_X509_EXTENSION_pop_free(exts, X509_EXTENSION_free);
#endif
if (!X509_REQ_sign(x, pk, EVP_sha1()))
goto err;
*req = x;
*pkeyp = pk;
return (1);
err:
return (0);
}
