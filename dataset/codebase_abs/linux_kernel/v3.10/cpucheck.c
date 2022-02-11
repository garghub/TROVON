static int F_1 ( void )
{
return V_1 [ 0 ] == F_2 ( 'A' , 'u' , 't' , 'h' ) &&
V_1 [ 1 ] == F_2 ( 'e' , 'n' , 't' , 'i' ) &&
V_1 [ 2 ] == F_2 ( 'c' , 'A' , 'M' , 'D' ) ;
}
static int F_3 ( void )
{
return V_1 [ 0 ] == F_2 ( 'C' , 'e' , 'n' , 't' ) &&
V_1 [ 1 ] == F_2 ( 'a' , 'u' , 'r' , 'H' ) &&
V_1 [ 2 ] == F_2 ( 'a' , 'u' , 'l' , 's' ) ;
}
static int F_4 ( void )
{
return V_1 [ 0 ] == F_2 ( 'G' , 'e' , 'n' , 'u' ) &&
V_1 [ 1 ] == F_2 ( 'i' , 'n' , 'e' , 'T' ) &&
V_1 [ 2 ] == F_2 ( 'M' , 'x' , '8' , '6' ) ;
}
static int F_5 ( void )
{
T_1 V_2 = - 1 , V_3 = - 1 ;
T_2 V_4 ;
asm("movl %%cr0,%0" : "=r" (cr0));
if ( V_4 & ( V_5 | V_6 ) ) {
V_4 &= ~ ( V_5 | V_6 ) ;
asm volatile("movl %0,%%cr0" : : "r" (cr0));
}
asm volatile("fninit ; fnstsw %0 ; fnstcw %1"
: "+m" (fsw), "+m" (fcw));
return V_3 == 0 && ( V_2 & 0x103f ) == 0x003f ;
}
static int F_6 ( T_2 V_7 )
{
T_2 V_8 , V_9 ;
asm("pushfl ; "
"pushfl ; "
"popl %0 ; "
"movl %0,%1 ; "
"xorl %2,%1 ; "
"pushl %1 ; "
"popfl ; "
"pushfl ; "
"popl %1 ; "
"popfl"
: "=&r" (f0), "=&r" (f1)
: "ri" (mask));
return ! ! ( ( V_8 ^ V_9 ) & V_7 ) ;
}
static void F_7 ( void )
{
T_2 V_10 , V_11 ;
T_2 V_12 ;
if ( F_5 () )
F_8 ( V_13 , V_14 . V_15 ) ;
if ( F_6 ( V_16 ) ) {
asm("cpuid"
: "=a" (max_intel_level),
"=b" (cpu_vendor[0]),
"=d" (cpu_vendor[1]),
"=c" (cpu_vendor[2])
: "a" (0));
if ( V_10 >= 0x00000001 &&
V_10 <= 0x0000ffff ) {
asm("cpuid"
: "=a" (tfms),
"=c" (cpu.flags[4]),
"=d" (cpu.flags[0])
: "a" (0x00000001)
: "ebx");
V_14 . V_17 = ( V_12 >> 8 ) & 15 ;
V_14 . V_18 = ( V_12 >> 4 ) & 15 ;
if ( V_14 . V_17 >= 6 )
V_14 . V_18 += ( ( V_12 >> 16 ) & 0xf ) << 4 ;
}
asm("cpuid"
: "=a" (max_amd_level)
: "a" (0x80000000)
: "ebx", "ecx", "edx");
if ( V_11 >= 0x80000001 &&
V_11 <= 0x8000ffff ) {
T_2 V_19 = 0x80000001 ;
asm("cpuid"
: "+a" (eax),
"=c" (cpu.flags[6]),
"=d" (cpu.flags[1])
: : "ebx");
}
}
}
static int F_9 ( void )
{
T_2 V_20 ;
int V_21 ;
V_20 = 0 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
V_23 [ V_21 ] = V_24 [ V_21 ] & ~ V_14 . V_15 [ V_21 ] ;
if ( V_23 [ V_21 ] )
V_20 |= 1 << V_21 ;
}
return V_20 ;
}
int F_10 ( int * V_25 , int * V_26 , T_2 * * V_27 )
{
int V_20 ;
memset ( & V_14 . V_15 , 0 , sizeof V_14 . V_15 ) ;
V_14 . V_17 = 3 ;
if ( F_6 ( V_28 ) )
V_14 . V_17 = 4 ;
F_7 () ;
V_20 = F_9 () ;
if ( F_11 ( V_29 , V_14 . V_15 ) )
V_14 . V_17 = 64 ;
if ( V_20 == 0x01 &&
! ( V_23 [ 0 ] &
~ ( ( 1 << V_30 ) | ( 1 << V_31 ) ) ) &&
F_1 () ) {
T_2 V_32 = V_33 ;
T_2 V_19 , V_34 ;
asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
V_19 &= ~ ( 1 << 15 ) ;
asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));
F_7 () ;
V_20 = F_9 () ;
} else if ( V_20 == 0x01 &&
! ( V_23 [ 0 ] & ~ ( 1 << V_35 ) ) &&
F_3 () && V_14 . V_18 >= 6 ) {
T_2 V_32 = V_36 ;
T_2 V_19 , V_34 ;
asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
V_19 |= ( 1 << 1 ) | ( 1 << 7 ) ;
asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));
F_8 ( V_35 , V_14 . V_15 ) ;
V_20 = F_9 () ;
} else if ( V_20 == 0x01 && F_4 () ) {
T_2 V_32 = 0x80860004 ;
T_2 V_19 , V_34 ;
T_2 V_17 = 1 ;
asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
asm("wrmsr" : : "a" (~0), "d" (edx), "c" (ecx));
asm("cpuid"
: "+a" (level), "=d" (cpu.flags[0])
: : "ecx", "ebx");
asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));
V_20 = F_9 () ;
}
if ( V_27 )
* V_27 = V_20 ? V_23 : NULL ;
if ( V_25 )
* V_25 = V_14 . V_17 ;
if ( V_26 )
* V_26 = V_37 ;
return ( V_14 . V_17 < V_37 || V_20 ) ? - 1 : 0 ;
}
