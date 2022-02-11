static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 , struct V_6 * V_7 )
{
V_5 &= ~ ( V_8 | V_9 | V_10 ) ;
#ifdef F_2
if ( V_2 -> V_11 <= F_3 ( 32 ) )
V_5 |= V_9 ;
#endif
V_5 |= V_12 ;
return F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_13 , T_2 V_4 , struct V_6 * V_7 )
{
F_6 ( V_2 , V_3 , V_13 , V_4 ) ;
}
void T_4 F_7 ( void )
{
T_1 V_14 ;
unsigned long V_15 ;
V_14 = 1 << 20 ;
V_15 = V_14 >> V_16 ;
V_15 = F_8 ( V_15 , V_17 ) ;
V_14 = V_15 << V_16 ;
V_18 = F_9 ( V_14 ) ;
F_10 ( V_18 , V_15 , 1 ) ;
}
