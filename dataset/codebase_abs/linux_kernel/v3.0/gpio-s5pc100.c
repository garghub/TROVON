static T_1 int F_1 ( void )
{
struct V_1 * V_2 = V_3 ;
int V_4 = F_2 ( V_3 ) ;
int V_5 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ , V_2 ++ ) {
if ( V_2 -> V_7 == NULL ) {
V_2 -> V_7 = & V_8 ;
V_2 -> V_9 = V_5 ++ ;
}
if ( V_2 -> V_10 == NULL )
V_2 -> V_10 = F_3 ( V_6 ) ;
}
F_4 ( V_3 , V_4 ) ;
F_5 ( V_11 , 0 , V_12 ) ;
return 0 ;
}
