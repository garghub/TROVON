int main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL;
CMS_ContentInfo *cms = NULL;
int ret = 1;
OpenSSL_add_all_algorithms();
ERR_load_crypto_strings();
in = BIO_new_file("smcomp.txt", "r");
if (!in)
goto err;
cms = SMIME_read_CMS(in, NULL);
if (!cms)
goto err;
out = BIO_new_file("smuncomp.txt", "w");
if (!out)
goto err;
if (!CMS_uncompress(cms, out, NULL, 0))
goto err;
ret = 0;
err:
if (ret)
{
fprintf(stderr, "Error Uncompressing Data\n");
ERR_print_errors_fp(stderr);
}
if (cms)
CMS_ContentInfo_free(cms);
if (in)
BIO_free(in);
if (out)
BIO_free(out);
return ret;
}
