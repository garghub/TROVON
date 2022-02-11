int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_2 V_3 ;
if ( F_2 () ) {
V_4 = V_5 ;
V_3 = V_6 ;
} else if ( F_3 () ) {
V_4 = V_7 | V_5 ;
V_3 = V_8 | V_6 ;
} else {
return 0 ;
}
F_4 ( & V_9 ) ;
for ( V_2 = V_10 ; V_2 < V_10 + F_5 ( V_10 ) ;
V_2 ++ )
F_6 ( V_2 -> V_11 . V_12 ) ;
for ( V_2 = V_10 ; V_2 < V_10 + F_5 ( V_10 ) ;
V_2 ++ )
if ( V_2 -> V_13 & V_3 ) {
F_7 ( & V_2 -> V_11 ) ;
F_8 ( V_2 -> V_11 . V_12 ) ;
F_9 ( V_2 -> V_11 . V_12 ) ;
}
F_10 () ;
F_11 () ;
F_12 () ;
return 0 ;
}
