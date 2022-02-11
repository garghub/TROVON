static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = & V_2 -> V_4 ;
if ( F_2 ( V_2 , 0 ) == 'I' ) {
V_4 -> V_5 = V_6 ;
}
}
int F_3 ( struct V_1 * V_2 , T_1 * V_7 )
{
int V_8 ;
#if F_4 ( V_9 ) && ! F_4 ( V_10 )
V_11 . V_12 = 0 ;
V_11 . V_13 = 0 ;
V_11 . V_14 = 0 ;
V_11 . V_15 = 0 ;
V_11 . V_16 = 0 ;
V_11 . V_17 = 0 ;
V_11 . V_18 = 0 ;
#ifdef F_5
V_11 . V_19 = 0 ;
#endif
#ifdef F_6
V_11 . V_20 = 0 ;
#endif
#endif
for ( V_8 = 0 ; V_8 < V_21 ; V_8 ++ ) {
V_2 -> V_22 [ V_8 ] . V_4 = & V_2 -> V_4 . V_8 [ V_8 ] ;
}
F_1 ( V_2 ) ;
( void ) F_7 ( V_2 ) ;
F_8 ( V_2 , V_7 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
#ifndef F_11
F_12 ( V_2 ) ;
#endif
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < V_21 ; V_8 ++ ) {
F_19 ( V_2 , V_8 , 0 ) ;
}
F_20 ( V_2 , 0 ) ;
F_21 ( V_2 , 0 ) ;
F_22 ( V_2 , 0 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
