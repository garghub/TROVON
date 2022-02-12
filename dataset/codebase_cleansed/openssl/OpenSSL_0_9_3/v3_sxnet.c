int i2d_SXNET(SXNET *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->version, i2d_ASN1_INTEGER);
M_ASN1_I2D_len_SEQUENCE_type (SXNETID, a->ids, i2d_SXNETID);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put (a->version, i2d_ASN1_INTEGER);
M_ASN1_I2D_put_SEQUENCE_type (SXNETID, a->ids, i2d_SXNETID);
M_ASN1_I2D_finish();
}
SXNET *SXNET_new(void)
{
SXNET *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, SXNET);
M_ASN1_New(ret->version,ASN1_INTEGER_new);
M_ASN1_New(ret->ids,sk_SXNETID_new_null);
return (ret);
M_ASN1_New_Error(ASN1_F_SXNET_NEW);
}
SXNET *d2i_SXNET(SXNET **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,SXNET *,SXNET_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get (ret->version, d2i_ASN1_INTEGER);
M_ASN1_D2I_get_seq_type (SXNETID, ret->ids, d2i_SXNETID, SXNETID_free);
M_ASN1_D2I_Finish(a, SXNET_free, ASN1_F_D2I_SXNET);
}
void SXNET_free(SXNET *a)
{
if (a == NULL) return;
ASN1_INTEGER_free(a->version);
sk_SXNETID_pop_free(a->ids, SXNETID_free);
Free (a);
}
int i2d_SXNETID(SXNETID *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->zone, i2d_ASN1_INTEGER);
M_ASN1_I2D_len (a->user, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put (a->zone, i2d_ASN1_INTEGER);
M_ASN1_I2D_put (a->user, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_finish();
}
SXNETID *SXNETID_new(void)
{
SXNETID *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, SXNETID);
ret->zone = NULL;
M_ASN1_New(ret->user,ASN1_OCTET_STRING_new);
return (ret);
M_ASN1_New_Error(ASN1_F_SXNETID_NEW);
}
SXNETID *d2i_SXNETID(SXNETID **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,SXNETID *,SXNETID_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->zone, d2i_ASN1_INTEGER);
M_ASN1_D2I_get(ret->user, d2i_ASN1_OCTET_STRING);
M_ASN1_D2I_Finish(a, SXNETID_free, ASN1_F_D2I_SXNETID);
}
void SXNETID_free(SXNETID *a)
{
if (a == NULL) return;
ASN1_INTEGER_free(a->zone);
ASN1_OCTET_STRING_free(a->user);
Free (a);
}
static int sxnet_i2r(X509V3_EXT_METHOD *method, SXNET *sx, BIO *out,
int indent)
{
long v;
char *tmp;
SXNETID *id;
int i;
v = ASN1_INTEGER_get(sx->version);
BIO_printf(out, "%*sVersion: %d (0x%X)", indent, "", v + 1, v);
for(i = 0; i < sk_SXNETID_num(sx->ids); i++) {
id = sk_SXNETID_value(sx->ids, i);
tmp = i2s_ASN1_INTEGER(NULL, id->zone);
BIO_printf(out, "\n%*sZone: %s, User: ", indent, "", tmp);
Free(tmp);
ASN1_OCTET_STRING_print(out, id->user);
}
return 1;
}
static SXNET * sxnet_v2i(X509V3_EXT_METHOD *method, X509V3_CTX *ctx,
STACK *nval)
{
CONF_VALUE *cnf;
SXNET *sx = NULL;
int i;
for(i = 0; i < sk_num(nval); i++) {
cnf = (CONF_VALUE *)sk_value(nval, i);
if(!SXNET_add_id_asc(&sx, cnf->name, cnf->value, -1))
return NULL;
}
return sx;
}
int SXNET_add_id_asc(SXNET **psx, char *zone, char *user,
int userlen)
{
ASN1_INTEGER *izone = NULL;
if(!(izone = s2i_ASN1_INTEGER(NULL, zone))) {
X509V3err(X509V3_F_SXNET_ADD_ASC,X509V3_R_ERROR_CONVERTING_ZONE);
return 0;
}
return SXNET_add_id_INTEGER(psx, izone, user, userlen);
}
int SXNET_add_id_ulong(SXNET **psx, unsigned long lzone, char *user,
int userlen)
{
ASN1_INTEGER *izone = NULL;
if(!(izone = ASN1_INTEGER_new()) || !ASN1_INTEGER_set(izone, lzone)) {
X509V3err(X509V3_F_SXNET_ADD_ID_ULONG,ERR_R_MALLOC_FAILURE);
ASN1_INTEGER_free(izone);
return 0;
}
return SXNET_add_id_INTEGER(psx, izone, user, userlen);
}
int SXNET_add_id_INTEGER(SXNET **psx, ASN1_INTEGER *zone, char *user,
int userlen)
{
SXNET *sx = NULL;
SXNETID *id = NULL;
if(!psx || !zone || !user) {
X509V3err(X509V3_F_SXNET_ADD_ID_INTEGER,X509V3_R_INVALID_NULL_ARGUMENT);
return 0;
}
if(userlen == -1) userlen = strlen(user);
if(userlen > 64) {
X509V3err(X509V3_F_SXNET_ADD_ID_INTEGER,X509V3_R_USER_TOO_LONG);
return 0;
}
if(!*psx) {
if(!(sx = SXNET_new())) goto err;
if(!ASN1_INTEGER_set(sx->version, 0)) goto err;
*psx = sx;
} else sx = *psx;
if(SXNET_get_id_INTEGER(sx, zone)) {
X509V3err(X509V3_F_SXNET_ADD_ID_INTEGER,X509V3_R_DUPLICATE_ZONE_ID);
return 0;
}
if(!(id = SXNETID_new())) goto err;
if(userlen == -1) userlen = strlen(user);
if(!ASN1_OCTET_STRING_set(id->user, user, userlen)) goto err;
if(!sk_SXNETID_push(sx->ids, id)) goto err;
id->zone = zone;
return 1;
err:
X509V3err(X509V3_F_SXNET_ADD_ID_INTEGER,ERR_R_MALLOC_FAILURE);
SXNETID_free(id);
SXNET_free(sx);
*psx = NULL;
return 0;
}
ASN1_OCTET_STRING *SXNET_get_id_asc(SXNET *sx, char *zone)
{
ASN1_INTEGER *izone = NULL;
ASN1_OCTET_STRING *oct;
if(!(izone = s2i_ASN1_INTEGER(NULL, zone))) {
X509V3err(X509V3_F_SXNET_GET_ID_ASC,X509V3_R_ERROR_CONVERTING_ZONE);
return NULL;
}
oct = SXNET_get_id_INTEGER(sx, izone);
ASN1_INTEGER_free(oct);
return oct;
}
ASN1_OCTET_STRING *SXNET_get_id_ulong(SXNET *sx, unsigned long lzone)
{
ASN1_INTEGER *izone = NULL;
ASN1_OCTET_STRING *oct;
if(!(izone = ASN1_INTEGER_new()) || !ASN1_INTEGER_set(izone, lzone)) {
X509V3err(X509V3_F_SXNET_GET_ID_ULONG,ERR_R_MALLOC_FAILURE);
ASN1_INTEGER_free(izone);
return NULL;
}
oct = SXNET_get_id_INTEGER(sx, izone);
ASN1_INTEGER_free(oct);
return oct;
}
ASN1_OCTET_STRING *SXNET_get_id_INTEGER(SXNET *sx, ASN1_INTEGER *zone)
{
SXNETID *id;
int i;
for(i = 0; i < sk_SXNETID_num(sx->ids); i++) {
id = sk_SXNETID_value(sx->ids, i);
if(!ASN1_INTEGER_cmp(id->zone, zone)) return id->user;
}
return NULL;
}
