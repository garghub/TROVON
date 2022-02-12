int MAIN(int argc, char **argv)
{
int i,badops=0,offset=0,ret=1,j;
unsigned int length=0;
long num,tmplen;
BIO *in=NULL,*out=NULL,*b64=NULL, *derout = NULL;
int informat,indent=0, noout = 0, dump = 0;
char *infile=NULL,*str=NULL,*prog,*oidfile=NULL, *derfile=NULL;
unsigned char *tmpbuf;
BUF_MEM *buf=NULL;
STACK *osk=NULL;
ASN1_TYPE *at=NULL;
informat=FORMAT_PEM;
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
prog=argv[0];
argc--;
argv++;
if ((osk=sk_new_null()) == NULL)
{
BIO_printf(bio_err,"Memory allocation failure\n");
goto end;
}
while (argc >= 1)
{
if (strcmp(*argv,"-inform") == 0)
{
if (--argc < 1) goto bad;
informat=str2fmt(*(++argv));
}
else if (strcmp(*argv,"-in") == 0)
{
if (--argc < 1) goto bad;
infile= *(++argv);
}
else if (strcmp(*argv,"-out") == 0)
{
if (--argc < 1) goto bad;
derfile= *(++argv);
}
else if (strcmp(*argv,"-i") == 0)
{
indent=1;
}
else if (strcmp(*argv,"-noout") == 0) noout = 1;
else if (strcmp(*argv,"-oid") == 0)
{
if (--argc < 1) goto bad;
oidfile= *(++argv);
}
else if (strcmp(*argv,"-offset") == 0)
{
if (--argc < 1) goto bad;
offset= atoi(*(++argv));
}
else if (strcmp(*argv,"-length") == 0)
{
if (--argc < 1) goto bad;
length= atoi(*(++argv));
if (length == 0) goto bad;
}
else if (strcmp(*argv,"-dump") == 0)
{
dump= -1;
}
else if (strcmp(*argv,"-dlimit") == 0)
{
if (--argc < 1) goto bad;
dump= atoi(*(++argv));
if (dump <= 0) goto bad;
}
else if (strcmp(*argv,"-strparse") == 0)
{
if (--argc < 1) goto bad;
sk_push(osk,*(++argv));
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
BIO_printf(bio_err,"%s [options] <infile\n",prog);
BIO_printf(bio_err,"where options are\n");
BIO_printf(bio_err," -inform arg input format - one of DER TXT PEM\n");
BIO_printf(bio_err," -in arg input file\n");
BIO_printf(bio_err," -out arg output file\n");
BIO_printf(bio_err," -noout arg don't produce any output\n");
BIO_printf(bio_err," -offset arg offset into file\n");
BIO_printf(bio_err," -length arg length of section in file\n");
BIO_printf(bio_err," -i indent entries\n");
BIO_printf(bio_err," -dump dump unknown data in hex form\n");
BIO_printf(bio_err," -dlimit arg dump the first arg bytes of unknown data in hex form\n");
BIO_printf(bio_err," -oid file file of extra oid definitions\n");
BIO_printf(bio_err," -strparse offset\n");
BIO_printf(bio_err," a series of these can be used to 'dig' into multiple\n");
BIO_printf(bio_err," ASN1 blob wrappings\n");
BIO_printf(bio_err," -out filename output DER encoding to file\n");
goto end;
}
ERR_load_crypto_strings();
in=BIO_new(BIO_s_file());
out=BIO_new(BIO_s_file());
if ((in == NULL) || (out == NULL))
{
ERR_print_errors(bio_err);
goto end;
}
BIO_set_fp(out,stdout,BIO_NOCLOSE|BIO_FP_TEXT);
#ifdef VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
if (oidfile != NULL)
{
if (BIO_read_filename(in,oidfile) <= 0)
{
BIO_printf(bio_err,"problems opening %s\n",oidfile);
ERR_print_errors(bio_err);
goto end;
}
OBJ_create_objects(in);
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
if (derfile) {
if(!(derout = BIO_new_file(derfile, "wb"))) {
BIO_printf(bio_err,"problems opening %s\n",derfile);
ERR_print_errors(bio_err);
goto end;
}
}
if ((buf=BUF_MEM_new()) == NULL) goto end;
if (!BUF_MEM_grow(buf,BUFSIZ*8)) goto end;
if (informat == FORMAT_PEM)
{
BIO *tmp;
if ((b64=BIO_new(BIO_f_base64())) == NULL)
goto end;
BIO_push(b64,in);
tmp=in;
in=b64;
b64=tmp;
}
num=0;
for (;;)
{
if (!BUF_MEM_grow(buf,(int)num+BUFSIZ)) goto end;
i=BIO_read(in,&(buf->data[num]),BUFSIZ);
if (i <= 0) break;
num+=i;
}
str=buf->data;
if (sk_num(osk))
{
tmpbuf=(unsigned char *)str;
tmplen=num;
for (i=0; i<sk_num(osk); i++)
{
ASN1_TYPE *atmp;
j=atoi(sk_value(osk,i));
if (j == 0)
{
BIO_printf(bio_err,"'%s' is an invalid number\n",sk_value(osk,i));
continue;
}
tmpbuf+=j;
tmplen-=j;
atmp = at;
at = d2i_ASN1_TYPE(NULL,&tmpbuf,tmplen);
ASN1_TYPE_free(atmp);
if(!at)
{
BIO_printf(bio_err,"Error parsing structure\n");
ERR_print_errors(bio_err);
goto end;
}
tmpbuf=at->value.asn1_string->data;
tmplen=at->value.asn1_string->length;
}
str=(char *)tmpbuf;
num=tmplen;
}
if (length == 0) length=(unsigned int)num;
if(derout) {
if(BIO_write(derout, str + offset, length) != (int)length) {
BIO_printf(bio_err, "Error writing output\n");
ERR_print_errors(bio_err);
goto end;
}
}
if (!noout &&
!ASN1_parse_dump(out,(unsigned char *)&(str[offset]),length,
indent,dump))
{
ERR_print_errors(bio_err);
goto end;
}
ret=0;
end:
BIO_free(derout);
if (in != NULL) BIO_free(in);
if (out != NULL) BIO_free_all(out);
if (b64 != NULL) BIO_free(b64);
if (ret != 0)
ERR_print_errors(bio_err);
if (buf != NULL) BUF_MEM_free(buf);
if (at != NULL) ASN1_TYPE_free(at);
if (osk != NULL) sk_free(osk);
OBJ_cleanup();
EXIT(ret);
}
