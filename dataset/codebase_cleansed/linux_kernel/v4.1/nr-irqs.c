void foo(void)\r\n{\r\nunion paravirt_nr_irqs_max {\r\nchar ia64_native_nr_irqs[IA64_NATIVE_NR_IRQS];\r\n};\r\nDEFINE(NR_IRQS, sizeof (union paravirt_nr_irqs_max));\r\n}
