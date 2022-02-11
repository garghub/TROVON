static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 ,
F_3 ( V_4 ) ) ;
if ( V_3 )
goto V_5;
V_2 -> V_6 . V_7 = F_4 ( V_4 [ V_8 ] . V_9 ) ;
V_2 -> V_10 [ V_11 ] . V_12 = F_4 ( V_4 [ V_13 ] . V_9 ) ;
V_2 -> V_10 [ V_11 ] . V_14 = L_1 ;
V_5:
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_4 ,
F_3 ( V_4 ) ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_16 -> V_17 = ! ! F_8 ( V_4 [ V_13 ] . V_9 ) ;
V_16 -> V_18 = ! ! F_8 ( V_4 [ V_8 ] . V_9 ) ;
V_16 -> V_19 = ! ! F_8 ( V_4 [ V_20 ] . V_9 ) ;
V_16 -> V_21 = ! ! F_8 ( V_4 [ V_22 ] . V_9 ) ;
V_16 -> V_23 = 1 ;
V_16 -> V_24 = 0 ;
}
static int
F_9 ( struct V_1 * V_2 ,
const T_1 * V_16 )
{
F_10 ( V_4 [ V_25 ] . V_9 ,
! ( V_16 -> V_26 == 33 && V_16 -> V_27 < 50 ) ) ;
F_10 ( V_4 [ V_28 ] . V_9 ,
V_16 -> V_29 & V_30 ) ;
return 0 ;
}
static int T_2 F_11 ( void )
{
int V_3 ;
if ( ! F_12 () && ! F_13 () )
return - V_31 ;
V_32 = F_14 ( L_2 , - 1 ) ;
if ( ! V_32 )
return - V_33 ;
if ( F_12 () ) {
V_4 [ V_28 ] . V_9 = V_34 ;
V_4 [ V_25 ] . V_9 = V_35 ;
V_4 [ V_20 ] . V_9 = V_36 ;
V_4 [ V_22 ] . V_9 = V_37 ;
V_4 [ V_13 ] . V_9 = V_38 ;
V_4 [ V_8 ] . V_9 = V_39 ;
} else if ( F_13 () ) {
V_4 [ V_28 ] . V_9 = V_40 ;
V_4 [ V_25 ] . V_9 = V_41 ;
V_4 [ V_20 ] . V_9 = V_42 ;
V_4 [ V_22 ] . V_9 = V_43 ;
V_4 [ V_13 ] . V_9 = V_44 ;
V_4 [ V_8 ] . V_9 = V_45 ;
}
V_3 = F_15 ( V_32 ,
& V_46 , sizeof( V_46 ) ) ;
if ( ! V_3 )
V_3 = F_16 ( V_32 ) ;
if ( V_3 )
F_17 ( V_32 ) ;
return V_3 ;
}
static void T_3 F_18 ( void )
{
F_19 ( V_32 ) ;
}
