void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_5 = V_2 -> V_5 ;
V_7 = & V_5 -> V_8 ;
if ( F_2 ( V_7 , V_9 ) ) {
#ifdef F_3
F_4 ( V_5 , V_2 , V_3 ) ;
#endif
} else
F_5 ( V_5 , V_2 -> V_10 , V_3 ) ;
}
