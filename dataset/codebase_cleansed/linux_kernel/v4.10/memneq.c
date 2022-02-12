static inline unsigned long
__crypto_memneq_generic(const void *a, const void *b, size_t size)
{
unsigned long neq = 0;
#if defined(CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS)
while (size >= sizeof(unsigned long)) {
neq |= *(unsigned long *)a ^ *(unsigned long *)b;
OPTIMIZER_HIDE_VAR(neq);
a += sizeof(unsigned long);
b += sizeof(unsigned long);
size -= sizeof(unsigned long);
}
#endif
while (size > 0) {
neq |= *(unsigned char *)a ^ *(unsigned char *)b;
OPTIMIZER_HIDE_VAR(neq);
a += 1;
b += 1;
size -= 1;
}
return neq;
}
static inline unsigned long __crypto_memneq_16(const void *a, const void *b)
{
unsigned long neq = 0;
#ifdef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS
if (sizeof(unsigned long) == 8) {
neq |= *(unsigned long *)(a) ^ *(unsigned long *)(b);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned long *)(a+8) ^ *(unsigned long *)(b+8);
OPTIMIZER_HIDE_VAR(neq);
} else if (sizeof(unsigned int) == 4) {
neq |= *(unsigned int *)(a) ^ *(unsigned int *)(b);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned int *)(a+4) ^ *(unsigned int *)(b+4);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned int *)(a+8) ^ *(unsigned int *)(b+8);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned int *)(a+12) ^ *(unsigned int *)(b+12);
OPTIMIZER_HIDE_VAR(neq);
} else
#endif
{
neq |= *(unsigned char *)(a) ^ *(unsigned char *)(b);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+1) ^ *(unsigned char *)(b+1);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+2) ^ *(unsigned char *)(b+2);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+3) ^ *(unsigned char *)(b+3);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+4) ^ *(unsigned char *)(b+4);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+5) ^ *(unsigned char *)(b+5);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+6) ^ *(unsigned char *)(b+6);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+7) ^ *(unsigned char *)(b+7);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+8) ^ *(unsigned char *)(b+8);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+9) ^ *(unsigned char *)(b+9);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+10) ^ *(unsigned char *)(b+10);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+11) ^ *(unsigned char *)(b+11);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+12) ^ *(unsigned char *)(b+12);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+13) ^ *(unsigned char *)(b+13);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+14) ^ *(unsigned char *)(b+14);
OPTIMIZER_HIDE_VAR(neq);
neq |= *(unsigned char *)(a+15) ^ *(unsigned char *)(b+15);
OPTIMIZER_HIDE_VAR(neq);
}
return neq;
}
noinline unsigned long __crypto_memneq(const void *a, const void *b,
size_t size)
{
switch (size) {
case 16:
return __crypto_memneq_16(a, b);
default:
return __crypto_memneq_generic(a, b, size);
}
}
