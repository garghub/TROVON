static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
if( V_2 -> V_6 == V_7 )
V_3 = F_4 ( V_2 , V_8 , V_9 ) ;
else
V_3 = F_4 ( V_2 , V_8 , 0 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_10 , 0 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
if( V_2 -> V_6 == V_7 )
V_3 = F_4 ( V_2 , V_12 , V_13 ) ;
else
V_3 = F_4 ( V_2 , V_12 , 0 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_14 = F_2 ( V_2 , V_15 ) ;
if ( V_14 & V_16 ) {
V_14 = F_2 ( V_2 , V_17 ) ;
V_14 |= ( V_18 | V_19 ) ;
V_14 &= ~ V_20 ;
F_4 ( V_2 , V_17 , V_14 ) ;
V_2 -> V_21 = F_8 ;
} else {
V_2 -> V_21 = NULL ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_21 ? 0 : F_10 ( V_2 ) ;
}
static int T_1 F_11 ( void )
{
int V_22 ;
V_22 = F_12 ( & V_23 ) ;
if ( V_22 )
goto V_24;
V_22 = F_12 ( & V_25 ) ;
if ( V_22 )
goto V_26;
V_22 = F_12 ( & V_27 ) ;
if ( V_22 )
goto V_28;
return 0 ;
V_28:
F_13 ( & V_25 ) ;
V_26:
F_13 ( & V_23 ) ;
V_24:
return V_22 ;
}
static void T_2 F_14 ( void )
{
F_13 ( & V_23 ) ;
F_13 ( & V_25 ) ;
F_13 ( & V_27 ) ;
}
