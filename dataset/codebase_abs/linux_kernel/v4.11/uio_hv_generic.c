static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_6 >= V_7 )
return - V_8 ;
if ( V_2 -> V_9 [ V_4 -> V_6 ] . V_10 == 0 )
return - V_8 ;
V_5 = ( int ) V_4 -> V_6 ;
return F_2 ( V_4 , V_4 -> V_11 ,
V_2 -> V_9 [ V_5 ] . V_12 >> V_13 ,
V_4 -> V_14 - V_4 -> V_11 , V_4 -> V_15 ) ;
}
static int
F_3 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 ;
V_21 -> V_23 -> V_24 . V_25 -> V_26 = ! V_16 ;
F_4 () ;
return 0 ;
}
static void F_5 ( void * V_27 )
{
struct V_17 * V_18 = V_27 ;
struct V_20 * V_21 = V_18 -> V_22 ;
V_21 -> V_23 -> V_24 . V_25 -> V_26 = 1 ;
F_4 () ;
F_6 ( & V_18 -> V_2 ) ;
}
static int
F_7 ( struct V_20 * V_21 ,
const struct V_28 * V_29 )
{
struct V_17 * V_18 ;
int V_30 ;
V_18 = F_8 ( sizeof( * V_18 ) , V_31 ) ;
if ( ! V_18 )
return - V_32 ;
V_30 = F_9 ( V_21 -> V_23 , V_33 * V_34 ,
V_33 * V_34 , NULL , 0 ,
F_5 , V_18 ) ;
if ( V_30 )
goto V_35;
V_21 -> V_23 -> V_24 . V_25 -> V_26 = 1 ;
F_10 ( V_21 -> V_23 , V_36 ) ;
V_18 -> V_2 . V_37 = L_1 ;
V_18 -> V_2 . V_38 = V_39 ;
V_18 -> V_2 . V_40 = F_3 ;
V_18 -> V_2 . V_41 = F_1 ;
V_18 -> V_2 . V_42 = V_43 ;
V_18 -> V_2 . V_9 [ V_44 ] . V_37 = L_2 ;
V_18 -> V_2 . V_9 [ V_44 ] . V_12
= F_11 ( V_21 -> V_23 -> V_45 ) ;
V_18 -> V_2 . V_9 [ V_44 ] . V_10
= V_21 -> V_23 -> V_46 * V_34 ;
V_18 -> V_2 . V_9 [ V_44 ] . V_47 = V_48 ;
V_18 -> V_2 . V_9 [ V_49 ] . V_37 = L_3 ;
V_18 -> V_2 . V_9 [ V_49 ] . V_12 =
F_11 ( V_50 . V_51 ) ;
V_18 -> V_2 . V_9 [ V_49 ] . V_10 = V_34 ;
V_18 -> V_2 . V_9 [ V_49 ] . V_47 = V_48 ;
V_18 -> V_2 . V_9 [ V_52 ] . V_37 = L_4 ;
V_18 -> V_2 . V_9 [ V_52 ] . V_12 =
F_11 ( V_50 . V_53 [ 1 ] ) ;
V_18 -> V_2 . V_9 [ V_52 ] . V_10 = V_34 ;
V_18 -> V_2 . V_9 [ V_52 ] . V_47 = V_48 ;
V_18 -> V_2 . V_19 = V_18 ;
V_18 -> V_22 = V_21 ;
V_30 = F_12 ( & V_21 -> V_22 , & V_18 -> V_2 ) ;
if ( V_30 ) {
F_13 ( & V_21 -> V_22 , L_5 ) ;
goto V_54;
}
F_14 ( V_21 , V_18 ) ;
return 0 ;
V_54:
F_15 ( V_21 -> V_23 ) ;
V_35:
F_16 ( V_18 ) ;
return V_30 ;
}
static int
F_17 ( struct V_20 * V_21 )
{
struct V_17 * V_18 = F_18 ( V_21 ) ;
if ( ! V_18 )
return 0 ;
F_19 ( & V_18 -> V_2 ) ;
F_14 ( V_21 , NULL ) ;
F_15 ( V_21 -> V_23 ) ;
F_16 ( V_18 ) ;
return 0 ;
}
static int T_2
F_20 ( void )
{
return F_21 ( & V_55 ) ;
}
static void T_3
F_22 ( void )
{
F_23 ( & V_55 ) ;
}
