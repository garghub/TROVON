int EVP_PBE_CipherInit (ASN1_OBJECT *pbe_obj, const char *pass, int passlen,
ASN1_TYPE *param, EVP_CIPHER_CTX *ctx, int en_de)
{
EVP_PBE_CTL *pbetmp, pbelu;
int i;
pbelu.pbe_nid = OBJ_obj2nid(pbe_obj);
if (pbelu.pbe_nid != NID_undef) i = sk_find(pbe_algs, (char *)&pbelu);
else i = -1;
if (i == -1) {
char obj_tmp[80];
EVPerr(EVP_F_EVP_PBE_CIPHERINIT,EVP_R_UNKNOWN_PBE_ALGORITHM);
if (!pbe_obj) strcpy (obj_tmp, "NULL");
else i2t_ASN1_OBJECT(obj_tmp, 80, pbe_obj);
ERR_add_error_data(2, "TYPE=", obj_tmp);
return 0;
}
if (passlen == -1) passlen = strlen(pass);
pbetmp = (EVP_PBE_CTL *)sk_value (pbe_algs, i);
i = (*pbetmp->keygen)(ctx, pass, passlen, param, pbetmp->cipher,
pbetmp->md, en_de);
if (!i) {
EVPerr(EVP_F_EVP_PBE_CIPHERINIT,EVP_R_KEYGEN_FAILURE);
return 0;
}
return 1;
}
static int pbe_cmp (EVP_PBE_CTL **pbe1, EVP_PBE_CTL **pbe2)
{
return ((*pbe1)->pbe_nid - (*pbe2)->pbe_nid);
}
int EVP_PBE_alg_add (int nid, EVP_CIPHER *cipher, EVP_MD *md,
EVP_PBE_KEYGEN *keygen)
{
EVP_PBE_CTL *pbe_tmp;
if (!pbe_algs) pbe_algs = sk_new (pbe_cmp);
if (!(pbe_tmp = (EVP_PBE_CTL*) Malloc (sizeof(EVP_PBE_CTL)))) {
EVPerr(EVP_F_EVP_PBE_ALG_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
pbe_tmp->pbe_nid = nid;
pbe_tmp->cipher = cipher;
pbe_tmp->md = md;
pbe_tmp->keygen = keygen;
sk_push (pbe_algs, (char *)pbe_tmp);
return 1;
}
void EVP_PBE_cleanup(void)
{
sk_pop_free(pbe_algs, FreeFunc);
pbe_algs = NULL;
}
