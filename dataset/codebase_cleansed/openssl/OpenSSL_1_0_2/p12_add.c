PKCS12_SAFEBAG *PKCS12_item_pack_safebag(void *obj, const ASN1_ITEM *it,
int nid1, int nid2)
{
PKCS12_BAGS *bag;
PKCS12_SAFEBAG *safebag;
if (!(bag = PKCS12_BAGS_new())) {
PKCS12err(PKCS12_F_PKCS12_ITEM_PACK_SAFEBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
bag->type = OBJ_nid2obj(nid1);
if (!ASN1_item_pack(obj, it, &bag->value.octet)) {
PKCS12err(PKCS12_F_PKCS12_ITEM_PACK_SAFEBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!(safebag = PKCS12_SAFEBAG_new())) {
PKCS12err(PKCS12_F_PKCS12_ITEM_PACK_SAFEBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
safebag->value.bag = bag;
safebag->type = OBJ_nid2obj(nid2);
return safebag;
}
PKCS12_SAFEBAG *PKCS12_MAKE_KEYBAG(PKCS8_PRIV_KEY_INFO *p8)
{
PKCS12_SAFEBAG *bag;
if (!(bag = PKCS12_SAFEBAG_new())) {
PKCS12err(PKCS12_F_PKCS12_MAKE_KEYBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
bag->type = OBJ_nid2obj(NID_keyBag);
bag->value.keybag = p8;
return bag;
}
PKCS12_SAFEBAG *PKCS12_MAKE_SHKEYBAG(int pbe_nid, const char *pass,
int passlen, unsigned char *salt,
int saltlen, int iter,
PKCS8_PRIV_KEY_INFO *p8)
{
PKCS12_SAFEBAG *bag;
const EVP_CIPHER *pbe_ciph;
if (!(bag = PKCS12_SAFEBAG_new())) {
PKCS12err(PKCS12_F_PKCS12_MAKE_SHKEYBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
bag->type = OBJ_nid2obj(NID_pkcs8ShroudedKeyBag);
pbe_ciph = EVP_get_cipherbynid(pbe_nid);
if (pbe_ciph)
pbe_nid = -1;
if (!(bag->value.shkeybag =
PKCS8_encrypt(pbe_nid, pbe_ciph, pass, passlen, salt, saltlen, iter,
p8))) {
PKCS12err(PKCS12_F_PKCS12_MAKE_SHKEYBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
return bag;
}
