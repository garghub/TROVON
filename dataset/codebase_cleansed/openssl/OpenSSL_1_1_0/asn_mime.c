int i2d_ASN1_bio_stream(BIO *out, ASN1_VALUE *val, BIO *in, int flags,
const ASN1_ITEM *it)
{
if (flags & SMIME_STREAM) {
BIO *bio, *tbio;
bio = BIO_new_NDEF(out, val, it);
if (!bio) {
ASN1err(ASN1_F_I2D_ASN1_BIO_STREAM, ERR_R_MALLOC_FAILURE);
return 0;
}
SMIME_crlf_copy(in, bio, flags);
(void)BIO_flush(bio);
do {
tbio = BIO_pop(bio);
BIO_free(bio);
bio = tbio;
} while (bio != out);
}
else
ASN1_item_i2d_bio(it, out, val);
return 1;
}
static int B64_write_ASN1(BIO *out, ASN1_VALUE *val, BIO *in, int flags,
const ASN1_ITEM *it)
{
BIO *b64;
int r;
b64 = BIO_new(BIO_f_base64());
if (b64 == NULL) {
ASN1err(ASN1_F_B64_WRITE_ASN1, ERR_R_MALLOC_FAILURE);
return 0;
}
out = BIO_push(b64, out);
r = i2d_ASN1_bio_stream(out, val, in, flags, it);
(void)BIO_flush(out);
BIO_pop(out);
BIO_free(b64);
return r;
}
int PEM_write_bio_ASN1_stream(BIO *out, ASN1_VALUE *val, BIO *in, int flags,
const char *hdr, const ASN1_ITEM *it)
{
int r;
BIO_printf(out, "-----BEGIN %s-----\n", hdr);
r = B64_write_ASN1(out, val, in, flags, it);
BIO_printf(out, "-----END %s-----\n", hdr);
return r;
}
static ASN1_VALUE *b64_read_asn1(BIO *bio, const ASN1_ITEM *it)
{
BIO *b64;
ASN1_VALUE *val;
if ((b64 = BIO_new(BIO_f_base64())) == NULL) {
ASN1err(ASN1_F_B64_READ_ASN1, ERR_R_MALLOC_FAILURE);
return 0;
}
bio = BIO_push(b64, bio);
val = ASN1_item_d2i_bio(it, bio, NULL);
if (!val)
ASN1err(ASN1_F_B64_READ_ASN1, ASN1_R_DECODE_ERROR);
(void)BIO_flush(bio);
BIO_pop(bio);
BIO_free(b64);
return val;
}
static int asn1_output_data(BIO *out, BIO *data, ASN1_VALUE *val, int flags,
const ASN1_ITEM *it)
{
BIO *tmpbio;
const ASN1_AUX *aux = it->funcs;
ASN1_STREAM_ARG sarg;
int rv = 1;
if (!(flags & SMIME_DETACHED) || (flags & PKCS7_REUSE_DIGEST)) {
SMIME_crlf_copy(data, out, flags);
return 1;
}
if (!aux || !aux->asn1_cb) {
ASN1err(ASN1_F_ASN1_OUTPUT_DATA, ASN1_R_STREAMING_NOT_SUPPORTED);
return 0;
}
sarg.out = out;
sarg.ndef_bio = NULL;
sarg.boundary = NULL;
if (aux->asn1_cb(ASN1_OP_DETACHED_PRE, &val, it, &sarg) <= 0)
return 0;
SMIME_crlf_copy(data, sarg.ndef_bio, flags);
if (aux->asn1_cb(ASN1_OP_DETACHED_POST, &val, it, &sarg) <= 0)
rv = 0;
while (sarg.ndef_bio != out) {
tmpbio = BIO_pop(sarg.ndef_bio);
BIO_free(sarg.ndef_bio);
sarg.ndef_bio = tmpbio;
}
return rv;
}
ASN1_VALUE *SMIME_read_ASN1(BIO *bio, BIO **bcont, const ASN1_ITEM *it)
{
BIO *asnin;
STACK_OF(MIME_HEADER) *headers = NULL;
STACK_OF(BIO) *parts = NULL;
MIME_HEADER *hdr;
MIME_PARAM *prm;
ASN1_VALUE *val;
int ret;
if (bcont)
*bcont = NULL;
if ((headers = mime_parse_hdr(bio)) == NULL) {
ASN1err(ASN1_F_SMIME_READ_ASN1, ASN1_R_MIME_PARSE_ERROR);
return NULL;
}
if ((hdr = mime_hdr_find(headers, "content-type")) == NULL
|| hdr->value == NULL) {
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
ASN1err(ASN1_F_SMIME_READ_ASN1, ASN1_R_NO_CONTENT_TYPE);
return NULL;
}
if (strcmp(hdr->value, "multipart/signed") == 0) {
prm = mime_param_find(hdr, "boundary");
if (!prm || !prm->param_value) {
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
ASN1err(ASN1_F_SMIME_READ_ASN1, ASN1_R_NO_MULTIPART_BOUNDARY);
return NULL;
}
ret = multi_split(bio, prm->param_value, &parts);
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
if (!ret || (sk_BIO_num(parts) != 2)) {
ASN1err(ASN1_F_SMIME_READ_ASN1, ASN1_R_NO_MULTIPART_BODY_FAILURE);
sk_BIO_pop_free(parts, BIO_vfree);
return NULL;
}
asnin = sk_BIO_value(parts, 1);
if ((headers = mime_parse_hdr(asnin)) == NULL) {
ASN1err(ASN1_F_SMIME_READ_ASN1, ASN1_R_MIME_SIG_PARSE_ERROR);
sk_BIO_pop_free(parts, BIO_vfree);
return NULL;
}
if ((hdr = mime_hdr_find(headers, "content-type")) == NULL
|| hdr->value == NULL) {
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
ASN1err(ASN1_F_SMIME_READ_ASN1, ASN1_R_NO_SIG_CONTENT_TYPE);
return NULL;
}
if (strcmp(hdr->value, "application/x-pkcs7-signature") &&
strcmp(hdr->value, "application/pkcs7-signature")) {
ASN1err(ASN1_F_SMIME_READ_ASN1, ASN1_R_SIG_INVALID_MIME_TYPE);
ERR_add_error_data(2, "type: ", hdr->value);
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
sk_BIO_pop_free(parts, BIO_vfree);
return NULL;
}
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
if ((val = b64_read_asn1(asnin, it)) == NULL) {
ASN1err(ASN1_F_SMIME_READ_ASN1, ASN1_R_ASN1_SIG_PARSE_ERROR);
sk_BIO_pop_free(parts, BIO_vfree);
return NULL;
}
if (bcont) {
*bcont = sk_BIO_value(parts, 0);
BIO_free(asnin);
sk_BIO_free(parts);
} else
sk_BIO_pop_free(parts, BIO_vfree);
return val;
}
if (strcmp(hdr->value, "application/x-pkcs7-mime") &&
strcmp(hdr->value, "application/pkcs7-mime")) {
ASN1err(ASN1_F_SMIME_READ_ASN1, ASN1_R_INVALID_MIME_TYPE);
ERR_add_error_data(2, "type: ", hdr->value);
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
return NULL;
}
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
if ((val = b64_read_asn1(bio, it)) == NULL) {
ASN1err(ASN1_F_SMIME_READ_ASN1, ASN1_R_ASN1_PARSE_ERROR);
return NULL;
}
return val;
}
int SMIME_crlf_copy(BIO *in, BIO *out, int flags)
{
BIO *bf;
char eol;
int len;
char linebuf[MAX_SMLEN];
bf = BIO_new(BIO_f_buffer());
if (bf == NULL)
return 0;
out = BIO_push(bf, out);
if (flags & SMIME_BINARY) {
while ((len = BIO_read(in, linebuf, MAX_SMLEN)) > 0)
BIO_write(out, linebuf, len);
} else {
int eolcnt = 0;
if (flags & SMIME_TEXT)
BIO_printf(out, "Content-Type: text/plain\r\n\r\n");
while ((len = BIO_gets(in, linebuf, MAX_SMLEN)) > 0) {
eol = strip_eol(linebuf, &len, flags);
if (len) {
if (flags & SMIME_ASCIICRLF) {
int i;
for (i = 0; i < eolcnt; i++)
BIO_write(out, "\r\n", 2);
eolcnt = 0;
}
BIO_write(out, linebuf, len);
if (eol)
BIO_write(out, "\r\n", 2);
} else if (flags & SMIME_ASCIICRLF)
eolcnt++;
else if (eol)
BIO_write(out, "\r\n", 2);
}
}
(void)BIO_flush(out);
BIO_pop(out);
BIO_free(bf);
return 1;
}
int SMIME_text(BIO *in, BIO *out)
{
char iobuf[4096];
int len;
STACK_OF(MIME_HEADER) *headers;
MIME_HEADER *hdr;
if ((headers = mime_parse_hdr(in)) == NULL) {
ASN1err(ASN1_F_SMIME_TEXT, ASN1_R_MIME_PARSE_ERROR);
return 0;
}
if ((hdr = mime_hdr_find(headers, "content-type")) == NULL
|| hdr->value == NULL) {
ASN1err(ASN1_F_SMIME_TEXT, ASN1_R_MIME_NO_CONTENT_TYPE);
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
return 0;
}
if (strcmp(hdr->value, "text/plain")) {
ASN1err(ASN1_F_SMIME_TEXT, ASN1_R_INVALID_MIME_TYPE);
ERR_add_error_data(2, "type: ", hdr->value);
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
return 0;
}
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
while ((len = BIO_read(in, iobuf, sizeof(iobuf))) > 0)
BIO_write(out, iobuf, len);
if (len < 0)
return 0;
return 1;
}
char *strip_ends(char *name)
{
return strip_end(strip_start(name));
}
static char *strip_start(char *name)
{
char *p, c;
for (p = name; (c = *p); p++) {
if (c == '"') {
if (p[1])
return p + 1;
return NULL;
}
if (!isspace((unsigned char)c))
return p;
}
return NULL;
}
static char *strip_end(char *name)
{
char *p, c;
if (!name)
return NULL;
for (p = name + strlen(name) - 1; p >= name; p--) {
c = *p;
if (c == '"') {
if (p - 1 == name)
return NULL;
*p = 0;
return name;
}
if (isspace((unsigned char)c))
*p = 0;
else
return name;
}
return NULL;
}
static MIME_HEADER *mime_hdr_new(const char *name, const char *value)
{
MIME_HEADER *mhdr = NULL;
char *tmpname = NULL, *tmpval = NULL, *p;
int c;
if (name) {
if ((tmpname = OPENSSL_strdup(name)) == NULL)
return NULL;
for (p = tmpname; *p; p++) {
c = (unsigned char)*p;
if (isupper(c)) {
c = tolower(c);
*p = c;
}
}
}
if (value) {
if ((tmpval = OPENSSL_strdup(value)) == NULL)
goto err;
for (p = tmpval; *p; p++) {
c = (unsigned char)*p;
if (isupper(c)) {
c = tolower(c);
*p = c;
}
}
}
mhdr = OPENSSL_malloc(sizeof(*mhdr));
if (mhdr == NULL)
goto err;
mhdr->name = tmpname;
mhdr->value = tmpval;
if ((mhdr->params = sk_MIME_PARAM_new(mime_param_cmp)) == NULL)
goto err;
return mhdr;
err:
OPENSSL_free(tmpname);
OPENSSL_free(tmpval);
OPENSSL_free(mhdr);
return NULL;
}
static int mime_hdr_addparam(MIME_HEADER *mhdr, const char *name, const char *value)
{
char *tmpname = NULL, *tmpval = NULL, *p;
int c;
MIME_PARAM *mparam = NULL;
if (name) {
tmpname = OPENSSL_strdup(name);
if (!tmpname)
goto err;
for (p = tmpname; *p; p++) {
c = (unsigned char)*p;
if (isupper(c)) {
c = tolower(c);
*p = c;
}
}
}
if (value) {
tmpval = OPENSSL_strdup(value);
if (!tmpval)
goto err;
}
mparam = OPENSSL_malloc(sizeof(*mparam));
if (mparam == NULL)
goto err;
mparam->param_name = tmpname;
mparam->param_value = tmpval;
if (!sk_MIME_PARAM_push(mhdr->params, mparam))
goto err;
return 1;
err:
OPENSSL_free(tmpname);
OPENSSL_free(tmpval);
OPENSSL_free(mparam);
return 0;
}
static int mime_hdr_cmp(const MIME_HEADER *const *a,
const MIME_HEADER *const *b)
{
if (!(*a)->name || !(*b)->name)
return ! !(*a)->name - ! !(*b)->name;
return (strcmp((*a)->name, (*b)->name));
}
static int mime_param_cmp(const MIME_PARAM *const *a,
const MIME_PARAM *const *b)
{
if (!(*a)->param_name || !(*b)->param_name)
return ! !(*a)->param_name - ! !(*b)->param_name;
return (strcmp((*a)->param_name, (*b)->param_name));
}
static MIME_PARAM *mime_param_find(MIME_HEADER *hdr, const char *name)
{
MIME_PARAM param;
int idx;
param.param_name = (char *)name;
param.param_value = NULL;
idx = sk_MIME_PARAM_find(hdr->params, &param);
if (idx < 0)
return NULL;
return sk_MIME_PARAM_value(hdr->params, idx);
}
static void mime_hdr_free(MIME_HEADER *hdr)
{
if (hdr == NULL)
return;
OPENSSL_free(hdr->name);
OPENSSL_free(hdr->value);
if (hdr->params)
sk_MIME_PARAM_pop_free(hdr->params, mime_param_free);
OPENSSL_free(hdr);
}
static void mime_param_free(MIME_PARAM *param)
{
OPENSSL_free(param->param_name);
OPENSSL_free(param->param_value);
OPENSSL_free(param);
}
static int mime_bound_check(char *line, int linelen, const char *bound, int blen)
{
if (linelen == -1)
linelen = strlen(line);
if (blen == -1)
blen = strlen(bound);
if (blen + 2 > linelen)
return 0;
if ((strncmp(line, "--", 2) == 0)
&& strncmp(line + 2, bound, blen) == 0) {
if (strncmp(line + blen + 2, "--", 2) == 0)
return 2;
else
return 1;
}
return 0;
}
static int strip_eol(char *linebuf, int *plen, int flags)
{
int len = *plen;
char *p, c;
int is_eol = 0;
p = linebuf + len - 1;
for (p = linebuf + len - 1; len > 0; len--, p--) {
c = *p;
if (c == '\n')
is_eol = 1;
else if (is_eol && flags & SMIME_ASCIICRLF && c < 33)
continue;
else if (c != '\r')
break;
}
*plen = len;
return is_eol;
}
