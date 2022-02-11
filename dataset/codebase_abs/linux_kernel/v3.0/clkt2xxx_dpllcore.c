unsigned long F_1 ( struct V_1 * V_1 )
{
long long V_2 ;
T_1 V_3 ;
V_2 = F_2 ( V_1 ) ;
V_3 = F_3 ( V_4 , V_5 ) ;
V_3 &= V_6 ;
if ( V_3 == V_7 )
V_2 = 32768 ;
else
V_2 *= V_3 ;
return V_2 ;
}
static long F_4 ( unsigned long V_8 )
{
T_1 V_9 , V_10 , V_11 ;
V_11 = F_3 ( V_4 , V_5 ) ;
V_11 &= V_6 ;
if ( V_11 == V_12 ) {
V_9 = V_13 -> V_14 * 2 ;
V_10 = V_13 -> V_14 ;
} else {
V_9 = V_13 -> V_14 ;
V_10 = V_13 -> V_14 / 2 ;
}
#ifdef F_5
if ( V_8 > V_9 )
return V_9 ;
else
return V_8 ;
#else
if ( V_8 > V_10 )
return V_9 ;
else
return V_10 ;
#endif
}
unsigned long F_6 ( struct V_1 * V_1 )
{
return F_1 ( V_1 ) ;
}
int F_7 ( struct V_1 * V_1 , unsigned long V_15 )
{
T_1 V_16 , V_10 , V_17 , div , V_18 , V_19 ;
T_1 V_20 = 0 ;
struct V_21 V_22 ;
const struct V_23 * V_24 ;
V_16 = F_1 ( V_25 ) ;
V_17 = F_3 ( V_4 , V_5 ) ;
V_17 &= V_6 ;
if ( ( V_15 == ( V_16 / 2 ) ) && ( V_17 == 2 ) ) {
F_8 ( V_12 , 1 ) ;
} else if ( ( V_15 == ( V_16 * 2 ) ) && ( V_17 == 1 ) ) {
F_8 ( V_26 , 1 ) ;
} else if ( V_15 != V_16 ) {
V_18 = F_4 ( V_15 ) ;
if ( V_18 != V_15 )
return - V_27 ;
if ( V_17 == 1 )
V_10 = V_13 -> V_14 ;
else
V_10 = V_13 -> V_14 / 2 ;
V_24 = V_1 -> V_23 ;
if ( ! V_24 )
return - V_27 ;
V_22 . V_28 = F_9 ( V_24 -> V_29 ) ;
V_22 . V_28 &= ~ ( V_24 -> V_30 |
V_24 -> V_31 ) ;
div = ( ( V_13 -> V_32 / 1000000 ) - 1 ) ;
V_22 . V_33 = F_3 ( V_4 , V_5 ) ;
V_22 . V_33 &= ~ V_6 ;
if ( V_15 > V_10 ) {
V_22 . V_33 |= V_26 ;
V_17 = ( ( V_15 / 2 ) / 1000000 ) ;
V_19 = V_26 ;
} else {
V_22 . V_33 |= V_12 ;
V_17 = ( V_15 / 1000000 ) ;
V_19 = V_12 ;
}
V_22 . V_28 |= ( div << F_10 ( V_24 -> V_30 ) ) ;
V_22 . V_28 |= ( V_17 << F_10 ( V_24 -> V_31 ) ) ;
V_22 . V_34 = V_35 ;
if ( V_15 == V_13 -> V_32 )
V_20 = 1 ;
F_8 ( V_26 , 1 ) ;
F_11 ( V_22 . V_28 , V_22 . V_34 ,
V_20 ) ;
F_12 ( F_13 () ) ;
F_8 ( V_19 , 0 ) ;
}
return 0 ;
}
