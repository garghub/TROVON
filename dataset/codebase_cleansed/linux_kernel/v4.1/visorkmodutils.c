static __init uint32_t visorutil_spar_detect(void)
{
unsigned int eax, ebx, ecx, edx;
if (cpu_has_hypervisor) {
cpuid(UNISYS_SPAR_LEAF_ID, &eax, &ebx, &ecx, &edx);
return (ebx == UNISYS_SPAR_ID_EBX) &&
(ecx == UNISYS_SPAR_ID_ECX) &&
(edx == UNISYS_SPAR_ID_EDX);
} else {
return 0;
}
}
static __init int visorutil_mod_init(void)
{
if (visorutil_spar_detect()) {
unisys_spar_platform = TRUE;
return 0;
} else {
return -ENODEV;
}
}
static __exit void
visorutil_mod_exit(void)
{
}
