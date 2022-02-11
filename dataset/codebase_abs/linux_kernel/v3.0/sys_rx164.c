static inline void
F_1 ( unsigned long V_1 )
{
volatile unsigned int * V_2 ;
V_2 = ( void * ) ( V_3 + 0x74 ) ;
* V_2 = V_1 ;
F_2 () ;
* V_2 ;
}
static inline void
F_3 ( struct V_4 * V_5 )
{
F_1 ( V_6 |= 1UL << ( V_5 -> V_7 - 16 ) ) ;
}
static void
F_4 ( struct V_4 * V_5 )
{
F_1 ( V_6 &= ~ ( 1UL << ( V_5 -> V_7 - 16 ) ) ) ;
}
static void
F_5 ( unsigned long V_8 )
{
unsigned long V_9 ;
volatile unsigned int * V_10 ;
long V_11 ;
V_10 = ( void * ) ( V_3 + 0x84 ) ;
V_9 = * V_10 ;
while ( V_9 ) {
V_11 = F_6 ( ~ V_9 ) ;
V_9 &= V_9 - 1 ;
if ( V_11 == 20 ) {
F_7 ( V_8 ) ;
} else {
F_8 ( 16 + V_11 ) ;
}
}
}
static void T_1
F_9 ( void )
{
long V_11 ;
F_1 ( 0 ) ;
for ( V_11 = 16 ; V_11 < 40 ; ++ V_11 ) {
F_10 ( V_11 , & V_12 , V_13 ) ;
F_11 ( V_11 , V_14 ) ;
}
F_12 () ;
F_13 () ;
F_14 ( 16 + 20 , & V_15 ) ;
}
static int T_1
F_15 ( struct V_16 * V_17 , T_2 V_18 , T_2 V_19 )
{
#if 0
static char irq_tab_pass1[6][5] __initdata = {
{ 16+3, 16+3, 16+8, 16+13, 16+18},
{ 16+5, 16+5, 16+10, 16+15, 16+20},
{ 16+4, 16+4, 16+9, 16+14, 16+19},
{ -1, -1, -1, -1, -1},
{ 16+2, 16+2, 16+7, 16+12, 16+17},
{ 16+1, 16+1, 16+6, 16+11, 16+16},
};
#else
static char V_20 [ 6 ] [ 5 ] V_21 = {
{ 16 + 0 , 16 + 0 , 16 + 6 , 16 + 11 , 16 + 16 } ,
{ 16 + 1 , 16 + 1 , 16 + 7 , 16 + 12 , 16 + 17 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 16 + 2 , 16 + 2 , 16 + 8 , 16 + 13 , 16 + 18 } ,
{ 16 + 3 , 16 + 3 , 16 + 9 , 16 + 14 , 16 + 19 } ,
{ 16 + 4 , 16 + 4 , 16 + 10 , 16 + 15 , 16 + 5 } ,
} ;
#endif
const long V_22 = 5 , V_23 = 10 , V_24 = 5 ;
return V_25 ;
}
