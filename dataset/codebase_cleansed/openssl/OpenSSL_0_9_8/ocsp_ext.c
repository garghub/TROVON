int OCSP_REQUEST_get_ext_count(OCSP_REQUEST *x)
{
return(X509v3_get_ext_count(x->tbsRequest->requestExtensions));
}
int OCSP_REQUEST_get_ext_by_NID(OCSP_REQUEST *x, int nid, int lastpos)
{
return(X509v3_get_ext_by_NID(x->tbsRequest->requestExtensions,nid,lastpos));
}
int OCSP_REQUEST_get_ext_by_OBJ(OCSP_REQUEST *x, ASN1_OBJECT *obj, int lastpos)
{
return(X509v3_get_ext_by_OBJ(x->tbsRequest->requestExtensions,obj,lastpos));
}
int OCSP_REQUEST_get_ext_by_critical(OCSP_REQUEST *x, int crit, int lastpos)
{
return(X509v3_get_ext_by_critical(x->tbsRequest->requestExtensions,crit,lastpos));
}
X509_EXTENSION *OCSP_REQUEST_get_ext(OCSP_REQUEST *x, int loc)
{
return(X509v3_get_ext(x->tbsRequest->requestExtensions,loc));
}
X509_EXTENSION *OCSP_REQUEST_delete_ext(OCSP_REQUEST *x, int loc)
{
return(X509v3_delete_ext(x->tbsRequest->requestExtensions,loc));
}
void *OCSP_REQUEST_get1_ext_d2i(OCSP_REQUEST *x, int nid, int *crit, int *idx)
{
return X509V3_get_d2i(x->tbsRequest->requestExtensions, nid, crit, idx);
}
int OCSP_REQUEST_add1_ext_i2d(OCSP_REQUEST *x, int nid, void *value, int crit,
unsigned long flags)
{
return X509V3_add1_i2d(&x->tbsRequest->requestExtensions, nid, value, crit, flags);
}
int OCSP_REQUEST_add_ext(OCSP_REQUEST *x, X509_EXTENSION *ex, int loc)
{
return(X509v3_add_ext(&(x->tbsRequest->requestExtensions),ex,loc) != NULL);
}
int OCSP_ONEREQ_get_ext_count(OCSP_ONEREQ *x)
{
return(X509v3_get_ext_count(x->singleRequestExtensions));
}
int OCSP_ONEREQ_get_ext_by_NID(OCSP_ONEREQ *x, int nid, int lastpos)
{
return(X509v3_get_ext_by_NID(x->singleRequestExtensions,nid,lastpos));
}
int OCSP_ONEREQ_get_ext_by_OBJ(OCSP_ONEREQ *x, ASN1_OBJECT *obj, int lastpos)
{
return(X509v3_get_ext_by_OBJ(x->singleRequestExtensions,obj,lastpos));
}
int OCSP_ONEREQ_get_ext_by_critical(OCSP_ONEREQ *x, int crit, int lastpos)
{
return(X509v3_get_ext_by_critical(x->singleRequestExtensions,crit,lastpos));
}
X509_EXTENSION *OCSP_ONEREQ_get_ext(OCSP_ONEREQ *x, int loc)
{
return(X509v3_get_ext(x->singleRequestExtensions,loc));
}
X509_EXTENSION *OCSP_ONEREQ_delete_ext(OCSP_ONEREQ *x, int loc)
{
return(X509v3_delete_ext(x->singleRequestExtensions,loc));
}
void *OCSP_ONEREQ_get1_ext_d2i(OCSP_ONEREQ *x, int nid, int *crit, int *idx)
{
return X509V3_get_d2i(x->singleRequestExtensions, nid, crit, idx);
}
int OCSP_ONEREQ_add1_ext_i2d(OCSP_ONEREQ *x, int nid, void *value, int crit,
unsigned long flags)
{
return X509V3_add1_i2d(&x->singleRequestExtensions, nid, value, crit, flags);
}
int OCSP_ONEREQ_add_ext(OCSP_ONEREQ *x, X509_EXTENSION *ex, int loc)
{
return(X509v3_add_ext(&(x->singleRequestExtensions),ex,loc) != NULL);
}
int OCSP_BASICRESP_get_ext_count(OCSP_BASICRESP *x)
{
return(X509v3_get_ext_count(x->tbsResponseData->responseExtensions));
}
int OCSP_BASICRESP_get_ext_by_NID(OCSP_BASICRESP *x, int nid, int lastpos)
{
return(X509v3_get_ext_by_NID(x->tbsResponseData->responseExtensions,nid,lastpos));
}
int OCSP_BASICRESP_get_ext_by_OBJ(OCSP_BASICRESP *x, ASN1_OBJECT *obj, int lastpos)
{
return(X509v3_get_ext_by_OBJ(x->tbsResponseData->responseExtensions,obj,lastpos));
}
int OCSP_BASICRESP_get_ext_by_critical(OCSP_BASICRESP *x, int crit, int lastpos)
{
return(X509v3_get_ext_by_critical(x->tbsResponseData->responseExtensions,crit,lastpos));
}
X509_EXTENSION *OCSP_BASICRESP_get_ext(OCSP_BASICRESP *x, int loc)
{
return(X509v3_get_ext(x->tbsResponseData->responseExtensions,loc));
}
X509_EXTENSION *OCSP_BASICRESP_delete_ext(OCSP_BASICRESP *x, int loc)
{
return(X509v3_delete_ext(x->tbsResponseData->responseExtensions,loc));
}
void *OCSP_BASICRESP_get1_ext_d2i(OCSP_BASICRESP *x, int nid, int *crit, int *idx)
{
return X509V3_get_d2i(x->tbsResponseData->responseExtensions, nid, crit, idx);
}
int OCSP_BASICRESP_add1_ext_i2d(OCSP_BASICRESP *x, int nid, void *value, int crit,
unsigned long flags)
{
return X509V3_add1_i2d(&x->tbsResponseData->responseExtensions, nid, value, crit, flags);
}
int OCSP_BASICRESP_add_ext(OCSP_BASICRESP *x, X509_EXTENSION *ex, int loc)
{
return(X509v3_add_ext(&(x->tbsResponseData->responseExtensions),ex,loc) != NULL);
}
int OCSP_SINGLERESP_get_ext_count(OCSP_SINGLERESP *x)
{
return(X509v3_get_ext_count(x->singleExtensions));
}
int OCSP_SINGLERESP_get_ext_by_NID(OCSP_SINGLERESP *x, int nid, int lastpos)
{
return(X509v3_get_ext_by_NID(x->singleExtensions,nid,lastpos));
}
int OCSP_SINGLERESP_get_ext_by_OBJ(OCSP_SINGLERESP *x, ASN1_OBJECT *obj, int lastpos)
{
return(X509v3_get_ext_by_OBJ(x->singleExtensions,obj,lastpos));
}
int OCSP_SINGLERESP_get_ext_by_critical(OCSP_SINGLERESP *x, int crit, int lastpos)
{
return(X509v3_get_ext_by_critical(x->singleExtensions,crit,lastpos));
}
X509_EXTENSION *OCSP_SINGLERESP_get_ext(OCSP_SINGLERESP *x, int loc)
{
return(X509v3_get_ext(x->singleExtensions,loc));
}
X509_EXTENSION *OCSP_SINGLERESP_delete_ext(OCSP_SINGLERESP *x, int loc)
{
return(X509v3_delete_ext(x->singleExtensions,loc));
}
void *OCSP_SINGLERESP_get1_ext_d2i(OCSP_SINGLERESP *x, int nid, int *crit, int *idx)
{
return X509V3_get_d2i(x->singleExtensions, nid, crit, idx);
}
int OCSP_SINGLERESP_add1_ext_i2d(OCSP_SINGLERESP *x, int nid, void *value, int crit,
unsigned long flags)
{
return X509V3_add1_i2d(&x->singleExtensions, nid, value, crit, flags);
}
int OCSP_SINGLERESP_add_ext(OCSP_SINGLERESP *x, X509_EXTENSION *ex, int loc)
{
return(X509v3_add_ext(&(x->singleExtensions),ex,loc) != NULL);
}
int OCSP_request_add1_nonce(OCSP_REQUEST *req, unsigned char *val, int len)
{
return ocsp_add1_nonce(&req->tbsRequest->requestExtensions, val, len);
}
int OCSP_basic_add1_nonce(OCSP_BASICRESP *resp, unsigned char *val, int len)
{
return ocsp_add1_nonce(&resp->tbsResponseData->responseExtensions, val, len);
}
int OCSP_check_nonce(OCSP_REQUEST *req, OCSP_BASICRESP *bs)
{
int req_idx, resp_idx;
X509_EXTENSION *req_ext, *resp_ext;
req_idx = OCSP_REQUEST_get_ext_by_NID(req, NID_id_pkix_OCSP_Nonce, -1);
resp_idx = OCSP_BASICRESP_get_ext_by_NID(bs, NID_id_pkix_OCSP_Nonce, -1);
if((req_idx < 0) && (resp_idx < 0))
return 2;
if((req_idx >= 0) && (resp_idx < 0))
return -1;
if((req_idx < 0) && (resp_idx >= 0))
return 3;
req_ext = OCSP_REQUEST_get_ext(req, req_idx);
resp_ext = OCSP_BASICRESP_get_ext(bs, resp_idx);
if(ASN1_OCTET_STRING_cmp(req_ext->value, resp_ext->value))
return 0;
return 1;
}
int OCSP_copy_nonce(OCSP_BASICRESP *resp, OCSP_REQUEST *req)
{
X509_EXTENSION *req_ext;
int req_idx;
req_idx = OCSP_REQUEST_get_ext_by_NID(req, NID_id_pkix_OCSP_Nonce, -1);
if (req_idx < 0) return 2;
req_ext = OCSP_REQUEST_get_ext(req, req_idx);
return OCSP_BASICRESP_add_ext(resp, req_ext, -1);
}
X509_EXTENSION *OCSP_crlID_new(char *url, long *n, char *tim)
{
X509_EXTENSION *x = NULL;
OCSP_CRLID *cid = NULL;
if (!(cid = OCSP_CRLID_new())) goto err;
if (url)
{
if (!(cid->crlUrl = ASN1_IA5STRING_new())) goto err;
if (!(ASN1_STRING_set(cid->crlUrl, url, -1))) goto err;
}
if (n)
{
if (!(cid->crlNum = ASN1_INTEGER_new())) goto err;
if (!(ASN1_INTEGER_set(cid->crlNum, *n))) goto err;
}
if (tim)
{
if (!(cid->crlTime = ASN1_GENERALIZEDTIME_new())) goto err;
if (!(ASN1_GENERALIZEDTIME_set_string(cid->crlTime, tim)))
goto err;
}
if (!(x = X509_EXTENSION_new())) goto err;
if (!(x->object = OBJ_nid2obj(NID_id_pkix_OCSP_CrlID))) goto err;
if (!(ASN1_STRING_encode_of(OCSP_CRLID,x->value,i2d_OCSP_CRLID,cid,
NULL)))
goto err;
OCSP_CRLID_free(cid);
return x;
err:
if (x) X509_EXTENSION_free(x);
if (cid) OCSP_CRLID_free(cid);
return NULL;
}
X509_EXTENSION *OCSP_accept_responses_new(char **oids)
{
int nid;
STACK_OF(ASN1_OBJECT) *sk = NULL;
ASN1_OBJECT *o = NULL;
X509_EXTENSION *x = NULL;
if (!(sk = sk_ASN1_OBJECT_new_null())) goto err;
while (oids && *oids)
{
if ((nid=OBJ_txt2nid(*oids))!=NID_undef&&(o=OBJ_nid2obj(nid)))
sk_ASN1_OBJECT_push(sk, o);
oids++;
}
if (!(x = X509_EXTENSION_new())) goto err;
if (!(x->object = OBJ_nid2obj(NID_id_pkix_OCSP_acceptableResponses)))
goto err;
if (!(ASN1_STRING_encode_of(ASN1_OBJECT,x->value,i2d_ASN1_OBJECT,NULL,
sk)))
goto err;
sk_ASN1_OBJECT_pop_free(sk, ASN1_OBJECT_free);
return x;
err:
if (x) X509_EXTENSION_free(x);
if (sk) sk_ASN1_OBJECT_pop_free(sk, ASN1_OBJECT_free);
return NULL;
}
X509_EXTENSION *OCSP_archive_cutoff_new(char* tim)
{
X509_EXTENSION *x=NULL;
ASN1_GENERALIZEDTIME *gt = NULL;
if (!(gt = ASN1_GENERALIZEDTIME_new())) goto err;
if (!(ASN1_GENERALIZEDTIME_set_string(gt, tim))) goto err;
if (!(x = X509_EXTENSION_new())) goto err;
if (!(x->object=OBJ_nid2obj(NID_id_pkix_OCSP_archiveCutoff)))goto err;
if (!(ASN1_STRING_encode_of(ASN1_GENERALIZEDTIME,x->value,
i2d_ASN1_GENERALIZEDTIME,gt,NULL))) goto err;
ASN1_GENERALIZEDTIME_free(gt);
return x;
err:
if (gt) ASN1_GENERALIZEDTIME_free(gt);
if (x) X509_EXTENSION_free(x);
return NULL;
}
X509_EXTENSION *OCSP_url_svcloc_new(X509_NAME* issuer, char **urls)
{
X509_EXTENSION *x = NULL;
ASN1_IA5STRING *ia5 = NULL;
OCSP_SERVICELOC *sloc = NULL;
ACCESS_DESCRIPTION *ad = NULL;
if (!(sloc = OCSP_SERVICELOC_new())) goto err;
if (!(sloc->issuer = X509_NAME_dup(issuer))) goto err;
if (urls && *urls && !(sloc->locator = sk_ACCESS_DESCRIPTION_new_null())) goto err;
while (urls && *urls)
{
if (!(ad = ACCESS_DESCRIPTION_new())) goto err;
if (!(ad->method=OBJ_nid2obj(NID_ad_OCSP))) goto err;
if (!(ad->location = GENERAL_NAME_new())) goto err;
if (!(ia5 = ASN1_IA5STRING_new())) goto err;
if (!ASN1_STRING_set((ASN1_STRING*)ia5, *urls, -1)) goto err;
ad->location->type = GEN_URI;
ad->location->d.ia5 = ia5;
if (!sk_ACCESS_DESCRIPTION_push(sloc->locator, ad)) goto err;
urls++;
}
if (!(x = X509_EXTENSION_new())) goto err;
if (!(x->object = OBJ_nid2obj(NID_id_pkix_OCSP_serviceLocator)))
goto err;
if (!(ASN1_STRING_encode_of(OCSP_SERVICELOC,x->value,
i2d_OCSP_SERVICELOC,sloc,NULL))) goto err;
OCSP_SERVICELOC_free(sloc);
return x;
err:
if (x) X509_EXTENSION_free(x);
if (sloc) OCSP_SERVICELOC_free(sloc);
return NULL;
}
