int main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL, *tbio = NULL;
X509 *scert = NULL;
EVP_PKEY *skey = NULL;
CMS_ContentInfo *cms = NULL;
int ret = 1;
int flags = CMS_DETACHED | CMS_STREAM;
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
cms = CMS_sign(scert, skey, NULL, in, flags);
if (!cms)
goto err;
out = BIO_new_file("smout.txt", "w");
if (!out)
goto err;
if (!(flags & CMS_STREAM))
BIO_reset(in);
if (!SMIME_write_CMS(out, cms, in, flags))
goto err;
ret = 0;
err:
if (ret) {
fprintf(stderr, "Error Signing Data\n");
ERR_print_errors_fp(stderr);
}
CMS_ContentInfo_free(cms);
X509_free(scert);
EVP_PKEY_free(skey);
BIO_free(in);
BIO_free(out);
BIO_free(tbio);
return ret;
}
