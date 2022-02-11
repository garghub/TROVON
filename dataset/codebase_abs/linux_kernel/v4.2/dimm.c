static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return - V_7 ;
F_3 ( V_2 , V_4 ) ;
V_4 -> V_8 . V_9 = F_4 ( V_2 ) ;
V_4 -> V_10 = - 1 ;
V_4 -> V_11 = - 1 ;
V_4 -> V_8 . V_12 = 0 ;
V_4 -> V_8 . V_13 = - 1 ;
V_4 -> V_2 = V_2 ;
F_5 ( V_2 ) ;
F_6 ( & V_4 -> V_14 ) ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
goto V_15;
V_5 = F_8 ( V_4 ) ;
if ( V_5 )
goto V_15;
F_9 ( V_2 , L_1 , V_4 -> V_16 . V_17 ) ;
F_10 ( V_2 ) ;
V_4 -> V_10 = F_11 ( V_4 ) ;
V_4 -> V_11 = F_12 ( V_4 -> V_10 ) ;
F_13 ( V_4 , F_14 ( V_4 ) ,
F_15 ( V_4 ) ) ;
V_5 = F_16 ( V_4 ) ;
F_17 ( V_2 ) ;
if ( V_5 )
goto V_15;
return 0 ;
V_15:
F_18 ( V_4 ) ;
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_20 ( V_2 ) ;
F_10 ( V_2 ) ;
F_3 ( V_2 , NULL ) ;
F_17 ( V_2 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
int T_1 F_21 ( void )
{
return F_22 ( & V_18 ) ;
}
void F_23 ( void )
{
F_24 ( & V_18 . V_19 ) ;
}
