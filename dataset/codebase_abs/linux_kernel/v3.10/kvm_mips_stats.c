int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
int V_3 , V_4 ;
F_3 ( L_1 , V_2 -> V_5 ) ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( V_2 -> V_8 . V_9 -> V_10 [ V_3 ] [ V_4 ] )
F_3 ( L_2 , V_11 [ V_3 ] , V_4 ,
V_2 -> V_8 . V_9 -> V_10 [ V_3 ] [ V_4 ] ) ;
}
}
#endif
return 0 ;
}
