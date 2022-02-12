void drain_openssl_errors(void)
{
const char *file;
int line;
if (ERR_peek_error() == 0)
return;
while (ERR_get_error_line(&file, &line)) {}
}
static void write_cert(X509 *x509)
{
char buf[200];
if (!wb) {
wb = BIO_new_file(cert_dst, "wb");
ERR(!wb, "%s", cert_dst);
}
X509_NAME_oneline(X509_get_subject_name(x509), buf, sizeof(buf));
ERR(!i2d_X509_bio(wb, x509), "%s", cert_dst);
if (kbuild_verbose)
fprintf(stderr, "Extracted cert: %s\n", buf);
}
int main(int argc, char **argv)
{
char *cert_src;
OpenSSL_add_all_algorithms();
ERR_load_crypto_strings();
ERR_clear_error();
kbuild_verbose = atoi(getenv("KBUILD_VERBOSE")?:"0");
key_pass = getenv("KBUILD_SIGN_PIN");
if (argc != 3)
format();
cert_src = argv[1];
cert_dst = argv[2];
if (!cert_src[0]) {
FILE *f = fopen(cert_dst, "wb");
ERR(!f, "%s", cert_dst);
fclose(f);
exit(0);
} else if (!strncmp(cert_src, "pkcs11:", 7)) {
ENGINE *e;
struct {
const char *cert_id;
X509 *cert;
} parms;
parms.cert_id = cert_src;
parms.cert = NULL;
ENGINE_load_builtin_engines();
drain_openssl_errors();
e = ENGINE_by_id("pkcs11");
ERR(!e, "Load PKCS#11 ENGINE");
if (ENGINE_init(e))
drain_openssl_errors();
else
ERR(1, "ENGINE_init");
if (key_pass)
ERR(!ENGINE_ctrl_cmd_string(e, "PIN", key_pass, 0), "Set PKCS#11 PIN");
ENGINE_ctrl_cmd(e, "LOAD_CERT_CTRL", 0, &parms, NULL, 1);
ERR(!parms.cert, "Get X.509 from PKCS#11");
write_cert(parms.cert);
} else {
BIO *b;
X509 *x509;
b = BIO_new_file(cert_src, "rb");
ERR(!b, "%s", cert_src);
while (1) {
x509 = PEM_read_bio_X509(b, NULL, NULL, NULL);
if (wb && !x509) {
unsigned long err = ERR_peek_last_error();
if (ERR_GET_LIB(err) == ERR_LIB_PEM &&
ERR_GET_REASON(err) == PEM_R_NO_START_LINE) {
ERR_clear_error();
break;
}
}
ERR(!x509, "%s", cert_src);
write_cert(x509);
}
}
BIO_free(wb);
return 0;
}
