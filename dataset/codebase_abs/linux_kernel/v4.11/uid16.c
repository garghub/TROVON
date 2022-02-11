static int F_1 ( T_1 T_2 * V_1 ,
struct V_2 * V_2 )
{
struct V_3 * V_4 = F_2 () ;
int V_5 ;
T_1 V_6 ;
T_3 V_7 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_8 ; V_5 ++ ) {
V_7 = V_2 -> V_9 [ V_5 ] ;
V_6 = F_3 ( F_4 ( V_4 , V_7 ) ) ;
if ( F_5 ( V_6 , V_1 + V_5 ) )
return - V_10 ;
}
return 0 ;
}
static int F_6 ( struct V_2 * V_2 ,
T_1 T_2 * V_1 )
{
struct V_3 * V_4 = F_2 () ;
int V_5 ;
T_1 V_6 ;
T_3 V_7 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_8 ; V_5 ++ ) {
if ( F_7 ( V_6 , V_1 + V_5 ) )
return - V_10 ;
V_7 = F_8 ( V_4 , F_9 ( V_6 ) ) ;
if ( ! F_10 ( V_7 ) )
return - V_11 ;
V_2 -> V_9 [ V_5 ] = V_7 ;
}
return 0 ;
}
