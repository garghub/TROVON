bool F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
#if V_4 == V_5
unsigned long V_6 = F_2 ( F_3 ( V_2 -> V_7 ) ) ;
unsigned long V_8 = F_2 ( F_3 ( V_3 -> V_7 ) ) ;
return V_6 + F_4 ( V_2 -> V_9 + V_2 -> V_10 ) == V_8 ;
#else
return 0 ;
#endif
}
