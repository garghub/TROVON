int MAIN(int argc, char **argv)
{
ENGINE *e = NULL;
char *key=NULL,*passargin=NULL;
int create_ser = 0;
int free_key = 0;
int total=0;
int total_done=0;
int badops=0;
int ret=1;
int email_dn=1;
int req=0;
int verbose=0;
int gencrl=0;
int dorevoke=0;
int doupdatedb=0;
long crldays=0;
long crlhours=0;
long crlsec=0;
long errorline= -1;
char *configfile=NULL;
char *md=NULL;
char *policy=NULL;
char *keyfile=NULL;
char *certfile=NULL;
int keyform=FORMAT_PEM;
char *infile=NULL;
char *spkac_file=NULL;
char *ss_cert_file=NULL;
char *ser_status=NULL;
EVP_PKEY *pkey=NULL;
int output_der = 0;
char *outfile=NULL;
char *outdir=NULL;
char *serialfile=NULL;
char *crlnumberfile=NULL;
char *extensions=NULL;
char *extfile=NULL;
char *subj=NULL;
unsigned long chtype = MBSTRING_ASC;
int multirdn = 0;
char *tmp_email_dn=NULL;
char *crl_ext=NULL;
int rev_type = REV_NONE;
char *rev_arg = NULL;
BIGNUM *serial=NULL;
BIGNUM *crlnumber=NULL;
char *startdate=NULL;
char *enddate=NULL;
long days=0;
int batch=0;
int notext=0;
unsigned long nameopt = 0, certopt = 0;
int default_op = 1;
int ext_copy = EXT_COPY_NONE;
int selfsign = 0;
X509 *x509=NULL, *x509p = NULL;
X509 *x=NULL;
BIO *in=NULL,*out=NULL,*Sout=NULL,*Cout=NULL;
char *dbfile=NULL;
CA_DB *db=NULL;
X509_CRL *crl=NULL;
X509_REVOKED *r=NULL;
ASN1_TIME *tmptm;
ASN1_INTEGER *tmpser;
char *f;
const char *p;
char * const *pp;
int i,j;
const EVP_MD *dgst=NULL;
STACK_OF(CONF_VALUE) *attribs=NULL;
STACK_OF(X509) *cert_sk=NULL;
#undef BSIZE
#define BSIZE 256
MS_STATIC char buf[3][BSIZE];
char *randfile=NULL;
#ifndef OPENSSL_NO_ENGINE
char *engine = NULL;
#endif
char *tofree=NULL;
DB_ATTR db_attr;
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
else if (strcmp(*argv,"-subj") == 0)
{
if (--argc < 1) goto bad;
subj= *(++argv);
}
else if (strcmp(*argv,"-utf8") == 0)
chtype = MBSTRING_UTF8;
else if (strcmp(*argv,"-create_serial") == 0)
create_ser = 1;
else if (strcmp(*argv,"-multivalue-rdn") == 0)
multirdn=1;
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
else if (strcmp(*argv,"-keyform") == 0)
{
if (--argc < 1) goto bad;
keyform=str2fmt(*(++argv));
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
else if (strcmp(*argv,"-selfsign") == 0)
selfsign=1;
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
else if (strcmp(*argv,"-noemailDN") == 0)
email_dn=0;
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
else if (strcmp(*argv,"-crlsec") == 0)
{
if (--argc < 1) goto bad;
crlsec = atol(*(++argv));
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
else if (strcmp(*argv,"-extfile") == 0)
{
if (--argc < 1) goto bad;
extfile= *(++argv);
}
else if (strcmp(*argv,"-status") == 0)
{
if (--argc < 1) goto bad;
ser_status= *(++argv);
}
else if (strcmp(*argv,"-updatedb") == 0)
{
doupdatedb=1;
}
else if (strcmp(*argv,"-crlexts") == 0)
{
if (--argc < 1) goto bad;
crl_ext= *(++argv);
}
else if (strcmp(*argv,"-crl_reason") == 0)
{
if (--argc < 1) goto bad;
rev_arg = *(++argv);
rev_type = REV_CRL_REASON;
}
else if (strcmp(*argv,"-crl_hold") == 0)
{
if (--argc < 1) goto bad;
rev_arg = *(++argv);
rev_type = REV_HOLD;
}
else if (strcmp(*argv,"-crl_compromise") == 0)
{
if (--argc < 1) goto bad;
rev_arg = *(++argv);
rev_type = REV_KEY_COMPROMISE;
}
else if (strcmp(*argv,"-crl_CA_compromise") == 0)
{
if (--argc < 1) goto bad;
rev_arg = *(++argv);
rev_type = REV_CA_COMPROMISE;
}
#ifndef OPENSSL_NO_ENGINE
else if (strcmp(*argv,"-engine") == 0)
{
if (--argc < 1) goto bad;
engine= *(++argv);
}
#endif
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
const char **pp2;
for (pp2=ca_usage; (*pp2 != NULL); pp2++)
BIO_printf(bio_err,"%s",*pp2);
goto err;
}
ERR_load_crypto_strings();
tofree=NULL;
if (configfile == NULL) configfile = getenv("OPENSSL_CONF");
if (configfile == NULL) configfile = getenv("SSLEAY_CONF");
if (configfile == NULL)
{
const char *s=X509_get_default_cert_area();
size_t len;
#ifdef OPENSSL_SYS_VMS
len = strlen(s)+sizeof(CONFIG_FILE);
tofree=OPENSSL_malloc(len);
strcpy(tofree,s);
#else
len = strlen(s)+sizeof(CONFIG_FILE)+1;
tofree=OPENSSL_malloc(len);
BUF_strlcpy(tofree,s,len);
BUF_strlcat(tofree,"/",len);
#endif
BUF_strlcat(tofree,CONFIG_FILE,len);
configfile=tofree;
}
BIO_printf(bio_err,"Using configuration from %s\n",configfile);
conf = NCONF_new(NULL);
if (NCONF_load(conf,configfile,&errorline) <= 0)
{
if (errorline <= 0)
BIO_printf(bio_err,"error loading the config file '%s'\n",
configfile);
else
BIO_printf(bio_err,"error on line %ld of config file '%s'\n"
,errorline,configfile);
goto err;
}
if(tofree)
{
OPENSSL_free(tofree);
tofree = NULL;
}
if (!load_config(bio_err, conf))
goto err;
#ifndef OPENSSL_NO_ENGINE
e = setup_engine(bio_err, engine, 0);
#endif
if (section == NULL)
{
section=NCONF_get_string(conf,BASE_SECTION,ENV_DEFAULT_CA);
if (section == NULL)
{
lookup_fail(BASE_SECTION,ENV_DEFAULT_CA);
goto err;
}
}
if (conf != NULL)
{
p=NCONF_get_string(conf,NULL,"oid_file");
if (p == NULL)
ERR_clear_error();
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
if (!add_oid_section(bio_err,conf))
{
ERR_print_errors(bio_err);
goto err;
}
}
randfile = NCONF_get_string(conf, BASE_SECTION, "RANDFILE");
if (randfile == NULL)
ERR_clear_error();
app_RAND_load_file(randfile, bio_err, 0);
f = NCONF_get_string(conf, section, STRING_MASK);
if (!f)
ERR_clear_error();
if(f && !ASN1_STRING_set_default_mask_asc(f)) {
BIO_printf(bio_err, "Invalid global string mask setting %s\n", f);
goto err;
}
if (chtype != MBSTRING_UTF8){
f = NCONF_get_string(conf, section, UTF8_IN);
if (!f)
ERR_clear_error();
else if (!strcmp(f, "yes"))
chtype = MBSTRING_UTF8;
}
db_attr.unique_subject = 1;
p = NCONF_get_string(conf, section, ENV_UNIQUE_SUBJECT);
if (p)
{
#ifdef RL_DEBUG
BIO_printf(bio_err, "DEBUG: unique_subject = \"%s\"\n", p);
#endif
db_attr.unique_subject = parse_yesno(p,1);
}
else
ERR_clear_error();
#ifdef RL_DEBUG
if (!p)
BIO_printf(bio_err, "DEBUG: unique_subject undefined\n", p);
#endif
#ifdef RL_DEBUG
BIO_printf(bio_err, "DEBUG: configured unique_subject is %d\n",
db_attr.unique_subject);
#endif
in=BIO_new(BIO_s_file());
out=BIO_new(BIO_s_file());
Sout=BIO_new(BIO_s_file());
Cout=BIO_new(BIO_s_file());
if ((in == NULL) || (out == NULL) || (Sout == NULL) || (Cout == NULL))
{
ERR_print_errors(bio_err);
goto err;
}
if (ser_status)
{
if ((dbfile=NCONF_get_string(conf,section,ENV_DATABASE)) == NULL)
{
lookup_fail(section,ENV_DATABASE);
goto err;
}
db = load_index(dbfile,&db_attr);
if (db == NULL) goto err;
if (!index_index(db)) goto err;
if (get_certificate_status(ser_status,db) != 1)
BIO_printf(bio_err,"Error verifying serial %s!\n",
ser_status);
goto err;
}
if ((keyfile == NULL) && ((keyfile=NCONF_get_string(conf,
section,ENV_PRIVATE_KEY)) == NULL))
{
lookup_fail(section,ENV_PRIVATE_KEY);
goto err;
}
if (!key)
{
free_key = 1;
if (!app_passwd(bio_err, passargin, NULL, &key, NULL))
{
BIO_printf(bio_err,"Error getting password\n");
goto err;
}
}
pkey = load_key(bio_err, keyfile, keyform, 0, key, e,
"CA private key");
if (key) OPENSSL_cleanse(key,strlen(key));
if (pkey == NULL)
{
goto err;
}
if (!selfsign || spkac_file || ss_cert_file || gencrl)
{
if ((certfile == NULL)
&& ((certfile=NCONF_get_string(conf,
section,ENV_CERTIFICATE)) == NULL))
{
lookup_fail(section,ENV_CERTIFICATE);
goto err;
}
x509=load_cert(bio_err, certfile, FORMAT_PEM, NULL, e,
"CA certificate");
if (x509 == NULL)
goto err;
if (!X509_check_private_key(x509,pkey))
{
BIO_printf(bio_err,"CA certificate and CA private key do not match\n");
goto err;
}
}
if (!selfsign) x509p = x509;
f=NCONF_get_string(conf,BASE_SECTION,ENV_PRESERVE);
if (f == NULL)
ERR_clear_error();
if ((f != NULL) && ((*f == 'y') || (*f == 'Y')))
preserve=1;
f=NCONF_get_string(conf,BASE_SECTION,ENV_MSIE_HACK);
if (f == NULL)
ERR_clear_error();
if ((f != NULL) && ((*f == 'y') || (*f == 'Y')))
msie_hack=1;
f=NCONF_get_string(conf,section,ENV_NAMEOPT);
if (f)
{
if (!set_name_ex(&nameopt, f))
{
BIO_printf(bio_err, "Invalid name options: \"%s\"\n", f);
goto err;
}
default_op = 0;
}
else
ERR_clear_error();
f=NCONF_get_string(conf,section,ENV_CERTOPT);
if (f)
{
if (!set_cert_ex(&certopt, f))
{
BIO_printf(bio_err, "Invalid certificate options: \"%s\"\n", f);
goto err;
}
default_op = 0;
}
else
ERR_clear_error();
f=NCONF_get_string(conf,section,ENV_EXTCOPY);
if (f)
{
if (!set_ext_copy(&ext_copy, f))
{
BIO_printf(bio_err, "Invalid extension copy option: \"%s\"\n", f);
goto err;
}
}
else
ERR_clear_error();
if ((outdir == NULL) && (req))
{
if ((outdir=NCONF_get_string(conf,section,ENV_NEW_CERTS_DIR))
== NULL)
{
BIO_printf(bio_err,"there needs to be defined a directory for new certificate to be placed in\n");
goto err;
}
#ifndef OPENSSL_SYS_VMS
#ifndef _WIN32
if (access(outdir,R_OK|W_OK|X_OK) != 0)
#else
if (_access(outdir,R_OK|W_OK|X_OK) != 0)
#endif
{
BIO_printf(bio_err,"I am unable to access the %s directory\n",outdir);
perror(outdir);
goto err;
}
if (app_isdir(outdir)<=0)
{
BIO_printf(bio_err,"%s need to be a directory\n",outdir);
perror(outdir);
goto err;
}
#endif
}
if ((dbfile=NCONF_get_string(conf,section,ENV_DATABASE)) == NULL)
{
lookup_fail(section,ENV_DATABASE);
goto err;
}
db = load_index(dbfile, &db_attr);
if (db == NULL) goto err;
for (i=0; i<sk_OPENSSL_PSTRING_num(db->db->data); i++)
{
pp=sk_OPENSSL_PSTRING_value(db->db->data,i);
if ((pp[DB_type][0] != DB_TYPE_REV) &&
(pp[DB_rev_date][0] != '\0'))
{
BIO_printf(bio_err,"entry %d: not revoked yet, but has a revocation date\n",i+1);
goto err;
}
if ((pp[DB_type][0] == DB_TYPE_REV) &&
!make_revoked(NULL, pp[DB_rev_date]))
{
BIO_printf(bio_err," in entry %d\n", i+1);
goto err;
}
if (!check_time_format((char *)pp[DB_exp_date]))
{
BIO_printf(bio_err,"entry %d: invalid expiry date\n",i+1);
goto err;
}
p=pp[DB_serial];
j=strlen(p);
if (*p == '-')
{
p++;
j--;
}
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
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
TXT_DB_write(out,db->db);
BIO_printf(bio_err,"%d entries loaded from the database\n",
sk_OPENSSL_PSTRING_num(db->db->data));
BIO_printf(bio_err,"generating index\n");
}
if (!index_index(db)) goto err;
if (doupdatedb)
{
if (verbose)
BIO_printf(bio_err, "Updating %s ...\n",
dbfile);
i = do_updatedb(db);
if (i == -1)
{
BIO_printf(bio_err,"Malloc failure\n");
goto err;
}
else if (i == 0)
{
if (verbose) BIO_printf(bio_err,
"No entries found to mark expired\n");
}
else
{
if (!save_index(dbfile,"new",db)) goto err;
if (!rotate_index(dbfile,"new","old")) goto err;
if (verbose) BIO_printf(bio_err,
"Done. %d entries marked as expired\n",i);
}
}
if (extfile)
{
extconf = NCONF_new(NULL);
if (NCONF_load(extconf,extfile,&errorline) <= 0)
{
if (errorline <= 0)
BIO_printf(bio_err, "ERROR: loading the config file '%s'\n",
extfile);
else
BIO_printf(bio_err, "ERROR: on line %ld of config file '%s'\n",
errorline,extfile);
ret = 1;
goto err;
}
if (verbose)
BIO_printf(bio_err, "Successfully loaded extensions file %s\n", extfile);
if (!extensions && !(extensions = NCONF_get_string(extconf, "default", "extensions")))
extensions = "default";
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
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
Sout = BIO_push(tmpbio, Sout);
}
#endif
}
}
if ((md == NULL) && ((md=NCONF_get_string(conf,
section,ENV_DEFAULT_MD)) == NULL))
{
lookup_fail(section,ENV_DEFAULT_MD);
goto err;
}
if (!strcmp(md, "default"))
{
int def_nid;
if (EVP_PKEY_get_default_digest_nid(pkey, &def_nid) <= 0)
{
BIO_puts(bio_err,"no default digest\n");
goto err;
}
md = (char *)OBJ_nid2sn(def_nid);
}
if ((dgst=EVP_get_digestbyname(md)) == NULL)
{
BIO_printf(bio_err,"%s is an unsupported message digest type\n",md);
goto err;
}
if (req)
{
if ((email_dn == 1) && ((tmp_email_dn=NCONF_get_string(conf,
section,ENV_DEFAULT_EMAIL_DN)) != NULL ))
{
if(strcmp(tmp_email_dn,"no") == 0)
email_dn=0;
}
if (verbose)
BIO_printf(bio_err,"message digest is %s\n",
OBJ_nid2ln(dgst->type));
if ((policy == NULL) && ((policy=NCONF_get_string(conf,
section,ENV_POLICY)) == NULL))
{
lookup_fail(section,ENV_POLICY);
goto err;
}
if (verbose)
BIO_printf(bio_err,"policy is %s\n",policy);
if ((serialfile=NCONF_get_string(conf,section,ENV_SERIAL))
== NULL)
{
lookup_fail(section,ENV_SERIAL);
goto err;
}
if (!extconf)
{
if (!extensions)
{
extensions=NCONF_get_string(conf,section,
ENV_EXTENSIONS);
if (!extensions)
ERR_clear_error();
}
if (extensions)
{
X509V3_CTX ctx;
X509V3_set_ctx_test(&ctx);
X509V3_set_nconf(&ctx, conf);
if (!X509V3_EXT_add_nconf(conf, &ctx, extensions,
NULL))
{
BIO_printf(bio_err,
"Error Loading extension section %s\n",
extensions);
ret = 1;
goto err;
}
}
}
if (startdate == NULL)
{
startdate=NCONF_get_string(conf,section,
ENV_DEFAULT_STARTDATE);
if (startdate == NULL)
ERR_clear_error();
}
if (startdate && !ASN1_TIME_set_string(NULL, startdate))
{
BIO_printf(bio_err,"start date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n");
goto err;
}
if (startdate == NULL) startdate="today";
if (enddate == NULL)
{
enddate=NCONF_get_string(conf,section,
ENV_DEFAULT_ENDDATE);
if (enddate == NULL)
ERR_clear_error();
}
if (enddate && !ASN1_TIME_set_string(NULL, enddate))
{
BIO_printf(bio_err,"end date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n");
goto err;
}
if (days == 0)
{
if(!NCONF_get_number(conf,section, ENV_DEFAULT_DAYS, &days))
days = 0;
}
if (!enddate && (days == 0))
{
BIO_printf(bio_err,"cannot lookup how many days to certify for\n");
goto err;
}
if ((serial=load_serial(serialfile, create_ser, NULL)) == NULL)
{
BIO_printf(bio_err,"error while loading serial number\n");
goto err;
}
if (verbose)
{
if (BN_is_zero(serial))
BIO_printf(bio_err,"next serial number is 00\n");
else
{
if ((f=BN_bn2hex(serial)) == NULL) goto err;
BIO_printf(bio_err,"next serial number is %s\n",f);
OPENSSL_free(f);
}
}
if ((attribs=NCONF_get_section(conf,policy)) == NULL)
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
serial,subj,chtype,multirdn,email_dn,startdate,enddate,days,extensions,
conf,verbose,certopt,nameopt,default_op,ext_copy);
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
db,serial,subj,chtype,multirdn,email_dn,startdate,enddate,days,batch,
extensions,conf,verbose, certopt, nameopt,
default_op, ext_copy, e);
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
j=certify(&x,infile,pkey,x509p,dgst,attribs,db,
serial,subj,chtype,multirdn,email_dn,startdate,enddate,days,batch,
extensions,conf,verbose, certopt, nameopt,
default_op, ext_copy, selfsign);
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
j=certify(&x,argv[i],pkey,x509p,dgst,attribs,db,
serial,subj,chtype,multirdn,email_dn,startdate,enddate,days,batch,
extensions,conf,verbose, certopt, nameopt,
default_op, ext_copy, selfsign);
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
if (!fgets(buf[0],10,stdin))
{
BIO_printf(bio_err,"CERTIFICATION CANCELED: I/O error\n");
ret=0;
goto err;
}
if ((buf[0][0] != 'y') && (buf[0][0] != 'Y'))
{
BIO_printf(bio_err,"CERTIFICATION CANCELED\n");
ret=0;
goto err;
}
}
BIO_printf(bio_err,"Write out database with %d new entries\n",sk_X509_num(cert_sk));
if (!save_serial(serialfile,"new",serial,NULL)) goto err;
if (!save_index(dbfile, "new", db)) goto err;
}
if (verbose)
BIO_printf(bio_err,"writing new certificates\n");
for (i=0; i<sk_X509_num(cert_sk); i++)
{
int k;
char *n;
x=sk_X509_value(cert_sk,i);
j=x->cert_info->serialNumber->length;
p=(const char *)x->cert_info->serialNumber->data;
if(strlen(outdir) >= (size_t)(j ? BSIZE-j*2-6 : BSIZE-8))
{
BIO_printf(bio_err,"certificate file name too long\n");
goto err;
}
strcpy(buf[2],outdir);
#ifndef OPENSSL_SYS_VMS
BUF_strlcat(buf[2],"/",sizeof(buf[2]));
#endif
n=(char *)&(buf[2][strlen(buf[2])]);
if (j > 0)
{
for (k=0; k<j; k++)
{
if (n >= &(buf[2][sizeof(buf[2])]))
break;
BIO_snprintf(n,
&buf[2][0] + sizeof(buf[2]) - n,
"%02X",(unsigned char)*(p++));
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
if (!rotate_serial(serialfile,"new","old")) goto err;
if (!rotate_index(dbfile,"new","old")) goto err;
BIO_printf(bio_err,"Data Base Updated\n");
}
}
if (gencrl)
{
int crl_v2 = 0;
if (!crl_ext)
{
crl_ext=NCONF_get_string(conf,section,ENV_CRLEXT);
if (!crl_ext)
ERR_clear_error();
}
if (crl_ext)
{
X509V3_CTX ctx;
X509V3_set_ctx_test(&ctx);
X509V3_set_nconf(&ctx, conf);
if (!X509V3_EXT_add_nconf(conf, &ctx, crl_ext, NULL))
{
BIO_printf(bio_err,
"Error Loading CRL extension section %s\n",
crl_ext);
ret = 1;
goto err;
}
}
if ((crlnumberfile=NCONF_get_string(conf,section,ENV_CRLNUMBER))
!= NULL)
if ((crlnumber=load_serial(crlnumberfile,0,NULL)) == NULL)
{
BIO_printf(bio_err,"error while loading CRL number\n");
goto err;
}
if (!crldays && !crlhours && !crlsec)
{
if (!NCONF_get_number(conf,section,
ENV_DEFAULT_CRL_DAYS, &crldays))
crldays = 0;
if (!NCONF_get_number(conf,section,
ENV_DEFAULT_CRL_HOURS, &crlhours))
crlhours = 0;
}
if ((crldays == 0) && (crlhours == 0) && (crlsec == 0))
{
BIO_printf(bio_err,"cannot lookup how long until the next CRL is issued\n");
goto err;
}
if (verbose) BIO_printf(bio_err,"making CRL\n");
if ((crl=X509_CRL_new()) == NULL) goto err;
if (!X509_CRL_set_issuer_name(crl, X509_get_subject_name(x509))) goto err;
tmptm = ASN1_TIME_new();
if (!tmptm) goto err;
X509_gmtime_adj(tmptm,0);
X509_CRL_set_lastUpdate(crl, tmptm);
if (!X509_time_adj_ex(tmptm, crldays, crlhours*60*60 + crlsec,
NULL))
{
BIO_puts(bio_err, "error setting CRL nextUpdate\n");
goto err;
}
X509_CRL_set_nextUpdate(crl, tmptm);
ASN1_TIME_free(tmptm);
for (i=0; i<sk_OPENSSL_PSTRING_num(db->db->data); i++)
{
pp=sk_OPENSSL_PSTRING_value(db->db->data,i);
if (pp[DB_type][0] == DB_TYPE_REV)
{
if ((r=X509_REVOKED_new()) == NULL) goto err;
j = make_revoked(r, pp[DB_rev_date]);
if (!j) goto err;
if (j == 2) crl_v2 = 1;
if (!BN_hex2bn(&serial, pp[DB_serial]))
goto err;
tmpser = BN_to_ASN1_INTEGER(serial, NULL);
BN_free(serial);
serial = NULL;
if (!tmpser)
goto err;
X509_REVOKED_set_serialNumber(r, tmpser);
ASN1_INTEGER_free(tmpser);
X509_CRL_add0_revoked(crl,r);
}
}
X509_CRL_sort(crl);
if (verbose) BIO_printf(bio_err,"signing CRL\n");
if (crl_ext || crlnumberfile != NULL)
{
X509V3_CTX crlctx;
X509V3_set_ctx(&crlctx, x509, NULL, NULL, crl, 0);
X509V3_set_nconf(&crlctx, conf);
if (crl_ext)
if (!X509V3_EXT_CRL_add_nconf(conf, &crlctx,
crl_ext, crl)) goto err;
if (crlnumberfile != NULL)
{
tmpser = BN_to_ASN1_INTEGER(crlnumber, NULL);
if (!tmpser) goto err;
X509_CRL_add1_ext_i2d(crl,NID_crl_number,tmpser,0,0);
ASN1_INTEGER_free(tmpser);
crl_v2 = 1;
if (!BN_add_word(crlnumber,1)) goto err;
}
}
if (crl_ext || crl_v2)
{
if (!X509_CRL_set_version(crl, 1))
goto err;
}
if (crlnumberfile != NULL)
if (!save_serial(crlnumberfile,"new",crlnumber,NULL)) goto err;
if (crlnumber)
{
BN_free(crlnumber);
crlnumber = NULL;
}
if (!X509_CRL_sign(crl,pkey,dgst)) goto err;
PEM_write_bio_X509_CRL(Sout,crl);
if (crlnumberfile != NULL)
if (!rotate_serial(crlnumberfile,"new","old")) goto err;
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
revcert=load_cert(bio_err, infile, FORMAT_PEM,
NULL, e, infile);
if (revcert == NULL)
goto err;
j=do_revoke(revcert,db, rev_type, rev_arg);
if (j <= 0) goto err;
X509_free(revcert);
if (!save_index(dbfile, "new", db)) goto err;
if (!rotate_index(dbfile, "new", "old")) goto err;
BIO_printf(bio_err,"Data Base Updated\n");
}
}
ret=0;
err:
if(tofree)
OPENSSL_free(tofree);
BIO_free_all(Cout);
BIO_free_all(Sout);
BIO_free_all(out);
BIO_free_all(in);
if (cert_sk)
sk_X509_pop_free(cert_sk,X509_free);
if (ret) ERR_print_errors(bio_err);
app_RAND_write_file(randfile, bio_err);
if (free_key && key)
OPENSSL_free(key);
BN_free(serial);
BN_free(crlnumber);
free_index(db);
EVP_PKEY_free(pkey);
if (x509) X509_free(x509);
X509_CRL_free(crl);
NCONF_free(conf);
NCONF_free(extconf);
OBJ_cleanup();
apps_shutdown();
OPENSSL_EXIT(ret);
}
static void lookup_fail(const char *name, const char *tag)
{
BIO_printf(bio_err,"variable lookup failed for %s::%s\n",name,tag);
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
if (!notext)X509_print(bp,x);
PEM_write_bio_X509(bp,x);
}
static int check_time_format(const char *str)
{
return ASN1_TIME_set_string(NULL, str);
}
static int do_revoke(X509 *x509, CA_DB *db, int type, char *value)
{
ASN1_UTCTIME *tm=NULL;
char *row[DB_NUMBER],**rrow,**irow;
char *rev_str = NULL;
BIGNUM *bn = NULL;
int ok=-1,i;
for (i=0; i<DB_NUMBER; i++)
row[i]=NULL;
row[DB_name]=X509_NAME_oneline(X509_get_subject_name(x509),NULL,0);
bn = ASN1_INTEGER_to_BN(X509_get_serialNumber(x509),NULL);
if (!bn)
goto err;
if (BN_is_zero(bn))
row[DB_serial]=BUF_strdup("00");
else
row[DB_serial]=BN_bn2hex(bn);
BN_free(bn);
if ((row[DB_name] == NULL) || (row[DB_serial] == NULL))
{
BIO_printf(bio_err,"Memory allocation failure\n");
goto err;
}
rrow=TXT_DB_get_by_index(db->db,DB_serial,row);
if (rrow == NULL)
{
BIO_printf(bio_err,"Adding Entry with serial number %s to DB for %s\n", row[DB_serial], row[DB_name]);
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
BUF_strlcpy(row[DB_file],"unknown",8);
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
if (!TXT_DB_insert(db->db,irow))
{
BIO_printf(bio_err,"failed to update database\n");
BIO_printf(bio_err,"TXT_DB error number %ld\n",db->db->error);
goto err;
}
ok = do_revoke(x509,db, type, value);
goto err;
}
else if (index_name_cmp_noconst(row, rrow))
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
rev_str = make_revocation_str(type, value);
if (!rev_str)
{
BIO_printf(bio_err, "Error in revocation arguments\n");
goto err;
}
rrow[DB_type][0]='R';
rrow[DB_type][1]='\0';
rrow[DB_rev_date] = rev_str;
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
static int get_certificate_status(const char *serial, CA_DB *db)
{
char *row[DB_NUMBER],**rrow;
int ok=-1,i;
for (i=0; i<DB_NUMBER; i++)
row[i]=NULL;
row[DB_serial] = OPENSSL_malloc(strlen(serial) + 2);
if (row[DB_serial] == NULL)
{
BIO_printf(bio_err,"Malloc failure\n");
goto err;
}
if (strlen(serial) % 2)
{
;
row[DB_serial][0]='0';
memcpy(row[DB_serial]+1, serial, strlen(serial));
row[DB_serial][strlen(serial)+1]='\0';
}
else
{
memcpy(row[DB_serial], serial, strlen(serial));
row[DB_serial][strlen(serial)]='\0';
}
for (i=0; row[DB_serial][i] != '\0'; i++)
row[DB_serial][i] = toupper(row[DB_serial][i]);
ok=1;
rrow=TXT_DB_get_by_index(db->db,DB_serial,row);
if (rrow == NULL)
{
BIO_printf(bio_err,"Serial %s not present in db.\n",
row[DB_serial]);
ok=-1;
goto err;
}
else if (rrow[DB_type][0]=='V')
{
BIO_printf(bio_err,"%s=Valid (%c)\n",
row[DB_serial], rrow[DB_type][0]);
goto err;
}
else if (rrow[DB_type][0]=='R')
{
BIO_printf(bio_err,"%s=Revoked (%c)\n",
row[DB_serial], rrow[DB_type][0]);
goto err;
}
else if (rrow[DB_type][0]=='E')
{
BIO_printf(bio_err,"%s=Expired (%c)\n",
row[DB_serial], rrow[DB_type][0]);
goto err;
}
else if (rrow[DB_type][0]=='S')
{
BIO_printf(bio_err,"%s=Suspended (%c)\n",
row[DB_serial], rrow[DB_type][0]);
goto err;
}
else
{
BIO_printf(bio_err,"%s=Unknown (%c).\n",
row[DB_serial], rrow[DB_type][0]);
ok=-1;
}
err:
for (i=0; i<DB_NUMBER; i++)
{
if (row[i] != NULL)
OPENSSL_free(row[i]);
}
return(ok);
}
static int do_updatedb (CA_DB *db)
{
ASN1_UTCTIME *a_tm = NULL;
int i, cnt = 0;
int db_y2k, a_y2k;
char **rrow, *a_tm_s;
a_tm = ASN1_UTCTIME_new();
a_tm = X509_gmtime_adj(a_tm, 0);
a_tm_s = (char *) OPENSSL_malloc(a_tm->length+1);
if (a_tm_s == NULL)
{
cnt = -1;
goto err;
}
memcpy(a_tm_s, a_tm->data, a_tm->length);
a_tm_s[a_tm->length] = '\0';
if (strncmp(a_tm_s, "49", 2) <= 0)
a_y2k = 1;
else
a_y2k = 0;
for (i = 0; i < sk_OPENSSL_PSTRING_num(db->db->data); i++)
{
rrow = sk_OPENSSL_PSTRING_value(db->db->data, i);
if (rrow[DB_type][0] == 'V')
{
if (strncmp(rrow[DB_exp_date], "49", 2) <= 0)
db_y2k = 1;
else
db_y2k = 0;
if (db_y2k == a_y2k)
{
if (strcmp(rrow[DB_exp_date], a_tm_s) <= 0)
{
rrow[DB_type][0] = 'E';
rrow[DB_type][1] = '\0';
cnt++;
BIO_printf(bio_err, "%s=Expired\n",
rrow[DB_serial]);
}
}
else if (db_y2k < a_y2k)
{
rrow[DB_type][0] = 'E';
rrow[DB_type][1] = '\0';
cnt++;
BIO_printf(bio_err, "%s=Expired\n",
rrow[DB_serial]);
}
}
}
err:
ASN1_UTCTIME_free(a_tm);
OPENSSL_free(a_tm_s);
return (cnt);
}
char *make_revocation_str(int rev_type, char *rev_arg)
{
char *other = NULL, *str;
const char *reason = NULL;
ASN1_OBJECT *otmp;
ASN1_UTCTIME *revtm = NULL;
int i;
switch (rev_type)
{
case REV_NONE:
break;
case REV_CRL_REASON:
for (i = 0; i < 8; i++)
{
if (!strcasecmp(rev_arg, crl_reasons[i]))
{
reason = crl_reasons[i];
break;
}
}
if (reason == NULL)
{
BIO_printf(bio_err, "Unknown CRL reason %s\n", rev_arg);
return NULL;
}
break;
case REV_HOLD:
otmp = OBJ_txt2obj(rev_arg, 0);
ASN1_OBJECT_free(otmp);
if (otmp == NULL)
{
BIO_printf(bio_err, "Invalid object identifier %s\n", rev_arg);
return NULL;
}
reason = "holdInstruction";
other = rev_arg;
break;
case REV_KEY_COMPROMISE:
case REV_CA_COMPROMISE:
if (!ASN1_GENERALIZEDTIME_set_string(NULL, rev_arg))
{
BIO_printf(bio_err, "Invalid time format %s. Need YYYYMMDDHHMMSSZ\n", rev_arg);
return NULL;
}
other = rev_arg;
if (rev_type == REV_KEY_COMPROMISE)
reason = "keyTime";
else
reason = "CAkeyTime";
break;
}
revtm = X509_gmtime_adj(NULL, 0);
i = revtm->length + 1;
if (reason) i += strlen(reason) + 1;
if (other) i += strlen(other) + 1;
str = OPENSSL_malloc(i);
if (!str) return NULL;
BUF_strlcpy(str, (char *)revtm->data, i);
if (reason)
{
BUF_strlcat(str, ",", i);
BUF_strlcat(str, reason, i);
}
if (other)
{
BUF_strlcat(str, ",", i);
BUF_strlcat(str, other, i);
}
ASN1_UTCTIME_free(revtm);
return str;
}
int make_revoked(X509_REVOKED *rev, const char *str)
{
char *tmp = NULL;
int reason_code = -1;
int i, ret = 0;
ASN1_OBJECT *hold = NULL;
ASN1_GENERALIZEDTIME *comp_time = NULL;
ASN1_ENUMERATED *rtmp = NULL;
ASN1_TIME *revDate = NULL;
i = unpack_revinfo(&revDate, &reason_code, &hold, &comp_time, str);
if (i == 0)
goto err;
if (rev && !X509_REVOKED_set_revocationDate(rev, revDate))
goto err;
if (rev && (reason_code != OCSP_REVOKED_STATUS_NOSTATUS))
{
rtmp = ASN1_ENUMERATED_new();
if (!rtmp || !ASN1_ENUMERATED_set(rtmp, reason_code))
goto err;
if (!X509_REVOKED_add1_ext_i2d(rev, NID_crl_reason, rtmp, 0, 0))
goto err;
}
if (rev && comp_time)
{
if (!X509_REVOKED_add1_ext_i2d(rev, NID_invalidity_date, comp_time, 0, 0))
goto err;
}
if (rev && hold)
{
if (!X509_REVOKED_add1_ext_i2d(rev, NID_hold_instruction_code, hold, 0, 0))
goto err;
}
if (reason_code != OCSP_REVOKED_STATUS_NOSTATUS)
ret = 2;
else ret = 1;
err:
if (tmp) OPENSSL_free(tmp);
ASN1_OBJECT_free(hold);
ASN1_GENERALIZEDTIME_free(comp_time);
ASN1_ENUMERATED_free(rtmp);
ASN1_TIME_free(revDate);
return ret;
}
int old_entry_print(BIO *bp, ASN1_OBJECT *obj, ASN1_STRING *str)
{
char buf[25],*pbuf, *p;
int j;
j=i2a_ASN1_OBJECT(bp,obj);
pbuf=buf;
for (j=22-j; j>0; j--)
*(pbuf++)=' ';
*(pbuf++)=':';
*(pbuf++)='\0';
BIO_puts(bp,buf);
if (str->type == V_ASN1_PRINTABLESTRING)
BIO_printf(bp,"PRINTABLE:'");
else if (str->type == V_ASN1_T61STRING)
BIO_printf(bp,"T61STRING:'");
else if (str->type == V_ASN1_IA5STRING)
BIO_printf(bp,"IA5STRING:'");
else if (str->type == V_ASN1_UNIVERSALSTRING)
BIO_printf(bp,"UNIVERSALSTRING:'");
else
BIO_printf(bp,"ASN.1 %2d:'",str->type);
p=(char *)str->data;
for (j=str->length; j>0; j--)
{
if ((*p >= ' ') && (*p <= '~'))
BIO_printf(bp,"%c",*p);
else if (*p & 0x80)
BIO_printf(bp,"\\0x%02X",*p);
else if ((unsigned char)*p == 0xf7)
BIO_printf(bp,"^?");
else BIO_printf(bp,"^%c",*p+'@');
p++;
}
BIO_printf(bp,"'\n");
return 1;
}
int unpack_revinfo(ASN1_TIME **prevtm, int *preason, ASN1_OBJECT **phold, ASN1_GENERALIZEDTIME **pinvtm, const char *str)
{
char *tmp = NULL;
char *rtime_str, *reason_str = NULL, *arg_str = NULL, *p;
int reason_code = -1;
int ret = 0;
unsigned int i;
ASN1_OBJECT *hold = NULL;
ASN1_GENERALIZEDTIME *comp_time = NULL;
tmp = BUF_strdup(str);
p = strchr(tmp, ',');
rtime_str = tmp;
if (p)
{
*p = '\0';
p++;
reason_str = p;
p = strchr(p, ',');
if (p)
{
*p = '\0';
arg_str = p + 1;
}
}
if (prevtm)
{
*prevtm = ASN1_UTCTIME_new();
if (!ASN1_UTCTIME_set_string(*prevtm, rtime_str))
{
BIO_printf(bio_err, "invalid revocation date %s\n", rtime_str);
goto err;
}
}
if (reason_str)
{
for (i = 0; i < NUM_REASONS; i++)
{
if(!strcasecmp(reason_str, crl_reasons[i]))
{
reason_code = i;
break;
}
}
if (reason_code == OCSP_REVOKED_STATUS_NOSTATUS)
{
BIO_printf(bio_err, "invalid reason code %s\n", reason_str);
goto err;
}
if (reason_code == 7)
reason_code = OCSP_REVOKED_STATUS_REMOVEFROMCRL;
else if (reason_code == 8)
{
if (!arg_str)
{
BIO_printf(bio_err, "missing hold instruction\n");
goto err;
}
reason_code = OCSP_REVOKED_STATUS_CERTIFICATEHOLD;
hold = OBJ_txt2obj(arg_str, 0);
if (!hold)
{
BIO_printf(bio_err, "invalid object identifier %s\n", arg_str);
goto err;
}
if (phold) *phold = hold;
}
else if ((reason_code == 9) || (reason_code == 10))
{
if (!arg_str)
{
BIO_printf(bio_err, "missing compromised time\n");
goto err;
}
comp_time = ASN1_GENERALIZEDTIME_new();
if (!ASN1_GENERALIZEDTIME_set_string(comp_time, arg_str))
{
BIO_printf(bio_err, "invalid compromised time %s\n", arg_str);
goto err;
}
if (reason_code == 9)
reason_code = OCSP_REVOKED_STATUS_KEYCOMPROMISE;
else
reason_code = OCSP_REVOKED_STATUS_CACOMPROMISE;
}
}
if (preason) *preason = reason_code;
if (pinvtm) *pinvtm = comp_time;
else ASN1_GENERALIZEDTIME_free(comp_time);
ret = 1;
err:
if (tmp) OPENSSL_free(tmp);
if (!phold) ASN1_OBJECT_free(hold);
if (!pinvtm) ASN1_GENERALIZEDTIME_free(comp_time);
return ret;
}
