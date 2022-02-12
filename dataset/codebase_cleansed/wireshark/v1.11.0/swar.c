int swar_count_bits(const guint32 bitmask)
{
int bits = bitmask;
bits = bits - ((bits >> 1) & 0x55555555);
bits = (bits & 0x33333333) + ((bits >> 2) & 0x33333333);
bits = (bits + (bits >> 4)) & 0x0F0F0F0F;
return (bits * 0x01010101) >> 24;
}
