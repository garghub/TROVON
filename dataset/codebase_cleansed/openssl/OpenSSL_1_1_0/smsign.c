int main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL, *tbio = NULL;
X509 *scert = NULL;
EVP_PKEY *skey = NULL;
PKCS7 *p7 = NULL;
int ret = 1;
int flags = PKCS7_DETACHED | PKCS7_STREAM;
OpenSSL_add_all_algorithms();
ERR_load_crypto_strings();
tbio = BIO_new_file("signer.pem", "r");
if (!tbio)
goto err;
scert = PEM_read_bio_X509(tbio, NULL, 0, NULL);
BIO_reset(tbio);
skey = PEM_read_bio_PrivateKey(tbio, NULL, 0, NULL);
if (!scert || !skey)
goto err;
in = BIO_new_file("sign.txt", "r");
if (!in)
goto err;
p7 = PKCS7_sign(scert, skey, NULL, in, flags);
if (!p7)
goto err;
out = BIO_new_file("smout.txt", "w");
if (!out)
goto err;
if (!(flags & PKCS7_STREAM))
BIO_reset(in);
if (!SMIME_write_PKCS7(out, p7, in, flags))
goto err;
ret = 0;
err:
if (ret) {
fprintf(stderr, "Error Signing Data\n");
ERR_print_errors_fp(stderr);
}
PKCS7_free(p7);
X509_free(scert);
EVP_PKEY_free(skey);
BIO_free(in);
BIO_free(out);
BIO_free(tbio);
return ret;
}
