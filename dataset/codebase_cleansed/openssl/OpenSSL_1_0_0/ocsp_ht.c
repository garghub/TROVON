void OCSP_REQ_CTX_free(OCSP_REQ_CTX *rctx)
{
if (rctx->mem)
BIO_free(rctx->mem);
if (rctx->iobuf)
OPENSSL_free(rctx->iobuf);
OPENSSL_free(rctx);
}
int OCSP_REQ_CTX_set1_req(OCSP_REQ_CTX *rctx, OCSP_REQUEST *req)
{
static const char req_hdr[] =
"Content-Type: application/ocsp-request\r\n"
"Content-Length: %d\r\n\r\n";
if (BIO_printf(rctx->mem, req_hdr, i2d_OCSP_REQUEST(req, NULL)) <= 0)
return 0;
if (i2d_OCSP_REQUEST_bio(rctx->mem, req) <= 0)
return 0;
rctx->state = OHS_ASN1_WRITE;
rctx->asn1_len = BIO_get_mem_data(rctx->mem, NULL);
return 1;
}
int OCSP_REQ_CTX_add1_header(OCSP_REQ_CTX *rctx,
const char *name, const char *value)
{
if (!name)
return 0;
if (BIO_puts(rctx->mem, name) <= 0)
return 0;
if (value)
{
if (BIO_write(rctx->mem, ": ", 2) != 2)
return 0;
if (BIO_puts(rctx->mem, value) <= 0)
return 0;
}
if (BIO_write(rctx->mem, "\r\n", 2) != 2)
return 0;
return 1;
}
OCSP_REQ_CTX *OCSP_sendreq_new(BIO *io, char *path, OCSP_REQUEST *req,
int maxline)
{
static const char post_hdr[] = "POST %s HTTP/1.0\r\n";
OCSP_REQ_CTX *rctx;
rctx = OPENSSL_malloc(sizeof(OCSP_REQ_CTX));
rctx->state = OHS_ERROR;
rctx->mem = BIO_new(BIO_s_mem());
rctx->io = io;
rctx->asn1_len = 0;
if (maxline > 0)
rctx->iobuflen = maxline;
else
rctx->iobuflen = OCSP_MAX_LINE_LEN;
rctx->iobuf = OPENSSL_malloc(rctx->iobuflen);
if (!rctx->iobuf)
return 0;
if (!path)
path = "/";
if (BIO_printf(rctx->mem, post_hdr, path) <= 0)
return 0;
if (req && !OCSP_REQ_CTX_set1_req(rctx, req))
return 0;
return rctx;
}
static int parse_http_line1(char *line)
{
int retcode;
char *p, *q, *r;
for(p = line; *p && !isspace((unsigned char)*p); p++)
continue;
if(!*p)
{
OCSPerr(OCSP_F_PARSE_HTTP_LINE1,
OCSP_R_SERVER_RESPONSE_PARSE_ERROR);
return 0;
}
while(*p && isspace((unsigned char)*p))
p++;
if(!*p)
{
OCSPerr(OCSP_F_PARSE_HTTP_LINE1,
OCSP_R_SERVER_RESPONSE_PARSE_ERROR);
return 0;
}
for(q = p; *q && !isspace((unsigned char)*q); q++)
continue;
if(!*q)
{
OCSPerr(OCSP_F_PARSE_HTTP_LINE1,
OCSP_R_SERVER_RESPONSE_PARSE_ERROR);
return 0;
}
*q++ = 0;
retcode = strtoul(p, &r, 10);
if(*r)
return 0;
while(*q && isspace((unsigned char)*q))
q++;
if(*q)
{
for(r = q + strlen(q) - 1; isspace((unsigned char)*r); r--)
*r = 0;
}
if(retcode != 200)
{
OCSPerr(OCSP_F_PARSE_HTTP_LINE1, OCSP_R_SERVER_RESPONSE_ERROR);
if(!*q)
ERR_add_error_data(2, "Code=", p);
else
ERR_add_error_data(4, "Code=", p, ",Reason=", q);
return 0;
}
return 1;
}
int OCSP_sendreq_nbio(OCSP_RESPONSE **presp, OCSP_REQ_CTX *rctx)
{
int i, n;
const unsigned char *p;
next_io:
if (!(rctx->state & OHS_NOREAD))
{
n = BIO_read(rctx->io, rctx->iobuf, rctx->iobuflen);
if (n <= 0)
{
if (BIO_should_retry(rctx->io))
return -1;
return 0;
}
if (BIO_write(rctx->mem, rctx->iobuf, n) != n)
return 0;
}
switch(rctx->state)
{
case OHS_ASN1_WRITE:
n = BIO_get_mem_data(rctx->mem, &p);
i = BIO_write(rctx->io,
p + (n - rctx->asn1_len), rctx->asn1_len);
if (i <= 0)
{
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
if (i > 0)
{
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
if ((n <= 0) || !memchr(p, '\n', n))
{
if (n >= rctx->iobuflen)
{
rctx->state = OHS_ERROR;
return 0;
}
goto next_io;
}
n = BIO_gets(rctx->mem, (char *)rctx->iobuf, rctx->iobuflen);
if (n <= 0)
{
if (BIO_should_retry(rctx->mem))
goto next_io;
rctx->state = OHS_ERROR;
return 0;
}
if (n == rctx->iobuflen)
{
rctx->state = OHS_ERROR;
return 0;
}
if (rctx->state == OHS_FIRSTLINE)
{
if (parse_http_line1((char *)rctx->iobuf))
{
rctx->state = OHS_HEADERS;
goto next_line;
}
else
{
rctx->state = OHS_ERROR;
return 0;
}
}
else
{
for (p = rctx->iobuf; *p; p++)
{
if ((*p != '\r') && (*p != '\n'))
break;
}
if (*p)
goto next_line;
rctx->state = OHS_ASN1_HEADER;
}
case OHS_ASN1_HEADER:
n = BIO_get_mem_data(rctx->mem, &p);
if (n < 6)
goto next_io;
if (*p++ != (V_ASN1_SEQUENCE|V_ASN1_CONSTRUCTED))
{
rctx->state = OHS_ERROR;
return 0;
}
if (*p & 0x80)
{
n = *p & 0x7F;
if (!n || (n > 4))
{
rctx->state = OHS_ERROR;
return 0;
}
p++;
rctx->asn1_len = 0;
for (i = 0; i < n; i++)
{
rctx->asn1_len <<= 8;
rctx->asn1_len |= *p++;
}
if (rctx->asn1_len > OCSP_MAX_REQUEST_LENGTH)
{
rctx->state = OHS_ERROR;
return 0;
}
rctx->asn1_len += n + 2;
}
else
rctx->asn1_len = *p + 2;
rctx->state = OHS_ASN1_CONTENT;
case OHS_ASN1_CONTENT:
n = BIO_get_mem_data(rctx->mem, &p);
if (n < (int)rctx->asn1_len)
goto next_io;
*presp = d2i_OCSP_RESPONSE(NULL, &p, rctx->asn1_len);
if (*presp)
{
rctx->state = OHS_DONE;
return 1;
}
rctx->state = OHS_ERROR;
return 0;
break;
case OHS_DONE:
return 1;
}
return 0;
}
OCSP_RESPONSE *OCSP_sendreq_bio(BIO *b, char *path, OCSP_REQUEST *req)
{
OCSP_RESPONSE *resp = NULL;
OCSP_REQ_CTX *ctx;
int rv;
ctx = OCSP_sendreq_new(b, path, req, -1);
do
{
rv = OCSP_sendreq_nbio(&resp, ctx);
} while ((rv == -1) && BIO_should_retry(b));
OCSP_REQ_CTX_free(ctx);
if (rv)
return resp;
return NULL;
}
