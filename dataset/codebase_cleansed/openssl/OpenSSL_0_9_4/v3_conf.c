X509_EXTENSION *X509V3_EXT_conf(LHASH *conf, X509V3_CTX *ctx, char *name,
char *value)
{
int crit;
int ext_type;
X509_EXTENSION *ret;
crit = v3_check_critical(&value);
if((ext_type = v3_check_generic(&value)))
return v3_generic_extension(name, value, crit, ext_type);
ret = do_ext_conf(conf, ctx, OBJ_sn2nid(name), crit, value);
if(!ret) {
X509V3err(X509V3_F_X509V3_EXT_CONF,X509V3_R_ERROR_IN_EXTENSION);
ERR_add_error_data(4,"name=", name, ", value=", value);
}
return ret;
}
X509_EXTENSION *X509V3_EXT_conf_nid(LHASH *conf, X509V3_CTX *ctx, int ext_nid,
char *value)
{
int crit;
int ext_type;
crit = v3_check_critical(&value);
if((ext_type = v3_check_generic(&value)))
return v3_generic_extension(OBJ_nid2sn(ext_nid),
value, crit, ext_type);
return do_ext_conf(conf, ctx, ext_nid, crit, value);
}
static X509_EXTENSION *do_ext_conf(LHASH *conf, X509V3_CTX *ctx, int ext_nid,
int crit, char *value)
{
X509V3_EXT_METHOD *method;
X509_EXTENSION *ext;
STACK_OF(CONF_VALUE) *nval;
void *ext_struc;
if(ext_nid == NID_undef) {
X509V3err(X509V3_F_DO_EXT_CONF,X509V3_R_UNKNOWN_EXTENSION_NAME);
return NULL;
}
if(!(method = X509V3_EXT_get_nid(ext_nid))) {
X509V3err(X509V3_F_DO_EXT_CONF,X509V3_R_UNKNOWN_EXTENSION);
return NULL;
}
if(method->v2i) {
if(*value == '@') nval = CONF_get_section(conf, value + 1);
else nval = X509V3_parse_list(value);
if(!nval) {
X509V3err(X509V3_F_X509V3_EXT_CONF,X509V3_R_INVALID_EXTENSION_STRING);
ERR_add_error_data(4, "name=", OBJ_nid2sn(ext_nid), ",section=", value);
return NULL;
}
ext_struc = method->v2i(method, ctx, nval);
if(*value != '@') sk_CONF_VALUE_pop_free(nval,
X509V3_conf_free);
if(!ext_struc) return NULL;
} else if(method->s2i) {
if(!(ext_struc = method->s2i(method, ctx, value))) return NULL;
} else if(method->r2i) {
if(!ctx->db) {
X509V3err(X509V3_F_X509V3_EXT_CONF,X509V3_R_NO_CONFIG_DATABASE);
return NULL;
}
if(!(ext_struc = method->r2i(method, ctx, value))) return NULL;
} else {
X509V3err(X509V3_F_X509V3_EXT_CONF,X509V3_R_EXTENSION_SETTING_NOT_SUPPORTED);
ERR_add_error_data(2, "name=", OBJ_nid2sn(ext_nid));
return NULL;
}
ext = do_ext_i2d(method, ext_nid, crit, ext_struc);
method->ext_free(ext_struc);
return ext;
}
static X509_EXTENSION *do_ext_i2d(X509V3_EXT_METHOD *method, int ext_nid,
int crit, void *ext_struc)
{
unsigned char *ext_der, *p;
int ext_len;
ASN1_OCTET_STRING *ext_oct;
X509_EXTENSION *ext;
ext_len = method->i2d(ext_struc, NULL);
if(!(ext_der = Malloc(ext_len))) goto merr;
p = ext_der;
method->i2d(ext_struc, &p);
if(!(ext_oct = ASN1_OCTET_STRING_new())) goto merr;
ext_oct->data = ext_der;
ext_oct->length = ext_len;
ext = X509_EXTENSION_create_by_NID(NULL, ext_nid, crit, ext_oct);
if(!ext) goto merr;
ASN1_OCTET_STRING_free(ext_oct);
return ext;
merr:
X509V3err(X509V3_F_DO_EXT_I2D,ERR_R_MALLOC_FAILURE);
return NULL;
}
X509_EXTENSION *X509V3_EXT_i2d(int ext_nid, int crit, void *ext_struc)
{
X509V3_EXT_METHOD *method;
if(!(method = X509V3_EXT_get_nid(ext_nid))) {
X509V3err(X509V3_F_X509V3_EXT_I2D,X509V3_R_UNKNOWN_EXTENSION);
return NULL;
}
return do_ext_i2d(method, ext_nid, crit, ext_struc);
}
static int v3_check_critical(char **value)
{
char *p = *value;
if((strlen(p) < 9) || strncmp(p, "critical,", 9)) return 0;
p+=9;
while(isspace((unsigned char)*p)) p++;
*value = p;
return 1;
}
static int v3_check_generic(char **value)
{
char *p = *value;
if((strlen(p) < 4) || strncmp(p, "DER:,", 4)) return 0;
p+=4;
while(isspace((unsigned char)*p)) p++;
*value = p;
return 1;
}
static X509_EXTENSION *v3_generic_extension(const char *ext, char *value,
int crit, int type)
{
unsigned char *ext_der=NULL;
long ext_len;
ASN1_OBJECT *obj=NULL;
ASN1_OCTET_STRING *oct=NULL;
X509_EXTENSION *extension=NULL;
if(!(obj = OBJ_txt2obj(ext, 0))) {
X509V3err(X509V3_F_V3_GENERIC_EXTENSION,X509V3_R_EXTENSION_NAME_ERROR);
ERR_add_error_data(2, "name=", ext);
goto err;
}
if(!(ext_der = string_to_hex(value, &ext_len))) {
X509V3err(X509V3_F_V3_GENERIC_EXTENSION,X509V3_R_EXTENSION_VALUE_ERROR);
ERR_add_error_data(2, "value=", value);
goto err;
}
if(!(oct = ASN1_OCTET_STRING_new())) {
X509V3err(X509V3_F_V3_GENERIC_EXTENSION,ERR_R_MALLOC_FAILURE);
goto err;
}
oct->data = ext_der;
oct->length = ext_len;
ext_der = NULL;
extension = X509_EXTENSION_create_by_OBJ(NULL, obj, crit, oct);
err:
ASN1_OBJECT_free(obj);
ASN1_OCTET_STRING_free(oct);
if(ext_der) Free(ext_der);
return extension;
}
int X509V3_EXT_add_conf(LHASH *conf, X509V3_CTX *ctx, char *section,
X509 *cert)
{
X509_EXTENSION *ext;
STACK_OF(CONF_VALUE) *nval;
CONF_VALUE *val;
int i;
if(!(nval = CONF_get_section(conf, section))) return 0;
for(i = 0; i < sk_CONF_VALUE_num(nval); i++) {
val = sk_CONF_VALUE_value(nval, i);
if(!(ext = X509V3_EXT_conf(conf, ctx, val->name, val->value)))
return 0;
if(cert) X509_add_ext(cert, ext, -1);
X509_EXTENSION_free(ext);
}
return 1;
}
int X509V3_EXT_CRL_add_conf(LHASH *conf, X509V3_CTX *ctx, char *section,
X509_CRL *crl)
{
X509_EXTENSION *ext;
STACK_OF(CONF_VALUE) *nval;
CONF_VALUE *val;
int i;
if(!(nval = CONF_get_section(conf, section))) return 0;
for(i = 0; i < sk_CONF_VALUE_num(nval); i++) {
val = sk_CONF_VALUE_value(nval, i);
if(!(ext = X509V3_EXT_conf(conf, ctx, val->name, val->value)))
return 0;
if(crl) X509_CRL_add_ext(crl, ext, -1);
X509_EXTENSION_free(ext);
}
return 1;
}
char * X509V3_get_string(X509V3_CTX *ctx, char *name, char *section)
{
if(ctx->db_meth->get_string)
return ctx->db_meth->get_string(ctx->db, name, section);
return NULL;
}
static char *conf_lhash_get_string(void *db, char *section, char *value)
{
return CONF_get_string(db, section, value);
}
void X509V3_set_conf_lhash(X509V3_CTX *ctx, LHASH *lhash)
{
ctx->db_meth = &conf_lhash_method;
ctx->db = lhash;
}
void X509V3_set_ctx(X509V3_CTX *ctx, X509 *issuer, X509 *subj, X509_REQ *req,
X509_CRL *crl, int flags)
{
ctx->issuer_cert = issuer;
ctx->subject_cert = subj;
ctx->crl = crl;
ctx->subject_req = req;
ctx->flags = flags;
}
