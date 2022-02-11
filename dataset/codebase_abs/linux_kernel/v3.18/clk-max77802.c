static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
int V_7 ;
V_7 = F_3 ( V_2 , V_4 -> V_8 , V_9 ,
V_10 , V_11 ) ;
if ( V_7 ) {
F_4 ( & V_2 -> V_5 , L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_4 -> V_8 , V_9 ,
1 << V_12 ,
1 << V_12 ) ;
if ( V_7 < 0 )
F_4 ( & V_2 -> V_5 , L_2 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_11 ) ;
}
