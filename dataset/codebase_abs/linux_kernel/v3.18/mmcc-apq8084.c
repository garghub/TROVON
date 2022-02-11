static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_4 ;
V_3 = F_2 ( V_2 , & V_5 ) ;
if ( V_3 )
return V_3 ;
V_4 = F_3 ( & V_2 -> V_6 , NULL ) ;
F_4 ( & V_7 , V_4 , & V_8 , true ) ;
F_4 ( & V_9 , V_4 , & V_10 , false ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
return 0 ;
}
