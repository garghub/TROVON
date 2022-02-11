static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
F_2 ( 0xaa , V_6 ) ;
return V_5 ;
}
static int T_1 F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_4 ( V_8 , V_11 , 0 ) ;
V_6 = F_5 ( & V_8 -> V_2 , V_10 ) ;
if ( F_6 ( V_6 ) )
return F_7 ( V_6 ) ;
return F_8 ( & V_12 , NULL ) ;
}
