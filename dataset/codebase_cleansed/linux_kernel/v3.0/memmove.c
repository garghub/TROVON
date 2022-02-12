void *memmove(void *v_dst, const void *v_src, __kernel_size_t c)
{
const char *src = v_src;
char *dst = v_dst;
if (!c)
return v_dst;
if (v_dst <= v_src)
return memcpy(v_dst, v_src, c);
src += c;
dst += c;
while (c--)
*--dst = *--src;
return v_dst;
}
void *memmove(void *v_dst, const void *v_src, __kernel_size_t c)
{
const char *src = v_src;
char *dst = v_dst;
const uint32_t *i_src;
uint32_t *i_dst;
if (!c)
return v_dst;
if (v_dst <= v_src)
return memcpy(v_dst, v_src, c);
dst += c;
src += c;
if (c >= 4) {
unsigned value, buf_hold;
switch ((unsigned long)dst & 3) {
case 3:
*--dst = *--src;
--c;
case 2:
*--dst = *--src;
--c;
case 1:
*--dst = *--src;
--c;
}
i_dst = (void *)dst;
switch ((unsigned long)src & 3) {
case 0x0:
i_src = (const void *)src;
for (; c >= 4; c -= 4)
*--i_dst = *--i_src;
src = (const void *)i_src;
break;
case 0x1:
i_src = (const void *) (((unsigned)src + 4) & ~3);
#ifndef __MICROBLAZEEL__
buf_hold = *--i_src >> 24;
for (; c >= 4; c -= 4) {
value = *--i_src;
*--i_dst = buf_hold << 8 | value;
buf_hold = value >> 24;
}
#else
buf_hold = (*--i_src & 0xFF) << 24;
for (; c >= 4; c -= 4) {
value = *--i_src;
*--i_dst = buf_hold | ((value & 0xFFFFFF00)>>8);
buf_hold = (value & 0xFF) << 24;
}
#endif
src = (const void *)i_src;
src += 1;
break;
case 0x2:
i_src = (const void *) (((unsigned)src + 4) & ~3);
#ifndef __MICROBLAZEEL__
buf_hold = *--i_src >> 16;
for (; c >= 4; c -= 4) {
value = *--i_src;
*--i_dst = buf_hold << 16 | value;
buf_hold = value >> 16;
}
#else
buf_hold = (*--i_src & 0xFFFF) << 16;
for (; c >= 4; c -= 4) {
value = *--i_src;
*--i_dst = buf_hold | ((value & 0xFFFF0000)>>16);
buf_hold = (value & 0xFFFF) << 16;
}
#endif
src = (const void *)i_src;
src += 2;
break;
case 0x3:
i_src = (const void *) (((unsigned)src + 4) & ~3);
#ifndef __MICROBLAZEEL__
buf_hold = *--i_src >> 8;
for (; c >= 4; c -= 4) {
value = *--i_src;
*--i_dst = buf_hold << 24 | value;
buf_hold = value >> 8;
}
#else
buf_hold = (*--i_src & 0xFFFFFF) << 8;
for (; c >= 4; c -= 4) {
value = *--i_src;
*--i_dst = buf_hold | ((value & 0xFF000000)>> 24);
buf_hold = (value & 0xFFFFFF) << 8;
}
#endif
src = (const void *)i_src;
src += 3;
break;
}
dst = (void *)i_dst;
}
switch (c) {
case 4:
*--dst = *--src;
case 3:
*--dst = *--src;
case 2:
*--dst = *--src;
case 1:
*--dst = *--src;
}
return v_dst;
}
