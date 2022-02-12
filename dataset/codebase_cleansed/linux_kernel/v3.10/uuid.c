static void __uuid_gen_common(__u8 b[16])
{
prandom_bytes(b, 16);
b[8] = (b[8] & 0x3F) | 0x80;
}
void uuid_le_gen(uuid_le *lu)
{
__uuid_gen_common(lu->b);
lu->b[7] = (lu->b[7] & 0x0F) | 0x40;
}
void uuid_be_gen(uuid_be *bu)
{
__uuid_gen_common(bu->b);
bu->b[6] = (bu->b[6] & 0x0F) | 0x40;
}
