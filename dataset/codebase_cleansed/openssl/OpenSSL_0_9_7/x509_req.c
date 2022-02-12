X509_REQ *X509_to_X509_REQ(X509 *x, EVP_PKEY *pkey, const EVP_MD *md)
{
X509_REQ *ret;
X509_REQ_INFO *ri;
int i;
EVP_PKEY *pktmp;
ret=X509_REQ_new();
if (ret == NULL)
{
X509err(X509_F_X509_TO_X509_REQ,ERR_R_MALLOC_FAILURE);
goto err;
}
ri=ret->req_info;
ri->version->length=1;
ri->version->data=(unsigned char *)OPENSSL_malloc(1);
if (ri->version->data == NULL) goto err;
ri->version->data[0]=0;
if (!X509_REQ_set_subject_name(ret,X509_get_subject_name(x)))
goto err;
pktmp = X509_get_pubkey(x);
i=X509_REQ_set_pubkey(ret,pktmp);
EVP_PKEY_free(pktmp);
if (!i) goto err;
if (pkey != NULL)
{
if (!X509_REQ_sign(ret,pkey,md))
goto err;
}
return(ret);
err:
X509_REQ_free(ret);
return(NULL);
}
EVP_PKEY *X509_REQ_get_pubkey(X509_REQ *req)
{
if ((req == NULL) || (req->req_info == NULL))
return(NULL);
return(X509_PUBKEY_get(req->req_info->pubkey));
}
int X509_REQ_extension_nid(int req_nid)
{
int i, nid;
for(i = 0; ; i++) {
nid = ext_nids[i];
if(nid == NID_undef) return 0;
else if (req_nid == nid) return 1;
}
}
int *X509_REQ_get_extension_nids(void)
{
return ext_nids;
}
void X509_REQ_set_extension_nids(int *nids)
{
ext_nids = nids;
}
int X509_REQ_get_attr_count(const X509_REQ *req)
{
return X509at_get_attr_count(req->req_info->attributes);
}
int X509_REQ_get_attr_by_NID(const X509_REQ *req, int nid,
int lastpos)
{
return X509at_get_attr_by_NID(req->req_info->attributes, nid, lastpos);
}
int X509_REQ_get_attr_by_OBJ(const X509_REQ *req, ASN1_OBJECT *obj,
int lastpos)
{
return X509at_get_attr_by_OBJ(req->req_info->attributes, obj, lastpos);
}
X509_ATTRIBUTE *X509_REQ_get_attr(const X509_REQ *req, int loc)
{
return X509at_get_attr(req->req_info->attributes, loc);
}
X509_ATTRIBUTE *X509_REQ_delete_attr(X509_REQ *req, int loc)
{
return X509at_delete_attr(req->req_info->attributes, loc);
}
int X509_REQ_add1_attr(X509_REQ *req, X509_ATTRIBUTE *attr)
{
if(X509at_add1_attr(&req->req_info->attributes, attr)) return 1;
return 0;
}
int X509_REQ_add1_attr_by_OBJ(X509_REQ *req,
const ASN1_OBJECT *obj, int type,
const unsigned char *bytes, int len)
{
if(X509at_add1_attr_by_OBJ(&req->req_info->attributes, obj,
type, bytes, len)) return 1;
return 0;
}
int X509_REQ_add1_attr_by_NID(X509_REQ *req,
int nid, int type,
const unsigned char *bytes, int len)
{
if(X509at_add1_attr_by_NID(&req->req_info->attributes, nid,
type, bytes, len)) return 1;
return 0;
}
int X509_REQ_add1_attr_by_txt(X509_REQ *req,
const char *attrname, int type,
const unsigned char *bytes, int len)
{
if(X509at_add1_attr_by_txt(&req->req_info->attributes, attrname,
type, bytes, len)) return 1;
return 0;
}
