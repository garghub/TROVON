OCSP_CERTID *OCSP_cert_to_id(const EVP_MD *dgst, X509 *subject, X509 *issuer)
{
X509_NAME *iname;
ASN1_INTEGER *serial;
ASN1_BIT_STRING *ikey;
#ifndef OPENSSL_NO_SHA1
if (!dgst)
dgst = EVP_sha1();
#endif
if (subject) {
iname = X509_get_issuer_name(subject);
serial = X509_get_serialNumber(subject);
} else {
iname = X509_get_subject_name(issuer);
serial = NULL;
}
ikey = X509_get0_pubkey_bitstr(issuer);
return OCSP_cert_id_new(dgst, iname, ikey, serial);
}
OCSP_CERTID *OCSP_cert_id_new(const EVP_MD *dgst,
X509_NAME *issuerName,
ASN1_BIT_STRING *issuerKey,
ASN1_INTEGER *serialNumber)
{
int nid;
unsigned int i;
X509_ALGOR *alg;
OCSP_CERTID *cid = NULL;
unsigned char md[EVP_MAX_MD_SIZE];
if (!(cid = OCSP_CERTID_new()))
goto err;
alg = cid->hashAlgorithm;
if (alg->algorithm != NULL)
ASN1_OBJECT_free(alg->algorithm);
if ((nid = EVP_MD_type(dgst)) == NID_undef) {
OCSPerr(OCSP_F_OCSP_CERT_ID_NEW, OCSP_R_UNKNOWN_NID);
goto err;
}
if (!(alg->algorithm = OBJ_nid2obj(nid)))
goto err;
if ((alg->parameter = ASN1_TYPE_new()) == NULL)
goto err;
alg->parameter->type = V_ASN1_NULL;
if (!X509_NAME_digest(issuerName, dgst, md, &i))
goto digerr;
if (!(ASN1_OCTET_STRING_set(cid->issuerNameHash, md, i)))
goto err;
if (!EVP_Digest(issuerKey->data, issuerKey->length, md, &i, dgst, NULL))
goto err;
if (!(ASN1_OCTET_STRING_set(cid->issuerKeyHash, md, i)))
goto err;
if (serialNumber) {
ASN1_INTEGER_free(cid->serialNumber);
if (!(cid->serialNumber = ASN1_INTEGER_dup(serialNumber)))
goto err;
}
return cid;
digerr:
OCSPerr(OCSP_F_OCSP_CERT_ID_NEW, OCSP_R_DIGEST_ERR);
err:
if (cid)
OCSP_CERTID_free(cid);
return NULL;
}
int OCSP_id_issuer_cmp(OCSP_CERTID *a, OCSP_CERTID *b)
{
int ret;
ret = OBJ_cmp(a->hashAlgorithm->algorithm, b->hashAlgorithm->algorithm);
if (ret)
return ret;
ret = ASN1_OCTET_STRING_cmp(a->issuerNameHash, b->issuerNameHash);
if (ret)
return ret;
return ASN1_OCTET_STRING_cmp(a->issuerKeyHash, b->issuerKeyHash);
}
int OCSP_id_cmp(OCSP_CERTID *a, OCSP_CERTID *b)
{
int ret;
ret = OCSP_id_issuer_cmp(a, b);
if (ret)
return ret;
return ASN1_INTEGER_cmp(a->serialNumber, b->serialNumber);
}
int OCSP_parse_url(const char *url, char **phost, char **pport, char **ppath,
int *pssl)
{
char *p, *buf;
char *host, *port;
*phost = NULL;
*pport = NULL;
*ppath = NULL;
buf = BUF_strdup(url);
if (!buf)
goto mem_err;
p = strchr(buf, ':');
if (!p)
goto parse_err;
*(p++) = '\0';
if (!strcmp(buf, "http")) {
*pssl = 0;
port = "80";
} else if (!strcmp(buf, "https")) {
*pssl = 1;
port = "443";
} else
goto parse_err;
if ((p[0] != '/') || (p[1] != '/'))
goto parse_err;
p += 2;
host = p;
p = strchr(p, '/');
if (!p)
*ppath = BUF_strdup("/");
else {
*ppath = BUF_strdup(p);
*p = '\0';
}
if (!*ppath)
goto mem_err;
p = host;
if (host[0] == '[') {
host++;
p = strchr(host, ']');
if (!p)
goto parse_err;
*p = '\0';
p++;
}
if ((p = strchr(p, ':'))) {
*p = 0;
port = p + 1;
} else {
if (*pssl)
port = "443";
else
port = "80";
}
*pport = BUF_strdup(port);
if (!*pport)
goto mem_err;
*phost = BUF_strdup(host);
if (!*phost)
goto mem_err;
OPENSSL_free(buf);
return 1;
mem_err:
OCSPerr(OCSP_F_OCSP_PARSE_URL, ERR_R_MALLOC_FAILURE);
goto err;
parse_err:
OCSPerr(OCSP_F_OCSP_PARSE_URL, OCSP_R_ERROR_PARSING_URL);
err:
if (buf)
OPENSSL_free(buf);
if (*ppath)
OPENSSL_free(*ppath);
if (*pport)
OPENSSL_free(*pport);
if (*phost)
OPENSSL_free(*phost);
return 0;
}
