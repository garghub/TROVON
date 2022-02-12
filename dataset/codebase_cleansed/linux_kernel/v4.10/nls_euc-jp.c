static inline int sjisibm2euc(unsigned char *euc, const unsigned char sjis_hi,
const unsigned char sjis_lo)
{
int index;
index = ((sjis_hi - 0xFA) * (0xFD - 0x40)) + (sjis_lo - 0x40);
if (IS_EUC_IBM2JISX0208(sjisibm2euc_map[index][0],
sjisibm2euc_map[index][1])) {
euc[0] = sjisibm2euc_map[index][0];
euc[1] = sjisibm2euc_map[index][1];
return 2;
} else {
euc[0] = SS3;
euc[1] = sjisibm2euc_map[index][0];
euc[2] = sjisibm2euc_map[index][1];
return 3;
}
}
static inline int euc2sjisibm_jisx0212(unsigned char *sjis, const unsigned char euc_hi,
const unsigned char euc_lo)
{
int index, min_index, max_index;
unsigned short euc;
min_index = 0;
max_index = ARRAY_SIZE(euc2sjisibm_jisx0212_map) - 1;
euc = (euc_hi << 8) | euc_lo;
while (min_index <= max_index) {
index = (min_index + max_index) / 2;
if (euc < euc2sjisibm_jisx0212_map[index].euc)
max_index = index - 1;
else
min_index = index + 1;
if (euc == euc2sjisibm_jisx0212_map[index].euc) {
sjis[0] = euc2sjisibm_jisx0212_map[index].sjis[0];
sjis[1] = euc2sjisibm_jisx0212_map[index].sjis[1];
return 3;
}
}
return 0;
}
static inline int euc2sjisibm_g3upper(unsigned char *sjis, const unsigned char euc_hi,
const unsigned char euc_lo)
{
int index;
if (euc_hi == 0xF3)
index = ((euc_hi << 8) | euc_lo) - 0xF3F3;
else
index = ((euc_hi << 8) | euc_lo) - 0xF4A1 + 12;
if ((index < 0) || (index >= ARRAY_SIZE(euc2sjisibm_g3upper_map)))
return 0;
sjis[0] = euc2sjisibm_g3upper_map[index][0];
sjis[1] = euc2sjisibm_g3upper_map[index][1];
return 3;
}
static inline int euc2sjisibm(unsigned char *sjis, const unsigned char euc_hi,
const unsigned char euc_lo)
{
int n;
#if 0
if ((euc_hi == 0xA2) && (euc_lo == 0xCC)) {
sjis[0] = 0xFA;
sjis[1] = 0x54;
return 2;
} else if ((euc_hi == 0xA2) && (euc_lo == 0xE8)) {
sjis[0] = 0xFA;
sjis[1] = 0x5B;
return 2;
}
#endif
if ((n = euc2sjisibm_g3upper(sjis, euc_hi, euc_lo))) {
return n;
} else if ((n = euc2sjisibm_jisx0212(sjis, euc_hi, euc_lo))) {
return n;
}
return 0;
}
static inline int sjisnec2sjisibm(unsigned char *sjisibm,
const unsigned char sjisnec_hi,
const unsigned char sjisnec_lo)
{
int count;
if (! IS_SJIS_NECIBM(sjisnec_hi, sjisnec_lo))
return 0;
if ((sjisnec_hi == 0xEE) && (sjisnec_lo == 0xF9)) {
sjisibm[0] = 0x81;
sjisibm[1] = 0xCA;
return 2;
}
if ((sjisnec_hi == 0xEE) && (sjisnec_lo >= 0xEF)) {
count = (sjisnec_hi << 8 | sjisnec_lo)
- (sjisnec_lo <= 0xF9 ? 0xEEEF : (0xEEEF - 10));
} else {
count = (sjisnec_hi - 0xED) * (0xFC - 0x40)
+ (sjisnec_lo - 0x40) + (0x5C - 0x40);
if (sjisnec_lo >= 0x7F)
count--;
}
sjisibm[0] = 0xFA + (count / (0xFC - 0x40));
sjisibm[1] = 0x40 + (count % (0xFC - 0x40));
if (sjisibm[1] >= 0x7F)
sjisibm[1]++;
return 2;
}
static int uni2char(const wchar_t uni,
unsigned char *out, int boundlen)
{
int n;
if (!p_nls)
return -EINVAL;
if ((n = p_nls->uni2char(uni, out, boundlen)) < 0)
return n;
if (n == 1) {
if (IS_SJIS_JISX0201KANA(out[0])) {
if (boundlen < 2)
return -ENAMETOOLONG;
out[1] = out[0];
out[0] = SS2;
return 2;
}
} else if (n == 2) {
sjisnec2sjisibm(out, out[0], out[1]);
if (IS_SJIS_UDC_LOW(out[0], out[1])) {
MAP_SJIS2EUC(out[0], out[1], 0xF0, out[0], out[1], 0xF5);
} else if (IS_SJIS_UDC_HI(out[0], out[1])) {
unsigned char ch, cl;
if (boundlen < 3)
return -ENAMETOOLONG;
n = 3; ch = out[0]; cl = out[1];
out[0] = SS3;
MAP_SJIS2EUC(ch, cl, 0xF5, out[1], out[2], 0xF5);
} else if (IS_SJIS_IBM(out[0], out[1])) {
unsigned char euc[3], i;
n = sjisibm2euc(euc, out[0], out[1]);
if (boundlen < n)
return -ENAMETOOLONG;
for (i = 0; i < n; i++)
out[i] = euc[i];
} else if (IS_SJIS_JISX0208(out[0], out[1])) {
out[0] = (out[0]^0xA0)*2 + 0x5F;
if (out[1] > 0x9E)
out[0]++;
if (out[1] < 0x7F)
out[1] = out[1] + 0x61;
else if (out[1] < 0x9F)
out[1] = out[1] + 0x60;
else
out[1] = out[1] + 0x02;
} else {
return -EINVAL;
}
}
else
return -EINVAL;
return n;
}
static int char2uni(const unsigned char *rawstring, int boundlen,
wchar_t *uni)
{
unsigned char sjis_temp[2];
int euc_offset, n;
if ( !p_nls )
return -EINVAL;
if (boundlen <= 0)
return -ENAMETOOLONG;
if (rawstring[0] > 0x7F) {
if (rawstring[0] == SS3) {
if (boundlen < 3)
return -EINVAL;
euc_offset = 3;
if (IS_EUC_UDC_HI(rawstring[1], rawstring[2])) {
MAP_EUC2SJIS(rawstring[1], rawstring[2], 0xF5,
sjis_temp[0], sjis_temp[1], 0xF5);
} else if (euc2sjisibm(sjis_temp,rawstring[1],rawstring[2])) {
} else {
return -EINVAL;
}
} else {
if (boundlen < 2)
return -EINVAL;
euc_offset = 2;
if (IS_EUC_JISX0201KANA(rawstring[0], rawstring[1])) {
sjis_temp[0] = rawstring[1];
sjis_temp[1] = 0x00;
} else if (IS_EUC_UDC_LOW(rawstring[0], rawstring[1])) {
MAP_EUC2SJIS(rawstring[0], rawstring[1], 0xF5,
sjis_temp[0], sjis_temp[1], 0xF0);
} else if (IS_EUC_JISX0208(rawstring[0], rawstring[1])) {
sjis_temp[0] = ((rawstring[0]-0x5f)/2) ^ 0xA0;
if (!(rawstring[0] & 1))
sjis_temp[1] = rawstring[1] - 0x02;
else if (rawstring[1] < 0xE0)
sjis_temp[1] = rawstring[1] - 0x61;
else
sjis_temp[1] = rawstring[1] - 0x60;
} else {
return -EINVAL;
}
}
} else {
euc_offset = 1;
sjis_temp[0] = rawstring[0];
sjis_temp[1] = 0x00;
}
if ( (n = p_nls->char2uni(sjis_temp, sizeof(sjis_temp), uni)) < 0)
return n;
return euc_offset;
}
static int __init init_nls_euc_jp(void)
{
p_nls = load_nls("cp932");
if (p_nls) {
table.charset2upper = p_nls->charset2upper;
table.charset2lower = p_nls->charset2lower;
return register_nls(&table);
}
return -EINVAL;
}
static void __exit exit_nls_euc_jp(void)
{
unregister_nls(&table);
unload_nls(p_nls);
}
