static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static const T_1 V_5 [ 6 ] = {
0x0566 , 0x0433 , 0x0311 , 0x0201 , 0x0200 , 0x0100
} ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ) ;
T_1 V_10 ;
F_3 ( V_7 , 0x50 , & V_10 ) ;
V_10 &= 0xE088 ;
V_10 |= V_5 [ V_4 -> V_11 - V_12 ] ;
F_4 ( V_7 , 0x50 , V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ) ;
T_2 V_10 ;
F_6 ( V_7 , 0x5C , & V_10 ) ;
V_10 &= 0x78FFE088 ;
if ( V_4 -> V_13 >= V_14 ) {
int V_15 = V_4 -> V_13 - V_14 ;
V_10 |= 0x80000000 ;
V_10 |= ( V_15 + 2 ) << 28 ;
V_10 |= ( 2 - V_15 ) * 0x111 ;
} else {
static const T_2 V_16 [ 4 ] = {
0x0655 , 0x0200 , 0x0200 , 0x0100
} ;
V_10 |= V_16 [ V_4 -> V_13 - V_17 ] ;
}
F_7 ( V_7 , 0x5C , V_10 ) ;
}
static int F_8 ( struct V_6 * V_9 , const struct V_18 * V_19 )
{
static const struct V_20 V_21 = {
. V_22 = V_23 ,
. V_24 = V_25 ,
. V_26 = V_27 ,
. V_28 = V_29 ,
. V_30 = & V_31
} ;
const struct V_20 * V_32 [] = { & V_21 , & V_33 } ;
return F_9 ( V_9 , V_32 , & V_34 , NULL , 0 ) ;
}
