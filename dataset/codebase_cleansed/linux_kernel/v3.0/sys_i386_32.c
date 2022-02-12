int kernel_execve(const char *filename,
const char *const argv[],
const char *const envp[])
{
long __res;
asm volatile ("int $0x80"
: "=a" (__res)
: "0" (__NR_execve), "b" (filename), "c" (argv), "d" (envp) : "memory");
return __res;
}
