static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
if ( ! V_7 )
return - V_10 ;
V_3 = V_7 -> V_11 ;
F_2 ( & V_5 , F_3 ( 0 ) , 1 , 0 ) ;
if ( F_4 ( V_3 , V_12 , & V_5 ) <= 0 ) {
F_5 ( & V_2 -> V_8 , L_1 ,
V_3 ) ;
return - V_10 ;
}
return 0 ;
}
static int T_1 F_6 ( void )
{
if ( F_7 () == V_13 ) {
V_14 . V_8 . V_9 = & V_15 ;
return F_8 ( & V_14 ) ;
}
return - V_16 ;
}
