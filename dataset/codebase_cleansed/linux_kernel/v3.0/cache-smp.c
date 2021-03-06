void smp_cache_interrupt(void)
{
unsigned long opr_mask = smp_cache_mask;
switch ((enum smp_dcache_ops)(opr_mask & SMP_DCACHE_OP_MASK)) {
case SMP_DCACHE_NOP:
break;
case SMP_DCACHE_INV:
mn10300_local_dcache_inv();
break;
case SMP_DCACHE_INV_RANGE:
mn10300_local_dcache_inv_range(smp_cache_start, smp_cache_end);
break;
case SMP_DCACHE_FLUSH:
mn10300_local_dcache_flush();
break;
case SMP_DCACHE_FLUSH_RANGE:
mn10300_local_dcache_flush_range(smp_cache_start,
smp_cache_end);
break;
case SMP_DCACHE_FLUSH_INV:
mn10300_local_dcache_flush_inv();
break;
case SMP_DCACHE_FLUSH_INV_RANGE:
mn10300_local_dcache_flush_inv_range(smp_cache_start,
smp_cache_end);
break;
}
switch ((enum smp_icache_ops)(opr_mask & SMP_ICACHE_OP_MASK)) {
case SMP_ICACHE_NOP:
break;
case SMP_ICACHE_INV:
mn10300_local_icache_inv();
break;
case SMP_ICACHE_INV_RANGE:
mn10300_local_icache_inv_range(smp_cache_start, smp_cache_end);
break;
}
cpumask_clear_cpu(smp_processor_id(), &smp_cache_ipi_map);
}
void smp_cache_call(unsigned long opr_mask,
unsigned long start, unsigned long end)
{
smp_cache_mask = opr_mask;
smp_cache_start = start;
smp_cache_end = end;
cpumask_copy(&smp_cache_ipi_map, cpu_online_mask);
cpumask_clear_cpu(smp_processor_id(), &smp_cache_ipi_map);
send_IPI_allbutself(FLUSH_CACHE_IPI);
while (!cpumask_empty(&smp_cache_ipi_map))
mb();
}
