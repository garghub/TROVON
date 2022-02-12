int cb(int p, int n)
{
char c='*';
if (p == 0) c='.';
if (p == 1) c='+';
if (p == 2) c='*';
if (p == 3) c='\n';
printf("%c",c);
fflush(stdout);
}
main()
{
int i;
BIGNUM *n;
BN_CTX *ctx;
unsigned char seed_buf[20];
DSA *dsa;
int counter,h;
BIO *bio_err=NULL;
if (bio_err == NULL)
bio_err=BIO_new_fp(stderr,BIO_NOCLOSE);
memcpy(seed_buf,seed,20);
dsa=DSA_generate_parameters(1024,seed,20,&counter,&h,cb);
if (dsa == NULL)
DSA_print(bio_err,dsa,0);
}
