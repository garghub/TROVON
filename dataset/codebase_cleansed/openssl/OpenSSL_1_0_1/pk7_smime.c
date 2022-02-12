int PKCS7_final(PKCS7 *p7, BIO *data, int flags)
{
BIO *p7bio;
int ret = 0;
if (!(p7bio = PKCS7_dataInit(p7, NULL)))
{
PKCS7err(PKCS7_F_PKCS7_FINAL,ERR_R_MALLOC_FAILURE);
return 0;
}
SMIME_crlf_copy(data, p7bio, flags);
(void)BIO_flush(p7bio);
if (!PKCS7_dataFinal(p7,p7bio))
{
PKCS7err(PKCS7_F_PKCS7_FINAL,PKCS7_R_PKCS7_DATASIGN);
goto err;
}
ret = 1;
err:
BIO_free_all(p7bio);
return ret;
}
PKCS7_SIGNER_INFO *PKCS7_sign_add_signer(PKCS7 *p7, X509 *signcert,
EVP_PKEY *pkey, const EVP_MD *md,
int flags)
{
PKCS7_SIGNER_INFO *si = NULL;
STACK_OF(X509_ALGOR) *smcap = NULL;
if(!X509_check_private_key(signcert, pkey))
{
PKCS7err(PKCS7_F_PKCS7_SIGN_ADD_SIGNER,
PKCS7_R_PRIVATE_KEY_DOES_NOT_MATCH_CERTIFICATE);
return NULL;
}
if (!(si = PKCS7_add_signature(p7,signcert,pkey, md)))
{
PKCS7err(PKCS7_F_PKCS7_SIGN_ADD_SIGNER,
PKCS7_R_PKCS7_ADD_SIGNATURE_ERROR);
return NULL;
}
if(!(flags & PKCS7_NOCERTS))
{
if (!PKCS7_add_certificate(p7, signcert))
goto err;
}
if(!(flags & PKCS7_NOATTR))
{
if (!PKCS7_add_attrib_content_type(si, NULL))
goto err;
if(!(flags & PKCS7_NOSMIMECAP))
{
if(!(smcap = sk_X509_ALGOR_new_null()))
{
PKCS7err(PKCS7_F_PKCS7_SIGN_ADD_SIGNER,
ERR_R_MALLOC_FAILURE);
goto err;
}
if (!add_cipher_smcap(smcap, NID_aes_256_cbc, -1)
|| !add_digest_smcap(smcap, NID_id_GostR3411_94, -1)
|| !add_cipher_smcap(smcap, NID_id_Gost28147_89, -1)
|| !add_cipher_smcap(smcap, NID_aes_192_cbc, -1)
|| !add_cipher_smcap(smcap, NID_aes_128_cbc, -1)
|| !add_cipher_smcap(smcap, NID_des_ede3_cbc, -1)
|| !add_cipher_smcap(smcap, NID_rc2_cbc, 128)
|| !add_cipher_smcap(smcap, NID_rc2_cbc, 64)
|| !add_cipher_smcap(smcap, NID_des_cbc, -1)
|| !add_cipher_smcap(smcap, NID_rc2_cbc, 40)
|| !PKCS7_add_attrib_smimecap (si, smcap))
goto err;
sk_X509_ALGOR_pop_free(smcap, X509_ALGOR_free);
smcap = NULL;
}
if (flags & PKCS7_REUSE_DIGEST)
{
if (!pkcs7_copy_existing_digest(p7, si))
goto err;
if (!(flags & PKCS7_PARTIAL) &&
!PKCS7_SIGNER_INFO_sign(si))
goto err;
}
}
return si;
err:
if (smcap)
sk_X509_ALGOR_pop_free(smcap, X509_ALGOR_free);
return NULL;
}
static int pkcs7_copy_existing_digest(PKCS7 *p7, PKCS7_SIGNER_INFO *si)
{
int i;
STACK_OF(PKCS7_SIGNER_INFO) *sinfos;
PKCS7_SIGNER_INFO *sitmp;
ASN1_OCTET_STRING *osdig = NULL;
sinfos = PKCS7_get_signer_info(p7);
for (i = 0; i < sk_PKCS7_SIGNER_INFO_num(sinfos); i++)
{
sitmp = sk_PKCS7_SIGNER_INFO_value(sinfos, i);
if (si == sitmp)
break;
if (sk_X509_ATTRIBUTE_num(sitmp->auth_attr) <= 0)
continue;
if (!OBJ_cmp(si->digest_alg->algorithm,
sitmp->digest_alg->algorithm))
{
osdig = PKCS7_digest_from_attributes(sitmp->auth_attr);
break;
}
}
if (osdig)
return PKCS7_add1_attrib_digest(si, osdig->data, osdig->length);
PKCS7err(PKCS7_F_PKCS7_COPY_EXISTING_DIGEST,
PKCS7_R_NO_MATCHING_DIGEST_TYPE_FOUND);
return 0;
}
