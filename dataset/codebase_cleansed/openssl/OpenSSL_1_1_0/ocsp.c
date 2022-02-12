int ocsp_main(int argc, char **argv)
{
BIO *acbio = NULL, *cbio = NULL, *derbio = NULL, *out = NULL;
const EVP_MD *cert_id_md = NULL, *rsign_md = NULL;
int trailing_md = 0;
CA_DB *rdb = NULL;
EVP_PKEY *key = NULL, *rkey = NULL;
OCSP_BASICRESP *bs = NULL;
OCSP_REQUEST *req = NULL;
OCSP_RESPONSE *resp = NULL;
STACK_OF(CONF_VALUE) *headers = NULL;
STACK_OF(OCSP_CERTID) *ids = NULL;
STACK_OF(OPENSSL_STRING) *reqnames = NULL;
STACK_OF(X509) *sign_other = NULL, *verify_other = NULL, *rother = NULL;
STACK_OF(X509) *issuers = NULL;
X509 *issuer = NULL, *cert = NULL, *rca_cert = NULL;
X509 *signer = NULL, *rsigner = NULL;
X509_STORE *store = NULL;
X509_VERIFY_PARAM *vpm = NULL;
const char *CAfile = NULL, *CApath = NULL;
char *header, *value;
char *host = NULL, *port = NULL, *path = "/", *outfile = NULL;
char *rca_filename = NULL, *reqin = NULL, *respin = NULL;
char *reqout = NULL, *respout = NULL, *ridx_filename = NULL;
char *rsignfile = NULL, *rkeyfile = NULL;
char *sign_certfile = NULL, *verify_certfile = NULL, *rcertfile = NULL;
char *signfile = NULL, *keyfile = NULL;
char *thost = NULL, *tport = NULL, *tpath = NULL;
int noCAfile = 0, noCApath = 0;
int accept_count = -1, add_nonce = 1, noverify = 0, use_ssl = -1;
int vpmtouched = 0, badsig = 0, i, ignore_err = 0, nmin = 0, ndays = -1;
int req_text = 0, resp_text = 0, ret = 1;
#ifndef OPENSSL_NO_SOCK
int req_timeout = -1;
#endif
long nsec = MAX_VALIDITY_PERIOD, maxage = -1;
unsigned long sign_flags = 0, verify_flags = 0, rflags = 0;
OPTION_CHOICE o;
char *prog;
reqnames = sk_OPENSSL_STRING_new_null();
if (!reqnames)
goto end;
ids = sk_OCSP_CERTID_new_null();
if (!ids)
goto end;
if ((vpm = X509_VERIFY_PARAM_new()) == NULL)
return 1;
prog = opt_init(argc, argv, ocsp_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
ret = 0;
opt_help(ocsp_options);
goto end;
case OPT_OUTFILE:
outfile = opt_arg();
break;
case OPT_TIMEOUT:
#ifndef OPENSSL_NO_SOCK
req_timeout = atoi(opt_arg());
#endif
break;
case OPT_URL:
OPENSSL_free(thost);
OPENSSL_free(tport);
OPENSSL_free(tpath);
thost = tport = tpath = NULL;
if (!OCSP_parse_url(opt_arg(), &host, &port, &path, &use_ssl)) {
BIO_printf(bio_err, "%s Error parsing URL\n", prog);
goto end;
}
thost = host;
tport = port;
tpath = path;
break;
case OPT_HOST:
host = opt_arg();
break;
case OPT_PORT:
port = opt_arg();
break;
case OPT_IGNORE_ERR:
ignore_err = 1;
break;
case OPT_NOVERIFY:
noverify = 1;
break;
case OPT_NONCE:
add_nonce = 2;
break;
case OPT_NO_NONCE:
add_nonce = 0;
break;
case OPT_RESP_NO_CERTS:
rflags |= OCSP_NOCERTS;
break;
case OPT_RESP_KEY_ID:
rflags |= OCSP_RESPID_KEY;
break;
case OPT_NO_CERTS:
sign_flags |= OCSP_NOCERTS;
break;
case OPT_NO_SIGNATURE_VERIFY:
verify_flags |= OCSP_NOSIGS;
break;
case OPT_NO_CERT_VERIFY:
verify_flags |= OCSP_NOVERIFY;
break;
case OPT_NO_CHAIN:
verify_flags |= OCSP_NOCHAIN;
break;
case OPT_NO_CERT_CHECKS:
verify_flags |= OCSP_NOCHECKS;
break;
case OPT_NO_EXPLICIT:
verify_flags |= OCSP_NOEXPLICIT;
break;
case OPT_TRUST_OTHER:
verify_flags |= OCSP_TRUSTOTHER;
break;
case OPT_NO_INTERN:
verify_flags |= OCSP_NOINTERN;
break;
case OPT_BADSIG:
badsig = 1;
break;
case OPT_TEXT:
req_text = resp_text = 1;
break;
case OPT_REQ_TEXT:
req_text = 1;
break;
case OPT_RESP_TEXT:
resp_text = 1;
break;
case OPT_REQIN:
reqin = opt_arg();
break;
case OPT_RESPIN:
respin = opt_arg();
break;
case OPT_SIGNER:
signfile = opt_arg();
break;
case OPT_VAFILE:
verify_certfile = opt_arg();
verify_flags |= OCSP_TRUSTOTHER;
break;
case OPT_SIGN_OTHER:
sign_certfile = opt_arg();
break;
case OPT_VERIFY_OTHER:
verify_certfile = opt_arg();
break;
case OPT_CAFILE:
CAfile = opt_arg();
break;
case OPT_CAPATH:
CApath = opt_arg();
break;
case OPT_NOCAFILE:
noCAfile = 1;
break;
case OPT_NOCAPATH:
noCApath = 1;
break;
case OPT_V_CASES:
if (!opt_verify(o, vpm))
goto end;
vpmtouched++;
break;
case OPT_VALIDITY_PERIOD:
opt_long(opt_arg(), &nsec);
break;
case OPT_STATUS_AGE:
opt_long(opt_arg(), &maxage);
break;
case OPT_SIGNKEY:
keyfile = opt_arg();
break;
case OPT_REQOUT:
reqout = opt_arg();
break;
case OPT_RESPOUT:
respout = opt_arg();
break;
case OPT_PATH:
path = opt_arg();
break;
case OPT_ISSUER:
issuer = load_cert(opt_arg(), FORMAT_PEM, "issuer certificate");
if (issuer == NULL)
goto end;
if (issuers == NULL) {
if ((issuers = sk_X509_new_null()) == NULL)
goto end;
}
sk_X509_push(issuers, issuer);
break;
case OPT_CERT:
X509_free(cert);
cert = load_cert(opt_arg(), FORMAT_PEM, "certificate");
if (cert == NULL)
goto end;
if (cert_id_md == NULL)
cert_id_md = EVP_sha1();
if (!add_ocsp_cert(&req, cert, cert_id_md, issuer, ids))
goto end;
if (!sk_OPENSSL_STRING_push(reqnames, opt_arg()))
goto end;
trailing_md = 0;
break;
case OPT_SERIAL:
if (cert_id_md == NULL)
cert_id_md = EVP_sha1();
if (!add_ocsp_serial(&req, opt_arg(), cert_id_md, issuer, ids))
goto end;
if (!sk_OPENSSL_STRING_push(reqnames, opt_arg()))
goto end;
trailing_md = 0;
break;
case OPT_INDEX:
ridx_filename = opt_arg();
break;
case OPT_CA:
rca_filename = opt_arg();
break;
case OPT_NMIN:
opt_int(opt_arg(), &nmin);
if (ndays == -1)
ndays = 0;
break;
case OPT_REQUEST:
opt_int(opt_arg(), &accept_count);
break;
case OPT_NDAYS:
ndays = atoi(opt_arg());
break;
case OPT_RSIGNER:
rsignfile = opt_arg();
break;
case OPT_RKEY:
rkeyfile = opt_arg();
break;
case OPT_ROTHER:
rcertfile = opt_arg();
break;
case OPT_RMD:
if (!opt_md(opt_arg(), &rsign_md))
goto end;
break;
case OPT_HEADER:
header = opt_arg();
value = strchr(header, '=');
if (value == NULL) {
BIO_printf(bio_err, "Missing = in header key=value\n");
goto opthelp;
}
*value++ = '\0';
if (!X509V3_add_value(header, value, &headers))
goto end;
break;
case OPT_MD:
if (trailing_md) {
BIO_printf(bio_err,
"%s: Digest must be before -cert or -serial\n",
prog);
goto opthelp;
}
if (!opt_md(opt_unknown(), &cert_id_md))
goto opthelp;
trailing_md = 1;
break;
}
}
if (trailing_md) {
BIO_printf(bio_err, "%s: Digest must be before -cert or -serial\n",
prog);
goto opthelp;
}
argc = opt_num_rest();
if (argc != 0)
goto opthelp;
if (!req && !reqin && !respin && !(port && ridx_filename))
goto opthelp;
out = bio_open_default(outfile, 'w', FORMAT_TEXT);
if (out == NULL)
goto end;
if (!req && (add_nonce != 2))
add_nonce = 0;
if (!req && reqin) {
derbio = bio_open_default(reqin, 'r', FORMAT_ASN1);
if (derbio == NULL)
goto end;
req = d2i_OCSP_REQUEST_bio(derbio, NULL);
BIO_free(derbio);
if (!req) {
BIO_printf(bio_err, "Error reading OCSP request\n");
goto end;
}
}
if (!req && port) {
acbio = init_responder(port);
if (!acbio)
goto end;
}
if (rsignfile) {
if (!rkeyfile)
rkeyfile = rsignfile;
rsigner = load_cert(rsignfile, FORMAT_PEM, "responder certificate");
if (!rsigner) {
BIO_printf(bio_err, "Error loading responder certificate\n");
goto end;
}
rca_cert = load_cert(rca_filename, FORMAT_PEM, "CA certificate");
if (rcertfile) {
if (!load_certs(rcertfile, &rother, FORMAT_PEM, NULL,
"responder other certificates"))
goto end;
}
rkey = load_key(rkeyfile, FORMAT_PEM, 0, NULL, NULL,
"responder private key");
if (!rkey)
goto end;
}
if (acbio)
BIO_printf(bio_err, "Waiting for OCSP client connections...\n");
redo_accept:
if (acbio) {
if (!do_responder(&req, &cbio, acbio))
goto end;
if (!req) {
resp =
OCSP_response_create(OCSP_RESPONSE_STATUS_MALFORMEDREQUEST,
NULL);
send_ocsp_response(cbio, resp);
goto done_resp;
}
}
if (!req && (signfile || reqout || host || add_nonce || ridx_filename)) {
BIO_printf(bio_err, "Need an OCSP request for this operation!\n");
goto end;
}
if (req && add_nonce)
OCSP_request_add1_nonce(req, NULL, -1);
if (signfile) {
if (!keyfile)
keyfile = signfile;
signer = load_cert(signfile, FORMAT_PEM, "signer certificate");
if (!signer) {
BIO_printf(bio_err, "Error loading signer certificate\n");
goto end;
}
if (sign_certfile) {
if (!load_certs(sign_certfile, &sign_other, FORMAT_PEM, NULL,
"signer certificates"))
goto end;
}
key = load_key(keyfile, FORMAT_PEM, 0, NULL, NULL,
"signer private key");
if (!key)
goto end;
if (!OCSP_request_sign
(req, signer, key, NULL, sign_other, sign_flags)) {
BIO_printf(bio_err, "Error signing OCSP request\n");
goto end;
}
}
if (req_text && req)
OCSP_REQUEST_print(out, req, 0);
if (reqout) {
derbio = bio_open_default(reqout, 'w', FORMAT_ASN1);
if (derbio == NULL)
goto end;
i2d_OCSP_REQUEST_bio(derbio, req);
BIO_free(derbio);
}
if (ridx_filename && (!rkey || !rsigner || !rca_cert)) {
BIO_printf(bio_err,
"Need a responder certificate, key and CA for this operation!\n");
goto end;
}
if (ridx_filename && !rdb) {
rdb = load_index(ridx_filename, NULL);
if (!rdb)
goto end;
if (!index_index(rdb))
goto end;
}
if (rdb) {
make_ocsp_response(&resp, req, rdb, rca_cert, rsigner, rkey,
rsign_md, rother, rflags, nmin, ndays, badsig);
if (cbio)
send_ocsp_response(cbio, resp);
} else if (host) {
# ifndef OPENSSL_NO_SOCK
resp = process_responder(req, host, path,
port, use_ssl, headers, req_timeout);
if (!resp)
goto end;
# else
BIO_printf(bio_err,
"Error creating connect BIO - sockets not supported.\n");
goto end;
# endif
} else if (respin) {
derbio = bio_open_default(respin, 'r', FORMAT_ASN1);
if (derbio == NULL)
goto end;
resp = d2i_OCSP_RESPONSE_bio(derbio, NULL);
BIO_free(derbio);
if (!resp) {
BIO_printf(bio_err, "Error reading OCSP response\n");
goto end;
}
} else {
ret = 0;
goto end;
}
done_resp:
if (respout) {
derbio = bio_open_default(respout, 'w', FORMAT_ASN1);
if (derbio == NULL)
goto end;
i2d_OCSP_RESPONSE_bio(derbio, resp);
BIO_free(derbio);
}
i = OCSP_response_status(resp);
if (i != OCSP_RESPONSE_STATUS_SUCCESSFUL) {
BIO_printf(out, "Responder Error: %s (%d)\n",
OCSP_response_status_str(i), i);
if (ignore_err)
goto redo_accept;
ret = 0;
goto end;
}
if (resp_text)
OCSP_RESPONSE_print(out, resp, 0);
if (cbio) {
if (accept_count != -1 && --accept_count <= 0) {
ret = 0;
goto end;
}
BIO_free_all(cbio);
cbio = NULL;
OCSP_REQUEST_free(req);
req = NULL;
OCSP_RESPONSE_free(resp);
resp = NULL;
goto redo_accept;
}
if (ridx_filename) {
ret = 0;
goto end;
}
if (!store) {
store = setup_verify(CAfile, CApath, noCAfile, noCApath);
if (!store)
goto end;
}
if (vpmtouched)
X509_STORE_set1_param(store, vpm);
if (verify_certfile) {
if (!load_certs(verify_certfile, &verify_other, FORMAT_PEM, NULL,
"validator certificate"))
goto end;
}
bs = OCSP_response_get1_basic(resp);
if (!bs) {
BIO_printf(bio_err, "Error parsing response\n");
goto end;
}
ret = 0;
if (!noverify) {
if (req && ((i = OCSP_check_nonce(req, bs)) <= 0)) {
if (i == -1)
BIO_printf(bio_err, "WARNING: no nonce in response\n");
else {
BIO_printf(bio_err, "Nonce Verify error\n");
ret = 1;
goto end;
}
}
i = OCSP_basic_verify(bs, verify_other, store, verify_flags);
if (i <= 0 && issuers) {
i = OCSP_basic_verify(bs, issuers, store, OCSP_TRUSTOTHER);
if (i > 0)
ERR_clear_error();
}
if (i <= 0) {
BIO_printf(bio_err, "Response Verify Failure\n");
ERR_print_errors(bio_err);
ret = 1;
} else
BIO_printf(bio_err, "Response verify OK\n");
}
print_ocsp_summary(out, bs, req, reqnames, ids, nsec, maxage);
end:
ERR_print_errors(bio_err);
X509_free(signer);
X509_STORE_free(store);
X509_VERIFY_PARAM_free(vpm);
EVP_PKEY_free(key);
EVP_PKEY_free(rkey);
X509_free(cert);
sk_X509_pop_free(issuers, X509_free);
X509_free(rsigner);
X509_free(rca_cert);
free_index(rdb);
BIO_free_all(cbio);
BIO_free_all(acbio);
BIO_free(out);
OCSP_REQUEST_free(req);
OCSP_RESPONSE_free(resp);
OCSP_BASICRESP_free(bs);
sk_OPENSSL_STRING_free(reqnames);
sk_OCSP_CERTID_free(ids);
sk_X509_pop_free(sign_other, X509_free);
sk_X509_pop_free(verify_other, X509_free);
sk_CONF_VALUE_pop_free(headers, X509V3_conf_free);
OPENSSL_free(thost);
OPENSSL_free(tport);
OPENSSL_free(tpath);
return (ret);
}
static char **lookup_serial(CA_DB *db, ASN1_INTEGER *ser)
{
int i;
BIGNUM *bn = NULL;
char *itmp, *row[DB_NUMBER], **rrow;
for (i = 0; i < DB_NUMBER; i++)
row[i] = NULL;
bn = ASN1_INTEGER_to_BN(ser, NULL);
OPENSSL_assert(bn);
if (BN_is_zero(bn))
itmp = OPENSSL_strdup("00");
else
itmp = BN_bn2hex(bn);
row[DB_serial] = itmp;
BN_free(bn);
rrow = TXT_DB_get_by_index(db->db, DB_serial, row);
OPENSSL_free(itmp);
return rrow;
}
static BIO *init_responder(const char *port)
{
# ifdef OPENSSL_NO_SOCK
BIO_printf(bio_err,
"Error setting up accept BIO - sockets not supported.\n");
return NULL;
# else
BIO *acbio = NULL, *bufbio = NULL;
bufbio = BIO_new(BIO_f_buffer());
if (bufbio == NULL)
goto err;
acbio = BIO_new(BIO_s_accept());
if (acbio == NULL
|| BIO_set_bind_mode(acbio, BIO_BIND_REUSEADDR) < 0
|| BIO_set_accept_port(acbio, port) < 0) {
BIO_printf(bio_err, "Error setting up accept BIO\n");
ERR_print_errors(bio_err);
goto err;
}
BIO_set_accept_bios(acbio, bufbio);
bufbio = NULL;
if (BIO_do_accept(acbio) <= 0) {
BIO_printf(bio_err, "Error starting accept\n");
ERR_print_errors(bio_err);
goto err;
}
return acbio;
err:
BIO_free_all(acbio);
BIO_free(bufbio);
return NULL;
# endif
}
static int urldecode(char *p)
{
unsigned char *out = (unsigned char *)p;
unsigned char *save = out;
for (; *p; p++) {
if (*p != '%')
*out++ = *p;
else if (isxdigit(_UC(p[1])) && isxdigit(_UC(p[2]))) {
*out++ = (OPENSSL_hexchar2int(p[1]) << 4)
| OPENSSL_hexchar2int(p[2]);
p += 2;
}
else
return -1;
}
*out = '\0';
return (int)(out - save);
}
static int do_responder(OCSP_REQUEST **preq, BIO **pcbio, BIO *acbio)
{
# ifdef OPENSSL_NO_SOCK
return 0;
# else
int len;
OCSP_REQUEST *req = NULL;
char inbuf[2048], reqbuf[2048];
char *p, *q;
BIO *cbio = NULL, *getbio = NULL, *b64 = NULL;
if (BIO_do_accept(acbio) <= 0) {
BIO_printf(bio_err, "Error accepting connection\n");
ERR_print_errors(bio_err);
return 0;
}
cbio = BIO_pop(acbio);
*pcbio = cbio;
len = BIO_gets(cbio, reqbuf, sizeof reqbuf);
if (len <= 0)
return 1;
if (strncmp(reqbuf, "GET ", 4) == 0) {
for (p = reqbuf + 4; *p == ' '; ++p)
continue;
if (*p != '/') {
BIO_printf(bio_err, "Invalid request -- bad URL\n");
return 1;
}
p++;
for (q = p; *q; q++)
if (*q == ' ')
break;
if (strncmp(q, " HTTP/1.", 8) != 0) {
BIO_printf(bio_err, "Invalid request -- bad HTTP vesion\n");
return 1;
}
*q = '\0';
len = urldecode(p);
if (len <= 0) {
BIO_printf(bio_err, "Invalid request -- bad URL encoding\n");
return 1;
}
if ((getbio = BIO_new_mem_buf(p, len)) == NULL
|| (b64 = BIO_new(BIO_f_base64())) == NULL) {
BIO_printf(bio_err, "Could not allocate memory\n");
ERR_print_errors(bio_err);
return 1;
}
BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
getbio = BIO_push(b64, getbio);
} else if (strncmp(reqbuf, "POST ", 5) != 0) {
BIO_printf(bio_err, "Invalid request -- bad HTTP verb\n");
return 1;
}
for (;;) {
len = BIO_gets(cbio, inbuf, sizeof inbuf);
if (len <= 0)
return 1;
if ((inbuf[0] == '\r') || (inbuf[0] == '\n'))
break;
}
if (getbio) {
req = d2i_OCSP_REQUEST_bio(getbio, NULL);
BIO_free_all(getbio);
} else
req = d2i_OCSP_REQUEST_bio(cbio, NULL);
if (!req) {
BIO_printf(bio_err, "Error parsing OCSP request\n");
ERR_print_errors(bio_err);
}
*preq = req;
return 1;
# endif
}
static int send_ocsp_response(BIO *cbio, OCSP_RESPONSE *resp)
{
char http_resp[] =
"HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\n"
"Content-Length: %d\r\n\r\n";
if (!cbio)
return 0;
BIO_printf(cbio, http_resp, i2d_OCSP_RESPONSE(resp, NULL));
i2d_OCSP_RESPONSE_bio(cbio, resp);
(void)BIO_flush(cbio);
return 1;
}
