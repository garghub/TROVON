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
static int F_5 ( struct V_6 * V_7 ,
T_1 V_8 )
{
F_6 ( & V_9 ) ;
F_6 ( & V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 )
{
F_8 ( & V_9 ) ;
F_8 ( & V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_11 )
{
int V_12 ;
V_12 = F_10 ( & V_11 -> V_7 , & V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( & V_11 -> V_7 , & V_10 ) ;
if ( V_12 < 0 )
F_11 ( & V_9 ) ;
return V_12 ;
}
static int F_12 ( struct V_6 * V_11 )
{
F_11 ( & V_9 ) ;
F_11 ( & V_10 ) ;
return 0 ;
}
static int T_2 F_13 ( void )
{
int V_12 ;
V_12 = F_14 ( & V_13 ) ;
if ( V_12 < 0 )
goto V_14;
V_11 = F_15 ( V_15 , - 1 , NULL , 0 ) ;
if ( F_16 ( V_11 ) ) {
V_12 = F_17 ( V_11 ) ;
F_18 ( & V_13 ) ;
goto V_14;
}
V_14:
return V_12 ;
}
static void T_3 F_19 ( void )
{
F_20 ( V_11 ) ;
F_18 ( & V_13 ) ;
}
