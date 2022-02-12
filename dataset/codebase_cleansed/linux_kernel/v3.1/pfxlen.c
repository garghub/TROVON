u32
ip_set_range_to_cidr(u32 from, u32 to, u8 *cidr)
{
u32 last;
u8 i;
for (i = 1; i < 32; i++) {
if ((from & ip_set_hostmask(i)) != from)
continue;
last = from | ~ip_set_hostmask(i);
if (!after(last, to)) {
*cidr = i;
return last;
}
}
*cidr = 32;
return from;
}
