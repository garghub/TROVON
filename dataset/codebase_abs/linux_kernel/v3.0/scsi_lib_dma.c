int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( F_2 ( V_2 ) ) {
struct V_4 * V_5 = V_2 -> V_4 -> V_6 -> V_7 ;
V_3 = F_3 ( V_5 , F_4 ( V_2 ) , F_2 ( V_2 ) ,
V_2 -> V_8 ) ;
if ( F_5 ( ! V_3 ) )
return - V_9 ;
}
return V_3 ;
}
void F_6 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
struct V_4 * V_5 = V_2 -> V_4 -> V_6 -> V_7 ;
F_7 ( V_5 , F_4 ( V_2 ) , F_2 ( V_2 ) ,
V_2 -> V_8 ) ;
}
}
