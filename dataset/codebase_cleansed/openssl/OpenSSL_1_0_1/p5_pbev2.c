X509_ALGOR *PKCS5_pbkdf2_set(int iter, unsigned char *salt, int saltlen,
int prf_nid, int keylen)
{
X509_ALGOR *keyfunc = NULL;
PBKDF2PARAM *kdf = NULL;
ASN1_OCTET_STRING *osalt = NULL;
if(!(kdf = PBKDF2PARAM_new()))
goto merr;
if(!(osalt = M_ASN1_OCTET_STRING_new()))
goto merr;
kdf->salt->value.octet_string = osalt;
kdf->salt->type = V_ASN1_OCTET_STRING;
if (!saltlen)
saltlen = PKCS5_SALT_LEN;
if (!(osalt->data = OPENSSL_malloc (saltlen)))
goto merr;
osalt->length = saltlen;
if (salt)
memcpy (osalt->data, salt, saltlen);
else if (RAND_pseudo_bytes (osalt->data, saltlen) < 0)
goto merr;
if(iter <= 0)
iter = PKCS5_DEFAULT_ITER;
if(!ASN1_INTEGER_set(kdf->iter, iter))
goto merr;
if(keylen > 0)
{
if(!(kdf->keylength = M_ASN1_INTEGER_new()))
goto merr;
if(!ASN1_INTEGER_set (kdf->keylength, keylen))
goto merr;
}
if (prf_nid > 0 && prf_nid != NID_hmacWithSHA1)
{
kdf->prf = X509_ALGOR_new();
if (!kdf->prf)
goto merr;
X509_ALGOR_set0(kdf->prf, OBJ_nid2obj(prf_nid),
V_ASN1_NULL, NULL);
}
keyfunc = X509_ALGOR_new();
if (!keyfunc)
goto merr;
keyfunc->algorithm = OBJ_nid2obj(NID_id_pbkdf2);
if(!(keyfunc->parameter = ASN1_TYPE_new()))
goto merr;
if(!ASN1_item_pack(kdf, ASN1_ITEM_rptr(PBKDF2PARAM),
&keyfunc->parameter->value.sequence))
goto merr;
keyfunc->parameter->type = V_ASN1_SEQUENCE;
PBKDF2PARAM_free(kdf);
return keyfunc;
merr:
ASN1err(ASN1_F_PKCS5_PBKDF2_SET,ERR_R_MALLOC_FAILURE);
PBKDF2PARAM_free(kdf);
X509_ALGOR_free(keyfunc);
return NULL;
}
