static int cms_copy_content(BIO *out, BIO *in, unsigned int flags)
{
unsigned char buf[4096];
int r = 0, i;
BIO *tmpout = NULL;
if (out == NULL)
tmpout = BIO_new(BIO_s_null());
else if (flags & CMS_TEXT)
{
tmpout = BIO_new(BIO_s_mem());
BIO_set_mem_eof_return(tmpout, 0);
}
else
tmpout = out;
if(!tmpout)
{
CMSerr(CMS_F_CMS_COPY_CONTENT,ERR_R_MALLOC_FAILURE);
goto err;
}
for (;;)
{
i=BIO_read(in,buf,sizeof(buf));
if (i <= 0)
{
if (BIO_method_type(in) == BIO_TYPE_CIPHER)
{
if (!BIO_get_cipher_status(in))
goto err;
}
if (i < 0)
goto err;
break;
}
if (tmpout && (BIO_write(tmpout, buf, i) != i))
goto err;
}
if(flags & CMS_TEXT)
{
if(!SMIME_text(tmpout, out))
{
CMSerr(CMS_F_CMS_COPY_CONTENT,CMS_R_SMIME_TEXT_ERROR);
goto err;
}
}
r = 1;
err:
if (tmpout && (tmpout != out))
BIO_free(tmpout);
return r;
}
static int check_content(CMS_ContentInfo *cms)
{
ASN1_OCTET_STRING **pos = CMS_get0_content(cms);
if (!pos || !*pos)
{
CMSerr(CMS_F_CHECK_CONTENT, CMS_R_NO_CONTENT);
return 0;
}
return 1;
}
static void do_free_upto(BIO *f, BIO *upto)
{
if (upto)
{
BIO *tbio;
do
{
tbio = BIO_pop(f);
BIO_free(f);
f = tbio;
}
while (f != upto);
}
else
BIO_free_all(f);
}
int CMS_data(CMS_ContentInfo *cms, BIO *out, unsigned int flags)
{
BIO *cont;
int r;
if (OBJ_obj2nid(CMS_get0_type(cms)) != NID_pkcs7_data)
{
CMSerr(CMS_F_CMS_DATA, CMS_R_TYPE_NOT_DATA);
return 0;
}
cont = CMS_dataInit(cms, NULL);
if (!cont)
return 0;
r = cms_copy_content(out, cont, flags);
BIO_free_all(cont);
return r;
}
CMS_ContentInfo *CMS_data_create(BIO *in, unsigned int flags)
{
CMS_ContentInfo *cms;
cms = cms_Data_create();
if (!cms)
return NULL;
if ((flags & CMS_STREAM) || CMS_final(cms, in, NULL, flags))
return cms;
CMS_ContentInfo_free(cms);
return NULL;
}
int CMS_digest_verify(CMS_ContentInfo *cms, BIO *dcont, BIO *out,
unsigned int flags)
{
BIO *cont;
int r;
if (OBJ_obj2nid(CMS_get0_type(cms)) != NID_pkcs7_digest)
{
CMSerr(CMS_F_CMS_DIGEST_VERIFY, CMS_R_TYPE_NOT_DIGESTED_DATA);
return 0;
}
if (!dcont && !check_content(cms))
return 0;
cont = CMS_dataInit(cms, dcont);
if (!cont)
return 0;
r = cms_copy_content(out, cont, flags);
if (r)
r = cms_DigestedData_do_final(cms, cont, 1);
do_free_upto(cont, dcont);
return r;
}
CMS_ContentInfo *CMS_digest_create(BIO *in, const EVP_MD *md,
unsigned int flags)
{
CMS_ContentInfo *cms;
if (!md)
md = EVP_sha1();
cms = cms_DigestedData_create(md);
if (!cms)
return NULL;
if(!(flags & CMS_DETACHED))
CMS_set_detached(cms, 0);
if ((flags & CMS_STREAM) || CMS_final(cms, in, NULL, flags))
return cms;
CMS_ContentInfo_free(cms);
return NULL;
}
int CMS_EncryptedData_decrypt(CMS_ContentInfo *cms,
const unsigned char *key, size_t keylen,
BIO *dcont, BIO *out, unsigned int flags)
{
BIO *cont;
int r;
if (OBJ_obj2nid(CMS_get0_type(cms)) != NID_pkcs7_encrypted)
{
CMSerr(CMS_F_CMS_ENCRYPTEDDATA_DECRYPT,
CMS_R_TYPE_NOT_ENCRYPTED_DATA);
return 0;
}
if (!dcont && !check_content(cms))
return 0;
if (CMS_EncryptedData_set1_key(cms, NULL, key, keylen) <= 0)
return 0;
cont = CMS_dataInit(cms, dcont);
if (!cont)
return 0;
r = cms_copy_content(out, cont, flags);
do_free_upto(cont, dcont);
return r;
}
CMS_ContentInfo *CMS_EncryptedData_encrypt(BIO *in, const EVP_CIPHER *cipher,
const unsigned char *key, size_t keylen,
unsigned int flags)
{
CMS_ContentInfo *cms;
if (!cipher)
{
CMSerr(CMS_F_CMS_ENCRYPTEDDATA_ENCRYPT, CMS_R_NO_CIPHER);
return NULL;
}
cms = CMS_ContentInfo_new();
if (!cms)
return NULL;
if (!CMS_EncryptedData_set1_key(cms, cipher, key, keylen))
return NULL;
if(!(flags & CMS_DETACHED))
CMS_set_detached(cms, 0);
if ((flags & (CMS_STREAM|CMS_PARTIAL))
|| CMS_final(cms, in, NULL, flags))
return cms;
CMS_ContentInfo_free(cms);
return NULL;
}
int CMS_decrypt_set1_pkey(CMS_ContentInfo *cms, EVP_PKEY *pk, X509 *cert)
{
STACK_OF(CMS_RecipientInfo) *ris;
CMS_RecipientInfo *ri;
int i, r;
ris = CMS_get0_RecipientInfos(cms);
for (i = 0; i < sk_CMS_RecipientInfo_num(ris); i++)
{
ri = sk_CMS_RecipientInfo_value(ris, i);
if (CMS_RecipientInfo_type(ri) != CMS_RECIPINFO_TRANS)
continue;
if (!cert || (CMS_RecipientInfo_ktri_cert_cmp(ri, cert) == 0))
{
CMS_RecipientInfo_set0_pkey(ri, pk);
r = CMS_RecipientInfo_decrypt(cms, ri);
CMS_RecipientInfo_set0_pkey(ri, NULL);
if (r > 0)
return 1;
if (cert)
{
CMSerr(CMS_F_CMS_DECRYPT_SET1_PKEY,
CMS_R_DECRYPT_ERROR);
return 0;
}
ERR_clear_error();
}
}
CMSerr(CMS_F_CMS_DECRYPT_SET1_PKEY, CMS_R_NO_MATCHING_RECIPIENT);
return 0;
}
int CMS_decrypt_set1_key(CMS_ContentInfo *cms,
unsigned char *key, size_t keylen,
unsigned char *id, size_t idlen)
{
STACK_OF(CMS_RecipientInfo) *ris;
CMS_RecipientInfo *ri;
int i, r;
ris = CMS_get0_RecipientInfos(cms);
for (i = 0; i < sk_CMS_RecipientInfo_num(ris); i++)
{
ri = sk_CMS_RecipientInfo_value(ris, i);
if (CMS_RecipientInfo_type(ri) != CMS_RECIPINFO_KEK)
continue;
if (!id || (CMS_RecipientInfo_kekri_id_cmp(ri, id, idlen) == 0))
{
CMS_RecipientInfo_set0_key(ri, key, keylen);
r = CMS_RecipientInfo_decrypt(cms, ri);
CMS_RecipientInfo_set0_key(ri, NULL, 0);
if (r > 0)
return 1;
if (id)
{
CMSerr(CMS_F_CMS_DECRYPT_SET1_KEY,
CMS_R_DECRYPT_ERROR);
return 0;
}
ERR_clear_error();
}
}
CMSerr(CMS_F_CMS_DECRYPT_SET1_KEY, CMS_R_NO_MATCHING_RECIPIENT);
return 0;
}
int CMS_decrypt(CMS_ContentInfo *cms, EVP_PKEY *pk, X509 *cert,
BIO *dcont, BIO *out,
unsigned int flags)
{
int r;
BIO *cont;
if (OBJ_obj2nid(CMS_get0_type(cms)) != NID_pkcs7_enveloped)
{
CMSerr(CMS_F_CMS_DECRYPT, CMS_R_TYPE_NOT_ENVELOPED_DATA);
return 0;
}
if (!dcont && !check_content(cms))
return 0;
if (pk && !CMS_decrypt_set1_pkey(cms, pk, cert))
return 0;
cont = CMS_dataInit(cms, dcont);
if (!cont)
return 0;
r = cms_copy_content(out, cont, flags);
do_free_upto(cont, dcont);
return r;
}
int CMS_final(CMS_ContentInfo *cms, BIO *data, BIO *dcont, unsigned int flags)
{
BIO *cmsbio;
int ret = 0;
if (!(cmsbio = CMS_dataInit(cms, dcont)))
{
CMSerr(CMS_F_CMS_FINAL,ERR_R_MALLOC_FAILURE);
return 0;
}
SMIME_crlf_copy(data, cmsbio, flags);
(void)BIO_flush(cmsbio);
if (!CMS_dataFinal(cms, cmsbio))
{
CMSerr(CMS_F_CMS_FINAL,CMS_R_CMS_DATAFINAL_ERROR);
goto err;
}
ret = 1;
err:
do_free_upto(cmsbio, dcont);
return ret;
}
int CMS_uncompress(CMS_ContentInfo *cms, BIO *dcont, BIO *out,
unsigned int flags)
{
BIO *cont;
int r;
if (OBJ_obj2nid(CMS_get0_type(cms)) != NID_id_smime_ct_compressedData)
{
CMSerr(CMS_F_CMS_UNCOMPRESS,
CMS_R_TYPE_NOT_COMPRESSED_DATA);
return 0;
}
if (!dcont && !check_content(cms))
return 0;
cont = CMS_dataInit(cms, dcont);
if (!cont)
return 0;
r = cms_copy_content(out, cont, flags);
do_free_upto(cont, dcont);
return r;
}
CMS_ContentInfo *CMS_compress(BIO *in, int comp_nid, unsigned int flags)
{
CMS_ContentInfo *cms;
if (comp_nid <= 0)
comp_nid = NID_zlib_compression;
cms = cms_CompressedData_create(comp_nid);
if (!cms)
return NULL;
if(!(flags & CMS_DETACHED))
CMS_set_detached(cms, 0);
if ((flags & CMS_STREAM) || CMS_final(cms, in, NULL, flags))
return cms;
CMS_ContentInfo_free(cms);
return NULL;
}
int CMS_uncompress(CMS_ContentInfo *cms, BIO *dcont, BIO *out,
unsigned int flags)
{
CMSerr(CMS_F_CMS_UNCOMPRESS, CMS_R_UNSUPPORTED_COMPRESSION_ALGORITHM);
return 0;
}
CMS_ContentInfo *CMS_compress(BIO *in, int comp_nid, unsigned int flags)
{
CMSerr(CMS_F_CMS_COMPRESS, CMS_R_UNSUPPORTED_COMPRESSION_ALGORITHM);
return NULL;
}
