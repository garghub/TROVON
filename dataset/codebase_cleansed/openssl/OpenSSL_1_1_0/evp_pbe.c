int EVP_PBE_CipherInit(ASN1_OBJECT *pbe_obj, const char *pass, int passlen,
ASN1_TYPE *param, EVP_CIPHER_CTX *ctx, int en_de)
{
const EVP_CIPHER *cipher;
const EVP_MD *md;
int cipher_nid, md_nid;
EVP_PBE_KEYGEN *keygen;
if (!EVP_PBE_find(EVP_PBE_TYPE_OUTER, OBJ_obj2nid(pbe_obj),
&cipher_nid, &md_nid, &keygen)) {
char obj_tmp[80];
EVPerr(EVP_F_EVP_PBE_CIPHERINIT, EVP_R_UNKNOWN_PBE_ALGORITHM);
if (!pbe_obj)
OPENSSL_strlcpy(obj_tmp, "NULL", sizeof obj_tmp);
else
i2t_ASN1_OBJECT(obj_tmp, sizeof obj_tmp, pbe_obj);
ERR_add_error_data(2, "TYPE=", obj_tmp);
return 0;
}
if (!pass)
passlen = 0;
else if (passlen == -1)
passlen = strlen(pass);
if (cipher_nid == -1)
cipher = NULL;
else {
cipher = EVP_get_cipherbynid(cipher_nid);
if (!cipher) {
EVPerr(EVP_F_EVP_PBE_CIPHERINIT, EVP_R_UNKNOWN_CIPHER);
return 0;
}
}
if (md_nid == -1)
md = NULL;
else {
md = EVP_get_digestbynid(md_nid);
if (!md) {
EVPerr(EVP_F_EVP_PBE_CIPHERINIT, EVP_R_UNKNOWN_DIGEST);
return 0;
}
}
if (!keygen(ctx, pass, passlen, param, cipher, md, en_de)) {
EVPerr(EVP_F_EVP_PBE_CIPHERINIT, EVP_R_KEYGEN_FAILURE);
return 0;
}
return 1;
}
static int pbe2_cmp(const EVP_PBE_CTL *pbe1, const EVP_PBE_CTL *pbe2)
{
int ret = pbe1->pbe_type - pbe2->pbe_type;
if (ret)
return ret;
else
return pbe1->pbe_nid - pbe2->pbe_nid;
}
static int pbe_cmp(const EVP_PBE_CTL *const *a, const EVP_PBE_CTL *const *b)
{
int ret = (*a)->pbe_type - (*b)->pbe_type;
if (ret)
return ret;
else
return (*a)->pbe_nid - (*b)->pbe_nid;
}
int EVP_PBE_alg_add_type(int pbe_type, int pbe_nid, int cipher_nid,
int md_nid, EVP_PBE_KEYGEN *keygen)
{
EVP_PBE_CTL *pbe_tmp;
if (pbe_algs == NULL) {
pbe_algs = sk_EVP_PBE_CTL_new(pbe_cmp);
if (pbe_algs == NULL)
goto err;
}
if ((pbe_tmp = OPENSSL_malloc(sizeof(*pbe_tmp))) == NULL)
goto err;
pbe_tmp->pbe_type = pbe_type;
pbe_tmp->pbe_nid = pbe_nid;
pbe_tmp->cipher_nid = cipher_nid;
pbe_tmp->md_nid = md_nid;
pbe_tmp->keygen = keygen;
if (!sk_EVP_PBE_CTL_push(pbe_algs, pbe_tmp)) {
OPENSSL_free(pbe_tmp);
goto err;
}
return 1;
err:
EVPerr(EVP_F_EVP_PBE_ALG_ADD_TYPE, ERR_R_MALLOC_FAILURE);
return 0;
}
int EVP_PBE_alg_add(int nid, const EVP_CIPHER *cipher, const EVP_MD *md,
EVP_PBE_KEYGEN *keygen)
{
int cipher_nid, md_nid;
if (cipher)
cipher_nid = EVP_CIPHER_nid(cipher);
else
cipher_nid = -1;
if (md)
md_nid = EVP_MD_type(md);
else
md_nid = -1;
return EVP_PBE_alg_add_type(EVP_PBE_TYPE_OUTER, nid,
cipher_nid, md_nid, keygen);
}
int EVP_PBE_find(int type, int pbe_nid,
int *pcnid, int *pmnid, EVP_PBE_KEYGEN **pkeygen)
{
EVP_PBE_CTL *pbetmp = NULL, pbelu;
int i;
if (pbe_nid == NID_undef)
return 0;
pbelu.pbe_type = type;
pbelu.pbe_nid = pbe_nid;
if (pbe_algs) {
i = sk_EVP_PBE_CTL_find(pbe_algs, &pbelu);
if (i != -1)
pbetmp = sk_EVP_PBE_CTL_value(pbe_algs, i);
}
if (pbetmp == NULL) {
pbetmp = OBJ_bsearch_pbe2(&pbelu, builtin_pbe, OSSL_NELEM(builtin_pbe));
}
if (pbetmp == NULL)
return 0;
if (pcnid)
*pcnid = pbetmp->cipher_nid;
if (pmnid)
*pmnid = pbetmp->md_nid;
if (pkeygen)
*pkeygen = pbetmp->keygen;
return 1;
}
static void free_evp_pbe_ctl(EVP_PBE_CTL *pbe)
{
OPENSSL_free(pbe);
}
void EVP_PBE_cleanup(void)
{
sk_EVP_PBE_CTL_pop_free(pbe_algs, free_evp_pbe_ctl);
pbe_algs = NULL;
}
int EVP_PBE_get(int *ptype, int *ppbe_nid, size_t num)
{
const EVP_PBE_CTL *tpbe;
if (num >= OSSL_NELEM(builtin_pbe))
return 0;
tpbe = builtin_pbe + num;
if (ptype)
*ptype = tpbe->pbe_type;
if (ppbe_nid)
*ppbe_nid = tpbe->pbe_nid;
return 1;
}
