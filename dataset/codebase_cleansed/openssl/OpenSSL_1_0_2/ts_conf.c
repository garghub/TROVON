X509 *TS_CONF_load_cert(const char *file)
{
BIO *cert = NULL;
X509 *x = NULL;
if ((cert = BIO_new_file(file, "r")) == NULL)
goto end;
x = PEM_read_bio_X509_AUX(cert, NULL, NULL, NULL);
end:
if (x == NULL)
fprintf(stderr, "unable to load certificate: %s\n", file);
BIO_free(cert);
return x;
}
void TS_CONF_lookup_fail(const char *name, const char *tag)
{
fprintf(stderr, "variable lookup failed for %s::%s\n", name, tag);
}
static void TS_CONF_invalid(const char *name, const char *tag)
{
fprintf(stderr, "invalid variable value for %s::%s\n", name, tag);
}
const char *TS_CONF_get_tsa_section(CONF *conf, const char *section)
{
if (!section) {
section = NCONF_get_string(conf, BASE_SECTION, ENV_DEFAULT_TSA);
if (!section)
TS_CONF_lookup_fail(BASE_SECTION, ENV_DEFAULT_TSA);
}
return section;
}
int TS_CONF_set_serial(CONF *conf, const char *section, TS_serial_cb cb,
TS_RESP_CTX *ctx)
{
int ret = 0;
char *serial = NCONF_get_string(conf, section, ENV_SERIAL);
if (!serial) {
TS_CONF_lookup_fail(section, ENV_SERIAL);
goto err;
}
TS_RESP_CTX_set_serial_cb(ctx, cb, serial);
ret = 1;
err:
return ret;
}
int TS_CONF_set_crypto_device(CONF *conf, const char *section,
const char *device)
{
int ret = 0;
if (!device)
device = NCONF_get_string(conf, section, ENV_CRYPTO_DEVICE);
if (device && !TS_CONF_set_default_engine(device)) {
TS_CONF_invalid(section, ENV_CRYPTO_DEVICE);
goto err;
}
ret = 1;
err:
return ret;
}
int TS_CONF_set_default_engine(const char *name)
{
ENGINE *e = NULL;
int ret = 0;
if (strcmp(name, "builtin") == 0)
return 1;
if (!(e = ENGINE_by_id(name)))
goto err;
if (strcmp(name, "chil") == 0)
ENGINE_ctrl(e, ENGINE_CTRL_CHIL_SET_FORKCHECK, 1, 0, 0);
if (!ENGINE_set_default(e, ENGINE_METHOD_ALL))
goto err;
ret = 1;
err:
if (!ret) {
TSerr(TS_F_TS_CONF_SET_DEFAULT_ENGINE, TS_R_COULD_NOT_SET_ENGINE);
ERR_add_error_data(2, "engine:", name);
}
if (e)
ENGINE_free(e);
return ret;
}
int TS_CONF_set_signer_cert(CONF *conf, const char *section,
const char *cert, TS_RESP_CTX *ctx)
{
int ret = 0;
X509 *cert_obj = NULL;
if (!cert)
cert = NCONF_get_string(conf, section, ENV_SIGNER_CERT);
if (!cert) {
TS_CONF_lookup_fail(section, ENV_SIGNER_CERT);
goto err;
}
if (!(cert_obj = TS_CONF_load_cert(cert)))
goto err;
if (!TS_RESP_CTX_set_signer_cert(ctx, cert_obj))
goto err;
ret = 1;
err:
X509_free(cert_obj);
return ret;
}
int TS_CONF_set_certs(CONF *conf, const char *section, const char *certs,
TS_RESP_CTX *ctx)
{
int ret = 0;
STACK_OF(X509) *certs_obj = NULL;
if (!certs)
certs = NCONF_get_string(conf, section, ENV_CERTS);
if (!certs)
goto end;
if (!(certs_obj = TS_CONF_load_certs(certs)))
goto err;
if (!TS_RESP_CTX_set_certs(ctx, certs_obj))
goto err;
end:
ret = 1;
err:
sk_X509_pop_free(certs_obj, X509_free);
return ret;
}
int TS_CONF_set_signer_key(CONF *conf, const char *section,
const char *key, const char *pass,
TS_RESP_CTX *ctx)
{
int ret = 0;
EVP_PKEY *key_obj = NULL;
if (!key)
key = NCONF_get_string(conf, section, ENV_SIGNER_KEY);
if (!key) {
TS_CONF_lookup_fail(section, ENV_SIGNER_KEY);
goto err;
}
if (!(key_obj = TS_CONF_load_key(key, pass)))
goto err;
if (!TS_RESP_CTX_set_signer_key(ctx, key_obj))
goto err;
ret = 1;
err:
EVP_PKEY_free(key_obj);
return ret;
}
int TS_CONF_set_def_policy(CONF *conf, const char *section,
const char *policy, TS_RESP_CTX *ctx)
{
int ret = 0;
ASN1_OBJECT *policy_obj = NULL;
if (!policy)
policy = NCONF_get_string(conf, section, ENV_DEFAULT_POLICY);
if (!policy) {
TS_CONF_lookup_fail(section, ENV_DEFAULT_POLICY);
goto err;
}
if (!(policy_obj = OBJ_txt2obj(policy, 0))) {
TS_CONF_invalid(section, ENV_DEFAULT_POLICY);
goto err;
}
if (!TS_RESP_CTX_set_def_policy(ctx, policy_obj))
goto err;
ret = 1;
err:
ASN1_OBJECT_free(policy_obj);
return ret;
}
int TS_CONF_set_policies(CONF *conf, const char *section, TS_RESP_CTX *ctx)
{
int ret = 0;
int i;
STACK_OF(CONF_VALUE) *list = NULL;
char *policies = NCONF_get_string(conf, section,
ENV_OTHER_POLICIES);
if (policies && !(list = X509V3_parse_list(policies))) {
TS_CONF_invalid(section, ENV_OTHER_POLICIES);
goto err;
}
for (i = 0; i < sk_CONF_VALUE_num(list); ++i) {
CONF_VALUE *val = sk_CONF_VALUE_value(list, i);
const char *extval = val->value ? val->value : val->name;
ASN1_OBJECT *objtmp;
if (!(objtmp = OBJ_txt2obj(extval, 0))) {
TS_CONF_invalid(section, ENV_OTHER_POLICIES);
goto err;
}
if (!TS_RESP_CTX_add_policy(ctx, objtmp))
goto err;
ASN1_OBJECT_free(objtmp);
}
ret = 1;
err:
sk_CONF_VALUE_pop_free(list, X509V3_conf_free);
return ret;
}
int TS_CONF_set_digests(CONF *conf, const char *section, TS_RESP_CTX *ctx)
{
int ret = 0;
int i;
STACK_OF(CONF_VALUE) *list = NULL;
char *digests = NCONF_get_string(conf, section, ENV_DIGESTS);
if (!digests) {
TS_CONF_lookup_fail(section, ENV_DIGESTS);
goto err;
}
if (!(list = X509V3_parse_list(digests))) {
TS_CONF_invalid(section, ENV_DIGESTS);
goto err;
}
if (sk_CONF_VALUE_num(list) == 0) {
TS_CONF_invalid(section, ENV_DIGESTS);
goto err;
}
for (i = 0; i < sk_CONF_VALUE_num(list); ++i) {
CONF_VALUE *val = sk_CONF_VALUE_value(list, i);
const char *extval = val->value ? val->value : val->name;
const EVP_MD *md;
if (!(md = EVP_get_digestbyname(extval))) {
TS_CONF_invalid(section, ENV_DIGESTS);
goto err;
}
if (!TS_RESP_CTX_add_md(ctx, md))
goto err;
}
ret = 1;
err:
sk_CONF_VALUE_pop_free(list, X509V3_conf_free);
return ret;
}
int TS_CONF_set_accuracy(CONF *conf, const char *section, TS_RESP_CTX *ctx)
{
int ret = 0;
int i;
int secs = 0, millis = 0, micros = 0;
STACK_OF(CONF_VALUE) *list = NULL;
char *accuracy = NCONF_get_string(conf, section, ENV_ACCURACY);
if (accuracy && !(list = X509V3_parse_list(accuracy))) {
TS_CONF_invalid(section, ENV_ACCURACY);
goto err;
}
for (i = 0; i < sk_CONF_VALUE_num(list); ++i) {
CONF_VALUE *val = sk_CONF_VALUE_value(list, i);
if (strcmp(val->name, ENV_VALUE_SECS) == 0) {
if (val->value)
secs = atoi(val->value);
} else if (strcmp(val->name, ENV_VALUE_MILLISECS) == 0) {
if (val->value)
millis = atoi(val->value);
} else if (strcmp(val->name, ENV_VALUE_MICROSECS) == 0) {
if (val->value)
micros = atoi(val->value);
} else {
TS_CONF_invalid(section, ENV_ACCURACY);
goto err;
}
}
if (!TS_RESP_CTX_set_accuracy(ctx, secs, millis, micros))
goto err;
ret = 1;
err:
sk_CONF_VALUE_pop_free(list, X509V3_conf_free);
return ret;
}
int TS_CONF_set_clock_precision_digits(CONF *conf, const char *section,
TS_RESP_CTX *ctx)
{
int ret = 0;
long digits = 0;
if (!NCONF_get_number_e(conf, section, ENV_CLOCK_PRECISION_DIGITS,
&digits))
digits = 0;
if (digits < 0 || digits > TS_MAX_CLOCK_PRECISION_DIGITS) {
TS_CONF_invalid(section, ENV_CLOCK_PRECISION_DIGITS);
goto err;
}
if (!TS_RESP_CTX_set_clock_precision_digits(ctx, digits))
goto err;
return 1;
err:
return ret;
}
static int TS_CONF_add_flag(CONF *conf, const char *section,
const char *field, int flag, TS_RESP_CTX *ctx)
{
const char *value = NCONF_get_string(conf, section, field);
if (value) {
if (strcmp(value, ENV_VALUE_YES) == 0)
TS_RESP_CTX_add_flags(ctx, flag);
else if (strcmp(value, ENV_VALUE_NO) != 0) {
TS_CONF_invalid(section, field);
return 0;
}
}
return 1;
}
int TS_CONF_set_ordering(CONF *conf, const char *section, TS_RESP_CTX *ctx)
{
return TS_CONF_add_flag(conf, section, ENV_ORDERING, TS_ORDERING, ctx);
}
int TS_CONF_set_tsa_name(CONF *conf, const char *section, TS_RESP_CTX *ctx)
{
return TS_CONF_add_flag(conf, section, ENV_TSA_NAME, TS_TSA_NAME, ctx);
}
int TS_CONF_set_ess_cert_id_chain(CONF *conf, const char *section,
TS_RESP_CTX *ctx)
{
return TS_CONF_add_flag(conf, section, ENV_ESS_CERT_ID_CHAIN,
TS_ESS_CERT_ID_CHAIN, ctx);
}
