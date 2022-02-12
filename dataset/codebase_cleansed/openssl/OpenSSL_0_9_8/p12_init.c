PKCS12 *PKCS12_init(int mode)
{
PKCS12 *pkcs12;
if (!(pkcs12 = PKCS12_new())) {
PKCS12err(PKCS12_F_PKCS12_INIT,ERR_R_MALLOC_FAILURE);
return NULL;
}
ASN1_INTEGER_set(pkcs12->version, 3);
pkcs12->authsafes->type = OBJ_nid2obj(mode);
switch (mode) {
case NID_pkcs7_data:
if (!(pkcs12->authsafes->d.data =
M_ASN1_OCTET_STRING_new())) {
PKCS12err(PKCS12_F_PKCS12_INIT,ERR_R_MALLOC_FAILURE);
goto err;
}
break;
default:
PKCS12err(PKCS12_F_PKCS12_INIT,
PKCS12_R_UNSUPPORTED_PKCS12_MODE);
goto err;
}
return pkcs12;
err:
if (pkcs12 != NULL) PKCS12_free(pkcs12);
return NULL;
}
