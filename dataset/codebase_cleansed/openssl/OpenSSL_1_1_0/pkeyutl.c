int pkeyutl_main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL;
ENGINE *e = NULL;
EVP_PKEY_CTX *ctx = NULL;
char *infile = NULL, *outfile = NULL, *sigfile = NULL, *passinarg = NULL;
char hexdump = 0, asn1parse = 0, rev = 0, *prog;
unsigned char *buf_in = NULL, *buf_out = NULL, *sig = NULL;
OPTION_CHOICE o;
int buf_inlen = 0, siglen = -1, keyform = FORMAT_PEM, peerform =
FORMAT_PEM;
int keysize = -1, pkey_op = EVP_PKEY_OP_SIGN, key_type = KEY_PRIVKEY;
int engine_impl = 0;
int ret = 1, rv = -1;
size_t buf_outlen;
const char *inkey = NULL;
const char *peerkey = NULL;
const char *kdfalg = NULL;
int kdflen = 0;
STACK_OF(OPENSSL_STRING) *pkeyopts = NULL;
prog = opt_init(argc, argv, pkeyutl_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(pkeyutl_options);
ret = 0;
goto end;
case OPT_IN:
infile = opt_arg();
break;
case OPT_OUT:
outfile = opt_arg();
break;
case OPT_SIGFILE:
sigfile = opt_arg();
break;
case OPT_ENGINE_IMPL:
engine_impl = 1;
break;
case OPT_INKEY:
inkey = opt_arg();
break;
case OPT_PEERKEY:
peerkey = opt_arg();
break;
case OPT_PASSIN:
passinarg = opt_arg();
break;
case OPT_PEERFORM:
if (!opt_format(opt_arg(), OPT_FMT_PDE, &peerform))
goto opthelp;
break;
case OPT_KEYFORM:
if (!opt_format(opt_arg(), OPT_FMT_PDE, &keyform))
goto opthelp;
break;
case OPT_ENGINE:
e = setup_engine(opt_arg(), 0);
break;
case OPT_PUBIN:
key_type = KEY_PUBKEY;
break;
case OPT_CERTIN:
key_type = KEY_CERT;
break;
case OPT_ASN1PARSE:
asn1parse = 1;
break;
case OPT_HEXDUMP:
hexdump = 1;
break;
case OPT_SIGN:
pkey_op = EVP_PKEY_OP_SIGN;
break;
case OPT_VERIFY:
pkey_op = EVP_PKEY_OP_VERIFY;
break;
case OPT_VERIFYRECOVER:
pkey_op = EVP_PKEY_OP_VERIFYRECOVER;
break;
case OPT_ENCRYPT:
pkey_op = EVP_PKEY_OP_ENCRYPT;
break;
case OPT_DECRYPT:
pkey_op = EVP_PKEY_OP_DECRYPT;
break;
case OPT_DERIVE:
pkey_op = EVP_PKEY_OP_DERIVE;
break;
case OPT_KDF:
pkey_op = EVP_PKEY_OP_DERIVE;
key_type = KEY_NONE;
kdfalg = opt_arg();
break;
case OPT_KDFLEN:
kdflen = atoi(opt_arg());
break;
case OPT_REV:
rev = 1;
break;
case OPT_PKEYOPT:
if ((pkeyopts == NULL &&
(pkeyopts = sk_OPENSSL_STRING_new_null()) == NULL) ||
sk_OPENSSL_STRING_push(pkeyopts, opt_arg()) == 0) {
BIO_puts(bio_err, "out of memory\n");
goto end;
}
break;
}
}
argc = opt_num_rest();
if (argc != 0)
goto opthelp;
if (kdfalg != NULL) {
if (kdflen == 0)
goto opthelp;
} else if ((inkey == NULL)
|| (peerkey != NULL && pkey_op != EVP_PKEY_OP_DERIVE)) {
goto opthelp;
}
ctx = init_ctx(kdfalg, &keysize, inkey, keyform, key_type,
passinarg, pkey_op, e, engine_impl);
if (ctx == NULL) {
BIO_printf(bio_err, "%s: Error initializing context\n", prog);
ERR_print_errors(bio_err);
goto end;
}
if (peerkey != NULL && !setup_peer(ctx, peerform, peerkey, e)) {
BIO_printf(bio_err, "%s: Error setting up peer key\n", prog);
ERR_print_errors(bio_err);
goto end;
}
if (pkeyopts != NULL) {
int num = sk_OPENSSL_STRING_num(pkeyopts);
int i;
for (i = 0; i < num; ++i) {
const char *opt = sk_OPENSSL_STRING_value(pkeyopts, i);
if (pkey_ctrl_string(ctx, opt) <= 0) {
BIO_printf(bio_err, "%s: Can't set parameter:\n", prog);
ERR_print_errors(bio_err);
goto end;
}
}
}
if (sigfile && (pkey_op != EVP_PKEY_OP_VERIFY)) {
BIO_printf(bio_err,
"%s: Signature file specified for non verify\n", prog);
goto end;
}
if (!sigfile && (pkey_op == EVP_PKEY_OP_VERIFY)) {
BIO_printf(bio_err,
"%s: No signature file specified for verify\n", prog);
goto end;
}
app_RAND_load_file(NULL, 0);
if (pkey_op != EVP_PKEY_OP_DERIVE) {
in = bio_open_default(infile, 'r', FORMAT_BINARY);
if (in == NULL)
goto end;
}
out = bio_open_default(outfile, 'w', FORMAT_BINARY);
if (out == NULL)
goto end;
if (sigfile) {
BIO *sigbio = BIO_new_file(sigfile, "rb");
if (!sigbio) {
BIO_printf(bio_err, "Can't open signature file %s\n", sigfile);
goto end;
}
siglen = bio_to_mem(&sig, keysize * 10, sigbio);
BIO_free(sigbio);
if (siglen < 0) {
BIO_printf(bio_err, "Error reading signature data\n");
goto end;
}
}
if (in) {
buf_inlen = bio_to_mem(&buf_in, keysize * 10, in);
if (buf_inlen < 0) {
BIO_printf(bio_err, "Error reading input Data\n");
exit(1);
}
if (rev) {
size_t i;
unsigned char ctmp;
size_t l = (size_t)buf_inlen;
for (i = 0; i < l / 2; i++) {
ctmp = buf_in[i];
buf_in[i] = buf_in[l - 1 - i];
buf_in[l - 1 - i] = ctmp;
}
}
}
if (pkey_op == EVP_PKEY_OP_VERIFY) {
rv = EVP_PKEY_verify(ctx, sig, (size_t)siglen,
buf_in, (size_t)buf_inlen);
if (rv == 1) {
BIO_puts(out, "Signature Verified Successfully\n");
ret = 0;
} else
BIO_puts(out, "Signature Verification Failure\n");
goto end;
}
if (kdflen != 0) {
buf_outlen = kdflen;
rv = 1;
} else {
rv = do_keyop(ctx, pkey_op, NULL, (size_t *)&buf_outlen,
buf_in, (size_t)buf_inlen);
}
if (rv > 0 && buf_outlen != 0) {
buf_out = app_malloc(buf_outlen, "buffer output");
rv = do_keyop(ctx, pkey_op,
buf_out, (size_t *)&buf_outlen,
buf_in, (size_t)buf_inlen);
}
if (rv <= 0) {
BIO_puts(bio_err, "Public Key operation error\n");
ERR_print_errors(bio_err);
goto end;
}
ret = 0;
if (asn1parse) {
if (!ASN1_parse_dump(out, buf_out, buf_outlen, 1, -1))
ERR_print_errors(bio_err);
} else if (hexdump)
BIO_dump(out, (char *)buf_out, buf_outlen);
else
BIO_write(out, buf_out, buf_outlen);
end:
EVP_PKEY_CTX_free(ctx);
BIO_free(in);
BIO_free_all(out);
OPENSSL_free(buf_in);
OPENSSL_free(buf_out);
OPENSSL_free(sig);
sk_OPENSSL_STRING_free(pkeyopts);
return ret;
}
static EVP_PKEY_CTX *init_ctx(const char *kdfalg, int *pkeysize,
const char *keyfile, int keyform, int key_type,
char *passinarg, int pkey_op, ENGINE *e,
const int engine_impl)
{
EVP_PKEY *pkey = NULL;
EVP_PKEY_CTX *ctx = NULL;
ENGINE *impl = NULL;
char *passin = NULL;
int rv = -1;
X509 *x;
if (((pkey_op == EVP_PKEY_OP_SIGN) || (pkey_op == EVP_PKEY_OP_DECRYPT)
|| (pkey_op == EVP_PKEY_OP_DERIVE))
&& (key_type != KEY_PRIVKEY && kdfalg == NULL)) {
BIO_printf(bio_err, "A private key is needed for this operation\n");
goto end;
}
if (!app_passwd(passinarg, NULL, &passin, NULL)) {
BIO_printf(bio_err, "Error getting password\n");
goto end;
}
switch (key_type) {
case KEY_PRIVKEY:
pkey = load_key(keyfile, keyform, 0, passin, e, "Private Key");
break;
case KEY_PUBKEY:
pkey = load_pubkey(keyfile, keyform, 0, NULL, e, "Public Key");
break;
case KEY_CERT:
x = load_cert(keyfile, keyform, "Certificate");
if (x) {
pkey = X509_get_pubkey(x);
X509_free(x);
}
break;
case KEY_NONE:
break;
}
#ifndef OPENSSL_NO_ENGINE
if (engine_impl)
impl = e;
#endif
if (kdfalg) {
int kdfnid = OBJ_sn2nid(kdfalg);
if (kdfnid == NID_undef)
goto end;
ctx = EVP_PKEY_CTX_new_id(kdfnid, impl);
} else {
if (pkey == NULL)
goto end;
*pkeysize = EVP_PKEY_size(pkey);
ctx = EVP_PKEY_CTX_new(pkey, impl);
EVP_PKEY_free(pkey);
}
if (ctx == NULL)
goto end;
switch (pkey_op) {
case EVP_PKEY_OP_SIGN:
rv = EVP_PKEY_sign_init(ctx);
break;
case EVP_PKEY_OP_VERIFY:
rv = EVP_PKEY_verify_init(ctx);
break;
case EVP_PKEY_OP_VERIFYRECOVER:
rv = EVP_PKEY_verify_recover_init(ctx);
break;
case EVP_PKEY_OP_ENCRYPT:
rv = EVP_PKEY_encrypt_init(ctx);
break;
case EVP_PKEY_OP_DECRYPT:
rv = EVP_PKEY_decrypt_init(ctx);
break;
case EVP_PKEY_OP_DERIVE:
rv = EVP_PKEY_derive_init(ctx);
break;
}
if (rv <= 0) {
EVP_PKEY_CTX_free(ctx);
ctx = NULL;
}
end:
OPENSSL_free(passin);
return ctx;
}
static int setup_peer(EVP_PKEY_CTX *ctx, int peerform, const char *file,
ENGINE* e)
{
EVP_PKEY *peer = NULL;
ENGINE* engine = NULL;
int ret;
if (peerform == FORMAT_ENGINE)
engine = e;
peer = load_pubkey(file, peerform, 0, NULL, engine, "Peer Key");
if (!peer) {
BIO_printf(bio_err, "Error reading peer key %s\n", file);
ERR_print_errors(bio_err);
return 0;
}
ret = EVP_PKEY_derive_set_peer(ctx, peer);
EVP_PKEY_free(peer);
if (ret <= 0)
ERR_print_errors(bio_err);
return ret;
}
static int do_keyop(EVP_PKEY_CTX *ctx, int pkey_op,
unsigned char *out, size_t *poutlen,
const unsigned char *in, size_t inlen)
{
int rv = 0;
switch (pkey_op) {
case EVP_PKEY_OP_VERIFYRECOVER:
rv = EVP_PKEY_verify_recover(ctx, out, poutlen, in, inlen);
break;
case EVP_PKEY_OP_SIGN:
rv = EVP_PKEY_sign(ctx, out, poutlen, in, inlen);
break;
case EVP_PKEY_OP_ENCRYPT:
rv = EVP_PKEY_encrypt(ctx, out, poutlen, in, inlen);
break;
case EVP_PKEY_OP_DECRYPT:
rv = EVP_PKEY_decrypt(ctx, out, poutlen, in, inlen);
break;
case EVP_PKEY_OP_DERIVE:
rv = EVP_PKEY_derive(ctx, out, poutlen);
break;
}
return rv;
}
