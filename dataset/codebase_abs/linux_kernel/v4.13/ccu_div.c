static unsigned long F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long * V_5 ,
unsigned long V_6 ,
void * V_7 )
{
struct V_8 * V_9 = V_7 ;
return F_2 ( & V_9 -> V_10 . V_11 , V_4 ,
V_6 , V_5 ,
V_9 -> div . V_12 , V_9 -> div . V_13 ,
V_9 -> div . V_14 ) ;
}
static void F_3 ( struct V_3 * V_11 )
{
struct V_8 * V_9 = F_4 ( V_11 ) ;
return F_5 ( & V_9 -> V_10 , V_9 -> V_15 ) ;
}
static int F_6 ( struct V_3 * V_11 )
{
struct V_8 * V_9 = F_4 ( V_11 ) ;
return F_7 ( & V_9 -> V_10 , V_9 -> V_15 ) ;
}
static int F_8 ( struct V_3 * V_11 )
{
struct V_8 * V_9 = F_4 ( V_11 ) ;
return F_9 ( & V_9 -> V_10 , V_9 -> V_15 ) ;
}
static unsigned long F_10 ( struct V_3 * V_11 ,
unsigned long V_5 )
{
struct V_8 * V_9 = F_4 ( V_11 ) ;
unsigned long V_16 ;
T_1 V_17 ;
V_17 = F_11 ( V_9 -> V_10 . V_18 + V_9 -> V_10 . V_17 ) ;
V_16 = V_17 >> V_9 -> div . V_19 ;
V_16 &= ( 1 << V_9 -> div . V_13 ) - 1 ;
V_5 = F_12 ( & V_9 -> V_10 , & V_9 -> V_2 , - 1 ,
V_5 ) ;
return F_13 ( V_11 , V_5 , V_16 , V_9 -> div . V_12 ,
V_9 -> div . V_14 ) ;
}
static int F_14 ( struct V_3 * V_11 ,
struct V_20 * V_21 )
{
struct V_8 * V_9 = F_4 ( V_11 ) ;
return F_15 ( & V_9 -> V_10 , & V_9 -> V_2 ,
V_21 , F_1 , V_9 ) ;
}
static int F_16 ( struct V_3 * V_11 , unsigned long V_6 ,
unsigned long V_5 )
{
struct V_8 * V_9 = F_4 ( V_11 ) ;
unsigned long V_14 ;
unsigned long V_16 ;
T_1 V_17 ;
V_5 = F_12 ( & V_9 -> V_10 , & V_9 -> V_2 , - 1 ,
V_5 ) ;
V_16 = F_17 ( V_6 , V_5 , V_9 -> div . V_12 , V_9 -> div . V_13 ,
V_9 -> div . V_14 ) ;
F_18 ( V_9 -> V_10 . V_22 , V_14 ) ;
V_17 = F_11 ( V_9 -> V_10 . V_18 + V_9 -> V_10 . V_17 ) ;
V_17 &= ~ F_19 ( V_9 -> div . V_13 + V_9 -> div . V_19 - 1 , V_9 -> div . V_19 ) ;
F_20 ( V_17 | ( V_16 << V_9 -> div . V_19 ) ,
V_9 -> V_10 . V_18 + V_9 -> V_10 . V_17 ) ;
F_21 ( V_9 -> V_10 . V_22 , V_14 ) ;
return 0 ;
}
static T_2 F_22 ( struct V_3 * V_11 )
{
struct V_8 * V_9 = F_4 ( V_11 ) ;
return F_23 ( & V_9 -> V_10 , & V_9 -> V_2 ) ;
}
static int F_24 ( struct V_3 * V_11 , T_2 V_23 )
{
struct V_8 * V_9 = F_4 ( V_11 ) ;
return F_25 ( & V_9 -> V_10 , & V_9 -> V_2 , V_23 ) ;
}
