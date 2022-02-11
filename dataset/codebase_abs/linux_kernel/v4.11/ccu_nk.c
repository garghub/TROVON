static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = 0 ;
unsigned int V_6 = 0 , V_7 = 0 ;
unsigned int V_8 , V_9 ;
for ( V_8 = V_4 -> V_10 ; V_8 <= V_4 -> V_11 ; V_8 ++ ) {
for ( V_9 = V_4 -> V_12 ; V_9 <= V_4 -> V_13 ; V_9 ++ ) {
unsigned long V_14 = V_1 * V_9 * V_8 ;
if ( V_14 > V_2 )
continue;
if ( ( V_2 - V_14 ) < ( V_2 - V_5 ) ) {
V_5 = V_14 ;
V_6 = V_8 ;
V_7 = V_9 ;
}
}
}
V_4 -> V_15 = V_6 ;
V_4 -> V_16 = V_7 ;
}
static void F_2 ( struct V_17 * V_18 )
{
struct V_19 * V_4 = F_3 ( V_18 ) ;
return F_4 ( & V_4 -> V_20 , V_4 -> V_21 ) ;
}
static int F_5 ( struct V_17 * V_18 )
{
struct V_19 * V_4 = F_3 ( V_18 ) ;
return F_6 ( & V_4 -> V_20 , V_4 -> V_21 ) ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_4 = F_3 ( V_18 ) ;
return F_8 ( & V_4 -> V_20 , V_4 -> V_21 ) ;
}
static unsigned long F_9 ( struct V_17 * V_18 ,
unsigned long V_22 )
{
struct V_19 * V_4 = F_3 ( V_18 ) ;
unsigned long V_2 , V_16 , V_15 ;
T_1 V_23 ;
V_23 = F_10 ( V_4 -> V_20 . V_24 + V_4 -> V_20 . V_23 ) ;
V_16 = V_23 >> V_4 -> V_16 . V_25 ;
V_16 &= ( 1 << V_4 -> V_16 . V_26 ) - 1 ;
V_16 += V_4 -> V_16 . V_27 ;
if ( ! V_16 )
V_16 ++ ;
V_15 = V_23 >> V_4 -> V_15 . V_25 ;
V_15 &= ( 1 << V_4 -> V_15 . V_26 ) - 1 ;
V_15 += V_4 -> V_15 . V_27 ;
if ( ! V_15 )
V_15 ++ ;
V_2 = V_22 * V_16 * V_15 ;
if ( V_4 -> V_20 . V_28 & V_29 )
V_2 /= V_4 -> V_30 ;
return V_2 ;
}
static long F_11 ( struct V_17 * V_18 , unsigned long V_2 ,
unsigned long * V_22 )
{
struct V_19 * V_4 = F_3 ( V_18 ) ;
struct V_3 V_31 ;
if ( V_4 -> V_20 . V_28 & V_29 )
V_2 *= V_4 -> V_30 ;
V_31 . V_12 = V_4 -> V_16 . V_32 ;
V_31 . V_13 = V_4 -> V_16 . V_33 ? : 1 << V_4 -> V_16 . V_26 ;
V_31 . V_10 = V_4 -> V_15 . V_32 ;
V_31 . V_11 = V_4 -> V_15 . V_33 ? : 1 << V_4 -> V_15 . V_26 ;
F_1 ( * V_22 , V_2 , & V_31 ) ;
V_2 = * V_22 * V_31 . V_16 * V_31 . V_15 ;
if ( V_4 -> V_20 . V_28 & V_29 )
V_2 = V_2 / V_4 -> V_30 ;
return V_2 ;
}
static int F_12 ( struct V_17 * V_18 , unsigned long V_2 ,
unsigned long V_22 )
{
struct V_19 * V_4 = F_3 ( V_18 ) ;
unsigned long V_34 ;
struct V_3 V_31 ;
T_1 V_23 ;
if ( V_4 -> V_20 . V_28 & V_29 )
V_2 = V_2 * V_4 -> V_30 ;
V_31 . V_12 = V_4 -> V_16 . V_32 ;
V_31 . V_13 = V_4 -> V_16 . V_33 ? : 1 << V_4 -> V_16 . V_26 ;
V_31 . V_10 = V_4 -> V_15 . V_32 ;
V_31 . V_11 = V_4 -> V_15 . V_33 ? : 1 << V_4 -> V_15 . V_26 ;
F_1 ( V_22 , V_2 , & V_31 ) ;
F_13 ( V_4 -> V_20 . V_35 , V_34 ) ;
V_23 = F_10 ( V_4 -> V_20 . V_24 + V_4 -> V_20 . V_23 ) ;
V_23 &= ~ F_14 ( V_4 -> V_16 . V_26 + V_4 -> V_16 . V_25 - 1 , V_4 -> V_16 . V_25 ) ;
V_23 &= ~ F_14 ( V_4 -> V_15 . V_26 + V_4 -> V_15 . V_25 - 1 , V_4 -> V_15 . V_25 ) ;
V_23 |= ( V_31 . V_15 - V_4 -> V_15 . V_27 ) << V_4 -> V_15 . V_25 ;
V_23 |= ( V_31 . V_16 - V_4 -> V_16 . V_27 ) << V_4 -> V_16 . V_25 ;
F_15 ( V_23 , V_4 -> V_20 . V_24 + V_4 -> V_20 . V_23 ) ;
F_16 ( V_4 -> V_20 . V_35 , V_34 ) ;
F_17 ( & V_4 -> V_20 , V_4 -> V_35 ) ;
return 0 ;
}
