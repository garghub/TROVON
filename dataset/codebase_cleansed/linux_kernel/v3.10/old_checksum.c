__wsum csum_partial(const void *p, int len, __wsum __sum)
{
u32 sum = (__force u32)__sum;
const u16 *buff = p;
const void *endMarker = p + len;
const void *marker = endMarker - (len % 16);
#if 0
if((int)buff & 0x3)
printk("unaligned buff %p\n", buff);
__delay(900);
#endif
BITON;
while (buff < marker) {
sum += *buff++;
sum += *buff++;
sum += *buff++;
sum += *buff++;
sum += *buff++;
sum += *buff++;
sum += *buff++;
sum += *buff++;
}
marker = endMarker - (len % 2);
while (buff < marker)
sum += *buff++;
if (endMarker > buff)
sum += *(const u8 *)buff;
BITOFF;
return (__force __wsum)sum;
}
