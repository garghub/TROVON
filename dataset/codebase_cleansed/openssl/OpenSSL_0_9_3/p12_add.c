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
PKCS8_encrypt(pbe_nid, pass, passlen, salt, saltlen, iter, p8))) {
PKCS12err(PKCS12_F_PKCS12_MAKE_SHKEYBAG, ERR_R_MALLOC_FAILURE);
return NULL;
}
return bag;
}
PKCS7 *PKCS12_pack_p7data (STACK *sk)
{
PKCS7 *p7;
if (!(p7 = PKCS7_new())) {
PKCS12err(PKCS12_F_PKCS12_PACK_P7DATA, ERR_R_MALLOC_FAILURE);
return NULL;
}
p7->type = OBJ_nid2obj(NID_pkcs7_data);
if (!(p7->d.data = ASN1_OCTET_STRING_new())) {
PKCS12err(PKCS12_F_PKCS12_PACK_P7DATA, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!ASN1_seq_pack(sk, i2d_PKCS12_SAFEBAG, &p7->d.data->data,
&p7->d.data->length)) {
PKCS12err(PKCS12_F_PKCS12_PACK_P7DATA, PKCS12_R_CANT_PACK_STRUCTURE);
return NULL;
}
return p7;
}
PKCS7 *PKCS12_pack_p7encdata (int pbe_nid, const char *pass, int passlen,
unsigned char *salt, int saltlen, int iter, STACK *bags)
{
PKCS7 *p7;
X509_ALGOR *pbe;
if (!(p7 = PKCS7_new())) {
PKCS12err(PKCS12_F_PKCS12_PACK_P7ENCDATA, ERR_R_MALLOC_FAILURE);
return NULL;
}
p7->type = OBJ_nid2obj(NID_pkcs7_encrypted);
if (!(p7->d.encrypted = PKCS7_ENCRYPT_new ())) {
PKCS12err(PKCS12_F_PKCS12_PACK_P7ENCDATA, ERR_R_MALLOC_FAILURE);
return NULL;
}
ASN1_INTEGER_set (p7->d.encrypted->version, 0);
p7->d.encrypted->enc_data->content_type = OBJ_nid2obj(NID_pkcs7_data);
if (!(pbe = PKCS5_pbe_set (pbe_nid, iter, salt, saltlen))) {
PKCS12err(PKCS12_F_PKCS12_PACK_P7ENCDATA, ERR_R_MALLOC_FAILURE);
return NULL;
}
X509_ALGOR_free(p7->d.encrypted->enc_data->algorithm);
p7->d.encrypted->enc_data->algorithm = pbe;
ASN1_OCTET_STRING_free(p7->d.encrypted->enc_data->enc_data);
if (!(p7->d.encrypted->enc_data->enc_data =
PKCS12_i2d_encrypt (pbe, i2d_PKCS12_SAFEBAG, pass, passlen,
(char *)bags, 1))) {
PKCS12err(PKCS12_F_PKCS12_PACK_P7ENCDATA, PKCS12_R_ENCRYPT_ERROR);
return NULL;
}
return p7;
}
X509_SIG *PKCS8_encrypt (int pbe_nid, const char *pass, int passlen,
unsigned char *salt, int saltlen, int iter,
PKCS8_PRIV_KEY_INFO *p8inf)
{
X509_SIG *p8;
X509_ALGOR *pbe;
if (!(p8 = X509_SIG_new())) {
PKCS12err(PKCS12_F_PKCS8_ENCRYPT, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!(pbe = PKCS5_pbe_set (pbe_nid, iter, salt, saltlen))) {
PKCS12err(PKCS12_F_PKCS8_ENCRYPT, ERR_R_MALLOC_FAILURE);
return NULL;
}
X509_ALGOR_free(p8->algor);
p8->algor = pbe;
ASN1_OCTET_STRING_free(p8->digest);
if (!(p8->digest =
PKCS12_i2d_encrypt (pbe, i2d_PKCS8_PRIV_KEY_INFO, pass, passlen,
(char *)p8inf, 0))) {
PKCS12err(PKCS12_F_PKCS8_ENCRYPT, PKCS12_R_ENCRYPT_ERROR);
return NULL;
}
return p8;
}
