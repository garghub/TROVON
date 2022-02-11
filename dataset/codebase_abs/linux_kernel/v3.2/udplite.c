static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , & V_3 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 )
{
F_4 ( V_2 , V_5 , & V_3 ) ;
}
static int T_2 F_5 ( struct V_6 * V_6 )
{
return F_6 ( V_6 , & V_7 ) ;
}
static void T_3 F_7 ( struct V_6 * V_6 )
{
F_8 ( V_6 , & V_7 ) ;
}
static T_4 int F_9 ( void )
{
return F_10 ( & V_8 ) ;
}
static inline int F_9 ( void )
{
return 0 ;
}
void T_4 F_11 ( void )
{
F_12 ( & V_3 , L_1 ) ;
if ( F_13 ( & V_9 , 1 ) )
goto V_10;
if ( F_14 ( & V_11 , V_4 ) < 0 )
goto V_12;
F_15 ( & V_13 ) ;
if ( F_9 () )
F_16 ( V_14 L_2 , V_15 ) ;
return;
V_12:
F_17 ( & V_9 ) ;
V_10:
F_16 ( V_16 L_3 , V_15 ) ;
}
