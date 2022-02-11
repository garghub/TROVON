void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
struct V_1 * * V_3 ;
int V_4 ;
#ifdef F_2
if ( F_3 () ) {
V_5 . V_6 = V_7 ;
V_8 . V_6 = V_9 ;
} else {
V_5 . V_6 = V_10 ;
V_8 . V_6 = V_11 ;
}
#endif
if ( F_4 () )
V_3 = V_12 ;
else
V_3 = V_13 ;
for ( V_4 = 0 ; V_2 = V_3 [ V_4 ] , V_2 ; V_4 ++ )
V_2 -> V_14 . V_15 = V_16 ;
F_5 ( V_3 ) ;
}
