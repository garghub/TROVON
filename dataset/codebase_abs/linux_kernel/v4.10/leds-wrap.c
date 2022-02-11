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
return V_10 ;
return F_7 ( & V_9 -> V_11 , & V_14 ) ;
}
static int T_1 F_8 ( void )
{
int V_10 ;
if ( ! F_9 () ) {
V_10 = - V_15 ;
goto V_16;
}
V_10 = F_10 ( & V_17 ) ;
if ( V_10 < 0 )
goto V_16;
V_9 = F_11 ( V_18 , - 1 , NULL , 0 ) ;
if ( F_12 ( V_9 ) ) {
V_10 = F_13 ( V_9 ) ;
F_14 ( & V_17 ) ;
goto V_16;
}
V_16:
return V_10 ;
}
static void T_2 F_15 ( void )
{
F_16 ( V_9 ) ;
F_14 ( & V_17 ) ;
}
