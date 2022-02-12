int smp_call_function_single(int cpu, void (*func) (void *info), void *info,\r\nint wait)\r\n{\r\nWARN_ON(cpu != 0);\r\nlocal_irq_disable();\r\n(func)(info);\r\nlocal_irq_enable();\r\nreturn 0;\r\n}
