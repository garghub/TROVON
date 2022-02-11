static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 , & V_5 ) ;
if ( F_3 ( V_3 ) ) {
V_4 = F_4 ( V_3 ) ;
return V_4 ;
}
return F_5 ( & V_2 -> V_6 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_6 ) ;
return 0 ;
}
