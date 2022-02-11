const char * F_1 ( void )
{
return L_1 ;
}
void T_1 F_2 ( void )
{
V_1 = 1 ;
F_3 () ;
#if 0
mips_pcibios_init();
#endif
F_4 () ;
}
static void F_3 ()
{
static struct V_2 V_3 = {
. V_4 = V_5 ,
. V_6 = NULL ,
. V_7 = V_8
} ;
F_5 ( & V_9 , & V_3 ) ;
}
static int V_5 ( struct V_2 * V_2 ,
unsigned long V_10 , void * V_11 )
{
struct V_12 V_13 ;
{
unsigned long V_14 , V_15 , V_16 ;
__asm__ __volatile__ (
".set noat\n"
LONG_S_ "$at, %[at]\n"
LONG_S_ "$2, %[v0]\n"
LONG_S_ "$3, %[v1]\n"
:
[at] "=m" (at),
[v0] "=m" (v0),
[v1] "=m" (v1)
:
: "at"
);
__asm__ __volatile__ (
".set noat\n"
"move $at, %[pt_regs]\n"
LONG_S_ "$4, " VAL(PT_R4) "($at)\n"
LONG_S_ "$5, " VAL(PT_R5) "($at)\n"
LONG_S_ "$6, " VAL(PT_R6) "($at)\n"
LONG_S_ "$7, " VAL(PT_R7) "($at)\n"
LONG_S_ "$8, " VAL(PT_R8) "($at)\n"
LONG_S_ "$9, " VAL(PT_R9) "($at)\n"
LONG_S_ "$10, " VAL(PT_R10) "($at)\n"
LONG_S_ "$11, " VAL(PT_R11) "($at)\n"
LONG_S_ "$12, " VAL(PT_R12) "($at)\n"
LONG_S_ "$13, " VAL(PT_R13) "($at)\n"
LONG_S_ "$14, " VAL(PT_R14) "($at)\n"
LONG_S_ "$15, " VAL(PT_R15) "($at)\n"
LONG_S_ "$16, " VAL(PT_R16) "($at)\n"
LONG_S_ "$17, " VAL(PT_R17) "($at)\n"
LONG_S_ "$18, " VAL(PT_R18) "($at)\n"
LONG_S_ "$19, " VAL(PT_R19) "($at)\n"
LONG_S_ "$20, " VAL(PT_R20) "($at)\n"
LONG_S_ "$21, " VAL(PT_R21) "($at)\n"
LONG_S_ "$22, " VAL(PT_R22) "($at)\n"
LONG_S_ "$23, " VAL(PT_R23) "($at)\n"
LONG_S_ "$24, " VAL(PT_R24) "($at)\n"
LONG_S_ "$25, " VAL(PT_R25) "($at)\n"
LONG_S_ "$26, " VAL(PT_R26) "($at)\n"
LONG_S_ "$27, " VAL(PT_R27) "($at)\n"
LONG_S_ "$gp, " VAL(PT_R28) "($at)\n"
LONG_S_ "$sp, " VAL(PT_R29) "($at)\n"
LONG_S_ "$fp, " VAL(PT_R30) "($at)\n"
LONG_S_ "$ra, " VAL(PT_R31) "($at)\n"
LONG_L_ "$8, %[at]\n"
LONG_S_ "$8, " VAL(PT_R1) "($at)\n"
LONG_L_ "$8, %[v0]\n"
LONG_S_ "$8, " VAL(PT_R2) "($at)\n"
LONG_L_ "$8, %[v1]\n"
LONG_S_ "$8, " VAL(PT_R3) "($at)\n"
:
:
[at] "m" (at),
[v0] "m" (v0),
[v1] "m" (v1),
[pt_regs] "r" (&my_regs)
: "at", "t0"
);
__asm__ __volatile__ (
".set noat\n"
"1:\n"
PTR_LA_ "$at, 1b\n"
LONG_S_ "$at, %[cp0_epc]\n"
:
[cp0_epc] "=m" (my_regs.cp0_epc)
:
: "at"
);
V_13 . V_17 = F_6 () ;
V_13 . V_18 = F_7 () ;
}
F_8 ( L_2
L_3 ) ;
return V_19 ;
}
static int F_9 ( char * V_20 )
{
T_2 * V_21 ;
bool V_22 ;
int V_23 ;
if ( * V_20 == '0' && * ( V_20 + 1 ) == 'x' )
V_20 += 2 ;
V_21 = V_24 ;
V_22 = true ;
for ( V_23 = ( unsigned char ) * V_20 ++ ;
isxdigit ( V_23 ) && V_21 - V_24 < V_25 ;
V_23 = ( unsigned char ) * V_20 ++ ) {
int V_26 ;
V_26 = ( isdigit ( V_23 ) ? ( V_23 - '0' ) :
( isupper ( V_23 ) ? V_23 - 'A' + 10 : V_23 - 'a' + 10 ) ) ;
if ( V_22 )
* V_21 = V_26 << 4 ;
else
* V_21 ++ |= V_26 ;
V_22 = ! V_22 ;
}
V_27 = ( V_23 == '\0' && V_21 - V_24 == V_25 ) ;
return 0 ;
}
void F_10 ( T_2 V_28 [ V_25 ] )
{
const int V_29 = 2 ;
const unsigned char V_30 = 0xc0u ;
const unsigned char V_31 = ( 1 << 1 ) ;
if ( ! V_27 ) {
F_11 ( L_4
L_5 ) ;
F_12 ( V_28 ) ;
}
else {
int V_32 ;
V_28 [ 0 ] = V_30 | V_31 ;
F_13 ( & V_28 [ 1 ] , V_29 ) ;
for ( V_32 = 1 + V_29 ; V_32 < V_25 ; V_32 ++ )
V_28 [ V_32 ] = V_24 [ V_32 ] ;
}
}
