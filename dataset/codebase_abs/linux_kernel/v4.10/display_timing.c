void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
F_2 ( V_2 -> V_3 [ V_4 ] ) ;
F_2 ( V_2 -> V_3 ) ;
}
F_2 ( V_2 ) ;
}
