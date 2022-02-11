int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , true ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( ! F_6 () && V_5 -> V_6 == NULL )
V_5 -> V_7 = V_3 ;
return 0 ;
}
