uint8_t crc4(uint8_t c, uint64_t x, int bits)
{
int i;
x &= (1ull << bits) - 1;
bits = (bits + 3) & ~0x3;
for (i = bits - 4; i >= 0; i -= 4)
c = crc4_tab[c ^ ((x >> i) & 0xf)];
return c;
}
