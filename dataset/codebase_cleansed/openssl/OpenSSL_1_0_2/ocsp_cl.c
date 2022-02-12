OCSP_ONEREQ *OCSP_request_add0_id(OCSP_REQUEST *req, OCSP_CERTID *cid)
{
OCSP_ONEREQ *one = NULL;
if (!(one = OCSP_ONEREQ_new()))
goto err;
if (one->reqCert)
OCSP_CERTID_free(one->reqCert);
one->reqCert = cid;
if (req && !sk_OCSP_ONEREQ_push(req->tbsRequest->requestList, one))
goto err;
return one;
err:
OCSP_ONEREQ_free(one);
return NULL;
}
int OCSP_request_set1_name(OCSP_REQUEST *req, X509_NAME *nm)
{
GENERAL_NAME *gen;
gen = GENERAL_NAME_new();
if (gen == NULL)
return 0;
if (!X509_NAME_set(&gen->d.directoryName, nm)) {
GENERAL_NAME_free(gen);
return 0;
}
gen->type = GEN_DIRNAME;
if (req->tbsRequest->requestorName)
GENERAL_NAME_free(req->tbsRequest->requestorName);
req->tbsRequest->requestorName = gen;
return 1;
}
int OCSP_request_add1_cert(OCSP_REQUEST *req, X509 *cert)
{
OCSP_SIGNATURE *sig;
if (!req->optionalSignature)
req->optionalSignature = OCSP_SIGNATURE_new();
sig = req->optionalSignature;
if (!sig)
return 0;
if (!cert)
return 1;
if (!sig->certs && !(sig->certs = sk_X509_new_null()))
return 0;
if (!sk_X509_push(sig->certs, cert))
return 0;
CRYPTO_add(&cert->references, 1, CRYPTO_LOCK_X509);
return 1;
}
int OCSP_response_status(OCSP_RESPONSE *resp)
{
return ASN1_ENUMERATED_get(resp->responseStatus);
}
OCSP_BASICRESP *OCSP_response_get1_basic(OCSP_RESPONSE *resp)
{
OCSP_RESPBYTES *rb;
rb = resp->responseBytes;
if (!rb) {
OCSPerr(OCSP_F_OCSP_RESPONSE_GET1_BASIC, OCSP_R_NO_RESPONSE_DATA);
return NULL;
}
if (OBJ_obj2nid(rb->responseType) != NID_id_pkix_OCSP_basic) {
OCSPerr(OCSP_F_OCSP_RESPONSE_GET1_BASIC, OCSP_R_NOT_BASIC_RESPONSE);
return NULL;
}
return ASN1_item_unpack(rb->response, ASN1_ITEM_rptr(OCSP_BASICRESP));
}
int OCSP_resp_count(OCSP_BASICRESP *bs)
{
if (!bs)
return -1;
return sk_OCSP_SINGLERESP_num(bs->tbsResponseData->responses);
}
OCSP_SINGLERESP *OCSP_resp_get0(OCSP_BASICRESP *bs, int idx)
{
if (!bs)
return NULL;
return sk_OCSP_SINGLERESP_value(bs->tbsResponseData->responses, idx);
}
int OCSP_resp_find(OCSP_BASICRESP *bs, OCSP_CERTID *id, int last)
{
int i;
STACK_OF(OCSP_SINGLERESP) *sresp;
OCSP_SINGLERESP *single;
if (!bs)
return -1;
if (last < 0)
last = 0;
else
last++;
sresp = bs->tbsResponseData->responses;
for (i = last; i < sk_OCSP_SINGLERESP_num(sresp); i++) {
single = sk_OCSP_SINGLERESP_value(sresp, i);
if (!OCSP_id_cmp(id, single->certId))
return i;
}
return -1;
}
int OCSP_single_get0_status(OCSP_SINGLERESP *single, int *reason,
ASN1_GENERALIZEDTIME **revtime,
ASN1_GENERALIZEDTIME **thisupd,
ASN1_GENERALIZEDTIME **nextupd)
{
int ret;
OCSP_CERTSTATUS *cst;
if (!single)
return -1;
cst = single->certStatus;
ret = cst->type;
if (ret == V_OCSP_CERTSTATUS_REVOKED) {
OCSP_REVOKEDINFO *rev = cst->value.revoked;
if (revtime)
*revtime = rev->revocationTime;
if (reason) {
if (rev->revocationReason)
*reason = ASN1_ENUMERATED_get(rev->revocationReason);
else
*reason = -1;
}
}
if (thisupd)
*thisupd = single->thisUpdate;
if (nextupd)
*nextupd = single->nextUpdate;
return ret;
}
int OCSP_resp_find_status(OCSP_BASICRESP *bs, OCSP_CERTID *id, int *status,
int *reason,
ASN1_GENERALIZEDTIME **revtime,
ASN1_GENERALIZEDTIME **thisupd,
ASN1_GENERALIZEDTIME **nextupd)
{
int i;
OCSP_SINGLERESP *single;
i = OCSP_resp_find(bs, id, -1);
if (i < 0)
return 0;
single = OCSP_resp_get0(bs, i);
i = OCSP_single_get0_status(single, reason, revtime, thisupd, nextupd);
if (status)
*status = i;
return 1;
}
int OCSP_check_validity(ASN1_GENERALIZEDTIME *thisupd,
ASN1_GENERALIZEDTIME *nextupd, long nsec, long maxsec)
{
int ret = 1;
time_t t_now, t_tmp;
time(&t_now);
if (!ASN1_GENERALIZEDTIME_check(thisupd)) {
OCSPerr(OCSP_F_OCSP_CHECK_VALIDITY, OCSP_R_ERROR_IN_THISUPDATE_FIELD);
ret = 0;
} else {
t_tmp = t_now + nsec;
if (X509_cmp_time(thisupd, &t_tmp) > 0) {
OCSPerr(OCSP_F_OCSP_CHECK_VALIDITY, OCSP_R_STATUS_NOT_YET_VALID);
ret = 0;
}
if (maxsec >= 0) {
t_tmp = t_now - maxsec;
if (X509_cmp_time(thisupd, &t_tmp) < 0) {
OCSPerr(OCSP_F_OCSP_CHECK_VALIDITY, OCSP_R_STATUS_TOO_OLD);
ret = 0;
}
}
}
if (!nextupd)
return ret;
if (!ASN1_GENERALIZEDTIME_check(nextupd)) {
OCSPerr(OCSP_F_OCSP_CHECK_VALIDITY, OCSP_R_ERROR_IN_NEXTUPDATE_FIELD);
ret = 0;
} else {
t_tmp = t_now - nsec;
if (X509_cmp_time(nextupd, &t_tmp) < 0) {
OCSPerr(OCSP_F_OCSP_CHECK_VALIDITY, OCSP_R_STATUS_EXPIRED);
ret = 0;
}
}
if (ASN1_STRING_cmp(nextupd, thisupd) < 0) {
OCSPerr(OCSP_F_OCSP_CHECK_VALIDITY,
OCSP_R_NEXTUPDATE_BEFORE_THISUPDATE);
ret = 0;
}
return ret;
}
