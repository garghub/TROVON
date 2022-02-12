int MAIN(int argc, char **argv)
{
char *infile=NULL, *outfile=NULL, *keyname = NULL;
char *certfile=NULL;
BIO *in=NULL, *out = NULL, *inkey = NULL, *certsin = NULL;
char **args;
char *name = NULL;
PKCS12 *p12 = NULL;
char pass[50], macpass[50];
int export_cert = 0;
int options = 0;
int chain = 0;
int badarg = 0;
int iter = PKCS12_DEFAULT_ITER;
int maciter = PKCS12_DEFAULT_ITER;
int twopass = 0;
int keytype = 0;
int cert_pbe = NID_pbe_WithSHA1And40BitRC2_CBC;
int key_pbe = NID_pbe_WithSHA1And3_Key_TripleDES_CBC;
int ret = 1;
int macver = 1;
int noprompt = 0;
STACK *canames = NULL;
char *cpass = NULL, *mpass = NULL;
char *passargin = NULL, *passargout = NULL, *passarg = NULL;
char *passin = NULL, *passout = NULL;
char *inrand = NULL;
apps_startup();
enc = EVP_des_ede3_cbc();
if (bio_err == NULL ) bio_err = BIO_new_fp (stderr, BIO_NOCLOSE);
args = argv + 1;
while (*args) {
if (*args[0] == '-') {
if (!strcmp (*args, "-nokeys")) options |= NOKEYS;
else if (!strcmp (*args, "-keyex")) keytype = KEY_EX;
else if (!strcmp (*args, "-keysig")) keytype = KEY_SIG;
else if (!strcmp (*args, "-nocerts")) options |= NOCERTS;
else if (!strcmp (*args, "-clcerts")) options |= CLCERTS;
else if (!strcmp (*args, "-cacerts")) options |= CACERTS;
else if (!strcmp (*args, "-noout")) options |= (NOKEYS|NOCERTS);
else if (!strcmp (*args, "-info")) options |= INFO;
else if (!strcmp (*args, "-chain")) chain = 1;
else if (!strcmp (*args, "-twopass")) twopass = 1;
else if (!strcmp (*args, "-nomacver")) macver = 0;
else if (!strcmp (*args, "-descert"))
cert_pbe = NID_pbe_WithSHA1And3_Key_TripleDES_CBC;
else if (!strcmp (*args, "-export")) export_cert = 1;
else if (!strcmp (*args, "-des")) enc=EVP_des_cbc();
#ifndef NO_IDEA
else if (!strcmp (*args, "-idea")) enc=EVP_idea_cbc();
#endif
else if (!strcmp (*args, "-des3")) enc = EVP_des_ede3_cbc();
else if (!strcmp (*args, "-noiter")) iter = 1;
else if (!strcmp (*args, "-maciter"))
maciter = PKCS12_DEFAULT_ITER;
else if (!strcmp (*args, "-nomaciter"))
maciter = 1;
else if (!strcmp (*args, "-nodes")) enc=NULL;
else if (!strcmp (*args, "-certpbe")) {
if (args[1]) {
args++;
cert_pbe=OBJ_txt2nid(*args);
if(cert_pbe == NID_undef) {
BIO_printf(bio_err,
"Unknown PBE algorithm %s\n", *args);
badarg = 1;
}
} else badarg = 1;
} else if (!strcmp (*args, "-keypbe")) {
if (args[1]) {
args++;
key_pbe=OBJ_txt2nid(*args);
if(key_pbe == NID_undef) {
BIO_printf(bio_err,
"Unknown PBE algorithm %s\n", *args);
badarg = 1;
}
} else badarg = 1;
} else if (!strcmp (*args, "-rand")) {
if (args[1]) {
args++;
inrand = *args;
} else badarg = 1;
} else if (!strcmp (*args, "-inkey")) {
if (args[1]) {
args++;
keyname = *args;
} else badarg = 1;
} else if (!strcmp (*args, "-certfile")) {
if (args[1]) {
args++;
certfile = *args;
} else badarg = 1;
} else if (!strcmp (*args, "-name")) {
if (args[1]) {
args++;
name = *args;
} else badarg = 1;
} else if (!strcmp (*args, "-caname")) {
if (args[1]) {
args++;
if (!canames) canames = sk_new(NULL);
sk_push(canames, *args);
} else badarg = 1;
} else if (!strcmp (*args, "-in")) {
if (args[1]) {
args++;
infile = *args;
} else badarg = 1;
} else if (!strcmp (*args, "-out")) {
if (args[1]) {
args++;
outfile = *args;
} else badarg = 1;
} else if (!strcmp(*args,"-passin")) {
if (args[1]) {
args++;
passargin = *args;
} else badarg = 1;
} else if (!strcmp(*args,"-passout")) {
if (args[1]) {
args++;
passargout = *args;
} else badarg = 1;
} else if (!strcmp (*args, "-password")) {
if (args[1]) {
args++;
passarg = *args;
noprompt = 1;
} else badarg = 1;
} else badarg = 1;
} else badarg = 1;
args++;
}
if (badarg) {
BIO_printf (bio_err, "Usage: pkcs12 [options]\n");
BIO_printf (bio_err, "where options are\n");
BIO_printf (bio_err, "-export output PKCS12 file\n");
BIO_printf (bio_err, "-chain add certificate chain\n");
BIO_printf (bio_err, "-inkey file private key if not infile\n");
BIO_printf (bio_err, "-certfile f add all certs in f\n");
BIO_printf (bio_err, "-name \"name\" use name as friendly name\n");
BIO_printf (bio_err, "-caname \"nm\" use nm as CA friendly name (can be used more than once).\n");
BIO_printf (bio_err, "-in infile input filename\n");
BIO_printf (bio_err, "-out outfile output filename\n");
BIO_printf (bio_err, "-noout don't output anything, just verify.\n");
BIO_printf (bio_err, "-nomacver don't verify MAC.\n");
BIO_printf (bio_err, "-nocerts don't output certificates.\n");
BIO_printf (bio_err, "-clcerts only output client certificates.\n");
BIO_printf (bio_err, "-cacerts only output CA certificates.\n");
BIO_printf (bio_err, "-nokeys don't output private keys.\n");
BIO_printf (bio_err, "-info give info about PKCS#12 structure.\n");
BIO_printf (bio_err, "-des encrypt private keys with DES\n");
BIO_printf (bio_err, "-des3 encrypt private keys with triple DES (default)\n");
#ifndef NO_IDEA
BIO_printf (bio_err, "-idea encrypt private keys with idea\n");
#endif
BIO_printf (bio_err, "-nodes don't encrypt private keys\n");
BIO_printf (bio_err, "-noiter don't use encryption iteration\n");
BIO_printf (bio_err, "-maciter use MAC iteration\n");
BIO_printf (bio_err, "-twopass separate MAC, encryption passwords\n");
BIO_printf (bio_err, "-descert encrypt PKCS#12 certificates with triple DES (default RC2-40)\n");
BIO_printf (bio_err, "-certpbe alg specify certificate PBE algorithm (default RC2-40)\n");
BIO_printf (bio_err, "-keypbe alg specify private key PBE algorithm (default 3DES)\n");
BIO_printf (bio_err, "-keyex set MS key exchange type\n");
BIO_printf (bio_err, "-keysig set MS key signature type\n");
BIO_printf (bio_err, "-password p set import/export password source\n");
BIO_printf (bio_err, "-passin p input file pass phrase source\n");
BIO_printf (bio_err, "-passout p output file pass phrase source\n");
BIO_printf(bio_err, "-rand file:file:...\n");
BIO_printf(bio_err, " load the file (or the files in the directory) into\n");
BIO_printf(bio_err, " the random number generator\n");
goto end;
}
if(passarg) {
if(export_cert) passargout = passarg;
else passargin = passarg;
}
if(!app_passwd(bio_err, passargin, passargout, &passin, &passout)) {
BIO_printf(bio_err, "Error getting passwords\n");
goto end;
}
if(!cpass) {
if(export_cert) cpass = passout;
else cpass = passin;
}
if(cpass) {
mpass = cpass;
noprompt = 1;
} else {
cpass = pass;
mpass = macpass;
}
if(export_cert || inrand) {
app_RAND_load_file(NULL, bio_err, (inrand != NULL));
if (inrand != NULL)
BIO_printf(bio_err,"%ld semi-random bytes loaded\n",
app_RAND_load_files(inrand));
}
ERR_load_crypto_strings();
#ifdef CRYPTO_MDEBUG
CRYPTO_push_info("read files");
#endif
if (!infile) in = BIO_new_fp(stdin, BIO_NOCLOSE);
else in = BIO_new_file(infile, "rb");
if (!in) {
BIO_printf(bio_err, "Error opening input file %s\n",
infile ? infile : "<stdin>");
perror (infile);
goto end;
}
if (certfile) {
if(!(certsin = BIO_new_file(certfile, "r"))) {
BIO_printf(bio_err, "Can't open certificate file %s\n", certfile);
perror (certfile);
goto end;
}
}
if (keyname) {
if(!(inkey = BIO_new_file(keyname, "r"))) {
BIO_printf(bio_err, "Can't key certificate file %s\n", keyname);
perror (keyname);
goto end;
}
}
#ifdef CRYPTO_MDEBUG
CRYPTO_pop_info();
CRYPTO_push_info("write files");
#endif
if (!outfile) out = BIO_new_fp(stdout, BIO_NOCLOSE);
else out = BIO_new_file(outfile, "wb");
if (!out) {
BIO_printf(bio_err, "Error opening output file %s\n",
outfile ? outfile : "<stdout>");
perror (outfile);
goto end;
}
if (twopass) {
#ifdef CRYPTO_MDEBUG
CRYPTO_push_info("read MAC password");
#endif
if(EVP_read_pw_string (macpass, 50, "Enter MAC Password:", export_cert))
{
BIO_printf (bio_err, "Can't read Password\n");
goto end;
}
#ifdef CRYPTO_MDEBUG
CRYPTO_pop_info();
#endif
}
if (export_cert) {
EVP_PKEY *key;
STACK *bags, *safes;
PKCS12_SAFEBAG *bag;
PKCS8_PRIV_KEY_INFO *p8;
PKCS7 *authsafe;
X509 *ucert = NULL;
STACK_OF(X509) *certs=NULL;
char *catmp;
int i;
unsigned char keyid[EVP_MAX_MD_SIZE];
unsigned int keyidlen = 0;
#ifdef CRYPTO_MDEBUG
CRYPTO_push_info("process -export_cert");
#endif
key = PEM_read_bio_PrivateKey(inkey ? inkey : in, NULL, NULL, passin);
if (!inkey) (void) BIO_reset(in);
else BIO_free(inkey);
if (!key) {
BIO_printf (bio_err, "Error loading private key\n");
ERR_print_errors(bio_err);
goto end;
}
certs = sk_X509_new(NULL);
if(!cert_load(in, certs)) {
BIO_printf(bio_err, "Error loading certificates from input\n");
ERR_print_errors(bio_err);
goto end;
}
for(i = 0; i < sk_X509_num(certs); i++) {
ucert = sk_X509_value(certs, i);
if(X509_check_private_key(ucert, key)) {
X509_digest(ucert, EVP_sha1(), keyid, &keyidlen);
break;
}
}
if(!keyidlen) {
BIO_printf(bio_err, "No certificate matches private key\n");
goto end;
}
bags = sk_new (NULL);
if (certsin) {
if(!cert_load(certsin, certs)) {
BIO_printf(bio_err, "Error loading certificates from certfile\n");
ERR_print_errors(bio_err);
goto end;
}
BIO_free(certsin);
}
if (chain) {
int vret;
STACK_OF(X509) *chain2;
vret = get_cert_chain (ucert, &chain2);
if (vret) {
BIO_printf (bio_err, "Error %s getting chain.\n",
X509_verify_cert_error_string(vret));
goto end;
}
for (i = 1; i < sk_X509_num (chain2) ; i++)
sk_X509_push(certs, sk_X509_value (chain2, i));
sk_X509_free(chain2);
}
for(i = 0; i < sk_X509_num(certs); i++) {
X509 *cert = NULL;
cert = sk_X509_value(certs, i);
bag = M_PKCS12_x5092certbag(cert);
if(cert == ucert) {
if(name) PKCS12_add_friendlyname(bag, name, -1);
PKCS12_add_localkeyid(bag, keyid, keyidlen);
} else if((catmp = sk_shift(canames)))
PKCS12_add_friendlyname(bag, catmp, -1);
sk_push(bags, (char *)bag);
}
sk_X509_pop_free(certs, X509_free);
if (canames) sk_free(canames);
if(!noprompt &&
EVP_read_pw_string(pass, 50, "Enter Export Password:", 1)) {
BIO_printf (bio_err, "Can't read Password\n");
goto end;
}
if (!twopass) strcpy(macpass, pass);
authsafe = PKCS12_pack_p7encdata(cert_pbe, cpass, -1, NULL, 0,
iter, bags);
sk_pop_free(bags, PKCS12_SAFEBAG_free);
if (!authsafe) {
ERR_print_errors (bio_err);
goto end;
}
safes = sk_new (NULL);
sk_push (safes, (char *)authsafe);
p8 = EVP_PKEY2PKCS8 (key);
EVP_PKEY_free(key);
if(keytype) PKCS8_add_keyusage(p8, keytype);
bag = PKCS12_MAKE_SHKEYBAG(key_pbe, cpass, -1, NULL, 0, iter, p8);
PKCS8_PRIV_KEY_INFO_free(p8);
if (name) PKCS12_add_friendlyname (bag, name, -1);
PKCS12_add_localkeyid (bag, keyid, keyidlen);
bags = sk_new(NULL);
sk_push (bags, (char *)bag);
authsafe = PKCS12_pack_p7data (bags);
sk_pop_free(bags, PKCS12_SAFEBAG_free);
sk_push (safes, (char *)authsafe);
p12 = PKCS12_init (NID_pkcs7_data);
M_PKCS12_pack_authsafes (p12, safes);
sk_pop_free(safes, PKCS7_free);
PKCS12_set_mac (p12, mpass, -1, NULL, 0, maciter, NULL);
i2d_PKCS12_bio (out, p12);
PKCS12_free(p12);
ret = 0;
#ifdef CRYPTO_MDEBUG
CRYPTO_pop_info();
#endif
goto end;
}
if (!(p12 = d2i_PKCS12_bio (in, NULL))) {
ERR_print_errors(bio_err);
goto end;
}
#ifdef CRYPTO_MDEBUG
CRYPTO_push_info("read import password");
#endif
if(!noprompt && EVP_read_pw_string(pass, 50, "Enter Import Password:", 0)) {
BIO_printf (bio_err, "Can't read Password\n");
goto end;
}
#ifdef CRYPTO_MDEBUG
CRYPTO_pop_info();
#endif
if (!twopass) strcpy(macpass, pass);
if (options & INFO) BIO_printf (bio_err, "MAC Iteration %ld\n", p12->mac->iter ? ASN1_INTEGER_get (p12->mac->iter) : 1);
if(macver) {
#ifdef CRYPTO_MDEBUG
CRYPTO_push_info("verify MAC");
#endif
if (!PKCS12_verify_mac (p12, mpass, -1)) {
BIO_printf (bio_err, "Mac verify error: invalid password?\n");
ERR_print_errors (bio_err);
goto end;
} else BIO_printf (bio_err, "MAC verified OK\n");
#ifdef CRYPTO_MDEBUG
CRYPTO_pop_info();
#endif
}
#ifdef CRYPTO_MDEBUG
CRYPTO_push_info("output keys and certificates");
#endif
if (!dump_certs_keys_p12 (out, p12, cpass, -1, options, passout)) {
BIO_printf(bio_err, "Error outputting keys and certificates\n");
ERR_print_errors (bio_err);
goto end;
}
#ifdef CRYPTO_MDEBUG
CRYPTO_pop_info();
#endif
PKCS12_free(p12);
ret = 0;
end:
if(export_cert || inrand) app_RAND_write_file(NULL, bio_err);
#ifdef CRYPTO_MDEBUG
CRYPTO_remove_all_info();
#endif
BIO_free(in);
BIO_free(out);
if(passin) Free(passin);
if(passout) Free(passout);
EXIT(ret);
}
int dump_certs_keys_p12 (BIO *out, PKCS12 *p12, char *pass,
int passlen, int options, char *pempass)
{
STACK *asafes, *bags;
int i, bagnid;
PKCS7 *p7;
if (!( asafes = M_PKCS12_unpack_authsafes (p12))) return 0;
for (i = 0; i < sk_num (asafes); i++) {
p7 = (PKCS7 *) sk_value (asafes, i);
bagnid = OBJ_obj2nid (p7->type);
if (bagnid == NID_pkcs7_data) {
bags = M_PKCS12_unpack_p7data (p7);
if (options & INFO) BIO_printf (bio_err, "PKCS7 Data\n");
} else if (bagnid == NID_pkcs7_encrypted) {
if (options & INFO) {
BIO_printf (bio_err, "PKCS7 Encrypted data: ");
alg_print (bio_err,
p7->d.encrypted->enc_data->algorithm);
}
bags = M_PKCS12_unpack_p7encdata (p7, pass, passlen);
} else continue;
if (!bags) return 0;
if (!dump_certs_pkeys_bags (out, bags, pass, passlen,
options, pempass)) {
sk_pop_free (bags, PKCS12_SAFEBAG_free);
return 0;
}
sk_pop_free (bags, PKCS12_SAFEBAG_free);
}
sk_pop_free (asafes, PKCS7_free);
return 1;
}
int dump_certs_pkeys_bags (BIO *out, STACK *bags, char *pass,
int passlen, int options, char *pempass)
{
int i;
for (i = 0; i < sk_num (bags); i++) {
if (!dump_certs_pkeys_bag (out,
(PKCS12_SAFEBAG *)sk_value (bags, i), pass, passlen,
options, pempass)) return 0;
}
return 1;
}
int dump_certs_pkeys_bag (BIO *out, PKCS12_SAFEBAG *bag, char *pass,
int passlen, int options, char *pempass)
{
EVP_PKEY *pkey;
PKCS8_PRIV_KEY_INFO *p8;
X509 *x509;
switch (M_PKCS12_bag_type(bag))
{
case NID_keyBag:
if (options & INFO) BIO_printf (bio_err, "Key bag\n");
if (options & NOKEYS) return 1;
print_attribs (out, bag->attrib, "Bag Attributes");
p8 = bag->value.keybag;
if (!(pkey = EVP_PKCS82PKEY (p8))) return 0;
print_attribs (out, p8->attributes, "Key Attributes");
PEM_write_bio_PrivateKey (out, pkey, enc, NULL, 0, NULL, pempass);
EVP_PKEY_free(pkey);
break;
case NID_pkcs8ShroudedKeyBag:
if (options & INFO) {
BIO_printf (bio_err, "Shrouded Keybag: ");
alg_print (bio_err, bag->value.shkeybag->algor);
}
if (options & NOKEYS) return 1;
print_attribs (out, bag->attrib, "Bag Attributes");
if (!(p8 = M_PKCS12_decrypt_skey (bag, pass, passlen)))
return 0;
if (!(pkey = EVP_PKCS82PKEY (p8))) return 0;
print_attribs (out, p8->attributes, "Key Attributes");
PKCS8_PRIV_KEY_INFO_free(p8);
PEM_write_bio_PrivateKey (out, pkey, enc, NULL, 0, NULL, pempass);
EVP_PKEY_free(pkey);
break;
case NID_certBag:
if (options & INFO) BIO_printf (bio_err, "Certificate bag\n");
if (options & NOCERTS) return 1;
if (PKCS12_get_attr(bag, NID_localKeyID)) {
if (options & CACERTS) return 1;
} else if (options & CLCERTS) return 1;
print_attribs (out, bag->attrib, "Bag Attributes");
if (M_PKCS12_cert_bag_type(bag) != NID_x509Certificate )
return 1;
if (!(x509 = M_PKCS12_certbag2x509(bag))) return 0;
dump_cert_text (out, x509);
PEM_write_bio_X509 (out, x509);
X509_free(x509);
break;
case NID_safeContentsBag:
if (options & INFO) BIO_printf (bio_err, "Safe Contents bag\n");
print_attribs (out, bag->attrib, "Bag Attributes");
return dump_certs_pkeys_bags (out, bag->value.safes, pass,
passlen, options, pempass);
default:
BIO_printf (bio_err, "Warning unsupported bag type: ");
i2a_ASN1_OBJECT (bio_err, bag->type);
BIO_printf (bio_err, "\n");
return 1;
break;
}
return 1;
}
int alg_print (BIO *x, X509_ALGOR *alg)
{
PBEPARAM *pbe;
unsigned char *p;
p = alg->parameter->value.sequence->data;
pbe = d2i_PBEPARAM (NULL, &p, alg->parameter->value.sequence->length);
BIO_printf (bio_err, "%s, Iteration %d\n",
OBJ_nid2ln(OBJ_obj2nid(alg->algorithm)), ASN1_INTEGER_get(pbe->iter));
PBEPARAM_free (pbe);
return 0;
}
void hex_prin(BIO *out, unsigned char *buf, int len)
{
int i;
for (i = 0; i < len; i++) BIO_printf (out, "%02X ", buf[i]);
}
