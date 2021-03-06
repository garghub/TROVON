int PKCS12_add_localkeyid(PKCS12_SAFEBAG *bag, unsigned char *name,
int namelen)
{
if (X509at_add1_attr_by_NID(&bag->attrib, NID_localKeyID,
V_ASN1_OCTET_STRING, name, namelen))
return 1;
else
return 0;
}
int PKCS8_add_keyusage(PKCS8_PRIV_KEY_INFO *p8, int usage)
{
unsigned char us_val = (unsigned char)usage;
return PKCS8_pkey_add1_attr_by_NID(p8, NID_key_usage,
V_ASN1_BIT_STRING, &us_val, 1);
}
int PKCS12_add_friendlyname_asc(PKCS12_SAFEBAG *bag, const char *name,
int namelen)
{
if (X509at_add1_attr_by_NID(&bag->attrib, NID_friendlyName,
MBSTRING_ASC, (unsigned char *)name, namelen))
return 1;
else
return 0;
}
int PKCS12_add_friendlyname_utf8(PKCS12_SAFEBAG *bag, const char *name,
int namelen)
{
if (X509at_add1_attr_by_NID(&bag->attrib, NID_friendlyName,
MBSTRING_UTF8, (unsigned char *)name, namelen))
return 1;
else
return 0;
}
int PKCS12_add_friendlyname_uni(PKCS12_SAFEBAG *bag,
const unsigned char *name, int namelen)
{
if (X509at_add1_attr_by_NID(&bag->attrib, NID_friendlyName,
MBSTRING_BMP, name, namelen))
return 1;
else
return 0;
}
int PKCS12_add_CSPName_asc(PKCS12_SAFEBAG *bag, const char *name, int namelen)
{
if (X509at_add1_attr_by_NID(&bag->attrib, NID_ms_csp_name,
MBSTRING_ASC, (unsigned char *)name, namelen))
return 1;
else
return 0;
}
char *PKCS12_get_friendlyname(PKCS12_SAFEBAG *bag)
{
const ASN1_TYPE *atype;
if ((atype = PKCS12_SAFEBAG_get0_attr(bag, NID_friendlyName)) == NULL)
return NULL;
if (atype->type != V_ASN1_BMPSTRING)
return NULL;
return OPENSSL_uni2utf8(atype->value.bmpstring->data,
atype->value.bmpstring->length);
}
