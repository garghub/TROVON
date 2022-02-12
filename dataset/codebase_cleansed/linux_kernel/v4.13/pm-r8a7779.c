static void __init r8a7779_sysc_init(void)
{
rcar_sysc_init(0xffd85000, 0x0131000e);
}
static inline void r8a7779_sysc_init(void) {}
void __init r8a7779_pm_init(void)
{
static int once;
if (!once++)
r8a7779_sysc_init();
}
