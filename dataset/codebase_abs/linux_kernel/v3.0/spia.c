static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_7 & V_8 ) {
void T_1 * V_9 = V_10 + V_11 ;
unsigned char V_12 ;
V_12 = ( V_7 & V_13 ) << 2 ;
V_12 |= ( V_7 & V_14 | V_15 ) >> 1 ;
F_2 ( ( F_3 ( V_9 ) & ~ 0x7 ) | V_12 , V_9 ) ;
}
if ( V_3 != V_16 )
F_2 ( V_3 , V_5 -> V_17 ) ;
}
static int T_2 F_4 ( void )
{
struct V_4 * V_18 ;
V_19 = F_5 ( sizeof( struct V_1 ) + sizeof( struct V_4 ) , V_20 ) ;
if ( ! V_19 ) {
F_6 ( L_1 ) ;
return - V_21 ;
}
V_18 = (struct V_4 * ) ( & V_19 [ 1 ] ) ;
memset ( V_19 , 0 , sizeof( struct V_1 ) ) ;
memset ( V_18 , 0 , sizeof( struct V_4 ) ) ;
V_19 -> V_6 = V_18 ;
V_19 -> V_22 = V_23 ;
( * ( volatile unsigned char * ) ( V_10 + V_24 ) ) = 0x07 ;
V_18 -> V_25 = ( void T_1 * ) V_26 ;
V_18 -> V_17 = ( void T_1 * ) V_26 ;
V_18 -> V_27 = F_1 ;
V_18 -> V_28 = 15 ;
if ( F_7 ( V_19 , 1 ) ) {
F_8 ( V_19 ) ;
return - V_29 ;
}
F_9 ( V_19 , V_30 , V_31 ) ;
return 0 ;
}
static void T_3 F_10 ( void )
{
F_11 ( V_19 ) ;
F_8 ( V_19 ) ;
}
