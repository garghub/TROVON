void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
#ifdef F_2
if ( F_3 () ) {
V_4 . V_5 = V_6 ;
V_7 . V_5 = V_8 ;
V_9 . V_5 = V_10 ;
} else if ( F_4 () ) {
V_4 . V_5 = V_11 ;
V_7 . V_5 = V_12 ;
V_9 . V_5 = V_13 ;
}
#endif
V_4 . V_14 = & V_15 ;
V_7 . V_14 = & V_16 ;
V_9 . V_14 = & V_17 ;
V_4 . V_18 = & V_19 ;
V_7 . V_18 = & V_20 ;
V_9 . V_18 = & V_21 ;
for ( V_3 = 0 ; V_2 = V_22 [ V_3 ] , V_2 ; V_3 ++ )
V_2 -> V_23 . V_24 = V_25 ;
F_5 ( V_22 ) ;
}
