static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned int V_3 , unsigned int V_4 ,
unsigned int * V_5 , unsigned int * V_6 )
{
unsigned long V_7 = 0 ;
unsigned int V_8 = 0 , V_9 = 0 ;
unsigned int V_10 , V_11 ;
for ( V_10 = 1 ; V_10 <= V_4 ; V_10 ++ ) {
for ( V_11 = 1 ; V_11 <= V_3 ; V_11 ++ ) {
unsigned long V_12 = V_1 * V_11 * V_10 ;
if ( V_12 > V_2 )
continue;
if ( ( V_2 - V_12 ) < ( V_2 - V_7 ) ) {
V_7 = V_12 ;
V_8 = V_10 ;
V_9 = V_11 ;
}
}
}
* V_6 = V_8 ;
* V_5 = V_9 ;
}
static void F_2 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_3 ( V_14 ) ;
return F_4 ( & V_16 -> V_17 , V_16 -> V_18 ) ;
}
static int F_5 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_3 ( V_14 ) ;
return F_6 ( & V_16 -> V_17 , V_16 -> V_18 ) ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_3 ( V_14 ) ;
return F_8 ( & V_16 -> V_17 , V_16 -> V_18 ) ;
}
static unsigned long F_9 ( struct V_13 * V_14 ,
unsigned long V_19 )
{
struct V_15 * V_16 = F_3 ( V_14 ) ;
unsigned long V_2 , V_5 , V_6 ;
T_1 V_20 ;
V_20 = F_10 ( V_16 -> V_17 . V_21 + V_16 -> V_17 . V_20 ) ;
V_5 = V_20 >> V_16 -> V_5 . V_22 ;
V_5 &= ( 1 << V_16 -> V_5 . V_23 ) - 1 ;
V_6 = V_20 >> V_16 -> V_6 . V_22 ;
V_6 &= ( 1 << V_16 -> V_6 . V_23 ) - 1 ;
V_2 = V_19 * ( V_5 + 1 ) * ( V_6 + 1 ) ;
if ( V_16 -> V_17 . V_24 & V_25 )
V_2 /= V_16 -> V_26 ;
return V_2 ;
}
static long F_11 ( struct V_13 * V_14 , unsigned long V_2 ,
unsigned long * V_19 )
{
struct V_15 * V_16 = F_3 ( V_14 ) ;
unsigned int V_5 , V_6 ;
if ( V_16 -> V_17 . V_24 & V_25 )
V_2 *= V_16 -> V_26 ;
F_1 ( * V_19 , V_2 ,
1 << V_16 -> V_5 . V_23 , 1 << V_16 -> V_6 . V_23 ,
& V_5 , & V_6 ) ;
V_2 = * V_19 * V_5 * V_6 ;
if ( V_16 -> V_17 . V_24 & V_25 )
V_2 = V_2 / V_16 -> V_26 ;
return V_2 ;
}
static int F_12 ( struct V_13 * V_14 , unsigned long V_2 ,
unsigned long V_19 )
{
struct V_15 * V_16 = F_3 ( V_14 ) ;
unsigned long V_27 ;
unsigned int V_5 , V_6 ;
T_1 V_20 ;
if ( V_16 -> V_17 . V_24 & V_25 )
V_2 = V_2 * V_16 -> V_26 ;
F_1 ( V_19 , V_2 ,
1 << V_16 -> V_5 . V_23 , 1 << V_16 -> V_6 . V_23 ,
& V_5 , & V_6 ) ;
F_13 ( V_16 -> V_17 . V_28 , V_27 ) ;
V_20 = F_10 ( V_16 -> V_17 . V_21 + V_16 -> V_17 . V_20 ) ;
V_20 &= ~ F_14 ( V_16 -> V_5 . V_23 + V_16 -> V_5 . V_22 - 1 , V_16 -> V_5 . V_22 ) ;
V_20 &= ~ F_14 ( V_16 -> V_6 . V_23 + V_16 -> V_6 . V_22 - 1 , V_16 -> V_6 . V_22 ) ;
F_15 ( V_20 | ( ( V_6 - 1 ) << V_16 -> V_6 . V_22 ) | ( ( V_5 - 1 ) << V_16 -> V_5 . V_22 ) ,
V_16 -> V_17 . V_21 + V_16 -> V_17 . V_20 ) ;
F_16 ( V_16 -> V_17 . V_28 , V_27 ) ;
F_17 ( & V_16 -> V_17 , V_16 -> V_28 ) ;
return 0 ;
}
