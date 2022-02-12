OCSP_RESPONSE *OCSP_sendreq_bio(BIO *b, char *path, OCSP_REQUEST *req)
{
BIO *mem = NULL;
char tmpbuf[1024];
OCSP_RESPONSE *resp = NULL;
char *p, *q, *r;
int len, retcode;
static char req_txt[] =
"POST %s HTTP/1.0\r\n\
Content-Type: application/ocsp-request\r\n\
Content-Length: %d\r\n\r\n";
len = i2d_OCSP_REQUEST(req, NULL);
if(BIO_printf(b, req_txt, path, len) < 0) {
OCSPerr(OCSP_F_OCSP_SENDREQ_BIO,OCSP_R_SERVER_WRITE_ERROR);
goto err;
}
if(i2d_OCSP_REQUEST_bio(b, req) <= 0) {
OCSPerr(OCSP_F_OCSP_SENDREQ_BIO,OCSP_R_SERVER_WRITE_ERROR);
goto err;
}
if(!(mem = BIO_new(BIO_s_mem()))) goto err;
while ((len = BIO_read(b, tmpbuf, sizeof tmpbuf))) {
if(len < 0) {
OCSPerr(OCSP_F_OCSP_SENDREQ_BIO,OCSP_R_SERVER_READ_ERROR);
goto err;
}
BIO_write(mem, tmpbuf, len);
}
if(BIO_gets(mem, tmpbuf, 512) <= 0) {
OCSPerr(OCSP_F_OCSP_SENDREQ_BIO,OCSP_R_SERVER_RESPONSE_PARSE_ERROR);
goto err;
}
for(p = tmpbuf; *p && !isspace((unsigned char)*p); p++) continue;
if(!*p) {
OCSPerr(OCSP_F_OCSP_SENDREQ_BIO,OCSP_R_SERVER_RESPONSE_PARSE_ERROR);
goto err;
}
while(*p && isspace((unsigned char)*p)) p++;
if(!*p) {
OCSPerr(OCSP_F_OCSP_SENDREQ_BIO,OCSP_R_SERVER_RESPONSE_PARSE_ERROR);
goto err;
}
for(q = p; *q && !isspace((unsigned char)*q); q++) continue;
if(!*q) {
OCSPerr(OCSP_F_OCSP_SENDREQ_BIO,OCSP_R_SERVER_RESPONSE_PARSE_ERROR);
goto err;
}
*q++ = 0;
retcode = strtoul(p, &r, 10);
if(*r) goto err;
while(*q && isspace((unsigned char)*q)) q++;
if(*q) {
for(r = q + strlen(q) - 1; isspace((unsigned char)*r); r--) *r = 0;
}
if(retcode != 200) {
OCSPerr(OCSP_F_OCSP_SENDREQ_BIO,OCSP_R_SERVER_RESPONSE_ERROR);
if(!*q) {
ERR_add_error_data(2, "Code=", p);
}
else {
ERR_add_error_data(4, "Code=", p, ",Reason=", q);
}
goto err;
}
while(BIO_gets(mem, tmpbuf, 512) > 0)
{
for(p = tmpbuf; *p && isspace((unsigned char)*p); p++) continue;
if(!*p) break;
}
if(*p) {
OCSPerr(OCSP_F_OCSP_SENDREQ_BIO,OCSP_R_NO_CONTENT);
goto err;
}
if(!(resp = d2i_OCSP_RESPONSE_bio(mem, NULL))) {
OCSPerr(OCSP_F_OCSP_SENDREQ_BIO,ERR_R_NESTED_ASN1_ERROR);
goto err;
}
err:
BIO_free(mem);
return resp;
}
