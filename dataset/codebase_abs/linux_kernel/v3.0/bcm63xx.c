static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 |= V_6 ;
V_4 = F_3 ( V_2 , V_5 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 = ~ ( V_7 |
V_8 |
V_9 ) |
V_10 ;
V_4 = F_3 ( V_2 , V_5 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_11 == V_12 )
V_3 &= ~ V_6 ;
else
V_3 |= V_6 ;
V_4 = F_3 ( V_2 , V_5 , V_3 ) ;
return V_4 ;
}
static int T_1 F_6 ( void )
{
int V_13 ;
V_13 = F_7 ( & V_14 ) ;
if ( V_13 )
goto V_15;
V_13 = F_7 ( & V_16 ) ;
if ( V_13 )
goto V_17;
return V_13 ;
V_17:
F_8 ( & V_14 ) ;
V_15:
return V_13 ;
}
static void T_2 F_9 ( void )
{
F_8 ( & V_14 ) ;
F_8 ( & V_16 ) ;
}
