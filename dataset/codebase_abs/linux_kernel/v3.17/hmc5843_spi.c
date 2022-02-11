static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = 8000000 ;
V_2 -> V_7 = 8 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 )
return V_3 ;
return F_3 ( & V_2 -> V_8 ,
F_4 ( V_2 , & V_9 ) ,
V_10 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( & V_2 -> V_8 ) ;
}
