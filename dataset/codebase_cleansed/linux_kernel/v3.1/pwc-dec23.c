static void build_subblock_pattern(struct pwc_dec23_private *pdec)
{
static const unsigned int initial_values[12] = {
-0x526500, -0x221200, 0x221200, 0x526500,
-0x3de200, 0x3de200,
-0x6db480, -0x2d5d00, 0x2d5d00, 0x6db480,
-0x12c200, 0x12c200
};
static const unsigned int values_derivated[12] = {
0xa4ca, 0x4424, -0x4424, -0xa4ca,
0x7bc4, -0x7bc4,
0xdb69, 0x5aba, -0x5aba, -0xdb69,
0x2584, -0x2584
};
unsigned int temp_values[12];
int i, j;
memcpy(temp_values, initial_values, sizeof(initial_values));
for (i = 0; i < 256; i++) {
for (j = 0; j < 12; j++) {
pdec->table_subblock[i][j] = temp_values[j];
temp_values[j] += values_derivated[j];
}
}
}
static void build_bit_powermask_table(struct pwc_dec23_private *pdec)
{
unsigned char *p;
unsigned int bit, byte, mask, val;
unsigned int bitpower = 1;
for (bit = 0; bit < 8; bit++) {
mask = bitpower - 1;
p = pdec->table_bitpowermask[bit];
for (byte = 0; byte < 256; byte++) {
val = (byte & mask);
if (byte & bitpower)
val = -val;
*p++ = val;
}
bitpower<<=1;
}
}
static void build_table_color(const unsigned int romtable[16][8],
unsigned char p0004[16][1024],
unsigned char p8004[16][256])
{
int compression_mode, j, k, bit, pw;
unsigned char *p0, *p8;
const unsigned int *r;
for (compression_mode = 0; compression_mode < 16; compression_mode++) {
p0 = p0004[compression_mode];
p8 = p8004[compression_mode];
r = romtable[compression_mode];
for (j = 0; j < 8; j++, r++, p0 += 128) {
for (k = 0; k < 16; k++) {
if (k == 0)
bit = 1;
else if (k >= 1 && k < 3)
bit = (r[0] >> 15) & 7;
else if (k >= 3 && k < 6)
bit = (r[0] >> 12) & 7;
else if (k >= 6 && k < 10)
bit = (r[0] >> 9) & 7;
else if (k >= 10 && k < 13)
bit = (r[0] >> 6) & 7;
else if (k >= 13 && k < 15)
bit = (r[0] >> 3) & 7;
else
bit = (r[0]) & 7;
if (k == 0)
*p8++ = 8;
else
*p8++ = j - bit;
*p8++ = bit;
pw = 1 << bit;
p0[k + 0x00] = (1 * pw) + 0x80;
p0[k + 0x10] = (2 * pw) + 0x80;
p0[k + 0x20] = (3 * pw) + 0x80;
p0[k + 0x30] = (4 * pw) + 0x80;
p0[k + 0x40] = (-1 * pw) + 0x80;
p0[k + 0x50] = (-2 * pw) + 0x80;
p0[k + 0x60] = (-3 * pw) + 0x80;
p0[k + 0x70] = (-4 * pw) + 0x80;
}
}
}
}
static void fill_table_dc00_d800(struct pwc_dec23_private *pdec)
{
#define SCALEBITS 15
#define ONE_HALF (1UL << (SCALEBITS - 1))
int i;
unsigned int offset1 = ONE_HALF;
unsigned int offset2 = 0x0000;
for (i=0; i<256; i++) {
pdec->table_dc00[i] = offset1 & ~(ONE_HALF);
pdec->table_d800[i] = offset2;
offset1 += 0x7bc4;
offset2 += 0x7bc4;
}
}
int pwc_dec23_init(struct pwc_device *pwc, int type, unsigned char *cmd)
{
int flags, version, shift, i;
struct pwc_dec23_private *pdec;
if (pwc->decompress_data == NULL) {
pdec = kmalloc(sizeof(struct pwc_dec23_private), GFP_KERNEL);
if (pdec == NULL)
return -ENOMEM;
pwc->decompress_data = pdec;
}
pdec = pwc->decompress_data;
if (DEVICE_USE_CODEC3(type)) {
flags = cmd[2] & 0x18;
if (flags == 8)
pdec->nbits = 7;
else if (flags == 0x10)
pdec->nbits = 8;
else
pdec->nbits = 6;
version = cmd[2] >> 5;
build_table_color(KiaraRomTable[version][0], pdec->table_0004_pass1, pdec->table_8004_pass1);
build_table_color(KiaraRomTable[version][1], pdec->table_0004_pass2, pdec->table_8004_pass2);
} else {
flags = cmd[2] & 6;
if (flags == 2)
pdec->nbits = 7;
else if (flags == 4)
pdec->nbits = 8;
else
pdec->nbits = 6;
version = cmd[2] >> 3;
build_table_color(TimonRomTable[version][0], pdec->table_0004_pass1, pdec->table_8004_pass1);
build_table_color(TimonRomTable[version][1], pdec->table_0004_pass2, pdec->table_8004_pass2);
}
shift = 8 - pdec->nbits;
pdec->scalebits = SCALEBITS - shift;
pdec->nbitsmask = 0xFF >> shift;
fill_table_dc00_d800(pdec);
build_subblock_pattern(pdec);
build_bit_powermask_table(pdec);
#if USE_LOOKUP_TABLE_TO_CLAMP
for (i=0;i<MAX_OUTER_CROP_VALUE;i++)
pwc_crop_table[i] = 0;
for (i=0; i<256; i++)
pwc_crop_table[MAX_OUTER_CROP_VALUE+i] = i;
for (i=0; i<MAX_OUTER_CROP_VALUE; i++)
pwc_crop_table[MAX_OUTER_CROP_VALUE+256+i] = 255;
#endif
return 0;
}
static void copy_image_block_Y(const int *src, unsigned char *dst, unsigned int bytes_per_line, unsigned int scalebits)
{
#if UNROLL_LOOP_FOR_COPY
const unsigned char *cm = pwc_crop_table+MAX_OUTER_CROP_VALUE;
const int *c = src;
unsigned char *d = dst;
*d++ = cm[c[0] >> scalebits];
*d++ = cm[c[1] >> scalebits];
*d++ = cm[c[2] >> scalebits];
*d++ = cm[c[3] >> scalebits];
d = dst + bytes_per_line;
*d++ = cm[c[4] >> scalebits];
*d++ = cm[c[5] >> scalebits];
*d++ = cm[c[6] >> scalebits];
*d++ = cm[c[7] >> scalebits];
d = dst + bytes_per_line*2;
*d++ = cm[c[8] >> scalebits];
*d++ = cm[c[9] >> scalebits];
*d++ = cm[c[10] >> scalebits];
*d++ = cm[c[11] >> scalebits];
d = dst + bytes_per_line*3;
*d++ = cm[c[12] >> scalebits];
*d++ = cm[c[13] >> scalebits];
*d++ = cm[c[14] >> scalebits];
*d++ = cm[c[15] >> scalebits];
#else
int i;
const int *c = src;
unsigned char *d = dst;
for (i = 0; i < 4; i++, c++)
*d++ = CLAMP((*c) >> scalebits);
d = dst + bytes_per_line;
for (i = 0; i < 4; i++, c++)
*d++ = CLAMP((*c) >> scalebits);
d = dst + bytes_per_line*2;
for (i = 0; i < 4; i++, c++)
*d++ = CLAMP((*c) >> scalebits);
d = dst + bytes_per_line*3;
for (i = 0; i < 4; i++, c++)
*d++ = CLAMP((*c) >> scalebits);
#endif
}
static void copy_image_block_CrCb(const int *src, unsigned char *dst, unsigned int bytes_per_line, unsigned int scalebits)
{
#if UNROLL_LOOP_FOR_COPY
const unsigned char *cm = pwc_crop_table+MAX_OUTER_CROP_VALUE;
const int *c = src;
unsigned char *d = dst;
*d++ = cm[c[0] >> scalebits];
*d++ = cm[c[4] >> scalebits];
*d++ = cm[c[1] >> scalebits];
*d++ = cm[c[5] >> scalebits];
*d++ = cm[c[2] >> scalebits];
*d++ = cm[c[6] >> scalebits];
*d++ = cm[c[3] >> scalebits];
*d++ = cm[c[7] >> scalebits];
d = dst + bytes_per_line;
*d++ = cm[c[12] >> scalebits];
*d++ = cm[c[8] >> scalebits];
*d++ = cm[c[13] >> scalebits];
*d++ = cm[c[9] >> scalebits];
*d++ = cm[c[14] >> scalebits];
*d++ = cm[c[10] >> scalebits];
*d++ = cm[c[15] >> scalebits];
*d++ = cm[c[11] >> scalebits];
#else
int i;
const int *c1 = src;
const int *c2 = src + 4;
unsigned char *d = dst;
for (i = 0; i < 4; i++, c1++, c2++) {
*d++ = CLAMP((*c1) >> scalebits);
*d++ = CLAMP((*c2) >> scalebits);
}
c1 = src + 12;
d = dst + bytes_per_line;
for (i = 0; i < 4; i++, c1++, c2++) {
*d++ = CLAMP((*c1) >> scalebits);
*d++ = CLAMP((*c2) >> scalebits);
}
#endif
}
static void copy_image_block_Green(const int *src, unsigned char *dst, unsigned int bytes_per_line, unsigned int scalebits)
{
#if UNROLL_LOOP_FOR_COPY
const unsigned char *cm = pwc_crop_table+MAX_OUTER_CROP_VALUE;
unsigned char *d = dst;
const int *c = src;
d[0] = cm[c[0] >> scalebits];
d[2] = cm[c[1] >> scalebits];
d[4] = cm[c[2] >> scalebits];
d[6] = cm[c[3] >> scalebits];
d[8] = cm[c[4] >> scalebits];
d[10] = cm[c[5] >> scalebits];
d[12] = cm[c[6] >> scalebits];
d[14] = cm[c[7] >> scalebits];
d = dst + bytes_per_line;
d[0] = cm[c[8] >> scalebits];
d[2] = cm[c[9] >> scalebits];
d[4] = cm[c[10] >> scalebits];
d[6] = cm[c[11] >> scalebits];
d[8] = cm[c[12] >> scalebits];
d[10] = cm[c[13] >> scalebits];
d[12] = cm[c[14] >> scalebits];
d[14] = cm[c[15] >> scalebits];
#else
int i;
unsigned char *d;
const int *c = src;
d = dst;
for (i = 0; i < 8; i++, c++)
d[i*2] = CLAMP((*c) >> scalebits);
d = dst + bytes_per_line;
for (i = 0; i < 8; i++, c++)
d[i*2] = CLAMP((*c) >> scalebits);
#endif
}
static void copy_image_block_RedBlue(const int *src, unsigned char *dst, unsigned int bytes_per_line, unsigned int scalebits)
{
#if UNROLL_LOOP_FOR_COPY
const unsigned char *cm = pwc_crop_table+MAX_OUTER_CROP_VALUE;
unsigned char *d = dst;
const int *c = src;
d[0] = cm[c[0] >> scalebits];
d[2] = cm[c[1] >> scalebits];
d[4] = cm[c[2] >> scalebits];
d[6] = cm[c[3] >> scalebits];
d = dst + bytes_per_line;
d[1] = cm[c[4] >> scalebits];
d[3] = cm[c[5] >> scalebits];
d[5] = cm[c[6] >> scalebits];
d[7] = cm[c[7] >> scalebits];
d = dst + bytes_per_line*2;
d[0] = cm[c[8] >> scalebits];
d[2] = cm[c[9] >> scalebits];
d[4] = cm[c[10] >> scalebits];
d[6] = cm[c[11] >> scalebits];
d = dst + bytes_per_line*3;
d[1] = cm[c[12] >> scalebits];
d[3] = cm[c[13] >> scalebits];
d[5] = cm[c[14] >> scalebits];
d[7] = cm[c[15] >> scalebits];
#else
int i;
unsigned char *d;
const int *c = src;
d = dst;
for (i = 0; i < 4; i++, c++)
d[i*2] = CLAMP((*c) >> scalebits);
d = dst + bytes_per_line;
for (i = 0; i < 4; i++, c++)
d[i*2+1] = CLAMP((*c) >> scalebits);
d = dst + bytes_per_line*2;
for (i = 0; i < 4; i++, c++)
d[i*2] = CLAMP((*c) >> scalebits);
d = dst + bytes_per_line*3;
for (i = 0; i < 4; i++, c++)
d[i*2+1] = CLAMP((*c) >> scalebits);
#endif
}
static void decode_block(struct pwc_dec23_private *pdec,
const unsigned char *ptable0004,
const unsigned char *ptable8004)
{
unsigned int primary_color;
unsigned int channel_v, offset1, op;
int i;
fill_nbits(pdec, 16);
__get_nbits(pdec, pdec->nbits, primary_color);
if (look_nbits(pdec,2) == 0) {
skip_nbits(pdec, 2);
for (i = 0; i < 16; i++)
pdec->temp_colors[i] = pdec->table_dc00[primary_color];
return;
}
for (i = 0; i < 16; i++)
pdec->temp_colors[i] = pdec->table_d800[primary_color];
__get_nbits(pdec, 3, channel_v);
channel_v = ((channel_v & 1) << 2) | (channel_v & 2) | ((channel_v & 4) >> 2);
ptable0004 += (channel_v * 128);
ptable8004 += (channel_v * 32);
offset1 = 0;
do
{
unsigned int htable_idx, rows = 0;
const unsigned int *block;
fill_nbits(pdec, 16);
htable_idx = look_nbits(pdec, 6);
op = hash_table_ops[htable_idx * 4];
if (op == 2) {
skip_nbits(pdec, 2);
} else if (op == 1) {
unsigned int mask, shift;
unsigned int nbits, col1;
unsigned int yyyy;
skip_nbits(pdec, 3);
__get_nbits(pdec, 4, yyyy);
offset1 += 1 + yyyy;
offset1 &= 0x0F;
nbits = ptable8004[offset1 * 2];
__get_nbits(pdec, nbits+1, col1);
mask = pdec->table_bitpowermask[nbits][col1];
shift = ptable8004[offset1 * 2 + 1];
rows = ((mask << shift) + 0x80) & 0xFF;
block = pdec->table_subblock[rows];
for (i = 0; i < 16; i++)
pdec->temp_colors[i] += block[MulIdx[offset1][i]];
} else {
unsigned int shift;
offset1 += hash_table_ops [htable_idx * 4 + 2];
offset1 &= 0x0F;
rows = ptable0004[offset1 + hash_table_ops [htable_idx * 4 + 3]];
block = pdec->table_subblock[rows];
for (i = 0; i < 16; i++)
pdec->temp_colors[i] += block[MulIdx[offset1][i]];
shift = hash_table_ops[htable_idx * 4 + 1];
skip_nbits(pdec, shift);
}
} while (op != 2);
}
static void DecompressBand23(struct pwc_dec23_private *pdec,
const unsigned char *rawyuv,
unsigned char *planar_y,
unsigned char *planar_u,
unsigned char *planar_v,
unsigned int compressed_image_width,
unsigned int real_image_width)
{
int compression_index, nblocks;
const unsigned char *ptable0004;
const unsigned char *ptable8004;
pdec->reservoir = 0;
pdec->nbits_in_reservoir = 0;
pdec->stream = rawyuv + 1;
get_nbits(pdec, 4, compression_index);
nblocks = compressed_image_width / 4;
ptable0004 = pdec->table_0004_pass1[compression_index];
ptable8004 = pdec->table_8004_pass1[compression_index];
while (nblocks) {
decode_block(pdec, ptable0004, ptable8004);
copy_image_block_Y(pdec->temp_colors, planar_y, real_image_width, pdec->scalebits);
planar_y += 4;
nblocks--;
}
nblocks = compressed_image_width / 8;
ptable0004 = pdec->table_0004_pass2[compression_index];
ptable8004 = pdec->table_8004_pass2[compression_index];
while (nblocks) {
decode_block(pdec, ptable0004, ptable8004);
copy_image_block_CrCb(pdec->temp_colors, planar_u, real_image_width/2, pdec->scalebits);
decode_block(pdec, ptable0004, ptable8004);
copy_image_block_CrCb(pdec->temp_colors, planar_v, real_image_width/2, pdec->scalebits);
planar_v += 8;
planar_u += 8;
nblocks -= 2;
}
}
static void DecompressBandBayer(struct pwc_dec23_private *pdec,
const unsigned char *rawyuv,
unsigned char *rgbbayer,
unsigned int compressed_image_width,
unsigned int real_image_width)
{
int compression_index, nblocks;
const unsigned char *ptable0004;
const unsigned char *ptable8004;
unsigned char *dest;
pdec->reservoir = 0;
pdec->nbits_in_reservoir = 0;
pdec->stream = rawyuv + 1;
get_nbits(pdec, 4, compression_index);
nblocks = compressed_image_width / 4;
ptable0004 = pdec->table_0004_pass1[compression_index];
ptable8004 = pdec->table_8004_pass1[compression_index];
dest = rgbbayer;
while (nblocks) {
decode_block(pdec, ptable0004, ptable8004);
copy_image_block_RedBlue(pdec->temp_colors, rgbbayer, real_image_width, pdec->scalebits);
dest += 8;
nblocks--;
}
nblocks = compressed_image_width / 8;
ptable0004 = pdec->table_0004_pass2[compression_index];
ptable8004 = pdec->table_8004_pass2[compression_index];
while (nblocks) {
decode_block(pdec, ptable0004, ptable8004);
copy_image_block_Green(pdec->temp_colors, rgbbayer+1, real_image_width, pdec->scalebits);
decode_block(pdec, ptable0004, ptable8004);
copy_image_block_Green(pdec->temp_colors, rgbbayer+real_image_width, real_image_width, pdec->scalebits);
rgbbayer += 16;
nblocks -= 2;
}
}
void pwc_dec23_decompress(const struct pwc_device *pwc,
const void *src,
void *dst,
int flags)
{
int bandlines_left, stride, bytes_per_block;
bandlines_left = pwc->image.y / 4;
bytes_per_block = pwc->view.x * 4;
if (flags & PWCX_FLAG_BAYER) {
#if ENABLE_BAYER_DECODER
unsigned char *rgbout;
stride = pwc->view.x * pwc->offset.y;
rgbout = dst + stride + pwc->offset.x;
while (bandlines_left--) {
DecompressBandBayer(pwc->decompress_data,
src,
rgbout,
pwc->image.x, pwc->view.x);
src += pwc->vbandlength;
rgbout += bytes_per_block;
}
#else
memset(dst, 0, pwc->view.x * pwc->view.y);
#endif
} else {
unsigned char *pout_planar_y;
unsigned char *pout_planar_u;
unsigned char *pout_planar_v;
unsigned int plane_size;
plane_size = pwc->view.x * pwc->view.y;
stride = pwc->view.x * pwc->offset.y;
pout_planar_y = dst + stride + pwc->offset.x;
stride = (pwc->view.x * pwc->offset.y) / 4 + pwc->offset.x / 2;
pout_planar_u = dst + plane_size + stride;
pout_planar_v = dst + plane_size + plane_size / 4 + stride;
while (bandlines_left--) {
DecompressBand23(pwc->decompress_data,
src,
pout_planar_y, pout_planar_u, pout_planar_v,
pwc->image.x, pwc->view.x);
src += pwc->vbandlength;
pout_planar_y += bytes_per_block;
pout_planar_u += pwc->view.x;
pout_planar_v += pwc->view.x;
}
}
}
