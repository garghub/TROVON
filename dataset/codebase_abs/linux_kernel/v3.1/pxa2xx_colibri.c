static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 ,
F_3 ( V_4 ) ) ;
if ( V_3 )
goto V_5;
V_6 [ 0 ] . V_7 = F_4 ( V_4 [ V_8 ] . V_9 ) ;
V_2 -> V_10 . V_11 = F_4 ( V_4 [ V_12 ] . V_9 ) ;
V_3 = F_5 ( V_2 , V_6 ,
F_3 ( V_6 ) ) ;
if ( V_3 )
goto V_13;
return V_3 ;
V_13:
F_6 ( V_4 ,
F_3 ( V_4 ) ) ;
V_5:
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_6 ( V_4 ,
F_3 ( V_4 ) ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
V_15 -> V_16 = ! ! F_9 ( V_4 [ V_8 ] . V_9 ) ;
V_15 -> V_17 = ! ! F_9 ( V_4 [ V_12 ] . V_9 ) ;
V_15 -> V_18 = ! ! F_9 ( V_4 [ V_19 ] . V_9 ) ;
V_15 -> V_20 = ! ! F_9 ( V_4 [ V_21 ] . V_9 ) ;
V_15 -> V_22 = 0 ;
V_15 -> V_23 = 1 ;
V_15 -> V_24 = 0 ;
}
static int
F_10 ( struct V_1 * V_2 ,
const T_1 * V_15 )
{
F_11 ( V_4 [ V_25 ] . V_9 ,
! ( V_15 -> V_26 == 33 && V_15 -> V_27 < 50 ) ) ;
F_11 ( V_4 [ V_28 ] . V_9 ,
V_15 -> V_29 & V_30 ) ;
return 0 ;
}
static int T_2 F_12 ( void )
{
int V_3 ;
if ( ! F_13 () && ! F_14 () )
return - V_31 ;
V_32 = F_15 ( L_1 , - 1 ) ;
if ( ! V_32 )
return - V_33 ;
if ( F_13 () ) {
V_4 [ V_28 ] . V_9 = V_34 ;
V_4 [ V_25 ] . V_9 = V_35 ;
V_4 [ V_19 ] . V_9 = V_36 ;
V_4 [ V_21 ] . V_9 = V_37 ;
V_4 [ V_8 ] . V_9 = V_38 ;
V_4 [ V_12 ] . V_9 = V_39 ;
} else if ( F_14 () ) {
V_4 [ V_28 ] . V_9 = V_40 ;
V_4 [ V_25 ] . V_9 = V_41 ;
V_4 [ V_19 ] . V_9 = V_42 ;
V_4 [ V_21 ] . V_9 = V_43 ;
V_4 [ V_8 ] . V_9 = V_44 ;
V_4 [ V_12 ] . V_9 = V_45 ;
}
V_3 = F_16 ( V_32 ,
& V_46 , sizeof( V_46 ) ) ;
if ( ! V_3 )
V_3 = F_17 ( V_32 ) ;
if ( V_3 )
F_18 ( V_32 ) ;
return V_3 ;
}
static void T_3 F_19 ( void )
{
F_20 ( V_32 ) ;
}
