int MAIN(int argc, char **argv)
{
ENGINE *e = NULL;
char **args, *infile = NULL, *outfile = NULL;
char *passargin = NULL, *passargout = NULL;
BIO *in = NULL, *out = NULL;
const EVP_CIPHER *cipher = NULL;
int informat, outformat;
int pubin = 0, pubout = 0, pubtext = 0, text = 0, noout = 0;
EVP_PKEY *pkey=NULL;
char *passin = NULL, *passout = NULL;
int badarg = 0;
#ifndef OPENSSL_NO_ENGINE
char *engine=NULL;
#endif
int ret = 1;
if (bio_err == NULL)
bio_err = BIO_new_fp (stderr, BIO_NOCLOSE);
if (!load_config(bio_err, NULL))
goto end;
informat=FORMAT_PEM;
outformat=FORMAT_PEM;
ERR_load_crypto_strings();
OpenSSL_add_all_algorithms();
args = argv + 1;
while (!badarg && *args && *args[0] == '-')
{
if (!strcmp(*args,"-inform"))
{
if (args[1])
{
args++;
informat=str2fmt(*args);
}
else badarg = 1;
}
else if (!strcmp(*args,"-outform"))
{
if (args[1])
{
args++;
outformat=str2fmt(*args);
}
else badarg = 1;
}
else if (!strcmp(*args,"-passin"))
{
if (!args[1]) goto bad;
passargin= *(++args);
}
else if (!strcmp(*args,"-passout"))
{
if (!args[1]) goto bad;
passargout= *(++args);
}
#ifndef OPENSSL_NO_ENGINE
else if (strcmp(*args,"-engine") == 0)
{
if (!args[1]) goto bad;
engine= *(++args);
}
#endif
else if (!strcmp (*args, "-in"))
{
if (args[1])
{
args++;
infile = *args;
}
else badarg = 1;
}
else if (!strcmp (*args, "-out"))
{
if (args[1])
{
args++;
outfile = *args;
}
else badarg = 1;
}
else if (strcmp(*args,"-pubin") == 0)
{
pubin=1;
pubout=1;
pubtext=1;
}
else if (strcmp(*args,"-pubout") == 0)
pubout=1;
else if (strcmp(*args,"-text_pub") == 0)
{
pubtext=1;
text=1;
}
else if (strcmp(*args,"-text") == 0)
text=1;
else if (strcmp(*args,"-noout") == 0)
noout=1;
else
{
cipher = EVP_get_cipherbyname(*args + 1);
if (!cipher)
{
BIO_printf(bio_err, "Unknown cipher %s\n",
*args + 1);
badarg = 1;
}
}
args++;
}
if (badarg)
{
bad:
BIO_printf(bio_err, "Usage pkey [options]\n");
BIO_printf(bio_err, "where options are\n");
BIO_printf(bio_err, "-in file input file\n");
BIO_printf(bio_err, "-inform X input format (DER or PEM)\n");
BIO_printf(bio_err, "-passin arg input file pass phrase source\n");
BIO_printf(bio_err, "-outform X output format (DER or PEM)\n");
BIO_printf(bio_err, "-out file output file\n");
BIO_printf(bio_err, "-passout arg output file pass phrase source\n");
#ifndef OPENSSL_NO_ENGINE
BIO_printf(bio_err, "-engine e use engine e, possibly a hardware device.\n");
#endif
return 1;
}
#ifndef OPENSSL_NO_ENGINE
e = setup_engine(bio_err, engine, 0);
#endif
if (!app_passwd(bio_err, passargin, passargout, &passin, &passout))
{
BIO_printf(bio_err, "Error getting passwords\n");
goto end;
}
if (outfile)
{
if (!(out = BIO_new_file (outfile, "wb")))
{
BIO_printf(bio_err,
"Can't open output file %s\n", outfile);
goto end;
}
}
else
{
out = BIO_new_fp (stdout, BIO_NOCLOSE);
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
}
if (pubin)
pkey = load_pubkey(bio_err, infile, informat, 1,
passin, e, "Public Key");
else
pkey = load_key(bio_err, infile, informat, 1,
passin, e, "key");
if (!pkey)
goto end;
if (!noout)
{
if (outformat == FORMAT_PEM)
{
if (pubout)
PEM_write_bio_PUBKEY(out,pkey);
else
PEM_write_bio_PrivateKey(out, pkey, cipher,
NULL, 0, NULL, passout);
}
else if (outformat == FORMAT_ASN1)
{
if (pubout)
i2d_PUBKEY_bio(out, pkey);
else
i2d_PrivateKey_bio(out, pkey);
}
else
{
BIO_printf(bio_err, "Bad format specified for key\n");
goto end;
}
}
if (text)
{
if (pubtext)
EVP_PKEY_print_public(out, pkey, 0, NULL);
else
EVP_PKEY_print_private(out, pkey, 0, NULL);
}
ret = 0;
end:
EVP_PKEY_free(pkey);
BIO_free_all(out);
BIO_free(in);
if (passin)
OPENSSL_free(passin);
if (passout)
OPENSSL_free(passout);
return ret;
}
