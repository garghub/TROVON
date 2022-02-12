int i2d_PBE2PARAM(PBE2PARAM *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->keyfunc, i2d_X509_ALGOR);
M_ASN1_I2D_len (a->encryption, i2d_X509_ALGOR);
M_ASN1_I2D_seq_total ();
M_ASN1_I2D_put (a->keyfunc, i2d_X509_ALGOR);
M_ASN1_I2D_put (a->encryption, i2d_X509_ALGOR);
M_ASN1_I2D_finish();
}
PBE2PARAM *PBE2PARAM_new(void)
{
PBE2PARAM *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, PBE2PARAM);
M_ASN1_New(ret->keyfunc,X509_ALGOR_new);
M_ASN1_New(ret->encryption,X509_ALGOR_new);
return (ret);
M_ASN1_New_Error(ASN1_F_PBE2PARAM_NEW);
}
PBE2PARAM *d2i_PBE2PARAM(PBE2PARAM **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,PBE2PARAM *,PBE2PARAM_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get (ret->keyfunc, d2i_X509_ALGOR);
M_ASN1_D2I_get (ret->encryption, d2i_X509_ALGOR);
M_ASN1_D2I_Finish(a, PBE2PARAM_free, ASN1_F_D2I_PBE2PARAM);
}
void PBE2PARAM_free (PBE2PARAM *a)
{
if(a==NULL) return;
X509_ALGOR_free(a->keyfunc);
X509_ALGOR_free(a->encryption);
Free (a);
}
int i2d_PBKDF2PARAM(PBKDF2PARAM *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->salt, i2d_ASN1_TYPE);
M_ASN1_I2D_len (a->iter, i2d_ASN1_INTEGER);
M_ASN1_I2D_len (a->keylength, i2d_ASN1_INTEGER);
M_ASN1_I2D_len (a->prf, i2d_X509_ALGOR);
M_ASN1_I2D_seq_total ();
M_ASN1_I2D_put (a->salt, i2d_ASN1_TYPE);
M_ASN1_I2D_put (a->iter, i2d_ASN1_INTEGER);
M_ASN1_I2D_put (a->keylength, i2d_ASN1_INTEGER);
M_ASN1_I2D_put (a->prf, i2d_X509_ALGOR);
M_ASN1_I2D_finish();
}
PBKDF2PARAM *PBKDF2PARAM_new(void)
{
PBKDF2PARAM *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, PBKDF2PARAM);
M_ASN1_New(ret->salt, ASN1_TYPE_new);
M_ASN1_New(ret->iter, M_ASN1_INTEGER_new);
ret->keylength = NULL;
ret->prf = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_PBKDF2PARAM_NEW);
}
PBKDF2PARAM *d2i_PBKDF2PARAM(PBKDF2PARAM **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,PBKDF2PARAM *,PBKDF2PARAM_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get (ret->salt, d2i_ASN1_TYPE);
M_ASN1_D2I_get (ret->iter, d2i_ASN1_INTEGER);
M_ASN1_D2I_get_opt (ret->keylength, d2i_ASN1_INTEGER, V_ASN1_INTEGER);
M_ASN1_D2I_get_opt (ret->prf, d2i_X509_ALGOR, V_ASN1_SEQUENCE);
M_ASN1_D2I_Finish(a, PBKDF2PARAM_free, ASN1_F_D2I_PBKDF2PARAM);
}
void PBKDF2PARAM_free (PBKDF2PARAM *a)
{
if(a==NULL) return;
ASN1_TYPE_free(a->salt);
M_ASN1_INTEGER_free(a->iter);
M_ASN1_INTEGER_free(a->keylength);
X509_ALGOR_free(a->prf);
Free (a);
}
X509_ALGOR *PKCS5_pbe2_set(const EVP_CIPHER *cipher, int iter,
unsigned char *salt, int saltlen)
{
X509_ALGOR *scheme = NULL, *kalg = NULL, *ret = NULL;
int alg_nid;
EVP_CIPHER_CTX ctx;
unsigned char iv[EVP_MAX_IV_LENGTH];
PBKDF2PARAM *kdf = NULL;
PBE2PARAM *pbe2 = NULL;
ASN1_OCTET_STRING *osalt = NULL;
ASN1_OBJECT *obj;
alg_nid = EVP_CIPHER_type(cipher);
if(alg_nid == NID_undef) {
ASN1err(ASN1_F_PKCS5_PBE2_SET,
ASN1_R_CIPHER_HAS_NO_OBJECT_IDENTIFIER);
goto err;
}
obj = OBJ_nid2obj(alg_nid);
if(!(pbe2 = PBE2PARAM_new())) goto merr;
scheme = pbe2->encryption;
scheme->algorithm = obj;
if(!(scheme->parameter = ASN1_TYPE_new())) goto merr;
RAND_pseudo_bytes(iv, EVP_CIPHER_iv_length(cipher));
EVP_CipherInit(&ctx, cipher, NULL, iv, 0);
if(EVP_CIPHER_param_to_asn1(&ctx, scheme->parameter) < 0) {
ASN1err(ASN1_F_PKCS5_PBE2_SET,
ASN1_R_ERROR_SETTING_CIPHER_PARAMS);
goto err;
}
EVP_CIPHER_CTX_cleanup(&ctx);
if(!(kdf = PBKDF2PARAM_new())) goto merr;
if(!(osalt = M_ASN1_OCTET_STRING_new())) goto merr;
if (!saltlen) saltlen = PKCS5_SALT_LEN;
if (!(osalt->data = Malloc (saltlen))) goto merr;
osalt->length = saltlen;
if (salt) memcpy (osalt->data, salt, saltlen);
else if (RAND_bytes (osalt->data, saltlen) <= 0) goto merr;
if(iter <= 0) iter = PKCS5_DEFAULT_ITER;
if(!ASN1_INTEGER_set(kdf->iter, iter)) goto merr;
kdf->salt->value.octet_string = osalt;
kdf->salt->type = V_ASN1_OCTET_STRING;
osalt = NULL;
if(alg_nid == NID_rc2_cbc) {
if(!(kdf->keylength = M_ASN1_INTEGER_new())) goto merr;
if(!ASN1_INTEGER_set (kdf->keylength,
EVP_CIPHER_key_length(cipher))) goto merr;
}
pbe2->keyfunc->algorithm = OBJ_nid2obj(NID_id_pbkdf2);
if(!(pbe2->keyfunc->parameter = ASN1_TYPE_new())) goto merr;
if(!ASN1_pack_string(kdf, i2d_PBKDF2PARAM,
&pbe2->keyfunc->parameter->value.sequence)) goto merr;
pbe2->keyfunc->parameter->type = V_ASN1_SEQUENCE;
PBKDF2PARAM_free(kdf);
kdf = NULL;
if(!(ret = X509_ALGOR_new())) goto merr;
if(!(ret->parameter = ASN1_TYPE_new())) goto merr;
ret->algorithm = OBJ_nid2obj(NID_pbes2);
if(!ASN1_pack_string(pbe2, i2d_PBE2PARAM,
&ret->parameter->value.sequence)) goto merr;
ret->parameter->type = V_ASN1_SEQUENCE;
PBE2PARAM_free(pbe2);
pbe2 = NULL;
return ret;
merr:
ASN1err(ASN1_F_PKCS5_PBE2_SET,ERR_R_MALLOC_FAILURE);
err:
PBE2PARAM_free(pbe2);
M_ASN1_OCTET_STRING_free(osalt);
PBKDF2PARAM_free(kdf);
X509_ALGOR_free(kalg);
X509_ALGOR_free(ret);
return NULL;
}
