static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = 0 ;
unsigned long V_6 = 0 , V_7 = 0 ;
unsigned long V_8 , V_9 ;
for ( V_8 = V_4 -> V_10 ; V_8 <= V_4 -> V_11 ; V_8 ++ ) {
for ( V_9 = V_4 -> V_12 ; V_9 <= V_4 -> V_13 ; V_9 ++ ) {
unsigned long V_14 = V_1 * V_8 / V_9 ;
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
unsigned long V_15 , V_16 ;
T_1 V_23 ;
if ( F_10 ( & V_4 -> V_20 , & V_4 -> V_24 ) )
return F_11 ( & V_4 -> V_20 , & V_4 -> V_24 ) ;
V_23 = F_12 ( V_4 -> V_20 . V_25 + V_4 -> V_20 . V_23 ) ;
V_15 = V_23 >> V_4 -> V_15 . V_26 ;
V_15 &= ( 1 << V_4 -> V_15 . V_27 ) - 1 ;
V_15 += V_4 -> V_15 . V_28 ;
if ( ! V_15 )
V_15 ++ ;
V_16 = V_23 >> V_4 -> V_16 . V_26 ;
V_16 &= ( 1 << V_4 -> V_16 . V_27 ) - 1 ;
V_16 += V_4 -> V_16 . V_28 ;
if ( ! V_16 )
V_16 ++ ;
return V_22 * V_15 / V_16 ;
}
static long F_13 ( struct V_17 * V_18 , unsigned long V_2 ,
unsigned long * V_22 )
{
struct V_19 * V_4 = F_3 ( V_18 ) ;
struct V_3 V_29 ;
V_29 . V_10 = V_4 -> V_15 . V_30 ;
V_29 . V_11 = V_4 -> V_15 . V_31 ? : 1 << V_4 -> V_15 . V_27 ;
V_29 . V_12 = 1 ;
V_29 . V_13 = V_4 -> V_16 . V_31 ? : 1 << V_4 -> V_16 . V_27 ;
F_1 ( * V_22 , V_2 , & V_29 ) ;
return * V_22 * V_29 . V_15 / V_29 . V_16 ;
}
static int F_14 ( struct V_17 * V_18 , unsigned long V_2 ,
unsigned long V_22 )
{
struct V_19 * V_4 = F_3 ( V_18 ) ;
struct V_3 V_29 ;
unsigned long V_32 ;
T_1 V_23 ;
if ( F_15 ( & V_4 -> V_20 , & V_4 -> V_24 , V_2 ) )
return F_16 ( & V_4 -> V_20 , & V_4 -> V_24 , V_2 ) ;
else
F_17 ( & V_4 -> V_20 , & V_4 -> V_24 ) ;
V_29 . V_10 = 1 ;
V_29 . V_11 = V_4 -> V_15 . V_31 ? : 1 << V_4 -> V_15 . V_27 ;
V_29 . V_12 = 1 ;
V_29 . V_13 = V_4 -> V_16 . V_31 ? : 1 << V_4 -> V_16 . V_27 ;
F_1 ( V_22 , V_2 , & V_29 ) ;
F_18 ( V_4 -> V_20 . V_33 , V_32 ) ;
V_23 = F_12 ( V_4 -> V_20 . V_25 + V_4 -> V_20 . V_23 ) ;
V_23 &= ~ F_19 ( V_4 -> V_15 . V_27 + V_4 -> V_15 . V_26 - 1 , V_4 -> V_15 . V_26 ) ;
V_23 &= ~ F_19 ( V_4 -> V_16 . V_27 + V_4 -> V_16 . V_26 - 1 , V_4 -> V_16 . V_26 ) ;
V_23 |= ( V_29 . V_15 - V_4 -> V_15 . V_28 ) << V_4 -> V_15 . V_26 ;
V_23 |= ( V_29 . V_16 - V_4 -> V_16 . V_28 ) << V_4 -> V_16 . V_26 ;
F_20 ( V_23 , V_4 -> V_20 . V_25 + V_4 -> V_20 . V_23 ) ;
F_21 ( V_4 -> V_20 . V_33 , V_32 ) ;
F_22 ( & V_4 -> V_20 , V_4 -> V_33 ) ;
return 0 ;
}
