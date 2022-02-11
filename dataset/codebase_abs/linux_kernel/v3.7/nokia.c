static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_4 L_1 ) ;
V_3 = F_4 ( V_2 , 0 ) ;
if ( V_3 )
F_3 ( V_4 L_2 , 0 ) ;
V_3 = F_4 ( V_2 , 1 ) ;
if ( V_3 )
F_3 ( V_4 L_2 , 0 ) ;
V_3 = F_5 ( V_2 , 2 ) ;
if ( V_3 )
F_3 ( V_4 L_3 ) ;
V_3 = F_6 ( V_2 , V_5 ) ;
if ( V_3 )
F_3 ( V_4 L_4 ) ;
return V_3 ;
}
static int T_1 F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
int V_3 ;
V_3 = F_8 ( V_7 -> V_9 ) ;
if ( V_3 < 0 )
goto V_10;
V_3 = F_9 ( V_7 -> V_9 , 3 ) ;
if ( V_3 < 0 )
goto V_11;
V_3 = F_10 ( V_7 -> V_9 , V_5 ) ;
if ( V_3 < 0 )
goto V_12;
V_3 = F_11 ( V_7 , V_13 ) ;
if ( V_3 < 0 )
goto V_14;
V_15 . V_16 = V_13 [ V_17 ] . V_18 ;
V_15 . V_19 = V_13 [ V_20 ] . V_18 ;
V_3 = V_13 [ V_21 ] . V_18 ;
V_22 . V_23 = V_3 ;
V_24 . V_23 = V_3 ;
if ( ! F_12 ( V_9 ) )
goto V_14;
V_3 = F_13 ( V_7 , & V_22 ,
F_1 ) ;
if ( V_3 < 0 )
goto V_14;
V_3 = F_13 ( V_7 , & V_24 ,
F_1 ) ;
if ( V_3 < 0 )
goto V_14;
F_14 ( V_7 , & V_25 ) ;
F_15 ( & V_9 -> V_26 , L_5 , V_27 ) ;
return 0 ;
V_14:
F_16 () ;
V_12:
F_17 () ;
V_11:
F_18 () ;
V_10:
return V_3 ;
}
static int T_2 F_19 ( struct V_6 * V_7 )
{
F_18 () ;
F_17 () ;
F_16 () ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_28 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_28 ) ;
}
