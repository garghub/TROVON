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
return V_1 [ 0 ] == F_2 ( 'G' , 'e' , 'n' , 'u' ) &&
V_1 [ 1 ] == F_2 ( 'i' , 'n' , 'e' , 'I' ) &&
V_1 [ 2 ] == F_2 ( 'n' , 't' , 'e' , 'l' ) ;
}
static int F_6 ( void )
{
T_1 V_2 ;
int V_3 ;
V_2 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_5 [ V_3 ] = V_6 [ V_3 ] & ~ V_7 . V_8 [ V_3 ] ;
if ( V_5 [ V_3 ] )
V_2 |= 1 << V_3 ;
}
return V_2 ;
}
int F_7 ( int * V_9 , int * V_10 , T_1 * * V_11 )
{
int V_2 ;
memset ( & V_7 . V_8 , 0 , sizeof V_7 . V_8 ) ;
V_7 . V_12 = 3 ;
if ( F_8 ( V_13 ) )
V_7 . V_12 = 4 ;
F_9 () ;
V_2 = F_6 () ;
if ( F_10 ( V_14 , V_7 . V_8 ) )
V_7 . V_12 = 64 ;
if ( V_2 == 0x01 &&
! ( V_5 [ 0 ] &
~ ( ( 1 << V_15 ) | ( 1 << V_16 ) ) ) &&
F_1 () ) {
T_1 V_17 = V_18 ;
T_1 V_19 , V_20 ;
asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
V_19 &= ~ ( 1 << 15 ) ;
asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));
F_9 () ;
V_2 = F_6 () ;
} else if ( V_2 == 0x01 &&
! ( V_5 [ 0 ] & ~ ( 1 << V_21 ) ) &&
F_3 () && V_7 . V_22 >= 6 ) {
T_1 V_17 = V_23 ;
T_1 V_19 , V_20 ;
asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
V_19 |= ( 1 << 1 ) | ( 1 << 7 ) ;
asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));
F_11 ( V_21 , V_7 . V_8 ) ;
V_2 = F_6 () ;
} else if ( V_2 == 0x01 && F_4 () ) {
T_1 V_17 = 0x80860004 ;
T_1 V_19 , V_20 ;
T_1 V_12 = 1 ;
asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
asm("wrmsr" : : "a" (~0), "d" (edx), "c" (ecx));
asm("cpuid"
: "+a" (level), "=d" (cpu.flags[0])
: : "ecx", "ebx");
asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));
V_2 = F_6 () ;
} else if ( V_2 == 0x01 &&
! ( V_5 [ 0 ] & ~ ( 1 << V_24 ) ) &&
F_5 () && V_7 . V_12 == 6 &&
( V_7 . V_22 == 9 || V_7 . V_22 == 13 ) ) {
if ( F_12 ( L_1 ) ) {
puts ( L_2 ) ;
F_11 ( V_24 , V_7 . V_8 ) ;
V_2 = F_6 () ;
}
else {
puts ( L_3 ) ;
}
}
if ( ! V_2 )
V_2 = F_13 () ;
if ( V_11 )
* V_11 = V_2 ? V_5 : NULL ;
if ( V_9 )
* V_9 = V_7 . V_12 ;
if ( V_10 )
* V_10 = V_25 ;
return ( V_7 . V_12 < V_25 || V_2 ) ? - 1 : 0 ;
}
int F_13 ( void )
{
if ( ! F_5 () ||
V_7 . V_26 != 6 ||
V_7 . V_22 != V_27 )
return 0 ;
if ( F_14 ( V_28 ) || F_14 ( V_29 ) )
return 0 ;
puts ( L_4
L_5
L_6 ) ;
return - 1 ;
}
