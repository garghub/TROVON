static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
const struct V_4 * V_5 = F_2 ( V_2 ) ;
V_2 -> V_6 = V_7 ;
V_2 -> V_8 = 8000000 ;
V_2 -> V_9 = 8 ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 )
return V_3 ;
return F_4 ( & V_2 -> V_10 ,
F_5 ( V_2 , & V_11 ) ,
V_5 -> V_12 , V_5 -> V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( & V_2 -> V_10 ) ;
}
