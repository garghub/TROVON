void foo(void)
{
union paravirt_nr_irqs_max {
char ia64_native_nr_irqs[IA64_NATIVE_NR_IRQS];
#ifdef CONFIG_XEN
char xen_nr_irqs[XEN_NR_IRQS];
#endif
};
DEFINE(NR_IRQS, sizeof (union paravirt_nr_irqs_max));
}
