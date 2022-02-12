int MAIN(int argc, char **argv)
{
ENGINE *e = NULL, *gen_eng = NULL;
unsigned long nmflag = 0, reqflag = 0;
int ex=1,x509=0,days=30;
X509 *x509ss=NULL;
X509_REQ *req=NULL;
EVP_PKEY_CTX *genctx = NULL;
const char *keyalg = NULL;
char *keyalgstr = NULL;
STACK_OF(OPENSSL_STRING) *pkeyopts = NULL, *sigopts = NULL;
EVP_PKEY *pkey=NULL;
int i=0,badops=0,newreq=0,verbose=0,pkey_type=-1;
long newkey = -1;
BIO *in=NULL,*out=NULL;
int informat,outformat,verify=0,noout=0,text=0,keyform=FORMAT_PEM;
int nodes=0,kludge=0,newhdr=0,subject=0,pubkey=0;
char *infile,*outfile,*prog,*keyfile=NULL,*template=NULL,*keyout=NULL;
#ifndef OPENSSL_NO_ENGINE
char *engine=NULL;
#endif
char *extensions = NULL;
char *req_exts = NULL;
const EVP_CIPHER *cipher=NULL;
ASN1_INTEGER *serial = NULL;
int modulus=0;
char *inrand=NULL;
char *passargin = NULL, *passargout = NULL;
char *passin = NULL, *passout = NULL;
char *p;
char *subj = NULL;
int multirdn = 0;
const EVP_MD *md_alg=NULL,*digest=NULL;
unsigned long chtype = MBSTRING_ASC;
#ifndef MONOLITH
char *to_free;
long errline;
#endif
req_conf = NULL;
#ifndef OPENSSL_NO_DES
cipher=EVP_des_ede3_cbc();
#endif
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
infile=NULL;
outfile=NULL;
informat=FORMAT_PEM;
outformat=FORMAT_PEM;
prog=argv[0];
argc--;
argv++;
while (argc >= 1)
{
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
#ifndef OPENSSL_NO_ENGINE
else if (strcmp(*argv,"-engine") == 0)
{
if (--argc < 1) goto bad;
engine= *(++argv);
}
else if (strcmp(*argv,"-keygen_engine") == 0)
{
if (--argc < 1) goto bad;
gen_eng = ENGINE_by_id(*(++argv));
if (gen_eng == NULL)
{
BIO_printf(bio_err, "Can't find keygen engine %s\n", *argv);
goto end;
}
}
#endif
else if (strcmp(*argv,"-key") == 0)
{
if (--argc < 1) goto bad;
keyfile= *(++argv);
}
else if (strcmp(*argv,"-pubkey") == 0)
{
pubkey=1;
}
else if (strcmp(*argv,"-new") == 0)
{
newreq=1;
}
else if (strcmp(*argv,"-config") == 0)
{
if (--argc < 1) goto bad;
template= *(++argv);
}
else if (strcmp(*argv,"-keyform") == 0)
{
if (--argc < 1) goto bad;
keyform=str2fmt(*(++argv));
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
else if (strcmp(*argv,"-keyout") == 0)
{
if (--argc < 1) goto bad;
keyout= *(++argv);
}
else if (strcmp(*argv,"-passin") == 0)
{
if (--argc < 1) goto bad;
passargin= *(++argv);
}
else if (strcmp(*argv,"-passout") == 0)
{
if (--argc < 1) goto bad;
passargout= *(++argv);
}
else if (strcmp(*argv,"-rand") == 0)
{
if (--argc < 1) goto bad;
inrand= *(++argv);
}
else if (strcmp(*argv,"-newkey") == 0)
{
if (--argc < 1)
goto bad;
keyalg = *(++argv);
newreq=1;
}
else if (strcmp(*argv,"-pkeyopt") == 0)
{
if (--argc < 1)
goto bad;
if (!pkeyopts)
pkeyopts = sk_OPENSSL_STRING_new_null();
if (!pkeyopts || !sk_OPENSSL_STRING_push(pkeyopts, *(++argv)))
goto bad;
}
else if (strcmp(*argv,"-sigopt") == 0)
{
if (--argc < 1)
goto bad;
if (!sigopts)
sigopts = sk_OPENSSL_STRING_new_null();
if (!sigopts || !sk_OPENSSL_STRING_push(sigopts, *(++argv)))
goto bad;
}
else if (strcmp(*argv,"-batch") == 0)
batch=1;
else if (strcmp(*argv,"-newhdr") == 0)
newhdr=1;
else if (strcmp(*argv,"-modulus") == 0)
modulus=1;
else if (strcmp(*argv,"-verify") == 0)
verify=1;
else if (strcmp(*argv,"-nodes") == 0)
nodes=1;
else if (strcmp(*argv,"-noout") == 0)
noout=1;
else if (strcmp(*argv,"-verbose") == 0)
verbose=1;
else if (strcmp(*argv,"-utf8") == 0)
chtype = MBSTRING_UTF8;
else if (strcmp(*argv,"-nameopt") == 0)
{
if (--argc < 1) goto bad;
if (!set_name_ex(&nmflag, *(++argv))) goto bad;
}
else if (strcmp(*argv,"-reqopt") == 0)
{
if (--argc < 1) goto bad;
if (!set_cert_ex(&reqflag, *(++argv))) goto bad;
}
else if (strcmp(*argv,"-subject") == 0)
subject=1;
else if (strcmp(*argv,"-text") == 0)
text=1;
else if (strcmp(*argv,"-x509") == 0)
x509=1;
else if (strcmp(*argv,"-asn1-kludge") == 0)
kludge=1;
else if (strcmp(*argv,"-no-asn1-kludge") == 0)
kludge=0;
else if (strcmp(*argv,"-subj") == 0)
{
if (--argc < 1) goto bad;
subj= *(++argv);
}
else if (strcmp(*argv,"-multivalue-rdn") == 0)
multirdn=1;
else if (strcmp(*argv,"-days") == 0)
{
if (--argc < 1) goto bad;
days= atoi(*(++argv));
if (days == 0) days=30;
}
else if (strcmp(*argv,"-set_serial") == 0)
{
if (--argc < 1) goto bad;
serial = s2i_ASN1_INTEGER(NULL, *(++argv));
if (!serial) goto bad;
}
else if (strcmp(*argv,"-extensions") == 0)
{
if (--argc < 1) goto bad;
extensions = *(++argv);
}
else if (strcmp(*argv,"-reqexts") == 0)
{
if (--argc < 1) goto bad;
req_exts = *(++argv);
}
else if ((md_alg=EVP_get_digestbyname(&((*argv)[1]))) != NULL)
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
BIO_printf(bio_err,"%s [options] <infile >outfile\n",prog);
BIO_printf(bio_err,"where options are\n");
BIO_printf(bio_err," -inform arg input format - DER or PEM\n");
BIO_printf(bio_err," -outform arg output format - DER or PEM\n");
BIO_printf(bio_err," -in arg input file\n");
BIO_printf(bio_err," -out arg output file\n");
BIO_printf(bio_err," -text text form of request\n");
BIO_printf(bio_err," -pubkey output public key\n");
BIO_printf(bio_err," -noout do not output REQ\n");
BIO_printf(bio_err," -verify verify signature on REQ\n");
BIO_printf(bio_err," -modulus RSA modulus\n");
BIO_printf(bio_err," -nodes don't encrypt the output key\n");
#ifndef OPENSSL_NO_ENGINE
BIO_printf(bio_err," -engine e use engine e, possibly a hardware device\n");
#endif
BIO_printf(bio_err," -subject output the request's subject\n");
BIO_printf(bio_err," -passin private key password source\n");
BIO_printf(bio_err," -key file use the private key contained in file\n");
BIO_printf(bio_err," -keyform arg key file format\n");
BIO_printf(bio_err," -keyout arg file to send the key to\n");
BIO_printf(bio_err," -rand file%cfile%c...\n", LIST_SEPARATOR_CHAR, LIST_SEPARATOR_CHAR);
BIO_printf(bio_err," load the file (or the files in the directory) into\n");
BIO_printf(bio_err," the random number generator\n");
BIO_printf(bio_err," -newkey rsa:bits generate a new RSA key of 'bits' in size\n");
BIO_printf(bio_err," -newkey dsa:file generate a new DSA key, parameters taken from CA in 'file'\n");
#ifndef OPENSSL_NO_ECDSA
BIO_printf(bio_err," -newkey ec:file generate a new EC key, parameters taken from CA in 'file'\n");
#endif
BIO_printf(bio_err," -[digest] Digest to sign with (md5, sha1, md2, mdc2, md4)\n");
BIO_printf(bio_err," -config file request template file.\n");
BIO_printf(bio_err," -subj arg set or modify request subject\n");
BIO_printf(bio_err," -multivalue-rdn enable support for multivalued RDNs\n");
BIO_printf(bio_err," -new new request.\n");
BIO_printf(bio_err," -batch do not ask anything during request generation\n");
BIO_printf(bio_err," -x509 output a x509 structure instead of a cert. req.\n");
BIO_printf(bio_err," -days number of days a certificate generated by -x509 is valid for.\n");
BIO_printf(bio_err," -set_serial serial number to use for a certificate generated by -x509.\n");
BIO_printf(bio_err," -newhdr output \"NEW\" in the header lines\n");
BIO_printf(bio_err," -asn1-kludge Output the 'request' in a format that is wrong but some CA's\n");
BIO_printf(bio_err," have been reported as requiring\n");
BIO_printf(bio_err," -extensions .. specify certificate extension section (override value in config file)\n");
BIO_printf(bio_err," -reqexts .. specify request extension section (override value in config file)\n");
BIO_printf(bio_err," -utf8 input characters are UTF8 (default ASCII)\n");
BIO_printf(bio_err," -nameopt arg - various certificate name options\n");
BIO_printf(bio_err," -reqopt arg - various request text options\n\n");
goto end;
}
ERR_load_crypto_strings();
if(!app_passwd(bio_err, passargin, passargout, &passin, &passout)) {
BIO_printf(bio_err, "Error getting passwords\n");
goto end;
}
#ifndef MONOLITH
p=getenv("OPENSSL_CONF");
if (p == NULL)
p=getenv("SSLEAY_CONF");
if (p == NULL)
p=to_free=make_config_name();
default_config_file=p;
config=NCONF_new(NULL);
i=NCONF_load(config, p, &errline);
#endif
if (template != NULL)
{
long errline = -1;
if( verbose )
BIO_printf(bio_err,"Using configuration from %s\n",template);
req_conf=NCONF_new(NULL);
i=NCONF_load(req_conf,template,&errline);
if (i == 0)
{
BIO_printf(bio_err,"error on line %ld of %s\n",errline,template);
goto end;
}
}
else
{
req_conf=config;
if (req_conf == NULL)
{
BIO_printf(bio_err,"Unable to load config info from %s\n", default_config_file);
if (newreq)
goto end;
}
else if( verbose )
BIO_printf(bio_err,"Using configuration from %s\n",
default_config_file);
}
if (req_conf != NULL)
{
if (!load_config(bio_err, req_conf))
goto end;
p=NCONF_get_string(req_conf,NULL,"oid_file");
if (p == NULL)
ERR_clear_error();
if (p != NULL)
{
BIO *oid_bio;
oid_bio=BIO_new_file(p,"r");
if (oid_bio == NULL)
{
}
else
{
OBJ_create_objects(oid_bio);
BIO_free(oid_bio);
}
}
}
if(!add_oid_section(bio_err, req_conf)) goto end;
if (md_alg == NULL)
{
p=NCONF_get_string(req_conf,SECTION,"default_md");
if (p == NULL)
ERR_clear_error();
if (p != NULL)
{
if ((md_alg=EVP_get_digestbyname(p)) != NULL)
digest=md_alg;
}
}
if (!extensions)
{
extensions = NCONF_get_string(req_conf, SECTION, V3_EXTENSIONS);
if (!extensions)
ERR_clear_error();
}
if (extensions) {
X509V3_CTX ctx;
X509V3_set_ctx_test(&ctx);
X509V3_set_nconf(&ctx, req_conf);
if(!X509V3_EXT_add_nconf(req_conf, &ctx, extensions, NULL)) {
BIO_printf(bio_err,
"Error Loading extension section %s\n", extensions);
goto end;
}
}
if(!passin)
{
passin = NCONF_get_string(req_conf, SECTION, "input_password");
if (!passin)
ERR_clear_error();
}
if(!passout)
{
passout = NCONF_get_string(req_conf, SECTION, "output_password");
if (!passout)
ERR_clear_error();
}
p = NCONF_get_string(req_conf, SECTION, STRING_MASK);
if (!p)
ERR_clear_error();
if(p && !ASN1_STRING_set_default_mask_asc(p)) {
BIO_printf(bio_err, "Invalid global string mask setting %s\n", p);
goto end;
}
if (chtype != MBSTRING_UTF8)
{
p = NCONF_get_string(req_conf, SECTION, UTF8_IN);
if (!p)
ERR_clear_error();
else if (!strcmp(p, "yes"))
chtype = MBSTRING_UTF8;
}
if(!req_exts)
{
req_exts = NCONF_get_string(req_conf, SECTION, REQ_EXTENSIONS);
if (!req_exts)
ERR_clear_error();
}
if(req_exts) {
X509V3_CTX ctx;
X509V3_set_ctx_test(&ctx);
X509V3_set_nconf(&ctx, req_conf);
if(!X509V3_EXT_add_nconf(req_conf, &ctx, req_exts, NULL)) {
BIO_printf(bio_err,
"Error Loading request extension section %s\n",
req_exts);
goto end;
}
}
in=BIO_new(BIO_s_file());
out=BIO_new(BIO_s_file());
if ((in == NULL) || (out == NULL))
goto end;
#ifndef OPENSSL_NO_ENGINE
e = setup_engine(bio_err, engine, 0);
#endif
if (keyfile != NULL)
{
pkey = load_key(bio_err, keyfile, keyform, 0, passin, e,
"Private Key");
if (!pkey)
{
goto end;
}
else
{
char *randfile = NCONF_get_string(req_conf,SECTION,"RANDFILE");
if (randfile == NULL)
ERR_clear_error();
app_RAND_load_file(randfile, bio_err, 0);
}
}
if (newreq && (pkey == NULL))
{
char *randfile = NCONF_get_string(req_conf,SECTION,"RANDFILE");
if (randfile == NULL)
ERR_clear_error();
app_RAND_load_file(randfile, bio_err, 0);
if (inrand)
app_RAND_load_files(inrand);
if (keyalg)
{
genctx = set_keygen_ctx(bio_err, keyalg, &pkey_type, &newkey,
&keyalgstr, gen_eng);
if (!genctx)
goto end;
}
if (newkey <= 0)
{
if (!NCONF_get_number(req_conf,SECTION,BITS, &newkey))
newkey=DEFAULT_KEY_LENGTH;
}
if (newkey < MIN_KEY_LENGTH && (pkey_type == EVP_PKEY_RSA || pkey_type == EVP_PKEY_DSA))
{
BIO_printf(bio_err,"private key length is too short,\n");
BIO_printf(bio_err,"it needs to be at least %d bits, not %ld\n",MIN_KEY_LENGTH,newkey);
goto end;
}
if (!genctx)
{
genctx = set_keygen_ctx(bio_err, NULL, &pkey_type, &newkey,
&keyalgstr, gen_eng);
if (!genctx)
goto end;
}
if (pkeyopts)
{
char *genopt;
for (i = 0; i < sk_OPENSSL_STRING_num(pkeyopts); i++)
{
genopt = sk_OPENSSL_STRING_value(pkeyopts, i);
if (pkey_ctrl_string(genctx, genopt) <= 0)
{
BIO_printf(bio_err,
"parameter error \"%s\"\n",
genopt);
ERR_print_errors(bio_err);
goto end;
}
}
}
BIO_printf(bio_err,"Generating a %ld bit %s private key\n",
newkey, keyalgstr);
EVP_PKEY_CTX_set_cb(genctx, genpkey_cb);
EVP_PKEY_CTX_set_app_data(genctx, bio_err);
if (EVP_PKEY_keygen(genctx, &pkey) <= 0)
{
BIO_puts(bio_err, "Error Generating Key\n");
goto end;
}
EVP_PKEY_CTX_free(genctx);
genctx = NULL;
app_RAND_write_file(randfile, bio_err);
if (keyout == NULL)
{
keyout=NCONF_get_string(req_conf,SECTION,KEYFILE);
if (keyout == NULL)
ERR_clear_error();
}
if (keyout == NULL)
{
BIO_printf(bio_err,"writing new private key to stdout\n");
BIO_set_fp(out,stdout,BIO_NOCLOSE);
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
}
else
{
BIO_printf(bio_err,"writing new private key to '%s'\n",keyout);
if (BIO_write_filename(out,keyout) <= 0)
{
perror(keyout);
goto end;
}
}
p=NCONF_get_string(req_conf,SECTION,"encrypt_rsa_key");
if (p == NULL)
{
ERR_clear_error();
p=NCONF_get_string(req_conf,SECTION,"encrypt_key");
if (p == NULL)
ERR_clear_error();
}
if ((p != NULL) && (strcmp(p,"no") == 0))
cipher=NULL;
if (nodes) cipher=NULL;
i=0;
loop:
if (!PEM_write_bio_PrivateKey(out,pkey,cipher,
NULL,0,NULL,passout))
{
if ((ERR_GET_REASON(ERR_peek_error()) ==
PEM_R_PROBLEMS_GETTING_PASSWORD) && (i < 3))
{
ERR_clear_error();
i++;
goto loop;
}
goto end;
}
BIO_printf(bio_err,"-----\n");
}
if (!newreq)
{
kludge= -1;
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
if (informat == FORMAT_ASN1)
req=d2i_X509_REQ_bio(in,NULL);
else if (informat == FORMAT_PEM)
req=PEM_read_bio_X509_REQ(in,NULL,NULL,NULL);
else
{
BIO_printf(bio_err,"bad input format specified for X509 request\n");
goto end;
}
if (req == NULL)
{
BIO_printf(bio_err,"unable to load X509 request\n");
goto end;
}
}
if (newreq || x509)
{
if (pkey == NULL)
{
BIO_printf(bio_err,"you need to specify a private key\n");
goto end;
}
if (req == NULL)
{
req=X509_REQ_new();
if (req == NULL)
{
goto end;
}
i=make_REQ(req,pkey,subj,multirdn,!x509, chtype);
subj=NULL;
if ((kludge > 0) && !sk_X509_ATTRIBUTE_num(req->req_info->attributes))
{
sk_X509_ATTRIBUTE_free(req->req_info->attributes);
req->req_info->attributes = NULL;
}
if (!i)
{
BIO_printf(bio_err,"problems making Certificate Request\n");
goto end;
}
}
if (x509)
{
EVP_PKEY *tmppkey;
X509V3_CTX ext_ctx;
if ((x509ss=X509_new()) == NULL) goto end;
if(extensions && !X509_set_version(x509ss, 2)) goto end;
if (serial)
{
if (!X509_set_serialNumber(x509ss, serial)) goto end;
}
else
{
if (!rand_serial(NULL,
X509_get_serialNumber(x509ss)))
goto end;
}
if (!X509_set_issuer_name(x509ss, X509_REQ_get_subject_name(req))) goto end;
if (!X509_gmtime_adj(X509_get_notBefore(x509ss),0)) goto end;
if (!X509_time_adj_ex(X509_get_notAfter(x509ss), days, 0, NULL)) goto end;
if (!X509_set_subject_name(x509ss, X509_REQ_get_subject_name(req))) goto end;
tmppkey = X509_REQ_get_pubkey(req);
if (!tmppkey || !X509_set_pubkey(x509ss,tmppkey)) goto end;
EVP_PKEY_free(tmppkey);
X509V3_set_ctx(&ext_ctx, x509ss, x509ss, NULL, NULL, 0);
X509V3_set_nconf(&ext_ctx, req_conf);
if(extensions && !X509V3_EXT_add_nconf(req_conf,
&ext_ctx, extensions, x509ss))
{
BIO_printf(bio_err,
"Error Loading extension section %s\n",
extensions);
goto end;
}
i=do_X509_sign(bio_err, x509ss, pkey, digest, sigopts);
if (!i)
{
ERR_print_errors(bio_err);
goto end;
}
}
else
{
X509V3_CTX ext_ctx;
X509V3_set_ctx(&ext_ctx, NULL, NULL, req, NULL, 0);
X509V3_set_nconf(&ext_ctx, req_conf);
if(req_exts && !X509V3_EXT_REQ_add_nconf(req_conf,
&ext_ctx, req_exts, req))
{
BIO_printf(bio_err,
"Error Loading extension section %s\n",
req_exts);
goto end;
}
i=do_X509_REQ_sign(bio_err, req, pkey, digest, sigopts);
if (!i)
{
ERR_print_errors(bio_err);
goto end;
}
}
}
if (subj && x509)
{
BIO_printf(bio_err, "Cannot modifiy certificate subject\n");
goto end;
}
if (subj && !x509)
{
if (verbose)
{
BIO_printf(bio_err, "Modifying Request's Subject\n");
print_name(bio_err, "old subject=", X509_REQ_get_subject_name(req), nmflag);
}
if (build_subject(req, subj, chtype, multirdn) == 0)
{
BIO_printf(bio_err, "ERROR: cannot modify subject\n");
ex=1;
goto end;
}
req->req_info->enc.modified = 1;
if (verbose)
{
print_name(bio_err, "new subject=", X509_REQ_get_subject_name(req), nmflag);
}
}
if (verify && !x509)
{
int tmp=0;
if (pkey == NULL)
{
pkey=X509_REQ_get_pubkey(req);
tmp=1;
if (pkey == NULL) goto end;
}
i=X509_REQ_verify(req,pkey);
if (tmp) {
EVP_PKEY_free(pkey);
pkey=NULL;
}
if (i < 0)
{
goto end;
}
else if (i == 0)
{
BIO_printf(bio_err,"verify failure\n");
ERR_print_errors(bio_err);
}
else
BIO_printf(bio_err,"verify OK\n");
}
if (noout && !text && !modulus && !subject && !pubkey)
{
ex=0;
goto end;
}
if (outfile == NULL)
{
BIO_set_fp(out,stdout,BIO_NOCLOSE);
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
}
else
{
if ((keyout != NULL) && (strcmp(outfile,keyout) == 0))
i=(int)BIO_append_filename(out,outfile);
else
i=(int)BIO_write_filename(out,outfile);
if (!i)
{
perror(outfile);
goto end;
}
}
if (pubkey)
{
EVP_PKEY *tpubkey;
tpubkey=X509_REQ_get_pubkey(req);
if (tpubkey == NULL)
{
BIO_printf(bio_err,"Error getting public key\n");
ERR_print_errors(bio_err);
goto end;
}
PEM_write_bio_PUBKEY(out, tpubkey);
EVP_PKEY_free(tpubkey);
}
if (text)
{
if (x509)
X509_print_ex(out, x509ss, nmflag, reqflag);
else
X509_REQ_print_ex(out, req, nmflag, reqflag);
}
if(subject)
{
if(x509)
print_name(out, "subject=", X509_get_subject_name(x509ss), nmflag);
else
print_name(out, "subject=", X509_REQ_get_subject_name(req), nmflag);
}
if (modulus)
{
EVP_PKEY *tpubkey;
if (x509)
tpubkey=X509_get_pubkey(x509ss);
else
tpubkey=X509_REQ_get_pubkey(req);
if (tpubkey == NULL)
{
fprintf(stdout,"Modulus=unavailable\n");
goto end;
}
fprintf(stdout,"Modulus=");
#ifndef OPENSSL_NO_RSA
if (EVP_PKEY_base_id(tpubkey) == EVP_PKEY_RSA)
BN_print(out,tpubkey->pkey.rsa->n);
else
#endif
fprintf(stdout,"Wrong Algorithm type");
EVP_PKEY_free(tpubkey);
fprintf(stdout,"\n");
}
if (!noout && !x509)
{
if (outformat == FORMAT_ASN1)
i=i2d_X509_REQ_bio(out,req);
else if (outformat == FORMAT_PEM) {
if(newhdr) i=PEM_write_bio_X509_REQ_NEW(out,req);
else i=PEM_write_bio_X509_REQ(out,req);
} else {
BIO_printf(bio_err,"bad output format specified for outfile\n");
goto end;
}
if (!i)
{
BIO_printf(bio_err,"unable to write X509 request\n");
goto end;
}
}
if (!noout && x509 && (x509ss != NULL))
{
if (outformat == FORMAT_ASN1)
i=i2d_X509_bio(out,x509ss);
else if (outformat == FORMAT_PEM)
i=PEM_write_bio_X509(out,x509ss);
else {
BIO_printf(bio_err,"bad output format specified for outfile\n");
goto end;
}
if (!i)
{
BIO_printf(bio_err,"unable to write X509 certificate\n");
goto end;
}
}
ex=0;
end:
#ifndef MONOLITH
if(to_free)
OPENSSL_free(to_free);
#endif
if (ex)
{
ERR_print_errors(bio_err);
}
if ((req_conf != NULL) && (req_conf != config)) NCONF_free(req_conf);
BIO_free(in);
BIO_free_all(out);
EVP_PKEY_free(pkey);
if (genctx)
EVP_PKEY_CTX_free(genctx);
if (pkeyopts)
sk_OPENSSL_STRING_free(pkeyopts);
if (sigopts)
sk_OPENSSL_STRING_free(sigopts);
#ifndef OPENSSL_NO_ENGINE
if (gen_eng)
ENGINE_free(gen_eng);
#endif
if (keyalgstr)
OPENSSL_free(keyalgstr);
X509_REQ_free(req);
X509_free(x509ss);
ASN1_INTEGER_free(serial);
if(passargin && passin) OPENSSL_free(passin);
if(passargout && passout) OPENSSL_free(passout);
OBJ_cleanup();
apps_shutdown();
OPENSSL_EXIT(ex);
}
static int make_REQ(X509_REQ *req, EVP_PKEY *pkey, char *subj, int multirdn,
int attribs, unsigned long chtype)
{
int ret=0,i;
char no_prompt = 0;
STACK_OF(CONF_VALUE) *dn_sk, *attr_sk = NULL;
char *tmp, *dn_sect,*attr_sect;
tmp=NCONF_get_string(req_conf,SECTION,PROMPT);
if (tmp == NULL)
ERR_clear_error();
if((tmp != NULL) && !strcmp(tmp, "no")) no_prompt = 1;
dn_sect=NCONF_get_string(req_conf,SECTION,DISTINGUISHED_NAME);
if (dn_sect == NULL)
{
BIO_printf(bio_err,"unable to find '%s' in config\n",
DISTINGUISHED_NAME);
goto err;
}
dn_sk=NCONF_get_section(req_conf,dn_sect);
if (dn_sk == NULL)
{
BIO_printf(bio_err,"unable to get '%s' section\n",dn_sect);
goto err;
}
attr_sect=NCONF_get_string(req_conf,SECTION,ATTRIBUTES);
if (attr_sect == NULL)
{
ERR_clear_error();
attr_sk=NULL;
}
else
{
attr_sk=NCONF_get_section(req_conf,attr_sect);
if (attr_sk == NULL)
{
BIO_printf(bio_err,"unable to get '%s' section\n",attr_sect);
goto err;
}
}
if (!X509_REQ_set_version(req,0L)) goto err;
if (no_prompt)
i = auto_info(req, dn_sk, attr_sk, attribs, chtype);
else
{
if (subj)
i = build_subject(req, subj, chtype, multirdn);
else
i = prompt_info(req, dn_sk, dn_sect, attr_sk, attr_sect, attribs, chtype);
}
if(!i) goto err;
if (!X509_REQ_set_pubkey(req,pkey)) goto err;
ret=1;
err:
return(ret);
}
static int build_subject(X509_REQ *req, char *subject, unsigned long chtype, int multirdn)
{
X509_NAME *n;
if (!(n = parse_name(subject, chtype, multirdn)))
return 0;
if (!X509_REQ_set_subject_name(req, n))
{
X509_NAME_free(n);
return 0;
}
X509_NAME_free(n);
return 1;
}
static int add_DN_object(X509_NAME *n, char *text, const char *def, char *value,
int nid, int n_min, int n_max, unsigned long chtype, int mval)
{
int i,ret=0;
MS_STATIC char buf[1024];
start:
if (!batch) BIO_printf(bio_err,"%s [%s]:",text,def);
(void)BIO_flush(bio_err);
if(value != NULL)
{
BUF_strlcpy(buf,value,sizeof buf);
BUF_strlcat(buf,"\n",sizeof buf);
BIO_printf(bio_err,"%s\n",value);
}
else
{
buf[0]='\0';
if (!batch)
{
if (!fgets(buf,sizeof buf,stdin))
return 0;
}
else
{
buf[0] = '\n';
buf[1] = '\0';
}
}
if (buf[0] == '\0') return(0);
else if (buf[0] == '\n')
{
if ((def == NULL) || (def[0] == '\0'))
return(1);
BUF_strlcpy(buf,def,sizeof buf);
BUF_strlcat(buf,"\n",sizeof buf);
}
else if ((buf[0] == '.') && (buf[1] == '\n')) return(1);
i=strlen(buf);
if (buf[i-1] != '\n')
{
BIO_printf(bio_err,"weird input :-(\n");
return(0);
}
buf[--i]='\0';
#ifdef CHARSET_EBCDIC
ebcdic2ascii(buf, buf, i);
#endif
if(!req_check_len(i, n_min, n_max)) goto start;
if (!X509_NAME_add_entry_by_NID(n,nid, chtype,
(unsigned char *) buf, -1,-1,mval)) goto err;
ret=1;
err:
return(ret);
}
static int add_attribute_object(X509_REQ *req, char *text, const char *def,
char *value, int nid, int n_min,
int n_max, unsigned long chtype)
{
int i;
static char buf[1024];
start:
if (!batch) BIO_printf(bio_err,"%s [%s]:",text,def);
(void)BIO_flush(bio_err);
if (value != NULL)
{
BUF_strlcpy(buf,value,sizeof buf);
BUF_strlcat(buf,"\n",sizeof buf);
BIO_printf(bio_err,"%s\n",value);
}
else
{
buf[0]='\0';
if (!batch)
{
if (!fgets(buf,sizeof buf,stdin))
return 0;
}
else
{
buf[0] = '\n';
buf[1] = '\0';
}
}
if (buf[0] == '\0') return(0);
else if (buf[0] == '\n')
{
if ((def == NULL) || (def[0] == '\0'))
return(1);
BUF_strlcpy(buf,def,sizeof buf);
BUF_strlcat(buf,"\n",sizeof buf);
}
else if ((buf[0] == '.') && (buf[1] == '\n')) return(1);
i=strlen(buf);
if (buf[i-1] != '\n')
{
BIO_printf(bio_err,"weird input :-(\n");
return(0);
}
buf[--i]='\0';
#ifdef CHARSET_EBCDIC
ebcdic2ascii(buf, buf, i);
#endif
if(!req_check_len(i, n_min, n_max)) goto start;
if(!X509_REQ_add1_attr_by_NID(req, nid, chtype,
(unsigned char *)buf, -1)) {
BIO_printf(bio_err, "Error adding attribute\n");
ERR_print_errors(bio_err);
goto err;
}
return(1);
err:
return(0);
}
static int req_check_len(int len, int n_min, int n_max)
{
if ((n_min > 0) && (len < n_min))
{
BIO_printf(bio_err,"string is too short, it needs to be at least %d bytes long\n",n_min);
return(0);
}
if ((n_max >= 0) && (len > n_max))
{
BIO_printf(bio_err,"string is too long, it needs to be less than %d bytes long\n",n_max);
return(0);
}
return(1);
}
static int check_end(const char *str, const char *end)
{
int elen, slen;
const char *tmp;
elen = strlen(end);
slen = strlen(str);
if(elen > slen) return 1;
tmp = str + slen - elen;
return strcmp(tmp, end);
}
static EVP_PKEY_CTX *set_keygen_ctx(BIO *err, const char *gstr, int *pkey_type,
long *pkeylen, char **palgnam,
ENGINE *keygen_engine)
{
EVP_PKEY_CTX *gctx = NULL;
EVP_PKEY *param = NULL;
long keylen = -1;
BIO *pbio = NULL;
const char *paramfile = NULL;
if (gstr == NULL)
{
*pkey_type = EVP_PKEY_RSA;
keylen = *pkeylen;
}
else if (gstr[0] >= '0' && gstr[0] <= '9')
{
*pkey_type = EVP_PKEY_RSA;
keylen = atol(gstr);
*pkeylen = keylen;
}
else if (!strncmp(gstr, "param:", 6))
paramfile = gstr + 6;
else
{
const char *p = strchr(gstr, ':');
int len;
ENGINE *tmpeng;
const EVP_PKEY_ASN1_METHOD *ameth;
if (p)
len = p - gstr;
else
len = strlen(gstr);
ameth = EVP_PKEY_asn1_find_str(&tmpeng, gstr, len);
if (!ameth)
{
BIO_printf(err, "Unknown algorithm %.*s\n", len, gstr);
return NULL;
}
EVP_PKEY_asn1_get0_info(NULL, pkey_type, NULL, NULL, NULL,
ameth);
#ifndef OPENSSL_NO_ENGINE
if (tmpeng)
ENGINE_finish(tmpeng);
#endif
if (*pkey_type == EVP_PKEY_RSA)
{
if (p)
{
keylen = atol(p + 1);
*pkeylen = keylen;
}
}
else if (p)
paramfile = p + 1;
}
if (paramfile)
{
pbio = BIO_new_file(paramfile, "r");
if (!pbio)
{
BIO_printf(err, "Can't open parameter file %s\n",
paramfile);
return NULL;
}
param = PEM_read_bio_Parameters(pbio, NULL);
if (!param)
{
X509 *x;
(void)BIO_reset(pbio);
x = PEM_read_bio_X509(pbio, NULL, NULL, NULL);
if (x)
{
param = X509_get_pubkey(x);
X509_free(x);
}
}
BIO_free(pbio);
if (!param)
{
BIO_printf(err, "Error reading parameter file %s\n",
paramfile);
return NULL;
}
if (*pkey_type == -1)
*pkey_type = EVP_PKEY_id(param);
else if (*pkey_type != EVP_PKEY_base_id(param))
{
BIO_printf(err, "Key Type does not match parameters\n");
EVP_PKEY_free(param);
return NULL;
}
}
if (palgnam)
{
const EVP_PKEY_ASN1_METHOD *ameth;
ENGINE *tmpeng;
const char *anam;
ameth = EVP_PKEY_asn1_find(&tmpeng, *pkey_type);
if (!ameth)
{
BIO_puts(err, "Internal error: can't find key algorithm\n");
return NULL;
}
EVP_PKEY_asn1_get0_info(NULL, NULL, NULL, NULL, &anam, ameth);
*palgnam = BUF_strdup(anam);
#ifndef OPENSSL_NO_ENGINE
if (tmpeng)
ENGINE_finish(tmpeng);
#endif
}
if (param)
{
gctx = EVP_PKEY_CTX_new(param, keygen_engine);
*pkeylen = EVP_PKEY_bits(param);
EVP_PKEY_free(param);
}
else
gctx = EVP_PKEY_CTX_new_id(*pkey_type, keygen_engine);
if (!gctx)
{
BIO_puts(err, "Error allocating keygen context\n");
ERR_print_errors(err);
return NULL;
}
if (EVP_PKEY_keygen_init(gctx) <= 0)
{
BIO_puts(err, "Error initializing keygen context\n");
ERR_print_errors(err);
return NULL;
}
#ifndef OPENSSL_NO_RSA
if ((*pkey_type == EVP_PKEY_RSA) && (keylen != -1))
{
if (EVP_PKEY_CTX_set_rsa_keygen_bits(gctx, keylen) <= 0)
{
BIO_puts(err, "Error setting RSA keysize\n");
ERR_print_errors(err);
EVP_PKEY_CTX_free(gctx);
return NULL;
}
}
#endif
return gctx;
}
static int genpkey_cb(EVP_PKEY_CTX *ctx)
{
char c='*';
BIO *b = EVP_PKEY_CTX_get_app_data(ctx);
int p;
p = EVP_PKEY_CTX_get_keygen_info(ctx, 0);
if (p == 0) c='.';
if (p == 1) c='+';
if (p == 2) c='*';
if (p == 3) c='\n';
BIO_write(b,&c,1);
(void)BIO_flush(b);
#ifdef LINT
p=n;
#endif
return 1;
}
