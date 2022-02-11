static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = ( V_6 == V_2 -> V_7 ) ?
V_8 : 0 ;
return F_4 ( V_2 , V_4 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_5 , V_3 ;
V_5 = F_2 ( V_2 , V_9 ) ;
V_5 &= ~ V_10 ;
F_4 ( V_2 , V_9 , V_5 ) ;
V_3 = F_3 ( V_2 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_5 , V_3 ;
V_5 = F_2 ( V_2 , V_9 ) ;
V_5 &= ~ V_11 ;
F_4 ( V_2 , V_9 , V_5 ) ;
V_3 = F_3 ( V_2 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 , V_3 ;
V_5 = F_2 ( V_2 , V_9 ) ;
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_9 , V_5 ) ;
V_3 = F_3 ( V_2 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_13 ;
if ( V_2 -> V_14 & V_15 ) {
V_13 = F_2 ( V_2 , V_9 ) ;
V_13 |= V_16 ;
F_4 ( V_2 , V_9 , V_13 ) ;
}
return 0 ;
}
static int T_1 F_10 ( void )
{
int V_17 ;
V_17 = F_11 ( & V_18 ) ;
if ( V_17 )
goto V_19;
V_17 = F_11 ( & V_20 ) ;
if ( V_17 )
goto V_21;
V_17 = F_11 ( & V_22 ) ;
if ( V_17 )
goto V_23;
V_17 = F_11 ( & V_24 ) ;
if ( V_17 )
goto V_25;
V_17 = F_11 ( & V_26 ) ;
if ( V_17 )
goto V_27;
return 0 ;
V_27:
F_12 ( & V_24 ) ;
V_25:
F_12 ( & V_22 ) ;
V_23:
F_12 ( & V_20 ) ;
V_21:
F_12 ( & V_18 ) ;
V_19:
return V_17 ;
}
static void T_2 F_13 ( void )
{
F_12 ( & V_18 ) ;
F_12 ( & V_22 ) ;
F_12 ( & V_20 ) ;
F_12 ( & V_24 ) ;
F_12 ( & V_26 ) ;
}
