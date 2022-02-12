PKCS12 *PKCS12_create(char *pass, char *name, EVP_PKEY *pkey, X509 *cert,
STACK *ca, int nid_key, int nid_cert, int iter, int mac_iter,
int keytype)
{
PKCS12 *p12;
STACK *bags, *safes;
PKCS12_SAFEBAG *bag;
PKCS8_PRIV_KEY_INFO *p8;
PKCS7 *authsafe;
X509 *tcert;
int i;
unsigned char keyid[EVP_MAX_MD_SIZE];
unsigned int keyidlen;
if(!nid_cert) nid_cert = NID_pbe_WithSHA1And40BitRC2_CBC;
if(!nid_key) nid_key = NID_pbe_WithSHA1And3_Key_TripleDES_CBC;
if(!iter) iter = PKCS12_DEFAULT_ITER;
if(!mac_iter) mac_iter = 1;
if(!pkey || !cert) {
PKCS12err(PKCS12_F_PKCS12_CREATE,PKCS12_R_INVALID_NULL_ARGUMENT);
return NULL;
}
if(!(bags = sk_new (NULL))) {
PKCS12err(PKCS12_F_PKCS12_CREATE,ERR_R_MALLOC_FAILURE);
return NULL;
}
if(!(bag = M_PKCS12_x5092certbag(cert))) return NULL;
if(name && !PKCS12_add_friendlyname(bag, name, -1)) return NULL;
X509_digest(cert, EVP_sha1(), keyid, &keyidlen);
if(!PKCS12_add_localkeyid(bag, keyid, keyidlen)) return NULL;
if(!sk_push(bags, (char *)bag)) {
PKCS12err(PKCS12_F_PKCS12_CREATE,ERR_R_MALLOC_FAILURE);
return NULL;
}
if(ca) {
for(i = 0; i < sk_num(ca); i++) {
tcert = (X509 *)sk_value(ca, i);
if(!(bag = M_PKCS12_x5092certbag(tcert))) return NULL;
if(!sk_push(bags, (char *)bag)) {
PKCS12err(PKCS12_F_PKCS12_CREATE,ERR_R_MALLOC_FAILURE);
return NULL;
}
}
}
authsafe = PKCS12_pack_p7encdata (nid_cert, pass, -1, NULL, 0,
iter, bags);
sk_pop_free(bags, PKCS12_SAFEBAG_free);
if (!authsafe) return NULL;
if(!(safes = sk_new (NULL)) || !sk_push(safes, (char *)authsafe)) {
PKCS12err(PKCS12_F_PKCS12_CREATE,ERR_R_MALLOC_FAILURE);
return NULL;
}
if(!(p8 = EVP_PKEY2PKCS8 (pkey))) return NULL;
if(keytype && !PKCS8_add_keyusage(p8, keytype)) return NULL;
bag = PKCS12_MAKE_SHKEYBAG (nid_key, pass, -1, NULL, 0, iter, p8);
if(!bag) return NULL;
PKCS8_PRIV_KEY_INFO_free(p8);
if (name && !PKCS12_add_friendlyname (bag, name, -1)) return NULL;
if(!PKCS12_add_localkeyid (bag, keyid, keyidlen)) return NULL;
if(!(bags = sk_new(NULL)) || !sk_push (bags, (char *)bag)) {
PKCS12err(PKCS12_F_PKCS12_CREATE,ERR_R_MALLOC_FAILURE);
return NULL;
}
if(!(authsafe = PKCS12_pack_p7data (bags))) return NULL;
sk_pop_free(bags, PKCS12_SAFEBAG_free);
if(!sk_push(safes, (char *)authsafe)) {
PKCS12err(PKCS12_F_PKCS12_CREATE,ERR_R_MALLOC_FAILURE);
return NULL;
}
if(!(p12 = PKCS12_init (NID_pkcs7_data))) return NULL;
if(!M_PKCS12_pack_authsafes (p12, safes)) return NULL;
sk_pop_free(safes, PKCS7_free);
if(!PKCS12_set_mac (p12, pass, -1, NULL, 0, mac_iter, NULL))
return NULL;
return p12;
}
