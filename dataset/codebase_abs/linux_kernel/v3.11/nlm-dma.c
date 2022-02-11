static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 , struct V_6 * V_7 )
{
void * V_8 ;
if ( F_2 ( V_2 , V_3 , V_4 , & V_8 ) )
return V_8 ;
V_5 &= ~ ( V_9 | V_10 | V_11 ) ;
#ifdef F_3
if ( V_2 -> V_12 <= F_4 ( 32 ) )
V_5 |= V_10 ;
#endif
V_5 |= V_13 ;
return F_5 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_14 , T_2 V_4 , struct V_6 * V_7 )
{
int V_15 = F_7 ( V_3 ) ;
if ( F_8 ( V_2 , V_15 , V_14 ) )
return;
F_9 ( V_2 , V_3 , V_14 , V_4 ) ;
}
void T_4 F_10 ( void )
{
T_1 V_16 ;
unsigned long V_17 ;
V_16 = 1 << 20 ;
V_17 = V_16 >> V_18 ;
V_17 = F_11 ( V_17 , V_19 ) ;
V_16 = V_17 << V_18 ;
V_20 = F_12 ( V_16 ) ;
F_13 ( V_20 , V_17 , 1 ) ;
}
