PKCS12_SAFEBAG *PKCS12_pack_safebag (char *obj, int (*i2d)(), int nid1,
int nid2)
{
PKCS12_BAGS *bag;
PKCS12_SAFEBAG *safebag;
if (!(bag = PKCS12_BAGS_new ())) {
PKCS12err(PKCS12_F_PKCS12_PACK_SAFEBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
bag->type = OBJ_nid2obj(nid1);
if (!ASN1_pack_string(obj, i2d, &bag->value.octet)) {
PKCS12err(PKCS12_F_PKCS12_PACK_SAFEBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!(safebag = PKCS12_SAFEBAG_new ())) {
PKCS12err(PKCS12_F_PKCS12_PACK_SAFEBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
safebag->value.bag = bag;
safebag->type = OBJ_nid2obj(nid2);
return safebag;
}
PKCS12_SAFEBAG *PKCS12_MAKE_KEYBAG (PKCS8_PRIV_KEY_INFO *p8)
{
PKCS12_SAFEBAG *bag;
if (!(bag = PKCS12_SAFEBAG_new())) {
PKCS12err(PKCS12_F_PKCS12_MAKE_KEYBAG,ERR_R_MALLOC_FAILURE);
return NULL;
}
bag->type = OBJ_nid2obj(NID_keyBag);
bag->value.keybag = p8;
return bag;
}
PKCS12_SAFEBAG *PKCS12_MAKE_SHKEYBAG (int pbe_nid, const char *pass,
int passlen, unsigned char *salt, int saltlen, int iter,
PKCS8_PRIV_KEY_INFO *p8)
{
PKCS12_SAFEBAG *bag;
if (!(bag = PKCS12_SAFEBAG_new ())) {
PKCS12err(PKCS12_F_PKCS12_MAKE_SHKEYBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
bag->type = OBJ_nid2obj(NID_pkcs8ShroudedKeyBag);
if (!(bag->value.shkeybag =
PKCS8_encrypt(pbe_nid, NULL, pass, passlen, salt, saltlen, iter,
p8))) {
PKCS12err(PKCS12_F_PKCS12_MAKE_SHKEYBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
return bag;
}
X509_SIG *PKCS8_encrypt(int pbe_nid, const EVP_CIPHER *cipher,
const char *pass, int passlen,
unsigned char *salt, int saltlen, int iter,
PKCS8_PRIV_KEY_INFO *p8inf)
{
X509_SIG *p8;
X509_ALGOR *pbe;
if (!(p8 = X509_SIG_new())) {
PKCS12err(PKCS12_F_PKCS8_ENCRYPT, ERR_R_MALLOC_FAILURE);
goto err;
}
if(pbe_nid == -1) pbe = PKCS5_pbe2_set(cipher, iter, salt, saltlen);
else pbe = PKCS5_pbe_set(pbe_nid, iter, salt, saltlen);
if(!pbe) {
PKCS12err(PKCS12_F_PKCS8_ENCRYPT, ERR_R_ASN1_LIB);
goto err;
}
X509_ALGOR_free(p8->algor);
p8->algor = pbe;
M_ASN1_OCTET_STRING_free(p8->digest);
if (!(p8->digest =
PKCS12_i2d_encrypt (pbe, i2d_PKCS8_PRIV_KEY_INFO, pass, passlen,
(char *)p8inf, 0))) {
PKCS12err(PKCS12_F_PKCS8_ENCRYPT, PKCS12_R_ENCRYPT_ERROR);
goto err;
}
return p8;
err:
X509_SIG_free(p8);
return NULL;
}
