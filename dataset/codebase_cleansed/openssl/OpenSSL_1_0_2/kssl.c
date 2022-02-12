void load_krb5_dll(void)
{
HANDLE hKRB5_32;
krb5_loaded++;
hKRB5_32 = LoadLibrary(TEXT("KRB5_32"));
if (!hKRB5_32)
return;
(FARPROC) p_krb5_free_data_contents =
GetProcAddress(hKRB5_32, "krb5_free_data_contents");
(FARPROC) p_krb5_free_context =
GetProcAddress(hKRB5_32, "krb5_free_context");
(FARPROC) p_krb5_auth_con_free =
GetProcAddress(hKRB5_32, "krb5_auth_con_free");
(FARPROC) p_krb5_free_principal =
GetProcAddress(hKRB5_32, "krb5_free_principal");
(FARPROC) p_krb5_mk_req_extended =
GetProcAddress(hKRB5_32, "krb5_mk_req_extended");
(FARPROC) p_krb5_get_credentials =
GetProcAddress(hKRB5_32, "krb5_get_credentials");
(FARPROC) p_krb5_cc_get_principal =
GetProcAddress(hKRB5_32, "krb5_cc_get_principal");
(FARPROC) p_krb5_cc_default = GetProcAddress(hKRB5_32, "krb5_cc_default");
(FARPROC) p_krb5_sname_to_principal =
GetProcAddress(hKRB5_32, "krb5_sname_to_principal");
(FARPROC) p_krb5_init_context =
GetProcAddress(hKRB5_32, "krb5_init_context");
(FARPROC) p_krb5_free_ticket =
GetProcAddress(hKRB5_32, "krb5_free_ticket");
(FARPROC) p_krb5_rd_req = GetProcAddress(hKRB5_32, "krb5_rd_req");
(FARPROC) p_krb5_principal_compare =
GetProcAddress(hKRB5_32, "krb5_principal_compare");
(FARPROC) p_krb5_decrypt_tkt_part =
GetProcAddress(hKRB5_32, "krb5_decrypt_tkt_part");
(FARPROC) p_krb5_timeofday = GetProcAddress(hKRB5_32, "krb5_timeofday");
(FARPROC) p_krb5_rc_default = GetProcAddress(hKRB5_32, "krb5_rc_default");
(FARPROC) p_krb5_rc_initialize =
GetProcAddress(hKRB5_32, "krb5_rc_initialize");
(FARPROC) p_krb5_rc_get_lifespan =
GetProcAddress(hKRB5_32, "krb5_rc_get_lifespan");
(FARPROC) p_krb5_rc_destroy = GetProcAddress(hKRB5_32, "krb5_rc_destroy");
(FARPROC) p_krb5_kt_default = GetProcAddress(hKRB5_32, "krb5_kt_default");
(FARPROC) p_krb5_kt_resolve = GetProcAddress(hKRB5_32, "krb5_kt_resolve");
(FARPROC) p_krb5_auth_con_init =
GetProcAddress(hKRB5_32, "krb5_auth_con_init");
(FARPROC) p_valid_cksumtype = GetProcAddress(hKRB5_32, "valid_cksumtype");
(FARPROC) p_krb5_checksum_size =
GetProcAddress(hKRB5_32, "krb5_checksum_size");
(FARPROC) p_krb5_kt_free_entry =
GetProcAddress(hKRB5_32, "krb5_kt_free_entry");
(FARPROC) p_krb5_auth_con_setrcache =
GetProcAddress(hKRB5_32, "krb5_auth_con_setrcache");
(FARPROC) p_krb5_get_server_rcache =
GetProcAddress(hKRB5_32, "krb5_get_server_rcache");
(FARPROC) p_krb5_auth_con_getrcache =
GetProcAddress(hKRB5_32, "krb5_auth_con_getrcache");
(FARPROC) p_krb5_kt_close = GetProcAddress(hKRB5_32, "krb5_kt_close");
(FARPROC) p_krb5_kt_get_entry =
GetProcAddress(hKRB5_32, "krb5_kt_get_entry");
}
void kssl_krb5_free_data_contents(krb5_context CO, krb5_data *data)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_free_data_contents)
p_krb5_free_data_contents(CO, data);
}
krb5_error_code
kssl_krb5_mk_req_extended(krb5_context CO,
krb5_auth_context *pACO,
krb5_const krb5_flags F,
krb5_data *pD1, krb5_creds *pC, krb5_data *pD2)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_mk_req_extended)
return (p_krb5_mk_req_extended(CO, pACO, F, pD1, pC, pD2));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
kssl_krb5_auth_con_init(krb5_context CO, krb5_auth_context *pACO)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_auth_con_init)
return (p_krb5_auth_con_init(CO, pACO));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
kssl_krb5_auth_con_free(krb5_context CO, krb5_auth_context ACO)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_auth_con_free)
return (p_krb5_auth_con_free(CO, ACO));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
kssl_krb5_get_credentials(krb5_context CO,
krb5_const krb5_flags F,
krb5_ccache CC, krb5_creds *pCR, krb5_creds **ppCR)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_get_credentials)
return (p_krb5_get_credentials(CO, F, CC, pCR, ppCR));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
kssl_krb5_sname_to_principal(krb5_context CO,
krb5_const char *pC1,
krb5_const char *pC2,
krb5_int32 I, krb5_principal *pPR)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_sname_to_principal)
return (p_krb5_sname_to_principal(CO, pC1, pC2, I, pPR));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code kssl_krb5_cc_default(krb5_context CO, krb5_ccache *pCC)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_cc_default)
return (p_krb5_cc_default(CO, pCC));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code kssl_krb5_init_context(krb5_context *pCO)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_init_context)
return (p_krb5_init_context(pCO));
else
return KRB5KRB_ERR_GENERIC;
}
void kssl_krb5_free_context(krb5_context CO)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_free_context)
p_krb5_free_context(CO);
}
void kssl_krb5_free_principal(krb5_context c, krb5_principal p)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_free_principal)
p_krb5_free_principal(c, p);
}
krb5_error_code
kssl_krb5_kt_resolve(krb5_context con, krb5_const char *sz, krb5_keytab *kt)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_kt_resolve)
return (p_krb5_kt_resolve(con, sz, kt));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code kssl_krb5_kt_default(krb5_context con, krb5_keytab *kt)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_kt_default)
return (p_krb5_kt_default(con, kt));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code kssl_krb5_free_ticket(krb5_context con, krb5_ticket *kt)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_free_ticket)
return (p_krb5_free_ticket(con, kt));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
kssl_krb5_rd_req(krb5_context con, krb5_auth_context *pacon,
krb5_const krb5_data *data,
krb5_const_principal princ, krb5_keytab keytab,
krb5_flags *flags, krb5_ticket **pptkt)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_rd_req)
return (p_krb5_rd_req(con, pacon, data, princ, keytab, flags, pptkt));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_boolean
krb5_principal_compare(krb5_context con, krb5_const_principal princ1,
krb5_const_principal princ2)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_principal_compare)
return (p_krb5_principal_compare(con, princ1, princ2));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
krb5_decrypt_tkt_part(krb5_context con, krb5_const krb5_keyblock *keys,
krb5_ticket *ticket)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_decrypt_tkt_part)
return (p_krb5_decrypt_tkt_part(con, keys, ticket));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code krb5_timeofday(krb5_context con, krb5_int32 *timeret)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_timeofday)
return (p_krb5_timeofday(con, timeret));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code krb5_rc_default(krb5_context con, krb5_rcache *rc)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_rc_default)
return (p_krb5_rc_default(con, rc));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
krb5_rc_initialize(krb5_context con, krb5_rcache rc, krb5_deltat lifespan)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_rc_initialize)
return (p_krb5_rc_initialize(con, rc, lifespan));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
krb5_rc_get_lifespan(krb5_context con, krb5_rcache rc, krb5_deltat *lifespanp)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_rc_get_lifespan)
return (p_krb5_rc_get_lifespan(con, rc, lifespanp));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code krb5_rc_destroy(krb5_context con, krb5_rcache rc)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_rc_destroy)
return (p_krb5_rc_destroy(con, rc));
else
return KRB5KRB_ERR_GENERIC;
}
size_t krb5_checksum_size(krb5_context context, krb5_cksumtype ctype)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_checksum_size)
return (p_krb5_checksum_size(context, ctype));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_boolean valid_cksumtype(krb5_cksumtype ctype)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_valid_cksumtype)
return (p_valid_cksumtype(ctype));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code krb5_kt_free_entry(krb5_context con, krb5_keytab_entry *entry)
{
if (!krb5_loaded)
load_krb5_dll();
if (p_krb5_kt_free_entry)
return (p_krb5_kt_free_entry(con, entry));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
kssl_krb5_cc_get_principal
(krb5_context context, krb5_ccache cache, krb5_principal *principal) {
if (p_krb5_cc_get_principal)
return (p_krb5_cc_get_principal(context, cache, principal));
else
return (krb5_x((cache)->ops->get_princ, (context, cache, principal)));
}
krb5_error_code
kssl_krb5_auth_con_setrcache(krb5_context con, krb5_auth_context acon,
krb5_rcache rcache)
{
if (p_krb5_auth_con_setrcache)
return (p_krb5_auth_con_setrcache(con, acon, rcache));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
kssl_krb5_get_server_rcache(krb5_context con, krb5_const krb5_data *data,
krb5_rcache *rcache)
{
if (p_krb5_get_server_rcache)
return (p_krb5_get_server_rcache(con, data, rcache));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
kssl_krb5_auth_con_getrcache(krb5_context con, krb5_auth_context acon,
krb5_rcache *prcache)
{
if (p_krb5_auth_con_getrcache)
return (p_krb5_auth_con_getrcache(con, acon, prcache));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code kssl_krb5_kt_close(krb5_context context, krb5_keytab keytab)
{
if (p_krb5_kt_close)
return (p_krb5_kt_close(context, keytab));
else
return KRB5KRB_ERR_GENERIC;
}
krb5_error_code
kssl_krb5_kt_get_entry(krb5_context context, krb5_keytab keytab,
krb5_const_principal principal, krb5_kvno vno,
krb5_enctype enctype, krb5_keytab_entry *entry)
{
if (p_krb5_kt_get_entry)
return (p_krb5_kt_get_entry
(context, keytab, principal, vno, enctype, entry));
else
return KRB5KRB_ERR_GENERIC;
}
static void *kssl_calloc(size_t nmemb, size_t size)
{
void *p;
p = OPENSSL_malloc(nmemb * size);
if (p) {
memset(p, 0, nmemb * size);
}
return p;
}
char
*kstring(char *string)
{
static char *null = "[NULL]";
return ((string == NULL) ? null : string);
}
const EVP_CIPHER *kssl_map_enc(krb5_enctype enctype)
{
switch (enctype) {
case ENCTYPE_DES_HMAC_SHA1:
case ENCTYPE_DES_CBC_CRC:
case ENCTYPE_DES_CBC_MD4:
case ENCTYPE_DES_CBC_MD5:
case ENCTYPE_DES_CBC_RAW:
return EVP_des_cbc();
break;
case ENCTYPE_DES3_CBC_SHA1:
case ENCTYPE_DES3_CBC_SHA:
case ENCTYPE_DES3_CBC_RAW:
return EVP_des_ede3_cbc();
break;
default:
return NULL;
break;
}
}
static int kssl_test_confound(unsigned char *p)
{
int len = 2;
int xx = 0, yy = 0;
if (*p++ != 0x62)
return 0;
if (*p > 0x82)
return 0;
switch (*p) {
case 0x82:
p++;
xx = (*p++ << 8);
xx += *p++;
break;
case 0x81:
p++;
xx = *p++;
break;
case 0x80:
return 0;
default:
xx = *p++;
break;
}
if (*p++ != 0x30)
return 0;
if (*p > 0x82)
return 0;
switch (*p) {
case 0x82:
p++;
len += 2;
yy = (*p++ << 8);
yy += *p++;
break;
case 0x81:
p++;
len++;
yy = *p++;
break;
case 0x80:
return 0;
default:
yy = *p++;
break;
}
return (xx - len == yy) ? 1 : 0;
}
static size_t *populate_cksumlens(void)
{
int i, j, n;
static size_t *cklens = NULL;
# ifdef KRB5_MIT_OLD11
n = krb5_max_cksum;
# else
n = 0x0010;
# endif
# ifdef KRB5CHECKAUTH
if (!cklens && !(cklens = (size_t *)calloc(sizeof(int), n + 1)))
return NULL;
for (i = 0; i < n; i++) {
if (!valid_cksumtype(i))
continue;
for (j = 0; j < n; j++) {
if (cklens[j] == 0) {
cklens[j] = krb5_checksum_size(NULL, i);
break;
}
if (cklens[j] == krb5_checksum_size(NULL, i)) {
break;
}
}
}
# endif
return cklens;
}
unsigned char *kssl_skip_confound(krb5_enctype etype, unsigned char *a)
{
int i, conlen;
size_t cklen;
static size_t *cksumlens = NULL;
unsigned char *test_auth;
conlen = (etype) ? 8 : 0;
if (!cksumlens && !(cksumlens = populate_cksumlens()))
return NULL;
for (i = 0; (cklen = cksumlens[i]) != 0; i++) {
test_auth = a + conlen + cklen;
if (kssl_test_confound(test_auth))
return test_auth;
}
return NULL;
}
void kssl_err_set(KSSL_ERR *kssl_err, int reason, char *text)
{
if (kssl_err == NULL)
return;
kssl_err->reason = reason;
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX, "%s", text);
return;
}
void print_krb5_data(char *label, krb5_data *kdata)
{
int i;
fprintf(stderr, "%s[%d] ", label, kdata->length);
for (i = 0; i < (int)kdata->length; i++) {
if (0 && isprint((int)kdata->data[i]))
fprintf(stderr, "%c ", kdata->data[i]);
else
fprintf(stderr, "%02x ", (unsigned char)kdata->data[i]);
}
fprintf(stderr, "\n");
}
void print_krb5_authdata(char *label, krb5_authdata **adata)
{
if (adata == NULL) {
fprintf(stderr, "%s, authdata==0\n", label);
return;
}
fprintf(stderr, "%s [%p]\n", label, (void *)adata);
# if 0
{
int i;
fprintf(stderr, "%s[at%d:%d] ", label, adata->ad_type, adata->length);
for (i = 0; i < adata->length; i++) {
fprintf(stderr, (isprint(adata->contents[i])) ? "%c " : "%02x",
adata->contents[i]);
}
fprintf(stderr, "\n");
}
# endif
}
void print_krb5_keyblock(char *label, krb5_keyblock *keyblk)
{
int i;
if (keyblk == NULL) {
fprintf(stderr, "%s, keyblk==0\n", label);
return;
}
# ifdef KRB5_HEIMDAL
fprintf(stderr, "%s\n\t[et%d:%d]: ", label, keyblk->keytype,
keyblk->keyvalue->length);
for (i = 0; i < (int)keyblk->keyvalue->length; i++) {
fprintf(stderr, "%02x",
(unsigned char *)(keyblk->keyvalue->contents)[i]);
}
fprintf(stderr, "\n");
# else
fprintf(stderr, "%s\n\t[et%d:%d]: ", label, keyblk->enctype,
keyblk->length);
for (i = 0; i < (int)keyblk->length; i++) {
fprintf(stderr, "%02x", keyblk->contents[i]);
}
fprintf(stderr, "\n");
# endif
}
static void print_krb5_princ(char *label, krb5_principal_data *princ)
{
int i, ui, uj;
fprintf(stderr, "%s principal Realm: ", label);
if (princ == NULL)
return;
for (ui = 0; ui < (int)princ->realm.length; ui++)
putchar(princ->realm.data[ui]);
fprintf(stderr, " (nametype %d) has %d strings:\n", princ->type,
princ->length);
for (i = 0; i < (int)princ->length; i++) {
fprintf(stderr, "\t%d [%d]: ", i, princ->data[i].length);
for (uj = 0; uj < (int)princ->data[i].length; uj++) {
putchar(princ->data[i].data[uj]);
}
fprintf(stderr, "\n");
}
return;
}
krb5_error_code kssl_cget_tkt( KSSL_CTX *kssl_ctx,
krb5_data **enc_ticketp,
krb5_data *authenp,
KSSL_ERR *kssl_err)
{
krb5_error_code krb5rc = KRB5KRB_ERR_GENERIC;
krb5_context krb5context = NULL;
krb5_auth_context krb5auth_context = NULL;
krb5_ccache krb5ccdef = NULL;
krb5_creds krb5creds, *krb5credsp = NULL;
krb5_data krb5_app_req;
kssl_err_set(kssl_err, 0, "");
memset((char *)&krb5creds, 0, sizeof(krb5creds));
if (!kssl_ctx) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT, "No kssl_ctx defined.\n");
goto err;
} else if (!kssl_ctx->service_host) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"kssl_ctx service_host undefined.\n");
goto err;
}
if ((krb5rc = krb5_init_context(&krb5context)) != 0) {
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"krb5_init_context() fails: %d\n", krb5rc);
kssl_err->reason = SSL_R_KRB5_C_INIT;
goto err;
}
if ((krb5rc = krb5_sname_to_principal(krb5context,
kssl_ctx->service_host,
(kssl_ctx->service_name) ?
kssl_ctx->service_name : KRB5SVC,
KRB5_NT_SRV_HST,
&krb5creds.server)) != 0) {
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"krb5_sname_to_principal() fails for %s/%s\n",
kssl_ctx->service_host,
(kssl_ctx->
service_name) ? kssl_ctx->service_name : KRB5SVC);
kssl_err->reason = SSL_R_KRB5_C_INIT;
goto err;
}
if ((krb5rc = krb5_cc_default(krb5context, &krb5ccdef)) != 0) {
kssl_err_set(kssl_err, SSL_R_KRB5_C_CC_PRINC,
"krb5_cc_default fails.\n");
goto err;
}
if ((krb5rc = krb5_cc_get_principal(krb5context, krb5ccdef,
&krb5creds.client)) != 0) {
kssl_err_set(kssl_err, SSL_R_KRB5_C_CC_PRINC,
"krb5_cc_get_principal() fails.\n");
goto err;
}
if ((krb5rc = krb5_get_credentials(krb5context, 0, krb5ccdef,
&krb5creds, &krb5credsp)) != 0) {
kssl_err_set(kssl_err, SSL_R_KRB5_C_GET_CRED,
"krb5_get_credentials() fails.\n");
goto err;
}
*enc_ticketp = &krb5credsp->ticket;
# ifdef KRB5_HEIMDAL
kssl_ctx->enctype = krb5credsp->session.keytype;
# else
kssl_ctx->enctype = krb5credsp->keyblock.enctype;
# endif
krb5rc = KRB5KRB_ERR_GENERIC;
krb5_app_req.length = 0;
if (authenp) {
krb5_data krb5in_data;
const unsigned char *p;
long arlen;
KRB5_APREQBODY *ap_req;
authenp->length = 0;
krb5in_data.data = NULL;
krb5in_data.length = 0;
if ((krb5rc = krb5_mk_req_extended(krb5context,
&krb5auth_context, 0, &krb5in_data,
krb5credsp, &krb5_app_req)) != 0) {
kssl_err_set(kssl_err, SSL_R_KRB5_C_MK_REQ,
"krb5_mk_req_extended() fails.\n");
goto err;
}
arlen = krb5_app_req.length;
p = (unsigned char *)krb5_app_req.data;
ap_req = (KRB5_APREQBODY *)d2i_KRB5_APREQ(NULL, &p, arlen);
if (ap_req) {
authenp->length = i2d_KRB5_ENCDATA(ap_req->authenticator, NULL);
if (authenp->length && (authenp->data = malloc(authenp->length))) {
unsigned char *adp = (unsigned char *)authenp->data;
authenp->length =
i2d_KRB5_ENCDATA(ap_req->authenticator, &adp);
}
}
if (ap_req)
KRB5_APREQ_free((KRB5_APREQ *) ap_req);
if (krb5_app_req.length)
kssl_krb5_free_data_contents(krb5context, &krb5_app_req);
}
# ifdef KRB5_HEIMDAL
if (kssl_ctx_setkey(kssl_ctx, &krb5credsp->session)) {
kssl_err_set(kssl_err, SSL_R_KRB5_C_INIT,
"kssl_ctx_setkey() fails.\n");
}
# else
if (kssl_ctx_setkey(kssl_ctx, &krb5credsp->keyblock)) {
kssl_err_set(kssl_err, SSL_R_KRB5_C_INIT,
"kssl_ctx_setkey() fails.\n");
}
# endif
else
krb5rc = 0;
err:
# ifdef KSSL_DEBUG
kssl_ctx_show(kssl_ctx);
# endif
if (krb5creds.client)
krb5_free_principal(krb5context, krb5creds.client);
if (krb5creds.server)
krb5_free_principal(krb5context, krb5creds.server);
if (krb5auth_context)
krb5_auth_con_free(krb5context, krb5auth_context);
if (krb5context)
krb5_free_context(krb5context);
return (krb5rc);
}
static krb5_error_code kssl_TKT2tkt( krb5_context krb5context,
KRB5_TKTBODY *asn1ticket,
krb5_ticket **krb5ticket,
KSSL_ERR *kssl_err)
{
krb5_error_code krb5rc = KRB5KRB_ERR_GENERIC;
krb5_ticket *new5ticket = NULL;
ASN1_GENERALSTRING *gstr_svc, *gstr_host;
*krb5ticket = NULL;
if (asn1ticket == NULL || asn1ticket->realm == NULL ||
asn1ticket->sname == NULL ||
sk_ASN1_GENERALSTRING_num(asn1ticket->sname->namestring) < 2) {
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"Null field in asn1ticket.\n");
kssl_err->reason = SSL_R_KRB5_S_RD_REQ;
return KRB5KRB_ERR_GENERIC;
}
if ((new5ticket = (krb5_ticket *)calloc(1, sizeof(krb5_ticket))) == NULL) {
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"Unable to allocate new krb5_ticket.\n");
kssl_err->reason = SSL_R_KRB5_S_RD_REQ;
return ENOMEM;
}
gstr_svc = sk_ASN1_GENERALSTRING_value(asn1ticket->sname->namestring, 0);
gstr_host = sk_ASN1_GENERALSTRING_value(asn1ticket->sname->namestring, 1);
if ((krb5rc = kssl_build_principal_2(krb5context,
&new5ticket->server,
asn1ticket->realm->length,
(char *)asn1ticket->realm->data,
gstr_svc->length,
(char *)gstr_svc->data,
gstr_host->length,
(char *)gstr_host->data)) != 0) {
free(new5ticket);
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"Error building ticket server principal.\n");
kssl_err->reason = SSL_R_KRB5_S_RD_REQ;
return krb5rc;
}
krb5_princ_type(krb5context, new5ticket->server) =
asn1ticket->sname->nametype->data[0];
new5ticket->enc_part.enctype = asn1ticket->encdata->etype->data[0];
new5ticket->enc_part.kvno = asn1ticket->encdata->kvno->data[0];
new5ticket->enc_part.ciphertext.length =
asn1ticket->encdata->cipher->length;
if ((new5ticket->enc_part.ciphertext.data =
calloc(1, asn1ticket->encdata->cipher->length)) == NULL) {
free(new5ticket);
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"Error allocating cipher in krb5ticket.\n");
kssl_err->reason = SSL_R_KRB5_S_RD_REQ;
return KRB5KRB_ERR_GENERIC;
} else {
memcpy(new5ticket->enc_part.ciphertext.data,
asn1ticket->encdata->cipher->data,
asn1ticket->encdata->cipher->length);
}
*krb5ticket = new5ticket;
return 0;
}
krb5_error_code kssl_sget_tkt( KSSL_CTX *kssl_ctx,
krb5_data *indata,
krb5_ticket_times *ttimes,
KSSL_ERR *kssl_err)
{
krb5_error_code krb5rc = KRB5KRB_ERR_GENERIC;
static krb5_context krb5context = NULL;
static krb5_auth_context krb5auth_context = NULL;
krb5_ticket *krb5ticket = NULL;
KRB5_TKTBODY *asn1ticket = NULL;
const unsigned char *p;
krb5_keytab krb5keytab = NULL;
krb5_keytab_entry kt_entry;
krb5_principal krb5server;
krb5_rcache rcache = NULL;
kssl_err_set(kssl_err, 0, "");
if (!kssl_ctx) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT, "No kssl_ctx defined.\n");
goto err;
}
# ifdef KSSL_DEBUG
fprintf(stderr, "in kssl_sget_tkt(%s)\n",
kstring(kssl_ctx->service_name));
# endif
if (!krb5context && (krb5rc = krb5_init_context(&krb5context))) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"krb5_init_context() fails.\n");
goto err;
}
if (krb5auth_context &&
(krb5rc = krb5_auth_con_free(krb5context, krb5auth_context))) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"krb5_auth_con_free() fails.\n");
goto err;
} else
krb5auth_context = NULL;
if (!krb5auth_context &&
(krb5rc = krb5_auth_con_init(krb5context, &krb5auth_context))) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"krb5_auth_con_init() fails.\n");
goto err;
}
if ((krb5rc = krb5_auth_con_getrcache(krb5context, krb5auth_context,
&rcache))) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"krb5_auth_con_getrcache() fails.\n");
goto err;
}
if ((krb5rc = krb5_sname_to_principal(krb5context, NULL,
(kssl_ctx->service_name) ?
kssl_ctx->service_name : KRB5SVC,
KRB5_NT_SRV_HST,
&krb5server)) != 0) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"krb5_sname_to_principal() fails.\n");
goto err;
}
if (rcache == NULL) {
if ((krb5rc = krb5_get_server_rcache(krb5context,
krb5_princ_component(krb5context,
krb5server,
0),
&rcache))) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"krb5_get_server_rcache() fails.\n");
goto err;
}
}
if ((krb5rc =
krb5_auth_con_setrcache(krb5context, krb5auth_context, rcache))) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"krb5_auth_con_setrcache() fails.\n");
goto err;
}
if (kssl_ctx->keytab_file) {
krb5rc = krb5_kt_resolve(krb5context, kssl_ctx->keytab_file,
&krb5keytab);
if (krb5rc) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"krb5_kt_resolve() fails.\n");
goto err;
}
} else {
krb5rc = krb5_kt_default(krb5context, &krb5keytab);
if (krb5rc) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"krb5_kt_default() fails.\n");
goto err;
}
}
p = (unsigned char *)indata->data;
if ((asn1ticket = (KRB5_TKTBODY *)d2i_KRB5_TICKET(NULL, &p,
(long)indata->length))
== NULL) {
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"d2i_KRB5_TICKET() ASN.1 decode failure.\n");
kssl_err->reason = SSL_R_KRB5_S_RD_REQ;
goto err;
}
if ((krb5rc = kssl_TKT2tkt(krb5context, asn1ticket, &krb5ticket,
kssl_err)) != 0) {
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"Error converting ASN.1 ticket to krb5_ticket.\n");
kssl_err->reason = SSL_R_KRB5_S_RD_REQ;
goto err;
}
if (!krb5_principal_compare(krb5context, krb5server, krb5ticket->server)) {
krb5rc = KRB5_PRINC_NOMATCH;
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"server principal != ticket principal\n");
kssl_err->reason = SSL_R_KRB5_S_RD_REQ;
goto err;
}
if ((krb5rc = krb5_kt_get_entry(krb5context, krb5keytab,
krb5ticket->server,
krb5ticket->enc_part.kvno,
krb5ticket->enc_part.enctype,
&kt_entry)) != 0) {
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"krb5_kt_get_entry() fails with %x.\n", krb5rc);
kssl_err->reason = SSL_R_KRB5_S_RD_REQ;
goto err;
}
if ((krb5rc = krb5_decrypt_tkt_part(krb5context, &kt_entry.key,
krb5ticket)) != 0) {
BIO_snprintf(kssl_err->text, KSSL_ERR_MAX,
"krb5_decrypt_tkt_part() failed.\n");
kssl_err->reason = SSL_R_KRB5_S_RD_REQ;
goto err;
} else {
krb5_kt_free_entry(krb5context, &kt_entry);
# ifdef KSSL_DEBUG
{
int i;
krb5_address **paddr = krb5ticket->enc_part2->caddrs;
fprintf(stderr, "Decrypted ticket fields:\n");
fprintf(stderr, "\tflags: %X, transit-type: %X",
krb5ticket->enc_part2->flags,
krb5ticket->enc_part2->transited.tr_type);
print_krb5_data("\ttransit-data: ",
&(krb5ticket->enc_part2->transited.tr_contents));
fprintf(stderr, "\tcaddrs: %p, authdata: %p\n",
krb5ticket->enc_part2->caddrs,
krb5ticket->enc_part2->authorization_data);
if (paddr) {
fprintf(stderr, "\tcaddrs:\n");
for (i = 0; paddr[i] != NULL; i++) {
krb5_data d;
d.length = paddr[i]->length;
d.data = paddr[i]->contents;
print_krb5_data("\t\tIP: ", &d);
}
}
fprintf(stderr, "\tstart/auth/end times: %d / %d / %d\n",
krb5ticket->enc_part2->times.starttime,
krb5ticket->enc_part2->times.authtime,
krb5ticket->enc_part2->times.endtime);
}
# endif
}
krb5rc = KRB5_NO_TKT_SUPPLIED;
if (!krb5ticket || !krb5ticket->enc_part2 ||
!krb5ticket->enc_part2->client ||
!krb5ticket->enc_part2->client->data ||
!krb5ticket->enc_part2->session) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_BAD_TICKET,
"bad ticket from krb5_rd_req.\n");
} else if (kssl_ctx_setprinc(kssl_ctx, KSSL_CLIENT,
&krb5ticket->enc_part2->client->realm,
krb5ticket->enc_part2->client->data,
krb5ticket->enc_part2->client->length)) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_BAD_TICKET,
"kssl_ctx_setprinc() fails.\n");
} else if (kssl_ctx_setkey(kssl_ctx, krb5ticket->enc_part2->session)) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_BAD_TICKET,
"kssl_ctx_setkey() fails.\n");
} else if (krb5ticket->enc_part2->flags & TKT_FLG_INVALID) {
krb5rc = KRB5KRB_AP_ERR_TKT_INVALID;
kssl_err_set(kssl_err, SSL_R_KRB5_S_BAD_TICKET,
"invalid ticket from krb5_rd_req.\n");
} else
krb5rc = 0;
kssl_ctx->enctype = krb5ticket->enc_part.enctype;
ttimes->authtime = krb5ticket->enc_part2->times.authtime;
ttimes->starttime = krb5ticket->enc_part2->times.starttime;
ttimes->endtime = krb5ticket->enc_part2->times.endtime;
ttimes->renew_till = krb5ticket->enc_part2->times.renew_till;
err:
# ifdef KSSL_DEBUG
kssl_ctx_show(kssl_ctx);
# endif
if (asn1ticket)
KRB5_TICKET_free((KRB5_TICKET *) asn1ticket);
if (krb5keytab)
krb5_kt_close(krb5context, krb5keytab);
if (krb5ticket)
krb5_free_ticket(krb5context, krb5ticket);
if (krb5server)
krb5_free_principal(krb5context, krb5server);
return (krb5rc);
}
KSSL_CTX *kssl_ctx_new(void)
{
return ((KSSL_CTX *)kssl_calloc(1, sizeof(KSSL_CTX)));
}
KSSL_CTX *kssl_ctx_free(KSSL_CTX *kssl_ctx)
{
if (kssl_ctx == NULL)
return kssl_ctx;
if (kssl_ctx->key)
OPENSSL_cleanse(kssl_ctx->key, kssl_ctx->length);
if (kssl_ctx->key)
kssl_free(kssl_ctx->key);
if (kssl_ctx->client_princ)
kssl_free(kssl_ctx->client_princ);
if (kssl_ctx->service_host)
kssl_free(kssl_ctx->service_host);
if (kssl_ctx->service_name)
kssl_free(kssl_ctx->service_name);
if (kssl_ctx->keytab_file)
kssl_free(kssl_ctx->keytab_file);
kssl_free(kssl_ctx);
return (KSSL_CTX *)NULL;
}
krb5_error_code
kssl_ctx_setprinc(KSSL_CTX *kssl_ctx, int which,
krb5_data *realm, krb5_data *entity, int nentities)
{
char **princ;
int length;
int i;
if (kssl_ctx == NULL || entity == NULL)
return KSSL_CTX_ERR;
switch (which) {
case KSSL_CLIENT:
princ = &kssl_ctx->client_princ;
break;
case KSSL_SERVER:
princ = &kssl_ctx->service_host;
break;
default:
return KSSL_CTX_ERR;
break;
}
if (*princ)
kssl_free(*princ);
length = 0;
for (i = 0; i < nentities; i++) {
length += entity[i].length;
}
length += nentities - 1;
length += ((realm) ? realm->length + 2 : 1);
if ((*princ = kssl_calloc(1, length)) == NULL)
return KSSL_CTX_ERR;
else {
for (i = 0; i < nentities; i++) {
strncat(*princ, entity[i].data, entity[i].length);
if (i < nentities - 1) {
strcat(*princ, "/");
}
}
if (realm) {
strcat(*princ, "@");
(void)strncat(*princ, realm->data, realm->length);
}
}
return KSSL_CTX_OK;
}
krb5_error_code kssl_ctx_setstring(KSSL_CTX *kssl_ctx, int which, char *text)
{
char **string;
if (!kssl_ctx)
return KSSL_CTX_ERR;
switch (which) {
case KSSL_SERVICE:
string = &kssl_ctx->service_name;
break;
case KSSL_SERVER:
string = &kssl_ctx->service_host;
break;
case KSSL_CLIENT:
string = &kssl_ctx->client_princ;
break;
case KSSL_KEYTAB:
string = &kssl_ctx->keytab_file;
break;
default:
return KSSL_CTX_ERR;
break;
}
if (*string)
kssl_free(*string);
if (!text) {
*string = '\0';
return KSSL_CTX_OK;
}
if ((*string = kssl_calloc(1, strlen(text) + 1)) == NULL)
return KSSL_CTX_ERR;
else
strcpy(*string, text);
return KSSL_CTX_OK;
}
krb5_error_code kssl_ctx_setkey(KSSL_CTX *kssl_ctx, krb5_keyblock *session)
{
int length;
krb5_enctype enctype;
krb5_octet FAR *contents = NULL;
if (!kssl_ctx)
return KSSL_CTX_ERR;
if (kssl_ctx->key) {
OPENSSL_cleanse(kssl_ctx->key, kssl_ctx->length);
kssl_free(kssl_ctx->key);
}
if (session) {
# ifdef KRB5_HEIMDAL
length = session->keyvalue->length;
enctype = session->keytype;
contents = session->keyvalue->contents;
# else
length = session->length;
enctype = session->enctype;
contents = session->contents;
# endif
kssl_ctx->enctype = enctype;
kssl_ctx->length = length;
} else {
kssl_ctx->enctype = ENCTYPE_UNKNOWN;
kssl_ctx->length = 0;
return KSSL_CTX_OK;
}
if ((kssl_ctx->key =
(krb5_octet FAR *)kssl_calloc(1, kssl_ctx->length)) == NULL) {
kssl_ctx->length = 0;
return KSSL_CTX_ERR;
} else
memcpy(kssl_ctx->key, contents, length);
return KSSL_CTX_OK;
}
void kssl_ctx_show(KSSL_CTX *kssl_ctx)
{
int i;
printf("kssl_ctx: ");
if (kssl_ctx == NULL) {
printf("NULL\n");
return;
} else
printf("%p\n", (void *)kssl_ctx);
printf("\tservice:\t%s\n",
(kssl_ctx->service_name) ? kssl_ctx->service_name : "NULL");
printf("\tclient:\t%s\n",
(kssl_ctx->client_princ) ? kssl_ctx->client_princ : "NULL");
printf("\tserver:\t%s\n",
(kssl_ctx->service_host) ? kssl_ctx->service_host : "NULL");
printf("\tkeytab:\t%s\n",
(kssl_ctx->keytab_file) ? kssl_ctx->keytab_file : "NULL");
printf("\tkey [%d:%d]:\t", kssl_ctx->enctype, kssl_ctx->length);
for (i = 0; i < kssl_ctx->length && kssl_ctx->key; i++) {
printf("%02x", kssl_ctx->key[i]);
}
printf("\n");
return;
}
int kssl_keytab_is_available(KSSL_CTX *kssl_ctx)
{
krb5_context krb5context = NULL;
krb5_keytab krb5keytab = NULL;
krb5_keytab_entry entry;
krb5_principal princ = NULL;
krb5_error_code krb5rc = KRB5KRB_ERR_GENERIC;
int rc = 0;
if ((krb5rc = krb5_init_context(&krb5context)))
return (0);
if (kssl_ctx->keytab_file) {
krb5rc = krb5_kt_resolve(krb5context, kssl_ctx->keytab_file,
&krb5keytab);
if (krb5rc)
goto exit;
} else {
krb5rc = krb5_kt_default(krb5context, &krb5keytab);
if (krb5rc)
goto exit;
}
krb5rc = krb5_sname_to_principal(krb5context, NULL,
kssl_ctx->
service_name ? kssl_ctx->service_name :
KRB5SVC, KRB5_NT_SRV_HST, &princ);
if (krb5rc)
goto exit;
krb5rc = krb5_kt_get_entry(krb5context, krb5keytab, princ,
0,
0, &entry);
if (krb5rc == KRB5_KT_NOTFOUND) {
rc = 1;
goto exit;
} else if (krb5rc)
goto exit;
krb5_kt_free_entry(krb5context, &entry);
rc = 1;
exit:
if (krb5keytab)
krb5_kt_close(krb5context, krb5keytab);
if (princ)
krb5_free_principal(krb5context, princ);
if (krb5context)
krb5_free_context(krb5context);
return (rc);
}
int kssl_tgt_is_available(KSSL_CTX *kssl_ctx)
{
krb5_error_code krb5rc = KRB5KRB_ERR_GENERIC;
krb5_context krb5context = NULL;
krb5_ccache krb5ccdef = NULL;
krb5_creds krb5creds, *krb5credsp = NULL;
int rc = 0;
memset((char *)&krb5creds, 0, sizeof(krb5creds));
if (!kssl_ctx)
return (0);
if (!kssl_ctx->service_host)
return (0);
if ((krb5rc = krb5_init_context(&krb5context)) != 0)
goto err;
if ((krb5rc = krb5_sname_to_principal(krb5context,
kssl_ctx->service_host,
(kssl_ctx->service_name) ?
kssl_ctx->service_name : KRB5SVC,
KRB5_NT_SRV_HST,
&krb5creds.server)) != 0)
goto err;
if ((krb5rc = krb5_cc_default(krb5context, &krb5ccdef)) != 0)
goto err;
if ((krb5rc = krb5_cc_get_principal(krb5context, krb5ccdef,
&krb5creds.client)) != 0)
goto err;
if ((krb5rc = krb5_get_credentials(krb5context, 0, krb5ccdef,
&krb5creds, &krb5credsp)) != 0)
goto err;
rc = 1;
err:
# ifdef KSSL_DEBUG
kssl_ctx_show(kssl_ctx);
# endif
if (krb5creds.client)
krb5_free_principal(krb5context, krb5creds.client);
if (krb5creds.server)
krb5_free_principal(krb5context, krb5creds.server);
if (krb5context)
krb5_free_context(krb5context);
return (rc);
}
void kssl_krb5_free_data_contents(krb5_context context, krb5_data *data)
{
# ifdef KRB5_HEIMDAL
data->length = 0;
if (data->data)
free(data->data);
# elif defined(KRB5_MIT_OLD11)
if (data->data) {
krb5_xfree(data->data);
data->data = 0;
}
# else
krb5_free_data_contents(NULL, data);
# endif
}
static struct tm *k_gmtime(ASN1_GENERALIZEDTIME *gtime, struct tm *k_tm)
{
char c, *p;
if (!k_tm)
return NULL;
if (gtime == NULL || gtime->length < 14)
return NULL;
if (gtime->data == NULL)
return NULL;
p = (char *)&gtime->data[14];
c = *p;
*p = '\0';
p -= 2;
k_tm->tm_sec = atoi(p);
*(p + 2) = c;
c = *p;
*p = '\0';
p -= 2;
k_tm->tm_min = atoi(p);
*(p + 2) = c;
c = *p;
*p = '\0';
p -= 2;
k_tm->tm_hour = atoi(p);
*(p + 2) = c;
c = *p;
*p = '\0';
p -= 2;
k_tm->tm_mday = atoi(p);
*(p + 2) = c;
c = *p;
*p = '\0';
p -= 2;
k_tm->tm_mon = atoi(p) - 1;
*(p + 2) = c;
c = *p;
*p = '\0';
p -= 4;
k_tm->tm_year = atoi(p) - 1900;
*(p + 4) = c;
return k_tm;
}
static krb5_deltat get_rc_clockskew(krb5_context context)
{
krb5_rcache rc;
krb5_deltat clockskew;
if (krb5_rc_default(context, &rc))
return KSSL_CLOCKSKEW;
if (krb5_rc_initialize(context, rc, 0))
return KSSL_CLOCKSKEW;
if (krb5_rc_get_lifespan(context, rc, &clockskew)) {
clockskew = KSSL_CLOCKSKEW;
}
(void)krb5_rc_destroy(context, rc);
return clockskew;
}
krb5_error_code kssl_validate_times(krb5_timestamp atime,
krb5_ticket_times *ttimes)
{
krb5_deltat skew;
krb5_timestamp start, now;
krb5_error_code rc;
krb5_context context;
if ((rc = krb5_init_context(&context)))
return SSL_R_KRB5_S_BAD_TICKET;
skew = get_rc_clockskew(context);
if ((rc = krb5_timeofday(context, &now)))
return SSL_R_KRB5_S_BAD_TICKET;
krb5_free_context(context);
if (atime && labs(atime - now) >= skew)
return SSL_R_KRB5_S_TKT_SKEW;
if (!ttimes)
return 0;
start = (ttimes->starttime != 0) ? ttimes->starttime : ttimes->authtime;
if (start - now > skew)
return SSL_R_KRB5_S_TKT_NYV;
if ((now - ttimes->endtime) > skew)
return SSL_R_KRB5_S_TKT_EXPIRED;
# ifdef KSSL_DEBUG
fprintf(stderr, "kssl_validate_times: %d |<- | %d - %d | < %d ->| %d\n",
start, atime, now, skew, ttimes->endtime);
# endif
return 0;
}
krb5_error_code kssl_check_authent(
KSSL_CTX *kssl_ctx,
krb5_data *authentp,
krb5_timestamp *atimep,
KSSL_ERR *kssl_err)
{
krb5_error_code krb5rc = 0;
KRB5_ENCDATA *dec_authent = NULL;
KRB5_AUTHENTBODY *auth = NULL;
krb5_enctype enctype;
EVP_CIPHER_CTX ciph_ctx;
const EVP_CIPHER *enc = NULL;
unsigned char iv[EVP_MAX_IV_LENGTH];
const unsigned char *p;
unsigned char *unenc_authent;
int outl, unencbufsize;
struct tm tm_time, *tm_l, *tm_g;
time_t now, tl, tg, tr, tz_offset;
EVP_CIPHER_CTX_init(&ciph_ctx);
*atimep = 0;
kssl_err_set(kssl_err, 0, "");
# ifndef KRB5CHECKAUTH
authentp = NULL;
# else
# if KRB5CHECKAUTH == 0
authentp = NULL;
# endif
# endif
if (authentp == NULL || authentp->length == 0)
return 0;
# ifdef KSSL_DEBUG
{
unsigned int ui;
fprintf(stderr, "kssl_check_authent: authenticator[%d]:\n",
authentp->length);
p = authentp->data;
for (ui = 0; ui < authentp->length; ui++)
fprintf(stderr, "%02x ", p[ui]);
fprintf(stderr, "\n");
}
# endif
unencbufsize = 2 * authentp->length;
if ((unenc_authent = calloc(1, unencbufsize)) == NULL) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"Unable to allocate authenticator buffer.\n");
krb5rc = KRB5KRB_ERR_GENERIC;
goto err;
}
p = (unsigned char *)authentp->data;
if ((dec_authent = d2i_KRB5_ENCDATA(NULL, &p,
(long)authentp->length)) == NULL) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"Error decoding authenticator.\n");
krb5rc = KRB5KRB_AP_ERR_BAD_INTEGRITY;
goto err;
}
enctype = dec_authent->etype->data[0];
# if !defined(KRB5_MIT_OLD11)
switch (enctype) {
case ENCTYPE_DES3_CBC_SHA1:
case ENCTYPE_DES3_CBC_SHA:
case ENCTYPE_DES3_CBC_RAW:
krb5rc = 0;
goto err;
}
# endif
enc = kssl_map_enc(enctype);
memset(iv, 0, sizeof iv);
if (enc == NULL) {
goto err;
}
if (!EVP_CipherInit(&ciph_ctx, enc, kssl_ctx->key, iv, 0)) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"EVP_CipherInit error decrypting authenticator.\n");
krb5rc = KRB5KRB_AP_ERR_BAD_INTEGRITY;
goto err;
}
outl = dec_authent->cipher->length;
if (!EVP_Cipher
(&ciph_ctx, unenc_authent, dec_authent->cipher->data, outl)) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"EVP_Cipher error decrypting authenticator.\n");
krb5rc = KRB5KRB_AP_ERR_BAD_INTEGRITY;
goto err;
}
EVP_CIPHER_CTX_cleanup(&ciph_ctx);
# ifdef KSSL_DEBUG
{
int padl;
fprintf(stderr, "kssl_check_authent: decrypted authenticator[%d] =\n",
outl);
for (padl = 0; padl < outl; padl++)
fprintf(stderr, "%02x ", unenc_authent[padl]);
fprintf(stderr, "\n");
}
# endif
if ((p = kssl_skip_confound(enctype, unenc_authent)) == NULL) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"confounded by authenticator.\n");
krb5rc = KRB5KRB_AP_ERR_BAD_INTEGRITY;
goto err;
}
outl -= p - unenc_authent;
if ((auth = (KRB5_AUTHENTBODY *)d2i_KRB5_AUTHENT(NULL, &p,
(long)outl)) == NULL) {
kssl_err_set(kssl_err, SSL_R_KRB5_S_INIT,
"Error decoding authenticator body.\n");
krb5rc = KRB5KRB_AP_ERR_BAD_INTEGRITY;
goto err;
}
memset(&tm_time, 0, sizeof(struct tm));
if (k_gmtime(auth->ctime, &tm_time) &&
((tr = mktime(&tm_time)) != (time_t)(-1))) {
now = time(&now);
tm_l = localtime(&now);
tl = mktime(tm_l);
tm_g = gmtime(&now);
tg = mktime(tm_g);
tz_offset = tg - tl;
*atimep = (krb5_timestamp)(tr - tz_offset);
}
# ifdef KSSL_DEBUG
fprintf(stderr, "kssl_check_authent: returns %d for client time ",
*atimep);
if (auth && auth->ctime && auth->ctime->length && auth->ctime->data)
fprintf(stderr, "%.*s\n", auth->ctime->length, auth->ctime->data);
else
fprintf(stderr, "NULL\n");
# endif
err:
if (auth)
KRB5_AUTHENT_free((KRB5_AUTHENT *) auth);
if (dec_authent)
KRB5_ENCDATA_free(dec_authent);
if (unenc_authent)
free(unenc_authent);
EVP_CIPHER_CTX_cleanup(&ciph_ctx);
return krb5rc;
}
krb5_error_code kssl_build_principal_2(
krb5_context context,
krb5_principal *princ,
int rlen, const char *realm,
int slen, const char *svc,
int hlen, const char *host)
{
krb5_data *p_data = NULL;
krb5_principal new_p = NULL;
char *new_r = NULL;
if ((p_data = (krb5_data *)calloc(2, sizeof(krb5_data))) == NULL ||
(new_p = (krb5_principal)calloc(1, sizeof(krb5_principal_data)))
== NULL)
goto err;
new_p->length = 2;
new_p->data = p_data;
if ((new_r = calloc(1, rlen + 1)) == NULL)
goto err;
memcpy(new_r, realm, rlen);
krb5_princ_set_realm_length(context, new_p, rlen);
krb5_princ_set_realm_data(context, new_p, new_r);
if ((new_p->data[0].data = calloc(1, slen + 1)) == NULL)
goto err;
memcpy(new_p->data[0].data, svc, slen);
new_p->data[0].length = slen;
if ((new_p->data[1].data = calloc(1, hlen + 1)) == NULL)
goto err;
memcpy(new_p->data[1].data, host, hlen);
new_p->data[1].length = hlen;
krb5_princ_type(context, new_p) = KRB5_NT_UNKNOWN;
*princ = new_p;
return 0;
err:
if (new_p && new_p[0].data)
free(new_p[0].data);
if (new_p && new_p[1].data)
free(new_p[1].data);
if (new_p)
free(new_p);
if (new_r)
free(new_r);
return ENOMEM;
}
void SSL_set0_kssl_ctx(SSL *s, KSSL_CTX *kctx)
{
s->kssl_ctx = kctx;
}
KSSL_CTX *SSL_get0_kssl_ctx(SSL *s)
{
return s->kssl_ctx;
}
char *kssl_ctx_get0_client_princ(KSSL_CTX *kctx)
{
if (kctx)
return kctx->client_princ;
return NULL;
}
