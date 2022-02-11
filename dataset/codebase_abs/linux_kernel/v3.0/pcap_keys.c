static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
int V_4 = F_2 ( V_3 -> V_5 , V_1 ) ;
T_2 V_6 ;
F_3 ( V_3 -> V_5 , V_7 , & V_6 ) ;
V_6 &= 1 << V_4 ;
switch ( V_4 ) {
case V_8 :
F_4 ( V_3 -> V_9 , V_10 , ! V_6 ) ;
break;
case V_11 :
F_4 ( V_3 -> V_9 , V_12 , ! V_6 ) ;
break;
}
F_5 ( V_3 -> V_9 ) ;
return V_13 ;
}
static int T_3 F_6 ( struct V_14 * V_15 )
{
int V_16 = - V_17 ;
struct V_3 * V_3 ;
struct V_18 * V_18 ;
V_3 = F_7 ( sizeof( struct V_3 ) , V_19 ) ;
if ( ! V_3 )
return V_16 ;
V_3 -> V_5 = F_8 ( V_15 -> V_20 . V_21 ) ;
V_18 = F_9 () ;
if ( ! V_18 )
goto V_22;
V_3 -> V_9 = V_18 ;
F_10 ( V_15 , V_3 ) ;
V_18 -> V_23 = V_15 -> V_23 ;
V_18 -> V_24 = L_1 ;
V_18 -> V_25 . V_26 = V_27 ;
V_18 -> V_20 . V_21 = & V_15 -> V_20 ;
F_11 ( V_28 , V_18 -> V_29 ) ;
F_11 ( V_10 , V_18 -> V_30 ) ;
F_11 ( V_12 , V_18 -> V_30 ) ;
V_16 = F_12 ( V_18 ) ;
if ( V_16 )
goto V_31;
V_16 = F_13 ( F_14 ( V_3 -> V_5 , V_8 ) ,
F_1 , 0 , L_2 , V_3 ) ;
if ( V_16 )
goto V_32;
V_16 = F_13 ( F_14 ( V_3 -> V_5 , V_11 ) ,
F_1 , 0 , L_3 , V_3 ) ;
if ( V_16 )
goto V_33;
return 0 ;
V_33:
F_15 ( F_14 ( V_3 -> V_5 , V_8 ) , V_3 ) ;
V_32:
F_16 ( V_18 ) ;
goto V_22;
V_31:
F_17 ( V_18 ) ;
V_22:
F_18 ( V_3 ) ;
return V_16 ;
}
static int T_4 F_19 ( struct V_14 * V_15 )
{
struct V_3 * V_3 = F_20 ( V_15 ) ;
F_15 ( F_14 ( V_3 -> V_5 , V_8 ) , V_3 ) ;
F_15 ( F_14 ( V_3 -> V_5 , V_11 ) , V_3 ) ;
F_16 ( V_3 -> V_9 ) ;
F_18 ( V_3 ) ;
return 0 ;
}
static int T_5 F_21 ( void )
{
return F_22 ( & V_34 ) ;
}
static void T_6 F_23 ( void )
{
F_24 ( & V_34 ) ;
}
