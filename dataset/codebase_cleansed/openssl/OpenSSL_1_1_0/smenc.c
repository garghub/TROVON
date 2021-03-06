int main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL, *tbio = NULL;
X509 *rcert = NULL;
STACK_OF(X509) *recips = NULL;
PKCS7 *p7 = NULL;
int ret = 1;
int flags = PKCS7_STREAM;
OpenSSL_add_all_algorithms();
ERR_load_crypto_strings();
tbio = BIO_new_file("signer.pem", "r");
if (!tbio)
goto err;
rcert = PEM_read_bio_X509(tbio, NULL, 0, NULL);
if (!rcert)
goto err;
recips = sk_X509_new_null();
if (!recips || !sk_X509_push(recips, rcert))
goto err;
rcert = NULL;
in = BIO_new_file("encr.txt", "r");
if (!in)
goto err;
p7 = PKCS7_encrypt(recips, in, EVP_des_ede3_cbc(), flags);
if (!p7)
goto err;
out = BIO_new_file("smencr.txt", "w");
if (!out)
goto err;
if (!SMIME_write_PKCS7(out, p7, in, flags))
goto err;
ret = 0;
err:
if (ret) {
fprintf(stderr, "Error Encrypting Data\n");
ERR_print_errors_fp(stderr);
}
PKCS7_free(p7);
X509_free(rcert);
sk_X509_pop_free(recips, X509_free);
BIO_free(in);
BIO_free(out);
BIO_free(tbio);
return ret;
}
