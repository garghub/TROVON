unsigned long bfin_get_addr_from_rp(u32 *ptr,
u32 relval,
u32 flags,
u32 *persistent)
{
unsigned short *usptr = (unsigned short *)ptr;
int type = (relval >> 26) & 7;
u32 val;
switch (type) {
case FLAT_BFIN_RELOC_TYPE_16_BIT:
case FLAT_BFIN_RELOC_TYPE_16H_BIT:
usptr = (unsigned short *)ptr;
pr_debug("*usptr = %x", get_unaligned(usptr));
val = get_unaligned(usptr);
val += *persistent;
break;
case FLAT_BFIN_RELOC_TYPE_32_BIT:
pr_debug("*ptr = %x", get_unaligned(ptr));
val = get_unaligned(ptr);
break;
default:
pr_debug("BINFMT_FLAT: Unknown relocation type %x\n", type);
return 0;
}
if (relval & (1 << 29))
return val + current->mm->context.end_brk;
if ((flags & FLAT_FLAG_GOTPIC) == 0)
val = htonl(val);
return val;
}
void bfin_put_addr_at_rp(u32 *ptr, u32 addr, u32 relval)
{
unsigned short *usptr = (unsigned short *)ptr;
int type = (relval >> 26) & 7;
switch (type) {
case FLAT_BFIN_RELOC_TYPE_16_BIT:
put_unaligned(addr, usptr);
pr_debug("new value %x at %p", get_unaligned(usptr), usptr);
break;
case FLAT_BFIN_RELOC_TYPE_16H_BIT:
put_unaligned(addr >> 16, usptr);
pr_debug("new value %x", get_unaligned(usptr));
break;
case FLAT_BFIN_RELOC_TYPE_32_BIT:
put_unaligned(addr, ptr);
pr_debug("new ptr =%x", get_unaligned(ptr));
break;
}
}
