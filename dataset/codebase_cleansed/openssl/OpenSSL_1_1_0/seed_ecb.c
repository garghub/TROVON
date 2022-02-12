void SEED_ecb_encrypt(const unsigned char *in, unsigned char *out,
const SEED_KEY_SCHEDULE *ks, int enc)
{
if (enc)
SEED_encrypt(in, out, ks);
else
SEED_decrypt(in, out, ks);
}
