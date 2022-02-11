void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 = V_6 ;
F_2 ( V_5 ) ;
V_3 = V_5 -> V_3 ;
if ( V_3 != V_2 ) {
F_3 ( & V_2 -> V_7 ) ;
V_5 -> V_3 = V_2 ;
}
V_5 -> V_2 = V_2 ;
F_4 ( V_3 , V_2 , V_5 ) ;
F_5 ( V_5 ) ;
#ifdef F_6
F_6 () ;
#endif
if ( V_3 != V_2 )
F_7 ( V_3 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_6 ;
F_2 ( V_5 ) ;
F_9 ( V_2 ) ;
V_5 -> V_2 = NULL ;
F_10 ( V_2 , V_5 ) ;
F_5 ( V_5 ) ;
}
