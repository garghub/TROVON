static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = 0 ;
unsigned long V_6 = 0 , V_7 = 0 , V_8 = 0 , V_9 = 0 ;
unsigned long V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 1 ; V_11 <= V_4 -> V_14 ; V_11 ++ ) {
for ( V_13 = 1 ; V_13 <= V_4 -> V_15 ; V_13 <<= 1 ) {
unsigned long V_16 ;
F_2 ( V_2 / V_11 , V_1 / V_13 ,
V_4 -> V_17 , V_4 -> V_18 ,
& V_10 , & V_12 ) ;
V_16 = V_1 * V_10 * V_11 / ( V_12 * V_13 ) ;
if ( V_16 > V_2 )
continue;
if ( ( V_2 - V_16 ) < ( V_2 - V_5 ) ) {
V_5 = V_16 ;
V_6 = V_10 ;
V_7 = V_11 ;
V_8 = V_12 ;
V_9 = V_13 ;
}
}
}
V_4 -> V_19 = V_6 ;
V_4 -> V_20 = V_7 ;
V_4 -> V_21 = V_8 ;
V_4 -> V_22 = V_9 ;
}
static void F_3 ( struct V_23 * V_24 )
{
struct V_25 * V_4 = F_4 ( V_24 ) ;
return F_5 ( & V_4 -> V_26 , V_4 -> V_27 ) ;
}
static int F_6 ( struct V_23 * V_24 )
{
struct V_25 * V_4 = F_4 ( V_24 ) ;
return F_7 ( & V_4 -> V_26 , V_4 -> V_27 ) ;
}
static int F_8 ( struct V_23 * V_24 )
{
struct V_25 * V_4 = F_4 ( V_24 ) ;
return F_9 ( & V_4 -> V_26 , V_4 -> V_27 ) ;
}
static unsigned long F_10 ( struct V_23 * V_24 ,
unsigned long V_28 )
{
struct V_25 * V_4 = F_4 ( V_24 ) ;
unsigned long V_19 , V_21 , V_20 , V_22 ;
T_1 V_29 ;
V_29 = F_11 ( V_4 -> V_26 . V_30 + V_4 -> V_26 . V_29 ) ;
V_19 = V_29 >> V_4 -> V_19 . V_31 ;
V_19 &= ( 1 << V_4 -> V_19 . V_32 ) - 1 ;
V_20 = V_29 >> V_4 -> V_20 . V_31 ;
V_20 &= ( 1 << V_4 -> V_20 . V_32 ) - 1 ;
V_21 = V_29 >> V_4 -> V_21 . V_31 ;
V_21 &= ( 1 << V_4 -> V_21 . V_32 ) - 1 ;
V_22 = V_29 >> V_4 -> V_22 . V_31 ;
V_22 &= ( 1 << V_4 -> V_22 . V_32 ) - 1 ;
return ( V_28 * ( V_19 + 1 ) * ( V_20 + 1 ) >> V_22 ) / ( V_21 + 1 ) ;
}
static long F_12 ( struct V_23 * V_24 , unsigned long V_2 ,
unsigned long * V_28 )
{
struct V_25 * V_4 = F_4 ( V_24 ) ;
struct V_3 V_33 ;
V_33 . V_17 = 1 << V_4 -> V_19 . V_32 ;
V_33 . V_14 = 1 << V_4 -> V_20 . V_32 ;
V_33 . V_18 = V_4 -> V_21 . V_34 ? : 1 << V_4 -> V_21 . V_32 ;
V_33 . V_15 = V_4 -> V_22 . V_34 ? : 1 << ( ( 1 << V_4 -> V_22 . V_32 ) - 1 ) ;
F_1 ( * V_28 , V_2 , & V_33 ) ;
return * V_28 * V_33 . V_19 * V_33 . V_20 / ( V_33 . V_21 * V_33 . V_22 ) ;
}
static int F_13 ( struct V_23 * V_24 , unsigned long V_2 ,
unsigned long V_28 )
{
struct V_25 * V_4 = F_4 ( V_24 ) ;
struct V_3 V_33 ;
unsigned long V_35 ;
T_1 V_29 ;
V_33 . V_17 = 1 << V_4 -> V_19 . V_32 ;
V_33 . V_14 = 1 << V_4 -> V_20 . V_32 ;
V_33 . V_18 = V_4 -> V_21 . V_34 ? : 1 << V_4 -> V_21 . V_32 ;
V_33 . V_15 = V_4 -> V_22 . V_34 ? : 1 << ( ( 1 << V_4 -> V_22 . V_32 ) - 1 ) ;
F_1 ( V_28 , V_2 , & V_33 ) ;
F_14 ( V_4 -> V_26 . V_36 , V_35 ) ;
V_29 = F_11 ( V_4 -> V_26 . V_30 + V_4 -> V_26 . V_29 ) ;
V_29 &= ~ F_15 ( V_4 -> V_19 . V_32 + V_4 -> V_19 . V_31 - 1 , V_4 -> V_19 . V_31 ) ;
V_29 &= ~ F_15 ( V_4 -> V_20 . V_32 + V_4 -> V_20 . V_31 - 1 , V_4 -> V_20 . V_31 ) ;
V_29 &= ~ F_15 ( V_4 -> V_21 . V_32 + V_4 -> V_21 . V_31 - 1 , V_4 -> V_21 . V_31 ) ;
V_29 &= ~ F_15 ( V_4 -> V_22 . V_32 + V_4 -> V_22 . V_31 - 1 , V_4 -> V_22 . V_31 ) ;
V_29 |= ( V_33 . V_19 - 1 ) << V_4 -> V_19 . V_31 ;
V_29 |= ( V_33 . V_20 - 1 ) << V_4 -> V_20 . V_31 ;
V_29 |= ( V_33 . V_21 - 1 ) << V_4 -> V_21 . V_31 ;
V_29 |= F_16 ( V_33 . V_22 ) << V_4 -> V_22 . V_31 ;
F_17 ( V_29 , V_4 -> V_26 . V_30 + V_4 -> V_26 . V_29 ) ;
F_18 ( V_4 -> V_26 . V_36 , V_35 ) ;
F_19 ( & V_4 -> V_26 , V_4 -> V_36 ) ;
return 0 ;
}
