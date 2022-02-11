static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
if ( V_3 < 0x4f08 )
F_3 ( L_1
L_2 ,
V_3 ) ;
V_2 -> V_5 . V_6 = V_7 ;
return F_4 ( V_2 , V_8 , F_5 ( V_8 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_8 , F_5 ( V_8 ) ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_11 ;
int V_12 ;
V_11 = F_2 ( V_13 ) ;
V_12 = ( V_11 ^ V_14 [ V_2 -> V_15 ] )
& V_16 ;
if ( V_12 ) {
V_14 [ V_2 -> V_15 ] = V_11 ;
if ( V_11 & V_16 )
F_9 ( V_17 ) ;
else
F_10 ( V_17 ) ;
}
V_10 -> V_18 = ! F_11 ( V_19 ) ;
V_10 -> V_20 = ! ! ( V_11 & V_21 ) ;
V_10 -> V_22 = ! ! ( V_11 & V_16 ) ;
V_10 -> V_23 = 0 ;
V_10 -> V_24 = 1 ;
V_10 -> V_25 = 0 ;
V_10 -> V_26 = 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
const T_2 * V_10 )
{
F_13 ( V_27 , V_28 |
( ( V_10 -> V_29 & V_30 ) ?
V_31 : 0 ) ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
}
static void F_15 ( struct V_1 * V_2 )
{
}
static int T_3 F_16 ( void )
{
int V_32 ;
if ( ! F_17 () )
return - V_33 ;
V_34 = F_18 ( L_3 , - 1 ) ;
if ( ! V_34 )
return - V_35 ;
V_32 = F_19 ( V_34 ,
& V_36 , sizeof( V_36 ) ) ;
if ( ! V_32 )
V_32 = F_20 ( V_34 ) ;
if ( V_32 )
F_21 ( V_34 ) ;
return V_32 ;
}
static void T_4 F_22 ( void )
{
F_23 ( V_34 ) ;
}
