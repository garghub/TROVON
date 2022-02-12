int EVP_PBE_CipherInit (ASN1_OBJECT *pbe_obj, const char *pass, int passlen,
unsigned char *salt, int saltlen, int iter, EVP_CIPHER_CTX *ctx,
int en_de)
{
EVP_PBE_CTL *pbetmp, pbelu;
unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
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
i = (*pbetmp->keygen)(pass, passlen, salt, saltlen, iter,
pbetmp->cipher, pbetmp->md, key, iv);
if (!i) {
EVPerr(EVP_F_EVP_PBE_CIPHERINIT,EVP_R_KEYGEN_FAILURE);
return 0;
}
EVP_CipherInit (ctx, pbetmp->cipher, key, iv, en_de);
return 1;
}
int EVP_PBE_ALGOR_CipherInit (X509_ALGOR *algor, const char *pass,
int passlen, EVP_CIPHER_CTX *ctx, int en_de)
{
PBEPARAM *pbe;
int saltlen, iter;
unsigned char *salt, *pbuf;
pbuf = algor->parameter->value.sequence->data;
if (!(pbe = d2i_PBEPARAM (NULL, &pbuf,
algor->parameter->value.sequence->length))) {
EVPerr(EVP_F_EVP_PBE_ALGOR_CIPHERINIT,EVP_R_DECODE_ERROR);
return 0;
}
if (!pbe->iter) iter = 1;
else iter = ASN1_INTEGER_get (pbe->iter);
salt = pbe->salt->data;
saltlen = pbe->salt->length;
if (!(EVP_PBE_CipherInit (algor->algorithm, pass, passlen, salt,
saltlen, iter, ctx, en_de))) {
EVPerr(EVP_F_EVP_PBE_ALGOR_CIPHERINIT,EVP_R_EVP_PBE_CIPHERINIT_ERROR);
PBEPARAM_free(pbe);
return 0;
}
PBEPARAM_free(pbe);
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
