static int F_1 ( T_1 T_2 * V_1 ,
struct V_2 * V_2 )
{
int V_3 ;
T_1 V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_4 = F_2 ( F_3 ( V_2 , V_3 ) ) ;
if ( F_4 ( V_4 , V_1 + V_3 ) )
return - V_6 ;
}
return 0 ;
}
static int F_5 ( struct V_2 * V_2 ,
T_1 T_2 * V_1 )
{
int V_3 ;
T_1 V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
if ( F_6 ( V_4 , V_1 + V_3 ) )
return - V_6 ;
F_3 ( V_2 , V_3 ) = F_7 ( V_4 ) ;
}
return 0 ;
}
