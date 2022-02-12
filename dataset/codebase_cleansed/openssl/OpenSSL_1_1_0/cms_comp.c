int main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL;
CMS_ContentInfo *cms = NULL;
int ret = 1;
int flags = CMS_STREAM;
OpenSSL_add_all_algorithms();
ERR_load_crypto_strings();
in = BIO_new_file("comp.txt", "r");
if (!in)
goto err;
cms = CMS_compress(in, NID_zlib_compression, flags);
if (!cms)
goto err;
out = BIO_new_file("smcomp.txt", "w");
if (!out)
goto err;
if (!SMIME_write_CMS(out, cms, in, flags))
goto err;
ret = 0;
err:
if (ret) {
fprintf(stderr, "Error Compressing Data\n");
ERR_print_errors_fp(stderr);
}
CMS_ContentInfo_free(cms);
BIO_free(in);
BIO_free(out);
return ret;
}
