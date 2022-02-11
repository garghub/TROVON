static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 && V_2 -> V_3 &&
! V_4 . V_5 ( V_2 , * V_2 -> V_3 ) ;
}
struct V_6 * F_2 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return & V_7 ;
return & V_4 ;
}
void T_1
F_3 ( void )
{
if ( F_4 ( 2 * ( 1 << 20 ) ) != 0 ) {
#ifdef F_5
F_6 ( V_8 L_1
L_2 , V_9 ) ;
F_7 ( L_3 ) ;
#else
F_8 ( L_4 ) ;
#endif
}
}
