int MAIN(int argc, char **argv)
{
X509_CRL *x=NULL;
char *CAfile = NULL, *CApath = NULL;
int ret=1,i,num,badops=0;
BIO *out=NULL;
int informat,outformat;
char *infile=NULL,*outfile=NULL;
int hash=0,issuer=0,lastupdate=0,nextupdate=0,noout=0,text=0;
int fingerprint = 0;
char **pp,buf[256];
X509_STORE *store = NULL;
X509_STORE_CTX ctx;
X509_LOOKUP *lookup = NULL;
X509_OBJECT xobj;
EVP_PKEY *pkey;
int do_ver = 0;
const EVP_MD *md_alg,*digest=EVP_md5();
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
if (bio_out == NULL)
if ((bio_out=BIO_new(BIO_s_file())) != NULL)
{
BIO_set_fp(bio_out,stdout,BIO_NOCLOSE);
#ifdef VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
bio_out = BIO_push(tmpbio, bio_out);
}
#endif
}
informat=FORMAT_PEM;
outformat=FORMAT_PEM;
argc--;
argv++;
num=0;
while (argc >= 1)
{
#ifdef undef
if (strcmp(*argv,"-p") == 0)
{
if (--argc < 1) goto bad;
if (!args_from_file(++argv,Nargc,Nargv)) { goto end; }*/
}
#endif
if (strcmp(*argv,"-inform") == 0)
{
if (--argc < 1) goto bad;
informat=str2fmt(*(++argv));
}
else if (strcmp(*argv,"-outform") == 0)
{
if (--argc < 1) goto bad;
outformat=str2fmt(*(++argv));
}
else if (strcmp(*argv,"-in") == 0)
{
if (--argc < 1) goto bad;
infile= *(++argv);
}
else if (strcmp(*argv,"-out") == 0)
{
if (--argc < 1) goto bad;
outfile= *(++argv);
}
else if (strcmp(*argv,"-CApath") == 0)
{
if (--argc < 1) goto bad;
CApath = *(++argv);
do_ver = 1;
}
else if (strcmp(*argv,"-CAfile") == 0)
{
if (--argc < 1) goto bad;
CAfile = *(++argv);
do_ver = 1;
}
else if (strcmp(*argv,"-verify") == 0)
do_ver = 1;
else if (strcmp(*argv,"-text") == 0)
text = 1;
else if (strcmp(*argv,"-hash") == 0)
hash= ++num;
else if (strcmp(*argv,"-issuer") == 0)
issuer= ++num;
else if (strcmp(*argv,"-lastupdate") == 0)
lastupdate= ++num;
else if (strcmp(*argv,"-nextupdate") == 0)
nextupdate= ++num;
else if (strcmp(*argv,"-noout") == 0)
noout= ++num;
else if (strcmp(*argv,"-fingerprint") == 0)
fingerprint= ++num;
else if ((md_alg=EVP_get_digestbyname(*argv + 1)))
{
digest=md_alg;
}
else
{
BIO_printf(bio_err,"unknown option %s\n",*argv);
badops=1;
break;
}
argc--;
argv++;
}
if (badops)
{
bad:
for (pp=crl_usage; (*pp != NULL); pp++)
BIO_printf(bio_err,*pp);
goto end;
}
ERR_load_crypto_strings();
x=load_crl(infile,informat);
if (x == NULL) { goto end; }
if(do_ver) {
store = X509_STORE_new();
lookup=X509_STORE_add_lookup(store,X509_LOOKUP_file());
if (lookup == NULL) goto end;
if (!X509_LOOKUP_load_file(lookup,CAfile,X509_FILETYPE_PEM))
X509_LOOKUP_load_file(lookup,NULL,X509_FILETYPE_DEFAULT);
lookup=X509_STORE_add_lookup(store,X509_LOOKUP_hash_dir());
if (lookup == NULL) goto end;
if (!X509_LOOKUP_add_dir(lookup,CApath,X509_FILETYPE_PEM))
X509_LOOKUP_add_dir(lookup,NULL,X509_FILETYPE_DEFAULT);
ERR_clear_error();
X509_STORE_CTX_init(&ctx, store, NULL, NULL);
i = X509_STORE_get_by_subject(&ctx, X509_LU_X509,
X509_CRL_get_issuer(x), &xobj);
if(i <= 0) {
BIO_printf(bio_err,
"Error getting CRL issuer certificate\n");
goto end;
}
pkey = X509_get_pubkey(xobj.data.x509);
X509_OBJECT_free_contents(&xobj);
if(!pkey) {
BIO_printf(bio_err,
"Error getting CRL issuer public key\n");
goto end;
}
i = X509_CRL_verify(x, pkey);
EVP_PKEY_free(pkey);
if(i < 0) goto end;
if(i == 0) BIO_printf(bio_err, "verify failure\n");
else BIO_printf(bio_err, "verify OK\n");
}
if (num)
{
for (i=1; i<=num; i++)
{
if (issuer == i)
{
X509_NAME_oneline(X509_CRL_get_issuer(x),
buf,256);
BIO_printf(bio_out,"issuer= %s\n",buf);
}
if (hash == i)
{
BIO_printf(bio_out,"%08lx\n",
X509_NAME_hash(X509_CRL_get_issuer(x)));
}
if (lastupdate == i)
{
BIO_printf(bio_out,"lastUpdate=");
ASN1_TIME_print(bio_out,
X509_CRL_get_lastUpdate(x));
BIO_printf(bio_out,"\n");
}
if (nextupdate == i)
{
BIO_printf(bio_out,"nextUpdate=");
if (X509_CRL_get_nextUpdate(x))
ASN1_TIME_print(bio_out,
X509_CRL_get_nextUpdate(x));
else
BIO_printf(bio_out,"NONE");
BIO_printf(bio_out,"\n");
}
if (fingerprint == i)
{
int j;
unsigned int n;
unsigned char md[EVP_MAX_MD_SIZE];
if (!X509_CRL_digest(x,digest,md,&n))
{
BIO_printf(bio_err,"out of memory\n");
goto end;
}
BIO_printf(bio_out,"%s Fingerprint=",
OBJ_nid2sn(EVP_MD_type(digest)));
for (j=0; j<(int)n; j++)
{
BIO_printf(bio_out,"%02X%c",md[j],
(j+1 == (int)n)
?'\n':':');
}
}
}
}
out=BIO_new(BIO_s_file());
if (out == NULL)
{
ERR_print_errors(bio_err);
goto end;
}
if (outfile == NULL)
{
BIO_set_fp(out,stdout,BIO_NOCLOSE);
#ifdef VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
}
else
{
if (BIO_write_filename(out,outfile) <= 0)
{
perror(outfile);
goto end;
}
}
if (text) X509_CRL_print(out, x);
if (noout) goto end;
if (outformat == FORMAT_ASN1)
i=(int)i2d_X509_CRL_bio(out,x);
else if (outformat == FORMAT_PEM)
i=PEM_write_bio_X509_CRL(out,x);
else
{
BIO_printf(bio_err,"bad output format specified for outfile\n");
goto end;
}
if (!i) { BIO_printf(bio_err,"unable to write CRL\n"); goto end; }
ret=0;
end:
BIO_free_all(out);
BIO_free_all(bio_out);
bio_out=NULL;
X509_CRL_free(x);
if(store) {
X509_STORE_CTX_cleanup(&ctx);
X509_STORE_free(store);
}
EXIT(ret);
}
static X509_CRL *load_crl(char *infile, int format)
{
X509_CRL *x=NULL;
BIO *in=NULL;
in=BIO_new(BIO_s_file());
if (in == NULL)
{
ERR_print_errors(bio_err);
goto end;
}
if (infile == NULL)
BIO_set_fp(in,stdin,BIO_NOCLOSE);
else
{
if (BIO_read_filename(in,infile) <= 0)
{
perror(infile);
goto end;
}
}
if (format == FORMAT_ASN1)
x=d2i_X509_CRL_bio(in,NULL);
else if (format == FORMAT_PEM)
x=PEM_read_bio_X509_CRL(in,NULL,NULL,NULL);
else {
BIO_printf(bio_err,"bad input format specified for input crl\n");
goto end;
}
if (x == NULL)
{
BIO_printf(bio_err,"unable to load CRL\n");
ERR_print_errors(bio_err);
goto end;
}
end:
BIO_free(in);
return(x);
}
