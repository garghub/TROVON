static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
if ( V_3 < 0x4f08 )
F_3 ( L_1
L_2 ,
V_3 ) ;
V_2 -> V_5 . V_6 = V_7 ;
V_2 -> V_8 [ V_9 ] . V_10 = V_11 ;
V_2 -> V_8 [ V_9 ] . V_12 = L_3 ;
V_2 -> V_8 [ V_13 ] . V_14 = V_15 ;
V_2 -> V_8 [ V_13 ] . V_12 = L_4 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
T_1 V_18 ;
int V_19 ;
V_18 = F_2 ( V_20 ) ;
V_19 = ( V_18 ^ V_21 [ V_2 -> V_22 ] )
& V_23 ;
if ( V_19 ) {
V_21 [ V_2 -> V_22 ] = V_18 ;
if ( V_18 & V_23 )
F_5 ( V_15 ) ;
else
F_6 ( V_15 ) ;
}
V_17 -> V_24 = ! ! ( V_18 & V_25 ) ;
V_17 -> V_26 = ! ! ( V_18 & V_23 ) ;
V_17 -> V_27 = 0 ;
V_17 -> V_28 = 1 ;
V_17 -> V_29 = 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const T_2 * V_17 )
{
F_8 ( V_30 , V_31 +
( ( V_17 -> V_32 & V_33 ) ?
V_34 : 0 ) ) ;
return 0 ;
}
static int T_3 F_9 ( void )
{
int V_35 ;
if ( ! F_10 () )
return - V_36 ;
V_37 = F_11 ( L_5 , - 1 ) ;
if ( ! V_37 )
return - V_38 ;
V_35 = F_12 ( V_37 ,
& V_39 , sizeof( V_39 ) ) ;
if ( ! V_35 )
V_35 = F_13 ( V_37 ) ;
if ( V_35 )
F_14 ( V_37 ) ;
return V_35 ;
}
static void T_4 F_15 ( void )
{
F_16 ( V_37 ) ;
}
