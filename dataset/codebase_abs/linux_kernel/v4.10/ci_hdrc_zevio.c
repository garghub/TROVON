static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
F_2 ( & V_2 -> V_4 , L_1 ) ;
V_3 = F_3 ( & V_2 -> V_4 ,
V_2 -> V_5 , V_2 -> V_6 ,
& V_7 ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( & V_2 -> V_4 , L_2 ) ;
return F_6 ( V_3 ) ;
}
F_7 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_9 ( V_2 ) ;
F_10 ( V_3 ) ;
return 0 ;
}
