unsigned long __xchg_small(volatile void *ptr, unsigned long val, unsigned int size)
{
u32 old32, new32, load32, mask;
volatile u32 *ptr32;
unsigned int shift;
WARN_ON((unsigned long)ptr & (size - 1));
mask = GENMASK((size * BITS_PER_BYTE) - 1, 0);
val &= mask;
shift = (unsigned long)ptr & 0x3;
if (IS_ENABLED(CONFIG_CPU_BIG_ENDIAN))
shift ^= sizeof(u32) - size;
shift *= BITS_PER_BYTE;
mask <<= shift;
ptr32 = (volatile u32 *)((unsigned long)ptr & ~0x3);
load32 = *ptr32;
do {
old32 = load32;
new32 = (load32 & ~mask) | (val << shift);
load32 = cmpxchg(ptr32, old32, new32);
} while (load32 != old32);
return (load32 & mask) >> shift;
}
unsigned long __cmpxchg_small(volatile void *ptr, unsigned long old,
unsigned long new, unsigned int size)
{
u32 mask, old32, new32, load32;
volatile u32 *ptr32;
unsigned int shift;
u8 load;
WARN_ON((unsigned long)ptr & (size - 1));
mask = GENMASK((size * BITS_PER_BYTE) - 1, 0);
old &= mask;
new &= mask;
shift = (unsigned long)ptr & 0x3;
if (IS_ENABLED(CONFIG_CPU_BIG_ENDIAN))
shift ^= sizeof(u32) - size;
shift *= BITS_PER_BYTE;
mask <<= shift;
ptr32 = (volatile u32 *)((unsigned long)ptr & ~0x3);
load32 = *ptr32;
while (true) {
load = (load32 & mask) >> shift;
if (load != old)
return load;
old32 = (load32 & ~mask) | (old << shift);
new32 = (load32 & ~mask) | (new << shift);
load32 = cmpxchg(ptr32, old32, new32);
if (load32 == old32)
return old;
}
}
