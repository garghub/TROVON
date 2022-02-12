void
dsp_bf_encrypt(struct dsp *dsp, u8 *data, int len)
{
int i = 0, j = dsp->bf_crypt_pos;
u8 *bf_data_in = dsp->bf_data_in;
u8 *bf_crypt_out = dsp->bf_crypt_out;
u32 *P = dsp->bf_p;
u32 *S = dsp->bf_s;
u32 yl, yr;
u32 cs;
u8 nibble;
while (i < len) {
if (j < 9) {
bf_data_in[j] = *data;
*data++ = bf_crypt_out[j++];
i++;
continue;
}
j = 0;
yl = dsp_audio_law2seven[bf_data_in[0]];
yl = (yl<<7) | dsp_audio_law2seven[bf_data_in[1]];
yl = (yl<<7) | dsp_audio_law2seven[bf_data_in[2]];
yl = (yl<<7) | dsp_audio_law2seven[bf_data_in[3]];
nibble = dsp_audio_law2seven[bf_data_in[4]];
yr = nibble;
yl = (yl<<4) | (nibble>>3);
yr = (yr<<7) | dsp_audio_law2seven[bf_data_in[5]];
yr = (yr<<7) | dsp_audio_law2seven[bf_data_in[6]];
yr = (yr<<7) | dsp_audio_law2seven[bf_data_in[7]];
yr = (yr<<7) | dsp_audio_law2seven[bf_data_in[8]];
yr = (yr<<1) | (bf_data_in[0] & 1);
EROUND(yr, yl, 0);
EROUND(yl, yr, 1);
EROUND(yr, yl, 2);
EROUND(yl, yr, 3);
EROUND(yr, yl, 4);
EROUND(yl, yr, 5);
EROUND(yr, yl, 6);
EROUND(yl, yr, 7);
EROUND(yr, yl, 8);
EROUND(yl, yr, 9);
EROUND(yr, yl, 10);
EROUND(yl, yr, 11);
EROUND(yr, yl, 12);
EROUND(yl, yr, 13);
EROUND(yr, yl, 14);
EROUND(yl, yr, 15);
yl ^= P[16];
yr ^= P[17];
cs = yl ^ (yl>>3) ^ (yl>>6) ^ (yl>>9) ^ (yl>>12) ^ (yl>>15)
^ (yl>>18) ^ (yl>>21) ^ (yl>>24) ^ (yl>>27) ^ (yl>>30)
^ (yr<<2) ^ (yr>>1) ^ (yr>>4) ^ (yr>>7) ^ (yr>>10)
^ (yr>>13) ^ (yr>>16) ^ (yr>>19) ^ (yr>>22) ^ (yr>>25)
^ (yr>>28) ^ (yr>>31);
bf_crypt_out[0] = (yl>>25) | 0x80;
bf_crypt_out[1] = (yl>>18) & 0x7f;
bf_crypt_out[2] = (yl>>11) & 0x7f;
bf_crypt_out[3] = (yl>>4) & 0x7f;
bf_crypt_out[4] = ((yl<<3) & 0x78) | ((yr>>29) & 0x07);
bf_crypt_out[5] = ((yr>>22) & 0x7f) | ((cs<<5) & 0x80);
bf_crypt_out[6] = ((yr>>15) & 0x7f) | ((cs<<6) & 0x80);
bf_crypt_out[7] = ((yr>>8) & 0x7f) | (cs<<7);
bf_crypt_out[8] = yr;
}
dsp->bf_crypt_pos = j;
}
void
dsp_bf_decrypt(struct dsp *dsp, u8 *data, int len)
{
int i = 0;
u8 j = dsp->bf_decrypt_in_pos;
u8 k = dsp->bf_decrypt_out_pos;
u8 *bf_crypt_inring = dsp->bf_crypt_inring;
u8 *bf_data_out = dsp->bf_data_out;
u16 sync = dsp->bf_sync;
u32 *P = dsp->bf_p;
u32 *S = dsp->bf_s;
u32 yl, yr;
u8 nibble;
u8 cs, cs0, cs1, cs2;
while (i < len) {
sync = (sync<<1) | ((*data)>>7);
bf_crypt_inring[j++ & 15] = *data;
*data++ = bf_data_out[k++];
i++;
if (k == 9)
k = 0;
if ((sync&0x1f0) != 0x100)
continue;
j -= 9;
yl = bf_crypt_inring[j++ & 15];
yl = (yl<<7) | bf_crypt_inring[j++ & 15];
yl = (yl<<7) | bf_crypt_inring[j++ & 15];
yl = (yl<<7) | bf_crypt_inring[j++ & 15];
nibble = bf_crypt_inring[j++ & 15];
yr = nibble;
yl = (yl<<4) | (nibble>>3);
cs2 = bf_crypt_inring[j++ & 15];
yr = (yr<<7) | (cs2 & 0x7f);
cs1 = bf_crypt_inring[j++ & 15];
yr = (yr<<7) | (cs1 & 0x7f);
cs0 = bf_crypt_inring[j++ & 15];
yr = (yr<<7) | (cs0 & 0x7f);
yr = (yr<<8) | bf_crypt_inring[j++ & 15];
cs = yl ^ (yl>>3) ^ (yl>>6) ^ (yl>>9) ^ (yl>>12) ^ (yl>>15)
^ (yl>>18) ^ (yl>>21) ^ (yl>>24) ^ (yl>>27) ^ (yl>>30)
^ (yr<<2) ^ (yr>>1) ^ (yr>>4) ^ (yr>>7) ^ (yr>>10)
^ (yr>>13) ^ (yr>>16) ^ (yr>>19) ^ (yr>>22) ^ (yr>>25)
^ (yr>>28) ^ (yr>>31);
if ((cs&0x7) != (((cs2>>5)&4) | ((cs1>>6)&2) | (cs0 >> 7))) {
if (dsp_debug & DEBUG_DSP_BLOWFISH)
printk(KERN_DEBUG
"DSP BLOWFISH: received corrupt frame, "
"checksumme is not correct\n");
continue;
}
yr ^= P[17];
yl ^= P[16];
DROUND(yl, yr, 15);
DROUND(yr, yl, 14);
DROUND(yl, yr, 13);
DROUND(yr, yl, 12);
DROUND(yl, yr, 11);
DROUND(yr, yl, 10);
DROUND(yl, yr, 9);
DROUND(yr, yl, 8);
DROUND(yl, yr, 7);
DROUND(yr, yl, 6);
DROUND(yl, yr, 5);
DROUND(yr, yl, 4);
DROUND(yl, yr, 3);
DROUND(yr, yl, 2);
DROUND(yl, yr, 1);
DROUND(yr, yl, 0);
bf_data_out[0] = dsp_audio_seven2law[(yl>>25) & 0x7f];
bf_data_out[1] = dsp_audio_seven2law[(yl>>18) & 0x7f];
bf_data_out[2] = dsp_audio_seven2law[(yl>>11) & 0x7f];
bf_data_out[3] = dsp_audio_seven2law[(yl>>4) & 0x7f];
bf_data_out[4] = dsp_audio_seven2law[((yl<<3) & 0x78) |
((yr>>29) & 0x07)];
bf_data_out[5] = dsp_audio_seven2law[(yr>>22) & 0x7f];
bf_data_out[6] = dsp_audio_seven2law[(yr>>15) & 0x7f];
bf_data_out[7] = dsp_audio_seven2law[(yr>>8) & 0x7f];
bf_data_out[8] = dsp_audio_seven2law[(yr>>1) & 0x7f];
k = 0;
}
dsp->bf_decrypt_in_pos = j;
dsp->bf_decrypt_out_pos = k;
dsp->bf_sync = sync;
}
static inline void
encrypt_block(const u32 *P, const u32 *S, u32 *dst, u32 *src)
{
u32 yl = src[0];
u32 yr = src[1];
EROUND(yr, yl, 0);
EROUND(yl, yr, 1);
EROUND(yr, yl, 2);
EROUND(yl, yr, 3);
EROUND(yr, yl, 4);
EROUND(yl, yr, 5);
EROUND(yr, yl, 6);
EROUND(yl, yr, 7);
EROUND(yr, yl, 8);
EROUND(yl, yr, 9);
EROUND(yr, yl, 10);
EROUND(yl, yr, 11);
EROUND(yr, yl, 12);
EROUND(yl, yr, 13);
EROUND(yr, yl, 14);
EROUND(yl, yr, 15);
yl ^= P[16];
yr ^= P[17];
dst[0] = yr;
dst[1] = yl;
}
int
dsp_bf_init(struct dsp *dsp, const u8 *key, uint keylen)
{
short i, j, count;
u32 data[2], temp;
u32 *P = (u32 *)dsp->bf_p;
u32 *S = (u32 *)dsp->bf_s;
if (keylen < 4 || keylen > 56)
return 1;
i = 0;
while (i < 9) {
dsp->bf_crypt_out[i] = 0xff;
dsp->bf_data_out[i] = dsp_silence;
i++;
}
dsp->bf_crypt_pos = 0;
dsp->bf_decrypt_in_pos = 0;
dsp->bf_decrypt_out_pos = 0;
dsp->bf_sync = 0x1ff;
dsp->bf_enable = 1;
for (i = 0, count = 0; i < 256; i++)
for (j = 0; j < 4; j++, count++)
S[count] = bf_sbox[count];
for (i = 0; i < 16 + 2; i++)
P[i] = bf_pbox[i];
for (j = 0, i = 0; i < 16 + 2; i++) {
temp = (((u32)key[j] << 24) |
((u32)key[(j + 1) % keylen] << 16) |
((u32)key[(j + 2) % keylen] << 8) |
((u32)key[(j + 3) % keylen]));
P[i] = P[i] ^ temp;
j = (j + 4) % keylen;
}
data[0] = 0x00000000;
data[1] = 0x00000000;
for (i = 0; i < 16 + 2; i += 2) {
encrypt_block(P, S, data, data);
P[i] = data[0];
P[i + 1] = data[1];
}
for (i = 0; i < 4; i++) {
for (j = 0, count = i * 256; j < 256; j += 2, count += 2) {
encrypt_block(P, S, data, data);
S[count] = data[0];
S[count + 1] = data[1];
}
}
return 0;
}
void
dsp_bf_cleanup(struct dsp *dsp)
{
dsp->bf_enable = 0;
}
