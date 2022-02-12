unsigned long crc_drm(const char *data, size_t bytesize,
unsigned short num_crc_bits, unsigned long crc_gen, int invert)
{
unsigned long crc_holder, ones, i, msb, databit;
signed short j;
ones = (1 << num_crc_bits) - 1;
crc_holder = ones;
for (i=0; i<bytesize; i++)
for (j=7; j>=0; j--)
{
crc_holder <<= 1;
msb = crc_holder >> num_crc_bits;
databit = (data[i] >> j) & 1;
if ((msb ^ databit) != 0)
crc_holder = crc_holder ^ crc_gen;
crc_holder = crc_holder & ones;
}
if (invert)
crc_holder = crc_holder ^ ones;
return crc_holder;
}
