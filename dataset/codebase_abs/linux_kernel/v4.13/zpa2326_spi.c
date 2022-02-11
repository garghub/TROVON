static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 , & V_5 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( & V_2 -> V_6 , L_1 ) ;
return F_5 ( V_3 ) ;
}
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = F_6 ( V_2 -> V_9 , 1000000U ) ;
V_2 -> V_10 = 8 ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_8 ( & V_2 -> V_6 , F_9 ( V_2 ) -> V_11 ,
V_2 -> V_12 , V_13 , V_3 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_6 ) ;
return 0 ;
}
