OCSP_REQ_CTX *OCSP_REQ_CTX_new(BIO *io, int maxline)
{
OCSP_REQ_CTX *rctx;
rctx = OPENSSL_malloc(sizeof(OCSP_REQ_CTX));
if (!rctx)
return NULL;
rctx->state = OHS_ERROR;
rctx->max_resp_len = OCSP_MAX_RESP_LENGTH;
rctx->mem = BIO_new(BIO_s_mem());
rctx->io = io;
rctx->asn1_len = 0;
if (maxline > 0)
rctx->iobuflen = maxline;
else
rctx->iobuflen = OCSP_MAX_LINE_LEN;
rctx->iobuf = OPENSSL_malloc(rctx->iobuflen);
if (!rctx->iobuf || !rctx->mem) {
OCSP_REQ_CTX_free(rctx);
return NULL;
}
return rctx;
}
void OCSP_REQ_CTX_free(OCSP_REQ_CTX *rctx)
{
if (rctx->mem)
BIO_free(rctx->mem);
if (rctx->iobuf)
OPENSSL_free(rctx->iobuf);
OPENSSL_free(rctx);
}
BIO *OCSP_REQ_CTX_get0_mem_bio(OCSP_REQ_CTX *rctx)
{
return rctx->mem;
}
void OCSP_set_max_response_length(OCSP_REQ_CTX *rctx, unsigned long len)
{
if (len == 0)
rctx->max_resp_len = OCSP_MAX_RESP_LENGTH;
else
rctx->max_resp_len = len;
}
int OCSP_REQ_CTX_i2d(OCSP_REQ_CTX *rctx, const ASN1_ITEM *it, ASN1_VALUE *val)
{
static const char req_hdr[] =
"Content-Type: application/ocsp-request\r\n"
"Content-Length: %d\r\n\r\n";
int reqlen = ASN1_item_i2d(val, NULL, it);
if (BIO_printf(rctx->mem, req_hdr, reqlen) <= 0)
return 0;
if (ASN1_item_i2d_bio(it, rctx->mem, val) <= 0)
return 0;
rctx->state = OHS_ASN1_WRITE_INIT;
return 1;
}
int OCSP_REQ_CTX_nbio_d2i(OCSP_REQ_CTX *rctx,
ASN1_VALUE **pval, const ASN1_ITEM *it)
{
int rv, len;
const unsigned char *p;
rv = OCSP_REQ_CTX_nbio(rctx);
if (rv != 1)
return rv;
len = BIO_get_mem_data(rctx->mem, &p);
*pval = ASN1_item_d2i(NULL, &p, len, it);
if (*pval == NULL) {
rctx->state = OHS_ERROR;
return 0;
}
return 1;
}
int OCSP_REQ_CTX_http(OCSP_REQ_CTX *rctx, const char *op, const char *path)
{
static const char http_hdr[] = "%s %s HTTP/1.0\r\n";
if (!path)
path = "/";
if (BIO_printf(rctx->mem, http_hdr, op, path) <= 0)
return 0;
rctx->state = OHS_HTTP_HEADER;
return 1;
}
int OCSP_REQ_CTX_set1_req(OCSP_REQ_CTX *rctx, OCSP_REQUEST *req)
{
return OCSP_REQ_CTX_i2d(rctx, ASN1_ITEM_rptr(OCSP_REQUEST),
(ASN1_VALUE *)req);
}
int OCSP_REQ_CTX_add1_header(OCSP_REQ_CTX *rctx,
const char *name, const char *value)
{
if (!name)
return 0;
if (BIO_puts(rctx->mem, name) <= 0)
return 0;
if (value) {
if (BIO_write(rctx->mem, ": ", 2) != 2)
return 0;
if (BIO_puts(rctx->mem, value) <= 0)
return 0;
}
if (BIO_write(rctx->mem, "\r\n", 2) != 2)
return 0;
rctx->state = OHS_HTTP_HEADER;
return 1;
}
OCSP_REQ_CTX *OCSP_sendreq_new(BIO *io, const char *path, OCSP_REQUEST *req,
int maxline)
{
OCSP_REQ_CTX *rctx = NULL;
rctx = OCSP_REQ_CTX_new(io, maxline);
if (!rctx)
return NULL;
if (!OCSP_REQ_CTX_http(rctx, "POST", path))
goto err;
if (req && !OCSP_REQ_CTX_set1_req(rctx, req))
goto err;
return rctx;
err:
OCSP_REQ_CTX_free(rctx);
return NULL;
}
static int parse_http_line1(char *line)
{
int retcode;
char *p, *q, *r;
for (p = line; *p && !isspace((unsigned char)*p); p++)
continue;
if (!*p) {
OCSPerr(OCSP_F_PARSE_HTTP_LINE1, OCSP_R_SERVER_RESPONSE_PARSE_ERROR);
return 0;
}
while (*p && isspace((unsigned char)*p))
p++;
if (!*p) {
OCSPerr(OCSP_F_PARSE_HTTP_LINE1, OCSP_R_SERVER_RESPONSE_PARSE_ERROR);
return 0;
}
for (q = p; *q && !isspace((unsigned char)*q); q++)
continue;
if (!*q) {
OCSPerr(OCSP_F_PARSE_HTTP_LINE1, OCSP_R_SERVER_RESPONSE_PARSE_ERROR);
return 0;
}
*q++ = 0;
retcode = strtoul(p, &r, 10);
if (*r)
return 0;
while (*q && isspace((unsigned char)*q))
q++;
if (*q) {
for (r = q + strlen(q) - 1; isspace((unsigned char)*r); r--)
*r = 0;
}
if (retcode != 200) {
OCSPerr(OCSP_F_PARSE_HTTP_LINE1, OCSP_R_SERVER_RESPONSE_ERROR);
if (!*q)
ERR_add_error_data(2, "Code=", p);
else
ERR_add_error_data(4, "Code=", p, ",Reason=", q);
return 0;
}
return 1;
}
int OCSP_REQ_CTX_nbio(OCSP_REQ_CTX *rctx)
{
int i, n;
const unsigned char *p;
next_io:
if (!(rctx->state & OHS_NOREAD)) {
n = BIO_read(rctx->io, rctx->iobuf, rctx->iobuflen);
if (n <= 0) {
if (BIO_should_retry(rctx->io))
return -1;
return 0;
}
if (BIO_write(rctx->mem, rctx->iobuf, n) != n)
return 0;
}
switch (rctx->state) {
case OHS_HTTP_HEADER:
if (BIO_write(rctx->mem, "\r\n", 2) != 2) {
rctx->state = OHS_ERROR;
return 0;
}
rctx->state = OHS_ASN1_WRITE_INIT;
case OHS_ASN1_WRITE_INIT:
rctx->asn1_len = BIO_get_mem_data(rctx->mem, NULL);
rctx->state = OHS_ASN1_WRITE;
case OHS_ASN1_WRITE:
n = BIO_get_mem_data(rctx->mem, &p);
i = BIO_write(rctx->io, p + (n - rctx->asn1_len), rctx->asn1_len);
if (i <= 0) {
if (BIO_should_retry(rctx->io))
return -1;
rctx->state = OHS_ERROR;
return 0;
}
rctx->asn1_len -= i;
if (rctx->asn1_len > 0)
goto next_io;
rctx->state = OHS_ASN1_FLUSH;
(void)BIO_reset(rctx->mem);
case OHS_ASN1_FLUSH:
i = BIO_flush(rctx->io);
if (i > 0) {
rctx->state = OHS_FIRSTLINE;
goto next_io;
}
if (BIO_should_retry(rctx->io))
return -1;
rctx->state = OHS_ERROR;
return 0;
case OHS_ERROR:
return 0;
case OHS_FIRSTLINE:
case OHS_HEADERS:
next_line:
n = BIO_get_mem_data(rctx->mem, &p);
if ((n <= 0) || !memchr(p, '\n', n)) {
if (n >= rctx->iobuflen) {
rctx->state = OHS_ERROR;
return 0;
}
goto next_io;
}
n = BIO_gets(rctx->mem, (char *)rctx->iobuf, rctx->iobuflen);
if (n <= 0) {
if (BIO_should_retry(rctx->mem))
goto next_io;
rctx->state = OHS_ERROR;
return 0;
}
if (n == rctx->iobuflen) {
rctx->state = OHS_ERROR;
return 0;
}
if (rctx->state == OHS_FIRSTLINE) {
if (parse_http_line1((char *)rctx->iobuf)) {
rctx->state = OHS_HEADERS;
goto next_line;
} else {
rctx->state = OHS_ERROR;
return 0;
}
} else {
for (p = rctx->iobuf; *p; p++) {
if ((*p != '\r') && (*p != '\n'))
break;
}
if (*p)
goto next_line;
rctx->state = OHS_ASN1_HEADER;
}
case OHS_ASN1_HEADER:
n = BIO_get_mem_data(rctx->mem, &p);
if (n < 2)
goto next_io;
if (*p++ != (V_ASN1_SEQUENCE | V_ASN1_CONSTRUCTED)) {
rctx->state = OHS_ERROR;
return 0;
}
if (*p & 0x80) {
if (n < 6)
goto next_io;
n = *p & 0x7F;
if (!n || (n > 4)) {
rctx->state = OHS_ERROR;
return 0;
}
p++;
rctx->asn1_len = 0;
for (i = 0; i < n; i++) {
rctx->asn1_len <<= 8;
rctx->asn1_len |= *p++;
}
if (rctx->asn1_len > rctx->max_resp_len) {
rctx->state = OHS_ERROR;
return 0;
}
rctx->asn1_len += n + 2;
} else
rctx->asn1_len = *p + 2;
rctx->state = OHS_ASN1_CONTENT;
case OHS_ASN1_CONTENT:
n = BIO_get_mem_data(rctx->mem, NULL);
if (n < (int)rctx->asn1_len)
goto next_io;
rctx->state = OHS_DONE;
return 1;
break;
case OHS_DONE:
return 1;
}
return 0;
}
int OCSP_sendreq_nbio(OCSP_RESPONSE **presp, OCSP_REQ_CTX *rctx)
{
return OCSP_REQ_CTX_nbio_d2i(rctx,
(ASN1_VALUE **)presp,
ASN1_ITEM_rptr(OCSP_RESPONSE));
}
OCSP_RESPONSE *OCSP_sendreq_bio(BIO *b, const char *path, OCSP_REQUEST *req)
{
OCSP_RESPONSE *resp = NULL;
OCSP_REQ_CTX *ctx;
int rv;
ctx = OCSP_sendreq_new(b, path, req, -1);
if (!ctx)
return NULL;
do {
rv = OCSP_sendreq_nbio(&resp, ctx);
} while ((rv == -1) && BIO_should_retry(b));
OCSP_REQ_CTX_free(ctx);
if (rv)
return resp;
return NULL;
}
