static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( F_2 ( V_2 -> V_6 -> V_7 ) ) {
V_2 -> V_8 = V_9 ;
V_2 -> V_10 |= V_11 ;
}
V_4 = F_3 ( V_12 ) ;
V_13 = F_4 ( V_12 ) ;
if ( F_5 ( V_13 ) )
return F_6 ( V_13 ) ;
V_5 = F_7 ( V_2 , V_13 ) ;
if ( V_5 )
goto V_14;
return 0 ;
V_14:
F_8 ( V_13 ) ;
return V_5 ;
}
static int F_9 ( struct V_15 * V_6 )
{
struct V_3 * V_4 ;
struct V_16 V_17 ;
int V_18 ;
V_12 = F_10 ( L_1 ) ;
if ( F_5 ( V_12 ) )
return F_6 ( V_12 ) ;
F_11 ( & V_17 , & V_19 , V_20 ) ;
V_4 = F_3 ( V_12 ) ;
V_4 -> V_21 = true ;
V_18 = F_12 ( V_4 -> V_22 , V_20 ) ;
if ( V_18 )
goto V_23;
V_18 = F_13 ( V_4 -> V_22 , V_6 , V_17 . V_24 ) ;
if ( V_18 )
goto V_25;
F_14 ( V_4 -> V_22 , true ) ;
V_18 = F_15 ( V_4 -> V_22 , & V_17 ) ;
if ( V_18 )
goto V_25;
F_16 ( V_4 -> V_22 , V_17 . V_26 ,
V_17 . V_27 ) ;
V_18 = F_17 ( V_6 , V_28 ) ;
if ( V_18 < 0 )
goto V_29;
V_30 . V_31 = V_28 [ V_32 ] . V_33 ;
if ( F_2 ( V_6 -> V_7 ) && ! V_9 [ 0 ] ) {
struct V_34 * V_35 ;
V_35 = F_18 ( V_6 -> V_7 ) ;
if ( ! V_35 )
goto V_29;
F_19 ( V_6 -> V_7 , V_35 ) ;
V_9 [ 0 ] = V_35 ;
V_9 [ 1 ] = NULL ;
}
V_18 = F_20 ( V_6 , & V_36 , F_1 ) ;
if ( V_18 < 0 )
goto V_37;
F_21 ( V_6 , & V_38 ) ;
F_22 ( & V_6 -> V_7 -> V_39 ,
V_40 L_2 V_41 L_3 ) ;
return 0 ;
V_37:
F_23 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = NULL ;
V_29:
F_24 ( V_4 -> V_22 ) ;
V_25:
F_25 ( V_4 -> V_22 ) ;
V_23:
F_26 ( V_12 ) ;
return V_18 ;
}
static int F_27 ( struct V_15 * V_6 )
{
if ( ! F_5 ( V_13 ) )
F_8 ( V_13 ) ;
if ( ! F_5 ( V_12 ) )
F_26 ( V_12 ) ;
F_23 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = NULL ;
return 0 ;
}
static int T_1 F_28 ( void )
{
return F_29 ( & V_42 ) ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_42 ) ;
}
