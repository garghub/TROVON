static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_2 ( L_1 ) ;
F_3 ( V_4 , ( void V_5 * ) 0xBF000210 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_2 ( L_2 ) ;
F_3 ( V_4 , ( void V_5 * ) 0xBF000218 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_6 ( & V_7 -> V_9 , & V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( & V_7 -> V_9 , & V_11 ) ;
if ( V_8 < 0 )
F_7 ( & V_10 ) ;
return V_8 ;
}
static int F_8 ( struct V_6 * V_7 )
{
F_7 ( & V_10 ) ;
F_7 ( & V_11 ) ;
return 0 ;
}
static int T_1 F_9 ( void )
{
int V_8 ;
V_8 = F_10 ( & V_12 ) ;
if ( V_8 < 0 )
goto V_13;
V_7 = F_11 ( V_14 , - 1 , NULL , 0 ) ;
if ( F_12 ( V_7 ) ) {
V_8 = F_13 ( V_7 ) ;
F_14 ( & V_12 ) ;
goto V_13;
}
V_13:
return V_8 ;
}
static void T_2 F_15 ( void )
{
F_16 ( V_7 ) ;
F_14 ( & V_12 ) ;
}
