static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_10 = F_2 ( V_4 ) ;
if ( ! V_10 )
return - V_11 ;
V_8 = F_3 ( V_4 , V_12 ) ;
if ( ! V_8 ) {
F_4 ( V_10 ) ;
return - V_13 ;
}
F_5 ( V_14 ,
F_6 ( V_14 ) ,
V_8 ) ;
F_7 ( V_15 , F_6 ( V_15 ) ,
V_8 ) ;
F_8 ( V_16 ,
F_6 ( V_16 ) , V_8 ) ;
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_17 ) ;
}
