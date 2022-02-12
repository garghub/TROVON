void drain_openssl_errors(void)
{
const char *file;
int line;
if (ERR_peek_error() == 0)
return;
while (ERR_get_error_line(&file, &line)) {}
}
static int pem_pw_cb(char *buf, int len, int w, void *v)
{
int pwlen;
if (!key_pass)
return -1;
pwlen = strlen(key_pass);
if (pwlen >= len)
return -1;
strcpy(buf, key_pass);
key_pass = NULL;
return pwlen;
}
static EVP_PKEY *read_private_key(const char *private_key_name)
{
EVP_PKEY *private_key;
if (!strncmp(private_key_name, "pkcs11:", 7)) {
ENGINE *e;
ENGINE_load_builtin_engines();
drain_openssl_errors();
e = ENGINE_by_id("pkcs11");
ERR(!e, "Load PKCS#11 ENGINE");
if (ENGINE_init(e))
drain_openssl_errors();
else
ERR(1, "ENGINE_init");
if (key_pass)
ERR(!ENGINE_ctrl_cmd_string(e, "PIN", key_pass, 0),
"Set PKCS#11 PIN");
private_key = ENGINE_load_private_key(e, private_key_name,
NULL, NULL);
ERR(!private_key, "%s", private_key_name);
} else {
BIO *b;
b = BIO_new_file(private_key_name, "rb");
ERR(!b, "%s", private_key_name);
private_key = PEM_read_bio_PrivateKey(b, NULL, pem_pw_cb,
NULL);
ERR(!private_key, "%s", private_key_name);
BIO_free(b);
}
return private_key;
}
static X509 *read_x509(const char *x509_name)
{
unsigned char buf[2];
X509 *x509;
BIO *b;
int n;
b = BIO_new_file(x509_name, "rb");
ERR(!b, "%s", x509_name);
n = BIO_read(b, buf, 2);
if (n != 2) {
if (BIO_should_retry(b)) {
fprintf(stderr, "%s: Read wanted retry\n", x509_name);
exit(1);
}
if (n >= 0) {
fprintf(stderr, "%s: Short read\n", x509_name);
exit(1);
}
ERR(1, "%s", x509_name);
}
ERR(BIO_reset(b) != 0, "%s", x509_name);
if (buf[0] == 0x30 && buf[1] >= 0x81 && buf[1] <= 0x84)
x509 = d2i_X509_bio(b, NULL);
else
x509 = PEM_read_bio_X509(b, NULL, NULL, NULL);
BIO_free(b);
ERR(!x509, "%s", x509_name);
return x509;
}
int main(int argc, char **argv)
{
struct module_signature sig_info = { .id_type = PKEY_ID_PKCS7 };
char *hash_algo = NULL;
char *private_key_name = NULL, *raw_sig_name = NULL;
char *x509_name, *module_name, *dest_name;
bool save_sig = false, replace_orig;
bool sign_only = false;
bool raw_sig = false;
unsigned char buf[4096];
unsigned long module_size, sig_size;
unsigned int use_signed_attrs;
const EVP_MD *digest_algo;
EVP_PKEY *private_key;
#ifndef USE_PKCS7
CMS_ContentInfo *cms = NULL;
unsigned int use_keyid = 0;
#else
PKCS7 *pkcs7 = NULL;
#endif
X509 *x509;
BIO *bd, *bm;
int opt, n;
OpenSSL_add_all_algorithms();
ERR_load_crypto_strings();
ERR_clear_error();
key_pass = getenv("KBUILD_SIGN_PIN");
#ifndef USE_PKCS7
use_signed_attrs = CMS_NOATTR;
#else
use_signed_attrs = PKCS7_NOATTR;
#endif
do {
opt = getopt(argc, argv, "sdpk");
switch (opt) {
case 's': raw_sig = true; break;
case 'p': save_sig = true; break;
case 'd': sign_only = true; save_sig = true; break;
#ifndef USE_PKCS7
case 'k': use_keyid = CMS_USE_KEYID; break;
#endif
case -1: break;
default: format();
}
} while (opt != -1);
argc -= optind;
argv += optind;
if (argc < 4 || argc > 5)
format();
if (raw_sig) {
raw_sig_name = argv[0];
hash_algo = argv[1];
} else {
hash_algo = argv[0];
private_key_name = argv[1];
}
x509_name = argv[2];
module_name = argv[3];
if (argc == 5) {
dest_name = argv[4];
replace_orig = false;
} else {
ERR(asprintf(&dest_name, "%s.~signed~", module_name) < 0,
"asprintf");
replace_orig = true;
}
#ifdef USE_PKCS7
if (strcmp(hash_algo, "sha1") != 0) {
fprintf(stderr, "sign-file: %s only supports SHA1 signing\n",
OPENSSL_VERSION_TEXT);
exit(3);
}
#endif
bm = BIO_new_file(module_name, "rb");
ERR(!bm, "%s", module_name);
if (!raw_sig) {
private_key = read_private_key(private_key_name);
x509 = read_x509(x509_name);
OpenSSL_add_all_digests();
display_openssl_errors(__LINE__);
digest_algo = EVP_get_digestbyname(hash_algo);
ERR(!digest_algo, "EVP_get_digestbyname");
#ifndef USE_PKCS7
cms = CMS_sign(NULL, NULL, NULL, NULL,
CMS_NOCERTS | CMS_PARTIAL | CMS_BINARY |
CMS_DETACHED | CMS_STREAM);
ERR(!cms, "CMS_sign");
ERR(!CMS_add1_signer(cms, x509, private_key, digest_algo,
CMS_NOCERTS | CMS_BINARY |
CMS_NOSMIMECAP | use_keyid |
use_signed_attrs),
"CMS_add1_signer");
ERR(CMS_final(cms, bm, NULL, CMS_NOCERTS | CMS_BINARY) < 0,
"CMS_final");
#else
pkcs7 = PKCS7_sign(x509, private_key, NULL, bm,
PKCS7_NOCERTS | PKCS7_BINARY |
PKCS7_DETACHED | use_signed_attrs);
ERR(!pkcs7, "PKCS7_sign");
#endif
if (save_sig) {
char *sig_file_name;
BIO *b;
ERR(asprintf(&sig_file_name, "%s.p7s", module_name) < 0,
"asprintf");
b = BIO_new_file(sig_file_name, "wb");
ERR(!b, "%s", sig_file_name);
#ifndef USE_PKCS7
ERR(i2d_CMS_bio_stream(b, cms, NULL, 0) < 0,
"%s", sig_file_name);
#else
ERR(i2d_PKCS7_bio(b, pkcs7) < 0,
"%s", sig_file_name);
#endif
BIO_free(b);
}
if (sign_only) {
BIO_free(bm);
return 0;
}
}
bd = BIO_new_file(dest_name, "wb");
ERR(!bd, "%s", dest_name);
ERR(BIO_reset(bm) < 0, "%s", module_name);
while ((n = BIO_read(bm, buf, sizeof(buf))),
n > 0) {
ERR(BIO_write(bd, buf, n) < 0, "%s", dest_name);
}
BIO_free(bm);
ERR(n < 0, "%s", module_name);
module_size = BIO_number_written(bd);
if (!raw_sig) {
#ifndef USE_PKCS7
ERR(i2d_CMS_bio_stream(bd, cms, NULL, 0) < 0, "%s", dest_name);
#else
ERR(i2d_PKCS7_bio(bd, pkcs7) < 0, "%s", dest_name);
#endif
} else {
BIO *b;
b = BIO_new_file(raw_sig_name, "rb");
ERR(!b, "%s", raw_sig_name);
while ((n = BIO_read(b, buf, sizeof(buf))), n > 0)
ERR(BIO_write(bd, buf, n) < 0, "%s", dest_name);
BIO_free(b);
}
sig_size = BIO_number_written(bd) - module_size;
sig_info.sig_len = htonl(sig_size);
ERR(BIO_write(bd, &sig_info, sizeof(sig_info)) < 0, "%s", dest_name);
ERR(BIO_write(bd, magic_number, sizeof(magic_number) - 1) < 0, "%s", dest_name);
ERR(BIO_free(bd) < 0, "%s", dest_name);
if (replace_orig)
ERR(rename(dest_name, module_name) < 0, "%s", dest_name);
return 0;
}
