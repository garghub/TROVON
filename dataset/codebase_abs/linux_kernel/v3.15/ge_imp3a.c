void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
struct V_2 * V_3 ;
struct V_2 * V_4 = NULL ;
unsigned long V_5 = F_2 () ;
if ( F_3 ( V_5 , L_1 ) ) {
V_1 = F_4 ( NULL , 0 ,
V_6 |
V_7 |
V_8 ,
0 , 256 , L_2 ) ;
} else {
V_1 = F_4 ( NULL , 0 ,
V_7 |
V_8 ,
0 , 256 , L_2 ) ;
}
F_5 ( V_1 == NULL ) ;
F_6 ( V_1 ) ;
F_7 (np, L_3 )
if ( F_8 ( V_3 , L_4 ) ) {
V_4 = V_3 ;
break;
}
if ( V_4 == NULL ) {
F_9 ( V_9 L_5 ) ;
return;
}
F_10 ( V_4 ) ;
F_11 ( V_4 ) ;
}
static void F_12 ( void )
{
#ifdef F_13
struct V_2 * V_3 ;
struct V_10 V_11 ;
F_7 (np, L_6 ) {
if ( F_8 ( V_3 , L_7 ) ||
F_8 ( V_3 , L_8 ) ||
F_8 ( V_3 , L_9 ) ) {
F_14 ( V_3 , 0 , & V_11 ) ;
if ( ( V_11 . V_12 & 0xfffff ) == 0x9000 )
V_13 = V_3 ;
}
}
#endif
}
static void T_1 F_15 ( void )
{
struct V_2 * V_14 ;
if ( V_15 . V_16 )
V_15 . V_16 ( L_10 , 0 ) ;
F_16 () ;
F_12 () ;
F_17 () ;
V_14 = F_18 ( NULL , NULL , L_11 ) ;
if ( V_14 ) {
V_17 = F_19 ( V_14 , 0 ) ;
if ( V_17 == NULL )
F_9 ( V_9 L_12 ) ;
F_11 ( V_14 ) ;
}
#if F_20 ( V_18 )
F_21 () ;
#endif
F_9 ( V_19 L_13 ) ;
}
static unsigned int F_22 ( void )
{
unsigned int V_20 ;
V_20 = F_23 ( V_17 ) ;
return ( V_20 >> 8 ) & 0xff ;
}
static unsigned int F_24 ( void )
{
unsigned int V_20 ;
V_20 = F_23 ( V_17 + 0x2 ) ;
return V_20 & 0xff ;
}
static unsigned int F_25 ( void )
{
unsigned int V_20 ;
V_20 = F_23 ( V_17 + 0x2 ) ;
return ( V_20 >> 8 ) & 0xff ;
}
static unsigned int F_26 ( void )
{
unsigned int V_20 ;
V_20 = F_23 ( V_17 + 0x6 ) ;
return ( V_20 & 0x0f00 ) >> 8 ;
}
static unsigned int F_27 ( void )
{
unsigned int V_20 ;
V_20 = F_23 ( V_17 + 0x6 ) ;
return V_20 & ( 1 << 12 ) ;
}
static void F_28 ( struct V_21 * V_22 )
{
F_29 ( V_22 , L_14 ) ;
F_29 ( V_22 , L_15 , F_22 () ,
( 'A' + F_24 () - 1 ) ) ;
F_29 ( V_22 , L_16 , F_25 () ) ;
F_29 ( V_22 , L_17 , F_26 () ) ;
F_29 ( V_22 , L_18 ,
F_27 () ? L_19 : L_20 ) ;
}
static int T_1 F_30 ( void )
{
unsigned long V_5 = F_2 () ;
return F_3 ( V_5 , L_21 ) ;
}
