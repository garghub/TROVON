void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
unsigned long * V_6 )
{
T_1 V_7 = 1 ;
T_2 V_8 ;
if ( ! ( ( V_2 -> V_9 & V_10 ) ||
( V_2 -> V_9 & V_11 ) ) )
return;
V_8 = F_2 ( V_2 -> V_12 + V_2 -> V_8 ) ;
if ( V_5 < 0 ) {
V_5 = V_8 >> V_4 -> V_13 ;
V_5 &= ( 1 << V_4 -> V_14 ) - 1 ;
}
if ( V_2 -> V_9 & V_10 )
if ( V_5 == V_4 -> V_15 . V_16 )
V_7 = V_4 -> V_15 . div ;
if ( V_2 -> V_9 & V_11 )
if ( V_5 == V_4 -> V_17 . V_16 ) {
T_1 div ;
div = V_8 >> V_4 -> V_17 . V_13 ;
div &= ( 1 << V_4 -> V_17 . V_14 ) - 1 ;
V_7 = div + 1 ;
}
* V_6 = * V_6 / V_7 ;
}
T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_8 ;
T_1 V_18 ;
V_8 = F_2 ( V_2 -> V_12 + V_2 -> V_8 ) ;
V_18 = V_8 >> V_4 -> V_13 ;
V_18 &= ( 1 << V_4 -> V_14 ) - 1 ;
return V_18 ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_16 )
{
unsigned long V_19 ;
T_2 V_8 ;
F_5 ( V_2 -> V_20 , V_19 ) ;
V_8 = F_2 ( V_2 -> V_12 + V_2 -> V_8 ) ;
V_8 &= ~ F_6 ( V_4 -> V_14 + V_4 -> V_13 - 1 , V_4 -> V_13 ) ;
F_7 ( V_8 | ( V_16 << V_4 -> V_13 ) , V_2 -> V_12 + V_2 -> V_8 ) ;
F_8 ( V_2 -> V_20 , V_19 ) ;
return 0 ;
}
static void F_9 ( struct V_21 * V_22 )
{
struct V_23 * V_4 = F_10 ( V_22 ) ;
return F_11 ( & V_4 -> V_2 , V_4 -> V_24 ) ;
}
static int F_12 ( struct V_21 * V_22 )
{
struct V_23 * V_4 = F_10 ( V_22 ) ;
return F_13 ( & V_4 -> V_2 , V_4 -> V_24 ) ;
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_23 * V_4 = F_10 ( V_22 ) ;
return F_15 ( & V_4 -> V_2 , V_4 -> V_24 ) ;
}
static T_1 F_16 ( struct V_21 * V_22 )
{
struct V_23 * V_4 = F_10 ( V_22 ) ;
return F_3 ( & V_4 -> V_2 , & V_4 -> V_25 ) ;
}
static int F_17 ( struct V_21 * V_22 , T_1 V_16 )
{
struct V_23 * V_4 = F_10 ( V_22 ) ;
return F_4 ( & V_4 -> V_2 , & V_4 -> V_25 , V_16 ) ;
}
static unsigned long F_18 ( struct V_21 * V_22 ,
unsigned long V_6 )
{
struct V_23 * V_4 = F_10 ( V_22 ) ;
F_1 ( & V_4 -> V_2 , & V_4 -> V_25 , - 1 ,
& V_6 ) ;
return V_6 ;
}
