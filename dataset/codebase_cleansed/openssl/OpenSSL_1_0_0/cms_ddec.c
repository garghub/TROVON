int main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL, *tbio = NULL, *dcont = NULL;
X509 *rcert = NULL;
EVP_PKEY *rkey = NULL;
CMS_ContentInfo *cms = NULL;
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
in = BIO_new_file("smencr.pem", "r");
if (!in)
goto err;
cms = PEM_read_bio_CMS(in, NULL, 0, NULL);
if (!cms)
goto err;
dcont = BIO_new_file("smencr.out", "rb");
if (!in)
goto err;
out = BIO_new_file("encrout.txt", "w");
if (!out)
goto err;
if (!CMS_decrypt(cms, rkey, rcert, dcont, out, 0))
goto err;
ret = 0;
err:
if (ret)
{
fprintf(stderr, "Error Decrypting Data\n");
ERR_print_errors_fp(stderr);
}
if (cms)
CMS_ContentInfo_free(cms);
if (rcert)
X509_free(rcert);
if (rkey)
EVP_PKEY_free(rkey);
if (in)
BIO_free(in);
if (out)
BIO_free(out);
if (tbio)
BIO_free(tbio);
if (dcont)
BIO_free(dcont);
return ret;
}
