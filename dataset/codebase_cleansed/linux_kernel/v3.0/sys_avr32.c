int kernel_execve(const char *file,
const char *const *argv,
const char *const *envp)
{
register long scno asm("r8") = __NR_execve;
register long sc1 asm("r12") = (long)file;
register long sc2 asm("r11") = (long)argv;
register long sc3 asm("r10") = (long)envp;
asm volatile("scall"
: "=r"(sc1)
: "r"(scno), "0"(sc1), "r"(sc2), "r"(sc3)
: "cc", "memory");
return sc1;
}
