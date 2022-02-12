int MAIN(int argc, char **argv)
{
char *key=NULL,*passargin=NULL;
int total=0;
int total_done=0;
int badops=0;
int ret=1;
int req=0;
int verbose=0;
int gencrl=0;
int dorevoke=0;
long crldays=0;
long crlhours=0;
long errorline= -1;
char *configfile=NULL;
char *md=NULL;
char *policy=NULL;
char *keyfile=NULL;
char *certfile=NULL;
char *infile=NULL;
char *spkac_file=NULL;
char *ss_cert_file=NULL;
EVP_PKEY *pkey=NULL;
int output_der = 0;
char *outfile=NULL;
char *outdir=NULL;
char *serialfile=NULL;
char *extensions=NULL;
char *crl_ext=NULL;
BIGNUM *serial=NULL;
char *startdate=NULL;
char *enddate=NULL;
int days=0;
int batch=0;
int notext=0;
X509 *x509=NULL;
X509 *x=NULL;
BIO *in=NULL,*out=NULL,*Sout=NULL,*Cout=NULL;
char *dbfile=NULL;
TXT_DB *db=NULL;
X509_CRL *crl=NULL;
X509_CRL_INFO *ci=NULL;
X509_REVOKED *r=NULL;
char **pp,*p,*f;
int i,j;
long l;
const EVP_MD *dgst=NULL;
STACK_OF(CONF_VALUE) *attribs=NULL;
STACK_OF(X509) *cert_sk=NULL;
BIO *hex=NULL;
#undef BSIZE
#define BSIZE 256
MS_STATIC char buf[3][BSIZE];
char *randfile=NULL;
#ifdef EFENCE
EF_PROTECT_FREE=1;
EF_PROTECT_BELOW=1;
EF_ALIGNMENT=0;
#endif
apps_startup();
conf = NULL;
key = NULL;
section = NULL;
preserve=0;
msie_hack=0;
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
argc--;
argv++;
while (argc >= 1)
{
if (strcmp(*argv,"-verbose") == 0)
verbose=1;
else if (strcmp(*argv,"-config") == 0)
{
if (--argc < 1) goto bad;
configfile= *(++argv);
}
else if (strcmp(*argv,"-name") == 0)
{
if (--argc < 1) goto bad;
section= *(++argv);
}
else if (strcmp(*argv,"-startdate") == 0)
{
if (--argc < 1) goto bad;
startdate= *(++argv);
}
else if (strcmp(*argv,"-enddate") == 0)
{
if (--argc < 1) goto bad;
enddate= *(++argv);
}
else if (strcmp(*argv,"-days") == 0)
{
if (--argc < 1) goto bad;
days=atoi(*(++argv));
}
else if (strcmp(*argv,"-md") == 0)
{
if (--argc < 1) goto bad;
md= *(++argv);
}
else if (strcmp(*argv,"-policy") == 0)
{
if (--argc < 1) goto bad;
policy= *(++argv);
}
else if (strcmp(*argv,"-keyfile") == 0)
{
if (--argc < 1) goto bad;
keyfile= *(++argv);
}
else if (strcmp(*argv,"-passin") == 0)
{
if (--argc < 1) goto bad;
passargin= *(++argv);
}
else if (strcmp(*argv,"-key") == 0)
{
if (--argc < 1) goto bad;
key= *(++argv);
}
else if (strcmp(*argv,"-cert") == 0)
{
if (--argc < 1) goto bad;
certfile= *(++argv);
}
else if (strcmp(*argv,"-in") == 0)
{
if (--argc < 1) goto bad;
infile= *(++argv);
req=1;
}
else if (strcmp(*argv,"-out") == 0)
{
if (--argc < 1) goto bad;
outfile= *(++argv);
}
else if (strcmp(*argv,"-outdir") == 0)
{
if (--argc < 1) goto bad;
outdir= *(++argv);
}
else if (strcmp(*argv,"-notext") == 0)
notext=1;
else if (strcmp(*argv,"-batch") == 0)
batch=1;
else if (strcmp(*argv,"-preserveDN") == 0)
preserve=1;
else if (strcmp(*argv,"-gencrl") == 0)
gencrl=1;
else if (strcmp(*argv,"-msie_hack") == 0)
msie_hack=1;
else if (strcmp(*argv,"-crldays") == 0)
{
if (--argc < 1) goto bad;
crldays= atol(*(++argv));
}
else if (strcmp(*argv,"-crlhours") == 0)
{
if (--argc < 1) goto bad;
crlhours= atol(*(++argv));
}
else if (strcmp(*argv,"-infiles") == 0)
{
argc--;
argv++;
req=1;
break;
}
else if (strcmp(*argv, "-ss_cert") == 0)
{
if (--argc < 1) goto bad;
ss_cert_file = *(++argv);
req=1;
}
else if (strcmp(*argv, "-spkac") == 0)
{
if (--argc < 1) goto bad;
spkac_file = *(++argv);
req=1;
}
else if (strcmp(*argv,"-revoke") == 0)
{
if (--argc < 1) goto bad;
infile= *(++argv);
dorevoke=1;
}
else if (strcmp(*argv,"-extensions") == 0)
{
if (--argc < 1) goto bad;
extensions= *(++argv);
}
else if (strcmp(*argv,"-crlexts") == 0)
{
if (--argc < 1) goto bad;
crl_ext= *(++argv);
}
else
{
bad:
BIO_printf(bio_err,"unknown option %s\n",*argv);
badops=1;
break;
}
argc--;
argv++;
}
if (badops)
{
for (pp=ca_usage; (*pp != NULL); pp++)
BIO_printf(bio_err,*pp);
goto err;
}
ERR_load_crypto_strings();
if (configfile == NULL) configfile = getenv("OPENSSL_CONF");
if (configfile == NULL) configfile = getenv("SSLEAY_CONF");
if (configfile == NULL)
{
#ifdef VMS
strncpy(buf[0],X509_get_default_cert_area(),
sizeof(buf[0])-1-sizeof(CONFIG_FILE));
#else
strncpy(buf[0],X509_get_default_cert_area(),
sizeof(buf[0])-2-sizeof(CONFIG_FILE));
strcat(buf[0],"/");
#endif
strcat(buf[0],CONFIG_FILE);
configfile=buf[0];
}
BIO_printf(bio_err,"Using configuration from %s\n",configfile);
if ((conf=CONF_load(NULL,configfile,&errorline)) == NULL)
{
if (errorline <= 0)
BIO_printf(bio_err,"error loading the config file '%s'\n",
configfile);
else
BIO_printf(bio_err,"error on line %ld of config file '%s'\n"
,errorline,configfile);
goto err;
}
if (section == NULL)
{
section=CONF_get_string(conf,BASE_SECTION,ENV_DEFAULT_CA);
if (section == NULL)
{
lookup_fail(BASE_SECTION,ENV_DEFAULT_CA);
goto err;
}
}
if (conf != NULL)
{
p=CONF_get_string(conf,NULL,"oid_file");
if (p != NULL)
{
BIO *oid_bio;
oid_bio=BIO_new_file(p,"r");
if (oid_bio == NULL)
{
ERR_clear_error();
}
else
{
OBJ_create_objects(oid_bio);
BIO_free(oid_bio);
}
}
if(!add_oid_section(bio_err,conf))
{
ERR_print_errors(bio_err);
goto err;
}
}
randfile = CONF_get_string(conf, BASE_SECTION, "RANDFILE");
app_RAND_load_file(randfile, bio_err, 0);
in=BIO_new(BIO_s_file());
out=BIO_new(BIO_s_file());
Sout=BIO_new(BIO_s_file());
Cout=BIO_new(BIO_s_file());
if ((in == NULL) || (out == NULL) || (Sout == NULL) || (Cout == NULL))
{
ERR_print_errors(bio_err);
goto err;
}
if ((keyfile == NULL) && ((keyfile=CONF_get_string(conf,
section,ENV_PRIVATE_KEY)) == NULL))
{
lookup_fail(section,ENV_PRIVATE_KEY);
goto err;
}
if(!key && !app_passwd(bio_err, passargin, NULL, &key, NULL))
{
BIO_printf(bio_err,"Error getting password\n");
goto err;
}
if (BIO_read_filename(in,keyfile) <= 0)
{
perror(keyfile);
BIO_printf(bio_err,"trying to load CA private key\n");
goto err;
}
pkey=PEM_read_bio_PrivateKey(in,NULL,NULL,key);
if(key) memset(key,0,strlen(key));
if (pkey == NULL)
{
BIO_printf(bio_err,"unable to load CA private key\n");
goto err;
}
if ((certfile == NULL) && ((certfile=CONF_get_string(conf,
section,ENV_CERTIFICATE)) == NULL))
{
lookup_fail(section,ENV_CERTIFICATE);
goto err;
}
if (BIO_read_filename(in,certfile) <= 0)
{
perror(certfile);
BIO_printf(bio_err,"trying to load CA certificate\n");
goto err;
}
x509=PEM_read_bio_X509(in,NULL,NULL,NULL);
if (x509 == NULL)
{
BIO_printf(bio_err,"unable to load CA certificate\n");
goto err;
}
if (!X509_check_private_key(x509,pkey))
{
BIO_printf(bio_err,"CA certificate and CA private key do not match\n");
goto err;
}
f=CONF_get_string(conf,BASE_SECTION,ENV_PRESERVE);
if ((f != NULL) && ((*f == 'y') || (*f == 'Y')))
preserve=1;
f=CONF_get_string(conf,BASE_SECTION,ENV_MSIE_HACK);
if ((f != NULL) && ((*f == 'y') || (*f == 'Y')))
msie_hack=1;
if ((outdir == NULL) && (req))
{
struct stat sb;
if ((outdir=CONF_get_string(conf,section,ENV_NEW_CERTS_DIR))
== NULL)
{
BIO_printf(bio_err,"there needs to be defined a directory for new certificate to be placed in\n");
goto err;
}
#ifndef VMS
if (access(outdir,R_OK|W_OK|X_OK) != 0)
{
BIO_printf(bio_err,"I am unable to access the %s directory\n",outdir);
perror(outdir);
goto err;
}
if (stat(outdir,&sb) != 0)
{
BIO_printf(bio_err,"unable to stat(%s)\n",outdir);
perror(outdir);
goto err;
}
#ifdef S_IFDIR
if (!(sb.st_mode & S_IFDIR))
{
BIO_printf(bio_err,"%s need to be a directory\n",outdir);
perror(outdir);
goto err;
}
#endif
#endif
}
if ((dbfile=CONF_get_string(conf,section,ENV_DATABASE)) == NULL)
{
lookup_fail(section,ENV_DATABASE);
goto err;
}
if (BIO_read_filename(in,dbfile) <= 0)
{
perror(dbfile);
BIO_printf(bio_err,"unable to open '%s'\n",dbfile);
goto err;
}
db=TXT_DB_read(in,DB_NUMBER);
if (db == NULL) goto err;
for (i=0; i<sk_num(db->data); i++)
{
pp=(char **)sk_value(db->data,i);
if ((pp[DB_type][0] != DB_TYPE_REV) &&
(pp[DB_rev_date][0] != '\0'))
{
BIO_printf(bio_err,"entry %d: not revoked yet, but has a revocation date\n",i+1);
goto err;
}
if ((pp[DB_type][0] == DB_TYPE_REV) &&
!check_time_format(pp[DB_rev_date]))
{
BIO_printf(bio_err,"entry %d: invalid revocation date\n",
i+1);
goto err;
}
if (!check_time_format(pp[DB_exp_date]))
{
BIO_printf(bio_err,"entry %d: invalid expiry date\n",i+1);
goto err;
}
p=pp[DB_serial];
j=strlen(p);
if ((j&1) || (j < 2))
{
BIO_printf(bio_err,"entry %d: bad serial number length (%d)\n",i+1,j);
goto err;
}
while (*p)
{
if (!( ((*p >= '0') && (*p <= '9')) ||
((*p >= 'A') && (*p <= 'F')) ||
((*p >= 'a') && (*p <= 'f'))) )
{
BIO_printf(bio_err,"entry %d: bad serial number characters, char pos %ld, char is '%c'\n",i+1,(long)(p-pp[DB_serial]),*p);
goto err;
}
p++;
}
}
if (verbose)
{
BIO_set_fp(out,stdout,BIO_NOCLOSE|BIO_FP_TEXT);
#ifdef VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
TXT_DB_write(out,db);
BIO_printf(bio_err,"%d entries loaded from the database\n",
db->data->num);
BIO_printf(bio_err,"generating index\n");
}
if (!TXT_DB_create_index(db,DB_serial,NULL,index_serial_hash,
index_serial_cmp))
{
BIO_printf(bio_err,"error creating serial number index:(%ld,%ld,%ld)\n",db->error,db->arg1,db->arg2);
goto err;
}
if (!TXT_DB_create_index(db,DB_name,index_name_qual,index_name_hash,
index_name_cmp))
{
BIO_printf(bio_err,"error creating name index:(%ld,%ld,%ld)\n",
db->error,db->arg1,db->arg2);
goto err;
}
if (req || gencrl)
{
if (outfile != NULL)
{
if (BIO_write_filename(Sout,outfile) <= 0)
{
perror(outfile);
goto err;
}
}
else
{
BIO_set_fp(Sout,stdout,BIO_NOCLOSE|BIO_FP_TEXT);
#ifdef VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
Sout = BIO_push(tmpbio, Sout);
}
#endif
}
}
if (req)
{
if ((md == NULL) && ((md=CONF_get_string(conf,
section,ENV_DEFAULT_MD)) == NULL))
{
lookup_fail(section,ENV_DEFAULT_MD);
goto err;
}
if ((dgst=EVP_get_digestbyname(md)) == NULL)
{
BIO_printf(bio_err,"%s is an unsupported message digest type\n",md);
goto err;
}
if (verbose)
BIO_printf(bio_err,"message digest is %s\n",
OBJ_nid2ln(dgst->type));
if ((policy == NULL) && ((policy=CONF_get_string(conf,
section,ENV_POLICY)) == NULL))
{
lookup_fail(section,ENV_POLICY);
goto err;
}
if (verbose)
BIO_printf(bio_err,"policy is %s\n",policy);
if ((serialfile=CONF_get_string(conf,section,ENV_SERIAL))
== NULL)
{
lookup_fail(section,ENV_SERIAL);
goto err;
}
if(!extensions)
extensions=CONF_get_string(conf,section,ENV_EXTENSIONS);
if(extensions) {
X509V3_CTX ctx;
X509V3_set_ctx_test(&ctx);
X509V3_set_conf_lhash(&ctx, conf);
if(!X509V3_EXT_add_conf(conf, &ctx, extensions, NULL)) {
BIO_printf(bio_err,
"Error Loading extension section %s\n",
extensions);
ret = 1;
goto err;
}
}
if (startdate == NULL)
{
startdate=CONF_get_string(conf,section,
ENV_DEFAULT_STARTDATE);
}
if (startdate && !ASN1_UTCTIME_set_string(NULL,startdate))
{
BIO_printf(bio_err,"start date is invalid, it should be YYMMDDHHMMSSZ\n");
goto err;
}
if (startdate == NULL) startdate="today";
if (enddate == NULL)
{
enddate=CONF_get_string(conf,section,
ENV_DEFAULT_ENDDATE);
}
if (enddate && !ASN1_UTCTIME_set_string(NULL,enddate))
{
BIO_printf(bio_err,"end date is invalid, it should be YYMMDDHHMMSSZ\n");
goto err;
}
if (days == 0)
{
days=(int)CONF_get_number(conf,section,
ENV_DEFAULT_DAYS);
}
if (!enddate && (days == 0))
{
BIO_printf(bio_err,"cannot lookup how many days to certify for\n");
goto err;
}
if ((serial=load_serial(serialfile)) == NULL)
{
BIO_printf(bio_err,"error while loading serial number\n");
goto err;
}
if (verbose)
{
if ((f=BN_bn2hex(serial)) == NULL) goto err;
BIO_printf(bio_err,"next serial number is %s\n",f);
OPENSSL_free(f);
}
if ((attribs=CONF_get_section(conf,policy)) == NULL)
{
BIO_printf(bio_err,"unable to find 'section' for %s\n",policy);
goto err;
}
if ((cert_sk=sk_X509_new_null()) == NULL)
{
BIO_printf(bio_err,"Memory allocation failure\n");
goto err;
}
if (spkac_file != NULL)
{
total++;
j=certify_spkac(&x,spkac_file,pkey,x509,dgst,attribs,db,
serial,startdate,enddate, days,extensions,conf,
verbose);
if (j < 0) goto err;
if (j > 0)
{
total_done++;
BIO_printf(bio_err,"\n");
if (!BN_add_word(serial,1)) goto err;
if (!sk_X509_push(cert_sk,x))
{
BIO_printf(bio_err,"Memory allocation failure\n");
goto err;
}
if (outfile)
{
output_der = 1;
batch = 1;
}
}
}
if (ss_cert_file != NULL)
{
total++;
j=certify_cert(&x,ss_cert_file,pkey,x509,dgst,attribs,
db,serial,startdate,enddate,days,batch,
extensions,conf,verbose);
if (j < 0) goto err;
if (j > 0)
{
total_done++;
BIO_printf(bio_err,"\n");
if (!BN_add_word(serial,1)) goto err;
if (!sk_X509_push(cert_sk,x))
{
BIO_printf(bio_err,"Memory allocation failure\n");
goto err;
}
}
}
if (infile != NULL)
{
total++;
j=certify(&x,infile,pkey,x509,dgst,attribs,db,
serial,startdate,enddate,days,batch,
extensions,conf,verbose);
if (j < 0) goto err;
if (j > 0)
{
total_done++;
BIO_printf(bio_err,"\n");
if (!BN_add_word(serial,1)) goto err;
if (!sk_X509_push(cert_sk,x))
{
BIO_printf(bio_err,"Memory allocation failure\n");
goto err;
}
}
}
for (i=0; i<argc; i++)
{
total++;
j=certify(&x,argv[i],pkey,x509,dgst,attribs,db,
serial,startdate,enddate,days,batch,
extensions,conf,verbose);
if (j < 0) goto err;
if (j > 0)
{
total_done++;
BIO_printf(bio_err,"\n");
if (!BN_add_word(serial,1)) goto err;
if (!sk_X509_push(cert_sk,x))
{
BIO_printf(bio_err,"Memory allocation failure\n");
goto err;
}
}
}
if (sk_X509_num(cert_sk) > 0)
{
if (!batch)
{
BIO_printf(bio_err,"\n%d out of %d certificate requests certified, commit? [y/n]",total_done,total);
(void)BIO_flush(bio_err);
buf[0][0]='\0';
fgets(buf[0],10,stdin);
if ((buf[0][0] != 'y') && (buf[0][0] != 'Y'))
{
BIO_printf(bio_err,"CERTIFICATION CANCELED\n");
ret=0;
goto err;
}
}
BIO_printf(bio_err,"Write out database with %d new entries\n",sk_X509_num(cert_sk));
strncpy(buf[0],serialfile,BSIZE-4);
#ifdef VMS
strcat(buf[0],"-new");
#else
strcat(buf[0],".new");
#endif
if (!save_serial(buf[0],serial)) goto err;
strncpy(buf[1],dbfile,BSIZE-4);
#ifdef VMS
strcat(buf[1],"-new");
#else
strcat(buf[1],".new");
#endif
if (BIO_write_filename(out,buf[1]) <= 0)
{
perror(dbfile);
BIO_printf(bio_err,"unable to open '%s'\n",dbfile);
goto err;
}
l=TXT_DB_write(out,db);
if (l <= 0) goto err;
}
if (verbose)
BIO_printf(bio_err,"writing new certificates\n");
for (i=0; i<sk_X509_num(cert_sk); i++)
{
int k;
unsigned char *n;
x=sk_X509_value(cert_sk,i);
j=x->cert_info->serialNumber->length;
p=(char *)x->cert_info->serialNumber->data;
strncpy(buf[2],outdir,BSIZE-(j*2)-6);
#ifndef VMS
strcat(buf[2],"/");
#endif
n=(unsigned char *)&(buf[2][strlen(buf[2])]);
if (j > 0)
{
for (k=0; k<j; k++)
{
sprintf((char *)n,"%02X",(unsigned char)*(p++));
n+=2;
}
}
else
{
*(n++)='0';
*(n++)='0';
}
*(n++)='.'; *(n++)='p'; *(n++)='e'; *(n++)='m';
*n='\0';
if (verbose)
BIO_printf(bio_err,"writing %s\n",buf[2]);
if (BIO_write_filename(Cout,buf[2]) <= 0)
{
perror(buf[2]);
goto err;
}
write_new_certificate(Cout,x, 0, notext);
write_new_certificate(Sout,x, output_der, notext);
}
if (sk_X509_num(cert_sk))
{
strncpy(buf[2],serialfile,BSIZE-4);
#ifdef VMS
strcat(buf[2],"-old");
#else
strcat(buf[2],".old");
#endif
BIO_free(in);
BIO_free_all(out);
in=NULL;
out=NULL;
if (rename(serialfile,buf[2]) < 0)
{
BIO_printf(bio_err,"unable to rename %s to %s\n",
serialfile,buf[2]);
perror("reason");
goto err;
}
if (rename(buf[0],serialfile) < 0)
{
BIO_printf(bio_err,"unable to rename %s to %s\n",
buf[0],serialfile);
perror("reason");
rename(buf[2],serialfile);
goto err;
}
strncpy(buf[2],dbfile,BSIZE-4);
#ifdef VMS
strcat(buf[2],"-old");
#else
strcat(buf[2],".old");
#endif
if (rename(dbfile,buf[2]) < 0)
{
BIO_printf(bio_err,"unable to rename %s to %s\n",
dbfile,buf[2]);
perror("reason");
goto err;
}
if (rename(buf[1],dbfile) < 0)
{
BIO_printf(bio_err,"unable to rename %s to %s\n",
buf[1],dbfile);
perror("reason");
rename(buf[2],dbfile);
goto err;
}
BIO_printf(bio_err,"Data Base Updated\n");
}
}
if (gencrl)
{
if(!crl_ext) crl_ext=CONF_get_string(conf,section,ENV_CRLEXT);
if(crl_ext) {
X509V3_CTX ctx;
X509V3_set_ctx_test(&ctx);
X509V3_set_conf_lhash(&ctx, conf);
if(!X509V3_EXT_add_conf(conf, &ctx, crl_ext, NULL)) {
BIO_printf(bio_err,
"Error Loading CRL extension section %s\n",
crl_ext);
ret = 1;
goto err;
}
}
if ((hex=BIO_new(BIO_s_mem())) == NULL) goto err;
if (!crldays && !crlhours)
{
crldays=CONF_get_number(conf,section,
ENV_DEFAULT_CRL_DAYS);
crlhours=CONF_get_number(conf,section,
ENV_DEFAULT_CRL_HOURS);
}
if ((crldays == 0) && (crlhours == 0))
{
BIO_printf(bio_err,"cannot lookup how long until the next CRL is issuer\n");
goto err;
}
if (verbose) BIO_printf(bio_err,"making CRL\n");
if ((crl=X509_CRL_new()) == NULL) goto err;
ci=crl->crl;
X509_NAME_free(ci->issuer);
ci->issuer=X509_NAME_dup(x509->cert_info->subject);
if (ci->issuer == NULL) goto err;
X509_gmtime_adj(ci->lastUpdate,0);
if (ci->nextUpdate == NULL)
ci->nextUpdate=ASN1_UTCTIME_new();
X509_gmtime_adj(ci->nextUpdate,(crldays*24+crlhours)*60*60);
for (i=0; i<sk_num(db->data); i++)
{
pp=(char **)sk_value(db->data,i);
if (pp[DB_type][0] == DB_TYPE_REV)
{
if ((r=X509_REVOKED_new()) == NULL) goto err;
ASN1_STRING_set((ASN1_STRING *)
r->revocationDate,
(unsigned char *)pp[DB_rev_date],
strlen(pp[DB_rev_date]));
(void)BIO_reset(hex);
if (!BIO_puts(hex,pp[DB_serial]))
goto err;
if (!a2i_ASN1_INTEGER(hex,r->serialNumber,
buf[0],BSIZE)) goto err;
sk_X509_REVOKED_push(ci->revoked,r);
}
}
sk_X509_REVOKED_sort(ci->revoked);
for (i=0; i<sk_X509_REVOKED_num(ci->revoked); i++)
{
r=sk_X509_REVOKED_value(ci->revoked,i);
r->sequence=i;
}
if (verbose) BIO_printf(bio_err,"signing CRL\n");
if (md != NULL)
{
if ((dgst=EVP_get_digestbyname(md)) == NULL)
{
BIO_printf(bio_err,"%s is an unsupported message digest type\n",md);
goto err;
}
}
else
{
#ifndef NO_DSA
if (pkey->type == EVP_PKEY_DSA)
dgst=EVP_dss1();
else
#endif
dgst=EVP_md5();
}
if(crl_ext) {
X509V3_CTX crlctx;
if (ci->version == NULL)
if ((ci->version=ASN1_INTEGER_new()) == NULL) goto err;
ASN1_INTEGER_set(ci->version,1);
X509V3_set_ctx(&crlctx, x509, NULL, NULL, crl, 0);
X509V3_set_conf_lhash(&crlctx, conf);
if(!X509V3_EXT_CRL_add_conf(conf, &crlctx,
crl_ext, crl)) goto err;
}
if (!X509_CRL_sign(crl,pkey,dgst)) goto err;
PEM_write_bio_X509_CRL(Sout,crl);
}
if (dorevoke)
{
if (infile == NULL)
{
BIO_printf(bio_err,"no input files\n");
goto err;
}
else
{
X509 *revcert;
if (BIO_read_filename(in,infile) <= 0)
{
perror(infile);
BIO_printf(bio_err,"error trying to load '%s' certificate\n",infile);
goto err;
}
revcert=PEM_read_bio_X509(in,NULL,NULL,NULL);
if (revcert == NULL)
{
BIO_printf(bio_err,"unable to load '%s' certificate\n",infile);
goto err;
}
j=do_revoke(revcert,db);
if (j <= 0) goto err;
X509_free(revcert);
strncpy(buf[0],dbfile,BSIZE-4);
strcat(buf[0],".new");
if (BIO_write_filename(out,buf[0]) <= 0)
{
perror(dbfile);
BIO_printf(bio_err,"unable to open '%s'\n",dbfile);
goto err;
}
j=TXT_DB_write(out,db);
if (j <= 0) goto err;
strncpy(buf[1],dbfile,BSIZE-4);
strcat(buf[1],".old");
if (rename(dbfile,buf[1]) < 0)
{
BIO_printf(bio_err,"unable to rename %s to %s\n", dbfile, buf[1]);
perror("reason");
goto err;
}
if (rename(buf[0],dbfile) < 0)
{
BIO_printf(bio_err,"unable to rename %s to %s\n", buf[0],dbfile);
perror("reason");
rename(buf[1],dbfile);
goto err;
}
BIO_printf(bio_err,"Data Base Updated\n");
}
}
ret=0;
err:
BIO_free(hex);
BIO_free_all(Cout);
BIO_free_all(Sout);
BIO_free_all(out);
BIO_free(in);
sk_X509_pop_free(cert_sk,X509_free);
if (ret) ERR_print_errors(bio_err);
app_RAND_write_file(randfile, bio_err);
BN_free(serial);
TXT_DB_free(db);
EVP_PKEY_free(pkey);
X509_free(x509);
X509_CRL_free(crl);
CONF_free(conf);
OBJ_cleanup();
EXIT(ret);
}
static void lookup_fail(char *name, char *tag)
{
BIO_printf(bio_err,"variable lookup failed for %s::%s\n",name,tag);
}
static unsigned long index_serial_hash(char **a)
{
char *n;
n=a[DB_serial];
while (*n == '0') n++;
return(lh_strhash(n));
}
static int index_serial_cmp(char **a, char **b)
{
char *aa,*bb;
for (aa=a[DB_serial]; *aa == '0'; aa++);
for (bb=b[DB_serial]; *bb == '0'; bb++);
return(strcmp(aa,bb));
}
static unsigned long index_name_hash(char **a)
{ return(lh_strhash(a[DB_name])); }
static int index_name_qual(char **a)
{ return(a[0][0] == 'V'); }
static int index_name_cmp(char **a, char **b)
{ return(strcmp(a[DB_name],
b[DB_name])); }
static BIGNUM *load_serial(char *serialfile)
{
BIO *in=NULL;
BIGNUM *ret=NULL;
MS_STATIC char buf[1024];
ASN1_INTEGER *ai=NULL;
if ((in=BIO_new(BIO_s_file())) == NULL)
{
ERR_print_errors(bio_err);
goto err;
}
if (BIO_read_filename(in,serialfile) <= 0)
{
perror(serialfile);
goto err;
}
ai=ASN1_INTEGER_new();
if (ai == NULL) goto err;
if (!a2i_ASN1_INTEGER(in,ai,buf,1024))
{
BIO_printf(bio_err,"unable to load number from %s\n",
serialfile);
goto err;
}
ret=ASN1_INTEGER_to_BN(ai,NULL);
if (ret == NULL)
{
BIO_printf(bio_err,"error converting number from bin to BIGNUM");
goto err;
}
err:
if (in != NULL) BIO_free(in);
if (ai != NULL) ASN1_INTEGER_free(ai);
return(ret);
}
static int save_serial(char *serialfile, BIGNUM *serial)
{
BIO *out;
int ret=0;
ASN1_INTEGER *ai=NULL;
out=BIO_new(BIO_s_file());
if (out == NULL)
{
ERR_print_errors(bio_err);
goto err;
}
if (BIO_write_filename(out,serialfile) <= 0)
{
perror(serialfile);
goto err;
}
if ((ai=BN_to_ASN1_INTEGER(serial,NULL)) == NULL)
{
BIO_printf(bio_err,"error converting serial to ASN.1 format\n");
goto err;
}
i2a_ASN1_INTEGER(out,ai);
BIO_puts(out,"\n");
ret=1;
err:
if (out != NULL) BIO_free_all(out);
if (ai != NULL) ASN1_INTEGER_free(ai);
return(ret);
}
static void write_new_certificate(BIO *bp, X509 *x, int output_der, int notext)
{
if (output_der)
{
(void)i2d_X509_bio(bp,x);
return;
}
#if 0
f=X509_NAME_oneline(X509_get_issuer_name(x),buf,256);
BIO_printf(bp,"issuer :%s\n",f);
f=X509_NAME_oneline(X509_get_subject_name(x),buf,256);
BIO_printf(bp,"subject:%s\n",f);
BIO_puts(bp,"serial :");
i2a_ASN1_INTEGER(bp,x->cert_info->serialNumber);
BIO_puts(bp,"\n\n");
#endif
if(!notext)X509_print(bp,x);
PEM_write_bio_X509(bp,x);
}
static int fix_data(int nid, int *type)
{
if (nid == NID_pkcs9_emailAddress)
*type=V_ASN1_IA5STRING;
if ((nid == NID_commonName) && (*type == V_ASN1_IA5STRING))
*type=V_ASN1_T61STRING;
if ((nid == NID_pkcs9_challengePassword) && (*type == V_ASN1_IA5STRING))
*type=V_ASN1_T61STRING;
if ((nid == NID_pkcs9_unstructuredName) && (*type == V_ASN1_T61STRING))
return(0);
if (nid == NID_pkcs9_unstructuredName)
*type=V_ASN1_IA5STRING;
return(1);
}
static int check_time_format(char *str)
{
ASN1_UTCTIME tm;
tm.data=(unsigned char *)str;
tm.length=strlen(str);
tm.type=V_ASN1_UTCTIME;
return(ASN1_UTCTIME_check(&tm));
}
static int do_revoke(X509 *x509, TXT_DB *db)
{
ASN1_UTCTIME *tm=NULL, *revtm=NULL;
char *row[DB_NUMBER],**rrow,**irow;
BIGNUM *bn = NULL;
int ok=-1,i;
for (i=0; i<DB_NUMBER; i++)
row[i]=NULL;
row[DB_name]=X509_NAME_oneline(X509_get_subject_name(x509),NULL,0);
bn = ASN1_INTEGER_to_BN(X509_get_serialNumber(x509),NULL);
row[DB_serial]=BN_bn2hex(bn);
BN_free(bn);
if ((row[DB_name] == NULL) || (row[DB_serial] == NULL))
{
BIO_printf(bio_err,"Memory allocation failure\n");
goto err;
}
rrow=TXT_DB_get_by_index(db,DB_serial,row);
if (rrow == NULL)
{
BIO_printf(bio_err,"Adding Entry to DB for %s\n", row[DB_name]);
row[DB_type]=(char *)OPENSSL_malloc(2);
tm=X509_get_notAfter(x509);
row[DB_exp_date]=(char *)OPENSSL_malloc(tm->length+1);
memcpy(row[DB_exp_date],tm->data,tm->length);
row[DB_exp_date][tm->length]='\0';
row[DB_rev_date]=NULL;
row[DB_file]=(char *)OPENSSL_malloc(8);
if ((row[DB_type] == NULL) || (row[DB_exp_date] == NULL) ||
(row[DB_file] == NULL))
{
BIO_printf(bio_err,"Memory allocation failure\n");
goto err;
}
strcpy(row[DB_file],"unknown");
row[DB_type][0]='V';
row[DB_type][1]='\0';
if ((irow=(char **)OPENSSL_malloc(sizeof(char *)*(DB_NUMBER+1))) == NULL)
{
BIO_printf(bio_err,"Memory allocation failure\n");
goto err;
}
for (i=0; i<DB_NUMBER; i++)
{
irow[i]=row[i];
row[i]=NULL;
}
irow[DB_NUMBER]=NULL;
if (!TXT_DB_insert(db,irow))
{
BIO_printf(bio_err,"failed to update database\n");
BIO_printf(bio_err,"TXT_DB error number %ld\n",db->error);
goto err;
}
ok = do_revoke(x509,db);
goto err;
}
else if (index_name_cmp(row,rrow))
{
BIO_printf(bio_err,"ERROR:name does not match %s\n",
row[DB_name]);
goto err;
}
else if (rrow[DB_type][0]=='R')
{
BIO_printf(bio_err,"ERROR:Already revoked, serial number %s\n",
row[DB_serial]);
goto err;
}
else
{
BIO_printf(bio_err,"Revoking Certificate %s.\n", rrow[DB_serial]);
revtm = ASN1_UTCTIME_new();
revtm=X509_gmtime_adj(revtm,0);
rrow[DB_type][0]='R';
rrow[DB_type][1]='\0';
rrow[DB_rev_date]=(char *)OPENSSL_malloc(revtm->length+1);
memcpy(rrow[DB_rev_date],revtm->data,revtm->length);
rrow[DB_rev_date][revtm->length]='\0';
ASN1_UTCTIME_free(revtm);
}
ok=1;
err:
for (i=0; i<DB_NUMBER; i++)
{
if (row[i] != NULL)
OPENSSL_free(row[i]);
}
return(ok);
}
