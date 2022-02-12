int MAIN(int argc, char **argv)
{
ENGINE *e = NULL;
int ret = 1;
X509_REQ *req = NULL;
X509 *x = NULL, *xca = NULL;
ASN1_OBJECT *objtmp;
STACK_OF(OPENSSL_STRING) *sigopts = NULL;
EVP_PKEY *Upkey = NULL, *CApkey = NULL, *fkey = NULL;
ASN1_INTEGER *sno = NULL;
int i, num, badops = 0, badsig = 0;
BIO *out = NULL;
BIO *STDout = NULL;
STACK_OF(ASN1_OBJECT) *trust = NULL, *reject = NULL;
int informat, outformat, keyformat, CAformat, CAkeyformat;
char *infile = NULL, *outfile = NULL, *keyfile = NULL, *CAfile = NULL;
char *CAkeyfile = NULL, *CAserial = NULL;
char *fkeyfile = NULL;
char *alias = NULL;
int text = 0, serial = 0, subject = 0, issuer = 0, startdate =
0, enddate = 0;
int next_serial = 0;
int subject_hash = 0, issuer_hash = 0, ocspid = 0;
#ifndef OPENSSL_NO_MD5
int subject_hash_old = 0, issuer_hash_old = 0;
#endif
int noout = 0, sign_flag = 0, CA_flag = 0, CA_createserial = 0, email = 0;
int ocsp_uri = 0;
int trustout = 0, clrtrust = 0, clrreject = 0, aliasout = 0, clrext = 0;
int C = 0;
int x509req = 0, days = DEF_DAYS, modulus = 0, pubkey = 0;
int pprint = 0;
const char **pp;
X509_STORE *ctx = NULL;
X509_REQ *rq = NULL;
int fingerprint = 0;
char buf[256];
const EVP_MD *md_alg, *digest = NULL;
CONF *extconf = NULL;
char *extsect = NULL, *extfile = NULL, *passin = NULL, *passargin = NULL;
int need_rand = 0;
int checkend = 0, checkoffset = 0;
unsigned long nmflag = 0, certflag = 0;
char *checkhost = NULL;
char *checkemail = NULL;
char *checkip = NULL;
#ifndef OPENSSL_NO_ENGINE
char *engine = NULL;
#endif
reqfile = 0;
apps_startup();
if (bio_err == NULL)
bio_err = BIO_new_fp(stderr, BIO_NOCLOSE);
if (!load_config(bio_err, NULL))
goto end;
STDout = BIO_new_fp(stdout, BIO_NOCLOSE);
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
STDout = BIO_push(tmpbio, STDout);
}
#endif
informat = FORMAT_PEM;
outformat = FORMAT_PEM;
keyformat = FORMAT_PEM;
CAformat = FORMAT_PEM;
CAkeyformat = FORMAT_PEM;
ctx = X509_STORE_new();
if (ctx == NULL)
goto end;
X509_STORE_set_verify_cb(ctx, callb);
argc--;
argv++;
num = 0;
while (argc >= 1) {
if (strcmp(*argv, "-inform") == 0) {
if (--argc < 1)
goto bad;
informat = str2fmt(*(++argv));
} else if (strcmp(*argv, "-outform") == 0) {
if (--argc < 1)
goto bad;
outformat = str2fmt(*(++argv));
} else if (strcmp(*argv, "-keyform") == 0) {
if (--argc < 1)
goto bad;
keyformat = str2fmt(*(++argv));
} else if (strcmp(*argv, "-req") == 0) {
reqfile = 1;
need_rand = 1;
} else if (strcmp(*argv, "-CAform") == 0) {
if (--argc < 1)
goto bad;
CAformat = str2fmt(*(++argv));
} else if (strcmp(*argv, "-CAkeyform") == 0) {
if (--argc < 1)
goto bad;
CAkeyformat = str2fmt(*(++argv));
} else if (strcmp(*argv, "-sigopt") == 0) {
if (--argc < 1)
goto bad;
if (!sigopts)
sigopts = sk_OPENSSL_STRING_new_null();
if (!sigopts || !sk_OPENSSL_STRING_push(sigopts, *(++argv)))
goto bad;
}
#ifdef OPENSSL_SSL_DEBUG_BROKEN_PROTOCOL
else if (strcmp(*argv, "-force_version") == 0) {
if (--argc < 1)
goto bad;
force_version = atoi(*(++argv)) - 1;
}
#endif
else if (strcmp(*argv, "-days") == 0) {
if (--argc < 1)
goto bad;
days = atoi(*(++argv));
if (days == 0) {
BIO_printf(bio_err, "bad number of days\n");
goto bad;
}
} else if (strcmp(*argv, "-passin") == 0) {
if (--argc < 1)
goto bad;
passargin = *(++argv);
} else if (strcmp(*argv, "-extfile") == 0) {
if (--argc < 1)
goto bad;
extfile = *(++argv);
} else if (strcmp(*argv, "-extensions") == 0) {
if (--argc < 1)
goto bad;
extsect = *(++argv);
} else if (strcmp(*argv, "-in") == 0) {
if (--argc < 1)
goto bad;
infile = *(++argv);
} else if (strcmp(*argv, "-out") == 0) {
if (--argc < 1)
goto bad;
outfile = *(++argv);
} else if (strcmp(*argv, "-signkey") == 0) {
if (--argc < 1)
goto bad;
keyfile = *(++argv);
sign_flag = ++num;
need_rand = 1;
} else if (strcmp(*argv, "-CA") == 0) {
if (--argc < 1)
goto bad;
CAfile = *(++argv);
CA_flag = ++num;
need_rand = 1;
} else if (strcmp(*argv, "-CAkey") == 0) {
if (--argc < 1)
goto bad;
CAkeyfile = *(++argv);
} else if (strcmp(*argv, "-CAserial") == 0) {
if (--argc < 1)
goto bad;
CAserial = *(++argv);
} else if (strcmp(*argv, "-set_serial") == 0) {
if (--argc < 1)
goto bad;
if (!(sno = s2i_ASN1_INTEGER(NULL, *(++argv))))
goto bad;
} else if (strcmp(*argv, "-force_pubkey") == 0) {
if (--argc < 1)
goto bad;
fkeyfile = *(++argv);
} else if (strcmp(*argv, "-addtrust") == 0) {
if (--argc < 1)
goto bad;
if (!(objtmp = OBJ_txt2obj(*(++argv), 0))) {
BIO_printf(bio_err, "Invalid trust object value %s\n", *argv);
goto bad;
}
if (!trust)
trust = sk_ASN1_OBJECT_new_null();
sk_ASN1_OBJECT_push(trust, objtmp);
trustout = 1;
} else if (strcmp(*argv, "-addreject") == 0) {
if (--argc < 1)
goto bad;
if (!(objtmp = OBJ_txt2obj(*(++argv), 0))) {
BIO_printf(bio_err,
"Invalid reject object value %s\n", *argv);
goto bad;
}
if (!reject)
reject = sk_ASN1_OBJECT_new_null();
sk_ASN1_OBJECT_push(reject, objtmp);
trustout = 1;
} else if (strcmp(*argv, "-setalias") == 0) {
if (--argc < 1)
goto bad;
alias = *(++argv);
trustout = 1;
} else if (strcmp(*argv, "-certopt") == 0) {
if (--argc < 1)
goto bad;
if (!set_cert_ex(&certflag, *(++argv)))
goto bad;
} else if (strcmp(*argv, "-nameopt") == 0) {
if (--argc < 1)
goto bad;
if (!set_name_ex(&nmflag, *(++argv)))
goto bad;
}
#ifndef OPENSSL_NO_ENGINE
else if (strcmp(*argv, "-engine") == 0) {
if (--argc < 1)
goto bad;
engine = *(++argv);
}
#endif
else if (strcmp(*argv, "-C") == 0)
C = ++num;
else if (strcmp(*argv, "-email") == 0)
email = ++num;
else if (strcmp(*argv, "-ocsp_uri") == 0)
ocsp_uri = ++num;
else if (strcmp(*argv, "-serial") == 0)
serial = ++num;
else if (strcmp(*argv, "-next_serial") == 0)
next_serial = ++num;
else if (strcmp(*argv, "-modulus") == 0)
modulus = ++num;
else if (strcmp(*argv, "-pubkey") == 0)
pubkey = ++num;
else if (strcmp(*argv, "-x509toreq") == 0)
x509req = ++num;
else if (strcmp(*argv, "-text") == 0)
text = ++num;
else if (strcmp(*argv, "-hash") == 0
|| strcmp(*argv, "-subject_hash") == 0)
subject_hash = ++num;
#ifndef OPENSSL_NO_MD5
else if (strcmp(*argv, "-subject_hash_old") == 0)
subject_hash_old = ++num;
#endif
else if (strcmp(*argv, "-issuer_hash") == 0)
issuer_hash = ++num;
#ifndef OPENSSL_NO_MD5
else if (strcmp(*argv, "-issuer_hash_old") == 0)
issuer_hash_old = ++num;
#endif
else if (strcmp(*argv, "-subject") == 0)
subject = ++num;
else if (strcmp(*argv, "-issuer") == 0)
issuer = ++num;
else if (strcmp(*argv, "-fingerprint") == 0)
fingerprint = ++num;
else if (strcmp(*argv, "-dates") == 0) {
startdate = ++num;
enddate = ++num;
} else if (strcmp(*argv, "-purpose") == 0)
pprint = ++num;
else if (strcmp(*argv, "-startdate") == 0)
startdate = ++num;
else if (strcmp(*argv, "-enddate") == 0)
enddate = ++num;
else if (strcmp(*argv, "-checkend") == 0) {
if (--argc < 1)
goto bad;
checkoffset = atoi(*(++argv));
checkend = 1;
} else if (strcmp(*argv, "-checkhost") == 0) {
if (--argc < 1)
goto bad;
checkhost = *(++argv);
} else if (strcmp(*argv, "-checkemail") == 0) {
if (--argc < 1)
goto bad;
checkemail = *(++argv);
} else if (strcmp(*argv, "-checkip") == 0) {
if (--argc < 1)
goto bad;
checkip = *(++argv);
} else if (strcmp(*argv, "-noout") == 0)
noout = ++num;
else if (strcmp(*argv, "-trustout") == 0)
trustout = 1;
else if (strcmp(*argv, "-clrtrust") == 0)
clrtrust = ++num;
else if (strcmp(*argv, "-clrreject") == 0)
clrreject = ++num;
else if (strcmp(*argv, "-alias") == 0)
aliasout = ++num;
else if (strcmp(*argv, "-CAcreateserial") == 0)
CA_createserial = ++num;
else if (strcmp(*argv, "-clrext") == 0)
clrext = 1;
#if 1
else if (strcmp(*argv, "-crlext") == 0) {
BIO_printf(bio_err, "use -clrext instead of -crlext\n");
clrext = 1;
}
#endif
else if (strcmp(*argv, "-ocspid") == 0)
ocspid = ++num;
else if (strcmp(*argv, "-badsig") == 0)
badsig = 1;
else if ((md_alg = EVP_get_digestbyname(*argv + 1))) {
digest = md_alg;
} else {
BIO_printf(bio_err, "unknown option %s\n", *argv);
badops = 1;
break;
}
argc--;
argv++;
}
if (badops) {
bad:
for (pp = x509_usage; (*pp != NULL); pp++)
BIO_printf(bio_err, "%s", *pp);
goto end;
}
#ifndef OPENSSL_NO_ENGINE
e = setup_engine(bio_err, engine, 0);
#endif
if (need_rand)
app_RAND_load_file(NULL, bio_err, 0);
ERR_load_crypto_strings();
if (!app_passwd(bio_err, passargin, NULL, &passin, NULL)) {
BIO_printf(bio_err, "Error getting password\n");
goto end;
}
if (!X509_STORE_set_default_paths(ctx)) {
ERR_print_errors(bio_err);
goto end;
}
if (fkeyfile) {
fkey = load_pubkey(bio_err, fkeyfile, keyformat, 0,
NULL, e, "Forced key");
if (fkey == NULL)
goto end;
}
if ((CAkeyfile == NULL) && (CA_flag) && (CAformat == FORMAT_PEM)) {
CAkeyfile = CAfile;
} else if ((CA_flag) && (CAkeyfile == NULL)) {
BIO_printf(bio_err,
"need to specify a CAkey if using the CA command\n");
goto end;
}
if (extfile) {
long errorline = -1;
X509V3_CTX ctx2;
extconf = NCONF_new(NULL);
if (!NCONF_load(extconf, extfile, &errorline)) {
if (errorline <= 0)
BIO_printf(bio_err,
"error loading the config file '%s'\n", extfile);
else
BIO_printf(bio_err,
"error on line %ld of config file '%s'\n",
errorline, extfile);
goto end;
}
if (!extsect) {
extsect = NCONF_get_string(extconf, "default", "extensions");
if (!extsect) {
ERR_clear_error();
extsect = "default";
}
}
X509V3_set_ctx_test(&ctx2);
X509V3_set_nconf(&ctx2, extconf);
if (!X509V3_EXT_add_nconf(extconf, &ctx2, extsect, NULL)) {
BIO_printf(bio_err,
"Error Loading extension section %s\n", extsect);
ERR_print_errors(bio_err);
goto end;
}
}
if (reqfile) {
EVP_PKEY *pkey;
BIO *in;
if (!sign_flag && !CA_flag) {
BIO_printf(bio_err, "We need a private key to sign with\n");
goto end;
}
in = BIO_new(BIO_s_file());
if (in == NULL) {
ERR_print_errors(bio_err);
goto end;
}
if (infile == NULL)
BIO_set_fp(in, stdin, BIO_NOCLOSE | BIO_FP_TEXT);
else {
if (BIO_read_filename(in, infile) <= 0) {
perror(infile);
BIO_free(in);
goto end;
}
}
req = PEM_read_bio_X509_REQ(in, NULL, NULL, NULL);
BIO_free(in);
if (req == NULL) {
ERR_print_errors(bio_err);
goto end;
}
if ((req->req_info == NULL) ||
(req->req_info->pubkey == NULL) ||
(req->req_info->pubkey->public_key == NULL) ||
(req->req_info->pubkey->public_key->data == NULL)) {
BIO_printf(bio_err,
"The certificate request appears to corrupted\n");
BIO_printf(bio_err, "It does not contain a public key\n");
goto end;
}
if ((pkey = X509_REQ_get_pubkey(req)) == NULL) {
BIO_printf(bio_err, "error unpacking public key\n");
goto end;
}
i = X509_REQ_verify(req, pkey);
EVP_PKEY_free(pkey);
if (i < 0) {
BIO_printf(bio_err, "Signature verification error\n");
ERR_print_errors(bio_err);
goto end;
}
if (i == 0) {
BIO_printf(bio_err,
"Signature did not match the certificate request\n");
goto end;
} else
BIO_printf(bio_err, "Signature ok\n");
print_name(bio_err, "subject=", X509_REQ_get_subject_name(req),
nmflag);
if ((x = X509_new()) == NULL)
goto end;
if (sno == NULL) {
sno = ASN1_INTEGER_new();
if (!sno || !rand_serial(NULL, sno))
goto end;
if (!X509_set_serialNumber(x, sno))
goto end;
ASN1_INTEGER_free(sno);
sno = NULL;
} else if (!X509_set_serialNumber(x, sno))
goto end;
if (!X509_set_issuer_name(x, req->req_info->subject))
goto end;
if (!X509_set_subject_name(x, req->req_info->subject))
goto end;
X509_gmtime_adj(X509_get_notBefore(x), 0);
X509_time_adj_ex(X509_get_notAfter(x), days, 0, NULL);
if (fkey)
X509_set_pubkey(x, fkey);
else {
pkey = X509_REQ_get_pubkey(req);
X509_set_pubkey(x, pkey);
EVP_PKEY_free(pkey);
}
} else
x = load_cert(bio_err, infile, informat, NULL, e, "Certificate");
if (x == NULL)
goto end;
if (CA_flag) {
xca = load_cert(bio_err, CAfile, CAformat, NULL, e, "CA Certificate");
if (xca == NULL)
goto end;
}
if (!noout || text || next_serial) {
OBJ_create("2.99999.3", "SET.ex3", "SET x509v3 extension 3");
out = BIO_new(BIO_s_file());
if (out == NULL) {
ERR_print_errors(bio_err);
goto end;
}
if (outfile == NULL) {
BIO_set_fp(out, stdout, BIO_NOCLOSE);
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
} else {
if (BIO_write_filename(out, outfile) <= 0) {
perror(outfile);
goto end;
}
}
}
if (alias)
X509_alias_set1(x, (unsigned char *)alias, -1);
if (clrtrust)
X509_trust_clear(x);
if (clrreject)
X509_reject_clear(x);
if (trust) {
for (i = 0; i < sk_ASN1_OBJECT_num(trust); i++) {
objtmp = sk_ASN1_OBJECT_value(trust, i);
X509_add1_trust_object(x, objtmp);
}
}
if (reject) {
for (i = 0; i < sk_ASN1_OBJECT_num(reject); i++) {
objtmp = sk_ASN1_OBJECT_value(reject, i);
X509_add1_reject_object(x, objtmp);
}
}
if (num) {
for (i = 1; i <= num; i++) {
if (issuer == i) {
print_name(STDout, "issuer= ",
X509_get_issuer_name(x), nmflag);
} else if (subject == i) {
print_name(STDout, "subject= ",
X509_get_subject_name(x), nmflag);
} else if (serial == i) {
BIO_printf(STDout, "serial=");
i2a_ASN1_INTEGER(STDout, X509_get_serialNumber(x));
BIO_printf(STDout, "\n");
} else if (next_serial == i) {
BIGNUM *bnser;
ASN1_INTEGER *ser;
ser = X509_get_serialNumber(x);
bnser = ASN1_INTEGER_to_BN(ser, NULL);
if (!bnser)
goto end;
if (!BN_add_word(bnser, 1))
goto end;
ser = BN_to_ASN1_INTEGER(bnser, NULL);
if (!ser)
goto end;
BN_free(bnser);
i2a_ASN1_INTEGER(out, ser);
ASN1_INTEGER_free(ser);
BIO_puts(out, "\n");
} else if ((email == i) || (ocsp_uri == i)) {
int j;
STACK_OF(OPENSSL_STRING) *emlst;
if (email == i)
emlst = X509_get1_email(x);
else
emlst = X509_get1_ocsp(x);
for (j = 0; j < sk_OPENSSL_STRING_num(emlst); j++)
BIO_printf(STDout, "%s\n",
sk_OPENSSL_STRING_value(emlst, j));
X509_email_free(emlst);
} else if (aliasout == i) {
unsigned char *alstr;
alstr = X509_alias_get0(x, NULL);
if (alstr)
BIO_printf(STDout, "%s\n", alstr);
else
BIO_puts(STDout, "<No Alias>\n");
} else if (subject_hash == i) {
BIO_printf(STDout, "%08lx\n", X509_subject_name_hash(x));
}
#ifndef OPENSSL_NO_MD5
else if (subject_hash_old == i) {
BIO_printf(STDout, "%08lx\n", X509_subject_name_hash_old(x));
}
#endif
else if (issuer_hash == i) {
BIO_printf(STDout, "%08lx\n", X509_issuer_name_hash(x));
}
#ifndef OPENSSL_NO_MD5
else if (issuer_hash_old == i) {
BIO_printf(STDout, "%08lx\n", X509_issuer_name_hash_old(x));
}
#endif
else if (pprint == i) {
X509_PURPOSE *ptmp;
int j;
BIO_printf(STDout, "Certificate purposes:\n");
for (j = 0; j < X509_PURPOSE_get_count(); j++) {
ptmp = X509_PURPOSE_get0(j);
purpose_print(STDout, x, ptmp);
}
} else if (modulus == i) {
EVP_PKEY *pkey;
pkey = X509_get_pubkey(x);
if (pkey == NULL) {
BIO_printf(bio_err, "Modulus=unavailable\n");
ERR_print_errors(bio_err);
goto end;
}
BIO_printf(STDout, "Modulus=");
#ifndef OPENSSL_NO_RSA
if (pkey->type == EVP_PKEY_RSA)
BN_print(STDout, pkey->pkey.rsa->n);
else
#endif
#ifndef OPENSSL_NO_DSA
if (pkey->type == EVP_PKEY_DSA)
BN_print(STDout, pkey->pkey.dsa->pub_key);
else
#endif
BIO_printf(STDout, "Wrong Algorithm type");
BIO_printf(STDout, "\n");
EVP_PKEY_free(pkey);
} else if (pubkey == i) {
EVP_PKEY *pkey;
pkey = X509_get_pubkey(x);
if (pkey == NULL) {
BIO_printf(bio_err, "Error getting public key\n");
ERR_print_errors(bio_err);
goto end;
}
PEM_write_bio_PUBKEY(STDout, pkey);
EVP_PKEY_free(pkey);
} else if (C == i) {
unsigned char *d;
char *m;
int y, z;
X509_NAME_oneline(X509_get_subject_name(x), buf, sizeof buf);
BIO_printf(STDout, "/* subject:%s */\n", buf);
m = X509_NAME_oneline(X509_get_issuer_name(x), buf,
sizeof buf);
BIO_printf(STDout, "/* issuer :%s */\n", buf);
z = i2d_X509(x, NULL);
m = OPENSSL_malloc(z);
d = (unsigned char *)m;
z = i2d_X509_NAME(X509_get_subject_name(x), &d);
BIO_printf(STDout, "unsigned char XXX_subject_name[%d]={\n",
z);
d = (unsigned char *)m;
for (y = 0; y < z; y++) {
BIO_printf(STDout, "0x%02X,", d[y]);
if ((y & 0x0f) == 0x0f)
BIO_printf(STDout, "\n");
}
if (y % 16 != 0)
BIO_printf(STDout, "\n");
BIO_printf(STDout, "};\n");
z = i2d_X509_PUBKEY(X509_get_X509_PUBKEY(x), &d);
BIO_printf(STDout, "unsigned char XXX_public_key[%d]={\n", z);
d = (unsigned char *)m;
for (y = 0; y < z; y++) {
BIO_printf(STDout, "0x%02X,", d[y]);
if ((y & 0x0f) == 0x0f)
BIO_printf(STDout, "\n");
}
if (y % 16 != 0)
BIO_printf(STDout, "\n");
BIO_printf(STDout, "};\n");
z = i2d_X509(x, &d);
BIO_printf(STDout, "unsigned char XXX_certificate[%d]={\n",
z);
d = (unsigned char *)m;
for (y = 0; y < z; y++) {
BIO_printf(STDout, "0x%02X,", d[y]);
if ((y & 0x0f) == 0x0f)
BIO_printf(STDout, "\n");
}
if (y % 16 != 0)
BIO_printf(STDout, "\n");
BIO_printf(STDout, "};\n");
OPENSSL_free(m);
} else if (text == i) {
X509_print_ex(STDout, x, nmflag, certflag);
} else if (startdate == i) {
BIO_puts(STDout, "notBefore=");
ASN1_TIME_print(STDout, X509_get_notBefore(x));
BIO_puts(STDout, "\n");
} else if (enddate == i) {
BIO_puts(STDout, "notAfter=");
ASN1_TIME_print(STDout, X509_get_notAfter(x));
BIO_puts(STDout, "\n");
} else if (fingerprint == i) {
int j;
unsigned int n;
unsigned char md[EVP_MAX_MD_SIZE];
const EVP_MD *fdig = digest;
if (!fdig)
fdig = EVP_sha1();
if (!X509_digest(x, fdig, md, &n)) {
BIO_printf(bio_err, "out of memory\n");
goto end;
}
BIO_printf(STDout, "%s Fingerprint=",
OBJ_nid2sn(EVP_MD_type(fdig)));
for (j = 0; j < (int)n; j++) {
BIO_printf(STDout, "%02X%c", md[j], (j + 1 == (int)n)
? '\n' : ':');
}
}
else if ((sign_flag == i) && (x509req == 0)) {
BIO_printf(bio_err, "Getting Private key\n");
if (Upkey == NULL) {
Upkey = load_key(bio_err,
keyfile, keyformat, 0,
passin, e, "Private key");
if (Upkey == NULL)
goto end;
}
assert(need_rand);
if (!sign(x, Upkey, days, clrext, digest, extconf, extsect))
goto end;
} else if (CA_flag == i) {
BIO_printf(bio_err, "Getting CA Private Key\n");
if (CAkeyfile != NULL) {
CApkey = load_key(bio_err,
CAkeyfile, CAkeyformat,
0, passin, e, "CA Private Key");
if (CApkey == NULL)
goto end;
}
assert(need_rand);
if (!x509_certify(ctx, CAfile, digest, x, xca,
CApkey, sigopts,
CAserial, CA_createserial, days, clrext,
extconf, extsect, sno))
goto end;
} else if (x509req == i) {
EVP_PKEY *pk;
BIO_printf(bio_err, "Getting request Private Key\n");
if (keyfile == NULL) {
BIO_printf(bio_err, "no request key file specified\n");
goto end;
} else {
pk = load_key(bio_err,
keyfile, keyformat, 0,
passin, e, "request key");
if (pk == NULL)
goto end;
}
BIO_printf(bio_err, "Generating certificate request\n");
rq = X509_to_X509_REQ(x, pk, digest);
EVP_PKEY_free(pk);
if (rq == NULL) {
ERR_print_errors(bio_err);
goto end;
}
if (!noout) {
X509_REQ_print(out, rq);
PEM_write_bio_X509_REQ(out, rq);
}
noout = 1;
} else if (ocspid == i) {
X509_ocspid_print(out, x);
}
}
}
if (checkend) {
time_t tcheck = time(NULL) + checkoffset;
if (X509_cmp_time(X509_get_notAfter(x), &tcheck) < 0) {
BIO_printf(out, "Certificate will expire\n");
ret = 1;
} else {
BIO_printf(out, "Certificate will not expire\n");
ret = 0;
}
goto end;
}
print_cert_checks(STDout, x, checkhost, checkemail, checkip);
if (noout) {
ret = 0;
goto end;
}
if (badsig)
x->signature->data[x->signature->length - 1] ^= 0x1;
if (outformat == FORMAT_ASN1)
i = i2d_X509_bio(out, x);
else if (outformat == FORMAT_PEM) {
if (trustout)
i = PEM_write_bio_X509_AUX(out, x);
else
i = PEM_write_bio_X509(out, x);
} else if (outformat == FORMAT_NETSCAPE) {
NETSCAPE_X509 nx;
ASN1_OCTET_STRING hdr;
hdr.data = (unsigned char *)NETSCAPE_CERT_HDR;
hdr.length = strlen(NETSCAPE_CERT_HDR);
nx.header = &hdr;
nx.cert = x;
i = ASN1_item_i2d_bio(ASN1_ITEM_rptr(NETSCAPE_X509), out, &nx);
} else {
BIO_printf(bio_err, "bad output format specified for outfile\n");
goto end;
}
if (!i) {
BIO_printf(bio_err, "unable to write certificate\n");
ERR_print_errors(bio_err);
goto end;
}
ret = 0;
end:
if (need_rand)
app_RAND_write_file(NULL, bio_err);
OBJ_cleanup();
NCONF_free(extconf);
BIO_free_all(out);
BIO_free_all(STDout);
X509_STORE_free(ctx);
X509_REQ_free(req);
X509_free(x);
X509_free(xca);
EVP_PKEY_free(Upkey);
EVP_PKEY_free(CApkey);
EVP_PKEY_free(fkey);
if (sigopts)
sk_OPENSSL_STRING_free(sigopts);
X509_REQ_free(rq);
ASN1_INTEGER_free(sno);
sk_ASN1_OBJECT_pop_free(trust, ASN1_OBJECT_free);
sk_ASN1_OBJECT_pop_free(reject, ASN1_OBJECT_free);
if (passin)
OPENSSL_free(passin);
apps_shutdown();
OPENSSL_EXIT(ret);
}
static ASN1_INTEGER *x509_load_serial(char *CAfile, char *serialfile,
int create)
{
char *buf = NULL, *p;
ASN1_INTEGER *bs = NULL;
BIGNUM *serial = NULL;
size_t len;
len = ((serialfile == NULL)
? (strlen(CAfile) + strlen(POSTFIX) + 1)
: (strlen(serialfile))) + 1;
buf = OPENSSL_malloc(len);
if (buf == NULL) {
BIO_printf(bio_err, "out of mem\n");
goto end;
}
if (serialfile == NULL) {
BUF_strlcpy(buf, CAfile, len);
for (p = buf; *p; p++)
if (*p == '.') {
*p = '\0';
break;
}
BUF_strlcat(buf, POSTFIX, len);
} else
BUF_strlcpy(buf, serialfile, len);
serial = load_serial(buf, create, NULL);
if (serial == NULL)
goto end;
if (!BN_add_word(serial, 1)) {
BIO_printf(bio_err, "add_word failure\n");
goto end;
}
if (!save_serial(buf, NULL, serial, &bs))
goto end;
end:
if (buf)
OPENSSL_free(buf);
BN_free(serial);
return bs;
}
static int MS_CALLBACK callb(int ok, X509_STORE_CTX *ctx)
{
int err;
X509 *err_cert;
err = X509_STORE_CTX_get_error(ctx);
if (err == X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT)
return 1;
if (ok) {
BIO_printf(bio_err,
"error with certificate to be certified - should be self signed\n");
return 0;
} else {
err_cert = X509_STORE_CTX_get_current_cert(ctx);
print_name(bio_err, NULL, X509_get_subject_name(err_cert), 0);
BIO_printf(bio_err,
"error with certificate - error %d at depth %d\n%s\n", err,
X509_STORE_CTX_get_error_depth(ctx),
X509_verify_cert_error_string(err));
return 1;
}
}
static int sign(X509 *x, EVP_PKEY *pkey, int days, int clrext,
const EVP_MD *digest, CONF *conf, char *section)
{
EVP_PKEY *pktmp;
pktmp = X509_get_pubkey(x);
EVP_PKEY_copy_parameters(pktmp, pkey);
EVP_PKEY_save_parameters(pktmp, 1);
EVP_PKEY_free(pktmp);
if (!X509_set_issuer_name(x, X509_get_subject_name(x)))
goto err;
if (X509_gmtime_adj(X509_get_notBefore(x), 0) == NULL)
goto err;
if (X509_gmtime_adj(X509_get_notAfter(x), (long)60 * 60 * 24 * days) ==
NULL)
goto err;
if (!X509_set_pubkey(x, pkey))
goto err;
if (clrext) {
while (X509_get_ext_count(x) > 0)
X509_delete_ext(x, 0);
}
if (conf) {
X509V3_CTX ctx;
#ifdef OPENSSL_SSL_DEBUG_BROKEN_PROTOCOL
X509_set_version(x, force_version);
#else
X509_set_version(x, 2);
#endif
X509V3_set_ctx(&ctx, x, x, NULL, NULL, 0);
X509V3_set_nconf(&ctx, conf);
if (!X509V3_EXT_add_nconf(conf, &ctx, section, x))
goto err;
}
if (!X509_sign(x, pkey, digest))
goto err;
return 1;
err:
ERR_print_errors(bio_err);
return 0;
}
static int purpose_print(BIO *bio, X509 *cert, X509_PURPOSE *pt)
{
int id, i, idret;
char *pname;
id = X509_PURPOSE_get_id(pt);
pname = X509_PURPOSE_get0_name(pt);
for (i = 0; i < 2; i++) {
idret = X509_check_purpose(cert, id, i);
BIO_printf(bio, "%s%s : ", pname, i ? " CA" : "");
if (idret == 1)
BIO_printf(bio, "Yes\n");
else if (idret == 0)
BIO_printf(bio, "No\n");
else
BIO_printf(bio, "Yes (WARNING code=%d)\n", idret);
}
return 1;
}
