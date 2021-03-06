int MAIN(int argc, char **argv)
{
char **args, *infile = NULL, *outfile = NULL;
char *passargin = NULL, *passargout = NULL;
BIO *in = NULL, *out = NULL;
int topk8 = 0;
int pbe_nid = -1;
const EVP_CIPHER *cipher = NULL;
int iter = PKCS12_DEFAULT_ITER;
int informat, outformat;
int p8_broken = PKCS8_OK;
int nocrypt = 0;
X509_SIG *p8;
PKCS8_PRIV_KEY_INFO *p8inf;
EVP_PKEY *pkey;
char pass[50], *passin = NULL, *passout = NULL, *p8pass = NULL;
int badarg = 0;
if (bio_err == NULL) bio_err = BIO_new_fp (stderr, BIO_NOCLOSE);
informat=FORMAT_PEM;
outformat=FORMAT_PEM;
ERR_load_crypto_strings();
OpenSSL_add_all_algorithms();
args = argv + 1;
while (!badarg && *args && *args[0] == '-') {
if (!strcmp(*args,"-v2")) {
if (args[1]) {
args++;
cipher=EVP_get_cipherbyname(*args);
if(!cipher) {
BIO_printf(bio_err,
"Unknown cipher %s\n", *args);
badarg = 1;
}
} else badarg = 1;
} else if (!strcmp(*args,"-v1")) {
if (args[1]) {
args++;
pbe_nid=OBJ_txt2nid(*args);
if(pbe_nid == NID_undef) {
BIO_printf(bio_err,
"Unknown PBE algorithm %s\n", *args);
badarg = 1;
}
} else badarg = 1;
} else if (!strcmp(*args,"-inform")) {
if (args[1]) {
args++;
informat=str2fmt(*args);
} else badarg = 1;
} else if (!strcmp(*args,"-outform")) {
if (args[1]) {
args++;
outformat=str2fmt(*args);
} else badarg = 1;
} else if (!strcmp (*args, "-topk8")) topk8 = 1;
else if (!strcmp (*args, "-noiter")) iter = 1;
else if (!strcmp (*args, "-nocrypt")) nocrypt = 1;
else if (!strcmp (*args, "-nooct")) p8_broken = PKCS8_NO_OCTET;
else if (!strcmp (*args, "-nsdb")) p8_broken = PKCS8_NS_DB;
else if (!strcmp (*args, "-embed")) p8_broken = PKCS8_EMBEDDED_PARAM;
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
else if (!strcmp (*args, "-in")) {
if (args[1]) {
args++;
infile = *args;
} else badarg = 1;
} else if (!strcmp (*args, "-out")) {
if (args[1]) {
args++;
outfile = *args;
} else badarg = 1;
} else badarg = 1;
args++;
}
if (badarg) {
bad:
BIO_printf(bio_err, "Usage pkcs8 [options]\n");
BIO_printf(bio_err, "where options are\n");
BIO_printf(bio_err, "-in file input file\n");
BIO_printf(bio_err, "-inform X input format (DER or PEM)\n");
BIO_printf(bio_err, "-passin arg input file pass phrase source\n");
BIO_printf(bio_err, "-outform X output format (DER or PEM)\n");
BIO_printf(bio_err, "-out file output file\n");
BIO_printf(bio_err, "-passout arg output file pass phrase source\n");
BIO_printf(bio_err, "-topk8 output PKCS8 file\n");
BIO_printf(bio_err, "-nooct use (nonstandard) no octet format\n");
BIO_printf(bio_err, "-embed use (nonstandard) embedded DSA parameters format\n");
BIO_printf(bio_err, "-nsdb use (nonstandard) DSA Netscape DB format\n");
BIO_printf(bio_err, "-noiter use 1 as iteration count\n");
BIO_printf(bio_err, "-nocrypt use or expect unencrypted private key\n");
BIO_printf(bio_err, "-v2 alg use PKCS#5 v2.0 and cipher \"alg\"\n");
BIO_printf(bio_err, "-v1 obj use PKCS#5 v1.5 and cipher \"alg\"\n");
return (1);
}
if(!app_passwd(bio_err, passargin, passargout, &passin, &passout)) {
BIO_printf(bio_err, "Error getting passwords\n");
return (1);
}
if ((pbe_nid == -1) && !cipher) pbe_nid = NID_pbeWithMD5AndDES_CBC;
if (infile) {
if (!(in = BIO_new_file(infile, "rb"))) {
BIO_printf(bio_err,
"Can't open input file %s\n", infile);
return (1);
}
} else in = BIO_new_fp (stdin, BIO_NOCLOSE);
if (outfile) {
if (!(out = BIO_new_file (outfile, "wb"))) {
BIO_printf(bio_err,
"Can't open output file %s\n", outfile);
return (1);
}
} else out = BIO_new_fp (stdout, BIO_NOCLOSE);
if (topk8) {
if(informat == FORMAT_PEM)
pkey = PEM_read_bio_PrivateKey(in, NULL, NULL, passin);
else if(informat == FORMAT_ASN1)
pkey = d2i_PrivateKey_bio(in, NULL);
else {
BIO_printf(bio_err, "Bad format specified for key\n");
return (1);
}
if (!pkey) {
BIO_printf(bio_err, "Error reading key\n", outfile);
ERR_print_errors(bio_err);
return (1);
}
BIO_free(in);
if (!(p8inf = EVP_PKEY2PKCS8_broken(pkey, p8_broken))) {
BIO_printf(bio_err, "Error converting key\n", outfile);
ERR_print_errors(bio_err);
return (1);
}
if(nocrypt) {
if(outformat == FORMAT_PEM)
PEM_write_bio_PKCS8_PRIV_KEY_INFO(out, p8inf);
else if(outformat == FORMAT_ASN1)
i2d_PKCS8_PRIV_KEY_INFO_bio(out, p8inf);
else {
BIO_printf(bio_err, "Bad format specified for key\n");
return (1);
}
} else {
if(passout) p8pass = passout;
else {
p8pass = pass;
EVP_read_pw_string(pass, 50, "Enter Encryption Password:", 1);
}
app_RAND_load_file(NULL, bio_err, 0);
if (!(p8 = PKCS8_encrypt(pbe_nid, cipher,
p8pass, strlen(p8pass),
NULL, 0, iter, p8inf))) {
BIO_printf(bio_err, "Error encrypting key\n",
outfile);
ERR_print_errors(bio_err);
return (1);
}
app_RAND_write_file(NULL, bio_err);
if(outformat == FORMAT_PEM)
PEM_write_bio_PKCS8(out, p8);
else if(outformat == FORMAT_ASN1)
i2d_PKCS8_bio(out, p8);
else {
BIO_printf(bio_err, "Bad format specified for key\n");
return (1);
}
X509_SIG_free(p8);
}
PKCS8_PRIV_KEY_INFO_free (p8inf);
EVP_PKEY_free(pkey);
BIO_free(out);
if(passin) Free(passin);
if(passout) Free(passout);
return (0);
}
if(nocrypt) {
if(informat == FORMAT_PEM)
p8inf = PEM_read_bio_PKCS8_PRIV_KEY_INFO(in,NULL,NULL, NULL);
else if(informat == FORMAT_ASN1)
p8inf = d2i_PKCS8_PRIV_KEY_INFO_bio(in, NULL);
else {
BIO_printf(bio_err, "Bad format specified for key\n");
return (1);
}
} else {
if(informat == FORMAT_PEM)
p8 = PEM_read_bio_PKCS8(in, NULL, NULL, NULL);
else if(informat == FORMAT_ASN1)
p8 = d2i_PKCS8_bio(in, NULL);
else {
BIO_printf(bio_err, "Bad format specified for key\n");
return (1);
}
if (!p8) {
BIO_printf (bio_err, "Error reading key\n", outfile);
ERR_print_errors(bio_err);
return (1);
}
if(passin) p8pass = passin;
else {
p8pass = pass;
EVP_read_pw_string(pass, 50, "Enter Password:", 0);
}
p8inf = M_PKCS8_decrypt(p8, p8pass, strlen(p8pass));
X509_SIG_free(p8);
}
if (!p8inf) {
BIO_printf(bio_err, "Error decrypting key\n", outfile);
ERR_print_errors(bio_err);
return (1);
}
if (!(pkey = EVP_PKCS82PKEY(p8inf))) {
BIO_printf(bio_err, "Error converting key\n", outfile);
ERR_print_errors(bio_err);
return (1);
}
if (p8inf->broken) {
BIO_printf(bio_err, "Warning: broken key encoding: ");
switch (p8inf->broken) {
case PKCS8_NO_OCTET:
BIO_printf(bio_err, "No Octet String in PrivateKey\n");
break;
case PKCS8_EMBEDDED_PARAM:
BIO_printf(bio_err, "DSA parameters included in PrivateKey\n");
break;
case PKCS8_NS_DB:
BIO_printf(bio_err, "DSA public key include in PrivateKey\n");
break;
default:
BIO_printf(bio_err, "Unknown broken type\n");
break;
}
}
PKCS8_PRIV_KEY_INFO_free(p8inf);
if(outformat == FORMAT_PEM)
PEM_write_bio_PrivateKey(out, pkey, NULL, NULL, 0, NULL, passout);
else if(outformat == FORMAT_ASN1)
i2d_PrivateKey_bio(out, pkey);
else {
BIO_printf(bio_err, "Bad format specified for key\n");
return (1);
}
EVP_PKEY_free(pkey);
BIO_free(out);
BIO_free(in);
if(passin) Free(passin);
if(passout) Free(passout);
return (0);
}
