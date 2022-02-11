static void T_1 F_1 ( void )
{
extern unsigned int V_1 [] ;
extern unsigned int V_2 [] ;
V_1 [ 0 ] = ( V_1 [ 0 ] & 0xffff0000 ) |
V_3 ;
F_2 ( ( unsigned long ) & V_1 [ 0 ] ,
( unsigned long ) & V_1 [ 1 ] ) ;
V_2 [ 0 ] = ( V_2 [ 0 ] & 0xffff0000 ) |
V_3 ;
F_2 ( ( unsigned long ) & V_2 [ 0 ] ,
( unsigned long ) & V_2 [ 1 ] ) ;
}
static void T_2 F_3 ( unsigned int V_4 , unsigned int V_5 )
{
unsigned int V_6 = V_3 -- ;
F_1 () ;
F_4 ( V_7 , 0 ) ;
__asm__ __volatile__(
"tlbwe %2,%3,%4\n"
"tlbwe %1,%3,%5\n"
"tlbwe %0,%3,%6\n"
:
#ifdef F_5
: "r" (PPC47x_TLB2_S_RWX),
#else
: "r" (PPC44x_TLB_SW | PPC44x_TLB_SR | PPC44x_TLB_SX | PPC44x_TLB_G),
#endif
"r" (phys),
"r" (virt | PPC44x_TLB_VALID | PPC44x_TLB_256M),
"r" (entry),
"i" (PPC44x_TLB_PAGEID),
"i" (PPC44x_TLB_XLAT),
"i" (PPC44x_TLB_ATTRIB));
}
static int T_2 F_6 ( void )
{
unsigned int V_8 = F_7 ( V_9 ) ;
unsigned int V_10 = F_7 ( V_11 ) ;
if ( ! ( V_8 & V_12 ) )
return 0 ;
if ( ! ( V_8 & V_13 ) )
return 1 ;
if ( ! ( V_8 & V_14 ) )
return 2 ;
if ( ! ( V_10 & V_15 ) )
return 3 ;
if ( ! ( V_10 & V_16 ) )
return 4 ;
if ( ! ( V_10 & V_17 ) )
return 5 ;
return - 1 ;
}
static void T_2 F_8 ( void )
{
unsigned int V_8 = F_7 ( V_9 ) ;
unsigned int V_10 = F_7 ( V_11 ) ;
if ( V_8 & V_12 )
F_9 ( ( V_8 >> V_18 ) & 0xff ,
V_19 ) ;
if ( V_8 & V_13 )
F_9 ( ( V_8 >> V_20 ) & 0xff ,
V_19 ) ;
if ( V_8 & V_14 )
F_9 ( ( V_8 >> V_21 ) & 0xff ,
V_19 ) ;
if ( V_10 & V_15 )
F_9 ( ( V_10 >> V_22 ) & 0xff ,
V_19 ) ;
if ( V_10 & V_16 )
F_9 ( ( V_10 >> V_23 ) & 0xff ,
V_19 ) ;
if ( V_10 & V_17 )
F_9 ( ( V_10 >> V_24 ) & 0xff ,
V_19 ) ;
}
static void T_1 F_10 ( unsigned int V_4 , unsigned int V_5 )
{
unsigned int V_25 ;
int V_26 ;
V_25 = 0x88000000 ;
V_26 = F_6 () ;
F_11 ( V_26 < 0 ) ;
V_25 |= V_26 << 24 ;
F_12 ( L_1 ,
V_4 , V_5 , V_26 ) ;
F_4 ( V_7 , 0 ) ;
__asm__ __volatile__(
"tlbwe %2,%3,0\n"
"tlbwe %1,%3,1\n"
"tlbwe %0,%3,2\n"
:
: "r" (PPC47x_TLB2_SW | PPC47x_TLB2_SR |
PPC47x_TLB2_SX
#ifdef F_13
| PPC47x_TLB2_M
#endif
),
"r" (phys),
"r" (virt | PPC47x_TLB0_VALID | PPC47x_TLB0_256M),
"r" (rA));
}
void T_2 F_14 ( void )
{
F_1 () ;
F_15 () ;
}
unsigned long T_2 F_16 ( unsigned long V_27 )
{
unsigned long V_28 ;
for ( V_28 = V_29 ; V_28 < V_30 ;
V_28 += V_29 ) {
if ( F_17 ( V_31 ) )
F_10 ( V_28 + V_32 , V_28 ) ;
else
F_3 ( V_28 + V_32 , V_28 ) ;
}
if ( F_17 ( V_31 ) ) {
F_8 () ;
#ifdef F_18
{
int V_33 ;
F_19 ( V_34 L_2 ) ;
for ( V_33 = 0 ; V_33 < 255 ; V_33 ++ ) {
if ( F_20 ( V_33 , V_19 ) )
F_19 ( L_3 , V_33 ) ;
}
F_19 ( L_4 ) ;
}
#endif
}
return V_35 ;
}
void F_21 ( T_3 V_36 ,
T_3 V_37 )
{
F_11 ( V_36 != 0 ) ;
F_22 ( F_23 ( V_38 , V_37 , V_29 ) ) ;
}
void T_1 F_24 ( int V_39 )
{
unsigned long V_28 ;
for ( V_28 = V_29 ; V_28 < V_30 ;
V_28 += V_29 ) {
if ( F_17 ( V_31 ) )
F_10 ( V_28 + V_32 , V_28 ) ;
else
F_3 ( V_28 + V_32 , V_28 ) ;
}
}
