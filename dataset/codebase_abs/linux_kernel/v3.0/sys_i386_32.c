int F_1 ( const char * V_1 ,
const char * const V_2 [] ,
const char * const V_3 [] )
{
long V_4 ;
asm volatile ("int $0x80"
: "=a" (__res)
: "0" (__NR_execve), "b" (filename), "c" (argv), "d" (envp) : "memory");
return V_4 ;
}
