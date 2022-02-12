int AirPDcapWepDecrypt(
const guchar *seed,
const size_t seed_len,
guchar *cypher_text,
const size_t data_len)
{
guint32 i, j, k, crc;
guint8 S[256];
guint8 icv[4];
size_t buflen;
for (i = 0; i < 256; i++)
S[i] = (guint8)i;
for (j = i = 0; i < 256; i++) {
j = (j + S[i] + seed[i % seed_len]) & 0xff;
S_SWAP(i, j);
}
crc = ~(guint32)0;
buflen = data_len;
for (i = j = k = 0; k < buflen; k++) {
i = (i + 1) & 0xff;
j = (j + S[i]) & 0xff;
S_SWAP(i, j);
*cypher_text ^= S[(S[i] + S[j]) & 0xff];
crc = crc32_ccitt_table_lookup((crc ^ *cypher_text) & 0xff) ^ (crc >> 8);
cypher_text++;
}
crc = ~crc;
icv[0] = (guint8)crc;
icv[1] = (guint8)(crc >> 8);
icv[2] = (guint8)(crc >> 16);
icv[3] = (guint8)(crc >> 24);
for (k = 0; k < 4; k++) {
i = (i + 1) & 0xff;
j = (j + S[i]) & 0xff;
S_SWAP(i, j);
if ((icv[k] ^ S[(S[i] + S[j]) & 0xff]) != *cypher_text++) {
return 1;
}
}
return 0;
}
