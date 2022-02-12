int i2d_PBEPARAM(PBEPARAM *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->salt, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_len (a->iter, i2d_ASN1_INTEGER);
M_ASN1_I2D_seq_total ();
M_ASN1_I2D_put (a->salt, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_put (a->iter, i2d_ASN1_INTEGER);
M_ASN1_I2D_finish();
}
PBEPARAM *PBEPARAM_new(void)
{
PBEPARAM *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, PBEPARAM);
M_ASN1_New(ret->iter,ASN1_INTEGER_new);
M_ASN1_New(ret->salt,ASN1_OCTET_STRING_new);
return (ret);
M_ASN1_New_Error(ASN1_F_PBEPARAM_NEW);
}
PBEPARAM *d2i_PBEPARAM(PBEPARAM **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,PBEPARAM *,PBEPARAM_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get (ret->salt, d2i_ASN1_OCTET_STRING);
M_ASN1_D2I_get (ret->iter, d2i_ASN1_INTEGER);
M_ASN1_D2I_Finish(a, PBEPARAM_free, ASN1_F_D2I_PBEPARAM);
}
void PBEPARAM_free (PBEPARAM *a)
{
if(a==NULL) return;
ASN1_OCTET_STRING_free(a->salt);
ASN1_INTEGER_free (a->iter);
Free ((char *)a);
}
X509_ALGOR *PKCS5_pbe_set(int alg, int iter, unsigned char *salt,
int saltlen)
{
PBEPARAM *pbe;
ASN1_OBJECT *al;
X509_ALGOR *algor;
ASN1_TYPE *astype;
if (!(pbe = PBEPARAM_new ())) {
ASN1err(ASN1_F_ASN1_PBE_SET,ERR_R_MALLOC_FAILURE);
return NULL;
}
if(iter <= 0) iter = PKCS5_DEFAULT_ITER;
ASN1_INTEGER_set (pbe->iter, iter);
if (!saltlen) saltlen = PKCS5_SALT_LEN;
if (!(pbe->salt->data = Malloc (saltlen))) {
ASN1err(ASN1_F_ASN1_PBE_SET,ERR_R_MALLOC_FAILURE);
return NULL;
}
pbe->salt->length = saltlen;
if (salt) memcpy (pbe->salt->data, salt, saltlen);
else RAND_bytes (pbe->salt->data, saltlen);
if (!(astype = ASN1_TYPE_new())) {
ASN1err(ASN1_F_ASN1_PBE_SET,ERR_R_MALLOC_FAILURE);
return NULL;
}
astype->type = V_ASN1_SEQUENCE;
if(!ASN1_pack_string(pbe, i2d_PBEPARAM, &astype->value.sequence)) {
ASN1err(ASN1_F_ASN1_PBE_SET,ERR_R_MALLOC_FAILURE);
return NULL;
}
PBEPARAM_free (pbe);
al = OBJ_nid2obj(alg);
if (!(algor = X509_ALGOR_new())) {
ASN1err(ASN1_F_ASN1_PBE_SET,ERR_R_MALLOC_FAILURE);
return NULL;
}
ASN1_OBJECT_free(algor->algorithm);
algor->algorithm = al;
algor->parameter = astype;
return (algor);
}
