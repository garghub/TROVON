int F_1 ( struct V_1 * V_2 )
{
int V_3 = - 1 ;
int V_4 ;
if ( F_2 ( V_2 -> V_5 ) != 55601 &&
V_2 -> V_6 != 55601 )
return - 1 ;
V_4 = ( int ) V_2 -> V_4 ;
#ifdef F_3
F_4 ( L_1 , V_4 ) ;
#endif
if ( V_4 == V_7 &&
V_2 -> V_8 == V_9 ) {
if ( V_2 -> V_10 [ 0 ] == V_2 -> V_11 [ 0 ] &&
( F_2 ( V_2 -> V_10 [ 1 ] ) & 0xfff00000 ) ==
( F_2 ( V_2 -> V_11 [ 1 ] ) & 0xfff00000 ) )
V_3 = 10 ;
}
#ifdef F_3
F_4 ( L_2 , V_3 ) ;
#endif
V_2 -> V_12 = V_3 ;
return 1 ;
}
