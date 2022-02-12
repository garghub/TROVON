void __init load_mmu(void)
{
switch(sparc_cpu_model) {
case sun4c:
case sun4:
ld_mmu_sun4c();
break;
case sun4m:
case sun4d:
case sparc_leon:
ld_mmu_srmmu();
break;
default:
prom_printf("load_mmu: %d unsupported\n", (int)sparc_cpu_model);
prom_halt();
}
btfixup();
}
