static inline void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_1 -> V_2 ) ;
}
int T_1 F_3 ( void )
{
struct V_3 * V_4 ;
T_2 V_5 ;
if ( F_4 () ) {
V_6 = V_7 ;
V_5 = V_8 ;
}
F_5 ( & V_9 ) ;
for ( V_4 = V_10 ; V_4 < V_10 + F_6 ( V_10 ) ; V_4 ++ )
F_7 ( V_4 -> V_11 . V_1 ) ;
for ( V_4 = V_10 ; V_4 < V_10 + F_6 ( V_10 ) ; V_4 ++ ) {
if ( V_4 -> V_12 & V_5 ) {
F_8 ( & V_4 -> V_11 ) ;
F_9 ( V_4 -> V_11 . V_1 ) ;
F_10 ( V_4 -> V_11 . V_1 ) ;
}
}
F_11 () ;
F_12 () ;
return 0 ;
}
