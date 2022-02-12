int MAIN(int argc, char **argv)
{
unsigned char *buf=NULL;
int i,err=0;
const EVP_MD *md=NULL,*m;
BIO *in=NULL,*inp;
BIO *bmd=NULL;
BIO *out = NULL;
const char *name;
#define PROG_NAME_SIZE 16
char pname[PROG_NAME_SIZE];
int separator=0;
int debug=0;
const char *outfile = NULL, *keyfile = NULL;
const char *sigfile = NULL, *randfile = NULL;
char out_bin = -1, want_pub = 0, do_verify = 0;
EVP_PKEY *sigkey = NULL;
unsigned char *sigbuf = NULL;
int siglen = 0;
apps_startup();
if ((buf=(unsigned char *)OPENSSL_malloc(BUFSIZE)) == NULL)
{
BIO_printf(bio_err,"out of memory\n");
goto end;
}
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
program_name(argv[0],pname,PROG_NAME_SIZE);
md=EVP_get_digestbyname(pname);
argc--;
argv++;
while (argc > 0)
{
if ((*argv)[0] != '-') break;
if (strcmp(*argv,"-c") == 0)
separator=1;
else if (strcmp(*argv,"-rand") == 0)
{
if (--argc < 1) break;
randfile=*(++argv);
}
else if (strcmp(*argv,"-out") == 0)
{
if (--argc < 1) break;
outfile=*(++argv);
}
else if (strcmp(*argv,"-sign") == 0)
{
if (--argc < 1) break;
keyfile=*(++argv);
}
else if (strcmp(*argv,"-verify") == 0)
{
if (--argc < 1) break;
keyfile=*(++argv);
want_pub = 1;
do_verify = 1;
}
else if (strcmp(*argv,"-prverify") == 0)
{
if (--argc < 1) break;
keyfile=*(++argv);
do_verify = 1;
}
else if (strcmp(*argv,"-signature") == 0)
{
if (--argc < 1) break;
sigfile=*(++argv);
}
else if (strcmp(*argv,"-hex") == 0)
out_bin = 0;
else if (strcmp(*argv,"-binary") == 0)
out_bin = 1;
else if (strcmp(*argv,"-d") == 0)
debug=1;
else if ((m=EVP_get_digestbyname(&((*argv)[1]))) != NULL)
md=m;
else
break;
argc--;
argv++;
}
if (md == NULL)
md=EVP_md5();
if(do_verify && !sigfile) {
BIO_printf(bio_err, "No signature to verify: use the -signature option\n");
err = 1;
goto end;
}
if ((argc > 0) && (argv[0][0] == '-'))
{
BIO_printf(bio_err,"unknown option '%s'\n",*argv);
BIO_printf(bio_err,"options are\n");
BIO_printf(bio_err,"-c to output the digest with separating colons\n");
BIO_printf(bio_err,"-d to output debug info\n");
BIO_printf(bio_err,"-hex output as hex dump\n");
BIO_printf(bio_err,"-binary output in binary form\n");
BIO_printf(bio_err,"-sign file sign digest using private key in file\n");
BIO_printf(bio_err,"-verify file verify a signature using public key in file\n");
BIO_printf(bio_err,"-prverify file verify a signature using private key in file\n");
BIO_printf(bio_err,"-signature file signature to verify\n");
BIO_printf(bio_err,"-binary output in binary form\n");
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm (default)\n",
LN_md5,LN_md5);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_md4,LN_md4);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_md2,LN_md2);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_sha1,LN_sha1);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_sha,LN_sha);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_mdc2,LN_mdc2);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_ripemd160,LN_ripemd160);
err=1;
goto end;
}
in=BIO_new(BIO_s_file());
bmd=BIO_new(BIO_f_md());
if (debug)
{
BIO_set_callback(in,BIO_debug_callback);
BIO_set_callback_arg(in,bio_err);
}
if ((in == NULL) || (bmd == NULL))
{
ERR_print_errors(bio_err);
goto end;
}
if(out_bin == -1) {
if(keyfile) out_bin = 1;
else out_bin = 0;
}
if(randfile)
app_RAND_load_file(randfile, bio_err, 0);
if(outfile) {
if(out_bin)
out = BIO_new_file(outfile, "wb");
else out = BIO_new_file(outfile, "w");
} else {
out = BIO_new_fp(stdout, BIO_NOCLOSE);
#ifdef VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
}
if(!out) {
BIO_printf(bio_err, "Error opening output file %s\n",
outfile ? outfile : "(stdout)");
ERR_print_errors(bio_err);
goto end;
}
if(keyfile) {
BIO *keybio;
keybio = BIO_new_file(keyfile, "r");
if(!keybio) {
BIO_printf(bio_err, "Error opening key file %s\n",
keyfile);
ERR_print_errors(bio_err);
goto end;
}
if(want_pub)
sigkey = PEM_read_bio_PUBKEY(keybio, NULL, NULL, NULL);
else sigkey = PEM_read_bio_PrivateKey(keybio, NULL, NULL, NULL);
BIO_free(keybio);
if(!sigkey) {
BIO_printf(bio_err, "Error reading key file %s\n",
keyfile);
ERR_print_errors(bio_err);
goto end;
}
}
if(sigfile && sigkey) {
BIO *sigbio;
sigbio = BIO_new_file(sigfile, "rb");
siglen = EVP_PKEY_size(sigkey);
sigbuf = OPENSSL_malloc(siglen);
if(!sigbio) {
BIO_printf(bio_err, "Error opening signature file %s\n",
sigfile);
ERR_print_errors(bio_err);
goto end;
}
siglen = BIO_read(sigbio, sigbuf, siglen);
BIO_free(sigbio);
if(siglen <= 0) {
BIO_printf(bio_err, "Error reading signature file %s\n",
sigfile);
ERR_print_errors(bio_err);
goto end;
}
}
BIO_set_md(bmd,md);
inp=BIO_push(bmd,in);
if (argc == 0)
{
BIO_set_fp(in,stdin,BIO_NOCLOSE);
do_fp(out, buf,inp,separator, out_bin, sigkey, sigbuf, siglen);
}
else
{
name=OBJ_nid2sn(md->type);
for (i=0; i<argc; i++)
{
if (BIO_read_filename(in,argv[i]) <= 0)
{
perror(argv[i]);
err++;
continue;
}
if(!out_bin) BIO_printf(out, "%s(%s)= ",name,argv[i]);
do_fp(out, buf,inp,separator, out_bin, sigkey,
sigbuf, siglen);
(void)BIO_reset(bmd);
}
}
end:
if (buf != NULL)
{
memset(buf,0,BUFSIZE);
OPENSSL_free(buf);
}
if (in != NULL) BIO_free(in);
BIO_free_all(out);
EVP_PKEY_free(sigkey);
if(sigbuf) OPENSSL_free(sigbuf);
if (bmd != NULL) BIO_free(bmd);
EXIT(err);
}
void do_fp(BIO *out, unsigned char *buf, BIO *bp, int sep, char binout,
EVP_PKEY *key, unsigned char *sigin, int siglen)
{
int len;
int i;
for (;;)
{
i=BIO_read(bp,(char *)buf,BUFSIZE);
if (i <= 0) break;
}
if(sigin)
{
EVP_MD_CTX *ctx;
BIO_get_md_ctx(bp, &ctx);
i = EVP_VerifyFinal(ctx, sigin, (unsigned int)siglen, key);
if(i > 0) BIO_printf(out, "Verified OK\n");
else if(i == 0) BIO_printf(out, "Verification Failure\n");
else
{
BIO_printf(bio_err, "Error Verifying Data\n");
ERR_print_errors(bio_err);
}
return;
}
if(key)
{
EVP_MD_CTX *ctx;
BIO_get_md_ctx(bp, &ctx);
if(!EVP_SignFinal(ctx, buf, (unsigned int *)&len, key))
{
BIO_printf(bio_err, "Error Signing Data\n");
ERR_print_errors(bio_err);
return;
}
}
else
len=BIO_gets(bp,(char *)buf,BUFSIZE);
if(binout) BIO_write(out, buf, len);
else
{
for (i=0; i<len; i++)
{
if (sep && (i != 0))
BIO_printf(out, ":");
BIO_printf(out, "%02x",buf[i]);
}
BIO_printf(out, "\n");
}
}
