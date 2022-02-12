struct cpu_op *mx51_get_cpu_op(int *op)\r\n{\r\n*op = ARRAY_SIZE(mx51_cpu_op);\r\nreturn mx51_cpu_op;\r\n}
