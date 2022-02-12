int cms_main(int argc, char **argv)
{
ASN1_OBJECT *econtent_type = NULL;
BIO *in = NULL, *out = NULL, *indata = NULL, *rctin = NULL;
CMS_ContentInfo *cms = NULL, *rcms = NULL;
CMS_ReceiptRequest *rr = NULL;
ENGINE *e = NULL;
EVP_PKEY *key = NULL;
const EVP_CIPHER *cipher = NULL, *wrap_cipher = NULL;
const EVP_MD *sign_md = NULL;
STACK_OF(OPENSSL_STRING) *rr_to = NULL, *rr_from = NULL;
STACK_OF(OPENSSL_STRING) *sksigners = NULL, *skkeys = NULL;
STACK_OF(X509) *encerts = NULL, *other = NULL;
X509 *cert = NULL, *recip = NULL, *signer = NULL;
X509_STORE *store = NULL;
X509_VERIFY_PARAM *vpm = NULL;
char *certfile = NULL, *keyfile = NULL, *contfile = NULL;
const char *CAfile = NULL, *CApath = NULL;
char *certsoutfile = NULL;
int noCAfile = 0, noCApath = 0;
char *infile = NULL, *outfile = NULL, *rctfile = NULL, *inrand = NULL;
char *passinarg = NULL, *passin = NULL, *signerfile = NULL, *recipfile =
NULL;
char *to = NULL, *from = NULL, *subject = NULL, *prog;
cms_key_param *key_first = NULL, *key_param = NULL;
int flags = CMS_DETACHED, noout = 0, print = 0, keyidx = -1, vpmtouched =
0;
int informat = FORMAT_SMIME, outformat = FORMAT_SMIME;
int need_rand = 0, operation = 0, ret = 1, rr_print = 0, rr_allorfirst =
-1;
int verify_retcode = 0, rctformat = FORMAT_SMIME, keyform = FORMAT_PEM;
size_t secret_keylen = 0, secret_keyidlen = 0;
unsigned char *pwri_pass = NULL, *pwri_tmp = NULL;
unsigned char *secret_key = NULL, *secret_keyid = NULL;
long ltmp;
const char *mime_eol = "\n";
OPTION_CHOICE o;
if ((vpm = X509_VERIFY_PARAM_new()) == NULL)
return 1;
prog = opt_init(argc, argv, cms_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(cms_options);
ret = 0;
goto end;
case OPT_INFORM:
if (!opt_format(opt_arg(), OPT_FMT_PDS, &informat))
goto opthelp;
break;
case OPT_OUTFORM:
if (!opt_format(opt_arg(), OPT_FMT_PDS, &outformat))
goto opthelp;
break;
case OPT_OUT:
outfile = opt_arg();
break;
case OPT_ENCRYPT:
operation = SMIME_ENCRYPT;
break;
case OPT_DECRYPT:
operation = SMIME_DECRYPT;
break;
case OPT_SIGN:
operation = SMIME_SIGN;
break;
case OPT_SIGN_RECEIPT:
operation = SMIME_SIGN_RECEIPT;
break;
case OPT_RESIGN:
operation = SMIME_RESIGN;
break;
case OPT_VERIFY:
operation = SMIME_VERIFY;
break;
case OPT_VERIFY_RETCODE:
verify_retcode = 1;
break;
case OPT_VERIFY_RECEIPT:
operation = SMIME_VERIFY_RECEIPT;
rctfile = opt_arg();
break;
case OPT_CMSOUT:
operation = SMIME_CMSOUT;
break;
case OPT_DATA_OUT:
operation = SMIME_DATAOUT;
break;
case OPT_DATA_CREATE:
operation = SMIME_DATA_CREATE;
break;
case OPT_DIGEST_VERIFY:
operation = SMIME_DIGEST_VERIFY;
break;
case OPT_DIGEST_CREATE:
operation = SMIME_DIGEST_CREATE;
break;
case OPT_COMPRESS:
operation = SMIME_COMPRESS;
break;
case OPT_UNCOMPRESS:
operation = SMIME_UNCOMPRESS;
break;
case OPT_ED_DECRYPT:
operation = SMIME_ENCRYPTED_DECRYPT;
break;
case OPT_ED_ENCRYPT:
operation = SMIME_ENCRYPTED_ENCRYPT;
break;
case OPT_DEBUG_DECRYPT:
flags |= CMS_DEBUG_DECRYPT;
break;
case OPT_TEXT:
flags |= CMS_TEXT;
break;
case OPT_ASCIICRLF:
flags |= CMS_ASCIICRLF;
break;
case OPT_NOINTERN:
flags |= CMS_NOINTERN;
break;
case OPT_NOVERIFY:
flags |= CMS_NO_SIGNER_CERT_VERIFY;
break;
case OPT_NOCERTS:
flags |= CMS_NOCERTS;
break;
case OPT_NOATTR:
flags |= CMS_NOATTR;
break;
case OPT_NODETACH:
flags &= ~CMS_DETACHED;
break;
case OPT_NOSMIMECAP:
flags |= CMS_NOSMIMECAP;
break;
case OPT_BINARY:
flags |= CMS_BINARY;
break;
case OPT_KEYID:
flags |= CMS_USE_KEYID;
break;
case OPT_NOSIGS:
flags |= CMS_NOSIGS;
break;
case OPT_NO_CONTENT_VERIFY:
flags |= CMS_NO_CONTENT_VERIFY;
break;
case OPT_NO_ATTR_VERIFY:
flags |= CMS_NO_ATTR_VERIFY;
break;
case OPT_INDEF:
flags |= CMS_STREAM;
break;
case OPT_NOINDEF:
flags &= ~CMS_STREAM;
break;
case OPT_NOOLDMIME:
flags |= CMS_NOOLDMIMETYPE;
break;
case OPT_CRLFEOL:
mime_eol = "\r\n";
flags |= CMS_CRLFEOL;
break;
case OPT_NOOUT:
noout = 1;
break;
case OPT_RR_PRINT:
rr_print = 1;
break;
case OPT_RR_ALL:
rr_allorfirst = 0;
break;
case OPT_RR_FIRST:
rr_allorfirst = 1;
break;
case OPT_RCTFORM:
if (rctformat == FORMAT_SMIME)
rcms = SMIME_read_CMS(rctin, NULL);
else if (rctformat == FORMAT_PEM)
rcms = PEM_read_bio_CMS(rctin, NULL, NULL, NULL);
else if (rctformat == FORMAT_ASN1)
if (!opt_format(opt_arg(),
OPT_FMT_PEMDER | OPT_FMT_SMIME, &rctformat))
goto opthelp;
break;
case OPT_CERTFILE:
certfile = opt_arg();
break;
case OPT_CAFILE:
CAfile = opt_arg();
break;
case OPT_CAPATH:
CApath = opt_arg();
break;
case OPT_NOCAFILE:
noCAfile = 1;
break;
case OPT_NOCAPATH:
noCApath = 1;
break;
case OPT_IN:
infile = opt_arg();
break;
case OPT_CONTENT:
contfile = opt_arg();
break;
case OPT_RR_FROM:
if (rr_from == NULL
&& (rr_from = sk_OPENSSL_STRING_new_null()) == NULL)
goto end;
sk_OPENSSL_STRING_push(rr_from, opt_arg());
break;
case OPT_RR_TO:
if (rr_to == NULL
&& (rr_to = sk_OPENSSL_STRING_new_null()) == NULL)
goto end;
sk_OPENSSL_STRING_push(rr_to, opt_arg());
break;
case OPT_PRINT:
noout = print = 1;
break;
case OPT_SECRETKEY:
if (secret_key != NULL) {
BIO_printf(bio_err, "Invalid key (supplied twice) %s\n",
opt_arg());
goto opthelp;
}
secret_key = OPENSSL_hexstr2buf(opt_arg(), &ltmp);
if (secret_key == NULL) {
BIO_printf(bio_err, "Invalid key %s\n", opt_arg());
goto end;
}
secret_keylen = (size_t)ltmp;
break;
case OPT_SECRETKEYID:
if (secret_keyid != NULL) {
BIO_printf(bio_err, "Invalid id (supplied twice) %s\n",
opt_arg());
goto opthelp;
}
secret_keyid = OPENSSL_hexstr2buf(opt_arg(), &ltmp);
if (secret_keyid == NULL) {
BIO_printf(bio_err, "Invalid id %s\n", opt_arg());
goto opthelp;
}
secret_keyidlen = (size_t)ltmp;
break;
case OPT_PWRI_PASSWORD:
pwri_pass = (unsigned char *)opt_arg();
break;
case OPT_ECONTENT_TYPE:
if (econtent_type != NULL) {
BIO_printf(bio_err, "Invalid OID (supplied twice) %s\n",
opt_arg());
goto opthelp;
}
econtent_type = OBJ_txt2obj(opt_arg(), 0);
if (econtent_type == NULL) {
BIO_printf(bio_err, "Invalid OID %s\n", opt_arg());
goto opthelp;
}
break;
case OPT_RAND:
inrand = opt_arg();
need_rand = 1;
break;
case OPT_ENGINE:
e = setup_engine(opt_arg(), 0);
break;
case OPT_PASSIN:
passinarg = opt_arg();
break;
case OPT_TO:
to = opt_arg();
break;
case OPT_FROM:
from = opt_arg();
break;
case OPT_SUBJECT:
subject = opt_arg();
break;
case OPT_CERTSOUT:
certsoutfile = opt_arg();
break;
case OPT_MD:
if (!opt_md(opt_arg(), &sign_md))
goto end;
break;
case OPT_SIGNER:
if (signerfile) {
if (sksigners == NULL
&& (sksigners = sk_OPENSSL_STRING_new_null()) == NULL)
goto end;
sk_OPENSSL_STRING_push(sksigners, signerfile);
if (keyfile == NULL)
keyfile = signerfile;
if (skkeys == NULL
&& (skkeys = sk_OPENSSL_STRING_new_null()) == NULL)
goto end;
sk_OPENSSL_STRING_push(skkeys, keyfile);
keyfile = NULL;
}
signerfile = opt_arg();
break;
case OPT_INKEY:
if (keyfile) {
if (signerfile == NULL) {
BIO_puts(bio_err, "Illegal -inkey without -signer\n");
goto end;
}
if (sksigners == NULL
&& (sksigners = sk_OPENSSL_STRING_new_null()) == NULL)
goto end;
sk_OPENSSL_STRING_push(sksigners, signerfile);
signerfile = NULL;
if (skkeys == NULL
&& (skkeys = sk_OPENSSL_STRING_new_null()) == NULL)
goto end;
sk_OPENSSL_STRING_push(skkeys, keyfile);
}
keyfile = opt_arg();
break;
case OPT_KEYFORM:
if (!opt_format(opt_arg(), OPT_FMT_ANY, &keyform))
goto opthelp;
break;
case OPT_RECIP:
if (operation == SMIME_ENCRYPT) {
if (encerts == NULL && (encerts = sk_X509_new_null()) == NULL)
goto end;
cert = load_cert(opt_arg(), FORMAT_PEM,
"recipient certificate file");
if (cert == NULL)
goto end;
sk_X509_push(encerts, cert);
cert = NULL;
} else
recipfile = opt_arg();
break;
case OPT_CIPHER:
if (!opt_cipher(opt_unknown(), &cipher))
goto end;
break;
case OPT_KEYOPT:
keyidx = -1;
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
goto opthelp;
}
if (key_param == NULL || key_param->idx != keyidx) {
cms_key_param *nparam;
nparam = app_malloc(sizeof(*nparam), "key param buffer");
nparam->idx = keyidx;
if ((nparam->param = sk_OPENSSL_STRING_new_null()) == NULL)
goto end;
nparam->next = NULL;
if (key_first == NULL)
key_first = nparam;
else
key_param->next = nparam;
key_param = nparam;
}
sk_OPENSSL_STRING_push(key_param->param, opt_arg());
break;
case OPT_V_CASES:
if (!opt_verify(o, vpm))
goto end;
vpmtouched++;
break;
case OPT_3DES_WRAP:
# ifndef OPENSSL_NO_DES
wrap_cipher = EVP_des_ede3_wrap();
# endif
break;
case OPT_AES128_WRAP:
wrap_cipher = EVP_aes_128_wrap();
break;
case OPT_AES192_WRAP:
wrap_cipher = EVP_aes_192_wrap();
break;
case OPT_AES256_WRAP:
wrap_cipher = EVP_aes_256_wrap();
break;
}
}
argc = opt_num_rest();
argv = opt_rest();
if (((rr_allorfirst != -1) || rr_from) && !rr_to) {
BIO_puts(bio_err, "No Signed Receipts Recipients\n");
goto opthelp;
}
if (!(operation & SMIME_SIGNERS) && (rr_to || rr_from)) {
BIO_puts(bio_err, "Signed receipts only allowed with -sign\n");
goto opthelp;
}
if (!(operation & SMIME_SIGNERS) && (skkeys || sksigners)) {
BIO_puts(bio_err, "Multiple signers or keys not allowed\n");
goto opthelp;
}
if (operation & SMIME_SIGNERS) {
if (keyfile && !signerfile) {
BIO_puts(bio_err, "Illegal -inkey without -signer\n");
goto opthelp;
}
if (signerfile) {
if (!sksigners
&& (sksigners = sk_OPENSSL_STRING_new_null()) == NULL)
goto end;
sk_OPENSSL_STRING_push(sksigners, signerfile);
if (!skkeys && (skkeys = sk_OPENSSL_STRING_new_null()) == NULL)
goto end;
if (!keyfile)
keyfile = signerfile;
sk_OPENSSL_STRING_push(skkeys, keyfile);
}
if (!sksigners) {
BIO_printf(bio_err, "No signer certificate specified\n");
goto opthelp;
}
signerfile = NULL;
keyfile = NULL;
need_rand = 1;
}
else if (operation == SMIME_DECRYPT) {
if (!recipfile && !keyfile && !secret_key && !pwri_pass) {
BIO_printf(bio_err,
"No recipient certificate or key specified\n");
goto opthelp;
}
} else if (operation == SMIME_ENCRYPT) {
if (*argv == NULL && !secret_key && !pwri_pass && !encerts) {
BIO_printf(bio_err, "No recipient(s) certificate(s) specified\n");
goto opthelp;
}
need_rand = 1;
} else if (!operation)
goto opthelp;
if (!app_passwd(passinarg, NULL, &passin, NULL)) {
BIO_printf(bio_err, "Error getting password\n");
goto end;
}
if (need_rand) {
app_RAND_load_file(NULL, (inrand != NULL));
if (inrand != NULL)
BIO_printf(bio_err, "%ld semi-random bytes loaded\n",
app_RAND_load_files(inrand));
}
ret = 2;
if (!(operation & SMIME_SIGNERS))
flags &= ~CMS_DETACHED;
if (!(operation & SMIME_OP)) {
if (flags & CMS_BINARY)
outformat = FORMAT_BINARY;
}
if (!(operation & SMIME_IP)) {
if (flags & CMS_BINARY)
informat = FORMAT_BINARY;
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
if (*argv && !encerts)
if ((encerts = sk_X509_new_null()) == NULL)
goto end;
while (*argv) {
if ((cert = load_cert(*argv, FORMAT_PEM,
"recipient certificate file")) == NULL)
goto end;
sk_X509_push(encerts, cert);
cert = NULL;
argv++;
}
}
if (certfile) {
if (!load_certs(certfile, &other, FORMAT_PEM, NULL,
"certificate file")) {
ERR_print_errors(bio_err);
goto end;
}
}
if (recipfile && (operation == SMIME_DECRYPT)) {
if ((recip = load_cert(recipfile, FORMAT_PEM,
"recipient certificate file")) == NULL) {
ERR_print_errors(bio_err);
goto end;
}
}
if (operation == SMIME_SIGN_RECEIPT) {
if ((signer = load_cert(signerfile, FORMAT_PEM,
"receipt signer certificate file")) == NULL) {
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
key = load_key(keyfile, keyform, 0, passin, e, "signing key file");
if (!key)
goto end;
}
in = bio_open_default(infile, 'r', informat);
if (in == NULL)
goto end;
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
if ((indata = BIO_new_file(contfile, "rb")) == NULL) {
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
if ((rctin = BIO_new_file(rctfile, rctmode)) == NULL) {
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
out = bio_open_default(outfile, 'w', outformat);
if (out == NULL)
goto end;
if ((operation == SMIME_VERIFY) || (operation == SMIME_VERIFY_RECEIPT)) {
if ((store = setup_verify(CAfile, CApath, noCAfile, noCApath)) == NULL)
goto end;
X509_STORE_set_verify_cb(store, cms_cb);
if (vpmtouched)
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
pwri_tmp = (unsigned char *)OPENSSL_strdup((char *)pwri_pass);
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
signer = load_cert(signerfile, FORMAT_PEM, "signer certificate");
if (!signer)
goto end;
key = load_key(keyfile, keyform, 0, passin, e, "signing key file");
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
receipt_request_print(cms);
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
BIO_printf(out, "To: %s%s", to, mime_eol);
if (from)
BIO_printf(out, "From: %s%s", from, mime_eol);
if (subject)
BIO_printf(out, "Subject: %s%s", subject, mime_eol);
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
app_RAND_write_file(NULL);
sk_X509_pop_free(encerts, X509_free);
sk_X509_pop_free(other, X509_free);
X509_VERIFY_PARAM_free(vpm);
sk_OPENSSL_STRING_free(sksigners);
sk_OPENSSL_STRING_free(skkeys);
OPENSSL_free(secret_key);
OPENSSL_free(secret_keyid);
OPENSSL_free(pwri_tmp);
ASN1_OBJECT_free(econtent_type);
CMS_ReceiptRequest_free(rr);
sk_OPENSSL_STRING_free(rr_to);
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
policies_print(ctx);
return ok;
}
static void receipt_request_print(CMS_ContentInfo *cms)
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
const char *id;
int idlen;
CMS_ReceiptRequest_get0_values(rr, &scid, &allorfirst,
&rlist, &rto);
BIO_puts(bio_err, " Signed Content ID:\n");
idlen = ASN1_STRING_length(scid);
id = (const char *)ASN1_STRING_get0_data(scid);
BIO_dump_indent(bio_err, id, idlen, 4);
BIO_puts(bio_err, " Receipts From");
if (rlist) {
BIO_puts(bio_err, " List:\n");
gnames_stack_print(rlist);
} else if (allorfirst == 1)
BIO_puts(bio_err, ": First Tier\n");
else if (allorfirst == 0)
BIO_puts(bio_err, ": All\n");
else
BIO_printf(bio_err, " Unknown (%d)\n", allorfirst);
BIO_puts(bio_err, " Receipts To:\n");
gnames_stack_print(rto);
}
CMS_ReceiptRequest_free(rr);
}
}
