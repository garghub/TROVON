int MAIN(int argc, char **argv)
{
ENGINE *e = NULL;
int operation = 0;
int ret = 0;
char **args;
const char *inmode = "r", *outmode = "w";
char *infile = NULL, *outfile = NULL, *rctfile = NULL;
char *signerfile = NULL, *recipfile = NULL;
STACK_OF(OPENSSL_STRING) *sksigners = NULL, *skkeys = NULL;
char *certfile = NULL, *keyfile = NULL, *contfile = NULL;
char *certsoutfile = NULL;
const EVP_CIPHER *cipher = NULL, *wrap_cipher = NULL;
CMS_ContentInfo *cms = NULL, *rcms = NULL;
X509_STORE *store = NULL;
X509 *cert = NULL, *recip = NULL, *signer = NULL;
EVP_PKEY *key = NULL;
STACK_OF(X509) *encerts = NULL, *other = NULL;
BIO *in = NULL, *out = NULL, *indata = NULL, *rctin = NULL;
int badarg = 0;
int flags = CMS_DETACHED, noout = 0, print = 0;
int verify_retcode = 0;
int rr_print = 0, rr_allorfirst = -1;
STACK_OF(OPENSSL_STRING) *rr_to = NULL, *rr_from = NULL;
CMS_ReceiptRequest *rr = NULL;
char *to = NULL, *from = NULL, *subject = NULL;
char *CAfile = NULL, *CApath = NULL;
char *passargin = NULL, *passin = NULL;
char *inrand = NULL;
int need_rand = 0;
const EVP_MD *sign_md = NULL;
int informat = FORMAT_SMIME, outformat = FORMAT_SMIME;
int rctformat = FORMAT_SMIME, keyform = FORMAT_PEM;
# ifndef OPENSSL_NO_ENGINE
char *engine = NULL;
# endif
unsigned char *secret_key = NULL, *secret_keyid = NULL;
unsigned char *pwri_pass = NULL, *pwri_tmp = NULL;
size_t secret_keylen = 0, secret_keyidlen = 0;
cms_key_param *key_first = NULL, *key_param = NULL;
ASN1_OBJECT *econtent_type = NULL;
X509_VERIFY_PARAM *vpm = NULL;
args = argv + 1;
ret = 1;
apps_startup();
if (bio_err == NULL) {
if ((bio_err = BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err, stderr, BIO_NOCLOSE | BIO_FP_TEXT);
}
if (!load_config(bio_err, NULL))
goto end;
while (!badarg && *args && *args[0] == '-') {
if (!strcmp(*args, "-encrypt"))
operation = SMIME_ENCRYPT;
else if (!strcmp(*args, "-decrypt"))
operation = SMIME_DECRYPT;
else if (!strcmp(*args, "-sign"))
operation = SMIME_SIGN;
else if (!strcmp(*args, "-sign_receipt"))
operation = SMIME_SIGN_RECEIPT;
else if (!strcmp(*args, "-resign"))
operation = SMIME_RESIGN;
else if (!strcmp(*args, "-verify"))
operation = SMIME_VERIFY;
else if (!strcmp(*args, "-verify_retcode"))
verify_retcode = 1;
else if (!strcmp(*args, "-verify_receipt")) {
operation = SMIME_VERIFY_RECEIPT;
if (!args[1])
goto argerr;
args++;
rctfile = *args;
} else if (!strcmp(*args, "-cmsout"))
operation = SMIME_CMSOUT;
else if (!strcmp(*args, "-data_out"))
operation = SMIME_DATAOUT;
else if (!strcmp(*args, "-data_create"))
operation = SMIME_DATA_CREATE;
else if (!strcmp(*args, "-digest_verify"))
operation = SMIME_DIGEST_VERIFY;
else if (!strcmp(*args, "-digest_create"))
operation = SMIME_DIGEST_CREATE;
else if (!strcmp(*args, "-compress"))
operation = SMIME_COMPRESS;
else if (!strcmp(*args, "-uncompress"))
operation = SMIME_UNCOMPRESS;
else if (!strcmp(*args, "-EncryptedData_decrypt"))
operation = SMIME_ENCRYPTED_DECRYPT;
else if (!strcmp(*args, "-EncryptedData_encrypt"))
operation = SMIME_ENCRYPTED_ENCRYPT;
# ifndef OPENSSL_NO_DES
else if (!strcmp(*args, "-des3"))
cipher = EVP_des_ede3_cbc();
else if (!strcmp(*args, "-des"))
cipher = EVP_des_cbc();
else if (!strcmp(*args, "-des3-wrap"))
wrap_cipher = EVP_des_ede3_wrap();
# endif
# ifndef OPENSSL_NO_SEED
else if (!strcmp(*args, "-seed"))
cipher = EVP_seed_cbc();
# endif
# ifndef OPENSSL_NO_RC2
else if (!strcmp(*args, "-rc2-40"))
cipher = EVP_rc2_40_cbc();
else if (!strcmp(*args, "-rc2-128"))
cipher = EVP_rc2_cbc();
else if (!strcmp(*args, "-rc2-64"))
cipher = EVP_rc2_64_cbc();
# endif
# ifndef OPENSSL_NO_AES
else if (!strcmp(*args, "-aes128"))
cipher = EVP_aes_128_cbc();
else if (!strcmp(*args, "-aes192"))
cipher = EVP_aes_192_cbc();
else if (!strcmp(*args, "-aes256"))
cipher = EVP_aes_256_cbc();
else if (!strcmp(*args, "-aes128-wrap"))
wrap_cipher = EVP_aes_128_wrap();
else if (!strcmp(*args, "-aes192-wrap"))
wrap_cipher = EVP_aes_192_wrap();
else if (!strcmp(*args, "-aes256-wrap"))
wrap_cipher = EVP_aes_256_wrap();
# endif
# ifndef OPENSSL_NO_CAMELLIA
else if (!strcmp(*args, "-camellia128"))
cipher = EVP_camellia_128_cbc();
else if (!strcmp(*args, "-camellia192"))
cipher = EVP_camellia_192_cbc();
else if (!strcmp(*args, "-camellia256"))
cipher = EVP_camellia_256_cbc();
# endif
else if (!strcmp(*args, "-debug_decrypt"))
flags |= CMS_DEBUG_DECRYPT;
else if (!strcmp(*args, "-text"))
flags |= CMS_TEXT;
else if (!strcmp(*args, "-nointern"))
flags |= CMS_NOINTERN;
else if (!strcmp(*args, "-noverify")
|| !strcmp(*args, "-no_signer_cert_verify"))
flags |= CMS_NO_SIGNER_CERT_VERIFY;
else if (!strcmp(*args, "-nocerts"))
flags |= CMS_NOCERTS;
else if (!strcmp(*args, "-noattr"))
flags |= CMS_NOATTR;
else if (!strcmp(*args, "-nodetach"))
flags &= ~CMS_DETACHED;
else if (!strcmp(*args, "-nosmimecap"))
flags |= CMS_NOSMIMECAP;
else if (!strcmp(*args, "-binary"))
flags |= CMS_BINARY;
else if (!strcmp(*args, "-keyid"))
flags |= CMS_USE_KEYID;
else if (!strcmp(*args, "-nosigs"))
flags |= CMS_NOSIGS;
else if (!strcmp(*args, "-no_content_verify"))
flags |= CMS_NO_CONTENT_VERIFY;
else if (!strcmp(*args, "-no_attr_verify"))
flags |= CMS_NO_ATTR_VERIFY;
else if (!strcmp(*args, "-stream"))
flags |= CMS_STREAM;
else if (!strcmp(*args, "-indef"))
flags |= CMS_STREAM;
else if (!strcmp(*args, "-noindef"))
flags &= ~CMS_STREAM;
else if (!strcmp(*args, "-nooldmime"))
flags |= CMS_NOOLDMIMETYPE;
else if (!strcmp(*args, "-crlfeol"))
flags |= CMS_CRLFEOL;
else if (!strcmp(*args, "-noout"))
noout = 1;
else if (!strcmp(*args, "-receipt_request_print"))
rr_print = 1;
else if (!strcmp(*args, "-receipt_request_all"))
rr_allorfirst = 0;
else if (!strcmp(*args, "-receipt_request_first"))
rr_allorfirst = 1;
else if (!strcmp(*args, "-receipt_request_from")) {
if (!args[1])
goto argerr;
args++;
if (!rr_from)
rr_from = sk_OPENSSL_STRING_new_null();
sk_OPENSSL_STRING_push(rr_from, *args);
} else if (!strcmp(*args, "-receipt_request_to")) {
if (!args[1])
goto argerr;
args++;
if (!rr_to)
rr_to = sk_OPENSSL_STRING_new_null();
sk_OPENSSL_STRING_push(rr_to, *args);
} else if (!strcmp(*args, "-print")) {
noout = 1;
print = 1;
} else if (!strcmp(*args, "-secretkey")) {
long ltmp;
if (!args[1])
goto argerr;
args++;
secret_key = string_to_hex(*args, &ltmp);
if (!secret_key) {
BIO_printf(bio_err, "Invalid key %s\n", *args);
goto argerr;
}
secret_keylen = (size_t)ltmp;
} else if (!strcmp(*args, "-secretkeyid")) {
long ltmp;
if (!args[1])
goto argerr;
args++;
secret_keyid = string_to_hex(*args, &ltmp);
if (!secret_keyid) {
BIO_printf(bio_err, "Invalid id %s\n", *args);
goto argerr;
}
secret_keyidlen = (size_t)ltmp;
} else if (!strcmp(*args, "-pwri_password")) {
if (!args[1])
goto argerr;
args++;
pwri_pass = (unsigned char *)*args;
} else if (!strcmp(*args, "-econtent_type")) {
if (!args[1])
goto argerr;
args++;
econtent_type = OBJ_txt2obj(*args, 0);
if (!econtent_type) {
BIO_printf(bio_err, "Invalid OID %s\n", *args);
goto argerr;
}
} else if (!strcmp(*args, "-rand")) {
if (!args[1])
goto argerr;
args++;
inrand = *args;
need_rand = 1;
}
# ifndef OPENSSL_NO_ENGINE
else if (!strcmp(*args, "-engine")) {
if (!args[1])
goto argerr;
engine = *++args;
}
# endif
else if (!strcmp(*args, "-passin")) {
if (!args[1])
goto argerr;
passargin = *++args;
} else if (!strcmp(*args, "-to")) {
if (!args[1])
goto argerr;
to = *++args;
} else if (!strcmp(*args, "-from")) {
if (!args[1])
goto argerr;
from = *++args;
} else if (!strcmp(*args, "-subject")) {
if (!args[1])
goto argerr;
subject = *++args;
} else if (!strcmp(*args, "-signer")) {
if (!args[1])
goto argerr;
if (signerfile) {
if (!sksigners)
sksigners = sk_OPENSSL_STRING_new_null();
sk_OPENSSL_STRING_push(sksigners, signerfile);
if (!keyfile)
keyfile = signerfile;
if (!skkeys)
skkeys = sk_OPENSSL_STRING_new_null();
sk_OPENSSL_STRING_push(skkeys, keyfile);
keyfile = NULL;
}
signerfile = *++args;
} else if (!strcmp(*args, "-recip")) {
if (!args[1])
goto argerr;
if (operation == SMIME_ENCRYPT) {
if (!encerts)
encerts = sk_X509_new_null();
cert = load_cert(bio_err, *++args, FORMAT_PEM,
NULL, e, "recipient certificate file");
if (!cert)
goto end;
sk_X509_push(encerts, cert);
cert = NULL;
} else
recipfile = *++args;
} else if (!strcmp(*args, "-certsout")) {
if (!args[1])
goto argerr;
certsoutfile = *++args;
} else if (!strcmp(*args, "-md")) {
if (!args[1])
goto argerr;
sign_md = EVP_get_digestbyname(*++args);
if (sign_md == NULL) {
BIO_printf(bio_err, "Unknown digest %s\n", *args);
goto argerr;
}
} else if (!strcmp(*args, "-inkey")) {
if (!args[1])
goto argerr;
if (keyfile) {
if (!signerfile) {
BIO_puts(bio_err, "Illegal -inkey without -signer\n");
goto argerr;
}
if (!sksigners)
sksigners = sk_OPENSSL_STRING_new_null();
sk_OPENSSL_STRING_push(sksigners, signerfile);
signerfile = NULL;
if (!skkeys)
skkeys = sk_OPENSSL_STRING_new_null();
sk_OPENSSL_STRING_push(skkeys, keyfile);
}
keyfile = *++args;
} else if (!strcmp(*args, "-keyform")) {
if (!args[1])
goto argerr;
keyform = str2fmt(*++args);
} else if (!strcmp(*args, "-keyopt")) {
int keyidx = -1;
if (!args[1])
goto argerr;
if (operation == SMIME_ENCRYPT) {
if (encerts)
keyidx += sk_X509_num(encerts);
} else {
if (keyfile || signerfile)
keyidx++;
if (skkeys)
keyidx += sk_OPENSSL_STRING_num(skkeys);
}
if (keyidx < 0) {
BIO_printf(bio_err, "No key specified\n");
goto argerr;
}
if (key_param == NULL || key_param->idx != keyidx) {
cms_key_param *nparam;
nparam = OPENSSL_malloc(sizeof(cms_key_param));
nparam->idx = keyidx;
nparam->param = sk_OPENSSL_STRING_new_null();
nparam->next = NULL;
if (key_first == NULL)
key_first = nparam;
else
key_param->next = nparam;
key_param = nparam;
}
sk_OPENSSL_STRING_push(key_param->param, *++args);
} else if (!strcmp(*args, "-rctform")) {
if (!args[1])
goto argerr;
rctformat = str2fmt(*++args);
} else if (!strcmp(*args, "-certfile")) {
if (!args[1])
goto argerr;
certfile = *++args;
} else if (!strcmp(*args, "-CAfile")) {
if (!args[1])
goto argerr;
CAfile = *++args;
} else if (!strcmp(*args, "-CApath")) {
if (!args[1])
goto argerr;
CApath = *++args;
} else if (!strcmp(*args, "-in")) {
if (!args[1])
goto argerr;
infile = *++args;
} else if (!strcmp(*args, "-inform")) {
if (!args[1])
goto argerr;
informat = str2fmt(*++args);
} else if (!strcmp(*args, "-outform")) {
if (!args[1])
goto argerr;
outformat = str2fmt(*++args);
} else if (!strcmp(*args, "-out")) {
if (!args[1])
goto argerr;
outfile = *++args;
} else if (!strcmp(*args, "-content")) {
if (!args[1])
goto argerr;
contfile = *++args;
} else if (args_verify(&args, NULL, &badarg, bio_err, &vpm))
continue;
else if ((cipher = EVP_get_cipherbyname(*args + 1)) == NULL)
badarg = 1;
args++;
}
if (((rr_allorfirst != -1) || rr_from) && !rr_to) {
BIO_puts(bio_err, "No Signed Receipts Recipients\n");
goto argerr;
}
if (!(operation & SMIME_SIGNERS) && (rr_to || rr_from)) {
BIO_puts(bio_err, "Signed receipts only allowed with -sign\n");
goto argerr;
}
if (!(operation & SMIME_SIGNERS) && (skkeys || sksigners)) {
BIO_puts(bio_err, "Multiple signers or keys not allowed\n");
goto argerr;
}
if (operation & SMIME_SIGNERS) {
if (keyfile && !signerfile) {
BIO_puts(bio_err, "Illegal -inkey without -signer\n");
goto argerr;
}
if (signerfile) {
if (!sksigners)
sksigners = sk_OPENSSL_STRING_new_null();
sk_OPENSSL_STRING_push(sksigners, signerfile);
if (!skkeys)
skkeys = sk_OPENSSL_STRING_new_null();
if (!keyfile)
keyfile = signerfile;
sk_OPENSSL_STRING_push(skkeys, keyfile);
}
if (!sksigners) {
BIO_printf(bio_err, "No signer certificate specified\n");
badarg = 1;
}
signerfile = NULL;
keyfile = NULL;
need_rand = 1;
}
else if (operation == SMIME_DECRYPT) {
if (!recipfile && !keyfile && !secret_key && !pwri_pass) {
BIO_printf(bio_err,
"No recipient certificate or key specified\n");
badarg = 1;
}
} else if (operation == SMIME_ENCRYPT) {
if (!*args && !secret_key && !pwri_pass && !encerts) {
BIO_printf(bio_err, "No recipient(s) certificate(s) specified\n");
badarg = 1;
}
need_rand = 1;
} else if (!operation)
badarg = 1;
if (badarg) {
argerr:
BIO_printf(bio_err, "Usage cms [options] cert.pem ...\n");
BIO_printf(bio_err, "where options are\n");
BIO_printf(bio_err, "-encrypt encrypt message\n");
BIO_printf(bio_err, "-decrypt decrypt encrypted message\n");
BIO_printf(bio_err, "-sign sign message\n");
BIO_printf(bio_err, "-verify verify signed message\n");
BIO_printf(bio_err, "-cmsout output CMS structure\n");
# ifndef OPENSSL_NO_DES
BIO_printf(bio_err, "-des3 encrypt with triple DES\n");
BIO_printf(bio_err, "-des encrypt with DES\n");
# endif
# ifndef OPENSSL_NO_SEED
BIO_printf(bio_err, "-seed encrypt with SEED\n");
# endif
# ifndef OPENSSL_NO_RC2
BIO_printf(bio_err, "-rc2-40 encrypt with RC2-40 (default)\n");
BIO_printf(bio_err, "-rc2-64 encrypt with RC2-64\n");
BIO_printf(bio_err, "-rc2-128 encrypt with RC2-128\n");
# endif
# ifndef OPENSSL_NO_AES
BIO_printf(bio_err, "-aes128, -aes192, -aes256\n");
BIO_printf(bio_err,
" encrypt PEM output with cbc aes\n");
# endif
# ifndef OPENSSL_NO_CAMELLIA
BIO_printf(bio_err, "-camellia128, -camellia192, -camellia256\n");
BIO_printf(bio_err,
" encrypt PEM output with cbc camellia\n");
# endif
BIO_printf(bio_err,
"-nointern don't search certificates in message for signer\n");
BIO_printf(bio_err,
"-nosigs don't verify message signature\n");
BIO_printf(bio_err,
"-noverify don't verify signers certificate\n");
BIO_printf(bio_err,
"-nocerts don't include signers certificate when signing\n");
BIO_printf(bio_err, "-nodetach use opaque signing\n");
BIO_printf(bio_err,
"-noattr don't include any signed attributes\n");
BIO_printf(bio_err,
"-binary don't translate message to text\n");
BIO_printf(bio_err, "-certfile file other certificates file\n");
BIO_printf(bio_err, "-certsout file certificate output file\n");
BIO_printf(bio_err, "-signer file signer certificate file\n");
BIO_printf(bio_err,
"-recip file recipient certificate file for decryption\n");
BIO_printf(bio_err, "-keyid use subject key identifier\n");
BIO_printf(bio_err, "-in file input file\n");
BIO_printf(bio_err,
"-inform arg input format SMIME (default), PEM or DER\n");
BIO_printf(bio_err,
"-inkey file input private key (if not signer or recipient)\n");
BIO_printf(bio_err,
"-keyform arg input private key format (PEM or ENGINE)\n");
BIO_printf(bio_err, "-keyopt nm:v set public key parameters\n");
BIO_printf(bio_err, "-out file output file\n");
BIO_printf(bio_err,
"-outform arg output format SMIME (default), PEM or DER\n");
BIO_printf(bio_err,
"-content file supply or override content for detached signature\n");
BIO_printf(bio_err, "-to addr to address\n");
BIO_printf(bio_err, "-from ad from address\n");
BIO_printf(bio_err, "-subject s subject\n");
BIO_printf(bio_err,
"-text include or delete text MIME headers\n");
BIO_printf(bio_err,
"-CApath dir trusted certificates directory\n");
BIO_printf(bio_err, "-CAfile file trusted certificates file\n");
BIO_printf(bio_err,
"-crl_check check revocation status of signer's certificate using CRLs\n");
BIO_printf(bio_err,
"-crl_check_all check revocation status of signer's certificate chain using CRLs\n");
# ifndef OPENSSL_NO_ENGINE
BIO_printf(bio_err,
"-engine e use engine e, possibly a hardware device.\n");
# endif
BIO_printf(bio_err, "-passin arg input file pass phrase source\n");
BIO_printf(bio_err, "-rand file%cfile%c...\n", LIST_SEPARATOR_CHAR,
LIST_SEPARATOR_CHAR);
BIO_printf(bio_err,
" load the file (or the files in the directory) into\n");
BIO_printf(bio_err, " the random number generator\n");
BIO_printf(bio_err,
"cert.pem recipient certificate(s) for encryption\n");
goto end;
}
# ifndef OPENSSL_NO_ENGINE
e = setup_engine(bio_err, engine, 0);
# endif
if (!app_passwd(bio_err, passargin, NULL, &passin, NULL)) {
BIO_printf(bio_err, "Error getting password\n");
goto end;
}
if (need_rand) {
app_RAND_load_file(NULL, bio_err, (inrand != NULL));
if (inrand != NULL)
BIO_printf(bio_err, "%ld semi-random bytes loaded\n",
app_RAND_load_files(inrand));
}
ret = 2;
if (!(operation & SMIME_SIGNERS))
flags &= ~CMS_DETACHED;
if (operation & SMIME_OP) {
if (outformat == FORMAT_ASN1)
outmode = "wb";
} else {
if (flags & CMS_BINARY)
outmode = "wb";
}
if (operation & SMIME_IP) {
if (informat == FORMAT_ASN1)
inmode = "rb";
} else {
if (flags & CMS_BINARY)
inmode = "rb";
}
if (operation == SMIME_ENCRYPT) {
if (!cipher) {
# ifndef OPENSSL_NO_DES
cipher = EVP_des_ede3_cbc();
# else
BIO_printf(bio_err, "No cipher selected\n");
goto end;
# endif
}
if (secret_key && !secret_keyid) {
BIO_printf(bio_err, "No secret key id\n");
goto end;
}
if (*args && !encerts)
encerts = sk_X509_new_null();
while (*args) {
if (!(cert = load_cert(bio_err, *args, FORMAT_PEM,
NULL, e, "recipient certificate file")))
goto end;
sk_X509_push(encerts, cert);
cert = NULL;
args++;
}
}
if (certfile) {
if (!(other = load_certs(bio_err, certfile, FORMAT_PEM, NULL,
e, "certificate file"))) {
ERR_print_errors(bio_err);
goto end;
}
}
if (recipfile && (operation == SMIME_DECRYPT)) {
if (!(recip = load_cert(bio_err, recipfile, FORMAT_PEM, NULL,
e, "recipient certificate file"))) {
ERR_print_errors(bio_err);
goto end;
}
}
if (operation == SMIME_SIGN_RECEIPT) {
if (!(signer = load_cert(bio_err, signerfile, FORMAT_PEM, NULL,
e, "receipt signer certificate file"))) {
ERR_print_errors(bio_err);
goto end;
}
}
if (operation == SMIME_DECRYPT) {
if (!keyfile)
keyfile = recipfile;
} else if ((operation == SMIME_SIGN) || (operation == SMIME_SIGN_RECEIPT)) {
if (!keyfile)
keyfile = signerfile;
} else
keyfile = NULL;
if (keyfile) {
key = load_key(bio_err, keyfile, keyform, 0, passin, e,
"signing key file");
if (!key)
goto end;
}
if (infile) {
if (!(in = BIO_new_file(infile, inmode))) {
BIO_printf(bio_err, "Can't open input file %s\n", infile);
goto end;
}
} else
in = BIO_new_fp(stdin, BIO_NOCLOSE);
if (operation & SMIME_IP) {
if (informat == FORMAT_SMIME)
cms = SMIME_read_CMS(in, &indata);
else if (informat == FORMAT_PEM)
cms = PEM_read_bio_CMS(in, NULL, NULL, NULL);
else if (informat == FORMAT_ASN1)
cms = d2i_CMS_bio(in, NULL);
else {
BIO_printf(bio_err, "Bad input format for CMS file\n");
goto end;
}
if (!cms) {
BIO_printf(bio_err, "Error reading S/MIME message\n");
goto end;
}
if (contfile) {
BIO_free(indata);
if (!(indata = BIO_new_file(contfile, "rb"))) {
BIO_printf(bio_err, "Can't read content file %s\n", contfile);
goto end;
}
}
if (certsoutfile) {
STACK_OF(X509) *allcerts;
allcerts = CMS_get1_certs(cms);
if (!save_certs(certsoutfile, allcerts)) {
BIO_printf(bio_err,
"Error writing certs to %s\n", certsoutfile);
ret = 5;
goto end;
}
sk_X509_pop_free(allcerts, X509_free);
}
}
if (rctfile) {
char *rctmode = (rctformat == FORMAT_ASN1) ? "rb" : "r";
if (!(rctin = BIO_new_file(rctfile, rctmode))) {
BIO_printf(bio_err, "Can't open receipt file %s\n", rctfile);
goto end;
}
if (rctformat == FORMAT_SMIME)
rcms = SMIME_read_CMS(rctin, NULL);
else if (rctformat == FORMAT_PEM)
rcms = PEM_read_bio_CMS(rctin, NULL, NULL, NULL);
else if (rctformat == FORMAT_ASN1)
rcms = d2i_CMS_bio(rctin, NULL);
else {
BIO_printf(bio_err, "Bad input format for receipt\n");
goto end;
}
if (!rcms) {
BIO_printf(bio_err, "Error reading receipt\n");
goto end;
}
}
if (outfile) {
if (!(out = BIO_new_file(outfile, outmode))) {
BIO_printf(bio_err, "Can't open output file %s\n", outfile);
goto end;
}
} else {
out = BIO_new_fp(stdout, BIO_NOCLOSE);
# ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
# endif
}
if ((operation == SMIME_VERIFY) || (operation == SMIME_VERIFY_RECEIPT)) {
if (!(store = setup_verify(bio_err, CAfile, CApath)))
goto end;
X509_STORE_set_verify_cb(store, cms_cb);
if (vpm)
X509_STORE_set1_param(store, vpm);
}
ret = 3;
if (operation == SMIME_DATA_CREATE) {
cms = CMS_data_create(in, flags);
} else if (operation == SMIME_DIGEST_CREATE) {
cms = CMS_digest_create(in, sign_md, flags);
} else if (operation == SMIME_COMPRESS) {
cms = CMS_compress(in, -1, flags);
} else if (operation == SMIME_ENCRYPT) {
int i;
flags |= CMS_PARTIAL;
cms = CMS_encrypt(NULL, in, cipher, flags);
if (!cms)
goto end;
for (i = 0; i < sk_X509_num(encerts); i++) {
CMS_RecipientInfo *ri;
cms_key_param *kparam;
int tflags = flags;
X509 *x = sk_X509_value(encerts, i);
for (kparam = key_first; kparam; kparam = kparam->next) {
if (kparam->idx == i) {
tflags |= CMS_KEY_PARAM;
break;
}
}
ri = CMS_add1_recipient_cert(cms, x, tflags);
if (!ri)
goto end;
if (kparam) {
EVP_PKEY_CTX *pctx;
pctx = CMS_RecipientInfo_get0_pkey_ctx(ri);
if (!cms_set_pkey_param(pctx, kparam->param))
goto end;
}
if (CMS_RecipientInfo_type(ri) == CMS_RECIPINFO_AGREE
&& wrap_cipher) {
EVP_CIPHER_CTX *wctx;
wctx = CMS_RecipientInfo_kari_get0_ctx(ri);
EVP_EncryptInit_ex(wctx, wrap_cipher, NULL, NULL, NULL);
}
}
if (secret_key) {
if (!CMS_add0_recipient_key(cms, NID_undef,
secret_key, secret_keylen,
secret_keyid, secret_keyidlen,
NULL, NULL, NULL))
goto end;
secret_key = NULL;
secret_keyid = NULL;
}
if (pwri_pass) {
pwri_tmp = (unsigned char *)BUF_strdup((char *)pwri_pass);
if (!pwri_tmp)
goto end;
if (!CMS_add0_recipient_password(cms,
-1, NID_undef, NID_undef,
pwri_tmp, -1, NULL))
goto end;
pwri_tmp = NULL;
}
if (!(flags & CMS_STREAM)) {
if (!CMS_final(cms, in, NULL, flags))
goto end;
}
} else if (operation == SMIME_ENCRYPTED_ENCRYPT) {
cms = CMS_EncryptedData_encrypt(in, cipher,
secret_key, secret_keylen, flags);
} else if (operation == SMIME_SIGN_RECEIPT) {
CMS_ContentInfo *srcms = NULL;
STACK_OF(CMS_SignerInfo) *sis;
CMS_SignerInfo *si;
sis = CMS_get0_SignerInfos(cms);
if (!sis)
goto end;
si = sk_CMS_SignerInfo_value(sis, 0);
srcms = CMS_sign_receipt(si, signer, key, other, flags);
if (!srcms)
goto end;
CMS_ContentInfo_free(cms);
cms = srcms;
} else if (operation & SMIME_SIGNERS) {
int i;
if (operation == SMIME_SIGN) {
if (flags & CMS_DETACHED) {
if (outformat == FORMAT_SMIME)
flags |= CMS_STREAM;
}
flags |= CMS_PARTIAL;
cms = CMS_sign(NULL, NULL, other, in, flags);
if (!cms)
goto end;
if (econtent_type)
CMS_set1_eContentType(cms, econtent_type);
if (rr_to) {
rr = make_receipt_request(rr_to, rr_allorfirst, rr_from);
if (!rr) {
BIO_puts(bio_err,
"Signed Receipt Request Creation Error\n");
goto end;
}
}
} else
flags |= CMS_REUSE_DIGEST;
for (i = 0; i < sk_OPENSSL_STRING_num(sksigners); i++) {
CMS_SignerInfo *si;
cms_key_param *kparam;
int tflags = flags;
signerfile = sk_OPENSSL_STRING_value(sksigners, i);
keyfile = sk_OPENSSL_STRING_value(skkeys, i);
signer = load_cert(bio_err, signerfile, FORMAT_PEM, NULL,
e, "signer certificate");
if (!signer)
goto end;
key = load_key(bio_err, keyfile, keyform, 0, passin, e,
"signing key file");
if (!key)
goto end;
for (kparam = key_first; kparam; kparam = kparam->next) {
if (kparam->idx == i) {
tflags |= CMS_KEY_PARAM;
break;
}
}
si = CMS_add1_signer(cms, signer, key, sign_md, tflags);
if (!si)
goto end;
if (kparam) {
EVP_PKEY_CTX *pctx;
pctx = CMS_SignerInfo_get0_pkey_ctx(si);
if (!cms_set_pkey_param(pctx, kparam->param))
goto end;
}
if (rr && !CMS_add1_ReceiptRequest(si, rr))
goto end;
X509_free(signer);
signer = NULL;
EVP_PKEY_free(key);
key = NULL;
}
if ((operation == SMIME_SIGN) && !(flags & CMS_STREAM)) {
if (!CMS_final(cms, in, NULL, flags))
goto end;
}
}
if (!cms) {
BIO_printf(bio_err, "Error creating CMS structure\n");
goto end;
}
ret = 4;
if (operation == SMIME_DECRYPT) {
if (flags & CMS_DEBUG_DECRYPT)
CMS_decrypt(cms, NULL, NULL, NULL, NULL, flags);
if (secret_key) {
if (!CMS_decrypt_set1_key(cms,
secret_key, secret_keylen,
secret_keyid, secret_keyidlen)) {
BIO_puts(bio_err, "Error decrypting CMS using secret key\n");
goto end;
}
}
if (key) {
if (!CMS_decrypt_set1_pkey(cms, key, recip)) {
BIO_puts(bio_err, "Error decrypting CMS using private key\n");
goto end;
}
}
if (pwri_pass) {
if (!CMS_decrypt_set1_password(cms, pwri_pass, -1)) {
BIO_puts(bio_err, "Error decrypting CMS using password\n");
goto end;
}
}
if (!CMS_decrypt(cms, NULL, NULL, indata, out, flags)) {
BIO_printf(bio_err, "Error decrypting CMS structure\n");
goto end;
}
} else if (operation == SMIME_DATAOUT) {
if (!CMS_data(cms, out, flags))
goto end;
} else if (operation == SMIME_UNCOMPRESS) {
if (!CMS_uncompress(cms, indata, out, flags))
goto end;
} else if (operation == SMIME_DIGEST_VERIFY) {
if (CMS_digest_verify(cms, indata, out, flags) > 0)
BIO_printf(bio_err, "Verification successful\n");
else {
BIO_printf(bio_err, "Verification failure\n");
goto end;
}
} else if (operation == SMIME_ENCRYPTED_DECRYPT) {
if (!CMS_EncryptedData_decrypt(cms, secret_key, secret_keylen,
indata, out, flags))
goto end;
} else if (operation == SMIME_VERIFY) {
if (CMS_verify(cms, other, store, indata, out, flags) > 0)
BIO_printf(bio_err, "Verification successful\n");
else {
BIO_printf(bio_err, "Verification failure\n");
if (verify_retcode)
ret = verify_err + 32;
goto end;
}
if (signerfile) {
STACK_OF(X509) *signers;
signers = CMS_get0_signers(cms);
if (!save_certs(signerfile, signers)) {
BIO_printf(bio_err,
"Error writing signers to %s\n", signerfile);
ret = 5;
goto end;
}
sk_X509_free(signers);
}
if (rr_print)
receipt_request_print(bio_err, cms);
} else if (operation == SMIME_VERIFY_RECEIPT) {
if (CMS_verify_receipt(rcms, cms, other, store, flags) > 0)
BIO_printf(bio_err, "Verification successful\n");
else {
BIO_printf(bio_err, "Verification failure\n");
goto end;
}
} else {
if (noout) {
if (print)
CMS_ContentInfo_print_ctx(out, cms, 0, NULL);
} else if (outformat == FORMAT_SMIME) {
if (to)
BIO_printf(out, "To: %s\n", to);
if (from)
BIO_printf(out, "From: %s\n", from);
if (subject)
BIO_printf(out, "Subject: %s\n", subject);
if (operation == SMIME_RESIGN)
ret = SMIME_write_CMS(out, cms, indata, flags);
else
ret = SMIME_write_CMS(out, cms, in, flags);
} else if (outformat == FORMAT_PEM)
ret = PEM_write_bio_CMS_stream(out, cms, in, flags);
else if (outformat == FORMAT_ASN1)
ret = i2d_CMS_bio_stream(out, cms, in, flags);
else {
BIO_printf(bio_err, "Bad output format for CMS file\n");
goto end;
}
if (ret <= 0) {
ret = 6;
goto end;
}
}
ret = 0;
end:
if (ret)
ERR_print_errors(bio_err);
if (need_rand)
app_RAND_write_file(NULL, bio_err);
sk_X509_pop_free(encerts, X509_free);
sk_X509_pop_free(other, X509_free);
if (vpm)
X509_VERIFY_PARAM_free(vpm);
if (sksigners)
sk_OPENSSL_STRING_free(sksigners);
if (skkeys)
sk_OPENSSL_STRING_free(skkeys);
if (secret_key)
OPENSSL_free(secret_key);
if (secret_keyid)
OPENSSL_free(secret_keyid);
if (pwri_tmp)
OPENSSL_free(pwri_tmp);
if (econtent_type)
ASN1_OBJECT_free(econtent_type);
if (rr)
CMS_ReceiptRequest_free(rr);
if (rr_to)
sk_OPENSSL_STRING_free(rr_to);
if (rr_from)
sk_OPENSSL_STRING_free(rr_from);
for (key_param = key_first; key_param;) {
cms_key_param *tparam;
sk_OPENSSL_STRING_free(key_param->param);
tparam = key_param->next;
OPENSSL_free(key_param);
key_param = tparam;
}
X509_STORE_free(store);
X509_free(cert);
X509_free(recip);
X509_free(signer);
EVP_PKEY_free(key);
CMS_ContentInfo_free(cms);
CMS_ContentInfo_free(rcms);
BIO_free(rctin);
BIO_free(in);
BIO_free(indata);
BIO_free_all(out);
if (passin)
OPENSSL_free(passin);
return (ret);
}
static int cms_cb(int ok, X509_STORE_CTX *ctx)
{
int error;
error = X509_STORE_CTX_get_error(ctx);
verify_err = error;
if ((error != X509_V_ERR_NO_EXPLICIT_POLICY)
&& ((error != X509_V_OK) || (ok != 2)))
return ok;
policies_print(NULL, ctx);
return ok;
}
static void receipt_request_print(BIO *out, CMS_ContentInfo *cms)
{
STACK_OF(CMS_SignerInfo) *sis;
CMS_SignerInfo *si;
CMS_ReceiptRequest *rr;
int allorfirst;
STACK_OF(GENERAL_NAMES) *rto, *rlist;
ASN1_STRING *scid;
int i, rv;
sis = CMS_get0_SignerInfos(cms);
for (i = 0; i < sk_CMS_SignerInfo_num(sis); i++) {
si = sk_CMS_SignerInfo_value(sis, i);
rv = CMS_get1_ReceiptRequest(si, &rr);
BIO_printf(bio_err, "Signer %d:\n", i + 1);
if (rv == 0)
BIO_puts(bio_err, " No Receipt Request\n");
else if (rv < 0) {
BIO_puts(bio_err, " Receipt Request Parse Error\n");
ERR_print_errors(bio_err);
} else {
char *id;
int idlen;
CMS_ReceiptRequest_get0_values(rr, &scid, &allorfirst,
&rlist, &rto);
BIO_puts(out, " Signed Content ID:\n");
idlen = ASN1_STRING_length(scid);
id = (char *)ASN1_STRING_data(scid);
BIO_dump_indent(out, id, idlen, 4);
BIO_puts(out, " Receipts From");
if (rlist) {
BIO_puts(out, " List:\n");
gnames_stack_print(out, rlist);
} else if (allorfirst == 1)
BIO_puts(out, ": First Tier\n");
else if (allorfirst == 0)
BIO_puts(out, ": All\n");
else
BIO_printf(out, " Unknown (%d)\n", allorfirst);
BIO_puts(out, " Receipts To:\n");
gnames_stack_print(out, rto);
}
if (rr)
CMS_ReceiptRequest_free(rr);
}
}
