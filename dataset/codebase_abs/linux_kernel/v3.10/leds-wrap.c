static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 )
F_2 ( V_5 ) ;
else
F_3 ( V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 )
F_2 ( V_6 ) ;
else
F_3 ( V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 )
F_2 ( V_7 ) ;
else
F_3 ( V_7 ) ;
}
static int F_6 ( struct V_8 * V_9 )
{
int V_10 ;
V_10 = F_7 ( & V_9 -> V_11 , & V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_7 ( & V_9 -> V_11 , & V_13 ) ;
if ( V_10 < 0 )
goto V_14;
V_10 = F_7 ( & V_9 -> V_11 , & V_15 ) ;
if ( V_10 < 0 )
goto V_16;
return V_10 ;
V_16:
F_8 ( & V_13 ) ;
V_14:
F_8 ( & V_12 ) ;
return V_10 ;
}
static int F_9 ( struct V_8 * V_9 )
{
F_8 ( & V_12 ) ;
F_8 ( & V_13 ) ;
F_8 ( & V_15 ) ;
return 0 ;
}
static int T_1 F_10 ( void )
{
int V_10 ;
if ( ! F_11 () ) {
V_10 = - V_17 ;
goto V_18;
}
V_10 = F_12 ( & V_19 ) ;
if ( V_10 < 0 )
goto V_18;
V_9 = F_13 ( V_20 , - 1 , NULL , 0 ) ;
if ( F_14 ( V_9 ) ) {
V_10 = F_15 ( V_9 ) ;
F_16 ( & V_19 ) ;
goto V_18;
}
V_18:
return V_10 ;
}
static void T_2 F_17 ( void )
{
F_18 ( V_9 ) ;
F_16 ( & V_19 ) ;
}
