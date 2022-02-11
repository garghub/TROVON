static int F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return 0 ;
}
static int F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
if ( F_4 ( V_4 -> V_8 -> V_9 ) ) {
V_4 -> V_10 = V_11 ;
V_4 -> V_12 |= V_13 ;
}
V_6 = F_5 ( V_14 ) ;
V_15 = F_6 ( V_14 ) ;
if ( F_7 ( V_15 ) )
return F_8 ( V_15 ) ;
V_7 = F_9 ( V_4 , V_15 ) ;
if ( V_7 )
goto V_16;
return 0 ;
V_16:
F_10 ( V_15 ) ;
return V_7 ;
}
static int F_11 ( struct V_17 * V_8 )
{
static const struct V_18 V_19 = {
. V_20 = F_1 ,
} ;
struct V_5 * V_6 ;
struct V_21 V_22 ;
int V_23 ;
V_14 = F_12 ( L_1 ) ;
if ( F_7 ( V_14 ) )
return F_8 ( V_14 ) ;
F_13 ( & V_22 , & V_24 , V_25 ) ;
V_6 = F_5 ( V_14 ) ;
V_6 -> V_26 = true ;
V_23 = F_14 ( V_6 -> V_2 , V_25 ) ;
if ( V_23 )
goto V_27;
F_15 ( V_6 -> V_2 , & V_19 ) ;
V_23 = F_16 ( V_6 -> V_2 , V_8 , V_22 . V_28 ) ;
if ( V_23 )
goto V_29;
F_17 ( V_6 -> V_2 , true ) ;
V_23 = F_18 ( V_6 -> V_2 , & V_22 ) ;
if ( V_23 )
goto V_29;
F_19 ( V_6 -> V_2 , V_22 . V_30 ,
V_22 . V_31 ) ;
V_23 = F_20 ( V_8 , V_32 ) ;
if ( V_23 < 0 )
goto V_33;
V_34 . V_35 = V_32 [ V_36 ] . V_37 ;
if ( F_4 ( V_8 -> V_9 ) && ! V_11 [ 0 ] ) {
struct V_38 * V_39 ;
V_39 = F_21 ( V_8 -> V_9 ) ;
if ( ! V_39 )
goto V_33;
F_22 ( V_8 -> V_9 , V_39 ) ;
V_11 [ 0 ] = V_39 ;
V_11 [ 1 ] = NULL ;
}
V_23 = F_23 ( V_8 , & V_40 , F_3 ) ;
if ( V_23 < 0 )
goto V_41;
F_24 ( V_8 , & V_42 ) ;
F_25 ( & V_8 -> V_9 -> V_43 ,
V_44 L_2 V_45 L_3 ) ;
return 0 ;
V_41:
F_26 ( V_11 [ 0 ] ) ;
V_11 [ 0 ] = NULL ;
V_33:
F_27 ( V_6 -> V_2 ) ;
V_29:
F_28 ( V_6 -> V_2 ) ;
V_27:
F_29 ( V_14 ) ;
return V_23 ;
}
static int F_30 ( struct V_17 * V_8 )
{
if ( ! F_7 ( V_15 ) )
F_10 ( V_15 ) ;
if ( ! F_7 ( V_14 ) )
F_29 ( V_14 ) ;
F_26 ( V_11 [ 0 ] ) ;
V_11 [ 0 ] = NULL ;
return 0 ;
}
static int T_1 F_31 ( void )
{
int V_7 ;
V_7 = F_32 ( & V_46 ) ;
F_33 ( 0 , & V_47 ) ;
return V_7 ;
}
static void F_2 ( void )
{
if ( F_34 ( 0 , & V_47 ) )
F_35 ( & V_46 ) ;
}
