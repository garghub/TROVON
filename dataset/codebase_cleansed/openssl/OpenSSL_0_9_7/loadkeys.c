EVP_PKEY * ReadPublicKey(const char *certfile)
{
FILE *fp = fopen (certfile, "r");
X509 *x509;
EVP_PKEY *pkey;
if (!fp)
return NULL;
x509 = PEM_read_X509(fp, NULL, 0, NULL);
if (x509 == NULL)
{
ERR_print_errors_fp (stderr);
return NULL;
}
fclose (fp);
pkey=X509_extract_key(x509);
X509_free(x509);
if (pkey == NULL)
ERR_print_errors_fp (stderr);
return pkey;
}
EVP_PKEY *ReadPrivateKey(const char *keyfile)
{
FILE *fp = fopen(keyfile, "r");
EVP_PKEY *pkey;
if (!fp)
return NULL;
pkey = PEM_read_PrivateKey(fp, NULL, 0, NULL);
fclose (fp);
if (pkey == NULL)
ERR_print_errors_fp (stderr);
return pkey;
}
