int main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL, *tbio = NULL;
X509 *rcert = NULL;
EVP_PKEY *rkey = NULL;
PKCS7 *p7 = NULL;
int ret = 1;
OpenSSL_add_all_algorithms();
ERR_load_crypto_strings();
tbio = BIO_new_file("signer.pem", "r");
if (!tbio)
goto err;
rcert = PEM_read_bio_X509(tbio, NULL, 0, NULL);
BIO_reset(tbio);
rkey = PEM_read_bio_PrivateKey(tbio, NULL, 0, NULL);
if (!rcert || !rkey)
goto err;
in = BIO_new_file("smencr.txt", "r");
if (!in)
goto err;
p7 = SMIME_read_PKCS7(in, NULL);
if (!p7)
goto err;
out = BIO_new_file("encrout.txt", "w");
if (!out)
goto err;
if (!PKCS7_decrypt(p7, rkey, rcert, out, 0))
goto err;
ret = 0;
err:
if (ret) {
fprintf(stderr, "Error Signing Data\n");
ERR_print_errors_fp(stderr);
}
PKCS7_free(p7);
X509_free(rcert);
EVP_PKEY_free(rkey);
BIO_free(in);
BIO_free(out);
BIO_free(tbio);
return ret;
}
