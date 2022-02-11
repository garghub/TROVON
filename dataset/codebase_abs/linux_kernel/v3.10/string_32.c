char * strcpy ( char * V_1 , const char * V_2 )
{
int V_3 , V_4 , V_5 ;
asm volatile("1:\tlodsb\n\t"
"stosb\n\t"
"testb %%al,%%al\n\t"
"jne 1b"
: "=&S" (d0), "=&D" (d1), "=&a" (d2)
: "0" (src), "1" (dest) : "memory");
return V_1 ;
}
char * strncpy ( char * V_1 , const char * V_2 , T_1 V_6 )
{
int V_3 , V_4 , V_5 , V_7 ;
asm volatile("1:\tdecl %2\n\t"
"js 2f\n\t"
"lodsb\n\t"
"stosb\n\t"
"testb %%al,%%al\n\t"
"jne 1b\n\t"
"rep\n\t"
"stosb\n"
"2:"
: "=&S" (d0), "=&D" (d1), "=&c" (d2), "=&a" (d3)
: "0" (src), "1" (dest), "2" (count) : "memory");
return V_1 ;
}
char * strcat ( char * V_1 , const char * V_2 )
{
int V_3 , V_4 , V_5 , V_7 ;
asm volatile("repne\n\t"
"scasb\n\t"
"decl %1\n"
"1:\tlodsb\n\t"
"stosb\n\t"
"testb %%al,%%al\n\t"
"jne 1b"
: "=&S" (d0), "=&D" (d1), "=&a" (d2), "=&c" (d3)
: "0" (src), "1" (dest), "2" (0), "3" (0xffffffffu) : "memory");
return V_1 ;
}
char * strncat ( char * V_1 , const char * V_2 , T_1 V_6 )
{
int V_3 , V_4 , V_5 , V_7 ;
asm volatile("repne\n\t"
"scasb\n\t"
"decl %1\n\t"
"movl %8,%3\n"
"1:\tdecl %3\n\t"
"js 2f\n\t"
"lodsb\n\t"
"stosb\n\t"
"testb %%al,%%al\n\t"
"jne 1b\n"
"2:\txorl %2,%2\n\t"
"stosb"
: "=&S" (d0), "=&D" (d1), "=&a" (d2), "=&c" (d3)
: "0" (src), "1" (dest), "2" (0), "3" (0xffffffffu), "g" (count)
: "memory");
return V_1 ;
}
int strcmp ( const char * V_8 , const char * V_9 )
{
int V_3 , V_4 ;
int V_10 ;
asm volatile("1:\tlodsb\n\t"
"scasb\n\t"
"jne 2f\n\t"
"testb %%al,%%al\n\t"
"jne 1b\n\t"
"xorl %%eax,%%eax\n\t"
"jmp 3f\n"
"2:\tsbbl %%eax,%%eax\n\t"
"orb $1,%%al\n"
"3:"
: "=a" (res), "=&S" (d0), "=&D" (d1)
: "1" (cs), "2" (ct)
: "memory");
return V_10 ;
}
int strncmp ( const char * V_8 , const char * V_9 , T_1 V_6 )
{
int V_10 ;
int V_3 , V_4 , V_5 ;
asm volatile("1:\tdecl %3\n\t"
"js 2f\n\t"
"lodsb\n\t"
"scasb\n\t"
"jne 3f\n\t"
"testb %%al,%%al\n\t"
"jne 1b\n"
"2:\txorl %%eax,%%eax\n\t"
"jmp 4f\n"
"3:\tsbbl %%eax,%%eax\n\t"
"orb $1,%%al\n"
"4:"
: "=a" (res), "=&S" (d0), "=&D" (d1), "=&c" (d2)
: "1" (cs), "2" (ct), "3" (count)
: "memory");
return V_10 ;
}
char * strchr ( const char * V_11 , int V_12 )
{
int V_3 ;
char * V_10 ;
asm volatile("movb %%al,%%ah\n"
"1:\tlodsb\n\t"
"cmpb %%ah,%%al\n\t"
"je 2f\n\t"
"testb %%al,%%al\n\t"
"jne 1b\n\t"
"movl $1,%1\n"
"2:\tmovl %1,%0\n\t"
"decl %0"
: "=a" (res), "=&S" (d0)
: "1" (s), "0" (c)
: "memory");
return V_10 ;
}
T_1 strlen ( const char * V_11 )
{
int V_3 ;
T_1 V_10 ;
asm volatile("repne\n\t"
"scasb"
: "=c" (res), "=&D" (d0)
: "1" (s), "a" (0), "0" (0xffffffffu)
: "memory");
return ~ V_10 - 1 ;
}
void * memchr ( const void * V_8 , int V_12 , T_1 V_6 )
{
int V_3 ;
void * V_10 ;
if ( ! V_6 )
return NULL ;
asm volatile("repne\n\t"
"scasb\n\t"
"je 1f\n\t"
"movl $1,%0\n"
"1:\tdecl %0"
: "=D" (res), "=&c" (d0)
: "a" (c), "0" (cs), "1" (count)
: "memory");
return V_10 ;
}
void * F_1 ( void * V_13 , int V_12 , T_1 V_14 )
{
if ( ! V_14 )
return V_13 ;
asm volatile("repnz; scasb\n\t"
"jnz 1f\n\t"
"dec %%edi\n"
"1:"
: "=D" (addr), "=c" (size)
: "0" (addr), "1" (size), "a" (c)
: "memory");
return V_13 ;
}
T_1 F_2 ( const char * V_11 , T_1 V_6 )
{
int V_3 ;
int V_10 ;
asm volatile("movl %2,%0\n\t"
"jmp 2f\n"
"1:\tcmpb $0,(%0)\n\t"
"je 3f\n\t"
"incl %0\n"
"2:\tdecl %1\n\t"
"cmpl $-1,%1\n\t"
"jne 1b\n"
"3:\tsubl %2,%0"
: "=a" (res), "=&d" (d0)
: "c" (s), "1" (count)
: "memory");
return V_10 ;
}
