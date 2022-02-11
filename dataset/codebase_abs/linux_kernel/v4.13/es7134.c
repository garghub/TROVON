static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
V_3 &= ( V_4 | V_5 |
V_6 ) ;
if ( V_3 != ( V_7 | V_8 |
V_9 ) ) {
F_2 ( V_2 -> V_10 , L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_3 ( struct V_12 * V_13 )
{
return F_4 ( & V_13 -> V_10 ,
& V_14 ,
& V_15 , 1 ) ;
}
static int F_5 ( struct V_12 * V_13 )
{
F_6 ( & V_13 -> V_10 ) ;
return 0 ;
}
