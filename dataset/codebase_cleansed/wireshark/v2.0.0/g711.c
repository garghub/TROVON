static int
search(
int val,
short *table,
int size)
{
int i;
for (i = 0; i < size; i++) {
if (val <= *table++)
return (i);
}
return (size);
}
unsigned char
linear2alaw(
int pcm_val)
{
int mask;
int seg;
unsigned char aval;
if (pcm_val >= 0) {
mask = 0xD5;
} else {
mask = 0x55;
pcm_val = -pcm_val - 8;
}
seg = search(pcm_val, seg_end, 8);
if (seg >= 8)
return (0x7F ^ mask);
else {
aval = seg << SEG_SHIFT;
if (seg < 2)
aval |= (pcm_val >> 4) & QUANT_MASK;
else
aval |= (pcm_val >> (seg + 3)) & QUANT_MASK;
return (aval ^ mask);
}
}
int
alaw2linear(
unsigned char a_val)
{
int t;
int seg;
a_val ^= 0x55;
t = (a_val & QUANT_MASK) << 4;
seg = ((unsigned)a_val & SEG_MASK) >> SEG_SHIFT;
switch (seg) {
case 0:
t += 8;
break;
case 1:
t += 0x108;
break;
default:
t += 0x108;
t <<= seg - 1;
}
return ((a_val & SIGN_BIT) ? t : -t);
}
unsigned char
linear2ulaw(
int pcm_val)
{
int mask;
int seg;
unsigned char uval;
if (pcm_val < 0) {
pcm_val = BIAS - pcm_val;
mask = 0x7F;
} else {
pcm_val += BIAS;
mask = 0xFF;
}
seg = search(pcm_val, seg_end, 8);
if (seg >= 8)
return (0x7F ^ mask);
else {
uval = (seg << 4) | ((pcm_val >> (seg + 3)) & 0xF);
return (uval ^ mask);
}
}
int
ulaw2linear(
unsigned char u_val)
{
int t;
u_val = ~u_val;
t = ((u_val & QUANT_MASK) << 3) + BIAS;
t <<= ((unsigned)u_val & SEG_MASK) >> SEG_SHIFT;
return ((u_val & SIGN_BIT) ? (BIAS - t) : (t - BIAS));
}
