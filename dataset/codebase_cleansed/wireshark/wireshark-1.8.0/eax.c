gboolean Eax_Decrypt(guint8 *pN, guint8 *pK, guint8 *pC,
guint32 SizeN, guint32 SizeK, guint32 SizeC, MAC_T *pMac,
guint8 Mode)
{
guint8 wsn[EAX_SIZEOF_KEY];
guint8 wsc[EAX_SIZEOF_KEY];
int i;
if (SizeK != EAX_SIZEOF_KEY)
return FALSE;
for (i = 0; i < EAX_SIZEOF_KEY; i++)
instance.L[i] = 0;
AesEncrypt(instance.L, pK);
Dbl(instance.D, instance.L);
Dbl(instance.Q, instance.D);
BLK_CPY(wsn, instance.D);
if (Mode == EAX_MODE_CLEARTEXT_AUTH) {
dCMAC(pK, wsn, pN, SizeN, pC, SizeC);
} else {
CMAC(pK, wsn, pN, SizeN);
}
if (Mode == EAX_MODE_CLEARTEXT_AUTH)
{
return (memcmp(pMac, &wsn[EAX_SIZEOF_KEY-sizeof(*pMac)], sizeof(*pMac)) ? FALSE : TRUE);
}
else if (Mode == EAX_MODE_CIPHERTEXT_AUTH)
{
if (SizeC == 0)
return (memcmp(pMac, &wsn[EAX_SIZEOF_KEY-sizeof(*pMac)], sizeof(*pMac)) ? FALSE : TRUE);
{
BLK_CPY(wsc, instance.Q);
CMAC(pK, wsc, pC, SizeC);
BLK_XOR(wsc, wsn);
}
if (memcmp(pMac, &wsc[EAX_SIZEOF_KEY-sizeof(*pMac)], sizeof(*pMac)) == 0)
{
CTR(wsn, pK, pC, SizeC);
return TRUE;
}
}
return FALSE;
}
static void Dbl(guint8 *out, const guint8 *in)
{
int i;
guint8 carry = 0;
for (i=0; i < EAX_SIZEOF_KEY; i++)
{
out[i] = ( in[i] << 1 ) | carry;
carry = (in[i] & 0x80) ? 1 : 0;
}
if (carry)
out[0] ^= 0x87;
}
static void CMAC(guint8 *pK, guint8 *ws, const guint8 *pN, guint16 SizeN)
{
dCMAC(pK, ws, pN, SizeN, NULL, 0);
}
static void dCMAC(guint8 *pK, guint8 *ws, const guint8 *pN, guint16 SizeN, const guint8 *pC, guint16 SizeC)
{
gcry_cipher_hd_t cipher_hd;
guint8 *work;
guint8 *ptr;
guint16 SizeT = SizeN + SizeC;
guint16 worksize = SizeT;
if (SizeT & 0xf) {
worksize += 0x10 - (worksize & 0xf);
}
work = g_malloc(worksize);
if (work == NULL) {
return;
}
memcpy(work, pN, SizeN);
if (pC != NULL) {
memcpy(&work[SizeN], pC, SizeC);
}
if (worksize != SizeT) {
work[SizeT] = 0x80;
for (ptr = &work[SizeT+1]; ptr < &work[worksize]; ptr++)
*ptr = 0;
ptr= &work[worksize-0x10];
BLK_XOR(ptr, instance.Q);
} else {
ptr = &work[worksize-0x10];
BLK_XOR(ptr, instance.D);
}
if (gcry_cipher_open(&cipher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_CBC,0)){
g_free(work);
return;
}
if (gcry_cipher_setkey(cipher_hd, pK, EAX_SIZEOF_KEY)) {
g_free(work);
gcry_cipher_close(cipher_hd);
return;
}
if (gcry_cipher_setiv(cipher_hd, ws, EAX_SIZEOF_KEY)) {
g_free(work);
gcry_cipher_close(cipher_hd);
return;
}
if (gcry_cipher_encrypt(cipher_hd, work, worksize, work, worksize)) {
g_free(work);
gcry_cipher_close(cipher_hd);
return;
}
memcpy(ws, ptr, EAX_SIZEOF_KEY);
g_free(work);
gcry_cipher_close(cipher_hd);
return;
}
static void CTR(const guint8 *ws, guint8 *pK, guint8 *pN, guint16 SizeN)
{
gcry_cipher_hd_t cipher_hd;
guint8 ctr[EAX_SIZEOF_KEY];
BLK_CPY(ctr, ws);
ctr[12] &= 0x7f;
ctr[14] &= 0x7f;
if (gcry_cipher_open(&cipher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_CTR, 0)) {
return;
}
if (gcry_cipher_setkey(cipher_hd, pK, EAX_SIZEOF_KEY)) {
gcry_cipher_close(cipher_hd);
return;
}
if (gcry_cipher_setctr(cipher_hd, ctr, EAX_SIZEOF_KEY)) {
gcry_cipher_close(cipher_hd);
return;
}
if (gcry_cipher_encrypt(cipher_hd, pN, SizeN, pN, SizeN)) {
gcry_cipher_close(cipher_hd);
return;
}
gcry_cipher_close(cipher_hd);
return;
}
void AesEncrypt(unsigned char msg[EAX_SIZEOF_KEY], unsigned char key[EAX_SIZEOF_KEY])
{
gcry_cipher_hd_t cipher_hd;
if (gcry_cipher_open(&cipher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_ECB, 0)) {
return;
}
if (gcry_cipher_setkey(cipher_hd, key, EAX_SIZEOF_KEY)) {
gcry_cipher_close(cipher_hd);
return;
}
if (gcry_cipher_encrypt(cipher_hd, msg, EAX_SIZEOF_KEY, msg, EAX_SIZEOF_KEY)) {
gcry_cipher_close(cipher_hd);
return;
}
gcry_cipher_close(cipher_hd);
return;
}
