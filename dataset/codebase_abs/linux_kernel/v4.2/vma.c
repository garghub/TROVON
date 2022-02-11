static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
F_2 ( V_3 - V_4 > V_5 ) ;
V_6 = V_7 - V_5 ;
V_8 = F_3 ( sizeof( struct V_1 * ) , V_9 ) ;
if ( ! V_8 )
goto V_10;
V_2 = F_4 ( V_9 ) ;
if ( ! V_2 ) {
F_5 ( V_8 ) ;
goto V_10;
}
F_6 ( F_7 ( V_2 ) , V_4 ) ;
* V_8 = V_2 ;
return 0 ;
V_10:
F_8 ( V_11 L_1 ) ;
V_12 = 0 ;
return - V_13 ;
}
int F_9 ( struct V_14 * V_15 , int V_16 )
{
int V_17 ;
struct V_18 * V_19 = V_20 -> V_19 ;
if ( ! V_12 )
return 0 ;
F_10 ( & V_19 -> V_21 ) ;
V_17 = F_11 ( V_19 , V_6 , V_5 ,
V_22 | V_23 |
V_24 | V_25 | V_26 ,
V_8 ) ;
F_12 ( & V_19 -> V_21 ) ;
return V_17 ;
}
