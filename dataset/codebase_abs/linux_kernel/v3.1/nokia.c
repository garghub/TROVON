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
int V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
int V_3 ;
V_3 = F_8 ( V_7 -> V_10 ) ;
if ( V_3 < 0 )
goto V_11;
V_3 = F_9 ( V_7 -> V_10 , 3 ) ;
if ( V_3 < 0 )
goto V_12;
V_3 = F_10 ( V_7 -> V_10 , V_5 ) ;
if ( V_3 < 0 )
goto V_13;
V_3 = F_11 ( V_7 ) ;
if ( V_3 < 0 )
goto V_14;
V_15 [ V_16 ] . V_17 = V_3 ;
V_18 . V_19 = V_3 ;
V_3 = F_11 ( V_7 ) ;
if ( V_3 < 0 )
goto V_14;
V_15 [ V_20 ] . V_17 = V_3 ;
V_18 . V_21 = V_3 ;
V_3 = F_11 ( V_7 ) ;
if ( V_3 < 0 )
goto V_14;
V_15 [ V_22 ] . V_17 = V_3 ;
V_23 . V_24 = V_3 ;
V_25 . V_24 = V_3 ;
V_8 = F_12 ( V_10 ) ;
if ( V_8 >= 0 )
V_18 . V_26 = F_13 ( V_27 ) ;
else {
F_14 ( L_5 ,
V_10 -> V_28 ) ;
goto V_14;
}
V_3 = F_15 ( V_7 , & V_23 ,
F_1 ) ;
if ( V_3 < 0 )
goto V_14;
V_3 = F_15 ( V_7 , & V_25 ,
F_1 ) ;
if ( V_3 < 0 )
goto V_14;
F_16 ( & V_10 -> V_29 , L_6 , V_30 ) ;
return 0 ;
V_14:
F_17 () ;
V_13:
F_18 () ;
V_12:
F_19 () ;
V_11:
return V_3 ;
}
static int T_2 F_20 ( struct V_6 * V_7 )
{
F_19 () ;
F_18 () ;
F_17 () ;
return 0 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_31 , F_7 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_31 ) ;
}
