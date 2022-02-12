static void tls12_signature_print(BIO *out, const unsigned char hash_alg,
const unsigned char sig_alg)
{
int nid = NID_undef;
if (hash_alg == TLSEXT_hash_sha256) {
if (sig_alg == TLSEXT_signature_rsa)
nid = NID_sha256WithRSAEncryption;
else if (sig_alg == TLSEXT_signature_ecdsa)
nid = NID_ecdsa_with_SHA256;
}
if (nid == NID_undef)
BIO_printf(out, "%02X%02X", hash_alg, sig_alg);
else
BIO_printf(out, "%s", OBJ_nid2ln(nid));
}
static void timestamp_print(BIO *out, SCT_TIMESTAMP timestamp)
{
ASN1_GENERALIZEDTIME *gen;
char genstr[20];
gen = ASN1_GENERALIZEDTIME_new();
ASN1_GENERALIZEDTIME_adj(gen, (time_t)0,
(int)(timestamp / 86400000),
(timestamp % 86400000) / 1000);
BIO_snprintf(genstr, sizeof(genstr), "%.14s.%03dZ",
ASN1_STRING_data(gen), (unsigned int)(timestamp % 1000));
ASN1_GENERALIZEDTIME_set_string(gen, genstr);
ASN1_GENERALIZEDTIME_print(out, gen);
ASN1_GENERALIZEDTIME_free(gen);
}
static void SCT_free(SCT *sct)
{
if (sct) {
if (sct->sct)
OPENSSL_free(sct->sct);
OPENSSL_free(sct);
}
}
