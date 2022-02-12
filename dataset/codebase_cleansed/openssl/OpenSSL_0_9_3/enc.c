int main(argc,argv)
int argc;
char *argv[];
{
X509 *x509;
PKCS7 *p7;
BIO *in;
BIO *data,*p7bio;
char buf[1024*4];
int i;
int nodetach=1;
char *keyfile = NULL;
const EVP_CIPHER *cipher;
SSLeay_add_all_algorithms();
data=BIO_new(BIO_s_file());
while(argc > 1)
{
if (strcmp(argv[1],"-nd") == 0)
{
nodetach=1;
argv++; argc--;
}
else if ((strcmp(argv[1],"-c") == 0) && (argc >= 2)) {
if(!(cipher = EVP_get_cipherbyname(argv[2]))) {
fprintf(stderr, "Unknown cipher %s\n", argv[2]);
goto err;
}
argc-=2;
argv+=2;
} else if ((strcmp(argv[1],"-k") == 0) && (argc >= 2)) {
keyfile = argv[2];
argc-=2;
argv+=2;
} else break;
}
if (!BIO_read_filename(data,argv[1])) goto err;
if ((in=BIO_new_file(keyfile,"r")) == NULL) goto err;
if ((x509=PEM_read_bio_X509(in,NULL,NULL)) == NULL) goto err;
p7=PKCS7_new();
#if 0
BIO_reset(in);
if ((pkey=PEM_read_bio_PrivateKey(in,NULL,NULL)) == NULL) goto err;
BIO_free(in);
PKCS7_set_type(p7,NID_pkcs7_signedAndEnveloped);
if (PKCS7_add_signature(p7,x509,pkey,EVP_sha1()) == NULL) goto err;
PKCS7_add_certificate(p7,x509);
#else
PKCS7_set_type(p7,NID_pkcs7_enveloped);
#endif
if(!cipher) cipher = EVP_des_ede3_cbc();
if (!PKCS7_set_cipher(p7,cipher)) goto err;
if (PKCS7_add_recipient(p7,x509) == NULL) goto err;
if ((p7bio=PKCS7_dataInit(p7,NULL)) == NULL) goto err;
for (;;)
{
i=BIO_read(data,buf,sizeof(buf));
if (i <= 0) break;
BIO_write(p7bio,buf,i);
}
BIO_flush(p7bio);
if (!PKCS7_dataFinal(p7,p7bio)) goto err;
BIO_free(p7bio);
PEM_write_PKCS7(stdout,p7);
PKCS7_free(p7);
exit(0);
err:
ERR_load_crypto_strings();
ERR_print_errors_fp(stderr);
exit(1);
}
