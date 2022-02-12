void SEED_ecb_encrypt(const unsigned char *in, unsigned char *out, const SEED_KEY_SCHEDULE *ks, int enc)\r\n{\r\nif (enc)\r\nSEED_encrypt(in, out, ks);\r\nelse\r\nSEED_decrypt(in, out, ks);\r\n}
