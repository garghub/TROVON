static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 , unsigned long V_6 )
{
V_5 &= ~ ( V_7 | V_8 | V_9 ) ;
#ifdef F_2
if ( V_2 -> V_10 <= F_3 ( 32 ) )
V_5 |= V_8 ;
#endif
V_5 |= V_11 ;
return F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_12 , T_2 V_4 , unsigned long V_6 )
{
F_6 ( V_2 , V_3 , V_12 , V_4 ) ;
}
void T_4 F_7 ( void )
{
T_1 V_13 ;
unsigned long V_14 ;
V_13 = 1 << 20 ;
V_14 = V_13 >> V_15 ;
V_14 = F_8 ( V_14 , V_16 ) ;
V_13 = V_14 << V_15 ;
V_17 = F_9 ( V_13 ) ;
F_10 ( V_17 , V_14 , 1 ) ;
}
