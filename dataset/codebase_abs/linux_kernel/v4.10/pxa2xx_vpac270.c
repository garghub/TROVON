static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 == 0 ) {
V_3 = F_2 ( V_5 ,
F_3 ( V_5 ) ) ;
V_2 -> V_6 [ V_7 ] . V_8 = V_9 ;
V_2 -> V_6 [ V_7 ] . V_10 = L_1 ;
V_2 -> V_6 [ V_11 ] . V_8 = V_12 ;
V_2 -> V_6 [ V_11 ] . V_10 = L_2 ;
} else {
V_3 = F_2 ( V_13 ,
F_3 ( V_13 ) ) ;
V_2 -> V_6 [ V_7 ] . V_8 = V_14 ;
V_2 -> V_6 [ V_7 ] . V_10 = L_3 ;
V_2 -> V_6 [ V_11 ] . V_8 = V_15 ;
V_2 -> V_6 [ V_11 ] . V_10 = L_4 ;
}
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 == 0 )
F_5 ( V_5 ,
F_3 ( V_5 ) ) ;
else
F_5 ( V_13 ,
F_3 ( V_13 ) ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
V_17 -> V_18 = 1 ;
V_17 -> V_19 = 0 ;
}
static int
F_7 ( struct V_1 * V_2 ,
const T_1 * V_17 )
{
if ( V_2 -> V_4 == 0 ) {
F_8 ( V_20 ,
( V_17 -> V_21 & V_22 ) ) ;
F_8 ( V_23 ,
! ( V_17 -> V_24 == 33 || V_17 -> V_24 == 50 ) ) ;
} else {
F_8 ( V_25 ,
( V_17 -> V_21 & V_22 ) ) ;
}
return 0 ;
}
static int T_2 F_9 ( void )
{
int V_3 ;
if ( ! F_10 () )
return - V_26 ;
V_27 = F_11 ( L_5 , - 1 ) ;
if ( ! V_27 )
return - V_28 ;
V_3 = F_12 ( V_27 ,
& V_29 , sizeof( V_29 ) ) ;
if ( ! V_3 )
V_3 = F_13 ( V_27 ) ;
if ( V_3 )
F_14 ( V_27 ) ;
return V_3 ;
}
static void T_3 F_15 ( void )
{
F_16 ( V_27 ) ;
}
