EVP_PKEY *EVP_PKCS82PKEY(PKCS8_PRIV_KEY_INFO *p8)
{
EVP_PKEY *pkey = NULL;
ASN1_OBJECT *algoid;
char obj_tmp[80];
if (!PKCS8_pkey_get0(&algoid, NULL, NULL, NULL, p8))
return NULL;
if (!(pkey = EVP_PKEY_new())) {
EVPerr(EVP_F_EVP_PKCS82PKEY, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!EVP_PKEY_set_type(pkey, OBJ_obj2nid(algoid))) {
EVPerr(EVP_F_EVP_PKCS82PKEY, EVP_R_UNSUPPORTED_PRIVATE_KEY_ALGORITHM);
i2t_ASN1_OBJECT(obj_tmp, 80, algoid);
ERR_add_error_data(2, "TYPE=", obj_tmp);
goto error;
}
if (pkey->ameth->priv_decode) {
if (!pkey->ameth->priv_decode(pkey, p8)) {
EVPerr(EVP_F_EVP_PKCS82PKEY, EVP_R_PRIVATE_KEY_DECODE_ERROR);
goto error;
}
} else {
EVPerr(EVP_F_EVP_PKCS82PKEY, EVP_R_METHOD_NOT_SUPPORTED);
goto error;
}
return pkey;
error:
EVP_PKEY_free(pkey);
return NULL;
}
PKCS8_PRIV_KEY_INFO *EVP_PKEY2PKCS8(EVP_PKEY *pkey)
{
return EVP_PKEY2PKCS8_broken(pkey, PKCS8_OK);
}
PKCS8_PRIV_KEY_INFO *EVP_PKEY2PKCS8_broken(EVP_PKEY *pkey, int broken)
{
PKCS8_PRIV_KEY_INFO *p8;
if (!(p8 = PKCS8_PRIV_KEY_INFO_new())) {
EVPerr(EVP_F_EVP_PKEY2PKCS8_BROKEN, ERR_R_MALLOC_FAILURE);
return NULL;
}
p8->broken = broken;
if (pkey->ameth) {
if (pkey->ameth->priv_encode) {
if (!pkey->ameth->priv_encode(p8, pkey)) {
EVPerr(EVP_F_EVP_PKEY2PKCS8_BROKEN,
EVP_R_PRIVATE_KEY_ENCODE_ERROR);
goto error;
}
} else {
EVPerr(EVP_F_EVP_PKEY2PKCS8_BROKEN, EVP_R_METHOD_NOT_SUPPORTED);
goto error;
}
} else {
EVPerr(EVP_F_EVP_PKEY2PKCS8_BROKEN,
EVP_R_UNSUPPORTED_PRIVATE_KEY_ALGORITHM);
goto error;
}
RAND_add(p8->pkey->value.octet_string->data,
p8->pkey->value.octet_string->length, 0.0);
return p8;
error:
PKCS8_PRIV_KEY_INFO_free(p8);
return NULL;
}
PKCS8_PRIV_KEY_INFO *PKCS8_set_broken(PKCS8_PRIV_KEY_INFO *p8, int broken)
{
switch (broken) {
case PKCS8_OK:
p8->broken = PKCS8_OK;
return p8;
break;
case PKCS8_NO_OCTET:
p8->broken = PKCS8_NO_OCTET;
p8->pkey->type = V_ASN1_SEQUENCE;
return p8;
break;
default:
EVPerr(EVP_F_PKCS8_SET_BROKEN, EVP_R_PKCS8_UNKNOWN_BROKEN_TYPE);
return NULL;
}
}
int EVP_PKEY_get_attr_count(const EVP_PKEY *key)
{
return X509at_get_attr_count(key->attributes);
}
int EVP_PKEY_get_attr_by_NID(const EVP_PKEY *key, int nid, int lastpos)
{
return X509at_get_attr_by_NID(key->attributes, nid, lastpos);
}
int EVP_PKEY_get_attr_by_OBJ(const EVP_PKEY *key, ASN1_OBJECT *obj,
int lastpos)
{
return X509at_get_attr_by_OBJ(key->attributes, obj, lastpos);
}
X509_ATTRIBUTE *EVP_PKEY_get_attr(const EVP_PKEY *key, int loc)
{
return X509at_get_attr(key->attributes, loc);
}
X509_ATTRIBUTE *EVP_PKEY_delete_attr(EVP_PKEY *key, int loc)
{
return X509at_delete_attr(key->attributes, loc);
}
int EVP_PKEY_add1_attr(EVP_PKEY *key, X509_ATTRIBUTE *attr)
{
if (X509at_add1_attr(&key->attributes, attr))
return 1;
return 0;
}
int EVP_PKEY_add1_attr_by_OBJ(EVP_PKEY *key,
const ASN1_OBJECT *obj, int type,
const unsigned char *bytes, int len)
{
if (X509at_add1_attr_by_OBJ(&key->attributes, obj, type, bytes, len))
return 1;
return 0;
}
int EVP_PKEY_add1_attr_by_NID(EVP_PKEY *key,
int nid, int type,
const unsigned char *bytes, int len)
{
if (X509at_add1_attr_by_NID(&key->attributes, nid, type, bytes, len))
return 1;
return 0;
}
int EVP_PKEY_add1_attr_by_txt(EVP_PKEY *key,
const char *attrname, int type,
const unsigned char *bytes, int len)
{
if (X509at_add1_attr_by_txt(&key->attributes, attrname, type, bytes, len))
return 1;
return 0;
}
