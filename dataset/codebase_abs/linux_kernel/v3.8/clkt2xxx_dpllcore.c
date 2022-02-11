unsigned long F_1 ( void )
{
long long V_1 ;
T_1 V_2 ;
F_2 ( ! V_3 ) ;
V_1 = F_3 ( V_3 ) ;
V_2 = F_4 ( V_4 , V_5 ) ;
V_2 &= V_6 ;
if ( V_2 == V_7 )
V_1 = 32768 ;
else
V_1 *= V_2 ;
return V_1 ;
}
static long F_5 ( unsigned long V_8 )
{
T_1 V_9 , V_10 , V_11 ;
V_11 = F_4 ( V_4 , V_5 ) ;
V_11 &= V_6 ;
if ( V_11 == V_12 ) {
V_9 = V_13 -> V_14 * 2 ;
V_10 = V_13 -> V_14 ;
} else {
V_9 = V_13 -> V_14 ;
V_10 = V_13 -> V_14 / 2 ;
}
#ifdef F_6
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
unsigned long F_7 ( struct V_15 * V_16 ,
unsigned long V_17 )
{
return F_1 () ;
}
int F_8 ( struct V_15 * V_16 , unsigned long V_18 ,
unsigned long V_17 )
{
struct V_19 * V_20 = F_9 ( V_16 ) ;
T_1 V_21 , V_10 , V_22 , div , V_23 , V_24 ;
T_1 V_25 = 0 ;
struct V_26 V_27 ;
const struct V_28 * V_29 ;
V_21 = F_1 () ;
V_22 = F_4 ( V_4 , V_5 ) ;
V_22 &= V_6 ;
if ( ( V_18 == ( V_21 / 2 ) ) && ( V_22 == 2 ) ) {
F_10 ( V_12 , 1 ) ;
} else if ( ( V_18 == ( V_21 * 2 ) ) && ( V_22 == 1 ) ) {
F_10 ( V_30 , 1 ) ;
} else if ( V_18 != V_21 ) {
V_23 = F_5 ( V_18 ) ;
if ( V_23 != V_18 )
return - V_31 ;
if ( V_22 == 1 )
V_10 = V_13 -> V_14 ;
else
V_10 = V_13 -> V_14 / 2 ;
V_29 = V_20 -> V_28 ;
if ( ! V_29 )
return - V_31 ;
V_27 . V_32 = F_11 ( V_29 -> V_33 ) ;
V_27 . V_32 &= ~ ( V_29 -> V_34 |
V_29 -> V_35 ) ;
div = ( ( V_13 -> V_36 / 1000000 ) - 1 ) ;
V_27 . V_37 = F_4 ( V_4 , V_5 ) ;
V_27 . V_37 &= ~ V_6 ;
if ( V_18 > V_10 ) {
V_27 . V_37 |= V_30 ;
V_22 = ( ( V_18 / 2 ) / 1000000 ) ;
V_24 = V_30 ;
} else {
V_27 . V_37 |= V_12 ;
V_22 = ( V_18 / 1000000 ) ;
V_24 = V_12 ;
}
V_27 . V_32 |= ( div << F_12 ( V_29 -> V_34 ) ) ;
V_27 . V_32 |= ( V_22 << F_12 ( V_29 -> V_35 ) ) ;
V_27 . V_38 = V_39 ;
if ( V_18 == V_13 -> V_36 )
V_25 = 1 ;
F_10 ( V_30 , 1 ) ;
F_13 ( V_27 . V_32 , V_27 . V_38 ,
V_25 ) ;
F_14 ( F_15 () ) ;
F_10 ( V_24 , 0 ) ;
}
return 0 ;
}
void F_16 ( struct V_15 * V_16 )
{
F_17 ( V_3 , L_1 ) ;
V_3 = F_9 ( V_16 ) ;
}
