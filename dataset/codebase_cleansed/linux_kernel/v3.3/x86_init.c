void __cpuinit x86_init_noop(void) { }
void __init x86_init_uint_noop(unsigned int unused) { }
void __init x86_init_pgd_noop(pgd_t *unused) { }
int __init iommu_init_noop(void) { return 0; }
void iommu_shutdown_noop(void) { }
void wallclock_init_noop(void) { }
static void default_nmi_init(void) { }
static int default_i8042_detect(void) { return 1; }
