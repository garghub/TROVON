bool has_cpuflag(int flag)
{
get_cpuflags();
return test_bit(flag, cpu.flags);
}
