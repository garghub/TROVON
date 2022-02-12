int ca_main(int argc, char **argv)
{
CONF *conf = NULL;
ENGINE *e = NULL;
BIGNUM *crlnumber = NULL, *serial = NULL;
EVP_PKEY *pkey = NULL;
BIO *in = NULL, *out = NULL, *Sout = NULL;
ASN1_INTEGER *tmpser;
ASN1_TIME *tmptm;
CA_DB *db = NULL;
DB_ATTR db_attr;
STACK_OF(CONF_VALUE) *attribs = NULL;
STACK_OF(OPENSSL_STRING) *sigopts = NULL;
STACK_OF(X509) *cert_sk = NULL;
X509_CRL *crl = NULL;
const EVP_MD *dgst = NULL;
char *configfile = default_config_file, *section = NULL;
char *md = NULL, *policy = NULL, *keyfile = NULL;
char *certfile = NULL, *crl_ext = NULL, *crlnumberfile = NULL, *key = NULL;
const char *infile = NULL, *spkac_file = NULL, *ss_cert_file = NULL;
const char *extensions = NULL, *extfile = NULL, *passinarg = NULL;
char *outdir = NULL, *outfile = NULL, *rev_arg = NULL, *ser_status = NULL;
const char *serialfile = NULL, *subj = NULL;
char *prog, *startdate = NULL, *enddate = NULL;
char *dbfile = NULL, *f, *randfile = NULL;
char buf[3][BSIZE];
char *const *pp;
const char *p;
int create_ser = 0, free_key = 0, total = 0, total_done = 0;
int batch = 0, default_op = 1, doupdatedb = 0, ext_copy = EXT_COPY_NONE;
int keyformat = FORMAT_PEM, multirdn = 0, notext = 0, output_der = 0;
int ret = 1, email_dn = 1, req = 0, verbose = 0, gencrl = 0, dorevoke = 0;
int i, j, rev_type = REV_NONE, selfsign = 0;
long crldays = 0, crlhours = 0, crlsec = 0, days = 0;
unsigned long chtype = MBSTRING_ASC, nameopt = 0, certopt = 0;
X509 *x509 = NULL, *x509p = NULL, *x = NULL;
X509_REVOKED *r = NULL;
OPTION_CHOICE o;
prog = opt_init(argc, argv, ca_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(ca_options);
ret = 0;
goto end;
case OPT_IN:
req = 1;
infile = opt_arg();
break;
case OPT_OUT:
outfile = opt_arg();
break;
case OPT_VERBOSE:
verbose = 1;
break;
case OPT_CONFIG:
configfile = opt_arg();
break;
case OPT_NAME:
section = opt_arg();
break;
case OPT_SUBJ:
subj = opt_arg();
break;
case OPT_UTF8:
chtype = MBSTRING_UTF8;
break;
case OPT_CREATE_SERIAL:
create_ser = 1;
break;
case OPT_MULTIVALUE_RDN:
multirdn = 1;
break;
case OPT_STARTDATE:
startdate = opt_arg();
break;
case OPT_ENDDATE:
enddate = opt_arg();
break;
case OPT_DAYS:
days = atoi(opt_arg());
break;
case OPT_MD:
md = opt_arg();
break;
case OPT_POLICY:
policy = opt_arg();
break;
case OPT_KEYFILE:
keyfile = opt_arg();
break;
case OPT_KEYFORM:
if (!opt_format(opt_arg(), OPT_FMT_ANY, &keyformat))
goto opthelp;
break;
case OPT_PASSIN:
passinarg = opt_arg();
break;
case OPT_KEY:
key = opt_arg();
break;
case OPT_CERT:
certfile = opt_arg();
break;
case OPT_SELFSIGN:
selfsign = 1;
break;
case OPT_OUTDIR:
outdir = opt_arg();
break;
case OPT_SIGOPT:
if (sigopts == NULL)
sigopts = sk_OPENSSL_STRING_new_null();
if (sigopts == NULL
|| !sk_OPENSSL_STRING_push(sigopts, opt_arg()))
goto end;
break;
case OPT_NOTEXT:
notext = 1;
break;
case OPT_BATCH:
batch = 1;
break;
case OPT_PRESERVEDN:
preserve = 1;
break;
case OPT_NOEMAILDN:
email_dn = 0;
break;
case OPT_GENCRL:
gencrl = 1;
break;
case OPT_MSIE_HACK:
msie_hack = 1;
break;
case OPT_CRLDAYS:
crldays = atol(opt_arg());
break;
case OPT_CRLHOURS:
crlhours = atol(opt_arg());
break;
case OPT_CRLSEC:
crlsec = atol(opt_arg());
break;
case OPT_INFILES:
req = 1;
goto end_of_options;
case OPT_SS_CERT:
ss_cert_file = opt_arg();
req = 1;
break;
case OPT_SPKAC:
spkac_file = opt_arg();
req = 1;
break;
case OPT_REVOKE:
infile = opt_arg();
dorevoke = 1;
break;
case OPT_VALID:
infile = opt_arg();
dorevoke = 2;
break;
case OPT_EXTENSIONS:
extensions = opt_arg();
break;
case OPT_EXTFILE:
extfile = opt_arg();
break;
case OPT_STATUS:
ser_status = opt_arg();
break;
case OPT_UPDATEDB:
doupdatedb = 1;
break;
case OPT_CRLEXTS:
crl_ext = opt_arg();
break;
case OPT_CRL_REASON:
rev_arg = opt_arg();
rev_type = REV_CRL_REASON;
break;
case OPT_CRL_HOLD:
rev_arg = opt_arg();
rev_type = REV_HOLD;
break;
case OPT_CRL_COMPROMISE:
rev_arg = opt_arg();
rev_type = REV_KEY_COMPROMISE;
break;
case OPT_CRL_CA_COMPROMISE:
rev_arg = opt_arg();
rev_type = REV_CA_COMPROMISE;
break;
case OPT_ENGINE:
e = setup_engine(opt_arg(), 0);
break;
}
}
end_of_options:
argc = opt_num_rest();
argv = opt_rest();
BIO_printf(bio_err, "Using configuration from %s\n", configfile);
if ((conf = app_load_config(configfile)) == NULL)
goto end;
if (configfile != default_config_file && !app_load_modules(conf))
goto end;
if (section == NULL
&& (section = lookup_conf(conf, BASE_SECTION, ENV_DEFAULT_CA)) == NULL)
goto end;
if (conf != NULL) {
p = NCONF_get_string(conf, NULL, "oid_file");
if (p == NULL)
ERR_clear_error();
if (p != NULL) {
BIO *oid_bio;
oid_bio = BIO_new_file(p, "r");
if (oid_bio == NULL) {
ERR_clear_error();
} else {
OBJ_create_objects(oid_bio);
BIO_free(oid_bio);
}
}
if (!add_oid_section(conf)) {
ERR_print_errors(bio_err);
goto end;
}
}
randfile = NCONF_get_string(conf, BASE_SECTION, "RANDFILE");
if (randfile == NULL)
ERR_clear_error();
app_RAND_load_file(randfile, 0);
f = NCONF_get_string(conf, section, STRING_MASK);
if (!f)
ERR_clear_error();
if (f && !ASN1_STRING_set_default_mask_asc(f)) {
BIO_printf(bio_err, "Invalid global string mask setting %s\n", f);
goto end;
}
if (chtype != MBSTRING_UTF8) {
f = NCONF_get_string(conf, section, UTF8_IN);
if (!f)
ERR_clear_error();
else if (strcmp(f, "yes") == 0)
chtype = MBSTRING_UTF8;
}
db_attr.unique_subject = 1;
p = NCONF_get_string(conf, section, ENV_UNIQUE_SUBJECT);
if (p) {
db_attr.unique_subject = parse_yesno(p, 1);
} else
ERR_clear_error();
if (ser_status) {
dbfile = lookup_conf(conf, section, ENV_DATABASE);
if (dbfile == NULL)
goto end;
db = load_index(dbfile, &db_attr);
if (db == NULL)
goto end;
if (!index_index(db))
goto end;
if (get_certificate_status(ser_status, db) != 1)
BIO_printf(bio_err, "Error verifying serial %s!\n", ser_status);
goto end;
}
if (keyfile == NULL
&& (keyfile = lookup_conf(conf, section, ENV_PRIVATE_KEY)) == NULL)
goto end;
if (!key) {
free_key = 1;
if (!app_passwd(passinarg, NULL, &key, NULL)) {
BIO_printf(bio_err, "Error getting password\n");
goto end;
}
}
pkey = load_key(keyfile, keyformat, 0, key, e, "CA private key");
if (key)
OPENSSL_cleanse(key, strlen(key));
if (pkey == NULL) {
goto end;
}
if (!selfsign || spkac_file || ss_cert_file || gencrl) {
if (certfile == NULL
&& (certfile = lookup_conf(conf, section, ENV_CERTIFICATE)) == NULL)
goto end;
x509 = load_cert(certfile, FORMAT_PEM, "CA certificate");
if (x509 == NULL)
goto end;
if (!X509_check_private_key(x509, pkey)) {
BIO_printf(bio_err,
"CA certificate and CA private key do not match\n");
goto end;
}
}
if (!selfsign)
x509p = x509;
f = NCONF_get_string(conf, BASE_SECTION, ENV_PRESERVE);
if (f == NULL)
ERR_clear_error();
if ((f != NULL) && ((*f == 'y') || (*f == 'Y')))
preserve = 1;
f = NCONF_get_string(conf, BASE_SECTION, ENV_MSIE_HACK);
if (f == NULL)
ERR_clear_error();
if ((f != NULL) && ((*f == 'y') || (*f == 'Y')))
msie_hack = 1;
f = NCONF_get_string(conf, section, ENV_NAMEOPT);
if (f) {
if (!set_name_ex(&nameopt, f)) {
BIO_printf(bio_err, "Invalid name options: \"%s\"\n", f);
goto end;
}
default_op = 0;
} else {
nameopt = XN_FLAG_ONELINE;
ERR_clear_error();
}
f = NCONF_get_string(conf, section, ENV_CERTOPT);
if (f) {
if (!set_cert_ex(&certopt, f)) {
BIO_printf(bio_err, "Invalid certificate options: \"%s\"\n", f);
goto end;
}
default_op = 0;
} else
ERR_clear_error();
f = NCONF_get_string(conf, section, ENV_EXTCOPY);
if (f) {
if (!set_ext_copy(&ext_copy, f)) {
BIO_printf(bio_err, "Invalid extension copy option: \"%s\"\n", f);
goto end;
}
} else
ERR_clear_error();
if ((outdir == NULL) && (req)) {
outdir = NCONF_get_string(conf, section, ENV_NEW_CERTS_DIR);
if (outdir == NULL) {
BIO_printf(bio_err,
"there needs to be defined a directory for new certificate to be placed in\n");
goto end;
}
#ifndef OPENSSL_SYS_VMS
if (app_isdir(outdir) <= 0) {
BIO_printf(bio_err, "%s: %s is not a directory\n", prog, outdir);
perror(outdir);
goto end;
}
#endif
}
dbfile = lookup_conf(conf, section, ENV_DATABASE);
if (dbfile == NULL)
goto end;
db = load_index(dbfile, &db_attr);
if (db == NULL)
goto end;
for (i = 0; i < sk_OPENSSL_PSTRING_num(db->db->data); i++) {
pp = sk_OPENSSL_PSTRING_value(db->db->data, i);
if ((pp[DB_type][0] != DB_TYPE_REV) && (pp[DB_rev_date][0] != '\0')) {
BIO_printf(bio_err,
"entry %d: not revoked yet, but has a revocation date\n",
i + 1);
goto end;
}
if ((pp[DB_type][0] == DB_TYPE_REV) &&
!make_revoked(NULL, pp[DB_rev_date])) {
BIO_printf(bio_err, " in entry %d\n", i + 1);
goto end;
}
if (!check_time_format((char *)pp[DB_exp_date])) {
BIO_printf(bio_err, "entry %d: invalid expiry date\n", i + 1);
goto end;
}
p = pp[DB_serial];
j = strlen(p);
if (*p == '-') {
p++;
j--;
}
if ((j & 1) || (j < 2)) {
BIO_printf(bio_err, "entry %d: bad serial number length (%d)\n",
i + 1, j);
goto end;
}
for ( ; *p; p++) {
if (!isxdigit(_UC(*p))) {
BIO_printf(bio_err,
"entry %d: bad char 0%o '%c' in serial number\n",
i + 1, *p, *p);
goto end;
}
}
}
if (verbose) {
TXT_DB_write(bio_out, db->db);
BIO_printf(bio_err, "%d entries loaded from the database\n",
sk_OPENSSL_PSTRING_num(db->db->data));
BIO_printf(bio_err, "generating index\n");
}
if (!index_index(db))
goto end;
if (doupdatedb) {
if (verbose)
BIO_printf(bio_err, "Updating %s ...\n", dbfile);
i = do_updatedb(db);
if (i == -1) {
BIO_printf(bio_err, "Malloc failure\n");
goto end;
} else if (i == 0) {
if (verbose)
BIO_printf(bio_err, "No entries found to mark expired\n");
} else {
if (!save_index(dbfile, "new", db))
goto end;
if (!rotate_index(dbfile, "new", "old"))
goto end;
if (verbose)
BIO_printf(bio_err,
"Done. %d entries marked as expired\n", i);
}
}
if (extfile) {
if ((extconf = app_load_config(extfile)) == NULL) {
ret = 1;
goto end;
}
if (verbose)
BIO_printf(bio_err, "Successfully loaded extensions file %s\n",
extfile);
if (extensions == NULL) {
extensions = NCONF_get_string(extconf, "default", "extensions");
if (extensions == NULL)
extensions = "default";
}
}
if (req || gencrl) {
Sout = bio_open_default(outfile, 'w', FORMAT_TEXT);
if (Sout == NULL)
goto end;
}
if (md == NULL
&& (md = lookup_conf(conf, section, ENV_DEFAULT_MD)) == NULL)
goto end;
if (strcmp(md, "default") == 0) {
int def_nid;
if (EVP_PKEY_get_default_digest_nid(pkey, &def_nid) <= 0) {
BIO_puts(bio_err, "no default digest\n");
goto end;
}
md = (char *)OBJ_nid2sn(def_nid);
}
if (!opt_md(md, &dgst)) {
goto end;
}
if (req) {
if (email_dn == 1) {
char *tmp_email_dn = NULL;
tmp_email_dn = NCONF_get_string(conf, section, ENV_DEFAULT_EMAIL_DN);
if (tmp_email_dn != NULL && strcmp(tmp_email_dn, "no") == 0)
email_dn = 0;
}
if (verbose)
BIO_printf(bio_err, "message digest is %s\n",
OBJ_nid2ln(EVP_MD_type(dgst)));
if (policy == NULL
&& (policy = lookup_conf(conf, section, ENV_POLICY)) == NULL)
goto end;
if (verbose)
BIO_printf(bio_err, "policy is %s\n", policy);
serialfile = lookup_conf(conf, section, ENV_SERIAL);
if (serialfile == NULL)
goto end;
if (!extconf) {
if (!extensions) {
extensions = NCONF_get_string(conf, section, ENV_EXTENSIONS);
if (!extensions)
ERR_clear_error();
}
if (extensions) {
X509V3_CTX ctx;
X509V3_set_ctx_test(&ctx);
X509V3_set_nconf(&ctx, conf);
if (!X509V3_EXT_add_nconf(conf, &ctx, extensions, NULL)) {
BIO_printf(bio_err,
"Error Loading extension section %s\n",
extensions);
ret = 1;
goto end;
}
}
}
if (startdate == NULL) {
startdate = NCONF_get_string(conf, section,
ENV_DEFAULT_STARTDATE);
if (startdate == NULL)
ERR_clear_error();
}
if (startdate && !ASN1_TIME_set_string(NULL, startdate)) {
BIO_printf(bio_err,
"start date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n");
goto end;
}
if (startdate == NULL)
startdate = "today";
if (enddate == NULL) {
enddate = NCONF_get_string(conf, section, ENV_DEFAULT_ENDDATE);
if (enddate == NULL)
ERR_clear_error();
}
if (enddate && !ASN1_TIME_set_string(NULL, enddate)) {
BIO_printf(bio_err,
"end date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n");
goto end;
}
if (days == 0) {
if (!NCONF_get_number(conf, section, ENV_DEFAULT_DAYS, &days))
days = 0;
}
if (!enddate && (days == 0)) {
BIO_printf(bio_err,
"cannot lookup how many days to certify for\n");
goto end;
}
if ((serial = load_serial(serialfile, create_ser, NULL)) == NULL) {
BIO_printf(bio_err, "error while loading serial number\n");
goto end;
}
if (verbose) {
if (BN_is_zero(serial))
BIO_printf(bio_err, "next serial number is 00\n");
else {
if ((f = BN_bn2hex(serial)) == NULL)
goto end;
BIO_printf(bio_err, "next serial number is %s\n", f);
OPENSSL_free(f);
}
}
if ((attribs = NCONF_get_section(conf, policy)) == NULL) {
BIO_printf(bio_err, "unable to find 'section' for %s\n", policy);
goto end;
}
if ((cert_sk = sk_X509_new_null()) == NULL) {
BIO_printf(bio_err, "Memory allocation failure\n");
goto end;
}
if (spkac_file != NULL) {
total++;
j = certify_spkac(&x, spkac_file, pkey, x509, dgst, sigopts,
attribs, db, serial, subj, chtype, multirdn,
email_dn, startdate, enddate, days, extensions,
conf, verbose, certopt, nameopt, default_op,
ext_copy);
if (j < 0)
goto end;
if (j > 0) {
total_done++;
BIO_printf(bio_err, "\n");
if (!BN_add_word(serial, 1))
goto end;
if (!sk_X509_push(cert_sk, x)) {
BIO_printf(bio_err, "Memory allocation failure\n");
goto end;
}
if (outfile) {
output_der = 1;
batch = 1;
}
}
}
if (ss_cert_file != NULL) {
total++;
j = certify_cert(&x, ss_cert_file, pkey, x509, dgst, sigopts,
attribs,
db, serial, subj, chtype, multirdn, email_dn,
startdate, enddate, days, batch, extensions,
conf, verbose, certopt, nameopt, default_op,
ext_copy);
if (j < 0)
goto end;
if (j > 0) {
total_done++;
BIO_printf(bio_err, "\n");
if (!BN_add_word(serial, 1))
goto end;
if (!sk_X509_push(cert_sk, x)) {
BIO_printf(bio_err, "Memory allocation failure\n");
goto end;
}
}
}
if (infile != NULL) {
total++;
j = certify(&x, infile, pkey, x509p, dgst, sigopts, attribs, db,
serial, subj, chtype, multirdn, email_dn, startdate,
enddate, days, batch, extensions, conf, verbose,
certopt, nameopt, default_op, ext_copy, selfsign);
if (j < 0)
goto end;
if (j > 0) {
total_done++;
BIO_printf(bio_err, "\n");
if (!BN_add_word(serial, 1))
goto end;
if (!sk_X509_push(cert_sk, x)) {
BIO_printf(bio_err, "Memory allocation failure\n");
goto end;
}
}
}
for (i = 0; i < argc; i++) {
total++;
j = certify(&x, argv[i], pkey, x509p, dgst, sigopts, attribs, db,
serial, subj, chtype, multirdn, email_dn, startdate,
enddate, days, batch, extensions, conf, verbose,
certopt, nameopt, default_op, ext_copy, selfsign);
if (j < 0)
goto end;
if (j > 0) {
total_done++;
BIO_printf(bio_err, "\n");
if (!BN_add_word(serial, 1))
goto end;
if (!sk_X509_push(cert_sk, x)) {
BIO_printf(bio_err, "Memory allocation failure\n");
goto end;
}
}
}
if (sk_X509_num(cert_sk) > 0) {
if (!batch) {
BIO_printf(bio_err,
"\n%d out of %d certificate requests certified, commit? [y/n]",
total_done, total);
(void)BIO_flush(bio_err);
buf[0][0] = '\0';
if (!fgets(buf[0], 10, stdin)) {
BIO_printf(bio_err,
"CERTIFICATION CANCELED: I/O error\n");
ret = 0;
goto end;
}
if ((buf[0][0] != 'y') && (buf[0][0] != 'Y')) {
BIO_printf(bio_err, "CERTIFICATION CANCELED\n");
ret = 0;
goto end;
}
}
BIO_printf(bio_err, "Write out database with %d new entries\n",
sk_X509_num(cert_sk));
if (!save_serial(serialfile, "new", serial, NULL))
goto end;
if (!save_index(dbfile, "new", db))
goto end;
}
if (verbose)
BIO_printf(bio_err, "writing new certificates\n");
for (i = 0; i < sk_X509_num(cert_sk); i++) {
BIO *Cout = NULL;
ASN1_INTEGER *serialNumber = X509_get_serialNumber(x);
int k;
char *n;
x = sk_X509_value(cert_sk, i);
j = ASN1_STRING_length(serialNumber);
p = (const char *)ASN1_STRING_get0_data(serialNumber);
if (strlen(outdir) >= (size_t)(j ? BSIZE - j * 2 - 6 : BSIZE - 8)) {
BIO_printf(bio_err, "certificate file name too long\n");
goto end;
}
strcpy(buf[2], outdir);
#ifndef OPENSSL_SYS_VMS
OPENSSL_strlcat(buf[2], "/", sizeof(buf[2]));
#endif
n = (char *)&(buf[2][strlen(buf[2])]);
if (j > 0) {
for (k = 0; k < j; k++) {
if (n >= &(buf[2][sizeof(buf[2])]))
break;
BIO_snprintf(n,
&buf[2][0] + sizeof(buf[2]) - n,
"%02X", (unsigned char)*(p++));
n += 2;
}
} else {
*(n++) = '0';
*(n++) = '0';
}
*(n++) = '.';
*(n++) = 'p';
*(n++) = 'e';
*(n++) = 'm';
*n = '\0';
if (verbose)
BIO_printf(bio_err, "writing %s\n", buf[2]);
Cout = BIO_new_file(buf[2], "w");
if (Cout == NULL) {
perror(buf[2]);
goto end;
}
write_new_certificate(Cout, x, 0, notext);
write_new_certificate(Sout, x, output_der, notext);
BIO_free_all(Cout);
}
if (sk_X509_num(cert_sk)) {
if (!rotate_serial(serialfile, "new", "old"))
goto end;
if (!rotate_index(dbfile, "new", "old"))
goto end;
BIO_printf(bio_err, "Data Base Updated\n");
}
}
if (gencrl) {
int crl_v2 = 0;
if (!crl_ext) {
crl_ext = NCONF_get_string(conf, section, ENV_CRLEXT);
if (!crl_ext)
ERR_clear_error();
}
if (crl_ext) {
X509V3_CTX ctx;
X509V3_set_ctx_test(&ctx);
X509V3_set_nconf(&ctx, conf);
if (!X509V3_EXT_add_nconf(conf, &ctx, crl_ext, NULL)) {
BIO_printf(bio_err,
"Error Loading CRL extension section %s\n",
crl_ext);
ret = 1;
goto end;
}
}
if ((crlnumberfile = NCONF_get_string(conf, section, ENV_CRLNUMBER))
!= NULL)
if ((crlnumber = load_serial(crlnumberfile, 0, NULL)) == NULL) {
BIO_printf(bio_err, "error while loading CRL number\n");
goto end;
}
if (!crldays && !crlhours && !crlsec) {
if (!NCONF_get_number(conf, section,
ENV_DEFAULT_CRL_DAYS, &crldays))
crldays = 0;
if (!NCONF_get_number(conf, section,
ENV_DEFAULT_CRL_HOURS, &crlhours))
crlhours = 0;
ERR_clear_error();
}
if ((crldays == 0) && (crlhours == 0) && (crlsec == 0)) {
BIO_printf(bio_err,
"cannot lookup how long until the next CRL is issued\n");
goto end;
}
if (verbose)
BIO_printf(bio_err, "making CRL\n");
if ((crl = X509_CRL_new()) == NULL)
goto end;
if (!X509_CRL_set_issuer_name(crl, X509_get_subject_name(x509)))
goto end;
tmptm = ASN1_TIME_new();
if (tmptm == NULL)
goto end;
X509_gmtime_adj(tmptm, 0);
X509_CRL_set1_lastUpdate(crl, tmptm);
if (!X509_time_adj_ex(tmptm, crldays, crlhours * 60 * 60 + crlsec,
NULL)) {
BIO_puts(bio_err, "error setting CRL nextUpdate\n");
goto end;
}
X509_CRL_set1_nextUpdate(crl, tmptm);
ASN1_TIME_free(tmptm);
for (i = 0; i < sk_OPENSSL_PSTRING_num(db->db->data); i++) {
pp = sk_OPENSSL_PSTRING_value(db->db->data, i);
if (pp[DB_type][0] == DB_TYPE_REV) {
if ((r = X509_REVOKED_new()) == NULL)
goto end;
j = make_revoked(r, pp[DB_rev_date]);
if (!j)
goto end;
if (j == 2)
crl_v2 = 1;
if (!BN_hex2bn(&serial, pp[DB_serial]))
goto end;
tmpser = BN_to_ASN1_INTEGER(serial, NULL);
BN_free(serial);
serial = NULL;
if (!tmpser)
goto end;
X509_REVOKED_set_serialNumber(r, tmpser);
ASN1_INTEGER_free(tmpser);
X509_CRL_add0_revoked(crl, r);
}
}
X509_CRL_sort(crl);
if (verbose)
BIO_printf(bio_err, "signing CRL\n");
if (crl_ext || crlnumberfile != NULL) {
X509V3_CTX crlctx;
X509V3_set_ctx(&crlctx, x509, NULL, NULL, crl, 0);
X509V3_set_nconf(&crlctx, conf);
if (crl_ext)
if (!X509V3_EXT_CRL_add_nconf(conf, &crlctx, crl_ext, crl))
goto end;
if (crlnumberfile != NULL) {
tmpser = BN_to_ASN1_INTEGER(crlnumber, NULL);
if (!tmpser)
goto end;
X509_CRL_add1_ext_i2d(crl, NID_crl_number, tmpser, 0, 0);
ASN1_INTEGER_free(tmpser);
crl_v2 = 1;
if (!BN_add_word(crlnumber, 1))
goto end;
}
}
if (crl_ext || crl_v2) {
if (!X509_CRL_set_version(crl, 1))
goto end;
}
if (crlnumberfile != NULL)
if (!save_serial(crlnumberfile, "new", crlnumber, NULL))
goto end;
BN_free(crlnumber);
crlnumber = NULL;
if (!do_X509_CRL_sign(crl, pkey, dgst, sigopts))
goto end;
PEM_write_bio_X509_CRL(Sout, crl);
if (crlnumberfile != NULL)
if (!rotate_serial(crlnumberfile, "new", "old"))
goto end;
}
if (dorevoke) {
if (infile == NULL) {
BIO_printf(bio_err, "no input files\n");
goto end;
} else {
X509 *revcert;
revcert = load_cert(infile, FORMAT_PEM, infile);
if (revcert == NULL)
goto end;
if (dorevoke == 2)
rev_type = -1;
j = do_revoke(revcert, db, rev_type, rev_arg);
if (j <= 0)
goto end;
X509_free(revcert);
if (!save_index(dbfile, "new", db))
goto end;
if (!rotate_index(dbfile, "new", "old"))
goto end;
BIO_printf(bio_err, "Data Base Updated\n");
}
}
ret = 0;
end:
BIO_free_all(Sout);
BIO_free_all(out);
BIO_free_all(in);
sk_X509_pop_free(cert_sk, X509_free);
if (ret)
ERR_print_errors(bio_err);
app_RAND_write_file(randfile);
if (free_key)
OPENSSL_free(key);
BN_free(serial);
BN_free(crlnumber);
free_index(db);
sk_OPENSSL_STRING_free(sigopts);
EVP_PKEY_free(pkey);
X509_free(x509);
X509_CRL_free(crl);
NCONF_free(conf);
NCONF_free(extconf);
return (ret);
}
static char *lookup_conf(const CONF *conf, const char *section, const char *tag)
{
char *entry = NCONF_get_string(conf, section, tag);
if (entry == NULL)
BIO_printf(bio_err, "variable lookup failed for %s::%s\n", section, tag);
return entry;
}
static void write_new_certificate(BIO *bp, X509 *x, int output_der,
int notext)
{
if (output_der) {
(void)i2d_X509_bio(bp, x);
return;
}
if (!notext)
X509_print(bp, x);
PEM_write_bio_X509(bp, x);
}
static int check_time_format(const char *str)
{
return ASN1_TIME_set_string(NULL, str);
}
static int do_revoke(X509 *x509, CA_DB *db, int type, char *value)
{
const ASN1_TIME *tm = NULL;
char *row[DB_NUMBER], **rrow, **irow;
char *rev_str = NULL;
BIGNUM *bn = NULL;
int ok = -1, i;
for (i = 0; i < DB_NUMBER; i++)
row[i] = NULL;
row[DB_name] = X509_NAME_oneline(X509_get_subject_name(x509), NULL, 0);
bn = ASN1_INTEGER_to_BN(X509_get_serialNumber(x509), NULL);
if (!bn)
goto end;
if (BN_is_zero(bn))
row[DB_serial] = OPENSSL_strdup("00");
else
row[DB_serial] = BN_bn2hex(bn);
BN_free(bn);
if ((row[DB_name] == NULL) || (row[DB_serial] == NULL)) {
BIO_printf(bio_err, "Memory allocation failure\n");
goto end;
}
rrow = TXT_DB_get_by_index(db->db, DB_serial, row);
if (rrow == NULL) {
BIO_printf(bio_err,
"Adding Entry with serial number %s to DB for %s\n",
row[DB_serial], row[DB_name]);
row[DB_type] = OPENSSL_strdup("V");
tm = X509_get0_notAfter(x509);
row[DB_exp_date] = app_malloc(tm->length + 1, "row exp_data");
memcpy(row[DB_exp_date], tm->data, tm->length);
row[DB_exp_date][tm->length] = '\0';
row[DB_rev_date] = NULL;
row[DB_file] = OPENSSL_strdup("unknown");
irow = app_malloc(sizeof(*irow) * (DB_NUMBER + 1), "row ptr");
for (i = 0; i < DB_NUMBER; i++) {
irow[i] = row[i];
row[i] = NULL;
}
irow[DB_NUMBER] = NULL;
if (!TXT_DB_insert(db->db, irow)) {
BIO_printf(bio_err, "failed to update database\n");
BIO_printf(bio_err, "TXT_DB error number %ld\n", db->db->error);
goto end;
}
if (type == -1)
ok = 1;
else
ok = do_revoke(x509, db, type, value);
goto end;
} else if (index_name_cmp_noconst(row, rrow)) {
BIO_printf(bio_err, "ERROR:name does not match %s\n", row[DB_name]);
goto end;
} else if (type == -1) {
BIO_printf(bio_err, "ERROR:Already present, serial number %s\n",
row[DB_serial]);
goto end;
} else if (rrow[DB_type][0] == 'R') {
BIO_printf(bio_err, "ERROR:Already revoked, serial number %s\n",
row[DB_serial]);
goto end;
} else {
BIO_printf(bio_err, "Revoking Certificate %s.\n", rrow[DB_serial]);
rev_str = make_revocation_str(type, value);
if (!rev_str) {
BIO_printf(bio_err, "Error in revocation arguments\n");
goto end;
}
rrow[DB_type][0] = 'R';
rrow[DB_type][1] = '\0';
rrow[DB_rev_date] = rev_str;
}
ok = 1;
end:
for (i = 0; i < DB_NUMBER; i++) {
OPENSSL_free(row[i]);
}
return (ok);
}
static int get_certificate_status(const char *serial, CA_DB *db)
{
char *row[DB_NUMBER], **rrow;
int ok = -1, i;
size_t serial_len = strlen(serial);
for (i = 0; i < DB_NUMBER; i++)
row[i] = NULL;
row[DB_serial] = app_malloc(serial_len + 2, "row serial#");
if (serial_len % 2) {
;
row[DB_serial][0] = '0';
memcpy(row[DB_serial] + 1, serial, serial_len);
row[DB_serial][serial_len + 1] = '\0';
} else {
memcpy(row[DB_serial], serial, serial_len);
row[DB_serial][serial_len] = '\0';
}
for (i = 0; row[DB_serial][i] != '\0'; i++)
row[DB_serial][i] = toupper((unsigned char)row[DB_serial][i]);
ok = 1;
rrow = TXT_DB_get_by_index(db->db, DB_serial, row);
if (rrow == NULL) {
BIO_printf(bio_err, "Serial %s not present in db.\n", row[DB_serial]);
ok = -1;
goto end;
} else if (rrow[DB_type][0] == 'V') {
BIO_printf(bio_err, "%s=Valid (%c)\n",
row[DB_serial], rrow[DB_type][0]);
goto end;
} else if (rrow[DB_type][0] == 'R') {
BIO_printf(bio_err, "%s=Revoked (%c)\n",
row[DB_serial], rrow[DB_type][0]);
goto end;
} else if (rrow[DB_type][0] == 'E') {
BIO_printf(bio_err, "%s=Expired (%c)\n",
row[DB_serial], rrow[DB_type][0]);
goto end;
} else if (rrow[DB_type][0] == 'S') {
BIO_printf(bio_err, "%s=Suspended (%c)\n",
row[DB_serial], rrow[DB_type][0]);
goto end;
} else {
BIO_printf(bio_err, "%s=Unknown (%c).\n",
row[DB_serial], rrow[DB_type][0]);
ok = -1;
}
end:
for (i = 0; i < DB_NUMBER; i++) {
OPENSSL_free(row[i]);
}
return (ok);
}
static int do_updatedb(CA_DB *db)
{
ASN1_UTCTIME *a_tm = NULL;
int i, cnt = 0;
int db_y2k, a_y2k;
char **rrow, *a_tm_s;
a_tm = ASN1_UTCTIME_new();
if (a_tm == NULL)
return -1;
a_tm = X509_gmtime_adj(a_tm, 0);
a_tm_s = app_malloc(a_tm->length + 1, "time string");
memcpy(a_tm_s, a_tm->data, a_tm->length);
a_tm_s[a_tm->length] = '\0';
if (strncmp(a_tm_s, "49", 2) <= 0)
a_y2k = 1;
else
a_y2k = 0;
for (i = 0; i < sk_OPENSSL_PSTRING_num(db->db->data); i++) {
rrow = sk_OPENSSL_PSTRING_value(db->db->data, i);
if (rrow[DB_type][0] == 'V') {
if (strncmp(rrow[DB_exp_date], "49", 2) <= 0)
db_y2k = 1;
else
db_y2k = 0;
if (db_y2k == a_y2k) {
if (strcmp(rrow[DB_exp_date], a_tm_s) <= 0) {
rrow[DB_type][0] = 'E';
rrow[DB_type][1] = '\0';
cnt++;
BIO_printf(bio_err, "%s=Expired\n", rrow[DB_serial]);
}
} else if (db_y2k < a_y2k) {
rrow[DB_type][0] = 'E';
rrow[DB_type][1] = '\0';
cnt++;
BIO_printf(bio_err, "%s=Expired\n", rrow[DB_serial]);
}
}
}
ASN1_UTCTIME_free(a_tm);
OPENSSL_free(a_tm_s);
return (cnt);
}
char *make_revocation_str(int rev_type, char *rev_arg)
{
char *str;
const char *other = NULL;
const char *reason = NULL;
ASN1_OBJECT *otmp;
ASN1_UTCTIME *revtm = NULL;
int i;
switch (rev_type) {
case REV_NONE:
break;
case REV_CRL_REASON:
for (i = 0; i < 8; i++) {
if (strcasecmp(rev_arg, crl_reasons[i]) == 0) {
reason = crl_reasons[i];
break;
}
}
if (reason == NULL) {
BIO_printf(bio_err, "Unknown CRL reason %s\n", rev_arg);
return NULL;
}
break;
case REV_HOLD:
otmp = OBJ_txt2obj(rev_arg, 0);
ASN1_OBJECT_free(otmp);
if (otmp == NULL) {
BIO_printf(bio_err, "Invalid object identifier %s\n", rev_arg);
return NULL;
}
reason = "holdInstruction";
other = rev_arg;
break;
case REV_KEY_COMPROMISE:
case REV_CA_COMPROMISE:
if (!ASN1_GENERALIZEDTIME_set_string(NULL, rev_arg)) {
BIO_printf(bio_err,
"Invalid time format %s. Need YYYYMMDDHHMMSSZ\n",
rev_arg);
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
if (!revtm)
return NULL;
i = revtm->length + 1;
if (reason)
i += strlen(reason) + 1;
if (other)
i += strlen(other) + 1;
str = app_malloc(i, "revocation reason");
OPENSSL_strlcpy(str, (char *)revtm->data, i);
if (reason) {
OPENSSL_strlcat(str, ",", i);
OPENSSL_strlcat(str, reason, i);
}
if (other) {
OPENSSL_strlcat(str, ",", i);
OPENSSL_strlcat(str, other, i);
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
goto end;
if (rev && !X509_REVOKED_set_revocationDate(rev, revDate))
goto end;
if (rev && (reason_code != OCSP_REVOKED_STATUS_NOSTATUS)) {
rtmp = ASN1_ENUMERATED_new();
if (rtmp == NULL || !ASN1_ENUMERATED_set(rtmp, reason_code))
goto end;
if (!X509_REVOKED_add1_ext_i2d(rev, NID_crl_reason, rtmp, 0, 0))
goto end;
}
if (rev && comp_time) {
if (!X509_REVOKED_add1_ext_i2d
(rev, NID_invalidity_date, comp_time, 0, 0))
goto end;
}
if (rev && hold) {
if (!X509_REVOKED_add1_ext_i2d
(rev, NID_hold_instruction_code, hold, 0, 0))
goto end;
}
if (reason_code != OCSP_REVOKED_STATUS_NOSTATUS)
ret = 2;
else
ret = 1;
end:
OPENSSL_free(tmp);
ASN1_OBJECT_free(hold);
ASN1_GENERALIZEDTIME_free(comp_time);
ASN1_ENUMERATED_free(rtmp);
ASN1_TIME_free(revDate);
return ret;
}
static int old_entry_print(const ASN1_OBJECT *obj, const ASN1_STRING *str)
{
char buf[25], *pbuf;
const char *p;
int j;
j = i2a_ASN1_OBJECT(bio_err, obj);
pbuf = buf;
for (j = 22 - j; j > 0; j--)
*(pbuf++) = ' ';
*(pbuf++) = ':';
*(pbuf++) = '\0';
BIO_puts(bio_err, buf);
if (str->type == V_ASN1_PRINTABLESTRING)
BIO_printf(bio_err, "PRINTABLE:'");
else if (str->type == V_ASN1_T61STRING)
BIO_printf(bio_err, "T61STRING:'");
else if (str->type == V_ASN1_IA5STRING)
BIO_printf(bio_err, "IA5STRING:'");
else if (str->type == V_ASN1_UNIVERSALSTRING)
BIO_printf(bio_err, "UNIVERSALSTRING:'");
else
BIO_printf(bio_err, "ASN.1 %2d:'", str->type);
p = (const char *)str->data;
for (j = str->length; j > 0; j--) {
if ((*p >= ' ') && (*p <= '~'))
BIO_printf(bio_err, "%c", *p);
else if (*p & 0x80)
BIO_printf(bio_err, "\\0x%02X", *p);
else if ((unsigned char)*p == 0xf7)
BIO_printf(bio_err, "^?");
else
BIO_printf(bio_err, "^%c", *p + '@');
p++;
}
BIO_printf(bio_err, "'\n");
return 1;
}
int unpack_revinfo(ASN1_TIME **prevtm, int *preason, ASN1_OBJECT **phold,
ASN1_GENERALIZEDTIME **pinvtm, const char *str)
{
char *tmp;
char *rtime_str, *reason_str = NULL, *arg_str = NULL, *p;
int reason_code = -1;
int ret = 0;
unsigned int i;
ASN1_OBJECT *hold = NULL;
ASN1_GENERALIZEDTIME *comp_time = NULL;
tmp = OPENSSL_strdup(str);
if (!tmp) {
BIO_printf(bio_err, "memory allocation failure\n");
goto end;
}
p = strchr(tmp, ',');
rtime_str = tmp;
if (p) {
*p = '\0';
p++;
reason_str = p;
p = strchr(p, ',');
if (p) {
*p = '\0';
arg_str = p + 1;
}
}
if (prevtm) {
*prevtm = ASN1_UTCTIME_new();
if (*prevtm == NULL) {
BIO_printf(bio_err, "memory allocation failure\n");
goto end;
}
if (!ASN1_UTCTIME_set_string(*prevtm, rtime_str)) {
BIO_printf(bio_err, "invalid revocation date %s\n", rtime_str);
goto end;
}
}
if (reason_str) {
for (i = 0; i < NUM_REASONS; i++) {
if (strcasecmp(reason_str, crl_reasons[i]) == 0) {
reason_code = i;
break;
}
}
if (reason_code == OCSP_REVOKED_STATUS_NOSTATUS) {
BIO_printf(bio_err, "invalid reason code %s\n", reason_str);
goto end;
}
if (reason_code == 7)
reason_code = OCSP_REVOKED_STATUS_REMOVEFROMCRL;
else if (reason_code == 8) {
if (!arg_str) {
BIO_printf(bio_err, "missing hold instruction\n");
goto end;
}
reason_code = OCSP_REVOKED_STATUS_CERTIFICATEHOLD;
hold = OBJ_txt2obj(arg_str, 0);
if (!hold) {
BIO_printf(bio_err, "invalid object identifier %s\n",
arg_str);
goto end;
}
if (phold)
*phold = hold;
else
ASN1_OBJECT_free(hold);
} else if ((reason_code == 9) || (reason_code == 10)) {
if (!arg_str) {
BIO_printf(bio_err, "missing compromised time\n");
goto end;
}
comp_time = ASN1_GENERALIZEDTIME_new();
if (comp_time == NULL) {
BIO_printf(bio_err, "memory allocation failure\n");
goto end;
}
if (!ASN1_GENERALIZEDTIME_set_string(comp_time, arg_str)) {
BIO_printf(bio_err, "invalid compromised time %s\n", arg_str);
goto end;
}
if (reason_code == 9)
reason_code = OCSP_REVOKED_STATUS_KEYCOMPROMISE;
else
reason_code = OCSP_REVOKED_STATUS_CACOMPROMISE;
}
}
if (preason)
*preason = reason_code;
if (pinvtm) {
*pinvtm = comp_time;
comp_time = NULL;
}
ret = 1;
end:
OPENSSL_free(tmp);
ASN1_GENERALIZEDTIME_free(comp_time);
return ret;
}
