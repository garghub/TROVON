int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_6 -> V_7 ( V_2 ) ;
#else
return 0 ;
#endif
}
void F_3 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_8 ) {
V_4 -> V_8 -> V_9 . V_10 = 0 ;
F_4 ( V_4 -> V_8 ) ;
F_5 ( V_4 -> V_8 ) ;
}
#endif
}
