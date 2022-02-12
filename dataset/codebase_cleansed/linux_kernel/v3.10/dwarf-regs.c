const char *get_arch_regstr(unsigned int n)
{
return (n >= NUM_GPRS) ? NULL : gpr_names[n];
}
