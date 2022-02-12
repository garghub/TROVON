int PKCS12_key_gen_asc (const char *pass, int passlen, unsigned char *salt,
int saltlen, int id, int iter, int n, unsigned char *out,
const EVP_MD *md_type)
{
int ret;
unsigned char *unipass;
int uniplen;
if (!asc2uni (pass, &unipass, &uniplen)) {
PKCS12err(PKCS12_F_PKCS12_KEY_GEN_ASC,ERR_R_MALLOC_FAILURE);
return 0;
}
ret = PKCS12_key_gen_uni (unipass, uniplen, salt, saltlen,
id, iter, n, out, md_type);
memset(unipass, 0, uniplen);
Free(unipass);
return ret;
}
int PKCS12_key_gen_uni (unsigned char *pass, int passlen, unsigned char *salt,
int saltlen, int id, int iter, int n, unsigned char *out,
const EVP_MD *md_type)
{
unsigned char *B, *D, *I, *p, *Ai;
int Slen, Plen, Ilen;
int i, j, u, v;
BIGNUM *Ij, *Bpl1;
EVP_MD_CTX ctx;
#ifdef DEBUG_KEYGEN
unsigned char *tmpout = out;
int tmpn = n;
BIO_printf (bio_err, "KEYGEN DEBUG\n");
BIO_printf (bio_err, "ID %d, ITER %d\n", id, iter);
BIO_printf (bio_err, "Password (length %d):\n", passlen);
h__dump (pass, passlen);
BIO_printf (bio_err, "Salt (length %d):\n", saltlen);
h__dump (salt, saltlen);
BIO_printf (bio_err, "ID %d, ITER %d\n\n", id, iter);
#endif
v = EVP_MD_block_size (md_type);
u = EVP_MD_size (md_type);
D = Malloc (v);
Ai = Malloc (u);
B = Malloc (v + 1);
Slen = v * ((saltlen+v-1)/v);
Plen = v * ((passlen+v-1)/v);
Ilen = Slen + Plen;
I = Malloc (Ilen);
Ij = BN_new();
Bpl1 = BN_new();
if (!D || !Ai || !B || !I || !Ij || !Bpl1) {
PKCS12err(PKCS12_F_PKCS12_KEY_GEN_UNI,ERR_R_MALLOC_FAILURE);
return 0;
}
for (i = 0; i < v; i++) D[i] = id;
p = I;
for (i = 0; i < Slen; i++) *p++ = salt[i % saltlen];
for (i = 0; i < Plen; i++) *p++ = pass[i % passlen];
for (;;) {
EVP_DigestInit (&ctx, md_type);
EVP_DigestUpdate (&ctx, D, v);
EVP_DigestUpdate (&ctx, I, Ilen);
EVP_DigestFinal (&ctx, Ai, NULL);
for (j = 1; j < iter; j++) {
EVP_DigestInit (&ctx, md_type);
EVP_DigestUpdate (&ctx, Ai, u);
EVP_DigestFinal (&ctx, Ai, NULL);
}
memcpy (out, Ai, min (n, u));
if (u >= n) {
Free (Ai);
Free (B);
Free (D);
Free (I);
BN_free (Ij);
BN_free (Bpl1);
#ifdef DEBUG_KEYGEN
BIO_printf (bio_err, "Output KEY (length %d)\n", tmpn);
h__dump (tmpout, tmpn);
#endif
return 1;
}
n -= u;
out += u;
for (j = 0; j < v; j++) B[j] = Ai[j % u];
BN_bin2bn (B, v, Bpl1);
BN_add_word (Bpl1, 1);
for (j = 0; j < Ilen ; j+=v) {
BN_bin2bn (I + j, v, Ij);
BN_add (Ij, Ij, Bpl1);
BN_bn2bin (Ij, B);
if (BN_num_bytes (Ij) > v) {
BN_bn2bin (Ij, B);
memcpy (I + j, B + 1, v);
} else BN_bn2bin (Ij, I + j);
}
}
}
void h__dump (unsigned char *p, int len)
{
for (; len --; p++) BIO_printf (bio_err, "%02X", *p);
BIO_printf (bio_err, "\n");
}
