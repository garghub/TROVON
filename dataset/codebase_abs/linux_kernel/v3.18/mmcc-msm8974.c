static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
V_3 = F_2 ( V_2 , & V_4 ) ;
if ( F_3 ( V_3 ) )
return F_4 ( V_3 ) ;
F_5 ( & V_5 , V_3 , & V_6 , true ) ;
F_5 ( & V_7 , V_3 , & V_8 , false ) ;
return F_6 ( V_2 , & V_4 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
return 0 ;
}
