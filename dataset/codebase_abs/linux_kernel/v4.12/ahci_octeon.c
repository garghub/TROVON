static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 ;
void T_1 * V_10 ;
T_2 V_11 ;
int V_12 ;
V_9 = F_2 ( V_2 , V_13 , 0 ) ;
V_10 = F_3 ( & V_2 -> V_4 , V_9 ) ;
if ( F_4 ( V_10 ) )
return F_5 ( V_10 ) ;
V_11 = F_6 ( V_10 + V_14 ) ;
V_11 &= ~ ( V_15 << V_16 ) ;
V_11 &= ~ ( V_15 << V_17 ) ;
#ifdef F_7
V_11 |= V_18 << V_16 ;
V_11 |= V_18 << V_17 ;
#else
V_11 |= V_19 << V_16 ;
V_11 |= V_19 << V_17 ;
#endif
V_11 |= 1 << V_20 ;
F_8 ( V_10 + V_14 , V_11 ) ;
if ( ! V_6 ) {
F_9 ( V_4 , L_1 ) ;
return - V_21 ;
}
V_12 = F_10 ( V_6 , NULL , NULL , V_4 ) ;
if ( V_12 ) {
F_9 ( V_4 , L_2 ) ;
return V_12 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return 0 ;
}
