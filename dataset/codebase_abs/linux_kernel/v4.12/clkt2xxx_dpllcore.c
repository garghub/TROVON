unsigned long F_1 ( void )
{
long long V_1 ;
T_1 V_2 ;
F_2 ( ! V_3 ) ;
V_1 = F_3 ( V_3 ) ;
V_2 = F_4 () ;
if ( V_2 == V_4 )
V_1 = 32768 ;
else
V_1 *= V_2 ;
return V_1 ;
}
static long F_5 ( unsigned long V_5 )
{
T_1 V_6 , V_7 , V_8 ;
V_8 = F_4 () ;
if ( V_8 == V_9 ) {
V_6 = V_10 -> V_11 * 2 ;
V_7 = V_10 -> V_11 ;
} else {
V_6 = V_10 -> V_11 ;
V_7 = V_10 -> V_11 / 2 ;
}
#ifdef F_6
if ( V_5 > V_6 )
return V_6 ;
else
return V_5 ;
#else
if ( V_5 > V_7 )
return V_6 ;
else
return V_7 ;
#endif
}
unsigned long F_7 ( struct V_12 * V_13 ,
unsigned long V_14 )
{
return F_1 () ;
}
int F_8 ( struct V_12 * V_13 , unsigned long V_15 ,
unsigned long V_14 )
{
struct V_16 * V_17 = F_9 ( V_13 ) ;
T_1 V_18 , V_7 , V_19 , div , V_20 , V_21 ;
T_1 V_22 = 0 ;
struct V_23 V_24 ;
const struct V_25 * V_26 ;
V_18 = F_1 () ;
V_19 = F_4 () ;
if ( ( V_15 == ( V_18 / 2 ) ) && ( V_19 == 2 ) ) {
F_10 ( V_9 , 1 ) ;
} else if ( ( V_15 == ( V_18 * 2 ) ) && ( V_19 == 1 ) ) {
F_10 ( V_27 , 1 ) ;
} else if ( V_15 != V_18 ) {
V_20 = F_5 ( V_15 ) ;
if ( V_20 != V_15 )
return - V_28 ;
if ( V_19 == 1 )
V_7 = V_10 -> V_11 ;
else
V_7 = V_10 -> V_11 / 2 ;
V_26 = V_17 -> V_25 ;
if ( ! V_26 )
return - V_28 ;
V_24 . V_29 =
V_30 . V_31 ( & V_26 -> V_32 ) ;
V_24 . V_29 &= ~ ( V_26 -> V_33 |
V_26 -> V_34 ) ;
div = ( ( V_10 -> V_35 / 1000000 ) - 1 ) ;
V_24 . V_36 = F_11 () ;
V_24 . V_36 &= ~ V_37 ;
if ( V_15 > V_7 ) {
V_24 . V_36 |= V_27 ;
V_19 = ( ( V_15 / 2 ) / 1000000 ) ;
V_21 = V_27 ;
} else {
V_24 . V_36 |= V_9 ;
V_19 = ( V_15 / 1000000 ) ;
V_21 = V_9 ;
}
V_24 . V_29 |= ( div << F_12 ( V_26 -> V_33 ) ) ;
V_24 . V_29 |= ( V_19 << F_12 ( V_26 -> V_34 ) ) ;
V_24 . V_38 = V_39 ;
if ( V_15 == V_10 -> V_35 )
V_22 = 1 ;
F_10 ( V_27 , 1 ) ;
F_13 ( V_24 . V_29 , V_24 . V_38 ,
V_22 ) ;
F_14 ( F_15 () ) ;
F_10 ( V_21 , 0 ) ;
}
return 0 ;
}
void F_16 ( struct V_12 * V_13 )
{
F_17 ( V_3 , L_1 ) ;
V_3 = F_9 ( V_13 ) ;
}
