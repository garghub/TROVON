static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_6 * V_8 = V_4 -> V_8 ;
int V_9 ;
F_2 ( V_7 , V_10 ,
12000000 , V_11 ) ;
V_9 = F_3 ( V_7 , V_12 |
V_13 | V_14 ) ;
if ( V_9 < 0 )
goto V_15;
V_9 = F_3 ( V_8 , V_12 |
V_13 | V_14 ) ;
if ( V_9 < 0 )
goto V_15;
V_9 = 0 ;
V_15:
return V_9 ;
}
static int T_1 F_4 ( void )
{
int V_9 ;
V_9 = - V_16 ;
V_17 = F_5 ( L_1 , 1 ) ;
if ( ! V_17 )
goto V_15;
if ( F_6 ( V_18 ) & V_19 )
F_7 ( V_17 , & V_20 ) ;
else
F_7 ( V_17 , & V_21 ) ;
V_9 = F_8 ( V_17 ) ;
if ( V_9 ) {
F_9 ( V_17 ) ;
V_17 = NULL ;
}
V_15:
return V_9 ;
}
static void T_2 F_10 ( void )
{
F_11 ( V_17 ) ;
}
