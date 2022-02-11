static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
if ( V_2 [ 0 ] . V_4 )
V_3 |= F_2 ( V_2 [ 0 ] . V_5 ) |
V_6 |
V_7 |
V_8 ;
if ( V_2 [ 1 ] . V_4 )
V_3 |= F_3 ( V_2 [ 1 ] . V_5 ) |
V_9 |
V_10 |
V_11 ;
V_12 . V_3 = V_3 ;
V_12 . V_13 = 0x80000000 - V_2 [ 0 ] . V_14 ;
V_12 . V_15 = 0x80000000 - V_2 [ 1 ] . V_14 ;
}
static void F_4 ( void * args )
{
T_1 V_16 ;
V_16 = ( ( T_1 ) V_12 . V_15 << 32 ) | V_12 . V_13 ;
F_5 ( V_16 ) ;
}
static void F_6 ( void * args )
{
F_7 ( V_12 . V_3 ) ;
}
static void F_8 ( void * args )
{
F_7 ( 0 ) ;
}
static T_2 F_9 ( int V_17 , void * V_18 )
{
unsigned int V_3 = F_10 () ;
struct V_19 * V_20 = F_11 () ;
T_3 V_21 , V_22 ;
T_1 V_23 ;
F_7 ( 0 ) ;
V_23 = F_12 () ;
V_21 = V_23 ;
V_22 = V_23 >> 32 ;
if ( V_3 & V_24 ) {
F_13 ( V_20 , 0 ) ;
V_21 = V_12 . V_13 ;
}
if ( V_3 & V_25 ) {
F_13 ( V_20 , 1 ) ;
V_22 = V_12 . V_15 ;
}
V_23 = ( ( T_1 ) V_22 << 32 ) | V_21 ;
F_5 ( V_23 ) ;
F_7 ( V_12 . V_3 ) ;
return V_26 ;
}
static int T_4 F_14 ( void )
{
return F_15 ( V_27 , F_9 ,
0 , L_1 , NULL ) ;
}
static void F_16 ( void )
{
F_17 ( V_27 , NULL ) ;
}
