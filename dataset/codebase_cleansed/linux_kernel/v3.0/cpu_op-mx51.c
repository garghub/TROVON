struct cpu_op *mx51_get_cpu_op(int *op)
{
*op = ARRAY_SIZE(mx51_cpu_op);
return mx51_cpu_op;
}
