static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_1 ) ;
V_2 -> V_3 = NULL ;
}
static int F_3 ( struct V_1 * V_3 , T_1 V_4 ,
int V_5 )
{
if ( V_6 . V_2 . V_3 )
return - V_7 ;
V_6 . V_2 . V_3 = V_3 ;
V_8 [ 0 ] . V_9 = V_5 ;
V_8 [ 1 ] . V_9 = V_4 ;
V_8 [ 1 ] . V_10 = V_4 ;
V_8 [ 2 ] . V_9 = V_4 + 1 ;
V_8 [ 2 ] . V_10 = V_4 + 1 ;
V_6 . V_11 = V_12 . V_13 . V_11 ;
return F_4 ( & V_6 ) ;
}
static void F_5 ( struct V_14 * V_15 )
{
F_2 ( & V_15 -> V_2 , L_2 ) ;
F_6 ( V_15 ) ;
F_7 ( V_15 -> V_16 ) ;
}
static void F_6 ( struct V_14 * V_15 )
{
F_2 ( & V_15 -> V_2 , L_3 ) ;
F_8 ( V_15 ) ;
F_9 ( & V_6 ) ;
}
static int F_10 ( struct V_14 * V_17 , void * V_18 )
{
if ( V_17 -> V_19 == 0 )
return - V_20 ;
return F_11 ( V_17 ) ;
}
static int F_12 ( struct V_14 * V_15 )
{
struct V_1 * V_3 = & V_15 -> V_2 ;
int V_21 ;
F_2 ( & V_15 -> V_2 , L_4 ) ;
V_15 -> V_22 |= V_23 | V_24 |
V_25 | V_26 ;
if ( F_13 ( V_15 , F_10 , NULL ) )
goto V_27;
if ( F_14 ( V_15 -> V_28 [ 0 ] ) < 2 )
goto V_27;
if ( ! V_15 -> V_5 )
goto V_27;
V_21 = F_15 ( V_15 ) ;
if ( V_21 )
goto V_27;
if ( F_3 ( V_3 , V_15 -> V_28 [ 0 ] -> V_9 , V_15 -> V_5 )
< 0 ) {
V_27:
F_16 ( V_29 L_5 ) ;
F_6 ( V_15 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_17 ( struct V_14 * V_15 )
{
T_2 * V_31 ;
V_31 = F_18 ( sizeof( T_2 ) , V_32 ) ;
if ( ! V_31 )
return - V_33 ;
V_31 -> V_17 = V_15 ;
V_15 -> V_16 = V_31 ;
return F_12 ( V_15 ) ;
}
static int T_3 F_19 ( void )
{
return F_20 ( & V_34 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_34 ) ;
}
