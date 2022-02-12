asmlinkage __visible void xen_maybe_preempt_hcall(void)
{
if (unlikely(__this_cpu_read(xen_in_preemptible_hcall)
&& need_resched())) {
__this_cpu_write(xen_in_preemptible_hcall, false);
_cond_resched();
__this_cpu_write(xen_in_preemptible_hcall, true);
}
}
