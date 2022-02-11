static void F_1 ( T_1 * V_1 , const T_2 V_2 )
{
T_3 V_3 = 0 , V_4 ;
T_2 V_5 = V_1 -> V_6 & 1 ;
if ( V_2 < V_7 ) {
T_1 * V_8 = F_2 ( V_1 ) ;
T_2 V_9 , V_10 ;
V_9 = V_10 = V_2 - V_11 ;
if ( V_8 ) {
T_2 V_12 = V_8 -> V_13 - V_11 ;
if ( V_12 < V_9 )
V_9 = V_12 ;
}
V_3 = ( V_14 [ V_9 ] << 16 ) |
V_15 [ V_10 ] ;
F_3 ( V_5 ? V_16 : V_17 , V_3 , 0 ) ;
F_4 ( V_5 ? V_17 : V_16 , V_3 , V_4 ) ;
if ( ( ( V_3 >> 16 ) & V_14 [ V_9 ] ) !=
V_14 [ V_9 ] ) {
V_3 &= 0x0000FFFF ;
V_3 |= V_14 [ V_9 ] << 16 ;
F_3 ( V_5 ? V_17 : V_16 , V_3 , 0 ) ;
}
F_4 ( V_5 ? V_18 : V_19 , V_3 , V_4 ) ;
F_3 ( V_5 ? V_18 : V_19 ,
V_3 | 0x80000000UL , 0 ) ;
} else {
F_4 ( V_5 ? V_18 : V_19 , V_3 , V_4 ) ;
V_3 &= 0x80000000UL ;
if ( V_2 >= V_20 && V_2 <= V_21 )
V_3 |= V_22 [ V_2 - V_20 ] ;
else if ( V_2 >= V_23 && V_2 <= V_24 )
V_3 |= V_25 [ V_2 - V_23 ] ;
else
return;
F_3 ( V_5 ? V_18 : V_19 , V_3 , 0 ) ;
}
}
static void F_5 ( T_4 * V_26 , T_1 * V_1 )
{
F_1 ( V_1 , V_1 -> V_27 ) ;
}
static void F_6 ( T_4 * V_26 , T_1 * V_1 )
{
F_1 ( V_1 , V_1 -> V_13 ) ;
}
static T_2 F_7 ( T_4 * V_26 )
{
struct V_28 * V_29 = F_8 ( V_26 -> V_29 ) ;
T_2 V_30 ;
F_9 ( V_29 , V_31 , & V_30 ) ;
return ( V_30 & 1 ) ? V_32 : V_33 ;
}
static int F_10 ( struct V_28 * V_29 , const struct V_34 * V_35 )
{
return F_11 ( V_29 , & V_36 , NULL ) ;
}
static int T_5 F_12 ( void )
{
return F_13 ( & V_37 ) ;
}
static void T_6 F_14 ( void )
{
F_15 ( & V_37 ) ;
}
