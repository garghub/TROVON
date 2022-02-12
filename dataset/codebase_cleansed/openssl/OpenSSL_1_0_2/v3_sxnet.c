int SXNET_add_id_asc(SXNET **psx, char *zone, char *user, int userlen)
{
ASN1_INTEGER *izone = NULL;
if (!(izone = s2i_ASN1_INTEGER(NULL, zone))) {
X509V3err(X509V3_F_SXNET_ADD_ID_ASC, X509V3_R_ERROR_CONVERTING_ZONE);
return 0;
}
return SXNET_add_id_INTEGER(psx, izone, user, userlen);
}
int SXNET_add_id_ulong(SXNET **psx, unsigned long lzone, char *user,
int userlen)
{
ASN1_INTEGER *izone = NULL;
if (!(izone = M_ASN1_INTEGER_new()) || !ASN1_INTEGER_set(izone, lzone)) {
X509V3err(X509V3_F_SXNET_ADD_ID_ULONG, ERR_R_MALLOC_FAILURE);
M_ASN1_INTEGER_free(izone);
return 0;
}
return SXNET_add_id_INTEGER(psx, izone, user, userlen);
}
int SXNET_add_id_INTEGER(SXNET **psx, ASN1_INTEGER *zone, char *user,
int userlen)
{
SXNET *sx = NULL;
SXNETID *id = NULL;
if (!psx || !zone || !user) {
X509V3err(X509V3_F_SXNET_ADD_ID_INTEGER,
X509V3_R_INVALID_NULL_ARGUMENT);
return 0;
}
if (userlen == -1)
userlen = strlen(user);
if (userlen > 64) {
X509V3err(X509V3_F_SXNET_ADD_ID_INTEGER, X509V3_R_USER_TOO_LONG);
return 0;
}
if (!*psx) {
if (!(sx = SXNET_new()))
goto err;
if (!ASN1_INTEGER_set(sx->version, 0))
goto err;
*psx = sx;
} else
sx = *psx;
if (SXNET_get_id_INTEGER(sx, zone)) {
X509V3err(X509V3_F_SXNET_ADD_ID_INTEGER, X509V3_R_DUPLICATE_ZONE_ID);
return 0;
}
if (!(id = SXNETID_new()))
goto err;
if (userlen == -1)
userlen = strlen(user);
if (!M_ASN1_OCTET_STRING_set(id->user, user, userlen))
goto err;
if (!sk_SXNETID_push(sx->ids, id))
goto err;
id->zone = zone;
return 1;
err:
X509V3err(X509V3_F_SXNET_ADD_ID_INTEGER, ERR_R_MALLOC_FAILURE);
SXNETID_free(id);
SXNET_free(sx);
*psx = NULL;
return 0;
}
ASN1_OCTET_STRING *SXNET_get_id_asc(SXNET *sx, char *zone)
{
ASN1_INTEGER *izone = NULL;
ASN1_OCTET_STRING *oct;
if (!(izone = s2i_ASN1_INTEGER(NULL, zone))) {
X509V3err(X509V3_F_SXNET_GET_ID_ASC, X509V3_R_ERROR_CONVERTING_ZONE);
return NULL;
}
oct = SXNET_get_id_INTEGER(sx, izone);
M_ASN1_INTEGER_free(izone);
return oct;
}
ASN1_OCTET_STRING *SXNET_get_id_ulong(SXNET *sx, unsigned long lzone)
{
ASN1_INTEGER *izone = NULL;
ASN1_OCTET_STRING *oct;
if (!(izone = M_ASN1_INTEGER_new()) || !ASN1_INTEGER_set(izone, lzone)) {
X509V3err(X509V3_F_SXNET_GET_ID_ULONG, ERR_R_MALLOC_FAILURE);
M_ASN1_INTEGER_free(izone);
return NULL;
}
oct = SXNET_get_id_INTEGER(sx, izone);
M_ASN1_INTEGER_free(izone);
return oct;
}
ASN1_OCTET_STRING *SXNET_get_id_INTEGER(SXNET *sx, ASN1_INTEGER *zone)
{
SXNETID *id;
int i;
for (i = 0; i < sk_SXNETID_num(sx->ids); i++) {
id = sk_SXNETID_value(sx->ids, i);
if (!M_ASN1_INTEGER_cmp(id->zone, zone))
return id->user;
}
return NULL;
}
