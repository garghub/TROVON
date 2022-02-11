static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( ! F_2 ( V_4 ) )
return - V_5 ;
return F_3 ( V_1 , V_3 ) ;
}
static long F_4 ( T_1 V_6 )
{
struct V_7 V_8 ;
int V_9 = - V_10 ;
F_5 () ;
if ( V_11 )
goto V_12;
F_6 ( V_13 , V_6 ,
F_7 ( V_14 ) , 0 ) ;
V_8 . V_15 = V_16 ;
V_8 . V_17 = V_6 ;
V_9 = F_8 ( V_18 , & V_8 ) ;
if ( V_9 )
goto V_12;
if ( V_19 > 0 )
F_9 () ;
V_19 = V_8 . V_20 ;
F_10 () ;
return V_8 . V_20 ;
V_12:
F_11 () ;
return V_9 ;
}
static long F_12 ( struct V_2 * V_2 , unsigned int V_21 ,
unsigned long V_22 )
{
if ( ! F_2 ( V_4 ) )
return - V_5 ;
switch ( V_21 ) {
case V_23 :
if ( V_19 > 0 )
return V_19 ;
return - V_24 ;
case V_25 :
return F_4 ( V_22 ) ;
default:
return - V_26 ;
}
}
static int F_13 ( struct V_2 * V_2 , struct V_27 * V_28 )
{
T_2 V_29 = V_28 -> V_30 - V_28 -> V_31 ;
if ( ! F_2 ( V_4 ) )
return - V_5 ;
if ( ( V_29 > V_32 ) || ( V_28 -> V_33 != 0 ) )
return - V_34 ;
if ( F_14 ( V_28 , V_28 -> V_31 ,
F_15 ( V_14 ) ,
V_29 , V_28 -> V_35 ) )
return - V_36 ;
return 0 ;
}
static int T_3 F_16 ( void )
{
int V_9 ;
if ( ! F_17 () )
return - V_24 ;
V_9 = F_18 ( & V_37 ) ;
if ( V_9 )
F_19 ( V_38 L_1 ) ;
return V_9 ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_37 ) ;
}
