int PKCS12_parse (PKCS12 *p12, const char *pass, EVP_PKEY **pkey, X509 **cert,
STACK **ca)
{
if(!p12) {
PKCS12err(PKCS12_F_PKCS12_PARSE,PKCS12_R_INVALID_NULL_PKCS12_POINTER);
return 0;
}
if ((ca != NULL) && (*ca == NULL)) {
if (!(*ca = sk_new(NULL))) {
PKCS12err(PKCS12_F_PKCS12_PARSE,ERR_R_MALLOC_FAILURE);
return 0;
}
}
if(pkey) *pkey = NULL;
if(cert) *cert = NULL;
if (!PKCS12_verify_mac (p12, pass, -1)) {
PKCS12err(PKCS12_F_PKCS12_PARSE,PKCS12_R_MAC_VERIFY_FAILURE);
goto err;
}
if (!parse_pk12 (p12, pass, -1, pkey, cert, ca)) {
PKCS12err(PKCS12_F_PKCS12_PARSE,PKCS12_R_PARSE_ERROR);
goto err;
}
return 1;
err:
if (pkey && *pkey) EVP_PKEY_free (*pkey);
if (cert && *cert) X509_free (*cert);
if (ca) sk_pop_free (*ca, X509_free);
return 0;
}
static int parse_pk12 (PKCS12 *p12, const char *pass, int passlen,
EVP_PKEY **pkey, X509 **cert, STACK **ca)
{
STACK *asafes, *bags;
int i, bagnid;
PKCS7 *p7;
ASN1_OCTET_STRING *keyid = NULL;
char keymatch = 0;
if (!( asafes = M_PKCS12_unpack_authsafes (p12))) return 0;
for (i = 0; i < sk_num (asafes); i++) {
p7 = (PKCS7 *) sk_value (asafes, i);
bagnid = OBJ_obj2nid (p7->type);
if (bagnid == NID_pkcs7_data) {
bags = M_PKCS12_unpack_p7data (p7);
} else if (bagnid == NID_pkcs7_encrypted) {
bags = M_PKCS12_unpack_p7encdata (p7, pass, passlen);
} else continue;
if (!bags) {
sk_pop_free (asafes, PKCS7_free);
return 0;
}
if (!parse_bags(bags, pass, passlen, pkey, cert, ca,
&keyid, &keymatch)) {
sk_pop_free(bags, PKCS12_SAFEBAG_free);
sk_pop_free(asafes, PKCS7_free);
return 0;
}
sk_pop_free(bags, PKCS12_SAFEBAG_free);
}
sk_pop_free(asafes, PKCS7_free);
if (keyid) M_ASN1_OCTET_STRING_free(keyid);
return 1;
}
static int parse_bags (STACK *bags, const char *pass, int passlen,
EVP_PKEY **pkey, X509 **cert, STACK **ca,
ASN1_OCTET_STRING **keyid, char *keymatch)
{
int i;
for (i = 0; i < sk_num(bags); i++) {
if (!parse_bag((PKCS12_SAFEBAG *)sk_value (bags, i),
pass, passlen, pkey, cert, ca, keyid,
keymatch)) return 0;
}
return 1;
}
static int parse_bag(PKCS12_SAFEBAG *bag, const char *pass, int passlen,
EVP_PKEY **pkey, X509 **cert, STACK **ca,
ASN1_OCTET_STRING **keyid,
char *keymatch)
{
PKCS8_PRIV_KEY_INFO *p8;
X509 *x509;
ASN1_OCTET_STRING *lkey = NULL;
ASN1_TYPE *attrib;
if ((attrib = PKCS12_get_attr (bag, NID_localKeyID)))
lkey = attrib->value.octet_string;
if (lkey && ((*keymatch & MATCH_ALL) != MATCH_ALL)) {
if (*keyid) {
if (M_ASN1_OCTET_STRING_cmp(*keyid, lkey)) lkey = NULL;
} else {
if (!(*keyid = M_ASN1_OCTET_STRING_dup(lkey))) {
PKCS12err(PKCS12_F_PARSE_BAGS,ERR_R_MALLOC_FAILURE);
return 0;
}
}
}
switch (M_PKCS12_bag_type(bag))
{
case NID_keyBag:
if (!lkey || !pkey) return 1;
if (!(*pkey = EVP_PKCS82PKEY(bag->value.keybag))) return 0;
*keymatch |= MATCH_KEY;
break;
case NID_pkcs8ShroudedKeyBag:
if (!lkey || !pkey) return 1;
if (!(p8 = M_PKCS12_decrypt_skey(bag, pass, passlen)))
return 0;
*pkey = EVP_PKCS82PKEY(p8);
PKCS8_PRIV_KEY_INFO_free(p8);
if (!(*pkey)) return 0;
*keymatch |= MATCH_KEY;
break;
case NID_certBag:
if (M_PKCS12_cert_bag_type(bag) != NID_x509Certificate )
return 1;
if (!(x509 = M_PKCS12_certbag2x509(bag))) return 0;
if (lkey) {
*keymatch |= MATCH_CERT;
if (cert) *cert = x509;
} else if (ca) sk_push (*ca, (char *)x509);
break;
case NID_safeContentsBag:
return parse_bags(bag->value.safes, pass, passlen,
pkey, cert, ca, keyid, keymatch);
break;
default:
return 1;
break;
}
return 1;
}
