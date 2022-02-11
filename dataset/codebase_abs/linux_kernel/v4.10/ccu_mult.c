static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_5 = V_2 / V_1 ;
if ( V_5 < V_4 -> V_6 )
V_5 = V_4 -> V_6 ;
if ( V_5 > V_4 -> V_7 )
V_5 = V_4 -> V_7 ;
V_4 -> V_4 = V_5 ;
}
static unsigned long F_2 ( struct V_8 * V_9 ,
unsigned long V_10 ,
unsigned long V_2 ,
void * V_11 )
{
struct V_12 * V_13 = V_11 ;
struct V_3 V_14 ;
V_14 . V_6 = 1 ;
V_14 . V_7 = 1 << V_13 -> V_4 . V_15 ;
F_1 ( V_10 , V_2 , & V_14 ) ;
return V_10 * V_14 . V_4 ;
}
static void F_3 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = F_4 ( V_17 ) ;
return F_5 ( & V_13 -> V_18 , V_13 -> V_19 ) ;
}
static int F_6 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = F_4 ( V_17 ) ;
return F_7 ( & V_13 -> V_18 , V_13 -> V_19 ) ;
}
static int F_8 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = F_4 ( V_17 ) ;
return F_9 ( & V_13 -> V_18 , V_13 -> V_19 ) ;
}
static unsigned long F_10 ( struct V_16 * V_17 ,
unsigned long V_10 )
{
struct V_12 * V_13 = F_4 ( V_17 ) ;
unsigned long V_20 ;
T_1 V_21 ;
V_21 = F_11 ( V_13 -> V_18 . V_22 + V_13 -> V_18 . V_21 ) ;
V_20 = V_21 >> V_13 -> V_4 . V_23 ;
V_20 &= ( 1 << V_13 -> V_4 . V_15 ) - 1 ;
F_12 ( & V_13 -> V_18 , & V_13 -> V_9 , - 1 ,
& V_10 ) ;
return V_10 * ( V_20 + 1 ) ;
}
static int F_13 ( struct V_16 * V_17 ,
struct V_24 * V_25 )
{
struct V_12 * V_13 = F_4 ( V_17 ) ;
return F_14 ( & V_13 -> V_18 , & V_13 -> V_9 ,
V_25 , F_2 , V_13 ) ;
}
static int F_15 ( struct V_16 * V_17 , unsigned long V_2 ,
unsigned long V_10 )
{
struct V_12 * V_13 = F_4 ( V_17 ) ;
struct V_3 V_14 ;
unsigned long V_26 ;
T_1 V_21 ;
F_12 ( & V_13 -> V_18 , & V_13 -> V_9 , - 1 ,
& V_10 ) ;
V_14 . V_6 = V_13 -> V_4 . V_6 ;
V_14 . V_7 = 1 << V_13 -> V_4 . V_15 ;
F_1 ( V_10 , V_2 , & V_14 ) ;
F_16 ( V_13 -> V_18 . V_27 , V_26 ) ;
V_21 = F_11 ( V_13 -> V_18 . V_22 + V_13 -> V_18 . V_21 ) ;
V_21 &= ~ F_17 ( V_13 -> V_4 . V_15 + V_13 -> V_4 . V_23 - 1 , V_13 -> V_4 . V_23 ) ;
F_18 ( V_21 | ( ( V_14 . V_4 - 1 ) << V_13 -> V_4 . V_23 ) ,
V_13 -> V_18 . V_22 + V_13 -> V_18 . V_21 ) ;
F_19 ( V_13 -> V_18 . V_27 , V_26 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = F_4 ( V_17 ) ;
return F_21 ( & V_13 -> V_18 , & V_13 -> V_9 ) ;
}
static int F_22 ( struct V_16 * V_17 , T_2 V_28 )
{
struct V_12 * V_13 = F_4 ( V_17 ) ;
return F_23 ( & V_13 -> V_18 , & V_13 -> V_9 , V_28 ) ;
}
