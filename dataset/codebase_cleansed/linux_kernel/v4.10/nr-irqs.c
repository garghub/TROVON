void foo(void)
{
union paravirt_nr_irqs_max {
char ia64_native_nr_irqs[IA64_NATIVE_NR_IRQS];
};
DEFINE(NR_IRQS, sizeof (union paravirt_nr_irqs_max));
}
