int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_4 = NULL ;
struct V_5 * V_6 = NULL ;
int V_7 = 0 ;
if ( V_3 )
V_4 = F_2 ( V_3 ) ;
if ( V_4 )
V_6 = & V_4 -> V_5 [ V_8 ] ;
if ( V_6 && V_6 -> V_9 & V_10 )
V_7 = 1 ;
return V_7 ;
}
