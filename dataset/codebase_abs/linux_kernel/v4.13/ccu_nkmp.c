static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = 0 ;
unsigned long V_6 = 0 , V_7 = 0 , V_8 = 0 , V_9 = 0 ;
unsigned long V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = V_4 -> V_14 ; V_11 <= V_4 -> V_15 ; V_11 ++ ) {
for ( V_10 = V_4 -> V_16 ; V_10 <= V_4 -> V_17 ; V_10 ++ ) {
for ( V_12 = V_4 -> V_18 ; V_12 <= V_4 -> V_19 ; V_12 ++ ) {
for ( V_13 = V_4 -> V_20 ; V_13 <= V_4 -> V_21 ; V_13 <<= 1 ) {
unsigned long V_22 ;
V_22 = V_1 * V_10 * V_11 / ( V_12 * V_13 ) ;
if ( V_22 > V_2 )
continue;
if ( ( V_2 - V_22 ) < ( V_2 - V_5 ) ) {
V_5 = V_22 ;
V_6 = V_10 ;
V_7 = V_11 ;
V_8 = V_12 ;
V_9 = V_13 ;
}
}
}
}
}
V_4 -> V_23 = V_6 ;
V_4 -> V_24 = V_7 ;
V_4 -> V_25 = V_8 ;
V_4 -> V_26 = V_9 ;
}
static void F_2 ( struct V_27 * V_28 )
{
struct V_29 * V_4 = F_3 ( V_28 ) ;
return F_4 ( & V_4 -> V_30 , V_4 -> V_31 ) ;
}
static int F_5 ( struct V_27 * V_28 )
{
struct V_29 * V_4 = F_3 ( V_28 ) ;
return F_6 ( & V_4 -> V_30 , V_4 -> V_31 ) ;
}
static int F_7 ( struct V_27 * V_28 )
{
struct V_29 * V_4 = F_3 ( V_28 ) ;
return F_8 ( & V_4 -> V_30 , V_4 -> V_31 ) ;
}
static unsigned long F_9 ( struct V_27 * V_28 ,
unsigned long V_32 )
{
struct V_29 * V_4 = F_3 ( V_28 ) ;
unsigned long V_23 , V_25 , V_24 , V_26 ;
T_1 V_33 ;
V_33 = F_10 ( V_4 -> V_30 . V_34 + V_4 -> V_30 . V_33 ) ;
V_23 = V_33 >> V_4 -> V_23 . V_35 ;
V_23 &= ( 1 << V_4 -> V_23 . V_36 ) - 1 ;
V_23 += V_4 -> V_23 . V_37 ;
if ( ! V_23 )
V_23 ++ ;
V_24 = V_33 >> V_4 -> V_24 . V_35 ;
V_24 &= ( 1 << V_4 -> V_24 . V_36 ) - 1 ;
V_24 += V_4 -> V_24 . V_37 ;
if ( ! V_24 )
V_24 ++ ;
V_25 = V_33 >> V_4 -> V_25 . V_35 ;
V_25 &= ( 1 << V_4 -> V_25 . V_36 ) - 1 ;
V_25 += V_4 -> V_25 . V_37 ;
if ( ! V_25 )
V_25 ++ ;
V_26 = V_33 >> V_4 -> V_26 . V_35 ;
V_26 &= ( 1 << V_4 -> V_26 . V_36 ) - 1 ;
return ( V_32 * V_23 * V_24 >> V_26 ) / V_25 ;
}
static long F_11 ( struct V_27 * V_28 , unsigned long V_2 ,
unsigned long * V_32 )
{
struct V_29 * V_4 = F_3 ( V_28 ) ;
struct V_3 V_38 ;
V_38 . V_16 = V_4 -> V_23 . V_39 ? : 1 ;
V_38 . V_17 = V_4 -> V_23 . V_40 ? : 1 << V_4 -> V_23 . V_36 ;
V_38 . V_14 = V_4 -> V_24 . V_39 ? : 1 ;
V_38 . V_15 = V_4 -> V_24 . V_40 ? : 1 << V_4 -> V_24 . V_36 ;
V_38 . V_18 = 1 ;
V_38 . V_19 = V_4 -> V_25 . V_40 ? : 1 << V_4 -> V_25 . V_36 ;
V_38 . V_20 = 1 ;
V_38 . V_21 = V_4 -> V_26 . V_40 ? : 1 << ( ( 1 << V_4 -> V_26 . V_36 ) - 1 ) ;
F_1 ( * V_32 , V_2 , & V_38 ) ;
return * V_32 * V_38 . V_23 * V_38 . V_24 / ( V_38 . V_25 * V_38 . V_26 ) ;
}
static int F_12 ( struct V_27 * V_28 , unsigned long V_2 ,
unsigned long V_32 )
{
struct V_29 * V_4 = F_3 ( V_28 ) ;
struct V_3 V_38 ;
unsigned long V_41 ;
T_1 V_33 ;
V_38 . V_16 = V_4 -> V_23 . V_39 ? : 1 ;
V_38 . V_17 = V_4 -> V_23 . V_40 ? : 1 << V_4 -> V_23 . V_36 ;
V_38 . V_14 = V_4 -> V_24 . V_39 ? : 1 ;
V_38 . V_15 = V_4 -> V_24 . V_40 ? : 1 << V_4 -> V_24 . V_36 ;
V_38 . V_18 = 1 ;
V_38 . V_19 = V_4 -> V_25 . V_40 ? : 1 << V_4 -> V_25 . V_36 ;
V_38 . V_20 = 1 ;
V_38 . V_21 = V_4 -> V_26 . V_40 ? : 1 << ( ( 1 << V_4 -> V_26 . V_36 ) - 1 ) ;
F_1 ( V_32 , V_2 , & V_38 ) ;
F_13 ( V_4 -> V_30 . V_42 , V_41 ) ;
V_33 = F_10 ( V_4 -> V_30 . V_34 + V_4 -> V_30 . V_33 ) ;
V_33 &= ~ F_14 ( V_4 -> V_23 . V_36 + V_4 -> V_23 . V_35 - 1 , V_4 -> V_23 . V_35 ) ;
V_33 &= ~ F_14 ( V_4 -> V_24 . V_36 + V_4 -> V_24 . V_35 - 1 , V_4 -> V_24 . V_35 ) ;
V_33 &= ~ F_14 ( V_4 -> V_25 . V_36 + V_4 -> V_25 . V_35 - 1 , V_4 -> V_25 . V_35 ) ;
V_33 &= ~ F_14 ( V_4 -> V_26 . V_36 + V_4 -> V_26 . V_35 - 1 , V_4 -> V_26 . V_35 ) ;
V_33 |= ( V_38 . V_23 - V_4 -> V_23 . V_37 ) << V_4 -> V_23 . V_35 ;
V_33 |= ( V_38 . V_24 - V_4 -> V_24 . V_37 ) << V_4 -> V_24 . V_35 ;
V_33 |= ( V_38 . V_25 - V_4 -> V_25 . V_37 ) << V_4 -> V_25 . V_35 ;
V_33 |= F_15 ( V_38 . V_26 ) << V_4 -> V_26 . V_35 ;
F_16 ( V_33 , V_4 -> V_30 . V_34 + V_4 -> V_30 . V_33 ) ;
F_17 ( V_4 -> V_30 . V_42 , V_41 ) ;
F_18 ( & V_4 -> V_30 , V_4 -> V_42 ) ;
return 0 ;
}
