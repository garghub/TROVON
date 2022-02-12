static int B64_write_PKCS7(BIO *bio, PKCS7 *p7)
{
BIO *b64;
if(!(b64 = BIO_new(BIO_f_base64()))) {
PKCS7err(PKCS7_F_B64_WRITE_PKCS7,ERR_R_MALLOC_FAILURE);
return 0;
}
bio = BIO_push(b64, bio);
i2d_PKCS7_bio(bio, p7);
BIO_flush(bio);
bio = BIO_pop(bio);
BIO_free(b64);
return 1;
}
static PKCS7 *B64_read_PKCS7(BIO *bio)
{
BIO *b64;
PKCS7 *p7;
if(!(b64 = BIO_new(BIO_f_base64()))) {
PKCS7err(PKCS7_F_B64_READ_PKCS7,ERR_R_MALLOC_FAILURE);
return 0;
}
bio = BIO_push(b64, bio);
if(!(p7 = d2i_PKCS7_bio(bio, NULL)))
PKCS7err(PKCS7_F_B64_READ_PKCS7,PKCS7_R_DECODE_ERROR);
BIO_flush(bio);
bio = BIO_pop(bio);
BIO_free(b64);
return p7;
}
int SMIME_write_PKCS7(BIO *bio, PKCS7 *p7, BIO *data, int flags)
{
char linebuf[MAX_SMLEN];
char bound[33], c;
int i;
if((flags & PKCS7_DETACHED) && data) {
RAND_pseudo_bytes((unsigned char *)bound, 32);
for(i = 0; i < 32; i++) {
c = bound[i] & 0xf;
if(c < 10) c += '0';
else c += 'A' - 10;
bound[i] = c;
}
bound[32] = 0;
BIO_printf(bio, "MIME-Version: 1.0\n");
BIO_printf(bio, "Content-Type: multipart/signed;");
BIO_printf(bio, " protocol=\"application/x-pkcs7-signature\";");
BIO_printf(bio, " micalg=sha1; boundary=\"----%s\"\n\n", bound);
BIO_printf(bio, "This is an S/MIME signed message\n\n");
BIO_printf(bio, "------%s\n", bound);
if(flags & PKCS7_TEXT) BIO_printf(bio, "Content-Type: text/plain\n\n");
while((i = BIO_read(data, linebuf, MAX_SMLEN)) > 0)
BIO_write(bio, linebuf, i);
BIO_printf(bio, "\n------%s\n", bound);
BIO_printf(bio, "Content-Type: application/x-pkcs7-signature; name=\"smime.p7s\"\n");
BIO_printf(bio, "Content-Transfer-Encoding: base64\n");
BIO_printf(bio, "Content-Disposition: attachment; filename=\"smime.p7s\"\n\n");
B64_write_PKCS7(bio, p7);
BIO_printf(bio,"\n------%s--\n\n", bound);
return 1;
}
BIO_printf(bio, "MIME-Version: 1.0\n");
BIO_printf(bio, "Content-Disposition: attachment; filename=\"smime.p7m\"\n");
BIO_printf(bio, "Content-Type: application/x-pkcs7-mime; name=\"smime.p7m\"\n");
BIO_printf(bio, "Content-Transfer-Encoding: base64\n\n");
B64_write_PKCS7(bio, p7);
BIO_printf(bio, "\n");
return 1;
}
PKCS7 *SMIME_read_PKCS7(BIO *bio, BIO **bcont)
{
BIO *p7in;
STACK_OF(MIME_HEADER) *headers = NULL;
STACK_OF(BIO) *parts = NULL;
MIME_HEADER *hdr;
MIME_PARAM *prm;
PKCS7 *p7;
int ret;
if(bcont) *bcont = NULL;
if (!(headers = mime_parse_hdr(bio))) {
PKCS7err(PKCS7_F_SMIME_READ_PKCS7,PKCS7_R_MIME_PARSE_ERROR);
return NULL;
}
if(!(hdr = mime_hdr_find(headers, "content-type")) || !hdr->value) {
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
PKCS7err(PKCS7_F_SMIME_READ_PKCS7, PKCS7_R_NO_CONTENT_TYPE);
return NULL;
}
if(!strcmp(hdr->value, "multipart/signed")) {
prm = mime_param_find(hdr, "boundary");
if(!prm || !prm->param_value) {
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
PKCS7err(PKCS7_F_SMIME_READ_PKCS7, PKCS7_R_NO_MULTIPART_BOUNDARY);
return NULL;
}
ret = multi_split(bio, prm->param_value, &parts);
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
if(!ret || (sk_BIO_num(parts) != 2) ) {
PKCS7err(PKCS7_F_SMIME_READ_PKCS7, PKCS7_R_NO_MULTIPART_BODY_FAILURE);
sk_BIO_pop_free(parts, BIO_vfree);
return NULL;
}
p7in = sk_BIO_value(parts, 1);
if (!(headers = mime_parse_hdr(p7in))) {
PKCS7err(PKCS7_F_SMIME_READ_PKCS7,PKCS7_R_MIME_SIG_PARSE_ERROR);
sk_BIO_pop_free(parts, BIO_vfree);
return NULL;
}
if(!(hdr = mime_hdr_find(headers, "content-type")) ||
!hdr->value) {
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
PKCS7err(PKCS7_F_SMIME_READ_PKCS7, PKCS7_R_NO_SIG_CONTENT_TYPE);
return NULL;
}
if(strcmp(hdr->value, "application/x-pkcs7-signature") &&
strcmp(hdr->value, "application/pkcs7-signature")) {
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
PKCS7err(PKCS7_F_SMIME_READ_PKCS7,PKCS7_R_SIG_INVALID_MIME_TYPE);
ERR_add_error_data(2, "type: ", hdr->value);
sk_BIO_pop_free(parts, BIO_vfree);
return NULL;
}
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
if(!(p7 = B64_read_PKCS7(p7in))) {
PKCS7err(PKCS7_F_SMIME_READ_PKCS7,PKCS7_R_PKCS7_SIG_PARSE_ERROR);
sk_BIO_pop_free(parts, BIO_vfree);
return NULL;
}
if(bcont) {
*bcont = sk_BIO_value(parts, 0);
BIO_free(p7in);
sk_BIO_free(parts);
} else sk_BIO_pop_free(parts, BIO_vfree);
return p7;
}
if (strcmp (hdr->value, "application/x-pkcs7-mime") &&
strcmp (hdr->value, "application/pkcs7-mime")) {
PKCS7err(PKCS7_F_SMIME_READ_PKCS7,PKCS7_R_INVALID_MIME_TYPE);
ERR_add_error_data(2, "type: ", hdr->value);
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
return NULL;
}
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
if(!(p7 = B64_read_PKCS7(bio))) {
PKCS7err(PKCS7_F_SMIME_READ_PKCS7, PKCS7_R_PKCS7_PARSE_ERROR);
return NULL;
}
return p7;
}
int SMIME_crlf_copy(BIO *in, BIO *out, int flags)
{
char eol;
int len;
char linebuf[MAX_SMLEN];
if(flags & PKCS7_BINARY) {
while((len = BIO_read(in, linebuf, MAX_SMLEN)) > 0)
BIO_write(out, linebuf, len);
return 1;
}
if(flags & PKCS7_TEXT) BIO_printf(out, "Content-Type: text/plain\r\n\r\n");
while ((len = BIO_gets(in, linebuf, MAX_SMLEN)) > 0) {
eol = 0;
while(iscrlf(linebuf[len - 1])) {
len--;
eol = 1;
}
BIO_write(out, linebuf, len);
if(eol) BIO_write(out, "\r\n", 2);
}
return 1;
}
int SMIME_text(BIO *in, BIO *out)
{
char iobuf[4096];
int len;
STACK_OF(MIME_HEADER) *headers;
MIME_HEADER *hdr;
if (!(headers = mime_parse_hdr(in))) {
PKCS7err(PKCS7_F_SMIME_TEXT,PKCS7_R_MIME_PARSE_ERROR);
return 0;
}
if(!(hdr = mime_hdr_find(headers, "content-type")) || !hdr->value) {
PKCS7err(PKCS7_F_SMIME_TEXT,PKCS7_R_MIME_NO_CONTENT_TYPE);
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
return 0;
}
if (strcmp (hdr->value, "text/plain")) {
PKCS7err(PKCS7_F_SMIME_TEXT,PKCS7_R_INVALID_MIME_TYPE);
ERR_add_error_data(2, "type: ", hdr->value);
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
return 0;
}
sk_MIME_HEADER_pop_free(headers, mime_hdr_free);
while ((len = BIO_read(in, iobuf, sizeof(iobuf))) > 0)
BIO_write(out, iobuf, len);
return 1;
}
static int iscrlf(char c)
{
if(c == '\r' || c == '\n') return 1;
return 0;
}
char *strip_ends(char *name)
{
return strip_end(strip_start(name));
}
static char *strip_start(char *name)
{
char *p, c;
for(p = name; (c = *p) ;p++) {
if(c == '"') {
if(p[1]) return p + 1;
return NULL;
}
if(!isspace((unsigned char)c)) return p;
}
return NULL;
}
static char *strip_end(char *name)
{
char *p, c;
if(!name) return NULL;
for(p = name + strlen(name) - 1; p >= name ;p--) {
c = *p;
if(c == '"') {
if(p - 1 == name) return NULL;
*p = 0;
return name;
}
if(isspace((unsigned char)c)) *p = 0;
else return name;
}
return NULL;
}
static MIME_HEADER *mime_hdr_new(char *name, char *value)
{
MIME_HEADER *mhdr;
char *tmpname, *tmpval, *p;
int c;
if(name) {
if(!(tmpname = BUF_strdup(name))) return NULL;
for(p = tmpname ; *p; p++) {
c = *p;
if(isupper(c)) {
c = tolower(c);
*p = c;
}
}
} else tmpname = NULL;
if(value) {
if(!(tmpval = BUF_strdup(value))) return NULL;
for(p = tmpval ; *p; p++) {
c = *p;
if(isupper(c)) {
c = tolower(c);
*p = c;
}
}
} else tmpval = NULL;
mhdr = (MIME_HEADER *) OPENSSL_malloc(sizeof(MIME_HEADER));
if(!mhdr) return NULL;
mhdr->name = tmpname;
mhdr->value = tmpval;
if(!(mhdr->params = sk_MIME_PARAM_new(mime_param_cmp))) return NULL;
return mhdr;
}
static int mime_hdr_addparam(MIME_HEADER *mhdr, char *name, char *value)
{
char *tmpname, *tmpval, *p;
int c;
MIME_PARAM *mparam;
if(name) {
tmpname = BUF_strdup(name);
if(!tmpname) return 0;
for(p = tmpname ; *p; p++) {
c = *p;
if(isupper(c)) {
c = tolower(c);
*p = c;
}
}
} else tmpname = NULL;
if(value) {
tmpval = BUF_strdup(value);
if(!tmpval) return 0;
} else tmpval = NULL;
mparam = (MIME_PARAM *) OPENSSL_malloc(sizeof(MIME_PARAM));
if(!mparam) return 0;
mparam->param_name = tmpname;
mparam->param_value = tmpval;
sk_MIME_PARAM_push(mhdr->params, mparam);
return 1;
}
static int mime_hdr_cmp(const MIME_HEADER * const *a,
const MIME_HEADER * const *b)
{
return(strcmp((*a)->name, (*b)->name));
}
static int mime_param_cmp(const MIME_PARAM * const *a,
const MIME_PARAM * const *b)
{
return(strcmp((*a)->param_name, (*b)->param_name));
}
static MIME_PARAM *mime_param_find(MIME_HEADER *hdr, char *name)
{
MIME_PARAM param;
int idx;
param.param_name = name;
idx = sk_MIME_PARAM_find(hdr->params, &param);
if(idx < 0) return NULL;
return sk_MIME_PARAM_value(hdr->params, idx);
}
static void mime_hdr_free(MIME_HEADER *hdr)
{
if(hdr->name) OPENSSL_free(hdr->name);
if(hdr->value) OPENSSL_free(hdr->value);
if(hdr->params) sk_MIME_PARAM_pop_free(hdr->params, mime_param_free);
OPENSSL_free(hdr);
}
static void mime_param_free(MIME_PARAM *param)
{
if(param->param_name) OPENSSL_free(param->param_name);
if(param->param_value) OPENSSL_free(param->param_value);
OPENSSL_free(param);
}
static int mime_bound_check(char *line, int linelen, char *bound, int blen)
{
if(linelen == -1) linelen = strlen(line);
if(blen == -1) blen = strlen(bound);
if(blen + 2 > linelen) return 0;
if(!strncmp(line, "--", 2) && !strncmp(line + 2, bound, blen)) {
if(!strncmp(line + blen + 2, "--", 2)) return 2;
else return 1;
}
return 0;
}
