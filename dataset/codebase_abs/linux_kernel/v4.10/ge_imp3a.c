void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
struct V_2 * V_3 ;
struct V_2 * V_4 = NULL ;
if ( F_2 ( L_1 ) ) {
V_1 = F_3 ( NULL , 0 ,
V_5 |
V_6 |
V_7 ,
0 , 256 , L_2 ) ;
} else {
V_1 = F_3 ( NULL , 0 ,
V_6 |
V_7 ,
0 , 256 , L_2 ) ;
}
F_4 ( V_1 == NULL ) ;
F_5 ( V_1 ) ;
F_6 (np, L_3 )
if ( F_7 ( V_3 , L_4 ) ) {
V_4 = V_3 ;
break;
}
if ( V_4 == NULL ) {
F_8 ( V_8 L_5 ) ;
return;
}
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
}
static void F_11 ( void )
{
#ifdef F_12
struct V_2 * V_3 ;
struct V_9 V_10 ;
F_6 (np, L_6 ) {
if ( F_7 ( V_3 , L_7 ) ||
F_7 ( V_3 , L_8 ) ||
F_7 ( V_3 , L_9 ) ) {
F_13 ( V_3 , 0 , & V_10 ) ;
if ( ( V_10 . V_11 & 0xfffff ) == 0x9000 )
V_12 = V_3 ;
}
}
#endif
}
static void T_1 F_14 ( void )
{
struct V_2 * V_13 ;
if ( V_14 . V_15 )
V_14 . V_15 ( L_10 , 0 ) ;
F_15 () ;
F_11 () ;
F_16 () ;
V_13 = F_17 ( NULL , NULL , L_11 ) ;
if ( V_13 ) {
V_16 = F_18 ( V_13 , 0 ) ;
if ( V_16 == NULL )
F_8 ( V_8 L_12 ) ;
F_10 ( V_13 ) ;
}
#if F_19 ( V_17 )
F_20 () ;
#endif
F_8 ( V_18 L_13 ) ;
}
static unsigned int F_21 ( void )
{
unsigned int V_19 ;
V_19 = F_22 ( V_16 ) ;
return ( V_19 >> 8 ) & 0xff ;
}
static unsigned int F_23 ( void )
{
unsigned int V_19 ;
V_19 = F_22 ( V_16 + 0x2 ) ;
return V_19 & 0xff ;
}
static unsigned int F_24 ( void )
{
unsigned int V_19 ;
V_19 = F_22 ( V_16 + 0x2 ) ;
return ( V_19 >> 8 ) & 0xff ;
}
static unsigned int F_25 ( void )
{
unsigned int V_19 ;
V_19 = F_22 ( V_16 + 0x6 ) ;
return ( V_19 & 0x0f00 ) >> 8 ;
}
static unsigned int F_26 ( void )
{
unsigned int V_19 ;
V_19 = F_22 ( V_16 + 0x6 ) ;
return V_19 & ( 1 << 12 ) ;
}
static void F_27 ( struct V_20 * V_21 )
{
F_28 ( V_21 , L_14 ) ;
F_28 ( V_21 , L_15 , F_21 () ,
( 'A' + F_23 () - 1 ) ) ;
F_28 ( V_21 , L_16 , F_24 () ) ;
F_28 ( V_21 , L_17 , F_25 () ) ;
F_28 ( V_21 , L_18 ,
F_26 () ? L_19 : L_20 ) ;
}
static int T_1 F_29 ( void )
{
return F_2 ( L_21 ) ;
}
