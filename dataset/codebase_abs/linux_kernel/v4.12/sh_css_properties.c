void
F_1 ( struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
#if F_2 ( V_3 ) || F_2 ( V_4 )
V_2 -> V_5 = F_3 ( V_6 ) / V_7 ;
#else
#error "Unknown GDC version"
#endif
V_2 -> V_8 = true ;
#if F_2 ( V_9 )
V_2 -> V_10 = V_11 ;
#elif F_2 ( V_12 )
V_2 -> V_10 = V_13 ;
#else
#error "Unknown VAMEM version"
#endif
}
