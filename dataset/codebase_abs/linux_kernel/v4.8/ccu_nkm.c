static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = 0 ;
unsigned long V_6 = 0 , V_7 = 0 , V_8 = 0 ;
unsigned long V_9 , V_10 , V_11 ;
for ( V_10 = 1 ; V_10 <= V_4 -> V_12 ; V_10 ++ ) {
unsigned long V_13 ;
F_2 ( V_2 / V_10 , V_1 ,
V_4 -> V_14 , V_4 -> V_15 , & V_9 , & V_11 ) ;
V_13 = V_1 * V_9 * V_10 / V_11 ;
if ( V_13 > V_2 )
continue;
if ( ( V_2 - V_13 ) < ( V_2 - V_5 ) ) {
V_5 = V_13 ;
V_6 = V_9 ;
V_7 = V_10 ;
V_8 = V_11 ;
}
}
V_4 -> V_16 = V_6 ;
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = V_8 ;
}
static void F_3 ( struct V_19 * V_20 )
{
struct V_21 * V_4 = F_4 ( V_20 ) ;
return F_5 ( & V_4 -> V_22 , V_4 -> V_23 ) ;
}
static int F_6 ( struct V_19 * V_20 )
{
struct V_21 * V_4 = F_4 ( V_20 ) ;
return F_7 ( & V_4 -> V_22 , V_4 -> V_23 ) ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_4 = F_4 ( V_20 ) ;
return F_9 ( & V_4 -> V_22 , V_4 -> V_23 ) ;
}
static unsigned long F_10 ( struct V_19 * V_20 ,
unsigned long V_24 )
{
struct V_21 * V_4 = F_4 ( V_20 ) ;
unsigned long V_16 , V_18 , V_17 ;
T_1 V_25 ;
V_25 = F_11 ( V_4 -> V_22 . V_26 + V_4 -> V_22 . V_25 ) ;
V_16 = V_25 >> V_4 -> V_16 . V_27 ;
V_16 &= ( 1 << V_4 -> V_16 . V_28 ) - 1 ;
V_17 = V_25 >> V_4 -> V_17 . V_27 ;
V_17 &= ( 1 << V_4 -> V_17 . V_28 ) - 1 ;
V_18 = V_25 >> V_4 -> V_18 . V_27 ;
V_18 &= ( 1 << V_4 -> V_18 . V_28 ) - 1 ;
return V_24 * ( V_16 + 1 ) * ( V_17 + 1 ) / ( V_18 + 1 ) ;
}
static long F_12 ( struct V_19 * V_20 , unsigned long V_2 ,
unsigned long * V_24 )
{
struct V_21 * V_4 = F_4 ( V_20 ) ;
struct V_3 V_29 ;
V_29 . V_14 = 1 << V_4 -> V_16 . V_28 ;
V_29 . V_12 = 1 << V_4 -> V_17 . V_28 ;
V_29 . V_15 = 1 << V_4 -> V_18 . V_28 ;
F_1 ( * V_24 , V_2 , & V_29 ) ;
return * V_24 * V_29 . V_16 * V_29 . V_17 / V_29 . V_18 ;
}
static int F_13 ( struct V_19 * V_20 , unsigned long V_2 ,
unsigned long V_24 )
{
struct V_21 * V_4 = F_4 ( V_20 ) ;
struct V_3 V_29 ;
unsigned long V_30 ;
T_1 V_25 ;
V_29 . V_14 = 1 << V_4 -> V_16 . V_28 ;
V_29 . V_12 = 1 << V_4 -> V_17 . V_28 ;
V_29 . V_15 = 1 << V_4 -> V_18 . V_28 ;
F_1 ( V_24 , V_2 , & V_29 ) ;
F_14 ( V_4 -> V_22 . V_31 , V_30 ) ;
V_25 = F_11 ( V_4 -> V_22 . V_26 + V_4 -> V_22 . V_25 ) ;
V_25 &= ~ F_15 ( V_4 -> V_16 . V_28 + V_4 -> V_16 . V_27 - 1 , V_4 -> V_16 . V_27 ) ;
V_25 &= ~ F_15 ( V_4 -> V_17 . V_28 + V_4 -> V_17 . V_27 - 1 , V_4 -> V_17 . V_27 ) ;
V_25 &= ~ F_15 ( V_4 -> V_18 . V_28 + V_4 -> V_18 . V_27 - 1 , V_4 -> V_18 . V_27 ) ;
V_25 |= ( V_29 . V_16 - 1 ) << V_4 -> V_16 . V_27 ;
V_25 |= ( V_29 . V_17 - 1 ) << V_4 -> V_17 . V_27 ;
V_25 |= ( V_29 . V_18 - 1 ) << V_4 -> V_18 . V_27 ;
F_16 ( V_25 , V_4 -> V_22 . V_26 + V_4 -> V_22 . V_25 ) ;
F_17 ( V_4 -> V_22 . V_31 , V_30 ) ;
F_18 ( & V_4 -> V_22 , V_4 -> V_31 ) ;
return 0 ;
}
