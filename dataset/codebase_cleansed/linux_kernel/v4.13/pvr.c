int cpu_has_pvr(void)
{
unsigned long flags;
unsigned pvr0;
local_save_flags(flags);
if (!(flags & PVR_MSR_BIT))
return 0;
get_single_pvr(0, pvr0);
pr_debug("%s: pvr0 is 0x%08x\n", __func__, pvr0);
if (pvr0 & PVR0_PVR_FULL_MASK)
return 1;
return 2;
}
void get_pvr(struct pvr_s *p)
{
get_single_pvr(0, p->pvr[0]);
get_single_pvr(1, p->pvr[1]);
get_single_pvr(2, p->pvr[2]);
get_single_pvr(3, p->pvr[3]);
get_single_pvr(4, p->pvr[4]);
get_single_pvr(5, p->pvr[5]);
get_single_pvr(6, p->pvr[6]);
get_single_pvr(7, p->pvr[7]);
get_single_pvr(8, p->pvr[8]);
get_single_pvr(9, p->pvr[9]);
get_single_pvr(10, p->pvr[10]);
get_single_pvr(11, p->pvr[11]);
}
