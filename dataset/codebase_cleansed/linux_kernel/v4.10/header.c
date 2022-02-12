int get_cpuid(char *buffer, size_t sz)
{
const char *cpuid = "IBM/S390";
if (strlen(cpuid) + 1 > sz)
return -1;
strcpy(buffer, cpuid);
return 0;
}
