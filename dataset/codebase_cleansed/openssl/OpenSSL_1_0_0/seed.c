void SEED_set_key(const unsigned char rawkey[SEED_KEY_LENGTH], SEED_KEY_SCHEDULE *ks)
{
seed_word x1, x2, x3, x4;
seed_word t0, t1;
char2word(rawkey , x1);
char2word(rawkey+4 , x2);
char2word(rawkey+8 , x3);
char2word(rawkey+12, x4);
t0 = (x1 + x3 - KC0) & 0xffffffff;
t1 = (x2 - x4 + KC0) & 0xffffffff; KEYUPDATE_TEMP(t0, t1, &ks->data[0]);
KEYSCHEDULE_UPDATE1(t0, t1, x1, x2, x3, x4, KC1); KEYUPDATE_TEMP(t0, t1, &ks->data[2]);
#if !defined(OPENSSL_SMALL_FOOTPRINT)
KEYSCHEDULE_UPDATE0(t0, t1, x1, x2, x3, x4, KC2); KEYUPDATE_TEMP(t0, t1, &ks->data[4]);
KEYSCHEDULE_UPDATE1(t0, t1, x1, x2, x3, x4, KC3); KEYUPDATE_TEMP(t0, t1, &ks->data[6]);
KEYSCHEDULE_UPDATE0(t0, t1, x1, x2, x3, x4, KC4); KEYUPDATE_TEMP(t0, t1, &ks->data[8]);
KEYSCHEDULE_UPDATE1(t0, t1, x1, x2, x3, x4, KC5); KEYUPDATE_TEMP(t0, t1, &ks->data[10]);
KEYSCHEDULE_UPDATE0(t0, t1, x1, x2, x3, x4, KC6); KEYUPDATE_TEMP(t0, t1, &ks->data[12]);
KEYSCHEDULE_UPDATE1(t0, t1, x1, x2, x3, x4, KC7); KEYUPDATE_TEMP(t0, t1, &ks->data[14]);
KEYSCHEDULE_UPDATE0(t0, t1, x1, x2, x3, x4, KC8); KEYUPDATE_TEMP(t0, t1, &ks->data[16]);
KEYSCHEDULE_UPDATE1(t0, t1, x1, x2, x3, x4, KC9); KEYUPDATE_TEMP(t0, t1, &ks->data[18]);
KEYSCHEDULE_UPDATE0(t0, t1, x1, x2, x3, x4, KC10); KEYUPDATE_TEMP(t0, t1, &ks->data[20]);
KEYSCHEDULE_UPDATE1(t0, t1, x1, x2, x3, x4, KC11); KEYUPDATE_TEMP(t0, t1, &ks->data[22]);
KEYSCHEDULE_UPDATE0(t0, t1, x1, x2, x3, x4, KC12); KEYUPDATE_TEMP(t0, t1, &ks->data[24]);
KEYSCHEDULE_UPDATE1(t0, t1, x1, x2, x3, x4, KC13); KEYUPDATE_TEMP(t0, t1, &ks->data[26]);
KEYSCHEDULE_UPDATE0(t0, t1, x1, x2, x3, x4, KC14); KEYUPDATE_TEMP(t0, t1, &ks->data[28]);
KEYSCHEDULE_UPDATE1(t0, t1, x1, x2, x3, x4, KC15); KEYUPDATE_TEMP(t0, t1, &ks->data[30]);
#else
{
int i;
for (i=2; i<16; i+=2) {
KEYSCHEDULE_UPDATE0(t0, t1, x1, x2, x3, x4, KC[i]);
KEYUPDATE_TEMP(t0, t1, &ks->data[i*2]);
KEYSCHEDULE_UPDATE1(t0, t1, x1, x2, x3, x4, KC[i+1]);
KEYUPDATE_TEMP(t0, t1, &ks->data[i*2+2]);
}
}
#endif
}
void SEED_encrypt(const unsigned char s[SEED_BLOCK_SIZE], unsigned char d[SEED_BLOCK_SIZE], const SEED_KEY_SCHEDULE *ks)
{
seed_word x1, x2, x3, x4;
seed_word t0, t1;
char2word(s, x1);
char2word(s+4, x2);
char2word(s+8, x3);
char2word(s+12, x4);
#if !defined(OPENSSL_SMALL_FOOTPRINT)
E_SEED(t0, t1, x1, x2, x3, x4, 0);
E_SEED(t0, t1, x3, x4, x1, x2, 2);
E_SEED(t0, t1, x1, x2, x3, x4, 4);
E_SEED(t0, t1, x3, x4, x1, x2, 6);
E_SEED(t0, t1, x1, x2, x3, x4, 8);
E_SEED(t0, t1, x3, x4, x1, x2, 10);
E_SEED(t0, t1, x1, x2, x3, x4, 12);
E_SEED(t0, t1, x3, x4, x1, x2, 14);
E_SEED(t0, t1, x1, x2, x3, x4, 16);
E_SEED(t0, t1, x3, x4, x1, x2, 18);
E_SEED(t0, t1, x1, x2, x3, x4, 20);
E_SEED(t0, t1, x3, x4, x1, x2, 22);
E_SEED(t0, t1, x1, x2, x3, x4, 24);
E_SEED(t0, t1, x3, x4, x1, x2, 26);
E_SEED(t0, t1, x1, x2, x3, x4, 28);
E_SEED(t0, t1, x3, x4, x1, x2, 30);
#else
{
int i;
for (i=0;i<30;i+=4) {
E_SEED(t0,t1,x1,x2,x3,x4,i);
E_SEED(t0,t1,x3,x4,x1,x2,i+2);
}
}
#endif
word2char(x3, d);
word2char(x4, d+4);
word2char(x1, d+8);
word2char(x2, d+12);
}
void SEED_decrypt(const unsigned char s[SEED_BLOCK_SIZE], unsigned char d[SEED_BLOCK_SIZE], const SEED_KEY_SCHEDULE *ks)
{
seed_word x1, x2, x3, x4;
seed_word t0, t1;
char2word(s, x1);
char2word(s+4, x2);
char2word(s+8, x3);
char2word(s+12, x4);
#if !defined(OPENSSL_SMALL_FOOTPRINT)
E_SEED(t0, t1, x1, x2, x3, x4, 30);
E_SEED(t0, t1, x3, x4, x1, x2, 28);
E_SEED(t0, t1, x1, x2, x3, x4, 26);
E_SEED(t0, t1, x3, x4, x1, x2, 24);
E_SEED(t0, t1, x1, x2, x3, x4, 22);
E_SEED(t0, t1, x3, x4, x1, x2, 20);
E_SEED(t0, t1, x1, x2, x3, x4, 18);
E_SEED(t0, t1, x3, x4, x1, x2, 16);
E_SEED(t0, t1, x1, x2, x3, x4, 14);
E_SEED(t0, t1, x3, x4, x1, x2, 12);
E_SEED(t0, t1, x1, x2, x3, x4, 10);
E_SEED(t0, t1, x3, x4, x1, x2, 8);
E_SEED(t0, t1, x1, x2, x3, x4, 6);
E_SEED(t0, t1, x3, x4, x1, x2, 4);
E_SEED(t0, t1, x1, x2, x3, x4, 2);
E_SEED(t0, t1, x3, x4, x1, x2, 0);
#else
{
int i;
for (i=30; i>0; i-=4) {
E_SEED(t0, t1, x1, x2, x3, x4, i);
E_SEED(t0, t1, x3, x4, x1, x2, i-2);
}
}
#endif
word2char(x3, d);
word2char(x4, d+4);
word2char(x1, d+8);
word2char(x2, d+12);
}
