static u32 altera_bits_req(u32 n)
{
u32 result = SHORT_BITS;
if (n == 0)
result = 1;
else {
while ((n & (1 << (SHORT_BITS - 1))) == 0) {
n <<= 1;
--result;
}
}
return result;
}
static u32 altera_read_packed(u8 *buffer, u32 bits, u32 *bits_avail,
u32 *in_index)
{
u32 result = 0;
u32 shift = 0;
u32 databyte = 0;
while (bits > 0) {
databyte = buffer[*in_index];
result |= (((databyte >> (CHAR_BITS - *bits_avail))
& (0xff >> (CHAR_BITS - *bits_avail))) << shift);
if (bits <= *bits_avail) {
result &= (0xffff >> (SHORT_BITS - (bits + shift)));
*bits_avail -= bits;
bits = 0;
} else {
++(*in_index);
shift += *bits_avail;
bits -= *bits_avail;
*bits_avail = CHAR_BITS;
}
}
return result;
}
u32 altera_shrink(u8 *in, u32 in_length, u8 *out, u32 out_length, s32 version)
{
u32 i, j, data_length = 0L;
u32 offset, length;
u32 match_data_length = MATCH_DATA_LENGTH;
u32 bits_avail = CHAR_BITS;
u32 in_index = 0L;
if (version > 0)
--match_data_length;
for (i = 0; i < out_length; ++i)
out[i] = 0;
for (i = 0; i < sizeof(in_length); ++i) {
data_length = data_length | (
altera_read_packed(in,
CHAR_BITS,
&bits_avail,
&in_index) << (i * CHAR_BITS));
}
if (data_length > out_length) {
data_length = 0L;
return data_length;
}
i = 0;
while (i < data_length) {
if (altera_read_packed(in, 1, &bits_avail,
&in_index) == 0) {
for (j = 0; j < DATA_BLOB_LENGTH; ++j) {
if (i < data_length) {
out[i] = (u8)altera_read_packed(in,
CHAR_BITS,
&bits_avail,
&in_index);
i++;
}
}
} else {
offset = altera_read_packed(in, altera_bits_req((s16)
(i > match_data_length ?
match_data_length : i)),
&bits_avail,
&in_index);
length = altera_read_packed(in, CHAR_BITS,
&bits_avail,
&in_index);
for (j = 0; j < length; ++j) {
if (i < data_length) {
out[i] = out[i - offset];
i++;
}
}
}
}
return data_length;
}
