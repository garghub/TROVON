int MAIN(int argc, char **argv)
{
int ret = 1;
char *configfile = NULL;
char *section = NULL;
CONF *conf = NULL;
enum mode {
CMD_NONE, CMD_QUERY, CMD_REPLY, CMD_VERIFY
} mode = CMD_NONE;
char *data = NULL;
char *digest = NULL;
const EVP_MD *md = NULL;
char *rnd = NULL;
char *policy = NULL;
int no_nonce = 0;
int cert = 0;
char *in = NULL;
char *out = NULL;
int text = 0;
char *queryfile = NULL;
char *passin = NULL;
char *password = NULL;
char *inkey = NULL;
char *signer = NULL;
char *chain = NULL;
char *ca_path = NULL;
char *ca_file = NULL;
char *untrusted = NULL;
char *engine = NULL;
int token_in = 0;
int token_out = 0;
int free_bio_err = 0;
ERR_load_crypto_strings();
apps_startup();
if (bio_err == NULL && (bio_err = BIO_new(BIO_s_file())) != NULL) {
free_bio_err = 1;
BIO_set_fp(bio_err, stderr, BIO_NOCLOSE | BIO_FP_TEXT);
}
if (!load_config(bio_err, NULL))
goto cleanup;
for (argc--, argv++; argc > 0; argc--, argv++) {
if (strcmp(*argv, "-config") == 0) {
if (argc-- < 1)
goto usage;
configfile = *++argv;
} else if (strcmp(*argv, "-section") == 0) {
if (argc-- < 1)
goto usage;
section = *++argv;
} else if (strcmp(*argv, "-query") == 0) {
if (mode != CMD_NONE)
goto usage;
mode = CMD_QUERY;
} else if (strcmp(*argv, "-data") == 0) {
if (argc-- < 1)
goto usage;
data = *++argv;
} else if (strcmp(*argv, "-digest") == 0) {
if (argc-- < 1)
goto usage;
digest = *++argv;
} else if (strcmp(*argv, "-rand") == 0) {
if (argc-- < 1)
goto usage;
rnd = *++argv;
} else if (strcmp(*argv, "-policy") == 0) {
if (argc-- < 1)
goto usage;
policy = *++argv;
} else if (strcmp(*argv, "-no_nonce") == 0) {
no_nonce = 1;
} else if (strcmp(*argv, "-cert") == 0) {
cert = 1;
} else if (strcmp(*argv, "-in") == 0) {
if (argc-- < 1)
goto usage;
in = *++argv;
} else if (strcmp(*argv, "-token_in") == 0) {
token_in = 1;
} else if (strcmp(*argv, "-out") == 0) {
if (argc-- < 1)
goto usage;
out = *++argv;
} else if (strcmp(*argv, "-token_out") == 0) {
token_out = 1;
} else if (strcmp(*argv, "-text") == 0) {
text = 1;
} else if (strcmp(*argv, "-reply") == 0) {
if (mode != CMD_NONE)
goto usage;
mode = CMD_REPLY;
} else if (strcmp(*argv, "-queryfile") == 0) {
if (argc-- < 1)
goto usage;
queryfile = *++argv;
} else if (strcmp(*argv, "-passin") == 0) {
if (argc-- < 1)
goto usage;
passin = *++argv;
} else if (strcmp(*argv, "-inkey") == 0) {
if (argc-- < 1)
goto usage;
inkey = *++argv;
} else if (strcmp(*argv, "-signer") == 0) {
if (argc-- < 1)
goto usage;
signer = *++argv;
} else if (strcmp(*argv, "-chain") == 0) {
if (argc-- < 1)
goto usage;
chain = *++argv;
} else if (strcmp(*argv, "-verify") == 0) {
if (mode != CMD_NONE)
goto usage;
mode = CMD_VERIFY;
} else if (strcmp(*argv, "-CApath") == 0) {
if (argc-- < 1)
goto usage;
ca_path = *++argv;
} else if (strcmp(*argv, "-CAfile") == 0) {
if (argc-- < 1)
goto usage;
ca_file = *++argv;
} else if (strcmp(*argv, "-untrusted") == 0) {
if (argc-- < 1)
goto usage;
untrusted = *++argv;
} else if (strcmp(*argv, "-engine") == 0) {
if (argc-- < 1)
goto usage;
engine = *++argv;
} else if ((md = EVP_get_digestbyname(*argv + 1)) != NULL) {
} else
goto usage;
}
if (mode == CMD_QUERY && !no_nonce) {
if (!app_RAND_load_file(NULL, bio_err, 1) && rnd == NULL)
BIO_printf(bio_err, "warning, not much extra random "
"data, consider using the -rand option\n");
if (rnd != NULL)
BIO_printf(bio_err, "%ld semi-random bytes loaded\n",
app_RAND_load_files(rnd));
}
if (mode == CMD_REPLY && passin &&
!app_passwd(bio_err, passin, NULL, &password, NULL)) {
BIO_printf(bio_err, "Error getting password.\n");
goto cleanup;
}
switch (mode) {
case CMD_NONE:
goto usage;
case CMD_QUERY:
ret = data != NULL && digest != NULL;
if (ret)
goto usage;
conf = load_config_file(configfile);
ret = !query_command(data, digest, md, policy, no_nonce, cert,
in, out, text);
break;
case CMD_REPLY:
conf = load_config_file(configfile);
if (in == NULL) {
ret = !(queryfile != NULL && conf != NULL && !token_in);
if (ret)
goto usage;
} else {
ret = !(queryfile == NULL);
if (ret)
goto usage;
}
ret = !reply_command(conf, section, engine, queryfile,
password, inkey, signer, chain, policy,
in, token_in, out, token_out, text);
break;
case CMD_VERIFY:
ret = !(((queryfile && !data && !digest)
|| (!queryfile && data && !digest)
|| (!queryfile && !data && digest))
&& in != NULL);
if (ret)
goto usage;
ret = !verify_command(data, digest, queryfile, in, token_in,
ca_path, ca_file, untrusted);
}
goto cleanup;
usage:
BIO_printf(bio_err, "usage:\n"
"ts -query [-rand file%cfile%c...] [-config configfile] "
"[-data file_to_hash] [-digest digest_bytes]"
"[-md2|-md4|-md5|-sha|-sha1|-mdc2|-ripemd160] "
"[-policy object_id] [-no_nonce] [-cert] "
"[-in request.tsq] [-out request.tsq] [-text]\n",
LIST_SEPARATOR_CHAR, LIST_SEPARATOR_CHAR);
BIO_printf(bio_err, "or\n"
"ts -reply [-config configfile] [-section tsa_section] "
"[-queryfile request.tsq] [-passin password] "
"[-signer tsa_cert.pem] [-inkey private_key.pem] "
"[-chain certs_file.pem] [-policy object_id] "
"[-in response.tsr] [-token_in] "
"[-out response.tsr] [-token_out] [-text] [-engine id]\n");
BIO_printf(bio_err, "or\n"
"ts -verify [-data file_to_hash] [-digest digest_bytes] "
"[-queryfile request.tsq] "
"-in response.tsr [-token_in] "
"-CApath ca_path -CAfile ca_file.pem "
"-untrusted cert_file.pem\n");
cleanup:
app_RAND_write_file(NULL, bio_err);
NCONF_free(conf);
OPENSSL_free(password);
OBJ_cleanup();
if (free_bio_err) {
BIO_free_all(bio_err);
bio_err = NULL;
}
OPENSSL_EXIT(ret);
}
static ASN1_OBJECT *txt2obj(const char *oid)
{
ASN1_OBJECT *oid_obj = NULL;
if (!(oid_obj = OBJ_txt2obj(oid, 0)))
BIO_printf(bio_err, "cannot convert %s to OID\n", oid);
return oid_obj;
}
static CONF *load_config_file(const char *configfile)
{
CONF *conf = NULL;
long errorline = -1;
if (!configfile)
configfile = getenv("OPENSSL_CONF");
if (!configfile)
configfile = getenv("SSLEAY_CONF");
if (configfile &&
(!(conf = NCONF_new(NULL)) ||
NCONF_load(conf, configfile, &errorline) <= 0)) {
if (errorline <= 0)
BIO_printf(bio_err, "error loading the config file "
"'%s'\n", configfile);
else
BIO_printf(bio_err, "error on line %ld of config file "
"'%s'\n", errorline, configfile);
}
if (conf != NULL) {
const char *p;
BIO_printf(bio_err, "Using configuration from %s\n", configfile);
p = NCONF_get_string(conf, NULL, ENV_OID_FILE);
if (p != NULL) {
BIO *oid_bio = BIO_new_file(p, "r");
if (!oid_bio)
ERR_print_errors(bio_err);
else {
OBJ_create_objects(oid_bio);
BIO_free_all(oid_bio);
}
} else
ERR_clear_error();
if (!add_oid_section(bio_err, conf))
ERR_print_errors(bio_err);
}
return conf;
}
static int query_command(const char *data, char *digest, const EVP_MD *md,
const char *policy, int no_nonce,
int cert, const char *in, const char *out, int text)
{
int ret = 0;
TS_REQ *query = NULL;
BIO *in_bio = NULL;
BIO *data_bio = NULL;
BIO *out_bio = NULL;
if (in != NULL) {
if ((in_bio = BIO_new_file(in, "rb")) == NULL)
goto end;
query = d2i_TS_REQ_bio(in_bio, NULL);
} else {
if (!digest && !(data_bio = BIO_open_with_default(data, "rb", stdin)))
goto end;
query = create_query(data_bio, digest, md, policy, no_nonce, cert);
}
if (query == NULL)
goto end;
if ((out_bio = BIO_open_with_default(out, "wb", stdout)) == NULL)
goto end;
if (text) {
if (!TS_REQ_print_bio(out_bio, query))
goto end;
} else {
if (!i2d_TS_REQ_bio(out_bio, query))
goto end;
}
ret = 1;
end:
ERR_print_errors(bio_err);
BIO_free_all(in_bio);
BIO_free_all(data_bio);
BIO_free_all(out_bio);
TS_REQ_free(query);
return ret;
}
static BIO *BIO_open_with_default(const char *file, const char *mode,
FILE *default_fp)
{
return file == NULL ? BIO_new_fp(default_fp, BIO_NOCLOSE)
: BIO_new_file(file, mode);
}
static TS_REQ *create_query(BIO *data_bio, char *digest, const EVP_MD *md,
const char *policy, int no_nonce, int cert)
{
int ret = 0;
TS_REQ *ts_req = NULL;
int len;
TS_MSG_IMPRINT *msg_imprint = NULL;
X509_ALGOR *algo = NULL;
unsigned char *data = NULL;
ASN1_OBJECT *policy_obj = NULL;
ASN1_INTEGER *nonce_asn1 = NULL;
if (!md && !(md = EVP_get_digestbyname("sha1")))
goto err;
if (!(ts_req = TS_REQ_new()))
goto err;
if (!TS_REQ_set_version(ts_req, 1))
goto err;
if (!(msg_imprint = TS_MSG_IMPRINT_new()))
goto err;
if (!(algo = X509_ALGOR_new()))
goto err;
if (!(algo->algorithm = OBJ_nid2obj(EVP_MD_type(md))))
goto err;
if (!(algo->parameter = ASN1_TYPE_new()))
goto err;
algo->parameter->type = V_ASN1_NULL;
if (!TS_MSG_IMPRINT_set_algo(msg_imprint, algo))
goto err;
if ((len = create_digest(data_bio, digest, md, &data)) == 0)
goto err;
if (!TS_MSG_IMPRINT_set_msg(msg_imprint, data, len))
goto err;
if (!TS_REQ_set_msg_imprint(ts_req, msg_imprint))
goto err;
if (policy && !(policy_obj = txt2obj(policy)))
goto err;
if (policy_obj && !TS_REQ_set_policy_id(ts_req, policy_obj))
goto err;
if (!no_nonce && !(nonce_asn1 = create_nonce(NONCE_LENGTH)))
goto err;
if (nonce_asn1 && !TS_REQ_set_nonce(ts_req, nonce_asn1))
goto err;
if (!TS_REQ_set_cert_req(ts_req, cert))
goto err;
ret = 1;
err:
if (!ret) {
TS_REQ_free(ts_req);
ts_req = NULL;
BIO_printf(bio_err, "could not create query\n");
}
TS_MSG_IMPRINT_free(msg_imprint);
X509_ALGOR_free(algo);
OPENSSL_free(data);
ASN1_OBJECT_free(policy_obj);
ASN1_INTEGER_free(nonce_asn1);
return ts_req;
}
static int create_digest(BIO *input, char *digest, const EVP_MD *md,
unsigned char **md_value)
{
int md_value_len;
md_value_len = EVP_MD_size(md);
if (md_value_len < 0)
goto err;
if (input) {
EVP_MD_CTX md_ctx;
unsigned char buffer[4096];
int length;
*md_value = OPENSSL_malloc(md_value_len);
if (*md_value == 0)
goto err;
EVP_DigestInit(&md_ctx, md);
while ((length = BIO_read(input, buffer, sizeof(buffer))) > 0) {
EVP_DigestUpdate(&md_ctx, buffer, length);
}
EVP_DigestFinal(&md_ctx, *md_value, NULL);
} else {
long digest_len;
*md_value = string_to_hex(digest, &digest_len);
if (!*md_value || md_value_len != digest_len) {
OPENSSL_free(*md_value);
*md_value = NULL;
BIO_printf(bio_err, "bad digest, %d bytes "
"must be specified\n", md_value_len);
goto err;
}
}
return md_value_len;
err:
return 0;
}
static ASN1_INTEGER *create_nonce(int bits)
{
unsigned char buf[20];
ASN1_INTEGER *nonce = NULL;
int len = (bits - 1) / 8 + 1;
int i;
if (len > (int)sizeof(buf))
goto err;
if (RAND_bytes(buf, len) <= 0)
goto err;
for (i = 0; i < len && !buf[i]; ++i) ;
if (!(nonce = ASN1_INTEGER_new()))
goto err;
OPENSSL_free(nonce->data);
nonce->length = len - i;
if (!(nonce->data = OPENSSL_malloc(nonce->length + 1)))
goto err;
memcpy(nonce->data, buf + i, nonce->length);
return nonce;
err:
BIO_printf(bio_err, "could not create nonce\n");
ASN1_INTEGER_free(nonce);
return NULL;
}
static int reply_command(CONF *conf, char *section, char *engine,
char *queryfile, char *passin, char *inkey,
char *signer, char *chain, const char *policy,
char *in, int token_in,
char *out, int token_out, int text)
{
int ret = 0;
TS_RESP *response = NULL;
BIO *in_bio = NULL;
BIO *query_bio = NULL;
BIO *inkey_bio = NULL;
BIO *signer_bio = NULL;
BIO *out_bio = NULL;
if (in != NULL) {
if ((in_bio = BIO_new_file(in, "rb")) == NULL)
goto end;
if (token_in) {
response = read_PKCS7(in_bio);
} else {
response = d2i_TS_RESP_bio(in_bio, NULL);
}
} else {
response = create_response(conf, section, engine, queryfile,
passin, inkey, signer, chain, policy);
if (response)
BIO_printf(bio_err, "Response has been generated.\n");
else
BIO_printf(bio_err, "Response is not generated.\n");
}
if (response == NULL)
goto end;
if ((out_bio = BIO_open_with_default(out, "wb", stdout)) == NULL)
goto end;
if (text) {
if (token_out) {
TS_TST_INFO *tst_info = TS_RESP_get_tst_info(response);
if (!TS_TST_INFO_print_bio(out_bio, tst_info))
goto end;
} else {
if (!TS_RESP_print_bio(out_bio, response))
goto end;
}
} else {
if (token_out) {
PKCS7 *token = TS_RESP_get_token(response);
if (!i2d_PKCS7_bio(out_bio, token))
goto end;
} else {
if (!i2d_TS_RESP_bio(out_bio, response))
goto end;
}
}
ret = 1;
end:
ERR_print_errors(bio_err);
BIO_free_all(in_bio);
BIO_free_all(query_bio);
BIO_free_all(inkey_bio);
BIO_free_all(signer_bio);
BIO_free_all(out_bio);
TS_RESP_free(response);
return ret;
}
static TS_RESP *read_PKCS7(BIO *in_bio)
{
int ret = 0;
PKCS7 *token = NULL;
TS_TST_INFO *tst_info = NULL;
TS_RESP *resp = NULL;
TS_STATUS_INFO *si = NULL;
if (!(token = d2i_PKCS7_bio(in_bio, NULL)))
goto end;
if (!(tst_info = PKCS7_to_TS_TST_INFO(token)))
goto end;
if (!(resp = TS_RESP_new()))
goto end;
if (!(si = TS_STATUS_INFO_new()))
goto end;
if (!(ASN1_INTEGER_set(si->status, TS_STATUS_GRANTED)))
goto end;
if (!TS_RESP_set_status_info(resp, si))
goto end;
TS_RESP_set_tst_info(resp, token, tst_info);
token = NULL;
tst_info = NULL;
ret = 1;
end:
PKCS7_free(token);
TS_TST_INFO_free(tst_info);
if (!ret) {
TS_RESP_free(resp);
resp = NULL;
}
TS_STATUS_INFO_free(si);
return resp;
}
static TS_RESP *create_response(CONF *conf, const char *section, char *engine,
char *queryfile, char *passin, char *inkey,
char *signer, char *chain, const char *policy)
{
int ret = 0;
TS_RESP *response = NULL;
BIO *query_bio = NULL;
TS_RESP_CTX *resp_ctx = NULL;
if (!(query_bio = BIO_new_file(queryfile, "rb")))
goto end;
if (!(section = TS_CONF_get_tsa_section(conf, section)))
goto end;
if (!(resp_ctx = TS_RESP_CTX_new()))
goto end;
if (!TS_CONF_set_serial(conf, section, serial_cb, resp_ctx))
goto end;
#ifndef OPENSSL_NO_ENGINE
if (!TS_CONF_set_crypto_device(conf, section, engine))
goto end;
#endif
if (!TS_CONF_set_signer_cert(conf, section, signer, resp_ctx))
goto end;
if (!TS_CONF_set_certs(conf, section, chain, resp_ctx))
goto end;
if (!TS_CONF_set_signer_key(conf, section, inkey, passin, resp_ctx))
goto end;
if (!TS_CONF_set_def_policy(conf, section, policy, resp_ctx))
goto end;
if (!TS_CONF_set_policies(conf, section, resp_ctx))
goto end;
if (!TS_CONF_set_digests(conf, section, resp_ctx))
goto end;
if (!TS_CONF_set_accuracy(conf, section, resp_ctx))
goto end;
if (!TS_CONF_set_clock_precision_digits(conf, section, resp_ctx))
goto end;
if (!TS_CONF_set_ordering(conf, section, resp_ctx))
goto end;
if (!TS_CONF_set_tsa_name(conf, section, resp_ctx))
goto end;
if (!TS_CONF_set_ess_cert_id_chain(conf, section, resp_ctx))
goto end;
if (!(response = TS_RESP_create_response(resp_ctx, query_bio)))
goto end;
ret = 1;
end:
if (!ret) {
TS_RESP_free(response);
response = NULL;
}
TS_RESP_CTX_free(resp_ctx);
BIO_free_all(query_bio);
return response;
}
static ASN1_INTEGER *MS_CALLBACK serial_cb(TS_RESP_CTX *ctx, void *data)
{
const char *serial_file = (const char *)data;
ASN1_INTEGER *serial = next_serial(serial_file);
if (!serial) {
TS_RESP_CTX_set_status_info(ctx, TS_STATUS_REJECTION,
"Error during serial number "
"generation.");
TS_RESP_CTX_add_failure_info(ctx, TS_INFO_ADD_INFO_NOT_AVAILABLE);
} else
save_ts_serial(serial_file, serial);
return serial;
}
static ASN1_INTEGER *next_serial(const char *serialfile)
{
int ret = 0;
BIO *in = NULL;
ASN1_INTEGER *serial = NULL;
BIGNUM *bn = NULL;
if (!(serial = ASN1_INTEGER_new()))
goto err;
if (!(in = BIO_new_file(serialfile, "r"))) {
ERR_clear_error();
BIO_printf(bio_err, "Warning: could not open file %s for "
"reading, using serial number: 1\n", serialfile);
if (!ASN1_INTEGER_set(serial, 1))
goto err;
} else {
char buf[1024];
if (!a2i_ASN1_INTEGER(in, serial, buf, sizeof(buf))) {
BIO_printf(bio_err, "unable to load number from %s\n",
serialfile);
goto err;
}
if (!(bn = ASN1_INTEGER_to_BN(serial, NULL)))
goto err;
ASN1_INTEGER_free(serial);
serial = NULL;
if (!BN_add_word(bn, 1))
goto err;
if (!(serial = BN_to_ASN1_INTEGER(bn, NULL)))
goto err;
}
ret = 1;
err:
if (!ret) {
ASN1_INTEGER_free(serial);
serial = NULL;
}
BIO_free_all(in);
BN_free(bn);
return serial;
}
static int save_ts_serial(const char *serialfile, ASN1_INTEGER *serial)
{
int ret = 0;
BIO *out = NULL;
if (!(out = BIO_new_file(serialfile, "w")))
goto err;
if (i2a_ASN1_INTEGER(out, serial) <= 0)
goto err;
if (BIO_puts(out, "\n") <= 0)
goto err;
ret = 1;
err:
if (!ret)
BIO_printf(bio_err, "could not save serial number to %s\n",
serialfile);
BIO_free_all(out);
return ret;
}
static int verify_command(char *data, char *digest, char *queryfile,
char *in, int token_in,
char *ca_path, char *ca_file, char *untrusted)
{
BIO *in_bio = NULL;
PKCS7 *token = NULL;
TS_RESP *response = NULL;
TS_VERIFY_CTX *verify_ctx = NULL;
int ret = 0;
if (!(in_bio = BIO_new_file(in, "rb")))
goto end;
if (token_in) {
if (!(token = d2i_PKCS7_bio(in_bio, NULL)))
goto end;
} else {
if (!(response = d2i_TS_RESP_bio(in_bio, NULL)))
goto end;
}
if (!(verify_ctx = create_verify_ctx(data, digest, queryfile,
ca_path, ca_file, untrusted)))
goto end;
ret = token_in ?
TS_RESP_verify_token(verify_ctx, token) :
TS_RESP_verify_response(verify_ctx, response);
end:
printf("Verification: ");
if (ret)
printf("OK\n");
else {
printf("FAILED\n");
ERR_print_errors(bio_err);
}
BIO_free_all(in_bio);
PKCS7_free(token);
TS_RESP_free(response);
TS_VERIFY_CTX_free(verify_ctx);
return ret;
}
static TS_VERIFY_CTX *create_verify_ctx(char *data, char *digest,
char *queryfile,
char *ca_path, char *ca_file,
char *untrusted)
{
TS_VERIFY_CTX *ctx = NULL;
BIO *input = NULL;
TS_REQ *request = NULL;
int ret = 0;
if (data != NULL || digest != NULL) {
if (!(ctx = TS_VERIFY_CTX_new()))
goto err;
ctx->flags = TS_VFY_VERSION | TS_VFY_SIGNER;
if (data != NULL) {
ctx->flags |= TS_VFY_DATA;
if (!(ctx->data = BIO_new_file(data, "rb")))
goto err;
} else if (digest != NULL) {
long imprint_len;
ctx->flags |= TS_VFY_IMPRINT;
if (!(ctx->imprint = string_to_hex(digest, &imprint_len))) {
BIO_printf(bio_err, "invalid digest string\n");
goto err;
}
ctx->imprint_len = imprint_len;
}
} else if (queryfile != NULL) {
if (!(input = BIO_new_file(queryfile, "rb")))
goto err;
if (!(request = d2i_TS_REQ_bio(input, NULL)))
goto err;
if (!(ctx = TS_REQ_to_TS_VERIFY_CTX(request, NULL)))
goto err;
} else
return NULL;
ctx->flags |= TS_VFY_SIGNATURE;
if (!(ctx->store = create_cert_store(ca_path, ca_file)))
goto err;
if (untrusted && !(ctx->certs = TS_CONF_load_certs(untrusted)))
goto err;
ret = 1;
err:
if (!ret) {
TS_VERIFY_CTX_free(ctx);
ctx = NULL;
}
BIO_free_all(input);
TS_REQ_free(request);
return ctx;
}
static X509_STORE *create_cert_store(char *ca_path, char *ca_file)
{
X509_STORE *cert_ctx = NULL;
X509_LOOKUP *lookup = NULL;
int i;
cert_ctx = X509_STORE_new();
X509_STORE_set_verify_cb(cert_ctx, verify_cb);
if (ca_path) {
lookup = X509_STORE_add_lookup(cert_ctx, X509_LOOKUP_hash_dir());
if (lookup == NULL) {
BIO_printf(bio_err, "memory allocation failure\n");
goto err;
}
i = X509_LOOKUP_add_dir(lookup, ca_path, X509_FILETYPE_PEM);
if (!i) {
BIO_printf(bio_err, "Error loading directory %s\n", ca_path);
goto err;
}
}
if (ca_file) {
lookup = X509_STORE_add_lookup(cert_ctx, X509_LOOKUP_file());
if (lookup == NULL) {
BIO_printf(bio_err, "memory allocation failure\n");
goto err;
}
i = X509_LOOKUP_load_file(lookup, ca_file, X509_FILETYPE_PEM);
if (!i) {
BIO_printf(bio_err, "Error loading file %s\n", ca_file);
goto err;
}
}
return cert_ctx;
err:
X509_STORE_free(cert_ctx);
return NULL;
}
static int MS_CALLBACK verify_cb(int ok, X509_STORE_CTX *ctx)
{
return ok;
}
