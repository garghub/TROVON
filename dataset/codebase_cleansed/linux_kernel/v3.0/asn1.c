static void
asn1_open(struct asn1_ctx *ctx, unsigned char *buf, unsigned int len)
{
ctx->begin = buf;
ctx->end = buf + len;
ctx->pointer = buf;
ctx->error = ASN1_ERR_NOERROR;
}
static unsigned char
asn1_octet_decode(struct asn1_ctx *ctx, unsigned char *ch)
{
if (ctx->pointer >= ctx->end) {
ctx->error = ASN1_ERR_DEC_EMPTY;
return 0;
}
*ch = *(ctx->pointer)++;
return 1;
}
static unsigned char
asn1_tag_decode(struct asn1_ctx *ctx, unsigned int *tag)
{
unsigned char ch;
*tag = 0;
do {
if (!asn1_octet_decode(ctx, &ch))
return 0;
*tag <<= 7;
*tag |= ch & 0x7F;
} while ((ch & 0x80) == 0x80);
return 1;
}
static unsigned char
asn1_id_decode(struct asn1_ctx *ctx,
unsigned int *cls, unsigned int *con, unsigned int *tag)
{
unsigned char ch;
if (!asn1_octet_decode(ctx, &ch))
return 0;
*cls = (ch & 0xC0) >> 6;
*con = (ch & 0x20) >> 5;
*tag = (ch & 0x1F);
if (*tag == 0x1F) {
if (!asn1_tag_decode(ctx, tag))
return 0;
}
return 1;
}
static unsigned char
asn1_length_decode(struct asn1_ctx *ctx, unsigned int *def, unsigned int *len)
{
unsigned char ch, cnt;
if (!asn1_octet_decode(ctx, &ch))
return 0;
if (ch == 0x80)
*def = 0;
else {
*def = 1;
if (ch < 0x80)
*len = ch;
else {
cnt = (unsigned char) (ch & 0x7F);
*len = 0;
while (cnt > 0) {
if (!asn1_octet_decode(ctx, &ch))
return 0;
*len <<= 8;
*len |= ch;
cnt--;
}
}
}
if (*len > ctx->end - ctx->pointer)
return 0;
return 1;
}
static unsigned char
asn1_header_decode(struct asn1_ctx *ctx,
unsigned char **eoc,
unsigned int *cls, unsigned int *con, unsigned int *tag)
{
unsigned int def = 0;
unsigned int len = 0;
if (!asn1_id_decode(ctx, cls, con, tag))
return 0;
if (!asn1_length_decode(ctx, &def, &len))
return 0;
if (*con == ASN1_PRI && !def)
return 0;
if (def)
*eoc = ctx->pointer + len;
else
*eoc = NULL;
return 1;
}
static unsigned char
asn1_eoc_decode(struct asn1_ctx *ctx, unsigned char *eoc)
{
unsigned char ch;
if (eoc == NULL) {
if (!asn1_octet_decode(ctx, &ch))
return 0;
if (ch != 0x00) {
ctx->error = ASN1_ERR_DEC_EOC_MISMATCH;
return 0;
}
if (!asn1_octet_decode(ctx, &ch))
return 0;
if (ch != 0x00) {
ctx->error = ASN1_ERR_DEC_EOC_MISMATCH;
return 0;
}
return 1;
} else {
if (ctx->pointer != eoc) {
ctx->error = ASN1_ERR_DEC_LENGTH_MISMATCH;
return 0;
}
return 1;
}
}
static unsigned char
asn1_subid_decode(struct asn1_ctx *ctx, unsigned long *subid)
{
unsigned char ch;
*subid = 0;
do {
if (!asn1_octet_decode(ctx, &ch))
return 0;
*subid <<= 7;
*subid |= ch & 0x7F;
} while ((ch & 0x80) == 0x80);
return 1;
}
static int
asn1_oid_decode(struct asn1_ctx *ctx,
unsigned char *eoc, unsigned long **oid, unsigned int *len)
{
unsigned long subid;
unsigned int size;
unsigned long *optr;
size = eoc - ctx->pointer + 1;
if (size < 2 || size > UINT_MAX/sizeof(unsigned long))
return 0;
*oid = kmalloc(size * sizeof(unsigned long), GFP_ATOMIC);
if (*oid == NULL)
return 0;
optr = *oid;
if (!asn1_subid_decode(ctx, &subid)) {
kfree(*oid);
*oid = NULL;
return 0;
}
if (subid < 40) {
optr[0] = 0;
optr[1] = subid;
} else if (subid < 80) {
optr[0] = 1;
optr[1] = subid - 40;
} else {
optr[0] = 2;
optr[1] = subid - 80;
}
*len = 2;
optr += 2;
while (ctx->pointer < eoc) {
if (++(*len) > size) {
ctx->error = ASN1_ERR_DEC_BADVALUE;
kfree(*oid);
*oid = NULL;
return 0;
}
if (!asn1_subid_decode(ctx, optr++)) {
kfree(*oid);
*oid = NULL;
return 0;
}
}
return 1;
}
static int
compare_oid(unsigned long *oid1, unsigned int oid1len,
unsigned long *oid2, unsigned int oid2len)
{
unsigned int i;
if (oid1len != oid2len)
return 0;
else {
for (i = 0; i < oid1len; i++) {
if (oid1[i] != oid2[i])
return 0;
}
return 1;
}
}
int
decode_negTokenInit(unsigned char *security_blob, int length,
struct TCP_Server_Info *server)
{
struct asn1_ctx ctx;
unsigned char *end;
unsigned char *sequence_end;
unsigned long *oid = NULL;
unsigned int cls, con, tag, oidlen, rc;
asn1_open(&ctx, security_blob, length);
if (asn1_header_decode(&ctx, &end, &cls, &con, &tag) == 0) {
cFYI(1, "Error decoding negTokenInit header");
return 0;
} else if ((cls != ASN1_APL) || (con != ASN1_CON)
|| (tag != ASN1_EOC)) {
cFYI(1, "cls = %d con = %d tag = %d", cls, con, tag);
return 0;
}
rc = asn1_header_decode(&ctx, &end, &cls, &con, &tag);
if (rc) {
if ((tag == ASN1_OJI) && (con == ASN1_PRI) &&
(cls == ASN1_UNI)) {
rc = asn1_oid_decode(&ctx, end, &oid, &oidlen);
if (rc) {
rc = compare_oid(oid, oidlen, SPNEGO_OID,
SPNEGO_OID_LEN);
kfree(oid);
}
} else
rc = 0;
}
if (!rc) {
cFYI(1, "Error decoding negTokenInit header");
return 0;
}
if (asn1_header_decode(&ctx, &end, &cls, &con, &tag) == 0) {
cFYI(1, "Error decoding negTokenInit");
return 0;
} else if ((cls != ASN1_CTX) || (con != ASN1_CON)
|| (tag != ASN1_EOC)) {
cFYI(1, "cls = %d con = %d tag = %d end = %p (%d) exit 0",
cls, con, tag, end, *end);
return 0;
}
if (asn1_header_decode(&ctx, &end, &cls, &con, &tag) == 0) {
cFYI(1, "Error decoding negTokenInit");
return 0;
} else if ((cls != ASN1_UNI) || (con != ASN1_CON)
|| (tag != ASN1_SEQ)) {
cFYI(1, "cls = %d con = %d tag = %d end = %p (%d) exit 1",
cls, con, tag, end, *end);
return 0;
}
if (asn1_header_decode(&ctx, &end, &cls, &con, &tag) == 0) {
cFYI(1, "Error decoding 2nd part of negTokenInit");
return 0;
} else if ((cls != ASN1_CTX) || (con != ASN1_CON)
|| (tag != ASN1_EOC)) {
cFYI(1, "cls = %d con = %d tag = %d end = %p (%d) exit 0",
cls, con, tag, end, *end);
return 0;
}
if (asn1_header_decode
(&ctx, &sequence_end, &cls, &con, &tag) == 0) {
cFYI(1, "Error decoding 2nd part of negTokenInit");
return 0;
} else if ((cls != ASN1_UNI) || (con != ASN1_CON)
|| (tag != ASN1_SEQ)) {
cFYI(1, "cls = %d con = %d tag = %d end = %p (%d) exit 1",
cls, con, tag, end, *end);
return 0;
}
while (!asn1_eoc_decode(&ctx, sequence_end)) {
rc = asn1_header_decode(&ctx, &end, &cls, &con, &tag);
if (!rc) {
cFYI(1, "Error decoding negTokenInit hdr exit2");
return 0;
}
if ((tag == ASN1_OJI) && (con == ASN1_PRI)) {
if (asn1_oid_decode(&ctx, end, &oid, &oidlen)) {
cFYI(1, "OID len = %d oid = 0x%lx 0x%lx "
"0x%lx 0x%lx", oidlen, *oid,
*(oid + 1), *(oid + 2), *(oid + 3));
if (compare_oid(oid, oidlen, MSKRB5_OID,
MSKRB5_OID_LEN))
server->sec_mskerberos = true;
else if (compare_oid(oid, oidlen, KRB5U2U_OID,
KRB5U2U_OID_LEN))
server->sec_kerberosu2u = true;
else if (compare_oid(oid, oidlen, KRB5_OID,
KRB5_OID_LEN))
server->sec_kerberos = true;
else if (compare_oid(oid, oidlen, NTLMSSP_OID,
NTLMSSP_OID_LEN))
server->sec_ntlmssp = true;
kfree(oid);
}
} else {
cFYI(1, "Should be an oid what is going on?");
}
}
if (asn1_header_decode(&ctx, &end, &cls, &con, &tag) == 0) {
if (ctx.error == ASN1_ERR_DEC_EMPTY)
goto decode_negtoken_exit;
cFYI(1, "Error decoding last part negTokenInit exit3");
return 0;
} else if ((cls != ASN1_CTX) || (con != ASN1_CON)) {
cFYI(1, "Exit 4 cls = %d con = %d tag = %d end = %p (%d)",
cls, con, tag, end, *end);
return 0;
}
if (asn1_header_decode(&ctx, &end, &cls, &con, &tag) == 0) {
cFYI(1, "Error decoding last part negTokenInit exit5");
return 0;
} else if ((cls != ASN1_UNI) || (con != ASN1_CON)
|| (tag != ASN1_SEQ)) {
cFYI(1, "cls = %d con = %d tag = %d end = %p (%d)",
cls, con, tag, end, *end);
}
if (asn1_header_decode(&ctx, &end, &cls, &con, &tag) == 0) {
cFYI(1, "Error decoding last part negTokenInit exit 7");
return 0;
} else if ((cls != ASN1_CTX) || (con != ASN1_CON)) {
cFYI(1, "Exit 8 cls = %d con = %d tag = %d end = %p (%d)",
cls, con, tag, end, *end);
return 0;
}
if (asn1_header_decode(&ctx, &end, &cls, &con, &tag) == 0) {
cFYI(1, "Error decoding last part negTokenInit exit9");
return 0;
} else if ((cls != ASN1_UNI) || (con != ASN1_PRI)
|| (tag != ASN1_GENSTR)) {
cFYI(1, "Exit10 cls = %d con = %d tag = %d end = %p (%d)",
cls, con, tag, end, *end);
return 0;
}
cFYI(1, "Need to call asn1_octets_decode() function for %s",
ctx.pointer);
decode_negtoken_exit:
return 1;
}
