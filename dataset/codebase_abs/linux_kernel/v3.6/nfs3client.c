static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
goto V_5;
V_2 -> V_6 = F_2 ( V_2 -> V_7 , & V_8 , 3 ) ;
if ( F_3 ( V_2 -> V_6 ) )
goto V_5;
V_2 -> V_9 |= V_10 ;
return;
V_5:
V_2 -> V_9 &= ~ V_10 ;
}
static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 &= ~ V_4 ;
V_2 -> V_9 &= ~ V_10 ;
}
struct V_1 * F_4 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_12 , V_14 ) ;
if ( ! F_3 ( V_2 ) )
F_1 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_6 ( struct V_1 * V_15 ,
struct V_16 * V_17 ,
struct V_18 * V_19 ,
T_1 V_20 )
{
struct V_1 * V_2 = F_7 ( V_15 , V_17 , V_19 , V_20 ) ;
if ( ! F_3 ( V_2 ) && ! F_3 ( V_15 -> V_6 ) )
F_1 ( V_2 ) ;
return V_2 ;
}
