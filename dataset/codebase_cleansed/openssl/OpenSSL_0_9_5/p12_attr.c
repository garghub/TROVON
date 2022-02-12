int PKCS12_add_localkeyid (PKCS12_SAFEBAG *bag, unsigned char *name,
int namelen)
{
X509_ATTRIBUTE *attrib;
ASN1_BMPSTRING *oct;
ASN1_TYPE *keyid;
if (!(keyid = ASN1_TYPE_new ())) {
PKCS12err(PKCS12_F_PKCS12_ADD_LOCALKEYID, ERR_R_MALLOC_FAILURE);
return 0;
}
keyid->type = V_ASN1_OCTET_STRING;
if (!(oct = M_ASN1_OCTET_STRING_new())) {
PKCS12err(PKCS12_F_PKCS12_ADD_LOCALKEYID, ERR_R_MALLOC_FAILURE);
return 0;
}
if (!M_ASN1_OCTET_STRING_set(oct, name, namelen)) {
PKCS12err(PKCS12_F_PKCS12_ADD_LOCALKEYID, ERR_R_MALLOC_FAILURE);
return 0;
}
keyid->value.octet_string = oct;
if (!(attrib = X509_ATTRIBUTE_new ())) {
PKCS12err(PKCS12_F_PKCS12_ADD_LOCALKEYID, ERR_R_MALLOC_FAILURE);
return 0;
}
attrib->object = OBJ_nid2obj(NID_localKeyID);
if (!(attrib->value.set = sk_ASN1_TYPE_new(NULL))) {
PKCS12err(PKCS12_F_PKCS12_ADD_LOCALKEYID, ERR_R_MALLOC_FAILURE);
return 0;
}
sk_ASN1_TYPE_push (attrib->value.set,keyid);
attrib->set = 1;
if (!bag->attrib && !(bag->attrib = sk_X509_ATTRIBUTE_new (NULL))) {
PKCS12err(PKCS12_F_PKCS12_ADD_LOCALKEYID, ERR_R_MALLOC_FAILURE);
return 0;
}
sk_X509_ATTRIBUTE_push (bag->attrib, attrib);
return 1;
}
int PKCS8_add_keyusage (PKCS8_PRIV_KEY_INFO *p8, int usage)
{
X509_ATTRIBUTE *attrib;
ASN1_BIT_STRING *bstr;
ASN1_TYPE *keyid;
unsigned char us_val;
us_val = (unsigned char) usage;
if (!(keyid = ASN1_TYPE_new ())) {
PKCS12err(PKCS12_F_PKCS8_ADD_KEYUSAGE, ERR_R_MALLOC_FAILURE);
return 0;
}
keyid->type = V_ASN1_BIT_STRING;
if (!(bstr = M_ASN1_BIT_STRING_new())) {
PKCS12err(PKCS12_F_PKCS8_ADD_KEYUSAGE, ERR_R_MALLOC_FAILURE);
return 0;
}
if (!M_ASN1_BIT_STRING_set(bstr, &us_val, 1)) {
PKCS12err(PKCS12_F_PKCS8_ADD_KEYUSAGE, ERR_R_MALLOC_FAILURE);
return 0;
}
keyid->value.bit_string = bstr;
if (!(attrib = X509_ATTRIBUTE_new ())) {
PKCS12err(PKCS12_F_PKCS8_ADD_KEYUSAGE, ERR_R_MALLOC_FAILURE);
return 0;
}
attrib->object = OBJ_nid2obj(NID_key_usage);
if (!(attrib->value.set = sk_ASN1_TYPE_new(NULL))) {
PKCS12err(PKCS12_F_PKCS8_ADD_KEYUSAGE, ERR_R_MALLOC_FAILURE);
return 0;
}
sk_ASN1_TYPE_push (attrib->value.set,keyid);
attrib->set = 1;
if (!p8->attributes
&& !(p8->attributes = sk_X509_ATTRIBUTE_new (NULL))) {
PKCS12err(PKCS12_F_PKCS8_ADD_KEYUSAGE, ERR_R_MALLOC_FAILURE);
return 0;
}
sk_X509_ATTRIBUTE_push (p8->attributes, attrib);
return 1;
}
int PKCS12_add_friendlyname_asc (PKCS12_SAFEBAG *bag, const char *name,
int namelen)
{
unsigned char *uniname;
int ret, unilen;
if (!asc2uni(name, &uniname, &unilen)) {
PKCS12err(PKCS12_F_PKCS12_ADD_FRIENDLYNAME_ASC,
ERR_R_MALLOC_FAILURE);
return 0;
}
ret = PKCS12_add_friendlyname_uni (bag, uniname, unilen);
Free(uniname);
return ret;
}
int PKCS12_add_friendlyname_uni (PKCS12_SAFEBAG *bag,
const unsigned char *name, int namelen)
{
X509_ATTRIBUTE *attrib;
ASN1_BMPSTRING *bmp;
ASN1_TYPE *fname;
if(!name[namelen - 1] && !name[namelen - 2]) namelen -= 2;
if (!(fname = ASN1_TYPE_new ())) {
PKCS12err(PKCS12_F_PKCS12_ADD_FRIENDLYNAME_UNI,
ERR_R_MALLOC_FAILURE);
return 0;
}
fname->type = V_ASN1_BMPSTRING;
if (!(bmp = M_ASN1_BMPSTRING_new())) {
PKCS12err(PKCS12_F_PKCS12_ADD_FRIENDLYNAME_UNI,
ERR_R_MALLOC_FAILURE);
return 0;
}
if (!(bmp->data = Malloc (namelen))) {
PKCS12err(PKCS12_F_PKCS12_ADD_FRIENDLYNAME_UNI,
ERR_R_MALLOC_FAILURE);
return 0;
}
memcpy (bmp->data, name, namelen);
bmp->length = namelen;
fname->value.bmpstring = bmp;
if (!(attrib = X509_ATTRIBUTE_new ())) {
PKCS12err(PKCS12_F_PKCS12_ADD_FRIENDLYNAME_UNI,
ERR_R_MALLOC_FAILURE);
return 0;
}
attrib->object = OBJ_nid2obj(NID_friendlyName);
if (!(attrib->value.set = sk_ASN1_TYPE_new(NULL))) {
PKCS12err(PKCS12_F_PKCS12_ADD_FRIENDLYNAME,
ERR_R_MALLOC_FAILURE);
return 0;
}
sk_ASN1_TYPE_push (attrib->value.set,fname);
attrib->set = 1;
if (!bag->attrib && !(bag->attrib = sk_X509_ATTRIBUTE_new (NULL))) {
PKCS12err(PKCS12_F_PKCS12_ADD_FRIENDLYNAME_UNI,
ERR_R_MALLOC_FAILURE);
return 0;
}
sk_X509_ATTRIBUTE_push (bag->attrib, attrib);
return PKCS12_OK;
}
char *PKCS12_get_friendlyname(PKCS12_SAFEBAG *bag)
{
ASN1_TYPE *atype;
if (!(atype = PKCS12_get_attr(bag, NID_friendlyName))) return NULL;
if (atype->type != V_ASN1_BMPSTRING) return NULL;
return uni2asc(atype->value.bmpstring->data,
atype->value.bmpstring->length);
}
