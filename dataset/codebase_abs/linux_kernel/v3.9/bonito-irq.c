static inline void F_1 ( struct V_1 * V_2 )
{
V_3 = ( 1 << ( V_2 -> V_4 - V_5 ) ) ;
F_2 () ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_6 = ( 1 << ( V_2 -> V_4 - V_5 ) ) ;
F_2 () ;
}
void F_4 ( void )
{
T_1 V_7 ;
for ( V_7 = V_5 ; V_7 < V_5 + 32 ; V_7 ++ )
F_5 ( V_7 , & V_8 ,
V_9 ) ;
#ifdef F_6
F_7 ( V_5 + 10 , & V_10 ) ;
#endif
}
