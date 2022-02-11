static void F_1 ( void * V_1 )
{
F_2 ( 0 ) ;
F_3 ( 0 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
unsigned int V_4 = 0 ;
V_5 . V_6 = 0 ;
V_5 . V_7 = 0 ;
if ( V_3 [ 0 ] . V_8 ) {
V_4 |= F_5 ( 0 , V_3 [ 0 ] . V_9 ) ;
V_5 . V_6 = 0x80000000ULL - V_3 [ 0 ] . V_10 ;
}
if ( V_3 [ 1 ] . V_8 ) {
V_4 |= F_5 ( 1 , V_3 [ 1 ] . V_9 ) ;
V_5 . V_7 = 0x80000000ULL - V_3 [ 1 ] . V_10 ;
}
if ( V_3 [ 0 ] . V_8 || V_3 [ 1 ] . V_8 ) {
V_4 |= V_11 | V_12 ;
if ( V_3 [ 0 ] . V_13 || V_3 [ 1 ] . V_13 )
V_4 |= V_14 ;
if ( V_3 [ 0 ] . V_15 || V_3 [ 1 ] . V_15 )
V_4 |= V_16 ;
}
V_5 . V_4 = V_4 ;
V_5 . V_17 = V_3 [ 0 ] . V_8 ;
V_5 . V_18 = V_3 [ 1 ] . V_8 ;
}
static void F_6 ( void * args )
{
F_3 ( ( V_5 . V_7 << 32 ) | V_5 . V_6 ) ;
}
static void F_7 ( void * args )
{
if ( V_5 . V_17 || V_5 . V_18 )
F_2 ( V_5 . V_4 ) ;
}
static void F_8 ( void * args )
{
F_2 ( 0 ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
}
static T_1 F_9 ( int V_19 , void * V_20 )
{
T_2 V_21 , V_22 , V_23 ;
struct V_24 * V_25 = F_10 () ;
int V_8 ;
V_8 = F_11 () & V_12 ;
if ( ! V_8 )
return V_26 ;
V_8 = V_5 . V_17 | V_5 . V_18 ;
if ( ! V_8 )
return V_26 ;
V_21 = F_12 () ;
V_22 = V_21 & 0xffffffff ;
V_23 = V_21 >> 32 ;
if ( V_22 & V_27 ) {
if ( V_5 . V_17 )
F_13 ( V_25 , 0 ) ;
V_22 = V_5 . V_6 ;
}
if ( V_23 & V_27 ) {
if ( V_5 . V_18 )
F_13 ( V_25 , 1 ) ;
V_23 = V_5 . V_7 ;
}
F_3 ( ( V_23 << 32 ) | V_22 ) ;
return V_28 ;
}
static int T_3 F_14 ( void )
{
return F_15 ( V_29 , F_9 ,
V_30 , L_1 , V_31 ) ;
}
static void F_16 ( void )
{
F_1 ( NULL ) ;
F_17 ( V_29 , V_31 ) ;
}
