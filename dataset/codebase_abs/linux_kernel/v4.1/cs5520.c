static void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_5 ) ;
int V_6 = V_2 -> V_7 > 1 ? 1 : 0 ;
const T_3 V_8 = V_2 -> V_9 - V_10 ;
F_3 ( V_4 , 0x62 + V_6 ,
( V_11 [ V_8 ] . V_12 << 4 ) |
( V_11 [ V_8 ] . assert ) ) ;
F_3 ( V_4 , 0x64 + 4 * V_6 + ( V_2 -> V_7 & 1 ) ,
( V_11 [ V_8 ] . V_12 << 4 ) |
( V_11 [ V_8 ] . assert ) ) ;
F_3 ( V_4 , 0x66 + 4 * V_6 + ( V_2 -> V_7 & 1 ) ,
( V_11 [ V_8 ] . V_12 << 4 ) |
( V_11 [ V_8 ] . assert ) ) ;
}
static void F_4 ( T_1 * V_1 , T_2 * V_2 )
{
F_5 ( V_13 L_1 ) ;
V_2 -> V_9 = V_10 + 0 ;
F_1 ( V_1 , V_2 ) ;
}
static int F_6 ( struct V_3 * V_5 , const struct V_14 * V_15 )
{
const struct V_16 * V_17 = & V_18 ;
struct V_19 V_20 [ 2 ] , * V_21 [] = { NULL , NULL } ;
F_7 ( V_5 , V_17 ) ;
if ( F_8 ( V_5 ) ) {
F_5 ( V_22 L_2 , V_17 -> V_23 ) ;
return - V_24 ;
}
F_9 ( V_5 ) ;
if ( F_10 ( & V_5 -> V_5 , F_11 ( 32 ) ) ) {
F_5 ( V_22 L_3 ,
V_17 -> V_23 ) ;
return - V_24 ;
}
F_12 ( V_5 , V_17 , & V_20 [ 0 ] , & V_21 [ 0 ] ) ;
V_20 [ 0 ] . V_25 = 14 ;
V_20 [ 1 ] . V_25 = 15 ;
return F_13 ( V_17 , V_21 , 2 , NULL ) ;
}
static int T_4 F_14 ( void )
{
return F_15 ( & V_26 ) ;
}
