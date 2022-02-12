u16 bitrev16(u16 x)
{
return (bitrev8(x & 0xff) << 8) | bitrev8(x >> 8);
}
u32 bitrev32(u32 x)
{
return (bitrev16(x & 0xffff) << 16) | bitrev16(x >> 16);
}
