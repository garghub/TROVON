static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_4 ,
( ( V_5 == V_2 -> V_6 )
? V_7
: 0 ) ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_8 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_9 ,
V_3 | V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_3 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) ;
}
static int T_1 F_7 ( void )
{
int V_11 ;
V_11 = F_8 ( & V_12 ) ;
if ( V_11 )
goto V_13;
V_11 = F_8 ( & V_14 ) ;
if ( V_11 )
goto V_15;
V_11 = F_8 ( & V_16 ) ;
if ( V_11 )
goto V_17;
V_11 = F_8 ( & V_18 ) ;
if ( V_11 )
goto V_19;
V_11 = F_8 ( & V_20 ) ;
if ( V_11 )
goto V_21;
return 0 ;
V_21:
F_9 ( & V_18 ) ;
V_19:
F_9 ( & V_16 ) ;
V_17:
F_9 ( & V_14 ) ;
V_15:
F_9 ( & V_12 ) ;
V_13:
return V_11 ;
}
static void T_2 F_10 ( void )
{
F_9 ( & V_20 ) ;
F_9 ( & V_18 ) ;
F_9 ( & V_16 ) ;
F_9 ( & V_14 ) ;
F_9 ( & V_12 ) ;
}
