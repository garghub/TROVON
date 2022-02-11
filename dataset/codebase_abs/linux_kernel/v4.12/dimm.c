static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 ) {
if ( V_5 == - V_6 )
V_5 = 0 ;
return V_5 ;
}
V_4 = F_3 ( sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
F_4 ( V_2 , V_4 ) ;
V_4 -> V_9 . V_10 = F_5 ( V_2 ) ;
V_4 -> V_11 = - 1 ;
V_4 -> V_12 = - 1 ;
V_4 -> V_9 . V_13 = 0 ;
V_4 -> V_9 . V_14 = - 1 ;
V_4 -> V_2 = V_2 ;
F_6 ( V_2 ) ;
F_7 ( & V_4 -> V_15 ) ;
V_5 = F_8 ( V_4 ) ;
if ( V_5 == - V_16 )
F_9 ( V_2 ) ;
if ( V_5 )
goto V_17;
V_5 = F_10 ( V_4 ) ;
if ( V_5 )
goto V_17;
F_11 ( V_2 , L_1 , V_4 -> V_18 . V_19 ) ;
F_12 ( V_2 ) ;
V_4 -> V_11 = F_13 ( V_4 ) ;
V_4 -> V_12 = F_14 ( V_4 -> V_11 ) ;
F_15 ( V_4 , F_16 ( V_4 ) ,
F_17 ( V_4 ) ) ;
V_5 = F_18 ( V_4 ) ;
if ( V_4 -> V_11 >= 0 )
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( V_5 )
goto V_17;
return 0 ;
V_17:
F_21 ( V_4 ) ;
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_23 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
F_12 ( V_2 ) ;
F_4 ( V_2 , NULL ) ;
F_20 ( V_2 ) ;
F_21 ( V_4 ) ;
return 0 ;
}
int T_1 F_24 ( void )
{
return F_25 ( & V_20 ) ;
}
void F_26 ( void )
{
F_27 ( & V_20 . V_21 ) ;
}
