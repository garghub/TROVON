static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( ! V_5 )
return - V_8 ;
V_3 = V_5 -> V_9 ;
if ( F_2 ( V_3 , 1 , 0 , F_3 ( 0 ) ) ||
F_4 ( V_3 , V_10 ) <= 0 ) {
F_5 ( & V_2 -> V_6 , L_1 ,
V_3 ) ;
return - V_8 ;
}
return 0 ;
}
static int T_1 F_6 ( void )
{
if ( F_7 () == V_11 ) {
V_12 . V_6 . V_7 = & V_13 ;
return F_8 ( & V_12 ) ;
}
return - V_14 ;
}
