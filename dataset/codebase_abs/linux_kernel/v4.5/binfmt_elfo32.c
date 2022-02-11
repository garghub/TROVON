static inline void
F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
T_1 V_4 = ( T_1 ) V_1 * V_5 ;
T_2 V_6 ;
V_3 -> V_7 = F_2 ( V_4 , V_8 , & V_6 ) ;
V_3 -> V_9 = V_6 / V_10 ;
}
static T_3 void
F_3 ( const T_4 V_11 , struct V_2 * V_3 )
{
unsigned long V_1 = F_4 ( V_11 ) ;
V_3 -> V_9 = ( V_1 % V_12 ) * ( 1000000L / V_12 ) ;
V_3 -> V_7 = V_1 / V_12 ;
}
