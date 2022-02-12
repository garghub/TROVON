static const char *do_ssl_trace_str(int val, ssl_trace_tbl *tbl, size_t ntbl)
{
size_t i;
for (i = 0; i < ntbl; i++, tbl++) {
if (tbl->num == val)
return tbl->name;
}
return "UNKNOWN";
}
static int do_ssl_trace_list(BIO *bio, int indent,
const unsigned char *msg, size_t msglen,
size_t vlen, ssl_trace_tbl *tbl, size_t ntbl)
{
int val;
if (msglen % vlen)
return 0;
while (msglen) {
val = msg[0];
if (vlen == 2)
val = (val << 8) | msg[1];
BIO_indent(bio, indent, 80);
BIO_printf(bio, "%s (%d)\n", do_ssl_trace_str(val, tbl, ntbl), val);
msg += vlen;
msglen -= vlen;
}
return 1;
}
static void ssl_print_hex(BIO *bio, int indent, const char *name,
const unsigned char *msg, size_t msglen)
{
size_t i;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "%s (len=%d): ", name, (int)msglen);
for (i = 0; i < msglen; i++)
BIO_printf(bio, "%02X", msg[i]);
BIO_puts(bio, "\n");
}
static int ssl_print_hexbuf(BIO *bio, int indent,
const char *name, size_t nlen,
const unsigned char **pmsg, size_t *pmsglen)
{
size_t blen;
const unsigned char *p = *pmsg;
if (*pmsglen < nlen)
return 0;
blen = p[0];
if (nlen > 1)
blen = (blen << 8) | p[1];
if (*pmsglen < nlen + blen)
return 0;
p += nlen;
ssl_print_hex(bio, indent, name, p, blen);
*pmsg += blen + nlen;
*pmsglen -= blen + nlen;
return 1;
}
static int ssl_print_version(BIO *bio, int indent, const char *name,
const unsigned char **pmsg, size_t *pmsglen)
{
int vers;
if (*pmsglen < 2)
return 0;
vers = ((*pmsg)[0] << 8) | (*pmsg)[1];
BIO_indent(bio, indent, 80);
BIO_printf(bio, "%s=0x%x (%s)\n",
name, vers, ssl_trace_str(vers, ssl_version_tbl));
*pmsg += 2;
*pmsglen -= 2;
return 1;
}
static int ssl_print_random(BIO *bio, int indent,
const unsigned char **pmsg, size_t *pmsglen)
{
unsigned int tm;
const unsigned char *p = *pmsg;
if (*pmsglen < 32)
return 0;
tm = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
p += 4;
BIO_indent(bio, indent, 80);
BIO_puts(bio, "Random:\n");
BIO_indent(bio, indent + 2, 80);
BIO_printf(bio, "gmt_unix_time=0x%08X\n", tm);
ssl_print_hex(bio, indent + 2, "random_bytes", p, 28);
*pmsg += 32;
*pmsglen -= 32;
return 1;
}
static int ssl_print_signature(BIO *bio, int indent, SSL *s,
const unsigned char **pmsg, size_t *pmsglen)
{
if (*pmsglen < 2)
return 0;
if (SSL_USE_SIGALGS(s)) {
const unsigned char *p = *pmsg;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "Signature Algorithm %s+%s (%d+%d)\n",
ssl_trace_str(p[0], ssl_md_tbl),
ssl_trace_str(p[1], ssl_sig_tbl), p[0], p[1]);
*pmsg += 2;
*pmsglen -= 2;
}
return ssl_print_hexbuf(bio, indent, "Signature", 2, pmsg, pmsglen);
}
static int ssl_print_extension(BIO *bio, int indent, int server, int extype,
const unsigned char *ext, size_t extlen)
{
size_t xlen;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "extension_type=%s(%d), length=%d\n",
ssl_trace_str(extype, ssl_exts_tbl), extype, (int)extlen);
switch (extype) {
case TLSEXT_TYPE_ec_point_formats:
if (extlen < 1)
return 0;
xlen = ext[0];
if (extlen != xlen + 1)
return 0;
return ssl_trace_list(bio, indent + 2, ext + 1, xlen, 1, ssl_point_tbl);
case TLSEXT_TYPE_elliptic_curves:
if (extlen < 2)
return 0;
xlen = (ext[0] << 8) | ext[1];
if (extlen != xlen + 2)
return 0;
return ssl_trace_list(bio, indent + 2, ext + 2, xlen, 2, ssl_curve_tbl);
case TLSEXT_TYPE_signature_algorithms:
if (extlen < 2)
return 0;
xlen = (ext[0] << 8) | ext[1];
if (extlen != xlen + 2)
return 0;
if (xlen & 1)
return 0;
ext += 2;
while (xlen > 0) {
BIO_indent(bio, indent + 2, 80);
BIO_printf(bio, "%s+%s (%d+%d)\n",
ssl_trace_str(ext[0], ssl_md_tbl),
ssl_trace_str(ext[1], ssl_sig_tbl), ext[0], ext[1]);
xlen -= 2;
ext += 2;
}
break;
case TLSEXT_TYPE_renegotiate:
if (extlen < 1)
return 0;
xlen = ext[0];
if (xlen + 1 != extlen)
return 0;
ext++;
if (xlen) {
if (server) {
if (xlen & 1)
return 0;
xlen >>= 1;
}
ssl_print_hex(bio, indent + 4, "client_verify_data", ext, xlen);
if (server) {
ext += xlen;
ssl_print_hex(bio, indent + 4, "server_verify_data", ext, xlen);
}
} else {
BIO_indent(bio, indent + 4, 80);
BIO_puts(bio, "<EMPTY>\n");
}
break;
case TLSEXT_TYPE_heartbeat:
if (extlen != 1)
return 0;
BIO_indent(bio, indent + 2, 80);
BIO_printf(bio, "HeartbeatMode: %s\n",
ssl_trace_str(ext[0], ssl_hb_tbl));
break;
case TLSEXT_TYPE_session_ticket:
if (extlen != 0)
ssl_print_hex(bio, indent + 4, "ticket", ext, extlen);
break;
default:
BIO_dump_indent(bio, (const char *)ext, extlen, indent + 2);
}
return 1;
}
static int ssl_print_extensions(BIO *bio, int indent, int server,
const unsigned char *msg, size_t msglen)
{
size_t extslen;
BIO_indent(bio, indent, 80);
if (msglen == 0) {
BIO_puts(bio, "No Extensions\n");
return 1;
}
extslen = (msg[0] << 8) | msg[1];
if (extslen != msglen - 2)
return 0;
msg += 2;
msglen = extslen;
BIO_printf(bio, "extensions, length = %d\n", (int)msglen);
while (msglen > 0) {
int extype;
size_t extlen;
if (msglen < 4)
return 0;
extype = (msg[0] << 8) | msg[1];
extlen = (msg[2] << 8) | msg[3];
if (msglen < extlen + 4)
return 0;
msg += 4;
if (!ssl_print_extension(bio, indent + 2, server, extype, msg, extlen))
return 0;
msg += extlen;
msglen -= extlen + 4;
}
return 1;
}
static int ssl_print_client_hello(BIO *bio, SSL *ssl, int indent,
const unsigned char *msg, size_t msglen)
{
size_t len;
unsigned int cs;
if (!ssl_print_version(bio, indent, "client_version", &msg, &msglen))
return 0;
if (!ssl_print_random(bio, indent, &msg, &msglen))
return 0;
if (!ssl_print_hexbuf(bio, indent, "session_id", 1, &msg, &msglen))
return 0;
if (SSL_IS_DTLS(ssl)) {
if (!ssl_print_hexbuf(bio, indent, "cookie", 1, &msg, &msglen))
return 0;
}
if (msglen < 2)
return 0;
len = (msg[0] << 8) | msg[1];
msg += 2;
msglen -= 2;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "cipher_suites (len=%d)\n", (int)len);
if (msglen < len || len & 1)
return 0;
while (len > 0) {
cs = (msg[0] << 8) | msg[1];
BIO_indent(bio, indent + 2, 80);
BIO_printf(bio, "{0x%02X, 0x%02X} %s\n",
msg[0], msg[1], ssl_trace_str(cs, ssl_ciphers_tbl));
msg += 2;
msglen -= 2;
len -= 2;
}
if (msglen < 1)
return 0;
len = msg[0];
msg++;
msglen--;
if (msglen < len)
return 0;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "compression_methods (len=%d)\n", (int)len);
while (len > 0) {
BIO_indent(bio, indent + 2, 80);
BIO_printf(bio, "%s (0x%02X)\n",
ssl_trace_str(msg[0], ssl_comp_tbl), msg[0]);
msg++;
msglen--;
len--;
}
if (!ssl_print_extensions(bio, indent, 0, msg, msglen))
return 0;
return 1;
}
static int dtls_print_hello_vfyrequest(BIO *bio, int indent,
const unsigned char *msg, size_t msglen)
{
if (!ssl_print_version(bio, indent, "server_version", &msg, &msglen))
return 0;
if (!ssl_print_hexbuf(bio, indent, "cookie", 1, &msg, &msglen))
return 0;
return 1;
}
static int ssl_print_server_hello(BIO *bio, int indent,
const unsigned char *msg, size_t msglen)
{
unsigned int cs;
if (!ssl_print_version(bio, indent, "server_version", &msg, &msglen))
return 0;
if (!ssl_print_random(bio, indent, &msg, &msglen))
return 0;
if (!ssl_print_hexbuf(bio, indent, "session_id", 1, &msg, &msglen))
return 0;
if (msglen < 2)
return 0;
cs = (msg[0] << 8) | msg[1];
BIO_indent(bio, indent, 80);
BIO_printf(bio, "cipher_suite {0x%02X, 0x%02X} %s\n",
msg[0], msg[1], ssl_trace_str(cs, ssl_ciphers_tbl));
msg += 2;
msglen -= 2;
if (msglen < 1)
return 0;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "compression_method: %s (0x%02X)\n",
ssl_trace_str(msg[0], ssl_comp_tbl), msg[0]);
msg++;
msglen--;
if (!ssl_print_extensions(bio, indent, 1, msg, msglen))
return 0;
return 1;
}
static int ssl_get_keyex(const char **pname, SSL *ssl)
{
unsigned long alg_k = ssl->s3->tmp.new_cipher->algorithm_mkey;
if (alg_k & SSL_kRSA) {
*pname = "rsa";
return SSL_kRSA;
}
if (alg_k & SSL_kDHE) {
*pname = "DHE";
return SSL_kDHE;
}
if (alg_k & SSL_kECDHE) {
*pname = "ECDHE";
return SSL_kECDHE;
}
if (alg_k & SSL_kPSK) {
*pname = "PSK";
return SSL_kPSK;
}
if (alg_k & SSL_kRSAPSK) {
*pname = "RSAPSK";
return SSL_kRSAPSK;
}
if (alg_k & SSL_kDHEPSK) {
*pname = "DHEPSK";
return SSL_kDHEPSK;
}
if (alg_k & SSL_kECDHEPSK) {
*pname = "ECDHEPSK";
return SSL_kECDHEPSK;
}
if (alg_k & SSL_kSRP) {
*pname = "SRP";
return SSL_kSRP;
}
if (alg_k & SSL_kGOST) {
*pname = "GOST";
return SSL_kGOST;
}
*pname = "UNKNOWN";
return 0;
}
static int ssl_print_client_keyex(BIO *bio, int indent, SSL *ssl,
const unsigned char *msg, size_t msglen)
{
const char *algname;
int id;
id = ssl_get_keyex(&algname, ssl);
BIO_indent(bio, indent, 80);
BIO_printf(bio, "KeyExchangeAlgorithm=%s\n", algname);
if (id & SSL_PSK) {
if (!ssl_print_hexbuf(bio, indent + 2,
"psk_identity", 2, &msg, &msglen))
return 0;
}
switch (id) {
case SSL_kRSA:
case SSL_kRSAPSK:
if (TLS1_get_version(ssl) == SSL3_VERSION) {
ssl_print_hex(bio, indent + 2,
"EncyptedPreMasterSecret", msg, msglen);
} else {
if (!ssl_print_hexbuf(bio, indent + 2,
"EncyptedPreMasterSecret", 2, &msg, &msglen))
return 0;
}
break;
case SSL_kDHE:
case SSL_kDHEPSK:
if (!ssl_print_hexbuf(bio, indent + 2, "dh_Yc", 2, &msg, &msglen))
return 0;
break;
case SSL_kECDHE:
case SSL_kECDHEPSK:
if (!ssl_print_hexbuf(bio, indent + 2, "ecdh_Yc", 1, &msg, &msglen))
return 0;
break;
}
return !msglen;
}
static int ssl_print_server_keyex(BIO *bio, int indent, SSL *ssl,
const unsigned char *msg, size_t msglen)
{
const char *algname;
int id;
id = ssl_get_keyex(&algname, ssl);
BIO_indent(bio, indent, 80);
BIO_printf(bio, "KeyExchangeAlgorithm=%s\n", algname);
if (id & SSL_PSK) {
if (!ssl_print_hexbuf(bio, indent + 2,
"psk_identity_hint", 2, &msg, &msglen))
return 0;
}
switch (id) {
case SSL_kRSA:
if (!ssl_print_hexbuf(bio, indent + 2, "rsa_modulus", 2, &msg, &msglen))
return 0;
if (!ssl_print_hexbuf(bio, indent + 2, "rsa_exponent", 2,
&msg, &msglen))
return 0;
break;
case SSL_kDHE:
case SSL_kDHEPSK:
if (!ssl_print_hexbuf(bio, indent + 2, "dh_p", 2, &msg, &msglen))
return 0;
if (!ssl_print_hexbuf(bio, indent + 2, "dh_g", 2, &msg, &msglen))
return 0;
if (!ssl_print_hexbuf(bio, indent + 2, "dh_Ys", 2, &msg, &msglen))
return 0;
break;
# ifndef OPENSSL_NO_EC
case SSL_kECDHE:
case SSL_kECDHEPSK:
if (msglen < 1)
return 0;
BIO_indent(bio, indent + 2, 80);
if (msg[0] == EXPLICIT_PRIME_CURVE_TYPE)
BIO_puts(bio, "explicit_prime\n");
else if (msg[0] == EXPLICIT_CHAR2_CURVE_TYPE)
BIO_puts(bio, "explicit_char2\n");
else if (msg[0] == NAMED_CURVE_TYPE) {
int curve;
if (msglen < 3)
return 0;
curve = (msg[1] << 8) | msg[2];
BIO_printf(bio, "named_curve: %s (%d)\n",
ssl_trace_str(curve, ssl_curve_tbl), curve);
msg += 3;
msglen -= 3;
if (!ssl_print_hexbuf(bio, indent + 2, "point", 1, &msg, &msglen))
return 0;
} else {
BIO_printf(bio, "UNKNOWN CURVE PARAMETER TYPE %d\n", msg[0]);
return 0;
}
break;
# endif
case SSL_kPSK:
case SSL_kRSAPSK:
break;
}
if (!(id & SSL_PSK))
ssl_print_signature(bio, indent, ssl, &msg, &msglen);
return !msglen;
}
static int ssl_print_certificate(BIO *bio, int indent,
const unsigned char **pmsg, size_t *pmsglen)
{
size_t msglen = *pmsglen;
size_t clen;
X509 *x;
const unsigned char *p = *pmsg, *q;
if (msglen < 3)
return 0;
clen = (p[0] << 16) | (p[1] << 8) | p[2];
if (msglen < clen + 3)
return 0;
q = p + 3;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "ASN.1Cert, length=%d", (int)clen);
x = d2i_X509(NULL, &q, clen);
if (!x)
BIO_puts(bio, "<UNPARSEABLE CERTIFICATE>\n");
else {
BIO_puts(bio, "\n------details-----\n");
X509_print_ex(bio, x, XN_FLAG_ONELINE, 0);
PEM_write_bio_X509(bio, x);
BIO_puts(bio, "------------------\n");
X509_free(x);
}
if (q != p + 3 + clen) {
BIO_puts(bio, "<TRAILING GARBAGE AFTER CERTIFICATE>\n");
}
*pmsg += clen + 3;
*pmsglen -= clen + 3;
return 1;
}
static int ssl_print_certificates(BIO *bio, int indent,
const unsigned char *msg, size_t msglen)
{
size_t clen;
if (msglen < 3)
return 0;
clen = (msg[0] << 16) | (msg[1] << 8) | msg[2];
if (msglen != clen + 3)
return 0;
msg += 3;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "certificate_list, length=%d\n", (int)clen);
while (clen > 0) {
if (!ssl_print_certificate(bio, indent + 2, &msg, &clen))
return 0;
}
return 1;
}
static int ssl_print_cert_request(BIO *bio, int indent, SSL *s,
const unsigned char *msg, size_t msglen)
{
size_t xlen;
if (msglen < 1)
return 0;
xlen = msg[0];
if (msglen < xlen + 1)
return 0;
msg++;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "certificate_types (len=%d)\n", (int)xlen);
if (!ssl_trace_list(bio, indent + 2, msg, xlen, 1, ssl_ctype_tbl))
return 0;
msg += xlen;
msglen -= xlen + 1;
if (!SSL_USE_SIGALGS(s))
goto skip_sig;
if (msglen < 2)
return 0;
xlen = (msg[0] << 8) | msg[1];
if (msglen < xlen + 2 || (xlen & 1))
return 0;
msg += 2;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "signature_algorithms (len=%d)\n", (int)xlen);
while (xlen > 0) {
BIO_indent(bio, indent + 2, 80);
BIO_printf(bio, "%s+%s (%d+%d)\n",
ssl_trace_str(msg[0], ssl_md_tbl),
ssl_trace_str(msg[1], ssl_sig_tbl), msg[0], msg[1]);
xlen -= 2;
msg += 2;
}
msg += xlen;
msglen -= xlen + 2;
skip_sig:
xlen = (msg[0] << 8) | msg[1];
BIO_indent(bio, indent, 80);
if (msglen < xlen + 2)
return 0;
msg += 2;
msglen -= 2;
BIO_printf(bio, "certificate_authorities (len=%d)\n", (int)xlen);
while (xlen > 0) {
size_t dlen;
X509_NAME *nm;
const unsigned char *p;
if (xlen < 2)
return 0;
dlen = (msg[0] << 8) | msg[1];
if (xlen < dlen + 2)
return 0;
msg += 2;
BIO_indent(bio, indent + 2, 80);
BIO_printf(bio, "DistinguishedName (len=%d): ", (int)dlen);
p = msg;
nm = d2i_X509_NAME(NULL, &p, dlen);
if (!nm) {
BIO_puts(bio, "<UNPARSEABLE DN>\n");
} else {
X509_NAME_print_ex(bio, nm, 0, XN_FLAG_ONELINE);
BIO_puts(bio, "\n");
X509_NAME_free(nm);
}
xlen -= dlen + 2;
msg += dlen;
}
return 1;
}
static int ssl_print_ticket(BIO *bio, int indent,
const unsigned char *msg, size_t msglen)
{
unsigned int tick_life;
if (msglen == 0) {
BIO_indent(bio, indent + 2, 80);
BIO_puts(bio, "No Ticket\n");
return 1;
}
if (msglen < 4)
return 0;
tick_life = (msg[0] << 24) | (msg[1] << 16) | (msg[2] << 8) | msg[3];
msglen -= 4;
msg += 4;
BIO_indent(bio, indent + 2, 80);
BIO_printf(bio, "ticket_lifetime_hint=%u\n", tick_life);
if (!ssl_print_hexbuf(bio, indent + 2, "ticket", 2, &msg, &msglen))
return 0;
if (msglen)
return 0;
return 1;
}
static int ssl_print_handshake(BIO *bio, SSL *ssl,
const unsigned char *msg, size_t msglen,
int indent)
{
size_t hlen;
unsigned char htype;
if (msglen < 4)
return 0;
htype = msg[0];
hlen = (msg[1] << 16) | (msg[2] << 8) | msg[3];
BIO_indent(bio, indent, 80);
BIO_printf(bio, "%s, Length=%d\n",
ssl_trace_str(htype, ssl_handshake_tbl), (int)hlen);
msg += 4;
msglen -= 4;
if (SSL_IS_DTLS(ssl)) {
if (msglen < 8)
return 0;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "message_seq=%d, fragment_offset=%d, "
"fragment_length=%d\n",
(msg[0] << 8) | msg[1],
(msg[2] << 16) | (msg[3] << 8) | msg[4],
(msg[5] << 16) | (msg[6] << 8) | msg[7]);
msg += 8;
msglen -= 8;
}
if (msglen < hlen)
return 0;
switch (htype) {
case SSL3_MT_CLIENT_HELLO:
if (!ssl_print_client_hello(bio, ssl, indent + 2, msg, msglen))
return 0;
break;
case DTLS1_MT_HELLO_VERIFY_REQUEST:
if (!dtls_print_hello_vfyrequest(bio, indent + 2, msg, msglen))
return 0;
break;
case SSL3_MT_SERVER_HELLO:
if (!ssl_print_server_hello(bio, indent + 2, msg, msglen))
return 0;
break;
case SSL3_MT_SERVER_KEY_EXCHANGE:
if (!ssl_print_server_keyex(bio, indent + 2, ssl, msg, msglen))
return 0;
break;
case SSL3_MT_CLIENT_KEY_EXCHANGE:
if (!ssl_print_client_keyex(bio, indent + 2, ssl, msg, msglen))
return 0;
break;
case SSL3_MT_CERTIFICATE:
if (!ssl_print_certificates(bio, indent + 2, msg, msglen))
return 0;
break;
case SSL3_MT_CERTIFICATE_VERIFY:
if (!ssl_print_signature(bio, indent + 2, ssl, &msg, &msglen))
return 0;
break;
case SSL3_MT_CERTIFICATE_REQUEST:
if (!ssl_print_cert_request(bio, indent + 2, ssl, msg, msglen))
return 0;
break;
case SSL3_MT_FINISHED:
ssl_print_hex(bio, indent + 2, "verify_data", msg, msglen);
break;
case SSL3_MT_SERVER_DONE:
if (msglen != 0)
ssl_print_hex(bio, indent + 2, "unexpected value", msg, msglen);
break;
case SSL3_MT_NEWSESSION_TICKET:
if (!ssl_print_ticket(bio, indent + 2, msg, msglen))
return 0;
break;
default:
BIO_indent(bio, indent + 2, 80);
BIO_puts(bio, "Unsupported, hex dump follows:\n");
BIO_dump_indent(bio, (const char *)msg, msglen, indent + 4);
}
return 1;
}
static int ssl_print_heartbeat(BIO *bio, int indent,
const unsigned char *msg, size_t msglen)
{
if (msglen < 3)
return 0;
BIO_indent(bio, indent, 80);
BIO_printf(bio, "HeartBeatMessageType: %s\n",
ssl_trace_str(msg[0], ssl_hb_type_tbl));
msg++;
msglen--;
if (!ssl_print_hexbuf(bio, indent, "payload", 2, &msg, &msglen))
return 0;
ssl_print_hex(bio, indent, "padding", msg, msglen);
return 1;
}
const char *SSL_CIPHER_standard_name(const SSL_CIPHER *c)
{
return ssl_trace_str(c->id & 0xFFFF, ssl_ciphers_tbl);
}
void SSL_trace(int write_p, int version, int content_type,
const void *buf, size_t msglen, SSL *ssl, void *arg)
{
const unsigned char *msg = buf;
BIO *bio = arg;
if (write_p == 2) {
BIO_puts(bio, "Session ");
ssl_print_hex(bio, 0,
ssl_trace_str(content_type, ssl_crypto_tbl), msg, msglen);
return;
}
switch (content_type) {
case SSL3_RT_HEADER:
{
int hvers = msg[1] << 8 | msg[2];
BIO_puts(bio, write_p ? "Sent" : "Received");
BIO_printf(bio, " Record\nHeader:\n Version = %s (0x%x)\n",
ssl_trace_str(hvers, ssl_version_tbl), hvers);
if (SSL_IS_DTLS(ssl)) {
BIO_printf(bio,
" epoch=%d, sequence_number=%04x%04x%04x\n",
(msg[3] << 8 | msg[4]),
(msg[5] << 8 | msg[6]),
(msg[7] << 8 | msg[8]), (msg[9] << 8 | msg[10]));
}
BIO_printf(bio, " Content Type = %s (%d)\n Length = %d",
ssl_trace_str(msg[0], ssl_content_tbl), msg[0],
msg[msglen - 2] << 8 | msg[msglen - 1]);
}
break;
case SSL3_RT_HANDSHAKE:
if (!ssl_print_handshake(bio, ssl, msg, msglen, 4))
BIO_printf(bio, "Message length parse error!\n");
break;
case SSL3_RT_CHANGE_CIPHER_SPEC:
if (msglen == 1 && msg[0] == 1)
BIO_puts(bio, " change_cipher_spec (1)\n");
else
ssl_print_hex(bio, 4, "unknown value", msg, msglen);
break;
case SSL3_RT_ALERT:
if (msglen != 2)
BIO_puts(bio, " Illegal Alert Length\n");
else {
BIO_printf(bio, " Level=%s(%d), description=%s(%d)\n",
SSL_alert_type_string_long(msg[0] << 8),
msg[0], SSL_alert_desc_string_long(msg[1]), msg[1]);
}
case DTLS1_RT_HEARTBEAT:
ssl_print_heartbeat(bio, 4, msg, msglen);
break;
}
BIO_puts(bio, "\n");
}
